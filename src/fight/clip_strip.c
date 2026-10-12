/* Walk indexed triangle strips, reject back faces and submit visible packets.
 * The five original attribute layouts share the same strip state machine.
 * Depth masks route crossing triangles through the existing clipper; a
 * contiguous visible run uses its three original attribute writers. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <string.h>
#define R(n) s->v[(n)]
#define F(n) s->v[21+(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))

typedef struct {
    uint32_t entry, stride, attribute_pool, flag_pool, shaders[2], clip_pool;
    uint32_t returns[6];
} strip_profile;
static const strip_profile profiles[]={
    {0x0c0570e0,2,0x0c057108,0x0c05710c,{0x0c057110,0x0c057114},0x0c057288,
     {0x0c0571e4,0x0c0571ec,0x0c0571f4,0x0c057258,0x0c057264,0x0c057276}},
    {0x0c057480,6,0x0c0574a8,0x0c0574ac,{0x0c0574b0,0x0c0574b4},0x0c05762c,
     {0x0c057584,0x0c05758c,0x0c057594,0x0c0575fc,0x0c057608,0x0c05761a}},
    {0x0c057860,2,0x0c057888,0x0c05788c,{0x0c057890,0x0c057894},0x0c057a10,
     {0x0c057968,0x0c057970,0x0c057978,0x0c0579e0,0x0c0579ec,0x0c0579fe}},
    {0x0c057c60,6,0x0c057c84,0x0c057c88,{0x0c057c8c,0x0c057c90},0x0c057e08,
     {0x0c057d64,0x0c057d6c,0x0c057d74,0x0c057dda,0x0c057de6,0x0c057df8}},
    {0x0c057fa0,10,0x0c057fc4,0x0c057fc8,{0x0c057fcc,0x0c057fd0},0x0c058148,
     {0x0c0580a4,0x0c0580ac,0x0c0580b4,0x0c05811a,0x0c058126,0x0c058138}}
};
static void condition(vf3_matrix_state *s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static uint32_t word(const vf3_ram_map *ram,uint32_t address){return (uint32_t)(int32_t)(int16_t)READ(address,2);}
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t value){R(15)-=4;WRITE(R(15),value,4);}
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram){uint32_t value=READ(R(15),4);R(15)+=4;return value;}
static void rotate(vf3_matrix_state *s,unsigned reg){uint32_t old=R(reg);R(reg)=(old<<1)|(R(17)&1u);condition(s,old>>31);}
static void arithmetic(vf3_matrix_state *s,unsigned to,unsigned from,char operation){F(to)=vf3_fpu_binary(F(to),F(from),R(18),operation);}
static int positive(uint32_t value){float f;memcpy(&f,&value,4);return f>0.0f;}
static int call(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t target,uint32_t returned){R(16)=returned;return vf3_matrix_family(target,s,ram);}
static int writer(vf3_matrix_state *s,const vf3_ram_map *ram,const strip_profile *p,unsigned slot,unsigned returned)
{R(1)=R(20);R(1)=READ(R(1)+slot*4,4);return call(s,ram,R(1),p->returns[returned]);}
static void end_packet(vf3_matrix_state *s,const vf3_ram_map *ram)
{R(0)=0xffffffffu;WRITE(R(12),R(0),4);R(12)+=32;}

/* Preserve each layout's original floating expression and scratch registers.
 * Wide FMOV pairs carry the corresponding Y coordinates in odd lanes. */
