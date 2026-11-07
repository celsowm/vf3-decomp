/* Parse the extracted AKI/JAC POL meshes into native triangle scenes. */
#include "pol.h"
#include "pol_mesh.h"

#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int load(const char *path, uint8_t **data, uint32_t *size)
{
    FILE *f = fopen(path, "rb");
    long n;
    if (!f)
        return -1;
    if (fseek(f, 0, SEEK_END) != 0 || (n = ftell(f)) <= 0 ||
        (unsigned long)n > UINT32_MAX || fseek(f, 0, SEEK_SET) != 0) {
        fclose(f);
        return -1;
    }
    *data = (uint8_t *)malloc((size_t)n);
    if (!*data || fread(*data, 1, (size_t)n, f) != (size_t)n) {
        free(*data);
        *data = NULL;
        fclose(f);
        return -1;
    }
    fclose(f);
    *size = (uint32_t)n;
    return 0;
}

static void wr32(uint8_t *p, uint32_t value)
{
    p[0] = (uint8_t)value;
    p[1] = (uint8_t)(value >> 8);
    p[2] = (uint8_t)(value >> 16);
    p[3] = (uint8_t)(value >> 24);
}

static int finite_float(float value)
{
    return value >= -FLT_MAX && value <= FLT_MAX;
}

static int check_slot_data(const char *stem, const uint8_t *data,
                           uint32_t size)
{
    uint32_t slot_count = 0, span_count = 0, expected = 0, tagged = 0;
    uint32_t untagged = 0;
    PolSlot *slots = NULL;
    PolDataSpan *spans = NULL;
    int fails = 0;
    if (pol_slots(data, size, NULL, 0, &slot_count) != -2 ||
        pol_data_spans(data, size, NULL, 0, &span_count) != -2) {
        fprintf(stderr, "  %s: cannot query all-slot data spans\n", stem);
        return 1;
    }
    slots = (PolSlot *)calloc(slot_count, sizeof *slots);
    spans = (PolDataSpan *)calloc(span_count, sizeof *spans);
    if ((!slots && slot_count) || (!spans && span_count) ||
        pol_slots(data, size, slots, slot_count, &slot_count) != 0 ||
        pol_data_spans(data, size, spans, span_count, &span_count) != 0) {
        fprintf(stderr, "  %s: cannot read all-slot data spans\n", stem);
        fails++;
        goto done;
    }
    for (uint32_t i = 0; i < slot_count; ++i)
        expected += slots[i].raw != 0;
    if (span_count != expected) {
        fprintf(stderr, "  %s: %u nonzero slots but %u data spans\n",
                stem, expected, span_count);
        fails++;
    }
    for (uint32_t i = 0; i < span_count; ++i) {
        const PolDataSpan *span = &spans[i];
        if (span->slot_index >= slot_count || span->start < 0x30u ||
            span->start >= span->end || span->end > size ||
            span->tagged != slots[span->slot_index].tagged ||
            span->start != slots[span->slot_index].offset_candidate ||
            (i && (spans[i - 1u].start > span->start ||
                   (spans[i - 1u].start == span->start &&
                    spans[i - 1u].slot_index >= span->slot_index)))) {
            fprintf(stderr, "  %s: invalid or unsorted slot span at row %u\n",
                    stem, i);
            fails++;
            break;
        }
        if (i && spans[i - 1u].start == span->start) {
            if (spans[i - 1u].end != span->end) {
                fprintf(stderr, "  %s: aliases do not share a bounded span\n", stem);
                fails++;
                break;
            }
        } else if (i && spans[i - 1u].end != span->start) {
            fprintf(stderr, "  %s: adjacent slot spans do not meet at next target\n",
                    stem);
            fails++;
            break;
        }
        tagged += span->tagged != 0;
        untagged += span->tagged == 0;
    }
    printf("  %s: indexed %u nonzero slots (%u tagged, %u untagged)\n",
           stem, span_count, tagged, untagged);
done:
    free(spans);
    free(slots);
    return fails;
}

