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
int vf3_away_batch24_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0baf16u: goto P_0c0baf16;
case 0x0c0baf18u: goto P_0c0baf18;
case 0x0c0baf1au: goto P_0c0baf1a;
case 0x0c0baf1cu: goto P_0c0baf1c;
case 0x0c0baf1eu: goto P_0c0baf1e;
case 0x0c0baf20u: goto P_0c0baf20;
case 0x0c0baf22u: goto P_0c0baf22;
case 0x0c0baf24u: goto P_0c0baf24;
case 0x0c0baf26u: goto P_0c0baf26;
case 0x0c0baf28u: goto P_0c0baf28;
case 0x0c0baf2au: goto P_0c0baf2a;
case 0x0c0baf2cu: goto P_0c0baf2c;
case 0x0c0baf2eu: goto P_0c0baf2e;
case 0x0c0baf30u: goto P_0c0baf30;
case 0x0c0baf32u: goto P_0c0baf32;
case 0x0c0baf34u: goto P_0c0baf34;
case 0x0c0baf36u: goto P_0c0baf36;
case 0x0c0baf38u: goto P_0c0baf38;
case 0x0c0baf3au: goto P_0c0baf3a;
case 0x0c0baf3cu: goto P_0c0baf3c;
case 0x0c0baf3eu: goto P_0c0baf3e;
case 0x0c0baf40u: goto P_0c0baf40;
case 0x0c0baf42u: goto P_0c0baf42;
case 0x0c0baf44u: goto P_0c0baf44;
case 0x0c0baf46u: goto P_0c0baf46;
case 0x0c0baf48u: goto P_0c0baf48;
case 0x0c0baf4au: goto P_0c0baf4a;
case 0x0c0baf4cu: goto P_0c0baf4c;
case 0x0c0baf4eu: goto P_0c0baf4e;
case 0x0c0baf50u: goto P_0c0baf50;
case 0x0c0baf52u: goto P_0c0baf52;
case 0x0c0baf54u: goto P_0c0baf54;
case 0x0c0baf56u: goto P_0c0baf56;
case 0x0c0baf58u: goto P_0c0baf58;
case 0x0c0baf5au: goto P_0c0baf5a;
case 0x0c0baf5cu: goto P_0c0baf5c;
case 0x0c0baf5eu: goto P_0c0baf5e;
case 0x0c0baf60u: goto P_0c0baf60;
case 0x0c0baf62u: goto P_0c0baf62;
case 0x0c0baf64u: goto P_0c0baf64;
case 0x0c0baf66u: goto P_0c0baf66;
case 0x0c0baf68u: goto P_0c0baf68;
case 0x0c0baf6au: goto P_0c0baf6a;
case 0x0c0baf6cu: goto P_0c0baf6c;
case 0x0c0baf6eu: goto P_0c0baf6e;
case 0x0c0baf70u: goto P_0c0baf70;
case 0x0c0baf72u: goto P_0c0baf72;
case 0x0c0baf74u: goto P_0c0baf74;
case 0x0c0baf76u: goto P_0c0baf76;
case 0x0c0baf78u: goto P_0c0baf78;
case 0x0c0baf7au: goto P_0c0baf7a;
case 0x0c0baf7cu: goto P_0c0baf7c;
case 0x0c0baf7eu: goto P_0c0baf7e;
case 0x0c0baf80u: goto P_0c0baf80;
case 0x0c0baf82u: goto P_0c0baf82;
case 0x0c0baf84u: goto P_0c0baf84;
case 0x0c0baf86u: goto P_0c0baf86;
case 0x0c0baf88u: goto P_0c0baf88;
case 0x0c0baf8au: goto P_0c0baf8a;
case 0x0c0baf8cu: goto P_0c0baf8c;
case 0x0c0baf8eu: goto P_0c0baf8e;
case 0x0c0baf90u: goto P_0c0baf90;
case 0x0c0baf92u: goto P_0c0baf92;
case 0x0c0baf94u: goto P_0c0baf94;
case 0x0c0baf96u: goto P_0c0baf96;
case 0x0c0baf98u: goto P_0c0baf98;
case 0x0c0baf9au: goto P_0c0baf9a;
case 0x0c0baf9cu: goto P_0c0baf9c;
case 0x0c0baf9eu: goto P_0c0baf9e;
case 0x0c0bafa0u: goto P_0c0bafa0;
case 0x0c0bafa2u: goto P_0c0bafa2;
case 0x0c0bafa4u: goto P_0c0bafa4;
case 0x0c0bafa6u: goto P_0c0bafa6;
case 0x0c0bafa8u: goto P_0c0bafa8;
case 0x0c0bafaau: goto P_0c0bafaa;
case 0x0c0bafacu: goto P_0c0bafac;
case 0x0c0bafaeu: goto P_0c0bafae;
case 0x0c0bafb0u: goto P_0c0bafb0;
case 0x0c0bafb2u: goto P_0c0bafb2;
case 0x0c0bafb4u: goto P_0c0bafb4;
case 0x0c0bafb6u: goto P_0c0bafb6;
case 0x0c0bafb8u: goto P_0c0bafb8;
case 0x0c0bafbau: goto P_0c0bafba;
case 0x0c0bafbcu: goto P_0c0bafbc;
case 0x0c0bafbeu: goto P_0c0bafbe;
case 0x0c0bafc0u: goto P_0c0bafc0;
case 0x0c0bafc2u: goto P_0c0bafc2;
case 0x0c0bafc4u: goto P_0c0bafc4;
case 0x0c0bafc6u: goto P_0c0bafc6;
case 0x0c0bafc8u: goto P_0c0bafc8;
case 0x0c0bafcau: goto P_0c0bafca;
case 0x0c0bafccu: goto P_0c0bafcc;
case 0x0c0bafceu: goto P_0c0bafce;
case 0x0c0bafd0u: goto P_0c0bafd0;
case 0x0c0bafd2u: goto P_0c0bafd2;
case 0x0c0bafd4u: goto P_0c0bafd4;
case 0x0c0bafd6u: goto P_0c0bafd6;
case 0x0c0bafd8u: goto P_0c0bafd8;
case 0x0c0bafdau: goto P_0c0bafda;
case 0x0c0bafdcu: goto P_0c0bafdc;
case 0x0c0bafdeu: goto P_0c0bafde;
case 0x0c0bafe0u: goto P_0c0bafe0;
case 0x0c0bafe2u: goto P_0c0bafe2;
case 0x0c0bafe4u: goto P_0c0bafe4;
case 0x0c0bafe6u: goto P_0c0bafe6;
case 0x0c0bafe8u: goto P_0c0bafe8;
case 0x0c0bafeau: goto P_0c0bafea;
case 0x0c0bafecu: goto P_0c0bafec;
case 0x0c0bafeeu: goto P_0c0bafee;
case 0x0c0baff0u: goto P_0c0baff0;
case 0x0c0baff2u: goto P_0c0baff2;
case 0x0c0baff4u: goto P_0c0baff4;
case 0x0c0baff6u: goto P_0c0baff6;
case 0x0c0baff8u: goto P_0c0baff8;
case 0x0c0baffau: goto P_0c0baffa;
case 0x0c0baffcu: goto P_0c0baffc;
case 0x0c0baffeu: goto P_0c0baffe;
case 0x0c0bb000u: goto P_0c0bb000;
case 0x0c0bb002u: goto P_0c0bb002;
case 0x0c0bb004u: goto P_0c0bb004;
case 0x0c0bb006u: goto P_0c0bb006;
case 0x0c0bb008u: goto P_0c0bb008;
case 0x0c0bb00au: goto P_0c0bb00a;
case 0x0c0bb00cu: goto P_0c0bb00c;
case 0x0c0bb00eu: goto P_0c0bb00e;
case 0x0c0bb010u: goto P_0c0bb010;
case 0x0c0bb012u: goto P_0c0bb012;
case 0x0c0bb014u: goto P_0c0bb014;
case 0x0c0bb016u: goto P_0c0bb016;
case 0x0c0bb018u: goto P_0c0bb018;
case 0x0c0bb01au: goto P_0c0bb01a;
case 0x0c0bb01cu: goto P_0c0bb01c;
case 0x0c0bb01eu: goto P_0c0bb01e;
case 0x0c0bb020u: goto P_0c0bb020;
case 0x0c0bb022u: goto P_0c0bb022;
case 0x0c0bb024u: goto P_0c0bb024;
case 0x0c0bb026u: goto P_0c0bb026;
case 0x0c0bb028u: goto P_0c0bb028;
case 0x0c0bb02au: goto P_0c0bb02a;
case 0x0c0bb02cu: goto P_0c0bb02c;
case 0x0c0bb02eu: goto P_0c0bb02e;
case 0x0c0bb030u: goto P_0c0bb030;
case 0x0c0bb032u: goto P_0c0bb032;
case 0x0c0bb034u: goto P_0c0bb034;
case 0x0c0bb036u: goto P_0c0bb036;
case 0x0c0bb038u: goto P_0c0bb038;
case 0x0c0bb03au: goto P_0c0bb03a;
case 0x0c0bb03cu: goto P_0c0bb03c;
case 0x0c0bb03eu: goto P_0c0bb03e;
case 0x0c0bb040u: goto P_0c0bb040;
case 0x0c0bb042u: goto P_0c0bb042;
case 0x0c0bb044u: goto P_0c0bb044;
case 0x0c0bb046u: goto P_0c0bb046;
case 0x0c0bb048u: goto P_0c0bb048;
case 0x0c0bb04au: goto P_0c0bb04a;
case 0x0c0bb04cu: goto P_0c0bb04c;
case 0x0c0bb04eu: goto P_0c0bb04e;
case 0x0c0bb050u: goto P_0c0bb050;
case 0x0c0bb052u: goto P_0c0bb052;
case 0x0c0bb054u: goto P_0c0bb054;
case 0x0c0bb056u: goto P_0c0bb056;
case 0x0c0bb058u: goto P_0c0bb058;
case 0x0c0bb05au: goto P_0c0bb05a;
case 0x0c0bb05cu: goto P_0c0bb05c;
case 0x0c0bb05eu: goto P_0c0bb05e;
case 0x0c0bb060u: goto P_0c0bb060;
case 0x0c0bb062u: goto P_0c0bb062;
case 0x0c0bb064u: goto P_0c0bb064;
case 0x0c0bb066u: goto P_0c0bb066;
case 0x0c0bb068u: goto P_0c0bb068;
case 0x0c0bb06au: goto P_0c0bb06a;
case 0x0c0bb06cu: goto P_0c0bb06c;
case 0x0c0bb06eu: goto P_0c0bb06e;
case 0x0c0bb070u: goto P_0c0bb070;
case 0x0c0bb072u: goto P_0c0bb072;
case 0x0c0bb074u: goto P_0c0bb074;
case 0x0c0bb076u: goto P_0c0bb076;
case 0x0c0bb078u: goto P_0c0bb078;
case 0x0c0bb0e8u: goto P_0c0bb0e8;
case 0x0c0bb0eau: goto P_0c0bb0ea;
case 0x0c0bb0ecu: goto P_0c0bb0ec;
case 0x0c0bb0eeu: goto P_0c0bb0ee;
case 0x0c0bb0f0u: goto P_0c0bb0f0;
case 0x0c0bb0f2u: goto P_0c0bb0f2;
case 0x0c0bb0f4u: goto P_0c0bb0f4;
case 0x0c0bb0f6u: goto P_0c0bb0f6;
case 0x0c0bb0f8u: goto P_0c0bb0f8;
case 0x0c0bb0fau: goto P_0c0bb0fa;
case 0x0c0bb0fcu: goto P_0c0bb0fc;
case 0x0c0bb0feu: goto P_0c0bb0fe;
case 0x0c0bb100u: goto P_0c0bb100;
case 0x0c0bb102u: goto P_0c0bb102;
case 0x0c0bb104u: goto P_0c0bb104;
case 0x0c0bb106u: goto P_0c0bb106;
case 0x0c0bb108u: goto P_0c0bb108;
case 0x0c0bb10au: goto P_0c0bb10a;
case 0x0c0bb10cu: goto P_0c0bb10c;
case 0x0c0bb10eu: goto P_0c0bb10e;
case 0x0c0bb110u: goto P_0c0bb110;
case 0x0c0bb112u: goto P_0c0bb112;
case 0x0c0bb114u: goto P_0c0bb114;
case 0x0c0bb116u: goto P_0c0bb116;
case 0x0c0bb118u: goto P_0c0bb118;
case 0x0c0bb11au: goto P_0c0bb11a;
case 0x0c0bb11cu: goto P_0c0bb11c;
case 0x0c0bb11eu: goto P_0c0bb11e;
case 0x0c0bb120u: goto P_0c0bb120;
case 0x0c0bb122u: goto P_0c0bb122;
case 0x0c0bb124u: goto P_0c0bb124;
case 0x0c0bb126u: goto P_0c0bb126;
case 0x0c0bb128u: goto P_0c0bb128;
case 0x0c0bb12au: goto P_0c0bb12a;
case 0x0c0bb12cu: goto P_0c0bb12c;
case 0x0c0bb12eu: goto P_0c0bb12e;
case 0x0c0bb130u: goto P_0c0bb130;
case 0x0c0bb132u: goto P_0c0bb132;
case 0x0c0bb134u: goto P_0c0bb134;
case 0x0c0bb136u: goto P_0c0bb136;
case 0x0c0bb138u: goto P_0c0bb138;
case 0x0c0bb13au: goto P_0c0bb13a;
case 0x0c0bb13cu: goto P_0c0bb13c;
case 0x0c0bb13eu: goto P_0c0bb13e;
case 0x0c0bb140u: goto P_0c0bb140;
case 0x0c0bb142u: goto P_0c0bb142;
case 0x0c0bb144u: goto P_0c0bb144;
case 0x0c0bb146u: goto P_0c0bb146;
case 0x0c0bb148u: goto P_0c0bb148;
case 0x0c0bb14au: goto P_0c0bb14a;
case 0x0c0bb14cu: goto P_0c0bb14c;
case 0x0c0bb14eu: goto P_0c0bb14e;
case 0x0c0bb150u: goto P_0c0bb150;
case 0x0c0bb152u: goto P_0c0bb152;
case 0x0c0bb154u: goto P_0c0bb154;
case 0x0c0bb156u: goto P_0c0bb156;
case 0x0c0bb158u: goto P_0c0bb158;
case 0x0c0bb15au: goto P_0c0bb15a;
case 0x0c0bb15cu: goto P_0c0bb15c;
case 0x0c0bb15eu: goto P_0c0bb15e;
case 0x0c0bb160u: goto P_0c0bb160;
case 0x0c0bb162u: goto P_0c0bb162;
case 0x0c0bb164u: goto P_0c0bb164;
case 0x0c0bb166u: goto P_0c0bb166;
case 0x0c0bb168u: goto P_0c0bb168;
case 0x0c0bb16au: goto P_0c0bb16a;
case 0x0c0bb16cu: goto P_0c0bb16c;
case 0x0c0bb16eu: goto P_0c0bb16e;
case 0x0c0bb170u: goto P_0c0bb170;
case 0x0c0bb172u: goto P_0c0bb172;
case 0x0c0bb174u: goto P_0c0bb174;
case 0x0c0bb176u: goto P_0c0bb176;
case 0x0c0bb178u: goto P_0c0bb178;
case 0x0c0bb17au: goto P_0c0bb17a;
case 0x0c0bb17cu: goto P_0c0bb17c;
case 0x0c0bb17eu: goto P_0c0bb17e;
case 0x0c0bb180u: goto P_0c0bb180;
case 0x0c0bb182u: goto P_0c0bb182;
case 0x0c0bb184u: goto P_0c0bb184;
case 0x0c0bb186u: goto P_0c0bb186;
case 0x0c0bb188u: goto P_0c0bb188;
case 0x0c0bb18au: goto P_0c0bb18a;
case 0x0c0bb18cu: goto P_0c0bb18c;
case 0x0c0bb18eu: goto P_0c0bb18e;
case 0x0c0bb190u: goto P_0c0bb190;
case 0x0c0bb192u: goto P_0c0bb192;
case 0x0c0bb194u: goto P_0c0bb194;
case 0x0c0bb196u: goto P_0c0bb196;
case 0x0c0bb198u: goto P_0c0bb198;
case 0x0c0bb19au: goto P_0c0bb19a;
case 0x0c0bb19cu: goto P_0c0bb19c;
case 0x0c0bb19eu: goto P_0c0bb19e;
case 0x0c0bb1a0u: goto P_0c0bb1a0;
case 0x0c0bb1a2u: goto P_0c0bb1a2;
case 0x0c0bb1a4u: goto P_0c0bb1a4;
case 0x0c0bb1a6u: goto P_0c0bb1a6;
case 0x0c0bb1a8u: goto P_0c0bb1a8;
case 0x0c0bb1aau: goto P_0c0bb1aa;
case 0x0c0bb1acu: goto P_0c0bb1ac;
case 0x0c0bb1aeu: goto P_0c0bb1ae;
case 0x0c0bb1b0u: goto P_0c0bb1b0;
case 0x0c0bb1b2u: goto P_0c0bb1b2;
case 0x0c0bb1b4u: goto P_0c0bb1b4;
case 0x0c0bb1b6u: goto P_0c0bb1b6;
case 0x0c0bb1b8u: goto P_0c0bb1b8;
case 0x0c0bb1bau: goto P_0c0bb1ba;
case 0x0c0bb1bcu: goto P_0c0bb1bc;
case 0x0c0bb1beu: goto P_0c0bb1be;
case 0x0c0bb1c0u: goto P_0c0bb1c0;
case 0x0c0bb1c2u: goto P_0c0bb1c2;
case 0x0c0bb1c4u: goto P_0c0bb1c4;
case 0x0c0bb1c6u: goto P_0c0bb1c6;
case 0x0c0bb1c8u: goto P_0c0bb1c8;
case 0x0c0bb1cau: goto P_0c0bb1ca;
case 0x0c0bb1ccu: goto P_0c0bb1cc;
case 0x0c0bb1ceu: goto P_0c0bb1ce;
case 0x0c0bb1d0u: goto P_0c0bb1d0;
case 0x0c0bb1d2u: goto P_0c0bb1d2;
case 0x0c0bb1d4u: goto P_0c0bb1d4;
case 0x0c0bb1d6u: goto P_0c0bb1d6;
case 0x0c0bb1d8u: goto P_0c0bb1d8;
case 0x0c0bb1dau: goto P_0c0bb1da;
case 0x0c0bb1dcu: goto P_0c0bb1dc;
case 0x0c0bb1deu: goto P_0c0bb1de;
case 0x0c0bb1e0u: goto P_0c0bb1e0;
case 0x0c0bb1e2u: goto P_0c0bb1e2;
case 0x0c0bb1e4u: goto P_0c0bb1e4;
case 0x0c0bb1e6u: goto P_0c0bb1e6;
case 0x0c0bb1e8u: goto P_0c0bb1e8;
case 0x0c0bb1eau: goto P_0c0bb1ea;
case 0x0c0bb1ecu: goto P_0c0bb1ec;
case 0x0c0bb1eeu: goto P_0c0bb1ee;
case 0x0c0bb1f0u: goto P_0c0bb1f0;
case 0x0c0bb1f2u: goto P_0c0bb1f2;
case 0x0c0bb1f4u: goto P_0c0bb1f4;
case 0x0c0bb1f6u: goto P_0c0bb1f6;
case 0x0c0bb1f8u: goto P_0c0bb1f8;
case 0x0c0bb1fau: goto P_0c0bb1fa;
case 0x0c0bb1fcu: goto P_0c0bb1fc;
case 0x0c0bb1feu: goto P_0c0bb1fe;
case 0x0c0bb200u: goto P_0c0bb200;
case 0x0c0bb202u: goto P_0c0bb202;
case 0x0c0bb204u: goto P_0c0bb204;
case 0x0c0bb206u: goto P_0c0bb206;
case 0x0c0bb208u: goto P_0c0bb208;
case 0x0c0bb20au: goto P_0c0bb20a;
case 0x0c0bb20cu: goto P_0c0bb20c;
case 0x0c0bb20eu: goto P_0c0bb20e;
case 0x0c0bb210u: goto P_0c0bb210;
case 0x0c0bb212u: goto P_0c0bb212;
case 0x0c0bb214u: goto P_0c0bb214;
case 0x0c0bb216u: goto P_0c0bb216;
case 0x0c0bb218u: goto P_0c0bb218;
case 0x0c0bb21au: goto P_0c0bb21a;
case 0x0c0bb21cu: goto P_0c0bb21c;
case 0x0c0bb21eu: goto P_0c0bb21e;
case 0x0c0bb220u: goto P_0c0bb220;
case 0x0c0bb222u: goto P_0c0bb222;
case 0x0c0bb224u: goto P_0c0bb224;
case 0x0c0bb226u: goto P_0c0bb226;
case 0x0c0bb228u: goto P_0c0bb228;
case 0x0c0bb22au: goto P_0c0bb22a;
case 0x0c0bb22cu: goto P_0c0bb22c;
case 0x0c0bb22eu: goto P_0c0bb22e;
case 0x0c0bb230u: goto P_0c0bb230;
case 0x0c0bb232u: goto P_0c0bb232;
case 0x0c0bb234u: goto P_0c0bb234;
case 0x0c0bb236u: goto P_0c0bb236;
case 0x0c0bb238u: goto P_0c0bb238;
case 0x0c0bb23au: goto P_0c0bb23a;
case 0x0c0bb23cu: goto P_0c0bb23c;
case 0x0c0bb23eu: goto P_0c0bb23e;
case 0x0c0bb240u: goto P_0c0bb240;
case 0x0c0bb2bau: goto P_0c0bb2ba;
case 0x0c0bb2bcu: goto P_0c0bb2bc;
case 0x0c0bb2beu: goto P_0c0bb2be;
case 0x0c0bb2c0u: goto P_0c0bb2c0;
case 0x0c0bb2c2u: goto P_0c0bb2c2;
case 0x0c0bb2c4u: goto P_0c0bb2c4;
case 0x0c0bb2c6u: goto P_0c0bb2c6;
case 0x0c0bb2c8u: goto P_0c0bb2c8;
case 0x0c0bb2cau: goto P_0c0bb2ca;
case 0x0c0bb2ccu: goto P_0c0bb2cc;
case 0x0c0bb2ceu: goto P_0c0bb2ce;
case 0x0c0bb2d0u: goto P_0c0bb2d0;
case 0x0c0bb2d2u: goto P_0c0bb2d2;
case 0x0c0bb2d4u: goto P_0c0bb2d4;
case 0x0c0bb2d6u: goto P_0c0bb2d6;
case 0x0c0bb2d8u: goto P_0c0bb2d8;
case 0x0c0bb2dau: goto P_0c0bb2da;
case 0x0c0bb2dcu: goto P_0c0bb2dc;
case 0x0c0bb2deu: goto P_0c0bb2de;
case 0x0c0bb2e0u: goto P_0c0bb2e0;
case 0x0c0bb2e2u: goto P_0c0bb2e2;
case 0x0c0bb2e4u: goto P_0c0bb2e4;
case 0x0c0bb2e6u: goto P_0c0bb2e6;
case 0x0c0bb2e8u: goto P_0c0bb2e8;
case 0x0c0bb2eau: goto P_0c0bb2ea;
case 0x0c0bb2ecu: goto P_0c0bb2ec;
case 0x0c0bb2eeu: goto P_0c0bb2ee;
case 0x0c0bb2f0u: goto P_0c0bb2f0;
case 0x0c0bb2f2u: goto P_0c0bb2f2;
case 0x0c0bb2f4u: goto P_0c0bb2f4;
case 0x0c0bb2f6u: goto P_0c0bb2f6;
case 0x0c0bb2f8u: goto P_0c0bb2f8;
case 0x0c0bb2fau: goto P_0c0bb2fa;
case 0x0c0bb2fcu: goto P_0c0bb2fc;
case 0x0c0bb2feu: goto P_0c0bb2fe;
case 0x0c0bb300u: goto P_0c0bb300;
case 0x0c0bb302u: goto P_0c0bb302;
case 0x0c0bb304u: goto P_0c0bb304;
case 0x0c0bb306u: goto P_0c0bb306;
case 0x0c0bb308u: goto P_0c0bb308;
case 0x0c0bb30au: goto P_0c0bb30a;
case 0x0c0bb30cu: goto P_0c0bb30c;
case 0x0c0bb30eu: goto P_0c0bb30e;
case 0x0c0bb310u: goto P_0c0bb310;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0baf16: /* original 2fe6, guest PC 0x0c0baf16 */
if(!s->budget--) { s->failed_pc=0x0c0baf16u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0baf18;
P_0c0baf18: /* original 2fd6, guest PC 0x0c0baf18 */
if(!s->budget--) { s->failed_pc=0x0c0baf18u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0baf1a;
P_0c0baf1a: /* original 2fc6, guest PC 0x0c0baf1a */
if(!s->budget--) { s->failed_pc=0x0c0baf1au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0baf1c;
P_0c0baf1c: /* original 2fb6, guest PC 0x0c0baf1c */
if(!s->budget--) { s->failed_pc=0x0c0baf1cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0baf1e;
P_0c0baf1e: /* original 2fa6, guest PC 0x0c0baf1e */
if(!s->budget--) { s->failed_pc=0x0c0baf1eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0baf20;
P_0c0baf20: /* original 2f96, guest PC 0x0c0baf20 */
if(!s->budget--) { s->failed_pc=0x0c0baf20u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0baf22;
P_0c0baf22: /* original 4f22, guest PC 0x0c0baf22 */
if(!s->budget--) { s->failed_pc=0x0c0baf22u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0baf24;
P_0c0baf24: /* original 5d44, guest PC 0x0c0baf24 */
if(!s->budget--) { s->failed_pc=0x0c0baf24u; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0baf26;
P_0c0baf26: /* original 94a8, guest PC 0x0c0baf26 */
if(!s->budget--) { s->failed_pc=0x0c0baf26u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb07au,2);
goto P_0c0baf28;
P_0c0baf28: /* original de6e, guest PC 0x0c0baf28 */
if(!s->budget--) { s->failed_pc=0x0c0baf28u; return 0; }
r[14]=read(ram,0x0c0bb0e4u,4);
goto P_0c0baf2a;
P_0c0baf2a: /* original 7ff8, guest PC 0x0c0baf2a */
if(!s->budget--) { s->failed_pc=0x0c0baf2au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0baf2c;
P_0c0baf2c: /* original 4e0b, guest PC 0x0c0baf2c */
if(!s->budget--) { s->failed_pc=0x0c0baf2cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0baf30u;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baf30u) { target=s->pc; goto dispatch; }
goto P_0c0baf30;
P_0c0baf2e: /* original 65d2, guest PC 0x0c0baf2e */
if(!s->budget--) { s->failed_pc=0x0c0baf2eu; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0baf30;
P_0c0baf30: /* original 94a4, guest PC 0x0c0baf30 */
if(!s->budget--) { s->failed_pc=0x0c0baf30u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb07cu,2);
goto P_0c0baf32;
P_0c0baf32: /* original 4e0b, guest PC 0x0c0baf32 */
if(!s->budget--) { s->failed_pc=0x0c0baf32u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baf36u;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baf36u) { target=s->pc; goto dispatch; }
goto P_0c0baf36;
P_0c0baf34: /* original 55d1, guest PC 0x0c0baf34 */
if(!s->budget--) { s->failed_pc=0x0c0baf34u; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0baf36;
P_0c0baf36: /* original 94a2, guest PC 0x0c0baf36 */
if(!s->budget--) { s->failed_pc=0x0c0baf36u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb07eu,2);
goto P_0c0baf38;
P_0c0baf38: /* original 4e0b, guest PC 0x0c0baf38 */
if(!s->budget--) { s->failed_pc=0x0c0baf38u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baf3cu;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baf3cu) { target=s->pc; goto dispatch; }
goto P_0c0baf3c;
P_0c0baf3a: /* original 55d2, guest PC 0x0c0baf3a */
if(!s->budget--) { s->failed_pc=0x0c0baf3au; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0baf3c;
P_0c0baf3c: /* original 94a0, guest PC 0x0c0baf3c */
if(!s->budget--) { s->failed_pc=0x0c0baf3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb080u,2);
goto P_0c0baf3e;
P_0c0baf3e: /* original 4e0b, guest PC 0x0c0baf3e */
if(!s->budget--) { s->failed_pc=0x0c0baf3eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0baf42u;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baf42u) { target=s->pc; goto dispatch; }
goto P_0c0baf42;
P_0c0baf40: /* original 55d3, guest PC 0x0c0baf40 */
if(!s->budget--) { s->failed_pc=0x0c0baf40u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0baf42;
P_0c0baf42: /* original 949e, guest PC 0x0c0baf42 */
if(!s->budget--) { s->failed_pc=0x0c0baf42u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb082u,2);
goto P_0c0baf44;
P_0c0baf44: /* original 4e0b, guest PC 0x0c0baf44 */
if(!s->budget--) { s->failed_pc=0x0c0baf44u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baf48u;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baf48u) { target=s->pc; goto dispatch; }
goto P_0c0baf48;
P_0c0baf46: /* original 55d4, guest PC 0x0c0baf46 */
if(!s->budget--) { s->failed_pc=0x0c0baf46u; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0baf48;
P_0c0baf48: /* original 949c, guest PC 0x0c0baf48 */
if(!s->budget--) { s->failed_pc=0x0c0baf48u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb084u,2);
goto P_0c0baf4a;
P_0c0baf4a: /* original 4e0b, guest PC 0x0c0baf4a */
if(!s->budget--) { s->failed_pc=0x0c0baf4au; return 0; }
target=r[14];
r[16]=code_base|0x0c0baf4eu;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baf4eu) { target=s->pc; goto dispatch; }
goto P_0c0baf4e;
P_0c0baf4c: /* original 55d5, guest PC 0x0c0baf4c */
if(!s->budget--) { s->failed_pc=0x0c0baf4cu; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0baf4e;
P_0c0baf4e: /* original 949a, guest PC 0x0c0baf4e */
if(!s->budget--) { s->failed_pc=0x0c0baf4eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb086u,2);
goto P_0c0baf50;
P_0c0baf50: /* original 4e0b, guest PC 0x0c0baf50 */
if(!s->budget--) { s->failed_pc=0x0c0baf50u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baf54u;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baf54u) { target=s->pc; goto dispatch; }
goto P_0c0baf54;
P_0c0baf52: /* original 55d6, guest PC 0x0c0baf52 */
if(!s->budget--) { s->failed_pc=0x0c0baf52u; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0baf54;
P_0c0baf54: /* original 9498, guest PC 0x0c0baf54 */
if(!s->budget--) { s->failed_pc=0x0c0baf54u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb088u,2);
goto P_0c0baf56;
P_0c0baf56: /* original 4e0b, guest PC 0x0c0baf56 */
if(!s->budget--) { s->failed_pc=0x0c0baf56u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baf5au;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baf5au) { target=s->pc; goto dispatch; }
goto P_0c0baf5a;
P_0c0baf58: /* original 55d7, guest PC 0x0c0baf58 */
if(!s->budget--) { s->failed_pc=0x0c0baf58u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0baf5a;
P_0c0baf5a: /* original 9496, guest PC 0x0c0baf5a */
if(!s->budget--) { s->failed_pc=0x0c0baf5au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb08au,2);
goto P_0c0baf5c;
P_0c0baf5c: /* original 4e0b, guest PC 0x0c0baf5c */
if(!s->budget--) { s->failed_pc=0x0c0baf5cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0baf60u;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baf60u) { target=s->pc; goto dispatch; }
goto P_0c0baf60;
P_0c0baf5e: /* original 55d8, guest PC 0x0c0baf5e */
if(!s->budget--) { s->failed_pc=0x0c0baf5eu; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0baf60;
P_0c0baf60: /* original 9494, guest PC 0x0c0baf60 */
if(!s->budget--) { s->failed_pc=0x0c0baf60u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb08cu,2);
goto P_0c0baf62;
P_0c0baf62: /* original 4e0b, guest PC 0x0c0baf62 */
if(!s->budget--) { s->failed_pc=0x0c0baf62u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baf66u;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baf66u) { target=s->pc; goto dispatch; }
goto P_0c0baf66;
P_0c0baf64: /* original 55d9, guest PC 0x0c0baf64 */
if(!s->budget--) { s->failed_pc=0x0c0baf64u; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0baf66;
P_0c0baf66: /* original 9492, guest PC 0x0c0baf66 */
if(!s->budget--) { s->failed_pc=0x0c0baf66u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb08eu,2);
goto P_0c0baf68;
P_0c0baf68: /* original 4e0b, guest PC 0x0c0baf68 */
if(!s->budget--) { s->failed_pc=0x0c0baf68u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baf6cu;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baf6cu) { target=s->pc; goto dispatch; }
goto P_0c0baf6c;
P_0c0baf6a: /* original 55da, guest PC 0x0c0baf6a */
if(!s->budget--) { s->failed_pc=0x0c0baf6au; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0baf6c;
P_0c0baf6c: /* original 9490, guest PC 0x0c0baf6c */
if(!s->budget--) { s->failed_pc=0x0c0baf6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb090u,2);
goto P_0c0baf6e;
P_0c0baf6e: /* original 4e0b, guest PC 0x0c0baf6e */
if(!s->budget--) { s->failed_pc=0x0c0baf6eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0baf72u;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baf72u) { target=s->pc; goto dispatch; }
goto P_0c0baf72;
P_0c0baf70: /* original 55db, guest PC 0x0c0baf70 */
if(!s->budget--) { s->failed_pc=0x0c0baf70u; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0baf72;
P_0c0baf72: /* original 948e, guest PC 0x0c0baf72 */
if(!s->budget--) { s->failed_pc=0x0c0baf72u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb092u,2);
goto P_0c0baf74;
P_0c0baf74: /* original 4e0b, guest PC 0x0c0baf74 */
if(!s->budget--) { s->failed_pc=0x0c0baf74u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baf78u;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baf78u) { target=s->pc; goto dispatch; }
goto P_0c0baf78;
P_0c0baf76: /* original 55dc, guest PC 0x0c0baf76 */
if(!s->budget--) { s->failed_pc=0x0c0baf76u; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0baf78;
P_0c0baf78: /* original 948c, guest PC 0x0c0baf78 */
if(!s->budget--) { s->failed_pc=0x0c0baf78u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb094u,2);
goto P_0c0baf7a;
P_0c0baf7a: /* original 4e0b, guest PC 0x0c0baf7a */
if(!s->budget--) { s->failed_pc=0x0c0baf7au; return 0; }
target=r[14];
r[16]=code_base|0x0c0baf7eu;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baf7eu) { target=s->pc; goto dispatch; }
goto P_0c0baf7e;
P_0c0baf7c: /* original 55dd, guest PC 0x0c0baf7c */
if(!s->budget--) { s->failed_pc=0x0c0baf7cu; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0baf7e;
P_0c0baf7e: /* original 948a, guest PC 0x0c0baf7e */
if(!s->budget--) { s->failed_pc=0x0c0baf7eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb096u,2);
goto P_0c0baf80;
P_0c0baf80: /* original 4e0b, guest PC 0x0c0baf80 */
if(!s->budget--) { s->failed_pc=0x0c0baf80u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baf84u;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baf84u) { target=s->pc; goto dispatch; }
goto P_0c0baf84;
P_0c0baf82: /* original 55de, guest PC 0x0c0baf82 */
if(!s->budget--) { s->failed_pc=0x0c0baf82u; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0baf84;
P_0c0baf84: /* original 9488, guest PC 0x0c0baf84 */
if(!s->budget--) { s->failed_pc=0x0c0baf84u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb098u,2);
goto P_0c0baf86;
P_0c0baf86: /* original 4e0b, guest PC 0x0c0baf86 */
if(!s->budget--) { s->failed_pc=0x0c0baf86u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baf8au;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baf8au) { target=s->pc; goto dispatch; }
goto P_0c0baf8a;
P_0c0baf88: /* original 55df, guest PC 0x0c0baf88 */
if(!s->budget--) { s->failed_pc=0x0c0baf88u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0baf8a;
P_0c0baf8a: /* original 9486, guest PC 0x0c0baf8a */
if(!s->budget--) { s->failed_pc=0x0c0baf8au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb09au,2);
goto P_0c0baf8c;
P_0c0baf8c: /* original e040, guest PC 0x0c0baf8c */
if(!s->budget--) { s->failed_pc=0x0c0baf8cu; return 0; }
r[0]=0x00000040u;
goto P_0c0baf8e;
P_0c0baf8e: /* original 4e0b, guest PC 0x0c0baf8e */
if(!s->budget--) { s->failed_pc=0x0c0baf8eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0baf92u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baf92u) { target=s->pc; goto dispatch; }
goto P_0c0baf92;
P_0c0baf90: /* original 05de, guest PC 0x0c0baf90 */
if(!s->budget--) { s->failed_pc=0x0c0baf90u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0baf92;
P_0c0baf92: /* original 9483, guest PC 0x0c0baf92 */
if(!s->budget--) { s->failed_pc=0x0c0baf92u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb09cu,2);
goto P_0c0baf94;
P_0c0baf94: /* original e044, guest PC 0x0c0baf94 */
if(!s->budget--) { s->failed_pc=0x0c0baf94u; return 0; }
r[0]=0x00000044u;
goto P_0c0baf96;
P_0c0baf96: /* original 4e0b, guest PC 0x0c0baf96 */
if(!s->budget--) { s->failed_pc=0x0c0baf96u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baf9au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baf9au) { target=s->pc; goto dispatch; }
goto P_0c0baf9a;
P_0c0baf98: /* original 05de, guest PC 0x0c0baf98 */
if(!s->budget--) { s->failed_pc=0x0c0baf98u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0baf9a;
P_0c0baf9a: /* original 9480, guest PC 0x0c0baf9a */
if(!s->budget--) { s->failed_pc=0x0c0baf9au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb09eu,2);
goto P_0c0baf9c;
P_0c0baf9c: /* original e048, guest PC 0x0c0baf9c */
if(!s->budget--) { s->failed_pc=0x0c0baf9cu; return 0; }
r[0]=0x00000048u;
goto P_0c0baf9e;
P_0c0baf9e: /* original 4e0b, guest PC 0x0c0baf9e */
if(!s->budget--) { s->failed_pc=0x0c0baf9eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bafa2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bafa2u) { target=s->pc; goto dispatch; }
goto P_0c0bafa2;
P_0c0bafa0: /* original 05de, guest PC 0x0c0bafa0 */
if(!s->budget--) { s->failed_pc=0x0c0bafa0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bafa2;
P_0c0bafa2: /* original 947d, guest PC 0x0c0bafa2 */
if(!s->budget--) { s->failed_pc=0x0c0bafa2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0a0u,2);
goto P_0c0bafa4;
P_0c0bafa4: /* original e04c, guest PC 0x0c0bafa4 */
if(!s->budget--) { s->failed_pc=0x0c0bafa4u; return 0; }
r[0]=0x0000004cu;
goto P_0c0bafa6;
P_0c0bafa6: /* original 4e0b, guest PC 0x0c0bafa6 */
if(!s->budget--) { s->failed_pc=0x0c0bafa6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bafaau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bafaau) { target=s->pc; goto dispatch; }
goto P_0c0bafaa;
P_0c0bafa8: /* original 05de, guest PC 0x0c0bafa8 */
if(!s->budget--) { s->failed_pc=0x0c0bafa8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bafaa;
P_0c0bafaa: /* original 947a, guest PC 0x0c0bafaa */
if(!s->budget--) { s->failed_pc=0x0c0bafaau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0a2u,2);
goto P_0c0bafac;
P_0c0bafac: /* original e050, guest PC 0x0c0bafac */
if(!s->budget--) { s->failed_pc=0x0c0bafacu; return 0; }
r[0]=0x00000050u;
goto P_0c0bafae;
P_0c0bafae: /* original 4e0b, guest PC 0x0c0bafae */
if(!s->budget--) { s->failed_pc=0x0c0bafaeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bafb2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bafb2u) { target=s->pc; goto dispatch; }
goto P_0c0bafb2;
P_0c0bafb0: /* original 05de, guest PC 0x0c0bafb0 */
if(!s->budget--) { s->failed_pc=0x0c0bafb0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bafb2;
P_0c0bafb2: /* original 9477, guest PC 0x0c0bafb2 */
if(!s->budget--) { s->failed_pc=0x0c0bafb2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0a4u,2);
goto P_0c0bafb4;
P_0c0bafb4: /* original e054, guest PC 0x0c0bafb4 */
if(!s->budget--) { s->failed_pc=0x0c0bafb4u; return 0; }
r[0]=0x00000054u;
goto P_0c0bafb6;
P_0c0bafb6: /* original 4e0b, guest PC 0x0c0bafb6 */
if(!s->budget--) { s->failed_pc=0x0c0bafb6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bafbau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bafbau) { target=s->pc; goto dispatch; }
goto P_0c0bafba;
P_0c0bafb8: /* original 05de, guest PC 0x0c0bafb8 */
if(!s->budget--) { s->failed_pc=0x0c0bafb8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bafba;
P_0c0bafba: /* original 9474, guest PC 0x0c0bafba */
if(!s->budget--) { s->failed_pc=0x0c0bafbau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0a6u,2);
goto P_0c0bafbc;
P_0c0bafbc: /* original e058, guest PC 0x0c0bafbc */
if(!s->budget--) { s->failed_pc=0x0c0bafbcu; return 0; }
r[0]=0x00000058u;
goto P_0c0bafbe;
P_0c0bafbe: /* original 4e0b, guest PC 0x0c0bafbe */
if(!s->budget--) { s->failed_pc=0x0c0bafbeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bafc2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bafc2u) { target=s->pc; goto dispatch; }
goto P_0c0bafc2;
P_0c0bafc0: /* original 05de, guest PC 0x0c0bafc0 */
if(!s->budget--) { s->failed_pc=0x0c0bafc0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bafc2;
P_0c0bafc2: /* original 9471, guest PC 0x0c0bafc2 */
if(!s->budget--) { s->failed_pc=0x0c0bafc2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0a8u,2);
goto P_0c0bafc4;
P_0c0bafc4: /* original e05c, guest PC 0x0c0bafc4 */
if(!s->budget--) { s->failed_pc=0x0c0bafc4u; return 0; }
r[0]=0x0000005cu;
goto P_0c0bafc6;
P_0c0bafc6: /* original 4e0b, guest PC 0x0c0bafc6 */
if(!s->budget--) { s->failed_pc=0x0c0bafc6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bafcau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bafcau) { target=s->pc; goto dispatch; }
goto P_0c0bafca;
P_0c0bafc8: /* original 05de, guest PC 0x0c0bafc8 */
if(!s->budget--) { s->failed_pc=0x0c0bafc8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bafca;
P_0c0bafca: /* original 946e, guest PC 0x0c0bafca */
if(!s->budget--) { s->failed_pc=0x0c0bafcau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0aau,2);
goto P_0c0bafcc;
P_0c0bafcc: /* original e060, guest PC 0x0c0bafcc */
if(!s->budget--) { s->failed_pc=0x0c0bafccu; return 0; }
r[0]=0x00000060u;
goto P_0c0bafce;
P_0c0bafce: /* original 4e0b, guest PC 0x0c0bafce */
if(!s->budget--) { s->failed_pc=0x0c0bafceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bafd2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bafd2u) { target=s->pc; goto dispatch; }
goto P_0c0bafd2;
P_0c0bafd0: /* original 05de, guest PC 0x0c0bafd0 */
if(!s->budget--) { s->failed_pc=0x0c0bafd0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bafd2;
P_0c0bafd2: /* original 946b, guest PC 0x0c0bafd2 */
if(!s->budget--) { s->failed_pc=0x0c0bafd2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0acu,2);
goto P_0c0bafd4;
P_0c0bafd4: /* original e064, guest PC 0x0c0bafd4 */
if(!s->budget--) { s->failed_pc=0x0c0bafd4u; return 0; }
r[0]=0x00000064u;
goto P_0c0bafd6;
P_0c0bafd6: /* original 4e0b, guest PC 0x0c0bafd6 */
if(!s->budget--) { s->failed_pc=0x0c0bafd6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bafdau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bafdau) { target=s->pc; goto dispatch; }
goto P_0c0bafda;
P_0c0bafd8: /* original 05de, guest PC 0x0c0bafd8 */
if(!s->budget--) { s->failed_pc=0x0c0bafd8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bafda;
P_0c0bafda: /* original 9468, guest PC 0x0c0bafda */
if(!s->budget--) { s->failed_pc=0x0c0bafdau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0aeu,2);
goto P_0c0bafdc;
P_0c0bafdc: /* original e068, guest PC 0x0c0bafdc */
if(!s->budget--) { s->failed_pc=0x0c0bafdcu; return 0; }
r[0]=0x00000068u;
goto P_0c0bafde;
P_0c0bafde: /* original 4e0b, guest PC 0x0c0bafde */
if(!s->budget--) { s->failed_pc=0x0c0bafdeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bafe2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bafe2u) { target=s->pc; goto dispatch; }
goto P_0c0bafe2;
P_0c0bafe0: /* original 05de, guest PC 0x0c0bafe0 */
if(!s->budget--) { s->failed_pc=0x0c0bafe0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bafe2;
P_0c0bafe2: /* original 9465, guest PC 0x0c0bafe2 */
if(!s->budget--) { s->failed_pc=0x0c0bafe2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0b0u,2);
goto P_0c0bafe4;
P_0c0bafe4: /* original e06c, guest PC 0x0c0bafe4 */
if(!s->budget--) { s->failed_pc=0x0c0bafe4u; return 0; }
r[0]=0x0000006cu;
goto P_0c0bafe6;
P_0c0bafe6: /* original 4e0b, guest PC 0x0c0bafe6 */
if(!s->budget--) { s->failed_pc=0x0c0bafe6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bafeau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bafeau) { target=s->pc; goto dispatch; }
goto P_0c0bafea;
P_0c0bafe8: /* original 05de, guest PC 0x0c0bafe8 */
if(!s->budget--) { s->failed_pc=0x0c0bafe8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bafea;
P_0c0bafea: /* original 9462, guest PC 0x0c0bafea */
if(!s->budget--) { s->failed_pc=0x0c0bafeau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0b2u,2);
goto P_0c0bafec;
P_0c0bafec: /* original e070, guest PC 0x0c0bafec */
if(!s->budget--) { s->failed_pc=0x0c0bafecu; return 0; }
r[0]=0x00000070u;
goto P_0c0bafee;
P_0c0bafee: /* original 4e0b, guest PC 0x0c0bafee */
if(!s->budget--) { s->failed_pc=0x0c0bafeeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0baff2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baff2u) { target=s->pc; goto dispatch; }
goto P_0c0baff2;
P_0c0baff0: /* original 05de, guest PC 0x0c0baff0 */
if(!s->budget--) { s->failed_pc=0x0c0baff0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0baff2;
P_0c0baff2: /* original 945f, guest PC 0x0c0baff2 */
if(!s->budget--) { s->failed_pc=0x0c0baff2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0b4u,2);
goto P_0c0baff4;
P_0c0baff4: /* original e074, guest PC 0x0c0baff4 */
if(!s->budget--) { s->failed_pc=0x0c0baff4u; return 0; }
r[0]=0x00000074u;
goto P_0c0baff6;
P_0c0baff6: /* original 4e0b, guest PC 0x0c0baff6 */
if(!s->budget--) { s->failed_pc=0x0c0baff6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0baffau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0baffau) { target=s->pc; goto dispatch; }
goto P_0c0baffa;
P_0c0baff8: /* original 05de, guest PC 0x0c0baff8 */
if(!s->budget--) { s->failed_pc=0x0c0baff8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0baffa;
P_0c0baffa: /* original 945c, guest PC 0x0c0baffa */
if(!s->budget--) { s->failed_pc=0x0c0baffau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0b6u,2);
goto P_0c0baffc;
P_0c0baffc: /* original e078, guest PC 0x0c0baffc */
if(!s->budget--) { s->failed_pc=0x0c0baffcu; return 0; }
r[0]=0x00000078u;
goto P_0c0baffe;
P_0c0baffe: /* original 4e0b, guest PC 0x0c0baffe */
if(!s->budget--) { s->failed_pc=0x0c0baffeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb002u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb002u) { target=s->pc; goto dispatch; }
goto P_0c0bb002;
P_0c0bb000: /* original 05de, guest PC 0x0c0bb000 */
if(!s->budget--) { s->failed_pc=0x0c0bb000u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb002;
P_0c0bb002: /* original 9459, guest PC 0x0c0bb002 */
if(!s->budget--) { s->failed_pc=0x0c0bb002u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0b8u,2);
goto P_0c0bb004;
P_0c0bb004: /* original e07c, guest PC 0x0c0bb004 */
if(!s->budget--) { s->failed_pc=0x0c0bb004u; return 0; }
r[0]=0x0000007cu;
goto P_0c0bb006;
P_0c0bb006: /* original 4e0b, guest PC 0x0c0bb006 */
if(!s->budget--) { s->failed_pc=0x0c0bb006u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb00au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb00au) { target=s->pc; goto dispatch; }
goto P_0c0bb00a;
P_0c0bb008: /* original 05de, guest PC 0x0c0bb008 */
if(!s->budget--) { s->failed_pc=0x0c0bb008u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb00a;
P_0c0bb00a: /* original 9457, guest PC 0x0c0bb00a */
if(!s->budget--) { s->failed_pc=0x0c0bb00au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0bcu,2);
goto P_0c0bb00c;
P_0c0bb00c: /* original 9055, guest PC 0x0c0bb00c */
if(!s->budget--) { s->failed_pc=0x0c0bb00cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0bau,2);
goto P_0c0bb00e;
P_0c0bb00e: /* original 4e0b, guest PC 0x0c0bb00e */
if(!s->budget--) { s->failed_pc=0x0c0bb00eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb012u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb012u) { target=s->pc; goto dispatch; }
goto P_0c0bb012;
P_0c0bb010: /* original 05de, guest PC 0x0c0bb010 */
if(!s->budget--) { s->failed_pc=0x0c0bb010u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb012;
P_0c0bb012: /* original 9554, guest PC 0x0c0bb012 */
if(!s->budget--) { s->failed_pc=0x0c0bb012u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0beu,2);
goto P_0c0bb014;
P_0c0bb014: /* original 35dc, guest PC 0x0c0bb014 */
if(!s->budget--) { s->failed_pc=0x0c0bb014u; return 0; }
r[5]+=r[13];
goto P_0c0bb016;
P_0c0bb016: /* original 2f52, guest PC 0x0c0bb016 */
if(!s->budget--) { s->failed_pc=0x0c0bb016u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bb018;
P_0c0bb018: /* original 9452, guest PC 0x0c0bb018 */
if(!s->budget--) { s->failed_pc=0x0c0bb018u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0c0u,2);
goto P_0c0bb01a;
P_0c0bb01a: /* original 4e0b, guest PC 0x0c0bb01a */
if(!s->budget--) { s->failed_pc=0x0c0bb01au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb01eu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb01eu) { target=s->pc; goto dispatch; }
goto P_0c0bb01e;
P_0c0bb01c: /* original 6552, guest PC 0x0c0bb01c */
if(!s->budget--) { s->failed_pc=0x0c0bb01cu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb01e;
P_0c0bb01e: /* original 9550, guest PC 0x0c0bb01e */
if(!s->budget--) { s->failed_pc=0x0c0bb01eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0c2u,2);
goto P_0c0bb020;
P_0c0bb020: /* original 35dc, guest PC 0x0c0bb020 */
if(!s->budget--) { s->failed_pc=0x0c0bb020u; return 0; }
r[5]+=r[13];
goto P_0c0bb022;
P_0c0bb022: /* original 1f51, guest PC 0x0c0bb022 */
if(!s->budget--) { s->failed_pc=0x0c0bb022u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0bb024;
P_0c0bb024: /* original 944e, guest PC 0x0c0bb024 */
if(!s->budget--) { s->failed_pc=0x0c0bb024u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0c4u,2);
goto P_0c0bb026;
P_0c0bb026: /* original 4e0b, guest PC 0x0c0bb026 */
if(!s->budget--) { s->failed_pc=0x0c0bb026u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb02au;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb02au) { target=s->pc; goto dispatch; }
goto P_0c0bb02a;
P_0c0bb028: /* original 6552, guest PC 0x0c0bb028 */
if(!s->budget--) { s->failed_pc=0x0c0bb028u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb02a;
P_0c0bb02a: /* original 944d, guest PC 0x0c0bb02a */
if(!s->budget--) { s->failed_pc=0x0c0bb02au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0c8u,2);
goto P_0c0bb02c;
P_0c0bb02c: /* original 904b, guest PC 0x0c0bb02c */
if(!s->budget--) { s->failed_pc=0x0c0bb02cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0c6u,2);
goto P_0c0bb02e;
P_0c0bb02e: /* original 4e0b, guest PC 0x0c0bb02e */
if(!s->budget--) { s->failed_pc=0x0c0bb02eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb032u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb032u) { target=s->pc; goto dispatch; }
goto P_0c0bb032;
P_0c0bb030: /* original 05de, guest PC 0x0c0bb030 */
if(!s->budget--) { s->failed_pc=0x0c0bb030u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb032;
P_0c0bb032: /* original 944b, guest PC 0x0c0bb032 */
if(!s->budget--) { s->failed_pc=0x0c0bb032u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0ccu,2);
goto P_0c0bb034;
P_0c0bb034: /* original 9049, guest PC 0x0c0bb034 */
if(!s->budget--) { s->failed_pc=0x0c0bb034u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0cau,2);
goto P_0c0bb036;
P_0c0bb036: /* original 4e0b, guest PC 0x0c0bb036 */
if(!s->budget--) { s->failed_pc=0x0c0bb036u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb03au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb03au) { target=s->pc; goto dispatch; }
goto P_0c0bb03a;
P_0c0bb038: /* original 05de, guest PC 0x0c0bb038 */
if(!s->budget--) { s->failed_pc=0x0c0bb038u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb03a;
P_0c0bb03a: /* original 9948, guest PC 0x0c0bb03a */
if(!s->budget--) { s->failed_pc=0x0c0bb03au; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0ceu,2);
goto P_0c0bb03c;
P_0c0bb03c: /* original 9448, guest PC 0x0c0bb03c */
if(!s->budget--) { s->failed_pc=0x0c0bb03cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0d0u,2);
goto P_0c0bb03e;
P_0c0bb03e: /* original 39dc, guest PC 0x0c0bb03e */
if(!s->budget--) { s->failed_pc=0x0c0bb03eu; return 0; }
r[9]+=r[13];
goto P_0c0bb040;
P_0c0bb040: /* original 4e0b, guest PC 0x0c0bb040 */
if(!s->budget--) { s->failed_pc=0x0c0bb040u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb044u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb044u) { target=s->pc; goto dispatch; }
goto P_0c0bb044;
P_0c0bb042: /* original 6592, guest PC 0x0c0bb042 */
if(!s->budget--) { s->failed_pc=0x0c0bb042u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bb044;
P_0c0bb044: /* original 9445, guest PC 0x0c0bb044 */
if(!s->budget--) { s->failed_pc=0x0c0bb044u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0d2u,2);
goto P_0c0bb046;
P_0c0bb046: /* original 4e0b, guest PC 0x0c0bb046 */
if(!s->budget--) { s->failed_pc=0x0c0bb046u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb04au;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb04au) { target=s->pc; goto dispatch; }
goto P_0c0bb04a;
P_0c0bb048: /* original 6592, guest PC 0x0c0bb048 */
if(!s->budget--) { s->failed_pc=0x0c0bb048u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bb04a;
P_0c0bb04a: /* original 9443, guest PC 0x0c0bb04a */
if(!s->budget--) { s->failed_pc=0x0c0bb04au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0d4u,2);
goto P_0c0bb04c;
P_0c0bb04c: /* original 4e0b, guest PC 0x0c0bb04c */
if(!s->budget--) { s->failed_pc=0x0c0bb04cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb050u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb050u) { target=s->pc; goto dispatch; }
goto P_0c0bb050;
P_0c0bb04e: /* original 6592, guest PC 0x0c0bb04e */
if(!s->budget--) { s->failed_pc=0x0c0bb04eu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bb050;
P_0c0bb050: /* original 9441, guest PC 0x0c0bb050 */
if(!s->budget--) { s->failed_pc=0x0c0bb050u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0d6u,2);
goto P_0c0bb052;
P_0c0bb052: /* original 4e0b, guest PC 0x0c0bb052 */
if(!s->budget--) { s->failed_pc=0x0c0bb052u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb056u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb056u) { target=s->pc; goto dispatch; }
goto P_0c0bb056;
P_0c0bb054: /* original 6592, guest PC 0x0c0bb054 */
if(!s->budget--) { s->failed_pc=0x0c0bb054u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bb056;
P_0c0bb056: /* original 9c3f, guest PC 0x0c0bb056 */
if(!s->budget--) { s->failed_pc=0x0c0bb056u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0d8u,2);
goto P_0c0bb058;
P_0c0bb058: /* original 943f, guest PC 0x0c0bb058 */
if(!s->budget--) { s->failed_pc=0x0c0bb058u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0dau,2);
goto P_0c0bb05a;
P_0c0bb05a: /* original 3cdc, guest PC 0x0c0bb05a */
if(!s->budget--) { s->failed_pc=0x0c0bb05au; return 0; }
r[12]+=r[13];
goto P_0c0bb05c;
P_0c0bb05c: /* original 4e0b, guest PC 0x0c0bb05c */
if(!s->budget--) { s->failed_pc=0x0c0bb05cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb060u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb060u) { target=s->pc; goto dispatch; }
goto P_0c0bb060;
P_0c0bb05e: /* original 65c2, guest PC 0x0c0bb05e */
if(!s->budget--) { s->failed_pc=0x0c0bb05eu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bb060;
P_0c0bb060: /* original 943c, guest PC 0x0c0bb060 */
if(!s->budget--) { s->failed_pc=0x0c0bb060u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0dcu,2);
goto P_0c0bb062;
P_0c0bb062: /* original 4e0b, guest PC 0x0c0bb062 */
if(!s->budget--) { s->failed_pc=0x0c0bb062u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb066u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb066u) { target=s->pc; goto dispatch; }
goto P_0c0bb066;
P_0c0bb064: /* original 65c2, guest PC 0x0c0bb064 */
if(!s->budget--) { s->failed_pc=0x0c0bb064u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bb066;
P_0c0bb066: /* original 943a, guest PC 0x0c0bb066 */
if(!s->budget--) { s->failed_pc=0x0c0bb066u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0deu,2);
goto P_0c0bb068;
P_0c0bb068: /* original 4e0b, guest PC 0x0c0bb068 */
if(!s->budget--) { s->failed_pc=0x0c0bb068u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb06cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb06cu) { target=s->pc; goto dispatch; }
goto P_0c0bb06c;
P_0c0bb06a: /* original 65c2, guest PC 0x0c0bb06a */
if(!s->budget--) { s->failed_pc=0x0c0bb06au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bb06c;
P_0c0bb06c: /* original 9438, guest PC 0x0c0bb06c */
if(!s->budget--) { s->failed_pc=0x0c0bb06cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0e0u,2);
goto P_0c0bb06e;
P_0c0bb06e: /* original 4e0b, guest PC 0x0c0bb06e */
if(!s->budget--) { s->failed_pc=0x0c0bb06eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb072u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb072u) { target=s->pc; goto dispatch; }
goto P_0c0bb072;
P_0c0bb070: /* original 65c2, guest PC 0x0c0bb070 */
if(!s->budget--) { s->failed_pc=0x0c0bb070u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bb072;
P_0c0bb072: /* original 9b36, guest PC 0x0c0bb072 */
if(!s->budget--) { s->failed_pc=0x0c0bb072u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb0e2u,2);
goto P_0c0bb074;
P_0c0bb074: /* original 3bdc, guest PC 0x0c0bb074 */
if(!s->budget--) { s->failed_pc=0x0c0bb074u; return 0; }
r[11]+=r[13];
goto P_0c0bb076;
P_0c0bb076: /* original a037, guest PC 0x0c0bb076 */
if(!s->budget--) { s->failed_pc=0x0c0bb076u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bb0e8;
P_0c0bb078: /* original 65b2, guest PC 0x0c0bb078 */
if(!s->budget--) { s->failed_pc=0x0c0bb078u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0bb07au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bb07au; return 0; } return 1;
P_0c0bb0e8: /* original 94ab, guest PC 0x0c0bb0e8 */
if(!s->budget--) { s->failed_pc=0x0c0bb0e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb242u,2);
goto P_0c0bb0ea;
P_0c0bb0ea: /* original 4e0b, guest PC 0x0c0bb0ea */
if(!s->budget--) { s->failed_pc=0x0c0bb0eau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb0eeu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb0eeu) { target=s->pc; goto dispatch; }
goto P_0c0bb0ee;
P_0c0bb0ec: /* original 0009, guest PC 0x0c0bb0ec */
if(!s->budget--) { s->failed_pc=0x0c0bb0ecu; return 0; }
goto P_0c0bb0ee;
P_0c0bb0ee: /* original 94a9, guest PC 0x0c0bb0ee */
if(!s->budget--) { s->failed_pc=0x0c0bb0eeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb244u,2);
goto P_0c0bb0f0;
P_0c0bb0f0: /* original 4e0b, guest PC 0x0c0bb0f0 */
if(!s->budget--) { s->failed_pc=0x0c0bb0f0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb0f4u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb0f4u) { target=s->pc; goto dispatch; }
goto P_0c0bb0f4;
P_0c0bb0f2: /* original 65b2, guest PC 0x0c0bb0f2 */
if(!s->budget--) { s->failed_pc=0x0c0bb0f2u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bb0f4;
P_0c0bb0f4: /* original 94a7, guest PC 0x0c0bb0f4 */
if(!s->budget--) { s->failed_pc=0x0c0bb0f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb246u,2);
goto P_0c0bb0f6;
P_0c0bb0f6: /* original 4e0b, guest PC 0x0c0bb0f6 */
if(!s->budget--) { s->failed_pc=0x0c0bb0f6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb0fau;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb0fau) { target=s->pc; goto dispatch; }
goto P_0c0bb0fa;
P_0c0bb0f8: /* original 65b2, guest PC 0x0c0bb0f8 */
if(!s->budget--) { s->failed_pc=0x0c0bb0f8u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bb0fa;
P_0c0bb0fa: /* original 94a5, guest PC 0x0c0bb0fa */
if(!s->budget--) { s->failed_pc=0x0c0bb0fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb248u,2);
goto P_0c0bb0fc;
P_0c0bb0fc: /* original 4e0b, guest PC 0x0c0bb0fc */
if(!s->budget--) { s->failed_pc=0x0c0bb0fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb100u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb100u) { target=s->pc; goto dispatch; }
goto P_0c0bb100;
P_0c0bb0fe: /* original 65b2, guest PC 0x0c0bb0fe */
if(!s->budget--) { s->failed_pc=0x0c0bb0feu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bb100;
P_0c0bb100: /* original 9aa3, guest PC 0x0c0bb100 */
if(!s->budget--) { s->failed_pc=0x0c0bb100u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb24au,2);
goto P_0c0bb102;
P_0c0bb102: /* original 94a3, guest PC 0x0c0bb102 */
if(!s->budget--) { s->failed_pc=0x0c0bb102u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb24cu,2);
goto P_0c0bb104;
P_0c0bb104: /* original 3adc, guest PC 0x0c0bb104 */
if(!s->budget--) { s->failed_pc=0x0c0bb104u; return 0; }
r[10]+=r[13];
goto P_0c0bb106;
P_0c0bb106: /* original 4e0b, guest PC 0x0c0bb106 */
if(!s->budget--) { s->failed_pc=0x0c0bb106u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb10au;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb10au) { target=s->pc; goto dispatch; }
goto P_0c0bb10a;
P_0c0bb108: /* original 65a2, guest PC 0x0c0bb108 */
if(!s->budget--) { s->failed_pc=0x0c0bb108u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bb10a;
P_0c0bb10a: /* original 94a0, guest PC 0x0c0bb10a */
if(!s->budget--) { s->failed_pc=0x0c0bb10au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb24eu,2);
goto P_0c0bb10c;
P_0c0bb10c: /* original 4e0b, guest PC 0x0c0bb10c */
if(!s->budget--) { s->failed_pc=0x0c0bb10cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb110u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb110u) { target=s->pc; goto dispatch; }
goto P_0c0bb110;
P_0c0bb10e: /* original 65a2, guest PC 0x0c0bb10e */
if(!s->budget--) { s->failed_pc=0x0c0bb10eu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bb110;
P_0c0bb110: /* original 949e, guest PC 0x0c0bb110 */
if(!s->budget--) { s->failed_pc=0x0c0bb110u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb250u,2);
goto P_0c0bb112;
P_0c0bb112: /* original 4e0b, guest PC 0x0c0bb112 */
if(!s->budget--) { s->failed_pc=0x0c0bb112u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb116u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb116u) { target=s->pc; goto dispatch; }
goto P_0c0bb116;
P_0c0bb114: /* original 65a2, guest PC 0x0c0bb114 */
if(!s->budget--) { s->failed_pc=0x0c0bb114u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bb116;
P_0c0bb116: /* original 949c, guest PC 0x0c0bb116 */
if(!s->budget--) { s->failed_pc=0x0c0bb116u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb252u,2);
goto P_0c0bb118;
P_0c0bb118: /* original 4e0b, guest PC 0x0c0bb118 */
if(!s->budget--) { s->failed_pc=0x0c0bb118u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb11cu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb11cu) { target=s->pc; goto dispatch; }
goto P_0c0bb11c;
P_0c0bb11a: /* original 65a2, guest PC 0x0c0bb11a */
if(!s->budget--) { s->failed_pc=0x0c0bb11au; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bb11c;
P_0c0bb11c: /* original 949a, guest PC 0x0c0bb11c */
if(!s->budget--) { s->failed_pc=0x0c0bb11cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb254u,2);
goto P_0c0bb11e;
P_0c0bb11e: /* original 65f2, guest PC 0x0c0bb11e */
if(!s->budget--) { s->failed_pc=0x0c0bb11eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bb120;
P_0c0bb120: /* original 4e0b, guest PC 0x0c0bb120 */
if(!s->budget--) { s->failed_pc=0x0c0bb120u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb124u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb124u) { target=s->pc; goto dispatch; }
goto P_0c0bb124;
P_0c0bb122: /* original 6552, guest PC 0x0c0bb122 */
if(!s->budget--) { s->failed_pc=0x0c0bb122u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb124;
P_0c0bb124: /* original 9497, guest PC 0x0c0bb124 */
if(!s->budget--) { s->failed_pc=0x0c0bb124u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb256u,2);
goto P_0c0bb126;
P_0c0bb126: /* original 55f1, guest PC 0x0c0bb126 */
if(!s->budget--) { s->failed_pc=0x0c0bb126u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0bb128;
P_0c0bb128: /* original 4e0b, guest PC 0x0c0bb128 */
if(!s->budget--) { s->failed_pc=0x0c0bb128u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb12cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb12cu) { target=s->pc; goto dispatch; }
goto P_0c0bb12c;
P_0c0bb12a: /* original 6552, guest PC 0x0c0bb12a */
if(!s->budget--) { s->failed_pc=0x0c0bb12au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb12c;
P_0c0bb12c: /* original 9494, guest PC 0x0c0bb12c */
if(!s->budget--) { s->failed_pc=0x0c0bb12cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb258u,2);
goto P_0c0bb12e;
P_0c0bb12e: /* original 4e0b, guest PC 0x0c0bb12e */
if(!s->budget--) { s->failed_pc=0x0c0bb12eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb132u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb132u) { target=s->pc; goto dispatch; }
goto P_0c0bb132;
P_0c0bb130: /* original 6592, guest PC 0x0c0bb130 */
if(!s->budget--) { s->failed_pc=0x0c0bb130u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bb132;
P_0c0bb132: /* original 9492, guest PC 0x0c0bb132 */
if(!s->budget--) { s->failed_pc=0x0c0bb132u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb25au,2);
goto P_0c0bb134;
P_0c0bb134: /* original 4e0b, guest PC 0x0c0bb134 */
if(!s->budget--) { s->failed_pc=0x0c0bb134u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb138u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb138u) { target=s->pc; goto dispatch; }
goto P_0c0bb138;
P_0c0bb136: /* original 6592, guest PC 0x0c0bb136 */
if(!s->budget--) { s->failed_pc=0x0c0bb136u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bb138;
P_0c0bb138: /* original 9490, guest PC 0x0c0bb138 */
if(!s->budget--) { s->failed_pc=0x0c0bb138u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb25cu,2);
goto P_0c0bb13a;
P_0c0bb13a: /* original 4e0b, guest PC 0x0c0bb13a */
if(!s->budget--) { s->failed_pc=0x0c0bb13au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb13eu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb13eu) { target=s->pc; goto dispatch; }
goto P_0c0bb13e;
P_0c0bb13c: /* original 6592, guest PC 0x0c0bb13c */
if(!s->budget--) { s->failed_pc=0x0c0bb13cu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bb13e;
P_0c0bb13e: /* original 948e, guest PC 0x0c0bb13e */
if(!s->budget--) { s->failed_pc=0x0c0bb13eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb25eu,2);
goto P_0c0bb140;
P_0c0bb140: /* original 4e0b, guest PC 0x0c0bb140 */
if(!s->budget--) { s->failed_pc=0x0c0bb140u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb144u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb144u) { target=s->pc; goto dispatch; }
goto P_0c0bb144;
P_0c0bb142: /* original 6592, guest PC 0x0c0bb142 */
if(!s->budget--) { s->failed_pc=0x0c0bb142u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bb144;
P_0c0bb144: /* original 948c, guest PC 0x0c0bb144 */
if(!s->budget--) { s->failed_pc=0x0c0bb144u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb260u,2);
goto P_0c0bb146;
P_0c0bb146: /* original 4e0b, guest PC 0x0c0bb146 */
if(!s->budget--) { s->failed_pc=0x0c0bb146u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb14au;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb14au) { target=s->pc; goto dispatch; }
goto P_0c0bb14a;
P_0c0bb148: /* original 65c2, guest PC 0x0c0bb148 */
if(!s->budget--) { s->failed_pc=0x0c0bb148u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bb14a;
P_0c0bb14a: /* original 948a, guest PC 0x0c0bb14a */
if(!s->budget--) { s->failed_pc=0x0c0bb14au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb262u,2);
goto P_0c0bb14c;
P_0c0bb14c: /* original 4e0b, guest PC 0x0c0bb14c */
if(!s->budget--) { s->failed_pc=0x0c0bb14cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb150u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb150u) { target=s->pc; goto dispatch; }
goto P_0c0bb150;
P_0c0bb14e: /* original 65c2, guest PC 0x0c0bb14e */
if(!s->budget--) { s->failed_pc=0x0c0bb14eu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bb150;
P_0c0bb150: /* original 9488, guest PC 0x0c0bb150 */
if(!s->budget--) { s->failed_pc=0x0c0bb150u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb264u,2);
goto P_0c0bb152;
P_0c0bb152: /* original 4e0b, guest PC 0x0c0bb152 */
if(!s->budget--) { s->failed_pc=0x0c0bb152u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb156u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb156u) { target=s->pc; goto dispatch; }
goto P_0c0bb156;
P_0c0bb154: /* original 65c2, guest PC 0x0c0bb154 */
if(!s->budget--) { s->failed_pc=0x0c0bb154u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bb156;
P_0c0bb156: /* original 9486, guest PC 0x0c0bb156 */
if(!s->budget--) { s->failed_pc=0x0c0bb156u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb266u,2);
goto P_0c0bb158;
P_0c0bb158: /* original 4e0b, guest PC 0x0c0bb158 */
if(!s->budget--) { s->failed_pc=0x0c0bb158u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb15cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb15cu) { target=s->pc; goto dispatch; }
goto P_0c0bb15c;
P_0c0bb15a: /* original 65c2, guest PC 0x0c0bb15a */
if(!s->budget--) { s->failed_pc=0x0c0bb15au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bb15c;
P_0c0bb15c: /* original 9484, guest PC 0x0c0bb15c */
if(!s->budget--) { s->failed_pc=0x0c0bb15cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb268u,2);
goto P_0c0bb15e;
P_0c0bb15e: /* original 4e0b, guest PC 0x0c0bb15e */
if(!s->budget--) { s->failed_pc=0x0c0bb15eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb162u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb162u) { target=s->pc; goto dispatch; }
goto P_0c0bb162;
P_0c0bb160: /* original 65b2, guest PC 0x0c0bb160 */
if(!s->budget--) { s->failed_pc=0x0c0bb160u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bb162;
P_0c0bb162: /* original 9482, guest PC 0x0c0bb162 */
if(!s->budget--) { s->failed_pc=0x0c0bb162u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb26au,2);
goto P_0c0bb164;
P_0c0bb164: /* original 4e0b, guest PC 0x0c0bb164 */
if(!s->budget--) { s->failed_pc=0x0c0bb164u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb168u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb168u) { target=s->pc; goto dispatch; }
goto P_0c0bb168;
P_0c0bb166: /* original 65b2, guest PC 0x0c0bb166 */
if(!s->budget--) { s->failed_pc=0x0c0bb166u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bb168;
P_0c0bb168: /* original 9480, guest PC 0x0c0bb168 */
if(!s->budget--) { s->failed_pc=0x0c0bb168u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb26cu,2);
goto P_0c0bb16a;
P_0c0bb16a: /* original 4e0b, guest PC 0x0c0bb16a */
if(!s->budget--) { s->failed_pc=0x0c0bb16au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb16eu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb16eu) { target=s->pc; goto dispatch; }
goto P_0c0bb16e;
P_0c0bb16c: /* original 65b2, guest PC 0x0c0bb16c */
if(!s->budget--) { s->failed_pc=0x0c0bb16cu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bb16e;
P_0c0bb16e: /* original 947e, guest PC 0x0c0bb16e */
if(!s->budget--) { s->failed_pc=0x0c0bb16eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb26eu,2);
goto P_0c0bb170;
P_0c0bb170: /* original 4e0b, guest PC 0x0c0bb170 */
if(!s->budget--) { s->failed_pc=0x0c0bb170u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb174u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb174u) { target=s->pc; goto dispatch; }
goto P_0c0bb174;
P_0c0bb172: /* original 65b2, guest PC 0x0c0bb172 */
if(!s->budget--) { s->failed_pc=0x0c0bb172u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bb174;
P_0c0bb174: /* original 947c, guest PC 0x0c0bb174 */
if(!s->budget--) { s->failed_pc=0x0c0bb174u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb270u,2);
goto P_0c0bb176;
P_0c0bb176: /* original 4e0b, guest PC 0x0c0bb176 */
if(!s->budget--) { s->failed_pc=0x0c0bb176u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb17au;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb17au) { target=s->pc; goto dispatch; }
goto P_0c0bb17a;
P_0c0bb178: /* original 65a2, guest PC 0x0c0bb178 */
if(!s->budget--) { s->failed_pc=0x0c0bb178u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bb17a;
P_0c0bb17a: /* original 947a, guest PC 0x0c0bb17a */
if(!s->budget--) { s->failed_pc=0x0c0bb17au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb272u,2);
goto P_0c0bb17c;
P_0c0bb17c: /* original 4e0b, guest PC 0x0c0bb17c */
if(!s->budget--) { s->failed_pc=0x0c0bb17cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb180u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb180u) { target=s->pc; goto dispatch; }
goto P_0c0bb180;
P_0c0bb17e: /* original 65a2, guest PC 0x0c0bb17e */
if(!s->budget--) { s->failed_pc=0x0c0bb17eu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bb180;
P_0c0bb180: /* original 9478, guest PC 0x0c0bb180 */
if(!s->budget--) { s->failed_pc=0x0c0bb180u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb274u,2);
goto P_0c0bb182;
P_0c0bb182: /* original 4e0b, guest PC 0x0c0bb182 */
if(!s->budget--) { s->failed_pc=0x0c0bb182u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb186u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb186u) { target=s->pc; goto dispatch; }
goto P_0c0bb186;
P_0c0bb184: /* original 65a2, guest PC 0x0c0bb184 */
if(!s->budget--) { s->failed_pc=0x0c0bb184u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bb186;
P_0c0bb186: /* original 9476, guest PC 0x0c0bb186 */
if(!s->budget--) { s->failed_pc=0x0c0bb186u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb276u,2);
goto P_0c0bb188;
P_0c0bb188: /* original 4e0b, guest PC 0x0c0bb188 */
if(!s->budget--) { s->failed_pc=0x0c0bb188u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb18cu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb18cu) { target=s->pc; goto dispatch; }
goto P_0c0bb18c;
P_0c0bb18a: /* original 65a2, guest PC 0x0c0bb18a */
if(!s->budget--) { s->failed_pc=0x0c0bb18au; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bb18c;
P_0c0bb18c: /* original 9574, guest PC 0x0c0bb18c */
if(!s->budget--) { s->failed_pc=0x0c0bb18cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb278u,2);
goto P_0c0bb18e;
P_0c0bb18e: /* original 35dc, guest PC 0x0c0bb18e */
if(!s->budget--) { s->failed_pc=0x0c0bb18eu; return 0; }
r[5]+=r[13];
goto P_0c0bb190;
P_0c0bb190: /* original 2f52, guest PC 0x0c0bb190 */
if(!s->budget--) { s->failed_pc=0x0c0bb190u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bb192;
P_0c0bb192: /* original 9472, guest PC 0x0c0bb192 */
if(!s->budget--) { s->failed_pc=0x0c0bb192u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb27au,2);
goto P_0c0bb194;
P_0c0bb194: /* original 4e0b, guest PC 0x0c0bb194 */
if(!s->budget--) { s->failed_pc=0x0c0bb194u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb198u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb198u) { target=s->pc; goto dispatch; }
goto P_0c0bb198;
P_0c0bb196: /* original 6552, guest PC 0x0c0bb196 */
if(!s->budget--) { s->failed_pc=0x0c0bb196u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb198;
P_0c0bb198: /* original 9470, guest PC 0x0c0bb198 */
if(!s->budget--) { s->failed_pc=0x0c0bb198u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb27cu,2);
goto P_0c0bb19a;
P_0c0bb19a: /* original 65f2, guest PC 0x0c0bb19a */
if(!s->budget--) { s->failed_pc=0x0c0bb19au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bb19c;
P_0c0bb19c: /* original 4e0b, guest PC 0x0c0bb19c */
if(!s->budget--) { s->failed_pc=0x0c0bb19cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb1a0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb1a0u) { target=s->pc; goto dispatch; }
goto P_0c0bb1a0;
P_0c0bb19e: /* original 6552, guest PC 0x0c0bb19e */
if(!s->budget--) { s->failed_pc=0x0c0bb19eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb1a0;
P_0c0bb1a0: /* original 956d, guest PC 0x0c0bb1a0 */
if(!s->budget--) { s->failed_pc=0x0c0bb1a0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb27eu,2);
goto P_0c0bb1a2;
P_0c0bb1a2: /* original 35dc, guest PC 0x0c0bb1a2 */
if(!s->budget--) { s->failed_pc=0x0c0bb1a2u; return 0; }
r[5]+=r[13];
goto P_0c0bb1a4;
P_0c0bb1a4: /* original 2f52, guest PC 0x0c0bb1a4 */
if(!s->budget--) { s->failed_pc=0x0c0bb1a4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bb1a6;
P_0c0bb1a6: /* original 946b, guest PC 0x0c0bb1a6 */
if(!s->budget--) { s->failed_pc=0x0c0bb1a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb280u,2);
goto P_0c0bb1a8;
P_0c0bb1a8: /* original 4e0b, guest PC 0x0c0bb1a8 */
if(!s->budget--) { s->failed_pc=0x0c0bb1a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb1acu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb1acu) { target=s->pc; goto dispatch; }
goto P_0c0bb1ac;
P_0c0bb1aa: /* original 6552, guest PC 0x0c0bb1aa */
if(!s->budget--) { s->failed_pc=0x0c0bb1aau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb1ac;
P_0c0bb1ac: /* original 9469, guest PC 0x0c0bb1ac */
if(!s->budget--) { s->failed_pc=0x0c0bb1acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb282u,2);
goto P_0c0bb1ae;
P_0c0bb1ae: /* original 65f2, guest PC 0x0c0bb1ae */
if(!s->budget--) { s->failed_pc=0x0c0bb1aeu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bb1b0;
P_0c0bb1b0: /* original 4e0b, guest PC 0x0c0bb1b0 */
if(!s->budget--) { s->failed_pc=0x0c0bb1b0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb1b4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb1b4u) { target=s->pc; goto dispatch; }
goto P_0c0bb1b4;
P_0c0bb1b2: /* original 6552, guest PC 0x0c0bb1b2 */
if(!s->budget--) { s->failed_pc=0x0c0bb1b2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb1b4;
P_0c0bb1b4: /* original 9467, guest PC 0x0c0bb1b4 */
if(!s->budget--) { s->failed_pc=0x0c0bb1b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb286u,2);
goto P_0c0bb1b6;
P_0c0bb1b6: /* original 9065, guest PC 0x0c0bb1b6 */
if(!s->budget--) { s->failed_pc=0x0c0bb1b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb284u,2);
goto P_0c0bb1b8;
P_0c0bb1b8: /* original 4e0b, guest PC 0x0c0bb1b8 */
if(!s->budget--) { s->failed_pc=0x0c0bb1b8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb1bcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb1bcu) { target=s->pc; goto dispatch; }
goto P_0c0bb1bc;
P_0c0bb1ba: /* original 05de, guest PC 0x0c0bb1ba */
if(!s->budget--) { s->failed_pc=0x0c0bb1bau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb1bc;
P_0c0bb1bc: /* original 9564, guest PC 0x0c0bb1bc */
if(!s->budget--) { s->failed_pc=0x0c0bb1bcu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb288u,2);
goto P_0c0bb1be;
P_0c0bb1be: /* original 35dc, guest PC 0x0c0bb1be */
if(!s->budget--) { s->failed_pc=0x0c0bb1beu; return 0; }
r[5]+=r[13];
goto P_0c0bb1c0;
P_0c0bb1c0: /* original 2f52, guest PC 0x0c0bb1c0 */
if(!s->budget--) { s->failed_pc=0x0c0bb1c0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bb1c2;
P_0c0bb1c2: /* original 9462, guest PC 0x0c0bb1c2 */
if(!s->budget--) { s->failed_pc=0x0c0bb1c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb28au,2);
goto P_0c0bb1c4;
P_0c0bb1c4: /* original 4e0b, guest PC 0x0c0bb1c4 */
if(!s->budget--) { s->failed_pc=0x0c0bb1c4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb1c8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb1c8u) { target=s->pc; goto dispatch; }
goto P_0c0bb1c8;
P_0c0bb1c6: /* original 6552, guest PC 0x0c0bb1c6 */
if(!s->budget--) { s->failed_pc=0x0c0bb1c6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb1c8;
P_0c0bb1c8: /* original 9460, guest PC 0x0c0bb1c8 */
if(!s->budget--) { s->failed_pc=0x0c0bb1c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb28cu,2);
goto P_0c0bb1ca;
P_0c0bb1ca: /* original 65f2, guest PC 0x0c0bb1ca */
if(!s->budget--) { s->failed_pc=0x0c0bb1cau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bb1cc;
P_0c0bb1cc: /* original 4e0b, guest PC 0x0c0bb1cc */
if(!s->budget--) { s->failed_pc=0x0c0bb1ccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb1d0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb1d0u) { target=s->pc; goto dispatch; }
goto P_0c0bb1d0;
P_0c0bb1ce: /* original 6552, guest PC 0x0c0bb1ce */
if(!s->budget--) { s->failed_pc=0x0c0bb1ceu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb1d0;
P_0c0bb1d0: /* original 945e, guest PC 0x0c0bb1d0 */
if(!s->budget--) { s->failed_pc=0x0c0bb1d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb290u,2);
goto P_0c0bb1d2;
P_0c0bb1d2: /* original 905c, guest PC 0x0c0bb1d2 */
if(!s->budget--) { s->failed_pc=0x0c0bb1d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb28eu,2);
goto P_0c0bb1d4;
P_0c0bb1d4: /* original 4e0b, guest PC 0x0c0bb1d4 */
if(!s->budget--) { s->failed_pc=0x0c0bb1d4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb1d8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb1d8u) { target=s->pc; goto dispatch; }
goto P_0c0bb1d8;
P_0c0bb1d6: /* original 05de, guest PC 0x0c0bb1d6 */
if(!s->budget--) { s->failed_pc=0x0c0bb1d6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb1d8;
P_0c0bb1d8: /* original 955b, guest PC 0x0c0bb1d8 */
if(!s->budget--) { s->failed_pc=0x0c0bb1d8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb292u,2);
goto P_0c0bb1da;
P_0c0bb1da: /* original 35dc, guest PC 0x0c0bb1da */
if(!s->budget--) { s->failed_pc=0x0c0bb1dau; return 0; }
r[5]+=r[13];
goto P_0c0bb1dc;
P_0c0bb1dc: /* original 2f52, guest PC 0x0c0bb1dc */
if(!s->budget--) { s->failed_pc=0x0c0bb1dcu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bb1de;
P_0c0bb1de: /* original 9459, guest PC 0x0c0bb1de */
if(!s->budget--) { s->failed_pc=0x0c0bb1deu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb294u,2);
goto P_0c0bb1e0;
P_0c0bb1e0: /* original 4e0b, guest PC 0x0c0bb1e0 */
if(!s->budget--) { s->failed_pc=0x0c0bb1e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb1e4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb1e4u) { target=s->pc; goto dispatch; }
goto P_0c0bb1e4;
P_0c0bb1e2: /* original 6552, guest PC 0x0c0bb1e2 */
if(!s->budget--) { s->failed_pc=0x0c0bb1e2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb1e4;
P_0c0bb1e4: /* original 9457, guest PC 0x0c0bb1e4 */
if(!s->budget--) { s->failed_pc=0x0c0bb1e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb296u,2);
goto P_0c0bb1e6;
P_0c0bb1e6: /* original 65f2, guest PC 0x0c0bb1e6 */
if(!s->budget--) { s->failed_pc=0x0c0bb1e6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bb1e8;
P_0c0bb1e8: /* original 4e0b, guest PC 0x0c0bb1e8 */
if(!s->budget--) { s->failed_pc=0x0c0bb1e8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb1ecu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb1ecu) { target=s->pc; goto dispatch; }
goto P_0c0bb1ec;
P_0c0bb1ea: /* original 6552, guest PC 0x0c0bb1ea */
if(!s->budget--) { s->failed_pc=0x0c0bb1eau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb1ec;
P_0c0bb1ec: /* original 9455, guest PC 0x0c0bb1ec */
if(!s->budget--) { s->failed_pc=0x0c0bb1ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb29au,2);
goto P_0c0bb1ee;
P_0c0bb1ee: /* original 9053, guest PC 0x0c0bb1ee */
if(!s->budget--) { s->failed_pc=0x0c0bb1eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb298u,2);
goto P_0c0bb1f0;
P_0c0bb1f0: /* original 4e0b, guest PC 0x0c0bb1f0 */
if(!s->budget--) { s->failed_pc=0x0c0bb1f0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb1f4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb1f4u) { target=s->pc; goto dispatch; }
goto P_0c0bb1f4;
P_0c0bb1f2: /* original 05de, guest PC 0x0c0bb1f2 */
if(!s->budget--) { s->failed_pc=0x0c0bb1f2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb1f4;
P_0c0bb1f4: /* original 9552, guest PC 0x0c0bb1f4 */
if(!s->budget--) { s->failed_pc=0x0c0bb1f4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb29cu,2);
goto P_0c0bb1f6;
P_0c0bb1f6: /* original 35dc, guest PC 0x0c0bb1f6 */
if(!s->budget--) { s->failed_pc=0x0c0bb1f6u; return 0; }
r[5]+=r[13];
goto P_0c0bb1f8;
P_0c0bb1f8: /* original 2f52, guest PC 0x0c0bb1f8 */
if(!s->budget--) { s->failed_pc=0x0c0bb1f8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bb1fa;
P_0c0bb1fa: /* original 9450, guest PC 0x0c0bb1fa */
if(!s->budget--) { s->failed_pc=0x0c0bb1fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb29eu,2);
goto P_0c0bb1fc;
P_0c0bb1fc: /* original 4e0b, guest PC 0x0c0bb1fc */
if(!s->budget--) { s->failed_pc=0x0c0bb1fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb200u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb200u) { target=s->pc; goto dispatch; }
goto P_0c0bb200;
P_0c0bb1fe: /* original 6552, guest PC 0x0c0bb1fe */
if(!s->budget--) { s->failed_pc=0x0c0bb1feu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb200;
P_0c0bb200: /* original 944e, guest PC 0x0c0bb200 */
if(!s->budget--) { s->failed_pc=0x0c0bb200u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb2a0u,2);
goto P_0c0bb202;
P_0c0bb202: /* original 65f2, guest PC 0x0c0bb202 */
if(!s->budget--) { s->failed_pc=0x0c0bb202u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bb204;
P_0c0bb204: /* original 4e0b, guest PC 0x0c0bb204 */
if(!s->budget--) { s->failed_pc=0x0c0bb204u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb208u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb208u) { target=s->pc; goto dispatch; }
goto P_0c0bb208;
P_0c0bb206: /* original 6552, guest PC 0x0c0bb206 */
if(!s->budget--) { s->failed_pc=0x0c0bb206u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb208;
P_0c0bb208: /* original 954b, guest PC 0x0c0bb208 */
if(!s->budget--) { s->failed_pc=0x0c0bb208u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb2a2u,2);
goto P_0c0bb20a;
P_0c0bb20a: /* original 35dc, guest PC 0x0c0bb20a */
if(!s->budget--) { s->failed_pc=0x0c0bb20au; return 0; }
r[5]+=r[13];
goto P_0c0bb20c;
P_0c0bb20c: /* original 2f52, guest PC 0x0c0bb20c */
if(!s->budget--) { s->failed_pc=0x0c0bb20cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bb20e;
P_0c0bb20e: /* original 9449, guest PC 0x0c0bb20e */
if(!s->budget--) { s->failed_pc=0x0c0bb20eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb2a4u,2);
goto P_0c0bb210;
P_0c0bb210: /* original 4e0b, guest PC 0x0c0bb210 */
if(!s->budget--) { s->failed_pc=0x0c0bb210u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb214u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb214u) { target=s->pc; goto dispatch; }
goto P_0c0bb214;
P_0c0bb212: /* original 6552, guest PC 0x0c0bb212 */
if(!s->budget--) { s->failed_pc=0x0c0bb212u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb214;
P_0c0bb214: /* original 9447, guest PC 0x0c0bb214 */
if(!s->budget--) { s->failed_pc=0x0c0bb214u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb2a6u,2);
goto P_0c0bb216;
P_0c0bb216: /* original 65f2, guest PC 0x0c0bb216 */
if(!s->budget--) { s->failed_pc=0x0c0bb216u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bb218;
P_0c0bb218: /* original 4e0b, guest PC 0x0c0bb218 */
if(!s->budget--) { s->failed_pc=0x0c0bb218u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb21cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb21cu) { target=s->pc; goto dispatch; }
goto P_0c0bb21c;
P_0c0bb21a: /* original 6552, guest PC 0x0c0bb21a */
if(!s->budget--) { s->failed_pc=0x0c0bb21au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb21c;
P_0c0bb21c: /* original 9445, guest PC 0x0c0bb21c */
if(!s->budget--) { s->failed_pc=0x0c0bb21cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb2aau,2);
goto P_0c0bb21e;
P_0c0bb21e: /* original 9043, guest PC 0x0c0bb21e */
if(!s->budget--) { s->failed_pc=0x0c0bb21eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb2a8u,2);
goto P_0c0bb220;
P_0c0bb220: /* original 4e0b, guest PC 0x0c0bb220 */
if(!s->budget--) { s->failed_pc=0x0c0bb220u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb224u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb224u) { target=s->pc; goto dispatch; }
goto P_0c0bb224;
P_0c0bb222: /* original 05de, guest PC 0x0c0bb222 */
if(!s->budget--) { s->failed_pc=0x0c0bb222u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb224;
P_0c0bb224: /* original 9443, guest PC 0x0c0bb224 */
if(!s->budget--) { s->failed_pc=0x0c0bb224u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb2aeu,2);
goto P_0c0bb226;
P_0c0bb226: /* original 9041, guest PC 0x0c0bb226 */
if(!s->budget--) { s->failed_pc=0x0c0bb226u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb2acu,2);
goto P_0c0bb228;
P_0c0bb228: /* original 4e0b, guest PC 0x0c0bb228 */
if(!s->budget--) { s->failed_pc=0x0c0bb228u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb22cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb22cu) { target=s->pc; goto dispatch; }
goto P_0c0bb22c;
P_0c0bb22a: /* original 05de, guest PC 0x0c0bb22a */
if(!s->budget--) { s->failed_pc=0x0c0bb22au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb22c;
P_0c0bb22c: /* original 9441, guest PC 0x0c0bb22c */
if(!s->budget--) { s->failed_pc=0x0c0bb22cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb2b2u,2);
goto P_0c0bb22e;
P_0c0bb22e: /* original 903f, guest PC 0x0c0bb22e */
if(!s->budget--) { s->failed_pc=0x0c0bb22eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb2b0u,2);
goto P_0c0bb230;
P_0c0bb230: /* original 4e0b, guest PC 0x0c0bb230 */
if(!s->budget--) { s->failed_pc=0x0c0bb230u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb234u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb234u) { target=s->pc; goto dispatch; }
goto P_0c0bb234;
P_0c0bb232: /* original 05de, guest PC 0x0c0bb232 */
if(!s->budget--) { s->failed_pc=0x0c0bb232u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb234;
P_0c0bb234: /* original 943f, guest PC 0x0c0bb234 */
if(!s->budget--) { s->failed_pc=0x0c0bb234u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb2b6u,2);
goto P_0c0bb236;
P_0c0bb236: /* original 903d, guest PC 0x0c0bb236 */
if(!s->budget--) { s->failed_pc=0x0c0bb236u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb2b4u,2);
goto P_0c0bb238;
P_0c0bb238: /* original 4e0b, guest PC 0x0c0bb238 */
if(!s->budget--) { s->failed_pc=0x0c0bb238u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb23cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb23cu) { target=s->pc; goto dispatch; }
goto P_0c0bb23c;
P_0c0bb23a: /* original 05de, guest PC 0x0c0bb23a */
if(!s->budget--) { s->failed_pc=0x0c0bb23au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb23c;
P_0c0bb23c: /* original 903c, guest PC 0x0c0bb23c */
if(!s->budget--) { s->failed_pc=0x0c0bb23cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb2b8u,2);
goto P_0c0bb23e;
P_0c0bb23e: /* original a03c, guest PC 0x0c0bb23e */
if(!s->budget--) { s->failed_pc=0x0c0bb23eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb2ba;
P_0c0bb240: /* original 05de, guest PC 0x0c0bb240 */
if(!s->budget--) { s->failed_pc=0x0c0bb240u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0bb242u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bb242u; return 0; } return 1;
P_0c0bb2ba: /* original 942a, guest PC 0x0c0bb2ba */
if(!s->budget--) { s->failed_pc=0x0c0bb2bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb312u,2);
goto P_0c0bb2bc;
P_0c0bb2bc: /* original 4e0b, guest PC 0x0c0bb2bc */
if(!s->budget--) { s->failed_pc=0x0c0bb2bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb2c0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb2c0u) { target=s->pc; goto dispatch; }
goto P_0c0bb2c0;
P_0c0bb2be: /* original 0009, guest PC 0x0c0bb2be */
if(!s->budget--) { s->failed_pc=0x0c0bb2beu; return 0; }
goto P_0c0bb2c0;
P_0c0bb2c0: /* original 9429, guest PC 0x0c0bb2c0 */
if(!s->budget--) { s->failed_pc=0x0c0bb2c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb316u,2);
goto P_0c0bb2c2;
P_0c0bb2c2: /* original 9027, guest PC 0x0c0bb2c2 */
if(!s->budget--) { s->failed_pc=0x0c0bb2c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb314u,2);
goto P_0c0bb2c4;
P_0c0bb2c4: /* original 4e0b, guest PC 0x0c0bb2c4 */
if(!s->budget--) { s->failed_pc=0x0c0bb2c4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb2c8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb2c8u) { target=s->pc; goto dispatch; }
goto P_0c0bb2c8;
P_0c0bb2c6: /* original 05de, guest PC 0x0c0bb2c6 */
if(!s->budget--) { s->failed_pc=0x0c0bb2c6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb2c8;
P_0c0bb2c8: /* original 9427, guest PC 0x0c0bb2c8 */
if(!s->budget--) { s->failed_pc=0x0c0bb2c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb31au,2);
goto P_0c0bb2ca;
P_0c0bb2ca: /* original 9025, guest PC 0x0c0bb2ca */
if(!s->budget--) { s->failed_pc=0x0c0bb2cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb318u,2);
goto P_0c0bb2cc;
P_0c0bb2cc: /* original 4e0b, guest PC 0x0c0bb2cc */
if(!s->budget--) { s->failed_pc=0x0c0bb2ccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb2d0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb2d0u) { target=s->pc; goto dispatch; }
goto P_0c0bb2d0;
P_0c0bb2ce: /* original 05de, guest PC 0x0c0bb2ce */
if(!s->budget--) { s->failed_pc=0x0c0bb2ceu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb2d0;
P_0c0bb2d0: /* original 9425, guest PC 0x0c0bb2d0 */
if(!s->budget--) { s->failed_pc=0x0c0bb2d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb31eu,2);
goto P_0c0bb2d2;
P_0c0bb2d2: /* original 9023, guest PC 0x0c0bb2d2 */
if(!s->budget--) { s->failed_pc=0x0c0bb2d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb31cu,2);
goto P_0c0bb2d4;
P_0c0bb2d4: /* original 4e0b, guest PC 0x0c0bb2d4 */
if(!s->budget--) { s->failed_pc=0x0c0bb2d4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb2d8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb2d8u) { target=s->pc; goto dispatch; }
goto P_0c0bb2d8;
P_0c0bb2d6: /* original 05de, guest PC 0x0c0bb2d6 */
if(!s->budget--) { s->failed_pc=0x0c0bb2d6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb2d8;
P_0c0bb2d8: /* original 9423, guest PC 0x0c0bb2d8 */
if(!s->budget--) { s->failed_pc=0x0c0bb2d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb322u,2);
goto P_0c0bb2da;
P_0c0bb2da: /* original 9021, guest PC 0x0c0bb2da */
if(!s->budget--) { s->failed_pc=0x0c0bb2dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb320u,2);
goto P_0c0bb2dc;
P_0c0bb2dc: /* original 4e0b, guest PC 0x0c0bb2dc */
if(!s->budget--) { s->failed_pc=0x0c0bb2dcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb2e0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb2e0u) { target=s->pc; goto dispatch; }
goto P_0c0bb2e0;
P_0c0bb2de: /* original 05de, guest PC 0x0c0bb2de */
if(!s->budget--) { s->failed_pc=0x0c0bb2deu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb2e0;
P_0c0bb2e0: /* original 9421, guest PC 0x0c0bb2e0 */
if(!s->budget--) { s->failed_pc=0x0c0bb2e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb326u,2);
goto P_0c0bb2e2;
P_0c0bb2e2: /* original 901f, guest PC 0x0c0bb2e2 */
if(!s->budget--) { s->failed_pc=0x0c0bb2e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb324u,2);
goto P_0c0bb2e4;
P_0c0bb2e4: /* original 4e0b, guest PC 0x0c0bb2e4 */
if(!s->budget--) { s->failed_pc=0x0c0bb2e4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb2e8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb2e8u) { target=s->pc; goto dispatch; }
goto P_0c0bb2e8;
P_0c0bb2e6: /* original 05de, guest PC 0x0c0bb2e6 */
if(!s->budget--) { s->failed_pc=0x0c0bb2e6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb2e8;
P_0c0bb2e8: /* original 941f, guest PC 0x0c0bb2e8 */
if(!s->budget--) { s->failed_pc=0x0c0bb2e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb32au,2);
goto P_0c0bb2ea;
P_0c0bb2ea: /* original 901d, guest PC 0x0c0bb2ea */
if(!s->budget--) { s->failed_pc=0x0c0bb2eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb328u,2);
goto P_0c0bb2ec;
P_0c0bb2ec: /* original 4e0b, guest PC 0x0c0bb2ec */
if(!s->budget--) { s->failed_pc=0x0c0bb2ecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb2f0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb2f0u) { target=s->pc; goto dispatch; }
goto P_0c0bb2f0;
P_0c0bb2ee: /* original 05de, guest PC 0x0c0bb2ee */
if(!s->budget--) { s->failed_pc=0x0c0bb2eeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb2f0;
P_0c0bb2f0: /* original 941d, guest PC 0x0c0bb2f0 */
if(!s->budget--) { s->failed_pc=0x0c0bb2f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb32eu,2);
goto P_0c0bb2f2;
P_0c0bb2f2: /* original 901b, guest PC 0x0c0bb2f2 */
if(!s->budget--) { s->failed_pc=0x0c0bb2f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb32cu,2);
goto P_0c0bb2f4;
P_0c0bb2f4: /* original 4e0b, guest PC 0x0c0bb2f4 */
if(!s->budget--) { s->failed_pc=0x0c0bb2f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb2f8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb2f8u) { target=s->pc; goto dispatch; }
goto P_0c0bb2f8;
P_0c0bb2f6: /* original 05de, guest PC 0x0c0bb2f6 */
if(!s->budget--) { s->failed_pc=0x0c0bb2f6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb2f8;
P_0c0bb2f8: /* original 941b, guest PC 0x0c0bb2f8 */
if(!s->budget--) { s->failed_pc=0x0c0bb2f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb332u,2);
goto P_0c0bb2fa;
P_0c0bb2fa: /* original 9019, guest PC 0x0c0bb2fa */
if(!s->budget--) { s->failed_pc=0x0c0bb2fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb330u,2);
goto P_0c0bb2fc;
P_0c0bb2fc: /* original 4e0b, guest PC 0x0c0bb2fc */
if(!s->budget--) { s->failed_pc=0x0c0bb2fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb300u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb300u) { target=s->pc; goto dispatch; }
goto P_0c0bb300;
P_0c0bb2fe: /* original 05de, guest PC 0x0c0bb2fe */
if(!s->budget--) { s->failed_pc=0x0c0bb2feu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb300;
P_0c0bb300: /* original 7f08, guest PC 0x0c0bb300 */
if(!s->budget--) { s->failed_pc=0x0c0bb300u; return 0; }
r[15]+=0x00000008u;
goto P_0c0bb302;
P_0c0bb302: /* original 4f26, guest PC 0x0c0bb302 */
if(!s->budget--) { s->failed_pc=0x0c0bb302u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0bb304;
P_0c0bb304: /* original 69f6, guest PC 0x0c0bb304 */
if(!s->budget--) { s->failed_pc=0x0c0bb304u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0bb306;
P_0c0bb306: /* original 6af6, guest PC 0x0c0bb306 */
if(!s->budget--) { s->failed_pc=0x0c0bb306u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0bb308;
P_0c0bb308: /* original 6bf6, guest PC 0x0c0bb308 */
if(!s->budget--) { s->failed_pc=0x0c0bb308u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0bb30a;
P_0c0bb30a: /* original 6cf6, guest PC 0x0c0bb30a */
if(!s->budget--) { s->failed_pc=0x0c0bb30au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0bb30c;
P_0c0bb30c: /* original 6df6, guest PC 0x0c0bb30c */
if(!s->budget--) { s->failed_pc=0x0c0bb30cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0bb30e;
P_0c0bb30e: /* original 000b, guest PC 0x0c0bb30e */
if(!s->budget--) { s->failed_pc=0x0c0bb30eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0bb310: /* original 6ef6, guest PC 0x0c0bb310 */
if(!s->budget--) { s->failed_pc=0x0c0bb310u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0bb312u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bb312u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