static unsigned winding(vf3_matrix_state *s,int alternate)
{
    if(!alternate){
        vf3_matrix_move(s,0,8);arithmetic(s,0,12,'-');vf3_matrix_move(s,2,4);
        arithmetic(s,2,12,'-');F(3)^=0x80000000u;arithmetic(s,1,13,'-');
        arithmetic(s,3,13,'+');arithmetic(s,1,2,'*');
        F(1)=vf3_fpu_mac(F(0),F(3),F(1),R(18));return 1;
    }
    vf3_matrix_move(s,0,12);arithmetic(s,1,5,'-');arithmetic(s,0,8,'-');
    arithmetic(s,1,0,'*');F(2)=0;arithmetic(s,2,1,'-');vf3_matrix_move(s,0,12);
    arithmetic(s,1,9,'-');arithmetic(s,0,4,'-');
    F(2)=vf3_fpu_mac(F(0),F(1),F(2),R(18));return 2;
}

int vf3_clip_strip_c(uint32_t entry,vf3_matrix_state *s,const vf3_ram_map *ram)
{
    const strip_profile *p=0;
    for(unsigned i=0;i<sizeof(profiles)/sizeof(profiles[0]);i++)if(profiles[i].entry==entry)p=&profiles[i];
    if(!p || !s->bank_known)return 0;
    int alternate=entry!=0x0c0570e0;unsigned facing;
    push(s,ram,R(14));push(s,ram,R(16));R(14)=R(4);R(14)+=4;
    if(entry!=0x0c057fa0 && entry!=0x0c057c60){R(0)=p->attribute_pool;R(4)=READ(R(0),4);}
    else R(4)=READ(p->attribute_pool,4);
    R(4)=READ(R(4),4);
    if(entry!=0x0c057c60)R(19)=R(4);
    R(0)=READ(p->flag_pool,4);R(0)=READ(R(0),4);
    condition(s,R(0)==0);R(0)=READ(p->shaders[!(R(17)&1u)],4);R(20)=R(0);
    R(18)^=0x100000u;R(11)=word(ram,R(14));R(14)+=2;
next_strip:
    if(!s->budget--)return 0;
    R(8)=R(14);R(0)=word(ram,R(14)+2);R(14)+=p->stride+2;
    R(0)<<=2;R(7)=word(ram,R(8));R(8)+=2;R(0)<<=2;
    vf3_matrix_load(s,ram,8,R(13)+R(0));R(0)+=R(13);R(3)=READ(R(0)+8,4);
    R(0)+=8;vf3_matrix_load(s,ram,10,R(0));condition(s,(int32_t)R(7)>=0);R(5)=0xffffffffu;
    if(!(R(17)&1u)){R(5)=~R(5);R(7)=0u-R(7);}
    condition(s,R(3)>R(10));R(4)=R(17)&1u;condition(s,(int32_t)R(3)>=0);R(9)=R(17)&1u;
    if(R(17)&1u)R(5)=~R(5);
    R(0)=word(ram,R(14));R(7)--;condition(s,R(7)==0);if(R(17)&1u)goto finish_strip;
    R(0)<<=2;R(0)<<=2;vf3_matrix_load(s,ram,12,R(13)+R(0));R(0)+=R(13);
    R(3)=READ(R(0)+8,4);R(0)+=8;vf3_matrix_load(s,ram,14,R(0));R(14)+=p->stride;
    condition(s,R(3)>R(10));rotate(s,4);condition(s,(int32_t)R(3)>=0);R(8)-=p->stride;
    if(R(17)&1u)R(5)=~R(5);
    rotate(s,9);
new_fragment:
    R(6)=0;R(0)=R(4);
next_triangle:
    if(!s->budget--)return 0;
    R(7)--;condition(s,R(7)==0);R(1)=word(ram,R(14));R(2)=4;if(R(17)&1u)goto finish_strip;
    vf3_matrix_move(s,4,8);vf3_matrix_move(s,6,10);condition(s,(R(9)&R(2))==0);
    R(2)=0u-(R(17)&1u);condition(s,R(2)!=0);R(1)<<=2;
    vf3_matrix_move(s,8,12);vf3_matrix_move(s,10,14);R(1)<<=2;R(1)+=R(13);
    R(3)=READ(R(1)+8,4);R(14)+=p->stride;vf3_matrix_load(s,ram,12,R(1));R(1)+=8;
    vf3_matrix_load(s,ram,14,R(1));R(1)+=8;R(5)^=R(2);
    condition(s,R(3)>R(10));rotate(s,0);condition(s,(int32_t)R(3)>=0);R(0)&=7;
    if(R(17)&1u)R(5)=~R(5);
    rotate(s,9);condition(s,R(0)==7);R(8)+=p->stride;
    if(R(17)&1u)goto next_triangle;
    facing=winding(s,alternate);condition(s,(int32_t)R(5)>=0);F(0)=0;
    if(!(R(17)&1u))F(facing)^=0x80000000u;
    condition(s,positive(F(facing)));int visible=(R(17)&1u)!=0;condition(s,R(0)==0);
    if(!visible)goto next_triangle;
    R(18)^=0x100000u;R(6)=R(12);
    if(!(R(17)&1u)){
        R(2)=READ(p->clip_pool,4);R(4)=R(0);if(!call(s,ram,R(2),p->returns[4]))return 0;
        R(18)^=0x100000u;goto new_fragment;
    }
    R(1)=R(20);R(1)=READ(R(1),4);R(4)=R(0);if(!call(s,ram,R(1),p->returns[0]))return 0;
    if(!writer(s,ram,p,1,1) || !writer(s,ram,p,2,2))return 0;
    R(2)=4;R(0)=word(ram,R(14));
continue_run:
    if(!s->budget--)return 0;
    R(7)--;condition(s,R(7)==0);int ended=(R(17)&1u)!=0;R(18)^=0x100000u;
    condition(s,(R(9)&R(2))==0);if(ended)goto finish_run;
    R(0)<<=2;vf3_matrix_move(s,4,8);vf3_matrix_move(s,6,10);
    R(2)=0u-(R(17)&1u);condition(s,R(2)!=0);vf3_matrix_move(s,8,12);vf3_matrix_move(s,10,14);
    R(0)<<=2;vf3_matrix_load(s,ram,12,R(13)+R(0));R(0)+=R(13);R(3)=READ(R(0)+8,4);
    R(0)+=8;vf3_matrix_load(s,ram,14,R(0));R(14)+=p->stride;R(5)^=R(2);
    condition(s,(int32_t)R(3)>=0);int positive_depth=(R(17)&1u)!=0;rotate(s,9);
    if(positive_depth)R(5)=~R(5);
    facing=winding(s,alternate);condition(s,R(3)>R(10));rotate(s,4);condition(s,(int32_t)R(5)>=0);
    if(!(R(17)&1u))F(facing)^=0x80000000u;
    F(0)=0;condition(s,positive(F(facing)));
    visible=(R(17)&1u)!=0;R(8)+=p->stride;R(18)^=0x100000u;
    if(!visible){R(0)=0xffffffffu;R(18)^=0x100000u;WRITE(R(12),R(0),4);R(12)+=32;goto new_fragment;}
    condition(s,R(4)==0);
    if(R(17)&1u){if(!writer(s,ram,p,2,3))return 0;R(2)=4;R(0)=word(ram,R(14));goto continue_run;}
    end_packet(s,ram);R(2)=READ(p->clip_pool,4);R(4)=1;
    if(!call(s,ram,R(2),p->returns[5]))return 0;
    R(18)^=0x100000u;goto new_fragment;
finish_run:
    condition(s,R(6)==0);ended=(R(17)&1u)!=0;R(11)--;condition(s,R(11)==0);
    if(!ended)end_packet(s,ram);
    goto strip_count;
finish_strip:
    R(11)--;condition(s,R(11)==0);
strip_count:
    if(!(R(17)&1u))goto next_strip;
    R(18)^=0x100000u;R(3)=s->bank[3];WRITE(R(3),R(12),4);R(4)=R(14);
    R(16)=pop(s,ram);R(14)=pop(s,ram);s->pc=R(16);return ram->oob==0;
}
