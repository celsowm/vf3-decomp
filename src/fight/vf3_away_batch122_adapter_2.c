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
int vf3_away_batch122_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09befcu: goto P_0c09befc;
case 0x0c09befeu: goto P_0c09befe;
case 0x0c09bf00u: goto P_0c09bf00;
case 0x0c09bf02u: goto P_0c09bf02;
case 0x0c09bf04u: goto P_0c09bf04;
case 0x0c09bf06u: goto P_0c09bf06;
case 0x0c09bf08u: goto P_0c09bf08;
case 0x0c09bf0au: goto P_0c09bf0a;
case 0x0c09bf0cu: goto P_0c09bf0c;
case 0x0c09bf0eu: goto P_0c09bf0e;
case 0x0c09bf10u: goto P_0c09bf10;
case 0x0c09bf12u: goto P_0c09bf12;
case 0x0c09bf14u: goto P_0c09bf14;
case 0x0c09bf16u: goto P_0c09bf16;
case 0x0c09bf18u: goto P_0c09bf18;
case 0x0c09bf1au: goto P_0c09bf1a;
case 0x0c09bf1cu: goto P_0c09bf1c;
case 0x0c09bf1eu: goto P_0c09bf1e;
case 0x0c09bf20u: goto P_0c09bf20;
case 0x0c09bf22u: goto P_0c09bf22;
case 0x0c09bf24u: goto P_0c09bf24;
case 0x0c09bf26u: goto P_0c09bf26;
case 0x0c09bf28u: goto P_0c09bf28;
case 0x0c09bf2au: goto P_0c09bf2a;
case 0x0c09bf2cu: goto P_0c09bf2c;
case 0x0c09bf2eu: goto P_0c09bf2e;
case 0x0c09bf30u: goto P_0c09bf30;
case 0x0c09bf32u: goto P_0c09bf32;
case 0x0c09bf34u: goto P_0c09bf34;
case 0x0c09bf36u: goto P_0c09bf36;
case 0x0c09bf38u: goto P_0c09bf38;
case 0x0c09bf3au: goto P_0c09bf3a;
case 0x0c09bf3cu: goto P_0c09bf3c;
case 0x0c09bf3eu: goto P_0c09bf3e;
case 0x0c09bf40u: goto P_0c09bf40;
case 0x0c09bf42u: goto P_0c09bf42;
case 0x0c09bf44u: goto P_0c09bf44;
case 0x0c09bf46u: goto P_0c09bf46;
case 0x0c09bf48u: goto P_0c09bf48;
case 0x0c09bf4au: goto P_0c09bf4a;
case 0x0c09bf4cu: goto P_0c09bf4c;
case 0x0c09bf4eu: goto P_0c09bf4e;
case 0x0c09bf50u: goto P_0c09bf50;
case 0x0c09bf52u: goto P_0c09bf52;
case 0x0c09bf54u: goto P_0c09bf54;
case 0x0c09bf56u: goto P_0c09bf56;
case 0x0c09bf58u: goto P_0c09bf58;
case 0x0c09bf5au: goto P_0c09bf5a;
case 0x0c09bf5cu: goto P_0c09bf5c;
case 0x0c09bf5eu: goto P_0c09bf5e;
case 0x0c09bf60u: goto P_0c09bf60;
case 0x0c09bf62u: goto P_0c09bf62;
case 0x0c09bf64u: goto P_0c09bf64;
case 0x0c09bf66u: goto P_0c09bf66;
case 0x0c09bf68u: goto P_0c09bf68;
case 0x0c09bf6au: goto P_0c09bf6a;
case 0x0c09bf6cu: goto P_0c09bf6c;
case 0x0c09bf6eu: goto P_0c09bf6e;
case 0x0c09bf70u: goto P_0c09bf70;
case 0x0c09bf72u: goto P_0c09bf72;
case 0x0c09bf74u: goto P_0c09bf74;
case 0x0c09bf76u: goto P_0c09bf76;
case 0x0c09bf78u: goto P_0c09bf78;
case 0x0c09bf7au: goto P_0c09bf7a;
case 0x0c09bf7cu: goto P_0c09bf7c;
case 0x0c09bf7eu: goto P_0c09bf7e;
case 0x0c09bf80u: goto P_0c09bf80;
case 0x0c09bf82u: goto P_0c09bf82;
case 0x0c09bf84u: goto P_0c09bf84;
case 0x0c09bf86u: goto P_0c09bf86;
case 0x0c09bf88u: goto P_0c09bf88;
case 0x0c09bf8au: goto P_0c09bf8a;
case 0x0c09bf8cu: goto P_0c09bf8c;
case 0x0c09bf8eu: goto P_0c09bf8e;
case 0x0c09bf90u: goto P_0c09bf90;
case 0x0c09bf92u: goto P_0c09bf92;
case 0x0c09bfa8u: goto P_0c09bfa8;
case 0x0c09bfaau: goto P_0c09bfaa;
case 0x0c09bfacu: goto P_0c09bfac;
case 0x0c09bfaeu: goto P_0c09bfae;
case 0x0c09bfb0u: goto P_0c09bfb0;
case 0x0c09bfb2u: goto P_0c09bfb2;
case 0x0c09bfb4u: goto P_0c09bfb4;
case 0x0c09bfb6u: goto P_0c09bfb6;
case 0x0c09bfb8u: goto P_0c09bfb8;
case 0x0c09bfbau: goto P_0c09bfba;
case 0x0c09bfbcu: goto P_0c09bfbc;
case 0x0c09bfbeu: goto P_0c09bfbe;
case 0x0c09bfc0u: goto P_0c09bfc0;
case 0x0c09bfc2u: goto P_0c09bfc2;
case 0x0c09bfc4u: goto P_0c09bfc4;
case 0x0c09bfc6u: goto P_0c09bfc6;
case 0x0c09bfc8u: goto P_0c09bfc8;
case 0x0c09bfcau: goto P_0c09bfca;
case 0x0c09bfccu: goto P_0c09bfcc;
case 0x0c09bfceu: goto P_0c09bfce;
case 0x0c09bfd0u: goto P_0c09bfd0;
case 0x0c09bfd2u: goto P_0c09bfd2;
case 0x0c09bfd4u: goto P_0c09bfd4;
case 0x0c09bfd6u: goto P_0c09bfd6;
case 0x0c09bfd8u: goto P_0c09bfd8;
case 0x0c09bfdau: goto P_0c09bfda;
case 0x0c09bfdcu: goto P_0c09bfdc;
case 0x0c09bfdeu: goto P_0c09bfde;
case 0x0c09bfe0u: goto P_0c09bfe0;
case 0x0c09bfe2u: goto P_0c09bfe2;
case 0x0c09bfe4u: goto P_0c09bfe4;
case 0x0c09bfe6u: goto P_0c09bfe6;
case 0x0c09bfe8u: goto P_0c09bfe8;
case 0x0c09bfeau: goto P_0c09bfea;
case 0x0c09bfecu: goto P_0c09bfec;
case 0x0c09bfeeu: goto P_0c09bfee;
case 0x0c09bff0u: goto P_0c09bff0;
case 0x0c09bff2u: goto P_0c09bff2;
case 0x0c09bff4u: goto P_0c09bff4;
case 0x0c09bff6u: goto P_0c09bff6;
case 0x0c09bff8u: goto P_0c09bff8;
case 0x0c09bffau: goto P_0c09bffa;
case 0x0c09bffcu: goto P_0c09bffc;
case 0x0c09bffeu: goto P_0c09bffe;
case 0x0c09c000u: goto P_0c09c000;
case 0x0c09c002u: goto P_0c09c002;
case 0x0c09c004u: goto P_0c09c004;
case 0x0c09c006u: goto P_0c09c006;
case 0x0c09c008u: goto P_0c09c008;
case 0x0c09c00au: goto P_0c09c00a;
case 0x0c09c00cu: goto P_0c09c00c;
case 0x0c09c00eu: goto P_0c09c00e;
case 0x0c09c010u: goto P_0c09c010;
case 0x0c09c012u: goto P_0c09c012;
case 0x0c09c014u: goto P_0c09c014;
case 0x0c09c016u: goto P_0c09c016;
case 0x0c09c018u: goto P_0c09c018;
case 0x0c09c01au: goto P_0c09c01a;
case 0x0c09c01cu: goto P_0c09c01c;
case 0x0c09c01eu: goto P_0c09c01e;
case 0x0c09c020u: goto P_0c09c020;
case 0x0c09c022u: goto P_0c09c022;
case 0x0c09c024u: goto P_0c09c024;
case 0x0c09c026u: goto P_0c09c026;
case 0x0c09c028u: goto P_0c09c028;
case 0x0c09c02au: goto P_0c09c02a;
case 0x0c09c02cu: goto P_0c09c02c;
case 0x0c09c02eu: goto P_0c09c02e;
case 0x0c09c030u: goto P_0c09c030;
case 0x0c09c032u: goto P_0c09c032;
case 0x0c09c034u: goto P_0c09c034;
case 0x0c09c036u: goto P_0c09c036;
case 0x0c09c038u: goto P_0c09c038;
case 0x0c09c03au: goto P_0c09c03a;
case 0x0c09c03cu: goto P_0c09c03c;
case 0x0c09c03eu: goto P_0c09c03e;
case 0x0c09c040u: goto P_0c09c040;
case 0x0c09c042u: goto P_0c09c042;
case 0x0c09c044u: goto P_0c09c044;
case 0x0c09c046u: goto P_0c09c046;
case 0x0c09c048u: goto P_0c09c048;
case 0x0c09c04au: goto P_0c09c04a;
case 0x0c09c04cu: goto P_0c09c04c;
case 0x0c09c04eu: goto P_0c09c04e;
case 0x0c09c050u: goto P_0c09c050;
case 0x0c09c052u: goto P_0c09c052;
case 0x0c09c054u: goto P_0c09c054;
case 0x0c09c056u: goto P_0c09c056;
case 0x0c09c058u: goto P_0c09c058;
case 0x0c09c05au: goto P_0c09c05a;
case 0x0c09c05cu: goto P_0c09c05c;
case 0x0c09c05eu: goto P_0c09c05e;
case 0x0c09c060u: goto P_0c09c060;
case 0x0c09c062u: goto P_0c09c062;
case 0x0c09c064u: goto P_0c09c064;
case 0x0c09c066u: goto P_0c09c066;
case 0x0c09c068u: goto P_0c09c068;
case 0x0c09c06au: goto P_0c09c06a;
case 0x0c09c06cu: goto P_0c09c06c;
case 0x0c09c06eu: goto P_0c09c06e;
case 0x0c09c070u: goto P_0c09c070;
case 0x0c09c072u: goto P_0c09c072;
case 0x0c09c074u: goto P_0c09c074;
case 0x0c09c076u: goto P_0c09c076;
case 0x0c09c078u: goto P_0c09c078;
case 0x0c09c07au: goto P_0c09c07a;
case 0x0c09c07cu: goto P_0c09c07c;
case 0x0c09c07eu: goto P_0c09c07e;
case 0x0c09c080u: goto P_0c09c080;
case 0x0c09c082u: goto P_0c09c082;
case 0x0c09c084u: goto P_0c09c084;
case 0x0c09c086u: goto P_0c09c086;
case 0x0c09c088u: goto P_0c09c088;
case 0x0c09c08au: goto P_0c09c08a;
case 0x0c09c08cu: goto P_0c09c08c;
case 0x0c09c08eu: goto P_0c09c08e;
case 0x0c09c090u: goto P_0c09c090;
case 0x0c09c092u: goto P_0c09c092;
case 0x0c09c094u: goto P_0c09c094;
case 0x0c09c096u: goto P_0c09c096;
case 0x0c09c098u: goto P_0c09c098;
case 0x0c09c09au: goto P_0c09c09a;
case 0x0c09c09cu: goto P_0c09c09c;
case 0x0c09c09eu: goto P_0c09c09e;
case 0x0c09c0a0u: goto P_0c09c0a0;
case 0x0c09c0a2u: goto P_0c09c0a2;
case 0x0c09c0a4u: goto P_0c09c0a4;
case 0x0c09c0a6u: goto P_0c09c0a6;
case 0x0c09c0a8u: goto P_0c09c0a8;
case 0x0c09c0aau: goto P_0c09c0aa;
case 0x0c09c0acu: goto P_0c09c0ac;
case 0x0c09c0aeu: goto P_0c09c0ae;
case 0x0c09c0b0u: goto P_0c09c0b0;
case 0x0c09c0b2u: goto P_0c09c0b2;
case 0x0c09c0b4u: goto P_0c09c0b4;
case 0x0c09c0e4u: goto P_0c09c0e4;
case 0x0c09c0e6u: goto P_0c09c0e6;
case 0x0c09c0e8u: goto P_0c09c0e8;
case 0x0c09c0eau: goto P_0c09c0ea;
case 0x0c09c0ecu: goto P_0c09c0ec;
case 0x0c09c0eeu: goto P_0c09c0ee;
case 0x0c09c0f0u: goto P_0c09c0f0;
case 0x0c09c0f2u: goto P_0c09c0f2;
case 0x0c09c0f4u: goto P_0c09c0f4;
case 0x0c09c0f6u: goto P_0c09c0f6;
case 0x0c09c0f8u: goto P_0c09c0f8;
case 0x0c09c0fau: goto P_0c09c0fa;
case 0x0c09c0fcu: goto P_0c09c0fc;
case 0x0c09c0feu: goto P_0c09c0fe;
case 0x0c09c100u: goto P_0c09c100;
case 0x0c09c102u: goto P_0c09c102;
case 0x0c09c104u: goto P_0c09c104;
case 0x0c09c106u: goto P_0c09c106;
case 0x0c09c108u: goto P_0c09c108;
case 0x0c09c10au: goto P_0c09c10a;
case 0x0c09c10cu: goto P_0c09c10c;
case 0x0c09c10eu: goto P_0c09c10e;
case 0x0c09c110u: goto P_0c09c110;
case 0x0c09c112u: goto P_0c09c112;
case 0x0c09c114u: goto P_0c09c114;
case 0x0c09c116u: goto P_0c09c116;
case 0x0c09c118u: goto P_0c09c118;
case 0x0c09c11au: goto P_0c09c11a;
case 0x0c09c11cu: goto P_0c09c11c;
case 0x0c09c11eu: goto P_0c09c11e;
case 0x0c09c120u: goto P_0c09c120;
case 0x0c09c122u: goto P_0c09c122;
case 0x0c09c124u: goto P_0c09c124;
case 0x0c09c126u: goto P_0c09c126;
case 0x0c09c128u: goto P_0c09c128;
case 0x0c09c12au: goto P_0c09c12a;
case 0x0c09c12cu: goto P_0c09c12c;
case 0x0c09c12eu: goto P_0c09c12e;
case 0x0c09c130u: goto P_0c09c130;
case 0x0c09c132u: goto P_0c09c132;
case 0x0c09c134u: goto P_0c09c134;
case 0x0c09c136u: goto P_0c09c136;
case 0x0c09c138u: goto P_0c09c138;
case 0x0c09c13au: goto P_0c09c13a;
case 0x0c09c13cu: goto P_0c09c13c;
case 0x0c09c13eu: goto P_0c09c13e;
case 0x0c09c140u: goto P_0c09c140;
case 0x0c09c142u: goto P_0c09c142;
case 0x0c09c144u: goto P_0c09c144;
case 0x0c09c146u: goto P_0c09c146;
case 0x0c09c148u: goto P_0c09c148;
case 0x0c09c14au: goto P_0c09c14a;
case 0x0c09c14cu: goto P_0c09c14c;
case 0x0c09c14eu: goto P_0c09c14e;
case 0x0c09c150u: goto P_0c09c150;
case 0x0c09c152u: goto P_0c09c152;
case 0x0c09c154u: goto P_0c09c154;
case 0x0c09c156u: goto P_0c09c156;
case 0x0c09c158u: goto P_0c09c158;
case 0x0c09c15au: goto P_0c09c15a;
case 0x0c09c15cu: goto P_0c09c15c;
case 0x0c09c15eu: goto P_0c09c15e;
case 0x0c09c160u: goto P_0c09c160;
case 0x0c09c162u: goto P_0c09c162;
case 0x0c09c164u: goto P_0c09c164;
case 0x0c09c166u: goto P_0c09c166;
case 0x0c09c168u: goto P_0c09c168;
case 0x0c09c16au: goto P_0c09c16a;
case 0x0c09c16cu: goto P_0c09c16c;
case 0x0c09c16eu: goto P_0c09c16e;
case 0x0c09c170u: goto P_0c09c170;
case 0x0c09c172u: goto P_0c09c172;
case 0x0c09c174u: goto P_0c09c174;
case 0x0c09c176u: goto P_0c09c176;
case 0x0c09c178u: goto P_0c09c178;
case 0x0c09c17au: goto P_0c09c17a;
case 0x0c09c17cu: goto P_0c09c17c;
case 0x0c09c17eu: goto P_0c09c17e;
case 0x0c09c180u: goto P_0c09c180;
case 0x0c09c182u: goto P_0c09c182;
case 0x0c09c184u: goto P_0c09c184;
case 0x0c09c186u: goto P_0c09c186;
case 0x0c09c188u: goto P_0c09c188;
case 0x0c09c18au: goto P_0c09c18a;
case 0x0c09c18cu: goto P_0c09c18c;
case 0x0c09c18eu: goto P_0c09c18e;
case 0x0c09c190u: goto P_0c09c190;
case 0x0c09c192u: goto P_0c09c192;
case 0x0c09c194u: goto P_0c09c194;
case 0x0c09c196u: goto P_0c09c196;
case 0x0c09c198u: goto P_0c09c198;
case 0x0c09c19au: goto P_0c09c19a;
case 0x0c09c19cu: goto P_0c09c19c;
case 0x0c09c19eu: goto P_0c09c19e;
case 0x0c09c1a0u: goto P_0c09c1a0;
case 0x0c09c1a2u: goto P_0c09c1a2;
case 0x0c09c1a4u: goto P_0c09c1a4;
case 0x0c09c1a6u: goto P_0c09c1a6;
case 0x0c09c1a8u: goto P_0c09c1a8;
case 0x0c09c1aau: goto P_0c09c1aa;
case 0x0c09c1acu: goto P_0c09c1ac;
case 0x0c09c1aeu: goto P_0c09c1ae;
case 0x0c09c1b0u: goto P_0c09c1b0;
case 0x0c09c1b2u: goto P_0c09c1b2;
case 0x0c09c1b4u: goto P_0c09c1b4;
case 0x0c09c1b6u: goto P_0c09c1b6;
case 0x0c09c1b8u: goto P_0c09c1b8;
case 0x0c09c1bau: goto P_0c09c1ba;
case 0x0c09c1bcu: goto P_0c09c1bc;
case 0x0c09c1beu: goto P_0c09c1be;
case 0x0c09c1c0u: goto P_0c09c1c0;
case 0x0c09c1c2u: goto P_0c09c1c2;
case 0x0c09c1c4u: goto P_0c09c1c4;
case 0x0c09c1c6u: goto P_0c09c1c6;
case 0x0c09c1c8u: goto P_0c09c1c8;
case 0x0c09c1cau: goto P_0c09c1ca;
case 0x0c09c1ccu: goto P_0c09c1cc;
case 0x0c09c1ceu: goto P_0c09c1ce;
case 0x0c09c1d0u: goto P_0c09c1d0;
case 0x0c09c1d2u: goto P_0c09c1d2;
case 0x0c09c1d4u: goto P_0c09c1d4;
case 0x0c09c1d6u: goto P_0c09c1d6;
case 0x0c09c1d8u: goto P_0c09c1d8;
case 0x0c09c1dau: goto P_0c09c1da;
case 0x0c09c1dcu: goto P_0c09c1dc;
case 0x0c09c1deu: goto P_0c09c1de;
case 0x0c09c1e0u: goto P_0c09c1e0;
case 0x0c09c1e2u: goto P_0c09c1e2;
case 0x0c09c1e4u: goto P_0c09c1e4;
case 0x0c09c1e6u: goto P_0c09c1e6;
case 0x0c09c1e8u: goto P_0c09c1e8;
case 0x0c09c1eau: goto P_0c09c1ea;
case 0x0c09c1ecu: goto P_0c09c1ec;
case 0x0c09c1eeu: goto P_0c09c1ee;
case 0x0c09c1f0u: goto P_0c09c1f0;
case 0x0c09c1f2u: goto P_0c09c1f2;
case 0x0c09c1f4u: goto P_0c09c1f4;
case 0x0c09c1f6u: goto P_0c09c1f6;
case 0x0c09c1f8u: goto P_0c09c1f8;
case 0x0c09c1fau: goto P_0c09c1fa;
case 0x0c09c1fcu: goto P_0c09c1fc;
case 0x0c09c1feu: goto P_0c09c1fe;
case 0x0c09c200u: goto P_0c09c200;
case 0x0c09c202u: goto P_0c09c202;
case 0x0c09c204u: goto P_0c09c204;
case 0x0c09c206u: goto P_0c09c206;
case 0x0c09c208u: goto P_0c09c208;
case 0x0c09c20au: goto P_0c09c20a;
case 0x0c09c224u: goto P_0c09c224;
case 0x0c09c226u: goto P_0c09c226;
case 0x0c09c228u: goto P_0c09c228;
case 0x0c09c22au: goto P_0c09c22a;
case 0x0c09c22cu: goto P_0c09c22c;
case 0x0c09c22eu: goto P_0c09c22e;
case 0x0c09c230u: goto P_0c09c230;
case 0x0c09c232u: goto P_0c09c232;
case 0x0c09c234u: goto P_0c09c234;
case 0x0c09c236u: goto P_0c09c236;
case 0x0c09c238u: goto P_0c09c238;
case 0x0c09c23au: goto P_0c09c23a;
case 0x0c09c23cu: goto P_0c09c23c;
case 0x0c09c23eu: goto P_0c09c23e;
case 0x0c09c240u: goto P_0c09c240;
case 0x0c09c242u: goto P_0c09c242;
case 0x0c09c244u: goto P_0c09c244;
case 0x0c09c246u: goto P_0c09c246;
case 0x0c09c248u: goto P_0c09c248;
case 0x0c09c24au: goto P_0c09c24a;
case 0x0c09c24cu: goto P_0c09c24c;
case 0x0c09c24eu: goto P_0c09c24e;
case 0x0c09c250u: goto P_0c09c250;
case 0x0c09c252u: goto P_0c09c252;
case 0x0c09c254u: goto P_0c09c254;
case 0x0c09c256u: goto P_0c09c256;
case 0x0c09c258u: goto P_0c09c258;
case 0x0c09c25au: goto P_0c09c25a;
case 0x0c09c25cu: goto P_0c09c25c;
case 0x0c09c25eu: goto P_0c09c25e;
case 0x0c09c260u: goto P_0c09c260;
case 0x0c09c262u: goto P_0c09c262;
case 0x0c09c264u: goto P_0c09c264;
case 0x0c09c266u: goto P_0c09c266;
case 0x0c09c268u: goto P_0c09c268;
case 0x0c09c26au: goto P_0c09c26a;
case 0x0c09c26cu: goto P_0c09c26c;
case 0x0c09c26eu: goto P_0c09c26e;
case 0x0c09c270u: goto P_0c09c270;
case 0x0c09c272u: goto P_0c09c272;
case 0x0c09c274u: goto P_0c09c274;
case 0x0c09c276u: goto P_0c09c276;
case 0x0c09c278u: goto P_0c09c278;
case 0x0c09c27au: goto P_0c09c27a;
case 0x0c09c27cu: goto P_0c09c27c;
case 0x0c09c27eu: goto P_0c09c27e;
case 0x0c09c280u: goto P_0c09c280;
case 0x0c09c282u: goto P_0c09c282;
case 0x0c09c284u: goto P_0c09c284;
case 0x0c09c286u: goto P_0c09c286;
case 0x0c09c288u: goto P_0c09c288;
case 0x0c09c28au: goto P_0c09c28a;
case 0x0c09c28cu: goto P_0c09c28c;
case 0x0c09c28eu: goto P_0c09c28e;
case 0x0c09c290u: goto P_0c09c290;
case 0x0c09c292u: goto P_0c09c292;
case 0x0c09c294u: goto P_0c09c294;
case 0x0c09c296u: goto P_0c09c296;
case 0x0c09c298u: goto P_0c09c298;
case 0x0c09c29au: goto P_0c09c29a;
case 0x0c09c29cu: goto P_0c09c29c;
case 0x0c09c29eu: goto P_0c09c29e;
case 0x0c09c2a0u: goto P_0c09c2a0;
case 0x0c09c2a2u: goto P_0c09c2a2;
case 0x0c09c2a4u: goto P_0c09c2a4;
case 0x0c09c2a6u: goto P_0c09c2a6;
case 0x0c09c2a8u: goto P_0c09c2a8;
case 0x0c09c2aau: goto P_0c09c2aa;
case 0x0c09c2acu: goto P_0c09c2ac;
case 0x0c09c2aeu: goto P_0c09c2ae;
case 0x0c09c2b0u: goto P_0c09c2b0;
case 0x0c09c2b2u: goto P_0c09c2b2;
case 0x0c09c2b4u: goto P_0c09c2b4;
case 0x0c09c2b6u: goto P_0c09c2b6;
case 0x0c09c2b8u: goto P_0c09c2b8;
case 0x0c09c2bau: goto P_0c09c2ba;
case 0x0c09c2bcu: goto P_0c09c2bc;
case 0x0c09c2beu: goto P_0c09c2be;
case 0x0c09c2c0u: goto P_0c09c2c0;
case 0x0c09c2c2u: goto P_0c09c2c2;
case 0x0c09c2c4u: goto P_0c09c2c4;
case 0x0c09c2c6u: goto P_0c09c2c6;
case 0x0c09c2c8u: goto P_0c09c2c8;
case 0x0c09c2cau: goto P_0c09c2ca;
case 0x0c09c2ccu: goto P_0c09c2cc;
case 0x0c09c2ceu: goto P_0c09c2ce;
case 0x0c09c2d0u: goto P_0c09c2d0;
case 0x0c09c2d2u: goto P_0c09c2d2;
case 0x0c09c2d4u: goto P_0c09c2d4;
case 0x0c09c2d6u: goto P_0c09c2d6;
case 0x0c09c2d8u: goto P_0c09c2d8;
case 0x0c09c2dau: goto P_0c09c2da;
case 0x0c09c2dcu: goto P_0c09c2dc;
case 0x0c09c2deu: goto P_0c09c2de;
case 0x0c09c2e0u: goto P_0c09c2e0;
case 0x0c09c2e2u: goto P_0c09c2e2;
case 0x0c09c2e4u: goto P_0c09c2e4;
case 0x0c09c2e6u: goto P_0c09c2e6;
case 0x0c09c2e8u: goto P_0c09c2e8;
case 0x0c09c304u: goto P_0c09c304;
case 0x0c09c306u: goto P_0c09c306;
case 0x0c09c308u: goto P_0c09c308;
case 0x0c09c30au: goto P_0c09c30a;
case 0x0c09c30cu: goto P_0c09c30c;
case 0x0c09c30eu: goto P_0c09c30e;
case 0x0c09c310u: goto P_0c09c310;
case 0x0c09c312u: goto P_0c09c312;
case 0x0c09c314u: goto P_0c09c314;
case 0x0c09c316u: goto P_0c09c316;
case 0x0c09c318u: goto P_0c09c318;
case 0x0c09c31au: goto P_0c09c31a;
case 0x0c09c31cu: goto P_0c09c31c;
case 0x0c09c31eu: goto P_0c09c31e;
case 0x0c09c320u: goto P_0c09c320;
case 0x0c09c322u: goto P_0c09c322;
case 0x0c09c324u: goto P_0c09c324;
case 0x0c09c326u: goto P_0c09c326;
case 0x0c09c328u: goto P_0c09c328;
case 0x0c09c32au: goto P_0c09c32a;
case 0x0c09c32cu: goto P_0c09c32c;
case 0x0c09c32eu: goto P_0c09c32e;
case 0x0c09c330u: goto P_0c09c330;
case 0x0c09c332u: goto P_0c09c332;
case 0x0c09c334u: goto P_0c09c334;
case 0x0c09c336u: goto P_0c09c336;
case 0x0c09c338u: goto P_0c09c338;
case 0x0c09c33au: goto P_0c09c33a;
case 0x0c09c33cu: goto P_0c09c33c;
case 0x0c09c33eu: goto P_0c09c33e;
case 0x0c09c340u: goto P_0c09c340;
case 0x0c09c342u: goto P_0c09c342;
case 0x0c09c344u: goto P_0c09c344;
case 0x0c09c346u: goto P_0c09c346;
case 0x0c09c348u: goto P_0c09c348;
case 0x0c09c34au: goto P_0c09c34a;
case 0x0c09c34cu: goto P_0c09c34c;
case 0x0c09c34eu: goto P_0c09c34e;
case 0x0c09c350u: goto P_0c09c350;
case 0x0c09c352u: goto P_0c09c352;
case 0x0c09c354u: goto P_0c09c354;
case 0x0c09c356u: goto P_0c09c356;
case 0x0c09c358u: goto P_0c09c358;
case 0x0c09c35au: goto P_0c09c35a;
case 0x0c09c35cu: goto P_0c09c35c;
case 0x0c09c35eu: goto P_0c09c35e;
case 0x0c09c360u: goto P_0c09c360;
case 0x0c09c362u: goto P_0c09c362;
case 0x0c09c364u: goto P_0c09c364;
case 0x0c09c366u: goto P_0c09c366;
case 0x0c09c368u: goto P_0c09c368;
case 0x0c09c36au: goto P_0c09c36a;
case 0x0c09c36cu: goto P_0c09c36c;
case 0x0c09c36eu: goto P_0c09c36e;
case 0x0c09c370u: goto P_0c09c370;
case 0x0c09c372u: goto P_0c09c372;
case 0x0c09c374u: goto P_0c09c374;
case 0x0c09c376u: goto P_0c09c376;
case 0x0c09c378u: goto P_0c09c378;
case 0x0c09c37au: goto P_0c09c37a;
case 0x0c09c37cu: goto P_0c09c37c;
case 0x0c09c37eu: goto P_0c09c37e;
case 0x0c09c380u: goto P_0c09c380;
case 0x0c09c382u: goto P_0c09c382;
case 0x0c09c384u: goto P_0c09c384;
case 0x0c09c386u: goto P_0c09c386;
case 0x0c09c388u: goto P_0c09c388;
case 0x0c09c38au: goto P_0c09c38a;
case 0x0c09c38cu: goto P_0c09c38c;
case 0x0c09c38eu: goto P_0c09c38e;
case 0x0c09c390u: goto P_0c09c390;
case 0x0c09c392u: goto P_0c09c392;
case 0x0c09c394u: goto P_0c09c394;
case 0x0c09c396u: goto P_0c09c396;
case 0x0c09c398u: goto P_0c09c398;
case 0x0c09c39au: goto P_0c09c39a;
case 0x0c09c39cu: goto P_0c09c39c;
case 0x0c09c39eu: goto P_0c09c39e;
case 0x0c09c3a0u: goto P_0c09c3a0;
case 0x0c09c3a2u: goto P_0c09c3a2;
case 0x0c09c3a4u: goto P_0c09c3a4;
case 0x0c09c3a6u: goto P_0c09c3a6;
case 0x0c09c3a8u: goto P_0c09c3a8;
case 0x0c09c3aau: goto P_0c09c3aa;
case 0x0c09c3acu: goto P_0c09c3ac;
case 0x0c09c3aeu: goto P_0c09c3ae;
case 0x0c09c3b0u: goto P_0c09c3b0;
case 0x0c09c3b2u: goto P_0c09c3b2;
case 0x0c09c3b4u: goto P_0c09c3b4;
case 0x0c09c3b6u: goto P_0c09c3b6;
case 0x0c09c3b8u: goto P_0c09c3b8;
case 0x0c09c3bau: goto P_0c09c3ba;
case 0x0c09c3bcu: goto P_0c09c3bc;
case 0x0c09c3beu: goto P_0c09c3be;
case 0x0c09c3c0u: goto P_0c09c3c0;
case 0x0c09c3c2u: goto P_0c09c3c2;
case 0x0c09c3c4u: goto P_0c09c3c4;
case 0x0c09c3c6u: goto P_0c09c3c6;
case 0x0c09c3c8u: goto P_0c09c3c8;
case 0x0c09c3cau: goto P_0c09c3ca;
case 0x0c09c3ccu: goto P_0c09c3cc;
case 0x0c09c3ceu: goto P_0c09c3ce;
case 0x0c09c3d0u: goto P_0c09c3d0;
case 0x0c09c3d2u: goto P_0c09c3d2;
case 0x0c09c3d4u: goto P_0c09c3d4;
case 0x0c09c3d6u: goto P_0c09c3d6;
case 0x0c09c3d8u: goto P_0c09c3d8;
case 0x0c09c3dau: goto P_0c09c3da;
case 0x0c09c3dcu: goto P_0c09c3dc;
case 0x0c09c3deu: goto P_0c09c3de;
case 0x0c09c3e0u: goto P_0c09c3e0;
case 0x0c09c3e2u: goto P_0c09c3e2;
case 0x0c09c3e4u: goto P_0c09c3e4;
case 0x0c09c3e6u: goto P_0c09c3e6;
case 0x0c09c3e8u: goto P_0c09c3e8;
case 0x0c09c3eau: goto P_0c09c3ea;
case 0x0c09c3ecu: goto P_0c09c3ec;
case 0x0c09c3eeu: goto P_0c09c3ee;
case 0x0c09c3f0u: goto P_0c09c3f0;
case 0x0c09c3f2u: goto P_0c09c3f2;
case 0x0c09c3f4u: goto P_0c09c3f4;
case 0x0c09c3f6u: goto P_0c09c3f6;
case 0x0c09c3f8u: goto P_0c09c3f8;
case 0x0c09c3fau: goto P_0c09c3fa;
case 0x0c09c3fcu: goto P_0c09c3fc;
case 0x0c09c3feu: goto P_0c09c3fe;
case 0x0c09c400u: goto P_0c09c400;
case 0x0c09c402u: goto P_0c09c402;
case 0x0c09c404u: goto P_0c09c404;
case 0x0c09c406u: goto P_0c09c406;
case 0x0c09c408u: goto P_0c09c408;
case 0x0c09c40au: goto P_0c09c40a;
case 0x0c09c40cu: goto P_0c09c40c;
case 0x0c09c40eu: goto P_0c09c40e;
case 0x0c09c410u: goto P_0c09c410;
case 0x0c09c412u: goto P_0c09c412;
case 0x0c09c414u: goto P_0c09c414;
case 0x0c09c416u: goto P_0c09c416;
case 0x0c09c418u: goto P_0c09c418;
case 0x0c09c41au: goto P_0c09c41a;
case 0x0c09c41cu: goto P_0c09c41c;
case 0x0c09c41eu: goto P_0c09c41e;
case 0x0c09c420u: goto P_0c09c420;
case 0x0c09c422u: goto P_0c09c422;
case 0x0c09c424u: goto P_0c09c424;
case 0x0c09c426u: goto P_0c09c426;
case 0x0c09c428u: goto P_0c09c428;
case 0x0c09c42au: goto P_0c09c42a;
case 0x0c09c42cu: goto P_0c09c42c;
case 0x0c09c42eu: goto P_0c09c42e;
case 0x0c09c430u: goto P_0c09c430;
case 0x0c09c432u: goto P_0c09c432;
case 0x0c09c434u: goto P_0c09c434;
case 0x0c09c436u: goto P_0c09c436;
case 0x0c09c438u: goto P_0c09c438;
case 0x0c09c43au: goto P_0c09c43a;
case 0x0c09c43cu: goto P_0c09c43c;
case 0x0c09c43eu: goto P_0c09c43e;
case 0x0c09c440u: goto P_0c09c440;
case 0x0c09c442u: goto P_0c09c442;
case 0x0c09c444u: goto P_0c09c444;
case 0x0c09c446u: goto P_0c09c446;
case 0x0c09c448u: goto P_0c09c448;
case 0x0c09c458u: goto P_0c09c458;
case 0x0c09c45au: goto P_0c09c45a;
case 0x0c09c45cu: goto P_0c09c45c;
case 0x0c09c45eu: goto P_0c09c45e;
case 0x0c09c460u: goto P_0c09c460;
case 0x0c09c462u: goto P_0c09c462;
case 0x0c09c464u: goto P_0c09c464;
case 0x0c09c466u: goto P_0c09c466;
case 0x0c09c468u: goto P_0c09c468;
case 0x0c09c46au: goto P_0c09c46a;
case 0x0c09c46cu: goto P_0c09c46c;
case 0x0c09c46eu: goto P_0c09c46e;
case 0x0c09c470u: goto P_0c09c470;
case 0x0c09c472u: goto P_0c09c472;
case 0x0c09c474u: goto P_0c09c474;
case 0x0c09c476u: goto P_0c09c476;
case 0x0c09c478u: goto P_0c09c478;
case 0x0c09c47au: goto P_0c09c47a;
case 0x0c09c47cu: goto P_0c09c47c;
case 0x0c09c47eu: goto P_0c09c47e;
case 0x0c09c480u: goto P_0c09c480;
case 0x0c09c482u: goto P_0c09c482;
case 0x0c09c484u: goto P_0c09c484;
case 0x0c09c486u: goto P_0c09c486;
case 0x0c09c488u: goto P_0c09c488;
case 0x0c09c48au: goto P_0c09c48a;
case 0x0c09c48cu: goto P_0c09c48c;
case 0x0c09c48eu: goto P_0c09c48e;
case 0x0c09c490u: goto P_0c09c490;
case 0x0c09c492u: goto P_0c09c492;
case 0x0c09c494u: goto P_0c09c494;
case 0x0c09c496u: goto P_0c09c496;
case 0x0c09c498u: goto P_0c09c498;
case 0x0c09c49au: goto P_0c09c49a;
case 0x0c09c49cu: goto P_0c09c49c;
case 0x0c09c49eu: goto P_0c09c49e;
case 0x0c09c4a0u: goto P_0c09c4a0;
case 0x0c09c4a2u: goto P_0c09c4a2;
case 0x0c09c4a4u: goto P_0c09c4a4;
case 0x0c09c4a6u: goto P_0c09c4a6;
case 0x0c09c4a8u: goto P_0c09c4a8;
case 0x0c09c4aau: goto P_0c09c4aa;
case 0x0c09c4acu: goto P_0c09c4ac;
case 0x0c09c4aeu: goto P_0c09c4ae;
case 0x0c09c4b0u: goto P_0c09c4b0;
case 0x0c09c4b2u: goto P_0c09c4b2;
case 0x0c09c4b4u: goto P_0c09c4b4;
case 0x0c09c4b6u: goto P_0c09c4b6;
case 0x0c09c4b8u: goto P_0c09c4b8;
case 0x0c09c4bau: goto P_0c09c4ba;
case 0x0c09c4bcu: goto P_0c09c4bc;
case 0x0c09c4beu: goto P_0c09c4be;
case 0x0c09c4c0u: goto P_0c09c4c0;
case 0x0c09c4c2u: goto P_0c09c4c2;
case 0x0c09c4c4u: goto P_0c09c4c4;
case 0x0c09c4c6u: goto P_0c09c4c6;
case 0x0c09c4c8u: goto P_0c09c4c8;
case 0x0c09c4cau: goto P_0c09c4ca;
case 0x0c09c4ccu: goto P_0c09c4cc;
case 0x0c09c4ceu: goto P_0c09c4ce;
case 0x0c09c4d0u: goto P_0c09c4d0;
case 0x0c09c4d2u: goto P_0c09c4d2;
case 0x0c09c4d4u: goto P_0c09c4d4;
case 0x0c09c4d6u: goto P_0c09c4d6;
case 0x0c09c4d8u: goto P_0c09c4d8;
case 0x0c09c4dau: goto P_0c09c4da;
case 0x0c09c4dcu: goto P_0c09c4dc;
case 0x0c09c4deu: goto P_0c09c4de;
case 0x0c09c4e0u: goto P_0c09c4e0;
case 0x0c09c4e2u: goto P_0c09c4e2;
case 0x0c09c4e4u: goto P_0c09c4e4;
case 0x0c09c4e6u: goto P_0c09c4e6;
case 0x0c09c4e8u: goto P_0c09c4e8;
case 0x0c09c4eau: goto P_0c09c4ea;
case 0x0c09c4ecu: goto P_0c09c4ec;
case 0x0c09c4eeu: goto P_0c09c4ee;
case 0x0c09c4f0u: goto P_0c09c4f0;
case 0x0c09c4f2u: goto P_0c09c4f2;
case 0x0c09c4f4u: goto P_0c09c4f4;
case 0x0c09c4f6u: goto P_0c09c4f6;
case 0x0c09c4f8u: goto P_0c09c4f8;
case 0x0c09c4fau: goto P_0c09c4fa;
case 0x0c09c4fcu: goto P_0c09c4fc;
case 0x0c09c4feu: goto P_0c09c4fe;
case 0x0c09c500u: goto P_0c09c500;
case 0x0c09c502u: goto P_0c09c502;
case 0x0c09c504u: goto P_0c09c504;
case 0x0c09c506u: goto P_0c09c506;
case 0x0c09c508u: goto P_0c09c508;
case 0x0c09c50au: goto P_0c09c50a;
case 0x0c09c50cu: goto P_0c09c50c;
case 0x0c09c50eu: goto P_0c09c50e;
case 0x0c09c510u: goto P_0c09c510;
case 0x0c09c512u: goto P_0c09c512;
case 0x0c09c514u: goto P_0c09c514;
case 0x0c09c516u: goto P_0c09c516;
case 0x0c09c518u: goto P_0c09c518;
case 0x0c09c51au: goto P_0c09c51a;
case 0x0c09c51cu: goto P_0c09c51c;
case 0x0c09c51eu: goto P_0c09c51e;
case 0x0c09c520u: goto P_0c09c520;
case 0x0c09c522u: goto P_0c09c522;
case 0x0c09c524u: goto P_0c09c524;
case 0x0c09c526u: goto P_0c09c526;
case 0x0c09c528u: goto P_0c09c528;
case 0x0c09c52au: goto P_0c09c52a;
case 0x0c09c52cu: goto P_0c09c52c;
case 0x0c09c52eu: goto P_0c09c52e;
case 0x0c09c530u: goto P_0c09c530;
case 0x0c09c532u: goto P_0c09c532;
case 0x0c09c534u: goto P_0c09c534;
case 0x0c09c536u: goto P_0c09c536;
case 0x0c09c538u: goto P_0c09c538;
case 0x0c09c53au: goto P_0c09c53a;
case 0x0c09c53cu: goto P_0c09c53c;
case 0x0c09c53eu: goto P_0c09c53e;
case 0x0c09c540u: goto P_0c09c540;
case 0x0c09c542u: goto P_0c09c542;
case 0x0c09c544u: goto P_0c09c544;
case 0x0c09c546u: goto P_0c09c546;
case 0x0c09c548u: goto P_0c09c548;
case 0x0c09c54au: goto P_0c09c54a;
case 0x0c09c54cu: goto P_0c09c54c;
case 0x0c09c54eu: goto P_0c09c54e;
case 0x0c09c550u: goto P_0c09c550;
case 0x0c09c552u: goto P_0c09c552;
case 0x0c09c554u: goto P_0c09c554;
case 0x0c09c556u: goto P_0c09c556;
case 0x0c09c558u: goto P_0c09c558;
case 0x0c09c55au: goto P_0c09c55a;
case 0x0c09c568u: goto P_0c09c568;
case 0x0c09c56au: goto P_0c09c56a;
case 0x0c09c56cu: goto P_0c09c56c;
case 0x0c09c56eu: goto P_0c09c56e;
case 0x0c09c570u: goto P_0c09c570;
case 0x0c09c572u: goto P_0c09c572;
case 0x0c09c574u: goto P_0c09c574;
case 0x0c09c576u: goto P_0c09c576;
case 0x0c09c578u: goto P_0c09c578;
case 0x0c09c57au: goto P_0c09c57a;
case 0x0c09c57cu: goto P_0c09c57c;
case 0x0c09c57eu: goto P_0c09c57e;
case 0x0c09c580u: goto P_0c09c580;
case 0x0c09c582u: goto P_0c09c582;
case 0x0c09c584u: goto P_0c09c584;
case 0x0c09c586u: goto P_0c09c586;
case 0x0c09c588u: goto P_0c09c588;
case 0x0c09c58au: goto P_0c09c58a;
case 0x0c09c58cu: goto P_0c09c58c;
case 0x0c09c58eu: goto P_0c09c58e;
case 0x0c09c590u: goto P_0c09c590;
case 0x0c09c592u: goto P_0c09c592;
case 0x0c09c594u: goto P_0c09c594;
case 0x0c09c596u: goto P_0c09c596;
case 0x0c09c598u: goto P_0c09c598;
case 0x0c09c59au: goto P_0c09c59a;
case 0x0c09c59cu: goto P_0c09c59c;
case 0x0c09c59eu: goto P_0c09c59e;
case 0x0c09c5a0u: goto P_0c09c5a0;
case 0x0c09c5a2u: goto P_0c09c5a2;
case 0x0c09c5a4u: goto P_0c09c5a4;
case 0x0c09c5a6u: goto P_0c09c5a6;
case 0x0c09c5a8u: goto P_0c09c5a8;
case 0x0c09c5aau: goto P_0c09c5aa;
case 0x0c09c5acu: goto P_0c09c5ac;
case 0x0c09c5aeu: goto P_0c09c5ae;
case 0x0c09c5b0u: goto P_0c09c5b0;
case 0x0c09c5b2u: goto P_0c09c5b2;
case 0x0c09c5b4u: goto P_0c09c5b4;
case 0x0c09c5b6u: goto P_0c09c5b6;
case 0x0c09c5b8u: goto P_0c09c5b8;
case 0x0c09c5bau: goto P_0c09c5ba;
case 0x0c09c5bcu: goto P_0c09c5bc;
case 0x0c09c5beu: goto P_0c09c5be;
case 0x0c09c5c0u: goto P_0c09c5c0;
case 0x0c09c5c2u: goto P_0c09c5c2;
case 0x0c09c5c4u: goto P_0c09c5c4;
case 0x0c09c5c6u: goto P_0c09c5c6;
case 0x0c09c5c8u: goto P_0c09c5c8;
case 0x0c09c5cau: goto P_0c09c5ca;
case 0x0c09c5ccu: goto P_0c09c5cc;
case 0x0c09c5ceu: goto P_0c09c5ce;
case 0x0c09c5d0u: goto P_0c09c5d0;
case 0x0c09c5d2u: goto P_0c09c5d2;
case 0x0c09c5d4u: goto P_0c09c5d4;
case 0x0c09c5d6u: goto P_0c09c5d6;
case 0x0c09c5d8u: goto P_0c09c5d8;
case 0x0c09c5dau: goto P_0c09c5da;
case 0x0c09c5dcu: goto P_0c09c5dc;
case 0x0c09c5deu: goto P_0c09c5de;
case 0x0c09c5e0u: goto P_0c09c5e0;
case 0x0c09c5e2u: goto P_0c09c5e2;
case 0x0c09c5e4u: goto P_0c09c5e4;
case 0x0c09c5e6u: goto P_0c09c5e6;
case 0x0c09c5e8u: goto P_0c09c5e8;
case 0x0c09c5eau: goto P_0c09c5ea;
case 0x0c09c5ecu: goto P_0c09c5ec;
case 0x0c09c5eeu: goto P_0c09c5ee;
case 0x0c09c5f0u: goto P_0c09c5f0;
case 0x0c09c5f2u: goto P_0c09c5f2;
case 0x0c09c5f4u: goto P_0c09c5f4;
case 0x0c09c5f6u: goto P_0c09c5f6;
case 0x0c09c5f8u: goto P_0c09c5f8;
case 0x0c09c5fau: goto P_0c09c5fa;
case 0x0c09c5fcu: goto P_0c09c5fc;
case 0x0c09c5feu: goto P_0c09c5fe;
case 0x0c09c600u: goto P_0c09c600;
case 0x0c09c602u: goto P_0c09c602;
case 0x0c09c604u: goto P_0c09c604;
case 0x0c09c606u: goto P_0c09c606;
case 0x0c09c608u: goto P_0c09c608;
case 0x0c09c60au: goto P_0c09c60a;
case 0x0c09c60cu: goto P_0c09c60c;
case 0x0c09c60eu: goto P_0c09c60e;
case 0x0c09c610u: goto P_0c09c610;
case 0x0c09c612u: goto P_0c09c612;
case 0x0c09c614u: goto P_0c09c614;
case 0x0c09c616u: goto P_0c09c616;
case 0x0c09c618u: goto P_0c09c618;
case 0x0c09c61au: goto P_0c09c61a;
case 0x0c09c61cu: goto P_0c09c61c;
case 0x0c09c61eu: goto P_0c09c61e;
case 0x0c09c620u: goto P_0c09c620;
case 0x0c09c622u: goto P_0c09c622;
case 0x0c09c624u: goto P_0c09c624;
case 0x0c09c626u: goto P_0c09c626;
case 0x0c09c628u: goto P_0c09c628;
case 0x0c09c62au: goto P_0c09c62a;
case 0x0c09c62cu: goto P_0c09c62c;
case 0x0c09c62eu: goto P_0c09c62e;
case 0x0c09c630u: goto P_0c09c630;
case 0x0c09c632u: goto P_0c09c632;
case 0x0c09c634u: goto P_0c09c634;
case 0x0c09c636u: goto P_0c09c636;
case 0x0c09c638u: goto P_0c09c638;
case 0x0c09c63au: goto P_0c09c63a;
case 0x0c09c63cu: goto P_0c09c63c;
case 0x0c09c63eu: goto P_0c09c63e;
case 0x0c09c640u: goto P_0c09c640;
case 0x0c09c642u: goto P_0c09c642;
case 0x0c09c644u: goto P_0c09c644;
case 0x0c09c646u: goto P_0c09c646;
case 0x0c09c648u: goto P_0c09c648;
case 0x0c09c64au: goto P_0c09c64a;
case 0x0c09c64cu: goto P_0c09c64c;
case 0x0c09c64eu: goto P_0c09c64e;
case 0x0c09c650u: goto P_0c09c650;
case 0x0c09c652u: goto P_0c09c652;
case 0x0c09c654u: goto P_0c09c654;
case 0x0c09c656u: goto P_0c09c656;
case 0x0c09c658u: goto P_0c09c658;
case 0x0c09c65au: goto P_0c09c65a;
case 0x0c09c65cu: goto P_0c09c65c;
case 0x0c09c65eu: goto P_0c09c65e;
case 0x0c09c660u: goto P_0c09c660;
case 0x0c09c662u: goto P_0c09c662;
case 0x0c09c664u: goto P_0c09c664;
case 0x0c09c666u: goto P_0c09c666;
case 0x0c09c668u: goto P_0c09c668;
case 0x0c09c66au: goto P_0c09c66a;
case 0x0c09c66cu: goto P_0c09c66c;
case 0x0c09c66eu: goto P_0c09c66e;
case 0x0c09c67cu: goto P_0c09c67c;
case 0x0c09c67eu: goto P_0c09c67e;
case 0x0c09c680u: goto P_0c09c680;
case 0x0c09c682u: goto P_0c09c682;
case 0x0c09c684u: goto P_0c09c684;
case 0x0c09c686u: goto P_0c09c686;
case 0x0c09c688u: goto P_0c09c688;
case 0x0c09c68au: goto P_0c09c68a;
case 0x0c09c68cu: goto P_0c09c68c;
case 0x0c09c68eu: goto P_0c09c68e;
case 0x0c09c690u: goto P_0c09c690;
case 0x0c09c692u: goto P_0c09c692;
case 0x0c09c694u: goto P_0c09c694;
case 0x0c09c696u: goto P_0c09c696;
case 0x0c09c698u: goto P_0c09c698;
case 0x0c09c69au: goto P_0c09c69a;
case 0x0c09c69cu: goto P_0c09c69c;
case 0x0c09c69eu: goto P_0c09c69e;
case 0x0c09c6a0u: goto P_0c09c6a0;
case 0x0c09c6a2u: goto P_0c09c6a2;
case 0x0c09c6a4u: goto P_0c09c6a4;
case 0x0c09c6a6u: goto P_0c09c6a6;
case 0x0c09c6a8u: goto P_0c09c6a8;
case 0x0c09c6aau: goto P_0c09c6aa;
case 0x0c09c6acu: goto P_0c09c6ac;
case 0x0c09c6aeu: goto P_0c09c6ae;
case 0x0c09c6b0u: goto P_0c09c6b0;
case 0x0c09c6b2u: goto P_0c09c6b2;
case 0x0c09c6b4u: goto P_0c09c6b4;
case 0x0c09c6b6u: goto P_0c09c6b6;
case 0x0c09c6b8u: goto P_0c09c6b8;
case 0x0c09c6bau: goto P_0c09c6ba;
case 0x0c09c6bcu: goto P_0c09c6bc;
case 0x0c09c6beu: goto P_0c09c6be;
case 0x0c09c6c0u: goto P_0c09c6c0;
case 0x0c09c6c2u: goto P_0c09c6c2;
case 0x0c09c6c4u: goto P_0c09c6c4;
case 0x0c09c6c6u: goto P_0c09c6c6;
case 0x0c09c6c8u: goto P_0c09c6c8;
case 0x0c09c6cau: goto P_0c09c6ca;
case 0x0c09c6ccu: goto P_0c09c6cc;
case 0x0c09c6ceu: goto P_0c09c6ce;
case 0x0c09c6d0u: goto P_0c09c6d0;
case 0x0c09c6d2u: goto P_0c09c6d2;
case 0x0c09c6d4u: goto P_0c09c6d4;
case 0x0c09c6d6u: goto P_0c09c6d6;
case 0x0c09c6d8u: goto P_0c09c6d8;
case 0x0c09c6dau: goto P_0c09c6da;
case 0x0c09c6dcu: goto P_0c09c6dc;
case 0x0c09c6deu: goto P_0c09c6de;
case 0x0c09c6e0u: goto P_0c09c6e0;
case 0x0c09c6e2u: goto P_0c09c6e2;
case 0x0c09c6e4u: goto P_0c09c6e4;
case 0x0c09c6e6u: goto P_0c09c6e6;
case 0x0c09c6e8u: goto P_0c09c6e8;
case 0x0c09c6eau: goto P_0c09c6ea;
case 0x0c09c6ecu: goto P_0c09c6ec;
case 0x0c09c6eeu: goto P_0c09c6ee;
case 0x0c09c6f0u: goto P_0c09c6f0;
case 0x0c09c6f2u: goto P_0c09c6f2;
case 0x0c09c6f4u: goto P_0c09c6f4;
case 0x0c09c6f6u: goto P_0c09c6f6;
case 0x0c09c6f8u: goto P_0c09c6f8;
case 0x0c09c6fau: goto P_0c09c6fa;
case 0x0c09c6fcu: goto P_0c09c6fc;
case 0x0c09c6feu: goto P_0c09c6fe;
case 0x0c09c700u: goto P_0c09c700;
case 0x0c09c702u: goto P_0c09c702;
case 0x0c09c704u: goto P_0c09c704;
case 0x0c09c706u: goto P_0c09c706;
case 0x0c09c708u: goto P_0c09c708;
case 0x0c09c70au: goto P_0c09c70a;
case 0x0c09c70cu: goto P_0c09c70c;
case 0x0c09c70eu: goto P_0c09c70e;
case 0x0c09c710u: goto P_0c09c710;
case 0x0c09c712u: goto P_0c09c712;
case 0x0c09c714u: goto P_0c09c714;
case 0x0c09c716u: goto P_0c09c716;
case 0x0c09c718u: goto P_0c09c718;
case 0x0c09c71au: goto P_0c09c71a;
case 0x0c09c71cu: goto P_0c09c71c;
case 0x0c09c71eu: goto P_0c09c71e;
case 0x0c09c720u: goto P_0c09c720;
case 0x0c09c722u: goto P_0c09c722;
case 0x0c09c724u: goto P_0c09c724;
case 0x0c09c726u: goto P_0c09c726;
case 0x0c09c728u: goto P_0c09c728;
case 0x0c09c72au: goto P_0c09c72a;
case 0x0c09c72cu: goto P_0c09c72c;
case 0x0c09c72eu: goto P_0c09c72e;
case 0x0c09c730u: goto P_0c09c730;
case 0x0c09c732u: goto P_0c09c732;
case 0x0c09c734u: goto P_0c09c734;
case 0x0c09c736u: goto P_0c09c736;
case 0x0c09c738u: goto P_0c09c738;
case 0x0c09c73au: goto P_0c09c73a;
case 0x0c09c73cu: goto P_0c09c73c;
case 0x0c09c73eu: goto P_0c09c73e;
case 0x0c09c740u: goto P_0c09c740;
case 0x0c09c742u: goto P_0c09c742;
case 0x0c09c744u: goto P_0c09c744;
case 0x0c09c746u: goto P_0c09c746;
case 0x0c09c748u: goto P_0c09c748;
case 0x0c09c74au: goto P_0c09c74a;
case 0x0c09c74cu: goto P_0c09c74c;
case 0x0c09c74eu: goto P_0c09c74e;
case 0x0c09c750u: goto P_0c09c750;
case 0x0c09c752u: goto P_0c09c752;
case 0x0c09c75cu: goto P_0c09c75c;
case 0x0c09c75eu: goto P_0c09c75e;
case 0x0c09c760u: goto P_0c09c760;
case 0x0c09c762u: goto P_0c09c762;
case 0x0c09c764u: goto P_0c09c764;
case 0x0c09c766u: goto P_0c09c766;
case 0x0c09c768u: goto P_0c09c768;
case 0x0c09c76au: goto P_0c09c76a;
case 0x0c09c76cu: goto P_0c09c76c;
case 0x0c09c76eu: goto P_0c09c76e;
case 0x0c09c770u: goto P_0c09c770;
case 0x0c09c772u: goto P_0c09c772;
case 0x0c09c774u: goto P_0c09c774;
case 0x0c09c776u: goto P_0c09c776;
case 0x0c09c778u: goto P_0c09c778;
case 0x0c09c77au: goto P_0c09c77a;
case 0x0c09c77cu: goto P_0c09c77c;
case 0x0c09c77eu: goto P_0c09c77e;
case 0x0c09c780u: goto P_0c09c780;
case 0x0c09c782u: goto P_0c09c782;
case 0x0c09c784u: goto P_0c09c784;
case 0x0c09c786u: goto P_0c09c786;
case 0x0c09c788u: goto P_0c09c788;
case 0x0c09c78au: goto P_0c09c78a;
case 0x0c09c78cu: goto P_0c09c78c;
case 0x0c09c78eu: goto P_0c09c78e;
case 0x0c09c790u: goto P_0c09c790;
case 0x0c09c792u: goto P_0c09c792;
case 0x0c09c794u: goto P_0c09c794;
case 0x0c09c796u: goto P_0c09c796;
case 0x0c09c798u: goto P_0c09c798;
case 0x0c09c79au: goto P_0c09c79a;
case 0x0c09c79cu: goto P_0c09c79c;
case 0x0c09c79eu: goto P_0c09c79e;
case 0x0c09c7a0u: goto P_0c09c7a0;
case 0x0c09c7a2u: goto P_0c09c7a2;
case 0x0c09c7a4u: goto P_0c09c7a4;
case 0x0c09c7a6u: goto P_0c09c7a6;
case 0x0c09c7a8u: goto P_0c09c7a8;
case 0x0c09c7aau: goto P_0c09c7aa;
case 0x0c09c7acu: goto P_0c09c7ac;
case 0x0c09c7aeu: goto P_0c09c7ae;
case 0x0c09c7b0u: goto P_0c09c7b0;
case 0x0c09c7b2u: goto P_0c09c7b2;
case 0x0c09c7b4u: goto P_0c09c7b4;
case 0x0c09c7b6u: goto P_0c09c7b6;
case 0x0c09c7b8u: goto P_0c09c7b8;
case 0x0c09c7bau: goto P_0c09c7ba;
case 0x0c09c7bcu: goto P_0c09c7bc;
case 0x0c09c7beu: goto P_0c09c7be;
case 0x0c09c7c0u: goto P_0c09c7c0;
case 0x0c09c7c2u: goto P_0c09c7c2;
case 0x0c09c7c4u: goto P_0c09c7c4;
case 0x0c09c7c6u: goto P_0c09c7c6;
case 0x0c09c7c8u: goto P_0c09c7c8;
case 0x0c09c7cau: goto P_0c09c7ca;
case 0x0c09c7ccu: goto P_0c09c7cc;
case 0x0c09c7ceu: goto P_0c09c7ce;
case 0x0c09c7d0u: goto P_0c09c7d0;
case 0x0c09c7d2u: goto P_0c09c7d2;
case 0x0c09c7d4u: goto P_0c09c7d4;
case 0x0c09c7d6u: goto P_0c09c7d6;
case 0x0c09c7d8u: goto P_0c09c7d8;
case 0x0c09c7dau: goto P_0c09c7da;
case 0x0c09c7dcu: goto P_0c09c7dc;
case 0x0c09c7deu: goto P_0c09c7de;
case 0x0c09c7e0u: goto P_0c09c7e0;
case 0x0c09c7e2u: goto P_0c09c7e2;
case 0x0c09c7e4u: goto P_0c09c7e4;
case 0x0c09c7e6u: goto P_0c09c7e6;
case 0x0c09c7e8u: goto P_0c09c7e8;
case 0x0c09c7eau: goto P_0c09c7ea;
case 0x0c09c7ecu: goto P_0c09c7ec;
case 0x0c09c7eeu: goto P_0c09c7ee;
case 0x0c09c7f0u: goto P_0c09c7f0;
case 0x0c09c7f2u: goto P_0c09c7f2;
case 0x0c09c7f4u: goto P_0c09c7f4;
case 0x0c09c7f6u: goto P_0c09c7f6;
case 0x0c09c7f8u: goto P_0c09c7f8;
case 0x0c09c7fau: goto P_0c09c7fa;
case 0x0c09c7fcu: goto P_0c09c7fc;
case 0x0c09c7feu: goto P_0c09c7fe;
case 0x0c09c800u: goto P_0c09c800;
case 0x0c09c802u: goto P_0c09c802;
case 0x0c09c804u: goto P_0c09c804;
case 0x0c09c806u: goto P_0c09c806;
case 0x0c09c808u: goto P_0c09c808;
case 0x0c09c80au: goto P_0c09c80a;
case 0x0c09c80cu: goto P_0c09c80c;
case 0x0c09c80eu: goto P_0c09c80e;
case 0x0c09c810u: goto P_0c09c810;
case 0x0c09c812u: goto P_0c09c812;
case 0x0c09c814u: goto P_0c09c814;
case 0x0c09c816u: goto P_0c09c816;
case 0x0c09c818u: goto P_0c09c818;
case 0x0c09c81au: goto P_0c09c81a;
case 0x0c09c81cu: goto P_0c09c81c;
case 0x0c09c81eu: goto P_0c09c81e;
case 0x0c09c820u: goto P_0c09c820;
case 0x0c09c822u: goto P_0c09c822;
case 0x0c09c824u: goto P_0c09c824;
case 0x0c09c826u: goto P_0c09c826;
case 0x0c09c828u: goto P_0c09c828;
case 0x0c09c82au: goto P_0c09c82a;
case 0x0c09c82cu: goto P_0c09c82c;
case 0x0c09c82eu: goto P_0c09c82e;
case 0x0c09c830u: goto P_0c09c830;
case 0x0c09c832u: goto P_0c09c832;
case 0x0c09c834u: goto P_0c09c834;
case 0x0c09c836u: goto P_0c09c836;
case 0x0c09c838u: goto P_0c09c838;
case 0x0c09c83au: goto P_0c09c83a;
case 0x0c09c83cu: goto P_0c09c83c;
case 0x0c09c83eu: goto P_0c09c83e;
case 0x0c09c840u: goto P_0c09c840;
case 0x0c09c842u: goto P_0c09c842;
case 0x0c09c844u: goto P_0c09c844;
case 0x0c09c846u: goto P_0c09c846;
case 0x0c09c848u: goto P_0c09c848;
case 0x0c09c84au: goto P_0c09c84a;
case 0x0c09c84cu: goto P_0c09c84c;
case 0x0c09c84eu: goto P_0c09c84e;
case 0x0c09c850u: goto P_0c09c850;
case 0x0c09c852u: goto P_0c09c852;
case 0x0c09c854u: goto P_0c09c854;
case 0x0c09c856u: goto P_0c09c856;
case 0x0c09c858u: goto P_0c09c858;
case 0x0c09c85au: goto P_0c09c85a;
case 0x0c09c85cu: goto P_0c09c85c;
case 0x0c09c85eu: goto P_0c09c85e;
case 0x0c09c860u: goto P_0c09c860;
case 0x0c09c862u: goto P_0c09c862;
case 0x0c09c864u: goto P_0c09c864;
case 0x0c09c866u: goto P_0c09c866;
case 0x0c09c868u: goto P_0c09c868;
case 0x0c09c86au: goto P_0c09c86a;
case 0x0c09c86cu: goto P_0c09c86c;
case 0x0c09c86eu: goto P_0c09c86e;
case 0x0c09c870u: goto P_0c09c870;
case 0x0c09c872u: goto P_0c09c872;
case 0x0c09c874u: goto P_0c09c874;
case 0x0c09c876u: goto P_0c09c876;
case 0x0c09c878u: goto P_0c09c878;
case 0x0c09c87au: goto P_0c09c87a;
case 0x0c09c87cu: goto P_0c09c87c;
case 0x0c09c87eu: goto P_0c09c87e;
case 0x0c09c880u: goto P_0c09c880;
case 0x0c09c882u: goto P_0c09c882;
case 0x0c09c884u: goto P_0c09c884;
case 0x0c09c886u: goto P_0c09c886;
case 0x0c09c888u: goto P_0c09c888;
case 0x0c09c88au: goto P_0c09c88a;
case 0x0c09c88cu: goto P_0c09c88c;
case 0x0c09c88eu: goto P_0c09c88e;
case 0x0c09c890u: goto P_0c09c890;
case 0x0c09c892u: goto P_0c09c892;
case 0x0c09c894u: goto P_0c09c894;
case 0x0c09c896u: goto P_0c09c896;
case 0x0c09c898u: goto P_0c09c898;
case 0x0c09c89au: goto P_0c09c89a;
case 0x0c09c89cu: goto P_0c09c89c;
case 0x0c09c89eu: goto P_0c09c89e;
case 0x0c09c8a0u: goto P_0c09c8a0;
case 0x0c09c8a2u: goto P_0c09c8a2;
case 0x0c09c8a4u: goto P_0c09c8a4;
case 0x0c09c8a6u: goto P_0c09c8a6;
case 0x0c09c8a8u: goto P_0c09c8a8;
case 0x0c09c8aau: goto P_0c09c8aa;
case 0x0c09c8acu: goto P_0c09c8ac;
case 0x0c09c8b6u: goto P_0c09c8b6;
case 0x0c09c8b8u: goto P_0c09c8b8;
case 0x0c09c8bau: goto P_0c09c8ba;
case 0x0c09c8bcu: goto P_0c09c8bc;
case 0x0c09c8beu: goto P_0c09c8be;
case 0x0c09c8c0u: goto P_0c09c8c0;
case 0x0c09c8c2u: goto P_0c09c8c2;
case 0x0c09c8c4u: goto P_0c09c8c4;
case 0x0c09c8c6u: goto P_0c09c8c6;
case 0x0c09c8c8u: goto P_0c09c8c8;
case 0x0c09c8cau: goto P_0c09c8ca;
case 0x0c09c8ccu: goto P_0c09c8cc;
case 0x0c09c8ceu: goto P_0c09c8ce;
case 0x0c09c8d0u: goto P_0c09c8d0;
case 0x0c09c8d2u: goto P_0c09c8d2;
case 0x0c09c8d4u: goto P_0c09c8d4;
case 0x0c09c8d6u: goto P_0c09c8d6;
case 0x0c09c8d8u: goto P_0c09c8d8;
case 0x0c09c8dau: goto P_0c09c8da;
case 0x0c09c8dcu: goto P_0c09c8dc;
case 0x0c09c8deu: goto P_0c09c8de;
case 0x0c09c8e0u: goto P_0c09c8e0;
case 0x0c09c8e2u: goto P_0c09c8e2;
case 0x0c09c8e4u: goto P_0c09c8e4;
case 0x0c09c8e6u: goto P_0c09c8e6;
case 0x0c09c8e8u: goto P_0c09c8e8;
case 0x0c09c8eau: goto P_0c09c8ea;
case 0x0c09c8ecu: goto P_0c09c8ec;
case 0x0c09c8eeu: goto P_0c09c8ee;
case 0x0c09c8f0u: goto P_0c09c8f0;
case 0x0c09c8f2u: goto P_0c09c8f2;
case 0x0c09c8f4u: goto P_0c09c8f4;
case 0x0c09c8f6u: goto P_0c09c8f6;
case 0x0c09c8f8u: goto P_0c09c8f8;
case 0x0c09c8fau: goto P_0c09c8fa;
case 0x0c09c8fcu: goto P_0c09c8fc;
case 0x0c09c8feu: goto P_0c09c8fe;
case 0x0c09c900u: goto P_0c09c900;
case 0x0c09c902u: goto P_0c09c902;
case 0x0c09c904u: goto P_0c09c904;
case 0x0c09c906u: goto P_0c09c906;
case 0x0c09c908u: goto P_0c09c908;
case 0x0c09c90au: goto P_0c09c90a;
case 0x0c09c90cu: goto P_0c09c90c;
case 0x0c09c90eu: goto P_0c09c90e;
case 0x0c09c910u: goto P_0c09c910;
case 0x0c09c912u: goto P_0c09c912;
case 0x0c09c914u: goto P_0c09c914;
case 0x0c09c916u: goto P_0c09c916;
case 0x0c09c918u: goto P_0c09c918;
case 0x0c09c91au: goto P_0c09c91a;
case 0x0c09c91cu: goto P_0c09c91c;
case 0x0c09c91eu: goto P_0c09c91e;
case 0x0c09c920u: goto P_0c09c920;
case 0x0c09c922u: goto P_0c09c922;
case 0x0c09c924u: goto P_0c09c924;
case 0x0c09c926u: goto P_0c09c926;
case 0x0c09c928u: goto P_0c09c928;
case 0x0c09c92au: goto P_0c09c92a;
case 0x0c09c92cu: goto P_0c09c92c;
case 0x0c09c92eu: goto P_0c09c92e;
case 0x0c09c930u: goto P_0c09c930;
case 0x0c09c932u: goto P_0c09c932;
case 0x0c09c934u: goto P_0c09c934;
case 0x0c09c936u: goto P_0c09c936;
case 0x0c09c938u: goto P_0c09c938;
case 0x0c09c93au: goto P_0c09c93a;
case 0x0c09c93cu: goto P_0c09c93c;
case 0x0c09c942u: goto P_0c09c942;
case 0x0c09c944u: goto P_0c09c944;
case 0x0c09c946u: goto P_0c09c946;
case 0x0c09c948u: goto P_0c09c948;
case 0x0c09c94au: goto P_0c09c94a;
case 0x0c09c94cu: goto P_0c09c94c;
case 0x0c09c94eu: goto P_0c09c94e;
case 0x0c09c950u: goto P_0c09c950;
case 0x0c09c952u: goto P_0c09c952;
case 0x0c09c954u: goto P_0c09c954;
case 0x0c09c956u: goto P_0c09c956;
case 0x0c09c958u: goto P_0c09c958;
case 0x0c09c95au: goto P_0c09c95a;
case 0x0c09c95cu: goto P_0c09c95c;
case 0x0c09c95eu: goto P_0c09c95e;
case 0x0c09c960u: goto P_0c09c960;
case 0x0c09c962u: goto P_0c09c962;
case 0x0c09c964u: goto P_0c09c964;
case 0x0c09c966u: goto P_0c09c966;
case 0x0c09c968u: goto P_0c09c968;
case 0x0c09c96au: goto P_0c09c96a;
case 0x0c09c96cu: goto P_0c09c96c;
case 0x0c09c96eu: goto P_0c09c96e;
case 0x0c09c970u: goto P_0c09c970;
case 0x0c09c972u: goto P_0c09c972;
case 0x0c09c974u: goto P_0c09c974;
case 0x0c09c976u: goto P_0c09c976;
case 0x0c09c978u: goto P_0c09c978;
case 0x0c09c97au: goto P_0c09c97a;
case 0x0c09c97cu: goto P_0c09c97c;
case 0x0c09c97eu: goto P_0c09c97e;
case 0x0c09c980u: goto P_0c09c980;
case 0x0c09c982u: goto P_0c09c982;
case 0x0c09c984u: goto P_0c09c984;
case 0x0c09c986u: goto P_0c09c986;
case 0x0c09c988u: goto P_0c09c988;
case 0x0c09c98au: goto P_0c09c98a;
case 0x0c09c98cu: goto P_0c09c98c;
case 0x0c09c98eu: goto P_0c09c98e;
case 0x0c09c990u: goto P_0c09c990;
case 0x0c09c992u: goto P_0c09c992;
case 0x0c09c994u: goto P_0c09c994;
case 0x0c09c996u: goto P_0c09c996;
case 0x0c09c998u: goto P_0c09c998;
case 0x0c09c99au: goto P_0c09c99a;
case 0x0c09c99cu: goto P_0c09c99c;
case 0x0c09c99eu: goto P_0c09c99e;
case 0x0c09c9a0u: goto P_0c09c9a0;
case 0x0c09c9a2u: goto P_0c09c9a2;
case 0x0c09c9a4u: goto P_0c09c9a4;
case 0x0c09c9a6u: goto P_0c09c9a6;
case 0x0c09c9a8u: goto P_0c09c9a8;
case 0x0c09c9aau: goto P_0c09c9aa;
case 0x0c09c9acu: goto P_0c09c9ac;
case 0x0c09c9aeu: goto P_0c09c9ae;
case 0x0c09c9b0u: goto P_0c09c9b0;
case 0x0c09c9b2u: goto P_0c09c9b2;
case 0x0c09c9b4u: goto P_0c09c9b4;
case 0x0c09c9b6u: goto P_0c09c9b6;
case 0x0c09c9b8u: goto P_0c09c9b8;
case 0x0c09c9bau: goto P_0c09c9ba;
case 0x0c09c9bcu: goto P_0c09c9bc;
case 0x0c09c9beu: goto P_0c09c9be;
case 0x0c09c9c0u: goto P_0c09c9c0;
case 0x0c09c9c2u: goto P_0c09c9c2;
case 0x0c09c9c4u: goto P_0c09c9c4;
case 0x0c09c9c6u: goto P_0c09c9c6;
case 0x0c09c9c8u: goto P_0c09c9c8;
case 0x0c09c9cau: goto P_0c09c9ca;
case 0x0c09c9ccu: goto P_0c09c9cc;
case 0x0c09c9ceu: goto P_0c09c9ce;
case 0x0c09c9d0u: goto P_0c09c9d0;
case 0x0c09c9d2u: goto P_0c09c9d2;
case 0x0c09c9d4u: goto P_0c09c9d4;
case 0x0c09c9d6u: goto P_0c09c9d6;
case 0x0c09c9d8u: goto P_0c09c9d8;
case 0x0c09c9dau: goto P_0c09c9da;
case 0x0c09c9dcu: goto P_0c09c9dc;
case 0x0c09c9deu: goto P_0c09c9de;
case 0x0c09c9e0u: goto P_0c09c9e0;
case 0x0c09c9e2u: goto P_0c09c9e2;
case 0x0c09c9e4u: goto P_0c09c9e4;
case 0x0c09c9e6u: goto P_0c09c9e6;
case 0x0c09c9e8u: goto P_0c09c9e8;
case 0x0c09c9eau: goto P_0c09c9ea;
case 0x0c09c9ecu: goto P_0c09c9ec;
case 0x0c09c9eeu: goto P_0c09c9ee;
case 0x0c09c9f0u: goto P_0c09c9f0;
case 0x0c09c9f2u: goto P_0c09c9f2;
case 0x0c09c9f4u: goto P_0c09c9f4;
case 0x0c09c9f6u: goto P_0c09c9f6;
case 0x0c09c9f8u: goto P_0c09c9f8;
case 0x0c09c9fau: goto P_0c09c9fa;
case 0x0c09c9fcu: goto P_0c09c9fc;
case 0x0c09c9feu: goto P_0c09c9fe;
case 0x0c09ca00u: goto P_0c09ca00;
case 0x0c09ca02u: goto P_0c09ca02;
case 0x0c09ca04u: goto P_0c09ca04;
case 0x0c09ca06u: goto P_0c09ca06;
case 0x0c09ca08u: goto P_0c09ca08;
case 0x0c09ca0au: goto P_0c09ca0a;
case 0x0c09ca0cu: goto P_0c09ca0c;
case 0x0c09ca0eu: goto P_0c09ca0e;
case 0x0c09ca10u: goto P_0c09ca10;
case 0x0c09ca12u: goto P_0c09ca12;
case 0x0c09ca14u: goto P_0c09ca14;
case 0x0c09ca16u: goto P_0c09ca16;
case 0x0c09ca18u: goto P_0c09ca18;
case 0x0c09ca1au: goto P_0c09ca1a;
case 0x0c09ca1cu: goto P_0c09ca1c;
case 0x0c09ca1eu: goto P_0c09ca1e;
case 0x0c09ca20u: goto P_0c09ca20;
case 0x0c09ca22u: goto P_0c09ca22;
case 0x0c09ca24u: goto P_0c09ca24;
case 0x0c09ca26u: goto P_0c09ca26;
case 0x0c09ca28u: goto P_0c09ca28;
case 0x0c09ca2au: goto P_0c09ca2a;
case 0x0c09ca2cu: goto P_0c09ca2c;
case 0x0c09ca2eu: goto P_0c09ca2e;
case 0x0c09ca30u: goto P_0c09ca30;
case 0x0c09ca32u: goto P_0c09ca32;
case 0x0c09ca34u: goto P_0c09ca34;
case 0x0c09ca36u: goto P_0c09ca36;
case 0x0c09ca38u: goto P_0c09ca38;
case 0x0c09ca3au: goto P_0c09ca3a;
case 0x0c09ca3cu: goto P_0c09ca3c;
case 0x0c09ca46u: goto P_0c09ca46;
case 0x0c09ca48u: goto P_0c09ca48;
case 0x0c09ca4au: goto P_0c09ca4a;
case 0x0c09ca4cu: goto P_0c09ca4c;
case 0x0c09ca4eu: goto P_0c09ca4e;
case 0x0c09ca50u: goto P_0c09ca50;
case 0x0c09ca52u: goto P_0c09ca52;
case 0x0c09ca54u: goto P_0c09ca54;
case 0x0c09ca56u: goto P_0c09ca56;
case 0x0c09ca58u: goto P_0c09ca58;
case 0x0c09ca5au: goto P_0c09ca5a;
case 0x0c09ca5cu: goto P_0c09ca5c;
case 0x0c09ca5eu: goto P_0c09ca5e;
case 0x0c09ca60u: goto P_0c09ca60;
case 0x0c09ca62u: goto P_0c09ca62;
case 0x0c09ca64u: goto P_0c09ca64;
case 0x0c09ca66u: goto P_0c09ca66;
case 0x0c09ca68u: goto P_0c09ca68;
case 0x0c09ca6au: goto P_0c09ca6a;
case 0x0c09ca6cu: goto P_0c09ca6c;
case 0x0c09ca6eu: goto P_0c09ca6e;
case 0x0c09ca70u: goto P_0c09ca70;
case 0x0c09ca72u: goto P_0c09ca72;
case 0x0c09ca74u: goto P_0c09ca74;
case 0x0c09ca76u: goto P_0c09ca76;
case 0x0c09ca78u: goto P_0c09ca78;
case 0x0c09ca7au: goto P_0c09ca7a;
case 0x0c09ca7cu: goto P_0c09ca7c;
case 0x0c09ca7eu: goto P_0c09ca7e;
case 0x0c09ca80u: goto P_0c09ca80;
case 0x0c09ca82u: goto P_0c09ca82;
case 0x0c09ca84u: goto P_0c09ca84;
case 0x0c09ca86u: goto P_0c09ca86;
case 0x0c09ca88u: goto P_0c09ca88;
case 0x0c09ca8au: goto P_0c09ca8a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09befc: /* original 6242, guest PC 0x0c09befc */
if(!s->budget--) { s->failed_pc=0x0c09befcu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09befe;
P_0c09befe: /* original 5341, guest PC 0x0c09befe */
if(!s->budget--) { s->failed_pc=0x0c09befeu; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c09bf00;
P_0c09bf00: /* original 5142, guest PC 0x0c09bf00 */
if(!s->budget--) { s->failed_pc=0x0c09bf00u; return 0; }
r[1]=read(ram,r[4]+8,4);
goto P_0c09bf02;
P_0c09bf02: /* original 2239, guest PC 0x0c09bf02 */
if(!s->budget--) { s->failed_pc=0x0c09bf02u; return 0; }
r[2]&=r[3];
goto P_0c09bf04;
P_0c09bf04: /* original 2219, guest PC 0x0c09bf04 */
if(!s->budget--) { s->failed_pc=0x0c09bf04u; return 0; }
r[2]&=r[1];
goto P_0c09bf06;
P_0c09bf06: /* original 2258, guest PC 0x0c09bf06 */
if(!s->budget--) { s->failed_pc=0x0c09bf06u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf08;
P_0c09bf08: /* original 8902, guest PC 0x0c09bf08 */
if(!s->budget--) { s->failed_pc=0x0c09bf08u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf10; }
goto P_0c09bf0a;
P_0c09bf0a: /* original 9044, guest PC 0x0c09bf0a */
if(!s->budget--) { s->failed_pc=0x0c09bf0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bf96u,2);
goto P_0c09bf0c;
P_0c09bf0c: /* original 000b, guest PC 0x0c09bf0c */
if(!s->budget--) { s->failed_pc=0x0c09bf0cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09bf0e: /* original 0009, guest PC 0x0c09bf0e */
if(!s->budget--) { s->failed_pc=0x0c09bf0eu; return 0; }
goto P_0c09bf10;
P_0c09bf10: /* original 6242, guest PC 0x0c09bf10 */
if(!s->budget--) { s->failed_pc=0x0c09bf10u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09bf12;
P_0c09bf12: /* original 5342, guest PC 0x0c09bf12 */
if(!s->budget--) { s->failed_pc=0x0c09bf12u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c09bf14;
P_0c09bf14: /* original 2239, guest PC 0x0c09bf14 */
if(!s->budget--) { s->failed_pc=0x0c09bf14u; return 0; }
r[2]&=r[3];
goto P_0c09bf16;
P_0c09bf16: /* original 2258, guest PC 0x0c09bf16 */
if(!s->budget--) { s->failed_pc=0x0c09bf16u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf18;
P_0c09bf18: /* original 8901, guest PC 0x0c09bf18 */
if(!s->budget--) { s->failed_pc=0x0c09bf18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf1e; }
goto P_0c09bf1a;
P_0c09bf1a: /* original 000b, guest PC 0x0c09bf1a */
if(!s->budget--) { s->failed_pc=0x0c09bf1au; return 0; }
target=r[16];
r[0]=0x00000020u;
s->pc=target; return ram->oob==0;
P_0c09bf1c: /* original e020, guest PC 0x0c09bf1c */
if(!s->budget--) { s->failed_pc=0x0c09bf1cu; return 0; }
r[0]=0x00000020u;
goto P_0c09bf1e;
P_0c09bf1e: /* original 6242, guest PC 0x0c09bf1e */
if(!s->budget--) { s->failed_pc=0x0c09bf1eu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09bf20;
P_0c09bf20: /* original 5343, guest PC 0x0c09bf20 */
if(!s->budget--) { s->failed_pc=0x0c09bf20u; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c09bf22;
P_0c09bf22: /* original 2239, guest PC 0x0c09bf22 */
if(!s->budget--) { s->failed_pc=0x0c09bf22u; return 0; }
r[2]&=r[3];
goto P_0c09bf24;
P_0c09bf24: /* original 2258, guest PC 0x0c09bf24 */
if(!s->budget--) { s->failed_pc=0x0c09bf24u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf26;
P_0c09bf26: /* original 8901, guest PC 0x0c09bf26 */
if(!s->budget--) { s->failed_pc=0x0c09bf26u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf2c; }
goto P_0c09bf28;
P_0c09bf28: /* original 000b, guest PC 0x0c09bf28 */
if(!s->budget--) { s->failed_pc=0x0c09bf28u; return 0; }
target=r[16];
r[0]=0x00000040u;
s->pc=target; return ram->oob==0;
P_0c09bf2a: /* original e040, guest PC 0x0c09bf2a */
if(!s->budget--) { s->failed_pc=0x0c09bf2au; return 0; }
r[0]=0x00000040u;
goto P_0c09bf2c;
P_0c09bf2c: /* original 5241, guest PC 0x0c09bf2c */
if(!s->budget--) { s->failed_pc=0x0c09bf2cu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c09bf2e;
P_0c09bf2e: /* original 5342, guest PC 0x0c09bf2e */
if(!s->budget--) { s->failed_pc=0x0c09bf2eu; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c09bf30;
P_0c09bf30: /* original 2239, guest PC 0x0c09bf30 */
if(!s->budget--) { s->failed_pc=0x0c09bf30u; return 0; }
r[2]&=r[3];
goto P_0c09bf32;
P_0c09bf32: /* original 2258, guest PC 0x0c09bf32 */
if(!s->budget--) { s->failed_pc=0x0c09bf32u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf34;
P_0c09bf34: /* original 8902, guest PC 0x0c09bf34 */
if(!s->budget--) { s->failed_pc=0x0c09bf34u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf3c; }
goto P_0c09bf36;
P_0c09bf36: /* original 902f, guest PC 0x0c09bf36 */
if(!s->budget--) { s->failed_pc=0x0c09bf36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bf98u,2);
goto P_0c09bf38;
P_0c09bf38: /* original 000b, guest PC 0x0c09bf38 */
if(!s->budget--) { s->failed_pc=0x0c09bf38u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09bf3a: /* original 0009, guest PC 0x0c09bf3a */
if(!s->budget--) { s->failed_pc=0x0c09bf3au; return 0; }
goto P_0c09bf3c;
P_0c09bf3c: /* original 5241, guest PC 0x0c09bf3c */
if(!s->budget--) { s->failed_pc=0x0c09bf3cu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c09bf3e;
P_0c09bf3e: /* original 5343, guest PC 0x0c09bf3e */
if(!s->budget--) { s->failed_pc=0x0c09bf3eu; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c09bf40;
P_0c09bf40: /* original 2239, guest PC 0x0c09bf40 */
if(!s->budget--) { s->failed_pc=0x0c09bf40u; return 0; }
r[2]&=r[3];
goto P_0c09bf42;
P_0c09bf42: /* original 2258, guest PC 0x0c09bf42 */
if(!s->budget--) { s->failed_pc=0x0c09bf42u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf44;
P_0c09bf44: /* original 8902, guest PC 0x0c09bf44 */
if(!s->budget--) { s->failed_pc=0x0c09bf44u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf4c; }
goto P_0c09bf46;
P_0c09bf46: /* original 9028, guest PC 0x0c09bf46 */
if(!s->budget--) { s->failed_pc=0x0c09bf46u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bf9au,2);
goto P_0c09bf48;
P_0c09bf48: /* original 000b, guest PC 0x0c09bf48 */
if(!s->budget--) { s->failed_pc=0x0c09bf48u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09bf4a: /* original 0009, guest PC 0x0c09bf4a */
if(!s->budget--) { s->failed_pc=0x0c09bf4au; return 0; }
goto P_0c09bf4c;
P_0c09bf4c: /* original 6242, guest PC 0x0c09bf4c */
if(!s->budget--) { s->failed_pc=0x0c09bf4cu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09bf4e;
P_0c09bf4e: /* original 5341, guest PC 0x0c09bf4e */
if(!s->budget--) { s->failed_pc=0x0c09bf4eu; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c09bf50;
P_0c09bf50: /* original 2239, guest PC 0x0c09bf50 */
if(!s->budget--) { s->failed_pc=0x0c09bf50u; return 0; }
r[2]&=r[3];
goto P_0c09bf52;
P_0c09bf52: /* original 2258, guest PC 0x0c09bf52 */
if(!s->budget--) { s->failed_pc=0x0c09bf52u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf54;
P_0c09bf54: /* original 8902, guest PC 0x0c09bf54 */
if(!s->budget--) { s->failed_pc=0x0c09bf54u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf5c; }
goto P_0c09bf56;
P_0c09bf56: /* original 9021, guest PC 0x0c09bf56 */
if(!s->budget--) { s->failed_pc=0x0c09bf56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bf9cu,2);
goto P_0c09bf58;
P_0c09bf58: /* original 000b, guest PC 0x0c09bf58 */
if(!s->budget--) { s->failed_pc=0x0c09bf58u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09bf5a: /* original 0009, guest PC 0x0c09bf5a */
if(!s->budget--) { s->failed_pc=0x0c09bf5au; return 0; }
goto P_0c09bf5c;
P_0c09bf5c: /* original 6242, guest PC 0x0c09bf5c */
if(!s->budget--) { s->failed_pc=0x0c09bf5cu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09bf5e;
P_0c09bf5e: /* original 2258, guest PC 0x0c09bf5e */
if(!s->budget--) { s->failed_pc=0x0c09bf5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf60;
P_0c09bf60: /* original 8901, guest PC 0x0c09bf60 */
if(!s->budget--) { s->failed_pc=0x0c09bf60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf66; }
goto P_0c09bf62;
P_0c09bf62: /* original 000b, guest PC 0x0c09bf62 */
if(!s->budget--) { s->failed_pc=0x0c09bf62u; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c09bf64: /* original e001, guest PC 0x0c09bf64 */
if(!s->budget--) { s->failed_pc=0x0c09bf64u; return 0; }
r[0]=0x00000001u;
goto P_0c09bf66;
P_0c09bf66: /* original 5241, guest PC 0x0c09bf66 */
if(!s->budget--) { s->failed_pc=0x0c09bf66u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c09bf68;
P_0c09bf68: /* original 2258, guest PC 0x0c09bf68 */
if(!s->budget--) { s->failed_pc=0x0c09bf68u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf6a;
P_0c09bf6a: /* original 8901, guest PC 0x0c09bf6a */
if(!s->budget--) { s->failed_pc=0x0c09bf6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf70; }
goto P_0c09bf6c;
P_0c09bf6c: /* original 000b, guest PC 0x0c09bf6c */
if(!s->budget--) { s->failed_pc=0x0c09bf6cu; return 0; }
target=r[16];
r[0]=0x00000002u;
s->pc=target; return ram->oob==0;
P_0c09bf6e: /* original e002, guest PC 0x0c09bf6e */
if(!s->budget--) { s->failed_pc=0x0c09bf6eu; return 0; }
r[0]=0x00000002u;
goto P_0c09bf70;
P_0c09bf70: /* original 5242, guest PC 0x0c09bf70 */
if(!s->budget--) { s->failed_pc=0x0c09bf70u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c09bf72;
P_0c09bf72: /* original 2258, guest PC 0x0c09bf72 */
if(!s->budget--) { s->failed_pc=0x0c09bf72u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf74;
P_0c09bf74: /* original 8901, guest PC 0x0c09bf74 */
if(!s->budget--) { s->failed_pc=0x0c09bf74u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf7a; }
goto P_0c09bf76;
P_0c09bf76: /* original 000b, guest PC 0x0c09bf76 */
if(!s->budget--) { s->failed_pc=0x0c09bf76u; return 0; }
target=r[16];
r[0]=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c09bf78: /* original e004, guest PC 0x0c09bf78 */
if(!s->budget--) { s->failed_pc=0x0c09bf78u; return 0; }
r[0]=0x00000004u;
goto P_0c09bf7a;
P_0c09bf7a: /* original 5243, guest PC 0x0c09bf7a */
if(!s->budget--) { s->failed_pc=0x0c09bf7au; return 0; }
r[2]=read(ram,r[4]+12,4);
goto P_0c09bf7c;
P_0c09bf7c: /* original 2258, guest PC 0x0c09bf7c */
if(!s->budget--) { s->failed_pc=0x0c09bf7cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf7e;
P_0c09bf7e: /* original 8901, guest PC 0x0c09bf7e */
if(!s->budget--) { s->failed_pc=0x0c09bf7eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf84; }
goto P_0c09bf80;
P_0c09bf80: /* original 000b, guest PC 0x0c09bf80 */
if(!s->budget--) { s->failed_pc=0x0c09bf80u; return 0; }
target=r[16];
r[0]=0x00000008u;
s->pc=target; return ram->oob==0;
P_0c09bf82: /* original e008, guest PC 0x0c09bf82 */
if(!s->budget--) { s->failed_pc=0x0c09bf82u; return 0; }
r[0]=0x00000008u;
goto P_0c09bf84;
P_0c09bf84: /* original 5244, guest PC 0x0c09bf84 */
if(!s->budget--) { s->failed_pc=0x0c09bf84u; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c09bf86;
P_0c09bf86: /* original 2528, guest PC 0x0c09bf86 */
if(!s->budget--) { s->failed_pc=0x0c09bf86u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c09bf88;
P_0c09bf88: /* original 8901, guest PC 0x0c09bf88 */
if(!s->budget--) { s->failed_pc=0x0c09bf88u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf8e; }
goto P_0c09bf8a;
P_0c09bf8a: /* original 000b, guest PC 0x0c09bf8a */
if(!s->budget--) { s->failed_pc=0x0c09bf8au; return 0; }
target=r[16];
r[0]=0x00000010u;
s->pc=target; return ram->oob==0;
P_0c09bf8c: /* original e010, guest PC 0x0c09bf8c */
if(!s->budget--) { s->failed_pc=0x0c09bf8cu; return 0; }
r[0]=0x00000010u;
goto P_0c09bf8e;
P_0c09bf8e: /* original e000, guest PC 0x0c09bf8e */
if(!s->budget--) { s->failed_pc=0x0c09bf8eu; return 0; }
r[0]=0x00000000u;
goto P_0c09bf90;
P_0c09bf90: /* original 000b, guest PC 0x0c09bf90 */
if(!s->budget--) { s->failed_pc=0x0c09bf90u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09bf92: /* original 0009, guest PC 0x0c09bf92 */
if(!s->budget--) { s->failed_pc=0x0c09bf92u; return 0; }
if(!vf3_matrix_family(0x0c09bf94u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09bf94u; return 0; } return 1;
P_0c09bfa8: /* original 6043, guest PC 0x0c09bfa8 */
if(!s->budget--) { s->failed_pc=0x0c09bfa8u; return 0; }
r[0]=r[4];
goto P_0c09bfaa;
P_0c09bfaa: /* original 9384, guest PC 0x0c09bfaa */
if(!s->budget--) { s->failed_pc=0x0c09bfaau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0b6u,2);
goto P_0c09bfac;
P_0c09bfac: /* original 4008, guest PC 0x0c09bfac */
if(!s->budget--) { s->failed_pc=0x0c09bfacu; return 0; }
r[0]<<=2;
goto P_0c09bfae;
P_0c09bfae: /* original d746, guest PC 0x0c09bfae */
if(!s->budget--) { s->failed_pc=0x0c09bfaeu; return 0; }
r[7]=read(ram,0x0c09c0c8u,4);
goto P_0c09bfb0;
P_0c09bfb0: /* original 4008, guest PC 0x0c09bfb0 */
if(!s->budget--) { s->failed_pc=0x0c09bfb0u; return 0; }
r[0]<<=2;
goto P_0c09bfb2;
P_0c09bfb2: /* original 337c, guest PC 0x0c09bfb2 */
if(!s->budget--) { s->failed_pc=0x0c09bfb2u; return 0; }
r[3]+=r[7];
goto P_0c09bfb4;
P_0c09bfb4: /* original 4008, guest PC 0x0c09bfb4 */
if(!s->budget--) { s->failed_pc=0x0c09bfb4u; return 0; }
r[0]<<=2;
goto P_0c09bfb6;
P_0c09bfb6: /* original 330c, guest PC 0x0c09bfb6 */
if(!s->budget--) { s->failed_pc=0x0c09bfb6u; return 0; }
r[3]+=r[0];
goto P_0c09bfb8;
P_0c09bfb8: /* original 5231, guest PC 0x0c09bfb8 */
if(!s->budget--) { s->failed_pc=0x0c09bfb8u; return 0; }
r[2]=read(ram,r[3]+4,4);
goto P_0c09bfba;
P_0c09bfba: /* original 2258, guest PC 0x0c09bfba */
if(!s->budget--) { s->failed_pc=0x0c09bfbau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bfbc;
P_0c09bfbc: /* original 8d01, guest PC 0x0c09bfbc */
if(!s->budget--) { s->failed_pc=0x0c09bfbcu; return 0; }
cond=r[17]&1u;
r[6]=0x00000000u;
if(cond) { goto P_0c09bfc2; }
goto P_0c09bfc0;
P_0c09bfbe: /* original e600, guest PC 0x0c09bfbe */
if(!s->budget--) { s->failed_pc=0x0c09bfbeu; return 0; }
r[6]=0x00000000u;
goto P_0c09bfc0;
P_0c09bfc0: /* original e604, guest PC 0x0c09bfc0 */
if(!s->budget--) { s->failed_pc=0x0c09bfc0u; return 0; }
r[6]=0x00000004u;
goto P_0c09bfc2;
P_0c09bfc2: /* original 9278, guest PC 0x0c09bfc2 */
if(!s->budget--) { s->failed_pc=0x0c09bfc2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0b6u,2);
goto P_0c09bfc4;
P_0c09bfc4: /* original 327c, guest PC 0x0c09bfc4 */
if(!s->budget--) { s->failed_pc=0x0c09bfc4u; return 0; }
r[2]+=r[7];
goto P_0c09bfc6;
P_0c09bfc6: /* original 320c, guest PC 0x0c09bfc6 */
if(!s->budget--) { s->failed_pc=0x0c09bfc6u; return 0; }
r[2]+=r[0];
goto P_0c09bfc8;
P_0c09bfc8: /* original 5322, guest PC 0x0c09bfc8 */
if(!s->budget--) { s->failed_pc=0x0c09bfc8u; return 0; }
r[3]=read(ram,r[2]+8,4);
goto P_0c09bfca;
P_0c09bfca: /* original 2358, guest PC 0x0c09bfca */
if(!s->budget--) { s->failed_pc=0x0c09bfcau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c09bfcc;
P_0c09bfcc: /* original 8901, guest PC 0x0c09bfcc */
if(!s->budget--) { s->failed_pc=0x0c09bfccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bfd2; }
goto P_0c09bfce;
P_0c09bfce: /* original e102, guest PC 0x0c09bfce */
if(!s->budget--) { s->failed_pc=0x0c09bfceu; return 0; }
r[1]=0x00000002u;
goto P_0c09bfd0;
P_0c09bfd0: /* original 261b, guest PC 0x0c09bfd0 */
if(!s->budget--) { s->failed_pc=0x0c09bfd0u; return 0; }
r[6]|=r[1];
goto P_0c09bfd2;
P_0c09bfd2: /* original 9370, guest PC 0x0c09bfd2 */
if(!s->budget--) { s->failed_pc=0x0c09bfd2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0b6u,2);
goto P_0c09bfd4;
P_0c09bfd4: /* original 337c, guest PC 0x0c09bfd4 */
if(!s->budget--) { s->failed_pc=0x0c09bfd4u; return 0; }
r[3]+=r[7];
goto P_0c09bfd6;
P_0c09bfd6: /* original 330c, guest PC 0x0c09bfd6 */
if(!s->budget--) { s->failed_pc=0x0c09bfd6u; return 0; }
r[3]+=r[0];
goto P_0c09bfd8;
P_0c09bfd8: /* original 5233, guest PC 0x0c09bfd8 */
if(!s->budget--) { s->failed_pc=0x0c09bfd8u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c09bfda;
P_0c09bfda: /* original 2258, guest PC 0x0c09bfda */
if(!s->budget--) { s->failed_pc=0x0c09bfdau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bfdc;
P_0c09bfdc: /* original 8901, guest PC 0x0c09bfdc */
if(!s->budget--) { s->failed_pc=0x0c09bfdcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bfe2; }
goto P_0c09bfde;
P_0c09bfde: /* original e101, guest PC 0x0c09bfde */
if(!s->budget--) { s->failed_pc=0x0c09bfdeu; return 0; }
r[1]=0x00000001u;
goto P_0c09bfe0;
P_0c09bfe0: /* original 261b, guest PC 0x0c09bfe0 */
if(!s->budget--) { s->failed_pc=0x0c09bfe0u; return 0; }
r[6]|=r[1];
goto P_0c09bfe2;
P_0c09bfe2: /* original 9368, guest PC 0x0c09bfe2 */
if(!s->budget--) { s->failed_pc=0x0c09bfe2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0b6u,2);
goto P_0c09bfe4;
P_0c09bfe4: /* original 337c, guest PC 0x0c09bfe4 */
if(!s->budget--) { s->failed_pc=0x0c09bfe4u; return 0; }
r[3]+=r[7];
goto P_0c09bfe6;
P_0c09bfe6: /* original 330c, guest PC 0x0c09bfe6 */
if(!s->budget--) { s->failed_pc=0x0c09bfe6u; return 0; }
r[3]+=r[0];
goto P_0c09bfe8;
P_0c09bfe8: /* original 5234, guest PC 0x0c09bfe8 */
if(!s->budget--) { s->failed_pc=0x0c09bfe8u; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c09bfea;
P_0c09bfea: /* original 2258, guest PC 0x0c09bfea */
if(!s->budget--) { s->failed_pc=0x0c09bfeau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bfec;
P_0c09bfec: /* original 8901, guest PC 0x0c09bfec */
if(!s->budget--) { s->failed_pc=0x0c09bfecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bff2; }
goto P_0c09bfee;
P_0c09bfee: /* original 9163, guest PC 0x0c09bfee */
if(!s->budget--) { s->failed_pc=0x0c09bfeeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0b8u,2);
goto P_0c09bff0;
P_0c09bff0: /* original 261b, guest PC 0x0c09bff0 */
if(!s->budget--) { s->failed_pc=0x0c09bff0u; return 0; }
r[6]|=r[1];
goto P_0c09bff2;
P_0c09bff2: /* original 9360, guest PC 0x0c09bff2 */
if(!s->budget--) { s->failed_pc=0x0c09bff2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0b6u,2);
goto P_0c09bff4;
P_0c09bff4: /* original 337c, guest PC 0x0c09bff4 */
if(!s->budget--) { s->failed_pc=0x0c09bff4u; return 0; }
r[3]+=r[7];
goto P_0c09bff6;
P_0c09bff6: /* original 330c, guest PC 0x0c09bff6 */
if(!s->budget--) { s->failed_pc=0x0c09bff6u; return 0; }
r[3]+=r[0];
goto P_0c09bff8;
P_0c09bff8: /* original 5235, guest PC 0x0c09bff8 */
if(!s->budget--) { s->failed_pc=0x0c09bff8u; return 0; }
r[2]=read(ram,r[3]+20,4);
goto P_0c09bffa;
P_0c09bffa: /* original 2258, guest PC 0x0c09bffa */
if(!s->budget--) { s->failed_pc=0x0c09bffau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bffc;
P_0c09bffc: /* original 8901, guest PC 0x0c09bffc */
if(!s->budget--) { s->failed_pc=0x0c09bffcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c002; }
goto P_0c09bffe;
P_0c09bffe: /* original 915c, guest PC 0x0c09bffe */
if(!s->budget--) { s->failed_pc=0x0c09bffeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0bau,2);
goto P_0c09c000;
P_0c09c000: /* original 261b, guest PC 0x0c09c000 */
if(!s->budget--) { s->failed_pc=0x0c09c000u; return 0; }
r[6]|=r[1];
goto P_0c09c002;
P_0c09c002: /* original 9358, guest PC 0x0c09c002 */
if(!s->budget--) { s->failed_pc=0x0c09c002u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0b6u,2);
goto P_0c09c004;
P_0c09c004: /* original 337c, guest PC 0x0c09c004 */
if(!s->budget--) { s->failed_pc=0x0c09c004u; return 0; }
r[3]+=r[7];
goto P_0c09c006;
P_0c09c006: /* original 330c, guest PC 0x0c09c006 */
if(!s->budget--) { s->failed_pc=0x0c09c006u; return 0; }
r[3]+=r[0];
goto P_0c09c008;
P_0c09c008: /* original 5236, guest PC 0x0c09c008 */
if(!s->budget--) { s->failed_pc=0x0c09c008u; return 0; }
r[2]=read(ram,r[3]+24,4);
goto P_0c09c00a;
P_0c09c00a: /* original 2258, guest PC 0x0c09c00a */
if(!s->budget--) { s->failed_pc=0x0c09c00au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09c00c;
P_0c09c00c: /* original 8901, guest PC 0x0c09c00c */
if(!s->budget--) { s->failed_pc=0x0c09c00cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c012; }
goto P_0c09c00e;
P_0c09c00e: /* original 9155, guest PC 0x0c09c00e */
if(!s->budget--) { s->failed_pc=0x0c09c00eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0bcu,2);
goto P_0c09c010;
P_0c09c010: /* original 261b, guest PC 0x0c09c010 */
if(!s->budget--) { s->failed_pc=0x0c09c010u; return 0; }
r[6]|=r[1];
goto P_0c09c012;
P_0c09c012: /* original 9350, guest PC 0x0c09c012 */
if(!s->budget--) { s->failed_pc=0x0c09c012u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0b6u,2);
goto P_0c09c014;
P_0c09c014: /* original 337c, guest PC 0x0c09c014 */
if(!s->budget--) { s->failed_pc=0x0c09c014u; return 0; }
r[3]+=r[7];
goto P_0c09c016;
P_0c09c016: /* original 330c, guest PC 0x0c09c016 */
if(!s->budget--) { s->failed_pc=0x0c09c016u; return 0; }
r[3]+=r[0];
goto P_0c09c018;
P_0c09c018: /* original 5237, guest PC 0x0c09c018 */
if(!s->budget--) { s->failed_pc=0x0c09c018u; return 0; }
r[2]=read(ram,r[3]+28,4);
goto P_0c09c01a;
P_0c09c01a: /* original 2258, guest PC 0x0c09c01a */
if(!s->budget--) { s->failed_pc=0x0c09c01au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09c01c;
P_0c09c01c: /* original 8901, guest PC 0x0c09c01c */
if(!s->budget--) { s->failed_pc=0x0c09c01cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c022; }
goto P_0c09c01e;
P_0c09c01e: /* original d12b, guest PC 0x0c09c01e */
if(!s->budget--) { s->failed_pc=0x0c09c01eu; return 0; }
r[1]=read(ram,0x0c09c0ccu,4);
goto P_0c09c020;
P_0c09c020: /* original 261b, guest PC 0x0c09c020 */
if(!s->budget--) { s->failed_pc=0x0c09c020u; return 0; }
r[6]|=r[1];
goto P_0c09c022;
P_0c09c022: /* original 9348, guest PC 0x0c09c022 */
if(!s->budget--) { s->failed_pc=0x0c09c022u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0b6u,2);
goto P_0c09c024;
P_0c09c024: /* original 337c, guest PC 0x0c09c024 */
if(!s->budget--) { s->failed_pc=0x0c09c024u; return 0; }
r[3]+=r[7];
goto P_0c09c026;
P_0c09c026: /* original 303c, guest PC 0x0c09c026 */
if(!s->budget--) { s->failed_pc=0x0c09c026u; return 0; }
r[0]+=r[3];
goto P_0c09c028;
P_0c09c028: /* original 5208, guest PC 0x0c09c028 */
if(!s->budget--) { s->failed_pc=0x0c09c028u; return 0; }
r[2]=read(ram,r[0]+32,4);
goto P_0c09c02a;
P_0c09c02a: /* original 2528, guest PC 0x0c09c02a */
if(!s->budget--) { s->failed_pc=0x0c09c02au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c09c02c;
P_0c09c02c: /* original 8901, guest PC 0x0c09c02c */
if(!s->budget--) { s->failed_pc=0x0c09c02cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c032; }
goto P_0c09c02e;
P_0c09c02e: /* original d128, guest PC 0x0c09c02e */
if(!s->budget--) { s->failed_pc=0x0c09c02eu; return 0; }
r[1]=read(ram,0x0c09c0d0u,4);
goto P_0c09c030;
P_0c09c030: /* original 261b, guest PC 0x0c09c030 */
if(!s->budget--) { s->failed_pc=0x0c09c030u; return 0; }
r[6]|=r[1];
goto P_0c09c032;
P_0c09c032: /* original 000b, guest PC 0x0c09c032 */
if(!s->budget--) { s->failed_pc=0x0c09c032u; return 0; }
target=r[16];
r[0]=r[6];
s->pc=target; return ram->oob==0;
P_0c09c034: /* original 6063, guest PC 0x0c09c034 */
if(!s->budget--) { s->failed_pc=0x0c09c034u; return 0; }
r[0]=r[6];
goto P_0c09c036;
P_0c09c036: /* original 2fe6, guest PC 0x0c09c036 */
if(!s->budget--) { s->failed_pc=0x0c09c036u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c038;
P_0c09c038: /* original 2fd6, guest PC 0x0c09c038 */
if(!s->budget--) { s->failed_pc=0x0c09c038u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c03a;
P_0c09c03a: /* original 2fc6, guest PC 0x0c09c03a */
if(!s->budget--) { s->failed_pc=0x0c09c03au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c03c;
P_0c09c03c: /* original 2fb6, guest PC 0x0c09c03c */
if(!s->budget--) { s->failed_pc=0x0c09c03cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c03e;
P_0c09c03e: /* original 2fa6, guest PC 0x0c09c03e */
if(!s->budget--) { s->failed_pc=0x0c09c03eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c040;
P_0c09c040: /* original 2f96, guest PC 0x0c09c040 */
if(!s->budget--) { s->failed_pc=0x0c09c040u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c042;
P_0c09c042: /* original 2f86, guest PC 0x0c09c042 */
if(!s->budget--) { s->failed_pc=0x0c09c042u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c044;
P_0c09c044: /* original 4f22, guest PC 0x0c09c044 */
if(!s->budget--) { s->failed_pc=0x0c09c044u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09c046;
P_0c09c046: /* original d323, guest PC 0x0c09c046 */
if(!s->budget--) { s->failed_pc=0x0c09c046u; return 0; }
r[3]=read(ram,0x0c09c0d4u,4);
goto P_0c09c048;
P_0c09c048: /* original de1f, guest PC 0x0c09c048 */
if(!s->budget--) { s->failed_pc=0x0c09c048u; return 0; }
r[14]=read(ram,0x0c09c0c8u,4);
goto P_0c09c04a;
P_0c09c04a: /* original 430b, guest PC 0x0c09c04a */
if(!s->budget--) { s->failed_pc=0x0c09c04au; return 0; }
target=r[3];
r[16]=code_base|0x0c09c04eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c04eu) { target=s->pc; goto dispatch; }
goto P_0c09c04e;
P_0c09c04c: /* original e400, guest PC 0x0c09c04c */
if(!s->budget--) { s->failed_pc=0x0c09c04cu; return 0; }
r[4]=0x00000000u;
goto P_0c09c04e;
P_0c09c04e: /* original e300, guest PC 0x0c09c04e */
if(!s->budget--) { s->failed_pc=0x0c09c04eu; return 0; }
r[3]=0x00000000u;
goto P_0c09c050;
P_0c09c050: /* original 6a33, guest PC 0x0c09c050 */
if(!s->budget--) { s->failed_pc=0x0c09c050u; return 0; }
r[10]=r[3];
goto P_0c09c052;
P_0c09c052: /* original e07d, guest PC 0x0c09c052 */
if(!s->budget--) { s->failed_pc=0x0c09c052u; return 0; }
r[0]=0x0000007du;
goto P_0c09c054;
P_0c09c054: /* original e240, guest PC 0x0c09c054 */
if(!s->budget--) { s->failed_pc=0x0c09c054u; return 0; }
r[2]=0x00000040u;
goto P_0c09c056;
P_0c09c056: /* original 1e23, guest PC 0x0c09c056 */
if(!s->budget--) { s->failed_pc=0x0c09c056u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c09c058;
P_0c09c058: /* original 62a3, guest PC 0x0c09c058 */
if(!s->budget--) { s->failed_pc=0x0c09c058u; return 0; }
r[2]=r[10];
goto P_0c09c05a;
P_0c09c05a: /* original 6b23, guest PC 0x0c09c05a */
if(!s->budget--) { s->failed_pc=0x0c09c05au; return 0; }
r[11]=r[2];
goto P_0c09c05c;
P_0c09c05c: /* original 1e36, guest PC 0x0c09c05c */
if(!s->budget--) { s->failed_pc=0x0c09c05cu; return 0; }
write(ram,r[14]+24,r[3],4);
goto P_0c09c05e;
P_0c09c05e: /* original 0ea4, guest PC 0x0c09c05e */
if(!s->budget--) { s->failed_pc=0x0c09c05eu; return 0; }
write(ram,r[14]+r[0],r[10],1);
goto P_0c09c060;
P_0c09c060: /* original 1ea5, guest PC 0x0c09c060 */
if(!s->budget--) { s->failed_pc=0x0c09c060u; return 0; }
write(ram,r[14]+20,r[10],4);
goto P_0c09c062;
P_0c09c062: /* original 902c, guest PC 0x0c09c062 */
if(!s->budget--) { s->failed_pc=0x0c09c062u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0beu,2);
goto P_0c09c064;
P_0c09c064: /* original 0ea6, guest PC 0x0c09c064 */
if(!s->budget--) { s->failed_pc=0x0c09c064u; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c09c066;
P_0c09c066: /* original 70fc, guest PC 0x0c09c066 */
if(!s->budget--) { s->failed_pc=0x0c09c066u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09c068;
P_0c09c068: /* original 0e26, guest PC 0x0c09c068 */
if(!s->budget--) { s->failed_pc=0x0c09c068u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09c06a;
P_0c09c06a: /* original d818, guest PC 0x0c09c06a */
if(!s->budget--) { s->failed_pc=0x0c09c06au; return 0; }
r[8]=read(ram,0x0c09c0ccu,4);
goto P_0c09c06c;
P_0c09c06c: /* original d918, guest PC 0x0c09c06c */
if(!s->budget--) { s->failed_pc=0x0c09c06cu; return 0; }
r[9]=read(ram,0x0c09c0d0u,4);
goto P_0c09c06e;
P_0c09c06e: /* original 9327, guest PC 0x0c09c06e */
if(!s->budget--) { s->failed_pc=0x0c09c06eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0c0u,2);
goto P_0c09c070;
P_0c09c070: /* original 6cb3, guest PC 0x0c09c070 */
if(!s->budget--) { s->failed_pc=0x0c09c070u; return 0; }
r[12]=r[11];
goto P_0c09c072;
P_0c09c072: /* original 9226, guest PC 0x0c09c072 */
if(!s->budget--) { s->failed_pc=0x0c09c072u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0c2u,2);
goto P_0c09c074;
P_0c09c074: /* original 4c08, guest PC 0x0c09c074 */
if(!s->budget--) { s->failed_pc=0x0c09c074u; return 0; }
r[12]<<=2;
goto P_0c09c076;
P_0c09c076: /* original 33ec, guest PC 0x0c09c076 */
if(!s->budget--) { s->failed_pc=0x0c09c076u; return 0; }
r[3]+=r[14];
goto P_0c09c078;
P_0c09c078: /* original 6db3, guest PC 0x0c09c078 */
if(!s->budget--) { s->failed_pc=0x0c09c078u; return 0; }
r[13]=r[11];
goto P_0c09c07a;
P_0c09c07a: /* original 33cc, guest PC 0x0c09c07a */
if(!s->budget--) { s->failed_pc=0x0c09c07au; return 0; }
r[3]+=r[12];
goto P_0c09c07c;
P_0c09c07c: /* original 9122, guest PC 0x0c09c07c */
if(!s->budget--) { s->failed_pc=0x0c09c07cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0c4u,2);
goto P_0c09c07e;
P_0c09c07e: /* original 32ec, guest PC 0x0c09c07e */
if(!s->budget--) { s->failed_pc=0x0c09c07eu; return 0; }
r[2]+=r[14];
goto P_0c09c080;
P_0c09c080: /* original 4d08, guest PC 0x0c09c080 */
if(!s->budget--) { s->failed_pc=0x0c09c080u; return 0; }
r[13]<<=2;
goto P_0c09c082;
P_0c09c082: /* original 4d00, guest PC 0x0c09c082 */
if(!s->budget--) { s->failed_pc=0x0c09c082u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c09c084;
P_0c09c084: /* original 32cc, guest PC 0x0c09c084 */
if(!s->budget--) { s->failed_pc=0x0c09c084u; return 0; }
r[2]+=r[12];
goto P_0c09c086;
P_0c09c086: /* original 31ec, guest PC 0x0c09c086 */
if(!s->budget--) { s->failed_pc=0x0c09c086u; return 0; }
r[1]+=r[14];
goto P_0c09c088;
P_0c09c088: /* original 31cc, guest PC 0x0c09c088 */
if(!s->budget--) { s->failed_pc=0x0c09c088u; return 0; }
r[1]+=r[12];
goto P_0c09c08a;
P_0c09c08a: /* original 21a2, guest PC 0x0c09c08a */
if(!s->budget--) { s->failed_pc=0x0c09c08au; return 0; }
write(ram,r[1],r[10],4);
goto P_0c09c08c;
P_0c09c08c: /* original 22a2, guest PC 0x0c09c08c */
if(!s->budget--) { s->failed_pc=0x0c09c08cu; return 0; }
write(ram,r[2],r[10],4);
goto P_0c09c08e;
P_0c09c08e: /* original 23a2, guest PC 0x0c09c08e */
if(!s->budget--) { s->failed_pc=0x0c09c08eu; return 0; }
write(ram,r[3],r[10],4);
goto P_0c09c090;
P_0c09c090: /* original 63b3, guest PC 0x0c09c090 */
if(!s->budget--) { s->failed_pc=0x0c09c090u; return 0; }
r[3]=r[11];
goto P_0c09c092;
P_0c09c092: /* original 3d3c, guest PC 0x0c09c092 */
if(!s->budget--) { s->failed_pc=0x0c09c092u; return 0; }
r[13]+=r[3];
goto P_0c09c094;
P_0c09c094: /* original d210, guest PC 0x0c09c094 */
if(!s->budget--) { s->failed_pc=0x0c09c094u; return 0; }
r[2]=read(ram,0x0c09c0d8u,4);
goto P_0c09c096;
P_0c09c096: /* original 4d08, guest PC 0x0c09c096 */
if(!s->budget--) { s->failed_pc=0x0c09c096u; return 0; }
r[13]<<=2;
goto P_0c09c098;
P_0c09c098: /* original d310, guest PC 0x0c09c098 */
if(!s->budget--) { s->failed_pc=0x0c09c098u; return 0; }
r[3]=read(ram,0x0c09c0dcu,4);
goto P_0c09c09a;
P_0c09c09a: /* original 6dde, guest PC 0x0c09c09a */
if(!s->budget--) { s->failed_pc=0x0c09c09au; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)r[13];
goto P_0c09c09c;
P_0c09c09c: /* original 3d2c, guest PC 0x0c09c09c */
if(!s->budget--) { s->failed_pc=0x0c09c09cu; return 0; }
r[13]+=r[2];
goto P_0c09c09e;
P_0c09c09e: /* original 430b, guest PC 0x0c09c09e */
if(!s->budget--) { s->failed_pc=0x0c09c09eu; return 0; }
target=r[3];
r[16]=code_base|0x0c09c0a2u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c0a2u) { target=s->pc; goto dispatch; }
goto P_0c09c0a2;
P_0c09c0a0: /* original 64b3, guest PC 0x0c09c0a0 */
if(!s->budget--) { s->failed_pc=0x0c09c0a0u; return 0; }
r[4]=r[11];
goto P_0c09c0a2;
P_0c09c0a2: /* original 6403, guest PC 0x0c09c0a2 */
if(!s->budget--) { s->failed_pc=0x0c09c0a2u; return 0; }
r[4]=r[0];
goto P_0c09c0a4;
P_0c09c0a4: /* original 6342, guest PC 0x0c09c0a4 */
if(!s->budget--) { s->failed_pc=0x0c09c0a4u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c09c0a6;
P_0c09c0a6: /* original d20e, guest PC 0x0c09c0a6 */
if(!s->budget--) { s->failed_pc=0x0c09c0a6u; return 0; }
r[2]=read(ram,0x0c09c0e0u,4);
goto P_0c09c0a8;
P_0c09c0a8: /* original 3320, guest PC 0x0c09c0a8 */
if(!s->budget--) { s->failed_pc=0x0c09c0a8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c09c0aa;
P_0c09c0aa: /* original 8b1b, guest PC 0x0c09c0aa */
if(!s->budget--) { s->failed_pc=0x0c09c0aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c0e4; }
goto P_0c09c0ac;
P_0c09c0ac: /* original 900b, guest PC 0x0c09c0ac */
if(!s->budget--) { s->failed_pc=0x0c09c0acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0c6u,2);
goto P_0c09c0ae;
P_0c09c0ae: /* original 30ec, guest PC 0x0c09c0ae */
if(!s->budget--) { s->failed_pc=0x0c09c0aeu; return 0; }
r[0]+=r[14];
goto P_0c09c0b0;
P_0c09c0b0: /* original 30cc, guest PC 0x0c09c0b0 */
if(!s->budget--) { s->failed_pc=0x0c09c0b0u; return 0; }
r[0]+=r[12];
goto P_0c09c0b2;
P_0c09c0b2: /* original a027, guest PC 0x0c09c0b2 */
if(!s->budget--) { s->failed_pc=0x0c09c0b2u; return 0; }
write(ram,r[0],r[10],4);
goto P_0c09c104;
P_0c09c0b4: /* original 20a2, guest PC 0x0c09c0b4 */
if(!s->budget--) { s->failed_pc=0x0c09c0b4u; return 0; }
write(ram,r[0],r[10],4);
if(!vf3_matrix_family(0x0c09c0b6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09c0b6u; return 0; } return 1;
P_0c09c0e4: /* original 6342, guest PC 0x0c09c0e4 */
if(!s->budget--) { s->failed_pc=0x0c09c0e4u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c09c0e6;
P_0c09c0e6: /* original 9191, guest PC 0x0c09c0e6 */
if(!s->budget--) { s->failed_pc=0x0c09c0e6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c20cu,2);
goto P_0c09c0e8;
P_0c09c0e8: /* original 3310, guest PC 0x0c09c0e8 */
if(!s->budget--) { s->failed_pc=0x0c09c0e8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c09c0ea;
P_0c09c0ea: /* original 8b06, guest PC 0x0c09c0ea */
if(!s->budget--) { s->failed_pc=0x0c09c0eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c0fa; }
goto P_0c09c0ec;
P_0c09c0ec: /* original 938f, guest PC 0x0c09c0ec */
if(!s->budget--) { s->failed_pc=0x0c09c0ecu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c20eu,2);
goto P_0c09c0ee;
P_0c09c0ee: /* original e001, guest PC 0x0c09c0ee */
if(!s->budget--) { s->failed_pc=0x0c09c0eeu; return 0; }
r[0]=0x00000001u;
goto P_0c09c0f0;
P_0c09c0f0: /* original 33ec, guest PC 0x0c09c0f0 */
if(!s->budget--) { s->failed_pc=0x0c09c0f0u; return 0; }
r[3]+=r[14];
goto P_0c09c0f2;
P_0c09c0f2: /* original 33cc, guest PC 0x0c09c0f2 */
if(!s->budget--) { s->failed_pc=0x0c09c0f2u; return 0; }
r[3]+=r[12];
goto P_0c09c0f4;
P_0c09c0f4: /* original 2302, guest PC 0x0c09c0f4 */
if(!s->budget--) { s->failed_pc=0x0c09c0f4u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c09c0f6;
P_0c09c0f6: /* original a005, guest PC 0x0c09c0f6 */
if(!s->budget--) { s->failed_pc=0x0c09c0f6u; return 0; }
goto P_0c09c104;
P_0c09c0f8: /* original 0009, guest PC 0x0c09c0f8 */
if(!s->budget--) { s->failed_pc=0x0c09c0f8u; return 0; }
goto P_0c09c0fa;
P_0c09c0fa: /* original 9388, guest PC 0x0c09c0fa */
if(!s->budget--) { s->failed_pc=0x0c09c0fau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c20eu,2);
goto P_0c09c0fc;
P_0c09c0fc: /* original e0ff, guest PC 0x0c09c0fc */
if(!s->budget--) { s->failed_pc=0x0c09c0fcu; return 0; }
r[0]=0xffffffffu;
goto P_0c09c0fe;
P_0c09c0fe: /* original 33ec, guest PC 0x0c09c0fe */
if(!s->budget--) { s->failed_pc=0x0c09c0feu; return 0; }
r[3]+=r[14];
goto P_0c09c100;
P_0c09c100: /* original 33cc, guest PC 0x0c09c100 */
if(!s->budget--) { s->failed_pc=0x0c09c100u; return 0; }
r[3]+=r[12];
goto P_0c09c102;
P_0c09c102: /* original 2302, guest PC 0x0c09c102 */
if(!s->budget--) { s->failed_pc=0x0c09c102u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c09c104;
P_0c09c104: /* original 6cb3, guest PC 0x0c09c104 */
if(!s->budget--) { s->failed_pc=0x0c09c104u; return 0; }
r[12]=r[11];
goto P_0c09c106;
P_0c09c106: /* original 9383, guest PC 0x0c09c106 */
if(!s->budget--) { s->failed_pc=0x0c09c106u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c210u,2);
goto P_0c09c108;
P_0c09c108: /* original 4c08, guest PC 0x0c09c108 */
if(!s->budget--) { s->failed_pc=0x0c09c108u; return 0; }
r[12]<<=2;
goto P_0c09c10a;
P_0c09c10a: /* original 4c08, guest PC 0x0c09c10a */
if(!s->budget--) { s->failed_pc=0x0c09c10au; return 0; }
r[12]<<=2;
goto P_0c09c10c;
P_0c09c10c: /* original 33ec, guest PC 0x0c09c10c */
if(!s->budget--) { s->failed_pc=0x0c09c10cu; return 0; }
r[3]+=r[14];
goto P_0c09c10e;
P_0c09c10e: /* original 4c08, guest PC 0x0c09c10e */
if(!s->budget--) { s->failed_pc=0x0c09c10eu; return 0; }
r[12]<<=2;
goto P_0c09c110;
P_0c09c110: /* original e104, guest PC 0x0c09c110 */
if(!s->budget--) { s->failed_pc=0x0c09c110u; return 0; }
r[1]=0x00000004u;
goto P_0c09c112;
P_0c09c112: /* original 33cc, guest PC 0x0c09c112 */
if(!s->budget--) { s->failed_pc=0x0c09c112u; return 0; }
r[3]+=r[12];
goto P_0c09c114;
P_0c09c114: /* original 313c, guest PC 0x0c09c114 */
if(!s->budget--) { s->failed_pc=0x0c09c114u; return 0; }
r[1]+=r[3];
goto P_0c09c116;
P_0c09c116: /* original e504, guest PC 0x0c09c116 */
if(!s->budget--) { s->failed_pc=0x0c09c116u; return 0; }
r[5]=0x00000004u;
goto P_0c09c118;
P_0c09c118: /* original 2f16, guest PC 0x0c09c118 */
if(!s->budget--) { s->failed_pc=0x0c09c118u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c11a;
P_0c09c11a: /* original beef, guest PC 0x0c09c11a */
if(!s->budget--) { s->failed_pc=0x0c09c11au; return 0; }
target=code_base|0x0c09befcu; r[16]=code_base|0x0c09c11eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c11eu) { target=s->pc; goto dispatch; }
goto P_0c09c11e;
P_0c09c11c: /* original 64d3, guest PC 0x0c09c11c */
if(!s->budget--) { s->failed_pc=0x0c09c11cu; return 0; }
r[4]=r[13];
goto P_0c09c11e;
P_0c09c11e: /* original e108, guest PC 0x0c09c11e */
if(!s->budget--) { s->failed_pc=0x0c09c11eu; return 0; }
r[1]=0x00000008u;
goto P_0c09c120;
P_0c09c120: /* original 62f6, guest PC 0x0c09c120 */
if(!s->budget--) { s->failed_pc=0x0c09c120u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c09c122;
P_0c09c122: /* original e502, guest PC 0x0c09c122 */
if(!s->budget--) { s->failed_pc=0x0c09c122u; return 0; }
r[5]=0x00000002u;
goto P_0c09c124;
P_0c09c124: /* original 2202, guest PC 0x0c09c124 */
if(!s->budget--) { s->failed_pc=0x0c09c124u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c09c126;
P_0c09c126: /* original 9373, guest PC 0x0c09c126 */
if(!s->budget--) { s->failed_pc=0x0c09c126u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c210u,2);
goto P_0c09c128;
P_0c09c128: /* original 33ec, guest PC 0x0c09c128 */
if(!s->budget--) { s->failed_pc=0x0c09c128u; return 0; }
r[3]+=r[14];
goto P_0c09c12a;
P_0c09c12a: /* original 33cc, guest PC 0x0c09c12a */
if(!s->budget--) { s->failed_pc=0x0c09c12au; return 0; }
r[3]+=r[12];
goto P_0c09c12c;
P_0c09c12c: /* original 313c, guest PC 0x0c09c12c */
if(!s->budget--) { s->failed_pc=0x0c09c12cu; return 0; }
r[1]+=r[3];
goto P_0c09c12e;
P_0c09c12e: /* original 2f16, guest PC 0x0c09c12e */
if(!s->budget--) { s->failed_pc=0x0c09c12eu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c130;
P_0c09c130: /* original bee4, guest PC 0x0c09c130 */
if(!s->budget--) { s->failed_pc=0x0c09c130u; return 0; }
target=code_base|0x0c09befcu; r[16]=code_base|0x0c09c134u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c134u) { target=s->pc; goto dispatch; }
goto P_0c09c134;
P_0c09c132: /* original 64d3, guest PC 0x0c09c132 */
if(!s->budget--) { s->failed_pc=0x0c09c132u; return 0; }
r[4]=r[13];
goto P_0c09c134;
P_0c09c134: /* original e10c, guest PC 0x0c09c134 */
if(!s->budget--) { s->failed_pc=0x0c09c134u; return 0; }
r[1]=0x0000000cu;
goto P_0c09c136;
P_0c09c136: /* original 62f6, guest PC 0x0c09c136 */
if(!s->budget--) { s->failed_pc=0x0c09c136u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c09c138;
P_0c09c138: /* original e501, guest PC 0x0c09c138 */
if(!s->budget--) { s->failed_pc=0x0c09c138u; return 0; }
r[5]=0x00000001u;
goto P_0c09c13a;
P_0c09c13a: /* original 2202, guest PC 0x0c09c13a */
if(!s->budget--) { s->failed_pc=0x0c09c13au; return 0; }
write(ram,r[2],r[0],4);
goto P_0c09c13c;
P_0c09c13c: /* original 9368, guest PC 0x0c09c13c */
if(!s->budget--) { s->failed_pc=0x0c09c13cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c210u,2);
goto P_0c09c13e;
P_0c09c13e: /* original 33ec, guest PC 0x0c09c13e */
if(!s->budget--) { s->failed_pc=0x0c09c13eu; return 0; }
r[3]+=r[14];
goto P_0c09c140;
P_0c09c140: /* original 33cc, guest PC 0x0c09c140 */
if(!s->budget--) { s->failed_pc=0x0c09c140u; return 0; }
r[3]+=r[12];
goto P_0c09c142;
P_0c09c142: /* original 313c, guest PC 0x0c09c142 */
if(!s->budget--) { s->failed_pc=0x0c09c142u; return 0; }
r[1]+=r[3];
goto P_0c09c144;
P_0c09c144: /* original 2f16, guest PC 0x0c09c144 */
if(!s->budget--) { s->failed_pc=0x0c09c144u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c146;
P_0c09c146: /* original bed9, guest PC 0x0c09c146 */
if(!s->budget--) { s->failed_pc=0x0c09c146u; return 0; }
target=code_base|0x0c09befcu; r[16]=code_base|0x0c09c14au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c14au) { target=s->pc; goto dispatch; }
goto P_0c09c14a;
P_0c09c148: /* original 64d3, guest PC 0x0c09c148 */
if(!s->budget--) { s->failed_pc=0x0c09c148u; return 0; }
r[4]=r[13];
goto P_0c09c14a;
P_0c09c14a: /* original e110, guest PC 0x0c09c14a */
if(!s->budget--) { s->failed_pc=0x0c09c14au; return 0; }
r[1]=0x00000010u;
goto P_0c09c14c;
P_0c09c14c: /* original 62f6, guest PC 0x0c09c14c */
if(!s->budget--) { s->failed_pc=0x0c09c14cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c09c14e;
P_0c09c14e: /* original 2202, guest PC 0x0c09c14e */
if(!s->budget--) { s->failed_pc=0x0c09c14eu; return 0; }
write(ram,r[2],r[0],4);
goto P_0c09c150;
P_0c09c150: /* original 935e, guest PC 0x0c09c150 */
if(!s->budget--) { s->failed_pc=0x0c09c150u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c210u,2);
goto P_0c09c152;
P_0c09c152: /* original 33ec, guest PC 0x0c09c152 */
if(!s->budget--) { s->failed_pc=0x0c09c152u; return 0; }
r[3]+=r[14];
goto P_0c09c154;
P_0c09c154: /* original 33cc, guest PC 0x0c09c154 */
if(!s->budget--) { s->failed_pc=0x0c09c154u; return 0; }
r[3]+=r[12];
goto P_0c09c156;
P_0c09c156: /* original 313c, guest PC 0x0c09c156 */
if(!s->budget--) { s->failed_pc=0x0c09c156u; return 0; }
r[1]+=r[3];
goto P_0c09c158;
P_0c09c158: /* original 2f16, guest PC 0x0c09c158 */
if(!s->budget--) { s->failed_pc=0x0c09c158u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c15a;
P_0c09c15a: /* original 955a, guest PC 0x0c09c15a */
if(!s->budget--) { s->failed_pc=0x0c09c15au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c212u,2);
goto P_0c09c15c;
P_0c09c15c: /* original bece, guest PC 0x0c09c15c */
if(!s->budget--) { s->failed_pc=0x0c09c15cu; return 0; }
target=code_base|0x0c09befcu; r[16]=code_base|0x0c09c160u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c160u) { target=s->pc; goto dispatch; }
goto P_0c09c160;
P_0c09c15e: /* original 64d3, guest PC 0x0c09c15e */
if(!s->budget--) { s->failed_pc=0x0c09c15eu; return 0; }
r[4]=r[13];
goto P_0c09c160;
P_0c09c160: /* original e114, guest PC 0x0c09c160 */
if(!s->budget--) { s->failed_pc=0x0c09c160u; return 0; }
r[1]=0x00000014u;
goto P_0c09c162;
P_0c09c162: /* original 62f6, guest PC 0x0c09c162 */
if(!s->budget--) { s->failed_pc=0x0c09c162u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c09c164;
P_0c09c164: /* original 2202, guest PC 0x0c09c164 */
if(!s->budget--) { s->failed_pc=0x0c09c164u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c09c166;
P_0c09c166: /* original 9353, guest PC 0x0c09c166 */
if(!s->budget--) { s->failed_pc=0x0c09c166u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c210u,2);
goto P_0c09c168;
P_0c09c168: /* original 33ec, guest PC 0x0c09c168 */
if(!s->budget--) { s->failed_pc=0x0c09c168u; return 0; }
r[3]+=r[14];
goto P_0c09c16a;
P_0c09c16a: /* original 33cc, guest PC 0x0c09c16a */
if(!s->budget--) { s->failed_pc=0x0c09c16au; return 0; }
r[3]+=r[12];
goto P_0c09c16c;
P_0c09c16c: /* original 313c, guest PC 0x0c09c16c */
if(!s->budget--) { s->failed_pc=0x0c09c16cu; return 0; }
r[1]+=r[3];
goto P_0c09c16e;
P_0c09c16e: /* original 2f16, guest PC 0x0c09c16e */
if(!s->budget--) { s->failed_pc=0x0c09c16eu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c170;
P_0c09c170: /* original 9550, guest PC 0x0c09c170 */
if(!s->budget--) { s->failed_pc=0x0c09c170u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c214u,2);
goto P_0c09c172;
P_0c09c172: /* original bec3, guest PC 0x0c09c172 */
if(!s->budget--) { s->failed_pc=0x0c09c172u; return 0; }
target=code_base|0x0c09befcu; r[16]=code_base|0x0c09c176u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c176u) { target=s->pc; goto dispatch; }
goto P_0c09c176;
P_0c09c174: /* original 64d3, guest PC 0x0c09c174 */
if(!s->budget--) { s->failed_pc=0x0c09c174u; return 0; }
r[4]=r[13];
goto P_0c09c176;
P_0c09c176: /* original e118, guest PC 0x0c09c176 */
if(!s->budget--) { s->failed_pc=0x0c09c176u; return 0; }
r[1]=0x00000018u;
goto P_0c09c178;
P_0c09c178: /* original 62f6, guest PC 0x0c09c178 */
if(!s->budget--) { s->failed_pc=0x0c09c178u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c09c17a;
P_0c09c17a: /* original 2202, guest PC 0x0c09c17a */
if(!s->budget--) { s->failed_pc=0x0c09c17au; return 0; }
write(ram,r[2],r[0],4);
goto P_0c09c17c;
P_0c09c17c: /* original 9348, guest PC 0x0c09c17c */
if(!s->budget--) { s->failed_pc=0x0c09c17cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c210u,2);
goto P_0c09c17e;
P_0c09c17e: /* original 33ec, guest PC 0x0c09c17e */
if(!s->budget--) { s->failed_pc=0x0c09c17eu; return 0; }
r[3]+=r[14];
goto P_0c09c180;
P_0c09c180: /* original 33cc, guest PC 0x0c09c180 */
if(!s->budget--) { s->failed_pc=0x0c09c180u; return 0; }
r[3]+=r[12];
goto P_0c09c182;
P_0c09c182: /* original 313c, guest PC 0x0c09c182 */
if(!s->budget--) { s->failed_pc=0x0c09c182u; return 0; }
r[1]+=r[3];
goto P_0c09c184;
P_0c09c184: /* original 2f16, guest PC 0x0c09c184 */
if(!s->budget--) { s->failed_pc=0x0c09c184u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c186;
P_0c09c186: /* original 9546, guest PC 0x0c09c186 */
if(!s->budget--) { s->failed_pc=0x0c09c186u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c216u,2);
goto P_0c09c188;
P_0c09c188: /* original beb8, guest PC 0x0c09c188 */
if(!s->budget--) { s->failed_pc=0x0c09c188u; return 0; }
target=code_base|0x0c09befcu; r[16]=code_base|0x0c09c18cu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c18cu) { target=s->pc; goto dispatch; }
goto P_0c09c18c;
P_0c09c18a: /* original 64d3, guest PC 0x0c09c18a */
if(!s->budget--) { s->failed_pc=0x0c09c18au; return 0; }
r[4]=r[13];
goto P_0c09c18c;
P_0c09c18c: /* original e11c, guest PC 0x0c09c18c */
if(!s->budget--) { s->failed_pc=0x0c09c18cu; return 0; }
r[1]=0x0000001cu;
goto P_0c09c18e;
P_0c09c18e: /* original 62f6, guest PC 0x0c09c18e */
if(!s->budget--) { s->failed_pc=0x0c09c18eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c09c190;
P_0c09c190: /* original 6583, guest PC 0x0c09c190 */
if(!s->budget--) { s->failed_pc=0x0c09c190u; return 0; }
r[5]=r[8];
goto P_0c09c192;
P_0c09c192: /* original 2202, guest PC 0x0c09c192 */
if(!s->budget--) { s->failed_pc=0x0c09c192u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c09c194;
P_0c09c194: /* original 933c, guest PC 0x0c09c194 */
if(!s->budget--) { s->failed_pc=0x0c09c194u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c210u,2);
goto P_0c09c196;
P_0c09c196: /* original 33ec, guest PC 0x0c09c196 */
if(!s->budget--) { s->failed_pc=0x0c09c196u; return 0; }
r[3]+=r[14];
goto P_0c09c198;
P_0c09c198: /* original 33cc, guest PC 0x0c09c198 */
if(!s->budget--) { s->failed_pc=0x0c09c198u; return 0; }
r[3]+=r[12];
goto P_0c09c19a;
P_0c09c19a: /* original 313c, guest PC 0x0c09c19a */
if(!s->budget--) { s->failed_pc=0x0c09c19au; return 0; }
r[1]+=r[3];
goto P_0c09c19c;
P_0c09c19c: /* original 2f16, guest PC 0x0c09c19c */
if(!s->budget--) { s->failed_pc=0x0c09c19cu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c19e;
P_0c09c19e: /* original bead, guest PC 0x0c09c19e */
if(!s->budget--) { s->failed_pc=0x0c09c19eu; return 0; }
target=code_base|0x0c09befcu; r[16]=code_base|0x0c09c1a2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c1a2u) { target=s->pc; goto dispatch; }
goto P_0c09c1a2;
P_0c09c1a0: /* original 64d3, guest PC 0x0c09c1a0 */
if(!s->budget--) { s->failed_pc=0x0c09c1a0u; return 0; }
r[4]=r[13];
goto P_0c09c1a2;
P_0c09c1a2: /* original 62f6, guest PC 0x0c09c1a2 */
if(!s->budget--) { s->failed_pc=0x0c09c1a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c09c1a4;
P_0c09c1a4: /* original 6593, guest PC 0x0c09c1a4 */
if(!s->budget--) { s->failed_pc=0x0c09c1a4u; return 0; }
r[5]=r[9];
goto P_0c09c1a6;
P_0c09c1a6: /* original 2202, guest PC 0x0c09c1a6 */
if(!s->budget--) { s->failed_pc=0x0c09c1a6u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c09c1a8;
P_0c09c1a8: /* original 9332, guest PC 0x0c09c1a8 */
if(!s->budget--) { s->failed_pc=0x0c09c1a8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c210u,2);
goto P_0c09c1aa;
P_0c09c1aa: /* original 33ec, guest PC 0x0c09c1aa */
if(!s->budget--) { s->failed_pc=0x0c09c1aau; return 0; }
r[3]+=r[14];
goto P_0c09c1ac;
P_0c09c1ac: /* original 3c3c, guest PC 0x0c09c1ac */
if(!s->budget--) { s->failed_pc=0x0c09c1acu; return 0; }
r[12]+=r[3];
goto P_0c09c1ae;
P_0c09c1ae: /* original bea5, guest PC 0x0c09c1ae */
if(!s->budget--) { s->failed_pc=0x0c09c1aeu; return 0; }
target=code_base|0x0c09befcu; r[16]=code_base|0x0c09c1b2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c1b2u) { target=s->pc; goto dispatch; }
goto P_0c09c1b2;
P_0c09c1b0: /* original 64d3, guest PC 0x0c09c1b0 */
if(!s->budget--) { s->failed_pc=0x0c09c1b0u; return 0; }
r[4]=r[13];
goto P_0c09c1b2;
P_0c09c1b2: /* original e302, guest PC 0x0c09c1b2 */
if(!s->budget--) { s->failed_pc=0x0c09c1b2u; return 0; }
r[3]=0x00000002u;
goto P_0c09c1b4;
P_0c09c1b4: /* original 7b01, guest PC 0x0c09c1b4 */
if(!s->budget--) { s->failed_pc=0x0c09c1b4u; return 0; }
r[11]+=0x00000001u;
goto P_0c09c1b6;
P_0c09c1b6: /* original 3b33, guest PC 0x0c09c1b6 */
if(!s->budget--) { s->failed_pc=0x0c09c1b6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[3])!=0);
goto P_0c09c1b8;
P_0c09c1b8: /* original 8d02, guest PC 0x0c09c1b8 */
if(!s->budget--) { s->failed_pc=0x0c09c1b8u; return 0; }
cond=r[17]&1u;
write(ram,r[12]+32,r[0],4);
if(cond) { goto P_0c09c1c0; }
goto P_0c09c1bc;
P_0c09c1ba: /* original 1c08, guest PC 0x0c09c1ba */
if(!s->budget--) { s->failed_pc=0x0c09c1bau; return 0; }
write(ram,r[12]+32,r[0],4);
goto P_0c09c1bc;
P_0c09c1bc: /* original af57, guest PC 0x0c09c1bc */
if(!s->budget--) { s->failed_pc=0x0c09c1bcu; return 0; }
goto P_0c09c06e;
P_0c09c1be: /* original 0009, guest PC 0x0c09c1be */
if(!s->budget--) { s->failed_pc=0x0c09c1beu; return 0; }
goto P_0c09c1c0;
P_0c09c1c0: /* original 4f26, guest PC 0x0c09c1c0 */
if(!s->budget--) { s->failed_pc=0x0c09c1c0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09c1c2;
P_0c09c1c2: /* original 84eb, guest PC 0x0c09c1c2 */
if(!s->budget--) { s->failed_pc=0x0c09c1c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c09c1c4;
P_0c09c1c4: /* original e377, guest PC 0x0c09c1c4 */
if(!s->budget--) { s->failed_pc=0x0c09c1c4u; return 0; }
r[3]=0x00000077u;
goto P_0c09c1c6;
P_0c09c1c6: /* original 7001, guest PC 0x0c09c1c6 */
if(!s->budget--) { s->failed_pc=0x0c09c1c6u; return 0; }
r[0]+=0x00000001u;
goto P_0c09c1c8;
P_0c09c1c8: /* original 80eb, guest PC 0x0c09c1c8 */
if(!s->budget--) { s->failed_pc=0x0c09c1c8u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09c1ca;
P_0c09c1ca: /* original e010, guest PC 0x0c09c1ca */
if(!s->budget--) { s->failed_pc=0x0c09c1cau; return 0; }
r[0]=0x00000010u;
goto P_0c09c1cc;
P_0c09c1cc: /* original 0e34, guest PC 0x0c09c1cc */
if(!s->budget--) { s->failed_pc=0x0c09c1ccu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09c1ce;
P_0c09c1ce: /* original 68f6, guest PC 0x0c09c1ce */
if(!s->budget--) { s->failed_pc=0x0c09c1ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09c1d0;
P_0c09c1d0: /* original 69f6, guest PC 0x0c09c1d0 */
if(!s->budget--) { s->failed_pc=0x0c09c1d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09c1d2;
P_0c09c1d2: /* original 6af6, guest PC 0x0c09c1d2 */
if(!s->budget--) { s->failed_pc=0x0c09c1d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09c1d4;
P_0c09c1d4: /* original 6bf6, guest PC 0x0c09c1d4 */
if(!s->budget--) { s->failed_pc=0x0c09c1d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09c1d6;
P_0c09c1d6: /* original 6cf6, guest PC 0x0c09c1d6 */
if(!s->budget--) { s->failed_pc=0x0c09c1d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09c1d8;
P_0c09c1d8: /* original 6df6, guest PC 0x0c09c1d8 */
if(!s->budget--) { s->failed_pc=0x0c09c1d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09c1da;
P_0c09c1da: /* original a000, guest PC 0x0c09c1da */
if(!s->budget--) { s->failed_pc=0x0c09c1dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09c1de;
P_0c09c1dc: /* original 6ef6, guest PC 0x0c09c1dc */
if(!s->budget--) { s->failed_pc=0x0c09c1dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09c1de;
P_0c09c1de: /* original 2fe6, guest PC 0x0c09c1de */
if(!s->budget--) { s->failed_pc=0x0c09c1deu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c1e0;
P_0c09c1e0: /* original e07d, guest PC 0x0c09c1e0 */
if(!s->budget--) { s->failed_pc=0x0c09c1e0u; return 0; }
r[0]=0x0000007du;
goto P_0c09c1e2;
P_0c09c1e2: /* original 2fd6, guest PC 0x0c09c1e2 */
if(!s->budget--) { s->failed_pc=0x0c09c1e2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c1e4;
P_0c09c1e4: /* original e340, guest PC 0x0c09c1e4 */
if(!s->budget--) { s->failed_pc=0x0c09c1e4u; return 0; }
r[3]=0x00000040u;
goto P_0c09c1e6;
P_0c09c1e6: /* original 2fc6, guest PC 0x0c09c1e6 */
if(!s->budget--) { s->failed_pc=0x0c09c1e6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c1e8;
P_0c09c1e8: /* original ec01, guest PC 0x0c09c1e8 */
if(!s->budget--) { s->failed_pc=0x0c09c1e8u; return 0; }
r[12]=0x00000001u;
goto P_0c09c1ea;
P_0c09c1ea: /* original 2fb6, guest PC 0x0c09c1ea */
if(!s->budget--) { s->failed_pc=0x0c09c1eau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c1ec;
P_0c09c1ec: /* original 2fa6, guest PC 0x0c09c1ec */
if(!s->budget--) { s->failed_pc=0x0c09c1ecu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c1ee;
P_0c09c1ee: /* original 2f96, guest PC 0x0c09c1ee */
if(!s->budget--) { s->failed_pc=0x0c09c1eeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c1f0;
P_0c09c1f0: /* original e900, guest PC 0x0c09c1f0 */
if(!s->budget--) { s->failed_pc=0x0c09c1f0u; return 0; }
r[9]=0x00000000u;
goto P_0c09c1f2;
P_0c09c1f2: /* original 2f86, guest PC 0x0c09c1f2 */
if(!s->budget--) { s->failed_pc=0x0c09c1f2u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c1f4;
P_0c09c1f4: /* original 4f22, guest PC 0x0c09c1f4 */
if(!s->budget--) { s->failed_pc=0x0c09c1f4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09c1f6;
P_0c09c1f6: /* original dd0a, guest PC 0x0c09c1f6 */
if(!s->budget--) { s->failed_pc=0x0c09c1f6u; return 0; }
r[13]=read(ram,0x0c09c220u,4);
goto P_0c09c1f8;
P_0c09c1f8: /* original 9b0e, guest PC 0x0c09c1f8 */
if(!s->budget--) { s->failed_pc=0x0c09c1f8u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c218u,2);
goto P_0c09c1fa;
P_0c09c1fa: /* original 980a, guest PC 0x0c09c1fa */
if(!s->budget--) { s->failed_pc=0x0c09c1fau; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c212u,2);
goto P_0c09c1fc;
P_0c09c1fc: /* original 7ff4, guest PC 0x0c09c1fc */
if(!s->budget--) { s->failed_pc=0x0c09c1fcu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c09c1fe;
P_0c09c1fe: /* original da07, guest PC 0x0c09c1fe */
if(!s->budget--) { s->failed_pc=0x0c09c1feu; return 0; }
r[10]=read(ram,0x0c09c21cu,4);
goto P_0c09c200;
P_0c09c200: /* original 1d33, guest PC 0x0c09c200 */
if(!s->budget--) { s->failed_pc=0x0c09c200u; return 0; }
write(ram,r[13]+12,r[3],4);
goto P_0c09c202;
P_0c09c202: /* original 1d96, guest PC 0x0c09c202 */
if(!s->budget--) { s->failed_pc=0x0c09c202u; return 0; }
write(ram,r[13]+24,r[9],4);
goto P_0c09c204;
P_0c09c204: /* original 0d94, guest PC 0x0c09c204 */
if(!s->budget--) { s->failed_pc=0x0c09c204u; return 0; }
write(ram,r[13]+r[0],r[9],1);
goto P_0c09c206;
P_0c09c206: /* original 1d95, guest PC 0x0c09c206 */
if(!s->budget--) { s->failed_pc=0x0c09c206u; return 0; }
write(ram,r[13]+20,r[9],4);
goto P_0c09c208;
P_0c09c208: /* original a3f6, guest PC 0x0c09c208 */
if(!s->budget--) { s->failed_pc=0x0c09c208u; return 0; }
r[14]=r[9];
goto P_0c09c9f8;
P_0c09c20a: /* original 6e93, guest PC 0x0c09c20a */
if(!s->budget--) { s->failed_pc=0x0c09c20au; return 0; }
r[14]=r[9];
if(!vf3_matrix_family(0x0c09c20cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09c20cu; return 0; } return 1;
P_0c09c224: /* original d232, guest PC 0x0c09c224 */
if(!s->budget--) { s->failed_pc=0x0c09c224u; return 0; }
r[2]=read(ram,0x0c09c2f0u,4);
goto P_0c09c226;
P_0c09c226: /* original 420b, guest PC 0x0c09c226 */
if(!s->budget--) { s->failed_pc=0x0c09c226u; return 0; }
target=r[2];
r[16]=code_base|0x0c09c22au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c22au) { target=s->pc; goto dispatch; }
goto P_0c09c22a;
P_0c09c228: /* original 64e3, guest PC 0x0c09c228 */
if(!s->budget--) { s->failed_pc=0x0c09c228u; return 0; }
r[4]=r[14];
goto P_0c09c22a;
P_0c09c22a: /* original 63e3, guest PC 0x0c09c22a */
if(!s->budget--) { s->failed_pc=0x0c09c22au; return 0; }
r[3]=r[14];
goto P_0c09c22c;
P_0c09c22c: /* original 4308, guest PC 0x0c09c22c */
if(!s->budget--) { s->failed_pc=0x0c09c22cu; return 0; }
r[3]<<=2;
goto P_0c09c22e;
P_0c09c22e: /* original 4300, guest PC 0x0c09c22e */
if(!s->budget--) { s->failed_pc=0x0c09c22eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c09c230;
P_0c09c230: /* original 62e3, guest PC 0x0c09c230 */
if(!s->budget--) { s->failed_pc=0x0c09c230u; return 0; }
r[2]=r[14];
goto P_0c09c232;
P_0c09c232: /* original 332c, guest PC 0x0c09c232 */
if(!s->budget--) { s->failed_pc=0x0c09c232u; return 0; }
r[3]+=r[2];
goto P_0c09c234;
P_0c09c234: /* original 1f02, guest PC 0x0c09c234 */
if(!s->budget--) { s->failed_pc=0x0c09c234u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c09c236;
P_0c09c236: /* original d12f, guest PC 0x0c09c236 */
if(!s->budget--) { s->failed_pc=0x0c09c236u; return 0; }
r[1]=read(ram,0x0c09c2f4u,4);
goto P_0c09c238;
P_0c09c238: /* original 4308, guest PC 0x0c09c238 */
if(!s->budget--) { s->failed_pc=0x0c09c238u; return 0; }
r[3]<<=2;
goto P_0c09c23a;
P_0c09c23a: /* original 633e, guest PC 0x0c09c23a */
if(!s->budget--) { s->failed_pc=0x0c09c23au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c09c23c;
P_0c09c23c: /* original 331c, guest PC 0x0c09c23c */
if(!s->budget--) { s->failed_pc=0x0c09c23cu; return 0; }
r[3]+=r[1];
goto P_0c09c23e;
P_0c09c23e: /* original 1f31, guest PC 0x0c09c23e */
if(!s->budget--) { s->failed_pc=0x0c09c23eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09c240;
P_0c09c240: /* original d22d, guest PC 0x0c09c240 */
if(!s->budget--) { s->failed_pc=0x0c09c240u; return 0; }
r[2]=read(ram,0x0c09c2f8u,4);
goto P_0c09c242;
P_0c09c242: /* original 420b, guest PC 0x0c09c242 */
if(!s->budget--) { s->failed_pc=0x0c09c242u; return 0; }
target=r[2];
r[16]=code_base|0x0c09c246u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c246u) { target=s->pc; goto dispatch; }
goto P_0c09c246;
P_0c09c244: /* original 64e3, guest PC 0x0c09c244 */
if(!s->budget--) { s->failed_pc=0x0c09c244u; return 0; }
r[4]=r[14];
goto P_0c09c246;
P_0c09c246: /* original d42d, guest PC 0x0c09c246 */
if(!s->budget--) { s->failed_pc=0x0c09c246u; return 0; }
r[4]=read(ram,0x0c09c2fcu,4);
goto P_0c09c248;
P_0c09c248: /* original 3040, guest PC 0x0c09c248 */
if(!s->budget--) { s->failed_pc=0x0c09c248u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[4])!=0);
goto P_0c09c24a;
P_0c09c24a: /* original 8f0a, guest PC 0x0c09c24a */
if(!s->budget--) { s->failed_pc=0x0c09c24au; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[0],4);
if(!cond) { goto P_0c09c262; }
goto P_0c09c24e;
P_0c09c24c: /* original 2f02, guest PC 0x0c09c24c */
if(!s->budget--) { s->failed_pc=0x0c09c24cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c09c24e;
P_0c09c24e: /* original 924c, guest PC 0x0c09c24e */
if(!s->budget--) { s->failed_pc=0x0c09c24eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c2eau,2);
goto P_0c09c250;
P_0c09c250: /* original 63e3, guest PC 0x0c09c250 */
if(!s->budget--) { s->failed_pc=0x0c09c250u; return 0; }
r[3]=r[14];
goto P_0c09c252;
P_0c09c252: /* original 4308, guest PC 0x0c09c252 */
if(!s->budget--) { s->failed_pc=0x0c09c252u; return 0; }
r[3]<<=2;
goto P_0c09c254;
P_0c09c254: /* original 32dc, guest PC 0x0c09c254 */
if(!s->budget--) { s->failed_pc=0x0c09c254u; return 0; }
r[2]+=r[13];
goto P_0c09c256;
P_0c09c256: /* original 332c, guest PC 0x0c09c256 */
if(!s->budget--) { s->failed_pc=0x0c09c256u; return 0; }
r[3]+=r[2];
goto P_0c09c258;
P_0c09c258: /* original 6032, guest PC 0x0c09c258 */
if(!s->budget--) { s->failed_pc=0x0c09c258u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c09c25a;
P_0c09c25a: /* original cb04, guest PC 0x0c09c25a */
if(!s->budget--) { s->failed_pc=0x0c09c25au; return 0; }
r[0]|=4u;
goto P_0c09c25c;
P_0c09c25c: /* original 2302, guest PC 0x0c09c25c */
if(!s->budget--) { s->failed_pc=0x0c09c25cu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c09c25e;
P_0c09c25e: /* original a3ca, guest PC 0x0c09c25e */
if(!s->budget--) { s->failed_pc=0x0c09c25eu; return 0; }
goto P_0c09c9f6;
P_0c09c260: /* original 0009, guest PC 0x0c09c260 */
if(!s->budget--) { s->failed_pc=0x0c09c260u; return 0; }
goto P_0c09c262;
P_0c09c262: /* original 9242, guest PC 0x0c09c262 */
if(!s->budget--) { s->failed_pc=0x0c09c262u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c2eau,2);
goto P_0c09c264;
P_0c09c264: /* original 63e3, guest PC 0x0c09c264 */
if(!s->budget--) { s->failed_pc=0x0c09c264u; return 0; }
r[3]=r[14];
goto P_0c09c266;
P_0c09c266: /* original 4308, guest PC 0x0c09c266 */
if(!s->budget--) { s->failed_pc=0x0c09c266u; return 0; }
r[3]<<=2;
goto P_0c09c268;
P_0c09c268: /* original 32dc, guest PC 0x0c09c268 */
if(!s->budget--) { s->failed_pc=0x0c09c268u; return 0; }
r[2]+=r[13];
goto P_0c09c26a;
P_0c09c26a: /* original 332c, guest PC 0x0c09c26a */
if(!s->budget--) { s->failed_pc=0x0c09c26au; return 0; }
r[3]+=r[2];
goto P_0c09c26c;
P_0c09c26c: /* original 6132, guest PC 0x0c09c26c */
if(!s->budget--) { s->failed_pc=0x0c09c26cu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c26e;
P_0c09c26e: /* original e4fb, guest PC 0x0c09c26e */
if(!s->budget--) { s->failed_pc=0x0c09c26eu; return 0; }
r[4]=0xfffffffbu;
goto P_0c09c270;
P_0c09c270: /* original 2149, guest PC 0x0c09c270 */
if(!s->budget--) { s->failed_pc=0x0c09c270u; return 0; }
r[1]&=r[4];
goto P_0c09c272;
P_0c09c272: /* original 2312, guest PC 0x0c09c272 */
if(!s->budget--) { s->failed_pc=0x0c09c272u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c274;
P_0c09c274: /* original 63e3, guest PC 0x0c09c274 */
if(!s->budget--) { s->failed_pc=0x0c09c274u; return 0; }
r[3]=r[14];
goto P_0c09c276;
P_0c09c276: /* original 9238, guest PC 0x0c09c276 */
if(!s->budget--) { s->failed_pc=0x0c09c276u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c2eau,2);
goto P_0c09c278;
P_0c09c278: /* original 4308, guest PC 0x0c09c278 */
if(!s->budget--) { s->failed_pc=0x0c09c278u; return 0; }
r[3]<<=2;
goto P_0c09c27a;
P_0c09c27a: /* original 32dc, guest PC 0x0c09c27a */
if(!s->budget--) { s->failed_pc=0x0c09c27au; return 0; }
r[2]+=r[13];
goto P_0c09c27c;
P_0c09c27c: /* original 332c, guest PC 0x0c09c27c */
if(!s->budget--) { s->failed_pc=0x0c09c27cu; return 0; }
r[3]+=r[2];
goto P_0c09c27e;
P_0c09c27e: /* original 6132, guest PC 0x0c09c27e */
if(!s->budget--) { s->failed_pc=0x0c09c27eu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c280;
P_0c09c280: /* original 21c8, guest PC 0x0c09c280 */
if(!s->budget--) { s->failed_pc=0x0c09c280u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[12])==0)!=0);
goto P_0c09c282;
P_0c09c282: /* original 8901, guest PC 0x0c09c282 */
if(!s->budget--) { s->failed_pc=0x0c09c282u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c288; }
goto P_0c09c284;
P_0c09c284: /* original a3b7, guest PC 0x0c09c284 */
if(!s->budget--) { s->failed_pc=0x0c09c284u; return 0; }
goto P_0c09c9f6;
P_0c09c286: /* original 0009, guest PC 0x0c09c286 */
if(!s->budget--) { s->failed_pc=0x0c09c286u; return 0; }
goto P_0c09c288;
P_0c09c288: /* original 9330, guest PC 0x0c09c288 */
if(!s->budget--) { s->failed_pc=0x0c09c288u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c2ecu,2);
goto P_0c09c28a;
P_0c09c28a: /* original 60e3, guest PC 0x0c09c28a */
if(!s->budget--) { s->failed_pc=0x0c09c28au; return 0; }
r[0]=r[14];
goto P_0c09c28c;
P_0c09c28c: /* original 4008, guest PC 0x0c09c28c */
if(!s->budget--) { s->failed_pc=0x0c09c28cu; return 0; }
r[0]<<=2;
goto P_0c09c28e;
P_0c09c28e: /* original 33dc, guest PC 0x0c09c28e */
if(!s->budget--) { s->failed_pc=0x0c09c28eu; return 0; }
r[3]+=r[13];
goto P_0c09c290;
P_0c09c290: /* original 003e, guest PC 0x0c09c290 */
if(!s->budget--) { s->failed_pc=0x0c09c290u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c292;
P_0c09c292: /* original 8809, guest PC 0x0c09c292 */
if(!s->budget--) { s->failed_pc=0x0c09c292u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c09c294;
P_0c09c294: /* original 8901, guest PC 0x0c09c294 */
if(!s->budget--) { s->failed_pc=0x0c09c294u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c29a; }
goto P_0c09c296;
P_0c09c296: /* original a0b9, guest PC 0x0c09c296 */
if(!s->budget--) { s->failed_pc=0x0c09c296u; return 0; }
goto P_0c09c40c;
P_0c09c298: /* original 0009, guest PC 0x0c09c298 */
if(!s->budget--) { s->failed_pc=0x0c09c298u; return 0; }
goto P_0c09c29a;
P_0c09c29a: /* original 63f2, guest PC 0x0c09c29a */
if(!s->budget--) { s->failed_pc=0x0c09c29au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09c29c;
P_0c09c29c: /* original e40c, guest PC 0x0c09c29c */
if(!s->budget--) { s->failed_pc=0x0c09c29cu; return 0; }
r[4]=0x0000000cu;
goto P_0c09c29e;
P_0c09c29e: /* original 2348, guest PC 0x0c09c29e */
if(!s->budget--) { s->failed_pc=0x0c09c29eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c09c2a0;
P_0c09c2a0: /* original 8b01, guest PC 0x0c09c2a0 */
if(!s->budget--) { s->failed_pc=0x0c09c2a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c2a6; }
goto P_0c09c2a2;
P_0c09c2a2: /* original a0b3, guest PC 0x0c09c2a2 */
if(!s->budget--) { s->failed_pc=0x0c09c2a2u; return 0; }
goto P_0c09c40c;
P_0c09c2a4: /* original 0009, guest PC 0x0c09c2a4 */
if(!s->budget--) { s->failed_pc=0x0c09c2a4u; return 0; }
goto P_0c09c2a6;
P_0c09c2a6: /* original 60f2, guest PC 0x0c09c2a6 */
if(!s->budget--) { s->failed_pc=0x0c09c2a6u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c09c2a8;
P_0c09c2a8: /* original c808, guest PC 0x0c09c2a8 */
if(!s->budget--) { s->failed_pc=0x0c09c2a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c09c2aa;
P_0c09c2aa: /* original 8907, guest PC 0x0c09c2aa */
if(!s->budget--) { s->failed_pc=0x0c09c2aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c2bc; }
goto P_0c09c2ac;
P_0c09c2ac: /* original 921d, guest PC 0x0c09c2ac */
if(!s->budget--) { s->failed_pc=0x0c09c2acu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c2eau,2);
goto P_0c09c2ae;
P_0c09c2ae: /* original 63e3, guest PC 0x0c09c2ae */
if(!s->budget--) { s->failed_pc=0x0c09c2aeu; return 0; }
r[3]=r[14];
goto P_0c09c2b0;
P_0c09c2b0: /* original 4308, guest PC 0x0c09c2b0 */
if(!s->budget--) { s->failed_pc=0x0c09c2b0u; return 0; }
r[3]<<=2;
goto P_0c09c2b2;
P_0c09c2b2: /* original 32dc, guest PC 0x0c09c2b2 */
if(!s->budget--) { s->failed_pc=0x0c09c2b2u; return 0; }
r[2]+=r[13];
goto P_0c09c2b4;
P_0c09c2b4: /* original 332c, guest PC 0x0c09c2b4 */
if(!s->budget--) { s->failed_pc=0x0c09c2b4u; return 0; }
r[3]+=r[2];
goto P_0c09c2b6;
P_0c09c2b6: /* original 6032, guest PC 0x0c09c2b6 */
if(!s->budget--) { s->failed_pc=0x0c09c2b6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c09c2b8;
P_0c09c2b8: /* original cb08, guest PC 0x0c09c2b8 */
if(!s->budget--) { s->failed_pc=0x0c09c2b8u; return 0; }
r[0]|=8u;
goto P_0c09c2ba;
P_0c09c2ba: /* original 2302, guest PC 0x0c09c2ba */
if(!s->budget--) { s->failed_pc=0x0c09c2bau; return 0; }
write(ram,r[3],r[0],4);
goto P_0c09c2bc;
P_0c09c2bc: /* original 9215, guest PC 0x0c09c2bc */
if(!s->budget--) { s->failed_pc=0x0c09c2bcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c2eau,2);
goto P_0c09c2be;
P_0c09c2be: /* original 63e3, guest PC 0x0c09c2be */
if(!s->budget--) { s->failed_pc=0x0c09c2beu; return 0; }
r[3]=r[14];
goto P_0c09c2c0;
P_0c09c2c0: /* original 4308, guest PC 0x0c09c2c0 */
if(!s->budget--) { s->failed_pc=0x0c09c2c0u; return 0; }
r[3]<<=2;
goto P_0c09c2c2;
P_0c09c2c2: /* original 32dc, guest PC 0x0c09c2c2 */
if(!s->budget--) { s->failed_pc=0x0c09c2c2u; return 0; }
r[2]+=r[13];
goto P_0c09c2c4;
P_0c09c2c4: /* original 332c, guest PC 0x0c09c2c4 */
if(!s->budget--) { s->failed_pc=0x0c09c2c4u; return 0; }
r[3]+=r[2];
goto P_0c09c2c6;
P_0c09c2c6: /* original 6132, guest PC 0x0c09c2c6 */
if(!s->budget--) { s->failed_pc=0x0c09c2c6u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c2c8;
P_0c09c2c8: /* original 21c8, guest PC 0x0c09c2c8 */
if(!s->budget--) { s->failed_pc=0x0c09c2c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[12])==0)!=0);
goto P_0c09c2ca;
P_0c09c2ca: /* original 8901, guest PC 0x0c09c2ca */
if(!s->budget--) { s->failed_pc=0x0c09c2cau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c2d0; }
goto P_0c09c2cc;
P_0c09c2cc: /* original a096, guest PC 0x0c09c2cc */
if(!s->budget--) { s->failed_pc=0x0c09c2ccu; return 0; }
goto P_0c09c3fc;
P_0c09c2ce: /* original 0009, guest PC 0x0c09c2ce */
if(!s->budget--) { s->failed_pc=0x0c09c2ceu; return 0; }
goto P_0c09c2d0;
P_0c09c2d0: /* original 930d, guest PC 0x0c09c2d0 */
if(!s->budget--) { s->failed_pc=0x0c09c2d0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c2eeu,2);
goto P_0c09c2d2;
P_0c09c2d2: /* original 62e3, guest PC 0x0c09c2d2 */
if(!s->budget--) { s->failed_pc=0x0c09c2d2u; return 0; }
r[2]=r[14];
goto P_0c09c2d4;
P_0c09c2d4: /* original 4208, guest PC 0x0c09c2d4 */
if(!s->budget--) { s->failed_pc=0x0c09c2d4u; return 0; }
r[2]<<=2;
goto P_0c09c2d6;
P_0c09c2d6: /* original 33dc, guest PC 0x0c09c2d6 */
if(!s->budget--) { s->failed_pc=0x0c09c2d6u; return 0; }
r[3]+=r[13];
goto P_0c09c2d8;
P_0c09c2d8: /* original 323c, guest PC 0x0c09c2d8 */
if(!s->budget--) { s->failed_pc=0x0c09c2d8u; return 0; }
r[2]+=r[3];
goto P_0c09c2da;
P_0c09c2da: /* original 6122, guest PC 0x0c09c2da */
if(!s->budget--) { s->failed_pc=0x0c09c2dau; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c2dc;
P_0c09c2dc: /* original 2118, guest PC 0x0c09c2dc */
if(!s->budget--) { s->failed_pc=0x0c09c2dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c09c2de;
P_0c09c2de: /* original 8b11, guest PC 0x0c09c2de */
if(!s->budget--) { s->failed_pc=0x0c09c2deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c304; }
goto P_0c09c2e0;
P_0c09c2e0: /* original d307, guest PC 0x0c09c2e0 */
if(!s->budget--) { s->failed_pc=0x0c09c2e0u; return 0; }
r[3]=read(ram,0x0c09c300u,4);
goto P_0c09c2e2;
P_0c09c2e2: /* original 430b, guest PC 0x0c09c2e2 */
if(!s->budget--) { s->failed_pc=0x0c09c2e2u; return 0; }
target=r[3];
r[16]=code_base|0x0c09c2e6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c2e6u) { target=s->pc; goto dispatch; }
goto P_0c09c2e6;
P_0c09c2e4: /* original 64e3, guest PC 0x0c09c2e4 */
if(!s->budget--) { s->failed_pc=0x0c09c2e4u; return 0; }
r[4]=r[14];
goto P_0c09c2e6;
P_0c09c2e6: /* original a086, guest PC 0x0c09c2e6 */
if(!s->budget--) { s->failed_pc=0x0c09c2e6u; return 0; }
goto P_0c09c3f6;
P_0c09c2e8: /* original 0009, guest PC 0x0c09c2e8 */
if(!s->budget--) { s->failed_pc=0x0c09c2e8u; return 0; }
if(!vf3_matrix_family(0x0c09c2eau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09c2eau; return 0; } return 1;
P_0c09c304: /* original 53f1, guest PC 0x0c09c304 */
if(!s->budget--) { s->failed_pc=0x0c09c304u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09c306;
P_0c09c306: /* original e501, guest PC 0x0c09c306 */
if(!s->budget--) { s->failed_pc=0x0c09c306u; return 0; }
r[5]=0x00000001u;
goto P_0c09c308;
P_0c09c308: /* original 2f36, guest PC 0x0c09c308 */
if(!s->budget--) { s->failed_pc=0x0c09c308u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c30a;
P_0c09c30a: /* original be4d, guest PC 0x0c09c30a */
if(!s->budget--) { s->failed_pc=0x0c09c30au; return 0; }
target=code_base|0x0c09bfa8u; r[16]=code_base|0x0c09c30eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c30eu) { target=s->pc; goto dispatch; }
goto P_0c09c30e;
P_0c09c30c: /* original 64e3, guest PC 0x0c09c30c */
if(!s->budget--) { s->failed_pc=0x0c09c30cu; return 0; }
r[4]=r[14];
goto P_0c09c30e;
P_0c09c30e: /* original e520, guest PC 0x0c09c30e */
if(!s->budget--) { s->failed_pc=0x0c09c30eu; return 0; }
r[5]=0x00000020u;
goto P_0c09c310;
P_0c09c310: /* original 2f06, guest PC 0x0c09c310 */
if(!s->budget--) { s->failed_pc=0x0c09c310u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c312;
P_0c09c312: /* original be49, guest PC 0x0c09c312 */
if(!s->budget--) { s->failed_pc=0x0c09c312u; return 0; }
target=code_base|0x0c09bfa8u; r[16]=code_base|0x0c09c316u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c316u) { target=s->pc; goto dispatch; }
goto P_0c09c316;
P_0c09c314: /* original 64e3, guest PC 0x0c09c314 */
if(!s->budget--) { s->failed_pc=0x0c09c314u; return 0; }
r[4]=r[14];
goto P_0c09c316;
P_0c09c316: /* original 63f6, guest PC 0x0c09c316 */
if(!s->budget--) { s->failed_pc=0x0c09c316u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c318;
P_0c09c318: /* original e540, guest PC 0x0c09c318 */
if(!s->budget--) { s->failed_pc=0x0c09c318u; return 0; }
r[5]=0x00000040u;
goto P_0c09c31a;
P_0c09c31a: /* original 203b, guest PC 0x0c09c31a */
if(!s->budget--) { s->failed_pc=0x0c09c31au; return 0; }
r[0]|=r[3];
goto P_0c09c31c;
P_0c09c31c: /* original 2f06, guest PC 0x0c09c31c */
if(!s->budget--) { s->failed_pc=0x0c09c31cu; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c31e;
P_0c09c31e: /* original be43, guest PC 0x0c09c31e */
if(!s->budget--) { s->failed_pc=0x0c09c31eu; return 0; }
target=code_base|0x0c09bfa8u; r[16]=code_base|0x0c09c322u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c322u) { target=s->pc; goto dispatch; }
goto P_0c09c322;
P_0c09c320: /* original 64e3, guest PC 0x0c09c320 */
if(!s->budget--) { s->failed_pc=0x0c09c320u; return 0; }
r[4]=r[14];
goto P_0c09c322;
P_0c09c322: /* original 63f6, guest PC 0x0c09c322 */
if(!s->budget--) { s->failed_pc=0x0c09c322u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c324;
P_0c09c324: /* original 203b, guest PC 0x0c09c324 */
if(!s->budget--) { s->failed_pc=0x0c09c324u; return 0; }
r[0]|=r[3];
goto P_0c09c326;
P_0c09c326: /* original 2f06, guest PC 0x0c09c326 */
if(!s->budget--) { s->failed_pc=0x0c09c326u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c328;
P_0c09c328: /* original 958f, guest PC 0x0c09c328 */
if(!s->budget--) { s->failed_pc=0x0c09c328u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c44au,2);
goto P_0c09c32a;
P_0c09c32a: /* original be3d, guest PC 0x0c09c32a */
if(!s->budget--) { s->failed_pc=0x0c09c32au; return 0; }
target=code_base|0x0c09bfa8u; r[16]=code_base|0x0c09c32eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c32eu) { target=s->pc; goto dispatch; }
goto P_0c09c32e;
P_0c09c32c: /* original 64e3, guest PC 0x0c09c32c */
if(!s->budget--) { s->failed_pc=0x0c09c32cu; return 0; }
r[4]=r[14];
goto P_0c09c32e;
P_0c09c32e: /* original 63f6, guest PC 0x0c09c32e */
if(!s->budget--) { s->failed_pc=0x0c09c32eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c330;
P_0c09c330: /* original 203b, guest PC 0x0c09c330 */
if(!s->budget--) { s->failed_pc=0x0c09c330u; return 0; }
r[0]|=r[3];
goto P_0c09c332;
P_0c09c332: /* original 2f06, guest PC 0x0c09c332 */
if(!s->budget--) { s->failed_pc=0x0c09c332u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c334;
P_0c09c334: /* original 958a, guest PC 0x0c09c334 */
if(!s->budget--) { s->failed_pc=0x0c09c334u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c44cu,2);
goto P_0c09c336;
P_0c09c336: /* original be37, guest PC 0x0c09c336 */
if(!s->budget--) { s->failed_pc=0x0c09c336u; return 0; }
target=code_base|0x0c09bfa8u; r[16]=code_base|0x0c09c33au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c33au) { target=s->pc; goto dispatch; }
goto P_0c09c33a;
P_0c09c338: /* original 64e3, guest PC 0x0c09c338 */
if(!s->budget--) { s->failed_pc=0x0c09c338u; return 0; }
r[4]=r[14];
goto P_0c09c33a;
P_0c09c33a: /* original 63f6, guest PC 0x0c09c33a */
if(!s->budget--) { s->failed_pc=0x0c09c33au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c33c;
P_0c09c33c: /* original e502, guest PC 0x0c09c33c */
if(!s->budget--) { s->failed_pc=0x0c09c33cu; return 0; }
r[5]=0x00000002u;
goto P_0c09c33e;
P_0c09c33e: /* original 62f6, guest PC 0x0c09c33e */
if(!s->budget--) { s->failed_pc=0x0c09c33eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c09c340;
P_0c09c340: /* original 203b, guest PC 0x0c09c340 */
if(!s->budget--) { s->failed_pc=0x0c09c340u; return 0; }
r[0]|=r[3];
goto P_0c09c342;
P_0c09c342: /* original 2202, guest PC 0x0c09c342 */
if(!s->budget--) { s->failed_pc=0x0c09c342u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c09c344;
P_0c09c344: /* original e204, guest PC 0x0c09c344 */
if(!s->budget--) { s->failed_pc=0x0c09c344u; return 0; }
r[2]=0x00000004u;
goto P_0c09c346;
P_0c09c346: /* original 53f1, guest PC 0x0c09c346 */
if(!s->budget--) { s->failed_pc=0x0c09c346u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09c348;
P_0c09c348: /* original 323c, guest PC 0x0c09c348 */
if(!s->budget--) { s->failed_pc=0x0c09c348u; return 0; }
r[2]+=r[3];
goto P_0c09c34a;
P_0c09c34a: /* original 2f26, guest PC 0x0c09c34a */
if(!s->budget--) { s->failed_pc=0x0c09c34au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c34c;
P_0c09c34c: /* original be2c, guest PC 0x0c09c34c */
if(!s->budget--) { s->failed_pc=0x0c09c34cu; return 0; }
target=code_base|0x0c09bfa8u; r[16]=code_base|0x0c09c350u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c350u) { target=s->pc; goto dispatch; }
goto P_0c09c350;
P_0c09c34e: /* original 64e3, guest PC 0x0c09c34e */
if(!s->budget--) { s->failed_pc=0x0c09c34eu; return 0; }
r[4]=r[14];
goto P_0c09c350;
P_0c09c350: /* original 2f06, guest PC 0x0c09c350 */
if(!s->budget--) { s->failed_pc=0x0c09c350u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c352;
P_0c09c352: /* original 957c, guest PC 0x0c09c352 */
if(!s->budget--) { s->failed_pc=0x0c09c352u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c44eu,2);
goto P_0c09c354;
P_0c09c354: /* original be28, guest PC 0x0c09c354 */
if(!s->budget--) { s->failed_pc=0x0c09c354u; return 0; }
target=code_base|0x0c09bfa8u; r[16]=code_base|0x0c09c358u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c358u) { target=s->pc; goto dispatch; }
goto P_0c09c358;
P_0c09c356: /* original 64e3, guest PC 0x0c09c356 */
if(!s->budget--) { s->failed_pc=0x0c09c356u; return 0; }
r[4]=r[14];
goto P_0c09c358;
P_0c09c358: /* original 63f6, guest PC 0x0c09c358 */
if(!s->budget--) { s->failed_pc=0x0c09c358u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c35a;
P_0c09c35a: /* original 6583, guest PC 0x0c09c35a */
if(!s->budget--) { s->failed_pc=0x0c09c35au; return 0; }
r[5]=r[8];
goto P_0c09c35c;
P_0c09c35c: /* original 203b, guest PC 0x0c09c35c */
if(!s->budget--) { s->failed_pc=0x0c09c35cu; return 0; }
r[0]|=r[3];
goto P_0c09c35e;
P_0c09c35e: /* original 2f06, guest PC 0x0c09c35e */
if(!s->budget--) { s->failed_pc=0x0c09c35eu; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c360;
P_0c09c360: /* original be22, guest PC 0x0c09c360 */
if(!s->budget--) { s->failed_pc=0x0c09c360u; return 0; }
target=code_base|0x0c09bfa8u; r[16]=code_base|0x0c09c364u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c364u) { target=s->pc; goto dispatch; }
goto P_0c09c364;
P_0c09c362: /* original 64e3, guest PC 0x0c09c362 */
if(!s->budget--) { s->failed_pc=0x0c09c362u; return 0; }
r[4]=r[14];
goto P_0c09c364;
P_0c09c364: /* original 63f6, guest PC 0x0c09c364 */
if(!s->budget--) { s->failed_pc=0x0c09c364u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c366;
P_0c09c366: /* original 203b, guest PC 0x0c09c366 */
if(!s->budget--) { s->failed_pc=0x0c09c366u; return 0; }
r[0]|=r[3];
goto P_0c09c368;
P_0c09c368: /* original 2f06, guest PC 0x0c09c368 */
if(!s->budget--) { s->failed_pc=0x0c09c368u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c36a;
P_0c09c36a: /* original 956e, guest PC 0x0c09c36a */
if(!s->budget--) { s->failed_pc=0x0c09c36au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c44au,2);
goto P_0c09c36c;
P_0c09c36c: /* original be1c, guest PC 0x0c09c36c */
if(!s->budget--) { s->failed_pc=0x0c09c36cu; return 0; }
target=code_base|0x0c09bfa8u; r[16]=code_base|0x0c09c370u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c370u) { target=s->pc; goto dispatch; }
goto P_0c09c370;
P_0c09c36e: /* original 64e3, guest PC 0x0c09c36e */
if(!s->budget--) { s->failed_pc=0x0c09c36eu; return 0; }
r[4]=r[14];
goto P_0c09c370;
P_0c09c370: /* original 63f6, guest PC 0x0c09c370 */
if(!s->budget--) { s->failed_pc=0x0c09c370u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c372;
P_0c09c372: /* original 203b, guest PC 0x0c09c372 */
if(!s->budget--) { s->failed_pc=0x0c09c372u; return 0; }
r[0]|=r[3];
goto P_0c09c374;
P_0c09c374: /* original 2f06, guest PC 0x0c09c374 */
if(!s->budget--) { s->failed_pc=0x0c09c374u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c376;
P_0c09c376: /* original 9569, guest PC 0x0c09c376 */
if(!s->budget--) { s->failed_pc=0x0c09c376u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c44cu,2);
goto P_0c09c378;
P_0c09c378: /* original be16, guest PC 0x0c09c378 */
if(!s->budget--) { s->failed_pc=0x0c09c378u; return 0; }
target=code_base|0x0c09bfa8u; r[16]=code_base|0x0c09c37cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c37cu) { target=s->pc; goto dispatch; }
goto P_0c09c37c;
P_0c09c37a: /* original 64e3, guest PC 0x0c09c37a */
if(!s->budget--) { s->failed_pc=0x0c09c37au; return 0; }
r[4]=r[14];
goto P_0c09c37c;
P_0c09c37c: /* original 63f6, guest PC 0x0c09c37c */
if(!s->budget--) { s->failed_pc=0x0c09c37cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c37e;
P_0c09c37e: /* original e208, guest PC 0x0c09c37e */
if(!s->budget--) { s->failed_pc=0x0c09c37eu; return 0; }
r[2]=0x00000008u;
goto P_0c09c380;
P_0c09c380: /* original e504, guest PC 0x0c09c380 */
if(!s->budget--) { s->failed_pc=0x0c09c380u; return 0; }
r[5]=0x00000004u;
goto P_0c09c382;
P_0c09c382: /* original 61f6, guest PC 0x0c09c382 */
if(!s->budget--) { s->failed_pc=0x0c09c382u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c09c384;
P_0c09c384: /* original 203b, guest PC 0x0c09c384 */
if(!s->budget--) { s->failed_pc=0x0c09c384u; return 0; }
r[0]|=r[3];
goto P_0c09c386;
P_0c09c386: /* original 2102, guest PC 0x0c09c386 */
if(!s->budget--) { s->failed_pc=0x0c09c386u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c09c388;
P_0c09c388: /* original 53f1, guest PC 0x0c09c388 */
if(!s->budget--) { s->failed_pc=0x0c09c388u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09c38a;
P_0c09c38a: /* original 323c, guest PC 0x0c09c38a */
if(!s->budget--) { s->failed_pc=0x0c09c38au; return 0; }
r[2]+=r[3];
goto P_0c09c38c;
P_0c09c38c: /* original 2f26, guest PC 0x0c09c38c */
if(!s->budget--) { s->failed_pc=0x0c09c38cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c38e;
P_0c09c38e: /* original be0b, guest PC 0x0c09c38e */
if(!s->budget--) { s->failed_pc=0x0c09c38eu; return 0; }
target=code_base|0x0c09bfa8u; r[16]=code_base|0x0c09c392u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c392u) { target=s->pc; goto dispatch; }
goto P_0c09c392;
P_0c09c390: /* original 64e3, guest PC 0x0c09c390 */
if(!s->budget--) { s->failed_pc=0x0c09c390u; return 0; }
r[4]=r[14];
goto P_0c09c392;
P_0c09c392: /* original e520, guest PC 0x0c09c392 */
if(!s->budget--) { s->failed_pc=0x0c09c392u; return 0; }
r[5]=0x00000020u;
goto P_0c09c394;
P_0c09c394: /* original 2f06, guest PC 0x0c09c394 */
if(!s->budget--) { s->failed_pc=0x0c09c394u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c396;
P_0c09c396: /* original be07, guest PC 0x0c09c396 */
if(!s->budget--) { s->failed_pc=0x0c09c396u; return 0; }
target=code_base|0x0c09bfa8u; r[16]=code_base|0x0c09c39au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c39au) { target=s->pc; goto dispatch; }
goto P_0c09c39a;
P_0c09c398: /* original 64e3, guest PC 0x0c09c398 */
if(!s->budget--) { s->failed_pc=0x0c09c398u; return 0; }
r[4]=r[14];
goto P_0c09c39a;
P_0c09c39a: /* original 63f6, guest PC 0x0c09c39a */
if(!s->budget--) { s->failed_pc=0x0c09c39au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c39c;
P_0c09c39c: /* original 203b, guest PC 0x0c09c39c */
if(!s->budget--) { s->failed_pc=0x0c09c39cu; return 0; }
r[0]|=r[3];
goto P_0c09c39e;
P_0c09c39e: /* original 2f06, guest PC 0x0c09c39e */
if(!s->budget--) { s->failed_pc=0x0c09c39eu; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c3a0;
P_0c09c3a0: /* original 9555, guest PC 0x0c09c3a0 */
if(!s->budget--) { s->failed_pc=0x0c09c3a0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c44eu,2);
goto P_0c09c3a2;
P_0c09c3a2: /* original be01, guest PC 0x0c09c3a2 */
if(!s->budget--) { s->failed_pc=0x0c09c3a2u; return 0; }
target=code_base|0x0c09bfa8u; r[16]=code_base|0x0c09c3a6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c3a6u) { target=s->pc; goto dispatch; }
goto P_0c09c3a6;
P_0c09c3a4: /* original 64e3, guest PC 0x0c09c3a4 */
if(!s->budget--) { s->failed_pc=0x0c09c3a4u; return 0; }
r[4]=r[14];
goto P_0c09c3a6;
P_0c09c3a6: /* original 63f6, guest PC 0x0c09c3a6 */
if(!s->budget--) { s->failed_pc=0x0c09c3a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c3a8;
P_0c09c3a8: /* original 203b, guest PC 0x0c09c3a8 */
if(!s->budget--) { s->failed_pc=0x0c09c3a8u; return 0; }
r[0]|=r[3];
goto P_0c09c3aa;
P_0c09c3aa: /* original 2f06, guest PC 0x0c09c3aa */
if(!s->budget--) { s->failed_pc=0x0c09c3aau; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c3ac;
P_0c09c3ac: /* original 954e, guest PC 0x0c09c3ac */
if(!s->budget--) { s->failed_pc=0x0c09c3acu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c44cu,2);
goto P_0c09c3ae;
P_0c09c3ae: /* original bdfb, guest PC 0x0c09c3ae */
if(!s->budget--) { s->failed_pc=0x0c09c3aeu; return 0; }
target=code_base|0x0c09bfa8u; r[16]=code_base|0x0c09c3b2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c3b2u) { target=s->pc; goto dispatch; }
goto P_0c09c3b2;
P_0c09c3b0: /* original 64e3, guest PC 0x0c09c3b0 */
if(!s->budget--) { s->failed_pc=0x0c09c3b0u; return 0; }
r[4]=r[14];
goto P_0c09c3b2;
P_0c09c3b2: /* original 63f6, guest PC 0x0c09c3b2 */
if(!s->budget--) { s->failed_pc=0x0c09c3b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c3b4;
P_0c09c3b4: /* original e20c, guest PC 0x0c09c3b4 */
if(!s->budget--) { s->failed_pc=0x0c09c3b4u; return 0; }
r[2]=0x0000000cu;
goto P_0c09c3b6;
P_0c09c3b6: /* original e508, guest PC 0x0c09c3b6 */
if(!s->budget--) { s->failed_pc=0x0c09c3b6u; return 0; }
r[5]=0x00000008u;
goto P_0c09c3b8;
P_0c09c3b8: /* original 61f6, guest PC 0x0c09c3b8 */
if(!s->budget--) { s->failed_pc=0x0c09c3b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c09c3ba;
P_0c09c3ba: /* original 203b, guest PC 0x0c09c3ba */
if(!s->budget--) { s->failed_pc=0x0c09c3bau; return 0; }
r[0]|=r[3];
goto P_0c09c3bc;
P_0c09c3bc: /* original 2102, guest PC 0x0c09c3bc */
if(!s->budget--) { s->failed_pc=0x0c09c3bcu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c09c3be;
P_0c09c3be: /* original 53f1, guest PC 0x0c09c3be */
if(!s->budget--) { s->failed_pc=0x0c09c3beu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09c3c0;
P_0c09c3c0: /* original 323c, guest PC 0x0c09c3c0 */
if(!s->budget--) { s->failed_pc=0x0c09c3c0u; return 0; }
r[2]+=r[3];
goto P_0c09c3c2;
P_0c09c3c2: /* original 2f26, guest PC 0x0c09c3c2 */
if(!s->budget--) { s->failed_pc=0x0c09c3c2u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c3c4;
P_0c09c3c4: /* original bdf0, guest PC 0x0c09c3c4 */
if(!s->budget--) { s->failed_pc=0x0c09c3c4u; return 0; }
target=code_base|0x0c09bfa8u; r[16]=code_base|0x0c09c3c8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c3c8u) { target=s->pc; goto dispatch; }
goto P_0c09c3c8;
P_0c09c3c6: /* original 64e3, guest PC 0x0c09c3c6 */
if(!s->budget--) { s->failed_pc=0x0c09c3c6u; return 0; }
r[4]=r[14];
goto P_0c09c3c8;
P_0c09c3c8: /* original e540, guest PC 0x0c09c3c8 */
if(!s->budget--) { s->failed_pc=0x0c09c3c8u; return 0; }
r[5]=0x00000040u;
goto P_0c09c3ca;
P_0c09c3ca: /* original 2f06, guest PC 0x0c09c3ca */
if(!s->budget--) { s->failed_pc=0x0c09c3cau; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c3cc;
P_0c09c3cc: /* original bdec, guest PC 0x0c09c3cc */
if(!s->budget--) { s->failed_pc=0x0c09c3ccu; return 0; }
target=code_base|0x0c09bfa8u; r[16]=code_base|0x0c09c3d0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c3d0u) { target=s->pc; goto dispatch; }
goto P_0c09c3d0;
P_0c09c3ce: /* original 64e3, guest PC 0x0c09c3ce */
if(!s->budget--) { s->failed_pc=0x0c09c3ceu; return 0; }
r[4]=r[14];
goto P_0c09c3d0;
P_0c09c3d0: /* original 63f6, guest PC 0x0c09c3d0 */
if(!s->budget--) { s->failed_pc=0x0c09c3d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c3d2;
P_0c09c3d2: /* original 6583, guest PC 0x0c09c3d2 */
if(!s->budget--) { s->failed_pc=0x0c09c3d2u; return 0; }
r[5]=r[8];
goto P_0c09c3d4;
P_0c09c3d4: /* original 203b, guest PC 0x0c09c3d4 */
if(!s->budget--) { s->failed_pc=0x0c09c3d4u; return 0; }
r[0]|=r[3];
goto P_0c09c3d6;
P_0c09c3d6: /* original 2f06, guest PC 0x0c09c3d6 */
if(!s->budget--) { s->failed_pc=0x0c09c3d6u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c3d8;
P_0c09c3d8: /* original bde6, guest PC 0x0c09c3d8 */
if(!s->budget--) { s->failed_pc=0x0c09c3d8u; return 0; }
target=code_base|0x0c09bfa8u; r[16]=code_base|0x0c09c3dcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c3dcu) { target=s->pc; goto dispatch; }
goto P_0c09c3dc;
P_0c09c3da: /* original 64e3, guest PC 0x0c09c3da */
if(!s->budget--) { s->failed_pc=0x0c09c3dau; return 0; }
r[4]=r[14];
goto P_0c09c3dc;
P_0c09c3dc: /* original 63f6, guest PC 0x0c09c3dc */
if(!s->budget--) { s->failed_pc=0x0c09c3dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c09c3de;
P_0c09c3de: /* original e210, guest PC 0x0c09c3de */
if(!s->budget--) { s->failed_pc=0x0c09c3deu; return 0; }
r[2]=0x00000010u;
goto P_0c09c3e0;
P_0c09c3e0: /* original e510, guest PC 0x0c09c3e0 */
if(!s->budget--) { s->failed_pc=0x0c09c3e0u; return 0; }
r[5]=0x00000010u;
goto P_0c09c3e2;
P_0c09c3e2: /* original 61f6, guest PC 0x0c09c3e2 */
if(!s->budget--) { s->failed_pc=0x0c09c3e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c09c3e4;
P_0c09c3e4: /* original 203b, guest PC 0x0c09c3e4 */
if(!s->budget--) { s->failed_pc=0x0c09c3e4u; return 0; }
r[0]|=r[3];
goto P_0c09c3e6;
P_0c09c3e6: /* original 2102, guest PC 0x0c09c3e6 */
if(!s->budget--) { s->failed_pc=0x0c09c3e6u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c09c3e8;
P_0c09c3e8: /* original 53f1, guest PC 0x0c09c3e8 */
if(!s->budget--) { s->failed_pc=0x0c09c3e8u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09c3ea;
P_0c09c3ea: /* original 323c, guest PC 0x0c09c3ea */
if(!s->budget--) { s->failed_pc=0x0c09c3eau; return 0; }
r[2]+=r[3];
goto P_0c09c3ec;
P_0c09c3ec: /* original 2f26, guest PC 0x0c09c3ec */
if(!s->budget--) { s->failed_pc=0x0c09c3ecu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09c3ee;
P_0c09c3ee: /* original bddb, guest PC 0x0c09c3ee */
if(!s->budget--) { s->failed_pc=0x0c09c3eeu; return 0; }
target=code_base|0x0c09bfa8u; r[16]=code_base|0x0c09c3f2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c3f2u) { target=s->pc; goto dispatch; }
goto P_0c09c3f2;
P_0c09c3f0: /* original 64e3, guest PC 0x0c09c3f0 */
if(!s->budget--) { s->failed_pc=0x0c09c3f0u; return 0; }
r[4]=r[14];
goto P_0c09c3f2;
P_0c09c3f2: /* original 61f6, guest PC 0x0c09c3f2 */
if(!s->budget--) { s->failed_pc=0x0c09c3f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c09c3f4;
P_0c09c3f4: /* original 2102, guest PC 0x0c09c3f4 */
if(!s->budget--) { s->failed_pc=0x0c09c3f4u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c09c3f6;
P_0c09c3f6: /* original 942b, guest PC 0x0c09c3f6 */
if(!s->budget--) { s->failed_pc=0x0c09c3f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c450u,2);
goto P_0c09c3f8;
P_0c09c3f8: /* original 4a0b, guest PC 0x0c09c3f8 */
if(!s->budget--) { s->failed_pc=0x0c09c3f8u; return 0; }
target=r[10];
r[16]=code_base|0x0c09c3fcu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c3fcu) { target=s->pc; goto dispatch; }
goto P_0c09c3fc;
P_0c09c3fa: /* original 0009, guest PC 0x0c09c3fa */
if(!s->budget--) { s->failed_pc=0x0c09c3fau; return 0; }
goto P_0c09c3fc;
P_0c09c3fc: /* original 9229, guest PC 0x0c09c3fc */
if(!s->budget--) { s->failed_pc=0x0c09c3fcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c452u,2);
goto P_0c09c3fe;
P_0c09c3fe: /* original 63e3, guest PC 0x0c09c3fe */
if(!s->budget--) { s->failed_pc=0x0c09c3feu; return 0; }
r[3]=r[14];
goto P_0c09c400;
P_0c09c400: /* original 4308, guest PC 0x0c09c400 */
if(!s->budget--) { s->failed_pc=0x0c09c400u; return 0; }
r[3]<<=2;
goto P_0c09c402;
P_0c09c402: /* original 32dc, guest PC 0x0c09c402 */
if(!s->budget--) { s->failed_pc=0x0c09c402u; return 0; }
r[2]+=r[13];
goto P_0c09c404;
P_0c09c404: /* original 332c, guest PC 0x0c09c404 */
if(!s->budget--) { s->failed_pc=0x0c09c404u; return 0; }
r[3]+=r[2];
goto P_0c09c406;
P_0c09c406: /* original 6132, guest PC 0x0c09c406 */
if(!s->budget--) { s->failed_pc=0x0c09c406u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c408;
P_0c09c408: /* original 21cb, guest PC 0x0c09c408 */
if(!s->budget--) { s->failed_pc=0x0c09c408u; return 0; }
r[1]|=r[12];
goto P_0c09c40a;
P_0c09c40a: /* original 2312, guest PC 0x0c09c40a */
if(!s->budget--) { s->failed_pc=0x0c09c40au; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c40c;
P_0c09c40c: /* original 63f2, guest PC 0x0c09c40c */
if(!s->budget--) { s->failed_pc=0x0c09c40cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09c40e;
P_0c09c40e: /* original e410, guest PC 0x0c09c40e */
if(!s->budget--) { s->failed_pc=0x0c09c40eu; return 0; }
r[4]=0x00000010u;
goto P_0c09c410;
P_0c09c410: /* original 2348, guest PC 0x0c09c410 */
if(!s->budget--) { s->failed_pc=0x0c09c410u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c09c412;
P_0c09c412: /* original 8b01, guest PC 0x0c09c412 */
if(!s->budget--) { s->failed_pc=0x0c09c412u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c418; }
goto P_0c09c414;
P_0c09c414: /* original a07d, guest PC 0x0c09c414 */
if(!s->budget--) { s->failed_pc=0x0c09c414u; return 0; }
goto P_0c09c512;
P_0c09c416: /* original 0009, guest PC 0x0c09c416 */
if(!s->budget--) { s->failed_pc=0x0c09c416u; return 0; }
goto P_0c09c418;
P_0c09c418: /* original 4a0b, guest PC 0x0c09c418 */
if(!s->budget--) { s->failed_pc=0x0c09c418u; return 0; }
target=r[10];
r[16]=code_base|0x0c09c41cu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c41cu) { target=s->pc; goto dispatch; }
goto P_0c09c41c;
P_0c09c41a: /* original 64b3, guest PC 0x0c09c41a */
if(!s->budget--) { s->failed_pc=0x0c09c41au; return 0; }
r[4]=r[11];
goto P_0c09c41c;
P_0c09c41c: /* original 921a, guest PC 0x0c09c41c */
if(!s->budget--) { s->failed_pc=0x0c09c41cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c454u,2);
goto P_0c09c41e;
P_0c09c41e: /* original 63e3, guest PC 0x0c09c41e */
if(!s->budget--) { s->failed_pc=0x0c09c41eu; return 0; }
r[3]=r[14];
goto P_0c09c420;
P_0c09c420: /* original 4308, guest PC 0x0c09c420 */
if(!s->budget--) { s->failed_pc=0x0c09c420u; return 0; }
r[3]<<=2;
goto P_0c09c422;
P_0c09c422: /* original 32dc, guest PC 0x0c09c422 */
if(!s->budget--) { s->failed_pc=0x0c09c422u; return 0; }
r[2]+=r[13];
goto P_0c09c424;
P_0c09c424: /* original 332c, guest PC 0x0c09c424 */
if(!s->budget--) { s->failed_pc=0x0c09c424u; return 0; }
r[3]+=r[2];
goto P_0c09c426;
P_0c09c426: /* original 6132, guest PC 0x0c09c426 */
if(!s->budget--) { s->failed_pc=0x0c09c426u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c428;
P_0c09c428: /* original 2118, guest PC 0x0c09c428 */
if(!s->budget--) { s->failed_pc=0x0c09c428u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c09c42a;
P_0c09c42a: /* original 8b15, guest PC 0x0c09c42a */
if(!s->budget--) { s->failed_pc=0x0c09c42au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c458; }
goto P_0c09c42c;
P_0c09c42c: /* original 9313, guest PC 0x0c09c42c */
if(!s->budget--) { s->failed_pc=0x0c09c42cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c456u,2);
goto P_0c09c42e;
P_0c09c42e: /* original 61e3, guest PC 0x0c09c42e */
if(!s->budget--) { s->failed_pc=0x0c09c42eu; return 0; }
r[1]=r[14];
goto P_0c09c430;
P_0c09c430: /* original 4108, guest PC 0x0c09c430 */
if(!s->budget--) { s->failed_pc=0x0c09c430u; return 0; }
r[1]<<=2;
goto P_0c09c432;
P_0c09c432: /* original 33dc, guest PC 0x0c09c432 */
if(!s->budget--) { s->failed_pc=0x0c09c432u; return 0; }
r[3]+=r[13];
goto P_0c09c434;
P_0c09c434: /* original 313c, guest PC 0x0c09c434 */
if(!s->budget--) { s->failed_pc=0x0c09c434u; return 0; }
r[1]+=r[3];
goto P_0c09c436;
P_0c09c436: /* original 6212, guest PC 0x0c09c436 */
if(!s->budget--) { s->failed_pc=0x0c09c436u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c09c438;
P_0c09c438: /* original 4215, guest PC 0x0c09c438 */
if(!s->budget--) { s->failed_pc=0x0c09c438u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c09c43a;
P_0c09c43a: /* original 8b63, guest PC 0x0c09c43a */
if(!s->budget--) { s->failed_pc=0x0c09c43au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c504; }
goto P_0c09c43c;
P_0c09c43c: /* original 930b, guest PC 0x0c09c43c */
if(!s->budget--) { s->failed_pc=0x0c09c43cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c456u,2);
goto P_0c09c43e;
P_0c09c43e: /* original 61e3, guest PC 0x0c09c43e */
if(!s->budget--) { s->failed_pc=0x0c09c43eu; return 0; }
r[1]=r[14];
goto P_0c09c440;
P_0c09c440: /* original 4108, guest PC 0x0c09c440 */
if(!s->budget--) { s->failed_pc=0x0c09c440u; return 0; }
r[1]<<=2;
goto P_0c09c442;
P_0c09c442: /* original 33dc, guest PC 0x0c09c442 */
if(!s->budget--) { s->failed_pc=0x0c09c442u; return 0; }
r[3]+=r[13];
goto P_0c09c444;
P_0c09c444: /* original 313c, guest PC 0x0c09c444 */
if(!s->budget--) { s->failed_pc=0x0c09c444u; return 0; }
r[1]+=r[3];
goto P_0c09c446;
P_0c09c446: /* original a064, guest PC 0x0c09c446 */
if(!s->budget--) { s->failed_pc=0x0c09c446u; return 0; }
write(ram,r[1],r[9],4);
goto P_0c09c512;
P_0c09c448: /* original 2192, guest PC 0x0c09c448 */
if(!s->budget--) { s->failed_pc=0x0c09c448u; return 0; }
write(ram,r[1],r[9],4);
if(!vf3_matrix_family(0x0c09c44au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09c44au; return 0; } return 1;
P_0c09c458: /* original 9280, guest PC 0x0c09c458 */
if(!s->budget--) { s->failed_pc=0x0c09c458u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c45a;
P_0c09c45a: /* original 63e3, guest PC 0x0c09c45a */
if(!s->budget--) { s->failed_pc=0x0c09c45au; return 0; }
r[3]=r[14];
goto P_0c09c45c;
P_0c09c45c: /* original 4308, guest PC 0x0c09c45c */
if(!s->budget--) { s->failed_pc=0x0c09c45cu; return 0; }
r[3]<<=2;
goto P_0c09c45e;
P_0c09c45e: /* original 32dc, guest PC 0x0c09c45e */
if(!s->budget--) { s->failed_pc=0x0c09c45eu; return 0; }
r[2]+=r[13];
goto P_0c09c460;
P_0c09c460: /* original 332c, guest PC 0x0c09c460 */
if(!s->budget--) { s->failed_pc=0x0c09c460u; return 0; }
r[3]+=r[2];
goto P_0c09c462;
P_0c09c462: /* original 6132, guest PC 0x0c09c462 */
if(!s->budget--) { s->failed_pc=0x0c09c462u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c464;
P_0c09c464: /* original 71ff, guest PC 0x0c09c464 */
if(!s->budget--) { s->failed_pc=0x0c09c464u; return 0; }
r[1]+=0xffffffffu;
goto P_0c09c466;
P_0c09c466: /* original 2312, guest PC 0x0c09c466 */
if(!s->budget--) { s->failed_pc=0x0c09c466u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c468;
P_0c09c468: /* original 53f2, guest PC 0x0c09c468 */
if(!s->budget--) { s->failed_pc=0x0c09c468u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c09c46a;
P_0c09c46a: /* original d23e, guest PC 0x0c09c46a */
if(!s->budget--) { s->failed_pc=0x0c09c46au; return 0; }
r[2]=read(ram,0x0c09c564u,4);
goto P_0c09c46c;
P_0c09c46c: /* original 6132, guest PC 0x0c09c46c */
if(!s->budget--) { s->failed_pc=0x0c09c46cu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c46e;
P_0c09c46e: /* original 3120, guest PC 0x0c09c46e */
if(!s->budget--) { s->failed_pc=0x0c09c46eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c09c470;
P_0c09c470: /* original 8b1d, guest PC 0x0c09c470 */
if(!s->budget--) { s->failed_pc=0x0c09c470u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c4ae; }
goto P_0c09c472;
P_0c09c472: /* original 9373, guest PC 0x0c09c472 */
if(!s->budget--) { s->failed_pc=0x0c09c472u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c474;
P_0c09c474: /* original 60e3, guest PC 0x0c09c474 */
if(!s->budget--) { s->failed_pc=0x0c09c474u; return 0; }
r[0]=r[14];
goto P_0c09c476;
P_0c09c476: /* original 4008, guest PC 0x0c09c476 */
if(!s->budget--) { s->failed_pc=0x0c09c476u; return 0; }
r[0]<<=2;
goto P_0c09c478;
P_0c09c478: /* original 33dc, guest PC 0x0c09c478 */
if(!s->budget--) { s->failed_pc=0x0c09c478u; return 0; }
r[3]+=r[13];
goto P_0c09c47a;
P_0c09c47a: /* original 003e, guest PC 0x0c09c47a */
if(!s->budget--) { s->failed_pc=0x0c09c47au; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c47c;
P_0c09c47c: /* original 8806, guest PC 0x0c09c47c */
if(!s->budget--) { s->failed_pc=0x0c09c47cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c09c47e;
P_0c09c47e: /* original 8b07, guest PC 0x0c09c47e */
if(!s->budget--) { s->failed_pc=0x0c09c47eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c490; }
goto P_0c09c480;
P_0c09c480: /* original 916c, guest PC 0x0c09c480 */
if(!s->budget--) { s->failed_pc=0x0c09c480u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c482;
P_0c09c482: /* original 63e3, guest PC 0x0c09c482 */
if(!s->budget--) { s->failed_pc=0x0c09c482u; return 0; }
r[3]=r[14];
goto P_0c09c484;
P_0c09c484: /* original 4308, guest PC 0x0c09c484 */
if(!s->budget--) { s->failed_pc=0x0c09c484u; return 0; }
r[3]<<=2;
goto P_0c09c486;
P_0c09c486: /* original 31dc, guest PC 0x0c09c486 */
if(!s->budget--) { s->failed_pc=0x0c09c486u; return 0; }
r[1]+=r[13];
goto P_0c09c488;
P_0c09c488: /* original 331c, guest PC 0x0c09c488 */
if(!s->budget--) { s->failed_pc=0x0c09c488u; return 0; }
r[3]+=r[1];
goto P_0c09c48a;
P_0c09c48a: /* original 6032, guest PC 0x0c09c48a */
if(!s->budget--) { s->failed_pc=0x0c09c48au; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c09c48c;
P_0c09c48c: /* original 70ff, guest PC 0x0c09c48c */
if(!s->budget--) { s->failed_pc=0x0c09c48cu; return 0; }
r[0]+=0xffffffffu;
goto P_0c09c48e;
P_0c09c48e: /* original 2302, guest PC 0x0c09c48e */
if(!s->budget--) { s->failed_pc=0x0c09c48eu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c09c490;
P_0c09c490: /* original 9364, guest PC 0x0c09c490 */
if(!s->budget--) { s->failed_pc=0x0c09c490u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c492;
P_0c09c492: /* original 60e3, guest PC 0x0c09c492 */
if(!s->budget--) { s->failed_pc=0x0c09c492u; return 0; }
r[0]=r[14];
goto P_0c09c494;
P_0c09c494: /* original 4008, guest PC 0x0c09c494 */
if(!s->budget--) { s->failed_pc=0x0c09c494u; return 0; }
r[0]<<=2;
goto P_0c09c496;
P_0c09c496: /* original 33dc, guest PC 0x0c09c496 */
if(!s->budget--) { s->failed_pc=0x0c09c496u; return 0; }
r[3]+=r[13];
goto P_0c09c498;
P_0c09c498: /* original 003e, guest PC 0x0c09c498 */
if(!s->budget--) { s->failed_pc=0x0c09c498u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c49a;
P_0c09c49a: /* original 8803, guest PC 0x0c09c49a */
if(!s->budget--) { s->failed_pc=0x0c09c49au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09c49c;
P_0c09c49c: /* original 8b07, guest PC 0x0c09c49c */
if(!s->budget--) { s->failed_pc=0x0c09c49cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c4ae; }
goto P_0c09c49e;
P_0c09c49e: /* original 925d, guest PC 0x0c09c49e */
if(!s->budget--) { s->failed_pc=0x0c09c49eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c4a0;
P_0c09c4a0: /* original 63e3, guest PC 0x0c09c4a0 */
if(!s->budget--) { s->failed_pc=0x0c09c4a0u; return 0; }
r[3]=r[14];
goto P_0c09c4a2;
P_0c09c4a2: /* original 4308, guest PC 0x0c09c4a2 */
if(!s->budget--) { s->failed_pc=0x0c09c4a2u; return 0; }
r[3]<<=2;
goto P_0c09c4a4;
P_0c09c4a4: /* original 32dc, guest PC 0x0c09c4a4 */
if(!s->budget--) { s->failed_pc=0x0c09c4a4u; return 0; }
r[2]+=r[13];
goto P_0c09c4a6;
P_0c09c4a6: /* original 332c, guest PC 0x0c09c4a6 */
if(!s->budget--) { s->failed_pc=0x0c09c4a6u; return 0; }
r[3]+=r[2];
goto P_0c09c4a8;
P_0c09c4a8: /* original 6132, guest PC 0x0c09c4a8 */
if(!s->budget--) { s->failed_pc=0x0c09c4a8u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c4aa;
P_0c09c4aa: /* original 71ff, guest PC 0x0c09c4aa */
if(!s->budget--) { s->failed_pc=0x0c09c4aau; return 0; }
r[1]+=0xffffffffu;
goto P_0c09c4ac;
P_0c09c4ac: /* original 2312, guest PC 0x0c09c4ac */
if(!s->budget--) { s->failed_pc=0x0c09c4acu; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c4ae;
P_0c09c4ae: /* original 53f2, guest PC 0x0c09c4ae */
if(!s->budget--) { s->failed_pc=0x0c09c4aeu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c09c4b0;
P_0c09c4b0: /* original 9255, guest PC 0x0c09c4b0 */
if(!s->budget--) { s->failed_pc=0x0c09c4b0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55eu,2);
goto P_0c09c4b2;
P_0c09c4b2: /* original 6132, guest PC 0x0c09c4b2 */
if(!s->budget--) { s->failed_pc=0x0c09c4b2u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c4b4;
P_0c09c4b4: /* original 3120, guest PC 0x0c09c4b4 */
if(!s->budget--) { s->failed_pc=0x0c09c4b4u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c09c4b6;
P_0c09c4b6: /* original 8b1d, guest PC 0x0c09c4b6 */
if(!s->budget--) { s->failed_pc=0x0c09c4b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c4f4; }
goto P_0c09c4b8;
P_0c09c4b8: /* original 9350, guest PC 0x0c09c4b8 */
if(!s->budget--) { s->failed_pc=0x0c09c4b8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c4ba;
P_0c09c4ba: /* original 60e3, guest PC 0x0c09c4ba */
if(!s->budget--) { s->failed_pc=0x0c09c4bau; return 0; }
r[0]=r[14];
goto P_0c09c4bc;
P_0c09c4bc: /* original 4008, guest PC 0x0c09c4bc */
if(!s->budget--) { s->failed_pc=0x0c09c4bcu; return 0; }
r[0]<<=2;
goto P_0c09c4be;
P_0c09c4be: /* original 33dc, guest PC 0x0c09c4be */
if(!s->budget--) { s->failed_pc=0x0c09c4beu; return 0; }
r[3]+=r[13];
goto P_0c09c4c0;
P_0c09c4c0: /* original 003e, guest PC 0x0c09c4c0 */
if(!s->budget--) { s->failed_pc=0x0c09c4c0u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c4c2;
P_0c09c4c2: /* original 8808, guest PC 0x0c09c4c2 */
if(!s->budget--) { s->failed_pc=0x0c09c4c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c09c4c4;
P_0c09c4c4: /* original 8b07, guest PC 0x0c09c4c4 */
if(!s->budget--) { s->failed_pc=0x0c09c4c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c4d6; }
goto P_0c09c4c6;
P_0c09c4c6: /* original 9149, guest PC 0x0c09c4c6 */
if(!s->budget--) { s->failed_pc=0x0c09c4c6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c4c8;
P_0c09c4c8: /* original 63e3, guest PC 0x0c09c4c8 */
if(!s->budget--) { s->failed_pc=0x0c09c4c8u; return 0; }
r[3]=r[14];
goto P_0c09c4ca;
P_0c09c4ca: /* original 4308, guest PC 0x0c09c4ca */
if(!s->budget--) { s->failed_pc=0x0c09c4cau; return 0; }
r[3]<<=2;
goto P_0c09c4cc;
P_0c09c4cc: /* original 31dc, guest PC 0x0c09c4cc */
if(!s->budget--) { s->failed_pc=0x0c09c4ccu; return 0; }
r[1]+=r[13];
goto P_0c09c4ce;
P_0c09c4ce: /* original 331c, guest PC 0x0c09c4ce */
if(!s->budget--) { s->failed_pc=0x0c09c4ceu; return 0; }
r[3]+=r[1];
goto P_0c09c4d0;
P_0c09c4d0: /* original 6032, guest PC 0x0c09c4d0 */
if(!s->budget--) { s->failed_pc=0x0c09c4d0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c09c4d2;
P_0c09c4d2: /* original 70ff, guest PC 0x0c09c4d2 */
if(!s->budget--) { s->failed_pc=0x0c09c4d2u; return 0; }
r[0]+=0xffffffffu;
goto P_0c09c4d4;
P_0c09c4d4: /* original 2302, guest PC 0x0c09c4d4 */
if(!s->budget--) { s->failed_pc=0x0c09c4d4u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c09c4d6;
P_0c09c4d6: /* original 9341, guest PC 0x0c09c4d6 */
if(!s->budget--) { s->failed_pc=0x0c09c4d6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c4d8;
P_0c09c4d8: /* original 60e3, guest PC 0x0c09c4d8 */
if(!s->budget--) { s->failed_pc=0x0c09c4d8u; return 0; }
r[0]=r[14];
goto P_0c09c4da;
P_0c09c4da: /* original 4008, guest PC 0x0c09c4da */
if(!s->budget--) { s->failed_pc=0x0c09c4dau; return 0; }
r[0]<<=2;
goto P_0c09c4dc;
P_0c09c4dc: /* original 33dc, guest PC 0x0c09c4dc */
if(!s->budget--) { s->failed_pc=0x0c09c4dcu; return 0; }
r[3]+=r[13];
goto P_0c09c4de;
P_0c09c4de: /* original 003e, guest PC 0x0c09c4de */
if(!s->budget--) { s->failed_pc=0x0c09c4deu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c4e0;
P_0c09c4e0: /* original 8807, guest PC 0x0c09c4e0 */
if(!s->budget--) { s->failed_pc=0x0c09c4e0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c09c4e2;
P_0c09c4e2: /* original 8b07, guest PC 0x0c09c4e2 */
if(!s->budget--) { s->failed_pc=0x0c09c4e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c4f4; }
goto P_0c09c4e4;
P_0c09c4e4: /* original 923a, guest PC 0x0c09c4e4 */
if(!s->budget--) { s->failed_pc=0x0c09c4e4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c4e6;
P_0c09c4e6: /* original 63e3, guest PC 0x0c09c4e6 */
if(!s->budget--) { s->failed_pc=0x0c09c4e6u; return 0; }
r[3]=r[14];
goto P_0c09c4e8;
P_0c09c4e8: /* original 4308, guest PC 0x0c09c4e8 */
if(!s->budget--) { s->failed_pc=0x0c09c4e8u; return 0; }
r[3]<<=2;
goto P_0c09c4ea;
P_0c09c4ea: /* original 32dc, guest PC 0x0c09c4ea */
if(!s->budget--) { s->failed_pc=0x0c09c4eau; return 0; }
r[2]+=r[13];
goto P_0c09c4ec;
P_0c09c4ec: /* original 332c, guest PC 0x0c09c4ec */
if(!s->budget--) { s->failed_pc=0x0c09c4ecu; return 0; }
r[3]+=r[2];
goto P_0c09c4ee;
P_0c09c4ee: /* original 6132, guest PC 0x0c09c4ee */
if(!s->budget--) { s->failed_pc=0x0c09c4eeu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c4f0;
P_0c09c4f0: /* original 71ff, guest PC 0x0c09c4f0 */
if(!s->budget--) { s->failed_pc=0x0c09c4f0u; return 0; }
r[1]+=0xffffffffu;
goto P_0c09c4f2;
P_0c09c4f2: /* original 2312, guest PC 0x0c09c4f2 */
if(!s->budget--) { s->failed_pc=0x0c09c4f2u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c4f4;
P_0c09c4f4: /* original 9232, guest PC 0x0c09c4f4 */
if(!s->budget--) { s->failed_pc=0x0c09c4f4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c4f6;
P_0c09c4f6: /* original 63e3, guest PC 0x0c09c4f6 */
if(!s->budget--) { s->failed_pc=0x0c09c4f6u; return 0; }
r[3]=r[14];
goto P_0c09c4f8;
P_0c09c4f8: /* original 4308, guest PC 0x0c09c4f8 */
if(!s->budget--) { s->failed_pc=0x0c09c4f8u; return 0; }
r[3]<<=2;
goto P_0c09c4fa;
P_0c09c4fa: /* original 32dc, guest PC 0x0c09c4fa */
if(!s->budget--) { s->failed_pc=0x0c09c4fau; return 0; }
r[2]+=r[13];
goto P_0c09c4fc;
P_0c09c4fc: /* original 332c, guest PC 0x0c09c4fc */
if(!s->budget--) { s->failed_pc=0x0c09c4fcu; return 0; }
r[3]+=r[2];
goto P_0c09c4fe;
P_0c09c4fe: /* original 6132, guest PC 0x0c09c4fe */
if(!s->budget--) { s->failed_pc=0x0c09c4feu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c500;
P_0c09c500: /* original 4111, guest PC 0x0c09c500 */
if(!s->budget--) { s->failed_pc=0x0c09c500u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=0)!=0);
goto P_0c09c502;
P_0c09c502: /* original 8906, guest PC 0x0c09c502 */
if(!s->budget--) { s->failed_pc=0x0c09c502u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c512; }
goto P_0c09c504;
P_0c09c504: /* original 932a, guest PC 0x0c09c504 */
if(!s->budget--) { s->failed_pc=0x0c09c504u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c506;
P_0c09c506: /* original 62e3, guest PC 0x0c09c506 */
if(!s->budget--) { s->failed_pc=0x0c09c506u; return 0; }
r[2]=r[14];
goto P_0c09c508;
P_0c09c508: /* original 4208, guest PC 0x0c09c508 */
if(!s->budget--) { s->failed_pc=0x0c09c508u; return 0; }
r[2]<<=2;
goto P_0c09c50a;
P_0c09c50a: /* original 33dc, guest PC 0x0c09c50a */
if(!s->budget--) { s->failed_pc=0x0c09c50au; return 0; }
r[3]+=r[13];
goto P_0c09c50c;
P_0c09c50c: /* original e109, guest PC 0x0c09c50c */
if(!s->budget--) { s->failed_pc=0x0c09c50cu; return 0; }
r[1]=0x00000009u;
goto P_0c09c50e;
P_0c09c50e: /* original 323c, guest PC 0x0c09c50e */
if(!s->budget--) { s->failed_pc=0x0c09c50eu; return 0; }
r[2]+=r[3];
goto P_0c09c510;
P_0c09c510: /* original 2212, guest PC 0x0c09c510 */
if(!s->budget--) { s->failed_pc=0x0c09c510u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c09c512;
P_0c09c512: /* original 60f2, guest PC 0x0c09c512 */
if(!s->budget--) { s->failed_pc=0x0c09c512u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c09c514;
P_0c09c514: /* original c820, guest PC 0x0c09c514 */
if(!s->budget--) { s->failed_pc=0x0c09c514u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c09c516;
P_0c09c516: /* original 8b01, guest PC 0x0c09c516 */
if(!s->budget--) { s->failed_pc=0x0c09c516u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c51c; }
goto P_0c09c518;
P_0c09c518: /* original a083, guest PC 0x0c09c518 */
if(!s->budget--) { s->failed_pc=0x0c09c518u; return 0; }
goto P_0c09c622;
P_0c09c51a: /* original 0009, guest PC 0x0c09c51a */
if(!s->budget--) { s->failed_pc=0x0c09c51au; return 0; }
goto P_0c09c51c;
P_0c09c51c: /* original 4a0b, guest PC 0x0c09c51c */
if(!s->budget--) { s->failed_pc=0x0c09c51cu; return 0; }
target=r[10];
r[16]=code_base|0x0c09c520u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c520u) { target=s->pc; goto dispatch; }
goto P_0c09c520;
P_0c09c51e: /* original 64b3, guest PC 0x0c09c51e */
if(!s->budget--) { s->failed_pc=0x0c09c51eu; return 0; }
r[4]=r[11];
goto P_0c09c520;
P_0c09c520: /* original 931e, guest PC 0x0c09c520 */
if(!s->budget--) { s->failed_pc=0x0c09c520u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c560u,2);
goto P_0c09c522;
P_0c09c522: /* original 62e3, guest PC 0x0c09c522 */
if(!s->budget--) { s->failed_pc=0x0c09c522u; return 0; }
r[2]=r[14];
goto P_0c09c524;
P_0c09c524: /* original 4208, guest PC 0x0c09c524 */
if(!s->budget--) { s->failed_pc=0x0c09c524u; return 0; }
r[2]<<=2;
goto P_0c09c526;
P_0c09c526: /* original 33dc, guest PC 0x0c09c526 */
if(!s->budget--) { s->failed_pc=0x0c09c526u; return 0; }
r[3]+=r[13];
goto P_0c09c528;
P_0c09c528: /* original 323c, guest PC 0x0c09c528 */
if(!s->budget--) { s->failed_pc=0x0c09c528u; return 0; }
r[2]+=r[3];
goto P_0c09c52a;
P_0c09c52a: /* original 6122, guest PC 0x0c09c52a */
if(!s->budget--) { s->failed_pc=0x0c09c52au; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c52c;
P_0c09c52c: /* original 2118, guest PC 0x0c09c52c */
if(!s->budget--) { s->failed_pc=0x0c09c52cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c09c52e;
P_0c09c52e: /* original 8b1b, guest PC 0x0c09c52e */
if(!s->budget--) { s->failed_pc=0x0c09c52eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c568; }
goto P_0c09c530;
P_0c09c530: /* original 9314, guest PC 0x0c09c530 */
if(!s->budget--) { s->failed_pc=0x0c09c530u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c532;
P_0c09c532: /* original 64e3, guest PC 0x0c09c532 */
if(!s->budget--) { s->failed_pc=0x0c09c532u; return 0; }
r[4]=r[14];
goto P_0c09c534;
P_0c09c534: /* original 4408, guest PC 0x0c09c534 */
if(!s->budget--) { s->failed_pc=0x0c09c534u; return 0; }
r[4]<<=2;
goto P_0c09c536;
P_0c09c536: /* original 33dc, guest PC 0x0c09c536 */
if(!s->budget--) { s->failed_pc=0x0c09c536u; return 0; }
r[3]+=r[13];
goto P_0c09c538;
P_0c09c538: /* original 334c, guest PC 0x0c09c538 */
if(!s->budget--) { s->failed_pc=0x0c09c538u; return 0; }
r[3]+=r[4];
goto P_0c09c53a;
P_0c09c53a: /* original 6232, guest PC 0x0c09c53a */
if(!s->budget--) { s->failed_pc=0x0c09c53au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c09c53c;
P_0c09c53c: /* original 7201, guest PC 0x0c09c53c */
if(!s->budget--) { s->failed_pc=0x0c09c53cu; return 0; }
r[2]+=0x00000001u;
goto P_0c09c53e;
P_0c09c53e: /* original 2322, guest PC 0x0c09c53e */
if(!s->budget--) { s->failed_pc=0x0c09c53eu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c09c540;
P_0c09c540: /* original e209, guest PC 0x0c09c540 */
if(!s->budget--) { s->failed_pc=0x0c09c540u; return 0; }
r[2]=0x00000009u;
goto P_0c09c542;
P_0c09c542: /* original 930b, guest PC 0x0c09c542 */
if(!s->budget--) { s->failed_pc=0x0c09c542u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c544;
P_0c09c544: /* original 33dc, guest PC 0x0c09c544 */
if(!s->budget--) { s->failed_pc=0x0c09c544u; return 0; }
r[3]+=r[13];
goto P_0c09c546;
P_0c09c546: /* original 343c, guest PC 0x0c09c546 */
if(!s->budget--) { s->failed_pc=0x0c09c546u; return 0; }
r[4]+=r[3];
goto P_0c09c548;
P_0c09c548: /* original 6142, guest PC 0x0c09c548 */
if(!s->budget--) { s->failed_pc=0x0c09c548u; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c09c54a;
P_0c09c54a: /* original 3123, guest PC 0x0c09c54a */
if(!s->budget--) { s->failed_pc=0x0c09c54au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c09c54c;
P_0c09c54c: /* original 8963, guest PC 0x0c09c54c */
if(!s->budget--) { s->failed_pc=0x0c09c54cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c616; }
goto P_0c09c54e;
P_0c09c54e: /* original 9305, guest PC 0x0c09c54e */
if(!s->budget--) { s->failed_pc=0x0c09c54eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c55cu,2);
goto P_0c09c550;
P_0c09c550: /* original 60e3, guest PC 0x0c09c550 */
if(!s->budget--) { s->failed_pc=0x0c09c550u; return 0; }
r[0]=r[14];
goto P_0c09c552;
P_0c09c552: /* original 4008, guest PC 0x0c09c552 */
if(!s->budget--) { s->failed_pc=0x0c09c552u; return 0; }
r[0]<<=2;
goto P_0c09c554;
P_0c09c554: /* original 33dc, guest PC 0x0c09c554 */
if(!s->budget--) { s->failed_pc=0x0c09c554u; return 0; }
r[3]+=r[13];
goto P_0c09c556;
P_0c09c556: /* original 303c, guest PC 0x0c09c556 */
if(!s->budget--) { s->failed_pc=0x0c09c556u; return 0; }
r[0]+=r[3];
goto P_0c09c558;
P_0c09c558: /* original a063, guest PC 0x0c09c558 */
if(!s->budget--) { s->failed_pc=0x0c09c558u; return 0; }
write(ram,r[0],r[2],4);
goto P_0c09c622;
P_0c09c55a: /* original 2022, guest PC 0x0c09c55a */
if(!s->budget--) { s->failed_pc=0x0c09c55au; return 0; }
write(ram,r[0],r[2],4);
if(!vf3_matrix_family(0x0c09c55cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09c55cu; return 0; } return 1;
P_0c09c568: /* original 9282, guest PC 0x0c09c568 */
if(!s->budget--) { s->failed_pc=0x0c09c568u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c56a;
P_0c09c56a: /* original 63e3, guest PC 0x0c09c56a */
if(!s->budget--) { s->failed_pc=0x0c09c56au; return 0; }
r[3]=r[14];
goto P_0c09c56c;
P_0c09c56c: /* original 4308, guest PC 0x0c09c56c */
if(!s->budget--) { s->failed_pc=0x0c09c56cu; return 0; }
r[3]<<=2;
goto P_0c09c56e;
P_0c09c56e: /* original 32dc, guest PC 0x0c09c56e */
if(!s->budget--) { s->failed_pc=0x0c09c56eu; return 0; }
r[2]+=r[13];
goto P_0c09c570;
P_0c09c570: /* original 332c, guest PC 0x0c09c570 */
if(!s->budget--) { s->failed_pc=0x0c09c570u; return 0; }
r[3]+=r[2];
goto P_0c09c572;
P_0c09c572: /* original 6132, guest PC 0x0c09c572 */
if(!s->budget--) { s->failed_pc=0x0c09c572u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c574;
P_0c09c574: /* original 7101, guest PC 0x0c09c574 */
if(!s->budget--) { s->failed_pc=0x0c09c574u; return 0; }
r[1]+=0x00000001u;
goto P_0c09c576;
P_0c09c576: /* original 2312, guest PC 0x0c09c576 */
if(!s->budget--) { s->failed_pc=0x0c09c576u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c578;
P_0c09c578: /* original 53f2, guest PC 0x0c09c578 */
if(!s->budget--) { s->failed_pc=0x0c09c578u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c09c57a;
P_0c09c57a: /* original d23f, guest PC 0x0c09c57a */
if(!s->budget--) { s->failed_pc=0x0c09c57au; return 0; }
r[2]=read(ram,0x0c09c678u,4);
goto P_0c09c57c;
P_0c09c57c: /* original 6132, guest PC 0x0c09c57c */
if(!s->budget--) { s->failed_pc=0x0c09c57cu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c57e;
P_0c09c57e: /* original 3120, guest PC 0x0c09c57e */
if(!s->budget--) { s->failed_pc=0x0c09c57eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c09c580;
P_0c09c580: /* original 8b1d, guest PC 0x0c09c580 */
if(!s->budget--) { s->failed_pc=0x0c09c580u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c5be; }
goto P_0c09c582;
P_0c09c582: /* original 9375, guest PC 0x0c09c582 */
if(!s->budget--) { s->failed_pc=0x0c09c582u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c584;
P_0c09c584: /* original 60e3, guest PC 0x0c09c584 */
if(!s->budget--) { s->failed_pc=0x0c09c584u; return 0; }
r[0]=r[14];
goto P_0c09c586;
P_0c09c586: /* original 4008, guest PC 0x0c09c586 */
if(!s->budget--) { s->failed_pc=0x0c09c586u; return 0; }
r[0]<<=2;
goto P_0c09c588;
P_0c09c588: /* original 33dc, guest PC 0x0c09c588 */
if(!s->budget--) { s->failed_pc=0x0c09c588u; return 0; }
r[3]+=r[13];
goto P_0c09c58a;
P_0c09c58a: /* original 003e, guest PC 0x0c09c58a */
if(!s->budget--) { s->failed_pc=0x0c09c58au; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c58c;
P_0c09c58c: /* original 8803, guest PC 0x0c09c58c */
if(!s->budget--) { s->failed_pc=0x0c09c58cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09c58e;
P_0c09c58e: /* original 8b07, guest PC 0x0c09c58e */
if(!s->budget--) { s->failed_pc=0x0c09c58eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c5a0; }
goto P_0c09c590;
P_0c09c590: /* original 916e, guest PC 0x0c09c590 */
if(!s->budget--) { s->failed_pc=0x0c09c590u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c592;
P_0c09c592: /* original 63e3, guest PC 0x0c09c592 */
if(!s->budget--) { s->failed_pc=0x0c09c592u; return 0; }
r[3]=r[14];
goto P_0c09c594;
P_0c09c594: /* original 4308, guest PC 0x0c09c594 */
if(!s->budget--) { s->failed_pc=0x0c09c594u; return 0; }
r[3]<<=2;
goto P_0c09c596;
P_0c09c596: /* original 31dc, guest PC 0x0c09c596 */
if(!s->budget--) { s->failed_pc=0x0c09c596u; return 0; }
r[1]+=r[13];
goto P_0c09c598;
P_0c09c598: /* original 331c, guest PC 0x0c09c598 */
if(!s->budget--) { s->failed_pc=0x0c09c598u; return 0; }
r[3]+=r[1];
goto P_0c09c59a;
P_0c09c59a: /* original 6032, guest PC 0x0c09c59a */
if(!s->budget--) { s->failed_pc=0x0c09c59au; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c09c59c;
P_0c09c59c: /* original 7001, guest PC 0x0c09c59c */
if(!s->budget--) { s->failed_pc=0x0c09c59cu; return 0; }
r[0]+=0x00000001u;
goto P_0c09c59e;
P_0c09c59e: /* original 2302, guest PC 0x0c09c59e */
if(!s->budget--) { s->failed_pc=0x0c09c59eu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c09c5a0;
P_0c09c5a0: /* original 9366, guest PC 0x0c09c5a0 */
if(!s->budget--) { s->failed_pc=0x0c09c5a0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c5a2;
P_0c09c5a2: /* original 60e3, guest PC 0x0c09c5a2 */
if(!s->budget--) { s->failed_pc=0x0c09c5a2u; return 0; }
r[0]=r[14];
goto P_0c09c5a4;
P_0c09c5a4: /* original 4008, guest PC 0x0c09c5a4 */
if(!s->budget--) { s->failed_pc=0x0c09c5a4u; return 0; }
r[0]<<=2;
goto P_0c09c5a6;
P_0c09c5a6: /* original 33dc, guest PC 0x0c09c5a6 */
if(!s->budget--) { s->failed_pc=0x0c09c5a6u; return 0; }
r[3]+=r[13];
goto P_0c09c5a8;
P_0c09c5a8: /* original 003e, guest PC 0x0c09c5a8 */
if(!s->budget--) { s->failed_pc=0x0c09c5a8u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c5aa;
P_0c09c5aa: /* original 8806, guest PC 0x0c09c5aa */
if(!s->budget--) { s->failed_pc=0x0c09c5aau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c09c5ac;
P_0c09c5ac: /* original 8b07, guest PC 0x0c09c5ac */
if(!s->budget--) { s->failed_pc=0x0c09c5acu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c5be; }
goto P_0c09c5ae;
P_0c09c5ae: /* original 925f, guest PC 0x0c09c5ae */
if(!s->budget--) { s->failed_pc=0x0c09c5aeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c5b0;
P_0c09c5b0: /* original 63e3, guest PC 0x0c09c5b0 */
if(!s->budget--) { s->failed_pc=0x0c09c5b0u; return 0; }
r[3]=r[14];
goto P_0c09c5b2;
P_0c09c5b2: /* original 4308, guest PC 0x0c09c5b2 */
if(!s->budget--) { s->failed_pc=0x0c09c5b2u; return 0; }
r[3]<<=2;
goto P_0c09c5b4;
P_0c09c5b4: /* original 32dc, guest PC 0x0c09c5b4 */
if(!s->budget--) { s->failed_pc=0x0c09c5b4u; return 0; }
r[2]+=r[13];
goto P_0c09c5b6;
P_0c09c5b6: /* original 332c, guest PC 0x0c09c5b6 */
if(!s->budget--) { s->failed_pc=0x0c09c5b6u; return 0; }
r[3]+=r[2];
goto P_0c09c5b8;
P_0c09c5b8: /* original 6132, guest PC 0x0c09c5b8 */
if(!s->budget--) { s->failed_pc=0x0c09c5b8u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c5ba;
P_0c09c5ba: /* original 7101, guest PC 0x0c09c5ba */
if(!s->budget--) { s->failed_pc=0x0c09c5bau; return 0; }
r[1]+=0x00000001u;
goto P_0c09c5bc;
P_0c09c5bc: /* original 2312, guest PC 0x0c09c5bc */
if(!s->budget--) { s->failed_pc=0x0c09c5bcu; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c5be;
P_0c09c5be: /* original 53f2, guest PC 0x0c09c5be */
if(!s->budget--) { s->failed_pc=0x0c09c5beu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c09c5c0;
P_0c09c5c0: /* original 9257, guest PC 0x0c09c5c0 */
if(!s->budget--) { s->failed_pc=0x0c09c5c0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c672u,2);
goto P_0c09c5c2;
P_0c09c5c2: /* original 6132, guest PC 0x0c09c5c2 */
if(!s->budget--) { s->failed_pc=0x0c09c5c2u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c5c4;
P_0c09c5c4: /* original 3120, guest PC 0x0c09c5c4 */
if(!s->budget--) { s->failed_pc=0x0c09c5c4u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c09c5c6;
P_0c09c5c6: /* original 8b1d, guest PC 0x0c09c5c6 */
if(!s->budget--) { s->failed_pc=0x0c09c5c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c604; }
goto P_0c09c5c8;
P_0c09c5c8: /* original 9352, guest PC 0x0c09c5c8 */
if(!s->budget--) { s->failed_pc=0x0c09c5c8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c5ca;
P_0c09c5ca: /* original 60e3, guest PC 0x0c09c5ca */
if(!s->budget--) { s->failed_pc=0x0c09c5cau; return 0; }
r[0]=r[14];
goto P_0c09c5cc;
P_0c09c5cc: /* original 4008, guest PC 0x0c09c5cc */
if(!s->budget--) { s->failed_pc=0x0c09c5ccu; return 0; }
r[0]<<=2;
goto P_0c09c5ce;
P_0c09c5ce: /* original 33dc, guest PC 0x0c09c5ce */
if(!s->budget--) { s->failed_pc=0x0c09c5ceu; return 0; }
r[3]+=r[13];
goto P_0c09c5d0;
P_0c09c5d0: /* original 003e, guest PC 0x0c09c5d0 */
if(!s->budget--) { s->failed_pc=0x0c09c5d0u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c5d2;
P_0c09c5d2: /* original 8807, guest PC 0x0c09c5d2 */
if(!s->budget--) { s->failed_pc=0x0c09c5d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c09c5d4;
P_0c09c5d4: /* original 8b07, guest PC 0x0c09c5d4 */
if(!s->budget--) { s->failed_pc=0x0c09c5d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c5e6; }
goto P_0c09c5d6;
P_0c09c5d6: /* original 914b, guest PC 0x0c09c5d6 */
if(!s->budget--) { s->failed_pc=0x0c09c5d6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c5d8;
P_0c09c5d8: /* original 63e3, guest PC 0x0c09c5d8 */
if(!s->budget--) { s->failed_pc=0x0c09c5d8u; return 0; }
r[3]=r[14];
goto P_0c09c5da;
P_0c09c5da: /* original 4308, guest PC 0x0c09c5da */
if(!s->budget--) { s->failed_pc=0x0c09c5dau; return 0; }
r[3]<<=2;
goto P_0c09c5dc;
P_0c09c5dc: /* original 31dc, guest PC 0x0c09c5dc */
if(!s->budget--) { s->failed_pc=0x0c09c5dcu; return 0; }
r[1]+=r[13];
goto P_0c09c5de;
P_0c09c5de: /* original 331c, guest PC 0x0c09c5de */
if(!s->budget--) { s->failed_pc=0x0c09c5deu; return 0; }
r[3]+=r[1];
goto P_0c09c5e0;
P_0c09c5e0: /* original 6032, guest PC 0x0c09c5e0 */
if(!s->budget--) { s->failed_pc=0x0c09c5e0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c09c5e2;
P_0c09c5e2: /* original 7001, guest PC 0x0c09c5e2 */
if(!s->budget--) { s->failed_pc=0x0c09c5e2u; return 0; }
r[0]+=0x00000001u;
goto P_0c09c5e4;
P_0c09c5e4: /* original 2302, guest PC 0x0c09c5e4 */
if(!s->budget--) { s->failed_pc=0x0c09c5e4u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c09c5e6;
P_0c09c5e6: /* original 9343, guest PC 0x0c09c5e6 */
if(!s->budget--) { s->failed_pc=0x0c09c5e6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c5e8;
P_0c09c5e8: /* original 60e3, guest PC 0x0c09c5e8 */
if(!s->budget--) { s->failed_pc=0x0c09c5e8u; return 0; }
r[0]=r[14];
goto P_0c09c5ea;
P_0c09c5ea: /* original 4008, guest PC 0x0c09c5ea */
if(!s->budget--) { s->failed_pc=0x0c09c5eau; return 0; }
r[0]<<=2;
goto P_0c09c5ec;
P_0c09c5ec: /* original 33dc, guest PC 0x0c09c5ec */
if(!s->budget--) { s->failed_pc=0x0c09c5ecu; return 0; }
r[3]+=r[13];
goto P_0c09c5ee;
P_0c09c5ee: /* original 003e, guest PC 0x0c09c5ee */
if(!s->budget--) { s->failed_pc=0x0c09c5eeu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c5f0;
P_0c09c5f0: /* original 8808, guest PC 0x0c09c5f0 */
if(!s->budget--) { s->failed_pc=0x0c09c5f0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c09c5f2;
P_0c09c5f2: /* original 8b07, guest PC 0x0c09c5f2 */
if(!s->budget--) { s->failed_pc=0x0c09c5f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c604; }
goto P_0c09c5f4;
P_0c09c5f4: /* original 923c, guest PC 0x0c09c5f4 */
if(!s->budget--) { s->failed_pc=0x0c09c5f4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c5f6;
P_0c09c5f6: /* original 63e3, guest PC 0x0c09c5f6 */
if(!s->budget--) { s->failed_pc=0x0c09c5f6u; return 0; }
r[3]=r[14];
goto P_0c09c5f8;
P_0c09c5f8: /* original 4308, guest PC 0x0c09c5f8 */
if(!s->budget--) { s->failed_pc=0x0c09c5f8u; return 0; }
r[3]<<=2;
goto P_0c09c5fa;
P_0c09c5fa: /* original 32dc, guest PC 0x0c09c5fa */
if(!s->budget--) { s->failed_pc=0x0c09c5fau; return 0; }
r[2]+=r[13];
goto P_0c09c5fc;
P_0c09c5fc: /* original 332c, guest PC 0x0c09c5fc */
if(!s->budget--) { s->failed_pc=0x0c09c5fcu; return 0; }
r[3]+=r[2];
goto P_0c09c5fe;
P_0c09c5fe: /* original 6132, guest PC 0x0c09c5fe */
if(!s->budget--) { s->failed_pc=0x0c09c5feu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c09c600;
P_0c09c600: /* original 7101, guest PC 0x0c09c600 */
if(!s->budget--) { s->failed_pc=0x0c09c600u; return 0; }
r[1]+=0x00000001u;
goto P_0c09c602;
P_0c09c602: /* original 2312, guest PC 0x0c09c602 */
if(!s->budget--) { s->failed_pc=0x0c09c602u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c604;
P_0c09c604: /* original 9234, guest PC 0x0c09c604 */
if(!s->budget--) { s->failed_pc=0x0c09c604u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c606;
P_0c09c606: /* original 63e3, guest PC 0x0c09c606 */
if(!s->budget--) { s->failed_pc=0x0c09c606u; return 0; }
r[3]=r[14];
goto P_0c09c608;
P_0c09c608: /* original 4308, guest PC 0x0c09c608 */
if(!s->budget--) { s->failed_pc=0x0c09c608u; return 0; }
r[3]<<=2;
goto P_0c09c60a;
P_0c09c60a: /* original 32dc, guest PC 0x0c09c60a */
if(!s->budget--) { s->failed_pc=0x0c09c60au; return 0; }
r[2]+=r[13];
goto P_0c09c60c;
P_0c09c60c: /* original 332c, guest PC 0x0c09c60c */
if(!s->budget--) { s->failed_pc=0x0c09c60cu; return 0; }
r[3]+=r[2];
goto P_0c09c60e;
P_0c09c60e: /* original 6032, guest PC 0x0c09c60e */
if(!s->budget--) { s->failed_pc=0x0c09c60eu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c09c610;
P_0c09c610: /* original e109, guest PC 0x0c09c610 */
if(!s->budget--) { s->failed_pc=0x0c09c610u; return 0; }
r[1]=0x00000009u;
goto P_0c09c612;
P_0c09c612: /* original 3017, guest PC 0x0c09c612 */
if(!s->budget--) { s->failed_pc=0x0c09c612u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>(int32_t)r[1])!=0);
goto P_0c09c614;
P_0c09c614: /* original 8b05, guest PC 0x0c09c614 */
if(!s->budget--) { s->failed_pc=0x0c09c614u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c622; }
goto P_0c09c616;
P_0c09c616: /* original 932b, guest PC 0x0c09c616 */
if(!s->budget--) { s->failed_pc=0x0c09c616u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c618;
P_0c09c618: /* original 62e3, guest PC 0x0c09c618 */
if(!s->budget--) { s->failed_pc=0x0c09c618u; return 0; }
r[2]=r[14];
goto P_0c09c61a;
P_0c09c61a: /* original 4208, guest PC 0x0c09c61a */
if(!s->budget--) { s->failed_pc=0x0c09c61au; return 0; }
r[2]<<=2;
goto P_0c09c61c;
P_0c09c61c: /* original 33dc, guest PC 0x0c09c61c */
if(!s->budget--) { s->failed_pc=0x0c09c61cu; return 0; }
r[3]+=r[13];
goto P_0c09c61e;
P_0c09c61e: /* original 323c, guest PC 0x0c09c61e */
if(!s->budget--) { s->failed_pc=0x0c09c61eu; return 0; }
r[2]+=r[3];
goto P_0c09c620;
P_0c09c620: /* original 2292, guest PC 0x0c09c620 */
if(!s->budget--) { s->failed_pc=0x0c09c620u; return 0; }
write(ram,r[2],r[9],4);
goto P_0c09c622;
P_0c09c622: /* original 60f2, guest PC 0x0c09c622 */
if(!s->budget--) { s->failed_pc=0x0c09c622u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c09c624;
P_0c09c624: /* original c840, guest PC 0x0c09c624 */
if(!s->budget--) { s->failed_pc=0x0c09c624u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c09c626;
P_0c09c626: /* original 8b01, guest PC 0x0c09c626 */
if(!s->budget--) { s->failed_pc=0x0c09c626u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c62c; }
goto P_0c09c628;
P_0c09c628: /* original a0f2, guest PC 0x0c09c628 */
if(!s->budget--) { s->failed_pc=0x0c09c628u; return 0; }
goto P_0c09c810;
P_0c09c62a: /* original 0009, guest PC 0x0c09c62a */
if(!s->budget--) { s->failed_pc=0x0c09c62au; return 0; }
goto P_0c09c62c;
P_0c09c62c: /* original 9320, guest PC 0x0c09c62c */
if(!s->budget--) { s->failed_pc=0x0c09c62cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c670u,2);
goto P_0c09c62e;
P_0c09c62e: /* original 62e3, guest PC 0x0c09c62e */
if(!s->budget--) { s->failed_pc=0x0c09c62eu; return 0; }
r[2]=r[14];
goto P_0c09c630;
P_0c09c630: /* original 4208, guest PC 0x0c09c630 */
if(!s->budget--) { s->failed_pc=0x0c09c630u; return 0; }
r[2]<<=2;
goto P_0c09c632;
P_0c09c632: /* original 33dc, guest PC 0x0c09c632 */
if(!s->budget--) { s->failed_pc=0x0c09c632u; return 0; }
r[3]+=r[13];
goto P_0c09c634;
P_0c09c634: /* original 323c, guest PC 0x0c09c634 */
if(!s->budget--) { s->failed_pc=0x0c09c634u; return 0; }
r[2]+=r[3];
goto P_0c09c636;
P_0c09c636: /* original 6122, guest PC 0x0c09c636 */
if(!s->budget--) { s->failed_pc=0x0c09c636u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c638;
P_0c09c638: /* original 2118, guest PC 0x0c09c638 */
if(!s->budget--) { s->failed_pc=0x0c09c638u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c09c63a;
P_0c09c63a: /* original 8b1f, guest PC 0x0c09c63a */
if(!s->budget--) { s->failed_pc=0x0c09c63au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c67c; }
goto P_0c09c63c;
P_0c09c63c: /* original 4a0b, guest PC 0x0c09c63c */
if(!s->budget--) { s->failed_pc=0x0c09c63cu; return 0; }
target=r[10];
r[16]=code_base|0x0c09c640u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c640u) { target=s->pc; goto dispatch; }
goto P_0c09c640;
P_0c09c63e: /* original 64b3, guest PC 0x0c09c63e */
if(!s->budget--) { s->failed_pc=0x0c09c63eu; return 0; }
r[4]=r[11];
goto P_0c09c640;
P_0c09c640: /* original 9219, guest PC 0x0c09c640 */
if(!s->budget--) { s->failed_pc=0x0c09c640u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c676u,2);
goto P_0c09c642;
P_0c09c642: /* original 64e3, guest PC 0x0c09c642 */
if(!s->budget--) { s->failed_pc=0x0c09c642u; return 0; }
r[4]=r[14];
goto P_0c09c644;
P_0c09c644: /* original 4408, guest PC 0x0c09c644 */
if(!s->budget--) { s->failed_pc=0x0c09c644u; return 0; }
r[4]<<=2;
goto P_0c09c646;
P_0c09c646: /* original 9315, guest PC 0x0c09c646 */
if(!s->budget--) { s->failed_pc=0x0c09c646u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c674u,2);
goto P_0c09c648;
P_0c09c648: /* original 32dc, guest PC 0x0c09c648 */
if(!s->budget--) { s->failed_pc=0x0c09c648u; return 0; }
r[2]+=r[13];
goto P_0c09c64a;
P_0c09c64a: /* original 324c, guest PC 0x0c09c64a */
if(!s->budget--) { s->failed_pc=0x0c09c64au; return 0; }
r[2]+=r[4];
goto P_0c09c64c;
P_0c09c64c: /* original 33dc, guest PC 0x0c09c64c */
if(!s->budget--) { s->failed_pc=0x0c09c64cu; return 0; }
r[3]+=r[13];
goto P_0c09c64e;
P_0c09c64e: /* original 6122, guest PC 0x0c09c64e */
if(!s->budget--) { s->failed_pc=0x0c09c64eu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c650;
P_0c09c650: /* original 334c, guest PC 0x0c09c650 */
if(!s->budget--) { s->failed_pc=0x0c09c650u; return 0; }
r[3]+=r[4];
goto P_0c09c652;
P_0c09c652: /* original 2312, guest PC 0x0c09c652 */
if(!s->budget--) { s->failed_pc=0x0c09c652u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c654;
P_0c09c654: /* original 930f, guest PC 0x0c09c654 */
if(!s->budget--) { s->failed_pc=0x0c09c654u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c676u,2);
goto P_0c09c656;
P_0c09c656: /* original 33dc, guest PC 0x0c09c656 */
if(!s->budget--) { s->failed_pc=0x0c09c656u; return 0; }
r[3]+=r[13];
goto P_0c09c658;
P_0c09c658: /* original 334c, guest PC 0x0c09c658 */
if(!s->budget--) { s->failed_pc=0x0c09c658u; return 0; }
r[3]+=r[4];
goto P_0c09c65a;
P_0c09c65a: /* original 6232, guest PC 0x0c09c65a */
if(!s->budget--) { s->failed_pc=0x0c09c65au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c09c65c;
P_0c09c65c: /* original 72ff, guest PC 0x0c09c65c */
if(!s->budget--) { s->failed_pc=0x0c09c65cu; return 0; }
r[2]+=0xffffffffu;
goto P_0c09c65e;
P_0c09c65e: /* original 2322, guest PC 0x0c09c65e */
if(!s->budget--) { s->failed_pc=0x0c09c65eu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c09c660;
P_0c09c660: /* original 9309, guest PC 0x0c09c660 */
if(!s->budget--) { s->failed_pc=0x0c09c660u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c676u,2);
goto P_0c09c662;
P_0c09c662: /* original 33dc, guest PC 0x0c09c662 */
if(!s->budget--) { s->failed_pc=0x0c09c662u; return 0; }
r[3]+=r[13];
goto P_0c09c664;
P_0c09c664: /* original 343c, guest PC 0x0c09c664 */
if(!s->budget--) { s->failed_pc=0x0c09c664u; return 0; }
r[4]+=r[3];
goto P_0c09c666;
P_0c09c666: /* original 6242, guest PC 0x0c09c666 */
if(!s->budget--) { s->failed_pc=0x0c09c666u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09c668;
P_0c09c668: /* original 4211, guest PC 0x0c09c668 */
if(!s->budget--) { s->failed_pc=0x0c09c668u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09c66a;
P_0c09c66a: /* original 8b28, guest PC 0x0c09c66a */
if(!s->budget--) { s->failed_pc=0x0c09c66au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c6be; }
goto P_0c09c66c;
P_0c09c66c: /* original a0d0, guest PC 0x0c09c66c */
if(!s->budget--) { s->failed_pc=0x0c09c66cu; return 0; }
goto P_0c09c810;
P_0c09c66e: /* original 0009, guest PC 0x0c09c66e */
if(!s->budget--) { s->failed_pc=0x0c09c66eu; return 0; }
if(!vf3_matrix_family(0x0c09c670u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09c670u; return 0; } return 1;
P_0c09c67c: /* original 936a, guest PC 0x0c09c67c */
if(!s->budget--) { s->failed_pc=0x0c09c67cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c754u,2);
goto P_0c09c67e;
P_0c09c67e: /* original 60e3, guest PC 0x0c09c67e */
if(!s->budget--) { s->failed_pc=0x0c09c67eu; return 0; }
r[0]=r[14];
goto P_0c09c680;
P_0c09c680: /* original 4008, guest PC 0x0c09c680 */
if(!s->budget--) { s->failed_pc=0x0c09c680u; return 0; }
r[0]<<=2;
goto P_0c09c682;
P_0c09c682: /* original 33dc, guest PC 0x0c09c682 */
if(!s->budget--) { s->failed_pc=0x0c09c682u; return 0; }
r[3]+=r[13];
goto P_0c09c684;
P_0c09c684: /* original 003e, guest PC 0x0c09c684 */
if(!s->budget--) { s->failed_pc=0x0c09c684u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c686;
P_0c09c686: /* original 8809, guest PC 0x0c09c686 */
if(!s->budget--) { s->failed_pc=0x0c09c686u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c09c688;
P_0c09c688: /* original 8b20, guest PC 0x0c09c688 */
if(!s->budget--) { s->failed_pc=0x0c09c688u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c6cc; }
goto P_0c09c68a;
P_0c09c68a: /* original 4a0b, guest PC 0x0c09c68a */
if(!s->budget--) { s->failed_pc=0x0c09c68au; return 0; }
target=r[10];
r[16]=code_base|0x0c09c68eu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c68eu) { target=s->pc; goto dispatch; }
goto P_0c09c68e;
P_0c09c68c: /* original 64b3, guest PC 0x0c09c68c */
if(!s->budget--) { s->failed_pc=0x0c09c68cu; return 0; }
r[4]=r[11];
goto P_0c09c68e;
P_0c09c68e: /* original 9263, guest PC 0x0c09c68e */
if(!s->budget--) { s->failed_pc=0x0c09c68eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c758u,2);
goto P_0c09c690;
P_0c09c690: /* original 64e3, guest PC 0x0c09c690 */
if(!s->budget--) { s->failed_pc=0x0c09c690u; return 0; }
r[4]=r[14];
goto P_0c09c692;
P_0c09c692: /* original 4408, guest PC 0x0c09c692 */
if(!s->budget--) { s->failed_pc=0x0c09c692u; return 0; }
r[4]<<=2;
goto P_0c09c694;
P_0c09c694: /* original 935f, guest PC 0x0c09c694 */
if(!s->budget--) { s->failed_pc=0x0c09c694u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c756u,2);
goto P_0c09c696;
P_0c09c696: /* original 32dc, guest PC 0x0c09c696 */
if(!s->budget--) { s->failed_pc=0x0c09c696u; return 0; }
r[2]+=r[13];
goto P_0c09c698;
P_0c09c698: /* original 324c, guest PC 0x0c09c698 */
if(!s->budget--) { s->failed_pc=0x0c09c698u; return 0; }
r[2]+=r[4];
goto P_0c09c69a;
P_0c09c69a: /* original 33dc, guest PC 0x0c09c69a */
if(!s->budget--) { s->failed_pc=0x0c09c69au; return 0; }
r[3]+=r[13];
goto P_0c09c69c;
P_0c09c69c: /* original 6122, guest PC 0x0c09c69c */
if(!s->budget--) { s->failed_pc=0x0c09c69cu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c69e;
P_0c09c69e: /* original 334c, guest PC 0x0c09c69e */
if(!s->budget--) { s->failed_pc=0x0c09c69eu; return 0; }
r[3]+=r[4];
goto P_0c09c6a0;
P_0c09c6a0: /* original 2312, guest PC 0x0c09c6a0 */
if(!s->budget--) { s->failed_pc=0x0c09c6a0u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c6a2;
P_0c09c6a2: /* original 9359, guest PC 0x0c09c6a2 */
if(!s->budget--) { s->failed_pc=0x0c09c6a2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c758u,2);
goto P_0c09c6a4;
P_0c09c6a4: /* original 33dc, guest PC 0x0c09c6a4 */
if(!s->budget--) { s->failed_pc=0x0c09c6a4u; return 0; }
r[3]+=r[13];
goto P_0c09c6a6;
P_0c09c6a6: /* original 334c, guest PC 0x0c09c6a6 */
if(!s->budget--) { s->failed_pc=0x0c09c6a6u; return 0; }
r[3]+=r[4];
goto P_0c09c6a8;
P_0c09c6a8: /* original 6232, guest PC 0x0c09c6a8 */
if(!s->budget--) { s->failed_pc=0x0c09c6a8u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c09c6aa;
P_0c09c6aa: /* original 72ff, guest PC 0x0c09c6aa */
if(!s->budget--) { s->failed_pc=0x0c09c6aau; return 0; }
r[2]+=0xffffffffu;
goto P_0c09c6ac;
P_0c09c6ac: /* original 2322, guest PC 0x0c09c6ac */
if(!s->budget--) { s->failed_pc=0x0c09c6acu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c09c6ae;
P_0c09c6ae: /* original 9353, guest PC 0x0c09c6ae */
if(!s->budget--) { s->failed_pc=0x0c09c6aeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c758u,2);
goto P_0c09c6b0;
P_0c09c6b0: /* original 33dc, guest PC 0x0c09c6b0 */
if(!s->budget--) { s->failed_pc=0x0c09c6b0u; return 0; }
r[3]+=r[13];
goto P_0c09c6b2;
P_0c09c6b2: /* original 343c, guest PC 0x0c09c6b2 */
if(!s->budget--) { s->failed_pc=0x0c09c6b2u; return 0; }
r[4]+=r[3];
goto P_0c09c6b4;
P_0c09c6b4: /* original 6242, guest PC 0x0c09c6b4 */
if(!s->budget--) { s->failed_pc=0x0c09c6b4u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09c6b6;
P_0c09c6b6: /* original 4211, guest PC 0x0c09c6b6 */
if(!s->budget--) { s->failed_pc=0x0c09c6b6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09c6b8;
P_0c09c6b8: /* original 8b01, guest PC 0x0c09c6b8 */
if(!s->budget--) { s->failed_pc=0x0c09c6b8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c6be; }
goto P_0c09c6ba;
P_0c09c6ba: /* original a0a9, guest PC 0x0c09c6ba */
if(!s->budget--) { s->failed_pc=0x0c09c6bau; return 0; }
goto P_0c09c810;
P_0c09c6bc: /* original 0009, guest PC 0x0c09c6bc */
if(!s->budget--) { s->failed_pc=0x0c09c6bcu; return 0; }
goto P_0c09c6be;
P_0c09c6be: /* original 934b, guest PC 0x0c09c6be */
if(!s->budget--) { s->failed_pc=0x0c09c6beu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c758u,2);
goto P_0c09c6c0;
P_0c09c6c0: /* original 61e3, guest PC 0x0c09c6c0 */
if(!s->budget--) { s->failed_pc=0x0c09c6c0u; return 0; }
r[1]=r[14];
goto P_0c09c6c2;
P_0c09c6c2: /* original 4108, guest PC 0x0c09c6c2 */
if(!s->budget--) { s->failed_pc=0x0c09c6c2u; return 0; }
r[1]<<=2;
goto P_0c09c6c4;
P_0c09c6c4: /* original 33dc, guest PC 0x0c09c6c4 */
if(!s->budget--) { s->failed_pc=0x0c09c6c4u; return 0; }
r[3]+=r[13];
goto P_0c09c6c6;
P_0c09c6c6: /* original 313c, guest PC 0x0c09c6c6 */
if(!s->budget--) { s->failed_pc=0x0c09c6c6u; return 0; }
r[1]+=r[3];
goto P_0c09c6c8;
P_0c09c6c8: /* original a0a2, guest PC 0x0c09c6c8 */
if(!s->budget--) { s->failed_pc=0x0c09c6c8u; return 0; }
write(ram,r[1],r[12],4);
goto P_0c09c810;
P_0c09c6ca: /* original 21c2, guest PC 0x0c09c6ca */
if(!s->budget--) { s->failed_pc=0x0c09c6cau; return 0; }
write(ram,r[1],r[12],4);
goto P_0c09c6cc;
P_0c09c6cc: /* original 4a0b, guest PC 0x0c09c6cc */
if(!s->budget--) { s->failed_pc=0x0c09c6ccu; return 0; }
target=r[10];
r[16]=code_base|0x0c09c6d0u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c6d0u) { target=s->pc; goto dispatch; }
goto P_0c09c6d0;
P_0c09c6ce: /* original 64b3, guest PC 0x0c09c6ce */
if(!s->budget--) { s->failed_pc=0x0c09c6ceu; return 0; }
r[4]=r[11];
goto P_0c09c6d0;
P_0c09c6d0: /* original 60e3, guest PC 0x0c09c6d0 */
if(!s->budget--) { s->failed_pc=0x0c09c6d0u; return 0; }
r[0]=r[14];
goto P_0c09c6d2;
P_0c09c6d2: /* original 9342, guest PC 0x0c09c6d2 */
if(!s->budget--) { s->failed_pc=0x0c09c6d2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c75au,2);
goto P_0c09c6d4;
P_0c09c6d4: /* original 4008, guest PC 0x0c09c6d4 */
if(!s->budget--) { s->failed_pc=0x0c09c6d4u; return 0; }
r[0]<<=2;
goto P_0c09c6d6;
P_0c09c6d6: /* original 62e3, guest PC 0x0c09c6d6 */
if(!s->budget--) { s->failed_pc=0x0c09c6d6u; return 0; }
r[2]=r[14];
goto P_0c09c6d8;
P_0c09c6d8: /* original 4008, guest PC 0x0c09c6d8 */
if(!s->budget--) { s->failed_pc=0x0c09c6d8u; return 0; }
r[0]<<=2;
goto P_0c09c6da;
P_0c09c6da: /* original 33dc, guest PC 0x0c09c6da */
if(!s->budget--) { s->failed_pc=0x0c09c6dau; return 0; }
r[3]+=r[13];
goto P_0c09c6dc;
P_0c09c6dc: /* original 4008, guest PC 0x0c09c6dc */
if(!s->budget--) { s->failed_pc=0x0c09c6dcu; return 0; }
r[0]<<=2;
goto P_0c09c6de;
P_0c09c6de: /* original 303c, guest PC 0x0c09c6de */
if(!s->budget--) { s->failed_pc=0x0c09c6deu; return 0; }
r[0]+=r[3];
goto P_0c09c6e0;
P_0c09c6e0: /* original 9338, guest PC 0x0c09c6e0 */
if(!s->budget--) { s->failed_pc=0x0c09c6e0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c754u,2);
goto P_0c09c6e2;
P_0c09c6e2: /* original 4208, guest PC 0x0c09c6e2 */
if(!s->budget--) { s->failed_pc=0x0c09c6e2u; return 0; }
r[2]<<=2;
goto P_0c09c6e4;
P_0c09c6e4: /* original 33dc, guest PC 0x0c09c6e4 */
if(!s->budget--) { s->failed_pc=0x0c09c6e4u; return 0; }
r[3]+=r[13];
goto P_0c09c6e6;
P_0c09c6e6: /* original 323c, guest PC 0x0c09c6e6 */
if(!s->budget--) { s->failed_pc=0x0c09c6e6u; return 0; }
r[2]+=r[3];
goto P_0c09c6e8;
P_0c09c6e8: /* original 6122, guest PC 0x0c09c6e8 */
if(!s->budget--) { s->failed_pc=0x0c09c6e8u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c6ea;
P_0c09c6ea: /* original 4108, guest PC 0x0c09c6ea */
if(!s->budget--) { s->failed_pc=0x0c09c6eau; return 0; }
r[1]<<=2;
goto P_0c09c6ec;
P_0c09c6ec: /* original 031e, guest PC 0x0c09c6ec */
if(!s->budget--) { s->failed_pc=0x0c09c6ecu; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c09c6ee;
P_0c09c6ee: /* original 2338, guest PC 0x0c09c6ee */
if(!s->budget--) { s->failed_pc=0x0c09c6eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09c6f0;
P_0c09c6f0: /* original 8b0f, guest PC 0x0c09c6f0 */
if(!s->budget--) { s->failed_pc=0x0c09c6f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c712; }
goto P_0c09c6f2;
P_0c09c6f2: /* original 60e3, guest PC 0x0c09c6f2 */
if(!s->budget--) { s->failed_pc=0x0c09c6f2u; return 0; }
r[0]=r[14];
goto P_0c09c6f4;
P_0c09c6f4: /* original 9331, guest PC 0x0c09c6f4 */
if(!s->budget--) { s->failed_pc=0x0c09c6f4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c75au,2);
goto P_0c09c6f6;
P_0c09c6f6: /* original 4008, guest PC 0x0c09c6f6 */
if(!s->budget--) { s->failed_pc=0x0c09c6f6u; return 0; }
r[0]<<=2;
goto P_0c09c6f8;
P_0c09c6f8: /* original 62e3, guest PC 0x0c09c6f8 */
if(!s->budget--) { s->failed_pc=0x0c09c6f8u; return 0; }
r[2]=r[14];
goto P_0c09c6fa;
P_0c09c6fa: /* original 4008, guest PC 0x0c09c6fa */
if(!s->budget--) { s->failed_pc=0x0c09c6fau; return 0; }
r[0]<<=2;
goto P_0c09c6fc;
P_0c09c6fc: /* original 33dc, guest PC 0x0c09c6fc */
if(!s->budget--) { s->failed_pc=0x0c09c6fcu; return 0; }
r[3]+=r[13];
goto P_0c09c6fe;
P_0c09c6fe: /* original 4008, guest PC 0x0c09c6fe */
if(!s->budget--) { s->failed_pc=0x0c09c6feu; return 0; }
r[0]<<=2;
goto P_0c09c700;
P_0c09c700: /* original 303c, guest PC 0x0c09c700 */
if(!s->budget--) { s->failed_pc=0x0c09c700u; return 0; }
r[0]+=r[3];
goto P_0c09c702;
P_0c09c702: /* original 9327, guest PC 0x0c09c702 */
if(!s->budget--) { s->failed_pc=0x0c09c702u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c754u,2);
goto P_0c09c704;
P_0c09c704: /* original 4208, guest PC 0x0c09c704 */
if(!s->budget--) { s->failed_pc=0x0c09c704u; return 0; }
r[2]<<=2;
goto P_0c09c706;
P_0c09c706: /* original 33dc, guest PC 0x0c09c706 */
if(!s->budget--) { s->failed_pc=0x0c09c706u; return 0; }
r[3]+=r[13];
goto P_0c09c708;
P_0c09c708: /* original 323c, guest PC 0x0c09c708 */
if(!s->budget--) { s->failed_pc=0x0c09c708u; return 0; }
r[2]+=r[3];
goto P_0c09c70a;
P_0c09c70a: /* original 6122, guest PC 0x0c09c70a */
if(!s->budget--) { s->failed_pc=0x0c09c70au; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c70c;
P_0c09c70c: /* original 4108, guest PC 0x0c09c70c */
if(!s->budget--) { s->failed_pc=0x0c09c70cu; return 0; }
r[1]<<=2;
goto P_0c09c70e;
P_0c09c70e: /* original a037, guest PC 0x0c09c70e */
if(!s->budget--) { s->failed_pc=0x0c09c70eu; return 0; }
write(ram,r[1]+r[0],r[12],4);
goto P_0c09c780;
P_0c09c710: /* original 01c6, guest PC 0x0c09c710 */
if(!s->budget--) { s->failed_pc=0x0c09c710u; return 0; }
write(ram,r[1]+r[0],r[12],4);
goto P_0c09c712;
P_0c09c712: /* original 60e3, guest PC 0x0c09c712 */
if(!s->budget--) { s->failed_pc=0x0c09c712u; return 0; }
r[0]=r[14];
goto P_0c09c714;
P_0c09c714: /* original 9321, guest PC 0x0c09c714 */
if(!s->budget--) { s->failed_pc=0x0c09c714u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c75au,2);
goto P_0c09c716;
P_0c09c716: /* original 4008, guest PC 0x0c09c716 */
if(!s->budget--) { s->failed_pc=0x0c09c716u; return 0; }
r[0]<<=2;
goto P_0c09c718;
P_0c09c718: /* original 62e3, guest PC 0x0c09c718 */
if(!s->budget--) { s->failed_pc=0x0c09c718u; return 0; }
r[2]=r[14];
goto P_0c09c71a;
P_0c09c71a: /* original 4008, guest PC 0x0c09c71a */
if(!s->budget--) { s->failed_pc=0x0c09c71au; return 0; }
r[0]<<=2;
goto P_0c09c71c;
P_0c09c71c: /* original 33dc, guest PC 0x0c09c71c */
if(!s->budget--) { s->failed_pc=0x0c09c71cu; return 0; }
r[3]+=r[13];
goto P_0c09c71e;
P_0c09c71e: /* original 4008, guest PC 0x0c09c71e */
if(!s->budget--) { s->failed_pc=0x0c09c71eu; return 0; }
r[0]<<=2;
goto P_0c09c720;
P_0c09c720: /* original 303c, guest PC 0x0c09c720 */
if(!s->budget--) { s->failed_pc=0x0c09c720u; return 0; }
r[0]+=r[3];
goto P_0c09c722;
P_0c09c722: /* original 9317, guest PC 0x0c09c722 */
if(!s->budget--) { s->failed_pc=0x0c09c722u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c754u,2);
goto P_0c09c724;
P_0c09c724: /* original 4208, guest PC 0x0c09c724 */
if(!s->budget--) { s->failed_pc=0x0c09c724u; return 0; }
r[2]<<=2;
goto P_0c09c726;
P_0c09c726: /* original 33dc, guest PC 0x0c09c726 */
if(!s->budget--) { s->failed_pc=0x0c09c726u; return 0; }
r[3]+=r[13];
goto P_0c09c728;
P_0c09c728: /* original 323c, guest PC 0x0c09c728 */
if(!s->budget--) { s->failed_pc=0x0c09c728u; return 0; }
r[2]+=r[3];
goto P_0c09c72a;
P_0c09c72a: /* original 6122, guest PC 0x0c09c72a */
if(!s->budget--) { s->failed_pc=0x0c09c72au; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c72c;
P_0c09c72c: /* original 4108, guest PC 0x0c09c72c */
if(!s->budget--) { s->failed_pc=0x0c09c72cu; return 0; }
r[1]<<=2;
goto P_0c09c72e;
P_0c09c72e: /* original 031e, guest PC 0x0c09c72e */
if(!s->budget--) { s->failed_pc=0x0c09c72eu; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c09c730;
P_0c09c730: /* original 3380, guest PC 0x0c09c730 */
if(!s->budget--) { s->failed_pc=0x0c09c730u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[8])!=0);
goto P_0c09c732;
P_0c09c732: /* original 8b13, guest PC 0x0c09c732 */
if(!s->budget--) { s->failed_pc=0x0c09c732u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c75c; }
goto P_0c09c734;
P_0c09c734: /* original 60e3, guest PC 0x0c09c734 */
if(!s->budget--) { s->failed_pc=0x0c09c734u; return 0; }
r[0]=r[14];
goto P_0c09c736;
P_0c09c736: /* original 9310, guest PC 0x0c09c736 */
if(!s->budget--) { s->failed_pc=0x0c09c736u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c75au,2);
goto P_0c09c738;
P_0c09c738: /* original 4008, guest PC 0x0c09c738 */
if(!s->budget--) { s->failed_pc=0x0c09c738u; return 0; }
r[0]<<=2;
goto P_0c09c73a;
P_0c09c73a: /* original 62e3, guest PC 0x0c09c73a */
if(!s->budget--) { s->failed_pc=0x0c09c73au; return 0; }
r[2]=r[14];
goto P_0c09c73c;
P_0c09c73c: /* original 4008, guest PC 0x0c09c73c */
if(!s->budget--) { s->failed_pc=0x0c09c73cu; return 0; }
r[0]<<=2;
goto P_0c09c73e;
P_0c09c73e: /* original 33dc, guest PC 0x0c09c73e */
if(!s->budget--) { s->failed_pc=0x0c09c73eu; return 0; }
r[3]+=r[13];
goto P_0c09c740;
P_0c09c740: /* original 4008, guest PC 0x0c09c740 */
if(!s->budget--) { s->failed_pc=0x0c09c740u; return 0; }
r[0]<<=2;
goto P_0c09c742;
P_0c09c742: /* original 303c, guest PC 0x0c09c742 */
if(!s->budget--) { s->failed_pc=0x0c09c742u; return 0; }
r[0]+=r[3];
goto P_0c09c744;
P_0c09c744: /* original 9306, guest PC 0x0c09c744 */
if(!s->budget--) { s->failed_pc=0x0c09c744u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c754u,2);
goto P_0c09c746;
P_0c09c746: /* original 4208, guest PC 0x0c09c746 */
if(!s->budget--) { s->failed_pc=0x0c09c746u; return 0; }
r[2]<<=2;
goto P_0c09c748;
P_0c09c748: /* original 33dc, guest PC 0x0c09c748 */
if(!s->budget--) { s->failed_pc=0x0c09c748u; return 0; }
r[3]+=r[13];
goto P_0c09c74a;
P_0c09c74a: /* original 323c, guest PC 0x0c09c74a */
if(!s->budget--) { s->failed_pc=0x0c09c74au; return 0; }
r[2]+=r[3];
goto P_0c09c74c;
P_0c09c74c: /* original 6122, guest PC 0x0c09c74c */
if(!s->budget--) { s->failed_pc=0x0c09c74cu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c74e;
P_0c09c74e: /* original 4108, guest PC 0x0c09c74e */
if(!s->budget--) { s->failed_pc=0x0c09c74eu; return 0; }
r[1]<<=2;
goto P_0c09c750;
P_0c09c750: /* original a016, guest PC 0x0c09c750 */
if(!s->budget--) { s->failed_pc=0x0c09c750u; return 0; }
write(ram,r[1]+r[0],r[9],4);
goto P_0c09c780;
P_0c09c752: /* original 0196, guest PC 0x0c09c752 */
if(!s->budget--) { s->failed_pc=0x0c09c752u; return 0; }
write(ram,r[1]+r[0],r[9],4);
if(!vf3_matrix_family(0x0c09c754u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09c754u; return 0; } return 1;
P_0c09c75c: /* original 64e3, guest PC 0x0c09c75c */
if(!s->budget--) { s->failed_pc=0x0c09c75cu; return 0; }
r[4]=r[14];
goto P_0c09c75e;
P_0c09c75e: /* original 93a6, guest PC 0x0c09c75e */
if(!s->budget--) { s->failed_pc=0x0c09c75eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8aeu,2);
goto P_0c09c760;
P_0c09c760: /* original 4408, guest PC 0x0c09c760 */
if(!s->budget--) { s->failed_pc=0x0c09c760u; return 0; }
r[4]<<=2;
goto P_0c09c762;
P_0c09c762: /* original 62e3, guest PC 0x0c09c762 */
if(!s->budget--) { s->failed_pc=0x0c09c762u; return 0; }
r[2]=r[14];
goto P_0c09c764;
P_0c09c764: /* original 4408, guest PC 0x0c09c764 */
if(!s->budget--) { s->failed_pc=0x0c09c764u; return 0; }
r[4]<<=2;
goto P_0c09c766;
P_0c09c766: /* original 33dc, guest PC 0x0c09c766 */
if(!s->budget--) { s->failed_pc=0x0c09c766u; return 0; }
r[3]+=r[13];
goto P_0c09c768;
P_0c09c768: /* original 4408, guest PC 0x0c09c768 */
if(!s->budget--) { s->failed_pc=0x0c09c768u; return 0; }
r[4]<<=2;
goto P_0c09c76a;
P_0c09c76a: /* original 343c, guest PC 0x0c09c76a */
if(!s->budget--) { s->failed_pc=0x0c09c76au; return 0; }
r[4]+=r[3];
goto P_0c09c76c;
P_0c09c76c: /* original 93a0, guest PC 0x0c09c76c */
if(!s->budget--) { s->failed_pc=0x0c09c76cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b0u,2);
goto P_0c09c76e;
P_0c09c76e: /* original 4208, guest PC 0x0c09c76e */
if(!s->budget--) { s->failed_pc=0x0c09c76eu; return 0; }
r[2]<<=2;
goto P_0c09c770;
P_0c09c770: /* original 33dc, guest PC 0x0c09c770 */
if(!s->budget--) { s->failed_pc=0x0c09c770u; return 0; }
r[3]+=r[13];
goto P_0c09c772;
P_0c09c772: /* original 323c, guest PC 0x0c09c772 */
if(!s->budget--) { s->failed_pc=0x0c09c772u; return 0; }
r[2]+=r[3];
goto P_0c09c774;
P_0c09c774: /* original 6122, guest PC 0x0c09c774 */
if(!s->budget--) { s->failed_pc=0x0c09c774u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c776;
P_0c09c776: /* original 4108, guest PC 0x0c09c776 */
if(!s->budget--) { s->failed_pc=0x0c09c776u; return 0; }
r[1]<<=2;
goto P_0c09c778;
P_0c09c778: /* original 341c, guest PC 0x0c09c778 */
if(!s->budget--) { s->failed_pc=0x0c09c778u; return 0; }
r[4]+=r[1];
goto P_0c09c77a;
P_0c09c77a: /* original 6342, guest PC 0x0c09c77a */
if(!s->budget--) { s->failed_pc=0x0c09c77au; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c09c77c;
P_0c09c77c: /* original 4300, guest PC 0x0c09c77c */
if(!s->budget--) { s->failed_pc=0x0c09c77cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c09c77e;
P_0c09c77e: /* original 2432, guest PC 0x0c09c77e */
if(!s->budget--) { s->failed_pc=0x0c09c77eu; return 0; }
write(ram,r[4],r[3],4);
goto P_0c09c780;
P_0c09c780: /* original 9396, guest PC 0x0c09c780 */
if(!s->budget--) { s->failed_pc=0x0c09c780u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b0u,2);
goto P_0c09c782;
P_0c09c782: /* original 60e3, guest PC 0x0c09c782 */
if(!s->budget--) { s->failed_pc=0x0c09c782u; return 0; }
r[0]=r[14];
goto P_0c09c784;
P_0c09c784: /* original 4008, guest PC 0x0c09c784 */
if(!s->budget--) { s->failed_pc=0x0c09c784u; return 0; }
r[0]<<=2;
goto P_0c09c786;
P_0c09c786: /* original 33dc, guest PC 0x0c09c786 */
if(!s->budget--) { s->failed_pc=0x0c09c786u; return 0; }
r[3]+=r[13];
goto P_0c09c788;
P_0c09c788: /* original 003e, guest PC 0x0c09c788 */
if(!s->budget--) { s->failed_pc=0x0c09c788u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c78a;
P_0c09c78a: /* original 8801, guest PC 0x0c09c78a */
if(!s->budget--) { s->failed_pc=0x0c09c78au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09c78c;
P_0c09c78c: /* original 8b40, guest PC 0x0c09c78c */
if(!s->budget--) { s->failed_pc=0x0c09c78cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c810; }
goto P_0c09c78e;
P_0c09c78e: /* original 60e3, guest PC 0x0c09c78e */
if(!s->budget--) { s->failed_pc=0x0c09c78eu; return 0; }
r[0]=r[14];
goto P_0c09c790;
P_0c09c790: /* original 938d, guest PC 0x0c09c790 */
if(!s->budget--) { s->failed_pc=0x0c09c790u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8aeu,2);
goto P_0c09c792;
P_0c09c792: /* original 4008, guest PC 0x0c09c792 */
if(!s->budget--) { s->failed_pc=0x0c09c792u; return 0; }
r[0]<<=2;
goto P_0c09c794;
P_0c09c794: /* original 62e3, guest PC 0x0c09c794 */
if(!s->budget--) { s->failed_pc=0x0c09c794u; return 0; }
r[2]=r[14];
goto P_0c09c796;
P_0c09c796: /* original 4008, guest PC 0x0c09c796 */
if(!s->budget--) { s->failed_pc=0x0c09c796u; return 0; }
r[0]<<=2;
goto P_0c09c798;
P_0c09c798: /* original 33dc, guest PC 0x0c09c798 */
if(!s->budget--) { s->failed_pc=0x0c09c798u; return 0; }
r[3]+=r[13];
goto P_0c09c79a;
P_0c09c79a: /* original 4008, guest PC 0x0c09c79a */
if(!s->budget--) { s->failed_pc=0x0c09c79au; return 0; }
r[0]<<=2;
goto P_0c09c79c;
P_0c09c79c: /* original 303c, guest PC 0x0c09c79c */
if(!s->budget--) { s->failed_pc=0x0c09c79cu; return 0; }
r[0]+=r[3];
goto P_0c09c79e;
P_0c09c79e: /* original 9387, guest PC 0x0c09c79e */
if(!s->budget--) { s->failed_pc=0x0c09c79eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b0u,2);
goto P_0c09c7a0;
P_0c09c7a0: /* original 4208, guest PC 0x0c09c7a0 */
if(!s->budget--) { s->failed_pc=0x0c09c7a0u; return 0; }
r[2]<<=2;
goto P_0c09c7a2;
P_0c09c7a2: /* original 33dc, guest PC 0x0c09c7a2 */
if(!s->budget--) { s->failed_pc=0x0c09c7a2u; return 0; }
r[3]+=r[13];
goto P_0c09c7a4;
P_0c09c7a4: /* original 323c, guest PC 0x0c09c7a4 */
if(!s->budget--) { s->failed_pc=0x0c09c7a4u; return 0; }
r[2]+=r[3];
goto P_0c09c7a6;
P_0c09c7a6: /* original 6122, guest PC 0x0c09c7a6 */
if(!s->budget--) { s->failed_pc=0x0c09c7a6u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c7a8;
P_0c09c7a8: /* original 4108, guest PC 0x0c09c7a8 */
if(!s->budget--) { s->failed_pc=0x0c09c7a8u; return 0; }
r[1]<<=2;
goto P_0c09c7aa;
P_0c09c7aa: /* original 001e, guest PC 0x0c09c7aa */
if(!s->budget--) { s->failed_pc=0x0c09c7aau; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c09c7ac;
P_0c09c7ac: /* original 8810, guest PC 0x0c09c7ac */
if(!s->budget--) { s->failed_pc=0x0c09c7acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c09c7ae;
P_0c09c7ae: /* original 8b0f, guest PC 0x0c09c7ae */
if(!s->budget--) { s->failed_pc=0x0c09c7aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c7d0; }
goto P_0c09c7b0;
P_0c09c7b0: /* original 60e3, guest PC 0x0c09c7b0 */
if(!s->budget--) { s->failed_pc=0x0c09c7b0u; return 0; }
r[0]=r[14];
goto P_0c09c7b2;
P_0c09c7b2: /* original 937c, guest PC 0x0c09c7b2 */
if(!s->budget--) { s->failed_pc=0x0c09c7b2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8aeu,2);
goto P_0c09c7b4;
P_0c09c7b4: /* original 4008, guest PC 0x0c09c7b4 */
if(!s->budget--) { s->failed_pc=0x0c09c7b4u; return 0; }
r[0]<<=2;
goto P_0c09c7b6;
P_0c09c7b6: /* original 62e3, guest PC 0x0c09c7b6 */
if(!s->budget--) { s->failed_pc=0x0c09c7b6u; return 0; }
r[2]=r[14];
goto P_0c09c7b8;
P_0c09c7b8: /* original 4008, guest PC 0x0c09c7b8 */
if(!s->budget--) { s->failed_pc=0x0c09c7b8u; return 0; }
r[0]<<=2;
goto P_0c09c7ba;
P_0c09c7ba: /* original 33dc, guest PC 0x0c09c7ba */
if(!s->budget--) { s->failed_pc=0x0c09c7bau; return 0; }
r[3]+=r[13];
goto P_0c09c7bc;
P_0c09c7bc: /* original 4008, guest PC 0x0c09c7bc */
if(!s->budget--) { s->failed_pc=0x0c09c7bcu; return 0; }
r[0]<<=2;
goto P_0c09c7be;
P_0c09c7be: /* original 303c, guest PC 0x0c09c7be */
if(!s->budget--) { s->failed_pc=0x0c09c7beu; return 0; }
r[0]+=r[3];
goto P_0c09c7c0;
P_0c09c7c0: /* original 9376, guest PC 0x0c09c7c0 */
if(!s->budget--) { s->failed_pc=0x0c09c7c0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b0u,2);
goto P_0c09c7c2;
P_0c09c7c2: /* original 4208, guest PC 0x0c09c7c2 */
if(!s->budget--) { s->failed_pc=0x0c09c7c2u; return 0; }
r[2]<<=2;
goto P_0c09c7c4;
P_0c09c7c4: /* original 33dc, guest PC 0x0c09c7c4 */
if(!s->budget--) { s->failed_pc=0x0c09c7c4u; return 0; }
r[3]+=r[13];
goto P_0c09c7c6;
P_0c09c7c6: /* original 323c, guest PC 0x0c09c7c6 */
if(!s->budget--) { s->failed_pc=0x0c09c7c6u; return 0; }
r[2]+=r[3];
goto P_0c09c7c8;
P_0c09c7c8: /* original 6122, guest PC 0x0c09c7c8 */
if(!s->budget--) { s->failed_pc=0x0c09c7c8u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c7ca;
P_0c09c7ca: /* original e320, guest PC 0x0c09c7ca */
if(!s->budget--) { s->failed_pc=0x0c09c7cau; return 0; }
r[3]=0x00000020u;
goto P_0c09c7cc;
P_0c09c7cc: /* original 4108, guest PC 0x0c09c7cc */
if(!s->budget--) { s->failed_pc=0x0c09c7ccu; return 0; }
r[1]<<=2;
goto P_0c09c7ce;
P_0c09c7ce: /* original 0136, guest PC 0x0c09c7ce */
if(!s->budget--) { s->failed_pc=0x0c09c7ceu; return 0; }
write(ram,r[1]+r[0],r[3],4);
goto P_0c09c7d0;
P_0c09c7d0: /* original 60e3, guest PC 0x0c09c7d0 */
if(!s->budget--) { s->failed_pc=0x0c09c7d0u; return 0; }
r[0]=r[14];
goto P_0c09c7d2;
P_0c09c7d2: /* original 936c, guest PC 0x0c09c7d2 */
if(!s->budget--) { s->failed_pc=0x0c09c7d2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8aeu,2);
goto P_0c09c7d4;
P_0c09c7d4: /* original 4008, guest PC 0x0c09c7d4 */
if(!s->budget--) { s->failed_pc=0x0c09c7d4u; return 0; }
r[0]<<=2;
goto P_0c09c7d6;
P_0c09c7d6: /* original 62e3, guest PC 0x0c09c7d6 */
if(!s->budget--) { s->failed_pc=0x0c09c7d6u; return 0; }
r[2]=r[14];
goto P_0c09c7d8;
P_0c09c7d8: /* original 4008, guest PC 0x0c09c7d8 */
if(!s->budget--) { s->failed_pc=0x0c09c7d8u; return 0; }
r[0]<<=2;
goto P_0c09c7da;
P_0c09c7da: /* original 33dc, guest PC 0x0c09c7da */
if(!s->budget--) { s->failed_pc=0x0c09c7dau; return 0; }
r[3]+=r[13];
goto P_0c09c7dc;
P_0c09c7dc: /* original 4008, guest PC 0x0c09c7dc */
if(!s->budget--) { s->failed_pc=0x0c09c7dcu; return 0; }
r[0]<<=2;
goto P_0c09c7de;
P_0c09c7de: /* original 303c, guest PC 0x0c09c7de */
if(!s->budget--) { s->failed_pc=0x0c09c7deu; return 0; }
r[0]+=r[3];
goto P_0c09c7e0;
P_0c09c7e0: /* original 9366, guest PC 0x0c09c7e0 */
if(!s->budget--) { s->failed_pc=0x0c09c7e0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b0u,2);
goto P_0c09c7e2;
P_0c09c7e2: /* original 4208, guest PC 0x0c09c7e2 */
if(!s->budget--) { s->failed_pc=0x0c09c7e2u; return 0; }
r[2]<<=2;
goto P_0c09c7e4;
P_0c09c7e4: /* original 33dc, guest PC 0x0c09c7e4 */
if(!s->budget--) { s->failed_pc=0x0c09c7e4u; return 0; }
r[3]+=r[13];
goto P_0c09c7e6;
P_0c09c7e6: /* original 323c, guest PC 0x0c09c7e6 */
if(!s->budget--) { s->failed_pc=0x0c09c7e6u; return 0; }
r[2]+=r[3];
goto P_0c09c7e8;
P_0c09c7e8: /* original 6122, guest PC 0x0c09c7e8 */
if(!s->budget--) { s->failed_pc=0x0c09c7e8u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c7ea;
P_0c09c7ea: /* original 4108, guest PC 0x0c09c7ea */
if(!s->budget--) { s->failed_pc=0x0c09c7eau; return 0; }
r[1]<<=2;
goto P_0c09c7ec;
P_0c09c7ec: /* original 031e, guest PC 0x0c09c7ec */
if(!s->budget--) { s->failed_pc=0x0c09c7ecu; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c09c7ee;
P_0c09c7ee: /* original 2338, guest PC 0x0c09c7ee */
if(!s->budget--) { s->failed_pc=0x0c09c7eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09c7f0;
P_0c09c7f0: /* original 8b0e, guest PC 0x0c09c7f0 */
if(!s->budget--) { s->failed_pc=0x0c09c7f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c810; }
goto P_0c09c7f2;
P_0c09c7f2: /* original 60e3, guest PC 0x0c09c7f2 */
if(!s->budget--) { s->failed_pc=0x0c09c7f2u; return 0; }
r[0]=r[14];
goto P_0c09c7f4;
P_0c09c7f4: /* original 935b, guest PC 0x0c09c7f4 */
if(!s->budget--) { s->failed_pc=0x0c09c7f4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8aeu,2);
goto P_0c09c7f6;
P_0c09c7f6: /* original 4008, guest PC 0x0c09c7f6 */
if(!s->budget--) { s->failed_pc=0x0c09c7f6u; return 0; }
r[0]<<=2;
goto P_0c09c7f8;
P_0c09c7f8: /* original 62e3, guest PC 0x0c09c7f8 */
if(!s->budget--) { s->failed_pc=0x0c09c7f8u; return 0; }
r[2]=r[14];
goto P_0c09c7fa;
P_0c09c7fa: /* original 4008, guest PC 0x0c09c7fa */
if(!s->budget--) { s->failed_pc=0x0c09c7fau; return 0; }
r[0]<<=2;
goto P_0c09c7fc;
P_0c09c7fc: /* original 33dc, guest PC 0x0c09c7fc */
if(!s->budget--) { s->failed_pc=0x0c09c7fcu; return 0; }
r[3]+=r[13];
goto P_0c09c7fe;
P_0c09c7fe: /* original 4008, guest PC 0x0c09c7fe */
if(!s->budget--) { s->failed_pc=0x0c09c7feu; return 0; }
r[0]<<=2;
goto P_0c09c800;
P_0c09c800: /* original 303c, guest PC 0x0c09c800 */
if(!s->budget--) { s->failed_pc=0x0c09c800u; return 0; }
r[0]+=r[3];
goto P_0c09c802;
P_0c09c802: /* original 9355, guest PC 0x0c09c802 */
if(!s->budget--) { s->failed_pc=0x0c09c802u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b0u,2);
goto P_0c09c804;
P_0c09c804: /* original 4208, guest PC 0x0c09c804 */
if(!s->budget--) { s->failed_pc=0x0c09c804u; return 0; }
r[2]<<=2;
goto P_0c09c806;
P_0c09c806: /* original 33dc, guest PC 0x0c09c806 */
if(!s->budget--) { s->failed_pc=0x0c09c806u; return 0; }
r[3]+=r[13];
goto P_0c09c808;
P_0c09c808: /* original 323c, guest PC 0x0c09c808 */
if(!s->budget--) { s->failed_pc=0x0c09c808u; return 0; }
r[2]+=r[3];
goto P_0c09c80a;
P_0c09c80a: /* original 6122, guest PC 0x0c09c80a */
if(!s->budget--) { s->failed_pc=0x0c09c80au; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c80c;
P_0c09c80c: /* original 4108, guest PC 0x0c09c80c */
if(!s->budget--) { s->failed_pc=0x0c09c80cu; return 0; }
r[1]<<=2;
goto P_0c09c80e;
P_0c09c80e: /* original 01c6, guest PC 0x0c09c80e */
if(!s->budget--) { s->failed_pc=0x0c09c80eu; return 0; }
write(ram,r[1]+r[0],r[12],4);
goto P_0c09c810;
P_0c09c810: /* original 60f2, guest PC 0x0c09c810 */
if(!s->budget--) { s->failed_pc=0x0c09c810u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c09c812;
P_0c09c812: /* original c880, guest PC 0x0c09c812 */
if(!s->budget--) { s->failed_pc=0x0c09c812u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c09c814;
P_0c09c814: /* original 8b01, guest PC 0x0c09c814 */
if(!s->budget--) { s->failed_pc=0x0c09c814u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c81a; }
goto P_0c09c816;
P_0c09c816: /* original a0ee, guest PC 0x0c09c816 */
if(!s->budget--) { s->failed_pc=0x0c09c816u; return 0; }
goto P_0c09c9f6;
P_0c09c818: /* original 0009, guest PC 0x0c09c818 */
if(!s->budget--) { s->failed_pc=0x0c09c818u; return 0; }
goto P_0c09c81a;
P_0c09c81a: /* original 9349, guest PC 0x0c09c81a */
if(!s->budget--) { s->failed_pc=0x0c09c81au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b0u,2);
goto P_0c09c81c;
P_0c09c81c: /* original 62e3, guest PC 0x0c09c81c */
if(!s->budget--) { s->failed_pc=0x0c09c81cu; return 0; }
r[2]=r[14];
goto P_0c09c81e;
P_0c09c81e: /* original 4208, guest PC 0x0c09c81e */
if(!s->budget--) { s->failed_pc=0x0c09c81eu; return 0; }
r[2]<<=2;
goto P_0c09c820;
P_0c09c820: /* original 33dc, guest PC 0x0c09c820 */
if(!s->budget--) { s->failed_pc=0x0c09c820u; return 0; }
r[3]+=r[13];
goto P_0c09c822;
P_0c09c822: /* original 323c, guest PC 0x0c09c822 */
if(!s->budget--) { s->failed_pc=0x0c09c822u; return 0; }
r[2]+=r[3];
goto P_0c09c824;
P_0c09c824: /* original 6122, guest PC 0x0c09c824 */
if(!s->budget--) { s->failed_pc=0x0c09c824u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c826;
P_0c09c826: /* original 2118, guest PC 0x0c09c826 */
if(!s->budget--) { s->failed_pc=0x0c09c826u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c09c828;
P_0c09c828: /* original 8b19, guest PC 0x0c09c828 */
if(!s->budget--) { s->failed_pc=0x0c09c828u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c85e; }
goto P_0c09c82a;
P_0c09c82a: /* original 4a0b, guest PC 0x0c09c82a */
if(!s->budget--) { s->failed_pc=0x0c09c82au; return 0; }
target=r[10];
r[16]=code_base|0x0c09c82eu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c82eu) { target=s->pc; goto dispatch; }
goto P_0c09c82e;
P_0c09c82c: /* original 64b3, guest PC 0x0c09c82c */
if(!s->budget--) { s->failed_pc=0x0c09c82cu; return 0; }
r[4]=r[11];
goto P_0c09c82e;
P_0c09c82e: /* original 9241, guest PC 0x0c09c82e */
if(!s->budget--) { s->failed_pc=0x0c09c82eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b4u,2);
goto P_0c09c830;
P_0c09c830: /* original 64e3, guest PC 0x0c09c830 */
if(!s->budget--) { s->failed_pc=0x0c09c830u; return 0; }
r[4]=r[14];
goto P_0c09c832;
P_0c09c832: /* original 4408, guest PC 0x0c09c832 */
if(!s->budget--) { s->failed_pc=0x0c09c832u; return 0; }
r[4]<<=2;
goto P_0c09c834;
P_0c09c834: /* original 933d, guest PC 0x0c09c834 */
if(!s->budget--) { s->failed_pc=0x0c09c834u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b2u,2);
goto P_0c09c836;
P_0c09c836: /* original 32dc, guest PC 0x0c09c836 */
if(!s->budget--) { s->failed_pc=0x0c09c836u; return 0; }
r[2]+=r[13];
goto P_0c09c838;
P_0c09c838: /* original 324c, guest PC 0x0c09c838 */
if(!s->budget--) { s->failed_pc=0x0c09c838u; return 0; }
r[2]+=r[4];
goto P_0c09c83a;
P_0c09c83a: /* original 33dc, guest PC 0x0c09c83a */
if(!s->budget--) { s->failed_pc=0x0c09c83au; return 0; }
r[3]+=r[13];
goto P_0c09c83c;
P_0c09c83c: /* original 6122, guest PC 0x0c09c83c */
if(!s->budget--) { s->failed_pc=0x0c09c83cu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c83e;
P_0c09c83e: /* original 334c, guest PC 0x0c09c83e */
if(!s->budget--) { s->failed_pc=0x0c09c83eu; return 0; }
r[3]+=r[4];
goto P_0c09c840;
P_0c09c840: /* original 2312, guest PC 0x0c09c840 */
if(!s->budget--) { s->failed_pc=0x0c09c840u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c842;
P_0c09c842: /* original 9337, guest PC 0x0c09c842 */
if(!s->budget--) { s->failed_pc=0x0c09c842u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b4u,2);
goto P_0c09c844;
P_0c09c844: /* original 33dc, guest PC 0x0c09c844 */
if(!s->budget--) { s->failed_pc=0x0c09c844u; return 0; }
r[3]+=r[13];
goto P_0c09c846;
P_0c09c846: /* original 334c, guest PC 0x0c09c846 */
if(!s->budget--) { s->failed_pc=0x0c09c846u; return 0; }
r[3]+=r[4];
goto P_0c09c848;
P_0c09c848: /* original 6232, guest PC 0x0c09c848 */
if(!s->budget--) { s->failed_pc=0x0c09c848u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c09c84a;
P_0c09c84a: /* original 7201, guest PC 0x0c09c84a */
if(!s->budget--) { s->failed_pc=0x0c09c84au; return 0; }
r[2]+=0x00000001u;
goto P_0c09c84c;
P_0c09c84c: /* original 2322, guest PC 0x0c09c84c */
if(!s->budget--) { s->failed_pc=0x0c09c84cu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c09c84e;
P_0c09c84e: /* original 9331, guest PC 0x0c09c84e */
if(!s->budget--) { s->failed_pc=0x0c09c84eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b4u,2);
goto P_0c09c850;
P_0c09c850: /* original 33dc, guest PC 0x0c09c850 */
if(!s->budget--) { s->failed_pc=0x0c09c850u; return 0; }
r[3]+=r[13];
goto P_0c09c852;
P_0c09c852: /* original 343c, guest PC 0x0c09c852 */
if(!s->budget--) { s->failed_pc=0x0c09c852u; return 0; }
r[4]+=r[3];
goto P_0c09c854;
P_0c09c854: /* original 6242, guest PC 0x0c09c854 */
if(!s->budget--) { s->failed_pc=0x0c09c854u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09c856;
P_0c09c856: /* original 32c7, guest PC 0x0c09c856 */
if(!s->budget--) { s->failed_pc=0x0c09c856u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[12])!=0);
goto P_0c09c858;
P_0c09c858: /* original 8922, guest PC 0x0c09c858 */
if(!s->budget--) { s->failed_pc=0x0c09c858u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c8a0; }
goto P_0c09c85a;
P_0c09c85a: /* original a0cc, guest PC 0x0c09c85a */
if(!s->budget--) { s->failed_pc=0x0c09c85au; return 0; }
goto P_0c09c9f6;
P_0c09c85c: /* original 0009, guest PC 0x0c09c85c */
if(!s->budget--) { s->failed_pc=0x0c09c85cu; return 0; }
goto P_0c09c85e;
P_0c09c85e: /* original 9327, guest PC 0x0c09c85e */
if(!s->budget--) { s->failed_pc=0x0c09c85eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b0u,2);
goto P_0c09c860;
P_0c09c860: /* original 60e3, guest PC 0x0c09c860 */
if(!s->budget--) { s->failed_pc=0x0c09c860u; return 0; }
r[0]=r[14];
goto P_0c09c862;
P_0c09c862: /* original 4008, guest PC 0x0c09c862 */
if(!s->budget--) { s->failed_pc=0x0c09c862u; return 0; }
r[0]<<=2;
goto P_0c09c864;
P_0c09c864: /* original 33dc, guest PC 0x0c09c864 */
if(!s->budget--) { s->failed_pc=0x0c09c864u; return 0; }
r[3]+=r[13];
goto P_0c09c866;
P_0c09c866: /* original 003e, guest PC 0x0c09c866 */
if(!s->budget--) { s->failed_pc=0x0c09c866u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c868;
P_0c09c868: /* original 8809, guest PC 0x0c09c868 */
if(!s->budget--) { s->failed_pc=0x0c09c868u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c09c86a;
P_0c09c86a: /* original 8b24, guest PC 0x0c09c86a */
if(!s->budget--) { s->failed_pc=0x0c09c86au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c8b6; }
goto P_0c09c86c;
P_0c09c86c: /* original 4a0b, guest PC 0x0c09c86c */
if(!s->budget--) { s->failed_pc=0x0c09c86cu; return 0; }
target=r[10];
r[16]=code_base|0x0c09c870u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c870u) { target=s->pc; goto dispatch; }
goto P_0c09c870;
P_0c09c86e: /* original 64b3, guest PC 0x0c09c86e */
if(!s->budget--) { s->failed_pc=0x0c09c86eu; return 0; }
r[4]=r[11];
goto P_0c09c870;
P_0c09c870: /* original 9220, guest PC 0x0c09c870 */
if(!s->budget--) { s->failed_pc=0x0c09c870u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b4u,2);
goto P_0c09c872;
P_0c09c872: /* original 64e3, guest PC 0x0c09c872 */
if(!s->budget--) { s->failed_pc=0x0c09c872u; return 0; }
r[4]=r[14];
goto P_0c09c874;
P_0c09c874: /* original 4408, guest PC 0x0c09c874 */
if(!s->budget--) { s->failed_pc=0x0c09c874u; return 0; }
r[4]<<=2;
goto P_0c09c876;
P_0c09c876: /* original 931c, guest PC 0x0c09c876 */
if(!s->budget--) { s->failed_pc=0x0c09c876u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b2u,2);
goto P_0c09c878;
P_0c09c878: /* original 32dc, guest PC 0x0c09c878 */
if(!s->budget--) { s->failed_pc=0x0c09c878u; return 0; }
r[2]+=r[13];
goto P_0c09c87a;
P_0c09c87a: /* original 324c, guest PC 0x0c09c87a */
if(!s->budget--) { s->failed_pc=0x0c09c87au; return 0; }
r[2]+=r[4];
goto P_0c09c87c;
P_0c09c87c: /* original 33dc, guest PC 0x0c09c87c */
if(!s->budget--) { s->failed_pc=0x0c09c87cu; return 0; }
r[3]+=r[13];
goto P_0c09c87e;
P_0c09c87e: /* original 6122, guest PC 0x0c09c87e */
if(!s->budget--) { s->failed_pc=0x0c09c87eu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c880;
P_0c09c880: /* original 334c, guest PC 0x0c09c880 */
if(!s->budget--) { s->failed_pc=0x0c09c880u; return 0; }
r[3]+=r[4];
goto P_0c09c882;
P_0c09c882: /* original 2312, guest PC 0x0c09c882 */
if(!s->budget--) { s->failed_pc=0x0c09c882u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c09c884;
P_0c09c884: /* original 9316, guest PC 0x0c09c884 */
if(!s->budget--) { s->failed_pc=0x0c09c884u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b4u,2);
goto P_0c09c886;
P_0c09c886: /* original 33dc, guest PC 0x0c09c886 */
if(!s->budget--) { s->failed_pc=0x0c09c886u; return 0; }
r[3]+=r[13];
goto P_0c09c888;
P_0c09c888: /* original 334c, guest PC 0x0c09c888 */
if(!s->budget--) { s->failed_pc=0x0c09c888u; return 0; }
r[3]+=r[4];
goto P_0c09c88a;
P_0c09c88a: /* original 6232, guest PC 0x0c09c88a */
if(!s->budget--) { s->failed_pc=0x0c09c88au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c09c88c;
P_0c09c88c: /* original 7201, guest PC 0x0c09c88c */
if(!s->budget--) { s->failed_pc=0x0c09c88cu; return 0; }
r[2]+=0x00000001u;
goto P_0c09c88e;
P_0c09c88e: /* original 2322, guest PC 0x0c09c88e */
if(!s->budget--) { s->failed_pc=0x0c09c88eu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c09c890;
P_0c09c890: /* original 9310, guest PC 0x0c09c890 */
if(!s->budget--) { s->failed_pc=0x0c09c890u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b4u,2);
goto P_0c09c892;
P_0c09c892: /* original 33dc, guest PC 0x0c09c892 */
if(!s->budget--) { s->failed_pc=0x0c09c892u; return 0; }
r[3]+=r[13];
goto P_0c09c894;
P_0c09c894: /* original 343c, guest PC 0x0c09c894 */
if(!s->budget--) { s->failed_pc=0x0c09c894u; return 0; }
r[4]+=r[3];
goto P_0c09c896;
P_0c09c896: /* original 6242, guest PC 0x0c09c896 */
if(!s->budget--) { s->failed_pc=0x0c09c896u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09c898;
P_0c09c898: /* original 32c7, guest PC 0x0c09c898 */
if(!s->budget--) { s->failed_pc=0x0c09c898u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[12])!=0);
goto P_0c09c89a;
P_0c09c89a: /* original 8901, guest PC 0x0c09c89a */
if(!s->budget--) { s->failed_pc=0x0c09c89au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c8a0; }
goto P_0c09c89c;
P_0c09c89c: /* original a0ab, guest PC 0x0c09c89c */
if(!s->budget--) { s->failed_pc=0x0c09c89cu; return 0; }
goto P_0c09c9f6;
P_0c09c89e: /* original 0009, guest PC 0x0c09c89e */
if(!s->budget--) { s->failed_pc=0x0c09c89eu; return 0; }
goto P_0c09c8a0;
P_0c09c8a0: /* original 9308, guest PC 0x0c09c8a0 */
if(!s->budget--) { s->failed_pc=0x0c09c8a0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c8b4u,2);
goto P_0c09c8a2;
P_0c09c8a2: /* original 61e3, guest PC 0x0c09c8a2 */
if(!s->budget--) { s->failed_pc=0x0c09c8a2u; return 0; }
r[1]=r[14];
goto P_0c09c8a4;
P_0c09c8a4: /* original 4108, guest PC 0x0c09c8a4 */
if(!s->budget--) { s->failed_pc=0x0c09c8a4u; return 0; }
r[1]<<=2;
goto P_0c09c8a6;
P_0c09c8a6: /* original 33dc, guest PC 0x0c09c8a6 */
if(!s->budget--) { s->failed_pc=0x0c09c8a6u; return 0; }
r[3]+=r[13];
goto P_0c09c8a8;
P_0c09c8a8: /* original 313c, guest PC 0x0c09c8a8 */
if(!s->budget--) { s->failed_pc=0x0c09c8a8u; return 0; }
r[1]+=r[3];
goto P_0c09c8aa;
P_0c09c8aa: /* original a0a4, guest PC 0x0c09c8aa */
if(!s->budget--) { s->failed_pc=0x0c09c8aau; return 0; }
write(ram,r[1],r[9],4);
goto P_0c09c9f6;
P_0c09c8ac: /* original 2192, guest PC 0x0c09c8ac */
if(!s->budget--) { s->failed_pc=0x0c09c8acu; return 0; }
write(ram,r[1],r[9],4);
if(!vf3_matrix_family(0x0c09c8aeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09c8aeu; return 0; } return 1;
P_0c09c8b6: /* original 4a0b, guest PC 0x0c09c8b6 */
if(!s->budget--) { s->failed_pc=0x0c09c8b6u; return 0; }
target=r[10];
r[16]=code_base|0x0c09c8bau;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09c8bau) { target=s->pc; goto dispatch; }
goto P_0c09c8ba;
P_0c09c8b8: /* original 64b3, guest PC 0x0c09c8b8 */
if(!s->budget--) { s->failed_pc=0x0c09c8b8u; return 0; }
r[4]=r[11];
goto P_0c09c8ba;
P_0c09c8ba: /* original 60e3, guest PC 0x0c09c8ba */
if(!s->budget--) { s->failed_pc=0x0c09c8bau; return 0; }
r[0]=r[14];
goto P_0c09c8bc;
P_0c09c8bc: /* original 933f, guest PC 0x0c09c8bc */
if(!s->budget--) { s->failed_pc=0x0c09c8bcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c93eu,2);
goto P_0c09c8be;
P_0c09c8be: /* original 4008, guest PC 0x0c09c8be */
if(!s->budget--) { s->failed_pc=0x0c09c8beu; return 0; }
r[0]<<=2;
goto P_0c09c8c0;
P_0c09c8c0: /* original 62e3, guest PC 0x0c09c8c0 */
if(!s->budget--) { s->failed_pc=0x0c09c8c0u; return 0; }
r[2]=r[14];
goto P_0c09c8c2;
P_0c09c8c2: /* original 4008, guest PC 0x0c09c8c2 */
if(!s->budget--) { s->failed_pc=0x0c09c8c2u; return 0; }
r[0]<<=2;
goto P_0c09c8c4;
P_0c09c8c4: /* original 33dc, guest PC 0x0c09c8c4 */
if(!s->budget--) { s->failed_pc=0x0c09c8c4u; return 0; }
r[3]+=r[13];
goto P_0c09c8c6;
P_0c09c8c6: /* original 4008, guest PC 0x0c09c8c6 */
if(!s->budget--) { s->failed_pc=0x0c09c8c6u; return 0; }
r[0]<<=2;
goto P_0c09c8c8;
P_0c09c8c8: /* original 303c, guest PC 0x0c09c8c8 */
if(!s->budget--) { s->failed_pc=0x0c09c8c8u; return 0; }
r[0]+=r[3];
goto P_0c09c8ca;
P_0c09c8ca: /* original 9339, guest PC 0x0c09c8ca */
if(!s->budget--) { s->failed_pc=0x0c09c8cau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c940u,2);
goto P_0c09c8cc;
P_0c09c8cc: /* original 4208, guest PC 0x0c09c8cc */
if(!s->budget--) { s->failed_pc=0x0c09c8ccu; return 0; }
r[2]<<=2;
goto P_0c09c8ce;
P_0c09c8ce: /* original 33dc, guest PC 0x0c09c8ce */
if(!s->budget--) { s->failed_pc=0x0c09c8ceu; return 0; }
r[3]+=r[13];
goto P_0c09c8d0;
P_0c09c8d0: /* original 323c, guest PC 0x0c09c8d0 */
if(!s->budget--) { s->failed_pc=0x0c09c8d0u; return 0; }
r[2]+=r[3];
goto P_0c09c8d2;
P_0c09c8d2: /* original 6122, guest PC 0x0c09c8d2 */
if(!s->budget--) { s->failed_pc=0x0c09c8d2u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c8d4;
P_0c09c8d4: /* original 4108, guest PC 0x0c09c8d4 */
if(!s->budget--) { s->failed_pc=0x0c09c8d4u; return 0; }
r[1]<<=2;
goto P_0c09c8d6;
P_0c09c8d6: /* original 031e, guest PC 0x0c09c8d6 */
if(!s->budget--) { s->failed_pc=0x0c09c8d6u; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c09c8d8;
P_0c09c8d8: /* original 2338, guest PC 0x0c09c8d8 */
if(!s->budget--) { s->failed_pc=0x0c09c8d8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09c8da;
P_0c09c8da: /* original 8b0f, guest PC 0x0c09c8da */
if(!s->budget--) { s->failed_pc=0x0c09c8dau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c8fc; }
goto P_0c09c8dc;
P_0c09c8dc: /* original 60e3, guest PC 0x0c09c8dc */
if(!s->budget--) { s->failed_pc=0x0c09c8dcu; return 0; }
r[0]=r[14];
goto P_0c09c8de;
P_0c09c8de: /* original 932e, guest PC 0x0c09c8de */
if(!s->budget--) { s->failed_pc=0x0c09c8deu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c93eu,2);
goto P_0c09c8e0;
P_0c09c8e0: /* original 4008, guest PC 0x0c09c8e0 */
if(!s->budget--) { s->failed_pc=0x0c09c8e0u; return 0; }
r[0]<<=2;
goto P_0c09c8e2;
P_0c09c8e2: /* original 62e3, guest PC 0x0c09c8e2 */
if(!s->budget--) { s->failed_pc=0x0c09c8e2u; return 0; }
r[2]=r[14];
goto P_0c09c8e4;
P_0c09c8e4: /* original 4008, guest PC 0x0c09c8e4 */
if(!s->budget--) { s->failed_pc=0x0c09c8e4u; return 0; }
r[0]<<=2;
goto P_0c09c8e6;
P_0c09c8e6: /* original 33dc, guest PC 0x0c09c8e6 */
if(!s->budget--) { s->failed_pc=0x0c09c8e6u; return 0; }
r[3]+=r[13];
goto P_0c09c8e8;
P_0c09c8e8: /* original 4008, guest PC 0x0c09c8e8 */
if(!s->budget--) { s->failed_pc=0x0c09c8e8u; return 0; }
r[0]<<=2;
goto P_0c09c8ea;
P_0c09c8ea: /* original 303c, guest PC 0x0c09c8ea */
if(!s->budget--) { s->failed_pc=0x0c09c8eau; return 0; }
r[0]+=r[3];
goto P_0c09c8ec;
P_0c09c8ec: /* original 9328, guest PC 0x0c09c8ec */
if(!s->budget--) { s->failed_pc=0x0c09c8ecu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c940u,2);
goto P_0c09c8ee;
P_0c09c8ee: /* original 4208, guest PC 0x0c09c8ee */
if(!s->budget--) { s->failed_pc=0x0c09c8eeu; return 0; }
r[2]<<=2;
goto P_0c09c8f0;
P_0c09c8f0: /* original 33dc, guest PC 0x0c09c8f0 */
if(!s->budget--) { s->failed_pc=0x0c09c8f0u; return 0; }
r[3]+=r[13];
goto P_0c09c8f2;
P_0c09c8f2: /* original 323c, guest PC 0x0c09c8f2 */
if(!s->budget--) { s->failed_pc=0x0c09c8f2u; return 0; }
r[2]+=r[3];
goto P_0c09c8f4;
P_0c09c8f4: /* original 6122, guest PC 0x0c09c8f4 */
if(!s->budget--) { s->failed_pc=0x0c09c8f4u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c8f6;
P_0c09c8f6: /* original 4108, guest PC 0x0c09c8f6 */
if(!s->budget--) { s->failed_pc=0x0c09c8f6u; return 0; }
r[1]<<=2;
goto P_0c09c8f8;
P_0c09c8f8: /* original a035, guest PC 0x0c09c8f8 */
if(!s->budget--) { s->failed_pc=0x0c09c8f8u; return 0; }
write(ram,r[1]+r[0],r[8],4);
goto P_0c09c966;
P_0c09c8fa: /* original 0186, guest PC 0x0c09c8fa */
if(!s->budget--) { s->failed_pc=0x0c09c8fau; return 0; }
write(ram,r[1]+r[0],r[8],4);
goto P_0c09c8fc;
P_0c09c8fc: /* original 60e3, guest PC 0x0c09c8fc */
if(!s->budget--) { s->failed_pc=0x0c09c8fcu; return 0; }
r[0]=r[14];
goto P_0c09c8fe;
P_0c09c8fe: /* original 931e, guest PC 0x0c09c8fe */
if(!s->budget--) { s->failed_pc=0x0c09c8feu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c93eu,2);
goto P_0c09c900;
P_0c09c900: /* original 4008, guest PC 0x0c09c900 */
if(!s->budget--) { s->failed_pc=0x0c09c900u; return 0; }
r[0]<<=2;
goto P_0c09c902;
P_0c09c902: /* original 62e3, guest PC 0x0c09c902 */
if(!s->budget--) { s->failed_pc=0x0c09c902u; return 0; }
r[2]=r[14];
goto P_0c09c904;
P_0c09c904: /* original 4008, guest PC 0x0c09c904 */
if(!s->budget--) { s->failed_pc=0x0c09c904u; return 0; }
r[0]<<=2;
goto P_0c09c906;
P_0c09c906: /* original 33dc, guest PC 0x0c09c906 */
if(!s->budget--) { s->failed_pc=0x0c09c906u; return 0; }
r[3]+=r[13];
goto P_0c09c908;
P_0c09c908: /* original 4008, guest PC 0x0c09c908 */
if(!s->budget--) { s->failed_pc=0x0c09c908u; return 0; }
r[0]<<=2;
goto P_0c09c90a;
P_0c09c90a: /* original 303c, guest PC 0x0c09c90a */
if(!s->budget--) { s->failed_pc=0x0c09c90au; return 0; }
r[0]+=r[3];
goto P_0c09c90c;
P_0c09c90c: /* original 9318, guest PC 0x0c09c90c */
if(!s->budget--) { s->failed_pc=0x0c09c90cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c940u,2);
goto P_0c09c90e;
P_0c09c90e: /* original 4208, guest PC 0x0c09c90e */
if(!s->budget--) { s->failed_pc=0x0c09c90eu; return 0; }
r[2]<<=2;
goto P_0c09c910;
P_0c09c910: /* original 33dc, guest PC 0x0c09c910 */
if(!s->budget--) { s->failed_pc=0x0c09c910u; return 0; }
r[3]+=r[13];
goto P_0c09c912;
P_0c09c912: /* original 323c, guest PC 0x0c09c912 */
if(!s->budget--) { s->failed_pc=0x0c09c912u; return 0; }
r[2]+=r[3];
goto P_0c09c914;
P_0c09c914: /* original 6122, guest PC 0x0c09c914 */
if(!s->budget--) { s->failed_pc=0x0c09c914u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c916;
P_0c09c916: /* original 4108, guest PC 0x0c09c916 */
if(!s->budget--) { s->failed_pc=0x0c09c916u; return 0; }
r[1]<<=2;
goto P_0c09c918;
P_0c09c918: /* original 001e, guest PC 0x0c09c918 */
if(!s->budget--) { s->failed_pc=0x0c09c918u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c09c91a;
P_0c09c91a: /* original 8801, guest PC 0x0c09c91a */
if(!s->budget--) { s->failed_pc=0x0c09c91au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09c91c;
P_0c09c91c: /* original 8b11, guest PC 0x0c09c91c */
if(!s->budget--) { s->failed_pc=0x0c09c91cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c942; }
goto P_0c09c91e;
P_0c09c91e: /* original 60e3, guest PC 0x0c09c91e */
if(!s->budget--) { s->failed_pc=0x0c09c91eu; return 0; }
r[0]=r[14];
goto P_0c09c920;
P_0c09c920: /* original 930d, guest PC 0x0c09c920 */
if(!s->budget--) { s->failed_pc=0x0c09c920u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c93eu,2);
goto P_0c09c922;
P_0c09c922: /* original 4008, guest PC 0x0c09c922 */
if(!s->budget--) { s->failed_pc=0x0c09c922u; return 0; }
r[0]<<=2;
goto P_0c09c924;
P_0c09c924: /* original 62e3, guest PC 0x0c09c924 */
if(!s->budget--) { s->failed_pc=0x0c09c924u; return 0; }
r[2]=r[14];
goto P_0c09c926;
P_0c09c926: /* original 4008, guest PC 0x0c09c926 */
if(!s->budget--) { s->failed_pc=0x0c09c926u; return 0; }
r[0]<<=2;
goto P_0c09c928;
P_0c09c928: /* original 33dc, guest PC 0x0c09c928 */
if(!s->budget--) { s->failed_pc=0x0c09c928u; return 0; }
r[3]+=r[13];
goto P_0c09c92a;
P_0c09c92a: /* original 4008, guest PC 0x0c09c92a */
if(!s->budget--) { s->failed_pc=0x0c09c92au; return 0; }
r[0]<<=2;
goto P_0c09c92c;
P_0c09c92c: /* original 303c, guest PC 0x0c09c92c */
if(!s->budget--) { s->failed_pc=0x0c09c92cu; return 0; }
r[0]+=r[3];
goto P_0c09c92e;
P_0c09c92e: /* original 9307, guest PC 0x0c09c92e */
if(!s->budget--) { s->failed_pc=0x0c09c92eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c940u,2);
goto P_0c09c930;
P_0c09c930: /* original 4208, guest PC 0x0c09c930 */
if(!s->budget--) { s->failed_pc=0x0c09c930u; return 0; }
r[2]<<=2;
goto P_0c09c932;
P_0c09c932: /* original 33dc, guest PC 0x0c09c932 */
if(!s->budget--) { s->failed_pc=0x0c09c932u; return 0; }
r[3]+=r[13];
goto P_0c09c934;
P_0c09c934: /* original 323c, guest PC 0x0c09c934 */
if(!s->budget--) { s->failed_pc=0x0c09c934u; return 0; }
r[2]+=r[3];
goto P_0c09c936;
P_0c09c936: /* original 6122, guest PC 0x0c09c936 */
if(!s->budget--) { s->failed_pc=0x0c09c936u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c938;
P_0c09c938: /* original 4108, guest PC 0x0c09c938 */
if(!s->budget--) { s->failed_pc=0x0c09c938u; return 0; }
r[1]<<=2;
goto P_0c09c93a;
P_0c09c93a: /* original a014, guest PC 0x0c09c93a */
if(!s->budget--) { s->failed_pc=0x0c09c93au; return 0; }
write(ram,r[1]+r[0],r[9],4);
goto P_0c09c966;
P_0c09c93c: /* original 0196, guest PC 0x0c09c93c */
if(!s->budget--) { s->failed_pc=0x0c09c93cu; return 0; }
write(ram,r[1]+r[0],r[9],4);
if(!vf3_matrix_family(0x0c09c93eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09c93eu; return 0; } return 1;
P_0c09c942: /* original 64e3, guest PC 0x0c09c942 */
if(!s->budget--) { s->failed_pc=0x0c09c942u; return 0; }
r[4]=r[14];
goto P_0c09c944;
P_0c09c944: /* original 937b, guest PC 0x0c09c944 */
if(!s->budget--) { s->failed_pc=0x0c09c944u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca3eu,2);
goto P_0c09c946;
P_0c09c946: /* original 4408, guest PC 0x0c09c946 */
if(!s->budget--) { s->failed_pc=0x0c09c946u; return 0; }
r[4]<<=2;
goto P_0c09c948;
P_0c09c948: /* original 62e3, guest PC 0x0c09c948 */
if(!s->budget--) { s->failed_pc=0x0c09c948u; return 0; }
r[2]=r[14];
goto P_0c09c94a;
P_0c09c94a: /* original 4408, guest PC 0x0c09c94a */
if(!s->budget--) { s->failed_pc=0x0c09c94au; return 0; }
r[4]<<=2;
goto P_0c09c94c;
P_0c09c94c: /* original 33dc, guest PC 0x0c09c94c */
if(!s->budget--) { s->failed_pc=0x0c09c94cu; return 0; }
r[3]+=r[13];
goto P_0c09c94e;
P_0c09c94e: /* original 4408, guest PC 0x0c09c94e */
if(!s->budget--) { s->failed_pc=0x0c09c94eu; return 0; }
r[4]<<=2;
goto P_0c09c950;
P_0c09c950: /* original 343c, guest PC 0x0c09c950 */
if(!s->budget--) { s->failed_pc=0x0c09c950u; return 0; }
r[4]+=r[3];
goto P_0c09c952;
P_0c09c952: /* original 9375, guest PC 0x0c09c952 */
if(!s->budget--) { s->failed_pc=0x0c09c952u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca40u,2);
goto P_0c09c954;
P_0c09c954: /* original 4208, guest PC 0x0c09c954 */
if(!s->budget--) { s->failed_pc=0x0c09c954u; return 0; }
r[2]<<=2;
goto P_0c09c956;
P_0c09c956: /* original 33dc, guest PC 0x0c09c956 */
if(!s->budget--) { s->failed_pc=0x0c09c956u; return 0; }
r[3]+=r[13];
goto P_0c09c958;
P_0c09c958: /* original 323c, guest PC 0x0c09c958 */
if(!s->budget--) { s->failed_pc=0x0c09c958u; return 0; }
r[2]+=r[3];
goto P_0c09c95a;
P_0c09c95a: /* original 6122, guest PC 0x0c09c95a */
if(!s->budget--) { s->failed_pc=0x0c09c95au; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c95c;
P_0c09c95c: /* original 4108, guest PC 0x0c09c95c */
if(!s->budget--) { s->failed_pc=0x0c09c95cu; return 0; }
r[1]<<=2;
goto P_0c09c95e;
P_0c09c95e: /* original 341c, guest PC 0x0c09c95e */
if(!s->budget--) { s->failed_pc=0x0c09c95eu; return 0; }
r[4]+=r[1];
goto P_0c09c960;
P_0c09c960: /* original 6342, guest PC 0x0c09c960 */
if(!s->budget--) { s->failed_pc=0x0c09c960u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c09c962;
P_0c09c962: /* original 4321, guest PC 0x0c09c962 */
if(!s->budget--) { s->failed_pc=0x0c09c962u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c09c964;
P_0c09c964: /* original 2432, guest PC 0x0c09c964 */
if(!s->budget--) { s->failed_pc=0x0c09c964u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c09c966;
P_0c09c966: /* original 936b, guest PC 0x0c09c966 */
if(!s->budget--) { s->failed_pc=0x0c09c966u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca40u,2);
goto P_0c09c968;
P_0c09c968: /* original 60e3, guest PC 0x0c09c968 */
if(!s->budget--) { s->failed_pc=0x0c09c968u; return 0; }
r[0]=r[14];
goto P_0c09c96a;
P_0c09c96a: /* original 4008, guest PC 0x0c09c96a */
if(!s->budget--) { s->failed_pc=0x0c09c96au; return 0; }
r[0]<<=2;
goto P_0c09c96c;
P_0c09c96c: /* original 33dc, guest PC 0x0c09c96c */
if(!s->budget--) { s->failed_pc=0x0c09c96cu; return 0; }
r[3]+=r[13];
goto P_0c09c96e;
P_0c09c96e: /* original 003e, guest PC 0x0c09c96e */
if(!s->budget--) { s->failed_pc=0x0c09c96eu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c09c970;
P_0c09c970: /* original 8801, guest PC 0x0c09c970 */
if(!s->budget--) { s->failed_pc=0x0c09c970u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09c972;
P_0c09c972: /* original 8b40, guest PC 0x0c09c972 */
if(!s->budget--) { s->failed_pc=0x0c09c972u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c9f6; }
goto P_0c09c974;
P_0c09c974: /* original 60e3, guest PC 0x0c09c974 */
if(!s->budget--) { s->failed_pc=0x0c09c974u; return 0; }
r[0]=r[14];
goto P_0c09c976;
P_0c09c976: /* original 9362, guest PC 0x0c09c976 */
if(!s->budget--) { s->failed_pc=0x0c09c976u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca3eu,2);
goto P_0c09c978;
P_0c09c978: /* original 4008, guest PC 0x0c09c978 */
if(!s->budget--) { s->failed_pc=0x0c09c978u; return 0; }
r[0]<<=2;
goto P_0c09c97a;
P_0c09c97a: /* original 62e3, guest PC 0x0c09c97a */
if(!s->budget--) { s->failed_pc=0x0c09c97au; return 0; }
r[2]=r[14];
goto P_0c09c97c;
P_0c09c97c: /* original 4008, guest PC 0x0c09c97c */
if(!s->budget--) { s->failed_pc=0x0c09c97cu; return 0; }
r[0]<<=2;
goto P_0c09c97e;
P_0c09c97e: /* original 33dc, guest PC 0x0c09c97e */
if(!s->budget--) { s->failed_pc=0x0c09c97eu; return 0; }
r[3]+=r[13];
goto P_0c09c980;
P_0c09c980: /* original 4008, guest PC 0x0c09c980 */
if(!s->budget--) { s->failed_pc=0x0c09c980u; return 0; }
r[0]<<=2;
goto P_0c09c982;
P_0c09c982: /* original 303c, guest PC 0x0c09c982 */
if(!s->budget--) { s->failed_pc=0x0c09c982u; return 0; }
r[0]+=r[3];
goto P_0c09c984;
P_0c09c984: /* original 935c, guest PC 0x0c09c984 */
if(!s->budget--) { s->failed_pc=0x0c09c984u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca40u,2);
goto P_0c09c986;
P_0c09c986: /* original 4208, guest PC 0x0c09c986 */
if(!s->budget--) { s->failed_pc=0x0c09c986u; return 0; }
r[2]<<=2;
goto P_0c09c988;
P_0c09c988: /* original 33dc, guest PC 0x0c09c988 */
if(!s->budget--) { s->failed_pc=0x0c09c988u; return 0; }
r[3]+=r[13];
goto P_0c09c98a;
P_0c09c98a: /* original 323c, guest PC 0x0c09c98a */
if(!s->budget--) { s->failed_pc=0x0c09c98au; return 0; }
r[2]+=r[3];
goto P_0c09c98c;
P_0c09c98c: /* original 6122, guest PC 0x0c09c98c */
if(!s->budget--) { s->failed_pc=0x0c09c98cu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c98e;
P_0c09c98e: /* original 4108, guest PC 0x0c09c98e */
if(!s->budget--) { s->failed_pc=0x0c09c98eu; return 0; }
r[1]<<=2;
goto P_0c09c990;
P_0c09c990: /* original 001e, guest PC 0x0c09c990 */
if(!s->budget--) { s->failed_pc=0x0c09c990u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c09c992;
P_0c09c992: /* original 8810, guest PC 0x0c09c992 */
if(!s->budget--) { s->failed_pc=0x0c09c992u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c09c994;
P_0c09c994: /* original 8b0f, guest PC 0x0c09c994 */
if(!s->budget--) { s->failed_pc=0x0c09c994u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c9b6; }
goto P_0c09c996;
P_0c09c996: /* original 60e3, guest PC 0x0c09c996 */
if(!s->budget--) { s->failed_pc=0x0c09c996u; return 0; }
r[0]=r[14];
goto P_0c09c998;
P_0c09c998: /* original 9351, guest PC 0x0c09c998 */
if(!s->budget--) { s->failed_pc=0x0c09c998u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca3eu,2);
goto P_0c09c99a;
P_0c09c99a: /* original 4008, guest PC 0x0c09c99a */
if(!s->budget--) { s->failed_pc=0x0c09c99au; return 0; }
r[0]<<=2;
goto P_0c09c99c;
P_0c09c99c: /* original 62e3, guest PC 0x0c09c99c */
if(!s->budget--) { s->failed_pc=0x0c09c99cu; return 0; }
r[2]=r[14];
goto P_0c09c99e;
P_0c09c99e: /* original 4008, guest PC 0x0c09c99e */
if(!s->budget--) { s->failed_pc=0x0c09c99eu; return 0; }
r[0]<<=2;
goto P_0c09c9a0;
P_0c09c9a0: /* original 33dc, guest PC 0x0c09c9a0 */
if(!s->budget--) { s->failed_pc=0x0c09c9a0u; return 0; }
r[3]+=r[13];
goto P_0c09c9a2;
P_0c09c9a2: /* original 4008, guest PC 0x0c09c9a2 */
if(!s->budget--) { s->failed_pc=0x0c09c9a2u; return 0; }
r[0]<<=2;
goto P_0c09c9a4;
P_0c09c9a4: /* original 303c, guest PC 0x0c09c9a4 */
if(!s->budget--) { s->failed_pc=0x0c09c9a4u; return 0; }
r[0]+=r[3];
goto P_0c09c9a6;
P_0c09c9a6: /* original 934b, guest PC 0x0c09c9a6 */
if(!s->budget--) { s->failed_pc=0x0c09c9a6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca40u,2);
goto P_0c09c9a8;
P_0c09c9a8: /* original 4208, guest PC 0x0c09c9a8 */
if(!s->budget--) { s->failed_pc=0x0c09c9a8u; return 0; }
r[2]<<=2;
goto P_0c09c9aa;
P_0c09c9aa: /* original 33dc, guest PC 0x0c09c9aa */
if(!s->budget--) { s->failed_pc=0x0c09c9aau; return 0; }
r[3]+=r[13];
goto P_0c09c9ac;
P_0c09c9ac: /* original 323c, guest PC 0x0c09c9ac */
if(!s->budget--) { s->failed_pc=0x0c09c9acu; return 0; }
r[2]+=r[3];
goto P_0c09c9ae;
P_0c09c9ae: /* original 6122, guest PC 0x0c09c9ae */
if(!s->budget--) { s->failed_pc=0x0c09c9aeu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c9b0;
P_0c09c9b0: /* original e308, guest PC 0x0c09c9b0 */
if(!s->budget--) { s->failed_pc=0x0c09c9b0u; return 0; }
r[3]=0x00000008u;
goto P_0c09c9b2;
P_0c09c9b2: /* original 4108, guest PC 0x0c09c9b2 */
if(!s->budget--) { s->failed_pc=0x0c09c9b2u; return 0; }
r[1]<<=2;
goto P_0c09c9b4;
P_0c09c9b4: /* original 0136, guest PC 0x0c09c9b4 */
if(!s->budget--) { s->failed_pc=0x0c09c9b4u; return 0; }
write(ram,r[1]+r[0],r[3],4);
goto P_0c09c9b6;
P_0c09c9b6: /* original 60e3, guest PC 0x0c09c9b6 */
if(!s->budget--) { s->failed_pc=0x0c09c9b6u; return 0; }
r[0]=r[14];
goto P_0c09c9b8;
P_0c09c9b8: /* original 9341, guest PC 0x0c09c9b8 */
if(!s->budget--) { s->failed_pc=0x0c09c9b8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca3eu,2);
goto P_0c09c9ba;
P_0c09c9ba: /* original 4008, guest PC 0x0c09c9ba */
if(!s->budget--) { s->failed_pc=0x0c09c9bau; return 0; }
r[0]<<=2;
goto P_0c09c9bc;
P_0c09c9bc: /* original 62e3, guest PC 0x0c09c9bc */
if(!s->budget--) { s->failed_pc=0x0c09c9bcu; return 0; }
r[2]=r[14];
goto P_0c09c9be;
P_0c09c9be: /* original 4008, guest PC 0x0c09c9be */
if(!s->budget--) { s->failed_pc=0x0c09c9beu; return 0; }
r[0]<<=2;
goto P_0c09c9c0;
P_0c09c9c0: /* original 33dc, guest PC 0x0c09c9c0 */
if(!s->budget--) { s->failed_pc=0x0c09c9c0u; return 0; }
r[3]+=r[13];
goto P_0c09c9c2;
P_0c09c9c2: /* original 4008, guest PC 0x0c09c9c2 */
if(!s->budget--) { s->failed_pc=0x0c09c9c2u; return 0; }
r[0]<<=2;
goto P_0c09c9c4;
P_0c09c9c4: /* original 303c, guest PC 0x0c09c9c4 */
if(!s->budget--) { s->failed_pc=0x0c09c9c4u; return 0; }
r[0]+=r[3];
goto P_0c09c9c6;
P_0c09c9c6: /* original 933b, guest PC 0x0c09c9c6 */
if(!s->budget--) { s->failed_pc=0x0c09c9c6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca40u,2);
goto P_0c09c9c8;
P_0c09c9c8: /* original 4208, guest PC 0x0c09c9c8 */
if(!s->budget--) { s->failed_pc=0x0c09c9c8u; return 0; }
r[2]<<=2;
goto P_0c09c9ca;
P_0c09c9ca: /* original 33dc, guest PC 0x0c09c9ca */
if(!s->budget--) { s->failed_pc=0x0c09c9cau; return 0; }
r[3]+=r[13];
goto P_0c09c9cc;
P_0c09c9cc: /* original 323c, guest PC 0x0c09c9cc */
if(!s->budget--) { s->failed_pc=0x0c09c9ccu; return 0; }
r[2]+=r[3];
goto P_0c09c9ce;
P_0c09c9ce: /* original 6122, guest PC 0x0c09c9ce */
if(!s->budget--) { s->failed_pc=0x0c09c9ceu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c9d0;
P_0c09c9d0: /* original 4108, guest PC 0x0c09c9d0 */
if(!s->budget--) { s->failed_pc=0x0c09c9d0u; return 0; }
r[1]<<=2;
goto P_0c09c9d2;
P_0c09c9d2: /* original 031e, guest PC 0x0c09c9d2 */
if(!s->budget--) { s->failed_pc=0x0c09c9d2u; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c09c9d4;
P_0c09c9d4: /* original 2338, guest PC 0x0c09c9d4 */
if(!s->budget--) { s->failed_pc=0x0c09c9d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09c9d6;
P_0c09c9d6: /* original 8b0e, guest PC 0x0c09c9d6 */
if(!s->budget--) { s->failed_pc=0x0c09c9d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09c9f6; }
goto P_0c09c9d8;
P_0c09c9d8: /* original 60e3, guest PC 0x0c09c9d8 */
if(!s->budget--) { s->failed_pc=0x0c09c9d8u; return 0; }
r[0]=r[14];
goto P_0c09c9da;
P_0c09c9da: /* original 9330, guest PC 0x0c09c9da */
if(!s->budget--) { s->failed_pc=0x0c09c9dau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca3eu,2);
goto P_0c09c9dc;
P_0c09c9dc: /* original 4008, guest PC 0x0c09c9dc */
if(!s->budget--) { s->failed_pc=0x0c09c9dcu; return 0; }
r[0]<<=2;
goto P_0c09c9de;
P_0c09c9de: /* original 62e3, guest PC 0x0c09c9de */
if(!s->budget--) { s->failed_pc=0x0c09c9deu; return 0; }
r[2]=r[14];
goto P_0c09c9e0;
P_0c09c9e0: /* original 4008, guest PC 0x0c09c9e0 */
if(!s->budget--) { s->failed_pc=0x0c09c9e0u; return 0; }
r[0]<<=2;
goto P_0c09c9e2;
P_0c09c9e2: /* original 33dc, guest PC 0x0c09c9e2 */
if(!s->budget--) { s->failed_pc=0x0c09c9e2u; return 0; }
r[3]+=r[13];
goto P_0c09c9e4;
P_0c09c9e4: /* original 4008, guest PC 0x0c09c9e4 */
if(!s->budget--) { s->failed_pc=0x0c09c9e4u; return 0; }
r[0]<<=2;
goto P_0c09c9e6;
P_0c09c9e6: /* original 303c, guest PC 0x0c09c9e6 */
if(!s->budget--) { s->failed_pc=0x0c09c9e6u; return 0; }
r[0]+=r[3];
goto P_0c09c9e8;
P_0c09c9e8: /* original 932a, guest PC 0x0c09c9e8 */
if(!s->budget--) { s->failed_pc=0x0c09c9e8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca40u,2);
goto P_0c09c9ea;
P_0c09c9ea: /* original 4208, guest PC 0x0c09c9ea */
if(!s->budget--) { s->failed_pc=0x0c09c9eau; return 0; }
r[2]<<=2;
goto P_0c09c9ec;
P_0c09c9ec: /* original 33dc, guest PC 0x0c09c9ec */
if(!s->budget--) { s->failed_pc=0x0c09c9ecu; return 0; }
r[3]+=r[13];
goto P_0c09c9ee;
P_0c09c9ee: /* original 323c, guest PC 0x0c09c9ee */
if(!s->budget--) { s->failed_pc=0x0c09c9eeu; return 0; }
r[2]+=r[3];
goto P_0c09c9f0;
P_0c09c9f0: /* original 6122, guest PC 0x0c09c9f0 */
if(!s->budget--) { s->failed_pc=0x0c09c9f0u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c09c9f2;
P_0c09c9f2: /* original 4108, guest PC 0x0c09c9f2 */
if(!s->budget--) { s->failed_pc=0x0c09c9f2u; return 0; }
r[1]<<=2;
goto P_0c09c9f4;
P_0c09c9f4: /* original 0186, guest PC 0x0c09c9f4 */
if(!s->budget--) { s->failed_pc=0x0c09c9f4u; return 0; }
write(ram,r[1]+r[0],r[8],4);
goto P_0c09c9f6;
P_0c09c9f6: /* original 7e01, guest PC 0x0c09c9f6 */
if(!s->budget--) { s->failed_pc=0x0c09c9f6u; return 0; }
r[14]+=0x00000001u;
goto P_0c09c9f8;
P_0c09c9f8: /* original e402, guest PC 0x0c09c9f8 */
if(!s->budget--) { s->failed_pc=0x0c09c9f8u; return 0; }
r[4]=0x00000002u;
goto P_0c09c9fa;
P_0c09c9fa: /* original 3e43, guest PC 0x0c09c9fa */
if(!s->budget--) { s->failed_pc=0x0c09c9fau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[4])!=0);
goto P_0c09c9fc;
P_0c09c9fc: /* original 8901, guest PC 0x0c09c9fc */
if(!s->budget--) { s->failed_pc=0x0c09c9fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ca02; }
goto P_0c09c9fe;
P_0c09c9fe: /* original ac11, guest PC 0x0c09c9fe */
if(!s->budget--) { s->failed_pc=0x0c09c9feu; return 0; }
goto P_0c09c224;
P_0c09ca00: /* original 0009, guest PC 0x0c09ca00 */
if(!s->budget--) { s->failed_pc=0x0c09ca00u; return 0; }
goto P_0c09ca02;
P_0c09ca02: /* original 901e, guest PC 0x0c09ca02 */
if(!s->budget--) { s->failed_pc=0x0c09ca02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca42u,2);
goto P_0c09ca04;
P_0c09ca04: /* original 00de, guest PC 0x0c09ca04 */
if(!s->budget--) { s->failed_pc=0x0c09ca04u; return 0; }
r[0]=read(ram,r[13]+r[0],4);
goto P_0c09ca06;
P_0c09ca06: /* original c804, guest PC 0x0c09ca06 */
if(!s->budget--) { s->failed_pc=0x0c09ca06u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c09ca08;
P_0c09ca08: /* original 890c, guest PC 0x0c09ca08 */
if(!s->budget--) { s->failed_pc=0x0c09ca08u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ca24; }
goto P_0c09ca0a;
P_0c09ca0a: /* original 901b, guest PC 0x0c09ca0a */
if(!s->budget--) { s->failed_pc=0x0c09ca0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca44u,2);
goto P_0c09ca0c;
P_0c09ca0c: /* original 00de, guest PC 0x0c09ca0c */
if(!s->budget--) { s->failed_pc=0x0c09ca0cu; return 0; }
r[0]=read(ram,r[13]+r[0],4);
goto P_0c09ca0e;
P_0c09ca0e: /* original c804, guest PC 0x0c09ca0e */
if(!s->budget--) { s->failed_pc=0x0c09ca0eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c09ca10;
P_0c09ca10: /* original 8b2d, guest PC 0x0c09ca10 */
if(!s->budget--) { s->failed_pc=0x0c09ca10u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ca6e; }
goto P_0c09ca12;
P_0c09ca12: /* original 9017, guest PC 0x0c09ca12 */
if(!s->budget--) { s->failed_pc=0x0c09ca12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca44u,2);
goto P_0c09ca14;
P_0c09ca14: /* original 03de, guest PC 0x0c09ca14 */
if(!s->budget--) { s->failed_pc=0x0c09ca14u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c09ca16;
P_0c09ca16: /* original 23c8, guest PC 0x0c09ca16 */
if(!s->budget--) { s->failed_pc=0x0c09ca16u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c09ca18;
P_0c09ca18: /* original 892e, guest PC 0x0c09ca18 */
if(!s->budget--) { s->failed_pc=0x0c09ca18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ca78; }
goto P_0c09ca1a;
P_0c09ca1a: /* original 00de, guest PC 0x0c09ca1a */
if(!s->budget--) { s->failed_pc=0x0c09ca1au; return 0; }
r[0]=read(ram,r[13]+r[0],4);
goto P_0c09ca1c;
P_0c09ca1c: /* original c808, guest PC 0x0c09ca1c */
if(!s->budget--) { s->failed_pc=0x0c09ca1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c09ca1e;
P_0c09ca1e: /* original 8b22, guest PC 0x0c09ca1e */
if(!s->budget--) { s->failed_pc=0x0c09ca1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ca66; }
goto P_0c09ca20;
P_0c09ca20: /* original a025, guest PC 0x0c09ca20 */
if(!s->budget--) { s->failed_pc=0x0c09ca20u; return 0; }
goto P_0c09ca6e;
P_0c09ca22: /* original 0009, guest PC 0x0c09ca22 */
if(!s->budget--) { s->failed_pc=0x0c09ca22u; return 0; }
goto P_0c09ca24;
P_0c09ca24: /* original 900e, guest PC 0x0c09ca24 */
if(!s->budget--) { s->failed_pc=0x0c09ca24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca44u,2);
goto P_0c09ca26;
P_0c09ca26: /* original 00de, guest PC 0x0c09ca26 */
if(!s->budget--) { s->failed_pc=0x0c09ca26u; return 0; }
r[0]=read(ram,r[13]+r[0],4);
goto P_0c09ca28;
P_0c09ca28: /* original c804, guest PC 0x0c09ca28 */
if(!s->budget--) { s->failed_pc=0x0c09ca28u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c09ca2a;
P_0c09ca2a: /* original 890c, guest PC 0x0c09ca2a */
if(!s->budget--) { s->failed_pc=0x0c09ca2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ca46; }
goto P_0c09ca2c;
P_0c09ca2c: /* original 9009, guest PC 0x0c09ca2c */
if(!s->budget--) { s->failed_pc=0x0c09ca2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ca42u,2);
goto P_0c09ca2e;
P_0c09ca2e: /* original 02de, guest PC 0x0c09ca2e */
if(!s->budget--) { s->failed_pc=0x0c09ca2eu; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c09ca30;
P_0c09ca30: /* original 22c8, guest PC 0x0c09ca30 */
if(!s->budget--) { s->failed_pc=0x0c09ca30u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c09ca32;
P_0c09ca32: /* original 8921, guest PC 0x0c09ca32 */
if(!s->budget--) { s->failed_pc=0x0c09ca32u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ca78; }
goto P_0c09ca34;
P_0c09ca34: /* original 00de, guest PC 0x0c09ca34 */
if(!s->budget--) { s->failed_pc=0x0c09ca34u; return 0; }
r[0]=read(ram,r[13]+r[0],4);
goto P_0c09ca36;
P_0c09ca36: /* original c808, guest PC 0x0c09ca36 */
if(!s->budget--) { s->failed_pc=0x0c09ca36u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c09ca38;
P_0c09ca38: /* original 8919, guest PC 0x0c09ca38 */
if(!s->budget--) { s->failed_pc=0x0c09ca38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ca6e; }
goto P_0c09ca3a;
P_0c09ca3a: /* original a014, guest PC 0x0c09ca3a */
if(!s->budget--) { s->failed_pc=0x0c09ca3au; return 0; }
goto P_0c09ca66;
P_0c09ca3c: /* original 0009, guest PC 0x0c09ca3c */
if(!s->budget--) { s->failed_pc=0x0c09ca3cu; return 0; }
if(!vf3_matrix_family(0x0c09ca3eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09ca3eu; return 0; } return 1;
P_0c09ca46: /* original 9478, guest PC 0x0c09ca46 */
if(!s->budget--) { s->failed_pc=0x0c09ca46u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cb3au,2);
goto P_0c09ca48;
P_0c09ca48: /* original 34dc, guest PC 0x0c09ca48 */
if(!s->budget--) { s->failed_pc=0x0c09ca48u; return 0; }
r[4]+=r[13];
goto P_0c09ca4a;
P_0c09ca4a: /* original 6042, guest PC 0x0c09ca4a */
if(!s->budget--) { s->failed_pc=0x0c09ca4au; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c09ca4c;
P_0c09ca4c: /* original 5341, guest PC 0x0c09ca4c */
if(!s->budget--) { s->failed_pc=0x0c09ca4cu; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c09ca4e;
P_0c09ca4e: /* original 2039, guest PC 0x0c09ca4e */
if(!s->budget--) { s->failed_pc=0x0c09ca4eu; return 0; }
r[0]&=r[3];
goto P_0c09ca50;
P_0c09ca50: /* original 20c9, guest PC 0x0c09ca50 */
if(!s->budget--) { s->failed_pc=0x0c09ca50u; return 0; }
r[0]&=r[12];
goto P_0c09ca52;
P_0c09ca52: /* original 8801, guest PC 0x0c09ca52 */
if(!s->budget--) { s->failed_pc=0x0c09ca52u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09ca54;
P_0c09ca54: /* original 8b10, guest PC 0x0c09ca54 */
if(!s->budget--) { s->failed_pc=0x0c09ca54u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ca78; }
goto P_0c09ca56;
P_0c09ca56: /* original 9470, guest PC 0x0c09ca56 */
if(!s->budget--) { s->failed_pc=0x0c09ca56u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cb3au,2);
goto P_0c09ca58;
P_0c09ca58: /* original 34dc, guest PC 0x0c09ca58 */
if(!s->budget--) { s->failed_pc=0x0c09ca58u; return 0; }
r[4]+=r[13];
goto P_0c09ca5a;
P_0c09ca5a: /* original 6042, guest PC 0x0c09ca5a */
if(!s->budget--) { s->failed_pc=0x0c09ca5au; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c09ca5c;
P_0c09ca5c: /* original 5341, guest PC 0x0c09ca5c */
if(!s->budget--) { s->failed_pc=0x0c09ca5cu; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c09ca5e;
P_0c09ca5e: /* original 203b, guest PC 0x0c09ca5e */
if(!s->budget--) { s->failed_pc=0x0c09ca5eu; return 0; }
r[0]|=r[3];
goto P_0c09ca60;
P_0c09ca60: /* original c908, guest PC 0x0c09ca60 */
if(!s->budget--) { s->failed_pc=0x0c09ca60u; return 0; }
r[0]&=8u;
goto P_0c09ca62;
P_0c09ca62: /* original 8808, guest PC 0x0c09ca62 */
if(!s->budget--) { s->failed_pc=0x0c09ca62u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c09ca64;
P_0c09ca64: /* original 8b03, guest PC 0x0c09ca64 */
if(!s->budget--) { s->failed_pc=0x0c09ca64u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ca6e; }
goto P_0c09ca66;
P_0c09ca66: /* original 60c3, guest PC 0x0c09ca66 */
if(!s->budget--) { s->failed_pc=0x0c09ca66u; return 0; }
r[0]=r[12];
goto P_0c09ca68;
P_0c09ca68: /* original 80db, guest PC 0x0c09ca68 */
if(!s->budget--) { s->failed_pc=0x0c09ca68u; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c09ca6a;
P_0c09ca6a: /* original a003, guest PC 0x0c09ca6a */
if(!s->budget--) { s->failed_pc=0x0c09ca6au; return 0; }
r[3]=0x00000072u;
goto P_0c09ca74;
P_0c09ca6c: /* original e372, guest PC 0x0c09ca6c */
if(!s->budget--) { s->failed_pc=0x0c09ca6cu; return 0; }
r[3]=0x00000072u;
goto P_0c09ca6e;
P_0c09ca6e: /* original e009, guest PC 0x0c09ca6e */
if(!s->budget--) { s->failed_pc=0x0c09ca6eu; return 0; }
r[0]=0x00000009u;
goto P_0c09ca70;
P_0c09ca70: /* original e376, guest PC 0x0c09ca70 */
if(!s->budget--) { s->failed_pc=0x0c09ca70u; return 0; }
r[3]=0x00000076u;
goto P_0c09ca72;
P_0c09ca72: /* original 80db, guest PC 0x0c09ca72 */
if(!s->budget--) { s->failed_pc=0x0c09ca72u; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c09ca74;
P_0c09ca74: /* original e010, guest PC 0x0c09ca74 */
if(!s->budget--) { s->failed_pc=0x0c09ca74u; return 0; }
r[0]=0x00000010u;
goto P_0c09ca76;
P_0c09ca76: /* original 0d34, guest PC 0x0c09ca76 */
if(!s->budget--) { s->failed_pc=0x0c09ca76u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c09ca78;
P_0c09ca78: /* original 7f0c, guest PC 0x0c09ca78 */
if(!s->budget--) { s->failed_pc=0x0c09ca78u; return 0; }
r[15]+=0x0000000cu;
goto P_0c09ca7a;
P_0c09ca7a: /* original 4f26, guest PC 0x0c09ca7a */
if(!s->budget--) { s->failed_pc=0x0c09ca7au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09ca7c;
P_0c09ca7c: /* original 68f6, guest PC 0x0c09ca7c */
if(!s->budget--) { s->failed_pc=0x0c09ca7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09ca7e;
P_0c09ca7e: /* original 69f6, guest PC 0x0c09ca7e */
if(!s->budget--) { s->failed_pc=0x0c09ca7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09ca80;
P_0c09ca80: /* original 6af6, guest PC 0x0c09ca80 */
if(!s->budget--) { s->failed_pc=0x0c09ca80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09ca82;
P_0c09ca82: /* original 6bf6, guest PC 0x0c09ca82 */
if(!s->budget--) { s->failed_pc=0x0c09ca82u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09ca84;
P_0c09ca84: /* original 6cf6, guest PC 0x0c09ca84 */
if(!s->budget--) { s->failed_pc=0x0c09ca84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09ca86;
P_0c09ca86: /* original 6df6, guest PC 0x0c09ca86 */
if(!s->budget--) { s->failed_pc=0x0c09ca86u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09ca88;
P_0c09ca88: /* original 000b, guest PC 0x0c09ca88 */
if(!s->budget--) { s->failed_pc=0x0c09ca88u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09ca8a: /* original 6ef6, guest PC 0x0c09ca8a */
if(!s->budget--) { s->failed_pc=0x0c09ca8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09ca8cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09ca8cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
