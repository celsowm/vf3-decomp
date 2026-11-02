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
int vf3_away_batch53_adapter_10(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0917fcu: goto P_0c0917fc;
case 0x0c0917feu: goto P_0c0917fe;
case 0x0c091800u: goto P_0c091800;
case 0x0c091802u: goto P_0c091802;
case 0x0c091804u: goto P_0c091804;
case 0x0c091806u: goto P_0c091806;
case 0x0c091808u: goto P_0c091808;
case 0x0c09180au: goto P_0c09180a;
case 0x0c09180cu: goto P_0c09180c;
case 0x0c09180eu: goto P_0c09180e;
case 0x0c091810u: goto P_0c091810;
case 0x0c091812u: goto P_0c091812;
case 0x0c091814u: goto P_0c091814;
case 0x0c091816u: goto P_0c091816;
case 0x0c091818u: goto P_0c091818;
case 0x0c09181au: goto P_0c09181a;
case 0x0c09181cu: goto P_0c09181c;
case 0x0c09181eu: goto P_0c09181e;
case 0x0c091820u: goto P_0c091820;
case 0x0c091822u: goto P_0c091822;
case 0x0c091824u: goto P_0c091824;
case 0x0c091826u: goto P_0c091826;
case 0x0c091828u: goto P_0c091828;
case 0x0c09182au: goto P_0c09182a;
case 0x0c09182cu: goto P_0c09182c;
case 0x0c09182eu: goto P_0c09182e;
case 0x0c091830u: goto P_0c091830;
case 0x0c091832u: goto P_0c091832;
case 0x0c091834u: goto P_0c091834;
case 0x0c091836u: goto P_0c091836;
case 0x0c091838u: goto P_0c091838;
case 0x0c09183au: goto P_0c09183a;
case 0x0c09183cu: goto P_0c09183c;
case 0x0c09183eu: goto P_0c09183e;
case 0x0c091840u: goto P_0c091840;
case 0x0c091842u: goto P_0c091842;
case 0x0c091844u: goto P_0c091844;
case 0x0c091846u: goto P_0c091846;
case 0x0c091848u: goto P_0c091848;
case 0x0c09184au: goto P_0c09184a;
case 0x0c09184cu: goto P_0c09184c;
case 0x0c09184eu: goto P_0c09184e;
case 0x0c091850u: goto P_0c091850;
case 0x0c091852u: goto P_0c091852;
case 0x0c091854u: goto P_0c091854;
case 0x0c091856u: goto P_0c091856;
case 0x0c091858u: goto P_0c091858;
case 0x0c09185au: goto P_0c09185a;
case 0x0c09185cu: goto P_0c09185c;
case 0x0c09185eu: goto P_0c09185e;
case 0x0c091860u: goto P_0c091860;
case 0x0c091862u: goto P_0c091862;
case 0x0c091864u: goto P_0c091864;
case 0x0c091866u: goto P_0c091866;
case 0x0c091868u: goto P_0c091868;
case 0x0c09186au: goto P_0c09186a;
case 0x0c09186cu: goto P_0c09186c;
case 0x0c09186eu: goto P_0c09186e;
case 0x0c091870u: goto P_0c091870;
case 0x0c091872u: goto P_0c091872;
case 0x0c091874u: goto P_0c091874;
case 0x0c091876u: goto P_0c091876;
case 0x0c091878u: goto P_0c091878;
case 0x0c09187au: goto P_0c09187a;
case 0x0c09187cu: goto P_0c09187c;
case 0x0c09187eu: goto P_0c09187e;
case 0x0c091880u: goto P_0c091880;
case 0x0c091882u: goto P_0c091882;
case 0x0c091884u: goto P_0c091884;
case 0x0c091886u: goto P_0c091886;
case 0x0c091888u: goto P_0c091888;
case 0x0c09188au: goto P_0c09188a;
case 0x0c09188cu: goto P_0c09188c;
case 0x0c09188eu: goto P_0c09188e;
case 0x0c091890u: goto P_0c091890;
case 0x0c091892u: goto P_0c091892;
case 0x0c091894u: goto P_0c091894;
case 0x0c091896u: goto P_0c091896;
case 0x0c091898u: goto P_0c091898;
case 0x0c09189au: goto P_0c09189a;
case 0x0c09189cu: goto P_0c09189c;
case 0x0c09189eu: goto P_0c09189e;
case 0x0c0918a0u: goto P_0c0918a0;
case 0x0c0918a2u: goto P_0c0918a2;
case 0x0c0918a4u: goto P_0c0918a4;
case 0x0c0918a6u: goto P_0c0918a6;
case 0x0c0918a8u: goto P_0c0918a8;
case 0x0c0918aau: goto P_0c0918aa;
case 0x0c0918acu: goto P_0c0918ac;
case 0x0c0918aeu: goto P_0c0918ae;
case 0x0c0918b0u: goto P_0c0918b0;
case 0x0c0918b2u: goto P_0c0918b2;
case 0x0c0918b4u: goto P_0c0918b4;
case 0x0c0918b6u: goto P_0c0918b6;
case 0x0c0918b8u: goto P_0c0918b8;
case 0x0c0918bau: goto P_0c0918ba;
case 0x0c0918bcu: goto P_0c0918bc;
case 0x0c0918beu: goto P_0c0918be;
case 0x0c0918c0u: goto P_0c0918c0;
case 0x0c0918c2u: goto P_0c0918c2;
case 0x0c0918c4u: goto P_0c0918c4;
case 0x0c0918c6u: goto P_0c0918c6;
case 0x0c0918c8u: goto P_0c0918c8;
case 0x0c0918cau: goto P_0c0918ca;
case 0x0c0918ccu: goto P_0c0918cc;
case 0x0c0918ceu: goto P_0c0918ce;
case 0x0c0918d0u: goto P_0c0918d0;
case 0x0c0918d2u: goto P_0c0918d2;
case 0x0c0918d4u: goto P_0c0918d4;
case 0x0c0918d6u: goto P_0c0918d6;
case 0x0c0918d8u: goto P_0c0918d8;
case 0x0c0918dau: goto P_0c0918da;
case 0x0c0918dcu: goto P_0c0918dc;
case 0x0c0918deu: goto P_0c0918de;
case 0x0c0918e0u: goto P_0c0918e0;
case 0x0c0918e2u: goto P_0c0918e2;
case 0x0c0918e4u: goto P_0c0918e4;
case 0x0c0918e6u: goto P_0c0918e6;
case 0x0c0918e8u: goto P_0c0918e8;
case 0x0c0918eau: goto P_0c0918ea;
case 0x0c0918ecu: goto P_0c0918ec;
case 0x0c0918eeu: goto P_0c0918ee;
case 0x0c0918f0u: goto P_0c0918f0;
case 0x0c0918f2u: goto P_0c0918f2;
case 0x0c0918f4u: goto P_0c0918f4;
case 0x0c0918f6u: goto P_0c0918f6;
case 0x0c0918f8u: goto P_0c0918f8;
case 0x0c0918fau: goto P_0c0918fa;
case 0x0c0918fcu: goto P_0c0918fc;
case 0x0c0918feu: goto P_0c0918fe;
case 0x0c091900u: goto P_0c091900;
case 0x0c091902u: goto P_0c091902;
case 0x0c091904u: goto P_0c091904;
case 0x0c091906u: goto P_0c091906;
case 0x0c091908u: goto P_0c091908;
case 0x0c09190au: goto P_0c09190a;
case 0x0c09190cu: goto P_0c09190c;
case 0x0c09190eu: goto P_0c09190e;
case 0x0c091910u: goto P_0c091910;
case 0x0c091912u: goto P_0c091912;
case 0x0c091914u: goto P_0c091914;
case 0x0c091916u: goto P_0c091916;
case 0x0c091918u: goto P_0c091918;
case 0x0c09191au: goto P_0c09191a;
case 0x0c09191cu: goto P_0c09191c;
case 0x0c09191eu: goto P_0c09191e;
case 0x0c091920u: goto P_0c091920;
case 0x0c091922u: goto P_0c091922;
case 0x0c091924u: goto P_0c091924;
case 0x0c091926u: goto P_0c091926;
case 0x0c091928u: goto P_0c091928;
case 0x0c09192au: goto P_0c09192a;
case 0x0c09192cu: goto P_0c09192c;
case 0x0c09192eu: goto P_0c09192e;
case 0x0c091930u: goto P_0c091930;
case 0x0c091932u: goto P_0c091932;
case 0x0c091934u: goto P_0c091934;
case 0x0c091936u: goto P_0c091936;
case 0x0c091938u: goto P_0c091938;
case 0x0c09193au: goto P_0c09193a;
case 0x0c09193cu: goto P_0c09193c;
case 0x0c09193eu: goto P_0c09193e;
case 0x0c091940u: goto P_0c091940;
case 0x0c091942u: goto P_0c091942;
case 0x0c091944u: goto P_0c091944;
case 0x0c091946u: goto P_0c091946;
case 0x0c091948u: goto P_0c091948;
case 0x0c09194au: goto P_0c09194a;
case 0x0c09194cu: goto P_0c09194c;
case 0x0c09194eu: goto P_0c09194e;
case 0x0c091950u: goto P_0c091950;
case 0x0c091952u: goto P_0c091952;
case 0x0c091954u: goto P_0c091954;
case 0x0c091956u: goto P_0c091956;
case 0x0c091958u: goto P_0c091958;
case 0x0c09195au: goto P_0c09195a;
case 0x0c09195cu: goto P_0c09195c;
case 0x0c09195eu: goto P_0c09195e;
case 0x0c091960u: goto P_0c091960;
case 0x0c091962u: goto P_0c091962;
case 0x0c091980u: goto P_0c091980;
case 0x0c091982u: goto P_0c091982;
case 0x0c091984u: goto P_0c091984;
case 0x0c091986u: goto P_0c091986;
case 0x0c091988u: goto P_0c091988;
case 0x0c09198au: goto P_0c09198a;
case 0x0c09198cu: goto P_0c09198c;
case 0x0c09198eu: goto P_0c09198e;
case 0x0c091990u: goto P_0c091990;
case 0x0c091992u: goto P_0c091992;
case 0x0c091994u: goto P_0c091994;
case 0x0c091996u: goto P_0c091996;
case 0x0c091998u: goto P_0c091998;
case 0x0c09199au: goto P_0c09199a;
case 0x0c09199cu: goto P_0c09199c;
case 0x0c09199eu: goto P_0c09199e;
case 0x0c0919a0u: goto P_0c0919a0;
case 0x0c0919a2u: goto P_0c0919a2;
case 0x0c0919a4u: goto P_0c0919a4;
case 0x0c0919a6u: goto P_0c0919a6;
case 0x0c0919a8u: goto P_0c0919a8;
case 0x0c0919aau: goto P_0c0919aa;
case 0x0c0919acu: goto P_0c0919ac;
case 0x0c0919aeu: goto P_0c0919ae;
case 0x0c0919b0u: goto P_0c0919b0;
case 0x0c0919b2u: goto P_0c0919b2;
case 0x0c0919b4u: goto P_0c0919b4;
case 0x0c0919b6u: goto P_0c0919b6;
case 0x0c0919b8u: goto P_0c0919b8;
case 0x0c0919bau: goto P_0c0919ba;
case 0x0c0919bcu: goto P_0c0919bc;
case 0x0c0919beu: goto P_0c0919be;
case 0x0c0919c0u: goto P_0c0919c0;
case 0x0c0919c2u: goto P_0c0919c2;
case 0x0c0919c4u: goto P_0c0919c4;
case 0x0c0919c6u: goto P_0c0919c6;
case 0x0c0919c8u: goto P_0c0919c8;
case 0x0c0919cau: goto P_0c0919ca;
case 0x0c0919ccu: goto P_0c0919cc;
case 0x0c0919ceu: goto P_0c0919ce;
case 0x0c0919d0u: goto P_0c0919d0;
case 0x0c0919d2u: goto P_0c0919d2;
case 0x0c0919d4u: goto P_0c0919d4;
case 0x0c0919d6u: goto P_0c0919d6;
case 0x0c0919d8u: goto P_0c0919d8;
case 0x0c0919dau: goto P_0c0919da;
case 0x0c0919dcu: goto P_0c0919dc;
case 0x0c0919deu: goto P_0c0919de;
case 0x0c0919e0u: goto P_0c0919e0;
case 0x0c0919e2u: goto P_0c0919e2;
case 0x0c0919e4u: goto P_0c0919e4;
case 0x0c0919e6u: goto P_0c0919e6;
case 0x0c0919e8u: goto P_0c0919e8;
case 0x0c0919eau: goto P_0c0919ea;
case 0x0c0919ecu: goto P_0c0919ec;
case 0x0c0919eeu: goto P_0c0919ee;
case 0x0c0919f0u: goto P_0c0919f0;
case 0x0c0919f2u: goto P_0c0919f2;
case 0x0c0919f4u: goto P_0c0919f4;
case 0x0c0919f6u: goto P_0c0919f6;
case 0x0c0919f8u: goto P_0c0919f8;
case 0x0c0919fau: goto P_0c0919fa;
case 0x0c0919fcu: goto P_0c0919fc;
case 0x0c0919feu: goto P_0c0919fe;
case 0x0c091a00u: goto P_0c091a00;
case 0x0c091a02u: goto P_0c091a02;
case 0x0c091a04u: goto P_0c091a04;
case 0x0c091a06u: goto P_0c091a06;
case 0x0c091a08u: goto P_0c091a08;
case 0x0c091a0au: goto P_0c091a0a;
case 0x0c091a0cu: goto P_0c091a0c;
case 0x0c091a0eu: goto P_0c091a0e;
case 0x0c091a10u: goto P_0c091a10;
case 0x0c091a12u: goto P_0c091a12;
case 0x0c091a14u: goto P_0c091a14;
case 0x0c091a16u: goto P_0c091a16;
case 0x0c091a18u: goto P_0c091a18;
case 0x0c091a1au: goto P_0c091a1a;
case 0x0c091a1cu: goto P_0c091a1c;
case 0x0c091a1eu: goto P_0c091a1e;
case 0x0c091a20u: goto P_0c091a20;
case 0x0c091a22u: goto P_0c091a22;
case 0x0c091a24u: goto P_0c091a24;
case 0x0c091a26u: goto P_0c091a26;
case 0x0c091a28u: goto P_0c091a28;
case 0x0c091a2au: goto P_0c091a2a;
case 0x0c091a2cu: goto P_0c091a2c;
case 0x0c091a2eu: goto P_0c091a2e;
case 0x0c091a30u: goto P_0c091a30;
case 0x0c091a32u: goto P_0c091a32;
case 0x0c091a34u: goto P_0c091a34;
case 0x0c091a36u: goto P_0c091a36;
case 0x0c091a38u: goto P_0c091a38;
case 0x0c091a3au: goto P_0c091a3a;
case 0x0c091a3cu: goto P_0c091a3c;
case 0x0c091a3eu: goto P_0c091a3e;
case 0x0c091a40u: goto P_0c091a40;
case 0x0c091a42u: goto P_0c091a42;
case 0x0c091a44u: goto P_0c091a44;
case 0x0c091a46u: goto P_0c091a46;
case 0x0c091a48u: goto P_0c091a48;
case 0x0c091a4au: goto P_0c091a4a;
case 0x0c091a4cu: goto P_0c091a4c;
case 0x0c091a4eu: goto P_0c091a4e;
case 0x0c091a50u: goto P_0c091a50;
case 0x0c091a52u: goto P_0c091a52;
case 0x0c091a54u: goto P_0c091a54;
case 0x0c091a56u: goto P_0c091a56;
case 0x0c091a58u: goto P_0c091a58;
case 0x0c091a5au: goto P_0c091a5a;
case 0x0c091a5cu: goto P_0c091a5c;
case 0x0c091a5eu: goto P_0c091a5e;
case 0x0c091a60u: goto P_0c091a60;
case 0x0c091a62u: goto P_0c091a62;
case 0x0c091a64u: goto P_0c091a64;
case 0x0c091a66u: goto P_0c091a66;
case 0x0c091a68u: goto P_0c091a68;
case 0x0c091a6au: goto P_0c091a6a;
case 0x0c091a6cu: goto P_0c091a6c;
case 0x0c091a6eu: goto P_0c091a6e;
case 0x0c091a70u: goto P_0c091a70;
case 0x0c091a72u: goto P_0c091a72;
case 0x0c091a74u: goto P_0c091a74;
case 0x0c091a76u: goto P_0c091a76;
case 0x0c091a78u: goto P_0c091a78;
case 0x0c091a7au: goto P_0c091a7a;
case 0x0c091a7cu: goto P_0c091a7c;
case 0x0c091a7eu: goto P_0c091a7e;
case 0x0c091a80u: goto P_0c091a80;
case 0x0c091a82u: goto P_0c091a82;
case 0x0c091a84u: goto P_0c091a84;
case 0x0c091a86u: goto P_0c091a86;
case 0x0c091a88u: goto P_0c091a88;
case 0x0c091a8au: goto P_0c091a8a;
case 0x0c091a8cu: goto P_0c091a8c;
case 0x0c091a8eu: goto P_0c091a8e;
case 0x0c091a90u: goto P_0c091a90;
case 0x0c091a92u: goto P_0c091a92;
case 0x0c091a94u: goto P_0c091a94;
case 0x0c091a96u: goto P_0c091a96;
case 0x0c091a98u: goto P_0c091a98;
case 0x0c091a9au: goto P_0c091a9a;
case 0x0c091a9cu: goto P_0c091a9c;
case 0x0c091a9eu: goto P_0c091a9e;
case 0x0c091aa0u: goto P_0c091aa0;
case 0x0c091aa2u: goto P_0c091aa2;
case 0x0c091aa4u: goto P_0c091aa4;
case 0x0c091aa6u: goto P_0c091aa6;
case 0x0c091aa8u: goto P_0c091aa8;
case 0x0c091aaau: goto P_0c091aaa;
case 0x0c091aacu: goto P_0c091aac;
case 0x0c091aaeu: goto P_0c091aae;
case 0x0c091ab0u: goto P_0c091ab0;
case 0x0c091ab2u: goto P_0c091ab2;
case 0x0c091ac8u: goto P_0c091ac8;
case 0x0c091acau: goto P_0c091aca;
case 0x0c091accu: goto P_0c091acc;
case 0x0c091aceu: goto P_0c091ace;
case 0x0c091ad0u: goto P_0c091ad0;
case 0x0c091ad2u: goto P_0c091ad2;
case 0x0c091ad4u: goto P_0c091ad4;
case 0x0c091ad6u: goto P_0c091ad6;
case 0x0c091ad8u: goto P_0c091ad8;
case 0x0c091adau: goto P_0c091ada;
case 0x0c091adcu: goto P_0c091adc;
case 0x0c091adeu: goto P_0c091ade;
case 0x0c091ae0u: goto P_0c091ae0;
case 0x0c091ae2u: goto P_0c091ae2;
case 0x0c091ae4u: goto P_0c091ae4;
case 0x0c091ae6u: goto P_0c091ae6;
case 0x0c091ae8u: goto P_0c091ae8;
case 0x0c091aeau: goto P_0c091aea;
case 0x0c091aecu: goto P_0c091aec;
case 0x0c091aeeu: goto P_0c091aee;
case 0x0c091af0u: goto P_0c091af0;
case 0x0c091af2u: goto P_0c091af2;
case 0x0c091af4u: goto P_0c091af4;
case 0x0c091af6u: goto P_0c091af6;
case 0x0c091af8u: goto P_0c091af8;
case 0x0c091afau: goto P_0c091afa;
case 0x0c091afcu: goto P_0c091afc;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0917fc: /* original 2fe6, guest PC 0x0c0917fc */
if(!s->budget--) { s->failed_pc=0x0c0917fcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0917fe;
P_0c0917fe: /* original d359, guest PC 0x0c0917fe */
if(!s->budget--) { s->failed_pc=0x0c0917feu; return 0; }
r[3]=read(ram,0x0c091964u,4);
goto P_0c091800;
P_0c091800: /* original d659, guest PC 0x0c091800 */
if(!s->budget--) { s->failed_pc=0x0c091800u; return 0; }
r[6]=read(ram,0x0c091968u,4);
goto P_0c091802;
P_0c091802: /* original 6532, guest PC 0x0c091802 */
if(!s->budget--) { s->failed_pc=0x0c091802u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c091804;
P_0c091804: /* original 7514, guest PC 0x0c091804 */
if(!s->budget--) { s->failed_pc=0x0c091804u; return 0; }
r[5]+=0x00000014u;
goto P_0c091806;
P_0c091806: /* original 6052, guest PC 0x0c091806 */
if(!s->budget--) { s->failed_pc=0x0c091806u; return 0; }
tmp=read(ram,r[5],4);
r[0]=tmp;
goto P_0c091808;
P_0c091808: /* original 880c, guest PC 0x0c091808 */
if(!s->budget--) { s->failed_pc=0x0c091808u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c09180a;
P_0c09180a: /* original 8d0d, guest PC 0x0c09180a */
if(!s->budget--) { s->failed_pc=0x0c09180au; return 0; }
cond=r[17]&1u;
r[14]=r[0];
if(cond) { goto P_0c091828; }
goto P_0c09180e;
P_0c09180c: /* original 6e03, guest PC 0x0c09180c */
if(!s->budget--) { s->failed_pc=0x0c09180cu; return 0; }
r[14]=r[0];
goto P_0c09180e;
P_0c09180e: /* original e364, guest PC 0x0c09180e */
if(!s->budget--) { s->failed_pc=0x0c09180eu; return 0; }
r[3]=0x00000064u;
goto P_0c091810;
P_0c091810: /* original 2432, guest PC 0x0c091810 */
if(!s->budget--) { s->failed_pc=0x0c091810u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c091812;
P_0c091812: /* original 63e3, guest PC 0x0c091812 */
if(!s->budget--) { s->failed_pc=0x0c091812u; return 0; }
r[3]=r[14];
goto P_0c091814;
P_0c091814: /* original 6262, guest PC 0x0c091814 */
if(!s->budget--) { s->failed_pc=0x0c091814u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c091816;
P_0c091816: /* original 7301, guest PC 0x0c091816 */
if(!s->budget--) { s->failed_pc=0x0c091816u; return 0; }
r[3]+=0x00000001u;
goto P_0c091818;
P_0c091818: /* original 1428, guest PC 0x0c091818 */
if(!s->budget--) { s->failed_pc=0x0c091818u; return 0; }
write(ram,r[4]+32,r[2],4);
goto P_0c09181a;
P_0c09181a: /* original 62e3, guest PC 0x0c09181a */
if(!s->budget--) { s->failed_pc=0x0c09181au; return 0; }
r[2]=r[14];
goto P_0c09181c;
P_0c09181c: /* original 2532, guest PC 0x0c09181c */
if(!s->budget--) { s->failed_pc=0x0c09181cu; return 0; }
write(ram,r[5],r[3],4);
goto P_0c09181e;
P_0c09181e: /* original 6353, guest PC 0x0c09181e */
if(!s->budget--) { s->failed_pc=0x0c09181eu; return 0; }
r[3]=r[5];
goto P_0c091820;
P_0c091820: /* original 7304, guest PC 0x0c091820 */
if(!s->budget--) { s->failed_pc=0x0c091820u; return 0; }
r[3]+=0x00000004u;
goto P_0c091822;
P_0c091822: /* original 4208, guest PC 0x0c091822 */
if(!s->budget--) { s->failed_pc=0x0c091822u; return 0; }
r[2]<<=2;
goto P_0c091824;
P_0c091824: /* original 323c, guest PC 0x0c091824 */
if(!s->budget--) { s->failed_pc=0x0c091824u; return 0; }
r[2]+=r[3];
goto P_0c091826;
P_0c091826: /* original 2242, guest PC 0x0c091826 */
if(!s->budget--) { s->failed_pc=0x0c091826u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c091828;
P_0c091828: /* original 000b, guest PC 0x0c091828 */
if(!s->budget--) { s->failed_pc=0x0c091828u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09182a: /* original 6ef6, guest PC 0x0c09182a */
if(!s->budget--) { s->failed_pc=0x0c09182au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09182c;
P_0c09182c: /* original 2fe6, guest PC 0x0c09182c */
if(!s->budget--) { s->failed_pc=0x0c09182cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09182e;
P_0c09182e: /* original 6e43, guest PC 0x0c09182e */
if(!s->budget--) { s->failed_pc=0x0c09182eu; return 0; }
r[14]=r[4];
goto P_0c091830;
P_0c091830: /* original 2fd6, guest PC 0x0c091830 */
if(!s->budget--) { s->failed_pc=0x0c091830u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091832;
P_0c091832: /* original e044, guest PC 0x0c091832 */
if(!s->budget--) { s->failed_pc=0x0c091832u; return 0; }
r[0]=0x00000044u;
goto P_0c091834;
P_0c091834: /* original fffb, guest PC 0x0c091834 */
if(!s->budget--) { s->failed_pc=0x0c091834u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c091836;
P_0c091836: /* original ffeb, guest PC 0x0c091836 */
if(!s->budget--) { s->failed_pc=0x0c091836u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c091838;
P_0c091838: /* original dd4c, guest PC 0x0c091838 */
if(!s->budget--) { s->failed_pc=0x0c091838u; return 0; }
r[13]=read(ram,0x0c09196cu,4);
goto P_0c09183a;
P_0c09183a: /* original 4f22, guest PC 0x0c09183a */
if(!s->budget--) { s->failed_pc=0x0c09183au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09183c;
P_0c09183c: /* original 04de, guest PC 0x0c09183c */
if(!s->budget--) { s->failed_pc=0x0c09183cu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c09183e;
P_0c09183e: /* original 60e2, guest PC 0x0c09183e */
if(!s->budget--) { s->failed_pc=0x0c09183eu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c091840;
P_0c091840: /* original 7ff4, guest PC 0x0c091840 */
if(!s->budget--) { s->failed_pc=0x0c091840u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c091842;
P_0c091842: /* original 6543, guest PC 0x0c091842 */
if(!s->budget--) { s->failed_pc=0x0c091842u; return 0; }
r[5]=r[4];
goto P_0c091844;
P_0c091844: /* original 8864, guest PC 0x0c091844 */
if(!s->budget--) { s->failed_pc=0x0c091844u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000064u)!=0);
goto P_0c091846;
P_0c091846: /* original 8d02, guest PC 0x0c091846 */
if(!s->budget--) { s->failed_pc=0x0c091846u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000014u;
if(cond) { goto P_0c09184e; }
goto P_0c09184a;
P_0c091848: /* original 7514, guest PC 0x0c091848 */
if(!s->budget--) { s->failed_pc=0x0c091848u; return 0; }
r[5]+=0x00000014u;
goto P_0c09184a;
P_0c09184a: /* original a082, guest PC 0x0c09184a */
if(!s->budget--) { s->failed_pc=0x0c09184au; return 0; }
goto P_0c091952;
P_0c09184c: /* original 0009, guest PC 0x0c09184c */
if(!s->budget--) { s->failed_pc=0x0c09184cu; return 0; }
goto P_0c09184e;
P_0c09184e: /* original 6452, guest PC 0x0c09184e */
if(!s->budget--) { s->failed_pc=0x0c09184eu; return 0; }
tmp=read(ram,r[5],4);
r[4]=tmp;
goto P_0c091850;
P_0c091850: /* original 4411, guest PC 0x0c091850 */
if(!s->budget--) { s->failed_pc=0x0c091850u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c091852;
P_0c091852: /* original 8b0d, guest PC 0x0c091852 */
if(!s->budget--) { s->failed_pc=0x0c091852u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091870; }
goto P_0c091854;
P_0c091854: /* original e30c, guest PC 0x0c091854 */
if(!s->budget--) { s->failed_pc=0x0c091854u; return 0; }
r[3]=0x0000000cu;
goto P_0c091856;
P_0c091856: /* original 3437, guest PC 0x0c091856 */
if(!s->budget--) { s->failed_pc=0x0c091856u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c091858;
P_0c091858: /* original 890a, guest PC 0x0c091858 */
if(!s->budget--) { s->failed_pc=0x0c091858u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c091870; }
goto P_0c09185a;
P_0c09185a: /* original 7504, guest PC 0x0c09185a */
if(!s->budget--) { s->failed_pc=0x0c09185au; return 0; }
r[5]+=0x00000004u;
goto P_0c09185c;
P_0c09185c: /* original 6643, guest PC 0x0c09185c */
if(!s->budget--) { s->failed_pc=0x0c09185cu; return 0; }
r[6]=r[4];
goto P_0c09185e;
P_0c09185e: /* original 6753, guest PC 0x0c09185e */
if(!s->budget--) { s->failed_pc=0x0c09185eu; return 0; }
r[7]=r[5];
goto P_0c091860;
P_0c091860: /* original 6352, guest PC 0x0c091860 */
if(!s->budget--) { s->failed_pc=0x0c091860u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c091862;
P_0c091862: /* original 6233, guest PC 0x0c091862 */
if(!s->budget--) { s->failed_pc=0x0c091862u; return 0; }
r[2]=r[3];
goto P_0c091864;
P_0c091864: /* original 32e0, guest PC 0x0c091864 */
if(!s->budget--) { s->failed_pc=0x0c091864u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[14])!=0);
goto P_0c091866;
P_0c091866: /* original 1f32, guest PC 0x0c091866 */
if(!s->budget--) { s->failed_pc=0x0c091866u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c091868;
P_0c091868: /* original 8904, guest PC 0x0c091868 */
if(!s->budget--) { s->failed_pc=0x0c091868u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c091874; }
goto P_0c09186a;
P_0c09186a: /* original 4410, guest PC 0x0c09186a */
if(!s->budget--) { s->failed_pc=0x0c09186au; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c09186c;
P_0c09186c: /* original 8ff8, guest PC 0x0c09186c */
if(!s->budget--) { s->failed_pc=0x0c09186cu; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(!cond) { goto P_0c091860; }
goto P_0c091870;
P_0c09186e: /* original 7504, guest PC 0x0c09186e */
if(!s->budget--) { s->failed_pc=0x0c09186eu; return 0; }
r[5]+=0x00000004u;
goto P_0c091870;
P_0c091870: /* original a070, guest PC 0x0c091870 */
if(!s->budget--) { s->failed_pc=0x0c091870u; return 0; }
r[4]=0x00000001u;
goto P_0c091954;
P_0c091872: /* original e401, guest PC 0x0c091872 */
if(!s->budget--) { s->failed_pc=0x0c091872u; return 0; }
r[4]=0x00000001u;
goto P_0c091874;
P_0c091874: /* original e004, guest PC 0x0c091874 */
if(!s->budget--) { s->failed_pc=0x0c091874u; return 0; }
r[0]=0x00000004u;
goto P_0c091876;
P_0c091876: /* original f3e6, guest PC 0x0c091876 */
if(!s->budget--) { s->failed_pc=0x0c091876u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c091878;
P_0c091878: /* original e004, guest PC 0x0c091878 */
if(!s->budget--) { s->failed_pc=0x0c091878u; return 0; }
r[0]=0x00000004u;
goto P_0c09187a;
P_0c09187a: /* original ff37, guest PC 0x0c09187a */
if(!s->budget--) { s->failed_pc=0x0c09187au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09187c;
P_0c09187c: /* original e00c, guest PC 0x0c09187c */
if(!s->budget--) { s->failed_pc=0x0c09187cu; return 0; }
r[0]=0x0000000cu;
goto P_0c09187e;
P_0c09187e: /* original f3e6, guest PC 0x0c09187e */
if(!s->budget--) { s->failed_pc=0x0c09187eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c091880;
P_0c091880: /* original e01c, guest PC 0x0c091880 */
if(!s->budget--) { s->failed_pc=0x0c091880u; return 0; }
r[0]=0x0000001cu;
goto P_0c091882;
P_0c091882: /* original ff3a, guest PC 0x0c091882 */
if(!s->budget--) { s->failed_pc=0x0c091882u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c091884;
P_0c091884: /* original fee6, guest PC 0x0c091884 */
if(!s->budget--) { s->failed_pc=0x0c091884u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c091886;
P_0c091886: /* original 6472, guest PC 0x0c091886 */
if(!s->budget--) { s->failed_pc=0x0c091886u; return 0; }
tmp=read(ram,r[7],4);
r[4]=tmp;
goto P_0c091888;
P_0c091888: /* original 34e0, guest PC 0x0c091888 */
if(!s->budget--) { s->failed_pc=0x0c091888u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[14])!=0);
goto P_0c09188a;
P_0c09188a: /* original 8938, guest PC 0x0c09188a */
if(!s->budget--) { s->failed_pc=0x0c09188au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0918fe; }
goto P_0c09188c;
P_0c09188c: /* original e004, guest PC 0x0c09188c */
if(!s->budget--) { s->failed_pc=0x0c09188cu; return 0; }
r[0]=0x00000004u;
goto P_0c09188e;
P_0c09188e: /* original f546, guest PC 0x0c09188e */
if(!s->budget--) { s->failed_pc=0x0c09188eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c091890;
P_0c091890: /* original e00c, guest PC 0x0c091890 */
if(!s->budget--) { s->failed_pc=0x0c091890u; return 0; }
r[0]=0x0000000cu;
goto P_0c091892;
P_0c091892: /* original f646, guest PC 0x0c091892 */
if(!s->budget--) { s->failed_pc=0x0c091892u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c091894;
P_0c091894: /* original e01c, guest PC 0x0c091894 */
if(!s->budget--) { s->failed_pc=0x0c091894u; return 0; }
r[0]=0x0000001cu;
goto P_0c091896;
P_0c091896: /* original f746, guest PC 0x0c091896 */
if(!s->budget--) { s->failed_pc=0x0c091896u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c091898;
P_0c091898: /* original e004, guest PC 0x0c091898 */
if(!s->budget--) { s->failed_pc=0x0c091898u; return 0; }
r[0]=0x00000004u;
goto P_0c09189a;
P_0c09189a: /* original f3f6, guest PC 0x0c09189a */
if(!s->budget--) { s->failed_pc=0x0c09189au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09189c;
P_0c09189c: /* original f354, guest PC 0x0c09189c */
if(!s->budget--) { s->failed_pc=0x0c09189cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])==as_float(fr[5]))!=0);
goto P_0c09189e;
P_0c09189e: /* original 8b06, guest PC 0x0c09189e */
if(!s->budget--) { s->failed_pc=0x0c09189eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0918ae; }
goto P_0c0918a0;
P_0c0918a0: /* original f3f8, guest PC 0x0c0918a0 */
if(!s->budget--) { s->failed_pc=0x0c0918a0u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0918a2;
P_0c0918a2: /* original f364, guest PC 0x0c0918a2 */
if(!s->budget--) { s->failed_pc=0x0c0918a2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])==as_float(fr[6]))!=0);
goto P_0c0918a4;
P_0c0918a4: /* original 8b03, guest PC 0x0c0918a4 */
if(!s->budget--) { s->failed_pc=0x0c0918a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0918ae; }
goto P_0c0918a6;
P_0c0918a6: /* original c732, guest PC 0x0c0918a6 */
if(!s->budget--) { s->failed_pc=0x0c0918a6u; return 0; }
r[0]=code_base|0x00091970u;
goto P_0c0918a8;
P_0c0918a8: /* original f408, guest PC 0x0c0918a8 */
if(!s->budget--) { s->failed_pc=0x0c0918a8u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0918aa;
P_0c0918aa: /* original f640, guest PC 0x0c0918aa */
if(!s->budget--) { s->failed_pc=0x0c0918aau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'+');
goto P_0c0918ac;
P_0c0918ac: /* original f540, guest PC 0x0c0918ac */
if(!s->budget--) { s->failed_pc=0x0c0918acu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'+');
goto P_0c0918ae;
P_0c0918ae: /* original e004, guest PC 0x0c0918ae */
if(!s->budget--) { s->failed_pc=0x0c0918aeu; return 0; }
r[0]=0x00000004u;
goto P_0c0918b0;
P_0c0918b0: /* original fff8, guest PC 0x0c0918b0 */
if(!s->budget--) { s->failed_pc=0x0c0918b0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
goto P_0c0918b2;
P_0c0918b2: /* original f4f6, guest PC 0x0c0918b2 */
if(!s->budget--) { s->failed_pc=0x0c0918b2u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0918b4;
P_0c0918b4: /* original ff61, guest PC 0x0c0918b4 */
if(!s->budget--) { s->failed_pc=0x0c0918b4u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[6],r[18],'-');
goto P_0c0918b6;
P_0c0918b6: /* original f67c, guest PC 0x0c0918b6 */
if(!s->budget--) { s->failed_pc=0x0c0918b6u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c0918b8;
P_0c0918b8: /* original f451, guest PC 0x0c0918b8 */
if(!s->budget--) { s->failed_pc=0x0c0918b8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c0918ba;
P_0c0918ba: /* original f672, guest PC 0x0c0918ba */
if(!s->budget--) { s->failed_pc=0x0c0918bau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c0918bc;
P_0c0918bc: /* original f0fc, guest PC 0x0c0918bc */
if(!s->budget--) { s->failed_pc=0x0c0918bcu; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c0918be;
P_0c0918be: /* original f34c, guest PC 0x0c0918be */
if(!s->budget--) { s->failed_pc=0x0c0918beu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0918c0;
P_0c0918c0: /* original f432, guest PC 0x0c0918c0 */
if(!s->budget--) { s->failed_pc=0x0c0918c0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0918c2;
P_0c0918c2: /* original f36c, guest PC 0x0c0918c2 */
if(!s->budget--) { s->failed_pc=0x0c0918c2u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c0918c4;
P_0c0918c4: /* original f24c, guest PC 0x0c0918c4 */
if(!s->budget--) { s->failed_pc=0x0c0918c4u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0918c6;
P_0c0918c6: /* original f2fe, guest PC 0x0c0918c6 */
if(!s->budget--) { s->failed_pc=0x0c0918c6u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[15],fr[2],r[18]);
goto P_0c0918c8;
P_0c0918c8: /* original f0ec, guest PC 0x0c0918c8 */
if(!s->budget--) { s->failed_pc=0x0c0918c8u; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c0918ca;
P_0c0918ca: /* original f3ee, guest PC 0x0c0918ca */
if(!s->budget--) { s->failed_pc=0x0c0918cau; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[14],fr[3],r[18]);
goto P_0c0918cc;
P_0c0918cc: /* original f42c, guest PC 0x0c0918cc */
if(!s->budget--) { s->failed_pc=0x0c0918ccu; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c0918ce;
P_0c0918ce: /* original f63c, guest PC 0x0c0918ce */
if(!s->budget--) { s->failed_pc=0x0c0918ceu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c0918d0;
P_0c0918d0: /* original f465, guest PC 0x0c0918d0 */
if(!s->budget--) { s->failed_pc=0x0c0918d0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c0918d2;
P_0c0918d2: /* original 8914, guest PC 0x0c0918d2 */
if(!s->budget--) { s->failed_pc=0x0c0918d2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0918fe; }
goto P_0c0918d4;
P_0c0918d4: /* original c727, guest PC 0x0c0918d4 */
if(!s->budget--) { s->failed_pc=0x0c0918d4u; return 0; }
r[0]=code_base|0x00091974u;
goto P_0c0918d6;
P_0c0918d6: /* original f308, guest PC 0x0c0918d6 */
if(!s->budget--) { s->failed_pc=0x0c0918d6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0918d8;
P_0c0918d8: /* original f345, guest PC 0x0c0918d8 */
if(!s->budget--) { s->failed_pc=0x0c0918d8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0918da;
P_0c0918da: /* original 8f02, guest PC 0x0c0918da */
if(!s->budget--) { s->failed_pc=0x0c0918dau; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,6,15);
if(!cond) { goto P_0c0918e2; }
goto P_0c0918de;
P_0c0918dc: /* original f6fc, guest PC 0x0c0918dc */
if(!s->budget--) { s->failed_pc=0x0c0918dcu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0918de;
P_0c0918de: /* original a001, guest PC 0x0c0918de */
if(!s->budget--) { s->failed_pc=0x0c0918deu; return 0; }
fr[4]=0;
goto P_0c0918e4;
P_0c0918e0: /* original f48d, guest PC 0x0c0918e0 */
if(!s->budget--) { s->failed_pc=0x0c0918e0u; return 0; }
fr[4]=0;
goto P_0c0918e2;
P_0c0918e2: /* original f47d, guest PC 0x0c0918e2 */
if(!s->budget--) { s->failed_pc=0x0c0918e2u; return 0; }
if(!vf3_fpu_fsrra(fr[4],r[18],&fr[4])) goto unsupported;
goto P_0c0918e4;
P_0c0918e4: /* original c724, guest PC 0x0c0918e4 */
if(!s->budget--) { s->failed_pc=0x0c0918e4u; return 0; }
r[0]=code_base|0x00091978u;
goto P_0c0918e6;
P_0c0918e6: /* original f642, guest PC 0x0c0918e6 */
if(!s->budget--) { s->failed_pc=0x0c0918e6u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c0918e8;
P_0c0918e8: /* original f542, guest PC 0x0c0918e8 */
if(!s->budget--) { s->failed_pc=0x0c0918e8u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c0918ea;
P_0c0918ea: /* original f408, guest PC 0x0c0918ea */
if(!s->budget--) { s->failed_pc=0x0c0918eau; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0918ec;
P_0c0918ec: /* original e004, guest PC 0x0c0918ec */
if(!s->budget--) { s->failed_pc=0x0c0918ecu; return 0; }
r[0]=0x00000004u;
goto P_0c0918ee;
P_0c0918ee: /* original f3f6, guest PC 0x0c0918ee */
if(!s->budget--) { s->failed_pc=0x0c0918eeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0918f0;
P_0c0918f0: /* original e004, guest PC 0x0c0918f0 */
if(!s->budget--) { s->failed_pc=0x0c0918f0u; return 0; }
r[0]=0x00000004u;
goto P_0c0918f2;
P_0c0918f2: /* original f04c, guest PC 0x0c0918f2 */
if(!s->budget--) { s->failed_pc=0x0c0918f2u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0918f4;
P_0c0918f4: /* original f35e, guest PC 0x0c0918f4 */
if(!s->budget--) { s->failed_pc=0x0c0918f4u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c0918f6;
P_0c0918f6: /* original ff37, guest PC 0x0c0918f6 */
if(!s->budget--) { s->failed_pc=0x0c0918f6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0918f8;
P_0c0918f8: /* original f2f8, guest PC 0x0c0918f8 */
if(!s->budget--) { s->failed_pc=0x0c0918f8u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0918fa;
P_0c0918fa: /* original f26e, guest PC 0x0c0918fa */
if(!s->budget--) { s->failed_pc=0x0c0918fau; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[6],fr[2],r[18]);
goto P_0c0918fc;
P_0c0918fc: /* original ff2a, guest PC 0x0c0918fc */
if(!s->budget--) { s->failed_pc=0x0c0918fcu; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c0918fe;
P_0c0918fe: /* original 4610, guest PC 0x0c0918fe */
if(!s->budget--) { s->failed_pc=0x0c0918feu; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c091900;
P_0c091900: /* original 8fc1, guest PC 0x0c091900 */
if(!s->budget--) { s->failed_pc=0x0c091900u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000004u;
if(!cond) { goto P_0c091886; }
goto P_0c091904;
P_0c091902: /* original 7704, guest PC 0x0c091902 */
if(!s->budget--) { s->failed_pc=0x0c091902u; return 0; }
r[7]+=0x00000004u;
goto P_0c091904;
P_0c091904: /* original e008, guest PC 0x0c091904 */
if(!s->budget--) { s->failed_pc=0x0c091904u; return 0; }
r[0]=0x00000008u;
goto P_0c091906;
P_0c091906: /* original 54d4, guest PC 0x0c091906 */
if(!s->budget--) { s->failed_pc=0x0c091906u; return 0; }
r[4]=read(ram,r[13]+16,4);
goto P_0c091908;
P_0c091908: /* original ffe6, guest PC 0x0c091908 */
if(!s->budget--) { s->failed_pc=0x0c091908u; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c09190a;
P_0c09190a: /* original e014, guest PC 0x0c09190a */
if(!s->budget--) { s->failed_pc=0x0c09190au; return 0; }
r[0]=0x00000014u;
goto P_0c09190c;
P_0c09190c: /* original f4e6, guest PC 0x0c09190c */
if(!s->budget--) { s->failed_pc=0x0c09190cu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c09190e;
P_0c09190e: /* original 65f3, guest PC 0x0c09190e */
if(!s->budget--) { s->failed_pc=0x0c09190eu; return 0; }
r[5]=r[15];
goto P_0c091910;
P_0c091910: /* original f5ec, guest PC 0x0c091910 */
if(!s->budget--) { s->failed_pc=0x0c091910u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c091912;
P_0c091912: /* original 66f3, guest PC 0x0c091912 */
if(!s->budget--) { s->failed_pc=0x0c091912u; return 0; }
r[6]=r[15];
goto P_0c091914;
P_0c091914: /* original ff41, guest PC 0x0c091914 */
if(!s->budget--) { s->failed_pc=0x0c091914u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'-');
goto P_0c091916;
P_0c091916: /* original ff41, guest PC 0x0c091916 */
if(!s->budget--) { s->failed_pc=0x0c091916u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'-');
goto P_0c091918;
P_0c091918: /* original f4fc, guest PC 0x0c091918 */
if(!s->budget--) { s->failed_pc=0x0c091918u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09191a;
P_0c09191a: /* original b031, guest PC 0x0c09191a */
if(!s->budget--) { s->failed_pc=0x0c09191au; return 0; }
target=code_base|0x0c091980u; r[16]=code_base|0x0c09191eu;
r[5]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09191eu) { target=s->pc; goto dispatch; }
goto P_0c09191e;
P_0c09191c: /* original 7504, guest PC 0x0c09191c */
if(!s->budget--) { s->failed_pc=0x0c09191cu; return 0; }
r[5]+=0x00000004u;
goto P_0c09191e;
P_0c09191e: /* original 54d5, guest PC 0x0c09191e */
if(!s->budget--) { s->failed_pc=0x0c09191eu; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c091920;
P_0c091920: /* original 65f3, guest PC 0x0c091920 */
if(!s->budget--) { s->failed_pc=0x0c091920u; return 0; }
r[5]=r[15];
goto P_0c091922;
P_0c091922: /* original f4fc, guest PC 0x0c091922 */
if(!s->budget--) { s->failed_pc=0x0c091922u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c091924;
P_0c091924: /* original 66f3, guest PC 0x0c091924 */
if(!s->budget--) { s->failed_pc=0x0c091924u; return 0; }
r[6]=r[15];
goto P_0c091926;
P_0c091926: /* original f5ec, guest PC 0x0c091926 */
if(!s->budget--) { s->failed_pc=0x0c091926u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c091928;
P_0c091928: /* original b02a, guest PC 0x0c091928 */
if(!s->budget--) { s->failed_pc=0x0c091928u; return 0; }
target=code_base|0x0c091980u; r[16]=code_base|0x0c09192cu;
r[5]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09192cu) { target=s->pc; goto dispatch; }
goto P_0c09192c;
P_0c09192a: /* original 7504, guest PC 0x0c09192a */
if(!s->budget--) { s->failed_pc=0x0c09192au; return 0; }
r[5]+=0x00000004u;
goto P_0c09192c;
P_0c09192c: /* original f5f8, guest PC 0x0c09192c */
if(!s->budget--) { s->failed_pc=0x0c09192cu; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c09192e;
P_0c09192e: /* original e004, guest PC 0x0c09192e */
if(!s->budget--) { s->failed_pc=0x0c09192eu; return 0; }
r[0]=0x00000004u;
goto P_0c091930;
P_0c091930: /* original d312, guest PC 0x0c091930 */
if(!s->budget--) { s->failed_pc=0x0c091930u; return 0; }
r[3]=read(ram,0x0c09197cu,4);
goto P_0c091932;
P_0c091932: /* original f54d, guest PC 0x0c091932 */
if(!s->budget--) { s->failed_pc=0x0c091932u; return 0; }
fr[5]^=0x80000000u;
goto P_0c091934;
P_0c091934: /* original 430b, guest PC 0x0c091934 */
if(!s->budget--) { s->failed_pc=0x0c091934u; return 0; }
target=r[3];
r[16]=code_base|0x0c091938u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091938u) { target=s->pc; goto dispatch; }
goto P_0c091938;
P_0c091936: /* original f4f6, guest PC 0x0c091936 */
if(!s->budget--) { s->failed_pc=0x0c091936u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c091938;
P_0c091938: /* original e014, guest PC 0x0c091938 */
if(!s->budget--) { s->failed_pc=0x0c091938u; return 0; }
r[0]=0x00000014u;
goto P_0c09193a;
P_0c09193a: /* original f40c, guest PC 0x0c09193a */
if(!s->budget--) { s->failed_pc=0x0c09193au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c09193c;
P_0c09193c: /* original f5e6, guest PC 0x0c09193c */
if(!s->budget--) { s->failed_pc=0x0c09193cu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c09193e;
P_0c09193e: /* original e004, guest PC 0x0c09193e */
if(!s->budget--) { s->failed_pc=0x0c09193eu; return 0; }
r[0]=0x00000004u;
goto P_0c091940;
P_0c091940: /* original f3f6, guest PC 0x0c091940 */
if(!s->budget--) { s->failed_pc=0x0c091940u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c091942;
P_0c091942: /* original e004, guest PC 0x0c091942 */
if(!s->budget--) { s->failed_pc=0x0c091942u; return 0; }
r[0]=0x00000004u;
goto P_0c091944;
P_0c091944: /* original f451, guest PC 0x0c091944 */
if(!s->budget--) { s->failed_pc=0x0c091944u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c091946;
P_0c091946: /* original fe37, guest PC 0x0c091946 */
if(!s->budget--) { s->failed_pc=0x0c091946u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c091948;
P_0c091948: /* original e008, guest PC 0x0c091948 */
if(!s->budget--) { s->failed_pc=0x0c091948u; return 0; }
r[0]=0x00000008u;
goto P_0c09194a;
P_0c09194a: /* original fe47, guest PC 0x0c09194a */
if(!s->budget--) { s->failed_pc=0x0c09194au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c09194c;
P_0c09194c: /* original e00c, guest PC 0x0c09194c */
if(!s->budget--) { s->failed_pc=0x0c09194cu; return 0; }
r[0]=0x0000000cu;
goto P_0c09194e;
P_0c09194e: /* original f3f8, guest PC 0x0c09194e */
if(!s->budget--) { s->failed_pc=0x0c09194eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c091950;
P_0c091950: /* original fe37, guest PC 0x0c091950 */
if(!s->budget--) { s->failed_pc=0x0c091950u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c091952;
P_0c091952: /* original e400, guest PC 0x0c091952 */
if(!s->budget--) { s->failed_pc=0x0c091952u; return 0; }
r[4]=0x00000000u;
goto P_0c091954;
P_0c091954: /* original 7f0c, guest PC 0x0c091954 */
if(!s->budget--) { s->failed_pc=0x0c091954u; return 0; }
r[15]+=0x0000000cu;
goto P_0c091956;
P_0c091956: /* original 6043, guest PC 0x0c091956 */
if(!s->budget--) { s->failed_pc=0x0c091956u; return 0; }
r[0]=r[4];
goto P_0c091958;
P_0c091958: /* original 4f26, guest PC 0x0c091958 */
if(!s->budget--) { s->failed_pc=0x0c091958u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09195a;
P_0c09195a: /* original fef9, guest PC 0x0c09195a */
if(!s->budget--) { s->failed_pc=0x0c09195au; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09195c;
P_0c09195c: /* original fff9, guest PC 0x0c09195c */
if(!s->budget--) { s->failed_pc=0x0c09195cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09195e;
P_0c09195e: /* original 6df6, guest PC 0x0c09195e */
if(!s->budget--) { s->failed_pc=0x0c09195eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c091960;
P_0c091960: /* original 000b, guest PC 0x0c091960 */
if(!s->budget--) { s->failed_pc=0x0c091960u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c091962: /* original 6ef6, guest PC 0x0c091962 */
if(!s->budget--) { s->failed_pc=0x0c091962u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c091964u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c091964u; return 0; } return 1;
P_0c091980: /* original 2fd6, guest PC 0x0c091980 */
if(!s->budget--) { s->failed_pc=0x0c091980u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091982;
P_0c091982: /* original e700, guest PC 0x0c091982 */
if(!s->budget--) { s->failed_pc=0x0c091982u; return 0; }
r[7]=0x00000000u;
goto P_0c091984;
P_0c091984: /* original 2fc6, guest PC 0x0c091984 */
if(!s->budget--) { s->failed_pc=0x0c091984u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091986;
P_0c091986: /* original ec1c, guest PC 0x0c091986 */
if(!s->budget--) { s->failed_pc=0x0c091986u; return 0; }
r[12]=0x0000001cu;
goto P_0c091988;
P_0c091988: /* original 2fb6, guest PC 0x0c091988 */
if(!s->budget--) { s->failed_pc=0x0c091988u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09198a;
P_0c09198a: /* original 6b73, guest PC 0x0c09198a */
if(!s->budget--) { s->failed_pc=0x0c09198au; return 0; }
r[11]=r[7];
goto P_0c09198c;
P_0c09198c: /* original fffb, guest PC 0x0c09198c */
if(!s->budget--) { s->failed_pc=0x0c09198cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09198e;
P_0c09198e: /* original 6dc3, guest PC 0x0c09198e */
if(!s->budget--) { s->failed_pc=0x0c09198eu; return 0; }
r[13]=r[12];
goto P_0c091990;
P_0c091990: /* original 9090, guest PC 0x0c091990 */
if(!s->budget--) { s->failed_pc=0x0c091990u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091ab4u,2);
goto P_0c091992;
P_0c091992: /* original 7ffc, guest PC 0x0c091992 */
if(!s->budget--) { s->failed_pc=0x0c091992u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c091994;
P_0c091994: /* original f868, guest PC 0x0c091994 */
if(!s->budget--) { s->failed_pc=0x0c091994u; return 0; }
vf3_matrix_load(s,ram,8,r[6]);
goto P_0c091996;
P_0c091996: /* original 014e, guest PC 0x0c091996 */
if(!s->budget--) { s->failed_pc=0x0c091996u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c091998;
P_0c091998: /* original c747, guest PC 0x0c091998 */
if(!s->budget--) { s->failed_pc=0x0c091998u; return 0; }
r[0]=code_base|0x00091ab8u;
goto P_0c09199a;
P_0c09199a: /* original fa08, guest PC 0x0c09199a */
if(!s->budget--) { s->failed_pc=0x0c09199au; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c09199c;
P_0c09199c: /* original f758, guest PC 0x0c09199c */
if(!s->budget--) { s->failed_pc=0x0c09199cu; return 0; }
vf3_matrix_load(s,ram,7,r[5]);
goto P_0c09199e;
P_0c09199e: /* original e004, guest PC 0x0c09199e */
if(!s->budget--) { s->failed_pc=0x0c09199eu; return 0; }
r[0]=0x00000004u;
goto P_0c0919a0;
P_0c0919a0: /* original f618, guest PC 0x0c0919a0 */
if(!s->budget--) { s->failed_pc=0x0c0919a0u; return 0; }
vf3_matrix_load(s,ram,6,r[1]);
goto P_0c0919a2;
P_0c0919a2: /* original f916, guest PC 0x0c0919a2 */
if(!s->budget--) { s->failed_pc=0x0c0919a2u; return 0; }
vf3_matrix_load(s,ram,9,r[1]+r[0]);
goto P_0c0919a4;
P_0c0919a4: /* original e008, guest PC 0x0c0919a4 */
if(!s->budget--) { s->failed_pc=0x0c0919a4u; return 0; }
r[0]=0x00000008u;
goto P_0c0919a6;
P_0c0919a6: /* original f945, guest PC 0x0c0919a6 */
if(!s->budget--) { s->failed_pc=0x0c0919a6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[4]))!=0);
goto P_0c0919a8;
P_0c0919a8: /* original 8d17, guest PC 0x0c0919a8 */
if(!s->budget--) { s->failed_pc=0x0c0919a8u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,11,r[1]+r[0]);
if(cond) { goto P_0c0919da; }
goto P_0c0919ac;
P_0c0919aa: /* original fb16, guest PC 0x0c0919aa */
if(!s->budget--) { s->failed_pc=0x0c0919aau; return 0; }
vf3_matrix_load(s,ram,11,r[1]+r[0]);
goto P_0c0919ac;
P_0c0919ac: /* original f36c, guest PC 0x0c0919ac */
if(!s->budget--) { s->failed_pc=0x0c0919acu; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c0919ae;
P_0c0919ae: /* original f67c, guest PC 0x0c0919ae */
if(!s->budget--) { s->failed_pc=0x0c0919aeu; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c0919b0;
P_0c0919b0: /* original f631, guest PC 0x0c0919b0 */
if(!s->budget--) { s->failed_pc=0x0c0919b0u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c0919b2;
P_0c0919b2: /* original f39c, guest PC 0x0c0919b2 */
if(!s->budget--) { s->failed_pc=0x0c0919b2u; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c0919b4;
P_0c0919b4: /* original f94c, guest PC 0x0c0919b4 */
if(!s->budget--) { s->failed_pc=0x0c0919b4u; return 0; }
vf3_matrix_move(s,9,4);
goto P_0c0919b6;
P_0c0919b6: /* original f931, guest PC 0x0c0919b6 */
if(!s->budget--) { s->failed_pc=0x0c0919b6u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'-');
goto P_0c0919b8;
P_0c0919b8: /* original f3bc, guest PC 0x0c0919b8 */
if(!s->budget--) { s->failed_pc=0x0c0919b8u; return 0; }
vf3_matrix_move(s,3,11);
goto P_0c0919ba;
P_0c0919ba: /* original fb8c, guest PC 0x0c0919ba */
if(!s->budget--) { s->failed_pc=0x0c0919bau; return 0; }
vf3_matrix_move(s,11,8);
goto P_0c0919bc;
P_0c0919bc: /* original fb31, guest PC 0x0c0919bc */
if(!s->budget--) { s->failed_pc=0x0c0919bcu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[3],r[18],'-');
goto P_0c0919be;
P_0c0919be: /* original f36c, guest PC 0x0c0919be */
if(!s->budget--) { s->failed_pc=0x0c0919beu; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c0919c0;
P_0c0919c0: /* original f632, guest PC 0x0c0919c0 */
if(!s->budget--) { s->failed_pc=0x0c0919c0u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c0919c2;
P_0c0919c2: /* original f09c, guest PC 0x0c0919c2 */
if(!s->budget--) { s->failed_pc=0x0c0919c2u; return 0; }
vf3_matrix_move(s,0,9);
goto P_0c0919c4;
P_0c0919c4: /* original f26c, guest PC 0x0c0919c4 */
if(!s->budget--) { s->failed_pc=0x0c0919c4u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c0919c6;
P_0c0919c6: /* original f29e, guest PC 0x0c0919c6 */
if(!s->budget--) { s->failed_pc=0x0c0919c6u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[9],fr[2],r[18]);
goto P_0c0919c8;
P_0c0919c8: /* original f0bc, guest PC 0x0c0919c8 */
if(!s->budget--) { s->failed_pc=0x0c0919c8u; return 0; }
vf3_matrix_move(s,0,11);
goto P_0c0919ca;
P_0c0919ca: /* original f32c, guest PC 0x0c0919ca */
if(!s->budget--) { s->failed_pc=0x0c0919cau; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c0919cc;
P_0c0919cc: /* original f3be, guest PC 0x0c0919cc */
if(!s->budget--) { s->failed_pc=0x0c0919ccu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[11],fr[3],r[18]);
goto P_0c0919ce;
P_0c0919ce: /* original f63c, guest PC 0x0c0919ce */
if(!s->budget--) { s->failed_pc=0x0c0919ceu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c0919d0;
P_0c0919d0: /* original fa65, guest PC 0x0c0919d0 */
if(!s->budget--) { s->failed_pc=0x0c0919d0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[6]))!=0);
goto P_0c0919d2;
P_0c0919d2: /* original 8b02, guest PC 0x0c0919d2 */
if(!s->budget--) { s->failed_pc=0x0c0919d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0919da; }
goto P_0c0919d4;
P_0c0919d4: /* original 6db3, guest PC 0x0c0919d4 */
if(!s->budget--) { s->failed_pc=0x0c0919d4u; return 0; }
r[13]=r[11];
goto P_0c0919d6;
P_0c0919d6: /* original 6713, guest PC 0x0c0919d6 */
if(!s->budget--) { s->failed_pc=0x0c0919d6u; return 0; }
r[7]=r[1];
goto P_0c0919d8;
P_0c0919d8: /* original fa6c, guest PC 0x0c0919d8 */
if(!s->budget--) { s->failed_pc=0x0c0919d8u; return 0; }
vf3_matrix_move(s,10,6);
goto P_0c0919da;
P_0c0919da: /* original 7cff, guest PC 0x0c0919da */
if(!s->budget--) { s->failed_pc=0x0c0919dau; return 0; }
r[12]+=0xffffffffu;
goto P_0c0919dc;
P_0c0919dc: /* original 60c3, guest PC 0x0c0919dc */
if(!s->budget--) { s->failed_pc=0x0c0919dcu; return 0; }
r[0]=r[12];
goto P_0c0919de;
P_0c0919de: /* original 88ff, guest PC 0x0c0919de */
if(!s->budget--) { s->failed_pc=0x0c0919deu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0919e0;
P_0c0919e0: /* original 710c, guest PC 0x0c0919e0 */
if(!s->budget--) { s->failed_pc=0x0c0919e0u; return 0; }
r[1]+=0x0000000cu;
goto P_0c0919e2;
P_0c0919e2: /* original 8fdc, guest PC 0x0c0919e2 */
if(!s->budget--) { s->failed_pc=0x0c0919e2u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000001u;
if(!cond) { goto P_0c09199e; }
goto P_0c0919e6;
P_0c0919e4: /* original 7b01, guest PC 0x0c0919e4 */
if(!s->budget--) { s->failed_pc=0x0c0919e4u; return 0; }
r[11]+=0x00000001u;
goto P_0c0919e6;
P_0c0919e6: /* original 2778, guest PC 0x0c0919e6 */
if(!s->budget--) { s->failed_pc=0x0c0919e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0919e8;
P_0c0919e8: /* original 8b01, guest PC 0x0c0919e8 */
if(!s->budget--) { s->failed_pc=0x0c0919e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0919ee; }
goto P_0c0919ea;
P_0c0919ea: /* original a080, guest PC 0x0c0919ea */
if(!s->budget--) { s->failed_pc=0x0c0919eau; return 0; }
goto P_0c091aee;
P_0c0919ec: /* original 0009, guest PC 0x0c0919ec */
if(!s->budget--) { s->failed_pc=0x0c0919ecu; return 0; }
goto P_0c0919ee;
P_0c0919ee: /* original 9262, guest PC 0x0c0919ee */
if(!s->budget--) { s->failed_pc=0x0c0919eeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091ab6u,2);
goto P_0c0919f0;
P_0c0919f0: /* original 63d3, guest PC 0x0c0919f0 */
if(!s->budget--) { s->failed_pc=0x0c0919f0u; return 0; }
r[3]=r[13];
goto P_0c0919f2;
P_0c0919f2: /* original f35c, guest PC 0x0c0919f2 */
if(!s->budget--) { s->failed_pc=0x0c0919f2u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0919f4;
P_0c0919f4: /* original 4308, guest PC 0x0c0919f4 */
if(!s->budget--) { s->failed_pc=0x0c0919f4u; return 0; }
r[3]<<=2;
goto P_0c0919f6;
P_0c0919f6: /* original 324c, guest PC 0x0c0919f6 */
if(!s->budget--) { s->failed_pc=0x0c0919f6u; return 0; }
r[2]+=r[4];
goto P_0c0919f8;
P_0c0919f8: /* original f532, guest PC 0x0c0919f8 */
if(!s->budget--) { s->failed_pc=0x0c0919f8u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0919fa;
P_0c0919fa: /* original 332c, guest PC 0x0c0919fa */
if(!s->budget--) { s->failed_pc=0x0c0919fau; return 0; }
r[3]+=r[2];
goto P_0c0919fc;
P_0c0919fc: /* original f438, guest PC 0x0c0919fc */
if(!s->budget--) { s->failed_pc=0x0c0919fcu; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c0919fe;
P_0c0919fe: /* original f04c, guest PC 0x0c0919fe */
if(!s->budget--) { s->failed_pc=0x0c0919feu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c091a00;
P_0c091a00: /* original f54e, guest PC 0x0c091a00 */
if(!s->budget--) { s->failed_pc=0x0c091a00u; return 0; }
fr[5]=vf3_fpu_mac(fr[0],fr[4],fr[5],r[18]);
goto P_0c091a02;
P_0c091a02: /* original f95c, guest PC 0x0c091a02 */
if(!s->budget--) { s->failed_pc=0x0c091a02u; return 0; }
vf3_matrix_move(s,9,5);
goto P_0c091a04;
P_0c091a04: /* original fa95, guest PC 0x0c091a04 */
if(!s->budget--) { s->failed_pc=0x0c091a04u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[9]))!=0);
goto P_0c091a06;
P_0c091a06: /* original 8972, guest PC 0x0c091a06 */
if(!s->budget--) { s->failed_pc=0x0c091a06u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c091aee; }
goto P_0c091a08;
P_0c091a08: /* original e008, guest PC 0x0c091a08 */
if(!s->budget--) { s->failed_pc=0x0c091a08u; return 0; }
r[0]=0x00000008u;
goto P_0c091a0a;
P_0c091a0a: /* original f9a1, guest PC 0x0c091a0a */
if(!s->budget--) { s->failed_pc=0x0c091a0au; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[10],r[18],'-');
goto P_0c091a0c;
P_0c091a0c: /* original f676, guest PC 0x0c091a0c */
if(!s->budget--) { s->failed_pc=0x0c091a0cu; return 0; }
vf3_matrix_load(s,ram,6,r[7]+r[0]);
goto P_0c091a0e;
P_0c091a0e: /* original d02b, guest PC 0x0c091a0e */
if(!s->budget--) { s->failed_pc=0x0c091a0eu; return 0; }
r[0]=read(ram,0x0c091abcu,4);
goto P_0c091a10;
P_0c091a10: /* original f578, guest PC 0x0c091a10 */
if(!s->budget--) { s->failed_pc=0x0c091a10u; return 0; }
vf3_matrix_load(s,ram,5,r[7]);
goto P_0c091a12;
P_0c091a12: /* original 03dc, guest PC 0x0c091a12 */
if(!s->budget--) { s->failed_pc=0x0c091a12u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c091a14;
P_0c091a14: /* original 2f32, guest PC 0x0c091a14 */
if(!s->budget--) { s->failed_pc=0x0c091a14u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c091a16;
P_0c091a16: /* original 904d, guest PC 0x0c091a16 */
if(!s->budget--) { s->failed_pc=0x0c091a16u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091ab4u,2);
goto P_0c091a18;
P_0c091a18: /* original 044e, guest PC 0x0c091a18 */
if(!s->budget--) { s->failed_pc=0x0c091a18u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c091a1a;
P_0c091a1a: /* original 6033, guest PC 0x0c091a1a */
if(!s->budget--) { s->failed_pc=0x0c091a1au; return 0; }
r[0]=r[3];
goto P_0c091a1c;
P_0c091a1c: /* original 4000, guest PC 0x0c091a1c */
if(!s->budget--) { s->failed_pc=0x0c091a1cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c091a1e;
P_0c091a1e: /* original 303c, guest PC 0x0c091a1e */
if(!s->budget--) { s->failed_pc=0x0c091a1eu; return 0; }
r[0]+=r[3];
goto P_0c091a20;
P_0c091a20: /* original 4008, guest PC 0x0c091a20 */
if(!s->budget--) { s->failed_pc=0x0c091a20u; return 0; }
r[0]<<=2;
goto P_0c091a22;
P_0c091a22: /* original 340c, guest PC 0x0c091a22 */
if(!s->budget--) { s->failed_pc=0x0c091a22u; return 0; }
r[4]+=r[0];
goto P_0c091a24;
P_0c091a24: /* original e008, guest PC 0x0c091a24 */
if(!s->budget--) { s->failed_pc=0x0c091a24u; return 0; }
r[0]=0x00000008u;
goto P_0c091a26;
P_0c091a26: /* original f448, guest PC 0x0c091a26 */
if(!s->budget--) { s->failed_pc=0x0c091a26u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c091a28;
P_0c091a28: /* original fa46, guest PC 0x0c091a28 */
if(!s->budget--) { s->failed_pc=0x0c091a28u; return 0; }
vf3_matrix_load(s,ram,10,r[4]+r[0]);
goto P_0c091a2a;
P_0c091a2a: /* original fb4c, guest PC 0x0c091a2a */
if(!s->budget--) { s->failed_pc=0x0c091a2au; return 0; }
vf3_matrix_move(s,11,4);
goto P_0c091a2c;
P_0c091a2c: /* original f541, guest PC 0x0c091a2c */
if(!s->budget--) { s->failed_pc=0x0c091a2cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'-');
goto P_0c091a2e;
P_0c091a2e: /* original f4ac, guest PC 0x0c091a2e */
if(!s->budget--) { s->failed_pc=0x0c091a2eu; return 0; }
vf3_matrix_move(s,4,10);
goto P_0c091a30;
P_0c091a30: /* original f481, guest PC 0x0c091a30 */
if(!s->budget--) { s->failed_pc=0x0c091a30u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'-');
goto P_0c091a32;
P_0c091a32: /* original f6a1, guest PC 0x0c091a32 */
if(!s->budget--) { s->failed_pc=0x0c091a32u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[10],r[18],'-');
goto P_0c091a34;
P_0c091a34: /* original fb71, guest PC 0x0c091a34 */
if(!s->budget--) { s->failed_pc=0x0c091a34u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[7],r[18],'-');
goto P_0c091a36;
P_0c091a36: /* original fa5c, guest PC 0x0c091a36 */
if(!s->budget--) { s->failed_pc=0x0c091a36u; return 0; }
vf3_matrix_move(s,10,5);
goto P_0c091a38;
P_0c091a38: /* original fa52, guest PC 0x0c091a38 */
if(!s->budget--) { s->failed_pc=0x0c091a38u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[5],r[18],'*');
goto P_0c091a3a;
P_0c091a3a: /* original f34c, guest PC 0x0c091a3a */
if(!s->budget--) { s->failed_pc=0x0c091a3au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c091a3c;
P_0c091a3c: /* original f46c, guest PC 0x0c091a3c */
if(!s->budget--) { s->failed_pc=0x0c091a3cu; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c091a3e;
P_0c091a3e: /* original f432, guest PC 0x0c091a3e */
if(!s->budget--) { s->failed_pc=0x0c091a3eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c091a40;
P_0c091a40: /* original f0bc, guest PC 0x0c091a40 */
if(!s->budget--) { s->failed_pc=0x0c091a40u; return 0; }
vf3_matrix_move(s,0,11);
goto P_0c091a42;
P_0c091a42: /* original f24c, guest PC 0x0c091a42 */
if(!s->budget--) { s->failed_pc=0x0c091a42u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c091a44;
P_0c091a44: /* original f25e, guest PC 0x0c091a44 */
if(!s->budget--) { s->failed_pc=0x0c091a44u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[5],fr[2],r[18]);
goto P_0c091a46;
P_0c091a46: /* original f42c, guest PC 0x0c091a46 */
if(!s->budget--) { s->failed_pc=0x0c091a46u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c091a48;
P_0c091a48: /* original f06c, guest PC 0x0c091a48 */
if(!s->budget--) { s->failed_pc=0x0c091a48u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c091a4a;
P_0c091a4a: /* original c71d, guest PC 0x0c091a4a */
if(!s->budget--) { s->failed_pc=0x0c091a4au; return 0; }
r[0]=code_base|0x00091ac0u;
goto P_0c091a4c;
P_0c091a4c: /* original f3ac, guest PC 0x0c091a4c */
if(!s->budget--) { s->failed_pc=0x0c091a4cu; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c091a4e;
P_0c091a4e: /* original f36e, guest PC 0x0c091a4e */
if(!s->budget--) { s->failed_pc=0x0c091a4eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[6],fr[3],r[18]);
goto P_0c091a50;
P_0c091a50: /* original f18d, guest PC 0x0c091a50 */
if(!s->budget--) { s->failed_pc=0x0c091a50u; return 0; }
fr[1]=0;
goto P_0c091a52;
P_0c091a52: /* original fa3c, guest PC 0x0c091a52 */
if(!s->budget--) { s->failed_pc=0x0c091a52u; return 0; }
vf3_matrix_move(s,10,3);
goto P_0c091a54;
P_0c091a54: /* original f38d, guest PC 0x0c091a54 */
if(!s->budget--) { s->failed_pc=0x0c091a54u; return 0; }
fr[3]=0;
goto P_0c091a56;
P_0c091a56: /* original f3a4, guest PC 0x0c091a56 */
if(!s->budget--) { s->failed_pc=0x0c091a56u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])==as_float(fr[10]))!=0);
goto P_0c091a58;
P_0c091a58: /* original 8d07, guest PC 0x0c091a58 */
if(!s->budget--) { s->failed_pc=0x0c091a58u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,15,r[0]);
if(cond) { goto P_0c091a6a; }
goto P_0c091a5c;
P_0c091a5a: /* original ff08, guest PC 0x0c091a5a */
if(!s->budget--) { s->failed_pc=0x0c091a5au; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c091a5c;
P_0c091a5c: /* original ffa5, guest PC 0x0c091a5c */
if(!s->budget--) { s->failed_pc=0x0c091a5cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[10]))!=0);
goto P_0c091a5e;
P_0c091a5e: /* original 8b01, guest PC 0x0c091a5e */
if(!s->budget--) { s->failed_pc=0x0c091a5eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091a64; }
goto P_0c091a60;
P_0c091a60: /* original a004, guest PC 0x0c091a60 */
if(!s->budget--) { s->failed_pc=0x0c091a60u; return 0; }
fr[11]=0;
goto P_0c091a6c;
P_0c091a62: /* original fb8d, guest PC 0x0c091a62 */
if(!s->budget--) { s->failed_pc=0x0c091a62u; return 0; }
fr[11]=0;
goto P_0c091a64;
P_0c091a64: /* original fbac, guest PC 0x0c091a64 */
if(!s->budget--) { s->failed_pc=0x0c091a64u; return 0; }
vf3_matrix_move(s,11,10);
goto P_0c091a66;
P_0c091a66: /* original a001, guest PC 0x0c091a66 */
if(!s->budget--) { s->failed_pc=0x0c091a66u; return 0; }
if(!vf3_fpu_fsrra(fr[11],r[18],&fr[11])) goto unsupported;
goto P_0c091a6c;
P_0c091a68: /* original fb7d, guest PC 0x0c091a68 */
if(!s->budget--) { s->failed_pc=0x0c091a68u; return 0; }
if(!vf3_fpu_fsrra(fr[11],r[18],&fr[11])) goto unsupported;
goto P_0c091a6a;
P_0c091a6a: /* original fb1c, guest PC 0x0c091a6a */
if(!s->budget--) { s->failed_pc=0x0c091a6au; return 0; }
vf3_matrix_move(s,11,1);
goto P_0c091a6c;
P_0c091a6c: /* original f34c, guest PC 0x0c091a6c */
if(!s->budget--) { s->failed_pc=0x0c091a6cu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c091a6e;
P_0c091a6e: /* original e008, guest PC 0x0c091a6e */
if(!s->budget--) { s->failed_pc=0x0c091a6eu; return 0; }
r[0]=0x00000008u;
goto P_0c091a70;
P_0c091a70: /* original f4bc, guest PC 0x0c091a70 */
if(!s->budget--) { s->failed_pc=0x0c091a70u; return 0; }
vf3_matrix_move(s,4,11);
goto P_0c091a72;
P_0c091a72: /* original f432, guest PC 0x0c091a72 */
if(!s->budget--) { s->failed_pc=0x0c091a72u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c091a74;
P_0c091a74: /* original fb78, guest PC 0x0c091a74 */
if(!s->budget--) { s->failed_pc=0x0c091a74u; return 0; }
vf3_matrix_load(s,ram,11,r[7]);
goto P_0c091a76;
P_0c091a76: /* original fa76, guest PC 0x0c091a76 */
if(!s->budget--) { s->failed_pc=0x0c091a76u; return 0; }
vf3_matrix_load(s,ram,10,r[7]+r[0]);
goto P_0c091a78;
P_0c091a78: /* original f04c, guest PC 0x0c091a78 */
if(!s->budget--) { s->failed_pc=0x0c091a78u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c091a7a;
P_0c091a7a: /* original fb5e, guest PC 0x0c091a7a */
if(!s->budget--) { s->failed_pc=0x0c091a7au; return 0; }
fr[11]=vf3_fpu_mac(fr[0],fr[5],fr[11],r[18]);
goto P_0c091a7c;
P_0c091a7c: /* original fa6e, guest PC 0x0c091a7c */
if(!s->budget--) { s->failed_pc=0x0c091a7cu; return 0; }
fr[10]=vf3_fpu_mac(fr[0],fr[6],fr[10],r[18]);
goto P_0c091a7e;
P_0c091a7e: /* original f5bc, guest PC 0x0c091a7e */
if(!s->budget--) { s->failed_pc=0x0c091a7eu; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c091a80;
P_0c091a80: /* original f754, guest PC 0x0c091a80 */
if(!s->budget--) { s->failed_pc=0x0c091a80u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])==as_float(fr[5]))!=0);
goto P_0c091a82;
P_0c091a82: /* original 8f07, guest PC 0x0c091a82 */
if(!s->budget--) { s->failed_pc=0x0c091a82u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,10);
if(!cond) { goto P_0c091a94; }
goto P_0c091a86;
P_0c091a84: /* original f4ac, guest PC 0x0c091a84 */
if(!s->budget--) { s->failed_pc=0x0c091a84u; return 0; }
vf3_matrix_move(s,4,10);
goto P_0c091a86;
P_0c091a86: /* original f844, guest PC 0x0c091a86 */
if(!s->budget--) { s->failed_pc=0x0c091a86u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])==as_float(fr[4]))!=0);
goto P_0c091a88;
P_0c091a88: /* original 8b04, guest PC 0x0c091a88 */
if(!s->budget--) { s->failed_pc=0x0c091a88u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091a94; }
goto P_0c091a8a;
P_0c091a8a: /* original c70e, guest PC 0x0c091a8a */
if(!s->budget--) { s->failed_pc=0x0c091a8au; return 0; }
r[0]=code_base|0x00091ac4u;
goto P_0c091a8c;
P_0c091a8c: /* original f51c, guest PC 0x0c091a8c */
if(!s->budget--) { s->failed_pc=0x0c091a8cu; return 0; }
vf3_matrix_move(s,5,1);
goto P_0c091a8e;
P_0c091a8e: /* original f608, guest PC 0x0c091a8e */
if(!s->budget--) { s->failed_pc=0x0c091a8eu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c091a90;
P_0c091a90: /* original a00c, guest PC 0x0c091a90 */
if(!s->budget--) { s->failed_pc=0x0c091a90u; return 0; }
vf3_matrix_move(s,4,1);
goto P_0c091aac;
P_0c091a92: /* original f41c, guest PC 0x0c091a92 */
if(!s->budget--) { s->failed_pc=0x0c091a92u; return 0; }
vf3_matrix_move(s,4,1);
goto P_0c091a94;
P_0c091a94: /* original f35c, guest PC 0x0c091a94 */
if(!s->budget--) { s->failed_pc=0x0c091a94u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c091a96;
P_0c091a96: /* original f57c, guest PC 0x0c091a96 */
if(!s->budget--) { s->failed_pc=0x0c091a96u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c091a98;
P_0c091a98: /* original f531, guest PC 0x0c091a98 */
if(!s->budget--) { s->failed_pc=0x0c091a98u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c091a9a;
P_0c091a9a: /* original f34c, guest PC 0x0c091a9a */
if(!s->budget--) { s->failed_pc=0x0c091a9au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c091a9c;
P_0c091a9c: /* original f48c, guest PC 0x0c091a9c */
if(!s->budget--) { s->failed_pc=0x0c091a9cu; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c091a9e;
P_0c091a9e: /* original f431, guest PC 0x0c091a9e */
if(!s->budget--) { s->failed_pc=0x0c091a9eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c091aa0;
P_0c091aa0: /* original f65c, guest PC 0x0c091aa0 */
if(!s->budget--) { s->failed_pc=0x0c091aa0u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c091aa2;
P_0c091aa2: /* original f652, guest PC 0x0c091aa2 */
if(!s->budget--) { s->failed_pc=0x0c091aa2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c091aa4;
P_0c091aa4: /* original f04c, guest PC 0x0c091aa4 */
if(!s->budget--) { s->failed_pc=0x0c091aa4u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c091aa6;
P_0c091aa6: /* original f26c, guest PC 0x0c091aa6 */
if(!s->budget--) { s->failed_pc=0x0c091aa6u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c091aa8;
P_0c091aa8: /* original f24e, guest PC 0x0c091aa8 */
if(!s->budget--) { s->failed_pc=0x0c091aa8u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[4],fr[2],r[18]);
goto P_0c091aaa;
P_0c091aaa: /* original f62c, guest PC 0x0c091aaa */
if(!s->budget--) { s->failed_pc=0x0c091aaau; return 0; }
vf3_matrix_move(s,6,2);
goto P_0c091aac;
P_0c091aac: /* original ff65, guest PC 0x0c091aac */
if(!s->budget--) { s->failed_pc=0x0c091aacu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[6]))!=0);
goto P_0c091aae;
P_0c091aae: /* original 8b0b, guest PC 0x0c091aae */
if(!s->budget--) { s->failed_pc=0x0c091aaeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091ac8; }
goto P_0c091ab0;
P_0c091ab0: /* original a00b, guest PC 0x0c091ab0 */
if(!s->budget--) { s->failed_pc=0x0c091ab0u; return 0; }
fr[6]=0;
goto P_0c091aca;
P_0c091ab2: /* original f68d, guest PC 0x0c091ab2 */
if(!s->budget--) { s->failed_pc=0x0c091ab2u; return 0; }
fr[6]=0;
if(!vf3_matrix_family(0x0c091ab4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c091ab4u; return 0; } return 1;
P_0c091ac8: /* original f67d, guest PC 0x0c091ac8 */
if(!s->budget--) { s->failed_pc=0x0c091ac8u; return 0; }
if(!vf3_fpu_fsrra(fr[6],r[18],&fr[6])) goto unsupported;
goto P_0c091aca;
P_0c091aca: /* original ff95, guest PC 0x0c091aca */
if(!s->budget--) { s->failed_pc=0x0c091acau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[9]))!=0);
goto P_0c091acc;
P_0c091acc: /* original f562, guest PC 0x0c091acc */
if(!s->budget--) { s->failed_pc=0x0c091accu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c091ace;
P_0c091ace: /* original 8f02, guest PC 0x0c091ace */
if(!s->budget--) { s->failed_pc=0x0c091aceu; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
if(!cond) { goto P_0c091ad6; }
goto P_0c091ad2;
P_0c091ad0: /* original f462, guest PC 0x0c091ad0 */
if(!s->budget--) { s->failed_pc=0x0c091ad0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c091ad2;
P_0c091ad2: /* original a002, guest PC 0x0c091ad2 */
if(!s->budget--) { s->failed_pc=0x0c091ad2u; return 0; }
fr[6]=0;
goto P_0c091ada;
P_0c091ad4: /* original f68d, guest PC 0x0c091ad4 */
if(!s->budget--) { s->failed_pc=0x0c091ad4u; return 0; }
fr[6]=0;
goto P_0c091ad6;
P_0c091ad6: /* original f69c, guest PC 0x0c091ad6 */
if(!s->budget--) { s->failed_pc=0x0c091ad6u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c091ad8;
P_0c091ad8: /* original f66d, guest PC 0x0c091ad8 */
if(!s->budget--) { s->failed_pc=0x0c091ad8u; return 0; }
fr[6]=vf3_fpu_sqrt(fr[6],r[18]);
goto P_0c091ada;
P_0c091ada: /* original c71b, guest PC 0x0c091ada */
if(!s->budget--) { s->failed_pc=0x0c091adau; return 0; }
r[0]=code_base|0x00091b48u;
goto P_0c091adc;
P_0c091adc: /* original f28c, guest PC 0x0c091adc */
if(!s->budget--) { s->failed_pc=0x0c091adcu; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c091ade;
P_0c091ade: /* original f908, guest PC 0x0c091ade */
if(!s->budget--) { s->failed_pc=0x0c091adeu; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c091ae0;
P_0c091ae0: /* original f37c, guest PC 0x0c091ae0 */
if(!s->budget--) { s->failed_pc=0x0c091ae0u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c091ae2;
P_0c091ae2: /* original f692, guest PC 0x0c091ae2 */
if(!s->budget--) { s->failed_pc=0x0c091ae2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[9],r[18],'*');
goto P_0c091ae4;
P_0c091ae4: /* original f06c, guest PC 0x0c091ae4 */
if(!s->budget--) { s->failed_pc=0x0c091ae4u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c091ae6;
P_0c091ae6: /* original f24e, guest PC 0x0c091ae6 */
if(!s->budget--) { s->failed_pc=0x0c091ae6u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[4],fr[2],r[18]);
goto P_0c091ae8;
P_0c091ae8: /* original f35e, guest PC 0x0c091ae8 */
if(!s->budget--) { s->failed_pc=0x0c091ae8u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c091aea;
P_0c091aea: /* original f82c, guest PC 0x0c091aea */
if(!s->budget--) { s->failed_pc=0x0c091aeau; return 0; }
vf3_matrix_move(s,8,2);
goto P_0c091aec;
P_0c091aec: /* original f73c, guest PC 0x0c091aec */
if(!s->budget--) { s->failed_pc=0x0c091aecu; return 0; }
vf3_matrix_move(s,7,3);
goto P_0c091aee;
P_0c091aee: /* original 7f04, guest PC 0x0c091aee */
if(!s->budget--) { s->failed_pc=0x0c091aeeu; return 0; }
r[15]+=0x00000004u;
goto P_0c091af0;
P_0c091af0: /* original f57a, guest PC 0x0c091af0 */
if(!s->budget--) { s->failed_pc=0x0c091af0u; return 0; }
vf3_matrix_store(s,ram,7,r[5]);
goto P_0c091af2;
P_0c091af2: /* original f68a, guest PC 0x0c091af2 */
if(!s->budget--) { s->failed_pc=0x0c091af2u; return 0; }
vf3_matrix_store(s,ram,8,r[6]);
goto P_0c091af4;
P_0c091af4: /* original fff9, guest PC 0x0c091af4 */
if(!s->budget--) { s->failed_pc=0x0c091af4u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c091af6;
P_0c091af6: /* original 6bf6, guest PC 0x0c091af6 */
if(!s->budget--) { s->failed_pc=0x0c091af6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c091af8;
P_0c091af8: /* original 6cf6, guest PC 0x0c091af8 */
if(!s->budget--) { s->failed_pc=0x0c091af8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c091afa;
P_0c091afa: /* original 000b, guest PC 0x0c091afa */
if(!s->budget--) { s->failed_pc=0x0c091afau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c091afc: /* original 6df6, guest PC 0x0c091afc */
if(!s->budget--) { s->failed_pc=0x0c091afcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
if(!vf3_matrix_family(0x0c091afeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c091afeu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
