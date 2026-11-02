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
int vf3_away_batch15_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08b38au: goto P_0c08b38a;
case 0x0c08b38cu: goto P_0c08b38c;
case 0x0c08b38eu: goto P_0c08b38e;
case 0x0c08b390u: goto P_0c08b390;
case 0x0c08b392u: goto P_0c08b392;
case 0x0c08b394u: goto P_0c08b394;
case 0x0c08b396u: goto P_0c08b396;
case 0x0c08b398u: goto P_0c08b398;
case 0x0c08b39au: goto P_0c08b39a;
case 0x0c08b39cu: goto P_0c08b39c;
case 0x0c08b39eu: goto P_0c08b39e;
case 0x0c08b3a0u: goto P_0c08b3a0;
case 0x0c08b3a2u: goto P_0c08b3a2;
case 0x0c08b3a4u: goto P_0c08b3a4;
case 0x0c08b3a6u: goto P_0c08b3a6;
case 0x0c08b3a8u: goto P_0c08b3a8;
case 0x0c08b3aau: goto P_0c08b3aa;
case 0x0c08b3acu: goto P_0c08b3ac;
case 0x0c08b3aeu: goto P_0c08b3ae;
case 0x0c08b3b0u: goto P_0c08b3b0;
case 0x0c08b3b2u: goto P_0c08b3b2;
case 0x0c08b3b4u: goto P_0c08b3b4;
case 0x0c08b3b6u: goto P_0c08b3b6;
case 0x0c08b3b8u: goto P_0c08b3b8;
case 0x0c08b3bau: goto P_0c08b3ba;
case 0x0c08b3bcu: goto P_0c08b3bc;
case 0x0c08b3beu: goto P_0c08b3be;
case 0x0c08b3c0u: goto P_0c08b3c0;
case 0x0c08b3c2u: goto P_0c08b3c2;
case 0x0c08b3c4u: goto P_0c08b3c4;
case 0x0c08b3c6u: goto P_0c08b3c6;
case 0x0c08b3c8u: goto P_0c08b3c8;
case 0x0c08b3cau: goto P_0c08b3ca;
case 0x0c08b3ccu: goto P_0c08b3cc;
case 0x0c08b3ceu: goto P_0c08b3ce;
case 0x0c08b3d0u: goto P_0c08b3d0;
case 0x0c08b3d2u: goto P_0c08b3d2;
case 0x0c08b3d4u: goto P_0c08b3d4;
case 0x0c08b3d6u: goto P_0c08b3d6;
case 0x0c08b3d8u: goto P_0c08b3d8;
case 0x0c08b3dau: goto P_0c08b3da;
case 0x0c08b3dcu: goto P_0c08b3dc;
case 0x0c08b3deu: goto P_0c08b3de;
case 0x0c08b3e0u: goto P_0c08b3e0;
case 0x0c08b3e2u: goto P_0c08b3e2;
case 0x0c08b3e4u: goto P_0c08b3e4;
case 0x0c08b3e6u: goto P_0c08b3e6;
case 0x0c08b3e8u: goto P_0c08b3e8;
case 0x0c08b3eau: goto P_0c08b3ea;
case 0x0c08c82eu: goto P_0c08c82e;
case 0x0c08c830u: goto P_0c08c830;
case 0x0c08c832u: goto P_0c08c832;
case 0x0c08c834u: goto P_0c08c834;
case 0x0c08c836u: goto P_0c08c836;
case 0x0c08c838u: goto P_0c08c838;
case 0x0c08c83au: goto P_0c08c83a;
case 0x0c08c83cu: goto P_0c08c83c;
case 0x0c08c83eu: goto P_0c08c83e;
case 0x0c08c840u: goto P_0c08c840;
case 0x0c08c842u: goto P_0c08c842;
case 0x0c08c844u: goto P_0c08c844;
case 0x0c08c846u: goto P_0c08c846;
case 0x0c08c848u: goto P_0c08c848;
case 0x0c08c84au: goto P_0c08c84a;
case 0x0c08c84cu: goto P_0c08c84c;
case 0x0c08c84eu: goto P_0c08c84e;
case 0x0c08c850u: goto P_0c08c850;
case 0x0c08c852u: goto P_0c08c852;
case 0x0c08c854u: goto P_0c08c854;
case 0x0c08c856u: goto P_0c08c856;
case 0x0c08c858u: goto P_0c08c858;
case 0x0c08c85au: goto P_0c08c85a;
case 0x0c08c85cu: goto P_0c08c85c;
case 0x0c08c87cu: goto P_0c08c87c;
case 0x0c08c87eu: goto P_0c08c87e;
case 0x0c08c880u: goto P_0c08c880;
case 0x0c08c882u: goto P_0c08c882;
case 0x0c08c884u: goto P_0c08c884;
case 0x0c08c886u: goto P_0c08c886;
case 0x0c08c888u: goto P_0c08c888;
case 0x0c08c88au: goto P_0c08c88a;
case 0x0c08c88cu: goto P_0c08c88c;
case 0x0c08c88eu: goto P_0c08c88e;
case 0x0c08c890u: goto P_0c08c890;
case 0x0c08c892u: goto P_0c08c892;
case 0x0c08c894u: goto P_0c08c894;
case 0x0c08c896u: goto P_0c08c896;
case 0x0c08c898u: goto P_0c08c898;
case 0x0c08c89au: goto P_0c08c89a;
case 0x0c08c89cu: goto P_0c08c89c;
case 0x0c08c89eu: goto P_0c08c89e;
case 0x0c08c8a0u: goto P_0c08c8a0;
case 0x0c08c8a2u: goto P_0c08c8a2;
case 0x0c08c8a4u: goto P_0c08c8a4;
case 0x0c08c8a6u: goto P_0c08c8a6;
case 0x0c08c8a8u: goto P_0c08c8a8;
case 0x0c08c8aau: goto P_0c08c8aa;
case 0x0c08c8acu: goto P_0c08c8ac;
case 0x0c08c8aeu: goto P_0c08c8ae;
case 0x0c08c8b0u: goto P_0c08c8b0;
case 0x0c08c8b2u: goto P_0c08c8b2;
case 0x0c08c8b4u: goto P_0c08c8b4;
case 0x0c08c8b6u: goto P_0c08c8b6;
case 0x0c08c8b8u: goto P_0c08c8b8;
case 0x0c08c8bau: goto P_0c08c8ba;
case 0x0c08c8bcu: goto P_0c08c8bc;
case 0x0c08c8beu: goto P_0c08c8be;
case 0x0c08c8c0u: goto P_0c08c8c0;
case 0x0c08c8c2u: goto P_0c08c8c2;
case 0x0c08c8c4u: goto P_0c08c8c4;
case 0x0c08c8c6u: goto P_0c08c8c6;
case 0x0c08c8c8u: goto P_0c08c8c8;
case 0x0c08c8cau: goto P_0c08c8ca;
case 0x0c08c8ccu: goto P_0c08c8cc;
case 0x0c08c8ceu: goto P_0c08c8ce;
case 0x0c08c8d0u: goto P_0c08c8d0;
case 0x0c08c8d2u: goto P_0c08c8d2;
case 0x0c08c8d4u: goto P_0c08c8d4;
case 0x0c08c8d6u: goto P_0c08c8d6;
case 0x0c08c8d8u: goto P_0c08c8d8;
case 0x0c08c8dau: goto P_0c08c8da;
case 0x0c08c8dcu: goto P_0c08c8dc;
case 0x0c08c8deu: goto P_0c08c8de;
case 0x0c08c8e0u: goto P_0c08c8e0;
case 0x0c08c8e2u: goto P_0c08c8e2;
case 0x0c08c8e4u: goto P_0c08c8e4;
case 0x0c08c8e6u: goto P_0c08c8e6;
case 0x0c08c8e8u: goto P_0c08c8e8;
case 0x0c08c8eau: goto P_0c08c8ea;
case 0x0c08c8ecu: goto P_0c08c8ec;
case 0x0c08c8eeu: goto P_0c08c8ee;
case 0x0c08c8f0u: goto P_0c08c8f0;
case 0x0c08c8f2u: goto P_0c08c8f2;
case 0x0c08c8f4u: goto P_0c08c8f4;
case 0x0c08c8f6u: goto P_0c08c8f6;
case 0x0c08c8f8u: goto P_0c08c8f8;
case 0x0c08c8fau: goto P_0c08c8fa;
case 0x0c08c8fcu: goto P_0c08c8fc;
case 0x0c08c8feu: goto P_0c08c8fe;
case 0x0c08c900u: goto P_0c08c900;
case 0x0c08c902u: goto P_0c08c902;
case 0x0c08c904u: goto P_0c08c904;
case 0x0c08c906u: goto P_0c08c906;
case 0x0c08c908u: goto P_0c08c908;
case 0x0c08c90au: goto P_0c08c90a;
case 0x0c08c90cu: goto P_0c08c90c;
case 0x0c08c90eu: goto P_0c08c90e;
case 0x0c08c910u: goto P_0c08c910;
case 0x0c08c912u: goto P_0c08c912;
case 0x0c08c914u: goto P_0c08c914;
case 0x0c08c916u: goto P_0c08c916;
case 0x0c08c918u: goto P_0c08c918;
case 0x0c08c91au: goto P_0c08c91a;
case 0x0c08c91cu: goto P_0c08c91c;
case 0x0c08c91eu: goto P_0c08c91e;
case 0x0c08c920u: goto P_0c08c920;
case 0x0c08c922u: goto P_0c08c922;
case 0x0c08c924u: goto P_0c08c924;
case 0x0c08c926u: goto P_0c08c926;
case 0x0c08c928u: goto P_0c08c928;
case 0x0c08c92au: goto P_0c08c92a;
case 0x0c08c92cu: goto P_0c08c92c;
case 0x0c08c92eu: goto P_0c08c92e;
case 0x0c08c930u: goto P_0c08c930;
case 0x0c08c932u: goto P_0c08c932;
case 0x0c08c934u: goto P_0c08c934;
case 0x0c08c936u: goto P_0c08c936;
case 0x0c08c938u: goto P_0c08c938;
case 0x0c08c93au: goto P_0c08c93a;
case 0x0c08c93cu: goto P_0c08c93c;
case 0x0c08c93eu: goto P_0c08c93e;
case 0x0c08c940u: goto P_0c08c940;
case 0x0c08c942u: goto P_0c08c942;
case 0x0c08c944u: goto P_0c08c944;
case 0x0c08c946u: goto P_0c08c946;
case 0x0c08c948u: goto P_0c08c948;
case 0x0c08c94au: goto P_0c08c94a;
case 0x0c08c94cu: goto P_0c08c94c;
case 0x0c08c94eu: goto P_0c08c94e;
case 0x0c08c950u: goto P_0c08c950;
case 0x0c08c952u: goto P_0c08c952;
case 0x0c08c954u: goto P_0c08c954;
case 0x0c08c956u: goto P_0c08c956;
case 0x0c08c958u: goto P_0c08c958;
case 0x0c08c95au: goto P_0c08c95a;
case 0x0c08c95cu: goto P_0c08c95c;
case 0x0c08c95eu: goto P_0c08c95e;
case 0x0c08c960u: goto P_0c08c960;
case 0x0c08c962u: goto P_0c08c962;
case 0x0c08c964u: goto P_0c08c964;
case 0x0c08c966u: goto P_0c08c966;
case 0x0c08c968u: goto P_0c08c968;
case 0x0c08c96au: goto P_0c08c96a;
case 0x0c08c96cu: goto P_0c08c96c;
case 0x0c08c96eu: goto P_0c08c96e;
case 0x0c08c970u: goto P_0c08c970;
case 0x0c08c972u: goto P_0c08c972;
case 0x0c08c974u: goto P_0c08c974;
case 0x0c08c976u: goto P_0c08c976;
case 0x0c08c990u: goto P_0c08c990;
case 0x0c08c992u: goto P_0c08c992;
case 0x0c08c994u: goto P_0c08c994;
case 0x0c08c996u: goto P_0c08c996;
case 0x0c08c998u: goto P_0c08c998;
case 0x0c08c99au: goto P_0c08c99a;
case 0x0c08c99cu: goto P_0c08c99c;
case 0x0c08c99eu: goto P_0c08c99e;
case 0x0c08c9a0u: goto P_0c08c9a0;
case 0x0c08c9a2u: goto P_0c08c9a2;
case 0x0c08c9a4u: goto P_0c08c9a4;
case 0x0c08c9a6u: goto P_0c08c9a6;
case 0x0c08c9a8u: goto P_0c08c9a8;
case 0x0c08c9aau: goto P_0c08c9aa;
case 0x0c08c9acu: goto P_0c08c9ac;
case 0x0c08c9aeu: goto P_0c08c9ae;
case 0x0c08c9b0u: goto P_0c08c9b0;
case 0x0c08c9b2u: goto P_0c08c9b2;
case 0x0c08c9b4u: goto P_0c08c9b4;
case 0x0c08c9b6u: goto P_0c08c9b6;
case 0x0c08c9b8u: goto P_0c08c9b8;
case 0x0c08c9bau: goto P_0c08c9ba;
case 0x0c08c9bcu: goto P_0c08c9bc;
case 0x0c08c9beu: goto P_0c08c9be;
case 0x0c08c9c0u: goto P_0c08c9c0;
case 0x0c08c9c2u: goto P_0c08c9c2;
case 0x0c08c9c4u: goto P_0c08c9c4;
case 0x0c08c9c6u: goto P_0c08c9c6;
case 0x0c08c9c8u: goto P_0c08c9c8;
case 0x0c08c9cau: goto P_0c08c9ca;
case 0x0c08c9ccu: goto P_0c08c9cc;
case 0x0c08c9ceu: goto P_0c08c9ce;
case 0x0c08c9d0u: goto P_0c08c9d0;
case 0x0c08c9d2u: goto P_0c08c9d2;
case 0x0c08c9d4u: goto P_0c08c9d4;
case 0x0c08c9d6u: goto P_0c08c9d6;
case 0x0c08c9d8u: goto P_0c08c9d8;
case 0x0c08c9dau: goto P_0c08c9da;
case 0x0c08c9dcu: goto P_0c08c9dc;
case 0x0c08c9deu: goto P_0c08c9de;
case 0x0c08c9e0u: goto P_0c08c9e0;
case 0x0c08c9e2u: goto P_0c08c9e2;
case 0x0c08c9e4u: goto P_0c08c9e4;
case 0x0c08c9e6u: goto P_0c08c9e6;
case 0x0c08c9e8u: goto P_0c08c9e8;
case 0x0c08c9eau: goto P_0c08c9ea;
case 0x0c08c9ecu: goto P_0c08c9ec;
case 0x0c08c9eeu: goto P_0c08c9ee;
case 0x0c08c9f0u: goto P_0c08c9f0;
case 0x0c08c9f2u: goto P_0c08c9f2;
case 0x0c08c9f4u: goto P_0c08c9f4;
case 0x0c08c9f6u: goto P_0c08c9f6;
case 0x0c08c9f8u: goto P_0c08c9f8;
case 0x0c08c9fau: goto P_0c08c9fa;
case 0x0c08c9fcu: goto P_0c08c9fc;
case 0x0c08c9feu: goto P_0c08c9fe;
case 0x0c08ca00u: goto P_0c08ca00;
case 0x0c08ca02u: goto P_0c08ca02;
case 0x0c08ca04u: goto P_0c08ca04;
case 0x0c08ca06u: goto P_0c08ca06;
case 0x0c08ca08u: goto P_0c08ca08;
case 0x0c08ca0au: goto P_0c08ca0a;
case 0x0c08ca0cu: goto P_0c08ca0c;
case 0x0c08ca0eu: goto P_0c08ca0e;
case 0x0c08ca10u: goto P_0c08ca10;
case 0x0c08ca12u: goto P_0c08ca12;
case 0x0c08ca14u: goto P_0c08ca14;
case 0x0c08ca16u: goto P_0c08ca16;
case 0x0c08ca18u: goto P_0c08ca18;
case 0x0c08ca1au: goto P_0c08ca1a;
case 0x0c08ca1cu: goto P_0c08ca1c;
case 0x0c08ca1eu: goto P_0c08ca1e;
case 0x0c08ca20u: goto P_0c08ca20;
case 0x0c08ca22u: goto P_0c08ca22;
case 0x0c08ca24u: goto P_0c08ca24;
case 0x0c08ca26u: goto P_0c08ca26;
case 0x0c08ca28u: goto P_0c08ca28;
case 0x0c08ca2au: goto P_0c08ca2a;
case 0x0c08ca2cu: goto P_0c08ca2c;
case 0x0c08ca54u: goto P_0c08ca54;
case 0x0c08ca56u: goto P_0c08ca56;
case 0x0c08ca58u: goto P_0c08ca58;
case 0x0c08ca5au: goto P_0c08ca5a;
case 0x0c08ca5cu: goto P_0c08ca5c;
case 0x0c08ca5eu: goto P_0c08ca5e;
case 0x0c08ca60u: goto P_0c08ca60;
case 0x0c08ca62u: goto P_0c08ca62;
case 0x0c08ca64u: goto P_0c08ca64;
case 0x0c08ca66u: goto P_0c08ca66;
case 0x0c08ca68u: goto P_0c08ca68;
case 0x0c08ca6au: goto P_0c08ca6a;
case 0x0c08ca6cu: goto P_0c08ca6c;
case 0x0c08ca6eu: goto P_0c08ca6e;
case 0x0c08ca70u: goto P_0c08ca70;
case 0x0c08ca72u: goto P_0c08ca72;
case 0x0c08ca74u: goto P_0c08ca74;
case 0x0c08ca76u: goto P_0c08ca76;
case 0x0c08ca78u: goto P_0c08ca78;
case 0x0c08ca7au: goto P_0c08ca7a;
case 0x0c08ca7cu: goto P_0c08ca7c;
case 0x0c08ca7eu: goto P_0c08ca7e;
case 0x0c08ca80u: goto P_0c08ca80;
case 0x0c08ca82u: goto P_0c08ca82;
case 0x0c08ca84u: goto P_0c08ca84;
case 0x0c08ca86u: goto P_0c08ca86;
case 0x0c08ca88u: goto P_0c08ca88;
case 0x0c08ca8au: goto P_0c08ca8a;
case 0x0c08ca8cu: goto P_0c08ca8c;
case 0x0c08ca8eu: goto P_0c08ca8e;
case 0x0c08ca90u: goto P_0c08ca90;
case 0x0c08ca92u: goto P_0c08ca92;
case 0x0c08ca94u: goto P_0c08ca94;
case 0x0c08ca96u: goto P_0c08ca96;
case 0x0c08ca98u: goto P_0c08ca98;
case 0x0c08ca9au: goto P_0c08ca9a;
case 0x0c08ca9cu: goto P_0c08ca9c;
case 0x0c08ca9eu: goto P_0c08ca9e;
case 0x0c08caa0u: goto P_0c08caa0;
case 0x0c08caa2u: goto P_0c08caa2;
case 0x0c08caa4u: goto P_0c08caa4;
case 0x0c08caa6u: goto P_0c08caa6;
case 0x0c08caa8u: goto P_0c08caa8;
case 0x0c08caaau: goto P_0c08caaa;
case 0x0c08caacu: goto P_0c08caac;
case 0x0c08caaeu: goto P_0c08caae;
case 0x0c08cab0u: goto P_0c08cab0;
case 0x0c08cab2u: goto P_0c08cab2;
case 0x0c08cab4u: goto P_0c08cab4;
case 0x0c08cab6u: goto P_0c08cab6;
case 0x0c08cab8u: goto P_0c08cab8;
case 0x0c08cabau: goto P_0c08caba;
case 0x0c08cabcu: goto P_0c08cabc;
case 0x0c08cabeu: goto P_0c08cabe;
case 0x0c08cac0u: goto P_0c08cac0;
case 0x0c08cac2u: goto P_0c08cac2;
case 0x0c08cac4u: goto P_0c08cac4;
case 0x0c08cac6u: goto P_0c08cac6;
case 0x0c08cac8u: goto P_0c08cac8;
case 0x0c08cacau: goto P_0c08caca;
case 0x0c08caccu: goto P_0c08cacc;
case 0x0c08caceu: goto P_0c08cace;
case 0x0c08cad0u: goto P_0c08cad0;
case 0x0c08cad2u: goto P_0c08cad2;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08b38a: /* original 2fe6, guest PC 0x0c08b38a */
if(!s->budget--) { s->failed_pc=0x0c08b38au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b38c;
P_0c08b38c: /* original e054, guest PC 0x0c08b38c */
if(!s->budget--) { s->failed_pc=0x0c08b38cu; return 0; }
r[0]=0x00000054u;
goto P_0c08b38e;
P_0c08b38e: /* original 2fd6, guest PC 0x0c08b38e */
if(!s->budget--) { s->failed_pc=0x0c08b38eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b390;
P_0c08b390: /* original 6d43, guest PC 0x0c08b390 */
if(!s->budget--) { s->failed_pc=0x0c08b390u; return 0; }
r[13]=r[4];
goto P_0c08b392;
P_0c08b392: /* original d318, guest PC 0x0c08b392 */
if(!s->budget--) { s->failed_pc=0x0c08b392u; return 0; }
r[3]=read(ram,0x0c08b3f4u,4);
goto P_0c08b394;
P_0c08b394: /* original 4f22, guest PC 0x0c08b394 */
if(!s->budget--) { s->failed_pc=0x0c08b394u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b396;
P_0c08b396: /* original 6432, guest PC 0x0c08b396 */
if(!s->budget--) { s->failed_pc=0x0c08b396u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c08b398;
P_0c08b398: /* original 044d, guest PC 0x0c08b398 */
if(!s->budget--) { s->failed_pc=0x0c08b398u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08b39a;
P_0c08b39a: /* original 7ff8, guest PC 0x0c08b39a */
if(!s->budget--) { s->failed_pc=0x0c08b39au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c08b39c;
P_0c08b39c: /* original d016, guest PC 0x0c08b39c */
if(!s->budget--) { s->failed_pc=0x0c08b39cu; return 0; }
r[0]=read(ram,0x0c08b3f8u,4);
goto P_0c08b39e;
P_0c08b39e: /* original 61f3, guest PC 0x0c08b39e */
if(!s->budget--) { s->failed_pc=0x0c08b39eu; return 0; }
r[1]=r[15];
goto P_0c08b3a0;
P_0c08b3a0: /* original 4400, guest PC 0x0c08b3a0 */
if(!s->budget--) { s->failed_pc=0x0c08b3a0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08b3a2;
P_0c08b3a2: /* original 024d, guest PC 0x0c08b3a2 */
if(!s->budget--) { s->failed_pc=0x0c08b3a2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08b3a4;
P_0c08b3a4: /* original 6543, guest PC 0x0c08b3a4 */
if(!s->budget--) { s->failed_pc=0x0c08b3a4u; return 0; }
r[5]=r[4];
goto P_0c08b3a6;
P_0c08b3a6: /* original 7104, guest PC 0x0c08b3a6 */
if(!s->budget--) { s->failed_pc=0x0c08b3a6u; return 0; }
r[1]+=0x00000004u;
goto P_0c08b3a8;
P_0c08b3a8: /* original 2121, guest PC 0x0c08b3a8 */
if(!s->budget--) { s->failed_pc=0x0c08b3a8u; return 0; }
write(ram,r[1],r[2],2);
goto P_0c08b3aa;
P_0c08b3aa: /* original d014, guest PC 0x0c08b3aa */
if(!s->budget--) { s->failed_pc=0x0c08b3aau; return 0; }
r[0]=read(ram,0x0c08b3fcu,4);
goto P_0c08b3ac;
P_0c08b3ac: /* original 035d, guest PC 0x0c08b3ac */
if(!s->budget--) { s->failed_pc=0x0c08b3acu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c08b3ae;
P_0c08b3ae: /* original 2f31, guest PC 0x0c08b3ae */
if(!s->budget--) { s->failed_pc=0x0c08b3aeu; return 0; }
write(ram,r[15],r[3],2);
goto P_0c08b3b0;
P_0c08b3b0: /* original de13, guest PC 0x0c08b3b0 */
if(!s->budget--) { s->failed_pc=0x0c08b3b0u; return 0; }
r[14]=read(ram,0x0c08b400u,4);
goto P_0c08b3b2;
P_0c08b3b2: /* original 85f2, guest PC 0x0c08b3b2 */
if(!s->budget--) { s->failed_pc=0x0c08b3b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c08b3b4;
P_0c08b3b4: /* original 4e0b, guest PC 0x0c08b3b4 */
if(!s->budget--) { s->failed_pc=0x0c08b3b4u; return 0; }
target=r[14];
r[16]=code_base|0x0c08b3b8u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b3b8u) { target=s->pc; goto dispatch; }
goto P_0c08b3b8;
P_0c08b3b6: /* original 6403, guest PC 0x0c08b3b6 */
if(!s->budget--) { s->failed_pc=0x0c08b3b6u; return 0; }
r[4]=r[0];
goto P_0c08b3b8;
P_0c08b3b8: /* original 4e0b, guest PC 0x0c08b3b8 */
if(!s->budget--) { s->failed_pc=0x0c08b3b8u; return 0; }
target=r[14];
r[16]=code_base|0x0c08b3bcu;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b3bcu) { target=s->pc; goto dispatch; }
goto P_0c08b3bc;
P_0c08b3ba: /* original 64f1, guest PC 0x0c08b3ba */
if(!s->budget--) { s->failed_pc=0x0c08b3bau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c08b3bc;
P_0c08b3bc: /* original 85d7, guest PC 0x0c08b3bc */
if(!s->budget--) { s->failed_pc=0x0c08b3bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+14,2);
goto P_0c08b3be;
P_0c08b3be: /* original d111, guest PC 0x0c08b3be */
if(!s->budget--) { s->failed_pc=0x0c08b3beu; return 0; }
r[1]=read(ram,0x0c08b404u,4);
goto P_0c08b3c0;
P_0c08b3c0: /* original 6503, guest PC 0x0c08b3c0 */
if(!s->budget--) { s->failed_pc=0x0c08b3c0u; return 0; }
r[5]=r[0];
goto P_0c08b3c2;
P_0c08b3c2: /* original 85d8, guest PC 0x0c08b3c2 */
if(!s->budget--) { s->failed_pc=0x0c08b3c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+16,2);
goto P_0c08b3c4;
P_0c08b3c4: /* original 6403, guest PC 0x0c08b3c4 */
if(!s->budget--) { s->failed_pc=0x0c08b3c4u; return 0; }
r[4]=r[0];
goto P_0c08b3c6;
P_0c08b3c6: /* original 605f, guest PC 0x0c08b3c6 */
if(!s->budget--) { s->failed_pc=0x0c08b3c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c08b3c8;
P_0c08b3c8: /* original 4000, guest PC 0x0c08b3c8 */
if(!s->budget--) { s->failed_pc=0x0c08b3c8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c08b3ca;
P_0c08b3ca: /* original 001d, guest PC 0x0c08b3ca */
if(!s->budget--) { s->failed_pc=0x0c08b3cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c08b3cc;
P_0c08b3cc: /* original 644f, guest PC 0x0c08b3cc */
if(!s->budget--) { s->failed_pc=0x0c08b3ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c08b3ce;
P_0c08b3ce: /* original 4400, guest PC 0x0c08b3ce */
if(!s->budget--) { s->failed_pc=0x0c08b3ceu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08b3d0;
P_0c08b3d0: /* original 81f2, guest PC 0x0c08b3d0 */
if(!s->budget--) { s->failed_pc=0x0c08b3d0u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c08b3d2;
P_0c08b3d2: /* original d00d, guest PC 0x0c08b3d2 */
if(!s->budget--) { s->failed_pc=0x0c08b3d2u; return 0; }
r[0]=read(ram,0x0c08b408u,4);
goto P_0c08b3d4;
P_0c08b3d4: /* original 034d, guest PC 0x0c08b3d4 */
if(!s->budget--) { s->failed_pc=0x0c08b3d4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08b3d6;
P_0c08b3d6: /* original 2f31, guest PC 0x0c08b3d6 */
if(!s->budget--) { s->failed_pc=0x0c08b3d6u; return 0; }
write(ram,r[15],r[3],2);
goto P_0c08b3d8;
P_0c08b3d8: /* original 85f2, guest PC 0x0c08b3d8 */
if(!s->budget--) { s->failed_pc=0x0c08b3d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c08b3da;
P_0c08b3da: /* original 4e0b, guest PC 0x0c08b3da */
if(!s->budget--) { s->failed_pc=0x0c08b3dau; return 0; }
target=r[14];
r[16]=code_base|0x0c08b3deu;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b3deu) { target=s->pc; goto dispatch; }
goto P_0c08b3de;
P_0c08b3dc: /* original 6403, guest PC 0x0c08b3dc */
if(!s->budget--) { s->failed_pc=0x0c08b3dcu; return 0; }
r[4]=r[0];
goto P_0c08b3de;
P_0c08b3de: /* original 4e0b, guest PC 0x0c08b3de */
if(!s->budget--) { s->failed_pc=0x0c08b3deu; return 0; }
target=r[14];
r[16]=code_base|0x0c08b3e2u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b3e2u) { target=s->pc; goto dispatch; }
goto P_0c08b3e2;
P_0c08b3e0: /* original 64f1, guest PC 0x0c08b3e0 */
if(!s->budget--) { s->failed_pc=0x0c08b3e0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c08b3e2;
P_0c08b3e2: /* original 7f08, guest PC 0x0c08b3e2 */
if(!s->budget--) { s->failed_pc=0x0c08b3e2u; return 0; }
r[15]+=0x00000008u;
goto P_0c08b3e4;
P_0c08b3e4: /* original 4f26, guest PC 0x0c08b3e4 */
if(!s->budget--) { s->failed_pc=0x0c08b3e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b3e6;
P_0c08b3e6: /* original 6df6, guest PC 0x0c08b3e6 */
if(!s->budget--) { s->failed_pc=0x0c08b3e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08b3e8;
P_0c08b3e8: /* original 000b, guest PC 0x0c08b3e8 */
if(!s->budget--) { s->failed_pc=0x0c08b3e8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b3ea: /* original 6ef6, guest PC 0x0c08b3ea */
if(!s->budget--) { s->failed_pc=0x0c08b3eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08b3ecu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08b3ecu; return 0; } return 1;
P_0c08c82e: /* original 2fe6, guest PC 0x0c08c82e */
if(!s->budget--) { s->failed_pc=0x0c08c82eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08c830;
P_0c08c830: /* original e030, guest PC 0x0c08c830 */
if(!s->budget--) { s->failed_pc=0x0c08c830u; return 0; }
r[0]=0x00000030u;
goto P_0c08c832;
P_0c08c832: /* original 2fd6, guest PC 0x0c08c832 */
if(!s->budget--) { s->failed_pc=0x0c08c832u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08c834;
P_0c08c834: /* original 6e43, guest PC 0x0c08c834 */
if(!s->budget--) { s->failed_pc=0x0c08c834u; return 0; }
r[14]=r[4];
goto P_0c08c836;
P_0c08c836: /* original 2fc6, guest PC 0x0c08c836 */
if(!s->budget--) { s->failed_pc=0x0c08c836u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08c838;
P_0c08c838: /* original 6c53, guest PC 0x0c08c838 */
if(!s->budget--) { s->failed_pc=0x0c08c838u; return 0; }
r[12]=r[5];
goto P_0c08c83a;
P_0c08c83a: /* original 4f22, guest PC 0x0c08c83a */
if(!s->budget--) { s->failed_pc=0x0c08c83au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08c83c;
P_0c08c83c: /* original 03ec, guest PC 0x0c08c83c */
if(!s->budget--) { s->failed_pc=0x0c08c83cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08c83e;
P_0c08c83e: /* original d20d, guest PC 0x0c08c83e */
if(!s->budget--) { s->failed_pc=0x0c08c83eu; return 0; }
r[2]=read(ram,0x0c08c874u,4);
goto P_0c08c840;
P_0c08c840: /* original 633c, guest PC 0x0c08c840 */
if(!s->budget--) { s->failed_pc=0x0c08c840u; return 0; }
r[3]=r[3]&255u;
goto P_0c08c842;
P_0c08c842: /* original 7ffc, guest PC 0x0c08c842 */
if(!s->budget--) { s->failed_pc=0x0c08c842u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08c844;
P_0c08c844: /* original 420b, guest PC 0x0c08c844 */
if(!s->budget--) { s->failed_pc=0x0c08c844u; return 0; }
target=r[2];
r[16]=code_base|0x0c08c848u;
write(ram,r[15],r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08c848u) { target=s->pc; goto dispatch; }
goto P_0c08c848;
P_0c08c846: /* original 2f32, guest PC 0x0c08c846 */
if(!s->budget--) { s->failed_pc=0x0c08c846u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08c848;
P_0c08c848: /* original d30b, guest PC 0x0c08c848 */
if(!s->budget--) { s->failed_pc=0x0c08c848u; return 0; }
r[3]=read(ram,0x0c08c878u,4);
goto P_0c08c84a;
P_0c08c84a: /* original 6103, guest PC 0x0c08c84a */
if(!s->budget--) { s->failed_pc=0x0c08c84au; return 0; }
r[1]=r[0];
goto P_0c08c84c;
P_0c08c84c: /* original 430b, guest PC 0x0c08c84c */
if(!s->budget--) { s->failed_pc=0x0c08c84cu; return 0; }
target=r[3];
r[16]=code_base|0x0c08c850u;
tmp=read(ram,r[15],4);
r[0]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08c850u) { target=s->pc; goto dispatch; }
goto P_0c08c850;
P_0c08c84e: /* original 60f2, guest PC 0x0c08c84e */
if(!s->budget--) { s->failed_pc=0x0c08c84eu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c08c850;
P_0c08c850: /* original 6403, guest PC 0x0c08c850 */
if(!s->budget--) { s->failed_pc=0x0c08c850u; return 0; }
r[4]=r[0];
goto P_0c08c852;
P_0c08c852: /* original 2448, guest PC 0x0c08c852 */
if(!s->budget--) { s->failed_pc=0x0c08c852u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c08c854;
P_0c08c854: /* original 8912, guest PC 0x0c08c854 */
if(!s->budget--) { s->failed_pc=0x0c08c854u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08c87c; }
goto P_0c08c856;
P_0c08c856: /* original e04a, guest PC 0x0c08c856 */
if(!s->budget--) { s->failed_pc=0x0c08c856u; return 0; }
r[0]=0x0000004au;
goto P_0c08c858;
P_0c08c858: /* original 0ded, guest PC 0x0c08c858 */
if(!s->budget--) { s->failed_pc=0x0c08c858u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08c85a;
P_0c08c85a: /* original a031, guest PC 0x0c08c85a */
if(!s->budget--) { s->failed_pc=0x0c08c85au; return 0; }
r[13]=r[13]&65535u;
goto P_0c08c8c0;
P_0c08c85c: /* original 6ddd, guest PC 0x0c08c85c */
if(!s->budget--) { s->failed_pc=0x0c08c85cu; return 0; }
r[13]=r[13]&65535u;
if(!vf3_matrix_family(0x0c08c85eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08c85eu; return 0; } return 1;
P_0c08c87c: /* original e04c, guest PC 0x0c08c87c */
if(!s->budget--) { s->failed_pc=0x0c08c87cu; return 0; }
r[0]=0x0000004cu;
goto P_0c08c87e;
P_0c08c87e: /* original 957b, guest PC 0x0c08c87e */
if(!s->budget--) { s->failed_pc=0x0c08c87eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08c978u,2);
goto P_0c08c880;
P_0c08c880: /* original 04ce, guest PC 0x0c08c880 */
if(!s->budget--) { s->failed_pc=0x0c08c880u; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c08c882;
P_0c08c882: /* original 907a, guest PC 0x0c08c882 */
if(!s->budget--) { s->failed_pc=0x0c08c882u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08c97au,2);
goto P_0c08c884;
P_0c08c884: /* original 044c, guest PC 0x0c08c884 */
if(!s->budget--) { s->failed_pc=0x0c08c884u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c08c886;
P_0c08c886: /* original 644c, guest PC 0x0c08c886 */
if(!s->budget--) { s->failed_pc=0x0c08c886u; return 0; }
r[4]=r[4]&255u;
goto P_0c08c888;
P_0c08c888: /* original 6043, guest PC 0x0c08c888 */
if(!s->budget--) { s->failed_pc=0x0c08c888u; return 0; }
r[0]=r[4];
goto P_0c08c88a;
P_0c08c88a: /* original 8802, guest PC 0x0c08c88a */
if(!s->budget--) { s->failed_pc=0x0c08c88au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c08c88c;
P_0c08c88c: /* original 8d18, guest PC 0x0c08c88c */
if(!s->budget--) { s->failed_pc=0x0c08c88cu; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c08c8c0; }
goto P_0c08c890;
P_0c08c88e: /* original 6d53, guest PC 0x0c08c88e */
if(!s->budget--) { s->failed_pc=0x0c08c88eu; return 0; }
r[13]=r[5];
goto P_0c08c890;
P_0c08c890: /* original 6043, guest PC 0x0c08c890 */
if(!s->budget--) { s->failed_pc=0x0c08c890u; return 0; }
r[0]=r[4];
goto P_0c08c892;
P_0c08c892: /* original 8806, guest PC 0x0c08c892 */
if(!s->budget--) { s->failed_pc=0x0c08c892u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c08c894;
P_0c08c894: /* original 8914, guest PC 0x0c08c894 */
if(!s->budget--) { s->failed_pc=0x0c08c894u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08c8c0; }
goto P_0c08c896;
P_0c08c896: /* original 6043, guest PC 0x0c08c896 */
if(!s->budget--) { s->failed_pc=0x0c08c896u; return 0; }
r[0]=r[4];
goto P_0c08c898;
P_0c08c898: /* original 8805, guest PC 0x0c08c898 */
if(!s->budget--) { s->failed_pc=0x0c08c898u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c08c89a;
P_0c08c89a: /* original 8911, guest PC 0x0c08c89a */
if(!s->budget--) { s->failed_pc=0x0c08c89au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08c8c0; }
goto P_0c08c89c;
P_0c08c89c: /* original 2448, guest PC 0x0c08c89c */
if(!s->budget--) { s->failed_pc=0x0c08c89cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c08c89e;
P_0c08c89e: /* original 8b0e, guest PC 0x0c08c89e */
if(!s->budget--) { s->failed_pc=0x0c08c89eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08c8be; }
goto P_0c08c8a0;
P_0c08c8a0: /* original e04a, guest PC 0x0c08c8a0 */
if(!s->budget--) { s->failed_pc=0x0c08c8a0u; return 0; }
r[0]=0x0000004au;
goto P_0c08c8a2;
P_0c08c8a2: /* original 04ed, guest PC 0x0c08c8a2 */
if(!s->budget--) { s->failed_pc=0x0c08c8a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08c8a4;
P_0c08c8a4: /* original 644d, guest PC 0x0c08c8a4 */
if(!s->budget--) { s->failed_pc=0x0c08c8a4u; return 0; }
r[4]=r[4]&65535u;
goto P_0c08c8a6;
P_0c08c8a6: /* original 3450, guest PC 0x0c08c8a6 */
if(!s->budget--) { s->failed_pc=0x0c08c8a6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c08c8a8;
P_0c08c8a8: /* original 890a, guest PC 0x0c08c8a8 */
if(!s->budget--) { s->failed_pc=0x0c08c8a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08c8c0; }
goto P_0c08c8aa;
P_0c08c8aa: /* original d335, guest PC 0x0c08c8aa */
if(!s->budget--) { s->failed_pc=0x0c08c8aau; return 0; }
r[3]=read(ram,0x0c08c980u,4);
goto P_0c08c8ac;
P_0c08c8ac: /* original 430b, guest PC 0x0c08c8ac */
if(!s->budget--) { s->failed_pc=0x0c08c8acu; return 0; }
target=r[3];
r[16]=code_base|0x0c08c8b0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08c8b0u) { target=s->pc; goto dispatch; }
goto P_0c08c8b0;
P_0c08c8ae: /* original 0009, guest PC 0x0c08c8ae */
if(!s->budget--) { s->failed_pc=0x0c08c8aeu; return 0; }
goto P_0c08c8b0;
P_0c08c8b0: /* original d234, guest PC 0x0c08c8b0 */
if(!s->budget--) { s->failed_pc=0x0c08c8b0u; return 0; }
r[2]=read(ram,0x0c08c984u,4);
goto P_0c08c8b2;
P_0c08c8b2: /* original 6103, guest PC 0x0c08c8b2 */
if(!s->budget--) { s->failed_pc=0x0c08c8b2u; return 0; }
r[1]=r[0];
goto P_0c08c8b4;
P_0c08c8b4: /* original 420b, guest PC 0x0c08c8b4 */
if(!s->budget--) { s->failed_pc=0x0c08c8b4u; return 0; }
target=r[2];
r[16]=code_base|0x0c08c8b8u;
r[0]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08c8b8u) { target=s->pc; goto dispatch; }
goto P_0c08c8b8;
P_0c08c8b6: /* original e003, guest PC 0x0c08c8b6 */
if(!s->budget--) { s->failed_pc=0x0c08c8b6u; return 0; }
r[0]=0x00000003u;
goto P_0c08c8b8;
P_0c08c8b8: /* original 6403, guest PC 0x0c08c8b8 */
if(!s->budget--) { s->failed_pc=0x0c08c8b8u; return 0; }
r[4]=r[0];
goto P_0c08c8ba;
P_0c08c8ba: /* original 2448, guest PC 0x0c08c8ba */
if(!s->budget--) { s->failed_pc=0x0c08c8bau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c08c8bc;
P_0c08c8bc: /* original 8900, guest PC 0x0c08c8bc */
if(!s->budget--) { s->failed_pc=0x0c08c8bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08c8c0; }
goto P_0c08c8be;
P_0c08c8be: /* original 9d5d, guest PC 0x0c08c8be */
if(!s->budget--) { s->failed_pc=0x0c08c8beu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08c97cu,2);
goto P_0c08c8c0;
P_0c08c8c0: /* original e04a, guest PC 0x0c08c8c0 */
if(!s->budget--) { s->failed_pc=0x0c08c8c0u; return 0; }
r[0]=0x0000004au;
goto P_0c08c8c2;
P_0c08c8c2: /* original 0ed5, guest PC 0x0c08c8c2 */
if(!s->budget--) { s->failed_pc=0x0c08c8c2u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c08c8c4;
P_0c08c8c4: /* original e028, guest PC 0x0c08c8c4 */
if(!s->budget--) { s->failed_pc=0x0c08c8c4u; return 0; }
r[0]=0x00000028u;
goto P_0c08c8c6;
P_0c08c8c6: /* original 0ed5, guest PC 0x0c08c8c6 */
if(!s->budget--) { s->failed_pc=0x0c08c8c6u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c08c8c8;
P_0c08c8c8: /* original e040, guest PC 0x0c08c8c8 */
if(!s->budget--) { s->failed_pc=0x0c08c8c8u; return 0; }
r[0]=0x00000040u;
goto P_0c08c8ca;
P_0c08c8ca: /* original e400, guest PC 0x0c08c8ca */
if(!s->budget--) { s->failed_pc=0x0c08c8cau; return 0; }
r[4]=0x00000000u;
goto P_0c08c8cc;
P_0c08c8cc: /* original 1cdd, guest PC 0x0c08c8cc */
if(!s->budget--) { s->failed_pc=0x0c08c8ccu; return 0; }
write(ram,r[12]+52,r[13],4);
goto P_0c08c8ce;
P_0c08c8ce: /* original 0c46, guest PC 0x0c08c8ce */
if(!s->budget--) { s->failed_pc=0x0c08c8ceu; return 0; }
write(ram,r[12]+r[0],r[4],4);
goto P_0c08c8d0;
P_0c08c8d0: /* original b442, guest PC 0x0c08c8d0 */
if(!s->budget--) { s->failed_pc=0x0c08c8d0u; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08c8d4u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08c8d4u) { target=s->pc; goto dispatch; }
goto P_0c08c8d4;
P_0c08c8d2: /* original 64c3, guest PC 0x0c08c8d2 */
if(!s->budget--) { s->failed_pc=0x0c08c8d2u; return 0; }
r[4]=r[12];
goto P_0c08c8d4;
P_0c08c8d4: /* original e200, guest PC 0x0c08c8d4 */
if(!s->budget--) { s->failed_pc=0x0c08c8d4u; return 0; }
r[2]=0x00000000u;
goto P_0c08c8d6;
P_0c08c8d6: /* original 55ce, guest PC 0x0c08c8d6 */
if(!s->budget--) { s->failed_pc=0x0c08c8d6u; return 0; }
r[5]=read(ram,r[12]+56,4);
goto P_0c08c8d8;
P_0c08c8d8: /* original e02c, guest PC 0x0c08c8d8 */
if(!s->budget--) { s->failed_pc=0x0c08c8d8u; return 0; }
r[0]=0x0000002cu;
goto P_0c08c8da;
P_0c08c8da: /* original 54cf, guest PC 0x0c08c8da */
if(!s->budget--) { s->failed_pc=0x0c08c8dau; return 0; }
r[4]=read(ram,r[12]+60,4);
goto P_0c08c8dc;
P_0c08c8dc: /* original 0e24, guest PC 0x0c08c8dc */
if(!s->budget--) { s->failed_pc=0x0c08c8dcu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c08c8de;
P_0c08c8de: /* original e02d, guest PC 0x0c08c8de */
if(!s->budget--) { s->failed_pc=0x0c08c8deu; return 0; }
r[0]=0x0000002du;
goto P_0c08c8e0;
P_0c08c8e0: /* original 0e54, guest PC 0x0c08c8e0 */
if(!s->budget--) { s->failed_pc=0x0c08c8e0u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c08c8e2;
P_0c08c8e2: /* original e048, guest PC 0x0c08c8e2 */
if(!s->budget--) { s->failed_pc=0x0c08c8e2u; return 0; }
r[0]=0x00000048u;
goto P_0c08c8e4;
P_0c08c8e4: /* original 00ec, guest PC 0x0c08c8e4 */
if(!s->budget--) { s->failed_pc=0x0c08c8e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08c8e6;
P_0c08c8e6: /* original 8801, guest PC 0x0c08c8e6 */
if(!s->budget--) { s->failed_pc=0x0c08c8e6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08c8e8;
P_0c08c8e8: /* original 8905, guest PC 0x0c08c8e8 */
if(!s->budget--) { s->failed_pc=0x0c08c8e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08c8f6; }
goto P_0c08c8ea;
P_0c08c8ea: /* original 6043, guest PC 0x0c08c8ea */
if(!s->budget--) { s->failed_pc=0x0c08c8eau; return 0; }
r[0]=r[4];
goto P_0c08c8ec;
P_0c08c8ec: /* original 81ea, guest PC 0x0c08c8ec */
if(!s->budget--) { s->failed_pc=0x0c08c8ecu; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c08c8ee;
P_0c08c8ee: /* original e048, guest PC 0x0c08c8ee */
if(!s->budget--) { s->failed_pc=0x0c08c8eeu; return 0; }
r[0]=0x00000048u;
goto P_0c08c8f0;
P_0c08c8f0: /* original 03ec, guest PC 0x0c08c8f0 */
if(!s->budget--) { s->failed_pc=0x0c08c8f0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08c8f2;
P_0c08c8f2: /* original 7301, guest PC 0x0c08c8f2 */
if(!s->budget--) { s->failed_pc=0x0c08c8f2u; return 0; }
r[3]+=0x00000001u;
goto P_0c08c8f4;
P_0c08c8f4: /* original 0e34, guest PC 0x0c08c8f4 */
if(!s->budget--) { s->failed_pc=0x0c08c8f4u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08c8f6;
P_0c08c8f6: /* original 7f04, guest PC 0x0c08c8f6 */
if(!s->budget--) { s->failed_pc=0x0c08c8f6u; return 0; }
r[15]+=0x00000004u;
goto P_0c08c8f8;
P_0c08c8f8: /* original 4f26, guest PC 0x0c08c8f8 */
if(!s->budget--) { s->failed_pc=0x0c08c8f8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08c8fa;
P_0c08c8fa: /* original 6cf6, guest PC 0x0c08c8fa */
if(!s->budget--) { s->failed_pc=0x0c08c8fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08c8fc;
P_0c08c8fc: /* original 6df6, guest PC 0x0c08c8fc */
if(!s->budget--) { s->failed_pc=0x0c08c8fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08c8fe;
P_0c08c8fe: /* original 000b, guest PC 0x0c08c8fe */
if(!s->budget--) { s->failed_pc=0x0c08c8feu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08c900: /* original 6ef6, guest PC 0x0c08c900 */
if(!s->budget--) { s->failed_pc=0x0c08c900u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08c902;
P_0c08c902: /* original 2fe6, guest PC 0x0c08c902 */
if(!s->budget--) { s->failed_pc=0x0c08c902u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08c904;
P_0c08c904: /* original e048, guest PC 0x0c08c904 */
if(!s->budget--) { s->failed_pc=0x0c08c904u; return 0; }
r[0]=0x00000048u;
goto P_0c08c906;
P_0c08c906: /* original 2fd6, guest PC 0x0c08c906 */
if(!s->budget--) { s->failed_pc=0x0c08c906u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08c908;
P_0c08c908: /* original 6d43, guest PC 0x0c08c908 */
if(!s->budget--) { s->failed_pc=0x0c08c908u; return 0; }
r[13]=r[4];
goto P_0c08c90a;
P_0c08c90a: /* original 2fc6, guest PC 0x0c08c90a */
if(!s->budget--) { s->failed_pc=0x0c08c90au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08c90c;
P_0c08c90c: /* original 00dc, guest PC 0x0c08c90c */
if(!s->budget--) { s->failed_pc=0x0c08c90cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08c90e;
P_0c08c90e: /* original 4f22, guest PC 0x0c08c90e */
if(!s->budget--) { s->failed_pc=0x0c08c90eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08c910;
P_0c08c910: /* original 8801, guest PC 0x0c08c910 */
if(!s->budget--) { s->failed_pc=0x0c08c910u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08c912;
P_0c08c912: /* original 8d2c, guest PC 0x0c08c912 */
if(!s->budget--) { s->failed_pc=0x0c08c912u; return 0; }
cond=r[17]&1u;
r[14]=r[5];
if(cond) { goto P_0c08c96e; }
goto P_0c08c916;
P_0c08c914: /* original 6e53, guest PC 0x0c08c914 */
if(!s->budget--) { s->failed_pc=0x0c08c914u; return 0; }
r[14]=r[5];
goto P_0c08c916;
P_0c08c916: /* original 60e2, guest PC 0x0c08c916 */
if(!s->budget--) { s->failed_pc=0x0c08c916u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c08c918;
P_0c08c918: /* original cb01, guest PC 0x0c08c918 */
if(!s->budget--) { s->failed_pc=0x0c08c918u; return 0; }
r[0]|=1u;
goto P_0c08c91a;
P_0c08c91a: /* original 2e02, guest PC 0x0c08c91a */
if(!s->budget--) { s->failed_pc=0x0c08c91au; return 0; }
write(ram,r[14],r[0],4);
goto P_0c08c91c;
P_0c08c91c: /* original 84e8, guest PC 0x0c08c91c */
if(!s->budget--) { s->failed_pc=0x0c08c91cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08c91e;
P_0c08c91e: /* original d11a, guest PC 0x0c08c91e */
if(!s->budget--) { s->failed_pc=0x0c08c91eu; return 0; }
r[1]=read(ram,0x0c08c988u,4);
goto P_0c08c920;
P_0c08c920: /* original 600c, guest PC 0x0c08c920 */
if(!s->budget--) { s->failed_pc=0x0c08c920u; return 0; }
r[0]=r[0]&255u;
goto P_0c08c922;
P_0c08c922: /* original d317, guest PC 0x0c08c922 */
if(!s->budget--) { s->failed_pc=0x0c08c922u; return 0; }
r[3]=read(ram,0x0c08c980u,4);
goto P_0c08c924;
P_0c08c924: /* original 0c1c, guest PC 0x0c08c924 */
if(!s->budget--) { s->failed_pc=0x0c08c924u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c08c926;
P_0c08c926: /* original 430b, guest PC 0x0c08c926 */
if(!s->budget--) { s->failed_pc=0x0c08c926u; return 0; }
target=r[3];
r[16]=code_base|0x0c08c92au;
r[12]=r[12]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08c92au) { target=s->pc; goto dispatch; }
goto P_0c08c92a;
P_0c08c928: /* original 6ccc, guest PC 0x0c08c928 */
if(!s->budget--) { s->failed_pc=0x0c08c928u; return 0; }
r[12]=r[12]&255u;
goto P_0c08c92a;
P_0c08c92a: /* original d216, guest PC 0x0c08c92a */
if(!s->budget--) { s->failed_pc=0x0c08c92au; return 0; }
r[2]=read(ram,0x0c08c984u,4);
goto P_0c08c92c;
P_0c08c92c: /* original 6103, guest PC 0x0c08c92c */
if(!s->budget--) { s->failed_pc=0x0c08c92cu; return 0; }
r[1]=r[0];
goto P_0c08c92e;
P_0c08c92e: /* original 420b, guest PC 0x0c08c92e */
if(!s->budget--) { s->failed_pc=0x0c08c92eu; return 0; }
target=r[2];
r[16]=code_base|0x0c08c932u;
r[0]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08c932u) { target=s->pc; goto dispatch; }
goto P_0c08c932;
P_0c08c930: /* original 60c3, guest PC 0x0c08c930 */
if(!s->budget--) { s->failed_pc=0x0c08c930u; return 0; }
r[0]=r[12];
goto P_0c08c932;
P_0c08c932: /* original 6403, guest PC 0x0c08c932 */
if(!s->budget--) { s->failed_pc=0x0c08c932u; return 0; }
r[4]=r[0];
goto P_0c08c934;
P_0c08c934: /* original 84e8, guest PC 0x0c08c934 */
if(!s->budget--) { s->failed_pc=0x0c08c934u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08c936;
P_0c08c936: /* original d115, guest PC 0x0c08c936 */
if(!s->budget--) { s->failed_pc=0x0c08c936u; return 0; }
r[1]=read(ram,0x0c08c98cu,4);
goto P_0c08c938;
P_0c08c938: /* original 4400, guest PC 0x0c08c938 */
if(!s->budget--) { s->failed_pc=0x0c08c938u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08c93a;
P_0c08c93a: /* original 600c, guest PC 0x0c08c93a */
if(!s->budget--) { s->failed_pc=0x0c08c93au; return 0; }
r[0]=r[0]&255u;
goto P_0c08c93c;
P_0c08c93c: /* original 4008, guest PC 0x0c08c93c */
if(!s->budget--) { s->failed_pc=0x0c08c93cu; return 0; }
r[0]<<=2;
goto P_0c08c93e;
P_0c08c93e: /* original 001e, guest PC 0x0c08c93e */
if(!s->budget--) { s->failed_pc=0x0c08c93eu; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c08c940;
P_0c08c940: /* original e500, guest PC 0x0c08c940 */
if(!s->budget--) { s->failed_pc=0x0c08c940u; return 0; }
r[5]=0x00000000u;
goto P_0c08c942;
P_0c08c942: /* original 044d, guest PC 0x0c08c942 */
if(!s->budget--) { s->failed_pc=0x0c08c942u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08c944;
P_0c08c944: /* original e028, guest PC 0x0c08c944 */
if(!s->budget--) { s->failed_pc=0x0c08c944u; return 0; }
r[0]=0x00000028u;
goto P_0c08c946;
P_0c08c946: /* original 644d, guest PC 0x0c08c946 */
if(!s->budget--) { s->failed_pc=0x0c08c946u; return 0; }
r[4]=r[4]&65535u;
goto P_0c08c948;
P_0c08c948: /* original 0d45, guest PC 0x0c08c948 */
if(!s->budget--) { s->failed_pc=0x0c08c948u; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c08c94a;
P_0c08c94a: /* original e040, guest PC 0x0c08c94a */
if(!s->budget--) { s->failed_pc=0x0c08c94au; return 0; }
r[0]=0x00000040u;
goto P_0c08c94c;
P_0c08c94c: /* original 1e4d, guest PC 0x0c08c94c */
if(!s->budget--) { s->failed_pc=0x0c08c94cu; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c08c94e;
P_0c08c94e: /* original 0e56, guest PC 0x0c08c94e */
if(!s->budget--) { s->failed_pc=0x0c08c94eu; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c08c950;
P_0c08c950: /* original b402, guest PC 0x0c08c950 */
if(!s->budget--) { s->failed_pc=0x0c08c950u; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08c954u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08c954u) { target=s->pc; goto dispatch; }
goto P_0c08c954;
P_0c08c952: /* original 64e3, guest PC 0x0c08c952 */
if(!s->budget--) { s->failed_pc=0x0c08c952u; return 0; }
r[4]=r[14];
goto P_0c08c954;
P_0c08c954: /* original e200, guest PC 0x0c08c954 */
if(!s->budget--) { s->failed_pc=0x0c08c954u; return 0; }
r[2]=0x00000000u;
goto P_0c08c956;
P_0c08c956: /* original 55ee, guest PC 0x0c08c956 */
if(!s->budget--) { s->failed_pc=0x0c08c956u; return 0; }
r[5]=read(ram,r[14]+56,4);
goto P_0c08c958;
P_0c08c958: /* original e02c, guest PC 0x0c08c958 */
if(!s->budget--) { s->failed_pc=0x0c08c958u; return 0; }
r[0]=0x0000002cu;
goto P_0c08c95a;
P_0c08c95a: /* original 54ef, guest PC 0x0c08c95a */
if(!s->budget--) { s->failed_pc=0x0c08c95au; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c08c95c;
P_0c08c95c: /* original 0d24, guest PC 0x0c08c95c */
if(!s->budget--) { s->failed_pc=0x0c08c95cu; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c08c95e;
P_0c08c95e: /* original e02d, guest PC 0x0c08c95e */
if(!s->budget--) { s->failed_pc=0x0c08c95eu; return 0; }
r[0]=0x0000002du;
goto P_0c08c960;
P_0c08c960: /* original 0d54, guest PC 0x0c08c960 */
if(!s->budget--) { s->failed_pc=0x0c08c960u; return 0; }
write(ram,r[13]+r[0],r[5],1);
goto P_0c08c962;
P_0c08c962: /* original 6043, guest PC 0x0c08c962 */
if(!s->budget--) { s->failed_pc=0x0c08c962u; return 0; }
r[0]=r[4];
goto P_0c08c964;
P_0c08c964: /* original 81da, guest PC 0x0c08c964 */
if(!s->budget--) { s->failed_pc=0x0c08c964u; return 0; }
write(ram,r[13]+20,r[0],2);
goto P_0c08c966;
P_0c08c966: /* original e048, guest PC 0x0c08c966 */
if(!s->budget--) { s->failed_pc=0x0c08c966u; return 0; }
r[0]=0x00000048u;
goto P_0c08c968;
P_0c08c968: /* original 03dc, guest PC 0x0c08c968 */
if(!s->budget--) { s->failed_pc=0x0c08c968u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08c96a;
P_0c08c96a: /* original 7301, guest PC 0x0c08c96a */
if(!s->budget--) { s->failed_pc=0x0c08c96au; return 0; }
r[3]+=0x00000001u;
goto P_0c08c96c;
P_0c08c96c: /* original 0d34, guest PC 0x0c08c96c */
if(!s->budget--) { s->failed_pc=0x0c08c96cu; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c08c96e;
P_0c08c96e: /* original 4f26, guest PC 0x0c08c96e */
if(!s->budget--) { s->failed_pc=0x0c08c96eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08c970;
P_0c08c970: /* original 6cf6, guest PC 0x0c08c970 */
if(!s->budget--) { s->failed_pc=0x0c08c970u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08c972;
P_0c08c972: /* original 6df6, guest PC 0x0c08c972 */
if(!s->budget--) { s->failed_pc=0x0c08c972u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08c974;
P_0c08c974: /* original 000b, guest PC 0x0c08c974 */
if(!s->budget--) { s->failed_pc=0x0c08c974u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08c976: /* original 6ef6, guest PC 0x0c08c976 */
if(!s->budget--) { s->failed_pc=0x0c08c976u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08c978u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08c978u; return 0; } return 1;
P_0c08c990: /* original 2fe6, guest PC 0x0c08c990 */
if(!s->budget--) { s->failed_pc=0x0c08c990u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08c992;
P_0c08c992: /* original 6e53, guest PC 0x0c08c992 */
if(!s->budget--) { s->failed_pc=0x0c08c992u; return 0; }
r[14]=r[5];
goto P_0c08c994;
P_0c08c994: /* original 2fd6, guest PC 0x0c08c994 */
if(!s->budget--) { s->failed_pc=0x0c08c994u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08c996;
P_0c08c996: /* original e048, guest PC 0x0c08c996 */
if(!s->budget--) { s->failed_pc=0x0c08c996u; return 0; }
r[0]=0x00000048u;
goto P_0c08c998;
P_0c08c998: /* original 6d43, guest PC 0x0c08c998 */
if(!s->budget--) { s->failed_pc=0x0c08c998u; return 0; }
r[13]=r[4];
goto P_0c08c99a;
P_0c08c99a: /* original 2fc6, guest PC 0x0c08c99a */
if(!s->budget--) { s->failed_pc=0x0c08c99au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08c99c;
P_0c08c99c: /* original 04ee, guest PC 0x0c08c99c */
if(!s->budget--) { s->failed_pc=0x0c08c99cu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c08c99e;
P_0c08c99e: /* original e061, guest PC 0x0c08c99e */
if(!s->budget--) { s->failed_pc=0x0c08c99eu; return 0; }
r[0]=0x00000061u;
goto P_0c08c9a0;
P_0c08c9a0: /* original 4f22, guest PC 0x0c08c9a0 */
if(!s->budget--) { s->failed_pc=0x0c08c9a0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08c9a2;
P_0c08c9a2: /* original 044c, guest PC 0x0c08c9a2 */
if(!s->budget--) { s->failed_pc=0x0c08c9a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c08c9a4;
P_0c08c9a4: /* original 6043, guest PC 0x0c08c9a4 */
if(!s->budget--) { s->failed_pc=0x0c08c9a4u; return 0; }
r[0]=r[4];
goto P_0c08c9a6;
P_0c08c9a6: /* original 80e8, guest PC 0x0c08c9a6 */
if(!s->budget--) { s->failed_pc=0x0c08c9a6u; return 0; }
write(ram,r[14]+8,r[0],1);
goto P_0c08c9a8;
P_0c08c9a8: /* original e048, guest PC 0x0c08c9a8 */
if(!s->budget--) { s->failed_pc=0x0c08c9a8u; return 0; }
r[0]=0x00000048u;
goto P_0c08c9aa;
P_0c08c9aa: /* original 00dc, guest PC 0x0c08c9aa */
if(!s->budget--) { s->failed_pc=0x0c08c9aau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08c9ac;
P_0c08c9ac: /* original 8801, guest PC 0x0c08c9ac */
if(!s->budget--) { s->failed_pc=0x0c08c9acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08c9ae;
P_0c08c9ae: /* original 8b01, guest PC 0x0c08c9ae */
if(!s->budget--) { s->failed_pc=0x0c08c9aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08c9b4; }
goto P_0c08c9b0;
P_0c08c9b0: /* original a08b, guest PC 0x0c08c9b0 */
if(!s->budget--) { s->failed_pc=0x0c08c9b0u; return 0; }
goto P_0c08caca;
P_0c08c9b2: /* original 0009, guest PC 0x0c08c9b2 */
if(!s->budget--) { s->failed_pc=0x0c08c9b2u; return 0; }
goto P_0c08c9b4;
P_0c08c9b4: /* original 60e2, guest PC 0x0c08c9b4 */
if(!s->budget--) { s->failed_pc=0x0c08c9b4u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c08c9b6;
P_0c08c9b6: /* original cb01, guest PC 0x0c08c9b6 */
if(!s->budget--) { s->failed_pc=0x0c08c9b6u; return 0; }
r[0]|=1u;
goto P_0c08c9b8;
P_0c08c9b8: /* original 2e02, guest PC 0x0c08c9b8 */
if(!s->budget--) { s->failed_pc=0x0c08c9b8u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c08c9ba;
P_0c08c9ba: /* original e04c, guest PC 0x0c08c9ba */
if(!s->budget--) { s->failed_pc=0x0c08c9bau; return 0; }
r[0]=0x0000004cu;
goto P_0c08c9bc;
P_0c08c9bc: /* original 04ee, guest PC 0x0c08c9bc */
if(!s->budget--) { s->failed_pc=0x0c08c9bcu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c08c9be;
P_0c08c9be: /* original e03c, guest PC 0x0c08c9be */
if(!s->budget--) { s->failed_pc=0x0c08c9beu; return 0; }
r[0]=0x0000003cu;
goto P_0c08c9c0;
P_0c08c9c0: /* original 9335, guest PC 0x0c08c9c0 */
if(!s->budget--) { s->failed_pc=0x0c08c9c0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ca2eu,2);
goto P_0c08c9c2;
P_0c08c9c2: /* original 044d, guest PC 0x0c08c9c2 */
if(!s->budget--) { s->failed_pc=0x0c08c9c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08c9c4;
P_0c08c9c4: /* original 644d, guest PC 0x0c08c9c4 */
if(!s->budget--) { s->failed_pc=0x0c08c9c4u; return 0; }
r[4]=r[4]&65535u;
goto P_0c08c9c6;
P_0c08c9c6: /* original 3430, guest PC 0x0c08c9c6 */
if(!s->budget--) { s->failed_pc=0x0c08c9c6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c08c9c8;
P_0c08c9c8: /* original 891e, guest PC 0x0c08c9c8 */
if(!s->budget--) { s->failed_pc=0x0c08c9c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ca08; }
goto P_0c08c9ca;
P_0c08c9ca: /* original 9231, guest PC 0x0c08c9ca */
if(!s->budget--) { s->failed_pc=0x0c08c9cau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ca30u,2);
goto P_0c08c9cc;
P_0c08c9cc: /* original 3420, guest PC 0x0c08c9cc */
if(!s->budget--) { s->failed_pc=0x0c08c9ccu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c08c9ce;
P_0c08c9ce: /* original 891b, guest PC 0x0c08c9ce */
if(!s->budget--) { s->failed_pc=0x0c08c9ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ca08; }
goto P_0c08c9d0;
P_0c08c9d0: /* original 932f, guest PC 0x0c08c9d0 */
if(!s->budget--) { s->failed_pc=0x0c08c9d0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ca32u,2);
goto P_0c08c9d2;
P_0c08c9d2: /* original 3430, guest PC 0x0c08c9d2 */
if(!s->budget--) { s->failed_pc=0x0c08c9d2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c08c9d4;
P_0c08c9d4: /* original 8918, guest PC 0x0c08c9d4 */
if(!s->budget--) { s->failed_pc=0x0c08c9d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ca08; }
goto P_0c08c9d6;
P_0c08c9d6: /* original 922d, guest PC 0x0c08c9d6 */
if(!s->budget--) { s->failed_pc=0x0c08c9d6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ca34u,2);
goto P_0c08c9d8;
P_0c08c9d8: /* original 3420, guest PC 0x0c08c9d8 */
if(!s->budget--) { s->failed_pc=0x0c08c9d8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c08c9da;
P_0c08c9da: /* original 8915, guest PC 0x0c08c9da */
if(!s->budget--) { s->failed_pc=0x0c08c9dau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ca08; }
goto P_0c08c9dc;
P_0c08c9dc: /* original 932b, guest PC 0x0c08c9dc */
if(!s->budget--) { s->failed_pc=0x0c08c9dcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ca36u,2);
goto P_0c08c9de;
P_0c08c9de: /* original 3430, guest PC 0x0c08c9de */
if(!s->budget--) { s->failed_pc=0x0c08c9deu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c08c9e0;
P_0c08c9e0: /* original 8912, guest PC 0x0c08c9e0 */
if(!s->budget--) { s->failed_pc=0x0c08c9e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ca08; }
goto P_0c08c9e2;
P_0c08c9e2: /* original 9229, guest PC 0x0c08c9e2 */
if(!s->budget--) { s->failed_pc=0x0c08c9e2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ca38u,2);
goto P_0c08c9e4;
P_0c08c9e4: /* original 3420, guest PC 0x0c08c9e4 */
if(!s->budget--) { s->failed_pc=0x0c08c9e4u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c08c9e6;
P_0c08c9e6: /* original 890f, guest PC 0x0c08c9e6 */
if(!s->budget--) { s->failed_pc=0x0c08c9e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ca08; }
goto P_0c08c9e8;
P_0c08c9e8: /* original 9327, guest PC 0x0c08c9e8 */
if(!s->budget--) { s->failed_pc=0x0c08c9e8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ca3au,2);
goto P_0c08c9ea;
P_0c08c9ea: /* original 3430, guest PC 0x0c08c9ea */
if(!s->budget--) { s->failed_pc=0x0c08c9eau; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c08c9ec;
P_0c08c9ec: /* original 890c, guest PC 0x0c08c9ec */
if(!s->budget--) { s->failed_pc=0x0c08c9ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ca08; }
goto P_0c08c9ee;
P_0c08c9ee: /* original 9225, guest PC 0x0c08c9ee */
if(!s->budget--) { s->failed_pc=0x0c08c9eeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ca3cu,2);
goto P_0c08c9f0;
P_0c08c9f0: /* original 3420, guest PC 0x0c08c9f0 */
if(!s->budget--) { s->failed_pc=0x0c08c9f0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c08c9f2;
P_0c08c9f2: /* original 8909, guest PC 0x0c08c9f2 */
if(!s->budget--) { s->failed_pc=0x0c08c9f2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ca08; }
goto P_0c08c9f4;
P_0c08c9f4: /* original 9323, guest PC 0x0c08c9f4 */
if(!s->budget--) { s->failed_pc=0x0c08c9f4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ca3eu,2);
goto P_0c08c9f6;
P_0c08c9f6: /* original 3430, guest PC 0x0c08c9f6 */
if(!s->budget--) { s->failed_pc=0x0c08c9f6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c08c9f8;
P_0c08c9f8: /* original 8906, guest PC 0x0c08c9f8 */
if(!s->budget--) { s->failed_pc=0x0c08c9f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ca08; }
goto P_0c08c9fa;
P_0c08c9fa: /* original 9221, guest PC 0x0c08c9fa */
if(!s->budget--) { s->failed_pc=0x0c08c9fau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ca40u,2);
goto P_0c08c9fc;
P_0c08c9fc: /* original 3420, guest PC 0x0c08c9fc */
if(!s->budget--) { s->failed_pc=0x0c08c9fcu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c08c9fe;
P_0c08c9fe: /* original 8903, guest PC 0x0c08c9fe */
if(!s->budget--) { s->failed_pc=0x0c08c9feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ca08; }
goto P_0c08ca00;
P_0c08ca00: /* original 64e2, guest PC 0x0c08ca00 */
if(!s->budget--) { s->failed_pc=0x0c08ca00u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c08ca02;
P_0c08ca02: /* original e320, guest PC 0x0c08ca02 */
if(!s->budget--) { s->failed_pc=0x0c08ca02u; return 0; }
r[3]=0x00000020u;
goto P_0c08ca04;
P_0c08ca04: /* original 2438, guest PC 0x0c08ca04 */
if(!s->budget--) { s->failed_pc=0x0c08ca04u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c08ca06;
P_0c08ca06: /* original 8925, guest PC 0x0c08ca06 */
if(!s->budget--) { s->failed_pc=0x0c08ca06u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ca54; }
goto P_0c08ca08;
P_0c08ca08: /* original 84e8, guest PC 0x0c08ca08 */
if(!s->budget--) { s->failed_pc=0x0c08ca08u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08ca0a;
P_0c08ca0a: /* original d10e, guest PC 0x0c08ca0a */
if(!s->budget--) { s->failed_pc=0x0c08ca0au; return 0; }
r[1]=read(ram,0x0c08ca44u,4);
goto P_0c08ca0c;
P_0c08ca0c: /* original 600c, guest PC 0x0c08ca0c */
if(!s->budget--) { s->failed_pc=0x0c08ca0cu; return 0; }
r[0]=r[0]&255u;
goto P_0c08ca0e;
P_0c08ca0e: /* original d30e, guest PC 0x0c08ca0e */
if(!s->budget--) { s->failed_pc=0x0c08ca0eu; return 0; }
r[3]=read(ram,0x0c08ca48u,4);
goto P_0c08ca10;
P_0c08ca10: /* original 0c1c, guest PC 0x0c08ca10 */
if(!s->budget--) { s->failed_pc=0x0c08ca10u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c08ca12;
P_0c08ca12: /* original 430b, guest PC 0x0c08ca12 */
if(!s->budget--) { s->failed_pc=0x0c08ca12u; return 0; }
target=r[3];
r[16]=code_base|0x0c08ca16u;
r[12]=r[12]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ca16u) { target=s->pc; goto dispatch; }
goto P_0c08ca16;
P_0c08ca14: /* original 6ccc, guest PC 0x0c08ca14 */
if(!s->budget--) { s->failed_pc=0x0c08ca14u; return 0; }
r[12]=r[12]&255u;
goto P_0c08ca16;
P_0c08ca16: /* original d20d, guest PC 0x0c08ca16 */
if(!s->budget--) { s->failed_pc=0x0c08ca16u; return 0; }
r[2]=read(ram,0x0c08ca4cu,4);
goto P_0c08ca18;
P_0c08ca18: /* original 6103, guest PC 0x0c08ca18 */
if(!s->budget--) { s->failed_pc=0x0c08ca18u; return 0; }
r[1]=r[0];
goto P_0c08ca1a;
P_0c08ca1a: /* original 420b, guest PC 0x0c08ca1a */
if(!s->budget--) { s->failed_pc=0x0c08ca1au; return 0; }
target=r[2];
r[16]=code_base|0x0c08ca1eu;
r[0]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ca1eu) { target=s->pc; goto dispatch; }
goto P_0c08ca1e;
P_0c08ca1c: /* original 60c3, guest PC 0x0c08ca1c */
if(!s->budget--) { s->failed_pc=0x0c08ca1cu; return 0; }
r[0]=r[12];
goto P_0c08ca1e;
P_0c08ca1e: /* original 6c03, guest PC 0x0c08ca1e */
if(!s->budget--) { s->failed_pc=0x0c08ca1eu; return 0; }
r[12]=r[0];
goto P_0c08ca20;
P_0c08ca20: /* original 84e8, guest PC 0x0c08ca20 */
if(!s->budget--) { s->failed_pc=0x0c08ca20u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08ca22;
P_0c08ca22: /* original d10b, guest PC 0x0c08ca22 */
if(!s->budget--) { s->failed_pc=0x0c08ca22u; return 0; }
r[1]=read(ram,0x0c08ca50u,4);
goto P_0c08ca24;
P_0c08ca24: /* original 64c3, guest PC 0x0c08ca24 */
if(!s->budget--) { s->failed_pc=0x0c08ca24u; return 0; }
r[4]=r[12];
goto P_0c08ca26;
P_0c08ca26: /* original 600c, guest PC 0x0c08ca26 */
if(!s->budget--) { s->failed_pc=0x0c08ca26u; return 0; }
r[0]=r[0]&255u;
goto P_0c08ca28;
P_0c08ca28: /* original 4008, guest PC 0x0c08ca28 */
if(!s->budget--) { s->failed_pc=0x0c08ca28u; return 0; }
r[0]<<=2;
goto P_0c08ca2a;
P_0c08ca2a: /* original a036, guest PC 0x0c08ca2a */
if(!s->budget--) { s->failed_pc=0x0c08ca2au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08ca9a;
P_0c08ca2c: /* original 4400, guest PC 0x0c08ca2c */
if(!s->budget--) { s->failed_pc=0x0c08ca2cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
if(!vf3_matrix_family(0x0c08ca2eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08ca2eu; return 0; } return 1;
P_0c08ca54: /* original 84e8, guest PC 0x0c08ca54 */
if(!s->budget--) { s->failed_pc=0x0c08ca54u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08ca56;
P_0c08ca56: /* original e304, guest PC 0x0c08ca56 */
if(!s->budget--) { s->failed_pc=0x0c08ca56u; return 0; }
r[3]=0x00000004u;
goto P_0c08ca58;
P_0c08ca58: /* original d246, guest PC 0x0c08ca58 */
if(!s->budget--) { s->failed_pc=0x0c08ca58u; return 0; }
r[2]=read(ram,0x0c08cb74u,4);
goto P_0c08ca5a;
P_0c08ca5a: /* original d147, guest PC 0x0c08ca5a */
if(!s->budget--) { s->failed_pc=0x0c08ca5au; return 0; }
r[1]=read(ram,0x0c08cb78u,4);
goto P_0c08ca5c;
P_0c08ca5c: /* original 600c, guest PC 0x0c08ca5c */
if(!s->budget--) { s->failed_pc=0x0c08ca5cu; return 0; }
r[0]=r[0]&255u;
goto P_0c08ca5e;
P_0c08ca5e: /* original 6420, guest PC 0x0c08ca5e */
if(!s->budget--) { s->failed_pc=0x0c08ca5eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[4]=tmp;
goto P_0c08ca60;
P_0c08ca60: /* original 0c1c, guest PC 0x0c08ca60 */
if(!s->budget--) { s->failed_pc=0x0c08ca60u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c08ca62;
P_0c08ca62: /* original 3432, guest PC 0x0c08ca62 */
if(!s->budget--) { s->failed_pc=0x0c08ca62u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[3])!=0);
goto P_0c08ca64;
P_0c08ca64: /* original 8f0b, guest PC 0x0c08ca64 */
if(!s->budget--) { s->failed_pc=0x0c08ca64u; return 0; }
cond=r[17]&1u;
r[12]=r[12]&255u;
if(!cond) { goto P_0c08ca7e; }
goto P_0c08ca68;
P_0c08ca66: /* original 6ccc, guest PC 0x0c08ca66 */
if(!s->budget--) { s->failed_pc=0x0c08ca66u; return 0; }
r[12]=r[12]&255u;
goto P_0c08ca68;
P_0c08ca68: /* original 84e8, guest PC 0x0c08ca68 */
if(!s->budget--) { s->failed_pc=0x0c08ca68u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08ca6a;
P_0c08ca6a: /* original e302, guest PC 0x0c08ca6a */
if(!s->budget--) { s->failed_pc=0x0c08ca6au; return 0; }
r[3]=0x00000002u;
goto P_0c08ca6c;
P_0c08ca6c: /* original d243, guest PC 0x0c08ca6c */
if(!s->budget--) { s->failed_pc=0x0c08ca6cu; return 0; }
r[2]=read(ram,0x0c08cb7cu,4);
goto P_0c08ca6e;
P_0c08ca6e: /* original 600c, guest PC 0x0c08ca6e */
if(!s->budget--) { s->failed_pc=0x0c08ca6eu; return 0; }
r[0]=r[0]&255u;
goto P_0c08ca70;
P_0c08ca70: /* original 0c2c, guest PC 0x0c08ca70 */
if(!s->budget--) { s->failed_pc=0x0c08ca70u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c08ca72;
P_0c08ca72: /* original e04f, guest PC 0x0c08ca72 */
if(!s->budget--) { s->failed_pc=0x0c08ca72u; return 0; }
r[0]=0x0000004fu;
goto P_0c08ca74;
P_0c08ca74: /* original 01dc, guest PC 0x0c08ca74 */
if(!s->budget--) { s->failed_pc=0x0c08ca74u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08ca76;
P_0c08ca76: /* original 3133, guest PC 0x0c08ca76 */
if(!s->budget--) { s->failed_pc=0x0c08ca76u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c08ca78;
P_0c08ca78: /* original 8f01, guest PC 0x0c08ca78 */
if(!s->budget--) { s->failed_pc=0x0c08ca78u; return 0; }
cond=r[17]&1u;
r[12]=r[12]&255u;
if(!cond) { goto P_0c08ca7e; }
goto P_0c08ca7c;
P_0c08ca7a: /* original 6ccc, guest PC 0x0c08ca7a */
if(!s->budget--) { s->failed_pc=0x0c08ca7au; return 0; }
r[12]=r[12]&255u;
goto P_0c08ca7c;
P_0c08ca7c: /* original 3c38, guest PC 0x0c08ca7c */
if(!s->budget--) { s->failed_pc=0x0c08ca7cu; return 0; }
r[12]-=r[3];
goto P_0c08ca7e;
P_0c08ca7e: /* original d340, guest PC 0x0c08ca7e */
if(!s->budget--) { s->failed_pc=0x0c08ca7eu; return 0; }
r[3]=read(ram,0x0c08cb80u,4);
goto P_0c08ca80;
P_0c08ca80: /* original 430b, guest PC 0x0c08ca80 */
if(!s->budget--) { s->failed_pc=0x0c08ca80u; return 0; }
target=r[3];
r[16]=code_base|0x0c08ca84u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ca84u) { target=s->pc; goto dispatch; }
goto P_0c08ca84;
P_0c08ca82: /* original 0009, guest PC 0x0c08ca82 */
if(!s->budget--) { s->failed_pc=0x0c08ca82u; return 0; }
goto P_0c08ca84;
P_0c08ca84: /* original d23f, guest PC 0x0c08ca84 */
if(!s->budget--) { s->failed_pc=0x0c08ca84u; return 0; }
r[2]=read(ram,0x0c08cb84u,4);
goto P_0c08ca86;
P_0c08ca86: /* original 6103, guest PC 0x0c08ca86 */
if(!s->budget--) { s->failed_pc=0x0c08ca86u; return 0; }
r[1]=r[0];
goto P_0c08ca88;
P_0c08ca88: /* original 420b, guest PC 0x0c08ca88 */
if(!s->budget--) { s->failed_pc=0x0c08ca88u; return 0; }
target=r[2];
r[16]=code_base|0x0c08ca8cu;
r[0]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ca8cu) { target=s->pc; goto dispatch; }
goto P_0c08ca8c;
P_0c08ca8a: /* original 60c3, guest PC 0x0c08ca8a */
if(!s->budget--) { s->failed_pc=0x0c08ca8au; return 0; }
r[0]=r[12];
goto P_0c08ca8c;
P_0c08ca8c: /* original 6c03, guest PC 0x0c08ca8c */
if(!s->budget--) { s->failed_pc=0x0c08ca8cu; return 0; }
r[12]=r[0];
goto P_0c08ca8e;
P_0c08ca8e: /* original 84e8, guest PC 0x0c08ca8e */
if(!s->budget--) { s->failed_pc=0x0c08ca8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08ca90;
P_0c08ca90: /* original 64c3, guest PC 0x0c08ca90 */
if(!s->budget--) { s->failed_pc=0x0c08ca90u; return 0; }
r[4]=r[12];
goto P_0c08ca92;
P_0c08ca92: /* original d13d, guest PC 0x0c08ca92 */
if(!s->budget--) { s->failed_pc=0x0c08ca92u; return 0; }
r[1]=read(ram,0x0c08cb88u,4);
goto P_0c08ca94;
P_0c08ca94: /* original 600c, guest PC 0x0c08ca94 */
if(!s->budget--) { s->failed_pc=0x0c08ca94u; return 0; }
r[0]=r[0]&255u;
goto P_0c08ca96;
P_0c08ca96: /* original 4400, guest PC 0x0c08ca96 */
if(!s->budget--) { s->failed_pc=0x0c08ca96u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08ca98;
P_0c08ca98: /* original 4008, guest PC 0x0c08ca98 */
if(!s->budget--) { s->failed_pc=0x0c08ca98u; return 0; }
r[0]<<=2;
goto P_0c08ca9a;
P_0c08ca9a: /* original 001e, guest PC 0x0c08ca9a */
if(!s->budget--) { s->failed_pc=0x0c08ca9au; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c08ca9c;
P_0c08ca9c: /* original e500, guest PC 0x0c08ca9c */
if(!s->budget--) { s->failed_pc=0x0c08ca9cu; return 0; }
r[5]=0x00000000u;
goto P_0c08ca9e;
P_0c08ca9e: /* original 044d, guest PC 0x0c08ca9e */
if(!s->budget--) { s->failed_pc=0x0c08ca9eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08caa0;
P_0c08caa0: /* original e028, guest PC 0x0c08caa0 */
if(!s->budget--) { s->failed_pc=0x0c08caa0u; return 0; }
r[0]=0x00000028u;
goto P_0c08caa2;
P_0c08caa2: /* original 644d, guest PC 0x0c08caa2 */
if(!s->budget--) { s->failed_pc=0x0c08caa2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c08caa4;
P_0c08caa4: /* original 0d45, guest PC 0x0c08caa4 */
if(!s->budget--) { s->failed_pc=0x0c08caa4u; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c08caa6;
P_0c08caa6: /* original e040, guest PC 0x0c08caa6 */
if(!s->budget--) { s->failed_pc=0x0c08caa6u; return 0; }
r[0]=0x00000040u;
goto P_0c08caa8;
P_0c08caa8: /* original 1e4d, guest PC 0x0c08caa8 */
if(!s->budget--) { s->failed_pc=0x0c08caa8u; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c08caaa;
P_0c08caaa: /* original 0e56, guest PC 0x0c08caaa */
if(!s->budget--) { s->failed_pc=0x0c08caaau; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c08caac;
P_0c08caac: /* original b354, guest PC 0x0c08caac */
if(!s->budget--) { s->failed_pc=0x0c08caacu; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08cab0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cab0u) { target=s->pc; goto dispatch; }
goto P_0c08cab0;
P_0c08caae: /* original 64e3, guest PC 0x0c08caae */
if(!s->budget--) { s->failed_pc=0x0c08caaeu; return 0; }
r[4]=r[14];
goto P_0c08cab0;
P_0c08cab0: /* original e200, guest PC 0x0c08cab0 */
if(!s->budget--) { s->failed_pc=0x0c08cab0u; return 0; }
r[2]=0x00000000u;
goto P_0c08cab2;
P_0c08cab2: /* original 55ee, guest PC 0x0c08cab2 */
if(!s->budget--) { s->failed_pc=0x0c08cab2u; return 0; }
r[5]=read(ram,r[14]+56,4);
goto P_0c08cab4;
P_0c08cab4: /* original e02c, guest PC 0x0c08cab4 */
if(!s->budget--) { s->failed_pc=0x0c08cab4u; return 0; }
r[0]=0x0000002cu;
goto P_0c08cab6;
P_0c08cab6: /* original 54ef, guest PC 0x0c08cab6 */
if(!s->budget--) { s->failed_pc=0x0c08cab6u; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c08cab8;
P_0c08cab8: /* original 0d24, guest PC 0x0c08cab8 */
if(!s->budget--) { s->failed_pc=0x0c08cab8u; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c08caba;
P_0c08caba: /* original e02d, guest PC 0x0c08caba */
if(!s->budget--) { s->failed_pc=0x0c08cabau; return 0; }
r[0]=0x0000002du;
goto P_0c08cabc;
P_0c08cabc: /* original 0d54, guest PC 0x0c08cabc */
if(!s->budget--) { s->failed_pc=0x0c08cabcu; return 0; }
write(ram,r[13]+r[0],r[5],1);
goto P_0c08cabe;
P_0c08cabe: /* original 6043, guest PC 0x0c08cabe */
if(!s->budget--) { s->failed_pc=0x0c08cabeu; return 0; }
r[0]=r[4];
goto P_0c08cac0;
P_0c08cac0: /* original 81da, guest PC 0x0c08cac0 */
if(!s->budget--) { s->failed_pc=0x0c08cac0u; return 0; }
write(ram,r[13]+20,r[0],2);
goto P_0c08cac2;
P_0c08cac2: /* original e048, guest PC 0x0c08cac2 */
if(!s->budget--) { s->failed_pc=0x0c08cac2u; return 0; }
r[0]=0x00000048u;
goto P_0c08cac4;
P_0c08cac4: /* original 03dc, guest PC 0x0c08cac4 */
if(!s->budget--) { s->failed_pc=0x0c08cac4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08cac6;
P_0c08cac6: /* original 7301, guest PC 0x0c08cac6 */
if(!s->budget--) { s->failed_pc=0x0c08cac6u; return 0; }
r[3]+=0x00000001u;
goto P_0c08cac8;
P_0c08cac8: /* original 0d34, guest PC 0x0c08cac8 */
if(!s->budget--) { s->failed_pc=0x0c08cac8u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c08caca;
P_0c08caca: /* original 4f26, guest PC 0x0c08caca */
if(!s->budget--) { s->failed_pc=0x0c08cacau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08cacc;
P_0c08cacc: /* original 6cf6, guest PC 0x0c08cacc */
if(!s->budget--) { s->failed_pc=0x0c08caccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08cace;
P_0c08cace: /* original 6df6, guest PC 0x0c08cace */
if(!s->budget--) { s->failed_pc=0x0c08caceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08cad0;
P_0c08cad0: /* original 000b, guest PC 0x0c08cad0 */
if(!s->budget--) { s->failed_pc=0x0c08cad0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08cad2: /* original 6ef6, guest PC 0x0c08cad2 */
if(!s->budget--) { s->failed_pc=0x0c08cad2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08cad4u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
