/* SDL presentation for the native fighter scene; contains no guest runtime. */
#ifndef VF3_NATIVE_FIGHTER_VIEW_H
#define VF3_NATIVE_FIGHTER_VIEW_H

#include <SDL3/SDL.h>

#include "fight.h"
#include "pol_mesh.h"

typedef struct {
    PolScene scene;
    SDL_Texture **textures;
    SDL_Vertex *vertices;
    int *indices;
    uint32_t *depth_order;
    uint32_t texture_count;
} vf3_fighter_view;

enum {
    VF3_NATIVE_BONE_COUNT = 23,
    VF3_NATIVE_BONE_MATRIX_FLOATS = 16,
    VF3_NATIVE_ATTACHMENT_COUNT = 18,
    VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS = 16
};

int vf3_fighter_view_init(SDL_Renderer *renderer,
                          const void *pol_data, uint32_t pol_size,
                          const void *tex_data, size_t tex_size,
                          vf3_fighter_view *out);
void vf3_fighter_view_free(vf3_fighter_view *view);
void vf3_fighter_view_draw(SDL_Renderer *renderer, vf3_fighter_view *view,
                           const vf3_native_fighter *fighter,
                           float center_x, float ground_y, float scale);
void vf3_fighter_view_draw_model_slot(SDL_Renderer *renderer,
                                      vf3_fighter_view *view,
                                      const vf3_native_fighter *fighter,
                                      uint32_t slot_index,
                                      float center_x, float ground_y,
                                      float scale);
/* Offline pose preview: apply one captured SH-4 column-major bone matrix,
 * expressed relative to matrix 0's translation, to one POL model slot. */
void vf3_fighter_view_draw_model_bone(
    SDL_Renderer *renderer, vf3_fighter_view *view,
    const vf3_native_fighter *fighter, uint32_t slot_index,
    const float matrices[VF3_NATIVE_BONE_COUNT][VF3_NATIVE_BONE_MATRIX_FLOATS],
    uint32_t bone_index, float center_x, float ground_y, float scale);
/* Apply the same-index row from the actor's 18-entry attachment matrix table.
 * Retail refresh dispatches selector i under matrix row i for the ordinary
 * attachment entries. The root translation is taken from row zero. */
void vf3_fighter_view_draw_model_attachment(
    SDL_Renderer *renderer, vf3_fighter_view *view,
    const vf3_native_fighter *fighter, uint32_t slot_index,
    const float matrices[VF3_NATIVE_ATTACHMENT_COUNT]
                   [VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS],
    uint32_t attachment_index, float center_x, float ground_y, float scale);
/* Apply scene * attachment[index], using scene * attachment[0] as the actor
 * origin. This mirrors the retail draw helper's matrix composition. */
void vf3_fighter_view_draw_model_attachment_scene(
    SDL_Renderer *renderer, vf3_fighter_view *view,
    const vf3_native_fighter *fighter, uint32_t slot_index,
    const float matrices[VF3_NATIVE_ATTACHMENT_COUNT]
                   [VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS],
    const float scene_matrix[VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS],
    uint32_t attachment_index, float center_x, float ground_y, float scale);
/* Depth-sort the recovered multi-slot fighter by its transformed POL mesh
 * centers, then draw one mesh at a time with its native attachment matrix. */
int vf3_fighter_view_attachment_mesh_depth(
    const vf3_fighter_view *view, uint32_t mesh_index,
    const float matrices[VF3_NATIVE_ATTACHMENT_COUNT]
                   [VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS],
    const float scene_matrix[VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS],
    uint32_t attachment_index, float *out_depth);
int vf3_fighter_view_draw_attachment_mesh(
    SDL_Renderer *renderer, vf3_fighter_view *view,
    const vf3_native_fighter *fighter, uint32_t mesh_index,
    const float matrices[VF3_NATIVE_ATTACHMENT_COUNT]
                   [VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS],
    const float scene_matrix[VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS],
    uint32_t attachment_index, float center_x, float ground_y, float scale);
void vf3_stage_view_draw(SDL_Renderer *renderer, vf3_fighter_view *view,
                         float center_x, float ground_y, float scale);

#endif
