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
int vf3_c90d_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04df6au: goto P_0c04df6a;
case 0x0c04df6cu: goto P_0c04df6c;
case 0x0c04df6eu: goto P_0c04df6e;
case 0x0c04df70u: goto P_0c04df70;
case 0x0c04df72u: goto P_0c04df72;
case 0x0c04df74u: goto P_0c04df74;
case 0x0c04df76u: goto P_0c04df76;
case 0x0c04df78u: goto P_0c04df78;
case 0x0c04df7au: goto P_0c04df7a;
case 0x0c04df7cu: goto P_0c04df7c;
case 0x0c04df7eu: goto P_0c04df7e;
case 0x0c04df80u: goto P_0c04df80;
case 0x0c04df82u: goto P_0c04df82;
case 0x0c04df84u: goto P_0c04df84;
case 0x0c04df86u: goto P_0c04df86;
case 0x0c04df88u: goto P_0c04df88;
case 0x0c04df8au: goto P_0c04df8a;
case 0x0c04df8cu: goto P_0c04df8c;
case 0x0c04df8eu: goto P_0c04df8e;
case 0x0c04df90u: goto P_0c04df90;
case 0x0c04df92u: goto P_0c04df92;
case 0x0c04df94u: goto P_0c04df94;
case 0x0c04df96u: goto P_0c04df96;
case 0x0c04df98u: goto P_0c04df98;
case 0x0c04df9au: goto P_0c04df9a;
case 0x0c04df9cu: goto P_0c04df9c;
case 0x0c04df9eu: goto P_0c04df9e;
case 0x0c04dfa0u: goto P_0c04dfa0;
case 0x0c04dfa2u: goto P_0c04dfa2;
case 0x0c04dfa4u: goto P_0c04dfa4;
case 0x0c04dfa6u: goto P_0c04dfa6;
case 0x0c04dfa8u: goto P_0c04dfa8;
case 0x0c04dfaau: goto P_0c04dfaa;
case 0x0c04dfacu: goto P_0c04dfac;
case 0x0c04dfaeu: goto P_0c04dfae;
case 0x0c04dfb0u: goto P_0c04dfb0;
case 0x0c04dfb2u: goto P_0c04dfb2;
case 0x0c04dfb4u: goto P_0c04dfb4;
case 0x0c04dfb6u: goto P_0c04dfb6;
case 0x0c04dfb8u: goto P_0c04dfb8;
case 0x0c04dfbau: goto P_0c04dfba;
case 0x0c04dfbcu: goto P_0c04dfbc;
case 0x0c04dfbeu: goto P_0c04dfbe;
case 0x0c04dfc0u: goto P_0c04dfc0;
case 0x0c04dfc2u: goto P_0c04dfc2;
case 0x0c04dfc4u: goto P_0c04dfc4;
case 0x0c04dfc6u: goto P_0c04dfc6;
case 0x0c04dfc8u: goto P_0c04dfc8;
case 0x0c04dfcau: goto P_0c04dfca;
case 0x0c04dfccu: goto P_0c04dfcc;
case 0x0c04dfceu: goto P_0c04dfce;
case 0x0c04dfd0u: goto P_0c04dfd0;
case 0x0c04dfd2u: goto P_0c04dfd2;
case 0x0c04dfd4u: goto P_0c04dfd4;
case 0x0c04dfd6u: goto P_0c04dfd6;
case 0x0c04dfd8u: goto P_0c04dfd8;
case 0x0c04dfdau: goto P_0c04dfda;
case 0x0c04dfdcu: goto P_0c04dfdc;
case 0x0c04e010u: goto P_0c04e010;
case 0x0c04e012u: goto P_0c04e012;
case 0x0c04e014u: goto P_0c04e014;
case 0x0c04e016u: goto P_0c04e016;
case 0x0c04e018u: goto P_0c04e018;
case 0x0c04e01au: goto P_0c04e01a;
case 0x0c04e01cu: goto P_0c04e01c;
case 0x0c04e01eu: goto P_0c04e01e;
case 0x0c04e020u: goto P_0c04e020;
case 0x0c04e022u: goto P_0c04e022;
case 0x0c04e024u: goto P_0c04e024;
case 0x0c04e026u: goto P_0c04e026;
case 0x0c04e028u: goto P_0c04e028;
case 0x0c04e02au: goto P_0c04e02a;
case 0x0c0503ccu: goto P_0c0503cc;
case 0x0c0503ceu: goto P_0c0503ce;
case 0x0c0503d0u: goto P_0c0503d0;
case 0x0c0503d2u: goto P_0c0503d2;
case 0x0c0503d4u: goto P_0c0503d4;
case 0x0c0503d6u: goto P_0c0503d6;
case 0x0c0503d8u: goto P_0c0503d8;
case 0x0c0503dau: goto P_0c0503da;
case 0x0c0503dcu: goto P_0c0503dc;
case 0x0c0503deu: goto P_0c0503de;
case 0x0c0503e0u: goto P_0c0503e0;
case 0x0c0503e2u: goto P_0c0503e2;
case 0x0c0503e4u: goto P_0c0503e4;
case 0x0c0503e6u: goto P_0c0503e6;
case 0x0c0503e8u: goto P_0c0503e8;
case 0x0c0503eau: goto P_0c0503ea;
case 0x0c0503ecu: goto P_0c0503ec;
case 0x0c0503eeu: goto P_0c0503ee;
case 0x0c0503f0u: goto P_0c0503f0;
case 0x0c0503f2u: goto P_0c0503f2;
case 0x0c0503f4u: goto P_0c0503f4;
case 0x0c0503f6u: goto P_0c0503f6;
case 0x0c0503f8u: goto P_0c0503f8;
case 0x0c0503fau: goto P_0c0503fa;
case 0x0c0503fcu: goto P_0c0503fc;
case 0x0c0503feu: goto P_0c0503fe;
case 0x0c050400u: goto P_0c050400;
case 0x0c050402u: goto P_0c050402;
case 0x0c050404u: goto P_0c050404;
case 0x0c050406u: goto P_0c050406;
case 0x0c050408u: goto P_0c050408;
case 0x0c05040au: goto P_0c05040a;
case 0x0c05040cu: goto P_0c05040c;
case 0x0c05040eu: goto P_0c05040e;
case 0x0c050410u: goto P_0c050410;
case 0x0c050412u: goto P_0c050412;
case 0x0c050414u: goto P_0c050414;
case 0x0c050416u: goto P_0c050416;
case 0x0c050418u: goto P_0c050418;
case 0x0c05041au: goto P_0c05041a;
case 0x0c05041cu: goto P_0c05041c;
case 0x0c05041eu: goto P_0c05041e;
case 0x0c050420u: goto P_0c050420;
case 0x0c050422u: goto P_0c050422;
case 0x0c050424u: goto P_0c050424;
case 0x0c050426u: goto P_0c050426;
case 0x0c050428u: goto P_0c050428;
case 0x0c05042au: goto P_0c05042a;
case 0x0c05042cu: goto P_0c05042c;
case 0x0c05042eu: goto P_0c05042e;
case 0x0c050430u: goto P_0c050430;
case 0x0c050432u: goto P_0c050432;
case 0x0c050434u: goto P_0c050434;
case 0x0c050436u: goto P_0c050436;
case 0x0c050438u: goto P_0c050438;
case 0x0c05043au: goto P_0c05043a;
case 0x0c05043cu: goto P_0c05043c;
case 0x0c05043eu: goto P_0c05043e;
case 0x0c050440u: goto P_0c050440;
case 0x0c050442u: goto P_0c050442;
case 0x0c050444u: goto P_0c050444;
case 0x0c050446u: goto P_0c050446;
case 0x0c050448u: goto P_0c050448;
case 0x0c05044au: goto P_0c05044a;
case 0x0c05044cu: goto P_0c05044c;
case 0x0c05044eu: goto P_0c05044e;
case 0x0c050450u: goto P_0c050450;
case 0x0c050452u: goto P_0c050452;
case 0x0c050492u: goto P_0c050492;
case 0x0c050494u: goto P_0c050494;
case 0x0c050496u: goto P_0c050496;
case 0x0c050498u: goto P_0c050498;
case 0x0c05049au: goto P_0c05049a;
case 0x0c05049cu: goto P_0c05049c;
case 0x0c05049eu: goto P_0c05049e;
case 0x0c0504a0u: goto P_0c0504a0;
case 0x0c0504a2u: goto P_0c0504a2;
case 0x0c0504a4u: goto P_0c0504a4;
case 0x0c0504a6u: goto P_0c0504a6;
case 0x0c0504a8u: goto P_0c0504a8;
case 0x0c0504aau: goto P_0c0504aa;
case 0x0c0504acu: goto P_0c0504ac;
case 0x0c0504aeu: goto P_0c0504ae;
case 0x0c0504b0u: goto P_0c0504b0;
case 0x0c0504b2u: goto P_0c0504b2;
case 0x0c0504b4u: goto P_0c0504b4;
case 0x0c0504b6u: goto P_0c0504b6;
case 0x0c0504b8u: goto P_0c0504b8;
case 0x0c0504bau: goto P_0c0504ba;
case 0x0c0504bcu: goto P_0c0504bc;
case 0x0c0504beu: goto P_0c0504be;
case 0x0c0504c0u: goto P_0c0504c0;
case 0x0c0504c2u: goto P_0c0504c2;
case 0x0c0504c4u: goto P_0c0504c4;
case 0x0c0504c6u: goto P_0c0504c6;
case 0x0c0504c8u: goto P_0c0504c8;
case 0x0c0504cau: goto P_0c0504ca;
case 0x0c0504ccu: goto P_0c0504cc;
case 0x0c0504ceu: goto P_0c0504ce;
case 0x0c0504d0u: goto P_0c0504d0;
case 0x0c0504d2u: goto P_0c0504d2;
case 0x0c0504d4u: goto P_0c0504d4;
case 0x0c0504d6u: goto P_0c0504d6;
case 0x0c0504d8u: goto P_0c0504d8;
case 0x0c0504dau: goto P_0c0504da;
case 0x0c0504dcu: goto P_0c0504dc;
case 0x0c0504deu: goto P_0c0504de;
case 0x0c0504e0u: goto P_0c0504e0;
case 0x0c0504e2u: goto P_0c0504e2;
case 0x0c0504e4u: goto P_0c0504e4;
case 0x0c0504e6u: goto P_0c0504e6;
case 0x0c0504e8u: goto P_0c0504e8;
case 0x0c0504eau: goto P_0c0504ea;
case 0x0c0504ecu: goto P_0c0504ec;
case 0x0c0504eeu: goto P_0c0504ee;
case 0x0c0504f0u: goto P_0c0504f0;
case 0x0c0504f2u: goto P_0c0504f2;
case 0x0c0504f4u: goto P_0c0504f4;
case 0x0c0504f6u: goto P_0c0504f6;
case 0x0c0504f8u: goto P_0c0504f8;
case 0x0c0504fau: goto P_0c0504fa;
case 0x0c0504fcu: goto P_0c0504fc;
case 0x0c0504feu: goto P_0c0504fe;
case 0x0c050500u: goto P_0c050500;
case 0x0c050502u: goto P_0c050502;
case 0x0c050504u: goto P_0c050504;
case 0x0c050506u: goto P_0c050506;
case 0x0c050508u: goto P_0c050508;
case 0x0c05050au: goto P_0c05050a;
case 0x0c05050cu: goto P_0c05050c;
case 0x0c05050eu: goto P_0c05050e;
case 0x0c050510u: goto P_0c050510;
case 0x0c050512u: goto P_0c050512;
case 0x0c050514u: goto P_0c050514;
case 0x0c050516u: goto P_0c050516;
case 0x0c050518u: goto P_0c050518;
case 0x0c062cb8u: goto P_0c062cb8;
case 0x0c062cbau: goto P_0c062cba;
case 0x0c062cbcu: goto P_0c062cbc;
case 0x0c062cbeu: goto P_0c062cbe;
case 0x0c062cc0u: goto P_0c062cc0;
case 0x0c062cc2u: goto P_0c062cc2;
case 0x0c062cc4u: goto P_0c062cc4;
case 0x0c062cc6u: goto P_0c062cc6;
case 0x0c062cc8u: goto P_0c062cc8;
case 0x0c062ccau: goto P_0c062cca;
case 0x0c062cccu: goto P_0c062ccc;
case 0x0c062cceu: goto P_0c062cce;
case 0x0c062cd0u: goto P_0c062cd0;
case 0x0c062cd2u: goto P_0c062cd2;
case 0x0c062cd4u: goto P_0c062cd4;
case 0x0c062cd6u: goto P_0c062cd6;
case 0x0c062cd8u: goto P_0c062cd8;
case 0x0c062cdau: goto P_0c062cda;
case 0x0c062cdcu: goto P_0c062cdc;
case 0x0c062cdeu: goto P_0c062cde;
case 0x0c062ce0u: goto P_0c062ce0;
case 0x0c062ce2u: goto P_0c062ce2;
case 0x0c062ce4u: goto P_0c062ce4;
case 0x0c062ce6u: goto P_0c062ce6;
case 0x0c062ce8u: goto P_0c062ce8;
case 0x0c062ceau: goto P_0c062cea;
case 0x0c062cecu: goto P_0c062cec;
case 0x0c062ceeu: goto P_0c062cee;
case 0x0c062cf0u: goto P_0c062cf0;
case 0x0c062cf2u: goto P_0c062cf2;
case 0x0c062cf4u: goto P_0c062cf4;
case 0x0c062cf6u: goto P_0c062cf6;
case 0x0c062cf8u: goto P_0c062cf8;
case 0x0c062cfau: goto P_0c062cfa;
case 0x0c062cfcu: goto P_0c062cfc;
case 0x0c062cfeu: goto P_0c062cfe;
case 0x0c062d00u: goto P_0c062d00;
case 0x0c062d02u: goto P_0c062d02;
case 0x0c062d04u: goto P_0c062d04;
case 0x0c062d06u: goto P_0c062d06;
case 0x0c062d08u: goto P_0c062d08;
case 0x0c062d0au: goto P_0c062d0a;
case 0x0c062d0cu: goto P_0c062d0c;
case 0x0c062d0eu: goto P_0c062d0e;
case 0x0c062d10u: goto P_0c062d10;
case 0x0c062d12u: goto P_0c062d12;
case 0x0c062d14u: goto P_0c062d14;
case 0x0c062d16u: goto P_0c062d16;
case 0x0c062d18u: goto P_0c062d18;
case 0x0c062d1au: goto P_0c062d1a;
case 0x0c062d1cu: goto P_0c062d1c;
case 0x0c062d1eu: goto P_0c062d1e;
case 0x0c062d20u: goto P_0c062d20;
case 0x0c062d22u: goto P_0c062d22;
case 0x0c062d24u: goto P_0c062d24;
case 0x0c062d26u: goto P_0c062d26;
case 0x0c062d28u: goto P_0c062d28;
case 0x0c062d2au: goto P_0c062d2a;
case 0x0c062d2cu: goto P_0c062d2c;
case 0x0c062d2eu: goto P_0c062d2e;
case 0x0c062d30u: goto P_0c062d30;
case 0x0c062d32u: goto P_0c062d32;
case 0x0c062d34u: goto P_0c062d34;
case 0x0c062d36u: goto P_0c062d36;
case 0x0c062d38u: goto P_0c062d38;
case 0x0c062d3au: goto P_0c062d3a;
case 0x0c062d3cu: goto P_0c062d3c;
case 0x0c062d3eu: goto P_0c062d3e;
case 0x0c062d40u: goto P_0c062d40;
case 0x0c062d42u: goto P_0c062d42;
case 0x0c062d44u: goto P_0c062d44;
case 0x0c062d46u: goto P_0c062d46;
case 0x0c062d48u: goto P_0c062d48;
case 0x0c062d4au: goto P_0c062d4a;
case 0x0c062d4cu: goto P_0c062d4c;
case 0x0c076a08u: goto P_0c076a08;
case 0x0c076a0au: goto P_0c076a0a;
case 0x0c076a0cu: goto P_0c076a0c;
case 0x0c076a0eu: goto P_0c076a0e;
case 0x0c076a10u: goto P_0c076a10;
case 0x0c076a12u: goto P_0c076a12;
case 0x0c076a14u: goto P_0c076a14;
case 0x0c076a16u: goto P_0c076a16;
case 0x0c076a18u: goto P_0c076a18;
case 0x0c076a1au: goto P_0c076a1a;
case 0x0c076a1cu: goto P_0c076a1c;
case 0x0c076a1eu: goto P_0c076a1e;
case 0x0c076a20u: goto P_0c076a20;
case 0x0c076a22u: goto P_0c076a22;
case 0x0c076a24u: goto P_0c076a24;
case 0x0c076a26u: goto P_0c076a26;
case 0x0c076a28u: goto P_0c076a28;
case 0x0c076a2au: goto P_0c076a2a;
case 0x0c076a2cu: goto P_0c076a2c;
case 0x0c076a2eu: goto P_0c076a2e;
case 0x0c076a30u: goto P_0c076a30;
case 0x0c076a32u: goto P_0c076a32;
case 0x0c076a34u: goto P_0c076a34;
case 0x0c076a36u: goto P_0c076a36;
case 0x0c076a38u: goto P_0c076a38;
case 0x0c076a3au: goto P_0c076a3a;
case 0x0c076a3cu: goto P_0c076a3c;
case 0x0c076a3eu: goto P_0c076a3e;
case 0x0c076a40u: goto P_0c076a40;
case 0x0c076a42u: goto P_0c076a42;
case 0x0c076a44u: goto P_0c076a44;
case 0x0c076a46u: goto P_0c076a46;
case 0x0c076a48u: goto P_0c076a48;
case 0x0c076a4au: goto P_0c076a4a;
case 0x0c076a4cu: goto P_0c076a4c;
case 0x0c076a4eu: goto P_0c076a4e;
case 0x0c076a50u: goto P_0c076a50;
case 0x0c076a52u: goto P_0c076a52;
case 0x0c076a54u: goto P_0c076a54;
case 0x0c076a56u: goto P_0c076a56;
case 0x0c076a58u: goto P_0c076a58;
case 0x0c076a5au: goto P_0c076a5a;
case 0x0c076a5cu: goto P_0c076a5c;
case 0x0c076a5eu: goto P_0c076a5e;
case 0x0c076a60u: goto P_0c076a60;
case 0x0c076a62u: goto P_0c076a62;
case 0x0c076a64u: goto P_0c076a64;
case 0x0c076a66u: goto P_0c076a66;
case 0x0c076a68u: goto P_0c076a68;
case 0x0c076a6au: goto P_0c076a6a;
case 0x0c076a6cu: goto P_0c076a6c;
case 0x0c076a6eu: goto P_0c076a6e;
case 0x0c076a70u: goto P_0c076a70;
case 0x0c076a72u: goto P_0c076a72;
case 0x0c076a74u: goto P_0c076a74;
case 0x0c076a76u: goto P_0c076a76;
case 0x0c076a78u: goto P_0c076a78;
case 0x0c076a7au: goto P_0c076a7a;
case 0x0c076a7cu: goto P_0c076a7c;
case 0x0c076a7eu: goto P_0c076a7e;
case 0x0c076a80u: goto P_0c076a80;
case 0x0c076a82u: goto P_0c076a82;
case 0x0c076a84u: goto P_0c076a84;
case 0x0c076a86u: goto P_0c076a86;
case 0x0c076a88u: goto P_0c076a88;
case 0x0c076a8au: goto P_0c076a8a;
case 0x0c076a8cu: goto P_0c076a8c;
case 0x0c076a8eu: goto P_0c076a8e;
case 0x0c076a90u: goto P_0c076a90;
case 0x0c076a92u: goto P_0c076a92;
case 0x0c076a94u: goto P_0c076a94;
case 0x0c076a96u: goto P_0c076a96;
case 0x0c076a98u: goto P_0c076a98;
case 0x0c076a9au: goto P_0c076a9a;
case 0x0c076a9cu: goto P_0c076a9c;
case 0x0c076a9eu: goto P_0c076a9e;
case 0x0c076aa0u: goto P_0c076aa0;
case 0x0c076aa2u: goto P_0c076aa2;
case 0x0c076aa4u: goto P_0c076aa4;
case 0x0c076aa6u: goto P_0c076aa6;
case 0x0c076aa8u: goto P_0c076aa8;
case 0x0c076aaau: goto P_0c076aaa;
case 0x0c076aacu: goto P_0c076aac;
case 0x0c076aaeu: goto P_0c076aae;
case 0x0c076ab0u: goto P_0c076ab0;
case 0x0c076ab2u: goto P_0c076ab2;
case 0x0c076ab4u: goto P_0c076ab4;
case 0x0c076ab6u: goto P_0c076ab6;
case 0x0c076ab8u: goto P_0c076ab8;
case 0x0c076abau: goto P_0c076aba;
case 0x0c076abcu: goto P_0c076abc;
case 0x0c076abeu: goto P_0c076abe;
case 0x0c076ac0u: goto P_0c076ac0;
case 0x0c076ac2u: goto P_0c076ac2;
case 0x0c076ac4u: goto P_0c076ac4;
case 0x0c076ac6u: goto P_0c076ac6;
case 0x0c076ac8u: goto P_0c076ac8;
case 0x0c076acau: goto P_0c076aca;
case 0x0c076accu: goto P_0c076acc;
case 0x0c076aceu: goto P_0c076ace;
case 0x0c076ad0u: goto P_0c076ad0;
case 0x0c076ad2u: goto P_0c076ad2;
case 0x0c076ad4u: goto P_0c076ad4;
case 0x0c076ad6u: goto P_0c076ad6;
case 0x0c076ad8u: goto P_0c076ad8;
case 0x0c076adau: goto P_0c076ada;
case 0x0c076adcu: goto P_0c076adc;
case 0x0c076adeu: goto P_0c076ade;
case 0x0c076ae0u: goto P_0c076ae0;
case 0x0c076ae2u: goto P_0c076ae2;
case 0x0c076ae4u: goto P_0c076ae4;
case 0x0c076ae6u: goto P_0c076ae6;
case 0x0c076ae8u: goto P_0c076ae8;
case 0x0c076aeau: goto P_0c076aea;
case 0x0c076aecu: goto P_0c076aec;
case 0x0c076aeeu: goto P_0c076aee;
case 0x0c076af0u: goto P_0c076af0;
case 0x0c076af2u: goto P_0c076af2;
case 0x0c076af4u: goto P_0c076af4;
case 0x0c076af6u: goto P_0c076af6;
case 0x0c076af8u: goto P_0c076af8;
case 0x0c076afau: goto P_0c076afa;
case 0x0c076afcu: goto P_0c076afc;
case 0x0c076afeu: goto P_0c076afe;
case 0x0c076b00u: goto P_0c076b00;
case 0x0c076b02u: goto P_0c076b02;
case 0x0c076b04u: goto P_0c076b04;
case 0x0c076b06u: goto P_0c076b06;
case 0x0c076b08u: goto P_0c076b08;
case 0x0c076b0au: goto P_0c076b0a;
case 0x0c076b0cu: goto P_0c076b0c;
case 0x0c076b0eu: goto P_0c076b0e;
case 0x0c076b10u: goto P_0c076b10;
case 0x0c076b12u: goto P_0c076b12;
case 0x0c076b14u: goto P_0c076b14;
case 0x0c076b16u: goto P_0c076b16;
case 0x0c076b18u: goto P_0c076b18;
case 0x0c07f1bau: goto P_0c07f1ba;
case 0x0c07f1bcu: goto P_0c07f1bc;
case 0x0c07f1beu: goto P_0c07f1be;
case 0x0c07f1c0u: goto P_0c07f1c0;
case 0x0c07f1c2u: goto P_0c07f1c2;
case 0x0c07f1c4u: goto P_0c07f1c4;
case 0x0c07f1c6u: goto P_0c07f1c6;
case 0x0c07f1c8u: goto P_0c07f1c8;
case 0x0c07f1cau: goto P_0c07f1ca;
case 0x0c07f1ccu: goto P_0c07f1cc;
case 0x0c07f1ceu: goto P_0c07f1ce;
case 0x0c07f1d0u: goto P_0c07f1d0;
case 0x0c07f1d2u: goto P_0c07f1d2;
case 0x0c07f1d4u: goto P_0c07f1d4;
case 0x0c07f1d6u: goto P_0c07f1d6;
case 0x0c07f1d8u: goto P_0c07f1d8;
case 0x0c07f1dau: goto P_0c07f1da;
case 0x0c07f1dcu: goto P_0c07f1dc;
case 0x0c07f1deu: goto P_0c07f1de;
case 0x0c07f1e0u: goto P_0c07f1e0;
case 0x0c07f1e2u: goto P_0c07f1e2;
case 0x0c07f1e4u: goto P_0c07f1e4;
case 0x0c07f1e6u: goto P_0c07f1e6;
case 0x0c07f1e8u: goto P_0c07f1e8;
case 0x0c07f1eau: goto P_0c07f1ea;
case 0x0c07f1ecu: goto P_0c07f1ec;
case 0x0c07f1eeu: goto P_0c07f1ee;
case 0x0c07f1f0u: goto P_0c07f1f0;
case 0x0c07f1f2u: goto P_0c07f1f2;
case 0x0c07f1f4u: goto P_0c07f1f4;
case 0x0c07f1f6u: goto P_0c07f1f6;
case 0x0c07f1f8u: goto P_0c07f1f8;
case 0x0c07f238u: goto P_0c07f238;
case 0x0c07f23au: goto P_0c07f23a;
case 0x0c07f23cu: goto P_0c07f23c;
case 0x0c07f23eu: goto P_0c07f23e;
case 0x0c07f240u: goto P_0c07f240;
case 0x0c07f242u: goto P_0c07f242;
case 0x0c07f244u: goto P_0c07f244;
case 0x0c07f246u: goto P_0c07f246;
case 0x0c07f248u: goto P_0c07f248;
case 0x0c07f24au: goto P_0c07f24a;
case 0x0c07f24cu: goto P_0c07f24c;
case 0x0c07f24eu: goto P_0c07f24e;
case 0x0c07f250u: goto P_0c07f250;
case 0x0c07f252u: goto P_0c07f252;
case 0x0c07f254u: goto P_0c07f254;
case 0x0c07f256u: goto P_0c07f256;
case 0x0c07f258u: goto P_0c07f258;
case 0x0c07f25au: goto P_0c07f25a;
case 0x0c07f25cu: goto P_0c07f25c;
case 0x0c07f25eu: goto P_0c07f25e;
case 0x0c07f260u: goto P_0c07f260;
case 0x0c07f262u: goto P_0c07f262;
case 0x0c07f264u: goto P_0c07f264;
case 0x0c07f266u: goto P_0c07f266;
case 0x0c07f268u: goto P_0c07f268;
case 0x0c07f26au: goto P_0c07f26a;
case 0x0c07f26cu: goto P_0c07f26c;
case 0x0c07f26eu: goto P_0c07f26e;
case 0x0c07f270u: goto P_0c07f270;
case 0x0c07f272u: goto P_0c07f272;
case 0x0c07f274u: goto P_0c07f274;
case 0x0c07f276u: goto P_0c07f276;
case 0x0c07f278u: goto P_0c07f278;
case 0x0c07f27au: goto P_0c07f27a;
case 0x0c07f27cu: goto P_0c07f27c;
case 0x0c07f27eu: goto P_0c07f27e;
case 0x0c07f280u: goto P_0c07f280;
case 0x0c07f282u: goto P_0c07f282;
case 0x0c07f284u: goto P_0c07f284;
case 0x0c07f286u: goto P_0c07f286;
case 0x0c07f288u: goto P_0c07f288;
case 0x0c07f28au: goto P_0c07f28a;
case 0x0c07f28cu: goto P_0c07f28c;
case 0x0c07f28eu: goto P_0c07f28e;
case 0x0c07f290u: goto P_0c07f290;
case 0x0c07f292u: goto P_0c07f292;
case 0x0c07f294u: goto P_0c07f294;
case 0x0c07f296u: goto P_0c07f296;
case 0x0c07f298u: goto P_0c07f298;
case 0x0c07f29au: goto P_0c07f29a;
case 0x0c07f29cu: goto P_0c07f29c;
case 0x0c07f29eu: goto P_0c07f29e;
case 0x0c07f2a0u: goto P_0c07f2a0;
case 0x0c07f2a2u: goto P_0c07f2a2;
case 0x0c07f2a4u: goto P_0c07f2a4;
case 0x0c07f2a6u: goto P_0c07f2a6;
case 0x0c07f2a8u: goto P_0c07f2a8;
case 0x0c07f2aau: goto P_0c07f2aa;
case 0x0c07f2acu: goto P_0c07f2ac;
case 0x0c07f2aeu: goto P_0c07f2ae;
case 0x0c07f2b0u: goto P_0c07f2b0;
case 0x0c07f2b2u: goto P_0c07f2b2;
case 0x0c07f2b4u: goto P_0c07f2b4;
case 0x0c07f2b6u: goto P_0c07f2b6;
case 0x0c07f2b8u: goto P_0c07f2b8;
case 0x0c07f2bau: goto P_0c07f2ba;
case 0x0c07f2bcu: goto P_0c07f2bc;
case 0x0c07f2beu: goto P_0c07f2be;
case 0x0c07f2c0u: goto P_0c07f2c0;
case 0x0c07f2c2u: goto P_0c07f2c2;
case 0x0c07f2c4u: goto P_0c07f2c4;
case 0x0c07f2c6u: goto P_0c07f2c6;
case 0x0c07f2c8u: goto P_0c07f2c8;
case 0x0c07f2cau: goto P_0c07f2ca;
case 0x0c07f2ccu: goto P_0c07f2cc;
case 0x0c07f2ceu: goto P_0c07f2ce;
case 0x0c07f2d0u: goto P_0c07f2d0;
case 0x0c07f2d2u: goto P_0c07f2d2;
case 0x0c07f2d4u: goto P_0c07f2d4;
case 0x0c07f2d6u: goto P_0c07f2d6;
case 0x0c07f2d8u: goto P_0c07f2d8;
case 0x0c07f2dau: goto P_0c07f2da;
case 0x0c07f2dcu: goto P_0c07f2dc;
case 0x0c07f2deu: goto P_0c07f2de;
case 0x0c07f2e0u: goto P_0c07f2e0;
case 0x0c07f2e2u: goto P_0c07f2e2;
case 0x0c07f2e4u: goto P_0c07f2e4;
case 0x0c07f2e6u: goto P_0c07f2e6;
case 0x0c07f2e8u: goto P_0c07f2e8;
case 0x0c07f2eau: goto P_0c07f2ea;
case 0x0c07f2ecu: goto P_0c07f2ec;
case 0x0c07f2eeu: goto P_0c07f2ee;
case 0x0c07f2f0u: goto P_0c07f2f0;
case 0x0c07f2f2u: goto P_0c07f2f2;
case 0x0c07f2f4u: goto P_0c07f2f4;
case 0x0c07f2f6u: goto P_0c07f2f6;
case 0x0c07f2f8u: goto P_0c07f2f8;
case 0x0c07f2fau: goto P_0c07f2fa;
case 0x0c07f2fcu: goto P_0c07f2fc;
case 0x0c07f2feu: goto P_0c07f2fe;
case 0x0c07f300u: goto P_0c07f300;
case 0x0c07f302u: goto P_0c07f302;
case 0x0c07f304u: goto P_0c07f304;
case 0x0c07f306u: goto P_0c07f306;
case 0x0c07f308u: goto P_0c07f308;
case 0x0c081fbeu: goto P_0c081fbe;
case 0x0c081fc0u: goto P_0c081fc0;
case 0x0c081fc2u: goto P_0c081fc2;
case 0x0c081fc4u: goto P_0c081fc4;
case 0x0c081fc6u: goto P_0c081fc6;
case 0x0c081fc8u: goto P_0c081fc8;
case 0x0c081fcau: goto P_0c081fca;
case 0x0c081fccu: goto P_0c081fcc;
case 0x0c081fceu: goto P_0c081fce;
case 0x0c081fd0u: goto P_0c081fd0;
case 0x0c081fd2u: goto P_0c081fd2;
case 0x0c081fd4u: goto P_0c081fd4;
case 0x0c081fd6u: goto P_0c081fd6;
case 0x0c081fd8u: goto P_0c081fd8;
case 0x0c081fdau: goto P_0c081fda;
case 0x0c081fdcu: goto P_0c081fdc;
case 0x0c081fdeu: goto P_0c081fde;
case 0x0c081fe0u: goto P_0c081fe0;
case 0x0c081fe2u: goto P_0c081fe2;
case 0x0c081fe4u: goto P_0c081fe4;
case 0x0c081fe6u: goto P_0c081fe6;
case 0x0c081fe8u: goto P_0c081fe8;
case 0x0c081feau: goto P_0c081fea;
case 0x0c081fecu: goto P_0c081fec;
case 0x0c081feeu: goto P_0c081fee;
case 0x0c081ff0u: goto P_0c081ff0;
case 0x0c081ff2u: goto P_0c081ff2;
case 0x0c081ff4u: goto P_0c081ff4;
case 0x0c081ff6u: goto P_0c081ff6;
case 0x0c081ff8u: goto P_0c081ff8;
case 0x0c081ffau: goto P_0c081ffa;
case 0x0c081ffcu: goto P_0c081ffc;
case 0x0c081ffeu: goto P_0c081ffe;
case 0x0c082000u: goto P_0c082000;
case 0x0c082002u: goto P_0c082002;
case 0x0c082004u: goto P_0c082004;
case 0x0c082006u: goto P_0c082006;
case 0x0c082008u: goto P_0c082008;
case 0x0c08200au: goto P_0c08200a;
case 0x0c08200cu: goto P_0c08200c;
case 0x0c08200eu: goto P_0c08200e;
case 0x0c082010u: goto P_0c082010;
case 0x0c082012u: goto P_0c082012;
case 0x0c082014u: goto P_0c082014;
case 0x0c082016u: goto P_0c082016;
case 0x0c082018u: goto P_0c082018;
case 0x0c08201au: goto P_0c08201a;
case 0x0c08201cu: goto P_0c08201c;
case 0x0c08201eu: goto P_0c08201e;
case 0x0c082020u: goto P_0c082020;
case 0x0c082022u: goto P_0c082022;
case 0x0c082024u: goto P_0c082024;
case 0x0c082026u: goto P_0c082026;
case 0x0c082028u: goto P_0c082028;
case 0x0c08202au: goto P_0c08202a;
case 0x0c08202cu: goto P_0c08202c;
case 0x0c08202eu: goto P_0c08202e;
case 0x0c082030u: goto P_0c082030;
case 0x0c082032u: goto P_0c082032;
case 0x0c082034u: goto P_0c082034;
case 0x0c082036u: goto P_0c082036;
case 0x0c082038u: goto P_0c082038;
case 0x0c08203au: goto P_0c08203a;
case 0x0c08203cu: goto P_0c08203c;
case 0x0c08203eu: goto P_0c08203e;
case 0x0c082040u: goto P_0c082040;
case 0x0c082042u: goto P_0c082042;
case 0x0c082044u: goto P_0c082044;
case 0x0c082046u: goto P_0c082046;
case 0x0c082048u: goto P_0c082048;
case 0x0c08204au: goto P_0c08204a;
case 0x0c08204cu: goto P_0c08204c;
case 0x0c08204eu: goto P_0c08204e;
case 0x0c082050u: goto P_0c082050;
case 0x0c082052u: goto P_0c082052;
case 0x0c082054u: goto P_0c082054;
case 0x0c097ff4u: goto P_0c097ff4;
case 0x0c097ff6u: goto P_0c097ff6;
case 0x0c097ff8u: goto P_0c097ff8;
case 0x0c097ffau: goto P_0c097ffa;
case 0x0c097ffcu: goto P_0c097ffc;
case 0x0c097ffeu: goto P_0c097ffe;
case 0x0c098000u: goto P_0c098000;
case 0x0c098002u: goto P_0c098002;
case 0x0c098004u: goto P_0c098004;
case 0x0c098006u: goto P_0c098006;
case 0x0c098008u: goto P_0c098008;
case 0x0c09800au: goto P_0c09800a;
case 0x0c09800cu: goto P_0c09800c;
case 0x0c09800eu: goto P_0c09800e;
case 0x0c098010u: goto P_0c098010;
case 0x0c098012u: goto P_0c098012;
case 0x0c098014u: goto P_0c098014;
case 0x0c098016u: goto P_0c098016;
case 0x0c098018u: goto P_0c098018;
case 0x0c09801au: goto P_0c09801a;
case 0x0c09801cu: goto P_0c09801c;
case 0x0c09801eu: goto P_0c09801e;
case 0x0c098020u: goto P_0c098020;
case 0x0c098022u: goto P_0c098022;
case 0x0c098024u: goto P_0c098024;
case 0x0c098026u: goto P_0c098026;
case 0x0c098028u: goto P_0c098028;
case 0x0c09802au: goto P_0c09802a;
case 0x0c09802cu: goto P_0c09802c;
case 0x0c09802eu: goto P_0c09802e;
case 0x0c098030u: goto P_0c098030;
case 0x0c098032u: goto P_0c098032;
case 0x0c098034u: goto P_0c098034;
case 0x0c098036u: goto P_0c098036;
case 0x0c098038u: goto P_0c098038;
case 0x0c09803au: goto P_0c09803a;
case 0x0c09803cu: goto P_0c09803c;
case 0x0c09803eu: goto P_0c09803e;
case 0x0c098588u: goto P_0c098588;
case 0x0c09858au: goto P_0c09858a;
case 0x0c09858cu: goto P_0c09858c;
case 0x0c09858eu: goto P_0c09858e;
case 0x0c098590u: goto P_0c098590;
case 0x0c098592u: goto P_0c098592;
case 0x0c098594u: goto P_0c098594;
case 0x0c098596u: goto P_0c098596;
case 0x0c098598u: goto P_0c098598;
case 0x0c09859au: goto P_0c09859a;
case 0x0c09859cu: goto P_0c09859c;
case 0x0c09859eu: goto P_0c09859e;
case 0x0c0985a0u: goto P_0c0985a0;
case 0x0c0985a2u: goto P_0c0985a2;
case 0x0c0985a4u: goto P_0c0985a4;
case 0x0c0985a6u: goto P_0c0985a6;
case 0x0c0985a8u: goto P_0c0985a8;
case 0x0c0985aau: goto P_0c0985aa;
case 0x0c0985acu: goto P_0c0985ac;
case 0x0c0985aeu: goto P_0c0985ae;
case 0x0c0985b0u: goto P_0c0985b0;
case 0x0c0985b2u: goto P_0c0985b2;
case 0x0c0985b4u: goto P_0c0985b4;
case 0x0c0985b6u: goto P_0c0985b6;
case 0x0c0985b8u: goto P_0c0985b8;
case 0x0c0985bau: goto P_0c0985ba;
case 0x0c0985bcu: goto P_0c0985bc;
case 0x0c0985beu: goto P_0c0985be;
case 0x0c0985c0u: goto P_0c0985c0;
case 0x0c0985c2u: goto P_0c0985c2;
case 0x0c0985c4u: goto P_0c0985c4;
case 0x0c0985c6u: goto P_0c0985c6;
case 0x0c0985c8u: goto P_0c0985c8;
case 0x0c0985cau: goto P_0c0985ca;
case 0x0c0985ccu: goto P_0c0985cc;
case 0x0c0985ceu: goto P_0c0985ce;
case 0x0c0985d0u: goto P_0c0985d0;
case 0x0c0985d2u: goto P_0c0985d2;
case 0x0c0985d4u: goto P_0c0985d4;
case 0x0c0985d6u: goto P_0c0985d6;
case 0x0c0985d8u: goto P_0c0985d8;
case 0x0c0985dau: goto P_0c0985da;
case 0x0c0985dcu: goto P_0c0985dc;
case 0x0c0985deu: goto P_0c0985de;
case 0x0c0985e0u: goto P_0c0985e0;
case 0x0c0985e2u: goto P_0c0985e2;
case 0x0c0985e4u: goto P_0c0985e4;
case 0x0c0985e6u: goto P_0c0985e6;
case 0x0c0985e8u: goto P_0c0985e8;
case 0x0c0985eau: goto P_0c0985ea;
case 0x0c0985ecu: goto P_0c0985ec;
case 0x0c0985eeu: goto P_0c0985ee;
case 0x0c0985f0u: goto P_0c0985f0;
case 0x0c0985f2u: goto P_0c0985f2;
case 0x0c0985f4u: goto P_0c0985f4;
case 0x0c0985f6u: goto P_0c0985f6;
case 0x0c0985f8u: goto P_0c0985f8;
case 0x0c0985fau: goto P_0c0985fa;
case 0x0c0985fcu: goto P_0c0985fc;
case 0x0c0985feu: goto P_0c0985fe;
case 0x0c098600u: goto P_0c098600;
case 0x0c098602u: goto P_0c098602;
case 0x0c098604u: goto P_0c098604;
case 0x0c098606u: goto P_0c098606;
case 0x0c098608u: goto P_0c098608;
case 0x0c09860au: goto P_0c09860a;
case 0x0c09860cu: goto P_0c09860c;
case 0x0c09860eu: goto P_0c09860e;
case 0x0c098610u: goto P_0c098610;
case 0x0c098612u: goto P_0c098612;
case 0x0c098614u: goto P_0c098614;
case 0x0c098616u: goto P_0c098616;
case 0x0c098618u: goto P_0c098618;
case 0x0c09861au: goto P_0c09861a;
case 0x0c09861cu: goto P_0c09861c;
case 0x0c09d09eu: goto P_0c09d09e;
case 0x0c09d0a0u: goto P_0c09d0a0;
case 0x0c09d0a2u: goto P_0c09d0a2;
case 0x0c09d0a4u: goto P_0c09d0a4;
case 0x0c09d0a6u: goto P_0c09d0a6;
case 0x0c09d0a8u: goto P_0c09d0a8;
case 0x0c09d0aau: goto P_0c09d0aa;
case 0x0c09d0acu: goto P_0c09d0ac;
case 0x0c09d0aeu: goto P_0c09d0ae;
case 0x0c09d0b0u: goto P_0c09d0b0;
case 0x0c09d0b2u: goto P_0c09d0b2;
case 0x0c09d0b4u: goto P_0c09d0b4;
case 0x0c09d0b6u: goto P_0c09d0b6;
case 0x0c09d0b8u: goto P_0c09d0b8;
case 0x0c09d0bau: goto P_0c09d0ba;
case 0x0c09d0bcu: goto P_0c09d0bc;
case 0x0c09d0beu: goto P_0c09d0be;
case 0x0c09d0c0u: goto P_0c09d0c0;
case 0x0c09d0c2u: goto P_0c09d0c2;
case 0x0c09d0c4u: goto P_0c09d0c4;
case 0x0c09d0c6u: goto P_0c09d0c6;
case 0x0c09d0c8u: goto P_0c09d0c8;
case 0x0c09d0cau: goto P_0c09d0ca;
case 0x0c09d0ccu: goto P_0c09d0cc;
case 0x0c09d0ceu: goto P_0c09d0ce;
case 0x0c09d0d0u: goto P_0c09d0d0;
case 0x0c09d0d2u: goto P_0c09d0d2;
case 0x0c09d0d4u: goto P_0c09d0d4;
case 0x0c09d0d6u: goto P_0c09d0d6;
case 0x0c09d0d8u: goto P_0c09d0d8;
case 0x0c09d0dau: goto P_0c09d0da;
case 0x0c09d0dcu: goto P_0c09d0dc;
case 0x0c09d0deu: goto P_0c09d0de;
case 0x0c09d0e0u: goto P_0c09d0e0;
case 0x0c09d0e2u: goto P_0c09d0e2;
case 0x0c09d0e4u: goto P_0c09d0e4;
case 0x0c09d0e6u: goto P_0c09d0e6;
case 0x0c09d0e8u: goto P_0c09d0e8;
case 0x0c09d0eau: goto P_0c09d0ea;
case 0x0c09d0ecu: goto P_0c09d0ec;
case 0x0c09d0eeu: goto P_0c09d0ee;
case 0x0c09d0f0u: goto P_0c09d0f0;
case 0x0c09d0f2u: goto P_0c09d0f2;
case 0x0c09d0f4u: goto P_0c09d0f4;
case 0x0c09d0f6u: goto P_0c09d0f6;
case 0x0c09d0f8u: goto P_0c09d0f8;
case 0x0c09d0fau: goto P_0c09d0fa;
case 0x0c09d0fcu: goto P_0c09d0fc;
case 0x0c09d0feu: goto P_0c09d0fe;
case 0x0c09d100u: goto P_0c09d100;
case 0x0c09d102u: goto P_0c09d102;
case 0x0c09d104u: goto P_0c09d104;
case 0x0c09d106u: goto P_0c09d106;
case 0x0c09d108u: goto P_0c09d108;
case 0x0c09d10au: goto P_0c09d10a;
case 0x0c09d10cu: goto P_0c09d10c;
case 0x0c09d10eu: goto P_0c09d10e;
case 0x0c09d110u: goto P_0c09d110;
case 0x0c09d112u: goto P_0c09d112;
case 0x0c09d114u: goto P_0c09d114;
case 0x0c09d116u: goto P_0c09d116;
case 0x0c09d118u: goto P_0c09d118;
case 0x0c09d11au: goto P_0c09d11a;
case 0x0c09d11cu: goto P_0c09d11c;
case 0x0c09d11eu: goto P_0c09d11e;
case 0x0c09d120u: goto P_0c09d120;
case 0x0c09d122u: goto P_0c09d122;
case 0x0c09d124u: goto P_0c09d124;
case 0x0c09d126u: goto P_0c09d126;
case 0x0c09d128u: goto P_0c09d128;
case 0x0c09d12au: goto P_0c09d12a;
case 0x0c09d12cu: goto P_0c09d12c;
case 0x0c09d12eu: goto P_0c09d12e;
case 0x0c09d130u: goto P_0c09d130;
case 0x0c09d132u: goto P_0c09d132;
case 0x0c09d134u: goto P_0c09d134;
case 0x0c09d136u: goto P_0c09d136;
case 0x0c0a0280u: goto P_0c0a0280;
case 0x0c0a0282u: goto P_0c0a0282;
case 0x0c0a0284u: goto P_0c0a0284;
case 0x0c0a0286u: goto P_0c0a0286;
case 0x0c0a0288u: goto P_0c0a0288;
case 0x0c0a03deu: goto P_0c0a03de;
case 0x0c0a03e0u: goto P_0c0a03e0;
case 0x0c0a03e2u: goto P_0c0a03e2;
case 0x0c0a03e4u: goto P_0c0a03e4;
case 0x0c0a03e6u: goto P_0c0a03e6;
case 0x0c0a03e8u: goto P_0c0a03e8;
case 0x0c0a03eau: goto P_0c0a03ea;
case 0x0c0a03ecu: goto P_0c0a03ec;
case 0x0c0a03eeu: goto P_0c0a03ee;
case 0x0c0aa7a2u: goto P_0c0aa7a2;
case 0x0c0aa7a4u: goto P_0c0aa7a4;
case 0x0c0aa7a6u: goto P_0c0aa7a6;
case 0x0c0aa7a8u: goto P_0c0aa7a8;
case 0x0c0aa7aau: goto P_0c0aa7aa;
case 0x0c0aa7acu: goto P_0c0aa7ac;
case 0x0c0aa7aeu: goto P_0c0aa7ae;
case 0x0c0aa7b0u: goto P_0c0aa7b0;
case 0x0c0aa7b2u: goto P_0c0aa7b2;
case 0x0c0aa7b4u: goto P_0c0aa7b4;
case 0x0c0aa7b6u: goto P_0c0aa7b6;
case 0x0c0aa7b8u: goto P_0c0aa7b8;
case 0x0c0aa7bau: goto P_0c0aa7ba;
case 0x0c0aa7bcu: goto P_0c0aa7bc;
case 0x0c0aa7beu: goto P_0c0aa7be;
case 0x0c0aa7c0u: goto P_0c0aa7c0;
case 0x0c0aa7c2u: goto P_0c0aa7c2;
case 0x0c0aa7c4u: goto P_0c0aa7c4;
case 0x0c0aa7c6u: goto P_0c0aa7c6;
case 0x0c0aa7c8u: goto P_0c0aa7c8;
case 0x0c0aa7cau: goto P_0c0aa7ca;
case 0x0c0aa7ccu: goto P_0c0aa7cc;
case 0x0c0aa7ceu: goto P_0c0aa7ce;
case 0x0c0aa7d0u: goto P_0c0aa7d0;
case 0x0c0aa7d2u: goto P_0c0aa7d2;
case 0x0c0aa7d4u: goto P_0c0aa7d4;
case 0x0c0aa7d6u: goto P_0c0aa7d6;
case 0x0c0aa7d8u: goto P_0c0aa7d8;
case 0x0c0aa7dau: goto P_0c0aa7da;
case 0x0c0aa7dcu: goto P_0c0aa7dc;
case 0x0c0aa7deu: goto P_0c0aa7de;
case 0x0c0aa7e0u: goto P_0c0aa7e0;
case 0x0c0aa7e2u: goto P_0c0aa7e2;
case 0x0c0aa7e4u: goto P_0c0aa7e4;
case 0x0c0aa7e6u: goto P_0c0aa7e6;
case 0x0c0aa7e8u: goto P_0c0aa7e8;
case 0x0c0aa7eau: goto P_0c0aa7ea;
case 0x0c0aaaf6u: goto P_0c0aaaf6;
case 0x0c0aaaf8u: goto P_0c0aaaf8;
case 0x0c0aaafau: goto P_0c0aaafa;
case 0x0c0aaafcu: goto P_0c0aaafc;
case 0x0c0aaafeu: goto P_0c0aaafe;
case 0x0c0aab00u: goto P_0c0aab00;
case 0x0c0aab02u: goto P_0c0aab02;
case 0x0c0aab04u: goto P_0c0aab04;
case 0x0c0aab06u: goto P_0c0aab06;
case 0x0c0aab08u: goto P_0c0aab08;
case 0x0c0aab0au: goto P_0c0aab0a;
case 0x0c0aab0cu: goto P_0c0aab0c;
case 0x0c0aab0eu: goto P_0c0aab0e;
case 0x0c0aab10u: goto P_0c0aab10;
case 0x0c0aab12u: goto P_0c0aab12;
case 0x0c0aab14u: goto P_0c0aab14;
case 0x0c0aab16u: goto P_0c0aab16;
case 0x0c0aab18u: goto P_0c0aab18;
case 0x0c0aab1au: goto P_0c0aab1a;
case 0x0c0aab1cu: goto P_0c0aab1c;
case 0x0c0aab1eu: goto P_0c0aab1e;
case 0x0c0aab4cu: goto P_0c0aab4c;
case 0x0c0aab4eu: goto P_0c0aab4e;
case 0x0c0aab50u: goto P_0c0aab50;
case 0x0c0aab52u: goto P_0c0aab52;
case 0x0c0aab54u: goto P_0c0aab54;
case 0x0c0aab56u: goto P_0c0aab56;
case 0x0c0aab58u: goto P_0c0aab58;
case 0x0c0aab5au: goto P_0c0aab5a;
case 0x0c0aab5cu: goto P_0c0aab5c;
case 0x0c0aab5eu: goto P_0c0aab5e;
case 0x0c0aab60u: goto P_0c0aab60;
case 0x0c0aab62u: goto P_0c0aab62;
case 0x0c0aab64u: goto P_0c0aab64;
case 0x0c0aab66u: goto P_0c0aab66;
case 0x0c0aab68u: goto P_0c0aab68;
case 0x0c0aab6au: goto P_0c0aab6a;
case 0x0c0aab6cu: goto P_0c0aab6c;
case 0x0c0aab6eu: goto P_0c0aab6e;
case 0x0c0aab70u: goto P_0c0aab70;
case 0x0c0aab72u: goto P_0c0aab72;
case 0x0c0aab74u: goto P_0c0aab74;
case 0x0c0aab76u: goto P_0c0aab76;
case 0x0c0aab78u: goto P_0c0aab78;
case 0x0c0aab7au: goto P_0c0aab7a;
case 0x0c0aab7cu: goto P_0c0aab7c;
case 0x0c0aab7eu: goto P_0c0aab7e;
case 0x0c0aab80u: goto P_0c0aab80;
case 0x0c0aab82u: goto P_0c0aab82;
case 0x0c0aab84u: goto P_0c0aab84;
case 0x0c0aab86u: goto P_0c0aab86;
case 0x0c0aab88u: goto P_0c0aab88;
case 0x0c0aab8au: goto P_0c0aab8a;
case 0x0c0aab8cu: goto P_0c0aab8c;
case 0x0c0aab8eu: goto P_0c0aab8e;
case 0x0c0aab90u: goto P_0c0aab90;
case 0x0c0aab92u: goto P_0c0aab92;
case 0x0c0aab94u: goto P_0c0aab94;
case 0x0c0aab96u: goto P_0c0aab96;
case 0x0c0aab98u: goto P_0c0aab98;
case 0x0c0aab9au: goto P_0c0aab9a;
case 0x0c0aab9cu: goto P_0c0aab9c;
case 0x0c0aab9eu: goto P_0c0aab9e;
case 0x0c0aaba0u: goto P_0c0aaba0;
case 0x0c0aaba2u: goto P_0c0aaba2;
case 0x0c0aaba4u: goto P_0c0aaba4;
case 0x0c0aaba6u: goto P_0c0aaba6;
case 0x0c0aaba8u: goto P_0c0aaba8;
case 0x0c0aabaau: goto P_0c0aabaa;
case 0x0c0aabacu: goto P_0c0aabac;
case 0x0c0aabaeu: goto P_0c0aabae;
case 0x0c0aabb0u: goto P_0c0aabb0;
case 0x0c0aabb2u: goto P_0c0aabb2;
case 0x0c0aabb4u: goto P_0c0aabb4;
case 0x0c0aabb6u: goto P_0c0aabb6;
case 0x0c0aabb8u: goto P_0c0aabb8;
case 0x0c0aabbau: goto P_0c0aabba;
case 0x0c0aabbcu: goto P_0c0aabbc;
case 0x0c0aabbeu: goto P_0c0aabbe;
case 0x0c0aabc0u: goto P_0c0aabc0;
case 0x0c0aabc2u: goto P_0c0aabc2;
case 0x0c0aabc4u: goto P_0c0aabc4;
case 0x0c0aabc6u: goto P_0c0aabc6;
case 0x0c0aabc8u: goto P_0c0aabc8;
case 0x0c0aabcau: goto P_0c0aabca;
case 0x0c0aabccu: goto P_0c0aabcc;
case 0x0c0aabceu: goto P_0c0aabce;
case 0x0c0aabd0u: goto P_0c0aabd0;
case 0x0c0aabd2u: goto P_0c0aabd2;
case 0x0c0aabd4u: goto P_0c0aabd4;
case 0x0c0aabd6u: goto P_0c0aabd6;
case 0x0c0aabd8u: goto P_0c0aabd8;
case 0x0c0aabdau: goto P_0c0aabda;
case 0x0c0aabdcu: goto P_0c0aabdc;
case 0x0c0aabdeu: goto P_0c0aabde;
case 0x0c0aabe0u: goto P_0c0aabe0;
case 0x0c0aabe2u: goto P_0c0aabe2;
case 0x0c0aabe4u: goto P_0c0aabe4;
case 0x0c0aabe6u: goto P_0c0aabe6;
case 0x0c0aabe8u: goto P_0c0aabe8;
case 0x0c0aabeau: goto P_0c0aabea;
case 0x0c0aabecu: goto P_0c0aabec;
case 0x0c0aabeeu: goto P_0c0aabee;
case 0x0c0aabf0u: goto P_0c0aabf0;
case 0x0c0aabf2u: goto P_0c0aabf2;
case 0x0c0aabf4u: goto P_0c0aabf4;
case 0x0c0c6298u: goto P_0c0c6298;
case 0x0c0c629au: goto P_0c0c629a;
case 0x0c0c629cu: goto P_0c0c629c;
case 0x0c0c629eu: goto P_0c0c629e;
case 0x0c0c62a0u: goto P_0c0c62a0;
case 0x0c0c62a2u: goto P_0c0c62a2;
case 0x0c0c62a4u: goto P_0c0c62a4;
case 0x0c0c62a6u: goto P_0c0c62a6;
case 0x0c0c62a8u: goto P_0c0c62a8;
case 0x0c0c62aau: goto P_0c0c62aa;
case 0x0c0c62acu: goto P_0c0c62ac;
case 0x0c0c62aeu: goto P_0c0c62ae;
case 0x0c0c62b0u: goto P_0c0c62b0;
case 0x0c0c62b2u: goto P_0c0c62b2;
case 0x0c0c62b4u: goto P_0c0c62b4;
case 0x0c0c62b6u: goto P_0c0c62b6;
case 0x0c0c62b8u: goto P_0c0c62b8;
case 0x0c0c62bau: goto P_0c0c62ba;
case 0x0c0c62bcu: goto P_0c0c62bc;
case 0x0c0c62beu: goto P_0c0c62be;
case 0x0c0c62c0u: goto P_0c0c62c0;
case 0x0c0c62c2u: goto P_0c0c62c2;
case 0x0c0c62c4u: goto P_0c0c62c4;
case 0x0c0c62c6u: goto P_0c0c62c6;
case 0x0c0c62c8u: goto P_0c0c62c8;
case 0x0c0c62cau: goto P_0c0c62ca;
case 0x0c0c62ccu: goto P_0c0c62cc;
case 0x0c0c62ceu: goto P_0c0c62ce;
case 0x0c0c62d0u: goto P_0c0c62d0;
case 0x0c0c62d2u: goto P_0c0c62d2;
case 0x0c0c62d4u: goto P_0c0c62d4;
case 0x0c0c62d6u: goto P_0c0c62d6;
case 0x0c0c62d8u: goto P_0c0c62d8;
case 0x0c0c62dau: goto P_0c0c62da;
case 0x0c0c62dcu: goto P_0c0c62dc;
case 0x0c0c62deu: goto P_0c0c62de;
case 0x0c0c62e0u: goto P_0c0c62e0;
case 0x0c0c62e2u: goto P_0c0c62e2;
case 0x0c0c62e4u: goto P_0c0c62e4;
case 0x0c0c62e6u: goto P_0c0c62e6;
case 0x0c0c62e8u: goto P_0c0c62e8;
case 0x0c0c62eau: goto P_0c0c62ea;
case 0x0c0c62ecu: goto P_0c0c62ec;
case 0x0c0c62eeu: goto P_0c0c62ee;
case 0x0c0c62f0u: goto P_0c0c62f0;
case 0x0c0c62f2u: goto P_0c0c62f2;
case 0x0c0c62f4u: goto P_0c0c62f4;
case 0x0c0c62f6u: goto P_0c0c62f6;
case 0x0c0c62f8u: goto P_0c0c62f8;
case 0x0c0c62fau: goto P_0c0c62fa;
case 0x0c0c62fcu: goto P_0c0c62fc;
case 0x0c0c62feu: goto P_0c0c62fe;
case 0x0c0c6300u: goto P_0c0c6300;
case 0x0c0c6302u: goto P_0c0c6302;
case 0x0c0c6304u: goto P_0c0c6304;
case 0x0c0c6306u: goto P_0c0c6306;
case 0x0c0c6308u: goto P_0c0c6308;
case 0x0c0c630au: goto P_0c0c630a;
case 0x0c0c630cu: goto P_0c0c630c;
case 0x0c0c630eu: goto P_0c0c630e;
case 0x0c0c6310u: goto P_0c0c6310;
case 0x0c0c6312u: goto P_0c0c6312;
case 0x0c0c6314u: goto P_0c0c6314;
case 0x0c0c6316u: goto P_0c0c6316;
case 0x0c0c6318u: goto P_0c0c6318;
case 0x0c0c631au: goto P_0c0c631a;
case 0x0c0c631cu: goto P_0c0c631c;
case 0x0c0c631eu: goto P_0c0c631e;
case 0x0c0c6320u: goto P_0c0c6320;
case 0x0c0c6322u: goto P_0c0c6322;
case 0x0c0c6324u: goto P_0c0c6324;
case 0x0c0c6326u: goto P_0c0c6326;
case 0x0c0c6328u: goto P_0c0c6328;
case 0x0c0c632au: goto P_0c0c632a;
case 0x0c0c632cu: goto P_0c0c632c;
case 0x0c0c8644u: goto P_0c0c8644;
case 0x0c0c8646u: goto P_0c0c8646;
case 0x0c0c8648u: goto P_0c0c8648;
case 0x0c0c864au: goto P_0c0c864a;
case 0x0c0c864cu: goto P_0c0c864c;
case 0x0c0c864eu: goto P_0c0c864e;
case 0x0c0c8650u: goto P_0c0c8650;
case 0x0c0c8652u: goto P_0c0c8652;
case 0x0c0c8654u: goto P_0c0c8654;
case 0x0c0c8656u: goto P_0c0c8656;
case 0x0c0c8658u: goto P_0c0c8658;
case 0x0c0c865au: goto P_0c0c865a;
case 0x0c0c865cu: goto P_0c0c865c;
case 0x0c0c865eu: goto P_0c0c865e;
case 0x0c0c8660u: goto P_0c0c8660;
case 0x0c0c8662u: goto P_0c0c8662;
case 0x0c0c8664u: goto P_0c0c8664;
case 0x0c0c8666u: goto P_0c0c8666;
case 0x0c0c8668u: goto P_0c0c8668;
case 0x0c0c866au: goto P_0c0c866a;
case 0x0c0c866cu: goto P_0c0c866c;
case 0x0c0c866eu: goto P_0c0c866e;
case 0x0c0c8670u: goto P_0c0c8670;
case 0x0c0c8672u: goto P_0c0c8672;
case 0x0c0c8674u: goto P_0c0c8674;
case 0x0c0c8676u: goto P_0c0c8676;
case 0x0c0c8678u: goto P_0c0c8678;
case 0x0c0c867au: goto P_0c0c867a;
case 0x0c0c867cu: goto P_0c0c867c;
case 0x0c0c867eu: goto P_0c0c867e;
case 0x0c0c8680u: goto P_0c0c8680;
case 0x0c0c8682u: goto P_0c0c8682;
case 0x0c0c8684u: goto P_0c0c8684;
case 0x0c0c8686u: goto P_0c0c8686;
case 0x0c0c8688u: goto P_0c0c8688;
case 0x0c0c868au: goto P_0c0c868a;
case 0x0c0c868cu: goto P_0c0c868c;
case 0x0c0c868eu: goto P_0c0c868e;
case 0x0c0c8690u: goto P_0c0c8690;
case 0x0c0c8692u: goto P_0c0c8692;
case 0x0c0c8694u: goto P_0c0c8694;
case 0x0c0c8696u: goto P_0c0c8696;
case 0x0c0c8698u: goto P_0c0c8698;
case 0x0c0c869au: goto P_0c0c869a;
case 0x0c0c869cu: goto P_0c0c869c;
case 0x0c0c869eu: goto P_0c0c869e;
case 0x0c0c86a0u: goto P_0c0c86a0;
case 0x0c0c86a2u: goto P_0c0c86a2;
case 0x0c0c86a4u: goto P_0c0c86a4;
case 0x0c0c86a6u: goto P_0c0c86a6;
case 0x0c0c86a8u: goto P_0c0c86a8;
case 0x0c0c86aau: goto P_0c0c86aa;
case 0x0c0c86acu: goto P_0c0c86ac;
case 0x0c0c86aeu: goto P_0c0c86ae;
case 0x0c0c86b0u: goto P_0c0c86b0;
case 0x0c0c86b2u: goto P_0c0c86b2;
case 0x0c0c86b4u: goto P_0c0c86b4;
case 0x0c0c86b6u: goto P_0c0c86b6;
case 0x0c0c86b8u: goto P_0c0c86b8;
case 0x0c0c86bau: goto P_0c0c86ba;
case 0x0c0c86bcu: goto P_0c0c86bc;
case 0x0c0c86beu: goto P_0c0c86be;
case 0x0c0c86c0u: goto P_0c0c86c0;
case 0x0c0c86c2u: goto P_0c0c86c2;
case 0x0c0c86c4u: goto P_0c0c86c4;
case 0x0c0c86c6u: goto P_0c0c86c6;
case 0x0c0c86c8u: goto P_0c0c86c8;
case 0x0c0c86cau: goto P_0c0c86ca;
case 0x0c0c86ccu: goto P_0c0c86cc;
case 0x0c0c86ceu: goto P_0c0c86ce;
case 0x0c0c86d0u: goto P_0c0c86d0;
case 0x0c0c86d2u: goto P_0c0c86d2;
case 0x0c0c86d4u: goto P_0c0c86d4;
case 0x0c0c86d6u: goto P_0c0c86d6;
case 0x0c0c86d8u: goto P_0c0c86d8;
case 0x0c0c9c14u: goto P_0c0c9c14;
case 0x0c0c9c16u: goto P_0c0c9c16;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04df6a: /* original 4f22, guest PC 0x0c04df6a */
if(!s->budget--) { s->failed_pc=0x0c04df6au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04df6c;
P_0c04df6c: /* original 4f12, guest PC 0x0c04df6c */
if(!s->budget--) { s->failed_pc=0x0c04df6cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04df6e;
P_0c04df6e: /* original 8f03, guest PC 0x0c04df6e */
if(!s->budget--) { s->failed_pc=0x0c04df6eu; return 0; }
cond=r[17]&1u;
r[11]=r[6];
if(!cond) { goto P_0c04df78; }
goto P_0c04df72;
P_0c04df70: /* original 6b63, guest PC 0x0c04df70 */
if(!s->budget--) { s->failed_pc=0x0c04df70u; return 0; }
r[11]=r[6];
goto P_0c04df72;
P_0c04df72: /* original 9034, guest PC 0x0c04df72 */
if(!s->budget--) { s->failed_pc=0x0c04df72u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dfdeu,2);
goto P_0c04df74;
P_0c04df74: /* original a051, guest PC 0x0c04df74 */
if(!s->budget--) { s->failed_pc=0x0c04df74u; return 0; }
goto P_0c04e01a;
P_0c04df76: /* original 0009, guest PC 0x0c04df76 */
if(!s->budget--) { s->failed_pc=0x0c04df76u; return 0; }
goto P_0c04df78;
P_0c04df78: /* original 9332, guest PC 0x0c04df78 */
if(!s->budget--) { s->failed_pc=0x0c04df78u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dfe0u,2);
goto P_0c04df7a;
P_0c04df7a: /* original 52ea, guest PC 0x0c04df7a */
if(!s->budget--) { s->failed_pc=0x0c04df7au; return 0; }
r[2]=read(ram,r[14]+40,4);
goto P_0c04df7c;
P_0c04df7c: /* original d421, guest PC 0x0c04df7c */
if(!s->budget--) { s->failed_pc=0x0c04df7cu; return 0; }
r[4]=read(ram,0x0c04e004u,4);
goto P_0c04df7e;
P_0c04df7e: /* original 223f, guest PC 0x0c04df7e */
if(!s->budget--) { s->failed_pc=0x0c04df7eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[2]*(int32_t)(int16_t)r[3]);
goto P_0c04df80;
P_0c04df80: /* original 021a, guest PC 0x0c04df80 */
if(!s->budget--) { s->failed_pc=0x0c04df80u; return 0; }
r[2]=r[19];
goto P_0c04df82;
P_0c04df82: /* original 622f, guest PC 0x0c04df82 */
if(!s->budget--) { s->failed_pc=0x0c04df82u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c04df84;
P_0c04df84: /* original 324c, guest PC 0x0c04df84 */
if(!s->budget--) { s->failed_pc=0x0c04df84u; return 0; }
r[2]+=r[4];
goto P_0c04df86;
P_0c04df86: /* original 8422, guest PC 0x0c04df86 */
if(!s->budget--) { s->failed_pc=0x0c04df86u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+2,1);
goto P_0c04df88;
P_0c04df88: /* original 2008, guest PC 0x0c04df88 */
if(!s->budget--) { s->failed_pc=0x0c04df88u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04df8a;
P_0c04df8a: /* original 8b02, guest PC 0x0c04df8a */
if(!s->budget--) { s->failed_pc=0x0c04df8au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04df92; }
goto P_0c04df8c;
P_0c04df8c: /* original 9029, guest PC 0x0c04df8c */
if(!s->budget--) { s->failed_pc=0x0c04df8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dfe2u,2);
goto P_0c04df8e;
P_0c04df8e: /* original a044, guest PC 0x0c04df8e */
if(!s->budget--) { s->failed_pc=0x0c04df8eu; return 0; }
goto P_0c04e01a;
P_0c04df90: /* original 0009, guest PC 0x0c04df90 */
if(!s->budget--) { s->failed_pc=0x0c04df90u; return 0; }
goto P_0c04df92;
P_0c04df92: /* original 50e1, guest PC 0x0c04df92 */
if(!s->budget--) { s->failed_pc=0x0c04df92u; return 0; }
r[0]=read(ram,r[14]+4,4);
goto P_0c04df94;
P_0c04df94: /* original 8801, guest PC 0x0c04df94 */
if(!s->budget--) { s->failed_pc=0x0c04df94u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c04df96;
P_0c04df96: /* original 8903, guest PC 0x0c04df96 */
if(!s->budget--) { s->failed_pc=0x0c04df96u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04dfa0; }
goto P_0c04df98;
P_0c04df98: /* original 8802, guest PC 0x0c04df98 */
if(!s->budget--) { s->failed_pc=0x0c04df98u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c04df9a;
P_0c04df9a: /* original 8904, guest PC 0x0c04df9a */
if(!s->budget--) { s->failed_pc=0x0c04df9au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04dfa6; }
goto P_0c04df9c;
P_0c04df9c: /* original a006, guest PC 0x0c04df9c */
if(!s->budget--) { s->failed_pc=0x0c04df9cu; return 0; }
goto P_0c04dfac;
P_0c04df9e: /* original 0009, guest PC 0x0c04df9e */
if(!s->budget--) { s->failed_pc=0x0c04df9eu; return 0; }
goto P_0c04dfa0;
P_0c04dfa0: /* original da19, guest PC 0x0c04dfa0 */
if(!s->budget--) { s->failed_pc=0x0c04dfa0u; return 0; }
r[10]=read(ram,0x0c04e008u,4);
goto P_0c04dfa2;
P_0c04dfa2: /* original a006, guest PC 0x0c04dfa2 */
if(!s->budget--) { s->failed_pc=0x0c04dfa2u; return 0; }
goto P_0c04dfb2;
P_0c04dfa4: /* original 0009, guest PC 0x0c04dfa4 */
if(!s->budget--) { s->failed_pc=0x0c04dfa4u; return 0; }
goto P_0c04dfa6;
P_0c04dfa6: /* original da19, guest PC 0x0c04dfa6 */
if(!s->budget--) { s->failed_pc=0x0c04dfa6u; return 0; }
r[10]=read(ram,0x0c04e00cu,4);
goto P_0c04dfa8;
P_0c04dfa8: /* original a003, guest PC 0x0c04dfa8 */
if(!s->budget--) { s->failed_pc=0x0c04dfa8u; return 0; }
goto P_0c04dfb2;
P_0c04dfaa: /* original 0009, guest PC 0x0c04dfaa */
if(!s->budget--) { s->failed_pc=0x0c04dfaau; return 0; }
goto P_0c04dfac;
P_0c04dfac: /* original 901a, guest PC 0x0c04dfac */
if(!s->budget--) { s->failed_pc=0x0c04dfacu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dfe4u,2);
goto P_0c04dfae;
P_0c04dfae: /* original a034, guest PC 0x0c04dfae */
if(!s->budget--) { s->failed_pc=0x0c04dfaeu; return 0; }
goto P_0c04e01a;
P_0c04dfb0: /* original 0009, guest PC 0x0c04dfb0 */
if(!s->budget--) { s->failed_pc=0x0c04dfb0u; return 0; }
goto P_0c04dfb2;
P_0c04dfb2: /* original 9215, guest PC 0x0c04dfb2 */
if(!s->budget--) { s->failed_pc=0x0c04dfb2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dfe0u,2);
goto P_0c04dfb4;
P_0c04dfb4: /* original 4b15, guest PC 0x0c04dfb4 */
if(!s->budget--) { s->failed_pc=0x0c04dfb4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>0)!=0);
goto P_0c04dfb6;
P_0c04dfb6: /* original 53ea, guest PC 0x0c04dfb6 */
if(!s->budget--) { s->failed_pc=0x0c04dfb6u; return 0; }
r[3]=read(ram,r[14]+40,4);
goto P_0c04dfb8;
P_0c04dfb8: /* original 6d53, guest PC 0x0c04dfb8 */
if(!s->budget--) { s->failed_pc=0x0c04dfb8u; return 0; }
r[13]=r[5];
goto P_0c04dfba;
P_0c04dfba: /* original 232f, guest PC 0x0c04dfba */
if(!s->budget--) { s->failed_pc=0x0c04dfbau; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[3]*(int32_t)(int16_t)r[2]);
goto P_0c04dfbc;
P_0c04dfbc: /* original 031a, guest PC 0x0c04dfbc */
if(!s->budget--) { s->failed_pc=0x0c04dfbcu; return 0; }
r[3]=r[19];
goto P_0c04dfbe;
P_0c04dfbe: /* original 633f, guest PC 0x0c04dfbe */
if(!s->budget--) { s->failed_pc=0x0c04dfbeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04dfc0;
P_0c04dfc0: /* original 343c, guest PC 0x0c04dfc0 */
if(!s->budget--) { s->failed_pc=0x0c04dfc0u; return 0; }
r[4]+=r[3];
goto P_0c04dfc2;
P_0c04dfc2: /* original e301, guest PC 0x0c04dfc2 */
if(!s->budget--) { s->failed_pc=0x0c04dfc2u; return 0; }
r[3]=0x00000001u;
goto P_0c04dfc4;
P_0c04dfc4: /* original 143c, guest PC 0x0c04dfc4 */
if(!s->budget--) { s->failed_pc=0x0c04dfc4u; return 0; }
write(ram,r[4]+48,r[3],4);
goto P_0c04dfc6;
P_0c04dfc6: /* original 14bd, guest PC 0x0c04dfc6 */
if(!s->budget--) { s->failed_pc=0x0c04dfc6u; return 0; }
write(ram,r[4]+52,r[11],4);
goto P_0c04dfc8;
P_0c04dfc8: /* original 990d, guest PC 0x0c04dfc8 */
if(!s->budget--) { s->failed_pc=0x0c04dfc8u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dfe6u,2);
goto P_0c04dfca;
P_0c04dfca: /* original 8f25, guest PC 0x0c04dfca */
if(!s->budget--) { s->failed_pc=0x0c04dfcau; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(!cond) { goto P_0c04e018; }
goto P_0c04dfce;
P_0c04dfcc: /* original ec00, guest PC 0x0c04dfcc */
if(!s->budget--) { s->failed_pc=0x0c04dfccu; return 0; }
r[12]=0x00000000u;
goto P_0c04dfce;
P_0c04dfce: /* original 65d3, guest PC 0x0c04dfce */
if(!s->budget--) { s->failed_pc=0x0c04dfceu; return 0; }
r[5]=r[13];
goto P_0c04dfd0;
P_0c04dfd0: /* original 4a0b, guest PC 0x0c04dfd0 */
if(!s->budget--) { s->failed_pc=0x0c04dfd0u; return 0; }
target=r[10];
r[16]=code_base|0x0c04dfd4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04dfd4u) { target=s->pc; goto dispatch; }
goto P_0c04dfd4;
P_0c04dfd2: /* original 64e3, guest PC 0x0c04dfd2 */
if(!s->budget--) { s->failed_pc=0x0c04dfd2u; return 0; }
r[4]=r[14];
goto P_0c04dfd4;
P_0c04dfd4: /* original 6403, guest PC 0x0c04dfd4 */
if(!s->budget--) { s->failed_pc=0x0c04dfd4u; return 0; }
r[4]=r[0];
goto P_0c04dfd6;
P_0c04dfd6: /* original 4411, guest PC 0x0c04dfd6 */
if(!s->budget--) { s->failed_pc=0x0c04dfd6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c04dfd8;
P_0c04dfd8: /* original 891a, guest PC 0x0c04dfd8 */
if(!s->budget--) { s->failed_pc=0x0c04dfd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e010; }
goto P_0c04dfda;
P_0c04dfda: /* original a01e, guest PC 0x0c04dfda */
if(!s->budget--) { s->failed_pc=0x0c04dfdau; return 0; }
r[0]=r[4];
goto P_0c04e01a;
P_0c04dfdc: /* original 6043, guest PC 0x0c04dfdc */
if(!s->budget--) { s->failed_pc=0x0c04dfdcu; return 0; }
r[0]=r[4];
return vf3_matrix_family(0x0c04dfdeu,s,ram);
P_0c04e010: /* original 7c01, guest PC 0x0c04e010 */
if(!s->budget--) { s->failed_pc=0x0c04e010u; return 0; }
r[12]+=0x00000001u;
goto P_0c04e012;
P_0c04e012: /* original 3cb3, guest PC 0x0c04e012 */
if(!s->budget--) { s->failed_pc=0x0c04e012u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[11])!=0);
goto P_0c04e014;
P_0c04e014: /* original 8fdb, guest PC 0x0c04e014 */
if(!s->budget--) { s->failed_pc=0x0c04e014u; return 0; }
cond=r[17]&1u;
r[13]+=r[9];
if(!cond) { goto P_0c04dfce; }
goto P_0c04e018;
P_0c04e016: /* original 3d9c, guest PC 0x0c04e016 */
if(!s->budget--) { s->failed_pc=0x0c04e016u; return 0; }
r[13]+=r[9];
goto P_0c04e018;
P_0c04e018: /* original e000, guest PC 0x0c04e018 */
if(!s->budget--) { s->failed_pc=0x0c04e018u; return 0; }
r[0]=0x00000000u;
goto P_0c04e01a;
P_0c04e01a: /* original 4f16, guest PC 0x0c04e01a */
if(!s->budget--) { s->failed_pc=0x0c04e01au; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e01c;
P_0c04e01c: /* original 4f26, guest PC 0x0c04e01c */
if(!s->budget--) { s->failed_pc=0x0c04e01cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e01e;
P_0c04e01e: /* original 69f6, guest PC 0x0c04e01e */
if(!s->budget--) { s->failed_pc=0x0c04e01eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04e020;
P_0c04e020: /* original 6af6, guest PC 0x0c04e020 */
if(!s->budget--) { s->failed_pc=0x0c04e020u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04e022;
P_0c04e022: /* original 6bf6, guest PC 0x0c04e022 */
if(!s->budget--) { s->failed_pc=0x0c04e022u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04e024;
P_0c04e024: /* original 6cf6, guest PC 0x0c04e024 */
if(!s->budget--) { s->failed_pc=0x0c04e024u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04e026;
P_0c04e026: /* original 6df6, guest PC 0x0c04e026 */
if(!s->budget--) { s->failed_pc=0x0c04e026u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04e028;
P_0c04e028: /* original 000b, guest PC 0x0c04e028 */
if(!s->budget--) { s->failed_pc=0x0c04e028u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04e02a: /* original 6ef6, guest PC 0x0c04e02a */
if(!s->budget--) { s->failed_pc=0x0c04e02au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04e02cu,s,ram);
P_0c0503cc: /* original 4f22, guest PC 0x0c0503cc */
if(!s->budget--) { s->failed_pc=0x0c0503ccu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0503ce;
P_0c0503ce: /* original 4f12, guest PC 0x0c0503ce */
if(!s->budget--) { s->failed_pc=0x0c0503ceu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0503d0;
P_0c0503d0: /* original 7ffc, guest PC 0x0c0503d0 */
if(!s->budget--) { s->failed_pc=0x0c0503d0u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0503d2;
P_0c0503d2: /* original 2f52, guest PC 0x0c0503d2 */
if(!s->budget--) { s->failed_pc=0x0c0503d2u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0503d4;
P_0c0503d4: /* original 9c42, guest PC 0x0c0503d4 */
if(!s->budget--) { s->failed_pc=0x0c0503d4u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05045cu,2);
goto P_0c0503d6;
P_0c0503d6: /* original d325, guest PC 0x0c0503d6 */
if(!s->budget--) { s->failed_pc=0x0c0503d6u; return 0; }
r[3]=read(ram,0x0c05046cu,4);
goto P_0c0503d8;
P_0c0503d8: /* original 2bcf, guest PC 0x0c0503d8 */
if(!s->budget--) { s->failed_pc=0x0c0503d8u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[11]*(int32_t)(int16_t)r[12]);
goto P_0c0503da;
P_0c0503da: /* original 2f56, guest PC 0x0c0503da */
if(!s->budget--) { s->failed_pc=0x0c0503dau; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0503dc;
P_0c0503dc: /* original 2fb6, guest PC 0x0c0503dc */
if(!s->budget--) { s->failed_pc=0x0c0503dcu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0503de;
P_0c0503de: /* original d224, guest PC 0x0c0503de */
if(!s->budget--) { s->failed_pc=0x0c0503deu; return 0; }
r[2]=read(ram,0x0c050470u,4);
goto P_0c0503e0;
P_0c0503e0: /* original 0c1a, guest PC 0x0c0503e0 */
if(!s->budget--) { s->failed_pc=0x0c0503e0u; return 0; }
r[12]=r[19];
goto P_0c0503e2;
P_0c0503e2: /* original d120, guest PC 0x0c0503e2 */
if(!s->budget--) { s->failed_pc=0x0c0503e2u; return 0; }
r[1]=read(ram,0x0c050464u,4);
goto P_0c0503e4;
P_0c0503e4: /* original 6ccf, guest PC 0x0c0503e4 */
if(!s->budget--) { s->failed_pc=0x0c0503e4u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c0503e6;
P_0c0503e6: /* original 3c3c, guest PC 0x0c0503e6 */
if(!s->budget--) { s->failed_pc=0x0c0503e6u; return 0; }
r[12]+=r[3];
goto P_0c0503e8;
P_0c0503e8: /* original 410b, guest PC 0x0c0503e8 */
if(!s->budget--) { s->failed_pc=0x0c0503e8u; return 0; }
target=r[1];
r[16]=code_base|0x0c0503ecu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0503ecu) { target=s->pc; goto dispatch; }
goto P_0c0503ec;
P_0c0503ea: /* original 2f26, guest PC 0x0c0503ea */
if(!s->budget--) { s->failed_pc=0x0c0503eau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0503ec;
P_0c0503ec: /* original e301, guest PC 0x0c0503ec */
if(!s->budget--) { s->failed_pc=0x0c0503ecu; return 0; }
r[3]=0x00000001u;
goto P_0c0503ee;
P_0c0503ee: /* original 7f0c, guest PC 0x0c0503ee */
if(!s->budget--) { s->failed_pc=0x0c0503eeu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0503f0;
P_0c0503f0: /* original 6df2, guest PC 0x0c0503f0 */
if(!s->budget--) { s->failed_pc=0x0c0503f0u; return 0; }
tmp=read(ram,r[15],4);
r[13]=tmp;
goto P_0c0503f2;
P_0c0503f2: /* original 1c3c, guest PC 0x0c0503f2 */
if(!s->budget--) { s->failed_pc=0x0c0503f2u; return 0; }
write(ram,r[12]+48,r[3],4);
goto P_0c0503f4;
P_0c0503f4: /* original 52c1, guest PC 0x0c0503f4 */
if(!s->budget--) { s->failed_pc=0x0c0503f4u; return 0; }
r[2]=read(ram,r[12]+4,4);
goto P_0c0503f6;
P_0c0503f6: /* original d01f, guest PC 0x0c0503f6 */
if(!s->budget--) { s->failed_pc=0x0c0503f6u; return 0; }
r[0]=read(ram,0x0c050474u,4);
goto P_0c0503f8;
P_0c0503f8: /* original 6323, guest PC 0x0c0503f8 */
if(!s->budget--) { s->failed_pc=0x0c0503f8u; return 0; }
r[3]=r[2];
goto P_0c0503fa;
P_0c0503fa: /* original 4208, guest PC 0x0c0503fa */
if(!s->budget--) { s->failed_pc=0x0c0503fau; return 0; }
r[2]<<=2;
goto P_0c0503fc;
P_0c0503fc: /* original 323c, guest PC 0x0c0503fc */
if(!s->budget--) { s->failed_pc=0x0c0503fcu; return 0; }
r[2]+=r[3];
goto P_0c0503fe;
P_0c0503fe: /* original 4208, guest PC 0x0c0503fe */
if(!s->budget--) { s->failed_pc=0x0c0503feu; return 0; }
r[2]<<=2;
goto P_0c050400;
P_0c050400: /* original 4208, guest PC 0x0c050400 */
if(!s->budget--) { s->failed_pc=0x0c050400u; return 0; }
r[2]<<=2;
goto P_0c050402;
P_0c050402: /* original 622f, guest PC 0x0c050402 */
if(!s->budget--) { s->failed_pc=0x0c050402u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c050404;
P_0c050404: /* original 012e, guest PC 0x0c050404 */
if(!s->budget--) { s->failed_pc=0x0c050404u; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c050406;
P_0c050406: /* original 1c1d, guest PC 0x0c050406 */
if(!s->budget--) { s->failed_pc=0x0c050406u; return 0; }
write(ram,r[12]+52,r[1],4);
goto P_0c050408;
P_0c050408: /* original d81b, guest PC 0x0c050408 */
if(!s->budget--) { s->failed_pc=0x0c050408u; return 0; }
r[8]=read(ram,0x0c050478u,4);
goto P_0c05040a;
P_0c05040a: /* original d91c, guest PC 0x0c05040a */
if(!s->budget--) { s->failed_pc=0x0c05040au; return 0; }
r[9]=read(ram,0x0c05047cu,4);
goto P_0c05040c;
P_0c05040c: /* original 9a27, guest PC 0x0c05040c */
if(!s->budget--) { s->failed_pc=0x0c05040cu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05045eu,2);
goto P_0c05040e;
P_0c05040e: /* original a010, guest PC 0x0c05040e */
if(!s->budget--) { s->failed_pc=0x0c05040eu; return 0; }
r[14]=0x00000000u;
goto P_0c050432;
P_0c050410: /* original ee00, guest PC 0x0c050410 */
if(!s->budget--) { s->failed_pc=0x0c050410u; return 0; }
r[14]=0x00000000u;
goto P_0c050412;
P_0c050412: /* original 2fe6, guest PC 0x0c050412 */
if(!s->budget--) { s->failed_pc=0x0c050412u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050414;
P_0c050414: /* original d213, guest PC 0x0c050414 */
if(!s->budget--) { s->failed_pc=0x0c050414u; return 0; }
r[2]=read(ram,0x0c050464u,4);
goto P_0c050416;
P_0c050416: /* original 420b, guest PC 0x0c050416 */
if(!s->budget--) { s->failed_pc=0x0c050416u; return 0; }
target=r[2];
r[16]=code_base|0x0c05041au;
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05041au) { target=s->pc; goto dispatch; }
goto P_0c05041a;
P_0c050418: /* original 2f96, guest PC 0x0c050418 */
if(!s->budget--) { s->failed_pc=0x0c050418u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05041a;
P_0c05041a: /* original 65e3, guest PC 0x0c05041a */
if(!s->budget--) { s->failed_pc=0x0c05041au; return 0; }
r[5]=r[14];
goto P_0c05041c;
P_0c05041c: /* original 66d3, guest PC 0x0c05041c */
if(!s->budget--) { s->failed_pc=0x0c05041cu; return 0; }
r[6]=r[13];
goto P_0c05041e;
P_0c05041e: /* original 7f08, guest PC 0x0c05041e */
if(!s->budget--) { s->failed_pc=0x0c05041eu; return 0; }
r[15]+=0x00000008u;
goto P_0c050420;
P_0c050420: /* original 480b, guest PC 0x0c050420 */
if(!s->budget--) { s->failed_pc=0x0c050420u; return 0; }
target=r[8];
r[16]=code_base|0x0c050424u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050424u) { target=s->pc; goto dispatch; }
goto P_0c050424;
P_0c050422: /* original 64b3, guest PC 0x0c050422 */
if(!s->budget--) { s->failed_pc=0x0c050422u; return 0; }
r[4]=r[11];
goto P_0c050424;
P_0c050424: /* original 6403, guest PC 0x0c050424 */
if(!s->budget--) { s->failed_pc=0x0c050424u; return 0; }
r[4]=r[0];
goto P_0c050426;
P_0c050426: /* original 4411, guest PC 0x0c050426 */
if(!s->budget--) { s->failed_pc=0x0c050426u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c050428;
P_0c050428: /* original 8901, guest PC 0x0c050428 */
if(!s->budget--) { s->failed_pc=0x0c050428u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05042e; }
goto P_0c05042a;
P_0c05042a: /* original a008, guest PC 0x0c05042a */
if(!s->budget--) { s->failed_pc=0x0c05042au; return 0; }
r[0]=r[4];
goto P_0c05043e;
P_0c05042c: /* original 6043, guest PC 0x0c05042c */
if(!s->budget--) { s->failed_pc=0x0c05042cu; return 0; }
r[0]=r[4];
goto P_0c05042e;
P_0c05042e: /* original 7e01, guest PC 0x0c05042e */
if(!s->budget--) { s->failed_pc=0x0c05042eu; return 0; }
r[14]+=0x00000001u;
goto P_0c050430;
P_0c050430: /* original 3dac, guest PC 0x0c050430 */
if(!s->budget--) { s->failed_pc=0x0c050430u; return 0; }
r[13]+=r[10];
goto P_0c050432;
P_0c050432: /* original 52c7, guest PC 0x0c050432 */
if(!s->budget--) { s->failed_pc=0x0c050432u; return 0; }
r[2]=read(ram,r[12]+28,4);
goto P_0c050434;
P_0c050434: /* original 6322, guest PC 0x0c050434 */
if(!s->budget--) { s->failed_pc=0x0c050434u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c050436;
P_0c050436: /* original 7301, guest PC 0x0c050436 */
if(!s->budget--) { s->failed_pc=0x0c050436u; return 0; }
r[3]+=0x00000001u;
goto P_0c050438;
P_0c050438: /* original 3e33, guest PC 0x0c050438 */
if(!s->budget--) { s->failed_pc=0x0c050438u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c05043a;
P_0c05043a: /* original 8bea, guest PC 0x0c05043a */
if(!s->budget--) { s->failed_pc=0x0c05043au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c050412; }
goto P_0c05043c;
P_0c05043c: /* original e000, guest PC 0x0c05043c */
if(!s->budget--) { s->failed_pc=0x0c05043cu; return 0; }
r[0]=0x00000000u;
goto P_0c05043e;
P_0c05043e: /* original 7f04, guest PC 0x0c05043e */
if(!s->budget--) { s->failed_pc=0x0c05043eu; return 0; }
r[15]+=0x00000004u;
goto P_0c050440;
P_0c050440: /* original 4f16, guest PC 0x0c050440 */
if(!s->budget--) { s->failed_pc=0x0c050440u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c050442;
P_0c050442: /* original 4f26, guest PC 0x0c050442 */
if(!s->budget--) { s->failed_pc=0x0c050442u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c050444;
P_0c050444: /* original 68f6, guest PC 0x0c050444 */
if(!s->budget--) { s->failed_pc=0x0c050444u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c050446;
P_0c050446: /* original 69f6, guest PC 0x0c050446 */
if(!s->budget--) { s->failed_pc=0x0c050446u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c050448;
P_0c050448: /* original 6af6, guest PC 0x0c050448 */
if(!s->budget--) { s->failed_pc=0x0c050448u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05044a;
P_0c05044a: /* original 6bf6, guest PC 0x0c05044a */
if(!s->budget--) { s->failed_pc=0x0c05044au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05044c;
P_0c05044c: /* original 6cf6, guest PC 0x0c05044c */
if(!s->budget--) { s->failed_pc=0x0c05044cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05044e;
P_0c05044e: /* original 6df6, guest PC 0x0c05044e */
if(!s->budget--) { s->failed_pc=0x0c05044eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c050450;
P_0c050450: /* original 000b, guest PC 0x0c050450 */
if(!s->budget--) { s->failed_pc=0x0c050450u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c050452: /* original 6ef6, guest PC 0x0c050452 */
if(!s->budget--) { s->failed_pc=0x0c050452u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c050454u,s,ram);
P_0c050492: /* original 4f22, guest PC 0x0c050492 */
if(!s->budget--) { s->failed_pc=0x0c050492u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c050494;
P_0c050494: /* original 4f12, guest PC 0x0c050494 */
if(!s->budget--) { s->failed_pc=0x0c050494u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c050496;
P_0c050496: /* original 7ffc, guest PC 0x0c050496 */
if(!s->budget--) { s->failed_pc=0x0c050496u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c050498;
P_0c050498: /* original 2f52, guest PC 0x0c050498 */
if(!s->budget--) { s->failed_pc=0x0c050498u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c05049a;
P_0c05049a: /* original 9c55, guest PC 0x0c05049a */
if(!s->budget--) { s->failed_pc=0x0c05049au; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c050548u,2);
goto P_0c05049c;
P_0c05049c: /* original d32b, guest PC 0x0c05049c */
if(!s->budget--) { s->failed_pc=0x0c05049cu; return 0; }
r[3]=read(ram,0x0c05054cu,4);
goto P_0c05049e;
P_0c05049e: /* original 2bcf, guest PC 0x0c05049e */
if(!s->budget--) { s->failed_pc=0x0c05049eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[11]*(int32_t)(int16_t)r[12]);
goto P_0c0504a0;
P_0c0504a0: /* original 2f56, guest PC 0x0c0504a0 */
if(!s->budget--) { s->failed_pc=0x0c0504a0u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0504a2;
P_0c0504a2: /* original 2fb6, guest PC 0x0c0504a2 */
if(!s->budget--) { s->failed_pc=0x0c0504a2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0504a4;
P_0c0504a4: /* original d22a, guest PC 0x0c0504a4 */
if(!s->budget--) { s->failed_pc=0x0c0504a4u; return 0; }
r[2]=read(ram,0x0c050550u,4);
goto P_0c0504a6;
P_0c0504a6: /* original 0c1a, guest PC 0x0c0504a6 */
if(!s->budget--) { s->failed_pc=0x0c0504a6u; return 0; }
r[12]=r[19];
goto P_0c0504a8;
P_0c0504a8: /* original d12a, guest PC 0x0c0504a8 */
if(!s->budget--) { s->failed_pc=0x0c0504a8u; return 0; }
r[1]=read(ram,0x0c050554u,4);
goto P_0c0504aa;
P_0c0504aa: /* original 6ccf, guest PC 0x0c0504aa */
if(!s->budget--) { s->failed_pc=0x0c0504aau; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c0504ac;
P_0c0504ac: /* original 3c3c, guest PC 0x0c0504ac */
if(!s->budget--) { s->failed_pc=0x0c0504acu; return 0; }
r[12]+=r[3];
goto P_0c0504ae;
P_0c0504ae: /* original 410b, guest PC 0x0c0504ae */
if(!s->budget--) { s->failed_pc=0x0c0504aeu; return 0; }
target=r[1];
r[16]=code_base|0x0c0504b2u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0504b2u) { target=s->pc; goto dispatch; }
goto P_0c0504b2;
P_0c0504b0: /* original 2f26, guest PC 0x0c0504b0 */
if(!s->budget--) { s->failed_pc=0x0c0504b0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0504b2;
P_0c0504b2: /* original e301, guest PC 0x0c0504b2 */
if(!s->budget--) { s->failed_pc=0x0c0504b2u; return 0; }
r[3]=0x00000001u;
goto P_0c0504b4;
P_0c0504b4: /* original 7f0c, guest PC 0x0c0504b4 */
if(!s->budget--) { s->failed_pc=0x0c0504b4u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0504b6;
P_0c0504b6: /* original 6df2, guest PC 0x0c0504b6 */
if(!s->budget--) { s->failed_pc=0x0c0504b6u; return 0; }
tmp=read(ram,r[15],4);
r[13]=tmp;
goto P_0c0504b8;
P_0c0504b8: /* original 1c3c, guest PC 0x0c0504b8 */
if(!s->budget--) { s->failed_pc=0x0c0504b8u; return 0; }
write(ram,r[12]+48,r[3],4);
goto P_0c0504ba;
P_0c0504ba: /* original 52c1, guest PC 0x0c0504ba */
if(!s->budget--) { s->failed_pc=0x0c0504bau; return 0; }
r[2]=read(ram,r[12]+4,4);
goto P_0c0504bc;
P_0c0504bc: /* original d026, guest PC 0x0c0504bc */
if(!s->budget--) { s->failed_pc=0x0c0504bcu; return 0; }
r[0]=read(ram,0x0c050558u,4);
goto P_0c0504be;
P_0c0504be: /* original 6323, guest PC 0x0c0504be */
if(!s->budget--) { s->failed_pc=0x0c0504beu; return 0; }
r[3]=r[2];
goto P_0c0504c0;
P_0c0504c0: /* original 4208, guest PC 0x0c0504c0 */
if(!s->budget--) { s->failed_pc=0x0c0504c0u; return 0; }
r[2]<<=2;
goto P_0c0504c2;
P_0c0504c2: /* original 323c, guest PC 0x0c0504c2 */
if(!s->budget--) { s->failed_pc=0x0c0504c2u; return 0; }
r[2]+=r[3];
goto P_0c0504c4;
P_0c0504c4: /* original 4208, guest PC 0x0c0504c4 */
if(!s->budget--) { s->failed_pc=0x0c0504c4u; return 0; }
r[2]<<=2;
goto P_0c0504c6;
P_0c0504c6: /* original 4208, guest PC 0x0c0504c6 */
if(!s->budget--) { s->failed_pc=0x0c0504c6u; return 0; }
r[2]<<=2;
goto P_0c0504c8;
P_0c0504c8: /* original 622f, guest PC 0x0c0504c8 */
if(!s->budget--) { s->failed_pc=0x0c0504c8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c0504ca;
P_0c0504ca: /* original 012e, guest PC 0x0c0504ca */
if(!s->budget--) { s->failed_pc=0x0c0504cau; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c0504cc;
P_0c0504cc: /* original 1c1d, guest PC 0x0c0504cc */
if(!s->budget--) { s->failed_pc=0x0c0504ccu; return 0; }
write(ram,r[12]+52,r[1],4);
goto P_0c0504ce;
P_0c0504ce: /* original d823, guest PC 0x0c0504ce */
if(!s->budget--) { s->failed_pc=0x0c0504ceu; return 0; }
r[8]=read(ram,0x0c05055cu,4);
goto P_0c0504d0;
P_0c0504d0: /* original d923, guest PC 0x0c0504d0 */
if(!s->budget--) { s->failed_pc=0x0c0504d0u; return 0; }
r[9]=read(ram,0x0c050560u,4);
goto P_0c0504d2;
P_0c0504d2: /* original 9a3a, guest PC 0x0c0504d2 */
if(!s->budget--) { s->failed_pc=0x0c0504d2u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05054au,2);
goto P_0c0504d4;
P_0c0504d4: /* original a010, guest PC 0x0c0504d4 */
if(!s->budget--) { s->failed_pc=0x0c0504d4u; return 0; }
r[14]=0x00000000u;
goto P_0c0504f8;
P_0c0504d6: /* original ee00, guest PC 0x0c0504d6 */
if(!s->budget--) { s->failed_pc=0x0c0504d6u; return 0; }
r[14]=0x00000000u;
goto P_0c0504d8;
P_0c0504d8: /* original 2fe6, guest PC 0x0c0504d8 */
if(!s->budget--) { s->failed_pc=0x0c0504d8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0504da;
P_0c0504da: /* original d21e, guest PC 0x0c0504da */
if(!s->budget--) { s->failed_pc=0x0c0504dau; return 0; }
r[2]=read(ram,0x0c050554u,4);
goto P_0c0504dc;
P_0c0504dc: /* original 420b, guest PC 0x0c0504dc */
if(!s->budget--) { s->failed_pc=0x0c0504dcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0504e0u;
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0504e0u) { target=s->pc; goto dispatch; }
goto P_0c0504e0;
P_0c0504de: /* original 2f96, guest PC 0x0c0504de */
if(!s->budget--) { s->failed_pc=0x0c0504deu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0504e0;
P_0c0504e0: /* original 65e3, guest PC 0x0c0504e0 */
if(!s->budget--) { s->failed_pc=0x0c0504e0u; return 0; }
r[5]=r[14];
goto P_0c0504e2;
P_0c0504e2: /* original 66d3, guest PC 0x0c0504e2 */
if(!s->budget--) { s->failed_pc=0x0c0504e2u; return 0; }
r[6]=r[13];
goto P_0c0504e4;
P_0c0504e4: /* original 7f08, guest PC 0x0c0504e4 */
if(!s->budget--) { s->failed_pc=0x0c0504e4u; return 0; }
r[15]+=0x00000008u;
goto P_0c0504e6;
P_0c0504e6: /* original 480b, guest PC 0x0c0504e6 */
if(!s->budget--) { s->failed_pc=0x0c0504e6u; return 0; }
target=r[8];
r[16]=code_base|0x0c0504eau;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0504eau) { target=s->pc; goto dispatch; }
goto P_0c0504ea;
P_0c0504e8: /* original 64b3, guest PC 0x0c0504e8 */
if(!s->budget--) { s->failed_pc=0x0c0504e8u; return 0; }
r[4]=r[11];
goto P_0c0504ea;
P_0c0504ea: /* original 6403, guest PC 0x0c0504ea */
if(!s->budget--) { s->failed_pc=0x0c0504eau; return 0; }
r[4]=r[0];
goto P_0c0504ec;
P_0c0504ec: /* original 4411, guest PC 0x0c0504ec */
if(!s->budget--) { s->failed_pc=0x0c0504ecu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0504ee;
P_0c0504ee: /* original 8901, guest PC 0x0c0504ee */
if(!s->budget--) { s->failed_pc=0x0c0504eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0504f4; }
goto P_0c0504f0;
P_0c0504f0: /* original a008, guest PC 0x0c0504f0 */
if(!s->budget--) { s->failed_pc=0x0c0504f0u; return 0; }
r[0]=r[4];
goto P_0c050504;
P_0c0504f2: /* original 6043, guest PC 0x0c0504f2 */
if(!s->budget--) { s->failed_pc=0x0c0504f2u; return 0; }
r[0]=r[4];
goto P_0c0504f4;
P_0c0504f4: /* original 7e01, guest PC 0x0c0504f4 */
if(!s->budget--) { s->failed_pc=0x0c0504f4u; return 0; }
r[14]+=0x00000001u;
goto P_0c0504f6;
P_0c0504f6: /* original 3dac, guest PC 0x0c0504f6 */
if(!s->budget--) { s->failed_pc=0x0c0504f6u; return 0; }
r[13]+=r[10];
goto P_0c0504f8;
P_0c0504f8: /* original 52c7, guest PC 0x0c0504f8 */
if(!s->budget--) { s->failed_pc=0x0c0504f8u; return 0; }
r[2]=read(ram,r[12]+28,4);
goto P_0c0504fa;
P_0c0504fa: /* original 6322, guest PC 0x0c0504fa */
if(!s->budget--) { s->failed_pc=0x0c0504fau; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0504fc;
P_0c0504fc: /* original 7301, guest PC 0x0c0504fc */
if(!s->budget--) { s->failed_pc=0x0c0504fcu; return 0; }
r[3]+=0x00000001u;
goto P_0c0504fe;
P_0c0504fe: /* original 3e33, guest PC 0x0c0504fe */
if(!s->budget--) { s->failed_pc=0x0c0504feu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c050500;
P_0c050500: /* original 8bea, guest PC 0x0c050500 */
if(!s->budget--) { s->failed_pc=0x0c050500u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0504d8; }
goto P_0c050502;
P_0c050502: /* original e000, guest PC 0x0c050502 */
if(!s->budget--) { s->failed_pc=0x0c050502u; return 0; }
r[0]=0x00000000u;
goto P_0c050504;
P_0c050504: /* original 7f04, guest PC 0x0c050504 */
if(!s->budget--) { s->failed_pc=0x0c050504u; return 0; }
r[15]+=0x00000004u;
goto P_0c050506;
P_0c050506: /* original 4f16, guest PC 0x0c050506 */
if(!s->budget--) { s->failed_pc=0x0c050506u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c050508;
P_0c050508: /* original 4f26, guest PC 0x0c050508 */
if(!s->budget--) { s->failed_pc=0x0c050508u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05050a;
P_0c05050a: /* original 68f6, guest PC 0x0c05050a */
if(!s->budget--) { s->failed_pc=0x0c05050au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c05050c;
P_0c05050c: /* original 69f6, guest PC 0x0c05050c */
if(!s->budget--) { s->failed_pc=0x0c05050cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05050e;
P_0c05050e: /* original 6af6, guest PC 0x0c05050e */
if(!s->budget--) { s->failed_pc=0x0c05050eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c050510;
P_0c050510: /* original 6bf6, guest PC 0x0c050510 */
if(!s->budget--) { s->failed_pc=0x0c050510u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c050512;
P_0c050512: /* original 6cf6, guest PC 0x0c050512 */
if(!s->budget--) { s->failed_pc=0x0c050512u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c050514;
P_0c050514: /* original 6df6, guest PC 0x0c050514 */
if(!s->budget--) { s->failed_pc=0x0c050514u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c050516;
P_0c050516: /* original 000b, guest PC 0x0c050516 */
if(!s->budget--) { s->failed_pc=0x0c050516u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c050518: /* original 6ef6, guest PC 0x0c050518 */
if(!s->budget--) { s->failed_pc=0x0c050518u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c05051au,s,ram);
P_0c062cb8: /* original 4f22, guest PC 0x0c062cb8 */
if(!s->budget--) { s->failed_pc=0x0c062cb8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c062cba;
P_0c062cba: /* original 4e08, guest PC 0x0c062cba */
if(!s->budget--) { s->failed_pc=0x0c062cbau; return 0; }
r[14]<<=2;
goto P_0c062cbc;
P_0c062cbc: /* original 7ff4, guest PC 0x0c062cbc */
if(!s->budget--) { s->failed_pc=0x0c062cbcu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c062cbe;
P_0c062cbe: /* original 3e2c, guest PC 0x0c062cbe */
if(!s->budget--) { s->failed_pc=0x0c062cbeu; return 0; }
r[14]+=r[2];
goto P_0c062cc0;
P_0c062cc0: /* original 1f51, guest PC 0x0c062cc0 */
if(!s->budget--) { s->failed_pc=0x0c062cc0u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c062cc2;
P_0c062cc2: /* original 4e08, guest PC 0x0c062cc2 */
if(!s->budget--) { s->failed_pc=0x0c062cc2u; return 0; }
r[14]<<=2;
goto P_0c062cc4;
P_0c062cc4: /* original 1f62, guest PC 0x0c062cc4 */
if(!s->budget--) { s->failed_pc=0x0c062cc4u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c062cc6;
P_0c062cc6: /* original 6eee, guest PC 0x0c062cc6 */
if(!s->budget--) { s->failed_pc=0x0c062cc6u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)r[14];
goto P_0c062cc8;
P_0c062cc8: /* original 6c32, guest PC 0x0c062cc8 */
if(!s->budget--) { s->failed_pc=0x0c062cc8u; return 0; }
tmp=read(ram,r[3],4);
r[12]=tmp;
goto P_0c062cca;
P_0c062cca: /* original 0eee, guest PC 0x0c062cca */
if(!s->budget--) { s->failed_pc=0x0c062ccau; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c062ccc;
P_0c062ccc: /* original 2ee8, guest PC 0x0c062ccc */
if(!s->budget--) { s->failed_pc=0x0c062cccu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c062cce;
P_0c062cce: /* original 8d32, guest PC 0x0c062cce */
if(!s->budget--) { s->failed_pc=0x0c062cceu; return 0; }
cond=r[17]&1u;
r[11]=0x00000000u;
if(cond) { goto P_0c062d36; }
goto P_0c062cd2;
P_0c062cd0: /* original eb00, guest PC 0x0c062cd0 */
if(!s->budget--) { s->failed_pc=0x0c062cd0u; return 0; }
r[11]=0x00000000u;
goto P_0c062cd2;
P_0c062cd2: /* original ea04, guest PC 0x0c062cd2 */
if(!s->budget--) { s->failed_pc=0x0c062cd2u; return 0; }
r[10]=0x00000004u;
goto P_0c062cd4;
P_0c062cd4: /* original dd21, guest PC 0x0c062cd4 */
if(!s->budget--) { s->failed_pc=0x0c062cd4u; return 0; }
r[13]=read(ram,0x0c062d5cu,4);
goto P_0c062cd6;
P_0c062cd6: /* original d820, guest PC 0x0c062cd6 */
if(!s->budget--) { s->failed_pc=0x0c062cd6u; return 0; }
r[8]=read(ram,0x0c062d58u,4);
goto P_0c062cd8;
P_0c062cd8: /* original 64e1, guest PC 0x0c062cd8 */
if(!s->budget--) { s->failed_pc=0x0c062cd8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[4]=tmp;
goto P_0c062cda;
P_0c062cda: /* original 644d, guest PC 0x0c062cda */
if(!s->budget--) { s->failed_pc=0x0c062cdau; return 0; }
r[4]=r[4]&65535u;
goto P_0c062cdc;
P_0c062cdc: /* original 6343, guest PC 0x0c062cdc */
if(!s->budget--) { s->failed_pc=0x0c062cdcu; return 0; }
r[3]=r[4];
goto P_0c062cde;
P_0c062cde: /* original 23a8, guest PC 0x0c062cde */
if(!s->budget--) { s->failed_pc=0x0c062cdeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[10])==0)!=0);
goto P_0c062ce0;
P_0c062ce0: /* original 8b26, guest PC 0x0c062ce0 */
if(!s->budget--) { s->failed_pc=0x0c062ce0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062d30; }
goto P_0c062ce2;
P_0c062ce2: /* original e102, guest PC 0x0c062ce2 */
if(!s->budget--) { s->failed_pc=0x0c062ce2u; return 0; }
r[1]=0x00000002u;
goto P_0c062ce4;
P_0c062ce4: /* original 2148, guest PC 0x0c062ce4 */
if(!s->budget--) { s->failed_pc=0x0c062ce4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c062ce6;
P_0c062ce6: /* original 8923, guest PC 0x0c062ce6 */
if(!s->budget--) { s->failed_pc=0x0c062ce6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062d30; }
goto P_0c062ce8;
P_0c062ce8: /* original 9231, guest PC 0x0c062ce8 */
if(!s->budget--) { s->failed_pc=0x0c062ce8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062d4eu,2);
goto P_0c062cea;
P_0c062cea: /* original 2248, guest PC 0x0c062cea */
if(!s->budget--) { s->failed_pc=0x0c062ceau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c062cec;
P_0c062cec: /* original 8920, guest PC 0x0c062cec */
if(!s->budget--) { s->failed_pc=0x0c062cecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062d30; }
goto P_0c062cee;
P_0c062cee: /* original 51f1, guest PC 0x0c062cee */
if(!s->budget--) { s->failed_pc=0x0c062ceeu; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c062cf0;
P_0c062cf0: /* original 53e4, guest PC 0x0c062cf0 */
if(!s->budget--) { s->failed_pc=0x0c062cf0u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c062cf2;
P_0c062cf2: /* original 3313, guest PC 0x0c062cf2 */
if(!s->budget--) { s->failed_pc=0x0c062cf2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[1])!=0);
goto P_0c062cf4;
P_0c062cf4: /* original 8b1c, guest PC 0x0c062cf4 */
if(!s->budget--) { s->failed_pc=0x0c062cf4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062d30; }
goto P_0c062cf6;
P_0c062cf6: /* original 53e4, guest PC 0x0c062cf6 */
if(!s->budget--) { s->failed_pc=0x0c062cf6u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c062cf8;
P_0c062cf8: /* original 33c3, guest PC 0x0c062cf8 */
if(!s->budget--) { s->failed_pc=0x0c062cf8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[12])!=0);
goto P_0c062cfa;
P_0c062cfa: /* original 8919, guest PC 0x0c062cfa */
if(!s->budget--) { s->failed_pc=0x0c062cfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062d30; }
goto P_0c062cfc;
P_0c062cfc: /* original 639f, guest PC 0x0c062cfc */
if(!s->budget--) { s->failed_pc=0x0c062cfcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[9];
goto P_0c062cfe;
P_0c062cfe: /* original 2338, guest PC 0x0c062cfe */
if(!s->budget--) { s->failed_pc=0x0c062cfeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c062d00;
P_0c062d00: /* original 8f03, guest PC 0x0c062d00 */
if(!s->budget--) { s->failed_pc=0x0c062d00u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[8],4);
r[5]=tmp;
if(!cond) { goto P_0c062d0a; }
goto P_0c062d04;
P_0c062d02: /* original 6582, guest PC 0x0c062d02 */
if(!s->budget--) { s->failed_pc=0x0c062d02u; return 0; }
tmp=read(ram,r[8],4);
r[5]=tmp;
goto P_0c062d04;
P_0c062d04: /* original 54e3, guest PC 0x0c062d04 */
if(!s->budget--) { s->failed_pc=0x0c062d04u; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c062d06;
P_0c062d06: /* original a002, guest PC 0x0c062d06 */
if(!s->budget--) { s->failed_pc=0x0c062d06u; return 0; }
r[4]+=r[5];
goto P_0c062d0e;
P_0c062d08: /* original 345c, guest PC 0x0c062d08 */
if(!s->budget--) { s->failed_pc=0x0c062d08u; return 0; }
r[4]+=r[5];
goto P_0c062d0a;
P_0c062d0a: /* original 54e3, guest PC 0x0c062d0a */
if(!s->budget--) { s->failed_pc=0x0c062d0au; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c062d0c;
P_0c062d0c: /* original 3458, guest PC 0x0c062d0c */
if(!s->budget--) { s->failed_pc=0x0c062d0cu; return 0; }
r[4]-=r[5];
goto P_0c062d0e;
P_0c062d0e: /* original bb16, guest PC 0x0c062d0e */
if(!s->budget--) { s->failed_pc=0x0c062d0eu; return 0; }
target=0x0c06233eu; r[16]=code_base|0x0c062d12u;
r[5]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c062d12u) { target=s->pc; goto dispatch; }
goto P_0c062d12;
P_0c062d10: /* original 65f3, guest PC 0x0c062d10 */
if(!s->budget--) { s->failed_pc=0x0c062d10u; return 0; }
r[5]=r[15];
goto P_0c062d12;
P_0c062d12: /* original 6403, guest PC 0x0c062d12 */
if(!s->budget--) { s->failed_pc=0x0c062d12u; return 0; }
r[4]=r[0];
goto P_0c062d14;
P_0c062d14: /* original 2448, guest PC 0x0c062d14 */
if(!s->budget--) { s->failed_pc=0x0c062d14u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c062d16;
P_0c062d16: /* original 890b, guest PC 0x0c062d16 */
if(!s->budget--) { s->failed_pc=0x0c062d16u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062d30; }
goto P_0c062d18;
P_0c062d18: /* original 5245, guest PC 0x0c062d18 */
if(!s->budget--) { s->failed_pc=0x0c062d18u; return 0; }
r[2]=read(ram,r[4]+20,4);
goto P_0c062d1a;
P_0c062d1a: /* original 6321, guest PC 0x0c062d1a */
if(!s->budget--) { s->failed_pc=0x0c062d1au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[3]=tmp;
goto P_0c062d1c;
P_0c062d1c: /* original 52f2, guest PC 0x0c062d1c */
if(!s->budget--) { s->failed_pc=0x0c062d1cu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c062d1e;
P_0c062d1e: /* original 633d, guest PC 0x0c062d1e */
if(!s->budget--) { s->failed_pc=0x0c062d1eu; return 0; }
r[3]=r[3]&65535u;
goto P_0c062d20;
P_0c062d20: /* original 6121, guest PC 0x0c062d20 */
if(!s->budget--) { s->failed_pc=0x0c062d20u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[1]=tmp;
goto P_0c062d22;
P_0c062d22: /* original 23d9, guest PC 0x0c062d22 */
if(!s->budget--) { s->failed_pc=0x0c062d22u; return 0; }
r[3]&=r[13];
goto P_0c062d24;
P_0c062d24: /* original 611d, guest PC 0x0c062d24 */
if(!s->budget--) { s->failed_pc=0x0c062d24u; return 0; }
r[1]=r[1]&65535u;
goto P_0c062d26;
P_0c062d26: /* original 21d9, guest PC 0x0c062d26 */
if(!s->budget--) { s->failed_pc=0x0c062d26u; return 0; }
r[1]&=r[13];
goto P_0c062d28;
P_0c062d28: /* original 3310, guest PC 0x0c062d28 */
if(!s->budget--) { s->failed_pc=0x0c062d28u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c062d2a;
P_0c062d2a: /* original 8b01, guest PC 0x0c062d2a */
if(!s->budget--) { s->failed_pc=0x0c062d2au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062d30; }
goto P_0c062d2c;
P_0c062d2c: /* original 5ce4, guest PC 0x0c062d2c */
if(!s->budget--) { s->failed_pc=0x0c062d2cu; return 0; }
r[12]=read(ram,r[14]+16,4);
goto P_0c062d2e;
P_0c062d2e: /* original 6be3, guest PC 0x0c062d2e */
if(!s->budget--) { s->failed_pc=0x0c062d2eu; return 0; }
r[11]=r[14];
goto P_0c062d30;
P_0c062d30: /* original 5ee2, guest PC 0x0c062d30 */
if(!s->budget--) { s->failed_pc=0x0c062d30u; return 0; }
r[14]=read(ram,r[14]+8,4);
goto P_0c062d32;
P_0c062d32: /* original 2ee8, guest PC 0x0c062d32 */
if(!s->budget--) { s->failed_pc=0x0c062d32u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c062d34;
P_0c062d34: /* original 8bd0, guest PC 0x0c062d34 */
if(!s->budget--) { s->failed_pc=0x0c062d34u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062cd8; }
goto P_0c062d36;
P_0c062d36: /* original 60b3, guest PC 0x0c062d36 */
if(!s->budget--) { s->failed_pc=0x0c062d36u; return 0; }
r[0]=r[11];
goto P_0c062d38;
P_0c062d38: /* original 0009, guest PC 0x0c062d38 */
if(!s->budget--) { s->failed_pc=0x0c062d38u; return 0; }
goto P_0c062d3a;
P_0c062d3a: /* original 7f0c, guest PC 0x0c062d3a */
if(!s->budget--) { s->failed_pc=0x0c062d3au; return 0; }
r[15]+=0x0000000cu;
goto P_0c062d3c;
P_0c062d3c: /* original 4f26, guest PC 0x0c062d3c */
if(!s->budget--) { s->failed_pc=0x0c062d3cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c062d3e;
P_0c062d3e: /* original 68f6, guest PC 0x0c062d3e */
if(!s->budget--) { s->failed_pc=0x0c062d3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c062d40;
P_0c062d40: /* original 69f6, guest PC 0x0c062d40 */
if(!s->budget--) { s->failed_pc=0x0c062d40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c062d42;
P_0c062d42: /* original 6af6, guest PC 0x0c062d42 */
if(!s->budget--) { s->failed_pc=0x0c062d42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c062d44;
P_0c062d44: /* original 6bf6, guest PC 0x0c062d44 */
if(!s->budget--) { s->failed_pc=0x0c062d44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c062d46;
P_0c062d46: /* original 6cf6, guest PC 0x0c062d46 */
if(!s->budget--) { s->failed_pc=0x0c062d46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c062d48;
P_0c062d48: /* original 6df6, guest PC 0x0c062d48 */
if(!s->budget--) { s->failed_pc=0x0c062d48u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c062d4a;
P_0c062d4a: /* original 000b, guest PC 0x0c062d4a */
if(!s->budget--) { s->failed_pc=0x0c062d4au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c062d4c: /* original 6ef6, guest PC 0x0c062d4c */
if(!s->budget--) { s->failed_pc=0x0c062d4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c062d4eu,s,ram);
P_0c076a08: /* original 4f22, guest PC 0x0c076a08 */
if(!s->budget--) { s->failed_pc=0x0c076a08u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c076a0a;
P_0c076a0a: /* original 04dc, guest PC 0x0c076a0a */
if(!s->budget--) { s->failed_pc=0x0c076a0au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c076a0c;
P_0c076a0c: /* original d245, guest PC 0x0c076a0c */
if(!s->budget--) { s->failed_pc=0x0c076a0cu; return 0; }
r[2]=read(ram,0x0c076b24u,4);
goto P_0c076a0e;
P_0c076a0e: /* original 644c, guest PC 0x0c076a0e */
if(!s->budget--) { s->failed_pc=0x0c076a0eu; return 0; }
r[4]=r[4]&255u;
goto P_0c076a10;
P_0c076a10: /* original 2439, guest PC 0x0c076a10 */
if(!s->budget--) { s->failed_pc=0x0c076a10u; return 0; }
r[4]&=r[3];
goto P_0c076a12;
P_0c076a12: /* original 420b, guest PC 0x0c076a12 */
if(!s->budget--) { s->failed_pc=0x0c076a12u; return 0; }
target=r[2];
r[16]=code_base|0x0c076a16u;
write(ram,r[13]+r[0],r[4],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c076a16u) { target=s->pc; goto dispatch; }
goto P_0c076a16;
P_0c076a14: /* original 0d44, guest PC 0x0c076a14 */
if(!s->budget--) { s->failed_pc=0x0c076a14u; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c076a16;
P_0c076a16: /* original 9480, guest PC 0x0c076a16 */
if(!s->budget--) { s->failed_pc=0x0c076a16u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076b1au,2);
goto P_0c076a18;
P_0c076a18: /* original de43, guest PC 0x0c076a18 */
if(!s->budget--) { s->failed_pc=0x0c076a18u; return 0; }
r[14]=read(ram,0x0c076b28u,4);
goto P_0c076a1a;
P_0c076a1a: /* original d544, guest PC 0x0c076a1a */
if(!s->budget--) { s->failed_pc=0x0c076a1au; return 0; }
r[5]=read(ram,0x0c076b2cu,4);
goto P_0c076a1c;
P_0c076a1c: /* original d344, guest PC 0x0c076a1c */
if(!s->budget--) { s->failed_pc=0x0c076a1cu; return 0; }
r[3]=read(ram,0x0c076b30u,4);
goto P_0c076a1e;
P_0c076a1e: /* original 34ec, guest PC 0x0c076a1e */
if(!s->budget--) { s->failed_pc=0x0c076a1eu; return 0; }
r[4]+=r[14];
goto P_0c076a20;
P_0c076a20: /* original 430b, guest PC 0x0c076a20 */
if(!s->budget--) { s->failed_pc=0x0c076a20u; return 0; }
target=r[3];
r[16]=code_base|0x0c076a24u;
r[6]=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c076a24u) { target=s->pc; goto dispatch; }
goto P_0c076a24;
P_0c076a22: /* original e608, guest PC 0x0c076a22 */
if(!s->budget--) { s->failed_pc=0x0c076a22u; return 0; }
r[6]=0x00000008u;
goto P_0c076a24;
P_0c076a24: /* original 2008, guest PC 0x0c076a24 */
if(!s->budget--) { s->failed_pc=0x0c076a24u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c076a26;
P_0c076a26: /* original 8b2d, guest PC 0x0c076a26 */
if(!s->budget--) { s->failed_pc=0x0c076a26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076a84; }
goto P_0c076a28;
P_0c076a28: /* original 9578, guest PC 0x0c076a28 */
if(!s->budget--) { s->failed_pc=0x0c076a28u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076b1cu,2);
goto P_0c076a2a;
P_0c076a2a: /* original 9476, guest PC 0x0c076a2a */
if(!s->budget--) { s->failed_pc=0x0c076a2au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076b1au,2);
goto P_0c076a2c;
P_0c076a2c: /* original d240, guest PC 0x0c076a2c */
if(!s->budget--) { s->failed_pc=0x0c076a2cu; return 0; }
r[2]=read(ram,0x0c076b30u,4);
goto P_0c076a2e;
P_0c076a2e: /* original 35ec, guest PC 0x0c076a2e */
if(!s->budget--) { s->failed_pc=0x0c076a2eu; return 0; }
r[5]+=r[14];
goto P_0c076a30;
P_0c076a30: /* original 34ec, guest PC 0x0c076a30 */
if(!s->budget--) { s->failed_pc=0x0c076a30u; return 0; }
r[4]+=r[14];
goto P_0c076a32;
P_0c076a32: /* original 420b, guest PC 0x0c076a32 */
if(!s->budget--) { s->failed_pc=0x0c076a32u; return 0; }
target=r[2];
r[16]=code_base|0x0c076a36u;
r[6]=0x00000040u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c076a36u) { target=s->pc; goto dispatch; }
goto P_0c076a36;
P_0c076a34: /* original e640, guest PC 0x0c076a34 */
if(!s->budget--) { s->failed_pc=0x0c076a34u; return 0; }
r[6]=0x00000040u;
goto P_0c076a36;
P_0c076a36: /* original 2008, guest PC 0x0c076a36 */
if(!s->budget--) { s->failed_pc=0x0c076a36u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c076a38;
P_0c076a38: /* original 892e, guest PC 0x0c076a38 */
if(!s->budget--) { s->failed_pc=0x0c076a38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076a98; }
goto P_0c076a3a;
P_0c076a3a: /* original 9c6e, guest PC 0x0c076a3a */
if(!s->budget--) { s->failed_pc=0x0c076a3au; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076b1au,2);
goto P_0c076a3c;
P_0c076a3c: /* original 3cec, guest PC 0x0c076a3c */
if(!s->budget--) { s->failed_pc=0x0c076a3cu; return 0; }
r[12]+=r[14];
goto P_0c076a3e;
P_0c076a3e: /* original 64c3, guest PC 0x0c076a3e */
if(!s->budget--) { s->failed_pc=0x0c076a3eu; return 0; }
r[4]=r[12];
goto P_0c076a40;
P_0c076a40: /* original 740a, guest PC 0x0c076a40 */
if(!s->budget--) { s->failed_pc=0x0c076a40u; return 0; }
r[4]+=0x0000000au;
goto P_0c076a42;
P_0c076a42: /* original b07b, guest PC 0x0c076a42 */
if(!s->budget--) { s->failed_pc=0x0c076a42u; return 0; }
target=0x0c076b3cu; r[16]=code_base|0x0c076a46u;
r[5]=0x00000032u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c076a46u) { target=s->pc; goto dispatch; }
goto P_0c076a46;
P_0c076a44: /* original e532, guest PC 0x0c076a44 */
if(!s->budget--) { s->failed_pc=0x0c076a44u; return 0; }
r[5]=0x00000032u;
goto P_0c076a46;
P_0c076a46: /* original 6403, guest PC 0x0c076a46 */
if(!s->budget--) { s->failed_pc=0x0c076a46u; return 0; }
r[4]=r[0];
goto P_0c076a48;
P_0c076a48: /* original 85c4, guest PC 0x0c076a48 */
if(!s->budget--) { s->failed_pc=0x0c076a48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+8,2);
goto P_0c076a4a;
P_0c076a4a: /* original 650d, guest PC 0x0c076a4a */
if(!s->budget--) { s->failed_pc=0x0c076a4au; return 0; }
r[5]=r[0]&65535u;
goto P_0c076a4c;
P_0c076a4c: /* original 3540, guest PC 0x0c076a4c */
if(!s->budget--) { s->failed_pc=0x0c076a4cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[4])!=0);
goto P_0c076a4e;
P_0c076a4e: /* original 8915, guest PC 0x0c076a4e */
if(!s->budget--) { s->failed_pc=0x0c076a4eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076a7c; }
goto P_0c076a50;
P_0c076a50: /* original 9c64, guest PC 0x0c076a50 */
if(!s->budget--) { s->failed_pc=0x0c076a50u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076b1cu,2);
goto P_0c076a52;
P_0c076a52: /* original 3cec, guest PC 0x0c076a52 */
if(!s->budget--) { s->failed_pc=0x0c076a52u; return 0; }
r[12]+=r[14];
goto P_0c076a54;
P_0c076a54: /* original 64c3, guest PC 0x0c076a54 */
if(!s->budget--) { s->failed_pc=0x0c076a54u; return 0; }
r[4]=r[12];
goto P_0c076a56;
P_0c076a56: /* original 740a, guest PC 0x0c076a56 */
if(!s->budget--) { s->failed_pc=0x0c076a56u; return 0; }
r[4]+=0x0000000au;
goto P_0c076a58;
P_0c076a58: /* original b070, guest PC 0x0c076a58 */
if(!s->budget--) { s->failed_pc=0x0c076a58u; return 0; }
target=0x0c076b3cu; r[16]=code_base|0x0c076a5cu;
r[5]=0x00000032u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c076a5cu) { target=s->pc; goto dispatch; }
goto P_0c076a5c;
P_0c076a5a: /* original e532, guest PC 0x0c076a5a */
if(!s->budget--) { s->failed_pc=0x0c076a5au; return 0; }
r[5]=0x00000032u;
goto P_0c076a5c;
P_0c076a5c: /* original 6503, guest PC 0x0c076a5c */
if(!s->budget--) { s->failed_pc=0x0c076a5cu; return 0; }
r[5]=r[0];
goto P_0c076a5e;
P_0c076a5e: /* original 85c4, guest PC 0x0c076a5e */
if(!s->budget--) { s->failed_pc=0x0c076a5eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+8,2);
goto P_0c076a60;
P_0c076a60: /* original 640d, guest PC 0x0c076a60 */
if(!s->budget--) { s->failed_pc=0x0c076a60u; return 0; }
r[4]=r[0]&65535u;
goto P_0c076a62;
P_0c076a62: /* original 3450, guest PC 0x0c076a62 */
if(!s->budget--) { s->failed_pc=0x0c076a62u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c076a64;
P_0c076a64: /* original 8b0e, guest PC 0x0c076a64 */
if(!s->budget--) { s->failed_pc=0x0c076a64u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076a84; }
goto P_0c076a66;
P_0c076a66: /* original 9458, guest PC 0x0c076a66 */
if(!s->budget--) { s->failed_pc=0x0c076a66u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076b1au,2);
goto P_0c076a68;
P_0c076a68: /* original 9558, guest PC 0x0c076a68 */
if(!s->budget--) { s->failed_pc=0x0c076a68u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076b1cu,2);
goto P_0c076a6a;
P_0c076a6a: /* original d332, guest PC 0x0c076a6a */
if(!s->budget--) { s->failed_pc=0x0c076a6au; return 0; }
r[3]=read(ram,0x0c076b34u,4);
goto P_0c076a6c;
P_0c076a6c: /* original 34ec, guest PC 0x0c076a6c */
if(!s->budget--) { s->failed_pc=0x0c076a6cu; return 0; }
r[4]+=r[14];
goto P_0c076a6e;
P_0c076a6e: /* original 35ec, guest PC 0x0c076a6e */
if(!s->budget--) { s->failed_pc=0x0c076a6eu; return 0; }
r[5]+=r[14];
goto P_0c076a70;
P_0c076a70: /* original 430b, guest PC 0x0c076a70 */
if(!s->budget--) { s->failed_pc=0x0c076a70u; return 0; }
target=r[3];
r[16]=code_base|0x0c076a74u;
r[6]=0x00000040u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c076a74u) { target=s->pc; goto dispatch; }
goto P_0c076a74;
P_0c076a72: /* original e640, guest PC 0x0c076a72 */
if(!s->budget--) { s->failed_pc=0x0c076a72u; return 0; }
r[6]=0x00000040u;
goto P_0c076a74;
P_0c076a74: /* original 9451, guest PC 0x0c076a74 */
if(!s->budget--) { s->failed_pc=0x0c076a74u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076b1au,2);
goto P_0c076a76;
P_0c076a76: /* original e000, guest PC 0x0c076a76 */
if(!s->budget--) { s->failed_pc=0x0c076a76u; return 0; }
r[0]=0x00000000u;
goto P_0c076a78;
P_0c076a78: /* original 34ec, guest PC 0x0c076a78 */
if(!s->budget--) { s->failed_pc=0x0c076a78u; return 0; }
r[4]+=r[14];
goto P_0c076a7a;
P_0c076a7a: /* original 8144, guest PC 0x0c076a7a */
if(!s->budget--) { s->failed_pc=0x0c076a7au; return 0; }
write(ram,r[4]+8,r[0],2);
goto P_0c076a7c;
P_0c076a7c: /* original b011, guest PC 0x0c076a7c */
if(!s->budget--) { s->failed_pc=0x0c076a7cu; return 0; }
target=0x0c076aa2u; r[16]=code_base|0x0c076a80u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c076a80u) { target=s->pc; goto dispatch; }
goto P_0c076a80;
P_0c076a7e: /* original 0009, guest PC 0x0c076a7e */
if(!s->budget--) { s->failed_pc=0x0c076a7eu; return 0; }
goto P_0c076a80;
P_0c076a80: /* original a00a, guest PC 0x0c076a80 */
if(!s->budget--) { s->failed_pc=0x0c076a80u; return 0; }
goto P_0c076a98;
P_0c076a82: /* original 0009, guest PC 0x0c076a82 */
if(!s->budget--) { s->failed_pc=0x0c076a82u; return 0; }
goto P_0c076a84;
P_0c076a84: /* original b02f, guest PC 0x0c076a84 */
if(!s->budget--) { s->failed_pc=0x0c076a84u; return 0; }
target=0x0c076ae6u; r[16]=code_base|0x0c076a88u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c076a88u) { target=s->pc; goto dispatch; }
goto P_0c076a88;
P_0c076a86: /* original 0009, guest PC 0x0c076a86 */
if(!s->budget--) { s->failed_pc=0x0c076a86u; return 0; }
goto P_0c076a88;
P_0c076a88: /* original b00b, guest PC 0x0c076a88 */
if(!s->budget--) { s->failed_pc=0x0c076a88u; return 0; }
target=0x0c076aa2u; r[16]=code_base|0x0c076a8cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c076a8cu) { target=s->pc; goto dispatch; }
goto P_0c076a8c;
P_0c076a8a: /* original 0009, guest PC 0x0c076a8a */
if(!s->budget--) { s->failed_pc=0x0c076a8au; return 0; }
goto P_0c076a8c;
P_0c076a8c: /* original e074, guest PC 0x0c076a8c */
if(!s->budget--) { s->failed_pc=0x0c076a8cu; return 0; }
r[0]=0x00000074u;
goto P_0c076a8e;
P_0c076a8e: /* original 04dc, guest PC 0x0c076a8e */
if(!s->budget--) { s->failed_pc=0x0c076a8eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c076a90;
P_0c076a90: /* original e304, guest PC 0x0c076a90 */
if(!s->budget--) { s->failed_pc=0x0c076a90u; return 0; }
r[3]=0x00000004u;
goto P_0c076a92;
P_0c076a92: /* original 644c, guest PC 0x0c076a92 */
if(!s->budget--) { s->failed_pc=0x0c076a92u; return 0; }
r[4]=r[4]&255u;
goto P_0c076a94;
P_0c076a94: /* original 243b, guest PC 0x0c076a94 */
if(!s->budget--) { s->failed_pc=0x0c076a94u; return 0; }
r[4]|=r[3];
goto P_0c076a96;
P_0c076a96: /* original 0d44, guest PC 0x0c076a96 */
if(!s->budget--) { s->failed_pc=0x0c076a96u; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c076a98;
P_0c076a98: /* original 4f26, guest PC 0x0c076a98 */
if(!s->budget--) { s->failed_pc=0x0c076a98u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c076a9a;
P_0c076a9a: /* original 6cf6, guest PC 0x0c076a9a */
if(!s->budget--) { s->failed_pc=0x0c076a9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c076a9c;
P_0c076a9c: /* original 6df6, guest PC 0x0c076a9c */
if(!s->budget--) { s->failed_pc=0x0c076a9cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c076a9e;
P_0c076a9e: /* original 000b, guest PC 0x0c076a9e */
if(!s->budget--) { s->failed_pc=0x0c076a9eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c076aa0: /* original 6ef6, guest PC 0x0c076aa0 */
if(!s->budget--) { s->failed_pc=0x0c076aa0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c076aa2;
P_0c076aa2: /* original 2fe6, guest PC 0x0c076aa2 */
if(!s->budget--) { s->failed_pc=0x0c076aa2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c076aa4;
P_0c076aa4: /* original 9439, guest PC 0x0c076aa4 */
if(!s->budget--) { s->failed_pc=0x0c076aa4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076b1au,2);
goto P_0c076aa6;
P_0c076aa6: /* original 9539, guest PC 0x0c076aa6 */
if(!s->budget--) { s->failed_pc=0x0c076aa6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076b1cu,2);
goto P_0c076aa8;
P_0c076aa8: /* original 4f22, guest PC 0x0c076aa8 */
if(!s->budget--) { s->failed_pc=0x0c076aa8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c076aaa;
P_0c076aaa: /* original de1f, guest PC 0x0c076aaa */
if(!s->budget--) { s->failed_pc=0x0c076aaau; return 0; }
r[14]=read(ram,0x0c076b28u,4);
goto P_0c076aac;
P_0c076aac: /* original d320, guest PC 0x0c076aac */
if(!s->budget--) { s->failed_pc=0x0c076aacu; return 0; }
r[3]=read(ram,0x0c076b30u,4);
goto P_0c076aae;
P_0c076aae: /* original 35ec, guest PC 0x0c076aae */
if(!s->budget--) { s->failed_pc=0x0c076aaeu; return 0; }
r[5]+=r[14];
goto P_0c076ab0;
P_0c076ab0: /* original 34ec, guest PC 0x0c076ab0 */
if(!s->budget--) { s->failed_pc=0x0c076ab0u; return 0; }
r[4]+=r[14];
goto P_0c076ab2;
P_0c076ab2: /* original 430b, guest PC 0x0c076ab2 */
if(!s->budget--) { s->failed_pc=0x0c076ab2u; return 0; }
target=r[3];
r[16]=code_base|0x0c076ab6u;
r[6]=0x00000040u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c076ab6u) { target=s->pc; goto dispatch; }
goto P_0c076ab6;
P_0c076ab4: /* original e640, guest PC 0x0c076ab4 */
if(!s->budget--) { s->failed_pc=0x0c076ab4u; return 0; }
r[6]=0x00000040u;
goto P_0c076ab6;
P_0c076ab6: /* original 2008, guest PC 0x0c076ab6 */
if(!s->budget--) { s->failed_pc=0x0c076ab6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c076ab8;
P_0c076ab8: /* original 8912, guest PC 0x0c076ab8 */
if(!s->budget--) { s->failed_pc=0x0c076ab8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076ae0; }
goto P_0c076aba;
P_0c076aba: /* original 942e, guest PC 0x0c076aba */
if(!s->budget--) { s->failed_pc=0x0c076abau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076b1au,2);
goto P_0c076abc;
P_0c076abc: /* original 34ec, guest PC 0x0c076abc */
if(!s->budget--) { s->failed_pc=0x0c076abcu; return 0; }
r[4]+=r[14];
goto P_0c076abe;
P_0c076abe: /* original 554f, guest PC 0x0c076abe */
if(!s->budget--) { s->failed_pc=0x0c076abeu; return 0; }
r[5]=read(ram,r[4]+60,4);
goto P_0c076ac0;
P_0c076ac0: /* original 7501, guest PC 0x0c076ac0 */
if(!s->budget--) { s->failed_pc=0x0c076ac0u; return 0; }
r[5]+=0x00000001u;
goto P_0c076ac2;
P_0c076ac2: /* original 145f, guest PC 0x0c076ac2 */
if(!s->budget--) { s->failed_pc=0x0c076ac2u; return 0; }
write(ram,r[4]+60,r[5],4);
goto P_0c076ac4;
P_0c076ac4: /* original 740a, guest PC 0x0c076ac4 */
if(!s->budget--) { s->failed_pc=0x0c076ac4u; return 0; }
r[4]+=0x0000000au;
goto P_0c076ac6;
P_0c076ac6: /* original b039, guest PC 0x0c076ac6 */
if(!s->budget--) { s->failed_pc=0x0c076ac6u; return 0; }
target=0x0c076b3cu; r[16]=code_base|0x0c076acau;
r[5]=0x00000032u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c076acau) { target=s->pc; goto dispatch; }
goto P_0c076aca;
P_0c076ac8: /* original e532, guest PC 0x0c076ac8 */
if(!s->budget--) { s->failed_pc=0x0c076ac8u; return 0; }
r[5]=0x00000032u;
goto P_0c076aca;
P_0c076aca: /* original 9526, guest PC 0x0c076aca */
if(!s->budget--) { s->failed_pc=0x0c076acau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076b1au,2);
goto P_0c076acc;
P_0c076acc: /* original 9426, guest PC 0x0c076acc */
if(!s->budget--) { s->failed_pc=0x0c076accu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076b1cu,2);
goto P_0c076ace;
P_0c076ace: /* original 35ec, guest PC 0x0c076ace */
if(!s->budget--) { s->failed_pc=0x0c076aceu; return 0; }
r[5]+=r[14];
goto P_0c076ad0;
P_0c076ad0: /* original 8154, guest PC 0x0c076ad0 */
if(!s->budget--) { s->failed_pc=0x0c076ad0u; return 0; }
write(ram,r[5]+8,r[0],2);
goto P_0c076ad2;
P_0c076ad2: /* original 34ec, guest PC 0x0c076ad2 */
if(!s->budget--) { s->failed_pc=0x0c076ad2u; return 0; }
r[4]+=r[14];
goto P_0c076ad4;
P_0c076ad4: /* original d317, guest PC 0x0c076ad4 */
if(!s->budget--) { s->failed_pc=0x0c076ad4u; return 0; }
r[3]=read(ram,0x0c076b34u,4);
goto P_0c076ad6;
P_0c076ad6: /* original 430b, guest PC 0x0c076ad6 */
if(!s->budget--) { s->failed_pc=0x0c076ad6u; return 0; }
target=r[3];
r[16]=code_base|0x0c076adau;
r[6]=0x00000040u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c076adau) { target=s->pc; goto dispatch; }
goto P_0c076ada;
P_0c076ad8: /* original e640, guest PC 0x0c076ad8 */
if(!s->budget--) { s->failed_pc=0x0c076ad8u; return 0; }
r[6]=0x00000040u;
goto P_0c076ada;
P_0c076ada: /* original d217, guest PC 0x0c076ada */
if(!s->budget--) { s->failed_pc=0x0c076adau; return 0; }
r[2]=read(ram,0x0c076b38u,4);
goto P_0c076adc;
P_0c076adc: /* original 420b, guest PC 0x0c076adc */
if(!s->budget--) { s->failed_pc=0x0c076adcu; return 0; }
target=r[2];
r[16]=code_base|0x0c076ae0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c076ae0u) { target=s->pc; goto dispatch; }
goto P_0c076ae0;
P_0c076ade: /* original 0009, guest PC 0x0c076ade */
if(!s->budget--) { s->failed_pc=0x0c076adeu; return 0; }
goto P_0c076ae0;
P_0c076ae0: /* original 4f26, guest PC 0x0c076ae0 */
if(!s->budget--) { s->failed_pc=0x0c076ae0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c076ae2;
P_0c076ae2: /* original 000b, guest PC 0x0c076ae2 */
if(!s->budget--) { s->failed_pc=0x0c076ae2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c076ae4: /* original 6ef6, guest PC 0x0c076ae4 */
if(!s->budget--) { s->failed_pc=0x0c076ae4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c076ae6;
P_0c076ae6: /* original 2fe6, guest PC 0x0c076ae6 */
if(!s->budget--) { s->failed_pc=0x0c076ae6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c076ae8;
P_0c076ae8: /* original de0f, guest PC 0x0c076ae8 */
if(!s->budget--) { s->failed_pc=0x0c076ae8u; return 0; }
r[14]=read(ram,0x0c076b28u,4);
goto P_0c076aea;
P_0c076aea: /* original 9416, guest PC 0x0c076aea */
if(!s->budget--) { s->failed_pc=0x0c076aeau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076b1au,2);
goto P_0c076aec;
P_0c076aec: /* original 4f22, guest PC 0x0c076aec */
if(!s->budget--) { s->failed_pc=0x0c076aecu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c076aee;
P_0c076aee: /* original 34ec, guest PC 0x0c076aee */
if(!s->budget--) { s->failed_pc=0x0c076aeeu; return 0; }
r[4]+=r[14];
goto P_0c076af0;
P_0c076af0: /* original d50e, guest PC 0x0c076af0 */
if(!s->budget--) { s->failed_pc=0x0c076af0u; return 0; }
r[5]=read(ram,0x0c076b2cu,4);
goto P_0c076af2;
P_0c076af2: /* original 534f, guest PC 0x0c076af2 */
if(!s->budget--) { s->failed_pc=0x0c076af2u; return 0; }
r[3]=read(ram,r[4]+60,4);
goto P_0c076af4;
P_0c076af4: /* original 7ffc, guest PC 0x0c076af4 */
if(!s->budget--) { s->failed_pc=0x0c076af4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c076af6;
P_0c076af6: /* original 2f32, guest PC 0x0c076af6 */
if(!s->budget--) { s->failed_pc=0x0c076af6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c076af8;
P_0c076af8: /* original d30e, guest PC 0x0c076af8 */
if(!s->budget--) { s->failed_pc=0x0c076af8u; return 0; }
r[3]=read(ram,0x0c076b34u,4);
goto P_0c076afa;
P_0c076afa: /* original 430b, guest PC 0x0c076afa */
if(!s->budget--) { s->failed_pc=0x0c076afau; return 0; }
target=r[3];
r[16]=code_base|0x0c076afeu;
r[6]=0x00000040u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c076afeu) { target=s->pc; goto dispatch; }
goto P_0c076afe;
P_0c076afc: /* original e640, guest PC 0x0c076afc */
if(!s->budget--) { s->failed_pc=0x0c076afcu; return 0; }
r[6]=0x00000040u;
goto P_0c076afe;
P_0c076afe: /* original 900c, guest PC 0x0c076afe */
if(!s->budget--) { s->failed_pc=0x0c076afeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076b1au,2);
goto P_0c076b00;
P_0c076b00: /* original 02ec, guest PC 0x0c076b00 */
if(!s->budget--) { s->failed_pc=0x0c076b00u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c076b02;
P_0c076b02: /* original 7040, guest PC 0x0c076b02 */
if(!s->budget--) { s->failed_pc=0x0c076b02u; return 0; }
r[0]+=0x00000040u;
goto P_0c076b04;
P_0c076b04: /* original 03ec, guest PC 0x0c076b04 */
if(!s->budget--) { s->failed_pc=0x0c076b04u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c076b06;
P_0c076b06: /* original 3230, guest PC 0x0c076b06 */
if(!s->budget--) { s->failed_pc=0x0c076b06u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c076b08;
P_0c076b08: /* original 8b03, guest PC 0x0c076b08 */
if(!s->budget--) { s->failed_pc=0x0c076b08u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076b12; }
goto P_0c076b0a;
P_0c076b0a: /* original 9406, guest PC 0x0c076b0a */
if(!s->budget--) { s->failed_pc=0x0c076b0au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076b1au,2);
goto P_0c076b0c;
P_0c076b0c: /* original 63f2, guest PC 0x0c076b0c */
if(!s->budget--) { s->failed_pc=0x0c076b0cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c076b0e;
P_0c076b0e: /* original 34ec, guest PC 0x0c076b0e */
if(!s->budget--) { s->failed_pc=0x0c076b0eu; return 0; }
r[4]+=r[14];
goto P_0c076b10;
P_0c076b10: /* original 143f, guest PC 0x0c076b10 */
if(!s->budget--) { s->failed_pc=0x0c076b10u; return 0; }
write(ram,r[4]+60,r[3],4);
goto P_0c076b12;
P_0c076b12: /* original 7f04, guest PC 0x0c076b12 */
if(!s->budget--) { s->failed_pc=0x0c076b12u; return 0; }
r[15]+=0x00000004u;
goto P_0c076b14;
P_0c076b14: /* original 4f26, guest PC 0x0c076b14 */
if(!s->budget--) { s->failed_pc=0x0c076b14u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c076b16;
P_0c076b16: /* original 000b, guest PC 0x0c076b16 */
if(!s->budget--) { s->failed_pc=0x0c076b16u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c076b18: /* original 6ef6, guest PC 0x0c076b18 */
if(!s->budget--) { s->failed_pc=0x0c076b18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c076b1au,s,ram);
P_0c07f1ba: /* original 4f22, guest PC 0x0c07f1ba */
if(!s->budget--) { s->failed_pc=0x0c07f1bau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07f1bc;
P_0c07f1bc: /* original dc13, guest PC 0x0c07f1bc */
if(!s->budget--) { s->failed_pc=0x0c07f1bcu; return 0; }
r[12]=read(ram,0x0c07f20cu,4);
goto P_0c07f1be;
P_0c07f1be: /* original 7ff8, guest PC 0x0c07f1be */
if(!s->budget--) { s->failed_pc=0x0c07f1beu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c07f1c0;
P_0c07f1c0: /* original 1f41, guest PC 0x0c07f1c0 */
if(!s->budget--) { s->failed_pc=0x0c07f1c0u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c07f1c2;
P_0c07f1c2: /* original d31a, guest PC 0x0c07f1c2 */
if(!s->budget--) { s->failed_pc=0x0c07f1c2u; return 0; }
r[3]=read(ram,0x0c07f22cu,4);
goto P_0c07f1c4;
P_0c07f1c4: /* original 2f32, guest PC 0x0c07f1c4 */
if(!s->budget--) { s->failed_pc=0x0c07f1c4u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07f1c6;
P_0c07f1c6: /* original d410, guest PC 0x0c07f1c6 */
if(!s->budget--) { s->failed_pc=0x0c07f1c6u; return 0; }
r[4]=read(ram,0x0c07f208u,4);
goto P_0c07f1c8;
P_0c07f1c8: /* original 9618, guest PC 0x0c07f1c8 */
if(!s->budget--) { s->failed_pc=0x0c07f1c8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f1fcu,2);
goto P_0c07f1ca;
P_0c07f1ca: /* original d219, guest PC 0x0c07f1ca */
if(!s->budget--) { s->failed_pc=0x0c07f1cau; return 0; }
r[2]=read(ram,0x0c07f230u,4);
goto P_0c07f1cc;
P_0c07f1cc: /* original 6e43, guest PC 0x0c07f1cc */
if(!s->budget--) { s->failed_pc=0x0c07f1ccu; return 0; }
r[14]=r[4];
goto P_0c07f1ce;
P_0c07f1ce: /* original 364c, guest PC 0x0c07f1ce */
if(!s->budget--) { s->failed_pc=0x0c07f1ceu; return 0; }
r[6]+=r[4];
goto P_0c07f1d0;
P_0c07f1d0: /* original 6b22, guest PC 0x0c07f1d0 */
if(!s->budget--) { s->failed_pc=0x0c07f1d0u; return 0; }
tmp=read(ram,r[2],4);
r[11]=tmp;
goto P_0c07f1d2;
P_0c07f1d2: /* original 81ea, guest PC 0x0c07f1d2 */
if(!s->budget--) { s->failed_pc=0x0c07f1d2u; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c07f1d4;
P_0c07f1d4: /* original 81eb, guest PC 0x0c07f1d4 */
if(!s->budget--) { s->failed_pc=0x0c07f1d4u; return 0; }
write(ram,r[14]+22,r[0],2);
goto P_0c07f1d6;
P_0c07f1d6: /* original 9414, guest PC 0x0c07f1d6 */
if(!s->budget--) { s->failed_pc=0x0c07f1d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f202u,2);
goto P_0c07f1d8;
P_0c07f1d8: /* original d30f, guest PC 0x0c07f1d8 */
if(!s->budget--) { s->failed_pc=0x0c07f1d8u; return 0; }
r[3]=read(ram,0x0c07f218u,4);
goto P_0c07f1da;
P_0c07f1da: /* original 430b, guest PC 0x0c07f1da */
if(!s->budget--) { s->failed_pc=0x0c07f1dau; return 0; }
target=r[3];
r[16]=code_base|0x0c07f1deu;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f1deu) { target=s->pc; goto dispatch; }
goto P_0c07f1de;
P_0c07f1dc: /* original 65e3, guest PC 0x0c07f1dc */
if(!s->budget--) { s->failed_pc=0x0c07f1dcu; return 0; }
r[5]=r[14];
goto P_0c07f1de;
P_0c07f1de: /* original d20d, guest PC 0x0c07f1de */
if(!s->budget--) { s->failed_pc=0x0c07f1deu; return 0; }
r[2]=read(ram,0x0c07f214u,4);
goto P_0c07f1e0;
P_0c07f1e0: /* original 420b, guest PC 0x0c07f1e0 */
if(!s->budget--) { s->failed_pc=0x0c07f1e0u; return 0; }
target=r[2];
r[16]=code_base|0x0c07f1e4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f1e4u) { target=s->pc; goto dispatch; }
goto P_0c07f1e4;
P_0c07f1e2: /* original 64e3, guest PC 0x0c07f1e2 */
if(!s->budget--) { s->failed_pc=0x0c07f1e2u; return 0; }
r[4]=r[14];
goto P_0c07f1e4;
P_0c07f1e4: /* original d313, guest PC 0x0c07f1e4 */
if(!s->budget--) { s->failed_pc=0x0c07f1e4u; return 0; }
r[3]=read(ram,0x0c07f234u,4);
goto P_0c07f1e6;
P_0c07f1e6: /* original 64f2, guest PC 0x0c07f1e6 */
if(!s->budget--) { s->failed_pc=0x0c07f1e6u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07f1e8;
P_0c07f1e8: /* original 430b, guest PC 0x0c07f1e8 */
if(!s->budget--) { s->failed_pc=0x0c07f1e8u; return 0; }
target=r[3];
r[16]=code_base|0x0c07f1ecu;
r[4]+=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f1ecu) { target=s->pc; goto dispatch; }
goto P_0c07f1ec;
P_0c07f1ea: /* original 7412, guest PC 0x0c07f1ea */
if(!s->budget--) { s->failed_pc=0x0c07f1eau; return 0; }
r[4]+=0x00000012u;
goto P_0c07f1ec;
P_0c07f1ec: /* original 650c, guest PC 0x0c07f1ec */
if(!s->budget--) { s->failed_pc=0x0c07f1ecu; return 0; }
r[5]=r[0]&255u;
goto P_0c07f1ee;
P_0c07f1ee: /* original 2558, guest PC 0x0c07f1ee */
if(!s->budget--) { s->failed_pc=0x0c07f1eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c07f1f0;
P_0c07f1f0: /* original 8d22, guest PC 0x0c07f1f0 */
if(!s->budget--) { s->failed_pc=0x0c07f1f0u; return 0; }
cond=r[17]&1u;
r[4]=0x00000018u;
if(cond) { goto P_0c07f238; }
goto P_0c07f1f4;
P_0c07f1f2: /* original e418, guest PC 0x0c07f1f2 */
if(!s->budget--) { s->failed_pc=0x0c07f1f2u; return 0; }
r[4]=0x00000018u;
goto P_0c07f1f4;
P_0c07f1f4: /* original 9506, guest PC 0x0c07f1f4 */
if(!s->budget--) { s->failed_pc=0x0c07f1f4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f204u,2);
goto P_0c07f1f6;
P_0c07f1f6: /* original a021, guest PC 0x0c07f1f6 */
if(!s->budget--) { s->failed_pc=0x0c07f1f6u; return 0; }
r[10]=0x0000001fu;
goto P_0c07f23c;
P_0c07f1f8: /* original ea1f, guest PC 0x0c07f1f8 */
if(!s->budget--) { s->failed_pc=0x0c07f1f8u; return 0; }
r[10]=0x0000001fu;
return vf3_matrix_family(0x0c07f1fau,s,ram);
P_0c07f238: /* original 95ad, guest PC 0x0c07f238 */
if(!s->budget--) { s->failed_pc=0x0c07f238u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f396u,2);
goto P_0c07f23a;
P_0c07f23a: /* original ea22, guest PC 0x0c07f23a */
if(!s->budget--) { s->failed_pc=0x0c07f23au; return 0; }
r[10]=0x00000022u;
goto P_0c07f23c;
P_0c07f23c: /* original e307, guest PC 0x0c07f23c */
if(!s->budget--) { s->failed_pc=0x0c07f23cu; return 0; }
r[3]=0x00000007u;
goto P_0c07f23e;
P_0c07f23e: /* original 66e3, guest PC 0x0c07f23e */
if(!s->budget--) { s->failed_pc=0x0c07f23eu; return 0; }
r[6]=r[14];
goto P_0c07f240;
P_0c07f240: /* original 3ab8, guest PC 0x0c07f240 */
if(!s->budget--) { s->failed_pc=0x0c07f240u; return 0; }
r[10]-=r[11];
goto P_0c07f242;
P_0c07f242: /* original 2fd6, guest PC 0x0c07f242 */
if(!s->budget--) { s->failed_pc=0x0c07f242u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f244;
P_0c07f244: /* original 4a3c, guest PC 0x0c07f244 */
if(!s->budget--) { s->failed_pc=0x0c07f244u; return 0; }
r[10]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[10]>>((-r[3])&31u)):((int32_t)r[10]<0?0xffffffffu:0)):r[10]<<(r[3]&31u);
goto P_0c07f246;
P_0c07f246: /* original e700, guest PC 0x0c07f246 */
if(!s->budget--) { s->failed_pc=0x0c07f246u; return 0; }
r[7]=0x00000000u;
goto P_0c07f248;
P_0c07f248: /* original 2a4b, guest PC 0x0c07f248 */
if(!s->budget--) { s->failed_pc=0x0c07f248u; return 0; }
r[10]|=r[4];
goto P_0c07f24a;
P_0c07f24a: /* original 4c0b, guest PC 0x0c07f24a */
if(!s->budget--) { s->failed_pc=0x0c07f24au; return 0; }
target=r[12];
r[16]=code_base|0x0c07f24eu;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f24eu) { target=s->pc; goto dispatch; }
goto P_0c07f24e;
P_0c07f24c: /* original 64a3, guest PC 0x0c07f24c */
if(!s->budget--) { s->failed_pc=0x0c07f24cu; return 0; }
r[4]=r[10];
goto P_0c07f24e;
P_0c07f24e: /* original ea28, guest PC 0x0c07f24e */
if(!s->budget--) { s->failed_pc=0x0c07f24eu; return 0; }
r[10]=0x00000028u;
goto P_0c07f250;
P_0c07f250: /* original 66e3, guest PC 0x0c07f250 */
if(!s->budget--) { s->failed_pc=0x0c07f250u; return 0; }
r[6]=r[14];
goto P_0c07f252;
P_0c07f252: /* original e307, guest PC 0x0c07f252 */
if(!s->budget--) { s->failed_pc=0x0c07f252u; return 0; }
r[3]=0x00000007u;
goto P_0c07f254;
P_0c07f254: /* original 3ab8, guest PC 0x0c07f254 */
if(!s->budget--) { s->failed_pc=0x0c07f254u; return 0; }
r[10]-=r[11];
goto P_0c07f256;
P_0c07f256: /* original e20e, guest PC 0x0c07f256 */
if(!s->budget--) { s->failed_pc=0x0c07f256u; return 0; }
r[2]=0x0000000eu;
goto P_0c07f258;
P_0c07f258: /* original 4a3c, guest PC 0x0c07f258 */
if(!s->budget--) { s->failed_pc=0x0c07f258u; return 0; }
r[10]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[10]>>((-r[3])&31u)):((int32_t)r[10]<0?0xffffffffu:0)):r[10]<<(r[3]&31u);
goto P_0c07f25a;
P_0c07f25a: /* original 22ab, guest PC 0x0c07f25a */
if(!s->budget--) { s->failed_pc=0x0c07f25au; return 0; }
r[2]|=r[10];
goto P_0c07f25c;
P_0c07f25c: /* original 1f21, guest PC 0x0c07f25c */
if(!s->budget--) { s->failed_pc=0x0c07f25cu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c07f25e;
P_0c07f25e: /* original e700, guest PC 0x0c07f25e */
if(!s->budget--) { s->failed_pc=0x0c07f25eu; return 0; }
r[7]=0x00000000u;
goto P_0c07f260;
P_0c07f260: /* original 2fd6, guest PC 0x0c07f260 */
if(!s->budget--) { s->failed_pc=0x0c07f260u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f262;
P_0c07f262: /* original 9599, guest PC 0x0c07f262 */
if(!s->budget--) { s->failed_pc=0x0c07f262u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f398u,2);
goto P_0c07f264;
P_0c07f264: /* original 4c0b, guest PC 0x0c07f264 */
if(!s->budget--) { s->failed_pc=0x0c07f264u; return 0; }
target=r[12];
r[16]=code_base|0x0c07f268u;
r[4]=r[2];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f268u) { target=s->pc; goto dispatch; }
goto P_0c07f268;
P_0c07f266: /* original 6423, guest PC 0x0c07f266 */
if(!s->budget--) { s->failed_pc=0x0c07f266u; return 0; }
r[4]=r[2];
goto P_0c07f268;
P_0c07f268: /* original e31c, guest PC 0x0c07f268 */
if(!s->budget--) { s->failed_pc=0x0c07f268u; return 0; }
r[3]=0x0000001cu;
goto P_0c07f26a;
P_0c07f26a: /* original 66e3, guest PC 0x0c07f26a */
if(!s->budget--) { s->failed_pc=0x0c07f26au; return 0; }
r[6]=r[14];
goto P_0c07f26c;
P_0c07f26c: /* original 23ab, guest PC 0x0c07f26c */
if(!s->budget--) { s->failed_pc=0x0c07f26cu; return 0; }
r[3]|=r[10];
goto P_0c07f26e;
P_0c07f26e: /* original 1f32, guest PC 0x0c07f26e */
if(!s->budget--) { s->failed_pc=0x0c07f26eu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07f270;
P_0c07f270: /* original e700, guest PC 0x0c07f270 */
if(!s->budget--) { s->failed_pc=0x0c07f270u; return 0; }
r[7]=0x00000000u;
goto P_0c07f272;
P_0c07f272: /* original 2fd6, guest PC 0x0c07f272 */
if(!s->budget--) { s->failed_pc=0x0c07f272u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f274;
P_0c07f274: /* original 9591, guest PC 0x0c07f274 */
if(!s->budget--) { s->failed_pc=0x0c07f274u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f39au,2);
goto P_0c07f276;
P_0c07f276: /* original 4c0b, guest PC 0x0c07f276 */
if(!s->budget--) { s->failed_pc=0x0c07f276u; return 0; }
target=r[12];
r[16]=code_base|0x0c07f27au;
r[4]=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f27au) { target=s->pc; goto dispatch; }
goto P_0c07f27a;
P_0c07f278: /* original 6433, guest PC 0x0c07f278 */
if(!s->budget--) { s->failed_pc=0x0c07f278u; return 0; }
r[4]=r[3];
goto P_0c07f27a;
P_0c07f27a: /* original e236, guest PC 0x0c07f27a */
if(!s->budget--) { s->failed_pc=0x0c07f27au; return 0; }
r[2]=0x00000036u;
goto P_0c07f27c;
P_0c07f27c: /* original 66e3, guest PC 0x0c07f27c */
if(!s->budget--) { s->failed_pc=0x0c07f27cu; return 0; }
r[6]=r[14];
goto P_0c07f27e;
P_0c07f27e: /* original 22ab, guest PC 0x0c07f27e */
if(!s->budget--) { s->failed_pc=0x0c07f27eu; return 0; }
r[2]|=r[10];
goto P_0c07f280;
P_0c07f280: /* original 1f23, guest PC 0x0c07f280 */
if(!s->budget--) { s->failed_pc=0x0c07f280u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c07f282;
P_0c07f282: /* original e700, guest PC 0x0c07f282 */
if(!s->budget--) { s->failed_pc=0x0c07f282u; return 0; }
r[7]=0x00000000u;
goto P_0c07f284;
P_0c07f284: /* original 2fd6, guest PC 0x0c07f284 */
if(!s->budget--) { s->failed_pc=0x0c07f284u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f286;
P_0c07f286: /* original 9589, guest PC 0x0c07f286 */
if(!s->budget--) { s->failed_pc=0x0c07f286u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f39cu,2);
goto P_0c07f288;
P_0c07f288: /* original 4c0b, guest PC 0x0c07f288 */
if(!s->budget--) { s->failed_pc=0x0c07f288u; return 0; }
target=r[12];
r[16]=code_base|0x0c07f28cu;
r[4]=r[2];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f28cu) { target=s->pc; goto dispatch; }
goto P_0c07f28c;
P_0c07f28a: /* original 6423, guest PC 0x0c07f28a */
if(!s->budget--) { s->failed_pc=0x0c07f28au; return 0; }
r[4]=r[2];
goto P_0c07f28c;
P_0c07f28c: /* original eb50, guest PC 0x0c07f28c */
if(!s->budget--) { s->failed_pc=0x0c07f28cu; return 0; }
r[11]=0x00000050u;
goto P_0c07f28e;
P_0c07f28e: /* original 66e3, guest PC 0x0c07f28e */
if(!s->budget--) { s->failed_pc=0x0c07f28eu; return 0; }
r[6]=r[14];
goto P_0c07f290;
P_0c07f290: /* original e700, guest PC 0x0c07f290 */
if(!s->budget--) { s->failed_pc=0x0c07f290u; return 0; }
r[7]=0x00000000u;
goto P_0c07f292;
P_0c07f292: /* original 2fd6, guest PC 0x0c07f292 */
if(!s->budget--) { s->failed_pc=0x0c07f292u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f294;
P_0c07f294: /* original 9583, guest PC 0x0c07f294 */
if(!s->budget--) { s->failed_pc=0x0c07f294u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f39eu,2);
goto P_0c07f296;
P_0c07f296: /* original 2bab, guest PC 0x0c07f296 */
if(!s->budget--) { s->failed_pc=0x0c07f296u; return 0; }
r[11]|=r[10];
goto P_0c07f298;
P_0c07f298: /* original 4c0b, guest PC 0x0c07f298 */
if(!s->budget--) { s->failed_pc=0x0c07f298u; return 0; }
target=r[12];
r[16]=code_base|0x0c07f29cu;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f29cu) { target=s->pc; goto dispatch; }
goto P_0c07f29c;
P_0c07f29a: /* original 64b3, guest PC 0x0c07f29a */
if(!s->budget--) { s->failed_pc=0x0c07f29au; return 0; }
r[4]=r[11];
goto P_0c07f29c;
P_0c07f29c: /* original d345, guest PC 0x0c07f29c */
if(!s->budget--) { s->failed_pc=0x0c07f29cu; return 0; }
r[3]=read(ram,0x0c07f3b4u,4);
goto P_0c07f29e;
P_0c07f29e: /* original 957f, guest PC 0x0c07f29e */
if(!s->budget--) { s->failed_pc=0x0c07f29eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f3a0u,2);
goto P_0c07f2a0;
P_0c07f2a0: /* original 430b, guest PC 0x0c07f2a0 */
if(!s->budget--) { s->failed_pc=0x0c07f2a0u; return 0; }
target=r[3];
r[16]=code_base|0x0c07f2a4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f2a4u) { target=s->pc; goto dispatch; }
goto P_0c07f2a4;
P_0c07f2a2: /* original 64e3, guest PC 0x0c07f2a2 */
if(!s->budget--) { s->failed_pc=0x0c07f2a2u; return 0; }
r[4]=r[14];
goto P_0c07f2a4;
P_0c07f2a4: /* original 65b3, guest PC 0x0c07f2a4 */
if(!s->budget--) { s->failed_pc=0x0c07f2a4u; return 0; }
r[5]=r[11];
goto P_0c07f2a6;
P_0c07f2a6: /* original d244, guest PC 0x0c07f2a6 */
if(!s->budget--) { s->failed_pc=0x0c07f2a6u; return 0; }
r[2]=read(ram,0x0c07f3b8u,4);
goto P_0c07f2a8;
P_0c07f2a8: /* original 6320, guest PC 0x0c07f2a8 */
if(!s->budget--) { s->failed_pc=0x0c07f2a8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c07f2aa;
P_0c07f2aa: /* original 7301, guest PC 0x0c07f2aa */
if(!s->budget--) { s->failed_pc=0x0c07f2aau; return 0; }
r[3]+=0x00000001u;
goto P_0c07f2ac;
P_0c07f2ac: /* original 2230, guest PC 0x0c07f2ac */
if(!s->budget--) { s->failed_pc=0x0c07f2acu; return 0; }
write(ram,r[2],r[3],1);
goto P_0c07f2ae;
P_0c07f2ae: /* original 54f6, guest PC 0x0c07f2ae */
if(!s->budget--) { s->failed_pc=0x0c07f2aeu; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c07f2b0;
P_0c07f2b0: /* original 7f1c, guest PC 0x0c07f2b0 */
if(!s->budget--) { s->failed_pc=0x0c07f2b0u; return 0; }
r[15]+=0x0000001cu;
goto P_0c07f2b2;
P_0c07f2b2: /* original 4f26, guest PC 0x0c07f2b2 */
if(!s->budget--) { s->failed_pc=0x0c07f2b2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07f2b4;
P_0c07f2b4: /* original 6af6, guest PC 0x0c07f2b4 */
if(!s->budget--) { s->failed_pc=0x0c07f2b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07f2b6;
P_0c07f2b6: /* original 6bf6, guest PC 0x0c07f2b6 */
if(!s->budget--) { s->failed_pc=0x0c07f2b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07f2b8;
P_0c07f2b8: /* original 6cf6, guest PC 0x0c07f2b8 */
if(!s->budget--) { s->failed_pc=0x0c07f2b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07f2ba;
P_0c07f2ba: /* original 6df6, guest PC 0x0c07f2ba */
if(!s->budget--) { s->failed_pc=0x0c07f2bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07f2bc;
P_0c07f2bc: /* original a000, guest PC 0x0c07f2bc */
if(!s->budget--) { s->failed_pc=0x0c07f2bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07f2c0;
P_0c07f2be: /* original 6ef6, guest PC 0x0c07f2be */
if(!s->budget--) { s->failed_pc=0x0c07f2beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07f2c0;
P_0c07f2c0: /* original 2fe6, guest PC 0x0c07f2c0 */
if(!s->budget--) { s->failed_pc=0x0c07f2c0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f2c2;
P_0c07f2c2: /* original 2fd6, guest PC 0x0c07f2c2 */
if(!s->budget--) { s->failed_pc=0x0c07f2c2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f2c4;
P_0c07f2c4: /* original 4f22, guest PC 0x0c07f2c4 */
if(!s->budget--) { s->failed_pc=0x0c07f2c4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07f2c6;
P_0c07f2c6: /* original 7ff8, guest PC 0x0c07f2c6 */
if(!s->budget--) { s->failed_pc=0x0c07f2c6u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c07f2c8;
P_0c07f2c8: /* original 1f41, guest PC 0x0c07f2c8 */
if(!s->budget--) { s->failed_pc=0x0c07f2c8u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c07f2ca;
P_0c07f2ca: /* original dd3a, guest PC 0x0c07f2ca */
if(!s->budget--) { s->failed_pc=0x0c07f2cau; return 0; }
r[13]=read(ram,0x0c07f3b4u,4);
goto P_0c07f2cc;
P_0c07f2cc: /* original 9569, guest PC 0x0c07f2cc */
if(!s->budget--) { s->failed_pc=0x0c07f2ccu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f3a2u,2);
goto P_0c07f2ce;
P_0c07f2ce: /* original de3b, guest PC 0x0c07f2ce */
if(!s->budget--) { s->failed_pc=0x0c07f2ceu; return 0; }
r[14]=read(ram,0x0c07f3bcu,4);
goto P_0c07f2d0;
P_0c07f2d0: /* original 4d0b, guest PC 0x0c07f2d0 */
if(!s->budget--) { s->failed_pc=0x0c07f2d0u; return 0; }
target=r[13];
r[16]=code_base|0x0c07f2d4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f2d4u) { target=s->pc; goto dispatch; }
goto P_0c07f2d4;
P_0c07f2d2: /* original 64e3, guest PC 0x0c07f2d2 */
if(!s->budget--) { s->failed_pc=0x0c07f2d2u; return 0; }
r[4]=r[14];
goto P_0c07f2d4;
P_0c07f2d4: /* original 9366, guest PC 0x0c07f2d4 */
if(!s->budget--) { s->failed_pc=0x0c07f2d4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f3a4u,2);
goto P_0c07f2d6;
P_0c07f2d6: /* original 6433, guest PC 0x0c07f2d6 */
if(!s->budget--) { s->failed_pc=0x0c07f2d6u; return 0; }
r[4]=r[3];
goto P_0c07f2d8;
P_0c07f2d8: /* original 2f32, guest PC 0x0c07f2d8 */
if(!s->budget--) { s->failed_pc=0x0c07f2d8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07f2da;
P_0c07f2da: /* original d33a, guest PC 0x0c07f2da */
if(!s->budget--) { s->failed_pc=0x0c07f2dau; return 0; }
r[3]=read(ram,0x0c07f3c4u,4);
goto P_0c07f2dc;
P_0c07f2dc: /* original d538, guest PC 0x0c07f2dc */
if(!s->budget--) { s->failed_pc=0x0c07f2dcu; return 0; }
r[5]=read(ram,0x0c07f3c0u,4);
goto P_0c07f2de;
P_0c07f2de: /* original 430b, guest PC 0x0c07f2de */
if(!s->budget--) { s->failed_pc=0x0c07f2deu; return 0; }
target=r[3];
r[16]=code_base|0x0c07f2e2u;
r[6]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f2e2u) { target=s->pc; goto dispatch; }
goto P_0c07f2e2;
P_0c07f2e0: /* original e601, guest PC 0x0c07f2e0 */
if(!s->budget--) { s->failed_pc=0x0c07f2e0u; return 0; }
r[6]=0x00000001u;
goto P_0c07f2e2;
P_0c07f2e2: /* original d339, guest PC 0x0c07f2e2 */
if(!s->budget--) { s->failed_pc=0x0c07f2e2u; return 0; }
r[3]=read(ram,0x0c07f3c8u,4);
goto P_0c07f2e4;
P_0c07f2e4: /* original 430b, guest PC 0x0c07f2e4 */
if(!s->budget--) { s->failed_pc=0x0c07f2e4u; return 0; }
target=r[3];
r[16]=code_base|0x0c07f2e8u;
write(ram,r[15],r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f2e8u) { target=s->pc; goto dispatch; }
goto P_0c07f2e8;
P_0c07f2e6: /* original 2f02, guest PC 0x0c07f2e6 */
if(!s->budget--) { s->failed_pc=0x0c07f2e6u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c07f2e8;
P_0c07f2e8: /* original 955b, guest PC 0x0c07f2e8 */
if(!s->budget--) { s->failed_pc=0x0c07f2e8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f3a2u,2);
goto P_0c07f2ea;
P_0c07f2ea: /* original 4d0b, guest PC 0x0c07f2ea */
if(!s->budget--) { s->failed_pc=0x0c07f2eau; return 0; }
target=r[13];
r[16]=code_base|0x0c07f2eeu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f2eeu) { target=s->pc; goto dispatch; }
goto P_0c07f2ee;
P_0c07f2ec: /* original 64e3, guest PC 0x0c07f2ec */
if(!s->budget--) { s->failed_pc=0x0c07f2ecu; return 0; }
r[4]=r[14];
goto P_0c07f2ee;
P_0c07f2ee: /* original d237, guest PC 0x0c07f2ee */
if(!s->budget--) { s->failed_pc=0x0c07f2eeu; return 0; }
r[2]=read(ram,0x0c07f3ccu,4);
goto P_0c07f2f0;
P_0c07f2f0: /* original 420b, guest PC 0x0c07f2f0 */
if(!s->budget--) { s->failed_pc=0x0c07f2f0u; return 0; }
target=r[2];
r[16]=code_base|0x0c07f2f4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f2f4u) { target=s->pc; goto dispatch; }
goto P_0c07f2f4;
P_0c07f2f2: /* original 0009, guest PC 0x0c07f2f2 */
if(!s->budget--) { s->failed_pc=0x0c07f2f2u; return 0; }
goto P_0c07f2f4;
P_0c07f2f4: /* original 9554, guest PC 0x0c07f2f4 */
if(!s->budget--) { s->failed_pc=0x0c07f2f4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f3a0u,2);
goto P_0c07f2f6;
P_0c07f2f6: /* original 4d0b, guest PC 0x0c07f2f6 */
if(!s->budget--) { s->failed_pc=0x0c07f2f6u; return 0; }
target=r[13];
r[16]=code_base|0x0c07f2fau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f2fau) { target=s->pc; goto dispatch; }
goto P_0c07f2fa;
P_0c07f2f8: /* original 64e3, guest PC 0x0c07f2f8 */
if(!s->budget--) { s->failed_pc=0x0c07f2f8u; return 0; }
r[4]=r[14];
goto P_0c07f2fa;
P_0c07f2fa: /* original 54f1, guest PC 0x0c07f2fa */
if(!s->budget--) { s->failed_pc=0x0c07f2fau; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07f2fc;
P_0c07f2fc: /* original 65f2, guest PC 0x0c07f2fc */
if(!s->budget--) { s->failed_pc=0x0c07f2fcu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c07f2fe;
P_0c07f2fe: /* original 7f08, guest PC 0x0c07f2fe */
if(!s->budget--) { s->failed_pc=0x0c07f2feu; return 0; }
r[15]+=0x00000008u;
goto P_0c07f300;
P_0c07f300: /* original 4f26, guest PC 0x0c07f300 */
if(!s->budget--) { s->failed_pc=0x0c07f300u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07f302;
P_0c07f302: /* original d333, guest PC 0x0c07f302 */
if(!s->budget--) { s->failed_pc=0x0c07f302u; return 0; }
r[3]=read(ram,0x0c07f3d0u,4);
goto P_0c07f304;
P_0c07f304: /* original 6df6, guest PC 0x0c07f304 */
if(!s->budget--) { s->failed_pc=0x0c07f304u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07f306;
P_0c07f306: /* original 432b, guest PC 0x0c07f306 */
if(!s->budget--) { s->failed_pc=0x0c07f306u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c07f308: /* original 6ef6, guest PC 0x0c07f308 */
if(!s->budget--) { s->failed_pc=0x0c07f308u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07f30au,s,ram);
P_0c081fbe: /* original 4f22, guest PC 0x0c081fbe */
if(!s->budget--) { s->failed_pc=0x0c081fbeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c081fc0;
P_0c081fc0: /* original de49, guest PC 0x0c081fc0 */
if(!s->budget--) { s->failed_pc=0x0c081fc0u; return 0; }
r[14]=read(ram,0x0c0820e8u,4);
goto P_0c081fc2;
P_0c081fc2: /* original e40a, guest PC 0x0c081fc2 */
if(!s->budget--) { s->failed_pc=0x0c081fc2u; return 0; }
r[4]=0x0000000au;
goto P_0c081fc4;
P_0c081fc4: /* original d349, guest PC 0x0c081fc4 */
if(!s->budget--) { s->failed_pc=0x0c081fc4u; return 0; }
r[3]=read(ram,0x0c0820ecu,4);
goto P_0c081fc6;
P_0c081fc6: /* original 7ff8, guest PC 0x0c081fc6 */
if(!s->budget--) { s->failed_pc=0x0c081fc6u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c081fc8;
P_0c081fc8: /* original 430b, guest PC 0x0c081fc8 */
if(!s->budget--) { s->failed_pc=0x0c081fc8u; return 0; }
target=r[3];
r[16]=code_base|0x0c081fccu;
r[0]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081fccu) { target=s->pc; goto dispatch; }
goto P_0c081fcc;
P_0c081fca: /* original 6043, guest PC 0x0c081fca */
if(!s->budget--) { s->failed_pc=0x0c081fcau; return 0; }
r[0]=r[4];
goto P_0c081fcc;
P_0c081fcc: /* original 1f01, guest PC 0x0c081fcc */
if(!s->budget--) { s->failed_pc=0x0c081fccu; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c081fce;
P_0c081fce: /* original 6043, guest PC 0x0c081fce */
if(!s->budget--) { s->failed_pc=0x0c081fceu; return 0; }
r[0]=r[4];
goto P_0c081fd0;
P_0c081fd0: /* original d347, guest PC 0x0c081fd0 */
if(!s->budget--) { s->failed_pc=0x0c081fd0u; return 0; }
r[3]=read(ram,0x0c0820f0u,4);
goto P_0c081fd2;
P_0c081fd2: /* original 430b, guest PC 0x0c081fd2 */
if(!s->budget--) { s->failed_pc=0x0c081fd2u; return 0; }
target=r[3];
r[16]=code_base|0x0c081fd6u;
r[1]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081fd6u) { target=s->pc; goto dispatch; }
goto P_0c081fd6;
P_0c081fd4: /* original 6163, guest PC 0x0c081fd4 */
if(!s->budget--) { s->failed_pc=0x0c081fd4u; return 0; }
r[1]=r[6];
goto P_0c081fd6;
P_0c081fd6: /* original d245, guest PC 0x0c081fd6 */
if(!s->budget--) { s->failed_pc=0x0c081fd6u; return 0; }
r[2]=read(ram,0x0c0820ecu,4);
goto P_0c081fd8;
P_0c081fd8: /* original 6103, guest PC 0x0c081fd8 */
if(!s->budget--) { s->failed_pc=0x0c081fd8u; return 0; }
r[1]=r[0];
goto P_0c081fda;
P_0c081fda: /* original 6603, guest PC 0x0c081fda */
if(!s->budget--) { s->failed_pc=0x0c081fdau; return 0; }
r[6]=r[0];
goto P_0c081fdc;
P_0c081fdc: /* original 420b, guest PC 0x0c081fdc */
if(!s->budget--) { s->failed_pc=0x0c081fdcu; return 0; }
target=r[2];
r[16]=code_base|0x0c081fe0u;
r[0]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081fe0u) { target=s->pc; goto dispatch; }
goto P_0c081fe0;
P_0c081fde: /* original 6043, guest PC 0x0c081fde */
if(!s->budget--) { s->failed_pc=0x0c081fdeu; return 0; }
r[0]=r[4];
goto P_0c081fe0;
P_0c081fe0: /* original 2f02, guest PC 0x0c081fe0 */
if(!s->budget--) { s->failed_pc=0x0c081fe0u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c081fe2;
P_0c081fe2: /* original 6043, guest PC 0x0c081fe2 */
if(!s->budget--) { s->failed_pc=0x0c081fe2u; return 0; }
r[0]=r[4];
goto P_0c081fe4;
P_0c081fe4: /* original d342, guest PC 0x0c081fe4 */
if(!s->budget--) { s->failed_pc=0x0c081fe4u; return 0; }
r[3]=read(ram,0x0c0820f0u,4);
goto P_0c081fe6;
P_0c081fe6: /* original 430b, guest PC 0x0c081fe6 */
if(!s->budget--) { s->failed_pc=0x0c081fe6u; return 0; }
target=r[3];
r[16]=code_base|0x0c081feau;
r[1]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081feau) { target=s->pc; goto dispatch; }
goto P_0c081fea;
P_0c081fe8: /* original 6163, guest PC 0x0c081fe8 */
if(!s->budget--) { s->failed_pc=0x0c081fe8u; return 0; }
r[1]=r[6];
goto P_0c081fea;
P_0c081fea: /* original d240, guest PC 0x0c081fea */
if(!s->budget--) { s->failed_pc=0x0c081feau; return 0; }
r[2]=read(ram,0x0c0820ecu,4);
goto P_0c081fec;
P_0c081fec: /* original 6103, guest PC 0x0c081fec */
if(!s->budget--) { s->failed_pc=0x0c081fecu; return 0; }
r[1]=r[0];
goto P_0c081fee;
P_0c081fee: /* original 6603, guest PC 0x0c081fee */
if(!s->budget--) { s->failed_pc=0x0c081feeu; return 0; }
r[6]=r[0];
goto P_0c081ff0;
P_0c081ff0: /* original 420b, guest PC 0x0c081ff0 */
if(!s->budget--) { s->failed_pc=0x0c081ff0u; return 0; }
target=r[2];
r[16]=code_base|0x0c081ff4u;
r[0]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081ff4u) { target=s->pc; goto dispatch; }
goto P_0c081ff4;
P_0c081ff2: /* original 6043, guest PC 0x0c081ff2 */
if(!s->budget--) { s->failed_pc=0x0c081ff2u; return 0; }
r[0]=r[4];
goto P_0c081ff4;
P_0c081ff4: /* original 9d71, guest PC 0x0c081ff4 */
if(!s->budget--) { s->failed_pc=0x0c081ff4u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0820dau,2);
goto P_0c081ff6;
P_0c081ff6: /* original 6903, guest PC 0x0c081ff6 */
if(!s->budget--) { s->failed_pc=0x0c081ff6u; return 0; }
r[9]=r[0];
goto P_0c081ff8;
P_0c081ff8: /* original da3e, guest PC 0x0c081ff8 */
if(!s->budget--) { s->failed_pc=0x0c081ff8u; return 0; }
r[10]=read(ram,0x0c0820f4u,4);
goto P_0c081ffa;
P_0c081ffa: /* original 6c53, guest PC 0x0c081ffa */
if(!s->budget--) { s->failed_pc=0x0c081ffau; return 0; }
r[12]=r[5];
goto P_0c081ffc;
P_0c081ffc: /* original 2998, guest PC 0x0c081ffc */
if(!s->budget--) { s->failed_pc=0x0c081ffcu; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c081ffe;
P_0c081ffe: /* original eb00, guest PC 0x0c081ffe */
if(!s->budget--) { s->failed_pc=0x0c081ffeu; return 0; }
r[11]=0x00000000u;
goto P_0c082000;
P_0c082000: /* original e307, guest PC 0x0c082000 */
if(!s->budget--) { s->failed_pc=0x0c082000u; return 0; }
r[3]=0x00000007u;
goto P_0c082002;
P_0c082002: /* original 8d0a, guest PC 0x0c082002 */
if(!s->budget--) { s->failed_pc=0x0c082002u; return 0; }
cond=r[17]&1u;
r[12]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[12]>>((-r[3])&31u)):((int32_t)r[12]<0?0xffffffffu:0)):r[12]<<(r[3]&31u);
if(cond) { goto P_0c08201a; }
goto P_0c082006;
P_0c082004: /* original 4c3c, guest PC 0x0c082004 */
if(!s->budget--) { s->failed_pc=0x0c082004u; return 0; }
r[12]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[12]>>((-r[3])&31u)):((int32_t)r[12]<0?0xffffffffu:0)):r[12]<<(r[3]&31u);
goto P_0c082006;
P_0c082006: /* original 6483, guest PC 0x0c082006 */
if(!s->budget--) { s->failed_pc=0x0c082006u; return 0; }
r[4]=r[8];
goto P_0c082008;
P_0c082008: /* original 4400, guest PC 0x0c082008 */
if(!s->budget--) { s->failed_pc=0x0c082008u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08200a;
P_0c08200a: /* original 66e3, guest PC 0x0c08200a */
if(!s->budget--) { s->failed_pc=0x0c08200au; return 0; }
r[6]=r[14];
goto P_0c08200c;
P_0c08200c: /* original 6593, guest PC 0x0c08200c */
if(!s->budget--) { s->failed_pc=0x0c08200cu; return 0; }
r[5]=r[9];
goto P_0c08200e;
P_0c08200e: /* original e700, guest PC 0x0c08200e */
if(!s->budget--) { s->failed_pc=0x0c08200eu; return 0; }
r[7]=0x00000000u;
goto P_0c082010;
P_0c082010: /* original 2fb6, guest PC 0x0c082010 */
if(!s->budget--) { s->failed_pc=0x0c082010u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082012;
P_0c082012: /* original 24cb, guest PC 0x0c082012 */
if(!s->budget--) { s->failed_pc=0x0c082012u; return 0; }
r[4]|=r[12];
goto P_0c082014;
P_0c082014: /* original 4a0b, guest PC 0x0c082014 */
if(!s->budget--) { s->failed_pc=0x0c082014u; return 0; }
target=r[10];
r[16]=code_base|0x0c082018u;
r[5]+=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c082018u) { target=s->pc; goto dispatch; }
goto P_0c082018;
P_0c082016: /* original 35dc, guest PC 0x0c082016 */
if(!s->budget--) { s->failed_pc=0x0c082016u; return 0; }
r[5]+=r[13];
goto P_0c082018;
P_0c082018: /* original 7f04, guest PC 0x0c082018 */
if(!s->budget--) { s->failed_pc=0x0c082018u; return 0; }
r[15]+=0x00000004u;
goto P_0c08201a;
P_0c08201a: /* original 6483, guest PC 0x0c08201a */
if(!s->budget--) { s->failed_pc=0x0c08201au; return 0; }
r[4]=r[8];
goto P_0c08201c;
P_0c08201c: /* original 2fb6, guest PC 0x0c08201c */
if(!s->budget--) { s->failed_pc=0x0c08201cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08201e;
P_0c08201e: /* original 7402, guest PC 0x0c08201e */
if(!s->budget--) { s->failed_pc=0x0c08201eu; return 0; }
r[4]+=0x00000002u;
goto P_0c082020;
P_0c082020: /* original 55f1, guest PC 0x0c082020 */
if(!s->budget--) { s->failed_pc=0x0c082020u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c082022;
P_0c082022: /* original 4400, guest PC 0x0c082022 */
if(!s->budget--) { s->failed_pc=0x0c082022u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c082024;
P_0c082024: /* original 66e3, guest PC 0x0c082024 */
if(!s->budget--) { s->failed_pc=0x0c082024u; return 0; }
r[6]=r[14];
goto P_0c082026;
P_0c082026: /* original 24cb, guest PC 0x0c082026 */
if(!s->budget--) { s->failed_pc=0x0c082026u; return 0; }
r[4]|=r[12];
goto P_0c082028;
P_0c082028: /* original e700, guest PC 0x0c082028 */
if(!s->budget--) { s->failed_pc=0x0c082028u; return 0; }
r[7]=0x00000000u;
goto P_0c08202a;
P_0c08202a: /* original 4a0b, guest PC 0x0c08202a */
if(!s->budget--) { s->failed_pc=0x0c08202au; return 0; }
target=r[10];
r[16]=code_base|0x0c08202eu;
r[5]+=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08202eu) { target=s->pc; goto dispatch; }
goto P_0c08202e;
P_0c08202c: /* original 35dc, guest PC 0x0c08202c */
if(!s->budget--) { s->failed_pc=0x0c08202cu; return 0; }
r[5]+=r[13];
goto P_0c08202e;
P_0c08202e: /* original 6483, guest PC 0x0c08202e */
if(!s->budget--) { s->failed_pc=0x0c08202eu; return 0; }
r[4]=r[8];
goto P_0c082030;
P_0c082030: /* original 2fb6, guest PC 0x0c082030 */
if(!s->budget--) { s->failed_pc=0x0c082030u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082032;
P_0c082032: /* original 7404, guest PC 0x0c082032 */
if(!s->budget--) { s->failed_pc=0x0c082032u; return 0; }
r[4]+=0x00000004u;
goto P_0c082034;
P_0c082034: /* original 55f3, guest PC 0x0c082034 */
if(!s->budget--) { s->failed_pc=0x0c082034u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c082036;
P_0c082036: /* original 4400, guest PC 0x0c082036 */
if(!s->budget--) { s->failed_pc=0x0c082036u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c082038;
P_0c082038: /* original 66e3, guest PC 0x0c082038 */
if(!s->budget--) { s->failed_pc=0x0c082038u; return 0; }
r[6]=r[14];
goto P_0c08203a;
P_0c08203a: /* original 24cb, guest PC 0x0c08203a */
if(!s->budget--) { s->failed_pc=0x0c08203au; return 0; }
r[4]|=r[12];
goto P_0c08203c;
P_0c08203c: /* original e700, guest PC 0x0c08203c */
if(!s->budget--) { s->failed_pc=0x0c08203cu; return 0; }
r[7]=0x00000000u;
goto P_0c08203e;
P_0c08203e: /* original 4a0b, guest PC 0x0c08203e */
if(!s->budget--) { s->failed_pc=0x0c08203eu; return 0; }
target=r[10];
r[16]=code_base|0x0c082042u;
r[5]+=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c082042u) { target=s->pc; goto dispatch; }
goto P_0c082042;
P_0c082040: /* original 35dc, guest PC 0x0c082040 */
if(!s->budget--) { s->failed_pc=0x0c082040u; return 0; }
r[5]+=r[13];
goto P_0c082042;
P_0c082042: /* original 7f10, guest PC 0x0c082042 */
if(!s->budget--) { s->failed_pc=0x0c082042u; return 0; }
r[15]+=0x00000010u;
goto P_0c082044;
P_0c082044: /* original 4f26, guest PC 0x0c082044 */
if(!s->budget--) { s->failed_pc=0x0c082044u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c082046;
P_0c082046: /* original 68f6, guest PC 0x0c082046 */
if(!s->budget--) { s->failed_pc=0x0c082046u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c082048;
P_0c082048: /* original 69f6, guest PC 0x0c082048 */
if(!s->budget--) { s->failed_pc=0x0c082048u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08204a;
P_0c08204a: /* original 6af6, guest PC 0x0c08204a */
if(!s->budget--) { s->failed_pc=0x0c08204au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08204c;
P_0c08204c: /* original 6bf6, guest PC 0x0c08204c */
if(!s->budget--) { s->failed_pc=0x0c08204cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08204e;
P_0c08204e: /* original 6cf6, guest PC 0x0c08204e */
if(!s->budget--) { s->failed_pc=0x0c08204eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c082050;
P_0c082050: /* original 6df6, guest PC 0x0c082050 */
if(!s->budget--) { s->failed_pc=0x0c082050u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c082052;
P_0c082052: /* original 000b, guest PC 0x0c082052 */
if(!s->budget--) { s->failed_pc=0x0c082052u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c082054: /* original 6ef6, guest PC 0x0c082054 */
if(!s->budget--) { s->failed_pc=0x0c082054u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c082056u,s,ram);
P_0c097ff4: /* original d427, guest PC 0x0c097ff4 */
if(!s->budget--) { s->failed_pc=0x0c097ff4u; return 0; }
r[4]=read(ram,0x0c098094u,4);
goto P_0c097ff6;
P_0c097ff6: /* original d329, guest PC 0x0c097ff6 */
if(!s->budget--) { s->failed_pc=0x0c097ff6u; return 0; }
r[3]=read(ram,0x0c09809cu,4);
goto P_0c097ff8;
P_0c097ff8: /* original 5242, guest PC 0x0c097ff8 */
if(!s->budget--) { s->failed_pc=0x0c097ff8u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c097ffa;
P_0c097ffa: /* original d627, guest PC 0x0c097ffa */
if(!s->budget--) { s->failed_pc=0x0c097ffau; return 0; }
r[6]=read(ram,0x0c098098u,4);
goto P_0c097ffc;
P_0c097ffc: /* original 2238, guest PC 0x0c097ffc */
if(!s->budget--) { s->failed_pc=0x0c097ffcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c097ffe;
P_0c097ffe: /* original 8b1d, guest PC 0x0c097ffe */
if(!s->budget--) { s->failed_pc=0x0c097ffeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09803c; }
goto P_0c098000;
P_0c098000: /* original 5142, guest PC 0x0c098000 */
if(!s->budget--) { s->failed_pc=0x0c098000u; return 0; }
r[1]=read(ram,r[4]+8,4);
goto P_0c098002;
P_0c098002: /* original d327, guest PC 0x0c098002 */
if(!s->budget--) { s->failed_pc=0x0c098002u; return 0; }
r[3]=read(ram,0x0c0980a0u,4);
goto P_0c098004;
P_0c098004: /* original 2138, guest PC 0x0c098004 */
if(!s->budget--) { s->failed_pc=0x0c098004u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c098006;
P_0c098006: /* original 8919, guest PC 0x0c098006 */
if(!s->budget--) { s->failed_pc=0x0c098006u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09803c; }
goto P_0c098008;
P_0c098008: /* original 5242, guest PC 0x0c098008 */
if(!s->budget--) { s->failed_pc=0x0c098008u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c09800a;
P_0c09800a: /* original d326, guest PC 0x0c09800a */
if(!s->budget--) { s->failed_pc=0x0c09800au; return 0; }
r[3]=read(ram,0x0c0980a4u,4);
goto P_0c09800c;
P_0c09800c: /* original 2238, guest PC 0x0c09800c */
if(!s->budget--) { s->failed_pc=0x0c09800cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09800e;
P_0c09800e: /* original 8d0f, guest PC 0x0c09800e */
if(!s->budget--) { s->failed_pc=0x0c09800eu; return 0; }
cond=r[17]&1u;
r[7]=0x00000000u;
if(cond) { goto P_0c098030; }
goto P_0c098012;
P_0c098010: /* original e700, guest PC 0x0c098010 */
if(!s->budget--) { s->failed_pc=0x0c098010u; return 0; }
r[7]=0x00000000u;
goto P_0c098012;
P_0c098012: /* original e029, guest PC 0x0c098012 */
if(!s->budget--) { s->failed_pc=0x0c098012u; return 0; }
r[0]=0x00000029u;
goto P_0c098014;
P_0c098014: /* original 004c, guest PC 0x0c098014 */
if(!s->budget--) { s->failed_pc=0x0c098014u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c098016;
P_0c098016: /* original 600c, guest PC 0x0c098016 */
if(!s->budget--) { s->failed_pc=0x0c098016u; return 0; }
r[0]=r[0]&255u;
goto P_0c098018;
P_0c098018: /* original 8803, guest PC 0x0c098018 */
if(!s->budget--) { s->failed_pc=0x0c098018u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09801a;
P_0c09801a: /* original 8909, guest PC 0x0c09801a */
if(!s->budget--) { s->failed_pc=0x0c09801au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098030; }
goto P_0c09801c;
P_0c09801c: /* original e02b, guest PC 0x0c09801c */
if(!s->budget--) { s->failed_pc=0x0c09801cu; return 0; }
r[0]=0x0000002bu;
goto P_0c09801e;
P_0c09801e: /* original 034c, guest PC 0x0c09801e */
if(!s->budget--) { s->failed_pc=0x0c09801eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c098020;
P_0c098020: /* original 7301, guest PC 0x0c098020 */
if(!s->budget--) { s->failed_pc=0x0c098020u; return 0; }
r[3]+=0x00000001u;
goto P_0c098022;
P_0c098022: /* original 0434, guest PC 0x0c098022 */
if(!s->budget--) { s->failed_pc=0x0c098022u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c098024;
P_0c098024: /* original 554d, guest PC 0x0c098024 */
if(!s->budget--) { s->failed_pc=0x0c098024u; return 0; }
r[5]=read(ram,r[4]+52,4);
goto P_0c098026;
P_0c098026: /* original 534e, guest PC 0x0c098026 */
if(!s->budget--) { s->failed_pc=0x0c098026u; return 0; }
r[3]=read(ram,r[4]+56,4);
goto P_0c098028;
P_0c098028: /* original 353c, guest PC 0x0c098028 */
if(!s->budget--) { s->failed_pc=0x0c098028u; return 0; }
r[5]+=r[3];
goto P_0c09802a;
P_0c09802a: /* original 145c, guest PC 0x0c09802a */
if(!s->budget--) { s->failed_pc=0x0c09802au; return 0; }
write(ram,r[4]+48,r[5],4);
goto P_0c09802c;
P_0c09802c: /* original 145d, guest PC 0x0c09802c */
if(!s->budget--) { s->failed_pc=0x0c09802cu; return 0; }
write(ram,r[4]+52,r[5],4);
goto P_0c09802e;
P_0c09802e: /* original 147e, guest PC 0x0c09802e */
if(!s->budget--) { s->failed_pc=0x0c09802eu; return 0; }
write(ram,r[4]+56,r[7],4);
goto P_0c098030;
P_0c098030: /* original e010, guest PC 0x0c098030 */
if(!s->budget--) { s->failed_pc=0x0c098030u; return 0; }
r[0]=0x00000010u;
goto P_0c098032;
P_0c098032: /* original 0674, guest PC 0x0c098032 */
if(!s->budget--) { s->failed_pc=0x0c098032u; return 0; }
write(ram,r[6]+r[0],r[7],1);
goto P_0c098034;
P_0c098034: /* original e00a, guest PC 0x0c098034 */
if(!s->budget--) { s->failed_pc=0x0c098034u; return 0; }
r[0]=0x0000000au;
goto P_0c098036;
P_0c098036: /* original d31c, guest PC 0x0c098036 */
if(!s->budget--) { s->failed_pc=0x0c098036u; return 0; }
r[3]=read(ram,0x0c0980a8u,4);
goto P_0c098038;
P_0c098038: /* original 432b, guest PC 0x0c098038 */
if(!s->budget--) { s->failed_pc=0x0c098038u; return 0; }
target=r[3];
write(ram,r[6]+10,r[0],1);
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c09803a: /* original 806a, guest PC 0x0c09803a */
if(!s->budget--) { s->failed_pc=0x0c09803au; return 0; }
write(ram,r[6]+10,r[0],1);
goto P_0c09803c;
P_0c09803c: /* original 000b, guest PC 0x0c09803c */
if(!s->budget--) { s->failed_pc=0x0c09803cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09803e: /* original 0009, guest PC 0x0c09803e */
if(!s->budget--) { s->failed_pc=0x0c09803eu; return 0; }
return vf3_matrix_family(0x0c098040u,s,ram);
P_0c098588: /* original 4f22, guest PC 0x0c098588 */
if(!s->budget--) { s->failed_pc=0x0c098588u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09858a;
P_0c09858a: /* original 53d3, guest PC 0x0c09858a */
if(!s->budget--) { s->failed_pc=0x0c09858au; return 0; }
r[3]=read(ram,r[13]+12,4);
goto P_0c09858c;
P_0c09858c: /* original dc25, guest PC 0x0c09858c */
if(!s->budget--) { s->failed_pc=0x0c09858cu; return 0; }
r[12]=read(ram,0x0c098624u,4);
goto P_0c09858e;
P_0c09858e: /* original 2338, guest PC 0x0c09858e */
if(!s->budget--) { s->failed_pc=0x0c09858eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c098590;
P_0c098590: /* original 8b40, guest PC 0x0c098590 */
if(!s->budget--) { s->failed_pc=0x0c098590u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098614; }
goto P_0c098592;
P_0c098592: /* original d227, guest PC 0x0c098592 */
if(!s->budget--) { s->failed_pc=0x0c098592u; return 0; }
r[2]=read(ram,0x0c098630u,4);
goto P_0c098594;
P_0c098594: /* original de25, guest PC 0x0c098594 */
if(!s->budget--) { s->failed_pc=0x0c098594u; return 0; }
r[14]=read(ram,0x0c09862cu,4);
goto P_0c098596;
P_0c098596: /* original 420b, guest PC 0x0c098596 */
if(!s->budget--) { s->failed_pc=0x0c098596u; return 0; }
target=r[2];
r[16]=code_base|0x0c09859au;
r[4]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09859au) { target=s->pc; goto dispatch; }
goto P_0c09859a;
P_0c098598: /* original 54e8, guest PC 0x0c098598 */
if(!s->budget--) { s->failed_pc=0x0c098598u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c09859a;
P_0c09859a: /* original d325, guest PC 0x0c09859a */
if(!s->budget--) { s->failed_pc=0x0c09859au; return 0; }
r[3]=read(ram,0x0c098630u,4);
goto P_0c09859c;
P_0c09859c: /* original e044, guest PC 0x0c09859c */
if(!s->budget--) { s->failed_pc=0x0c09859cu; return 0; }
r[0]=0x00000044u;
goto P_0c09859e;
P_0c09859e: /* original 430b, guest PC 0x0c09859e */
if(!s->budget--) { s->failed_pc=0x0c09859eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0985a2u;
r[4]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0985a2u) { target=s->pc; goto dispatch; }
goto P_0c0985a2;
P_0c0985a0: /* original 04ee, guest PC 0x0c0985a0 */
if(!s->budget--) { s->failed_pc=0x0c0985a0u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0985a2;
P_0c0985a2: /* original 54e4, guest PC 0x0c0985a2 */
if(!s->budget--) { s->failed_pc=0x0c0985a2u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c0985a4;
P_0c0985a4: /* original e024, guest PC 0x0c0985a4 */
if(!s->budget--) { s->failed_pc=0x0c0985a4u; return 0; }
r[0]=0x00000024u;
goto P_0c0985a6;
P_0c0985a6: /* original f48d, guest PC 0x0c0985a6 */
if(!s->budget--) { s->failed_pc=0x0c0985a6u; return 0; }
fr[4]=0;
goto P_0c0985a8;
P_0c0985a8: /* original f447, guest PC 0x0c0985a8 */
if(!s->budget--) { s->failed_pc=0x0c0985a8u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0985aa;
P_0c0985aa: /* original e028, guest PC 0x0c0985aa */
if(!s->budget--) { s->failed_pc=0x0c0985aau; return 0; }
r[0]=0x00000028u;
goto P_0c0985ac;
P_0c0985ac: /* original f447, guest PC 0x0c0985ac */
if(!s->budget--) { s->failed_pc=0x0c0985acu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0985ae;
P_0c0985ae: /* original e02c, guest PC 0x0c0985ae */
if(!s->budget--) { s->failed_pc=0x0c0985aeu; return 0; }
r[0]=0x0000002cu;
goto P_0c0985b0;
P_0c0985b0: /* original f447, guest PC 0x0c0985b0 */
if(!s->budget--) { s->failed_pc=0x0c0985b0u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0985b2;
P_0c0985b2: /* original 9034, guest PC 0x0c0985b2 */
if(!s->budget--) { s->failed_pc=0x0c0985b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09861eu,2);
goto P_0c0985b4;
P_0c0985b4: /* original f447, guest PC 0x0c0985b4 */
if(!s->budget--) { s->failed_pc=0x0c0985b4u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0985b6;
P_0c0985b6: /* original 7004, guest PC 0x0c0985b6 */
if(!s->budget--) { s->failed_pc=0x0c0985b6u; return 0; }
r[0]+=0x00000004u;
goto P_0c0985b8;
P_0c0985b8: /* original f447, guest PC 0x0c0985b8 */
if(!s->budget--) { s->failed_pc=0x0c0985b8u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0985ba;
P_0c0985ba: /* original 9031, guest PC 0x0c0985ba */
if(!s->budget--) { s->failed_pc=0x0c0985bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098620u,2);
goto P_0c0985bc;
P_0c0985bc: /* original f447, guest PC 0x0c0985bc */
if(!s->budget--) { s->failed_pc=0x0c0985bcu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0985be;
P_0c0985be: /* original 7004, guest PC 0x0c0985be */
if(!s->budget--) { s->failed_pc=0x0c0985beu; return 0; }
r[0]+=0x00000004u;
goto P_0c0985c0;
P_0c0985c0: /* original f447, guest PC 0x0c0985c0 */
if(!s->budget--) { s->failed_pc=0x0c0985c0u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0985c2;
P_0c0985c2: /* original 7004, guest PC 0x0c0985c2 */
if(!s->budget--) { s->failed_pc=0x0c0985c2u; return 0; }
r[0]+=0x00000004u;
goto P_0c0985c4;
P_0c0985c4: /* original f447, guest PC 0x0c0985c4 */
if(!s->budget--) { s->failed_pc=0x0c0985c4u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0985c6;
P_0c0985c6: /* original e024, guest PC 0x0c0985c6 */
if(!s->budget--) { s->failed_pc=0x0c0985c6u; return 0; }
r[0]=0x00000024u;
goto P_0c0985c8;
P_0c0985c8: /* original 54e4, guest PC 0x0c0985c8 */
if(!s->budget--) { s->failed_pc=0x0c0985c8u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c0985ca;
P_0c0985ca: /* original f447, guest PC 0x0c0985ca */
if(!s->budget--) { s->failed_pc=0x0c0985cau; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0985cc;
P_0c0985cc: /* original e028, guest PC 0x0c0985cc */
if(!s->budget--) { s->failed_pc=0x0c0985ccu; return 0; }
r[0]=0x00000028u;
goto P_0c0985ce;
P_0c0985ce: /* original f447, guest PC 0x0c0985ce */
if(!s->budget--) { s->failed_pc=0x0c0985ceu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0985d0;
P_0c0985d0: /* original e02c, guest PC 0x0c0985d0 */
if(!s->budget--) { s->failed_pc=0x0c0985d0u; return 0; }
r[0]=0x0000002cu;
goto P_0c0985d2;
P_0c0985d2: /* original f447, guest PC 0x0c0985d2 */
if(!s->budget--) { s->failed_pc=0x0c0985d2u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0985d4;
P_0c0985d4: /* original 9023, guest PC 0x0c0985d4 */
if(!s->budget--) { s->failed_pc=0x0c0985d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09861eu,2);
goto P_0c0985d6;
P_0c0985d6: /* original f447, guest PC 0x0c0985d6 */
if(!s->budget--) { s->failed_pc=0x0c0985d6u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0985d8;
P_0c0985d8: /* original 7004, guest PC 0x0c0985d8 */
if(!s->budget--) { s->failed_pc=0x0c0985d8u; return 0; }
r[0]+=0x00000004u;
goto P_0c0985da;
P_0c0985da: /* original f447, guest PC 0x0c0985da */
if(!s->budget--) { s->failed_pc=0x0c0985dau; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0985dc;
P_0c0985dc: /* original 9020, guest PC 0x0c0985dc */
if(!s->budget--) { s->failed_pc=0x0c0985dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098620u,2);
goto P_0c0985de;
P_0c0985de: /* original f447, guest PC 0x0c0985de */
if(!s->budget--) { s->failed_pc=0x0c0985deu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0985e0;
P_0c0985e0: /* original 7004, guest PC 0x0c0985e0 */
if(!s->budget--) { s->failed_pc=0x0c0985e0u; return 0; }
r[0]+=0x00000004u;
goto P_0c0985e2;
P_0c0985e2: /* original f447, guest PC 0x0c0985e2 */
if(!s->budget--) { s->failed_pc=0x0c0985e2u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0985e4;
P_0c0985e4: /* original 7004, guest PC 0x0c0985e4 */
if(!s->budget--) { s->failed_pc=0x0c0985e4u; return 0; }
r[0]+=0x00000004u;
goto P_0c0985e6;
P_0c0985e6: /* original f447, guest PC 0x0c0985e6 */
if(!s->budget--) { s->failed_pc=0x0c0985e6u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0985e8;
P_0c0985e8: /* original 54e8, guest PC 0x0c0985e8 */
if(!s->budget--) { s->failed_pc=0x0c0985e8u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c0985ea;
P_0c0985ea: /* original 6042, guest PC 0x0c0985ea */
if(!s->budget--) { s->failed_pc=0x0c0985eau; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c0985ec;
P_0c0985ec: /* original c810, guest PC 0x0c0985ec */
if(!s->budget--) { s->failed_pc=0x0c0985ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0985ee;
P_0c0985ee: /* original 8b02, guest PC 0x0c0985ee */
if(!s->budget--) { s->failed_pc=0x0c0985eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0985f6; }
goto P_0c0985f0;
P_0c0985f0: /* original d310, guest PC 0x0c0985f0 */
if(!s->budget--) { s->failed_pc=0x0c0985f0u; return 0; }
r[3]=read(ram,0x0c098634u,4);
goto P_0c0985f2;
P_0c0985f2: /* original 430b, guest PC 0x0c0985f2 */
if(!s->budget--) { s->failed_pc=0x0c0985f2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0985f6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0985f6u) { target=s->pc; goto dispatch; }
goto P_0c0985f6;
P_0c0985f4: /* original 0009, guest PC 0x0c0985f4 */
if(!s->budget--) { s->failed_pc=0x0c0985f4u; return 0; }
goto P_0c0985f6;
P_0c0985f6: /* original e07f, guest PC 0x0c0985f6 */
if(!s->budget--) { s->failed_pc=0x0c0985f6u; return 0; }
r[0]=0x0000007fu;
goto P_0c0985f8;
P_0c0985f8: /* original e201, guest PC 0x0c0985f8 */
if(!s->budget--) { s->failed_pc=0x0c0985f8u; return 0; }
r[2]=0x00000001u;
goto P_0c0985fa;
P_0c0985fa: /* original 0d24, guest PC 0x0c0985fa */
if(!s->budget--) { s->failed_pc=0x0c0985fau; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c0985fc;
P_0c0985fc: /* original e400, guest PC 0x0c0985fc */
if(!s->budget--) { s->failed_pc=0x0c0985fcu; return 0; }
r[4]=0x00000000u;
goto P_0c0985fe;
P_0c0985fe: /* original 9010, guest PC 0x0c0985fe */
if(!s->budget--) { s->failed_pc=0x0c0985feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098622u,2);
goto P_0c098600;
P_0c098600: /* original e317, guest PC 0x0c098600 */
if(!s->budget--) { s->failed_pc=0x0c098600u; return 0; }
r[3]=0x00000017u;
goto P_0c098602;
P_0c098602: /* original 0c44, guest PC 0x0c098602 */
if(!s->budget--) { s->failed_pc=0x0c098602u; return 0; }
write(ram,r[12]+r[0],r[4],1);
goto P_0c098604;
P_0c098604: /* original e041, guest PC 0x0c098604 */
if(!s->budget--) { s->failed_pc=0x0c098604u; return 0; }
r[0]=0x00000041u;
goto P_0c098606;
P_0c098606: /* original 0c44, guest PC 0x0c098606 */
if(!s->budget--) { s->failed_pc=0x0c098606u; return 0; }
write(ram,r[12]+r[0],r[4],1);
goto P_0c098608;
P_0c098608: /* original e040, guest PC 0x0c098608 */
if(!s->budget--) { s->failed_pc=0x0c098608u; return 0; }
r[0]=0x00000040u;
goto P_0c09860a;
P_0c09860a: /* original 0c44, guest PC 0x0c09860a */
if(!s->budget--) { s->failed_pc=0x0c09860au; return 0; }
write(ram,r[12]+r[0],r[4],1);
goto P_0c09860c;
P_0c09860c: /* original e010, guest PC 0x0c09860c */
if(!s->budget--) { s->failed_pc=0x0c09860cu; return 0; }
r[0]=0x00000010u;
goto P_0c09860e;
P_0c09860e: /* original 0d34, guest PC 0x0c09860e */
if(!s->budget--) { s->failed_pc=0x0c09860eu; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c098610;
P_0c098610: /* original e004, guest PC 0x0c098610 */
if(!s->budget--) { s->failed_pc=0x0c098610u; return 0; }
r[0]=0x00000004u;
goto P_0c098612;
P_0c098612: /* original 80db, guest PC 0x0c098612 */
if(!s->budget--) { s->failed_pc=0x0c098612u; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c098614;
P_0c098614: /* original 4f26, guest PC 0x0c098614 */
if(!s->budget--) { s->failed_pc=0x0c098614u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c098616;
P_0c098616: /* original 6cf6, guest PC 0x0c098616 */
if(!s->budget--) { s->failed_pc=0x0c098616u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c098618;
P_0c098618: /* original 6df6, guest PC 0x0c098618 */
if(!s->budget--) { s->failed_pc=0x0c098618u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09861a;
P_0c09861a: /* original aceb, guest PC 0x0c09861a */
if(!s->budget--) { s->failed_pc=0x0c09861au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c097ff4;
P_0c09861c: /* original 6ef6, guest PC 0x0c09861c */
if(!s->budget--) { s->failed_pc=0x0c09861cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09861eu,s,ram);
P_0c09d09e: /* original 4f22, guest PC 0x0c09d09e */
if(!s->budget--) { s->failed_pc=0x0c09d09eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d0a0;
P_0c09d0a0: /* original d34a, guest PC 0x0c09d0a0 */
if(!s->budget--) { s->failed_pc=0x0c09d0a0u; return 0; }
r[3]=read(ram,0x0c09d1ccu,4);
goto P_0c09d0a2;
P_0c09d0a2: /* original dd49, guest PC 0x0c09d0a2 */
if(!s->budget--) { s->failed_pc=0x0c09d0a2u; return 0; }
r[13]=read(ram,0x0c09d1c8u,4);
goto P_0c09d0a4;
P_0c09d0a4: /* original de47, guest PC 0x0c09d0a4 */
if(!s->budget--) { s->failed_pc=0x0c09d0a4u; return 0; }
r[14]=read(ram,0x0c09d1c4u,4);
goto P_0c09d0a6;
P_0c09d0a6: /* original 430b, guest PC 0x0c09d0a6 */
if(!s->budget--) { s->failed_pc=0x0c09d0a6u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d0aau;
r[4]=0xffffffffu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09d0aau) { target=s->pc; goto dispatch; }
goto P_0c09d0aa;
P_0c09d0a8: /* original e4ff, guest PC 0x0c09d0a8 */
if(!s->budget--) { s->failed_pc=0x0c09d0a8u; return 0; }
r[4]=0xffffffffu;
goto P_0c09d0aa;
P_0c09d0aa: /* original 9484, guest PC 0x0c09d0aa */
if(!s->budget--) { s->failed_pc=0x0c09d0aau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d1b6u,2);
goto P_0c09d0ac;
P_0c09d0ac: /* original 66d3, guest PC 0x0c09d0ac */
if(!s->budget--) { s->failed_pc=0x0c09d0acu; return 0; }
r[6]=r[13];
goto P_0c09d0ae;
P_0c09d0ae: /* original d248, guest PC 0x0c09d0ae */
if(!s->budget--) { s->failed_pc=0x0c09d0aeu; return 0; }
r[2]=read(ram,0x0c09d1d0u,4);
goto P_0c09d0b0;
P_0c09d0b0: /* original 7658, guest PC 0x0c09d0b0 */
if(!s->budget--) { s->failed_pc=0x0c09d0b0u; return 0; }
r[6]+=0x00000058u;
goto P_0c09d0b2;
P_0c09d0b2: /* original 420b, guest PC 0x0c09d0b2 */
if(!s->budget--) { s->failed_pc=0x0c09d0b2u; return 0; }
target=r[2];
r[16]=code_base|0x0c09d0b6u;
r[5]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09d0b6u) { target=s->pc; goto dispatch; }
goto P_0c09d0b6;
P_0c09d0b4: /* original 65d3, guest PC 0x0c09d0b4 */
if(!s->budget--) { s->failed_pc=0x0c09d0b4u; return 0; }
r[5]=r[13];
goto P_0c09d0b6;
P_0c09d0b6: /* original e300, guest PC 0x0c09d0b6 */
if(!s->budget--) { s->failed_pc=0x0c09d0b6u; return 0; }
r[3]=0x00000000u;
goto P_0c09d0b8;
P_0c09d0b8: /* original 64d3, guest PC 0x0c09d0b8 */
if(!s->budget--) { s->failed_pc=0x0c09d0b8u; return 0; }
r[4]=r[13];
goto P_0c09d0ba;
P_0c09d0ba: /* original 6533, guest PC 0x0c09d0ba */
if(!s->budget--) { s->failed_pc=0x0c09d0bau; return 0; }
r[5]=r[3];
goto P_0c09d0bc;
P_0c09d0bc: /* original 2f36, guest PC 0x0c09d0bc */
if(!s->budget--) { s->failed_pc=0x0c09d0bcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d0be;
P_0c09d0be: /* original d245, guest PC 0x0c09d0be */
if(!s->budget--) { s->failed_pc=0x0c09d0beu; return 0; }
r[2]=read(ram,0x0c09d1d4u,4);
goto P_0c09d0c0;
P_0c09d0c0: /* original e730, guest PC 0x0c09d0c0 */
if(!s->budget--) { s->failed_pc=0x0c09d0c0u; return 0; }
r[7]=0x00000030u;
goto P_0c09d0c2;
P_0c09d0c2: /* original e63e, guest PC 0x0c09d0c2 */
if(!s->budget--) { s->failed_pc=0x0c09d0c2u; return 0; }
r[6]=0x0000003eu;
goto P_0c09d0c4;
P_0c09d0c4: /* original 420b, guest PC 0x0c09d0c4 */
if(!s->budget--) { s->failed_pc=0x0c09d0c4u; return 0; }
target=r[2];
r[16]=code_base|0x0c09d0c8u;
r[4]+=0x0000002cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09d0c8u) { target=s->pc; goto dispatch; }
goto P_0c09d0c8;
P_0c09d0c6: /* original 742c, guest PC 0x0c09d0c6 */
if(!s->budget--) { s->failed_pc=0x0c09d0c6u; return 0; }
r[4]+=0x0000002cu;
goto P_0c09d0c8;
P_0c09d0c8: /* original 6cd3, guest PC 0x0c09d0c8 */
if(!s->budget--) { s->failed_pc=0x0c09d0c8u; return 0; }
r[12]=r[13];
goto P_0c09d0ca;
P_0c09d0ca: /* original 9475, guest PC 0x0c09d0ca */
if(!s->budget--) { s->failed_pc=0x0c09d0cau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d1b8u,2);
goto P_0c09d0cc;
P_0c09d0cc: /* original dd42, guest PC 0x0c09d0cc */
if(!s->budget--) { s->failed_pc=0x0c09d0ccu; return 0; }
r[13]=read(ram,0x0c09d1d8u,4);
goto P_0c09d0ce;
P_0c09d0ce: /* original 7f04, guest PC 0x0c09d0ce */
if(!s->budget--) { s->failed_pc=0x0c09d0ceu; return 0; }
r[15]+=0x00000004u;
goto P_0c09d0d0;
P_0c09d0d0: /* original 4d0b, guest PC 0x0c09d0d0 */
if(!s->budget--) { s->failed_pc=0x0c09d0d0u; return 0; }
target=r[13];
r[16]=code_base|0x0c09d0d4u;
r[4]+=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09d0d4u) { target=s->pc; goto dispatch; }
goto P_0c09d0d4;
P_0c09d0d2: /* original 34cc, guest PC 0x0c09d0d2 */
if(!s->budget--) { s->failed_pc=0x0c09d0d2u; return 0; }
r[4]+=r[12];
goto P_0c09d0d4;
P_0c09d0d4: /* original 4d0b, guest PC 0x0c09d0d4 */
if(!s->budget--) { s->failed_pc=0x0c09d0d4u; return 0; }
target=r[13];
r[16]=code_base|0x0c09d0d8u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09d0d8u) { target=s->pc; goto dispatch; }
goto P_0c09d0d8;
P_0c09d0d6: /* original 64c3, guest PC 0x0c09d0d6 */
if(!s->budget--) { s->failed_pc=0x0c09d0d6u; return 0; }
r[4]=r[12];
goto P_0c09d0d8;
P_0c09d0d8: /* original 64c3, guest PC 0x0c09d0d8 */
if(!s->budget--) { s->failed_pc=0x0c09d0d8u; return 0; }
r[4]=r[12];
goto P_0c09d0da;
P_0c09d0da: /* original 4d0b, guest PC 0x0c09d0da */
if(!s->budget--) { s->failed_pc=0x0c09d0dau; return 0; }
target=r[13];
r[16]=code_base|0x0c09d0deu;
r[4]+=0x00000058u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09d0deu) { target=s->pc; goto dispatch; }
goto P_0c09d0de;
P_0c09d0dc: /* original 7458, guest PC 0x0c09d0dc */
if(!s->budget--) { s->failed_pc=0x0c09d0dcu; return 0; }
r[4]+=0x00000058u;
goto P_0c09d0de;
P_0c09d0de: /* original 906c, guest PC 0x0c09d0de */
if(!s->budget--) { s->failed_pc=0x0c09d0deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d1bau,2);
goto P_0c09d0e0;
P_0c09d0e0: /* original e301, guest PC 0x0c09d0e0 */
if(!s->budget--) { s->failed_pc=0x0c09d0e0u; return 0; }
r[3]=0x00000001u;
goto P_0c09d0e2;
P_0c09d0e2: /* original e600, guest PC 0x0c09d0e2 */
if(!s->budget--) { s->failed_pc=0x0c09d0e2u; return 0; }
r[6]=0x00000000u;
goto P_0c09d0e4;
P_0c09d0e4: /* original 0e36, guest PC 0x0c09d0e4 */
if(!s->budget--) { s->failed_pc=0x0c09d0e4u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09d0e6;
P_0c09d0e6: /* original e000, guest PC 0x0c09d0e6 */
if(!s->budget--) { s->failed_pc=0x0c09d0e6u; return 0; }
r[0]=0x00000000u;
goto P_0c09d0e8;
P_0c09d0e8: /* original 80eb, guest PC 0x0c09d0e8 */
if(!s->budget--) { s->failed_pc=0x0c09d0e8u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09d0ea;
P_0c09d0ea: /* original e010, guest PC 0x0c09d0ea */
if(!s->budget--) { s->failed_pc=0x0c09d0eau; return 0; }
r[0]=0x00000010u;
goto P_0c09d0ec;
P_0c09d0ec: /* original e37b, guest PC 0x0c09d0ec */
if(!s->budget--) { s->failed_pc=0x0c09d0ecu; return 0; }
r[3]=0x0000007bu;
goto P_0c09d0ee;
P_0c09d0ee: /* original 6563, guest PC 0x0c09d0ee */
if(!s->budget--) { s->failed_pc=0x0c09d0eeu; return 0; }
r[5]=r[6];
goto P_0c09d0f0;
P_0c09d0f0: /* original 0e34, guest PC 0x0c09d0f0 */
if(!s->budget--) { s->failed_pc=0x0c09d0f0u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09d0f2;
P_0c09d0f2: /* original 84ea, guest PC 0x0c09d0f2 */
if(!s->budget--) { s->failed_pc=0x0c09d0f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+10,1);
goto P_0c09d0f4;
P_0c09d0f4: /* original 7001, guest PC 0x0c09d0f4 */
if(!s->budget--) { s->failed_pc=0x0c09d0f4u; return 0; }
r[0]+=0x00000001u;
goto P_0c09d0f6;
P_0c09d0f6: /* original 80ea, guest PC 0x0c09d0f6 */
if(!s->budget--) { s->failed_pc=0x0c09d0f6u; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c09d0f8;
P_0c09d0f8: /* original d338, guest PC 0x0c09d0f8 */
if(!s->budget--) { s->failed_pc=0x0c09d0f8u; return 0; }
r[3]=read(ram,0x0c09d1dcu,4);
goto P_0c09d0fa;
P_0c09d0fa: /* original 430b, guest PC 0x0c09d0fa */
if(!s->budget--) { s->failed_pc=0x0c09d0fau; return 0; }
target=r[3];
r[16]=code_base|0x0c09d0feu;
r[4]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09d0feu) { target=s->pc; goto dispatch; }
goto P_0c09d0fe;
P_0c09d0fc: /* original 6463, guest PC 0x0c09d0fc */
if(!s->budget--) { s->failed_pc=0x0c09d0fcu; return 0; }
r[4]=r[6];
goto P_0c09d0fe;
P_0c09d0fe: /* original 4f26, guest PC 0x0c09d0fe */
if(!s->budget--) { s->failed_pc=0x0c09d0feu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d100;
P_0c09d100: /* original 925c, guest PC 0x0c09d100 */
if(!s->budget--) { s->failed_pc=0x0c09d100u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d1bcu,2);
goto P_0c09d102;
P_0c09d102: /* original 1e23, guest PC 0x0c09d102 */
if(!s->budget--) { s->failed_pc=0x0c09d102u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c09d104;
P_0c09d104: /* original 6cf6, guest PC 0x0c09d104 */
if(!s->budget--) { s->failed_pc=0x0c09d104u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09d106;
P_0c09d106: /* original 6df6, guest PC 0x0c09d106 */
if(!s->budget--) { s->failed_pc=0x0c09d106u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09d108;
P_0c09d108: /* original a000, guest PC 0x0c09d108 */
if(!s->budget--) { s->failed_pc=0x0c09d108u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09d10c;
P_0c09d10a: /* original 6ef6, guest PC 0x0c09d10a */
if(!s->budget--) { s->failed_pc=0x0c09d10au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09d10c;
P_0c09d10c: /* original 9055, guest PC 0x0c09d10c */
if(!s->budget--) { s->failed_pc=0x0c09d10cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d1bau,2);
goto P_0c09d10e;
P_0c09d10e: /* original d42d, guest PC 0x0c09d10e */
if(!s->budget--) { s->failed_pc=0x0c09d10eu; return 0; }
r[4]=read(ram,0x0c09d1c4u,4);
goto P_0c09d110;
P_0c09d110: /* original d633, guest PC 0x0c09d110 */
if(!s->budget--) { s->failed_pc=0x0c09d110u; return 0; }
r[6]=read(ram,0x0c09d1e0u,4);
goto P_0c09d112;
P_0c09d112: /* original 004e, guest PC 0x0c09d112 */
if(!s->budget--) { s->failed_pc=0x0c09d112u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c09d114;
P_0c09d114: /* original 8803, guest PC 0x0c09d114 */
if(!s->budget--) { s->failed_pc=0x0c09d114u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09d116;
P_0c09d116: /* original 8d03, guest PC 0x0c09d116 */
if(!s->budget--) { s->failed_pc=0x0c09d116u; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c09d120; }
goto P_0c09d11a;
P_0c09d118: /* original 6503, guest PC 0x0c09d118 */
if(!s->budget--) { s->failed_pc=0x0c09d118u; return 0; }
r[5]=r[0];
goto P_0c09d11a;
P_0c09d11a: /* original 6053, guest PC 0x0c09d11a */
if(!s->budget--) { s->failed_pc=0x0c09d11au; return 0; }
r[0]=r[5];
goto P_0c09d11c;
P_0c09d11c: /* original 8802, guest PC 0x0c09d11c */
if(!s->budget--) { s->failed_pc=0x0c09d11cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09d11e;
P_0c09d11e: /* original 8b09, guest PC 0x0c09d11e */
if(!s->budget--) { s->failed_pc=0x0c09d11eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09d134; }
goto P_0c09d120;
P_0c09d120: /* original e700, guest PC 0x0c09d120 */
if(!s->budget--) { s->failed_pc=0x0c09d120u; return 0; }
r[7]=0x00000000u;
goto P_0c09d122;
P_0c09d122: /* original e029, guest PC 0x0c09d122 */
if(!s->budget--) { s->failed_pc=0x0c09d122u; return 0; }
r[0]=0x00000029u;
goto P_0c09d124;
P_0c09d124: /* original 0674, guest PC 0x0c09d124 */
if(!s->budget--) { s->failed_pc=0x0c09d124u; return 0; }
write(ram,r[6]+r[0],r[7],1);
goto P_0c09d126;
P_0c09d126: /* original e002, guest PC 0x0c09d126 */
if(!s->budget--) { s->failed_pc=0x0c09d126u; return 0; }
r[0]=0x00000002u;
goto P_0c09d128;
P_0c09d128: /* original 5562, guest PC 0x0c09d128 */
if(!s->budget--) { s->failed_pc=0x0c09d128u; return 0; }
r[5]=read(ram,r[6]+8,4);
goto P_0c09d12a;
P_0c09d12a: /* original d32e, guest PC 0x0c09d12a */
if(!s->budget--) { s->failed_pc=0x0c09d12au; return 0; }
r[3]=read(ram,0x0c09d1e4u,4);
goto P_0c09d12c;
P_0c09d12c: /* original 2539, guest PC 0x0c09d12c */
if(!s->budget--) { s->failed_pc=0x0c09d12cu; return 0; }
r[5]&=r[3];
goto P_0c09d12e;
P_0c09d12e: /* original 1652, guest PC 0x0c09d12e */
if(!s->budget--) { s->failed_pc=0x0c09d12eu; return 0; }
write(ram,r[6]+8,r[5],4);
goto P_0c09d130;
P_0c09d130: /* original 804a, guest PC 0x0c09d130 */
if(!s->budget--) { s->failed_pc=0x0c09d130u; return 0; }
write(ram,r[4]+10,r[0],1);
goto P_0c09d132;
P_0c09d132: /* original 1473, guest PC 0x0c09d132 */
if(!s->budget--) { s->failed_pc=0x0c09d132u; return 0; }
write(ram,r[4]+12,r[7],4);
goto P_0c09d134;
P_0c09d134: /* original 000b, guest PC 0x0c09d134 */
if(!s->budget--) { s->failed_pc=0x0c09d134u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09d136: /* original 0009, guest PC 0x0c09d136 */
if(!s->budget--) { s->failed_pc=0x0c09d136u; return 0; }
return vf3_matrix_family(0x0c09d138u,s,ram);
P_0c0a0280: /* original 2fe6, guest PC 0x0c0a0280 */
if(!s->budget--) { s->failed_pc=0x0c0a0280u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0282;
P_0c0a0282: /* original 2fd6, guest PC 0x0c0a0282 */
if(!s->budget--) { s->failed_pc=0x0c0a0282u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0284;
P_0c0a0284: /* original 2fc6, guest PC 0x0c0a0284 */
if(!s->budget--) { s->failed_pc=0x0c0a0284u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0286;
P_0c0a0286: /* original ec2b, guest PC 0x0c0a0286 */
if(!s->budget--) { s->failed_pc=0x0c0a0286u; return 0; }
r[12]=0x0000002bu;
goto P_0c0a0288;
P_0c0a0288: /* original 2fb6, guest PC 0x0c0a0288 */
if(!s->budget--) { s->failed_pc=0x0c0a0288u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
return vf3_matrix_family(0x0c0a028au,s,ram);
P_0c0a03de: /* original 2fe6, guest PC 0x0c0a03de */
if(!s->budget--) { s->failed_pc=0x0c0a03deu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a03e0;
P_0c0a03e0: /* original 2fd6, guest PC 0x0c0a03e0 */
if(!s->budget--) { s->failed_pc=0x0c0a03e0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a03e2;
P_0c0a03e2: /* original 2fc6, guest PC 0x0c0a03e2 */
if(!s->budget--) { s->failed_pc=0x0c0a03e2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a03e4;
P_0c0a03e4: /* original ec1f, guest PC 0x0c0a03e4 */
if(!s->budget--) { s->failed_pc=0x0c0a03e4u; return 0; }
r[12]=0x0000001fu;
goto P_0c0a03e6;
P_0c0a03e6: /* original d31a, guest PC 0x0c0a03e6 */
if(!s->budget--) { s->failed_pc=0x0c0a03e6u; return 0; }
r[3]=read(ram,0x0c0a0450u,4);
goto P_0c0a03e8;
P_0c0a03e8: /* original d417, guest PC 0x0c0a03e8 */
if(!s->budget--) { s->failed_pc=0x0c0a03e8u; return 0; }
r[4]=read(ram,0x0c0a0448u,4);
goto P_0c0a03ea;
P_0c0a03ea: /* original 902b, guest PC 0x0c0a03ea */
if(!s->budget--) { s->failed_pc=0x0c0a03eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0444u,2);
goto P_0c0a03ec;
P_0c0a03ec: /* original 6532, guest PC 0x0c0a03ec */
if(!s->budget--) { s->failed_pc=0x0c0a03ecu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c0a03ee;
P_0c0a03ee: /* original 0e4c, guest PC 0x0c0a03ee */
if(!s->budget--) { s->failed_pc=0x0c0a03eeu; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
return vf3_matrix_family(0x0c0a03f0u,s,ram);
P_0c0aa7a2: /* original e048, guest PC 0x0c0aa7a2 */
if(!s->budget--) { s->failed_pc=0x0c0aa7a2u; return 0; }
r[0]=0x00000048u;
goto P_0c0aa7a4;
P_0c0aa7a4: /* original d324, guest PC 0x0c0aa7a4 */
if(!s->budget--) { s->failed_pc=0x0c0aa7a4u; return 0; }
r[3]=read(ram,0x0c0aa838u,4);
goto P_0c0aa7a6;
P_0c0aa7a6: /* original 025e, guest PC 0x0c0aa7a6 */
if(!s->budget--) { s->failed_pc=0x0c0aa7a6u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c0aa7a8;
P_0c0aa7a8: /* original 4f22, guest PC 0x0c0aa7a8 */
if(!s->budget--) { s->failed_pc=0x0c0aa7a8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aa7aa;
P_0c0aa7aa: /* original 2238, guest PC 0x0c0aa7aa */
if(!s->budget--) { s->failed_pc=0x0c0aa7aau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aa7ac;
P_0c0aa7ac: /* original 891b, guest PC 0x0c0aa7ac */
if(!s->budget--) { s->failed_pc=0x0c0aa7acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa7e6; }
goto P_0c0aa7ae;
P_0c0aa7ae: /* original 9034, guest PC 0x0c0aa7ae */
if(!s->budget--) { s->failed_pc=0x0c0aa7aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa81au,2);
goto P_0c0aa7b0;
P_0c0aa7b0: /* original 065d, guest PC 0x0c0aa7b0 */
if(!s->budget--) { s->failed_pc=0x0c0aa7b0u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0aa7b2;
P_0c0aa7b2: /* original e03e, guest PC 0x0c0aa7b2 */
if(!s->budget--) { s->failed_pc=0x0c0aa7b2u; return 0; }
r[0]=0x0000003eu;
goto P_0c0aa7b4;
P_0c0aa7b4: /* original 035d, guest PC 0x0c0aa7b4 */
if(!s->budget--) { s->failed_pc=0x0c0aa7b4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0aa7b6;
P_0c0aa7b6: /* original 8444, guest PC 0x0c0aa7b6 */
if(!s->budget--) { s->failed_pc=0x0c0aa7b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+4,1);
goto P_0c0aa7b8;
P_0c0aa7b8: /* original 666d, guest PC 0x0c0aa7b8 */
if(!s->budget--) { s->failed_pc=0x0c0aa7b8u; return 0; }
r[6]=r[6]&65535u;
goto P_0c0aa7ba;
P_0c0aa7ba: /* original 633d, guest PC 0x0c0aa7ba */
if(!s->budget--) { s->failed_pc=0x0c0aa7bau; return 0; }
r[3]=r[3]&65535u;
goto P_0c0aa7bc;
P_0c0aa7bc: /* original 600c, guest PC 0x0c0aa7bc */
if(!s->budget--) { s->failed_pc=0x0c0aa7bcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0aa7be;
P_0c0aa7be: /* original 3638, guest PC 0x0c0aa7be */
if(!s->budget--) { s->failed_pc=0x0c0aa7beu; return 0; }
r[6]-=r[3];
goto P_0c0aa7c0;
P_0c0aa7c0: /* original 360c, guest PC 0x0c0aa7c0 */
if(!s->budget--) { s->failed_pc=0x0c0aa7c0u; return 0; }
r[6]+=r[0];
goto P_0c0aa7c2;
P_0c0aa7c2: /* original 902b, guest PC 0x0c0aa7c2 */
if(!s->budget--) { s->failed_pc=0x0c0aa7c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa81cu,2);
goto P_0c0aa7c4;
P_0c0aa7c4: /* original e301, guest PC 0x0c0aa7c4 */
if(!s->budget--) { s->failed_pc=0x0c0aa7c4u; return 0; }
r[3]=0x00000001u;
goto P_0c0aa7c6;
P_0c0aa7c6: /* original 054d, guest PC 0x0c0aa7c6 */
if(!s->budget--) { s->failed_pc=0x0c0aa7c6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0aa7c8;
P_0c0aa7c8: /* original 3637, guest PC 0x0c0aa7c8 */
if(!s->budget--) { s->failed_pc=0x0c0aa7c8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[3])!=0);
goto P_0c0aa7ca;
P_0c0aa7ca: /* original 8f0a, guest PC 0x0c0aa7ca */
if(!s->budget--) { s->failed_pc=0x0c0aa7cau; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(!cond) { goto P_0c0aa7e2; }
goto P_0c0aa7ce;
P_0c0aa7cc: /* original 655d, guest PC 0x0c0aa7cc */
if(!s->budget--) { s->failed_pc=0x0c0aa7ccu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0aa7ce;
P_0c0aa7ce: /* original e03e, guest PC 0x0c0aa7ce */
if(!s->budget--) { s->failed_pc=0x0c0aa7ceu; return 0; }
r[0]=0x0000003eu;
goto P_0c0aa7d0;
P_0c0aa7d0: /* original d31a, guest PC 0x0c0aa7d0 */
if(!s->budget--) { s->failed_pc=0x0c0aa7d0u; return 0; }
r[3]=read(ram,0x0c0aa83cu,4);
goto P_0c0aa7d2;
P_0c0aa7d2: /* original 074d, guest PC 0x0c0aa7d2 */
if(!s->budget--) { s->failed_pc=0x0c0aa7d2u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0aa7d4;
P_0c0aa7d4: /* original 677d, guest PC 0x0c0aa7d4 */
if(!s->budget--) { s->failed_pc=0x0c0aa7d4u; return 0; }
r[7]=r[7]&65535u;
goto P_0c0aa7d6;
P_0c0aa7d6: /* original 3578, guest PC 0x0c0aa7d6 */
if(!s->budget--) { s->failed_pc=0x0c0aa7d6u; return 0; }
r[5]-=r[7];
goto P_0c0aa7d8;
P_0c0aa7d8: /* original 6153, guest PC 0x0c0aa7d8 */
if(!s->budget--) { s->failed_pc=0x0c0aa7d8u; return 0; }
r[1]=r[5];
goto P_0c0aa7da;
P_0c0aa7da: /* original 430b, guest PC 0x0c0aa7da */
if(!s->budget--) { s->failed_pc=0x0c0aa7dau; return 0; }
target=r[3];
r[16]=code_base|0x0c0aa7deu;
r[0]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aa7deu) { target=s->pc; goto dispatch; }
goto P_0c0aa7de;
P_0c0aa7dc: /* original 6063, guest PC 0x0c0aa7dc */
if(!s->budget--) { s->failed_pc=0x0c0aa7dcu; return 0; }
r[0]=r[6];
goto P_0c0aa7de;
P_0c0aa7de: /* original 6503, guest PC 0x0c0aa7de */
if(!s->budget--) { s->failed_pc=0x0c0aa7deu; return 0; }
r[5]=r[0];
goto P_0c0aa7e0;
P_0c0aa7e0: /* original 357c, guest PC 0x0c0aa7e0 */
if(!s->budget--) { s->failed_pc=0x0c0aa7e0u; return 0; }
r[5]+=r[7];
goto P_0c0aa7e2;
P_0c0aa7e2: /* original e03e, guest PC 0x0c0aa7e2 */
if(!s->budget--) { s->failed_pc=0x0c0aa7e2u; return 0; }
r[0]=0x0000003eu;
goto P_0c0aa7e4;
P_0c0aa7e4: /* original 0455, guest PC 0x0c0aa7e4 */
if(!s->budget--) { s->failed_pc=0x0c0aa7e4u; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c0aa7e6;
P_0c0aa7e6: /* original 4f26, guest PC 0x0c0aa7e6 */
if(!s->budget--) { s->failed_pc=0x0c0aa7e6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aa7e8;
P_0c0aa7e8: /* original 000b, guest PC 0x0c0aa7e8 */
if(!s->budget--) { s->failed_pc=0x0c0aa7e8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0aa7ea: /* original 0009, guest PC 0x0c0aa7ea */
if(!s->budget--) { s->failed_pc=0x0c0aa7eau; return 0; }
return vf3_matrix_family(0x0c0aa7ecu,s,ram);
P_0c0aaaf6: /* original 4f22, guest PC 0x0c0aaaf6 */
if(!s->budget--) { s->failed_pc=0x0c0aaaf6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aaaf8;
P_0c0aaaf8: /* original 7ffc, guest PC 0x0c0aaaf8 */
if(!s->budget--) { s->failed_pc=0x0c0aaaf8u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0aaafa;
P_0c0aaafa: /* original 2f52, guest PC 0x0c0aaafa */
if(!s->budget--) { s->failed_pc=0x0c0aaafau; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0aaafc;
P_0c0aaafc: /* original 04ee, guest PC 0x0c0aaafc */
if(!s->budget--) { s->failed_pc=0x0c0aaafcu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0aaafe;
P_0c0aaafe: /* original e048, guest PC 0x0c0aaafe */
if(!s->budget--) { s->failed_pc=0x0c0aaafeu; return 0; }
r[0]=0x00000048u;
goto P_0c0aab00;
P_0c0aab00: /* original 06ee, guest PC 0x0c0aab00 */
if(!s->budget--) { s->failed_pc=0x0c0aab00u; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c0aab02;
P_0c0aab02: /* original d30f, guest PC 0x0c0aab02 */
if(!s->budget--) { s->failed_pc=0x0c0aab02u; return 0; }
r[3]=read(ram,0x0c0aab40u,4);
goto P_0c0aab04;
P_0c0aab04: /* original 970e, guest PC 0x0c0aab04 */
if(!s->budget--) { s->failed_pc=0x0c0aab04u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aab24u,2);
goto P_0c0aab06;
P_0c0aab06: /* original 2368, guest PC 0x0c0aab06 */
if(!s->budget--) { s->failed_pc=0x0c0aab06u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0aab08;
P_0c0aab08: /* original 8d20, guest PC 0x0c0aab08 */
if(!s->budget--) { s->failed_pc=0x0c0aab08u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[14],4);
r[13]=tmp;
if(cond) { goto P_0c0aab4c; }
goto P_0c0aab0c;
P_0c0aab0a: /* original 6de2, guest PC 0x0c0aab0a */
if(!s->budget--) { s->failed_pc=0x0c0aab0au; return 0; }
tmp=read(ram,r[14],4);
r[13]=tmp;
goto P_0c0aab0c;
P_0c0aab0c: /* original d306, guest PC 0x0c0aab0c */
if(!s->budget--) { s->failed_pc=0x0c0aab0cu; return 0; }
r[3]=read(ram,0x0c0aab28u,4);
goto P_0c0aab0e;
P_0c0aab0e: /* original d50d, guest PC 0x0c0aab0e */
if(!s->budget--) { s->failed_pc=0x0c0aab0eu; return 0; }
r[5]=read(ram,0x0c0aab44u,4);
goto P_0c0aab10;
P_0c0aab10: /* original 2368, guest PC 0x0c0aab10 */
if(!s->budget--) { s->failed_pc=0x0c0aab10u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0aab12;
P_0c0aab12: /* original 8d38, guest PC 0x0c0aab12 */
if(!s->budget--) { s->failed_pc=0x0c0aab12u; return 0; }
cond=r[17]&1u;
r[5]&=r[13];
if(cond) { goto P_0c0aab86; }
goto P_0c0aab16;
P_0c0aab14: /* original 25d9, guest PC 0x0c0aab14 */
if(!s->budget--) { s->failed_pc=0x0c0aab14u; return 0; }
r[5]&=r[13];
goto P_0c0aab16;
P_0c0aab16: /* original d10c, guest PC 0x0c0aab16 */
if(!s->budget--) { s->failed_pc=0x0c0aab16u; return 0; }
r[1]=read(ram,0x0c0aab48u,4);
goto P_0c0aab18;
P_0c0aab18: /* original 2168, guest PC 0x0c0aab18 */
if(!s->budget--) { s->failed_pc=0x0c0aab18u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[6])==0)!=0);
goto P_0c0aab1a;
P_0c0aab1a: /* original 8b47, guest PC 0x0c0aab1a */
if(!s->budget--) { s->failed_pc=0x0c0aab1au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aabac; }
goto P_0c0aab1c;
P_0c0aab1c: /* original a033, guest PC 0x0c0aab1c */
if(!s->budget--) { s->failed_pc=0x0c0aab1cu; return 0; }
goto P_0c0aab86;
P_0c0aab1e: /* original 0009, guest PC 0x0c0aab1e */
if(!s->budget--) { s->failed_pc=0x0c0aab1eu; return 0; }
return vf3_matrix_family(0x0c0aab20u,s,ram);
P_0c0aab4c: /* original 8547, guest PC 0x0c0aab4c */
if(!s->budget--) { s->failed_pc=0x0c0aab4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+14,2);
goto P_0c0aab4e;
P_0c0aab4e: /* original 650d, guest PC 0x0c0aab4e */
if(!s->budget--) { s->failed_pc=0x0c0aab4eu; return 0; }
r[5]=r[0]&65535u;
goto P_0c0aab50;
P_0c0aab50: /* original e061, guest PC 0x0c0aab50 */
if(!s->budget--) { s->failed_pc=0x0c0aab50u; return 0; }
r[0]=0x00000061u;
goto P_0c0aab52;
P_0c0aab52: /* original 00ec, guest PC 0x0c0aab52 */
if(!s->budget--) { s->failed_pc=0x0c0aab52u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0aab54;
P_0c0aab54: /* original 600c, guest PC 0x0c0aab54 */
if(!s->budget--) { s->failed_pc=0x0c0aab54u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aab56;
P_0c0aab56: /* original 8801, guest PC 0x0c0aab56 */
if(!s->budget--) { s->failed_pc=0x0c0aab56u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0aab58;
P_0c0aab58: /* original 8904, guest PC 0x0c0aab58 */
if(!s->budget--) { s->failed_pc=0x0c0aab58u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aab64; }
goto P_0c0aab5a;
P_0c0aab5a: /* original d328, guest PC 0x0c0aab5a */
if(!s->budget--) { s->failed_pc=0x0c0aab5au; return 0; }
r[3]=read(ram,0x0c0aabfcu,4);
goto P_0c0aab5c;
P_0c0aab5c: /* original 2d38, guest PC 0x0c0aab5c */
if(!s->budget--) { s->failed_pc=0x0c0aab5cu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[3])==0)!=0);
goto P_0c0aab5e;
P_0c0aab5e: /* original 8901, guest PC 0x0c0aab5e */
if(!s->budget--) { s->failed_pc=0x0c0aab5eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aab64; }
goto P_0c0aab60;
P_0c0aab60: /* original 854b, guest PC 0x0c0aab60 */
if(!s->budget--) { s->failed_pc=0x0c0aab60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+22,2);
goto P_0c0aab62;
P_0c0aab62: /* original 650d, guest PC 0x0c0aab62 */
if(!s->budget--) { s->failed_pc=0x0c0aab62u; return 0; }
r[5]=r[0]&65535u;
goto P_0c0aab64;
P_0c0aab64: /* original 9047, guest PC 0x0c0aab64 */
if(!s->budget--) { s->failed_pc=0x0c0aab64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aabf6u,2);
goto P_0c0aab66;
P_0c0aab66: /* original 03ed, guest PC 0x0c0aab66 */
if(!s->budget--) { s->failed_pc=0x0c0aab66u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aab68;
P_0c0aab68: /* original 633d, guest PC 0x0c0aab68 */
if(!s->budget--) { s->failed_pc=0x0c0aab68u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0aab6a;
P_0c0aab6a: /* original 2378, guest PC 0x0c0aab6a */
if(!s->budget--) { s->failed_pc=0x0c0aab6au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c0aab6c;
P_0c0aab6c: /* original 8b04, guest PC 0x0c0aab6c */
if(!s->budget--) { s->failed_pc=0x0c0aab6cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aab78; }
goto P_0c0aab6e;
P_0c0aab6e: /* original d324, guest PC 0x0c0aab6e */
if(!s->budget--) { s->failed_pc=0x0c0aab6eu; return 0; }
r[3]=read(ram,0x0c0aac00u,4);
goto P_0c0aab70;
P_0c0aab70: /* original 430b, guest PC 0x0c0aab70 */
if(!s->budget--) { s->failed_pc=0x0c0aab70u; return 0; }
target=r[3];
r[16]=code_base|0x0c0aab74u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aab74u) { target=s->pc; goto dispatch; }
goto P_0c0aab74;
P_0c0aab72: /* original 64e3, guest PC 0x0c0aab72 */
if(!s->budget--) { s->failed_pc=0x0c0aab72u; return 0; }
r[4]=r[14];
goto P_0c0aab74;
P_0c0aab74: /* original a021, guest PC 0x0c0aab74 */
if(!s->budget--) { s->failed_pc=0x0c0aab74u; return 0; }
goto P_0c0aabba;
P_0c0aab76: /* original 0009, guest PC 0x0c0aab76 */
if(!s->budget--) { s->failed_pc=0x0c0aab76u; return 0; }
goto P_0c0aab78;
P_0c0aab78: /* original 8547, guest PC 0x0c0aab78 */
if(!s->budget--) { s->failed_pc=0x0c0aab78u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+14,2);
goto P_0c0aab7a;
P_0c0aab7a: /* original d322, guest PC 0x0c0aab7a */
if(!s->budget--) { s->failed_pc=0x0c0aab7au; return 0; }
r[3]=read(ram,0x0c0aac04u,4);
goto P_0c0aab7c;
P_0c0aab7c: /* original 650d, guest PC 0x0c0aab7c */
if(!s->budget--) { s->failed_pc=0x0c0aab7cu; return 0; }
r[5]=r[0]&65535u;
goto P_0c0aab7e;
P_0c0aab7e: /* original 430b, guest PC 0x0c0aab7e */
if(!s->budget--) { s->failed_pc=0x0c0aab7eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0aab82u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aab82u) { target=s->pc; goto dispatch; }
goto P_0c0aab82;
P_0c0aab80: /* original 64e3, guest PC 0x0c0aab80 */
if(!s->budget--) { s->failed_pc=0x0c0aab80u; return 0; }
r[4]=r[14];
goto P_0c0aab82;
P_0c0aab82: /* original a01a, guest PC 0x0c0aab82 */
if(!s->budget--) { s->failed_pc=0x0c0aab82u; return 0; }
goto P_0c0aabba;
P_0c0aab84: /* original 0009, guest PC 0x0c0aab84 */
if(!s->budget--) { s->failed_pc=0x0c0aab84u; return 0; }
goto P_0c0aab86;
P_0c0aab86: /* original 2558, guest PC 0x0c0aab86 */
if(!s->budget--) { s->failed_pc=0x0c0aab86u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0aab88;
P_0c0aab88: /* original 8b25, guest PC 0x0c0aab88 */
if(!s->budget--) { s->failed_pc=0x0c0aab88u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aabd6; }
goto P_0c0aab8a;
P_0c0aab8a: /* original 9034, guest PC 0x0c0aab8a */
if(!s->budget--) { s->failed_pc=0x0c0aab8au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aabf6u,2);
goto P_0c0aab8c;
P_0c0aab8c: /* original 02ed, guest PC 0x0c0aab8c */
if(!s->budget--) { s->failed_pc=0x0c0aab8cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aab8e;
P_0c0aab8e: /* original 622d, guest PC 0x0c0aab8e */
if(!s->budget--) { s->failed_pc=0x0c0aab8eu; return 0; }
r[2]=r[2]&65535u;
goto P_0c0aab90;
P_0c0aab90: /* original 2278, guest PC 0x0c0aab90 */
if(!s->budget--) { s->failed_pc=0x0c0aab90u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[7])==0)!=0);
goto P_0c0aab92;
P_0c0aab92: /* original 8b20, guest PC 0x0c0aab92 */
if(!s->budget--) { s->failed_pc=0x0c0aab92u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aabd6; }
goto P_0c0aab94;
P_0c0aab94: /* original 8547, guest PC 0x0c0aab94 */
if(!s->budget--) { s->failed_pc=0x0c0aab94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+14,2);
goto P_0c0aab96;
P_0c0aab96: /* original d31c, guest PC 0x0c0aab96 */
if(!s->budget--) { s->failed_pc=0x0c0aab96u; return 0; }
r[3]=read(ram,0x0c0aac08u,4);
goto P_0c0aab98;
P_0c0aab98: /* original 650d, guest PC 0x0c0aab98 */
if(!s->budget--) { s->failed_pc=0x0c0aab98u; return 0; }
r[5]=r[0]&65535u;
goto P_0c0aab9a;
P_0c0aab9a: /* original 902d, guest PC 0x0c0aab9a */
if(!s->budget--) { s->failed_pc=0x0c0aab9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aabf8u,2);
goto P_0c0aab9c;
P_0c0aab9c: /* original 02ee, guest PC 0x0c0aab9c */
if(!s->budget--) { s->failed_pc=0x0c0aab9cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0aab9e;
P_0c0aab9e: /* original 2238, guest PC 0x0c0aab9e */
if(!s->budget--) { s->failed_pc=0x0c0aab9eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aaba0;
P_0c0aaba0: /* original 8b19, guest PC 0x0c0aaba0 */
if(!s->budget--) { s->failed_pc=0x0c0aaba0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aabd6; }
goto P_0c0aaba2;
P_0c0aaba2: /* original d31a, guest PC 0x0c0aaba2 */
if(!s->budget--) { s->failed_pc=0x0c0aaba2u; return 0; }
r[3]=read(ram,0x0c0aac0cu,4);
goto P_0c0aaba4;
P_0c0aaba4: /* original 430b, guest PC 0x0c0aaba4 */
if(!s->budget--) { s->failed_pc=0x0c0aaba4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0aaba8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aaba8u) { target=s->pc; goto dispatch; }
goto P_0c0aaba8;
P_0c0aaba6: /* original 64e3, guest PC 0x0c0aaba6 */
if(!s->budget--) { s->failed_pc=0x0c0aaba6u; return 0; }
r[4]=r[14];
goto P_0c0aaba8;
P_0c0aaba8: /* original a007, guest PC 0x0c0aaba8 */
if(!s->budget--) { s->failed_pc=0x0c0aaba8u; return 0; }
goto P_0c0aabba;
P_0c0aabaa: /* original 0009, guest PC 0x0c0aabaa */
if(!s->budget--) { s->failed_pc=0x0c0aabaau; return 0; }
goto P_0c0aabac;
P_0c0aabac: /* original 2558, guest PC 0x0c0aabac */
if(!s->budget--) { s->failed_pc=0x0c0aabacu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0aabae;
P_0c0aabae: /* original 8b0b, guest PC 0x0c0aabae */
if(!s->budget--) { s->failed_pc=0x0c0aabaeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aabc8; }
goto P_0c0aabb0;
P_0c0aabb0: /* original 9021, guest PC 0x0c0aabb0 */
if(!s->budget--) { s->failed_pc=0x0c0aabb0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aabf6u,2);
goto P_0c0aabb2;
P_0c0aabb2: /* original 02ed, guest PC 0x0c0aabb2 */
if(!s->budget--) { s->failed_pc=0x0c0aabb2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aabb4;
P_0c0aabb4: /* original 622d, guest PC 0x0c0aabb4 */
if(!s->budget--) { s->failed_pc=0x0c0aabb4u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0aabb6;
P_0c0aabb6: /* original 2278, guest PC 0x0c0aabb6 */
if(!s->budget--) { s->failed_pc=0x0c0aabb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[7])==0)!=0);
goto P_0c0aabb8;
P_0c0aabb8: /* original 8b18, guest PC 0x0c0aabb8 */
if(!s->budget--) { s->failed_pc=0x0c0aabb8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aabec; }
goto P_0c0aabba;
P_0c0aabba: /* original 65f2, guest PC 0x0c0aabba */
if(!s->budget--) { s->failed_pc=0x0c0aabbau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0aabbc;
P_0c0aabbc: /* original 7f04, guest PC 0x0c0aabbc */
if(!s->budget--) { s->failed_pc=0x0c0aabbcu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aabbe;
P_0c0aabbe: /* original 4f26, guest PC 0x0c0aabbe */
if(!s->budget--) { s->failed_pc=0x0c0aabbeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aabc0;
P_0c0aabc0: /* original 64e3, guest PC 0x0c0aabc0 */
if(!s->budget--) { s->failed_pc=0x0c0aabc0u; return 0; }
r[4]=r[14];
goto P_0c0aabc2;
P_0c0aabc2: /* original 6df6, guest PC 0x0c0aabc2 */
if(!s->budget--) { s->failed_pc=0x0c0aabc2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aabc4;
P_0c0aabc4: /* original aded, guest PC 0x0c0aabc4 */
if(!s->budget--) { s->failed_pc=0x0c0aabc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aa7a2;
P_0c0aabc6: /* original 6ef6, guest PC 0x0c0aabc6 */
if(!s->budget--) { s->failed_pc=0x0c0aabc6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aabc8;
P_0c0aabc8: /* original 6543, guest PC 0x0c0aabc8 */
if(!s->budget--) { s->failed_pc=0x0c0aabc8u; return 0; }
r[5]=r[4];
goto P_0c0aabca;
P_0c0aabca: /* original d311, guest PC 0x0c0aabca */
if(!s->budget--) { s->failed_pc=0x0c0aabcau; return 0; }
r[3]=read(ram,0x0c0aac10u,4);
goto P_0c0aabcc;
P_0c0aabcc: /* original 7546, guest PC 0x0c0aabcc */
if(!s->budget--) { s->failed_pc=0x0c0aabccu; return 0; }
r[5]+=0x00000046u;
goto P_0c0aabce;
P_0c0aabce: /* original 6551, guest PC 0x0c0aabce */
if(!s->budget--) { s->failed_pc=0x0c0aabceu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0aabd0;
P_0c0aabd0: /* original 2638, guest PC 0x0c0aabd0 */
if(!s->budget--) { s->failed_pc=0x0c0aabd0u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0aabd2;
P_0c0aabd2: /* original 8d04, guest PC 0x0c0aabd2 */
if(!s->budget--) { s->failed_pc=0x0c0aabd2u; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(cond) { goto P_0c0aabde; }
goto P_0c0aabd6;
P_0c0aabd4: /* original 655d, guest PC 0x0c0aabd4 */
if(!s->budget--) { s->failed_pc=0x0c0aabd4u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0aabd6;
P_0c0aabd6: /* original 6543, guest PC 0x0c0aabd6 */
if(!s->budget--) { s->failed_pc=0x0c0aabd6u; return 0; }
r[5]=r[4];
goto P_0c0aabd8;
P_0c0aabd8: /* original 7544, guest PC 0x0c0aabd8 */
if(!s->budget--) { s->failed_pc=0x0c0aabd8u; return 0; }
r[5]+=0x00000044u;
goto P_0c0aabda;
P_0c0aabda: /* original 6551, guest PC 0x0c0aabda */
if(!s->budget--) { s->failed_pc=0x0c0aabdau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0aabdc;
P_0c0aabdc: /* original 655d, guest PC 0x0c0aabdc */
if(!s->budget--) { s->failed_pc=0x0c0aabdcu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0aabde;
P_0c0aabde: /* original 7f04, guest PC 0x0c0aabde */
if(!s->budget--) { s->failed_pc=0x0c0aabdeu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aabe0;
P_0c0aabe0: /* original d307, guest PC 0x0c0aabe0 */
if(!s->budget--) { s->failed_pc=0x0c0aabe0u; return 0; }
r[3]=read(ram,0x0c0aac00u,4);
goto P_0c0aabe2;
P_0c0aabe2: /* original 4f26, guest PC 0x0c0aabe2 */
if(!s->budget--) { s->failed_pc=0x0c0aabe2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aabe4;
P_0c0aabe4: /* original 64e3, guest PC 0x0c0aabe4 */
if(!s->budget--) { s->failed_pc=0x0c0aabe4u; return 0; }
r[4]=r[14];
goto P_0c0aabe6;
P_0c0aabe6: /* original 6df6, guest PC 0x0c0aabe6 */
if(!s->budget--) { s->failed_pc=0x0c0aabe6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aabe8;
P_0c0aabe8: /* original 432b, guest PC 0x0c0aabe8 */
if(!s->budget--) { s->failed_pc=0x0c0aabe8u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0aabea: /* original 6ef6, guest PC 0x0c0aabea */
if(!s->budget--) { s->failed_pc=0x0c0aabeau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aabec;
P_0c0aabec: /* original 7f04, guest PC 0x0c0aabec */
if(!s->budget--) { s->failed_pc=0x0c0aabecu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aabee;
P_0c0aabee: /* original 4f26, guest PC 0x0c0aabee */
if(!s->budget--) { s->failed_pc=0x0c0aabeeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aabf0;
P_0c0aabf0: /* original 6df6, guest PC 0x0c0aabf0 */
if(!s->budget--) { s->failed_pc=0x0c0aabf0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aabf2;
P_0c0aabf2: /* original 000b, guest PC 0x0c0aabf2 */
if(!s->budget--) { s->failed_pc=0x0c0aabf2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0aabf4: /* original 6ef6, guest PC 0x0c0aabf4 */
if(!s->budget--) { s->failed_pc=0x0c0aabf4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0aabf6u,s,ram);
P_0c0c6298: /* original 4f22, guest PC 0x0c0c6298 */
if(!s->budget--) { s->failed_pc=0x0c0c6298u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c629a;
P_0c0c629a: /* original dd3b, guest PC 0x0c0c629a */
if(!s->budget--) { s->failed_pc=0x0c0c629au; return 0; }
r[13]=read(ram,0x0c0c6388u,4);
goto P_0c0c629c;
P_0c0c629c: /* original 7ffc, guest PC 0x0c0c629c */
if(!s->budget--) { s->failed_pc=0x0c0c629cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c629e;
P_0c0c629e: /* original 8b3c, guest PC 0x0c0c629e */
if(!s->budget--) { s->failed_pc=0x0c0c629eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c631a; }
goto P_0c0c62a0;
P_0c0c62a0: /* original 926e, guest PC 0x0c0c62a0 */
if(!s->budget--) { s->failed_pc=0x0c0c62a0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6380u,2);
goto P_0c0c62a2;
P_0c0c62a2: /* original 3423, guest PC 0x0c0c62a2 */
if(!s->budget--) { s->failed_pc=0x0c0c62a2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0c62a4;
P_0c0c62a4: /* original 8939, guest PC 0x0c0c62a4 */
if(!s->budget--) { s->failed_pc=0x0c0c62a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c631a; }
goto P_0c0c62a6;
P_0c0c62a6: /* original d339, guest PC 0x0c0c62a6 */
if(!s->budget--) { s->failed_pc=0x0c0c62a6u; return 0; }
r[3]=read(ram,0x0c0c638cu,4);
goto P_0c0c62a8;
P_0c0c62a8: /* original 6a43, guest PC 0x0c0c62a8 */
if(!s->budget--) { s->failed_pc=0x0c0c62a8u; return 0; }
r[10]=r[4];
goto P_0c0c62aa;
P_0c0c62aa: /* original 4a08, guest PC 0x0c0c62aa */
if(!s->budget--) { s->failed_pc=0x0c0c62aau; return 0; }
r[10]<<=2;
goto P_0c0c62ac;
P_0c0c62ac: /* original 3a3c, guest PC 0x0c0c62ac */
if(!s->budget--) { s->failed_pc=0x0c0c62acu; return 0; }
r[10]+=r[3];
goto P_0c0c62ae;
P_0c0c62ae: /* original 62a2, guest PC 0x0c0c62ae */
if(!s->budget--) { s->failed_pc=0x0c0c62aeu; return 0; }
tmp=read(ram,r[10],4);
r[2]=tmp;
goto P_0c0c62b0;
P_0c0c62b0: /* original 4211, guest PC 0x0c0c62b0 */
if(!s->budget--) { s->failed_pc=0x0c0c62b0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c0c62b2;
P_0c0c62b2: /* original 8b32, guest PC 0x0c0c62b2 */
if(!s->budget--) { s->failed_pc=0x0c0c62b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c631a; }
goto P_0c0c62b4;
P_0c0c62b4: /* original d337, guest PC 0x0c0c62b4 */
if(!s->budget--) { s->failed_pc=0x0c0c62b4u; return 0; }
r[3]=read(ram,0x0c0c6394u,4);
goto P_0c0c62b6;
P_0c0c62b6: /* original ec00, guest PC 0x0c0c62b6 */
if(!s->budget--) { s->failed_pc=0x0c0c62b6u; return 0; }
r[12]=0x00000000u;
goto P_0c0c62b8;
P_0c0c62b8: /* original d935, guest PC 0x0c0c62b8 */
if(!s->budget--) { s->failed_pc=0x0c0c62b8u; return 0; }
r[9]=read(ram,0x0c0c6390u,4);
goto P_0c0c62ba;
P_0c0c62ba: /* original 65c3, guest PC 0x0c0c62ba */
if(!s->budget--) { s->failed_pc=0x0c0c62bau; return 0; }
r[5]=r[12];
goto P_0c0c62bc;
P_0c0c62bc: /* original 234b, guest PC 0x0c0c62bc */
if(!s->budget--) { s->failed_pc=0x0c0c62bcu; return 0; }
r[3]|=r[4];
goto P_0c0c62be;
P_0c0c62be: /* original 2f32, guest PC 0x0c0c62be */
if(!s->budget--) { s->failed_pc=0x0c0c62beu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c62c0;
P_0c0c62c0: /* original d635, guest PC 0x0c0c62c0 */
if(!s->budget--) { s->failed_pc=0x0c0c62c0u; return 0; }
r[6]=read(ram,0x0c0c6398u,4);
goto P_0c0c62c2;
P_0c0c62c2: /* original 9b5e, guest PC 0x0c0c62c2 */
if(!s->budget--) { s->failed_pc=0x0c0c62c2u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6382u,2);
goto P_0c0c62c4;
P_0c0c62c4: /* original d835, guest PC 0x0c0c62c4 */
if(!s->budget--) { s->failed_pc=0x0c0c62c4u; return 0; }
r[8]=read(ram,0x0c0c639cu,4);
goto P_0c0c62c6;
P_0c0c62c6: /* original 6e53, guest PC 0x0c0c62c6 */
if(!s->budget--) { s->failed_pc=0x0c0c62c6u; return 0; }
r[14]=r[5];
goto P_0c0c62c8;
P_0c0c62c8: /* original 4e08, guest PC 0x0c0c62c8 */
if(!s->budget--) { s->failed_pc=0x0c0c62c8u; return 0; }
r[14]<<=2;
goto P_0c0c62ca;
P_0c0c62ca: /* original 4e00, guest PC 0x0c0c62ca */
if(!s->budget--) { s->failed_pc=0x0c0c62cau; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c0c62cc;
P_0c0c62cc: /* original 3e6c, guest PC 0x0c0c62cc */
if(!s->budget--) { s->failed_pc=0x0c0c62ccu; return 0; }
r[14]+=r[6];
goto P_0c0c62ce;
P_0c0c62ce: /* original 53e1, guest PC 0x0c0c62ce */
if(!s->budget--) { s->failed_pc=0x0c0c62ceu; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0c62d0;
P_0c0c62d0: /* original 2338, guest PC 0x0c0c62d0 */
if(!s->budget--) { s->failed_pc=0x0c0c62d0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c62d2;
P_0c0c62d2: /* original 8922, guest PC 0x0c0c62d2 */
if(!s->budget--) { s->failed_pc=0x0c0c62d2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c631a; }
goto P_0c0c62d4;
P_0c0c62d4: /* original 52e1, guest PC 0x0c0c62d4 */
if(!s->budget--) { s->failed_pc=0x0c0c62d4u; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0c62d6;
P_0c0c62d6: /* original 3420, guest PC 0x0c0c62d6 */
if(!s->budget--) { s->failed_pc=0x0c0c62d6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c0c62d8;
P_0c0c62d8: /* original 8b1d, guest PC 0x0c0c62d8 */
if(!s->budget--) { s->failed_pc=0x0c0c62d8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6316; }
goto P_0c0c62da;
P_0c0c62da: /* original 6392, guest PC 0x0c0c62da */
if(!s->budget--) { s->failed_pc=0x0c0c62dau; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c0c62dc;
P_0c0c62dc: /* original 61e2, guest PC 0x0c0c62dc */
if(!s->budget--) { s->failed_pc=0x0c0c62dcu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0c62de;
P_0c0c62de: /* original 3310, guest PC 0x0c0c62de */
if(!s->budget--) { s->failed_pc=0x0c0c62deu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c0c62e0;
P_0c0c62e0: /* original 8912, guest PC 0x0c0c62e0 */
if(!s->budget--) { s->failed_pc=0x0c0c62e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6308; }
goto P_0c0c62e2;
P_0c0c62e2: /* original 2fb6, guest PC 0x0c0c62e2 */
if(!s->budget--) { s->failed_pc=0x0c0c62e2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c62e4;
P_0c0c62e4: /* original d32e, guest PC 0x0c0c62e4 */
if(!s->budget--) { s->failed_pc=0x0c0c62e4u; return 0; }
r[3]=read(ram,0x0c0c63a0u,4);
goto P_0c0c62e6;
P_0c0c62e6: /* original 2f36, guest PC 0x0c0c62e6 */
if(!s->budget--) { s->failed_pc=0x0c0c62e6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c62e8;
P_0c0c62e8: /* original 52f2, guest PC 0x0c0c62e8 */
if(!s->budget--) { s->failed_pc=0x0c0c62e8u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0c62ea;
P_0c0c62ea: /* original 2f26, guest PC 0x0c0c62ea */
if(!s->budget--) { s->failed_pc=0x0c0c62eau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c62ec;
P_0c0c62ec: /* original d22f, guest PC 0x0c0c62ec */
if(!s->budget--) { s->failed_pc=0x0c0c62ecu; return 0; }
r[2]=read(ram,0x0c0c63acu,4);
goto P_0c0c62ee;
P_0c0c62ee: /* original d130, guest PC 0x0c0c62ee */
if(!s->budget--) { s->failed_pc=0x0c0c62eeu; return 0; }
r[1]=read(ram,0x0c0c63b0u,4);
goto P_0c0c62f0;
P_0c0c62f0: /* original 6522, guest PC 0x0c0c62f0 */
if(!s->budget--) { s->failed_pc=0x0c0c62f0u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c0c62f2;
P_0c0c62f2: /* original d72c, guest PC 0x0c0c62f2 */
if(!s->budget--) { s->failed_pc=0x0c0c62f2u; return 0; }
r[7]=read(ram,0x0c0c63a4u,4);
goto P_0c0c62f4;
P_0c0c62f4: /* original d62c, guest PC 0x0c0c62f4 */
if(!s->budget--) { s->failed_pc=0x0c0c62f4u; return 0; }
r[6]=read(ram,0x0c0c63a8u,4);
goto P_0c0c62f6;
P_0c0c62f6: /* original 358c, guest PC 0x0c0c62f6 */
if(!s->budget--) { s->failed_pc=0x0c0c62f6u; return 0; }
r[5]+=r[8];
goto P_0c0c62f8;
P_0c0c62f8: /* original 410b, guest PC 0x0c0c62f8 */
if(!s->budget--) { s->failed_pc=0x0c0c62f8u; return 0; }
target=r[1];
r[16]=code_base|0x0c0c62fcu;
tmp=read(ram,r[14],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c62fcu) { target=s->pc; goto dispatch; }
goto P_0c0c62fc;
P_0c0c62fa: /* original 64e2, guest PC 0x0c0c62fa */
if(!s->budget--) { s->failed_pc=0x0c0c62fau; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0c62fc;
P_0c0c62fc: /* original 63e2, guest PC 0x0c0c62fc */
if(!s->budget--) { s->failed_pc=0x0c0c62fcu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0c62fe;
P_0c0c62fe: /* original 7f0c, guest PC 0x0c0c62fe */
if(!s->budget--) { s->failed_pc=0x0c0c62feu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0c6300;
P_0c0c6300: /* original 2932, guest PC 0x0c0c6300 */
if(!s->budget--) { s->failed_pc=0x0c0c6300u; return 0; }
write(ram,r[9],r[3],4);
goto P_0c0c6302;
P_0c0c6302: /* original 903f, guest PC 0x0c0c6302 */
if(!s->budget--) { s->failed_pc=0x0c0c6302u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6384u,2);
goto P_0c0c6304;
P_0c0c6304: /* original a009, guest PC 0x0c0c6304 */
if(!s->budget--) { s->failed_pc=0x0c0c6304u; return 0; }
write(ram,r[13]+r[0],r[12],4);
goto P_0c0c631a;
P_0c0c6306: /* original 0dc6, guest PC 0x0c0c6306 */
if(!s->budget--) { s->failed_pc=0x0c0c6306u; return 0; }
write(ram,r[13]+r[0],r[12],4);
goto P_0c0c6308;
P_0c0c6308: /* original d22a, guest PC 0x0c0c6308 */
if(!s->budget--) { s->failed_pc=0x0c0c6308u; return 0; }
r[2]=read(ram,0x0c0c63b4u,4);
goto P_0c0c630a;
P_0c0c630a: /* original 420b, guest PC 0x0c0c630a */
if(!s->budget--) { s->failed_pc=0x0c0c630au; return 0; }
target=r[2];
r[16]=code_base|0x0c0c630eu;
tmp=read(ram,r[10],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c630eu) { target=s->pc; goto dispatch; }
goto P_0c0c630e;
P_0c0c630c: /* original 64a2, guest PC 0x0c0c630c */
if(!s->budget--) { s->failed_pc=0x0c0c630cu; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c0c630e;
P_0c0c630e: /* original 9039, guest PC 0x0c0c630e */
if(!s->budget--) { s->failed_pc=0x0c0c630eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6384u,2);
goto P_0c0c6310;
P_0c0c6310: /* original e3ff, guest PC 0x0c0c6310 */
if(!s->budget--) { s->failed_pc=0x0c0c6310u; return 0; }
r[3]=0xffffffffu;
goto P_0c0c6312;
P_0c0c6312: /* original a002, guest PC 0x0c0c6312 */
if(!s->budget--) { s->failed_pc=0x0c0c6312u; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c0c631a;
P_0c0c6314: /* original 0d36, guest PC 0x0c0c6314 */
if(!s->budget--) { s->failed_pc=0x0c0c6314u; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c0c6316;
P_0c0c6316: /* original afd6, guest PC 0x0c0c6316 */
if(!s->budget--) { s->failed_pc=0x0c0c6316u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c62c6;
P_0c0c6318: /* original 7501, guest PC 0x0c0c6318 */
if(!s->budget--) { s->failed_pc=0x0c0c6318u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c631a;
P_0c0c631a: /* original 7f04, guest PC 0x0c0c631a */
if(!s->budget--) { s->failed_pc=0x0c0c631au; return 0; }
r[15]+=0x00000004u;
goto P_0c0c631c;
P_0c0c631c: /* original 4f26, guest PC 0x0c0c631c */
if(!s->budget--) { s->failed_pc=0x0c0c631cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c631e;
P_0c0c631e: /* original 68f6, guest PC 0x0c0c631e */
if(!s->budget--) { s->failed_pc=0x0c0c631eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c6320;
P_0c0c6320: /* original 69f6, guest PC 0x0c0c6320 */
if(!s->budget--) { s->failed_pc=0x0c0c6320u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c6322;
P_0c0c6322: /* original 6af6, guest PC 0x0c0c6322 */
if(!s->budget--) { s->failed_pc=0x0c0c6322u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c6324;
P_0c0c6324: /* original 6bf6, guest PC 0x0c0c6324 */
if(!s->budget--) { s->failed_pc=0x0c0c6324u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c6326;
P_0c0c6326: /* original 6cf6, guest PC 0x0c0c6326 */
if(!s->budget--) { s->failed_pc=0x0c0c6326u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c6328;
P_0c0c6328: /* original 6df6, guest PC 0x0c0c6328 */
if(!s->budget--) { s->failed_pc=0x0c0c6328u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c632a;
P_0c0c632a: /* original 000b, guest PC 0x0c0c632a */
if(!s->budget--) { s->failed_pc=0x0c0c632au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c632c: /* original 6ef6, guest PC 0x0c0c632c */
if(!s->budget--) { s->failed_pc=0x0c0c632cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c632eu,s,ram);
P_0c0c8644: /* original 4f22, guest PC 0x0c0c8644 */
if(!s->budget--) { s->failed_pc=0x0c0c8644u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c8646;
P_0c0c8646: /* original d33f, guest PC 0x0c0c8646 */
if(!s->budget--) { s->failed_pc=0x0c0c8646u; return 0; }
r[3]=read(ram,0x0c0c8744u,4);
goto P_0c0c8648;
P_0c0c8648: /* original 6212, guest PC 0x0c0c8648 */
if(!s->budget--) { s->failed_pc=0x0c0c8648u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0c864a;
P_0c0c864a: /* original d53d, guest PC 0x0c0c864a */
if(!s->budget--) { s->failed_pc=0x0c0c864au; return 0; }
r[5]=read(ram,0x0c0c8740u,4);
goto P_0c0c864c;
P_0c0c864c: /* original 7ff4, guest PC 0x0c0c864c */
if(!s->budget--) { s->failed_pc=0x0c0c864cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0c864e;
P_0c0c864e: /* original 2238, guest PC 0x0c0c864e */
if(!s->budget--) { s->failed_pc=0x0c0c864eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c8650;
P_0c0c8650: /* original 8b3f, guest PC 0x0c0c8650 */
if(!s->budget--) { s->failed_pc=0x0c0c8650u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c86d2; }
goto P_0c0c8652;
P_0c0c8652: /* original 8458, guest PC 0x0c0c8652 */
if(!s->budget--) { s->failed_pc=0x0c0c8652u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+8,1);
goto P_0c0c8654;
P_0c0c8654: /* original 600c, guest PC 0x0c0c8654 */
if(!s->budget--) { s->failed_pc=0x0c0c8654u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c8656;
P_0c0c8656: /* original 8807, guest PC 0x0c0c8656 */
if(!s->budget--) { s->failed_pc=0x0c0c8656u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0c8658;
P_0c0c8658: /* original 8b3b, guest PC 0x0c0c8658 */
if(!s->budget--) { s->failed_pc=0x0c0c8658u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c86d2; }
goto P_0c0c865a;
P_0c0c865a: /* original 9069, guest PC 0x0c0c865a */
if(!s->budget--) { s->failed_pc=0x0c0c865au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8730u,2);
goto P_0c0c865c;
P_0c0c865c: /* original 0e4e, guest PC 0x0c0c865c */
if(!s->budget--) { s->failed_pc=0x0c0c865cu; return 0; }
r[14]=read(ram,r[4]+r[0],4);
goto P_0c0c865e;
P_0c0c865e: /* original 7004, guest PC 0x0c0c865e */
if(!s->budget--) { s->failed_pc=0x0c0c865eu; return 0; }
r[0]+=0x00000004u;
goto P_0c0c8660;
P_0c0c8660: /* original 034e, guest PC 0x0c0c8660 */
if(!s->budget--) { s->failed_pc=0x0c0c8660u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0c8662;
P_0c0c8662: /* original 1f32, guest PC 0x0c0c8662 */
if(!s->budget--) { s->failed_pc=0x0c0c8662u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0c8664;
P_0c0c8664: /* original 9065, guest PC 0x0c0c8664 */
if(!s->budget--) { s->failed_pc=0x0c0c8664u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8732u,2);
goto P_0c0c8666;
P_0c0c8666: /* original 024c, guest PC 0x0c0c8666 */
if(!s->budget--) { s->failed_pc=0x0c0c8666u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c8668;
P_0c0c8668: /* original 2f22, guest PC 0x0c0c8668 */
if(!s->budget--) { s->failed_pc=0x0c0c8668u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c866a;
P_0c0c866a: /* original 6342, guest PC 0x0c0c866a */
if(!s->budget--) { s->failed_pc=0x0c0c866au; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0c866c;
P_0c0c866c: /* original 1f31, guest PC 0x0c0c866c */
if(!s->budget--) { s->failed_pc=0x0c0c866cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c866e;
P_0c0c866e: /* original 8459, guest PC 0x0c0c866e */
if(!s->budget--) { s->failed_pc=0x0c0c866eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+9,1);
goto P_0c0c8670;
P_0c0c8670: /* original 600c, guest PC 0x0c0c8670 */
if(!s->budget--) { s->failed_pc=0x0c0c8670u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c8672;
P_0c0c8672: /* original 880b, guest PC 0x0c0c8672 */
if(!s->budget--) { s->failed_pc=0x0c0c8672u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0c8674;
P_0c0c8674: /* original 8924, guest PC 0x0c0c8674 */
if(!s->budget--) { s->failed_pc=0x0c0c8674u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c86c0; }
goto P_0c0c8676;
P_0c0c8676: /* original 905d, guest PC 0x0c0c8676 */
if(!s->budget--) { s->failed_pc=0x0c0c8676u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8734u,2);
goto P_0c0c8678;
P_0c0c8678: /* original 055e, guest PC 0x0c0c8678 */
if(!s->budget--) { s->failed_pc=0x0c0c8678u; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c0c867a;
P_0c0c867a: /* original 84e4, guest PC 0x0c0c867a */
if(!s->budget--) { s->failed_pc=0x0c0c867au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c867c;
P_0c0c867c: /* original 2008, guest PC 0x0c0c867c */
if(!s->budget--) { s->failed_pc=0x0c0c867cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c867e;
P_0c0c867e: /* original 8b04, guest PC 0x0c0c867e */
if(!s->budget--) { s->failed_pc=0x0c0c867eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c868a; }
goto P_0c0c8680;
P_0c0c8680: /* original d232, guest PC 0x0c0c8680 */
if(!s->budget--) { s->failed_pc=0x0c0c8680u; return 0; }
r[2]=read(ram,0x0c0c874cu,4);
goto P_0c0c8682;
P_0c0c8682: /* original 2528, guest PC 0x0c0c8682 */
if(!s->budget--) { s->failed_pc=0x0c0c8682u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c0c8684;
P_0c0c8684: /* original 891c, guest PC 0x0c0c8684 */
if(!s->budget--) { s->failed_pc=0x0c0c8684u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c86c0; }
goto P_0c0c8686;
P_0c0c8686: /* original a003, guest PC 0x0c0c8686 */
if(!s->budget--) { s->failed_pc=0x0c0c8686u; return 0; }
goto P_0c0c8690;
P_0c0c8688: /* original 0009, guest PC 0x0c0c8688 */
if(!s->budget--) { s->failed_pc=0x0c0c8688u; return 0; }
goto P_0c0c868a;
P_0c0c868a: /* original d131, guest PC 0x0c0c868a */
if(!s->budget--) { s->failed_pc=0x0c0c868au; return 0; }
r[1]=read(ram,0x0c0c8750u,4);
goto P_0c0c868c;
P_0c0c868c: /* original 2518, guest PC 0x0c0c868c */
if(!s->budget--) { s->failed_pc=0x0c0c868cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[1])==0)!=0);
goto P_0c0c868e;
P_0c0c868e: /* original 8917, guest PC 0x0c0c868e */
if(!s->budget--) { s->failed_pc=0x0c0c868eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c86c0; }
goto P_0c0c8690;
P_0c0c8690: /* original 63f2, guest PC 0x0c0c8690 */
if(!s->budget--) { s->failed_pc=0x0c0c8690u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c8692;
P_0c0c8692: /* original 7301, guest PC 0x0c0c8692 */
if(!s->budget--) { s->failed_pc=0x0c0c8692u; return 0; }
r[3]+=0x00000001u;
goto P_0c0c8694;
P_0c0c8694: /* original 2f32, guest PC 0x0c0c8694 */
if(!s->budget--) { s->failed_pc=0x0c0c8694u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c8696;
P_0c0c8696: /* original e304, guest PC 0x0c0c8696 */
if(!s->budget--) { s->failed_pc=0x0c0c8696u; return 0; }
r[3]=0x00000004u;
goto P_0c0c8698;
P_0c0c8698: /* original d22e, guest PC 0x0c0c8698 */
if(!s->budget--) { s->failed_pc=0x0c0c8698u; return 0; }
r[2]=read(ram,0x0c0c8754u,4);
goto P_0c0c869a;
P_0c0c869a: /* original 51f1, guest PC 0x0c0c869a */
if(!s->budget--) { s->failed_pc=0x0c0c869au; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0c869c;
P_0c0c869c: /* original 2129, guest PC 0x0c0c869c */
if(!s->budget--) { s->failed_pc=0x0c0c869cu; return 0; }
r[1]&=r[2];
goto P_0c0c869e;
P_0c0c869e: /* original 1f11, guest PC 0x0c0c869e */
if(!s->budget--) { s->failed_pc=0x0c0c869eu; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0c86a0;
P_0c0c86a0: /* original 60f2, guest PC 0x0c0c86a0 */
if(!s->budget--) { s->failed_pc=0x0c0c86a0u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0c86a2;
P_0c0c86a2: /* original 3033, guest PC 0x0c0c86a2 */
if(!s->budget--) { s->failed_pc=0x0c0c86a2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=(int32_t)r[3])!=0);
goto P_0c0c86a4;
P_0c0c86a4: /* original 8b09, guest PC 0x0c0c86a4 */
if(!s->budget--) { s->failed_pc=0x0c0c86a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c86ba; }
goto P_0c0c86a6;
P_0c0c86a6: /* original 9046, guest PC 0x0c0c86a6 */
if(!s->budget--) { s->failed_pc=0x0c0c86a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8736u,2);
goto P_0c0c86a8;
P_0c0c86a8: /* original e102, guest PC 0x0c0c86a8 */
if(!s->budget--) { s->failed_pc=0x0c0c86a8u; return 0; }
r[1]=0x00000002u;
goto P_0c0c86aa;
P_0c0c86aa: /* original e300, guest PC 0x0c0c86aa */
if(!s->budget--) { s->failed_pc=0x0c0c86aau; return 0; }
r[3]=0x00000000u;
goto P_0c0c86ac;
P_0c0c86ac: /* original 0414, guest PC 0x0c0c86ac */
if(!s->budget--) { s->failed_pc=0x0c0c86acu; return 0; }
write(ram,r[4]+r[0],r[1],1);
goto P_0c0c86ae;
P_0c0c86ae: /* original 9040, guest PC 0x0c0c86ae */
if(!s->budget--) { s->failed_pc=0x0c0c86aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8732u,2);
goto P_0c0c86b0;
P_0c0c86b0: /* original 0434, guest PC 0x0c0c86b0 */
if(!s->budget--) { s->failed_pc=0x0c0c86b0u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c0c86b2;
P_0c0c86b2: /* original 62f2, guest PC 0x0c0c86b2 */
if(!s->budget--) { s->failed_pc=0x0c0c86b2u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c86b4;
P_0c0c86b4: /* original 72ff, guest PC 0x0c0c86b4 */
if(!s->budget--) { s->failed_pc=0x0c0c86b4u; return 0; }
r[2]+=0xffffffffu;
goto P_0c0c86b6;
P_0c0c86b6: /* original a003, guest PC 0x0c0c86b6 */
if(!s->budget--) { s->failed_pc=0x0c0c86b6u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c86c0;
P_0c0c86b8: /* original 2f22, guest PC 0x0c0c86b8 */
if(!s->budget--) { s->failed_pc=0x0c0c86b8u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c86ba;
P_0c0c86ba: /* original 903a, guest PC 0x0c0c86ba */
if(!s->budget--) { s->failed_pc=0x0c0c86bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8732u,2);
goto P_0c0c86bc;
P_0c0c86bc: /* original 61f2, guest PC 0x0c0c86bc */
if(!s->budget--) { s->failed_pc=0x0c0c86bcu; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0c86be;
P_0c0c86be: /* original 0414, guest PC 0x0c0c86be */
if(!s->budget--) { s->failed_pc=0x0c0c86beu; return 0; }
write(ram,r[4]+r[0],r[1],1);
goto P_0c0c86c0;
P_0c0c86c0: /* original 63f3, guest PC 0x0c0c86c0 */
if(!s->budget--) { s->failed_pc=0x0c0c86c0u; return 0; }
r[3]=r[15];
goto P_0c0c86c2;
P_0c0c86c2: /* original 7304, guest PC 0x0c0c86c2 */
if(!s->budget--) { s->failed_pc=0x0c0c86c2u; return 0; }
r[3]+=0x00000004u;
goto P_0c0c86c4;
P_0c0c86c4: /* original 2f36, guest PC 0x0c0c86c4 */
if(!s->budget--) { s->failed_pc=0x0c0c86c4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c86c6;
P_0c0c86c6: /* original 56f3, guest PC 0x0c0c86c6 */
if(!s->budget--) { s->failed_pc=0x0c0c86c6u; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c0c86c8;
P_0c0c86c8: /* original 67f3, guest PC 0x0c0c86c8 */
if(!s->budget--) { s->failed_pc=0x0c0c86c8u; return 0; }
r[7]=r[15];
goto P_0c0c86ca;
P_0c0c86ca: /* original 7704, guest PC 0x0c0c86ca */
if(!s->budget--) { s->failed_pc=0x0c0c86cau; return 0; }
r[7]+=0x00000004u;
goto P_0c0c86cc;
P_0c0c86cc: /* original b005, guest PC 0x0c0c86cc */
if(!s->budget--) { s->failed_pc=0x0c0c86ccu; return 0; }
target=0x0c0c86dau; r[16]=code_base|0x0c0c86d0u;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c86d0u) { target=s->pc; goto dispatch; }
goto P_0c0c86d0;
P_0c0c86ce: /* original 65e3, guest PC 0x0c0c86ce */
if(!s->budget--) { s->failed_pc=0x0c0c86ceu; return 0; }
r[5]=r[14];
goto P_0c0c86d0;
P_0c0c86d0: /* original 7f04, guest PC 0x0c0c86d0 */
if(!s->budget--) { s->failed_pc=0x0c0c86d0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c86d2;
P_0c0c86d2: /* original 7f0c, guest PC 0x0c0c86d2 */
if(!s->budget--) { s->failed_pc=0x0c0c86d2u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0c86d4;
P_0c0c86d4: /* original 4f26, guest PC 0x0c0c86d4 */
if(!s->budget--) { s->failed_pc=0x0c0c86d4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c86d6;
P_0c0c86d6: /* original 000b, guest PC 0x0c0c86d6 */
if(!s->budget--) { s->failed_pc=0x0c0c86d6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c86d8: /* original 6ef6, guest PC 0x0c0c86d8 */
if(!s->budget--) { s->failed_pc=0x0c0c86d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c86dau,s,ram);
P_0c0c9c14: /* original 000b, guest PC 0x0c0c9c14 */
if(!s->budget--) { s->failed_pc=0x0c0c9c14u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c9c16: /* original 0009, guest PC 0x0c0c9c16 */
if(!s->budget--) { s->failed_pc=0x0c0c9c16u; return 0; }
return vf3_matrix_family(0x0c0c9c18u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c04df6au,0x0c04df6cu,0x0c04df6eu,0x0c04df70u,0x0c04df72u,0x0c04df74u,0x0c04df76u,0x0c04df78u,0x0c04df7au,0x0c04df7cu,0x0c04df7eu,0x0c04df80u,0x0c04df82u,0x0c04df84u,0x0c04df86u,0x0c04df88u,
0x0c04df8au,0x0c04df8cu,0x0c04df8eu,0x0c04df90u,0x0c04df92u,0x0c04df94u,0x0c04df96u,0x0c04df98u,0x0c04df9au,0x0c04df9cu,0x0c04df9eu,0x0c04dfa0u,0x0c04dfa2u,0x0c04dfa4u,0x0c04dfa6u,0x0c04dfa8u,
0x0c04dfaau,0x0c04dfacu,0x0c04dfaeu,0x0c04dfb0u,0x0c04dfb2u,0x0c04dfb4u,0x0c04dfb6u,0x0c04dfb8u,0x0c04dfbau,0x0c04dfbcu,0x0c04dfbeu,0x0c04dfc0u,0x0c04dfc2u,0x0c04dfc4u,0x0c04dfc6u,0x0c04dfc8u,
0x0c04dfcau,0x0c04dfccu,0x0c04dfceu,0x0c04dfd0u,0x0c04dfd2u,0x0c04dfd4u,0x0c04dfd6u,0x0c04dfd8u,0x0c04dfdau,0x0c04dfdcu,0x0c04e010u,0x0c04e012u,0x0c04e014u,0x0c04e016u,0x0c04e018u,0x0c04e01au,
0x0c04e01cu,0x0c04e01eu,0x0c04e020u,0x0c04e022u,0x0c04e024u,0x0c04e026u,0x0c04e028u,0x0c04e02au,0x0c0503ccu,0x0c0503ceu,0x0c0503d0u,0x0c0503d2u,0x0c0503d4u,0x0c0503d6u,0x0c0503d8u,0x0c0503dau,
0x0c0503dcu,0x0c0503deu,0x0c0503e0u,0x0c0503e2u,0x0c0503e4u,0x0c0503e6u,0x0c0503e8u,0x0c0503eau,0x0c0503ecu,0x0c0503eeu,0x0c0503f0u,0x0c0503f2u,0x0c0503f4u,0x0c0503f6u,0x0c0503f8u,0x0c0503fau,
0x0c0503fcu,0x0c0503feu,0x0c050400u,0x0c050402u,0x0c050404u,0x0c050406u,0x0c050408u,0x0c05040au,0x0c05040cu,0x0c05040eu,0x0c050410u,0x0c050412u,0x0c050414u,0x0c050416u,0x0c050418u,0x0c05041au,
0x0c05041cu,0x0c05041eu,0x0c050420u,0x0c050422u,0x0c050424u,0x0c050426u,0x0c050428u,0x0c05042au,0x0c05042cu,0x0c05042eu,0x0c050430u,0x0c050432u,0x0c050434u,0x0c050436u,0x0c050438u,0x0c05043au,
0x0c05043cu,0x0c05043eu,0x0c050440u,0x0c050442u,0x0c050444u,0x0c050446u,0x0c050448u,0x0c05044au,0x0c05044cu,0x0c05044eu,0x0c050450u,0x0c050452u,0x0c050492u,0x0c050494u,0x0c050496u,0x0c050498u,
0x0c05049au,0x0c05049cu,0x0c05049eu,0x0c0504a0u,0x0c0504a2u,0x0c0504a4u,0x0c0504a6u,0x0c0504a8u,0x0c0504aau,0x0c0504acu,0x0c0504aeu,0x0c0504b0u,0x0c0504b2u,0x0c0504b4u,0x0c0504b6u,0x0c0504b8u,
0x0c0504bau,0x0c0504bcu,0x0c0504beu,0x0c0504c0u,0x0c0504c2u,0x0c0504c4u,0x0c0504c6u,0x0c0504c8u,0x0c0504cau,0x0c0504ccu,0x0c0504ceu,0x0c0504d0u,0x0c0504d2u,0x0c0504d4u,0x0c0504d6u,0x0c0504d8u,
0x0c0504dau,0x0c0504dcu,0x0c0504deu,0x0c0504e0u,0x0c0504e2u,0x0c0504e4u,0x0c0504e6u,0x0c0504e8u,0x0c0504eau,0x0c0504ecu,0x0c0504eeu,0x0c0504f0u,0x0c0504f2u,0x0c0504f4u,0x0c0504f6u,0x0c0504f8u,
0x0c0504fau,0x0c0504fcu,0x0c0504feu,0x0c050500u,0x0c050502u,0x0c050504u,0x0c050506u,0x0c050508u,0x0c05050au,0x0c05050cu,0x0c05050eu,0x0c050510u,0x0c050512u,0x0c050514u,0x0c050516u,0x0c050518u,
0x0c062cb8u,0x0c062cbau,0x0c062cbcu,0x0c062cbeu,0x0c062cc0u,0x0c062cc2u,0x0c062cc4u,0x0c062cc6u,0x0c062cc8u,0x0c062ccau,0x0c062cccu,0x0c062cceu,0x0c062cd0u,0x0c062cd2u,0x0c062cd4u,0x0c062cd6u,
0x0c062cd8u,0x0c062cdau,0x0c062cdcu,0x0c062cdeu,0x0c062ce0u,0x0c062ce2u,0x0c062ce4u,0x0c062ce6u,0x0c062ce8u,0x0c062ceau,0x0c062cecu,0x0c062ceeu,0x0c062cf0u,0x0c062cf2u,0x0c062cf4u,0x0c062cf6u,
0x0c062cf8u,0x0c062cfau,0x0c062cfcu,0x0c062cfeu,0x0c062d00u,0x0c062d02u,0x0c062d04u,0x0c062d06u,0x0c062d08u,0x0c062d0au,0x0c062d0cu,0x0c062d0eu,0x0c062d10u,0x0c062d12u,0x0c062d14u,0x0c062d16u,
0x0c062d18u,0x0c062d1au,0x0c062d1cu,0x0c062d1eu,0x0c062d20u,0x0c062d22u,0x0c062d24u,0x0c062d26u,0x0c062d28u,0x0c062d2au,0x0c062d2cu,0x0c062d2eu,0x0c062d30u,0x0c062d32u,0x0c062d34u,0x0c062d36u,
0x0c062d38u,0x0c062d3au,0x0c062d3cu,0x0c062d3eu,0x0c062d40u,0x0c062d42u,0x0c062d44u,0x0c062d46u,0x0c062d48u,0x0c062d4au,0x0c062d4cu,0x0c076a08u,0x0c076a0au,0x0c076a0cu,0x0c076a0eu,0x0c076a10u,
0x0c076a12u,0x0c076a14u,0x0c076a16u,0x0c076a18u,0x0c076a1au,0x0c076a1cu,0x0c076a1eu,0x0c076a20u,0x0c076a22u,0x0c076a24u,0x0c076a26u,0x0c076a28u,0x0c076a2au,0x0c076a2cu,0x0c076a2eu,0x0c076a30u,
0x0c076a32u,0x0c076a34u,0x0c076a36u,0x0c076a38u,0x0c076a3au,0x0c076a3cu,0x0c076a3eu,0x0c076a40u,0x0c076a42u,0x0c076a44u,0x0c076a46u,0x0c076a48u,0x0c076a4au,0x0c076a4cu,0x0c076a4eu,0x0c076a50u,
0x0c076a52u,0x0c076a54u,0x0c076a56u,0x0c076a58u,0x0c076a5au,0x0c076a5cu,0x0c076a5eu,0x0c076a60u,0x0c076a62u,0x0c076a64u,0x0c076a66u,0x0c076a68u,0x0c076a6au,0x0c076a6cu,0x0c076a6eu,0x0c076a70u,
0x0c076a72u,0x0c076a74u,0x0c076a76u,0x0c076a78u,0x0c076a7au,0x0c076a7cu,0x0c076a7eu,0x0c076a80u,0x0c076a82u,0x0c076a84u,0x0c076a86u,0x0c076a88u,0x0c076a8au,0x0c076a8cu,0x0c076a8eu,0x0c076a90u,
0x0c076a92u,0x0c076a94u,0x0c076a96u,0x0c076a98u,0x0c076a9au,0x0c076a9cu,0x0c076a9eu,0x0c076aa0u,0x0c076aa2u,0x0c076aa4u,0x0c076aa6u,0x0c076aa8u,0x0c076aaau,0x0c076aacu,0x0c076aaeu,0x0c076ab0u,
0x0c076ab2u,0x0c076ab4u,0x0c076ab6u,0x0c076ab8u,0x0c076abau,0x0c076abcu,0x0c076abeu,0x0c076ac0u,0x0c076ac2u,0x0c076ac4u,0x0c076ac6u,0x0c076ac8u,0x0c076acau,0x0c076accu,0x0c076aceu,0x0c076ad0u,
0x0c076ad2u,0x0c076ad4u,0x0c076ad6u,0x0c076ad8u,0x0c076adau,0x0c076adcu,0x0c076adeu,0x0c076ae0u,0x0c076ae2u,0x0c076ae4u,0x0c076ae6u,0x0c076ae8u,0x0c076aeau,0x0c076aecu,0x0c076aeeu,0x0c076af0u,
0x0c076af2u,0x0c076af4u,0x0c076af6u,0x0c076af8u,0x0c076afau,0x0c076afcu,0x0c076afeu,0x0c076b00u,0x0c076b02u,0x0c076b04u,0x0c076b06u,0x0c076b08u,0x0c076b0au,0x0c076b0cu,0x0c076b0eu,0x0c076b10u,
0x0c076b12u,0x0c076b14u,0x0c076b16u,0x0c076b18u,0x0c07f1bau,0x0c07f1bcu,0x0c07f1beu,0x0c07f1c0u,0x0c07f1c2u,0x0c07f1c4u,0x0c07f1c6u,0x0c07f1c8u,0x0c07f1cau,0x0c07f1ccu,0x0c07f1ceu,0x0c07f1d0u,
0x0c07f1d2u,0x0c07f1d4u,0x0c07f1d6u,0x0c07f1d8u,0x0c07f1dau,0x0c07f1dcu,0x0c07f1deu,0x0c07f1e0u,0x0c07f1e2u,0x0c07f1e4u,0x0c07f1e6u,0x0c07f1e8u,0x0c07f1eau,0x0c07f1ecu,0x0c07f1eeu,0x0c07f1f0u,
0x0c07f1f2u,0x0c07f1f4u,0x0c07f1f6u,0x0c07f1f8u,0x0c07f238u,0x0c07f23au,0x0c07f23cu,0x0c07f23eu,0x0c07f240u,0x0c07f242u,0x0c07f244u,0x0c07f246u,0x0c07f248u,0x0c07f24au,0x0c07f24cu,0x0c07f24eu,
0x0c07f250u,0x0c07f252u,0x0c07f254u,0x0c07f256u,0x0c07f258u,0x0c07f25au,0x0c07f25cu,0x0c07f25eu,0x0c07f260u,0x0c07f262u,0x0c07f264u,0x0c07f266u,0x0c07f268u,0x0c07f26au,0x0c07f26cu,0x0c07f26eu,
0x0c07f270u,0x0c07f272u,0x0c07f274u,0x0c07f276u,0x0c07f278u,0x0c07f27au,0x0c07f27cu,0x0c07f27eu,0x0c07f280u,0x0c07f282u,0x0c07f284u,0x0c07f286u,0x0c07f288u,0x0c07f28au,0x0c07f28cu,0x0c07f28eu,
0x0c07f290u,0x0c07f292u,0x0c07f294u,0x0c07f296u,0x0c07f298u,0x0c07f29au,0x0c07f29cu,0x0c07f29eu,0x0c07f2a0u,0x0c07f2a2u,0x0c07f2a4u,0x0c07f2a6u,0x0c07f2a8u,0x0c07f2aau,0x0c07f2acu,0x0c07f2aeu,
0x0c07f2b0u,0x0c07f2b2u,0x0c07f2b4u,0x0c07f2b6u,0x0c07f2b8u,0x0c07f2bau,0x0c07f2bcu,0x0c07f2beu,0x0c07f2c0u,0x0c07f2c2u,0x0c07f2c4u,0x0c07f2c6u,0x0c07f2c8u,0x0c07f2cau,0x0c07f2ccu,0x0c07f2ceu,
0x0c07f2d0u,0x0c07f2d2u,0x0c07f2d4u,0x0c07f2d6u,0x0c07f2d8u,0x0c07f2dau,0x0c07f2dcu,0x0c07f2deu,0x0c07f2e0u,0x0c07f2e2u,0x0c07f2e4u,0x0c07f2e6u,0x0c07f2e8u,0x0c07f2eau,0x0c07f2ecu,0x0c07f2eeu,
0x0c07f2f0u,0x0c07f2f2u,0x0c07f2f4u,0x0c07f2f6u,0x0c07f2f8u,0x0c07f2fau,0x0c07f2fcu,0x0c07f2feu,0x0c07f300u,0x0c07f302u,0x0c07f304u,0x0c07f306u,0x0c07f308u,0x0c081fbeu,0x0c081fc0u,0x0c081fc2u,
0x0c081fc4u,0x0c081fc6u,0x0c081fc8u,0x0c081fcau,0x0c081fccu,0x0c081fceu,0x0c081fd0u,0x0c081fd2u,0x0c081fd4u,0x0c081fd6u,0x0c081fd8u,0x0c081fdau,0x0c081fdcu,0x0c081fdeu,0x0c081fe0u,0x0c081fe2u,
0x0c081fe4u,0x0c081fe6u,0x0c081fe8u,0x0c081feau,0x0c081fecu,0x0c081feeu,0x0c081ff0u,0x0c081ff2u,0x0c081ff4u,0x0c081ff6u,0x0c081ff8u,0x0c081ffau,0x0c081ffcu,0x0c081ffeu,0x0c082000u,0x0c082002u,
0x0c082004u,0x0c082006u,0x0c082008u,0x0c08200au,0x0c08200cu,0x0c08200eu,0x0c082010u,0x0c082012u,0x0c082014u,0x0c082016u,0x0c082018u,0x0c08201au,0x0c08201cu,0x0c08201eu,0x0c082020u,0x0c082022u,
0x0c082024u,0x0c082026u,0x0c082028u,0x0c08202au,0x0c08202cu,0x0c08202eu,0x0c082030u,0x0c082032u,0x0c082034u,0x0c082036u,0x0c082038u,0x0c08203au,0x0c08203cu,0x0c08203eu,0x0c082040u,0x0c082042u,
0x0c082044u,0x0c082046u,0x0c082048u,0x0c08204au,0x0c08204cu,0x0c08204eu,0x0c082050u,0x0c082052u,0x0c082054u,0x0c097ff4u,0x0c097ff6u,0x0c097ff8u,0x0c097ffau,0x0c097ffcu,0x0c097ffeu,0x0c098000u,
0x0c098002u,0x0c098004u,0x0c098006u,0x0c098008u,0x0c09800au,0x0c09800cu,0x0c09800eu,0x0c098010u,0x0c098012u,0x0c098014u,0x0c098016u,0x0c098018u,0x0c09801au,0x0c09801cu,0x0c09801eu,0x0c098020u,
0x0c098022u,0x0c098024u,0x0c098026u,0x0c098028u,0x0c09802au,0x0c09802cu,0x0c09802eu,0x0c098030u,0x0c098032u,0x0c098034u,0x0c098036u,0x0c098038u,0x0c09803au,0x0c09803cu,0x0c09803eu,0x0c098588u,
0x0c09858au,0x0c09858cu,0x0c09858eu,0x0c098590u,0x0c098592u,0x0c098594u,0x0c098596u,0x0c098598u,0x0c09859au,0x0c09859cu,0x0c09859eu,0x0c0985a0u,0x0c0985a2u,0x0c0985a4u,0x0c0985a6u,0x0c0985a8u,
0x0c0985aau,0x0c0985acu,0x0c0985aeu,0x0c0985b0u,0x0c0985b2u,0x0c0985b4u,0x0c0985b6u,0x0c0985b8u,0x0c0985bau,0x0c0985bcu,0x0c0985beu,0x0c0985c0u,0x0c0985c2u,0x0c0985c4u,0x0c0985c6u,0x0c0985c8u,
0x0c0985cau,0x0c0985ccu,0x0c0985ceu,0x0c0985d0u,0x0c0985d2u,0x0c0985d4u,0x0c0985d6u,0x0c0985d8u,0x0c0985dau,0x0c0985dcu,0x0c0985deu,0x0c0985e0u,0x0c0985e2u,0x0c0985e4u,0x0c0985e6u,0x0c0985e8u,
0x0c0985eau,0x0c0985ecu,0x0c0985eeu,0x0c0985f0u,0x0c0985f2u,0x0c0985f4u,0x0c0985f6u,0x0c0985f8u,0x0c0985fau,0x0c0985fcu,0x0c0985feu,0x0c098600u,0x0c098602u,0x0c098604u,0x0c098606u,0x0c098608u,
0x0c09860au,0x0c09860cu,0x0c09860eu,0x0c098610u,0x0c098612u,0x0c098614u,0x0c098616u,0x0c098618u,0x0c09861au,0x0c09861cu,0x0c09d09eu,0x0c09d0a0u,0x0c09d0a2u,0x0c09d0a4u,0x0c09d0a6u,0x0c09d0a8u,
0x0c09d0aau,0x0c09d0acu,0x0c09d0aeu,0x0c09d0b0u,0x0c09d0b2u,0x0c09d0b4u,0x0c09d0b6u,0x0c09d0b8u,0x0c09d0bau,0x0c09d0bcu,0x0c09d0beu,0x0c09d0c0u,0x0c09d0c2u,0x0c09d0c4u,0x0c09d0c6u,0x0c09d0c8u,
0x0c09d0cau,0x0c09d0ccu,0x0c09d0ceu,0x0c09d0d0u,0x0c09d0d2u,0x0c09d0d4u,0x0c09d0d6u,0x0c09d0d8u,0x0c09d0dau,0x0c09d0dcu,0x0c09d0deu,0x0c09d0e0u,0x0c09d0e2u,0x0c09d0e4u,0x0c09d0e6u,0x0c09d0e8u,
0x0c09d0eau,0x0c09d0ecu,0x0c09d0eeu,0x0c09d0f0u,0x0c09d0f2u,0x0c09d0f4u,0x0c09d0f6u,0x0c09d0f8u,0x0c09d0fau,0x0c09d0fcu,0x0c09d0feu,0x0c09d100u,0x0c09d102u,0x0c09d104u,0x0c09d106u,0x0c09d108u,
0x0c09d10au,0x0c09d10cu,0x0c09d10eu,0x0c09d110u,0x0c09d112u,0x0c09d114u,0x0c09d116u,0x0c09d118u,0x0c09d11au,0x0c09d11cu,0x0c09d11eu,0x0c09d120u,0x0c09d122u,0x0c09d124u,0x0c09d126u,0x0c09d128u,
0x0c09d12au,0x0c09d12cu,0x0c09d12eu,0x0c09d130u,0x0c09d132u,0x0c09d134u,0x0c09d136u,0x0c0a0280u,0x0c0a0282u,0x0c0a0284u,0x0c0a0286u,0x0c0a0288u,0x0c0a03deu,0x0c0a03e0u,0x0c0a03e2u,0x0c0a03e4u,
0x0c0a03e6u,0x0c0a03e8u,0x0c0a03eau,0x0c0a03ecu,0x0c0a03eeu,0x0c0aa7a2u,0x0c0aa7a4u,0x0c0aa7a6u,0x0c0aa7a8u,0x0c0aa7aau,0x0c0aa7acu,0x0c0aa7aeu,0x0c0aa7b0u,0x0c0aa7b2u,0x0c0aa7b4u,0x0c0aa7b6u,
0x0c0aa7b8u,0x0c0aa7bau,0x0c0aa7bcu,0x0c0aa7beu,0x0c0aa7c0u,0x0c0aa7c2u,0x0c0aa7c4u,0x0c0aa7c6u,0x0c0aa7c8u,0x0c0aa7cau,0x0c0aa7ccu,0x0c0aa7ceu,0x0c0aa7d0u,0x0c0aa7d2u,0x0c0aa7d4u,0x0c0aa7d6u,
0x0c0aa7d8u,0x0c0aa7dau,0x0c0aa7dcu,0x0c0aa7deu,0x0c0aa7e0u,0x0c0aa7e2u,0x0c0aa7e4u,0x0c0aa7e6u,0x0c0aa7e8u,0x0c0aa7eau,0x0c0aaaf6u,0x0c0aaaf8u,0x0c0aaafau,0x0c0aaafcu,0x0c0aaafeu,0x0c0aab00u,
0x0c0aab02u,0x0c0aab04u,0x0c0aab06u,0x0c0aab08u,0x0c0aab0au,0x0c0aab0cu,0x0c0aab0eu,0x0c0aab10u,0x0c0aab12u,0x0c0aab14u,0x0c0aab16u,0x0c0aab18u,0x0c0aab1au,0x0c0aab1cu,0x0c0aab1eu,0x0c0aab4cu,
0x0c0aab4eu,0x0c0aab50u,0x0c0aab52u,0x0c0aab54u,0x0c0aab56u,0x0c0aab58u,0x0c0aab5au,0x0c0aab5cu,0x0c0aab5eu,0x0c0aab60u,0x0c0aab62u,0x0c0aab64u,0x0c0aab66u,0x0c0aab68u,0x0c0aab6au,0x0c0aab6cu,
0x0c0aab6eu,0x0c0aab70u,0x0c0aab72u,0x0c0aab74u,0x0c0aab76u,0x0c0aab78u,0x0c0aab7au,0x0c0aab7cu,0x0c0aab7eu,0x0c0aab80u,0x0c0aab82u,0x0c0aab84u,0x0c0aab86u,0x0c0aab88u,0x0c0aab8au,0x0c0aab8cu,
0x0c0aab8eu,0x0c0aab90u,0x0c0aab92u,0x0c0aab94u,0x0c0aab96u,0x0c0aab98u,0x0c0aab9au,0x0c0aab9cu,0x0c0aab9eu,0x0c0aaba0u,0x0c0aaba2u,0x0c0aaba4u,0x0c0aaba6u,0x0c0aaba8u,0x0c0aabaau,0x0c0aabacu,
0x0c0aabaeu,0x0c0aabb0u,0x0c0aabb2u,0x0c0aabb4u,0x0c0aabb6u,0x0c0aabb8u,0x0c0aabbau,0x0c0aabbcu,0x0c0aabbeu,0x0c0aabc0u,0x0c0aabc2u,0x0c0aabc4u,0x0c0aabc6u,0x0c0aabc8u,0x0c0aabcau,0x0c0aabccu,
0x0c0aabceu,0x0c0aabd0u,0x0c0aabd2u,0x0c0aabd4u,0x0c0aabd6u,0x0c0aabd8u,0x0c0aabdau,0x0c0aabdcu,0x0c0aabdeu,0x0c0aabe0u,0x0c0aabe2u,0x0c0aabe4u,0x0c0aabe6u,0x0c0aabe8u,0x0c0aabeau,0x0c0aabecu,
0x0c0aabeeu,0x0c0aabf0u,0x0c0aabf2u,0x0c0aabf4u,0x0c0c6298u,0x0c0c629au,0x0c0c629cu,0x0c0c629eu,0x0c0c62a0u,0x0c0c62a2u,0x0c0c62a4u,0x0c0c62a6u,0x0c0c62a8u,0x0c0c62aau,0x0c0c62acu,0x0c0c62aeu,
0x0c0c62b0u,0x0c0c62b2u,0x0c0c62b4u,0x0c0c62b6u,0x0c0c62b8u,0x0c0c62bau,0x0c0c62bcu,0x0c0c62beu,0x0c0c62c0u,0x0c0c62c2u,0x0c0c62c4u,0x0c0c62c6u,0x0c0c62c8u,0x0c0c62cau,0x0c0c62ccu,0x0c0c62ceu,
0x0c0c62d0u,0x0c0c62d2u,0x0c0c62d4u,0x0c0c62d6u,0x0c0c62d8u,0x0c0c62dau,0x0c0c62dcu,0x0c0c62deu,0x0c0c62e0u,0x0c0c62e2u,0x0c0c62e4u,0x0c0c62e6u,0x0c0c62e8u,0x0c0c62eau,0x0c0c62ecu,0x0c0c62eeu,
0x0c0c62f0u,0x0c0c62f2u,0x0c0c62f4u,0x0c0c62f6u,0x0c0c62f8u,0x0c0c62fau,0x0c0c62fcu,0x0c0c62feu,0x0c0c6300u,0x0c0c6302u,0x0c0c6304u,0x0c0c6306u,0x0c0c6308u,0x0c0c630au,0x0c0c630cu,0x0c0c630eu,
0x0c0c6310u,0x0c0c6312u,0x0c0c6314u,0x0c0c6316u,0x0c0c6318u,0x0c0c631au,0x0c0c631cu,0x0c0c631eu,0x0c0c6320u,0x0c0c6322u,0x0c0c6324u,0x0c0c6326u,0x0c0c6328u,0x0c0c632au,0x0c0c632cu,0x0c0c8644u,
0x0c0c8646u,0x0c0c8648u,0x0c0c864au,0x0c0c864cu,0x0c0c864eu,0x0c0c8650u,0x0c0c8652u,0x0c0c8654u,0x0c0c8656u,0x0c0c8658u,0x0c0c865au,0x0c0c865cu,0x0c0c865eu,0x0c0c8660u,0x0c0c8662u,0x0c0c8664u,
0x0c0c8666u,0x0c0c8668u,0x0c0c866au,0x0c0c866cu,0x0c0c866eu,0x0c0c8670u,0x0c0c8672u,0x0c0c8674u,0x0c0c8676u,0x0c0c8678u,0x0c0c867au,0x0c0c867cu,0x0c0c867eu,0x0c0c8680u,0x0c0c8682u,0x0c0c8684u,
0x0c0c8686u,0x0c0c8688u,0x0c0c868au,0x0c0c868cu,0x0c0c868eu,0x0c0c8690u,0x0c0c8692u,0x0c0c8694u,0x0c0c8696u,0x0c0c8698u,0x0c0c869au,0x0c0c869cu,0x0c0c869eu,0x0c0c86a0u,0x0c0c86a2u,0x0c0c86a4u,
0x0c0c86a6u,0x0c0c86a8u,0x0c0c86aau,0x0c0c86acu,0x0c0c86aeu,0x0c0c86b0u,0x0c0c86b2u,0x0c0c86b4u,0x0c0c86b6u,0x0c0c86b8u,0x0c0c86bau,0x0c0c86bcu,0x0c0c86beu,0x0c0c86c0u,0x0c0c86c2u,0x0c0c86c4u,
0x0c0c86c6u,0x0c0c86c8u,0x0c0c86cau,0x0c0c86ccu,0x0c0c86ceu,0x0c0c86d0u,0x0c0c86d2u,0x0c0c86d4u,0x0c0c86d6u,0x0c0c86d8u,0x0c0c9c14u,0x0c0c9c16u,
};
int vf3_c90d_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
