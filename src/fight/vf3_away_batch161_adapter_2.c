/* Static C ABI adapters. Generated with tools/oracle/translate_adapters.py.
 * Matrix operations are hand-written in matrix_family.c; unknown code fails.
 * Executed opcodes are checked against the untouched identity image. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <math.h>
#include <string.h>
#define read vf3_matrix_read
#define write vf3_matrix_write
#define pref vf3_matrix_pref
void vf3_matrix_pref(const vf3_ram_map*,uint32_t);
static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }
static uint32_t truncate_float(uint32_t u) { double d=as_float(u); if(isnan(d) || d< -2147483648.0) return 0x80000000u; if(d>=2147483648.0) return 0x7fffffffu; return (uint32_t)(int32_t)d; }
static void divide_step(vf3_matrix_state*s,unsigned n,unsigned m) { uint32_t *r=s->v; unsigned oldq=(r[17]>>8)&1u,sign=(r[17]>>9)&1u,q=r[n]>>31; uint32_t divisor=r[m],shifted=(r[n]<<1)|(r[17]&1u); r[n]=oldq==sign?shifted-divisor:shifted+divisor; unsigned carry=oldq==sign?r[n]>shifted:r[n]<shifted; q^=carry^sign; r[17]=(r[17]&~0x101u)|(q<<8)|(q==sign); }
int vf3_away_batch161_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c26fau: goto P_0c0c26fa;
case 0x0c0c26fcu: goto P_0c0c26fc;
case 0x0c0c26feu: goto P_0c0c26fe;
case 0x0c0c2700u: goto P_0c0c2700;
case 0x0c0c2702u: goto P_0c0c2702;
case 0x0c0c2704u: goto P_0c0c2704;
case 0x0c0c2706u: goto P_0c0c2706;
case 0x0c0c2708u: goto P_0c0c2708;
case 0x0c0c270au: goto P_0c0c270a;
case 0x0c0c270cu: goto P_0c0c270c;
case 0x0c0c270eu: goto P_0c0c270e;
case 0x0c0c2710u: goto P_0c0c2710;
case 0x0c0c2712u: goto P_0c0c2712;
case 0x0c0c2714u: goto P_0c0c2714;
case 0x0c0c2716u: goto P_0c0c2716;
case 0x0c0c2718u: goto P_0c0c2718;
case 0x0c0c271au: goto P_0c0c271a;
case 0x0c0c271cu: goto P_0c0c271c;
case 0x0c0c271eu: goto P_0c0c271e;
case 0x0c0c2720u: goto P_0c0c2720;
case 0x0c0c2722u: goto P_0c0c2722;
case 0x0c0c2724u: goto P_0c0c2724;
case 0x0c0c2726u: goto P_0c0c2726;
case 0x0c0c2728u: goto P_0c0c2728;
case 0x0c0c272au: goto P_0c0c272a;
case 0x0c0c272cu: goto P_0c0c272c;
case 0x0c0c272eu: goto P_0c0c272e;
case 0x0c0c2730u: goto P_0c0c2730;
case 0x0c0c2732u: goto P_0c0c2732;
case 0x0c0c2734u: goto P_0c0c2734;
case 0x0c0c2736u: goto P_0c0c2736;
case 0x0c0c2738u: goto P_0c0c2738;
case 0x0c0c273au: goto P_0c0c273a;
case 0x0c0c273cu: goto P_0c0c273c;
case 0x0c0c273eu: goto P_0c0c273e;
case 0x0c0c2740u: goto P_0c0c2740;
case 0x0c0c2742u: goto P_0c0c2742;
case 0x0c0c2744u: goto P_0c0c2744;
case 0x0c0c2746u: goto P_0c0c2746;
case 0x0c0c2748u: goto P_0c0c2748;
case 0x0c0c274au: goto P_0c0c274a;
case 0x0c0c274cu: goto P_0c0c274c;
case 0x0c0c274eu: goto P_0c0c274e;
case 0x0c0c2750u: goto P_0c0c2750;
case 0x0c0c2752u: goto P_0c0c2752;
case 0x0c0c2754u: goto P_0c0c2754;
case 0x0c0c2756u: goto P_0c0c2756;
case 0x0c0c2758u: goto P_0c0c2758;
case 0x0c0c275au: goto P_0c0c275a;
case 0x0c0c275cu: goto P_0c0c275c;
case 0x0c0c275eu: goto P_0c0c275e;
case 0x0c0c2760u: goto P_0c0c2760;
case 0x0c0c2762u: goto P_0c0c2762;
case 0x0c0c2764u: goto P_0c0c2764;
case 0x0c0c2766u: goto P_0c0c2766;
case 0x0c0c2768u: goto P_0c0c2768;
case 0x0c0c276au: goto P_0c0c276a;
case 0x0c0c276cu: goto P_0c0c276c;
case 0x0c0c276eu: goto P_0c0c276e;
case 0x0c0c2770u: goto P_0c0c2770;
case 0x0c0c2772u: goto P_0c0c2772;
case 0x0c0c2774u: goto P_0c0c2774;
case 0x0c0c2776u: goto P_0c0c2776;
case 0x0c0c2778u: goto P_0c0c2778;
case 0x0c0c277au: goto P_0c0c277a;
case 0x0c0c277cu: goto P_0c0c277c;
case 0x0c0c277eu: goto P_0c0c277e;
case 0x0c0c2780u: goto P_0c0c2780;
case 0x0c0c2782u: goto P_0c0c2782;
case 0x0c0c2784u: goto P_0c0c2784;
case 0x0c0c2786u: goto P_0c0c2786;
case 0x0c0c2788u: goto P_0c0c2788;
case 0x0c0c278au: goto P_0c0c278a;
case 0x0c0c278cu: goto P_0c0c278c;
case 0x0c0c278eu: goto P_0c0c278e;
case 0x0c0c2790u: goto P_0c0c2790;
case 0x0c0c2792u: goto P_0c0c2792;
case 0x0c0c2794u: goto P_0c0c2794;
case 0x0c0c2796u: goto P_0c0c2796;
case 0x0c0c2798u: goto P_0c0c2798;
case 0x0c0c279au: goto P_0c0c279a;
case 0x0c0c279cu: goto P_0c0c279c;
case 0x0c0c279eu: goto P_0c0c279e;
case 0x0c0c27a0u: goto P_0c0c27a0;
case 0x0c0c27a2u: goto P_0c0c27a2;
case 0x0c0c27a4u: goto P_0c0c27a4;
case 0x0c0c27a6u: goto P_0c0c27a6;
case 0x0c0c27a8u: goto P_0c0c27a8;
case 0x0c0c285cu: goto P_0c0c285c;
case 0x0c0c285eu: goto P_0c0c285e;
case 0x0c0c2860u: goto P_0c0c2860;
case 0x0c0c2862u: goto P_0c0c2862;
case 0x0c0c2864u: goto P_0c0c2864;
case 0x0c0c2866u: goto P_0c0c2866;
case 0x0c0c2868u: goto P_0c0c2868;
case 0x0c0c286au: goto P_0c0c286a;
case 0x0c0c286cu: goto P_0c0c286c;
case 0x0c0c286eu: goto P_0c0c286e;
case 0x0c0c2870u: goto P_0c0c2870;
case 0x0c0c2872u: goto P_0c0c2872;
case 0x0c0c2874u: goto P_0c0c2874;
case 0x0c0c2876u: goto P_0c0c2876;
case 0x0c0c2878u: goto P_0c0c2878;
case 0x0c0c287au: goto P_0c0c287a;
case 0x0c0c287cu: goto P_0c0c287c;
case 0x0c0c287eu: goto P_0c0c287e;
case 0x0c0c2880u: goto P_0c0c2880;
case 0x0c0c2882u: goto P_0c0c2882;
case 0x0c0c2884u: goto P_0c0c2884;
case 0x0c0c2886u: goto P_0c0c2886;
case 0x0c0c2888u: goto P_0c0c2888;
case 0x0c0c288au: goto P_0c0c288a;
case 0x0c0c288cu: goto P_0c0c288c;
case 0x0c0c288eu: goto P_0c0c288e;
case 0x0c0c2890u: goto P_0c0c2890;
case 0x0c0c2892u: goto P_0c0c2892;
case 0x0c0c2894u: goto P_0c0c2894;
case 0x0c0c2896u: goto P_0c0c2896;
case 0x0c0c2898u: goto P_0c0c2898;
case 0x0c0c289au: goto P_0c0c289a;
case 0x0c0c289cu: goto P_0c0c289c;
case 0x0c0c289eu: goto P_0c0c289e;
case 0x0c0c28a0u: goto P_0c0c28a0;
case 0x0c0c28a2u: goto P_0c0c28a2;
case 0x0c0c28a4u: goto P_0c0c28a4;
case 0x0c0c28a6u: goto P_0c0c28a6;
case 0x0c0c28a8u: goto P_0c0c28a8;
case 0x0c0c28aau: goto P_0c0c28aa;
case 0x0c0c28acu: goto P_0c0c28ac;
case 0x0c0c28aeu: goto P_0c0c28ae;
case 0x0c0c28b0u: goto P_0c0c28b0;
case 0x0c0c28b2u: goto P_0c0c28b2;
case 0x0c0c28b4u: goto P_0c0c28b4;
case 0x0c0c28b6u: goto P_0c0c28b6;
case 0x0c0c28b8u: goto P_0c0c28b8;
case 0x0c0c28bau: goto P_0c0c28ba;
case 0x0c0c28bcu: goto P_0c0c28bc;
case 0x0c0c28beu: goto P_0c0c28be;
case 0x0c0c28c0u: goto P_0c0c28c0;
case 0x0c0c28c2u: goto P_0c0c28c2;
case 0x0c0c28c4u: goto P_0c0c28c4;
case 0x0c0c28c6u: goto P_0c0c28c6;
case 0x0c0c28c8u: goto P_0c0c28c8;
case 0x0c0c28cau: goto P_0c0c28ca;
case 0x0c0c28ccu: goto P_0c0c28cc;
case 0x0c0c28ceu: goto P_0c0c28ce;
case 0x0c0c28d0u: goto P_0c0c28d0;
case 0x0c0c28d2u: goto P_0c0c28d2;
case 0x0c0c28d4u: goto P_0c0c28d4;
case 0x0c0c28d6u: goto P_0c0c28d6;
case 0x0c0c28d8u: goto P_0c0c28d8;
case 0x0c0c28dau: goto P_0c0c28da;
case 0x0c0c28dcu: goto P_0c0c28dc;
case 0x0c0c28deu: goto P_0c0c28de;
case 0x0c0c28e0u: goto P_0c0c28e0;
case 0x0c0c28e2u: goto P_0c0c28e2;
case 0x0c0c28e4u: goto P_0c0c28e4;
case 0x0c0c28e6u: goto P_0c0c28e6;
case 0x0c0c28e8u: goto P_0c0c28e8;
case 0x0c0c28eau: goto P_0c0c28ea;
case 0x0c0c28ecu: goto P_0c0c28ec;
case 0x0c0c28eeu: goto P_0c0c28ee;
case 0x0c0c28f0u: goto P_0c0c28f0;
case 0x0c0c28f2u: goto P_0c0c28f2;
case 0x0c0c28f4u: goto P_0c0c28f4;
case 0x0c0c28f6u: goto P_0c0c28f6;
case 0x0c0c28f8u: goto P_0c0c28f8;
case 0x0c0c28fau: goto P_0c0c28fa;
case 0x0c0c28fcu: goto P_0c0c28fc;
case 0x0c0c28feu: goto P_0c0c28fe;
case 0x0c0c2900u: goto P_0c0c2900;
case 0x0c0c2902u: goto P_0c0c2902;
case 0x0c0c2904u: goto P_0c0c2904;
case 0x0c0c2906u: goto P_0c0c2906;
case 0x0c0c2908u: goto P_0c0c2908;
case 0x0c0c290au: goto P_0c0c290a;
case 0x0c0c290cu: goto P_0c0c290c;
case 0x0c0c290eu: goto P_0c0c290e;
case 0x0c0c2910u: goto P_0c0c2910;
case 0x0c0c2912u: goto P_0c0c2912;
case 0x0c0c2914u: goto P_0c0c2914;
case 0x0c0c2916u: goto P_0c0c2916;
case 0x0c0c2918u: goto P_0c0c2918;
case 0x0c0c291au: goto P_0c0c291a;
case 0x0c0c291cu: goto P_0c0c291c;
case 0x0c0c291eu: goto P_0c0c291e;
case 0x0c0c2920u: goto P_0c0c2920;
case 0x0c0c2922u: goto P_0c0c2922;
case 0x0c0c2924u: goto P_0c0c2924;
case 0x0c0c2926u: goto P_0c0c2926;
case 0x0c0c2928u: goto P_0c0c2928;
case 0x0c0c292au: goto P_0c0c292a;
case 0x0c0c292cu: goto P_0c0c292c;
case 0x0c0c292eu: goto P_0c0c292e;
case 0x0c0c2930u: goto P_0c0c2930;
case 0x0c0c2932u: goto P_0c0c2932;
case 0x0c0c2934u: goto P_0c0c2934;
case 0x0c0c2936u: goto P_0c0c2936;
case 0x0c0c2938u: goto P_0c0c2938;
case 0x0c0c293au: goto P_0c0c293a;
case 0x0c0c293cu: goto P_0c0c293c;
case 0x0c0c293eu: goto P_0c0c293e;
case 0x0c0c2940u: goto P_0c0c2940;
case 0x0c0c2942u: goto P_0c0c2942;
case 0x0c0c2944u: goto P_0c0c2944;
case 0x0c0c2946u: goto P_0c0c2946;
case 0x0c0c2948u: goto P_0c0c2948;
case 0x0c0c294au: goto P_0c0c294a;
case 0x0c0c294cu: goto P_0c0c294c;
case 0x0c0c294eu: goto P_0c0c294e;
case 0x0c0c2950u: goto P_0c0c2950;
case 0x0c0c2952u: goto P_0c0c2952;
case 0x0c0c2954u: goto P_0c0c2954;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c26fa: /* original 2fe6, guest PC 0x0c0c26fa */
if(!s->budget--) { s->failed_pc=0x0c0c26fau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c26fc;
P_0c0c26fc: /* original e3ff, guest PC 0x0c0c26fc */
if(!s->budget--) { s->failed_pc=0x0c0c26fcu; return 0; }
r[3]=0xffffffffu;
goto P_0c0c26fe;
P_0c0c26fe: /* original 2fd6, guest PC 0x0c0c26fe */
if(!s->budget--) { s->failed_pc=0x0c0c26feu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2700;
P_0c0c2700: /* original 6233, guest PC 0x0c0c2700 */
if(!s->budget--) { s->failed_pc=0x0c0c2700u; return 0; }
r[2]=r[3];
goto P_0c0c2702;
P_0c0c2702: /* original de4a, guest PC 0x0c0c2702 */
if(!s->budget--) { s->failed_pc=0x0c0c2702u; return 0; }
r[14]=read(ram,0x0c0c282cu,4);
goto P_0c0c2704;
P_0c0c2704: /* original 9082, guest PC 0x0c0c2704 */
if(!s->budget--) { s->failed_pc=0x0c0c2704u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c280cu,2);
goto P_0c0c2706;
P_0c0c2706: /* original 4f22, guest PC 0x0c0c2706 */
if(!s->budget--) { s->failed_pc=0x0c0c2706u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c2708;
P_0c0c2708: /* original 0e36, guest PC 0x0c0c2708 */
if(!s->budget--) { s->failed_pc=0x0c0c2708u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0c270a;
P_0c0c270a: /* original 70f8, guest PC 0x0c0c270a */
if(!s->budget--) { s->failed_pc=0x0c0c270au; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c270c;
P_0c0c270c: /* original 0e36, guest PC 0x0c0c270c */
if(!s->budget--) { s->failed_pc=0x0c0c270cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0c270e;
P_0c0c270e: /* original 70e8, guest PC 0x0c0c270e */
if(!s->budget--) { s->failed_pc=0x0c0c270eu; return 0; }
r[0]+=0xffffffe8u;
goto P_0c0c2710;
P_0c0c2710: /* original 0e26, guest PC 0x0c0c2710 */
if(!s->budget--) { s->failed_pc=0x0c0c2710u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c2712;
P_0c0c2712: /* original 70f8, guest PC 0x0c0c2712 */
if(!s->budget--) { s->failed_pc=0x0c0c2712u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c2714;
P_0c0c2714: /* original 0e26, guest PC 0x0c0c2714 */
if(!s->budget--) { s->failed_pc=0x0c0c2714u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c2716;
P_0c0c2716: /* original 967a, guest PC 0x0c0c2716 */
if(!s->budget--) { s->failed_pc=0x0c0c2716u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c280eu,2);
goto P_0c0c2718;
P_0c0c2718: /* original 9477, guest PC 0x0c0c2718 */
if(!s->budget--) { s->failed_pc=0x0c0c2718u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c280au,2);
goto P_0c0c271a;
P_0c0c271a: /* original d345, guest PC 0x0c0c271a */
if(!s->budget--) { s->failed_pc=0x0c0c271au; return 0; }
r[3]=read(ram,0x0c0c2830u,4);
goto P_0c0c271c;
P_0c0c271c: /* original 36ec, guest PC 0x0c0c271c */
if(!s->budget--) { s->failed_pc=0x0c0c271cu; return 0; }
r[6]+=r[14];
goto P_0c0c271e;
P_0c0c271e: /* original 430b, guest PC 0x0c0c271e */
if(!s->budget--) { s->failed_pc=0x0c0c271eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c2722u;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2722u) { target=s->pc; goto dispatch; }
goto P_0c0c2722;
P_0c0c2720: /* original 65e3, guest PC 0x0c0c2720 */
if(!s->budget--) { s->failed_pc=0x0c0c2720u; return 0; }
r[5]=r[14];
goto P_0c0c2722;
P_0c0c2722: /* original 9d75, guest PC 0x0c0c2722 */
if(!s->budget--) { s->failed_pc=0x0c0c2722u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2810u,2);
goto P_0c0c2724;
P_0c0c2724: /* original e500, guest PC 0x0c0c2724 */
if(!s->budget--) { s->failed_pc=0x0c0c2724u; return 0; }
r[5]=0x00000000u;
goto P_0c0c2726;
P_0c0c2726: /* original e679, guest PC 0x0c0c2726 */
if(!s->budget--) { s->failed_pc=0x0c0c2726u; return 0; }
r[6]=0x00000079u;
goto P_0c0c2728;
P_0c0c2728: /* original 3dec, guest PC 0x0c0c2728 */
if(!s->budget--) { s->failed_pc=0x0c0c2728u; return 0; }
r[13]+=r[14];
goto P_0c0c272a;
P_0c0c272a: /* original bc02, guest PC 0x0c0c272a */
if(!s->budget--) { s->failed_pc=0x0c0c272au; return 0; }
target=code_base|0x0c0c1f32u; r[16]=code_base|0x0c0c272eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c272eu) { target=s->pc; goto dispatch; }
goto P_0c0c272e;
P_0c0c272c: /* original 64d3, guest PC 0x0c0c272c */
if(!s->budget--) { s->failed_pc=0x0c0c272cu; return 0; }
r[4]=r[13];
goto P_0c0c272e;
P_0c0c272e: /* original e700, guest PC 0x0c0c272e */
if(!s->budget--) { s->failed_pc=0x0c0c272eu; return 0; }
r[7]=0x00000000u;
goto P_0c0c2730;
P_0c0c2730: /* original 956f, guest PC 0x0c0c2730 */
if(!s->budget--) { s->failed_pc=0x0c0c2730u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2812u,2);
goto P_0c0c2732;
P_0c0c2732: /* original 6673, guest PC 0x0c0c2732 */
if(!s->budget--) { s->failed_pc=0x0c0c2732u; return 0; }
r[6]=r[7];
goto P_0c0c2734;
P_0c0c2734: /* original bc2e, guest PC 0x0c0c2734 */
if(!s->budget--) { s->failed_pc=0x0c0c2734u; return 0; }
target=code_base|0x0c0c1f94u; r[16]=code_base|0x0c0c2738u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2738u) { target=s->pc; goto dispatch; }
goto P_0c0c2738;
P_0c0c2736: /* original 64d3, guest PC 0x0c0c2736 */
if(!s->budget--) { s->failed_pc=0x0c0c2736u; return 0; }
r[4]=r[13];
goto P_0c0c2738;
P_0c0c2738: /* original e700, guest PC 0x0c0c2738 */
if(!s->budget--) { s->failed_pc=0x0c0c2738u; return 0; }
r[7]=0x00000000u;
goto P_0c0c273a;
P_0c0c273a: /* original 6573, guest PC 0x0c0c273a */
if(!s->budget--) { s->failed_pc=0x0c0c273au; return 0; }
r[5]=r[7];
goto P_0c0c273c;
P_0c0c273c: /* original 6673, guest PC 0x0c0c273c */
if(!s->budget--) { s->failed_pc=0x0c0c273cu; return 0; }
r[6]=r[7];
goto P_0c0c273e;
P_0c0c273e: /* original bc29, guest PC 0x0c0c273e */
if(!s->budget--) { s->failed_pc=0x0c0c273eu; return 0; }
target=code_base|0x0c0c1f94u; r[16]=code_base|0x0c0c2742u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2742u) { target=s->pc; goto dispatch; }
goto P_0c0c2742;
P_0c0c2740: /* original 64d3, guest PC 0x0c0c2740 */
if(!s->budget--) { s->failed_pc=0x0c0c2740u; return 0; }
r[4]=r[13];
goto P_0c0c2742;
P_0c0c2742: /* original e700, guest PC 0x0c0c2742 */
if(!s->budget--) { s->failed_pc=0x0c0c2742u; return 0; }
r[7]=0x00000000u;
goto P_0c0c2744;
P_0c0c2744: /* original 9566, guest PC 0x0c0c2744 */
if(!s->budget--) { s->failed_pc=0x0c0c2744u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2814u,2);
goto P_0c0c2746;
P_0c0c2746: /* original 6673, guest PC 0x0c0c2746 */
if(!s->budget--) { s->failed_pc=0x0c0c2746u; return 0; }
r[6]=r[7];
goto P_0c0c2748;
P_0c0c2748: /* original bc24, guest PC 0x0c0c2748 */
if(!s->budget--) { s->failed_pc=0x0c0c2748u; return 0; }
target=code_base|0x0c0c1f94u; r[16]=code_base|0x0c0c274cu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c274cu) { target=s->pc; goto dispatch; }
goto P_0c0c274c;
P_0c0c274a: /* original 64d3, guest PC 0x0c0c274a */
if(!s->budget--) { s->failed_pc=0x0c0c274au; return 0; }
r[4]=r[13];
goto P_0c0c274c;
P_0c0c274c: /* original d339, guest PC 0x0c0c274c */
if(!s->budget--) { s->failed_pc=0x0c0c274cu; return 0; }
r[3]=read(ram,0x0c0c2834u,4);
goto P_0c0c274e;
P_0c0c274e: /* original e2ff, guest PC 0x0c0c274e */
if(!s->budget--) { s->failed_pc=0x0c0c274eu; return 0; }
r[2]=0xffffffffu;
goto P_0c0c2750;
P_0c0c2750: /* original 2321, guest PC 0x0c0c2750 */
if(!s->budget--) { s->failed_pc=0x0c0c2750u; return 0; }
write(ram,r[3],r[2],2);
goto P_0c0c2752;
P_0c0c2752: /* original d239, guest PC 0x0c0c2752 */
if(!s->budget--) { s->failed_pc=0x0c0c2752u; return 0; }
r[2]=read(ram,0x0c0c2838u,4);
goto P_0c0c2754;
P_0c0c2754: /* original 945f, guest PC 0x0c0c2754 */
if(!s->budget--) { s->failed_pc=0x0c0c2754u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2816u,2);
goto P_0c0c2756;
P_0c0c2756: /* original 420b, guest PC 0x0c0c2756 */
if(!s->budget--) { s->failed_pc=0x0c0c2756u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c275au;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c275au) { target=s->pc; goto dispatch; }
goto P_0c0c275a;
P_0c0c2758: /* original 34ec, guest PC 0x0c0c2758 */
if(!s->budget--) { s->failed_pc=0x0c0c2758u; return 0; }
r[4]+=r[14];
goto P_0c0c275a;
P_0c0c275a: /* original dd38, guest PC 0x0c0c275a */
if(!s->budget--) { s->failed_pc=0x0c0c275au; return 0; }
r[13]=read(ram,0x0c0c283cu,4);
goto P_0c0c275c;
P_0c0c275c: /* original 64e3, guest PC 0x0c0c275c */
if(!s->budget--) { s->failed_pc=0x0c0c275cu; return 0; }
r[4]=r[14];
goto P_0c0c275e;
P_0c0c275e: /* original 2ff6, guest PC 0x0c0c275e */
if(!s->budget--) { s->failed_pc=0x0c0c275eu; return 0; }
tmp=r[15]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2760;
P_0c0c2760: /* original 2ff6, guest PC 0x0c0c2760 */
if(!s->budget--) { s->failed_pc=0x0c0c2760u; return 0; }
tmp=r[15]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2762;
P_0c0c2762: /* original 67d3, guest PC 0x0c0c2762 */
if(!s->budget--) { s->failed_pc=0x0c0c2762u; return 0; }
r[7]=r[13];
goto P_0c0c2764;
P_0c0c2764: /* original 66f3, guest PC 0x0c0c2764 */
if(!s->budget--) { s->failed_pc=0x0c0c2764u; return 0; }
r[6]=r[15];
goto P_0c0c2766;
P_0c0c2766: /* original b97e, guest PC 0x0c0c2766 */
if(!s->budget--) { s->failed_pc=0x0c0c2766u; return 0; }
target=code_base|0x0c0c1a66u; r[16]=code_base|0x0c0c276au;
r[5]=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c276au) { target=s->pc; goto dispatch; }
goto P_0c0c276a;
P_0c0c2768: /* original e518, guest PC 0x0c0c2768 */
if(!s->budget--) { s->failed_pc=0x0c0c2768u; return 0; }
r[5]=0x00000018u;
goto P_0c0c276a;
P_0c0c276a: /* original 9755, guest PC 0x0c0c276a */
if(!s->budget--) { s->failed_pc=0x0c0c276au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2818u,2);
goto P_0c0c276c;
P_0c0c276c: /* original 64e3, guest PC 0x0c0c276c */
if(!s->budget--) { s->failed_pc=0x0c0c276cu; return 0; }
r[4]=r[14];
goto P_0c0c276e;
P_0c0c276e: /* original 2ff6, guest PC 0x0c0c276e */
if(!s->budget--) { s->failed_pc=0x0c0c276eu; return 0; }
tmp=r[15]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2770;
P_0c0c2770: /* original 742c, guest PC 0x0c0c2770 */
if(!s->budget--) { s->failed_pc=0x0c0c2770u; return 0; }
r[4]+=0x0000002cu;
goto P_0c0c2772;
P_0c0c2772: /* original 2ff6, guest PC 0x0c0c2772 */
if(!s->budget--) { s->failed_pc=0x0c0c2772u; return 0; }
tmp=r[15]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2774;
P_0c0c2774: /* original 37dc, guest PC 0x0c0c2774 */
if(!s->budget--) { s->failed_pc=0x0c0c2774u; return 0; }
r[7]+=r[13];
goto P_0c0c2776;
P_0c0c2776: /* original 66f3, guest PC 0x0c0c2776 */
if(!s->budget--) { s->failed_pc=0x0c0c2776u; return 0; }
r[6]=r[15];
goto P_0c0c2778;
P_0c0c2778: /* original b975, guest PC 0x0c0c2778 */
if(!s->budget--) { s->failed_pc=0x0c0c2778u; return 0; }
target=code_base|0x0c0c1a66u; r[16]=code_base|0x0c0c277cu;
r[5]=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c277cu) { target=s->pc; goto dispatch; }
goto P_0c0c277c;
P_0c0c277a: /* original e518, guest PC 0x0c0c277a */
if(!s->budget--) { s->failed_pc=0x0c0c277au; return 0; }
r[5]=0x00000018u;
goto P_0c0c277c;
P_0c0c277c: /* original 9749, guest PC 0x0c0c277c */
if(!s->budget--) { s->failed_pc=0x0c0c277cu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2812u,2);
goto P_0c0c277e;
P_0c0c277e: /* original 64e3, guest PC 0x0c0c277e */
if(!s->budget--) { s->failed_pc=0x0c0c277eu; return 0; }
r[4]=r[14];
goto P_0c0c2780;
P_0c0c2780: /* original 2ff6, guest PC 0x0c0c2780 */
if(!s->budget--) { s->failed_pc=0x0c0c2780u; return 0; }
tmp=r[15]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2782;
P_0c0c2782: /* original 7458, guest PC 0x0c0c2782 */
if(!s->budget--) { s->failed_pc=0x0c0c2782u; return 0; }
r[4]+=0x00000058u;
goto P_0c0c2784;
P_0c0c2784: /* original 2ff6, guest PC 0x0c0c2784 */
if(!s->budget--) { s->failed_pc=0x0c0c2784u; return 0; }
tmp=r[15]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2786;
P_0c0c2786: /* original 37dc, guest PC 0x0c0c2786 */
if(!s->budget--) { s->failed_pc=0x0c0c2786u; return 0; }
r[7]+=r[13];
goto P_0c0c2788;
P_0c0c2788: /* original 66f3, guest PC 0x0c0c2788 */
if(!s->budget--) { s->failed_pc=0x0c0c2788u; return 0; }
r[6]=r[15];
goto P_0c0c278a;
P_0c0c278a: /* original b96c, guest PC 0x0c0c278a */
if(!s->budget--) { s->failed_pc=0x0c0c278au; return 0; }
target=code_base|0x0c0c1a66u; r[16]=code_base|0x0c0c278eu;
r[5]=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c278eu) { target=s->pc; goto dispatch; }
goto P_0c0c278e;
P_0c0c278c: /* original e518, guest PC 0x0c0c278c */
if(!s->budget--) { s->failed_pc=0x0c0c278cu; return 0; }
r[5]=0x00000018u;
goto P_0c0c278e;
P_0c0c278e: /* original 943e, guest PC 0x0c0c278e */
if(!s->budget--) { s->failed_pc=0x0c0c278eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c280eu,2);
goto P_0c0c2790;
P_0c0c2790: /* original 9743, guest PC 0x0c0c2790 */
if(!s->budget--) { s->failed_pc=0x0c0c2790u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c281au,2);
goto P_0c0c2792;
P_0c0c2792: /* original 2ff6, guest PC 0x0c0c2792 */
if(!s->budget--) { s->failed_pc=0x0c0c2792u; return 0; }
tmp=r[15]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2794;
P_0c0c2794: /* original 34ec, guest PC 0x0c0c2794 */
if(!s->budget--) { s->failed_pc=0x0c0c2794u; return 0; }
r[4]+=r[14];
goto P_0c0c2796;
P_0c0c2796: /* original 2ff6, guest PC 0x0c0c2796 */
if(!s->budget--) { s->failed_pc=0x0c0c2796u; return 0; }
tmp=r[15]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2798;
P_0c0c2798: /* original 37dc, guest PC 0x0c0c2798 */
if(!s->budget--) { s->failed_pc=0x0c0c2798u; return 0; }
r[7]+=r[13];
goto P_0c0c279a;
P_0c0c279a: /* original 66f3, guest PC 0x0c0c279a */
if(!s->budget--) { s->failed_pc=0x0c0c279au; return 0; }
r[6]=r[15];
goto P_0c0c279c;
P_0c0c279c: /* original b963, guest PC 0x0c0c279c */
if(!s->budget--) { s->failed_pc=0x0c0c279cu; return 0; }
target=code_base|0x0c0c1a66u; r[16]=code_base|0x0c0c27a0u;
r[5]=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c27a0u) { target=s->pc; goto dispatch; }
goto P_0c0c27a0;
P_0c0c279e: /* original e518, guest PC 0x0c0c279e */
if(!s->budget--) { s->failed_pc=0x0c0c279eu; return 0; }
r[5]=0x00000018u;
goto P_0c0c27a0;
P_0c0c27a0: /* original 7f20, guest PC 0x0c0c27a0 */
if(!s->budget--) { s->failed_pc=0x0c0c27a0u; return 0; }
r[15]+=0x00000020u;
goto P_0c0c27a2;
P_0c0c27a2: /* original 4f26, guest PC 0x0c0c27a2 */
if(!s->budget--) { s->failed_pc=0x0c0c27a2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c27a4;
P_0c0c27a4: /* original 6df6, guest PC 0x0c0c27a4 */
if(!s->budget--) { s->failed_pc=0x0c0c27a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c27a6;
P_0c0c27a6: /* original 000b, guest PC 0x0c0c27a6 */
if(!s->budget--) { s->failed_pc=0x0c0c27a6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c27a8: /* original 6ef6, guest PC 0x0c0c27a8 */
if(!s->budget--) { s->failed_pc=0x0c0c27a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c27aau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c27aau; return 0; } return 1;
P_0c0c285c: /* original 2fe6, guest PC 0x0c0c285c */
if(!s->budget--) { s->failed_pc=0x0c0c285cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c285e;
P_0c0c285e: /* original 2fd6, guest PC 0x0c0c285e */
if(!s->budget--) { s->failed_pc=0x0c0c285eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2860;
P_0c0c2860: /* original 2fc6, guest PC 0x0c0c2860 */
if(!s->budget--) { s->failed_pc=0x0c0c2860u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2862;
P_0c0c2862: /* original 2fb6, guest PC 0x0c0c2862 */
if(!s->budget--) { s->failed_pc=0x0c0c2862u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2864;
P_0c0c2864: /* original 2fa6, guest PC 0x0c0c2864 */
if(!s->budget--) { s->failed_pc=0x0c0c2864u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2866;
P_0c0c2866: /* original 2f96, guest PC 0x0c0c2866 */
if(!s->budget--) { s->failed_pc=0x0c0c2866u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2868;
P_0c0c2868: /* original 2f86, guest PC 0x0c0c2868 */
if(!s->budget--) { s->failed_pc=0x0c0c2868u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c286a;
P_0c0c286a: /* original 9074, guest PC 0x0c0c286a */
if(!s->budget--) { s->failed_pc=0x0c0c286au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2956u,2);
goto P_0c0c286c;
P_0c0c286c: /* original d83f, guest PC 0x0c0c286c */
if(!s->budget--) { s->failed_pc=0x0c0c286cu; return 0; }
r[8]=read(ram,0x0c0c296cu,4);
goto P_0c0c286e;
P_0c0c286e: /* original 9373, guest PC 0x0c0c286e */
if(!s->budget--) { s->failed_pc=0x0c0c286eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2958u,2);
goto P_0c0c2870;
P_0c0c2870: /* original 048e, guest PC 0x0c0c2870 */
if(!s->budget--) { s->failed_pc=0x0c0c2870u; return 0; }
r[4]=read(ram,r[8]+r[0],4);
goto P_0c0c2872;
P_0c0c2872: /* original 4f22, guest PC 0x0c0c2872 */
if(!s->budget--) { s->failed_pc=0x0c0c2872u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c2874;
P_0c0c2874: /* original dc41, guest PC 0x0c0c2874 */
if(!s->budget--) { s->failed_pc=0x0c0c2874u; return 0; }
r[12]=read(ram,0x0c0c297cu,4);
goto P_0c0c2876;
P_0c0c2876: /* original 3430, guest PC 0x0c0c2876 */
if(!s->budget--) { s->failed_pc=0x0c0c2876u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c0c2878;
P_0c0c2878: /* original dd41, guest PC 0x0c0c2878 */
if(!s->budget--) { s->failed_pc=0x0c0c2878u; return 0; }
r[13]=read(ram,0x0c0c2980u,4);
goto P_0c0c287a;
P_0c0c287a: /* original d93d, guest PC 0x0c0c287a */
if(!s->budget--) { s->failed_pc=0x0c0c287au; return 0; }
r[9]=read(ram,0x0c0c2970u,4);
goto P_0c0c287c;
P_0c0c287c: /* original da3d, guest PC 0x0c0c287c */
if(!s->budget--) { s->failed_pc=0x0c0c287cu; return 0; }
r[10]=read(ram,0x0c0c2974u,4);
goto P_0c0c287e;
P_0c0c287e: /* original db3e, guest PC 0x0c0c287e */
if(!s->budget--) { s->failed_pc=0x0c0c287eu; return 0; }
r[11]=read(ram,0x0c0c2978u,4);
goto P_0c0c2880;
P_0c0c2880: /* original 8b08, guest PC 0x0c0c2880 */
if(!s->budget--) { s->failed_pc=0x0c0c2880u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2894; }
goto P_0c0c2882;
P_0c0c2882: /* original 4c0b, guest PC 0x0c0c2882 */
if(!s->budget--) { s->failed_pc=0x0c0c2882u; return 0; }
target=r[12];
r[16]=code_base|0x0c0c2886u;
r[4]=0x0000001du;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2886u) { target=s->pc; goto dispatch; }
goto P_0c0c2886;
P_0c0c2884: /* original e41d, guest PC 0x0c0c2884 */
if(!s->budget--) { s->failed_pc=0x0c0c2884u; return 0; }
r[4]=0x0000001du;
goto P_0c0c2886;
P_0c0c2886: /* original 65a2, guest PC 0x0c0c2886 */
if(!s->budget--) { s->failed_pc=0x0c0c2886u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0c2888;
P_0c0c2888: /* original 6493, guest PC 0x0c0c2888 */
if(!s->budget--) { s->failed_pc=0x0c0c2888u; return 0; }
r[4]=r[9];
goto P_0c0c288a;
P_0c0c288a: /* original 4b0b, guest PC 0x0c0c288a */
if(!s->budget--) { s->failed_pc=0x0c0c288au; return 0; }
target=r[11];
r[16]=code_base|0x0c0c288eu;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c288eu) { target=s->pc; goto dispatch; }
goto P_0c0c288e;
P_0c0c288c: /* original 7410, guest PC 0x0c0c288c */
if(!s->budget--) { s->failed_pc=0x0c0c288cu; return 0; }
r[4]+=0x00000010u;
goto P_0c0c288e;
P_0c0c288e: /* original 7d3a, guest PC 0x0c0c288e */
if(!s->budget--) { s->failed_pc=0x0c0c288eu; return 0; }
r[13]+=0x0000003au;
goto P_0c0c2890;
P_0c0c2890: /* original a039, guest PC 0x0c0c2890 */
if(!s->budget--) { s->failed_pc=0x0c0c2890u; return 0; }
r[3]=0x0000001du;
goto P_0c0c2906;
P_0c0c2892: /* original e31d, guest PC 0x0c0c2892 */
if(!s->budget--) { s->failed_pc=0x0c0c2892u; return 0; }
r[3]=0x0000001du;
goto P_0c0c2894;
P_0c0c2894: /* original 9161, guest PC 0x0c0c2894 */
if(!s->budget--) { s->failed_pc=0x0c0c2894u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c295au,2);
goto P_0c0c2896;
P_0c0c2896: /* original 3410, guest PC 0x0c0c2896 */
if(!s->budget--) { s->failed_pc=0x0c0c2896u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[1])!=0);
goto P_0c0c2898;
P_0c0c2898: /* original 8b09, guest PC 0x0c0c2898 */
if(!s->budget--) { s->failed_pc=0x0c0c2898u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c28ae; }
goto P_0c0c289a;
P_0c0c289a: /* original 4c0b, guest PC 0x0c0c289a */
if(!s->budget--) { s->failed_pc=0x0c0c289au; return 0; }
target=r[12];
r[16]=code_base|0x0c0c289eu;
r[4]=0x0000001eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c289eu) { target=s->pc; goto dispatch; }
goto P_0c0c289e;
P_0c0c289c: /* original e41e, guest PC 0x0c0c289c */
if(!s->budget--) { s->failed_pc=0x0c0c289cu; return 0; }
r[4]=0x0000001eu;
goto P_0c0c289e;
P_0c0c289e: /* original 65a2, guest PC 0x0c0c289e */
if(!s->budget--) { s->failed_pc=0x0c0c289eu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0c28a0;
P_0c0c28a0: /* original 6493, guest PC 0x0c0c28a0 */
if(!s->budget--) { s->failed_pc=0x0c0c28a0u; return 0; }
r[4]=r[9];
goto P_0c0c28a2;
P_0c0c28a2: /* original 4b0b, guest PC 0x0c0c28a2 */
if(!s->budget--) { s->failed_pc=0x0c0c28a2u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c28a6u;
r[4]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c28a6u) { target=s->pc; goto dispatch; }
goto P_0c0c28a6;
P_0c0c28a4: /* original 7420, guest PC 0x0c0c28a4 */
if(!s->budget--) { s->failed_pc=0x0c0c28a4u; return 0; }
r[4]+=0x00000020u;
goto P_0c0c28a6;
P_0c0c28a6: /* original e31e, guest PC 0x0c0c28a6 */
if(!s->budget--) { s->failed_pc=0x0c0c28a6u; return 0; }
r[3]=0x0000001eu;
goto P_0c0c28a8;
P_0c0c28a8: /* original 7d3c, guest PC 0x0c0c28a8 */
if(!s->budget--) { s->failed_pc=0x0c0c28a8u; return 0; }
r[13]+=0x0000003cu;
goto P_0c0c28aa;
P_0c0c28aa: /* original a02c, guest PC 0x0c0c28aa */
if(!s->budget--) { s->failed_pc=0x0c0c28aau; return 0; }
goto P_0c0c2906;
P_0c0c28ac: /* original 0009, guest PC 0x0c0c28ac */
if(!s->budget--) { s->failed_pc=0x0c0c28acu; return 0; }
goto P_0c0c28ae;
P_0c0c28ae: /* original 9055, guest PC 0x0c0c28ae */
if(!s->budget--) { s->failed_pc=0x0c0c28aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c295cu,2);
goto P_0c0c28b0;
P_0c0c28b0: /* original de34, guest PC 0x0c0c28b0 */
if(!s->budget--) { s->failed_pc=0x0c0c28b0u; return 0; }
r[14]=read(ram,0x0c0c2984u,4);
goto P_0c0c28b2;
P_0c0c28b2: /* original 3400, guest PC 0x0c0c28b2 */
if(!s->budget--) { s->failed_pc=0x0c0c28b2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[0])!=0);
goto P_0c0c28b4;
P_0c0c28b4: /* original 8b0b, guest PC 0x0c0c28b4 */
if(!s->budget--) { s->failed_pc=0x0c0c28b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c28ce; }
goto P_0c0c28b6;
P_0c0c28b6: /* original 4e0b, guest PC 0x0c0c28b6 */
if(!s->budget--) { s->failed_pc=0x0c0c28b6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c28bau;
r[4]=0x00000015u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c28bau) { target=s->pc; goto dispatch; }
goto P_0c0c28ba;
P_0c0c28b8: /* original e415, guest PC 0x0c0c28b8 */
if(!s->budget--) { s->failed_pc=0x0c0c28b8u; return 0; }
r[4]=0x00000015u;
goto P_0c0c28ba;
P_0c0c28ba: /* original 4c0b, guest PC 0x0c0c28ba */
if(!s->budget--) { s->failed_pc=0x0c0c28bau; return 0; }
target=r[12];
r[16]=code_base|0x0c0c28beu;
r[4]=0x0000001fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c28beu) { target=s->pc; goto dispatch; }
goto P_0c0c28be;
P_0c0c28bc: /* original e41f, guest PC 0x0c0c28bc */
if(!s->budget--) { s->failed_pc=0x0c0c28bcu; return 0; }
r[4]=0x0000001fu;
goto P_0c0c28be;
P_0c0c28be: /* original 65a2, guest PC 0x0c0c28be */
if(!s->budget--) { s->failed_pc=0x0c0c28beu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0c28c0;
P_0c0c28c0: /* original 6493, guest PC 0x0c0c28c0 */
if(!s->budget--) { s->failed_pc=0x0c0c28c0u; return 0; }
r[4]=r[9];
goto P_0c0c28c2;
P_0c0c28c2: /* original 4b0b, guest PC 0x0c0c28c2 */
if(!s->budget--) { s->failed_pc=0x0c0c28c2u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c28c6u;
r[4]+=0x00000030u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c28c6u) { target=s->pc; goto dispatch; }
goto P_0c0c28c6;
P_0c0c28c4: /* original 7430, guest PC 0x0c0c28c4 */
if(!s->budget--) { s->failed_pc=0x0c0c28c4u; return 0; }
r[4]+=0x00000030u;
goto P_0c0c28c6;
P_0c0c28c6: /* original e21f, guest PC 0x0c0c28c6 */
if(!s->budget--) { s->failed_pc=0x0c0c28c6u; return 0; }
r[2]=0x0000001fu;
goto P_0c0c28c8;
P_0c0c28c8: /* original 7d3e, guest PC 0x0c0c28c8 */
if(!s->budget--) { s->failed_pc=0x0c0c28c8u; return 0; }
r[13]+=0x0000003eu;
goto P_0c0c28ca;
P_0c0c28ca: /* original a030, guest PC 0x0c0c28ca */
if(!s->budget--) { s->failed_pc=0x0c0c28cau; return 0; }
write(ram,r[13],r[2],2);
goto P_0c0c292e;
P_0c0c28cc: /* original 2d21, guest PC 0x0c0c28cc */
if(!s->budget--) { s->failed_pc=0x0c0c28ccu; return 0; }
write(ram,r[13],r[2],2);
goto P_0c0c28ce;
P_0c0c28ce: /* original 9346, guest PC 0x0c0c28ce */
if(!s->budget--) { s->failed_pc=0x0c0c28ceu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c295eu,2);
goto P_0c0c28d0;
P_0c0c28d0: /* original 3430, guest PC 0x0c0c28d0 */
if(!s->budget--) { s->failed_pc=0x0c0c28d0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c0c28d2;
P_0c0c28d2: /* original 8b0b, guest PC 0x0c0c28d2 */
if(!s->budget--) { s->failed_pc=0x0c0c28d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c28ec; }
goto P_0c0c28d4;
P_0c0c28d4: /* original 4e0b, guest PC 0x0c0c28d4 */
if(!s->budget--) { s->failed_pc=0x0c0c28d4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c28d8u;
r[4]=0x0000001du;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c28d8u) { target=s->pc; goto dispatch; }
goto P_0c0c28d8;
P_0c0c28d6: /* original e41d, guest PC 0x0c0c28d6 */
if(!s->budget--) { s->failed_pc=0x0c0c28d6u; return 0; }
r[4]=0x0000001du;
goto P_0c0c28d8;
P_0c0c28d8: /* original 4c0b, guest PC 0x0c0c28d8 */
if(!s->budget--) { s->failed_pc=0x0c0c28d8u; return 0; }
target=r[12];
r[16]=code_base|0x0c0c28dcu;
r[4]=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c28dcu) { target=s->pc; goto dispatch; }
goto P_0c0c28dc;
P_0c0c28da: /* original e420, guest PC 0x0c0c28da */
if(!s->budget--) { s->failed_pc=0x0c0c28dau; return 0; }
r[4]=0x00000020u;
goto P_0c0c28dc;
P_0c0c28dc: /* original 65a2, guest PC 0x0c0c28dc */
if(!s->budget--) { s->failed_pc=0x0c0c28dcu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0c28de;
P_0c0c28de: /* original 6493, guest PC 0x0c0c28de */
if(!s->budget--) { s->failed_pc=0x0c0c28deu; return 0; }
r[4]=r[9];
goto P_0c0c28e0;
P_0c0c28e0: /* original 4b0b, guest PC 0x0c0c28e0 */
if(!s->budget--) { s->failed_pc=0x0c0c28e0u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c28e4u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c28e4u) { target=s->pc; goto dispatch; }
goto P_0c0c28e4;
P_0c0c28e2: /* original 7440, guest PC 0x0c0c28e2 */
if(!s->budget--) { s->failed_pc=0x0c0c28e2u; return 0; }
r[4]+=0x00000040u;
goto P_0c0c28e4;
P_0c0c28e4: /* original e320, guest PC 0x0c0c28e4 */
if(!s->budget--) { s->failed_pc=0x0c0c28e4u; return 0; }
r[3]=0x00000020u;
goto P_0c0c28e6;
P_0c0c28e6: /* original 7d40, guest PC 0x0c0c28e6 */
if(!s->budget--) { s->failed_pc=0x0c0c28e6u; return 0; }
r[13]+=0x00000040u;
goto P_0c0c28e8;
P_0c0c28e8: /* original a00d, guest PC 0x0c0c28e8 */
if(!s->budget--) { s->failed_pc=0x0c0c28e8u; return 0; }
goto P_0c0c2906;
P_0c0c28ea: /* original 0009, guest PC 0x0c0c28ea */
if(!s->budget--) { s->failed_pc=0x0c0c28eau; return 0; }
goto P_0c0c28ec;
P_0c0c28ec: /* original 9138, guest PC 0x0c0c28ec */
if(!s->budget--) { s->failed_pc=0x0c0c28ecu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2960u,2);
goto P_0c0c28ee;
P_0c0c28ee: /* original 3410, guest PC 0x0c0c28ee */
if(!s->budget--) { s->failed_pc=0x0c0c28eeu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[1])!=0);
goto P_0c0c28f0;
P_0c0c28f0: /* original 8b0b, guest PC 0x0c0c28f0 */
if(!s->budget--) { s->failed_pc=0x0c0c28f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c290a; }
goto P_0c0c28f2;
P_0c0c28f2: /* original 4e0b, guest PC 0x0c0c28f2 */
if(!s->budget--) { s->failed_pc=0x0c0c28f2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c28f6u;
r[4]=0x0000001eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c28f6u) { target=s->pc; goto dispatch; }
goto P_0c0c28f6;
P_0c0c28f4: /* original e41e, guest PC 0x0c0c28f4 */
if(!s->budget--) { s->failed_pc=0x0c0c28f4u; return 0; }
r[4]=0x0000001eu;
goto P_0c0c28f6;
P_0c0c28f6: /* original 4c0b, guest PC 0x0c0c28f6 */
if(!s->budget--) { s->failed_pc=0x0c0c28f6u; return 0; }
target=r[12];
r[16]=code_base|0x0c0c28fau;
r[4]=0x00000021u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c28fau) { target=s->pc; goto dispatch; }
goto P_0c0c28fa;
P_0c0c28f8: /* original e421, guest PC 0x0c0c28f8 */
if(!s->budget--) { s->failed_pc=0x0c0c28f8u; return 0; }
r[4]=0x00000021u;
goto P_0c0c28fa;
P_0c0c28fa: /* original 65a2, guest PC 0x0c0c28fa */
if(!s->budget--) { s->failed_pc=0x0c0c28fau; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0c28fc;
P_0c0c28fc: /* original 6493, guest PC 0x0c0c28fc */
if(!s->budget--) { s->failed_pc=0x0c0c28fcu; return 0; }
r[4]=r[9];
goto P_0c0c28fe;
P_0c0c28fe: /* original 4b0b, guest PC 0x0c0c28fe */
if(!s->budget--) { s->failed_pc=0x0c0c28feu; return 0; }
target=r[11];
r[16]=code_base|0x0c0c2902u;
r[4]+=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2902u) { target=s->pc; goto dispatch; }
goto P_0c0c2902;
P_0c0c2900: /* original 7450, guest PC 0x0c0c2900 */
if(!s->budget--) { s->failed_pc=0x0c0c2900u; return 0; }
r[4]+=0x00000050u;
goto P_0c0c2902;
P_0c0c2902: /* original e321, guest PC 0x0c0c2902 */
if(!s->budget--) { s->failed_pc=0x0c0c2902u; return 0; }
r[3]=0x00000021u;
goto P_0c0c2904;
P_0c0c2904: /* original 7d42, guest PC 0x0c0c2904 */
if(!s->budget--) { s->failed_pc=0x0c0c2904u; return 0; }
r[13]+=0x00000042u;
goto P_0c0c2906;
P_0c0c2906: /* original a012, guest PC 0x0c0c2906 */
if(!s->budget--) { s->failed_pc=0x0c0c2906u; return 0; }
write(ram,r[13],r[3],2);
goto P_0c0c292e;
P_0c0c2908: /* original 2d31, guest PC 0x0c0c2908 */
if(!s->budget--) { s->failed_pc=0x0c0c2908u; return 0; }
write(ram,r[13],r[3],2);
goto P_0c0c290a;
P_0c0c290a: /* original 902a, guest PC 0x0c0c290a */
if(!s->budget--) { s->failed_pc=0x0c0c290au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2962u,2);
goto P_0c0c290c;
P_0c0c290c: /* original 3400, guest PC 0x0c0c290c */
if(!s->budget--) { s->failed_pc=0x0c0c290cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[0])!=0);
goto P_0c0c290e;
P_0c0c290e: /* original 8b01, guest PC 0x0c0c290e */
if(!s->budget--) { s->failed_pc=0x0c0c290eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2914; }
goto P_0c0c2910;
P_0c0c2910: /* original a004, guest PC 0x0c0c2910 */
if(!s->budget--) { s->failed_pc=0x0c0c2910u; return 0; }
r[4]=0x0000001fu;
goto P_0c0c291c;
P_0c0c2912: /* original e41f, guest PC 0x0c0c2912 */
if(!s->budget--) { s->failed_pc=0x0c0c2912u; return 0; }
r[4]=0x0000001fu;
goto P_0c0c2914;
P_0c0c2914: /* original 9326, guest PC 0x0c0c2914 */
if(!s->budget--) { s->failed_pc=0x0c0c2914u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2964u,2);
goto P_0c0c2916;
P_0c0c2916: /* original 3430, guest PC 0x0c0c2916 */
if(!s->budget--) { s->failed_pc=0x0c0c2916u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c0c2918;
P_0c0c2918: /* original 8b04, guest PC 0x0c0c2918 */
if(!s->budget--) { s->failed_pc=0x0c0c2918u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2924; }
goto P_0c0c291a;
P_0c0c291a: /* original e420, guest PC 0x0c0c291a */
if(!s->budget--) { s->failed_pc=0x0c0c291au; return 0; }
r[4]=0x00000020u;
goto P_0c0c291c;
P_0c0c291c: /* original 4e0b, guest PC 0x0c0c291c */
if(!s->budget--) { s->failed_pc=0x0c0c291cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c2920u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2920u) { target=s->pc; goto dispatch; }
goto P_0c0c2920;
P_0c0c291e: /* original 0009, guest PC 0x0c0c291e */
if(!s->budget--) { s->failed_pc=0x0c0c291eu; return 0; }
goto P_0c0c2920;
P_0c0c2920: /* original a005, guest PC 0x0c0c2920 */
if(!s->budget--) { s->failed_pc=0x0c0c2920u; return 0; }
goto P_0c0c292e;
P_0c0c2922: /* original 0009, guest PC 0x0c0c2922 */
if(!s->budget--) { s->failed_pc=0x0c0c2922u; return 0; }
goto P_0c0c2924;
P_0c0c2924: /* original 921f, guest PC 0x0c0c2924 */
if(!s->budget--) { s->failed_pc=0x0c0c2924u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2966u,2);
goto P_0c0c2926;
P_0c0c2926: /* original 3420, guest PC 0x0c0c2926 */
if(!s->budget--) { s->failed_pc=0x0c0c2926u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c0c2928;
P_0c0c2928: /* original 8b01, guest PC 0x0c0c2928 */
if(!s->budget--) { s->failed_pc=0x0c0c2928u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c292e; }
goto P_0c0c292a;
P_0c0c292a: /* original 4e0b, guest PC 0x0c0c292a */
if(!s->budget--) { s->failed_pc=0x0c0c292au; return 0; }
target=r[14];
r[16]=code_base|0x0c0c292eu;
r[4]=0x00000021u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c292eu) { target=s->pc; goto dispatch; }
goto P_0c0c292e;
P_0c0c292c: /* original e421, guest PC 0x0c0c292c */
if(!s->budget--) { s->failed_pc=0x0c0c292cu; return 0; }
r[4]=0x00000021u;
goto P_0c0c292e;
P_0c0c292e: /* original 901b, guest PC 0x0c0c292e */
if(!s->budget--) { s->failed_pc=0x0c0c292eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2968u,2);
goto P_0c0c2930;
P_0c0c2930: /* original 048e, guest PC 0x0c0c2930 */
if(!s->budget--) { s->failed_pc=0x0c0c2930u; return 0; }
r[4]=read(ram,r[8]+r[0],4);
goto P_0c0c2932;
P_0c0c2932: /* original 3f40, guest PC 0x0c0c2932 */
if(!s->budget--) { s->failed_pc=0x0c0c2932u; return 0; }
r[17]=(r[17]&~1u)|((r[15]==r[4])!=0);
goto P_0c0c2934;
P_0c0c2934: /* original 8906, guest PC 0x0c0c2934 */
if(!s->budget--) { s->failed_pc=0x0c0c2934u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2944; }
goto P_0c0c2936;
P_0c0c2936: /* original d214, guest PC 0x0c0c2936 */
if(!s->budget--) { s->failed_pc=0x0c0c2936u; return 0; }
r[2]=read(ram,0x0c0c2988u,4);
goto P_0c0c2938;
P_0c0c2938: /* original e501, guest PC 0x0c0c2938 */
if(!s->budget--) { s->failed_pc=0x0c0c2938u; return 0; }
r[5]=0x00000001u;
goto P_0c0c293a;
P_0c0c293a: /* original e600, guest PC 0x0c0c293a */
if(!s->budget--) { s->failed_pc=0x0c0c293au; return 0; }
r[6]=0x00000000u;
goto P_0c0c293c;
P_0c0c293c: /* original 420b, guest PC 0x0c0c293c */
if(!s->budget--) { s->failed_pc=0x0c0c293cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c2940u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2940u) { target=s->pc; goto dispatch; }
goto P_0c0c2940;
P_0c0c293e: /* original 64f3, guest PC 0x0c0c293e */
if(!s->budget--) { s->failed_pc=0x0c0c293eu; return 0; }
r[4]=r[15];
goto P_0c0c2940;
P_0c0c2940: /* original 9012, guest PC 0x0c0c2940 */
if(!s->budget--) { s->failed_pc=0x0c0c2940u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2968u,2);
goto P_0c0c2942;
P_0c0c2942: /* original 08f6, guest PC 0x0c0c2942 */
if(!s->budget--) { s->failed_pc=0x0c0c2942u; return 0; }
write(ram,r[8]+r[0],r[15],4);
goto P_0c0c2944;
P_0c0c2944: /* original 4f26, guest PC 0x0c0c2944 */
if(!s->budget--) { s->failed_pc=0x0c0c2944u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c2946;
P_0c0c2946: /* original 68f6, guest PC 0x0c0c2946 */
if(!s->budget--) { s->failed_pc=0x0c0c2946u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c2948;
P_0c0c2948: /* original 69f6, guest PC 0x0c0c2948 */
if(!s->budget--) { s->failed_pc=0x0c0c2948u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c294a;
P_0c0c294a: /* original 6af6, guest PC 0x0c0c294a */
if(!s->budget--) { s->failed_pc=0x0c0c294au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c294c;
P_0c0c294c: /* original 6bf6, guest PC 0x0c0c294c */
if(!s->budget--) { s->failed_pc=0x0c0c294cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c294e;
P_0c0c294e: /* original 6cf6, guest PC 0x0c0c294e */
if(!s->budget--) { s->failed_pc=0x0c0c294eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c2950;
P_0c0c2950: /* original 6df6, guest PC 0x0c0c2950 */
if(!s->budget--) { s->failed_pc=0x0c0c2950u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c2952;
P_0c0c2952: /* original 000b, guest PC 0x0c0c2952 */
if(!s->budget--) { s->failed_pc=0x0c0c2952u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c2954: /* original 6ef6, guest PC 0x0c0c2954 */
if(!s->budget--) { s->failed_pc=0x0c0c2954u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c2956u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c2956u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
