#include "pol_mesh.h"

#include "pol.h"

#include <stdlib.h>
#include <string.h>

enum { POL_MODEL_HEADER_BYTES = 0x18, POL_MESH_HEADER_BYTES = 0x50,
       POL_POLYGON_HEADER_BYTES = 8, POL_VERTEX_A_BYTES = 0x20,
       POL_VERTEX_B_BYTES = 8 };

typedef struct {
    uint32_t file_offset;
    uint32_t vertex_index;
} PolSourceVertex;

typedef struct {
    PolScene scene;
    PolSourceVertex *sources;
    uint32_t source_count;
    uint32_t source_capacity;
    uint32_t vertex_capacity;
    uint32_t index_capacity;
    uint32_t mesh_capacity;
    uint32_t model_capacity;
} PolBuild;

static uint32_t rd32(const uint8_t *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static float rdf32(const uint8_t *p)
{
    const uint32_t bits = rd32(p);
    float value;
    memcpy(&value, &bits, sizeof value);
    return value;
}

static int finite_word(uint32_t bits)
{
    return (bits & 0x7f800000u) != 0x7f800000u;
}

static int nan_word(uint32_t bits)
{
    return (bits & 0x7f800000u) == 0x7f800000u &&
           (bits & 0x007fffffu) != 0;
}

static int grow_array(void **memory, uint32_t *capacity, uint32_t needed,
                      size_t element_size)
{
    uint32_t next;
    void *grown;
    if (needed <= *capacity)
        return 1;
    if (element_size == 0 || (uint64_t)needed * element_size > SIZE_MAX)
        return 0;
    next = *capacity ? *capacity : 64u;
    while (next < needed) {
        if (next > UINT32_MAX / 2u) {
            next = needed;
            break;
        }
        next *= 2u;
    }
    if ((uint64_t)next * element_size > SIZE_MAX)
        next = needed;
    grown = realloc(*memory, (size_t)next * element_size);
    if (!grown)
        return 0;
    *memory = grown;
    *capacity = next;
    return 1;
}

static int source_find(const PolBuild *b, uint32_t file_offset,
                       uint32_t *vertex_index)
{
    uint32_t lo = 0, hi = b->source_count;
    while (lo < hi) {
        const uint32_t mid = lo + (hi - lo) / 2u;
        if (b->sources[mid].file_offset < file_offset)
            lo = mid + 1u;
        else
            hi = mid;
    }
    if (lo == b->source_count || b->sources[lo].file_offset != file_offset)
        return 0;
    *vertex_index = b->sources[lo].vertex_index;
    return 1;
}

static int source_add(PolBuild *b, uint32_t file_offset,
                      uint32_t vertex_index)
{
    if (b->source_count &&
        file_offset <= b->sources[b->source_count - 1u].file_offset)
        return 0;
    if (b->source_count == UINT32_MAX ||
        !grow_array((void **)&b->sources, &b->source_capacity,
                    b->source_count + 1u, sizeof *b->sources))
        return -1;
    b->sources[b->source_count].file_offset = file_offset;
    b->sources[b->source_count].vertex_index = vertex_index;
    ++b->source_count;
    return 1;
}

static int append_vertex(PolBuild *b, const uint8_t *data,
                         uint32_t record_offset, uint32_t *vertex_index)
{
    PolMeshVertex v;
    const uint8_t *p = data + record_offset;
    const uint32_t words[8] = {
        rd32(p), rd32(p + 4), rd32(p + 8), rd32(p + 12),
        rd32(p + 16), rd32(p + 20), rd32(p + 24), rd32(p + 28)
    };
    int map_rc;
    for (uint32_t i = 0; i < 8; ++i)
        if (!finite_word(words[i]))
            return -2;
    v.x = rdf32(p);
    v.y = rdf32(p + 4);
    v.z = rdf32(p + 8);
    v.nx = rdf32(p + 12);
    v.ny = rdf32(p + 16);
    v.nz = rdf32(p + 20);
    v.u = rdf32(p + 24);
    v.v = rdf32(p + 28);
    if (b->scene.vertex_count == UINT32_MAX ||
        !grow_array((void **)&b->scene.vertices, &b->vertex_capacity,
                    b->scene.vertex_count + 1u,
                    sizeof *b->scene.vertices))
        return -3;
    *vertex_index = b->scene.vertex_count;
    b->scene.vertices[b->scene.vertex_count++] = v;
    map_rc = source_add(b, record_offset, *vertex_index);
    if (map_rc <= 0)
        return map_rc < 0 ? -3 : -2;
    return 0;
}

static int append_reference(PolBuild *b, const uint8_t *data,
                            uint32_t record_offset, uint32_t *vertex_index)
{
    const uint32_t pointer = rd32(data + record_offset + 4u);
    const uint32_t back = 0xfffffff8u - pointer;
    uint32_t target, map_rc;
    if (pointer >= 0xfffffff8u || back == 0 || back > record_offset)
        return -4;
    target = record_offset - back;
    if (!source_find(b, target, vertex_index))
        return -4;
    map_rc = source_add(b, record_offset, *vertex_index);
    if (map_rc <= 0)
        return map_rc < 0 ? -3 : -2;
    return 0;
}

static int append_index(PolBuild *b, uint32_t index)
{
    if (index >= b->scene.vertex_count || b->scene.index_count == UINT32_MAX ||
        !grow_array((void **)&b->scene.indices, &b->index_capacity,
                    b->scene.index_count + 1u, sizeof *b->scene.indices))
        return index >= b->scene.vertex_count ? -2 : -3;
    b->scene.indices[b->scene.index_count++] = index;
    return 0;
}

static int append_triangle(PolBuild *b, uint32_t a, uint32_t c, uint32_t d)
{
    int rc;
    if (a == c || c == d || a == d)
        return 0;
    rc = append_index(b, a);
    if (rc != 0) return rc;
    rc = append_index(b, c);
    if (rc != 0) return rc;
    return append_index(b, d);
}

static int append_mesh(PolBuild *b, const uint8_t *header,
                       uint32_t slot_index, uint32_t *mesh_index)
{
    PolMesh mesh;
    static const uint8_t float_offsets[] = {
        0x10, 0x14, 0x18, 0x1c, 0x30, 0x34, 0x38
    };
    for (size_t i = 0; i < sizeof float_offsets; ++i)
        if (!finite_word(rd32(header + float_offsets[i])))
            return -2;
    if (b->scene.mesh_count == UINT32_MAX ||
        !grow_array((void **)&b->scene.meshes, &b->mesh_capacity,
                    b->scene.mesh_count + 1u, sizeof *b->scene.meshes))
        return -3;
    memset(&mesh, 0, sizeof mesh);
    mesh.slot_index = slot_index;
    mesh.flags = rd32(header + 8);
    mesh.texture_index = rd32(header + 0x20);
    mesh.first_index = b->scene.index_count;
    mesh.center[0] = rdf32(header + 0x10);
    mesh.center[1] = rdf32(header + 0x14);
    mesh.center[2] = rdf32(header + 0x18);
    mesh.radius = rdf32(header + 0x1c);
    mesh.color[0] = rdf32(header + 0x30);
    mesh.color[1] = rdf32(header + 0x34);
    mesh.color[2] = rdf32(header + 0x38);
    *mesh_index = b->scene.mesh_count;
    b->scene.meshes[b->scene.mesh_count++] = mesh;
    return 0;
}

static int parse_mesh_data(PolBuild *b, const uint8_t *data, uint32_t size,
                           uint32_t mesh_off, uint32_t data_off,
                           uint32_t data_len, uint32_t slot_index,
                           uint32_t texture_count)
{
    const uint32_t data_end = data_off + data_len;
    uint32_t mesh_index, pos;
    int rc;
    if (data_end < data_off || data_end > size || data_len == 0)
        return -2;
    const uint32_t texture_index = rd32(data + mesh_off + 0x20);
    if (texture_index != POL_TEXTURE_NONE && texture_index >= texture_count)
        return -2;
    rc = append_mesh(b, data + mesh_off, slot_index, &mesh_index);
    if (rc != 0)
        return rc;
    for (pos = data_off; pos < data_end;) {
        if (data_end - pos < POL_POLYGON_HEADER_BYTES)
            return -2;
        const uint32_t type = rd32(data + pos);
        const uint32_t count = rd32(data + pos + 4u);
        const uint64_t vertex_count64 = (uint64_t)count *
                                         ((type & 8u) ? 3u : 1u);
        uint32_t *polygon_vertices;
        uint32_t vertex_count;
        pos += POL_POLYGON_HEADER_BYTES;
        if (vertex_count64 > UINT32_MAX ||
            vertex_count64 > (data_end - pos) / POL_VERTEX_B_BYTES)
            return -2;
        vertex_count = (uint32_t)vertex_count64;
        if (vertex_count) {
            if ((uint64_t)vertex_count * sizeof *polygon_vertices > SIZE_MAX)
                return -3;
            polygon_vertices = (uint32_t *)malloc((size_t)vertex_count *
                                                    sizeof *polygon_vertices);
            if (!polygon_vertices)
                return -3;
        } else {
            polygon_vertices = NULL;
        }
        for (uint32_t i = 0; i < vertex_count; ++i) {
            const uint32_t remaining = data_end - pos;
            const int is_reference = remaining >= POL_VERTEX_B_BYTES &&
                                     nan_word(rd32(data + pos + 4u));
            if (is_reference) {
                rc = append_reference(b, data, pos, &polygon_vertices[i]);
                if (rc != 0) {
                    free(polygon_vertices);
                    return rc;
                }
                pos += POL_VERTEX_B_BYTES;
            } else {
                if (remaining < POL_VERTEX_A_BYTES) {
                    free(polygon_vertices);
                    return -2;
                }
                rc = append_vertex(b, data, pos, &polygon_vertices[i]);
                if (rc != 0) {
                    free(polygon_vertices);
                    return rc;
                }
                pos += POL_VERTEX_A_BYTES;
            }
        }
        if (type & 8u) {
            for (uint32_t i = 0; i < vertex_count; i += 3u) {
                rc = append_triangle(b, polygon_vertices[i],
                                     polygon_vertices[i + 1u],
                                     polygon_vertices[i + 2u]);
                if (rc != 0) {
                    free(polygon_vertices);
                    return rc;
                }
            }
        } else {
            for (uint32_t i = 2; i < vertex_count; ++i) {
                const uint32_t a = (i & 1u) ? polygon_vertices[i - 1u]
                                            : polygon_vertices[i - 2u];
                const uint32_t c = (i & 1u) ? polygon_vertices[i - 2u]
                                            : polygon_vertices[i - 1u];
                rc = append_triangle(b, a, c, polygon_vertices[i]);
                if (rc != 0) {
                    free(polygon_vertices);
                    return rc;
                }
            }
        }
        free(polygon_vertices);
    }
    if (pos != data_end)
        return -2;
    b->scene.meshes[mesh_index].index_count =
        b->scene.index_count - b->scene.meshes[mesh_index].first_index;
    return 0;
}

static int parse_model(PolBuild *b, const uint8_t *data, uint32_t size,
                       const PolSlotSpan *span, uint32_t texture_count)
{
    uint32_t pos, model_index;
    if (span->start > span->end || span->end > size ||
        span->end - span->start < POL_MODEL_HEADER_BYTES + 8u)
        return -2;
    if (b->scene.model_count == UINT32_MAX ||
        !grow_array((void **)&b->scene.models, &b->model_capacity,
                    b->scene.model_count + 1u, sizeof *b->scene.models))
        return -3;
    model_index = b->scene.model_count;
    memset(&b->scene.models[model_index], 0,
           sizeof b->scene.models[model_index]);
    b->scene.models[model_index].slot_index = span->slot_index;
    b->scene.models[model_index].file_start = span->start;
    b->scene.models[model_index].file_end = span->end;
    b->scene.models[model_index].first_mesh = b->scene.mesh_count;
    pos = span->start + POL_MODEL_HEADER_BYTES;
    while (pos <= span->end && span->end - pos >= 8u) {
        const uint32_t marker = rd32(data + pos);
        if (marker == 0) {
            pos += 8u; /* model end: zero word followed by its vertex total */
            for (; pos < span->end; ++pos)
                if (data[pos] != 0)
                    return -2;
            b->scene.models[model_index].mesh_count =
                b->scene.mesh_count - b->scene.models[model_index].first_mesh;
            ++b->scene.model_count;
            return 0;
        }
        if (span->end - pos < POL_MESH_HEADER_BYTES)
            return -2;
        {
            const uint32_t vertex_bytes = rd32(data + pos + 0x4cu);
            const uint32_t vertex_data = pos + POL_MESH_HEADER_BYTES;
            int rc;
            if (vertex_data < pos || vertex_bytes > span->end - vertex_data)
                return -2;
            rc = parse_mesh_data(b, data, size, pos, vertex_data,
                                 vertex_bytes, span->slot_index,
                                 texture_count);
            if (rc != 0)
                return rc;
            pos = vertex_data + vertex_bytes;
        }
    }
    return -2; /* tagged spans must terminate with the 8-byte model end */
}

void pol_scene_free(PolScene *scene)
{
    if (!scene)
        return;
    free(scene->vertices);
    free(scene->indices);
    free(scene->meshes);
    free(scene->models);
    memset(scene, 0, sizeof *scene);
}

int pol_scene_parse(const void *vdata, uint32_t size, PolScene *out)
{
    const uint8_t *data = (const uint8_t *)vdata;
    PolBuild build;
    PolHeader header;
    PolSlotSpan *spans = NULL;
    uint32_t span_count = 0;
    int rc;
    if (!data || !out)
        return -1;
    memset(out, 0, sizeof *out);
    memset(&build, 0, sizeof build);
    if (pol_header(data, size, &header) != 0)
        return -2;
    rc = pol_slot_spans(data, size, NULL, 0, &span_count);
    if (rc == 0 && span_count == 0) {
        *out = build.scene;
        return 0;
    }
    if (rc != -2 || span_count == 0)
        return -2;
    if ((uint64_t)span_count * sizeof *spans > SIZE_MAX)
        return -3;
    spans = (PolSlotSpan *)malloc((size_t)span_count * sizeof *spans);
    if (!spans)
        return -3;
    rc = pol_slot_spans(data, size, spans, span_count, &span_count);
    if (rc != 0) {
        free(spans);
        return -2;
    }
    for (uint32_t i = 0; i < span_count; ++i) {
        rc = parse_model(&build, data, size, &spans[i], header.texture_count);
        if (rc != 0)
            break;
    }
    free(spans);
    free(build.sources);
    if (rc != 0) {
        pol_scene_free(&build.scene);
        return rc;
    }
    *out = build.scene;
    return 0;
}
