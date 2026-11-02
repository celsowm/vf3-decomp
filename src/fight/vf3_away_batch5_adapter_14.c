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
int vf3_away_batch5_adapter_14(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c04e7dcu: goto P_0c04e7dc;
case 0x0c04e7deu: goto P_0c04e7de;
case 0x0c04e7e0u: goto P_0c04e7e0;
case 0x0c04e7e2u: goto P_0c04e7e2;
case 0x0c04e7e4u: goto P_0c04e7e4;
case 0x0c04e7e6u: goto P_0c04e7e6;
case 0x0c04e7e8u: goto P_0c04e7e8;
case 0x0c04e7eau: goto P_0c04e7ea;
case 0x0c04e7ecu: goto P_0c04e7ec;
case 0x0c04e7eeu: goto P_0c04e7ee;
case 0x0c04e7f0u: goto P_0c04e7f0;
case 0x0c04e7f2u: goto P_0c04e7f2;
case 0x0c04e7f4u: goto P_0c04e7f4;
case 0x0c04e7f6u: goto P_0c04e7f6;
case 0x0c04e7f8u: goto P_0c04e7f8;
case 0x0c04e7fau: goto P_0c04e7fa;
case 0x0c04e7fcu: goto P_0c04e7fc;
case 0x0c04e7feu: goto P_0c04e7fe;
case 0x0c04e800u: goto P_0c04e800;
case 0x0c04e802u: goto P_0c04e802;
case 0x0c04e804u: goto P_0c04e804;
case 0x0c04e806u: goto P_0c04e806;
case 0x0c04e808u: goto P_0c04e808;
case 0x0c04e80au: goto P_0c04e80a;
case 0x0c04e80cu: goto P_0c04e80c;
case 0x0c04e80eu: goto P_0c04e80e;
case 0x0c04e810u: goto P_0c04e810;
case 0x0c04e812u: goto P_0c04e812;
case 0x0c04e814u: goto P_0c04e814;
case 0x0c04e816u: goto P_0c04e816;
case 0x0c04e818u: goto P_0c04e818;
case 0x0c04e81au: goto P_0c04e81a;
case 0x0c04e81cu: goto P_0c04e81c;
case 0x0c04e81eu: goto P_0c04e81e;
case 0x0c04e820u: goto P_0c04e820;
case 0x0c04e822u: goto P_0c04e822;
case 0x0c04e824u: goto P_0c04e824;
case 0x0c04e826u: goto P_0c04e826;
case 0x0c04e828u: goto P_0c04e828;
case 0x0c04e82au: goto P_0c04e82a;
case 0x0c04e82cu: goto P_0c04e82c;
case 0x0c04e82eu: goto P_0c04e82e;
case 0x0c04e830u: goto P_0c04e830;
case 0x0c04e832u: goto P_0c04e832;
case 0x0c04e834u: goto P_0c04e834;
case 0x0c04e836u: goto P_0c04e836;
case 0x0c04e838u: goto P_0c04e838;
case 0x0c04e83au: goto P_0c04e83a;
case 0x0c04e83cu: goto P_0c04e83c;
case 0x0c04e83eu: goto P_0c04e83e;
case 0x0c04e840u: goto P_0c04e840;
case 0x0c04e842u: goto P_0c04e842;
case 0x0c04e844u: goto P_0c04e844;
case 0x0c04e846u: goto P_0c04e846;
case 0x0c04e848u: goto P_0c04e848;
case 0x0c04e84au: goto P_0c04e84a;
case 0x0c04e84cu: goto P_0c04e84c;
case 0x0c04e84eu: goto P_0c04e84e;
case 0x0c04e850u: goto P_0c04e850;
case 0x0c04e852u: goto P_0c04e852;
case 0x0c04e854u: goto P_0c04e854;
case 0x0c04e856u: goto P_0c04e856;
case 0x0c04e858u: goto P_0c04e858;
case 0x0c04e85au: goto P_0c04e85a;
case 0x0c04e85cu: goto P_0c04e85c;
case 0x0c04e85eu: goto P_0c04e85e;
case 0x0c04e860u: goto P_0c04e860;
case 0x0c04e862u: goto P_0c04e862;
case 0x0c04e864u: goto P_0c04e864;
case 0x0c04e866u: goto P_0c04e866;
case 0x0c04e868u: goto P_0c04e868;
case 0x0c04e86au: goto P_0c04e86a;
case 0x0c04e86cu: goto P_0c04e86c;
case 0x0c04e86eu: goto P_0c04e86e;
case 0x0c04e870u: goto P_0c04e870;
case 0x0c04e872u: goto P_0c04e872;
case 0x0c04e874u: goto P_0c04e874;
case 0x0c04e876u: goto P_0c04e876;
case 0x0c04e878u: goto P_0c04e878;
case 0x0c04e87au: goto P_0c04e87a;
case 0x0c04e87cu: goto P_0c04e87c;
case 0x0c04e87eu: goto P_0c04e87e;
case 0x0c04e880u: goto P_0c04e880;
case 0x0c04e882u: goto P_0c04e882;
case 0x0c04e884u: goto P_0c04e884;
case 0x0c04e886u: goto P_0c04e886;
case 0x0c04e888u: goto P_0c04e888;
case 0x0c04e88au: goto P_0c04e88a;
case 0x0c04e88cu: goto P_0c04e88c;
case 0x0c04e88eu: goto P_0c04e88e;
case 0x0c04e890u: goto P_0c04e890;
case 0x0c04e892u: goto P_0c04e892;
case 0x0c04e894u: goto P_0c04e894;
case 0x0c04e896u: goto P_0c04e896;
case 0x0c04e898u: goto P_0c04e898;
case 0x0c04e89au: goto P_0c04e89a;
case 0x0c04e89cu: goto P_0c04e89c;
case 0x0c04e89eu: goto P_0c04e89e;
case 0x0c04e8a0u: goto P_0c04e8a0;
case 0x0c04e8a2u: goto P_0c04e8a2;
case 0x0c04e8a4u: goto P_0c04e8a4;
case 0x0c04e8a6u: goto P_0c04e8a6;
case 0x0c04e8a8u: goto P_0c04e8a8;
case 0x0c04e8aau: goto P_0c04e8aa;
case 0x0c04e8acu: goto P_0c04e8ac;
case 0x0c04e8aeu: goto P_0c04e8ae;
case 0x0c04e8b0u: goto P_0c04e8b0;
case 0x0c04e8e4u: goto P_0c04e8e4;
case 0x0c04e8e6u: goto P_0c04e8e6;
case 0x0c04e8e8u: goto P_0c04e8e8;
case 0x0c04e8eau: goto P_0c04e8ea;
case 0x0c04e8ecu: goto P_0c04e8ec;
case 0x0c04e8eeu: goto P_0c04e8ee;
case 0x0c04e8f0u: goto P_0c04e8f0;
case 0x0c04e8f2u: goto P_0c04e8f2;
case 0x0c04e8f4u: goto P_0c04e8f4;
case 0x0c04e8f6u: goto P_0c04e8f6;
case 0x0c04e8f8u: goto P_0c04e8f8;
case 0x0c04e8fau: goto P_0c04e8fa;
case 0x0c04e8fcu: goto P_0c04e8fc;
case 0x0c04e8feu: goto P_0c04e8fe;
case 0x0c04e900u: goto P_0c04e900;
case 0x0c04e902u: goto P_0c04e902;
case 0x0c04e904u: goto P_0c04e904;
case 0x0c04e906u: goto P_0c04e906;
case 0x0c04e908u: goto P_0c04e908;
case 0x0c04e90au: goto P_0c04e90a;
case 0x0c04e90cu: goto P_0c04e90c;
case 0x0c04e90eu: goto P_0c04e90e;
case 0x0c04e910u: goto P_0c04e910;
case 0x0c04e912u: goto P_0c04e912;
case 0x0c04e914u: goto P_0c04e914;
case 0x0c04e916u: goto P_0c04e916;
case 0x0c04e918u: goto P_0c04e918;
case 0x0c04e91au: goto P_0c04e91a;
case 0x0c04e91cu: goto P_0c04e91c;
case 0x0c04e91eu: goto P_0c04e91e;
case 0x0c04e920u: goto P_0c04e920;
case 0x0c04e922u: goto P_0c04e922;
case 0x0c04e924u: goto P_0c04e924;
case 0x0c04e926u: goto P_0c04e926;
case 0x0c04e928u: goto P_0c04e928;
case 0x0c04e92au: goto P_0c04e92a;
case 0x0c04e92cu: goto P_0c04e92c;
case 0x0c04e92eu: goto P_0c04e92e;
case 0x0c04e930u: goto P_0c04e930;
case 0x0c04e932u: goto P_0c04e932;
case 0x0c04e934u: goto P_0c04e934;
case 0x0c04e936u: goto P_0c04e936;
case 0x0c04e938u: goto P_0c04e938;
case 0x0c04e93au: goto P_0c04e93a;
case 0x0c04e93cu: goto P_0c04e93c;
case 0x0c04e93eu: goto P_0c04e93e;
case 0x0c04e940u: goto P_0c04e940;
case 0x0c04e942u: goto P_0c04e942;
case 0x0c04e944u: goto P_0c04e944;
case 0x0c04e946u: goto P_0c04e946;
case 0x0c04e948u: goto P_0c04e948;
case 0x0c04e94au: goto P_0c04e94a;
case 0x0c04e94cu: goto P_0c04e94c;
case 0x0c04e94eu: goto P_0c04e94e;
case 0x0c04e950u: goto P_0c04e950;
case 0x0c04e952u: goto P_0c04e952;
case 0x0c04e954u: goto P_0c04e954;
case 0x0c04e956u: goto P_0c04e956;
case 0x0c04e958u: goto P_0c04e958;
case 0x0c04e95au: goto P_0c04e95a;
case 0x0c04e95cu: goto P_0c04e95c;
case 0x0c04e95eu: goto P_0c04e95e;
case 0x0c04e960u: goto P_0c04e960;
case 0x0c04e962u: goto P_0c04e962;
case 0x0c04e964u: goto P_0c04e964;
case 0x0c04e966u: goto P_0c04e966;
case 0x0c04e968u: goto P_0c04e968;
case 0x0c04e96au: goto P_0c04e96a;
case 0x0c04e96cu: goto P_0c04e96c;
case 0x0c04e96eu: goto P_0c04e96e;
case 0x0c04e970u: goto P_0c04e970;
case 0x0c04e972u: goto P_0c04e972;
case 0x0c04e974u: goto P_0c04e974;
case 0x0c04e976u: goto P_0c04e976;
case 0x0c04e978u: goto P_0c04e978;
case 0x0c04e97au: goto P_0c04e97a;
case 0x0c04e97cu: goto P_0c04e97c;
case 0x0c04e97eu: goto P_0c04e97e;
case 0x0c04e980u: goto P_0c04e980;
case 0x0c04e982u: goto P_0c04e982;
case 0x0c04e984u: goto P_0c04e984;
case 0x0c04e986u: goto P_0c04e986;
case 0x0c04e988u: goto P_0c04e988;
case 0x0c04e98au: goto P_0c04e98a;
case 0x0c04e98cu: goto P_0c04e98c;
case 0x0c04e98eu: goto P_0c04e98e;
case 0x0c04e990u: goto P_0c04e990;
case 0x0c04e992u: goto P_0c04e992;
case 0x0c04e994u: goto P_0c04e994;
case 0x0c04e996u: goto P_0c04e996;
case 0x0c04e998u: goto P_0c04e998;
case 0x0c04e99au: goto P_0c04e99a;
case 0x0c04e99cu: goto P_0c04e99c;
case 0x0c04e99eu: goto P_0c04e99e;
case 0x0c04e9ccu: goto P_0c04e9cc;
case 0x0c04e9ceu: goto P_0c04e9ce;
case 0x0c04e9d0u: goto P_0c04e9d0;
case 0x0c04e9d2u: goto P_0c04e9d2;
case 0x0c04e9d4u: goto P_0c04e9d4;
case 0x0c04e9d6u: goto P_0c04e9d6;
case 0x0c04e9d8u: goto P_0c04e9d8;
case 0x0c04e9dau: goto P_0c04e9da;
case 0x0c04e9dcu: goto P_0c04e9dc;
case 0x0c04e9deu: goto P_0c04e9de;
case 0x0c04e9e0u: goto P_0c04e9e0;
case 0x0c04e9e2u: goto P_0c04e9e2;
case 0x0c04e9e4u: goto P_0c04e9e4;
case 0x0c04e9e6u: goto P_0c04e9e6;
case 0x0c04e9e8u: goto P_0c04e9e8;
case 0x0c04e9eau: goto P_0c04e9ea;
case 0x0c04e9ecu: goto P_0c04e9ec;
case 0x0c04e9eeu: goto P_0c04e9ee;
case 0x0c04e9f0u: goto P_0c04e9f0;
case 0x0c04e9f2u: goto P_0c04e9f2;
case 0x0c04e9f4u: goto P_0c04e9f4;
case 0x0c04e9f6u: goto P_0c04e9f6;
case 0x0c04e9f8u: goto P_0c04e9f8;
case 0x0c04e9fau: goto P_0c04e9fa;
case 0x0c04e9fcu: goto P_0c04e9fc;
case 0x0c04e9feu: goto P_0c04e9fe;
case 0x0c04ea00u: goto P_0c04ea00;
case 0x0c04ea02u: goto P_0c04ea02;
case 0x0c04ea04u: goto P_0c04ea04;
case 0x0c04ea06u: goto P_0c04ea06;
case 0x0c04ea08u: goto P_0c04ea08;
case 0x0c04ea0au: goto P_0c04ea0a;
case 0x0c04ea0cu: goto P_0c04ea0c;
case 0x0c04ea0eu: goto P_0c04ea0e;
case 0x0c04ea10u: goto P_0c04ea10;
case 0x0c04ea12u: goto P_0c04ea12;
case 0x0c04ea14u: goto P_0c04ea14;
case 0x0c04ea16u: goto P_0c04ea16;
case 0x0c04ea18u: goto P_0c04ea18;
case 0x0c04ea1au: goto P_0c04ea1a;
case 0x0c04ea1cu: goto P_0c04ea1c;
case 0x0c04ea1eu: goto P_0c04ea1e;
case 0x0c04ea20u: goto P_0c04ea20;
case 0x0c04ea22u: goto P_0c04ea22;
case 0x0c04ea24u: goto P_0c04ea24;
case 0x0c04ea26u: goto P_0c04ea26;
case 0x0c04ea28u: goto P_0c04ea28;
case 0x0c04ea2au: goto P_0c04ea2a;
case 0x0c04ea2cu: goto P_0c04ea2c;
case 0x0c04ea2eu: goto P_0c04ea2e;
case 0x0c04ea30u: goto P_0c04ea30;
case 0x0c04ea32u: goto P_0c04ea32;
case 0x0c04ea34u: goto P_0c04ea34;
case 0x0c04ea36u: goto P_0c04ea36;
case 0x0c04ea38u: goto P_0c04ea38;
case 0x0c04ea3au: goto P_0c04ea3a;
case 0x0c04ea3cu: goto P_0c04ea3c;
case 0x0c04ea3eu: goto P_0c04ea3e;
case 0x0c04ea40u: goto P_0c04ea40;
case 0x0c04ea42u: goto P_0c04ea42;
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
P_0c04e7dc: /* original 2fe6, guest PC 0x0c04e7dc */
if(!s->budget--) { s->failed_pc=0x0c04e7dcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e7de;
P_0c04e7de: /* original 6e43, guest PC 0x0c04e7de */
if(!s->budget--) { s->failed_pc=0x0c04e7deu; return 0; }
r[14]=r[4];
goto P_0c04e7e0;
P_0c04e7e0: /* original 2fd6, guest PC 0x0c04e7e0 */
if(!s->budget--) { s->failed_pc=0x0c04e7e0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e7e2;
P_0c04e7e2: /* original 2fc6, guest PC 0x0c04e7e2 */
if(!s->budget--) { s->failed_pc=0x0c04e7e2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e7e4;
P_0c04e7e4: /* original 6c53, guest PC 0x0c04e7e4 */
if(!s->budget--) { s->failed_pc=0x0c04e7e4u; return 0; }
r[12]=r[5];
goto P_0c04e7e6;
P_0c04e7e6: /* original 4f22, guest PC 0x0c04e7e6 */
if(!s->budget--) { s->failed_pc=0x0c04e7e6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04e7e8;
P_0c04e7e8: /* original 4f12, guest PC 0x0c04e7e8 */
if(!s->budget--) { s->failed_pc=0x0c04e7e8u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04e7ea;
P_0c04e7ea: /* original 7ffc, guest PC 0x0c04e7ea */
if(!s->budget--) { s->failed_pc=0x0c04e7eau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04e7ec;
P_0c04e7ec: /* original 2f56, guest PC 0x0c04e7ec */
if(!s->budget--) { s->failed_pc=0x0c04e7ecu; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e7ee;
P_0c04e7ee: /* original 2fe6, guest PC 0x0c04e7ee */
if(!s->budget--) { s->failed_pc=0x0c04e7eeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e7f0;
P_0c04e7f0: /* original d332, guest PC 0x0c04e7f0 */
if(!s->budget--) { s->failed_pc=0x0c04e7f0u; return 0; }
r[3]=read(ram,0x0c04e8bcu,4);
goto P_0c04e7f2;
P_0c04e7f2: /* original d233, guest PC 0x0c04e7f2 */
if(!s->budget--) { s->failed_pc=0x0c04e7f2u; return 0; }
r[2]=read(ram,0x0c04e8c0u,4);
goto P_0c04e7f4;
P_0c04e7f4: /* original 420b, guest PC 0x0c04e7f4 */
if(!s->budget--) { s->failed_pc=0x0c04e7f4u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e7f8u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e7f8u) { target=s->pc; goto dispatch; }
goto P_0c04e7f8;
P_0c04e7f6: /* original 2f36, guest PC 0x0c04e7f6 */
if(!s->budget--) { s->failed_pc=0x0c04e7f6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e7f8;
P_0c04e7f8: /* original 9d5b, guest PC 0x0c04e7f8 */
if(!s->budget--) { s->failed_pc=0x0c04e7f8u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e8b2u,2);
goto P_0c04e7fa;
P_0c04e7fa: /* original 7f0c, guest PC 0x0c04e7fa */
if(!s->budget--) { s->failed_pc=0x0c04e7fau; return 0; }
r[15]+=0x0000000cu;
goto P_0c04e7fc;
P_0c04e7fc: /* original e201, guest PC 0x0c04e7fc */
if(!s->budget--) { s->failed_pc=0x0c04e7fcu; return 0; }
r[2]=0x00000001u;
goto P_0c04e7fe;
P_0c04e7fe: /* original 2edf, guest PC 0x0c04e7fe */
if(!s->budget--) { s->failed_pc=0x0c04e7feu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[13]);
goto P_0c04e800;
P_0c04e800: /* original 0d1a, guest PC 0x0c04e800 */
if(!s->budget--) { s->failed_pc=0x0c04e800u; return 0; }
r[13]=r[19];
goto P_0c04e802;
P_0c04e802: /* original 6ddf, guest PC 0x0c04e802 */
if(!s->budget--) { s->failed_pc=0x0c04e802u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c04e804;
P_0c04e804: /* original 2fd2, guest PC 0x0c04e804 */
if(!s->budget--) { s->failed_pc=0x0c04e804u; return 0; }
write(ram,r[15],r[13],4);
goto P_0c04e806;
P_0c04e806: /* original d32f, guest PC 0x0c04e806 */
if(!s->budget--) { s->failed_pc=0x0c04e806u; return 0; }
r[3]=read(ram,0x0c04e8c4u,4);
goto P_0c04e808;
P_0c04e808: /* original 3d3c, guest PC 0x0c04e808 */
if(!s->budget--) { s->failed_pc=0x0c04e808u; return 0; }
r[13]+=r[3];
goto P_0c04e80a;
P_0c04e80a: /* original 1d2c, guest PC 0x0c04e80a */
if(!s->budget--) { s->failed_pc=0x0c04e80au; return 0; }
write(ram,r[13]+48,r[2],4);
goto P_0c04e80c;
P_0c04e80c: /* original 51d1, guest PC 0x0c04e80c */
if(!s->budget--) { s->failed_pc=0x0c04e80cu; return 0; }
r[1]=read(ram,r[13]+4,4);
goto P_0c04e80e;
P_0c04e80e: /* original d02e, guest PC 0x0c04e80e */
if(!s->budget--) { s->failed_pc=0x0c04e80eu; return 0; }
r[0]=read(ram,0x0c04e8c8u,4);
goto P_0c04e810;
P_0c04e810: /* original 6213, guest PC 0x0c04e810 */
if(!s->budget--) { s->failed_pc=0x0c04e810u; return 0; }
r[2]=r[1];
goto P_0c04e812;
P_0c04e812: /* original 4108, guest PC 0x0c04e812 */
if(!s->budget--) { s->failed_pc=0x0c04e812u; return 0; }
r[1]<<=2;
goto P_0c04e814;
P_0c04e814: /* original 312c, guest PC 0x0c04e814 */
if(!s->budget--) { s->failed_pc=0x0c04e814u; return 0; }
r[1]+=r[2];
goto P_0c04e816;
P_0c04e816: /* original 4108, guest PC 0x0c04e816 */
if(!s->budget--) { s->failed_pc=0x0c04e816u; return 0; }
r[1]<<=2;
goto P_0c04e818;
P_0c04e818: /* original 4108, guest PC 0x0c04e818 */
if(!s->budget--) { s->failed_pc=0x0c04e818u; return 0; }
r[1]<<=2;
goto P_0c04e81a;
P_0c04e81a: /* original 611f, guest PC 0x0c04e81a */
if(!s->budget--) { s->failed_pc=0x0c04e81au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[1];
goto P_0c04e81c;
P_0c04e81c: /* original 001e, guest PC 0x0c04e81c */
if(!s->budget--) { s->failed_pc=0x0c04e81cu; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c04e81e;
P_0c04e81e: /* original 1d0d, guest PC 0x0c04e81e */
if(!s->budget--) { s->failed_pc=0x0c04e81eu; return 0; }
write(ram,r[13]+52,r[0],4);
goto P_0c04e820;
P_0c04e820: /* original 84d2, guest PC 0x0c04e820 */
if(!s->budget--) { s->failed_pc=0x0c04e820u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+2,1);
goto P_0c04e822;
P_0c04e822: /* original 2008, guest PC 0x0c04e822 */
if(!s->budget--) { s->failed_pc=0x0c04e822u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e824;
P_0c04e824: /* original 8914, guest PC 0x0c04e824 */
if(!s->budget--) { s->failed_pc=0x0c04e824u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e850; }
goto P_0c04e826;
P_0c04e826: /* original d329, guest PC 0x0c04e826 */
if(!s->budget--) { s->failed_pc=0x0c04e826u; return 0; }
r[3]=read(ram,0x0c04e8ccu,4);
goto P_0c04e828;
P_0c04e828: /* original 430b, guest PC 0x0c04e828 */
if(!s->budget--) { s->failed_pc=0x0c04e828u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e82cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e82cu) { target=s->pc; goto dispatch; }
goto P_0c04e82c;
P_0c04e82a: /* original 64e3, guest PC 0x0c04e82a */
if(!s->budget--) { s->failed_pc=0x0c04e82au; return 0; }
r[4]=r[14];
goto P_0c04e82c;
P_0c04e82c: /* original 2008, guest PC 0x0c04e82c */
if(!s->budget--) { s->failed_pc=0x0c04e82cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e82e;
P_0c04e82e: /* original 8b04, guest PC 0x0c04e82e */
if(!s->budget--) { s->failed_pc=0x0c04e82eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e83a; }
goto P_0c04e830;
P_0c04e830: /* original d327, guest PC 0x0c04e830 */
if(!s->budget--) { s->failed_pc=0x0c04e830u; return 0; }
r[3]=read(ram,0x0c04e8d0u,4);
goto P_0c04e832;
P_0c04e832: /* original 430b, guest PC 0x0c04e832 */
if(!s->budget--) { s->failed_pc=0x0c04e832u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e836u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e836u) { target=s->pc; goto dispatch; }
goto P_0c04e836;
P_0c04e834: /* original 64e3, guest PC 0x0c04e834 */
if(!s->budget--) { s->failed_pc=0x0c04e834u; return 0; }
r[4]=r[14];
goto P_0c04e836;
P_0c04e836: /* original a00b, guest PC 0x0c04e836 */
if(!s->budget--) { s->failed_pc=0x0c04e836u; return 0; }
goto P_0c04e850;
P_0c04e838: /* original 0009, guest PC 0x0c04e838 */
if(!s->budget--) { s->failed_pc=0x0c04e838u; return 0; }
goto P_0c04e83a;
P_0c04e83a: /* original d226, guest PC 0x0c04e83a */
if(!s->budget--) { s->failed_pc=0x0c04e83au; return 0; }
r[2]=read(ram,0x0c04e8d4u,4);
goto P_0c04e83c;
P_0c04e83c: /* original 420b, guest PC 0x0c04e83c */
if(!s->budget--) { s->failed_pc=0x0c04e83cu; return 0; }
target=r[2];
r[16]=code_base|0x0c04e840u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e840u) { target=s->pc; goto dispatch; }
goto P_0c04e840;
P_0c04e83e: /* original 64e3, guest PC 0x0c04e83e */
if(!s->budget--) { s->failed_pc=0x0c04e83eu; return 0; }
r[4]=r[14];
goto P_0c04e840;
P_0c04e840: /* original 2008, guest PC 0x0c04e840 */
if(!s->budget--) { s->failed_pc=0x0c04e840u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e842;
P_0c04e842: /* original 8905, guest PC 0x0c04e842 */
if(!s->budget--) { s->failed_pc=0x0c04e842u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e850; }
goto P_0c04e844;
P_0c04e844: /* original 62f2, guest PC 0x0c04e844 */
if(!s->budget--) { s->failed_pc=0x0c04e844u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04e846;
P_0c04e846: /* original d31f, guest PC 0x0c04e846 */
if(!s->budget--) { s->failed_pc=0x0c04e846u; return 0; }
r[3]=read(ram,0x0c04e8c4u,4);
goto P_0c04e848;
P_0c04e848: /* original 323c, guest PC 0x0c04e848 */
if(!s->budget--) { s->failed_pc=0x0c04e848u; return 0; }
r[2]+=r[3];
goto P_0c04e84a;
P_0c04e84a: /* original 8428, guest PC 0x0c04e84a */
if(!s->budget--) { s->failed_pc=0x0c04e84au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04e84c;
P_0c04e84c: /* original 2008, guest PC 0x0c04e84c */
if(!s->budget--) { s->failed_pc=0x0c04e84cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e84e;
P_0c04e84e: /* original 8b02, guest PC 0x0c04e84e */
if(!s->budget--) { s->failed_pc=0x0c04e84eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e856; }
goto P_0c04e850;
P_0c04e850: /* original 9030, guest PC 0x0c04e850 */
if(!s->budget--) { s->failed_pc=0x0c04e850u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e8b4u,2);
goto P_0c04e852;
P_0c04e852: /* original a027, guest PC 0x0c04e852 */
if(!s->budget--) { s->failed_pc=0x0c04e852u; return 0; }
goto P_0c04e8a4;
P_0c04e854: /* original 0009, guest PC 0x0c04e854 */
if(!s->budget--) { s->failed_pc=0x0c04e854u; return 0; }
goto P_0c04e856;
P_0c04e856: /* original d320, guest PC 0x0c04e856 */
if(!s->budget--) { s->failed_pc=0x0c04e856u; return 0; }
r[3]=read(ram,0x0c04e8d8u,4);
goto P_0c04e858;
P_0c04e858: /* original 430b, guest PC 0x0c04e858 */
if(!s->budget--) { s->failed_pc=0x0c04e858u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e85cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e85cu) { target=s->pc; goto dispatch; }
goto P_0c04e85c;
P_0c04e85a: /* original 64e3, guest PC 0x0c04e85a */
if(!s->budget--) { s->failed_pc=0x0c04e85au; return 0; }
r[4]=r[14];
goto P_0c04e85c;
P_0c04e85c: /* original 4011, guest PC 0x0c04e85c */
if(!s->budget--) { s->failed_pc=0x0c04e85cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e85e;
P_0c04e85e: /* original 8902, guest PC 0x0c04e85e */
if(!s->budget--) { s->failed_pc=0x0c04e85eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e866; }
goto P_0c04e860;
P_0c04e860: /* original 9029, guest PC 0x0c04e860 */
if(!s->budget--) { s->failed_pc=0x0c04e860u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e8b6u,2);
goto P_0c04e862;
P_0c04e862: /* original a01f, guest PC 0x0c04e862 */
if(!s->budget--) { s->failed_pc=0x0c04e862u; return 0; }
goto P_0c04e8a4;
P_0c04e864: /* original 0009, guest PC 0x0c04e864 */
if(!s->budget--) { s->failed_pc=0x0c04e864u; return 0; }
goto P_0c04e866;
P_0c04e866: /* original d31d, guest PC 0x0c04e866 */
if(!s->budget--) { s->failed_pc=0x0c04e866u; return 0; }
r[3]=read(ram,0x0c04e8dcu,4);
goto P_0c04e868;
P_0c04e868: /* original 65c3, guest PC 0x0c04e868 */
if(!s->budget--) { s->failed_pc=0x0c04e868u; return 0; }
r[5]=r[12];
goto P_0c04e86a;
P_0c04e86a: /* original 430b, guest PC 0x0c04e86a */
if(!s->budget--) { s->failed_pc=0x0c04e86au; return 0; }
target=r[3];
r[16]=code_base|0x0c04e86eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e86eu) { target=s->pc; goto dispatch; }
goto P_0c04e86e;
P_0c04e86c: /* original 64e3, guest PC 0x0c04e86c */
if(!s->budget--) { s->failed_pc=0x0c04e86cu; return 0; }
r[4]=r[14];
goto P_0c04e86e;
P_0c04e86e: /* original 4011, guest PC 0x0c04e86e */
if(!s->budget--) { s->failed_pc=0x0c04e86eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e870;
P_0c04e870: /* original 8902, guest PC 0x0c04e870 */
if(!s->budget--) { s->failed_pc=0x0c04e870u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e878; }
goto P_0c04e872;
P_0c04e872: /* original 9021, guest PC 0x0c04e872 */
if(!s->budget--) { s->failed_pc=0x0c04e872u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e8b8u,2);
goto P_0c04e874;
P_0c04e874: /* original a016, guest PC 0x0c04e874 */
if(!s->budget--) { s->failed_pc=0x0c04e874u; return 0; }
goto P_0c04e8a4;
P_0c04e876: /* original 0009, guest PC 0x0c04e876 */
if(!s->budget--) { s->failed_pc=0x0c04e876u; return 0; }
goto P_0c04e878;
P_0c04e878: /* original 65c3, guest PC 0x0c04e878 */
if(!s->budget--) { s->failed_pc=0x0c04e878u; return 0; }
r[5]=r[12];
goto P_0c04e87a;
P_0c04e87a: /* original bf4a, guest PC 0x0c04e87a */
if(!s->budget--) { s->failed_pc=0x0c04e87au; return 0; }
target=code_base|0x0c04e712u; r[16]=code_base|0x0c04e87eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e87eu) { target=s->pc; goto dispatch; }
goto P_0c04e87e;
P_0c04e87c: /* original 64e3, guest PC 0x0c04e87c */
if(!s->budget--) { s->failed_pc=0x0c04e87cu; return 0; }
r[4]=r[14];
goto P_0c04e87e;
P_0c04e87e: /* original 4011, guest PC 0x0c04e87e */
if(!s->budget--) { s->failed_pc=0x0c04e87eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e880;
P_0c04e880: /* original 8f05, guest PC 0x0c04e880 */
if(!s->budget--) { s->failed_pc=0x0c04e880u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c04e88e; }
goto P_0c04e884;
P_0c04e882: /* original 6403, guest PC 0x0c04e882 */
if(!s->budget--) { s->failed_pc=0x0c04e882u; return 0; }
r[4]=r[0];
goto P_0c04e884;
P_0c04e884: /* original b763, guest PC 0x0c04e884 */
if(!s->budget--) { s->failed_pc=0x0c04e884u; return 0; }
target=code_base|0x0c04f74eu; r[16]=code_base|0x0c04e888u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e888u) { target=s->pc; goto dispatch; }
goto P_0c04e888;
P_0c04e886: /* original 64e3, guest PC 0x0c04e886 */
if(!s->budget--) { s->failed_pc=0x0c04e886u; return 0; }
r[4]=r[14];
goto P_0c04e888;
P_0c04e888: /* original 4011, guest PC 0x0c04e888 */
if(!s->budget--) { s->failed_pc=0x0c04e888u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e88a;
P_0c04e88a: /* original 8d02, guest PC 0x0c04e88a */
if(!s->budget--) { s->failed_pc=0x0c04e88au; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c04e892; }
goto P_0c04e88e;
P_0c04e88c: /* original 6403, guest PC 0x0c04e88c */
if(!s->budget--) { s->failed_pc=0x0c04e88cu; return 0; }
r[4]=r[0];
goto P_0c04e88e;
P_0c04e88e: /* original a009, guest PC 0x0c04e88e */
if(!s->budget--) { s->failed_pc=0x0c04e88eu; return 0; }
r[0]=r[4];
goto P_0c04e8a4;
P_0c04e890: /* original 6043, guest PC 0x0c04e890 */
if(!s->budget--) { s->failed_pc=0x0c04e890u; return 0; }
r[0]=r[4];
goto P_0c04e892;
P_0c04e892: /* original 7f04, guest PC 0x0c04e892 */
if(!s->budget--) { s->failed_pc=0x0c04e892u; return 0; }
r[15]+=0x00000004u;
goto P_0c04e894;
P_0c04e894: /* original d212, guest PC 0x0c04e894 */
if(!s->budget--) { s->failed_pc=0x0c04e894u; return 0; }
r[2]=read(ram,0x0c04e8e0u,4);
goto P_0c04e896;
P_0c04e896: /* original 4f16, guest PC 0x0c04e896 */
if(!s->budget--) { s->failed_pc=0x0c04e896u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e898;
P_0c04e898: /* original 64e3, guest PC 0x0c04e898 */
if(!s->budget--) { s->failed_pc=0x0c04e898u; return 0; }
r[4]=r[14];
goto P_0c04e89a;
P_0c04e89a: /* original 4f26, guest PC 0x0c04e89a */
if(!s->budget--) { s->failed_pc=0x0c04e89au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e89c;
P_0c04e89c: /* original 6cf6, guest PC 0x0c04e89c */
if(!s->budget--) { s->failed_pc=0x0c04e89cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04e89e;
P_0c04e89e: /* original 6df6, guest PC 0x0c04e89e */
if(!s->budget--) { s->failed_pc=0x0c04e89eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04e8a0;
P_0c04e8a0: /* original 422b, guest PC 0x0c04e8a0 */
if(!s->budget--) { s->failed_pc=0x0c04e8a0u; return 0; }
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
P_0c04e8a2: /* original 6ef6, guest PC 0x0c04e8a2 */
if(!s->budget--) { s->failed_pc=0x0c04e8a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04e8a4;
P_0c04e8a4: /* original 7f04, guest PC 0x0c04e8a4 */
if(!s->budget--) { s->failed_pc=0x0c04e8a4u; return 0; }
r[15]+=0x00000004u;
goto P_0c04e8a6;
P_0c04e8a6: /* original 4f16, guest PC 0x0c04e8a6 */
if(!s->budget--) { s->failed_pc=0x0c04e8a6u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e8a8;
P_0c04e8a8: /* original 4f26, guest PC 0x0c04e8a8 */
if(!s->budget--) { s->failed_pc=0x0c04e8a8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e8aa;
P_0c04e8aa: /* original 6cf6, guest PC 0x0c04e8aa */
if(!s->budget--) { s->failed_pc=0x0c04e8aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04e8ac;
P_0c04e8ac: /* original 6df6, guest PC 0x0c04e8ac */
if(!s->budget--) { s->failed_pc=0x0c04e8acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04e8ae;
P_0c04e8ae: /* original 000b, guest PC 0x0c04e8ae */
if(!s->budget--) { s->failed_pc=0x0c04e8aeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04e8b0: /* original 6ef6, guest PC 0x0c04e8b0 */
if(!s->budget--) { s->failed_pc=0x0c04e8b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04e8b2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04e8b2u; return 0; } return 1;
P_0c04e8e4: /* original 2fe6, guest PC 0x0c04e8e4 */
if(!s->budget--) { s->failed_pc=0x0c04e8e4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e8e6;
P_0c04e8e6: /* original 6e43, guest PC 0x0c04e8e6 */
if(!s->budget--) { s->failed_pc=0x0c04e8e6u; return 0; }
r[14]=r[4];
goto P_0c04e8e8;
P_0c04e8e8: /* original 2fd6, guest PC 0x0c04e8e8 */
if(!s->budget--) { s->failed_pc=0x0c04e8e8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e8ea;
P_0c04e8ea: /* original 6d63, guest PC 0x0c04e8ea */
if(!s->budget--) { s->failed_pc=0x0c04e8eau; return 0; }
r[13]=r[6];
goto P_0c04e8ec;
P_0c04e8ec: /* original 2fc6, guest PC 0x0c04e8ec */
if(!s->budget--) { s->failed_pc=0x0c04e8ecu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e8ee;
P_0c04e8ee: /* original 2fb6, guest PC 0x0c04e8ee */
if(!s->budget--) { s->failed_pc=0x0c04e8eeu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e8f0;
P_0c04e8f0: /* original 6b53, guest PC 0x0c04e8f0 */
if(!s->budget--) { s->failed_pc=0x0c04e8f0u; return 0; }
r[11]=r[5];
goto P_0c04e8f2;
P_0c04e8f2: /* original 2fa6, guest PC 0x0c04e8f2 */
if(!s->budget--) { s->failed_pc=0x0c04e8f2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e8f4;
P_0c04e8f4: /* original 2f96, guest PC 0x0c04e8f4 */
if(!s->budget--) { s->failed_pc=0x0c04e8f4u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e8f6;
P_0c04e8f6: /* original 2f86, guest PC 0x0c04e8f6 */
if(!s->budget--) { s->failed_pc=0x0c04e8f6u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e8f8;
P_0c04e8f8: /* original 4f22, guest PC 0x0c04e8f8 */
if(!s->budget--) { s->failed_pc=0x0c04e8f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04e8fa;
P_0c04e8fa: /* original 4f12, guest PC 0x0c04e8fa */
if(!s->budget--) { s->failed_pc=0x0c04e8fau; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04e8fc;
P_0c04e8fc: /* original 7ffc, guest PC 0x0c04e8fc */
if(!s->budget--) { s->failed_pc=0x0c04e8fcu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04e8fe;
P_0c04e8fe: /* original 2f66, guest PC 0x0c04e8fe */
if(!s->budget--) { s->failed_pc=0x0c04e8feu; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e900;
P_0c04e900: /* original 2fb6, guest PC 0x0c04e900 */
if(!s->budget--) { s->failed_pc=0x0c04e900u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e902;
P_0c04e902: /* original 2fe6, guest PC 0x0c04e902 */
if(!s->budget--) { s->failed_pc=0x0c04e902u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e904;
P_0c04e904: /* original d328, guest PC 0x0c04e904 */
if(!s->budget--) { s->failed_pc=0x0c04e904u; return 0; }
r[3]=read(ram,0x0c04e9a8u,4);
goto P_0c04e906;
P_0c04e906: /* original d229, guest PC 0x0c04e906 */
if(!s->budget--) { s->failed_pc=0x0c04e906u; return 0; }
r[2]=read(ram,0x0c04e9acu,4);
goto P_0c04e908;
P_0c04e908: /* original 420b, guest PC 0x0c04e908 */
if(!s->budget--) { s->failed_pc=0x0c04e908u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e90cu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e90cu) { target=s->pc; goto dispatch; }
goto P_0c04e90c;
P_0c04e90a: /* original 2f36, guest PC 0x0c04e90a */
if(!s->budget--) { s->failed_pc=0x0c04e90au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e90c;
P_0c04e90c: /* original 4d15, guest PC 0x0c04e90c */
if(!s->budget--) { s->failed_pc=0x0c04e90cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c04e90e;
P_0c04e90e: /* original e900, guest PC 0x0c04e90e */
if(!s->budget--) { s->failed_pc=0x0c04e90eu; return 0; }
r[9]=0x00000000u;
goto P_0c04e910;
P_0c04e910: /* original 7f10, guest PC 0x0c04e910 */
if(!s->budget--) { s->failed_pc=0x0c04e910u; return 0; }
r[15]+=0x00000010u;
goto P_0c04e912;
P_0c04e912: /* original 8f0f, guest PC 0x0c04e912 */
if(!s->budget--) { s->failed_pc=0x0c04e912u; return 0; }
cond=r[17]&1u;
r[12]=r[9];
if(!cond) { goto P_0c04e934; }
goto P_0c04e916;
P_0c04e914: /* original 6c93, guest PC 0x0c04e914 */
if(!s->budget--) { s->failed_pc=0x0c04e914u; return 0; }
r[12]=r[9];
goto P_0c04e916;
P_0c04e916: /* original d826, guest PC 0x0c04e916 */
if(!s->budget--) { s->failed_pc=0x0c04e916u; return 0; }
r[8]=read(ram,0x0c04e9b0u,4);
goto P_0c04e918;
P_0c04e918: /* original 6ac3, guest PC 0x0c04e918 */
if(!s->budget--) { s->failed_pc=0x0c04e918u; return 0; }
r[10]=r[12];
goto P_0c04e91a;
P_0c04e91a: /* original 4a08, guest PC 0x0c04e91a */
if(!s->budget--) { s->failed_pc=0x0c04e91au; return 0; }
r[10]<<=2;
goto P_0c04e91c;
P_0c04e91c: /* original 3abc, guest PC 0x0c04e91c */
if(!s->budget--) { s->failed_pc=0x0c04e91cu; return 0; }
r[10]+=r[11];
goto P_0c04e91e;
P_0c04e91e: /* original 2fa6, guest PC 0x0c04e91e */
if(!s->budget--) { s->failed_pc=0x0c04e91eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e920;
P_0c04e920: /* original 63a2, guest PC 0x0c04e920 */
if(!s->budget--) { s->failed_pc=0x0c04e920u; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c04e922;
P_0c04e922: /* original 2f36, guest PC 0x0c04e922 */
if(!s->budget--) { s->failed_pc=0x0c04e922u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e924;
P_0c04e924: /* original 2fc6, guest PC 0x0c04e924 */
if(!s->budget--) { s->failed_pc=0x0c04e924u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e926;
P_0c04e926: /* original d221, guest PC 0x0c04e926 */
if(!s->budget--) { s->failed_pc=0x0c04e926u; return 0; }
r[2]=read(ram,0x0c04e9acu,4);
goto P_0c04e928;
P_0c04e928: /* original 420b, guest PC 0x0c04e928 */
if(!s->budget--) { s->failed_pc=0x0c04e928u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e92cu;
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e92cu) { target=s->pc; goto dispatch; }
goto P_0c04e92c;
P_0c04e92a: /* original 2f86, guest PC 0x0c04e92a */
if(!s->budget--) { s->failed_pc=0x0c04e92au; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e92c;
P_0c04e92c: /* original 7c01, guest PC 0x0c04e92c */
if(!s->budget--) { s->failed_pc=0x0c04e92cu; return 0; }
r[12]+=0x00000001u;
goto P_0c04e92e;
P_0c04e92e: /* original 3cd3, guest PC 0x0c04e92e */
if(!s->budget--) { s->failed_pc=0x0c04e92eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[13])!=0);
goto P_0c04e930;
P_0c04e930: /* original 8ff2, guest PC 0x0c04e930 */
if(!s->budget--) { s->failed_pc=0x0c04e930u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000010u;
if(!cond) { goto P_0c04e918; }
goto P_0c04e934;
P_0c04e932: /* original 7f10, guest PC 0x0c04e932 */
if(!s->budget--) { s->failed_pc=0x0c04e932u; return 0; }
r[15]+=0x00000010u;
goto P_0c04e934;
P_0c04e934: /* original 9c34, guest PC 0x0c04e934 */
if(!s->budget--) { s->failed_pc=0x0c04e934u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e9a0u,2);
goto P_0c04e936;
P_0c04e936: /* original ea01, guest PC 0x0c04e936 */
if(!s->budget--) { s->failed_pc=0x0c04e936u; return 0; }
r[10]=0x00000001u;
goto P_0c04e938;
P_0c04e938: /* original 2ecf, guest PC 0x0c04e938 */
if(!s->budget--) { s->failed_pc=0x0c04e938u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[12]);
goto P_0c04e93a;
P_0c04e93a: /* original 0c1a, guest PC 0x0c04e93a */
if(!s->budget--) { s->failed_pc=0x0c04e93au; return 0; }
r[12]=r[19];
goto P_0c04e93c;
P_0c04e93c: /* original 6ccf, guest PC 0x0c04e93c */
if(!s->budget--) { s->failed_pc=0x0c04e93cu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c04e93e;
P_0c04e93e: /* original 2fc2, guest PC 0x0c04e93e */
if(!s->budget--) { s->failed_pc=0x0c04e93eu; return 0; }
write(ram,r[15],r[12],4);
goto P_0c04e940;
P_0c04e940: /* original d31c, guest PC 0x0c04e940 */
if(!s->budget--) { s->failed_pc=0x0c04e940u; return 0; }
r[3]=read(ram,0x0c04e9b4u,4);
goto P_0c04e942;
P_0c04e942: /* original 3c3c, guest PC 0x0c04e942 */
if(!s->budget--) { s->failed_pc=0x0c04e942u; return 0; }
r[12]+=r[3];
goto P_0c04e944;
P_0c04e944: /* original 1cac, guest PC 0x0c04e944 */
if(!s->budget--) { s->failed_pc=0x0c04e944u; return 0; }
write(ram,r[12]+48,r[10],4);
goto P_0c04e946;
P_0c04e946: /* original 52c1, guest PC 0x0c04e946 */
if(!s->budget--) { s->failed_pc=0x0c04e946u; return 0; }
r[2]=read(ram,r[12]+4,4);
goto P_0c04e948;
P_0c04e948: /* original d01b, guest PC 0x0c04e948 */
if(!s->budget--) { s->failed_pc=0x0c04e948u; return 0; }
r[0]=read(ram,0x0c04e9b8u,4);
goto P_0c04e94a;
P_0c04e94a: /* original 6123, guest PC 0x0c04e94a */
if(!s->budget--) { s->failed_pc=0x0c04e94au; return 0; }
r[1]=r[2];
goto P_0c04e94c;
P_0c04e94c: /* original 4208, guest PC 0x0c04e94c */
if(!s->budget--) { s->failed_pc=0x0c04e94cu; return 0; }
r[2]<<=2;
goto P_0c04e94e;
P_0c04e94e: /* original 321c, guest PC 0x0c04e94e */
if(!s->budget--) { s->failed_pc=0x0c04e94eu; return 0; }
r[2]+=r[1];
goto P_0c04e950;
P_0c04e950: /* original 4208, guest PC 0x0c04e950 */
if(!s->budget--) { s->failed_pc=0x0c04e950u; return 0; }
r[2]<<=2;
goto P_0c04e952;
P_0c04e952: /* original 4208, guest PC 0x0c04e952 */
if(!s->budget--) { s->failed_pc=0x0c04e952u; return 0; }
r[2]<<=2;
goto P_0c04e954;
P_0c04e954: /* original 622f, guest PC 0x0c04e954 */
if(!s->budget--) { s->failed_pc=0x0c04e954u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c04e956;
P_0c04e956: /* original 002e, guest PC 0x0c04e956 */
if(!s->budget--) { s->failed_pc=0x0c04e956u; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c04e958;
P_0c04e958: /* original 1c0d, guest PC 0x0c04e958 */
if(!s->budget--) { s->failed_pc=0x0c04e958u; return 0; }
write(ram,r[12]+52,r[0],4);
goto P_0c04e95a;
P_0c04e95a: /* original 84c2, guest PC 0x0c04e95a */
if(!s->budget--) { s->failed_pc=0x0c04e95au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+2,1);
goto P_0c04e95c;
P_0c04e95c: /* original 2008, guest PC 0x0c04e95c */
if(!s->budget--) { s->failed_pc=0x0c04e95cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e95e;
P_0c04e95e: /* original 8914, guest PC 0x0c04e95e */
if(!s->budget--) { s->failed_pc=0x0c04e95eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e98a; }
goto P_0c04e960;
P_0c04e960: /* original d316, guest PC 0x0c04e960 */
if(!s->budget--) { s->failed_pc=0x0c04e960u; return 0; }
r[3]=read(ram,0x0c04e9bcu,4);
goto P_0c04e962;
P_0c04e962: /* original 430b, guest PC 0x0c04e962 */
if(!s->budget--) { s->failed_pc=0x0c04e962u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e966u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e966u) { target=s->pc; goto dispatch; }
goto P_0c04e966;
P_0c04e964: /* original 64e3, guest PC 0x0c04e964 */
if(!s->budget--) { s->failed_pc=0x0c04e964u; return 0; }
r[4]=r[14];
goto P_0c04e966;
P_0c04e966: /* original 2008, guest PC 0x0c04e966 */
if(!s->budget--) { s->failed_pc=0x0c04e966u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e968;
P_0c04e968: /* original 8b04, guest PC 0x0c04e968 */
if(!s->budget--) { s->failed_pc=0x0c04e968u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e974; }
goto P_0c04e96a;
P_0c04e96a: /* original d315, guest PC 0x0c04e96a */
if(!s->budget--) { s->failed_pc=0x0c04e96au; return 0; }
r[3]=read(ram,0x0c04e9c0u,4);
goto P_0c04e96c;
P_0c04e96c: /* original 430b, guest PC 0x0c04e96c */
if(!s->budget--) { s->failed_pc=0x0c04e96cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04e970u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e970u) { target=s->pc; goto dispatch; }
goto P_0c04e970;
P_0c04e96e: /* original 64e3, guest PC 0x0c04e96e */
if(!s->budget--) { s->failed_pc=0x0c04e96eu; return 0; }
r[4]=r[14];
goto P_0c04e970;
P_0c04e970: /* original a00b, guest PC 0x0c04e970 */
if(!s->budget--) { s->failed_pc=0x0c04e970u; return 0; }
goto P_0c04e98a;
P_0c04e972: /* original 0009, guest PC 0x0c04e972 */
if(!s->budget--) { s->failed_pc=0x0c04e972u; return 0; }
goto P_0c04e974;
P_0c04e974: /* original d213, guest PC 0x0c04e974 */
if(!s->budget--) { s->failed_pc=0x0c04e974u; return 0; }
r[2]=read(ram,0x0c04e9c4u,4);
goto P_0c04e976;
P_0c04e976: /* original 420b, guest PC 0x0c04e976 */
if(!s->budget--) { s->failed_pc=0x0c04e976u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e97au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e97au) { target=s->pc; goto dispatch; }
goto P_0c04e97a;
P_0c04e978: /* original 64e3, guest PC 0x0c04e978 */
if(!s->budget--) { s->failed_pc=0x0c04e978u; return 0; }
r[4]=r[14];
goto P_0c04e97a;
P_0c04e97a: /* original 2008, guest PC 0x0c04e97a */
if(!s->budget--) { s->failed_pc=0x0c04e97au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e97c;
P_0c04e97c: /* original 8905, guest PC 0x0c04e97c */
if(!s->budget--) { s->failed_pc=0x0c04e97cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e98a; }
goto P_0c04e97e;
P_0c04e97e: /* original 62f2, guest PC 0x0c04e97e */
if(!s->budget--) { s->failed_pc=0x0c04e97eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04e980;
P_0c04e980: /* original d30c, guest PC 0x0c04e980 */
if(!s->budget--) { s->failed_pc=0x0c04e980u; return 0; }
r[3]=read(ram,0x0c04e9b4u,4);
goto P_0c04e982;
P_0c04e982: /* original 323c, guest PC 0x0c04e982 */
if(!s->budget--) { s->failed_pc=0x0c04e982u; return 0; }
r[2]+=r[3];
goto P_0c04e984;
P_0c04e984: /* original 8428, guest PC 0x0c04e984 */
if(!s->budget--) { s->failed_pc=0x0c04e984u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04e986;
P_0c04e986: /* original 2008, guest PC 0x0c04e986 */
if(!s->budget--) { s->failed_pc=0x0c04e986u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e988;
P_0c04e988: /* original 8b02, guest PC 0x0c04e988 */
if(!s->budget--) { s->failed_pc=0x0c04e988u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e990; }
goto P_0c04e98a;
P_0c04e98a: /* original 900a, guest PC 0x0c04e98a */
if(!s->budget--) { s->failed_pc=0x0c04e98au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e9a2u,2);
goto P_0c04e98c;
P_0c04e98c: /* original a04f, guest PC 0x0c04e98c */
if(!s->budget--) { s->failed_pc=0x0c04e98cu; return 0; }
goto P_0c04ea2e;
P_0c04e98e: /* original 0009, guest PC 0x0c04e98e */
if(!s->budget--) { s->failed_pc=0x0c04e98eu; return 0; }
goto P_0c04e990;
P_0c04e990: /* original d30d, guest PC 0x0c04e990 */
if(!s->budget--) { s->failed_pc=0x0c04e990u; return 0; }
r[3]=read(ram,0x0c04e9c8u,4);
goto P_0c04e992;
P_0c04e992: /* original 430b, guest PC 0x0c04e992 */
if(!s->budget--) { s->failed_pc=0x0c04e992u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e996u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e996u) { target=s->pc; goto dispatch; }
goto P_0c04e996;
P_0c04e994: /* original 64e3, guest PC 0x0c04e994 */
if(!s->budget--) { s->failed_pc=0x0c04e994u; return 0; }
r[4]=r[14];
goto P_0c04e996;
P_0c04e996: /* original 4011, guest PC 0x0c04e996 */
if(!s->budget--) { s->failed_pc=0x0c04e996u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e998;
P_0c04e998: /* original 8918, guest PC 0x0c04e998 */
if(!s->budget--) { s->failed_pc=0x0c04e998u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e9cc; }
goto P_0c04e99a;
P_0c04e99a: /* original 9003, guest PC 0x0c04e99a */
if(!s->budget--) { s->failed_pc=0x0c04e99au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e9a4u,2);
goto P_0c04e99c;
P_0c04e99c: /* original a047, guest PC 0x0c04e99c */
if(!s->budget--) { s->failed_pc=0x0c04e99cu; return 0; }
goto P_0c04ea2e;
P_0c04e99e: /* original 0009, guest PC 0x0c04e99e */
if(!s->budget--) { s->failed_pc=0x0c04e99eu; return 0; }
if(!vf3_matrix_family(0x0c04e9a0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04e9a0u; return 0; } return 1;
P_0c04e9cc: /* original 4d15, guest PC 0x0c04e9cc */
if(!s->budget--) { s->failed_pc=0x0c04e9ccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c04e9ce;
P_0c04e9ce: /* original 6893, guest PC 0x0c04e9ce */
if(!s->budget--) { s->failed_pc=0x0c04e9ceu; return 0; }
r[8]=r[9];
goto P_0c04e9d0;
P_0c04e9d0: /* original 8f0a, guest PC 0x0c04e9d0 */
if(!s->budget--) { s->failed_pc=0x0c04e9d0u; return 0; }
cond=r[17]&1u;
r[12]=r[11];
if(!cond) { goto P_0c04e9e8; }
goto P_0c04e9d4;
P_0c04e9d2: /* original 6cb3, guest PC 0x0c04e9d2 */
if(!s->budget--) { s->failed_pc=0x0c04e9d2u; return 0; }
r[12]=r[11];
goto P_0c04e9d4;
P_0c04e9d4: /* original d235, guest PC 0x0c04e9d4 */
if(!s->budget--) { s->failed_pc=0x0c04e9d4u; return 0; }
r[2]=read(ram,0x0c04eaacu,4);
goto P_0c04e9d6;
P_0c04e9d6: /* original 65c2, guest PC 0x0c04e9d6 */
if(!s->budget--) { s->failed_pc=0x0c04e9d6u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c04e9d8;
P_0c04e9d8: /* original 420b, guest PC 0x0c04e9d8 */
if(!s->budget--) { s->failed_pc=0x0c04e9d8u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e9dcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e9dcu) { target=s->pc; goto dispatch; }
goto P_0c04e9dc;
P_0c04e9da: /* original 64e3, guest PC 0x0c04e9da */
if(!s->budget--) { s->failed_pc=0x0c04e9dau; return 0; }
r[4]=r[14];
goto P_0c04e9dc;
P_0c04e9dc: /* original 4011, guest PC 0x0c04e9dc */
if(!s->budget--) { s->failed_pc=0x0c04e9dcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e9de;
P_0c04e9de: /* original 8b22, guest PC 0x0c04e9de */
if(!s->budget--) { s->failed_pc=0x0c04e9deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ea26; }
goto P_0c04e9e0;
P_0c04e9e0: /* original 7801, guest PC 0x0c04e9e0 */
if(!s->budget--) { s->failed_pc=0x0c04e9e0u; return 0; }
r[8]+=0x00000001u;
goto P_0c04e9e2;
P_0c04e9e2: /* original 38d3, guest PC 0x0c04e9e2 */
if(!s->budget--) { s->failed_pc=0x0c04e9e2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[13])!=0);
goto P_0c04e9e4;
P_0c04e9e4: /* original 8ff6, guest PC 0x0c04e9e4 */
if(!s->budget--) { s->failed_pc=0x0c04e9e4u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000004u;
if(!cond) { goto P_0c04e9d4; }
goto P_0c04e9e8;
P_0c04e9e6: /* original 7c04, guest PC 0x0c04e9e6 */
if(!s->budget--) { s->failed_pc=0x0c04e9e6u; return 0; }
r[12]+=0x00000004u;
goto P_0c04e9e8;
P_0c04e9e8: /* original 4d15, guest PC 0x0c04e9e8 */
if(!s->budget--) { s->failed_pc=0x0c04e9e8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c04e9ea;
P_0c04e9ea: /* original 6893, guest PC 0x0c04e9ea */
if(!s->budget--) { s->failed_pc=0x0c04e9eau; return 0; }
r[8]=r[9];
goto P_0c04e9ec;
P_0c04e9ec: /* original 2f92, guest PC 0x0c04e9ec */
if(!s->budget--) { s->failed_pc=0x0c04e9ecu; return 0; }
write(ram,r[15],r[9],4);
goto P_0c04e9ee;
P_0c04e9ee: /* original 8f0a, guest PC 0x0c04e9ee */
if(!s->budget--) { s->failed_pc=0x0c04e9eeu; return 0; }
cond=r[17]&1u;
r[12]=r[11];
if(!cond) { goto P_0c04ea06; }
goto P_0c04e9f2;
P_0c04e9f0: /* original 6cb3, guest PC 0x0c04e9f0 */
if(!s->budget--) { s->failed_pc=0x0c04e9f0u; return 0; }
r[12]=r[11];
goto P_0c04e9f2;
P_0c04e9f2: /* original 65c2, guest PC 0x0c04e9f2 */
if(!s->budget--) { s->failed_pc=0x0c04e9f2u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c04e9f4;
P_0c04e9f4: /* original be8d, guest PC 0x0c04e9f4 */
if(!s->budget--) { s->failed_pc=0x0c04e9f4u; return 0; }
target=code_base|0x0c04e712u; r[16]=code_base|0x0c04e9f8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e9f8u) { target=s->pc; goto dispatch; }
goto P_0c04e9f8;
P_0c04e9f6: /* original 64e3, guest PC 0x0c04e9f6 */
if(!s->budget--) { s->failed_pc=0x0c04e9f6u; return 0; }
r[4]=r[14];
goto P_0c04e9f8;
P_0c04e9f8: /* original 4011, guest PC 0x0c04e9f8 */
if(!s->budget--) { s->failed_pc=0x0c04e9f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e9fa;
P_0c04e9fa: /* original 8d01, guest PC 0x0c04e9fa */
if(!s->budget--) { s->failed_pc=0x0c04e9fau; return 0; }
cond=r[17]&1u;
r[8]+=0x00000001u;
if(cond) { goto P_0c04ea00; }
goto P_0c04e9fe;
P_0c04e9fc: /* original 7801, guest PC 0x0c04e9fc */
if(!s->budget--) { s->failed_pc=0x0c04e9fcu; return 0; }
r[8]+=0x00000001u;
goto P_0c04e9fe;
P_0c04e9fe: /* original 2fa2, guest PC 0x0c04e9fe */
if(!s->budget--) { s->failed_pc=0x0c04e9feu; return 0; }
write(ram,r[15],r[10],4);
goto P_0c04ea00;
P_0c04ea00: /* original 38d3, guest PC 0x0c04ea00 */
if(!s->budget--) { s->failed_pc=0x0c04ea00u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[13])!=0);
goto P_0c04ea02;
P_0c04ea02: /* original 8ff6, guest PC 0x0c04ea02 */
if(!s->budget--) { s->failed_pc=0x0c04ea02u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000004u;
if(!cond) { goto P_0c04e9f2; }
goto P_0c04ea06;
P_0c04ea04: /* original 7c04, guest PC 0x0c04ea04 */
if(!s->budget--) { s->failed_pc=0x0c04ea04u; return 0; }
r[12]+=0x00000004u;
goto P_0c04ea06;
P_0c04ea06: /* original b6a2, guest PC 0x0c04ea06 */
if(!s->budget--) { s->failed_pc=0x0c04ea06u; return 0; }
target=code_base|0x0c04f74eu; r[16]=code_base|0x0c04ea0au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04ea0au) { target=s->pc; goto dispatch; }
goto P_0c04ea0a;
P_0c04ea08: /* original 64e3, guest PC 0x0c04ea08 */
if(!s->budget--) { s->failed_pc=0x0c04ea08u; return 0; }
r[4]=r[14];
goto P_0c04ea0a;
P_0c04ea0a: /* original 4011, guest PC 0x0c04ea0a */
if(!s->budget--) { s->failed_pc=0x0c04ea0au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04ea0c;
P_0c04ea0c: /* original 8f06, guest PC 0x0c04ea0c */
if(!s->budget--) { s->failed_pc=0x0c04ea0cu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c04ea1c; }
goto P_0c04ea10;
P_0c04ea0e: /* original 6403, guest PC 0x0c04ea0e */
if(!s->budget--) { s->failed_pc=0x0c04ea0eu; return 0; }
r[4]=r[0];
goto P_0c04ea10;
P_0c04ea10: /* original d327, guest PC 0x0c04ea10 */
if(!s->budget--) { s->failed_pc=0x0c04ea10u; return 0; }
r[3]=read(ram,0x0c04eab0u,4);
goto P_0c04ea12;
P_0c04ea12: /* original 430b, guest PC 0x0c04ea12 */
if(!s->budget--) { s->failed_pc=0x0c04ea12u; return 0; }
target=r[3];
r[16]=code_base|0x0c04ea16u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04ea16u) { target=s->pc; goto dispatch; }
goto P_0c04ea16;
P_0c04ea14: /* original 64e3, guest PC 0x0c04ea14 */
if(!s->budget--) { s->failed_pc=0x0c04ea14u; return 0; }
r[4]=r[14];
goto P_0c04ea16;
P_0c04ea16: /* original 4011, guest PC 0x0c04ea16 */
if(!s->budget--) { s->failed_pc=0x0c04ea16u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04ea18;
P_0c04ea18: /* original 8d02, guest PC 0x0c04ea18 */
if(!s->budget--) { s->failed_pc=0x0c04ea18u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c04ea20; }
goto P_0c04ea1c;
P_0c04ea1a: /* original 6403, guest PC 0x0c04ea1a */
if(!s->budget--) { s->failed_pc=0x0c04ea1au; return 0; }
r[4]=r[0];
goto P_0c04ea1c;
P_0c04ea1c: /* original a007, guest PC 0x0c04ea1c */
if(!s->budget--) { s->failed_pc=0x0c04ea1cu; return 0; }
r[0]=r[4];
goto P_0c04ea2e;
P_0c04ea1e: /* original 6043, guest PC 0x0c04ea1e */
if(!s->budget--) { s->failed_pc=0x0c04ea1eu; return 0; }
r[0]=r[4];
goto P_0c04ea20;
P_0c04ea20: /* original 63f2, guest PC 0x0c04ea20 */
if(!s->budget--) { s->failed_pc=0x0c04ea20u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c04ea22;
P_0c04ea22: /* original 2338, guest PC 0x0c04ea22 */
if(!s->budget--) { s->failed_pc=0x0c04ea22u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04ea24;
P_0c04ea24: /* original 8902, guest PC 0x0c04ea24 */
if(!s->budget--) { s->failed_pc=0x0c04ea24u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ea2c; }
goto P_0c04ea26;
P_0c04ea26: /* original 903f, guest PC 0x0c04ea26 */
if(!s->budget--) { s->failed_pc=0x0c04ea26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04eaa8u,2);
goto P_0c04ea28;
P_0c04ea28: /* original a001, guest PC 0x0c04ea28 */
if(!s->budget--) { s->failed_pc=0x0c04ea28u; return 0; }
goto P_0c04ea2e;
P_0c04ea2a: /* original 0009, guest PC 0x0c04ea2a */
if(!s->budget--) { s->failed_pc=0x0c04ea2au; return 0; }
goto P_0c04ea2c;
P_0c04ea2c: /* original e000, guest PC 0x0c04ea2c */
if(!s->budget--) { s->failed_pc=0x0c04ea2cu; return 0; }
r[0]=0x00000000u;
goto P_0c04ea2e;
P_0c04ea2e: /* original 7f04, guest PC 0x0c04ea2e */
if(!s->budget--) { s->failed_pc=0x0c04ea2eu; return 0; }
r[15]+=0x00000004u;
goto P_0c04ea30;
P_0c04ea30: /* original 4f16, guest PC 0x0c04ea30 */
if(!s->budget--) { s->failed_pc=0x0c04ea30u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ea32;
P_0c04ea32: /* original 4f26, guest PC 0x0c04ea32 */
if(!s->budget--) { s->failed_pc=0x0c04ea32u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ea34;
P_0c04ea34: /* original 68f6, guest PC 0x0c04ea34 */
if(!s->budget--) { s->failed_pc=0x0c04ea34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04ea36;
P_0c04ea36: /* original 69f6, guest PC 0x0c04ea36 */
if(!s->budget--) { s->failed_pc=0x0c04ea36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04ea38;
P_0c04ea38: /* original 6af6, guest PC 0x0c04ea38 */
if(!s->budget--) { s->failed_pc=0x0c04ea38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04ea3a;
P_0c04ea3a: /* original 6bf6, guest PC 0x0c04ea3a */
if(!s->budget--) { s->failed_pc=0x0c04ea3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04ea3c;
P_0c04ea3c: /* original 6cf6, guest PC 0x0c04ea3c */
if(!s->budget--) { s->failed_pc=0x0c04ea3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04ea3e;
P_0c04ea3e: /* original 6df6, guest PC 0x0c04ea3e */
if(!s->budget--) { s->failed_pc=0x0c04ea3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04ea40;
P_0c04ea40: /* original 000b, guest PC 0x0c04ea40 */
if(!s->budget--) { s->failed_pc=0x0c04ea40u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04ea42: /* original 6ef6, guest PC 0x0c04ea42 */
if(!s->budget--) { s->failed_pc=0x0c04ea42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04ea44u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
