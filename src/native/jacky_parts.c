#include "jacky_parts.h"

enum { JACKY_MESH_CAPACITY = 64 };

typedef struct {
    vf3_fighter_view *view;
    uint32_t mesh_index;
    uint32_t attachment_index;
    float depth;
} jacky_mesh_draw;

static const vf3_native_jacky_selector_entry jacky_selector_map[] = {
    { 0x0e21u, VF3_NATIVE_JACKY_PART_ROB_WO2, 50u, 7u },
    { 0x0e06u, VF3_NATIVE_JACKY_PART_MKAO_WO2, 3u, 5u },
    { 0x0e44u, VF3_NATIVE_JACKY_PART_ROB_WO2, 51u, 1u },
    { 0x0e0du, VF3_NATIVE_JACKY_PART_ROB_WO2, 52u, 1u },
    { 0x0e3au, VF3_NATIVE_JACKY_PART_ROB_WO2, 53u, 2u },
    { 0xffffffffu, VF3_NATIVE_JACKY_PART_EMPTY, 0u, 0u },
    { 0x0e43u, VF3_NATIVE_JACKY_PART_ROB_WO2, 54u, 1u },
    { 0x0e0cu, VF3_NATIVE_JACKY_PART_ROB_WO2, 55u, 1u },
    { 0x0e39u, VF3_NATIVE_JACKY_PART_ROB_WO2, 56u, 2u },
    { 0xffffffffu, VF3_NATIVE_JACKY_PART_EMPTY, 0u, 0u },
    { 0x0decu, VF3_NATIVE_JACKY_PART_ROB_WO2, 57u, 1u },
    { 0x0e16u, VF3_NATIVE_JACKY_PART_ROB_WO2, 58u, 5u },
    { 0x0e18u, VF3_NATIVE_JACKY_PART_ROB_WO2, 59u, 1u },
    { 0x0df0u, VF3_NATIVE_JACKY_PART_ROB_WO2, 60u, 2u },
    { 0x0de9u, VF3_NATIVE_JACKY_PART_ROB_WO2, 36u, 6u },
    { 0x0e17u, VF3_NATIVE_JACKY_PART_ROB_WO2, 61u, 1u },
    { 0x0defu, VF3_NATIVE_JACKY_PART_ROB_WO2, 62u, 2u },
    { 0x0de8u, VF3_NATIVE_JACKY_PART_ROB_WO2, 35u, 6u },
};

const vf3_native_jacky_selector_entry *
vf3_native_jacky_selector_map(size_t *count)
{
    if (count)
        *count = sizeof jacky_selector_map / sizeof jacky_selector_map[0];
    return jacky_selector_map;
}

static const PolModel *model_for_slot(const vf3_fighter_view *view,
                                      uint32_t slot)
{
    if (!view || !view->scene.models)
        return NULL;
    for (uint32_t i = 0; i < view->scene.model_count; ++i)
        if (view->scene.models[i].slot_index == slot)
            return &view->scene.models[i];
    return NULL;
}

int vf3_native_jacky_draw(
    SDL_Renderer *renderer,
    vf3_fighter_view *mkao_wo2,
    vf3_fighter_view *rob_wo2,
    const vf3_native_fighter *fighter,
    const float matrices[VF3_NATIVE_ATTACHMENT_COUNT]
                   [VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS],
    const float scene_matrix[VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS],
    float center_x, float ground_y, float scale)
{
    jacky_mesh_draw draws[JACKY_MESH_CAPACITY];
    size_t draw_count = 0;
    if (!renderer || !mkao_wo2 || !rob_wo2 || !fighter || !matrices)
        return -1;

    for (size_t entry = 0;
         entry < sizeof jacky_selector_map / sizeof jacky_selector_map[0];
         ++entry) {
        const vf3_native_jacky_selector_entry *part = &jacky_selector_map[entry];
        vf3_fighter_view *view;
        const PolModel *model;

        if (part->source == VF3_NATIVE_JACKY_PART_EMPTY)
            continue;
        view = part->source == VF3_NATIVE_JACKY_PART_MKAO_WO2
            ? mkao_wo2 : rob_wo2;
        model = model_for_slot(view, part->slot);
        if (!model || model->mesh_count < part->mesh_count ||
            model->first_mesh > view->scene.mesh_count ||
            model->mesh_count > view->scene.mesh_count - model->first_mesh ||
            draw_count + part->mesh_count > JACKY_MESH_CAPACITY)
            return -2;
        for (uint32_t mesh = 0; mesh < part->mesh_count; ++mesh) {
            jacky_mesh_draw item;
            item.view = view;
            item.mesh_index = model->first_mesh + mesh;
            item.attachment_index = (uint32_t)entry;
            if (vf3_fighter_view_attachment_mesh_depth(
                    view, item.mesh_index, matrices, scene_matrix,
                    item.attachment_index, &item.depth) != 0)
                return -3;

            /* Painter order is global across both POL packages. Drawing by
             * selector order leaves nearer pieces hidden behind later slots. */
            size_t at = draw_count;
            while (at > 0 && draws[at - 1u].depth < item.depth) {
                draws[at] = draws[at - 1u];
                --at;
            }
            draws[at] = item;
            ++draw_count;
        }
    }

    for (size_t i = 0; i < draw_count; ++i)
        if (vf3_fighter_view_draw_attachment_mesh(
                renderer, draws[i].view, fighter, draws[i].mesh_index,
                matrices, scene_matrix, draws[i].attachment_index,
                center_x, ground_y, scale) != 0)
            return -4;
    return 0;
}