static int check_model(const char *stem, uint32_t expected_meshes,
                       uint32_t expected_vertices)
{
    char path[128];
    uint8_t *data = NULL;
    uint32_t size = 0, span_count = 0;
    PolHeader header;
    PolScene scene = {0};
    PolSlotSpan *spans = NULL;
    int fails = 0;
    snprintf(path, sizeof path, "extract/gamedata/%s.POL", stem);
    if (load(path, &data, &size) != 0) {
        fprintf(stderr, "pol_mesh_replay: missing %s\n", path);
        return 1;
    }
    if (pol_header(data, size, &header) != 0 ||
        pol_slot_spans(data, size, NULL, 0, &span_count) != -2 ||
        pol_scene_parse(data, size, &scene) != 0) {
        fprintf(stderr, "  %s: real POL mesh parse failed\n", stem);
        fails++;
        goto done;
    }
    fails += check_slot_data(stem, data, size);
    if (scene.model_count != span_count || !scene.models ||
        scene.mesh_count != expected_meshes ||
        scene.vertex_count != expected_vertices || !scene.index_count ||
        scene.index_count % 3u != 0) {
        fprintf(stderr,
                "  %s: got %u models, %u meshes, %u vertices, %u indices\n",
                stem, scene.model_count, scene.mesh_count, scene.vertex_count,
                scene.index_count);
        fails++;
    }
    for (uint32_t i = 0; i < scene.model_count; ++i) {
        const PolModel *model = &scene.models[i];
        if (model->file_start >= model->file_end || model->file_end > size ||
            model->first_mesh > scene.mesh_count ||
            model->mesh_count > scene.mesh_count - model->first_mesh ||
            (i && scene.models[i - 1u].file_end != model->file_start &&
             (scene.models[i - 1u].file_start != model->file_start ||
              scene.models[i - 1u].file_end != model->file_end))) {
            fprintf(stderr, "  %s: model %u has invalid source or mesh range\n",
                    stem, i);
            fails++;
            break;
        }
        for (uint32_t j = 0; j < model->mesh_count; ++j) {
            const PolMesh *mesh = &scene.meshes[model->first_mesh + j];
            if (mesh->slot_index != model->slot_index) {
                fprintf(stderr,
                        "  %s: model %u slot %u contains mesh from slot %u\n",
                        stem, i, model->slot_index, mesh->slot_index);
                fails++;
                break;
            }
        }
    }
    for (uint32_t i = 0; i < scene.vertex_count; ++i) {
        const PolMeshVertex *v = &scene.vertices[i];
        if (!finite_float(v->x) || !finite_float(v->y) ||
            !finite_float(v->z) || !finite_float(v->nx) ||
            !finite_float(v->ny) || !finite_float(v->nz) ||
            !finite_float(v->u) || !finite_float(v->v)) {
            fprintf(stderr, "  %s: vertex %u has a non-finite component\n", stem, i);
            fails++;
            break;
        }
    }
    for (uint32_t i = 0; i < scene.index_count; ++i) {
        if (scene.indices[i] >= scene.vertex_count) {
            fprintf(stderr, "  %s: index %u is outside the vertex array\n", stem, i);
            fails++;
            break;
        }
    }
    for (uint32_t i = 0; i < scene.mesh_count; ++i) {
        const PolMesh *mesh = &scene.meshes[i];
        if (mesh->texture_index >= header.texture_count ||
            mesh->first_index > scene.index_count ||
            mesh->index_count > scene.index_count - mesh->first_index ||
            mesh->index_count % 3u != 0) {
            fprintf(stderr, "  %s: mesh %u has invalid material or index range\n",
                    stem, i);
            fails++;
            break;
        }
    }

    /* Corrupt the first mesh's declared byte count: no read may escape its
     * tagged model span, even when the rest of the file remains present. */
    if (pol_slot_spans(data, size, NULL, 0, &span_count) != -2) {
        fails++;
        goto done;
    }
    spans = (PolSlotSpan *)calloc(span_count, sizeof *spans);
    if (!spans || pol_slot_spans(data, size, spans, span_count,
                                 &span_count) != 0) {
        fails++;
        goto done;
    }
    {
        uint8_t *bad = (uint8_t *)malloc(size);
        PolScene rejected = {0};
        if (!bad) {
            fails++;
        } else {
            memcpy(bad, data, size);
            wr32(bad + spans[0].start + 0x18u + 0x4cu, UINT32_MAX);
            if (pol_scene_parse(bad, size, &rejected) == 0) {
                fprintf(stderr, "  %s: accepted an oversized mesh data range\n", stem);
                fails++;
                pol_scene_free(&rejected);
            }
            free(bad);
        }
    }
    {
        uint8_t *bad = (uint8_t *)malloc(size);
        PolScene rejected = {0};
        if (!bad) {
            fails++;
        } else {
            memcpy(bad, data, size);
            wr32(bad + spans[0].start + 0x18u + 0x50u + 4u, UINT32_MAX);
            if (pol_scene_parse(bad, size, &rejected) == 0) {
                fprintf(stderr, "  %s: accepted an overflowing polygon count\n", stem);
                fails++;
                pol_scene_free(&rejected);
            }
            free(bad);
        }
    }
    printf("  %s: %u models, %u meshes, %u vertices, %u triangle indices\n",
           stem, scene.model_count, scene.mesh_count, scene.vertex_count,
           scene.index_count);
done:
    free(spans);
    pol_scene_free(&scene);
    free(data);
    return fails;
}

