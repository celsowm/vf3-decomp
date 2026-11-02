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
int vf3_away_batch5_adapter_19(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04f74eu: goto P_0c04f74e;
case 0x0c04f750u: goto P_0c04f750;
case 0x0c04f752u: goto P_0c04f752;
case 0x0c04f754u: goto P_0c04f754;
case 0x0c04f756u: goto P_0c04f756;
case 0x0c04f758u: goto P_0c04f758;
case 0x0c04f75au: goto P_0c04f75a;
case 0x0c04f75cu: goto P_0c04f75c;
case 0x0c04f75eu: goto P_0c04f75e;
case 0x0c04f760u: goto P_0c04f760;
case 0x0c04f762u: goto P_0c04f762;
case 0x0c04f764u: goto P_0c04f764;
case 0x0c04f766u: goto P_0c04f766;
case 0x0c04f768u: goto P_0c04f768;
case 0x0c04f76au: goto P_0c04f76a;
case 0x0c04f76cu: goto P_0c04f76c;
case 0x0c04f76eu: goto P_0c04f76e;
case 0x0c04f770u: goto P_0c04f770;
case 0x0c04f772u: goto P_0c04f772;
case 0x0c04f774u: goto P_0c04f774;
case 0x0c04f776u: goto P_0c04f776;
case 0x0c04f778u: goto P_0c04f778;
case 0x0c04f77au: goto P_0c04f77a;
case 0x0c04f77cu: goto P_0c04f77c;
case 0x0c04f77eu: goto P_0c04f77e;
case 0x0c04f780u: goto P_0c04f780;
case 0x0c04f782u: goto P_0c04f782;
case 0x0c04f784u: goto P_0c04f784;
case 0x0c04f786u: goto P_0c04f786;
case 0x0c04f788u: goto P_0c04f788;
case 0x0c04f78au: goto P_0c04f78a;
case 0x0c04f78cu: goto P_0c04f78c;
case 0x0c04f78eu: goto P_0c04f78e;
case 0x0c04f790u: goto P_0c04f790;
case 0x0c04f792u: goto P_0c04f792;
case 0x0c04f794u: goto P_0c04f794;
case 0x0c04f796u: goto P_0c04f796;
case 0x0c04f798u: goto P_0c04f798;
case 0x0c04f79au: goto P_0c04f79a;
case 0x0c04f79cu: goto P_0c04f79c;
case 0x0c04f79eu: goto P_0c04f79e;
case 0x0c04f7a0u: goto P_0c04f7a0;
case 0x0c04f7a2u: goto P_0c04f7a2;
case 0x0c04f7a4u: goto P_0c04f7a4;
case 0x0c04f7a6u: goto P_0c04f7a6;
case 0x0c04f7a8u: goto P_0c04f7a8;
case 0x0c04f7aau: goto P_0c04f7aa;
case 0x0c04f7acu: goto P_0c04f7ac;
case 0x0c04f7aeu: goto P_0c04f7ae;
case 0x0c04f7b0u: goto P_0c04f7b0;
case 0x0c04f7b2u: goto P_0c04f7b2;
case 0x0c04f7b4u: goto P_0c04f7b4;
case 0x0c04f7b6u: goto P_0c04f7b6;
case 0x0c04f7b8u: goto P_0c04f7b8;
case 0x0c04f7bau: goto P_0c04f7ba;
case 0x0c04f7bcu: goto P_0c04f7bc;
case 0x0c04f7beu: goto P_0c04f7be;
case 0x0c04f7c0u: goto P_0c04f7c0;
case 0x0c04f7c2u: goto P_0c04f7c2;
case 0x0c04f7c4u: goto P_0c04f7c4;
case 0x0c04f7c6u: goto P_0c04f7c6;
case 0x0c04f7c8u: goto P_0c04f7c8;
case 0x0c04f7cau: goto P_0c04f7ca;
case 0x0c04f7ccu: goto P_0c04f7cc;
case 0x0c04f7e8u: goto P_0c04f7e8;
case 0x0c04f7eau: goto P_0c04f7ea;
case 0x0c04f7ecu: goto P_0c04f7ec;
case 0x0c04f7eeu: goto P_0c04f7ee;
case 0x0c04f7f0u: goto P_0c04f7f0;
case 0x0c04f7f2u: goto P_0c04f7f2;
case 0x0c04f7f4u: goto P_0c04f7f4;
case 0x0c04f7f6u: goto P_0c04f7f6;
case 0x0c04f7f8u: goto P_0c04f7f8;
case 0x0c04f7fau: goto P_0c04f7fa;
case 0x0c04f7fcu: goto P_0c04f7fc;
case 0x0c04f7feu: goto P_0c04f7fe;
case 0x0c04f800u: goto P_0c04f800;
case 0x0c04f802u: goto P_0c04f802;
case 0x0c04f804u: goto P_0c04f804;
case 0x0c04f806u: goto P_0c04f806;
case 0x0c04f808u: goto P_0c04f808;
case 0x0c04f80au: goto P_0c04f80a;
case 0x0c04f80cu: goto P_0c04f80c;
case 0x0c04f80eu: goto P_0c04f80e;
case 0x0c04f810u: goto P_0c04f810;
case 0x0c04f812u: goto P_0c04f812;
case 0x0c04f814u: goto P_0c04f814;
case 0x0c04f816u: goto P_0c04f816;
case 0x0c04f818u: goto P_0c04f818;
case 0x0c04f81au: goto P_0c04f81a;
case 0x0c04f81cu: goto P_0c04f81c;
case 0x0c04f81eu: goto P_0c04f81e;
case 0x0c04f820u: goto P_0c04f820;
case 0x0c04f822u: goto P_0c04f822;
case 0x0c04f824u: goto P_0c04f824;
case 0x0c04f826u: goto P_0c04f826;
case 0x0c04f828u: goto P_0c04f828;
case 0x0c04f82au: goto P_0c04f82a;
case 0x0c04f82cu: goto P_0c04f82c;
case 0x0c04f82eu: goto P_0c04f82e;
case 0x0c04f830u: goto P_0c04f830;
case 0x0c04f832u: goto P_0c04f832;
case 0x0c04f834u: goto P_0c04f834;
case 0x0c04f836u: goto P_0c04f836;
case 0x0c04f838u: goto P_0c04f838;
case 0x0c04f83au: goto P_0c04f83a;
case 0x0c04f83cu: goto P_0c04f83c;
case 0x0c04f83eu: goto P_0c04f83e;
case 0x0c04f840u: goto P_0c04f840;
case 0x0c04f842u: goto P_0c04f842;
case 0x0c04f844u: goto P_0c04f844;
case 0x0c04f846u: goto P_0c04f846;
case 0x0c04f848u: goto P_0c04f848;
case 0x0c04f84au: goto P_0c04f84a;
case 0x0c04f84cu: goto P_0c04f84c;
case 0x0c04f84eu: goto P_0c04f84e;
case 0x0c04f850u: goto P_0c04f850;
case 0x0c04f852u: goto P_0c04f852;
case 0x0c04f854u: goto P_0c04f854;
case 0x0c04f856u: goto P_0c04f856;
case 0x0c04f858u: goto P_0c04f858;
case 0x0c04f85au: goto P_0c04f85a;
case 0x0c04f85cu: goto P_0c04f85c;
case 0x0c04f85eu: goto P_0c04f85e;
case 0x0c04f860u: goto P_0c04f860;
case 0x0c04f862u: goto P_0c04f862;
case 0x0c04f864u: goto P_0c04f864;
case 0x0c04f866u: goto P_0c04f866;
case 0x0c04f868u: goto P_0c04f868;
case 0x0c04f86au: goto P_0c04f86a;
case 0x0c04f86cu: goto P_0c04f86c;
case 0x0c04f86eu: goto P_0c04f86e;
case 0x0c04f870u: goto P_0c04f870;
case 0x0c04f872u: goto P_0c04f872;
case 0x0c04f874u: goto P_0c04f874;
case 0x0c04f876u: goto P_0c04f876;
case 0x0c04f878u: goto P_0c04f878;
case 0x0c04f87au: goto P_0c04f87a;
case 0x0c04f87cu: goto P_0c04f87c;
case 0x0c04f87eu: goto P_0c04f87e;
case 0x0c04f880u: goto P_0c04f880;
case 0x0c04f882u: goto P_0c04f882;
case 0x0c04f884u: goto P_0c04f884;
case 0x0c04f886u: goto P_0c04f886;
case 0x0c04f888u: goto P_0c04f888;
case 0x0c04f88au: goto P_0c04f88a;
case 0x0c04f88cu: goto P_0c04f88c;
case 0x0c04f88eu: goto P_0c04f88e;
case 0x0c04f890u: goto P_0c04f890;
case 0x0c04f892u: goto P_0c04f892;
case 0x0c04f894u: goto P_0c04f894;
case 0x0c04f896u: goto P_0c04f896;
case 0x0c04f898u: goto P_0c04f898;
case 0x0c04f89au: goto P_0c04f89a;
case 0x0c04f89cu: goto P_0c04f89c;
case 0x0c04f89eu: goto P_0c04f89e;
case 0x0c04f8a0u: goto P_0c04f8a0;
case 0x0c04f8a2u: goto P_0c04f8a2;
case 0x0c04f8a4u: goto P_0c04f8a4;
case 0x0c04f8bcu: goto P_0c04f8bc;
case 0x0c04f8beu: goto P_0c04f8be;
case 0x0c04f8c0u: goto P_0c04f8c0;
case 0x0c04f8c2u: goto P_0c04f8c2;
case 0x0c04f8c4u: goto P_0c04f8c4;
case 0x0c04f8c6u: goto P_0c04f8c6;
case 0x0c04f8c8u: goto P_0c04f8c8;
case 0x0c04f8cau: goto P_0c04f8ca;
case 0x0c04f8ccu: goto P_0c04f8cc;
case 0x0c04f8ceu: goto P_0c04f8ce;
case 0x0c04f8d0u: goto P_0c04f8d0;
case 0x0c04f8d2u: goto P_0c04f8d2;
case 0x0c04f8d4u: goto P_0c04f8d4;
case 0x0c04f8d6u: goto P_0c04f8d6;
case 0x0c04f8d8u: goto P_0c04f8d8;
case 0x0c04f8dau: goto P_0c04f8da;
case 0x0c04f8dcu: goto P_0c04f8dc;
case 0x0c04f8deu: goto P_0c04f8de;
case 0x0c04f8e0u: goto P_0c04f8e0;
case 0x0c04f8e2u: goto P_0c04f8e2;
case 0x0c04f8e4u: goto P_0c04f8e4;
case 0x0c04f8e6u: goto P_0c04f8e6;
case 0x0c04f8e8u: goto P_0c04f8e8;
case 0x0c04f8eau: goto P_0c04f8ea;
case 0x0c04f8ecu: goto P_0c04f8ec;
case 0x0c04f8eeu: goto P_0c04f8ee;
case 0x0c04f8f0u: goto P_0c04f8f0;
case 0x0c04f8f2u: goto P_0c04f8f2;
case 0x0c04f8f4u: goto P_0c04f8f4;
case 0x0c04f8f6u: goto P_0c04f8f6;
case 0x0c04f8f8u: goto P_0c04f8f8;
case 0x0c04f8fau: goto P_0c04f8fa;
case 0x0c04f8fcu: goto P_0c04f8fc;
case 0x0c04f8feu: goto P_0c04f8fe;
case 0x0c04f900u: goto P_0c04f900;
case 0x0c04f902u: goto P_0c04f902;
case 0x0c04f904u: goto P_0c04f904;
case 0x0c04f906u: goto P_0c04f906;
case 0x0c04f908u: goto P_0c04f908;
case 0x0c04f90au: goto P_0c04f90a;
case 0x0c04f90cu: goto P_0c04f90c;
case 0x0c04f90eu: goto P_0c04f90e;
case 0x0c04f910u: goto P_0c04f910;
case 0x0c04f912u: goto P_0c04f912;
case 0x0c04f914u: goto P_0c04f914;
case 0x0c04f916u: goto P_0c04f916;
case 0x0c04f918u: goto P_0c04f918;
case 0x0c04f91au: goto P_0c04f91a;
case 0x0c04f91cu: goto P_0c04f91c;
case 0x0c04f91eu: goto P_0c04f91e;
case 0x0c04f920u: goto P_0c04f920;
case 0x0c04f922u: goto P_0c04f922;
case 0x0c04f924u: goto P_0c04f924;
case 0x0c04f926u: goto P_0c04f926;
case 0x0c04f928u: goto P_0c04f928;
case 0x0c04f92au: goto P_0c04f92a;
case 0x0c04f92cu: goto P_0c04f92c;
case 0x0c04f92eu: goto P_0c04f92e;
case 0x0c04f930u: goto P_0c04f930;
case 0x0c04f932u: goto P_0c04f932;
case 0x0c04f934u: goto P_0c04f934;
case 0x0c04f936u: goto P_0c04f936;
case 0x0c04f938u: goto P_0c04f938;
case 0x0c04f93au: goto P_0c04f93a;
case 0x0c04f93cu: goto P_0c04f93c;
case 0x0c04f93eu: goto P_0c04f93e;
case 0x0c04f940u: goto P_0c04f940;
case 0x0c04f942u: goto P_0c04f942;
case 0x0c04f944u: goto P_0c04f944;
case 0x0c04f946u: goto P_0c04f946;
case 0x0c04f948u: goto P_0c04f948;
case 0x0c04f94au: goto P_0c04f94a;
case 0x0c04f94cu: goto P_0c04f94c;
case 0x0c04f94eu: goto P_0c04f94e;
case 0x0c04f950u: goto P_0c04f950;
case 0x0c04f952u: goto P_0c04f952;
case 0x0c04f954u: goto P_0c04f954;
case 0x0c04f956u: goto P_0c04f956;
case 0x0c04f958u: goto P_0c04f958;
case 0x0c04f95au: goto P_0c04f95a;
case 0x0c04f95cu: goto P_0c04f95c;
case 0x0c04f95eu: goto P_0c04f95e;
case 0x0c04f960u: goto P_0c04f960;
case 0x0c04f962u: goto P_0c04f962;
case 0x0c04f964u: goto P_0c04f964;
case 0x0c04f966u: goto P_0c04f966;
case 0x0c04f968u: goto P_0c04f968;
case 0x0c04f96au: goto P_0c04f96a;
case 0x0c04f96cu: goto P_0c04f96c;
case 0x0c04f96eu: goto P_0c04f96e;
case 0x0c04f970u: goto P_0c04f970;
case 0x0c04f972u: goto P_0c04f972;
case 0x0c04f974u: goto P_0c04f974;
case 0x0c04f976u: goto P_0c04f976;
case 0x0c04f978u: goto P_0c04f978;
case 0x0c04f97au: goto P_0c04f97a;
case 0x0c04f97cu: goto P_0c04f97c;
case 0x0c04f97eu: goto P_0c04f97e;
case 0x0c04f980u: goto P_0c04f980;
case 0x0c04f982u: goto P_0c04f982;
case 0x0c04f984u: goto P_0c04f984;
case 0x0c04f986u: goto P_0c04f986;
case 0x0c04f988u: goto P_0c04f988;
case 0x0c04f98au: goto P_0c04f98a;
case 0x0c04f98cu: goto P_0c04f98c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04f74e: /* original 2fe6, guest PC 0x0c04f74e */
if(!s->budget--) { s->failed_pc=0x0c04f74eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f750;
P_0c04f750: /* original 2fd6, guest PC 0x0c04f750 */
if(!s->budget--) { s->failed_pc=0x0c04f750u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f752;
P_0c04f752: /* original 6d43, guest PC 0x0c04f752 */
if(!s->budget--) { s->failed_pc=0x0c04f752u; return 0; }
r[13]=r[4];
goto P_0c04f754;
P_0c04f754: /* original 2fc6, guest PC 0x0c04f754 */
if(!s->budget--) { s->failed_pc=0x0c04f754u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f756;
P_0c04f756: /* original 2fb6, guest PC 0x0c04f756 */
if(!s->budget--) { s->failed_pc=0x0c04f756u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f758;
P_0c04f758: /* original 2fa6, guest PC 0x0c04f758 */
if(!s->budget--) { s->failed_pc=0x0c04f758u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f75a;
P_0c04f75a: /* original 2f96, guest PC 0x0c04f75a */
if(!s->budget--) { s->failed_pc=0x0c04f75au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f75c;
P_0c04f75c: /* original 2f86, guest PC 0x0c04f75c */
if(!s->budget--) { s->failed_pc=0x0c04f75cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f75e;
P_0c04f75e: /* original 4f22, guest PC 0x0c04f75e */
if(!s->budget--) { s->failed_pc=0x0c04f75eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f760;
P_0c04f760: /* original 9935, guest PC 0x0c04f760 */
if(!s->budget--) { s->failed_pc=0x0c04f760u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f7ceu,2);
goto P_0c04f762;
P_0c04f762: /* original d31d, guest PC 0x0c04f762 */
if(!s->budget--) { s->failed_pc=0x0c04f762u; return 0; }
r[3]=read(ram,0x0c04f7d8u,4);
goto P_0c04f764;
P_0c04f764: /* original 4f12, guest PC 0x0c04f764 */
if(!s->budget--) { s->failed_pc=0x0c04f764u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04f766;
P_0c04f766: /* original 2d9f, guest PC 0x0c04f766 */
if(!s->budget--) { s->failed_pc=0x0c04f766u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[9]);
goto P_0c04f768;
P_0c04f768: /* original 7ff4, guest PC 0x0c04f768 */
if(!s->budget--) { s->failed_pc=0x0c04f768u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c04f76a;
P_0c04f76a: /* original 2f46, guest PC 0x0c04f76a */
if(!s->budget--) { s->failed_pc=0x0c04f76au; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f76c;
P_0c04f76c: /* original 091a, guest PC 0x0c04f76c */
if(!s->budget--) { s->failed_pc=0x0c04f76cu; return 0; }
r[9]=r[19];
goto P_0c04f76e;
P_0c04f76e: /* original d21b, guest PC 0x0c04f76e */
if(!s->budget--) { s->failed_pc=0x0c04f76eu; return 0; }
r[2]=read(ram,0x0c04f7dcu,4);
goto P_0c04f770;
P_0c04f770: /* original d11b, guest PC 0x0c04f770 */
if(!s->budget--) { s->failed_pc=0x0c04f770u; return 0; }
r[1]=read(ram,0x0c04f7e0u,4);
goto P_0c04f772;
P_0c04f772: /* original 699f, guest PC 0x0c04f772 */
if(!s->budget--) { s->failed_pc=0x0c04f772u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)r[9];
goto P_0c04f774;
P_0c04f774: /* original 393c, guest PC 0x0c04f774 */
if(!s->budget--) { s->failed_pc=0x0c04f774u; return 0; }
r[9]+=r[3];
goto P_0c04f776;
P_0c04f776: /* original 410b, guest PC 0x0c04f776 */
if(!s->budget--) { s->failed_pc=0x0c04f776u; return 0; }
target=r[1];
r[16]=code_base|0x0c04f77au;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f77au) { target=s->pc; goto dispatch; }
goto P_0c04f77a;
P_0c04f778: /* original 2f26, guest PC 0x0c04f778 */
if(!s->budget--) { s->failed_pc=0x0c04f778u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f77a;
P_0c04f77a: /* original 5597, guest PC 0x0c04f77a */
if(!s->budget--) { s->failed_pc=0x0c04f77au; return 0; }
r[5]=read(ram,r[9]+28,4);
goto P_0c04f77c;
P_0c04f77c: /* original 7f08, guest PC 0x0c04f77c */
if(!s->budget--) { s->failed_pc=0x0c04f77cu; return 0; }
r[15]+=0x00000008u;
goto P_0c04f77e;
P_0c04f77e: /* original 5356, guest PC 0x0c04f77e */
if(!s->budget--) { s->failed_pc=0x0c04f77eu; return 0; }
r[3]=read(ram,r[5]+24,4);
goto P_0c04f780;
P_0c04f780: /* original 5455, guest PC 0x0c04f780 */
if(!s->budget--) { s->failed_pc=0x0c04f780u; return 0; }
r[4]=read(ram,r[5]+20,4);
goto P_0c04f782;
P_0c04f782: /* original 1f31, guest PC 0x0c04f782 */
if(!s->budget--) { s->failed_pc=0x0c04f782u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c04f784;
P_0c04f784: /* original e300, guest PC 0x0c04f784 */
if(!s->budget--) { s->failed_pc=0x0c04f784u; return 0; }
r[3]=0x00000000u;
goto P_0c04f786;
P_0c04f786: /* original 6a33, guest PC 0x0c04f786 */
if(!s->budget--) { s->failed_pc=0x0c04f786u; return 0; }
r[10]=r[3];
goto P_0c04f788;
P_0c04f788: /* original 1f32, guest PC 0x0c04f788 */
if(!s->budget--) { s->failed_pc=0x0c04f788u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c04f78a;
P_0c04f78a: /* original a061, guest PC 0x0c04f78a */
if(!s->budget--) { s->failed_pc=0x0c04f78au; return 0; }
r[14]=r[4]&65535u;
goto P_0c04f850;
P_0c04f78c: /* original 6e4d, guest PC 0x0c04f78c */
if(!s->budget--) { s->failed_pc=0x0c04f78cu; return 0; }
r[14]=r[4]&65535u;
goto P_0c04f78e;
P_0c04f78e: /* original 6293, guest PC 0x0c04f78e */
if(!s->budget--) { s->failed_pc=0x0c04f78eu; return 0; }
r[2]=r[9];
goto P_0c04f790;
P_0c04f790: /* original 7248, guest PC 0x0c04f790 */
if(!s->budget--) { s->failed_pc=0x0c04f790u; return 0; }
r[2]+=0x00000048u;
goto P_0c04f792;
P_0c04f792: /* original 32ac, guest PC 0x0c04f792 */
if(!s->budget--) { s->failed_pc=0x0c04f792u; return 0; }
r[2]+=r[10];
goto P_0c04f794;
P_0c04f794: /* original 6320, guest PC 0x0c04f794 */
if(!s->budget--) { s->failed_pc=0x0c04f794u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c04f796;
P_0c04f796: /* original 2338, guest PC 0x0c04f796 */
if(!s->budget--) { s->failed_pc=0x0c04f796u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04f798;
P_0c04f798: /* original 8953, guest PC 0x0c04f798 */
if(!s->budget--) { s->failed_pc=0x0c04f798u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f842; }
goto P_0c04f79a;
P_0c04f79a: /* original 63a3, guest PC 0x0c04f79a */
if(!s->budget--) { s->failed_pc=0x0c04f79au; return 0; }
r[3]=r[10];
goto P_0c04f79c;
P_0c04f79c: /* original 4318, guest PC 0x0c04f79c */
if(!s->budget--) { s->failed_pc=0x0c04f79cu; return 0; }
r[3]<<=8;
goto P_0c04f79e;
P_0c04f79e: /* original 4300, guest PC 0x0c04f79e */
if(!s->budget--) { s->failed_pc=0x0c04f79eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c04f7a0;
P_0c04f7a0: /* original 2f32, guest PC 0x0c04f7a0 */
if(!s->budget--) { s->failed_pc=0x0c04f7a0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c04f7a2;
P_0c04f7a2: /* original 569a, guest PC 0x0c04f7a2 */
if(!s->budget--) { s->failed_pc=0x0c04f7a2u; return 0; }
r[6]=read(ram,r[9]+40,4);
goto P_0c04f7a4;
P_0c04f7a4: /* original 65e3, guest PC 0x0c04f7a4 */
if(!s->budget--) { s->failed_pc=0x0c04f7a4u; return 0; }
r[5]=r[14];
goto P_0c04f7a6;
P_0c04f7a6: /* original 63f2, guest PC 0x0c04f7a6 */
if(!s->budget--) { s->failed_pc=0x0c04f7a6u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c04f7a8;
P_0c04f7a8: /* original d20e, guest PC 0x0c04f7a8 */
if(!s->budget--) { s->failed_pc=0x0c04f7a8u; return 0; }
r[2]=read(ram,0x0c04f7e4u,4);
goto P_0c04f7aa;
P_0c04f7aa: /* original 363c, guest PC 0x0c04f7aa */
if(!s->budget--) { s->failed_pc=0x0c04f7aau; return 0; }
r[6]+=r[3];
goto P_0c04f7ac;
P_0c04f7ac: /* original 420b, guest PC 0x0c04f7ac */
if(!s->budget--) { s->failed_pc=0x0c04f7acu; return 0; }
target=r[2];
r[16]=code_base|0x0c04f7b0u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f7b0u) { target=s->pc; goto dispatch; }
goto P_0c04f7b0;
P_0c04f7ae: /* original 64d3, guest PC 0x0c04f7ae */
if(!s->budget--) { s->failed_pc=0x0c04f7aeu; return 0; }
r[4]=r[13];
goto P_0c04f7b0;
P_0c04f7b0: /* original 6403, guest PC 0x0c04f7b0 */
if(!s->budget--) { s->failed_pc=0x0c04f7b0u; return 0; }
r[4]=r[0];
goto P_0c04f7b2;
P_0c04f7b2: /* original 2448, guest PC 0x0c04f7b2 */
if(!s->budget--) { s->failed_pc=0x0c04f7b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c04f7b4;
P_0c04f7b4: /* original 8b18, guest PC 0x0c04f7b4 */
if(!s->budget--) { s->failed_pc=0x0c04f7b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f7e8; }
goto P_0c04f7b6;
P_0c04f7b6: /* original 65e3, guest PC 0x0c04f7b6 */
if(!s->budget--) { s->failed_pc=0x0c04f7b6u; return 0; }
r[5]=r[14];
goto P_0c04f7b8;
P_0c04f7b8: /* original b371, guest PC 0x0c04f7b8 */
if(!s->budget--) { s->failed_pc=0x0c04f7b8u; return 0; }
target=code_base|0x0c04fe9eu; r[16]=code_base|0x0c04f7bcu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f7bcu) { target=s->pc; goto dispatch; }
goto P_0c04f7bc;
P_0c04f7ba: /* original 64d3, guest PC 0x0c04f7ba */
if(!s->budget--) { s->failed_pc=0x0c04f7bau; return 0; }
r[4]=r[13];
goto P_0c04f7bc;
P_0c04f7bc: /* original 6393, guest PC 0x0c04f7bc */
if(!s->budget--) { s->failed_pc=0x0c04f7bcu; return 0; }
r[3]=r[9];
goto P_0c04f7be;
P_0c04f7be: /* original 7348, guest PC 0x0c04f7be */
if(!s->budget--) { s->failed_pc=0x0c04f7beu; return 0; }
r[3]+=0x00000048u;
goto P_0c04f7c0;
P_0c04f7c0: /* original 33ac, guest PC 0x0c04f7c0 */
if(!s->budget--) { s->failed_pc=0x0c04f7c0u; return 0; }
r[3]+=r[10];
goto P_0c04f7c2;
P_0c04f7c2: /* original 68e3, guest PC 0x0c04f7c2 */
if(!s->budget--) { s->failed_pc=0x0c04f7c2u; return 0; }
r[8]=r[14];
goto P_0c04f7c4;
P_0c04f7c4: /* original e200, guest PC 0x0c04f7c4 */
if(!s->budget--) { s->failed_pc=0x0c04f7c4u; return 0; }
r[2]=0x00000000u;
goto P_0c04f7c6;
P_0c04f7c6: /* original 2320, guest PC 0x0c04f7c6 */
if(!s->budget--) { s->failed_pc=0x0c04f7c6u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c04f7c8;
P_0c04f7c8: /* original 6b0d, guest PC 0x0c04f7c8 */
if(!s->budget--) { s->failed_pc=0x0c04f7c8u; return 0; }
r[11]=r[0]&65535u;
goto P_0c04f7ca;
P_0c04f7ca: /* original a040, guest PC 0x0c04f7ca */
if(!s->budget--) { s->failed_pc=0x0c04f7cau; return 0; }
r[14]=r[11];
goto P_0c04f84e;
P_0c04f7cc: /* original 6eb3, guest PC 0x0c04f7cc */
if(!s->budget--) { s->failed_pc=0x0c04f7ccu; return 0; }
r[14]=r[11];
if(!vf3_matrix_family(0x0c04f7ceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04f7ceu; return 0; } return 1;
P_0c04f7e8: /* original 925d, guest PC 0x0c04f7e8 */
if(!s->budget--) { s->failed_pc=0x0c04f7e8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f8a6u,2);
goto P_0c04f7ea;
P_0c04f7ea: /* original 3420, guest PC 0x0c04f7ea */
if(!s->budget--) { s->failed_pc=0x0c04f7eau; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c04f7ec;
P_0c04f7ec: /* original 8940, guest PC 0x0c04f7ec */
if(!s->budget--) { s->failed_pc=0x0c04f7ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f870; }
goto P_0c04f7ee;
P_0c04f7ee: /* original e201, guest PC 0x0c04f7ee */
if(!s->budget--) { s->failed_pc=0x0c04f7eeu; return 0; }
r[2]=0x00000001u;
goto P_0c04f7f0;
P_0c04f7f0: /* original 65e3, guest PC 0x0c04f7f0 */
if(!s->budget--) { s->failed_pc=0x0c04f7f0u; return 0; }
r[5]=r[14];
goto P_0c04f7f2;
P_0c04f7f2: /* original 1f22, guest PC 0x0c04f7f2 */
if(!s->budget--) { s->failed_pc=0x0c04f7f2u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c04f7f4;
P_0c04f7f4: /* original b353, guest PC 0x0c04f7f4 */
if(!s->budget--) { s->failed_pc=0x0c04f7f4u; return 0; }
target=code_base|0x0c04fe9eu; r[16]=code_base|0x0c04f7f8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f7f8u) { target=s->pc; goto dispatch; }
goto P_0c04f7f8;
P_0c04f7f6: /* original 64d3, guest PC 0x0c04f7f6 */
if(!s->budget--) { s->failed_pc=0x0c04f7f6u; return 0; }
r[4]=r[13];
goto P_0c04f7f8;
P_0c04f7f8: /* original d62c, guest PC 0x0c04f7f8 */
if(!s->budget--) { s->failed_pc=0x0c04f7f8u; return 0; }
r[6]=read(ram,0x0c04f8acu,4);
goto P_0c04f7fa;
P_0c04f7fa: /* original 65e3, guest PC 0x0c04f7fa */
if(!s->budget--) { s->failed_pc=0x0c04f7fau; return 0; }
r[5]=r[14];
goto P_0c04f7fc;
P_0c04f7fc: /* original 6b0d, guest PC 0x0c04f7fc */
if(!s->budget--) { s->failed_pc=0x0c04f7fcu; return 0; }
r[11]=r[0]&65535u;
goto P_0c04f7fe;
P_0c04f7fe: /* original b31f, guest PC 0x0c04f7fe */
if(!s->budget--) { s->failed_pc=0x0c04f7feu; return 0; }
target=code_base|0x0c04fe40u; r[16]=code_base|0x0c04f802u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f802u) { target=s->pc; goto dispatch; }
goto P_0c04f802;
P_0c04f800: /* original 64d3, guest PC 0x0c04f800 */
if(!s->budget--) { s->failed_pc=0x0c04f800u; return 0; }
r[4]=r[13];
goto P_0c04f802;
P_0c04f802: /* original d32c, guest PC 0x0c04f802 */
if(!s->budget--) { s->failed_pc=0x0c04f802u; return 0; }
r[3]=read(ram,0x0c04f8b4u,4);
goto P_0c04f804;
P_0c04f804: /* original d52a, guest PC 0x0c04f804 */
if(!s->budget--) { s->failed_pc=0x0c04f804u; return 0; }
r[5]=read(ram,0x0c04f8b0u,4);
goto P_0c04f806;
P_0c04f806: /* original 430b, guest PC 0x0c04f806 */
if(!s->budget--) { s->failed_pc=0x0c04f806u; return 0; }
target=r[3];
r[16]=code_base|0x0c04f80au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f80au) { target=s->pc; goto dispatch; }
goto P_0c04f80a;
P_0c04f808: /* original 64d3, guest PC 0x0c04f808 */
if(!s->budget--) { s->failed_pc=0x0c04f808u; return 0; }
r[4]=r[13];
goto P_0c04f80a;
P_0c04f80a: /* original 6c03, guest PC 0x0c04f80a */
if(!s->budget--) { s->failed_pc=0x0c04f80au; return 0; }
r[12]=r[0];
goto P_0c04f80c;
P_0c04f80c: /* original 4c11, guest PC 0x0c04f80c */
if(!s->budget--) { s->failed_pc=0x0c04f80cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=0)!=0);
goto P_0c04f80e;
P_0c04f80e: /* original 8902, guest PC 0x0c04f80e */
if(!s->budget--) { s->failed_pc=0x0c04f80eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f816; }
goto P_0c04f810;
P_0c04f810: /* original 904a, guest PC 0x0c04f810 */
if(!s->budget--) { s->failed_pc=0x0c04f810u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f8a8u,2);
goto P_0c04f812;
P_0c04f812: /* original a030, guest PC 0x0c04f812 */
if(!s->budget--) { s->failed_pc=0x0c04f812u; return 0; }
goto P_0c04f876;
P_0c04f814: /* original 0009, guest PC 0x0c04f814 */
if(!s->budget--) { s->failed_pc=0x0c04f814u; return 0; }
goto P_0c04f816;
P_0c04f816: /* original 65c3, guest PC 0x0c04f816 */
if(!s->budget--) { s->failed_pc=0x0c04f816u; return 0; }
r[5]=r[12];
goto P_0c04f818;
P_0c04f818: /* original 66b3, guest PC 0x0c04f818 */
if(!s->budget--) { s->failed_pc=0x0c04f818u; return 0; }
r[6]=r[11];
goto P_0c04f81a;
P_0c04f81a: /* original b311, guest PC 0x0c04f81a */
if(!s->budget--) { s->failed_pc=0x0c04f81au; return 0; }
target=code_base|0x0c04fe40u; r[16]=code_base|0x0c04f81eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f81eu) { target=s->pc; goto dispatch; }
goto P_0c04f81e;
P_0c04f81c: /* original 64d3, guest PC 0x0c04f81c */
if(!s->budget--) { s->failed_pc=0x0c04f81cu; return 0; }
r[4]=r[13];
goto P_0c04f81e;
P_0c04f81e: /* original 2aa8, guest PC 0x0c04f81e */
if(!s->budget--) { s->failed_pc=0x0c04f81eu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c04f820;
P_0c04f820: /* original 8b08, guest PC 0x0c04f820 */
if(!s->budget--) { s->failed_pc=0x0c04f820u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f834; }
goto P_0c04f822;
P_0c04f822: /* original d225, guest PC 0x0c04f822 */
if(!s->budget--) { s->failed_pc=0x0c04f822u; return 0; }
r[2]=read(ram,0x0c04f8b8u,4);
goto P_0c04f824;
P_0c04f824: /* original e54a, guest PC 0x0c04f824 */
if(!s->budget--) { s->failed_pc=0x0c04f824u; return 0; }
r[5]=0x0000004au;
goto P_0c04f826;
P_0c04f826: /* original 66c3, guest PC 0x0c04f826 */
if(!s->budget--) { s->failed_pc=0x0c04f826u; return 0; }
r[6]=r[12];
goto P_0c04f828;
P_0c04f828: /* original 6322, guest PC 0x0c04f828 */
if(!s->budget--) { s->failed_pc=0x0c04f828u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c04f82a;
P_0c04f82a: /* original 5134, guest PC 0x0c04f82a */
if(!s->budget--) { s->failed_pc=0x0c04f82au; return 0; }
r[1]=read(ram,r[3]+16,4);
goto P_0c04f82c;
P_0c04f82c: /* original 410b, guest PC 0x0c04f82c */
if(!s->budget--) { s->failed_pc=0x0c04f82cu; return 0; }
target=r[1];
r[16]=code_base|0x0c04f830u;
r[4]=read(ram,r[9]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f830u) { target=s->pc; goto dispatch; }
goto P_0c04f830;
P_0c04f82e: /* original 5498, guest PC 0x0c04f82e */
if(!s->budget--) { s->failed_pc=0x0c04f82eu; return 0; }
r[4]=read(ram,r[9]+32,4);
goto P_0c04f830;
P_0c04f830: /* original a004, guest PC 0x0c04f830 */
if(!s->budget--) { s->failed_pc=0x0c04f830u; return 0; }
goto P_0c04f83c;
P_0c04f832: /* original 0009, guest PC 0x0c04f832 */
if(!s->budget--) { s->failed_pc=0x0c04f832u; return 0; }
goto P_0c04f834;
P_0c04f834: /* original 6583, guest PC 0x0c04f834 */
if(!s->budget--) { s->failed_pc=0x0c04f834u; return 0; }
r[5]=r[8];
goto P_0c04f836;
P_0c04f836: /* original 66c3, guest PC 0x0c04f836 */
if(!s->budget--) { s->failed_pc=0x0c04f836u; return 0; }
r[6]=r[12];
goto P_0c04f838;
P_0c04f838: /* original b302, guest PC 0x0c04f838 */
if(!s->budget--) { s->failed_pc=0x0c04f838u; return 0; }
target=code_base|0x0c04fe40u; r[16]=code_base|0x0c04f83cu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f83cu) { target=s->pc; goto dispatch; }
goto P_0c04f83c;
P_0c04f83a: /* original 64d3, guest PC 0x0c04f83a */
if(!s->budget--) { s->failed_pc=0x0c04f83au; return 0; }
r[4]=r[13];
goto P_0c04f83c;
P_0c04f83c: /* original 68e3, guest PC 0x0c04f83c */
if(!s->budget--) { s->failed_pc=0x0c04f83cu; return 0; }
r[8]=r[14];
goto P_0c04f83e;
P_0c04f83e: /* original afb0, guest PC 0x0c04f83e */
if(!s->budget--) { s->failed_pc=0x0c04f83eu; return 0; }
r[14]=r[12];
goto P_0c04f7a2;
P_0c04f840: /* original 6ec3, guest PC 0x0c04f840 */
if(!s->budget--) { s->failed_pc=0x0c04f840u; return 0; }
r[14]=r[12];
goto P_0c04f842;
P_0c04f842: /* original 65e3, guest PC 0x0c04f842 */
if(!s->budget--) { s->failed_pc=0x0c04f842u; return 0; }
r[5]=r[14];
goto P_0c04f844;
P_0c04f844: /* original b32b, guest PC 0x0c04f844 */
if(!s->budget--) { s->failed_pc=0x0c04f844u; return 0; }
target=code_base|0x0c04fe9eu; r[16]=code_base|0x0c04f848u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f848u) { target=s->pc; goto dispatch; }
goto P_0c04f848;
P_0c04f846: /* original 64d3, guest PC 0x0c04f846 */
if(!s->budget--) { s->failed_pc=0x0c04f846u; return 0; }
r[4]=r[13];
goto P_0c04f848;
P_0c04f848: /* original 68e3, guest PC 0x0c04f848 */
if(!s->budget--) { s->failed_pc=0x0c04f848u; return 0; }
r[8]=r[14];
goto P_0c04f84a;
P_0c04f84a: /* original 6b0d, guest PC 0x0c04f84a */
if(!s->budget--) { s->failed_pc=0x0c04f84au; return 0; }
r[11]=r[0]&65535u;
goto P_0c04f84c;
P_0c04f84c: /* original 6eb3, guest PC 0x0c04f84c */
if(!s->budget--) { s->failed_pc=0x0c04f84cu; return 0; }
r[14]=r[11];
goto P_0c04f84e;
P_0c04f84e: /* original 7a01, guest PC 0x0c04f84e */
if(!s->budget--) { s->failed_pc=0x0c04f84eu; return 0; }
r[10]+=0x00000001u;
goto P_0c04f850;
P_0c04f850: /* original 53f1, guest PC 0x0c04f850 */
if(!s->budget--) { s->failed_pc=0x0c04f850u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c04f852;
P_0c04f852: /* original 3a33, guest PC 0x0c04f852 */
if(!s->budget--) { s->failed_pc=0x0c04f852u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[3])!=0);
goto P_0c04f854;
P_0c04f854: /* original 8b9b, guest PC 0x0c04f854 */
if(!s->budget--) { s->failed_pc=0x0c04f854u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f78e; }
goto P_0c04f856;
P_0c04f856: /* original 51f2, guest PC 0x0c04f856 */
if(!s->budget--) { s->failed_pc=0x0c04f856u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c04f858;
P_0c04f858: /* original 2118, guest PC 0x0c04f858 */
if(!s->budget--) { s->failed_pc=0x0c04f858u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c04f85a;
P_0c04f85a: /* original 890b, guest PC 0x0c04f85a */
if(!s->budget--) { s->failed_pc=0x0c04f85au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f874; }
goto P_0c04f85c;
P_0c04f85c: /* original b268, guest PC 0x0c04f85c */
if(!s->budget--) { s->failed_pc=0x0c04f85cu; return 0; }
target=code_base|0x0c04fd30u; r[16]=code_base|0x0c04f860u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f860u) { target=s->pc; goto dispatch; }
goto P_0c04f860;
P_0c04f85e: /* original 64d3, guest PC 0x0c04f85e */
if(!s->budget--) { s->failed_pc=0x0c04f85eu; return 0; }
r[4]=r[13];
goto P_0c04f860;
P_0c04f860: /* original 6403, guest PC 0x0c04f860 */
if(!s->budget--) { s->failed_pc=0x0c04f860u; return 0; }
r[4]=r[0];
goto P_0c04f862;
P_0c04f862: /* original 4411, guest PC 0x0c04f862 */
if(!s->budget--) { s->failed_pc=0x0c04f862u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c04f864;
P_0c04f864: /* original 8b04, guest PC 0x0c04f864 */
if(!s->budget--) { s->failed_pc=0x0c04f864u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f870; }
goto P_0c04f866;
P_0c04f866: /* original b149, guest PC 0x0c04f866 */
if(!s->budget--) { s->failed_pc=0x0c04f866u; return 0; }
target=code_base|0x0c04fafcu; r[16]=code_base|0x0c04f86au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f86au) { target=s->pc; goto dispatch; }
goto P_0c04f86a;
P_0c04f868: /* original 64d3, guest PC 0x0c04f868 */
if(!s->budget--) { s->failed_pc=0x0c04f868u; return 0; }
r[4]=r[13];
goto P_0c04f86a;
P_0c04f86a: /* original 6403, guest PC 0x0c04f86a */
if(!s->budget--) { s->failed_pc=0x0c04f86au; return 0; }
r[4]=r[0];
goto P_0c04f86c;
P_0c04f86c: /* original 4411, guest PC 0x0c04f86c */
if(!s->budget--) { s->failed_pc=0x0c04f86cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c04f86e;
P_0c04f86e: /* original 8901, guest PC 0x0c04f86e */
if(!s->budget--) { s->failed_pc=0x0c04f86eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f874; }
goto P_0c04f870;
P_0c04f870: /* original a001, guest PC 0x0c04f870 */
if(!s->budget--) { s->failed_pc=0x0c04f870u; return 0; }
r[0]=r[4];
goto P_0c04f876;
P_0c04f872: /* original 6043, guest PC 0x0c04f872 */
if(!s->budget--) { s->failed_pc=0x0c04f872u; return 0; }
r[0]=r[4];
goto P_0c04f874;
P_0c04f874: /* original e000, guest PC 0x0c04f874 */
if(!s->budget--) { s->failed_pc=0x0c04f874u; return 0; }
r[0]=0x00000000u;
goto P_0c04f876;
P_0c04f876: /* original 7f0c, guest PC 0x0c04f876 */
if(!s->budget--) { s->failed_pc=0x0c04f876u; return 0; }
r[15]+=0x0000000cu;
goto P_0c04f878;
P_0c04f878: /* original 4f16, guest PC 0x0c04f878 */
if(!s->budget--) { s->failed_pc=0x0c04f878u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f87a;
P_0c04f87a: /* original 4f26, guest PC 0x0c04f87a */
if(!s->budget--) { s->failed_pc=0x0c04f87au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f87c;
P_0c04f87c: /* original 68f6, guest PC 0x0c04f87c */
if(!s->budget--) { s->failed_pc=0x0c04f87cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04f87e;
P_0c04f87e: /* original 69f6, guest PC 0x0c04f87e */
if(!s->budget--) { s->failed_pc=0x0c04f87eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04f880;
P_0c04f880: /* original 6af6, guest PC 0x0c04f880 */
if(!s->budget--) { s->failed_pc=0x0c04f880u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04f882;
P_0c04f882: /* original 6bf6, guest PC 0x0c04f882 */
if(!s->budget--) { s->failed_pc=0x0c04f882u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04f884;
P_0c04f884: /* original 6cf6, guest PC 0x0c04f884 */
if(!s->budget--) { s->failed_pc=0x0c04f884u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04f886;
P_0c04f886: /* original 6df6, guest PC 0x0c04f886 */
if(!s->budget--) { s->failed_pc=0x0c04f886u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04f888;
P_0c04f888: /* original 000b, guest PC 0x0c04f888 */
if(!s->budget--) { s->failed_pc=0x0c04f888u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f88a: /* original 6ef6, guest PC 0x0c04f88a */
if(!s->budget--) { s->failed_pc=0x0c04f88au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04f88c;
P_0c04f88c: /* original e600, guest PC 0x0c04f88c */
if(!s->budget--) { s->failed_pc=0x0c04f88cu; return 0; }
r[6]=0x00000000u;
goto P_0c04f88e;
P_0c04f88e: /* original e70c, guest PC 0x0c04f88e */
if(!s->budget--) { s->failed_pc=0x0c04f88eu; return 0; }
r[7]=0x0000000cu;
goto P_0c04f890;
P_0c04f890: /* original 6563, guest PC 0x0c04f890 */
if(!s->budget--) { s->failed_pc=0x0c04f890u; return 0; }
r[5]=r[6];
goto P_0c04f892;
P_0c04f892: /* original 6340, guest PC 0x0c04f892 */
if(!s->budget--) { s->failed_pc=0x0c04f892u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c04f894;
P_0c04f894: /* original 2338, guest PC 0x0c04f894 */
if(!s->budget--) { s->failed_pc=0x0c04f894u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04f896;
P_0c04f896: /* original 8904, guest PC 0x0c04f896 */
if(!s->budget--) { s->failed_pc=0x0c04f896u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f8a2; }
goto P_0c04f898;
P_0c04f898: /* original 7601, guest PC 0x0c04f898 */
if(!s->budget--) { s->failed_pc=0x0c04f898u; return 0; }
r[6]+=0x00000001u;
goto P_0c04f89a;
P_0c04f89a: /* original 3673, guest PC 0x0c04f89a */
if(!s->budget--) { s->failed_pc=0x0c04f89au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[7])!=0);
goto P_0c04f89c;
P_0c04f89c: /* original 7501, guest PC 0x0c04f89c */
if(!s->budget--) { s->failed_pc=0x0c04f89cu; return 0; }
r[5]+=0x00000001u;
goto P_0c04f89e;
P_0c04f89e: /* original 8ff8, guest PC 0x0c04f89e */
if(!s->budget--) { s->failed_pc=0x0c04f89eu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c04f892; }
goto P_0c04f8a2;
P_0c04f8a0: /* original 7401, guest PC 0x0c04f8a0 */
if(!s->budget--) { s->failed_pc=0x0c04f8a0u; return 0; }
r[4]+=0x00000001u;
goto P_0c04f8a2;
P_0c04f8a2: /* original 000b, guest PC 0x0c04f8a2 */
if(!s->budget--) { s->failed_pc=0x0c04f8a2u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c04f8a4: /* original 6053, guest PC 0x0c04f8a4 */
if(!s->budget--) { s->failed_pc=0x0c04f8a4u; return 0; }
r[0]=r[5];
if(!vf3_matrix_family(0x0c04f8a6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04f8a6u; return 0; } return 1;
P_0c04f8bc: /* original 2fe6, guest PC 0x0c04f8bc */
if(!s->budget--) { s->failed_pc=0x0c04f8bcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f8be;
P_0c04f8be: /* original 4f22, guest PC 0x0c04f8be */
if(!s->budget--) { s->failed_pc=0x0c04f8beu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f8c0;
P_0c04f8c0: /* original 7ff8, guest PC 0x0c04f8c0 */
if(!s->budget--) { s->failed_pc=0x0c04f8c0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c04f8c2;
P_0c04f8c2: /* original 2f42, guest PC 0x0c04f8c2 */
if(!s->budget--) { s->failed_pc=0x0c04f8c2u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c04f8c4;
P_0c04f8c4: /* original 1f51, guest PC 0x0c04f8c4 */
if(!s->budget--) { s->failed_pc=0x0c04f8c4u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c04f8c6;
P_0c04f8c6: /* original bfe1, guest PC 0x0c04f8c6 */
if(!s->budget--) { s->failed_pc=0x0c04f8c6u; return 0; }
target=code_base|0x0c04f88cu; r[16]=code_base|0x0c04f8cau;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f8cau) { target=s->pc; goto dispatch; }
goto P_0c04f8ca;
P_0c04f8c8: /* original 64f2, guest PC 0x0c04f8c8 */
if(!s->budget--) { s->failed_pc=0x0c04f8c8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c04f8ca;
P_0c04f8ca: /* original 6e03, guest PC 0x0c04f8ca */
if(!s->budget--) { s->failed_pc=0x0c04f8cau; return 0; }
r[14]=r[0];
goto P_0c04f8cc;
P_0c04f8cc: /* original bfde, guest PC 0x0c04f8cc */
if(!s->budget--) { s->failed_pc=0x0c04f8ccu; return 0; }
target=code_base|0x0c04f88cu; r[16]=code_base|0x0c04f8d0u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f8d0u) { target=s->pc; goto dispatch; }
goto P_0c04f8d0;
P_0c04f8ce: /* original 54f1, guest PC 0x0c04f8ce */
if(!s->budget--) { s->failed_pc=0x0c04f8ceu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c04f8d0;
P_0c04f8d0: /* original 6403, guest PC 0x0c04f8d0 */
if(!s->budget--) { s->failed_pc=0x0c04f8d0u; return 0; }
r[4]=r[0];
goto P_0c04f8d2;
P_0c04f8d2: /* original 3e40, guest PC 0x0c04f8d2 */
if(!s->budget--) { s->failed_pc=0x0c04f8d2u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[4])!=0);
goto P_0c04f8d4;
P_0c04f8d4: /* original 8b08, guest PC 0x0c04f8d4 */
if(!s->budget--) { s->failed_pc=0x0c04f8d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f8e8; }
goto P_0c04f8d6;
P_0c04f8d6: /* original 54f1, guest PC 0x0c04f8d6 */
if(!s->budget--) { s->failed_pc=0x0c04f8d6u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c04f8d8;
P_0c04f8d8: /* original 4e15, guest PC 0x0c04f8d8 */
if(!s->budget--) { s->failed_pc=0x0c04f8d8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c04f8da;
P_0c04f8da: /* original e600, guest PC 0x0c04f8da */
if(!s->budget--) { s->failed_pc=0x0c04f8dau; return 0; }
r[6]=0x00000000u;
goto P_0c04f8dc;
P_0c04f8dc: /* original 8f0e, guest PC 0x0c04f8dc */
if(!s->budget--) { s->failed_pc=0x0c04f8dcu; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[15],4);
r[5]=tmp;
if(!cond) { goto P_0c04f8fc; }
goto P_0c04f8e0;
P_0c04f8de: /* original 65f2, guest PC 0x0c04f8de */
if(!s->budget--) { s->failed_pc=0x0c04f8deu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04f8e0;
P_0c04f8e0: /* original 6340, guest PC 0x0c04f8e0 */
if(!s->budget--) { s->failed_pc=0x0c04f8e0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c04f8e2;
P_0c04f8e2: /* original 6250, guest PC 0x0c04f8e2 */
if(!s->budget--) { s->failed_pc=0x0c04f8e2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[2]=tmp;
goto P_0c04f8e4;
P_0c04f8e4: /* original 3230, guest PC 0x0c04f8e4 */
if(!s->budget--) { s->failed_pc=0x0c04f8e4u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c04f8e6;
P_0c04f8e6: /* original 8904, guest PC 0x0c04f8e6 */
if(!s->budget--) { s->failed_pc=0x0c04f8e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f8f2; }
goto P_0c04f8e8;
P_0c04f8e8: /* original 7f08, guest PC 0x0c04f8e8 */
if(!s->budget--) { s->failed_pc=0x0c04f8e8u; return 0; }
r[15]+=0x00000008u;
goto P_0c04f8ea;
P_0c04f8ea: /* original 4f26, guest PC 0x0c04f8ea */
if(!s->budget--) { s->failed_pc=0x0c04f8eau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f8ec;
P_0c04f8ec: /* original e000, guest PC 0x0c04f8ec */
if(!s->budget--) { s->failed_pc=0x0c04f8ecu; return 0; }
r[0]=0x00000000u;
goto P_0c04f8ee;
P_0c04f8ee: /* original 000b, guest PC 0x0c04f8ee */
if(!s->budget--) { s->failed_pc=0x0c04f8eeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f8f0: /* original 6ef6, guest PC 0x0c04f8f0 */
if(!s->budget--) { s->failed_pc=0x0c04f8f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04f8f2;
P_0c04f8f2: /* original 7601, guest PC 0x0c04f8f2 */
if(!s->budget--) { s->failed_pc=0x0c04f8f2u; return 0; }
r[6]+=0x00000001u;
goto P_0c04f8f4;
P_0c04f8f4: /* original 36e3, guest PC 0x0c04f8f4 */
if(!s->budget--) { s->failed_pc=0x0c04f8f4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[14])!=0);
goto P_0c04f8f6;
P_0c04f8f6: /* original 7401, guest PC 0x0c04f8f6 */
if(!s->budget--) { s->failed_pc=0x0c04f8f6u; return 0; }
r[4]+=0x00000001u;
goto P_0c04f8f8;
P_0c04f8f8: /* original 8ff2, guest PC 0x0c04f8f8 */
if(!s->budget--) { s->failed_pc=0x0c04f8f8u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000001u;
if(!cond) { goto P_0c04f8e0; }
goto P_0c04f8fc;
P_0c04f8fa: /* original 7501, guest PC 0x0c04f8fa */
if(!s->budget--) { s->failed_pc=0x0c04f8fau; return 0; }
r[5]+=0x00000001u;
goto P_0c04f8fc;
P_0c04f8fc: /* original e001, guest PC 0x0c04f8fc */
if(!s->budget--) { s->failed_pc=0x0c04f8fcu; return 0; }
r[0]=0x00000001u;
goto P_0c04f8fe;
P_0c04f8fe: /* original 7f08, guest PC 0x0c04f8fe */
if(!s->budget--) { s->failed_pc=0x0c04f8feu; return 0; }
r[15]+=0x00000008u;
goto P_0c04f900;
P_0c04f900: /* original 4f26, guest PC 0x0c04f900 */
if(!s->budget--) { s->failed_pc=0x0c04f900u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f902;
P_0c04f902: /* original 000b, guest PC 0x0c04f902 */
if(!s->budget--) { s->failed_pc=0x0c04f902u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f904: /* original 6ef6, guest PC 0x0c04f904 */
if(!s->budget--) { s->failed_pc=0x0c04f904u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04f906;
P_0c04f906: /* original 2fe6, guest PC 0x0c04f906 */
if(!s->budget--) { s->failed_pc=0x0c04f906u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f908;
P_0c04f908: /* original 6e53, guest PC 0x0c04f908 */
if(!s->budget--) { s->failed_pc=0x0c04f908u; return 0; }
r[14]=r[5];
goto P_0c04f90a;
P_0c04f90a: /* original 2fd6, guest PC 0x0c04f90a */
if(!s->budget--) { s->failed_pc=0x0c04f90au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f90c;
P_0c04f90c: /* original 6d43, guest PC 0x0c04f90c */
if(!s->budget--) { s->failed_pc=0x0c04f90cu; return 0; }
r[13]=r[4];
goto P_0c04f90e;
P_0c04f90e: /* original 2fc6, guest PC 0x0c04f90e */
if(!s->budget--) { s->failed_pc=0x0c04f90eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f910;
P_0c04f910: /* original e500, guest PC 0x0c04f910 */
if(!s->budget--) { s->failed_pc=0x0c04f910u; return 0; }
r[5]=0x00000000u;
goto P_0c04f912;
P_0c04f912: /* original 4f22, guest PC 0x0c04f912 */
if(!s->budget--) { s->failed_pc=0x0c04f912u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f914;
P_0c04f914: /* original 63d0, guest PC 0x0c04f914 */
if(!s->budget--) { s->failed_pc=0x0c04f914u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[3]=tmp;
goto P_0c04f916;
P_0c04f916: /* original 35dc, guest PC 0x0c04f916 */
if(!s->budget--) { s->failed_pc=0x0c04f916u; return 0; }
r[5]+=r[13];
goto P_0c04f918;
P_0c04f918: /* original 64e3, guest PC 0x0c04f918 */
if(!s->budget--) { s->failed_pc=0x0c04f918u; return 0; }
r[4]=r[14];
goto P_0c04f91a;
P_0c04f91a: /* original ec00, guest PC 0x0c04f91a */
if(!s->budget--) { s->failed_pc=0x0c04f91au; return 0; }
r[12]=0x00000000u;
goto P_0c04f91c;
P_0c04f91c: /* original 7ffc, guest PC 0x0c04f91c */
if(!s->budget--) { s->failed_pc=0x0c04f91cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04f91e;
P_0c04f91e: /* original 66c3, guest PC 0x0c04f91e */
if(!s->budget--) { s->failed_pc=0x0c04f91eu; return 0; }
r[6]=r[12];
goto P_0c04f920;
P_0c04f920: /* original 633c, guest PC 0x0c04f920 */
if(!s->budget--) { s->failed_pc=0x0c04f920u; return 0; }
r[3]=r[3]&255u;
goto P_0c04f922;
P_0c04f922: /* original e70c, guest PC 0x0c04f922 */
if(!s->budget--) { s->failed_pc=0x0c04f922u; return 0; }
r[7]=0x0000000cu;
goto P_0c04f924;
P_0c04f924: /* original 1e31, guest PC 0x0c04f924 */
if(!s->budget--) { s->failed_pc=0x0c04f924u; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c04f926;
P_0c04f926: /* original 2f52, guest PC 0x0c04f926 */
if(!s->budget--) { s->failed_pc=0x0c04f926u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c04f928;
P_0c04f928: /* original 7410, guest PC 0x0c04f928 */
if(!s->budget--) { s->failed_pc=0x0c04f928u; return 0; }
r[4]+=0x00000010u;
goto P_0c04f92a;
P_0c04f92a: /* original 7504, guest PC 0x0c04f92a */
if(!s->budget--) { s->failed_pc=0x0c04f92au; return 0; }
r[5]+=0x00000004u;
goto P_0c04f92c;
P_0c04f92c: /* original 6354, guest PC 0x0c04f92c */
if(!s->budget--) { s->failed_pc=0x0c04f92cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[3]=tmp;
goto P_0c04f92e;
P_0c04f92e: /* original 7601, guest PC 0x0c04f92e */
if(!s->budget--) { s->failed_pc=0x0c04f92eu; return 0; }
r[6]+=0x00000001u;
goto P_0c04f930;
P_0c04f930: /* original 3673, guest PC 0x0c04f930 */
if(!s->budget--) { s->failed_pc=0x0c04f930u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[7])!=0);
goto P_0c04f932;
P_0c04f932: /* original 2430, guest PC 0x0c04f932 */
if(!s->budget--) { s->failed_pc=0x0c04f932u; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04f934;
P_0c04f934: /* original 8ffa, guest PC 0x0c04f934 */
if(!s->budget--) { s->failed_pc=0x0c04f934u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c04f92c; }
goto P_0c04f938;
P_0c04f936: /* original 7401, guest PC 0x0c04f936 */
if(!s->budget--) { s->failed_pc=0x0c04f936u; return 0; }
r[4]+=0x00000001u;
goto P_0c04f938;
P_0c04f938: /* original e01c, guest PC 0x0c04f938 */
if(!s->budget--) { s->failed_pc=0x0c04f938u; return 0; }
r[0]=0x0000001cu;
goto P_0c04f93a;
P_0c04f93a: /* original 64e3, guest PC 0x0c04f93a */
if(!s->budget--) { s->failed_pc=0x0c04f93au; return 0; }
r[4]=r[14];
goto P_0c04f93c;
P_0c04f93c: /* original e708, guest PC 0x0c04f93c */
if(!s->budget--) { s->failed_pc=0x0c04f93cu; return 0; }
r[7]=0x00000008u;
goto P_0c04f93e;
P_0c04f93e: /* original 0ec4, guest PC 0x0c04f93e */
if(!s->budget--) { s->failed_pc=0x0c04f93eu; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c04f940;
P_0c04f940: /* original 65f2, guest PC 0x0c04f940 */
if(!s->budget--) { s->failed_pc=0x0c04f940u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04f942;
P_0c04f942: /* original 7420, guest PC 0x0c04f942 */
if(!s->budget--) { s->failed_pc=0x0c04f942u; return 0; }
r[4]+=0x00000020u;
goto P_0c04f944;
P_0c04f944: /* original 66c3, guest PC 0x0c04f944 */
if(!s->budget--) { s->failed_pc=0x0c04f944u; return 0; }
r[6]=r[12];
goto P_0c04f946;
P_0c04f946: /* original 7510, guest PC 0x0c04f946 */
if(!s->budget--) { s->failed_pc=0x0c04f946u; return 0; }
r[5]+=0x00000010u;
goto P_0c04f948;
P_0c04f948: /* original 6354, guest PC 0x0c04f948 */
if(!s->budget--) { s->failed_pc=0x0c04f948u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[3]=tmp;
goto P_0c04f94a;
P_0c04f94a: /* original 7601, guest PC 0x0c04f94a */
if(!s->budget--) { s->failed_pc=0x0c04f94au; return 0; }
r[6]+=0x00000001u;
goto P_0c04f94c;
P_0c04f94c: /* original 3673, guest PC 0x0c04f94c */
if(!s->budget--) { s->failed_pc=0x0c04f94cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[7])!=0);
goto P_0c04f94e;
P_0c04f94e: /* original 2430, guest PC 0x0c04f94e */
if(!s->budget--) { s->failed_pc=0x0c04f94eu; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04f950;
P_0c04f950: /* original 8ffa, guest PC 0x0c04f950 */
if(!s->budget--) { s->failed_pc=0x0c04f950u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c04f948; }
goto P_0c04f954;
P_0c04f952: /* original 7401, guest PC 0x0c04f952 */
if(!s->budget--) { s->failed_pc=0x0c04f952u; return 0; }
r[4]+=0x00000001u;
goto P_0c04f954;
P_0c04f954: /* original dc21, guest PC 0x0c04f954 */
if(!s->budget--) { s->failed_pc=0x0c04f954u; return 0; }
r[12]=read(ram,0x0c04f9dcu,4);
goto P_0c04f956;
P_0c04f956: /* original e502, guest PC 0x0c04f956 */
if(!s->budget--) { s->failed_pc=0x0c04f956u; return 0; }
r[5]=0x00000002u;
goto P_0c04f958;
P_0c04f958: /* original 63c2, guest PC 0x0c04f958 */
if(!s->budget--) { s->failed_pc=0x0c04f958u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c04f95a;
P_0c04f95a: /* original 5233, guest PC 0x0c04f95a */
if(!s->budget--) { s->failed_pc=0x0c04f95au; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c04f95c;
P_0c04f95c: /* original 420b, guest PC 0x0c04f95c */
if(!s->budget--) { s->failed_pc=0x0c04f95cu; return 0; }
target=r[2];
r[16]=code_base|0x0c04f960u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f960u) { target=s->pc; goto dispatch; }
goto P_0c04f960;
P_0c04f95e: /* original 64d3, guest PC 0x0c04f95e */
if(!s->budget--) { s->failed_pc=0x0c04f95eu; return 0; }
r[4]=r[13];
goto P_0c04f960;
P_0c04f960: /* original 600d, guest PC 0x0c04f960 */
if(!s->budget--) { s->failed_pc=0x0c04f960u; return 0; }
r[0]=r[0]&65535u;
goto P_0c04f962;
P_0c04f962: /* original e518, guest PC 0x0c04f962 */
if(!s->budget--) { s->failed_pc=0x0c04f962u; return 0; }
r[5]=0x00000018u;
goto P_0c04f964;
P_0c04f964: /* original 1e03, guest PC 0x0c04f964 */
if(!s->budget--) { s->failed_pc=0x0c04f964u; return 0; }
write(ram,r[14]+12,r[0],4);
goto P_0c04f966;
P_0c04f966: /* original 63c2, guest PC 0x0c04f966 */
if(!s->budget--) { s->failed_pc=0x0c04f966u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c04f968;
P_0c04f968: /* original 5233, guest PC 0x0c04f968 */
if(!s->budget--) { s->failed_pc=0x0c04f968u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c04f96a;
P_0c04f96a: /* original 420b, guest PC 0x0c04f96a */
if(!s->budget--) { s->failed_pc=0x0c04f96au; return 0; }
target=r[2];
r[16]=code_base|0x0c04f96eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f96eu) { target=s->pc; goto dispatch; }
goto P_0c04f96e;
P_0c04f96c: /* original 64d3, guest PC 0x0c04f96c */
if(!s->budget--) { s->failed_pc=0x0c04f96cu; return 0; }
r[4]=r[13];
goto P_0c04f96e;
P_0c04f96e: /* original 600d, guest PC 0x0c04f96e */
if(!s->budget--) { s->failed_pc=0x0c04f96eu; return 0; }
r[0]=r[0]&65535u;
goto P_0c04f970;
P_0c04f970: /* original 1e0a, guest PC 0x0c04f970 */
if(!s->budget--) { s->failed_pc=0x0c04f970u; return 0; }
write(ram,r[14]+40,r[0],4);
goto P_0c04f972;
P_0c04f972: /* original e51a, guest PC 0x0c04f972 */
if(!s->budget--) { s->failed_pc=0x0c04f972u; return 0; }
r[5]=0x0000001au;
goto P_0c04f974;
P_0c04f974: /* original 84d1, guest PC 0x0c04f974 */
if(!s->budget--) { s->failed_pc=0x0c04f974u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+1,1);
goto P_0c04f976;
P_0c04f976: /* original 80ea, guest PC 0x0c04f976 */
if(!s->budget--) { s->failed_pc=0x0c04f976u; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c04f978;
P_0c04f978: /* original 60c2, guest PC 0x0c04f978 */
if(!s->budget--) { s->failed_pc=0x0c04f978u; return 0; }
tmp=read(ram,r[12],4);
r[0]=tmp;
goto P_0c04f97a;
P_0c04f97a: /* original 5003, guest PC 0x0c04f97a */
if(!s->budget--) { s->failed_pc=0x0c04f97au; return 0; }
r[0]=read(ram,r[0]+12,4);
goto P_0c04f97c;
P_0c04f97c: /* original 400b, guest PC 0x0c04f97c */
if(!s->budget--) { s->failed_pc=0x0c04f97cu; return 0; }
target=r[0];
r[16]=code_base|0x0c04f980u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f980u) { target=s->pc; goto dispatch; }
goto P_0c04f980;
P_0c04f97e: /* original 64d3, guest PC 0x0c04f97e */
if(!s->budget--) { s->failed_pc=0x0c04f97eu; return 0; }
r[4]=r[13];
goto P_0c04f980;
P_0c04f980: /* original 7f04, guest PC 0x0c04f980 */
if(!s->budget--) { s->failed_pc=0x0c04f980u; return 0; }
r[15]+=0x00000004u;
goto P_0c04f982;
P_0c04f982: /* original 81e4, guest PC 0x0c04f982 */
if(!s->budget--) { s->failed_pc=0x0c04f982u; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c04f984;
P_0c04f984: /* original 4f26, guest PC 0x0c04f984 */
if(!s->budget--) { s->failed_pc=0x0c04f984u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f986;
P_0c04f986: /* original 6cf6, guest PC 0x0c04f986 */
if(!s->budget--) { s->failed_pc=0x0c04f986u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04f988;
P_0c04f988: /* original 6df6, guest PC 0x0c04f988 */
if(!s->budget--) { s->failed_pc=0x0c04f988u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04f98a;
P_0c04f98a: /* original 000b, guest PC 0x0c04f98a */
if(!s->budget--) { s->failed_pc=0x0c04f98au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f98c: /* original 6ef6, guest PC 0x0c04f98c */
if(!s->budget--) { s->failed_pc=0x0c04f98cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04f98eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
