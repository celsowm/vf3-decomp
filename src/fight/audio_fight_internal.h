#ifndef VF3_AUDIO_FIGHT_INTERNAL_H
#define VF3_AUDIO_FIGHT_INTERNAL_H
#include "fight/matrix_family.h"
#include <string.h>
#define R(n) s->v[(n)]
#define FR(n) s->v[21+(n)]
#ifdef VF3_AUDIO_BRIDGE
extern void vf3_audio_queue_step(vf3_matrix_state*,uint32_t);
#define STEP(pc) vf3_audio_queue_step(s,alias+(pc))
#else
#define STEP(pc) ((void)0)
#endif
#define RD(addr,size) vf3_matrix_read(ram,(addr),(size))
#define WR(addr,value,size) vf3_matrix_write(ram,(addr),(value),(size))
static void condition(vf3_matrix_state *s,int value)
{ R(17)=(R(17)&~1u)|(value!=0); }
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t value)
{ R(15)-=4; WR(R(15),value,4); }
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram)
{ uint32_t value=RD(R(15),4); R(15)+=4; return value; }
static uint32_t signed_byte(uint32_t value) { return (uint32_t)(int32_t)(int8_t)value; }
static uint32_t signed_word(uint32_t value) { return (uint32_t)(int32_t)(int16_t)value; }
static uint32_t logical_shift(uint32_t value,uint32_t shift)
{
    if (!(shift&0x80000000u)) return value<<(shift&31);
    return (shift&31)?value>>((0u-shift)&31):0;
}
static uint32_t *float_bank(vf3_matrix_state *s,unsigned n)
{ return (R(18)&0x100000u)?&s->v[(n&1?37:21)+(n&~1u)]:&FR(n); }
static unsigned float_width(vf3_matrix_state *s) { return (R(18)&0x100000u)?8:4; }
static void float_load(vf3_matrix_state*s,const vf3_ram_map*ram,unsigned n,uint32_t addr)
{ uint32_t*p=float_bank(s,n);for(unsigned i=0;i<float_width(s)/4;++i)p[i]=RD(addr+4*i,4); }
static void float_store(vf3_matrix_state*s,const vf3_ram_map*ram,unsigned n,uint32_t addr)
{ uint32_t*p=float_bank(s,n);for(unsigned i=0;i<float_width(s)/4;++i)WR(addr+4*i,p[i],4); }
static void float_move(vf3_matrix_state*s,unsigned dst,unsigned src)
{ uint32_t tmp[2];unsigned w=float_width(s);memcpy(tmp,float_bank(s,src),w);memcpy(float_bank(s,dst),tmp,w); }
static void float_swap(vf3_matrix_state*s)
{ for(unsigned i=0;i<16;++i){uint32_t v=FR(i);FR(i)=s->v[37+i];s->v[37+i]=v;}R(18)^=0x200000u; }
extern int vf3_audio_request_c(vf3_matrix_state*,const vf3_ram_map*,uint32_t,int);
extern int vf3_audio_style_at_c(vf3_matrix_state*,const vf3_ram_map*,uint32_t);
extern int vf3_audio_submission_at_c(vf3_matrix_state*,const vf3_ram_map*,uint32_t);
int vf3_audio_fight_tail_c(vf3_matrix_state*,const vf3_ram_map*);
int vf3_audio_fight_callback_c(vf3_matrix_state*,const vf3_ram_map*);
int vf3_audio_fight_render_c(vf3_matrix_state*,const vf3_ram_map*,unsigned);
#endif
