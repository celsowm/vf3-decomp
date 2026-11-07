#include "akira_parts.h"

enum { AKIRA_MESH_CAPACITY = 32 };

typedef struct {
    vf3_fighter_view *view;
    uint32_t mesh_index;
    uint32_t attachment_index;
    float depth;
} akira_mesh_draw;

static const vf3_native_akira_selector_entry akira_selector_map[] = {
    { 0x025du, VF3_NATIVE_AKIRA_PART_ROB_AKI, 50u, 3u },
    { 0x0242u, VF3_NATIVE_AKIRA_PART_MKAO_AKI, 3u, 7u },
    { 0x0282u, VF3_NATIVE_AKIRA_PART_ROB_AKI, 51u, 1u },
    { 0x0249u, VF3_NATIVE_AKIRA_PART_ROB_AKI, 52u, 1u },
    { 0x0278u, VF3_NATIVE_AKIRA_PART_ROB_AKI, 53u, 2u },
    { 0xffffffffu, VF3_NATIVE_AKIRA_PART_EMPTY, 0u, 0u },
    { 0x0281u, VF3_NATIVE_AKIRA_PART_ROB_AKI, 54u, 1u },
    { 0x0248u, VF3_NATIVE_AKIRA_PART_ROB_AKI, 55u, 1u },
    { 0x0277u, VF3_NATIVE_AKIRA_PART_ROB_AKI, 56u, 2u },
    { 0xffffffffu, VF3_NATIVE_AKIRA_PART_EMPTY, 0u, 0u },
    { 0x0227u, VF3_NATIVE_AKIRA_PART_ROB_AKI, 57u, 1u },
    { 0x0252u, VF3_NATIVE_AKIRA_PART_ROB_AKI, 58u, 1u },
    { 0x0254u, VF3_NATIVE_AKIRA_PART_ROB_AKI, 59u, 1u },
    { 0x022fu, VF3_NATIVE_AKIRA_PART_ROB_AKI, 60u, 3u },
    { 0x0224u, VF3_NATIVE_AKIRA_PART_ROB_AKI, 36u, 2u },
    { 0x0253u, VF3_NATIVE_AKIRA_PART_ROB_AKI, 61u, 1u },
    { 0x022eu, VF3_NATIVE_AKIRA_PART_ROB_AKI, 62u, 3u },
    { 0x0223u, VF3_NATIVE_AKIRA_PART_ROB_AKI, 35u, 2u },
};

const vf3_native_akira_selector_entry *
vf3_native_akira_selector_map(size_t *count)
{
    if (count)
        *count = sizeof akira_selector_map / sizeof akira_selector_map[0];
    return akira_selector_map;
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

int vf3_native_akira_draw(
    SDL_Renderer *renderer,
    vf3_fighter_view *mkao_aki,
    vf3_fighter_view *rob_aki,
    const vf3_native_fighter *fighter,
    const float matrices[VF3_NATIVE_ATTACHMENT_COUNT]
                   [VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS],
    const float scene_matrix[VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS],
    float center_x, float ground_y, float scale)
{
    akira_mesh_draw draws[AKIRA_MESH_CAPACITY];
    size_t draw_count = 0;
    if (!renderer || !mkao_aki || !rob_aki || !fighter || !matrices)
        return -1;

    for (size_t entry = 0;
         entry < sizeof akira_selector_map / sizeof akira_selector_map[0];
         ++entry) {
        const vf3_native_akira_selector_entry *part = &akira_selector_map[entry];
        vf3_fighter_view *view;
        const PolModel *model;

        if (part->source == VF3_NATIVE_AKIRA_PART_EMPTY)
            continue;
        view = part->source == VF3_NATIVE_AKIRA_PART_MKAO_AKI
            ? mkao_aki : rob_aki;
        model = model_for_slot(view, part->slot);
        if (!model || model->mesh_count < part->mesh_count ||
            model->first_mesh > view->scene.mesh_count ||
            model->mesh_count > view->scene.mesh_count - model->first_mesh ||
            draw_count + part->mesh_count > AKIRA_MESH_CAPACITY)
            return -2;

        for (uint32_t mesh = 0; mesh < part->mesh_count; ++mesh) {
            akira_mesh_draw item;
            item.view = view;
            item.mesh_index = model->first_mesh + mesh;
            item.attachment_index = (uint32_t)entry;
            if (vf3_fighter_view_attachment_mesh_depth(
                    view, item.mesh_index, matrices, scene_matrix,
                    item.attachment_index, &item.depth) != 0)
                return -3;

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
