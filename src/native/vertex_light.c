/* The strip vertex format wrapper around the native lighting calculation. */
#include "vertex_light.h"
#include "vertex_lit.h"
#include "aim_math.h"

int vf3_native_vertex_light(vf3_native_aim *a)
{
    uint32_t record=a->r[4],header=vf3_aim_u32(a,record),next,body;
    if(header&1u){body=record;next=record+32;}
    else{body=record+8+vf3_aim_u32(a,record+4);next=record+8;}
    float fr0=a->fr[0],fr1=a->fr[1],fr11=a->fr[11];uint32_t fpul=a->fpul;
    a->r[4]=body;
    if(!vf3_native_vertex_lit(a))return 0;
    a->r[4]=next;a->fr[0]=fr0;a->fr[1]=fr1;a->fr[11]=fr11;a->fpul=fpul;
    return 1;
}
