/* SH-4 0x8C068FE4: classify one relative polygon node. */
#include "fight/mesh_node.h"

int vf3_mesh_node_classify(uint32_t node, float x, float y,
                           const vf3_ram_map *ram)
{
    return vf3_poly_classify(node, 0x0C113A0Cu, x, y, ram);
}
