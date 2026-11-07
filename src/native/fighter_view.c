#include "fighter_view.h"
#include "matrix.h"

#include "pol.h"
#include "pvr_texture.h"

#include <limits.h>
#include <stdlib.h>
#include <string.h>

void vf3_fighter_view_free(vf3_fighter_view *view)
{
    if (!view)
        return;
    if (view->textures) {
        for (uint32_t i = 0; i < view->texture_count; ++i)
            if (view->textures[i])
                SDL_DestroyTexture(view->textures[i]);
    }
    free(view->textures);
    free(view->vertices);
    free(view->indices);
    free(view->depth_order);
    pol_scene_free(&view->scene);
    memset(view, 0, sizeof *view);
}

int vf3_fighter_view_init(SDL_Renderer *renderer,
                          const void *pol_data, uint32_t pol_size,
                          const void *tex_data, size_t tex_size,
                          vf3_fighter_view *out)
{
    PolHeader header;
    PolTextureDesc *descs = NULL;
    uint32_t desc_count = 0;
    vf3_fighter_view view;
    int result = -1;
    if (!renderer || !pol_data || !tex_data || !out)
        return -1;
    memset(out, 0, sizeof *out);
    memset(&view, 0, sizeof view);
    if (pol_header(pol_data, pol_size, &header) != 0 ||
        pol_textures(pol_data, pol_size, NULL, 0, &desc_count) != -2 ||
        desc_count != header.texture_count || desc_count == 0 ||
        desc_count > (uint32_t)INT_MAX)
        goto done;
    descs = (PolTextureDesc *)calloc(desc_count, sizeof *descs);
    view.textures = (SDL_Texture **)calloc(desc_count, sizeof *view.textures);
    if (!descs || !view.textures ||
        pol_textures(pol_data, pol_size, descs, desc_count, &desc_count) != 0 ||
        pol_scene_parse(pol_data, pol_size, &view.scene) != 0)
        goto done;
    view.texture_count = desc_count;
    if (view.scene.vertex_count > (uint32_t)INT_MAX ||
        view.scene.index_count > (uint32_t)INT_MAX ||
        (uint64_t)view.scene.vertex_count * sizeof *view.vertices > SIZE_MAX ||
        (uint64_t)view.scene.index_count * sizeof *view.indices > SIZE_MAX)
        goto done;
    view.vertices = (SDL_Vertex *)malloc((size_t)view.scene.vertex_count *
                                         sizeof *view.vertices);
    view.indices = (int *)malloc((size_t)view.scene.index_count *
                                 sizeof *view.indices);
    if (view.scene.mesh_count > SIZE_MAX / sizeof *view.depth_order)
        goto done;
    view.depth_order = (uint32_t *)malloc((size_t)view.scene.mesh_count *
                                          sizeof *view.depth_order);
    if ((view.scene.vertex_count && !view.vertices) ||
        (view.scene.index_count && !view.indices) ||
        (view.scene.mesh_count && !view.depth_order))
        goto done;
    for (uint32_t i = 0; i < view.scene.index_count; ++i) {
        if (view.scene.indices[i] > (uint32_t)INT_MAX)
            goto done;
        view.indices[i] = (int)view.scene.indices[i];
    }
    for (uint32_t i = 0; i < view.scene.mesh_count; ++i) {
        uint32_t at = i;
        view.depth_order[i] = i;
        /* SDL_RenderGeometry has no depth buffer. Fighter models use Y as
         * camera depth, so draw the far (smaller Y) mesh centers first. */
        while (at > 0 &&
               view.scene.meshes[view.depth_order[at - 1u]].center[1] >
                   view.scene.meshes[view.depth_order[at]].center[1]) {
            const uint32_t swap = view.depth_order[at - 1u];
            view.depth_order[at - 1u] = view.depth_order[at];
            view.depth_order[at] = swap;
            --at;
        }
    }
    for (uint32_t i = 0; i < desc_count; ++i) {
        const uint64_t pixel_count = (uint64_t)descs[i].width * descs[i].height;
        uint32_t *pixels;
        if (!descs[i].width || !descs[i].height || pixel_count > SIZE_MAX / 4u ||
            (uint64_t)descs[i].width * 4u > INT_MAX)
            goto done;
        pixels = (uint32_t *)malloc((size_t)pixel_count * sizeof *pixels);
        if (!pixels)
            goto done;
        if (vf3_pvr_texture_decode(tex_data, tex_size, &descs[i], pixels,
                                   (size_t)pixel_count) != 0) {
            free(pixels);
            goto done;
        }
        view.textures[i] = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                                              SDL_TEXTUREACCESS_STATIC,
                                              descs[i].width, descs[i].height);
        if (!view.textures[i] ||
            !SDL_UpdateTexture(view.textures[i], NULL, pixels,
                               (int)descs[i].width * (int)sizeof *pixels) ||
            !SDL_SetTextureBlendMode(view.textures[i], SDL_BLENDMODE_BLEND) ||
            !SDL_SetTextureScaleMode(view.textures[i], SDL_SCALEMODE_NEAREST)) {
            free(pixels);
            goto done;
        }
        free(pixels);
    }
    *out = view;
    memset(&view, 0, sizeof view);
    result = 0;
