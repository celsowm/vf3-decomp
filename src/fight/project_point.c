/* Homogeneous point transform, perspective divide and viewport conversion.
 * Exact callable/frozen owner 0x8c03d9b0; matrix helpers preserve the stack. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#define R(n) s->v[(n)]
#define F(n) s->v[21+(n)]
#define READ(a) vf3_matrix_read(ram,(a),4)
#define WRITE(a,v) vf3_matrix_write(ram,(a),(v),4)
static int call(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t target,uint32_t next)
{R(16)=next;return vf3_matrix_family(target,s,ram)&&s->pc==next;}
static void op(vf3_matrix_state*s,unsigned d,unsigned f,char operation)
{F(d)=vf3_fpu_binary(F(d),F(f),R(18),operation);}
int vf3_project_point_c(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t alias)
{
    if(!vf3_fpu_supported(R(18)) || (R(18)&0x100000u))return 0;
    R(15)-=4;WRITE(R(15),R(16));R(15)-=24;WRITE(R(15)+4,R(4));
    R(3)=READ(alias+0x03dc2c);R(4)=READ(alias+0x03dc28);WRITE(R(15),R(5));
    if(!call(s,ram,R(3),alias+0x03d9be))return 0;
    R(3)=READ(alias+0x03dc30);R(5)=R(15)+8;R(4)=READ(R(15)+4);
    if(!call(s,ram,R(3),alias+0x03d9c8))return 0;
    /* Divide the two screen coordinates by transformed homogeneous w. */
    R(0)=20;F(4)=0x3f800000;F(3)=READ(R(15)+R(0));R(0)=8;
    F(5)=F(4);op(s,5,3,'/');F(3)=READ(R(15)+R(0));R(0)=8;
    op(s,3,5,'*');WRITE(R(15)+R(0),F(3));R(0)=12;
    F(3)=READ(R(15)+R(0));R(0)=12;op(s,3,5,'*');WRITE(R(15)+R(0),F(3));
    R(0)=alias+0x03dc34;F(5)=READ(R(0));R(0)=8;F(3)=READ(R(15)+R(0));
    R(2)=READ(alias+0x03dc38);op(s,3,4,'+');R(3)=READ(alias+0x03dc3c);
    F(0)=READ(R(2));F(2)=READ(R(3));R(1)=READ(R(15));op(s,3,0,'*');F(0)=F(5);
    F(2)=vf3_fpu_mac(F(0),F(3),F(2),R(18));WRITE(R(1),F(2));
    /* Viewport y is reflected before the scale and offset are applied. */
    R(1)=R(15);R(0)=READ(R(15));R(1)+=12;F(3)=READ(R(1));R(2)=4;
    R(1)=READ(alias+0x03dc40);F(3)^=0x80000000u;op(s,3,4,'+');F(0)=READ(R(1));
    R(3)=READ(alias+0x03dc44);op(s,3,0,'*');F(2)=READ(R(3));F(0)=F(5);
    F(2)=vf3_fpu_mac(F(0),F(3),F(2),R(18));WRITE(R(0)+R(2),F(2));
    R(2)=READ(alias+0x03dc48);R(4)=1;
    if(!call(s,ram,R(2),alias+0x03da26))return 0;
    R(15)+=24;R(16)=READ(R(15));R(15)+=4;s->pc=R(16);return ram->oob==0;
}
