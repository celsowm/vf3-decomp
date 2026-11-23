/* Task state check 0x8c0355a0. */
#include "state_checker.h"
#include "aim_math.h"

static void test(vf3_native_aim *a,int condition)
{a->sr=(a->sr&~1u)|(condition!=0);}

void vf3_native_state_checker(vf3_native_aim *a)
{
    uint32_t sp=a->r[15],pr=a->pr,r14=a->r[14],state=a->r[4];
    vf3_aim_set_u32(a,sp-4,r14);vf3_aim_set_u32(a,sp-8,pr);
    a->r[15]=sp-8;a->r[14]=state;test(a,state==0);
    if(state){
        a->r[0]=0x48;a->r[2]=(uint32_t)(int32_t)(int16_t)vf3_aim_h16(a,state+0x48);
        test(a,a->r[2]==0);
        if(a->r[2]==0){
            a->r[0]=(uint32_t)(int32_t)(int16_t)vf3_aim_h16(a,state+0x4c);
            test(a,a->r[0]==2);
            if(a->r[0]==2){
                /* 0x035a4e tests this same busy halfword; it is zero here,
                 * so only its early-return path is reachable from this call. */
                a->r[4]=state;vf3_aim_set_u32(a,sp-12,state);
                vf3_aim_set_u32(a,sp-16,0x0c0355beu);
                a->r[2]=(uint32_t)(int32_t)(int16_t)vf3_aim_h16(a,state+0x48);
                test(a,a->r[2]==0);a->r[0]=0xfffffff6u;
            }
            a->r[0]=0x48;a->r[3]=0;vf3_aim_set_u16(a,state+0x48,0);
        }
    }
    a->pr=pr;a->r[14]=r14;a->r[15]=sp;
}