done:
    free(descs);
    vf3_fighter_view_free(&view);
    return result;
}

static void draw_meshes(SDL_Renderer *renderer, vf3_fighter_view *view,
                        int filter_slot, uint32_t slot_index)
{
    for (uint32_t i = 0; i < view->scene.mesh_count; ++i) {
        const uint32_t mesh_index = filter_slot ? view->depth_order[i] : i;
        const PolMesh *mesh = &view->scene.meshes[mesh_index];
        if (filter_slot && mesh->slot_index != slot_index)
            continue;
        SDL_Texture *texture = NULL;
        if ((mesh->texture_index != POL_TEXTURE_NONE &&
             mesh->texture_index >= view->texture_count) || mesh->index_count < 3u ||
            mesh->first_index > view->scene.index_count ||
            mesh->index_count > view->scene.index_count - mesh->first_index)
            continue;
        if (mesh->texture_index != POL_TEXTURE_NONE)
            texture = view->textures[mesh->texture_index];
        SDL_RenderGeometry(renderer, texture,
                           view->vertices, (int)view->scene.vertex_count,
                           view->indices + mesh->first_index,
                           (int)mesh->index_count);
    }
}

static void fighter_view_draw(SDL_Renderer *renderer, vf3_fighter_view *view,
                              const vf3_native_fighter *fighter,
                              int filter_slot, uint32_t slot_index,
                              float center_x, float ground_y, float scale,
                              const float (*matrix)[16],
                              const float *root_translation)
{
    if (!renderer || !view || !fighter || !view->vertices ||
        !view->scene.vertex_count)
        return;
    for (uint32_t i = 0; i < view->scene.vertex_count; ++i) {
        const PolMeshVertex *source = &view->scene.vertices[i];
        SDL_Vertex *target = &view->vertices[i];
        const float bob = fighter->action == VF3_NATIVE_IDLE ? 0.0f : 0.012f;
        if (matrix) {
            const float point[3] = { source->x, source->y, source->z };
            float world[3];
            vf3_native_matrix_transform_point(matrix[0], point, world);
            world[0] -= root_translation[0];
            world[1] -= root_translation[1];
            world[2] -= root_translation[2];
            target->position.x = center_x + world[0] *
                                 (float)fighter->facing * scale;
            /* The matrix has moved local POL coordinates into scene space:
             * Y is vertical and Z is depth, as in the ST01 stage projection. */
            target->position.y = ground_y -
                (world[1] * 0.9759001f + world[2] * 0.2182179f + bob) * scale;
        } else {
            target->position.x = center_x + source->x * (float)fighter->facing * scale;
            /* Fighter POL vertices use X/Z for the body plane and Y for depth. */
            target->position.y = ground_y - (source->z + bob) * scale +
                                 source->y * scale * 0.16f;
        }
        target->color.r = 1.0f;
        target->color.g = 1.0f;
        target->color.b = 1.0f;
        target->color.a = 1.0f;
        target->tex_coord.x = source->u;
        target->tex_coord.y = -source->v;
    }
    draw_meshes(renderer, view, filter_slot, slot_index);
}

void vf3_fighter_view_draw(SDL_Renderer *renderer, vf3_fighter_view *view,
                           const vf3_native_fighter *fighter,
                           float center_x, float ground_y, float scale)
{
    fighter_view_draw(renderer, view, fighter, 0, 0, center_x, ground_y, scale,
                      NULL, NULL);
}

void vf3_fighter_view_draw_model_slot(SDL_Renderer *renderer,
                                      vf3_fighter_view *view,
                                      const vf3_native_fighter *fighter,
                                      uint32_t slot_index,
                                      float center_x, float ground_y,
                                      float scale)
{
    fighter_view_draw(renderer, view, fighter, 1, slot_index,
                      center_x, ground_y, scale, NULL, NULL);
}

