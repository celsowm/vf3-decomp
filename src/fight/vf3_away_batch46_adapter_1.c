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
int vf3_away_batch46_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07b6f4u: goto P_0c07b6f4;
case 0x0c07b6f6u: goto P_0c07b6f6;
case 0x0c07b6f8u: goto P_0c07b6f8;
case 0x0c07b6fau: goto P_0c07b6fa;
case 0x0c07b6fcu: goto P_0c07b6fc;
case 0x0c07b6feu: goto P_0c07b6fe;
case 0x0c07b700u: goto P_0c07b700;
case 0x0c07b702u: goto P_0c07b702;
case 0x0c07b704u: goto P_0c07b704;
case 0x0c07b706u: goto P_0c07b706;
case 0x0c07b708u: goto P_0c07b708;
case 0x0c07b70au: goto P_0c07b70a;
case 0x0c07b70cu: goto P_0c07b70c;
case 0x0c07b70eu: goto P_0c07b70e;
case 0x0c07b710u: goto P_0c07b710;
case 0x0c07b712u: goto P_0c07b712;
case 0x0c07b714u: goto P_0c07b714;
case 0x0c07b716u: goto P_0c07b716;
case 0x0c07b718u: goto P_0c07b718;
case 0x0c07b71au: goto P_0c07b71a;
case 0x0c07f714u: goto P_0c07f714;
case 0x0c07f716u: goto P_0c07f716;
case 0x0c07f718u: goto P_0c07f718;
case 0x0c07f71au: goto P_0c07f71a;
case 0x0c07f71cu: goto P_0c07f71c;
case 0x0c07f71eu: goto P_0c07f71e;
case 0x0c07f720u: goto P_0c07f720;
case 0x0c07f722u: goto P_0c07f722;
case 0x0c07f724u: goto P_0c07f724;
case 0x0c07f726u: goto P_0c07f726;
case 0x0c07f728u: goto P_0c07f728;
case 0x0c07f72au: goto P_0c07f72a;
case 0x0c07f72cu: goto P_0c07f72c;
case 0x0c07f72eu: goto P_0c07f72e;
case 0x0c07f730u: goto P_0c07f730;
case 0x0c07f732u: goto P_0c07f732;
case 0x0c07f734u: goto P_0c07f734;
case 0x0c07f736u: goto P_0c07f736;
case 0x0c07f738u: goto P_0c07f738;
case 0x0c07f73au: goto P_0c07f73a;
case 0x0c07f73cu: goto P_0c07f73c;
case 0x0c07f73eu: goto P_0c07f73e;
case 0x0c07f740u: goto P_0c07f740;
case 0x0c07f742u: goto P_0c07f742;
case 0x0c07f744u: goto P_0c07f744;
case 0x0c07f746u: goto P_0c07f746;
case 0x0c07f748u: goto P_0c07f748;
case 0x0c07f74au: goto P_0c07f74a;
case 0x0c07f74cu: goto P_0c07f74c;
case 0x0c07f74eu: goto P_0c07f74e;
case 0x0c07f750u: goto P_0c07f750;
case 0x0c07f752u: goto P_0c07f752;
case 0x0c07f754u: goto P_0c07f754;
case 0x0c07f756u: goto P_0c07f756;
case 0x0c07f758u: goto P_0c07f758;
case 0x0c07f75au: goto P_0c07f75a;
case 0x0c07f75cu: goto P_0c07f75c;
case 0x0c07f75eu: goto P_0c07f75e;
case 0x0c07f760u: goto P_0c07f760;
case 0x0c07f762u: goto P_0c07f762;
case 0x0c07f764u: goto P_0c07f764;
case 0x0c07f766u: goto P_0c07f766;
case 0x0c07f768u: goto P_0c07f768;
case 0x0c07f76au: goto P_0c07f76a;
case 0x0c07f76cu: goto P_0c07f76c;
case 0x0c07f76eu: goto P_0c07f76e;
case 0x0c07f770u: goto P_0c07f770;
case 0x0c07f772u: goto P_0c07f772;
case 0x0c07f774u: goto P_0c07f774;
case 0x0c07f776u: goto P_0c07f776;
case 0x0c07f778u: goto P_0c07f778;
case 0x0c07f77au: goto P_0c07f77a;
case 0x0c07f77cu: goto P_0c07f77c;
case 0x0c07f77eu: goto P_0c07f77e;
case 0x0c07f780u: goto P_0c07f780;
case 0x0c07f782u: goto P_0c07f782;
case 0x0c07f784u: goto P_0c07f784;
case 0x0c07f786u: goto P_0c07f786;
case 0x0c07f788u: goto P_0c07f788;
case 0x0c07f78au: goto P_0c07f78a;
case 0x0c07f78cu: goto P_0c07f78c;
case 0x0c07f78eu: goto P_0c07f78e;
case 0x0c07f790u: goto P_0c07f790;
case 0x0c07f792u: goto P_0c07f792;
case 0x0c07f794u: goto P_0c07f794;
case 0x0c07f796u: goto P_0c07f796;
case 0x0c07f798u: goto P_0c07f798;
case 0x0c07f79au: goto P_0c07f79a;
case 0x0c07f79cu: goto P_0c07f79c;
case 0x0c07f79eu: goto P_0c07f79e;
case 0x0c07f7a0u: goto P_0c07f7a0;
case 0x0c07f7a2u: goto P_0c07f7a2;
case 0x0c07f7a4u: goto P_0c07f7a4;
case 0x0c07f7a6u: goto P_0c07f7a6;
case 0x0c07f7a8u: goto P_0c07f7a8;
case 0x0c07f7aau: goto P_0c07f7aa;
case 0x0c07f7acu: goto P_0c07f7ac;
case 0x0c07f7aeu: goto P_0c07f7ae;
case 0x0c07f7b0u: goto P_0c07f7b0;
case 0x0c07f7b2u: goto P_0c07f7b2;
case 0x0c07f7b4u: goto P_0c07f7b4;
case 0x0c07f7b6u: goto P_0c07f7b6;
case 0x0c07f7b8u: goto P_0c07f7b8;
case 0x0c07f7bau: goto P_0c07f7ba;
case 0x0c07f7bcu: goto P_0c07f7bc;
case 0x0c07f7beu: goto P_0c07f7be;
case 0x0c07f7c0u: goto P_0c07f7c0;
case 0x0c07f7c2u: goto P_0c07f7c2;
case 0x0c07f7c4u: goto P_0c07f7c4;
case 0x0c07f7c6u: goto P_0c07f7c6;
case 0x0c07f7c8u: goto P_0c07f7c8;
case 0x0c07f7cau: goto P_0c07f7ca;
case 0x0c07f7ccu: goto P_0c07f7cc;
case 0x0c07f7ceu: goto P_0c07f7ce;
case 0x0c07f7d0u: goto P_0c07f7d0;
case 0x0c07f7d2u: goto P_0c07f7d2;
case 0x0c07f7d4u: goto P_0c07f7d4;
case 0x0c07f7d6u: goto P_0c07f7d6;
case 0x0c07f7d8u: goto P_0c07f7d8;
case 0x0c07f7dau: goto P_0c07f7da;
case 0x0c07f7dcu: goto P_0c07f7dc;
case 0x0c07f7deu: goto P_0c07f7de;
case 0x0c07f7e0u: goto P_0c07f7e0;
case 0x0c07f7e2u: goto P_0c07f7e2;
case 0x0c07f7e4u: goto P_0c07f7e4;
case 0x0c07f7e6u: goto P_0c07f7e6;
case 0x0c07f7e8u: goto P_0c07f7e8;
case 0x0c07f7eau: goto P_0c07f7ea;
case 0x0c07f7ecu: goto P_0c07f7ec;
case 0x0c07f7eeu: goto P_0c07f7ee;
case 0x0c07f7f0u: goto P_0c07f7f0;
case 0x0c07f7f2u: goto P_0c07f7f2;
case 0x0c07f7f4u: goto P_0c07f7f4;
case 0x0c07f7f6u: goto P_0c07f7f6;
case 0x0c07f7f8u: goto P_0c07f7f8;
case 0x0c07f7fau: goto P_0c07f7fa;
case 0x0c07f7fcu: goto P_0c07f7fc;
case 0x0c07f7feu: goto P_0c07f7fe;
case 0x0c07f800u: goto P_0c07f800;
case 0x0c07f802u: goto P_0c07f802;
case 0x0c07f804u: goto P_0c07f804;
case 0x0c07f806u: goto P_0c07f806;
case 0x0c07f808u: goto P_0c07f808;
case 0x0c07f80au: goto P_0c07f80a;
case 0x0c07f80cu: goto P_0c07f80c;
case 0x0c07f80eu: goto P_0c07f80e;
case 0x0c07f810u: goto P_0c07f810;
case 0x0c07f812u: goto P_0c07f812;
case 0x0c07f814u: goto P_0c07f814;
case 0x0c07f816u: goto P_0c07f816;
case 0x0c07f818u: goto P_0c07f818;
case 0x0c07f81au: goto P_0c07f81a;
case 0x0c07f81cu: goto P_0c07f81c;
case 0x0c07f81eu: goto P_0c07f81e;
case 0x0c07f820u: goto P_0c07f820;
case 0x0c07f822u: goto P_0c07f822;
case 0x0c07f824u: goto P_0c07f824;
case 0x0c07f826u: goto P_0c07f826;
case 0x0c07f828u: goto P_0c07f828;
case 0x0c07f82au: goto P_0c07f82a;
case 0x0c07f82cu: goto P_0c07f82c;
case 0x0c07f82eu: goto P_0c07f82e;
case 0x0c07f830u: goto P_0c07f830;
case 0x0c07f832u: goto P_0c07f832;
case 0x0c07f834u: goto P_0c07f834;
case 0x0c07f836u: goto P_0c07f836;
case 0x0c07f864u: goto P_0c07f864;
case 0x0c07f866u: goto P_0c07f866;
case 0x0c07f868u: goto P_0c07f868;
case 0x0c07f86au: goto P_0c07f86a;
case 0x0c07f86cu: goto P_0c07f86c;
case 0x0c07f86eu: goto P_0c07f86e;
case 0x0c07f870u: goto P_0c07f870;
case 0x0c07f872u: goto P_0c07f872;
case 0x0c07f874u: goto P_0c07f874;
case 0x0c07f876u: goto P_0c07f876;
case 0x0c07f878u: goto P_0c07f878;
case 0x0c07f87au: goto P_0c07f87a;
case 0x0c07f87cu: goto P_0c07f87c;
case 0x0c07f87eu: goto P_0c07f87e;
case 0x0c07f880u: goto P_0c07f880;
case 0x0c07f882u: goto P_0c07f882;
case 0x0c07f884u: goto P_0c07f884;
case 0x0c07f886u: goto P_0c07f886;
case 0x0c07f888u: goto P_0c07f888;
case 0x0c07f88au: goto P_0c07f88a;
case 0x0c07f88cu: goto P_0c07f88c;
case 0x0c07f88eu: goto P_0c07f88e;
case 0x0c07f890u: goto P_0c07f890;
case 0x0c07f892u: goto P_0c07f892;
case 0x0c07f894u: goto P_0c07f894;
case 0x0c07f896u: goto P_0c07f896;
case 0x0c07f898u: goto P_0c07f898;
case 0x0c07f89au: goto P_0c07f89a;
case 0x0c07f89cu: goto P_0c07f89c;
case 0x0c07f89eu: goto P_0c07f89e;
case 0x0c07f8a0u: goto P_0c07f8a0;
case 0x0c07f8a2u: goto P_0c07f8a2;
case 0x0c07f8a4u: goto P_0c07f8a4;
case 0x0c07f8a6u: goto P_0c07f8a6;
case 0x0c07f8a8u: goto P_0c07f8a8;
case 0x0c07f8aau: goto P_0c07f8aa;
case 0x0c07f8acu: goto P_0c07f8ac;
case 0x0c07f8aeu: goto P_0c07f8ae;
case 0x0c07f8b0u: goto P_0c07f8b0;
case 0x0c07f8b2u: goto P_0c07f8b2;
case 0x0c07f8b4u: goto P_0c07f8b4;
case 0x0c07f8b6u: goto P_0c07f8b6;
case 0x0c07f8b8u: goto P_0c07f8b8;
case 0x0c07f8bau: goto P_0c07f8ba;
case 0x0c07f8bcu: goto P_0c07f8bc;
case 0x0c07f8beu: goto P_0c07f8be;
case 0x0c07f8c0u: goto P_0c07f8c0;
case 0x0c07f8c2u: goto P_0c07f8c2;
case 0x0c07f8c4u: goto P_0c07f8c4;
case 0x0c07f8c6u: goto P_0c07f8c6;
case 0x0c07f8c8u: goto P_0c07f8c8;
case 0x0c07f8cau: goto P_0c07f8ca;
case 0x0c07f8ccu: goto P_0c07f8cc;
case 0x0c07f8ceu: goto P_0c07f8ce;
case 0x0c07f8d0u: goto P_0c07f8d0;
case 0x0c07f8d2u: goto P_0c07f8d2;
case 0x0c07f8d4u: goto P_0c07f8d4;
case 0x0c07f8d6u: goto P_0c07f8d6;
case 0x0c07f8d8u: goto P_0c07f8d8;
case 0x0c07f8dau: goto P_0c07f8da;
case 0x0c07f8dcu: goto P_0c07f8dc;
case 0x0c07f8deu: goto P_0c07f8de;
case 0x0c07f8e0u: goto P_0c07f8e0;
case 0x0c07f8e2u: goto P_0c07f8e2;
case 0x0c07f8e4u: goto P_0c07f8e4;
case 0x0c07f8e6u: goto P_0c07f8e6;
case 0x0c07f8e8u: goto P_0c07f8e8;
case 0x0c07f8eau: goto P_0c07f8ea;
case 0x0c07f8ecu: goto P_0c07f8ec;
case 0x0c07f8eeu: goto P_0c07f8ee;
case 0x0c07f8f0u: goto P_0c07f8f0;
case 0x0c07f8f2u: goto P_0c07f8f2;
case 0x0c07f8f4u: goto P_0c07f8f4;
case 0x0c07f8f6u: goto P_0c07f8f6;
case 0x0c07f8f8u: goto P_0c07f8f8;
case 0x0c07f8fau: goto P_0c07f8fa;
case 0x0c07f8fcu: goto P_0c07f8fc;
case 0x0c07f8feu: goto P_0c07f8fe;
case 0x0c07f900u: goto P_0c07f900;
case 0x0c07f902u: goto P_0c07f902;
case 0x0c07f904u: goto P_0c07f904;
case 0x0c07f906u: goto P_0c07f906;
case 0x0c07f908u: goto P_0c07f908;
case 0x0c07f90au: goto P_0c07f90a;
case 0x0c07f90cu: goto P_0c07f90c;
case 0x0c07f90eu: goto P_0c07f90e;
case 0x0c07f910u: goto P_0c07f910;
case 0x0c07f912u: goto P_0c07f912;
case 0x0c07f914u: goto P_0c07f914;
case 0x0c07f916u: goto P_0c07f916;
case 0x0c07f918u: goto P_0c07f918;
case 0x0c07f91au: goto P_0c07f91a;
case 0x0c07f91cu: goto P_0c07f91c;
case 0x0c07f91eu: goto P_0c07f91e;
case 0x0c07f920u: goto P_0c07f920;
case 0x0c07f922u: goto P_0c07f922;
case 0x0c07f924u: goto P_0c07f924;
case 0x0c07f926u: goto P_0c07f926;
case 0x0c07f928u: goto P_0c07f928;
case 0x0c07f92au: goto P_0c07f92a;
case 0x0c07f92cu: goto P_0c07f92c;
case 0x0c07f92eu: goto P_0c07f92e;
case 0x0c07f930u: goto P_0c07f930;
case 0x0c07f932u: goto P_0c07f932;
case 0x0c07f934u: goto P_0c07f934;
case 0x0c07f936u: goto P_0c07f936;
case 0x0c07f938u: goto P_0c07f938;
case 0x0c07f93au: goto P_0c07f93a;
case 0x0c07f93cu: goto P_0c07f93c;
case 0x0c07f93eu: goto P_0c07f93e;
case 0x0c07f940u: goto P_0c07f940;
case 0x0c07f942u: goto P_0c07f942;
case 0x0c07f944u: goto P_0c07f944;
case 0x0c07f946u: goto P_0c07f946;
case 0x0c07f948u: goto P_0c07f948;
case 0x0c07f94au: goto P_0c07f94a;
case 0x0c07f94cu: goto P_0c07f94c;
case 0x0c07f94eu: goto P_0c07f94e;
case 0x0c07f950u: goto P_0c07f950;
case 0x0c07f952u: goto P_0c07f952;
case 0x0c07f954u: goto P_0c07f954;
case 0x0c07f956u: goto P_0c07f956;
case 0x0c07f958u: goto P_0c07f958;
case 0x0c07f95au: goto P_0c07f95a;
case 0x0c07f95cu: goto P_0c07f95c;
case 0x0c07f95eu: goto P_0c07f95e;
case 0x0c07f960u: goto P_0c07f960;
case 0x0c07f962u: goto P_0c07f962;
case 0x0c07f964u: goto P_0c07f964;
case 0x0c07f966u: goto P_0c07f966;
case 0x0c07f968u: goto P_0c07f968;
case 0x0c07f96au: goto P_0c07f96a;
case 0x0c07f96cu: goto P_0c07f96c;
case 0x0c07f96eu: goto P_0c07f96e;
case 0x0c07f970u: goto P_0c07f970;
case 0x0c07f972u: goto P_0c07f972;
case 0x0c07f974u: goto P_0c07f974;
case 0x0c07f976u: goto P_0c07f976;
case 0x0c07f9c4u: goto P_0c07f9c4;
case 0x0c07f9c6u: goto P_0c07f9c6;
case 0x0c07f9c8u: goto P_0c07f9c8;
case 0x0c07f9cau: goto P_0c07f9ca;
case 0x0c07f9ccu: goto P_0c07f9cc;
case 0x0c07f9ceu: goto P_0c07f9ce;
case 0x0c07f9d0u: goto P_0c07f9d0;
case 0x0c07f9d2u: goto P_0c07f9d2;
case 0x0c07f9d4u: goto P_0c07f9d4;
case 0x0c07f9d6u: goto P_0c07f9d6;
case 0x0c07f9d8u: goto P_0c07f9d8;
case 0x0c07f9dau: goto P_0c07f9da;
case 0x0c07f9dcu: goto P_0c07f9dc;
case 0x0c07f9deu: goto P_0c07f9de;
case 0x0c07f9e0u: goto P_0c07f9e0;
case 0x0c07f9e2u: goto P_0c07f9e2;
case 0x0c07f9e4u: goto P_0c07f9e4;
case 0x0c07f9e6u: goto P_0c07f9e6;
case 0x0c07f9e8u: goto P_0c07f9e8;
case 0x0c07f9eau: goto P_0c07f9ea;
case 0x0c07f9ecu: goto P_0c07f9ec;
case 0x0c07f9eeu: goto P_0c07f9ee;
case 0x0c07f9f0u: goto P_0c07f9f0;
case 0x0c07f9f2u: goto P_0c07f9f2;
case 0x0c07f9f4u: goto P_0c07f9f4;
case 0x0c07f9f6u: goto P_0c07f9f6;
case 0x0c07f9f8u: goto P_0c07f9f8;
case 0x0c07f9fau: goto P_0c07f9fa;
case 0x0c07f9fcu: goto P_0c07f9fc;
case 0x0c07f9feu: goto P_0c07f9fe;
case 0x0c07fa00u: goto P_0c07fa00;
case 0x0c07fa02u: goto P_0c07fa02;
case 0x0c07fa04u: goto P_0c07fa04;
case 0x0c07fa06u: goto P_0c07fa06;
case 0x0c07fa08u: goto P_0c07fa08;
case 0x0c07fa0au: goto P_0c07fa0a;
case 0x0c07fa0cu: goto P_0c07fa0c;
case 0x0c07fa0eu: goto P_0c07fa0e;
case 0x0c07fa10u: goto P_0c07fa10;
case 0x0c07fa12u: goto P_0c07fa12;
case 0x0c07fa14u: goto P_0c07fa14;
case 0x0c07fa16u: goto P_0c07fa16;
case 0x0c07fa18u: goto P_0c07fa18;
case 0x0c07fa1au: goto P_0c07fa1a;
case 0x0c07fa1cu: goto P_0c07fa1c;
case 0x0c07fa1eu: goto P_0c07fa1e;
case 0x0c07fa20u: goto P_0c07fa20;
case 0x0c07fa22u: goto P_0c07fa22;
case 0x0c07fa24u: goto P_0c07fa24;
case 0x0c07fa26u: goto P_0c07fa26;
case 0x0c07fa28u: goto P_0c07fa28;
case 0x0c07fa2au: goto P_0c07fa2a;
case 0x0c07fa2cu: goto P_0c07fa2c;
case 0x0c07fa2eu: goto P_0c07fa2e;
case 0x0c07fa30u: goto P_0c07fa30;
case 0x0c07fa32u: goto P_0c07fa32;
case 0x0c07fa34u: goto P_0c07fa34;
case 0x0c07fa36u: goto P_0c07fa36;
case 0x0c07fa38u: goto P_0c07fa38;
case 0x0c07fa3au: goto P_0c07fa3a;
case 0x0c07fa3cu: goto P_0c07fa3c;
case 0x0c07fa3eu: goto P_0c07fa3e;
case 0x0c07fa40u: goto P_0c07fa40;
case 0x0c07fa42u: goto P_0c07fa42;
case 0x0c07fa44u: goto P_0c07fa44;
case 0x0c07fa46u: goto P_0c07fa46;
case 0x0c07fa48u: goto P_0c07fa48;
case 0x0c07fa4au: goto P_0c07fa4a;
case 0x0c07fa4cu: goto P_0c07fa4c;
case 0x0c07fa4eu: goto P_0c07fa4e;
case 0x0c07fa50u: goto P_0c07fa50;
case 0x0c07fa52u: goto P_0c07fa52;
case 0x0c07fa54u: goto P_0c07fa54;
case 0x0c07fa56u: goto P_0c07fa56;
case 0x0c07fa58u: goto P_0c07fa58;
case 0x0c07fa5au: goto P_0c07fa5a;
case 0x0c07fa5cu: goto P_0c07fa5c;
case 0x0c07fa5eu: goto P_0c07fa5e;
case 0x0c07fa60u: goto P_0c07fa60;
case 0x0c07fa62u: goto P_0c07fa62;
case 0x0c07fa64u: goto P_0c07fa64;
case 0x0c07fa66u: goto P_0c07fa66;
case 0x0c07fa68u: goto P_0c07fa68;
case 0x0c07fa6au: goto P_0c07fa6a;
case 0x0c07fa6cu: goto P_0c07fa6c;
case 0x0c07fa6eu: goto P_0c07fa6e;
case 0x0c07fa70u: goto P_0c07fa70;
case 0x0c07fa72u: goto P_0c07fa72;
case 0x0c07fa74u: goto P_0c07fa74;
case 0x0c07fa76u: goto P_0c07fa76;
case 0x0c07fa78u: goto P_0c07fa78;
case 0x0c07fa7au: goto P_0c07fa7a;
case 0x0c07fa7cu: goto P_0c07fa7c;
case 0x0c07fa7eu: goto P_0c07fa7e;
case 0x0c07fa80u: goto P_0c07fa80;
case 0x0c07fa82u: goto P_0c07fa82;
case 0x0c07fa84u: goto P_0c07fa84;
case 0x0c07fa86u: goto P_0c07fa86;
case 0x0c07fa88u: goto P_0c07fa88;
case 0x0c07fa8au: goto P_0c07fa8a;
case 0x0c07fa8cu: goto P_0c07fa8c;
case 0x0c07fa8eu: goto P_0c07fa8e;
case 0x0c07fa90u: goto P_0c07fa90;
case 0x0c07fa92u: goto P_0c07fa92;
case 0x0c07fa94u: goto P_0c07fa94;
case 0x0c07fa96u: goto P_0c07fa96;
case 0x0c07fa98u: goto P_0c07fa98;
case 0x0c07fa9au: goto P_0c07fa9a;
case 0x0c07fa9cu: goto P_0c07fa9c;
case 0x0c07fa9eu: goto P_0c07fa9e;
case 0x0c07faa0u: goto P_0c07faa0;
case 0x0c07faa2u: goto P_0c07faa2;
case 0x0c07faa4u: goto P_0c07faa4;
case 0x0c07faa6u: goto P_0c07faa6;
case 0x0c07faa8u: goto P_0c07faa8;
case 0x0c07faaau: goto P_0c07faaa;
case 0x0c07faacu: goto P_0c07faac;
case 0x0c07faaeu: goto P_0c07faae;
case 0x0c07fab0u: goto P_0c07fab0;
case 0x0c07fab2u: goto P_0c07fab2;
case 0x0c07fab4u: goto P_0c07fab4;
case 0x0c07fab6u: goto P_0c07fab6;
case 0x0c07fab8u: goto P_0c07fab8;
case 0x0c07fabau: goto P_0c07faba;
case 0x0c07fabcu: goto P_0c07fabc;
case 0x0c07fabeu: goto P_0c07fabe;
case 0x0c07fac0u: goto P_0c07fac0;
case 0x0c07fac2u: goto P_0c07fac2;
case 0x0c07fac4u: goto P_0c07fac4;
case 0x0c07fac6u: goto P_0c07fac6;
case 0x0c07fac8u: goto P_0c07fac8;
case 0x0c07facau: goto P_0c07faca;
case 0x0c07faccu: goto P_0c07facc;
case 0x0c07faceu: goto P_0c07face;
case 0x0c07fad0u: goto P_0c07fad0;
case 0x0c07fad2u: goto P_0c07fad2;
case 0x0c07fad4u: goto P_0c07fad4;
case 0x0c07fad6u: goto P_0c07fad6;
case 0x0c07fad8u: goto P_0c07fad8;
case 0x0c07fadau: goto P_0c07fada;
case 0x0c07fadcu: goto P_0c07fadc;
case 0x0c07fadeu: goto P_0c07fade;
case 0x0c07fb24u: goto P_0c07fb24;
case 0x0c07fb26u: goto P_0c07fb26;
case 0x0c07fb28u: goto P_0c07fb28;
case 0x0c07fb2au: goto P_0c07fb2a;
case 0x0c07fb2cu: goto P_0c07fb2c;
case 0x0c07fb2eu: goto P_0c07fb2e;
case 0x0c07fb30u: goto P_0c07fb30;
case 0x0c07fb32u: goto P_0c07fb32;
case 0x0c07fb34u: goto P_0c07fb34;
case 0x0c07fb36u: goto P_0c07fb36;
case 0x0c07fb38u: goto P_0c07fb38;
case 0x0c07fb3au: goto P_0c07fb3a;
case 0x0c07fb3cu: goto P_0c07fb3c;
case 0x0c07fb3eu: goto P_0c07fb3e;
case 0x0c07fb40u: goto P_0c07fb40;
case 0x0c07fb42u: goto P_0c07fb42;
case 0x0c07fb44u: goto P_0c07fb44;
case 0x0c07fb46u: goto P_0c07fb46;
case 0x0c07fb48u: goto P_0c07fb48;
case 0x0c07fb4au: goto P_0c07fb4a;
case 0x0c07fb4cu: goto P_0c07fb4c;
case 0x0c07fb4eu: goto P_0c07fb4e;
case 0x0c07fb50u: goto P_0c07fb50;
case 0x0c07fb52u: goto P_0c07fb52;
case 0x0c07fb54u: goto P_0c07fb54;
case 0x0c07fb56u: goto P_0c07fb56;
case 0x0c07fb58u: goto P_0c07fb58;
case 0x0c07fb5au: goto P_0c07fb5a;
case 0x0c07fb5cu: goto P_0c07fb5c;
case 0x0c07fb5eu: goto P_0c07fb5e;
case 0x0c07fb60u: goto P_0c07fb60;
case 0x0c07fb62u: goto P_0c07fb62;
case 0x0c07fb64u: goto P_0c07fb64;
case 0x0c07fb66u: goto P_0c07fb66;
case 0x0c07fb68u: goto P_0c07fb68;
case 0x0c07fb6au: goto P_0c07fb6a;
case 0x0c07fb6cu: goto P_0c07fb6c;
case 0x0c07fb6eu: goto P_0c07fb6e;
case 0x0c07fb70u: goto P_0c07fb70;
case 0x0c07fb72u: goto P_0c07fb72;
case 0x0c07fb74u: goto P_0c07fb74;
case 0x0c07fb76u: goto P_0c07fb76;
case 0x0c07fb78u: goto P_0c07fb78;
case 0x0c07fb7au: goto P_0c07fb7a;
case 0x0c07fb7cu: goto P_0c07fb7c;
case 0x0c07fb7eu: goto P_0c07fb7e;
case 0x0c07fb80u: goto P_0c07fb80;
case 0x0c07fb82u: goto P_0c07fb82;
case 0x0c07fb84u: goto P_0c07fb84;
case 0x0c07fb86u: goto P_0c07fb86;
case 0x0c07fb88u: goto P_0c07fb88;
case 0x0c07fb8au: goto P_0c07fb8a;
case 0x0c07fb8cu: goto P_0c07fb8c;
case 0x0c07fb8eu: goto P_0c07fb8e;
case 0x0c07fb90u: goto P_0c07fb90;
case 0x0c07fb92u: goto P_0c07fb92;
case 0x0c07fb94u: goto P_0c07fb94;
case 0x0c07fb96u: goto P_0c07fb96;
case 0x0c07fb98u: goto P_0c07fb98;
case 0x0c07fb9au: goto P_0c07fb9a;
case 0x0c07fb9cu: goto P_0c07fb9c;
case 0x0c07fb9eu: goto P_0c07fb9e;
case 0x0c07fba0u: goto P_0c07fba0;
case 0x0c07fba2u: goto P_0c07fba2;
case 0x0c07fba4u: goto P_0c07fba4;
case 0x0c07fba6u: goto P_0c07fba6;
case 0x0c07fba8u: goto P_0c07fba8;
case 0x0c07fbaau: goto P_0c07fbaa;
case 0x0c07fbacu: goto P_0c07fbac;
case 0x0c07fbaeu: goto P_0c07fbae;
case 0x0c07fbb0u: goto P_0c07fbb0;
case 0x0c07fbb2u: goto P_0c07fbb2;
case 0x0c07fbb4u: goto P_0c07fbb4;
case 0x0c07fbb6u: goto P_0c07fbb6;
case 0x0c07fbb8u: goto P_0c07fbb8;
case 0x0c07fbbau: goto P_0c07fbba;
case 0x0c07fbbcu: goto P_0c07fbbc;
case 0x0c07fbbeu: goto P_0c07fbbe;
case 0x0c07fbc0u: goto P_0c07fbc0;
case 0x0c07fbc2u: goto P_0c07fbc2;
case 0x0c07fbc4u: goto P_0c07fbc4;
case 0x0c07fbc6u: goto P_0c07fbc6;
case 0x0c07fbc8u: goto P_0c07fbc8;
case 0x0c07fbcau: goto P_0c07fbca;
case 0x0c07fbccu: goto P_0c07fbcc;
case 0x0c07fbceu: goto P_0c07fbce;
case 0x0c07fbd0u: goto P_0c07fbd0;
case 0x0c07fbd2u: goto P_0c07fbd2;
case 0x0c07fbd4u: goto P_0c07fbd4;
case 0x0c07fbd6u: goto P_0c07fbd6;
case 0x0c07fbd8u: goto P_0c07fbd8;
case 0x0c07fbdau: goto P_0c07fbda;
case 0x0c07fbdcu: goto P_0c07fbdc;
case 0x0c07fbdeu: goto P_0c07fbde;
case 0x0c07fbe0u: goto P_0c07fbe0;
case 0x0c07fbe2u: goto P_0c07fbe2;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07b6f4: /* original 4f22, guest PC 0x0c07b6f4 */
if(!s->budget--) { s->failed_pc=0x0c07b6f4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b6f6;
P_0c07b6f6: /* original 7ff4, guest PC 0x0c07b6f6 */
if(!s->budget--) { s->failed_pc=0x0c07b6f6u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c07b6f8;
P_0c07b6f8: /* original 2f42, guest PC 0x0c07b6f8 */
if(!s->budget--) { s->failed_pc=0x0c07b6f8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07b6fa;
P_0c07b6fa: /* original 1f51, guest PC 0x0c07b6fa */
if(!s->budget--) { s->failed_pc=0x0c07b6fau; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c07b6fc;
P_0c07b6fc: /* original 1f72, guest PC 0x0c07b6fc */
if(!s->budget--) { s->failed_pc=0x0c07b6fcu; return 0; }
write(ram,r[15]+8,r[7],4);
goto P_0c07b6fe;
P_0c07b6fe: /* original e700, guest PC 0x0c07b6fe */
if(!s->budget--) { s->failed_pc=0x0c07b6feu; return 0; }
r[7]=0x00000000u;
goto P_0c07b700;
P_0c07b700: /* original 53f4, guest PC 0x0c07b700 */
if(!s->budget--) { s->failed_pc=0x0c07b700u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c07b702;
P_0c07b702: /* original 2f36, guest PC 0x0c07b702 */
if(!s->budget--) { s->failed_pc=0x0c07b702u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b704;
P_0c07b704: /* original 52f3, guest PC 0x0c07b704 */
if(!s->budget--) { s->failed_pc=0x0c07b704u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c07b706;
P_0c07b706: /* original 2f26, guest PC 0x0c07b706 */
if(!s->budget--) { s->failed_pc=0x0c07b706u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b708;
P_0c07b708: /* original 55f3, guest PC 0x0c07b708 */
if(!s->budget--) { s->failed_pc=0x0c07b708u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c07b70a;
P_0c07b70a: /* original d309, guest PC 0x0c07b70a */
if(!s->budget--) { s->failed_pc=0x0c07b70au; return 0; }
r[3]=read(ram,0x0c07b730u,4);
goto P_0c07b70c;
P_0c07b70c: /* original d207, guest PC 0x0c07b70c */
if(!s->budget--) { s->failed_pc=0x0c07b70cu; return 0; }
r[2]=read(ram,0x0c07b72cu,4);
goto P_0c07b70e;
P_0c07b70e: /* original 253b, guest PC 0x0c07b70e */
if(!s->budget--) { s->failed_pc=0x0c07b70eu; return 0; }
r[5]|=r[3];
goto P_0c07b710;
P_0c07b710: /* original 420b, guest PC 0x0c07b710 */
if(!s->budget--) { s->failed_pc=0x0c07b710u; return 0; }
target=r[2];
r[16]=code_base|0x0c07b714u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b714u) { target=s->pc; goto dispatch; }
goto P_0c07b714;
P_0c07b712: /* original 54f2, guest PC 0x0c07b712 */
if(!s->budget--) { s->failed_pc=0x0c07b712u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07b714;
P_0c07b714: /* original 7f14, guest PC 0x0c07b714 */
if(!s->budget--) { s->failed_pc=0x0c07b714u; return 0; }
r[15]+=0x00000014u;
goto P_0c07b716;
P_0c07b716: /* original 4f26, guest PC 0x0c07b716 */
if(!s->budget--) { s->failed_pc=0x0c07b716u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b718;
P_0c07b718: /* original 000b, guest PC 0x0c07b718 */
if(!s->budget--) { s->failed_pc=0x0c07b718u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07b71a: /* original 0009, guest PC 0x0c07b71a */
if(!s->budget--) { s->failed_pc=0x0c07b71au; return 0; }
if(!vf3_matrix_family(0x0c07b71cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b71cu; return 0; } return 1;
P_0c07f714: /* original 2fe6, guest PC 0x0c07f714 */
if(!s->budget--) { s->failed_pc=0x0c07f714u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f716;
P_0c07f716: /* original 2fd6, guest PC 0x0c07f716 */
if(!s->budget--) { s->failed_pc=0x0c07f716u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f718;
P_0c07f718: /* original 2fc6, guest PC 0x0c07f718 */
if(!s->budget--) { s->failed_pc=0x0c07f718u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f71a;
P_0c07f71a: /* original 2fb6, guest PC 0x0c07f71a */
if(!s->budget--) { s->failed_pc=0x0c07f71au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f71c;
P_0c07f71c: /* original 2fa6, guest PC 0x0c07f71c */
if(!s->budget--) { s->failed_pc=0x0c07f71cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f71e;
P_0c07f71e: /* original 2f96, guest PC 0x0c07f71e */
if(!s->budget--) { s->failed_pc=0x0c07f71eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f720;
P_0c07f720: /* original 2f86, guest PC 0x0c07f720 */
if(!s->budget--) { s->failed_pc=0x0c07f720u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f722;
P_0c07f722: /* original 4f22, guest PC 0x0c07f722 */
if(!s->budget--) { s->failed_pc=0x0c07f722u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07f724;
P_0c07f724: /* original 7fe8, guest PC 0x0c07f724 */
if(!s->budget--) { s->failed_pc=0x0c07f724u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c07f726;
P_0c07f726: /* original 1f42, guest PC 0x0c07f726 */
if(!s->budget--) { s->failed_pc=0x0c07f726u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c07f728;
P_0c07f728: /* original d348, guest PC 0x0c07f728 */
if(!s->budget--) { s->failed_pc=0x0c07f728u; return 0; }
r[3]=read(ram,0x0c07f84cu,4);
goto P_0c07f72a;
P_0c07f72a: /* original 1f31, guest PC 0x0c07f72a */
if(!s->budget--) { s->failed_pc=0x0c07f72au; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07f72c;
P_0c07f72c: /* original de48, guest PC 0x0c07f72c */
if(!s->budget--) { s->failed_pc=0x0c07f72cu; return 0; }
r[14]=read(ram,0x0c07f850u,4);
goto P_0c07f72e;
P_0c07f72e: /* original 9083, guest PC 0x0c07f72e */
if(!s->budget--) { s->failed_pc=0x0c07f72eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f838u,2);
goto P_0c07f730;
P_0c07f730: /* original 03ec, guest PC 0x0c07f730 */
if(!s->budget--) { s->failed_pc=0x0c07f730u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07f732;
P_0c07f732: /* original 6633, guest PC 0x0c07f732 */
if(!s->budget--) { s->failed_pc=0x0c07f732u; return 0; }
r[6]=r[3];
goto P_0c07f734;
P_0c07f734: /* original 2f32, guest PC 0x0c07f734 */
if(!s->budget--) { s->failed_pc=0x0c07f734u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07f736;
P_0c07f736: /* original 9580, guest PC 0x0c07f736 */
if(!s->budget--) { s->failed_pc=0x0c07f736u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f83au,2);
goto P_0c07f738;
P_0c07f738: /* original d846, guest PC 0x0c07f738 */
if(!s->budget--) { s->failed_pc=0x0c07f738u; return 0; }
r[8]=read(ram,0x0c07f854u,4);
goto P_0c07f73a;
P_0c07f73a: /* original 977f, guest PC 0x0c07f73a */
if(!s->budget--) { s->failed_pc=0x0c07f73au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f83cu,2);
goto P_0c07f73c;
P_0c07f73c: /* original 480b, guest PC 0x0c07f73c */
if(!s->budget--) { s->failed_pc=0x0c07f73cu; return 0; }
target=r[8];
r[16]=code_base|0x0c07f740u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f740u) { target=s->pc; goto dispatch; }
goto P_0c07f740;
P_0c07f73e: /* original 54f1, guest PC 0x0c07f73e */
if(!s->budget--) { s->failed_pc=0x0c07f73eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07f740;
P_0c07f740: /* original 907d, guest PC 0x0c07f740 */
if(!s->budget--) { s->failed_pc=0x0c07f740u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f83eu,2);
goto P_0c07f742;
P_0c07f742: /* original 04ec, guest PC 0x0c07f742 */
if(!s->budget--) { s->failed_pc=0x0c07f742u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07f744;
P_0c07f744: /* original 2448, guest PC 0x0c07f744 */
if(!s->budget--) { s->failed_pc=0x0c07f744u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07f746;
P_0c07f746: /* original 8973, guest PC 0x0c07f746 */
if(!s->budget--) { s->failed_pc=0x0c07f746u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07f830; }
goto P_0c07f748;
P_0c07f748: /* original 907a, guest PC 0x0c07f748 */
if(!s->budget--) { s->failed_pc=0x0c07f748u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f840u,2);
goto P_0c07f74a;
P_0c07f74a: /* original e92b, guest PC 0x0c07f74a */
if(!s->budget--) { s->failed_pc=0x0c07f74au; return 0; }
r[9]=0x0000002bu;
goto P_0c07f74c;
P_0c07f74c: /* original 9379, guest PC 0x0c07f74c */
if(!s->budget--) { s->failed_pc=0x0c07f74cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f842u,2);
goto P_0c07f74e;
P_0c07f74e: /* original 6493, guest PC 0x0c07f74e */
if(!s->budget--) { s->failed_pc=0x0c07f74eu; return 0; }
r[4]=r[9];
goto P_0c07f750;
P_0c07f750: /* original 0cec, guest PC 0x0c07f750 */
if(!s->budget--) { s->failed_pc=0x0c07f750u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07f752;
P_0c07f752: /* original 7001, guest PC 0x0c07f752 */
if(!s->budget--) { s->failed_pc=0x0c07f752u; return 0; }
r[0]+=0x00000001u;
goto P_0c07f754;
P_0c07f754: /* original 33ec, guest PC 0x0c07f754 */
if(!s->budget--) { s->failed_pc=0x0c07f754u; return 0; }
r[3]+=r[14];
goto P_0c07f756;
P_0c07f756: /* original 0bec, guest PC 0x0c07f756 */
if(!s->budget--) { s->failed_pc=0x0c07f756u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07f758;
P_0c07f758: /* original 65ce, guest PC 0x0c07f758 */
if(!s->budget--) { s->failed_pc=0x0c07f758u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[12];
goto P_0c07f75a;
P_0c07f75a: /* original 353c, guest PC 0x0c07f75a */
if(!s->budget--) { s->failed_pc=0x0c07f75au; return 0; }
r[5]+=r[3];
goto P_0c07f75c;
P_0c07f75c: /* original 9372, guest PC 0x0c07f75c */
if(!s->budget--) { s->failed_pc=0x0c07f75cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f844u,2);
goto P_0c07f75e;
P_0c07f75e: /* original 6550, guest PC 0x0c07f75e */
if(!s->budget--) { s->failed_pc=0x0c07f75eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c07f760;
P_0c07f760: /* original 655c, guest PC 0x0c07f760 */
if(!s->budget--) { s->failed_pc=0x0c07f760u; return 0; }
r[5]=r[5]&255u;
goto P_0c07f762;
P_0c07f762: /* original 6253, guest PC 0x0c07f762 */
if(!s->budget--) { s->failed_pc=0x0c07f762u; return 0; }
r[2]=r[5];
goto P_0c07f764;
P_0c07f764: /* original 3230, guest PC 0x0c07f764 */
if(!s->budget--) { s->failed_pc=0x0c07f764u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c07f766;
P_0c07f766: /* original 8d63, guest PC 0x0c07f766 */
if(!s->budget--) { s->failed_pc=0x0c07f766u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+16,r[5],4);
if(cond) { goto P_0c07f830; }
goto P_0c07f76a;
P_0c07f768: /* original 1f54, guest PC 0x0c07f768 */
if(!s->budget--) { s->failed_pc=0x0c07f768u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c07f76a;
P_0c07f76a: /* original 63c3, guest PC 0x0c07f76a */
if(!s->budget--) { s->failed_pc=0x0c07f76au; return 0; }
r[3]=r[12];
goto P_0c07f76c;
P_0c07f76c: /* original 60c3, guest PC 0x0c07f76c */
if(!s->budget--) { s->failed_pc=0x0c07f76cu; return 0; }
r[0]=r[12];
goto P_0c07f76e;
P_0c07f76e: /* original 4308, guest PC 0x0c07f76e */
if(!s->budget--) { s->failed_pc=0x0c07f76eu; return 0; }
r[3]<<=2;
goto P_0c07f770;
P_0c07f770: /* original 4000, guest PC 0x0c07f770 */
if(!s->budget--) { s->failed_pc=0x0c07f770u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07f772;
P_0c07f772: /* original 303c, guest PC 0x0c07f772 */
if(!s->budget--) { s->failed_pc=0x0c07f772u; return 0; }
r[0]+=r[3];
goto P_0c07f774;
P_0c07f774: /* original 3408, guest PC 0x0c07f774 */
if(!s->budget--) { s->failed_pc=0x0c07f774u; return 0; }
r[4]-=r[0];
goto P_0c07f776;
P_0c07f776: /* original 80fc, guest PC 0x0c07f776 */
if(!s->budget--) { s->failed_pc=0x0c07f776u; return 0; }
write(ram,r[15]+12,r[0],1);
goto P_0c07f778;
P_0c07f778: /* original 654e, guest PC 0x0c07f778 */
if(!s->budget--) { s->failed_pc=0x0c07f778u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c07f77a;
P_0c07f77a: /* original 9a64, guest PC 0x0c07f77a */
if(!s->budget--) { s->failed_pc=0x0c07f77au; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f846u,2);
goto P_0c07f77c;
P_0c07f77c: /* original 63ce, guest PC 0x0c07f77c */
if(!s->budget--) { s->failed_pc=0x0c07f77cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[12];
goto P_0c07f77e;
P_0c07f77e: /* original 4500, guest PC 0x0c07f77e */
if(!s->budget--) { s->failed_pc=0x0c07f77eu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07f780;
P_0c07f780: /* original 4315, guest PC 0x0c07f780 */
if(!s->budget--) { s->failed_pc=0x0c07f780u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c07f782;
P_0c07f782: /* original 25ab, guest PC 0x0c07f782 */
if(!s->budget--) { s->failed_pc=0x0c07f782u; return 0; }
r[5]|=r[10];
goto P_0c07f784;
P_0c07f784: /* original ed00, guest PC 0x0c07f784 */
if(!s->budget--) { s->failed_pc=0x0c07f784u; return 0; }
r[13]=0x00000000u;
goto P_0c07f786;
P_0c07f786: /* original 8f1f, guest PC 0x0c07f786 */
if(!s->budget--) { s->failed_pc=0x0c07f786u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c07f7c8; }
goto P_0c07f78a;
P_0c07f788: /* original 2f32, guest PC 0x0c07f788 */
if(!s->budget--) { s->failed_pc=0x0c07f788u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07f78a;
P_0c07f78a: /* original 935a, guest PC 0x0c07f78a */
if(!s->budget--) { s->failed_pc=0x0c07f78au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f842u,2);
goto P_0c07f78c;
P_0c07f78c: /* original 33ec, guest PC 0x0c07f78c */
if(!s->budget--) { s->failed_pc=0x0c07f78cu; return 0; }
r[3]+=r[14];
goto P_0c07f78e;
P_0c07f78e: /* original 33dc, guest PC 0x0c07f78e */
if(!s->budget--) { s->failed_pc=0x0c07f78eu; return 0; }
r[3]+=r[13];
goto P_0c07f790;
P_0c07f790: /* original 6230, guest PC 0x0c07f790 */
if(!s->budget--) { s->failed_pc=0x0c07f790u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c07f792;
P_0c07f792: /* original 9357, guest PC 0x0c07f792 */
if(!s->budget--) { s->failed_pc=0x0c07f792u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f844u,2);
goto P_0c07f794;
P_0c07f794: /* original 622c, guest PC 0x0c07f794 */
if(!s->budget--) { s->failed_pc=0x0c07f794u; return 0; }
r[2]=r[2]&255u;
goto P_0c07f796;
P_0c07f796: /* original 3230, guest PC 0x0c07f796 */
if(!s->budget--) { s->failed_pc=0x0c07f796u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c07f798;
P_0c07f798: /* original 8916, guest PC 0x0c07f798 */
if(!s->budget--) { s->failed_pc=0x0c07f798u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07f7c8; }
goto P_0c07f79a;
P_0c07f79a: /* original 9652, guest PC 0x0c07f79a */
if(!s->budget--) { s->failed_pc=0x0c07f79au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f842u,2);
goto P_0c07f79c;
P_0c07f79c: /* original 63d3, guest PC 0x0c07f79c */
if(!s->budget--) { s->failed_pc=0x0c07f79cu; return 0; }
r[3]=r[13];
goto P_0c07f79e;
P_0c07f79e: /* original 62d3, guest PC 0x0c07f79e */
if(!s->budget--) { s->failed_pc=0x0c07f79eu; return 0; }
r[2]=r[13];
goto P_0c07f7a0;
P_0c07f7a0: /* original 4308, guest PC 0x0c07f7a0 */
if(!s->budget--) { s->failed_pc=0x0c07f7a0u; return 0; }
r[3]<<=2;
goto P_0c07f7a2;
P_0c07f7a2: /* original 4200, guest PC 0x0c07f7a2 */
if(!s->budget--) { s->failed_pc=0x0c07f7a2u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07f7a4;
P_0c07f7a4: /* original 6493, guest PC 0x0c07f7a4 */
if(!s->budget--) { s->failed_pc=0x0c07f7a4u; return 0; }
r[4]=r[9];
goto P_0c07f7a6;
P_0c07f7a6: /* original 36ec, guest PC 0x0c07f7a6 */
if(!s->budget--) { s->failed_pc=0x0c07f7a6u; return 0; }
r[6]+=r[14];
goto P_0c07f7a8;
P_0c07f7a8: /* original 974e, guest PC 0x0c07f7a8 */
if(!s->budget--) { s->failed_pc=0x0c07f7a8u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f848u,2);
goto P_0c07f7aa;
P_0c07f7aa: /* original 323c, guest PC 0x0c07f7aa */
if(!s->budget--) { s->failed_pc=0x0c07f7aau; return 0; }
r[2]+=r[3];
goto P_0c07f7ac;
P_0c07f7ac: /* original 36dc, guest PC 0x0c07f7ac */
if(!s->budget--) { s->failed_pc=0x0c07f7acu; return 0; }
r[6]+=r[13];
goto P_0c07f7ae;
P_0c07f7ae: /* original 3428, guest PC 0x0c07f7ae */
if(!s->budget--) { s->failed_pc=0x0c07f7aeu; return 0; }
r[4]-=r[2];
goto P_0c07f7b0;
P_0c07f7b0: /* original 6660, guest PC 0x0c07f7b0 */
if(!s->budget--) { s->failed_pc=0x0c07f7b0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]=tmp;
goto P_0c07f7b2;
P_0c07f7b2: /* original 4400, guest PC 0x0c07f7b2 */
if(!s->budget--) { s->failed_pc=0x0c07f7b2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07f7b4;
P_0c07f7b4: /* original 6543, guest PC 0x0c07f7b4 */
if(!s->budget--) { s->failed_pc=0x0c07f7b4u; return 0; }
r[5]=r[4];
goto P_0c07f7b6;
P_0c07f7b6: /* original 666c, guest PC 0x0c07f7b6 */
if(!s->budget--) { s->failed_pc=0x0c07f7b6u; return 0; }
r[6]=r[6]&255u;
goto P_0c07f7b8;
P_0c07f7b8: /* original 25ab, guest PC 0x0c07f7b8 */
if(!s->budget--) { s->failed_pc=0x0c07f7b8u; return 0; }
r[5]|=r[10];
goto P_0c07f7ba;
P_0c07f7ba: /* original 480b, guest PC 0x0c07f7ba */
if(!s->budget--) { s->failed_pc=0x0c07f7bau; return 0; }
target=r[8];
r[16]=code_base|0x0c07f7beu;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f7beu) { target=s->pc; goto dispatch; }
goto P_0c07f7be;
P_0c07f7bc: /* original 54f1, guest PC 0x0c07f7bc */
if(!s->budget--) { s->failed_pc=0x0c07f7bcu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07f7be;
P_0c07f7be: /* original 63f2, guest PC 0x0c07f7be */
if(!s->budget--) { s->failed_pc=0x0c07f7beu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07f7c0;
P_0c07f7c0: /* original 7d01, guest PC 0x0c07f7c0 */
if(!s->budget--) { s->failed_pc=0x0c07f7c0u; return 0; }
r[13]+=0x00000001u;
goto P_0c07f7c2;
P_0c07f7c2: /* original 6503, guest PC 0x0c07f7c2 */
if(!s->budget--) { s->failed_pc=0x0c07f7c2u; return 0; }
r[5]=r[0];
goto P_0c07f7c4;
P_0c07f7c4: /* original 3d33, guest PC 0x0c07f7c4 */
if(!s->budget--) { s->failed_pc=0x0c07f7c4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[3])!=0);
goto P_0c07f7c6;
P_0c07f7c6: /* original 8be0, guest PC 0x0c07f7c6 */
if(!s->budget--) { s->failed_pc=0x0c07f7c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07f78a; }
goto P_0c07f7c8;
P_0c07f7c8: /* original d123, guest PC 0x0c07f7c8 */
if(!s->budget--) { s->failed_pc=0x0c07f7c8u; return 0; }
r[1]=read(ram,0x0c07f858u,4);
goto P_0c07f7ca;
P_0c07f7ca: /* original e301, guest PC 0x0c07f7ca */
if(!s->budget--) { s->failed_pc=0x0c07f7cau; return 0; }
r[3]=0x00000001u;
goto P_0c07f7cc;
P_0c07f7cc: /* original 6412, guest PC 0x0c07f7cc */
if(!s->budget--) { s->failed_pc=0x0c07f7ccu; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c07f7ce;
P_0c07f7ce: /* original 2438, guest PC 0x0c07f7ce */
if(!s->budget--) { s->failed_pc=0x0c07f7ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c07f7d0;
P_0c07f7d0: /* original 890b, guest PC 0x0c07f7d0 */
if(!s->budget--) { s->failed_pc=0x0c07f7d0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07f7ea; }
goto P_0c07f7d2;
P_0c07f7d2: /* original 54f2, guest PC 0x0c07f7d2 */
if(!s->budget--) { s->failed_pc=0x0c07f7d2u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07f7d4;
P_0c07f7d4: /* original 7f18, guest PC 0x0c07f7d4 */
if(!s->budget--) { s->failed_pc=0x0c07f7d4u; return 0; }
r[15]+=0x00000018u;
goto P_0c07f7d6;
P_0c07f7d6: /* original 4f26, guest PC 0x0c07f7d6 */
if(!s->budget--) { s->failed_pc=0x0c07f7d6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07f7d8;
P_0c07f7d8: /* original d220, guest PC 0x0c07f7d8 */
if(!s->budget--) { s->failed_pc=0x0c07f7d8u; return 0; }
r[2]=read(ram,0x0c07f85cu,4);
goto P_0c07f7da;
P_0c07f7da: /* original 68f6, guest PC 0x0c07f7da */
if(!s->budget--) { s->failed_pc=0x0c07f7dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c07f7dc;
P_0c07f7dc: /* original 69f6, guest PC 0x0c07f7dc */
if(!s->budget--) { s->failed_pc=0x0c07f7dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07f7de;
P_0c07f7de: /* original 6af6, guest PC 0x0c07f7de */
if(!s->budget--) { s->failed_pc=0x0c07f7deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07f7e0;
P_0c07f7e0: /* original 6bf6, guest PC 0x0c07f7e0 */
if(!s->budget--) { s->failed_pc=0x0c07f7e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07f7e2;
P_0c07f7e2: /* original 6cf6, guest PC 0x0c07f7e2 */
if(!s->budget--) { s->failed_pc=0x0c07f7e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07f7e4;
P_0c07f7e4: /* original 6df6, guest PC 0x0c07f7e4 */
if(!s->budget--) { s->failed_pc=0x0c07f7e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07f7e6;
P_0c07f7e6: /* original 422b, guest PC 0x0c07f7e6 */
if(!s->budget--) { s->failed_pc=0x0c07f7e6u; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c03b450u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c07f7e8: /* original 6ef6, guest PC 0x0c07f7e8 */
if(!s->budget--) { s->failed_pc=0x0c07f7e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07f7ea;
P_0c07f7ea: /* original d31d, guest PC 0x0c07f7ea */
if(!s->budget--) { s->failed_pc=0x0c07f7eau; return 0; }
r[3]=read(ram,0x0c07f860u,4);
goto P_0c07f7ec;
P_0c07f7ec: /* original 64be, guest PC 0x0c07f7ec */
if(!s->budget--) { s->failed_pc=0x0c07f7ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[11];
goto P_0c07f7ee;
P_0c07f7ee: /* original 4408, guest PC 0x0c07f7ee */
if(!s->budget--) { s->failed_pc=0x0c07f7eeu; return 0; }
r[4]<<=2;
goto P_0c07f7f0;
P_0c07f7f0: /* original 61f3, guest PC 0x0c07f7f0 */
if(!s->budget--) { s->failed_pc=0x0c07f7f0u; return 0; }
r[1]=r[15];
goto P_0c07f7f2;
P_0c07f7f2: /* original 343c, guest PC 0x0c07f7f2 */
if(!s->budget--) { s->failed_pc=0x0c07f7f2u; return 0; }
r[4]+=r[3];
goto P_0c07f7f4;
P_0c07f7f4: /* original 7114, guest PC 0x0c07f7f4 */
if(!s->budget--) { s->failed_pc=0x0c07f7f4u; return 0; }
r[1]+=0x00000014u;
goto P_0c07f7f6;
P_0c07f7f6: /* original 6241, guest PC 0x0c07f7f6 */
if(!s->budget--) { s->failed_pc=0x0c07f7f6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[2]=tmp;
goto P_0c07f7f8;
P_0c07f7f8: /* original 2f21, guest PC 0x0c07f7f8 */
if(!s->budget--) { s->failed_pc=0x0c07f7f8u; return 0; }
write(ram,r[15],r[2],2);
goto P_0c07f7fa;
P_0c07f7fa: /* original 8442, guest PC 0x0c07f7fa */
if(!s->budget--) { s->failed_pc=0x0c07f7fau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c07f7fc;
P_0c07f7fc: /* original 6493, guest PC 0x0c07f7fc */
if(!s->budget--) { s->failed_pc=0x0c07f7fcu; return 0; }
r[4]=r[9];
goto P_0c07f7fe;
P_0c07f7fe: /* original 2100, guest PC 0x0c07f7fe */
if(!s->budget--) { s->failed_pc=0x0c07f7feu; return 0; }
write(ram,r[1],r[0],1);
goto P_0c07f800;
P_0c07f800: /* original 84fc, guest PC 0x0c07f800 */
if(!s->budget--) { s->failed_pc=0x0c07f800u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+12,1);
goto P_0c07f802;
P_0c07f802: /* original 67f1, guest PC 0x0c07f802 */
if(!s->budget--) { s->failed_pc=0x0c07f802u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[7]=tmp;
goto P_0c07f804;
P_0c07f804: /* original 3408, guest PC 0x0c07f804 */
if(!s->budget--) { s->failed_pc=0x0c07f804u; return 0; }
r[4]-=r[0];
goto P_0c07f806;
P_0c07f806: /* original e014, guest PC 0x0c07f806 */
if(!s->budget--) { s->failed_pc=0x0c07f806u; return 0; }
r[0]=0x00000014u;
goto P_0c07f808;
P_0c07f808: /* original 654e, guest PC 0x0c07f808 */
if(!s->budget--) { s->failed_pc=0x0c07f808u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c07f80a;
P_0c07f80a: /* original 06fc, guest PC 0x0c07f80a */
if(!s->budget--) { s->failed_pc=0x0c07f80au; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c07f80c;
P_0c07f80c: /* original 4500, guest PC 0x0c07f80c */
if(!s->budget--) { s->failed_pc=0x0c07f80cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07f80e;
P_0c07f80e: /* original 25ab, guest PC 0x0c07f80e */
if(!s->budget--) { s->failed_pc=0x0c07f80eu; return 0; }
r[5]|=r[10];
goto P_0c07f810;
P_0c07f810: /* original 480b, guest PC 0x0c07f810 */
if(!s->budget--) { s->failed_pc=0x0c07f810u; return 0; }
target=r[8];
r[16]=code_base|0x0c07f814u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f814u) { target=s->pc; goto dispatch; }
goto P_0c07f814;
P_0c07f812: /* original 54f1, guest PC 0x0c07f812 */
if(!s->budget--) { s->failed_pc=0x0c07f812u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07f814;
P_0c07f814: /* original 54f4, guest PC 0x0c07f814 */
if(!s->budget--) { s->failed_pc=0x0c07f814u; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c07f816;
P_0c07f816: /* original 7b01, guest PC 0x0c07f816 */
if(!s->budget--) { s->failed_pc=0x0c07f816u; return 0; }
r[11]+=0x00000001u;
goto P_0c07f818;
P_0c07f818: /* original 63be, guest PC 0x0c07f818 */
if(!s->budget--) { s->failed_pc=0x0c07f818u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[11];
goto P_0c07f81a;
P_0c07f81a: /* original 6503, guest PC 0x0c07f81a */
if(!s->budget--) { s->failed_pc=0x0c07f81au; return 0; }
r[5]=r[0];
goto P_0c07f81c;
P_0c07f81c: /* original 4400, guest PC 0x0c07f81c */
if(!s->budget--) { s->failed_pc=0x0c07f81cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07f81e;
P_0c07f81e: /* original 644c, guest PC 0x0c07f81e */
if(!s->budget--) { s->failed_pc=0x0c07f81eu; return 0; }
r[4]=r[4]&255u;
goto P_0c07f820;
P_0c07f820: /* original 3347, guest PC 0x0c07f820 */
if(!s->budget--) { s->failed_pc=0x0c07f820u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[4])!=0);
goto P_0c07f822;
P_0c07f822: /* original 8b21, guest PC 0x0c07f822 */
if(!s->budget--) { s->failed_pc=0x0c07f822u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07f868; }
goto P_0c07f824;
P_0c07f824: /* original 7c01, guest PC 0x0c07f824 */
if(!s->budget--) { s->failed_pc=0x0c07f824u; return 0; }
r[12]+=0x00000001u;
goto P_0c07f826;
P_0c07f826: /* original e205, guest PC 0x0c07f826 */
if(!s->budget--) { s->failed_pc=0x0c07f826u; return 0; }
r[2]=0x00000005u;
goto P_0c07f828;
P_0c07f828: /* original 63ce, guest PC 0x0c07f828 */
if(!s->budget--) { s->failed_pc=0x0c07f828u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[12];
goto P_0c07f82a;
P_0c07f82a: /* original 3327, guest PC 0x0c07f82a */
if(!s->budget--) { s->failed_pc=0x0c07f82au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c07f82c;
P_0c07f82c: /* original 8f1a, guest PC 0x0c07f82c */
if(!s->budget--) { s->failed_pc=0x0c07f82cu; return 0; }
cond=r[17]&1u;
r[11]=0x00000000u;
if(!cond) { goto P_0c07f864; }
goto P_0c07f830;
P_0c07f82e: /* original eb00, guest PC 0x0c07f82e */
if(!s->budget--) { s->failed_pc=0x0c07f82eu; return 0; }
r[11]=0x00000000u;
goto P_0c07f830;
P_0c07f830: /* original b029, guest PC 0x0c07f830 */
if(!s->budget--) { s->failed_pc=0x0c07f830u; return 0; }
target=code_base|0x0c07f886u; r[16]=code_base|0x0c07f834u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f834u) { target=s->pc; goto dispatch; }
goto P_0c07f834;
P_0c07f832: /* original 54f2, guest PC 0x0c07f832 */
if(!s->budget--) { s->failed_pc=0x0c07f832u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07f834;
P_0c07f834: /* original a01d, guest PC 0x0c07f834 */
if(!s->budget--) { s->failed_pc=0x0c07f834u; return 0; }
goto P_0c07f872;
P_0c07f836: /* original 0009, guest PC 0x0c07f836 */
if(!s->budget--) { s->failed_pc=0x0c07f836u; return 0; }
if(!vf3_matrix_family(0x0c07f838u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07f838u; return 0; } return 1;
P_0c07f864: /* original 9088, guest PC 0x0c07f864 */
if(!s->budget--) { s->failed_pc=0x0c07f864u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f978u,2);
goto P_0c07f866;
P_0c07f866: /* original 0ec4, guest PC 0x0c07f866 */
if(!s->budget--) { s->failed_pc=0x0c07f866u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c07f868;
P_0c07f868: /* original 9087, guest PC 0x0c07f868 */
if(!s->budget--) { s->failed_pc=0x0c07f868u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f97au,2);
goto P_0c07f86a;
P_0c07f86a: /* original 0eb4, guest PC 0x0c07f86a */
if(!s->budget--) { s->failed_pc=0x0c07f86au; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c07f86c;
P_0c07f86c: /* original d349, guest PC 0x0c07f86c */
if(!s->budget--) { s->failed_pc=0x0c07f86cu; return 0; }
r[3]=read(ram,0x0c07f994u,4);
goto P_0c07f86e;
P_0c07f86e: /* original 430b, guest PC 0x0c07f86e */
if(!s->budget--) { s->failed_pc=0x0c07f86eu; return 0; }
target=r[3];
r[16]=code_base|0x0c07f872u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f872u) { target=s->pc; goto dispatch; }
goto P_0c07f872;
P_0c07f870: /* original 54f2, guest PC 0x0c07f870 */
if(!s->budget--) { s->failed_pc=0x0c07f870u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07f872;
P_0c07f872: /* original 7f18, guest PC 0x0c07f872 */
if(!s->budget--) { s->failed_pc=0x0c07f872u; return 0; }
r[15]+=0x00000018u;
goto P_0c07f874;
P_0c07f874: /* original 4f26, guest PC 0x0c07f874 */
if(!s->budget--) { s->failed_pc=0x0c07f874u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07f876;
P_0c07f876: /* original 68f6, guest PC 0x0c07f876 */
if(!s->budget--) { s->failed_pc=0x0c07f876u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c07f878;
P_0c07f878: /* original 69f6, guest PC 0x0c07f878 */
if(!s->budget--) { s->failed_pc=0x0c07f878u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07f87a;
P_0c07f87a: /* original 6af6, guest PC 0x0c07f87a */
if(!s->budget--) { s->failed_pc=0x0c07f87au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07f87c;
P_0c07f87c: /* original 6bf6, guest PC 0x0c07f87c */
if(!s->budget--) { s->failed_pc=0x0c07f87cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07f87e;
P_0c07f87e: /* original 6cf6, guest PC 0x0c07f87e */
if(!s->budget--) { s->failed_pc=0x0c07f87eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07f880;
P_0c07f880: /* original 6df6, guest PC 0x0c07f880 */
if(!s->budget--) { s->failed_pc=0x0c07f880u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07f882;
P_0c07f882: /* original 000b, guest PC 0x0c07f882 */
if(!s->budget--) { s->failed_pc=0x0c07f882u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07f884: /* original 6ef6, guest PC 0x0c07f884 */
if(!s->budget--) { s->failed_pc=0x0c07f884u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07f886;
P_0c07f886: /* original 2fe6, guest PC 0x0c07f886 */
if(!s->budget--) { s->failed_pc=0x0c07f886u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f888;
P_0c07f888: /* original 2fd6, guest PC 0x0c07f888 */
if(!s->budget--) { s->failed_pc=0x0c07f888u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f88a;
P_0c07f88a: /* original 2fc6, guest PC 0x0c07f88a */
if(!s->budget--) { s->failed_pc=0x0c07f88au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f88c;
P_0c07f88c: /* original 2fb6, guest PC 0x0c07f88c */
if(!s->budget--) { s->failed_pc=0x0c07f88cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f88e;
P_0c07f88e: /* original 2fa6, guest PC 0x0c07f88e */
if(!s->budget--) { s->failed_pc=0x0c07f88eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f890;
P_0c07f890: /* original 2f96, guest PC 0x0c07f890 */
if(!s->budget--) { s->failed_pc=0x0c07f890u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f892;
P_0c07f892: /* original 2f86, guest PC 0x0c07f892 */
if(!s->budget--) { s->failed_pc=0x0c07f892u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f894;
P_0c07f894: /* original 4f22, guest PC 0x0c07f894 */
if(!s->budget--) { s->failed_pc=0x0c07f894u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07f896;
P_0c07f896: /* original 4f12, guest PC 0x0c07f896 */
if(!s->budget--) { s->failed_pc=0x0c07f896u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c07f898;
P_0c07f898: /* original 7fe8, guest PC 0x0c07f898 */
if(!s->budget--) { s->failed_pc=0x0c07f898u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c07f89a;
P_0c07f89a: /* original 1f44, guest PC 0x0c07f89a */
if(!s->budget--) { s->failed_pc=0x0c07f89au; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c07f89c;
P_0c07f89c: /* original 61f3, guest PC 0x0c07f89c */
if(!s->budget--) { s->failed_pc=0x0c07f89cu; return 0; }
r[1]=r[15];
goto P_0c07f89e;
P_0c07f89e: /* original 936d, guest PC 0x0c07f89e */
if(!s->budget--) { s->failed_pc=0x0c07f89eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f97cu,2);
goto P_0c07f8a0;
P_0c07f8a0: /* original 7114, guest PC 0x0c07f8a0 */
if(!s->budget--) { s->failed_pc=0x0c07f8a0u; return 0; }
r[1]+=0x00000014u;
goto P_0c07f8a2;
P_0c07f8a2: /* original d43d, guest PC 0x0c07f8a2 */
if(!s->budget--) { s->failed_pc=0x0c07f8a2u; return 0; }
r[4]=read(ram,0x0c07f998u,4);
goto P_0c07f8a4;
P_0c07f8a4: /* original 334c, guest PC 0x0c07f8a4 */
if(!s->budget--) { s->failed_pc=0x0c07f8a4u; return 0; }
r[3]+=r[4];
goto P_0c07f8a6;
P_0c07f8a6: /* original 1f31, guest PC 0x0c07f8a6 */
if(!s->budget--) { s->failed_pc=0x0c07f8a6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07f8a8;
P_0c07f8a8: /* original 1f43, guest PC 0x0c07f8a8 */
if(!s->budget--) { s->failed_pc=0x0c07f8a8u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c07f8aa;
P_0c07f8aa: /* original d23c, guest PC 0x0c07f8aa */
if(!s->budget--) { s->failed_pc=0x0c07f8aau; return 0; }
r[2]=read(ram,0x0c07f99cu,4);
goto P_0c07f8ac;
P_0c07f8ac: /* original d33c, guest PC 0x0c07f8ac */
if(!s->budget--) { s->failed_pc=0x0c07f8acu; return 0; }
r[3]=read(ram,0x0c07f9a0u,4);
goto P_0c07f8ae;
P_0c07f8ae: /* original 430b, guest PC 0x0c07f8ae */
if(!s->budget--) { s->failed_pc=0x0c07f8aeu; return 0; }
target=r[3];
r[16]=code_base|0x0c07f8b2u;
r[0]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f8b2u) { target=s->pc; goto dispatch; }
goto P_0c07f8b2;
P_0c07f8b0: /* original e004, guest PC 0x0c07f8b0 */
if(!s->budget--) { s->failed_pc=0x0c07f8b0u; return 0; }
r[0]=0x00000004u;
goto P_0c07f8b2;
P_0c07f8b2: /* original 9864, guest PC 0x0c07f8b2 */
if(!s->budget--) { s->failed_pc=0x0c07f8b2u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f97eu,2);
goto P_0c07f8b4;
P_0c07f8b4: /* original ec00, guest PC 0x0c07f8b4 */
if(!s->budget--) { s->failed_pc=0x0c07f8b4u; return 0; }
r[12]=0x00000000u;
goto P_0c07f8b6;
P_0c07f8b6: /* original da3c, guest PC 0x0c07f8b6 */
if(!s->budget--) { s->failed_pc=0x0c07f8b6u; return 0; }
r[10]=read(ram,0x0c07f9a8u,4);
goto P_0c07f8b8;
P_0c07f8b8: /* original 6bc3, guest PC 0x0c07f8b8 */
if(!s->budget--) { s->failed_pc=0x0c07f8b8u; return 0; }
r[11]=r[12];
goto P_0c07f8ba;
P_0c07f8ba: /* original dd3c, guest PC 0x0c07f8ba */
if(!s->budget--) { s->failed_pc=0x0c07f8bau; return 0; }
r[13]=read(ram,0x0c07f9acu,4);
goto P_0c07f8bc;
P_0c07f8bc: /* original e92b, guest PC 0x0c07f8bc */
if(!s->budget--) { s->failed_pc=0x0c07f8bcu; return 0; }
r[9]=0x0000002bu;
goto P_0c07f8be;
P_0c07f8be: /* original de39, guest PC 0x0c07f8be */
if(!s->budget--) { s->failed_pc=0x0c07f8beu; return 0; }
r[14]=read(ram,0x0c07f9a4u,4);
goto P_0c07f8c0;
P_0c07f8c0: /* original 925e, guest PC 0x0c07f8c0 */
if(!s->budget--) { s->failed_pc=0x0c07f8c0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f980u,2);
goto P_0c07f8c2;
P_0c07f8c2: /* original 32dc, guest PC 0x0c07f8c2 */
if(!s->budget--) { s->failed_pc=0x0c07f8c2u; return 0; }
r[2]+=r[13];
goto P_0c07f8c4;
P_0c07f8c4: /* original 32bc, guest PC 0x0c07f8c4 */
if(!s->budget--) { s->failed_pc=0x0c07f8c4u; return 0; }
r[2]+=r[11];
goto P_0c07f8c6;
P_0c07f8c6: /* original 6320, guest PC 0x0c07f8c6 */
if(!s->budget--) { s->failed_pc=0x0c07f8c6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c07f8c8;
P_0c07f8c8: /* original 633c, guest PC 0x0c07f8c8 */
if(!s->budget--) { s->failed_pc=0x0c07f8c8u; return 0; }
r[3]=r[3]&255u;
goto P_0c07f8ca;
P_0c07f8ca: /* original 3380, guest PC 0x0c07f8ca */
if(!s->budget--) { s->failed_pc=0x0c07f8cau; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[8])!=0);
goto P_0c07f8cc;
P_0c07f8cc: /* original 8917, guest PC 0x0c07f8cc */
if(!s->budget--) { s->failed_pc=0x0c07f8ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07f8fe; }
goto P_0c07f8ce;
P_0c07f8ce: /* original 63b3, guest PC 0x0c07f8ce */
if(!s->budget--) { s->failed_pc=0x0c07f8ceu; return 0; }
r[3]=r[11];
goto P_0c07f8d0;
P_0c07f8d0: /* original 62b3, guest PC 0x0c07f8d0 */
if(!s->budget--) { s->failed_pc=0x0c07f8d0u; return 0; }
r[2]=r[11];
goto P_0c07f8d2;
P_0c07f8d2: /* original 4308, guest PC 0x0c07f8d2 */
if(!s->budget--) { s->failed_pc=0x0c07f8d2u; return 0; }
r[3]<<=2;
goto P_0c07f8d4;
P_0c07f8d4: /* original 6493, guest PC 0x0c07f8d4 */
if(!s->budget--) { s->failed_pc=0x0c07f8d4u; return 0; }
r[4]=r[9];
goto P_0c07f8d6;
P_0c07f8d6: /* original 4200, guest PC 0x0c07f8d6 */
if(!s->budget--) { s->failed_pc=0x0c07f8d6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07f8d8;
P_0c07f8d8: /* original 323c, guest PC 0x0c07f8d8 */
if(!s->budget--) { s->failed_pc=0x0c07f8d8u; return 0; }
r[2]+=r[3];
goto P_0c07f8da;
P_0c07f8da: /* original 3428, guest PC 0x0c07f8da */
if(!s->budget--) { s->failed_pc=0x0c07f8dau; return 0; }
r[4]-=r[2];
goto P_0c07f8dc;
P_0c07f8dc: /* original 9251, guest PC 0x0c07f8dc */
if(!s->budget--) { s->failed_pc=0x0c07f8dcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f982u,2);
goto P_0c07f8de;
P_0c07f8de: /* original 4400, guest PC 0x0c07f8de */
if(!s->budget--) { s->failed_pc=0x0c07f8deu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07f8e0;
P_0c07f8e0: /* original 242b, guest PC 0x0c07f8e0 */
if(!s->budget--) { s->failed_pc=0x0c07f8e0u; return 0; }
r[4]|=r[2];
goto P_0c07f8e2;
P_0c07f8e2: /* original 6543, guest PC 0x0c07f8e2 */
if(!s->budget--) { s->failed_pc=0x0c07f8e2u; return 0; }
r[5]=r[4];
goto P_0c07f8e4;
P_0c07f8e4: /* original 2f42, guest PC 0x0c07f8e4 */
if(!s->budget--) { s->failed_pc=0x0c07f8e4u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07f8e6;
P_0c07f8e6: /* original 964b, guest PC 0x0c07f8e6 */
if(!s->budget--) { s->failed_pc=0x0c07f8e6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f980u,2);
goto P_0c07f8e8;
P_0c07f8e8: /* original 974c, guest PC 0x0c07f8e8 */
if(!s->budget--) { s->failed_pc=0x0c07f8e8u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f984u,2);
goto P_0c07f8ea;
P_0c07f8ea: /* original 36dc, guest PC 0x0c07f8ea */
if(!s->budget--) { s->failed_pc=0x0c07f8eau; return 0; }
r[6]+=r[13];
goto P_0c07f8ec;
P_0c07f8ec: /* original 36bc, guest PC 0x0c07f8ec */
if(!s->budget--) { s->failed_pc=0x0c07f8ecu; return 0; }
r[6]+=r[11];
goto P_0c07f8ee;
P_0c07f8ee: /* original 6660, guest PC 0x0c07f8ee */
if(!s->budget--) { s->failed_pc=0x0c07f8eeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]=tmp;
goto P_0c07f8f0;
P_0c07f8f0: /* original 666c, guest PC 0x0c07f8f0 */
if(!s->budget--) { s->failed_pc=0x0c07f8f0u; return 0; }
r[6]=r[6]&255u;
goto P_0c07f8f2;
P_0c07f8f2: /* original 4a0b, guest PC 0x0c07f8f2 */
if(!s->budget--) { s->failed_pc=0x0c07f8f2u; return 0; }
target=r[10];
r[16]=code_base|0x0c07f8f6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f8f6u) { target=s->pc; goto dispatch; }
goto P_0c07f8f6;
P_0c07f8f4: /* original 64e3, guest PC 0x0c07f8f4 */
if(!s->budget--) { s->failed_pc=0x0c07f8f4u; return 0; }
r[4]=r[14];
goto P_0c07f8f6;
P_0c07f8f6: /* original e306, guest PC 0x0c07f8f6 */
if(!s->budget--) { s->failed_pc=0x0c07f8f6u; return 0; }
r[3]=0x00000006u;
goto P_0c07f8f8;
P_0c07f8f8: /* original 7b01, guest PC 0x0c07f8f8 */
if(!s->budget--) { s->failed_pc=0x0c07f8f8u; return 0; }
r[11]+=0x00000001u;
goto P_0c07f8fa;
P_0c07f8fa: /* original 3b33, guest PC 0x0c07f8fa */
if(!s->budget--) { s->failed_pc=0x0c07f8fau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[3])!=0);
goto P_0c07f8fc;
P_0c07f8fc: /* original 8be0, guest PC 0x0c07f8fc */
if(!s->budget--) { s->failed_pc=0x0c07f8fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07f8c0; }
goto P_0c07f8fe;
P_0c07f8fe: /* original 54f1, guest PC 0x0c07f8fe */
if(!s->budget--) { s->failed_pc=0x0c07f8feu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07f900;
P_0c07f900: /* original d82b, guest PC 0x0c07f900 */
if(!s->budget--) { s->failed_pc=0x0c07f900u; return 0; }
r[8]=read(ram,0x0c07f9b0u,4);
goto P_0c07f902;
P_0c07f902: /* original 480b, guest PC 0x0c07f902 */
if(!s->budget--) { s->failed_pc=0x0c07f902u; return 0; }
target=r[8];
r[16]=code_base|0x0c07f906u;
r[4]+=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f906u) { target=s->pc; goto dispatch; }
goto P_0c07f906;
P_0c07f904: /* original 7412, guest PC 0x0c07f904 */
if(!s->budget--) { s->failed_pc=0x0c07f904u; return 0; }
r[4]+=0x00000012u;
goto P_0c07f906;
P_0c07f906: /* original 640c, guest PC 0x0c07f906 */
if(!s->budget--) { s->failed_pc=0x0c07f906u; return 0; }
r[4]=r[0]&255u;
goto P_0c07f908;
P_0c07f908: /* original 6043, guest PC 0x0c07f908 */
if(!s->budget--) { s->failed_pc=0x0c07f908u; return 0; }
r[0]=r[4];
goto P_0c07f90a;
P_0c07f90a: /* original 8803, guest PC 0x0c07f90a */
if(!s->budget--) { s->failed_pc=0x0c07f90au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c07f90c;
P_0c07f90c: /* original 890a, guest PC 0x0c07f90c */
if(!s->budget--) { s->failed_pc=0x0c07f90cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07f924; }
goto P_0c07f90e;
P_0c07f90e: /* original 903a, guest PC 0x0c07f90e */
if(!s->budget--) { s->failed_pc=0x0c07f90eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f986u,2);
goto P_0c07f910;
P_0c07f910: /* original 02dc, guest PC 0x0c07f910 */
if(!s->budget--) { s->failed_pc=0x0c07f910u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07f912;
P_0c07f912: /* original 2228, guest PC 0x0c07f912 */
if(!s->budget--) { s->failed_pc=0x0c07f912u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07f914;
P_0c07f914: /* original 8906, guest PC 0x0c07f914 */
if(!s->budget--) { s->failed_pc=0x0c07f914u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07f924; }
goto P_0c07f916;
P_0c07f916: /* original 9037, guest PC 0x0c07f916 */
if(!s->budget--) { s->failed_pc=0x0c07f916u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f988u,2);
goto P_0c07f918;
P_0c07f918: /* original d327, guest PC 0x0c07f918 */
if(!s->budget--) { s->failed_pc=0x0c07f918u; return 0; }
r[3]=read(ram,0x0c07f9b8u,4);
goto P_0c07f91a;
P_0c07f91a: /* original 04dc, guest PC 0x0c07f91a */
if(!s->budget--) { s->failed_pc=0x0c07f91au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07f91c;
P_0c07f91c: /* original d025, guest PC 0x0c07f91c */
if(!s->budget--) { s->failed_pc=0x0c07f91cu; return 0; }
r[0]=read(ram,0x0c07f9b4u,4);
goto P_0c07f91e;
P_0c07f91e: /* original 4408, guest PC 0x0c07f91e */
if(!s->budget--) { s->failed_pc=0x0c07f91eu; return 0; }
r[4]<<=2;
goto P_0c07f920;
P_0c07f920: /* original 430b, guest PC 0x0c07f920 */
if(!s->budget--) { s->failed_pc=0x0c07f920u; return 0; }
target=r[3];
r[16]=code_base|0x0c07f924u;
r[4]=read(ram,r[4]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f924u) { target=s->pc; goto dispatch; }
goto P_0c07f924;
P_0c07f922: /* original 044e, guest PC 0x0c07f922 */
if(!s->budget--) { s->failed_pc=0x0c07f922u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c07f924;
P_0c07f924: /* original 54f1, guest PC 0x0c07f924 */
if(!s->budget--) { s->failed_pc=0x0c07f924u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07f926;
P_0c07f926: /* original 480b, guest PC 0x0c07f926 */
if(!s->budget--) { s->failed_pc=0x0c07f926u; return 0; }
target=r[8];
r[16]=code_base|0x0c07f92au;
r[4]+=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f92au) { target=s->pc; goto dispatch; }
goto P_0c07f92a;
P_0c07f928: /* original 7412, guest PC 0x0c07f928 */
if(!s->budget--) { s->failed_pc=0x0c07f928u; return 0; }
r[4]+=0x00000012u;
goto P_0c07f92a;
P_0c07f92a: /* original 650c, guest PC 0x0c07f92a */
if(!s->budget--) { s->failed_pc=0x0c07f92au; return 0; }
r[5]=r[0]&255u;
goto P_0c07f92c;
P_0c07f92c: /* original 902c, guest PC 0x0c07f92c */
if(!s->budget--) { s->failed_pc=0x0c07f92cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f988u,2);
goto P_0c07f92e;
P_0c07f92e: /* original 2558, guest PC 0x0c07f92e */
if(!s->budget--) { s->failed_pc=0x0c07f92eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c07f930;
P_0c07f930: /* original 04dc, guest PC 0x0c07f930 */
if(!s->budget--) { s->failed_pc=0x0c07f930u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07f932;
P_0c07f932: /* original 6b4e, guest PC 0x0c07f932 */
if(!s->budget--) { s->failed_pc=0x0c07f932u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c07f934;
P_0c07f934: /* original 8f13, guest PC 0x0c07f934 */
if(!s->budget--) { s->failed_pc=0x0c07f934u; return 0; }
cond=r[17]&1u;
r[11]<<=2;
if(!cond) { goto P_0c07f95e; }
goto P_0c07f938;
P_0c07f936: /* original 4b08, guest PC 0x0c07f936 */
if(!s->budget--) { s->failed_pc=0x0c07f936u; return 0; }
r[11]<<=2;
goto P_0c07f938;
P_0c07f938: /* original d720, guest PC 0x0c07f938 */
if(!s->budget--) { s->failed_pc=0x0c07f938u; return 0; }
r[7]=read(ram,0x0c07f9bcu,4);
goto P_0c07f93a;
P_0c07f93a: /* original 37bc, guest PC 0x0c07f93a */
if(!s->budget--) { s->failed_pc=0x0c07f93au; return 0; }
r[7]+=r[11];
goto P_0c07f93c;
P_0c07f93c: /* original 2f72, guest PC 0x0c07f93c */
if(!s->budget--) { s->failed_pc=0x0c07f93cu; return 0; }
write(ram,r[15],r[7],4);
goto P_0c07f93e;
P_0c07f93e: /* original 66f2, guest PC 0x0c07f93e */
if(!s->budget--) { s->failed_pc=0x0c07f93eu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c07f940;
P_0c07f940: /* original 9523, guest PC 0x0c07f940 */
if(!s->budget--) { s->failed_pc=0x0c07f940u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f98au,2);
goto P_0c07f942;
P_0c07f942: /* original 8462, guest PC 0x0c07f942 */
if(!s->budget--) { s->failed_pc=0x0c07f942u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+2,1);
goto P_0c07f944;
P_0c07f944: /* original 6771, guest PC 0x0c07f944 */
if(!s->budget--) { s->failed_pc=0x0c07f944u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[7]=tmp;
goto P_0c07f946;
P_0c07f946: /* original 6603, guest PC 0x0c07f946 */
if(!s->budget--) { s->failed_pc=0x0c07f946u; return 0; }
r[6]=r[0];
goto P_0c07f948;
P_0c07f948: /* original 4a0b, guest PC 0x0c07f948 */
if(!s->budget--) { s->failed_pc=0x0c07f948u; return 0; }
target=r[10];
r[16]=code_base|0x0c07f94cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f94cu) { target=s->pc; goto dispatch; }
goto P_0c07f94c;
P_0c07f94a: /* original 64e3, guest PC 0x0c07f94a */
if(!s->budget--) { s->failed_pc=0x0c07f94au; return 0; }
r[4]=r[14];
goto P_0c07f94c;
P_0c07f94c: /* original 66f2, guest PC 0x0c07f94c */
if(!s->budget--) { s->failed_pc=0x0c07f94cu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c07f94e;
P_0c07f94e: /* original 951e, guest PC 0x0c07f94e */
if(!s->budget--) { s->failed_pc=0x0c07f94eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f98eu,2);
goto P_0c07f950;
P_0c07f950: /* original 8463, guest PC 0x0c07f950 */
if(!s->budget--) { s->failed_pc=0x0c07f950u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+3,1);
goto P_0c07f952;
P_0c07f952: /* original 971b, guest PC 0x0c07f952 */
if(!s->budget--) { s->failed_pc=0x0c07f952u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f98cu,2);
goto P_0c07f954;
P_0c07f954: /* original 6603, guest PC 0x0c07f954 */
if(!s->budget--) { s->failed_pc=0x0c07f954u; return 0; }
r[6]=r[0];
goto P_0c07f956;
P_0c07f956: /* original 4a0b, guest PC 0x0c07f956 */
if(!s->budget--) { s->failed_pc=0x0c07f956u; return 0; }
target=r[10];
r[16]=code_base|0x0c07f95au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f95au) { target=s->pc; goto dispatch; }
goto P_0c07f95a;
P_0c07f958: /* original 64e3, guest PC 0x0c07f958 */
if(!s->budget--) { s->failed_pc=0x0c07f958u; return 0; }
r[4]=r[14];
goto P_0c07f95a;
P_0c07f95a: /* original a046, guest PC 0x0c07f95a */
if(!s->budget--) { s->failed_pc=0x0c07f95au; return 0; }
r[9]=r[0];
goto P_0c07f9ea;
P_0c07f95c: /* original 6903, guest PC 0x0c07f95c */
if(!s->budget--) { s->failed_pc=0x0c07f95cu; return 0; }
r[9]=r[0];
goto P_0c07f95e;
P_0c07f95e: /* original e20e, guest PC 0x0c07f95e */
if(!s->budget--) { s->failed_pc=0x0c07f95eu; return 0; }
r[2]=0x0000000eu;
goto P_0c07f960;
P_0c07f960: /* original 644e, guest PC 0x0c07f960 */
if(!s->budget--) { s->failed_pc=0x0c07f960u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c07f962;
P_0c07f962: /* original 3423, guest PC 0x0c07f962 */
if(!s->budget--) { s->failed_pc=0x0c07f962u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c07f964;
P_0c07f964: /* original 892e, guest PC 0x0c07f964 */
if(!s->budget--) { s->failed_pc=0x0c07f964u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07f9c4; }
goto P_0c07f966;
P_0c07f966: /* original d716, guest PC 0x0c07f966 */
if(!s->budget--) { s->failed_pc=0x0c07f966u; return 0; }
r[7]=read(ram,0x0c07f9c0u,4);
goto P_0c07f968;
P_0c07f968: /* original 37bc, guest PC 0x0c07f968 */
if(!s->budget--) { s->failed_pc=0x0c07f968u; return 0; }
r[7]+=r[11];
goto P_0c07f96a;
P_0c07f96a: /* original 2f72, guest PC 0x0c07f96a */
if(!s->budget--) { s->failed_pc=0x0c07f96au; return 0; }
write(ram,r[15],r[7],4);
goto P_0c07f96c;
P_0c07f96c: /* original 66f2, guest PC 0x0c07f96c */
if(!s->budget--) { s->failed_pc=0x0c07f96cu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c07f96e;
P_0c07f96e: /* original 950f, guest PC 0x0c07f96e */
if(!s->budget--) { s->failed_pc=0x0c07f96eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f990u,2);
goto P_0c07f970;
P_0c07f970: /* original 8462, guest PC 0x0c07f970 */
if(!s->budget--) { s->failed_pc=0x0c07f970u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+2,1);
goto P_0c07f972;
P_0c07f972: /* original 6771, guest PC 0x0c07f972 */
if(!s->budget--) { s->failed_pc=0x0c07f972u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[7]=tmp;
goto P_0c07f974;
P_0c07f974: /* original a036, guest PC 0x0c07f974 */
if(!s->budget--) { s->failed_pc=0x0c07f974u; return 0; }
r[6]=r[0];
goto P_0c07f9e4;
P_0c07f976: /* original 6603, guest PC 0x0c07f976 */
if(!s->budget--) { s->failed_pc=0x0c07f976u; return 0; }
r[6]=r[0];
if(!vf3_matrix_family(0x0c07f978u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07f978u; return 0; } return 1;
P_0c07f9c4: /* original d750, guest PC 0x0c07f9c4 */
if(!s->budget--) { s->failed_pc=0x0c07f9c4u; return 0; }
r[7]=read(ram,0x0c07fb08u,4);
goto P_0c07f9c6;
P_0c07f9c6: /* original 37bc, guest PC 0x0c07f9c6 */
if(!s->budget--) { s->failed_pc=0x0c07f9c6u; return 0; }
r[7]+=r[11];
goto P_0c07f9c8;
P_0c07f9c8: /* original 2f72, guest PC 0x0c07f9c8 */
if(!s->budget--) { s->failed_pc=0x0c07f9c8u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c07f9ca;
P_0c07f9ca: /* original 66f2, guest PC 0x0c07f9ca */
if(!s->budget--) { s->failed_pc=0x0c07f9cau; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c07f9cc;
P_0c07f9cc: /* original 9588, guest PC 0x0c07f9cc */
if(!s->budget--) { s->failed_pc=0x0c07f9ccu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fae0u,2);
goto P_0c07f9ce;
P_0c07f9ce: /* original 8462, guest PC 0x0c07f9ce */
if(!s->budget--) { s->failed_pc=0x0c07f9ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+2,1);
goto P_0c07f9d0;
P_0c07f9d0: /* original 6771, guest PC 0x0c07f9d0 */
if(!s->budget--) { s->failed_pc=0x0c07f9d0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[7]=tmp;
goto P_0c07f9d2;
P_0c07f9d2: /* original 6603, guest PC 0x0c07f9d2 */
if(!s->budget--) { s->failed_pc=0x0c07f9d2u; return 0; }
r[6]=r[0];
goto P_0c07f9d4;
P_0c07f9d4: /* original 4a0b, guest PC 0x0c07f9d4 */
if(!s->budget--) { s->failed_pc=0x0c07f9d4u; return 0; }
target=r[10];
r[16]=code_base|0x0c07f9d8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f9d8u) { target=s->pc; goto dispatch; }
goto P_0c07f9d8;
P_0c07f9d6: /* original 64e3, guest PC 0x0c07f9d6 */
if(!s->budget--) { s->failed_pc=0x0c07f9d6u; return 0; }
r[4]=r[14];
goto P_0c07f9d8;
P_0c07f9d8: /* original 66f2, guest PC 0x0c07f9d8 */
if(!s->budget--) { s->failed_pc=0x0c07f9d8u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c07f9da;
P_0c07f9da: /* original 67f2, guest PC 0x0c07f9da */
if(!s->budget--) { s->failed_pc=0x0c07f9dau; return 0; }
tmp=read(ram,r[15],4);
r[7]=tmp;
goto P_0c07f9dc;
P_0c07f9dc: /* original 8463, guest PC 0x0c07f9dc */
if(!s->budget--) { s->failed_pc=0x0c07f9dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+3,1);
goto P_0c07f9de;
P_0c07f9de: /* original 9580, guest PC 0x0c07f9de */
if(!s->budget--) { s->failed_pc=0x0c07f9deu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fae2u,2);
goto P_0c07f9e0;
P_0c07f9e0: /* original 6771, guest PC 0x0c07f9e0 */
if(!s->budget--) { s->failed_pc=0x0c07f9e0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[7]=tmp;
goto P_0c07f9e2;
P_0c07f9e2: /* original 6603, guest PC 0x0c07f9e2 */
if(!s->budget--) { s->failed_pc=0x0c07f9e2u; return 0; }
r[6]=r[0];
goto P_0c07f9e4;
P_0c07f9e4: /* original 4a0b, guest PC 0x0c07f9e4 */
if(!s->budget--) { s->failed_pc=0x0c07f9e4u; return 0; }
target=r[10];
r[16]=code_base|0x0c07f9e8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f9e8u) { target=s->pc; goto dispatch; }
goto P_0c07f9e8;
P_0c07f9e6: /* original 64e3, guest PC 0x0c07f9e6 */
if(!s->budget--) { s->failed_pc=0x0c07f9e6u; return 0; }
r[4]=r[14];
goto P_0c07f9e8;
P_0c07f9e8: /* original 6903, guest PC 0x0c07f9e8 */
if(!s->budget--) { s->failed_pc=0x0c07f9e8u; return 0; }
r[9]=r[0];
goto P_0c07f9ea;
P_0c07f9ea: /* original 907b, guest PC 0x0c07f9ea */
if(!s->budget--) { s->failed_pc=0x0c07f9eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fae4u,2);
goto P_0c07f9ec;
P_0c07f9ec: /* original 03dc, guest PC 0x0c07f9ec */
if(!s->budget--) { s->failed_pc=0x0c07f9ecu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07f9ee;
P_0c07f9ee: /* original 2338, guest PC 0x0c07f9ee */
if(!s->budget--) { s->failed_pc=0x0c07f9eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07f9f0;
P_0c07f9f0: /* original 8b01, guest PC 0x0c07f9f0 */
if(!s->budget--) { s->failed_pc=0x0c07f9f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07f9f6; }
goto P_0c07f9f2;
P_0c07f9f2: /* original a0e8, guest PC 0x0c07f9f2 */
if(!s->budget--) { s->failed_pc=0x0c07f9f2u; return 0; }
goto P_0c07fbc6;
P_0c07f9f4: /* original 0009, guest PC 0x0c07f9f4 */
if(!s->budget--) { s->failed_pc=0x0c07f9f4u; return 0; }
goto P_0c07f9f6;
P_0c07f9f6: /* original 0dc4, guest PC 0x0c07f9f6 */
if(!s->budget--) { s->failed_pc=0x0c07f9f6u; return 0; }
write(ram,r[13]+r[0],r[12],1);
goto P_0c07f9f8;
P_0c07f9f8: /* original 54f1, guest PC 0x0c07f9f8 */
if(!s->budget--) { s->failed_pc=0x0c07f9f8u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07f9fa;
P_0c07f9fa: /* original 480b, guest PC 0x0c07f9fa */
if(!s->budget--) { s->failed_pc=0x0c07f9fau; return 0; }
target=r[8];
r[16]=code_base|0x0c07f9feu;
r[4]+=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f9feu) { target=s->pc; goto dispatch; }
goto P_0c07f9fe;
P_0c07f9fc: /* original 7412, guest PC 0x0c07f9fc */
if(!s->budget--) { s->failed_pc=0x0c07f9fcu; return 0; }
r[4]+=0x00000012u;
goto P_0c07f9fe;
P_0c07f9fe: /* original 600c, guest PC 0x0c07f9fe */
if(!s->budget--) { s->failed_pc=0x0c07f9feu; return 0; }
r[0]=r[0]&255u;
goto P_0c07fa00;
P_0c07fa00: /* original 1f01, guest PC 0x0c07fa00 */
if(!s->budget--) { s->failed_pc=0x0c07fa00u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c07fa02;
P_0c07fa02: /* original 9070, guest PC 0x0c07fa02 */
if(!s->budget--) { s->failed_pc=0x0c07fa02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fae6u,2);
goto P_0c07fa04;
P_0c07fa04: /* original db41, guest PC 0x0c07fa04 */
if(!s->budget--) { s->failed_pc=0x0c07fa04u; return 0; }
r[11]=read(ram,0x0c07fb0cu,4);
goto P_0c07fa06;
P_0c07fa06: /* original 09dc, guest PC 0x0c07fa06 */
if(!s->budget--) { s->failed_pc=0x0c07fa06u; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07fa08;
P_0c07fa08: /* original 639e, guest PC 0x0c07fa08 */
if(!s->budget--) { s->failed_pc=0x0c07fa08u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[9];
goto P_0c07fa0a;
P_0c07fa0a: /* original 2f32, guest PC 0x0c07fa0a */
if(!s->budget--) { s->failed_pc=0x0c07fa0au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07fa0c;
P_0c07fa0c: /* original 52f1, guest PC 0x0c07fa0c */
if(!s->budget--) { s->failed_pc=0x0c07fa0cu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07fa0e;
P_0c07fa0e: /* original 2228, guest PC 0x0c07fa0e */
if(!s->budget--) { s->failed_pc=0x0c07fa0eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07fa10;
P_0c07fa10: /* original 8b13, guest PC 0x0c07fa10 */
if(!s->budget--) { s->failed_pc=0x0c07fa10u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07fa3a; }
goto P_0c07fa12;
P_0c07fa12: /* original 2fc6, guest PC 0x0c07fa12 */
if(!s->budget--) { s->failed_pc=0x0c07fa12u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07fa14;
P_0c07fa14: /* original e700, guest PC 0x0c07fa14 */
if(!s->budget--) { s->failed_pc=0x0c07fa14u; return 0; }
r[7]=0x00000000u;
goto P_0c07fa16;
P_0c07fa16: /* original 9567, guest PC 0x0c07fa16 */
if(!s->budget--) { s->failed_pc=0x0c07fa16u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fae8u,2);
goto P_0c07fa18;
P_0c07fa18: /* original 9467, guest PC 0x0c07fa18 */
if(!s->budget--) { s->failed_pc=0x0c07fa18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07faeau,2);
goto P_0c07fa1a;
P_0c07fa1a: /* original 4b0b, guest PC 0x0c07fa1a */
if(!s->budget--) { s->failed_pc=0x0c07fa1au; return 0; }
target=r[11];
r[16]=code_base|0x0c07fa1eu;
r[6]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07fa1eu) { target=s->pc; goto dispatch; }
goto P_0c07fa1e;
P_0c07fa1c: /* original 66e3, guest PC 0x0c07fa1c */
if(!s->budget--) { s->failed_pc=0x0c07fa1cu; return 0; }
r[6]=r[14];
goto P_0c07fa1e;
P_0c07fa1e: /* original 2fc6, guest PC 0x0c07fa1e */
if(!s->budget--) { s->failed_pc=0x0c07fa1eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07fa20;
P_0c07fa20: /* original e700, guest PC 0x0c07fa20 */
if(!s->budget--) { s->failed_pc=0x0c07fa20u; return 0; }
r[7]=0x00000000u;
goto P_0c07fa22;
P_0c07fa22: /* original 9563, guest PC 0x0c07fa22 */
if(!s->budget--) { s->failed_pc=0x0c07fa22u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07faecu,2);
goto P_0c07fa24;
P_0c07fa24: /* original 9463, guest PC 0x0c07fa24 */
if(!s->budget--) { s->failed_pc=0x0c07fa24u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07faeeu,2);
goto P_0c07fa26;
P_0c07fa26: /* original 4b0b, guest PC 0x0c07fa26 */
if(!s->budget--) { s->failed_pc=0x0c07fa26u; return 0; }
target=r[11];
r[16]=code_base|0x0c07fa2au;
r[6]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07fa2au) { target=s->pc; goto dispatch; }
goto P_0c07fa2a;
P_0c07fa28: /* original 66e3, guest PC 0x0c07fa28 */
if(!s->budget--) { s->failed_pc=0x0c07fa28u; return 0; }
r[6]=r[14];
goto P_0c07fa2a;
P_0c07fa2a: /* original 2fc6, guest PC 0x0c07fa2a */
if(!s->budget--) { s->failed_pc=0x0c07fa2au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07fa2c;
P_0c07fa2c: /* original e700, guest PC 0x0c07fa2c */
if(!s->budget--) { s->failed_pc=0x0c07fa2cu; return 0; }
r[7]=0x00000000u;
goto P_0c07fa2e;
P_0c07fa2e: /* original 955f, guest PC 0x0c07fa2e */
if(!s->budget--) { s->failed_pc=0x0c07fa2eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07faf0u,2);
goto P_0c07fa30;
P_0c07fa30: /* original 945f, guest PC 0x0c07fa30 */
if(!s->budget--) { s->failed_pc=0x0c07fa30u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07faf2u,2);
goto P_0c07fa32;
P_0c07fa32: /* original 4b0b, guest PC 0x0c07fa32 */
if(!s->budget--) { s->failed_pc=0x0c07fa32u; return 0; }
target=r[11];
r[16]=code_base|0x0c07fa36u;
r[6]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07fa36u) { target=s->pc; goto dispatch; }
goto P_0c07fa36;
P_0c07fa34: /* original 66e3, guest PC 0x0c07fa34 */
if(!s->budget--) { s->failed_pc=0x0c07fa34u; return 0; }
r[6]=r[14];
goto P_0c07fa36;
P_0c07fa36: /* original a01e, guest PC 0x0c07fa36 */
if(!s->budget--) { s->failed_pc=0x0c07fa36u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07fa76;
P_0c07fa38: /* original 7f0c, guest PC 0x0c07fa38 */
if(!s->budget--) { s->failed_pc=0x0c07fa38u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07fa3a;
P_0c07fa3a: /* original 2fc6, guest PC 0x0c07fa3a */
if(!s->budget--) { s->failed_pc=0x0c07fa3au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07fa3c;
P_0c07fa3c: /* original e700, guest PC 0x0c07fa3c */
if(!s->budget--) { s->failed_pc=0x0c07fa3cu; return 0; }
r[7]=0x00000000u;
goto P_0c07fa3e;
P_0c07fa3e: /* original 9559, guest PC 0x0c07fa3e */
if(!s->budget--) { s->failed_pc=0x0c07fa3eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07faf4u,2);
goto P_0c07fa40;
P_0c07fa40: /* original 9459, guest PC 0x0c07fa40 */
if(!s->budget--) { s->failed_pc=0x0c07fa40u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07faf6u,2);
goto P_0c07fa42;
P_0c07fa42: /* original 4b0b, guest PC 0x0c07fa42 */
if(!s->budget--) { s->failed_pc=0x0c07fa42u; return 0; }
target=r[11];
r[16]=code_base|0x0c07fa46u;
r[6]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07fa46u) { target=s->pc; goto dispatch; }
goto P_0c07fa46;
P_0c07fa44: /* original 66e3, guest PC 0x0c07fa44 */
if(!s->budget--) { s->failed_pc=0x0c07fa44u; return 0; }
r[6]=r[14];
goto P_0c07fa46;
P_0c07fa46: /* original 7f04, guest PC 0x0c07fa46 */
if(!s->budget--) { s->failed_pc=0x0c07fa46u; return 0; }
r[15]+=0x00000004u;
goto P_0c07fa48;
P_0c07fa48: /* original 63f2, guest PC 0x0c07fa48 */
if(!s->budget--) { s->failed_pc=0x0c07fa48u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07fa4a;
P_0c07fa4a: /* original e20e, guest PC 0x0c07fa4a */
if(!s->budget--) { s->failed_pc=0x0c07fa4au; return 0; }
r[2]=0x0000000eu;
goto P_0c07fa4c;
P_0c07fa4c: /* original 3323, guest PC 0x0c07fa4c */
if(!s->budget--) { s->failed_pc=0x0c07fa4cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c07fa4e;
P_0c07fa4e: /* original 8912, guest PC 0x0c07fa4e */
if(!s->budget--) { s->failed_pc=0x0c07fa4eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07fa76; }
goto P_0c07fa50;
P_0c07fa50: /* original 2fc6, guest PC 0x0c07fa50 */
if(!s->budget--) { s->failed_pc=0x0c07fa50u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07fa52;
P_0c07fa52: /* original e700, guest PC 0x0c07fa52 */
if(!s->budget--) { s->failed_pc=0x0c07fa52u; return 0; }
r[7]=0x00000000u;
goto P_0c07fa54;
P_0c07fa54: /* original 9550, guest PC 0x0c07fa54 */
if(!s->budget--) { s->failed_pc=0x0c07fa54u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07faf8u,2);
goto P_0c07fa56;
P_0c07fa56: /* original 9450, guest PC 0x0c07fa56 */
if(!s->budget--) { s->failed_pc=0x0c07fa56u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fafau,2);
goto P_0c07fa58;
P_0c07fa58: /* original 4b0b, guest PC 0x0c07fa58 */
if(!s->budget--) { s->failed_pc=0x0c07fa58u; return 0; }
target=r[11];
r[16]=code_base|0x0c07fa5cu;
r[6]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07fa5cu) { target=s->pc; goto dispatch; }
goto P_0c07fa5c;
P_0c07fa5a: /* original 66e3, guest PC 0x0c07fa5a */
if(!s->budget--) { s->failed_pc=0x0c07fa5au; return 0; }
r[6]=r[14];
goto P_0c07fa5c;
P_0c07fa5c: /* original 659e, guest PC 0x0c07fa5c */
if(!s->budget--) { s->failed_pc=0x0c07fa5cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[9];
goto P_0c07fa5e;
P_0c07fa5e: /* original 2fc6, guest PC 0x0c07fa5e */
if(!s->budget--) { s->failed_pc=0x0c07fa5eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07fa60;
P_0c07fa60: /* original d02b, guest PC 0x0c07fa60 */
if(!s->budget--) { s->failed_pc=0x0c07fa60u; return 0; }
r[0]=read(ram,0x0c07fb10u,4);
goto P_0c07fa62;
P_0c07fa62: /* original 4508, guest PC 0x0c07fa62 */
if(!s->budget--) { s->failed_pc=0x0c07fa62u; return 0; }
r[5]<<=2;
goto P_0c07fa64;
P_0c07fa64: /* original 944a, guest PC 0x0c07fa64 */
if(!s->budget--) { s->failed_pc=0x0c07fa64u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fafcu,2);
goto P_0c07fa66;
P_0c07fa66: /* original e700, guest PC 0x0c07fa66 */
if(!s->budget--) { s->failed_pc=0x0c07fa66u; return 0; }
r[7]=0x00000000u;
goto P_0c07fa68;
P_0c07fa68: /* original 055c, guest PC 0x0c07fa68 */
if(!s->budget--) { s->failed_pc=0x0c07fa68u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07fa6a;
P_0c07fa6a: /* original 66e3, guest PC 0x0c07fa6a */
if(!s->budget--) { s->failed_pc=0x0c07fa6au; return 0; }
r[6]=r[14];
goto P_0c07fa6c;
P_0c07fa6c: /* original d029, guest PC 0x0c07fa6c */
if(!s->budget--) { s->failed_pc=0x0c07fa6cu; return 0; }
r[0]=read(ram,0x0c07fb14u,4);
goto P_0c07fa6e;
P_0c07fa6e: /* original 4500, guest PC 0x0c07fa6e */
if(!s->budget--) { s->failed_pc=0x0c07fa6eu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07fa70;
P_0c07fa70: /* original 4b0b, guest PC 0x0c07fa70 */
if(!s->budget--) { s->failed_pc=0x0c07fa70u; return 0; }
target=r[11];
r[16]=code_base|0x0c07fa74u;
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07fa74u) { target=s->pc; goto dispatch; }
goto P_0c07fa74;
P_0c07fa72: /* original 055d, guest PC 0x0c07fa72 */
if(!s->budget--) { s->failed_pc=0x0c07fa72u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c07fa74;
P_0c07fa74: /* original 7f08, guest PC 0x0c07fa74 */
if(!s->budget--) { s->failed_pc=0x0c07fa74u; return 0; }
r[15]+=0x00000008u;
goto P_0c07fa76;
P_0c07fa76: /* original 63f2, guest PC 0x0c07fa76 */
if(!s->budget--) { s->failed_pc=0x0c07fa76u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07fa78;
P_0c07fa78: /* original e20e, guest PC 0x0c07fa78 */
if(!s->budget--) { s->failed_pc=0x0c07fa78u; return 0; }
r[2]=0x0000000eu;
goto P_0c07fa7a;
P_0c07fa7a: /* original 9940, guest PC 0x0c07fa7a */
if(!s->budget--) { s->failed_pc=0x0c07fa7au; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fafeu,2);
goto P_0c07fa7c;
P_0c07fa7c: /* original 3323, guest PC 0x0c07fa7c */
if(!s->budget--) { s->failed_pc=0x0c07fa7cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c07fa7e;
P_0c07fa7e: /* original 8920, guest PC 0x0c07fa7e */
if(!s->budget--) { s->failed_pc=0x0c07fa7eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07fac2; }
goto P_0c07fa80;
P_0c07fa80: /* original 55d2, guest PC 0x0c07fa80 */
if(!s->budget--) { s->failed_pc=0x0c07fa80u; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c07fa82;
P_0c07fa82: /* original e310, guest PC 0x0c07fa82 */
if(!s->budget--) { s->failed_pc=0x0c07fa82u; return 0; }
r[3]=0x00000010u;
goto P_0c07fa84;
P_0c07fa84: /* original 2538, guest PC 0x0c07fa84 */
if(!s->budget--) { s->failed_pc=0x0c07fa84u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c07fa86;
P_0c07fa86: /* original 8d01, guest PC 0x0c07fa86 */
if(!s->budget--) { s->failed_pc=0x0c07fa86u; return 0; }
cond=r[17]&1u;
r[4]=0x00000006u;
if(cond) { goto P_0c07fa8c; }
goto P_0c07fa8a;
P_0c07fa88: /* original e406, guest PC 0x0c07fa88 */
if(!s->budget--) { s->failed_pc=0x0c07fa88u; return 0; }
r[4]=0x00000006u;
goto P_0c07fa8a;
P_0c07fa8a: /* original e405, guest PC 0x0c07fa8a */
if(!s->budget--) { s->failed_pc=0x0c07fa8au; return 0; }
r[4]=0x00000005u;
goto P_0c07fa8c;
P_0c07fa8c: /* original 9038, guest PC 0x0c07fa8c */
if(!s->budget--) { s->failed_pc=0x0c07fa8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fb00u,2);
goto P_0c07fa8e;
P_0c07fa8e: /* original d322, guest PC 0x0c07fa8e */
if(!s->budget--) { s->failed_pc=0x0c07fa8eu; return 0; }
r[3]=read(ram,0x0c07fb18u,4);
goto P_0c07fa90;
P_0c07fa90: /* original 06dd, guest PC 0x0c07fa90 */
if(!s->budget--) { s->failed_pc=0x0c07fa90u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c07fa92;
P_0c07fa92: /* original 656f, guest PC 0x0c07fa92 */
if(!s->budget--) { s->failed_pc=0x0c07fa92u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c07fa94;
P_0c07fa94: /* original 6153, guest PC 0x0c07fa94 */
if(!s->budget--) { s->failed_pc=0x0c07fa94u; return 0; }
r[1]=r[5];
goto P_0c07fa96;
P_0c07fa96: /* original 430b, guest PC 0x0c07fa96 */
if(!s->budget--) { s->failed_pc=0x0c07fa96u; return 0; }
target=r[3];
r[16]=code_base|0x0c07fa9au;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07fa9au) { target=s->pc; goto dispatch; }
goto P_0c07fa9a;
P_0c07fa98: /* original 6043, guest PC 0x0c07fa98 */
if(!s->budget--) { s->failed_pc=0x0c07fa98u; return 0; }
r[0]=r[4];
goto P_0c07fa9a;
P_0c07fa9a: /* original 0047, guest PC 0x0c07fa9a */
if(!s->budget--) { s->failed_pc=0x0c07fa9au; return 0; }
r[19]=r[0]*r[4];
goto P_0c07fa9c;
P_0c07fa9c: /* original 52f1, guest PC 0x0c07fa9c */
if(!s->budget--) { s->failed_pc=0x0c07fa9cu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07fa9e;
P_0c07fa9e: /* original 2228, guest PC 0x0c07fa9e */
if(!s->budget--) { s->failed_pc=0x0c07fa9eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07faa0;
P_0c07faa0: /* original 041a, guest PC 0x0c07faa0 */
if(!s->budget--) { s->failed_pc=0x0c07faa0u; return 0; }
r[4]=r[19];
goto P_0c07faa2;
P_0c07faa2: /* original 3548, guest PC 0x0c07faa2 */
if(!s->budget--) { s->failed_pc=0x0c07faa2u; return 0; }
r[5]-=r[4];
goto P_0c07faa4;
P_0c07faa4: /* original d41d, guest PC 0x0c07faa4 */
if(!s->budget--) { s->failed_pc=0x0c07faa4u; return 0; }
r[4]=read(ram,0x0c07fb1cu,4);
goto P_0c07faa6;
P_0c07faa6: /* original 8d01, guest PC 0x0c07faa6 */
if(!s->budget--) { s->failed_pc=0x0c07faa6u; return 0; }
cond=r[17]&1u;
r[0]=r[5];
if(cond) { goto P_0c07faac; }
goto P_0c07faaa;
P_0c07faa8: /* original 6053, guest PC 0x0c07faa8 */
if(!s->budget--) { s->failed_pc=0x0c07faa8u; return 0; }
r[0]=r[5];
goto P_0c07faaa;
P_0c07faaa: /* original d41d, guest PC 0x0c07faaa */
if(!s->budget--) { s->failed_pc=0x0c07faaau; return 0; }
r[4]=read(ram,0x0c07fb20u,4);
goto P_0c07faac;
P_0c07faac: /* original 4000, guest PC 0x0c07faac */
if(!s->budget--) { s->failed_pc=0x0c07faacu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07faae;
P_0c07faae: /* original 66e3, guest PC 0x0c07faae */
if(!s->budget--) { s->failed_pc=0x0c07faaeu; return 0; }
r[6]=r[14];
goto P_0c07fab0;
P_0c07fab0: /* original 034d, guest PC 0x0c07fab0 */
if(!s->budget--) { s->failed_pc=0x0c07fab0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07fab2;
P_0c07fab2: /* original e700, guest PC 0x0c07fab2 */
if(!s->budget--) { s->failed_pc=0x0c07fab2u; return 0; }
r[7]=0x00000000u;
goto P_0c07fab4;
P_0c07fab4: /* original 2f31, guest PC 0x0c07fab4 */
if(!s->budget--) { s->failed_pc=0x0c07fab4u; return 0; }
write(ram,r[15],r[3],2);
goto P_0c07fab6;
P_0c07fab6: /* original 2fc6, guest PC 0x0c07fab6 */
if(!s->budget--) { s->failed_pc=0x0c07fab6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07fab8;
P_0c07fab8: /* original 9421, guest PC 0x0c07fab8 */
if(!s->budget--) { s->failed_pc=0x0c07fab8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fafeu,2);
goto P_0c07faba;
P_0c07faba: /* original 4b0b, guest PC 0x0c07faba */
if(!s->budget--) { s->failed_pc=0x0c07fabau; return 0; }
target=r[11];
r[16]=code_base|0x0c07fabeu;
r[5]=(uint32_t)(int32_t)(int16_t)r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07fabeu) { target=s->pc; goto dispatch; }
goto P_0c07fabe;
P_0c07fabc: /* original 653f, guest PC 0x0c07fabc */
if(!s->budget--) { s->failed_pc=0x0c07fabcu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c07fabe;
P_0c07fabe: /* original a03f, guest PC 0x0c07fabe */
if(!s->budget--) { s->failed_pc=0x0c07fabeu; return 0; }
r[15]+=0x00000004u;
goto P_0c07fb40;
P_0c07fac0: /* original 7f04, guest PC 0x0c07fac0 */
if(!s->budget--) { s->failed_pc=0x0c07fac0u; return 0; }
r[15]+=0x00000004u;
goto P_0c07fac2;
P_0c07fac2: /* original 51f1, guest PC 0x0c07fac2 */
if(!s->budget--) { s->failed_pc=0x0c07fac2u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c07fac4;
P_0c07fac4: /* original 2118, guest PC 0x0c07fac4 */
if(!s->budget--) { s->failed_pc=0x0c07fac4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c07fac6;
P_0c07fac6: /* original 8b2d, guest PC 0x0c07fac6 */
if(!s->budget--) { s->failed_pc=0x0c07fac6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07fb24; }
goto P_0c07fac8;
P_0c07fac8: /* original 2fc6, guest PC 0x0c07fac8 */
if(!s->budget--) { s->failed_pc=0x0c07fac8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07faca;
P_0c07faca: /* original e700, guest PC 0x0c07faca */
if(!s->budget--) { s->failed_pc=0x0c07facau; return 0; }
r[7]=0x00000000u;
goto P_0c07facc;
P_0c07facc: /* original 9519, guest PC 0x0c07facc */
if(!s->budget--) { s->failed_pc=0x0c07faccu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fb02u,2);
goto P_0c07face;
P_0c07face: /* original 9416, guest PC 0x0c07face */
if(!s->budget--) { s->failed_pc=0x0c07faceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fafeu,2);
goto P_0c07fad0;
P_0c07fad0: /* original 4b0b, guest PC 0x0c07fad0 */
if(!s->budget--) { s->failed_pc=0x0c07fad0u; return 0; }
target=r[11];
r[16]=code_base|0x0c07fad4u;
r[6]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07fad4u) { target=s->pc; goto dispatch; }
goto P_0c07fad4;
P_0c07fad2: /* original 66e3, guest PC 0x0c07fad2 */
if(!s->budget--) { s->failed_pc=0x0c07fad2u; return 0; }
r[6]=r[14];
goto P_0c07fad4;
P_0c07fad4: /* original 9916, guest PC 0x0c07fad4 */
if(!s->budget--) { s->failed_pc=0x0c07fad4u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fb04u,2);
goto P_0c07fad6;
P_0c07fad6: /* original e700, guest PC 0x0c07fad6 */
if(!s->budget--) { s->failed_pc=0x0c07fad6u; return 0; }
r[7]=0x00000000u;
goto P_0c07fad8;
P_0c07fad8: /* original 2fc6, guest PC 0x0c07fad8 */
if(!s->budget--) { s->failed_pc=0x0c07fad8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07fada;
P_0c07fada: /* original 9514, guest PC 0x0c07fada */
if(!s->budget--) { s->failed_pc=0x0c07fadau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fb06u,2);
goto P_0c07fadc;
P_0c07fadc: /* original a02d, guest PC 0x0c07fadc */
if(!s->budget--) { s->failed_pc=0x0c07fadcu; return 0; }
r[6]=r[14];
goto P_0c07fb3a;
P_0c07fade: /* original 66e3, guest PC 0x0c07fade */
if(!s->budget--) { s->failed_pc=0x0c07fadeu; return 0; }
r[6]=r[14];
if(!vf3_matrix_family(0x0c07fae0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07fae0u; return 0; } return 1;
P_0c07fb24: /* original 2fc6, guest PC 0x0c07fb24 */
if(!s->budget--) { s->failed_pc=0x0c07fb24u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07fb26;
P_0c07fb26: /* original e700, guest PC 0x0c07fb26 */
if(!s->budget--) { s->failed_pc=0x0c07fb26u; return 0; }
r[7]=0x00000000u;
goto P_0c07fb28;
P_0c07fb28: /* original 9594, guest PC 0x0c07fb28 */
if(!s->budget--) { s->failed_pc=0x0c07fb28u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc54u,2);
goto P_0c07fb2a;
P_0c07fb2a: /* original 9494, guest PC 0x0c07fb2a */
if(!s->budget--) { s->failed_pc=0x0c07fb2au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc56u,2);
goto P_0c07fb2c;
P_0c07fb2c: /* original 4b0b, guest PC 0x0c07fb2c */
if(!s->budget--) { s->failed_pc=0x0c07fb2cu; return 0; }
target=r[11];
r[16]=code_base|0x0c07fb30u;
r[6]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07fb30u) { target=s->pc; goto dispatch; }
goto P_0c07fb30;
P_0c07fb2e: /* original 66e3, guest PC 0x0c07fb2e */
if(!s->budget--) { s->failed_pc=0x0c07fb2eu; return 0; }
r[6]=r[14];
goto P_0c07fb30;
P_0c07fb30: /* original 9992, guest PC 0x0c07fb30 */
if(!s->budget--) { s->failed_pc=0x0c07fb30u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc58u,2);
goto P_0c07fb32;
P_0c07fb32: /* original 66e3, guest PC 0x0c07fb32 */
if(!s->budget--) { s->failed_pc=0x0c07fb32u; return 0; }
r[6]=r[14];
goto P_0c07fb34;
P_0c07fb34: /* original 2fc6, guest PC 0x0c07fb34 */
if(!s->budget--) { s->failed_pc=0x0c07fb34u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07fb36;
P_0c07fb36: /* original e700, guest PC 0x0c07fb36 */
if(!s->budget--) { s->failed_pc=0x0c07fb36u; return 0; }
r[7]=0x00000000u;
goto P_0c07fb38;
P_0c07fb38: /* original 958f, guest PC 0x0c07fb38 */
if(!s->budget--) { s->failed_pc=0x0c07fb38u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc5au,2);
goto P_0c07fb3a;
P_0c07fb3a: /* original 4b0b, guest PC 0x0c07fb3a */
if(!s->budget--) { s->failed_pc=0x0c07fb3au; return 0; }
target=r[11];
r[16]=code_base|0x0c07fb3eu;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07fb3eu) { target=s->pc; goto dispatch; }
goto P_0c07fb3e;
P_0c07fb3c: /* original 6493, guest PC 0x0c07fb3c */
if(!s->budget--) { s->failed_pc=0x0c07fb3cu; return 0; }
r[4]=r[9];
goto P_0c07fb3e;
P_0c07fb3e: /* original 7f08, guest PC 0x0c07fb3e */
if(!s->budget--) { s->failed_pc=0x0c07fb3eu; return 0; }
r[15]+=0x00000008u;
goto P_0c07fb40;
P_0c07fb40: /* original 908c, guest PC 0x0c07fb40 */
if(!s->budget--) { s->failed_pc=0x0c07fb40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc5cu,2);
goto P_0c07fb42;
P_0c07fb42: /* original 938c, guest PC 0x0c07fb42 */
if(!s->budget--) { s->failed_pc=0x0c07fb42u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc5eu,2);
goto P_0c07fb44;
P_0c07fb44: /* original 04dd, guest PC 0x0c07fb44 */
if(!s->budget--) { s->failed_pc=0x0c07fb44u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c07fb46;
P_0c07fb46: /* original 3430, guest PC 0x0c07fb46 */
if(!s->budget--) { s->failed_pc=0x0c07fb46u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c07fb48;
P_0c07fb48: /* original 8b3d, guest PC 0x0c07fb48 */
if(!s->budget--) { s->failed_pc=0x0c07fb48u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07fbc6; }
goto P_0c07fb4a;
P_0c07fb4a: /* original e029, guest PC 0x0c07fb4a */
if(!s->budget--) { s->failed_pc=0x0c07fb4au; return 0; }
r[0]=0x00000029u;
goto P_0c07fb4c;
P_0c07fb4c: /* original d24a, guest PC 0x0c07fb4c */
if(!s->budget--) { s->failed_pc=0x0c07fb4cu; return 0; }
r[2]=read(ram,0x0c07fc78u,4);
goto P_0c07fb4e;
P_0c07fb4e: /* original 05dc, guest PC 0x0c07fb4e */
if(!s->budget--) { s->failed_pc=0x0c07fb4eu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07fb50;
P_0c07fb50: /* original 605e, guest PC 0x0c07fb50 */
if(!s->budget--) { s->failed_pc=0x0c07fb50u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c07fb52;
P_0c07fb52: /* original 8801, guest PC 0x0c07fb52 */
if(!s->budget--) { s->failed_pc=0x0c07fb52u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07fb54;
P_0c07fb54: /* original 8d01, guest PC 0x0c07fb54 */
if(!s->budget--) { s->failed_pc=0x0c07fb54u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[2],4);
r[4]=tmp;
if(cond) { goto P_0c07fb5a; }
goto P_0c07fb58;
P_0c07fb56: /* original 6422, guest PC 0x0c07fb56 */
if(!s->budget--) { s->failed_pc=0x0c07fb56u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c07fb58;
P_0c07fb58: /* original 4419, guest PC 0x0c07fb58 */
if(!s->budget--) { s->failed_pc=0x0c07fb58u; return 0; }
r[4]>>=8;
goto P_0c07fb5a;
P_0c07fb5a: /* original 9281, guest PC 0x0c07fb5a */
if(!s->budget--) { s->failed_pc=0x0c07fb5au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc60u,2);
goto P_0c07fb5c;
P_0c07fb5c: /* original 9381, guest PC 0x0c07fb5c */
if(!s->budget--) { s->failed_pc=0x0c07fb5cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc62u,2);
goto P_0c07fb5e;
P_0c07fb5e: /* original 2429, guest PC 0x0c07fb5e */
if(!s->budget--) { s->failed_pc=0x0c07fb5eu; return 0; }
r[4]&=r[2];
goto P_0c07fb60;
P_0c07fb60: /* original 9180, guest PC 0x0c07fb60 */
if(!s->budget--) { s->failed_pc=0x0c07fb60u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc64u,2);
goto P_0c07fb62;
P_0c07fb62: /* original 3430, guest PC 0x0c07fb62 */
if(!s->budget--) { s->failed_pc=0x0c07fb62u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c07fb64;
P_0c07fb64: /* original 0029, guest PC 0x0c07fb64 */
if(!s->budget--) { s->failed_pc=0x0c07fb64u; return 0; }
r[0]=r[17]&1u;
goto P_0c07fb66;
P_0c07fb66: /* original 201b, guest PC 0x0c07fb66 */
if(!s->budget--) { s->failed_pc=0x0c07fb66u; return 0; }
r[0]|=r[1];
goto P_0c07fb68;
P_0c07fb68: /* original 2008, guest PC 0x0c07fb68 */
if(!s->budget--) { s->failed_pc=0x0c07fb68u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c07fb6a;
P_0c07fb6a: /* original 892c, guest PC 0x0c07fb6a */
if(!s->budget--) { s->failed_pc=0x0c07fb6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07fbc6; }
goto P_0c07fb6c;
P_0c07fb6c: /* original 907b, guest PC 0x0c07fb6c */
if(!s->budget--) { s->failed_pc=0x0c07fb6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc66u,2);
goto P_0c07fb6e;
P_0c07fb6e: /* original 63f3, guest PC 0x0c07fb6e */
if(!s->budget--) { s->failed_pc=0x0c07fb6eu; return 0; }
r[3]=r[15];
goto P_0c07fb70;
P_0c07fb70: /* original 7314, guest PC 0x0c07fb70 */
if(!s->budget--) { s->failed_pc=0x0c07fb70u; return 0; }
r[3]+=0x00000014u;
goto P_0c07fb72;
P_0c07fb72: /* original 04dc, guest PC 0x0c07fb72 */
if(!s->budget--) { s->failed_pc=0x0c07fb72u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07fb74;
P_0c07fb74: /* original 2fc2, guest PC 0x0c07fb74 */
if(!s->budget--) { s->failed_pc=0x0c07fb74u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c07fb76;
P_0c07fb76: /* original 4408, guest PC 0x0c07fb76 */
if(!s->budget--) { s->failed_pc=0x0c07fb76u; return 0; }
r[4]<<=2;
goto P_0c07fb78;
P_0c07fb78: /* original 1f32, guest PC 0x0c07fb78 */
if(!s->budget--) { s->failed_pc=0x0c07fb78u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07fb7a;
P_0c07fb7a: /* original 5df3, guest PC 0x0c07fb7a */
if(!s->budget--) { s->failed_pc=0x0c07fb7au; return 0; }
r[13]=read(ram,r[15]+12,4);
goto P_0c07fb7c;
P_0c07fb7c: /* original 644e, guest PC 0x0c07fb7c */
if(!s->budget--) { s->failed_pc=0x0c07fb7cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c07fb7e;
P_0c07fb7e: /* original 3d4c, guest PC 0x0c07fb7e */
if(!s->budget--) { s->failed_pc=0x0c07fb7eu; return 0; }
r[13]+=r[4];
goto P_0c07fb80;
P_0c07fb80: /* original 480b, guest PC 0x0c07fb80 */
if(!s->budget--) { s->failed_pc=0x0c07fb80u; return 0; }
target=r[8];
r[16]=code_base|0x0c07fb84u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07fb84u) { target=s->pc; goto dispatch; }
goto P_0c07fb84;
P_0c07fb82: /* original 64d3, guest PC 0x0c07fb82 */
if(!s->budget--) { s->failed_pc=0x0c07fb82u; return 0; }
r[4]=r[13];
goto P_0c07fb84;
P_0c07fb84: /* original 55f2, guest PC 0x0c07fb84 */
if(!s->budget--) { s->failed_pc=0x0c07fb84u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c07fb86;
P_0c07fb86: /* original 640c, guest PC 0x0c07fb86 */
if(!s->budget--) { s->failed_pc=0x0c07fb86u; return 0; }
r[4]=r[0]&255u;
goto P_0c07fb88;
P_0c07fb88: /* original 7501, guest PC 0x0c07fb88 */
if(!s->budget--) { s->failed_pc=0x0c07fb88u; return 0; }
r[5]+=0x00000001u;
goto P_0c07fb8a;
P_0c07fb8a: /* original 1f52, guest PC 0x0c07fb8a */
if(!s->budget--) { s->failed_pc=0x0c07fb8au; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c07fb8c;
P_0c07fb8c: /* original 75ff, guest PC 0x0c07fb8c */
if(!s->budget--) { s->failed_pc=0x0c07fb8cu; return 0; }
r[5]+=0xffffffffu;
goto P_0c07fb8e;
P_0c07fb8e: /* original 6550, guest PC 0x0c07fb8e */
if(!s->budget--) { s->failed_pc=0x0c07fb8eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c07fb90;
P_0c07fb90: /* original 3450, guest PC 0x0c07fb90 */
if(!s->budget--) { s->failed_pc=0x0c07fb90u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c07fb92;
P_0c07fb92: /* original 8b18, guest PC 0x0c07fb92 */
if(!s->budget--) { s->failed_pc=0x0c07fb92u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07fbc6; }
goto P_0c07fb94;
P_0c07fb94: /* original 63f2, guest PC 0x0c07fb94 */
if(!s->budget--) { s->failed_pc=0x0c07fb94u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07fb96;
P_0c07fb96: /* original e203, guest PC 0x0c07fb96 */
if(!s->budget--) { s->failed_pc=0x0c07fb96u; return 0; }
r[2]=0x00000003u;
goto P_0c07fb98;
P_0c07fb98: /* original 7301, guest PC 0x0c07fb98 */
if(!s->budget--) { s->failed_pc=0x0c07fb98u; return 0; }
r[3]+=0x00000001u;
goto P_0c07fb9a;
P_0c07fb9a: /* original 3323, guest PC 0x0c07fb9a */
if(!s->budget--) { s->failed_pc=0x0c07fb9au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c07fb9c;
P_0c07fb9c: /* original 2f32, guest PC 0x0c07fb9c */
if(!s->budget--) { s->failed_pc=0x0c07fb9cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07fb9e;
P_0c07fb9e: /* original 8fef, guest PC 0x0c07fb9e */
if(!s->budget--) { s->failed_pc=0x0c07fb9eu; return 0; }
cond=r[17]&1u;
r[13]+=0x00000001u;
if(!cond) { goto P_0c07fb80; }
goto P_0c07fba2;
P_0c07fba0: /* original 7d01, guest PC 0x0c07fba0 */
if(!s->budget--) { s->failed_pc=0x0c07fba0u; return 0; }
r[13]+=0x00000001u;
goto P_0c07fba2;
P_0c07fba2: /* original 2fc6, guest PC 0x0c07fba2 */
if(!s->budget--) { s->failed_pc=0x0c07fba2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07fba4;
P_0c07fba4: /* original e700, guest PC 0x0c07fba4 */
if(!s->budget--) { s->failed_pc=0x0c07fba4u; return 0; }
r[7]=0x00000000u;
goto P_0c07fba6;
P_0c07fba6: /* original 955f, guest PC 0x0c07fba6 */
if(!s->budget--) { s->failed_pc=0x0c07fba6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc68u,2);
goto P_0c07fba8;
P_0c07fba8: /* original 945f, guest PC 0x0c07fba8 */
if(!s->budget--) { s->failed_pc=0x0c07fba8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc6au,2);
goto P_0c07fbaa;
P_0c07fbaa: /* original 4b0b, guest PC 0x0c07fbaa */
if(!s->budget--) { s->failed_pc=0x0c07fbaau; return 0; }
target=r[11];
r[16]=code_base|0x0c07fbaeu;
r[6]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07fbaeu) { target=s->pc; goto dispatch; }
goto P_0c07fbae;
P_0c07fbac: /* original 66e3, guest PC 0x0c07fbac */
if(!s->budget--) { s->failed_pc=0x0c07fbacu; return 0; }
r[6]=r[14];
goto P_0c07fbae;
P_0c07fbae: /* original 7f04, guest PC 0x0c07fbae */
if(!s->budget--) { s->failed_pc=0x0c07fbaeu; return 0; }
r[15]+=0x00000004u;
goto P_0c07fbb0;
P_0c07fbb0: /* original 9d5c, guest PC 0x0c07fbb0 */
if(!s->budget--) { s->failed_pc=0x0c07fbb0u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc6cu,2);
goto P_0c07fbb2;
P_0c07fbb2: /* original 53f1, guest PC 0x0c07fbb2 */
if(!s->budget--) { s->failed_pc=0x0c07fbb2u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07fbb4;
P_0c07fbb4: /* original 2338, guest PC 0x0c07fbb4 */
if(!s->budget--) { s->failed_pc=0x0c07fbb4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07fbb6;
P_0c07fbb6: /* original 8900, guest PC 0x0c07fbb6 */
if(!s->budget--) { s->failed_pc=0x0c07fbb6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07fbba; }
goto P_0c07fbb8;
P_0c07fbb8: /* original 9d59, guest PC 0x0c07fbb8 */
if(!s->budget--) { s->failed_pc=0x0c07fbb8u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc6eu,2);
goto P_0c07fbba;
P_0c07fbba: /* original 9759, guest PC 0x0c07fbba */
if(!s->budget--) { s->failed_pc=0x0c07fbbau; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc70u,2);
goto P_0c07fbbc;
P_0c07fbbc: /* original 65d3, guest PC 0x0c07fbbc */
if(!s->budget--) { s->failed_pc=0x0c07fbbcu; return 0; }
r[5]=r[13];
goto P_0c07fbbe;
P_0c07fbbe: /* original e600, guest PC 0x0c07fbbe */
if(!s->budget--) { s->failed_pc=0x0c07fbbeu; return 0; }
r[6]=0x00000000u;
goto P_0c07fbc0;
P_0c07fbc0: /* original 4a0b, guest PC 0x0c07fbc0 */
if(!s->budget--) { s->failed_pc=0x0c07fbc0u; return 0; }
target=r[10];
r[16]=code_base|0x0c07fbc4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07fbc4u) { target=s->pc; goto dispatch; }
goto P_0c07fbc4;
P_0c07fbc2: /* original 64e3, guest PC 0x0c07fbc2 */
if(!s->budget--) { s->failed_pc=0x0c07fbc2u; return 0; }
r[4]=r[14];
goto P_0c07fbc4;
P_0c07fbc4: /* original 6903, guest PC 0x0c07fbc4 */
if(!s->budget--) { s->failed_pc=0x0c07fbc4u; return 0; }
r[9]=r[0];
goto P_0c07fbc6;
P_0c07fbc6: /* original d32d, guest PC 0x0c07fbc6 */
if(!s->budget--) { s->failed_pc=0x0c07fbc6u; return 0; }
r[3]=read(ram,0x0c07fc7cu,4);
goto P_0c07fbc8;
P_0c07fbc8: /* original 6593, guest PC 0x0c07fbc8 */
if(!s->budget--) { s->failed_pc=0x0c07fbc8u; return 0; }
r[5]=r[9];
goto P_0c07fbca;
P_0c07fbca: /* original 430b, guest PC 0x0c07fbca */
if(!s->budget--) { s->failed_pc=0x0c07fbcau; return 0; }
target=r[3];
r[16]=code_base|0x0c07fbceu;
r[4]=read(ram,r[15]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07fbceu) { target=s->pc; goto dispatch; }
goto P_0c07fbce;
P_0c07fbcc: /* original 54f4, guest PC 0x0c07fbcc */
if(!s->budget--) { s->failed_pc=0x0c07fbccu; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c07fbce;
P_0c07fbce: /* original 7f18, guest PC 0x0c07fbce */
if(!s->budget--) { s->failed_pc=0x0c07fbceu; return 0; }
r[15]+=0x00000018u;
goto P_0c07fbd0;
P_0c07fbd0: /* original 4f16, guest PC 0x0c07fbd0 */
if(!s->budget--) { s->failed_pc=0x0c07fbd0u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c07fbd2;
P_0c07fbd2: /* original 4f26, guest PC 0x0c07fbd2 */
if(!s->budget--) { s->failed_pc=0x0c07fbd2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07fbd4;
P_0c07fbd4: /* original 68f6, guest PC 0x0c07fbd4 */
if(!s->budget--) { s->failed_pc=0x0c07fbd4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c07fbd6;
P_0c07fbd6: /* original 69f6, guest PC 0x0c07fbd6 */
if(!s->budget--) { s->failed_pc=0x0c07fbd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07fbd8;
P_0c07fbd8: /* original 6af6, guest PC 0x0c07fbd8 */
if(!s->budget--) { s->failed_pc=0x0c07fbd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07fbda;
P_0c07fbda: /* original 6bf6, guest PC 0x0c07fbda */
if(!s->budget--) { s->failed_pc=0x0c07fbdau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07fbdc;
P_0c07fbdc: /* original 6cf6, guest PC 0x0c07fbdc */
if(!s->budget--) { s->failed_pc=0x0c07fbdcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07fbde;
P_0c07fbde: /* original 6df6, guest PC 0x0c07fbde */
if(!s->budget--) { s->failed_pc=0x0c07fbdeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07fbe0;
P_0c07fbe0: /* original 000b, guest PC 0x0c07fbe0 */
if(!s->budget--) { s->failed_pc=0x0c07fbe0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07fbe2: /* original 6ef6, guest PC 0x0c07fbe2 */
if(!s->budget--) { s->failed_pc=0x0c07fbe2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07fbe4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07fbe4u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
