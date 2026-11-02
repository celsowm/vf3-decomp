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
int vf3_away_batch10_adapter_16(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06c7e4u: goto P_0c06c7e4;
case 0x0c06c7e6u: goto P_0c06c7e6;
case 0x0c06c7e8u: goto P_0c06c7e8;
case 0x0c06c7eau: goto P_0c06c7ea;
case 0x0c06c7ecu: goto P_0c06c7ec;
case 0x0c06c7eeu: goto P_0c06c7ee;
case 0x0c06c7f0u: goto P_0c06c7f0;
case 0x0c06c7f2u: goto P_0c06c7f2;
case 0x0c06c7f4u: goto P_0c06c7f4;
case 0x0c06c7f6u: goto P_0c06c7f6;
case 0x0c06c7f8u: goto P_0c06c7f8;
case 0x0c06c7fau: goto P_0c06c7fa;
case 0x0c06c7fcu: goto P_0c06c7fc;
case 0x0c06c7feu: goto P_0c06c7fe;
case 0x0c06c800u: goto P_0c06c800;
case 0x0c06c802u: goto P_0c06c802;
case 0x0c06c804u: goto P_0c06c804;
case 0x0c06c806u: goto P_0c06c806;
case 0x0c06c808u: goto P_0c06c808;
case 0x0c06c80au: goto P_0c06c80a;
case 0x0c06c80cu: goto P_0c06c80c;
case 0x0c06c80eu: goto P_0c06c80e;
case 0x0c06c810u: goto P_0c06c810;
case 0x0c06c812u: goto P_0c06c812;
case 0x0c06c814u: goto P_0c06c814;
case 0x0c06c816u: goto P_0c06c816;
case 0x0c06c818u: goto P_0c06c818;
case 0x0c06c81au: goto P_0c06c81a;
case 0x0c06c81cu: goto P_0c06c81c;
case 0x0c06c81eu: goto P_0c06c81e;
case 0x0c06c820u: goto P_0c06c820;
case 0x0c06c822u: goto P_0c06c822;
case 0x0c06c824u: goto P_0c06c824;
case 0x0c06c826u: goto P_0c06c826;
case 0x0c06c828u: goto P_0c06c828;
case 0x0c06c82au: goto P_0c06c82a;
case 0x0c06c82cu: goto P_0c06c82c;
case 0x0c06c82eu: goto P_0c06c82e;
case 0x0c06c830u: goto P_0c06c830;
case 0x0c06c832u: goto P_0c06c832;
case 0x0c06c834u: goto P_0c06c834;
case 0x0c06c836u: goto P_0c06c836;
case 0x0c06c838u: goto P_0c06c838;
case 0x0c06c83au: goto P_0c06c83a;
case 0x0c06c83cu: goto P_0c06c83c;
case 0x0c06c83eu: goto P_0c06c83e;
case 0x0c06c840u: goto P_0c06c840;
case 0x0c06c842u: goto P_0c06c842;
case 0x0c06c844u: goto P_0c06c844;
case 0x0c06c846u: goto P_0c06c846;
case 0x0c06c848u: goto P_0c06c848;
case 0x0c06c84au: goto P_0c06c84a;
case 0x0c06c84cu: goto P_0c06c84c;
case 0x0c06c84eu: goto P_0c06c84e;
case 0x0c06c850u: goto P_0c06c850;
case 0x0c06c852u: goto P_0c06c852;
case 0x0c06c854u: goto P_0c06c854;
case 0x0c06c856u: goto P_0c06c856;
case 0x0c06c858u: goto P_0c06c858;
case 0x0c06c85au: goto P_0c06c85a;
case 0x0c06c85cu: goto P_0c06c85c;
case 0x0c06c85eu: goto P_0c06c85e;
case 0x0c06c860u: goto P_0c06c860;
case 0x0c06c862u: goto P_0c06c862;
case 0x0c06c864u: goto P_0c06c864;
case 0x0c06c866u: goto P_0c06c866;
case 0x0c06c868u: goto P_0c06c868;
case 0x0c06c86au: goto P_0c06c86a;
case 0x0c06c86cu: goto P_0c06c86c;
case 0x0c06c86eu: goto P_0c06c86e;
case 0x0c06c870u: goto P_0c06c870;
case 0x0c06c872u: goto P_0c06c872;
case 0x0c06c874u: goto P_0c06c874;
case 0x0c06c876u: goto P_0c06c876;
case 0x0c06c878u: goto P_0c06c878;
case 0x0c06c87au: goto P_0c06c87a;
case 0x0c06c87cu: goto P_0c06c87c;
case 0x0c06c87eu: goto P_0c06c87e;
case 0x0c06c880u: goto P_0c06c880;
case 0x0c06c882u: goto P_0c06c882;
case 0x0c06c884u: goto P_0c06c884;
case 0x0c06c886u: goto P_0c06c886;
case 0x0c06c888u: goto P_0c06c888;
case 0x0c06c88au: goto P_0c06c88a;
case 0x0c06c88cu: goto P_0c06c88c;
case 0x0c06c88eu: goto P_0c06c88e;
case 0x0c06c890u: goto P_0c06c890;
case 0x0c06c892u: goto P_0c06c892;
case 0x0c06c894u: goto P_0c06c894;
case 0x0c06c896u: goto P_0c06c896;
case 0x0c06c898u: goto P_0c06c898;
case 0x0c06c89au: goto P_0c06c89a;
case 0x0c06c89cu: goto P_0c06c89c;
case 0x0c06c89eu: goto P_0c06c89e;
case 0x0c06c8a0u: goto P_0c06c8a0;
case 0x0c06c8a2u: goto P_0c06c8a2;
case 0x0c06c8a4u: goto P_0c06c8a4;
case 0x0c06c8a6u: goto P_0c06c8a6;
case 0x0c06c8a8u: goto P_0c06c8a8;
case 0x0c06c8aau: goto P_0c06c8aa;
case 0x0c06c8acu: goto P_0c06c8ac;
case 0x0c06c8aeu: goto P_0c06c8ae;
case 0x0c06c8b0u: goto P_0c06c8b0;
case 0x0c06c8b2u: goto P_0c06c8b2;
case 0x0c06c8b4u: goto P_0c06c8b4;
case 0x0c06c8b6u: goto P_0c06c8b6;
case 0x0c06c8b8u: goto P_0c06c8b8;
case 0x0c06c8bau: goto P_0c06c8ba;
case 0x0c06c8bcu: goto P_0c06c8bc;
case 0x0c06c8beu: goto P_0c06c8be;
case 0x0c06c8c0u: goto P_0c06c8c0;
case 0x0c06c8c2u: goto P_0c06c8c2;
case 0x0c06c8c4u: goto P_0c06c8c4;
case 0x0c06c8c6u: goto P_0c06c8c6;
case 0x0c06c8c8u: goto P_0c06c8c8;
case 0x0c06c8cau: goto P_0c06c8ca;
case 0x0c06c8ccu: goto P_0c06c8cc;
case 0x0c06c8ceu: goto P_0c06c8ce;
case 0x0c06c8d0u: goto P_0c06c8d0;
case 0x0c06c8d2u: goto P_0c06c8d2;
case 0x0c06c8d4u: goto P_0c06c8d4;
case 0x0c06c8d6u: goto P_0c06c8d6;
case 0x0c06c8d8u: goto P_0c06c8d8;
case 0x0c06c8dau: goto P_0c06c8da;
case 0x0c06c8dcu: goto P_0c06c8dc;
case 0x0c06c8deu: goto P_0c06c8de;
case 0x0c06c8e0u: goto P_0c06c8e0;
case 0x0c06c8e2u: goto P_0c06c8e2;
case 0x0c06c8e4u: goto P_0c06c8e4;
case 0x0c06c8e6u: goto P_0c06c8e6;
case 0x0c06c8e8u: goto P_0c06c8e8;
case 0x0c06c8eau: goto P_0c06c8ea;
case 0x0c06c8ecu: goto P_0c06c8ec;
case 0x0c06c8eeu: goto P_0c06c8ee;
case 0x0c06c8f0u: goto P_0c06c8f0;
case 0x0c06c8f2u: goto P_0c06c8f2;
case 0x0c06c8f4u: goto P_0c06c8f4;
case 0x0c06c914u: goto P_0c06c914;
case 0x0c06c916u: goto P_0c06c916;
case 0x0c06c918u: goto P_0c06c918;
case 0x0c06c91au: goto P_0c06c91a;
case 0x0c06c91cu: goto P_0c06c91c;
case 0x0c06c91eu: goto P_0c06c91e;
case 0x0c06c920u: goto P_0c06c920;
case 0x0c06c922u: goto P_0c06c922;
case 0x0c06c924u: goto P_0c06c924;
case 0x0c06c926u: goto P_0c06c926;
case 0x0c06c928u: goto P_0c06c928;
case 0x0c06c92au: goto P_0c06c92a;
case 0x0c06c92cu: goto P_0c06c92c;
case 0x0c06c92eu: goto P_0c06c92e;
case 0x0c06c930u: goto P_0c06c930;
case 0x0c06c932u: goto P_0c06c932;
case 0x0c06c934u: goto P_0c06c934;
case 0x0c06c936u: goto P_0c06c936;
case 0x0c06c938u: goto P_0c06c938;
case 0x0c06c93au: goto P_0c06c93a;
case 0x0c06c93cu: goto P_0c06c93c;
case 0x0c06c93eu: goto P_0c06c93e;
case 0x0c06c940u: goto P_0c06c940;
case 0x0c06c942u: goto P_0c06c942;
case 0x0c06c944u: goto P_0c06c944;
case 0x0c06c946u: goto P_0c06c946;
case 0x0c06c948u: goto P_0c06c948;
case 0x0c06c94au: goto P_0c06c94a;
case 0x0c06c94cu: goto P_0c06c94c;
case 0x0c06c94eu: goto P_0c06c94e;
case 0x0c06c950u: goto P_0c06c950;
case 0x0c06c952u: goto P_0c06c952;
case 0x0c06c954u: goto P_0c06c954;
case 0x0c06c956u: goto P_0c06c956;
case 0x0c06c958u: goto P_0c06c958;
case 0x0c06c95au: goto P_0c06c95a;
case 0x0c06c95cu: goto P_0c06c95c;
case 0x0c06c95eu: goto P_0c06c95e;
case 0x0c06c960u: goto P_0c06c960;
case 0x0c06c962u: goto P_0c06c962;
case 0x0c06c964u: goto P_0c06c964;
case 0x0c06c966u: goto P_0c06c966;
case 0x0c06c968u: goto P_0c06c968;
case 0x0c06c96au: goto P_0c06c96a;
case 0x0c06c96cu: goto P_0c06c96c;
case 0x0c06c96eu: goto P_0c06c96e;
case 0x0c06c970u: goto P_0c06c970;
case 0x0c06c972u: goto P_0c06c972;
case 0x0c06c974u: goto P_0c06c974;
case 0x0c06c976u: goto P_0c06c976;
case 0x0c06c978u: goto P_0c06c978;
case 0x0c06c97au: goto P_0c06c97a;
case 0x0c06c97cu: goto P_0c06c97c;
case 0x0c06c97eu: goto P_0c06c97e;
case 0x0c06c980u: goto P_0c06c980;
case 0x0c06c982u: goto P_0c06c982;
case 0x0c06c984u: goto P_0c06c984;
case 0x0c06c986u: goto P_0c06c986;
case 0x0c06c988u: goto P_0c06c988;
case 0x0c06c98au: goto P_0c06c98a;
case 0x0c06c98cu: goto P_0c06c98c;
case 0x0c06c98eu: goto P_0c06c98e;
case 0x0c06c990u: goto P_0c06c990;
case 0x0c06c992u: goto P_0c06c992;
case 0x0c06c994u: goto P_0c06c994;
case 0x0c06c996u: goto P_0c06c996;
case 0x0c06c998u: goto P_0c06c998;
case 0x0c06c99au: goto P_0c06c99a;
case 0x0c06c99cu: goto P_0c06c99c;
case 0x0c06c99eu: goto P_0c06c99e;
case 0x0c06c9a0u: goto P_0c06c9a0;
case 0x0c06c9a2u: goto P_0c06c9a2;
case 0x0c06c9a4u: goto P_0c06c9a4;
case 0x0c06c9a6u: goto P_0c06c9a6;
case 0x0c06c9a8u: goto P_0c06c9a8;
case 0x0c06c9aau: goto P_0c06c9aa;
case 0x0c06c9acu: goto P_0c06c9ac;
case 0x0c06c9aeu: goto P_0c06c9ae;
case 0x0c06c9b0u: goto P_0c06c9b0;
case 0x0c06c9b2u: goto P_0c06c9b2;
case 0x0c06c9b4u: goto P_0c06c9b4;
case 0x0c06c9b6u: goto P_0c06c9b6;
case 0x0c06c9b8u: goto P_0c06c9b8;
case 0x0c06c9bau: goto P_0c06c9ba;
case 0x0c06c9bcu: goto P_0c06c9bc;
case 0x0c06c9beu: goto P_0c06c9be;
case 0x0c06c9c0u: goto P_0c06c9c0;
case 0x0c06c9c2u: goto P_0c06c9c2;
case 0x0c06c9c4u: goto P_0c06c9c4;
case 0x0c06c9c6u: goto P_0c06c9c6;
case 0x0c06c9c8u: goto P_0c06c9c8;
case 0x0c06c9cau: goto P_0c06c9ca;
case 0x0c06c9ccu: goto P_0c06c9cc;
case 0x0c06c9ceu: goto P_0c06c9ce;
case 0x0c06c9d0u: goto P_0c06c9d0;
case 0x0c06c9d2u: goto P_0c06c9d2;
case 0x0c06c9d4u: goto P_0c06c9d4;
case 0x0c06c9d6u: goto P_0c06c9d6;
case 0x0c06c9d8u: goto P_0c06c9d8;
case 0x0c06c9dau: goto P_0c06c9da;
case 0x0c06c9dcu: goto P_0c06c9dc;
case 0x0c06c9deu: goto P_0c06c9de;
case 0x0c06c9e0u: goto P_0c06c9e0;
case 0x0c06c9e2u: goto P_0c06c9e2;
case 0x0c06c9e4u: goto P_0c06c9e4;
case 0x0c06c9e6u: goto P_0c06c9e6;
case 0x0c06c9e8u: goto P_0c06c9e8;
case 0x0c06c9eau: goto P_0c06c9ea;
case 0x0c06c9ecu: goto P_0c06c9ec;
case 0x0c06c9eeu: goto P_0c06c9ee;
case 0x0c06c9f0u: goto P_0c06c9f0;
case 0x0c06c9f2u: goto P_0c06c9f2;
case 0x0c06c9f4u: goto P_0c06c9f4;
case 0x0c06c9f6u: goto P_0c06c9f6;
case 0x0c06ca30u: goto P_0c06ca30;
case 0x0c06ca32u: goto P_0c06ca32;
case 0x0c06ca34u: goto P_0c06ca34;
case 0x0c06ca36u: goto P_0c06ca36;
case 0x0c06ca38u: goto P_0c06ca38;
case 0x0c06ca3au: goto P_0c06ca3a;
case 0x0c06ca3cu: goto P_0c06ca3c;
case 0x0c06ca3eu: goto P_0c06ca3e;
case 0x0c06ca40u: goto P_0c06ca40;
case 0x0c06ca42u: goto P_0c06ca42;
case 0x0c06ca44u: goto P_0c06ca44;
case 0x0c06ca46u: goto P_0c06ca46;
case 0x0c06ca48u: goto P_0c06ca48;
case 0x0c06ca4au: goto P_0c06ca4a;
case 0x0c06ca4cu: goto P_0c06ca4c;
case 0x0c06ca4eu: goto P_0c06ca4e;
case 0x0c06ca50u: goto P_0c06ca50;
case 0x0c06ca52u: goto P_0c06ca52;
case 0x0c06ca54u: goto P_0c06ca54;
case 0x0c06ca56u: goto P_0c06ca56;
case 0x0c06ca58u: goto P_0c06ca58;
case 0x0c06ca5au: goto P_0c06ca5a;
case 0x0c06ca5cu: goto P_0c06ca5c;
case 0x0c06ca5eu: goto P_0c06ca5e;
case 0x0c06ca60u: goto P_0c06ca60;
case 0x0c06ca62u: goto P_0c06ca62;
case 0x0c06ca64u: goto P_0c06ca64;
case 0x0c06ca66u: goto P_0c06ca66;
case 0x0c06ca68u: goto P_0c06ca68;
case 0x0c06ca6au: goto P_0c06ca6a;
case 0x0c06ca6cu: goto P_0c06ca6c;
case 0x0c06ca6eu: goto P_0c06ca6e;
case 0x0c06ca70u: goto P_0c06ca70;
case 0x0c06ca72u: goto P_0c06ca72;
case 0x0c06ca74u: goto P_0c06ca74;
case 0x0c06ca76u: goto P_0c06ca76;
case 0x0c06ca78u: goto P_0c06ca78;
case 0x0c06ca7au: goto P_0c06ca7a;
case 0x0c06ca7cu: goto P_0c06ca7c;
case 0x0c06ca7eu: goto P_0c06ca7e;
case 0x0c06ca80u: goto P_0c06ca80;
case 0x0c06ca82u: goto P_0c06ca82;
case 0x0c06ca84u: goto P_0c06ca84;
case 0x0c06ca86u: goto P_0c06ca86;
case 0x0c06ca88u: goto P_0c06ca88;
case 0x0c06ca8au: goto P_0c06ca8a;
case 0x0c06ca8cu: goto P_0c06ca8c;
case 0x0c06ca8eu: goto P_0c06ca8e;
case 0x0c06ca90u: goto P_0c06ca90;
case 0x0c06ca92u: goto P_0c06ca92;
case 0x0c06ca94u: goto P_0c06ca94;
case 0x0c06ca96u: goto P_0c06ca96;
case 0x0c06ca98u: goto P_0c06ca98;
case 0x0c06ca9au: goto P_0c06ca9a;
case 0x0c06ca9cu: goto P_0c06ca9c;
case 0x0c06ca9eu: goto P_0c06ca9e;
case 0x0c06caa0u: goto P_0c06caa0;
case 0x0c06caa2u: goto P_0c06caa2;
case 0x0c06caa4u: goto P_0c06caa4;
case 0x0c06caa6u: goto P_0c06caa6;
case 0x0c06caa8u: goto P_0c06caa8;
case 0x0c06caaau: goto P_0c06caaa;
case 0x0c06caacu: goto P_0c06caac;
case 0x0c06caaeu: goto P_0c06caae;
case 0x0c06cab0u: goto P_0c06cab0;
case 0x0c06cab2u: goto P_0c06cab2;
case 0x0c06cab4u: goto P_0c06cab4;
case 0x0c06cab6u: goto P_0c06cab6;
case 0x0c06cab8u: goto P_0c06cab8;
case 0x0c06cabau: goto P_0c06caba;
case 0x0c06cabcu: goto P_0c06cabc;
case 0x0c06cabeu: goto P_0c06cabe;
case 0x0c06cac0u: goto P_0c06cac0;
case 0x0c06cac2u: goto P_0c06cac2;
case 0x0c06cac4u: goto P_0c06cac4;
case 0x0c06cac6u: goto P_0c06cac6;
case 0x0c06cac8u: goto P_0c06cac8;
case 0x0c06cacau: goto P_0c06caca;
case 0x0c06caccu: goto P_0c06cacc;
case 0x0c06caceu: goto P_0c06cace;
case 0x0c06cad0u: goto P_0c06cad0;
case 0x0c06cad2u: goto P_0c06cad2;
case 0x0c06cad4u: goto P_0c06cad4;
case 0x0c06cad6u: goto P_0c06cad6;
case 0x0c06cad8u: goto P_0c06cad8;
case 0x0c06cadau: goto P_0c06cada;
case 0x0c06cadcu: goto P_0c06cadc;
case 0x0c06cadeu: goto P_0c06cade;
case 0x0c06cae0u: goto P_0c06cae0;
case 0x0c06cae2u: goto P_0c06cae2;
case 0x0c06cae4u: goto P_0c06cae4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06c7e4: /* original 2fe6, guest PC 0x0c06c7e4 */
if(!s->budget--) { s->failed_pc=0x0c06c7e4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c7e6;
P_0c06c7e6: /* original 2fd6, guest PC 0x0c06c7e6 */
if(!s->budget--) { s->failed_pc=0x0c06c7e6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c7e8;
P_0c06c7e8: /* original 2fc6, guest PC 0x0c06c7e8 */
if(!s->budget--) { s->failed_pc=0x0c06c7e8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c7ea;
P_0c06c7ea: /* original 2fb6, guest PC 0x0c06c7ea */
if(!s->budget--) { s->failed_pc=0x0c06c7eau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c7ec;
P_0c06c7ec: /* original 2f96, guest PC 0x0c06c7ec */
if(!s->budget--) { s->failed_pc=0x0c06c7ecu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c7ee;
P_0c06c7ee: /* original de46, guest PC 0x0c06c7ee */
if(!s->budget--) { s->failed_pc=0x0c06c7eeu; return 0; }
r[14]=read(ram,0x0c06c908u,4);
goto P_0c06c7f0;
P_0c06c7f0: /* original 9081, guest PC 0x0c06c7f0 */
if(!s->budget--) { s->failed_pc=0x0c06c7f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8f6u,2);
goto P_0c06c7f2;
P_0c06c7f2: /* original 4f22, guest PC 0x0c06c7f2 */
if(!s->budget--) { s->failed_pc=0x0c06c7f2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c7f4;
P_0c06c7f4: /* original 06ec, guest PC 0x0c06c7f4 */
if(!s->budget--) { s->failed_pc=0x0c06c7f4u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c7f6;
P_0c06c7f6: /* original 7005, guest PC 0x0c06c7f6 */
if(!s->budget--) { s->failed_pc=0x0c06c7f6u; return 0; }
r[0]+=0x00000005u;
goto P_0c06c7f8;
P_0c06c7f8: /* original 05ec, guest PC 0x0c06c7f8 */
if(!s->budget--) { s->failed_pc=0x0c06c7f8u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c7fa;
P_0c06c7fa: /* original 907d, guest PC 0x0c06c7fa */
if(!s->budget--) { s->failed_pc=0x0c06c7fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8f8u,2);
goto P_0c06c7fc;
P_0c06c7fc: /* original 7ff8, guest PC 0x0c06c7fc */
if(!s->budget--) { s->failed_pc=0x0c06c7fcu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c06c7fe;
P_0c06c7fe: /* original d441, guest PC 0x0c06c7fe */
if(!s->budget--) { s->failed_pc=0x0c06c7feu; return 0; }
r[4]=read(ram,0x0c06c904u,4);
goto P_0c06c800;
P_0c06c800: /* original 01ec, guest PC 0x0c06c800 */
if(!s->budget--) { s->failed_pc=0x0c06c800u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c802;
P_0c06c802: /* original 6063, guest PC 0x0c06c802 */
if(!s->budget--) { s->failed_pc=0x0c06c802u; return 0; }
r[0]=r[6];
goto P_0c06c804;
P_0c06c804: /* original 8801, guest PC 0x0c06c804 */
if(!s->budget--) { s->failed_pc=0x0c06c804u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c806;
P_0c06c806: /* original 8d22, guest PC 0x0c06c806 */
if(!s->budget--) { s->failed_pc=0x0c06c806u; return 0; }
cond=r[17]&1u;
r[7]=0x00000004u;
if(cond) { goto P_0c06c84e; }
goto P_0c06c80a;
P_0c06c808: /* original e704, guest PC 0x0c06c808 */
if(!s->budget--) { s->failed_pc=0x0c06c808u; return 0; }
r[7]=0x00000004u;
goto P_0c06c80a;
P_0c06c80a: /* original d340, guest PC 0x0c06c80a */
if(!s->budget--) { s->failed_pc=0x0c06c80au; return 0; }
r[3]=read(ram,0x0c06c90cu,4);
goto P_0c06c80c;
P_0c06c80c: /* original 6013, guest PC 0x0c06c80c */
if(!s->budget--) { s->failed_pc=0x0c06c80cu; return 0; }
r[0]=r[1];
goto P_0c06c80e;
P_0c06c80e: /* original 8801, guest PC 0x0c06c80e */
if(!s->budget--) { s->failed_pc=0x0c06c80eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c810;
P_0c06c810: /* original 6b53, guest PC 0x0c06c810 */
if(!s->budget--) { s->failed_pc=0x0c06c810u; return 0; }
r[11]=r[5];
goto P_0c06c812;
P_0c06c812: /* original 6c32, guest PC 0x0c06c812 */
if(!s->budget--) { s->failed_pc=0x0c06c812u; return 0; }
tmp=read(ram,r[3],4);
r[12]=tmp;
goto P_0c06c814;
P_0c06c814: /* original 6d73, guest PC 0x0c06c814 */
if(!s->budget--) { s->failed_pc=0x0c06c814u; return 0; }
r[13]=r[7];
goto P_0c06c816;
P_0c06c816: /* original 8f01, guest PC 0x0c06c816 */
if(!s->budget--) { s->failed_pc=0x0c06c816u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(!cond) { goto P_0c06c81c; }
goto P_0c06c81a;
P_0c06c818: /* original 7c01, guest PC 0x0c06c818 */
if(!s->budget--) { s->failed_pc=0x0c06c818u; return 0; }
r[12]+=0x00000001u;
goto P_0c06c81a;
P_0c06c81a: /* original ed27, guest PC 0x0c06c81a */
if(!s->budget--) { s->failed_pc=0x0c06c81au; return 0; }
r[13]=0x00000027u;
goto P_0c06c81c;
P_0c06c81c: /* original 63d3, guest PC 0x0c06c81c */
if(!s->budget--) { s->failed_pc=0x0c06c81cu; return 0; }
r[3]=r[13];
goto P_0c06c81e;
P_0c06c81e: /* original 65c3, guest PC 0x0c06c81e */
if(!s->budget--) { s->failed_pc=0x0c06c81eu; return 0; }
r[5]=r[12];
goto P_0c06c820;
P_0c06c820: /* original e207, guest PC 0x0c06c820 */
if(!s->budget--) { s->failed_pc=0x0c06c820u; return 0; }
r[2]=0x00000007u;
goto P_0c06c822;
P_0c06c822: /* original 73fd, guest PC 0x0c06c822 */
if(!s->budget--) { s->failed_pc=0x0c06c822u; return 0; }
r[3]+=0xfffffffdu;
goto P_0c06c824;
P_0c06c824: /* original 452d, guest PC 0x0c06c824 */
if(!s->budget--) { s->failed_pc=0x0c06c824u; return 0; }
r[5]=(r[2]&0x80000000u)?((r[2]&31u)?r[5]>>((-r[2])&31u):0):r[5]<<(r[2]&31u);
goto P_0c06c826;
P_0c06c826: /* original 2f32, guest PC 0x0c06c826 */
if(!s->budget--) { s->failed_pc=0x0c06c826u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c828;
P_0c06c828: /* original 1f51, guest PC 0x0c06c828 */
if(!s->budget--) { s->failed_pc=0x0c06c828u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c06c82a;
P_0c06c82a: /* original 4300, guest PC 0x0c06c82a */
if(!s->budget--) { s->failed_pc=0x0c06c82au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c06c82c;
P_0c06c82c: /* original 253b, guest PC 0x0c06c82c */
if(!s->budget--) { s->failed_pc=0x0c06c82cu; return 0; }
r[5]|=r[3];
goto P_0c06c82e;
P_0c06c82e: /* original e320, guest PC 0x0c06c82e */
if(!s->budget--) { s->failed_pc=0x0c06c82eu; return 0; }
r[3]=0x00000020u;
goto P_0c06c830;
P_0c06c830: /* original e701, guest PC 0x0c06c830 */
if(!s->budget--) { s->failed_pc=0x0c06c830u; return 0; }
r[7]=0x00000001u;
goto P_0c06c832;
P_0c06c832: /* original 2f36, guest PC 0x0c06c832 */
if(!s->budget--) { s->failed_pc=0x0c06c832u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c834;
P_0c06c834: /* original d236, guest PC 0x0c06c834 */
if(!s->budget--) { s->failed_pc=0x0c06c834u; return 0; }
r[2]=read(ram,0x0c06c910u,4);
goto P_0c06c836;
P_0c06c836: /* original 420b, guest PC 0x0c06c836 */
if(!s->budget--) { s->failed_pc=0x0c06c836u; return 0; }
target=r[2];
r[16]=code_base|0x0c06c83au;
r[6]=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c83au) { target=s->pc; goto dispatch; }
goto P_0c06c83a;
P_0c06c838: /* original e618, guest PC 0x0c06c838 */
if(!s->budget--) { s->failed_pc=0x0c06c838u; return 0; }
r[6]=0x00000018u;
goto P_0c06c83a;
P_0c06c83a: /* original 905e, guest PC 0x0c06c83a */
if(!s->budget--) { s->failed_pc=0x0c06c83au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8fau,2);
goto P_0c06c83c;
P_0c06c83c: /* original 7f04, guest PC 0x0c06c83c */
if(!s->budget--) { s->failed_pc=0x0c06c83cu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c83e;
P_0c06c83e: /* original 64f2, guest PC 0x0c06c83e */
if(!s->budget--) { s->failed_pc=0x0c06c83eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06c840;
P_0c06c840: /* original 09ec, guest PC 0x0c06c840 */
if(!s->budget--) { s->failed_pc=0x0c06c840u; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c842;
P_0c06c842: /* original 700d, guest PC 0x0c06c842 */
if(!s->budget--) { s->failed_pc=0x0c06c842u; return 0; }
r[0]+=0x0000000du;
goto P_0c06c844;
P_0c06c844: /* original 53f1, guest PC 0x0c06c844 */
if(!s->budget--) { s->failed_pc=0x0c06c844u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06c846;
P_0c06c846: /* original 4400, guest PC 0x0c06c846 */
if(!s->budget--) { s->failed_pc=0x0c06c846u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c848;
P_0c06c848: /* original 0eec, guest PC 0x0c06c848 */
if(!s->budget--) { s->failed_pc=0x0c06c848u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c84a;
P_0c06c84a: /* original a018, guest PC 0x0c06c84a */
if(!s->budget--) { s->failed_pc=0x0c06c84au; return 0; }
r[4]|=r[3];
goto P_0c06c87e;
P_0c06c84c: /* original 243b, guest PC 0x0c06c84c */
if(!s->budget--) { s->failed_pc=0x0c06c84cu; return 0; }
r[4]|=r[3];
goto P_0c06c84e;
P_0c06c84e: /* original 9054, guest PC 0x0c06c84e */
if(!s->budget--) { s->failed_pc=0x0c06c84eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8fau,2);
goto P_0c06c850;
P_0c06c850: /* original 6d73, guest PC 0x0c06c850 */
if(!s->budget--) { s->failed_pc=0x0c06c850u; return 0; }
r[13]=r[7];
goto P_0c06c852;
P_0c06c852: /* original d32e, guest PC 0x0c06c852 */
if(!s->budget--) { s->failed_pc=0x0c06c852u; return 0; }
r[3]=read(ram,0x0c06c90cu,4);
goto P_0c06c854;
P_0c06c854: /* original 09ec, guest PC 0x0c06c854 */
if(!s->budget--) { s->failed_pc=0x0c06c854u; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c856;
P_0c06c856: /* original 6013, guest PC 0x0c06c856 */
if(!s->budget--) { s->failed_pc=0x0c06c856u; return 0; }
r[0]=r[1];
goto P_0c06c858;
P_0c06c858: /* original 6c32, guest PC 0x0c06c858 */
if(!s->budget--) { s->failed_pc=0x0c06c858u; return 0; }
tmp=read(ram,r[3],4);
r[12]=tmp;
goto P_0c06c85a;
P_0c06c85a: /* original 8801, guest PC 0x0c06c85a */
if(!s->budget--) { s->failed_pc=0x0c06c85au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c85c;
P_0c06c85c: /* original 7c01, guest PC 0x0c06c85c */
if(!s->budget--) { s->failed_pc=0x0c06c85cu; return 0; }
r[12]+=0x00000001u;
goto P_0c06c85e;
P_0c06c85e: /* original 8f05, guest PC 0x0c06c85e */
if(!s->budget--) { s->failed_pc=0x0c06c85eu; return 0; }
cond=r[17]&1u;
r[11]=r[5];
if(!cond) { goto P_0c06c86c; }
goto P_0c06c862;
P_0c06c860: /* original 6b53, guest PC 0x0c06c860 */
if(!s->budget--) { s->failed_pc=0x0c06c860u; return 0; }
r[11]=r[5];
goto P_0c06c862;
P_0c06c862: /* original 904b, guest PC 0x0c06c862 */
if(!s->budget--) { s->failed_pc=0x0c06c862u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8fcu,2);
goto P_0c06c864;
P_0c06c864: /* original ed27, guest PC 0x0c06c864 */
if(!s->budget--) { s->failed_pc=0x0c06c864u; return 0; }
r[13]=0x00000027u;
goto P_0c06c866;
P_0c06c866: /* original 0bec, guest PC 0x0c06c866 */
if(!s->budget--) { s->failed_pc=0x0c06c866u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c868;
P_0c06c868: /* original 7001, guest PC 0x0c06c868 */
if(!s->budget--) { s->failed_pc=0x0c06c868u; return 0; }
r[0]+=0x00000001u;
goto P_0c06c86a;
P_0c06c86a: /* original 09ec, guest PC 0x0c06c86a */
if(!s->budget--) { s->failed_pc=0x0c06c86au; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c86c;
P_0c06c86c: /* original 64d3, guest PC 0x0c06c86c */
if(!s->budget--) { s->failed_pc=0x0c06c86cu; return 0; }
r[4]=r[13];
goto P_0c06c86e;
P_0c06c86e: /* original 9046, guest PC 0x0c06c86e */
if(!s->budget--) { s->failed_pc=0x0c06c86eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8feu,2);
goto P_0c06c870;
P_0c06c870: /* original 62c3, guest PC 0x0c06c870 */
if(!s->budget--) { s->failed_pc=0x0c06c870u; return 0; }
r[2]=r[12];
goto P_0c06c872;
P_0c06c872: /* original e307, guest PC 0x0c06c872 */
if(!s->budget--) { s->failed_pc=0x0c06c872u; return 0; }
r[3]=0x00000007u;
goto P_0c06c874;
P_0c06c874: /* original 74fd, guest PC 0x0c06c874 */
if(!s->budget--) { s->failed_pc=0x0c06c874u; return 0; }
r[4]+=0xfffffffdu;
goto P_0c06c876;
P_0c06c876: /* original 0eec, guest PC 0x0c06c876 */
if(!s->budget--) { s->failed_pc=0x0c06c876u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c878;
P_0c06c878: /* original 423d, guest PC 0x0c06c878 */
if(!s->budget--) { s->failed_pc=0x0c06c878u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c06c87a;
P_0c06c87a: /* original 4400, guest PC 0x0c06c87a */
if(!s->budget--) { s->failed_pc=0x0c06c87au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c87c;
P_0c06c87c: /* original 242b, guest PC 0x0c06c87c */
if(!s->budget--) { s->failed_pc=0x0c06c87cu; return 0; }
r[4]|=r[2];
goto P_0c06c87e;
P_0c06c87e: /* original bd8b, guest PC 0x0c06c87e */
if(!s->budget--) { s->failed_pc=0x0c06c87eu; return 0; }
target=code_base|0x0c06c398u; r[16]=code_base|0x0c06c882u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c882u) { target=s->pc; goto dispatch; }
goto P_0c06c882;
P_0c06c880: /* original 0009, guest PC 0x0c06c880 */
if(!s->budget--) { s->failed_pc=0x0c06c880u; return 0; }
goto P_0c06c882;
P_0c06c882: /* original 2008, guest PC 0x0c06c882 */
if(!s->budget--) { s->failed_pc=0x0c06c882u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06c884;
P_0c06c884: /* original 8906, guest PC 0x0c06c884 */
if(!s->budget--) { s->failed_pc=0x0c06c884u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c894; }
goto P_0c06c886;
P_0c06c886: /* original 66b3, guest PC 0x0c06c886 */
if(!s->budget--) { s->failed_pc=0x0c06c886u; return 0; }
r[6]=r[11];
goto P_0c06c888;
P_0c06c888: /* original 65c3, guest PC 0x0c06c888 */
if(!s->budget--) { s->failed_pc=0x0c06c888u; return 0; }
r[5]=r[12];
goto P_0c06c88a;
P_0c06c88a: /* original 2fe6, guest PC 0x0c06c88a */
if(!s->budget--) { s->failed_pc=0x0c06c88au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c88c;
P_0c06c88c: /* original 6793, guest PC 0x0c06c88c */
if(!s->budget--) { s->failed_pc=0x0c06c88cu; return 0; }
r[7]=r[9];
goto P_0c06c88e;
P_0c06c88e: /* original b12a, guest PC 0x0c06c88e */
if(!s->budget--) { s->failed_pc=0x0c06c88eu; return 0; }
target=code_base|0x0c06cae6u; r[16]=code_base|0x0c06c892u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c892u) { target=s->pc; goto dispatch; }
goto P_0c06c892;
P_0c06c890: /* original 64d3, guest PC 0x0c06c890 */
if(!s->budget--) { s->failed_pc=0x0c06c890u; return 0; }
r[4]=r[13];
goto P_0c06c892;
P_0c06c892: /* original 7f04, guest PC 0x0c06c892 */
if(!s->budget--) { s->failed_pc=0x0c06c892u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c894;
P_0c06c894: /* original 7f08, guest PC 0x0c06c894 */
if(!s->budget--) { s->failed_pc=0x0c06c894u; return 0; }
r[15]+=0x00000008u;
goto P_0c06c896;
P_0c06c896: /* original 4f26, guest PC 0x0c06c896 */
if(!s->budget--) { s->failed_pc=0x0c06c896u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c898;
P_0c06c898: /* original 69f6, guest PC 0x0c06c898 */
if(!s->budget--) { s->failed_pc=0x0c06c898u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06c89a;
P_0c06c89a: /* original 6bf6, guest PC 0x0c06c89a */
if(!s->budget--) { s->failed_pc=0x0c06c89au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06c89c;
P_0c06c89c: /* original 6cf6, guest PC 0x0c06c89c */
if(!s->budget--) { s->failed_pc=0x0c06c89cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06c89e;
P_0c06c89e: /* original 6df6, guest PC 0x0c06c89e */
if(!s->budget--) { s->failed_pc=0x0c06c89eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06c8a0;
P_0c06c8a0: /* original 000b, guest PC 0x0c06c8a0 */
if(!s->budget--) { s->failed_pc=0x0c06c8a0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06c8a2: /* original 6ef6, guest PC 0x0c06c8a2 */
if(!s->budget--) { s->failed_pc=0x0c06c8a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c8a4;
P_0c06c8a4: /* original 2fe6, guest PC 0x0c06c8a4 */
if(!s->budget--) { s->failed_pc=0x0c06c8a4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c8a6;
P_0c06c8a6: /* original e207, guest PC 0x0c06c8a6 */
if(!s->budget--) { s->failed_pc=0x0c06c8a6u; return 0; }
r[2]=0x00000007u;
goto P_0c06c8a8;
P_0c06c8a8: /* original 2fd6, guest PC 0x0c06c8a8 */
if(!s->budget--) { s->failed_pc=0x0c06c8a8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c8aa;
P_0c06c8aa: /* original ee08, guest PC 0x0c06c8aa */
if(!s->budget--) { s->failed_pc=0x0c06c8aau; return 0; }
r[14]=0x00000008u;
goto P_0c06c8ac;
P_0c06c8ac: /* original d317, guest PC 0x0c06c8ac */
if(!s->budget--) { s->failed_pc=0x0c06c8acu; return 0; }
r[3]=read(ram,0x0c06c90cu,4);
goto P_0c06c8ae;
P_0c06c8ae: /* original 9023, guest PC 0x0c06c8ae */
if(!s->budget--) { s->failed_pc=0x0c06c8aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8f8u,2);
goto P_0c06c8b0;
P_0c06c8b0: /* original 6432, guest PC 0x0c06c8b0 */
if(!s->budget--) { s->failed_pc=0x0c06c8b0u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c06c8b2;
P_0c06c8b2: /* original 4f22, guest PC 0x0c06c8b2 */
if(!s->budget--) { s->failed_pc=0x0c06c8b2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c8b4;
P_0c06c8b4: /* original 7401, guest PC 0x0c06c8b4 */
if(!s->budget--) { s->failed_pc=0x0c06c8b4u; return 0; }
r[4]+=0x00000001u;
goto P_0c06c8b6;
P_0c06c8b6: /* original 6543, guest PC 0x0c06c8b6 */
if(!s->budget--) { s->failed_pc=0x0c06c8b6u; return 0; }
r[5]=r[4];
goto P_0c06c8b8;
P_0c06c8b8: /* original d413, guest PC 0x0c06c8b8 */
if(!s->budget--) { s->failed_pc=0x0c06c8b8u; return 0; }
r[4]=read(ram,0x0c06c908u,4);
goto P_0c06c8ba;
P_0c06c8ba: /* original 7ffc, guest PC 0x0c06c8ba */
if(!s->budget--) { s->failed_pc=0x0c06c8bau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c8bc;
P_0c06c8bc: /* original 014c, guest PC 0x0c06c8bc */
if(!s->budget--) { s->failed_pc=0x0c06c8bcu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c8be;
P_0c06c8be: /* original 452d, guest PC 0x0c06c8be */
if(!s->budget--) { s->failed_pc=0x0c06c8beu; return 0; }
r[5]=(r[2]&0x80000000u)?((r[2]&31u)?r[5]>>((-r[2])&31u):0):r[5]<<(r[2]&31u);
goto P_0c06c8c0;
P_0c06c8c0: /* original 6013, guest PC 0x0c06c8c0 */
if(!s->budget--) { s->failed_pc=0x0c06c8c0u; return 0; }
r[0]=r[1];
goto P_0c06c8c2;
P_0c06c8c2: /* original 8801, guest PC 0x0c06c8c2 */
if(!s->budget--) { s->failed_pc=0x0c06c8c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c8c4;
P_0c06c8c4: /* original 2f12, guest PC 0x0c06c8c4 */
if(!s->budget--) { s->failed_pc=0x0c06c8c4u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c06c8c6;
P_0c06c8c6: /* original 8f02, guest PC 0x0c06c8c6 */
if(!s->budget--) { s->failed_pc=0x0c06c8c6u; return 0; }
cond=r[17]&1u;
r[14]|=r[5];
if(!cond) { goto P_0c06c8ce; }
goto P_0c06c8ca;
P_0c06c8c8: /* original 2e5b, guest PC 0x0c06c8c8 */
if(!s->budget--) { s->failed_pc=0x0c06c8c8u; return 0; }
r[14]|=r[5];
goto P_0c06c8ca;
P_0c06c8ca: /* original ee4e, guest PC 0x0c06c8ca */
if(!s->budget--) { s->failed_pc=0x0c06c8cau; return 0; }
r[14]=0x0000004eu;
goto P_0c06c8cc;
P_0c06c8cc: /* original 2e5b, guest PC 0x0c06c8cc */
if(!s->budget--) { s->failed_pc=0x0c06c8ccu; return 0; }
r[14]|=r[5];
goto P_0c06c8ce;
P_0c06c8ce: /* original 9017, guest PC 0x0c06c8ce */
if(!s->budget--) { s->failed_pc=0x0c06c8ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c900u,2);
goto P_0c06c8d0;
P_0c06c8d0: /* original 004c, guest PC 0x0c06c8d0 */
if(!s->budget--) { s->failed_pc=0x0c06c8d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c8d2;
P_0c06c8d2: /* original 8801, guest PC 0x0c06c8d2 */
if(!s->budget--) { s->failed_pc=0x0c06c8d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c8d4;
P_0c06c8d4: /* original 8d34, guest PC 0x0c06c8d4 */
if(!s->budget--) { s->failed_pc=0x0c06c8d4u; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c06c940; }
goto P_0c06c8d8;
P_0c06c8d6: /* original 6503, guest PC 0x0c06c8d6 */
if(!s->budget--) { s->failed_pc=0x0c06c8d6u; return 0; }
r[5]=r[0];
goto P_0c06c8d8;
P_0c06c8d8: /* original 900d, guest PC 0x0c06c8d8 */
if(!s->budget--) { s->failed_pc=0x0c06c8d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8f6u,2);
goto P_0c06c8da;
P_0c06c8da: /* original 004c, guest PC 0x0c06c8da */
if(!s->budget--) { s->failed_pc=0x0c06c8dau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c8dc;
P_0c06c8dc: /* original 8801, guest PC 0x0c06c8dc */
if(!s->budget--) { s->failed_pc=0x0c06c8dcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c8de;
P_0c06c8de: /* original 8d19, guest PC 0x0c06c8de */
if(!s->budget--) { s->failed_pc=0x0c06c8deu; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c06c914; }
goto P_0c06c8e2;
P_0c06c8e0: /* original 6503, guest PC 0x0c06c8e0 */
if(!s->budget--) { s->failed_pc=0x0c06c8e0u; return 0; }
r[5]=r[0];
goto P_0c06c8e2;
P_0c06c8e2: /* original 900a, guest PC 0x0c06c8e2 */
if(!s->budget--) { s->failed_pc=0x0c06c8e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8fau,2);
goto P_0c06c8e4;
P_0c06c8e4: /* original 064c, guest PC 0x0c06c8e4 */
if(!s->budget--) { s->failed_pc=0x0c06c8e4u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c8e6;
P_0c06c8e6: /* original 70ff, guest PC 0x0c06c8e6 */
if(!s->budget--) { s->failed_pc=0x0c06c8e6u; return 0; }
r[0]+=0xffffffffu;
goto P_0c06c8e8;
P_0c06c8e8: /* original 054c, guest PC 0x0c06c8e8 */
if(!s->budget--) { s->failed_pc=0x0c06c8e8u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c8ea;
P_0c06c8ea: /* original 2558, guest PC 0x0c06c8ea */
if(!s->budget--) { s->failed_pc=0x0c06c8eau; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06c8ec;
P_0c06c8ec: /* original 8b1d, guest PC 0x0c06c8ec */
if(!s->budget--) { s->failed_pc=0x0c06c8ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c92a; }
goto P_0c06c8ee;
P_0c06c8ee: /* original 2668, guest PC 0x0c06c8ee */
if(!s->budget--) { s->failed_pc=0x0c06c8eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06c8f0;
P_0c06c8f0: /* original 8b1b, guest PC 0x0c06c8f0 */
if(!s->budget--) { s->failed_pc=0x0c06c8f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c92a; }
goto P_0c06c8f2;
P_0c06c8f2: /* original a022, guest PC 0x0c06c8f2 */
if(!s->budget--) { s->failed_pc=0x0c06c8f2u; return 0; }
goto P_0c06c93a;
P_0c06c8f4: /* original 0009, guest PC 0x0c06c8f4 */
if(!s->budget--) { s->failed_pc=0x0c06c8f4u; return 0; }
if(!vf3_matrix_family(0x0c06c8f6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06c8f6u; return 0; } return 1;
P_0c06c914: /* original 60f2, guest PC 0x0c06c914 */
if(!s->budget--) { s->failed_pc=0x0c06c914u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c06c916;
P_0c06c916: /* original 8801, guest PC 0x0c06c916 */
if(!s->budget--) { s->failed_pc=0x0c06c916u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c918;
P_0c06c918: /* original 89e3, guest PC 0x0c06c918 */
if(!s->budget--) { s->failed_pc=0x0c06c918u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c8e2; }
goto P_0c06c91a;
P_0c06c91a: /* original 906d, guest PC 0x0c06c91a */
if(!s->budget--) { s->failed_pc=0x0c06c91au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c9f8u,2);
goto P_0c06c91c;
P_0c06c91c: /* original 064c, guest PC 0x0c06c91c */
if(!s->budget--) { s->failed_pc=0x0c06c91cu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c91e;
P_0c06c91e: /* original 70ff, guest PC 0x0c06c91e */
if(!s->budget--) { s->failed_pc=0x0c06c91eu; return 0; }
r[0]+=0xffffffffu;
goto P_0c06c920;
P_0c06c920: /* original 054c, guest PC 0x0c06c920 */
if(!s->budget--) { s->failed_pc=0x0c06c920u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c922;
P_0c06c922: /* original 2558, guest PC 0x0c06c922 */
if(!s->budget--) { s->failed_pc=0x0c06c922u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06c924;
P_0c06c924: /* original 8b01, guest PC 0x0c06c924 */
if(!s->budget--) { s->failed_pc=0x0c06c924u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c92a; }
goto P_0c06c926;
P_0c06c926: /* original 2668, guest PC 0x0c06c926 */
if(!s->budget--) { s->failed_pc=0x0c06c926u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06c928;
P_0c06c928: /* original 8907, guest PC 0x0c06c928 */
if(!s->budget--) { s->failed_pc=0x0c06c928u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c93a; }
goto P_0c06c92a;
P_0c06c92a: /* original 9066, guest PC 0x0c06c92a */
if(!s->budget--) { s->failed_pc=0x0c06c92au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c9fau,2);
goto P_0c06c92c;
P_0c06c92c: /* original 064c, guest PC 0x0c06c92c */
if(!s->budget--) { s->failed_pc=0x0c06c92cu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c92e;
P_0c06c92e: /* original 6453, guest PC 0x0c06c92e */
if(!s->budget--) { s->failed_pc=0x0c06c92eu; return 0; }
r[4]=r[5];
goto P_0c06c930;
P_0c06c930: /* original 3462, guest PC 0x0c06c930 */
if(!s->budget--) { s->failed_pc=0x0c06c930u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[6])!=0);
goto P_0c06c932;
P_0c06c932: /* original 8905, guest PC 0x0c06c932 */
if(!s->budget--) { s->failed_pc=0x0c06c932u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c940; }
goto P_0c06c934;
P_0c06c934: /* original dd32, guest PC 0x0c06c934 */
if(!s->budget--) { s->failed_pc=0x0c06c934u; return 0; }
r[13]=read(ram,0x0c06ca00u,4);
goto P_0c06c936;
P_0c06c936: /* original a004, guest PC 0x0c06c936 */
if(!s->budget--) { s->failed_pc=0x0c06c936u; return 0; }
goto P_0c06c942;
P_0c06c938: /* original 0009, guest PC 0x0c06c938 */
if(!s->budget--) { s->failed_pc=0x0c06c938u; return 0; }
goto P_0c06c93a;
P_0c06c93a: /* original dd32, guest PC 0x0c06c93a */
if(!s->budget--) { s->failed_pc=0x0c06c93au; return 0; }
r[13]=read(ram,0x0c06ca04u,4);
goto P_0c06c93c;
P_0c06c93c: /* original a001, guest PC 0x0c06c93c */
if(!s->budget--) { s->failed_pc=0x0c06c93cu; return 0; }
goto P_0c06c942;
P_0c06c93e: /* original 0009, guest PC 0x0c06c93e */
if(!s->budget--) { s->failed_pc=0x0c06c93eu; return 0; }
goto P_0c06c940;
P_0c06c940: /* original dd31, guest PC 0x0c06c940 */
if(!s->budget--) { s->failed_pc=0x0c06c940u; return 0; }
r[13]=read(ram,0x0c06ca08u,4);
goto P_0c06c942;
P_0c06c942: /* original bd29, guest PC 0x0c06c942 */
if(!s->budget--) { s->failed_pc=0x0c06c942u; return 0; }
target=code_base|0x0c06c398u; r[16]=code_base|0x0c06c946u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c946u) { target=s->pc; goto dispatch; }
goto P_0c06c946;
P_0c06c944: /* original 64e3, guest PC 0x0c06c944 */
if(!s->budget--) { s->failed_pc=0x0c06c944u; return 0; }
r[4]=r[14];
goto P_0c06c946;
P_0c06c946: /* original 2008, guest PC 0x0c06c946 */
if(!s->budget--) { s->failed_pc=0x0c06c946u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06c948;
P_0c06c948: /* original 8904, guest PC 0x0c06c948 */
if(!s->budget--) { s->failed_pc=0x0c06c948u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c954; }
goto P_0c06c94a;
P_0c06c94a: /* original d230, guest PC 0x0c06c94a */
if(!s->budget--) { s->failed_pc=0x0c06c94au; return 0; }
r[2]=read(ram,0x0c06ca0cu,4);
goto P_0c06c94c;
P_0c06c94c: /* original 65d3, guest PC 0x0c06c94c */
if(!s->budget--) { s->failed_pc=0x0c06c94cu; return 0; }
r[5]=r[13];
goto P_0c06c94e;
P_0c06c94e: /* original e601, guest PC 0x0c06c94e */
if(!s->budget--) { s->failed_pc=0x0c06c94eu; return 0; }
r[6]=0x00000001u;
goto P_0c06c950;
P_0c06c950: /* original 420b, guest PC 0x0c06c950 */
if(!s->budget--) { s->failed_pc=0x0c06c950u; return 0; }
target=r[2];
r[16]=code_base|0x0c06c954u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c954u) { target=s->pc; goto dispatch; }
goto P_0c06c954;
P_0c06c952: /* original 64e3, guest PC 0x0c06c952 */
if(!s->budget--) { s->failed_pc=0x0c06c952u; return 0; }
r[4]=r[14];
goto P_0c06c954;
P_0c06c954: /* original 7f04, guest PC 0x0c06c954 */
if(!s->budget--) { s->failed_pc=0x0c06c954u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c956;
P_0c06c956: /* original 4f26, guest PC 0x0c06c956 */
if(!s->budget--) { s->failed_pc=0x0c06c956u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c958;
P_0c06c958: /* original 6df6, guest PC 0x0c06c958 */
if(!s->budget--) { s->failed_pc=0x0c06c958u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06c95a;
P_0c06c95a: /* original 000b, guest PC 0x0c06c95a */
if(!s->budget--) { s->failed_pc=0x0c06c95au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06c95c: /* original 6ef6, guest PC 0x0c06c95c */
if(!s->budget--) { s->failed_pc=0x0c06c95cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c95e;
P_0c06c95e: /* original 2fe6, guest PC 0x0c06c95e */
if(!s->budget--) { s->failed_pc=0x0c06c95eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c960;
P_0c06c960: /* original ee27, guest PC 0x0c06c960 */
if(!s->budget--) { s->failed_pc=0x0c06c960u; return 0; }
r[14]=0x00000027u;
goto P_0c06c962;
P_0c06c962: /* original 2fd6, guest PC 0x0c06c962 */
if(!s->budget--) { s->failed_pc=0x0c06c962u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c964;
P_0c06c964: /* original 60e3, guest PC 0x0c06c964 */
if(!s->budget--) { s->failed_pc=0x0c06c964u; return 0; }
r[0]=r[14];
goto P_0c06c966;
P_0c06c966: /* original 2fc6, guest PC 0x0c06c966 */
if(!s->budget--) { s->failed_pc=0x0c06c966u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c968;
P_0c06c968: /* original 706b, guest PC 0x0c06c968 */
if(!s->budget--) { s->failed_pc=0x0c06c968u; return 0; }
r[0]+=0x0000006bu;
goto P_0c06c96a;
P_0c06c96a: /* original 2fb6, guest PC 0x0c06c96a */
if(!s->budget--) { s->failed_pc=0x0c06c96au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c96c;
P_0c06c96c: /* original 2fa6, guest PC 0x0c06c96c */
if(!s->budget--) { s->failed_pc=0x0c06c96cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c96e;
P_0c06c96e: /* original 2f96, guest PC 0x0c06c96e */
if(!s->budget--) { s->failed_pc=0x0c06c96eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c970;
P_0c06c970: /* original 4f22, guest PC 0x0c06c970 */
if(!s->budget--) { s->failed_pc=0x0c06c970u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c972;
P_0c06c972: /* original d327, guest PC 0x0c06c972 */
if(!s->budget--) { s->failed_pc=0x0c06c972u; return 0; }
r[3]=read(ram,0x0c06ca10u,4);
goto P_0c06c974;
P_0c06c974: /* original 7ffc, guest PC 0x0c06c974 */
if(!s->budget--) { s->failed_pc=0x0c06c974u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c976;
P_0c06c976: /* original 2f32, guest PC 0x0c06c976 */
if(!s->budget--) { s->failed_pc=0x0c06c976u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c978;
P_0c06c978: /* original dd28, guest PC 0x0c06c978 */
if(!s->budget--) { s->failed_pc=0x0c06c978u; return 0; }
r[13]=read(ram,0x0c06ca1cu,4);
goto P_0c06c97a;
P_0c06c97a: /* original d327, guest PC 0x0c06c97a */
if(!s->budget--) { s->failed_pc=0x0c06c97au; return 0; }
r[3]=read(ram,0x0c06ca18u,4);
goto P_0c06c97c;
P_0c06c97c: /* original 04dc, guest PC 0x0c06c97c */
if(!s->budget--) { s->failed_pc=0x0c06c97cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c06c97e;
P_0c06c97e: /* original 6632, guest PC 0x0c06c97e */
if(!s->budget--) { s->failed_pc=0x0c06c97eu; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c06c980;
P_0c06c980: /* original 6043, guest PC 0x0c06c980 */
if(!s->budget--) { s->failed_pc=0x0c06c980u; return 0; }
r[0]=r[4];
goto P_0c06c982;
P_0c06c982: /* original dc24, guest PC 0x0c06c982 */
if(!s->budget--) { s->failed_pc=0x0c06c982u; return 0; }
r[12]=read(ram,0x0c06ca14u,4);
goto P_0c06c984;
P_0c06c984: /* original 8801, guest PC 0x0c06c984 */
if(!s->budget--) { s->failed_pc=0x0c06c984u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c986;
P_0c06c986: /* original 7601, guest PC 0x0c06c986 */
if(!s->budget--) { s->failed_pc=0x0c06c986u; return 0; }
r[6]+=0x00000001u;
goto P_0c06c988;
P_0c06c988: /* original 8d01, guest PC 0x0c06c988 */
if(!s->budget--) { s->failed_pc=0x0c06c988u; return 0; }
cond=r[17]&1u;
r[5]=0x00000004u;
if(cond) { goto P_0c06c98e; }
goto P_0c06c98c;
P_0c06c98a: /* original e504, guest PC 0x0c06c98a */
if(!s->budget--) { s->failed_pc=0x0c06c98au; return 0; }
r[5]=0x00000004u;
goto P_0c06c98c;
P_0c06c98c: /* original 6e53, guest PC 0x0c06c98c */
if(!s->budget--) { s->failed_pc=0x0c06c98cu; return 0; }
r[14]=r[5];
goto P_0c06c98e;
P_0c06c98e: /* original 54d2, guest PC 0x0c06c98e */
if(!s->budget--) { s->failed_pc=0x0c06c98eu; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c06c990;
P_0c06c990: /* original 6b63, guest PC 0x0c06c990 */
if(!s->budget--) { s->failed_pc=0x0c06c990u; return 0; }
r[11]=r[6];
goto P_0c06c992;
P_0c06c992: /* original e307, guest PC 0x0c06c992 */
if(!s->budget--) { s->failed_pc=0x0c06c992u; return 0; }
r[3]=0x00000007u;
goto P_0c06c994;
P_0c06c994: /* original 6ae3, guest PC 0x0c06c994 */
if(!s->budget--) { s->failed_pc=0x0c06c994u; return 0; }
r[10]=r[14];
goto P_0c06c996;
P_0c06c996: /* original 4a00, guest PC 0x0c06c996 */
if(!s->budget--) { s->failed_pc=0x0c06c996u; return 0; }
r[17]=(r[17]&~1u)|((r[10]>>31)!=0);
r[10]<<=1;
goto P_0c06c998;
P_0c06c998: /* original 2458, guest PC 0x0c06c998 */
if(!s->budget--) { s->failed_pc=0x0c06c998u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[5])==0)!=0);
goto P_0c06c99a;
P_0c06c99a: /* original 4b3d, guest PC 0x0c06c99a */
if(!s->budget--) { s->failed_pc=0x0c06c99au; return 0; }
r[11]=(r[3]&0x80000000u)?((r[3]&31u)?r[11]>>((-r[3])&31u):0):r[11]<<(r[3]&31u);
goto P_0c06c99c;
P_0c06c99c: /* original 8d13, guest PC 0x0c06c99c */
if(!s->budget--) { s->failed_pc=0x0c06c99cu; return 0; }
cond=r[17]&1u;
r[10]|=r[11];
if(cond) { goto P_0c06c9c6; }
goto P_0c06c9a0;
P_0c06c99e: /* original 2abb, guest PC 0x0c06c99e */
if(!s->budget--) { s->failed_pc=0x0c06c99eu; return 0; }
r[10]|=r[11];
goto P_0c06c9a0;
P_0c06c9a0: /* original bcfa, guest PC 0x0c06c9a0 */
if(!s->budget--) { s->failed_pc=0x0c06c9a0u; return 0; }
target=code_base|0x0c06c398u; r[16]=code_base|0x0c06c9a4u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c9a4u) { target=s->pc; goto dispatch; }
goto P_0c06c9a4;
P_0c06c9a2: /* original 64a3, guest PC 0x0c06c9a2 */
if(!s->budget--) { s->failed_pc=0x0c06c9a2u; return 0; }
r[4]=r[10];
goto P_0c06c9a4;
P_0c06c9a4: /* original 2008, guest PC 0x0c06c9a4 */
if(!s->budget--) { s->failed_pc=0x0c06c9a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06c9a6;
P_0c06c9a6: /* original 8b01, guest PC 0x0c06c9a6 */
if(!s->budget--) { s->failed_pc=0x0c06c9a6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c9ac; }
goto P_0c06c9a8;
P_0c06c9a8: /* original a094, guest PC 0x0c06c9a8 */
if(!s->budget--) { s->failed_pc=0x0c06c9a8u; return 0; }
goto P_0c06cad4;
P_0c06c9aa: /* original 0009, guest PC 0x0c06c9aa */
if(!s->budget--) { s->failed_pc=0x0c06c9aau; return 0; }
goto P_0c06c9ac;
P_0c06c9ac: /* original 7f04, guest PC 0x0c06c9ac */
if(!s->budget--) { s->failed_pc=0x0c06c9acu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c9ae;
P_0c06c9ae: /* original 64a3, guest PC 0x0c06c9ae */
if(!s->budget--) { s->failed_pc=0x0c06c9aeu; return 0; }
r[4]=r[10];
goto P_0c06c9b0;
P_0c06c9b0: /* original 4f26, guest PC 0x0c06c9b0 */
if(!s->budget--) { s->failed_pc=0x0c06c9b0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c9b2;
P_0c06c9b2: /* original d216, guest PC 0x0c06c9b2 */
if(!s->budget--) { s->failed_pc=0x0c06c9b2u; return 0; }
r[2]=read(ram,0x0c06ca0cu,4);
goto P_0c06c9b4;
P_0c06c9b4: /* original e601, guest PC 0x0c06c9b4 */
if(!s->budget--) { s->failed_pc=0x0c06c9b4u; return 0; }
r[6]=0x00000001u;
goto P_0c06c9b6;
P_0c06c9b6: /* original d51a, guest PC 0x0c06c9b6 */
if(!s->budget--) { s->failed_pc=0x0c06c9b6u; return 0; }
r[5]=read(ram,0x0c06ca20u,4);
goto P_0c06c9b8;
P_0c06c9b8: /* original 69f6, guest PC 0x0c06c9b8 */
if(!s->budget--) { s->failed_pc=0x0c06c9b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06c9ba;
P_0c06c9ba: /* original 6af6, guest PC 0x0c06c9ba */
if(!s->budget--) { s->failed_pc=0x0c06c9bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06c9bc;
P_0c06c9bc: /* original 6bf6, guest PC 0x0c06c9bc */
if(!s->budget--) { s->failed_pc=0x0c06c9bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06c9be;
P_0c06c9be: /* original 6cf6, guest PC 0x0c06c9be */
if(!s->budget--) { s->failed_pc=0x0c06c9beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06c9c0;
P_0c06c9c0: /* original 6df6, guest PC 0x0c06c9c0 */
if(!s->budget--) { s->failed_pc=0x0c06c9c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06c9c2;
P_0c06c9c2: /* original 422b, guest PC 0x0c06c9c2 */
if(!s->budget--) { s->failed_pc=0x0c06c9c2u; return 0; }
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
P_0c06c9c4: /* original 6ef6, guest PC 0x0c06c9c4 */
if(!s->budget--) { s->failed_pc=0x0c06c9c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c9c6;
P_0c06c9c6: /* original d317, guest PC 0x0c06c9c6 */
if(!s->budget--) { s->failed_pc=0x0c06c9c6u; return 0; }
r[3]=read(ram,0x0c06ca24u,4);
goto P_0c06c9c8;
P_0c06c9c8: /* original 64f2, guest PC 0x0c06c9c8 */
if(!s->budget--) { s->failed_pc=0x0c06c9c8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06c9ca;
P_0c06c9ca: /* original 430b, guest PC 0x0c06c9ca */
if(!s->budget--) { s->failed_pc=0x0c06c9cau; return 0; }
target=r[3];
r[16]=code_base|0x0c06c9ceu;
r[4]+=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c9ceu) { target=s->pc; goto dispatch; }
goto P_0c06c9ce;
P_0c06c9cc: /* original 7412, guest PC 0x0c06c9cc */
if(!s->budget--) { s->failed_pc=0x0c06c9ccu; return 0; }
r[4]+=0x00000012u;
goto P_0c06c9ce;
P_0c06c9ce: /* original 9015, guest PC 0x0c06c9ce */
if(!s->budget--) { s->failed_pc=0x0c06c9ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c9fcu,2);
goto P_0c06c9d0;
P_0c06c9d0: /* original e706, guest PC 0x0c06c9d0 */
if(!s->budget--) { s->failed_pc=0x0c06c9d0u; return 0; }
r[7]=0x00000006u;
goto P_0c06c9d2;
P_0c06c9d2: /* original 0dde, guest PC 0x0c06c9d2 */
if(!s->budget--) { s->failed_pc=0x0c06c9d2u; return 0; }
r[13]=read(ram,r[13]+r[0],4);
goto P_0c06c9d4;
P_0c06c9d4: /* original 60d3, guest PC 0x0c06c9d4 */
if(!s->budget--) { s->failed_pc=0x0c06c9d4u; return 0; }
r[0]=r[13];
goto P_0c06c9d6;
P_0c06c9d6: /* original 4001, guest PC 0x0c06c9d6 */
if(!s->budget--) { s->failed_pc=0x0c06c9d6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c06c9d8;
P_0c06c9d8: /* original 66d3, guest PC 0x0c06c9d8 */
if(!s->budget--) { s->failed_pc=0x0c06c9d8u; return 0; }
r[6]=r[13];
goto P_0c06c9da;
P_0c06c9da: /* original 2709, guest PC 0x0c06c9da */
if(!s->budget--) { s->failed_pc=0x0c06c9dau; return 0; }
r[7]&=r[0];
goto P_0c06c9dc;
P_0c06c9dc: /* original d012, guest PC 0x0c06c9dc */
if(!s->budget--) { s->failed_pc=0x0c06c9dcu; return 0; }
r[0]=read(ram,0x0c06ca28u,4);
goto P_0c06c9de;
P_0c06c9de: /* original 4609, guest PC 0x0c06c9de */
if(!s->budget--) { s->failed_pc=0x0c06c9deu; return 0; }
r[6]>>=2;
goto P_0c06c9e0;
P_0c06c9e0: /* original 4600, guest PC 0x0c06c9e0 */
if(!s->budget--) { s->failed_pc=0x0c06c9e0u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c06c9e2;
P_0c06c9e2: /* original 046d, guest PC 0x0c06c9e2 */
if(!s->budget--) { s->failed_pc=0x0c06c9e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
goto P_0c06c9e4;
P_0c06c9e4: /* original 2778, guest PC 0x0c06c9e4 */
if(!s->budget--) { s->failed_pc=0x0c06c9e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c06c9e6;
P_0c06c9e6: /* original 8d23, guest PC 0x0c06c9e6 */
if(!s->budget--) { s->failed_pc=0x0c06c9e6u; return 0; }
cond=r[17]&1u;
r[5]=0x00000020u;
if(cond) { goto P_0c06ca30; }
goto P_0c06c9ea;
P_0c06c9e8: /* original e520, guest PC 0x0c06c9e8 */
if(!s->budget--) { s->failed_pc=0x0c06c9e8u; return 0; }
r[5]=0x00000020u;
goto P_0c06c9ea;
P_0c06c9ea: /* original d010, guest PC 0x0c06c9ea */
if(!s->budget--) { s->failed_pc=0x0c06c9eau; return 0; }
r[0]=read(ram,0x0c06ca2cu,4);
goto P_0c06c9ec;
P_0c06c9ec: /* original 3d52, guest PC 0x0c06c9ec */
if(!s->budget--) { s->failed_pc=0x0c06c9ecu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[5])!=0);
goto P_0c06c9ee;
P_0c06c9ee: /* original 8f61, guest PC 0x0c06c9ee */
if(!s->budget--) { s->failed_pc=0x0c06c9eeu; return 0; }
cond=r[17]&1u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
if(!cond) { goto P_0c06cab4; }
goto P_0c06c9f2;
P_0c06c9f0: /* original 046d, guest PC 0x0c06c9f0 */
if(!s->budget--) { s->failed_pc=0x0c06c9f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
goto P_0c06c9f2;
P_0c06c9f2: /* original 9904, guest PC 0x0c06c9f2 */
if(!s->budget--) { s->failed_pc=0x0c06c9f2u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c9feu,2);
goto P_0c06c9f4;
P_0c06c9f4: /* original a05f, guest PC 0x0c06c9f4 */
if(!s->budget--) { s->failed_pc=0x0c06c9f4u; return 0; }
goto P_0c06cab6;
P_0c06c9f6: /* original 0009, guest PC 0x0c06c9f6 */
if(!s->budget--) { s->failed_pc=0x0c06c9f6u; return 0; }
if(!vf3_matrix_family(0x0c06c9f8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06c9f8u; return 0; } return 1;
P_0c06ca30: /* original 3d52, guest PC 0x0c06ca30 */
if(!s->budget--) { s->failed_pc=0x0c06ca30u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[5])!=0);
goto P_0c06ca32;
P_0c06ca32: /* original 8b3f, guest PC 0x0c06ca32 */
if(!s->budget--) { s->failed_pc=0x0c06ca32u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06cab4; }
goto P_0c06ca34;
P_0c06ca34: /* original e228, guest PC 0x0c06ca34 */
if(!s->budget--) { s->failed_pc=0x0c06ca34u; return 0; }
r[2]=0x00000028u;
goto P_0c06ca36;
P_0c06ca36: /* original 9980, guest PC 0x0c06ca36 */
if(!s->budget--) { s->failed_pc=0x0c06ca36u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cb3au,2);
goto P_0c06ca38;
P_0c06ca38: /* original 3d26, guest PC 0x0c06ca38 */
if(!s->budget--) { s->failed_pc=0x0c06ca38u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>r[2])!=0);
goto P_0c06ca3a;
P_0c06ca3a: /* original 8b3c, guest PC 0x0c06ca3a */
if(!s->budget--) { s->failed_pc=0x0c06ca3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06cab6; }
goto P_0c06ca3c;
P_0c06ca3c: /* original e35a, guest PC 0x0c06ca3c */
if(!s->budget--) { s->failed_pc=0x0c06ca3cu; return 0; }
r[3]=0x0000005au;
goto P_0c06ca3e;
P_0c06ca3e: /* original 3d36, guest PC 0x0c06ca3e */
if(!s->budget--) { s->failed_pc=0x0c06ca3eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>r[3])!=0);
goto P_0c06ca40;
P_0c06ca40: /* original 8b39, guest PC 0x0c06ca40 */
if(!s->budget--) { s->failed_pc=0x0c06ca40u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06cab6; }
goto P_0c06ca42;
P_0c06ca42: /* original e464, guest PC 0x0c06ca42 */
if(!s->budget--) { s->failed_pc=0x0c06ca42u; return 0; }
r[4]=0x00000064u;
goto P_0c06ca44;
P_0c06ca44: /* original 997a, guest PC 0x0c06ca44 */
if(!s->budget--) { s->failed_pc=0x0c06ca44u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cb3cu,2);
goto P_0c06ca46;
P_0c06ca46: /* original 3d42, guest PC 0x0c06ca46 */
if(!s->budget--) { s->failed_pc=0x0c06ca46u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[4])!=0);
goto P_0c06ca48;
P_0c06ca48: /* original 8935, guest PC 0x0c06ca48 */
if(!s->budget--) { s->failed_pc=0x0c06ca48u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cab6; }
goto P_0c06ca4a;
P_0c06ca4a: /* original 2f42, guest PC 0x0c06ca4a */
if(!s->budget--) { s->failed_pc=0x0c06ca4au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06ca4c;
P_0c06ca4c: /* original bca4, guest PC 0x0c06ca4c */
if(!s->budget--) { s->failed_pc=0x0c06ca4cu; return 0; }
target=code_base|0x0c06c398u; r[16]=code_base|0x0c06ca50u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ca50u) { target=s->pc; goto dispatch; }
goto P_0c06ca50;
P_0c06ca4e: /* original 64a3, guest PC 0x0c06ca4e */
if(!s->budget--) { s->failed_pc=0x0c06ca4eu; return 0; }
r[4]=r[10];
goto P_0c06ca50;
P_0c06ca50: /* original 2008, guest PC 0x0c06ca50 */
if(!s->budget--) { s->failed_pc=0x0c06ca50u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06ca52;
P_0c06ca52: /* original 893f, guest PC 0x0c06ca52 */
if(!s->budget--) { s->failed_pc=0x0c06ca52u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cad4; }
goto P_0c06ca54;
P_0c06ca54: /* original 64e3, guest PC 0x0c06ca54 */
if(!s->budget--) { s->failed_pc=0x0c06ca54u; return 0; }
r[4]=r[14];
goto P_0c06ca56;
P_0c06ca56: /* original e300, guest PC 0x0c06ca56 */
if(!s->budget--) { s->failed_pc=0x0c06ca56u; return 0; }
r[3]=0x00000000u;
goto P_0c06ca58;
P_0c06ca58: /* original 4400, guest PC 0x0c06ca58 */
if(!s->budget--) { s->failed_pc=0x0c06ca58u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06ca5a;
P_0c06ca5a: /* original 2f36, guest PC 0x0c06ca5a */
if(!s->budget--) { s->failed_pc=0x0c06ca5au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ca5c;
P_0c06ca5c: /* original 956f, guest PC 0x0c06ca5c */
if(!s->budget--) { s->failed_pc=0x0c06ca5cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cb3eu,2);
goto P_0c06ca5e;
P_0c06ca5e: /* original 24bb, guest PC 0x0c06ca5e */
if(!s->budget--) { s->failed_pc=0x0c06ca5eu; return 0; }
r[4]|=r[11];
goto P_0c06ca60;
P_0c06ca60: /* original d239, guest PC 0x0c06ca60 */
if(!s->budget--) { s->failed_pc=0x0c06ca60u; return 0; }
r[2]=read(ram,0x0c06cb48u,4);
goto P_0c06ca62;
P_0c06ca62: /* original 6733, guest PC 0x0c06ca62 */
if(!s->budget--) { s->failed_pc=0x0c06ca62u; return 0; }
r[7]=r[3];
goto P_0c06ca64;
P_0c06ca64: /* original 420b, guest PC 0x0c06ca64 */
if(!s->budget--) { s->failed_pc=0x0c06ca64u; return 0; }
target=r[2];
r[16]=code_base|0x0c06ca68u;
r[6]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ca68u) { target=s->pc; goto dispatch; }
goto P_0c06ca68;
P_0c06ca66: /* original 66c3, guest PC 0x0c06ca66 */
if(!s->budget--) { s->failed_pc=0x0c06ca66u; return 0; }
r[6]=r[12];
goto P_0c06ca68;
P_0c06ca68: /* original 7efd, guest PC 0x0c06ca68 */
if(!s->budget--) { s->failed_pc=0x0c06ca68u; return 0; }
r[14]+=0xfffffffdu;
goto P_0c06ca6a;
P_0c06ca6a: /* original 9969, guest PC 0x0c06ca6a */
if(!s->budget--) { s->failed_pc=0x0c06ca6au; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cb40u,2);
goto P_0c06ca6c;
P_0c06ca6c: /* original 65e3, guest PC 0x0c06ca6c */
if(!s->budget--) { s->failed_pc=0x0c06ca6cu; return 0; }
r[5]=r[14];
goto P_0c06ca6e;
P_0c06ca6e: /* original 4500, guest PC 0x0c06ca6e */
if(!s->budget--) { s->failed_pc=0x0c06ca6eu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c06ca70;
P_0c06ca70: /* original da36, guest PC 0x0c06ca70 */
if(!s->budget--) { s->failed_pc=0x0c06ca70u; return 0; }
r[10]=read(ram,0x0c06cb4cu,4);
goto P_0c06ca72;
P_0c06ca72: /* original 6793, guest PC 0x0c06ca72 */
if(!s->budget--) { s->failed_pc=0x0c06ca72u; return 0; }
r[7]=r[9];
goto P_0c06ca74;
P_0c06ca74: /* original e601, guest PC 0x0c06ca74 */
if(!s->budget--) { s->failed_pc=0x0c06ca74u; return 0; }
r[6]=0x00000001u;
goto P_0c06ca76;
P_0c06ca76: /* original 7f04, guest PC 0x0c06ca76 */
if(!s->budget--) { s->failed_pc=0x0c06ca76u; return 0; }
r[15]+=0x00000004u;
goto P_0c06ca78;
P_0c06ca78: /* original 25bb, guest PC 0x0c06ca78 */
if(!s->budget--) { s->failed_pc=0x0c06ca78u; return 0; }
r[5]|=r[11];
goto P_0c06ca7a;
P_0c06ca7a: /* original 4a0b, guest PC 0x0c06ca7a */
if(!s->budget--) { s->failed_pc=0x0c06ca7au; return 0; }
target=r[10];
r[16]=code_base|0x0c06ca7eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ca7eu) { target=s->pc; goto dispatch; }
goto P_0c06ca7e;
P_0c06ca7c: /* original 64c3, guest PC 0x0c06ca7c */
if(!s->budget--) { s->failed_pc=0x0c06ca7cu; return 0; }
r[4]=r[12];
goto P_0c06ca7e;
P_0c06ca7e: /* original 65e3, guest PC 0x0c06ca7e */
if(!s->budget--) { s->failed_pc=0x0c06ca7eu; return 0; }
r[5]=r[14];
goto P_0c06ca80;
P_0c06ca80: /* original 7502, guest PC 0x0c06ca80 */
if(!s->budget--) { s->failed_pc=0x0c06ca80u; return 0; }
r[5]+=0x00000002u;
goto P_0c06ca82;
P_0c06ca82: /* original 4500, guest PC 0x0c06ca82 */
if(!s->budget--) { s->failed_pc=0x0c06ca82u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c06ca84;
P_0c06ca84: /* original 6793, guest PC 0x0c06ca84 */
if(!s->budget--) { s->failed_pc=0x0c06ca84u; return 0; }
r[7]=r[9];
goto P_0c06ca86;
P_0c06ca86: /* original e600, guest PC 0x0c06ca86 */
if(!s->budget--) { s->failed_pc=0x0c06ca86u; return 0; }
r[6]=0x00000000u;
goto P_0c06ca88;
P_0c06ca88: /* original 25bb, guest PC 0x0c06ca88 */
if(!s->budget--) { s->failed_pc=0x0c06ca88u; return 0; }
r[5]|=r[11];
goto P_0c06ca8a;
P_0c06ca8a: /* original 4a0b, guest PC 0x0c06ca8a */
if(!s->budget--) { s->failed_pc=0x0c06ca8au; return 0; }
target=r[10];
r[16]=code_base|0x0c06ca8eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ca8eu) { target=s->pc; goto dispatch; }
goto P_0c06ca8e;
P_0c06ca8c: /* original 64c3, guest PC 0x0c06ca8c */
if(!s->budget--) { s->failed_pc=0x0c06ca8cu; return 0; }
r[4]=r[12];
goto P_0c06ca8e;
P_0c06ca8e: /* original 65e3, guest PC 0x0c06ca8e */
if(!s->budget--) { s->failed_pc=0x0c06ca8eu; return 0; }
r[5]=r[14];
goto P_0c06ca90;
P_0c06ca90: /* original 7504, guest PC 0x0c06ca90 */
if(!s->budget--) { s->failed_pc=0x0c06ca90u; return 0; }
r[5]+=0x00000004u;
goto P_0c06ca92;
P_0c06ca92: /* original 4500, guest PC 0x0c06ca92 */
if(!s->budget--) { s->failed_pc=0x0c06ca92u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c06ca94;
P_0c06ca94: /* original 6793, guest PC 0x0c06ca94 */
if(!s->budget--) { s->failed_pc=0x0c06ca94u; return 0; }
r[7]=r[9];
goto P_0c06ca96;
P_0c06ca96: /* original e600, guest PC 0x0c06ca96 */
if(!s->budget--) { s->failed_pc=0x0c06ca96u; return 0; }
r[6]=0x00000000u;
goto P_0c06ca98;
P_0c06ca98: /* original 25bb, guest PC 0x0c06ca98 */
if(!s->budget--) { s->failed_pc=0x0c06ca98u; return 0; }
r[5]|=r[11];
goto P_0c06ca9a;
P_0c06ca9a: /* original 4a0b, guest PC 0x0c06ca9a */
if(!s->budget--) { s->failed_pc=0x0c06ca9au; return 0; }
target=r[10];
r[16]=code_base|0x0c06ca9eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ca9eu) { target=s->pc; goto dispatch; }
goto P_0c06ca9e;
P_0c06ca9c: /* original 64c3, guest PC 0x0c06ca9c */
if(!s->budget--) { s->failed_pc=0x0c06ca9cu; return 0; }
r[4]=r[12];
goto P_0c06ca9e;
P_0c06ca9e: /* original 65e3, guest PC 0x0c06ca9e */
if(!s->budget--) { s->failed_pc=0x0c06ca9eu; return 0; }
r[5]=r[14];
goto P_0c06caa0;
P_0c06caa0: /* original 7513, guest PC 0x0c06caa0 */
if(!s->budget--) { s->failed_pc=0x0c06caa0u; return 0; }
r[5]+=0x00000013u;
goto P_0c06caa2;
P_0c06caa2: /* original 66f2, guest PC 0x0c06caa2 */
if(!s->budget--) { s->failed_pc=0x0c06caa2u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c06caa4;
P_0c06caa4: /* original 4500, guest PC 0x0c06caa4 */
if(!s->budget--) { s->failed_pc=0x0c06caa4u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c06caa6;
P_0c06caa6: /* original 6793, guest PC 0x0c06caa6 */
if(!s->budget--) { s->failed_pc=0x0c06caa6u; return 0; }
r[7]=r[9];
goto P_0c06caa8;
P_0c06caa8: /* original 25bb, guest PC 0x0c06caa8 */
if(!s->budget--) { s->failed_pc=0x0c06caa8u; return 0; }
r[5]|=r[11];
goto P_0c06caaa;
P_0c06caaa: /* original 36d8, guest PC 0x0c06caaa */
if(!s->budget--) { s->failed_pc=0x0c06caaau; return 0; }
r[6]-=r[13];
goto P_0c06caac;
P_0c06caac: /* original 4a0b, guest PC 0x0c06caac */
if(!s->budget--) { s->failed_pc=0x0c06caacu; return 0; }
target=r[10];
r[16]=code_base|0x0c06cab0u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cab0u) { target=s->pc; goto dispatch; }
goto P_0c06cab0;
P_0c06caae: /* original 64c3, guest PC 0x0c06caae */
if(!s->budget--) { s->failed_pc=0x0c06caaeu; return 0; }
r[4]=r[12];
goto P_0c06cab0;
P_0c06cab0: /* original a010, guest PC 0x0c06cab0 */
if(!s->budget--) { s->failed_pc=0x0c06cab0u; return 0; }
goto P_0c06cad4;
P_0c06cab2: /* original 0009, guest PC 0x0c06cab2 */
if(!s->budget--) { s->failed_pc=0x0c06cab2u; return 0; }
goto P_0c06cab4;
P_0c06cab4: /* original 694d, guest PC 0x0c06cab4 */
if(!s->budget--) { s->failed_pc=0x0c06cab4u; return 0; }
r[9]=r[4]&65535u;
goto P_0c06cab6;
P_0c06cab6: /* original 4e00, guest PC 0x0c06cab6 */
if(!s->budget--) { s->failed_pc=0x0c06cab6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c06cab8;
P_0c06cab8: /* original 2ebb, guest PC 0x0c06cab8 */
if(!s->budget--) { s->failed_pc=0x0c06cab8u; return 0; }
r[14]|=r[11];
goto P_0c06caba;
P_0c06caba: /* original bc6d, guest PC 0x0c06caba */
if(!s->budget--) { s->failed_pc=0x0c06cabau; return 0; }
target=code_base|0x0c06c398u; r[16]=code_base|0x0c06cabeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cabeu) { target=s->pc; goto dispatch; }
goto P_0c06cabe;
P_0c06cabc: /* original 64e3, guest PC 0x0c06cabc */
if(!s->budget--) { s->failed_pc=0x0c06cabcu; return 0; }
r[4]=r[14];
goto P_0c06cabe;
P_0c06cabe: /* original 2008, guest PC 0x0c06cabe */
if(!s->budget--) { s->failed_pc=0x0c06cabeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06cac0;
P_0c06cac0: /* original 8908, guest PC 0x0c06cac0 */
if(!s->budget--) { s->failed_pc=0x0c06cac0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cad4; }
goto P_0c06cac2;
P_0c06cac2: /* original e300, guest PC 0x0c06cac2 */
if(!s->budget--) { s->failed_pc=0x0c06cac2u; return 0; }
r[3]=0x00000000u;
goto P_0c06cac4;
P_0c06cac4: /* original 6593, guest PC 0x0c06cac4 */
if(!s->budget--) { s->failed_pc=0x0c06cac4u; return 0; }
r[5]=r[9];
goto P_0c06cac6;
P_0c06cac6: /* original 66c3, guest PC 0x0c06cac6 */
if(!s->budget--) { s->failed_pc=0x0c06cac6u; return 0; }
r[6]=r[12];
goto P_0c06cac8;
P_0c06cac8: /* original 2f36, guest PC 0x0c06cac8 */
if(!s->budget--) { s->failed_pc=0x0c06cac8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06caca;
P_0c06caca: /* original d21f, guest PC 0x0c06caca */
if(!s->budget--) { s->failed_pc=0x0c06cacau; return 0; }
r[2]=read(ram,0x0c06cb48u,4);
goto P_0c06cacc;
P_0c06cacc: /* original 6733, guest PC 0x0c06cacc */
if(!s->budget--) { s->failed_pc=0x0c06caccu; return 0; }
r[7]=r[3];
goto P_0c06cace;
P_0c06cace: /* original 420b, guest PC 0x0c06cace */
if(!s->budget--) { s->failed_pc=0x0c06caceu; return 0; }
target=r[2];
r[16]=code_base|0x0c06cad2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cad2u) { target=s->pc; goto dispatch; }
goto P_0c06cad2;
P_0c06cad0: /* original 64e3, guest PC 0x0c06cad0 */
if(!s->budget--) { s->failed_pc=0x0c06cad0u; return 0; }
r[4]=r[14];
goto P_0c06cad2;
P_0c06cad2: /* original 7f04, guest PC 0x0c06cad2 */
if(!s->budget--) { s->failed_pc=0x0c06cad2u; return 0; }
r[15]+=0x00000004u;
goto P_0c06cad4;
P_0c06cad4: /* original 7f04, guest PC 0x0c06cad4 */
if(!s->budget--) { s->failed_pc=0x0c06cad4u; return 0; }
r[15]+=0x00000004u;
goto P_0c06cad6;
P_0c06cad6: /* original 4f26, guest PC 0x0c06cad6 */
if(!s->budget--) { s->failed_pc=0x0c06cad6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06cad8;
P_0c06cad8: /* original 69f6, guest PC 0x0c06cad8 */
if(!s->budget--) { s->failed_pc=0x0c06cad8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06cada;
P_0c06cada: /* original 6af6, guest PC 0x0c06cada */
if(!s->budget--) { s->failed_pc=0x0c06cadau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06cadc;
P_0c06cadc: /* original 6bf6, guest PC 0x0c06cadc */
if(!s->budget--) { s->failed_pc=0x0c06cadcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06cade;
P_0c06cade: /* original 6cf6, guest PC 0x0c06cade */
if(!s->budget--) { s->failed_pc=0x0c06cadeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06cae0;
P_0c06cae0: /* original 6df6, guest PC 0x0c06cae0 */
if(!s->budget--) { s->failed_pc=0x0c06cae0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06cae2;
P_0c06cae2: /* original 000b, guest PC 0x0c06cae2 */
if(!s->budget--) { s->failed_pc=0x0c06cae2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06cae4: /* original 6ef6, guest PC 0x0c06cae4 */
if(!s->budget--) { s->failed_pc=0x0c06cae4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06cae6u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
