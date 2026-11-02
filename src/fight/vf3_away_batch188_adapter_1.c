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
int vf3_away_batch188_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a0718u: goto P_0c0a0718;
case 0x0c0a071au: goto P_0c0a071a;
case 0x0c0a071cu: goto P_0c0a071c;
case 0x0c0a071eu: goto P_0c0a071e;
case 0x0c0a0720u: goto P_0c0a0720;
case 0x0c0a0722u: goto P_0c0a0722;
case 0x0c0a0724u: goto P_0c0a0724;
case 0x0c0a0726u: goto P_0c0a0726;
case 0x0c0a0728u: goto P_0c0a0728;
case 0x0c0a072au: goto P_0c0a072a;
case 0x0c0a072cu: goto P_0c0a072c;
case 0x0c0a072eu: goto P_0c0a072e;
case 0x0c0a0730u: goto P_0c0a0730;
case 0x0c0a0732u: goto P_0c0a0732;
case 0x0c0a0734u: goto P_0c0a0734;
case 0x0c0a0736u: goto P_0c0a0736;
case 0x0c0a0738u: goto P_0c0a0738;
case 0x0c0a073au: goto P_0c0a073a;
case 0x0c0a073cu: goto P_0c0a073c;
case 0x0c0a073eu: goto P_0c0a073e;
case 0x0c0a0740u: goto P_0c0a0740;
case 0x0c0a0742u: goto P_0c0a0742;
case 0x0c0a0744u: goto P_0c0a0744;
case 0x0c0a0746u: goto P_0c0a0746;
case 0x0c0a0748u: goto P_0c0a0748;
case 0x0c0a074au: goto P_0c0a074a;
case 0x0c0a074cu: goto P_0c0a074c;
case 0x0c0a074eu: goto P_0c0a074e;
case 0x0c0a0750u: goto P_0c0a0750;
case 0x0c0a0752u: goto P_0c0a0752;
case 0x0c0a0754u: goto P_0c0a0754;
case 0x0c0a0756u: goto P_0c0a0756;
case 0x0c0a0758u: goto P_0c0a0758;
case 0x0c0a075au: goto P_0c0a075a;
case 0x0c0a075cu: goto P_0c0a075c;
case 0x0c0a075eu: goto P_0c0a075e;
case 0x0c0a0760u: goto P_0c0a0760;
case 0x0c0a0762u: goto P_0c0a0762;
case 0x0c0a0764u: goto P_0c0a0764;
case 0x0c0a0766u: goto P_0c0a0766;
case 0x0c0a0768u: goto P_0c0a0768;
case 0x0c0a076au: goto P_0c0a076a;
case 0x0c0a076cu: goto P_0c0a076c;
case 0x0c0a076eu: goto P_0c0a076e;
case 0x0c0a0770u: goto P_0c0a0770;
case 0x0c0a0772u: goto P_0c0a0772;
case 0x0c0a0774u: goto P_0c0a0774;
case 0x0c0a0776u: goto P_0c0a0776;
case 0x0c0a0778u: goto P_0c0a0778;
case 0x0c0a077au: goto P_0c0a077a;
case 0x0c0a077cu: goto P_0c0a077c;
case 0x0c0a077eu: goto P_0c0a077e;
case 0x0c0a0780u: goto P_0c0a0780;
case 0x0c0a0782u: goto P_0c0a0782;
case 0x0c0a0784u: goto P_0c0a0784;
case 0x0c0a0786u: goto P_0c0a0786;
case 0x0c0a0788u: goto P_0c0a0788;
case 0x0c0a078au: goto P_0c0a078a;
case 0x0c0a078cu: goto P_0c0a078c;
case 0x0c0a078eu: goto P_0c0a078e;
case 0x0c0a0790u: goto P_0c0a0790;
case 0x0c0a0792u: goto P_0c0a0792;
case 0x0c0a0794u: goto P_0c0a0794;
case 0x0c0a0796u: goto P_0c0a0796;
case 0x0c0a0798u: goto P_0c0a0798;
case 0x0c0a079au: goto P_0c0a079a;
case 0x0c0a079cu: goto P_0c0a079c;
case 0x0c0a079eu: goto P_0c0a079e;
case 0x0c0a07a0u: goto P_0c0a07a0;
case 0x0c0a07a2u: goto P_0c0a07a2;
case 0x0c0a07a4u: goto P_0c0a07a4;
case 0x0c0a07a6u: goto P_0c0a07a6;
case 0x0c0a07a8u: goto P_0c0a07a8;
case 0x0c0a07aau: goto P_0c0a07aa;
case 0x0c0a07acu: goto P_0c0a07ac;
case 0x0c0a07aeu: goto P_0c0a07ae;
case 0x0c0a07b0u: goto P_0c0a07b0;
case 0x0c0a07b2u: goto P_0c0a07b2;
case 0x0c0a07b4u: goto P_0c0a07b4;
case 0x0c0a07b6u: goto P_0c0a07b6;
case 0x0c0a07b8u: goto P_0c0a07b8;
case 0x0c0a07bau: goto P_0c0a07ba;
case 0x0c0a07bcu: goto P_0c0a07bc;
case 0x0c0a07beu: goto P_0c0a07be;
case 0x0c0a07c0u: goto P_0c0a07c0;
case 0x0c0a07c2u: goto P_0c0a07c2;
case 0x0c0a07c4u: goto P_0c0a07c4;
case 0x0c0a07c6u: goto P_0c0a07c6;
case 0x0c0a07c8u: goto P_0c0a07c8;
case 0x0c0a07cau: goto P_0c0a07ca;
case 0x0c0a07ccu: goto P_0c0a07cc;
case 0x0c0a07ceu: goto P_0c0a07ce;
case 0x0c0a07d0u: goto P_0c0a07d0;
case 0x0c0a07d2u: goto P_0c0a07d2;
case 0x0c0a07d4u: goto P_0c0a07d4;
case 0x0c0a07d6u: goto P_0c0a07d6;
case 0x0c0a07d8u: goto P_0c0a07d8;
case 0x0c0a07dau: goto P_0c0a07da;
case 0x0c0a07dcu: goto P_0c0a07dc;
case 0x0c0a07deu: goto P_0c0a07de;
case 0x0c0a07e0u: goto P_0c0a07e0;
case 0x0c0a07e2u: goto P_0c0a07e2;
case 0x0c0c66d0u: goto P_0c0c66d0;
case 0x0c0c66d2u: goto P_0c0c66d2;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a0718: /* original 2fe6, guest PC 0x0c0a0718 */
if(!s->budget--) { s->failed_pc=0x0c0a0718u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a071a;
P_0c0a071a: /* original ee00, guest PC 0x0c0a071a */
if(!s->budget--) { s->failed_pc=0x0c0a071au; return 0; }
r[14]=0x00000000u;
goto P_0c0a071c;
P_0c0a071c: /* original d54a, guest PC 0x0c0a071c */
if(!s->budget--) { s->failed_pc=0x0c0a071cu; return 0; }
r[5]=read(ram,0x0c0a0848u,4);
goto P_0c0a071e;
P_0c0a071e: /* original 7fd4, guest PC 0x0c0a071e */
if(!s->budget--) { s->failed_pc=0x0c0a071eu; return 0; }
r[15]+=0xffffffd4u;
goto P_0c0a0720;
P_0c0a0720: /* original 64f3, guest PC 0x0c0a0720 */
if(!s->budget--) { s->failed_pc=0x0c0a0720u; return 0; }
r[4]=r[15];
goto P_0c0a0722;
P_0c0a0722: /* original 7420, guest PC 0x0c0a0722 */
if(!s->budget--) { s->failed_pc=0x0c0a0722u; return 0; }
r[4]+=0x00000020u;
goto P_0c0a0724;
P_0c0a0724: /* original 6343, guest PC 0x0c0a0724 */
if(!s->budget--) { s->failed_pc=0x0c0a0724u; return 0; }
r[3]=r[4];
goto P_0c0a0726;
P_0c0a0726: /* original 1f31, guest PC 0x0c0a0726 */
if(!s->budget--) { s->failed_pc=0x0c0a0726u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0a0728;
P_0c0a0728: /* original 9086, guest PC 0x0c0a0728 */
if(!s->budget--) { s->failed_pc=0x0c0a0728u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0838u,2);
goto P_0c0a072a;
P_0c0a072a: /* original 7402, guest PC 0x0c0a072a */
if(!s->budget--) { s->failed_pc=0x0c0a072au; return 0; }
r[4]+=0x00000002u;
goto P_0c0a072c;
P_0c0a072c: /* original 025c, guest PC 0x0c0a072c */
if(!s->budget--) { s->failed_pc=0x0c0a072cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0a072e;
P_0c0a072e: /* original 2320, guest PC 0x0c0a072e */
if(!s->budget--) { s->failed_pc=0x0c0a072eu; return 0; }
write(ram,r[3],r[2],1);
goto P_0c0a0730;
P_0c0a0730: /* original 7301, guest PC 0x0c0a0730 */
if(!s->budget--) { s->failed_pc=0x0c0a0730u; return 0; }
r[3]+=0x00000001u;
goto P_0c0a0732;
P_0c0a0732: /* original 1f36, guest PC 0x0c0a0732 */
if(!s->budget--) { s->failed_pc=0x0c0a0732u; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0a0734;
P_0c0a0734: /* original 9081, guest PC 0x0c0a0734 */
if(!s->budget--) { s->failed_pc=0x0c0a0734u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a083au,2);
goto P_0c0a0736;
P_0c0a0736: /* original 025c, guest PC 0x0c0a0736 */
if(!s->budget--) { s->failed_pc=0x0c0a0736u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0a0738;
P_0c0a0738: /* original 2320, guest PC 0x0c0a0738 */
if(!s->budget--) { s->failed_pc=0x0c0a0738u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c0a073a;
P_0c0a073a: /* original 1f44, guest PC 0x0c0a073a */
if(!s->budget--) { s->failed_pc=0x0c0a073au; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c0a073c;
P_0c0a073c: /* original 907e, guest PC 0x0c0a073c */
if(!s->budget--) { s->failed_pc=0x0c0a073cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a083cu,2);
goto P_0c0a073e;
P_0c0a073e: /* original 035c, guest PC 0x0c0a073e */
if(!s->budget--) { s->failed_pc=0x0c0a073eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0a0740;
P_0c0a0740: /* original 2430, guest PC 0x0c0a0740 */
if(!s->budget--) { s->failed_pc=0x0c0a0740u; return 0; }
write(ram,r[4],r[3],1);
goto P_0c0a0742;
P_0c0a0742: /* original d242, guest PC 0x0c0a0742 */
if(!s->budget--) { s->failed_pc=0x0c0a0742u; return 0; }
r[2]=read(ram,0x0c0a084cu,4);
goto P_0c0a0744;
P_0c0a0744: /* original 1f27, guest PC 0x0c0a0744 */
if(!s->budget--) { s->failed_pc=0x0c0a0744u; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c0a0746;
P_0c0a0746: /* original d342, guest PC 0x0c0a0746 */
if(!s->budget--) { s->failed_pc=0x0c0a0746u; return 0; }
r[3]=read(ram,0x0c0a0850u,4);
goto P_0c0a0748;
P_0c0a0748: /* original 2f32, guest PC 0x0c0a0748 */
if(!s->budget--) { s->failed_pc=0x0c0a0748u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a074a;
P_0c0a074a: /* original e30b, guest PC 0x0c0a074a */
if(!s->budget--) { s->failed_pc=0x0c0a074au; return 0; }
r[3]=0x0000000bu;
goto P_0c0a074c;
P_0c0a074c: /* original 3e33, guest PC 0x0c0a074c */
if(!s->budget--) { s->failed_pc=0x0c0a074cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c0a074e;
P_0c0a074e: /* original 8946, guest PC 0x0c0a074e */
if(!s->budget--) { s->failed_pc=0x0c0a074eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a07de; }
goto P_0c0a0750;
P_0c0a0750: /* original 54f7, guest PC 0x0c0a0750 */
if(!s->budget--) { s->failed_pc=0x0c0a0750u; return 0; }
r[4]=read(ram,r[15]+28,4);
goto P_0c0a0752;
P_0c0a0752: /* original 67f3, guest PC 0x0c0a0752 */
if(!s->budget--) { s->failed_pc=0x0c0a0752u; return 0; }
r[7]=r[15];
goto P_0c0a0754;
P_0c0a0754: /* original 7728, guest PC 0x0c0a0754 */
if(!s->budget--) { s->failed_pc=0x0c0a0754u; return 0; }
r[7]+=0x00000028u;
goto P_0c0a0756;
P_0c0a0756: /* original 7404, guest PC 0x0c0a0756 */
if(!s->budget--) { s->failed_pc=0x0c0a0756u; return 0; }
r[4]+=0x00000004u;
goto P_0c0a0758;
P_0c0a0758: /* original 6373, guest PC 0x0c0a0758 */
if(!s->budget--) { s->failed_pc=0x0c0a0758u; return 0; }
r[3]=r[7];
goto P_0c0a075a;
P_0c0a075a: /* original 1f47, guest PC 0x0c0a075a */
if(!s->budget--) { s->failed_pc=0x0c0a075au; return 0; }
write(ram,r[15]+28,r[4],4);
goto P_0c0a075c;
P_0c0a075c: /* original 74fc, guest PC 0x0c0a075c */
if(!s->budget--) { s->failed_pc=0x0c0a075cu; return 0; }
r[4]+=0xfffffffcu;
goto P_0c0a075e;
P_0c0a075e: /* original 6442, guest PC 0x0c0a075e */
if(!s->budget--) { s->failed_pc=0x0c0a075eu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0a0760;
P_0c0a0760: /* original 66f2, guest PC 0x0c0a0760 */
if(!s->budget--) { s->failed_pc=0x0c0a0760u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c0a0762;
P_0c0a0762: /* original 7604, guest PC 0x0c0a0762 */
if(!s->budget--) { s->failed_pc=0x0c0a0762u; return 0; }
r[6]+=0x00000004u;
goto P_0c0a0764;
P_0c0a0764: /* original 2f62, guest PC 0x0c0a0764 */
if(!s->budget--) { s->failed_pc=0x0c0a0764u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0a0766;
P_0c0a0766: /* original 76fc, guest PC 0x0c0a0766 */
if(!s->budget--) { s->failed_pc=0x0c0a0766u; return 0; }
r[6]+=0xfffffffcu;
goto P_0c0a0768;
P_0c0a0768: /* original 6662, guest PC 0x0c0a0768 */
if(!s->budget--) { s->failed_pc=0x0c0a0768u; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c0a076a;
P_0c0a076a: /* original 1f32, guest PC 0x0c0a076a */
if(!s->budget--) { s->failed_pc=0x0c0a076au; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0a076c;
P_0c0a076c: /* original 6244, guest PC 0x0c0a076c */
if(!s->budget--) { s->failed_pc=0x0c0a076cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[2]=tmp;
goto P_0c0a076e;
P_0c0a076e: /* original 2320, guest PC 0x0c0a076e */
if(!s->budget--) { s->failed_pc=0x0c0a076eu; return 0; }
write(ram,r[3],r[2],1);
goto P_0c0a0770;
P_0c0a0770: /* original 7301, guest PC 0x0c0a0770 */
if(!s->budget--) { s->failed_pc=0x0c0a0770u; return 0; }
r[3]+=0x00000001u;
goto P_0c0a0772;
P_0c0a0772: /* original 1f35, guest PC 0x0c0a0772 */
if(!s->budget--) { s->failed_pc=0x0c0a0772u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c0a0774;
P_0c0a0774: /* original 6244, guest PC 0x0c0a0774 */
if(!s->budget--) { s->failed_pc=0x0c0a0774u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[2]=tmp;
goto P_0c0a0776;
P_0c0a0776: /* original 2320, guest PC 0x0c0a0776 */
if(!s->budget--) { s->failed_pc=0x0c0a0776u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c0a0778;
P_0c0a0778: /* original 6373, guest PC 0x0c0a0778 */
if(!s->budget--) { s->failed_pc=0x0c0a0778u; return 0; }
r[3]=r[7];
goto P_0c0a077a;
P_0c0a077a: /* original 7302, guest PC 0x0c0a077a */
if(!s->budget--) { s->failed_pc=0x0c0a077au; return 0; }
r[3]+=0x00000002u;
goto P_0c0a077c;
P_0c0a077c: /* original 1f33, guest PC 0x0c0a077c */
if(!s->budget--) { s->failed_pc=0x0c0a077cu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0a077e;
P_0c0a077e: /* original 6244, guest PC 0x0c0a077e */
if(!s->budget--) { s->failed_pc=0x0c0a077eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[2]=tmp;
goto P_0c0a0780;
P_0c0a0780: /* original 2320, guest PC 0x0c0a0780 */
if(!s->budget--) { s->failed_pc=0x0c0a0780u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c0a0782;
P_0c0a0782: /* original 6040, guest PC 0x0c0a0782 */
if(!s->budget--) { s->failed_pc=0x0c0a0782u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
goto P_0c0a0784;
P_0c0a0784: /* original 64f3, guest PC 0x0c0a0784 */
if(!s->budget--) { s->failed_pc=0x0c0a0784u; return 0; }
r[4]=r[15];
goto P_0c0a0786;
P_0c0a0786: /* original 7424, guest PC 0x0c0a0786 */
if(!s->budget--) { s->failed_pc=0x0c0a0786u; return 0; }
r[4]+=0x00000024u;
goto P_0c0a0788;
P_0c0a0788: /* original 8073, guest PC 0x0c0a0788 */
if(!s->budget--) { s->failed_pc=0x0c0a0788u; return 0; }
write(ram,r[7]+3,r[0],1);
goto P_0c0a078a;
P_0c0a078a: /* original 6364, guest PC 0x0c0a078a */
if(!s->budget--) { s->failed_pc=0x0c0a078au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]+=1;
r[3]=tmp;
goto P_0c0a078c;
P_0c0a078c: /* original 2430, guest PC 0x0c0a078c */
if(!s->budget--) { s->failed_pc=0x0c0a078cu; return 0; }
write(ram,r[4],r[3],1);
goto P_0c0a078e;
P_0c0a078e: /* original 6064, guest PC 0x0c0a078e */
if(!s->budget--) { s->failed_pc=0x0c0a078eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]+=1;
r[0]=tmp;
goto P_0c0a0790;
P_0c0a0790: /* original 8041, guest PC 0x0c0a0790 */
if(!s->budget--) { s->failed_pc=0x0c0a0790u; return 0; }
write(ram,r[4]+1,r[0],1);
goto P_0c0a0792;
P_0c0a0792: /* original 6064, guest PC 0x0c0a0792 */
if(!s->budget--) { s->failed_pc=0x0c0a0792u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]+=1;
r[0]=tmp;
goto P_0c0a0794;
P_0c0a0794: /* original 8042, guest PC 0x0c0a0794 */
if(!s->budget--) { s->failed_pc=0x0c0a0794u; return 0; }
write(ram,r[4]+2,r[0],1);
goto P_0c0a0796;
P_0c0a0796: /* original 6060, guest PC 0x0c0a0796 */
if(!s->budget--) { s->failed_pc=0x0c0a0796u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[0]=tmp;
goto P_0c0a0798;
P_0c0a0798: /* original 8043, guest PC 0x0c0a0798 */
if(!s->budget--) { s->failed_pc=0x0c0a0798u; return 0; }
write(ram,r[4]+3,r[0],1);
goto P_0c0a079a;
P_0c0a079a: /* original 53f1, guest PC 0x0c0a079a */
if(!s->budget--) { s->failed_pc=0x0c0a079au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a079c;
P_0c0a079c: /* original 6230, guest PC 0x0c0a079c */
if(!s->budget--) { s->failed_pc=0x0c0a079cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c0a079e;
P_0c0a079e: /* original 53f2, guest PC 0x0c0a079e */
if(!s->budget--) { s->failed_pc=0x0c0a079eu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0a07a0;
P_0c0a07a0: /* original 6130, guest PC 0x0c0a07a0 */
if(!s->budget--) { s->failed_pc=0x0c0a07a0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[1]=tmp;
goto P_0c0a07a2;
P_0c0a07a2: /* original 3210, guest PC 0x0c0a07a2 */
if(!s->budget--) { s->failed_pc=0x0c0a07a2u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c0a07a4;
P_0c0a07a4: /* original 8fd1, guest PC 0x0c0a07a4 */
if(!s->budget--) { s->failed_pc=0x0c0a07a4u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000001u;
if(!cond) { goto P_0c0a074a; }
goto P_0c0a07a8;
P_0c0a07a6: /* original 7e01, guest PC 0x0c0a07a6 */
if(!s->budget--) { s->failed_pc=0x0c0a07a6u; return 0; }
r[14]+=0x00000001u;
goto P_0c0a07a8;
P_0c0a07a8: /* original 52f6, guest PC 0x0c0a07a8 */
if(!s->budget--) { s->failed_pc=0x0c0a07a8u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c0a07aa;
P_0c0a07aa: /* original 6320, guest PC 0x0c0a07aa */
if(!s->budget--) { s->failed_pc=0x0c0a07aau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c0a07ac;
P_0c0a07ac: /* original 52f5, guest PC 0x0c0a07ac */
if(!s->budget--) { s->failed_pc=0x0c0a07acu; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c0a07ae;
P_0c0a07ae: /* original 6120, guest PC 0x0c0a07ae */
if(!s->budget--) { s->failed_pc=0x0c0a07aeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c0a07b0;
P_0c0a07b0: /* original 3310, guest PC 0x0c0a07b0 */
if(!s->budget--) { s->failed_pc=0x0c0a07b0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c0a07b2;
P_0c0a07b2: /* original 8bca, guest PC 0x0c0a07b2 */
if(!s->budget--) { s->failed_pc=0x0c0a07b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a074a; }
goto P_0c0a07b4;
P_0c0a07b4: /* original 52f4, guest PC 0x0c0a07b4 */
if(!s->budget--) { s->failed_pc=0x0c0a07b4u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0a07b6;
P_0c0a07b6: /* original 6320, guest PC 0x0c0a07b6 */
if(!s->budget--) { s->failed_pc=0x0c0a07b6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c0a07b8;
P_0c0a07b8: /* original 52f3, guest PC 0x0c0a07b8 */
if(!s->budget--) { s->failed_pc=0x0c0a07b8u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0a07ba;
P_0c0a07ba: /* original 6120, guest PC 0x0c0a07ba */
if(!s->budget--) { s->failed_pc=0x0c0a07bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c0a07bc;
P_0c0a07bc: /* original 3310, guest PC 0x0c0a07bc */
if(!s->budget--) { s->failed_pc=0x0c0a07bcu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c0a07be;
P_0c0a07be: /* original 8bc4, guest PC 0x0c0a07be */
if(!s->budget--) { s->failed_pc=0x0c0a07beu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a074a; }
goto P_0c0a07c0;
P_0c0a07c0: /* original 903a, guest PC 0x0c0a07c0 */
if(!s->budget--) { s->failed_pc=0x0c0a07c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0838u,2);
goto P_0c0a07c2;
P_0c0a07c2: /* original 6340, guest PC 0x0c0a07c2 */
if(!s->budget--) { s->failed_pc=0x0c0a07c2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c0a07c4;
P_0c0a07c4: /* original 0534, guest PC 0x0c0a07c4 */
if(!s->budget--) { s->failed_pc=0x0c0a07c4u; return 0; }
write(ram,r[5]+r[0],r[3],1);
goto P_0c0a07c6;
P_0c0a07c6: /* original 9138, guest PC 0x0c0a07c6 */
if(!s->budget--) { s->failed_pc=0x0c0a07c6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a083au,2);
goto P_0c0a07c8;
P_0c0a07c8: /* original 8441, guest PC 0x0c0a07c8 */
if(!s->budget--) { s->failed_pc=0x0c0a07c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c0a07ca;
P_0c0a07ca: /* original 315c, guest PC 0x0c0a07ca */
if(!s->budget--) { s->failed_pc=0x0c0a07cau; return 0; }
r[1]+=r[5];
goto P_0c0a07cc;
P_0c0a07cc: /* original 2100, guest PC 0x0c0a07cc */
if(!s->budget--) { s->failed_pc=0x0c0a07ccu; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0a07ce;
P_0c0a07ce: /* original 9235, guest PC 0x0c0a07ce */
if(!s->budget--) { s->failed_pc=0x0c0a07ceu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a083cu,2);
goto P_0c0a07d0;
P_0c0a07d0: /* original 8442, guest PC 0x0c0a07d0 */
if(!s->budget--) { s->failed_pc=0x0c0a07d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c0a07d2;
P_0c0a07d2: /* original 325c, guest PC 0x0c0a07d2 */
if(!s->budget--) { s->failed_pc=0x0c0a07d2u; return 0; }
r[2]+=r[5];
goto P_0c0a07d4;
P_0c0a07d4: /* original 2200, guest PC 0x0c0a07d4 */
if(!s->budget--) { s->failed_pc=0x0c0a07d4u; return 0; }
write(ram,r[2],r[0],1);
goto P_0c0a07d6;
P_0c0a07d6: /* original 9132, guest PC 0x0c0a07d6 */
if(!s->budget--) { s->failed_pc=0x0c0a07d6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a083eu,2);
goto P_0c0a07d8;
P_0c0a07d8: /* original 8443, guest PC 0x0c0a07d8 */
if(!s->budget--) { s->failed_pc=0x0c0a07d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c0a07da;
P_0c0a07da: /* original 315c, guest PC 0x0c0a07da */
if(!s->budget--) { s->failed_pc=0x0c0a07dau; return 0; }
r[1]+=r[5];
goto P_0c0a07dc;
P_0c0a07dc: /* original 2100, guest PC 0x0c0a07dc */
if(!s->budget--) { s->failed_pc=0x0c0a07dcu; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0a07de;
P_0c0a07de: /* original 7f2c, guest PC 0x0c0a07de */
if(!s->budget--) { s->failed_pc=0x0c0a07deu; return 0; }
r[15]+=0x0000002cu;
goto P_0c0a07e0;
P_0c0a07e0: /* original 000b, guest PC 0x0c0a07e0 */
if(!s->budget--) { s->failed_pc=0x0c0a07e0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a07e2: /* original 6ef6, guest PC 0x0c0a07e2 */
if(!s->budget--) { s->failed_pc=0x0c0a07e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a07e4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a07e4u; return 0; } return 1;
P_0c0c66d0: /* original 000b, guest PC 0x0c0c66d0 */
if(!s->budget--) { s->failed_pc=0x0c0c66d0u; return 0; }
target=r[16];
write(ram,r[4],r[5],1);
s->pc=target; return ram->oob==0;
P_0c0c66d2: /* original 2450, guest PC 0x0c0c66d2 */
if(!s->budget--) { s->failed_pc=0x0c0c66d2u; return 0; }
write(ram,r[4],r[5],1);
if(!vf3_matrix_family(0x0c0c66d4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66d4u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
