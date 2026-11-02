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
int vf3_away_batch241_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c0c4e34u: goto P_0c0c4e34;
case 0x0c0c4e36u: goto P_0c0c4e36;
case 0x0c0c4e38u: goto P_0c0c4e38;
case 0x0c0c4e3au: goto P_0c0c4e3a;
case 0x0c0c4e3cu: goto P_0c0c4e3c;
case 0x0c0c4e3eu: goto P_0c0c4e3e;
case 0x0c0c4e40u: goto P_0c0c4e40;
case 0x0c0c4e42u: goto P_0c0c4e42;
case 0x0c0c4e44u: goto P_0c0c4e44;
case 0x0c0c4e46u: goto P_0c0c4e46;
case 0x0c0c4e48u: goto P_0c0c4e48;
case 0x0c0c4e4au: goto P_0c0c4e4a;
case 0x0c0c4e4cu: goto P_0c0c4e4c;
case 0x0c0c4e4eu: goto P_0c0c4e4e;
case 0x0c0c4e50u: goto P_0c0c4e50;
case 0x0c0c4e52u: goto P_0c0c4e52;
case 0x0c0c4e54u: goto P_0c0c4e54;
case 0x0c0c4e56u: goto P_0c0c4e56;
case 0x0c0c4e58u: goto P_0c0c4e58;
case 0x0c0c4e5au: goto P_0c0c4e5a;
case 0x0c0c4e5cu: goto P_0c0c4e5c;
case 0x0c0c4e5eu: goto P_0c0c4e5e;
case 0x0c0c4e60u: goto P_0c0c4e60;
case 0x0c0c4e62u: goto P_0c0c4e62;
case 0x0c0c4e64u: goto P_0c0c4e64;
case 0x0c0c4e66u: goto P_0c0c4e66;
case 0x0c0c4e68u: goto P_0c0c4e68;
case 0x0c0c4e6au: goto P_0c0c4e6a;
case 0x0c0c4e6cu: goto P_0c0c4e6c;
case 0x0c0c4e6eu: goto P_0c0c4e6e;
case 0x0c0c4e70u: goto P_0c0c4e70;
case 0x0c0c4e72u: goto P_0c0c4e72;
case 0x0c0c4e74u: goto P_0c0c4e74;
case 0x0c0c4e76u: goto P_0c0c4e76;
case 0x0c0c4e78u: goto P_0c0c4e78;
case 0x0c0c4e7au: goto P_0c0c4e7a;
case 0x0c0c4e7cu: goto P_0c0c4e7c;
case 0x0c0c4e7eu: goto P_0c0c4e7e;
case 0x0c0c4e80u: goto P_0c0c4e80;
case 0x0c0c4e82u: goto P_0c0c4e82;
case 0x0c0c4e84u: goto P_0c0c4e84;
case 0x0c0c4e86u: goto P_0c0c4e86;
case 0x0c0c4e88u: goto P_0c0c4e88;
case 0x0c0c4e8au: goto P_0c0c4e8a;
case 0x0c0c4e8cu: goto P_0c0c4e8c;
case 0x0c0c4e8eu: goto P_0c0c4e8e;
case 0x0c0c4e90u: goto P_0c0c4e90;
case 0x0c0c4e92u: goto P_0c0c4e92;
case 0x0c0c4e94u: goto P_0c0c4e94;
case 0x0c0c4e96u: goto P_0c0c4e96;
case 0x0c0c4e98u: goto P_0c0c4e98;
case 0x0c0c4e9au: goto P_0c0c4e9a;
case 0x0c0c4e9cu: goto P_0c0c4e9c;
case 0x0c0c4e9eu: goto P_0c0c4e9e;
case 0x0c0c4ea0u: goto P_0c0c4ea0;
case 0x0c0c4ea2u: goto P_0c0c4ea2;
case 0x0c0c4ea4u: goto P_0c0c4ea4;
case 0x0c0c4ea6u: goto P_0c0c4ea6;
case 0x0c0c4ea8u: goto P_0c0c4ea8;
case 0x0c0c4eaau: goto P_0c0c4eaa;
case 0x0c0c4eacu: goto P_0c0c4eac;
case 0x0c0c4eaeu: goto P_0c0c4eae;
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
P_0c0c4e34: /* original 2fe6, guest PC 0x0c0c4e34 */
if(!s->budget--) { s->failed_pc=0x0c0c4e34u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e36;
P_0c0c4e36: /* original 2fd6, guest PC 0x0c0c4e36 */
if(!s->budget--) { s->failed_pc=0x0c0c4e36u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e38;
P_0c0c4e38: /* original ed00, guest PC 0x0c0c4e38 */
if(!s->budget--) { s->failed_pc=0x0c0c4e38u; return 0; }
r[13]=0x00000000u;
goto P_0c0c4e3a;
P_0c0c4e3a: /* original 2fc6, guest PC 0x0c0c4e3a */
if(!s->budget--) { s->failed_pc=0x0c0c4e3au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e3c;
P_0c0c4e3c: /* original 6ed3, guest PC 0x0c0c4e3c */
if(!s->budget--) { s->failed_pc=0x0c0c4e3cu; return 0; }
r[14]=r[13];
goto P_0c0c4e3e;
P_0c0c4e3e: /* original 2fb6, guest PC 0x0c0c4e3e */
if(!s->budget--) { s->failed_pc=0x0c0c4e3eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e40;
P_0c0c4e40: /* original 2fa6, guest PC 0x0c0c4e40 */
if(!s->budget--) { s->failed_pc=0x0c0c4e40u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e42;
P_0c0c4e42: /* original 2f96, guest PC 0x0c0c4e42 */
if(!s->budget--) { s->failed_pc=0x0c0c4e42u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e44;
P_0c0c4e44: /* original 2f86, guest PC 0x0c0c4e44 */
if(!s->budget--) { s->failed_pc=0x0c0c4e44u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e46;
P_0c0c4e46: /* original fffb, guest PC 0x0c0c4e46 */
if(!s->budget--) { s->failed_pc=0x0c0c4e46u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c4e48;
P_0c0c4e48: /* original ffeb, guest PC 0x0c0c4e48 */
if(!s->budget--) { s->failed_pc=0x0c0c4e48u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0c4e4a;
P_0c0c4e4a: /* original 4f22, guest PC 0x0c0c4e4a */
if(!s->budget--) { s->failed_pc=0x0c0c4e4au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c4e4c;
P_0c0c4e4c: /* original 7ff8, guest PC 0x0c0c4e4c */
if(!s->budget--) { s->failed_pc=0x0c0c4e4cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c4e4e;
P_0c0c4e4e: /* original 2f42, guest PC 0x0c0c4e4e */
if(!s->budget--) { s->failed_pc=0x0c0c4e4eu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c4e50;
P_0c0c4e50: /* original 9078, guest PC 0x0c0c4e50 */
if(!s->budget--) { s->failed_pc=0x0c0c4e50u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f44u,2);
goto P_0c0c4e52;
P_0c0c4e52: /* original 9876, guest PC 0x0c0c4e52 */
if(!s->budget--) { s->failed_pc=0x0c0c4e52u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f42u,2);
goto P_0c0c4e54;
P_0c0c4e54: /* original 81f2, guest PC 0x0c0c4e54 */
if(!s->budget--) { s->failed_pc=0x0c0c4e54u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c0c4e56;
P_0c0c4e56: /* original c740, guest PC 0x0c0c4e56 */
if(!s->budget--) { s->failed_pc=0x0c0c4e56u; return 0; }
r[0]=code_base|0x000c4f58u;
goto P_0c0c4e58;
P_0c0c4e58: /* original fe08, guest PC 0x0c0c4e58 */
if(!s->budget--) { s->failed_pc=0x0c0c4e58u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c0c4e5a;
P_0c0c4e5a: /* original c740, guest PC 0x0c0c4e5a */
if(!s->budget--) { s->failed_pc=0x0c0c4e5au; return 0; }
r[0]=code_base|0x000c4f5cu;
goto P_0c0c4e5c;
P_0c0c4e5c: /* original 69f2, guest PC 0x0c0c4e5c */
if(!s->budget--) { s->failed_pc=0x0c0c4e5cu; return 0; }
tmp=read(ram,r[15],4);
r[9]=tmp;
goto P_0c0c4e5e;
P_0c0c4e5e: /* original 9b72, guest PC 0x0c0c4e5e */
if(!s->budget--) { s->failed_pc=0x0c0c4e5eu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f46u,2);
goto P_0c0c4e60;
P_0c0c4e60: /* original dc3f, guest PC 0x0c0c4e60 */
if(!s->budget--) { s->failed_pc=0x0c0c4e60u; return 0; }
r[12]=read(ram,0x0c0c4f60u,4);
goto P_0c0c4e62;
P_0c0c4e62: /* original 7904, guest PC 0x0c0c4e62 */
if(!s->budget--) { s->failed_pc=0x0c0c4e62u; return 0; }
r[9]+=0x00000004u;
goto P_0c0c4e64;
P_0c0c4e64: /* original ff08, guest PC 0x0c0c4e64 */
if(!s->budget--) { s->failed_pc=0x0c0c4e64u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0c4e66;
P_0c0c4e66: /* original 85f2, guest PC 0x0c0c4e66 */
if(!s->budget--) { s->failed_pc=0x0c0c4e66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c0c4e68;
P_0c0c4e68: /* original 3d8c, guest PC 0x0c0c4e68 */
if(!s->budget--) { s->failed_pc=0x0c0c4e68u; return 0; }
r[13]+=r[8];
goto P_0c0c4e6a;
P_0c0c4e6a: /* original 3e0c, guest PC 0x0c0c4e6a */
if(!s->budget--) { s->failed_pc=0x0c0c4e6au; return 0; }
r[14]+=r[0];
goto P_0c0c4e6c;
P_0c0c4e6c: /* original 4c0b, guest PC 0x0c0c4e6c */
if(!s->budget--) { s->failed_pc=0x0c0c4e6cu; return 0; }
target=r[12];
r[16]=code_base|0x0c0c4e70u;
r[4]=(uint32_t)(int32_t)(int16_t)r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4e70u) { target=s->pc; goto dispatch; }
goto P_0c0c4e70;
P_0c0c4e6e: /* original 64ef, guest PC 0x0c0c4e6e */
if(!s->budget--) { s->failed_pc=0x0c0c4e6eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c0c4e70;
P_0c0c4e70: /* original f4fc, guest PC 0x0c0c4e70 */
if(!s->budget--) { s->failed_pc=0x0c0c4e70u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0c4e72;
P_0c0c4e72: /* original 6add, guest PC 0x0c0c4e72 */
if(!s->budget--) { s->failed_pc=0x0c0c4e72u; return 0; }
r[10]=r[13]&65535u;
goto P_0c0c4e74;
P_0c0c4e74: /* original f30c, guest PC 0x0c0c4e74 */
if(!s->budget--) { s->failed_pc=0x0c0c4e74u; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0c4e76;
P_0c0c4e76: /* original f432, guest PC 0x0c0c4e76 */
if(!s->budget--) { s->failed_pc=0x0c0c4e76u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0c4e78;
P_0c0c4e78: /* original f43d, guest PC 0x0c0c4e78 */
if(!s->budget--) { s->failed_pc=0x0c0c4e78u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0c4e7a;
P_0c0c4e7a: /* original 045a, guest PC 0x0c0c4e7a */
if(!s->budget--) { s->failed_pc=0x0c0c4e7au; return 0; }
r[4]=r[53];
goto P_0c0c4e7c;
P_0c0c4e7c: /* original 3a4c, guest PC 0x0c0c4e7c */
if(!s->budget--) { s->failed_pc=0x0c0c4e7cu; return 0; }
r[10]+=r[4];
goto P_0c0c4e7e;
P_0c0c4e7e: /* original 4c0b, guest PC 0x0c0c4e7e */
if(!s->budget--) { s->failed_pc=0x0c0c4e7eu; return 0; }
target=r[12];
r[16]=code_base|0x0c0c4e82u;
r[4]=(uint32_t)(int32_t)(int16_t)r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4e82u) { target=s->pc; goto dispatch; }
goto P_0c0c4e82;
P_0c0c4e80: /* original 64af, guest PC 0x0c0c4e80 */
if(!s->budget--) { s->failed_pc=0x0c0c4e80u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[10];
goto P_0c0c4e82;
P_0c0c4e82: /* original f4ec, guest PC 0x0c0c4e82 */
if(!s->budget--) { s->failed_pc=0x0c0c4e82u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0c4e84;
P_0c0c4e84: /* original 4b10, guest PC 0x0c0c4e84 */
if(!s->budget--) { s->failed_pc=0x0c0c4e84u; return 0; }
--r[11];
r[17]=(r[17]&~1u)|((r[11]==0)!=0);
goto P_0c0c4e86;
P_0c0c4e86: /* original f30c, guest PC 0x0c0c4e86 */
if(!s->budget--) { s->failed_pc=0x0c0c4e86u; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0c4e88;
P_0c0c4e88: /* original f432, guest PC 0x0c0c4e88 */
if(!s->budget--) { s->failed_pc=0x0c0c4e88u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0c4e8a;
P_0c0c4e8a: /* original 7904, guest PC 0x0c0c4e8a */
if(!s->budget--) { s->failed_pc=0x0c0c4e8au; return 0; }
r[9]+=0x00000004u;
goto P_0c0c4e8c;
P_0c0c4e8c: /* original 8feb, guest PC 0x0c0c4e8c */
if(!s->budget--) { s->failed_pc=0x0c0c4e8cu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,4,r[9]);
if(!cond) { goto P_0c0c4e66; }
goto P_0c0c4e90;
P_0c0c4e8e: /* original f94a, guest PC 0x0c0c4e8e */
if(!s->budget--) { s->failed_pc=0x0c0c4e8eu; return 0; }
vf3_matrix_store(s,ram,4,r[9]);
goto P_0c0c4e90;
P_0c0c4e90: /* original 62f2, guest PC 0x0c0c4e90 */
if(!s->budget--) { s->failed_pc=0x0c0c4e90u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c4e92;
P_0c0c4e92: /* original 7f08, guest PC 0x0c0c4e92 */
if(!s->budget--) { s->failed_pc=0x0c0c4e92u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c4e94;
P_0c0c4e94: /* original 4f26, guest PC 0x0c0c4e94 */
if(!s->budget--) { s->failed_pc=0x0c0c4e94u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c4e96;
P_0c0c4e96: /* original 9057, guest PC 0x0c0c4e96 */
if(!s->budget--) { s->failed_pc=0x0c0c4e96u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f48u,2);
goto P_0c0c4e98;
P_0c0c4e98: /* original e300, guest PC 0x0c0c4e98 */
if(!s->budget--) { s->failed_pc=0x0c0c4e98u; return 0; }
r[3]=0x00000000u;
goto P_0c0c4e9a;
P_0c0c4e9a: /* original 0236, guest PC 0x0c0c4e9a */
if(!s->budget--) { s->failed_pc=0x0c0c4e9au; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0c4e9c;
P_0c0c4e9c: /* original fef9, guest PC 0x0c0c4e9c */
if(!s->budget--) { s->failed_pc=0x0c0c4e9cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c4e9e;
P_0c0c4e9e: /* original fff9, guest PC 0x0c0c4e9e */
if(!s->budget--) { s->failed_pc=0x0c0c4e9eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c4ea0;
P_0c0c4ea0: /* original 68f6, guest PC 0x0c0c4ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c4ea2;
P_0c0c4ea2: /* original 69f6, guest PC 0x0c0c4ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c4ea4;
P_0c0c4ea4: /* original 6af6, guest PC 0x0c0c4ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c4ea6;
P_0c0c4ea6: /* original 6bf6, guest PC 0x0c0c4ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c4ea8;
P_0c0c4ea8: /* original 6cf6, guest PC 0x0c0c4ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c4eaa;
P_0c0c4eaa: /* original 6df6, guest PC 0x0c0c4eaa */
if(!s->budget--) { s->failed_pc=0x0c0c4eaau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c4eac;
P_0c0c4eac: /* original 000b, guest PC 0x0c0c4eac */
if(!s->budget--) { s->failed_pc=0x0c0c4eacu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c4eae: /* original 6ef6, guest PC 0x0c0c4eae */
if(!s->budget--) { s->failed_pc=0x0c0c4eaeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c4eb0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c4eb0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
