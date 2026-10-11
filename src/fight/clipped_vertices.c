/* Reciprocal-depth intersections and packed output for a clipped triangle.
 * Original entry 0x8c058a5c uses the renderer's live register convention. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <string.h>
#define R(n) s->v[(n)]
#define F(n) s->v[21+(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v) vf3_matrix_write(ram,(a),(v),4)
static void push(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t v){R(15)-=4;WRITE(R(15),v);}
static uint32_t pop(vf3_matrix_state*s,const vf3_ram_map*ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static void output(vf3_matrix_state*s,const vf3_ram_map*ram,unsigned f){R(12)-=4;vf3_matrix_store(s,ram,f,R(12));}
static float value(uint32_t b){float f;memcpy(&f,&b,4);return f;}
static void condition(vf3_matrix_state*s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static void arithmetic(vf3_matrix_state*s,unsigned d,unsigned f,char op){F(d)=vf3_fpu_binary(F(d),F(f),R(18),op);}
static void mac(vf3_matrix_state*s,unsigned d,unsigned f){F(d)=vf3_fpu_mac(F(0),F(f),F(d),R(18));}
int vf3_clipped_vertices_c(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t alias)
{
    uint32_t saved;
    if(!vf3_fpu_supported(R(18)) || !(R(18)&0x100000u) || !s->gbr_known)return 0;
    /* The packed direction is shared by both output records. */
    push(s,ram,R(16));R(5)=R(14);R(16)=alias+0x058a62;
    if(!vf3_matrix_family(alias+0x05865c,s,ram) || s->pc!=R(16))return 0;
    push(s,ram,R(0));R(0)=8;
    /* Load projected endpoints and texture coordinates. Signed reciprocal
     * depths use the original square/reciprocal-square-root sequence. */
    vf3_matrix_load(s,ram,8,R(8));R(2)=R(14);
    vf3_matrix_load(s,ram,0,R(8)+R(0));R(2)-=48;
    F(10)=0x3f800000;R(1)=(uint32_t)(int32_t)(int16_t)READ(R(2),2);R(2)+=2;
    arithmetic(s,10,0,'/');R(2)=(uint32_t)(int32_t)(int16_t)READ(R(2),2);
    vf3_matrix_load(s,ram,2,R(6)+R(0));vf3_matrix_load(s,ram,6,R(6));
    s->v[53]=R(1);F(12)=vf3_fpu_float(s->v[53],R(18));F(0)=0;condition(s,value(F(0))>value(F(2)));
    s->v[53]=R(2);arithmetic(s,2,2,'*');R(2)=R(14);F(13)=vf3_fpu_float(s->v[53],R(18));
    R(1)=(uint32_t)(int32_t)(int16_t)READ(R(2),2);R(2)+=2;
    if(!vf3_fpu_fsrra(F(2),R(18),&F(2)))return 0;
    R(2)=(uint32_t)(int32_t)(int16_t)READ(R(2),2);
    arithmetic(s,12,15,'*');vf3_matrix_load(s,ram,4,R(9));arithmetic(s,13,15,'*');
    R(18)^=0x100000u;s->v[53]=R(1);vf3_matrix_load(s,ram,3,R(9)+R(0));
    R(0)=READ(s->gbr+28,4);F(11)=vf3_fpu_float(s->v[53],R(18));
    s->v[53]=R(2);F(14)=vf3_fpu_float(s->v[53],R(18));s->v[53]=R(0);
    if(R(17)&1)F(2)^=0x80000000u;
    F(0)=s->v[53];arithmetic(s,0,2,'-');R(2)=R(14);arithmetic(s,8,10,'*');R(2)-=24;
    arithmetic(s,9,10,'*');R(1)=(uint32_t)(int32_t)(int16_t)READ(R(2),2);R(2)+=2;
    arithmetic(s,10,2,'-');s->v[53]=F(0);arithmetic(s,11,15,'*');
    R(2)=(uint32_t)(int32_t)(int16_t)READ(R(2),2);arithmetic(s,14,15,'*');
    arithmetic(s,0,10,'/');R(12)+=60;arithmetic(s,7,2,'*');R(5)=pop(s,ram);
    arithmetic(s,6,2,'*');R(0)=READ(s->gbr+96,4);
    F(1)=0;condition(s,value(F(1))>value(F(3)));arithmetic(s,3,3,'*');
    arithmetic(s,13,14,'-');WRITE(R(12),R(5));arithmetic(s,12,11,'-');
    arithmetic(s,9,7,'-');arithmetic(s,8,6,'-');R(12)-=4;WRITE(R(12),R(0));
    if(!vf3_fpu_fsrra(F(3),R(18),&F(3)))return 0;
    /* First edge: interpolate projected and texture coordinates, then pack
     * the first record backwards into the output buffer. */
    F(1)=F(7);mac(s,1,9);F(9)=F(6);mac(s,9,8);
    F(8)=F(14);mac(s,8,13);F(13)=F(11);mac(s,13,12);
    F(0)=s->v[53];s->v[53]=R(10);F(12)=s->v[53];arithmetic(s,1,12,'*');
    output(s,ram,8);arithmetic(s,9,12,'*');output(s,ram,13);
    if(R(17)&1)F(3)^=0x80000000u;
    arithmetic(s,5,3,'*');s->v[53]=R(2);arithmetic(s,4,3,'*');R(12)-=4;WRITE(R(12),R(10));
    arithmetic(s,3,2,'-');output(s,ram,1);F(8)=vf3_fpu_float(s->v[53],R(18));
    s->v[53]=R(1);F(1)=vf3_fpu_float(s->v[53],R(18));output(s,ram,9);arithmetic(s,0,3,'/');
    saved=R(12);R(12)-=4;WRITE(R(12),saved);
    /* Second edge shares the clipping plane and start point. Its output
     * occupies the following record; return with the renderer's bank mode. */
    arithmetic(s,8,15,'*');arithmetic(s,1,15,'*');arithmetic(s,5,7,'-');R(12)+=44;
    arithmetic(s,4,6,'-');R(16)=pop(s,ram);arithmetic(s,8,14,'-');WRITE(R(12)+12,R(0));
    arithmetic(s,1,11,'-');WRITE(R(12),R(10));mac(s,7,5);WRITE(R(12)+16,R(5));
    mac(s,6,4);mac(s,14,8);R(12)+=8;mac(s,11,1);arithmetic(s,7,12,'*');R(0)=0xfffffffcu;
    arithmetic(s,6,12,'*');vf3_matrix_store(s,ram,14,R(12));vf3_matrix_store(s,ram,11,R(12)+R(0));
    R(12)-=12;vf3_matrix_store(s,ram,7,R(12));output(s,ram,6);
    R(18)^=0x100000u;R(12)-=4;vf3_matrix_load(s,ram,4,R(9));
    s->pc=R(16);vf3_matrix_load(s,ram,8,R(6));return ram->oob==0;
}