void vf3_fighter_view_draw_model_bone(
    SDL_Renderer *renderer, vf3_fighter_view *view,
    const vf3_native_fighter *fighter, uint32_t slot_index,
    const float matrices[VF3_NATIVE_BONE_COUNT][VF3_NATIVE_BONE_MATRIX_FLOATS],
    uint32_t bone_index, float center_x, float ground_y, float scale)
{
    if (!matrices || bone_index >= VF3_NATIVE_BONE_COUNT)
        return;
    fighter_view_draw(renderer, view, fighter, 1, slot_index,
                      center_x, ground_y, scale, &matrices[bone_index],
                      &matrices[0][12]);
}

void vf3_fighter_view_draw_model_attachment(
    SDL_Renderer *renderer, vf3_fighter_view *view,
    const vf3_native_fighter *fighter, uint32_t slot_index,
    const float matrices[VF3_NATIVE_ATTACHMENT_COUNT]
                   [VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS],
    uint32_t attachment_index, float center_x, float ground_y, float scale)
{
    if (!matrices || attachment_index >= VF3_NATIVE_ATTACHMENT_COUNT)
        return;
    fighter_view_draw(renderer, view, fighter, 1, slot_index,
                      center_x, ground_y, scale, &matrices[attachment_index],
                      &matrices[0][12]);
}

static int attachment_transform(
    const float matrices[VF3_NATIVE_ATTACHMENT_COUNT][16],
    const float scene_matrix[16], uint32_t attachment_index,
    float matrix[16], float root_translation[3])
{
    float root[16];
    if (!matrices || attachment_index >= VF3_NATIVE_ATTACHMENT_COUNT)
        return -1;
    if (scene_matrix) {
        vf3_native_matrix_multiply(scene_matrix, matrices[attachment_index], matrix);
        vf3_native_matrix_multiply(scene_matrix, matrices[0], root);
        root_translation[0] = root[12];
        root_translation[1] = root[13];
        root_translation[2] = root[14];
    } else {
        memcpy(matrix, matrices[attachment_index], sizeof root);
        root_translation[0] = matrices[0][12];
        root_translation[1] = matrices[0][13];
        root_translation[2] = matrices[0][14];
    }
    return 0;
}

static void transform_attachment_point(const float matrix[16],
                                       const float root_translation[3],
                                       const float point[3],
                                       float result[3])
{
    vf3_native_matrix_transform_point(matrix, point, result);
    result[0] -= root_translation[0];
    result[1] -= root_translation[1];
    result[2] -= root_translation[2];
}

int vf3_fighter_view_attachment_mesh_depth(
    const vf3_fighter_view *view, uint32_t mesh_index,
    const float matrices[VF3_NATIVE_ATTACHMENT_COUNT][16],
    const float scene_matrix[16], uint32_t attachment_index,
    float *out_depth)
{
    const PolMesh *mesh;
    float matrix[16], root_translation[3], point[3], world[3];
    if (!view || !out_depth || !view->scene.meshes ||
        mesh_index >= view->scene.mesh_count ||
        attachment_transform(matrices, scene_matrix, attachment_index,
                             matrix, root_translation) != 0)
        return -1;
    mesh = &view->scene.meshes[mesh_index];
    memcpy(point, mesh->center, sizeof point);
    transform_attachment_point(matrix, root_translation, point, world);

    /* Match the existing matrix-driven fighter projection: attachment rows
     * are already in the renderer's Y-up frame, with low-camera depth along
     * (0, -0.2182, 0.9759). Larger camera depth is farther away. */
    *out_depth = -0.2182179f * world[1] + 0.9759001f * world[2];
    return 0;
}

