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
int vf3_away_batch124_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09e6b2u: goto P_0c09e6b2;
case 0x0c09e6b4u: goto P_0c09e6b4;
case 0x0c09e6b6u: goto P_0c09e6b6;
case 0x0c09e6b8u: goto P_0c09e6b8;
case 0x0c09e6bau: goto P_0c09e6ba;
case 0x0c09e6bcu: goto P_0c09e6bc;
case 0x0c09e6beu: goto P_0c09e6be;
case 0x0c09e6c0u: goto P_0c09e6c0;
case 0x0c09e6c2u: goto P_0c09e6c2;
case 0x0c09e6c4u: goto P_0c09e6c4;
case 0x0c09e6c6u: goto P_0c09e6c6;
case 0x0c09e6c8u: goto P_0c09e6c8;
case 0x0c09e6cau: goto P_0c09e6ca;
case 0x0c09e6ccu: goto P_0c09e6cc;
case 0x0c09e6ceu: goto P_0c09e6ce;
case 0x0c09e6d0u: goto P_0c09e6d0;
case 0x0c09e6d2u: goto P_0c09e6d2;
case 0x0c09e6d4u: goto P_0c09e6d4;
case 0x0c09e6d6u: goto P_0c09e6d6;
case 0x0c09e6d8u: goto P_0c09e6d8;
case 0x0c09e6dau: goto P_0c09e6da;
case 0x0c09e6dcu: goto P_0c09e6dc;
case 0x0c09e6deu: goto P_0c09e6de;
case 0x0c09e6e0u: goto P_0c09e6e0;
case 0x0c09e6e2u: goto P_0c09e6e2;
case 0x0c09e6e4u: goto P_0c09e6e4;
case 0x0c09e6e6u: goto P_0c09e6e6;
case 0x0c09e6e8u: goto P_0c09e6e8;
case 0x0c09e6eau: goto P_0c09e6ea;
case 0x0c09e6ecu: goto P_0c09e6ec;
case 0x0c09e6eeu: goto P_0c09e6ee;
case 0x0c09e6f0u: goto P_0c09e6f0;
case 0x0c09e6f2u: goto P_0c09e6f2;
case 0x0c09e6f4u: goto P_0c09e6f4;
case 0x0c09e6f6u: goto P_0c09e6f6;
case 0x0c09e6f8u: goto P_0c09e6f8;
case 0x0c09e6fau: goto P_0c09e6fa;
case 0x0c09e6fcu: goto P_0c09e6fc;
case 0x0c09e6feu: goto P_0c09e6fe;
case 0x0c09e700u: goto P_0c09e700;
case 0x0c09e702u: goto P_0c09e702;
case 0x0c09e704u: goto P_0c09e704;
case 0x0c09e706u: goto P_0c09e706;
case 0x0c09e708u: goto P_0c09e708;
case 0x0c09e70au: goto P_0c09e70a;
case 0x0c09e70cu: goto P_0c09e70c;
case 0x0c09e70eu: goto P_0c09e70e;
case 0x0c09e710u: goto P_0c09e710;
case 0x0c09e712u: goto P_0c09e712;
case 0x0c09e714u: goto P_0c09e714;
case 0x0c09e716u: goto P_0c09e716;
case 0x0c09e718u: goto P_0c09e718;
case 0x0c09e71au: goto P_0c09e71a;
case 0x0c09e71cu: goto P_0c09e71c;
case 0x0c09e71eu: goto P_0c09e71e;
case 0x0c09e720u: goto P_0c09e720;
case 0x0c09e722u: goto P_0c09e722;
case 0x0c09e724u: goto P_0c09e724;
case 0x0c09e726u: goto P_0c09e726;
case 0x0c09e728u: goto P_0c09e728;
case 0x0c09e72au: goto P_0c09e72a;
case 0x0c09e72cu: goto P_0c09e72c;
case 0x0c09e72eu: goto P_0c09e72e;
case 0x0c09e730u: goto P_0c09e730;
case 0x0c09e732u: goto P_0c09e732;
case 0x0c09e734u: goto P_0c09e734;
case 0x0c09e736u: goto P_0c09e736;
case 0x0c09e738u: goto P_0c09e738;
case 0x0c09e73au: goto P_0c09e73a;
case 0x0c09e73cu: goto P_0c09e73c;
case 0x0c09e73eu: goto P_0c09e73e;
case 0x0c09e740u: goto P_0c09e740;
case 0x0c09e742u: goto P_0c09e742;
case 0x0c09e744u: goto P_0c09e744;
case 0x0c09e746u: goto P_0c09e746;
case 0x0c09e748u: goto P_0c09e748;
case 0x0c09e74au: goto P_0c09e74a;
case 0x0c09e74cu: goto P_0c09e74c;
case 0x0c09e74eu: goto P_0c09e74e;
case 0x0c09e750u: goto P_0c09e750;
case 0x0c09e752u: goto P_0c09e752;
case 0x0c09e754u: goto P_0c09e754;
case 0x0c09e756u: goto P_0c09e756;
case 0x0c09e758u: goto P_0c09e758;
case 0x0c09e75au: goto P_0c09e75a;
case 0x0c09e75cu: goto P_0c09e75c;
case 0x0c09e75eu: goto P_0c09e75e;
case 0x0c09e760u: goto P_0c09e760;
case 0x0c09e762u: goto P_0c09e762;
case 0x0c09e764u: goto P_0c09e764;
case 0x0c09e766u: goto P_0c09e766;
case 0x0c09e768u: goto P_0c09e768;
case 0x0c09e76au: goto P_0c09e76a;
case 0x0c09e76cu: goto P_0c09e76c;
case 0x0c09e76eu: goto P_0c09e76e;
case 0x0c09e770u: goto P_0c09e770;
case 0x0c09e772u: goto P_0c09e772;
case 0x0c09e774u: goto P_0c09e774;
case 0x0c09e776u: goto P_0c09e776;
case 0x0c09e778u: goto P_0c09e778;
case 0x0c09e77au: goto P_0c09e77a;
case 0x0c09e77cu: goto P_0c09e77c;
case 0x0c09e77eu: goto P_0c09e77e;
case 0x0c09e780u: goto P_0c09e780;
case 0x0c09e782u: goto P_0c09e782;
case 0x0c09e784u: goto P_0c09e784;
case 0x0c09e786u: goto P_0c09e786;
case 0x0c09e788u: goto P_0c09e788;
case 0x0c09e78au: goto P_0c09e78a;
case 0x0c09e78cu: goto P_0c09e78c;
case 0x0c09e78eu: goto P_0c09e78e;
case 0x0c09e790u: goto P_0c09e790;
case 0x0c09e792u: goto P_0c09e792;
case 0x0c09e794u: goto P_0c09e794;
case 0x0c09e796u: goto P_0c09e796;
case 0x0c09e798u: goto P_0c09e798;
case 0x0c09e79au: goto P_0c09e79a;
case 0x0c09e79cu: goto P_0c09e79c;
case 0x0c09e79eu: goto P_0c09e79e;
case 0x0c09e7a0u: goto P_0c09e7a0;
case 0x0c09e7a2u: goto P_0c09e7a2;
case 0x0c09e7a4u: goto P_0c09e7a4;
case 0x0c09e7a6u: goto P_0c09e7a6;
case 0x0c09e7a8u: goto P_0c09e7a8;
case 0x0c09e7aau: goto P_0c09e7aa;
case 0x0c09e7acu: goto P_0c09e7ac;
case 0x0c09e7aeu: goto P_0c09e7ae;
case 0x0c09e7b0u: goto P_0c09e7b0;
case 0x0c09e7b2u: goto P_0c09e7b2;
case 0x0c09e7b4u: goto P_0c09e7b4;
case 0x0c09e7b6u: goto P_0c09e7b6;
case 0x0c09e7b8u: goto P_0c09e7b8;
case 0x0c09e7bau: goto P_0c09e7ba;
case 0x0c09e7bcu: goto P_0c09e7bc;
case 0x0c09e7beu: goto P_0c09e7be;
case 0x0c09e7c0u: goto P_0c09e7c0;
case 0x0c09e7c2u: goto P_0c09e7c2;
case 0x0c09e7c4u: goto P_0c09e7c4;
case 0x0c09e7c6u: goto P_0c09e7c6;
case 0x0c09e7c8u: goto P_0c09e7c8;
case 0x0c09e7cau: goto P_0c09e7ca;
case 0x0c09e7ccu: goto P_0c09e7cc;
case 0x0c09e7ceu: goto P_0c09e7ce;
case 0x0c09e7d0u: goto P_0c09e7d0;
case 0x0c09e7d2u: goto P_0c09e7d2;
case 0x0c09e7d4u: goto P_0c09e7d4;
case 0x0c09e80cu: goto P_0c09e80c;
case 0x0c09e80eu: goto P_0c09e80e;
case 0x0c09e810u: goto P_0c09e810;
case 0x0c09e812u: goto P_0c09e812;
case 0x0c09e814u: goto P_0c09e814;
case 0x0c09e816u: goto P_0c09e816;
case 0x0c09e818u: goto P_0c09e818;
case 0x0c09e81au: goto P_0c09e81a;
case 0x0c09e81cu: goto P_0c09e81c;
case 0x0c09e81eu: goto P_0c09e81e;
case 0x0c09e820u: goto P_0c09e820;
case 0x0c09e822u: goto P_0c09e822;
case 0x0c09e824u: goto P_0c09e824;
case 0x0c09e826u: goto P_0c09e826;
case 0x0c09e828u: goto P_0c09e828;
case 0x0c09e82au: goto P_0c09e82a;
case 0x0c09e82cu: goto P_0c09e82c;
case 0x0c09e82eu: goto P_0c09e82e;
case 0x0c09e830u: goto P_0c09e830;
case 0x0c09e832u: goto P_0c09e832;
case 0x0c09e834u: goto P_0c09e834;
case 0x0c09e836u: goto P_0c09e836;
case 0x0c09e838u: goto P_0c09e838;
case 0x0c09e83au: goto P_0c09e83a;
case 0x0c09e83cu: goto P_0c09e83c;
case 0x0c09e83eu: goto P_0c09e83e;
case 0x0c09e840u: goto P_0c09e840;
case 0x0c09e842u: goto P_0c09e842;
case 0x0c09e844u: goto P_0c09e844;
case 0x0c09e846u: goto P_0c09e846;
case 0x0c09e848u: goto P_0c09e848;
case 0x0c09e84au: goto P_0c09e84a;
case 0x0c09e84cu: goto P_0c09e84c;
case 0x0c09e84eu: goto P_0c09e84e;
case 0x0c09e850u: goto P_0c09e850;
case 0x0c09e852u: goto P_0c09e852;
case 0x0c09e854u: goto P_0c09e854;
case 0x0c09e856u: goto P_0c09e856;
case 0x0c09e858u: goto P_0c09e858;
case 0x0c09e85au: goto P_0c09e85a;
case 0x0c09e85cu: goto P_0c09e85c;
case 0x0c09e85eu: goto P_0c09e85e;
case 0x0c09e860u: goto P_0c09e860;
case 0x0c09e862u: goto P_0c09e862;
case 0x0c09e864u: goto P_0c09e864;
case 0x0c09e866u: goto P_0c09e866;
case 0x0c09e868u: goto P_0c09e868;
case 0x0c09e86au: goto P_0c09e86a;
case 0x0c09e86cu: goto P_0c09e86c;
case 0x0c09e86eu: goto P_0c09e86e;
case 0x0c09e870u: goto P_0c09e870;
case 0x0c09e872u: goto P_0c09e872;
case 0x0c09e874u: goto P_0c09e874;
case 0x0c09e876u: goto P_0c09e876;
case 0x0c09e88cu: goto P_0c09e88c;
case 0x0c09e88eu: goto P_0c09e88e;
case 0x0c09e890u: goto P_0c09e890;
case 0x0c09e892u: goto P_0c09e892;
case 0x0c09e894u: goto P_0c09e894;
case 0x0c09e896u: goto P_0c09e896;
case 0x0c09e898u: goto P_0c09e898;
case 0x0c09e89au: goto P_0c09e89a;
case 0x0c09e89cu: goto P_0c09e89c;
case 0x0c09e89eu: goto P_0c09e89e;
case 0x0c09e8a0u: goto P_0c09e8a0;
case 0x0c09e8a2u: goto P_0c09e8a2;
case 0x0c09e8a4u: goto P_0c09e8a4;
case 0x0c09e8a6u: goto P_0c09e8a6;
case 0x0c09e8a8u: goto P_0c09e8a8;
case 0x0c09e8aau: goto P_0c09e8aa;
case 0x0c09e8acu: goto P_0c09e8ac;
case 0x0c09e8aeu: goto P_0c09e8ae;
case 0x0c09e8b0u: goto P_0c09e8b0;
case 0x0c09e8b2u: goto P_0c09e8b2;
case 0x0c09e8b4u: goto P_0c09e8b4;
case 0x0c09e8b6u: goto P_0c09e8b6;
case 0x0c09e8b8u: goto P_0c09e8b8;
case 0x0c09e8bau: goto P_0c09e8ba;
case 0x0c09e8bcu: goto P_0c09e8bc;
case 0x0c09e8beu: goto P_0c09e8be;
case 0x0c09e8c0u: goto P_0c09e8c0;
case 0x0c09e8c2u: goto P_0c09e8c2;
case 0x0c09e8c4u: goto P_0c09e8c4;
case 0x0c09e8c6u: goto P_0c09e8c6;
case 0x0c09e8c8u: goto P_0c09e8c8;
case 0x0c09e8cau: goto P_0c09e8ca;
case 0x0c09e8ccu: goto P_0c09e8cc;
case 0x0c09e8ceu: goto P_0c09e8ce;
case 0x0c09e8d0u: goto P_0c09e8d0;
case 0x0c09e8d2u: goto P_0c09e8d2;
case 0x0c09e8d4u: goto P_0c09e8d4;
case 0x0c09e8d6u: goto P_0c09e8d6;
case 0x0c09e8d8u: goto P_0c09e8d8;
case 0x0c09e8dau: goto P_0c09e8da;
case 0x0c09e8dcu: goto P_0c09e8dc;
case 0x0c09e8deu: goto P_0c09e8de;
case 0x0c09e8e0u: goto P_0c09e8e0;
case 0x0c09e8e2u: goto P_0c09e8e2;
case 0x0c09e8e4u: goto P_0c09e8e4;
case 0x0c09e8e6u: goto P_0c09e8e6;
case 0x0c09e8e8u: goto P_0c09e8e8;
case 0x0c09e8eau: goto P_0c09e8ea;
case 0x0c09e8ecu: goto P_0c09e8ec;
case 0x0c09e8eeu: goto P_0c09e8ee;
case 0x0c09e8f0u: goto P_0c09e8f0;
case 0x0c09e8f2u: goto P_0c09e8f2;
case 0x0c09e8f4u: goto P_0c09e8f4;
case 0x0c09e8f6u: goto P_0c09e8f6;
case 0x0c09e8f8u: goto P_0c09e8f8;
case 0x0c09e8fau: goto P_0c09e8fa;
case 0x0c09e8fcu: goto P_0c09e8fc;
case 0x0c09e8feu: goto P_0c09e8fe;
case 0x0c09e900u: goto P_0c09e900;
case 0x0c09e902u: goto P_0c09e902;
case 0x0c09e904u: goto P_0c09e904;
case 0x0c09e906u: goto P_0c09e906;
case 0x0c09e908u: goto P_0c09e908;
case 0x0c09e90au: goto P_0c09e90a;
case 0x0c09e90cu: goto P_0c09e90c;
case 0x0c09e90eu: goto P_0c09e90e;
case 0x0c09e910u: goto P_0c09e910;
case 0x0c09e912u: goto P_0c09e912;
case 0x0c09e914u: goto P_0c09e914;
case 0x0c09e916u: goto P_0c09e916;
case 0x0c09e918u: goto P_0c09e918;
case 0x0c09e91au: goto P_0c09e91a;
case 0x0c09e91cu: goto P_0c09e91c;
case 0x0c09e91eu: goto P_0c09e91e;
case 0x0c09e920u: goto P_0c09e920;
case 0x0c09e922u: goto P_0c09e922;
case 0x0c09e924u: goto P_0c09e924;
case 0x0c09e926u: goto P_0c09e926;
case 0x0c09e928u: goto P_0c09e928;
case 0x0c09e92au: goto P_0c09e92a;
case 0x0c09e92cu: goto P_0c09e92c;
case 0x0c09e92eu: goto P_0c09e92e;
case 0x0c09e930u: goto P_0c09e930;
case 0x0c09e932u: goto P_0c09e932;
case 0x0c09e934u: goto P_0c09e934;
case 0x0c09e936u: goto P_0c09e936;
case 0x0c09e938u: goto P_0c09e938;
case 0x0c09e93au: goto P_0c09e93a;
case 0x0c09e93cu: goto P_0c09e93c;
case 0x0c09e93eu: goto P_0c09e93e;
case 0x0c09e940u: goto P_0c09e940;
case 0x0c09e942u: goto P_0c09e942;
case 0x0c09e944u: goto P_0c09e944;
case 0x0c09e946u: goto P_0c09e946;
case 0x0c09e948u: goto P_0c09e948;
case 0x0c09e94au: goto P_0c09e94a;
case 0x0c09e94cu: goto P_0c09e94c;
case 0x0c09e94eu: goto P_0c09e94e;
case 0x0c09e950u: goto P_0c09e950;
case 0x0c09e952u: goto P_0c09e952;
case 0x0c09e954u: goto P_0c09e954;
case 0x0c09e956u: goto P_0c09e956;
case 0x0c09e958u: goto P_0c09e958;
case 0x0c09e95au: goto P_0c09e95a;
case 0x0c09e95cu: goto P_0c09e95c;
case 0x0c09e95eu: goto P_0c09e95e;
case 0x0c09e960u: goto P_0c09e960;
case 0x0c09e962u: goto P_0c09e962;
case 0x0c09e964u: goto P_0c09e964;
case 0x0c09e966u: goto P_0c09e966;
case 0x0c09e968u: goto P_0c09e968;
case 0x0c09e96au: goto P_0c09e96a;
case 0x0c09e96cu: goto P_0c09e96c;
case 0x0c09e96eu: goto P_0c09e96e;
case 0x0c09e970u: goto P_0c09e970;
case 0x0c09e972u: goto P_0c09e972;
case 0x0c09e974u: goto P_0c09e974;
case 0x0c09e976u: goto P_0c09e976;
case 0x0c09e978u: goto P_0c09e978;
case 0x0c09e97au: goto P_0c09e97a;
case 0x0c09e97cu: goto P_0c09e97c;
case 0x0c09e97eu: goto P_0c09e97e;
case 0x0c09e980u: goto P_0c09e980;
case 0x0c09e982u: goto P_0c09e982;
case 0x0c09e984u: goto P_0c09e984;
case 0x0c09e986u: goto P_0c09e986;
case 0x0c09e988u: goto P_0c09e988;
case 0x0c09e98au: goto P_0c09e98a;
case 0x0c09e98cu: goto P_0c09e98c;
case 0x0c09e98eu: goto P_0c09e98e;
case 0x0c09e990u: goto P_0c09e990;
case 0x0c09e992u: goto P_0c09e992;
case 0x0c09e994u: goto P_0c09e994;
case 0x0c09e996u: goto P_0c09e996;
case 0x0c09e998u: goto P_0c09e998;
case 0x0c09e99au: goto P_0c09e99a;
case 0x0c09e99cu: goto P_0c09e99c;
case 0x0c09e99eu: goto P_0c09e99e;
case 0x0c09e9a0u: goto P_0c09e9a0;
case 0x0c09e9a2u: goto P_0c09e9a2;
case 0x0c09e9a4u: goto P_0c09e9a4;
case 0x0c09e9a6u: goto P_0c09e9a6;
case 0x0c09e9a8u: goto P_0c09e9a8;
case 0x0c09e9aau: goto P_0c09e9aa;
case 0x0c09e9acu: goto P_0c09e9ac;
case 0x0c09e9aeu: goto P_0c09e9ae;
case 0x0c09e9b0u: goto P_0c09e9b0;
case 0x0c09e9b2u: goto P_0c09e9b2;
case 0x0c09e9b4u: goto P_0c09e9b4;
case 0x0c09e9b6u: goto P_0c09e9b6;
case 0x0c09e9b8u: goto P_0c09e9b8;
case 0x0c09e9bau: goto P_0c09e9ba;
case 0x0c09e9bcu: goto P_0c09e9bc;
case 0x0c09e9beu: goto P_0c09e9be;
case 0x0c09e9c0u: goto P_0c09e9c0;
case 0x0c09e9c2u: goto P_0c09e9c2;
case 0x0c09e9c4u: goto P_0c09e9c4;
case 0x0c09e9c6u: goto P_0c09e9c6;
case 0x0c09e9c8u: goto P_0c09e9c8;
case 0x0c09e9cau: goto P_0c09e9ca;
case 0x0c09e9ccu: goto P_0c09e9cc;
case 0x0c09e9ceu: goto P_0c09e9ce;
case 0x0c09e9d0u: goto P_0c09e9d0;
case 0x0c09e9d2u: goto P_0c09e9d2;
case 0x0c09e9d4u: goto P_0c09e9d4;
case 0x0c09e9d6u: goto P_0c09e9d6;
case 0x0c09e9d8u: goto P_0c09e9d8;
case 0x0c09e9dau: goto P_0c09e9da;
case 0x0c09e9dcu: goto P_0c09e9dc;
case 0x0c09e9deu: goto P_0c09e9de;
case 0x0c09e9e0u: goto P_0c09e9e0;
case 0x0c09e9e2u: goto P_0c09e9e2;
case 0x0c09e9e4u: goto P_0c09e9e4;
case 0x0c09e9e6u: goto P_0c09e9e6;
case 0x0c09e9e8u: goto P_0c09e9e8;
case 0x0c09e9eau: goto P_0c09e9ea;
case 0x0c09e9ecu: goto P_0c09e9ec;
case 0x0c09e9eeu: goto P_0c09e9ee;
case 0x0c09e9f0u: goto P_0c09e9f0;
case 0x0c09e9f2u: goto P_0c09e9f2;
case 0x0c09e9f4u: goto P_0c09e9f4;
case 0x0c09e9f6u: goto P_0c09e9f6;
case 0x0c09e9f8u: goto P_0c09e9f8;
case 0x0c09e9fau: goto P_0c09e9fa;
case 0x0c09e9fcu: goto P_0c09e9fc;
case 0x0c09e9feu: goto P_0c09e9fe;
case 0x0c09ea00u: goto P_0c09ea00;
case 0x0c09ea02u: goto P_0c09ea02;
case 0x0c09ea04u: goto P_0c09ea04;
case 0x0c09ea06u: goto P_0c09ea06;
case 0x0c09ea08u: goto P_0c09ea08;
case 0x0c09ea0au: goto P_0c09ea0a;
case 0x0c09ea0cu: goto P_0c09ea0c;
case 0x0c09ea0eu: goto P_0c09ea0e;
case 0x0c09ea10u: goto P_0c09ea10;
case 0x0c09ea12u: goto P_0c09ea12;
case 0x0c09ea14u: goto P_0c09ea14;
case 0x0c09ea16u: goto P_0c09ea16;
case 0x0c09ea18u: goto P_0c09ea18;
case 0x0c09ea1au: goto P_0c09ea1a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09e6b2: /* original 2fe6, guest PC 0x0c09e6b2 */
if(!s->budget--) { s->failed_pc=0x0c09e6b2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09e6b4;
P_0c09e6b4: /* original 2fd6, guest PC 0x0c09e6b4 */
if(!s->budget--) { s->failed_pc=0x0c09e6b4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09e6b6;
P_0c09e6b6: /* original 2fc6, guest PC 0x0c09e6b6 */
if(!s->budget--) { s->failed_pc=0x0c09e6b6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09e6b8;
P_0c09e6b8: /* original 2fb6, guest PC 0x0c09e6b8 */
if(!s->budget--) { s->failed_pc=0x0c09e6b8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09e6ba;
P_0c09e6ba: /* original 2fa6, guest PC 0x0c09e6ba */
if(!s->budget--) { s->failed_pc=0x0c09e6bau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09e6bc;
P_0c09e6bc: /* original 6a53, guest PC 0x0c09e6bc */
if(!s->budget--) { s->failed_pc=0x0c09e6bcu; return 0; }
r[10]=r[5];
goto P_0c09e6be;
P_0c09e6be: /* original 2f96, guest PC 0x0c09e6be */
if(!s->budget--) { s->failed_pc=0x0c09e6beu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09e6c0;
P_0c09e6c0: /* original 2f86, guest PC 0x0c09e6c0 */
if(!s->budget--) { s->failed_pc=0x0c09e6c0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09e6c2;
P_0c09e6c2: /* original fffb, guest PC 0x0c09e6c2 */
if(!s->budget--) { s->failed_pc=0x0c09e6c2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09e6c4;
P_0c09e6c4: /* original ffeb, guest PC 0x0c09e6c4 */
if(!s->budget--) { s->failed_pc=0x0c09e6c4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c09e6c6;
P_0c09e6c6: /* original ffdb, guest PC 0x0c09e6c6 */
if(!s->budget--) { s->failed_pc=0x0c09e6c6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c09e6c8;
P_0c09e6c8: /* original 4f22, guest PC 0x0c09e6c8 */
if(!s->budget--) { s->failed_pc=0x0c09e6c8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09e6ca;
P_0c09e6ca: /* original 9086, guest PC 0x0c09e6ca */
if(!s->budget--) { s->failed_pc=0x0c09e6cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e7dau,2);
goto P_0c09e6cc;
P_0c09e6cc: /* original 3f0c, guest PC 0x0c09e6cc */
if(!s->budget--) { s->failed_pc=0x0c09e6ccu; return 0; }
r[15]+=r[0];
goto P_0c09e6ce;
P_0c09e6ce: /* original 1f45, guest PC 0x0c09e6ce */
if(!s->budget--) { s->failed_pc=0x0c09e6ceu; return 0; }
write(ram,r[15]+20,r[4],4);
goto P_0c09e6d0;
P_0c09e6d0: /* original 1f61, guest PC 0x0c09e6d0 */
if(!s->budget--) { s->failed_pc=0x0c09e6d0u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c09e6d2;
P_0c09e6d2: /* original 2f72, guest PC 0x0c09e6d2 */
if(!s->budget--) { s->failed_pc=0x0c09e6d2u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c09e6d4;
P_0c09e6d4: /* original 9082, guest PC 0x0c09e6d4 */
if(!s->budget--) { s->failed_pc=0x0c09e6d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e7dcu,2);
goto P_0c09e6d6;
P_0c09e6d6: /* original 0bfe, guest PC 0x0c09e6d6 */
if(!s->budget--) { s->failed_pc=0x0c09e6d6u; return 0; }
r[11]=read(ram,r[15]+r[0],4);
goto P_0c09e6d8;
P_0c09e6d8: /* original 9081, guest PC 0x0c09e6d8 */
if(!s->budget--) { s->failed_pc=0x0c09e6d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e7deu,2);
goto P_0c09e6da;
P_0c09e6da: /* original 0cfe, guest PC 0x0c09e6da */
if(!s->budget--) { s->failed_pc=0x0c09e6dau; return 0; }
r[12]=read(ram,r[15]+r[0],4);
goto P_0c09e6dc;
P_0c09e6dc: /* original 9080, guest PC 0x0c09e6dc */
if(!s->budget--) { s->failed_pc=0x0c09e6dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e7e0u,2);
goto P_0c09e6de;
P_0c09e6de: /* original 0efe, guest PC 0x0c09e6de */
if(!s->budget--) { s->failed_pc=0x0c09e6deu; return 0; }
r[14]=read(ram,r[15]+r[0],4);
goto P_0c09e6e0;
P_0c09e6e0: /* original e010, guest PC 0x0c09e6e0 */
if(!s->budget--) { s->failed_pc=0x0c09e6e0u; return 0; }
r[0]=0x00000010u;
goto P_0c09e6e2;
P_0c09e6e2: /* original ff47, guest PC 0x0c09e6e2 */
if(!s->budget--) { s->failed_pc=0x0c09e6e2u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c09e6e4;
P_0c09e6e4: /* original d841, guest PC 0x0c09e6e4 */
if(!s->budget--) { s->failed_pc=0x0c09e6e4u; return 0; }
r[8]=read(ram,0x0c09e7ecu,4);
goto P_0c09e6e6;
P_0c09e6e6: /* original 480b, guest PC 0x0c09e6e6 */
if(!s->budget--) { s->failed_pc=0x0c09e6e6u; return 0; }
target=r[8];
r[16]=code_base|0x0c09e6eau;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e6eau) { target=s->pc; goto dispatch; }
goto P_0c09e6ea;
P_0c09e6e8: /* original e400, guest PC 0x0c09e6e8 */
if(!s->budget--) { s->failed_pc=0x0c09e6e8u; return 0; }
r[4]=0x00000000u;
goto P_0c09e6ea;
P_0c09e6ea: /* original d341, guest PC 0x0c09e6ea */
if(!s->budget--) { s->failed_pc=0x0c09e6eau; return 0; }
r[3]=read(ram,0x0c09e7f0u,4);
goto P_0c09e6ec;
P_0c09e6ec: /* original 430b, guest PC 0x0c09e6ec */
if(!s->budget--) { s->failed_pc=0x0c09e6ecu; return 0; }
target=r[3];
r[16]=code_base|0x0c09e6f0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e6f0u) { target=s->pc; goto dispatch; }
goto P_0c09e6f0;
P_0c09e6ee: /* original 0009, guest PC 0x0c09e6ee */
if(!s->budget--) { s->failed_pc=0x0c09e6eeu; return 0; }
goto P_0c09e6f0;
P_0c09e6f0: /* original 9477, guest PC 0x0c09e6f0 */
if(!s->budget--) { s->failed_pc=0x0c09e6f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e7e2u,2);
goto P_0c09e6f2;
P_0c09e6f2: /* original dd40, guest PC 0x0c09e6f2 */
if(!s->budget--) { s->failed_pc=0x0c09e6f2u; return 0; }
r[13]=read(ram,0x0c09e7f4u,4);
goto P_0c09e6f4;
P_0c09e6f4: /* original 4d0b, guest PC 0x0c09e6f4 */
if(!s->budget--) { s->failed_pc=0x0c09e6f4u; return 0; }
target=r[13];
r[16]=code_base|0x0c09e6f8u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e6f8u) { target=s->pc; goto dispatch; }
goto P_0c09e6f8;
P_0c09e6f6: /* original 34fc, guest PC 0x0c09e6f6 */
if(!s->budget--) { s->failed_pc=0x0c09e6f6u; return 0; }
r[4]+=r[15];
goto P_0c09e6f8;
P_0c09e6f8: /* original 9474, guest PC 0x0c09e6f8 */
if(!s->budget--) { s->failed_pc=0x0c09e6f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e7e4u,2);
goto P_0c09e6fa;
P_0c09e6fa: /* original 4d0b, guest PC 0x0c09e6fa */
if(!s->budget--) { s->failed_pc=0x0c09e6fau; return 0; }
target=r[13];
r[16]=code_base|0x0c09e6feu;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e6feu) { target=s->pc; goto dispatch; }
goto P_0c09e6fe;
P_0c09e6fc: /* original 34fc, guest PC 0x0c09e6fc */
if(!s->budget--) { s->failed_pc=0x0c09e6fcu; return 0; }
r[4]+=r[15];
goto P_0c09e6fe;
P_0c09e6fe: /* original 64f3, guest PC 0x0c09e6fe */
if(!s->budget--) { s->failed_pc=0x0c09e6feu; return 0; }
r[4]=r[15];
goto P_0c09e700;
P_0c09e700: /* original 4d0b, guest PC 0x0c09e700 */
if(!s->budget--) { s->failed_pc=0x0c09e700u; return 0; }
target=r[13];
r[16]=code_base|0x0c09e704u;
r[4]+=0x00000070u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e704u) { target=s->pc; goto dispatch; }
goto P_0c09e704;
P_0c09e702: /* original 7470, guest PC 0x0c09e702 */
if(!s->budget--) { s->failed_pc=0x0c09e702u; return 0; }
r[4]+=0x00000070u;
goto P_0c09e704;
P_0c09e704: /* original d93c, guest PC 0x0c09e704 */
if(!s->budget--) { s->failed_pc=0x0c09e704u; return 0; }
r[9]=read(ram,0x0c09e7f8u,4);
goto P_0c09e706;
P_0c09e706: /* original 490b, guest PC 0x0c09e706 */
if(!s->budget--) { s->failed_pc=0x0c09e706u; return 0; }
target=r[9];
r[16]=code_base|0x0c09e70au;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e70au) { target=s->pc; goto dispatch; }
goto P_0c09e70a;
P_0c09e708: /* original e401, guest PC 0x0c09e708 */
if(!s->budget--) { s->failed_pc=0x0c09e708u; return 0; }
r[4]=0x00000001u;
goto P_0c09e70a;
P_0c09e70a: /* original 480b, guest PC 0x0c09e70a */
if(!s->budget--) { s->failed_pc=0x0c09e70au; return 0; }
target=r[8];
r[16]=code_base|0x0c09e70eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e70eu) { target=s->pc; goto dispatch; }
goto P_0c09e70e;
P_0c09e70c: /* original e400, guest PC 0x0c09e70c */
if(!s->budget--) { s->failed_pc=0x0c09e70cu; return 0; }
r[4]=0x00000000u;
goto P_0c09e70e;
P_0c09e70e: /* original e008, guest PC 0x0c09e70e */
if(!s->budget--) { s->failed_pc=0x0c09e70eu; return 0; }
r[0]=0x00000008u;
goto P_0c09e710;
P_0c09e710: /* original d33a, guest PC 0x0c09e710 */
if(!s->budget--) { s->failed_pc=0x0c09e710u; return 0; }
r[3]=read(ram,0x0c09e7fcu,4);
goto P_0c09e712;
P_0c09e712: /* original f6a6, guest PC 0x0c09e712 */
if(!s->budget--) { s->failed_pc=0x0c09e712u; return 0; }
vf3_matrix_load(s,ram,6,r[10]+r[0]);
goto P_0c09e714;
P_0c09e714: /* original ff8d, guest PC 0x0c09e714 */
if(!s->budget--) { s->failed_pc=0x0c09e714u; return 0; }
fr[15]=0;
goto P_0c09e716;
P_0c09e716: /* original f5fc, guest PC 0x0c09e716 */
if(!s->budget--) { s->failed_pc=0x0c09e716u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09e718;
P_0c09e718: /* original f64d, guest PC 0x0c09e718 */
if(!s->budget--) { s->failed_pc=0x0c09e718u; return 0; }
fr[6]^=0x80000000u;
goto P_0c09e71a;
P_0c09e71a: /* original 430b, guest PC 0x0c09e71a */
if(!s->budget--) { s->failed_pc=0x0c09e71au; return 0; }
target=r[3];
r[16]=code_base|0x0c09e71eu;
vf3_matrix_load(s,ram,4,r[10]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e71eu) { target=s->pc; goto dispatch; }
goto P_0c09e71e;
P_0c09e71c: /* original f4a8, guest PC 0x0c09e71c */
if(!s->budget--) { s->failed_pc=0x0c09e71cu; return 0; }
vf3_matrix_load(s,ram,4,r[10]);
goto P_0c09e71e;
P_0c09e71e: /* original 9460, guest PC 0x0c09e71e */
if(!s->budget--) { s->failed_pc=0x0c09e71eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e7e2u,2);
goto P_0c09e720;
P_0c09e720: /* original 4d0b, guest PC 0x0c09e720 */
if(!s->budget--) { s->failed_pc=0x0c09e720u; return 0; }
target=r[13];
r[16]=code_base|0x0c09e724u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e724u) { target=s->pc; goto dispatch; }
goto P_0c09e724;
P_0c09e722: /* original 34fc, guest PC 0x0c09e722 */
if(!s->budget--) { s->failed_pc=0x0c09e722u; return 0; }
r[4]+=r[15];
goto P_0c09e724;
P_0c09e724: /* original 490b, guest PC 0x0c09e724 */
if(!s->budget--) { s->failed_pc=0x0c09e724u; return 0; }
target=r[9];
r[16]=code_base|0x0c09e728u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e728u) { target=s->pc; goto dispatch; }
goto P_0c09e728;
P_0c09e726: /* original e401, guest PC 0x0c09e726 */
if(!s->budget--) { s->failed_pc=0x0c09e726u; return 0; }
r[4]=0x00000001u;
goto P_0c09e728;
P_0c09e728: /* original 480b, guest PC 0x0c09e728 */
if(!s->budget--) { s->failed_pc=0x0c09e728u; return 0; }
target=r[8];
r[16]=code_base|0x0c09e72cu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e72cu) { target=s->pc; goto dispatch; }
goto P_0c09e72c;
P_0c09e72a: /* original e400, guest PC 0x0c09e72a */
if(!s->budget--) { s->failed_pc=0x0c09e72au; return 0; }
r[4]=0x00000000u;
goto P_0c09e72c;
P_0c09e72c: /* original 62f2, guest PC 0x0c09e72c */
if(!s->budget--) { s->failed_pc=0x0c09e72cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09e72e;
P_0c09e72e: /* original e004, guest PC 0x0c09e72e */
if(!s->budget--) { s->failed_pc=0x0c09e72eu; return 0; }
r[0]=0x00000004u;
goto P_0c09e730;
P_0c09e730: /* original d332, guest PC 0x0c09e730 */
if(!s->budget--) { s->failed_pc=0x0c09e730u; return 0; }
r[3]=read(ram,0x0c09e7fcu,4);
goto P_0c09e732;
P_0c09e732: /* original f626, guest PC 0x0c09e732 */
if(!s->budget--) { s->failed_pc=0x0c09e732u; return 0; }
vf3_matrix_load(s,ram,6,r[2]+r[0]);
goto P_0c09e734;
P_0c09e734: /* original f5fc, guest PC 0x0c09e734 */
if(!s->budget--) { s->failed_pc=0x0c09e734u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09e736;
P_0c09e736: /* original 430b, guest PC 0x0c09e736 */
if(!s->budget--) { s->failed_pc=0x0c09e736u; return 0; }
target=r[3];
r[16]=code_base|0x0c09e73au;
vf3_matrix_load(s,ram,4,r[2]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e73au) { target=s->pc; goto dispatch; }
goto P_0c09e73a;
P_0c09e738: /* original f428, guest PC 0x0c09e738 */
if(!s->budget--) { s->failed_pc=0x0c09e738u; return 0; }
vf3_matrix_load(s,ram,4,r[2]);
goto P_0c09e73a;
P_0c09e73a: /* original d331, guest PC 0x0c09e73a */
if(!s->budget--) { s->failed_pc=0x0c09e73au; return 0; }
r[3]=read(ram,0x0c09e800u,4);
goto P_0c09e73c;
P_0c09e73c: /* original 9053, guest PC 0x0c09e73c */
if(!s->budget--) { s->failed_pc=0x0c09e73cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e7e6u,2);
goto P_0c09e73e;
P_0c09e73e: /* original 430b, guest PC 0x0c09e73e */
if(!s->budget--) { s->failed_pc=0x0c09e73eu; return 0; }
target=r[3];
r[16]=code_base|0x0c09e742u;
r[4]=read(ram,r[15]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e742u) { target=s->pc; goto dispatch; }
goto P_0c09e742;
P_0c09e740: /* original 04fe, guest PC 0x0c09e740 */
if(!s->budget--) { s->failed_pc=0x0c09e740u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c09e742;
P_0c09e742: /* original 9051, guest PC 0x0c09e742 */
if(!s->budget--) { s->failed_pc=0x0c09e742u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e7e8u,2);
goto P_0c09e744;
P_0c09e744: /* original 66f3, guest PC 0x0c09e744 */
if(!s->budget--) { s->failed_pc=0x0c09e744u; return 0; }
r[6]=r[15];
goto P_0c09e746;
P_0c09e746: /* original 65f3, guest PC 0x0c09e746 */
if(!s->budget--) { s->failed_pc=0x0c09e746u; return 0; }
r[5]=r[15];
goto P_0c09e748;
P_0c09e748: /* original 7508, guest PC 0x0c09e748 */
if(!s->budget--) { s->failed_pc=0x0c09e748u; return 0; }
r[5]+=0x00000008u;
goto P_0c09e74a;
P_0c09e74a: /* original 02fe, guest PC 0x0c09e74a */
if(!s->budget--) { s->failed_pc=0x0c09e74au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c09e74c;
P_0c09e74c: /* original e058, guest PC 0x0c09e74c */
if(!s->budget--) { s->failed_pc=0x0c09e74cu; return 0; }
r[0]=0x00000058u;
goto P_0c09e74e;
P_0c09e74e: /* original 64f3, guest PC 0x0c09e74e */
if(!s->budget--) { s->failed_pc=0x0c09e74eu; return 0; }
r[4]=r[15];
goto P_0c09e750;
P_0c09e750: /* original 760c, guest PC 0x0c09e750 */
if(!s->budget--) { s->failed_pc=0x0c09e750u; return 0; }
r[6]+=0x0000000cu;
goto P_0c09e752;
P_0c09e752: /* original f328, guest PC 0x0c09e752 */
if(!s->budget--) { s->failed_pc=0x0c09e752u; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
goto P_0c09e754;
P_0c09e754: /* original ff37, guest PC 0x0c09e754 */
if(!s->budget--) { s->failed_pc=0x0c09e754u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e756;
P_0c09e756: /* original 9047, guest PC 0x0c09e756 */
if(!s->budget--) { s->failed_pc=0x0c09e756u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e7e8u,2);
goto P_0c09e758;
P_0c09e758: /* original 03fe, guest PC 0x0c09e758 */
if(!s->budget--) { s->failed_pc=0x0c09e758u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c09e75a;
P_0c09e75a: /* original e010, guest PC 0x0c09e75a */
if(!s->budget--) { s->failed_pc=0x0c09e75au; return 0; }
r[0]=0x00000010u;
goto P_0c09e75c;
P_0c09e75c: /* original f3f6, guest PC 0x0c09e75c */
if(!s->budget--) { s->failed_pc=0x0c09e75cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e75e;
P_0c09e75e: /* original e004, guest PC 0x0c09e75e */
if(!s->budget--) { s->failed_pc=0x0c09e75eu; return 0; }
r[0]=0x00000004u;
goto P_0c09e760;
P_0c09e760: /* original f236, guest PC 0x0c09e760 */
if(!s->budget--) { s->failed_pc=0x0c09e760u; return 0; }
vf3_matrix_load(s,ram,2,r[3]+r[0]);
goto P_0c09e762;
P_0c09e762: /* original e05c, guest PC 0x0c09e762 */
if(!s->budget--) { s->failed_pc=0x0c09e762u; return 0; }
r[0]=0x0000005cu;
goto P_0c09e764;
P_0c09e764: /* original f230, guest PC 0x0c09e764 */
if(!s->budget--) { s->failed_pc=0x0c09e764u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c09e766;
P_0c09e766: /* original ff27, guest PC 0x0c09e766 */
if(!s->budget--) { s->failed_pc=0x0c09e766u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c09e768;
P_0c09e768: /* original e008, guest PC 0x0c09e768 */
if(!s->budget--) { s->failed_pc=0x0c09e768u; return 0; }
r[0]=0x00000008u;
goto P_0c09e76a;
P_0c09e76a: /* original f236, guest PC 0x0c09e76a */
if(!s->budget--) { s->failed_pc=0x0c09e76au; return 0; }
vf3_matrix_load(s,ram,2,r[3]+r[0]);
goto P_0c09e76c;
P_0c09e76c: /* original e060, guest PC 0x0c09e76c */
if(!s->budget--) { s->failed_pc=0x0c09e76cu; return 0; }
r[0]=0x00000060u;
goto P_0c09e76e;
P_0c09e76e: /* original ff27, guest PC 0x0c09e76e */
if(!s->budget--) { s->failed_pc=0x0c09e76eu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c09e770;
P_0c09e770: /* original ba60, guest PC 0x0c09e770 */
if(!s->budget--) { s->failed_pc=0x0c09e770u; return 0; }
target=code_base|0x0c09dc34u; r[16]=code_base|0x0c09e774u;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e774u) { target=s->pc; goto dispatch; }
goto P_0c09e774;
P_0c09e772: /* original 7458, guest PC 0x0c09e772 */
if(!s->budget--) { s->failed_pc=0x0c09e772u; return 0; }
r[4]+=0x00000058u;
goto P_0c09e774;
P_0c09e774: /* original 63f2, guest PC 0x0c09e774 */
if(!s->budget--) { s->failed_pc=0x0c09e774u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09e776;
P_0c09e776: /* original e008, guest PC 0x0c09e776 */
if(!s->budget--) { s->failed_pc=0x0c09e776u; return 0; }
r[0]=0x00000008u;
goto P_0c09e778;
P_0c09e778: /* original f636, guest PC 0x0c09e778 */
if(!s->budget--) { s->failed_pc=0x0c09e778u; return 0; }
vf3_matrix_load(s,ram,6,r[3]+r[0]);
goto P_0c09e77a;
P_0c09e77a: /* original e00c, guest PC 0x0c09e77a */
if(!s->budget--) { s->failed_pc=0x0c09e77au; return 0; }
r[0]=0x0000000cu;
goto P_0c09e77c;
P_0c09e77c: /* original f436, guest PC 0x0c09e77c */
if(!s->budget--) { s->failed_pc=0x0c09e77cu; return 0; }
vf3_matrix_load(s,ram,4,r[3]+r[0]);
goto P_0c09e77e;
P_0c09e77e: /* original e008, guest PC 0x0c09e77e */
if(!s->budget--) { s->failed_pc=0x0c09e77eu; return 0; }
r[0]=0x00000008u;
goto P_0c09e780;
P_0c09e780: /* original f76c, guest PC 0x0c09e780 */
if(!s->budget--) { s->failed_pc=0x0c09e780u; return 0; }
vf3_matrix_move(s,7,6);
goto P_0c09e782;
P_0c09e782: /* original f740, guest PC 0x0c09e782 */
if(!s->budget--) { s->failed_pc=0x0c09e782u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'+');
goto P_0c09e784;
P_0c09e784: /* original f5f6, guest PC 0x0c09e784 */
if(!s->budget--) { s->failed_pc=0x0c09e784u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c09e786;
P_0c09e786: /* original f755, guest PC 0x0c09e786 */
if(!s->budget--) { s->failed_pc=0x0c09e786u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[5]))!=0);
goto P_0c09e788;
P_0c09e788: /* original 8901, guest PC 0x0c09e788 */
if(!s->budget--) { s->failed_pc=0x0c09e788u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09e78e; }
goto P_0c09e78a;
P_0c09e78a: /* original a07f, guest PC 0x0c09e78a */
if(!s->budget--) { s->failed_pc=0x0c09e78au; return 0; }
goto P_0c09e88c;
P_0c09e78c: /* original 0009, guest PC 0x0c09e78c */
if(!s->budget--) { s->failed_pc=0x0c09e78cu; return 0; }
goto P_0c09e78e;
P_0c09e78e: /* original fa5c, guest PC 0x0c09e78e */
if(!s->budget--) { s->failed_pc=0x0c09e78eu; return 0; }
vf3_matrix_move(s,10,5);
goto P_0c09e790;
P_0c09e790: /* original fa52, guest PC 0x0c09e790 */
if(!s->budget--) { s->failed_pc=0x0c09e790u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[5],r[18],'*');
goto P_0c09e792;
P_0c09e792: /* original f86c, guest PC 0x0c09e792 */
if(!s->budget--) { s->failed_pc=0x0c09e792u; return 0; }
vf3_matrix_move(s,8,6);
goto P_0c09e794;
P_0c09e794: /* original f862, guest PC 0x0c09e794 */
if(!s->budget--) { s->failed_pc=0x0c09e794u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'*');
goto P_0c09e796;
P_0c09e796: /* original f74c, guest PC 0x0c09e796 */
if(!s->budget--) { s->failed_pc=0x0c09e796u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c09e798;
P_0c09e798: /* original f742, guest PC 0x0c09e798 */
if(!s->budget--) { s->failed_pc=0x0c09e798u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c09e79a;
P_0c09e79a: /* original f24c, guest PC 0x0c09e79a */
if(!s->budget--) { s->failed_pc=0x0c09e79au; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c09e79c;
P_0c09e79c: /* original f252, guest PC 0x0c09e79c */
if(!s->budget--) { s->failed_pc=0x0c09e79cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'*');
goto P_0c09e79e;
P_0c09e79e: /* original f3ac, guest PC 0x0c09e79e */
if(!s->budget--) { s->failed_pc=0x0c09e79eu; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c09e7a0;
P_0c09e7a0: /* original c718, guest PC 0x0c09e7a0 */
if(!s->budget--) { s->failed_pc=0x0c09e7a0u; return 0; }
r[0]=code_base|0x0009e804u;
goto P_0c09e7a2;
P_0c09e7a2: /* original f381, guest PC 0x0c09e7a2 */
if(!s->budget--) { s->failed_pc=0x0c09e7a2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'-');
goto P_0c09e7a4;
P_0c09e7a4: /* original f908, guest PC 0x0c09e7a4 */
if(!s->budget--) { s->failed_pc=0x0c09e7a4u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c09e7a6;
P_0c09e7a6: /* original f642, guest PC 0x0c09e7a6 */
if(!s->budget--) { s->failed_pc=0x0c09e7a6u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c09e7a8;
P_0c09e7a8: /* original f49d, guest PC 0x0c09e7a8 */
if(!s->budget--) { s->failed_pc=0x0c09e7a8u; return 0; }
fr[4]=0x3f800000u;
goto P_0c09e7aa;
P_0c09e7aa: /* original f292, guest PC 0x0c09e7aa */
if(!s->budget--) { s->failed_pc=0x0c09e7aau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[9],r[18],'*');
goto P_0c09e7ac;
P_0c09e7ac: /* original c716, guest PC 0x0c09e7ac */
if(!s->budget--) { s->failed_pc=0x0c09e7acu; return 0; }
r[0]=code_base|0x0009e808u;
goto P_0c09e7ae;
P_0c09e7ae: /* original f370, guest PC 0x0c09e7ae */
if(!s->budget--) { s->failed_pc=0x0c09e7aeu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'+');
goto P_0c09e7b0;
P_0c09e7b0: /* original f780, guest PC 0x0c09e7b0 */
if(!s->budget--) { s->failed_pc=0x0c09e7b0u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[8],r[18],'+');
goto P_0c09e7b2;
P_0c09e7b2: /* original f692, guest PC 0x0c09e7b2 */
if(!s->budget--) { s->failed_pc=0x0c09e7b2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[9],r[18],'*');
goto P_0c09e7b4;
P_0c09e7b4: /* original f53c, guest PC 0x0c09e7b4 */
if(!s->budget--) { s->failed_pc=0x0c09e7b4u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c09e7b6;
P_0c09e7b6: /* original f523, guest PC 0x0c09e7b6 */
if(!s->budget--) { s->failed_pc=0x0c09e7b6u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
goto P_0c09e7b8;
P_0c09e7b8: /* original f7a1, guest PC 0x0c09e7b8 */
if(!s->budget--) { s->failed_pc=0x0c09e7b8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[10],r[18],'-');
goto P_0c09e7ba;
P_0c09e7ba: /* original fe7c, guest PC 0x0c09e7ba */
if(!s->budget--) { s->failed_pc=0x0c09e7bau; return 0; }
vf3_matrix_move(s,14,7);
goto P_0c09e7bc;
P_0c09e7bc: /* original fe63, guest PC 0x0c09e7bc */
if(!s->budget--) { s->failed_pc=0x0c09e7bcu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[6],r[18],'/');
goto P_0c09e7be;
P_0c09e7be: /* original f545, guest PC 0x0c09e7be */
if(!s->budget--) { s->failed_pc=0x0c09e7beu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c09e7c0;
P_0c09e7c0: /* original 8f02, guest PC 0x0c09e7c0 */
if(!s->budget--) { s->failed_pc=0x0c09e7c0u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,6,r[0]);
if(!cond) { goto P_0c09e7c8; }
goto P_0c09e7c4;
P_0c09e7c2: /* original f608, guest PC 0x0c09e7c2 */
if(!s->budget--) { s->failed_pc=0x0c09e7c2u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c09e7c4;
P_0c09e7c4: /* original a003, guest PC 0x0c09e7c4 */
if(!s->budget--) { s->failed_pc=0x0c09e7c4u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c09e7ce;
P_0c09e7c6: /* original f54c, guest PC 0x0c09e7c6 */
if(!s->budget--) { s->failed_pc=0x0c09e7c6u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c09e7c8;
P_0c09e7c8: /* original f655, guest PC 0x0c09e7c8 */
if(!s->budget--) { s->failed_pc=0x0c09e7c8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[5]))!=0);
goto P_0c09e7ca;
P_0c09e7ca: /* original 8b00, guest PC 0x0c09e7ca */
if(!s->budget--) { s->failed_pc=0x0c09e7cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09e7ce; }
goto P_0c09e7cc;
P_0c09e7cc: /* original f56c, guest PC 0x0c09e7cc */
if(!s->budget--) { s->failed_pc=0x0c09e7ccu; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c09e7ce;
P_0c09e7ce: /* original fe45, guest PC 0x0c09e7ce */
if(!s->budget--) { s->failed_pc=0x0c09e7ceu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[4]))!=0);
goto P_0c09e7d0;
P_0c09e7d0: /* original 8b1c, guest PC 0x0c09e7d0 */
if(!s->budget--) { s->failed_pc=0x0c09e7d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09e80c; }
goto P_0c09e7d2;
P_0c09e7d2: /* original a01e, guest PC 0x0c09e7d2 */
if(!s->budget--) { s->failed_pc=0x0c09e7d2u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c09e812;
P_0c09e7d4: /* original fe4c, guest PC 0x0c09e7d4 */
if(!s->budget--) { s->failed_pc=0x0c09e7d4u; return 0; }
vf3_matrix_move(s,14,4);
if(!vf3_matrix_family(0x0c09e7d6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09e7d6u; return 0; } return 1;
P_0c09e80c: /* original f6e5, guest PC 0x0c09e80c */
if(!s->budget--) { s->failed_pc=0x0c09e80cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[14]))!=0);
goto P_0c09e80e;
P_0c09e80e: /* original 8b00, guest PC 0x0c09e80e */
if(!s->budget--) { s->failed_pc=0x0c09e80eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09e812; }
goto P_0c09e810;
P_0c09e810: /* original fe6c, guest PC 0x0c09e810 */
if(!s->budget--) { s->failed_pc=0x0c09e810u; return 0; }
vf3_matrix_move(s,14,6);
goto P_0c09e812;
P_0c09e812: /* original f35c, guest PC 0x0c09e812 */
if(!s->budget--) { s->failed_pc=0x0c09e812u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c09e814;
P_0c09e814: /* original f352, guest PC 0x0c09e814 */
if(!s->budget--) { s->failed_pc=0x0c09e814u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c09e816;
P_0c09e816: /* original c719, guest PC 0x0c09e816 */
if(!s->budget--) { s->failed_pc=0x0c09e816u; return 0; }
r[0]=code_base|0x0009e87cu;
goto P_0c09e818;
P_0c09e818: /* original fd08, guest PC 0x0c09e818 */
if(!s->budget--) { s->failed_pc=0x0c09e818u; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c09e81a;
P_0c09e81a: /* original f431, guest PC 0x0c09e81a */
if(!s->budget--) { s->failed_pc=0x0c09e81au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c09e81c;
P_0c09e81c: /* original fd45, guest PC 0x0c09e81c */
if(!s->budget--) { s->failed_pc=0x0c09e81cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[13])>as_float(fr[4]))!=0);
goto P_0c09e81e;
P_0c09e81e: /* original 8b01, guest PC 0x0c09e81e */
if(!s->budget--) { s->failed_pc=0x0c09e81eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09e824; }
goto P_0c09e820;
P_0c09e820: /* original a002, guest PC 0x0c09e820 */
if(!s->budget--) { s->failed_pc=0x0c09e820u; return 0; }
fr[3]=0;
goto P_0c09e828;
P_0c09e822: /* original f38d, guest PC 0x0c09e822 */
if(!s->budget--) { s->failed_pc=0x0c09e822u; return 0; }
fr[3]=0;
goto P_0c09e824;
P_0c09e824: /* original f34c, guest PC 0x0c09e824 */
if(!s->budget--) { s->failed_pc=0x0c09e824u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c09e826;
P_0c09e826: /* original f36d, guest PC 0x0c09e826 */
if(!s->budget--) { s->failed_pc=0x0c09e826u; return 0; }
fr[3]=vf3_fpu_sqrt(fr[3],r[18]);
goto P_0c09e828;
P_0c09e828: /* original d315, guest PC 0x0c09e828 */
if(!s->budget--) { s->failed_pc=0x0c09e828u; return 0; }
r[3]=read(ram,0x0c09e880u,4);
goto P_0c09e82a;
P_0c09e82a: /* original f43c, guest PC 0x0c09e82a */
if(!s->budget--) { s->failed_pc=0x0c09e82au; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c09e82c;
P_0c09e82c: /* original 430b, guest PC 0x0c09e82c */
if(!s->budget--) { s->failed_pc=0x0c09e82cu; return 0; }
target=r[3];
r[16]=code_base|0x0c09e830u;
fr[4]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e830u) { target=s->pc; goto dispatch; }
goto P_0c09e830;
P_0c09e82e: /* original f44d, guest PC 0x0c09e82e */
if(!s->budget--) { s->failed_pc=0x0c09e82eu; return 0; }
fr[4]^=0x80000000u;
goto P_0c09e830;
P_0c09e830: /* original d214, guest PC 0x0c09e830 */
if(!s->budget--) { s->failed_pc=0x0c09e830u; return 0; }
r[2]=read(ram,0x0c09e884u,4);
goto P_0c09e832;
P_0c09e832: /* original 9421, guest PC 0x0c09e832 */
if(!s->budget--) { s->failed_pc=0x0c09e832u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e878u,2);
goto P_0c09e834;
P_0c09e834: /* original 420b, guest PC 0x0c09e834 */
if(!s->budget--) { s->failed_pc=0x0c09e834u; return 0; }
target=r[2];
r[16]=code_base|0x0c09e838u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e838u) { target=s->pc; goto dispatch; }
goto P_0c09e838;
P_0c09e836: /* original 34fc, guest PC 0x0c09e836 */
if(!s->budget--) { s->failed_pc=0x0c09e836u; return 0; }
r[4]+=r[15];
goto P_0c09e838;
P_0c09e838: /* original c713, guest PC 0x0c09e838 */
if(!s->budget--) { s->failed_pc=0x0c09e838u; return 0; }
r[0]=code_base|0x0009e888u;
goto P_0c09e83a;
P_0c09e83a: /* original f6ec, guest PC 0x0c09e83a */
if(!s->budget--) { s->failed_pc=0x0c09e83au; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c09e83c;
P_0c09e83c: /* original f408, guest PC 0x0c09e83c */
if(!s->budget--) { s->failed_pc=0x0c09e83cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c09e83e;
P_0c09e83e: /* original f642, guest PC 0x0c09e83e */
if(!s->budget--) { s->failed_pc=0x0c09e83eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c09e840;
P_0c09e840: /* original f56c, guest PC 0x0c09e840 */
if(!s->budget--) { s->failed_pc=0x0c09e840u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c09e842;
P_0c09e842: /* original f540, guest PC 0x0c09e842 */
if(!s->budget--) { s->failed_pc=0x0c09e842u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'+');
goto P_0c09e844;
P_0c09e844: /* original fd55, guest PC 0x0c09e844 */
if(!s->budget--) { s->failed_pc=0x0c09e844u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[13])>as_float(fr[5]))!=0);
goto P_0c09e846;
P_0c09e846: /* original 8f02, guest PC 0x0c09e846 */
if(!s->budget--) { s->failed_pc=0x0c09e846u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
if(!cond) { goto P_0c09e84e; }
goto P_0c09e84a;
P_0c09e848: /* original f461, guest PC 0x0c09e848 */
if(!s->budget--) { s->failed_pc=0x0c09e848u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
goto P_0c09e84a;
P_0c09e84a: /* original a002, guest PC 0x0c09e84a */
if(!s->budget--) { s->failed_pc=0x0c09e84au; return 0; }
fr[14]=0;
goto P_0c09e852;
P_0c09e84c: /* original fe8d, guest PC 0x0c09e84c */
if(!s->budget--) { s->failed_pc=0x0c09e84cu; return 0; }
fr[14]=0;
goto P_0c09e84e;
P_0c09e84e: /* original fe5c, guest PC 0x0c09e84e */
if(!s->budget--) { s->failed_pc=0x0c09e84eu; return 0; }
vf3_matrix_move(s,14,5);
goto P_0c09e850;
P_0c09e850: /* original fe6d, guest PC 0x0c09e850 */
if(!s->budget--) { s->failed_pc=0x0c09e850u; return 0; }
fr[14]=vf3_fpu_sqrt(fr[14],r[18]);
goto P_0c09e852;
P_0c09e852: /* original fd45, guest PC 0x0c09e852 */
if(!s->budget--) { s->failed_pc=0x0c09e852u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[13])>as_float(fr[4]))!=0);
goto P_0c09e854;
P_0c09e854: /* original 8b01, guest PC 0x0c09e854 */
if(!s->budget--) { s->failed_pc=0x0c09e854u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09e85a; }
goto P_0c09e856;
P_0c09e856: /* original a002, guest PC 0x0c09e856 */
if(!s->budget--) { s->failed_pc=0x0c09e856u; return 0; }
fr[13]=0;
goto P_0c09e85e;
P_0c09e858: /* original fd8d, guest PC 0x0c09e858 */
if(!s->budget--) { s->failed_pc=0x0c09e858u; return 0; }
fr[13]=0;
goto P_0c09e85a;
P_0c09e85a: /* original fd4c, guest PC 0x0c09e85a */
if(!s->budget--) { s->failed_pc=0x0c09e85au; return 0; }
vf3_matrix_move(s,13,4);
goto P_0c09e85c;
P_0c09e85c: /* original fd6d, guest PC 0x0c09e85c */
if(!s->budget--) { s->failed_pc=0x0c09e85cu; return 0; }
fr[13]=vf3_fpu_sqrt(fr[13],r[18]);
goto P_0c09e85e;
P_0c09e85e: /* original d308, guest PC 0x0c09e85e */
if(!s->budget--) { s->failed_pc=0x0c09e85eu; return 0; }
r[3]=read(ram,0x0c09e880u,4);
goto P_0c09e860;
P_0c09e860: /* original f5dc, guest PC 0x0c09e860 */
if(!s->budget--) { s->failed_pc=0x0c09e860u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c09e862;
P_0c09e862: /* original 430b, guest PC 0x0c09e862 */
if(!s->budget--) { s->failed_pc=0x0c09e862u; return 0; }
target=r[3];
r[16]=code_base|0x0c09e866u;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e866u) { target=s->pc; goto dispatch; }
goto P_0c09e866;
P_0c09e864: /* original f4ec, guest PC 0x0c09e864 */
if(!s->budget--) { s->failed_pc=0x0c09e864u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c09e866;
P_0c09e866: /* original d207, guest PC 0x0c09e866 */
if(!s->budget--) { s->failed_pc=0x0c09e866u; return 0; }
r[2]=read(ram,0x0c09e884u,4);
goto P_0c09e868;
P_0c09e868: /* original 420b, guest PC 0x0c09e868 */
if(!s->budget--) { s->failed_pc=0x0c09e868u; return 0; }
target=r[2];
r[16]=code_base|0x0c09e86cu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e86cu) { target=s->pc; goto dispatch; }
goto P_0c09e86c;
P_0c09e86a: /* original 64b3, guest PC 0x0c09e86a */
if(!s->budget--) { s->failed_pc=0x0c09e86au; return 0; }
r[4]=r[11];
goto P_0c09e86c;
P_0c09e86c: /* original d304, guest PC 0x0c09e86c */
if(!s->budget--) { s->failed_pc=0x0c09e86cu; return 0; }
r[3]=read(ram,0x0c09e880u,4);
goto P_0c09e86e;
P_0c09e86e: /* original f5dc, guest PC 0x0c09e86e */
if(!s->budget--) { s->failed_pc=0x0c09e86eu; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c09e870;
P_0c09e870: /* original 430b, guest PC 0x0c09e870 */
if(!s->budget--) { s->failed_pc=0x0c09e870u; return 0; }
target=r[3];
r[16]=code_base|0x0c09e874u;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e874u) { target=s->pc; goto dispatch; }
goto P_0c09e874;
P_0c09e872: /* original f4ec, guest PC 0x0c09e872 */
if(!s->budget--) { s->failed_pc=0x0c09e872u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c09e874;
P_0c09e874: /* original a011, guest PC 0x0c09e874 */
if(!s->budget--) { s->failed_pc=0x0c09e874u; return 0; }
goto P_0c09e89a;
P_0c09e876: /* original 0009, guest PC 0x0c09e876 */
if(!s->budget--) { s->failed_pc=0x0c09e876u; return 0; }
if(!vf3_matrix_family(0x0c09e878u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09e878u; return 0; } return 1;
P_0c09e88c: /* original d168, guest PC 0x0c09e88c */
if(!s->budget--) { s->failed_pc=0x0c09e88cu; return 0; }
r[1]=read(ram,0x0c09ea30u,4);
goto P_0c09e88e;
P_0c09e88e: /* original 94c5, guest PC 0x0c09e88e */
if(!s->budget--) { s->failed_pc=0x0c09e88eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ea1cu,2);
goto P_0c09e890;
P_0c09e890: /* original 410b, guest PC 0x0c09e890 */
if(!s->budget--) { s->failed_pc=0x0c09e890u; return 0; }
target=r[1];
r[16]=code_base|0x0c09e894u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e894u) { target=s->pc; goto dispatch; }
goto P_0c09e894;
P_0c09e892: /* original 34fc, guest PC 0x0c09e892 */
if(!s->budget--) { s->failed_pc=0x0c09e892u; return 0; }
r[4]+=r[15];
goto P_0c09e894;
P_0c09e894: /* original d366, guest PC 0x0c09e894 */
if(!s->budget--) { s->failed_pc=0x0c09e894u; return 0; }
r[3]=read(ram,0x0c09ea30u,4);
goto P_0c09e896;
P_0c09e896: /* original 430b, guest PC 0x0c09e896 */
if(!s->budget--) { s->failed_pc=0x0c09e896u; return 0; }
target=r[3];
r[16]=code_base|0x0c09e89au;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e89au) { target=s->pc; goto dispatch; }
goto P_0c09e89a;
P_0c09e898: /* original 64b3, guest PC 0x0c09e898 */
if(!s->budget--) { s->failed_pc=0x0c09e898u; return 0; }
r[4]=r[11];
goto P_0c09e89a;
P_0c09e89a: /* original d265, guest PC 0x0c09e89a */
if(!s->budget--) { s->failed_pc=0x0c09e89au; return 0; }
r[2]=read(ram,0x0c09ea30u,4);
goto P_0c09e89c;
P_0c09e89c: /* original 94bf, guest PC 0x0c09e89c */
if(!s->budget--) { s->failed_pc=0x0c09e89cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ea1eu,2);
goto P_0c09e89e;
P_0c09e89e: /* original 420b, guest PC 0x0c09e89e */
if(!s->budget--) { s->failed_pc=0x0c09e89eu; return 0; }
target=r[2];
r[16]=code_base|0x0c09e8a2u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e8a2u) { target=s->pc; goto dispatch; }
goto P_0c09e8a2;
P_0c09e8a0: /* original 34fc, guest PC 0x0c09e8a0 */
if(!s->budget--) { s->failed_pc=0x0c09e8a0u; return 0; }
r[4]+=r[15];
goto P_0c09e8a2;
P_0c09e8a2: /* original 480b, guest PC 0x0c09e8a2 */
if(!s->budget--) { s->failed_pc=0x0c09e8a2u; return 0; }
target=r[8];
r[16]=code_base|0x0c09e8a6u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e8a6u) { target=s->pc; goto dispatch; }
goto P_0c09e8a6;
P_0c09e8a4: /* original e400, guest PC 0x0c09e8a4 */
if(!s->budget--) { s->failed_pc=0x0c09e8a4u; return 0; }
r[4]=0x00000000u;
goto P_0c09e8a6;
P_0c09e8a6: /* original d363, guest PC 0x0c09e8a6 */
if(!s->budget--) { s->failed_pc=0x0c09e8a6u; return 0; }
r[3]=read(ram,0x0c09ea34u,4);
goto P_0c09e8a8;
P_0c09e8a8: /* original 94b9, guest PC 0x0c09e8a8 */
if(!s->budget--) { s->failed_pc=0x0c09e8a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ea1eu,2);
goto P_0c09e8aa;
P_0c09e8aa: /* original 430b, guest PC 0x0c09e8aa */
if(!s->budget--) { s->failed_pc=0x0c09e8aau; return 0; }
target=r[3];
r[16]=code_base|0x0c09e8aeu;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e8aeu) { target=s->pc; goto dispatch; }
goto P_0c09e8ae;
P_0c09e8ac: /* original 34fc, guest PC 0x0c09e8ac */
if(!s->budget--) { s->failed_pc=0x0c09e8acu; return 0; }
r[4]+=r[15];
goto P_0c09e8ae;
P_0c09e8ae: /* original d262, guest PC 0x0c09e8ae */
if(!s->budget--) { s->failed_pc=0x0c09e8aeu; return 0; }
r[2]=read(ram,0x0c09ea38u,4);
goto P_0c09e8b0;
P_0c09e8b0: /* original 64f3, guest PC 0x0c09e8b0 */
if(!s->budget--) { s->failed_pc=0x0c09e8b0u; return 0; }
r[4]=r[15];
goto P_0c09e8b2;
P_0c09e8b2: /* original 420b, guest PC 0x0c09e8b2 */
if(!s->budget--) { s->failed_pc=0x0c09e8b2u; return 0; }
target=r[2];
r[16]=code_base|0x0c09e8b6u;
r[4]+=0x00000064u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e8b6u) { target=s->pc; goto dispatch; }
goto P_0c09e8b6;
P_0c09e8b4: /* original 7464, guest PC 0x0c09e8b4 */
if(!s->budget--) { s->failed_pc=0x0c09e8b4u; return 0; }
r[4]+=0x00000064u;
goto P_0c09e8b6;
P_0c09e8b6: /* original 4d0b, guest PC 0x0c09e8b6 */
if(!s->budget--) { s->failed_pc=0x0c09e8b6u; return 0; }
target=r[13];
r[16]=code_base|0x0c09e8bau;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e8bau) { target=s->pc; goto dispatch; }
goto P_0c09e8ba;
P_0c09e8b8: /* original 54f1, guest PC 0x0c09e8b8 */
if(!s->budget--) { s->failed_pc=0x0c09e8b8u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c09e8ba;
P_0c09e8ba: /* original 490b, guest PC 0x0c09e8ba */
if(!s->budget--) { s->failed_pc=0x0c09e8bau; return 0; }
target=r[9];
r[16]=code_base|0x0c09e8beu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e8beu) { target=s->pc; goto dispatch; }
goto P_0c09e8be;
P_0c09e8bc: /* original e401, guest PC 0x0c09e8bc */
if(!s->budget--) { s->failed_pc=0x0c09e8bcu; return 0; }
r[4]=0x00000001u;
goto P_0c09e8be;
P_0c09e8be: /* original d35f, guest PC 0x0c09e8be */
if(!s->budget--) { s->failed_pc=0x0c09e8beu; return 0; }
r[3]=read(ram,0x0c09ea3cu,4);
goto P_0c09e8c0;
P_0c09e8c0: /* original 64f3, guest PC 0x0c09e8c0 */
if(!s->budget--) { s->failed_pc=0x0c09e8c0u; return 0; }
r[4]=r[15];
goto P_0c09e8c2;
P_0c09e8c2: /* original 430b, guest PC 0x0c09e8c2 */
if(!s->budget--) { s->failed_pc=0x0c09e8c2u; return 0; }
target=r[3];
r[16]=code_base|0x0c09e8c6u;
r[4]+=0x00000064u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e8c6u) { target=s->pc; goto dispatch; }
goto P_0c09e8c6;
P_0c09e8c4: /* original 7464, guest PC 0x0c09e8c4 */
if(!s->budget--) { s->failed_pc=0x0c09e8c4u; return 0; }
r[4]+=0x00000064u;
goto P_0c09e8c6;
P_0c09e8c6: /* original d25c, guest PC 0x0c09e8c6 */
if(!s->budget--) { s->failed_pc=0x0c09e8c6u; return 0; }
r[2]=read(ram,0x0c09ea38u,4);
goto P_0c09e8c8;
P_0c09e8c8: /* original 420b, guest PC 0x0c09e8c8 */
if(!s->budget--) { s->failed_pc=0x0c09e8c8u; return 0; }
target=r[2];
r[16]=code_base|0x0c09e8ccu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e8ccu) { target=s->pc; goto dispatch; }
goto P_0c09e8cc;
P_0c09e8ca: /* original 64e3, guest PC 0x0c09e8ca */
if(!s->budget--) { s->failed_pc=0x0c09e8cau; return 0; }
r[4]=r[14];
goto P_0c09e8cc;
P_0c09e8cc: /* original 64f3, guest PC 0x0c09e8cc */
if(!s->budget--) { s->failed_pc=0x0c09e8ccu; return 0; }
r[4]=r[15];
goto P_0c09e8ce;
P_0c09e8ce: /* original 4d0b, guest PC 0x0c09e8ce */
if(!s->budget--) { s->failed_pc=0x0c09e8ceu; return 0; }
target=r[13];
r[16]=code_base|0x0c09e8d2u;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e8d2u) { target=s->pc; goto dispatch; }
goto P_0c09e8d2;
P_0c09e8d0: /* original 7418, guest PC 0x0c09e8d0 */
if(!s->budget--) { s->failed_pc=0x0c09e8d0u; return 0; }
r[4]+=0x00000018u;
goto P_0c09e8d2;
P_0c09e8d2: /* original d35b, guest PC 0x0c09e8d2 */
if(!s->budget--) { s->failed_pc=0x0c09e8d2u; return 0; }
r[3]=read(ram,0x0c09ea40u,4);
goto P_0c09e8d4;
P_0c09e8d4: /* original 64e3, guest PC 0x0c09e8d4 */
if(!s->budget--) { s->failed_pc=0x0c09e8d4u; return 0; }
r[4]=r[14];
goto P_0c09e8d6;
P_0c09e8d6: /* original 740c, guest PC 0x0c09e8d6 */
if(!s->budget--) { s->failed_pc=0x0c09e8d6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c09e8d8;
P_0c09e8d8: /* original 430b, guest PC 0x0c09e8d8 */
if(!s->budget--) { s->failed_pc=0x0c09e8d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c09e8dcu;
vf3_matrix_load(s,ram,4,r[12]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e8dcu) { target=s->pc; goto dispatch; }
goto P_0c09e8dc;
P_0c09e8da: /* original f4c8, guest PC 0x0c09e8da */
if(!s->budget--) { s->failed_pc=0x0c09e8dau; return 0; }
vf3_matrix_load(s,ram,4,r[12]);
goto P_0c09e8dc;
P_0c09e8dc: /* original e00c, guest PC 0x0c09e8dc */
if(!s->budget--) { s->failed_pc=0x0c09e8dcu; return 0; }
r[0]=0x0000000cu;
goto P_0c09e8de;
P_0c09e8de: /* original f4a6, guest PC 0x0c09e8de */
if(!s->budget--) { s->failed_pc=0x0c09e8deu; return 0; }
vf3_matrix_load(s,ram,4,r[10]+r[0]);
goto P_0c09e8e0;
P_0c09e8e0: /* original e048, guest PC 0x0c09e8e0 */
if(!s->budget--) { s->failed_pc=0x0c09e8e0u; return 0; }
r[0]=0x00000048u;
goto P_0c09e8e2;
P_0c09e8e2: /* original f3f6, guest PC 0x0c09e8e2 */
if(!s->budget--) { s->failed_pc=0x0c09e8e2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e8e4;
P_0c09e8e4: /* original e018, guest PC 0x0c09e8e4 */
if(!s->budget--) { s->failed_pc=0x0c09e8e4u; return 0; }
r[0]=0x00000018u;
goto P_0c09e8e6;
P_0c09e8e6: /* original f2f6, guest PC 0x0c09e8e6 */
if(!s->budget--) { s->failed_pc=0x0c09e8e6u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09e8e8;
P_0c09e8e8: /* original e048, guest PC 0x0c09e8e8 */
if(!s->budget--) { s->failed_pc=0x0c09e8e8u; return 0; }
r[0]=0x00000048u;
goto P_0c09e8ea;
P_0c09e8ea: /* original f04c, guest PC 0x0c09e8ea */
if(!s->budget--) { s->failed_pc=0x0c09e8eau; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c09e8ec;
P_0c09e8ec: /* original f32e, guest PC 0x0c09e8ec */
if(!s->budget--) { s->failed_pc=0x0c09e8ecu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09e8ee;
P_0c09e8ee: /* original ff37, guest PC 0x0c09e8ee */
if(!s->budget--) { s->failed_pc=0x0c09e8eeu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e8f0;
P_0c09e8f0: /* original e04c, guest PC 0x0c09e8f0 */
if(!s->budget--) { s->failed_pc=0x0c09e8f0u; return 0; }
r[0]=0x0000004cu;
goto P_0c09e8f2;
P_0c09e8f2: /* original f3f6, guest PC 0x0c09e8f2 */
if(!s->budget--) { s->failed_pc=0x0c09e8f2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e8f4;
P_0c09e8f4: /* original e01c, guest PC 0x0c09e8f4 */
if(!s->budget--) { s->failed_pc=0x0c09e8f4u; return 0; }
r[0]=0x0000001cu;
goto P_0c09e8f6;
P_0c09e8f6: /* original f2f6, guest PC 0x0c09e8f6 */
if(!s->budget--) { s->failed_pc=0x0c09e8f6u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09e8f8;
P_0c09e8f8: /* original e04c, guest PC 0x0c09e8f8 */
if(!s->budget--) { s->failed_pc=0x0c09e8f8u; return 0; }
r[0]=0x0000004cu;
goto P_0c09e8fa;
P_0c09e8fa: /* original f32e, guest PC 0x0c09e8fa */
if(!s->budget--) { s->failed_pc=0x0c09e8fau; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09e8fc;
P_0c09e8fc: /* original ff37, guest PC 0x0c09e8fc */
if(!s->budget--) { s->failed_pc=0x0c09e8fcu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e8fe;
P_0c09e8fe: /* original e050, guest PC 0x0c09e8fe */
if(!s->budget--) { s->failed_pc=0x0c09e8feu; return 0; }
r[0]=0x00000050u;
goto P_0c09e900;
P_0c09e900: /* original f3f6, guest PC 0x0c09e900 */
if(!s->budget--) { s->failed_pc=0x0c09e900u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e902;
P_0c09e902: /* original e020, guest PC 0x0c09e902 */
if(!s->budget--) { s->failed_pc=0x0c09e902u; return 0; }
r[0]=0x00000020u;
goto P_0c09e904;
P_0c09e904: /* original f2f6, guest PC 0x0c09e904 */
if(!s->budget--) { s->failed_pc=0x0c09e904u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09e906;
P_0c09e906: /* original e050, guest PC 0x0c09e906 */
if(!s->budget--) { s->failed_pc=0x0c09e906u; return 0; }
r[0]=0x00000050u;
goto P_0c09e908;
P_0c09e908: /* original f32e, guest PC 0x0c09e908 */
if(!s->budget--) { s->failed_pc=0x0c09e908u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09e90a;
P_0c09e90a: /* original ff37, guest PC 0x0c09e90a */
if(!s->budget--) { s->failed_pc=0x0c09e90au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e90c;
P_0c09e90c: /* original e048, guest PC 0x0c09e90c */
if(!s->budget--) { s->failed_pc=0x0c09e90cu; return 0; }
r[0]=0x00000048u;
goto P_0c09e90e;
P_0c09e90e: /* original f3f6, guest PC 0x0c09e90e */
if(!s->budget--) { s->failed_pc=0x0c09e90eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e910;
P_0c09e910: /* original e030, guest PC 0x0c09e910 */
if(!s->budget--) { s->failed_pc=0x0c09e910u; return 0; }
r[0]=0x00000030u;
goto P_0c09e912;
P_0c09e912: /* original fb37, guest PC 0x0c09e912 */
if(!s->budget--) { s->failed_pc=0x0c09e912u; return 0; }
vf3_matrix_store(s,ram,3,r[11]+r[0]);
goto P_0c09e914;
P_0c09e914: /* original e04c, guest PC 0x0c09e914 */
if(!s->budget--) { s->failed_pc=0x0c09e914u; return 0; }
r[0]=0x0000004cu;
goto P_0c09e916;
P_0c09e916: /* original f3f6, guest PC 0x0c09e916 */
if(!s->budget--) { s->failed_pc=0x0c09e916u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e918;
P_0c09e918: /* original e034, guest PC 0x0c09e918 */
if(!s->budget--) { s->failed_pc=0x0c09e918u; return 0; }
r[0]=0x00000034u;
goto P_0c09e91a;
P_0c09e91a: /* original fb37, guest PC 0x0c09e91a */
if(!s->budget--) { s->failed_pc=0x0c09e91au; return 0; }
vf3_matrix_store(s,ram,3,r[11]+r[0]);
goto P_0c09e91c;
P_0c09e91c: /* original e050, guest PC 0x0c09e91c */
if(!s->budget--) { s->failed_pc=0x0c09e91cu; return 0; }
r[0]=0x00000050u;
goto P_0c09e91e;
P_0c09e91e: /* original f3f6, guest PC 0x0c09e91e */
if(!s->budget--) { s->failed_pc=0x0c09e91eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e920;
P_0c09e920: /* original e038, guest PC 0x0c09e920 */
if(!s->budget--) { s->failed_pc=0x0c09e920u; return 0; }
r[0]=0x00000038u;
goto P_0c09e922;
P_0c09e922: /* original fb37, guest PC 0x0c09e922 */
if(!s->budget--) { s->failed_pc=0x0c09e922u; return 0; }
vf3_matrix_store(s,ram,3,r[11]+r[0]);
goto P_0c09e924;
P_0c09e924: /* original e048, guest PC 0x0c09e924 */
if(!s->budget--) { s->failed_pc=0x0c09e924u; return 0; }
r[0]=0x00000048u;
goto P_0c09e926;
P_0c09e926: /* original 53f1, guest PC 0x0c09e926 */
if(!s->budget--) { s->failed_pc=0x0c09e926u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09e928;
P_0c09e928: /* original 7340, guest PC 0x0c09e928 */
if(!s->budget--) { s->failed_pc=0x0c09e928u; return 0; }
r[3]+=0x00000040u;
goto P_0c09e92a;
P_0c09e92a: /* original 2f32, guest PC 0x0c09e92a */
if(!s->budget--) { s->failed_pc=0x0c09e92au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09e92c;
P_0c09e92c: /* original f3f6, guest PC 0x0c09e92c */
if(!s->budget--) { s->failed_pc=0x0c09e92cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e92e;
P_0c09e92e: /* original 9077, guest PC 0x0c09e92e */
if(!s->budget--) { s->failed_pc=0x0c09e92eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ea20u,2);
goto P_0c09e930;
P_0c09e930: /* original ff37, guest PC 0x0c09e930 */
if(!s->budget--) { s->failed_pc=0x0c09e930u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e932;
P_0c09e932: /* original e04c, guest PC 0x0c09e932 */
if(!s->budget--) { s->failed_pc=0x0c09e932u; return 0; }
r[0]=0x0000004cu;
goto P_0c09e934;
P_0c09e934: /* original f3f6, guest PC 0x0c09e934 */
if(!s->budget--) { s->failed_pc=0x0c09e934u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e936;
P_0c09e936: /* original 9074, guest PC 0x0c09e936 */
if(!s->budget--) { s->failed_pc=0x0c09e936u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ea22u,2);
goto P_0c09e938;
P_0c09e938: /* original ff37, guest PC 0x0c09e938 */
if(!s->budget--) { s->failed_pc=0x0c09e938u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e93a;
P_0c09e93a: /* original e050, guest PC 0x0c09e93a */
if(!s->budget--) { s->failed_pc=0x0c09e93au; return 0; }
r[0]=0x00000050u;
goto P_0c09e93c;
P_0c09e93c: /* original f3f6, guest PC 0x0c09e93c */
if(!s->budget--) { s->failed_pc=0x0c09e93cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e93e;
P_0c09e93e: /* original 9071, guest PC 0x0c09e93e */
if(!s->budget--) { s->failed_pc=0x0c09e93eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ea24u,2);
goto P_0c09e940;
P_0c09e940: /* original ff37, guest PC 0x0c09e940 */
if(!s->budget--) { s->failed_pc=0x0c09e940u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e942;
P_0c09e942: /* original 946b, guest PC 0x0c09e942 */
if(!s->budget--) { s->failed_pc=0x0c09e942u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ea1cu,2);
goto P_0c09e944;
P_0c09e944: /* original d23b, guest PC 0x0c09e944 */
if(!s->budget--) { s->failed_pc=0x0c09e944u; return 0; }
r[2]=read(ram,0x0c09ea34u,4);
goto P_0c09e946;
P_0c09e946: /* original 420b, guest PC 0x0c09e946 */
if(!s->budget--) { s->failed_pc=0x0c09e946u; return 0; }
target=r[2];
r[16]=code_base|0x0c09e94au;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e94au) { target=s->pc; goto dispatch; }
goto P_0c09e94a;
P_0c09e948: /* original 34fc, guest PC 0x0c09e948 */
if(!s->budget--) { s->failed_pc=0x0c09e948u; return 0; }
r[4]+=r[15];
goto P_0c09e94a;
P_0c09e94a: /* original 4d0b, guest PC 0x0c09e94a */
if(!s->budget--) { s->failed_pc=0x0c09e94au; return 0; }
target=r[13];
r[16]=code_base|0x0c09e94eu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e94eu) { target=s->pc; goto dispatch; }
goto P_0c09e94e;
P_0c09e94c: /* original 64f2, guest PC 0x0c09e94c */
if(!s->budget--) { s->failed_pc=0x0c09e94cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c09e94e;
P_0c09e94e: /* original e048, guest PC 0x0c09e94e */
if(!s->budget--) { s->failed_pc=0x0c09e94eu; return 0; }
r[0]=0x00000048u;
goto P_0c09e950;
P_0c09e950: /* original 64e3, guest PC 0x0c09e950 */
if(!s->budget--) { s->failed_pc=0x0c09e950u; return 0; }
r[4]=r[14];
goto P_0c09e952;
P_0c09e952: /* original f3f6, guest PC 0x0c09e952 */
if(!s->budget--) { s->failed_pc=0x0c09e952u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e954;
P_0c09e954: /* original e018, guest PC 0x0c09e954 */
if(!s->budget--) { s->failed_pc=0x0c09e954u; return 0; }
r[0]=0x00000018u;
goto P_0c09e956;
P_0c09e956: /* original 7424, guest PC 0x0c09e956 */
if(!s->budget--) { s->failed_pc=0x0c09e956u; return 0; }
r[4]+=0x00000024u;
goto P_0c09e958;
P_0c09e958: /* original fe37, guest PC 0x0c09e958 */
if(!s->budget--) { s->failed_pc=0x0c09e958u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09e95a;
P_0c09e95a: /* original e04c, guest PC 0x0c09e95a */
if(!s->budget--) { s->failed_pc=0x0c09e95au; return 0; }
r[0]=0x0000004cu;
goto P_0c09e95c;
P_0c09e95c: /* original f3f6, guest PC 0x0c09e95c */
if(!s->budget--) { s->failed_pc=0x0c09e95cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e95e;
P_0c09e95e: /* original e01c, guest PC 0x0c09e95e */
if(!s->budget--) { s->failed_pc=0x0c09e95eu; return 0; }
r[0]=0x0000001cu;
goto P_0c09e960;
P_0c09e960: /* original fe37, guest PC 0x0c09e960 */
if(!s->budget--) { s->failed_pc=0x0c09e960u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09e962;
P_0c09e962: /* original e050, guest PC 0x0c09e962 */
if(!s->budget--) { s->failed_pc=0x0c09e962u; return 0; }
r[0]=0x00000050u;
goto P_0c09e964;
P_0c09e964: /* original f3f6, guest PC 0x0c09e964 */
if(!s->budget--) { s->failed_pc=0x0c09e964u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e966;
P_0c09e966: /* original e020, guest PC 0x0c09e966 */
if(!s->budget--) { s->failed_pc=0x0c09e966u; return 0; }
r[0]=0x00000020u;
goto P_0c09e968;
P_0c09e968: /* original fe37, guest PC 0x0c09e968 */
if(!s->budget--) { s->failed_pc=0x0c09e968u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09e96a;
P_0c09e96a: /* original e004, guest PC 0x0c09e96a */
if(!s->budget--) { s->failed_pc=0x0c09e96au; return 0; }
r[0]=0x00000004u;
goto P_0c09e96c;
P_0c09e96c: /* original d334, guest PC 0x0c09e96c */
if(!s->budget--) { s->failed_pc=0x0c09e96cu; return 0; }
r[3]=read(ram,0x0c09ea40u,4);
goto P_0c09e96e;
P_0c09e96e: /* original 430b, guest PC 0x0c09e96e */
if(!s->budget--) { s->failed_pc=0x0c09e96eu; return 0; }
target=r[3];
r[16]=code_base|0x0c09e972u;
vf3_matrix_load(s,ram,4,r[12]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e972u) { target=s->pc; goto dispatch; }
goto P_0c09e972;
P_0c09e970: /* original f4c6, guest PC 0x0c09e970 */
if(!s->budget--) { s->failed_pc=0x0c09e970u; return 0; }
vf3_matrix_load(s,ram,4,r[12]+r[0]);
goto P_0c09e972;
P_0c09e972: /* original d333, guest PC 0x0c09e972 */
if(!s->budget--) { s->failed_pc=0x0c09e972u; return 0; }
r[3]=read(ram,0x0c09ea40u,4);
goto P_0c09e974;
P_0c09e974: /* original 64e3, guest PC 0x0c09e974 */
if(!s->budget--) { s->failed_pc=0x0c09e974u; return 0; }
r[4]=r[14];
goto P_0c09e976;
P_0c09e976: /* original e008, guest PC 0x0c09e976 */
if(!s->budget--) { s->failed_pc=0x0c09e976u; return 0; }
r[0]=0x00000008u;
goto P_0c09e978;
P_0c09e978: /* original 7430, guest PC 0x0c09e978 */
if(!s->budget--) { s->failed_pc=0x0c09e978u; return 0; }
r[4]+=0x00000030u;
goto P_0c09e97a;
P_0c09e97a: /* original 430b, guest PC 0x0c09e97a */
if(!s->budget--) { s->failed_pc=0x0c09e97au; return 0; }
target=r[3];
r[16]=code_base|0x0c09e97eu;
vf3_matrix_load(s,ram,4,r[12]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e97eu) { target=s->pc; goto dispatch; }
goto P_0c09e97e;
P_0c09e97c: /* original f4c6, guest PC 0x0c09e97c */
if(!s->budget--) { s->failed_pc=0x0c09e97cu; return 0; }
vf3_matrix_load(s,ram,4,r[12]+r[0]);
goto P_0c09e97e;
P_0c09e97e: /* original e018, guest PC 0x0c09e97e */
if(!s->budget--) { s->failed_pc=0x0c09e97eu; return 0; }
r[0]=0x00000018u;
goto P_0c09e980;
P_0c09e980: /* original d330, guest PC 0x0c09e980 */
if(!s->budget--) { s->failed_pc=0x0c09e980u; return 0; }
r[3]=read(ram,0x0c09ea44u,4);
goto P_0c09e982;
P_0c09e982: /* original f4a6, guest PC 0x0c09e982 */
if(!s->budget--) { s->failed_pc=0x0c09e982u; return 0; }
vf3_matrix_load(s,ram,4,r[10]+r[0]);
goto P_0c09e984;
P_0c09e984: /* original f6fc, guest PC 0x0c09e984 */
if(!s->budget--) { s->failed_pc=0x0c09e984u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c09e986;
P_0c09e986: /* original 430b, guest PC 0x0c09e986 */
if(!s->budget--) { s->failed_pc=0x0c09e986u; return 0; }
target=r[3];
r[16]=code_base|0x0c09e98au;
vf3_matrix_move(s,5,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e98au) { target=s->pc; goto dispatch; }
goto P_0c09e98a;
P_0c09e988: /* original f5fc, guest PC 0x0c09e988 */
if(!s->budget--) { s->failed_pc=0x0c09e988u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09e98a;
P_0c09e98a: /* original 904c, guest PC 0x0c09e98a */
if(!s->budget--) { s->failed_pc=0x0c09e98au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ea26u,2);
goto P_0c09e98c;
P_0c09e98c: /* original 55f5, guest PC 0x0c09e98c */
if(!s->budget--) { s->failed_pc=0x0c09e98cu; return 0; }
r[5]=read(ram,r[15]+20,4);
goto P_0c09e98e;
P_0c09e98e: /* original 04fe, guest PC 0x0c09e98e */
if(!s->budget--) { s->failed_pc=0x0c09e98eu; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c09e990;
P_0c09e990: /* original b845, guest PC 0x0c09e990 */
if(!s->budget--) { s->failed_pc=0x0c09e990u; return 0; }
target=code_base|0x0c09da1eu; r[16]=code_base|0x0c09e994u;
r[4]+=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e994u) { target=s->pc; goto dispatch; }
goto P_0c09e994;
P_0c09e992: /* original 7406, guest PC 0x0c09e992 */
if(!s->budget--) { s->failed_pc=0x0c09e992u; return 0; }
r[4]+=0x00000006u;
goto P_0c09e994;
P_0c09e994: /* original 64f3, guest PC 0x0c09e994 */
if(!s->budget--) { s->failed_pc=0x0c09e994u; return 0; }
r[4]=r[15];
goto P_0c09e996;
P_0c09e996: /* original 4d0b, guest PC 0x0c09e996 */
if(!s->budget--) { s->failed_pc=0x0c09e996u; return 0; }
target=r[13];
r[16]=code_base|0x0c09e99au;
r[4]+=0x00000070u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e99au) { target=s->pc; goto dispatch; }
goto P_0c09e99a;
P_0c09e998: /* original 7470, guest PC 0x0c09e998 */
if(!s->budget--) { s->failed_pc=0x0c09e998u; return 0; }
r[4]+=0x00000070u;
goto P_0c09e99a;
P_0c09e99a: /* original 54f1, guest PC 0x0c09e99a */
if(!s->budget--) { s->failed_pc=0x0c09e99au; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c09e99c;
P_0c09e99c: /* original 65f3, guest PC 0x0c09e99c */
if(!s->budget--) { s->failed_pc=0x0c09e99cu; return 0; }
r[5]=r[15];
goto P_0c09e99e;
P_0c09e99e: /* original 9343, guest PC 0x0c09e99e */
if(!s->budget--) { s->failed_pc=0x0c09e99eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ea28u,2);
goto P_0c09e9a0;
P_0c09e9a0: /* original d229, guest PC 0x0c09e9a0 */
if(!s->budget--) { s->failed_pc=0x0c09e9a0u; return 0; }
r[2]=read(ram,0x0c09ea48u,4);
goto P_0c09e9a2;
P_0c09e9a2: /* original 343c, guest PC 0x0c09e9a2 */
if(!s->budget--) { s->failed_pc=0x0c09e9a2u; return 0; }
r[4]+=r[3];
goto P_0c09e9a4;
P_0c09e9a4: /* original 420b, guest PC 0x0c09e9a4 */
if(!s->budget--) { s->failed_pc=0x0c09e9a4u; return 0; }
target=r[2];
r[16]=code_base|0x0c09e9a8u;
r[5]+=0x00000070u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e9a8u) { target=s->pc; goto dispatch; }
goto P_0c09e9a8;
P_0c09e9a6: /* original 7570, guest PC 0x0c09e9a6 */
if(!s->budget--) { s->failed_pc=0x0c09e9a6u; return 0; }
r[5]+=0x00000070u;
goto P_0c09e9a8;
P_0c09e9a8: /* original c728, guest PC 0x0c09e9a8 */
if(!s->budget--) { s->failed_pc=0x0c09e9a8u; return 0; }
r[0]=code_base|0x0009ea4cu;
goto P_0c09e9aa;
P_0c09e9aa: /* original 64f3, guest PC 0x0c09e9aa */
if(!s->budget--) { s->failed_pc=0x0c09e9aau; return 0; }
r[4]=r[15];
goto P_0c09e9ac;
P_0c09e9ac: /* original f308, guest PC 0x0c09e9ac */
if(!s->budget--) { s->failed_pc=0x0c09e9acu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09e9ae;
P_0c09e9ae: /* original e05c, guest PC 0x0c09e9ae */
if(!s->budget--) { s->failed_pc=0x0c09e9aeu; return 0; }
r[0]=0x0000005cu;
goto P_0c09e9b0;
P_0c09e9b0: /* original ff37, guest PC 0x0c09e9b0 */
if(!s->budget--) { s->failed_pc=0x0c09e9b0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e9b2;
P_0c09e9b2: /* original e060, guest PC 0x0c09e9b2 */
if(!s->budget--) { s->failed_pc=0x0c09e9b2u; return 0; }
r[0]=0x00000060u;
goto P_0c09e9b4;
P_0c09e9b4: /* original f43c, guest PC 0x0c09e9b4 */
if(!s->budget--) { s->failed_pc=0x0c09e9b4u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c09e9b6;
P_0c09e9b6: /* original f340, guest PC 0x0c09e9b6 */
if(!s->budget--) { s->failed_pc=0x0c09e9b6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c09e9b8;
P_0c09e9b8: /* original ff37, guest PC 0x0c09e9b8 */
if(!s->budget--) { s->failed_pc=0x0c09e9b8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e9ba;
P_0c09e9ba: /* original e05c, guest PC 0x0c09e9ba */
if(!s->budget--) { s->failed_pc=0x0c09e9bau; return 0; }
r[0]=0x0000005cu;
goto P_0c09e9bc;
P_0c09e9bc: /* original f4f6, guest PC 0x0c09e9bc */
if(!s->budget--) { s->failed_pc=0x0c09e9bcu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c09e9be;
P_0c09e9be: /* original e058, guest PC 0x0c09e9be */
if(!s->budget--) { s->failed_pc=0x0c09e9beu; return 0; }
r[0]=0x00000058u;
goto P_0c09e9c0;
P_0c09e9c0: /* original f34c, guest PC 0x0c09e9c0 */
if(!s->budget--) { s->failed_pc=0x0c09e9c0u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c09e9c2;
P_0c09e9c2: /* original f341, guest PC 0x0c09e9c2 */
if(!s->budget--) { s->failed_pc=0x0c09e9c2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c09e9c4;
P_0c09e9c4: /* original ff37, guest PC 0x0c09e9c4 */
if(!s->budget--) { s->failed_pc=0x0c09e9c4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e9c6;
P_0c09e9c6: /* original 9030, guest PC 0x0c09e9c6 */
if(!s->budget--) { s->failed_pc=0x0c09e9c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ea2au,2);
goto P_0c09e9c8;
P_0c09e9c8: /* original d321, guest PC 0x0c09e9c8 */
if(!s->budget--) { s->failed_pc=0x0c09e9c8u; return 0; }
r[3]=read(ram,0x0c09ea50u,4);
goto P_0c09e9ca;
P_0c09e9ca: /* original 05fe, guest PC 0x0c09e9ca */
if(!s->budget--) { s->failed_pc=0x0c09e9cau; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c09e9cc;
P_0c09e9cc: /* original 430b, guest PC 0x0c09e9cc */
if(!s->budget--) { s->failed_pc=0x0c09e9ccu; return 0; }
target=r[3];
r[16]=code_base|0x0c09e9d0u;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e9d0u) { target=s->pc; goto dispatch; }
goto P_0c09e9d0;
P_0c09e9ce: /* original 7458, guest PC 0x0c09e9ce */
if(!s->budget--) { s->failed_pc=0x0c09e9ceu; return 0; }
r[4]+=0x00000058u;
goto P_0c09e9d0;
P_0c09e9d0: /* original d320, guest PC 0x0c09e9d0 */
if(!s->budget--) { s->failed_pc=0x0c09e9d0u; return 0; }
r[3]=read(ram,0x0c09ea54u,4);
goto P_0c09e9d2;
P_0c09e9d2: /* original 64e3, guest PC 0x0c09e9d2 */
if(!s->budget--) { s->failed_pc=0x0c09e9d2u; return 0; }
r[4]=r[14];
goto P_0c09e9d4;
P_0c09e9d4: /* original e00c, guest PC 0x0c09e9d4 */
if(!s->budget--) { s->failed_pc=0x0c09e9d4u; return 0; }
r[0]=0x0000000cu;
goto P_0c09e9d6;
P_0c09e9d6: /* original 743c, guest PC 0x0c09e9d6 */
if(!s->budget--) { s->failed_pc=0x0c09e9d6u; return 0; }
r[4]+=0x0000003cu;
goto P_0c09e9d8;
P_0c09e9d8: /* original 430b, guest PC 0x0c09e9d8 */
if(!s->budget--) { s->failed_pc=0x0c09e9d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c09e9dcu;
vf3_matrix_load(s,ram,4,r[12]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e9dcu) { target=s->pc; goto dispatch; }
goto P_0c09e9dc;
P_0c09e9da: /* original f4c6, guest PC 0x0c09e9da */
if(!s->budget--) { s->failed_pc=0x0c09e9dau; return 0; }
vf3_matrix_load(s,ram,4,r[12]+r[0]);
goto P_0c09e9dc;
P_0c09e9dc: /* original e064, guest PC 0x0c09e9dc */
if(!s->budget--) { s->failed_pc=0x0c09e9dcu; return 0; }
r[0]=0x00000064u;
goto P_0c09e9de;
P_0c09e9de: /* original 65e3, guest PC 0x0c09e9de */
if(!s->budget--) { s->failed_pc=0x0c09e9deu; return 0; }
r[5]=r[14];
goto P_0c09e9e0;
P_0c09e9e0: /* original fff7, guest PC 0x0c09e9e0 */
if(!s->budget--) { s->failed_pc=0x0c09e9e0u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c09e9e2;
P_0c09e9e2: /* original e010, guest PC 0x0c09e9e2 */
if(!s->budget--) { s->failed_pc=0x0c09e9e2u; return 0; }
r[0]=0x00000010u;
goto P_0c09e9e4;
P_0c09e9e4: /* original f3c6, guest PC 0x0c09e9e4 */
if(!s->budget--) { s->failed_pc=0x0c09e9e4u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c09e9e6;
P_0c09e9e6: /* original e068, guest PC 0x0c09e9e6 */
if(!s->budget--) { s->failed_pc=0x0c09e9e6u; return 0; }
r[0]=0x00000068u;
goto P_0c09e9e8;
P_0c09e9e8: /* original 64f3, guest PC 0x0c09e9e8 */
if(!s->budget--) { s->failed_pc=0x0c09e9e8u; return 0; }
r[4]=r[15];
goto P_0c09e9ea;
P_0c09e9ea: /* original 7548, guest PC 0x0c09e9ea */
if(!s->budget--) { s->failed_pc=0x0c09e9eau; return 0; }
r[5]+=0x00000048u;
goto P_0c09e9ec;
P_0c09e9ec: /* original ff37, guest PC 0x0c09e9ec */
if(!s->budget--) { s->failed_pc=0x0c09e9ecu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e9ee;
P_0c09e9ee: /* original e014, guest PC 0x0c09e9ee */
if(!s->budget--) { s->failed_pc=0x0c09e9eeu; return 0; }
r[0]=0x00000014u;
goto P_0c09e9f0;
P_0c09e9f0: /* original f3c6, guest PC 0x0c09e9f0 */
if(!s->budget--) { s->failed_pc=0x0c09e9f0u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c09e9f2;
P_0c09e9f2: /* original e06c, guest PC 0x0c09e9f2 */
if(!s->budget--) { s->failed_pc=0x0c09e9f2u; return 0; }
r[0]=0x0000006cu;
goto P_0c09e9f4;
P_0c09e9f4: /* original ff37, guest PC 0x0c09e9f4 */
if(!s->budget--) { s->failed_pc=0x0c09e9f4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e9f6;
P_0c09e9f6: /* original d316, guest PC 0x0c09e9f6 */
if(!s->budget--) { s->failed_pc=0x0c09e9f6u; return 0; }
r[3]=read(ram,0x0c09ea50u,4);
goto P_0c09e9f8;
P_0c09e9f8: /* original 430b, guest PC 0x0c09e9f8 */
if(!s->budget--) { s->failed_pc=0x0c09e9f8u; return 0; }
target=r[3];
r[16]=code_base|0x0c09e9fcu;
r[4]+=0x00000064u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e9fcu) { target=s->pc; goto dispatch; }
goto P_0c09e9fc;
P_0c09e9fa: /* original 7464, guest PC 0x0c09e9fa */
if(!s->budget--) { s->failed_pc=0x0c09e9fau; return 0; }
r[4]+=0x00000064u;
goto P_0c09e9fc;
P_0c09e9fc: /* original 490b, guest PC 0x0c09e9fc */
if(!s->budget--) { s->failed_pc=0x0c09e9fcu; return 0; }
target=r[9];
r[16]=code_base|0x0c09ea00u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ea00u) { target=s->pc; goto dispatch; }
goto P_0c09ea00;
P_0c09e9fe: /* original e401, guest PC 0x0c09e9fe */
if(!s->budget--) { s->failed_pc=0x0c09e9feu; return 0; }
r[4]=0x00000001u;
goto P_0c09ea00;
P_0c09ea00: /* original 9114, guest PC 0x0c09ea00 */
if(!s->budget--) { s->failed_pc=0x0c09ea00u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ea2cu,2);
goto P_0c09ea02;
P_0c09ea02: /* original 3f1c, guest PC 0x0c09ea02 */
if(!s->budget--) { s->failed_pc=0x0c09ea02u; return 0; }
r[15]+=r[1];
goto P_0c09ea04;
P_0c09ea04: /* original 4f26, guest PC 0x0c09ea04 */
if(!s->budget--) { s->failed_pc=0x0c09ea04u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09ea06;
P_0c09ea06: /* original fdf9, guest PC 0x0c09ea06 */
if(!s->budget--) { s->failed_pc=0x0c09ea06u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09ea08;
P_0c09ea08: /* original fef9, guest PC 0x0c09ea08 */
if(!s->budget--) { s->failed_pc=0x0c09ea08u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09ea0a;
P_0c09ea0a: /* original fff9, guest PC 0x0c09ea0a */
if(!s->budget--) { s->failed_pc=0x0c09ea0au; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09ea0c;
P_0c09ea0c: /* original 68f6, guest PC 0x0c09ea0c */
if(!s->budget--) { s->failed_pc=0x0c09ea0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09ea0e;
P_0c09ea0e: /* original 69f6, guest PC 0x0c09ea0e */
if(!s->budget--) { s->failed_pc=0x0c09ea0eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09ea10;
P_0c09ea10: /* original 6af6, guest PC 0x0c09ea10 */
if(!s->budget--) { s->failed_pc=0x0c09ea10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09ea12;
P_0c09ea12: /* original 6bf6, guest PC 0x0c09ea12 */
if(!s->budget--) { s->failed_pc=0x0c09ea12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09ea14;
P_0c09ea14: /* original 6cf6, guest PC 0x0c09ea14 */
if(!s->budget--) { s->failed_pc=0x0c09ea14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09ea16;
P_0c09ea16: /* original 6df6, guest PC 0x0c09ea16 */
if(!s->budget--) { s->failed_pc=0x0c09ea16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09ea18;
P_0c09ea18: /* original 000b, guest PC 0x0c09ea18 */
if(!s->budget--) { s->failed_pc=0x0c09ea18u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09ea1a: /* original 6ef6, guest PC 0x0c09ea1a */
if(!s->budget--) { s->failed_pc=0x0c09ea1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09ea1cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09ea1cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
