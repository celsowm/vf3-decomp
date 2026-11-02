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
int vf3_away_batch14_adapter_16(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08814cu: goto P_0c08814c;
case 0x0c08814eu: goto P_0c08814e;
case 0x0c088150u: goto P_0c088150;
case 0x0c088152u: goto P_0c088152;
case 0x0c088154u: goto P_0c088154;
case 0x0c088156u: goto P_0c088156;
case 0x0c088158u: goto P_0c088158;
case 0x0c08815au: goto P_0c08815a;
case 0x0c08815cu: goto P_0c08815c;
case 0x0c08815eu: goto P_0c08815e;
case 0x0c088160u: goto P_0c088160;
case 0x0c088162u: goto P_0c088162;
case 0x0c088164u: goto P_0c088164;
case 0x0c088166u: goto P_0c088166;
case 0x0c088168u: goto P_0c088168;
case 0x0c08816au: goto P_0c08816a;
case 0x0c08816cu: goto P_0c08816c;
case 0x0c08816eu: goto P_0c08816e;
case 0x0c088170u: goto P_0c088170;
case 0x0c088172u: goto P_0c088172;
case 0x0c088174u: goto P_0c088174;
case 0x0c088176u: goto P_0c088176;
case 0x0c088178u: goto P_0c088178;
case 0x0c08817au: goto P_0c08817a;
case 0x0c08817cu: goto P_0c08817c;
case 0x0c08817eu: goto P_0c08817e;
case 0x0c088180u: goto P_0c088180;
case 0x0c088182u: goto P_0c088182;
case 0x0c088184u: goto P_0c088184;
case 0x0c088186u: goto P_0c088186;
case 0x0c088188u: goto P_0c088188;
case 0x0c08818au: goto P_0c08818a;
case 0x0c08818cu: goto P_0c08818c;
case 0x0c08818eu: goto P_0c08818e;
case 0x0c088190u: goto P_0c088190;
case 0x0c088192u: goto P_0c088192;
case 0x0c088194u: goto P_0c088194;
case 0x0c088196u: goto P_0c088196;
case 0x0c088198u: goto P_0c088198;
case 0x0c08819au: goto P_0c08819a;
case 0x0c08819cu: goto P_0c08819c;
case 0x0c08819eu: goto P_0c08819e;
case 0x0c0881a0u: goto P_0c0881a0;
case 0x0c0881a2u: goto P_0c0881a2;
case 0x0c0881a4u: goto P_0c0881a4;
case 0x0c0881a6u: goto P_0c0881a6;
case 0x0c0881a8u: goto P_0c0881a8;
case 0x0c0881aau: goto P_0c0881aa;
case 0x0c088868u: goto P_0c088868;
case 0x0c08886au: goto P_0c08886a;
case 0x0c08886cu: goto P_0c08886c;
case 0x0c08886eu: goto P_0c08886e;
case 0x0c088870u: goto P_0c088870;
case 0x0c088872u: goto P_0c088872;
case 0x0c088874u: goto P_0c088874;
case 0x0c088876u: goto P_0c088876;
case 0x0c088878u: goto P_0c088878;
case 0x0c08887au: goto P_0c08887a;
case 0x0c08887cu: goto P_0c08887c;
case 0x0c08887eu: goto P_0c08887e;
case 0x0c088880u: goto P_0c088880;
case 0x0c088882u: goto P_0c088882;
case 0x0c088884u: goto P_0c088884;
case 0x0c088886u: goto P_0c088886;
case 0x0c088888u: goto P_0c088888;
case 0x0c08888au: goto P_0c08888a;
case 0x0c08888cu: goto P_0c08888c;
case 0x0c08888eu: goto P_0c08888e;
case 0x0c088890u: goto P_0c088890;
case 0x0c088892u: goto P_0c088892;
case 0x0c088894u: goto P_0c088894;
case 0x0c088896u: goto P_0c088896;
case 0x0c088898u: goto P_0c088898;
case 0x0c08889au: goto P_0c08889a;
case 0x0c08889cu: goto P_0c08889c;
case 0x0c08889eu: goto P_0c08889e;
case 0x0c0888a0u: goto P_0c0888a0;
case 0x0c0888a2u: goto P_0c0888a2;
case 0x0c0888a4u: goto P_0c0888a4;
case 0x0c0888a6u: goto P_0c0888a6;
case 0x0c0888a8u: goto P_0c0888a8;
case 0x0c0888aau: goto P_0c0888aa;
case 0x0c0888acu: goto P_0c0888ac;
case 0x0c0888aeu: goto P_0c0888ae;
case 0x0c0888b0u: goto P_0c0888b0;
case 0x0c0888b2u: goto P_0c0888b2;
case 0x0c0888b4u: goto P_0c0888b4;
case 0x0c0888b6u: goto P_0c0888b6;
case 0x0c0888b8u: goto P_0c0888b8;
case 0x0c0888bau: goto P_0c0888ba;
case 0x0c0888bcu: goto P_0c0888bc;
case 0x0c0888beu: goto P_0c0888be;
case 0x0c0888c0u: goto P_0c0888c0;
case 0x0c0888c2u: goto P_0c0888c2;
case 0x0c0888c4u: goto P_0c0888c4;
case 0x0c0888c6u: goto P_0c0888c6;
case 0x0c0888c8u: goto P_0c0888c8;
case 0x0c0888cau: goto P_0c0888ca;
case 0x0c0888ccu: goto P_0c0888cc;
case 0x0c0888ceu: goto P_0c0888ce;
case 0x0c0888d0u: goto P_0c0888d0;
case 0x0c0888d2u: goto P_0c0888d2;
case 0x0c0888d4u: goto P_0c0888d4;
case 0x0c0888d6u: goto P_0c0888d6;
case 0x0c0888d8u: goto P_0c0888d8;
case 0x0c0888dau: goto P_0c0888da;
case 0x0c0888dcu: goto P_0c0888dc;
case 0x0c0888deu: goto P_0c0888de;
case 0x0c0888e0u: goto P_0c0888e0;
case 0x0c0888e2u: goto P_0c0888e2;
case 0x0c0888e4u: goto P_0c0888e4;
case 0x0c0888e6u: goto P_0c0888e6;
case 0x0c0888e8u: goto P_0c0888e8;
case 0x0c0888eau: goto P_0c0888ea;
case 0x0c0888ecu: goto P_0c0888ec;
case 0x0c0888eeu: goto P_0c0888ee;
case 0x0c0888f0u: goto P_0c0888f0;
case 0x0c0888f2u: goto P_0c0888f2;
case 0x0c0888f4u: goto P_0c0888f4;
case 0x0c0888f6u: goto P_0c0888f6;
case 0x0c0888f8u: goto P_0c0888f8;
case 0x0c0888fau: goto P_0c0888fa;
case 0x0c0888fcu: goto P_0c0888fc;
case 0x0c0888feu: goto P_0c0888fe;
case 0x0c088900u: goto P_0c088900;
case 0x0c088902u: goto P_0c088902;
case 0x0c088904u: goto P_0c088904;
case 0x0c088906u: goto P_0c088906;
case 0x0c088908u: goto P_0c088908;
case 0x0c08890au: goto P_0c08890a;
case 0x0c08890cu: goto P_0c08890c;
case 0x0c08890eu: goto P_0c08890e;
case 0x0c08894cu: goto P_0c08894c;
case 0x0c08894eu: goto P_0c08894e;
case 0x0c088950u: goto P_0c088950;
case 0x0c088952u: goto P_0c088952;
case 0x0c088954u: goto P_0c088954;
case 0x0c088956u: goto P_0c088956;
case 0x0c088958u: goto P_0c088958;
case 0x0c08895au: goto P_0c08895a;
case 0x0c08895cu: goto P_0c08895c;
case 0x0c08895eu: goto P_0c08895e;
case 0x0c088960u: goto P_0c088960;
case 0x0c088962u: goto P_0c088962;
case 0x0c088964u: goto P_0c088964;
case 0x0c088966u: goto P_0c088966;
case 0x0c088968u: goto P_0c088968;
case 0x0c08896au: goto P_0c08896a;
case 0x0c08896cu: goto P_0c08896c;
case 0x0c08896eu: goto P_0c08896e;
case 0x0c088970u: goto P_0c088970;
case 0x0c088972u: goto P_0c088972;
case 0x0c088974u: goto P_0c088974;
case 0x0c088976u: goto P_0c088976;
case 0x0c088978u: goto P_0c088978;
case 0x0c08897au: goto P_0c08897a;
case 0x0c08897cu: goto P_0c08897c;
case 0x0c08897eu: goto P_0c08897e;
case 0x0c088980u: goto P_0c088980;
case 0x0c088982u: goto P_0c088982;
case 0x0c088984u: goto P_0c088984;
case 0x0c088986u: goto P_0c088986;
case 0x0c088988u: goto P_0c088988;
case 0x0c08898au: goto P_0c08898a;
case 0x0c08898cu: goto P_0c08898c;
case 0x0c08898eu: goto P_0c08898e;
case 0x0c088990u: goto P_0c088990;
case 0x0c088992u: goto P_0c088992;
case 0x0c088994u: goto P_0c088994;
case 0x0c088996u: goto P_0c088996;
case 0x0c088998u: goto P_0c088998;
case 0x0c08899au: goto P_0c08899a;
case 0x0c08899cu: goto P_0c08899c;
case 0x0c08899eu: goto P_0c08899e;
case 0x0c0889a0u: goto P_0c0889a0;
case 0x0c0889a2u: goto P_0c0889a2;
case 0x0c0889a4u: goto P_0c0889a4;
case 0x0c0889a6u: goto P_0c0889a6;
case 0x0c0889a8u: goto P_0c0889a8;
case 0x0c0889aau: goto P_0c0889aa;
case 0x0c0889acu: goto P_0c0889ac;
case 0x0c0889aeu: goto P_0c0889ae;
case 0x0c0889b0u: goto P_0c0889b0;
case 0x0c0889b2u: goto P_0c0889b2;
case 0x0c0889b4u: goto P_0c0889b4;
case 0x0c0889b6u: goto P_0c0889b6;
case 0x0c0889b8u: goto P_0c0889b8;
case 0x0c0889bau: goto P_0c0889ba;
case 0x0c0889bcu: goto P_0c0889bc;
case 0x0c0889beu: goto P_0c0889be;
case 0x0c0889c0u: goto P_0c0889c0;
case 0x0c0889c2u: goto P_0c0889c2;
case 0x0c0889c4u: goto P_0c0889c4;
case 0x0c0889c6u: goto P_0c0889c6;
case 0x0c0889c8u: goto P_0c0889c8;
case 0x0c0889cau: goto P_0c0889ca;
case 0x0c0889ccu: goto P_0c0889cc;
case 0x0c0889ceu: goto P_0c0889ce;
case 0x0c0889d0u: goto P_0c0889d0;
case 0x0c0889d2u: goto P_0c0889d2;
case 0x0c0889d4u: goto P_0c0889d4;
case 0x0c0889d6u: goto P_0c0889d6;
case 0x0c0889d8u: goto P_0c0889d8;
case 0x0c0889dau: goto P_0c0889da;
case 0x0c0889dcu: goto P_0c0889dc;
case 0x0c0889deu: goto P_0c0889de;
case 0x0c0889e0u: goto P_0c0889e0;
case 0x0c0889e2u: goto P_0c0889e2;
case 0x0c0889e4u: goto P_0c0889e4;
case 0x0c0889e6u: goto P_0c0889e6;
case 0x0c0889e8u: goto P_0c0889e8;
case 0x0c0889eau: goto P_0c0889ea;
case 0x0c0889ecu: goto P_0c0889ec;
case 0x0c0889eeu: goto P_0c0889ee;
case 0x0c0889f0u: goto P_0c0889f0;
case 0x0c0889f2u: goto P_0c0889f2;
case 0x0c0889f4u: goto P_0c0889f4;
case 0x0c0889f6u: goto P_0c0889f6;
case 0x0c0889f8u: goto P_0c0889f8;
case 0x0c0889fau: goto P_0c0889fa;
case 0x0c0889fcu: goto P_0c0889fc;
case 0x0c0889feu: goto P_0c0889fe;
case 0x0c088a00u: goto P_0c088a00;
case 0x0c088a02u: goto P_0c088a02;
case 0x0c088a04u: goto P_0c088a04;
case 0x0c088a06u: goto P_0c088a06;
case 0x0c088a08u: goto P_0c088a08;
case 0x0c088a0au: goto P_0c088a0a;
case 0x0c088a0cu: goto P_0c088a0c;
case 0x0c088a0eu: goto P_0c088a0e;
case 0x0c088a10u: goto P_0c088a10;
case 0x0c088a12u: goto P_0c088a12;
case 0x0c088a14u: goto P_0c088a14;
case 0x0c088a16u: goto P_0c088a16;
case 0x0c088a18u: goto P_0c088a18;
case 0x0c088a1au: goto P_0c088a1a;
case 0x0c088a1cu: goto P_0c088a1c;
case 0x0c088a1eu: goto P_0c088a1e;
case 0x0c088a20u: goto P_0c088a20;
case 0x0c088a22u: goto P_0c088a22;
case 0x0c088a24u: goto P_0c088a24;
case 0x0c088a26u: goto P_0c088a26;
case 0x0c088a28u: goto P_0c088a28;
case 0x0c088a2au: goto P_0c088a2a;
case 0x0c088a2cu: goto P_0c088a2c;
case 0x0c088a2eu: goto P_0c088a2e;
case 0x0c088a30u: goto P_0c088a30;
case 0x0c088a32u: goto P_0c088a32;
case 0x0c088a34u: goto P_0c088a34;
case 0x0c088a36u: goto P_0c088a36;
case 0x0c088a38u: goto P_0c088a38;
case 0x0c088a3au: goto P_0c088a3a;
case 0x0c088a3cu: goto P_0c088a3c;
case 0x0c088a3eu: goto P_0c088a3e;
case 0x0c088a40u: goto P_0c088a40;
case 0x0c088a42u: goto P_0c088a42;
case 0x0c088a44u: goto P_0c088a44;
case 0x0c088a46u: goto P_0c088a46;
case 0x0c088a48u: goto P_0c088a48;
case 0x0c088a4au: goto P_0c088a4a;
case 0x0c088a4cu: goto P_0c088a4c;
case 0x0c088a78u: goto P_0c088a78;
case 0x0c088a7au: goto P_0c088a7a;
case 0x0c088a7cu: goto P_0c088a7c;
case 0x0c088a7eu: goto P_0c088a7e;
case 0x0c088a80u: goto P_0c088a80;
case 0x0c088a82u: goto P_0c088a82;
case 0x0c088a84u: goto P_0c088a84;
case 0x0c088a86u: goto P_0c088a86;
case 0x0c088a88u: goto P_0c088a88;
case 0x0c088a8au: goto P_0c088a8a;
case 0x0c088a8cu: goto P_0c088a8c;
case 0x0c088a8eu: goto P_0c088a8e;
case 0x0c088a90u: goto P_0c088a90;
case 0x0c088a92u: goto P_0c088a92;
case 0x0c088a94u: goto P_0c088a94;
case 0x0c088a96u: goto P_0c088a96;
case 0x0c088a98u: goto P_0c088a98;
case 0x0c088a9au: goto P_0c088a9a;
case 0x0c088a9cu: goto P_0c088a9c;
case 0x0c088a9eu: goto P_0c088a9e;
case 0x0c088aa0u: goto P_0c088aa0;
case 0x0c088aa2u: goto P_0c088aa2;
case 0x0c088aa4u: goto P_0c088aa4;
case 0x0c088aa6u: goto P_0c088aa6;
case 0x0c088aa8u: goto P_0c088aa8;
case 0x0c088aaau: goto P_0c088aaa;
case 0x0c088aacu: goto P_0c088aac;
case 0x0c088aaeu: goto P_0c088aae;
case 0x0c088ab0u: goto P_0c088ab0;
case 0x0c088ab2u: goto P_0c088ab2;
case 0x0c088ab4u: goto P_0c088ab4;
case 0x0c088ab6u: goto P_0c088ab6;
case 0x0c088ab8u: goto P_0c088ab8;
case 0x0c088abau: goto P_0c088aba;
case 0x0c088abcu: goto P_0c088abc;
case 0x0c088abeu: goto P_0c088abe;
case 0x0c088ac0u: goto P_0c088ac0;
case 0x0c088ac2u: goto P_0c088ac2;
case 0x0c088ac4u: goto P_0c088ac4;
case 0x0c088ac6u: goto P_0c088ac6;
case 0x0c088ac8u: goto P_0c088ac8;
case 0x0c088acau: goto P_0c088aca;
case 0x0c088accu: goto P_0c088acc;
case 0x0c088aceu: goto P_0c088ace;
case 0x0c088ad0u: goto P_0c088ad0;
case 0x0c088ad2u: goto P_0c088ad2;
case 0x0c088ad4u: goto P_0c088ad4;
case 0x0c088ad6u: goto P_0c088ad6;
case 0x0c088ad8u: goto P_0c088ad8;
case 0x0c088adau: goto P_0c088ada;
case 0x0c088adcu: goto P_0c088adc;
case 0x0c088adeu: goto P_0c088ade;
case 0x0c088ae0u: goto P_0c088ae0;
case 0x0c088ae2u: goto P_0c088ae2;
case 0x0c088ae4u: goto P_0c088ae4;
case 0x0c088ae6u: goto P_0c088ae6;
case 0x0c088ae8u: goto P_0c088ae8;
case 0x0c088aeau: goto P_0c088aea;
case 0x0c088aecu: goto P_0c088aec;
case 0x0c088aeeu: goto P_0c088aee;
case 0x0c088af0u: goto P_0c088af0;
case 0x0c088af2u: goto P_0c088af2;
case 0x0c088af4u: goto P_0c088af4;
case 0x0c088af6u: goto P_0c088af6;
case 0x0c088af8u: goto P_0c088af8;
case 0x0c088afau: goto P_0c088afa;
case 0x0c088afcu: goto P_0c088afc;
case 0x0c088afeu: goto P_0c088afe;
case 0x0c088b00u: goto P_0c088b00;
case 0x0c088b02u: goto P_0c088b02;
case 0x0c088b04u: goto P_0c088b04;
case 0x0c088b06u: goto P_0c088b06;
case 0x0c088b08u: goto P_0c088b08;
case 0x0c088b0au: goto P_0c088b0a;
case 0x0c088b0cu: goto P_0c088b0c;
case 0x0c088b0eu: goto P_0c088b0e;
case 0x0c088b10u: goto P_0c088b10;
case 0x0c088b12u: goto P_0c088b12;
case 0x0c088b14u: goto P_0c088b14;
case 0x0c088b16u: goto P_0c088b16;
case 0x0c088b18u: goto P_0c088b18;
case 0x0c088b1au: goto P_0c088b1a;
case 0x0c088b1cu: goto P_0c088b1c;
case 0x0c088b1eu: goto P_0c088b1e;
case 0x0c088b20u: goto P_0c088b20;
case 0x0c088b22u: goto P_0c088b22;
case 0x0c088b24u: goto P_0c088b24;
case 0x0c088b26u: goto P_0c088b26;
case 0x0c088b28u: goto P_0c088b28;
case 0x0c088b2au: goto P_0c088b2a;
case 0x0c088b2cu: goto P_0c088b2c;
case 0x0c088b2eu: goto P_0c088b2e;
case 0x0c088b30u: goto P_0c088b30;
case 0x0c088b32u: goto P_0c088b32;
case 0x0c088b34u: goto P_0c088b34;
case 0x0c088b36u: goto P_0c088b36;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08814c: /* original 2fe6, guest PC 0x0c08814c */
if(!s->budget--) { s->failed_pc=0x0c08814cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08814e;
P_0c08814e: /* original 2fd6, guest PC 0x0c08814e */
if(!s->budget--) { s->failed_pc=0x0c08814eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088150;
P_0c088150: /* original 2fc6, guest PC 0x0c088150 */
if(!s->budget--) { s->failed_pc=0x0c088150u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088152;
P_0c088152: /* original 2fb6, guest PC 0x0c088152 */
if(!s->budget--) { s->failed_pc=0x0c088152u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088154;
P_0c088154: /* original 2fa6, guest PC 0x0c088154 */
if(!s->budget--) { s->failed_pc=0x0c088154u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088156;
P_0c088156: /* original fffb, guest PC 0x0c088156 */
if(!s->budget--) { s->failed_pc=0x0c088156u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c088158;
P_0c088158: /* original 4f22, guest PC 0x0c088158 */
if(!s->budget--) { s->failed_pc=0x0c088158u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08815a;
P_0c08815a: /* original 9e27, guest PC 0x0c08815a */
if(!s->budget--) { s->failed_pc=0x0c08815au; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0881acu,2);
goto P_0c08815c;
P_0c08815c: /* original d315, guest PC 0x0c08815c */
if(!s->budget--) { s->failed_pc=0x0c08815cu; return 0; }
r[3]=read(ram,0x0c0881b4u,4);
goto P_0c08815e;
P_0c08815e: /* original 3e4c, guest PC 0x0c08815e */
if(!s->budget--) { s->failed_pc=0x0c08815eu; return 0; }
r[14]+=r[4];
goto P_0c088160;
P_0c088160: /* original 7fc0, guest PC 0x0c088160 */
if(!s->budget--) { s->failed_pc=0x0c088160u; return 0; }
r[15]+=0xffffffc0u;
goto P_0c088162;
P_0c088162: /* original 430b, guest PC 0x0c088162 */
if(!s->budget--) { s->failed_pc=0x0c088162u; return 0; }
target=r[3];
r[16]=code_base|0x0c088166u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088166u) { target=s->pc; goto dispatch; }
goto P_0c088166;
P_0c088164: /* original e400, guest PC 0x0c088164 */
if(!s->budget--) { s->failed_pc=0x0c088164u; return 0; }
r[4]=0x00000000u;
goto P_0c088166;
P_0c088166: /* original c717, guest PC 0x0c088166 */
if(!s->budget--) { s->failed_pc=0x0c088166u; return 0; }
r[0]=code_base|0x000881c4u;
goto P_0c088168;
P_0c088168: /* original dc15, guest PC 0x0c088168 */
if(!s->budget--) { s->failed_pc=0x0c088168u; return 0; }
r[12]=read(ram,0x0c0881c0u,4);
goto P_0c08816a;
P_0c08816a: /* original ff08, guest PC 0x0c08816a */
if(!s->budget--) { s->failed_pc=0x0c08816au; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08816c;
P_0c08816c: /* original ed08, guest PC 0x0c08816c */
if(!s->budget--) { s->failed_pc=0x0c08816cu; return 0; }
r[13]=0x00000008u;
goto P_0c08816e;
P_0c08816e: /* original da12, guest PC 0x0c08816e */
if(!s->budget--) { s->failed_pc=0x0c08816eu; return 0; }
r[10]=read(ram,0x0c0881b8u,4);
goto P_0c088170;
P_0c088170: /* original db12, guest PC 0x0c088170 */
if(!s->budget--) { s->failed_pc=0x0c088170u; return 0; }
r[11]=read(ram,0x0c0881bcu,4);
goto P_0c088172;
P_0c088172: /* original 65e3, guest PC 0x0c088172 */
if(!s->budget--) { s->failed_pc=0x0c088172u; return 0; }
r[5]=r[14];
goto P_0c088174;
P_0c088174: /* original 4c0b, guest PC 0x0c088174 */
if(!s->budget--) { s->failed_pc=0x0c088174u; return 0; }
target=r[12];
r[16]=code_base|0x0c088178u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088178u) { target=s->pc; goto dispatch; }
goto P_0c088178;
P_0c088176: /* original 64f3, guest PC 0x0c088176 */
if(!s->budget--) { s->failed_pc=0x0c088176u; return 0; }
r[4]=r[15];
goto P_0c088178;
P_0c088178: /* original e038, guest PC 0x0c088178 */
if(!s->budget--) { s->failed_pc=0x0c088178u; return 0; }
r[0]=0x00000038u;
goto P_0c08817a;
P_0c08817a: /* original f3f6, guest PC 0x0c08817a */
if(!s->budget--) { s->failed_pc=0x0c08817au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08817c;
P_0c08817c: /* original e038, guest PC 0x0c08817c */
if(!s->budget--) { s->failed_pc=0x0c08817cu; return 0; }
r[0]=0x00000038u;
goto P_0c08817e;
P_0c08817e: /* original f3f2, guest PC 0x0c08817e */
if(!s->budget--) { s->failed_pc=0x0c08817eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c088180;
P_0c088180: /* original ff37, guest PC 0x0c088180 */
if(!s->budget--) { s->failed_pc=0x0c088180u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c088182;
P_0c088182: /* original 4b0b, guest PC 0x0c088182 */
if(!s->budget--) { s->failed_pc=0x0c088182u; return 0; }
target=r[11];
r[16]=code_base|0x0c088186u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088186u) { target=s->pc; goto dispatch; }
goto P_0c088186;
P_0c088184: /* original 64f3, guest PC 0x0c088184 */
if(!s->budget--) { s->failed_pc=0x0c088184u; return 0; }
r[4]=r[15];
goto P_0c088186;
P_0c088186: /* original 9012, guest PC 0x0c088186 */
if(!s->budget--) { s->failed_pc=0x0c088186u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0881aeu,2);
goto P_0c088188;
P_0c088188: /* original 4a0b, guest PC 0x0c088188 */
if(!s->budget--) { s->failed_pc=0x0c088188u; return 0; }
target=r[10];
r[16]=code_base|0x0c08818cu;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08818cu) { target=s->pc; goto dispatch; }
goto P_0c08818c;
P_0c08818a: /* original 04ed, guest PC 0x0c08818a */
if(!s->budget--) { s->failed_pc=0x0c08818au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08818c;
P_0c08818c: /* original 9310, guest PC 0x0c08818c */
if(!s->budget--) { s->failed_pc=0x0c08818cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0881b0u,2);
goto P_0c08818e;
P_0c08818e: /* original 4d10, guest PC 0x0c08818e */
if(!s->budget--) { s->failed_pc=0x0c08818eu; return 0; }
--r[13];
r[17]=(r[17]&~1u)|((r[13]==0)!=0);
goto P_0c088190;
P_0c088190: /* original 8fef, guest PC 0x0c088190 */
if(!s->budget--) { s->failed_pc=0x0c088190u; return 0; }
cond=r[17]&1u;
r[14]+=r[3];
if(!cond) { goto P_0c088172; }
goto P_0c088194;
P_0c088192: /* original 3e3c, guest PC 0x0c088192 */
if(!s->budget--) { s->failed_pc=0x0c088192u; return 0; }
r[14]+=r[3];
goto P_0c088194;
P_0c088194: /* original d30c, guest PC 0x0c088194 */
if(!s->budget--) { s->failed_pc=0x0c088194u; return 0; }
r[3]=read(ram,0x0c0881c8u,4);
goto P_0c088196;
P_0c088196: /* original 430b, guest PC 0x0c088196 */
if(!s->budget--) { s->failed_pc=0x0c088196u; return 0; }
target=r[3];
r[16]=code_base|0x0c08819au;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08819au) { target=s->pc; goto dispatch; }
goto P_0c08819a;
P_0c088198: /* original e401, guest PC 0x0c088198 */
if(!s->budget--) { s->failed_pc=0x0c088198u; return 0; }
r[4]=0x00000001u;
goto P_0c08819a;
P_0c08819a: /* original 7f40, guest PC 0x0c08819a */
if(!s->budget--) { s->failed_pc=0x0c08819au; return 0; }
r[15]+=0x00000040u;
goto P_0c08819c;
P_0c08819c: /* original 4f26, guest PC 0x0c08819c */
if(!s->budget--) { s->failed_pc=0x0c08819cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08819e;
P_0c08819e: /* original fff9, guest PC 0x0c08819e */
if(!s->budget--) { s->failed_pc=0x0c08819eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0881a0;
P_0c0881a0: /* original 6af6, guest PC 0x0c0881a0 */
if(!s->budget--) { s->failed_pc=0x0c0881a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0881a2;
P_0c0881a2: /* original 6bf6, guest PC 0x0c0881a2 */
if(!s->budget--) { s->failed_pc=0x0c0881a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0881a4;
P_0c0881a4: /* original 6cf6, guest PC 0x0c0881a4 */
if(!s->budget--) { s->failed_pc=0x0c0881a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0881a6;
P_0c0881a6: /* original 6df6, guest PC 0x0c0881a6 */
if(!s->budget--) { s->failed_pc=0x0c0881a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0881a8;
P_0c0881a8: /* original 000b, guest PC 0x0c0881a8 */
if(!s->budget--) { s->failed_pc=0x0c0881a8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0881aa: /* original 6ef6, guest PC 0x0c0881aa */
if(!s->budget--) { s->failed_pc=0x0c0881aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0881acu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0881acu; return 0; } return 1;
P_0c088868: /* original 2fe6, guest PC 0x0c088868 */
if(!s->budget--) { s->failed_pc=0x0c088868u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08886a;
P_0c08886a: /* original 2fd6, guest PC 0x0c08886a */
if(!s->budget--) { s->failed_pc=0x0c08886au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08886c;
P_0c08886c: /* original 2fc6, guest PC 0x0c08886c */
if(!s->budget--) { s->failed_pc=0x0c08886cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08886e;
P_0c08886e: /* original 2fb6, guest PC 0x0c08886e */
if(!s->budget--) { s->failed_pc=0x0c08886eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088870;
P_0c088870: /* original 2fa6, guest PC 0x0c088870 */
if(!s->budget--) { s->failed_pc=0x0c088870u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088872;
P_0c088872: /* original 2f96, guest PC 0x0c088872 */
if(!s->budget--) { s->failed_pc=0x0c088872u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088874;
P_0c088874: /* original 2f86, guest PC 0x0c088874 */
if(!s->budget--) { s->failed_pc=0x0c088874u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088876;
P_0c088876: /* original fffb, guest PC 0x0c088876 */
if(!s->budget--) { s->failed_pc=0x0c088876u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c088878;
P_0c088878: /* original ffeb, guest PC 0x0c088878 */
if(!s->budget--) { s->failed_pc=0x0c088878u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c08887a;
P_0c08887a: /* original 9e49, guest PC 0x0c08887a */
if(!s->budget--) { s->failed_pc=0x0c08887au; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c088910u,2);
goto P_0c08887c;
P_0c08887c: /* original 4f22, guest PC 0x0c08887c */
if(!s->budget--) { s->failed_pc=0x0c08887cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08887e;
P_0c08887e: /* original 5a4a, guest PC 0x0c08887e */
if(!s->budget--) { s->failed_pc=0x0c08887eu; return 0; }
r[10]=read(ram,r[4]+40,4);
goto P_0c088880;
P_0c088880: /* original 3e4c, guest PC 0x0c088880 */
if(!s->budget--) { s->failed_pc=0x0c088880u; return 0; }
r[14]+=r[4];
goto P_0c088882;
P_0c088882: /* original d329, guest PC 0x0c088882 */
if(!s->budget--) { s->failed_pc=0x0c088882u; return 0; }
r[3]=read(ram,0x0c088928u,4);
goto P_0c088884;
P_0c088884: /* original 430b, guest PC 0x0c088884 */
if(!s->budget--) { s->failed_pc=0x0c088884u; return 0; }
target=r[3];
r[16]=code_base|0x0c088888u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088888u) { target=s->pc; goto dispatch; }
goto P_0c088888;
P_0c088886: /* original e400, guest PC 0x0c088886 */
if(!s->budget--) { s->failed_pc=0x0c088886u; return 0; }
r[4]=0x00000000u;
goto P_0c088888;
P_0c088888: /* original d228, guest PC 0x0c088888 */
if(!s->budget--) { s->failed_pc=0x0c088888u; return 0; }
r[2]=read(ram,0x0c08892cu,4);
goto P_0c08888a;
P_0c08888a: /* original 420b, guest PC 0x0c08888a */
if(!s->budget--) { s->failed_pc=0x0c08888au; return 0; }
target=r[2];
r[16]=code_base|0x0c08888eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08888eu) { target=s->pc; goto dispatch; }
goto P_0c08888e;
P_0c08888c: /* original 0009, guest PC 0x0c08888c */
if(!s->budget--) { s->failed_pc=0x0c08888cu; return 0; }
goto P_0c08888e;
P_0c08888e: /* original c728, guest PC 0x0c08888e */
if(!s->budget--) { s->failed_pc=0x0c08888eu; return 0; }
r[0]=code_base|0x00088930u;
goto P_0c088890;
P_0c088890: /* original db29, guest PC 0x0c088890 */
if(!s->budget--) { s->failed_pc=0x0c088890u; return 0; }
r[11]=read(ram,0x0c088938u,4);
goto P_0c088892;
P_0c088892: /* original fe08, guest PC 0x0c088892 */
if(!s->budget--) { s->failed_pc=0x0c088892u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c088894;
P_0c088894: /* original c727, guest PC 0x0c088894 */
if(!s->budget--) { s->failed_pc=0x0c088894u; return 0; }
r[0]=code_base|0x00088934u;
goto P_0c088896;
P_0c088896: /* original dc29, guest PC 0x0c088896 */
if(!s->budget--) { s->failed_pc=0x0c088896u; return 0; }
r[12]=read(ram,0x0c08893cu,4);
goto P_0c088898;
P_0c088898: /* original ff08, guest PC 0x0c088898 */
if(!s->budget--) { s->failed_pc=0x0c088898u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08889a;
P_0c08889a: /* original 983b, guest PC 0x0c08889a */
if(!s->budget--) { s->failed_pc=0x0c08889au; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c088914u,2);
goto P_0c08889c;
P_0c08889c: /* original a029, guest PC 0x0c08889c */
if(!s->budget--) { s->failed_pc=0x0c08889cu; return 0; }
r[9]=0x00000002u;
goto P_0c0888f2;
P_0c08889e: /* original e902, guest PC 0x0c08889e */
if(!s->budget--) { s->failed_pc=0x0c08889eu; return 0; }
r[9]=0x00000002u;
goto P_0c0888a0;
P_0c0888a0: /* original e023, guest PC 0x0c0888a0 */
if(!s->budget--) { s->failed_pc=0x0c0888a0u; return 0; }
r[0]=0x00000023u;
goto P_0c0888a2;
P_0c0888a2: /* original 02ec, guest PC 0x0c0888a2 */
if(!s->budget--) { s->failed_pc=0x0c0888a2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0888a4;
P_0c0888a4: /* original 2298, guest PC 0x0c0888a4 */
if(!s->budget--) { s->failed_pc=0x0c0888a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[9])==0)!=0);
goto P_0c0888a6;
P_0c0888a6: /* original 890c, guest PC 0x0c0888a6 */
if(!s->budget--) { s->failed_pc=0x0c0888a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0888c2; }
goto P_0c0888a8;
P_0c0888a8: /* original e020, guest PC 0x0c0888a8 */
if(!s->budget--) { s->failed_pc=0x0c0888a8u; return 0; }
r[0]=0x00000020u;
goto P_0c0888aa;
P_0c0888aa: /* original 0dec, guest PC 0x0c0888aa */
if(!s->budget--) { s->failed_pc=0x0c0888aau; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0888ac;
P_0c0888ac: /* original e310, guest PC 0x0c0888ac */
if(!s->budget--) { s->failed_pc=0x0c0888acu; return 0; }
r[3]=0x00000010u;
goto P_0c0888ae;
P_0c0888ae: /* original 3d33, guest PC 0x0c0888ae */
if(!s->budget--) { s->failed_pc=0x0c0888aeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[3])!=0);
goto P_0c0888b0;
P_0c0888b0: /* original 8b00, guest PC 0x0c0888b0 */
if(!s->budget--) { s->failed_pc=0x0c0888b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0888b4; }
goto P_0c0888b2;
P_0c0888b2: /* original 7dff, guest PC 0x0c0888b2 */
if(!s->budget--) { s->failed_pc=0x0c0888b2u; return 0; }
r[13]+=0xffffffffu;
goto P_0c0888b4;
P_0c0888b4: /* original 3d8c, guest PC 0x0c0888b4 */
if(!s->budget--) { s->failed_pc=0x0c0888b4u; return 0; }
r[13]+=r[8];
goto P_0c0888b6;
P_0c0888b6: /* original 4c0b, guest PC 0x0c0888b6 */
if(!s->budget--) { s->failed_pc=0x0c0888b6u; return 0; }
target=r[12];
r[16]=code_base|0x0c0888bau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0888bau) { target=s->pc; goto dispatch; }
goto P_0c0888ba;
P_0c0888b8: /* original 64e3, guest PC 0x0c0888b8 */
if(!s->budget--) { s->failed_pc=0x0c0888b8u; return 0; }
r[4]=r[14];
goto P_0c0888ba;
P_0c0888ba: /* original 4b0b, guest PC 0x0c0888ba */
if(!s->budget--) { s->failed_pc=0x0c0888bau; return 0; }
target=r[11];
r[16]=code_base|0x0c0888beu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0888beu) { target=s->pc; goto dispatch; }
goto P_0c0888be;
P_0c0888bc: /* original 64d3, guest PC 0x0c0888bc */
if(!s->budget--) { s->failed_pc=0x0c0888bcu; return 0; }
r[4]=r[13];
goto P_0c0888be;
P_0c0888be: /* original a016, guest PC 0x0c0888be */
if(!s->budget--) { s->failed_pc=0x0c0888beu; return 0; }
goto P_0c0888ee;
P_0c0888c0: /* original 0009, guest PC 0x0c0888c0 */
if(!s->budget--) { s->failed_pc=0x0c0888c0u; return 0; }
goto P_0c0888c2;
P_0c0888c2: /* original e004, guest PC 0x0c0888c2 */
if(!s->budget--) { s->failed_pc=0x0c0888c2u; return 0; }
r[0]=0x00000004u;
goto P_0c0888c4;
P_0c0888c4: /* original f3e6, guest PC 0x0c0888c4 */
if(!s->budget--) { s->failed_pc=0x0c0888c4u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0888c6;
P_0c0888c6: /* original f3e0, guest PC 0x0c0888c6 */
if(!s->budget--) { s->failed_pc=0x0c0888c6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'+');
goto P_0c0888c8;
P_0c0888c8: /* original fe37, guest PC 0x0c0888c8 */
if(!s->budget--) { s->failed_pc=0x0c0888c8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0888ca;
P_0c0888ca: /* original 4c0b, guest PC 0x0c0888ca */
if(!s->budget--) { s->failed_pc=0x0c0888cau; return 0; }
target=r[12];
r[16]=code_base|0x0c0888ceu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0888ceu) { target=s->pc; goto dispatch; }
goto P_0c0888ce;
P_0c0888cc: /* original 64e3, guest PC 0x0c0888cc */
if(!s->budget--) { s->failed_pc=0x0c0888ccu; return 0; }
r[4]=r[14];
goto P_0c0888ce;
P_0c0888ce: /* original e004, guest PC 0x0c0888ce */
if(!s->budget--) { s->failed_pc=0x0c0888ceu; return 0; }
r[0]=0x00000004u;
goto P_0c0888d0;
P_0c0888d0: /* original f2e6, guest PC 0x0c0888d0 */
if(!s->budget--) { s->failed_pc=0x0c0888d0u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0888d2;
P_0c0888d2: /* original f2f0, guest PC 0x0c0888d2 */
if(!s->budget--) { s->failed_pc=0x0c0888d2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[15],r[18],'+');
goto P_0c0888d4;
P_0c0888d4: /* original fe27, guest PC 0x0c0888d4 */
if(!s->budget--) { s->failed_pc=0x0c0888d4u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0888d6;
P_0c0888d6: /* original d31a, guest PC 0x0c0888d6 */
if(!s->budget--) { s->failed_pc=0x0c0888d6u; return 0; }
r[3]=read(ram,0x0c088940u,4);
goto P_0c0888d8;
P_0c0888d8: /* original 85ee, guest PC 0x0c0888d8 */
if(!s->budget--) { s->failed_pc=0x0c0888d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+28,2);
goto P_0c0888da;
P_0c0888da: /* original 430b, guest PC 0x0c0888da */
if(!s->budget--) { s->failed_pc=0x0c0888dau; return 0; }
target=r[3];
r[16]=code_base|0x0c0888deu;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0888deu) { target=s->pc; goto dispatch; }
goto P_0c0888de;
P_0c0888dc: /* original 6403, guest PC 0x0c0888dc */
if(!s->budget--) { s->failed_pc=0x0c0888dcu; return 0; }
r[4]=r[0];
goto P_0c0888de;
P_0c0888de: /* original e021, guest PC 0x0c0888de */
if(!s->budget--) { s->failed_pc=0x0c0888deu; return 0; }
r[0]=0x00000021u;
goto P_0c0888e0;
P_0c0888e0: /* original 9319, guest PC 0x0c0888e0 */
if(!s->budget--) { s->failed_pc=0x0c0888e0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c088916u,2);
goto P_0c0888e2;
P_0c0888e2: /* original 04ec, guest PC 0x0c0888e2 */
if(!s->budget--) { s->failed_pc=0x0c0888e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0888e4;
P_0c0888e4: /* original 4b0b, guest PC 0x0c0888e4 */
if(!s->budget--) { s->failed_pc=0x0c0888e4u; return 0; }
target=r[11];
r[16]=code_base|0x0c0888e8u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0888e8u) { target=s->pc; goto dispatch; }
goto P_0c0888e8;
P_0c0888e6: /* original 343c, guest PC 0x0c0888e6 */
if(!s->budget--) { s->failed_pc=0x0c0888e6u; return 0; }
r[4]+=r[3];
goto P_0c0888e8;
P_0c0888e8: /* original d216, guest PC 0x0c0888e8 */
if(!s->budget--) { s->failed_pc=0x0c0888e8u; return 0; }
r[2]=read(ram,0x0c088944u,4);
goto P_0c0888ea;
P_0c0888ea: /* original 420b, guest PC 0x0c0888ea */
if(!s->budget--) { s->failed_pc=0x0c0888eau; return 0; }
target=r[2];
r[16]=code_base|0x0c0888eeu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0888eeu) { target=s->pc; goto dispatch; }
goto P_0c0888ee;
P_0c0888ec: /* original 0009, guest PC 0x0c0888ec */
if(!s->budget--) { s->failed_pc=0x0c0888ecu; return 0; }
goto P_0c0888ee;
P_0c0888ee: /* original 7aff, guest PC 0x0c0888ee */
if(!s->budget--) { s->failed_pc=0x0c0888eeu; return 0; }
r[10]+=0xffffffffu;
goto P_0c0888f0;
P_0c0888f0: /* original 7e24, guest PC 0x0c0888f0 */
if(!s->budget--) { s->failed_pc=0x0c0888f0u; return 0; }
r[14]+=0x00000024u;
goto P_0c0888f2;
P_0c0888f2: /* original 2aa8, guest PC 0x0c0888f2 */
if(!s->budget--) { s->failed_pc=0x0c0888f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0888f4;
P_0c0888f4: /* original 8bd4, guest PC 0x0c0888f4 */
if(!s->budget--) { s->failed_pc=0x0c0888f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0888a0; }
goto P_0c0888f6;
P_0c0888f6: /* original 4f26, guest PC 0x0c0888f6 */
if(!s->budget--) { s->failed_pc=0x0c0888f6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0888f8;
P_0c0888f8: /* original d213, guest PC 0x0c0888f8 */
if(!s->budget--) { s->failed_pc=0x0c0888f8u; return 0; }
r[2]=read(ram,0x0c088948u,4);
goto P_0c0888fa;
P_0c0888fa: /* original e401, guest PC 0x0c0888fa */
if(!s->budget--) { s->failed_pc=0x0c0888fau; return 0; }
r[4]=0x00000001u;
goto P_0c0888fc;
P_0c0888fc: /* original fef9, guest PC 0x0c0888fc */
if(!s->budget--) { s->failed_pc=0x0c0888fcu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0888fe;
P_0c0888fe: /* original fff9, guest PC 0x0c0888fe */
if(!s->budget--) { s->failed_pc=0x0c0888feu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088900;
P_0c088900: /* original 68f6, guest PC 0x0c088900 */
if(!s->budget--) { s->failed_pc=0x0c088900u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c088902;
P_0c088902: /* original 69f6, guest PC 0x0c088902 */
if(!s->budget--) { s->failed_pc=0x0c088902u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c088904;
P_0c088904: /* original 6af6, guest PC 0x0c088904 */
if(!s->budget--) { s->failed_pc=0x0c088904u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c088906;
P_0c088906: /* original 6bf6, guest PC 0x0c088906 */
if(!s->budget--) { s->failed_pc=0x0c088906u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c088908;
P_0c088908: /* original 6cf6, guest PC 0x0c088908 */
if(!s->budget--) { s->failed_pc=0x0c088908u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08890a;
P_0c08890a: /* original 6df6, guest PC 0x0c08890a */
if(!s->budget--) { s->failed_pc=0x0c08890au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08890c;
P_0c08890c: /* original 422b, guest PC 0x0c08890c */
if(!s->budget--) { s->failed_pc=0x0c08890cu; return 0; }
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
P_0c08890e: /* original 6ef6, guest PC 0x0c08890e */
if(!s->budget--) { s->failed_pc=0x0c08890eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c088910u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c088910u; return 0; } return 1;
P_0c08894c: /* original 6543, guest PC 0x0c08894c */
if(!s->budget--) { s->failed_pc=0x0c08894cu; return 0; }
r[5]=r[4];
goto P_0c08894e;
P_0c08894e: /* original 6643, guest PC 0x0c08894e */
if(!s->budget--) { s->failed_pc=0x0c08894eu; return 0; }
r[6]=r[4];
goto P_0c088950;
P_0c088950: /* original e40e, guest PC 0x0c088950 */
if(!s->budget--) { s->failed_pc=0x0c088950u; return 0; }
r[4]=0x0000000eu;
goto P_0c088952;
P_0c088952: /* original e700, guest PC 0x0c088952 */
if(!s->budget--) { s->failed_pc=0x0c088952u; return 0; }
r[7]=0x00000000u;
goto P_0c088954;
P_0c088954: /* original 7508, guest PC 0x0c088954 */
if(!s->budget--) { s->failed_pc=0x0c088954u; return 0; }
r[5]+=0x00000008u;
goto P_0c088956;
P_0c088956: /* original 4410, guest PC 0x0c088956 */
if(!s->budget--) { s->failed_pc=0x0c088956u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c088958;
P_0c088958: /* original 2571, guest PC 0x0c088958 */
if(!s->budget--) { s->failed_pc=0x0c088958u; return 0; }
write(ram,r[5],r[7],2);
goto P_0c08895a;
P_0c08895a: /* original 8ffc, guest PC 0x0c08895a */
if(!s->budget--) { s->failed_pc=0x0c08895au; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(!cond) { goto P_0c088956; }
goto P_0c08895e;
P_0c08895c: /* original 7504, guest PC 0x0c08895c */
if(!s->budget--) { s->failed_pc=0x0c08895cu; return 0; }
r[5]+=0x00000004u;
goto P_0c08895e;
P_0c08895e: /* original e000, guest PC 0x0c08895e */
if(!s->budget--) { s->failed_pc=0x0c08895eu; return 0; }
r[0]=0x00000000u;
goto P_0c088960;
P_0c088960: /* original 8163, guest PC 0x0c088960 */
if(!s->budget--) { s->failed_pc=0x0c088960u; return 0; }
write(ram,r[6]+6,r[0],2);
goto P_0c088962;
P_0c088962: /* original 000b, guest PC 0x0c088962 */
if(!s->budget--) { s->failed_pc=0x0c088962u; return 0; }
target=r[16];
write(ram,r[6]+4,r[0],2);
s->pc=target; return ram->oob==0;
P_0c088964: /* original 8162, guest PC 0x0c088964 */
if(!s->budget--) { s->failed_pc=0x0c088964u; return 0; }
write(ram,r[6]+4,r[0],2);
goto P_0c088966;
P_0c088966: /* original 5544, guest PC 0x0c088966 */
if(!s->budget--) { s->failed_pc=0x0c088966u; return 0; }
r[5]=read(ram,r[4]+16,4);
goto P_0c088968;
P_0c088968: /* original d439, guest PC 0x0c088968 */
if(!s->budget--) { s->failed_pc=0x0c088968u; return 0; }
r[4]=read(ram,0x0c088a50u,4);
goto P_0c08896a;
P_0c08896a: /* original 4508, guest PC 0x0c08896a */
if(!s->budget--) { s->failed_pc=0x0c08896au; return 0; }
r[5]<<=2;
goto P_0c08896c;
P_0c08896c: /* original 4508, guest PC 0x0c08896c */
if(!s->budget--) { s->failed_pc=0x0c08896cu; return 0; }
r[5]<<=2;
goto P_0c08896e;
P_0c08896e: /* original 4508, guest PC 0x0c08896e */
if(!s->budget--) { s->failed_pc=0x0c08896eu; return 0; }
r[5]<<=2;
goto P_0c088970;
P_0c088970: /* original 4500, guest PC 0x0c088970 */
if(!s->budget--) { s->failed_pc=0x0c088970u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c088972;
P_0c088972: /* original 345c, guest PC 0x0c088972 */
if(!s->budget--) { s->failed_pc=0x0c088972u; return 0; }
r[4]+=r[5];
goto P_0c088974;
P_0c088974: /* original 000b, guest PC 0x0c088974 */
if(!s->budget--) { s->failed_pc=0x0c088974u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c088976: /* original 6043, guest PC 0x0c088976 */
if(!s->budget--) { s->failed_pc=0x0c088976u; return 0; }
r[0]=r[4];
goto P_0c088978;
P_0c088978: /* original c736, guest PC 0x0c088978 */
if(!s->budget--) { s->failed_pc=0x0c088978u; return 0; }
r[0]=code_base|0x00088a54u;
goto P_0c08897a;
P_0c08897a: /* original f708, guest PC 0x0c08897a */
if(!s->budget--) { s->failed_pc=0x0c08897au; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c08897c;
P_0c08897c: /* original 9067, guest PC 0x0c08897c */
if(!s->budget--) { s->failed_pc=0x0c08897cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c088a4eu,2);
goto P_0c08897e;
P_0c08897e: /* original f646, guest PC 0x0c08897e */
if(!s->budget--) { s->failed_pc=0x0c08897eu; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c088980;
P_0c088980: /* original 7008, guest PC 0x0c088980 */
if(!s->budget--) { s->failed_pc=0x0c088980u; return 0; }
r[0]+=0x00000008u;
goto P_0c088982;
P_0c088982: /* original f346, guest PC 0x0c088982 */
if(!s->budget--) { s->failed_pc=0x0c088982u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c088984;
P_0c088984: /* original f641, guest PC 0x0c088984 */
if(!s->budget--) { s->failed_pc=0x0c088984u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'-');
goto P_0c088986;
P_0c088986: /* original f34d, guest PC 0x0c088986 */
if(!s->budget--) { s->failed_pc=0x0c088986u; return 0; }
fr[3]^=0x80000000u;
goto P_0c088988;
P_0c088988: /* original f43c, guest PC 0x0c088988 */
if(!s->budget--) { s->failed_pc=0x0c088988u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c08898a;
P_0c08898a: /* original f451, guest PC 0x0c08898a */
if(!s->budget--) { s->failed_pc=0x0c08898au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c08898c;
P_0c08898c: /* original f36c, guest PC 0x0c08898c */
if(!s->budget--) { s->failed_pc=0x0c08898cu; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c08898e;
P_0c08898e: /* original f362, guest PC 0x0c08898e */
if(!s->budget--) { s->failed_pc=0x0c08898eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c088990;
P_0c088990: /* original f04c, guest PC 0x0c088990 */
if(!s->budget--) { s->failed_pc=0x0c088990u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c088992;
P_0c088992: /* original f34e, guest PC 0x0c088992 */
if(!s->budget--) { s->failed_pc=0x0c088992u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c088994;
P_0c088994: /* original f43c, guest PC 0x0c088994 */
if(!s->budget--) { s->failed_pc=0x0c088994u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c088996;
P_0c088996: /* original f475, guest PC 0x0c088996 */
if(!s->budget--) { s->failed_pc=0x0c088996u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[7]))!=0);
goto P_0c088998;
P_0c088998: /* original 890c, guest PC 0x0c088998 */
if(!s->budget--) { s->failed_pc=0x0c088998u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0889b4; }
goto P_0c08899a;
P_0c08899a: /* original 6251, guest PC 0x0c08899a */
if(!s->budget--) { s->failed_pc=0x0c08899au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c08899c;
P_0c08899c: /* original 636d, guest PC 0x0c08899c */
if(!s->budget--) { s->failed_pc=0x0c08899cu; return 0; }
r[3]=r[6]&65535u;
goto P_0c08899e;
P_0c08899e: /* original 622d, guest PC 0x0c08899e */
if(!s->budget--) { s->failed_pc=0x0c08899eu; return 0; }
r[2]=r[2]&65535u;
goto P_0c0889a0;
P_0c0889a0: /* original 2238, guest PC 0x0c0889a0 */
if(!s->budget--) { s->failed_pc=0x0c0889a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0889a2;
P_0c0889a2: /* original 8b07, guest PC 0x0c0889a2 */
if(!s->budget--) { s->failed_pc=0x0c0889a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0889b4; }
goto P_0c0889a4;
P_0c0889a4: /* original d32c, guest PC 0x0c0889a4 */
if(!s->budget--) { s->failed_pc=0x0c0889a4u; return 0; }
r[3]=read(ram,0x0c088a58u,4);
goto P_0c0889a6;
P_0c0889a6: /* original 6432, guest PC 0x0c0889a6 */
if(!s->budget--) { s->failed_pc=0x0c0889a6u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0889a8;
P_0c0889a8: /* original 6042, guest PC 0x0c0889a8 */
if(!s->budget--) { s->failed_pc=0x0c0889a8u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c0889aa;
P_0c0889aa: /* original cb40, guest PC 0x0c0889aa */
if(!s->budget--) { s->failed_pc=0x0c0889aau; return 0; }
r[0]|=64u;
goto P_0c0889ac;
P_0c0889ac: /* original 2402, guest PC 0x0c0889ac */
if(!s->budget--) { s->failed_pc=0x0c0889acu; return 0; }
write(ram,r[4],r[0],4);
goto P_0c0889ae;
P_0c0889ae: /* original 6251, guest PC 0x0c0889ae */
if(!s->budget--) { s->failed_pc=0x0c0889aeu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c0889b0;
P_0c0889b0: /* original 226b, guest PC 0x0c0889b0 */
if(!s->budget--) { s->failed_pc=0x0c0889b0u; return 0; }
r[2]|=r[6];
goto P_0c0889b2;
P_0c0889b2: /* original 2521, guest PC 0x0c0889b2 */
if(!s->budget--) { s->failed_pc=0x0c0889b2u; return 0; }
write(ram,r[5],r[2],2);
goto P_0c0889b4;
P_0c0889b4: /* original 000b, guest PC 0x0c0889b4 */
if(!s->budget--) { s->failed_pc=0x0c0889b4u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0889b6: /* original 0009, guest PC 0x0c0889b6 */
if(!s->budget--) { s->failed_pc=0x0c0889b6u; return 0; }
goto P_0c0889b8;
P_0c0889b8: /* original 2fe6, guest PC 0x0c0889b8 */
if(!s->budget--) { s->failed_pc=0x0c0889b8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0889ba;
P_0c0889ba: /* original 2fd6, guest PC 0x0c0889ba */
if(!s->budget--) { s->failed_pc=0x0c0889bau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0889bc;
P_0c0889bc: /* original 2fc6, guest PC 0x0c0889bc */
if(!s->budget--) { s->failed_pc=0x0c0889bcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0889be;
P_0c0889be: /* original 2fb6, guest PC 0x0c0889be */
if(!s->budget--) { s->failed_pc=0x0c0889beu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0889c0;
P_0c0889c0: /* original 2fa6, guest PC 0x0c0889c0 */
if(!s->budget--) { s->failed_pc=0x0c0889c0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0889c2;
P_0c0889c2: /* original 2f96, guest PC 0x0c0889c2 */
if(!s->budget--) { s->failed_pc=0x0c0889c2u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0889c4;
P_0c0889c4: /* original 2f86, guest PC 0x0c0889c4 */
if(!s->budget--) { s->failed_pc=0x0c0889c4u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0889c6;
P_0c0889c6: /* original fffb, guest PC 0x0c0889c6 */
if(!s->budget--) { s->failed_pc=0x0c0889c6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0889c8;
P_0c0889c8: /* original ffeb, guest PC 0x0c0889c8 */
if(!s->budget--) { s->failed_pc=0x0c0889c8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0889ca;
P_0c0889ca: /* original d125, guest PC 0x0c0889ca */
if(!s->budget--) { s->failed_pc=0x0c0889cau; return 0; }
r[1]=read(ram,0x0c088a60u,4);
goto P_0c0889cc;
P_0c0889cc: /* original 4f22, guest PC 0x0c0889cc */
if(!s->budget--) { s->failed_pc=0x0c0889ccu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0889ce;
P_0c0889ce: /* original 6212, guest PC 0x0c0889ce */
if(!s->budget--) { s->failed_pc=0x0c0889ceu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0889d0;
P_0c0889d0: /* original d322, guest PC 0x0c0889d0 */
if(!s->budget--) { s->failed_pc=0x0c0889d0u; return 0; }
r[3]=read(ram,0x0c088a5cu,4);
goto P_0c0889d2;
P_0c0889d2: /* original 7fe0, guest PC 0x0c0889d2 */
if(!s->budget--) { s->failed_pc=0x0c0889d2u; return 0; }
r[15]+=0xffffffe0u;
goto P_0c0889d4;
P_0c0889d4: /* original 2238, guest PC 0x0c0889d4 */
if(!s->budget--) { s->failed_pc=0x0c0889d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0889d6;
P_0c0889d6: /* original 8d02, guest PC 0x0c0889d6 */
if(!s->budget--) { s->failed_pc=0x0c0889d6u; return 0; }
cond=r[17]&1u;
r[12]=r[4];
if(cond) { goto P_0c0889de; }
goto P_0c0889da;
P_0c0889d8: /* original 6c43, guest PC 0x0c0889d8 */
if(!s->budget--) { s->failed_pc=0x0c0889d8u; return 0; }
r[12]=r[4];
goto P_0c0889da;
P_0c0889da: /* original a0a1, guest PC 0x0c0889da */
if(!s->budget--) { s->failed_pc=0x0c0889dau; return 0; }
goto P_0c088b20;
P_0c0889dc: /* original 0009, guest PC 0x0c0889dc */
if(!s->budget--) { s->failed_pc=0x0c0889dcu; return 0; }
goto P_0c0889de;
P_0c0889de: /* original d123, guest PC 0x0c0889de */
if(!s->budget--) { s->failed_pc=0x0c0889deu; return 0; }
r[1]=read(ram,0x0c088a6cu,4);
goto P_0c0889e0;
P_0c0889e0: /* original d321, guest PC 0x0c0889e0 */
if(!s->budget--) { s->failed_pc=0x0c0889e0u; return 0; }
r[3]=read(ram,0x0c088a68u,4);
goto P_0c0889e2;
P_0c0889e2: /* original 6212, guest PC 0x0c0889e2 */
if(!s->budget--) { s->failed_pc=0x0c0889e2u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0889e4;
P_0c0889e4: /* original de1f, guest PC 0x0c0889e4 */
if(!s->budget--) { s->failed_pc=0x0c0889e4u; return 0; }
r[14]=read(ram,0x0c088a64u,4);
goto P_0c0889e6;
P_0c0889e6: /* original 2238, guest PC 0x0c0889e6 */
if(!s->budget--) { s->failed_pc=0x0c0889e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0889e8;
P_0c0889e8: /* original 890b, guest PC 0x0c0889e8 */
if(!s->budget--) { s->failed_pc=0x0c0889e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088a02; }
goto P_0c0889ea;
P_0c0889ea: /* original bfaf, guest PC 0x0c0889ea */
if(!s->budget--) { s->failed_pc=0x0c0889eau; return 0; }
target=code_base|0x0c08894cu; r[16]=code_base|0x0c0889eeu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0889eeu) { target=s->pc; goto dispatch; }
goto P_0c0889ee;
P_0c0889ec: /* original 0009, guest PC 0x0c0889ec */
if(!s->budget--) { s->failed_pc=0x0c0889ecu; return 0; }
goto P_0c0889ee;
P_0c0889ee: /* original e054, guest PC 0x0c0889ee */
if(!s->budget--) { s->failed_pc=0x0c0889eeu; return 0; }
r[0]=0x00000054u;
goto P_0c0889f0;
P_0c0889f0: /* original bfb9, guest PC 0x0c0889f0 */
if(!s->budget--) { s->failed_pc=0x0c0889f0u; return 0; }
target=code_base|0x0c088966u; r[16]=code_base|0x0c0889f4u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0889f4u) { target=s->pc; goto dispatch; }
goto P_0c0889f4;
P_0c0889f2: /* original 04ee, guest PC 0x0c0889f2 */
if(!s->budget--) { s->failed_pc=0x0c0889f2u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0889f4;
P_0c0889f4: /* original 6403, guest PC 0x0c0889f4 */
if(!s->budget--) { s->failed_pc=0x0c0889f4u; return 0; }
r[4]=r[0];
goto P_0c0889f6;
P_0c0889f6: /* original e034, guest PC 0x0c0889f6 */
if(!s->budget--) { s->failed_pc=0x0c0889f6u; return 0; }
r[0]=0x00000034u;
goto P_0c0889f8;
P_0c0889f8: /* original 004d, guest PC 0x0c0889f8 */
if(!s->budget--) { s->failed_pc=0x0c0889f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0889fa;
P_0c0889fa: /* original 81c2, guest PC 0x0c0889fa */
if(!s->budget--) { s->failed_pc=0x0c0889fau; return 0; }
write(ram,r[12]+4,r[0],2);
goto P_0c0889fc;
P_0c0889fc: /* original e036, guest PC 0x0c0889fc */
if(!s->budget--) { s->failed_pc=0x0c0889fcu; return 0; }
r[0]=0x00000036u;
goto P_0c0889fe;
P_0c0889fe: /* original 004d, guest PC 0x0c0889fe */
if(!s->budget--) { s->failed_pc=0x0c0889feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c088a00;
P_0c088a00: /* original 81c3, guest PC 0x0c088a00 */
if(!s->budget--) { s->failed_pc=0x0c088a00u; return 0; }
write(ram,r[12]+6,r[0],2);
goto P_0c088a02;
P_0c088a02: /* original d31b, guest PC 0x0c088a02 */
if(!s->budget--) { s->failed_pc=0x0c088a02u; return 0; }
r[3]=read(ram,0x0c088a70u,4);
goto P_0c088a04;
P_0c088a04: /* original 6430, guest PC 0x0c088a04 */
if(!s->budget--) { s->failed_pc=0x0c088a04u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[4]=tmp;
goto P_0c088a06;
P_0c088a06: /* original 604c, guest PC 0x0c088a06 */
if(!s->budget--) { s->failed_pc=0x0c088a06u; return 0; }
r[0]=r[4]&255u;
goto P_0c088a08;
P_0c088a08: /* original 8809, guest PC 0x0c088a08 */
if(!s->budget--) { s->failed_pc=0x0c088a08u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c088a0a;
P_0c088a0a: /* original 8d08, guest PC 0x0c088a0a */
if(!s->budget--) { s->failed_pc=0x0c088a0au; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c088a1e; }
goto P_0c088a0e;
P_0c088a0c: /* original 6403, guest PC 0x0c088a0c */
if(!s->budget--) { s->failed_pc=0x0c088a0cu; return 0; }
r[4]=r[0];
goto P_0c088a0e;
P_0c088a0e: /* original 6043, guest PC 0x0c088a0e */
if(!s->budget--) { s->failed_pc=0x0c088a0eu; return 0; }
r[0]=r[4];
goto P_0c088a10;
P_0c088a10: /* original 880d, guest PC 0x0c088a10 */
if(!s->budget--) { s->failed_pc=0x0c088a10u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c088a12;
P_0c088a12: /* original 8904, guest PC 0x0c088a12 */
if(!s->budget--) { s->failed_pc=0x0c088a12u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088a1e; }
goto P_0c088a14;
P_0c088a14: /* original 6043, guest PC 0x0c088a14 */
if(!s->budget--) { s->failed_pc=0x0c088a14u; return 0; }
r[0]=r[4];
goto P_0c088a16;
P_0c088a16: /* original 880b, guest PC 0x0c088a16 */
if(!s->budget--) { s->failed_pc=0x0c088a16u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c088a18;
P_0c088a18: /* original 8901, guest PC 0x0c088a18 */
if(!s->budget--) { s->failed_pc=0x0c088a18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088a1e; }
goto P_0c088a1a;
P_0c088a1a: /* original a081, guest PC 0x0c088a1a */
if(!s->budget--) { s->failed_pc=0x0c088a1au; return 0; }
goto P_0c088b20;
P_0c088a1c: /* original 0009, guest PC 0x0c088a1c */
if(!s->budget--) { s->failed_pc=0x0c088a1cu; return 0; }
goto P_0c088a1e;
P_0c088a1e: /* original e30e, guest PC 0x0c088a1e */
if(!s->budget--) { s->failed_pc=0x0c088a1eu; return 0; }
r[3]=0x0000000eu;
goto P_0c088a20;
P_0c088a20: /* original 68c3, guest PC 0x0c088a20 */
if(!s->budget--) { s->failed_pc=0x0c088a20u; return 0; }
r[8]=r[12];
goto P_0c088a22;
P_0c088a22: /* original e048, guest PC 0x0c088a22 */
if(!s->budget--) { s->failed_pc=0x0c088a22u; return 0; }
r[0]=0x00000048u;
goto P_0c088a24;
P_0c088a24: /* original 1f33, guest PC 0x0c088a24 */
if(!s->budget--) { s->failed_pc=0x0c088a24u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c088a26;
P_0c088a26: /* original 54e4, guest PC 0x0c088a26 */
if(!s->budget--) { s->failed_pc=0x0c088a26u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c088a28;
P_0c088a28: /* original ed01, guest PC 0x0c088a28 */
if(!s->budget--) { s->failed_pc=0x0c088a28u; return 0; }
r[13]=0x00000001u;
goto P_0c088a2a;
P_0c088a2a: /* original 7808, guest PC 0x0c088a2a */
if(!s->budget--) { s->failed_pc=0x0c088a2au; return 0; }
r[8]+=0x00000008u;
goto P_0c088a2c;
P_0c088a2c: /* original 034e, guest PC 0x0c088a2c */
if(!s->budget--) { s->failed_pc=0x0c088a2cu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c088a2e;
P_0c088a2e: /* original e048, guest PC 0x0c088a2e */
if(!s->budget--) { s->failed_pc=0x0c088a2eu; return 0; }
r[0]=0x00000048u;
goto P_0c088a30;
P_0c088a30: /* original 1f35, guest PC 0x0c088a30 */
if(!s->budget--) { s->failed_pc=0x0c088a30u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c088a32;
P_0c088a32: /* original 6242, guest PC 0x0c088a32 */
if(!s->budget--) { s->failed_pc=0x0c088a32u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c088a34;
P_0c088a34: /* original 1f26, guest PC 0x0c088a34 */
if(!s->budget--) { s->failed_pc=0x0c088a34u; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c088a36;
P_0c088a36: /* original 54e5, guest PC 0x0c088a36 */
if(!s->budget--) { s->failed_pc=0x0c088a36u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c088a38;
P_0c088a38: /* original 034e, guest PC 0x0c088a38 */
if(!s->budget--) { s->failed_pc=0x0c088a38u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c088a3a;
P_0c088a3a: /* original 1f34, guest PC 0x0c088a3a */
if(!s->budget--) { s->failed_pc=0x0c088a3au; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c088a3c;
P_0c088a3c: /* original 6242, guest PC 0x0c088a3c */
if(!s->budget--) { s->failed_pc=0x0c088a3cu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c088a3e;
P_0c088a3e: /* original 1f27, guest PC 0x0c088a3e */
if(!s->budget--) { s->failed_pc=0x0c088a3eu; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c088a40;
P_0c088a40: /* original d30c, guest PC 0x0c088a40 */
if(!s->budget--) { s->failed_pc=0x0c088a40u; return 0; }
r[3]=read(ram,0x0c088a74u,4);
goto P_0c088a42;
P_0c088a42: /* original 1f32, guest PC 0x0c088a42 */
if(!s->budget--) { s->failed_pc=0x0c088a42u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c088a44;
P_0c088a44: /* original 85c2, guest PC 0x0c088a44 */
if(!s->budget--) { s->failed_pc=0x0c088a44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+4,2);
goto P_0c088a46;
P_0c088a46: /* original 2f01, guest PC 0x0c088a46 */
if(!s->budget--) { s->failed_pc=0x0c088a46u; return 0; }
write(ram,r[15],r[0],2);
goto P_0c088a48;
P_0c088a48: /* original 85c3, guest PC 0x0c088a48 */
if(!s->budget--) { s->failed_pc=0x0c088a48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+6,2);
goto P_0c088a4a;
P_0c088a4a: /* original a057, guest PC 0x0c088a4a */
if(!s->budget--) { s->failed_pc=0x0c088a4au; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c088afc;
P_0c088a4c: /* original 81f2, guest PC 0x0c088a4c */
if(!s->budget--) { s->failed_pc=0x0c088a4cu; return 0; }
write(ram,r[15]+4,r[0],2);
if(!vf3_matrix_family(0x0c088a4eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c088a4eu; return 0; } return 1;
P_0c088a78: /* original 51f2, guest PC 0x0c088a78 */
if(!s->budget--) { s->failed_pc=0x0c088a78u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c088a7a;
P_0c088a7a: /* original 7104, guest PC 0x0c088a7a */
if(!s->budget--) { s->failed_pc=0x0c088a7au; return 0; }
r[1]+=0x00000004u;
goto P_0c088a7c;
P_0c088a7c: /* original 1f12, guest PC 0x0c088a7c */
if(!s->budget--) { s->failed_pc=0x0c088a7cu; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c088a7e;
P_0c088a7e: /* original 71fc, guest PC 0x0c088a7e */
if(!s->budget--) { s->failed_pc=0x0c088a7eu; return 0; }
r[1]+=0xfffffffcu;
goto P_0c088a80;
P_0c088a80: /* original 53f2, guest PC 0x0c088a80 */
if(!s->budget--) { s->failed_pc=0x0c088a80u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c088a82;
P_0c088a82: /* original fe18, guest PC 0x0c088a82 */
if(!s->budget--) { s->failed_pc=0x0c088a82u; return 0; }
vf3_matrix_load(s,ram,14,r[1]);
goto P_0c088a84;
P_0c088a84: /* original 7304, guest PC 0x0c088a84 */
if(!s->budget--) { s->failed_pc=0x0c088a84u; return 0; }
r[3]+=0x00000004u;
goto P_0c088a86;
P_0c088a86: /* original 6233, guest PC 0x0c088a86 */
if(!s->budget--) { s->failed_pc=0x0c088a86u; return 0; }
r[2]=r[3];
goto P_0c088a88;
P_0c088a88: /* original 7204, guest PC 0x0c088a88 */
if(!s->budget--) { s->failed_pc=0x0c088a88u; return 0; }
r[2]+=0x00000004u;
goto P_0c088a8a;
P_0c088a8a: /* original 1f22, guest PC 0x0c088a8a */
if(!s->budget--) { s->failed_pc=0x0c088a8au; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c088a8c;
P_0c088a8c: /* original 72fc, guest PC 0x0c088a8c */
if(!s->budget--) { s->failed_pc=0x0c088a8cu; return 0; }
r[2]+=0xfffffffcu;
goto P_0c088a8e;
P_0c088a8e: /* original 53f5, guest PC 0x0c088a8e */
if(!s->budget--) { s->failed_pc=0x0c088a8eu; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c088a90;
P_0c088a90: /* original 9b52, guest PC 0x0c088a90 */
if(!s->budget--) { s->failed_pc=0x0c088a90u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c088b38u,2);
goto P_0c088a92;
P_0c088a92: /* original da2b, guest PC 0x0c088a92 */
if(!s->budget--) { s->failed_pc=0x0c088a92u; return 0; }
r[10]=read(ram,0x0c088b40u,4);
goto P_0c088a94;
P_0c088a94: /* original ff28, guest PC 0x0c088a94 */
if(!s->budget--) { s->failed_pc=0x0c088a94u; return 0; }
vf3_matrix_load(s,ram,15,r[2]);
goto P_0c088a96;
P_0c088a96: /* original 23b8, guest PC 0x0c088a96 */
if(!s->budget--) { s->failed_pc=0x0c088a96u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c088a98;
P_0c088a98: /* original d928, guest PC 0x0c088a98 */
if(!s->budget--) { s->failed_pc=0x0c088a98u; return 0; }
r[9]=read(ram,0x0c088b3cu,4);
goto P_0c088a9a;
P_0c088a9a: /* original 8b02, guest PC 0x0c088a9a */
if(!s->budget--) { s->failed_pc=0x0c088a9au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c088aa2; }
goto P_0c088a9c;
P_0c088a9c: /* original 52f5, guest PC 0x0c088a9c */
if(!s->budget--) { s->failed_pc=0x0c088a9cu; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c088a9e;
P_0c088a9e: /* original 22a8, guest PC 0x0c088a9e */
if(!s->budget--) { s->failed_pc=0x0c088a9eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[10])==0)!=0);
goto P_0c088aa0;
P_0c088aa0: /* original 8908, guest PC 0x0c088aa0 */
if(!s->budget--) { s->failed_pc=0x0c088aa0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088ab4; }
goto P_0c088aa2;
P_0c088aa2: /* original 53f6, guest PC 0x0c088aa2 */
if(!s->budget--) { s->failed_pc=0x0c088aa2u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c088aa4;
P_0c088aa4: /* original 2398, guest PC 0x0c088aa4 */
if(!s->budget--) { s->failed_pc=0x0c088aa4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c088aa6;
P_0c088aa6: /* original 8905, guest PC 0x0c088aa6 */
if(!s->budget--) { s->failed_pc=0x0c088aa6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088ab4; }
goto P_0c088aa8;
P_0c088aa8: /* original f5fc, guest PC 0x0c088aa8 */
if(!s->budget--) { s->failed_pc=0x0c088aa8u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c088aaa;
P_0c088aaa: /* original 66d3, guest PC 0x0c088aaa */
if(!s->budget--) { s->failed_pc=0x0c088aaau; return 0; }
r[6]=r[13];
goto P_0c088aac;
P_0c088aac: /* original f4ec, guest PC 0x0c088aac */
if(!s->budget--) { s->failed_pc=0x0c088aacu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c088aae;
P_0c088aae: /* original 65f3, guest PC 0x0c088aae */
if(!s->budget--) { s->failed_pc=0x0c088aaeu; return 0; }
r[5]=r[15];
goto P_0c088ab0;
P_0c088ab0: /* original bf62, guest PC 0x0c088ab0 */
if(!s->budget--) { s->failed_pc=0x0c088ab0u; return 0; }
target=code_base|0x0c088978u; r[16]=code_base|0x0c088ab4u;
r[4]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088ab4u) { target=s->pc; goto dispatch; }
goto P_0c088ab4;
P_0c088ab2: /* original 54e4, guest PC 0x0c088ab2 */
if(!s->budget--) { s->failed_pc=0x0c088ab2u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c088ab4;
P_0c088ab4: /* original 52f4, guest PC 0x0c088ab4 */
if(!s->budget--) { s->failed_pc=0x0c088ab4u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c088ab6;
P_0c088ab6: /* original 2b28, guest PC 0x0c088ab6 */
if(!s->budget--) { s->failed_pc=0x0c088ab6u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[2])==0)!=0);
goto P_0c088ab8;
P_0c088ab8: /* original 8b02, guest PC 0x0c088ab8 */
if(!s->budget--) { s->failed_pc=0x0c088ab8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c088ac0; }
goto P_0c088aba;
P_0c088aba: /* original 53f4, guest PC 0x0c088aba */
if(!s->budget--) { s->failed_pc=0x0c088abau; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c088abc;
P_0c088abc: /* original 2a38, guest PC 0x0c088abc */
if(!s->budget--) { s->failed_pc=0x0c088abcu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[3])==0)!=0);
goto P_0c088abe;
P_0c088abe: /* original 8908, guest PC 0x0c088abe */
if(!s->budget--) { s->failed_pc=0x0c088abeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088ad2; }
goto P_0c088ac0;
P_0c088ac0: /* original 52f7, guest PC 0x0c088ac0 */
if(!s->budget--) { s->failed_pc=0x0c088ac0u; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c088ac2;
P_0c088ac2: /* original 2928, guest PC 0x0c088ac2 */
if(!s->budget--) { s->failed_pc=0x0c088ac2u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[2])==0)!=0);
goto P_0c088ac4;
P_0c088ac4: /* original 8905, guest PC 0x0c088ac4 */
if(!s->budget--) { s->failed_pc=0x0c088ac4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088ad2; }
goto P_0c088ac6;
P_0c088ac6: /* original f5fc, guest PC 0x0c088ac6 */
if(!s->budget--) { s->failed_pc=0x0c088ac6u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c088ac8;
P_0c088ac8: /* original 66d3, guest PC 0x0c088ac8 */
if(!s->budget--) { s->failed_pc=0x0c088ac8u; return 0; }
r[6]=r[13];
goto P_0c088aca;
P_0c088aca: /* original f4ec, guest PC 0x0c088aca */
if(!s->budget--) { s->failed_pc=0x0c088acau; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c088acc;
P_0c088acc: /* original 65f3, guest PC 0x0c088acc */
if(!s->budget--) { s->failed_pc=0x0c088accu; return 0; }
r[5]=r[15];
goto P_0c088ace;
P_0c088ace: /* original bf53, guest PC 0x0c088ace */
if(!s->budget--) { s->failed_pc=0x0c088aceu; return 0; }
target=code_base|0x0c088978u; r[16]=code_base|0x0c088ad2u;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088ad2u) { target=s->pc; goto dispatch; }
goto P_0c088ad2;
P_0c088ad0: /* original 54e5, guest PC 0x0c088ad0 */
if(!s->budget--) { s->failed_pc=0x0c088ad0u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c088ad2;
P_0c088ad2: /* original 62f1, guest PC 0x0c088ad2 */
if(!s->budget--) { s->failed_pc=0x0c088ad2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[2]=tmp;
goto P_0c088ad4;
P_0c088ad4: /* original 63dd, guest PC 0x0c088ad4 */
if(!s->budget--) { s->failed_pc=0x0c088ad4u; return 0; }
r[3]=r[13]&65535u;
goto P_0c088ad6;
P_0c088ad6: /* original 622d, guest PC 0x0c088ad6 */
if(!s->budget--) { s->failed_pc=0x0c088ad6u; return 0; }
r[2]=r[2]&65535u;
goto P_0c088ad8;
P_0c088ad8: /* original 2238, guest PC 0x0c088ad8 */
if(!s->budget--) { s->failed_pc=0x0c088ad8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c088ada;
P_0c088ada: /* original 8d0a, guest PC 0x0c088ada */
if(!s->budget--) { s->failed_pc=0x0c088adau; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[4]=tmp;
if(cond) { goto P_0c088af2; }
goto P_0c088ade;
P_0c088adc: /* original 6481, guest PC 0x0c088adc */
if(!s->budget--) { s->failed_pc=0x0c088adcu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[4]=tmp;
goto P_0c088ade;
P_0c088ade: /* original 634f, guest PC 0x0c088ade */
if(!s->budget--) { s->failed_pc=0x0c088adeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c088ae0;
P_0c088ae0: /* original e510, guest PC 0x0c088ae0 */
if(!s->budget--) { s->failed_pc=0x0c088ae0u; return 0; }
r[5]=0x00000010u;
goto P_0c088ae2;
P_0c088ae2: /* original 3353, guest PC 0x0c088ae2 */
if(!s->budget--) { s->failed_pc=0x0c088ae2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[5])!=0);
goto P_0c088ae4;
P_0c088ae4: /* original 8902, guest PC 0x0c088ae4 */
if(!s->budget--) { s->failed_pc=0x0c088ae4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088aec; }
goto P_0c088ae6;
P_0c088ae6: /* original 7401, guest PC 0x0c088ae6 */
if(!s->budget--) { s->failed_pc=0x0c088ae6u; return 0; }
r[4]+=0x00000001u;
goto P_0c088ae8;
P_0c088ae8: /* original a003, guest PC 0x0c088ae8 */
if(!s->budget--) { s->failed_pc=0x0c088ae8u; return 0; }
write(ram,r[8],r[4],2);
goto P_0c088af2;
P_0c088aea: /* original 2841, guest PC 0x0c088aea */
if(!s->budget--) { s->failed_pc=0x0c088aeau; return 0; }
write(ram,r[8],r[4],2);
goto P_0c088aec;
P_0c088aec: /* original 85f2, guest PC 0x0c088aec */
if(!s->budget--) { s->failed_pc=0x0c088aecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c088aee;
P_0c088aee: /* original 20db, guest PC 0x0c088aee */
if(!s->budget--) { s->failed_pc=0x0c088aeeu; return 0; }
r[0]|=r[13];
goto P_0c088af0;
P_0c088af0: /* original 81f2, guest PC 0x0c088af0 */
if(!s->budget--) { s->failed_pc=0x0c088af0u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c088af2;
P_0c088af2: /* original 53f3, guest PC 0x0c088af2 */
if(!s->budget--) { s->failed_pc=0x0c088af2u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c088af4;
P_0c088af4: /* original 7804, guest PC 0x0c088af4 */
if(!s->budget--) { s->failed_pc=0x0c088af4u; return 0; }
r[8]+=0x00000004u;
goto P_0c088af6;
P_0c088af6: /* original 4d00, guest PC 0x0c088af6 */
if(!s->budget--) { s->failed_pc=0x0c088af6u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c088af8;
P_0c088af8: /* original 73ff, guest PC 0x0c088af8 */
if(!s->budget--) { s->failed_pc=0x0c088af8u; return 0; }
r[3]+=0xffffffffu;
goto P_0c088afa;
P_0c088afa: /* original 1f33, guest PC 0x0c088afa */
if(!s->budget--) { s->failed_pc=0x0c088afau; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c088afc;
P_0c088afc: /* original 52f3, guest PC 0x0c088afc */
if(!s->budget--) { s->failed_pc=0x0c088afcu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c088afe;
P_0c088afe: /* original 2228, guest PC 0x0c088afe */
if(!s->budget--) { s->failed_pc=0x0c088afeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c088b00;
P_0c088b00: /* original 8bba, guest PC 0x0c088b00 */
if(!s->budget--) { s->failed_pc=0x0c088b00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c088a78; }
goto P_0c088b02;
P_0c088b02: /* original 60f1, guest PC 0x0c088b02 */
if(!s->budget--) { s->failed_pc=0x0c088b02u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[0]=tmp;
goto P_0c088b04;
P_0c088b04: /* original 81c2, guest PC 0x0c088b04 */
if(!s->budget--) { s->failed_pc=0x0c088b04u; return 0; }
write(ram,r[12]+4,r[0],2);
goto P_0c088b06;
P_0c088b06: /* original 85f2, guest PC 0x0c088b06 */
if(!s->budget--) { s->failed_pc=0x0c088b06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c088b08;
P_0c088b08: /* original 81c3, guest PC 0x0c088b08 */
if(!s->budget--) { s->failed_pc=0x0c088b08u; return 0; }
write(ram,r[12]+6,r[0],2);
goto P_0c088b0a;
P_0c088b0a: /* original e050, guest PC 0x0c088b0a */
if(!s->budget--) { s->failed_pc=0x0c088b0au; return 0; }
r[0]=0x00000050u;
goto P_0c088b0c;
P_0c088b0c: /* original bf2b, guest PC 0x0c088b0c */
if(!s->budget--) { s->failed_pc=0x0c088b0cu; return 0; }
target=code_base|0x0c088966u; r[16]=code_base|0x0c088b10u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088b10u) { target=s->pc; goto dispatch; }
goto P_0c088b10;
P_0c088b0e: /* original 04ee, guest PC 0x0c088b0e */
if(!s->budget--) { s->failed_pc=0x0c088b0eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c088b10;
P_0c088b10: /* original 62f1, guest PC 0x0c088b10 */
if(!s->budget--) { s->failed_pc=0x0c088b10u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[2]=tmp;
goto P_0c088b12;
P_0c088b12: /* original 6403, guest PC 0x0c088b12 */
if(!s->budget--) { s->failed_pc=0x0c088b12u; return 0; }
r[4]=r[0];
goto P_0c088b14;
P_0c088b14: /* original e034, guest PC 0x0c088b14 */
if(!s->budget--) { s->failed_pc=0x0c088b14u; return 0; }
r[0]=0x00000034u;
goto P_0c088b16;
P_0c088b16: /* original 0425, guest PC 0x0c088b16 */
if(!s->budget--) { s->failed_pc=0x0c088b16u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c088b18;
P_0c088b18: /* original e136, guest PC 0x0c088b18 */
if(!s->budget--) { s->failed_pc=0x0c088b18u; return 0; }
r[1]=0x00000036u;
goto P_0c088b1a;
P_0c088b1a: /* original 85f2, guest PC 0x0c088b1a */
if(!s->budget--) { s->failed_pc=0x0c088b1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c088b1c;
P_0c088b1c: /* original 314c, guest PC 0x0c088b1c */
if(!s->budget--) { s->failed_pc=0x0c088b1cu; return 0; }
r[1]+=r[4];
goto P_0c088b1e;
P_0c088b1e: /* original 2101, guest PC 0x0c088b1e */
if(!s->budget--) { s->failed_pc=0x0c088b1eu; return 0; }
write(ram,r[1],r[0],2);
goto P_0c088b20;
P_0c088b20: /* original 7f20, guest PC 0x0c088b20 */
if(!s->budget--) { s->failed_pc=0x0c088b20u; return 0; }
r[15]+=0x00000020u;
goto P_0c088b22;
P_0c088b22: /* original 4f26, guest PC 0x0c088b22 */
if(!s->budget--) { s->failed_pc=0x0c088b22u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c088b24;
P_0c088b24: /* original fef9, guest PC 0x0c088b24 */
if(!s->budget--) { s->failed_pc=0x0c088b24u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088b26;
P_0c088b26: /* original fff9, guest PC 0x0c088b26 */
if(!s->budget--) { s->failed_pc=0x0c088b26u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088b28;
P_0c088b28: /* original 68f6, guest PC 0x0c088b28 */
if(!s->budget--) { s->failed_pc=0x0c088b28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c088b2a;
P_0c088b2a: /* original 69f6, guest PC 0x0c088b2a */
if(!s->budget--) { s->failed_pc=0x0c088b2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c088b2c;
P_0c088b2c: /* original 6af6, guest PC 0x0c088b2c */
if(!s->budget--) { s->failed_pc=0x0c088b2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c088b2e;
P_0c088b2e: /* original 6bf6, guest PC 0x0c088b2e */
if(!s->budget--) { s->failed_pc=0x0c088b2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c088b30;
P_0c088b30: /* original 6cf6, guest PC 0x0c088b30 */
if(!s->budget--) { s->failed_pc=0x0c088b30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c088b32;
P_0c088b32: /* original 6df6, guest PC 0x0c088b32 */
if(!s->budget--) { s->failed_pc=0x0c088b32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c088b34;
P_0c088b34: /* original 000b, guest PC 0x0c088b34 */
if(!s->budget--) { s->failed_pc=0x0c088b34u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c088b36: /* original 6ef6, guest PC 0x0c088b36 */
if(!s->budget--) { s->failed_pc=0x0c088b36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c088b38u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c088b38u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