int vf3_fighter_view_draw_attachment_mesh(
    SDL_Renderer *renderer, vf3_fighter_view *view,
    const vf3_native_fighter *fighter, uint32_t mesh_index,
    const float matrices[VF3_NATIVE_ATTACHMENT_COUNT][16],
    const float scene_matrix[16], uint32_t attachment_index,
    float center_x, float ground_y, float scale)
{
    const PolMesh *mesh;
    float matrix[16], root_translation[3];
    if (!renderer || !view || !fighter || !view->scene.meshes ||
        !view->scene.vertices || !view->scene.indices || !view->vertices ||
        mesh_index >= view->scene.mesh_count ||
        attachment_transform(matrices, scene_matrix, attachment_index,
                             matrix, root_translation) != 0)
        return -1;

    mesh = &view->scene.meshes[mesh_index];
    if (mesh->index_count < 3u ||
        mesh->first_index > view->scene.index_count ||
        mesh->index_count > view->scene.index_count - mesh->first_index ||
        (mesh->texture_index != POL_TEXTURE_NONE &&
         mesh->texture_index >= view->texture_count))
        return -1;

    const float bob = fighter->action == VF3_NATIVE_IDLE ? 0.0f : 0.012f;
    for (uint32_t at = mesh->first_index;
         at < mesh->first_index + mesh->index_count; ++at) {
        const uint32_t vertex_index = view->scene.indices[at];
        if (vertex_index >= view->scene.vertex_count)
            return -1;
        const PolMeshVertex *source = &view->scene.vertices[vertex_index];
        SDL_Vertex *target = &view->vertices[vertex_index];
        float world[3];
        const float point[3] = { source->x, source->y, source->z };
        transform_attachment_point(matrix, root_translation, point, world);
        if (scene_matrix) {
            const float camera_distance = 105.0f;
            const float depth = camera_distance - world[1] * 0.2182179f +
                                world[2] * 0.9759001f;
            const float perspective = camera_distance /
                                     (depth > 1.0f ? depth : 1.0f);
            const float camera_up = world[1] * 0.9759001f +
                                    world[2] * 0.2182179f;
            target->position.x = center_x + world[0] *
                (float)fighter->facing * scale * perspective;
            target->position.y = ground_y - (camera_up + bob) *
                                 scale * perspective;
        } else {
            target->position.x = center_x +
                                 world[0] * (float)fighter->facing * scale;
            target->position.y = ground_y -
                (world[1] * 0.9759001f + world[2] * 0.2182179f + bob) * scale;
        }
        target->color.r = 1.0f;
        target->color.g = 1.0f;
        target->color.b = 1.0f;
        target->color.a = 1.0f;
        target->tex_coord.x = source->u;
        target->tex_coord.y = -source->v;
    }

    SDL_Texture *texture = mesh->texture_index == POL_TEXTURE_NONE
        ? NULL : view->textures[mesh->texture_index];
    if (!SDL_RenderGeometry(renderer, texture, view->vertices,
                            (int)view->scene.vertex_count,
                            view->indices + mesh->first_index,
                            (int)mesh->index_count))
        return -2;
    return 0;
}

void vf3_fighter_view_draw_model_attachment_scene(
    SDL_Renderer *renderer, vf3_fighter_view *view,
    const vf3_native_fighter *fighter, uint32_t slot_index,
    const float matrices[VF3_NATIVE_ATTACHMENT_COUNT]
                   [VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS],
    const float scene_matrix[VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS],
    uint32_t attachment_index, float center_x, float ground_y, float scale)
{
    float matrix[16], root[16];
    if (!matrices || !scene_matrix || attachment_index >= VF3_NATIVE_ATTACHMENT_COUNT)
        return;
    vf3_native_matrix_multiply(scene_matrix, matrices[attachment_index], matrix);
    vf3_native_matrix_multiply(scene_matrix, matrices[0], root);
    fighter_view_draw(renderer, view, fighter, 1, slot_index,
                      center_x, ground_y, scale, &matrix, &root[12]);
}

void vf3_stage_view_draw(SDL_Renderer *renderer, vf3_fighter_view *view,
                         float center_x, float ground_y, float scale)
{
    /* ST01 coordinates put Y on the vertical axis and X/Z on the arena
     * plane. Project them from a low camera looking along +Z. The previous
     * affine projection treated the far edge exactly like the near edge,
     * which made the arena read as a flat overhead disc. */
    const float target_y = 4.5f;
    const float camera_distance = 105.0f;
    const float up_y = 0.9759001f;
    const float up_z = 0.2182179f;
    const float forward_y = -up_z;
    const float forward_z = up_y;
    if (!renderer || !view || !view->vertices || !view->scene.vertex_count)
        return;
    for (uint32_t i = 0; i < view->scene.vertex_count; ++i) {
        const PolMeshVertex *source = &view->scene.vertices[i];
        SDL_Vertex *target = &view->vertices[i];
        const float relative_y = source->y - target_y;
        const float depth = camera_distance + relative_y * forward_y +
                            source->z * forward_z;
        const float perspective = camera_distance / (depth > 1.0f ? depth : 1.0f);
        const float projected_scale = scale * perspective;
        const float camera_up = relative_y * up_y + source->z * up_z;
        target->position.x = center_x + source->x * projected_scale;
        target->position.y = ground_y - camera_up * projected_scale;
        target->color.r = 1.0f;
        target->color.g = 1.0f;
        target->color.b = 1.0f;
        target->color.a = 1.0f;
        target->tex_coord.x = source->u;
        target->tex_coord.y = -source->v;
    }
    draw_meshes(renderer, view, 0, 0);
}
