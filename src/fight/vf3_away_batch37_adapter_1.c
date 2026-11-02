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
int vf3_away_batch37_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06b6dcu: goto P_0c06b6dc;
case 0x0c06b6deu: goto P_0c06b6de;
case 0x0c06b6e0u: goto P_0c06b6e0;
case 0x0c06b6e2u: goto P_0c06b6e2;
case 0x0c06b6e4u: goto P_0c06b6e4;
case 0x0c06b6e6u: goto P_0c06b6e6;
case 0x0c06b6e8u: goto P_0c06b6e8;
case 0x0c06b6eau: goto P_0c06b6ea;
case 0x0c06b6ecu: goto P_0c06b6ec;
case 0x0c06b6eeu: goto P_0c06b6ee;
case 0x0c06b6f0u: goto P_0c06b6f0;
case 0x0c06b6f2u: goto P_0c06b6f2;
case 0x0c06b6f4u: goto P_0c06b6f4;
case 0x0c06b6f6u: goto P_0c06b6f6;
case 0x0c06b6f8u: goto P_0c06b6f8;
case 0x0c06b6fau: goto P_0c06b6fa;
case 0x0c06b6fcu: goto P_0c06b6fc;
case 0x0c06b6feu: goto P_0c06b6fe;
case 0x0c06b700u: goto P_0c06b700;
case 0x0c06b702u: goto P_0c06b702;
case 0x0c06b704u: goto P_0c06b704;
case 0x0c06b706u: goto P_0c06b706;
case 0x0c06b708u: goto P_0c06b708;
case 0x0c06b70au: goto P_0c06b70a;
case 0x0c06b70cu: goto P_0c06b70c;
case 0x0c06b70eu: goto P_0c06b70e;
case 0x0c06b710u: goto P_0c06b710;
case 0x0c06b712u: goto P_0c06b712;
case 0x0c06b714u: goto P_0c06b714;
case 0x0c06b716u: goto P_0c06b716;
case 0x0c06b718u: goto P_0c06b718;
case 0x0c06b71au: goto P_0c06b71a;
case 0x0c06b71cu: goto P_0c06b71c;
case 0x0c06b71eu: goto P_0c06b71e;
case 0x0c06b720u: goto P_0c06b720;
case 0x0c06b722u: goto P_0c06b722;
case 0x0c06b724u: goto P_0c06b724;
case 0x0c06b726u: goto P_0c06b726;
case 0x0c06b728u: goto P_0c06b728;
case 0x0c06b72au: goto P_0c06b72a;
case 0x0c06b72cu: goto P_0c06b72c;
case 0x0c06b72eu: goto P_0c06b72e;
case 0x0c06b730u: goto P_0c06b730;
case 0x0c06b732u: goto P_0c06b732;
case 0x0c06b734u: goto P_0c06b734;
case 0x0c06b736u: goto P_0c06b736;
case 0x0c06b738u: goto P_0c06b738;
case 0x0c06b73au: goto P_0c06b73a;
case 0x0c06b73cu: goto P_0c06b73c;
case 0x0c06b758u: goto P_0c06b758;
case 0x0c06b75au: goto P_0c06b75a;
case 0x0c06b75cu: goto P_0c06b75c;
case 0x0c06b75eu: goto P_0c06b75e;
case 0x0c06b760u: goto P_0c06b760;
case 0x0c06b762u: goto P_0c06b762;
case 0x0c06b764u: goto P_0c06b764;
case 0x0c06b766u: goto P_0c06b766;
case 0x0c06b768u: goto P_0c06b768;
case 0x0c06b76au: goto P_0c06b76a;
case 0x0c06b76cu: goto P_0c06b76c;
case 0x0c06b76eu: goto P_0c06b76e;
case 0x0c06b770u: goto P_0c06b770;
case 0x0c06b772u: goto P_0c06b772;
case 0x0c06b774u: goto P_0c06b774;
case 0x0c06b776u: goto P_0c06b776;
case 0x0c06b778u: goto P_0c06b778;
case 0x0c06b77au: goto P_0c06b77a;
case 0x0c06b77cu: goto P_0c06b77c;
case 0x0c06b77eu: goto P_0c06b77e;
case 0x0c06b780u: goto P_0c06b780;
case 0x0c06b782u: goto P_0c06b782;
case 0x0c06b784u: goto P_0c06b784;
case 0x0c06b786u: goto P_0c06b786;
case 0x0c06b788u: goto P_0c06b788;
case 0x0c06b78au: goto P_0c06b78a;
case 0x0c06b78cu: goto P_0c06b78c;
case 0x0c06b78eu: goto P_0c06b78e;
case 0x0c06b790u: goto P_0c06b790;
case 0x0c06b792u: goto P_0c06b792;
case 0x0c06b794u: goto P_0c06b794;
case 0x0c06b796u: goto P_0c06b796;
case 0x0c06b798u: goto P_0c06b798;
case 0x0c06b79au: goto P_0c06b79a;
case 0x0c06b79cu: goto P_0c06b79c;
case 0x0c06b79eu: goto P_0c06b79e;
case 0x0c06b7a0u: goto P_0c06b7a0;
case 0x0c06b7a2u: goto P_0c06b7a2;
case 0x0c06b7a4u: goto P_0c06b7a4;
case 0x0c06b7a6u: goto P_0c06b7a6;
case 0x0c06b7a8u: goto P_0c06b7a8;
case 0x0c06b7aau: goto P_0c06b7aa;
case 0x0c06b7acu: goto P_0c06b7ac;
case 0x0c06b7aeu: goto P_0c06b7ae;
case 0x0c06b7b0u: goto P_0c06b7b0;
case 0x0c06b7b2u: goto P_0c06b7b2;
case 0x0c06b7b4u: goto P_0c06b7b4;
case 0x0c06b7b6u: goto P_0c06b7b6;
case 0x0c06b7b8u: goto P_0c06b7b8;
case 0x0c06b7bau: goto P_0c06b7ba;
case 0x0c06b7bcu: goto P_0c06b7bc;
case 0x0c06b7beu: goto P_0c06b7be;
case 0x0c06b7c0u: goto P_0c06b7c0;
case 0x0c06b7c2u: goto P_0c06b7c2;
case 0x0c06b7c4u: goto P_0c06b7c4;
case 0x0c06b7c6u: goto P_0c06b7c6;
case 0x0c06b7c8u: goto P_0c06b7c8;
case 0x0c06b7cau: goto P_0c06b7ca;
case 0x0c06b7ccu: goto P_0c06b7cc;
case 0x0c06b7ceu: goto P_0c06b7ce;
case 0x0c06b7d0u: goto P_0c06b7d0;
case 0x0c06b7d2u: goto P_0c06b7d2;
case 0x0c06b7d4u: goto P_0c06b7d4;
case 0x0c06b7d6u: goto P_0c06b7d6;
case 0x0c06b7d8u: goto P_0c06b7d8;
case 0x0c06b7dau: goto P_0c06b7da;
case 0x0c06b7dcu: goto P_0c06b7dc;
case 0x0c06b7deu: goto P_0c06b7de;
case 0x0c06b7e0u: goto P_0c06b7e0;
case 0x0c06b7e2u: goto P_0c06b7e2;
case 0x0c06b7e4u: goto P_0c06b7e4;
case 0x0c06b7e6u: goto P_0c06b7e6;
case 0x0c06b7e8u: goto P_0c06b7e8;
case 0x0c06b7eau: goto P_0c06b7ea;
case 0x0c06b7ecu: goto P_0c06b7ec;
case 0x0c06b7eeu: goto P_0c06b7ee;
case 0x0c06b7f0u: goto P_0c06b7f0;
case 0x0c06b7f2u: goto P_0c06b7f2;
case 0x0c06b7f4u: goto P_0c06b7f4;
case 0x0c06b7f6u: goto P_0c06b7f6;
case 0x0c06b7f8u: goto P_0c06b7f8;
case 0x0c06b7fau: goto P_0c06b7fa;
case 0x0c06b7fcu: goto P_0c06b7fc;
case 0x0c06b7feu: goto P_0c06b7fe;
case 0x0c06b800u: goto P_0c06b800;
case 0x0c06b802u: goto P_0c06b802;
case 0x0c06b804u: goto P_0c06b804;
case 0x0c06b806u: goto P_0c06b806;
case 0x0c06b808u: goto P_0c06b808;
case 0x0c06b80au: goto P_0c06b80a;
case 0x0c06b80cu: goto P_0c06b80c;
case 0x0c06b80eu: goto P_0c06b80e;
case 0x0c06b810u: goto P_0c06b810;
case 0x0c06b812u: goto P_0c06b812;
case 0x0c06b814u: goto P_0c06b814;
case 0x0c06b816u: goto P_0c06b816;
case 0x0c06b818u: goto P_0c06b818;
case 0x0c06b81au: goto P_0c06b81a;
case 0x0c06b81cu: goto P_0c06b81c;
case 0x0c06b81eu: goto P_0c06b81e;
case 0x0c06b820u: goto P_0c06b820;
case 0x0c06b822u: goto P_0c06b822;
case 0x0c06b824u: goto P_0c06b824;
case 0x0c06b826u: goto P_0c06b826;
case 0x0c06b828u: goto P_0c06b828;
case 0x0c06b82au: goto P_0c06b82a;
case 0x0c06b82cu: goto P_0c06b82c;
case 0x0c06b82eu: goto P_0c06b82e;
case 0x0c06b830u: goto P_0c06b830;
case 0x0c06b832u: goto P_0c06b832;
case 0x0c06b834u: goto P_0c06b834;
case 0x0c06b836u: goto P_0c06b836;
case 0x0c06b838u: goto P_0c06b838;
case 0x0c06b83au: goto P_0c06b83a;
case 0x0c06b83cu: goto P_0c06b83c;
case 0x0c06b83eu: goto P_0c06b83e;
case 0x0c06b840u: goto P_0c06b840;
case 0x0c06b842u: goto P_0c06b842;
case 0x0c06b844u: goto P_0c06b844;
case 0x0c06b846u: goto P_0c06b846;
case 0x0c06b848u: goto P_0c06b848;
case 0x0c06b84au: goto P_0c06b84a;
case 0x0c06b868u: goto P_0c06b868;
case 0x0c06b86au: goto P_0c06b86a;
case 0x0c06b86cu: goto P_0c06b86c;
case 0x0c06b86eu: goto P_0c06b86e;
case 0x0c06b870u: goto P_0c06b870;
case 0x0c06b872u: goto P_0c06b872;
case 0x0c06b874u: goto P_0c06b874;
case 0x0c06b876u: goto P_0c06b876;
case 0x0c06b878u: goto P_0c06b878;
case 0x0c06b87au: goto P_0c06b87a;
case 0x0c06b87cu: goto P_0c06b87c;
case 0x0c06b87eu: goto P_0c06b87e;
case 0x0c06b880u: goto P_0c06b880;
case 0x0c06b882u: goto P_0c06b882;
case 0x0c06b884u: goto P_0c06b884;
case 0x0c06b886u: goto P_0c06b886;
case 0x0c06b888u: goto P_0c06b888;
case 0x0c06b88au: goto P_0c06b88a;
case 0x0c06b88cu: goto P_0c06b88c;
case 0x0c06b88eu: goto P_0c06b88e;
case 0x0c06b890u: goto P_0c06b890;
case 0x0c06b892u: goto P_0c06b892;
case 0x0c06b894u: goto P_0c06b894;
case 0x0c06b896u: goto P_0c06b896;
case 0x0c06b898u: goto P_0c06b898;
case 0x0c06b89au: goto P_0c06b89a;
case 0x0c06b89cu: goto P_0c06b89c;
case 0x0c06b89eu: goto P_0c06b89e;
case 0x0c06b8a0u: goto P_0c06b8a0;
case 0x0c06b8a2u: goto P_0c06b8a2;
case 0x0c06b8a4u: goto P_0c06b8a4;
case 0x0c06b8a6u: goto P_0c06b8a6;
case 0x0c06b8a8u: goto P_0c06b8a8;
case 0x0c06b8aau: goto P_0c06b8aa;
case 0x0c06b8acu: goto P_0c06b8ac;
case 0x0c06b8aeu: goto P_0c06b8ae;
case 0x0c06b8b0u: goto P_0c06b8b0;
case 0x0c06b8b2u: goto P_0c06b8b2;
case 0x0c06b8b4u: goto P_0c06b8b4;
case 0x0c06b8b6u: goto P_0c06b8b6;
case 0x0c06b8b8u: goto P_0c06b8b8;
case 0x0c06b8bau: goto P_0c06b8ba;
case 0x0c06b8bcu: goto P_0c06b8bc;
case 0x0c06b8beu: goto P_0c06b8be;
case 0x0c06b8c0u: goto P_0c06b8c0;
case 0x0c06b8c2u: goto P_0c06b8c2;
case 0x0c06b8c4u: goto P_0c06b8c4;
case 0x0c06b8c6u: goto P_0c06b8c6;
case 0x0c06b8c8u: goto P_0c06b8c8;
case 0x0c06b8cau: goto P_0c06b8ca;
case 0x0c06b8ccu: goto P_0c06b8cc;
case 0x0c06b8ceu: goto P_0c06b8ce;
case 0x0c06b8d0u: goto P_0c06b8d0;
case 0x0c06b8d2u: goto P_0c06b8d2;
case 0x0c06b8d4u: goto P_0c06b8d4;
case 0x0c06b8d6u: goto P_0c06b8d6;
case 0x0c06b8d8u: goto P_0c06b8d8;
case 0x0c06b8dau: goto P_0c06b8da;
case 0x0c06b8dcu: goto P_0c06b8dc;
case 0x0c06b8deu: goto P_0c06b8de;
case 0x0c06b8e0u: goto P_0c06b8e0;
case 0x0c06b8e2u: goto P_0c06b8e2;
case 0x0c06b8e4u: goto P_0c06b8e4;
case 0x0c06b8e6u: goto P_0c06b8e6;
case 0x0c06b8e8u: goto P_0c06b8e8;
case 0x0c06b8eau: goto P_0c06b8ea;
case 0x0c06b8ecu: goto P_0c06b8ec;
case 0x0c06b8eeu: goto P_0c06b8ee;
case 0x0c06b8f0u: goto P_0c06b8f0;
case 0x0c06b8f2u: goto P_0c06b8f2;
case 0x0c06b8f4u: goto P_0c06b8f4;
case 0x0c06b8f6u: goto P_0c06b8f6;
case 0x0c06b8f8u: goto P_0c06b8f8;
case 0x0c06b8fau: goto P_0c06b8fa;
case 0x0c06b8fcu: goto P_0c06b8fc;
case 0x0c06b8feu: goto P_0c06b8fe;
case 0x0c06b900u: goto P_0c06b900;
case 0x0c06b902u: goto P_0c06b902;
case 0x0c06b904u: goto P_0c06b904;
case 0x0c06b906u: goto P_0c06b906;
case 0x0c06b908u: goto P_0c06b908;
case 0x0c06b90au: goto P_0c06b90a;
case 0x0c06b90cu: goto P_0c06b90c;
case 0x0c06b90eu: goto P_0c06b90e;
case 0x0c06b910u: goto P_0c06b910;
case 0x0c06b912u: goto P_0c06b912;
case 0x0c06b914u: goto P_0c06b914;
case 0x0c06b916u: goto P_0c06b916;
case 0x0c06b918u: goto P_0c06b918;
case 0x0c06b91au: goto P_0c06b91a;
case 0x0c06b91cu: goto P_0c06b91c;
case 0x0c06b91eu: goto P_0c06b91e;
case 0x0c06b920u: goto P_0c06b920;
case 0x0c06b922u: goto P_0c06b922;
case 0x0c06b924u: goto P_0c06b924;
case 0x0c06b926u: goto P_0c06b926;
case 0x0c06b928u: goto P_0c06b928;
case 0x0c06b92au: goto P_0c06b92a;
case 0x0c06b92cu: goto P_0c06b92c;
case 0x0c06b92eu: goto P_0c06b92e;
case 0x0c06b930u: goto P_0c06b930;
case 0x0c06b932u: goto P_0c06b932;
case 0x0c06b934u: goto P_0c06b934;
case 0x0c06b936u: goto P_0c06b936;
case 0x0c06b938u: goto P_0c06b938;
case 0x0c06b93au: goto P_0c06b93a;
case 0x0c06b93cu: goto P_0c06b93c;
case 0x0c06b93eu: goto P_0c06b93e;
case 0x0c06b940u: goto P_0c06b940;
case 0x0c06b942u: goto P_0c06b942;
case 0x0c06b944u: goto P_0c06b944;
case 0x0c06b946u: goto P_0c06b946;
case 0x0c06b948u: goto P_0c06b948;
case 0x0c06b94au: goto P_0c06b94a;
case 0x0c06b94cu: goto P_0c06b94c;
case 0x0c06b94eu: goto P_0c06b94e;
case 0x0c06b950u: goto P_0c06b950;
case 0x0c06b952u: goto P_0c06b952;
case 0x0c06b954u: goto P_0c06b954;
case 0x0c06b956u: goto P_0c06b956;
case 0x0c06b958u: goto P_0c06b958;
case 0x0c06b95au: goto P_0c06b95a;
case 0x0c06b95cu: goto P_0c06b95c;
case 0x0c06b984u: goto P_0c06b984;
case 0x0c06b986u: goto P_0c06b986;
case 0x0c06b988u: goto P_0c06b988;
case 0x0c06b98au: goto P_0c06b98a;
case 0x0c06b98cu: goto P_0c06b98c;
case 0x0c06b98eu: goto P_0c06b98e;
case 0x0c06b990u: goto P_0c06b990;
case 0x0c06b992u: goto P_0c06b992;
case 0x0c06b994u: goto P_0c06b994;
case 0x0c06b996u: goto P_0c06b996;
case 0x0c06b998u: goto P_0c06b998;
case 0x0c06b99au: goto P_0c06b99a;
case 0x0c06b99cu: goto P_0c06b99c;
case 0x0c06b99eu: goto P_0c06b99e;
case 0x0c06b9a0u: goto P_0c06b9a0;
case 0x0c06b9a2u: goto P_0c06b9a2;
case 0x0c06b9a4u: goto P_0c06b9a4;
case 0x0c06b9a6u: goto P_0c06b9a6;
case 0x0c06b9a8u: goto P_0c06b9a8;
case 0x0c06b9aau: goto P_0c06b9aa;
case 0x0c06b9acu: goto P_0c06b9ac;
case 0x0c06b9aeu: goto P_0c06b9ae;
case 0x0c06b9b0u: goto P_0c06b9b0;
case 0x0c06b9b2u: goto P_0c06b9b2;
case 0x0c06b9b4u: goto P_0c06b9b4;
case 0x0c06b9b6u: goto P_0c06b9b6;
case 0x0c06b9b8u: goto P_0c06b9b8;
case 0x0c06b9bau: goto P_0c06b9ba;
case 0x0c06b9bcu: goto P_0c06b9bc;
case 0x0c06b9beu: goto P_0c06b9be;
case 0x0c06b9c0u: goto P_0c06b9c0;
case 0x0c06b9c2u: goto P_0c06b9c2;
case 0x0c06b9c4u: goto P_0c06b9c4;
case 0x0c06b9c6u: goto P_0c06b9c6;
case 0x0c06b9c8u: goto P_0c06b9c8;
case 0x0c06b9cau: goto P_0c06b9ca;
case 0x0c06b9ccu: goto P_0c06b9cc;
case 0x0c06b9ceu: goto P_0c06b9ce;
case 0x0c06b9d0u: goto P_0c06b9d0;
case 0x0c06b9d2u: goto P_0c06b9d2;
case 0x0c06b9d4u: goto P_0c06b9d4;
case 0x0c06b9d6u: goto P_0c06b9d6;
case 0x0c06b9d8u: goto P_0c06b9d8;
case 0x0c06b9dau: goto P_0c06b9da;
case 0x0c06b9dcu: goto P_0c06b9dc;
case 0x0c06b9deu: goto P_0c06b9de;
case 0x0c06b9e0u: goto P_0c06b9e0;
case 0x0c06b9e2u: goto P_0c06b9e2;
case 0x0c06b9e4u: goto P_0c06b9e4;
case 0x0c06b9e6u: goto P_0c06b9e6;
case 0x0c06b9e8u: goto P_0c06b9e8;
case 0x0c06b9eau: goto P_0c06b9ea;
case 0x0c06b9ecu: goto P_0c06b9ec;
case 0x0c06b9eeu: goto P_0c06b9ee;
case 0x0c06b9f0u: goto P_0c06b9f0;
case 0x0c06b9f2u: goto P_0c06b9f2;
case 0x0c06b9f4u: goto P_0c06b9f4;
case 0x0c06b9f6u: goto P_0c06b9f6;
case 0x0c06b9f8u: goto P_0c06b9f8;
case 0x0c06b9fau: goto P_0c06b9fa;
case 0x0c06b9fcu: goto P_0c06b9fc;
case 0x0c06b9feu: goto P_0c06b9fe;
case 0x0c06ba00u: goto P_0c06ba00;
case 0x0c06ba02u: goto P_0c06ba02;
case 0x0c06ba04u: goto P_0c06ba04;
case 0x0c06ba06u: goto P_0c06ba06;
case 0x0c06ba08u: goto P_0c06ba08;
case 0x0c06ba0au: goto P_0c06ba0a;
case 0x0c06ba0cu: goto P_0c06ba0c;
case 0x0c06ba0eu: goto P_0c06ba0e;
case 0x0c06ba10u: goto P_0c06ba10;
case 0x0c06ba12u: goto P_0c06ba12;
case 0x0c06ba14u: goto P_0c06ba14;
case 0x0c06ba16u: goto P_0c06ba16;
case 0x0c06ba18u: goto P_0c06ba18;
case 0x0c06ba1au: goto P_0c06ba1a;
case 0x0c06ba1cu: goto P_0c06ba1c;
case 0x0c06ba1eu: goto P_0c06ba1e;
case 0x0c06ba20u: goto P_0c06ba20;
case 0x0c06ba22u: goto P_0c06ba22;
case 0x0c06ba24u: goto P_0c06ba24;
case 0x0c06ba26u: goto P_0c06ba26;
case 0x0c06ba28u: goto P_0c06ba28;
case 0x0c06ba2au: goto P_0c06ba2a;
case 0x0c06ba2cu: goto P_0c06ba2c;
case 0x0c06ba2eu: goto P_0c06ba2e;
case 0x0c06ba30u: goto P_0c06ba30;
case 0x0c06ba32u: goto P_0c06ba32;
case 0x0c06ba34u: goto P_0c06ba34;
case 0x0c06ba36u: goto P_0c06ba36;
case 0x0c06ba38u: goto P_0c06ba38;
case 0x0c06ba3au: goto P_0c06ba3a;
case 0x0c06ba3cu: goto P_0c06ba3c;
case 0x0c06ba3eu: goto P_0c06ba3e;
case 0x0c06ba40u: goto P_0c06ba40;
case 0x0c06ba42u: goto P_0c06ba42;
case 0x0c06ba44u: goto P_0c06ba44;
case 0x0c06ba46u: goto P_0c06ba46;
case 0x0c06ba48u: goto P_0c06ba48;
case 0x0c06ba4au: goto P_0c06ba4a;
case 0x0c06ba4cu: goto P_0c06ba4c;
case 0x0c06ba4eu: goto P_0c06ba4e;
case 0x0c06ba50u: goto P_0c06ba50;
case 0x0c06ba52u: goto P_0c06ba52;
case 0x0c06ba54u: goto P_0c06ba54;
case 0x0c06ba56u: goto P_0c06ba56;
case 0x0c06ba58u: goto P_0c06ba58;
case 0x0c06ba5au: goto P_0c06ba5a;
case 0x0c06ba5cu: goto P_0c06ba5c;
case 0x0c06ba5eu: goto P_0c06ba5e;
case 0x0c06ba60u: goto P_0c06ba60;
case 0x0c06ba62u: goto P_0c06ba62;
case 0x0c06ba64u: goto P_0c06ba64;
case 0x0c06ba66u: goto P_0c06ba66;
case 0x0c06ba68u: goto P_0c06ba68;
case 0x0c06ba6au: goto P_0c06ba6a;
case 0x0c06ba6cu: goto P_0c06ba6c;
case 0x0c06ba6eu: goto P_0c06ba6e;
case 0x0c06ba70u: goto P_0c06ba70;
case 0x0c06ba72u: goto P_0c06ba72;
case 0x0c06ba74u: goto P_0c06ba74;
case 0x0c06ba76u: goto P_0c06ba76;
case 0x0c06ba78u: goto P_0c06ba78;
case 0x0c06ba7au: goto P_0c06ba7a;
case 0x0c06ba7cu: goto P_0c06ba7c;
case 0x0c06ba7eu: goto P_0c06ba7e;
case 0x0c06ba80u: goto P_0c06ba80;
case 0x0c06ba82u: goto P_0c06ba82;
case 0x0c06ba9eu: goto P_0c06ba9e;
case 0x0c06baa0u: goto P_0c06baa0;
case 0x0c06baa2u: goto P_0c06baa2;
case 0x0c06baa4u: goto P_0c06baa4;
case 0x0c06baa6u: goto P_0c06baa6;
case 0x0c06baa8u: goto P_0c06baa8;
case 0x0c06baaau: goto P_0c06baaa;
case 0x0c06baacu: goto P_0c06baac;
case 0x0c06baaeu: goto P_0c06baae;
case 0x0c06bab0u: goto P_0c06bab0;
case 0x0c06bab2u: goto P_0c06bab2;
case 0x0c06bab4u: goto P_0c06bab4;
case 0x0c06bab6u: goto P_0c06bab6;
case 0x0c06bab8u: goto P_0c06bab8;
case 0x0c06babau: goto P_0c06baba;
case 0x0c06babcu: goto P_0c06babc;
case 0x0c06babeu: goto P_0c06babe;
case 0x0c06bac0u: goto P_0c06bac0;
case 0x0c06bac2u: goto P_0c06bac2;
case 0x0c06bac4u: goto P_0c06bac4;
case 0x0c06bac6u: goto P_0c06bac6;
case 0x0c06bac8u: goto P_0c06bac8;
case 0x0c06bacau: goto P_0c06baca;
case 0x0c06baccu: goto P_0c06bacc;
case 0x0c06baceu: goto P_0c06bace;
case 0x0c06bad0u: goto P_0c06bad0;
case 0x0c06bad2u: goto P_0c06bad2;
case 0x0c06bad4u: goto P_0c06bad4;
case 0x0c06bad6u: goto P_0c06bad6;
case 0x0c06bad8u: goto P_0c06bad8;
case 0x0c06badau: goto P_0c06bada;
case 0x0c06badcu: goto P_0c06badc;
case 0x0c06badeu: goto P_0c06bade;
case 0x0c06bae0u: goto P_0c06bae0;
case 0x0c06bae2u: goto P_0c06bae2;
case 0x0c06bae4u: goto P_0c06bae4;
case 0x0c06bae6u: goto P_0c06bae6;
case 0x0c06bae8u: goto P_0c06bae8;
case 0x0c06baeau: goto P_0c06baea;
case 0x0c06baecu: goto P_0c06baec;
case 0x0c06baeeu: goto P_0c06baee;
case 0x0c06baf0u: goto P_0c06baf0;
case 0x0c06baf2u: goto P_0c06baf2;
case 0x0c06baf4u: goto P_0c06baf4;
case 0x0c06baf6u: goto P_0c06baf6;
case 0x0c06baf8u: goto P_0c06baf8;
case 0x0c06bafau: goto P_0c06bafa;
case 0x0c06bafcu: goto P_0c06bafc;
case 0x0c06bafeu: goto P_0c06bafe;
case 0x0c06bb00u: goto P_0c06bb00;
case 0x0c06bb02u: goto P_0c06bb02;
case 0x0c06bb04u: goto P_0c06bb04;
case 0x0c06bb06u: goto P_0c06bb06;
case 0x0c06bb08u: goto P_0c06bb08;
case 0x0c06bb0au: goto P_0c06bb0a;
case 0x0c06bb0cu: goto P_0c06bb0c;
case 0x0c06bb0eu: goto P_0c06bb0e;
case 0x0c06bb10u: goto P_0c06bb10;
case 0x0c06bb12u: goto P_0c06bb12;
case 0x0c06bb14u: goto P_0c06bb14;
case 0x0c06bb16u: goto P_0c06bb16;
case 0x0c06bb18u: goto P_0c06bb18;
case 0x0c06bb1au: goto P_0c06bb1a;
case 0x0c06bb1cu: goto P_0c06bb1c;
case 0x0c06bb1eu: goto P_0c06bb1e;
case 0x0c06bb20u: goto P_0c06bb20;
case 0x0c06bb22u: goto P_0c06bb22;
case 0x0c06bb24u: goto P_0c06bb24;
case 0x0c06bb26u: goto P_0c06bb26;
case 0x0c06bb28u: goto P_0c06bb28;
case 0x0c06bb2au: goto P_0c06bb2a;
case 0x0c06bb2cu: goto P_0c06bb2c;
case 0x0c06bb2eu: goto P_0c06bb2e;
case 0x0c06bb30u: goto P_0c06bb30;
case 0x0c06bb32u: goto P_0c06bb32;
case 0x0c06bb34u: goto P_0c06bb34;
case 0x0c06bb36u: goto P_0c06bb36;
case 0x0c06bb38u: goto P_0c06bb38;
case 0x0c06bb3au: goto P_0c06bb3a;
case 0x0c06bb3cu: goto P_0c06bb3c;
case 0x0c06bb3eu: goto P_0c06bb3e;
case 0x0c06bb40u: goto P_0c06bb40;
case 0x0c06bb42u: goto P_0c06bb42;
case 0x0c06bb44u: goto P_0c06bb44;
case 0x0c06bb46u: goto P_0c06bb46;
case 0x0c06bb48u: goto P_0c06bb48;
case 0x0c06bb4au: goto P_0c06bb4a;
case 0x0c06bb4cu: goto P_0c06bb4c;
case 0x0c06bb4eu: goto P_0c06bb4e;
case 0x0c06bb50u: goto P_0c06bb50;
case 0x0c06bb52u: goto P_0c06bb52;
case 0x0c06bb54u: goto P_0c06bb54;
case 0x0c06bb56u: goto P_0c06bb56;
case 0x0c06bb58u: goto P_0c06bb58;
case 0x0c06bb5au: goto P_0c06bb5a;
case 0x0c06bb5cu: goto P_0c06bb5c;
case 0x0c06bb5eu: goto P_0c06bb5e;
case 0x0c06bb60u: goto P_0c06bb60;
case 0x0c06bb62u: goto P_0c06bb62;
case 0x0c06bb64u: goto P_0c06bb64;
case 0x0c06bb66u: goto P_0c06bb66;
case 0x0c06bb68u: goto P_0c06bb68;
case 0x0c06bb6au: goto P_0c06bb6a;
case 0x0c06bb6cu: goto P_0c06bb6c;
case 0x0c06bb6eu: goto P_0c06bb6e;
case 0x0c06bb70u: goto P_0c06bb70;
case 0x0c06bb72u: goto P_0c06bb72;
case 0x0c06bb74u: goto P_0c06bb74;
case 0x0c06bb76u: goto P_0c06bb76;
case 0x0c06bb78u: goto P_0c06bb78;
case 0x0c06bb7au: goto P_0c06bb7a;
case 0x0c06bb7cu: goto P_0c06bb7c;
case 0x0c06bb7eu: goto P_0c06bb7e;
case 0x0c06bb80u: goto P_0c06bb80;
case 0x0c06bb82u: goto P_0c06bb82;
case 0x0c06bb84u: goto P_0c06bb84;
case 0x0c06bb86u: goto P_0c06bb86;
case 0x0c06bb88u: goto P_0c06bb88;
case 0x0c06bb8au: goto P_0c06bb8a;
case 0x0c06bb8cu: goto P_0c06bb8c;
case 0x0c06bb8eu: goto P_0c06bb8e;
case 0x0c06bb90u: goto P_0c06bb90;
case 0x0c06bb92u: goto P_0c06bb92;
case 0x0c06bb94u: goto P_0c06bb94;
case 0x0c06bb96u: goto P_0c06bb96;
case 0x0c06bb98u: goto P_0c06bb98;
case 0x0c06bb9au: goto P_0c06bb9a;
case 0x0c06bb9cu: goto P_0c06bb9c;
case 0x0c06bb9eu: goto P_0c06bb9e;
case 0x0c06bba0u: goto P_0c06bba0;
case 0x0c06bba2u: goto P_0c06bba2;
case 0x0c06bba4u: goto P_0c06bba4;
case 0x0c06bba6u: goto P_0c06bba6;
case 0x0c06bba8u: goto P_0c06bba8;
case 0x0c06bbaau: goto P_0c06bbaa;
case 0x0c06bbacu: goto P_0c06bbac;
case 0x0c06bbaeu: goto P_0c06bbae;
case 0x0c06bbb0u: goto P_0c06bbb0;
case 0x0c06bbb2u: goto P_0c06bbb2;
case 0x0c06bbb4u: goto P_0c06bbb4;
case 0x0c06bbb6u: goto P_0c06bbb6;
case 0x0c06bbb8u: goto P_0c06bbb8;
case 0x0c06bbbau: goto P_0c06bbba;
case 0x0c06bbbcu: goto P_0c06bbbc;
case 0x0c06bbbeu: goto P_0c06bbbe;
case 0x0c06bbc0u: goto P_0c06bbc0;
case 0x0c06bbc2u: goto P_0c06bbc2;
case 0x0c06bbc4u: goto P_0c06bbc4;
case 0x0c06bbc6u: goto P_0c06bbc6;
case 0x0c06bbc8u: goto P_0c06bbc8;
case 0x0c06bbdcu: goto P_0c06bbdc;
case 0x0c06bbdeu: goto P_0c06bbde;
case 0x0c06bbe0u: goto P_0c06bbe0;
case 0x0c06bbe2u: goto P_0c06bbe2;
case 0x0c06bbe4u: goto P_0c06bbe4;
case 0x0c06bbe6u: goto P_0c06bbe6;
case 0x0c06bbe8u: goto P_0c06bbe8;
case 0x0c06bbeau: goto P_0c06bbea;
case 0x0c06bbecu: goto P_0c06bbec;
case 0x0c06bbeeu: goto P_0c06bbee;
case 0x0c06bbf0u: goto P_0c06bbf0;
case 0x0c06bbf2u: goto P_0c06bbf2;
case 0x0c06bbf4u: goto P_0c06bbf4;
case 0x0c06bbf6u: goto P_0c06bbf6;
case 0x0c06bbf8u: goto P_0c06bbf8;
case 0x0c06bbfau: goto P_0c06bbfa;
case 0x0c06bbfcu: goto P_0c06bbfc;
case 0x0c06bbfeu: goto P_0c06bbfe;
case 0x0c06bc00u: goto P_0c06bc00;
case 0x0c06bc02u: goto P_0c06bc02;
case 0x0c06bc04u: goto P_0c06bc04;
case 0x0c06bc06u: goto P_0c06bc06;
case 0x0c06bc08u: goto P_0c06bc08;
case 0x0c06bc0au: goto P_0c06bc0a;
case 0x0c06bc0cu: goto P_0c06bc0c;
case 0x0c06bc0eu: goto P_0c06bc0e;
case 0x0c06bc10u: goto P_0c06bc10;
case 0x0c06bc12u: goto P_0c06bc12;
case 0x0c06bc14u: goto P_0c06bc14;
case 0x0c06bc16u: goto P_0c06bc16;
case 0x0c06bc18u: goto P_0c06bc18;
case 0x0c06bc1au: goto P_0c06bc1a;
case 0x0c06bc1cu: goto P_0c06bc1c;
case 0x0c06bc1eu: goto P_0c06bc1e;
case 0x0c06bc20u: goto P_0c06bc20;
case 0x0c06bc22u: goto P_0c06bc22;
case 0x0c06bc24u: goto P_0c06bc24;
case 0x0c06bc26u: goto P_0c06bc26;
case 0x0c06bc28u: goto P_0c06bc28;
case 0x0c06bc2au: goto P_0c06bc2a;
case 0x0c06bc2cu: goto P_0c06bc2c;
case 0x0c06bc2eu: goto P_0c06bc2e;
case 0x0c06bc30u: goto P_0c06bc30;
case 0x0c06bc32u: goto P_0c06bc32;
case 0x0c06bc34u: goto P_0c06bc34;
case 0x0c06bc36u: goto P_0c06bc36;
case 0x0c06bc38u: goto P_0c06bc38;
case 0x0c06bc3au: goto P_0c06bc3a;
case 0x0c06bc3cu: goto P_0c06bc3c;
case 0x0c06bc3eu: goto P_0c06bc3e;
case 0x0c06bc40u: goto P_0c06bc40;
case 0x0c06bc42u: goto P_0c06bc42;
case 0x0c06bc44u: goto P_0c06bc44;
case 0x0c06bc46u: goto P_0c06bc46;
case 0x0c06bc48u: goto P_0c06bc48;
case 0x0c06bc4au: goto P_0c06bc4a;
case 0x0c06bc4cu: goto P_0c06bc4c;
case 0x0c06bc4eu: goto P_0c06bc4e;
case 0x0c06bc50u: goto P_0c06bc50;
case 0x0c06bc52u: goto P_0c06bc52;
case 0x0c06bc54u: goto P_0c06bc54;
case 0x0c06bc56u: goto P_0c06bc56;
case 0x0c06bc58u: goto P_0c06bc58;
case 0x0c06bc5au: goto P_0c06bc5a;
case 0x0c06bc5cu: goto P_0c06bc5c;
case 0x0c06bc5eu: goto P_0c06bc5e;
case 0x0c06bc60u: goto P_0c06bc60;
case 0x0c06bc62u: goto P_0c06bc62;
case 0x0c06bc64u: goto P_0c06bc64;
case 0x0c06bc66u: goto P_0c06bc66;
case 0x0c06bc68u: goto P_0c06bc68;
case 0x0c06bc6au: goto P_0c06bc6a;
case 0x0c06bc6cu: goto P_0c06bc6c;
case 0x0c06bc6eu: goto P_0c06bc6e;
case 0x0c06bc70u: goto P_0c06bc70;
case 0x0c06bc72u: goto P_0c06bc72;
case 0x0c06bc74u: goto P_0c06bc74;
case 0x0c06bc76u: goto P_0c06bc76;
case 0x0c06bc78u: goto P_0c06bc78;
case 0x0c06bc7au: goto P_0c06bc7a;
case 0x0c06bc7cu: goto P_0c06bc7c;
case 0x0c06bc7eu: goto P_0c06bc7e;
case 0x0c06bc80u: goto P_0c06bc80;
case 0x0c06bc82u: goto P_0c06bc82;
case 0x0c06bc84u: goto P_0c06bc84;
case 0x0c06bc86u: goto P_0c06bc86;
case 0x0c06bc88u: goto P_0c06bc88;
case 0x0c06bc8au: goto P_0c06bc8a;
case 0x0c06bc8cu: goto P_0c06bc8c;
case 0x0c06bc8eu: goto P_0c06bc8e;
case 0x0c06bc90u: goto P_0c06bc90;
case 0x0c06bc92u: goto P_0c06bc92;
case 0x0c06bc94u: goto P_0c06bc94;
case 0x0c06bc96u: goto P_0c06bc96;
case 0x0c06bc98u: goto P_0c06bc98;
case 0x0c06bc9au: goto P_0c06bc9a;
case 0x0c06bc9cu: goto P_0c06bc9c;
case 0x0c06bc9eu: goto P_0c06bc9e;
case 0x0c06bca0u: goto P_0c06bca0;
case 0x0c06bca2u: goto P_0c06bca2;
case 0x0c06bca4u: goto P_0c06bca4;
case 0x0c06bca6u: goto P_0c06bca6;
case 0x0c06bca8u: goto P_0c06bca8;
case 0x0c06bcaau: goto P_0c06bcaa;
case 0x0c06bcacu: goto P_0c06bcac;
case 0x0c06bcaeu: goto P_0c06bcae;
case 0x0c06bcb0u: goto P_0c06bcb0;
case 0x0c06bcb2u: goto P_0c06bcb2;
case 0x0c06bcb4u: goto P_0c06bcb4;
case 0x0c06bcb6u: goto P_0c06bcb6;
case 0x0c06bcb8u: goto P_0c06bcb8;
case 0x0c06bcbau: goto P_0c06bcba;
case 0x0c06bcbcu: goto P_0c06bcbc;
case 0x0c06bcbeu: goto P_0c06bcbe;
case 0x0c06bcc0u: goto P_0c06bcc0;
case 0x0c06bcc2u: goto P_0c06bcc2;
case 0x0c06bcc4u: goto P_0c06bcc4;
case 0x0c06bcc6u: goto P_0c06bcc6;
case 0x0c06bcc8u: goto P_0c06bcc8;
case 0x0c06bccau: goto P_0c06bcca;
case 0x0c06bcccu: goto P_0c06bccc;
case 0x0c06bcceu: goto P_0c06bcce;
case 0x0c06bcd0u: goto P_0c06bcd0;
case 0x0c06bcd2u: goto P_0c06bcd2;
case 0x0c06bcd4u: goto P_0c06bcd4;
case 0x0c06bcd6u: goto P_0c06bcd6;
case 0x0c06bcd8u: goto P_0c06bcd8;
case 0x0c06bcdau: goto P_0c06bcda;
case 0x0c06bcdcu: goto P_0c06bcdc;
case 0x0c06bcdeu: goto P_0c06bcde;
case 0x0c06bce0u: goto P_0c06bce0;
case 0x0c06bce2u: goto P_0c06bce2;
case 0x0c06bce4u: goto P_0c06bce4;
case 0x0c06bce6u: goto P_0c06bce6;
case 0x0c06bce8u: goto P_0c06bce8;
case 0x0c06bceau: goto P_0c06bcea;
case 0x0c06bcecu: goto P_0c06bcec;
case 0x0c06bceeu: goto P_0c06bcee;
case 0x0c06bcf0u: goto P_0c06bcf0;
case 0x0c06bcf2u: goto P_0c06bcf2;
case 0x0c06bcf4u: goto P_0c06bcf4;
case 0x0c06bcf6u: goto P_0c06bcf6;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06b6dc: /* original 2fe6, guest PC 0x0c06b6dc */
if(!s->budget--) { s->failed_pc=0x0c06b6dcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b6de;
P_0c06b6de: /* original 2fd6, guest PC 0x0c06b6de */
if(!s->budget--) { s->failed_pc=0x0c06b6deu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b6e0;
P_0c06b6e0: /* original 2fc6, guest PC 0x0c06b6e0 */
if(!s->budget--) { s->failed_pc=0x0c06b6e0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b6e2;
P_0c06b6e2: /* original 2fb6, guest PC 0x0c06b6e2 */
if(!s->budget--) { s->failed_pc=0x0c06b6e2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b6e4;
P_0c06b6e4: /* original 2fa6, guest PC 0x0c06b6e4 */
if(!s->budget--) { s->failed_pc=0x0c06b6e4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b6e6;
P_0c06b6e6: /* original 2f96, guest PC 0x0c06b6e6 */
if(!s->budget--) { s->failed_pc=0x0c06b6e6u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b6e8;
P_0c06b6e8: /* original d417, guest PC 0x0c06b6e8 */
if(!s->budget--) { s->failed_pc=0x0c06b6e8u; return 0; }
r[4]=read(ram,0x0c06b748u,4);
goto P_0c06b6ea;
P_0c06b6ea: /* original 9228, guest PC 0x0c06b6ea */
if(!s->budget--) { s->failed_pc=0x0c06b6eau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b73eu,2);
goto P_0c06b6ec;
P_0c06b6ec: /* original 6343, guest PC 0x0c06b6ec */
if(!s->budget--) { s->failed_pc=0x0c06b6ecu; return 0; }
r[3]=r[4];
goto P_0c06b6ee;
P_0c06b6ee: /* original 6532, guest PC 0x0c06b6ee */
if(!s->budget--) { s->failed_pc=0x0c06b6eeu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06b6f0;
P_0c06b6f0: /* original 4f22, guest PC 0x0c06b6f0 */
if(!s->budget--) { s->failed_pc=0x0c06b6f0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06b6f2;
P_0c06b6f2: /* original dd16, guest PC 0x0c06b6f2 */
if(!s->budget--) { s->failed_pc=0x0c06b6f2u; return 0; }
r[13]=read(ram,0x0c06b74cu,4);
goto P_0c06b6f4;
P_0c06b6f4: /* original 2528, guest PC 0x0c06b6f4 */
if(!s->budget--) { s->failed_pc=0x0c06b6f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c06b6f6;
P_0c06b6f6: /* original 8901, guest PC 0x0c06b6f6 */
if(!s->budget--) { s->failed_pc=0x0c06b6f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06b6fc; }
goto P_0c06b6f8;
P_0c06b6f8: /* original a0a0, guest PC 0x0c06b6f8 */
if(!s->budget--) { s->failed_pc=0x0c06b6f8u; return 0; }
goto P_0c06b83c;
P_0c06b6fa: /* original 0009, guest PC 0x0c06b6fa */
if(!s->budget--) { s->failed_pc=0x0c06b6fau; return 0; }
goto P_0c06b6fc;
P_0c06b6fc: /* original 9020, guest PC 0x0c06b6fc */
if(!s->budget--) { s->failed_pc=0x0c06b6fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b740u,2);
goto P_0c06b6fe;
P_0c06b6fe: /* original e901, guest PC 0x0c06b6fe */
if(!s->budget--) { s->failed_pc=0x0c06b6feu; return 0; }
r[9]=0x00000001u;
goto P_0c06b700;
P_0c06b700: /* original 054e, guest PC 0x0c06b700 */
if(!s->budget--) { s->failed_pc=0x0c06b700u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c06b702;
P_0c06b702: /* original 6353, guest PC 0x0c06b702 */
if(!s->budget--) { s->failed_pc=0x0c06b702u; return 0; }
r[3]=r[5];
goto P_0c06b704;
P_0c06b704: /* original 2398, guest PC 0x0c06b704 */
if(!s->budget--) { s->failed_pc=0x0c06b704u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c06b706;
P_0c06b706: /* original 8b16, guest PC 0x0c06b706 */
if(!s->budget--) { s->failed_pc=0x0c06b706u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06b736; }
goto P_0c06b708;
P_0c06b708: /* original e202, guest PC 0x0c06b708 */
if(!s->budget--) { s->failed_pc=0x0c06b708u; return 0; }
r[2]=0x00000002u;
goto P_0c06b70a;
P_0c06b70a: /* original 2528, guest PC 0x0c06b70a */
if(!s->budget--) { s->failed_pc=0x0c06b70au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c06b70c;
P_0c06b70c: /* original 8b13, guest PC 0x0c06b70c */
if(!s->budget--) { s->failed_pc=0x0c06b70cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06b736; }
goto P_0c06b70e;
P_0c06b70e: /* original 9018, guest PC 0x0c06b70e */
if(!s->budget--) { s->failed_pc=0x0c06b70eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b742u,2);
goto P_0c06b710;
P_0c06b710: /* original de0f, guest PC 0x0c06b710 */
if(!s->budget--) { s->failed_pc=0x0c06b710u; return 0; }
r[14]=read(ram,0x0c06b750u,4);
goto P_0c06b712;
P_0c06b712: /* original 054e, guest PC 0x0c06b712 */
if(!s->budget--) { s->failed_pc=0x0c06b712u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c06b714;
P_0c06b714: /* original 9016, guest PC 0x0c06b714 */
if(!s->budget--) { s->failed_pc=0x0c06b714u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b744u,2);
goto P_0c06b716;
P_0c06b716: /* original d30f, guest PC 0x0c06b716 */
if(!s->budget--) { s->failed_pc=0x0c06b716u; return 0; }
r[3]=read(ram,0x0c06b754u,4);
goto P_0c06b718;
P_0c06b718: /* original 04ee, guest PC 0x0c06b718 */
if(!s->budget--) { s->failed_pc=0x0c06b718u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c06b71a;
P_0c06b71a: /* original 2538, guest PC 0x0c06b71a */
if(!s->budget--) { s->failed_pc=0x0c06b71au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c06b71c;
P_0c06b71c: /* original 8d04, guest PC 0x0c06b71c */
if(!s->budget--) { s->failed_pc=0x0c06b71cu; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(cond) { goto P_0c06b728; }
goto P_0c06b720;
P_0c06b71e: /* original ec00, guest PC 0x0c06b71e */
if(!s->budget--) { s->failed_pc=0x0c06b71eu; return 0; }
r[12]=0x00000000u;
goto P_0c06b720;
P_0c06b720: /* original 7401, guest PC 0x0c06b720 */
if(!s->budget--) { s->failed_pc=0x0c06b720u; return 0; }
r[4]+=0x00000001u;
goto P_0c06b722;
P_0c06b722: /* original 6543, guest PC 0x0c06b722 */
if(!s->budget--) { s->failed_pc=0x0c06b722u; return 0; }
r[5]=r[4];
goto P_0c06b724;
P_0c06b724: /* original a002, guest PC 0x0c06b724 */
if(!s->budget--) { s->failed_pc=0x0c06b724u; return 0; }
r[5]+=0xfffffffau;
goto P_0c06b72c;
P_0c06b726: /* original 75fa, guest PC 0x0c06b726 */
if(!s->budget--) { s->failed_pc=0x0c06b726u; return 0; }
r[5]+=0xfffffffau;
goto P_0c06b728;
P_0c06b728: /* original 6593, guest PC 0x0c06b728 */
if(!s->budget--) { s->failed_pc=0x0c06b728u; return 0; }
r[5]=r[9];
goto P_0c06b72a;
P_0c06b72a: /* original 64c3, guest PC 0x0c06b72a */
if(!s->budget--) { s->failed_pc=0x0c06b72au; return 0; }
r[4]=r[12];
goto P_0c06b72c;
P_0c06b72c: /* original 2558, guest PC 0x0c06b72c */
if(!s->budget--) { s->failed_pc=0x0c06b72cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06b72e;
P_0c06b72e: /* original 8d13, guest PC 0x0c06b72e */
if(!s->budget--) { s->failed_pc=0x0c06b72eu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],4);
if(cond) { goto P_0c06b758; }
goto P_0c06b732;
P_0c06b730: /* original 0e46, guest PC 0x0c06b730 */
if(!s->budget--) { s->failed_pc=0x0c06b730u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c06b732;
P_0c06b732: /* original a083, guest PC 0x0c06b732 */
if(!s->budget--) { s->failed_pc=0x0c06b732u; return 0; }
goto P_0c06b83c;
P_0c06b734: /* original 0009, guest PC 0x0c06b734 */
if(!s->budget--) { s->failed_pc=0x0c06b734u; return 0; }
goto P_0c06b736;
P_0c06b736: /* original b097, guest PC 0x0c06b736 */
if(!s->budget--) { s->failed_pc=0x0c06b736u; return 0; }
target=code_base|0x0c06b868u; r[16]=code_base|0x0c06b73au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b73au) { target=s->pc; goto dispatch; }
goto P_0c06b73a;
P_0c06b738: /* original 0009, guest PC 0x0c06b738 */
if(!s->budget--) { s->failed_pc=0x0c06b738u; return 0; }
goto P_0c06b73a;
P_0c06b73a: /* original a07f, guest PC 0x0c06b73a */
if(!s->budget--) { s->failed_pc=0x0c06b73au; return 0; }
goto P_0c06b83c;
P_0c06b73c: /* original 0009, guest PC 0x0c06b73c */
if(!s->budget--) { s->failed_pc=0x0c06b73cu; return 0; }
if(!vf3_matrix_family(0x0c06b73eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06b73eu; return 0; } return 1;
P_0c06b758: /* original 9078, guest PC 0x0c06b758 */
if(!s->budget--) { s->failed_pc=0x0c06b758u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b84cu,2);
goto P_0c06b75a;
P_0c06b75a: /* original 00ec, guest PC 0x0c06b75a */
if(!s->budget--) { s->failed_pc=0x0c06b75au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b75c;
P_0c06b75c: /* original 8801, guest PC 0x0c06b75c */
if(!s->budget--) { s->failed_pc=0x0c06b75cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06b75e;
P_0c06b75e: /* original 8d6d, guest PC 0x0c06b75e */
if(!s->budget--) { s->failed_pc=0x0c06b75eu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c06b83c; }
goto P_0c06b762;
P_0c06b760: /* original 6403, guest PC 0x0c06b760 */
if(!s->budget--) { s->failed_pc=0x0c06b760u; return 0; }
r[4]=r[0];
goto P_0c06b762;
P_0c06b762: /* original 9074, guest PC 0x0c06b762 */
if(!s->budget--) { s->failed_pc=0x0c06b762u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b84eu,2);
goto P_0c06b764;
P_0c06b764: /* original e309, guest PC 0x0c06b764 */
if(!s->budget--) { s->failed_pc=0x0c06b764u; return 0; }
r[3]=0x00000009u;
goto P_0c06b766;
P_0c06b766: /* original 04ec, guest PC 0x0c06b766 */
if(!s->budget--) { s->failed_pc=0x0c06b766u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b768;
P_0c06b768: /* original 3432, guest PC 0x0c06b768 */
if(!s->budget--) { s->failed_pc=0x0c06b768u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[3])!=0);
goto P_0c06b76a;
P_0c06b76a: /* original 8967, guest PC 0x0c06b76a */
if(!s->budget--) { s->failed_pc=0x0c06b76au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06b83c; }
goto P_0c06b76c;
P_0c06b76c: /* original 03ec, guest PC 0x0c06b76c */
if(!s->budget--) { s->failed_pc=0x0c06b76cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b76e;
P_0c06b76e: /* original 64d3, guest PC 0x0c06b76e */
if(!s->budget--) { s->failed_pc=0x0c06b76eu; return 0; }
r[4]=r[13];
goto P_0c06b770;
P_0c06b770: /* original e500, guest PC 0x0c06b770 */
if(!s->budget--) { s->failed_pc=0x0c06b770u; return 0; }
r[5]=0x00000000u;
goto P_0c06b772;
P_0c06b772: /* original 7301, guest PC 0x0c06b772 */
if(!s->budget--) { s->failed_pc=0x0c06b772u; return 0; }
r[3]+=0x00000001u;
goto P_0c06b774;
P_0c06b774: /* original 0e34, guest PC 0x0c06b774 */
if(!s->budget--) { s->failed_pc=0x0c06b774u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06b776;
P_0c06b776: /* original 70f9, guest PC 0x0c06b776 */
if(!s->budget--) { s->failed_pc=0x0c06b776u; return 0; }
r[0]+=0xfffffff9u;
goto P_0c06b778;
P_0c06b778: /* original 0ec4, guest PC 0x0c06b778 */
if(!s->budget--) { s->failed_pc=0x0c06b778u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06b77a;
P_0c06b77a: /* original da39, guest PC 0x0c06b77a */
if(!s->budget--) { s->failed_pc=0x0c06b77au; return 0; }
r[10]=read(ram,0x0c06b860u,4);
goto P_0c06b77c;
P_0c06b77c: /* original 4a0b, guest PC 0x0c06b77c */
if(!s->budget--) { s->failed_pc=0x0c06b77cu; return 0; }
target=r[10];
r[16]=code_base|0x0c06b780u;
r[4]+=0x00000028u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b780u) { target=s->pc; goto dispatch; }
goto P_0c06b780;
P_0c06b77e: /* original 7428, guest PC 0x0c06b77e */
if(!s->budget--) { s->failed_pc=0x0c06b77eu; return 0; }
r[4]+=0x00000028u;
goto P_0c06b780;
P_0c06b780: /* original 9066, guest PC 0x0c06b780 */
if(!s->budget--) { s->failed_pc=0x0c06b780u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b850u,2);
goto P_0c06b782;
P_0c06b782: /* original 64d3, guest PC 0x0c06b782 */
if(!s->budget--) { s->failed_pc=0x0c06b782u; return 0; }
r[4]=r[13];
goto P_0c06b784;
P_0c06b784: /* original e500, guest PC 0x0c06b784 */
if(!s->budget--) { s->failed_pc=0x0c06b784u; return 0; }
r[5]=0x00000000u;
goto P_0c06b786;
P_0c06b786: /* original 0ec4, guest PC 0x0c06b786 */
if(!s->budget--) { s->failed_pc=0x0c06b786u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06b788;
P_0c06b788: /* original 4a0b, guest PC 0x0c06b788 */
if(!s->budget--) { s->failed_pc=0x0c06b788u; return 0; }
target=r[10];
r[16]=code_base|0x0c06b78cu;
r[4]+=0x0000002bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b78cu) { target=s->pc; goto dispatch; }
goto P_0c06b78c;
P_0c06b78a: /* original 742b, guest PC 0x0c06b78a */
if(!s->budget--) { s->failed_pc=0x0c06b78au; return 0; }
r[4]+=0x0000002bu;
goto P_0c06b78c;
P_0c06b78c: /* original 9061, guest PC 0x0c06b78c */
if(!s->budget--) { s->failed_pc=0x0c06b78cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b852u,2);
goto P_0c06b78e;
P_0c06b78e: /* original 0bec, guest PC 0x0c06b78e */
if(!s->budget--) { s->failed_pc=0x0c06b78eu; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b790;
P_0c06b790: /* original 7008, guest PC 0x0c06b790 */
if(!s->budget--) { s->failed_pc=0x0c06b790u; return 0; }
r[0]+=0x00000008u;
goto P_0c06b792;
P_0c06b792: /* original 05ec, guest PC 0x0c06b792 */
if(!s->budget--) { s->failed_pc=0x0c06b792u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b794;
P_0c06b794: /* original 3b52, guest PC 0x0c06b794 */
if(!s->budget--) { s->failed_pc=0x0c06b794u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>=r[5])!=0);
goto P_0c06b796;
P_0c06b796: /* original 8d2c, guest PC 0x0c06b796 */
if(!s->budget--) { s->failed_pc=0x0c06b796u; return 0; }
cond=r[17]&1u;
r[4]=r[12];
if(cond) { goto P_0c06b7f2; }
goto P_0c06b79a;
P_0c06b798: /* original 64c3, guest PC 0x0c06b798 */
if(!s->budget--) { s->failed_pc=0x0c06b798u; return 0; }
r[4]=r[12];
goto P_0c06b79a;
P_0c06b79a: /* original 905b, guest PC 0x0c06b79a */
if(!s->budget--) { s->failed_pc=0x0c06b79au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b854u,2);
goto P_0c06b79c;
P_0c06b79c: /* original 7b01, guest PC 0x0c06b79c */
if(!s->budget--) { s->failed_pc=0x0c06b79cu; return 0; }
r[11]+=0x00000001u;
goto P_0c06b79e;
P_0c06b79e: /* original 3b52, guest PC 0x0c06b79e */
if(!s->budget--) { s->failed_pc=0x0c06b79eu; return 0; }
r[17]=(r[17]&~1u)|((r[11]>=r[5])!=0);
goto P_0c06b7a0;
P_0c06b7a0: /* original 03ec, guest PC 0x0c06b7a0 */
if(!s->budget--) { s->failed_pc=0x0c06b7a0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b7a2;
P_0c06b7a2: /* original 7301, guest PC 0x0c06b7a2 */
if(!s->budget--) { s->failed_pc=0x0c06b7a2u; return 0; }
r[3]+=0x00000001u;
goto P_0c06b7a4;
P_0c06b7a4: /* original 8f1e, guest PC 0x0c06b7a4 */
if(!s->budget--) { s->failed_pc=0x0c06b7a4u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[3],1);
if(!cond) { goto P_0c06b7e4; }
goto P_0c06b7a8;
P_0c06b7a6: /* original 0e34, guest PC 0x0c06b7a6 */
if(!s->budget--) { s->failed_pc=0x0c06b7a6u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06b7a8;
P_0c06b7a8: /* original 9055, guest PC 0x0c06b7a8 */
if(!s->budget--) { s->failed_pc=0x0c06b7a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b856u,2);
goto P_0c06b7aa;
P_0c06b7aa: /* original 6b53, guest PC 0x0c06b7aa */
if(!s->budget--) { s->failed_pc=0x0c06b7aau; return 0; }
r[11]=r[5];
goto P_0c06b7ac;
P_0c06b7ac: /* original 64d3, guest PC 0x0c06b7ac */
if(!s->budget--) { s->failed_pc=0x0c06b7acu; return 0; }
r[4]=r[13];
goto P_0c06b7ae;
P_0c06b7ae: /* original e500, guest PC 0x0c06b7ae */
if(!s->budget--) { s->failed_pc=0x0c06b7aeu; return 0; }
r[5]=0x00000000u;
goto P_0c06b7b0;
P_0c06b7b0: /* original 0ec4, guest PC 0x0c06b7b0 */
if(!s->budget--) { s->failed_pc=0x0c06b7b0u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06b7b2;
P_0c06b7b2: /* original 70ff, guest PC 0x0c06b7b2 */
if(!s->budget--) { s->failed_pc=0x0c06b7b2u; return 0; }
r[0]+=0xffffffffu;
goto P_0c06b7b4;
P_0c06b7b4: /* original 0ec4, guest PC 0x0c06b7b4 */
if(!s->budget--) { s->failed_pc=0x0c06b7b4u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06b7b6;
P_0c06b7b6: /* original 4a0b, guest PC 0x0c06b7b6 */
if(!s->budget--) { s->failed_pc=0x0c06b7b6u; return 0; }
target=r[10];
r[16]=code_base|0x0c06b7bau;
r[4]+=0x00000028u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b7bau) { target=s->pc; goto dispatch; }
goto P_0c06b7ba;
P_0c06b7b8: /* original 7428, guest PC 0x0c06b7b8 */
if(!s->budget--) { s->failed_pc=0x0c06b7b8u; return 0; }
r[4]+=0x00000028u;
goto P_0c06b7ba;
P_0c06b7ba: /* original 64d3, guest PC 0x0c06b7ba */
if(!s->budget--) { s->failed_pc=0x0c06b7bau; return 0; }
r[4]=r[13];
goto P_0c06b7bc;
P_0c06b7bc: /* original e500, guest PC 0x0c06b7bc */
if(!s->budget--) { s->failed_pc=0x0c06b7bcu; return 0; }
r[5]=0x00000000u;
goto P_0c06b7be;
P_0c06b7be: /* original 4a0b, guest PC 0x0c06b7be */
if(!s->budget--) { s->failed_pc=0x0c06b7beu; return 0; }
target=r[10];
r[16]=code_base|0x0c06b7c2u;
r[4]+=0x00000027u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b7c2u) { target=s->pc; goto dispatch; }
goto P_0c06b7c2;
P_0c06b7c0: /* original 7427, guest PC 0x0c06b7c0 */
if(!s->budget--) { s->failed_pc=0x0c06b7c0u; return 0; }
r[4]+=0x00000027u;
goto P_0c06b7c2;
P_0c06b7c2: /* original 9049, guest PC 0x0c06b7c2 */
if(!s->budget--) { s->failed_pc=0x0c06b7c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b858u,2);
goto P_0c06b7c4;
P_0c06b7c4: /* original 00ec, guest PC 0x0c06b7c4 */
if(!s->budget--) { s->failed_pc=0x0c06b7c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b7c6;
P_0c06b7c6: /* original 8801, guest PC 0x0c06b7c6 */
if(!s->budget--) { s->failed_pc=0x0c06b7c6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06b7c8;
P_0c06b7c8: /* original 8d0c, guest PC 0x0c06b7c8 */
if(!s->budget--) { s->failed_pc=0x0c06b7c8u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c06b7e4; }
goto P_0c06b7cc;
P_0c06b7ca: /* original 6403, guest PC 0x0c06b7ca */
if(!s->budget--) { s->failed_pc=0x0c06b7cau; return 0; }
r[4]=r[0];
goto P_0c06b7cc;
P_0c06b7cc: /* original 9040, guest PC 0x0c06b7cc */
if(!s->budget--) { s->failed_pc=0x0c06b7ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b850u,2);
goto P_0c06b7ce;
P_0c06b7ce: /* original 64d3, guest PC 0x0c06b7ce */
if(!s->budget--) { s->failed_pc=0x0c06b7ceu; return 0; }
r[4]=r[13];
goto P_0c06b7d0;
P_0c06b7d0: /* original e500, guest PC 0x0c06b7d0 */
if(!s->budget--) { s->failed_pc=0x0c06b7d0u; return 0; }
r[5]=0x00000000u;
goto P_0c06b7d2;
P_0c06b7d2: /* original 0ec4, guest PC 0x0c06b7d2 */
if(!s->budget--) { s->failed_pc=0x0c06b7d2u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06b7d4;
P_0c06b7d4: /* original 70ff, guest PC 0x0c06b7d4 */
if(!s->budget--) { s->failed_pc=0x0c06b7d4u; return 0; }
r[0]+=0xffffffffu;
goto P_0c06b7d6;
P_0c06b7d6: /* original 0ec4, guest PC 0x0c06b7d6 */
if(!s->budget--) { s->failed_pc=0x0c06b7d6u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06b7d8;
P_0c06b7d8: /* original 4a0b, guest PC 0x0c06b7d8 */
if(!s->budget--) { s->failed_pc=0x0c06b7d8u; return 0; }
target=r[10];
r[16]=code_base|0x0c06b7dcu;
r[4]+=0x0000002bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b7dcu) { target=s->pc; goto dispatch; }
goto P_0c06b7dc;
P_0c06b7da: /* original 742b, guest PC 0x0c06b7da */
if(!s->budget--) { s->failed_pc=0x0c06b7dau; return 0; }
r[4]+=0x0000002bu;
goto P_0c06b7dc;
P_0c06b7dc: /* original 64d3, guest PC 0x0c06b7dc */
if(!s->budget--) { s->failed_pc=0x0c06b7dcu; return 0; }
r[4]=r[13];
goto P_0c06b7de;
P_0c06b7de: /* original e500, guest PC 0x0c06b7de */
if(!s->budget--) { s->failed_pc=0x0c06b7deu; return 0; }
r[5]=0x00000000u;
goto P_0c06b7e0;
P_0c06b7e0: /* original 4a0b, guest PC 0x0c06b7e0 */
if(!s->budget--) { s->failed_pc=0x0c06b7e0u; return 0; }
target=r[10];
r[16]=code_base|0x0c06b7e4u;
r[4]+=0x0000002au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b7e4u) { target=s->pc; goto dispatch; }
goto P_0c06b7e4;
P_0c06b7e2: /* original 742a, guest PC 0x0c06b7e2 */
if(!s->budget--) { s->failed_pc=0x0c06b7e2u; return 0; }
r[4]+=0x0000002au;
goto P_0c06b7e4;
P_0c06b7e4: /* original 9035, guest PC 0x0c06b7e4 */
if(!s->budget--) { s->failed_pc=0x0c06b7e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b852u,2);
goto P_0c06b7e6;
P_0c06b7e6: /* original 64d3, guest PC 0x0c06b7e6 */
if(!s->budget--) { s->failed_pc=0x0c06b7e6u; return 0; }
r[4]=r[13];
goto P_0c06b7e8;
P_0c06b7e8: /* original 65b3, guest PC 0x0c06b7e8 */
if(!s->budget--) { s->failed_pc=0x0c06b7e8u; return 0; }
r[5]=r[11];
goto P_0c06b7ea;
P_0c06b7ea: /* original 0eb4, guest PC 0x0c06b7ea */
if(!s->budget--) { s->failed_pc=0x0c06b7eau; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06b7ec;
P_0c06b7ec: /* original 4a0b, guest PC 0x0c06b7ec */
if(!s->budget--) { s->failed_pc=0x0c06b7ecu; return 0; }
target=r[10];
r[16]=code_base|0x0c06b7f0u;
r[4]+=0x00000026u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b7f0u) { target=s->pc; goto dispatch; }
goto P_0c06b7f0;
P_0c06b7ee: /* original 7426, guest PC 0x0c06b7ee */
if(!s->budget--) { s->failed_pc=0x0c06b7eeu; return 0; }
r[4]+=0x00000026u;
goto P_0c06b7f0;
P_0c06b7f0: /* original 6493, guest PC 0x0c06b7f0 */
if(!s->budget--) { s->failed_pc=0x0c06b7f0u; return 0; }
r[4]=r[9];
goto P_0c06b7f2;
P_0c06b7f2: /* original 9031, guest PC 0x0c06b7f2 */
if(!s->budget--) { s->failed_pc=0x0c06b7f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b858u,2);
goto P_0c06b7f4;
P_0c06b7f4: /* original 00ec, guest PC 0x0c06b7f4 */
if(!s->budget--) { s->failed_pc=0x0c06b7f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b7f6;
P_0c06b7f6: /* original 8801, guest PC 0x0c06b7f6 */
if(!s->budget--) { s->failed_pc=0x0c06b7f6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06b7f8;
P_0c06b7f8: /* original 8f18, guest PC 0x0c06b7f8 */
if(!s->budget--) { s->failed_pc=0x0c06b7f8u; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(!cond) { goto P_0c06b82c; }
goto P_0c06b7fc;
P_0c06b7fa: /* original 6503, guest PC 0x0c06b7fa */
if(!s->budget--) { s->failed_pc=0x0c06b7fau; return 0; }
r[5]=r[0];
goto P_0c06b7fc;
P_0c06b7fc: /* original 902d, guest PC 0x0c06b7fc */
if(!s->budget--) { s->failed_pc=0x0c06b7fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b85au,2);
goto P_0c06b7fe;
P_0c06b7fe: /* original 0cec, guest PC 0x0c06b7fe */
if(!s->budget--) { s->failed_pc=0x0c06b7feu; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b800;
P_0c06b800: /* original 7004, guest PC 0x0c06b800 */
if(!s->budget--) { s->failed_pc=0x0c06b800u; return 0; }
r[0]+=0x00000004u;
goto P_0c06b802;
P_0c06b802: /* original 0bec, guest PC 0x0c06b802 */
if(!s->budget--) { s->failed_pc=0x0c06b802u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b804;
P_0c06b804: /* original 3cb2, guest PC 0x0c06b804 */
if(!s->budget--) { s->failed_pc=0x0c06b804u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>=r[11])!=0);
goto P_0c06b806;
P_0c06b806: /* original 8911, guest PC 0x0c06b806 */
if(!s->budget--) { s->failed_pc=0x0c06b806u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06b82c; }
goto P_0c06b808;
P_0c06b808: /* original 9024, guest PC 0x0c06b808 */
if(!s->budget--) { s->failed_pc=0x0c06b808u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b854u,2);
goto P_0c06b80a;
P_0c06b80a: /* original 7c01, guest PC 0x0c06b80a */
if(!s->budget--) { s->failed_pc=0x0c06b80au; return 0; }
r[12]+=0x00000001u;
goto P_0c06b80c;
P_0c06b80c: /* original 3cb2, guest PC 0x0c06b80c */
if(!s->budget--) { s->failed_pc=0x0c06b80cu; return 0; }
r[17]=(r[17]&~1u)|((r[12]>=r[11])!=0);
goto P_0c06b80e;
P_0c06b80e: /* original 03ec, guest PC 0x0c06b80e */
if(!s->budget--) { s->failed_pc=0x0c06b80eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b810;
P_0c06b810: /* original 7301, guest PC 0x0c06b810 */
if(!s->budget--) { s->failed_pc=0x0c06b810u; return 0; }
r[3]+=0x00000001u;
goto P_0c06b812;
P_0c06b812: /* original 8f04, guest PC 0x0c06b812 */
if(!s->budget--) { s->failed_pc=0x0c06b812u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[3],1);
if(!cond) { goto P_0c06b81e; }
goto P_0c06b816;
P_0c06b814: /* original 0e34, guest PC 0x0c06b814 */
if(!s->budget--) { s->failed_pc=0x0c06b814u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06b816;
P_0c06b816: /* original 65b3, guest PC 0x0c06b816 */
if(!s->budget--) { s->failed_pc=0x0c06b816u; return 0; }
r[5]=r[11];
goto P_0c06b818;
P_0c06b818: /* original b30c, guest PC 0x0c06b818 */
if(!s->budget--) { s->failed_pc=0x0c06b818u; return 0; }
target=code_base|0x0c06be34u; r[16]=code_base|0x0c06b81cu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b81cu) { target=s->pc; goto dispatch; }
goto P_0c06b81c;
P_0c06b81a: /* original 64d3, guest PC 0x0c06b81a */
if(!s->budget--) { s->failed_pc=0x0c06b81au; return 0; }
r[4]=r[13];
goto P_0c06b81c;
P_0c06b81c: /* original 6cb3, guest PC 0x0c06b81c */
if(!s->budget--) { s->failed_pc=0x0c06b81cu; return 0; }
r[12]=r[11];
goto P_0c06b81e;
P_0c06b81e: /* original 901c, guest PC 0x0c06b81e */
if(!s->budget--) { s->failed_pc=0x0c06b81eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b85au,2);
goto P_0c06b820;
P_0c06b820: /* original 64d3, guest PC 0x0c06b820 */
if(!s->budget--) { s->failed_pc=0x0c06b820u; return 0; }
r[4]=r[13];
goto P_0c06b822;
P_0c06b822: /* original 65c3, guest PC 0x0c06b822 */
if(!s->budget--) { s->failed_pc=0x0c06b822u; return 0; }
r[5]=r[12];
goto P_0c06b824;
P_0c06b824: /* original 0ec4, guest PC 0x0c06b824 */
if(!s->budget--) { s->failed_pc=0x0c06b824u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06b826;
P_0c06b826: /* original 4a0b, guest PC 0x0c06b826 */
if(!s->budget--) { s->failed_pc=0x0c06b826u; return 0; }
target=r[10];
r[16]=code_base|0x0c06b82au;
r[4]+=0x00000029u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b82au) { target=s->pc; goto dispatch; }
goto P_0c06b82a;
P_0c06b828: /* original 7429, guest PC 0x0c06b828 */
if(!s->budget--) { s->failed_pc=0x0c06b828u; return 0; }
r[4]+=0x00000029u;
goto P_0c06b82a;
P_0c06b82a: /* original 6493, guest PC 0x0c06b82a */
if(!s->budget--) { s->failed_pc=0x0c06b82au; return 0; }
r[4]=r[9];
goto P_0c06b82c;
P_0c06b82c: /* original 6043, guest PC 0x0c06b82c */
if(!s->budget--) { s->failed_pc=0x0c06b82cu; return 0; }
r[0]=r[4];
goto P_0c06b82e;
P_0c06b82e: /* original 8801, guest PC 0x0c06b82e */
if(!s->budget--) { s->failed_pc=0x0c06b82eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06b830;
P_0c06b830: /* original 8b04, guest PC 0x0c06b830 */
if(!s->budget--) { s->failed_pc=0x0c06b830u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06b83c; }
goto P_0c06b832;
P_0c06b832: /* original d30c, guest PC 0x0c06b832 */
if(!s->budget--) { s->failed_pc=0x0c06b832u; return 0; }
r[3]=read(ram,0x0c06b864u,4);
goto P_0c06b834;
P_0c06b834: /* original 9413, guest PC 0x0c06b834 */
if(!s->budget--) { s->failed_pc=0x0c06b834u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b85eu,2);
goto P_0c06b836;
P_0c06b836: /* original 9011, guest PC 0x0c06b836 */
if(!s->budget--) { s->failed_pc=0x0c06b836u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b85cu,2);
goto P_0c06b838;
P_0c06b838: /* original 430b, guest PC 0x0c06b838 */
if(!s->budget--) { s->failed_pc=0x0c06b838u; return 0; }
target=r[3];
r[16]=code_base|0x0c06b83cu;
write(ram,r[14]+r[0],r[9],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b83cu) { target=s->pc; goto dispatch; }
goto P_0c06b83c;
P_0c06b83a: /* original 0e94, guest PC 0x0c06b83a */
if(!s->budget--) { s->failed_pc=0x0c06b83au; return 0; }
write(ram,r[14]+r[0],r[9],1);
goto P_0c06b83c;
P_0c06b83c: /* original 4f26, guest PC 0x0c06b83c */
if(!s->budget--) { s->failed_pc=0x0c06b83cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06b83e;
P_0c06b83e: /* original 69f6, guest PC 0x0c06b83e */
if(!s->budget--) { s->failed_pc=0x0c06b83eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06b840;
P_0c06b840: /* original 6af6, guest PC 0x0c06b840 */
if(!s->budget--) { s->failed_pc=0x0c06b840u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06b842;
P_0c06b842: /* original 6bf6, guest PC 0x0c06b842 */
if(!s->budget--) { s->failed_pc=0x0c06b842u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06b844;
P_0c06b844: /* original 6cf6, guest PC 0x0c06b844 */
if(!s->budget--) { s->failed_pc=0x0c06b844u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06b846;
P_0c06b846: /* original 6df6, guest PC 0x0c06b846 */
if(!s->budget--) { s->failed_pc=0x0c06b846u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06b848;
P_0c06b848: /* original 000b, guest PC 0x0c06b848 */
if(!s->budget--) { s->failed_pc=0x0c06b848u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06b84a: /* original 6ef6, guest PC 0x0c06b84a */
if(!s->budget--) { s->failed_pc=0x0c06b84au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06b84cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06b84cu; return 0; } return 1;
P_0c06b868: /* original 2fe6, guest PC 0x0c06b868 */
if(!s->budget--) { s->failed_pc=0x0c06b868u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b86a;
P_0c06b86a: /* original 2fd6, guest PC 0x0c06b86a */
if(!s->budget--) { s->failed_pc=0x0c06b86au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b86c;
P_0c06b86c: /* original 2fc6, guest PC 0x0c06b86c */
if(!s->budget--) { s->failed_pc=0x0c06b86cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b86e;
P_0c06b86e: /* original 2fb6, guest PC 0x0c06b86e */
if(!s->budget--) { s->failed_pc=0x0c06b86eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b870;
P_0c06b870: /* original 2fa6, guest PC 0x0c06b870 */
if(!s->budget--) { s->failed_pc=0x0c06b870u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b872;
P_0c06b872: /* original 2f96, guest PC 0x0c06b872 */
if(!s->budget--) { s->failed_pc=0x0c06b872u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b874;
P_0c06b874: /* original 2f86, guest PC 0x0c06b874 */
if(!s->budget--) { s->failed_pc=0x0c06b874u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b876;
P_0c06b876: /* original e801, guest PC 0x0c06b876 */
if(!s->budget--) { s->failed_pc=0x0c06b876u; return 0; }
r[8]=0x00000001u;
goto P_0c06b878;
P_0c06b878: /* original 4f22, guest PC 0x0c06b878 */
if(!s->budget--) { s->failed_pc=0x0c06b878u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06b87a;
P_0c06b87a: /* original d33d, guest PC 0x0c06b87a */
if(!s->budget--) { s->failed_pc=0x0c06b87au; return 0; }
r[3]=read(ram,0x0c06b970u,4);
goto P_0c06b87c;
P_0c06b87c: /* original 4f12, guest PC 0x0c06b87c */
if(!s->budget--) { s->failed_pc=0x0c06b87cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c06b87e;
P_0c06b87e: /* original 7fec, guest PC 0x0c06b87e */
if(!s->budget--) { s->failed_pc=0x0c06b87eu; return 0; }
r[15]+=0xffffffecu;
goto P_0c06b880;
P_0c06b880: /* original 1f33, guest PC 0x0c06b880 */
if(!s->budget--) { s->failed_pc=0x0c06b880u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c06b882;
P_0c06b882: /* original 906c, guest PC 0x0c06b882 */
if(!s->budget--) { s->failed_pc=0x0c06b882u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b95eu,2);
goto P_0c06b884;
P_0c06b884: /* original dd3b, guest PC 0x0c06b884 */
if(!s->budget--) { s->failed_pc=0x0c06b884u; return 0; }
r[13]=read(ram,0x0c06b974u,4);
goto P_0c06b886;
P_0c06b886: /* original 023e, guest PC 0x0c06b886 */
if(!s->budget--) { s->failed_pc=0x0c06b886u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c06b888;
P_0c06b888: /* original 6323, guest PC 0x0c06b888 */
if(!s->budget--) { s->failed_pc=0x0c06b888u; return 0; }
r[3]=r[2];
goto P_0c06b88a;
P_0c06b88a: /* original 2388, guest PC 0x0c06b88a */
if(!s->budget--) { s->failed_pc=0x0c06b88au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c06b88c;
P_0c06b88c: /* original 1f21, guest PC 0x0c06b88c */
if(!s->budget--) { s->failed_pc=0x0c06b88cu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c06b88e;
P_0c06b88e: /* original dc3b, guest PC 0x0c06b88e */
if(!s->budget--) { s->failed_pc=0x0c06b88eu; return 0; }
r[12]=read(ram,0x0c06b97cu,4);
goto P_0c06b890;
P_0c06b890: /* original da39, guest PC 0x0c06b890 */
if(!s->budget--) { s->failed_pc=0x0c06b890u; return 0; }
r[10]=read(ram,0x0c06b978u,4);
goto P_0c06b892;
P_0c06b892: /* original de3b, guest PC 0x0c06b892 */
if(!s->budget--) { s->failed_pc=0x0c06b892u; return 0; }
r[14]=read(ram,0x0c06b980u,4);
goto P_0c06b894;
P_0c06b894: /* original 9964, guest PC 0x0c06b894 */
if(!s->budget--) { s->failed_pc=0x0c06b894u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b960u,2);
goto P_0c06b896;
P_0c06b896: /* original 8f02, guest PC 0x0c06b896 */
if(!s->budget--) { s->failed_pc=0x0c06b896u; return 0; }
cond=r[17]&1u;
r[11]=0x00000000u;
if(!cond) { goto P_0c06b89e; }
goto P_0c06b89a;
P_0c06b898: /* original eb00, guest PC 0x0c06b898 */
if(!s->budget--) { s->failed_pc=0x0c06b898u; return 0; }
r[11]=0x00000000u;
goto P_0c06b89a;
P_0c06b89a: /* original a0b4, guest PC 0x0c06b89a */
if(!s->budget--) { s->failed_pc=0x0c06b89au; return 0; }
goto P_0c06ba06;
P_0c06b89c: /* original 0009, guest PC 0x0c06b89c */
if(!s->budget--) { s->failed_pc=0x0c06b89cu; return 0; }
goto P_0c06b89e;
P_0c06b89e: /* original 9060, guest PC 0x0c06b89e */
if(!s->budget--) { s->failed_pc=0x0c06b89eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b962u,2);
goto P_0c06b8a0;
P_0c06b8a0: /* original 0eb4, guest PC 0x0c06b8a0 */
if(!s->budget--) { s->failed_pc=0x0c06b8a0u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06b8a2;
P_0c06b8a2: /* original 70fa, guest PC 0x0c06b8a2 */
if(!s->budget--) { s->failed_pc=0x0c06b8a2u; return 0; }
r[0]+=0xfffffffau;
goto P_0c06b8a4;
P_0c06b8a4: /* original 03ec, guest PC 0x0c06b8a4 */
if(!s->budget--) { s->failed_pc=0x0c06b8a4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b8a6;
P_0c06b8a6: /* original 7301, guest PC 0x0c06b8a6 */
if(!s->budget--) { s->failed_pc=0x0c06b8a6u; return 0; }
r[3]+=0x00000001u;
goto P_0c06b8a8;
P_0c06b8a8: /* original 0e34, guest PC 0x0c06b8a8 */
if(!s->budget--) { s->failed_pc=0x0c06b8a8u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06b8aa;
P_0c06b8aa: /* original 7013, guest PC 0x0c06b8aa */
if(!s->budget--) { s->failed_pc=0x0c06b8aau; return 0; }
r[0]+=0x00000013u;
goto P_0c06b8ac;
P_0c06b8ac: /* original 02ec, guest PC 0x0c06b8ac */
if(!s->budget--) { s->failed_pc=0x0c06b8acu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b8ae;
P_0c06b8ae: /* original 7201, guest PC 0x0c06b8ae */
if(!s->budget--) { s->failed_pc=0x0c06b8aeu; return 0; }
r[2]+=0x00000001u;
goto P_0c06b8b0;
P_0c06b8b0: /* original 0e24, guest PC 0x0c06b8b0 */
if(!s->budget--) { s->failed_pc=0x0c06b8b0u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c06b8b2;
P_0c06b8b2: /* original 70ea, guest PC 0x0c06b8b2 */
if(!s->budget--) { s->failed_pc=0x0c06b8b2u; return 0; }
r[0]+=0xffffffeau;
goto P_0c06b8b4;
P_0c06b8b4: /* original 03ec, guest PC 0x0c06b8b4 */
if(!s->budget--) { s->failed_pc=0x0c06b8b4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b8b6;
P_0c06b8b6: /* original 2f32, guest PC 0x0c06b8b6 */
if(!s->budget--) { s->failed_pc=0x0c06b8b6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06b8b8;
P_0c06b8b8: /* original 9054, guest PC 0x0c06b8b8 */
if(!s->budget--) { s->failed_pc=0x0c06b8b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b964u,2);
goto P_0c06b8ba;
P_0c06b8ba: /* original 02ec, guest PC 0x0c06b8ba */
if(!s->budget--) { s->failed_pc=0x0c06b8bau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b8bc;
P_0c06b8bc: /* original 1f21, guest PC 0x0c06b8bc */
if(!s->budget--) { s->failed_pc=0x0c06b8bcu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c06b8be;
P_0c06b8be: /* original 63f2, guest PC 0x0c06b8be */
if(!s->budget--) { s->failed_pc=0x0c06b8beu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06b8c0;
P_0c06b8c0: /* original 3322, guest PC 0x0c06b8c0 */
if(!s->budget--) { s->failed_pc=0x0c06b8c0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c06b8c2;
P_0c06b8c2: /* original 8b01, guest PC 0x0c06b8c2 */
if(!s->budget--) { s->failed_pc=0x0c06b8c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06b8c8; }
goto P_0c06b8c4;
P_0c06b8c4: /* original a09f, guest PC 0x0c06b8c4 */
if(!s->budget--) { s->failed_pc=0x0c06b8c4u; return 0; }
goto P_0c06ba06;
P_0c06b8c6: /* original 0009, guest PC 0x0c06b8c6 */
if(!s->budget--) { s->failed_pc=0x0c06b8c6u; return 0; }
goto P_0c06b8c8;
P_0c06b8c8: /* original 904d, guest PC 0x0c06b8c8 */
if(!s->budget--) { s->failed_pc=0x0c06b8c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b966u,2);
goto P_0c06b8ca;
P_0c06b8ca: /* original 02ec, guest PC 0x0c06b8ca */
if(!s->budget--) { s->failed_pc=0x0c06b8cau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b8cc;
P_0c06b8cc: /* original 6023, guest PC 0x0c06b8cc */
if(!s->budget--) { s->failed_pc=0x0c06b8ccu; return 0; }
r[0]=r[2];
goto P_0c06b8ce;
P_0c06b8ce: /* original 8801, guest PC 0x0c06b8ce */
if(!s->budget--) { s->failed_pc=0x0c06b8ceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06b8d0;
P_0c06b8d0: /* original 1f21, guest PC 0x0c06b8d0 */
if(!s->budget--) { s->failed_pc=0x0c06b8d0u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c06b8d2;
P_0c06b8d2: /* original 8b01, guest PC 0x0c06b8d2 */
if(!s->budget--) { s->failed_pc=0x0c06b8d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06b8d8; }
goto P_0c06b8d4;
P_0c06b8d4: /* original a097, guest PC 0x0c06b8d4 */
if(!s->budget--) { s->failed_pc=0x0c06b8d4u; return 0; }
goto P_0c06ba06;
P_0c06b8d6: /* original 0009, guest PC 0x0c06b8d6 */
if(!s->budget--) { s->failed_pc=0x0c06b8d6u; return 0; }
goto P_0c06b8d8;
P_0c06b8d8: /* original 53f1, guest PC 0x0c06b8d8 */
if(!s->budget--) { s->failed_pc=0x0c06b8d8u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06b8da;
P_0c06b8da: /* original 2338, guest PC 0x0c06b8da */
if(!s->budget--) { s->failed_pc=0x0c06b8dau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06b8dc;
P_0c06b8dc: /* original 8952, guest PC 0x0c06b8dc */
if(!s->budget--) { s->failed_pc=0x0c06b8dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06b984; }
goto P_0c06b8de;
P_0c06b8de: /* original 63f3, guest PC 0x0c06b8de */
if(!s->budget--) { s->failed_pc=0x0c06b8deu; return 0; }
r[3]=r[15];
goto P_0c06b8e0;
P_0c06b8e0: /* original 7308, guest PC 0x0c06b8e0 */
if(!s->budget--) { s->failed_pc=0x0c06b8e0u; return 0; }
r[3]+=0x00000008u;
goto P_0c06b8e2;
P_0c06b8e2: /* original 9041, guest PC 0x0c06b8e2 */
if(!s->budget--) { s->failed_pc=0x0c06b8e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b968u,2);
goto P_0c06b8e4;
P_0c06b8e4: /* original 06ec, guest PC 0x0c06b8e4 */
if(!s->budget--) { s->failed_pc=0x0c06b8e4u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b8e6;
P_0c06b8e6: /* original 2f36, guest PC 0x0c06b8e6 */
if(!s->budget--) { s->failed_pc=0x0c06b8e6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b8e8;
P_0c06b8e8: /* original 65f3, guest PC 0x0c06b8e8 */
if(!s->budget--) { s->failed_pc=0x0c06b8e8u; return 0; }
r[5]=r[15];
goto P_0c06b8ea;
P_0c06b8ea: /* original 67f3, guest PC 0x0c06b8ea */
if(!s->budget--) { s->failed_pc=0x0c06b8eau; return 0; }
r[7]=r[15];
goto P_0c06b8ec;
P_0c06b8ec: /* original 7508, guest PC 0x0c06b8ec */
if(!s->budget--) { s->failed_pc=0x0c06b8ecu; return 0; }
r[5]+=0x00000008u;
goto P_0c06b8ee;
P_0c06b8ee: /* original 7704, guest PC 0x0c06b8ee */
if(!s->budget--) { s->failed_pc=0x0c06b8eeu; return 0; }
r[7]+=0x00000004u;
goto P_0c06b8f0;
P_0c06b8f0: /* original b20a, guest PC 0x0c06b8f0 */
if(!s->budget--) { s->failed_pc=0x0c06b8f0u; return 0; }
target=code_base|0x0c06bd08u; r[16]=code_base|0x0c06b8f4u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b8f4u) { target=s->pc; goto dispatch; }
goto P_0c06b8f4;
P_0c06b8f2: /* original 64d3, guest PC 0x0c06b8f2 */
if(!s->budget--) { s->failed_pc=0x0c06b8f2u; return 0; }
r[4]=r[13];
goto P_0c06b8f4;
P_0c06b8f4: /* original 7f04, guest PC 0x0c06b8f4 */
if(!s->budget--) { s->failed_pc=0x0c06b8f4u; return 0; }
r[15]+=0x00000004u;
goto P_0c06b8f6;
P_0c06b8f6: /* original 62f2, guest PC 0x0c06b8f6 */
if(!s->budget--) { s->failed_pc=0x0c06b8f6u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c06b8f8;
P_0c06b8f8: /* original 53f1, guest PC 0x0c06b8f8 */
if(!s->budget--) { s->failed_pc=0x0c06b8f8u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06b8fa;
P_0c06b8fa: /* original 3232, guest PC 0x0c06b8fa */
if(!s->budget--) { s->failed_pc=0x0c06b8fau; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[3])!=0);
goto P_0c06b8fc;
P_0c06b8fc: /* original 8b1e, guest PC 0x0c06b8fc */
if(!s->budget--) { s->failed_pc=0x0c06b8fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06b93c; }
goto P_0c06b8fe;
P_0c06b8fe: /* original 51f1, guest PC 0x0c06b8fe */
if(!s->budget--) { s->failed_pc=0x0c06b8feu; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c06b900;
P_0c06b900: /* original e500, guest PC 0x0c06b900 */
if(!s->budget--) { s->failed_pc=0x0c06b900u; return 0; }
r[5]=0x00000000u;
goto P_0c06b902;
P_0c06b902: /* original 64d3, guest PC 0x0c06b902 */
if(!s->budget--) { s->failed_pc=0x0c06b902u; return 0; }
r[4]=r[13];
goto P_0c06b904;
P_0c06b904: /* original 2f12, guest PC 0x0c06b904 */
if(!s->budget--) { s->failed_pc=0x0c06b904u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c06b906;
P_0c06b906: /* original 9030, guest PC 0x0c06b906 */
if(!s->budget--) { s->failed_pc=0x0c06b906u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b96au,2);
goto P_0c06b908;
P_0c06b908: /* original 0eb4, guest PC 0x0c06b908 */
if(!s->budget--) { s->failed_pc=0x0c06b908u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06b90a;
P_0c06b90a: /* original 70ff, guest PC 0x0c06b90a */
if(!s->budget--) { s->failed_pc=0x0c06b90au; return 0; }
r[0]+=0xffffffffu;
goto P_0c06b90c;
P_0c06b90c: /* original 0eb4, guest PC 0x0c06b90c */
if(!s->budget--) { s->failed_pc=0x0c06b90cu; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06b90e;
P_0c06b90e: /* original 4c0b, guest PC 0x0c06b90e */
if(!s->budget--) { s->failed_pc=0x0c06b90eu; return 0; }
target=r[12];
r[16]=code_base|0x0c06b912u;
r[4]+=0x00000028u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b912u) { target=s->pc; goto dispatch; }
goto P_0c06b912;
P_0c06b910: /* original 7428, guest PC 0x0c06b910 */
if(!s->budget--) { s->failed_pc=0x0c06b910u; return 0; }
r[4]+=0x00000028u;
goto P_0c06b912;
P_0c06b912: /* original 902b, guest PC 0x0c06b912 */
if(!s->budget--) { s->failed_pc=0x0c06b912u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b96cu,2);
goto P_0c06b914;
P_0c06b914: /* original 00ec, guest PC 0x0c06b914 */
if(!s->budget--) { s->failed_pc=0x0c06b914u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b916;
P_0c06b916: /* original 8801, guest PC 0x0c06b916 */
if(!s->budget--) { s->failed_pc=0x0c06b916u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06b918;
P_0c06b918: /* original 8d10, guest PC 0x0c06b918 */
if(!s->budget--) { s->failed_pc=0x0c06b918u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c06b93c; }
goto P_0c06b91c;
P_0c06b91a: /* original 6403, guest PC 0x0c06b91a */
if(!s->budget--) { s->failed_pc=0x0c06b91au; return 0; }
r[4]=r[0];
goto P_0c06b91c;
P_0c06b91c: /* original 9027, guest PC 0x0c06b91c */
if(!s->budget--) { s->failed_pc=0x0c06b91cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b96eu,2);
goto P_0c06b91e;
P_0c06b91e: /* original 64d3, guest PC 0x0c06b91e */
if(!s->budget--) { s->failed_pc=0x0c06b91eu; return 0; }
r[4]=r[13];
goto P_0c06b920;
P_0c06b920: /* original e500, guest PC 0x0c06b920 */
if(!s->budget--) { s->failed_pc=0x0c06b920u; return 0; }
r[5]=0x00000000u;
goto P_0c06b922;
P_0c06b922: /* original 0eb4, guest PC 0x0c06b922 */
if(!s->budget--) { s->failed_pc=0x0c06b922u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06b924;
P_0c06b924: /* original 70ff, guest PC 0x0c06b924 */
if(!s->budget--) { s->failed_pc=0x0c06b924u; return 0; }
r[0]+=0xffffffffu;
goto P_0c06b926;
P_0c06b926: /* original 0eb4, guest PC 0x0c06b926 */
if(!s->budget--) { s->failed_pc=0x0c06b926u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06b928;
P_0c06b928: /* original 4c0b, guest PC 0x0c06b928 */
if(!s->budget--) { s->failed_pc=0x0c06b928u; return 0; }
target=r[12];
r[16]=code_base|0x0c06b92cu;
r[4]+=0x00000027u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b92cu) { target=s->pc; goto dispatch; }
goto P_0c06b92c;
P_0c06b92a: /* original 7427, guest PC 0x0c06b92a */
if(!s->budget--) { s->failed_pc=0x0c06b92au; return 0; }
r[4]+=0x00000027u;
goto P_0c06b92c;
P_0c06b92c: /* original 64d3, guest PC 0x0c06b92c */
if(!s->budget--) { s->failed_pc=0x0c06b92cu; return 0; }
r[4]=r[13];
goto P_0c06b92e;
P_0c06b92e: /* original e500, guest PC 0x0c06b92e */
if(!s->budget--) { s->failed_pc=0x0c06b92eu; return 0; }
r[5]=0x00000000u;
goto P_0c06b930;
P_0c06b930: /* original 4c0b, guest PC 0x0c06b930 */
if(!s->budget--) { s->failed_pc=0x0c06b930u; return 0; }
target=r[12];
r[16]=code_base|0x0c06b934u;
r[4]+=0x0000002bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b934u) { target=s->pc; goto dispatch; }
goto P_0c06b934;
P_0c06b932: /* original 742b, guest PC 0x0c06b932 */
if(!s->budget--) { s->failed_pc=0x0c06b932u; return 0; }
r[4]+=0x0000002bu;
goto P_0c06b934;
P_0c06b934: /* original 64d3, guest PC 0x0c06b934 */
if(!s->budget--) { s->failed_pc=0x0c06b934u; return 0; }
r[4]=r[13];
goto P_0c06b936;
P_0c06b936: /* original e500, guest PC 0x0c06b936 */
if(!s->budget--) { s->failed_pc=0x0c06b936u; return 0; }
r[5]=0x00000000u;
goto P_0c06b938;
P_0c06b938: /* original 4c0b, guest PC 0x0c06b938 */
if(!s->budget--) { s->failed_pc=0x0c06b938u; return 0; }
target=r[12];
r[16]=code_base|0x0c06b93cu;
r[4]+=0x0000002au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b93cu) { target=s->pc; goto dispatch; }
goto P_0c06b93c;
P_0c06b93a: /* original 742a, guest PC 0x0c06b93a */
if(!s->budget--) { s->failed_pc=0x0c06b93au; return 0; }
r[4]+=0x0000002au;
goto P_0c06b93c;
P_0c06b93c: /* original 9015, guest PC 0x0c06b93c */
if(!s->budget--) { s->failed_pc=0x0c06b93cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b96au,2);
goto P_0c06b93e;
P_0c06b93e: /* original 53f2, guest PC 0x0c06b93e */
if(!s->budget--) { s->failed_pc=0x0c06b93eu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c06b940;
P_0c06b940: /* original 04ec, guest PC 0x0c06b940 */
if(!s->budget--) { s->failed_pc=0x0c06b940u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b942;
P_0c06b942: /* original 70fe, guest PC 0x0c06b942 */
if(!s->budget--) { s->failed_pc=0x0c06b942u; return 0; }
r[0]+=0xfffffffeu;
goto P_0c06b944;
P_0c06b944: /* original 05ec, guest PC 0x0c06b944 */
if(!s->budget--) { s->failed_pc=0x0c06b944u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b946;
P_0c06b946: /* original 3430, guest PC 0x0c06b946 */
if(!s->budget--) { s->failed_pc=0x0c06b946u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c06b948;
P_0c06b948: /* original 8b02, guest PC 0x0c06b948 */
if(!s->budget--) { s->failed_pc=0x0c06b948u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06b950; }
goto P_0c06b94a;
P_0c06b94a: /* original 61f2, guest PC 0x0c06b94a */
if(!s->budget--) { s->failed_pc=0x0c06b94au; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c06b94c;
P_0c06b94c: /* original 3510, guest PC 0x0c06b94c */
if(!s->budget--) { s->failed_pc=0x0c06b94cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[1])!=0);
goto P_0c06b94e;
P_0c06b94e: /* original 8901, guest PC 0x0c06b94e */
if(!s->budget--) { s->failed_pc=0x0c06b94eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06b954; }
goto P_0c06b950;
P_0c06b950: /* original 4a0b, guest PC 0x0c06b950 */
if(!s->budget--) { s->failed_pc=0x0c06b950u; return 0; }
target=r[10];
r[16]=code_base|0x0c06b954u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b954u) { target=s->pc; goto dispatch; }
goto P_0c06b954;
P_0c06b952: /* original 6493, guest PC 0x0c06b952 */
if(!s->budget--) { s->failed_pc=0x0c06b952u; return 0; }
r[4]=r[9];
goto P_0c06b954;
P_0c06b954: /* original 65f2, guest PC 0x0c06b954 */
if(!s->budget--) { s->failed_pc=0x0c06b954u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06b956;
P_0c06b956: /* original b223, guest PC 0x0c06b956 */
if(!s->budget--) { s->failed_pc=0x0c06b956u; return 0; }
target=code_base|0x0c06bda0u; r[16]=code_base|0x0c06b95au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b95au) { target=s->pc; goto dispatch; }
goto P_0c06b95a;
P_0c06b958: /* original 64d3, guest PC 0x0c06b958 */
if(!s->budget--) { s->failed_pc=0x0c06b958u; return 0; }
r[4]=r[13];
goto P_0c06b95a;
P_0c06b95a: /* original a054, guest PC 0x0c06b95a */
if(!s->budget--) { s->failed_pc=0x0c06b95au; return 0; }
goto P_0c06ba06;
P_0c06b95c: /* original 0009, guest PC 0x0c06b95c */
if(!s->budget--) { s->failed_pc=0x0c06b95cu; return 0; }
if(!vf3_matrix_family(0x0c06b95eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06b95eu; return 0; } return 1;
P_0c06b984: /* original 63f3, guest PC 0x0c06b984 */
if(!s->budget--) { s->failed_pc=0x0c06b984u; return 0; }
r[3]=r[15];
goto P_0c06b986;
P_0c06b986: /* original 7308, guest PC 0x0c06b986 */
if(!s->budget--) { s->failed_pc=0x0c06b986u; return 0; }
r[3]+=0x00000008u;
goto P_0c06b988;
P_0c06b988: /* original 907c, guest PC 0x0c06b988 */
if(!s->budget--) { s->failed_pc=0x0c06b988u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ba84u,2);
goto P_0c06b98a;
P_0c06b98a: /* original 06ec, guest PC 0x0c06b98a */
if(!s->budget--) { s->failed_pc=0x0c06b98au; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b98c;
P_0c06b98c: /* original 2f36, guest PC 0x0c06b98c */
if(!s->budget--) { s->failed_pc=0x0c06b98cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b98e;
P_0c06b98e: /* original 65f3, guest PC 0x0c06b98e */
if(!s->budget--) { s->failed_pc=0x0c06b98eu; return 0; }
r[5]=r[15];
goto P_0c06b990;
P_0c06b990: /* original 67f3, guest PC 0x0c06b990 */
if(!s->budget--) { s->failed_pc=0x0c06b990u; return 0; }
r[7]=r[15];
goto P_0c06b992;
P_0c06b992: /* original 7508, guest PC 0x0c06b992 */
if(!s->budget--) { s->failed_pc=0x0c06b992u; return 0; }
r[5]+=0x00000008u;
goto P_0c06b994;
P_0c06b994: /* original 7704, guest PC 0x0c06b994 */
if(!s->budget--) { s->failed_pc=0x0c06b994u; return 0; }
r[7]+=0x00000004u;
goto P_0c06b996;
P_0c06b996: /* original b21a, guest PC 0x0c06b996 */
if(!s->budget--) { s->failed_pc=0x0c06b996u; return 0; }
target=code_base|0x0c06bdceu; r[16]=code_base|0x0c06b99au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b99au) { target=s->pc; goto dispatch; }
goto P_0c06b99a;
P_0c06b998: /* original 64d3, guest PC 0x0c06b998 */
if(!s->budget--) { s->failed_pc=0x0c06b998u; return 0; }
r[4]=r[13];
goto P_0c06b99a;
P_0c06b99a: /* original 7f04, guest PC 0x0c06b99a */
if(!s->budget--) { s->failed_pc=0x0c06b99au; return 0; }
r[15]+=0x00000004u;
goto P_0c06b99c;
P_0c06b99c: /* original 62f2, guest PC 0x0c06b99c */
if(!s->budget--) { s->failed_pc=0x0c06b99cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c06b99e;
P_0c06b99e: /* original 53f1, guest PC 0x0c06b99e */
if(!s->budget--) { s->failed_pc=0x0c06b99eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06b9a0;
P_0c06b9a0: /* original 3232, guest PC 0x0c06b9a0 */
if(!s->budget--) { s->failed_pc=0x0c06b9a0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[3])!=0);
goto P_0c06b9a2;
P_0c06b9a2: /* original 8b12, guest PC 0x0c06b9a2 */
if(!s->budget--) { s->failed_pc=0x0c06b9a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06b9ca; }
goto P_0c06b9a4;
P_0c06b9a4: /* original 51f1, guest PC 0x0c06b9a4 */
if(!s->budget--) { s->failed_pc=0x0c06b9a4u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c06b9a6;
P_0c06b9a6: /* original e500, guest PC 0x0c06b9a6 */
if(!s->budget--) { s->failed_pc=0x0c06b9a6u; return 0; }
r[5]=0x00000000u;
goto P_0c06b9a8;
P_0c06b9a8: /* original 64d3, guest PC 0x0c06b9a8 */
if(!s->budget--) { s->failed_pc=0x0c06b9a8u; return 0; }
r[4]=r[13];
goto P_0c06b9aa;
P_0c06b9aa: /* original 2f12, guest PC 0x0c06b9aa */
if(!s->budget--) { s->failed_pc=0x0c06b9aau; return 0; }
write(ram,r[15],r[1],4);
goto P_0c06b9ac;
P_0c06b9ac: /* original 906b, guest PC 0x0c06b9ac */
if(!s->budget--) { s->failed_pc=0x0c06b9acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ba86u,2);
goto P_0c06b9ae;
P_0c06b9ae: /* original 0eb4, guest PC 0x0c06b9ae */
if(!s->budget--) { s->failed_pc=0x0c06b9aeu; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06b9b0;
P_0c06b9b0: /* original 4c0b, guest PC 0x0c06b9b0 */
if(!s->budget--) { s->failed_pc=0x0c06b9b0u; return 0; }
target=r[12];
r[16]=code_base|0x0c06b9b4u;
r[4]+=0x00000027u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b9b4u) { target=s->pc; goto dispatch; }
goto P_0c06b9b4;
P_0c06b9b2: /* original 7427, guest PC 0x0c06b9b2 */
if(!s->budget--) { s->failed_pc=0x0c06b9b2u; return 0; }
r[4]+=0x00000027u;
goto P_0c06b9b4;
P_0c06b9b4: /* original 9068, guest PC 0x0c06b9b4 */
if(!s->budget--) { s->failed_pc=0x0c06b9b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ba88u,2);
goto P_0c06b9b6;
P_0c06b9b6: /* original 00ec, guest PC 0x0c06b9b6 */
if(!s->budget--) { s->failed_pc=0x0c06b9b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b9b8;
P_0c06b9b8: /* original 8801, guest PC 0x0c06b9b8 */
if(!s->budget--) { s->failed_pc=0x0c06b9b8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06b9ba;
P_0c06b9ba: /* original 8d06, guest PC 0x0c06b9ba */
if(!s->budget--) { s->failed_pc=0x0c06b9bau; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c06b9ca; }
goto P_0c06b9be;
P_0c06b9bc: /* original 6403, guest PC 0x0c06b9bc */
if(!s->budget--) { s->failed_pc=0x0c06b9bcu; return 0; }
r[4]=r[0];
goto P_0c06b9be;
P_0c06b9be: /* original 9064, guest PC 0x0c06b9be */
if(!s->budget--) { s->failed_pc=0x0c06b9beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ba8au,2);
goto P_0c06b9c0;
P_0c06b9c0: /* original 64d3, guest PC 0x0c06b9c0 */
if(!s->budget--) { s->failed_pc=0x0c06b9c0u; return 0; }
r[4]=r[13];
goto P_0c06b9c2;
P_0c06b9c2: /* original e500, guest PC 0x0c06b9c2 */
if(!s->budget--) { s->failed_pc=0x0c06b9c2u; return 0; }
r[5]=0x00000000u;
goto P_0c06b9c4;
P_0c06b9c4: /* original 0eb4, guest PC 0x0c06b9c4 */
if(!s->budget--) { s->failed_pc=0x0c06b9c4u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06b9c6;
P_0c06b9c6: /* original 4c0b, guest PC 0x0c06b9c6 */
if(!s->budget--) { s->failed_pc=0x0c06b9c6u; return 0; }
target=r[12];
r[16]=code_base|0x0c06b9cau;
r[4]+=0x0000002au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b9cau) { target=s->pc; goto dispatch; }
goto P_0c06b9ca;
P_0c06b9c8: /* original 742a, guest PC 0x0c06b9c8 */
if(!s->budget--) { s->failed_pc=0x0c06b9c8u; return 0; }
r[4]+=0x0000002au;
goto P_0c06b9ca;
P_0c06b9ca: /* original 905c, guest PC 0x0c06b9ca */
if(!s->budget--) { s->failed_pc=0x0c06b9cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ba86u,2);
goto P_0c06b9cc;
P_0c06b9cc: /* original 53f2, guest PC 0x0c06b9cc */
if(!s->budget--) { s->failed_pc=0x0c06b9ccu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c06b9ce;
P_0c06b9ce: /* original 05ec, guest PC 0x0c06b9ce */
if(!s->budget--) { s->failed_pc=0x0c06b9ceu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b9d0;
P_0c06b9d0: /* original 70ff, guest PC 0x0c06b9d0 */
if(!s->budget--) { s->failed_pc=0x0c06b9d0u; return 0; }
r[0]+=0xffffffffu;
goto P_0c06b9d2;
P_0c06b9d2: /* original 04ec, guest PC 0x0c06b9d2 */
if(!s->budget--) { s->failed_pc=0x0c06b9d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b9d4;
P_0c06b9d4: /* original 3530, guest PC 0x0c06b9d4 */
if(!s->budget--) { s->failed_pc=0x0c06b9d4u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[3])!=0);
goto P_0c06b9d6;
P_0c06b9d6: /* original 8b02, guest PC 0x0c06b9d6 */
if(!s->budget--) { s->failed_pc=0x0c06b9d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06b9de; }
goto P_0c06b9d8;
P_0c06b9d8: /* original 61f2, guest PC 0x0c06b9d8 */
if(!s->budget--) { s->failed_pc=0x0c06b9d8u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c06b9da;
P_0c06b9da: /* original 3410, guest PC 0x0c06b9da */
if(!s->budget--) { s->failed_pc=0x0c06b9dau; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[1])!=0);
goto P_0c06b9dc;
P_0c06b9dc: /* original 8901, guest PC 0x0c06b9dc */
if(!s->budget--) { s->failed_pc=0x0c06b9dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06b9e2; }
goto P_0c06b9de;
P_0c06b9de: /* original 4a0b, guest PC 0x0c06b9de */
if(!s->budget--) { s->failed_pc=0x0c06b9deu; return 0; }
target=r[10];
r[16]=code_base|0x0c06b9e2u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b9e2u) { target=s->pc; goto dispatch; }
goto P_0c06b9e2;
P_0c06b9e0: /* original 6493, guest PC 0x0c06b9e0 */
if(!s->budget--) { s->failed_pc=0x0c06b9e0u; return 0; }
r[4]=r[9];
goto P_0c06b9e2;
P_0c06b9e2: /* original 9053, guest PC 0x0c06b9e2 */
if(!s->budget--) { s->failed_pc=0x0c06b9e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ba8cu,2);
goto P_0c06b9e4;
P_0c06b9e4: /* original 63f2, guest PC 0x0c06b9e4 */
if(!s->budget--) { s->failed_pc=0x0c06b9e4u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06b9e6;
P_0c06b9e6: /* original 05ec, guest PC 0x0c06b9e6 */
if(!s->budget--) { s->failed_pc=0x0c06b9e6u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b9e8;
P_0c06b9e8: /* original 9051, guest PC 0x0c06b9e8 */
if(!s->budget--) { s->failed_pc=0x0c06b9e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ba8eu,2);
goto P_0c06b9ea;
P_0c06b9ea: /* original 3358, guest PC 0x0c06b9ea */
if(!s->budget--) { s->failed_pc=0x0c06b9eau; return 0; }
r[3]-=r[5];
goto P_0c06b9ec;
P_0c06b9ec: /* original 04ec, guest PC 0x0c06b9ec */
if(!s->budget--) { s->failed_pc=0x0c06b9ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06b9ee;
P_0c06b9ee: /* original 6533, guest PC 0x0c06b9ee */
if(!s->budget--) { s->failed_pc=0x0c06b9eeu; return 0; }
r[5]=r[3];
goto P_0c06b9f0;
P_0c06b9f0: /* original 345c, guest PC 0x0c06b9f0 */
if(!s->budget--) { s->failed_pc=0x0c06b9f0u; return 0; }
r[4]+=r[5];
goto P_0c06b9f2;
P_0c06b9f2: /* original 0e44, guest PC 0x0c06b9f2 */
if(!s->budget--) { s->failed_pc=0x0c06b9f2u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06b9f4;
P_0c06b9f4: /* original 64d3, guest PC 0x0c06b9f4 */
if(!s->budget--) { s->failed_pc=0x0c06b9f4u; return 0; }
r[4]=r[13];
goto P_0c06b9f6;
P_0c06b9f6: /* original 9049, guest PC 0x0c06b9f6 */
if(!s->budget--) { s->failed_pc=0x0c06b9f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ba8cu,2);
goto P_0c06b9f8;
P_0c06b9f8: /* original 63f2, guest PC 0x0c06b9f8 */
if(!s->budget--) { s->failed_pc=0x0c06b9f8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06b9fa;
P_0c06b9fa: /* original 0e34, guest PC 0x0c06b9fa */
if(!s->budget--) { s->failed_pc=0x0c06b9fau; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06b9fc;
P_0c06b9fc: /* original 65f2, guest PC 0x0c06b9fc */
if(!s->budget--) { s->failed_pc=0x0c06b9fcu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06b9fe;
P_0c06b9fe: /* original 4c0b, guest PC 0x0c06b9fe */
if(!s->budget--) { s->failed_pc=0x0c06b9feu; return 0; }
target=r[12];
r[16]=code_base|0x0c06ba02u;
r[4]+=0x00000026u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ba02u) { target=s->pc; goto dispatch; }
goto P_0c06ba02;
P_0c06ba00: /* original 7426, guest PC 0x0c06ba00 */
if(!s->budget--) { s->failed_pc=0x0c06ba00u; return 0; }
r[4]+=0x00000026u;
goto P_0c06ba02;
P_0c06ba02: /* original 9045, guest PC 0x0c06ba02 */
if(!s->budget--) { s->failed_pc=0x0c06ba02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ba90u,2);
goto P_0c06ba04;
P_0c06ba04: /* original 0e84, guest PC 0x0c06ba04 */
if(!s->budget--) { s->failed_pc=0x0c06ba04u; return 0; }
write(ram,r[14]+r[0],r[8],1);
goto P_0c06ba06;
P_0c06ba06: /* original 9044, guest PC 0x0c06ba06 */
if(!s->budget--) { s->failed_pc=0x0c06ba06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ba92u,2);
goto P_0c06ba08;
P_0c06ba08: /* original 53f3, guest PC 0x0c06ba08 */
if(!s->budget--) { s->failed_pc=0x0c06ba08u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c06ba0a;
P_0c06ba0a: /* original 023e, guest PC 0x0c06ba0a */
if(!s->budget--) { s->failed_pc=0x0c06ba0au; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c06ba0c;
P_0c06ba0c: /* original 6023, guest PC 0x0c06ba0c */
if(!s->budget--) { s->failed_pc=0x0c06ba0cu; return 0; }
r[0]=r[2];
goto P_0c06ba0e;
P_0c06ba0e: /* original c802, guest PC 0x0c06ba0e */
if(!s->budget--) { s->failed_pc=0x0c06ba0eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c06ba10;
P_0c06ba10: /* original 1f21, guest PC 0x0c06ba10 */
if(!s->budget--) { s->failed_pc=0x0c06ba10u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c06ba12;
P_0c06ba12: /* original 8b01, guest PC 0x0c06ba12 */
if(!s->budget--) { s->failed_pc=0x0c06ba12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ba18; }
goto P_0c06ba14;
P_0c06ba14: /* original a165, guest PC 0x0c06ba14 */
if(!s->budget--) { s->failed_pc=0x0c06ba14u; return 0; }
goto P_0c06bce2;
P_0c06ba16: /* original 0009, guest PC 0x0c06ba16 */
if(!s->budget--) { s->failed_pc=0x0c06ba16u; return 0; }
goto P_0c06ba18;
P_0c06ba18: /* original 903c, guest PC 0x0c06ba18 */
if(!s->budget--) { s->failed_pc=0x0c06ba18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ba94u,2);
goto P_0c06ba1a;
P_0c06ba1a: /* original 0eb4, guest PC 0x0c06ba1a */
if(!s->budget--) { s->failed_pc=0x0c06ba1au; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06ba1c;
P_0c06ba1c: /* original 70f2, guest PC 0x0c06ba1c */
if(!s->budget--) { s->failed_pc=0x0c06ba1cu; return 0; }
r[0]+=0xfffffff2u;
goto P_0c06ba1e;
P_0c06ba1e: /* original 03ec, guest PC 0x0c06ba1e */
if(!s->budget--) { s->failed_pc=0x0c06ba1eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06ba20;
P_0c06ba20: /* original 6033, guest PC 0x0c06ba20 */
if(!s->budget--) { s->failed_pc=0x0c06ba20u; return 0; }
r[0]=r[3];
goto P_0c06ba22;
P_0c06ba22: /* original 8801, guest PC 0x0c06ba22 */
if(!s->budget--) { s->failed_pc=0x0c06ba22u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06ba24;
P_0c06ba24: /* original 1f31, guest PC 0x0c06ba24 */
if(!s->budget--) { s->failed_pc=0x0c06ba24u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c06ba26;
P_0c06ba26: /* original 891b, guest PC 0x0c06ba26 */
if(!s->budget--) { s->failed_pc=0x0c06ba26u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06ba60; }
goto P_0c06ba28;
P_0c06ba28: /* original 902c, guest PC 0x0c06ba28 */
if(!s->budget--) { s->failed_pc=0x0c06ba28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ba84u,2);
goto P_0c06ba2a;
P_0c06ba2a: /* original 03ec, guest PC 0x0c06ba2a */
if(!s->budget--) { s->failed_pc=0x0c06ba2au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06ba2c;
P_0c06ba2c: /* original 1f31, guest PC 0x0c06ba2c */
if(!s->budget--) { s->failed_pc=0x0c06ba2cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c06ba2e;
P_0c06ba2e: /* original 9032, guest PC 0x0c06ba2e */
if(!s->budget--) { s->failed_pc=0x0c06ba2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ba96u,2);
goto P_0c06ba30;
P_0c06ba30: /* original 04ec, guest PC 0x0c06ba30 */
if(!s->budget--) { s->failed_pc=0x0c06ba30u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06ba32;
P_0c06ba32: /* original 3340, guest PC 0x0c06ba32 */
if(!s->budget--) { s->failed_pc=0x0c06ba32u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[4])!=0);
goto P_0c06ba34;
P_0c06ba34: /* original 8914, guest PC 0x0c06ba34 */
if(!s->budget--) { s->failed_pc=0x0c06ba34u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06ba60; }
goto P_0c06ba36;
P_0c06ba36: /* original 902f, guest PC 0x0c06ba36 */
if(!s->budget--) { s->failed_pc=0x0c06ba36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ba98u,2);
goto P_0c06ba38;
P_0c06ba38: /* original 03ec, guest PC 0x0c06ba38 */
if(!s->budget--) { s->failed_pc=0x0c06ba38u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06ba3a;
P_0c06ba3a: /* original 7301, guest PC 0x0c06ba3a */
if(!s->budget--) { s->failed_pc=0x0c06ba3au; return 0; }
r[3]+=0x00000001u;
goto P_0c06ba3c;
P_0c06ba3c: /* original 0e34, guest PC 0x0c06ba3c */
if(!s->budget--) { s->failed_pc=0x0c06ba3cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06ba3e;
P_0c06ba3e: /* original 7010, guest PC 0x0c06ba3e */
if(!s->budget--) { s->failed_pc=0x0c06ba3eu; return 0; }
r[0]+=0x00000010u;
goto P_0c06ba40;
P_0c06ba40: /* original 02ec, guest PC 0x0c06ba40 */
if(!s->budget--) { s->failed_pc=0x0c06ba40u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06ba42;
P_0c06ba42: /* original 7201, guest PC 0x0c06ba42 */
if(!s->budget--) { s->failed_pc=0x0c06ba42u; return 0; }
r[2]+=0x00000001u;
goto P_0c06ba44;
P_0c06ba44: /* original 0e24, guest PC 0x0c06ba44 */
if(!s->budget--) { s->failed_pc=0x0c06ba44u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c06ba46;
P_0c06ba46: /* original 70ed, guest PC 0x0c06ba46 */
if(!s->budget--) { s->failed_pc=0x0c06ba46u; return 0; }
r[0]+=0xffffffedu;
goto P_0c06ba48;
P_0c06ba48: /* original 03ec, guest PC 0x0c06ba48 */
if(!s->budget--) { s->failed_pc=0x0c06ba48u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06ba4a;
P_0c06ba4a: /* original 2f32, guest PC 0x0c06ba4a */
if(!s->budget--) { s->failed_pc=0x0c06ba4au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06ba4c;
P_0c06ba4c: /* original 9025, guest PC 0x0c06ba4c */
if(!s->budget--) { s->failed_pc=0x0c06ba4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ba9au,2);
goto P_0c06ba4e;
P_0c06ba4e: /* original 02ec, guest PC 0x0c06ba4e */
if(!s->budget--) { s->failed_pc=0x0c06ba4eu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06ba50;
P_0c06ba50: /* original 1f21, guest PC 0x0c06ba50 */
if(!s->budget--) { s->failed_pc=0x0c06ba50u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c06ba52;
P_0c06ba52: /* original 63f2, guest PC 0x0c06ba52 */
if(!s->budget--) { s->failed_pc=0x0c06ba52u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06ba54;
P_0c06ba54: /* original 3322, guest PC 0x0c06ba54 */
if(!s->budget--) { s->failed_pc=0x0c06ba54u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c06ba56;
P_0c06ba56: /* original 8b01, guest PC 0x0c06ba56 */
if(!s->budget--) { s->failed_pc=0x0c06ba56u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ba5c; }
goto P_0c06ba58;
P_0c06ba58: /* original a143, guest PC 0x0c06ba58 */
if(!s->budget--) { s->failed_pc=0x0c06ba58u; return 0; }
goto P_0c06bce2;
P_0c06ba5a: /* original 0009, guest PC 0x0c06ba5a */
if(!s->budget--) { s->failed_pc=0x0c06ba5au; return 0; }
goto P_0c06ba5c;
P_0c06ba5c: /* original a02a, guest PC 0x0c06ba5c */
if(!s->budget--) { s->failed_pc=0x0c06ba5cu; return 0; }
goto P_0c06bab4;
P_0c06ba5e: /* original 0009, guest PC 0x0c06ba5e */
if(!s->budget--) { s->failed_pc=0x0c06ba5eu; return 0; }
goto P_0c06ba60;
P_0c06ba60: /* original 901c, guest PC 0x0c06ba60 */
if(!s->budget--) { s->failed_pc=0x0c06ba60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ba9cu,2);
goto P_0c06ba62;
P_0c06ba62: /* original 03ec, guest PC 0x0c06ba62 */
if(!s->budget--) { s->failed_pc=0x0c06ba62u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06ba64;
P_0c06ba64: /* original 7301, guest PC 0x0c06ba64 */
if(!s->budget--) { s->failed_pc=0x0c06ba64u; return 0; }
r[3]+=0x00000001u;
goto P_0c06ba66;
P_0c06ba66: /* original 0e34, guest PC 0x0c06ba66 */
if(!s->budget--) { s->failed_pc=0x0c06ba66u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06ba68;
P_0c06ba68: /* original 7014, guest PC 0x0c06ba68 */
if(!s->budget--) { s->failed_pc=0x0c06ba68u; return 0; }
r[0]+=0x00000014u;
goto P_0c06ba6a;
P_0c06ba6a: /* original 02ec, guest PC 0x0c06ba6a */
if(!s->budget--) { s->failed_pc=0x0c06ba6au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06ba6c;
P_0c06ba6c: /* original 7201, guest PC 0x0c06ba6c */
if(!s->budget--) { s->failed_pc=0x0c06ba6cu; return 0; }
r[2]+=0x00000001u;
goto P_0c06ba6e;
P_0c06ba6e: /* original 0e24, guest PC 0x0c06ba6e */
if(!s->budget--) { s->failed_pc=0x0c06ba6eu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c06ba70;
P_0c06ba70: /* original 70e4, guest PC 0x0c06ba70 */
if(!s->budget--) { s->failed_pc=0x0c06ba70u; return 0; }
r[0]+=0xffffffe4u;
goto P_0c06ba72;
P_0c06ba72: /* original 03ec, guest PC 0x0c06ba72 */
if(!s->budget--) { s->failed_pc=0x0c06ba72u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06ba74;
P_0c06ba74: /* original 6033, guest PC 0x0c06ba74 */
if(!s->budget--) { s->failed_pc=0x0c06ba74u; return 0; }
r[0]=r[3];
goto P_0c06ba76;
P_0c06ba76: /* original 8801, guest PC 0x0c06ba76 */
if(!s->budget--) { s->failed_pc=0x0c06ba76u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06ba78;
P_0c06ba78: /* original 1f31, guest PC 0x0c06ba78 */
if(!s->budget--) { s->failed_pc=0x0c06ba78u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c06ba7a;
P_0c06ba7a: /* original 8910, guest PC 0x0c06ba7a */
if(!s->budget--) { s->failed_pc=0x0c06ba7au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06ba9e; }
goto P_0c06ba7c;
P_0c06ba7c: /* original 9006, guest PC 0x0c06ba7c */
if(!s->budget--) { s->failed_pc=0x0c06ba7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ba8cu,2);
goto P_0c06ba7e;
P_0c06ba7e: /* original 03ec, guest PC 0x0c06ba7e */
if(!s->budget--) { s->failed_pc=0x0c06ba7eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06ba80;
P_0c06ba80: /* original a010, guest PC 0x0c06ba80 */
if(!s->budget--) { s->failed_pc=0x0c06ba80u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06baa4;
P_0c06ba82: /* original 2f32, guest PC 0x0c06ba82 */
if(!s->budget--) { s->failed_pc=0x0c06ba82u; return 0; }
write(ram,r[15],r[3],4);
if(!vf3_matrix_family(0x0c06ba84u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06ba84u; return 0; } return 1;
P_0c06ba9e: /* original 9094, guest PC 0x0c06ba9e */
if(!s->budget--) { s->failed_pc=0x0c06ba9eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bbcau,2);
goto P_0c06baa0;
P_0c06baa0: /* original 01ec, guest PC 0x0c06baa0 */
if(!s->budget--) { s->failed_pc=0x0c06baa0u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06baa2;
P_0c06baa2: /* original 2f12, guest PC 0x0c06baa2 */
if(!s->budget--) { s->failed_pc=0x0c06baa2u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c06baa4;
P_0c06baa4: /* original 9092, guest PC 0x0c06baa4 */
if(!s->budget--) { s->failed_pc=0x0c06baa4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bbccu,2);
goto P_0c06baa6;
P_0c06baa6: /* original 03ec, guest PC 0x0c06baa6 */
if(!s->budget--) { s->failed_pc=0x0c06baa6u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06baa8;
P_0c06baa8: /* original 1f31, guest PC 0x0c06baa8 */
if(!s->budget--) { s->failed_pc=0x0c06baa8u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c06baaa;
P_0c06baaa: /* original 62f2, guest PC 0x0c06baaa */
if(!s->budget--) { s->failed_pc=0x0c06baaau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c06baac;
P_0c06baac: /* original 3232, guest PC 0x0c06baac */
if(!s->budget--) { s->failed_pc=0x0c06baacu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[3])!=0);
goto P_0c06baae;
P_0c06baae: /* original 8b01, guest PC 0x0c06baae */
if(!s->budget--) { s->failed_pc=0x0c06baaeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06bab4; }
goto P_0c06bab0;
P_0c06bab0: /* original a117, guest PC 0x0c06bab0 */
if(!s->budget--) { s->failed_pc=0x0c06bab0u; return 0; }
goto P_0c06bce2;
P_0c06bab2: /* original 0009, guest PC 0x0c06bab2 */
if(!s->budget--) { s->failed_pc=0x0c06bab2u; return 0; }
goto P_0c06bab4;
P_0c06bab4: /* original 908b, guest PC 0x0c06bab4 */
if(!s->budget--) { s->failed_pc=0x0c06bab4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bbceu,2);
goto P_0c06bab6;
P_0c06bab6: /* original 03ec, guest PC 0x0c06bab6 */
if(!s->budget--) { s->failed_pc=0x0c06bab6u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bab8;
P_0c06bab8: /* original 6033, guest PC 0x0c06bab8 */
if(!s->budget--) { s->failed_pc=0x0c06bab8u; return 0; }
r[0]=r[3];
goto P_0c06baba;
P_0c06baba: /* original 8801, guest PC 0x0c06baba */
if(!s->budget--) { s->failed_pc=0x0c06babau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06babc;
P_0c06babc: /* original 1f31, guest PC 0x0c06babc */
if(!s->budget--) { s->failed_pc=0x0c06babcu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c06babe;
P_0c06babe: /* original 8b01, guest PC 0x0c06babe */
if(!s->budget--) { s->failed_pc=0x0c06babeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06bac4; }
goto P_0c06bac0;
P_0c06bac0: /* original a10f, guest PC 0x0c06bac0 */
if(!s->budget--) { s->failed_pc=0x0c06bac0u; return 0; }
goto P_0c06bce2;
P_0c06bac2: /* original 0009, guest PC 0x0c06bac2 */
if(!s->budget--) { s->failed_pc=0x0c06bac2u; return 0; }
goto P_0c06bac4;
P_0c06bac4: /* original 9084, guest PC 0x0c06bac4 */
if(!s->budget--) { s->failed_pc=0x0c06bac4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bbd0u,2);
goto P_0c06bac6;
P_0c06bac6: /* original 04ec, guest PC 0x0c06bac6 */
if(!s->budget--) { s->failed_pc=0x0c06bac6u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bac8;
P_0c06bac8: /* original 7003, guest PC 0x0c06bac8 */
if(!s->budget--) { s->failed_pc=0x0c06bac8u; return 0; }
r[0]+=0x00000003u;
goto P_0c06baca;
P_0c06baca: /* original 03ec, guest PC 0x0c06baca */
if(!s->budget--) { s->failed_pc=0x0c06bacau; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bacc;
P_0c06bacc: /* original 6043, guest PC 0x0c06bacc */
if(!s->budget--) { s->failed_pc=0x0c06baccu; return 0; }
r[0]=r[4];
goto P_0c06bace;
P_0c06bace: /* original 8801, guest PC 0x0c06bace */
if(!s->budget--) { s->failed_pc=0x0c06baceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06bad0;
P_0c06bad0: /* original 1f33, guest PC 0x0c06bad0 */
if(!s->budget--) { s->failed_pc=0x0c06bad0u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c06bad2;
P_0c06bad2: /* original 8b01, guest PC 0x0c06bad2 */
if(!s->budget--) { s->failed_pc=0x0c06bad2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06bad8; }
goto P_0c06bad4;
P_0c06bad4: /* original a082, guest PC 0x0c06bad4 */
if(!s->budget--) { s->failed_pc=0x0c06bad4u; return 0; }
goto P_0c06bbdc;
P_0c06bad6: /* original 0009, guest PC 0x0c06bad6 */
if(!s->budget--) { s->failed_pc=0x0c06bad6u; return 0; }
goto P_0c06bad8;
P_0c06bad8: /* original 53f1, guest PC 0x0c06bad8 */
if(!s->budget--) { s->failed_pc=0x0c06bad8u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06bada;
P_0c06bada: /* original 2338, guest PC 0x0c06bada */
if(!s->budget--) { s->failed_pc=0x0c06badau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06badc;
P_0c06badc: /* original 8939, guest PC 0x0c06badc */
if(!s->budget--) { s->failed_pc=0x0c06badcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06bb52; }
goto P_0c06bade;
P_0c06bade: /* original 62f3, guest PC 0x0c06bade */
if(!s->budget--) { s->failed_pc=0x0c06badeu; return 0; }
r[2]=r[15];
goto P_0c06bae0;
P_0c06bae0: /* original 7208, guest PC 0x0c06bae0 */
if(!s->budget--) { s->failed_pc=0x0c06bae0u; return 0; }
r[2]+=0x00000008u;
goto P_0c06bae2;
P_0c06bae2: /* original 2f26, guest PC 0x0c06bae2 */
if(!s->budget--) { s->failed_pc=0x0c06bae2u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06bae4;
P_0c06bae4: /* original 56f4, guest PC 0x0c06bae4 */
if(!s->budget--) { s->failed_pc=0x0c06bae4u; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c06bae6;
P_0c06bae6: /* original 65f3, guest PC 0x0c06bae6 */
if(!s->budget--) { s->failed_pc=0x0c06bae6u; return 0; }
r[5]=r[15];
goto P_0c06bae8;
P_0c06bae8: /* original 67f3, guest PC 0x0c06bae8 */
if(!s->budget--) { s->failed_pc=0x0c06bae8u; return 0; }
r[7]=r[15];
goto P_0c06baea;
P_0c06baea: /* original 7508, guest PC 0x0c06baea */
if(!s->budget--) { s->failed_pc=0x0c06baeau; return 0; }
r[5]+=0x00000008u;
goto P_0c06baec;
P_0c06baec: /* original 7704, guest PC 0x0c06baec */
if(!s->budget--) { s->failed_pc=0x0c06baecu; return 0; }
r[7]+=0x00000004u;
goto P_0c06baee;
P_0c06baee: /* original b10b, guest PC 0x0c06baee */
if(!s->budget--) { s->failed_pc=0x0c06baeeu; return 0; }
target=code_base|0x0c06bd08u; r[16]=code_base|0x0c06baf2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06baf2u) { target=s->pc; goto dispatch; }
goto P_0c06baf2;
P_0c06baf0: /* original 64d3, guest PC 0x0c06baf0 */
if(!s->budget--) { s->failed_pc=0x0c06baf0u; return 0; }
r[4]=r[13];
goto P_0c06baf2;
P_0c06baf2: /* original 7f04, guest PC 0x0c06baf2 */
if(!s->budget--) { s->failed_pc=0x0c06baf2u; return 0; }
r[15]+=0x00000004u;
goto P_0c06baf4;
P_0c06baf4: /* original 63f2, guest PC 0x0c06baf4 */
if(!s->budget--) { s->failed_pc=0x0c06baf4u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06baf6;
P_0c06baf6: /* original 52f1, guest PC 0x0c06baf6 */
if(!s->budget--) { s->failed_pc=0x0c06baf6u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c06baf8;
P_0c06baf8: /* original 3322, guest PC 0x0c06baf8 */
if(!s->budget--) { s->failed_pc=0x0c06baf8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c06bafa;
P_0c06bafa: /* original 8b19, guest PC 0x0c06bafa */
if(!s->budget--) { s->failed_pc=0x0c06bafau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06bb30; }
goto P_0c06bafc;
P_0c06bafc: /* original 51f1, guest PC 0x0c06bafc */
if(!s->budget--) { s->failed_pc=0x0c06bafcu; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c06bafe;
P_0c06bafe: /* original e500, guest PC 0x0c06bafe */
if(!s->budget--) { s->failed_pc=0x0c06bafeu; return 0; }
r[5]=0x00000000u;
goto P_0c06bb00;
P_0c06bb00: /* original 64d3, guest PC 0x0c06bb00 */
if(!s->budget--) { s->failed_pc=0x0c06bb00u; return 0; }
r[4]=r[13];
goto P_0c06bb02;
P_0c06bb02: /* original 2f12, guest PC 0x0c06bb02 */
if(!s->budget--) { s->failed_pc=0x0c06bb02u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c06bb04;
P_0c06bb04: /* original 9065, guest PC 0x0c06bb04 */
if(!s->budget--) { s->failed_pc=0x0c06bb04u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bbd2u,2);
goto P_0c06bb06;
P_0c06bb06: /* original 0eb4, guest PC 0x0c06bb06 */
if(!s->budget--) { s->failed_pc=0x0c06bb06u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06bb08;
P_0c06bb08: /* original 70ff, guest PC 0x0c06bb08 */
if(!s->budget--) { s->failed_pc=0x0c06bb08u; return 0; }
r[0]+=0xffffffffu;
goto P_0c06bb0a;
P_0c06bb0a: /* original 0eb4, guest PC 0x0c06bb0a */
if(!s->budget--) { s->failed_pc=0x0c06bb0au; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06bb0c;
P_0c06bb0c: /* original 7005, guest PC 0x0c06bb0c */
if(!s->budget--) { s->failed_pc=0x0c06bb0cu; return 0; }
r[0]+=0x00000005u;
goto P_0c06bb0e;
P_0c06bb0e: /* original 0eb4, guest PC 0x0c06bb0e */
if(!s->budget--) { s->failed_pc=0x0c06bb0eu; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06bb10;
P_0c06bb10: /* original 70ff, guest PC 0x0c06bb10 */
if(!s->budget--) { s->failed_pc=0x0c06bb10u; return 0; }
r[0]+=0xffffffffu;
goto P_0c06bb12;
P_0c06bb12: /* original 0eb4, guest PC 0x0c06bb12 */
if(!s->budget--) { s->failed_pc=0x0c06bb12u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06bb14;
P_0c06bb14: /* original 4c0b, guest PC 0x0c06bb14 */
if(!s->budget--) { s->failed_pc=0x0c06bb14u; return 0; }
target=r[12];
r[16]=code_base|0x0c06bb18u;
r[4]+=0x00000028u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bb18u) { target=s->pc; goto dispatch; }
goto P_0c06bb18;
P_0c06bb16: /* original 7428, guest PC 0x0c06bb16 */
if(!s->budget--) { s->failed_pc=0x0c06bb16u; return 0; }
r[4]+=0x00000028u;
goto P_0c06bb18;
P_0c06bb18: /* original 64d3, guest PC 0x0c06bb18 */
if(!s->budget--) { s->failed_pc=0x0c06bb18u; return 0; }
r[4]=r[13];
goto P_0c06bb1a;
P_0c06bb1a: /* original e500, guest PC 0x0c06bb1a */
if(!s->budget--) { s->failed_pc=0x0c06bb1au; return 0; }
r[5]=0x00000000u;
goto P_0c06bb1c;
P_0c06bb1c: /* original 4c0b, guest PC 0x0c06bb1c */
if(!s->budget--) { s->failed_pc=0x0c06bb1cu; return 0; }
target=r[12];
r[16]=code_base|0x0c06bb20u;
r[4]+=0x00000027u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bb20u) { target=s->pc; goto dispatch; }
goto P_0c06bb20;
P_0c06bb1e: /* original 7427, guest PC 0x0c06bb1e */
if(!s->budget--) { s->failed_pc=0x0c06bb1eu; return 0; }
r[4]+=0x00000027u;
goto P_0c06bb20;
P_0c06bb20: /* original 64d3, guest PC 0x0c06bb20 */
if(!s->budget--) { s->failed_pc=0x0c06bb20u; return 0; }
r[4]=r[13];
goto P_0c06bb22;
P_0c06bb22: /* original e500, guest PC 0x0c06bb22 */
if(!s->budget--) { s->failed_pc=0x0c06bb22u; return 0; }
r[5]=0x00000000u;
goto P_0c06bb24;
P_0c06bb24: /* original 4c0b, guest PC 0x0c06bb24 */
if(!s->budget--) { s->failed_pc=0x0c06bb24u; return 0; }
target=r[12];
r[16]=code_base|0x0c06bb28u;
r[4]+=0x0000002bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bb28u) { target=s->pc; goto dispatch; }
goto P_0c06bb28;
P_0c06bb26: /* original 742b, guest PC 0x0c06bb26 */
if(!s->budget--) { s->failed_pc=0x0c06bb26u; return 0; }
r[4]+=0x0000002bu;
goto P_0c06bb28;
P_0c06bb28: /* original 64d3, guest PC 0x0c06bb28 */
if(!s->budget--) { s->failed_pc=0x0c06bb28u; return 0; }
r[4]=r[13];
goto P_0c06bb2a;
P_0c06bb2a: /* original e500, guest PC 0x0c06bb2a */
if(!s->budget--) { s->failed_pc=0x0c06bb2au; return 0; }
r[5]=0x00000000u;
goto P_0c06bb2c;
P_0c06bb2c: /* original 4c0b, guest PC 0x0c06bb2c */
if(!s->budget--) { s->failed_pc=0x0c06bb2cu; return 0; }
target=r[12];
r[16]=code_base|0x0c06bb30u;
r[4]+=0x0000002au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bb30u) { target=s->pc; goto dispatch; }
goto P_0c06bb30;
P_0c06bb2e: /* original 742a, guest PC 0x0c06bb2e */
if(!s->budget--) { s->failed_pc=0x0c06bb2eu; return 0; }
r[4]+=0x0000002au;
goto P_0c06bb30;
P_0c06bb30: /* original 904f, guest PC 0x0c06bb30 */
if(!s->budget--) { s->failed_pc=0x0c06bb30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bbd2u,2);
goto P_0c06bb32;
P_0c06bb32: /* original 53f2, guest PC 0x0c06bb32 */
if(!s->budget--) { s->failed_pc=0x0c06bb32u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c06bb34;
P_0c06bb34: /* original 05ec, guest PC 0x0c06bb34 */
if(!s->budget--) { s->failed_pc=0x0c06bb34u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bb36;
P_0c06bb36: /* original 70fe, guest PC 0x0c06bb36 */
if(!s->budget--) { s->failed_pc=0x0c06bb36u; return 0; }
r[0]+=0xfffffffeu;
goto P_0c06bb38;
P_0c06bb38: /* original 04ec, guest PC 0x0c06bb38 */
if(!s->budget--) { s->failed_pc=0x0c06bb38u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bb3a;
P_0c06bb3a: /* original 3530, guest PC 0x0c06bb3a */
if(!s->budget--) { s->failed_pc=0x0c06bb3au; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[3])!=0);
goto P_0c06bb3c;
P_0c06bb3c: /* original 8b02, guest PC 0x0c06bb3c */
if(!s->budget--) { s->failed_pc=0x0c06bb3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06bb44; }
goto P_0c06bb3e;
P_0c06bb3e: /* original 61f2, guest PC 0x0c06bb3e */
if(!s->budget--) { s->failed_pc=0x0c06bb3eu; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c06bb40;
P_0c06bb40: /* original 3410, guest PC 0x0c06bb40 */
if(!s->budget--) { s->failed_pc=0x0c06bb40u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[1])!=0);
goto P_0c06bb42;
P_0c06bb42: /* original 8901, guest PC 0x0c06bb42 */
if(!s->budget--) { s->failed_pc=0x0c06bb42u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06bb48; }
goto P_0c06bb44;
P_0c06bb44: /* original 4a0b, guest PC 0x0c06bb44 */
if(!s->budget--) { s->failed_pc=0x0c06bb44u; return 0; }
target=r[10];
r[16]=code_base|0x0c06bb48u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bb48u) { target=s->pc; goto dispatch; }
goto P_0c06bb48;
P_0c06bb46: /* original 6493, guest PC 0x0c06bb46 */
if(!s->budget--) { s->failed_pc=0x0c06bb46u; return 0; }
r[4]=r[9];
goto P_0c06bb48;
P_0c06bb48: /* original 65f2, guest PC 0x0c06bb48 */
if(!s->budget--) { s->failed_pc=0x0c06bb48u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06bb4a;
P_0c06bb4a: /* original b129, guest PC 0x0c06bb4a */
if(!s->budget--) { s->failed_pc=0x0c06bb4au; return 0; }
target=code_base|0x0c06bda0u; r[16]=code_base|0x0c06bb4eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bb4eu) { target=s->pc; goto dispatch; }
goto P_0c06bb4e;
P_0c06bb4c: /* original 64d3, guest PC 0x0c06bb4c */
if(!s->budget--) { s->failed_pc=0x0c06bb4cu; return 0; }
r[4]=r[13];
goto P_0c06bb4e;
P_0c06bb4e: /* original a0c8, guest PC 0x0c06bb4e */
if(!s->budget--) { s->failed_pc=0x0c06bb4eu; return 0; }
goto P_0c06bce2;
P_0c06bb50: /* original 0009, guest PC 0x0c06bb50 */
if(!s->budget--) { s->failed_pc=0x0c06bb50u; return 0; }
goto P_0c06bb52;
P_0c06bb52: /* original 63f3, guest PC 0x0c06bb52 */
if(!s->budget--) { s->failed_pc=0x0c06bb52u; return 0; }
r[3]=r[15];
goto P_0c06bb54;
P_0c06bb54: /* original 7308, guest PC 0x0c06bb54 */
if(!s->budget--) { s->failed_pc=0x0c06bb54u; return 0; }
r[3]+=0x00000008u;
goto P_0c06bb56;
P_0c06bb56: /* original 2f36, guest PC 0x0c06bb56 */
if(!s->budget--) { s->failed_pc=0x0c06bb56u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06bb58;
P_0c06bb58: /* original 56f4, guest PC 0x0c06bb58 */
if(!s->budget--) { s->failed_pc=0x0c06bb58u; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c06bb5a;
P_0c06bb5a: /* original 65f3, guest PC 0x0c06bb5a */
if(!s->budget--) { s->failed_pc=0x0c06bb5au; return 0; }
r[5]=r[15];
goto P_0c06bb5c;
P_0c06bb5c: /* original 67f3, guest PC 0x0c06bb5c */
if(!s->budget--) { s->failed_pc=0x0c06bb5cu; return 0; }
r[7]=r[15];
goto P_0c06bb5e;
P_0c06bb5e: /* original 7508, guest PC 0x0c06bb5e */
if(!s->budget--) { s->failed_pc=0x0c06bb5eu; return 0; }
r[5]+=0x00000008u;
goto P_0c06bb60;
P_0c06bb60: /* original 7704, guest PC 0x0c06bb60 */
if(!s->budget--) { s->failed_pc=0x0c06bb60u; return 0; }
r[7]+=0x00000004u;
goto P_0c06bb62;
P_0c06bb62: /* original b134, guest PC 0x0c06bb62 */
if(!s->budget--) { s->failed_pc=0x0c06bb62u; return 0; }
target=code_base|0x0c06bdceu; r[16]=code_base|0x0c06bb66u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bb66u) { target=s->pc; goto dispatch; }
goto P_0c06bb66;
P_0c06bb64: /* original 64d3, guest PC 0x0c06bb64 */
if(!s->budget--) { s->failed_pc=0x0c06bb64u; return 0; }
r[4]=r[13];
goto P_0c06bb66;
P_0c06bb66: /* original 7f04, guest PC 0x0c06bb66 */
if(!s->budget--) { s->failed_pc=0x0c06bb66u; return 0; }
r[15]+=0x00000004u;
goto P_0c06bb68;
P_0c06bb68: /* original 63f2, guest PC 0x0c06bb68 */
if(!s->budget--) { s->failed_pc=0x0c06bb68u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06bb6a;
P_0c06bb6a: /* original 52f1, guest PC 0x0c06bb6a */
if(!s->budget--) { s->failed_pc=0x0c06bb6au; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c06bb6c;
P_0c06bb6c: /* original 3322, guest PC 0x0c06bb6c */
if(!s->budget--) { s->failed_pc=0x0c06bb6cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c06bb6e;
P_0c06bb6e: /* original 8b0d, guest PC 0x0c06bb6e */
if(!s->budget--) { s->failed_pc=0x0c06bb6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06bb8c; }
goto P_0c06bb70;
P_0c06bb70: /* original 51f1, guest PC 0x0c06bb70 */
if(!s->budget--) { s->failed_pc=0x0c06bb70u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c06bb72;
P_0c06bb72: /* original e500, guest PC 0x0c06bb72 */
if(!s->budget--) { s->failed_pc=0x0c06bb72u; return 0; }
r[5]=0x00000000u;
goto P_0c06bb74;
P_0c06bb74: /* original 64d3, guest PC 0x0c06bb74 */
if(!s->budget--) { s->failed_pc=0x0c06bb74u; return 0; }
r[4]=r[13];
goto P_0c06bb76;
P_0c06bb76: /* original 2f12, guest PC 0x0c06bb76 */
if(!s->budget--) { s->failed_pc=0x0c06bb76u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c06bb78;
P_0c06bb78: /* original 902c, guest PC 0x0c06bb78 */
if(!s->budget--) { s->failed_pc=0x0c06bb78u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bbd4u,2);
goto P_0c06bb7a;
P_0c06bb7a: /* original 0eb4, guest PC 0x0c06bb7a */
if(!s->budget--) { s->failed_pc=0x0c06bb7au; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06bb7c;
P_0c06bb7c: /* original 7004, guest PC 0x0c06bb7c */
if(!s->budget--) { s->failed_pc=0x0c06bb7cu; return 0; }
r[0]+=0x00000004u;
goto P_0c06bb7e;
P_0c06bb7e: /* original 0eb4, guest PC 0x0c06bb7e */
if(!s->budget--) { s->failed_pc=0x0c06bb7eu; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06bb80;
P_0c06bb80: /* original 4c0b, guest PC 0x0c06bb80 */
if(!s->budget--) { s->failed_pc=0x0c06bb80u; return 0; }
target=r[12];
r[16]=code_base|0x0c06bb84u;
r[4]+=0x00000027u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bb84u) { target=s->pc; goto dispatch; }
goto P_0c06bb84;
P_0c06bb82: /* original 7427, guest PC 0x0c06bb82 */
if(!s->budget--) { s->failed_pc=0x0c06bb82u; return 0; }
r[4]+=0x00000027u;
goto P_0c06bb84;
P_0c06bb84: /* original 64d3, guest PC 0x0c06bb84 */
if(!s->budget--) { s->failed_pc=0x0c06bb84u; return 0; }
r[4]=r[13];
goto P_0c06bb86;
P_0c06bb86: /* original e500, guest PC 0x0c06bb86 */
if(!s->budget--) { s->failed_pc=0x0c06bb86u; return 0; }
r[5]=0x00000000u;
goto P_0c06bb88;
P_0c06bb88: /* original 4c0b, guest PC 0x0c06bb88 */
if(!s->budget--) { s->failed_pc=0x0c06bb88u; return 0; }
target=r[12];
r[16]=code_base|0x0c06bb8cu;
r[4]+=0x0000002au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bb8cu) { target=s->pc; goto dispatch; }
goto P_0c06bb8c;
P_0c06bb8a: /* original 742a, guest PC 0x0c06bb8a */
if(!s->budget--) { s->failed_pc=0x0c06bb8au; return 0; }
r[4]+=0x0000002au;
goto P_0c06bb8c;
P_0c06bb8c: /* original 9022, guest PC 0x0c06bb8c */
if(!s->budget--) { s->failed_pc=0x0c06bb8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bbd4u,2);
goto P_0c06bb8e;
P_0c06bb8e: /* original 53f2, guest PC 0x0c06bb8e */
if(!s->budget--) { s->failed_pc=0x0c06bb8eu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c06bb90;
P_0c06bb90: /* original 04ec, guest PC 0x0c06bb90 */
if(!s->budget--) { s->failed_pc=0x0c06bb90u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bb92;
P_0c06bb92: /* original 70ff, guest PC 0x0c06bb92 */
if(!s->budget--) { s->failed_pc=0x0c06bb92u; return 0; }
r[0]+=0xffffffffu;
goto P_0c06bb94;
P_0c06bb94: /* original 05ec, guest PC 0x0c06bb94 */
if(!s->budget--) { s->failed_pc=0x0c06bb94u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bb96;
P_0c06bb96: /* original 3430, guest PC 0x0c06bb96 */
if(!s->budget--) { s->failed_pc=0x0c06bb96u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c06bb98;
P_0c06bb98: /* original 8b02, guest PC 0x0c06bb98 */
if(!s->budget--) { s->failed_pc=0x0c06bb98u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06bba0; }
goto P_0c06bb9a;
P_0c06bb9a: /* original 61f2, guest PC 0x0c06bb9a */
if(!s->budget--) { s->failed_pc=0x0c06bb9au; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c06bb9c;
P_0c06bb9c: /* original 3510, guest PC 0x0c06bb9c */
if(!s->budget--) { s->failed_pc=0x0c06bb9cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[1])!=0);
goto P_0c06bb9e;
P_0c06bb9e: /* original 8901, guest PC 0x0c06bb9e */
if(!s->budget--) { s->failed_pc=0x0c06bb9eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06bba4; }
goto P_0c06bba0;
P_0c06bba0: /* original 4a0b, guest PC 0x0c06bba0 */
if(!s->budget--) { s->failed_pc=0x0c06bba0u; return 0; }
target=r[10];
r[16]=code_base|0x0c06bba4u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bba4u) { target=s->pc; goto dispatch; }
goto P_0c06bba4;
P_0c06bba2: /* original 6493, guest PC 0x0c06bba2 */
if(!s->budget--) { s->failed_pc=0x0c06bba2u; return 0; }
r[4]=r[9];
goto P_0c06bba4;
P_0c06bba4: /* original 9017, guest PC 0x0c06bba4 */
if(!s->budget--) { s->failed_pc=0x0c06bba4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bbd6u,2);
goto P_0c06bba6;
P_0c06bba6: /* original 63f2, guest PC 0x0c06bba6 */
if(!s->budget--) { s->failed_pc=0x0c06bba6u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06bba8;
P_0c06bba8: /* original 05ec, guest PC 0x0c06bba8 */
if(!s->budget--) { s->failed_pc=0x0c06bba8u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bbaa;
P_0c06bbaa: /* original 9015, guest PC 0x0c06bbaa */
if(!s->budget--) { s->failed_pc=0x0c06bbaau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bbd8u,2);
goto P_0c06bbac;
P_0c06bbac: /* original 3358, guest PC 0x0c06bbac */
if(!s->budget--) { s->failed_pc=0x0c06bbacu; return 0; }
r[3]-=r[5];
goto P_0c06bbae;
P_0c06bbae: /* original 04ec, guest PC 0x0c06bbae */
if(!s->budget--) { s->failed_pc=0x0c06bbaeu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bbb0;
P_0c06bbb0: /* original 6533, guest PC 0x0c06bbb0 */
if(!s->budget--) { s->failed_pc=0x0c06bbb0u; return 0; }
r[5]=r[3];
goto P_0c06bbb2;
P_0c06bbb2: /* original 345c, guest PC 0x0c06bbb2 */
if(!s->budget--) { s->failed_pc=0x0c06bbb2u; return 0; }
r[4]+=r[5];
goto P_0c06bbb4;
P_0c06bbb4: /* original 0e44, guest PC 0x0c06bbb4 */
if(!s->budget--) { s->failed_pc=0x0c06bbb4u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06bbb6;
P_0c06bbb6: /* original 64d3, guest PC 0x0c06bbb6 */
if(!s->budget--) { s->failed_pc=0x0c06bbb6u; return 0; }
r[4]=r[13];
goto P_0c06bbb8;
P_0c06bbb8: /* original 900d, guest PC 0x0c06bbb8 */
if(!s->budget--) { s->failed_pc=0x0c06bbb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bbd6u,2);
goto P_0c06bbba;
P_0c06bbba: /* original 63f2, guest PC 0x0c06bbba */
if(!s->budget--) { s->failed_pc=0x0c06bbbau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06bbbc;
P_0c06bbbc: /* original 0e34, guest PC 0x0c06bbbc */
if(!s->budget--) { s->failed_pc=0x0c06bbbcu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06bbbe;
P_0c06bbbe: /* original 65f2, guest PC 0x0c06bbbe */
if(!s->budget--) { s->failed_pc=0x0c06bbbeu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06bbc0;
P_0c06bbc0: /* original 4c0b, guest PC 0x0c06bbc0 */
if(!s->budget--) { s->failed_pc=0x0c06bbc0u; return 0; }
target=r[12];
r[16]=code_base|0x0c06bbc4u;
r[4]+=0x00000026u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bbc4u) { target=s->pc; goto dispatch; }
goto P_0c06bbc4;
P_0c06bbc2: /* original 7426, guest PC 0x0c06bbc2 */
if(!s->budget--) { s->failed_pc=0x0c06bbc2u; return 0; }
r[4]+=0x00000026u;
goto P_0c06bbc4;
P_0c06bbc4: /* original 9009, guest PC 0x0c06bbc4 */
if(!s->budget--) { s->failed_pc=0x0c06bbc4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bbdau,2);
goto P_0c06bbc6;
P_0c06bbc6: /* original a08c, guest PC 0x0c06bbc6 */
if(!s->budget--) { s->failed_pc=0x0c06bbc6u; return 0; }
write(ram,r[14]+r[0],r[8],1);
goto P_0c06bce2;
P_0c06bbc8: /* original 0e84, guest PC 0x0c06bbc8 */
if(!s->budget--) { s->failed_pc=0x0c06bbc8u; return 0; }
write(ram,r[14]+r[0],r[8],1);
if(!vf3_matrix_family(0x0c06bbcau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06bbcau; return 0; } return 1;
P_0c06bbdc: /* original 52f1, guest PC 0x0c06bbdc */
if(!s->budget--) { s->failed_pc=0x0c06bbdcu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c06bbde;
P_0c06bbde: /* original 2228, guest PC 0x0c06bbde */
if(!s->budget--) { s->failed_pc=0x0c06bbdeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c06bbe0;
P_0c06bbe0: /* original 894c, guest PC 0x0c06bbe0 */
if(!s->budget--) { s->failed_pc=0x0c06bbe0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06bc7c; }
goto P_0c06bbe2;
P_0c06bbe2: /* original 9089, guest PC 0x0c06bbe2 */
if(!s->budget--) { s->failed_pc=0x0c06bbe2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bcf8u,2);
goto P_0c06bbe4;
P_0c06bbe4: /* original 5bf3, guest PC 0x0c06bbe4 */
if(!s->budget--) { s->failed_pc=0x0c06bbe4u; return 0; }
r[11]=read(ram,r[15]+12,4);
goto P_0c06bbe6;
P_0c06bbe6: /* original 03ec, guest PC 0x0c06bbe6 */
if(!s->budget--) { s->failed_pc=0x0c06bbe6u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bbe8;
P_0c06bbe8: /* original 64b3, guest PC 0x0c06bbe8 */
if(!s->budget--) { s->failed_pc=0x0c06bbe8u; return 0; }
r[4]=r[11];
goto P_0c06bbea;
P_0c06bbea: /* original 343c, guest PC 0x0c06bbea */
if(!s->budget--) { s->failed_pc=0x0c06bbeau; return 0; }
r[4]+=r[3];
goto P_0c06bbec;
P_0c06bbec: /* original 2f32, guest PC 0x0c06bbec */
if(!s->budget--) { s->failed_pc=0x0c06bbecu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06bbee;
P_0c06bbee: /* original 6143, guest PC 0x0c06bbee */
if(!s->budget--) { s->failed_pc=0x0c06bbeeu; return 0; }
r[1]=r[4];
goto P_0c06bbf0;
P_0c06bbf0: /* original 1f32, guest PC 0x0c06bbf0 */
if(!s->budget--) { s->failed_pc=0x0c06bbf0u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c06bbf2;
P_0c06bbf2: /* original d244, guest PC 0x0c06bbf2 */
if(!s->budget--) { s->failed_pc=0x0c06bbf2u; return 0; }
r[2]=read(ram,0x0c06bd04u,4);
goto P_0c06bbf4;
P_0c06bbf4: /* original 420b, guest PC 0x0c06bbf4 */
if(!s->budget--) { s->failed_pc=0x0c06bbf4u; return 0; }
target=r[2];
r[16]=code_base|0x0c06bbf8u;
r[0]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bbf8u) { target=s->pc; goto dispatch; }
goto P_0c06bbf8;
P_0c06bbf6: /* original 50f1, guest PC 0x0c06bbf6 */
if(!s->budget--) { s->failed_pc=0x0c06bbf6u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c06bbf8;
P_0c06bbf8: /* original 2f02, guest PC 0x0c06bbf8 */
if(!s->budget--) { s->failed_pc=0x0c06bbf8u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06bbfa;
P_0c06bbfa: /* original 6843, guest PC 0x0c06bbfa */
if(!s->budget--) { s->failed_pc=0x0c06bbfau; return 0; }
r[8]=r[4];
goto P_0c06bbfc;
P_0c06bbfc: /* original 55f1, guest PC 0x0c06bbfc */
if(!s->budget--) { s->failed_pc=0x0c06bbfcu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c06bbfe;
P_0c06bbfe: /* original 64d3, guest PC 0x0c06bbfe */
if(!s->budget--) { s->failed_pc=0x0c06bbfeu; return 0; }
r[4]=r[13];
goto P_0c06bc00;
P_0c06bc00: /* original 0507, guest PC 0x0c06bc00 */
if(!s->budget--) { s->failed_pc=0x0c06bc00u; return 0; }
r[19]=r[5]*r[0];
goto P_0c06bc02;
P_0c06bc02: /* original 9079, guest PC 0x0c06bc02 */
if(!s->budget--) { s->failed_pc=0x0c06bc02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bcf8u,2);
goto P_0c06bc04;
P_0c06bc04: /* original 051a, guest PC 0x0c06bc04 */
if(!s->budget--) { s->failed_pc=0x0c06bc04u; return 0; }
r[5]=r[19];
goto P_0c06bc06;
P_0c06bc06: /* original 3858, guest PC 0x0c06bc06 */
if(!s->budget--) { s->failed_pc=0x0c06bc06u; return 0; }
r[8]-=r[5];
goto P_0c06bc08;
P_0c06bc08: /* original 6583, guest PC 0x0c06bc08 */
if(!s->budget--) { s->failed_pc=0x0c06bc08u; return 0; }
r[5]=r[8];
goto P_0c06bc0a;
P_0c06bc0a: /* original 0e84, guest PC 0x0c06bc0a */
if(!s->budget--) { s->failed_pc=0x0c06bc0au; return 0; }
write(ram,r[14]+r[0],r[8],1);
goto P_0c06bc0c;
P_0c06bc0c: /* original 4c0b, guest PC 0x0c06bc0c */
if(!s->budget--) { s->failed_pc=0x0c06bc0cu; return 0; }
target=r[12];
r[16]=code_base|0x0c06bc10u;
r[4]+=0x0000002bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bc10u) { target=s->pc; goto dispatch; }
goto P_0c06bc10;
P_0c06bc0e: /* original 742b, guest PC 0x0c06bc0e */
if(!s->budget--) { s->failed_pc=0x0c06bc0eu; return 0; }
r[4]+=0x0000002bu;
goto P_0c06bc10;
P_0c06bc10: /* original 9073, guest PC 0x0c06bc10 */
if(!s->budget--) { s->failed_pc=0x0c06bc10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bcfau,2);
goto P_0c06bc12;
P_0c06bc12: /* original 63f2, guest PC 0x0c06bc12 */
if(!s->budget--) { s->failed_pc=0x0c06bc12u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06bc14;
P_0c06bc14: /* original 04ec, guest PC 0x0c06bc14 */
if(!s->budget--) { s->failed_pc=0x0c06bc14u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bc16;
P_0c06bc16: /* original 70f7, guest PC 0x0c06bc16 */
if(!s->budget--) { s->failed_pc=0x0c06bc16u; return 0; }
r[0]+=0xfffffff7u;
goto P_0c06bc18;
P_0c06bc18: /* original 3b3c, guest PC 0x0c06bc18 */
if(!s->budget--) { s->failed_pc=0x0c06bc18u; return 0; }
r[11]+=r[3];
goto P_0c06bc1a;
P_0c06bc1a: /* original 03ec, guest PC 0x0c06bc1a */
if(!s->budget--) { s->failed_pc=0x0c06bc1au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bc1c;
P_0c06bc1c: /* original 3b4c, guest PC 0x0c06bc1c */
if(!s->budget--) { s->failed_pc=0x0c06bc1cu; return 0; }
r[11]+=r[4];
goto P_0c06bc1e;
P_0c06bc1e: /* original 61b3, guest PC 0x0c06bc1e */
if(!s->budget--) { s->failed_pc=0x0c06bc1eu; return 0; }
r[1]=r[11];
goto P_0c06bc20;
P_0c06bc20: /* original 2f32, guest PC 0x0c06bc20 */
if(!s->budget--) { s->failed_pc=0x0c06bc20u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06bc22;
P_0c06bc22: /* original d238, guest PC 0x0c06bc22 */
if(!s->budget--) { s->failed_pc=0x0c06bc22u; return 0; }
r[2]=read(ram,0x0c06bd04u,4);
goto P_0c06bc24;
P_0c06bc24: /* original 420b, guest PC 0x0c06bc24 */
if(!s->budget--) { s->failed_pc=0x0c06bc24u; return 0; }
target=r[2];
r[16]=code_base|0x0c06bc28u;
r[0]=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bc28u) { target=s->pc; goto dispatch; }
goto P_0c06bc28;
P_0c06bc26: /* original 6033, guest PC 0x0c06bc26 */
if(!s->budget--) { s->failed_pc=0x0c06bc26u; return 0; }
r[0]=r[3];
goto P_0c06bc28;
P_0c06bc28: /* original 6803, guest PC 0x0c06bc28 */
if(!s->budget--) { s->failed_pc=0x0c06bc28u; return 0; }
r[8]=r[0];
goto P_0c06bc2a;
P_0c06bc2a: /* original 9066, guest PC 0x0c06bc2a */
if(!s->budget--) { s->failed_pc=0x0c06bc2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bcfau,2);
goto P_0c06bc2c;
P_0c06bc2c: /* original 0387, guest PC 0x0c06bc2c */
if(!s->budget--) { s->failed_pc=0x0c06bc2cu; return 0; }
r[19]=r[3]*r[8];
goto P_0c06bc2e;
P_0c06bc2e: /* original 041a, guest PC 0x0c06bc2e */
if(!s->budget--) { s->failed_pc=0x0c06bc2eu; return 0; }
r[4]=r[19];
goto P_0c06bc30;
P_0c06bc30: /* original 3b48, guest PC 0x0c06bc30 */
if(!s->budget--) { s->failed_pc=0x0c06bc30u; return 0; }
r[11]-=r[4];
goto P_0c06bc32;
P_0c06bc32: /* original 64d3, guest PC 0x0c06bc32 */
if(!s->budget--) { s->failed_pc=0x0c06bc32u; return 0; }
r[4]=r[13];
goto P_0c06bc34;
P_0c06bc34: /* original 65b3, guest PC 0x0c06bc34 */
if(!s->budget--) { s->failed_pc=0x0c06bc34u; return 0; }
r[5]=r[11];
goto P_0c06bc36;
P_0c06bc36: /* original 0eb4, guest PC 0x0c06bc36 */
if(!s->budget--) { s->failed_pc=0x0c06bc36u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06bc38;
P_0c06bc38: /* original 4c0b, guest PC 0x0c06bc38 */
if(!s->budget--) { s->failed_pc=0x0c06bc38u; return 0; }
target=r[12];
r[16]=code_base|0x0c06bc3cu;
r[4]+=0x0000002au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bc3cu) { target=s->pc; goto dispatch; }
goto P_0c06bc3c;
P_0c06bc3a: /* original 742a, guest PC 0x0c06bc3a */
if(!s->budget--) { s->failed_pc=0x0c06bc3au; return 0; }
r[4]+=0x0000002au;
goto P_0c06bc3c;
P_0c06bc3c: /* original 905e, guest PC 0x0c06bc3c */
if(!s->budget--) { s->failed_pc=0x0c06bc3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bcfcu,2);
goto P_0c06bc3e;
P_0c06bc3e: /* original 03ec, guest PC 0x0c06bc3e */
if(!s->budget--) { s->failed_pc=0x0c06bc3eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bc40;
P_0c06bc40: /* original 338c, guest PC 0x0c06bc40 */
if(!s->budget--) { s->failed_pc=0x0c06bc40u; return 0; }
r[3]+=r[8];
goto P_0c06bc42;
P_0c06bc42: /* original 2f32, guest PC 0x0c06bc42 */
if(!s->budget--) { s->failed_pc=0x0c06bc42u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06bc44;
P_0c06bc44: /* original 905b, guest PC 0x0c06bc44 */
if(!s->budget--) { s->failed_pc=0x0c06bc44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bcfeu,2);
goto P_0c06bc46;
P_0c06bc46: /* original 02ec, guest PC 0x0c06bc46 */
if(!s->budget--) { s->failed_pc=0x0c06bc46u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bc48;
P_0c06bc48: /* original 1f21, guest PC 0x0c06bc48 */
if(!s->budget--) { s->failed_pc=0x0c06bc48u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c06bc4a;
P_0c06bc4a: /* original 63f2, guest PC 0x0c06bc4a */
if(!s->budget--) { s->failed_pc=0x0c06bc4au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06bc4c;
P_0c06bc4c: /* original 3322, guest PC 0x0c06bc4c */
if(!s->budget--) { s->failed_pc=0x0c06bc4cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c06bc4e;
P_0c06bc4e: /* original 8b04, guest PC 0x0c06bc4e */
if(!s->budget--) { s->failed_pc=0x0c06bc4eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06bc5a; }
goto P_0c06bc50;
P_0c06bc50: /* original 55f1, guest PC 0x0c06bc50 */
if(!s->budget--) { s->failed_pc=0x0c06bc50u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c06bc52;
P_0c06bc52: /* original b0ef, guest PC 0x0c06bc52 */
if(!s->budget--) { s->failed_pc=0x0c06bc52u; return 0; }
target=code_base|0x0c06be34u; r[16]=code_base|0x0c06bc56u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bc56u) { target=s->pc; goto dispatch; }
goto P_0c06bc56;
P_0c06bc54: /* original 64d3, guest PC 0x0c06bc54 */
if(!s->budget--) { s->failed_pc=0x0c06bc54u; return 0; }
r[4]=r[13];
goto P_0c06bc56;
P_0c06bc56: /* original 52f1, guest PC 0x0c06bc56 */
if(!s->budget--) { s->failed_pc=0x0c06bc56u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c06bc58;
P_0c06bc58: /* original 2f22, guest PC 0x0c06bc58 */
if(!s->budget--) { s->failed_pc=0x0c06bc58u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c06bc5a;
P_0c06bc5a: /* original 904d, guest PC 0x0c06bc5a */
if(!s->budget--) { s->failed_pc=0x0c06bc5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bcf8u,2);
goto P_0c06bc5c;
P_0c06bc5c: /* original 53f2, guest PC 0x0c06bc5c */
if(!s->budget--) { s->failed_pc=0x0c06bc5cu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c06bc5e;
P_0c06bc5e: /* original 05ec, guest PC 0x0c06bc5e */
if(!s->budget--) { s->failed_pc=0x0c06bc5eu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bc60;
P_0c06bc60: /* original 70fe, guest PC 0x0c06bc60 */
if(!s->budget--) { s->failed_pc=0x0c06bc60u; return 0; }
r[0]+=0xfffffffeu;
goto P_0c06bc62;
P_0c06bc62: /* original 04ec, guest PC 0x0c06bc62 */
if(!s->budget--) { s->failed_pc=0x0c06bc62u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bc64;
P_0c06bc64: /* original 3530, guest PC 0x0c06bc64 */
if(!s->budget--) { s->failed_pc=0x0c06bc64u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[3])!=0);
goto P_0c06bc66;
P_0c06bc66: /* original 8b02, guest PC 0x0c06bc66 */
if(!s->budget--) { s->failed_pc=0x0c06bc66u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06bc6e; }
goto P_0c06bc68;
P_0c06bc68: /* original 61f2, guest PC 0x0c06bc68 */
if(!s->budget--) { s->failed_pc=0x0c06bc68u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c06bc6a;
P_0c06bc6a: /* original 3410, guest PC 0x0c06bc6a */
if(!s->budget--) { s->failed_pc=0x0c06bc6au; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[1])!=0);
goto P_0c06bc6c;
P_0c06bc6c: /* original 8901, guest PC 0x0c06bc6c */
if(!s->budget--) { s->failed_pc=0x0c06bc6cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06bc72; }
goto P_0c06bc6e;
P_0c06bc6e: /* original 4a0b, guest PC 0x0c06bc6e */
if(!s->budget--) { s->failed_pc=0x0c06bc6eu; return 0; }
target=r[10];
r[16]=code_base|0x0c06bc72u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bc72u) { target=s->pc; goto dispatch; }
goto P_0c06bc72;
P_0c06bc70: /* original 6493, guest PC 0x0c06bc70 */
if(!s->budget--) { s->failed_pc=0x0c06bc70u; return 0; }
r[4]=r[9];
goto P_0c06bc72;
P_0c06bc72: /* original 65f2, guest PC 0x0c06bc72 */
if(!s->budget--) { s->failed_pc=0x0c06bc72u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06bc74;
P_0c06bc74: /* original b0f4, guest PC 0x0c06bc74 */
if(!s->budget--) { s->failed_pc=0x0c06bc74u; return 0; }
target=code_base|0x0c06be60u; r[16]=code_base|0x0c06bc78u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bc78u) { target=s->pc; goto dispatch; }
goto P_0c06bc78;
P_0c06bc76: /* original 64d3, guest PC 0x0c06bc76 */
if(!s->budget--) { s->failed_pc=0x0c06bc76u; return 0; }
r[4]=r[13];
goto P_0c06bc78;
P_0c06bc78: /* original a033, guest PC 0x0c06bc78 */
if(!s->budget--) { s->failed_pc=0x0c06bc78u; return 0; }
goto P_0c06bce2;
P_0c06bc7a: /* original 0009, guest PC 0x0c06bc7a */
if(!s->budget--) { s->failed_pc=0x0c06bc7au; return 0; }
goto P_0c06bc7c;
P_0c06bc7c: /* original 903d, guest PC 0x0c06bc7c */
if(!s->budget--) { s->failed_pc=0x0c06bc7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bcfau,2);
goto P_0c06bc7e;
P_0c06bc7e: /* original 54f3, guest PC 0x0c06bc7e */
if(!s->budget--) { s->failed_pc=0x0c06bc7eu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c06bc80;
P_0c06bc80: /* original 03ec, guest PC 0x0c06bc80 */
if(!s->budget--) { s->failed_pc=0x0c06bc80u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bc82;
P_0c06bc82: /* original 343c, guest PC 0x0c06bc82 */
if(!s->budget--) { s->failed_pc=0x0c06bc82u; return 0; }
r[4]+=r[3];
goto P_0c06bc84;
P_0c06bc84: /* original 2f32, guest PC 0x0c06bc84 */
if(!s->budget--) { s->failed_pc=0x0c06bc84u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06bc86;
P_0c06bc86: /* original 903b, guest PC 0x0c06bc86 */
if(!s->budget--) { s->failed_pc=0x0c06bc86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bd00u,2);
goto P_0c06bc88;
P_0c06bc88: /* original 6143, guest PC 0x0c06bc88 */
if(!s->budget--) { s->failed_pc=0x0c06bc88u; return 0; }
r[1]=r[4];
goto P_0c06bc8a;
P_0c06bc8a: /* original 03ec, guest PC 0x0c06bc8a */
if(!s->budget--) { s->failed_pc=0x0c06bc8au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bc8c;
P_0c06bc8c: /* original 2f32, guest PC 0x0c06bc8c */
if(!s->budget--) { s->failed_pc=0x0c06bc8cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06bc8e;
P_0c06bc8e: /* original d21d, guest PC 0x0c06bc8e */
if(!s->budget--) { s->failed_pc=0x0c06bc8eu; return 0; }
r[2]=read(ram,0x0c06bd04u,4);
goto P_0c06bc90;
P_0c06bc90: /* original 420b, guest PC 0x0c06bc90 */
if(!s->budget--) { s->failed_pc=0x0c06bc90u; return 0; }
target=r[2];
r[16]=code_base|0x0c06bc94u;
r[0]=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bc94u) { target=s->pc; goto dispatch; }
goto P_0c06bc94;
P_0c06bc92: /* original 6033, guest PC 0x0c06bc92 */
if(!s->budget--) { s->failed_pc=0x0c06bc92u; return 0; }
r[0]=r[3];
goto P_0c06bc94;
P_0c06bc94: /* original 6503, guest PC 0x0c06bc94 */
if(!s->budget--) { s->failed_pc=0x0c06bc94u; return 0; }
r[5]=r[0];
goto P_0c06bc96;
P_0c06bc96: /* original 1f03, guest PC 0x0c06bc96 */
if(!s->budget--) { s->failed_pc=0x0c06bc96u; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c06bc98;
P_0c06bc98: /* original 0357, guest PC 0x0c06bc98 */
if(!s->budget--) { s->failed_pc=0x0c06bc98u; return 0; }
r[19]=r[3]*r[5];
goto P_0c06bc9a;
P_0c06bc9a: /* original 051a, guest PC 0x0c06bc9a */
if(!s->budget--) { s->failed_pc=0x0c06bc9au; return 0; }
r[5]=r[19];
goto P_0c06bc9c;
P_0c06bc9c: /* original 3458, guest PC 0x0c06bc9c */
if(!s->budget--) { s->failed_pc=0x0c06bc9cu; return 0; }
r[4]-=r[5];
goto P_0c06bc9e;
P_0c06bc9e: /* original 1f44, guest PC 0x0c06bc9e */
if(!s->budget--) { s->failed_pc=0x0c06bc9eu; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c06bca0;
P_0c06bca0: /* original 6343, guest PC 0x0c06bca0 */
if(!s->budget--) { s->failed_pc=0x0c06bca0u; return 0; }
r[3]=r[4];
goto P_0c06bca2;
P_0c06bca2: /* original 902a, guest PC 0x0c06bca2 */
if(!s->budget--) { s->failed_pc=0x0c06bca2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bcfau,2);
goto P_0c06bca4;
P_0c06bca4: /* original 64d3, guest PC 0x0c06bca4 */
if(!s->budget--) { s->failed_pc=0x0c06bca4u; return 0; }
r[4]=r[13];
goto P_0c06bca6;
P_0c06bca6: /* original 0e34, guest PC 0x0c06bca6 */
if(!s->budget--) { s->failed_pc=0x0c06bca6u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06bca8;
P_0c06bca8: /* original 55f4, guest PC 0x0c06bca8 */
if(!s->budget--) { s->failed_pc=0x0c06bca8u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c06bcaa;
P_0c06bcaa: /* original 4c0b, guest PC 0x0c06bcaa */
if(!s->budget--) { s->failed_pc=0x0c06bcaau; return 0; }
target=r[12];
r[16]=code_base|0x0c06bcaeu;
r[4]+=0x0000002au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bcaeu) { target=s->pc; goto dispatch; }
goto P_0c06bcae;
P_0c06bcac: /* original 742a, guest PC 0x0c06bcac */
if(!s->budget--) { s->failed_pc=0x0c06bcacu; return 0; }
r[4]+=0x0000002au;
goto P_0c06bcae;
P_0c06bcae: /* original 9025, guest PC 0x0c06bcae */
if(!s->budget--) { s->failed_pc=0x0c06bcaeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bcfcu,2);
goto P_0c06bcb0;
P_0c06bcb0: /* original 03ec, guest PC 0x0c06bcb0 */
if(!s->budget--) { s->failed_pc=0x0c06bcb0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bcb2;
P_0c06bcb2: /* original 2f32, guest PC 0x0c06bcb2 */
if(!s->budget--) { s->failed_pc=0x0c06bcb2u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06bcb4;
P_0c06bcb4: /* original 52f3, guest PC 0x0c06bcb4 */
if(!s->budget--) { s->failed_pc=0x0c06bcb4u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c06bcb6;
P_0c06bcb6: /* original 332c, guest PC 0x0c06bcb6 */
if(!s->budget--) { s->failed_pc=0x0c06bcb6u; return 0; }
r[3]+=r[2];
goto P_0c06bcb8;
P_0c06bcb8: /* original 2f32, guest PC 0x0c06bcb8 */
if(!s->budget--) { s->failed_pc=0x0c06bcb8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06bcba;
P_0c06bcba: /* original 9020, guest PC 0x0c06bcba */
if(!s->budget--) { s->failed_pc=0x0c06bcbau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bcfeu,2);
goto P_0c06bcbc;
P_0c06bcbc: /* original 02ec, guest PC 0x0c06bcbc */
if(!s->budget--) { s->failed_pc=0x0c06bcbcu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bcbe;
P_0c06bcbe: /* original 1f21, guest PC 0x0c06bcbe */
if(!s->budget--) { s->failed_pc=0x0c06bcbeu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c06bcc0;
P_0c06bcc0: /* original 63f2, guest PC 0x0c06bcc0 */
if(!s->budget--) { s->failed_pc=0x0c06bcc0u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06bcc2;
P_0c06bcc2: /* original 3322, guest PC 0x0c06bcc2 */
if(!s->budget--) { s->failed_pc=0x0c06bcc2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c06bcc4;
P_0c06bcc4: /* original 8b06, guest PC 0x0c06bcc4 */
if(!s->budget--) { s->failed_pc=0x0c06bcc4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06bcd4; }
goto P_0c06bcc6;
P_0c06bcc6: /* original e500, guest PC 0x0c06bcc6 */
if(!s->budget--) { s->failed_pc=0x0c06bcc6u; return 0; }
r[5]=0x00000000u;
goto P_0c06bcc8;
P_0c06bcc8: /* original 64d3, guest PC 0x0c06bcc8 */
if(!s->budget--) { s->failed_pc=0x0c06bcc8u; return 0; }
r[4]=r[13];
goto P_0c06bcca;
P_0c06bcca: /* original 2f22, guest PC 0x0c06bcca */
if(!s->budget--) { s->failed_pc=0x0c06bccau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c06bccc;
P_0c06bccc: /* original 9015, guest PC 0x0c06bccc */
if(!s->budget--) { s->failed_pc=0x0c06bcccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bcfau,2);
goto P_0c06bcce;
P_0c06bcce: /* original 0eb4, guest PC 0x0c06bcce */
if(!s->budget--) { s->failed_pc=0x0c06bcceu; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06bcd0;
P_0c06bcd0: /* original 4c0b, guest PC 0x0c06bcd0 */
if(!s->budget--) { s->failed_pc=0x0c06bcd0u; return 0; }
target=r[12];
r[16]=code_base|0x0c06bcd4u;
r[4]+=0x0000002au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bcd4u) { target=s->pc; goto dispatch; }
goto P_0c06bcd4;
P_0c06bcd2: /* original 742a, guest PC 0x0c06bcd2 */
if(!s->budget--) { s->failed_pc=0x0c06bcd2u; return 0; }
r[4]+=0x0000002au;
goto P_0c06bcd4;
P_0c06bcd4: /* original 65f2, guest PC 0x0c06bcd4 */
if(!s->budget--) { s->failed_pc=0x0c06bcd4u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06bcd6;
P_0c06bcd6: /* original b0c3, guest PC 0x0c06bcd6 */
if(!s->budget--) { s->failed_pc=0x0c06bcd6u; return 0; }
target=code_base|0x0c06be60u; r[16]=code_base|0x0c06bcdau;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bcdau) { target=s->pc; goto dispatch; }
goto P_0c06bcda;
P_0c06bcd8: /* original 64d3, guest PC 0x0c06bcd8 */
if(!s->budget--) { s->failed_pc=0x0c06bcd8u; return 0; }
r[4]=r[13];
goto P_0c06bcda;
P_0c06bcda: /* original 9012, guest PC 0x0c06bcda */
if(!s->budget--) { s->failed_pc=0x0c06bcdau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bd02u,2);
goto P_0c06bcdc;
P_0c06bcdc: /* original 0e84, guest PC 0x0c06bcdc */
if(!s->budget--) { s->failed_pc=0x0c06bcdcu; return 0; }
write(ram,r[14]+r[0],r[8],1);
goto P_0c06bcde;
P_0c06bcde: /* original 4a0b, guest PC 0x0c06bcde */
if(!s->budget--) { s->failed_pc=0x0c06bcdeu; return 0; }
target=r[10];
r[16]=code_base|0x0c06bce2u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bce2u) { target=s->pc; goto dispatch; }
goto P_0c06bce2;
P_0c06bce0: /* original 6493, guest PC 0x0c06bce0 */
if(!s->budget--) { s->failed_pc=0x0c06bce0u; return 0; }
r[4]=r[9];
goto P_0c06bce2;
P_0c06bce2: /* original 7f14, guest PC 0x0c06bce2 */
if(!s->budget--) { s->failed_pc=0x0c06bce2u; return 0; }
r[15]+=0x00000014u;
goto P_0c06bce4;
P_0c06bce4: /* original 4f16, guest PC 0x0c06bce4 */
if(!s->budget--) { s->failed_pc=0x0c06bce4u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c06bce6;
P_0c06bce6: /* original 4f26, guest PC 0x0c06bce6 */
if(!s->budget--) { s->failed_pc=0x0c06bce6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06bce8;
P_0c06bce8: /* original 68f6, guest PC 0x0c06bce8 */
if(!s->budget--) { s->failed_pc=0x0c06bce8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06bcea;
P_0c06bcea: /* original 69f6, guest PC 0x0c06bcea */
if(!s->budget--) { s->failed_pc=0x0c06bceau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06bcec;
P_0c06bcec: /* original 6af6, guest PC 0x0c06bcec */
if(!s->budget--) { s->failed_pc=0x0c06bcecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06bcee;
P_0c06bcee: /* original 6bf6, guest PC 0x0c06bcee */
if(!s->budget--) { s->failed_pc=0x0c06bceeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06bcf0;
P_0c06bcf0: /* original 6cf6, guest PC 0x0c06bcf0 */
if(!s->budget--) { s->failed_pc=0x0c06bcf0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06bcf2;
P_0c06bcf2: /* original 6df6, guest PC 0x0c06bcf2 */
if(!s->budget--) { s->failed_pc=0x0c06bcf2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06bcf4;
P_0c06bcf4: /* original 000b, guest PC 0x0c06bcf4 */
if(!s->budget--) { s->failed_pc=0x0c06bcf4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06bcf6: /* original 6ef6, guest PC 0x0c06bcf6 */
if(!s->budget--) { s->failed_pc=0x0c06bcf6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06bcf8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06bcf8u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
