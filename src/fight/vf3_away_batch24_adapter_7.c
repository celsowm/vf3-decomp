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
int vf3_away_batch24_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0ba7b6u: goto P_0c0ba7b6;
case 0x0c0ba7b8u: goto P_0c0ba7b8;
case 0x0c0ba7bau: goto P_0c0ba7ba;
case 0x0c0ba7bcu: goto P_0c0ba7bc;
case 0x0c0ba7beu: goto P_0c0ba7be;
case 0x0c0ba7c0u: goto P_0c0ba7c0;
case 0x0c0ba7c2u: goto P_0c0ba7c2;
case 0x0c0ba7c4u: goto P_0c0ba7c4;
case 0x0c0ba7c6u: goto P_0c0ba7c6;
case 0x0c0ba7c8u: goto P_0c0ba7c8;
case 0x0c0ba7cau: goto P_0c0ba7ca;
case 0x0c0ba7ccu: goto P_0c0ba7cc;
case 0x0c0ba7ceu: goto P_0c0ba7ce;
case 0x0c0ba7d0u: goto P_0c0ba7d0;
case 0x0c0ba7d2u: goto P_0c0ba7d2;
case 0x0c0ba7d4u: goto P_0c0ba7d4;
case 0x0c0ba7d6u: goto P_0c0ba7d6;
case 0x0c0ba7d8u: goto P_0c0ba7d8;
case 0x0c0ba7dau: goto P_0c0ba7da;
case 0x0c0ba7dcu: goto P_0c0ba7dc;
case 0x0c0ba7deu: goto P_0c0ba7de;
case 0x0c0ba7e0u: goto P_0c0ba7e0;
case 0x0c0ba7e2u: goto P_0c0ba7e2;
case 0x0c0ba7e4u: goto P_0c0ba7e4;
case 0x0c0ba7e6u: goto P_0c0ba7e6;
case 0x0c0ba7e8u: goto P_0c0ba7e8;
case 0x0c0ba7eau: goto P_0c0ba7ea;
case 0x0c0ba7ecu: goto P_0c0ba7ec;
case 0x0c0ba7eeu: goto P_0c0ba7ee;
case 0x0c0ba7f0u: goto P_0c0ba7f0;
case 0x0c0ba7f2u: goto P_0c0ba7f2;
case 0x0c0ba7f4u: goto P_0c0ba7f4;
case 0x0c0ba7f6u: goto P_0c0ba7f6;
case 0x0c0ba7f8u: goto P_0c0ba7f8;
case 0x0c0ba7fau: goto P_0c0ba7fa;
case 0x0c0ba7fcu: goto P_0c0ba7fc;
case 0x0c0ba7feu: goto P_0c0ba7fe;
case 0x0c0ba800u: goto P_0c0ba800;
case 0x0c0ba802u: goto P_0c0ba802;
case 0x0c0ba804u: goto P_0c0ba804;
case 0x0c0ba806u: goto P_0c0ba806;
case 0x0c0ba808u: goto P_0c0ba808;
case 0x0c0ba80au: goto P_0c0ba80a;
case 0x0c0ba80cu: goto P_0c0ba80c;
case 0x0c0ba80eu: goto P_0c0ba80e;
case 0x0c0ba810u: goto P_0c0ba810;
case 0x0c0ba812u: goto P_0c0ba812;
case 0x0c0ba814u: goto P_0c0ba814;
case 0x0c0ba816u: goto P_0c0ba816;
case 0x0c0ba818u: goto P_0c0ba818;
case 0x0c0ba81au: goto P_0c0ba81a;
case 0x0c0ba81cu: goto P_0c0ba81c;
case 0x0c0ba81eu: goto P_0c0ba81e;
case 0x0c0ba820u: goto P_0c0ba820;
case 0x0c0ba822u: goto P_0c0ba822;
case 0x0c0ba824u: goto P_0c0ba824;
case 0x0c0ba826u: goto P_0c0ba826;
case 0x0c0ba828u: goto P_0c0ba828;
case 0x0c0ba82au: goto P_0c0ba82a;
case 0x0c0ba82cu: goto P_0c0ba82c;
case 0x0c0ba82eu: goto P_0c0ba82e;
case 0x0c0ba830u: goto P_0c0ba830;
case 0x0c0ba832u: goto P_0c0ba832;
case 0x0c0ba834u: goto P_0c0ba834;
case 0x0c0ba836u: goto P_0c0ba836;
case 0x0c0ba838u: goto P_0c0ba838;
case 0x0c0ba83au: goto P_0c0ba83a;
case 0x0c0ba83cu: goto P_0c0ba83c;
case 0x0c0ba83eu: goto P_0c0ba83e;
case 0x0c0ba840u: goto P_0c0ba840;
case 0x0c0ba842u: goto P_0c0ba842;
case 0x0c0ba844u: goto P_0c0ba844;
case 0x0c0ba846u: goto P_0c0ba846;
case 0x0c0ba848u: goto P_0c0ba848;
case 0x0c0ba84au: goto P_0c0ba84a;
case 0x0c0ba84cu: goto P_0c0ba84c;
case 0x0c0ba84eu: goto P_0c0ba84e;
case 0x0c0ba850u: goto P_0c0ba850;
case 0x0c0ba852u: goto P_0c0ba852;
case 0x0c0ba854u: goto P_0c0ba854;
case 0x0c0ba856u: goto P_0c0ba856;
case 0x0c0ba858u: goto P_0c0ba858;
case 0x0c0ba85au: goto P_0c0ba85a;
case 0x0c0ba85cu: goto P_0c0ba85c;
case 0x0c0ba85eu: goto P_0c0ba85e;
case 0x0c0ba860u: goto P_0c0ba860;
case 0x0c0ba862u: goto P_0c0ba862;
case 0x0c0ba864u: goto P_0c0ba864;
case 0x0c0ba866u: goto P_0c0ba866;
case 0x0c0ba868u: goto P_0c0ba868;
case 0x0c0ba86au: goto P_0c0ba86a;
case 0x0c0ba86cu: goto P_0c0ba86c;
case 0x0c0ba86eu: goto P_0c0ba86e;
case 0x0c0ba870u: goto P_0c0ba870;
case 0x0c0ba872u: goto P_0c0ba872;
case 0x0c0ba874u: goto P_0c0ba874;
case 0x0c0ba876u: goto P_0c0ba876;
case 0x0c0ba878u: goto P_0c0ba878;
case 0x0c0ba87au: goto P_0c0ba87a;
case 0x0c0ba87cu: goto P_0c0ba87c;
case 0x0c0ba87eu: goto P_0c0ba87e;
case 0x0c0ba880u: goto P_0c0ba880;
case 0x0c0ba882u: goto P_0c0ba882;
case 0x0c0ba884u: goto P_0c0ba884;
case 0x0c0ba886u: goto P_0c0ba886;
case 0x0c0ba888u: goto P_0c0ba888;
case 0x0c0ba88au: goto P_0c0ba88a;
case 0x0c0ba88cu: goto P_0c0ba88c;
case 0x0c0ba88eu: goto P_0c0ba88e;
case 0x0c0ba890u: goto P_0c0ba890;
case 0x0c0ba892u: goto P_0c0ba892;
case 0x0c0ba894u: goto P_0c0ba894;
case 0x0c0ba896u: goto P_0c0ba896;
case 0x0c0ba898u: goto P_0c0ba898;
case 0x0c0ba89au: goto P_0c0ba89a;
case 0x0c0ba89cu: goto P_0c0ba89c;
case 0x0c0ba89eu: goto P_0c0ba89e;
case 0x0c0ba8a0u: goto P_0c0ba8a0;
case 0x0c0ba8a2u: goto P_0c0ba8a2;
case 0x0c0ba8a4u: goto P_0c0ba8a4;
case 0x0c0ba8a6u: goto P_0c0ba8a6;
case 0x0c0ba8a8u: goto P_0c0ba8a8;
case 0x0c0ba8aau: goto P_0c0ba8aa;
case 0x0c0ba8acu: goto P_0c0ba8ac;
case 0x0c0ba8aeu: goto P_0c0ba8ae;
case 0x0c0ba8b0u: goto P_0c0ba8b0;
case 0x0c0ba8b2u: goto P_0c0ba8b2;
case 0x0c0ba8b4u: goto P_0c0ba8b4;
case 0x0c0ba8b6u: goto P_0c0ba8b6;
case 0x0c0ba8b8u: goto P_0c0ba8b8;
case 0x0c0ba8bau: goto P_0c0ba8ba;
case 0x0c0ba8bcu: goto P_0c0ba8bc;
case 0x0c0ba8beu: goto P_0c0ba8be;
case 0x0c0ba8c0u: goto P_0c0ba8c0;
case 0x0c0ba8c2u: goto P_0c0ba8c2;
case 0x0c0ba8c4u: goto P_0c0ba8c4;
case 0x0c0ba8c6u: goto P_0c0ba8c6;
case 0x0c0ba8c8u: goto P_0c0ba8c8;
case 0x0c0ba8cau: goto P_0c0ba8ca;
case 0x0c0ba8ccu: goto P_0c0ba8cc;
case 0x0c0ba8ceu: goto P_0c0ba8ce;
case 0x0c0ba8d0u: goto P_0c0ba8d0;
case 0x0c0ba8d2u: goto P_0c0ba8d2;
case 0x0c0ba8d4u: goto P_0c0ba8d4;
case 0x0c0ba8d6u: goto P_0c0ba8d6;
case 0x0c0ba8d8u: goto P_0c0ba8d8;
case 0x0c0ba8dau: goto P_0c0ba8da;
case 0x0c0ba8dcu: goto P_0c0ba8dc;
case 0x0c0ba8deu: goto P_0c0ba8de;
case 0x0c0ba8e0u: goto P_0c0ba8e0;
case 0x0c0ba8e2u: goto P_0c0ba8e2;
case 0x0c0ba8e4u: goto P_0c0ba8e4;
case 0x0c0ba8e6u: goto P_0c0ba8e6;
case 0x0c0ba8e8u: goto P_0c0ba8e8;
case 0x0c0ba8eau: goto P_0c0ba8ea;
case 0x0c0ba8ecu: goto P_0c0ba8ec;
case 0x0c0ba8eeu: goto P_0c0ba8ee;
case 0x0c0ba8f0u: goto P_0c0ba8f0;
case 0x0c0ba8f2u: goto P_0c0ba8f2;
case 0x0c0ba8f4u: goto P_0c0ba8f4;
case 0x0c0ba8f6u: goto P_0c0ba8f6;
case 0x0c0ba8f8u: goto P_0c0ba8f8;
case 0x0c0ba8fau: goto P_0c0ba8fa;
case 0x0c0ba8fcu: goto P_0c0ba8fc;
case 0x0c0ba8feu: goto P_0c0ba8fe;
case 0x0c0ba900u: goto P_0c0ba900;
case 0x0c0ba902u: goto P_0c0ba902;
case 0x0c0ba904u: goto P_0c0ba904;
case 0x0c0ba906u: goto P_0c0ba906;
case 0x0c0ba908u: goto P_0c0ba908;
case 0x0c0ba90au: goto P_0c0ba90a;
case 0x0c0ba90cu: goto P_0c0ba90c;
case 0x0c0ba90eu: goto P_0c0ba90e;
case 0x0c0ba910u: goto P_0c0ba910;
case 0x0c0ba912u: goto P_0c0ba912;
case 0x0c0ba914u: goto P_0c0ba914;
case 0x0c0ba916u: goto P_0c0ba916;
case 0x0c0ba918u: goto P_0c0ba918;
case 0x0c0ba988u: goto P_0c0ba988;
case 0x0c0ba98au: goto P_0c0ba98a;
case 0x0c0ba98cu: goto P_0c0ba98c;
case 0x0c0ba98eu: goto P_0c0ba98e;
case 0x0c0ba990u: goto P_0c0ba990;
case 0x0c0ba992u: goto P_0c0ba992;
case 0x0c0ba994u: goto P_0c0ba994;
case 0x0c0ba996u: goto P_0c0ba996;
case 0x0c0ba998u: goto P_0c0ba998;
case 0x0c0ba99au: goto P_0c0ba99a;
case 0x0c0ba99cu: goto P_0c0ba99c;
case 0x0c0ba99eu: goto P_0c0ba99e;
case 0x0c0ba9a0u: goto P_0c0ba9a0;
case 0x0c0ba9a2u: goto P_0c0ba9a2;
case 0x0c0ba9a4u: goto P_0c0ba9a4;
case 0x0c0ba9a6u: goto P_0c0ba9a6;
case 0x0c0ba9a8u: goto P_0c0ba9a8;
case 0x0c0ba9aau: goto P_0c0ba9aa;
case 0x0c0ba9acu: goto P_0c0ba9ac;
case 0x0c0ba9aeu: goto P_0c0ba9ae;
case 0x0c0ba9b0u: goto P_0c0ba9b0;
case 0x0c0ba9b2u: goto P_0c0ba9b2;
case 0x0c0ba9b4u: goto P_0c0ba9b4;
case 0x0c0ba9b6u: goto P_0c0ba9b6;
case 0x0c0ba9b8u: goto P_0c0ba9b8;
case 0x0c0ba9bau: goto P_0c0ba9ba;
case 0x0c0ba9bcu: goto P_0c0ba9bc;
case 0x0c0ba9beu: goto P_0c0ba9be;
case 0x0c0ba9c0u: goto P_0c0ba9c0;
case 0x0c0ba9c2u: goto P_0c0ba9c2;
case 0x0c0ba9c4u: goto P_0c0ba9c4;
case 0x0c0ba9c6u: goto P_0c0ba9c6;
case 0x0c0ba9c8u: goto P_0c0ba9c8;
case 0x0c0ba9cau: goto P_0c0ba9ca;
case 0x0c0ba9ccu: goto P_0c0ba9cc;
case 0x0c0ba9ceu: goto P_0c0ba9ce;
case 0x0c0ba9d0u: goto P_0c0ba9d0;
case 0x0c0ba9d2u: goto P_0c0ba9d2;
case 0x0c0ba9d4u: goto P_0c0ba9d4;
case 0x0c0ba9d6u: goto P_0c0ba9d6;
case 0x0c0ba9d8u: goto P_0c0ba9d8;
case 0x0c0ba9dau: goto P_0c0ba9da;
case 0x0c0ba9dcu: goto P_0c0ba9dc;
case 0x0c0ba9deu: goto P_0c0ba9de;
case 0x0c0ba9e0u: goto P_0c0ba9e0;
case 0x0c0ba9e2u: goto P_0c0ba9e2;
case 0x0c0ba9e4u: goto P_0c0ba9e4;
case 0x0c0ba9e6u: goto P_0c0ba9e6;
case 0x0c0ba9e8u: goto P_0c0ba9e8;
case 0x0c0ba9eau: goto P_0c0ba9ea;
case 0x0c0ba9ecu: goto P_0c0ba9ec;
case 0x0c0ba9eeu: goto P_0c0ba9ee;
case 0x0c0ba9f0u: goto P_0c0ba9f0;
case 0x0c0ba9f2u: goto P_0c0ba9f2;
case 0x0c0ba9f4u: goto P_0c0ba9f4;
case 0x0c0ba9f6u: goto P_0c0ba9f6;
case 0x0c0ba9f8u: goto P_0c0ba9f8;
case 0x0c0ba9fau: goto P_0c0ba9fa;
case 0x0c0ba9fcu: goto P_0c0ba9fc;
case 0x0c0ba9feu: goto P_0c0ba9fe;
case 0x0c0baa00u: goto P_0c0baa00;
case 0x0c0baa02u: goto P_0c0baa02;
case 0x0c0baa04u: goto P_0c0baa04;
case 0x0c0baa06u: goto P_0c0baa06;
case 0x0c0baa08u: goto P_0c0baa08;
case 0x0c0baa0au: goto P_0c0baa0a;
case 0x0c0baa0cu: goto P_0c0baa0c;
case 0x0c0baa0eu: goto P_0c0baa0e;
case 0x0c0baa10u: goto P_0c0baa10;
case 0x0c0baa12u: goto P_0c0baa12;
case 0x0c0baa14u: goto P_0c0baa14;
case 0x0c0baa16u: goto P_0c0baa16;
case 0x0c0baa18u: goto P_0c0baa18;
case 0x0c0baa1au: goto P_0c0baa1a;
case 0x0c0baa1cu: goto P_0c0baa1c;
case 0x0c0baa1eu: goto P_0c0baa1e;
case 0x0c0baa20u: goto P_0c0baa20;
case 0x0c0baa22u: goto P_0c0baa22;
case 0x0c0baa24u: goto P_0c0baa24;
case 0x0c0baa26u: goto P_0c0baa26;
case 0x0c0baa28u: goto P_0c0baa28;
case 0x0c0baa2au: goto P_0c0baa2a;
case 0x0c0baa2cu: goto P_0c0baa2c;
case 0x0c0baa2eu: goto P_0c0baa2e;
case 0x0c0baa30u: goto P_0c0baa30;
case 0x0c0baa32u: goto P_0c0baa32;
case 0x0c0baa34u: goto P_0c0baa34;
case 0x0c0baa36u: goto P_0c0baa36;
case 0x0c0baa38u: goto P_0c0baa38;
case 0x0c0baa3au: goto P_0c0baa3a;
case 0x0c0baa3cu: goto P_0c0baa3c;
case 0x0c0baa3eu: goto P_0c0baa3e;
case 0x0c0baa40u: goto P_0c0baa40;
case 0x0c0baa42u: goto P_0c0baa42;
case 0x0c0baa44u: goto P_0c0baa44;
case 0x0c0baa46u: goto P_0c0baa46;
case 0x0c0baa48u: goto P_0c0baa48;
case 0x0c0baa4au: goto P_0c0baa4a;
case 0x0c0baa4cu: goto P_0c0baa4c;
case 0x0c0baa4eu: goto P_0c0baa4e;
case 0x0c0baa50u: goto P_0c0baa50;
case 0x0c0baa52u: goto P_0c0baa52;
case 0x0c0baa54u: goto P_0c0baa54;
case 0x0c0baa56u: goto P_0c0baa56;
case 0x0c0baa58u: goto P_0c0baa58;
case 0x0c0baa5au: goto P_0c0baa5a;
case 0x0c0baa5cu: goto P_0c0baa5c;
case 0x0c0baa5eu: goto P_0c0baa5e;
case 0x0c0baa60u: goto P_0c0baa60;
case 0x0c0baa62u: goto P_0c0baa62;
case 0x0c0baa64u: goto P_0c0baa64;
case 0x0c0baa66u: goto P_0c0baa66;
case 0x0c0baa68u: goto P_0c0baa68;
case 0x0c0baa6au: goto P_0c0baa6a;
case 0x0c0baa6cu: goto P_0c0baa6c;
case 0x0c0baa6eu: goto P_0c0baa6e;
case 0x0c0baa70u: goto P_0c0baa70;
case 0x0c0baa72u: goto P_0c0baa72;
case 0x0c0baa74u: goto P_0c0baa74;
case 0x0c0baa76u: goto P_0c0baa76;
case 0x0c0baa78u: goto P_0c0baa78;
case 0x0c0baa7au: goto P_0c0baa7a;
case 0x0c0baa7cu: goto P_0c0baa7c;
case 0x0c0baa7eu: goto P_0c0baa7e;
case 0x0c0baa80u: goto P_0c0baa80;
case 0x0c0baa82u: goto P_0c0baa82;
case 0x0c0baa84u: goto P_0c0baa84;
case 0x0c0baa86u: goto P_0c0baa86;
case 0x0c0baa88u: goto P_0c0baa88;
case 0x0c0baa8au: goto P_0c0baa8a;
case 0x0c0baa8cu: goto P_0c0baa8c;
case 0x0c0baa8eu: goto P_0c0baa8e;
case 0x0c0baa90u: goto P_0c0baa90;
case 0x0c0baa92u: goto P_0c0baa92;
case 0x0c0baa94u: goto P_0c0baa94;
case 0x0c0baa96u: goto P_0c0baa96;
case 0x0c0baa98u: goto P_0c0baa98;
case 0x0c0baa9au: goto P_0c0baa9a;
case 0x0c0baa9cu: goto P_0c0baa9c;
case 0x0c0baa9eu: goto P_0c0baa9e;
case 0x0c0baaa0u: goto P_0c0baaa0;
case 0x0c0baaa2u: goto P_0c0baaa2;
case 0x0c0baaa4u: goto P_0c0baaa4;
case 0x0c0baaa6u: goto P_0c0baaa6;
case 0x0c0baaa8u: goto P_0c0baaa8;
case 0x0c0baaaau: goto P_0c0baaaa;
case 0x0c0baaacu: goto P_0c0baaac;
case 0x0c0baaaeu: goto P_0c0baaae;
case 0x0c0baab0u: goto P_0c0baab0;
case 0x0c0baab2u: goto P_0c0baab2;
case 0x0c0baab4u: goto P_0c0baab4;
case 0x0c0baab6u: goto P_0c0baab6;
case 0x0c0baab8u: goto P_0c0baab8;
case 0x0c0baabau: goto P_0c0baaba;
case 0x0c0baabcu: goto P_0c0baabc;
case 0x0c0baabeu: goto P_0c0baabe;
case 0x0c0baac0u: goto P_0c0baac0;
case 0x0c0baac2u: goto P_0c0baac2;
case 0x0c0baac4u: goto P_0c0baac4;
case 0x0c0baac6u: goto P_0c0baac6;
case 0x0c0baac8u: goto P_0c0baac8;
case 0x0c0baacau: goto P_0c0baaca;
case 0x0c0baaccu: goto P_0c0baacc;
case 0x0c0baaceu: goto P_0c0baace;
case 0x0c0baad0u: goto P_0c0baad0;
case 0x0c0baad2u: goto P_0c0baad2;
case 0x0c0baad4u: goto P_0c0baad4;
case 0x0c0baad6u: goto P_0c0baad6;
case 0x0c0baad8u: goto P_0c0baad8;
case 0x0c0baadau: goto P_0c0baada;
case 0x0c0baadcu: goto P_0c0baadc;
case 0x0c0baadeu: goto P_0c0baade;
case 0x0c0baae0u: goto P_0c0baae0;
case 0x0c0bab5au: goto P_0c0bab5a;
case 0x0c0bab5cu: goto P_0c0bab5c;
case 0x0c0bab5eu: goto P_0c0bab5e;
case 0x0c0bab60u: goto P_0c0bab60;
case 0x0c0bab62u: goto P_0c0bab62;
case 0x0c0bab64u: goto P_0c0bab64;
case 0x0c0bab66u: goto P_0c0bab66;
case 0x0c0bab68u: goto P_0c0bab68;
case 0x0c0bab6au: goto P_0c0bab6a;
case 0x0c0bab6cu: goto P_0c0bab6c;
case 0x0c0bab6eu: goto P_0c0bab6e;
case 0x0c0bab70u: goto P_0c0bab70;
case 0x0c0bab72u: goto P_0c0bab72;
case 0x0c0bab74u: goto P_0c0bab74;
case 0x0c0bab76u: goto P_0c0bab76;
case 0x0c0bab78u: goto P_0c0bab78;
case 0x0c0bab7au: goto P_0c0bab7a;
case 0x0c0bab7cu: goto P_0c0bab7c;
case 0x0c0bab7eu: goto P_0c0bab7e;
case 0x0c0bab80u: goto P_0c0bab80;
case 0x0c0bab82u: goto P_0c0bab82;
case 0x0c0bab84u: goto P_0c0bab84;
case 0x0c0bab86u: goto P_0c0bab86;
case 0x0c0bab88u: goto P_0c0bab88;
case 0x0c0bab8au: goto P_0c0bab8a;
case 0x0c0bab8cu: goto P_0c0bab8c;
case 0x0c0bab8eu: goto P_0c0bab8e;
case 0x0c0bab90u: goto P_0c0bab90;
case 0x0c0bab92u: goto P_0c0bab92;
case 0x0c0bab94u: goto P_0c0bab94;
case 0x0c0bab96u: goto P_0c0bab96;
case 0x0c0bab98u: goto P_0c0bab98;
case 0x0c0bab9au: goto P_0c0bab9a;
case 0x0c0bab9cu: goto P_0c0bab9c;
case 0x0c0bab9eu: goto P_0c0bab9e;
case 0x0c0baba0u: goto P_0c0baba0;
case 0x0c0baba2u: goto P_0c0baba2;
case 0x0c0baba4u: goto P_0c0baba4;
case 0x0c0baba6u: goto P_0c0baba6;
case 0x0c0baba8u: goto P_0c0baba8;
case 0x0c0babaau: goto P_0c0babaa;
case 0x0c0babacu: goto P_0c0babac;
case 0x0c0babaeu: goto P_0c0babae;
case 0x0c0babb0u: goto P_0c0babb0;
case 0x0c0babb2u: goto P_0c0babb2;
case 0x0c0babb4u: goto P_0c0babb4;
case 0x0c0babb6u: goto P_0c0babb6;
case 0x0c0babb8u: goto P_0c0babb8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0ba7b6: /* original 2fe6, guest PC 0x0c0ba7b6 */
if(!s->budget--) { s->failed_pc=0x0c0ba7b6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ba7b8;
P_0c0ba7b8: /* original 2fd6, guest PC 0x0c0ba7b8 */
if(!s->budget--) { s->failed_pc=0x0c0ba7b8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ba7ba;
P_0c0ba7ba: /* original 2fc6, guest PC 0x0c0ba7ba */
if(!s->budget--) { s->failed_pc=0x0c0ba7bau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ba7bc;
P_0c0ba7bc: /* original 2fb6, guest PC 0x0c0ba7bc */
if(!s->budget--) { s->failed_pc=0x0c0ba7bcu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ba7be;
P_0c0ba7be: /* original 2fa6, guest PC 0x0c0ba7be */
if(!s->budget--) { s->failed_pc=0x0c0ba7beu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ba7c0;
P_0c0ba7c0: /* original 2f96, guest PC 0x0c0ba7c0 */
if(!s->budget--) { s->failed_pc=0x0c0ba7c0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ba7c2;
P_0c0ba7c2: /* original 4f22, guest PC 0x0c0ba7c2 */
if(!s->budget--) { s->failed_pc=0x0c0ba7c2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ba7c4;
P_0c0ba7c4: /* original 5d44, guest PC 0x0c0ba7c4 */
if(!s->budget--) { s->failed_pc=0x0c0ba7c4u; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0ba7c6;
P_0c0ba7c6: /* original 94a8, guest PC 0x0c0ba7c6 */
if(!s->budget--) { s->failed_pc=0x0c0ba7c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba91au,2);
goto P_0c0ba7c8;
P_0c0ba7c8: /* original de6e, guest PC 0x0c0ba7c8 */
if(!s->budget--) { s->failed_pc=0x0c0ba7c8u; return 0; }
r[14]=read(ram,0x0c0ba984u,4);
goto P_0c0ba7ca;
P_0c0ba7ca: /* original 7ff8, guest PC 0x0c0ba7ca */
if(!s->budget--) { s->failed_pc=0x0c0ba7cau; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0ba7cc;
P_0c0ba7cc: /* original 4e0b, guest PC 0x0c0ba7cc */
if(!s->budget--) { s->failed_pc=0x0c0ba7ccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba7d0u;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba7d0u) { target=s->pc; goto dispatch; }
goto P_0c0ba7d0;
P_0c0ba7ce: /* original 65d2, guest PC 0x0c0ba7ce */
if(!s->budget--) { s->failed_pc=0x0c0ba7ceu; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0ba7d0;
P_0c0ba7d0: /* original 94a4, guest PC 0x0c0ba7d0 */
if(!s->budget--) { s->failed_pc=0x0c0ba7d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba91cu,2);
goto P_0c0ba7d2;
P_0c0ba7d2: /* original 4e0b, guest PC 0x0c0ba7d2 */
if(!s->budget--) { s->failed_pc=0x0c0ba7d2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba7d6u;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba7d6u) { target=s->pc; goto dispatch; }
goto P_0c0ba7d6;
P_0c0ba7d4: /* original 55d1, guest PC 0x0c0ba7d4 */
if(!s->budget--) { s->failed_pc=0x0c0ba7d4u; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0ba7d6;
P_0c0ba7d6: /* original 94a2, guest PC 0x0c0ba7d6 */
if(!s->budget--) { s->failed_pc=0x0c0ba7d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba91eu,2);
goto P_0c0ba7d8;
P_0c0ba7d8: /* original 4e0b, guest PC 0x0c0ba7d8 */
if(!s->budget--) { s->failed_pc=0x0c0ba7d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba7dcu;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba7dcu) { target=s->pc; goto dispatch; }
goto P_0c0ba7dc;
P_0c0ba7da: /* original 55d2, guest PC 0x0c0ba7da */
if(!s->budget--) { s->failed_pc=0x0c0ba7dau; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0ba7dc;
P_0c0ba7dc: /* original 94a0, guest PC 0x0c0ba7dc */
if(!s->budget--) { s->failed_pc=0x0c0ba7dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba920u,2);
goto P_0c0ba7de;
P_0c0ba7de: /* original 4e0b, guest PC 0x0c0ba7de */
if(!s->budget--) { s->failed_pc=0x0c0ba7deu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba7e2u;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba7e2u) { target=s->pc; goto dispatch; }
goto P_0c0ba7e2;
P_0c0ba7e0: /* original 55d3, guest PC 0x0c0ba7e0 */
if(!s->budget--) { s->failed_pc=0x0c0ba7e0u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0ba7e2;
P_0c0ba7e2: /* original 949e, guest PC 0x0c0ba7e2 */
if(!s->budget--) { s->failed_pc=0x0c0ba7e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba922u,2);
goto P_0c0ba7e4;
P_0c0ba7e4: /* original 4e0b, guest PC 0x0c0ba7e4 */
if(!s->budget--) { s->failed_pc=0x0c0ba7e4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba7e8u;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba7e8u) { target=s->pc; goto dispatch; }
goto P_0c0ba7e8;
P_0c0ba7e6: /* original 55d4, guest PC 0x0c0ba7e6 */
if(!s->budget--) { s->failed_pc=0x0c0ba7e6u; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0ba7e8;
P_0c0ba7e8: /* original 949c, guest PC 0x0c0ba7e8 */
if(!s->budget--) { s->failed_pc=0x0c0ba7e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba924u,2);
goto P_0c0ba7ea;
P_0c0ba7ea: /* original 4e0b, guest PC 0x0c0ba7ea */
if(!s->budget--) { s->failed_pc=0x0c0ba7eau; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba7eeu;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba7eeu) { target=s->pc; goto dispatch; }
goto P_0c0ba7ee;
P_0c0ba7ec: /* original 55d5, guest PC 0x0c0ba7ec */
if(!s->budget--) { s->failed_pc=0x0c0ba7ecu; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0ba7ee;
P_0c0ba7ee: /* original 949a, guest PC 0x0c0ba7ee */
if(!s->budget--) { s->failed_pc=0x0c0ba7eeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba926u,2);
goto P_0c0ba7f0;
P_0c0ba7f0: /* original 4e0b, guest PC 0x0c0ba7f0 */
if(!s->budget--) { s->failed_pc=0x0c0ba7f0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba7f4u;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba7f4u) { target=s->pc; goto dispatch; }
goto P_0c0ba7f4;
P_0c0ba7f2: /* original 55d6, guest PC 0x0c0ba7f2 */
if(!s->budget--) { s->failed_pc=0x0c0ba7f2u; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0ba7f4;
P_0c0ba7f4: /* original 9498, guest PC 0x0c0ba7f4 */
if(!s->budget--) { s->failed_pc=0x0c0ba7f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba928u,2);
goto P_0c0ba7f6;
P_0c0ba7f6: /* original 4e0b, guest PC 0x0c0ba7f6 */
if(!s->budget--) { s->failed_pc=0x0c0ba7f6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba7fau;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba7fau) { target=s->pc; goto dispatch; }
goto P_0c0ba7fa;
P_0c0ba7f8: /* original 55d7, guest PC 0x0c0ba7f8 */
if(!s->budget--) { s->failed_pc=0x0c0ba7f8u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0ba7fa;
P_0c0ba7fa: /* original 9496, guest PC 0x0c0ba7fa */
if(!s->budget--) { s->failed_pc=0x0c0ba7fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba92au,2);
goto P_0c0ba7fc;
P_0c0ba7fc: /* original 4e0b, guest PC 0x0c0ba7fc */
if(!s->budget--) { s->failed_pc=0x0c0ba7fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba800u;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba800u) { target=s->pc; goto dispatch; }
goto P_0c0ba800;
P_0c0ba7fe: /* original 55d8, guest PC 0x0c0ba7fe */
if(!s->budget--) { s->failed_pc=0x0c0ba7feu; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0ba800;
P_0c0ba800: /* original 9494, guest PC 0x0c0ba800 */
if(!s->budget--) { s->failed_pc=0x0c0ba800u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba92cu,2);
goto P_0c0ba802;
P_0c0ba802: /* original 4e0b, guest PC 0x0c0ba802 */
if(!s->budget--) { s->failed_pc=0x0c0ba802u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba806u;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba806u) { target=s->pc; goto dispatch; }
goto P_0c0ba806;
P_0c0ba804: /* original 55d9, guest PC 0x0c0ba804 */
if(!s->budget--) { s->failed_pc=0x0c0ba804u; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0ba806;
P_0c0ba806: /* original 9492, guest PC 0x0c0ba806 */
if(!s->budget--) { s->failed_pc=0x0c0ba806u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba92eu,2);
goto P_0c0ba808;
P_0c0ba808: /* original 4e0b, guest PC 0x0c0ba808 */
if(!s->budget--) { s->failed_pc=0x0c0ba808u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba80cu;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba80cu) { target=s->pc; goto dispatch; }
goto P_0c0ba80c;
P_0c0ba80a: /* original 55da, guest PC 0x0c0ba80a */
if(!s->budget--) { s->failed_pc=0x0c0ba80au; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0ba80c;
P_0c0ba80c: /* original 9490, guest PC 0x0c0ba80c */
if(!s->budget--) { s->failed_pc=0x0c0ba80cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba930u,2);
goto P_0c0ba80e;
P_0c0ba80e: /* original 4e0b, guest PC 0x0c0ba80e */
if(!s->budget--) { s->failed_pc=0x0c0ba80eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba812u;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba812u) { target=s->pc; goto dispatch; }
goto P_0c0ba812;
P_0c0ba810: /* original 55db, guest PC 0x0c0ba810 */
if(!s->budget--) { s->failed_pc=0x0c0ba810u; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0ba812;
P_0c0ba812: /* original 948e, guest PC 0x0c0ba812 */
if(!s->budget--) { s->failed_pc=0x0c0ba812u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba932u,2);
goto P_0c0ba814;
P_0c0ba814: /* original 4e0b, guest PC 0x0c0ba814 */
if(!s->budget--) { s->failed_pc=0x0c0ba814u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba818u;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba818u) { target=s->pc; goto dispatch; }
goto P_0c0ba818;
P_0c0ba816: /* original 55dc, guest PC 0x0c0ba816 */
if(!s->budget--) { s->failed_pc=0x0c0ba816u; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0ba818;
P_0c0ba818: /* original 948c, guest PC 0x0c0ba818 */
if(!s->budget--) { s->failed_pc=0x0c0ba818u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba934u,2);
goto P_0c0ba81a;
P_0c0ba81a: /* original 4e0b, guest PC 0x0c0ba81a */
if(!s->budget--) { s->failed_pc=0x0c0ba81au; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba81eu;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba81eu) { target=s->pc; goto dispatch; }
goto P_0c0ba81e;
P_0c0ba81c: /* original 55dd, guest PC 0x0c0ba81c */
if(!s->budget--) { s->failed_pc=0x0c0ba81cu; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0ba81e;
P_0c0ba81e: /* original 948a, guest PC 0x0c0ba81e */
if(!s->budget--) { s->failed_pc=0x0c0ba81eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba936u,2);
goto P_0c0ba820;
P_0c0ba820: /* original 4e0b, guest PC 0x0c0ba820 */
if(!s->budget--) { s->failed_pc=0x0c0ba820u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba824u;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba824u) { target=s->pc; goto dispatch; }
goto P_0c0ba824;
P_0c0ba822: /* original 55de, guest PC 0x0c0ba822 */
if(!s->budget--) { s->failed_pc=0x0c0ba822u; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0ba824;
P_0c0ba824: /* original 9488, guest PC 0x0c0ba824 */
if(!s->budget--) { s->failed_pc=0x0c0ba824u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba938u,2);
goto P_0c0ba826;
P_0c0ba826: /* original 4e0b, guest PC 0x0c0ba826 */
if(!s->budget--) { s->failed_pc=0x0c0ba826u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba82au;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba82au) { target=s->pc; goto dispatch; }
goto P_0c0ba82a;
P_0c0ba828: /* original 55df, guest PC 0x0c0ba828 */
if(!s->budget--) { s->failed_pc=0x0c0ba828u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0ba82a;
P_0c0ba82a: /* original 9486, guest PC 0x0c0ba82a */
if(!s->budget--) { s->failed_pc=0x0c0ba82au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba93au,2);
goto P_0c0ba82c;
P_0c0ba82c: /* original e040, guest PC 0x0c0ba82c */
if(!s->budget--) { s->failed_pc=0x0c0ba82cu; return 0; }
r[0]=0x00000040u;
goto P_0c0ba82e;
P_0c0ba82e: /* original 4e0b, guest PC 0x0c0ba82e */
if(!s->budget--) { s->failed_pc=0x0c0ba82eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba832u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba832u) { target=s->pc; goto dispatch; }
goto P_0c0ba832;
P_0c0ba830: /* original 05de, guest PC 0x0c0ba830 */
if(!s->budget--) { s->failed_pc=0x0c0ba830u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba832;
P_0c0ba832: /* original 9483, guest PC 0x0c0ba832 */
if(!s->budget--) { s->failed_pc=0x0c0ba832u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba93cu,2);
goto P_0c0ba834;
P_0c0ba834: /* original e044, guest PC 0x0c0ba834 */
if(!s->budget--) { s->failed_pc=0x0c0ba834u; return 0; }
r[0]=0x00000044u;
goto P_0c0ba836;
P_0c0ba836: /* original 4e0b, guest PC 0x0c0ba836 */
if(!s->budget--) { s->failed_pc=0x0c0ba836u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba83au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba83au) { target=s->pc; goto dispatch; }
goto P_0c0ba83a;
P_0c0ba838: /* original 05de, guest PC 0x0c0ba838 */
if(!s->budget--) { s->failed_pc=0x0c0ba838u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba83a;
P_0c0ba83a: /* original 9480, guest PC 0x0c0ba83a */
if(!s->budget--) { s->failed_pc=0x0c0ba83au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba93eu,2);
goto P_0c0ba83c;
P_0c0ba83c: /* original e048, guest PC 0x0c0ba83c */
if(!s->budget--) { s->failed_pc=0x0c0ba83cu; return 0; }
r[0]=0x00000048u;
goto P_0c0ba83e;
P_0c0ba83e: /* original 4e0b, guest PC 0x0c0ba83e */
if(!s->budget--) { s->failed_pc=0x0c0ba83eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba842u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba842u) { target=s->pc; goto dispatch; }
goto P_0c0ba842;
P_0c0ba840: /* original 05de, guest PC 0x0c0ba840 */
if(!s->budget--) { s->failed_pc=0x0c0ba840u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba842;
P_0c0ba842: /* original 947d, guest PC 0x0c0ba842 */
if(!s->budget--) { s->failed_pc=0x0c0ba842u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba940u,2);
goto P_0c0ba844;
P_0c0ba844: /* original e04c, guest PC 0x0c0ba844 */
if(!s->budget--) { s->failed_pc=0x0c0ba844u; return 0; }
r[0]=0x0000004cu;
goto P_0c0ba846;
P_0c0ba846: /* original 4e0b, guest PC 0x0c0ba846 */
if(!s->budget--) { s->failed_pc=0x0c0ba846u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba84au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba84au) { target=s->pc; goto dispatch; }
goto P_0c0ba84a;
P_0c0ba848: /* original 05de, guest PC 0x0c0ba848 */
if(!s->budget--) { s->failed_pc=0x0c0ba848u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba84a;
P_0c0ba84a: /* original 947a, guest PC 0x0c0ba84a */
if(!s->budget--) { s->failed_pc=0x0c0ba84au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba942u,2);
goto P_0c0ba84c;
P_0c0ba84c: /* original e050, guest PC 0x0c0ba84c */
if(!s->budget--) { s->failed_pc=0x0c0ba84cu; return 0; }
r[0]=0x00000050u;
goto P_0c0ba84e;
P_0c0ba84e: /* original 4e0b, guest PC 0x0c0ba84e */
if(!s->budget--) { s->failed_pc=0x0c0ba84eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba852u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba852u) { target=s->pc; goto dispatch; }
goto P_0c0ba852;
P_0c0ba850: /* original 05de, guest PC 0x0c0ba850 */
if(!s->budget--) { s->failed_pc=0x0c0ba850u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba852;
P_0c0ba852: /* original 9477, guest PC 0x0c0ba852 */
if(!s->budget--) { s->failed_pc=0x0c0ba852u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba944u,2);
goto P_0c0ba854;
P_0c0ba854: /* original e054, guest PC 0x0c0ba854 */
if(!s->budget--) { s->failed_pc=0x0c0ba854u; return 0; }
r[0]=0x00000054u;
goto P_0c0ba856;
P_0c0ba856: /* original 4e0b, guest PC 0x0c0ba856 */
if(!s->budget--) { s->failed_pc=0x0c0ba856u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba85au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba85au) { target=s->pc; goto dispatch; }
goto P_0c0ba85a;
P_0c0ba858: /* original 05de, guest PC 0x0c0ba858 */
if(!s->budget--) { s->failed_pc=0x0c0ba858u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba85a;
P_0c0ba85a: /* original 9474, guest PC 0x0c0ba85a */
if(!s->budget--) { s->failed_pc=0x0c0ba85au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba946u,2);
goto P_0c0ba85c;
P_0c0ba85c: /* original e058, guest PC 0x0c0ba85c */
if(!s->budget--) { s->failed_pc=0x0c0ba85cu; return 0; }
r[0]=0x00000058u;
goto P_0c0ba85e;
P_0c0ba85e: /* original 4e0b, guest PC 0x0c0ba85e */
if(!s->budget--) { s->failed_pc=0x0c0ba85eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba862u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba862u) { target=s->pc; goto dispatch; }
goto P_0c0ba862;
P_0c0ba860: /* original 05de, guest PC 0x0c0ba860 */
if(!s->budget--) { s->failed_pc=0x0c0ba860u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba862;
P_0c0ba862: /* original 9471, guest PC 0x0c0ba862 */
if(!s->budget--) { s->failed_pc=0x0c0ba862u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba948u,2);
goto P_0c0ba864;
P_0c0ba864: /* original e05c, guest PC 0x0c0ba864 */
if(!s->budget--) { s->failed_pc=0x0c0ba864u; return 0; }
r[0]=0x0000005cu;
goto P_0c0ba866;
P_0c0ba866: /* original 4e0b, guest PC 0x0c0ba866 */
if(!s->budget--) { s->failed_pc=0x0c0ba866u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba86au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba86au) { target=s->pc; goto dispatch; }
goto P_0c0ba86a;
P_0c0ba868: /* original 05de, guest PC 0x0c0ba868 */
if(!s->budget--) { s->failed_pc=0x0c0ba868u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba86a;
P_0c0ba86a: /* original 946e, guest PC 0x0c0ba86a */
if(!s->budget--) { s->failed_pc=0x0c0ba86au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba94au,2);
goto P_0c0ba86c;
P_0c0ba86c: /* original e060, guest PC 0x0c0ba86c */
if(!s->budget--) { s->failed_pc=0x0c0ba86cu; return 0; }
r[0]=0x00000060u;
goto P_0c0ba86e;
P_0c0ba86e: /* original 4e0b, guest PC 0x0c0ba86e */
if(!s->budget--) { s->failed_pc=0x0c0ba86eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba872u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba872u) { target=s->pc; goto dispatch; }
goto P_0c0ba872;
P_0c0ba870: /* original 05de, guest PC 0x0c0ba870 */
if(!s->budget--) { s->failed_pc=0x0c0ba870u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba872;
P_0c0ba872: /* original 946b, guest PC 0x0c0ba872 */
if(!s->budget--) { s->failed_pc=0x0c0ba872u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba94cu,2);
goto P_0c0ba874;
P_0c0ba874: /* original e064, guest PC 0x0c0ba874 */
if(!s->budget--) { s->failed_pc=0x0c0ba874u; return 0; }
r[0]=0x00000064u;
goto P_0c0ba876;
P_0c0ba876: /* original 4e0b, guest PC 0x0c0ba876 */
if(!s->budget--) { s->failed_pc=0x0c0ba876u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba87au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba87au) { target=s->pc; goto dispatch; }
goto P_0c0ba87a;
P_0c0ba878: /* original 05de, guest PC 0x0c0ba878 */
if(!s->budget--) { s->failed_pc=0x0c0ba878u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba87a;
P_0c0ba87a: /* original 9468, guest PC 0x0c0ba87a */
if(!s->budget--) { s->failed_pc=0x0c0ba87au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba94eu,2);
goto P_0c0ba87c;
P_0c0ba87c: /* original e068, guest PC 0x0c0ba87c */
if(!s->budget--) { s->failed_pc=0x0c0ba87cu; return 0; }
r[0]=0x00000068u;
goto P_0c0ba87e;
P_0c0ba87e: /* original 4e0b, guest PC 0x0c0ba87e */
if(!s->budget--) { s->failed_pc=0x0c0ba87eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba882u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba882u) { target=s->pc; goto dispatch; }
goto P_0c0ba882;
P_0c0ba880: /* original 05de, guest PC 0x0c0ba880 */
if(!s->budget--) { s->failed_pc=0x0c0ba880u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba882;
P_0c0ba882: /* original 9465, guest PC 0x0c0ba882 */
if(!s->budget--) { s->failed_pc=0x0c0ba882u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba950u,2);
goto P_0c0ba884;
P_0c0ba884: /* original e06c, guest PC 0x0c0ba884 */
if(!s->budget--) { s->failed_pc=0x0c0ba884u; return 0; }
r[0]=0x0000006cu;
goto P_0c0ba886;
P_0c0ba886: /* original 4e0b, guest PC 0x0c0ba886 */
if(!s->budget--) { s->failed_pc=0x0c0ba886u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba88au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba88au) { target=s->pc; goto dispatch; }
goto P_0c0ba88a;
P_0c0ba888: /* original 05de, guest PC 0x0c0ba888 */
if(!s->budget--) { s->failed_pc=0x0c0ba888u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba88a;
P_0c0ba88a: /* original 9462, guest PC 0x0c0ba88a */
if(!s->budget--) { s->failed_pc=0x0c0ba88au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba952u,2);
goto P_0c0ba88c;
P_0c0ba88c: /* original e070, guest PC 0x0c0ba88c */
if(!s->budget--) { s->failed_pc=0x0c0ba88cu; return 0; }
r[0]=0x00000070u;
goto P_0c0ba88e;
P_0c0ba88e: /* original 4e0b, guest PC 0x0c0ba88e */
if(!s->budget--) { s->failed_pc=0x0c0ba88eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba892u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba892u) { target=s->pc; goto dispatch; }
goto P_0c0ba892;
P_0c0ba890: /* original 05de, guest PC 0x0c0ba890 */
if(!s->budget--) { s->failed_pc=0x0c0ba890u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba892;
P_0c0ba892: /* original 945f, guest PC 0x0c0ba892 */
if(!s->budget--) { s->failed_pc=0x0c0ba892u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba954u,2);
goto P_0c0ba894;
P_0c0ba894: /* original e074, guest PC 0x0c0ba894 */
if(!s->budget--) { s->failed_pc=0x0c0ba894u; return 0; }
r[0]=0x00000074u;
goto P_0c0ba896;
P_0c0ba896: /* original 4e0b, guest PC 0x0c0ba896 */
if(!s->budget--) { s->failed_pc=0x0c0ba896u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba89au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba89au) { target=s->pc; goto dispatch; }
goto P_0c0ba89a;
P_0c0ba898: /* original 05de, guest PC 0x0c0ba898 */
if(!s->budget--) { s->failed_pc=0x0c0ba898u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba89a;
P_0c0ba89a: /* original 945c, guest PC 0x0c0ba89a */
if(!s->budget--) { s->failed_pc=0x0c0ba89au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba956u,2);
goto P_0c0ba89c;
P_0c0ba89c: /* original e078, guest PC 0x0c0ba89c */
if(!s->budget--) { s->failed_pc=0x0c0ba89cu; return 0; }
r[0]=0x00000078u;
goto P_0c0ba89e;
P_0c0ba89e: /* original 4e0b, guest PC 0x0c0ba89e */
if(!s->budget--) { s->failed_pc=0x0c0ba89eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba8a2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba8a2u) { target=s->pc; goto dispatch; }
goto P_0c0ba8a2;
P_0c0ba8a0: /* original 05de, guest PC 0x0c0ba8a0 */
if(!s->budget--) { s->failed_pc=0x0c0ba8a0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba8a2;
P_0c0ba8a2: /* original 9459, guest PC 0x0c0ba8a2 */
if(!s->budget--) { s->failed_pc=0x0c0ba8a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba958u,2);
goto P_0c0ba8a4;
P_0c0ba8a4: /* original e07c, guest PC 0x0c0ba8a4 */
if(!s->budget--) { s->failed_pc=0x0c0ba8a4u; return 0; }
r[0]=0x0000007cu;
goto P_0c0ba8a6;
P_0c0ba8a6: /* original 4e0b, guest PC 0x0c0ba8a6 */
if(!s->budget--) { s->failed_pc=0x0c0ba8a6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba8aau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba8aau) { target=s->pc; goto dispatch; }
goto P_0c0ba8aa;
P_0c0ba8a8: /* original 05de, guest PC 0x0c0ba8a8 */
if(!s->budget--) { s->failed_pc=0x0c0ba8a8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba8aa;
P_0c0ba8aa: /* original 9457, guest PC 0x0c0ba8aa */
if(!s->budget--) { s->failed_pc=0x0c0ba8aau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba95cu,2);
goto P_0c0ba8ac;
P_0c0ba8ac: /* original 9055, guest PC 0x0c0ba8ac */
if(!s->budget--) { s->failed_pc=0x0c0ba8acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba95au,2);
goto P_0c0ba8ae;
P_0c0ba8ae: /* original 4e0b, guest PC 0x0c0ba8ae */
if(!s->budget--) { s->failed_pc=0x0c0ba8aeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba8b2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba8b2u) { target=s->pc; goto dispatch; }
goto P_0c0ba8b2;
P_0c0ba8b0: /* original 05de, guest PC 0x0c0ba8b0 */
if(!s->budget--) { s->failed_pc=0x0c0ba8b0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba8b2;
P_0c0ba8b2: /* original 9554, guest PC 0x0c0ba8b2 */
if(!s->budget--) { s->failed_pc=0x0c0ba8b2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba95eu,2);
goto P_0c0ba8b4;
P_0c0ba8b4: /* original 35dc, guest PC 0x0c0ba8b4 */
if(!s->budget--) { s->failed_pc=0x0c0ba8b4u; return 0; }
r[5]+=r[13];
goto P_0c0ba8b6;
P_0c0ba8b6: /* original 2f52, guest PC 0x0c0ba8b6 */
if(!s->budget--) { s->failed_pc=0x0c0ba8b6u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ba8b8;
P_0c0ba8b8: /* original 9452, guest PC 0x0c0ba8b8 */
if(!s->budget--) { s->failed_pc=0x0c0ba8b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba960u,2);
goto P_0c0ba8ba;
P_0c0ba8ba: /* original 4e0b, guest PC 0x0c0ba8ba */
if(!s->budget--) { s->failed_pc=0x0c0ba8bau; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba8beu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba8beu) { target=s->pc; goto dispatch; }
goto P_0c0ba8be;
P_0c0ba8bc: /* original 6552, guest PC 0x0c0ba8bc */
if(!s->budget--) { s->failed_pc=0x0c0ba8bcu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0ba8be;
P_0c0ba8be: /* original 9550, guest PC 0x0c0ba8be */
if(!s->budget--) { s->failed_pc=0x0c0ba8beu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba962u,2);
goto P_0c0ba8c0;
P_0c0ba8c0: /* original 35dc, guest PC 0x0c0ba8c0 */
if(!s->budget--) { s->failed_pc=0x0c0ba8c0u; return 0; }
r[5]+=r[13];
goto P_0c0ba8c2;
P_0c0ba8c2: /* original 1f51, guest PC 0x0c0ba8c2 */
if(!s->budget--) { s->failed_pc=0x0c0ba8c2u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0ba8c4;
P_0c0ba8c4: /* original 944e, guest PC 0x0c0ba8c4 */
if(!s->budget--) { s->failed_pc=0x0c0ba8c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba964u,2);
goto P_0c0ba8c6;
P_0c0ba8c6: /* original 4e0b, guest PC 0x0c0ba8c6 */
if(!s->budget--) { s->failed_pc=0x0c0ba8c6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba8cau;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba8cau) { target=s->pc; goto dispatch; }
goto P_0c0ba8ca;
P_0c0ba8c8: /* original 6552, guest PC 0x0c0ba8c8 */
if(!s->budget--) { s->failed_pc=0x0c0ba8c8u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0ba8ca;
P_0c0ba8ca: /* original 944d, guest PC 0x0c0ba8ca */
if(!s->budget--) { s->failed_pc=0x0c0ba8cau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba968u,2);
goto P_0c0ba8cc;
P_0c0ba8cc: /* original 904b, guest PC 0x0c0ba8cc */
if(!s->budget--) { s->failed_pc=0x0c0ba8ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba966u,2);
goto P_0c0ba8ce;
P_0c0ba8ce: /* original 4e0b, guest PC 0x0c0ba8ce */
if(!s->budget--) { s->failed_pc=0x0c0ba8ceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba8d2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba8d2u) { target=s->pc; goto dispatch; }
goto P_0c0ba8d2;
P_0c0ba8d0: /* original 05de, guest PC 0x0c0ba8d0 */
if(!s->budget--) { s->failed_pc=0x0c0ba8d0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba8d2;
P_0c0ba8d2: /* original 944b, guest PC 0x0c0ba8d2 */
if(!s->budget--) { s->failed_pc=0x0c0ba8d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba96cu,2);
goto P_0c0ba8d4;
P_0c0ba8d4: /* original 9049, guest PC 0x0c0ba8d4 */
if(!s->budget--) { s->failed_pc=0x0c0ba8d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba96au,2);
goto P_0c0ba8d6;
P_0c0ba8d6: /* original 4e0b, guest PC 0x0c0ba8d6 */
if(!s->budget--) { s->failed_pc=0x0c0ba8d6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba8dau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba8dau) { target=s->pc; goto dispatch; }
goto P_0c0ba8da;
P_0c0ba8d8: /* original 05de, guest PC 0x0c0ba8d8 */
if(!s->budget--) { s->failed_pc=0x0c0ba8d8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba8da;
P_0c0ba8da: /* original 9948, guest PC 0x0c0ba8da */
if(!s->budget--) { s->failed_pc=0x0c0ba8dau; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba96eu,2);
goto P_0c0ba8dc;
P_0c0ba8dc: /* original 9448, guest PC 0x0c0ba8dc */
if(!s->budget--) { s->failed_pc=0x0c0ba8dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba970u,2);
goto P_0c0ba8de;
P_0c0ba8de: /* original 39dc, guest PC 0x0c0ba8de */
if(!s->budget--) { s->failed_pc=0x0c0ba8deu; return 0; }
r[9]+=r[13];
goto P_0c0ba8e0;
P_0c0ba8e0: /* original 4e0b, guest PC 0x0c0ba8e0 */
if(!s->budget--) { s->failed_pc=0x0c0ba8e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba8e4u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba8e4u) { target=s->pc; goto dispatch; }
goto P_0c0ba8e4;
P_0c0ba8e2: /* original 6592, guest PC 0x0c0ba8e2 */
if(!s->budget--) { s->failed_pc=0x0c0ba8e2u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0ba8e4;
P_0c0ba8e4: /* original 9445, guest PC 0x0c0ba8e4 */
if(!s->budget--) { s->failed_pc=0x0c0ba8e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba972u,2);
goto P_0c0ba8e6;
P_0c0ba8e6: /* original 4e0b, guest PC 0x0c0ba8e6 */
if(!s->budget--) { s->failed_pc=0x0c0ba8e6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba8eau;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba8eau) { target=s->pc; goto dispatch; }
goto P_0c0ba8ea;
P_0c0ba8e8: /* original 6592, guest PC 0x0c0ba8e8 */
if(!s->budget--) { s->failed_pc=0x0c0ba8e8u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0ba8ea;
P_0c0ba8ea: /* original 9443, guest PC 0x0c0ba8ea */
if(!s->budget--) { s->failed_pc=0x0c0ba8eau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba974u,2);
goto P_0c0ba8ec;
P_0c0ba8ec: /* original 4e0b, guest PC 0x0c0ba8ec */
if(!s->budget--) { s->failed_pc=0x0c0ba8ecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba8f0u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba8f0u) { target=s->pc; goto dispatch; }
goto P_0c0ba8f0;
P_0c0ba8ee: /* original 6592, guest PC 0x0c0ba8ee */
if(!s->budget--) { s->failed_pc=0x0c0ba8eeu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0ba8f0;
P_0c0ba8f0: /* original 9441, guest PC 0x0c0ba8f0 */
if(!s->budget--) { s->failed_pc=0x0c0ba8f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba976u,2);
goto P_0c0ba8f2;
P_0c0ba8f2: /* original 4e0b, guest PC 0x0c0ba8f2 */
if(!s->budget--) { s->failed_pc=0x0c0ba8f2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba8f6u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba8f6u) { target=s->pc; goto dispatch; }
goto P_0c0ba8f6;
P_0c0ba8f4: /* original 6592, guest PC 0x0c0ba8f4 */
if(!s->budget--) { s->failed_pc=0x0c0ba8f4u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0ba8f6;
P_0c0ba8f6: /* original 9c3f, guest PC 0x0c0ba8f6 */
if(!s->budget--) { s->failed_pc=0x0c0ba8f6u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba978u,2);
goto P_0c0ba8f8;
P_0c0ba8f8: /* original 943f, guest PC 0x0c0ba8f8 */
if(!s->budget--) { s->failed_pc=0x0c0ba8f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba97au,2);
goto P_0c0ba8fa;
P_0c0ba8fa: /* original 3cdc, guest PC 0x0c0ba8fa */
if(!s->budget--) { s->failed_pc=0x0c0ba8fau; return 0; }
r[12]+=r[13];
goto P_0c0ba8fc;
P_0c0ba8fc: /* original 4e0b, guest PC 0x0c0ba8fc */
if(!s->budget--) { s->failed_pc=0x0c0ba8fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba900u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba900u) { target=s->pc; goto dispatch; }
goto P_0c0ba900;
P_0c0ba8fe: /* original 65c2, guest PC 0x0c0ba8fe */
if(!s->budget--) { s->failed_pc=0x0c0ba8feu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0ba900;
P_0c0ba900: /* original 943c, guest PC 0x0c0ba900 */
if(!s->budget--) { s->failed_pc=0x0c0ba900u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba97cu,2);
goto P_0c0ba902;
P_0c0ba902: /* original 4e0b, guest PC 0x0c0ba902 */
if(!s->budget--) { s->failed_pc=0x0c0ba902u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba906u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba906u) { target=s->pc; goto dispatch; }
goto P_0c0ba906;
P_0c0ba904: /* original 65c2, guest PC 0x0c0ba904 */
if(!s->budget--) { s->failed_pc=0x0c0ba904u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0ba906;
P_0c0ba906: /* original 943a, guest PC 0x0c0ba906 */
if(!s->budget--) { s->failed_pc=0x0c0ba906u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba97eu,2);
goto P_0c0ba908;
P_0c0ba908: /* original 4e0b, guest PC 0x0c0ba908 */
if(!s->budget--) { s->failed_pc=0x0c0ba908u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba90cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba90cu) { target=s->pc; goto dispatch; }
goto P_0c0ba90c;
P_0c0ba90a: /* original 65c2, guest PC 0x0c0ba90a */
if(!s->budget--) { s->failed_pc=0x0c0ba90au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0ba90c;
P_0c0ba90c: /* original 9438, guest PC 0x0c0ba90c */
if(!s->budget--) { s->failed_pc=0x0c0ba90cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba980u,2);
goto P_0c0ba90e;
P_0c0ba90e: /* original 4e0b, guest PC 0x0c0ba90e */
if(!s->budget--) { s->failed_pc=0x0c0ba90eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba912u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba912u) { target=s->pc; goto dispatch; }
goto P_0c0ba912;
P_0c0ba910: /* original 65c2, guest PC 0x0c0ba910 */
if(!s->budget--) { s->failed_pc=0x0c0ba910u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0ba912;
P_0c0ba912: /* original 9b36, guest PC 0x0c0ba912 */
if(!s->budget--) { s->failed_pc=0x0c0ba912u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba982u,2);
goto P_0c0ba914;
P_0c0ba914: /* original 3bdc, guest PC 0x0c0ba914 */
if(!s->budget--) { s->failed_pc=0x0c0ba914u; return 0; }
r[11]+=r[13];
goto P_0c0ba916;
P_0c0ba916: /* original a037, guest PC 0x0c0ba916 */
if(!s->budget--) { s->failed_pc=0x0c0ba916u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0ba988;
P_0c0ba918: /* original 65b2, guest PC 0x0c0ba918 */
if(!s->budget--) { s->failed_pc=0x0c0ba918u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0ba91au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ba91au; return 0; } return 1;
P_0c0ba988: /* original 94ab, guest PC 0x0c0ba988 */
if(!s->budget--) { s->failed_pc=0x0c0ba988u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0baae2u,2);
goto P_0c0ba98a;
P_0c0ba98a: /* original 4e0b, guest PC 0x0c0ba98a */
if(!s->budget--) { s->failed_pc=0x0c0ba98au; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba98eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba98eu) { target=s->pc; goto dispatch; }
goto P_0c0ba98e;
P_0c0ba98c: /* original 0009, guest PC 0x0c0ba98c */
if(!s->budget--) { s->failed_pc=0x0c0ba98cu; return 0; }
goto P_0c0ba98e;
P_0c0ba98e: /* original 94a9, guest PC 0x0c0ba98e */
if(!s->budget--) { s->failed_pc=0x0c0ba98eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0baae4u,2);
goto P_0c0ba990;
P_0c0ba990: /* original 4e0b, guest PC 0x0c0ba990 */
if(!s->budget--) { s->failed_pc=0x0c0ba990u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba994u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba994u) { target=s->pc; goto dispatch; }
goto P_0c0ba994;
P_0c0ba992: /* original 65b2, guest PC 0x0c0ba992 */
if(!s->budget--) { s->failed_pc=0x0c0ba992u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0ba994;
P_0c0ba994: /* original 94a7, guest PC 0x0c0ba994 */
if(!s->budget--) { s->failed_pc=0x0c0ba994u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0baae6u,2);
goto P_0c0ba996;
P_0c0ba996: /* original 4e0b, guest PC 0x0c0ba996 */
if(!s->budget--) { s->failed_pc=0x0c0ba996u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba99au;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba99au) { target=s->pc; goto dispatch; }
goto P_0c0ba99a;
P_0c0ba998: /* original 65b2, guest PC 0x0c0ba998 */
if(!s->budget--) { s->failed_pc=0x0c0ba998u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0ba99a;
P_0c0ba99a: /* original 94a5, guest PC 0x0c0ba99a */
if(!s->budget--) { s->failed_pc=0x0c0ba99au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0baae8u,2);
goto P_0c0ba99c;
P_0c0ba99c: /* original 4e0b, guest PC 0x0c0ba99c */
if(!s->budget--) { s->failed_pc=0x0c0ba99cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba9a0u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba9a0u) { target=s->pc; goto dispatch; }
goto P_0c0ba9a0;
P_0c0ba99e: /* original 65b2, guest PC 0x0c0ba99e */
if(!s->budget--) { s->failed_pc=0x0c0ba99eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0ba9a0;
P_0c0ba9a0: /* original 9aa3, guest PC 0x0c0ba9a0 */
if(!s->budget--) { s->failed_pc=0x0c0ba9a0u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0baaeau,2);
goto P_0c0ba9a2;
P_0c0ba9a2: /* original 94a3, guest PC 0x0c0ba9a2 */
if(!s->budget--) { s->failed_pc=0x0c0ba9a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0baaecu,2);
goto P_0c0ba9a4;
P_0c0ba9a4: /* original 3adc, guest PC 0x0c0ba9a4 */
if(!s->budget--) { s->failed_pc=0x0c0ba9a4u; return 0; }
r[10]+=r[13];
goto P_0c0ba9a6;
P_0c0ba9a6: /* original 4e0b, guest PC 0x0c0ba9a6 */
if(!s->budget--) { s->failed_pc=0x0c0ba9a6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba9aau;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba9aau) { target=s->pc; goto dispatch; }
goto P_0c0ba9aa;
P_0c0ba9a8: /* original 65a2, guest PC 0x0c0ba9a8 */
if(!s->budget--) { s->failed_pc=0x0c0ba9a8u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0ba9aa;
P_0c0ba9aa: /* original 94a0, guest PC 0x0c0ba9aa */
if(!s->budget--) { s->failed_pc=0x0c0ba9aau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0baaeeu,2);
goto P_0c0ba9ac;
P_0c0ba9ac: /* original 4e0b, guest PC 0x0c0ba9ac */
if(!s->budget--) { s->failed_pc=0x0c0ba9acu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba9b0u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba9b0u) { target=s->pc; goto dispatch; }
goto P_0c0ba9b0;
P_0c0ba9ae: /* original 65a2, guest PC 0x0c0ba9ae */
if(!s->budget--) { s->failed_pc=0x0c0ba9aeu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0ba9b0;
P_0c0ba9b0: /* original 949e, guest PC 0x0c0ba9b0 */
if(!s->budget--) { s->failed_pc=0x0c0ba9b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0baaf0u,2);
goto P_0c0ba9b2;
P_0c0ba9b2: /* original 4e0b, guest PC 0x0c0ba9b2 */
if(!s->budget--) { s->failed_pc=0x0c0ba9b2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba9b6u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba9b6u) { target=s->pc; goto dispatch; }
goto P_0c0ba9b6;
P_0c0ba9b4: /* original 65a2, guest PC 0x0c0ba9b4 */
if(!s->budget--) { s->failed_pc=0x0c0ba9b4u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0ba9b6;
P_0c0ba9b6: /* original 949c, guest PC 0x0c0ba9b6 */
if(!s->budget--) { s->failed_pc=0x0c0ba9b6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0baaf2u,2);
goto P_0c0ba9b8;
P_0c0ba9b8: /* original 4e0b, guest PC 0x0c0ba9b8 */
if(!s->budget--) { s->failed_pc=0x0c0ba9b8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba9bcu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba9bcu) { target=s->pc; goto dispatch; }
goto P_0c0ba9bc;
P_0c0ba9ba: /* original 65a2, guest PC 0x0c0ba9ba */
if(!s->budget--) { s->failed_pc=0x0c0ba9bau; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0ba9bc;
P_0c0ba9bc: /* original 949a, guest PC 0x0c0ba9bc */
if(!s->budget--) { s->failed_pc=0x0c0ba9bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0baaf4u,2);
goto P_0c0ba9be;
P_0c0ba9be: /* original 65f2, guest PC 0x0c0ba9be */
if(!s->budget--) { s->failed_pc=0x0c0ba9beu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ba9c0;
P_0c0ba9c0: /* original 4e0b, guest PC 0x0c0ba9c0 */
if(!s->budget--) { s->failed_pc=0x0c0ba9c0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba9c4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba9c4u) { target=s->pc; goto dispatch; }
goto P_0c0ba9c4;
P_0c0ba9c2: /* original 6552, guest PC 0x0c0ba9c2 */
if(!s->budget--) { s->failed_pc=0x0c0ba9c2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0ba9c4;
P_0c0ba9c4: /* original 9497, guest PC 0x0c0ba9c4 */
if(!s->budget--) { s->failed_pc=0x0c0ba9c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0baaf6u,2);
goto P_0c0ba9c6;
P_0c0ba9c6: /* original 55f1, guest PC 0x0c0ba9c6 */
if(!s->budget--) { s->failed_pc=0x0c0ba9c6u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0ba9c8;
P_0c0ba9c8: /* original 4e0b, guest PC 0x0c0ba9c8 */
if(!s->budget--) { s->failed_pc=0x0c0ba9c8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba9ccu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba9ccu) { target=s->pc; goto dispatch; }
goto P_0c0ba9cc;
P_0c0ba9ca: /* original 6552, guest PC 0x0c0ba9ca */
if(!s->budget--) { s->failed_pc=0x0c0ba9cau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0ba9cc;
P_0c0ba9cc: /* original 9494, guest PC 0x0c0ba9cc */
if(!s->budget--) { s->failed_pc=0x0c0ba9ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0baaf8u,2);
goto P_0c0ba9ce;
P_0c0ba9ce: /* original 4e0b, guest PC 0x0c0ba9ce */
if(!s->budget--) { s->failed_pc=0x0c0ba9ceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba9d2u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba9d2u) { target=s->pc; goto dispatch; }
goto P_0c0ba9d2;
P_0c0ba9d0: /* original 6592, guest PC 0x0c0ba9d0 */
if(!s->budget--) { s->failed_pc=0x0c0ba9d0u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0ba9d2;
P_0c0ba9d2: /* original 9492, guest PC 0x0c0ba9d2 */
if(!s->budget--) { s->failed_pc=0x0c0ba9d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0baafau,2);
goto P_0c0ba9d4;
P_0c0ba9d4: /* original 4e0b, guest PC 0x0c0ba9d4 */
if(!s->budget--) { s->failed_pc=0x0c0ba9d4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba9d8u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba9d8u) { target=s->pc; goto dispatch; }
goto P_0c0ba9d8;
P_0c0ba9d6: /* original 6592, guest PC 0x0c0ba9d6 */
if(!s->budget--) { s->failed_pc=0x0c0ba9d6u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0ba9d8;
P_0c0ba9d8: /* original 9490, guest PC 0x0c0ba9d8 */
if(!s->budget--) { s->failed_pc=0x0c0ba9d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0baafcu,2);
goto P_0c0ba9da;
P_0c0ba9da: /* original 4e0b, guest PC 0x0c0ba9da */
if(!s->budget--) { s->failed_pc=0x0c0ba9dau; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba9deu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba9deu) { target=s->pc; goto dispatch; }
goto P_0c0ba9de;
P_0c0ba9dc: /* original 6592, guest PC 0x0c0ba9dc */
if(!s->budget--) { s->failed_pc=0x0c0ba9dcu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0ba9de;
P_0c0ba9de: /* original 948e, guest PC 0x0c0ba9de */
if(!s->budget--) { s->failed_pc=0x0c0ba9deu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0baafeu,2);
goto P_0c0ba9e0;
P_0c0ba9e0: /* original 4e0b, guest PC 0x0c0ba9e0 */
if(!s->budget--) { s->failed_pc=0x0c0ba9e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba9e4u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba9e4u) { target=s->pc; goto dispatch; }
goto P_0c0ba9e4;
P_0c0ba9e2: /* original 6592, guest PC 0x0c0ba9e2 */
if(!s->budget--) { s->failed_pc=0x0c0ba9e2u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0ba9e4;
P_0c0ba9e4: /* original 948c, guest PC 0x0c0ba9e4 */
if(!s->budget--) { s->failed_pc=0x0c0ba9e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab00u,2);
goto P_0c0ba9e6;
P_0c0ba9e6: /* original 4e0b, guest PC 0x0c0ba9e6 */
if(!s->budget--) { s->failed_pc=0x0c0ba9e6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba9eau;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba9eau) { target=s->pc; goto dispatch; }
goto P_0c0ba9ea;
P_0c0ba9e8: /* original 65c2, guest PC 0x0c0ba9e8 */
if(!s->budget--) { s->failed_pc=0x0c0ba9e8u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0ba9ea;
P_0c0ba9ea: /* original 948a, guest PC 0x0c0ba9ea */
if(!s->budget--) { s->failed_pc=0x0c0ba9eau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab02u,2);
goto P_0c0ba9ec;
P_0c0ba9ec: /* original 4e0b, guest PC 0x0c0ba9ec */
if(!s->budget--) { s->failed_pc=0x0c0ba9ecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba9f0u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba9f0u) { target=s->pc; goto dispatch; }
goto P_0c0ba9f0;
P_0c0ba9ee: /* original 65c2, guest PC 0x0c0ba9ee */
if(!s->budget--) { s->failed_pc=0x0c0ba9eeu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0ba9f0;
P_0c0ba9f0: /* original 9488, guest PC 0x0c0ba9f0 */
if(!s->budget--) { s->failed_pc=0x0c0ba9f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab04u,2);
goto P_0c0ba9f2;
P_0c0ba9f2: /* original 4e0b, guest PC 0x0c0ba9f2 */
if(!s->budget--) { s->failed_pc=0x0c0ba9f2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba9f6u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba9f6u) { target=s->pc; goto dispatch; }
goto P_0c0ba9f6;
P_0c0ba9f4: /* original 65c2, guest PC 0x0c0ba9f4 */
if(!s->budget--) { s->failed_pc=0x0c0ba9f4u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0ba9f6;
P_0c0ba9f6: /* original 9486, guest PC 0x0c0ba9f6 */
if(!s->budget--) { s->failed_pc=0x0c0ba9f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab06u,2);
goto P_0c0ba9f8;
P_0c0ba9f8: /* original 4e0b, guest PC 0x0c0ba9f8 */
if(!s->budget--) { s->failed_pc=0x0c0ba9f8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba9fcu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba9fcu) { target=s->pc; goto dispatch; }
goto P_0c0ba9fc;
P_0c0ba9fa: /* original 65c2, guest PC 0x0c0ba9fa */
if(!s->budget--) { s->failed_pc=0x0c0ba9fau; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0ba9fc;
P_0c0ba9fc: /* original 9484, guest PC 0x0c0ba9fc */
if(!s->budget--) { s->failed_pc=0x0c0ba9fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab08u,2);
goto P_0c0ba9fe;
P_0c0ba9fe: /* original 4e0b, guest PC 0x0c0ba9fe */
if(!s->budget--) { s->failed_pc=0x0c0ba9feu; return 0; }
target=r[14];
r[16]=code_base|0x0c0baa02u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baa02u) { target=s->pc; goto dispatch; }
goto P_0c0baa02;
P_0c0baa00: /* original 65b2, guest PC 0x0c0baa00 */
if(!s->budget--) { s->failed_pc=0x0c0baa00u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0baa02;
P_0c0baa02: /* original 9482, guest PC 0x0c0baa02 */
if(!s->budget--) { s->failed_pc=0x0c0baa02u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab0au,2);
goto P_0c0baa04;
P_0c0baa04: /* original 4e0b, guest PC 0x0c0baa04 */
if(!s->budget--) { s->failed_pc=0x0c0baa04u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baa08u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baa08u) { target=s->pc; goto dispatch; }
goto P_0c0baa08;
P_0c0baa06: /* original 65b2, guest PC 0x0c0baa06 */
if(!s->budget--) { s->failed_pc=0x0c0baa06u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0baa08;
P_0c0baa08: /* original 9480, guest PC 0x0c0baa08 */
if(!s->budget--) { s->failed_pc=0x0c0baa08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab0cu,2);
goto P_0c0baa0a;
P_0c0baa0a: /* original 4e0b, guest PC 0x0c0baa0a */
if(!s->budget--) { s->failed_pc=0x0c0baa0au; return 0; }
target=r[14];
r[16]=code_base|0x0c0baa0eu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baa0eu) { target=s->pc; goto dispatch; }
goto P_0c0baa0e;
P_0c0baa0c: /* original 65b2, guest PC 0x0c0baa0c */
if(!s->budget--) { s->failed_pc=0x0c0baa0cu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0baa0e;
P_0c0baa0e: /* original 947e, guest PC 0x0c0baa0e */
if(!s->budget--) { s->failed_pc=0x0c0baa0eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab0eu,2);
goto P_0c0baa10;
P_0c0baa10: /* original 4e0b, guest PC 0x0c0baa10 */
if(!s->budget--) { s->failed_pc=0x0c0baa10u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baa14u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baa14u) { target=s->pc; goto dispatch; }
goto P_0c0baa14;
P_0c0baa12: /* original 65b2, guest PC 0x0c0baa12 */
if(!s->budget--) { s->failed_pc=0x0c0baa12u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0baa14;
P_0c0baa14: /* original 947c, guest PC 0x0c0baa14 */
if(!s->budget--) { s->failed_pc=0x0c0baa14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab10u,2);
goto P_0c0baa16;
P_0c0baa16: /* original 4e0b, guest PC 0x0c0baa16 */
if(!s->budget--) { s->failed_pc=0x0c0baa16u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baa1au;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baa1au) { target=s->pc; goto dispatch; }
goto P_0c0baa1a;
P_0c0baa18: /* original 65a2, guest PC 0x0c0baa18 */
if(!s->budget--) { s->failed_pc=0x0c0baa18u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0baa1a;
P_0c0baa1a: /* original 947a, guest PC 0x0c0baa1a */
if(!s->budget--) { s->failed_pc=0x0c0baa1au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab12u,2);
goto P_0c0baa1c;
P_0c0baa1c: /* original 4e0b, guest PC 0x0c0baa1c */
if(!s->budget--) { s->failed_pc=0x0c0baa1cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0baa20u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baa20u) { target=s->pc; goto dispatch; }
goto P_0c0baa20;
P_0c0baa1e: /* original 65a2, guest PC 0x0c0baa1e */
if(!s->budget--) { s->failed_pc=0x0c0baa1eu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0baa20;
P_0c0baa20: /* original 9478, guest PC 0x0c0baa20 */
if(!s->budget--) { s->failed_pc=0x0c0baa20u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab14u,2);
goto P_0c0baa22;
P_0c0baa22: /* original 4e0b, guest PC 0x0c0baa22 */
if(!s->budget--) { s->failed_pc=0x0c0baa22u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baa26u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baa26u) { target=s->pc; goto dispatch; }
goto P_0c0baa26;
P_0c0baa24: /* original 65a2, guest PC 0x0c0baa24 */
if(!s->budget--) { s->failed_pc=0x0c0baa24u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0baa26;
P_0c0baa26: /* original 9476, guest PC 0x0c0baa26 */
if(!s->budget--) { s->failed_pc=0x0c0baa26u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab16u,2);
goto P_0c0baa28;
P_0c0baa28: /* original 4e0b, guest PC 0x0c0baa28 */
if(!s->budget--) { s->failed_pc=0x0c0baa28u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baa2cu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baa2cu) { target=s->pc; goto dispatch; }
goto P_0c0baa2c;
P_0c0baa2a: /* original 65a2, guest PC 0x0c0baa2a */
if(!s->budget--) { s->failed_pc=0x0c0baa2au; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0baa2c;
P_0c0baa2c: /* original 9574, guest PC 0x0c0baa2c */
if(!s->budget--) { s->failed_pc=0x0c0baa2cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab18u,2);
goto P_0c0baa2e;
P_0c0baa2e: /* original 35dc, guest PC 0x0c0baa2e */
if(!s->budget--) { s->failed_pc=0x0c0baa2eu; return 0; }
r[5]+=r[13];
goto P_0c0baa30;
P_0c0baa30: /* original 2f52, guest PC 0x0c0baa30 */
if(!s->budget--) { s->failed_pc=0x0c0baa30u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0baa32;
P_0c0baa32: /* original 9472, guest PC 0x0c0baa32 */
if(!s->budget--) { s->failed_pc=0x0c0baa32u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab1au,2);
goto P_0c0baa34;
P_0c0baa34: /* original 4e0b, guest PC 0x0c0baa34 */
if(!s->budget--) { s->failed_pc=0x0c0baa34u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baa38u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baa38u) { target=s->pc; goto dispatch; }
goto P_0c0baa38;
P_0c0baa36: /* original 6552, guest PC 0x0c0baa36 */
if(!s->budget--) { s->failed_pc=0x0c0baa36u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0baa38;
P_0c0baa38: /* original 9470, guest PC 0x0c0baa38 */
if(!s->budget--) { s->failed_pc=0x0c0baa38u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab1cu,2);
goto P_0c0baa3a;
P_0c0baa3a: /* original 65f2, guest PC 0x0c0baa3a */
if(!s->budget--) { s->failed_pc=0x0c0baa3au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0baa3c;
P_0c0baa3c: /* original 4e0b, guest PC 0x0c0baa3c */
if(!s->budget--) { s->failed_pc=0x0c0baa3cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0baa40u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baa40u) { target=s->pc; goto dispatch; }
goto P_0c0baa40;
P_0c0baa3e: /* original 6552, guest PC 0x0c0baa3e */
if(!s->budget--) { s->failed_pc=0x0c0baa3eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0baa40;
P_0c0baa40: /* original 956d, guest PC 0x0c0baa40 */
if(!s->budget--) { s->failed_pc=0x0c0baa40u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab1eu,2);
goto P_0c0baa42;
P_0c0baa42: /* original 35dc, guest PC 0x0c0baa42 */
if(!s->budget--) { s->failed_pc=0x0c0baa42u; return 0; }
r[5]+=r[13];
goto P_0c0baa44;
P_0c0baa44: /* original 2f52, guest PC 0x0c0baa44 */
if(!s->budget--) { s->failed_pc=0x0c0baa44u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0baa46;
P_0c0baa46: /* original 946b, guest PC 0x0c0baa46 */
if(!s->budget--) { s->failed_pc=0x0c0baa46u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab20u,2);
goto P_0c0baa48;
P_0c0baa48: /* original 4e0b, guest PC 0x0c0baa48 */
if(!s->budget--) { s->failed_pc=0x0c0baa48u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baa4cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baa4cu) { target=s->pc; goto dispatch; }
goto P_0c0baa4c;
P_0c0baa4a: /* original 6552, guest PC 0x0c0baa4a */
if(!s->budget--) { s->failed_pc=0x0c0baa4au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0baa4c;
P_0c0baa4c: /* original 9469, guest PC 0x0c0baa4c */
if(!s->budget--) { s->failed_pc=0x0c0baa4cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab22u,2);
goto P_0c0baa4e;
P_0c0baa4e: /* original 65f2, guest PC 0x0c0baa4e */
if(!s->budget--) { s->failed_pc=0x0c0baa4eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0baa50;
P_0c0baa50: /* original 4e0b, guest PC 0x0c0baa50 */
if(!s->budget--) { s->failed_pc=0x0c0baa50u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baa54u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baa54u) { target=s->pc; goto dispatch; }
goto P_0c0baa54;
P_0c0baa52: /* original 6552, guest PC 0x0c0baa52 */
if(!s->budget--) { s->failed_pc=0x0c0baa52u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0baa54;
P_0c0baa54: /* original 9467, guest PC 0x0c0baa54 */
if(!s->budget--) { s->failed_pc=0x0c0baa54u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab26u,2);
goto P_0c0baa56;
P_0c0baa56: /* original 9065, guest PC 0x0c0baa56 */
if(!s->budget--) { s->failed_pc=0x0c0baa56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab24u,2);
goto P_0c0baa58;
P_0c0baa58: /* original 4e0b, guest PC 0x0c0baa58 */
if(!s->budget--) { s->failed_pc=0x0c0baa58u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baa5cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baa5cu) { target=s->pc; goto dispatch; }
goto P_0c0baa5c;
P_0c0baa5a: /* original 05de, guest PC 0x0c0baa5a */
if(!s->budget--) { s->failed_pc=0x0c0baa5au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0baa5c;
P_0c0baa5c: /* original 9564, guest PC 0x0c0baa5c */
if(!s->budget--) { s->failed_pc=0x0c0baa5cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab28u,2);
goto P_0c0baa5e;
P_0c0baa5e: /* original 35dc, guest PC 0x0c0baa5e */
if(!s->budget--) { s->failed_pc=0x0c0baa5eu; return 0; }
r[5]+=r[13];
goto P_0c0baa60;
P_0c0baa60: /* original 2f52, guest PC 0x0c0baa60 */
if(!s->budget--) { s->failed_pc=0x0c0baa60u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0baa62;
P_0c0baa62: /* original 9462, guest PC 0x0c0baa62 */
if(!s->budget--) { s->failed_pc=0x0c0baa62u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab2au,2);
goto P_0c0baa64;
P_0c0baa64: /* original 4e0b, guest PC 0x0c0baa64 */
if(!s->budget--) { s->failed_pc=0x0c0baa64u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baa68u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baa68u) { target=s->pc; goto dispatch; }
goto P_0c0baa68;
P_0c0baa66: /* original 6552, guest PC 0x0c0baa66 */
if(!s->budget--) { s->failed_pc=0x0c0baa66u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0baa68;
P_0c0baa68: /* original 9460, guest PC 0x0c0baa68 */
if(!s->budget--) { s->failed_pc=0x0c0baa68u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab2cu,2);
goto P_0c0baa6a;
P_0c0baa6a: /* original 65f2, guest PC 0x0c0baa6a */
if(!s->budget--) { s->failed_pc=0x0c0baa6au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0baa6c;
P_0c0baa6c: /* original 4e0b, guest PC 0x0c0baa6c */
if(!s->budget--) { s->failed_pc=0x0c0baa6cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0baa70u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baa70u) { target=s->pc; goto dispatch; }
goto P_0c0baa70;
P_0c0baa6e: /* original 6552, guest PC 0x0c0baa6e */
if(!s->budget--) { s->failed_pc=0x0c0baa6eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0baa70;
P_0c0baa70: /* original 945e, guest PC 0x0c0baa70 */
if(!s->budget--) { s->failed_pc=0x0c0baa70u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab30u,2);
goto P_0c0baa72;
P_0c0baa72: /* original 905c, guest PC 0x0c0baa72 */
if(!s->budget--) { s->failed_pc=0x0c0baa72u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab2eu,2);
goto P_0c0baa74;
P_0c0baa74: /* original 4e0b, guest PC 0x0c0baa74 */
if(!s->budget--) { s->failed_pc=0x0c0baa74u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baa78u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baa78u) { target=s->pc; goto dispatch; }
goto P_0c0baa78;
P_0c0baa76: /* original 05de, guest PC 0x0c0baa76 */
if(!s->budget--) { s->failed_pc=0x0c0baa76u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0baa78;
P_0c0baa78: /* original 955b, guest PC 0x0c0baa78 */
if(!s->budget--) { s->failed_pc=0x0c0baa78u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab32u,2);
goto P_0c0baa7a;
P_0c0baa7a: /* original 35dc, guest PC 0x0c0baa7a */
if(!s->budget--) { s->failed_pc=0x0c0baa7au; return 0; }
r[5]+=r[13];
goto P_0c0baa7c;
P_0c0baa7c: /* original 2f52, guest PC 0x0c0baa7c */
if(!s->budget--) { s->failed_pc=0x0c0baa7cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0baa7e;
P_0c0baa7e: /* original 9459, guest PC 0x0c0baa7e */
if(!s->budget--) { s->failed_pc=0x0c0baa7eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab34u,2);
goto P_0c0baa80;
P_0c0baa80: /* original 4e0b, guest PC 0x0c0baa80 */
if(!s->budget--) { s->failed_pc=0x0c0baa80u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baa84u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baa84u) { target=s->pc; goto dispatch; }
goto P_0c0baa84;
P_0c0baa82: /* original 6552, guest PC 0x0c0baa82 */
if(!s->budget--) { s->failed_pc=0x0c0baa82u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0baa84;
P_0c0baa84: /* original 9457, guest PC 0x0c0baa84 */
if(!s->budget--) { s->failed_pc=0x0c0baa84u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab36u,2);
goto P_0c0baa86;
P_0c0baa86: /* original 65f2, guest PC 0x0c0baa86 */
if(!s->budget--) { s->failed_pc=0x0c0baa86u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0baa88;
P_0c0baa88: /* original 4e0b, guest PC 0x0c0baa88 */
if(!s->budget--) { s->failed_pc=0x0c0baa88u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baa8cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baa8cu) { target=s->pc; goto dispatch; }
goto P_0c0baa8c;
P_0c0baa8a: /* original 6552, guest PC 0x0c0baa8a */
if(!s->budget--) { s->failed_pc=0x0c0baa8au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0baa8c;
P_0c0baa8c: /* original 9455, guest PC 0x0c0baa8c */
if(!s->budget--) { s->failed_pc=0x0c0baa8cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab3au,2);
goto P_0c0baa8e;
P_0c0baa8e: /* original 9053, guest PC 0x0c0baa8e */
if(!s->budget--) { s->failed_pc=0x0c0baa8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab38u,2);
goto P_0c0baa90;
P_0c0baa90: /* original 4e0b, guest PC 0x0c0baa90 */
if(!s->budget--) { s->failed_pc=0x0c0baa90u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baa94u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baa94u) { target=s->pc; goto dispatch; }
goto P_0c0baa94;
P_0c0baa92: /* original 05de, guest PC 0x0c0baa92 */
if(!s->budget--) { s->failed_pc=0x0c0baa92u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0baa94;
P_0c0baa94: /* original 9552, guest PC 0x0c0baa94 */
if(!s->budget--) { s->failed_pc=0x0c0baa94u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab3cu,2);
goto P_0c0baa96;
P_0c0baa96: /* original 35dc, guest PC 0x0c0baa96 */
if(!s->budget--) { s->failed_pc=0x0c0baa96u; return 0; }
r[5]+=r[13];
goto P_0c0baa98;
P_0c0baa98: /* original 2f52, guest PC 0x0c0baa98 */
if(!s->budget--) { s->failed_pc=0x0c0baa98u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0baa9a;
P_0c0baa9a: /* original 9450, guest PC 0x0c0baa9a */
if(!s->budget--) { s->failed_pc=0x0c0baa9au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab3eu,2);
goto P_0c0baa9c;
P_0c0baa9c: /* original 4e0b, guest PC 0x0c0baa9c */
if(!s->budget--) { s->failed_pc=0x0c0baa9cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0baaa0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baaa0u) { target=s->pc; goto dispatch; }
goto P_0c0baaa0;
P_0c0baa9e: /* original 6552, guest PC 0x0c0baa9e */
if(!s->budget--) { s->failed_pc=0x0c0baa9eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0baaa0;
P_0c0baaa0: /* original 944e, guest PC 0x0c0baaa0 */
if(!s->budget--) { s->failed_pc=0x0c0baaa0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab40u,2);
goto P_0c0baaa2;
P_0c0baaa2: /* original 65f2, guest PC 0x0c0baaa2 */
if(!s->budget--) { s->failed_pc=0x0c0baaa2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0baaa4;
P_0c0baaa4: /* original 4e0b, guest PC 0x0c0baaa4 */
if(!s->budget--) { s->failed_pc=0x0c0baaa4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baaa8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baaa8u) { target=s->pc; goto dispatch; }
goto P_0c0baaa8;
P_0c0baaa6: /* original 6552, guest PC 0x0c0baaa6 */
if(!s->budget--) { s->failed_pc=0x0c0baaa6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0baaa8;
P_0c0baaa8: /* original 954b, guest PC 0x0c0baaa8 */
if(!s->budget--) { s->failed_pc=0x0c0baaa8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab42u,2);
goto P_0c0baaaa;
P_0c0baaaa: /* original 35dc, guest PC 0x0c0baaaa */
if(!s->budget--) { s->failed_pc=0x0c0baaaau; return 0; }
r[5]+=r[13];
goto P_0c0baaac;
P_0c0baaac: /* original 2f52, guest PC 0x0c0baaac */
if(!s->budget--) { s->failed_pc=0x0c0baaacu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0baaae;
P_0c0baaae: /* original 9449, guest PC 0x0c0baaae */
if(!s->budget--) { s->failed_pc=0x0c0baaaeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab44u,2);
goto P_0c0baab0;
P_0c0baab0: /* original 4e0b, guest PC 0x0c0baab0 */
if(!s->budget--) { s->failed_pc=0x0c0baab0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baab4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baab4u) { target=s->pc; goto dispatch; }
goto P_0c0baab4;
P_0c0baab2: /* original 6552, guest PC 0x0c0baab2 */
if(!s->budget--) { s->failed_pc=0x0c0baab2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0baab4;
P_0c0baab4: /* original 9447, guest PC 0x0c0baab4 */
if(!s->budget--) { s->failed_pc=0x0c0baab4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab46u,2);
goto P_0c0baab6;
P_0c0baab6: /* original 65f2, guest PC 0x0c0baab6 */
if(!s->budget--) { s->failed_pc=0x0c0baab6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0baab8;
P_0c0baab8: /* original 4e0b, guest PC 0x0c0baab8 */
if(!s->budget--) { s->failed_pc=0x0c0baab8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baabcu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baabcu) { target=s->pc; goto dispatch; }
goto P_0c0baabc;
P_0c0baaba: /* original 6552, guest PC 0x0c0baaba */
if(!s->budget--) { s->failed_pc=0x0c0baabau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0baabc;
P_0c0baabc: /* original 9445, guest PC 0x0c0baabc */
if(!s->budget--) { s->failed_pc=0x0c0baabcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab4au,2);
goto P_0c0baabe;
P_0c0baabe: /* original 9043, guest PC 0x0c0baabe */
if(!s->budget--) { s->failed_pc=0x0c0baabeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab48u,2);
goto P_0c0baac0;
P_0c0baac0: /* original 4e0b, guest PC 0x0c0baac0 */
if(!s->budget--) { s->failed_pc=0x0c0baac0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baac4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baac4u) { target=s->pc; goto dispatch; }
goto P_0c0baac4;
P_0c0baac2: /* original 05de, guest PC 0x0c0baac2 */
if(!s->budget--) { s->failed_pc=0x0c0baac2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0baac4;
P_0c0baac4: /* original 9443, guest PC 0x0c0baac4 */
if(!s->budget--) { s->failed_pc=0x0c0baac4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab4eu,2);
goto P_0c0baac6;
P_0c0baac6: /* original 9041, guest PC 0x0c0baac6 */
if(!s->budget--) { s->failed_pc=0x0c0baac6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab4cu,2);
goto P_0c0baac8;
P_0c0baac8: /* original 4e0b, guest PC 0x0c0baac8 */
if(!s->budget--) { s->failed_pc=0x0c0baac8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baaccu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baaccu) { target=s->pc; goto dispatch; }
goto P_0c0baacc;
P_0c0baaca: /* original 05de, guest PC 0x0c0baaca */
if(!s->budget--) { s->failed_pc=0x0c0baacau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0baacc;
P_0c0baacc: /* original 9441, guest PC 0x0c0baacc */
if(!s->budget--) { s->failed_pc=0x0c0baaccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab52u,2);
goto P_0c0baace;
P_0c0baace: /* original 903f, guest PC 0x0c0baace */
if(!s->budget--) { s->failed_pc=0x0c0baaceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab50u,2);
goto P_0c0baad0;
P_0c0baad0: /* original 4e0b, guest PC 0x0c0baad0 */
if(!s->budget--) { s->failed_pc=0x0c0baad0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baad4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baad4u) { target=s->pc; goto dispatch; }
goto P_0c0baad4;
P_0c0baad2: /* original 05de, guest PC 0x0c0baad2 */
if(!s->budget--) { s->failed_pc=0x0c0baad2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0baad4;
P_0c0baad4: /* original 943f, guest PC 0x0c0baad4 */
if(!s->budget--) { s->failed_pc=0x0c0baad4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab56u,2);
goto P_0c0baad6;
P_0c0baad6: /* original 903d, guest PC 0x0c0baad6 */
if(!s->budget--) { s->failed_pc=0x0c0baad6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab54u,2);
goto P_0c0baad8;
P_0c0baad8: /* original 4e0b, guest PC 0x0c0baad8 */
if(!s->budget--) { s->failed_pc=0x0c0baad8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baadcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baadcu) { target=s->pc; goto dispatch; }
goto P_0c0baadc;
P_0c0baada: /* original 05de, guest PC 0x0c0baada */
if(!s->budget--) { s->failed_pc=0x0c0baadau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0baadc;
P_0c0baadc: /* original 903c, guest PC 0x0c0baadc */
if(!s->budget--) { s->failed_pc=0x0c0baadcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bab58u,2);
goto P_0c0baade;
P_0c0baade: /* original a03c, guest PC 0x0c0baade */
if(!s->budget--) { s->failed_pc=0x0c0baadeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bab5a;
P_0c0baae0: /* original 05de, guest PC 0x0c0baae0 */
if(!s->budget--) { s->failed_pc=0x0c0baae0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0baae2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0baae2u; return 0; } return 1;
P_0c0bab5a: /* original 942e, guest PC 0x0c0bab5a */
if(!s->budget--) { s->failed_pc=0x0c0bab5au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0babbau,2);
goto P_0c0bab5c;
P_0c0bab5c: /* original 4e0b, guest PC 0x0c0bab5c */
if(!s->budget--) { s->failed_pc=0x0c0bab5cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bab60u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bab60u) { target=s->pc; goto dispatch; }
goto P_0c0bab60;
P_0c0bab5e: /* original 0009, guest PC 0x0c0bab5e */
if(!s->budget--) { s->failed_pc=0x0c0bab5eu; return 0; }
goto P_0c0bab60;
P_0c0bab60: /* original 942d, guest PC 0x0c0bab60 */
if(!s->budget--) { s->failed_pc=0x0c0bab60u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0babbeu,2);
goto P_0c0bab62;
P_0c0bab62: /* original 902b, guest PC 0x0c0bab62 */
if(!s->budget--) { s->failed_pc=0x0c0bab62u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0babbcu,2);
goto P_0c0bab64;
P_0c0bab64: /* original 4e0b, guest PC 0x0c0bab64 */
if(!s->budget--) { s->failed_pc=0x0c0bab64u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bab68u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bab68u) { target=s->pc; goto dispatch; }
goto P_0c0bab68;
P_0c0bab66: /* original 05de, guest PC 0x0c0bab66 */
if(!s->budget--) { s->failed_pc=0x0c0bab66u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bab68;
P_0c0bab68: /* original 942b, guest PC 0x0c0bab68 */
if(!s->budget--) { s->failed_pc=0x0c0bab68u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0babc2u,2);
goto P_0c0bab6a;
P_0c0bab6a: /* original 9029, guest PC 0x0c0bab6a */
if(!s->budget--) { s->failed_pc=0x0c0bab6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0babc0u,2);
goto P_0c0bab6c;
P_0c0bab6c: /* original 4e0b, guest PC 0x0c0bab6c */
if(!s->budget--) { s->failed_pc=0x0c0bab6cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bab70u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bab70u) { target=s->pc; goto dispatch; }
goto P_0c0bab70;
P_0c0bab6e: /* original 05de, guest PC 0x0c0bab6e */
if(!s->budget--) { s->failed_pc=0x0c0bab6eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bab70;
P_0c0bab70: /* original 9429, guest PC 0x0c0bab70 */
if(!s->budget--) { s->failed_pc=0x0c0bab70u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0babc6u,2);
goto P_0c0bab72;
P_0c0bab72: /* original 9027, guest PC 0x0c0bab72 */
if(!s->budget--) { s->failed_pc=0x0c0bab72u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0babc4u,2);
goto P_0c0bab74;
P_0c0bab74: /* original 4e0b, guest PC 0x0c0bab74 */
if(!s->budget--) { s->failed_pc=0x0c0bab74u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bab78u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bab78u) { target=s->pc; goto dispatch; }
goto P_0c0bab78;
P_0c0bab76: /* original 05de, guest PC 0x0c0bab76 */
if(!s->budget--) { s->failed_pc=0x0c0bab76u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bab78;
P_0c0bab78: /* original 9427, guest PC 0x0c0bab78 */
if(!s->budget--) { s->failed_pc=0x0c0bab78u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0babcau,2);
goto P_0c0bab7a;
P_0c0bab7a: /* original 9025, guest PC 0x0c0bab7a */
if(!s->budget--) { s->failed_pc=0x0c0bab7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0babc8u,2);
goto P_0c0bab7c;
P_0c0bab7c: /* original 4e0b, guest PC 0x0c0bab7c */
if(!s->budget--) { s->failed_pc=0x0c0bab7cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bab80u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bab80u) { target=s->pc; goto dispatch; }
goto P_0c0bab80;
P_0c0bab7e: /* original 05de, guest PC 0x0c0bab7e */
if(!s->budget--) { s->failed_pc=0x0c0bab7eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bab80;
P_0c0bab80: /* original 9425, guest PC 0x0c0bab80 */
if(!s->budget--) { s->failed_pc=0x0c0bab80u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0babceu,2);
goto P_0c0bab82;
P_0c0bab82: /* original 9023, guest PC 0x0c0bab82 */
if(!s->budget--) { s->failed_pc=0x0c0bab82u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0babccu,2);
goto P_0c0bab84;
P_0c0bab84: /* original 4e0b, guest PC 0x0c0bab84 */
if(!s->budget--) { s->failed_pc=0x0c0bab84u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bab88u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bab88u) { target=s->pc; goto dispatch; }
goto P_0c0bab88;
P_0c0bab86: /* original 05de, guest PC 0x0c0bab86 */
if(!s->budget--) { s->failed_pc=0x0c0bab86u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bab88;
P_0c0bab88: /* original 9423, guest PC 0x0c0bab88 */
if(!s->budget--) { s->failed_pc=0x0c0bab88u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0babd2u,2);
goto P_0c0bab8a;
P_0c0bab8a: /* original 9021, guest PC 0x0c0bab8a */
if(!s->budget--) { s->failed_pc=0x0c0bab8au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0babd0u,2);
goto P_0c0bab8c;
P_0c0bab8c: /* original 4e0b, guest PC 0x0c0bab8c */
if(!s->budget--) { s->failed_pc=0x0c0bab8cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bab90u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bab90u) { target=s->pc; goto dispatch; }
goto P_0c0bab90;
P_0c0bab8e: /* original 05de, guest PC 0x0c0bab8e */
if(!s->budget--) { s->failed_pc=0x0c0bab8eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bab90;
P_0c0bab90: /* original 9421, guest PC 0x0c0bab90 */
if(!s->budget--) { s->failed_pc=0x0c0bab90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0babd6u,2);
goto P_0c0bab92;
P_0c0bab92: /* original 901f, guest PC 0x0c0bab92 */
if(!s->budget--) { s->failed_pc=0x0c0bab92u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0babd4u,2);
goto P_0c0bab94;
P_0c0bab94: /* original 4e0b, guest PC 0x0c0bab94 */
if(!s->budget--) { s->failed_pc=0x0c0bab94u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bab98u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bab98u) { target=s->pc; goto dispatch; }
goto P_0c0bab98;
P_0c0bab96: /* original 05de, guest PC 0x0c0bab96 */
if(!s->budget--) { s->failed_pc=0x0c0bab96u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bab98;
P_0c0bab98: /* original 941f, guest PC 0x0c0bab98 */
if(!s->budget--) { s->failed_pc=0x0c0bab98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0babdau,2);
goto P_0c0bab9a;
P_0c0bab9a: /* original 901d, guest PC 0x0c0bab9a */
if(!s->budget--) { s->failed_pc=0x0c0bab9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0babd8u,2);
goto P_0c0bab9c;
P_0c0bab9c: /* original 4e0b, guest PC 0x0c0bab9c */
if(!s->budget--) { s->failed_pc=0x0c0bab9cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0baba0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baba0u) { target=s->pc; goto dispatch; }
goto P_0c0baba0;
P_0c0bab9e: /* original 05de, guest PC 0x0c0bab9e */
if(!s->budget--) { s->failed_pc=0x0c0bab9eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0baba0;
P_0c0baba0: /* original 941d, guest PC 0x0c0baba0 */
if(!s->budget--) { s->failed_pc=0x0c0baba0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0babdeu,2);
goto P_0c0baba2;
P_0c0baba2: /* original 901b, guest PC 0x0c0baba2 */
if(!s->budget--) { s->failed_pc=0x0c0baba2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0babdcu,2);
goto P_0c0baba4;
P_0c0baba4: /* original 4e0b, guest PC 0x0c0baba4 */
if(!s->budget--) { s->failed_pc=0x0c0baba4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baba8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baba8u) { target=s->pc; goto dispatch; }
goto P_0c0baba8;
P_0c0baba6: /* original 05de, guest PC 0x0c0baba6 */
if(!s->budget--) { s->failed_pc=0x0c0baba6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0baba8;
P_0c0baba8: /* original 7f08, guest PC 0x0c0baba8 */
if(!s->budget--) { s->failed_pc=0x0c0baba8u; return 0; }
r[15]+=0x00000008u;
goto P_0c0babaa;
P_0c0babaa: /* original 4f26, guest PC 0x0c0babaa */
if(!s->budget--) { s->failed_pc=0x0c0babaau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0babac;
P_0c0babac: /* original 69f6, guest PC 0x0c0babac */
if(!s->budget--) { s->failed_pc=0x0c0babacu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0babae;
P_0c0babae: /* original 6af6, guest PC 0x0c0babae */
if(!s->budget--) { s->failed_pc=0x0c0babaeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0babb0;
P_0c0babb0: /* original 6bf6, guest PC 0x0c0babb0 */
if(!s->budget--) { s->failed_pc=0x0c0babb0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0babb2;
P_0c0babb2: /* original 6cf6, guest PC 0x0c0babb2 */
if(!s->budget--) { s->failed_pc=0x0c0babb2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0babb4;
P_0c0babb4: /* original 6df6, guest PC 0x0c0babb4 */
if(!s->budget--) { s->failed_pc=0x0c0babb4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0babb6;
P_0c0babb6: /* original 000b, guest PC 0x0c0babb6 */
if(!s->budget--) { s->failed_pc=0x0c0babb6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0babb8: /* original 6ef6, guest PC 0x0c0babb8 */
if(!s->budget--) { s->failed_pc=0x0c0babb8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0babbau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0babbau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
