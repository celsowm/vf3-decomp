/* Map the real 15-bit generator result to its original float scale. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
int vf3_random_fraction(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t *r = s->v;
    r[15] -= 4;
    vf3_matrix_write(ram,r[15],r[16],4);
    r[16] = 0x0c0c9d0a;
    if (!vf3_matrix_family(0x0c0c9cc0,s,ram) || s->pc != 0x0c0c9d0a)
        return 0;
    r[4] = r[0];
    r[53] = r[4];
    r[0] = 0x0c0c9d48;
    r[16] = vf3_matrix_read(ram,r[15],4);
    r[15] += 4;
    r[24] = vf3_fpu_float(r[53],r[18]);
    vf3_matrix_move(s,4,3);
    vf3_matrix_load(s,ram,3,r[0]);
    r[25] = vf3_fpu_binary(r[25],r[24],r[18],'*');
    vf3_matrix_move(s,0,4);
    s->pc = r[16];
    return ram->oob == 0;
}
