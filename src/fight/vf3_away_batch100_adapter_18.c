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
int vf3_away_batch100_adapter_18(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06d9d4u: goto P_0c06d9d4;
case 0x0c06d9d6u: goto P_0c06d9d6;
case 0x0c06d9d8u: goto P_0c06d9d8;
case 0x0c06d9dau: goto P_0c06d9da;
case 0x0c06d9dcu: goto P_0c06d9dc;
case 0x0c06d9deu: goto P_0c06d9de;
case 0x0c06d9e0u: goto P_0c06d9e0;
case 0x0c06d9e2u: goto P_0c06d9e2;
case 0x0c06d9e4u: goto P_0c06d9e4;
case 0x0c06d9e6u: goto P_0c06d9e6;
case 0x0c06d9e8u: goto P_0c06d9e8;
case 0x0c06d9eau: goto P_0c06d9ea;
case 0x0c06d9ecu: goto P_0c06d9ec;
case 0x0c06d9eeu: goto P_0c06d9ee;
case 0x0c06d9f0u: goto P_0c06d9f0;
case 0x0c06d9f2u: goto P_0c06d9f2;
case 0x0c06d9f4u: goto P_0c06d9f4;
case 0x0c06d9f6u: goto P_0c06d9f6;
case 0x0c06d9f8u: goto P_0c06d9f8;
case 0x0c06d9fau: goto P_0c06d9fa;
case 0x0c06d9fcu: goto P_0c06d9fc;
case 0x0c06d9feu: goto P_0c06d9fe;
case 0x0c06da00u: goto P_0c06da00;
case 0x0c06da02u: goto P_0c06da02;
case 0x0c06da04u: goto P_0c06da04;
case 0x0c06da06u: goto P_0c06da06;
case 0x0c06da08u: goto P_0c06da08;
case 0x0c06da0au: goto P_0c06da0a;
case 0x0c06da0cu: goto P_0c06da0c;
case 0x0c06da0eu: goto P_0c06da0e;
case 0x0c06da10u: goto P_0c06da10;
case 0x0c06da12u: goto P_0c06da12;
case 0x0c06da14u: goto P_0c06da14;
case 0x0c06da16u: goto P_0c06da16;
case 0x0c06da18u: goto P_0c06da18;
case 0x0c06da1au: goto P_0c06da1a;
case 0x0c06da1cu: goto P_0c06da1c;
case 0x0c06da1eu: goto P_0c06da1e;
case 0x0c06da20u: goto P_0c06da20;
case 0x0c06da22u: goto P_0c06da22;
case 0x0c06da24u: goto P_0c06da24;
case 0x0c06da26u: goto P_0c06da26;
case 0x0c06da28u: goto P_0c06da28;
case 0x0c06da2au: goto P_0c06da2a;
case 0x0c06da2cu: goto P_0c06da2c;
case 0x0c06da2eu: goto P_0c06da2e;
case 0x0c06da30u: goto P_0c06da30;
case 0x0c06da32u: goto P_0c06da32;
case 0x0c06da34u: goto P_0c06da34;
case 0x0c06da36u: goto P_0c06da36;
case 0x0c06da38u: goto P_0c06da38;
case 0x0c06da3au: goto P_0c06da3a;
case 0x0c06da3cu: goto P_0c06da3c;
case 0x0c06da3eu: goto P_0c06da3e;
case 0x0c06da40u: goto P_0c06da40;
case 0x0c06da42u: goto P_0c06da42;
case 0x0c06da44u: goto P_0c06da44;
case 0x0c06da46u: goto P_0c06da46;
case 0x0c06da48u: goto P_0c06da48;
case 0x0c06da4au: goto P_0c06da4a;
case 0x0c06da4cu: goto P_0c06da4c;
case 0x0c06da4eu: goto P_0c06da4e;
case 0x0c06da50u: goto P_0c06da50;
case 0x0c06da52u: goto P_0c06da52;
case 0x0c06da54u: goto P_0c06da54;
case 0x0c06da56u: goto P_0c06da56;
case 0x0c06da58u: goto P_0c06da58;
case 0x0c06da5au: goto P_0c06da5a;
case 0x0c06da5cu: goto P_0c06da5c;
case 0x0c06da5eu: goto P_0c06da5e;
case 0x0c06da60u: goto P_0c06da60;
case 0x0c06da62u: goto P_0c06da62;
case 0x0c06da64u: goto P_0c06da64;
case 0x0c06da66u: goto P_0c06da66;
case 0x0c06da68u: goto P_0c06da68;
case 0x0c06da6au: goto P_0c06da6a;
case 0x0c06da6cu: goto P_0c06da6c;
case 0x0c06da6eu: goto P_0c06da6e;
case 0x0c06da70u: goto P_0c06da70;
case 0x0c06da72u: goto P_0c06da72;
case 0x0c06da74u: goto P_0c06da74;
case 0x0c06da76u: goto P_0c06da76;
case 0x0c06da78u: goto P_0c06da78;
case 0x0c06da7au: goto P_0c06da7a;
case 0x0c07a7e8u: goto P_0c07a7e8;
case 0x0c07a7eau: goto P_0c07a7ea;
case 0x0c07a7ecu: goto P_0c07a7ec;
case 0x0c07a7eeu: goto P_0c07a7ee;
case 0x0c07a7f0u: goto P_0c07a7f0;
case 0x0c07a7f2u: goto P_0c07a7f2;
case 0x0c07a7f4u: goto P_0c07a7f4;
case 0x0c07a7f6u: goto P_0c07a7f6;
case 0x0c07a7f8u: goto P_0c07a7f8;
case 0x0c07a7fau: goto P_0c07a7fa;
case 0x0c07a7fcu: goto P_0c07a7fc;
case 0x0c07a7feu: goto P_0c07a7fe;
case 0x0c07a800u: goto P_0c07a800;
case 0x0c07a802u: goto P_0c07a802;
case 0x0c07a804u: goto P_0c07a804;
case 0x0c07a806u: goto P_0c07a806;
case 0x0c07a808u: goto P_0c07a808;
case 0x0c07a80au: goto P_0c07a80a;
case 0x0c07a80cu: goto P_0c07a80c;
case 0x0c07a80eu: goto P_0c07a80e;
case 0x0c07a810u: goto P_0c07a810;
case 0x0c07a812u: goto P_0c07a812;
case 0x0c07a814u: goto P_0c07a814;
case 0x0c07a816u: goto P_0c07a816;
case 0x0c07a818u: goto P_0c07a818;
case 0x0c07a81au: goto P_0c07a81a;
case 0x0c07a81cu: goto P_0c07a81c;
case 0x0c07a81eu: goto P_0c07a81e;
case 0x0c07a820u: goto P_0c07a820;
case 0x0c07a822u: goto P_0c07a822;
case 0x0c07a824u: goto P_0c07a824;
case 0x0c07a826u: goto P_0c07a826;
case 0x0c07a828u: goto P_0c07a828;
case 0x0c07a82au: goto P_0c07a82a;
case 0x0c07a82cu: goto P_0c07a82c;
case 0x0c07a82eu: goto P_0c07a82e;
case 0x0c07a830u: goto P_0c07a830;
case 0x0c07a832u: goto P_0c07a832;
case 0x0c07a834u: goto P_0c07a834;
case 0x0c07a836u: goto P_0c07a836;
case 0x0c07a838u: goto P_0c07a838;
case 0x0c07a83au: goto P_0c07a83a;
case 0x0c07a83cu: goto P_0c07a83c;
case 0x0c07a83eu: goto P_0c07a83e;
case 0x0c07a840u: goto P_0c07a840;
case 0x0c07a842u: goto P_0c07a842;
case 0x0c07a844u: goto P_0c07a844;
case 0x0c07a846u: goto P_0c07a846;
case 0x0c07a848u: goto P_0c07a848;
case 0x0c07a84au: goto P_0c07a84a;
case 0x0c07a84cu: goto P_0c07a84c;
case 0x0c07a84eu: goto P_0c07a84e;
case 0x0c07a850u: goto P_0c07a850;
case 0x0c07a852u: goto P_0c07a852;
case 0x0c07a854u: goto P_0c07a854;
case 0x0c07a856u: goto P_0c07a856;
case 0x0c07a858u: goto P_0c07a858;
case 0x0c07a85au: goto P_0c07a85a;
case 0x0c07a85cu: goto P_0c07a85c;
case 0x0c07a85eu: goto P_0c07a85e;
case 0x0c07a860u: goto P_0c07a860;
case 0x0c07a862u: goto P_0c07a862;
case 0x0c07a864u: goto P_0c07a864;
case 0x0c07a866u: goto P_0c07a866;
case 0x0c07a868u: goto P_0c07a868;
case 0x0c07a86au: goto P_0c07a86a;
case 0x0c07a86cu: goto P_0c07a86c;
case 0x0c07a86eu: goto P_0c07a86e;
case 0x0c07a870u: goto P_0c07a870;
case 0x0c07a872u: goto P_0c07a872;
case 0x0c07a874u: goto P_0c07a874;
case 0x0c07a876u: goto P_0c07a876;
case 0x0c07a878u: goto P_0c07a878;
case 0x0c07a87au: goto P_0c07a87a;
case 0x0c07a87cu: goto P_0c07a87c;
case 0x0c07a87eu: goto P_0c07a87e;
case 0x0c07a880u: goto P_0c07a880;
case 0x0c07a882u: goto P_0c07a882;
case 0x0c07a884u: goto P_0c07a884;
case 0x0c07a886u: goto P_0c07a886;
case 0x0c07a888u: goto P_0c07a888;
case 0x0c07a88au: goto P_0c07a88a;
case 0x0c07a88cu: goto P_0c07a88c;
case 0x0c07a88eu: goto P_0c07a88e;
case 0x0c07a890u: goto P_0c07a890;
case 0x0c07a892u: goto P_0c07a892;
case 0x0c07a894u: goto P_0c07a894;
case 0x0c07a896u: goto P_0c07a896;
case 0x0c07a898u: goto P_0c07a898;
case 0x0c07a89au: goto P_0c07a89a;
case 0x0c07a89cu: goto P_0c07a89c;
case 0x0c07a89eu: goto P_0c07a89e;
case 0x0c07a8a0u: goto P_0c07a8a0;
case 0x0c07a8a2u: goto P_0c07a8a2;
case 0x0c07a8a4u: goto P_0c07a8a4;
case 0x0c07a8a6u: goto P_0c07a8a6;
case 0x0c07a8a8u: goto P_0c07a8a8;
case 0x0c07a8aau: goto P_0c07a8aa;
case 0x0c07a8acu: goto P_0c07a8ac;
case 0x0c07a8aeu: goto P_0c07a8ae;
case 0x0c07a8b0u: goto P_0c07a8b0;
case 0x0c07a8b2u: goto P_0c07a8b2;
case 0x0c07a8b4u: goto P_0c07a8b4;
case 0x0c07a8b6u: goto P_0c07a8b6;
case 0x0c07a8b8u: goto P_0c07a8b8;
case 0x0c07a8bau: goto P_0c07a8ba;
case 0x0c07a8bcu: goto P_0c07a8bc;
case 0x0c07a8beu: goto P_0c07a8be;
case 0x0c07a8c0u: goto P_0c07a8c0;
case 0x0c07a8c2u: goto P_0c07a8c2;
case 0x0c07a8c4u: goto P_0c07a8c4;
case 0x0c07a8c6u: goto P_0c07a8c6;
case 0x0c07a8c8u: goto P_0c07a8c8;
case 0x0c07a8cau: goto P_0c07a8ca;
case 0x0c07a8ccu: goto P_0c07a8cc;
case 0x0c07a8ceu: goto P_0c07a8ce;
case 0x0c07a8d0u: goto P_0c07a8d0;
case 0x0c07a8d2u: goto P_0c07a8d2;
case 0x0c07a8d4u: goto P_0c07a8d4;
case 0x0c07a8d6u: goto P_0c07a8d6;
case 0x0c07a8d8u: goto P_0c07a8d8;
case 0x0c07a8dau: goto P_0c07a8da;
case 0x0c07a8dcu: goto P_0c07a8dc;
case 0x0c07a8deu: goto P_0c07a8de;
case 0x0c07a8e0u: goto P_0c07a8e0;
case 0x0c07a8e2u: goto P_0c07a8e2;
case 0x0c07a8e4u: goto P_0c07a8e4;
case 0x0c07a8e6u: goto P_0c07a8e6;
case 0x0c07a8e8u: goto P_0c07a8e8;
case 0x0c07a8eau: goto P_0c07a8ea;
case 0x0c07a8ecu: goto P_0c07a8ec;
case 0x0c07a8eeu: goto P_0c07a8ee;
case 0x0c07a8f0u: goto P_0c07a8f0;
case 0x0c07a8f2u: goto P_0c07a8f2;
case 0x0c07a8f4u: goto P_0c07a8f4;
case 0x0c07a8f6u: goto P_0c07a8f6;
case 0x0c07a8f8u: goto P_0c07a8f8;
case 0x0c07a8fau: goto P_0c07a8fa;
case 0x0c07a8fcu: goto P_0c07a8fc;
case 0x0c07a8feu: goto P_0c07a8fe;
case 0x0c07a900u: goto P_0c07a900;
case 0x0c07a902u: goto P_0c07a902;
case 0x0c07a904u: goto P_0c07a904;
case 0x0c07a906u: goto P_0c07a906;
case 0x0c07a908u: goto P_0c07a908;
case 0x0c07a90au: goto P_0c07a90a;
case 0x0c07a90cu: goto P_0c07a90c;
case 0x0c07a90eu: goto P_0c07a90e;
case 0x0c07a910u: goto P_0c07a910;
case 0x0c07a912u: goto P_0c07a912;
case 0x0c07a914u: goto P_0c07a914;
case 0x0c07a916u: goto P_0c07a916;
case 0x0c07a918u: goto P_0c07a918;
case 0x0c07a91au: goto P_0c07a91a;
case 0x0c07a91cu: goto P_0c07a91c;
case 0x0c07a91eu: goto P_0c07a91e;
case 0x0c07a920u: goto P_0c07a920;
case 0x0c07a922u: goto P_0c07a922;
case 0x0c07a924u: goto P_0c07a924;
case 0x0c07a926u: goto P_0c07a926;
case 0x0c07a928u: goto P_0c07a928;
case 0x0c07a92au: goto P_0c07a92a;
case 0x0c07a92cu: goto P_0c07a92c;
case 0x0c07a92eu: goto P_0c07a92e;
case 0x0c07a930u: goto P_0c07a930;
case 0x0c07a932u: goto P_0c07a932;
case 0x0c07a934u: goto P_0c07a934;
case 0x0c07a936u: goto P_0c07a936;
case 0x0c07a938u: goto P_0c07a938;
case 0x0c07a93au: goto P_0c07a93a;
case 0x0c07a93cu: goto P_0c07a93c;
case 0x0c07a93eu: goto P_0c07a93e;
case 0x0c07a940u: goto P_0c07a940;
case 0x0c07a942u: goto P_0c07a942;
case 0x0c07a944u: goto P_0c07a944;
case 0x0c07a946u: goto P_0c07a946;
case 0x0c07a948u: goto P_0c07a948;
case 0x0c07a94au: goto P_0c07a94a;
case 0x0c07a94cu: goto P_0c07a94c;
case 0x0c07a94eu: goto P_0c07a94e;
case 0x0c07a950u: goto P_0c07a950;
case 0x0c07a952u: goto P_0c07a952;
case 0x0c07a954u: goto P_0c07a954;
case 0x0c07a956u: goto P_0c07a956;
case 0x0c07a958u: goto P_0c07a958;
case 0x0c07a95au: goto P_0c07a95a;
case 0x0c07a95cu: goto P_0c07a95c;
case 0x0c07a95eu: goto P_0c07a95e;
case 0x0c07a960u: goto P_0c07a960;
case 0x0c07a962u: goto P_0c07a962;
case 0x0c07a964u: goto P_0c07a964;
case 0x0c07a966u: goto P_0c07a966;
case 0x0c07a968u: goto P_0c07a968;
case 0x0c07a96au: goto P_0c07a96a;
case 0x0c07a96cu: goto P_0c07a96c;
case 0x0c07a96eu: goto P_0c07a96e;
case 0x0c07a970u: goto P_0c07a970;
case 0x0c07a972u: goto P_0c07a972;
case 0x0c07a974u: goto P_0c07a974;
case 0x0c07a976u: goto P_0c07a976;
case 0x0c07a978u: goto P_0c07a978;
case 0x0c07a97au: goto P_0c07a97a;
case 0x0c07a97cu: goto P_0c07a97c;
case 0x0c07a97eu: goto P_0c07a97e;
case 0x0c07a980u: goto P_0c07a980;
case 0x0c07a982u: goto P_0c07a982;
case 0x0c07a984u: goto P_0c07a984;
case 0x0c07a986u: goto P_0c07a986;
case 0x0c07a988u: goto P_0c07a988;
case 0x0c07a98au: goto P_0c07a98a;
case 0x0c07a98cu: goto P_0c07a98c;
case 0x0c07a98eu: goto P_0c07a98e;
case 0x0c07a990u: goto P_0c07a990;
case 0x0c07a992u: goto P_0c07a992;
case 0x0c07a994u: goto P_0c07a994;
case 0x0c07a996u: goto P_0c07a996;
case 0x0c07a998u: goto P_0c07a998;
case 0x0c07a99au: goto P_0c07a99a;
case 0x0c07a99cu: goto P_0c07a99c;
case 0x0c07a99eu: goto P_0c07a99e;
case 0x0c07a9a0u: goto P_0c07a9a0;
case 0x0c07a9a2u: goto P_0c07a9a2;
case 0x0c07a9a4u: goto P_0c07a9a4;
case 0x0c07a9a6u: goto P_0c07a9a6;
case 0x0c07a9a8u: goto P_0c07a9a8;
case 0x0c07a9aau: goto P_0c07a9aa;
case 0x0c07a9acu: goto P_0c07a9ac;
case 0x0c07a9aeu: goto P_0c07a9ae;
case 0x0c07a9b0u: goto P_0c07a9b0;
case 0x0c07a9b2u: goto P_0c07a9b2;
case 0x0c07a9f8u: goto P_0c07a9f8;
case 0x0c07a9fau: goto P_0c07a9fa;
case 0x0c07a9fcu: goto P_0c07a9fc;
case 0x0c07a9feu: goto P_0c07a9fe;
case 0x0c07aa00u: goto P_0c07aa00;
case 0x0c07aa02u: goto P_0c07aa02;
case 0x0c07aa04u: goto P_0c07aa04;
case 0x0c07aa06u: goto P_0c07aa06;
case 0x0c07aa08u: goto P_0c07aa08;
case 0x0c07aa0au: goto P_0c07aa0a;
case 0x0c07aa0cu: goto P_0c07aa0c;
case 0x0c07aa0eu: goto P_0c07aa0e;
case 0x0c07aa10u: goto P_0c07aa10;
case 0x0c07aa12u: goto P_0c07aa12;
case 0x0c07aa14u: goto P_0c07aa14;
case 0x0c07aa16u: goto P_0c07aa16;
case 0x0c07aa18u: goto P_0c07aa18;
case 0x0c07aa1au: goto P_0c07aa1a;
case 0x0c07aa1cu: goto P_0c07aa1c;
case 0x0c07aa1eu: goto P_0c07aa1e;
case 0x0c07aa20u: goto P_0c07aa20;
case 0x0c07aa22u: goto P_0c07aa22;
case 0x0c07aa24u: goto P_0c07aa24;
case 0x0c07aa26u: goto P_0c07aa26;
case 0x0c07aa28u: goto P_0c07aa28;
case 0x0c07aa2au: goto P_0c07aa2a;
case 0x0c07aa2cu: goto P_0c07aa2c;
case 0x0c07aa2eu: goto P_0c07aa2e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06d9d4: /* original 2fe6, guest PC 0x0c06d9d4 */
if(!s->budget--) { s->failed_pc=0x0c06d9d4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06d9d6;
P_0c06d9d6: /* original 6e43, guest PC 0x0c06d9d6 */
if(!s->budget--) { s->failed_pc=0x0c06d9d6u; return 0; }
r[14]=r[4];
goto P_0c06d9d8;
P_0c06d9d8: /* original 2fd6, guest PC 0x0c06d9d8 */
if(!s->budget--) { s->failed_pc=0x0c06d9d8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06d9da;
P_0c06d9da: /* original ed00, guest PC 0x0c06d9da */
if(!s->budget--) { s->failed_pc=0x0c06d9dau; return 0; }
r[13]=0x00000000u;
goto P_0c06d9dc;
P_0c06d9dc: /* original 2fc6, guest PC 0x0c06d9dc */
if(!s->budget--) { s->failed_pc=0x0c06d9dcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06d9de;
P_0c06d9de: /* original 6cd3, guest PC 0x0c06d9de */
if(!s->budget--) { s->failed_pc=0x0c06d9deu; return 0; }
r[12]=r[13];
goto P_0c06d9e0;
P_0c06d9e0: /* original 4f22, guest PC 0x0c06d9e0 */
if(!s->budget--) { s->failed_pc=0x0c06d9e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06d9e2;
P_0c06d9e2: /* original d42b, guest PC 0x0c06d9e2 */
if(!s->budget--) { s->failed_pc=0x0c06d9e2u; return 0; }
r[4]=read(ram,0x0c06da90u,4);
goto P_0c06d9e4;
P_0c06d9e4: /* original 67d3, guest PC 0x0c06d9e4 */
if(!s->budget--) { s->failed_pc=0x0c06d9e4u; return 0; }
r[7]=r[13];
goto P_0c06d9e6;
P_0c06d9e6: /* original d32b, guest PC 0x0c06d9e6 */
if(!s->budget--) { s->failed_pc=0x0c06d9e6u; return 0; }
r[3]=read(ram,0x0c06da94u,4);
goto P_0c06d9e8;
P_0c06d9e8: /* original 66d3, guest PC 0x0c06d9e8 */
if(!s->budget--) { s->failed_pc=0x0c06d9e8u; return 0; }
r[6]=r[13];
goto P_0c06d9ea;
P_0c06d9ea: /* original 430b, guest PC 0x0c06d9ea */
if(!s->budget--) { s->failed_pc=0x0c06d9eau; return 0; }
target=r[3];
r[16]=code_base|0x0c06d9eeu;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d9eeu) { target=s->pc; goto dispatch; }
goto P_0c06d9ee;
P_0c06d9ec: /* original 65d3, guest PC 0x0c06d9ec */
if(!s->budget--) { s->failed_pc=0x0c06d9ecu; return 0; }
r[5]=r[13];
goto P_0c06d9ee;
P_0c06d9ee: /* original d42a, guest PC 0x0c06d9ee */
if(!s->budget--) { s->failed_pc=0x0c06d9eeu; return 0; }
r[4]=read(ram,0x0c06da98u,4);
goto P_0c06d9f0;
P_0c06d9f0: /* original 67c3, guest PC 0x0c06d9f0 */
if(!s->budget--) { s->failed_pc=0x0c06d9f0u; return 0; }
r[7]=r[12];
goto P_0c06d9f2;
P_0c06d9f2: /* original d228, guest PC 0x0c06d9f2 */
if(!s->budget--) { s->failed_pc=0x0c06d9f2u; return 0; }
r[2]=read(ram,0x0c06da94u,4);
goto P_0c06d9f4;
P_0c06d9f4: /* original 66c3, guest PC 0x0c06d9f4 */
if(!s->budget--) { s->failed_pc=0x0c06d9f4u; return 0; }
r[6]=r[12];
goto P_0c06d9f6;
P_0c06d9f6: /* original 420b, guest PC 0x0c06d9f6 */
if(!s->budget--) { s->failed_pc=0x0c06d9f6u; return 0; }
target=r[2];
r[16]=code_base|0x0c06d9fau;
r[5]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d9fau) { target=s->pc; goto dispatch; }
goto P_0c06d9fa;
P_0c06d9f8: /* original 65c3, guest PC 0x0c06d9f8 */
if(!s->budget--) { s->failed_pc=0x0c06d9f8u; return 0; }
r[5]=r[12];
goto P_0c06d9fa;
P_0c06d9fa: /* original 9045, guest PC 0x0c06d9fa */
if(!s->budget--) { s->failed_pc=0x0c06d9fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06da88u,2);
goto P_0c06d9fc;
P_0c06d9fc: /* original f59d, guest PC 0x0c06d9fc */
if(!s->budget--) { s->failed_pc=0x0c06d9fcu; return 0; }
fr[5]=0x3f800000u;
goto P_0c06d9fe;
P_0c06d9fe: /* original f45c, guest PC 0x0c06d9fe */
if(!s->budget--) { s->failed_pc=0x0c06d9feu; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c06da00;
P_0c06da00: /* original fe47, guest PC 0x0c06da00 */
if(!s->budget--) { s->failed_pc=0x0c06da00u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c06da02;
P_0c06da02: /* original 9042, guest PC 0x0c06da02 */
if(!s->budget--) { s->failed_pc=0x0c06da02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06da8au,2);
goto P_0c06da04;
P_0c06da04: /* original fe47, guest PC 0x0c06da04 */
if(!s->budget--) { s->failed_pc=0x0c06da04u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c06da06;
P_0c06da06: /* original 9041, guest PC 0x0c06da06 */
if(!s->budget--) { s->failed_pc=0x0c06da06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06da8cu,2);
goto P_0c06da08;
P_0c06da08: /* original fe47, guest PC 0x0c06da08 */
if(!s->budget--) { s->failed_pc=0x0c06da08u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c06da0a;
P_0c06da0a: /* original 7028, guest PC 0x0c06da0a */
if(!s->budget--) { s->failed_pc=0x0c06da0au; return 0; }
r[0]+=0x00000028u;
goto P_0c06da0c;
P_0c06da0c: /* original fe47, guest PC 0x0c06da0c */
if(!s->budget--) { s->failed_pc=0x0c06da0cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c06da0e;
P_0c06da0e: /* original 70dc, guest PC 0x0c06da0e */
if(!s->budget--) { s->failed_pc=0x0c06da0eu; return 0; }
r[0]+=0xffffffdcu;
goto P_0c06da10;
P_0c06da10: /* original f48d, guest PC 0x0c06da10 */
if(!s->budget--) { s->failed_pc=0x0c06da10u; return 0; }
fr[4]=0;
goto P_0c06da12;
P_0c06da12: /* original f64c, guest PC 0x0c06da12 */
if(!s->budget--) { s->failed_pc=0x0c06da12u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c06da14;
P_0c06da14: /* original f74c, guest PC 0x0c06da14 */
if(!s->budget--) { s->failed_pc=0x0c06da14u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c06da16;
P_0c06da16: /* original fe67, guest PC 0x0c06da16 */
if(!s->budget--) { s->failed_pc=0x0c06da16u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c06da18;
P_0c06da18: /* original 7004, guest PC 0x0c06da18 */
if(!s->budget--) { s->failed_pc=0x0c06da18u; return 0; }
r[0]+=0x00000004u;
goto P_0c06da1a;
P_0c06da1a: /* original fe67, guest PC 0x0c06da1a */
if(!s->budget--) { s->failed_pc=0x0c06da1au; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c06da1c;
P_0c06da1c: /* original 7024, guest PC 0x0c06da1c */
if(!s->budget--) { s->failed_pc=0x0c06da1cu; return 0; }
r[0]+=0x00000024u;
goto P_0c06da1e;
P_0c06da1e: /* original fe67, guest PC 0x0c06da1e */
if(!s->budget--) { s->failed_pc=0x0c06da1eu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c06da20;
P_0c06da20: /* original 7004, guest PC 0x0c06da20 */
if(!s->budget--) { s->failed_pc=0x0c06da20u; return 0; }
r[0]+=0x00000004u;
goto P_0c06da22;
P_0c06da22: /* original fe67, guest PC 0x0c06da22 */
if(!s->budget--) { s->failed_pc=0x0c06da22u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c06da24;
P_0c06da24: /* original 70dc, guest PC 0x0c06da24 */
if(!s->budget--) { s->failed_pc=0x0c06da24u; return 0; }
r[0]+=0xffffffdcu;
goto P_0c06da26;
P_0c06da26: /* original 0ec4, guest PC 0x0c06da26 */
if(!s->budget--) { s->failed_pc=0x0c06da26u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06da28;
P_0c06da28: /* original 7001, guest PC 0x0c06da28 */
if(!s->budget--) { s->failed_pc=0x0c06da28u; return 0; }
r[0]+=0x00000001u;
goto P_0c06da2a;
P_0c06da2a: /* original 0ec4, guest PC 0x0c06da2a */
if(!s->budget--) { s->failed_pc=0x0c06da2au; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06da2c;
P_0c06da2c: /* original 7001, guest PC 0x0c06da2c */
if(!s->budget--) { s->failed_pc=0x0c06da2cu; return 0; }
r[0]+=0x00000001u;
goto P_0c06da2e;
P_0c06da2e: /* original 0ec4, guest PC 0x0c06da2e */
if(!s->budget--) { s->failed_pc=0x0c06da2eu; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06da30;
P_0c06da30: /* original 7026, guest PC 0x0c06da30 */
if(!s->budget--) { s->failed_pc=0x0c06da30u; return 0; }
r[0]+=0x00000026u;
goto P_0c06da32;
P_0c06da32: /* original 0ec4, guest PC 0x0c06da32 */
if(!s->budget--) { s->failed_pc=0x0c06da32u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06da34;
P_0c06da34: /* original 7001, guest PC 0x0c06da34 */
if(!s->budget--) { s->failed_pc=0x0c06da34u; return 0; }
r[0]+=0x00000001u;
goto P_0c06da36;
P_0c06da36: /* original 0ec4, guest PC 0x0c06da36 */
if(!s->budget--) { s->failed_pc=0x0c06da36u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06da38;
P_0c06da38: /* original 7001, guest PC 0x0c06da38 */
if(!s->budget--) { s->failed_pc=0x0c06da38u; return 0; }
r[0]+=0x00000001u;
goto P_0c06da3a;
P_0c06da3a: /* original 0ec4, guest PC 0x0c06da3a */
if(!s->budget--) { s->failed_pc=0x0c06da3au; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06da3c;
P_0c06da3c: /* original 70da, guest PC 0x0c06da3c */
if(!s->budget--) { s->failed_pc=0x0c06da3cu; return 0; }
r[0]+=0xffffffdau;
goto P_0c06da3e;
P_0c06da3e: /* original 0ec4, guest PC 0x0c06da3e */
if(!s->budget--) { s->failed_pc=0x0c06da3eu; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06da40;
P_0c06da40: /* original 7001, guest PC 0x0c06da40 */
if(!s->budget--) { s->failed_pc=0x0c06da40u; return 0; }
r[0]+=0x00000001u;
goto P_0c06da42;
P_0c06da42: /* original e401, guest PC 0x0c06da42 */
if(!s->budget--) { s->failed_pc=0x0c06da42u; return 0; }
r[4]=0x00000001u;
goto P_0c06da44;
P_0c06da44: /* original 0e44, guest PC 0x0c06da44 */
if(!s->budget--) { s->failed_pc=0x0c06da44u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06da46;
P_0c06da46: /* original 0e44, guest PC 0x0c06da46 */
if(!s->budget--) { s->failed_pc=0x0c06da46u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06da48;
P_0c06da48: /* original 7003, guest PC 0x0c06da48 */
if(!s->budget--) { s->failed_pc=0x0c06da48u; return 0; }
r[0]+=0x00000003u;
goto P_0c06da4a;
P_0c06da4a: /* original fe67, guest PC 0x0c06da4a */
if(!s->budget--) { s->failed_pc=0x0c06da4au; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c06da4c;
P_0c06da4c: /* original 7004, guest PC 0x0c06da4c */
if(!s->budget--) { s->failed_pc=0x0c06da4cu; return 0; }
r[0]+=0x00000004u;
goto P_0c06da4e;
P_0c06da4e: /* original fe67, guest PC 0x0c06da4e */
if(!s->budget--) { s->failed_pc=0x0c06da4eu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c06da50;
P_0c06da50: /* original 7004, guest PC 0x0c06da50 */
if(!s->budget--) { s->failed_pc=0x0c06da50u; return 0; }
r[0]+=0x00000004u;
goto P_0c06da52;
P_0c06da52: /* original fe67, guest PC 0x0c06da52 */
if(!s->budget--) { s->failed_pc=0x0c06da52u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c06da54;
P_0c06da54: /* original 7004, guest PC 0x0c06da54 */
if(!s->budget--) { s->failed_pc=0x0c06da54u; return 0; }
r[0]+=0x00000004u;
goto P_0c06da56;
P_0c06da56: /* original fe57, guest PC 0x0c06da56 */
if(!s->budget--) { s->failed_pc=0x0c06da56u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c06da58;
P_0c06da58: /* original 7018, guest PC 0x0c06da58 */
if(!s->budget--) { s->failed_pc=0x0c06da58u; return 0; }
r[0]+=0x00000018u;
goto P_0c06da5a;
P_0c06da5a: /* original 0ec4, guest PC 0x0c06da5a */
if(!s->budget--) { s->failed_pc=0x0c06da5au; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06da5c;
P_0c06da5c: /* original 7001, guest PC 0x0c06da5c */
if(!s->budget--) { s->failed_pc=0x0c06da5cu; return 0; }
r[0]+=0x00000001u;
goto P_0c06da5e;
P_0c06da5e: /* original 0e44, guest PC 0x0c06da5e */
if(!s->budget--) { s->failed_pc=0x0c06da5eu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06da60;
P_0c06da60: /* original 0e44, guest PC 0x0c06da60 */
if(!s->budget--) { s->failed_pc=0x0c06da60u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06da62;
P_0c06da62: /* original 7003, guest PC 0x0c06da62 */
if(!s->budget--) { s->failed_pc=0x0c06da62u; return 0; }
r[0]+=0x00000003u;
goto P_0c06da64;
P_0c06da64: /* original 4f26, guest PC 0x0c06da64 */
if(!s->budget--) { s->failed_pc=0x0c06da64u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06da66;
P_0c06da66: /* original fe67, guest PC 0x0c06da66 */
if(!s->budget--) { s->failed_pc=0x0c06da66u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c06da68;
P_0c06da68: /* original 7004, guest PC 0x0c06da68 */
if(!s->budget--) { s->failed_pc=0x0c06da68u; return 0; }
r[0]+=0x00000004u;
goto P_0c06da6a;
P_0c06da6a: /* original fe67, guest PC 0x0c06da6a */
if(!s->budget--) { s->failed_pc=0x0c06da6au; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c06da6c;
P_0c06da6c: /* original 7004, guest PC 0x0c06da6c */
if(!s->budget--) { s->failed_pc=0x0c06da6cu; return 0; }
r[0]+=0x00000004u;
goto P_0c06da6e;
P_0c06da6e: /* original fe67, guest PC 0x0c06da6e */
if(!s->budget--) { s->failed_pc=0x0c06da6eu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c06da70;
P_0c06da70: /* original 7004, guest PC 0x0c06da70 */
if(!s->budget--) { s->failed_pc=0x0c06da70u; return 0; }
r[0]+=0x00000004u;
goto P_0c06da72;
P_0c06da72: /* original fe57, guest PC 0x0c06da72 */
if(!s->budget--) { s->failed_pc=0x0c06da72u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c06da74;
P_0c06da74: /* original 6cf6, guest PC 0x0c06da74 */
if(!s->budget--) { s->failed_pc=0x0c06da74u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06da76;
P_0c06da76: /* original 6df6, guest PC 0x0c06da76 */
if(!s->budget--) { s->failed_pc=0x0c06da76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06da78;
P_0c06da78: /* original 000b, guest PC 0x0c06da78 */
if(!s->budget--) { s->failed_pc=0x0c06da78u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06da7a: /* original 6ef6, guest PC 0x0c06da7a */
if(!s->budget--) { s->failed_pc=0x0c06da7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06da7cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06da7cu; return 0; } return 1;
P_0c07a7e8: /* original 6341, guest PC 0x0c07a7e8 */
if(!s->budget--) { s->failed_pc=0x0c07a7e8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[3]=tmp;
goto P_0c07a7ea;
P_0c07a7ea: /* original d676, guest PC 0x0c07a7ea */
if(!s->budget--) { s->failed_pc=0x0c07a7eau; return 0; }
r[6]=read(ram,0x0c07a9c4u,4);
goto P_0c07a7ec;
P_0c07a7ec: /* original 2631, guest PC 0x0c07a7ec */
if(!s->budget--) { s->failed_pc=0x0c07a7ecu; return 0; }
write(ram,r[6],r[3],2);
goto P_0c07a7ee;
P_0c07a7ee: /* original 8541, guest PC 0x0c07a7ee */
if(!s->budget--) { s->failed_pc=0x0c07a7eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c07a7f0;
P_0c07a7f0: /* original 8161, guest PC 0x0c07a7f0 */
if(!s->budget--) { s->failed_pc=0x0c07a7f0u; return 0; }
write(ram,r[6]+2,r[0],2);
goto P_0c07a7f2;
P_0c07a7f2: /* original 5341, guest PC 0x0c07a7f2 */
if(!s->budget--) { s->failed_pc=0x0c07a7f2u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c07a7f4;
P_0c07a7f4: /* original 1631, guest PC 0x0c07a7f4 */
if(!s->budget--) { s->failed_pc=0x0c07a7f4u; return 0; }
write(ram,r[6]+4,r[3],4);
goto P_0c07a7f6;
P_0c07a7f6: /* original 5242, guest PC 0x0c07a7f6 */
if(!s->budget--) { s->failed_pc=0x0c07a7f6u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c07a7f8;
P_0c07a7f8: /* original 352c, guest PC 0x0c07a7f8 */
if(!s->budget--) { s->failed_pc=0x0c07a7f8u; return 0; }
r[5]+=r[2];
goto P_0c07a7fa;
P_0c07a7fa: /* original 1652, guest PC 0x0c07a7fa */
if(!s->budget--) { s->failed_pc=0x0c07a7fau; return 0; }
write(ram,r[6]+8,r[5],4);
goto P_0c07a7fc;
P_0c07a7fc: /* original 5343, guest PC 0x0c07a7fc */
if(!s->budget--) { s->failed_pc=0x0c07a7fcu; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c07a7fe;
P_0c07a7fe: /* original 1633, guest PC 0x0c07a7fe */
if(!s->budget--) { s->failed_pc=0x0c07a7feu; return 0; }
write(ram,r[6]+12,r[3],4);
goto P_0c07a800;
P_0c07a800: /* original d271, guest PC 0x0c07a800 */
if(!s->budget--) { s->failed_pc=0x0c07a800u; return 0; }
r[2]=read(ram,0x0c07a9c8u,4);
goto P_0c07a802;
P_0c07a802: /* original 422b, guest PC 0x0c07a802 */
if(!s->budget--) { s->failed_pc=0x0c07a802u; return 0; }
target=r[2];
r[4]=r[6];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c03f5a0u: return vf3_matrix_family(0x0c03f5a0u,s,ram);
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
P_0c07a804: /* original 6463, guest PC 0x0c07a804 */
if(!s->budget--) { s->failed_pc=0x0c07a804u; return 0; }
r[4]=r[6];
goto P_0c07a806;
P_0c07a806: /* original 2fe6, guest PC 0x0c07a806 */
if(!s->budget--) { s->failed_pc=0x0c07a806u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a808;
P_0c07a808: /* original 6e53, guest PC 0x0c07a808 */
if(!s->budget--) { s->failed_pc=0x0c07a808u; return 0; }
r[14]=r[5];
goto P_0c07a80a;
P_0c07a80a: /* original 2fd6, guest PC 0x0c07a80a */
if(!s->budget--) { s->failed_pc=0x0c07a80au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a80c;
P_0c07a80c: /* original 6d43, guest PC 0x0c07a80c */
if(!s->budget--) { s->failed_pc=0x0c07a80cu; return 0; }
r[13]=r[4];
goto P_0c07a80e;
P_0c07a80e: /* original 4f22, guest PC 0x0c07a80e */
if(!s->budget--) { s->failed_pc=0x0c07a80eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07a810;
P_0c07a810: /* original 5041, guest PC 0x0c07a810 */
if(!s->budget--) { s->failed_pc=0x0c07a810u; return 0; }
r[0]=read(ram,r[4]+4,4);
goto P_0c07a812;
P_0c07a812: /* original 88ff, guest PC 0x0c07a812 */
if(!s->budget--) { s->failed_pc=0x0c07a812u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c07a814;
P_0c07a814: /* original 8904, guest PC 0x0c07a814 */
if(!s->budget--) { s->failed_pc=0x0c07a814u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07a820; }
goto P_0c07a816;
P_0c07a816: /* original 5242, guest PC 0x0c07a816 */
if(!s->budget--) { s->failed_pc=0x0c07a816u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c07a818;
P_0c07a818: /* original 32ec, guest PC 0x0c07a818 */
if(!s->budget--) { s->failed_pc=0x0c07a818u; return 0; }
r[2]+=r[14];
goto P_0c07a81a;
P_0c07a81a: /* original 1422, guest PC 0x0c07a81a */
if(!s->budget--) { s->failed_pc=0x0c07a81au; return 0; }
write(ram,r[4]+8,r[2],4);
goto P_0c07a81c;
P_0c07a81c: /* original aff8, guest PC 0x0c07a81c */
if(!s->budget--) { s->failed_pc=0x0c07a81cu; return 0; }
r[4]+=0x00000010u;
goto P_0c07a810;
P_0c07a81e: /* original 7410, guest PC 0x0c07a81e */
if(!s->budget--) { s->failed_pc=0x0c07a81eu; return 0; }
r[4]+=0x00000010u;
goto P_0c07a820;
P_0c07a820: /* original d369, guest PC 0x0c07a820 */
if(!s->budget--) { s->failed_pc=0x0c07a820u; return 0; }
r[3]=read(ram,0x0c07a9c8u,4);
goto P_0c07a822;
P_0c07a822: /* original 430b, guest PC 0x0c07a822 */
if(!s->budget--) { s->failed_pc=0x0c07a822u; return 0; }
target=r[3];
r[16]=code_base|0x0c07a826u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a826u) { target=s->pc; goto dispatch; }
goto P_0c07a826;
P_0c07a824: /* original 64d3, guest PC 0x0c07a824 */
if(!s->budget--) { s->failed_pc=0x0c07a824u; return 0; }
r[4]=r[13];
goto P_0c07a826;
P_0c07a826: /* original 64d3, guest PC 0x0c07a826 */
if(!s->budget--) { s->failed_pc=0x0c07a826u; return 0; }
r[4]=r[13];
goto P_0c07a828;
P_0c07a828: /* original 6503, guest PC 0x0c07a828 */
if(!s->budget--) { s->failed_pc=0x0c07a828u; return 0; }
r[5]=r[0];
goto P_0c07a82a;
P_0c07a82a: /* original 5041, guest PC 0x0c07a82a */
if(!s->budget--) { s->failed_pc=0x0c07a82au; return 0; }
r[0]=read(ram,r[4]+4,4);
goto P_0c07a82c;
P_0c07a82c: /* original 88ff, guest PC 0x0c07a82c */
if(!s->budget--) { s->failed_pc=0x0c07a82cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c07a82e;
P_0c07a82e: /* original 8904, guest PC 0x0c07a82e */
if(!s->budget--) { s->failed_pc=0x0c07a82eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07a83a; }
goto P_0c07a830;
P_0c07a830: /* original 5342, guest PC 0x0c07a830 */
if(!s->budget--) { s->failed_pc=0x0c07a830u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c07a832;
P_0c07a832: /* original 33e8, guest PC 0x0c07a832 */
if(!s->budget--) { s->failed_pc=0x0c07a832u; return 0; }
r[3]-=r[14];
goto P_0c07a834;
P_0c07a834: /* original 1432, guest PC 0x0c07a834 */
if(!s->budget--) { s->failed_pc=0x0c07a834u; return 0; }
write(ram,r[4]+8,r[3],4);
goto P_0c07a836;
P_0c07a836: /* original aff8, guest PC 0x0c07a836 */
if(!s->budget--) { s->failed_pc=0x0c07a836u; return 0; }
r[4]+=0x00000010u;
goto P_0c07a82a;
P_0c07a838: /* original 7410, guest PC 0x0c07a838 */
if(!s->budget--) { s->failed_pc=0x0c07a838u; return 0; }
r[4]+=0x00000010u;
goto P_0c07a83a;
P_0c07a83a: /* original 4f26, guest PC 0x0c07a83a */
if(!s->budget--) { s->failed_pc=0x0c07a83au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07a83c;
P_0c07a83c: /* original 6053, guest PC 0x0c07a83c */
if(!s->budget--) { s->failed_pc=0x0c07a83cu; return 0; }
r[0]=r[5];
goto P_0c07a83e;
P_0c07a83e: /* original 6df6, guest PC 0x0c07a83e */
if(!s->budget--) { s->failed_pc=0x0c07a83eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07a840;
P_0c07a840: /* original 000b, guest PC 0x0c07a840 */
if(!s->budget--) { s->failed_pc=0x0c07a840u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07a842: /* original 6ef6, guest PC 0x0c07a842 */
if(!s->budget--) { s->failed_pc=0x0c07a842u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07a844;
P_0c07a844: /* original 2fe6, guest PC 0x0c07a844 */
if(!s->budget--) { s->failed_pc=0x0c07a844u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a846;
P_0c07a846: /* original 6e53, guest PC 0x0c07a846 */
if(!s->budget--) { s->failed_pc=0x0c07a846u; return 0; }
r[14]=r[5];
goto P_0c07a848;
P_0c07a848: /* original 2fd6, guest PC 0x0c07a848 */
if(!s->budget--) { s->failed_pc=0x0c07a848u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a84a;
P_0c07a84a: /* original 2fc6, guest PC 0x0c07a84a */
if(!s->budget--) { s->failed_pc=0x0c07a84au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a84c;
P_0c07a84c: /* original 2fb6, guest PC 0x0c07a84c */
if(!s->budget--) { s->failed_pc=0x0c07a84cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a84e;
P_0c07a84e: /* original 2fa6, guest PC 0x0c07a84e */
if(!s->budget--) { s->failed_pc=0x0c07a84eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a850;
P_0c07a850: /* original 6a43, guest PC 0x0c07a850 */
if(!s->budget--) { s->failed_pc=0x0c07a850u; return 0; }
r[10]=r[4];
goto P_0c07a852;
P_0c07a852: /* original 2f96, guest PC 0x0c07a852 */
if(!s->budget--) { s->failed_pc=0x0c07a852u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a854;
P_0c07a854: /* original 6bad, guest PC 0x0c07a854 */
if(!s->budget--) { s->failed_pc=0x0c07a854u; return 0; }
r[11]=r[10]&65535u;
goto P_0c07a856;
P_0c07a856: /* original 4f22, guest PC 0x0c07a856 */
if(!s->budget--) { s->failed_pc=0x0c07a856u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07a858;
P_0c07a858: /* original dc59, guest PC 0x0c07a858 */
if(!s->budget--) { s->failed_pc=0x0c07a858u; return 0; }
r[12]=read(ram,0x0c07a9c0u,4);
goto P_0c07a85a;
P_0c07a85a: /* original dd5c, guest PC 0x0c07a85a */
if(!s->budget--) { s->failed_pc=0x0c07a85au; return 0; }
r[13]=read(ram,0x0c07a9ccu,4);
goto P_0c07a85c;
P_0c07a85c: /* original 4c0b, guest PC 0x0c07a85c */
if(!s->budget--) { s->failed_pc=0x0c07a85cu; return 0; }
target=r[12];
r[16]=code_base|0x0c07a860u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a860u) { target=s->pc; goto dispatch; }
goto P_0c07a860;
P_0c07a85e: /* original 64b3, guest PC 0x0c07a85e */
if(!s->budget--) { s->failed_pc=0x0c07a85eu; return 0; }
r[4]=r[11];
goto P_0c07a860;
P_0c07a860: /* original 60b3, guest PC 0x0c07a860 */
if(!s->budget--) { s->failed_pc=0x0c07a860u; return 0; }
r[0]=r[11];
goto P_0c07a862;
P_0c07a862: /* original 880f, guest PC 0x0c07a862 */
if(!s->budget--) { s->failed_pc=0x0c07a862u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c07a864;
P_0c07a864: /* original 8b0e, guest PC 0x0c07a864 */
if(!s->budget--) { s->failed_pc=0x0c07a864u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a884; }
goto P_0c07a866;
P_0c07a866: /* original 4c0b, guest PC 0x0c07a866 */
if(!s->budget--) { s->failed_pc=0x0c07a866u; return 0; }
target=r[12];
r[16]=code_base|0x0c07a86au;
r[4]=0x0000000fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a86au) { target=s->pc; goto dispatch; }
goto P_0c07a86a;
P_0c07a868: /* original e40f, guest PC 0x0c07a868 */
if(!s->budget--) { s->failed_pc=0x0c07a868u; return 0; }
r[4]=0x0000000fu;
goto P_0c07a86a;
P_0c07a86a: /* original d459, guest PC 0x0c07a86a */
if(!s->budget--) { s->failed_pc=0x0c07a86au; return 0; }
r[4]=read(ram,0x0c07a9d0u,4);
goto P_0c07a86c;
P_0c07a86c: /* original bfbc, guest PC 0x0c07a86c */
if(!s->budget--) { s->failed_pc=0x0c07a86cu; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07a870u;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a870u) { target=s->pc; goto dispatch; }
goto P_0c07a870;
P_0c07a86e: /* original 65e3, guest PC 0x0c07a86e */
if(!s->budget--) { s->failed_pc=0x0c07a86eu; return 0; }
r[5]=r[14];
goto P_0c07a870;
P_0c07a870: /* original 4c0b, guest PC 0x0c07a870 */
if(!s->budget--) { s->failed_pc=0x0c07a870u; return 0; }
target=r[12];
r[16]=code_base|0x0c07a874u;
r[4]=0x00000024u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a874u) { target=s->pc; goto dispatch; }
goto P_0c07a874;
P_0c07a872: /* original e424, guest PC 0x0c07a872 */
if(!s->budget--) { s->failed_pc=0x0c07a872u; return 0; }
r[4]=0x00000024u;
goto P_0c07a874;
P_0c07a874: /* original d457, guest PC 0x0c07a874 */
if(!s->budget--) { s->failed_pc=0x0c07a874u; return 0; }
r[4]=read(ram,0x0c07a9d4u,4);
goto P_0c07a876;
P_0c07a876: /* original bfb7, guest PC 0x0c07a876 */
if(!s->budget--) { s->failed_pc=0x0c07a876u; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07a87au;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a87au) { target=s->pc; goto dispatch; }
goto P_0c07a87a;
P_0c07a878: /* original 65e3, guest PC 0x0c07a878 */
if(!s->budget--) { s->failed_pc=0x0c07a878u; return 0; }
r[5]=r[14];
goto P_0c07a87a;
P_0c07a87a: /* original e00f, guest PC 0x0c07a87a */
if(!s->budget--) { s->failed_pc=0x0c07a87au; return 0; }
r[0]=0x0000000fu;
goto P_0c07a87c;
P_0c07a87c: /* original 81df, guest PC 0x0c07a87c */
if(!s->budget--) { s->failed_pc=0x0c07a87cu; return 0; }
write(ram,r[13]+30,r[0],2);
goto P_0c07a87e;
P_0c07a87e: /* original e048, guest PC 0x0c07a87e */
if(!s->budget--) { s->failed_pc=0x0c07a87eu; return 0; }
r[0]=0x00000048u;
goto P_0c07a880;
P_0c07a880: /* original a096, guest PC 0x0c07a880 */
if(!s->budget--) { s->failed_pc=0x0c07a880u; return 0; }
r[3]=0x00000024u;
goto P_0c07a9b0;
P_0c07a882: /* original e324, guest PC 0x0c07a882 */
if(!s->budget--) { s->failed_pc=0x0c07a882u; return 0; }
r[3]=0x00000024u;
goto P_0c07a884;
P_0c07a884: /* original 60b3, guest PC 0x0c07a884 */
if(!s->budget--) { s->failed_pc=0x0c07a884u; return 0; }
r[0]=r[11];
goto P_0c07a886;
P_0c07a886: /* original d954, guest PC 0x0c07a886 */
if(!s->budget--) { s->failed_pc=0x0c07a886u; return 0; }
r[9]=read(ram,0x0c07a9d8u,4);
goto P_0c07a888;
P_0c07a888: /* original 8808, guest PC 0x0c07a888 */
if(!s->budget--) { s->failed_pc=0x0c07a888u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c07a88a;
P_0c07a88a: /* original 8b06, guest PC 0x0c07a88a */
if(!s->budget--) { s->failed_pc=0x0c07a88au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a89a; }
goto P_0c07a88c;
P_0c07a88c: /* original 4c0b, guest PC 0x0c07a88c */
if(!s->budget--) { s->failed_pc=0x0c07a88cu; return 0; }
target=r[12];
r[16]=code_base|0x0c07a890u;
r[4]=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a890u) { target=s->pc; goto dispatch; }
goto P_0c07a890;
P_0c07a88e: /* original e408, guest PC 0x0c07a88e */
if(!s->budget--) { s->failed_pc=0x0c07a88eu; return 0; }
r[4]=0x00000008u;
goto P_0c07a890;
P_0c07a890: /* original 65e3, guest PC 0x0c07a890 */
if(!s->budget--) { s->failed_pc=0x0c07a890u; return 0; }
r[5]=r[14];
goto P_0c07a892;
P_0c07a892: /* original bfa9, guest PC 0x0c07a892 */
if(!s->budget--) { s->failed_pc=0x0c07a892u; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07a896u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a896u) { target=s->pc; goto dispatch; }
goto P_0c07a896;
P_0c07a894: /* original 6493, guest PC 0x0c07a894 */
if(!s->budget--) { s->failed_pc=0x0c07a894u; return 0; }
r[4]=r[9];
goto P_0c07a896;
P_0c07a896: /* original a008, guest PC 0x0c07a896 */
if(!s->budget--) { s->failed_pc=0x0c07a896u; return 0; }
r[4]=0x00000008u;
goto P_0c07a8aa;
P_0c07a898: /* original e408, guest PC 0x0c07a898 */
if(!s->budget--) { s->failed_pc=0x0c07a898u; return 0; }
r[4]=0x00000008u;
goto P_0c07a89a;
P_0c07a89a: /* original 8809, guest PC 0x0c07a89a */
if(!s->budget--) { s->failed_pc=0x0c07a89au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c07a89c;
P_0c07a89c: /* original 8b0b, guest PC 0x0c07a89c */
if(!s->budget--) { s->failed_pc=0x0c07a89cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a8b6; }
goto P_0c07a89e;
P_0c07a89e: /* original 4c0b, guest PC 0x0c07a89e */
if(!s->budget--) { s->failed_pc=0x0c07a89eu; return 0; }
target=r[12];
r[16]=code_base|0x0c07a8a2u;
r[4]=0x00000009u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a8a2u) { target=s->pc; goto dispatch; }
goto P_0c07a8a2;
P_0c07a8a0: /* original e409, guest PC 0x0c07a8a0 */
if(!s->budget--) { s->failed_pc=0x0c07a8a0u; return 0; }
r[4]=0x00000009u;
goto P_0c07a8a2;
P_0c07a8a2: /* original 65e3, guest PC 0x0c07a8a2 */
if(!s->budget--) { s->failed_pc=0x0c07a8a2u; return 0; }
r[5]=r[14];
goto P_0c07a8a4;
P_0c07a8a4: /* original bfa0, guest PC 0x0c07a8a4 */
if(!s->budget--) { s->failed_pc=0x0c07a8a4u; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07a8a8u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a8a8u) { target=s->pc; goto dispatch; }
goto P_0c07a8a8;
P_0c07a8a6: /* original 6493, guest PC 0x0c07a8a6 */
if(!s->budget--) { s->failed_pc=0x0c07a8a6u; return 0; }
r[4]=r[9];
goto P_0c07a8a8;
P_0c07a8a8: /* original e409, guest PC 0x0c07a8a8 */
if(!s->budget--) { s->failed_pc=0x0c07a8a8u; return 0; }
r[4]=0x00000009u;
goto P_0c07a8aa;
P_0c07a8aa: /* original 60ad, guest PC 0x0c07a8aa */
if(!s->budget--) { s->failed_pc=0x0c07a8aau; return 0; }
r[0]=r[10]&65535u;
goto P_0c07a8ac;
P_0c07a8ac: /* original 4000, guest PC 0x0c07a8ac */
if(!s->budget--) { s->failed_pc=0x0c07a8acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07a8ae;
P_0c07a8ae: /* original 0d45, guest PC 0x0c07a8ae */
if(!s->budget--) { s->failed_pc=0x0c07a8aeu; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c07a8b0;
P_0c07a8b0: /* original 6043, guest PC 0x0c07a8b0 */
if(!s->budget--) { s->failed_pc=0x0c07a8b0u; return 0; }
r[0]=r[4];
goto P_0c07a8b2;
P_0c07a8b2: /* original a0b5, guest PC 0x0c07a8b2 */
if(!s->budget--) { s->failed_pc=0x0c07a8b2u; return 0; }
write(ram,r[13]+10,r[0],2);
goto P_0c07aa20;
P_0c07a8b4: /* original 81d5, guest PC 0x0c07a8b4 */
if(!s->budget--) { s->failed_pc=0x0c07a8b4u; return 0; }
write(ram,r[13]+10,r[0],2);
goto P_0c07a8b6;
P_0c07a8b6: /* original 60b3, guest PC 0x0c07a8b6 */
if(!s->budget--) { s->failed_pc=0x0c07a8b6u; return 0; }
r[0]=r[11];
goto P_0c07a8b8;
P_0c07a8b8: /* original d448, guest PC 0x0c07a8b8 */
if(!s->budget--) { s->failed_pc=0x0c07a8b8u; return 0; }
r[4]=read(ram,0x0c07a9dcu,4);
goto P_0c07a8ba;
P_0c07a8ba: /* original 880a, guest PC 0x0c07a8ba */
if(!s->budget--) { s->failed_pc=0x0c07a8bau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c07a8bc;
P_0c07a8bc: /* original 8902, guest PC 0x0c07a8bc */
if(!s->budget--) { s->failed_pc=0x0c07a8bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07a8c4; }
goto P_0c07a8be;
P_0c07a8be: /* original 60b3, guest PC 0x0c07a8be */
if(!s->budget--) { s->failed_pc=0x0c07a8beu; return 0; }
r[0]=r[11];
goto P_0c07a8c0;
P_0c07a8c0: /* original 880b, guest PC 0x0c07a8c0 */
if(!s->budget--) { s->failed_pc=0x0c07a8c0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c07a8c2;
P_0c07a8c2: /* original 8b07, guest PC 0x0c07a8c2 */
if(!s->budget--) { s->failed_pc=0x0c07a8c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a8d4; }
goto P_0c07a8c4;
P_0c07a8c4: /* original bf9f, guest PC 0x0c07a8c4 */
if(!s->budget--) { s->failed_pc=0x0c07a8c4u; return 0; }
target=code_base|0x0c07a806u; r[16]=code_base|0x0c07a8c8u;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a8c8u) { target=s->pc; goto dispatch; }
goto P_0c07a8c8;
P_0c07a8c6: /* original 65e3, guest PC 0x0c07a8c6 */
if(!s->budget--) { s->failed_pc=0x0c07a8c6u; return 0; }
r[5]=r[14];
goto P_0c07a8c8;
P_0c07a8c8: /* original 60ad, guest PC 0x0c07a8c8 */
if(!s->budget--) { s->failed_pc=0x0c07a8c8u; return 0; }
r[0]=r[10]&65535u;
goto P_0c07a8ca;
P_0c07a8ca: /* original 4000, guest PC 0x0c07a8ca */
if(!s->budget--) { s->failed_pc=0x0c07a8cau; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07a8cc;
P_0c07a8cc: /* original 0db5, guest PC 0x0c07a8cc */
if(!s->budget--) { s->failed_pc=0x0c07a8ccu; return 0; }
write(ram,r[13]+r[0],r[11],2);
goto P_0c07a8ce;
P_0c07a8ce: /* original 60b3, guest PC 0x0c07a8ce */
if(!s->budget--) { s->failed_pc=0x0c07a8ceu; return 0; }
r[0]=r[11];
goto P_0c07a8d0;
P_0c07a8d0: /* original a0a6, guest PC 0x0c07a8d0 */
if(!s->budget--) { s->failed_pc=0x0c07a8d0u; return 0; }
write(ram,r[13]+12,r[0],2);
goto P_0c07aa20;
P_0c07a8d2: /* original 81d6, guest PC 0x0c07a8d2 */
if(!s->budget--) { s->failed_pc=0x0c07a8d2u; return 0; }
write(ram,r[13]+12,r[0],2);
goto P_0c07a8d4;
P_0c07a8d4: /* original 8812, guest PC 0x0c07a8d4 */
if(!s->budget--) { s->failed_pc=0x0c07a8d4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c07a8d6;
P_0c07a8d6: /* original 8b15, guest PC 0x0c07a8d6 */
if(!s->budget--) { s->failed_pc=0x0c07a8d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a904; }
goto P_0c07a8d8;
P_0c07a8d8: /* original 4c0b, guest PC 0x0c07a8d8 */
if(!s->budget--) { s->failed_pc=0x0c07a8d8u; return 0; }
target=r[12];
r[16]=code_base|0x0c07a8dcu;
r[4]=0x00000023u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a8dcu) { target=s->pc; goto dispatch; }
goto P_0c07a8dc;
P_0c07a8da: /* original e423, guest PC 0x0c07a8da */
if(!s->budget--) { s->failed_pc=0x0c07a8dau; return 0; }
r[4]=0x00000023u;
goto P_0c07a8dc;
P_0c07a8dc: /* original db40, guest PC 0x0c07a8dc */
if(!s->budget--) { s->failed_pc=0x0c07a8dcu; return 0; }
r[11]=read(ram,0x0c07a9e0u,4);
goto P_0c07a8de;
P_0c07a8de: /* original 65e3, guest PC 0x0c07a8de */
if(!s->budget--) { s->failed_pc=0x0c07a8deu; return 0; }
r[5]=r[14];
goto P_0c07a8e0;
P_0c07a8e0: /* original bf82, guest PC 0x0c07a8e0 */
if(!s->budget--) { s->failed_pc=0x0c07a8e0u; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07a8e4u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a8e4u) { target=s->pc; goto dispatch; }
goto P_0c07a8e4;
P_0c07a8e2: /* original 64b3, guest PC 0x0c07a8e2 */
if(!s->budget--) { s->failed_pc=0x0c07a8e2u; return 0; }
r[4]=r[11];
goto P_0c07a8e4;
P_0c07a8e4: /* original 4c0b, guest PC 0x0c07a8e4 */
if(!s->budget--) { s->failed_pc=0x0c07a8e4u; return 0; }
target=r[12];
r[16]=code_base|0x0c07a8e8u;
r[4]=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a8e8u) { target=s->pc; goto dispatch; }
goto P_0c07a8e8;
P_0c07a8e6: /* original e412, guest PC 0x0c07a8e6 */
if(!s->budget--) { s->failed_pc=0x0c07a8e6u; return 0; }
r[4]=0x00000012u;
goto P_0c07a8e8;
P_0c07a8e8: /* original 64b3, guest PC 0x0c07a8e8 */
if(!s->budget--) { s->failed_pc=0x0c07a8e8u; return 0; }
r[4]=r[11];
goto P_0c07a8ea;
P_0c07a8ea: /* original 65e3, guest PC 0x0c07a8ea */
if(!s->budget--) { s->failed_pc=0x0c07a8eau; return 0; }
r[5]=r[14];
goto P_0c07a8ec;
P_0c07a8ec: /* original bf7c, guest PC 0x0c07a8ec */
if(!s->budget--) { s->failed_pc=0x0c07a8ecu; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07a8f0u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a8f0u) { target=s->pc; goto dispatch; }
goto P_0c07a8f0;
P_0c07a8ee: /* original 7410, guest PC 0x0c07a8ee */
if(!s->budget--) { s->failed_pc=0x0c07a8eeu; return 0; }
r[4]+=0x00000010u;
goto P_0c07a8f0;
P_0c07a8f0: /* original 4c0b, guest PC 0x0c07a8f0 */
if(!s->budget--) { s->failed_pc=0x0c07a8f0u; return 0; }
target=r[12];
r[16]=code_base|0x0c07a8f4u;
r[4]=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a8f4u) { target=s->pc; goto dispatch; }
goto P_0c07a8f4;
P_0c07a8f2: /* original e418, guest PC 0x0c07a8f2 */
if(!s->budget--) { s->failed_pc=0x0c07a8f2u; return 0; }
r[4]=0x00000018u;
goto P_0c07a8f4;
P_0c07a8f4: /* original 64b3, guest PC 0x0c07a8f4 */
if(!s->budget--) { s->failed_pc=0x0c07a8f4u; return 0; }
r[4]=r[11];
goto P_0c07a8f6;
P_0c07a8f6: /* original 65e3, guest PC 0x0c07a8f6 */
if(!s->budget--) { s->failed_pc=0x0c07a8f6u; return 0; }
r[5]=r[14];
goto P_0c07a8f8;
P_0c07a8f8: /* original bf76, guest PC 0x0c07a8f8 */
if(!s->budget--) { s->failed_pc=0x0c07a8f8u; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07a8fcu;
r[4]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a8fcu) { target=s->pc; goto dispatch; }
goto P_0c07a8fc;
P_0c07a8fa: /* original 7420, guest PC 0x0c07a8fa */
if(!s->budget--) { s->failed_pc=0x0c07a8fau; return 0; }
r[4]+=0x00000020u;
goto P_0c07a8fc;
P_0c07a8fc: /* original e212, guest PC 0x0c07a8fc */
if(!s->budget--) { s->failed_pc=0x0c07a8fcu; return 0; }
r[2]=0x00000012u;
goto P_0c07a8fe;
P_0c07a8fe: /* original e024, guest PC 0x0c07a8fe */
if(!s->budget--) { s->failed_pc=0x0c07a8feu; return 0; }
r[0]=0x00000024u;
goto P_0c07a900;
P_0c07a900: /* original a018, guest PC 0x0c07a900 */
if(!s->budget--) { s->failed_pc=0x0c07a900u; return 0; }
write(ram,r[13]+r[0],r[2],2);
goto P_0c07a934;
P_0c07a902: /* original 0d25, guest PC 0x0c07a902 */
if(!s->budget--) { s->failed_pc=0x0c07a902u; return 0; }
write(ram,r[13]+r[0],r[2],2);
goto P_0c07a904;
P_0c07a904: /* original 60b3, guest PC 0x0c07a904 */
if(!s->budget--) { s->failed_pc=0x0c07a904u; return 0; }
r[0]=r[11];
goto P_0c07a906;
P_0c07a906: /* original 8813, guest PC 0x0c07a906 */
if(!s->budget--) { s->failed_pc=0x0c07a906u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000013u)!=0);
goto P_0c07a908;
P_0c07a908: /* original 8b1b, guest PC 0x0c07a908 */
if(!s->budget--) { s->failed_pc=0x0c07a908u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a942; }
goto P_0c07a90a;
P_0c07a90a: /* original 4c0b, guest PC 0x0c07a90a */
if(!s->budget--) { s->failed_pc=0x0c07a90au; return 0; }
target=r[12];
r[16]=code_base|0x0c07a90eu;
r[4]=0x00000023u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a90eu) { target=s->pc; goto dispatch; }
goto P_0c07a90e;
P_0c07a90c: /* original e423, guest PC 0x0c07a90c */
if(!s->budget--) { s->failed_pc=0x0c07a90cu; return 0; }
r[4]=0x00000023u;
goto P_0c07a90e;
P_0c07a90e: /* original db35, guest PC 0x0c07a90e */
if(!s->budget--) { s->failed_pc=0x0c07a90eu; return 0; }
r[11]=read(ram,0x0c07a9e4u,4);
goto P_0c07a910;
P_0c07a910: /* original 65e3, guest PC 0x0c07a910 */
if(!s->budget--) { s->failed_pc=0x0c07a910u; return 0; }
r[5]=r[14];
goto P_0c07a912;
P_0c07a912: /* original bf69, guest PC 0x0c07a912 */
if(!s->budget--) { s->failed_pc=0x0c07a912u; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07a916u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a916u) { target=s->pc; goto dispatch; }
goto P_0c07a916;
P_0c07a914: /* original 64b3, guest PC 0x0c07a914 */
if(!s->budget--) { s->failed_pc=0x0c07a914u; return 0; }
r[4]=r[11];
goto P_0c07a916;
P_0c07a916: /* original 4c0b, guest PC 0x0c07a916 */
if(!s->budget--) { s->failed_pc=0x0c07a916u; return 0; }
target=r[12];
r[16]=code_base|0x0c07a91au;
r[4]=0x00000013u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a91au) { target=s->pc; goto dispatch; }
goto P_0c07a91a;
P_0c07a918: /* original e413, guest PC 0x0c07a918 */
if(!s->budget--) { s->failed_pc=0x0c07a918u; return 0; }
r[4]=0x00000013u;
goto P_0c07a91a;
P_0c07a91a: /* original 64b3, guest PC 0x0c07a91a */
if(!s->budget--) { s->failed_pc=0x0c07a91au; return 0; }
r[4]=r[11];
goto P_0c07a91c;
P_0c07a91c: /* original 65e3, guest PC 0x0c07a91c */
if(!s->budget--) { s->failed_pc=0x0c07a91cu; return 0; }
r[5]=r[14];
goto P_0c07a91e;
P_0c07a91e: /* original bf63, guest PC 0x0c07a91e */
if(!s->budget--) { s->failed_pc=0x0c07a91eu; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07a922u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a922u) { target=s->pc; goto dispatch; }
goto P_0c07a922;
P_0c07a920: /* original 7410, guest PC 0x0c07a920 */
if(!s->budget--) { s->failed_pc=0x0c07a920u; return 0; }
r[4]+=0x00000010u;
goto P_0c07a922;
P_0c07a922: /* original 4c0b, guest PC 0x0c07a922 */
if(!s->budget--) { s->failed_pc=0x0c07a922u; return 0; }
target=r[12];
r[16]=code_base|0x0c07a926u;
r[4]=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a926u) { target=s->pc; goto dispatch; }
goto P_0c07a926;
P_0c07a924: /* original e418, guest PC 0x0c07a924 */
if(!s->budget--) { s->failed_pc=0x0c07a924u; return 0; }
r[4]=0x00000018u;
goto P_0c07a926;
P_0c07a926: /* original 64b3, guest PC 0x0c07a926 */
if(!s->budget--) { s->failed_pc=0x0c07a926u; return 0; }
r[4]=r[11];
goto P_0c07a928;
P_0c07a928: /* original 65e3, guest PC 0x0c07a928 */
if(!s->budget--) { s->failed_pc=0x0c07a928u; return 0; }
r[5]=r[14];
goto P_0c07a92a;
P_0c07a92a: /* original bf5d, guest PC 0x0c07a92a */
if(!s->budget--) { s->failed_pc=0x0c07a92au; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07a92eu;
r[4]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a92eu) { target=s->pc; goto dispatch; }
goto P_0c07a92e;
P_0c07a92c: /* original 7420, guest PC 0x0c07a92c */
if(!s->budget--) { s->failed_pc=0x0c07a92cu; return 0; }
r[4]+=0x00000020u;
goto P_0c07a92e;
P_0c07a92e: /* original e313, guest PC 0x0c07a92e */
if(!s->budget--) { s->failed_pc=0x0c07a92eu; return 0; }
r[3]=0x00000013u;
goto P_0c07a930;
P_0c07a930: /* original e026, guest PC 0x0c07a930 */
if(!s->budget--) { s->failed_pc=0x0c07a930u; return 0; }
r[0]=0x00000026u;
goto P_0c07a932;
P_0c07a932: /* original 0d35, guest PC 0x0c07a932 */
if(!s->budget--) { s->failed_pc=0x0c07a932u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07a934;
P_0c07a934: /* original e223, guest PC 0x0c07a934 */
if(!s->budget--) { s->failed_pc=0x0c07a934u; return 0; }
r[2]=0x00000023u;
goto P_0c07a936;
P_0c07a936: /* original e046, guest PC 0x0c07a936 */
if(!s->budget--) { s->failed_pc=0x0c07a936u; return 0; }
r[0]=0x00000046u;
goto P_0c07a938;
P_0c07a938: /* original 0d25, guest PC 0x0c07a938 */
if(!s->budget--) { s->failed_pc=0x0c07a938u; return 0; }
write(ram,r[13]+r[0],r[2],2);
goto P_0c07a93a;
P_0c07a93a: /* original e318, guest PC 0x0c07a93a */
if(!s->budget--) { s->failed_pc=0x0c07a93au; return 0; }
r[3]=0x00000018u;
goto P_0c07a93c;
P_0c07a93c: /* original e030, guest PC 0x0c07a93c */
if(!s->budget--) { s->failed_pc=0x0c07a93cu; return 0; }
r[0]=0x00000030u;
goto P_0c07a93e;
P_0c07a93e: /* original a037, guest PC 0x0c07a93e */
if(!s->budget--) { s->failed_pc=0x0c07a93eu; return 0; }
goto P_0c07a9b0;
P_0c07a940: /* original 0009, guest PC 0x0c07a940 */
if(!s->budget--) { s->failed_pc=0x0c07a940u; return 0; }
goto P_0c07a942;
P_0c07a942: /* original 880e, guest PC 0x0c07a942 */
if(!s->budget--) { s->failed_pc=0x0c07a942u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c07a944;
P_0c07a944: /* original 8b01, guest PC 0x0c07a944 */
if(!s->budget--) { s->failed_pc=0x0c07a944u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a94a; }
goto P_0c07a946;
P_0c07a946: /* original a004, guest PC 0x0c07a946 */
if(!s->budget--) { s->failed_pc=0x0c07a946u; return 0; }
r[4]=0x0000000eu;
goto P_0c07a952;
P_0c07a948: /* original e40e, guest PC 0x0c07a948 */
if(!s->budget--) { s->failed_pc=0x0c07a948u; return 0; }
r[4]=0x0000000eu;
goto P_0c07a94a;
P_0c07a94a: /* original 60b3, guest PC 0x0c07a94a */
if(!s->budget--) { s->failed_pc=0x0c07a94au; return 0; }
r[0]=r[11];
goto P_0c07a94c;
P_0c07a94c: /* original 881b, guest PC 0x0c07a94c */
if(!s->budget--) { s->failed_pc=0x0c07a94cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001bu)!=0);
goto P_0c07a94e;
P_0c07a94e: /* original 8b07, guest PC 0x0c07a94e */
if(!s->budget--) { s->failed_pc=0x0c07a94eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a960; }
goto P_0c07a950;
P_0c07a950: /* original e41b, guest PC 0x0c07a950 */
if(!s->budget--) { s->failed_pc=0x0c07a950u; return 0; }
r[4]=0x0000001bu;
goto P_0c07a952;
P_0c07a952: /* original 4c0b, guest PC 0x0c07a952 */
if(!s->budget--) { s->failed_pc=0x0c07a952u; return 0; }
target=r[12];
r[16]=code_base|0x0c07a956u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a956u) { target=s->pc; goto dispatch; }
goto P_0c07a956;
P_0c07a954: /* original 0009, guest PC 0x0c07a954 */
if(!s->budget--) { s->failed_pc=0x0c07a954u; return 0; }
goto P_0c07a956;
P_0c07a956: /* original 65e3, guest PC 0x0c07a956 */
if(!s->budget--) { s->failed_pc=0x0c07a956u; return 0; }
r[5]=r[14];
goto P_0c07a958;
P_0c07a958: /* original bf55, guest PC 0x0c07a958 */
if(!s->budget--) { s->failed_pc=0x0c07a958u; return 0; }
target=code_base|0x0c07a806u; r[16]=code_base|0x0c07a95cu;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a95cu) { target=s->pc; goto dispatch; }
goto P_0c07a95c;
P_0c07a95a: /* original 6493, guest PC 0x0c07a95a */
if(!s->budget--) { s->failed_pc=0x0c07a95au; return 0; }
r[4]=r[9];
goto P_0c07a95c;
P_0c07a95c: /* original a05d, guest PC 0x0c07a95c */
if(!s->budget--) { s->failed_pc=0x0c07a95cu; return 0; }
goto P_0c07aa1a;
P_0c07a95e: /* original 0009, guest PC 0x0c07a95e */
if(!s->budget--) { s->failed_pc=0x0c07a95eu; return 0; }
goto P_0c07a960;
P_0c07a960: /* original 8814, guest PC 0x0c07a960 */
if(!s->budget--) { s->failed_pc=0x0c07a960u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000014u)!=0);
goto P_0c07a962;
P_0c07a962: /* original 8b10, guest PC 0x0c07a962 */
if(!s->budget--) { s->failed_pc=0x0c07a962u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a986; }
goto P_0c07a964;
P_0c07a964: /* original 4c0b, guest PC 0x0c07a964 */
if(!s->budget--) { s->failed_pc=0x0c07a964u; return 0; }
target=r[12];
r[16]=code_base|0x0c07a968u;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a968u) { target=s->pc; goto dispatch; }
goto P_0c07a968;
P_0c07a966: /* original e414, guest PC 0x0c07a966 */
if(!s->budget--) { s->failed_pc=0x0c07a966u; return 0; }
r[4]=0x00000014u;
goto P_0c07a968;
P_0c07a968: /* original d41f, guest PC 0x0c07a968 */
if(!s->budget--) { s->failed_pc=0x0c07a968u; return 0; }
r[4]=read(ram,0x0c07a9e8u,4);
goto P_0c07a96a;
P_0c07a96a: /* original bf3d, guest PC 0x0c07a96a */
if(!s->budget--) { s->failed_pc=0x0c07a96au; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07a96eu;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a96eu) { target=s->pc; goto dispatch; }
goto P_0c07a96e;
P_0c07a96c: /* original 65e3, guest PC 0x0c07a96c */
if(!s->budget--) { s->failed_pc=0x0c07a96cu; return 0; }
r[5]=r[14];
goto P_0c07a96e;
P_0c07a96e: /* original 4c0b, guest PC 0x0c07a96e */
if(!s->budget--) { s->failed_pc=0x0c07a96eu; return 0; }
target=r[12];
r[16]=code_base|0x0c07a972u;
r[4]=0x00000022u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a972u) { target=s->pc; goto dispatch; }
goto P_0c07a972;
P_0c07a970: /* original e422, guest PC 0x0c07a970 */
if(!s->budget--) { s->failed_pc=0x0c07a970u; return 0; }
r[4]=0x00000022u;
goto P_0c07a972;
P_0c07a972: /* original d41e, guest PC 0x0c07a972 */
if(!s->budget--) { s->failed_pc=0x0c07a972u; return 0; }
r[4]=read(ram,0x0c07a9ecu,4);
goto P_0c07a974;
P_0c07a974: /* original bf38, guest PC 0x0c07a974 */
if(!s->budget--) { s->failed_pc=0x0c07a974u; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07a978u;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a978u) { target=s->pc; goto dispatch; }
goto P_0c07a978;
P_0c07a976: /* original 65e3, guest PC 0x0c07a976 */
if(!s->budget--) { s->failed_pc=0x0c07a976u; return 0; }
r[5]=r[14];
goto P_0c07a978;
P_0c07a978: /* original e214, guest PC 0x0c07a978 */
if(!s->budget--) { s->failed_pc=0x0c07a978u; return 0; }
r[2]=0x00000014u;
goto P_0c07a97a;
P_0c07a97a: /* original e028, guest PC 0x0c07a97a */
if(!s->budget--) { s->failed_pc=0x0c07a97au; return 0; }
r[0]=0x00000028u;
goto P_0c07a97c;
P_0c07a97c: /* original 0d25, guest PC 0x0c07a97c */
if(!s->budget--) { s->failed_pc=0x0c07a97cu; return 0; }
write(ram,r[13]+r[0],r[2],2);
goto P_0c07a97e;
P_0c07a97e: /* original e322, guest PC 0x0c07a97e */
if(!s->budget--) { s->failed_pc=0x0c07a97eu; return 0; }
r[3]=0x00000022u;
goto P_0c07a980;
P_0c07a980: /* original e044, guest PC 0x0c07a980 */
if(!s->budget--) { s->failed_pc=0x0c07a980u; return 0; }
r[0]=0x00000044u;
goto P_0c07a982;
P_0c07a982: /* original a015, guest PC 0x0c07a982 */
if(!s->budget--) { s->failed_pc=0x0c07a982u; return 0; }
goto P_0c07a9b0;
P_0c07a984: /* original 0009, guest PC 0x0c07a984 */
if(!s->budget--) { s->failed_pc=0x0c07a984u; return 0; }
goto P_0c07a986;
P_0c07a986: /* original 60b3, guest PC 0x0c07a986 */
if(!s->budget--) { s->failed_pc=0x0c07a986u; return 0; }
r[0]=r[11];
goto P_0c07a988;
P_0c07a988: /* original 8816, guest PC 0x0c07a988 */
if(!s->budget--) { s->failed_pc=0x0c07a988u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000016u)!=0);
goto P_0c07a98a;
P_0c07a98a: /* original 8b08, guest PC 0x0c07a98a */
if(!s->budget--) { s->failed_pc=0x0c07a98au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a99e; }
goto P_0c07a98c;
P_0c07a98c: /* original 4c0b, guest PC 0x0c07a98c */
if(!s->budget--) { s->failed_pc=0x0c07a98cu; return 0; }
target=r[12];
r[16]=code_base|0x0c07a990u;
r[4]=0x00000016u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a990u) { target=s->pc; goto dispatch; }
goto P_0c07a990;
P_0c07a98e: /* original e416, guest PC 0x0c07a98e */
if(!s->budget--) { s->failed_pc=0x0c07a98eu; return 0; }
r[4]=0x00000016u;
goto P_0c07a990;
P_0c07a990: /* original d417, guest PC 0x0c07a990 */
if(!s->budget--) { s->failed_pc=0x0c07a990u; return 0; }
r[4]=read(ram,0x0c07a9f0u,4);
goto P_0c07a992;
P_0c07a992: /* original bf29, guest PC 0x0c07a992 */
if(!s->budget--) { s->failed_pc=0x0c07a992u; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07a996u;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a996u) { target=s->pc; goto dispatch; }
goto P_0c07a996;
P_0c07a994: /* original 65e3, guest PC 0x0c07a994 */
if(!s->budget--) { s->failed_pc=0x0c07a994u; return 0; }
r[5]=r[14];
goto P_0c07a996;
P_0c07a996: /* original e316, guest PC 0x0c07a996 */
if(!s->budget--) { s->failed_pc=0x0c07a996u; return 0; }
r[3]=0x00000016u;
goto P_0c07a998;
P_0c07a998: /* original e02c, guest PC 0x0c07a998 */
if(!s->budget--) { s->failed_pc=0x0c07a998u; return 0; }
r[0]=0x0000002cu;
goto P_0c07a99a;
P_0c07a99a: /* original a009, guest PC 0x0c07a99a */
if(!s->budget--) { s->failed_pc=0x0c07a99au; return 0; }
goto P_0c07a9b0;
P_0c07a99c: /* original 0009, guest PC 0x0c07a99c */
if(!s->budget--) { s->failed_pc=0x0c07a99cu; return 0; }
goto P_0c07a99e;
P_0c07a99e: /* original 8817, guest PC 0x0c07a99e */
if(!s->budget--) { s->failed_pc=0x0c07a99eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000017u)!=0);
goto P_0c07a9a0;
P_0c07a9a0: /* original 8b2a, guest PC 0x0c07a9a0 */
if(!s->budget--) { s->failed_pc=0x0c07a9a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a9f8; }
goto P_0c07a9a2;
P_0c07a9a2: /* original 4c0b, guest PC 0x0c07a9a2 */
if(!s->budget--) { s->failed_pc=0x0c07a9a2u; return 0; }
target=r[12];
r[16]=code_base|0x0c07a9a6u;
r[4]=0x00000017u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a9a6u) { target=s->pc; goto dispatch; }
goto P_0c07a9a6;
P_0c07a9a4: /* original e417, guest PC 0x0c07a9a4 */
if(!s->budget--) { s->failed_pc=0x0c07a9a4u; return 0; }
r[4]=0x00000017u;
goto P_0c07a9a6;
P_0c07a9a6: /* original d413, guest PC 0x0c07a9a6 */
if(!s->budget--) { s->failed_pc=0x0c07a9a6u; return 0; }
r[4]=read(ram,0x0c07a9f4u,4);
goto P_0c07a9a8;
P_0c07a9a8: /* original bf1e, guest PC 0x0c07a9a8 */
if(!s->budget--) { s->failed_pc=0x0c07a9a8u; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07a9acu;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a9acu) { target=s->pc; goto dispatch; }
goto P_0c07a9ac;
P_0c07a9aa: /* original 65e3, guest PC 0x0c07a9aa */
if(!s->budget--) { s->failed_pc=0x0c07a9aau; return 0; }
r[5]=r[14];
goto P_0c07a9ac;
P_0c07a9ac: /* original e317, guest PC 0x0c07a9ac */
if(!s->budget--) { s->failed_pc=0x0c07a9acu; return 0; }
r[3]=0x00000017u;
goto P_0c07a9ae;
P_0c07a9ae: /* original e02e, guest PC 0x0c07a9ae */
if(!s->budget--) { s->failed_pc=0x0c07a9aeu; return 0; }
r[0]=0x0000002eu;
goto P_0c07a9b0;
P_0c07a9b0: /* original a036, guest PC 0x0c07a9b0 */
if(!s->budget--) { s->failed_pc=0x0c07a9b0u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07aa20;
P_0c07a9b2: /* original 0d35, guest PC 0x0c07a9b2 */
if(!s->budget--) { s->failed_pc=0x0c07a9b2u; return 0; }
write(ram,r[13]+r[0],r[3],2);
if(!vf3_matrix_family(0x0c07a9b4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07a9b4u; return 0; } return 1;
P_0c07a9f8: /* original 60b3, guest PC 0x0c07a9f8 */
if(!s->budget--) { s->failed_pc=0x0c07a9f8u; return 0; }
r[0]=r[11];
goto P_0c07a9fa;
P_0c07a9fa: /* original 880c, guest PC 0x0c07a9fa */
if(!s->budget--) { s->failed_pc=0x0c07a9fau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c07a9fc;
P_0c07a9fc: /* original 8902, guest PC 0x0c07a9fc */
if(!s->budget--) { s->failed_pc=0x0c07a9fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07aa04; }
goto P_0c07a9fe;
P_0c07a9fe: /* original 60b3, guest PC 0x0c07a9fe */
if(!s->budget--) { s->failed_pc=0x0c07a9feu; return 0; }
r[0]=r[11];
goto P_0c07aa00;
P_0c07aa00: /* original 880d, guest PC 0x0c07aa00 */
if(!s->budget--) { s->failed_pc=0x0c07aa00u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c07aa02;
P_0c07aa02: /* original 8b08, guest PC 0x0c07aa02 */
if(!s->budget--) { s->failed_pc=0x0c07aa02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07aa16; }
goto P_0c07aa04;
P_0c07aa04: /* original 4c0b, guest PC 0x0c07aa04 */
if(!s->budget--) { s->failed_pc=0x0c07aa04u; return 0; }
target=r[12];
r[16]=code_base|0x0c07aa08u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07aa08u) { target=s->pc; goto dispatch; }
goto P_0c07aa08;
P_0c07aa06: /* original 64b3, guest PC 0x0c07aa06 */
if(!s->budget--) { s->failed_pc=0x0c07aa06u; return 0; }
r[4]=r[11];
goto P_0c07aa08;
P_0c07aa08: /* original 65e3, guest PC 0x0c07aa08 */
if(!s->budget--) { s->failed_pc=0x0c07aa08u; return 0; }
r[5]=r[14];
goto P_0c07aa0a;
P_0c07aa0a: /* original beed, guest PC 0x0c07aa0a */
if(!s->budget--) { s->failed_pc=0x0c07aa0au; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07aa0eu;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07aa0eu) { target=s->pc; goto dispatch; }
goto P_0c07aa0e;
P_0c07aa0c: /* original 6493, guest PC 0x0c07aa0c */
if(!s->budget--) { s->failed_pc=0x0c07aa0cu; return 0; }
r[4]=r[9];
goto P_0c07aa0e;
P_0c07aa0e: /* original 60ad, guest PC 0x0c07aa0e */
if(!s->budget--) { s->failed_pc=0x0c07aa0eu; return 0; }
r[0]=r[10]&65535u;
goto P_0c07aa10;
P_0c07aa10: /* original 4000, guest PC 0x0c07aa10 */
if(!s->budget--) { s->failed_pc=0x0c07aa10u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07aa12;
P_0c07aa12: /* original a005, guest PC 0x0c07aa12 */
if(!s->budget--) { s->failed_pc=0x0c07aa12u; return 0; }
write(ram,r[13]+r[0],r[10],2);
goto P_0c07aa20;
P_0c07aa14: /* original 0da5, guest PC 0x0c07aa14 */
if(!s->budget--) { s->failed_pc=0x0c07aa14u; return 0; }
write(ram,r[13]+r[0],r[10],2);
goto P_0c07aa16;
P_0c07aa16: /* original bef6, guest PC 0x0c07aa16 */
if(!s->budget--) { s->failed_pc=0x0c07aa16u; return 0; }
target=code_base|0x0c07a806u; r[16]=code_base|0x0c07aa1au;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07aa1au) { target=s->pc; goto dispatch; }
goto P_0c07aa1a;
P_0c07aa18: /* original 65e3, guest PC 0x0c07aa18 */
if(!s->budget--) { s->failed_pc=0x0c07aa18u; return 0; }
r[5]=r[14];
goto P_0c07aa1a;
P_0c07aa1a: /* original 60ad, guest PC 0x0c07aa1a */
if(!s->budget--) { s->failed_pc=0x0c07aa1au; return 0; }
r[0]=r[10]&65535u;
goto P_0c07aa1c;
P_0c07aa1c: /* original 4000, guest PC 0x0c07aa1c */
if(!s->budget--) { s->failed_pc=0x0c07aa1cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07aa1e;
P_0c07aa1e: /* original 0db5, guest PC 0x0c07aa1e */
if(!s->budget--) { s->failed_pc=0x0c07aa1eu; return 0; }
write(ram,r[13]+r[0],r[11],2);
goto P_0c07aa20;
P_0c07aa20: /* original 4f26, guest PC 0x0c07aa20 */
if(!s->budget--) { s->failed_pc=0x0c07aa20u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07aa22;
P_0c07aa22: /* original 69f6, guest PC 0x0c07aa22 */
if(!s->budget--) { s->failed_pc=0x0c07aa22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07aa24;
P_0c07aa24: /* original 6af6, guest PC 0x0c07aa24 */
if(!s->budget--) { s->failed_pc=0x0c07aa24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07aa26;
P_0c07aa26: /* original 6bf6, guest PC 0x0c07aa26 */
if(!s->budget--) { s->failed_pc=0x0c07aa26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07aa28;
P_0c07aa28: /* original 6cf6, guest PC 0x0c07aa28 */
if(!s->budget--) { s->failed_pc=0x0c07aa28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07aa2a;
P_0c07aa2a: /* original 6df6, guest PC 0x0c07aa2a */
if(!s->budget--) { s->failed_pc=0x0c07aa2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07aa2c;
P_0c07aa2c: /* original 000b, guest PC 0x0c07aa2c */
if(!s->budget--) { s->failed_pc=0x0c07aa2cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07aa2e: /* original 6ef6, guest PC 0x0c07aa2e */
if(!s->budget--) { s->failed_pc=0x0c07aa2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07aa30u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07aa30u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
