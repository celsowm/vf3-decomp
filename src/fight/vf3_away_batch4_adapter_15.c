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
int vf3_away_batch4_adapter_15(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04ce3cu: goto P_0c04ce3c;
case 0x0c04ce3eu: goto P_0c04ce3e;
case 0x0c04ce40u: goto P_0c04ce40;
case 0x0c04ce42u: goto P_0c04ce42;
case 0x0c04ce44u: goto P_0c04ce44;
case 0x0c04ce46u: goto P_0c04ce46;
case 0x0c04ce48u: goto P_0c04ce48;
case 0x0c04ce4au: goto P_0c04ce4a;
case 0x0c04ce4cu: goto P_0c04ce4c;
case 0x0c04ce4eu: goto P_0c04ce4e;
case 0x0c04ce50u: goto P_0c04ce50;
case 0x0c04ce52u: goto P_0c04ce52;
case 0x0c04ce54u: goto P_0c04ce54;
case 0x0c04ce56u: goto P_0c04ce56;
case 0x0c04ce58u: goto P_0c04ce58;
case 0x0c04ce5au: goto P_0c04ce5a;
case 0x0c04ce5cu: goto P_0c04ce5c;
case 0x0c04ce5eu: goto P_0c04ce5e;
case 0x0c04ce60u: goto P_0c04ce60;
case 0x0c04ce62u: goto P_0c04ce62;
case 0x0c04ce64u: goto P_0c04ce64;
case 0x0c04ce66u: goto P_0c04ce66;
case 0x0c04ce68u: goto P_0c04ce68;
case 0x0c04ce6au: goto P_0c04ce6a;
case 0x0c04ce6cu: goto P_0c04ce6c;
case 0x0c04ce6eu: goto P_0c04ce6e;
case 0x0c04ce70u: goto P_0c04ce70;
case 0x0c04ce72u: goto P_0c04ce72;
case 0x0c04ce74u: goto P_0c04ce74;
case 0x0c04ce76u: goto P_0c04ce76;
case 0x0c04ce78u: goto P_0c04ce78;
case 0x0c04ce7au: goto P_0c04ce7a;
case 0x0c04ce7cu: goto P_0c04ce7c;
case 0x0c04ce7eu: goto P_0c04ce7e;
case 0x0c04ce80u: goto P_0c04ce80;
case 0x0c04ce82u: goto P_0c04ce82;
case 0x0c04ce84u: goto P_0c04ce84;
case 0x0c04ce86u: goto P_0c04ce86;
case 0x0c04ce88u: goto P_0c04ce88;
case 0x0c04ce8au: goto P_0c04ce8a;
case 0x0c04ce8cu: goto P_0c04ce8c;
case 0x0c04ce8eu: goto P_0c04ce8e;
case 0x0c04ce90u: goto P_0c04ce90;
case 0x0c04ce92u: goto P_0c04ce92;
case 0x0c04ce94u: goto P_0c04ce94;
case 0x0c04ce96u: goto P_0c04ce96;
case 0x0c04ce98u: goto P_0c04ce98;
case 0x0c04ce9au: goto P_0c04ce9a;
case 0x0c04ce9cu: goto P_0c04ce9c;
case 0x0c04ce9eu: goto P_0c04ce9e;
case 0x0c04cea0u: goto P_0c04cea0;
case 0x0c04cea2u: goto P_0c04cea2;
case 0x0c04cea4u: goto P_0c04cea4;
case 0x0c04cea6u: goto P_0c04cea6;
case 0x0c04cea8u: goto P_0c04cea8;
case 0x0c04ceaau: goto P_0c04ceaa;
case 0x0c04ceacu: goto P_0c04ceac;
case 0x0c04ceaeu: goto P_0c04ceae;
case 0x0c04ceb0u: goto P_0c04ceb0;
case 0x0c04ceb2u: goto P_0c04ceb2;
case 0x0c04ceb4u: goto P_0c04ceb4;
case 0x0c04ceb6u: goto P_0c04ceb6;
case 0x0c04ceb8u: goto P_0c04ceb8;
case 0x0c04cebau: goto P_0c04ceba;
case 0x0c04cebcu: goto P_0c04cebc;
case 0x0c04cebeu: goto P_0c04cebe;
case 0x0c04cec0u: goto P_0c04cec0;
case 0x0c04cec2u: goto P_0c04cec2;
case 0x0c04cec4u: goto P_0c04cec4;
case 0x0c04cec6u: goto P_0c04cec6;
case 0x0c04cec8u: goto P_0c04cec8;
case 0x0c04cecau: goto P_0c04ceca;
case 0x0c04ceccu: goto P_0c04cecc;
case 0x0c04ceceu: goto P_0c04cece;
case 0x0c04ced0u: goto P_0c04ced0;
case 0x0c04ced2u: goto P_0c04ced2;
case 0x0c04ced4u: goto P_0c04ced4;
case 0x0c04ced6u: goto P_0c04ced6;
case 0x0c04ced8u: goto P_0c04ced8;
case 0x0c04cedau: goto P_0c04ceda;
case 0x0c04cedcu: goto P_0c04cedc;
case 0x0c04cedeu: goto P_0c04cede;
case 0x0c04cee0u: goto P_0c04cee0;
case 0x0c04cee2u: goto P_0c04cee2;
case 0x0c04cee4u: goto P_0c04cee4;
case 0x0c04cee6u: goto P_0c04cee6;
case 0x0c04cee8u: goto P_0c04cee8;
case 0x0c04ceeau: goto P_0c04ceea;
case 0x0c04ceecu: goto P_0c04ceec;
case 0x0c04ceeeu: goto P_0c04ceee;
case 0x0c04cef0u: goto P_0c04cef0;
case 0x0c04cef2u: goto P_0c04cef2;
case 0x0c04cef4u: goto P_0c04cef4;
case 0x0c04cef6u: goto P_0c04cef6;
case 0x0c04cef8u: goto P_0c04cef8;
case 0x0c04cefau: goto P_0c04cefa;
case 0x0c04cefcu: goto P_0c04cefc;
case 0x0c04cefeu: goto P_0c04cefe;
case 0x0c04cf00u: goto P_0c04cf00;
case 0x0c04cf02u: goto P_0c04cf02;
case 0x0c04cf04u: goto P_0c04cf04;
case 0x0c04cf06u: goto P_0c04cf06;
case 0x0c04cf08u: goto P_0c04cf08;
case 0x0c04cf0au: goto P_0c04cf0a;
case 0x0c04cf0cu: goto P_0c04cf0c;
case 0x0c04d010u: goto P_0c04d010;
case 0x0c04d012u: goto P_0c04d012;
case 0x0c04d014u: goto P_0c04d014;
case 0x0c04d016u: goto P_0c04d016;
case 0x0c04d018u: goto P_0c04d018;
case 0x0c04d01au: goto P_0c04d01a;
case 0x0c04d01cu: goto P_0c04d01c;
case 0x0c04d01eu: goto P_0c04d01e;
case 0x0c04d020u: goto P_0c04d020;
case 0x0c04d022u: goto P_0c04d022;
case 0x0c04d024u: goto P_0c04d024;
case 0x0c04d026u: goto P_0c04d026;
case 0x0c04d028u: goto P_0c04d028;
case 0x0c04d02au: goto P_0c04d02a;
case 0x0c04d02cu: goto P_0c04d02c;
case 0x0c04d02eu: goto P_0c04d02e;
case 0x0c04d030u: goto P_0c04d030;
case 0x0c04d032u: goto P_0c04d032;
case 0x0c04d034u: goto P_0c04d034;
case 0x0c04d036u: goto P_0c04d036;
case 0x0c04d038u: goto P_0c04d038;
case 0x0c04d03au: goto P_0c04d03a;
case 0x0c04d03cu: goto P_0c04d03c;
case 0x0c04d03eu: goto P_0c04d03e;
case 0x0c04d040u: goto P_0c04d040;
case 0x0c04d042u: goto P_0c04d042;
case 0x0c04d044u: goto P_0c04d044;
case 0x0c04d046u: goto P_0c04d046;
case 0x0c04d048u: goto P_0c04d048;
case 0x0c04d04au: goto P_0c04d04a;
case 0x0c04d04cu: goto P_0c04d04c;
case 0x0c04d04eu: goto P_0c04d04e;
case 0x0c04d050u: goto P_0c04d050;
case 0x0c04d052u: goto P_0c04d052;
case 0x0c04d054u: goto P_0c04d054;
case 0x0c04d056u: goto P_0c04d056;
case 0x0c04d058u: goto P_0c04d058;
case 0x0c04d05au: goto P_0c04d05a;
case 0x0c04d05cu: goto P_0c04d05c;
case 0x0c04d05eu: goto P_0c04d05e;
case 0x0c04d060u: goto P_0c04d060;
case 0x0c04d062u: goto P_0c04d062;
case 0x0c04d064u: goto P_0c04d064;
case 0x0c04d066u: goto P_0c04d066;
case 0x0c04d068u: goto P_0c04d068;
case 0x0c04d06au: goto P_0c04d06a;
case 0x0c04d06cu: goto P_0c04d06c;
case 0x0c04d06eu: goto P_0c04d06e;
case 0x0c04d070u: goto P_0c04d070;
case 0x0c04d072u: goto P_0c04d072;
case 0x0c04d09cu: goto P_0c04d09c;
case 0x0c04d09eu: goto P_0c04d09e;
case 0x0c04d0a0u: goto P_0c04d0a0;
case 0x0c04d0a2u: goto P_0c04d0a2;
case 0x0c04d0a4u: goto P_0c04d0a4;
case 0x0c04d0a6u: goto P_0c04d0a6;
case 0x0c04d0a8u: goto P_0c04d0a8;
case 0x0c04d0aau: goto P_0c04d0aa;
case 0x0c04d0acu: goto P_0c04d0ac;
case 0x0c04d0aeu: goto P_0c04d0ae;
case 0x0c04d0b0u: goto P_0c04d0b0;
case 0x0c04d0b2u: goto P_0c04d0b2;
case 0x0c04d0b4u: goto P_0c04d0b4;
case 0x0c04d0b6u: goto P_0c04d0b6;
case 0x0c04d0b8u: goto P_0c04d0b8;
case 0x0c04d0bau: goto P_0c04d0ba;
case 0x0c04d0bcu: goto P_0c04d0bc;
case 0x0c04d0beu: goto P_0c04d0be;
case 0x0c04d0c0u: goto P_0c04d0c0;
case 0x0c04d0c2u: goto P_0c04d0c2;
case 0x0c04d0c4u: goto P_0c04d0c4;
case 0x0c04d0c6u: goto P_0c04d0c6;
case 0x0c04d0c8u: goto P_0c04d0c8;
case 0x0c04d0cau: goto P_0c04d0ca;
case 0x0c04d0ccu: goto P_0c04d0cc;
case 0x0c04d0ceu: goto P_0c04d0ce;
case 0x0c04d0d0u: goto P_0c04d0d0;
case 0x0c04d0d2u: goto P_0c04d0d2;
case 0x0c04d0d4u: goto P_0c04d0d4;
case 0x0c04d0d6u: goto P_0c04d0d6;
case 0x0c04d0d8u: goto P_0c04d0d8;
case 0x0c04d0dau: goto P_0c04d0da;
case 0x0c04d0dcu: goto P_0c04d0dc;
case 0x0c04d0deu: goto P_0c04d0de;
case 0x0c04d0e0u: goto P_0c04d0e0;
case 0x0c04d0e2u: goto P_0c04d0e2;
case 0x0c04d0e4u: goto P_0c04d0e4;
case 0x0c04d0e6u: goto P_0c04d0e6;
case 0x0c04d0e8u: goto P_0c04d0e8;
case 0x0c04d0eau: goto P_0c04d0ea;
case 0x0c04d0ecu: goto P_0c04d0ec;
case 0x0c04d0eeu: goto P_0c04d0ee;
case 0x0c04d0f0u: goto P_0c04d0f0;
case 0x0c04d0f2u: goto P_0c04d0f2;
case 0x0c04d0f4u: goto P_0c04d0f4;
case 0x0c04d0f6u: goto P_0c04d0f6;
case 0x0c04d0f8u: goto P_0c04d0f8;
case 0x0c04d0fau: goto P_0c04d0fa;
case 0x0c04d0fcu: goto P_0c04d0fc;
case 0x0c04d0feu: goto P_0c04d0fe;
case 0x0c04d100u: goto P_0c04d100;
case 0x0c04d102u: goto P_0c04d102;
case 0x0c04d104u: goto P_0c04d104;
case 0x0c04d106u: goto P_0c04d106;
case 0x0c04d108u: goto P_0c04d108;
case 0x0c04d10au: goto P_0c04d10a;
case 0x0c04d10cu: goto P_0c04d10c;
case 0x0c04d10eu: goto P_0c04d10e;
case 0x0c04d110u: goto P_0c04d110;
case 0x0c04d112u: goto P_0c04d112;
case 0x0c04d114u: goto P_0c04d114;
case 0x0c04d116u: goto P_0c04d116;
case 0x0c04d118u: goto P_0c04d118;
case 0x0c04d11au: goto P_0c04d11a;
case 0x0c04d11cu: goto P_0c04d11c;
case 0x0c04d11eu: goto P_0c04d11e;
case 0x0c04d120u: goto P_0c04d120;
case 0x0c04d122u: goto P_0c04d122;
case 0x0c04d124u: goto P_0c04d124;
case 0x0c04d126u: goto P_0c04d126;
case 0x0c04d128u: goto P_0c04d128;
case 0x0c04d12au: goto P_0c04d12a;
case 0x0c04d12cu: goto P_0c04d12c;
case 0x0c04d12eu: goto P_0c04d12e;
case 0x0c04d130u: goto P_0c04d130;
case 0x0c04d132u: goto P_0c04d132;
case 0x0c04d134u: goto P_0c04d134;
case 0x0c04d136u: goto P_0c04d136;
case 0x0c04d138u: goto P_0c04d138;
case 0x0c04d13au: goto P_0c04d13a;
case 0x0c04d13cu: goto P_0c04d13c;
case 0x0c04d13eu: goto P_0c04d13e;
case 0x0c04d140u: goto P_0c04d140;
case 0x0c04d142u: goto P_0c04d142;
case 0x0c04d144u: goto P_0c04d144;
case 0x0c04d146u: goto P_0c04d146;
case 0x0c04d148u: goto P_0c04d148;
case 0x0c04d14au: goto P_0c04d14a;
case 0x0c04d14cu: goto P_0c04d14c;
case 0x0c04d14eu: goto P_0c04d14e;
case 0x0c04d150u: goto P_0c04d150;
case 0x0c04d152u: goto P_0c04d152;
case 0x0c04d154u: goto P_0c04d154;
case 0x0c04d156u: goto P_0c04d156;
case 0x0c04d158u: goto P_0c04d158;
case 0x0c04d15au: goto P_0c04d15a;
case 0x0c04d15cu: goto P_0c04d15c;
case 0x0c04d15eu: goto P_0c04d15e;
case 0x0c04d160u: goto P_0c04d160;
case 0x0c04d162u: goto P_0c04d162;
case 0x0c04d164u: goto P_0c04d164;
case 0x0c04d166u: goto P_0c04d166;
case 0x0c04d168u: goto P_0c04d168;
case 0x0c04d16au: goto P_0c04d16a;
case 0x0c04d16cu: goto P_0c04d16c;
case 0x0c04d16eu: goto P_0c04d16e;
case 0x0c04d170u: goto P_0c04d170;
case 0x0c04d172u: goto P_0c04d172;
case 0x0c04d174u: goto P_0c04d174;
case 0x0c04d1a0u: goto P_0c04d1a0;
case 0x0c04d1a2u: goto P_0c04d1a2;
case 0x0c04d1a4u: goto P_0c04d1a4;
case 0x0c04d1a6u: goto P_0c04d1a6;
case 0x0c04d1a8u: goto P_0c04d1a8;
case 0x0c04d1aau: goto P_0c04d1aa;
case 0x0c04d1acu: goto P_0c04d1ac;
case 0x0c04d1aeu: goto P_0c04d1ae;
case 0x0c04d1b0u: goto P_0c04d1b0;
case 0x0c04d1b2u: goto P_0c04d1b2;
case 0x0c04d1b4u: goto P_0c04d1b4;
case 0x0c04d1b6u: goto P_0c04d1b6;
case 0x0c04d1b8u: goto P_0c04d1b8;
case 0x0c04d1bau: goto P_0c04d1ba;
case 0x0c04d1bcu: goto P_0c04d1bc;
case 0x0c04d1beu: goto P_0c04d1be;
case 0x0c04d1c0u: goto P_0c04d1c0;
case 0x0c04d1c2u: goto P_0c04d1c2;
case 0x0c04d1c4u: goto P_0c04d1c4;
case 0x0c04d1c6u: goto P_0c04d1c6;
case 0x0c04d1c8u: goto P_0c04d1c8;
case 0x0c04d1cau: goto P_0c04d1ca;
case 0x0c04d1ccu: goto P_0c04d1cc;
case 0x0c04d1ceu: goto P_0c04d1ce;
case 0x0c04d1d0u: goto P_0c04d1d0;
case 0x0c04d1d2u: goto P_0c04d1d2;
case 0x0c04d1d4u: goto P_0c04d1d4;
case 0x0c04d1d6u: goto P_0c04d1d6;
case 0x0c04d1d8u: goto P_0c04d1d8;
case 0x0c04d1dau: goto P_0c04d1da;
case 0x0c04d1dcu: goto P_0c04d1dc;
case 0x0c04d1deu: goto P_0c04d1de;
case 0x0c04d1e0u: goto P_0c04d1e0;
case 0x0c04d1e2u: goto P_0c04d1e2;
case 0x0c04d1e4u: goto P_0c04d1e4;
case 0x0c04d1e6u: goto P_0c04d1e6;
case 0x0c04d1e8u: goto P_0c04d1e8;
case 0x0c04d1eau: goto P_0c04d1ea;
case 0x0c04d1ecu: goto P_0c04d1ec;
case 0x0c04d1eeu: goto P_0c04d1ee;
case 0x0c04d1f0u: goto P_0c04d1f0;
case 0x0c04d1f2u: goto P_0c04d1f2;
case 0x0c04d1f4u: goto P_0c04d1f4;
case 0x0c04d1f6u: goto P_0c04d1f6;
case 0x0c04d1f8u: goto P_0c04d1f8;
case 0x0c04d1fau: goto P_0c04d1fa;
case 0x0c04d1fcu: goto P_0c04d1fc;
case 0x0c04d1feu: goto P_0c04d1fe;
case 0x0c04d200u: goto P_0c04d200;
case 0x0c04d202u: goto P_0c04d202;
case 0x0c04d204u: goto P_0c04d204;
case 0x0c04d206u: goto P_0c04d206;
case 0x0c04d208u: goto P_0c04d208;
case 0x0c04d20au: goto P_0c04d20a;
case 0x0c04d20cu: goto P_0c04d20c;
case 0x0c04d20eu: goto P_0c04d20e;
case 0x0c04d210u: goto P_0c04d210;
case 0x0c04d212u: goto P_0c04d212;
case 0x0c04d214u: goto P_0c04d214;
case 0x0c04d216u: goto P_0c04d216;
case 0x0c04d218u: goto P_0c04d218;
case 0x0c04d21au: goto P_0c04d21a;
case 0x0c04d21cu: goto P_0c04d21c;
case 0x0c04d21eu: goto P_0c04d21e;
case 0x0c04d220u: goto P_0c04d220;
case 0x0c04d222u: goto P_0c04d222;
case 0x0c04d224u: goto P_0c04d224;
case 0x0c04d226u: goto P_0c04d226;
case 0x0c04d228u: goto P_0c04d228;
case 0x0c04d22au: goto P_0c04d22a;
case 0x0c04d22cu: goto P_0c04d22c;
case 0x0c04d22eu: goto P_0c04d22e;
case 0x0c04d230u: goto P_0c04d230;
case 0x0c04d232u: goto P_0c04d232;
case 0x0c04d234u: goto P_0c04d234;
case 0x0c04d236u: goto P_0c04d236;
case 0x0c04d238u: goto P_0c04d238;
case 0x0c04d23au: goto P_0c04d23a;
case 0x0c04d23cu: goto P_0c04d23c;
case 0x0c04d23eu: goto P_0c04d23e;
case 0x0c04d240u: goto P_0c04d240;
case 0x0c04d242u: goto P_0c04d242;
case 0x0c04d244u: goto P_0c04d244;
case 0x0c04d246u: goto P_0c04d246;
case 0x0c04d248u: goto P_0c04d248;
case 0x0c04d24au: goto P_0c04d24a;
case 0x0c04d24cu: goto P_0c04d24c;
case 0x0c04d24eu: goto P_0c04d24e;
case 0x0c04d250u: goto P_0c04d250;
case 0x0c04d252u: goto P_0c04d252;
case 0x0c04d254u: goto P_0c04d254;
case 0x0c04d256u: goto P_0c04d256;
case 0x0c04d258u: goto P_0c04d258;
case 0x0c04d25au: goto P_0c04d25a;
case 0x0c04d25cu: goto P_0c04d25c;
case 0x0c04d25eu: goto P_0c04d25e;
case 0x0c04d260u: goto P_0c04d260;
case 0x0c04d262u: goto P_0c04d262;
case 0x0c04d264u: goto P_0c04d264;
case 0x0c04d266u: goto P_0c04d266;
case 0x0c04d268u: goto P_0c04d268;
case 0x0c04d26au: goto P_0c04d26a;
case 0x0c04d26cu: goto P_0c04d26c;
case 0x0c04d26eu: goto P_0c04d26e;
case 0x0c04d270u: goto P_0c04d270;
case 0x0c04d272u: goto P_0c04d272;
case 0x0c04d274u: goto P_0c04d274;
case 0x0c04d276u: goto P_0c04d276;
case 0x0c04d278u: goto P_0c04d278;
case 0x0c04d27au: goto P_0c04d27a;
case 0x0c04d27cu: goto P_0c04d27c;
case 0x0c04d27eu: goto P_0c04d27e;
case 0x0c04d280u: goto P_0c04d280;
case 0x0c04d282u: goto P_0c04d282;
case 0x0c04d284u: goto P_0c04d284;
case 0x0c04d286u: goto P_0c04d286;
case 0x0c04d288u: goto P_0c04d288;
case 0x0c04d28au: goto P_0c04d28a;
case 0x0c04d28cu: goto P_0c04d28c;
case 0x0c04d28eu: goto P_0c04d28e;
case 0x0c04d290u: goto P_0c04d290;
case 0x0c04d292u: goto P_0c04d292;
case 0x0c04d294u: goto P_0c04d294;
case 0x0c04d296u: goto P_0c04d296;
case 0x0c04d298u: goto P_0c04d298;
case 0x0c04d29au: goto P_0c04d29a;
case 0x0c04d29cu: goto P_0c04d29c;
case 0x0c04d29eu: goto P_0c04d29e;
case 0x0c04d2a0u: goto P_0c04d2a0;
case 0x0c04d2a2u: goto P_0c04d2a2;
case 0x0c04d2a4u: goto P_0c04d2a4;
case 0x0c04d2a6u: goto P_0c04d2a6;
case 0x0c04d2a8u: goto P_0c04d2a8;
case 0x0c04d2aau: goto P_0c04d2aa;
case 0x0c04d2acu: goto P_0c04d2ac;
case 0x0c04d2aeu: goto P_0c04d2ae;
case 0x0c04d2b0u: goto P_0c04d2b0;
case 0x0c04d2b2u: goto P_0c04d2b2;
case 0x0c04d2b4u: goto P_0c04d2b4;
case 0x0c04d2b6u: goto P_0c04d2b6;
case 0x0c04d2b8u: goto P_0c04d2b8;
case 0x0c04d2bau: goto P_0c04d2ba;
case 0x0c04d2bcu: goto P_0c04d2bc;
case 0x0c04d2beu: goto P_0c04d2be;
case 0x0c04d2c0u: goto P_0c04d2c0;
case 0x0c04d2c2u: goto P_0c04d2c2;
case 0x0c04d2c4u: goto P_0c04d2c4;
case 0x0c04d2c6u: goto P_0c04d2c6;
case 0x0c04d2c8u: goto P_0c04d2c8;
case 0x0c04d2cau: goto P_0c04d2ca;
case 0x0c04d2ccu: goto P_0c04d2cc;
case 0x0c04d2ceu: goto P_0c04d2ce;
case 0x0c04d2d0u: goto P_0c04d2d0;
case 0x0c04d2d2u: goto P_0c04d2d2;
case 0x0c04d2d4u: goto P_0c04d2d4;
case 0x0c04d2d6u: goto P_0c04d2d6;
case 0x0c04d2d8u: goto P_0c04d2d8;
case 0x0c04d2dau: goto P_0c04d2da;
case 0x0c04d2dcu: goto P_0c04d2dc;
case 0x0c04d2deu: goto P_0c04d2de;
case 0x0c04d2e0u: goto P_0c04d2e0;
case 0x0c04d2e2u: goto P_0c04d2e2;
case 0x0c04d2e4u: goto P_0c04d2e4;
case 0x0c04d2e6u: goto P_0c04d2e6;
case 0x0c04d2e8u: goto P_0c04d2e8;
case 0x0c04d2eau: goto P_0c04d2ea;
case 0x0c04d2ecu: goto P_0c04d2ec;
case 0x0c04d2eeu: goto P_0c04d2ee;
case 0x0c04d2f0u: goto P_0c04d2f0;
case 0x0c04d320u: goto P_0c04d320;
case 0x0c04d322u: goto P_0c04d322;
case 0x0c04d324u: goto P_0c04d324;
case 0x0c04d326u: goto P_0c04d326;
case 0x0c04d328u: goto P_0c04d328;
case 0x0c04d32au: goto P_0c04d32a;
case 0x0c04d32cu: goto P_0c04d32c;
case 0x0c04d32eu: goto P_0c04d32e;
case 0x0c04d330u: goto P_0c04d330;
case 0x0c04d332u: goto P_0c04d332;
case 0x0c04d334u: goto P_0c04d334;
case 0x0c04d336u: goto P_0c04d336;
case 0x0c04d338u: goto P_0c04d338;
case 0x0c04d33au: goto P_0c04d33a;
case 0x0c04d33cu: goto P_0c04d33c;
case 0x0c04d33eu: goto P_0c04d33e;
case 0x0c04d340u: goto P_0c04d340;
case 0x0c04d342u: goto P_0c04d342;
case 0x0c04d344u: goto P_0c04d344;
case 0x0c04d346u: goto P_0c04d346;
case 0x0c04d348u: goto P_0c04d348;
case 0x0c04d34au: goto P_0c04d34a;
case 0x0c04d34cu: goto P_0c04d34c;
case 0x0c04d34eu: goto P_0c04d34e;
case 0x0c04d350u: goto P_0c04d350;
case 0x0c04d352u: goto P_0c04d352;
case 0x0c04d354u: goto P_0c04d354;
case 0x0c04d356u: goto P_0c04d356;
case 0x0c04d358u: goto P_0c04d358;
case 0x0c04d35au: goto P_0c04d35a;
case 0x0c04d35cu: goto P_0c04d35c;
case 0x0c04d35eu: goto P_0c04d35e;
case 0x0c04d360u: goto P_0c04d360;
case 0x0c04d362u: goto P_0c04d362;
case 0x0c04d364u: goto P_0c04d364;
case 0x0c04d366u: goto P_0c04d366;
case 0x0c04d368u: goto P_0c04d368;
case 0x0c04d36au: goto P_0c04d36a;
case 0x0c04d36cu: goto P_0c04d36c;
case 0x0c04d36eu: goto P_0c04d36e;
case 0x0c04d370u: goto P_0c04d370;
case 0x0c04d372u: goto P_0c04d372;
case 0x0c04d374u: goto P_0c04d374;
case 0x0c04d376u: goto P_0c04d376;
case 0x0c04d378u: goto P_0c04d378;
case 0x0c04d37au: goto P_0c04d37a;
case 0x0c04d37cu: goto P_0c04d37c;
case 0x0c04d37eu: goto P_0c04d37e;
case 0x0c04d380u: goto P_0c04d380;
case 0x0c04d382u: goto P_0c04d382;
case 0x0c04d384u: goto P_0c04d384;
case 0x0c04d386u: goto P_0c04d386;
case 0x0c04d388u: goto P_0c04d388;
case 0x0c04d38au: goto P_0c04d38a;
case 0x0c04d38cu: goto P_0c04d38c;
case 0x0c04d38eu: goto P_0c04d38e;
case 0x0c04d390u: goto P_0c04d390;
case 0x0c04d392u: goto P_0c04d392;
case 0x0c04d394u: goto P_0c04d394;
case 0x0c04d396u: goto P_0c04d396;
case 0x0c04d398u: goto P_0c04d398;
case 0x0c04d39au: goto P_0c04d39a;
case 0x0c04d39cu: goto P_0c04d39c;
case 0x0c04d39eu: goto P_0c04d39e;
case 0x0c04d3a0u: goto P_0c04d3a0;
case 0x0c04d3a2u: goto P_0c04d3a2;
case 0x0c04d3a4u: goto P_0c04d3a4;
case 0x0c04d3a6u: goto P_0c04d3a6;
case 0x0c04d3a8u: goto P_0c04d3a8;
case 0x0c04d3aau: goto P_0c04d3aa;
case 0x0c04d3acu: goto P_0c04d3ac;
case 0x0c04d3aeu: goto P_0c04d3ae;
case 0x0c04d3b0u: goto P_0c04d3b0;
case 0x0c04d3b2u: goto P_0c04d3b2;
case 0x0c04d3b4u: goto P_0c04d3b4;
case 0x0c04d3b6u: goto P_0c04d3b6;
case 0x0c04d3b8u: goto P_0c04d3b8;
case 0x0c04d3bau: goto P_0c04d3ba;
case 0x0c04d3bcu: goto P_0c04d3bc;
case 0x0c04d3beu: goto P_0c04d3be;
case 0x0c04d3c0u: goto P_0c04d3c0;
case 0x0c04d3c2u: goto P_0c04d3c2;
case 0x0c04d3c4u: goto P_0c04d3c4;
case 0x0c04d3c6u: goto P_0c04d3c6;
case 0x0c04d3c8u: goto P_0c04d3c8;
case 0x0c04d3cau: goto P_0c04d3ca;
case 0x0c04d3ccu: goto P_0c04d3cc;
case 0x0c04d3ceu: goto P_0c04d3ce;
case 0x0c04d3d0u: goto P_0c04d3d0;
case 0x0c04d3d2u: goto P_0c04d3d2;
case 0x0c04d3d4u: goto P_0c04d3d4;
case 0x0c04d3d6u: goto P_0c04d3d6;
case 0x0c04d3d8u: goto P_0c04d3d8;
case 0x0c04d3dau: goto P_0c04d3da;
case 0x0c04d3dcu: goto P_0c04d3dc;
case 0x0c04d3deu: goto P_0c04d3de;
case 0x0c04d3e0u: goto P_0c04d3e0;
case 0x0c04d3e2u: goto P_0c04d3e2;
case 0x0c04d3e4u: goto P_0c04d3e4;
case 0x0c04d3e6u: goto P_0c04d3e6;
case 0x0c04d3e8u: goto P_0c04d3e8;
case 0x0c04d3eau: goto P_0c04d3ea;
case 0x0c04d3ecu: goto P_0c04d3ec;
case 0x0c04d3eeu: goto P_0c04d3ee;
case 0x0c04d3f0u: goto P_0c04d3f0;
case 0x0c04d3f2u: goto P_0c04d3f2;
case 0x0c04d3f4u: goto P_0c04d3f4;
case 0x0c04d3f6u: goto P_0c04d3f6;
case 0x0c04d3f8u: goto P_0c04d3f8;
case 0x0c04d3fau: goto P_0c04d3fa;
case 0x0c04d3fcu: goto P_0c04d3fc;
case 0x0c04d3feu: goto P_0c04d3fe;
case 0x0c04d400u: goto P_0c04d400;
case 0x0c04d402u: goto P_0c04d402;
case 0x0c04d404u: goto P_0c04d404;
case 0x0c04d406u: goto P_0c04d406;
case 0x0c04d408u: goto P_0c04d408;
case 0x0c04d40au: goto P_0c04d40a;
case 0x0c04d40cu: goto P_0c04d40c;
case 0x0c04d40eu: goto P_0c04d40e;
case 0x0c04d410u: goto P_0c04d410;
case 0x0c04d412u: goto P_0c04d412;
case 0x0c04d414u: goto P_0c04d414;
case 0x0c04d416u: goto P_0c04d416;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04ce3c: /* original 2fe6, guest PC 0x0c04ce3c */
if(!s->budget--) { s->failed_pc=0x0c04ce3cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ce3e;
P_0c04ce3e: /* original 6e43, guest PC 0x0c04ce3e */
if(!s->budget--) { s->failed_pc=0x0c04ce3eu; return 0; }
r[14]=r[4];
goto P_0c04ce40;
P_0c04ce40: /* original 2fd6, guest PC 0x0c04ce40 */
if(!s->budget--) { s->failed_pc=0x0c04ce40u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ce42;
P_0c04ce42: /* original 4f22, guest PC 0x0c04ce42 */
if(!s->budget--) { s->failed_pc=0x0c04ce42u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04ce44;
P_0c04ce44: /* original 9388, guest PC 0x0c04ce44 */
if(!s->budget--) { s->failed_pc=0x0c04ce44u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04cf58u,2);
goto P_0c04ce46;
P_0c04ce46: /* original 4f12, guest PC 0x0c04ce46 */
if(!s->budget--) { s->failed_pc=0x0c04ce46u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04ce48;
P_0c04ce48: /* original 2e3f, guest PC 0x0c04ce48 */
if(!s->budget--) { s->failed_pc=0x0c04ce48u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c04ce4a;
P_0c04ce4a: /* original 7ff8, guest PC 0x0c04ce4a */
if(!s->budget--) { s->failed_pc=0x0c04ce4au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c04ce4c;
P_0c04ce4c: /* original 031a, guest PC 0x0c04ce4c */
if(!s->budget--) { s->failed_pc=0x0c04ce4cu; return 0; }
r[3]=r[19];
goto P_0c04ce4e;
P_0c04ce4e: /* original 633f, guest PC 0x0c04ce4e */
if(!s->budget--) { s->failed_pc=0x0c04ce4eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04ce50;
P_0c04ce50: /* original 2f32, guest PC 0x0c04ce50 */
if(!s->budget--) { s->failed_pc=0x0c04ce50u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c04ce52;
P_0c04ce52: /* original d242, guest PC 0x0c04ce52 */
if(!s->budget--) { s->failed_pc=0x0c04ce52u; return 0; }
r[2]=read(ram,0x0c04cf5cu,4);
goto P_0c04ce54;
P_0c04ce54: /* original 332c, guest PC 0x0c04ce54 */
if(!s->budget--) { s->failed_pc=0x0c04ce54u; return 0; }
r[3]+=r[2];
goto P_0c04ce56;
P_0c04ce56: /* original 1f31, guest PC 0x0c04ce56 */
if(!s->budget--) { s->failed_pc=0x0c04ce56u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c04ce58;
P_0c04ce58: /* original 2fe6, guest PC 0x0c04ce58 */
if(!s->budget--) { s->failed_pc=0x0c04ce58u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ce5a;
P_0c04ce5a: /* original d141, guest PC 0x0c04ce5a */
if(!s->budget--) { s->failed_pc=0x0c04ce5au; return 0; }
r[1]=read(ram,0x0c04cf60u,4);
goto P_0c04ce5c;
P_0c04ce5c: /* original bba0, guest PC 0x0c04ce5c */
if(!s->budget--) { s->failed_pc=0x0c04ce5cu; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04ce60u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04ce60u) { target=s->pc; goto dispatch; }
goto P_0c04ce60;
P_0c04ce5e: /* original 2f16, guest PC 0x0c04ce5e */
if(!s->budget--) { s->failed_pc=0x0c04ce5eu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ce60;
P_0c04ce60: /* original 7f08, guest PC 0x0c04ce60 */
if(!s->budget--) { s->failed_pc=0x0c04ce60u; return 0; }
r[15]+=0x00000008u;
goto P_0c04ce62;
P_0c04ce62: /* original 52f1, guest PC 0x0c04ce62 */
if(!s->budget--) { s->failed_pc=0x0c04ce62u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c04ce64;
P_0c04ce64: /* original 8422, guest PC 0x0c04ce64 */
if(!s->budget--) { s->failed_pc=0x0c04ce64u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+2,1);
goto P_0c04ce66;
P_0c04ce66: /* original 2008, guest PC 0x0c04ce66 */
if(!s->budget--) { s->failed_pc=0x0c04ce66u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ce68;
P_0c04ce68: /* original 8b02, guest PC 0x0c04ce68 */
if(!s->budget--) { s->failed_pc=0x0c04ce68u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ce70; }
goto P_0c04ce6a;
P_0c04ce6a: /* original 9076, guest PC 0x0c04ce6a */
if(!s->budget--) { s->failed_pc=0x0c04ce6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04cf5au,2);
goto P_0c04ce6c;
P_0c04ce6c: /* original a029, guest PC 0x0c04ce6c */
if(!s->budget--) { s->failed_pc=0x0c04ce6cu; return 0; }
goto P_0c04cec2;
P_0c04ce6e: /* original 0009, guest PC 0x0c04ce6e */
if(!s->budget--) { s->failed_pc=0x0c04ce6eu; return 0; }
goto P_0c04ce70;
P_0c04ce70: /* original 6df2, guest PC 0x0c04ce70 */
if(!s->budget--) { s->failed_pc=0x0c04ce70u; return 0; }
tmp=read(ram,r[15],4);
r[13]=tmp;
goto P_0c04ce72;
P_0c04ce72: /* original e201, guest PC 0x0c04ce72 */
if(!s->budget--) { s->failed_pc=0x0c04ce72u; return 0; }
r[2]=0x00000001u;
goto P_0c04ce74;
P_0c04ce74: /* original d339, guest PC 0x0c04ce74 */
if(!s->budget--) { s->failed_pc=0x0c04ce74u; return 0; }
r[3]=read(ram,0x0c04cf5cu,4);
goto P_0c04ce76;
P_0c04ce76: /* original 3d3c, guest PC 0x0c04ce76 */
if(!s->budget--) { s->failed_pc=0x0c04ce76u; return 0; }
r[13]+=r[3];
goto P_0c04ce78;
P_0c04ce78: /* original 1d2c, guest PC 0x0c04ce78 */
if(!s->budget--) { s->failed_pc=0x0c04ce78u; return 0; }
write(ram,r[13]+48,r[2],4);
goto P_0c04ce7a;
P_0c04ce7a: /* original 51d1, guest PC 0x0c04ce7a */
if(!s->budget--) { s->failed_pc=0x0c04ce7au; return 0; }
r[1]=read(ram,r[13]+4,4);
goto P_0c04ce7c;
P_0c04ce7c: /* original d039, guest PC 0x0c04ce7c */
if(!s->budget--) { s->failed_pc=0x0c04ce7cu; return 0; }
r[0]=read(ram,0x0c04cf64u,4);
goto P_0c04ce7e;
P_0c04ce7e: /* original 6213, guest PC 0x0c04ce7e */
if(!s->budget--) { s->failed_pc=0x0c04ce7eu; return 0; }
r[2]=r[1];
goto P_0c04ce80;
P_0c04ce80: /* original 4108, guest PC 0x0c04ce80 */
if(!s->budget--) { s->failed_pc=0x0c04ce80u; return 0; }
r[1]<<=2;
goto P_0c04ce82;
P_0c04ce82: /* original 312c, guest PC 0x0c04ce82 */
if(!s->budget--) { s->failed_pc=0x0c04ce82u; return 0; }
r[1]+=r[2];
goto P_0c04ce84;
P_0c04ce84: /* original 62e3, guest PC 0x0c04ce84 */
if(!s->budget--) { s->failed_pc=0x0c04ce84u; return 0; }
r[2]=r[14];
goto P_0c04ce86;
P_0c04ce86: /* original 4108, guest PC 0x0c04ce86 */
if(!s->budget--) { s->failed_pc=0x0c04ce86u; return 0; }
r[1]<<=2;
goto P_0c04ce88;
P_0c04ce88: /* original 4108, guest PC 0x0c04ce88 */
if(!s->budget--) { s->failed_pc=0x0c04ce88u; return 0; }
r[1]<<=2;
goto P_0c04ce8a;
P_0c04ce8a: /* original 611f, guest PC 0x0c04ce8a */
if(!s->budget--) { s->failed_pc=0x0c04ce8au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[1];
goto P_0c04ce8c;
P_0c04ce8c: /* original 4208, guest PC 0x0c04ce8c */
if(!s->budget--) { s->failed_pc=0x0c04ce8cu; return 0; }
r[2]<<=2;
goto P_0c04ce8e;
P_0c04ce8e: /* original 001e, guest PC 0x0c04ce8e */
if(!s->budget--) { s->failed_pc=0x0c04ce8eu; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c04ce90;
P_0c04ce90: /* original 4208, guest PC 0x0c04ce90 */
if(!s->budget--) { s->failed_pc=0x0c04ce90u; return 0; }
r[2]<<=2;
goto P_0c04ce92;
P_0c04ce92: /* original 4208, guest PC 0x0c04ce92 */
if(!s->budget--) { s->failed_pc=0x0c04ce92u; return 0; }
r[2]<<=2;
goto P_0c04ce94;
P_0c04ce94: /* original 1d0d, guest PC 0x0c04ce94 */
if(!s->budget--) { s->failed_pc=0x0c04ce94u; return 0; }
write(ram,r[13]+52,r[0],4);
goto P_0c04ce96;
P_0c04ce96: /* original d134, guest PC 0x0c04ce96 */
if(!s->budget--) { s->failed_pc=0x0c04ce96u; return 0; }
r[1]=read(ram,0x0c04cf68u,4);
goto P_0c04ce98;
P_0c04ce98: /* original 4200, guest PC 0x0c04ce98 */
if(!s->budget--) { s->failed_pc=0x0c04ce98u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c04ce9a;
P_0c04ce9a: /* original 321c, guest PC 0x0c04ce9a */
if(!s->budget--) { s->failed_pc=0x0c04ce9au; return 0; }
r[2]+=r[1];
goto P_0c04ce9c;
P_0c04ce9c: /* original 2f22, guest PC 0x0c04ce9c */
if(!s->budget--) { s->failed_pc=0x0c04ce9cu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c04ce9e;
P_0c04ce9e: /* original 56dc, guest PC 0x0c04ce9e */
if(!s->budget--) { s->failed_pc=0x0c04ce9eu; return 0; }
r[6]=read(ram,r[13]+48,4);
goto P_0c04cea0;
P_0c04cea0: /* original 57dd, guest PC 0x0c04cea0 */
if(!s->budget--) { s->failed_pc=0x0c04cea0u; return 0; }
r[7]=read(ram,r[13]+52,4);
goto P_0c04cea2;
P_0c04cea2: /* original 7601, guest PC 0x0c04cea2 */
if(!s->budget--) { s->failed_pc=0x0c04cea2u; return 0; }
r[6]+=0x00000001u;
goto P_0c04cea4;
P_0c04cea4: /* original 1d6c, guest PC 0x0c04cea4 */
if(!s->budget--) { s->failed_pc=0x0c04cea4u; return 0; }
write(ram,r[13]+48,r[6],4);
goto P_0c04cea6;
P_0c04cea6: /* original 76ff, guest PC 0x0c04cea6 */
if(!s->budget--) { s->failed_pc=0x0c04cea6u; return 0; }
r[6]+=0xffffffffu;
goto P_0c04cea8;
P_0c04cea8: /* original 65f2, guest PC 0x0c04cea8 */
if(!s->budget--) { s->failed_pc=0x0c04cea8u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04ceaa;
P_0c04ceaa: /* original d330, guest PC 0x0c04ceaa */
if(!s->budget--) { s->failed_pc=0x0c04ceaau; return 0; }
r[3]=read(ram,0x0c04cf6cu,4);
goto P_0c04ceac;
P_0c04ceac: /* original 5552, guest PC 0x0c04ceac */
if(!s->budget--) { s->failed_pc=0x0c04ceacu; return 0; }
r[5]=read(ram,r[5]+8,4);
goto P_0c04ceae;
P_0c04ceae: /* original 430b, guest PC 0x0c04ceae */
if(!s->budget--) { s->failed_pc=0x0c04ceaeu; return 0; }
target=r[3];
r[16]=code_base|0x0c04ceb2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04ceb2u) { target=s->pc; goto dispatch; }
goto P_0c04ceb2;
P_0c04ceb0: /* original 64e3, guest PC 0x0c04ceb0 */
if(!s->budget--) { s->failed_pc=0x0c04ceb0u; return 0; }
r[4]=r[14];
goto P_0c04ceb2;
P_0c04ceb2: /* original 7f08, guest PC 0x0c04ceb2 */
if(!s->budget--) { s->failed_pc=0x0c04ceb2u; return 0; }
r[15]+=0x00000008u;
goto P_0c04ceb4;
P_0c04ceb4: /* original d22e, guest PC 0x0c04ceb4 */
if(!s->budget--) { s->failed_pc=0x0c04ceb4u; return 0; }
r[2]=read(ram,0x0c04cf70u,4);
goto P_0c04ceb6;
P_0c04ceb6: /* original 4f16, guest PC 0x0c04ceb6 */
if(!s->budget--) { s->failed_pc=0x0c04ceb6u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ceb8;
P_0c04ceb8: /* original 64e3, guest PC 0x0c04ceb8 */
if(!s->budget--) { s->failed_pc=0x0c04ceb8u; return 0; }
r[4]=r[14];
goto P_0c04ceba;
P_0c04ceba: /* original 4f26, guest PC 0x0c04ceba */
if(!s->budget--) { s->failed_pc=0x0c04cebau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04cebc;
P_0c04cebc: /* original 6df6, guest PC 0x0c04cebc */
if(!s->budget--) { s->failed_pc=0x0c04cebcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04cebe;
P_0c04cebe: /* original 422b, guest PC 0x0c04cebe */
if(!s->budget--) { s->failed_pc=0x0c04cebeu; return 0; }
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
P_0c04cec0: /* original 6ef6, guest PC 0x0c04cec0 */
if(!s->budget--) { s->failed_pc=0x0c04cec0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04cec2;
P_0c04cec2: /* original 7f08, guest PC 0x0c04cec2 */
if(!s->budget--) { s->failed_pc=0x0c04cec2u; return 0; }
r[15]+=0x00000008u;
goto P_0c04cec4;
P_0c04cec4: /* original 4f16, guest PC 0x0c04cec4 */
if(!s->budget--) { s->failed_pc=0x0c04cec4u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04cec6;
P_0c04cec6: /* original 4f26, guest PC 0x0c04cec6 */
if(!s->budget--) { s->failed_pc=0x0c04cec6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04cec8;
P_0c04cec8: /* original 6df6, guest PC 0x0c04cec8 */
if(!s->budget--) { s->failed_pc=0x0c04cec8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04ceca;
P_0c04ceca: /* original 000b, guest PC 0x0c04ceca */
if(!s->budget--) { s->failed_pc=0x0c04cecau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04cecc: /* original 6ef6, guest PC 0x0c04cecc */
if(!s->budget--) { s->failed_pc=0x0c04ceccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04cece;
P_0c04cece: /* original 2fe6, guest PC 0x0c04cece */
if(!s->budget--) { s->failed_pc=0x0c04ceceu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ced0;
P_0c04ced0: /* original 4f22, guest PC 0x0c04ced0 */
if(!s->budget--) { s->failed_pc=0x0c04ced0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04ced2;
P_0c04ced2: /* original 9e41, guest PC 0x0c04ced2 */
if(!s->budget--) { s->failed_pc=0x0c04ced2u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04cf58u,2);
goto P_0c04ced4;
P_0c04ced4: /* original d321, guest PC 0x0c04ced4 */
if(!s->budget--) { s->failed_pc=0x0c04ced4u; return 0; }
r[3]=read(ram,0x0c04cf5cu,4);
goto P_0c04ced6;
P_0c04ced6: /* original 4f12, guest PC 0x0c04ced6 */
if(!s->budget--) { s->failed_pc=0x0c04ced6u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04ced8;
P_0c04ced8: /* original 24ef, guest PC 0x0c04ced8 */
if(!s->budget--) { s->failed_pc=0x0c04ced8u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[14]);
goto P_0c04ceda;
P_0c04ceda: /* original 2f46, guest PC 0x0c04ceda */
if(!s->budget--) { s->failed_pc=0x0c04cedau; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cedc;
P_0c04cedc: /* original d225, guest PC 0x0c04cedc */
if(!s->budget--) { s->failed_pc=0x0c04cedcu; return 0; }
r[2]=read(ram,0x0c04cf74u,4);
goto P_0c04cede;
P_0c04cede: /* original 0e1a, guest PC 0x0c04cede */
if(!s->budget--) { s->failed_pc=0x0c04cedeu; return 0; }
r[14]=r[19];
goto P_0c04cee0;
P_0c04cee0: /* original 6eef, guest PC 0x0c04cee0 */
if(!s->budget--) { s->failed_pc=0x0c04cee0u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04cee2;
P_0c04cee2: /* original 3e3c, guest PC 0x0c04cee2 */
if(!s->budget--) { s->failed_pc=0x0c04cee2u; return 0; }
r[14]+=r[3];
goto P_0c04cee4;
P_0c04cee4: /* original bb5c, guest PC 0x0c04cee4 */
if(!s->budget--) { s->failed_pc=0x0c04cee4u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04cee8u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04cee8u) { target=s->pc; goto dispatch; }
goto P_0c04cee8;
P_0c04cee6: /* original 2f26, guest PC 0x0c04cee6 */
if(!s->budget--) { s->failed_pc=0x0c04cee6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cee8;
P_0c04cee8: /* original 84e2, guest PC 0x0c04cee8 */
if(!s->budget--) { s->failed_pc=0x0c04cee8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c04ceea;
P_0c04ceea: /* original 2008, guest PC 0x0c04ceea */
if(!s->budget--) { s->failed_pc=0x0c04ceeau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ceec;
P_0c04ceec: /* original 8f03, guest PC 0x0c04ceec */
if(!s->budget--) { s->failed_pc=0x0c04ceecu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000008u;
if(!cond) { goto P_0c04cef6; }
goto P_0c04cef0;
P_0c04ceee: /* original 7f08, guest PC 0x0c04ceee */
if(!s->budget--) { s->failed_pc=0x0c04ceeeu; return 0; }
r[15]+=0x00000008u;
goto P_0c04cef0;
P_0c04cef0: /* original 9033, guest PC 0x0c04cef0 */
if(!s->budget--) { s->failed_pc=0x0c04cef0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04cf5au,2);
goto P_0c04cef2;
P_0c04cef2: /* original a008, guest PC 0x0c04cef2 */
if(!s->budget--) { s->failed_pc=0x0c04cef2u; return 0; }
goto P_0c04cf06;
P_0c04cef4: /* original 0009, guest PC 0x0c04cef4 */
if(!s->budget--) { s->failed_pc=0x0c04cef4u; return 0; }
goto P_0c04cef6;
P_0c04cef6: /* original e400, guest PC 0x0c04cef6 */
if(!s->budget--) { s->failed_pc=0x0c04cef6u; return 0; }
r[4]=0x00000000u;
goto P_0c04cef8;
P_0c04cef8: /* original 6043, guest PC 0x0c04cef8 */
if(!s->budget--) { s->failed_pc=0x0c04cef8u; return 0; }
r[0]=r[4];
goto P_0c04cefa;
P_0c04cefa: /* original 80e9, guest PC 0x0c04cefa */
if(!s->budget--) { s->failed_pc=0x0c04cefau; return 0; }
write(ram,r[14]+9,r[0],1);
goto P_0c04cefc;
P_0c04cefc: /* original 80e8, guest PC 0x0c04cefc */
if(!s->budget--) { s->failed_pc=0x0c04cefcu; return 0; }
write(ram,r[14]+8,r[0],1);
goto P_0c04cefe;
P_0c04cefe: /* original 80ea, guest PC 0x0c04cefe */
if(!s->budget--) { s->failed_pc=0x0c04cefeu; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c04cf00;
P_0c04cf00: /* original 80eb, guest PC 0x0c04cf00 */
if(!s->budget--) { s->failed_pc=0x0c04cf00u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c04cf02;
P_0c04cf02: /* original 80ec, guest PC 0x0c04cf02 */
if(!s->budget--) { s->failed_pc=0x0c04cf02u; return 0; }
write(ram,r[14]+12,r[0],1);
goto P_0c04cf04;
P_0c04cf04: /* original 1e01, guest PC 0x0c04cf04 */
if(!s->budget--) { s->failed_pc=0x0c04cf04u; return 0; }
write(ram,r[14]+4,r[0],4);
goto P_0c04cf06;
P_0c04cf06: /* original 4f16, guest PC 0x0c04cf06 */
if(!s->budget--) { s->failed_pc=0x0c04cf06u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04cf08;
P_0c04cf08: /* original 4f26, guest PC 0x0c04cf08 */
if(!s->budget--) { s->failed_pc=0x0c04cf08u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04cf0a;
P_0c04cf0a: /* original 000b, guest PC 0x0c04cf0a */
if(!s->budget--) { s->failed_pc=0x0c04cf0au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04cf0c: /* original 6ef6, guest PC 0x0c04cf0c */
if(!s->budget--) { s->failed_pc=0x0c04cf0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04cf0eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04cf0eu; return 0; } return 1;
P_0c04d010: /* original 2fe6, guest PC 0x0c04d010 */
if(!s->budget--) { s->failed_pc=0x0c04d010u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d012;
P_0c04d012: /* original 2fd6, guest PC 0x0c04d012 */
if(!s->budget--) { s->failed_pc=0x0c04d012u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d014;
P_0c04d014: /* original 6d43, guest PC 0x0c04d014 */
if(!s->budget--) { s->failed_pc=0x0c04d014u; return 0; }
r[13]=r[4];
goto P_0c04d016;
P_0c04d016: /* original 2fc6, guest PC 0x0c04d016 */
if(!s->budget--) { s->failed_pc=0x0c04d016u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d018;
P_0c04d018: /* original 2fb6, guest PC 0x0c04d018 */
if(!s->budget--) { s->failed_pc=0x0c04d018u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d01a;
P_0c04d01a: /* original 2fa6, guest PC 0x0c04d01a */
if(!s->budget--) { s->failed_pc=0x0c04d01au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d01c;
P_0c04d01c: /* original 2f96, guest PC 0x0c04d01c */
if(!s->budget--) { s->failed_pc=0x0c04d01cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d01e;
P_0c04d01e: /* original 2f86, guest PC 0x0c04d01e */
if(!s->budget--) { s->failed_pc=0x0c04d01eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d020;
P_0c04d020: /* original 4f22, guest PC 0x0c04d020 */
if(!s->budget--) { s->failed_pc=0x0c04d020u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04d022;
P_0c04d022: /* original 4f12, guest PC 0x0c04d022 */
if(!s->budget--) { s->failed_pc=0x0c04d022u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04d024;
P_0c04d024: /* original 7fe8, guest PC 0x0c04d024 */
if(!s->budget--) { s->failed_pc=0x0c04d024u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c04d026;
P_0c04d026: /* original 1f52, guest PC 0x0c04d026 */
if(!s->budget--) { s->failed_pc=0x0c04d026u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c04d028;
P_0c04d028: /* original 2f62, guest PC 0x0c04d028 */
if(!s->budget--) { s->failed_pc=0x0c04d028u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c04d02a;
P_0c04d02a: /* original 1f71, guest PC 0x0c04d02a */
if(!s->budget--) { s->failed_pc=0x0c04d02au; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c04d02c;
P_0c04d02c: /* original 9a26, guest PC 0x0c04d02c */
if(!s->budget--) { s->failed_pc=0x0c04d02cu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d07cu,2);
goto P_0c04d02e;
P_0c04d02e: /* original db15, guest PC 0x0c04d02e */
if(!s->budget--) { s->failed_pc=0x0c04d02eu; return 0; }
r[11]=read(ram,0x0c04d084u,4);
goto P_0c04d030;
P_0c04d030: /* original 2daf, guest PC 0x0c04d030 */
if(!s->budget--) { s->failed_pc=0x0c04d030u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[10]);
goto P_0c04d032;
P_0c04d032: /* original 2fd6, guest PC 0x0c04d032 */
if(!s->budget--) { s->failed_pc=0x0c04d032u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d034;
P_0c04d034: /* original d317, guest PC 0x0c04d034 */
if(!s->budget--) { s->failed_pc=0x0c04d034u; return 0; }
r[3]=read(ram,0x0c04d094u,4);
goto P_0c04d036;
P_0c04d036: /* original 0a1a, guest PC 0x0c04d036 */
if(!s->budget--) { s->failed_pc=0x0c04d036u; return 0; }
r[10]=r[19];
goto P_0c04d038;
P_0c04d038: /* original 6aaf, guest PC 0x0c04d038 */
if(!s->budget--) { s->failed_pc=0x0c04d038u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)r[10];
goto P_0c04d03a;
P_0c04d03a: /* original 6ea3, guest PC 0x0c04d03a */
if(!s->budget--) { s->failed_pc=0x0c04d03au; return 0; }
r[14]=r[10];
goto P_0c04d03c;
P_0c04d03c: /* original 3ebc, guest PC 0x0c04d03c */
if(!s->budget--) { s->failed_pc=0x0c04d03cu; return 0; }
r[14]+=r[11];
goto P_0c04d03e;
P_0c04d03e: /* original baaf, guest PC 0x0c04d03e */
if(!s->budget--) { s->failed_pc=0x0c04d03eu; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04d042u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d042u) { target=s->pc; goto dispatch; }
goto P_0c04d042;
P_0c04d040: /* original 2f36, guest PC 0x0c04d040 */
if(!s->budget--) { s->failed_pc=0x0c04d040u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d042;
P_0c04d042: /* original 84e2, guest PC 0x0c04d042 */
if(!s->budget--) { s->failed_pc=0x0c04d042u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c04d044;
P_0c04d044: /* original 2008, guest PC 0x0c04d044 */
if(!s->budget--) { s->failed_pc=0x0c04d044u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d046;
P_0c04d046: /* original 8f02, guest PC 0x0c04d046 */
if(!s->budget--) { s->failed_pc=0x0c04d046u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000008u;
if(!cond) { goto P_0c04d04e; }
goto P_0c04d04a;
P_0c04d048: /* original 7f08, guest PC 0x0c04d048 */
if(!s->budget--) { s->failed_pc=0x0c04d048u; return 0; }
r[15]+=0x00000008u;
goto P_0c04d04a;
P_0c04d04a: /* original a173, guest PC 0x0c04d04a */
if(!s->budget--) { s->failed_pc=0x0c04d04au; return 0; }
goto P_0c04d334;
P_0c04d04c: /* original 0009, guest PC 0x0c04d04c */
if(!s->budget--) { s->failed_pc=0x0c04d04cu; return 0; }
goto P_0c04d04e;
P_0c04d04e: /* original 53ff, guest PC 0x0c04d04e */
if(!s->budget--) { s->failed_pc=0x0c04d04eu; return 0; }
r[3]=read(ram,r[15]+60,4);
goto P_0c04d050;
P_0c04d050: /* original e501, guest PC 0x0c04d050 */
if(!s->budget--) { s->failed_pc=0x0c04d050u; return 0; }
r[5]=0x00000001u;
goto P_0c04d052;
P_0c04d052: /* original d411, guest PC 0x0c04d052 */
if(!s->budget--) { s->failed_pc=0x0c04d052u; return 0; }
r[4]=read(ram,0x0c04d098u,4);
goto P_0c04d054;
P_0c04d054: /* original 6ca3, guest PC 0x0c04d054 */
if(!s->budget--) { s->failed_pc=0x0c04d054u; return 0; }
r[12]=r[10];
goto P_0c04d056;
P_0c04d056: /* original 2338, guest PC 0x0c04d056 */
if(!s->budget--) { s->failed_pc=0x0c04d056u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04d058;
P_0c04d058: /* original 8d20, guest PC 0x0c04d058 */
if(!s->budget--) { s->failed_pc=0x0c04d058u; return 0; }
cond=r[17]&1u;
r[12]+=r[11];
if(cond) { goto P_0c04d09c; }
goto P_0c04d05c;
P_0c04d05a: /* original 3cbc, guest PC 0x0c04d05a */
if(!s->budget--) { s->failed_pc=0x0c04d05au; return 0; }
r[12]+=r[11];
goto P_0c04d05c;
P_0c04d05c: /* original 1c5c, guest PC 0x0c04d05c */
if(!s->budget--) { s->failed_pc=0x0c04d05cu; return 0; }
write(ram,r[12]+48,r[5],4);
goto P_0c04d05e;
P_0c04d05e: /* original 53c1, guest PC 0x0c04d05e */
if(!s->budget--) { s->failed_pc=0x0c04d05eu; return 0; }
r[3]=read(ram,r[12]+4,4);
goto P_0c04d060;
P_0c04d060: /* original 6233, guest PC 0x0c04d060 */
if(!s->budget--) { s->failed_pc=0x0c04d060u; return 0; }
r[2]=r[3];
goto P_0c04d062;
P_0c04d062: /* original 4308, guest PC 0x0c04d062 */
if(!s->budget--) { s->failed_pc=0x0c04d062u; return 0; }
r[3]<<=2;
goto P_0c04d064;
P_0c04d064: /* original 332c, guest PC 0x0c04d064 */
if(!s->budget--) { s->failed_pc=0x0c04d064u; return 0; }
r[3]+=r[2];
goto P_0c04d066;
P_0c04d066: /* original 4308, guest PC 0x0c04d066 */
if(!s->budget--) { s->failed_pc=0x0c04d066u; return 0; }
r[3]<<=2;
goto P_0c04d068;
P_0c04d068: /* original 4308, guest PC 0x0c04d068 */
if(!s->budget--) { s->failed_pc=0x0c04d068u; return 0; }
r[3]<<=2;
goto P_0c04d06a;
P_0c04d06a: /* original 633f, guest PC 0x0c04d06a */
if(!s->budget--) { s->failed_pc=0x0c04d06au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04d06c;
P_0c04d06c: /* original 343c, guest PC 0x0c04d06c */
if(!s->budget--) { s->failed_pc=0x0c04d06cu; return 0; }
r[4]+=r[3];
goto P_0c04d06e;
P_0c04d06e: /* original 5343, guest PC 0x0c04d06e */
if(!s->budget--) { s->failed_pc=0x0c04d06eu; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c04d070;
P_0c04d070: /* original a022, guest PC 0x0c04d070 */
if(!s->budget--) { s->failed_pc=0x0c04d070u; return 0; }
write(ram,r[12]+52,r[3],4);
goto P_0c04d0b8;
P_0c04d072: /* original 1c3d, guest PC 0x0c04d072 */
if(!s->budget--) { s->failed_pc=0x0c04d072u; return 0; }
write(ram,r[12]+52,r[3],4);
if(!vf3_matrix_family(0x0c04d074u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04d074u; return 0; } return 1;
P_0c04d09c: /* original 1c5c, guest PC 0x0c04d09c */
if(!s->budget--) { s->failed_pc=0x0c04d09cu; return 0; }
write(ram,r[12]+48,r[5],4);
goto P_0c04d09e;
P_0c04d09e: /* original 51c1, guest PC 0x0c04d09e */
if(!s->budget--) { s->failed_pc=0x0c04d09eu; return 0; }
r[1]=read(ram,r[12]+4,4);
goto P_0c04d0a0;
P_0c04d0a0: /* original d236, guest PC 0x0c04d0a0 */
if(!s->budget--) { s->failed_pc=0x0c04d0a0u; return 0; }
r[2]=read(ram,0x0c04d17cu,4);
goto P_0c04d0a2;
P_0c04d0a2: /* original 6313, guest PC 0x0c04d0a2 */
if(!s->budget--) { s->failed_pc=0x0c04d0a2u; return 0; }
r[3]=r[1];
goto P_0c04d0a4;
P_0c04d0a4: /* original 4108, guest PC 0x0c04d0a4 */
if(!s->budget--) { s->failed_pc=0x0c04d0a4u; return 0; }
r[1]<<=2;
goto P_0c04d0a6;
P_0c04d0a6: /* original 313c, guest PC 0x0c04d0a6 */
if(!s->budget--) { s->failed_pc=0x0c04d0a6u; return 0; }
r[1]+=r[3];
goto P_0c04d0a8;
P_0c04d0a8: /* original 4108, guest PC 0x0c04d0a8 */
if(!s->budget--) { s->failed_pc=0x0c04d0a8u; return 0; }
r[1]<<=2;
goto P_0c04d0aa;
P_0c04d0aa: /* original 4108, guest PC 0x0c04d0aa */
if(!s->budget--) { s->failed_pc=0x0c04d0aau; return 0; }
r[1]<<=2;
goto P_0c04d0ac;
P_0c04d0ac: /* original 611f, guest PC 0x0c04d0ac */
if(!s->budget--) { s->failed_pc=0x0c04d0acu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[1];
goto P_0c04d0ae;
P_0c04d0ae: /* original 314c, guest PC 0x0c04d0ae */
if(!s->budget--) { s->failed_pc=0x0c04d0aeu; return 0; }
r[1]+=r[4];
goto P_0c04d0b0;
P_0c04d0b0: /* original 5113, guest PC 0x0c04d0b0 */
if(!s->budget--) { s->failed_pc=0x0c04d0b0u; return 0; }
r[1]=read(ram,r[1]+12,4);
goto P_0c04d0b2;
P_0c04d0b2: /* original 420b, guest PC 0x0c04d0b2 */
if(!s->budget--) { s->failed_pc=0x0c04d0b2u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d0b6u;
r[0]=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d0b6u) { target=s->pc; goto dispatch; }
goto P_0c04d0b6;
P_0c04d0b4: /* original e00a, guest PC 0x0c04d0b4 */
if(!s->budget--) { s->failed_pc=0x0c04d0b4u; return 0; }
r[0]=0x0000000au;
goto P_0c04d0b6;
P_0c04d0b6: /* original 1c0d, guest PC 0x0c04d0b6 */
if(!s->budget--) { s->failed_pc=0x0c04d0b6u; return 0; }
write(ram,r[12]+52,r[0],4);
goto P_0c04d0b8;
P_0c04d0b8: /* original d331, guest PC 0x0c04d0b8 */
if(!s->budget--) { s->failed_pc=0x0c04d0b8u; return 0; }
r[3]=read(ram,0x0c04d180u,4);
goto P_0c04d0ba;
P_0c04d0ba: /* original 430b, guest PC 0x0c04d0ba */
if(!s->budget--) { s->failed_pc=0x0c04d0bau; return 0; }
target=r[3];
r[16]=code_base|0x0c04d0beu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d0beu) { target=s->pc; goto dispatch; }
goto P_0c04d0be;
P_0c04d0bc: /* original 64d3, guest PC 0x0c04d0bc */
if(!s->budget--) { s->failed_pc=0x0c04d0bcu; return 0; }
r[4]=r[13];
goto P_0c04d0be;
P_0c04d0be: /* original 2008, guest PC 0x0c04d0be */
if(!s->budget--) { s->failed_pc=0x0c04d0beu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d0c0;
P_0c04d0c0: /* original 8b01, guest PC 0x0c04d0c0 */
if(!s->budget--) { s->failed_pc=0x0c04d0c0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d0c6; }
goto P_0c04d0c2;
P_0c04d0c2: /* original a137, guest PC 0x0c04d0c2 */
if(!s->budget--) { s->failed_pc=0x0c04d0c2u; return 0; }
goto P_0c04d334;
P_0c04d0c4: /* original 0009, guest PC 0x0c04d0c4 */
if(!s->budget--) { s->failed_pc=0x0c04d0c4u; return 0; }
goto P_0c04d0c6;
P_0c04d0c6: /* original 3abc, guest PC 0x0c04d0c6 */
if(!s->budget--) { s->failed_pc=0x0c04d0c6u; return 0; }
r[10]+=r[11];
goto P_0c04d0c8;
P_0c04d0c8: /* original 84a8, guest PC 0x0c04d0c8 */
if(!s->budget--) { s->failed_pc=0x0c04d0c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+8,1);
goto P_0c04d0ca;
P_0c04d0ca: /* original 2008, guest PC 0x0c04d0ca */
if(!s->budget--) { s->failed_pc=0x0c04d0cau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d0cc;
P_0c04d0cc: /* original 8b01, guest PC 0x0c04d0cc */
if(!s->budget--) { s->failed_pc=0x0c04d0ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d0d2; }
goto P_0c04d0ce;
P_0c04d0ce: /* original a131, guest PC 0x0c04d0ce */
if(!s->budget--) { s->failed_pc=0x0c04d0ceu; return 0; }
goto P_0c04d334;
P_0c04d0d0: /* original 0009, guest PC 0x0c04d0d0 */
if(!s->budget--) { s->failed_pc=0x0c04d0d0u; return 0; }
goto P_0c04d0d2;
P_0c04d0d2: /* original 69d3, guest PC 0x0c04d0d2 */
if(!s->budget--) { s->failed_pc=0x0c04d0d2u; return 0; }
r[9]=r[13];
goto P_0c04d0d4;
P_0c04d0d4: /* original d32b, guest PC 0x0c04d0d4 */
if(!s->budget--) { s->failed_pc=0x0c04d0d4u; return 0; }
r[3]=read(ram,0x0c04d184u,4);
goto P_0c04d0d6;
P_0c04d0d6: /* original 4918, guest PC 0x0c04d0d6 */
if(!s->budget--) { s->failed_pc=0x0c04d0d6u; return 0; }
r[9]<<=8;
goto P_0c04d0d8;
P_0c04d0d8: /* original da2b, guest PC 0x0c04d0d8 */
if(!s->budget--) { s->failed_pc=0x0c04d0d8u; return 0; }
r[10]=read(ram,0x0c04d188u,4);
goto P_0c04d0da;
P_0c04d0da: /* original 964c, guest PC 0x0c04d0da */
if(!s->budget--) { s->failed_pc=0x0c04d0dau; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d176u,2);
goto P_0c04d0dc;
P_0c04d0dc: /* original 4900, guest PC 0x0c04d0dc */
if(!s->budget--) { s->failed_pc=0x0c04d0dcu; return 0; }
r[17]=(r[17]&~1u)|((r[9]>>31)!=0);
r[9]<<=1;
goto P_0c04d0de;
P_0c04d0de: /* original e500, guest PC 0x0c04d0de */
if(!s->budget--) { s->failed_pc=0x0c04d0deu; return 0; }
r[5]=0x00000000u;
goto P_0c04d0e0;
P_0c04d0e0: /* original 393c, guest PC 0x0c04d0e0 */
if(!s->budget--) { s->failed_pc=0x0c04d0e0u; return 0; }
r[9]+=r[3];
goto P_0c04d0e2;
P_0c04d0e2: /* original 4a0b, guest PC 0x0c04d0e2 */
if(!s->budget--) { s->failed_pc=0x0c04d0e2u; return 0; }
target=r[10];
r[16]=code_base|0x0c04d0e6u;
r[4]=read(ram,r[14]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d0e6u) { target=s->pc; goto dispatch; }
goto P_0c04d0e6;
P_0c04d0e4: /* original 54e8, guest PC 0x0c04d0e4 */
if(!s->budget--) { s->failed_pc=0x0c04d0e4u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d0e6;
P_0c04d0e6: /* original d229, guest PC 0x0c04d0e6 */
if(!s->budget--) { s->failed_pc=0x0c04d0e6u; return 0; }
r[2]=read(ram,0x0c04d18cu,4);
goto P_0c04d0e8;
P_0c04d0e8: /* original ba5a, guest PC 0x0c04d0e8 */
if(!s->budget--) { s->failed_pc=0x0c04d0e8u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04d0ecu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d0ecu) { target=s->pc; goto dispatch; }
goto P_0c04d0ec;
P_0c04d0ea: /* original 2f26, guest PC 0x0c04d0ea */
if(!s->budget--) { s->failed_pc=0x0c04d0eau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d0ec;
P_0c04d0ec: /* original 55e7, guest PC 0x0c04d0ec */
if(!s->budget--) { s->failed_pc=0x0c04d0ecu; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c04d0ee;
P_0c04d0ee: /* original 7f04, guest PC 0x0c04d0ee */
if(!s->budget--) { s->failed_pc=0x0c04d0eeu; return 0; }
r[15]+=0x00000004u;
goto P_0c04d0f0;
P_0c04d0f0: /* original 56e8, guest PC 0x0c04d0f0 */
if(!s->budget--) { s->failed_pc=0x0c04d0f0u; return 0; }
r[6]=read(ram,r[14]+32,4);
goto P_0c04d0f2;
P_0c04d0f2: /* original 5552, guest PC 0x0c04d0f2 */
if(!s->budget--) { s->failed_pc=0x0c04d0f2u; return 0; }
r[5]=read(ram,r[5]+8,4);
goto P_0c04d0f4;
P_0c04d0f4: /* original d826, guest PC 0x0c04d0f4 */
if(!s->budget--) { s->failed_pc=0x0c04d0f4u; return 0; }
r[8]=read(ram,0x0c04d190u,4);
goto P_0c04d0f6;
P_0c04d0f6: /* original 480b, guest PC 0x0c04d0f6 */
if(!s->budget--) { s->failed_pc=0x0c04d0f6u; return 0; }
target=r[8];
r[16]=code_base|0x0c04d0fau;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d0fau) { target=s->pc; goto dispatch; }
goto P_0c04d0fa;
P_0c04d0f8: /* original 64d3, guest PC 0x0c04d0f8 */
if(!s->budget--) { s->failed_pc=0x0c04d0f8u; return 0; }
r[4]=r[13];
goto P_0c04d0fa;
P_0c04d0fa: /* original 6403, guest PC 0x0c04d0fa */
if(!s->budget--) { s->failed_pc=0x0c04d0fau; return 0; }
r[4]=r[0];
goto P_0c04d0fc;
P_0c04d0fc: /* original 4411, guest PC 0x0c04d0fc */
if(!s->budget--) { s->failed_pc=0x0c04d0fcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c04d0fe;
P_0c04d0fe: /* original 8906, guest PC 0x0c04d0fe */
if(!s->budget--) { s->failed_pc=0x0c04d0feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d10e; }
goto P_0c04d100;
P_0c04d100: /* original 923a, guest PC 0x0c04d100 */
if(!s->budget--) { s->failed_pc=0x0c04d100u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d178u,2);
goto P_0c04d102;
P_0c04d102: /* original 3420, guest PC 0x0c04d102 */
if(!s->budget--) { s->failed_pc=0x0c04d102u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c04d104;
P_0c04d104: /* original 8901, guest PC 0x0c04d104 */
if(!s->budget--) { s->failed_pc=0x0c04d104u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d10a; }
goto P_0c04d106;
P_0c04d106: /* original a115, guest PC 0x0c04d106 */
if(!s->budget--) { s->failed_pc=0x0c04d106u; return 0; }
goto P_0c04d334;
P_0c04d108: /* original 0009, guest PC 0x0c04d108 */
if(!s->budget--) { s->failed_pc=0x0c04d108u; return 0; }
goto P_0c04d10a;
P_0c04d10a: /* original a17a, guest PC 0x0c04d10a */
if(!s->budget--) { s->failed_pc=0x0c04d10au; return 0; }
r[0]=0xffffff81u;
goto P_0c04d402;
P_0c04d10c: /* original e081, guest PC 0x0c04d10c */
if(!s->budget--) { s->failed_pc=0x0c04d10cu; return 0; }
r[0]=0xffffff81u;
goto P_0c04d10e;
P_0c04d10e: /* original d321, guest PC 0x0c04d10e */
if(!s->budget--) { s->failed_pc=0x0c04d10eu; return 0; }
r[3]=read(ram,0x0c04d194u,4);
goto P_0c04d110;
P_0c04d110: /* original 55e7, guest PC 0x0c04d110 */
if(!s->budget--) { s->failed_pc=0x0c04d110u; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c04d112;
P_0c04d112: /* original 430b, guest PC 0x0c04d112 */
if(!s->budget--) { s->failed_pc=0x0c04d112u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d116u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d116u) { target=s->pc; goto dispatch; }
goto P_0c04d116;
P_0c04d114: /* original 64d3, guest PC 0x0c04d114 */
if(!s->budget--) { s->failed_pc=0x0c04d114u; return 0; }
r[4]=r[13];
goto P_0c04d116;
P_0c04d116: /* original 4011, guest PC 0x0c04d116 */
if(!s->budget--) { s->failed_pc=0x0c04d116u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04d118;
P_0c04d118: /* original 8901, guest PC 0x0c04d118 */
if(!s->budget--) { s->failed_pc=0x0c04d118u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d11e; }
goto P_0c04d11a;
P_0c04d11a: /* original a10b, guest PC 0x0c04d11a */
if(!s->budget--) { s->failed_pc=0x0c04d11au; return 0; }
goto P_0c04d334;
P_0c04d11c: /* original 0009, guest PC 0x0c04d11c */
if(!s->budget--) { s->failed_pc=0x0c04d11cu; return 0; }
goto P_0c04d11e;
P_0c04d11e: /* original d31e, guest PC 0x0c04d11e */
if(!s->budget--) { s->failed_pc=0x0c04d11eu; return 0; }
r[3]=read(ram,0x0c04d198u,4);
goto P_0c04d120;
P_0c04d120: /* original 430b, guest PC 0x0c04d120 */
if(!s->budget--) { s->failed_pc=0x0c04d120u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d124u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d124u) { target=s->pc; goto dispatch; }
goto P_0c04d124;
P_0c04d122: /* original 64e3, guest PC 0x0c04d122 */
if(!s->budget--) { s->failed_pc=0x0c04d122u; return 0; }
r[4]=r[14];
goto P_0c04d124;
P_0c04d124: /* original 4011, guest PC 0x0c04d124 */
if(!s->budget--) { s->failed_pc=0x0c04d124u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04d126;
P_0c04d126: /* original 8901, guest PC 0x0c04d126 */
if(!s->budget--) { s->failed_pc=0x0c04d126u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d12c; }
goto P_0c04d128;
P_0c04d128: /* original a16b, guest PC 0x0c04d128 */
if(!s->budget--) { s->failed_pc=0x0c04d128u; return 0; }
r[0]=0xffffff83u;
goto P_0c04d402;
P_0c04d12a: /* original e083, guest PC 0x0c04d12a */
if(!s->budget--) { s->failed_pc=0x0c04d12au; return 0; }
r[0]=0xffffff83u;
goto P_0c04d12c;
P_0c04d12c: /* original 54e7, guest PC 0x0c04d12c */
if(!s->budget--) { s->failed_pc=0x0c04d12cu; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c04d12e;
P_0c04d12e: /* original e500, guest PC 0x0c04d12e */
if(!s->budget--) { s->failed_pc=0x0c04d12eu; return 0; }
r[5]=0x00000000u;
goto P_0c04d130;
P_0c04d130: /* original 5347, guest PC 0x0c04d130 */
if(!s->budget--) { s->failed_pc=0x0c04d130u; return 0; }
r[3]=read(ram,r[4]+28,4);
goto P_0c04d132;
P_0c04d132: /* original 143c, guest PC 0x0c04d132 */
if(!s->budget--) { s->failed_pc=0x0c04d132u; return 0; }
write(ram,r[4]+48,r[3],4);
goto P_0c04d134;
P_0c04d134: /* original 961f, guest PC 0x0c04d134 */
if(!s->budget--) { s->failed_pc=0x0c04d134u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d176u,2);
goto P_0c04d136;
P_0c04d136: /* original 4a0b, guest PC 0x0c04d136 */
if(!s->budget--) { s->failed_pc=0x0c04d136u; return 0; }
target=r[10];
r[16]=code_base|0x0c04d13au;
r[4]=read(ram,r[14]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d13au) { target=s->pc; goto dispatch; }
goto P_0c04d13a;
P_0c04d138: /* original 54e8, guest PC 0x0c04d138 */
if(!s->budget--) { s->failed_pc=0x0c04d138u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d13a;
P_0c04d13a: /* original 54e8, guest PC 0x0c04d13a */
if(!s->budget--) { s->failed_pc=0x0c04d13au; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d13c;
P_0c04d13c: /* original e620, guest PC 0x0c04d13c */
if(!s->budget--) { s->failed_pc=0x0c04d13cu; return 0; }
r[6]=0x00000020u;
goto P_0c04d13e;
P_0c04d13e: /* original 6563, guest PC 0x0c04d13e */
if(!s->budget--) { s->failed_pc=0x0c04d13eu; return 0; }
r[5]=r[6];
goto P_0c04d140;
P_0c04d140: /* original 4a0b, guest PC 0x0c04d140 */
if(!s->budget--) { s->failed_pc=0x0c04d140u; return 0; }
target=r[10];
r[16]=code_base|0x0c04d144u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d144u) { target=s->pc; goto dispatch; }
goto P_0c04d144;
P_0c04d142: /* original 7410, guest PC 0x0c04d142 */
if(!s->budget--) { s->failed_pc=0x0c04d142u; return 0; }
r[4]+=0x00000010u;
goto P_0c04d144;
P_0c04d144: /* original 55f2, guest PC 0x0c04d144 */
if(!s->budget--) { s->failed_pc=0x0c04d144u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c04d146;
P_0c04d146: /* original e400, guest PC 0x0c04d146 */
if(!s->budget--) { s->failed_pc=0x0c04d146u; return 0; }
r[4]=0x00000000u;
goto P_0c04d148;
P_0c04d148: /* original a006, guest PC 0x0c04d148 */
if(!s->budget--) { s->failed_pc=0x0c04d148u; return 0; }
r[6]=0x00000020u;
goto P_0c04d158;
P_0c04d14a: /* original e620, guest PC 0x0c04d14a */
if(!s->budget--) { s->failed_pc=0x0c04d14au; return 0; }
r[6]=0x00000020u;
goto P_0c04d14c;
P_0c04d14c: /* original 50e8, guest PC 0x0c04d14c */
if(!s->budget--) { s->failed_pc=0x0c04d14cu; return 0; }
r[0]=read(ram,r[14]+32,4);
goto P_0c04d14e;
P_0c04d14e: /* original 6243, guest PC 0x0c04d14e */
if(!s->budget--) { s->failed_pc=0x0c04d14eu; return 0; }
r[2]=r[4];
goto P_0c04d150;
P_0c04d150: /* original 6354, guest PC 0x0c04d150 */
if(!s->budget--) { s->failed_pc=0x0c04d150u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[3]=tmp;
goto P_0c04d152;
P_0c04d152: /* original 7210, guest PC 0x0c04d152 */
if(!s->budget--) { s->failed_pc=0x0c04d152u; return 0; }
r[2]+=0x00000010u;
goto P_0c04d154;
P_0c04d154: /* original 7401, guest PC 0x0c04d154 */
if(!s->budget--) { s->failed_pc=0x0c04d154u; return 0; }
r[4]+=0x00000001u;
goto P_0c04d156;
P_0c04d156: /* original 0234, guest PC 0x0c04d156 */
if(!s->budget--) { s->failed_pc=0x0c04d156u; return 0; }
write(ram,r[2]+r[0],r[3],1);
goto P_0c04d158;
P_0c04d158: /* original 3463, guest PC 0x0c04d158 */
if(!s->budget--) { s->failed_pc=0x0c04d158u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c04d15a;
P_0c04d15a: /* original 8bf7, guest PC 0x0c04d15a */
if(!s->budget--) { s->failed_pc=0x0c04d15au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d14c; }
goto P_0c04d15c;
P_0c04d15c: /* original d30f, guest PC 0x0c04d15c */
if(!s->budget--) { s->failed_pc=0x0c04d15cu; return 0; }
r[3]=read(ram,0x0c04d19cu,4);
goto P_0c04d15e;
P_0c04d15e: /* original 64f3, guest PC 0x0c04d15e */
if(!s->budget--) { s->failed_pc=0x0c04d15eu; return 0; }
r[4]=r[15];
goto P_0c04d160;
P_0c04d160: /* original 55f1, guest PC 0x0c04d160 */
if(!s->budget--) { s->failed_pc=0x0c04d160u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c04d162;
P_0c04d162: /* original 430b, guest PC 0x0c04d162 */
if(!s->budget--) { s->failed_pc=0x0c04d162u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d166u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d166u) { target=s->pc; goto dispatch; }
goto P_0c04d166;
P_0c04d164: /* original 7410, guest PC 0x0c04d164 */
if(!s->budget--) { s->failed_pc=0x0c04d164u; return 0; }
r[4]+=0x00000010u;
goto P_0c04d166;
P_0c04d166: /* original 54e8, guest PC 0x0c04d166 */
if(!s->budget--) { s->failed_pc=0x0c04d166u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d168;
P_0c04d168: /* original 67f3, guest PC 0x0c04d168 */
if(!s->budget--) { s->failed_pc=0x0c04d168u; return 0; }
r[7]=r[15];
goto P_0c04d16a;
P_0c04d16a: /* original ec00, guest PC 0x0c04d16a */
if(!s->budget--) { s->failed_pc=0x0c04d16au; return 0; }
r[12]=0x00000000u;
goto P_0c04d16c;
P_0c04d16c: /* original 7430, guest PC 0x0c04d16c */
if(!s->budget--) { s->failed_pc=0x0c04d16cu; return 0; }
r[4]+=0x00000030u;
goto P_0c04d16e;
P_0c04d16e: /* original 65c3, guest PC 0x0c04d16e */
if(!s->budget--) { s->failed_pc=0x0c04d16eu; return 0; }
r[5]=r[12];
goto P_0c04d170;
P_0c04d170: /* original 7710, guest PC 0x0c04d170 */
if(!s->budget--) { s->failed_pc=0x0c04d170u; return 0; }
r[7]+=0x00000010u;
goto P_0c04d172;
P_0c04d172: /* original a019, guest PC 0x0c04d172 */
if(!s->budget--) { s->failed_pc=0x0c04d172u; return 0; }
r[6]=0x00000008u;
goto P_0c04d1a8;
P_0c04d174: /* original e608, guest PC 0x0c04d174 */
if(!s->budget--) { s->failed_pc=0x0c04d174u; return 0; }
r[6]=0x00000008u;
if(!vf3_matrix_family(0x0c04d176u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04d176u; return 0; } return 1;
P_0c04d1a0: /* original 6374, guest PC 0x0c04d1a0 */
if(!s->budget--) { s->failed_pc=0x0c04d1a0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]+=1;
r[3]=tmp;
goto P_0c04d1a2;
P_0c04d1a2: /* original 7501, guest PC 0x0c04d1a2 */
if(!s->budget--) { s->failed_pc=0x0c04d1a2u; return 0; }
r[5]+=0x00000001u;
goto P_0c04d1a4;
P_0c04d1a4: /* original 2430, guest PC 0x0c04d1a4 */
if(!s->budget--) { s->failed_pc=0x0c04d1a4u; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04d1a6;
P_0c04d1a6: /* original 7401, guest PC 0x0c04d1a6 */
if(!s->budget--) { s->failed_pc=0x0c04d1a6u; return 0; }
r[4]+=0x00000001u;
goto P_0c04d1a8;
P_0c04d1a8: /* original 3563, guest PC 0x0c04d1a8 */
if(!s->budget--) { s->failed_pc=0x0c04d1a8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c04d1aa;
P_0c04d1aa: /* original 8bf9, guest PC 0x0c04d1aa */
if(!s->budget--) { s->failed_pc=0x0c04d1aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d1a0; }
goto P_0c04d1ac;
P_0c04d1ac: /* original 53e7, guest PC 0x0c04d1ac */
if(!s->budget--) { s->failed_pc=0x0c04d1acu; return 0; }
r[3]=read(ram,r[14]+28,4);
goto P_0c04d1ae;
P_0c04d1ae: /* original e542, guest PC 0x0c04d1ae */
if(!s->budget--) { s->failed_pc=0x0c04d1aeu; return 0; }
r[5]=0x00000042u;
goto P_0c04d1b0;
P_0c04d1b0: /* original 1f31, guest PC 0x0c04d1b0 */
if(!s->budget--) { s->failed_pc=0x0c04d1b0u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c04d1b2;
P_0c04d1b2: /* original 5233, guest PC 0x0c04d1b2 */
if(!s->budget--) { s->failed_pc=0x0c04d1b2u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c04d1b4;
P_0c04d1b4: /* original 1f22, guest PC 0x0c04d1b4 */
if(!s->budget--) { s->failed_pc=0x0c04d1b4u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c04d1b6;
P_0c04d1b6: /* original 53f1, guest PC 0x0c04d1b6 */
if(!s->budget--) { s->failed_pc=0x0c04d1b6u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c04d1b8;
P_0c04d1b8: /* original 5235, guest PC 0x0c04d1b8 */
if(!s->budget--) { s->failed_pc=0x0c04d1b8u; return 0; }
r[2]=read(ram,r[3]+20,4);
goto P_0c04d1ba;
P_0c04d1ba: /* original 1f23, guest PC 0x0c04d1ba */
if(!s->budget--) { s->failed_pc=0x0c04d1bau; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c04d1bc;
P_0c04d1bc: /* original db4d, guest PC 0x0c04d1bc */
if(!s->budget--) { s->failed_pc=0x0c04d1bcu; return 0; }
r[11]=read(ram,0x0c04d2f4u,4);
goto P_0c04d1be;
P_0c04d1be: /* original 56f1, guest PC 0x0c04d1be */
if(!s->budget--) { s->failed_pc=0x0c04d1beu; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c04d1c0;
P_0c04d1c0: /* original 63b2, guest PC 0x0c04d1c0 */
if(!s->budget--) { s->failed_pc=0x0c04d1c0u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d1c2;
P_0c04d1c2: /* original 5661, guest PC 0x0c04d1c2 */
if(!s->budget--) { s->failed_pc=0x0c04d1c2u; return 0; }
r[6]=read(ram,r[6]+4,4);
goto P_0c04d1c4;
P_0c04d1c4: /* original 5234, guest PC 0x0c04d1c4 */
if(!s->budget--) { s->failed_pc=0x0c04d1c4u; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04d1c6;
P_0c04d1c6: /* original 420b, guest PC 0x0c04d1c6 */
if(!s->budget--) { s->failed_pc=0x0c04d1c6u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d1cau;
r[4]=read(ram,r[14]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d1cau) { target=s->pc; goto dispatch; }
goto P_0c04d1ca;
P_0c04d1c8: /* original 54e8, guest PC 0x0c04d1c8 */
if(!s->budget--) { s->failed_pc=0x0c04d1c8u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d1ca;
P_0c04d1ca: /* original 62f2, guest PC 0x0c04d1ca */
if(!s->budget--) { s->failed_pc=0x0c04d1cau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04d1cc;
P_0c04d1cc: /* original e04e, guest PC 0x0c04d1cc */
if(!s->budget--) { s->failed_pc=0x0c04d1ccu; return 0; }
r[0]=0x0000004eu;
goto P_0c04d1ce;
P_0c04d1ce: /* original 53e8, guest PC 0x0c04d1ce */
if(!s->budget--) { s->failed_pc=0x0c04d1ceu; return 0; }
r[3]=read(ram,r[14]+32,4);
goto P_0c04d1d0;
P_0c04d1d0: /* original e540, guest PC 0x0c04d1d0 */
if(!s->budget--) { s->failed_pc=0x0c04d1d0u; return 0; }
r[5]=0x00000040u;
goto P_0c04d1d2;
P_0c04d1d2: /* original 0324, guest PC 0x0c04d1d2 */
if(!s->budget--) { s->failed_pc=0x0c04d1d2u; return 0; }
write(ram,r[3]+r[0],r[2],1);
goto P_0c04d1d4;
P_0c04d1d4: /* original e04f, guest PC 0x0c04d1d4 */
if(!s->budget--) { s->failed_pc=0x0c04d1d4u; return 0; }
r[0]=0x0000004fu;
goto P_0c04d1d6;
P_0c04d1d6: /* original 53e8, guest PC 0x0c04d1d6 */
if(!s->budget--) { s->failed_pc=0x0c04d1d6u; return 0; }
r[3]=read(ram,r[14]+32,4);
goto P_0c04d1d8;
P_0c04d1d8: /* original 03c4, guest PC 0x0c04d1d8 */
if(!s->budget--) { s->failed_pc=0x0c04d1d8u; return 0; }
write(ram,r[3]+r[0],r[12],1);
goto P_0c04d1da;
P_0c04d1da: /* original 56e7, guest PC 0x0c04d1da */
if(!s->budget--) { s->failed_pc=0x0c04d1dau; return 0; }
r[6]=read(ram,r[14]+28,4);
goto P_0c04d1dc;
P_0c04d1dc: /* original 63b2, guest PC 0x0c04d1dc */
if(!s->budget--) { s->failed_pc=0x0c04d1dcu; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d1de;
P_0c04d1de: /* original 6662, guest PC 0x0c04d1de */
if(!s->budget--) { s->failed_pc=0x0c04d1deu; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c04d1e0;
P_0c04d1e0: /* original 5234, guest PC 0x0c04d1e0 */
if(!s->budget--) { s->failed_pc=0x0c04d1e0u; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04d1e2;
P_0c04d1e2: /* original 420b, guest PC 0x0c04d1e2 */
if(!s->budget--) { s->failed_pc=0x0c04d1e2u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d1e6u;
r[4]=read(ram,r[14]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d1e6u) { target=s->pc; goto dispatch; }
goto P_0c04d1e6;
P_0c04d1e4: /* original 54e8, guest PC 0x0c04d1e4 */
if(!s->budget--) { s->failed_pc=0x0c04d1e4u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d1e6;
P_0c04d1e6: /* original 63b2, guest PC 0x0c04d1e6 */
if(!s->budget--) { s->failed_pc=0x0c04d1e6u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d1e8;
P_0c04d1e8: /* original e54a, guest PC 0x0c04d1e8 */
if(!s->budget--) { s->failed_pc=0x0c04d1e8u; return 0; }
r[5]=0x0000004au;
goto P_0c04d1ea;
P_0c04d1ea: /* original 56f3, guest PC 0x0c04d1ea */
if(!s->budget--) { s->failed_pc=0x0c04d1eau; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c04d1ec;
P_0c04d1ec: /* original 5234, guest PC 0x0c04d1ec */
if(!s->budget--) { s->failed_pc=0x0c04d1ecu; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04d1ee;
P_0c04d1ee: /* original 420b, guest PC 0x0c04d1ee */
if(!s->budget--) { s->failed_pc=0x0c04d1eeu; return 0; }
target=r[2];
r[16]=code_base|0x0c04d1f2u;
r[4]=read(ram,r[14]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d1f2u) { target=s->pc; goto dispatch; }
goto P_0c04d1f2;
P_0c04d1f0: /* original 54e8, guest PC 0x0c04d1f0 */
if(!s->budget--) { s->failed_pc=0x0c04d1f0u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d1f2;
P_0c04d1f2: /* original 63b2, guest PC 0x0c04d1f2 */
if(!s->budget--) { s->failed_pc=0x0c04d1f2u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d1f4;
P_0c04d1f4: /* original e546, guest PC 0x0c04d1f4 */
if(!s->budget--) { s->failed_pc=0x0c04d1f4u; return 0; }
r[5]=0x00000046u;
goto P_0c04d1f6;
P_0c04d1f6: /* original 56f2, guest PC 0x0c04d1f6 */
if(!s->budget--) { s->failed_pc=0x0c04d1f6u; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c04d1f8;
P_0c04d1f8: /* original 5234, guest PC 0x0c04d1f8 */
if(!s->budget--) { s->failed_pc=0x0c04d1f8u; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04d1fa;
P_0c04d1fa: /* original 420b, guest PC 0x0c04d1fa */
if(!s->budget--) { s->failed_pc=0x0c04d1fau; return 0; }
target=r[2];
r[16]=code_base|0x0c04d1feu;
r[4]=read(ram,r[14]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d1feu) { target=s->pc; goto dispatch; }
goto P_0c04d1fe;
P_0c04d1fc: /* original 54e8, guest PC 0x0c04d1fc */
if(!s->budget--) { s->failed_pc=0x0c04d1fcu; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d1fe;
P_0c04d1fe: /* original 56e7, guest PC 0x0c04d1fe */
if(!s->budget--) { s->failed_pc=0x0c04d1feu; return 0; }
r[6]=read(ram,r[14]+28,4);
goto P_0c04d200;
P_0c04d200: /* original e54c, guest PC 0x0c04d200 */
if(!s->budget--) { s->failed_pc=0x0c04d200u; return 0; }
r[5]=0x0000004cu;
goto P_0c04d202;
P_0c04d202: /* original 63b2, guest PC 0x0c04d202 */
if(!s->budget--) { s->failed_pc=0x0c04d202u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d204;
P_0c04d204: /* original 5666, guest PC 0x0c04d204 */
if(!s->budget--) { s->failed_pc=0x0c04d204u; return 0; }
r[6]=read(ram,r[6]+24,4);
goto P_0c04d206;
P_0c04d206: /* original 5234, guest PC 0x0c04d206 */
if(!s->budget--) { s->failed_pc=0x0c04d206u; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04d208;
P_0c04d208: /* original 420b, guest PC 0x0c04d208 */
if(!s->budget--) { s->failed_pc=0x0c04d208u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d20cu;
r[4]=read(ram,r[14]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d20cu) { target=s->pc; goto dispatch; }
goto P_0c04d20c;
P_0c04d20a: /* original 54e8, guest PC 0x0c04d20a */
if(!s->budget--) { s->failed_pc=0x0c04d20au; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d20c;
P_0c04d20c: /* original 56e7, guest PC 0x0c04d20c */
if(!s->budget--) { s->failed_pc=0x0c04d20cu; return 0; }
r[6]=read(ram,r[14]+28,4);
goto P_0c04d20e;
P_0c04d20e: /* original e548, guest PC 0x0c04d20e */
if(!s->budget--) { s->failed_pc=0x0c04d20eu; return 0; }
r[5]=0x00000048u;
goto P_0c04d210;
P_0c04d210: /* original 63b2, guest PC 0x0c04d210 */
if(!s->budget--) { s->failed_pc=0x0c04d210u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d212;
P_0c04d212: /* original 5664, guest PC 0x0c04d212 */
if(!s->budget--) { s->failed_pc=0x0c04d212u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c04d214;
P_0c04d214: /* original 5234, guest PC 0x0c04d214 */
if(!s->budget--) { s->failed_pc=0x0c04d214u; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04d216;
P_0c04d216: /* original 420b, guest PC 0x0c04d216 */
if(!s->budget--) { s->failed_pc=0x0c04d216u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d21au;
r[4]=read(ram,r[14]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d21au) { target=s->pc; goto dispatch; }
goto P_0c04d21a;
P_0c04d218: /* original 54e8, guest PC 0x0c04d218 */
if(!s->budget--) { s->failed_pc=0x0c04d218u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d21a;
P_0c04d21a: /* original 56e7, guest PC 0x0c04d21a */
if(!s->budget--) { s->failed_pc=0x0c04d21au; return 0; }
r[6]=read(ram,r[14]+28,4);
goto P_0c04d21c;
P_0c04d21c: /* original e550, guest PC 0x0c04d21c */
if(!s->budget--) { s->failed_pc=0x0c04d21cu; return 0; }
r[5]=0x00000050u;
goto P_0c04d21e;
P_0c04d21e: /* original 63b2, guest PC 0x0c04d21e */
if(!s->budget--) { s->failed_pc=0x0c04d21eu; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d220;
P_0c04d220: /* original 5667, guest PC 0x0c04d220 */
if(!s->budget--) { s->failed_pc=0x0c04d220u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c04d222;
P_0c04d222: /* original 5234, guest PC 0x0c04d222 */
if(!s->budget--) { s->failed_pc=0x0c04d222u; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04d224;
P_0c04d224: /* original 420b, guest PC 0x0c04d224 */
if(!s->budget--) { s->failed_pc=0x0c04d224u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d228u;
r[4]=read(ram,r[14]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d228u) { target=s->pc; goto dispatch; }
goto P_0c04d228;
P_0c04d226: /* original 54e8, guest PC 0x0c04d226 */
if(!s->budget--) { s->failed_pc=0x0c04d226u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d228;
P_0c04d228: /* original 56e7, guest PC 0x0c04d228 */
if(!s->budget--) { s->failed_pc=0x0c04d228u; return 0; }
r[6]=read(ram,r[14]+28,4);
goto P_0c04d22a;
P_0c04d22a: /* original e552, guest PC 0x0c04d22a */
if(!s->budget--) { s->failed_pc=0x0c04d22au; return 0; }
r[5]=0x00000052u;
goto P_0c04d22c;
P_0c04d22c: /* original 63b2, guest PC 0x0c04d22c */
if(!s->budget--) { s->failed_pc=0x0c04d22cu; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d22e;
P_0c04d22e: /* original 5668, guest PC 0x0c04d22e */
if(!s->budget--) { s->failed_pc=0x0c04d22eu; return 0; }
r[6]=read(ram,r[6]+32,4);
goto P_0c04d230;
P_0c04d230: /* original 5234, guest PC 0x0c04d230 */
if(!s->budget--) { s->failed_pc=0x0c04d230u; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04d232;
P_0c04d232: /* original 420b, guest PC 0x0c04d232 */
if(!s->budget--) { s->failed_pc=0x0c04d232u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d236u;
r[4]=read(ram,r[14]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d236u) { target=s->pc; goto dispatch; }
goto P_0c04d236;
P_0c04d234: /* original 54e8, guest PC 0x0c04d234 */
if(!s->budget--) { s->failed_pc=0x0c04d234u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d236;
P_0c04d236: /* original 56e7, guest PC 0x0c04d236 */
if(!s->budget--) { s->failed_pc=0x0c04d236u; return 0; }
r[6]=read(ram,r[14]+28,4);
goto P_0c04d238;
P_0c04d238: /* original e554, guest PC 0x0c04d238 */
if(!s->budget--) { s->failed_pc=0x0c04d238u; return 0; }
r[5]=0x00000054u;
goto P_0c04d23a;
P_0c04d23a: /* original 63b2, guest PC 0x0c04d23a */
if(!s->budget--) { s->failed_pc=0x0c04d23au; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d23c;
P_0c04d23c: /* original 566d, guest PC 0x0c04d23c */
if(!s->budget--) { s->failed_pc=0x0c04d23cu; return 0; }
r[6]=read(ram,r[6]+52,4);
goto P_0c04d23e;
P_0c04d23e: /* original 5234, guest PC 0x0c04d23e */
if(!s->budget--) { s->failed_pc=0x0c04d23eu; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04d240;
P_0c04d240: /* original 420b, guest PC 0x0c04d240 */
if(!s->budget--) { s->failed_pc=0x0c04d240u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d244u;
r[4]=read(ram,r[14]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d244u) { target=s->pc; goto dispatch; }
goto P_0c04d244;
P_0c04d242: /* original 54e8, guest PC 0x0c04d242 */
if(!s->budget--) { s->failed_pc=0x0c04d242u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d244;
P_0c04d244: /* original 56e7, guest PC 0x0c04d244 */
if(!s->budget--) { s->failed_pc=0x0c04d244u; return 0; }
r[6]=read(ram,r[14]+28,4);
goto P_0c04d246;
P_0c04d246: /* original e556, guest PC 0x0c04d246 */
if(!s->budget--) { s->failed_pc=0x0c04d246u; return 0; }
r[5]=0x00000056u;
goto P_0c04d248;
P_0c04d248: /* original 63b2, guest PC 0x0c04d248 */
if(!s->budget--) { s->failed_pc=0x0c04d248u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d24a;
P_0c04d24a: /* original 566e, guest PC 0x0c04d24a */
if(!s->budget--) { s->failed_pc=0x0c04d24au; return 0; }
r[6]=read(ram,r[6]+56,4);
goto P_0c04d24c;
P_0c04d24c: /* original 5234, guest PC 0x0c04d24c */
if(!s->budget--) { s->failed_pc=0x0c04d24cu; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04d24e;
P_0c04d24e: /* original 420b, guest PC 0x0c04d24e */
if(!s->budget--) { s->failed_pc=0x0c04d24eu; return 0; }
target=r[2];
r[16]=code_base|0x0c04d252u;
r[4]=read(ram,r[14]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d252u) { target=s->pc; goto dispatch; }
goto P_0c04d252;
P_0c04d250: /* original 54e8, guest PC 0x0c04d250 */
if(!s->budget--) { s->failed_pc=0x0c04d250u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d252;
P_0c04d252: /* original 56e7, guest PC 0x0c04d252 */
if(!s->budget--) { s->failed_pc=0x0c04d252u; return 0; }
r[6]=read(ram,r[14]+28,4);
goto P_0c04d254;
P_0c04d254: /* original e544, guest PC 0x0c04d254 */
if(!s->budget--) { s->failed_pc=0x0c04d254u; return 0; }
r[5]=0x00000044u;
goto P_0c04d256;
P_0c04d256: /* original 63b2, guest PC 0x0c04d256 */
if(!s->budget--) { s->failed_pc=0x0c04d256u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d258;
P_0c04d258: /* original 6662, guest PC 0x0c04d258 */
if(!s->budget--) { s->failed_pc=0x0c04d258u; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c04d25a;
P_0c04d25a: /* original 5234, guest PC 0x0c04d25a */
if(!s->budget--) { s->failed_pc=0x0c04d25au; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04d25c;
P_0c04d25c: /* original 420b, guest PC 0x0c04d25c */
if(!s->budget--) { s->failed_pc=0x0c04d25cu; return 0; }
target=r[2];
r[16]=code_base|0x0c04d260u;
r[4]=read(ram,r[14]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d260u) { target=s->pc; goto dispatch; }
goto P_0c04d260;
P_0c04d25e: /* original 54e8, guest PC 0x0c04d25e */
if(!s->budget--) { s->failed_pc=0x0c04d25eu; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d260;
P_0c04d260: /* original 53e7, guest PC 0x0c04d260 */
if(!s->budget--) { s->failed_pc=0x0c04d260u; return 0; }
r[3]=read(ram,r[14]+28,4);
goto P_0c04d262;
P_0c04d262: /* original 6232, guest PC 0x0c04d262 */
if(!s->budget--) { s->failed_pc=0x0c04d262u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c04d264;
P_0c04d264: /* original 2f26, guest PC 0x0c04d264 */
if(!s->budget--) { s->failed_pc=0x0c04d264u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d266;
P_0c04d266: /* original d124, guest PC 0x0c04d266 */
if(!s->budget--) { s->failed_pc=0x0c04d266u; return 0; }
r[1]=read(ram,0x0c04d2f8u,4);
goto P_0c04d268;
P_0c04d268: /* original b99a, guest PC 0x0c04d268 */
if(!s->budget--) { s->failed_pc=0x0c04d268u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04d26cu;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d26cu) { target=s->pc; goto dispatch; }
goto P_0c04d26c;
P_0c04d26a: /* original 2f16, guest PC 0x0c04d26a */
if(!s->budget--) { s->failed_pc=0x0c04d26au; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d26c;
P_0c04d26c: /* original 52e7, guest PC 0x0c04d26c */
if(!s->budget--) { s->failed_pc=0x0c04d26cu; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04d26e;
P_0c04d26e: /* original 532b, guest PC 0x0c04d26e */
if(!s->budget--) { s->failed_pc=0x0c04d26eu; return 0; }
r[3]=read(ram,r[2]+44,4);
goto P_0c04d270;
P_0c04d270: /* original 2f36, guest PC 0x0c04d270 */
if(!s->budget--) { s->failed_pc=0x0c04d270u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d272;
P_0c04d272: /* original d122, guest PC 0x0c04d272 */
if(!s->budget--) { s->failed_pc=0x0c04d272u; return 0; }
r[1]=read(ram,0x0c04d2fcu,4);
goto P_0c04d274;
P_0c04d274: /* original b994, guest PC 0x0c04d274 */
if(!s->budget--) { s->failed_pc=0x0c04d274u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04d278u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d278u) { target=s->pc; goto dispatch; }
goto P_0c04d278;
P_0c04d276: /* original 2f16, guest PC 0x0c04d276 */
if(!s->budget--) { s->failed_pc=0x0c04d276u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d278;
P_0c04d278: /* original 52e7, guest PC 0x0c04d278 */
if(!s->budget--) { s->failed_pc=0x0c04d278u; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04d27a;
P_0c04d27a: /* original 5323, guest PC 0x0c04d27a */
if(!s->budget--) { s->failed_pc=0x0c04d27au; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c04d27c;
P_0c04d27c: /* original 2f36, guest PC 0x0c04d27c */
if(!s->budget--) { s->failed_pc=0x0c04d27cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d27e;
P_0c04d27e: /* original d120, guest PC 0x0c04d27e */
if(!s->budget--) { s->failed_pc=0x0c04d27eu; return 0; }
r[1]=read(ram,0x0c04d300u,4);
goto P_0c04d280;
P_0c04d280: /* original b98e, guest PC 0x0c04d280 */
if(!s->budget--) { s->failed_pc=0x0c04d280u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04d284u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d284u) { target=s->pc; goto dispatch; }
goto P_0c04d284;
P_0c04d282: /* original 2f16, guest PC 0x0c04d282 */
if(!s->budget--) { s->failed_pc=0x0c04d282u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d284;
P_0c04d284: /* original 52e7, guest PC 0x0c04d284 */
if(!s->budget--) { s->failed_pc=0x0c04d284u; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04d286;
P_0c04d286: /* original 5324, guest PC 0x0c04d286 */
if(!s->budget--) { s->failed_pc=0x0c04d286u; return 0; }
r[3]=read(ram,r[2]+16,4);
goto P_0c04d288;
P_0c04d288: /* original 2f36, guest PC 0x0c04d288 */
if(!s->budget--) { s->failed_pc=0x0c04d288u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d28a;
P_0c04d28a: /* original d11e, guest PC 0x0c04d28a */
if(!s->budget--) { s->failed_pc=0x0c04d28au; return 0; }
r[1]=read(ram,0x0c04d304u,4);
goto P_0c04d28c;
P_0c04d28c: /* original b988, guest PC 0x0c04d28c */
if(!s->budget--) { s->failed_pc=0x0c04d28cu; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04d290u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d290u) { target=s->pc; goto dispatch; }
goto P_0c04d290;
P_0c04d28e: /* original 2f16, guest PC 0x0c04d28e */
if(!s->budget--) { s->failed_pc=0x0c04d28eu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d290;
P_0c04d290: /* original 52e7, guest PC 0x0c04d290 */
if(!s->budget--) { s->failed_pc=0x0c04d290u; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04d292;
P_0c04d292: /* original 5325, guest PC 0x0c04d292 */
if(!s->budget--) { s->failed_pc=0x0c04d292u; return 0; }
r[3]=read(ram,r[2]+20,4);
goto P_0c04d294;
P_0c04d294: /* original 2f36, guest PC 0x0c04d294 */
if(!s->budget--) { s->failed_pc=0x0c04d294u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d296;
P_0c04d296: /* original d11c, guest PC 0x0c04d296 */
if(!s->budget--) { s->failed_pc=0x0c04d296u; return 0; }
r[1]=read(ram,0x0c04d308u,4);
goto P_0c04d298;
P_0c04d298: /* original b982, guest PC 0x0c04d298 */
if(!s->budget--) { s->failed_pc=0x0c04d298u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04d29cu;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d29cu) { target=s->pc; goto dispatch; }
goto P_0c04d29c;
P_0c04d29a: /* original 2f16, guest PC 0x0c04d29a */
if(!s->budget--) { s->failed_pc=0x0c04d29au; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d29c;
P_0c04d29c: /* original 52e7, guest PC 0x0c04d29c */
if(!s->budget--) { s->failed_pc=0x0c04d29cu; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04d29e;
P_0c04d29e: /* original 5326, guest PC 0x0c04d29e */
if(!s->budget--) { s->failed_pc=0x0c04d29eu; return 0; }
r[3]=read(ram,r[2]+24,4);
goto P_0c04d2a0;
P_0c04d2a0: /* original 2f36, guest PC 0x0c04d2a0 */
if(!s->budget--) { s->failed_pc=0x0c04d2a0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d2a2;
P_0c04d2a2: /* original d11a, guest PC 0x0c04d2a2 */
if(!s->budget--) { s->failed_pc=0x0c04d2a2u; return 0; }
r[1]=read(ram,0x0c04d30cu,4);
goto P_0c04d2a4;
P_0c04d2a4: /* original b97c, guest PC 0x0c04d2a4 */
if(!s->budget--) { s->failed_pc=0x0c04d2a4u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04d2a8u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d2a8u) { target=s->pc; goto dispatch; }
goto P_0c04d2a8;
P_0c04d2a6: /* original 2f16, guest PC 0x0c04d2a6 */
if(!s->budget--) { s->failed_pc=0x0c04d2a6u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d2a8;
P_0c04d2a8: /* original 52e7, guest PC 0x0c04d2a8 */
if(!s->budget--) { s->failed_pc=0x0c04d2a8u; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04d2aa;
P_0c04d2aa: /* original 5321, guest PC 0x0c04d2aa */
if(!s->budget--) { s->failed_pc=0x0c04d2aau; return 0; }
r[3]=read(ram,r[2]+4,4);
goto P_0c04d2ac;
P_0c04d2ac: /* original 2f36, guest PC 0x0c04d2ac */
if(!s->budget--) { s->failed_pc=0x0c04d2acu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d2ae;
P_0c04d2ae: /* original d118, guest PC 0x0c04d2ae */
if(!s->budget--) { s->failed_pc=0x0c04d2aeu; return 0; }
r[1]=read(ram,0x0c04d310u,4);
goto P_0c04d2b0;
P_0c04d2b0: /* original b976, guest PC 0x0c04d2b0 */
if(!s->budget--) { s->failed_pc=0x0c04d2b0u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04d2b4u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d2b4u) { target=s->pc; goto dispatch; }
goto P_0c04d2b4;
P_0c04d2b2: /* original 2f16, guest PC 0x0c04d2b2 */
if(!s->budget--) { s->failed_pc=0x0c04d2b2u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d2b4;
P_0c04d2b4: /* original 52fe, guest PC 0x0c04d2b4 */
if(!s->budget--) { s->failed_pc=0x0c04d2b4u; return 0; }
r[2]=read(ram,r[15]+56,4);
goto P_0c04d2b6;
P_0c04d2b6: /* original 2f26, guest PC 0x0c04d2b6 */
if(!s->budget--) { s->failed_pc=0x0c04d2b6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d2b8;
P_0c04d2b8: /* original d316, guest PC 0x0c04d2b8 */
if(!s->budget--) { s->failed_pc=0x0c04d2b8u; return 0; }
r[3]=read(ram,0x0c04d314u,4);
goto P_0c04d2ba;
P_0c04d2ba: /* original b971, guest PC 0x0c04d2ba */
if(!s->budget--) { s->failed_pc=0x0c04d2bau; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04d2beu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d2beu) { target=s->pc; goto dispatch; }
goto P_0c04d2be;
P_0c04d2bc: /* original 2f36, guest PC 0x0c04d2bc */
if(!s->budget--) { s->failed_pc=0x0c04d2bcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d2be;
P_0c04d2be: /* original e100, guest PC 0x0c04d2be */
if(!s->budget--) { s->failed_pc=0x0c04d2beu; return 0; }
r[1]=0x00000000u;
goto P_0c04d2c0;
P_0c04d2c0: /* original 2f16, guest PC 0x0c04d2c0 */
if(!s->budget--) { s->failed_pc=0x0c04d2c0u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d2c2;
P_0c04d2c2: /* original d315, guest PC 0x0c04d2c2 */
if(!s->budget--) { s->failed_pc=0x0c04d2c2u; return 0; }
r[3]=read(ram,0x0c04d318u,4);
goto P_0c04d2c4;
P_0c04d2c4: /* original b96c, guest PC 0x0c04d2c4 */
if(!s->budget--) { s->failed_pc=0x0c04d2c4u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04d2c8u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d2c8u) { target=s->pc; goto dispatch; }
goto P_0c04d2c8;
P_0c04d2c6: /* original 2f36, guest PC 0x0c04d2c6 */
if(!s->budget--) { s->failed_pc=0x0c04d2c6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d2c8;
P_0c04d2c8: /* original 9613, guest PC 0x0c04d2c8 */
if(!s->budget--) { s->failed_pc=0x0c04d2c8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d2f2u,2);
goto P_0c04d2ca;
P_0c04d2ca: /* original e500, guest PC 0x0c04d2ca */
if(!s->budget--) { s->failed_pc=0x0c04d2cau; return 0; }
r[5]=0x00000000u;
goto P_0c04d2cc;
P_0c04d2cc: /* original 7f48, guest PC 0x0c04d2cc */
if(!s->budget--) { s->failed_pc=0x0c04d2ccu; return 0; }
r[15]+=0x00000048u;
goto P_0c04d2ce;
P_0c04d2ce: /* original 4a0b, guest PC 0x0c04d2ce */
if(!s->budget--) { s->failed_pc=0x0c04d2ceu; return 0; }
target=r[10];
r[16]=code_base|0x0c04d2d2u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d2d2u) { target=s->pc; goto dispatch; }
goto P_0c04d2d2;
P_0c04d2d0: /* original 6493, guest PC 0x0c04d2d0 */
if(!s->budget--) { s->failed_pc=0x0c04d2d0u; return 0; }
r[4]=r[9];
goto P_0c04d2d2;
P_0c04d2d2: /* original a042, guest PC 0x0c04d2d2 */
if(!s->budget--) { s->failed_pc=0x0c04d2d2u; return 0; }
r[11]=0x00000000u;
goto P_0c04d35a;
P_0c04d2d4: /* original eb00, guest PC 0x0c04d2d4 */
if(!s->budget--) { s->failed_pc=0x0c04d2d4u; return 0; }
r[11]=0x00000000u;
goto P_0c04d2d6;
P_0c04d2d6: /* original 2fb6, guest PC 0x0c04d2d6 */
if(!s->budget--) { s->failed_pc=0x0c04d2d6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d2d8;
P_0c04d2d8: /* original d210, guest PC 0x0c04d2d8 */
if(!s->budget--) { s->failed_pc=0x0c04d2d8u; return 0; }
r[2]=read(ram,0x0c04d31cu,4);
goto P_0c04d2da;
P_0c04d2da: /* original b961, guest PC 0x0c04d2da */
if(!s->budget--) { s->failed_pc=0x0c04d2dau; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04d2deu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d2deu) { target=s->pc; goto dispatch; }
goto P_0c04d2de;
P_0c04d2dc: /* original 2f26, guest PC 0x0c04d2dc */
if(!s->budget--) { s->failed_pc=0x0c04d2dcu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d2de;
P_0c04d2de: /* original 7f08, guest PC 0x0c04d2de */
if(!s->budget--) { s->failed_pc=0x0c04d2deu; return 0; }
r[15]+=0x00000008u;
goto P_0c04d2e0;
P_0c04d2e0: /* original 51ff, guest PC 0x0c04d2e0 */
if(!s->budget--) { s->failed_pc=0x0c04d2e0u; return 0; }
r[1]=read(ram,r[15]+60,4);
goto P_0c04d2e2;
P_0c04d2e2: /* original 2118, guest PC 0x0c04d2e2 */
if(!s->budget--) { s->failed_pc=0x0c04d2e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c04d2e4;
P_0c04d2e4: /* original 891c, guest PC 0x0c04d2e4 */
if(!s->budget--) { s->failed_pc=0x0c04d2e4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d320; }
goto P_0c04d2e6;
P_0c04d2e6: /* original 65b3, guest PC 0x0c04d2e6 */
if(!s->budget--) { s->failed_pc=0x0c04d2e6u; return 0; }
r[5]=r[11];
goto P_0c04d2e8;
P_0c04d2e8: /* original 6693, guest PC 0x0c04d2e8 */
if(!s->budget--) { s->failed_pc=0x0c04d2e8u; return 0; }
r[6]=r[9];
goto P_0c04d2ea;
P_0c04d2ea: /* original 480b, guest PC 0x0c04d2ea */
if(!s->budget--) { s->failed_pc=0x0c04d2eau; return 0; }
target=r[8];
r[16]=code_base|0x0c04d2eeu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d2eeu) { target=s->pc; goto dispatch; }
goto P_0c04d2ee;
P_0c04d2ec: /* original 64d3, guest PC 0x0c04d2ec */
if(!s->budget--) { s->failed_pc=0x0c04d2ecu; return 0; }
r[4]=r[13];
goto P_0c04d2ee;
P_0c04d2ee: /* original a018, guest PC 0x0c04d2ee */
if(!s->budget--) { s->failed_pc=0x0c04d2eeu; return 0; }
r[4]=r[0];
goto P_0c04d322;
P_0c04d2f0: /* original 6403, guest PC 0x0c04d2f0 */
if(!s->budget--) { s->failed_pc=0x0c04d2f0u; return 0; }
r[4]=r[0];
if(!vf3_matrix_family(0x0c04d2f2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04d2f2u; return 0; } return 1;
P_0c04d320: /* original 64c3, guest PC 0x0c04d320 */
if(!s->budget--) { s->failed_pc=0x0c04d320u; return 0; }
r[4]=r[12];
goto P_0c04d322;
P_0c04d322: /* original 9179, guest PC 0x0c04d322 */
if(!s->budget--) { s->failed_pc=0x0c04d322u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d418u,2);
goto P_0c04d324;
P_0c04d324: /* original 6043, guest PC 0x0c04d324 */
if(!s->budget--) { s->failed_pc=0x0c04d324u; return 0; }
r[0]=r[4];
goto P_0c04d326;
P_0c04d326: /* original 3010, guest PC 0x0c04d326 */
if(!s->budget--) { s->failed_pc=0x0c04d326u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04d328;
P_0c04d328: /* original 8904, guest PC 0x0c04d328 */
if(!s->budget--) { s->failed_pc=0x0c04d328u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d334; }
goto P_0c04d32a;
P_0c04d32a: /* original 9176, guest PC 0x0c04d32a */
if(!s->budget--) { s->failed_pc=0x0c04d32au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d41au,2);
goto P_0c04d32c;
P_0c04d32c: /* original 3010, guest PC 0x0c04d32c */
if(!s->budget--) { s->failed_pc=0x0c04d32cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04d32e;
P_0c04d32e: /* original 8904, guest PC 0x0c04d32e */
if(!s->budget--) { s->failed_pc=0x0c04d32eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d33a; }
goto P_0c04d330;
P_0c04d330: /* original a009, guest PC 0x0c04d330 */
if(!s->budget--) { s->failed_pc=0x0c04d330u; return 0; }
goto P_0c04d346;
P_0c04d332: /* original 0009, guest PC 0x0c04d332 */
if(!s->budget--) { s->failed_pc=0x0c04d332u; return 0; }
goto P_0c04d334;
P_0c04d334: /* original 9070, guest PC 0x0c04d334 */
if(!s->budget--) { s->failed_pc=0x0c04d334u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d418u,2);
goto P_0c04d336;
P_0c04d336: /* original a064, guest PC 0x0c04d336 */
if(!s->budget--) { s->failed_pc=0x0c04d336u; return 0; }
goto P_0c04d402;
P_0c04d338: /* original 0009, guest PC 0x0c04d338 */
if(!s->budget--) { s->failed_pc=0x0c04d338u; return 0; }
goto P_0c04d33a;
P_0c04d33a: /* original d238, guest PC 0x0c04d33a */
if(!s->budget--) { s->failed_pc=0x0c04d33au; return 0; }
r[2]=read(ram,0x0c04d41cu,4);
goto P_0c04d33c;
P_0c04d33c: /* original b930, guest PC 0x0c04d33c */
if(!s->budget--) { s->failed_pc=0x0c04d33cu; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04d340u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d340u) { target=s->pc; goto dispatch; }
goto P_0c04d340;
P_0c04d33e: /* original 2f26, guest PC 0x0c04d33e */
if(!s->budget--) { s->failed_pc=0x0c04d33eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d340;
P_0c04d340: /* original d637, guest PC 0x0c04d340 */
if(!s->budget--) { s->failed_pc=0x0c04d340u; return 0; }
r[6]=read(ram,0x0c04d420u,4);
goto P_0c04d342;
P_0c04d342: /* original a005, guest PC 0x0c04d342 */
if(!s->budget--) { s->failed_pc=0x0c04d342u; return 0; }
r[15]+=0x00000004u;
goto P_0c04d350;
P_0c04d344: /* original 7f04, guest PC 0x0c04d344 */
if(!s->budget--) { s->failed_pc=0x0c04d344u; return 0; }
r[15]+=0x00000004u;
goto P_0c04d346;
P_0c04d346: /* original d237, guest PC 0x0c04d346 */
if(!s->budget--) { s->failed_pc=0x0c04d346u; return 0; }
r[2]=read(ram,0x0c04d424u,4);
goto P_0c04d348;
P_0c04d348: /* original b92a, guest PC 0x0c04d348 */
if(!s->budget--) { s->failed_pc=0x0c04d348u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04d34cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d34cu) { target=s->pc; goto dispatch; }
goto P_0c04d34c;
P_0c04d34a: /* original 2f26, guest PC 0x0c04d34a */
if(!s->budget--) { s->failed_pc=0x0c04d34au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d34c;
P_0c04d34c: /* original d636, guest PC 0x0c04d34c */
if(!s->budget--) { s->failed_pc=0x0c04d34cu; return 0; }
r[6]=read(ram,0x0c04d428u,4);
goto P_0c04d34e;
P_0c04d34e: /* original 7f04, guest PC 0x0c04d34e */
if(!s->budget--) { s->failed_pc=0x0c04d34eu; return 0; }
r[15]+=0x00000004u;
goto P_0c04d350;
P_0c04d350: /* original d236, guest PC 0x0c04d350 */
if(!s->budget--) { s->failed_pc=0x0c04d350u; return 0; }
r[2]=read(ram,0x0c04d42cu,4);
goto P_0c04d352;
P_0c04d352: /* original 65b3, guest PC 0x0c04d352 */
if(!s->budget--) { s->failed_pc=0x0c04d352u; return 0; }
r[5]=r[11];
goto P_0c04d354;
P_0c04d354: /* original 420b, guest PC 0x0c04d354 */
if(!s->budget--) { s->failed_pc=0x0c04d354u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d358u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d358u) { target=s->pc; goto dispatch; }
goto P_0c04d358;
P_0c04d356: /* original 64d3, guest PC 0x0c04d356 */
if(!s->budget--) { s->failed_pc=0x0c04d356u; return 0; }
r[4]=r[13];
goto P_0c04d358;
P_0c04d358: /* original 7b01, guest PC 0x0c04d358 */
if(!s->budget--) { s->failed_pc=0x0c04d358u; return 0; }
r[11]+=0x00000001u;
goto P_0c04d35a;
P_0c04d35a: /* original 53e7, guest PC 0x0c04d35a */
if(!s->budget--) { s->failed_pc=0x0c04d35au; return 0; }
r[3]=read(ram,r[14]+28,4);
goto P_0c04d35c;
P_0c04d35c: /* original 6232, guest PC 0x0c04d35c */
if(!s->budget--) { s->failed_pc=0x0c04d35cu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c04d35e;
P_0c04d35e: /* original 3b23, guest PC 0x0c04d35e */
if(!s->budget--) { s->failed_pc=0x0c04d35eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[2])!=0);
goto P_0c04d360;
P_0c04d360: /* original 8bb9, guest PC 0x0c04d360 */
if(!s->budget--) { s->failed_pc=0x0c04d360u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d2d6; }
goto P_0c04d362;
P_0c04d362: /* original 55e7, guest PC 0x0c04d362 */
if(!s->budget--) { s->failed_pc=0x0c04d362u; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c04d364;
P_0c04d364: /* original 5256, guest PC 0x0c04d364 */
if(!s->budget--) { s->failed_pc=0x0c04d364u; return 0; }
r[2]=read(ram,r[5]+24,4);
goto P_0c04d366;
P_0c04d366: /* original 545c, guest PC 0x0c04d366 */
if(!s->budget--) { s->failed_pc=0x0c04d366u; return 0; }
r[4]=read(ram,r[5]+48,4);
goto P_0c04d368;
P_0c04d368: /* original 2f22, guest PC 0x0c04d368 */
if(!s->budget--) { s->failed_pc=0x0c04d368u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c04d36a;
P_0c04d36a: /* original 2f46, guest PC 0x0c04d36a */
if(!s->budget--) { s->failed_pc=0x0c04d36au; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d36c;
P_0c04d36c: /* original d330, guest PC 0x0c04d36c */
if(!s->budget--) { s->failed_pc=0x0c04d36cu; return 0; }
r[3]=read(ram,0x0c04d430u,4);
goto P_0c04d36e;
P_0c04d36e: /* original b917, guest PC 0x0c04d36e */
if(!s->budget--) { s->failed_pc=0x0c04d36eu; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04d372u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d372u) { target=s->pc; goto dispatch; }
goto P_0c04d372;
P_0c04d370: /* original 2f36, guest PC 0x0c04d370 */
if(!s->budget--) { s->failed_pc=0x0c04d370u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d372;
P_0c04d372: /* original 7f08, guest PC 0x0c04d372 */
if(!s->budget--) { s->failed_pc=0x0c04d372u; return 0; }
r[15]+=0x00000008u;
goto P_0c04d374;
P_0c04d374: /* original 66f2, guest PC 0x0c04d374 */
if(!s->budget--) { s->failed_pc=0x0c04d374u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c04d376;
P_0c04d376: /* original e500, guest PC 0x0c04d376 */
if(!s->budget--) { s->failed_pc=0x0c04d376u; return 0; }
r[5]=0x00000000u;
goto P_0c04d378;
P_0c04d378: /* original 4618, guest PC 0x0c04d378 */
if(!s->budget--) { s->failed_pc=0x0c04d378u; return 0; }
r[6]<<=8;
goto P_0c04d37a;
P_0c04d37a: /* original 4600, guest PC 0x0c04d37a */
if(!s->budget--) { s->failed_pc=0x0c04d37au; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c04d37c;
P_0c04d37c: /* original 4a0b, guest PC 0x0c04d37c */
if(!s->budget--) { s->failed_pc=0x0c04d37cu; return 0; }
target=r[10];
r[16]=code_base|0x0c04d380u;
r[4]=read(ram,r[14]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d380u) { target=s->pc; goto dispatch; }
goto P_0c04d380;
P_0c04d37e: /* original 54ea, guest PC 0x0c04d37e */
if(!s->budget--) { s->failed_pc=0x0c04d37eu; return 0; }
r[4]=read(ram,r[14]+40,4);
goto P_0c04d380;
P_0c04d380: /* original d32c, guest PC 0x0c04d380 */
if(!s->budget--) { s->failed_pc=0x0c04d380u; return 0; }
r[3]=read(ram,0x0c04d434u,4);
goto P_0c04d382;
P_0c04d382: /* original 430b, guest PC 0x0c04d382 */
if(!s->budget--) { s->failed_pc=0x0c04d382u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d386u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d386u) { target=s->pc; goto dispatch; }
goto P_0c04d386;
P_0c04d384: /* original 64d3, guest PC 0x0c04d384 */
if(!s->budget--) { s->failed_pc=0x0c04d384u; return 0; }
r[4]=r[13];
goto P_0c04d386;
P_0c04d386: /* original 55e7, guest PC 0x0c04d386 */
if(!s->budget--) { s->failed_pc=0x0c04d386u; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c04d388;
P_0c04d388: /* original db2b, guest PC 0x0c04d388 */
if(!s->budget--) { s->failed_pc=0x0c04d388u; return 0; }
r[11]=read(ram,0x0c04d438u,4);
goto P_0c04d38a;
P_0c04d38a: /* original d328, guest PC 0x0c04d38a */
if(!s->budget--) { s->failed_pc=0x0c04d38au; return 0; }
r[3]=read(ram,0x0c04d42cu,4);
goto P_0c04d38c;
P_0c04d38c: /* original 5552, guest PC 0x0c04d38c */
if(!s->budget--) { s->failed_pc=0x0c04d38cu; return 0; }
r[5]=read(ram,r[5]+8,4);
goto P_0c04d38e;
P_0c04d38e: /* original 66b3, guest PC 0x0c04d38e */
if(!s->budget--) { s->failed_pc=0x0c04d38eu; return 0; }
r[6]=r[11];
goto P_0c04d390;
P_0c04d390: /* original 430b, guest PC 0x0c04d390 */
if(!s->budget--) { s->failed_pc=0x0c04d390u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d394u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d394u) { target=s->pc; goto dispatch; }
goto P_0c04d394;
P_0c04d392: /* original 64d3, guest PC 0x0c04d392 */
if(!s->budget--) { s->failed_pc=0x0c04d392u; return 0; }
r[4]=r[13];
goto P_0c04d394;
P_0c04d394: /* original a008, guest PC 0x0c04d394 */
if(!s->budget--) { s->failed_pc=0x0c04d394u; return 0; }
r[9]=0x00000000u;
goto P_0c04d3a8;
P_0c04d396: /* original e900, guest PC 0x0c04d396 */
if(!s->budget--) { s->failed_pc=0x0c04d396u; return 0; }
r[9]=0x00000000u;
goto P_0c04d398;
P_0c04d398: /* original 55e7, guest PC 0x0c04d398 */
if(!s->budget--) { s->failed_pc=0x0c04d398u; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c04d39a;
P_0c04d39a: /* original 66b3, guest PC 0x0c04d39a */
if(!s->budget--) { s->failed_pc=0x0c04d39au; return 0; }
r[6]=r[11];
goto P_0c04d39c;
P_0c04d39c: /* original d323, guest PC 0x0c04d39c */
if(!s->budget--) { s->failed_pc=0x0c04d39cu; return 0; }
r[3]=read(ram,0x0c04d42cu,4);
goto P_0c04d39e;
P_0c04d39e: /* original 5553, guest PC 0x0c04d39e */
if(!s->budget--) { s->failed_pc=0x0c04d39eu; return 0; }
r[5]=read(ram,r[5]+12,4);
goto P_0c04d3a0;
P_0c04d3a0: /* original 359c, guest PC 0x0c04d3a0 */
if(!s->budget--) { s->failed_pc=0x0c04d3a0u; return 0; }
r[5]+=r[9];
goto P_0c04d3a2;
P_0c04d3a2: /* original 430b, guest PC 0x0c04d3a2 */
if(!s->budget--) { s->failed_pc=0x0c04d3a2u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d3a6u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d3a6u) { target=s->pc; goto dispatch; }
goto P_0c04d3a6;
P_0c04d3a4: /* original 64d3, guest PC 0x0c04d3a4 */
if(!s->budget--) { s->failed_pc=0x0c04d3a4u; return 0; }
r[4]=r[13];
goto P_0c04d3a6;
P_0c04d3a6: /* original 7901, guest PC 0x0c04d3a6 */
if(!s->budget--) { s->failed_pc=0x0c04d3a6u; return 0; }
r[9]+=0x00000001u;
goto P_0c04d3a8;
P_0c04d3a8: /* original 52e7, guest PC 0x0c04d3a8 */
if(!s->budget--) { s->failed_pc=0x0c04d3a8u; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04d3aa;
P_0c04d3aa: /* original 5324, guest PC 0x0c04d3aa */
if(!s->budget--) { s->failed_pc=0x0c04d3aau; return 0; }
r[3]=read(ram,r[2]+16,4);
goto P_0c04d3ac;
P_0c04d3ac: /* original 3933, guest PC 0x0c04d3ac */
if(!s->budget--) { s->failed_pc=0x0c04d3acu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[3])!=0);
goto P_0c04d3ae;
P_0c04d3ae: /* original 8bf3, guest PC 0x0c04d3ae */
if(!s->budget--) { s->failed_pc=0x0c04d3aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d398; }
goto P_0c04d3b0;
P_0c04d3b0: /* original 55e7, guest PC 0x0c04d3b0 */
if(!s->budget--) { s->failed_pc=0x0c04d3b0u; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c04d3b2;
P_0c04d3b2: /* original 66b3, guest PC 0x0c04d3b2 */
if(!s->budget--) { s->failed_pc=0x0c04d3b2u; return 0; }
r[6]=r[11];
goto P_0c04d3b4;
P_0c04d3b4: /* original d31d, guest PC 0x0c04d3b4 */
if(!s->budget--) { s->failed_pc=0x0c04d3b4u; return 0; }
r[3]=read(ram,0x0c04d42cu,4);
goto P_0c04d3b6;
P_0c04d3b6: /* original 5552, guest PC 0x0c04d3b6 */
if(!s->budget--) { s->failed_pc=0x0c04d3b6u; return 0; }
r[5]=read(ram,r[5]+8,4);
goto P_0c04d3b8;
P_0c04d3b8: /* original 430b, guest PC 0x0c04d3b8 */
if(!s->budget--) { s->failed_pc=0x0c04d3b8u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d3bcu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d3bcu) { target=s->pc; goto dispatch; }
goto P_0c04d3bc;
P_0c04d3ba: /* original 64d3, guest PC 0x0c04d3ba */
if(!s->budget--) { s->failed_pc=0x0c04d3bau; return 0; }
r[4]=r[13];
goto P_0c04d3bc;
P_0c04d3bc: /* original a008, guest PC 0x0c04d3bc */
if(!s->budget--) { s->failed_pc=0x0c04d3bcu; return 0; }
r[9]=r[12];
goto P_0c04d3d0;
P_0c04d3be: /* original 69c3, guest PC 0x0c04d3be */
if(!s->budget--) { s->failed_pc=0x0c04d3beu; return 0; }
r[9]=r[12];
goto P_0c04d3c0;
P_0c04d3c0: /* original 55e7, guest PC 0x0c04d3c0 */
if(!s->budget--) { s->failed_pc=0x0c04d3c0u; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c04d3c2;
P_0c04d3c2: /* original 66b3, guest PC 0x0c04d3c2 */
if(!s->budget--) { s->failed_pc=0x0c04d3c2u; return 0; }
r[6]=r[11];
goto P_0c04d3c4;
P_0c04d3c4: /* original d319, guest PC 0x0c04d3c4 */
if(!s->budget--) { s->failed_pc=0x0c04d3c4u; return 0; }
r[3]=read(ram,0x0c04d42cu,4);
goto P_0c04d3c6;
P_0c04d3c6: /* original 5553, guest PC 0x0c04d3c6 */
if(!s->budget--) { s->failed_pc=0x0c04d3c6u; return 0; }
r[5]=read(ram,r[5]+12,4);
goto P_0c04d3c8;
P_0c04d3c8: /* original 359c, guest PC 0x0c04d3c8 */
if(!s->budget--) { s->failed_pc=0x0c04d3c8u; return 0; }
r[5]+=r[9];
goto P_0c04d3ca;
P_0c04d3ca: /* original 430b, guest PC 0x0c04d3ca */
if(!s->budget--) { s->failed_pc=0x0c04d3cau; return 0; }
target=r[3];
r[16]=code_base|0x0c04d3ceu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d3ceu) { target=s->pc; goto dispatch; }
goto P_0c04d3ce;
P_0c04d3cc: /* original 64d3, guest PC 0x0c04d3cc */
if(!s->budget--) { s->failed_pc=0x0c04d3ccu; return 0; }
r[4]=r[13];
goto P_0c04d3ce;
P_0c04d3ce: /* original 7901, guest PC 0x0c04d3ce */
if(!s->budget--) { s->failed_pc=0x0c04d3ceu; return 0; }
r[9]+=0x00000001u;
goto P_0c04d3d0;
P_0c04d3d0: /* original 52e7, guest PC 0x0c04d3d0 */
if(!s->budget--) { s->failed_pc=0x0c04d3d0u; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04d3d2;
P_0c04d3d2: /* original 5324, guest PC 0x0c04d3d2 */
if(!s->budget--) { s->failed_pc=0x0c04d3d2u; return 0; }
r[3]=read(ram,r[2]+16,4);
goto P_0c04d3d4;
P_0c04d3d4: /* original 3933, guest PC 0x0c04d3d4 */
if(!s->budget--) { s->failed_pc=0x0c04d3d4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[3])!=0);
goto P_0c04d3d6;
P_0c04d3d6: /* original 8bf3, guest PC 0x0c04d3d6 */
if(!s->budget--) { s->failed_pc=0x0c04d3d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d3c0; }
goto P_0c04d3d8;
P_0c04d3d8: /* original d318, guest PC 0x0c04d3d8 */
if(!s->budget--) { s->failed_pc=0x0c04d3d8u; return 0; }
r[3]=read(ram,0x0c04d43cu,4);
goto P_0c04d3da;
P_0c04d3da: /* original 430b, guest PC 0x0c04d3da */
if(!s->budget--) { s->failed_pc=0x0c04d3dau; return 0; }
target=r[3];
r[16]=code_base|0x0c04d3deu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d3deu) { target=s->pc; goto dispatch; }
goto P_0c04d3de;
P_0c04d3dc: /* original 64d3, guest PC 0x0c04d3dc */
if(!s->budget--) { s->failed_pc=0x0c04d3dcu; return 0; }
r[4]=r[13];
goto P_0c04d3de;
P_0c04d3de: /* original e555, guest PC 0x0c04d3de */
if(!s->budget--) { s->failed_pc=0x0c04d3deu; return 0; }
r[5]=0x00000055u;
goto P_0c04d3e0;
P_0c04d3e0: /* original e610, guest PC 0x0c04d3e0 */
if(!s->budget--) { s->failed_pc=0x0c04d3e0u; return 0; }
r[6]=0x00000010u;
goto P_0c04d3e2;
P_0c04d3e2: /* original 4a0b, guest PC 0x0c04d3e2 */
if(!s->budget--) { s->failed_pc=0x0c04d3e2u; return 0; }
target=r[10];
r[16]=code_base|0x0c04d3e6u;
r[4]=read(ram,r[14]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d3e6u) { target=s->pc; goto dispatch; }
goto P_0c04d3e6;
P_0c04d3e4: /* original 54e8, guest PC 0x0c04d3e4 */
if(!s->budget--) { s->failed_pc=0x0c04d3e4u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d3e6;
P_0c04d3e6: /* original d216, guest PC 0x0c04d3e6 */
if(!s->budget--) { s->failed_pc=0x0c04d3e6u; return 0; }
r[2]=read(ram,0x0c04d440u,4);
goto P_0c04d3e8;
P_0c04d3e8: /* original 420b, guest PC 0x0c04d3e8 */
if(!s->budget--) { s->failed_pc=0x0c04d3e8u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d3ecu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d3ecu) { target=s->pc; goto dispatch; }
goto P_0c04d3ec;
P_0c04d3ea: /* original 64d3, guest PC 0x0c04d3ea */
if(!s->budget--) { s->failed_pc=0x0c04d3eau; return 0; }
r[4]=r[13];
goto P_0c04d3ec;
P_0c04d3ec: /* original e500, guest PC 0x0c04d3ec */
if(!s->budget--) { s->failed_pc=0x0c04d3ecu; return 0; }
r[5]=0x00000000u;
goto P_0c04d3ee;
P_0c04d3ee: /* original e610, guest PC 0x0c04d3ee */
if(!s->budget--) { s->failed_pc=0x0c04d3eeu; return 0; }
r[6]=0x00000010u;
goto P_0c04d3f0;
P_0c04d3f0: /* original 4a0b, guest PC 0x0c04d3f0 */
if(!s->budget--) { s->failed_pc=0x0c04d3f0u; return 0; }
target=r[10];
r[16]=code_base|0x0c04d3f4u;
r[4]=read(ram,r[14]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d3f4u) { target=s->pc; goto dispatch; }
goto P_0c04d3f4;
P_0c04d3f2: /* original 54e8, guest PC 0x0c04d3f2 */
if(!s->budget--) { s->failed_pc=0x0c04d3f2u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04d3f4;
P_0c04d3f4: /* original 60c3, guest PC 0x0c04d3f4 */
if(!s->budget--) { s->failed_pc=0x0c04d3f4u; return 0; }
r[0]=r[12];
goto P_0c04d3f6;
P_0c04d3f6: /* original 80eb, guest PC 0x0c04d3f6 */
if(!s->budget--) { s->failed_pc=0x0c04d3f6u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c04d3f8;
P_0c04d3f8: /* original 80ec, guest PC 0x0c04d3f8 */
if(!s->budget--) { s->failed_pc=0x0c04d3f8u; return 0; }
write(ram,r[14]+12,r[0],1);
goto P_0c04d3fa;
P_0c04d3fa: /* original 80ea, guest PC 0x0c04d3fa */
if(!s->budget--) { s->failed_pc=0x0c04d3fau; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c04d3fc;
P_0c04d3fc: /* original d311, guest PC 0x0c04d3fc */
if(!s->budget--) { s->failed_pc=0x0c04d3fcu; return 0; }
r[3]=read(ram,0x0c04d444u,4);
goto P_0c04d3fe;
P_0c04d3fe: /* original 430b, guest PC 0x0c04d3fe */
if(!s->budget--) { s->failed_pc=0x0c04d3feu; return 0; }
target=r[3];
r[16]=code_base|0x0c04d402u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d402u) { target=s->pc; goto dispatch; }
goto P_0c04d402;
P_0c04d400: /* original 64d3, guest PC 0x0c04d400 */
if(!s->budget--) { s->failed_pc=0x0c04d400u; return 0; }
r[4]=r[13];
goto P_0c04d402;
P_0c04d402: /* original 7f18, guest PC 0x0c04d402 */
if(!s->budget--) { s->failed_pc=0x0c04d402u; return 0; }
r[15]+=0x00000018u;
goto P_0c04d404;
P_0c04d404: /* original 4f16, guest PC 0x0c04d404 */
if(!s->budget--) { s->failed_pc=0x0c04d404u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d406;
P_0c04d406: /* original 4f26, guest PC 0x0c04d406 */
if(!s->budget--) { s->failed_pc=0x0c04d406u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d408;
P_0c04d408: /* original 68f6, guest PC 0x0c04d408 */
if(!s->budget--) { s->failed_pc=0x0c04d408u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04d40a;
P_0c04d40a: /* original 69f6, guest PC 0x0c04d40a */
if(!s->budget--) { s->failed_pc=0x0c04d40au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04d40c;
P_0c04d40c: /* original 6af6, guest PC 0x0c04d40c */
if(!s->budget--) { s->failed_pc=0x0c04d40cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04d40e;
P_0c04d40e: /* original 6bf6, guest PC 0x0c04d40e */
if(!s->budget--) { s->failed_pc=0x0c04d40eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04d410;
P_0c04d410: /* original 6cf6, guest PC 0x0c04d410 */
if(!s->budget--) { s->failed_pc=0x0c04d410u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04d412;
P_0c04d412: /* original 6df6, guest PC 0x0c04d412 */
if(!s->budget--) { s->failed_pc=0x0c04d412u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04d414;
P_0c04d414: /* original 000b, guest PC 0x0c04d414 */
if(!s->budget--) { s->failed_pc=0x0c04d414u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04d416: /* original 6ef6, guest PC 0x0c04d416 */
if(!s->budget--) { s->failed_pc=0x0c04d416u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04d418u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04d418u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
