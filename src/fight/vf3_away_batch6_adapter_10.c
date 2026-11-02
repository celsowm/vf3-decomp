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
int vf3_away_batch6_adapter_10(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04d800u: goto P_0c04d800;
case 0x0c04d802u: goto P_0c04d802;
case 0x0c04d804u: goto P_0c04d804;
case 0x0c04d806u: goto P_0c04d806;
case 0x0c04d808u: goto P_0c04d808;
case 0x0c04d80au: goto P_0c04d80a;
case 0x0c04d80cu: goto P_0c04d80c;
case 0x0c04d80eu: goto P_0c04d80e;
case 0x0c04d810u: goto P_0c04d810;
case 0x0c04d812u: goto P_0c04d812;
case 0x0c04d814u: goto P_0c04d814;
case 0x0c04d816u: goto P_0c04d816;
case 0x0c04d818u: goto P_0c04d818;
case 0x0c04d81au: goto P_0c04d81a;
case 0x0c04d81cu: goto P_0c04d81c;
case 0x0c04d81eu: goto P_0c04d81e;
case 0x0c04d820u: goto P_0c04d820;
case 0x0c04d822u: goto P_0c04d822;
case 0x0c04d824u: goto P_0c04d824;
case 0x0c04d826u: goto P_0c04d826;
case 0x0c04d828u: goto P_0c04d828;
case 0x0c04d82au: goto P_0c04d82a;
case 0x0c04d82cu: goto P_0c04d82c;
case 0x0c04d82eu: goto P_0c04d82e;
case 0x0c04d830u: goto P_0c04d830;
case 0x0c04d832u: goto P_0c04d832;
case 0x0c04d834u: goto P_0c04d834;
case 0x0c04d836u: goto P_0c04d836;
case 0x0c04d838u: goto P_0c04d838;
case 0x0c04d83au: goto P_0c04d83a;
case 0x0c04d83cu: goto P_0c04d83c;
case 0x0c04d83eu: goto P_0c04d83e;
case 0x0c04d840u: goto P_0c04d840;
case 0x0c04d842u: goto P_0c04d842;
case 0x0c04d844u: goto P_0c04d844;
case 0x0c04d846u: goto P_0c04d846;
case 0x0c04d848u: goto P_0c04d848;
case 0x0c04d84au: goto P_0c04d84a;
case 0x0c04d84cu: goto P_0c04d84c;
case 0x0c04d84eu: goto P_0c04d84e;
case 0x0c04d850u: goto P_0c04d850;
case 0x0c04d852u: goto P_0c04d852;
case 0x0c04d854u: goto P_0c04d854;
case 0x0c04d856u: goto P_0c04d856;
case 0x0c04d858u: goto P_0c04d858;
case 0x0c04d85au: goto P_0c04d85a;
case 0x0c04d85cu: goto P_0c04d85c;
case 0x0c04d85eu: goto P_0c04d85e;
case 0x0c04d860u: goto P_0c04d860;
case 0x0c04d862u: goto P_0c04d862;
case 0x0c04d864u: goto P_0c04d864;
case 0x0c04d866u: goto P_0c04d866;
case 0x0c04d868u: goto P_0c04d868;
case 0x0c04d86au: goto P_0c04d86a;
case 0x0c04d86cu: goto P_0c04d86c;
case 0x0c04d86eu: goto P_0c04d86e;
case 0x0c04d870u: goto P_0c04d870;
case 0x0c04d872u: goto P_0c04d872;
case 0x0c04d874u: goto P_0c04d874;
case 0x0c04d876u: goto P_0c04d876;
case 0x0c04d878u: goto P_0c04d878;
case 0x0c04d87au: goto P_0c04d87a;
case 0x0c04d8acu: goto P_0c04d8ac;
case 0x0c04d8aeu: goto P_0c04d8ae;
case 0x0c04d8b0u: goto P_0c04d8b0;
case 0x0c04d8b2u: goto P_0c04d8b2;
case 0x0c04d8b4u: goto P_0c04d8b4;
case 0x0c04d8b6u: goto P_0c04d8b6;
case 0x0c04d8b8u: goto P_0c04d8b8;
case 0x0c04d8bau: goto P_0c04d8ba;
case 0x0c04d8bcu: goto P_0c04d8bc;
case 0x0c04d8beu: goto P_0c04d8be;
case 0x0c04d8c0u: goto P_0c04d8c0;
case 0x0c04d8c2u: goto P_0c04d8c2;
case 0x0c04d8c4u: goto P_0c04d8c4;
case 0x0c04d8c6u: goto P_0c04d8c6;
case 0x0c04d8c8u: goto P_0c04d8c8;
case 0x0c04d8cau: goto P_0c04d8ca;
case 0x0c04d8ccu: goto P_0c04d8cc;
case 0x0c04d8ceu: goto P_0c04d8ce;
case 0x0c04d8d0u: goto P_0c04d8d0;
case 0x0c04d8d2u: goto P_0c04d8d2;
case 0x0c04d8d4u: goto P_0c04d8d4;
case 0x0c04d8d6u: goto P_0c04d8d6;
case 0x0c04d8d8u: goto P_0c04d8d8;
case 0x0c04d8dau: goto P_0c04d8da;
case 0x0c04d8dcu: goto P_0c04d8dc;
case 0x0c04d8deu: goto P_0c04d8de;
case 0x0c04d8e0u: goto P_0c04d8e0;
case 0x0c04d8e2u: goto P_0c04d8e2;
case 0x0c04d8e4u: goto P_0c04d8e4;
case 0x0c04d8e6u: goto P_0c04d8e6;
case 0x0c04d8e8u: goto P_0c04d8e8;
case 0x0c04d8eau: goto P_0c04d8ea;
case 0x0c04d8ecu: goto P_0c04d8ec;
case 0x0c04d8eeu: goto P_0c04d8ee;
case 0x0c04d8f0u: goto P_0c04d8f0;
case 0x0c04d8f2u: goto P_0c04d8f2;
case 0x0c04d8f4u: goto P_0c04d8f4;
case 0x0c04d8f6u: goto P_0c04d8f6;
case 0x0c04d8f8u: goto P_0c04d8f8;
case 0x0c04d8fau: goto P_0c04d8fa;
case 0x0c04d8fcu: goto P_0c04d8fc;
case 0x0c04d8feu: goto P_0c04d8fe;
case 0x0c04d900u: goto P_0c04d900;
case 0x0c04d902u: goto P_0c04d902;
case 0x0c04d904u: goto P_0c04d904;
case 0x0c04d906u: goto P_0c04d906;
case 0x0c04d908u: goto P_0c04d908;
case 0x0c04d90au: goto P_0c04d90a;
case 0x0c04d90cu: goto P_0c04d90c;
case 0x0c04d90eu: goto P_0c04d90e;
case 0x0c04d910u: goto P_0c04d910;
case 0x0c04d912u: goto P_0c04d912;
case 0x0c04d914u: goto P_0c04d914;
case 0x0c04d916u: goto P_0c04d916;
case 0x0c04d918u: goto P_0c04d918;
case 0x0c04d91au: goto P_0c04d91a;
case 0x0c04d91cu: goto P_0c04d91c;
case 0x0c04d91eu: goto P_0c04d91e;
case 0x0c04d920u: goto P_0c04d920;
case 0x0c04d922u: goto P_0c04d922;
case 0x0c04d924u: goto P_0c04d924;
case 0x0c04d926u: goto P_0c04d926;
case 0x0c04d928u: goto P_0c04d928;
case 0x0c04d92au: goto P_0c04d92a;
case 0x0c04d92cu: goto P_0c04d92c;
case 0x0c04d92eu: goto P_0c04d92e;
case 0x0c04d930u: goto P_0c04d930;
case 0x0c04d932u: goto P_0c04d932;
case 0x0c04d934u: goto P_0c04d934;
case 0x0c04d936u: goto P_0c04d936;
case 0x0c04d938u: goto P_0c04d938;
case 0x0c04d93au: goto P_0c04d93a;
case 0x0c04d93cu: goto P_0c04d93c;
case 0x0c04d93eu: goto P_0c04d93e;
case 0x0c04d940u: goto P_0c04d940;
case 0x0c04d942u: goto P_0c04d942;
case 0x0c04d944u: goto P_0c04d944;
case 0x0c04d946u: goto P_0c04d946;
case 0x0c04d948u: goto P_0c04d948;
case 0x0c04d94au: goto P_0c04d94a;
case 0x0c04d94cu: goto P_0c04d94c;
case 0x0c04d94eu: goto P_0c04d94e;
case 0x0c04d950u: goto P_0c04d950;
case 0x0c04d952u: goto P_0c04d952;
case 0x0c04d954u: goto P_0c04d954;
case 0x0c04d956u: goto P_0c04d956;
case 0x0c04d958u: goto P_0c04d958;
case 0x0c04d95au: goto P_0c04d95a;
case 0x0c04d95cu: goto P_0c04d95c;
case 0x0c04d95eu: goto P_0c04d95e;
case 0x0c04d960u: goto P_0c04d960;
case 0x0c04d962u: goto P_0c04d962;
case 0x0c04d964u: goto P_0c04d964;
case 0x0c04d966u: goto P_0c04d966;
case 0x0c04d968u: goto P_0c04d968;
case 0x0c04d96au: goto P_0c04d96a;
case 0x0c04d96cu: goto P_0c04d96c;
case 0x0c04d96eu: goto P_0c04d96e;
case 0x0c04d970u: goto P_0c04d970;
case 0x0c04d972u: goto P_0c04d972;
case 0x0c04d974u: goto P_0c04d974;
case 0x0c04d976u: goto P_0c04d976;
case 0x0c04d978u: goto P_0c04d978;
case 0x0c04d97au: goto P_0c04d97a;
case 0x0c04d97cu: goto P_0c04d97c;
case 0x0c04d97eu: goto P_0c04d97e;
case 0x0c04d980u: goto P_0c04d980;
case 0x0c04d982u: goto P_0c04d982;
case 0x0c04d984u: goto P_0c04d984;
case 0x0c04d986u: goto P_0c04d986;
case 0x0c04d988u: goto P_0c04d988;
case 0x0c04d98au: goto P_0c04d98a;
case 0x0c04d98cu: goto P_0c04d98c;
case 0x0c04d98eu: goto P_0c04d98e;
case 0x0c04d990u: goto P_0c04d990;
case 0x0c04d992u: goto P_0c04d992;
case 0x0c04d994u: goto P_0c04d994;
case 0x0c04d996u: goto P_0c04d996;
case 0x0c04d998u: goto P_0c04d998;
case 0x0c04d99au: goto P_0c04d99a;
case 0x0c04d99cu: goto P_0c04d99c;
case 0x0c04d99eu: goto P_0c04d99e;
case 0x0c04d9a0u: goto P_0c04d9a0;
case 0x0c04d9a2u: goto P_0c04d9a2;
case 0x0c04d9a4u: goto P_0c04d9a4;
case 0x0c04d9a6u: goto P_0c04d9a6;
case 0x0c04d9a8u: goto P_0c04d9a8;
case 0x0c04d9aau: goto P_0c04d9aa;
case 0x0c04d9acu: goto P_0c04d9ac;
case 0x0c04d9aeu: goto P_0c04d9ae;
case 0x0c04d9b0u: goto P_0c04d9b0;
case 0x0c04d9b2u: goto P_0c04d9b2;
case 0x0c04d9b4u: goto P_0c04d9b4;
case 0x0c04d9b6u: goto P_0c04d9b6;
case 0x0c04d9b8u: goto P_0c04d9b8;
case 0x0c04d9fcu: goto P_0c04d9fc;
case 0x0c04d9feu: goto P_0c04d9fe;
case 0x0c04da00u: goto P_0c04da00;
case 0x0c04da02u: goto P_0c04da02;
case 0x0c04da04u: goto P_0c04da04;
case 0x0c04da06u: goto P_0c04da06;
case 0x0c04da08u: goto P_0c04da08;
case 0x0c04da0au: goto P_0c04da0a;
case 0x0c04da0cu: goto P_0c04da0c;
case 0x0c04da0eu: goto P_0c04da0e;
case 0x0c04da10u: goto P_0c04da10;
case 0x0c04da12u: goto P_0c04da12;
case 0x0c04da14u: goto P_0c04da14;
case 0x0c04da16u: goto P_0c04da16;
case 0x0c04da18u: goto P_0c04da18;
case 0x0c04da1au: goto P_0c04da1a;
case 0x0c04da1cu: goto P_0c04da1c;
case 0x0c04da1eu: goto P_0c04da1e;
case 0x0c04da20u: goto P_0c04da20;
case 0x0c04da22u: goto P_0c04da22;
case 0x0c04da24u: goto P_0c04da24;
case 0x0c04da26u: goto P_0c04da26;
case 0x0c04da28u: goto P_0c04da28;
case 0x0c04da2au: goto P_0c04da2a;
case 0x0c04da2cu: goto P_0c04da2c;
case 0x0c04da2eu: goto P_0c04da2e;
case 0x0c04da30u: goto P_0c04da30;
case 0x0c04da32u: goto P_0c04da32;
case 0x0c04da34u: goto P_0c04da34;
case 0x0c04da36u: goto P_0c04da36;
case 0x0c04da38u: goto P_0c04da38;
case 0x0c04da3au: goto P_0c04da3a;
case 0x0c04da3cu: goto P_0c04da3c;
case 0x0c04da3eu: goto P_0c04da3e;
case 0x0c04da40u: goto P_0c04da40;
case 0x0c04da42u: goto P_0c04da42;
case 0x0c04da44u: goto P_0c04da44;
case 0x0c04da46u: goto P_0c04da46;
case 0x0c04da48u: goto P_0c04da48;
case 0x0c04da4au: goto P_0c04da4a;
case 0x0c04da4cu: goto P_0c04da4c;
case 0x0c04da4eu: goto P_0c04da4e;
case 0x0c04da50u: goto P_0c04da50;
case 0x0c04da52u: goto P_0c04da52;
case 0x0c04da54u: goto P_0c04da54;
case 0x0c04da56u: goto P_0c04da56;
case 0x0c04da58u: goto P_0c04da58;
case 0x0c04da5au: goto P_0c04da5a;
case 0x0c04da5cu: goto P_0c04da5c;
case 0x0c04da5eu: goto P_0c04da5e;
case 0x0c04da60u: goto P_0c04da60;
case 0x0c04da62u: goto P_0c04da62;
case 0x0c04da64u: goto P_0c04da64;
case 0x0c04da66u: goto P_0c04da66;
case 0x0c04da68u: goto P_0c04da68;
case 0x0c04da6au: goto P_0c04da6a;
case 0x0c04da6cu: goto P_0c04da6c;
case 0x0c04da6eu: goto P_0c04da6e;
case 0x0c04da70u: goto P_0c04da70;
case 0x0c04da72u: goto P_0c04da72;
case 0x0c04da74u: goto P_0c04da74;
case 0x0c04da76u: goto P_0c04da76;
case 0x0c04da78u: goto P_0c04da78;
case 0x0c04da7au: goto P_0c04da7a;
case 0x0c04da7cu: goto P_0c04da7c;
case 0x0c04da7eu: goto P_0c04da7e;
case 0x0c04da80u: goto P_0c04da80;
case 0x0c04da82u: goto P_0c04da82;
case 0x0c04da84u: goto P_0c04da84;
case 0x0c04da86u: goto P_0c04da86;
case 0x0c04da88u: goto P_0c04da88;
case 0x0c04da8au: goto P_0c04da8a;
case 0x0c04da8cu: goto P_0c04da8c;
case 0x0c04da8eu: goto P_0c04da8e;
case 0x0c04da90u: goto P_0c04da90;
case 0x0c04da92u: goto P_0c04da92;
case 0x0c04da94u: goto P_0c04da94;
case 0x0c04da96u: goto P_0c04da96;
case 0x0c04da98u: goto P_0c04da98;
case 0x0c04da9au: goto P_0c04da9a;
case 0x0c04da9cu: goto P_0c04da9c;
case 0x0c04da9eu: goto P_0c04da9e;
case 0x0c04daa0u: goto P_0c04daa0;
case 0x0c04daa2u: goto P_0c04daa2;
case 0x0c04daa4u: goto P_0c04daa4;
case 0x0c04daa6u: goto P_0c04daa6;
case 0x0c04daa8u: goto P_0c04daa8;
case 0x0c04daaau: goto P_0c04daaa;
case 0x0c04daacu: goto P_0c04daac;
case 0x0c04daaeu: goto P_0c04daae;
case 0x0c04dab0u: goto P_0c04dab0;
case 0x0c04dab2u: goto P_0c04dab2;
case 0x0c04dab4u: goto P_0c04dab4;
case 0x0c04dab6u: goto P_0c04dab6;
case 0x0c04dab8u: goto P_0c04dab8;
case 0x0c04dabau: goto P_0c04daba;
case 0x0c04dabcu: goto P_0c04dabc;
case 0x0c04dabeu: goto P_0c04dabe;
case 0x0c04dac0u: goto P_0c04dac0;
case 0x0c04dac2u: goto P_0c04dac2;
case 0x0c04dac4u: goto P_0c04dac4;
case 0x0c04dac6u: goto P_0c04dac6;
case 0x0c04dac8u: goto P_0c04dac8;
case 0x0c04dacau: goto P_0c04daca;
case 0x0c04daccu: goto P_0c04dacc;
case 0x0c04daceu: goto P_0c04dace;
case 0x0c04dad0u: goto P_0c04dad0;
case 0x0c04dad2u: goto P_0c04dad2;
case 0x0c04dad4u: goto P_0c04dad4;
case 0x0c04dad6u: goto P_0c04dad6;
case 0x0c04dad8u: goto P_0c04dad8;
case 0x0c04dadau: goto P_0c04dada;
case 0x0c04dadcu: goto P_0c04dadc;
case 0x0c04db28u: goto P_0c04db28;
case 0x0c04db2au: goto P_0c04db2a;
case 0x0c04db2cu: goto P_0c04db2c;
case 0x0c04db2eu: goto P_0c04db2e;
case 0x0c04db30u: goto P_0c04db30;
case 0x0c04db32u: goto P_0c04db32;
case 0x0c04db34u: goto P_0c04db34;
case 0x0c04db36u: goto P_0c04db36;
case 0x0c04db38u: goto P_0c04db38;
case 0x0c04db3au: goto P_0c04db3a;
case 0x0c04db3cu: goto P_0c04db3c;
case 0x0c04db3eu: goto P_0c04db3e;
case 0x0c04db40u: goto P_0c04db40;
case 0x0c04db42u: goto P_0c04db42;
case 0x0c04db44u: goto P_0c04db44;
case 0x0c04db46u: goto P_0c04db46;
case 0x0c04db48u: goto P_0c04db48;
case 0x0c04db4au: goto P_0c04db4a;
case 0x0c04db4cu: goto P_0c04db4c;
case 0x0c04db4eu: goto P_0c04db4e;
case 0x0c04db50u: goto P_0c04db50;
case 0x0c04db52u: goto P_0c04db52;
case 0x0c04db54u: goto P_0c04db54;
case 0x0c04db56u: goto P_0c04db56;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04d800: /* original 2fe6, guest PC 0x0c04d800 */
if(!s->budget--) { s->failed_pc=0x0c04d800u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d802;
P_0c04d802: /* original 2fd6, guest PC 0x0c04d802 */
if(!s->budget--) { s->failed_pc=0x0c04d802u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d804;
P_0c04d804: /* original 6d43, guest PC 0x0c04d804 */
if(!s->budget--) { s->failed_pc=0x0c04d804u; return 0; }
r[13]=r[4];
goto P_0c04d806;
P_0c04d806: /* original 2fc6, guest PC 0x0c04d806 */
if(!s->budget--) { s->failed_pc=0x0c04d806u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d808;
P_0c04d808: /* original 6c53, guest PC 0x0c04d808 */
if(!s->budget--) { s->failed_pc=0x0c04d808u; return 0; }
r[12]=r[5];
goto P_0c04d80a;
P_0c04d80a: /* original 2fb6, guest PC 0x0c04d80a */
if(!s->budget--) { s->failed_pc=0x0c04d80au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d80c;
P_0c04d80c: /* original 6b63, guest PC 0x0c04d80c */
if(!s->budget--) { s->failed_pc=0x0c04d80cu; return 0; }
r[11]=r[6];
goto P_0c04d80e;
P_0c04d80e: /* original 2fa6, guest PC 0x0c04d80e */
if(!s->budget--) { s->failed_pc=0x0c04d80eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d810;
P_0c04d810: /* original ea00, guest PC 0x0c04d810 */
if(!s->budget--) { s->failed_pc=0x0c04d810u; return 0; }
r[10]=0x00000000u;
goto P_0c04d812;
P_0c04d812: /* original 4f22, guest PC 0x0c04d812 */
if(!s->budget--) { s->failed_pc=0x0c04d812u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04d814;
P_0c04d814: /* original 2ba2, guest PC 0x0c04d814 */
if(!s->budget--) { s->failed_pc=0x0c04d814u; return 0; }
write(ram,r[11],r[10],4);
goto P_0c04d816;
P_0c04d816: /* original 4f12, guest PC 0x0c04d816 */
if(!s->budget--) { s->failed_pc=0x0c04d816u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04d818;
P_0c04d818: /* original 7fd4, guest PC 0x0c04d818 */
if(!s->budget--) { s->failed_pc=0x0c04d818u; return 0; }
r[15]+=0xffffffd4u;
goto P_0c04d81a;
P_0c04d81a: /* original 2fb6, guest PC 0x0c04d81a */
if(!s->budget--) { s->failed_pc=0x0c04d81au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d81c;
P_0c04d81c: /* original 2fc6, guest PC 0x0c04d81c */
if(!s->budget--) { s->failed_pc=0x0c04d81cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d81e;
P_0c04d81e: /* original 2fd6, guest PC 0x0c04d81e */
if(!s->budget--) { s->failed_pc=0x0c04d81eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d820;
P_0c04d820: /* original d21e, guest PC 0x0c04d820 */
if(!s->budget--) { s->failed_pc=0x0c04d820u; return 0; }
r[2]=read(ram,0x0c04d89cu,4);
goto P_0c04d822;
P_0c04d822: /* original d31d, guest PC 0x0c04d822 */
if(!s->budget--) { s->failed_pc=0x0c04d822u; return 0; }
r[3]=read(ram,0x0c04d898u,4);
goto P_0c04d824;
P_0c04d824: /* original 420b, guest PC 0x0c04d824 */
if(!s->budget--) { s->failed_pc=0x0c04d824u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d828u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d828u) { target=s->pc; goto dispatch; }
goto P_0c04d828;
P_0c04d826: /* original 2f36, guest PC 0x0c04d826 */
if(!s->budget--) { s->failed_pc=0x0c04d826u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d828;
P_0c04d828: /* original 912a, guest PC 0x0c04d828 */
if(!s->budget--) { s->failed_pc=0x0c04d828u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d880u,2);
goto P_0c04d82a;
P_0c04d82a: /* original d01d, guest PC 0x0c04d82a */
if(!s->budget--) { s->failed_pc=0x0c04d82au; return 0; }
r[0]=read(ram,0x0c04d8a0u,4);
goto P_0c04d82c;
P_0c04d82c: /* original 2d1f, guest PC 0x0c04d82c */
if(!s->budget--) { s->failed_pc=0x0c04d82cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[1]);
goto P_0c04d82e;
P_0c04d82e: /* original 011a, guest PC 0x0c04d82e */
if(!s->budget--) { s->failed_pc=0x0c04d82eu; return 0; }
r[1]=r[19];
goto P_0c04d830;
P_0c04d830: /* original 611f, guest PC 0x0c04d830 */
if(!s->budget--) { s->failed_pc=0x0c04d830u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[1];
goto P_0c04d832;
P_0c04d832: /* original 031c, guest PC 0x0c04d832 */
if(!s->budget--) { s->failed_pc=0x0c04d832u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c04d834;
P_0c04d834: /* original 2338, guest PC 0x0c04d834 */
if(!s->budget--) { s->failed_pc=0x0c04d834u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04d836;
P_0c04d836: /* original 8d16, guest PC 0x0c04d836 */
if(!s->budget--) { s->failed_pc=0x0c04d836u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000010u;
if(cond) { goto P_0c04d866; }
goto P_0c04d83a;
P_0c04d838: /* original 7f10, guest PC 0x0c04d838 */
if(!s->budget--) { s->failed_pc=0x0c04d838u; return 0; }
r[15]+=0x00000010u;
goto P_0c04d83a;
P_0c04d83a: /* original d21a, guest PC 0x0c04d83a */
if(!s->budget--) { s->failed_pc=0x0c04d83au; return 0; }
r[2]=read(ram,0x0c04d8a4u,4);
goto P_0c04d83c;
P_0c04d83c: /* original 420b, guest PC 0x0c04d83c */
if(!s->budget--) { s->failed_pc=0x0c04d83cu; return 0; }
target=r[2];
r[16]=code_base|0x0c04d840u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d840u) { target=s->pc; goto dispatch; }
goto P_0c04d840;
P_0c04d83e: /* original 64d3, guest PC 0x0c04d83e */
if(!s->budget--) { s->failed_pc=0x0c04d83eu; return 0; }
r[4]=r[13];
goto P_0c04d840;
P_0c04d840: /* original 2008, guest PC 0x0c04d840 */
if(!s->budget--) { s->failed_pc=0x0c04d840u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d842;
P_0c04d842: /* original 8b03, guest PC 0x0c04d842 */
if(!s->budget--) { s->failed_pc=0x0c04d842u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d84c; }
goto P_0c04d844;
P_0c04d844: /* original bb43, guest PC 0x0c04d844 */
if(!s->budget--) { s->failed_pc=0x0c04d844u; return 0; }
target=code_base|0x0c04ceceu; r[16]=code_base|0x0c04d848u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d848u) { target=s->pc; goto dispatch; }
goto P_0c04d848;
P_0c04d846: /* original 64d3, guest PC 0x0c04d846 */
if(!s->budget--) { s->failed_pc=0x0c04d846u; return 0; }
r[4]=r[13];
goto P_0c04d848;
P_0c04d848: /* original a00d, guest PC 0x0c04d848 */
if(!s->budget--) { s->failed_pc=0x0c04d848u; return 0; }
goto P_0c04d866;
P_0c04d84a: /* original 0009, guest PC 0x0c04d84a */
if(!s->budget--) { s->failed_pc=0x0c04d84au; return 0; }
goto P_0c04d84c;
P_0c04d84c: /* original d30d, guest PC 0x0c04d84c */
if(!s->budget--) { s->failed_pc=0x0c04d84cu; return 0; }
r[3]=read(ram,0x0c04d884u,4);
goto P_0c04d84e;
P_0c04d84e: /* original 430b, guest PC 0x0c04d84e */
if(!s->budget--) { s->failed_pc=0x0c04d84eu; return 0; }
target=r[3];
r[16]=code_base|0x0c04d852u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d852u) { target=s->pc; goto dispatch; }
goto P_0c04d852;
P_0c04d850: /* original 64d3, guest PC 0x0c04d850 */
if(!s->budget--) { s->failed_pc=0x0c04d850u; return 0; }
r[4]=r[13];
goto P_0c04d852;
P_0c04d852: /* original 2008, guest PC 0x0c04d852 */
if(!s->budget--) { s->failed_pc=0x0c04d852u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d854;
P_0c04d854: /* original 8907, guest PC 0x0c04d854 */
if(!s->budget--) { s->failed_pc=0x0c04d854u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d866; }
goto P_0c04d856;
P_0c04d856: /* original 9213, guest PC 0x0c04d856 */
if(!s->budget--) { s->failed_pc=0x0c04d856u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d880u,2);
goto P_0c04d858;
P_0c04d858: /* original d013, guest PC 0x0c04d858 */
if(!s->budget--) { s->failed_pc=0x0c04d858u; return 0; }
r[0]=read(ram,0x0c04d8a8u,4);
goto P_0c04d85a;
P_0c04d85a: /* original 2d2f, guest PC 0x0c04d85a */
if(!s->budget--) { s->failed_pc=0x0c04d85au; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[2]);
goto P_0c04d85c;
P_0c04d85c: /* original 021a, guest PC 0x0c04d85c */
if(!s->budget--) { s->failed_pc=0x0c04d85cu; return 0; }
r[2]=r[19];
goto P_0c04d85e;
P_0c04d85e: /* original 622f, guest PC 0x0c04d85e */
if(!s->budget--) { s->failed_pc=0x0c04d85eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c04d860;
P_0c04d860: /* original 032c, guest PC 0x0c04d860 */
if(!s->budget--) { s->failed_pc=0x0c04d860u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c04d862;
P_0c04d862: /* original 2338, guest PC 0x0c04d862 */
if(!s->budget--) { s->failed_pc=0x0c04d862u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04d864;
P_0c04d864: /* original 8b02, guest PC 0x0c04d864 */
if(!s->budget--) { s->failed_pc=0x0c04d864u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d86c; }
goto P_0c04d866;
P_0c04d866: /* original 9009, guest PC 0x0c04d866 */
if(!s->budget--) { s->failed_pc=0x0c04d866u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d87cu,2);
goto P_0c04d868;
P_0c04d868: /* original a070, guest PC 0x0c04d868 */
if(!s->budget--) { s->failed_pc=0x0c04d868u; return 0; }
goto P_0c04d94c;
P_0c04d86a: /* original 0009, guest PC 0x0c04d86a */
if(!s->budget--) { s->failed_pc=0x0c04d86au; return 0; }
goto P_0c04d86c;
P_0c04d86c: /* original d307, guest PC 0x0c04d86c */
if(!s->budget--) { s->failed_pc=0x0c04d86cu; return 0; }
r[3]=read(ram,0x0c04d88cu,4);
goto P_0c04d86e;
P_0c04d86e: /* original 430b, guest PC 0x0c04d86e */
if(!s->budget--) { s->failed_pc=0x0c04d86eu; return 0; }
target=r[3];
r[16]=code_base|0x0c04d872u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d872u) { target=s->pc; goto dispatch; }
goto P_0c04d872;
P_0c04d870: /* original 64d3, guest PC 0x0c04d870 */
if(!s->budget--) { s->failed_pc=0x0c04d870u; return 0; }
r[4]=r[13];
goto P_0c04d872;
P_0c04d872: /* original 4011, guest PC 0x0c04d872 */
if(!s->budget--) { s->failed_pc=0x0c04d872u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04d874;
P_0c04d874: /* original 891a, guest PC 0x0c04d874 */
if(!s->budget--) { s->failed_pc=0x0c04d874u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d8ac; }
goto P_0c04d876;
P_0c04d876: /* original 9002, guest PC 0x0c04d876 */
if(!s->budget--) { s->failed_pc=0x0c04d876u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d87eu,2);
goto P_0c04d878;
P_0c04d878: /* original a068, guest PC 0x0c04d878 */
if(!s->budget--) { s->failed_pc=0x0c04d878u; return 0; }
goto P_0c04d94c;
P_0c04d87a: /* original 0009, guest PC 0x0c04d87a */
if(!s->budget--) { s->failed_pc=0x0c04d87au; return 0; }
if(!vf3_matrix_family(0x0c04d87cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04d87cu; return 0; } return 1;
P_0c04d8ac: /* original d345, guest PC 0x0c04d8ac */
if(!s->budget--) { s->failed_pc=0x0c04d8acu; return 0; }
r[3]=read(ram,0x0c04d9c4u,4);
goto P_0c04d8ae;
P_0c04d8ae: /* original 65c3, guest PC 0x0c04d8ae */
if(!s->budget--) { s->failed_pc=0x0c04d8aeu; return 0; }
r[5]=r[12];
goto P_0c04d8b0;
P_0c04d8b0: /* original 430b, guest PC 0x0c04d8b0 */
if(!s->budget--) { s->failed_pc=0x0c04d8b0u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d8b4u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d8b4u) { target=s->pc; goto dispatch; }
goto P_0c04d8b4;
P_0c04d8b2: /* original 64d3, guest PC 0x0c04d8b2 */
if(!s->budget--) { s->failed_pc=0x0c04d8b2u; return 0; }
r[4]=r[13];
goto P_0c04d8b4;
P_0c04d8b4: /* original 4011, guest PC 0x0c04d8b4 */
if(!s->budget--) { s->failed_pc=0x0c04d8b4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04d8b6;
P_0c04d8b6: /* original 8b0e, guest PC 0x0c04d8b6 */
if(!s->budget--) { s->failed_pc=0x0c04d8b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d8d6; }
goto P_0c04d8b8;
P_0c04d8b8: /* original d243, guest PC 0x0c04d8b8 */
if(!s->budget--) { s->failed_pc=0x0c04d8b8u; return 0; }
r[2]=read(ram,0x0c04d9c8u,4);
goto P_0c04d8ba;
P_0c04d8ba: /* original 65c3, guest PC 0x0c04d8ba */
if(!s->budget--) { s->failed_pc=0x0c04d8bau; return 0; }
r[5]=r[12];
goto P_0c04d8bc;
P_0c04d8bc: /* original 420b, guest PC 0x0c04d8bc */
if(!s->budget--) { s->failed_pc=0x0c04d8bcu; return 0; }
target=r[2];
r[16]=code_base|0x0c04d8c0u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d8c0u) { target=s->pc; goto dispatch; }
goto P_0c04d8c0;
P_0c04d8be: /* original 64d3, guest PC 0x0c04d8be */
if(!s->budget--) { s->failed_pc=0x0c04d8beu; return 0; }
r[4]=r[13];
goto P_0c04d8c0;
P_0c04d8c0: /* original 4011, guest PC 0x0c04d8c0 */
if(!s->budget--) { s->failed_pc=0x0c04d8c0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04d8c2;
P_0c04d8c2: /* original 8902, guest PC 0x0c04d8c2 */
if(!s->budget--) { s->failed_pc=0x0c04d8c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d8ca; }
goto P_0c04d8c4;
P_0c04d8c4: /* original 9079, guest PC 0x0c04d8c4 */
if(!s->budget--) { s->failed_pc=0x0c04d8c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d9bau,2);
goto P_0c04d8c6;
P_0c04d8c6: /* original a041, guest PC 0x0c04d8c6 */
if(!s->budget--) { s->failed_pc=0x0c04d8c6u; return 0; }
goto P_0c04d94c;
P_0c04d8c8: /* original 0009, guest PC 0x0c04d8c8 */
if(!s->budget--) { s->failed_pc=0x0c04d8c8u; return 0; }
goto P_0c04d8ca;
P_0c04d8ca: /* original d240, guest PC 0x0c04d8ca */
if(!s->budget--) { s->failed_pc=0x0c04d8cau; return 0; }
r[2]=read(ram,0x0c04d9ccu,4);
goto P_0c04d8cc;
P_0c04d8cc: /* original 420b, guest PC 0x0c04d8cc */
if(!s->budget--) { s->failed_pc=0x0c04d8ccu; return 0; }
target=r[2];
r[16]=code_base|0x0c04d8d0u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d8d0u) { target=s->pc; goto dispatch; }
goto P_0c04d8d0;
P_0c04d8ce: /* original 64d3, guest PC 0x0c04d8ce */
if(!s->budget--) { s->failed_pc=0x0c04d8ceu; return 0; }
r[4]=r[13];
goto P_0c04d8d0;
P_0c04d8d0: /* original 6e03, guest PC 0x0c04d8d0 */
if(!s->budget--) { s->failed_pc=0x0c04d8d0u; return 0; }
r[14]=r[0];
goto P_0c04d8d2;
P_0c04d8d2: /* original 2ee8, guest PC 0x0c04d8d2 */
if(!s->budget--) { s->failed_pc=0x0c04d8d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c04d8d4;
P_0c04d8d4: /* original 8b02, guest PC 0x0c04d8d4 */
if(!s->budget--) { s->failed_pc=0x0c04d8d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d8dc; }
goto P_0c04d8d6;
P_0c04d8d6: /* original 9071, guest PC 0x0c04d8d6 */
if(!s->budget--) { s->failed_pc=0x0c04d8d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d9bcu,2);
goto P_0c04d8d8;
P_0c04d8d8: /* original a038, guest PC 0x0c04d8d8 */
if(!s->budget--) { s->failed_pc=0x0c04d8d8u; return 0; }
goto P_0c04d94c;
P_0c04d8da: /* original 0009, guest PC 0x0c04d8da */
if(!s->budget--) { s->failed_pc=0x0c04d8dau; return 0; }
goto P_0c04d8dc;
P_0c04d8dc: /* original d23c, guest PC 0x0c04d8dc */
if(!s->budget--) { s->failed_pc=0x0c04d8dcu; return 0; }
r[2]=read(ram,0x0c04d9d0u,4);
goto P_0c04d8de;
P_0c04d8de: /* original 65c3, guest PC 0x0c04d8de */
if(!s->budget--) { s->failed_pc=0x0c04d8deu; return 0; }
r[5]=r[12];
goto P_0c04d8e0;
P_0c04d8e0: /* original 66f3, guest PC 0x0c04d8e0 */
if(!s->budget--) { s->failed_pc=0x0c04d8e0u; return 0; }
r[6]=r[15];
goto P_0c04d8e2;
P_0c04d8e2: /* original 420b, guest PC 0x0c04d8e2 */
if(!s->budget--) { s->failed_pc=0x0c04d8e2u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d8e6u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d8e6u) { target=s->pc; goto dispatch; }
goto P_0c04d8e6;
P_0c04d8e4: /* original 64d3, guest PC 0x0c04d8e4 */
if(!s->budget--) { s->failed_pc=0x0c04d8e4u; return 0; }
r[4]=r[13];
goto P_0c04d8e6;
P_0c04d8e6: /* original d33b, guest PC 0x0c04d8e6 */
if(!s->budget--) { s->failed_pc=0x0c04d8e6u; return 0; }
r[3]=read(ram,0x0c04d9d4u,4);
goto P_0c04d8e8;
P_0c04d8e8: /* original 4011, guest PC 0x0c04d8e8 */
if(!s->budget--) { s->failed_pc=0x0c04d8e8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04d8ea;
P_0c04d8ea: /* original 8d06, guest PC 0x0c04d8ea */
if(!s->budget--) { s->failed_pc=0x0c04d8eau; return 0; }
cond=r[17]&1u;
write(ram,r[3],r[0],4);
if(cond) { goto P_0c04d8fa; }
goto P_0c04d8ee;
P_0c04d8ec: /* original 2302, guest PC 0x0c04d8ec */
if(!s->budget--) { s->failed_pc=0x0c04d8ecu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c04d8ee;
P_0c04d8ee: /* original d13a, guest PC 0x0c04d8ee */
if(!s->budget--) { s->failed_pc=0x0c04d8eeu; return 0; }
r[1]=read(ram,0x0c04d9d8u,4);
goto P_0c04d8f0;
P_0c04d8f0: /* original 410b, guest PC 0x0c04d8f0 */
if(!s->budget--) { s->failed_pc=0x0c04d8f0u; return 0; }
target=r[1];
r[16]=code_base|0x0c04d8f4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d8f4u) { target=s->pc; goto dispatch; }
goto P_0c04d8f4;
P_0c04d8f2: /* original 64e3, guest PC 0x0c04d8f2 */
if(!s->budget--) { s->failed_pc=0x0c04d8f2u; return 0; }
r[4]=r[14];
goto P_0c04d8f4;
P_0c04d8f4: /* original 9063, guest PC 0x0c04d8f4 */
if(!s->budget--) { s->failed_pc=0x0c04d8f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d9beu,2);
goto P_0c04d8f6;
P_0c04d8f6: /* original a029, guest PC 0x0c04d8f6 */
if(!s->budget--) { s->failed_pc=0x0c04d8f6u; return 0; }
goto P_0c04d94c;
P_0c04d8f8: /* original 0009, guest PC 0x0c04d8f8 */
if(!s->budget--) { s->failed_pc=0x0c04d8f8u; return 0; }
goto P_0c04d8fa;
P_0c04d8fa: /* original e040, guest PC 0x0c04d8fa */
if(!s->budget--) { s->failed_pc=0x0c04d8fau; return 0; }
r[0]=0x00000040u;
goto P_0c04d8fc;
P_0c04d8fc: /* original 1ea1, guest PC 0x0c04d8fc */
if(!s->budget--) { s->failed_pc=0x0c04d8fcu; return 0; }
write(ram,r[14]+4,r[10],4);
goto P_0c04d8fe;
P_0c04d8fe: /* original 53fa, guest PC 0x0c04d8fe */
if(!s->budget--) { s->failed_pc=0x0c04d8feu; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c04d900;
P_0c04d900: /* original 1e3d, guest PC 0x0c04d900 */
if(!s->budget--) { s->failed_pc=0x0c04d900u; return 0; }
write(ram,r[14]+52,r[3],4);
goto P_0c04d902;
P_0c04d902: /* original 52f3, guest PC 0x0c04d902 */
if(!s->budget--) { s->failed_pc=0x0c04d902u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c04d904;
P_0c04d904: /* original 1e2e, guest PC 0x0c04d904 */
if(!s->budget--) { s->failed_pc=0x0c04d904u; return 0; }
write(ram,r[14]+56,r[2],4);
goto P_0c04d906;
P_0c04d906: /* original 6323, guest PC 0x0c04d906 */
if(!s->budget--) { s->failed_pc=0x0c04d906u; return 0; }
r[3]=r[2];
goto P_0c04d908;
P_0c04d908: /* original 0e26, guest PC 0x0c04d908 */
if(!s->budget--) { s->failed_pc=0x0c04d908u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c04d90a;
P_0c04d90a: /* original 1eda, guest PC 0x0c04d90a */
if(!s->budget--) { s->failed_pc=0x0c04d90au; return 0; }
write(ram,r[14]+40,r[13],4);
goto P_0c04d90c;
P_0c04d90c: /* original 85f4, guest PC 0x0c04d90c */
if(!s->budget--) { s->failed_pc=0x0c04d90cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c04d90e;
P_0c04d90e: /* original 81e1, guest PC 0x0c04d90e */
if(!s->budget--) { s->failed_pc=0x0c04d90eu; return 0; }
write(ram,r[14]+2,r[0],2);
goto P_0c04d910;
P_0c04d910: /* original 84fa, guest PC 0x0c04d910 */
if(!s->budget--) { s->failed_pc=0x0c04d910u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+10,1);
goto P_0c04d912;
P_0c04d912: /* original 80e1, guest PC 0x0c04d912 */
if(!s->budget--) { s->failed_pc=0x0c04d912u; return 0; }
write(ram,r[14]+1,r[0],1);
goto P_0c04d914;
P_0c04d914: /* original 53e1, guest PC 0x0c04d914 */
if(!s->budget--) { s->failed_pc=0x0c04d914u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c04d916;
P_0c04d916: /* original 2f36, guest PC 0x0c04d916 */
if(!s->budget--) { s->failed_pc=0x0c04d916u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d918;
P_0c04d918: /* original d331, guest PC 0x0c04d918 */
if(!s->budget--) { s->failed_pc=0x0c04d918u; return 0; }
r[3]=read(ram,0x0c04d9e0u,4);
goto P_0c04d91a;
P_0c04d91a: /* original d230, guest PC 0x0c04d91a */
if(!s->budget--) { s->failed_pc=0x0c04d91au; return 0; }
r[2]=read(ram,0x0c04d9dcu,4);
goto P_0c04d91c;
P_0c04d91c: /* original 430b, guest PC 0x0c04d91c */
if(!s->budget--) { s->failed_pc=0x0c04d91cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04d920u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d920u) { target=s->pc; goto dispatch; }
goto P_0c04d920;
P_0c04d91e: /* original 2f26, guest PC 0x0c04d91e */
if(!s->budget--) { s->failed_pc=0x0c04d91eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d920;
P_0c04d920: /* original 51ed, guest PC 0x0c04d920 */
if(!s->budget--) { s->failed_pc=0x0c04d920u; return 0; }
r[1]=read(ram,r[14]+52,4);
goto P_0c04d922;
P_0c04d922: /* original 2f16, guest PC 0x0c04d922 */
if(!s->budget--) { s->failed_pc=0x0c04d922u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d924;
P_0c04d924: /* original d32f, guest PC 0x0c04d924 */
if(!s->budget--) { s->failed_pc=0x0c04d924u; return 0; }
r[3]=read(ram,0x0c04d9e4u,4);
goto P_0c04d926;
P_0c04d926: /* original d22e, guest PC 0x0c04d926 */
if(!s->budget--) { s->failed_pc=0x0c04d926u; return 0; }
r[2]=read(ram,0x0c04d9e0u,4);
goto P_0c04d928;
P_0c04d928: /* original 420b, guest PC 0x0c04d928 */
if(!s->budget--) { s->failed_pc=0x0c04d928u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d92cu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d92cu) { target=s->pc; goto dispatch; }
goto P_0c04d92c;
P_0c04d92a: /* original 2f36, guest PC 0x0c04d92a */
if(!s->budget--) { s->failed_pc=0x0c04d92au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d92c;
P_0c04d92c: /* original 51ee, guest PC 0x0c04d92c */
if(!s->budget--) { s->failed_pc=0x0c04d92cu; return 0; }
r[1]=read(ram,r[14]+56,4);
goto P_0c04d92e;
P_0c04d92e: /* original 2f16, guest PC 0x0c04d92e */
if(!s->budget--) { s->failed_pc=0x0c04d92eu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d930;
P_0c04d930: /* original d32d, guest PC 0x0c04d930 */
if(!s->budget--) { s->failed_pc=0x0c04d930u; return 0; }
r[3]=read(ram,0x0c04d9e8u,4);
goto P_0c04d932;
P_0c04d932: /* original d22b, guest PC 0x0c04d932 */
if(!s->budget--) { s->failed_pc=0x0c04d932u; return 0; }
r[2]=read(ram,0x0c04d9e0u,4);
goto P_0c04d934;
P_0c04d934: /* original 420b, guest PC 0x0c04d934 */
if(!s->budget--) { s->failed_pc=0x0c04d934u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d938u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d938u) { target=s->pc; goto dispatch; }
goto P_0c04d938;
P_0c04d936: /* original 2f36, guest PC 0x0c04d936 */
if(!s->budget--) { s->failed_pc=0x0c04d936u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d938;
P_0c04d938: /* original e040, guest PC 0x0c04d938 */
if(!s->budget--) { s->failed_pc=0x0c04d938u; return 0; }
r[0]=0x00000040u;
goto P_0c04d93a;
P_0c04d93a: /* original 01ee, guest PC 0x0c04d93a */
if(!s->budget--) { s->failed_pc=0x0c04d93au; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c04d93c;
P_0c04d93c: /* original 2f16, guest PC 0x0c04d93c */
if(!s->budget--) { s->failed_pc=0x0c04d93cu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d93e;
P_0c04d93e: /* original d32b, guest PC 0x0c04d93e */
if(!s->budget--) { s->failed_pc=0x0c04d93eu; return 0; }
r[3]=read(ram,0x0c04d9ecu,4);
goto P_0c04d940;
P_0c04d940: /* original d227, guest PC 0x0c04d940 */
if(!s->budget--) { s->failed_pc=0x0c04d940u; return 0; }
r[2]=read(ram,0x0c04d9e0u,4);
goto P_0c04d942;
P_0c04d942: /* original 420b, guest PC 0x0c04d942 */
if(!s->budget--) { s->failed_pc=0x0c04d942u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d946u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d946u) { target=s->pc; goto dispatch; }
goto P_0c04d946;
P_0c04d944: /* original 2f36, guest PC 0x0c04d944 */
if(!s->budget--) { s->failed_pc=0x0c04d944u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d946;
P_0c04d946: /* original 60a3, guest PC 0x0c04d946 */
if(!s->budget--) { s->failed_pc=0x0c04d946u; return 0; }
r[0]=r[10];
goto P_0c04d948;
P_0c04d948: /* original 2be2, guest PC 0x0c04d948 */
if(!s->budget--) { s->failed_pc=0x0c04d948u; return 0; }
write(ram,r[11],r[14],4);
goto P_0c04d94a;
P_0c04d94a: /* original 7f20, guest PC 0x0c04d94a */
if(!s->budget--) { s->failed_pc=0x0c04d94au; return 0; }
r[15]+=0x00000020u;
goto P_0c04d94c;
P_0c04d94c: /* original 7f2c, guest PC 0x0c04d94c */
if(!s->budget--) { s->failed_pc=0x0c04d94cu; return 0; }
r[15]+=0x0000002cu;
goto P_0c04d94e;
P_0c04d94e: /* original 4f16, guest PC 0x0c04d94e */
if(!s->budget--) { s->failed_pc=0x0c04d94eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d950;
P_0c04d950: /* original 4f26, guest PC 0x0c04d950 */
if(!s->budget--) { s->failed_pc=0x0c04d950u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d952;
P_0c04d952: /* original 6af6, guest PC 0x0c04d952 */
if(!s->budget--) { s->failed_pc=0x0c04d952u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04d954;
P_0c04d954: /* original 6bf6, guest PC 0x0c04d954 */
if(!s->budget--) { s->failed_pc=0x0c04d954u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04d956;
P_0c04d956: /* original 6cf6, guest PC 0x0c04d956 */
if(!s->budget--) { s->failed_pc=0x0c04d956u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04d958;
P_0c04d958: /* original 6df6, guest PC 0x0c04d958 */
if(!s->budget--) { s->failed_pc=0x0c04d958u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04d95a;
P_0c04d95a: /* original 000b, guest PC 0x0c04d95a */
if(!s->budget--) { s->failed_pc=0x0c04d95au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04d95c: /* original 6ef6, guest PC 0x0c04d95c */
if(!s->budget--) { s->failed_pc=0x0c04d95cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04d95e;
P_0c04d95e: /* original 2fe6, guest PC 0x0c04d95e */
if(!s->budget--) { s->failed_pc=0x0c04d95eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d960;
P_0c04d960: /* original 6e43, guest PC 0x0c04d960 */
if(!s->budget--) { s->failed_pc=0x0c04d960u; return 0; }
r[14]=r[4];
goto P_0c04d962;
P_0c04d962: /* original 2fd6, guest PC 0x0c04d962 */
if(!s->budget--) { s->failed_pc=0x0c04d962u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d964;
P_0c04d964: /* original 2fc6, guest PC 0x0c04d964 */
if(!s->budget--) { s->failed_pc=0x0c04d964u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d966;
P_0c04d966: /* original 6c53, guest PC 0x0c04d966 */
if(!s->budget--) { s->failed_pc=0x0c04d966u; return 0; }
r[12]=r[5];
goto P_0c04d968;
P_0c04d968: /* original 2fb6, guest PC 0x0c04d968 */
if(!s->budget--) { s->failed_pc=0x0c04d968u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d96a;
P_0c04d96a: /* original 2fa6, guest PC 0x0c04d96a */
if(!s->budget--) { s->failed_pc=0x0c04d96au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d96c;
P_0c04d96c: /* original 6a73, guest PC 0x0c04d96c */
if(!s->budget--) { s->failed_pc=0x0c04d96cu; return 0; }
r[10]=r[7];
goto P_0c04d96e;
P_0c04d96e: /* original 2f96, guest PC 0x0c04d96e */
if(!s->budget--) { s->failed_pc=0x0c04d96eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d970;
P_0c04d970: /* original 4f22, guest PC 0x0c04d970 */
if(!s->budget--) { s->failed_pc=0x0c04d970u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04d972;
P_0c04d972: /* original 4f12, guest PC 0x0c04d972 */
if(!s->budget--) { s->failed_pc=0x0c04d972u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04d974;
P_0c04d974: /* original 7fc8, guest PC 0x0c04d974 */
if(!s->budget--) { s->failed_pc=0x0c04d974u; return 0; }
r[15]+=0xffffffc8u;
goto P_0c04d976;
P_0c04d976: /* original 2f62, guest PC 0x0c04d976 */
if(!s->budget--) { s->failed_pc=0x0c04d976u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c04d978;
P_0c04d978: /* original 9322, guest PC 0x0c04d978 */
if(!s->budget--) { s->failed_pc=0x0c04d978u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d9c0u,2);
goto P_0c04d97a;
P_0c04d97a: /* original 2e3f, guest PC 0x0c04d97a */
if(!s->budget--) { s->failed_pc=0x0c04d97au; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c04d97c;
P_0c04d97c: /* original 031a, guest PC 0x0c04d97c */
if(!s->budget--) { s->failed_pc=0x0c04d97cu; return 0; }
r[3]=r[19];
goto P_0c04d97e;
P_0c04d97e: /* original 633f, guest PC 0x0c04d97e */
if(!s->budget--) { s->failed_pc=0x0c04d97eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04d980;
P_0c04d980: /* original 1f32, guest PC 0x0c04d980 */
if(!s->budget--) { s->failed_pc=0x0c04d980u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c04d982;
P_0c04d982: /* original d21b, guest PC 0x0c04d982 */
if(!s->budget--) { s->failed_pc=0x0c04d982u; return 0; }
r[2]=read(ram,0x0c04d9f0u,4);
goto P_0c04d984;
P_0c04d984: /* original 332c, guest PC 0x0c04d984 */
if(!s->budget--) { s->failed_pc=0x0c04d984u; return 0; }
r[3]+=r[2];
goto P_0c04d986;
P_0c04d986: /* original 1f31, guest PC 0x0c04d986 */
if(!s->budget--) { s->failed_pc=0x0c04d986u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c04d988;
P_0c04d988: /* original 2fa6, guest PC 0x0c04d988 */
if(!s->budget--) { s->failed_pc=0x0c04d988u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d98a;
P_0c04d98a: /* original 51f1, guest PC 0x0c04d98a */
if(!s->budget--) { s->failed_pc=0x0c04d98au; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c04d98c;
P_0c04d98c: /* original 2f16, guest PC 0x0c04d98c */
if(!s->budget--) { s->failed_pc=0x0c04d98cu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d98e;
P_0c04d98e: /* original 2fc6, guest PC 0x0c04d98e */
if(!s->budget--) { s->failed_pc=0x0c04d98eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d990;
P_0c04d990: /* original 2fe6, guest PC 0x0c04d990 */
if(!s->budget--) { s->failed_pc=0x0c04d990u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d992;
P_0c04d992: /* original d118, guest PC 0x0c04d992 */
if(!s->budget--) { s->failed_pc=0x0c04d992u; return 0; }
r[1]=read(ram,0x0c04d9f4u,4);
goto P_0c04d994;
P_0c04d994: /* original d312, guest PC 0x0c04d994 */
if(!s->budget--) { s->failed_pc=0x0c04d994u; return 0; }
r[3]=read(ram,0x0c04d9e0u,4);
goto P_0c04d996;
P_0c04d996: /* original 430b, guest PC 0x0c04d996 */
if(!s->budget--) { s->failed_pc=0x0c04d996u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d99au;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d99au) { target=s->pc; goto dispatch; }
goto P_0c04d99a;
P_0c04d998: /* original 2f16, guest PC 0x0c04d998 */
if(!s->budget--) { s->failed_pc=0x0c04d998u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d99a;
P_0c04d99a: /* original 7f14, guest PC 0x0c04d99a */
if(!s->budget--) { s->failed_pc=0x0c04d99au; return 0; }
r[15]+=0x00000014u;
goto P_0c04d99c;
P_0c04d99c: /* original eb00, guest PC 0x0c04d99c */
if(!s->budget--) { s->failed_pc=0x0c04d99cu; return 0; }
r[11]=0x00000000u;
goto P_0c04d99e;
P_0c04d99e: /* original 2ab2, guest PC 0x0c04d99e */
if(!s->budget--) { s->failed_pc=0x0c04d99eu; return 0; }
write(ram,r[10],r[11],4);
goto P_0c04d9a0;
P_0c04d9a0: /* original 52f1, guest PC 0x0c04d9a0 */
if(!s->budget--) { s->failed_pc=0x0c04d9a0u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c04d9a2;
P_0c04d9a2: /* original 8422, guest PC 0x0c04d9a2 */
if(!s->budget--) { s->failed_pc=0x0c04d9a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+2,1);
goto P_0c04d9a4;
P_0c04d9a4: /* original 2008, guest PC 0x0c04d9a4 */
if(!s->budget--) { s->failed_pc=0x0c04d9a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d9a6;
P_0c04d9a6: /* original 8934, guest PC 0x0c04d9a6 */
if(!s->budget--) { s->failed_pc=0x0c04d9a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04da12; }
goto P_0c04d9a8;
P_0c04d9a8: /* original d213, guest PC 0x0c04d9a8 */
if(!s->budget--) { s->failed_pc=0x0c04d9a8u; return 0; }
r[2]=read(ram,0x0c04d9f8u,4);
goto P_0c04d9aa;
P_0c04d9aa: /* original 420b, guest PC 0x0c04d9aa */
if(!s->budget--) { s->failed_pc=0x0c04d9aau; return 0; }
target=r[2];
r[16]=code_base|0x0c04d9aeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d9aeu) { target=s->pc; goto dispatch; }
goto P_0c04d9ae;
P_0c04d9ac: /* original 64e3, guest PC 0x0c04d9ac */
if(!s->budget--) { s->failed_pc=0x0c04d9acu; return 0; }
r[4]=r[14];
goto P_0c04d9ae;
P_0c04d9ae: /* original 2008, guest PC 0x0c04d9ae */
if(!s->budget--) { s->failed_pc=0x0c04d9aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d9b0;
P_0c04d9b0: /* original 8b24, guest PC 0x0c04d9b0 */
if(!s->budget--) { s->failed_pc=0x0c04d9b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d9fc; }
goto P_0c04d9b2;
P_0c04d9b2: /* original ba8c, guest PC 0x0c04d9b2 */
if(!s->budget--) { s->failed_pc=0x0c04d9b2u; return 0; }
target=code_base|0x0c04ceceu; r[16]=code_base|0x0c04d9b6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d9b6u) { target=s->pc; goto dispatch; }
goto P_0c04d9b6;
P_0c04d9b4: /* original 64e3, guest PC 0x0c04d9b4 */
if(!s->budget--) { s->failed_pc=0x0c04d9b4u; return 0; }
r[4]=r[14];
goto P_0c04d9b6;
P_0c04d9b6: /* original a02c, guest PC 0x0c04d9b6 */
if(!s->budget--) { s->failed_pc=0x0c04d9b6u; return 0; }
goto P_0c04da12;
P_0c04d9b8: /* original 0009, guest PC 0x0c04d9b8 */
if(!s->budget--) { s->failed_pc=0x0c04d9b8u; return 0; }
if(!vf3_matrix_family(0x0c04d9bau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04d9bau; return 0; } return 1;
P_0c04d9fc: /* original d33b, guest PC 0x0c04d9fc */
if(!s->budget--) { s->failed_pc=0x0c04d9fcu; return 0; }
r[3]=read(ram,0x0c04daecu,4);
goto P_0c04d9fe;
P_0c04d9fe: /* original 430b, guest PC 0x0c04d9fe */
if(!s->budget--) { s->failed_pc=0x0c04d9feu; return 0; }
target=r[3];
r[16]=code_base|0x0c04da02u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04da02u) { target=s->pc; goto dispatch; }
goto P_0c04da02;
P_0c04da00: /* original 64e3, guest PC 0x0c04da00 */
if(!s->budget--) { s->failed_pc=0x0c04da00u; return 0; }
r[4]=r[14];
goto P_0c04da02;
P_0c04da02: /* original 2008, guest PC 0x0c04da02 */
if(!s->budget--) { s->failed_pc=0x0c04da02u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04da04;
P_0c04da04: /* original 8905, guest PC 0x0c04da04 */
if(!s->budget--) { s->failed_pc=0x0c04da04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04da12; }
goto P_0c04da06;
P_0c04da06: /* original 52f2, guest PC 0x0c04da06 */
if(!s->budget--) { s->failed_pc=0x0c04da06u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c04da08;
P_0c04da08: /* original d339, guest PC 0x0c04da08 */
if(!s->budget--) { s->failed_pc=0x0c04da08u; return 0; }
r[3]=read(ram,0x0c04daf0u,4);
goto P_0c04da0a;
P_0c04da0a: /* original 323c, guest PC 0x0c04da0a */
if(!s->budget--) { s->failed_pc=0x0c04da0au; return 0; }
r[2]+=r[3];
goto P_0c04da0c;
P_0c04da0c: /* original 8428, guest PC 0x0c04da0c */
if(!s->budget--) { s->failed_pc=0x0c04da0cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04da0e;
P_0c04da0e: /* original 2008, guest PC 0x0c04da0e */
if(!s->budget--) { s->failed_pc=0x0c04da0eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04da10;
P_0c04da10: /* original 8b02, guest PC 0x0c04da10 */
if(!s->budget--) { s->failed_pc=0x0c04da10u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04da18; }
goto P_0c04da12;
P_0c04da12: /* original 9064, guest PC 0x0c04da12 */
if(!s->budget--) { s->failed_pc=0x0c04da12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dadeu,2);
goto P_0c04da14;
P_0c04da14: /* original a096, guest PC 0x0c04da14 */
if(!s->budget--) { s->failed_pc=0x0c04da14u; return 0; }
goto P_0c04db44;
P_0c04da16: /* original 0009, guest PC 0x0c04da16 */
if(!s->budget--) { s->failed_pc=0x0c04da16u; return 0; }
goto P_0c04da18;
P_0c04da18: /* original d336, guest PC 0x0c04da18 */
if(!s->budget--) { s->failed_pc=0x0c04da18u; return 0; }
r[3]=read(ram,0x0c04daf4u,4);
goto P_0c04da1a;
P_0c04da1a: /* original 430b, guest PC 0x0c04da1a */
if(!s->budget--) { s->failed_pc=0x0c04da1au; return 0; }
target=r[3];
r[16]=code_base|0x0c04da1eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04da1eu) { target=s->pc; goto dispatch; }
goto P_0c04da1e;
P_0c04da1c: /* original 64e3, guest PC 0x0c04da1c */
if(!s->budget--) { s->failed_pc=0x0c04da1cu; return 0; }
r[4]=r[14];
goto P_0c04da1e;
P_0c04da1e: /* original 4011, guest PC 0x0c04da1e */
if(!s->budget--) { s->failed_pc=0x0c04da1eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04da20;
P_0c04da20: /* original 8902, guest PC 0x0c04da20 */
if(!s->budget--) { s->failed_pc=0x0c04da20u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04da28; }
goto P_0c04da22;
P_0c04da22: /* original 905d, guest PC 0x0c04da22 */
if(!s->budget--) { s->failed_pc=0x0c04da22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dae0u,2);
goto P_0c04da24;
P_0c04da24: /* original a08e, guest PC 0x0c04da24 */
if(!s->budget--) { s->failed_pc=0x0c04da24u; return 0; }
goto P_0c04db44;
P_0c04da26: /* original 0009, guest PC 0x0c04da26 */
if(!s->budget--) { s->failed_pc=0x0c04da26u; return 0; }
goto P_0c04da28;
P_0c04da28: /* original 53f1, guest PC 0x0c04da28 */
if(!s->budget--) { s->failed_pc=0x0c04da28u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c04da2a;
P_0c04da2a: /* original 5237, guest PC 0x0c04da2a */
if(!s->budget--) { s->failed_pc=0x0c04da2au; return 0; }
r[2]=read(ram,r[3]+28,4);
goto P_0c04da2c;
P_0c04da2c: /* original 512e, guest PC 0x0c04da2c */
if(!s->budget--) { s->failed_pc=0x0c04da2cu; return 0; }
r[1]=read(ram,r[2]+56,4);
goto P_0c04da2e;
P_0c04da2e: /* original 2118, guest PC 0x0c04da2e */
if(!s->budget--) { s->failed_pc=0x0c04da2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c04da30;
P_0c04da30: /* original 8928, guest PC 0x0c04da30 */
if(!s->budget--) { s->failed_pc=0x0c04da30u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04da84; }
goto P_0c04da32;
P_0c04da32: /* original d331, guest PC 0x0c04da32 */
if(!s->budget--) { s->failed_pc=0x0c04da32u; return 0; }
r[3]=read(ram,0x0c04daf8u,4);
goto P_0c04da34;
P_0c04da34: /* original 65c3, guest PC 0x0c04da34 */
if(!s->budget--) { s->failed_pc=0x0c04da34u; return 0; }
r[5]=r[12];
goto P_0c04da36;
P_0c04da36: /* original 430b, guest PC 0x0c04da36 */
if(!s->budget--) { s->failed_pc=0x0c04da36u; return 0; }
target=r[3];
r[16]=code_base|0x0c04da3au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04da3au) { target=s->pc; goto dispatch; }
goto P_0c04da3a;
P_0c04da38: /* original 64e3, guest PC 0x0c04da38 */
if(!s->budget--) { s->failed_pc=0x0c04da38u; return 0; }
r[4]=r[14];
goto P_0c04da3a;
P_0c04da3a: /* original 4011, guest PC 0x0c04da3a */
if(!s->budget--) { s->failed_pc=0x0c04da3au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04da3c;
P_0c04da3c: /* original 8b22, guest PC 0x0c04da3c */
if(!s->budget--) { s->failed_pc=0x0c04da3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04da84; }
goto P_0c04da3e;
P_0c04da3e: /* original d32f, guest PC 0x0c04da3e */
if(!s->budget--) { s->failed_pc=0x0c04da3eu; return 0; }
r[3]=read(ram,0x0c04dafcu,4);
goto P_0c04da40;
P_0c04da40: /* original 66f3, guest PC 0x0c04da40 */
if(!s->budget--) { s->failed_pc=0x0c04da40u; return 0; }
r[6]=r[15];
goto P_0c04da42;
P_0c04da42: /* original 65c3, guest PC 0x0c04da42 */
if(!s->budget--) { s->failed_pc=0x0c04da42u; return 0; }
r[5]=r[12];
goto P_0c04da44;
P_0c04da44: /* original 760c, guest PC 0x0c04da44 */
if(!s->budget--) { s->failed_pc=0x0c04da44u; return 0; }
r[6]+=0x0000000cu;
goto P_0c04da46;
P_0c04da46: /* original 430b, guest PC 0x0c04da46 */
if(!s->budget--) { s->failed_pc=0x0c04da46u; return 0; }
target=r[3];
r[16]=code_base|0x0c04da4au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04da4au) { target=s->pc; goto dispatch; }
goto P_0c04da4a;
P_0c04da48: /* original 64e3, guest PC 0x0c04da48 */
if(!s->budget--) { s->failed_pc=0x0c04da48u; return 0; }
r[4]=r[14];
goto P_0c04da4a;
P_0c04da4a: /* original 4011, guest PC 0x0c04da4a */
if(!s->budget--) { s->failed_pc=0x0c04da4au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04da4c;
P_0c04da4c: /* original 8b02, guest PC 0x0c04da4c */
if(!s->budget--) { s->failed_pc=0x0c04da4cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04da54; }
goto P_0c04da4e;
P_0c04da4e: /* original 9048, guest PC 0x0c04da4e */
if(!s->budget--) { s->failed_pc=0x0c04da4eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dae2u,2);
goto P_0c04da50;
P_0c04da50: /* original a078, guest PC 0x0c04da50 */
if(!s->budget--) { s->failed_pc=0x0c04da50u; return 0; }
goto P_0c04db44;
P_0c04da52: /* original 0009, guest PC 0x0c04da52 */
if(!s->budget--) { s->failed_pc=0x0c04da52u; return 0; }
goto P_0c04da54;
P_0c04da54: /* original d32a, guest PC 0x0c04da54 */
if(!s->budget--) { s->failed_pc=0x0c04da54u; return 0; }
r[3]=read(ram,0x0c04db00u,4);
goto P_0c04da56;
P_0c04da56: /* original 65f3, guest PC 0x0c04da56 */
if(!s->budget--) { s->failed_pc=0x0c04da56u; return 0; }
r[5]=r[15];
goto P_0c04da58;
P_0c04da58: /* original 750c, guest PC 0x0c04da58 */
if(!s->budget--) { s->failed_pc=0x0c04da58u; return 0; }
r[5]+=0x0000000cu;
goto P_0c04da5a;
P_0c04da5a: /* original 430b, guest PC 0x0c04da5a */
if(!s->budget--) { s->failed_pc=0x0c04da5au; return 0; }
target=r[3];
r[16]=code_base|0x0c04da5eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04da5eu) { target=s->pc; goto dispatch; }
goto P_0c04da5e;
P_0c04da5c: /* original 64e3, guest PC 0x0c04da5c */
if(!s->budget--) { s->failed_pc=0x0c04da5cu; return 0; }
r[4]=r[14];
goto P_0c04da5e;
P_0c04da5e: /* original 4011, guest PC 0x0c04da5e */
if(!s->budget--) { s->failed_pc=0x0c04da5eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04da60;
P_0c04da60: /* original 8b02, guest PC 0x0c04da60 */
if(!s->budget--) { s->failed_pc=0x0c04da60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04da68; }
goto P_0c04da62;
P_0c04da62: /* original 903f, guest PC 0x0c04da62 */
if(!s->budget--) { s->failed_pc=0x0c04da62u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dae4u,2);
goto P_0c04da64;
P_0c04da64: /* original a06e, guest PC 0x0c04da64 */
if(!s->budget--) { s->failed_pc=0x0c04da64u; return 0; }
goto P_0c04db44;
P_0c04da66: /* original 0009, guest PC 0x0c04da66 */
if(!s->budget--) { s->failed_pc=0x0c04da66u; return 0; }
goto P_0c04da68;
P_0c04da68: /* original d326, guest PC 0x0c04da68 */
if(!s->budget--) { s->failed_pc=0x0c04da68u; return 0; }
r[3]=read(ram,0x0c04db04u,4);
goto P_0c04da6a;
P_0c04da6a: /* original e500, guest PC 0x0c04da6a */
if(!s->budget--) { s->failed_pc=0x0c04da6au; return 0; }
r[5]=0x00000000u;
goto P_0c04da6c;
P_0c04da6c: /* original 430b, guest PC 0x0c04da6c */
if(!s->budget--) { s->failed_pc=0x0c04da6cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04da70u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04da70u) { target=s->pc; goto dispatch; }
goto P_0c04da70;
P_0c04da6e: /* original 64e3, guest PC 0x0c04da6e */
if(!s->budget--) { s->failed_pc=0x0c04da6eu; return 0; }
r[4]=r[14];
goto P_0c04da70;
P_0c04da70: /* original d225, guest PC 0x0c04da70 */
if(!s->budget--) { s->failed_pc=0x0c04da70u; return 0; }
r[2]=read(ram,0x0c04db08u,4);
goto P_0c04da72;
P_0c04da72: /* original 600d, guest PC 0x0c04da72 */
if(!s->budget--) { s->failed_pc=0x0c04da72u; return 0; }
r[0]=r[0]&65535u;
goto P_0c04da74;
P_0c04da74: /* original 3020, guest PC 0x0c04da74 */
if(!s->budget--) { s->failed_pc=0x0c04da74u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[2])!=0);
goto P_0c04da76;
P_0c04da76: /* original 8b05, guest PC 0x0c04da76 */
if(!s->budget--) { s->failed_pc=0x0c04da76u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04da84; }
goto P_0c04da78;
P_0c04da78: /* original d324, guest PC 0x0c04da78 */
if(!s->budget--) { s->failed_pc=0x0c04da78u; return 0; }
r[3]=read(ram,0x0c04db0cu,4);
goto P_0c04da7a;
P_0c04da7a: /* original 430b, guest PC 0x0c04da7a */
if(!s->budget--) { s->failed_pc=0x0c04da7au; return 0; }
target=r[3];
r[16]=code_base|0x0c04da7eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04da7eu) { target=s->pc; goto dispatch; }
goto P_0c04da7e;
P_0c04da7c: /* original 64e3, guest PC 0x0c04da7c */
if(!s->budget--) { s->failed_pc=0x0c04da7cu; return 0; }
r[4]=r[14];
goto P_0c04da7e;
P_0c04da7e: /* original 6903, guest PC 0x0c04da7e */
if(!s->budget--) { s->failed_pc=0x0c04da7eu; return 0; }
r[9]=r[0];
goto P_0c04da80;
P_0c04da80: /* original 4911, guest PC 0x0c04da80 */
if(!s->budget--) { s->failed_pc=0x0c04da80u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=0)!=0);
goto P_0c04da82;
P_0c04da82: /* original 8902, guest PC 0x0c04da82 */
if(!s->budget--) { s->failed_pc=0x0c04da82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04da8a; }
goto P_0c04da84;
P_0c04da84: /* original 902f, guest PC 0x0c04da84 */
if(!s->budget--) { s->failed_pc=0x0c04da84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dae6u,2);
goto P_0c04da86;
P_0c04da86: /* original a05d, guest PC 0x0c04da86 */
if(!s->budget--) { s->failed_pc=0x0c04da86u; return 0; }
goto P_0c04db44;
P_0c04da88: /* original 0009, guest PC 0x0c04da88 */
if(!s->budget--) { s->failed_pc=0x0c04da88u; return 0; }
goto P_0c04da8a;
P_0c04da8a: /* original d321, guest PC 0x0c04da8a */
if(!s->budget--) { s->failed_pc=0x0c04da8au; return 0; }
r[3]=read(ram,0x0c04db10u,4);
goto P_0c04da8c;
P_0c04da8c: /* original 6593, guest PC 0x0c04da8c */
if(!s->budget--) { s->failed_pc=0x0c04da8cu; return 0; }
r[5]=r[9];
goto P_0c04da8e;
P_0c04da8e: /* original 430b, guest PC 0x0c04da8e */
if(!s->budget--) { s->failed_pc=0x0c04da8eu; return 0; }
target=r[3];
r[16]=code_base|0x0c04da92u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04da92u) { target=s->pc; goto dispatch; }
goto P_0c04da92;
P_0c04da90: /* original 64e3, guest PC 0x0c04da90 */
if(!s->budget--) { s->failed_pc=0x0c04da90u; return 0; }
r[4]=r[14];
goto P_0c04da92;
P_0c04da92: /* original d220, guest PC 0x0c04da92 */
if(!s->budget--) { s->failed_pc=0x0c04da92u; return 0; }
r[2]=read(ram,0x0c04db14u,4);
goto P_0c04da94;
P_0c04da94: /* original 420b, guest PC 0x0c04da94 */
if(!s->budget--) { s->failed_pc=0x0c04da94u; return 0; }
target=r[2];
r[16]=code_base|0x0c04da98u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04da98u) { target=s->pc; goto dispatch; }
goto P_0c04da98;
P_0c04da96: /* original 64e3, guest PC 0x0c04da96 */
if(!s->budget--) { s->failed_pc=0x0c04da96u; return 0; }
r[4]=r[14];
goto P_0c04da98;
P_0c04da98: /* original 6d03, guest PC 0x0c04da98 */
if(!s->budget--) { s->failed_pc=0x0c04da98u; return 0; }
r[13]=r[0];
goto P_0c04da9a;
P_0c04da9a: /* original 2dd8, guest PC 0x0c04da9a */
if(!s->budget--) { s->failed_pc=0x0c04da9au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c04da9c;
P_0c04da9c: /* original 8b02, guest PC 0x0c04da9c */
if(!s->budget--) { s->failed_pc=0x0c04da9cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04daa4; }
goto P_0c04da9e;
P_0c04da9e: /* original 9023, guest PC 0x0c04da9e */
if(!s->budget--) { s->failed_pc=0x0c04da9eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dae8u,2);
goto P_0c04daa0;
P_0c04daa0: /* original a050, guest PC 0x0c04daa0 */
if(!s->budget--) { s->failed_pc=0x0c04daa0u; return 0; }
goto P_0c04db44;
P_0c04daa2: /* original 0009, guest PC 0x0c04daa2 */
if(!s->budget--) { s->failed_pc=0x0c04daa2u; return 0; }
goto P_0c04daa4;
P_0c04daa4: /* original e401, guest PC 0x0c04daa4 */
if(!s->budget--) { s->failed_pc=0x0c04daa4u; return 0; }
r[4]=0x00000001u;
goto P_0c04daa6;
P_0c04daa6: /* original e202, guest PC 0x0c04daa6 */
if(!s->budget--) { s->failed_pc=0x0c04daa6u; return 0; }
r[2]=0x00000002u;
goto P_0c04daa8;
P_0c04daa8: /* original 6043, guest PC 0x0c04daa8 */
if(!s->budget--) { s->failed_pc=0x0c04daa8u; return 0; }
r[0]=r[4];
goto P_0c04daaa;
P_0c04daaa: /* original 1d42, guest PC 0x0c04daaa */
if(!s->budget--) { s->failed_pc=0x0c04daaau; return 0; }
write(ram,r[13]+8,r[4],4);
goto P_0c04daac;
P_0c04daac: /* original 1d21, guest PC 0x0c04daac */
if(!s->budget--) { s->failed_pc=0x0c04daacu; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c04daae;
P_0c04daae: /* original 1d9b, guest PC 0x0c04daae */
if(!s->budget--) { s->failed_pc=0x0c04daaeu; return 0; }
write(ram,r[13]+44,r[9],4);
goto P_0c04dab0;
P_0c04dab0: /* original d319, guest PC 0x0c04dab0 */
if(!s->budget--) { s->failed_pc=0x0c04dab0u; return 0; }
r[3]=read(ram,0x0c04db18u,4);
goto P_0c04dab2;
P_0c04dab2: /* original 1d3e, guest PC 0x0c04dab2 */
if(!s->budget--) { s->failed_pc=0x0c04dab2u; return 0; }
write(ram,r[13]+56,r[3],4);
goto P_0c04dab4;
P_0c04dab4: /* original 1dbc, guest PC 0x0c04dab4 */
if(!s->budget--) { s->failed_pc=0x0c04dab4u; return 0; }
write(ram,r[13]+48,r[11],4);
goto P_0c04dab6;
P_0c04dab6: /* original 1dea, guest PC 0x0c04dab6 */
if(!s->budget--) { s->failed_pc=0x0c04dab6u; return 0; }
write(ram,r[13]+40,r[14],4);
goto P_0c04dab8;
P_0c04dab8: /* original 81d1, guest PC 0x0c04dab8 */
if(!s->budget--) { s->failed_pc=0x0c04dab8u; return 0; }
write(ram,r[13]+2,r[0],2);
goto P_0c04daba;
P_0c04daba: /* original 60b3, guest PC 0x0c04daba */
if(!s->budget--) { s->failed_pc=0x0c04dabau; return 0; }
r[0]=r[11];
goto P_0c04dabc;
P_0c04dabc: /* original 80d1, guest PC 0x0c04dabc */
if(!s->budget--) { s->failed_pc=0x0c04dabcu; return 0; }
write(ram,r[13]+1,r[0],1);
goto P_0c04dabe;
P_0c04dabe: /* original 53d1, guest PC 0x0c04dabe */
if(!s->budget--) { s->failed_pc=0x0c04dabeu; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c04dac0;
P_0c04dac0: /* original 2f36, guest PC 0x0c04dac0 */
if(!s->budget--) { s->failed_pc=0x0c04dac0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dac2;
P_0c04dac2: /* original d216, guest PC 0x0c04dac2 */
if(!s->budget--) { s->failed_pc=0x0c04dac2u; return 0; }
r[2]=read(ram,0x0c04db1cu,4);
goto P_0c04dac4;
P_0c04dac4: /* original d316, guest PC 0x0c04dac4 */
if(!s->budget--) { s->failed_pc=0x0c04dac4u; return 0; }
r[3]=read(ram,0x0c04db20u,4);
goto P_0c04dac6;
P_0c04dac6: /* original 430b, guest PC 0x0c04dac6 */
if(!s->budget--) { s->failed_pc=0x0c04dac6u; return 0; }
target=r[3];
r[16]=code_base|0x0c04dacau;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dacau) { target=s->pc; goto dispatch; }
goto P_0c04daca;
P_0c04dac8: /* original 2f26, guest PC 0x0c04dac8 */
if(!s->budget--) { s->failed_pc=0x0c04dac8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04daca;
P_0c04daca: /* original 51db, guest PC 0x0c04daca */
if(!s->budget--) { s->failed_pc=0x0c04dacau; return 0; }
r[1]=read(ram,r[13]+44,4);
goto P_0c04dacc;
P_0c04dacc: /* original 2f16, guest PC 0x0c04dacc */
if(!s->budget--) { s->failed_pc=0x0c04daccu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dace;
P_0c04dace: /* original d315, guest PC 0x0c04dace */
if(!s->budget--) { s->failed_pc=0x0c04daceu; return 0; }
r[3]=read(ram,0x0c04db24u,4);
goto P_0c04dad0;
P_0c04dad0: /* original d213, guest PC 0x0c04dad0 */
if(!s->budget--) { s->failed_pc=0x0c04dad0u; return 0; }
r[2]=read(ram,0x0c04db20u,4);
goto P_0c04dad2;
P_0c04dad2: /* original 420b, guest PC 0x0c04dad2 */
if(!s->budget--) { s->failed_pc=0x0c04dad2u; return 0; }
target=r[2];
r[16]=code_base|0x0c04dad6u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dad6u) { target=s->pc; goto dispatch; }
goto P_0c04dad6;
P_0c04dad4: /* original 2f36, guest PC 0x0c04dad4 */
if(!s->budget--) { s->failed_pc=0x0c04dad4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dad6;
P_0c04dad6: /* original 64d3, guest PC 0x0c04dad6 */
if(!s->budget--) { s->failed_pc=0x0c04dad6u; return 0; }
r[4]=r[13];
goto P_0c04dad8;
P_0c04dad8: /* original 7f10, guest PC 0x0c04dad8 */
if(!s->budget--) { s->failed_pc=0x0c04dad8u; return 0; }
r[15]+=0x00000010u;
goto P_0c04dada;
P_0c04dada: /* original a028, guest PC 0x0c04dada */
if(!s->budget--) { s->failed_pc=0x0c04dadau; return 0; }
r[4]+=0x00000010u;
goto P_0c04db2e;
P_0c04dadc: /* original 7410, guest PC 0x0c04dadc */
if(!s->budget--) { s->failed_pc=0x0c04dadcu; return 0; }
r[4]+=0x00000010u;
if(!vf3_matrix_family(0x0c04dadeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04dadeu; return 0; } return 1;
P_0c04db28: /* original 63c4, guest PC 0x0c04db28 */
if(!s->budget--) { s->failed_pc=0x0c04db28u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[12]+=1;
r[3]=tmp;
goto P_0c04db2a;
P_0c04db2a: /* original 2430, guest PC 0x0c04db2a */
if(!s->budget--) { s->failed_pc=0x0c04db2au; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04db2c;
P_0c04db2c: /* original 7401, guest PC 0x0c04db2c */
if(!s->budget--) { s->failed_pc=0x0c04db2cu; return 0; }
r[4]+=0x00000001u;
goto P_0c04db2e;
P_0c04db2e: /* original 62c0, guest PC 0x0c04db2e */
if(!s->budget--) { s->failed_pc=0x0c04db2eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[2]=tmp;
goto P_0c04db30;
P_0c04db30: /* original 2228, guest PC 0x0c04db30 */
if(!s->budget--) { s->failed_pc=0x0c04db30u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04db32;
P_0c04db32: /* original 8bf9, guest PC 0x0c04db32 */
if(!s->budget--) { s->failed_pc=0x0c04db32u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04db28; }
goto P_0c04db34;
P_0c04db34: /* original 24b0, guest PC 0x0c04db34 */
if(!s->budget--) { s->failed_pc=0x0c04db34u; return 0; }
write(ram,r[4],r[11],1);
goto P_0c04db36;
P_0c04db36: /* original 64d3, guest PC 0x0c04db36 */
if(!s->budget--) { s->failed_pc=0x0c04db36u; return 0; }
r[4]=r[13];
goto P_0c04db38;
P_0c04db38: /* original d33a, guest PC 0x0c04db38 */
if(!s->budget--) { s->failed_pc=0x0c04db38u; return 0; }
r[3]=read(ram,0x0c04dc24u,4);
goto P_0c04db3a;
P_0c04db3a: /* original 65f2, guest PC 0x0c04db3a */
if(!s->budget--) { s->failed_pc=0x0c04db3au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04db3c;
P_0c04db3c: /* original 430b, guest PC 0x0c04db3c */
if(!s->budget--) { s->failed_pc=0x0c04db3cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04db40u;
r[4]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04db40u) { target=s->pc; goto dispatch; }
goto P_0c04db40;
P_0c04db3e: /* original 7420, guest PC 0x0c04db3e */
if(!s->budget--) { s->failed_pc=0x0c04db3eu; return 0; }
r[4]+=0x00000020u;
goto P_0c04db40;
P_0c04db40: /* original e000, guest PC 0x0c04db40 */
if(!s->budget--) { s->failed_pc=0x0c04db40u; return 0; }
r[0]=0x00000000u;
goto P_0c04db42;
P_0c04db42: /* original 2ad2, guest PC 0x0c04db42 */
if(!s->budget--) { s->failed_pc=0x0c04db42u; return 0; }
write(ram,r[10],r[13],4);
goto P_0c04db44;
P_0c04db44: /* original 7f38, guest PC 0x0c04db44 */
if(!s->budget--) { s->failed_pc=0x0c04db44u; return 0; }
r[15]+=0x00000038u;
goto P_0c04db46;
P_0c04db46: /* original 4f16, guest PC 0x0c04db46 */
if(!s->budget--) { s->failed_pc=0x0c04db46u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04db48;
P_0c04db48: /* original 4f26, guest PC 0x0c04db48 */
if(!s->budget--) { s->failed_pc=0x0c04db48u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04db4a;
P_0c04db4a: /* original 69f6, guest PC 0x0c04db4a */
if(!s->budget--) { s->failed_pc=0x0c04db4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04db4c;
P_0c04db4c: /* original 6af6, guest PC 0x0c04db4c */
if(!s->budget--) { s->failed_pc=0x0c04db4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04db4e;
P_0c04db4e: /* original 6bf6, guest PC 0x0c04db4e */
if(!s->budget--) { s->failed_pc=0x0c04db4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04db50;
P_0c04db50: /* original 6cf6, guest PC 0x0c04db50 */
if(!s->budget--) { s->failed_pc=0x0c04db50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04db52;
P_0c04db52: /* original 6df6, guest PC 0x0c04db52 */
if(!s->budget--) { s->failed_pc=0x0c04db52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04db54;
P_0c04db54: /* original 000b, guest PC 0x0c04db54 */
if(!s->budget--) { s->failed_pc=0x0c04db54u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04db56: /* original 6ef6, guest PC 0x0c04db56 */
if(!s->budget--) { s->failed_pc=0x0c04db56u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04db58u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
