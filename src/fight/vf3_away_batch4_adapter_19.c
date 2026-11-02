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
int vf3_away_batch4_adapter_19(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04e712u: goto P_0c04e712;
case 0x0c04e714u: goto P_0c04e714;
case 0x0c04e716u: goto P_0c04e716;
case 0x0c04e718u: goto P_0c04e718;
case 0x0c04e71au: goto P_0c04e71a;
case 0x0c04e71cu: goto P_0c04e71c;
case 0x0c04e71eu: goto P_0c04e71e;
case 0x0c04e720u: goto P_0c04e720;
case 0x0c04e722u: goto P_0c04e722;
case 0x0c04e724u: goto P_0c04e724;
case 0x0c04e726u: goto P_0c04e726;
case 0x0c04e728u: goto P_0c04e728;
case 0x0c04e72au: goto P_0c04e72a;
case 0x0c04e72cu: goto P_0c04e72c;
case 0x0c04e72eu: goto P_0c04e72e;
case 0x0c04e730u: goto P_0c04e730;
case 0x0c04e732u: goto P_0c04e732;
case 0x0c04e734u: goto P_0c04e734;
case 0x0c04e736u: goto P_0c04e736;
case 0x0c04e738u: goto P_0c04e738;
case 0x0c04e73au: goto P_0c04e73a;
case 0x0c04e73cu: goto P_0c04e73c;
case 0x0c04e73eu: goto P_0c04e73e;
case 0x0c04e740u: goto P_0c04e740;
case 0x0c04e742u: goto P_0c04e742;
case 0x0c04e744u: goto P_0c04e744;
case 0x0c04e746u: goto P_0c04e746;
case 0x0c04e748u: goto P_0c04e748;
case 0x0c04e74au: goto P_0c04e74a;
case 0x0c04e74cu: goto P_0c04e74c;
case 0x0c04e74eu: goto P_0c04e74e;
case 0x0c04e750u: goto P_0c04e750;
case 0x0c04e752u: goto P_0c04e752;
case 0x0c04e754u: goto P_0c04e754;
case 0x0c04e756u: goto P_0c04e756;
case 0x0c04e758u: goto P_0c04e758;
case 0x0c04e75au: goto P_0c04e75a;
case 0x0c04e75cu: goto P_0c04e75c;
case 0x0c04e75eu: goto P_0c04e75e;
case 0x0c04e760u: goto P_0c04e760;
case 0x0c04e762u: goto P_0c04e762;
case 0x0c04e764u: goto P_0c04e764;
case 0x0c04e766u: goto P_0c04e766;
case 0x0c04e768u: goto P_0c04e768;
case 0x0c04e76au: goto P_0c04e76a;
case 0x0c04e76cu: goto P_0c04e76c;
case 0x0c04e76eu: goto P_0c04e76e;
case 0x0c04e770u: goto P_0c04e770;
case 0x0c04e772u: goto P_0c04e772;
case 0x0c04e774u: goto P_0c04e774;
case 0x0c04e776u: goto P_0c04e776;
case 0x0c04e778u: goto P_0c04e778;
case 0x0c04e77au: goto P_0c04e77a;
case 0x0c04e77cu: goto P_0c04e77c;
case 0x0c04e77eu: goto P_0c04e77e;
case 0x0c04e780u: goto P_0c04e780;
case 0x0c04e782u: goto P_0c04e782;
case 0x0c04e784u: goto P_0c04e784;
case 0x0c04e786u: goto P_0c04e786;
case 0x0c04e788u: goto P_0c04e788;
case 0x0c04e78au: goto P_0c04e78a;
case 0x0c04e78cu: goto P_0c04e78c;
case 0x0c04e78eu: goto P_0c04e78e;
case 0x0c04e790u: goto P_0c04e790;
case 0x0c04e792u: goto P_0c04e792;
case 0x0c04e794u: goto P_0c04e794;
case 0x0c04e796u: goto P_0c04e796;
case 0x0c04e798u: goto P_0c04e798;
case 0x0c04e79au: goto P_0c04e79a;
case 0x0c04e79cu: goto P_0c04e79c;
case 0x0c04e79eu: goto P_0c04e79e;
case 0x0c04e7a0u: goto P_0c04e7a0;
case 0x0c04e7a2u: goto P_0c04e7a2;
case 0x0c04e7a4u: goto P_0c04e7a4;
case 0x0c04e7a6u: goto P_0c04e7a6;
case 0x0c04e7a8u: goto P_0c04e7a8;
case 0x0c04e7aau: goto P_0c04e7aa;
case 0x0c04e7acu: goto P_0c04e7ac;
case 0x0c04f620u: goto P_0c04f620;
case 0x0c04f622u: goto P_0c04f622;
case 0x0c04f624u: goto P_0c04f624;
case 0x0c04f626u: goto P_0c04f626;
case 0x0c04f628u: goto P_0c04f628;
case 0x0c04f62au: goto P_0c04f62a;
case 0x0c04f62cu: goto P_0c04f62c;
case 0x0c04f62eu: goto P_0c04f62e;
case 0x0c04f630u: goto P_0c04f630;
case 0x0c04f632u: goto P_0c04f632;
case 0x0c04f634u: goto P_0c04f634;
case 0x0c04f636u: goto P_0c04f636;
case 0x0c04f638u: goto P_0c04f638;
case 0x0c04f63au: goto P_0c04f63a;
case 0x0c04f63cu: goto P_0c04f63c;
case 0x0c04f63eu: goto P_0c04f63e;
case 0x0c04f640u: goto P_0c04f640;
case 0x0c04f642u: goto P_0c04f642;
case 0x0c04f644u: goto P_0c04f644;
case 0x0c04f646u: goto P_0c04f646;
case 0x0c04f648u: goto P_0c04f648;
case 0x0c04f64au: goto P_0c04f64a;
case 0x0c04f64cu: goto P_0c04f64c;
case 0x0c04f64eu: goto P_0c04f64e;
case 0x0c04f650u: goto P_0c04f650;
case 0x0c04f652u: goto P_0c04f652;
case 0x0c04f654u: goto P_0c04f654;
case 0x0c04f656u: goto P_0c04f656;
case 0x0c04f658u: goto P_0c04f658;
case 0x0c04f65au: goto P_0c04f65a;
case 0x0c04f65cu: goto P_0c04f65c;
case 0x0c04f65eu: goto P_0c04f65e;
case 0x0c04f660u: goto P_0c04f660;
case 0x0c04f662u: goto P_0c04f662;
case 0x0c04f664u: goto P_0c04f664;
case 0x0c04f666u: goto P_0c04f666;
case 0x0c04f668u: goto P_0c04f668;
case 0x0c04f66au: goto P_0c04f66a;
case 0x0c04f66cu: goto P_0c04f66c;
case 0x0c04f66eu: goto P_0c04f66e;
case 0x0c04f670u: goto P_0c04f670;
case 0x0c04f672u: goto P_0c04f672;
case 0x0c04f674u: goto P_0c04f674;
case 0x0c04f676u: goto P_0c04f676;
case 0x0c04f678u: goto P_0c04f678;
case 0x0c04f67au: goto P_0c04f67a;
case 0x0c04f67cu: goto P_0c04f67c;
case 0x0c04f67eu: goto P_0c04f67e;
case 0x0c04f680u: goto P_0c04f680;
case 0x0c04f682u: goto P_0c04f682;
case 0x0c04f684u: goto P_0c04f684;
case 0x0c04f686u: goto P_0c04f686;
case 0x0c04f688u: goto P_0c04f688;
case 0x0c04f68au: goto P_0c04f68a;
case 0x0c04f68cu: goto P_0c04f68c;
case 0x0c04f68eu: goto P_0c04f68e;
case 0x0c04f690u: goto P_0c04f690;
case 0x0c04f692u: goto P_0c04f692;
case 0x0c04f694u: goto P_0c04f694;
case 0x0c04f696u: goto P_0c04f696;
case 0x0c04f698u: goto P_0c04f698;
case 0x0c04f69au: goto P_0c04f69a;
case 0x0c04f69cu: goto P_0c04f69c;
case 0x0c04f69eu: goto P_0c04f69e;
case 0x0c04f6a0u: goto P_0c04f6a0;
case 0x0c04f6a2u: goto P_0c04f6a2;
case 0x0c04f6a4u: goto P_0c04f6a4;
case 0x0c04f6a6u: goto P_0c04f6a6;
case 0x0c04f6a8u: goto P_0c04f6a8;
case 0x0c04f6aau: goto P_0c04f6aa;
case 0x0c04f6acu: goto P_0c04f6ac;
case 0x0c04f6aeu: goto P_0c04f6ae;
case 0x0c04f6b0u: goto P_0c04f6b0;
case 0x0c04f6b2u: goto P_0c04f6b2;
case 0x0c04f6b4u: goto P_0c04f6b4;
case 0x0c04f6b6u: goto P_0c04f6b6;
case 0x0c04f6b8u: goto P_0c04f6b8;
case 0x0c04f6bau: goto P_0c04f6ba;
case 0x0c04f6bcu: goto P_0c04f6bc;
case 0x0c04f6beu: goto P_0c04f6be;
case 0x0c04f6c0u: goto P_0c04f6c0;
case 0x0c04f6c2u: goto P_0c04f6c2;
case 0x0c04f6c4u: goto P_0c04f6c4;
case 0x0c04f6e0u: goto P_0c04f6e0;
case 0x0c04f6e2u: goto P_0c04f6e2;
case 0x0c04f6e4u: goto P_0c04f6e4;
case 0x0c04f6e6u: goto P_0c04f6e6;
case 0x0c04f6e8u: goto P_0c04f6e8;
case 0x0c04f6eau: goto P_0c04f6ea;
case 0x0c04f6ecu: goto P_0c04f6ec;
case 0x0c04f6eeu: goto P_0c04f6ee;
case 0x0c04f6f0u: goto P_0c04f6f0;
case 0x0c04f6f2u: goto P_0c04f6f2;
case 0x0c04f6f4u: goto P_0c04f6f4;
case 0x0c04f6f6u: goto P_0c04f6f6;
case 0x0c04f6f8u: goto P_0c04f6f8;
case 0x0c04f6fau: goto P_0c04f6fa;
case 0x0c04f6fcu: goto P_0c04f6fc;
case 0x0c04f6feu: goto P_0c04f6fe;
case 0x0c04f700u: goto P_0c04f700;
case 0x0c04f702u: goto P_0c04f702;
case 0x0c04f704u: goto P_0c04f704;
case 0x0c04f706u: goto P_0c04f706;
case 0x0c04f708u: goto P_0c04f708;
case 0x0c04f70au: goto P_0c04f70a;
case 0x0c04f70cu: goto P_0c04f70c;
case 0x0c04f70eu: goto P_0c04f70e;
case 0x0c04f710u: goto P_0c04f710;
case 0x0c04f712u: goto P_0c04f712;
case 0x0c04f714u: goto P_0c04f714;
case 0x0c04f716u: goto P_0c04f716;
case 0x0c04f718u: goto P_0c04f718;
case 0x0c04f71au: goto P_0c04f71a;
case 0x0c04f71cu: goto P_0c04f71c;
case 0x0c04f71eu: goto P_0c04f71e;
case 0x0c04f720u: goto P_0c04f720;
case 0x0c04f722u: goto P_0c04f722;
case 0x0c04f724u: goto P_0c04f724;
case 0x0c04f726u: goto P_0c04f726;
case 0x0c04f728u: goto P_0c04f728;
case 0x0c04f72au: goto P_0c04f72a;
case 0x0c04f72cu: goto P_0c04f72c;
case 0x0c04f72eu: goto P_0c04f72e;
case 0x0c04f730u: goto P_0c04f730;
case 0x0c04f732u: goto P_0c04f732;
case 0x0c04f734u: goto P_0c04f734;
case 0x0c04f736u: goto P_0c04f736;
case 0x0c04f738u: goto P_0c04f738;
case 0x0c04f73au: goto P_0c04f73a;
case 0x0c04f73cu: goto P_0c04f73c;
case 0x0c04f73eu: goto P_0c04f73e;
case 0x0c04f740u: goto P_0c04f740;
case 0x0c04f742u: goto P_0c04f742;
case 0x0c04f744u: goto P_0c04f744;
case 0x0c04f746u: goto P_0c04f746;
case 0x0c04f748u: goto P_0c04f748;
case 0x0c04f74au: goto P_0c04f74a;
case 0x0c04f74cu: goto P_0c04f74c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04e712: /* original 2fe6, guest PC 0x0c04e712 */
if(!s->budget--) { s->failed_pc=0x0c04e712u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e714;
P_0c04e714: /* original 6e43, guest PC 0x0c04e714 */
if(!s->budget--) { s->failed_pc=0x0c04e714u; return 0; }
r[14]=r[4];
goto P_0c04e716;
P_0c04e716: /* original 2fd6, guest PC 0x0c04e716 */
if(!s->budget--) { s->failed_pc=0x0c04e716u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e718;
P_0c04e718: /* original 6d53, guest PC 0x0c04e718 */
if(!s->budget--) { s->failed_pc=0x0c04e718u; return 0; }
r[13]=r[5];
goto P_0c04e71a;
P_0c04e71a: /* original 2fc6, guest PC 0x0c04e71a */
if(!s->budget--) { s->failed_pc=0x0c04e71au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e71c;
P_0c04e71c: /* original 2fb6, guest PC 0x0c04e71c */
if(!s->budget--) { s->failed_pc=0x0c04e71cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e71e;
P_0c04e71e: /* original 2fa6, guest PC 0x0c04e71e */
if(!s->budget--) { s->failed_pc=0x0c04e71eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e720;
P_0c04e720: /* original 2f96, guest PC 0x0c04e720 */
if(!s->budget--) { s->failed_pc=0x0c04e720u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e722;
P_0c04e722: /* original 4f22, guest PC 0x0c04e722 */
if(!s->budget--) { s->failed_pc=0x0c04e722u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04e724;
P_0c04e724: /* original 7fd0, guest PC 0x0c04e724 */
if(!s->budget--) { s->failed_pc=0x0c04e724u; return 0; }
r[15]+=0xffffffd0u;
goto P_0c04e726;
P_0c04e726: /* original 2f56, guest PC 0x0c04e726 */
if(!s->budget--) { s->failed_pc=0x0c04e726u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e728;
P_0c04e728: /* original 2fe6, guest PC 0x0c04e728 */
if(!s->budget--) { s->failed_pc=0x0c04e728u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e72a;
P_0c04e72a: /* original d322, guest PC 0x0c04e72a */
if(!s->budget--) { s->failed_pc=0x0c04e72au; return 0; }
r[3]=read(ram,0x0c04e7b4u,4);
goto P_0c04e72c;
P_0c04e72c: /* original d222, guest PC 0x0c04e72c */
if(!s->budget--) { s->failed_pc=0x0c04e72cu; return 0; }
r[2]=read(ram,0x0c04e7b8u,4);
goto P_0c04e72e;
P_0c04e72e: /* original 420b, guest PC 0x0c04e72e */
if(!s->budget--) { s->failed_pc=0x0c04e72eu; return 0; }
target=r[2];
r[16]=code_base|0x0c04e732u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e732u) { target=s->pc; goto dispatch; }
goto P_0c04e732;
P_0c04e730: /* original 2f36, guest PC 0x0c04e730 */
if(!s->budget--) { s->failed_pc=0x0c04e730u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e732;
P_0c04e732: /* original 7f0c, guest PC 0x0c04e732 */
if(!s->budget--) { s->failed_pc=0x0c04e732u; return 0; }
r[15]+=0x0000000cu;
goto P_0c04e734;
P_0c04e734: /* original d321, guest PC 0x0c04e734 */
if(!s->budget--) { s->failed_pc=0x0c04e734u; return 0; }
r[3]=read(ram,0x0c04e7bcu,4);
goto P_0c04e736;
P_0c04e736: /* original 66f3, guest PC 0x0c04e736 */
if(!s->budget--) { s->failed_pc=0x0c04e736u; return 0; }
r[6]=r[15];
goto P_0c04e738;
P_0c04e738: /* original 65d3, guest PC 0x0c04e738 */
if(!s->budget--) { s->failed_pc=0x0c04e738u; return 0; }
r[5]=r[13];
goto P_0c04e73a;
P_0c04e73a: /* original 7604, guest PC 0x0c04e73a */
if(!s->budget--) { s->failed_pc=0x0c04e73au; return 0; }
r[6]+=0x00000004u;
goto P_0c04e73c;
P_0c04e73c: /* original 430b, guest PC 0x0c04e73c */
if(!s->budget--) { s->failed_pc=0x0c04e73cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04e740u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e740u) { target=s->pc; goto dispatch; }
goto P_0c04e740;
P_0c04e73e: /* original 64e3, guest PC 0x0c04e73e */
if(!s->budget--) { s->failed_pc=0x0c04e73eu; return 0; }
r[4]=r[14];
goto P_0c04e740;
P_0c04e740: /* original 6c03, guest PC 0x0c04e740 */
if(!s->budget--) { s->failed_pc=0x0c04e740u; return 0; }
r[12]=r[0];
goto P_0c04e742;
P_0c04e742: /* original 4c11, guest PC 0x0c04e742 */
if(!s->budget--) { s->failed_pc=0x0c04e742u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=0)!=0);
goto P_0c04e744;
P_0c04e744: /* original 8902, guest PC 0x0c04e744 */
if(!s->budget--) { s->failed_pc=0x0c04e744u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e74c; }
goto P_0c04e746;
P_0c04e746: /* original 9033, guest PC 0x0c04e746 */
if(!s->budget--) { s->failed_pc=0x0c04e746u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e7b0u,2);
goto P_0c04e748;
P_0c04e748: /* original a028, guest PC 0x0c04e748 */
if(!s->budget--) { s->failed_pc=0x0c04e748u; return 0; }
goto P_0c04e79c;
P_0c04e74a: /* original 0009, guest PC 0x0c04e74a */
if(!s->budget--) { s->failed_pc=0x0c04e74au; return 0; }
goto P_0c04e74c;
P_0c04e74c: /* original d31c, guest PC 0x0c04e74c */
if(!s->budget--) { s->failed_pc=0x0c04e74cu; return 0; }
r[3]=read(ram,0x0c04e7c0u,4);
goto P_0c04e74e;
P_0c04e74e: /* original 65c3, guest PC 0x0c04e74e */
if(!s->budget--) { s->failed_pc=0x0c04e74eu; return 0; }
r[5]=r[12];
goto P_0c04e750;
P_0c04e750: /* original 430b, guest PC 0x0c04e750 */
if(!s->budget--) { s->failed_pc=0x0c04e750u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e754u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e754u) { target=s->pc; goto dispatch; }
goto P_0c04e754;
P_0c04e752: /* original 64e3, guest PC 0x0c04e752 */
if(!s->budget--) { s->failed_pc=0x0c04e752u; return 0; }
r[4]=r[14];
goto P_0c04e754;
P_0c04e754: /* original 65d3, guest PC 0x0c04e754 */
if(!s->budget--) { s->failed_pc=0x0c04e754u; return 0; }
r[5]=r[13];
goto P_0c04e756;
P_0c04e756: /* original 2f02, guest PC 0x0c04e756 */
if(!s->budget--) { s->failed_pc=0x0c04e756u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c04e758;
P_0c04e758: /* original d31a, guest PC 0x0c04e758 */
if(!s->budget--) { s->failed_pc=0x0c04e758u; return 0; }
r[3]=read(ram,0x0c04e7c4u,4);
goto P_0c04e75a;
P_0c04e75a: /* original 430b, guest PC 0x0c04e75a */
if(!s->budget--) { s->failed_pc=0x0c04e75au; return 0; }
target=r[3];
r[16]=code_base|0x0c04e75eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e75eu) { target=s->pc; goto dispatch; }
goto P_0c04e75e;
P_0c04e75c: /* original 64e3, guest PC 0x0c04e75c */
if(!s->budget--) { s->failed_pc=0x0c04e75cu; return 0; }
r[4]=r[14];
goto P_0c04e75e;
P_0c04e75e: /* original 2008, guest PC 0x0c04e75e */
if(!s->budget--) { s->failed_pc=0x0c04e75eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e760;
P_0c04e760: /* original 8b12, guest PC 0x0c04e760 */
if(!s->budget--) { s->failed_pc=0x0c04e760u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e788; }
goto P_0c04e762;
P_0c04e762: /* original da19, guest PC 0x0c04e762 */
if(!s->budget--) { s->failed_pc=0x0c04e762u; return 0; }
r[10]=read(ram,0x0c04e7c8u,4);
goto P_0c04e764;
P_0c04e764: /* original 5df4, guest PC 0x0c04e764 */
if(!s->budget--) { s->failed_pc=0x0c04e764u; return 0; }
r[13]=read(ram,r[15]+16,4);
goto P_0c04e766;
P_0c04e766: /* original a00c, guest PC 0x0c04e766 */
if(!s->budget--) { s->failed_pc=0x0c04e766u; return 0; }
r[11]=0x00000000u;
goto P_0c04e782;
P_0c04e768: /* original eb00, guest PC 0x0c04e768 */
if(!s->budget--) { s->failed_pc=0x0c04e768u; return 0; }
r[11]=0x00000000u;
goto P_0c04e76a;
P_0c04e76a: /* original d218, guest PC 0x0c04e76a */
if(!s->budget--) { s->failed_pc=0x0c04e76au; return 0; }
r[2]=read(ram,0x0c04e7ccu,4);
goto P_0c04e76c;
P_0c04e76c: /* original 65d3, guest PC 0x0c04e76c */
if(!s->budget--) { s->failed_pc=0x0c04e76cu; return 0; }
r[5]=r[13];
goto P_0c04e76e;
P_0c04e76e: /* original 420b, guest PC 0x0c04e76e */
if(!s->budget--) { s->failed_pc=0x0c04e76eu; return 0; }
target=r[2];
r[16]=code_base|0x0c04e772u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e772u) { target=s->pc; goto dispatch; }
goto P_0c04e772;
P_0c04e770: /* original 64e3, guest PC 0x0c04e770 */
if(!s->budget--) { s->failed_pc=0x0c04e770u; return 0; }
r[4]=r[14];
goto P_0c04e772;
P_0c04e772: /* original d317, guest PC 0x0c04e772 */
if(!s->budget--) { s->failed_pc=0x0c04e772u; return 0; }
r[3]=read(ram,0x0c04e7d0u,4);
goto P_0c04e774;
P_0c04e774: /* original 65d3, guest PC 0x0c04e774 */
if(!s->budget--) { s->failed_pc=0x0c04e774u; return 0; }
r[5]=r[13];
goto P_0c04e776;
P_0c04e776: /* original 690d, guest PC 0x0c04e776 */
if(!s->budget--) { s->failed_pc=0x0c04e776u; return 0; }
r[9]=r[0]&65535u;
goto P_0c04e778;
P_0c04e778: /* original 66a3, guest PC 0x0c04e778 */
if(!s->budget--) { s->failed_pc=0x0c04e778u; return 0; }
r[6]=r[10];
goto P_0c04e77a;
P_0c04e77a: /* original 430b, guest PC 0x0c04e77a */
if(!s->budget--) { s->failed_pc=0x0c04e77au; return 0; }
target=r[3];
r[16]=code_base|0x0c04e77eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e77eu) { target=s->pc; goto dispatch; }
goto P_0c04e77e;
P_0c04e77c: /* original 64e3, guest PC 0x0c04e77c */
if(!s->budget--) { s->failed_pc=0x0c04e77cu; return 0; }
r[4]=r[14];
goto P_0c04e77e;
P_0c04e77e: /* original 7b01, guest PC 0x0c04e77e */
if(!s->budget--) { s->failed_pc=0x0c04e77eu; return 0; }
r[11]+=0x00000001u;
goto P_0c04e780;
P_0c04e780: /* original 6d93, guest PC 0x0c04e780 */
if(!s->budget--) { s->failed_pc=0x0c04e780u; return 0; }
r[13]=r[9];
goto P_0c04e782;
P_0c04e782: /* original 52fb, guest PC 0x0c04e782 */
if(!s->budget--) { s->failed_pc=0x0c04e782u; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c04e784;
P_0c04e784: /* original 3b23, guest PC 0x0c04e784 */
if(!s->budget--) { s->failed_pc=0x0c04e784u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[2])!=0);
goto P_0c04e786;
P_0c04e786: /* original 8bf0, guest PC 0x0c04e786 */
if(!s->budget--) { s->failed_pc=0x0c04e786u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e76a; }
goto P_0c04e788;
P_0c04e788: /* original d312, guest PC 0x0c04e788 */
if(!s->budget--) { s->failed_pc=0x0c04e788u; return 0; }
r[3]=read(ram,0x0c04e7d4u,4);
goto P_0c04e78a;
P_0c04e78a: /* original e500, guest PC 0x0c04e78a */
if(!s->budget--) { s->failed_pc=0x0c04e78au; return 0; }
r[5]=0x00000000u;
goto P_0c04e78c;
P_0c04e78c: /* original e620, guest PC 0x0c04e78c */
if(!s->budget--) { s->failed_pc=0x0c04e78cu; return 0; }
r[6]=0x00000020u;
goto P_0c04e78e;
P_0c04e78e: /* original 430b, guest PC 0x0c04e78e */
if(!s->budget--) { s->failed_pc=0x0c04e78eu; return 0; }
target=r[3];
r[16]=code_base|0x0c04e792u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e792u) { target=s->pc; goto dispatch; }
goto P_0c04e792;
P_0c04e790: /* original 64f2, guest PC 0x0c04e790 */
if(!s->budget--) { s->failed_pc=0x0c04e790u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c04e792;
P_0c04e792: /* original d211, guest PC 0x0c04e792 */
if(!s->budget--) { s->failed_pc=0x0c04e792u; return 0; }
r[2]=read(ram,0x0c04e7d8u,4);
goto P_0c04e794;
P_0c04e794: /* original 65c3, guest PC 0x0c04e794 */
if(!s->budget--) { s->failed_pc=0x0c04e794u; return 0; }
r[5]=r[12];
goto P_0c04e796;
P_0c04e796: /* original 420b, guest PC 0x0c04e796 */
if(!s->budget--) { s->failed_pc=0x0c04e796u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e79au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e79au) { target=s->pc; goto dispatch; }
goto P_0c04e79a;
P_0c04e798: /* original 64e3, guest PC 0x0c04e798 */
if(!s->budget--) { s->failed_pc=0x0c04e798u; return 0; }
r[4]=r[14];
goto P_0c04e79a;
P_0c04e79a: /* original e000, guest PC 0x0c04e79a */
if(!s->budget--) { s->failed_pc=0x0c04e79au; return 0; }
r[0]=0x00000000u;
goto P_0c04e79c;
P_0c04e79c: /* original 7f30, guest PC 0x0c04e79c */
if(!s->budget--) { s->failed_pc=0x0c04e79cu; return 0; }
r[15]+=0x00000030u;
goto P_0c04e79e;
P_0c04e79e: /* original 4f26, guest PC 0x0c04e79e */
if(!s->budget--) { s->failed_pc=0x0c04e79eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e7a0;
P_0c04e7a0: /* original 69f6, guest PC 0x0c04e7a0 */
if(!s->budget--) { s->failed_pc=0x0c04e7a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04e7a2;
P_0c04e7a2: /* original 6af6, guest PC 0x0c04e7a2 */
if(!s->budget--) { s->failed_pc=0x0c04e7a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04e7a4;
P_0c04e7a4: /* original 6bf6, guest PC 0x0c04e7a4 */
if(!s->budget--) { s->failed_pc=0x0c04e7a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04e7a6;
P_0c04e7a6: /* original 6cf6, guest PC 0x0c04e7a6 */
if(!s->budget--) { s->failed_pc=0x0c04e7a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04e7a8;
P_0c04e7a8: /* original 6df6, guest PC 0x0c04e7a8 */
if(!s->budget--) { s->failed_pc=0x0c04e7a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04e7aa;
P_0c04e7aa: /* original 000b, guest PC 0x0c04e7aa */
if(!s->budget--) { s->failed_pc=0x0c04e7aau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04e7ac: /* original 6ef6, guest PC 0x0c04e7ac */
if(!s->budget--) { s->failed_pc=0x0c04e7acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04e7aeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04e7aeu; return 0; } return 1;
P_0c04f620: /* original 2fe6, guest PC 0x0c04f620 */
if(!s->budget--) { s->failed_pc=0x0c04f620u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f622;
P_0c04f622: /* original 6e43, guest PC 0x0c04f622 */
if(!s->budget--) { s->failed_pc=0x0c04f622u; return 0; }
r[14]=r[4];
goto P_0c04f624;
P_0c04f624: /* original 2fd6, guest PC 0x0c04f624 */
if(!s->budget--) { s->failed_pc=0x0c04f624u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f626;
P_0c04f626: /* original 2fc6, guest PC 0x0c04f626 */
if(!s->budget--) { s->failed_pc=0x0c04f626u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f628;
P_0c04f628: /* original 2fb6, guest PC 0x0c04f628 */
if(!s->budget--) { s->failed_pc=0x0c04f628u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f62a;
P_0c04f62a: /* original eb00, guest PC 0x0c04f62a */
if(!s->budget--) { s->failed_pc=0x0c04f62au; return 0; }
r[11]=0x00000000u;
goto P_0c04f62c;
P_0c04f62c: /* original 2fa6, guest PC 0x0c04f62c */
if(!s->budget--) { s->failed_pc=0x0c04f62cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f62e;
P_0c04f62e: /* original 2f96, guest PC 0x0c04f62e */
if(!s->budget--) { s->failed_pc=0x0c04f62eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f630;
P_0c04f630: /* original 2f86, guest PC 0x0c04f630 */
if(!s->budget--) { s->failed_pc=0x0c04f630u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f632;
P_0c04f632: /* original 4f22, guest PC 0x0c04f632 */
if(!s->budget--) { s->failed_pc=0x0c04f632u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f634;
P_0c04f634: /* original 9947, guest PC 0x0c04f634 */
if(!s->budget--) { s->failed_pc=0x0c04f634u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f6c6u,2);
goto P_0c04f636;
P_0c04f636: /* original d325, guest PC 0x0c04f636 */
if(!s->budget--) { s->failed_pc=0x0c04f636u; return 0; }
r[3]=read(ram,0x0c04f6ccu,4);
goto P_0c04f638;
P_0c04f638: /* original 4f12, guest PC 0x0c04f638 */
if(!s->budget--) { s->failed_pc=0x0c04f638u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04f63a;
P_0c04f63a: /* original 2e9f, guest PC 0x0c04f63a */
if(!s->budget--) { s->failed_pc=0x0c04f63au; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[9]);
goto P_0c04f63c;
P_0c04f63c: /* original 7ff0, guest PC 0x0c04f63c */
if(!s->budget--) { s->failed_pc=0x0c04f63cu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c04f63e;
P_0c04f63e: /* original 091a, guest PC 0x0c04f63e */
if(!s->budget--) { s->failed_pc=0x0c04f63eu; return 0; }
r[9]=r[19];
goto P_0c04f640;
P_0c04f640: /* original 699f, guest PC 0x0c04f640 */
if(!s->budget--) { s->failed_pc=0x0c04f640u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)r[9];
goto P_0c04f642;
P_0c04f642: /* original 393c, guest PC 0x0c04f642 */
if(!s->budget--) { s->failed_pc=0x0c04f642u; return 0; }
r[9]+=r[3];
goto P_0c04f644;
P_0c04f644: /* original 5497, guest PC 0x0c04f644 */
if(!s->budget--) { s->failed_pc=0x0c04f644u; return 0; }
r[4]=read(ram,r[9]+28,4);
goto P_0c04f646;
P_0c04f646: /* original 854a, guest PC 0x0c04f646 */
if(!s->budget--) { s->failed_pc=0x0c04f646u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+20,2);
goto P_0c04f648;
P_0c04f648: /* original 81f2, guest PC 0x0c04f648 */
if(!s->budget--) { s->failed_pc=0x0c04f648u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c04f64a;
P_0c04f64a: /* original da21, guest PC 0x0c04f64a */
if(!s->budget--) { s->failed_pc=0x0c04f64au; return 0; }
r[10]=read(ram,0x0c04f6d0u,4);
goto P_0c04f64c;
P_0c04f64c: /* original 85f2, guest PC 0x0c04f64c */
if(!s->budget--) { s->failed_pc=0x0c04f64cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c04f64e;
P_0c04f64e: /* original 5846, guest PC 0x0c04f64e */
if(!s->budget--) { s->failed_pc=0x0c04f64eu; return 0; }
r[8]=read(ram,r[4]+24,4);
goto P_0c04f650;
P_0c04f650: /* original 6da3, guest PC 0x0c04f650 */
if(!s->budget--) { s->failed_pc=0x0c04f650u; return 0; }
r[13]=r[10];
goto P_0c04f652;
P_0c04f652: /* original 6c03, guest PC 0x0c04f652 */
if(!s->budget--) { s->failed_pc=0x0c04f652u; return 0; }
r[12]=r[0];
goto P_0c04f654;
P_0c04f654: /* original 4815, guest PC 0x0c04f654 */
if(!s->budget--) { s->failed_pc=0x0c04f654u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>0)!=0);
goto P_0c04f656;
P_0c04f656: /* original 8f12, guest PC 0x0c04f656 */
if(!s->budget--) { s->failed_pc=0x0c04f656u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c04f67e; }
goto P_0c04f65a;
P_0c04f658: /* original 7d02, guest PC 0x0c04f658 */
if(!s->budget--) { s->failed_pc=0x0c04f658u; return 0; }
r[13]+=0x00000002u;
goto P_0c04f65a;
P_0c04f65a: /* original 65cd, guest PC 0x0c04f65a */
if(!s->budget--) { s->failed_pc=0x0c04f65au; return 0; }
r[5]=r[12]&65535u;
goto P_0c04f65c;
P_0c04f65c: /* original 2f52, guest PC 0x0c04f65c */
if(!s->budget--) { s->failed_pc=0x0c04f65cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c04f65e;
P_0c04f65e: /* original b41e, guest PC 0x0c04f65e */
if(!s->budget--) { s->failed_pc=0x0c04f65eu; return 0; }
target=code_base|0x0c04fe9eu; r[16]=code_base|0x0c04f662u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f662u) { target=s->pc; goto dispatch; }
goto P_0c04f662;
P_0c04f660: /* original 64e3, guest PC 0x0c04f660 */
if(!s->budget--) { s->failed_pc=0x0c04f660u; return 0; }
r[4]=r[14];
goto P_0c04f662;
P_0c04f662: /* original 65f2, guest PC 0x0c04f662 */
if(!s->budget--) { s->failed_pc=0x0c04f662u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04f664;
P_0c04f664: /* original 66d3, guest PC 0x0c04f664 */
if(!s->budget--) { s->failed_pc=0x0c04f664u; return 0; }
r[6]=r[13];
goto P_0c04f666;
P_0c04f666: /* original 6c03, guest PC 0x0c04f666 */
if(!s->budget--) { s->failed_pc=0x0c04f666u; return 0; }
r[12]=r[0];
goto P_0c04f668;
P_0c04f668: /* original b3ea, guest PC 0x0c04f668 */
if(!s->budget--) { s->failed_pc=0x0c04f668u; return 0; }
target=code_base|0x0c04fe40u; r[16]=code_base|0x0c04f66cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f66cu) { target=s->pc; goto dispatch; }
goto P_0c04f66c;
P_0c04f66a: /* original 64e3, guest PC 0x0c04f66a */
if(!s->budget--) { s->failed_pc=0x0c04f66au; return 0; }
r[4]=r[14];
goto P_0c04f66c;
P_0c04f66c: /* original 62cd, guest PC 0x0c04f66c */
if(!s->budget--) { s->failed_pc=0x0c04f66cu; return 0; }
r[2]=r[12]&65535u;
goto P_0c04f66e;
P_0c04f66e: /* original 32a0, guest PC 0x0c04f66e */
if(!s->budget--) { s->failed_pc=0x0c04f66eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[10])!=0);
goto P_0c04f670;
P_0c04f670: /* original 8905, guest PC 0x0c04f670 */
if(!s->budget--) { s->failed_pc=0x0c04f670u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f67e; }
goto P_0c04f672;
P_0c04f672: /* original 63cd, guest PC 0x0c04f672 */
if(!s->budget--) { s->failed_pc=0x0c04f672u; return 0; }
r[3]=r[12]&65535u;
goto P_0c04f674;
P_0c04f674: /* original 33d0, guest PC 0x0c04f674 */
if(!s->budget--) { s->failed_pc=0x0c04f674u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[13])!=0);
goto P_0c04f676;
P_0c04f676: /* original 8902, guest PC 0x0c04f676 */
if(!s->budget--) { s->failed_pc=0x0c04f676u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f67e; }
goto P_0c04f678;
P_0c04f678: /* original 7b01, guest PC 0x0c04f678 */
if(!s->budget--) { s->failed_pc=0x0c04f678u; return 0; }
r[11]+=0x00000001u;
goto P_0c04f67a;
P_0c04f67a: /* original 3b83, guest PC 0x0c04f67a */
if(!s->budget--) { s->failed_pc=0x0c04f67au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[8])!=0);
goto P_0c04f67c;
P_0c04f67c: /* original 8bed, guest PC 0x0c04f67c */
if(!s->budget--) { s->failed_pc=0x0c04f67cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f65a; }
goto P_0c04f67e;
P_0c04f67e: /* original 85f2, guest PC 0x0c04f67e */
if(!s->budget--) { s->failed_pc=0x0c04f67eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c04f680;
P_0c04f680: /* original 6383, guest PC 0x0c04f680 */
if(!s->budget--) { s->failed_pc=0x0c04f680u; return 0; }
r[3]=r[8];
goto P_0c04f682;
P_0c04f682: /* original 73ff, guest PC 0x0c04f682 */
if(!s->budget--) { s->failed_pc=0x0c04f682u; return 0; }
r[3]+=0xffffffffu;
goto P_0c04f684;
P_0c04f684: /* original 6c03, guest PC 0x0c04f684 */
if(!s->budget--) { s->failed_pc=0x0c04f684u; return 0; }
r[12]=r[0];
goto P_0c04f686;
P_0c04f686: /* original eb00, guest PC 0x0c04f686 */
if(!s->budget--) { s->failed_pc=0x0c04f686u; return 0; }
r[11]=0x00000000u;
goto P_0c04f688;
P_0c04f688: /* original a041, guest PC 0x0c04f688 */
if(!s->budget--) { s->failed_pc=0x0c04f688u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c04f70e;
P_0c04f68a: /* original 1f32, guest PC 0x0c04f68a */
if(!s->budget--) { s->failed_pc=0x0c04f68au; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c04f68c;
P_0c04f68c: /* original 61b3, guest PC 0x0c04f68c */
if(!s->budget--) { s->failed_pc=0x0c04f68cu; return 0; }
r[1]=r[11];
goto P_0c04f68e;
P_0c04f68e: /* original 4118, guest PC 0x0c04f68e */
if(!s->budget--) { s->failed_pc=0x0c04f68eu; return 0; }
r[1]<<=8;
goto P_0c04f690;
P_0c04f690: /* original 4100, guest PC 0x0c04f690 */
if(!s->budget--) { s->failed_pc=0x0c04f690u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c04f692;
P_0c04f692: /* original 2f12, guest PC 0x0c04f692 */
if(!s->budget--) { s->failed_pc=0x0c04f692u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c04f694;
P_0c04f694: /* original 569a, guest PC 0x0c04f694 */
if(!s->budget--) { s->failed_pc=0x0c04f694u; return 0; }
r[6]=read(ram,r[9]+40,4);
goto P_0c04f696;
P_0c04f696: /* original 65cd, guest PC 0x0c04f696 */
if(!s->budget--) { s->failed_pc=0x0c04f696u; return 0; }
r[5]=r[12]&65535u;
goto P_0c04f698;
P_0c04f698: /* original 63f2, guest PC 0x0c04f698 */
if(!s->budget--) { s->failed_pc=0x0c04f698u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c04f69a;
P_0c04f69a: /* original d20e, guest PC 0x0c04f69a */
if(!s->budget--) { s->failed_pc=0x0c04f69au; return 0; }
r[2]=read(ram,0x0c04f6d4u,4);
goto P_0c04f69c;
P_0c04f69c: /* original 363c, guest PC 0x0c04f69c */
if(!s->budget--) { s->failed_pc=0x0c04f69cu; return 0; }
r[6]+=r[3];
goto P_0c04f69e;
P_0c04f69e: /* original 420b, guest PC 0x0c04f69e */
if(!s->budget--) { s->failed_pc=0x0c04f69eu; return 0; }
target=r[2];
r[16]=code_base|0x0c04f6a2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f6a2u) { target=s->pc; goto dispatch; }
goto P_0c04f6a2;
P_0c04f6a0: /* original 64e3, guest PC 0x0c04f6a0 */
if(!s->budget--) { s->failed_pc=0x0c04f6a0u; return 0; }
r[4]=r[14];
goto P_0c04f6a2;
P_0c04f6a2: /* original 6403, guest PC 0x0c04f6a2 */
if(!s->budget--) { s->failed_pc=0x0c04f6a2u; return 0; }
r[4]=r[0];
goto P_0c04f6a4;
P_0c04f6a4: /* original 2448, guest PC 0x0c04f6a4 */
if(!s->budget--) { s->failed_pc=0x0c04f6a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c04f6a6;
P_0c04f6a6: /* original 891b, guest PC 0x0c04f6a6 */
if(!s->budget--) { s->failed_pc=0x0c04f6a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f6e0; }
goto P_0c04f6a8;
P_0c04f6a8: /* original 930e, guest PC 0x0c04f6a8 */
if(!s->budget--) { s->failed_pc=0x0c04f6a8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f6c8u,2);
goto P_0c04f6aa;
P_0c04f6aa: /* original 3430, guest PC 0x0c04f6aa */
if(!s->budget--) { s->failed_pc=0x0c04f6aau; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c04f6ac;
P_0c04f6ac: /* original 8b01, guest PC 0x0c04f6ac */
if(!s->budget--) { s->failed_pc=0x0c04f6acu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f6b2; }
goto P_0c04f6ae;
P_0c04f6ae: /* original a043, guest PC 0x0c04f6ae */
if(!s->budget--) { s->failed_pc=0x0c04f6aeu; return 0; }
r[0]=r[4];
goto P_0c04f738;
P_0c04f6b0: /* original 6043, guest PC 0x0c04f6b0 */
if(!s->budget--) { s->failed_pc=0x0c04f6b0u; return 0; }
r[0]=r[4];
goto P_0c04f6b2;
P_0c04f6b2: /* original d609, guest PC 0x0c04f6b2 */
if(!s->budget--) { s->failed_pc=0x0c04f6b2u; return 0; }
r[6]=read(ram,0x0c04f6d8u,4);
goto P_0c04f6b4;
P_0c04f6b4: /* original 65cd, guest PC 0x0c04f6b4 */
if(!s->budget--) { s->failed_pc=0x0c04f6b4u; return 0; }
r[5]=r[12]&65535u;
goto P_0c04f6b6;
P_0c04f6b6: /* original b3c3, guest PC 0x0c04f6b6 */
if(!s->budget--) { s->failed_pc=0x0c04f6b6u; return 0; }
target=code_base|0x0c04fe40u; r[16]=code_base|0x0c04f6bau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f6bau) { target=s->pc; goto dispatch; }
goto P_0c04f6ba;
P_0c04f6b8: /* original 64e3, guest PC 0x0c04f6b8 */
if(!s->budget--) { s->failed_pc=0x0c04f6b8u; return 0; }
r[4]=r[14];
goto P_0c04f6ba;
P_0c04f6ba: /* original d208, guest PC 0x0c04f6ba */
if(!s->budget--) { s->failed_pc=0x0c04f6bau; return 0; }
r[2]=read(ram,0x0c04f6dcu,4);
goto P_0c04f6bc;
P_0c04f6bc: /* original 65d3, guest PC 0x0c04f6bc */
if(!s->budget--) { s->failed_pc=0x0c04f6bcu; return 0; }
r[5]=r[13];
goto P_0c04f6be;
P_0c04f6be: /* original 420b, guest PC 0x0c04f6be */
if(!s->budget--) { s->failed_pc=0x0c04f6beu; return 0; }
target=r[2];
r[16]=code_base|0x0c04f6c2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f6c2u) { target=s->pc; goto dispatch; }
goto P_0c04f6c2;
P_0c04f6c0: /* original 64e3, guest PC 0x0c04f6c0 */
if(!s->budget--) { s->failed_pc=0x0c04f6c0u; return 0; }
r[4]=r[14];
goto P_0c04f6c2;
P_0c04f6c2: /* original afe7, guest PC 0x0c04f6c2 */
if(!s->budget--) { s->failed_pc=0x0c04f6c2u; return 0; }
r[12]=r[0];
goto P_0c04f694;
P_0c04f6c4: /* original 6c03, guest PC 0x0c04f6c4 */
if(!s->budget--) { s->failed_pc=0x0c04f6c4u; return 0; }
r[12]=r[0];
if(!vf3_matrix_family(0x0c04f6c6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04f6c6u; return 0; } return 1;
P_0c04f6e0: /* original 2bb8, guest PC 0x0c04f6e0 */
if(!s->budget--) { s->failed_pc=0x0c04f6e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c04f6e2;
P_0c04f6e2: /* original 8f02, guest PC 0x0c04f6e2 */
if(!s->budget--) { s->failed_pc=0x0c04f6e2u; return 0; }
cond=r[17]&1u;
r[6]=r[10];
if(!cond) { goto P_0c04f6ea; }
goto P_0c04f6e6;
P_0c04f6e4: /* original 66a3, guest PC 0x0c04f6e4 */
if(!s->budget--) { s->failed_pc=0x0c04f6e4u; return 0; }
r[6]=r[10];
goto P_0c04f6e6;
P_0c04f6e6: /* original 60c3, guest PC 0x0c04f6e6 */
if(!s->budget--) { s->failed_pc=0x0c04f6e6u; return 0; }
r[0]=r[12];
goto P_0c04f6e8;
P_0c04f6e8: /* original 81f2, guest PC 0x0c04f6e8 */
if(!s->budget--) { s->failed_pc=0x0c04f6e8u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c04f6ea;
P_0c04f6ea: /* original 65cd, guest PC 0x0c04f6ea */
if(!s->budget--) { s->failed_pc=0x0c04f6eau; return 0; }
r[5]=r[12]&65535u;
goto P_0c04f6ec;
P_0c04f6ec: /* original 1f53, guest PC 0x0c04f6ec */
if(!s->budget--) { s->failed_pc=0x0c04f6ecu; return 0; }
write(ram,r[15]+12,r[5],4);
goto P_0c04f6ee;
P_0c04f6ee: /* original b3a7, guest PC 0x0c04f6ee */
if(!s->budget--) { s->failed_pc=0x0c04f6eeu; return 0; }
target=code_base|0x0c04fe40u; r[16]=code_base|0x0c04f6f2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f6f2u) { target=s->pc; goto dispatch; }
goto P_0c04f6f2;
P_0c04f6f0: /* original 64e3, guest PC 0x0c04f6f0 */
if(!s->budget--) { s->failed_pc=0x0c04f6f0u; return 0; }
r[4]=r[14];
goto P_0c04f6f2;
P_0c04f6f2: /* original 52f2, guest PC 0x0c04f6f2 */
if(!s->budget--) { s->failed_pc=0x0c04f6f2u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c04f6f4;
P_0c04f6f4: /* original 3b20, guest PC 0x0c04f6f4 */
if(!s->budget--) { s->failed_pc=0x0c04f6f4u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[2])!=0);
goto P_0c04f6f6;
P_0c04f6f6: /* original 8909, guest PC 0x0c04f6f6 */
if(!s->budget--) { s->failed_pc=0x0c04f6f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f70c; }
goto P_0c04f6f8;
P_0c04f6f8: /* original d235, guest PC 0x0c04f6f8 */
if(!s->budget--) { s->failed_pc=0x0c04f6f8u; return 0; }
r[2]=read(ram,0x0c04f7d0u,4);
goto P_0c04f6fa;
P_0c04f6fa: /* original 65d3, guest PC 0x0c04f6fa */
if(!s->budget--) { s->failed_pc=0x0c04f6fau; return 0; }
r[5]=r[13];
goto P_0c04f6fc;
P_0c04f6fc: /* original 420b, guest PC 0x0c04f6fc */
if(!s->budget--) { s->failed_pc=0x0c04f6fcu; return 0; }
target=r[2];
r[16]=code_base|0x0c04f700u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f700u) { target=s->pc; goto dispatch; }
goto P_0c04f700;
P_0c04f6fe: /* original 64e3, guest PC 0x0c04f6fe */
if(!s->budget--) { s->failed_pc=0x0c04f6feu; return 0; }
r[4]=r[14];
goto P_0c04f700;
P_0c04f700: /* original 6603, guest PC 0x0c04f700 */
if(!s->budget--) { s->failed_pc=0x0c04f700u; return 0; }
r[6]=r[0];
goto P_0c04f702;
P_0c04f702: /* original 2f01, guest PC 0x0c04f702 */
if(!s->budget--) { s->failed_pc=0x0c04f702u; return 0; }
write(ram,r[15],r[0],2);
goto P_0c04f704;
P_0c04f704: /* original 55f3, guest PC 0x0c04f704 */
if(!s->budget--) { s->failed_pc=0x0c04f704u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c04f706;
P_0c04f706: /* original b39b, guest PC 0x0c04f706 */
if(!s->budget--) { s->failed_pc=0x0c04f706u; return 0; }
target=code_base|0x0c04fe40u; r[16]=code_base|0x0c04f70au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f70au) { target=s->pc; goto dispatch; }
goto P_0c04f70a;
P_0c04f708: /* original 64e3, guest PC 0x0c04f708 */
if(!s->budget--) { s->failed_pc=0x0c04f708u; return 0; }
r[4]=r[14];
goto P_0c04f70a;
P_0c04f70a: /* original 6cf1, guest PC 0x0c04f70a */
if(!s->budget--) { s->failed_pc=0x0c04f70au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[12]=tmp;
goto P_0c04f70c;
P_0c04f70c: /* original 7b01, guest PC 0x0c04f70c */
if(!s->budget--) { s->failed_pc=0x0c04f70cu; return 0; }
r[11]+=0x00000001u;
goto P_0c04f70e;
P_0c04f70e: /* original 3b83, guest PC 0x0c04f70e */
if(!s->budget--) { s->failed_pc=0x0c04f70eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[8])!=0);
goto P_0c04f710;
P_0c04f710: /* original 8bbc, guest PC 0x0c04f710 */
if(!s->budget--) { s->failed_pc=0x0c04f710u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f68c; }
goto P_0c04f712;
P_0c04f712: /* original 5397, guest PC 0x0c04f712 */
if(!s->budget--) { s->failed_pc=0x0c04f712u; return 0; }
r[3]=read(ram,r[9]+28,4);
goto P_0c04f714;
P_0c04f714: /* original 85f2, guest PC 0x0c04f714 */
if(!s->budget--) { s->failed_pc=0x0c04f714u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c04f716;
P_0c04f716: /* original 5235, guest PC 0x0c04f716 */
if(!s->budget--) { s->failed_pc=0x0c04f716u; return 0; }
r[2]=read(ram,r[3]+20,4);
goto P_0c04f718;
P_0c04f718: /* original 600d, guest PC 0x0c04f718 */
if(!s->budget--) { s->failed_pc=0x0c04f718u; return 0; }
r[0]=r[0]&65535u;
goto P_0c04f71a;
P_0c04f71a: /* original 3020, guest PC 0x0c04f71a */
if(!s->budget--) { s->failed_pc=0x0c04f71au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[2])!=0);
goto P_0c04f71c;
P_0c04f71c: /* original 890b, guest PC 0x0c04f71c */
if(!s->budget--) { s->failed_pc=0x0c04f71cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f736; }
goto P_0c04f71e;
P_0c04f71e: /* original d32d, guest PC 0x0c04f71e */
if(!s->budget--) { s->failed_pc=0x0c04f71eu; return 0; }
r[3]=read(ram,0x0c04f7d4u,4);
goto P_0c04f720;
P_0c04f720: /* original e54a, guest PC 0x0c04f720 */
if(!s->budget--) { s->failed_pc=0x0c04f720u; return 0; }
r[5]=0x0000004au;
goto P_0c04f722;
P_0c04f722: /* original 85f2, guest PC 0x0c04f722 */
if(!s->budget--) { s->failed_pc=0x0c04f722u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c04f724;
P_0c04f724: /* original 6132, guest PC 0x0c04f724 */
if(!s->budget--) { s->failed_pc=0x0c04f724u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c04f726;
P_0c04f726: /* original 6603, guest PC 0x0c04f726 */
if(!s->budget--) { s->failed_pc=0x0c04f726u; return 0; }
r[6]=r[0];
goto P_0c04f728;
P_0c04f728: /* original 5214, guest PC 0x0c04f728 */
if(!s->budget--) { s->failed_pc=0x0c04f728u; return 0; }
r[2]=read(ram,r[1]+16,4);
goto P_0c04f72a;
P_0c04f72a: /* original 420b, guest PC 0x0c04f72a */
if(!s->budget--) { s->failed_pc=0x0c04f72au; return 0; }
target=r[2];
r[16]=code_base|0x0c04f72eu;
r[4]=read(ram,r[9]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f72eu) { target=s->pc; goto dispatch; }
goto P_0c04f72e;
P_0c04f72c: /* original 5498, guest PC 0x0c04f72c */
if(!s->budget--) { s->failed_pc=0x0c04f72cu; return 0; }
r[4]=read(ram,r[9]+32,4);
goto P_0c04f72e;
P_0c04f72e: /* original b2ff, guest PC 0x0c04f72e */
if(!s->budget--) { s->failed_pc=0x0c04f72eu; return 0; }
target=code_base|0x0c04fd30u; r[16]=code_base|0x0c04f732u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f732u) { target=s->pc; goto dispatch; }
goto P_0c04f732;
P_0c04f730: /* original 64e3, guest PC 0x0c04f730 */
if(!s->budget--) { s->failed_pc=0x0c04f730u; return 0; }
r[4]=r[14];
goto P_0c04f732;
P_0c04f732: /* original b1e3, guest PC 0x0c04f732 */
if(!s->budget--) { s->failed_pc=0x0c04f732u; return 0; }
target=code_base|0x0c04fafcu; r[16]=code_base|0x0c04f736u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f736u) { target=s->pc; goto dispatch; }
goto P_0c04f736;
P_0c04f734: /* original 64e3, guest PC 0x0c04f734 */
if(!s->budget--) { s->failed_pc=0x0c04f734u; return 0; }
r[4]=r[14];
goto P_0c04f736;
P_0c04f736: /* original e000, guest PC 0x0c04f736 */
if(!s->budget--) { s->failed_pc=0x0c04f736u; return 0; }
r[0]=0x00000000u;
goto P_0c04f738;
P_0c04f738: /* original 7f10, guest PC 0x0c04f738 */
if(!s->budget--) { s->failed_pc=0x0c04f738u; return 0; }
r[15]+=0x00000010u;
goto P_0c04f73a;
P_0c04f73a: /* original 4f16, guest PC 0x0c04f73a */
if(!s->budget--) { s->failed_pc=0x0c04f73au; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f73c;
P_0c04f73c: /* original 4f26, guest PC 0x0c04f73c */
if(!s->budget--) { s->failed_pc=0x0c04f73cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f73e;
P_0c04f73e: /* original 68f6, guest PC 0x0c04f73e */
if(!s->budget--) { s->failed_pc=0x0c04f73eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04f740;
P_0c04f740: /* original 69f6, guest PC 0x0c04f740 */
if(!s->budget--) { s->failed_pc=0x0c04f740u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04f742;
P_0c04f742: /* original 6af6, guest PC 0x0c04f742 */
if(!s->budget--) { s->failed_pc=0x0c04f742u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04f744;
P_0c04f744: /* original 6bf6, guest PC 0x0c04f744 */
if(!s->budget--) { s->failed_pc=0x0c04f744u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04f746;
P_0c04f746: /* original 6cf6, guest PC 0x0c04f746 */
if(!s->budget--) { s->failed_pc=0x0c04f746u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04f748;
P_0c04f748: /* original 6df6, guest PC 0x0c04f748 */
if(!s->budget--) { s->failed_pc=0x0c04f748u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04f74a;
P_0c04f74a: /* original 000b, guest PC 0x0c04f74a */
if(!s->budget--) { s->failed_pc=0x0c04f74au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f74c: /* original 6ef6, guest PC 0x0c04f74c */
if(!s->budget--) { s->failed_pc=0x0c04f74cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04f74eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04f74eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
