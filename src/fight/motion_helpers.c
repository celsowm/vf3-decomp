/* Original motion-record initialization at 0x8C0CC2D6.
 * Scale three record deltas, add the anchor and initialize the step counter.
 * Register residues are retained for callers using the SH-4 ABI. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"

int vf3_motion_record_init(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    uint32_t *r=s->v,*fr=r+21;
    const uint32_t mode=r[18],out=r[4],record=r[5],anchor=r[7];
    if(mode&0x100000u) { s->failed_pc=0x0c0cc2d6u; return 0; }
    r[6]=vf3_matrix_read(ram,r[15],4);
    r[0]=0x0c0cc374u;
    fr[4]=vf3_matrix_read(ram,r[0],4);
    r[0]=24; r[6]&=255u; r[53]=r[6];
    fr[3]=vf3_fpu_float(r[53],mode);
    fr[5]=fr[3]; fr[3]=fr[4]; fr[4]=fr[5];
    fr[4]=vf3_fpu_binary(fr[4],fr[3],mode,'*');
    fr[5]=vf3_matrix_read(ram,record+r[0],4);
    r[0]=28; fr[6]=vf3_matrix_read(ram,record+r[0],4);
    r[0]=32;
    fr[5]=vf3_fpu_binary(fr[5],fr[4],mode,'*');
    fr[3]=fr[4];
    fr[6]=vf3_fpu_binary(fr[6],fr[4],mode,'*');
    fr[4]=vf3_matrix_read(ram,record+r[0],4);
    r[0]=12; fr[4]=vf3_fpu_binary(fr[4],fr[3],mode,'*');
    vf3_matrix_write(ram,out+r[0],fr[5],4);
    r[0]=16; vf3_matrix_write(ram,out+r[0],fr[6],4);
    r[0]=20; vf3_matrix_write(ram,out+r[0],fr[4],4);
    r[0]=4; fr[3]=vf3_matrix_read(ram,anchor,4);
    fr[3]=vf3_fpu_binary(fr[3],fr[5],mode,'+');
    vf3_matrix_write(ram,out,fr[3],4);
    fr[2]=vf3_matrix_read(ram,anchor+r[0],4);
    fr[2]=vf3_fpu_binary(fr[2],fr[6],mode,'+');
    vf3_matrix_write(ram,out+r[0],fr[2],4);
    r[0]=8; fr[3]=vf3_matrix_read(ram,anchor+r[0],4);
    r[3]=0xfffffff8u; r[5]=31; fr[3]^=0x80000000u;
    fr[3]=vf3_fpu_binary(fr[3],fr[4],mode,'-');
    vf3_matrix_write(ram,out+r[0],fr[3],4);
    r[0]=vf3_matrix_read(ram,r[15],4);
    r[0]=(uint32_t)((int32_t)r[0]>>8);
    r[5]=(r[5]&r[0])+4; r[0]=r[5];
    vf3_matrix_write(ram,out+30,r[0],2);
    s->pc=r[16];
    return ram->oob==0;
}