int main(void)
{
    int fails = check_model("MKAO_AKI", 25, 2452);
    fails += check_model("MKAO_JAC", 42, 2114);
    {
        uint8_t *stage = NULL;
        uint32_t size = 0;
        PolScene scene = {0};
        if (load("extract/gamedata/ST01.POL", &stage, &size) == 0) {
            const int rc = pol_scene_parse(stage, size, &scene);
            if (rc != 0 || scene.model_count != 19u ||
                scene.mesh_count != 68u || scene.vertex_count != 2381u ||
                scene.index_count != 7251u) {
                fprintf(stderr,
                        "  ST01: unexpected stage scene (rc=%d, %u/%u/%u/%u)\n",
                        rc, scene.model_count, scene.mesh_count,
                        scene.vertex_count, scene.index_count);
                fails++;
            } else {
                printf("  ST01: %u models, %u meshes, %u vertices, %u triangle indices\n",
                       scene.model_count, scene.mesh_count, scene.vertex_count,
                       scene.index_count);
            }
            pol_scene_free(&scene);
            free(stage);
        } else {
            fprintf(stderr, "  ST01: missing extracted stage package\n");
            fails++;
        }
    }
    {
        uint8_t *stage_ext = NULL;
        uint32_t size = 0;
        PolScene scene = {0};
        if (load("extract/gamedata/ST01_E.POL", &stage_ext, &size) == 0) {
            const int rc = pol_scene_parse(stage_ext, size, &scene);
            if (rc != 0 || scene.model_count != 340u ||
                scene.mesh_count != 463u || scene.vertex_count != 41033u ||
                scene.index_count != 114306u) {
                fprintf(stderr,
                        "  ST01_E: unexpected stage scene (rc=%d, %u/%u/%u/%u)\n",
                        rc, scene.model_count, scene.mesh_count,
                        scene.vertex_count, scene.index_count);
                fails++;
            } else {
                printf("  ST01_E: %u models, %u meshes, %u vertices, %u triangle indices\n",
                       scene.model_count, scene.mesh_count, scene.vertex_count,
                       scene.index_count);
            }
            pol_scene_free(&scene);
            free(stage_ext);
        } else {
            fprintf(stderr, "  ST01_E: missing extracted stage package\n");
            fails++;
        }
    }
    puts(fails ? "pol_mesh_replay: FAIL" : "pol_mesh_replay: PASS");
    return fails ? 1 : 0;
}
