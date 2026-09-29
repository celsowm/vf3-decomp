#ifndef VF3_FIGHT_MESH_NODE_H
#define VF3_FIGHT_MESH_NODE_H

#include <stdint.h>
#include "fight/poly_classify.h"

int vf3_mesh_node_classify(uint32_t node, float x, float y,
                           const vf3_ram_map *ram);

#endif
