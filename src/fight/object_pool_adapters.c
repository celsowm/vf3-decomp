/* Static C ABI adapters. Generated with tools/oracle/translate_adapters.py.
 * Matrix operations are hand-written in matrix_family.c; unknown code fails.
 * Executed opcodes are checked against the untouched identity image. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <math.h>
#include <string.h>
#define read vf3_matrix_read
#define write vf3_matrix_write
static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }
static uint32_t truncate_float(uint32_t u) { double d=as_float(u); if(isnan(d) || d< -2147483648.0) return 0x80000000u; if(d>=2147483648.0) return 0x7fffffffu; return (uint32_t)(int32_t)d; }
static void divide_step(vf3_matrix_state*s,unsigned n,unsigned m) { uint32_t *r=s->v; unsigned oldq=(r[17]>>8)&1u,sign=(r[17]>>9)&1u,q=r[n]>>31; uint32_t divisor=r[m],shifted=(r[n]<<1)|(r[17]&1u); r[n]=oldq==sign?shifted-divisor:shifted+divisor; unsigned carry=oldq==sign?r[n]>shifted:r[n]<shifted; q^=carry^sign; r[17]=(r[17]&~0x101u)|(q<<8)|(q==sign); }
int vf3_object_pool_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04d72eu: goto P_0c04d72e;
case 0x0c04d730u: goto P_0c04d730;
case 0x0c04d732u: goto P_0c04d732;
case 0x0c04d734u: goto P_0c04d734;
case 0x0c04d736u: goto P_0c04d736;
case 0x0c04d738u: goto P_0c04d738;
case 0x0c04d73au: goto P_0c04d73a;
case 0x0c04d73cu: goto P_0c04d73c;
case 0x0c04d73eu: goto P_0c04d73e;
case 0x0c04d740u: goto P_0c04d740;
case 0x0c04d742u: goto P_0c04d742;
case 0x0c04d744u: goto P_0c04d744;
case 0x0c04d746u: goto P_0c04d746;
case 0x0c04d748u: goto P_0c04d748;
case 0x0c04d74au: goto P_0c04d74a;
case 0x0c04d74cu: goto P_0c04d74c;
case 0x0c04d74eu: goto P_0c04d74e;
case 0x0c04d750u: goto P_0c04d750;
case 0x0c04d752u: goto P_0c04d752;
case 0x0c04d754u: goto P_0c04d754;
case 0x0c04d756u: goto P_0c04d756;
case 0x0c04d758u: goto P_0c04d758;
case 0x0c04d75au: goto P_0c04d75a;
case 0x0c04d75cu: goto P_0c04d75c;
case 0x0c04d75eu: goto P_0c04d75e;
case 0x0c04d760u: goto P_0c04d760;
case 0x0c04d762u: goto P_0c04d762;
case 0x0c04d764u: goto P_0c04d764;
case 0x0c04d78cu: goto P_0c04d78c;
case 0x0c04d78eu: goto P_0c04d78e;
case 0x0c04d790u: goto P_0c04d790;
case 0x0c04d792u: goto P_0c04d792;
case 0x0c04d794u: goto P_0c04d794;
case 0x0c04d796u: goto P_0c04d796;
case 0x0c04d798u: goto P_0c04d798;
case 0x0c04d79au: goto P_0c04d79a;
case 0x0c04d79cu: goto P_0c04d79c;
case 0x0c04d79eu: goto P_0c04d79e;
case 0x0c04d7a0u: goto P_0c04d7a0;
case 0x0c04d7a2u: goto P_0c04d7a2;
case 0x0c04d7a4u: goto P_0c04d7a4;
case 0x0c04d7a6u: goto P_0c04d7a6;
case 0x0c04d7a8u: goto P_0c04d7a8;
case 0x0c04d7aau: goto P_0c04d7aa;
case 0x0c04d7acu: goto P_0c04d7ac;
case 0x0c04d7aeu: goto P_0c04d7ae;
case 0x0c04d7b0u: goto P_0c04d7b0;
case 0x0c04d7b2u: goto P_0c04d7b2;
case 0x0c04d7b4u: goto P_0c04d7b4;
case 0x0c04d7b6u: goto P_0c04d7b6;
case 0x0c04d7b8u: goto P_0c04d7b8;
case 0x0c04d7bau: goto P_0c04d7ba;
case 0x0c04d7bcu: goto P_0c04d7bc;
case 0x0c04d7beu: goto P_0c04d7be;
case 0x0c04d7c0u: goto P_0c04d7c0;
case 0x0c04d7c2u: goto P_0c04d7c2;
case 0x0c04d7c4u: goto P_0c04d7c4;
case 0x0c04d7c6u: goto P_0c04d7c6;
case 0x0c04d7c8u: goto P_0c04d7c8;
case 0x0c04d7cau: goto P_0c04d7ca;
case 0x0c04d7ccu: goto P_0c04d7cc;
case 0x0c04d7ceu: goto P_0c04d7ce;
case 0x0c04d7d0u: goto P_0c04d7d0;
case 0x0c04d7d2u: goto P_0c04d7d2;
case 0x0c04d7d4u: goto P_0c04d7d4;
case 0x0c04d7d6u: goto P_0c04d7d6;
case 0x0c04d7d8u: goto P_0c04d7d8;
case 0x0c04d7dau: goto P_0c04d7da;
case 0x0c04d7dcu: goto P_0c04d7dc;
case 0x0c04d7deu: goto P_0c04d7de;
case 0x0c04d7e0u: goto P_0c04d7e0;
case 0x0c04d7e2u: goto P_0c04d7e2;
case 0x0c04d7e4u: goto P_0c04d7e4;
case 0x0c04d7e6u: goto P_0c04d7e6;
case 0x0c04d7e8u: goto P_0c04d7e8;
case 0x0c04d7eau: goto P_0c04d7ea;
case 0x0c04d7ecu: goto P_0c04d7ec;
case 0x0c04d7eeu: goto P_0c04d7ee;
case 0x0c04d7f0u: goto P_0c04d7f0;
case 0x0c04d7f2u: goto P_0c04d7f2;
case 0x0c04d7f4u: goto P_0c04d7f4;
case 0x0c04d7f6u: goto P_0c04d7f6;
case 0x0c04d7f8u: goto P_0c04d7f8;
case 0x0c04d7fau: goto P_0c04d7fa;
case 0x0c04d7fcu: goto P_0c04d7fc;
case 0x0c04d7feu: goto P_0c04d7fe;
case 0x0c04f0e2u: goto P_0c04f0e2;
case 0x0c04f0e4u: goto P_0c04f0e4;
case 0x0c04f0e6u: goto P_0c04f0e6;
case 0x0c04f0e8u: goto P_0c04f0e8;
case 0x0c04f0eau: goto P_0c04f0ea;
case 0x0c04f0ecu: goto P_0c04f0ec;
case 0x0c04f0eeu: goto P_0c04f0ee;
case 0x0c04f0f0u: goto P_0c04f0f0;
case 0x0c04f0f2u: goto P_0c04f0f2;
case 0x0c04f0f4u: goto P_0c04f0f4;
case 0x0c04f0f6u: goto P_0c04f0f6;
case 0x0c04f0f8u: goto P_0c04f0f8;
case 0x0c04f0fau: goto P_0c04f0fa;
case 0x0c04f0fcu: goto P_0c04f0fc;
case 0x0c04f0feu: goto P_0c04f0fe;
case 0x0c04f100u: goto P_0c04f100;
case 0x0c04f102u: goto P_0c04f102;
case 0x0c04f104u: goto P_0c04f104;
case 0x0c04f106u: goto P_0c04f106;
case 0x0c04f108u: goto P_0c04f108;
case 0x0c04f10au: goto P_0c04f10a;
case 0x0c04f10cu: goto P_0c04f10c;
case 0x0c04f10eu: goto P_0c04f10e;
case 0x0c04f110u: goto P_0c04f110;
case 0x0c04f112u: goto P_0c04f112;
case 0x0c04f114u: goto P_0c04f114;
case 0x0c04f116u: goto P_0c04f116;
case 0x0c04f118u: goto P_0c04f118;
case 0x0c04f11au: goto P_0c04f11a;
case 0x0c04f11cu: goto P_0c04f11c;
case 0x0c04f11eu: goto P_0c04f11e;
case 0x0c04f120u: goto P_0c04f120;
case 0x0c04f122u: goto P_0c04f122;
case 0x0c04f124u: goto P_0c04f124;
case 0x0c04f126u: goto P_0c04f126;
case 0x0c04f128u: goto P_0c04f128;
case 0x0c04f12au: goto P_0c04f12a;
case 0x0c04f12cu: goto P_0c04f12c;
case 0x0c04f12eu: goto P_0c04f12e;
case 0x0c04f130u: goto P_0c04f130;
case 0x0c04f14cu: goto P_0c04f14c;
case 0x0c04f14eu: goto P_0c04f14e;
case 0x0c04f150u: goto P_0c04f150;
case 0x0c04f152u: goto P_0c04f152;
case 0x0c04f154u: goto P_0c04f154;
case 0x0c04f156u: goto P_0c04f156;
case 0x0c04f158u: goto P_0c04f158;
case 0x0c04f15au: goto P_0c04f15a;
case 0x0c04f15cu: goto P_0c04f15c;
case 0x0c04f15eu: goto P_0c04f15e;
case 0x0c04f160u: goto P_0c04f160;
case 0x0c04f162u: goto P_0c04f162;
case 0x0c04f164u: goto P_0c04f164;
case 0x0c04f166u: goto P_0c04f166;
case 0x0c04f168u: goto P_0c04f168;
case 0x0c04f16au: goto P_0c04f16a;
case 0x0c04f16cu: goto P_0c04f16c;
case 0x0c04f16eu: goto P_0c04f16e;
case 0x0c04f170u: goto P_0c04f170;
case 0x0c04f172u: goto P_0c04f172;
case 0x0c04f174u: goto P_0c04f174;
case 0x0c04f176u: goto P_0c04f176;
case 0x0c04f178u: goto P_0c04f178;
case 0x0c04f17au: goto P_0c04f17a;
case 0x0c04f17cu: goto P_0c04f17c;
case 0x0c04f17eu: goto P_0c04f17e;
case 0x0c04f180u: goto P_0c04f180;
case 0x0c04f182u: goto P_0c04f182;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04d72e: /* original 4f22, guest PC 0x0c04d72e */
if(!s->budget--) { s->failed_pc=0x0c04d72eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04d730;
P_0c04d730: /* original 9b1b, guest PC 0x0c04d730 */
if(!s->budget--) { s->failed_pc=0x0c04d730u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d76au,2);
goto P_0c04d732;
P_0c04d732: /* original 4f12, guest PC 0x0c04d732 */
if(!s->budget--) { s->failed_pc=0x0c04d732u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04d734;
P_0c04d734: /* original 2ebf, guest PC 0x0c04d734 */
if(!s->budget--) { s->failed_pc=0x0c04d734u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[11]);
goto P_0c04d736;
P_0c04d736: /* original 7ffc, guest PC 0x0c04d736 */
if(!s->budget--) { s->failed_pc=0x0c04d736u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04d738;
P_0c04d738: /* original 0b1a, guest PC 0x0c04d738 */
if(!s->budget--) { s->failed_pc=0x0c04d738u; return 0; }
r[11]=r[19];
goto P_0c04d73a;
P_0c04d73a: /* original 6bbf, guest PC 0x0c04d73a */
if(!s->budget--) { s->failed_pc=0x0c04d73au; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c04d73c;
P_0c04d73c: /* original 2fb2, guest PC 0x0c04d73c */
if(!s->budget--) { s->failed_pc=0x0c04d73cu; return 0; }
write(ram,r[15],r[11],4);
goto P_0c04d73e;
P_0c04d73e: /* original d30c, guest PC 0x0c04d73e */
if(!s->budget--) { s->failed_pc=0x0c04d73eu; return 0; }
r[3]=read(ram,0x0c04d770u,4);
goto P_0c04d740;
P_0c04d740: /* original 2fe6, guest PC 0x0c04d740 */
if(!s->budget--) { s->failed_pc=0x0c04d740u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d742;
P_0c04d742: /* original d20f, guest PC 0x0c04d742 */
if(!s->budget--) { s->failed_pc=0x0c04d742u; return 0; }
r[2]=read(ram,0x0c04d780u,4);
goto P_0c04d744;
P_0c04d744: /* original 3b3c, guest PC 0x0c04d744 */
if(!s->budget--) { s->failed_pc=0x0c04d744u; return 0; }
r[11]+=r[3];
goto P_0c04d746;
P_0c04d746: /* original d10f, guest PC 0x0c04d746 */
if(!s->budget--) { s->failed_pc=0x0c04d746u; return 0; }
r[1]=read(ram,0x0c04d784u,4);
goto P_0c04d748;
P_0c04d748: /* original 410b, guest PC 0x0c04d748 */
if(!s->budget--) { s->failed_pc=0x0c04d748u; return 0; }
target=r[1];
r[16]=0x0c04d74cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d74cu) { target=s->pc; goto dispatch; }
goto P_0c04d74c;
P_0c04d74a: /* original 2f26, guest PC 0x0c04d74a */
if(!s->budget--) { s->failed_pc=0x0c04d74au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d74c;
P_0c04d74c: /* original 84b2, guest PC 0x0c04d74c */
if(!s->budget--) { s->failed_pc=0x0c04d74cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+2,1);
goto P_0c04d74e;
P_0c04d74e: /* original 2008, guest PC 0x0c04d74e */
if(!s->budget--) { s->failed_pc=0x0c04d74eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d750;
P_0c04d750: /* original 8d27, guest PC 0x0c04d750 */
if(!s->budget--) { s->failed_pc=0x0c04d750u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000008u;
if(cond) { goto P_0c04d7a2; }
goto P_0c04d754;
P_0c04d752: /* original 7f08, guest PC 0x0c04d752 */
if(!s->budget--) { s->failed_pc=0x0c04d752u; return 0; }
r[15]+=0x00000008u;
goto P_0c04d754;
P_0c04d754: /* original d20c, guest PC 0x0c04d754 */
if(!s->budget--) { s->failed_pc=0x0c04d754u; return 0; }
r[2]=read(ram,0x0c04d788u,4);
goto P_0c04d756;
P_0c04d756: /* original 420b, guest PC 0x0c04d756 */
if(!s->budget--) { s->failed_pc=0x0c04d756u; return 0; }
target=r[2];
r[16]=0x0c04d75au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d75au) { target=s->pc; goto dispatch; }
goto P_0c04d75a;
P_0c04d758: /* original 64e3, guest PC 0x0c04d758 */
if(!s->budget--) { s->failed_pc=0x0c04d758u; return 0; }
r[4]=r[14];
goto P_0c04d75a;
P_0c04d75a: /* original 2008, guest PC 0x0c04d75a */
if(!s->budget--) { s->failed_pc=0x0c04d75au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d75c;
P_0c04d75c: /* original 8b16, guest PC 0x0c04d75c */
if(!s->budget--) { s->failed_pc=0x0c04d75cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d78c; }
goto P_0c04d75e;
P_0c04d75e: /* original bbb6, guest PC 0x0c04d75e */
if(!s->budget--) { s->failed_pc=0x0c04d75eu; return 0; }
target=0x0c04ceceu; r[16]=0x0c04d762u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d762u) { target=s->pc; goto dispatch; }
goto P_0c04d762;
P_0c04d760: /* original 64e3, guest PC 0x0c04d760 */
if(!s->budget--) { s->failed_pc=0x0c04d760u; return 0; }
r[4]=r[14];
goto P_0c04d762;
P_0c04d762: /* original a01e, guest PC 0x0c04d762 */
if(!s->budget--) { s->failed_pc=0x0c04d762u; return 0; }
goto P_0c04d7a2;
P_0c04d764: /* original 0009, guest PC 0x0c04d764 */
if(!s->budget--) { s->failed_pc=0x0c04d764u; return 0; }
return vf3_matrix_family(0x0c04d766u,s,ram);
P_0c04d78c: /* original d33d, guest PC 0x0c04d78c */
if(!s->budget--) { s->failed_pc=0x0c04d78cu; return 0; }
r[3]=read(ram,0x0c04d884u,4);
goto P_0c04d78e;
P_0c04d78e: /* original 430b, guest PC 0x0c04d78e */
if(!s->budget--) { s->failed_pc=0x0c04d78eu; return 0; }
target=r[3];
r[16]=0x0c04d792u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d792u) { target=s->pc; goto dispatch; }
goto P_0c04d792;
P_0c04d790: /* original 64e3, guest PC 0x0c04d790 */
if(!s->budget--) { s->failed_pc=0x0c04d790u; return 0; }
r[4]=r[14];
goto P_0c04d792;
P_0c04d792: /* original 2008, guest PC 0x0c04d792 */
if(!s->budget--) { s->failed_pc=0x0c04d792u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d794;
P_0c04d794: /* original 8905, guest PC 0x0c04d794 */
if(!s->budget--) { s->failed_pc=0x0c04d794u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d7a2; }
goto P_0c04d796;
P_0c04d796: /* original 62f2, guest PC 0x0c04d796 */
if(!s->budget--) { s->failed_pc=0x0c04d796u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04d798;
P_0c04d798: /* original d33b, guest PC 0x0c04d798 */
if(!s->budget--) { s->failed_pc=0x0c04d798u; return 0; }
r[3]=read(ram,0x0c04d888u,4);
goto P_0c04d79a;
P_0c04d79a: /* original 323c, guest PC 0x0c04d79a */
if(!s->budget--) { s->failed_pc=0x0c04d79au; return 0; }
r[2]+=r[3];
goto P_0c04d79c;
P_0c04d79c: /* original 8428, guest PC 0x0c04d79c */
if(!s->budget--) { s->failed_pc=0x0c04d79cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04d79e;
P_0c04d79e: /* original 2008, guest PC 0x0c04d79e */
if(!s->budget--) { s->failed_pc=0x0c04d79eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d7a0;
P_0c04d7a0: /* original 8b02, guest PC 0x0c04d7a0 */
if(!s->budget--) { s->failed_pc=0x0c04d7a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d7a8; }
goto P_0c04d7a2;
P_0c04d7a2: /* original 906b, guest PC 0x0c04d7a2 */
if(!s->budget--) { s->failed_pc=0x0c04d7a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d87cu,2);
goto P_0c04d7a4;
P_0c04d7a4: /* original a023, guest PC 0x0c04d7a4 */
if(!s->budget--) { s->failed_pc=0x0c04d7a4u; return 0; }
goto P_0c04d7ee;
P_0c04d7a6: /* original 0009, guest PC 0x0c04d7a6 */
if(!s->budget--) { s->failed_pc=0x0c04d7a6u; return 0; }
goto P_0c04d7a8;
P_0c04d7a8: /* original d338, guest PC 0x0c04d7a8 */
if(!s->budget--) { s->failed_pc=0x0c04d7a8u; return 0; }
r[3]=read(ram,0x0c04d88cu,4);
goto P_0c04d7aa;
P_0c04d7aa: /* original 430b, guest PC 0x0c04d7aa */
if(!s->budget--) { s->failed_pc=0x0c04d7aau; return 0; }
target=r[3];
r[16]=0x0c04d7aeu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d7aeu) { target=s->pc; goto dispatch; }
goto P_0c04d7ae;
P_0c04d7ac: /* original 64e3, guest PC 0x0c04d7ac */
if(!s->budget--) { s->failed_pc=0x0c04d7acu; return 0; }
r[4]=r[14];
goto P_0c04d7ae;
P_0c04d7ae: /* original 4011, guest PC 0x0c04d7ae */
if(!s->budget--) { s->failed_pc=0x0c04d7aeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04d7b0;
P_0c04d7b0: /* original 8902, guest PC 0x0c04d7b0 */
if(!s->budget--) { s->failed_pc=0x0c04d7b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d7b8; }
goto P_0c04d7b2;
P_0c04d7b2: /* original 9064, guest PC 0x0c04d7b2 */
if(!s->budget--) { s->failed_pc=0x0c04d7b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d87eu,2);
goto P_0c04d7b4;
P_0c04d7b4: /* original a01b, guest PC 0x0c04d7b4 */
if(!s->budget--) { s->failed_pc=0x0c04d7b4u; return 0; }
goto P_0c04d7ee;
P_0c04d7b6: /* original 0009, guest PC 0x0c04d7b6 */
if(!s->budget--) { s->failed_pc=0x0c04d7b6u; return 0; }
goto P_0c04d7b8;
P_0c04d7b8: /* original da35, guest PC 0x0c04d7b8 */
if(!s->budget--) { s->failed_pc=0x0c04d7b8u; return 0; }
r[10]=read(ram,0x0c04d890u,4);
goto P_0c04d7ba;
P_0c04d7ba: /* original e400, guest PC 0x0c04d7ba */
if(!s->budget--) { s->failed_pc=0x0c04d7bau; return 0; }
r[4]=0x00000000u;
goto P_0c04d7bc;
P_0c04d7bc: /* original 6c43, guest PC 0x0c04d7bc */
if(!s->budget--) { s->failed_pc=0x0c04d7bcu; return 0; }
r[12]=r[4];
goto P_0c04d7be;
P_0c04d7be: /* original a009, guest PC 0x0c04d7be */
if(!s->budget--) { s->failed_pc=0x0c04d7beu; return 0; }
r[13]=r[4];
goto P_0c04d7d4;
P_0c04d7c0: /* original 6d43, guest PC 0x0c04d7c0 */
if(!s->budget--) { s->failed_pc=0x0c04d7c0u; return 0; }
r[13]=r[4];
goto P_0c04d7c2;
P_0c04d7c2: /* original d234, guest PC 0x0c04d7c2 */
if(!s->budget--) { s->failed_pc=0x0c04d7c2u; return 0; }
r[2]=read(ram,0x0c04d894u,4);
goto P_0c04d7c4;
P_0c04d7c4: /* original 65d3, guest PC 0x0c04d7c4 */
if(!s->budget--) { s->failed_pc=0x0c04d7c4u; return 0; }
r[5]=r[13];
goto P_0c04d7c6;
P_0c04d7c6: /* original 420b, guest PC 0x0c04d7c6 */
if(!s->budget--) { s->failed_pc=0x0c04d7c6u; return 0; }
target=r[2];
r[16]=0x0c04d7cau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d7cau) { target=s->pc; goto dispatch; }
goto P_0c04d7ca;
P_0c04d7c8: /* original 64e3, guest PC 0x0c04d7c8 */
if(!s->budget--) { s->failed_pc=0x0c04d7c8u; return 0; }
r[4]=r[14];
goto P_0c04d7ca;
P_0c04d7ca: /* original 600d, guest PC 0x0c04d7ca */
if(!s->budget--) { s->failed_pc=0x0c04d7cau; return 0; }
r[0]=r[0]&65535u;
goto P_0c04d7cc;
P_0c04d7cc: /* original 30a0, guest PC 0x0c04d7cc */
if(!s->budget--) { s->failed_pc=0x0c04d7ccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[10])!=0);
goto P_0c04d7ce;
P_0c04d7ce: /* original 8f01, guest PC 0x0c04d7ce */
if(!s->budget--) { s->failed_pc=0x0c04d7ceu; return 0; }
cond=r[17]&1u;
r[13]+=0x00000001u;
if(!cond) { goto P_0c04d7d4; }
goto P_0c04d7d2;
P_0c04d7d0: /* original 7d01, guest PC 0x0c04d7d0 */
if(!s->budget--) { s->failed_pc=0x0c04d7d0u; return 0; }
r[13]+=0x00000001u;
goto P_0c04d7d2;
P_0c04d7d2: /* original 7c01, guest PC 0x0c04d7d2 */
if(!s->budget--) { s->failed_pc=0x0c04d7d2u; return 0; }
r[12]+=0x00000001u;
goto P_0c04d7d4;
P_0c04d7d4: /* original 54b7, guest PC 0x0c04d7d4 */
if(!s->budget--) { s->failed_pc=0x0c04d7d4u; return 0; }
r[4]=read(ram,r[11]+28,4);
goto P_0c04d7d6;
P_0c04d7d6: /* original 524b, guest PC 0x0c04d7d6 */
if(!s->budget--) { s->failed_pc=0x0c04d7d6u; return 0; }
r[2]=read(ram,r[4]+44,4);
goto P_0c04d7d8;
P_0c04d7d8: /* original 5344, guest PC 0x0c04d7d8 */
if(!s->budget--) { s->failed_pc=0x0c04d7d8u; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c04d7da;
P_0c04d7da: /* original 7201, guest PC 0x0c04d7da */
if(!s->budget--) { s->failed_pc=0x0c04d7dau; return 0; }
r[2]+=0x00000001u;
goto P_0c04d7dc;
P_0c04d7dc: /* original 0327, guest PC 0x0c04d7dc */
if(!s->budget--) { s->failed_pc=0x0c04d7dcu; return 0; }
r[19]=r[3]*r[2];
goto P_0c04d7de;
P_0c04d7de: /* original e300, guest PC 0x0c04d7de */
if(!s->budget--) { s->failed_pc=0x0c04d7deu; return 0; }
r[3]=0x00000000u;
goto P_0c04d7e0;
P_0c04d7e0: /* original 021a, guest PC 0x0c04d7e0 */
if(!s->budget--) { s->failed_pc=0x0c04d7e0u; return 0; }
r[2]=r[19];
goto P_0c04d7e2;
P_0c04d7e2: /* original 3327, guest PC 0x0c04d7e2 */
if(!s->budget--) { s->failed_pc=0x0c04d7e2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c04d7e4;
P_0c04d7e4: /* original 323e, guest PC 0x0c04d7e4 */
if(!s->budget--) { s->failed_pc=0x0c04d7e4u; return 0; }
wide=(uint64_t)r[2]+r[3]+(r[17]&1u); r[2]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c04d7e6;
P_0c04d7e6: /* original 4221, guest PC 0x0c04d7e6 */
if(!s->budget--) { s->failed_pc=0x0c04d7e6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]=(uint32_t)((int32_t)r[2]>>1);
goto P_0c04d7e8;
P_0c04d7e8: /* original 3d23, guest PC 0x0c04d7e8 */
if(!s->budget--) { s->failed_pc=0x0c04d7e8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[2])!=0);
goto P_0c04d7ea;
P_0c04d7ea: /* original 8bea, guest PC 0x0c04d7ea */
if(!s->budget--) { s->failed_pc=0x0c04d7eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d7c2; }
goto P_0c04d7ec;
P_0c04d7ec: /* original 60c3, guest PC 0x0c04d7ec */
if(!s->budget--) { s->failed_pc=0x0c04d7ecu; return 0; }
r[0]=r[12];
goto P_0c04d7ee;
P_0c04d7ee: /* original 7f04, guest PC 0x0c04d7ee */
if(!s->budget--) { s->failed_pc=0x0c04d7eeu; return 0; }
r[15]+=0x00000004u;
goto P_0c04d7f0;
P_0c04d7f0: /* original 4f16, guest PC 0x0c04d7f0 */
if(!s->budget--) { s->failed_pc=0x0c04d7f0u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d7f2;
P_0c04d7f2: /* original 4f26, guest PC 0x0c04d7f2 */
if(!s->budget--) { s->failed_pc=0x0c04d7f2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d7f4;
P_0c04d7f4: /* original 6af6, guest PC 0x0c04d7f4 */
if(!s->budget--) { s->failed_pc=0x0c04d7f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04d7f6;
P_0c04d7f6: /* original 6bf6, guest PC 0x0c04d7f6 */
if(!s->budget--) { s->failed_pc=0x0c04d7f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04d7f8;
P_0c04d7f8: /* original 6cf6, guest PC 0x0c04d7f8 */
if(!s->budget--) { s->failed_pc=0x0c04d7f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04d7fa;
P_0c04d7fa: /* original 6df6, guest PC 0x0c04d7fa */
if(!s->budget--) { s->failed_pc=0x0c04d7fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04d7fc;
P_0c04d7fc: /* original 000b, guest PC 0x0c04d7fc */
if(!s->budget--) { s->failed_pc=0x0c04d7fcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04d7fe: /* original 6ef6, guest PC 0x0c04d7fe */
if(!s->budget--) { s->failed_pc=0x0c04d7feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04d800u,s,ram);
P_0c04f0e2: /* original 4f22, guest PC 0x0c04f0e2 */
if(!s->budget--) { s->failed_pc=0x0c04f0e2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f0e4;
P_0c04f0e4: /* original 4f12, guest PC 0x0c04f0e4 */
if(!s->budget--) { s->failed_pc=0x0c04f0e4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04f0e6;
P_0c04f0e6: /* original 7ff4, guest PC 0x0c04f0e6 */
if(!s->budget--) { s->failed_pc=0x0c04f0e6u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c04f0e8;
P_0c04f0e8: /* original 1f51, guest PC 0x0c04f0e8 */
if(!s->budget--) { s->failed_pc=0x0c04f0e8u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c04f0ea;
P_0c04f0ea: /* original 9322, guest PC 0x0c04f0ea */
if(!s->budget--) { s->failed_pc=0x0c04f0eau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f132u,2);
goto P_0c04f0ec;
P_0c04f0ec: /* original 2e3f, guest PC 0x0c04f0ec */
if(!s->budget--) { s->failed_pc=0x0c04f0ecu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c04f0ee;
P_0c04f0ee: /* original 031a, guest PC 0x0c04f0ee */
if(!s->budget--) { s->failed_pc=0x0c04f0eeu; return 0; }
r[3]=r[19];
goto P_0c04f0f0;
P_0c04f0f0: /* original 633f, guest PC 0x0c04f0f0 */
if(!s->budget--) { s->failed_pc=0x0c04f0f0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04f0f2;
P_0c04f0f2: /* original 1f32, guest PC 0x0c04f0f2 */
if(!s->budget--) { s->failed_pc=0x0c04f0f2u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c04f0f4;
P_0c04f0f4: /* original d210, guest PC 0x0c04f0f4 */
if(!s->budget--) { s->failed_pc=0x0c04f0f4u; return 0; }
r[2]=read(ram,0x0c04f138u,4);
goto P_0c04f0f6;
P_0c04f0f6: /* original 332c, guest PC 0x0c04f0f6 */
if(!s->budget--) { s->failed_pc=0x0c04f0f6u; return 0; }
r[3]+=r[2];
goto P_0c04f0f8;
P_0c04f0f8: /* original 6133, guest PC 0x0c04f0f8 */
if(!s->budget--) { s->failed_pc=0x0c04f0f8u; return 0; }
r[1]=r[3];
goto P_0c04f0fa;
P_0c04f0fa: /* original 2f32, guest PC 0x0c04f0fa */
if(!s->budget--) { s->failed_pc=0x0c04f0fau; return 0; }
write(ram,r[15],r[3],4);
goto P_0c04f0fc;
P_0c04f0fc: /* original 8412, guest PC 0x0c04f0fc */
if(!s->budget--) { s->failed_pc=0x0c04f0fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+2,1);
goto P_0c04f0fe;
P_0c04f0fe: /* original 2008, guest PC 0x0c04f0fe */
if(!s->budget--) { s->failed_pc=0x0c04f0feu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04f100;
P_0c04f100: /* original 8914, guest PC 0x0c04f100 */
if(!s->budget--) { s->failed_pc=0x0c04f100u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f12c; }
goto P_0c04f102;
P_0c04f102: /* original d20e, guest PC 0x0c04f102 */
if(!s->budget--) { s->failed_pc=0x0c04f102u; return 0; }
r[2]=read(ram,0x0c04f13cu,4);
goto P_0c04f104;
P_0c04f104: /* original 420b, guest PC 0x0c04f104 */
if(!s->budget--) { s->failed_pc=0x0c04f104u; return 0; }
target=r[2];
r[16]=0x0c04f108u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f108u) { target=s->pc; goto dispatch; }
goto P_0c04f108;
P_0c04f106: /* original 64e3, guest PC 0x0c04f106 */
if(!s->budget--) { s->failed_pc=0x0c04f106u; return 0; }
r[4]=r[14];
goto P_0c04f108;
P_0c04f108: /* original 2008, guest PC 0x0c04f108 */
if(!s->budget--) { s->failed_pc=0x0c04f108u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04f10a;
P_0c04f10a: /* original 8b04, guest PC 0x0c04f10a */
if(!s->budget--) { s->failed_pc=0x0c04f10au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f116; }
goto P_0c04f10c;
P_0c04f10c: /* original d20c, guest PC 0x0c04f10c */
if(!s->budget--) { s->failed_pc=0x0c04f10cu; return 0; }
r[2]=read(ram,0x0c04f140u,4);
goto P_0c04f10e;
P_0c04f10e: /* original 420b, guest PC 0x0c04f10e */
if(!s->budget--) { s->failed_pc=0x0c04f10eu; return 0; }
target=r[2];
r[16]=0x0c04f112u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f112u) { target=s->pc; goto dispatch; }
goto P_0c04f112;
P_0c04f110: /* original 64e3, guest PC 0x0c04f110 */
if(!s->budget--) { s->failed_pc=0x0c04f110u; return 0; }
r[4]=r[14];
goto P_0c04f112;
P_0c04f112: /* original a00b, guest PC 0x0c04f112 */
if(!s->budget--) { s->failed_pc=0x0c04f112u; return 0; }
goto P_0c04f12c;
P_0c04f114: /* original 0009, guest PC 0x0c04f114 */
if(!s->budget--) { s->failed_pc=0x0c04f114u; return 0; }
goto P_0c04f116;
P_0c04f116: /* original d30b, guest PC 0x0c04f116 */
if(!s->budget--) { s->failed_pc=0x0c04f116u; return 0; }
r[3]=read(ram,0x0c04f144u,4);
goto P_0c04f118;
P_0c04f118: /* original 430b, guest PC 0x0c04f118 */
if(!s->budget--) { s->failed_pc=0x0c04f118u; return 0; }
target=r[3];
r[16]=0x0c04f11cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f11cu) { target=s->pc; goto dispatch; }
goto P_0c04f11c;
P_0c04f11a: /* original 64e3, guest PC 0x0c04f11a */
if(!s->budget--) { s->failed_pc=0x0c04f11au; return 0; }
r[4]=r[14];
goto P_0c04f11c;
P_0c04f11c: /* original 2008, guest PC 0x0c04f11c */
if(!s->budget--) { s->failed_pc=0x0c04f11cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04f11e;
P_0c04f11e: /* original 8905, guest PC 0x0c04f11e */
if(!s->budget--) { s->failed_pc=0x0c04f11eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f12c; }
goto P_0c04f120;
P_0c04f120: /* original 52f2, guest PC 0x0c04f120 */
if(!s->budget--) { s->failed_pc=0x0c04f120u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c04f122;
P_0c04f122: /* original d305, guest PC 0x0c04f122 */
if(!s->budget--) { s->failed_pc=0x0c04f122u; return 0; }
r[3]=read(ram,0x0c04f138u,4);
goto P_0c04f124;
P_0c04f124: /* original 323c, guest PC 0x0c04f124 */
if(!s->budget--) { s->failed_pc=0x0c04f124u; return 0; }
r[2]+=r[3];
goto P_0c04f126;
P_0c04f126: /* original 8428, guest PC 0x0c04f126 */
if(!s->budget--) { s->failed_pc=0x0c04f126u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04f128;
P_0c04f128: /* original 2008, guest PC 0x0c04f128 */
if(!s->budget--) { s->failed_pc=0x0c04f128u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04f12a;
P_0c04f12a: /* original 8b0f, guest PC 0x0c04f12a */
if(!s->budget--) { s->failed_pc=0x0c04f12au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f14c; }
goto P_0c04f12c;
P_0c04f12c: /* original 9002, guest PC 0x0c04f12c */
if(!s->budget--) { s->failed_pc=0x0c04f12cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f134u,2);
goto P_0c04f12e;
P_0c04f12e: /* original a024, guest PC 0x0c04f12e */
if(!s->budget--) { s->failed_pc=0x0c04f12eu; return 0; }
goto P_0c04f17a;
P_0c04f130: /* original 0009, guest PC 0x0c04f130 */
if(!s->budget--) { s->failed_pc=0x0c04f130u; return 0; }
return vf3_matrix_family(0x0c04f132u,s,ram);
P_0c04f14c: /* original d33b, guest PC 0x0c04f14c */
if(!s->budget--) { s->failed_pc=0x0c04f14cu; return 0; }
r[3]=read(ram,0x0c04f23cu,4);
goto P_0c04f14e;
P_0c04f14e: /* original 430b, guest PC 0x0c04f14e */
if(!s->budget--) { s->failed_pc=0x0c04f14eu; return 0; }
target=r[3];
r[16]=0x0c04f152u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f152u) { target=s->pc; goto dispatch; }
goto P_0c04f152;
P_0c04f150: /* original 64e3, guest PC 0x0c04f150 */
if(!s->budget--) { s->failed_pc=0x0c04f150u; return 0; }
r[4]=r[14];
goto P_0c04f152;
P_0c04f152: /* original 4011, guest PC 0x0c04f152 */
if(!s->budget--) { s->failed_pc=0x0c04f152u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04f154;
P_0c04f154: /* original 8902, guest PC 0x0c04f154 */
if(!s->budget--) { s->failed_pc=0x0c04f154u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f15c; }
goto P_0c04f156;
P_0c04f156: /* original 906d, guest PC 0x0c04f156 */
if(!s->budget--) { s->failed_pc=0x0c04f156u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f234u,2);
goto P_0c04f158;
P_0c04f158: /* original a00f, guest PC 0x0c04f158 */
if(!s->budget--) { s->failed_pc=0x0c04f158u; return 0; }
goto P_0c04f17a;
P_0c04f15a: /* original 0009, guest PC 0x0c04f15a */
if(!s->budget--) { s->failed_pc=0x0c04f15au; return 0; }
goto P_0c04f15c;
P_0c04f15c: /* original 64f2, guest PC 0x0c04f15c */
if(!s->budget--) { s->failed_pc=0x0c04f15cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c04f15e;
P_0c04f15e: /* original e500, guest PC 0x0c04f15e */
if(!s->budget--) { s->failed_pc=0x0c04f15eu; return 0; }
r[5]=0x00000000u;
goto P_0c04f160;
P_0c04f160: /* original 5448, guest PC 0x0c04f160 */
if(!s->budget--) { s->failed_pc=0x0c04f160u; return 0; }
r[4]=read(ram,r[4]+32,4);
goto P_0c04f162;
P_0c04f162: /* original 7410, guest PC 0x0c04f162 */
if(!s->budget--) { s->failed_pc=0x0c04f162u; return 0; }
r[4]+=0x00000010u;
goto P_0c04f164;
P_0c04f164: /* original a006, guest PC 0x0c04f164 */
if(!s->budget--) { s->failed_pc=0x0c04f164u; return 0; }
r[6]=0x00000020u;
goto P_0c04f174;
P_0c04f166: /* original e620, guest PC 0x0c04f166 */
if(!s->budget--) { s->failed_pc=0x0c04f166u; return 0; }
r[6]=0x00000020u;
goto P_0c04f168;
P_0c04f168: /* original 52f1, guest PC 0x0c04f168 */
if(!s->budget--) { s->failed_pc=0x0c04f168u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c04f16a;
P_0c04f16a: /* original 7501, guest PC 0x0c04f16a */
if(!s->budget--) { s->failed_pc=0x0c04f16au; return 0; }
r[5]+=0x00000001u;
goto P_0c04f16c;
P_0c04f16c: /* original 7201, guest PC 0x0c04f16c */
if(!s->budget--) { s->failed_pc=0x0c04f16cu; return 0; }
r[2]+=0x00000001u;
goto P_0c04f16e;
P_0c04f16e: /* original 1f21, guest PC 0x0c04f16e */
if(!s->budget--) { s->failed_pc=0x0c04f16eu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c04f170;
P_0c04f170: /* original 6344, guest PC 0x0c04f170 */
if(!s->budget--) { s->failed_pc=0x0c04f170u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[3]=tmp;
goto P_0c04f172;
P_0c04f172: /* original 2234, guest PC 0x0c04f172 */
if(!s->budget--) { s->failed_pc=0x0c04f172u; return 0; }
tmp=r[3]; r[2]-=1; write(ram,r[2],tmp,1);
goto P_0c04f174;
P_0c04f174: /* original 3563, guest PC 0x0c04f174 */
if(!s->budget--) { s->failed_pc=0x0c04f174u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c04f176;
P_0c04f176: /* original 8bf7, guest PC 0x0c04f176 */
if(!s->budget--) { s->failed_pc=0x0c04f176u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f168; }
goto P_0c04f178;
P_0c04f178: /* original e000, guest PC 0x0c04f178 */
if(!s->budget--) { s->failed_pc=0x0c04f178u; return 0; }
r[0]=0x00000000u;
goto P_0c04f17a;
P_0c04f17a: /* original 7f0c, guest PC 0x0c04f17a */
if(!s->budget--) { s->failed_pc=0x0c04f17au; return 0; }
r[15]+=0x0000000cu;
goto P_0c04f17c;
P_0c04f17c: /* original 4f16, guest PC 0x0c04f17c */
if(!s->budget--) { s->failed_pc=0x0c04f17cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f17e;
P_0c04f17e: /* original 4f26, guest PC 0x0c04f17e */
if(!s->budget--) { s->failed_pc=0x0c04f17eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f180;
P_0c04f180: /* original 000b, guest PC 0x0c04f180 */
if(!s->budget--) { s->failed_pc=0x0c04f180u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f182: /* original 6ef6, guest PC 0x0c04f182 */
if(!s->budget--) { s->failed_pc=0x0c04f182u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04f184u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c04d72eu,0x0c04d730u,0x0c04d732u,0x0c04d734u,0x0c04d736u,0x0c04d738u,0x0c04d73au,0x0c04d73cu,0x0c04d73eu,0x0c04d740u,0x0c04d742u,0x0c04d744u,0x0c04d746u,0x0c04d748u,0x0c04d74au,0x0c04d74cu,
0x0c04d74eu,0x0c04d750u,0x0c04d752u,0x0c04d754u,0x0c04d756u,0x0c04d758u,0x0c04d75au,0x0c04d75cu,0x0c04d75eu,0x0c04d760u,0x0c04d762u,0x0c04d764u,0x0c04d78cu,0x0c04d78eu,0x0c04d790u,0x0c04d792u,
0x0c04d794u,0x0c04d796u,0x0c04d798u,0x0c04d79au,0x0c04d79cu,0x0c04d79eu,0x0c04d7a0u,0x0c04d7a2u,0x0c04d7a4u,0x0c04d7a6u,0x0c04d7a8u,0x0c04d7aau,0x0c04d7acu,0x0c04d7aeu,0x0c04d7b0u,0x0c04d7b2u,
0x0c04d7b4u,0x0c04d7b6u,0x0c04d7b8u,0x0c04d7bau,0x0c04d7bcu,0x0c04d7beu,0x0c04d7c0u,0x0c04d7c2u,0x0c04d7c4u,0x0c04d7c6u,0x0c04d7c8u,0x0c04d7cau,0x0c04d7ccu,0x0c04d7ceu,0x0c04d7d0u,0x0c04d7d2u,
0x0c04d7d4u,0x0c04d7d6u,0x0c04d7d8u,0x0c04d7dau,0x0c04d7dcu,0x0c04d7deu,0x0c04d7e0u,0x0c04d7e2u,0x0c04d7e4u,0x0c04d7e6u,0x0c04d7e8u,0x0c04d7eau,0x0c04d7ecu,0x0c04d7eeu,0x0c04d7f0u,0x0c04d7f2u,
0x0c04d7f4u,0x0c04d7f6u,0x0c04d7f8u,0x0c04d7fau,0x0c04d7fcu,0x0c04d7feu,0x0c04f0e2u,0x0c04f0e4u,0x0c04f0e6u,0x0c04f0e8u,0x0c04f0eau,0x0c04f0ecu,0x0c04f0eeu,0x0c04f0f0u,0x0c04f0f2u,0x0c04f0f4u,
0x0c04f0f6u,0x0c04f0f8u,0x0c04f0fau,0x0c04f0fcu,0x0c04f0feu,0x0c04f100u,0x0c04f102u,0x0c04f104u,0x0c04f106u,0x0c04f108u,0x0c04f10au,0x0c04f10cu,0x0c04f10eu,0x0c04f110u,0x0c04f112u,0x0c04f114u,
0x0c04f116u,0x0c04f118u,0x0c04f11au,0x0c04f11cu,0x0c04f11eu,0x0c04f120u,0x0c04f122u,0x0c04f124u,0x0c04f126u,0x0c04f128u,0x0c04f12au,0x0c04f12cu,0x0c04f12eu,0x0c04f130u,0x0c04f14cu,0x0c04f14eu,
0x0c04f150u,0x0c04f152u,0x0c04f154u,0x0c04f156u,0x0c04f158u,0x0c04f15au,0x0c04f15cu,0x0c04f15eu,0x0c04f160u,0x0c04f162u,0x0c04f164u,0x0c04f166u,0x0c04f168u,0x0c04f16au,0x0c04f16cu,0x0c04f16eu,
0x0c04f170u,0x0c04f172u,0x0c04f174u,0x0c04f176u,0x0c04f178u,0x0c04f17au,0x0c04f17cu,0x0c04f17eu,0x0c04f180u,0x0c04f182u,
};
int vf3_object_pool_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
