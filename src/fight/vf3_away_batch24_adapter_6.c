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
int vf3_away_batch24_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0ba006u: goto P_0c0ba006;
case 0x0c0ba008u: goto P_0c0ba008;
case 0x0c0ba00au: goto P_0c0ba00a;
case 0x0c0ba00cu: goto P_0c0ba00c;
case 0x0c0ba00eu: goto P_0c0ba00e;
case 0x0c0ba010u: goto P_0c0ba010;
case 0x0c0ba012u: goto P_0c0ba012;
case 0x0c0ba014u: goto P_0c0ba014;
case 0x0c0ba016u: goto P_0c0ba016;
case 0x0c0ba018u: goto P_0c0ba018;
case 0x0c0ba01au: goto P_0c0ba01a;
case 0x0c0ba01cu: goto P_0c0ba01c;
case 0x0c0ba01eu: goto P_0c0ba01e;
case 0x0c0ba020u: goto P_0c0ba020;
case 0x0c0ba022u: goto P_0c0ba022;
case 0x0c0ba024u: goto P_0c0ba024;
case 0x0c0ba026u: goto P_0c0ba026;
case 0x0c0ba028u: goto P_0c0ba028;
case 0x0c0ba02au: goto P_0c0ba02a;
case 0x0c0ba02cu: goto P_0c0ba02c;
case 0x0c0ba02eu: goto P_0c0ba02e;
case 0x0c0ba030u: goto P_0c0ba030;
case 0x0c0ba032u: goto P_0c0ba032;
case 0x0c0ba034u: goto P_0c0ba034;
case 0x0c0ba036u: goto P_0c0ba036;
case 0x0c0ba038u: goto P_0c0ba038;
case 0x0c0ba03au: goto P_0c0ba03a;
case 0x0c0ba03cu: goto P_0c0ba03c;
case 0x0c0ba03eu: goto P_0c0ba03e;
case 0x0c0ba040u: goto P_0c0ba040;
case 0x0c0ba042u: goto P_0c0ba042;
case 0x0c0ba044u: goto P_0c0ba044;
case 0x0c0ba046u: goto P_0c0ba046;
case 0x0c0ba048u: goto P_0c0ba048;
case 0x0c0ba04au: goto P_0c0ba04a;
case 0x0c0ba04cu: goto P_0c0ba04c;
case 0x0c0ba04eu: goto P_0c0ba04e;
case 0x0c0ba050u: goto P_0c0ba050;
case 0x0c0ba052u: goto P_0c0ba052;
case 0x0c0ba054u: goto P_0c0ba054;
case 0x0c0ba056u: goto P_0c0ba056;
case 0x0c0ba058u: goto P_0c0ba058;
case 0x0c0ba05au: goto P_0c0ba05a;
case 0x0c0ba05cu: goto P_0c0ba05c;
case 0x0c0ba05eu: goto P_0c0ba05e;
case 0x0c0ba060u: goto P_0c0ba060;
case 0x0c0ba062u: goto P_0c0ba062;
case 0x0c0ba064u: goto P_0c0ba064;
case 0x0c0ba066u: goto P_0c0ba066;
case 0x0c0ba068u: goto P_0c0ba068;
case 0x0c0ba06au: goto P_0c0ba06a;
case 0x0c0ba06cu: goto P_0c0ba06c;
case 0x0c0ba06eu: goto P_0c0ba06e;
case 0x0c0ba070u: goto P_0c0ba070;
case 0x0c0ba072u: goto P_0c0ba072;
case 0x0c0ba074u: goto P_0c0ba074;
case 0x0c0ba076u: goto P_0c0ba076;
case 0x0c0ba078u: goto P_0c0ba078;
case 0x0c0ba07au: goto P_0c0ba07a;
case 0x0c0ba07cu: goto P_0c0ba07c;
case 0x0c0ba07eu: goto P_0c0ba07e;
case 0x0c0ba080u: goto P_0c0ba080;
case 0x0c0ba082u: goto P_0c0ba082;
case 0x0c0ba084u: goto P_0c0ba084;
case 0x0c0ba086u: goto P_0c0ba086;
case 0x0c0ba088u: goto P_0c0ba088;
case 0x0c0ba08au: goto P_0c0ba08a;
case 0x0c0ba08cu: goto P_0c0ba08c;
case 0x0c0ba08eu: goto P_0c0ba08e;
case 0x0c0ba090u: goto P_0c0ba090;
case 0x0c0ba092u: goto P_0c0ba092;
case 0x0c0ba094u: goto P_0c0ba094;
case 0x0c0ba096u: goto P_0c0ba096;
case 0x0c0ba098u: goto P_0c0ba098;
case 0x0c0ba09au: goto P_0c0ba09a;
case 0x0c0ba09cu: goto P_0c0ba09c;
case 0x0c0ba09eu: goto P_0c0ba09e;
case 0x0c0ba0a0u: goto P_0c0ba0a0;
case 0x0c0ba0a2u: goto P_0c0ba0a2;
case 0x0c0ba0a4u: goto P_0c0ba0a4;
case 0x0c0ba0a6u: goto P_0c0ba0a6;
case 0x0c0ba0a8u: goto P_0c0ba0a8;
case 0x0c0ba0aau: goto P_0c0ba0aa;
case 0x0c0ba0acu: goto P_0c0ba0ac;
case 0x0c0ba0aeu: goto P_0c0ba0ae;
case 0x0c0ba0b0u: goto P_0c0ba0b0;
case 0x0c0ba0b2u: goto P_0c0ba0b2;
case 0x0c0ba0b4u: goto P_0c0ba0b4;
case 0x0c0ba0b6u: goto P_0c0ba0b6;
case 0x0c0ba0b8u: goto P_0c0ba0b8;
case 0x0c0ba0bau: goto P_0c0ba0ba;
case 0x0c0ba0bcu: goto P_0c0ba0bc;
case 0x0c0ba0beu: goto P_0c0ba0be;
case 0x0c0ba0c0u: goto P_0c0ba0c0;
case 0x0c0ba0c2u: goto P_0c0ba0c2;
case 0x0c0ba0c4u: goto P_0c0ba0c4;
case 0x0c0ba0c6u: goto P_0c0ba0c6;
case 0x0c0ba0c8u: goto P_0c0ba0c8;
case 0x0c0ba0cau: goto P_0c0ba0ca;
case 0x0c0ba0ccu: goto P_0c0ba0cc;
case 0x0c0ba0ceu: goto P_0c0ba0ce;
case 0x0c0ba0d0u: goto P_0c0ba0d0;
case 0x0c0ba0d2u: goto P_0c0ba0d2;
case 0x0c0ba0d4u: goto P_0c0ba0d4;
case 0x0c0ba0d6u: goto P_0c0ba0d6;
case 0x0c0ba0d8u: goto P_0c0ba0d8;
case 0x0c0ba0dau: goto P_0c0ba0da;
case 0x0c0ba0dcu: goto P_0c0ba0dc;
case 0x0c0ba0deu: goto P_0c0ba0de;
case 0x0c0ba0e0u: goto P_0c0ba0e0;
case 0x0c0ba0e2u: goto P_0c0ba0e2;
case 0x0c0ba0e4u: goto P_0c0ba0e4;
case 0x0c0ba0e6u: goto P_0c0ba0e6;
case 0x0c0ba0e8u: goto P_0c0ba0e8;
case 0x0c0ba0eau: goto P_0c0ba0ea;
case 0x0c0ba0ecu: goto P_0c0ba0ec;
case 0x0c0ba0eeu: goto P_0c0ba0ee;
case 0x0c0ba0f0u: goto P_0c0ba0f0;
case 0x0c0ba0f2u: goto P_0c0ba0f2;
case 0x0c0ba0f4u: goto P_0c0ba0f4;
case 0x0c0ba0f6u: goto P_0c0ba0f6;
case 0x0c0ba0f8u: goto P_0c0ba0f8;
case 0x0c0ba0fau: goto P_0c0ba0fa;
case 0x0c0ba0fcu: goto P_0c0ba0fc;
case 0x0c0ba0feu: goto P_0c0ba0fe;
case 0x0c0ba100u: goto P_0c0ba100;
case 0x0c0ba102u: goto P_0c0ba102;
case 0x0c0ba104u: goto P_0c0ba104;
case 0x0c0ba106u: goto P_0c0ba106;
case 0x0c0ba108u: goto P_0c0ba108;
case 0x0c0ba10au: goto P_0c0ba10a;
case 0x0c0ba10cu: goto P_0c0ba10c;
case 0x0c0ba10eu: goto P_0c0ba10e;
case 0x0c0ba110u: goto P_0c0ba110;
case 0x0c0ba112u: goto P_0c0ba112;
case 0x0c0ba114u: goto P_0c0ba114;
case 0x0c0ba116u: goto P_0c0ba116;
case 0x0c0ba118u: goto P_0c0ba118;
case 0x0c0ba11au: goto P_0c0ba11a;
case 0x0c0ba11cu: goto P_0c0ba11c;
case 0x0c0ba11eu: goto P_0c0ba11e;
case 0x0c0ba120u: goto P_0c0ba120;
case 0x0c0ba122u: goto P_0c0ba122;
case 0x0c0ba124u: goto P_0c0ba124;
case 0x0c0ba126u: goto P_0c0ba126;
case 0x0c0ba128u: goto P_0c0ba128;
case 0x0c0ba12au: goto P_0c0ba12a;
case 0x0c0ba12cu: goto P_0c0ba12c;
case 0x0c0ba12eu: goto P_0c0ba12e;
case 0x0c0ba130u: goto P_0c0ba130;
case 0x0c0ba132u: goto P_0c0ba132;
case 0x0c0ba134u: goto P_0c0ba134;
case 0x0c0ba136u: goto P_0c0ba136;
case 0x0c0ba138u: goto P_0c0ba138;
case 0x0c0ba13au: goto P_0c0ba13a;
case 0x0c0ba13cu: goto P_0c0ba13c;
case 0x0c0ba13eu: goto P_0c0ba13e;
case 0x0c0ba140u: goto P_0c0ba140;
case 0x0c0ba142u: goto P_0c0ba142;
case 0x0c0ba144u: goto P_0c0ba144;
case 0x0c0ba146u: goto P_0c0ba146;
case 0x0c0ba148u: goto P_0c0ba148;
case 0x0c0ba14au: goto P_0c0ba14a;
case 0x0c0ba14cu: goto P_0c0ba14c;
case 0x0c0ba14eu: goto P_0c0ba14e;
case 0x0c0ba150u: goto P_0c0ba150;
case 0x0c0ba152u: goto P_0c0ba152;
case 0x0c0ba154u: goto P_0c0ba154;
case 0x0c0ba156u: goto P_0c0ba156;
case 0x0c0ba158u: goto P_0c0ba158;
case 0x0c0ba15au: goto P_0c0ba15a;
case 0x0c0ba15cu: goto P_0c0ba15c;
case 0x0c0ba15eu: goto P_0c0ba15e;
case 0x0c0ba160u: goto P_0c0ba160;
case 0x0c0ba162u: goto P_0c0ba162;
case 0x0c0ba164u: goto P_0c0ba164;
case 0x0c0ba166u: goto P_0c0ba166;
case 0x0c0ba168u: goto P_0c0ba168;
case 0x0c0ba1d8u: goto P_0c0ba1d8;
case 0x0c0ba1dau: goto P_0c0ba1da;
case 0x0c0ba1dcu: goto P_0c0ba1dc;
case 0x0c0ba1deu: goto P_0c0ba1de;
case 0x0c0ba1e0u: goto P_0c0ba1e0;
case 0x0c0ba1e2u: goto P_0c0ba1e2;
case 0x0c0ba1e4u: goto P_0c0ba1e4;
case 0x0c0ba1e6u: goto P_0c0ba1e6;
case 0x0c0ba1e8u: goto P_0c0ba1e8;
case 0x0c0ba1eau: goto P_0c0ba1ea;
case 0x0c0ba1ecu: goto P_0c0ba1ec;
case 0x0c0ba1eeu: goto P_0c0ba1ee;
case 0x0c0ba1f0u: goto P_0c0ba1f0;
case 0x0c0ba1f2u: goto P_0c0ba1f2;
case 0x0c0ba1f4u: goto P_0c0ba1f4;
case 0x0c0ba1f6u: goto P_0c0ba1f6;
case 0x0c0ba1f8u: goto P_0c0ba1f8;
case 0x0c0ba1fau: goto P_0c0ba1fa;
case 0x0c0ba1fcu: goto P_0c0ba1fc;
case 0x0c0ba1feu: goto P_0c0ba1fe;
case 0x0c0ba200u: goto P_0c0ba200;
case 0x0c0ba202u: goto P_0c0ba202;
case 0x0c0ba204u: goto P_0c0ba204;
case 0x0c0ba206u: goto P_0c0ba206;
case 0x0c0ba208u: goto P_0c0ba208;
case 0x0c0ba20au: goto P_0c0ba20a;
case 0x0c0ba20cu: goto P_0c0ba20c;
case 0x0c0ba20eu: goto P_0c0ba20e;
case 0x0c0ba210u: goto P_0c0ba210;
case 0x0c0ba212u: goto P_0c0ba212;
case 0x0c0ba214u: goto P_0c0ba214;
case 0x0c0ba216u: goto P_0c0ba216;
case 0x0c0ba218u: goto P_0c0ba218;
case 0x0c0ba21au: goto P_0c0ba21a;
case 0x0c0ba21cu: goto P_0c0ba21c;
case 0x0c0ba21eu: goto P_0c0ba21e;
case 0x0c0ba220u: goto P_0c0ba220;
case 0x0c0ba222u: goto P_0c0ba222;
case 0x0c0ba224u: goto P_0c0ba224;
case 0x0c0ba226u: goto P_0c0ba226;
case 0x0c0ba228u: goto P_0c0ba228;
case 0x0c0ba22au: goto P_0c0ba22a;
case 0x0c0ba22cu: goto P_0c0ba22c;
case 0x0c0ba22eu: goto P_0c0ba22e;
case 0x0c0ba230u: goto P_0c0ba230;
case 0x0c0ba232u: goto P_0c0ba232;
case 0x0c0ba234u: goto P_0c0ba234;
case 0x0c0ba236u: goto P_0c0ba236;
case 0x0c0ba238u: goto P_0c0ba238;
case 0x0c0ba23au: goto P_0c0ba23a;
case 0x0c0ba23cu: goto P_0c0ba23c;
case 0x0c0ba23eu: goto P_0c0ba23e;
case 0x0c0ba240u: goto P_0c0ba240;
case 0x0c0ba242u: goto P_0c0ba242;
case 0x0c0ba244u: goto P_0c0ba244;
case 0x0c0ba246u: goto P_0c0ba246;
case 0x0c0ba248u: goto P_0c0ba248;
case 0x0c0ba24au: goto P_0c0ba24a;
case 0x0c0ba24cu: goto P_0c0ba24c;
case 0x0c0ba24eu: goto P_0c0ba24e;
case 0x0c0ba250u: goto P_0c0ba250;
case 0x0c0ba252u: goto P_0c0ba252;
case 0x0c0ba254u: goto P_0c0ba254;
case 0x0c0ba256u: goto P_0c0ba256;
case 0x0c0ba258u: goto P_0c0ba258;
case 0x0c0ba25au: goto P_0c0ba25a;
case 0x0c0ba25cu: goto P_0c0ba25c;
case 0x0c0ba25eu: goto P_0c0ba25e;
case 0x0c0ba260u: goto P_0c0ba260;
case 0x0c0ba262u: goto P_0c0ba262;
case 0x0c0ba264u: goto P_0c0ba264;
case 0x0c0ba266u: goto P_0c0ba266;
case 0x0c0ba268u: goto P_0c0ba268;
case 0x0c0ba26au: goto P_0c0ba26a;
case 0x0c0ba26cu: goto P_0c0ba26c;
case 0x0c0ba26eu: goto P_0c0ba26e;
case 0x0c0ba270u: goto P_0c0ba270;
case 0x0c0ba272u: goto P_0c0ba272;
case 0x0c0ba274u: goto P_0c0ba274;
case 0x0c0ba276u: goto P_0c0ba276;
case 0x0c0ba278u: goto P_0c0ba278;
case 0x0c0ba27au: goto P_0c0ba27a;
case 0x0c0ba27cu: goto P_0c0ba27c;
case 0x0c0ba27eu: goto P_0c0ba27e;
case 0x0c0ba280u: goto P_0c0ba280;
case 0x0c0ba282u: goto P_0c0ba282;
case 0x0c0ba284u: goto P_0c0ba284;
case 0x0c0ba286u: goto P_0c0ba286;
case 0x0c0ba288u: goto P_0c0ba288;
case 0x0c0ba28au: goto P_0c0ba28a;
case 0x0c0ba28cu: goto P_0c0ba28c;
case 0x0c0ba28eu: goto P_0c0ba28e;
case 0x0c0ba290u: goto P_0c0ba290;
case 0x0c0ba292u: goto P_0c0ba292;
case 0x0c0ba294u: goto P_0c0ba294;
case 0x0c0ba296u: goto P_0c0ba296;
case 0x0c0ba298u: goto P_0c0ba298;
case 0x0c0ba29au: goto P_0c0ba29a;
case 0x0c0ba29cu: goto P_0c0ba29c;
case 0x0c0ba29eu: goto P_0c0ba29e;
case 0x0c0ba2a0u: goto P_0c0ba2a0;
case 0x0c0ba2a2u: goto P_0c0ba2a2;
case 0x0c0ba2a4u: goto P_0c0ba2a4;
case 0x0c0ba2a6u: goto P_0c0ba2a6;
case 0x0c0ba2a8u: goto P_0c0ba2a8;
case 0x0c0ba2aau: goto P_0c0ba2aa;
case 0x0c0ba2acu: goto P_0c0ba2ac;
case 0x0c0ba2aeu: goto P_0c0ba2ae;
case 0x0c0ba2b0u: goto P_0c0ba2b0;
case 0x0c0ba2b2u: goto P_0c0ba2b2;
case 0x0c0ba2b4u: goto P_0c0ba2b4;
case 0x0c0ba2b6u: goto P_0c0ba2b6;
case 0x0c0ba2b8u: goto P_0c0ba2b8;
case 0x0c0ba2bau: goto P_0c0ba2ba;
case 0x0c0ba2bcu: goto P_0c0ba2bc;
case 0x0c0ba2beu: goto P_0c0ba2be;
case 0x0c0ba2c0u: goto P_0c0ba2c0;
case 0x0c0ba2c2u: goto P_0c0ba2c2;
case 0x0c0ba2c4u: goto P_0c0ba2c4;
case 0x0c0ba2c6u: goto P_0c0ba2c6;
case 0x0c0ba2c8u: goto P_0c0ba2c8;
case 0x0c0ba2cau: goto P_0c0ba2ca;
case 0x0c0ba2ccu: goto P_0c0ba2cc;
case 0x0c0ba2ceu: goto P_0c0ba2ce;
case 0x0c0ba2d0u: goto P_0c0ba2d0;
case 0x0c0ba2d2u: goto P_0c0ba2d2;
case 0x0c0ba2d4u: goto P_0c0ba2d4;
case 0x0c0ba2d6u: goto P_0c0ba2d6;
case 0x0c0ba2d8u: goto P_0c0ba2d8;
case 0x0c0ba2dau: goto P_0c0ba2da;
case 0x0c0ba2dcu: goto P_0c0ba2dc;
case 0x0c0ba2deu: goto P_0c0ba2de;
case 0x0c0ba2e0u: goto P_0c0ba2e0;
case 0x0c0ba2e2u: goto P_0c0ba2e2;
case 0x0c0ba2e4u: goto P_0c0ba2e4;
case 0x0c0ba2e6u: goto P_0c0ba2e6;
case 0x0c0ba2e8u: goto P_0c0ba2e8;
case 0x0c0ba2eau: goto P_0c0ba2ea;
case 0x0c0ba2ecu: goto P_0c0ba2ec;
case 0x0c0ba2eeu: goto P_0c0ba2ee;
case 0x0c0ba2f0u: goto P_0c0ba2f0;
case 0x0c0ba2f2u: goto P_0c0ba2f2;
case 0x0c0ba2f4u: goto P_0c0ba2f4;
case 0x0c0ba2f6u: goto P_0c0ba2f6;
case 0x0c0ba2f8u: goto P_0c0ba2f8;
case 0x0c0ba2fau: goto P_0c0ba2fa;
case 0x0c0ba2fcu: goto P_0c0ba2fc;
case 0x0c0ba2feu: goto P_0c0ba2fe;
case 0x0c0ba300u: goto P_0c0ba300;
case 0x0c0ba302u: goto P_0c0ba302;
case 0x0c0ba304u: goto P_0c0ba304;
case 0x0c0ba306u: goto P_0c0ba306;
case 0x0c0ba308u: goto P_0c0ba308;
case 0x0c0ba30au: goto P_0c0ba30a;
case 0x0c0ba30cu: goto P_0c0ba30c;
case 0x0c0ba30eu: goto P_0c0ba30e;
case 0x0c0ba310u: goto P_0c0ba310;
case 0x0c0ba312u: goto P_0c0ba312;
case 0x0c0ba314u: goto P_0c0ba314;
case 0x0c0ba316u: goto P_0c0ba316;
case 0x0c0ba318u: goto P_0c0ba318;
case 0x0c0ba31au: goto P_0c0ba31a;
case 0x0c0ba31cu: goto P_0c0ba31c;
case 0x0c0ba31eu: goto P_0c0ba31e;
case 0x0c0ba320u: goto P_0c0ba320;
case 0x0c0ba322u: goto P_0c0ba322;
case 0x0c0ba324u: goto P_0c0ba324;
case 0x0c0ba326u: goto P_0c0ba326;
case 0x0c0ba328u: goto P_0c0ba328;
case 0x0c0ba32au: goto P_0c0ba32a;
case 0x0c0ba32cu: goto P_0c0ba32c;
case 0x0c0ba32eu: goto P_0c0ba32e;
case 0x0c0ba330u: goto P_0c0ba330;
case 0x0c0ba3aau: goto P_0c0ba3aa;
case 0x0c0ba3acu: goto P_0c0ba3ac;
case 0x0c0ba3aeu: goto P_0c0ba3ae;
case 0x0c0ba3b0u: goto P_0c0ba3b0;
case 0x0c0ba3b2u: goto P_0c0ba3b2;
case 0x0c0ba3b4u: goto P_0c0ba3b4;
case 0x0c0ba3b6u: goto P_0c0ba3b6;
case 0x0c0ba3b8u: goto P_0c0ba3b8;
case 0x0c0ba3bau: goto P_0c0ba3ba;
case 0x0c0ba3bcu: goto P_0c0ba3bc;
case 0x0c0ba3beu: goto P_0c0ba3be;
case 0x0c0ba3c0u: goto P_0c0ba3c0;
case 0x0c0ba3c2u: goto P_0c0ba3c2;
case 0x0c0ba3c4u: goto P_0c0ba3c4;
case 0x0c0ba3c6u: goto P_0c0ba3c6;
case 0x0c0ba3c8u: goto P_0c0ba3c8;
case 0x0c0ba3cau: goto P_0c0ba3ca;
case 0x0c0ba3ccu: goto P_0c0ba3cc;
case 0x0c0ba3ceu: goto P_0c0ba3ce;
case 0x0c0ba3d0u: goto P_0c0ba3d0;
case 0x0c0ba3d2u: goto P_0c0ba3d2;
case 0x0c0ba3d4u: goto P_0c0ba3d4;
case 0x0c0ba3d6u: goto P_0c0ba3d6;
case 0x0c0ba3d8u: goto P_0c0ba3d8;
case 0x0c0ba3dau: goto P_0c0ba3da;
case 0x0c0ba3dcu: goto P_0c0ba3dc;
case 0x0c0ba3deu: goto P_0c0ba3de;
case 0x0c0ba3e0u: goto P_0c0ba3e0;
case 0x0c0ba3e2u: goto P_0c0ba3e2;
case 0x0c0ba3e4u: goto P_0c0ba3e4;
case 0x0c0ba3e6u: goto P_0c0ba3e6;
case 0x0c0ba3e8u: goto P_0c0ba3e8;
case 0x0c0ba3eau: goto P_0c0ba3ea;
case 0x0c0ba3ecu: goto P_0c0ba3ec;
case 0x0c0ba3eeu: goto P_0c0ba3ee;
case 0x0c0ba3f0u: goto P_0c0ba3f0;
case 0x0c0ba3f2u: goto P_0c0ba3f2;
case 0x0c0ba3f4u: goto P_0c0ba3f4;
case 0x0c0ba3f6u: goto P_0c0ba3f6;
case 0x0c0ba3f8u: goto P_0c0ba3f8;
case 0x0c0ba3fau: goto P_0c0ba3fa;
case 0x0c0ba3fcu: goto P_0c0ba3fc;
case 0x0c0ba3feu: goto P_0c0ba3fe;
case 0x0c0ba400u: goto P_0c0ba400;
case 0x0c0ba402u: goto P_0c0ba402;
case 0x0c0ba404u: goto P_0c0ba404;
case 0x0c0ba406u: goto P_0c0ba406;
case 0x0c0ba408u: goto P_0c0ba408;
case 0x0c0ba40au: goto P_0c0ba40a;
case 0x0c0ba40cu: goto P_0c0ba40c;
case 0x0c0ba40eu: goto P_0c0ba40e;
case 0x0c0ba410u: goto P_0c0ba410;
case 0x0c0ba412u: goto P_0c0ba412;
case 0x0c0ba414u: goto P_0c0ba414;
case 0x0c0ba416u: goto P_0c0ba416;
case 0x0c0ba418u: goto P_0c0ba418;
case 0x0c0ba41au: goto P_0c0ba41a;
case 0x0c0ba41cu: goto P_0c0ba41c;
case 0x0c0ba41eu: goto P_0c0ba41e;
case 0x0c0ba420u: goto P_0c0ba420;
case 0x0c0ba422u: goto P_0c0ba422;
case 0x0c0ba424u: goto P_0c0ba424;
case 0x0c0ba426u: goto P_0c0ba426;
case 0x0c0ba428u: goto P_0c0ba428;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0ba006: /* original 2fe6, guest PC 0x0c0ba006 */
if(!s->budget--) { s->failed_pc=0x0c0ba006u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ba008;
P_0c0ba008: /* original 2fd6, guest PC 0x0c0ba008 */
if(!s->budget--) { s->failed_pc=0x0c0ba008u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ba00a;
P_0c0ba00a: /* original 2fc6, guest PC 0x0c0ba00a */
if(!s->budget--) { s->failed_pc=0x0c0ba00au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ba00c;
P_0c0ba00c: /* original 2fb6, guest PC 0x0c0ba00c */
if(!s->budget--) { s->failed_pc=0x0c0ba00cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ba00e;
P_0c0ba00e: /* original 2fa6, guest PC 0x0c0ba00e */
if(!s->budget--) { s->failed_pc=0x0c0ba00eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ba010;
P_0c0ba010: /* original 2f96, guest PC 0x0c0ba010 */
if(!s->budget--) { s->failed_pc=0x0c0ba010u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ba012;
P_0c0ba012: /* original 4f22, guest PC 0x0c0ba012 */
if(!s->budget--) { s->failed_pc=0x0c0ba012u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ba014;
P_0c0ba014: /* original 5d44, guest PC 0x0c0ba014 */
if(!s->budget--) { s->failed_pc=0x0c0ba014u; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0ba016;
P_0c0ba016: /* original 94a8, guest PC 0x0c0ba016 */
if(!s->budget--) { s->failed_pc=0x0c0ba016u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba16au,2);
goto P_0c0ba018;
P_0c0ba018: /* original de6e, guest PC 0x0c0ba018 */
if(!s->budget--) { s->failed_pc=0x0c0ba018u; return 0; }
r[14]=read(ram,0x0c0ba1d4u,4);
goto P_0c0ba01a;
P_0c0ba01a: /* original 7ff8, guest PC 0x0c0ba01a */
if(!s->budget--) { s->failed_pc=0x0c0ba01au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0ba01c;
P_0c0ba01c: /* original 4e0b, guest PC 0x0c0ba01c */
if(!s->budget--) { s->failed_pc=0x0c0ba01cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba020u;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba020u) { target=s->pc; goto dispatch; }
goto P_0c0ba020;
P_0c0ba01e: /* original 65d2, guest PC 0x0c0ba01e */
if(!s->budget--) { s->failed_pc=0x0c0ba01eu; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0ba020;
P_0c0ba020: /* original 94a4, guest PC 0x0c0ba020 */
if(!s->budget--) { s->failed_pc=0x0c0ba020u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba16cu,2);
goto P_0c0ba022;
P_0c0ba022: /* original 4e0b, guest PC 0x0c0ba022 */
if(!s->budget--) { s->failed_pc=0x0c0ba022u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba026u;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba026u) { target=s->pc; goto dispatch; }
goto P_0c0ba026;
P_0c0ba024: /* original 55d1, guest PC 0x0c0ba024 */
if(!s->budget--) { s->failed_pc=0x0c0ba024u; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0ba026;
P_0c0ba026: /* original 94a2, guest PC 0x0c0ba026 */
if(!s->budget--) { s->failed_pc=0x0c0ba026u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba16eu,2);
goto P_0c0ba028;
P_0c0ba028: /* original 4e0b, guest PC 0x0c0ba028 */
if(!s->budget--) { s->failed_pc=0x0c0ba028u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba02cu;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba02cu) { target=s->pc; goto dispatch; }
goto P_0c0ba02c;
P_0c0ba02a: /* original 55d2, guest PC 0x0c0ba02a */
if(!s->budget--) { s->failed_pc=0x0c0ba02au; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0ba02c;
P_0c0ba02c: /* original 94a0, guest PC 0x0c0ba02c */
if(!s->budget--) { s->failed_pc=0x0c0ba02cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba170u,2);
goto P_0c0ba02e;
P_0c0ba02e: /* original 4e0b, guest PC 0x0c0ba02e */
if(!s->budget--) { s->failed_pc=0x0c0ba02eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba032u;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba032u) { target=s->pc; goto dispatch; }
goto P_0c0ba032;
P_0c0ba030: /* original 55d3, guest PC 0x0c0ba030 */
if(!s->budget--) { s->failed_pc=0x0c0ba030u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0ba032;
P_0c0ba032: /* original 949e, guest PC 0x0c0ba032 */
if(!s->budget--) { s->failed_pc=0x0c0ba032u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba172u,2);
goto P_0c0ba034;
P_0c0ba034: /* original 4e0b, guest PC 0x0c0ba034 */
if(!s->budget--) { s->failed_pc=0x0c0ba034u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba038u;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba038u) { target=s->pc; goto dispatch; }
goto P_0c0ba038;
P_0c0ba036: /* original 55d4, guest PC 0x0c0ba036 */
if(!s->budget--) { s->failed_pc=0x0c0ba036u; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0ba038;
P_0c0ba038: /* original 949c, guest PC 0x0c0ba038 */
if(!s->budget--) { s->failed_pc=0x0c0ba038u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba174u,2);
goto P_0c0ba03a;
P_0c0ba03a: /* original 4e0b, guest PC 0x0c0ba03a */
if(!s->budget--) { s->failed_pc=0x0c0ba03au; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba03eu;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba03eu) { target=s->pc; goto dispatch; }
goto P_0c0ba03e;
P_0c0ba03c: /* original 55d5, guest PC 0x0c0ba03c */
if(!s->budget--) { s->failed_pc=0x0c0ba03cu; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0ba03e;
P_0c0ba03e: /* original 949a, guest PC 0x0c0ba03e */
if(!s->budget--) { s->failed_pc=0x0c0ba03eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba176u,2);
goto P_0c0ba040;
P_0c0ba040: /* original 4e0b, guest PC 0x0c0ba040 */
if(!s->budget--) { s->failed_pc=0x0c0ba040u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba044u;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba044u) { target=s->pc; goto dispatch; }
goto P_0c0ba044;
P_0c0ba042: /* original 55d6, guest PC 0x0c0ba042 */
if(!s->budget--) { s->failed_pc=0x0c0ba042u; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0ba044;
P_0c0ba044: /* original 9498, guest PC 0x0c0ba044 */
if(!s->budget--) { s->failed_pc=0x0c0ba044u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba178u,2);
goto P_0c0ba046;
P_0c0ba046: /* original 4e0b, guest PC 0x0c0ba046 */
if(!s->budget--) { s->failed_pc=0x0c0ba046u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba04au;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba04au) { target=s->pc; goto dispatch; }
goto P_0c0ba04a;
P_0c0ba048: /* original 55d7, guest PC 0x0c0ba048 */
if(!s->budget--) { s->failed_pc=0x0c0ba048u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0ba04a;
P_0c0ba04a: /* original 9496, guest PC 0x0c0ba04a */
if(!s->budget--) { s->failed_pc=0x0c0ba04au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba17au,2);
goto P_0c0ba04c;
P_0c0ba04c: /* original 4e0b, guest PC 0x0c0ba04c */
if(!s->budget--) { s->failed_pc=0x0c0ba04cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba050u;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba050u) { target=s->pc; goto dispatch; }
goto P_0c0ba050;
P_0c0ba04e: /* original 55d8, guest PC 0x0c0ba04e */
if(!s->budget--) { s->failed_pc=0x0c0ba04eu; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0ba050;
P_0c0ba050: /* original 9494, guest PC 0x0c0ba050 */
if(!s->budget--) { s->failed_pc=0x0c0ba050u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba17cu,2);
goto P_0c0ba052;
P_0c0ba052: /* original 4e0b, guest PC 0x0c0ba052 */
if(!s->budget--) { s->failed_pc=0x0c0ba052u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba056u;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba056u) { target=s->pc; goto dispatch; }
goto P_0c0ba056;
P_0c0ba054: /* original 55d9, guest PC 0x0c0ba054 */
if(!s->budget--) { s->failed_pc=0x0c0ba054u; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0ba056;
P_0c0ba056: /* original 9492, guest PC 0x0c0ba056 */
if(!s->budget--) { s->failed_pc=0x0c0ba056u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba17eu,2);
goto P_0c0ba058;
P_0c0ba058: /* original 4e0b, guest PC 0x0c0ba058 */
if(!s->budget--) { s->failed_pc=0x0c0ba058u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba05cu;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba05cu) { target=s->pc; goto dispatch; }
goto P_0c0ba05c;
P_0c0ba05a: /* original 55da, guest PC 0x0c0ba05a */
if(!s->budget--) { s->failed_pc=0x0c0ba05au; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0ba05c;
P_0c0ba05c: /* original 9490, guest PC 0x0c0ba05c */
if(!s->budget--) { s->failed_pc=0x0c0ba05cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba180u,2);
goto P_0c0ba05e;
P_0c0ba05e: /* original 4e0b, guest PC 0x0c0ba05e */
if(!s->budget--) { s->failed_pc=0x0c0ba05eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba062u;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba062u) { target=s->pc; goto dispatch; }
goto P_0c0ba062;
P_0c0ba060: /* original 55db, guest PC 0x0c0ba060 */
if(!s->budget--) { s->failed_pc=0x0c0ba060u; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0ba062;
P_0c0ba062: /* original 948e, guest PC 0x0c0ba062 */
if(!s->budget--) { s->failed_pc=0x0c0ba062u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba182u,2);
goto P_0c0ba064;
P_0c0ba064: /* original 4e0b, guest PC 0x0c0ba064 */
if(!s->budget--) { s->failed_pc=0x0c0ba064u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba068u;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba068u) { target=s->pc; goto dispatch; }
goto P_0c0ba068;
P_0c0ba066: /* original 55dc, guest PC 0x0c0ba066 */
if(!s->budget--) { s->failed_pc=0x0c0ba066u; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0ba068;
P_0c0ba068: /* original 948c, guest PC 0x0c0ba068 */
if(!s->budget--) { s->failed_pc=0x0c0ba068u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba184u,2);
goto P_0c0ba06a;
P_0c0ba06a: /* original 4e0b, guest PC 0x0c0ba06a */
if(!s->budget--) { s->failed_pc=0x0c0ba06au; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba06eu;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba06eu) { target=s->pc; goto dispatch; }
goto P_0c0ba06e;
P_0c0ba06c: /* original 55dd, guest PC 0x0c0ba06c */
if(!s->budget--) { s->failed_pc=0x0c0ba06cu; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0ba06e;
P_0c0ba06e: /* original 948a, guest PC 0x0c0ba06e */
if(!s->budget--) { s->failed_pc=0x0c0ba06eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba186u,2);
goto P_0c0ba070;
P_0c0ba070: /* original 4e0b, guest PC 0x0c0ba070 */
if(!s->budget--) { s->failed_pc=0x0c0ba070u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba074u;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba074u) { target=s->pc; goto dispatch; }
goto P_0c0ba074;
P_0c0ba072: /* original 55de, guest PC 0x0c0ba072 */
if(!s->budget--) { s->failed_pc=0x0c0ba072u; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0ba074;
P_0c0ba074: /* original 9488, guest PC 0x0c0ba074 */
if(!s->budget--) { s->failed_pc=0x0c0ba074u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba188u,2);
goto P_0c0ba076;
P_0c0ba076: /* original 4e0b, guest PC 0x0c0ba076 */
if(!s->budget--) { s->failed_pc=0x0c0ba076u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba07au;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba07au) { target=s->pc; goto dispatch; }
goto P_0c0ba07a;
P_0c0ba078: /* original 55df, guest PC 0x0c0ba078 */
if(!s->budget--) { s->failed_pc=0x0c0ba078u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0ba07a;
P_0c0ba07a: /* original 9486, guest PC 0x0c0ba07a */
if(!s->budget--) { s->failed_pc=0x0c0ba07au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba18au,2);
goto P_0c0ba07c;
P_0c0ba07c: /* original e040, guest PC 0x0c0ba07c */
if(!s->budget--) { s->failed_pc=0x0c0ba07cu; return 0; }
r[0]=0x00000040u;
goto P_0c0ba07e;
P_0c0ba07e: /* original 4e0b, guest PC 0x0c0ba07e */
if(!s->budget--) { s->failed_pc=0x0c0ba07eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba082u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba082u) { target=s->pc; goto dispatch; }
goto P_0c0ba082;
P_0c0ba080: /* original 05de, guest PC 0x0c0ba080 */
if(!s->budget--) { s->failed_pc=0x0c0ba080u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba082;
P_0c0ba082: /* original 9483, guest PC 0x0c0ba082 */
if(!s->budget--) { s->failed_pc=0x0c0ba082u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba18cu,2);
goto P_0c0ba084;
P_0c0ba084: /* original e044, guest PC 0x0c0ba084 */
if(!s->budget--) { s->failed_pc=0x0c0ba084u; return 0; }
r[0]=0x00000044u;
goto P_0c0ba086;
P_0c0ba086: /* original 4e0b, guest PC 0x0c0ba086 */
if(!s->budget--) { s->failed_pc=0x0c0ba086u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba08au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba08au) { target=s->pc; goto dispatch; }
goto P_0c0ba08a;
P_0c0ba088: /* original 05de, guest PC 0x0c0ba088 */
if(!s->budget--) { s->failed_pc=0x0c0ba088u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba08a;
P_0c0ba08a: /* original 9480, guest PC 0x0c0ba08a */
if(!s->budget--) { s->failed_pc=0x0c0ba08au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba18eu,2);
goto P_0c0ba08c;
P_0c0ba08c: /* original e048, guest PC 0x0c0ba08c */
if(!s->budget--) { s->failed_pc=0x0c0ba08cu; return 0; }
r[0]=0x00000048u;
goto P_0c0ba08e;
P_0c0ba08e: /* original 4e0b, guest PC 0x0c0ba08e */
if(!s->budget--) { s->failed_pc=0x0c0ba08eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba092u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba092u) { target=s->pc; goto dispatch; }
goto P_0c0ba092;
P_0c0ba090: /* original 05de, guest PC 0x0c0ba090 */
if(!s->budget--) { s->failed_pc=0x0c0ba090u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba092;
P_0c0ba092: /* original 947d, guest PC 0x0c0ba092 */
if(!s->budget--) { s->failed_pc=0x0c0ba092u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba190u,2);
goto P_0c0ba094;
P_0c0ba094: /* original e04c, guest PC 0x0c0ba094 */
if(!s->budget--) { s->failed_pc=0x0c0ba094u; return 0; }
r[0]=0x0000004cu;
goto P_0c0ba096;
P_0c0ba096: /* original 4e0b, guest PC 0x0c0ba096 */
if(!s->budget--) { s->failed_pc=0x0c0ba096u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba09au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba09au) { target=s->pc; goto dispatch; }
goto P_0c0ba09a;
P_0c0ba098: /* original 05de, guest PC 0x0c0ba098 */
if(!s->budget--) { s->failed_pc=0x0c0ba098u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba09a;
P_0c0ba09a: /* original 947a, guest PC 0x0c0ba09a */
if(!s->budget--) { s->failed_pc=0x0c0ba09au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba192u,2);
goto P_0c0ba09c;
P_0c0ba09c: /* original e050, guest PC 0x0c0ba09c */
if(!s->budget--) { s->failed_pc=0x0c0ba09cu; return 0; }
r[0]=0x00000050u;
goto P_0c0ba09e;
P_0c0ba09e: /* original 4e0b, guest PC 0x0c0ba09e */
if(!s->budget--) { s->failed_pc=0x0c0ba09eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba0a2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba0a2u) { target=s->pc; goto dispatch; }
goto P_0c0ba0a2;
P_0c0ba0a0: /* original 05de, guest PC 0x0c0ba0a0 */
if(!s->budget--) { s->failed_pc=0x0c0ba0a0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba0a2;
P_0c0ba0a2: /* original 9477, guest PC 0x0c0ba0a2 */
if(!s->budget--) { s->failed_pc=0x0c0ba0a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba194u,2);
goto P_0c0ba0a4;
P_0c0ba0a4: /* original e054, guest PC 0x0c0ba0a4 */
if(!s->budget--) { s->failed_pc=0x0c0ba0a4u; return 0; }
r[0]=0x00000054u;
goto P_0c0ba0a6;
P_0c0ba0a6: /* original 4e0b, guest PC 0x0c0ba0a6 */
if(!s->budget--) { s->failed_pc=0x0c0ba0a6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba0aau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba0aau) { target=s->pc; goto dispatch; }
goto P_0c0ba0aa;
P_0c0ba0a8: /* original 05de, guest PC 0x0c0ba0a8 */
if(!s->budget--) { s->failed_pc=0x0c0ba0a8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba0aa;
P_0c0ba0aa: /* original 9474, guest PC 0x0c0ba0aa */
if(!s->budget--) { s->failed_pc=0x0c0ba0aau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba196u,2);
goto P_0c0ba0ac;
P_0c0ba0ac: /* original e058, guest PC 0x0c0ba0ac */
if(!s->budget--) { s->failed_pc=0x0c0ba0acu; return 0; }
r[0]=0x00000058u;
goto P_0c0ba0ae;
P_0c0ba0ae: /* original 4e0b, guest PC 0x0c0ba0ae */
if(!s->budget--) { s->failed_pc=0x0c0ba0aeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba0b2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba0b2u) { target=s->pc; goto dispatch; }
goto P_0c0ba0b2;
P_0c0ba0b0: /* original 05de, guest PC 0x0c0ba0b0 */
if(!s->budget--) { s->failed_pc=0x0c0ba0b0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba0b2;
P_0c0ba0b2: /* original 9471, guest PC 0x0c0ba0b2 */
if(!s->budget--) { s->failed_pc=0x0c0ba0b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba198u,2);
goto P_0c0ba0b4;
P_0c0ba0b4: /* original e05c, guest PC 0x0c0ba0b4 */
if(!s->budget--) { s->failed_pc=0x0c0ba0b4u; return 0; }
r[0]=0x0000005cu;
goto P_0c0ba0b6;
P_0c0ba0b6: /* original 4e0b, guest PC 0x0c0ba0b6 */
if(!s->budget--) { s->failed_pc=0x0c0ba0b6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba0bau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba0bau) { target=s->pc; goto dispatch; }
goto P_0c0ba0ba;
P_0c0ba0b8: /* original 05de, guest PC 0x0c0ba0b8 */
if(!s->budget--) { s->failed_pc=0x0c0ba0b8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba0ba;
P_0c0ba0ba: /* original 946e, guest PC 0x0c0ba0ba */
if(!s->budget--) { s->failed_pc=0x0c0ba0bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba19au,2);
goto P_0c0ba0bc;
P_0c0ba0bc: /* original e060, guest PC 0x0c0ba0bc */
if(!s->budget--) { s->failed_pc=0x0c0ba0bcu; return 0; }
r[0]=0x00000060u;
goto P_0c0ba0be;
P_0c0ba0be: /* original 4e0b, guest PC 0x0c0ba0be */
if(!s->budget--) { s->failed_pc=0x0c0ba0beu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba0c2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba0c2u) { target=s->pc; goto dispatch; }
goto P_0c0ba0c2;
P_0c0ba0c0: /* original 05de, guest PC 0x0c0ba0c0 */
if(!s->budget--) { s->failed_pc=0x0c0ba0c0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba0c2;
P_0c0ba0c2: /* original 946b, guest PC 0x0c0ba0c2 */
if(!s->budget--) { s->failed_pc=0x0c0ba0c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba19cu,2);
goto P_0c0ba0c4;
P_0c0ba0c4: /* original e064, guest PC 0x0c0ba0c4 */
if(!s->budget--) { s->failed_pc=0x0c0ba0c4u; return 0; }
r[0]=0x00000064u;
goto P_0c0ba0c6;
P_0c0ba0c6: /* original 4e0b, guest PC 0x0c0ba0c6 */
if(!s->budget--) { s->failed_pc=0x0c0ba0c6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba0cau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba0cau) { target=s->pc; goto dispatch; }
goto P_0c0ba0ca;
P_0c0ba0c8: /* original 05de, guest PC 0x0c0ba0c8 */
if(!s->budget--) { s->failed_pc=0x0c0ba0c8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba0ca;
P_0c0ba0ca: /* original 9468, guest PC 0x0c0ba0ca */
if(!s->budget--) { s->failed_pc=0x0c0ba0cau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba19eu,2);
goto P_0c0ba0cc;
P_0c0ba0cc: /* original e068, guest PC 0x0c0ba0cc */
if(!s->budget--) { s->failed_pc=0x0c0ba0ccu; return 0; }
r[0]=0x00000068u;
goto P_0c0ba0ce;
P_0c0ba0ce: /* original 4e0b, guest PC 0x0c0ba0ce */
if(!s->budget--) { s->failed_pc=0x0c0ba0ceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba0d2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba0d2u) { target=s->pc; goto dispatch; }
goto P_0c0ba0d2;
P_0c0ba0d0: /* original 05de, guest PC 0x0c0ba0d0 */
if(!s->budget--) { s->failed_pc=0x0c0ba0d0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba0d2;
P_0c0ba0d2: /* original 9465, guest PC 0x0c0ba0d2 */
if(!s->budget--) { s->failed_pc=0x0c0ba0d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1a0u,2);
goto P_0c0ba0d4;
P_0c0ba0d4: /* original e06c, guest PC 0x0c0ba0d4 */
if(!s->budget--) { s->failed_pc=0x0c0ba0d4u; return 0; }
r[0]=0x0000006cu;
goto P_0c0ba0d6;
P_0c0ba0d6: /* original 4e0b, guest PC 0x0c0ba0d6 */
if(!s->budget--) { s->failed_pc=0x0c0ba0d6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba0dau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba0dau) { target=s->pc; goto dispatch; }
goto P_0c0ba0da;
P_0c0ba0d8: /* original 05de, guest PC 0x0c0ba0d8 */
if(!s->budget--) { s->failed_pc=0x0c0ba0d8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba0da;
P_0c0ba0da: /* original 9462, guest PC 0x0c0ba0da */
if(!s->budget--) { s->failed_pc=0x0c0ba0dau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1a2u,2);
goto P_0c0ba0dc;
P_0c0ba0dc: /* original e070, guest PC 0x0c0ba0dc */
if(!s->budget--) { s->failed_pc=0x0c0ba0dcu; return 0; }
r[0]=0x00000070u;
goto P_0c0ba0de;
P_0c0ba0de: /* original 4e0b, guest PC 0x0c0ba0de */
if(!s->budget--) { s->failed_pc=0x0c0ba0deu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba0e2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba0e2u) { target=s->pc; goto dispatch; }
goto P_0c0ba0e2;
P_0c0ba0e0: /* original 05de, guest PC 0x0c0ba0e0 */
if(!s->budget--) { s->failed_pc=0x0c0ba0e0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba0e2;
P_0c0ba0e2: /* original 945f, guest PC 0x0c0ba0e2 */
if(!s->budget--) { s->failed_pc=0x0c0ba0e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1a4u,2);
goto P_0c0ba0e4;
P_0c0ba0e4: /* original e074, guest PC 0x0c0ba0e4 */
if(!s->budget--) { s->failed_pc=0x0c0ba0e4u; return 0; }
r[0]=0x00000074u;
goto P_0c0ba0e6;
P_0c0ba0e6: /* original 4e0b, guest PC 0x0c0ba0e6 */
if(!s->budget--) { s->failed_pc=0x0c0ba0e6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba0eau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba0eau) { target=s->pc; goto dispatch; }
goto P_0c0ba0ea;
P_0c0ba0e8: /* original 05de, guest PC 0x0c0ba0e8 */
if(!s->budget--) { s->failed_pc=0x0c0ba0e8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba0ea;
P_0c0ba0ea: /* original 945c, guest PC 0x0c0ba0ea */
if(!s->budget--) { s->failed_pc=0x0c0ba0eau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1a6u,2);
goto P_0c0ba0ec;
P_0c0ba0ec: /* original e078, guest PC 0x0c0ba0ec */
if(!s->budget--) { s->failed_pc=0x0c0ba0ecu; return 0; }
r[0]=0x00000078u;
goto P_0c0ba0ee;
P_0c0ba0ee: /* original 4e0b, guest PC 0x0c0ba0ee */
if(!s->budget--) { s->failed_pc=0x0c0ba0eeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba0f2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba0f2u) { target=s->pc; goto dispatch; }
goto P_0c0ba0f2;
P_0c0ba0f0: /* original 05de, guest PC 0x0c0ba0f0 */
if(!s->budget--) { s->failed_pc=0x0c0ba0f0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba0f2;
P_0c0ba0f2: /* original 9459, guest PC 0x0c0ba0f2 */
if(!s->budget--) { s->failed_pc=0x0c0ba0f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1a8u,2);
goto P_0c0ba0f4;
P_0c0ba0f4: /* original e07c, guest PC 0x0c0ba0f4 */
if(!s->budget--) { s->failed_pc=0x0c0ba0f4u; return 0; }
r[0]=0x0000007cu;
goto P_0c0ba0f6;
P_0c0ba0f6: /* original 4e0b, guest PC 0x0c0ba0f6 */
if(!s->budget--) { s->failed_pc=0x0c0ba0f6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba0fau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba0fau) { target=s->pc; goto dispatch; }
goto P_0c0ba0fa;
P_0c0ba0f8: /* original 05de, guest PC 0x0c0ba0f8 */
if(!s->budget--) { s->failed_pc=0x0c0ba0f8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba0fa;
P_0c0ba0fa: /* original 9457, guest PC 0x0c0ba0fa */
if(!s->budget--) { s->failed_pc=0x0c0ba0fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1acu,2);
goto P_0c0ba0fc;
P_0c0ba0fc: /* original 9055, guest PC 0x0c0ba0fc */
if(!s->budget--) { s->failed_pc=0x0c0ba0fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1aau,2);
goto P_0c0ba0fe;
P_0c0ba0fe: /* original 4e0b, guest PC 0x0c0ba0fe */
if(!s->budget--) { s->failed_pc=0x0c0ba0feu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba102u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba102u) { target=s->pc; goto dispatch; }
goto P_0c0ba102;
P_0c0ba100: /* original 05de, guest PC 0x0c0ba100 */
if(!s->budget--) { s->failed_pc=0x0c0ba100u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba102;
P_0c0ba102: /* original 9554, guest PC 0x0c0ba102 */
if(!s->budget--) { s->failed_pc=0x0c0ba102u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1aeu,2);
goto P_0c0ba104;
P_0c0ba104: /* original 35dc, guest PC 0x0c0ba104 */
if(!s->budget--) { s->failed_pc=0x0c0ba104u; return 0; }
r[5]+=r[13];
goto P_0c0ba106;
P_0c0ba106: /* original 2f52, guest PC 0x0c0ba106 */
if(!s->budget--) { s->failed_pc=0x0c0ba106u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ba108;
P_0c0ba108: /* original 9452, guest PC 0x0c0ba108 */
if(!s->budget--) { s->failed_pc=0x0c0ba108u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1b0u,2);
goto P_0c0ba10a;
P_0c0ba10a: /* original 4e0b, guest PC 0x0c0ba10a */
if(!s->budget--) { s->failed_pc=0x0c0ba10au; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba10eu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba10eu) { target=s->pc; goto dispatch; }
goto P_0c0ba10e;
P_0c0ba10c: /* original 6552, guest PC 0x0c0ba10c */
if(!s->budget--) { s->failed_pc=0x0c0ba10cu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0ba10e;
P_0c0ba10e: /* original 9550, guest PC 0x0c0ba10e */
if(!s->budget--) { s->failed_pc=0x0c0ba10eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1b2u,2);
goto P_0c0ba110;
P_0c0ba110: /* original 35dc, guest PC 0x0c0ba110 */
if(!s->budget--) { s->failed_pc=0x0c0ba110u; return 0; }
r[5]+=r[13];
goto P_0c0ba112;
P_0c0ba112: /* original 1f51, guest PC 0x0c0ba112 */
if(!s->budget--) { s->failed_pc=0x0c0ba112u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0ba114;
P_0c0ba114: /* original 944e, guest PC 0x0c0ba114 */
if(!s->budget--) { s->failed_pc=0x0c0ba114u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1b4u,2);
goto P_0c0ba116;
P_0c0ba116: /* original 4e0b, guest PC 0x0c0ba116 */
if(!s->budget--) { s->failed_pc=0x0c0ba116u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba11au;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba11au) { target=s->pc; goto dispatch; }
goto P_0c0ba11a;
P_0c0ba118: /* original 6552, guest PC 0x0c0ba118 */
if(!s->budget--) { s->failed_pc=0x0c0ba118u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0ba11a;
P_0c0ba11a: /* original 944d, guest PC 0x0c0ba11a */
if(!s->budget--) { s->failed_pc=0x0c0ba11au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1b8u,2);
goto P_0c0ba11c;
P_0c0ba11c: /* original 904b, guest PC 0x0c0ba11c */
if(!s->budget--) { s->failed_pc=0x0c0ba11cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1b6u,2);
goto P_0c0ba11e;
P_0c0ba11e: /* original 4e0b, guest PC 0x0c0ba11e */
if(!s->budget--) { s->failed_pc=0x0c0ba11eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba122u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba122u) { target=s->pc; goto dispatch; }
goto P_0c0ba122;
P_0c0ba120: /* original 05de, guest PC 0x0c0ba120 */
if(!s->budget--) { s->failed_pc=0x0c0ba120u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba122;
P_0c0ba122: /* original 944b, guest PC 0x0c0ba122 */
if(!s->budget--) { s->failed_pc=0x0c0ba122u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1bcu,2);
goto P_0c0ba124;
P_0c0ba124: /* original 9049, guest PC 0x0c0ba124 */
if(!s->budget--) { s->failed_pc=0x0c0ba124u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1bau,2);
goto P_0c0ba126;
P_0c0ba126: /* original 4e0b, guest PC 0x0c0ba126 */
if(!s->budget--) { s->failed_pc=0x0c0ba126u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba12au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba12au) { target=s->pc; goto dispatch; }
goto P_0c0ba12a;
P_0c0ba128: /* original 05de, guest PC 0x0c0ba128 */
if(!s->budget--) { s->failed_pc=0x0c0ba128u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba12a;
P_0c0ba12a: /* original 9948, guest PC 0x0c0ba12a */
if(!s->budget--) { s->failed_pc=0x0c0ba12au; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1beu,2);
goto P_0c0ba12c;
P_0c0ba12c: /* original 9448, guest PC 0x0c0ba12c */
if(!s->budget--) { s->failed_pc=0x0c0ba12cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1c0u,2);
goto P_0c0ba12e;
P_0c0ba12e: /* original 39dc, guest PC 0x0c0ba12e */
if(!s->budget--) { s->failed_pc=0x0c0ba12eu; return 0; }
r[9]+=r[13];
goto P_0c0ba130;
P_0c0ba130: /* original 4e0b, guest PC 0x0c0ba130 */
if(!s->budget--) { s->failed_pc=0x0c0ba130u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba134u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba134u) { target=s->pc; goto dispatch; }
goto P_0c0ba134;
P_0c0ba132: /* original 6592, guest PC 0x0c0ba132 */
if(!s->budget--) { s->failed_pc=0x0c0ba132u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0ba134;
P_0c0ba134: /* original 9445, guest PC 0x0c0ba134 */
if(!s->budget--) { s->failed_pc=0x0c0ba134u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1c2u,2);
goto P_0c0ba136;
P_0c0ba136: /* original 4e0b, guest PC 0x0c0ba136 */
if(!s->budget--) { s->failed_pc=0x0c0ba136u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba13au;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba13au) { target=s->pc; goto dispatch; }
goto P_0c0ba13a;
P_0c0ba138: /* original 6592, guest PC 0x0c0ba138 */
if(!s->budget--) { s->failed_pc=0x0c0ba138u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0ba13a;
P_0c0ba13a: /* original 9443, guest PC 0x0c0ba13a */
if(!s->budget--) { s->failed_pc=0x0c0ba13au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1c4u,2);
goto P_0c0ba13c;
P_0c0ba13c: /* original 4e0b, guest PC 0x0c0ba13c */
if(!s->budget--) { s->failed_pc=0x0c0ba13cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba140u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba140u) { target=s->pc; goto dispatch; }
goto P_0c0ba140;
P_0c0ba13e: /* original 6592, guest PC 0x0c0ba13e */
if(!s->budget--) { s->failed_pc=0x0c0ba13eu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0ba140;
P_0c0ba140: /* original 9441, guest PC 0x0c0ba140 */
if(!s->budget--) { s->failed_pc=0x0c0ba140u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1c6u,2);
goto P_0c0ba142;
P_0c0ba142: /* original 4e0b, guest PC 0x0c0ba142 */
if(!s->budget--) { s->failed_pc=0x0c0ba142u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba146u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba146u) { target=s->pc; goto dispatch; }
goto P_0c0ba146;
P_0c0ba144: /* original 6592, guest PC 0x0c0ba144 */
if(!s->budget--) { s->failed_pc=0x0c0ba144u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0ba146;
P_0c0ba146: /* original 9c3f, guest PC 0x0c0ba146 */
if(!s->budget--) { s->failed_pc=0x0c0ba146u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1c8u,2);
goto P_0c0ba148;
P_0c0ba148: /* original 943f, guest PC 0x0c0ba148 */
if(!s->budget--) { s->failed_pc=0x0c0ba148u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1cau,2);
goto P_0c0ba14a;
P_0c0ba14a: /* original 3cdc, guest PC 0x0c0ba14a */
if(!s->budget--) { s->failed_pc=0x0c0ba14au; return 0; }
r[12]+=r[13];
goto P_0c0ba14c;
P_0c0ba14c: /* original 4e0b, guest PC 0x0c0ba14c */
if(!s->budget--) { s->failed_pc=0x0c0ba14cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba150u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba150u) { target=s->pc; goto dispatch; }
goto P_0c0ba150;
P_0c0ba14e: /* original 65c2, guest PC 0x0c0ba14e */
if(!s->budget--) { s->failed_pc=0x0c0ba14eu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0ba150;
P_0c0ba150: /* original 943c, guest PC 0x0c0ba150 */
if(!s->budget--) { s->failed_pc=0x0c0ba150u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1ccu,2);
goto P_0c0ba152;
P_0c0ba152: /* original 4e0b, guest PC 0x0c0ba152 */
if(!s->budget--) { s->failed_pc=0x0c0ba152u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba156u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba156u) { target=s->pc; goto dispatch; }
goto P_0c0ba156;
P_0c0ba154: /* original 65c2, guest PC 0x0c0ba154 */
if(!s->budget--) { s->failed_pc=0x0c0ba154u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0ba156;
P_0c0ba156: /* original 943a, guest PC 0x0c0ba156 */
if(!s->budget--) { s->failed_pc=0x0c0ba156u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1ceu,2);
goto P_0c0ba158;
P_0c0ba158: /* original 4e0b, guest PC 0x0c0ba158 */
if(!s->budget--) { s->failed_pc=0x0c0ba158u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba15cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba15cu) { target=s->pc; goto dispatch; }
goto P_0c0ba15c;
P_0c0ba15a: /* original 65c2, guest PC 0x0c0ba15a */
if(!s->budget--) { s->failed_pc=0x0c0ba15au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0ba15c;
P_0c0ba15c: /* original 9438, guest PC 0x0c0ba15c */
if(!s->budget--) { s->failed_pc=0x0c0ba15cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1d0u,2);
goto P_0c0ba15e;
P_0c0ba15e: /* original 4e0b, guest PC 0x0c0ba15e */
if(!s->budget--) { s->failed_pc=0x0c0ba15eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba162u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba162u) { target=s->pc; goto dispatch; }
goto P_0c0ba162;
P_0c0ba160: /* original 65c2, guest PC 0x0c0ba160 */
if(!s->budget--) { s->failed_pc=0x0c0ba160u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0ba162;
P_0c0ba162: /* original 9b36, guest PC 0x0c0ba162 */
if(!s->budget--) { s->failed_pc=0x0c0ba162u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba1d2u,2);
goto P_0c0ba164;
P_0c0ba164: /* original 3bdc, guest PC 0x0c0ba164 */
if(!s->budget--) { s->failed_pc=0x0c0ba164u; return 0; }
r[11]+=r[13];
goto P_0c0ba166;
P_0c0ba166: /* original a037, guest PC 0x0c0ba166 */
if(!s->budget--) { s->failed_pc=0x0c0ba166u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0ba1d8;
P_0c0ba168: /* original 65b2, guest PC 0x0c0ba168 */
if(!s->budget--) { s->failed_pc=0x0c0ba168u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0ba16au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ba16au; return 0; } return 1;
P_0c0ba1d8: /* original 94ab, guest PC 0x0c0ba1d8 */
if(!s->budget--) { s->failed_pc=0x0c0ba1d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba332u,2);
goto P_0c0ba1da;
P_0c0ba1da: /* original 4e0b, guest PC 0x0c0ba1da */
if(!s->budget--) { s->failed_pc=0x0c0ba1dau; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba1deu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba1deu) { target=s->pc; goto dispatch; }
goto P_0c0ba1de;
P_0c0ba1dc: /* original 0009, guest PC 0x0c0ba1dc */
if(!s->budget--) { s->failed_pc=0x0c0ba1dcu; return 0; }
goto P_0c0ba1de;
P_0c0ba1de: /* original 94a9, guest PC 0x0c0ba1de */
if(!s->budget--) { s->failed_pc=0x0c0ba1deu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba334u,2);
goto P_0c0ba1e0;
P_0c0ba1e0: /* original 4e0b, guest PC 0x0c0ba1e0 */
if(!s->budget--) { s->failed_pc=0x0c0ba1e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba1e4u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba1e4u) { target=s->pc; goto dispatch; }
goto P_0c0ba1e4;
P_0c0ba1e2: /* original 65b2, guest PC 0x0c0ba1e2 */
if(!s->budget--) { s->failed_pc=0x0c0ba1e2u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0ba1e4;
P_0c0ba1e4: /* original 94a7, guest PC 0x0c0ba1e4 */
if(!s->budget--) { s->failed_pc=0x0c0ba1e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba336u,2);
goto P_0c0ba1e6;
P_0c0ba1e6: /* original 4e0b, guest PC 0x0c0ba1e6 */
if(!s->budget--) { s->failed_pc=0x0c0ba1e6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba1eau;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba1eau) { target=s->pc; goto dispatch; }
goto P_0c0ba1ea;
P_0c0ba1e8: /* original 65b2, guest PC 0x0c0ba1e8 */
if(!s->budget--) { s->failed_pc=0x0c0ba1e8u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0ba1ea;
P_0c0ba1ea: /* original 94a5, guest PC 0x0c0ba1ea */
if(!s->budget--) { s->failed_pc=0x0c0ba1eau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba338u,2);
goto P_0c0ba1ec;
P_0c0ba1ec: /* original 4e0b, guest PC 0x0c0ba1ec */
if(!s->budget--) { s->failed_pc=0x0c0ba1ecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba1f0u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba1f0u) { target=s->pc; goto dispatch; }
goto P_0c0ba1f0;
P_0c0ba1ee: /* original 65b2, guest PC 0x0c0ba1ee */
if(!s->budget--) { s->failed_pc=0x0c0ba1eeu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0ba1f0;
P_0c0ba1f0: /* original 9aa3, guest PC 0x0c0ba1f0 */
if(!s->budget--) { s->failed_pc=0x0c0ba1f0u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba33au,2);
goto P_0c0ba1f2;
P_0c0ba1f2: /* original 94a3, guest PC 0x0c0ba1f2 */
if(!s->budget--) { s->failed_pc=0x0c0ba1f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba33cu,2);
goto P_0c0ba1f4;
P_0c0ba1f4: /* original 3adc, guest PC 0x0c0ba1f4 */
if(!s->budget--) { s->failed_pc=0x0c0ba1f4u; return 0; }
r[10]+=r[13];
goto P_0c0ba1f6;
P_0c0ba1f6: /* original 4e0b, guest PC 0x0c0ba1f6 */
if(!s->budget--) { s->failed_pc=0x0c0ba1f6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba1fau;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba1fau) { target=s->pc; goto dispatch; }
goto P_0c0ba1fa;
P_0c0ba1f8: /* original 65a2, guest PC 0x0c0ba1f8 */
if(!s->budget--) { s->failed_pc=0x0c0ba1f8u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0ba1fa;
P_0c0ba1fa: /* original 94a0, guest PC 0x0c0ba1fa */
if(!s->budget--) { s->failed_pc=0x0c0ba1fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba33eu,2);
goto P_0c0ba1fc;
P_0c0ba1fc: /* original 4e0b, guest PC 0x0c0ba1fc */
if(!s->budget--) { s->failed_pc=0x0c0ba1fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba200u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba200u) { target=s->pc; goto dispatch; }
goto P_0c0ba200;
P_0c0ba1fe: /* original 65a2, guest PC 0x0c0ba1fe */
if(!s->budget--) { s->failed_pc=0x0c0ba1feu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0ba200;
P_0c0ba200: /* original 949e, guest PC 0x0c0ba200 */
if(!s->budget--) { s->failed_pc=0x0c0ba200u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba340u,2);
goto P_0c0ba202;
P_0c0ba202: /* original 4e0b, guest PC 0x0c0ba202 */
if(!s->budget--) { s->failed_pc=0x0c0ba202u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba206u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba206u) { target=s->pc; goto dispatch; }
goto P_0c0ba206;
P_0c0ba204: /* original 65a2, guest PC 0x0c0ba204 */
if(!s->budget--) { s->failed_pc=0x0c0ba204u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0ba206;
P_0c0ba206: /* original 949c, guest PC 0x0c0ba206 */
if(!s->budget--) { s->failed_pc=0x0c0ba206u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba342u,2);
goto P_0c0ba208;
P_0c0ba208: /* original 4e0b, guest PC 0x0c0ba208 */
if(!s->budget--) { s->failed_pc=0x0c0ba208u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba20cu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba20cu) { target=s->pc; goto dispatch; }
goto P_0c0ba20c;
P_0c0ba20a: /* original 65a2, guest PC 0x0c0ba20a */
if(!s->budget--) { s->failed_pc=0x0c0ba20au; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0ba20c;
P_0c0ba20c: /* original 949a, guest PC 0x0c0ba20c */
if(!s->budget--) { s->failed_pc=0x0c0ba20cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba344u,2);
goto P_0c0ba20e;
P_0c0ba20e: /* original 65f2, guest PC 0x0c0ba20e */
if(!s->budget--) { s->failed_pc=0x0c0ba20eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ba210;
P_0c0ba210: /* original 4e0b, guest PC 0x0c0ba210 */
if(!s->budget--) { s->failed_pc=0x0c0ba210u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba214u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba214u) { target=s->pc; goto dispatch; }
goto P_0c0ba214;
P_0c0ba212: /* original 6552, guest PC 0x0c0ba212 */
if(!s->budget--) { s->failed_pc=0x0c0ba212u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0ba214;
P_0c0ba214: /* original 9497, guest PC 0x0c0ba214 */
if(!s->budget--) { s->failed_pc=0x0c0ba214u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba346u,2);
goto P_0c0ba216;
P_0c0ba216: /* original 55f1, guest PC 0x0c0ba216 */
if(!s->budget--) { s->failed_pc=0x0c0ba216u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0ba218;
P_0c0ba218: /* original 4e0b, guest PC 0x0c0ba218 */
if(!s->budget--) { s->failed_pc=0x0c0ba218u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba21cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba21cu) { target=s->pc; goto dispatch; }
goto P_0c0ba21c;
P_0c0ba21a: /* original 6552, guest PC 0x0c0ba21a */
if(!s->budget--) { s->failed_pc=0x0c0ba21au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0ba21c;
P_0c0ba21c: /* original 9494, guest PC 0x0c0ba21c */
if(!s->budget--) { s->failed_pc=0x0c0ba21cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba348u,2);
goto P_0c0ba21e;
P_0c0ba21e: /* original 4e0b, guest PC 0x0c0ba21e */
if(!s->budget--) { s->failed_pc=0x0c0ba21eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba222u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba222u) { target=s->pc; goto dispatch; }
goto P_0c0ba222;
P_0c0ba220: /* original 6592, guest PC 0x0c0ba220 */
if(!s->budget--) { s->failed_pc=0x0c0ba220u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0ba222;
P_0c0ba222: /* original 9492, guest PC 0x0c0ba222 */
if(!s->budget--) { s->failed_pc=0x0c0ba222u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba34au,2);
goto P_0c0ba224;
P_0c0ba224: /* original 4e0b, guest PC 0x0c0ba224 */
if(!s->budget--) { s->failed_pc=0x0c0ba224u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba228u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba228u) { target=s->pc; goto dispatch; }
goto P_0c0ba228;
P_0c0ba226: /* original 6592, guest PC 0x0c0ba226 */
if(!s->budget--) { s->failed_pc=0x0c0ba226u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0ba228;
P_0c0ba228: /* original 9490, guest PC 0x0c0ba228 */
if(!s->budget--) { s->failed_pc=0x0c0ba228u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba34cu,2);
goto P_0c0ba22a;
P_0c0ba22a: /* original 4e0b, guest PC 0x0c0ba22a */
if(!s->budget--) { s->failed_pc=0x0c0ba22au; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba22eu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba22eu) { target=s->pc; goto dispatch; }
goto P_0c0ba22e;
P_0c0ba22c: /* original 6592, guest PC 0x0c0ba22c */
if(!s->budget--) { s->failed_pc=0x0c0ba22cu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0ba22e;
P_0c0ba22e: /* original 948e, guest PC 0x0c0ba22e */
if(!s->budget--) { s->failed_pc=0x0c0ba22eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba34eu,2);
goto P_0c0ba230;
P_0c0ba230: /* original 4e0b, guest PC 0x0c0ba230 */
if(!s->budget--) { s->failed_pc=0x0c0ba230u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba234u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba234u) { target=s->pc; goto dispatch; }
goto P_0c0ba234;
P_0c0ba232: /* original 6592, guest PC 0x0c0ba232 */
if(!s->budget--) { s->failed_pc=0x0c0ba232u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0ba234;
P_0c0ba234: /* original 948c, guest PC 0x0c0ba234 */
if(!s->budget--) { s->failed_pc=0x0c0ba234u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba350u,2);
goto P_0c0ba236;
P_0c0ba236: /* original 4e0b, guest PC 0x0c0ba236 */
if(!s->budget--) { s->failed_pc=0x0c0ba236u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba23au;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba23au) { target=s->pc; goto dispatch; }
goto P_0c0ba23a;
P_0c0ba238: /* original 65c2, guest PC 0x0c0ba238 */
if(!s->budget--) { s->failed_pc=0x0c0ba238u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0ba23a;
P_0c0ba23a: /* original 948a, guest PC 0x0c0ba23a */
if(!s->budget--) { s->failed_pc=0x0c0ba23au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba352u,2);
goto P_0c0ba23c;
P_0c0ba23c: /* original 4e0b, guest PC 0x0c0ba23c */
if(!s->budget--) { s->failed_pc=0x0c0ba23cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba240u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba240u) { target=s->pc; goto dispatch; }
goto P_0c0ba240;
P_0c0ba23e: /* original 65c2, guest PC 0x0c0ba23e */
if(!s->budget--) { s->failed_pc=0x0c0ba23eu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0ba240;
P_0c0ba240: /* original 9488, guest PC 0x0c0ba240 */
if(!s->budget--) { s->failed_pc=0x0c0ba240u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba354u,2);
goto P_0c0ba242;
P_0c0ba242: /* original 4e0b, guest PC 0x0c0ba242 */
if(!s->budget--) { s->failed_pc=0x0c0ba242u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba246u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba246u) { target=s->pc; goto dispatch; }
goto P_0c0ba246;
P_0c0ba244: /* original 65c2, guest PC 0x0c0ba244 */
if(!s->budget--) { s->failed_pc=0x0c0ba244u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0ba246;
P_0c0ba246: /* original 9486, guest PC 0x0c0ba246 */
if(!s->budget--) { s->failed_pc=0x0c0ba246u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba356u,2);
goto P_0c0ba248;
P_0c0ba248: /* original 4e0b, guest PC 0x0c0ba248 */
if(!s->budget--) { s->failed_pc=0x0c0ba248u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba24cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba24cu) { target=s->pc; goto dispatch; }
goto P_0c0ba24c;
P_0c0ba24a: /* original 65c2, guest PC 0x0c0ba24a */
if(!s->budget--) { s->failed_pc=0x0c0ba24au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0ba24c;
P_0c0ba24c: /* original 9484, guest PC 0x0c0ba24c */
if(!s->budget--) { s->failed_pc=0x0c0ba24cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba358u,2);
goto P_0c0ba24e;
P_0c0ba24e: /* original 4e0b, guest PC 0x0c0ba24e */
if(!s->budget--) { s->failed_pc=0x0c0ba24eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba252u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba252u) { target=s->pc; goto dispatch; }
goto P_0c0ba252;
P_0c0ba250: /* original 65b2, guest PC 0x0c0ba250 */
if(!s->budget--) { s->failed_pc=0x0c0ba250u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0ba252;
P_0c0ba252: /* original 9482, guest PC 0x0c0ba252 */
if(!s->budget--) { s->failed_pc=0x0c0ba252u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba35au,2);
goto P_0c0ba254;
P_0c0ba254: /* original 4e0b, guest PC 0x0c0ba254 */
if(!s->budget--) { s->failed_pc=0x0c0ba254u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba258u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba258u) { target=s->pc; goto dispatch; }
goto P_0c0ba258;
P_0c0ba256: /* original 65b2, guest PC 0x0c0ba256 */
if(!s->budget--) { s->failed_pc=0x0c0ba256u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0ba258;
P_0c0ba258: /* original 9480, guest PC 0x0c0ba258 */
if(!s->budget--) { s->failed_pc=0x0c0ba258u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba35cu,2);
goto P_0c0ba25a;
P_0c0ba25a: /* original 4e0b, guest PC 0x0c0ba25a */
if(!s->budget--) { s->failed_pc=0x0c0ba25au; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba25eu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba25eu) { target=s->pc; goto dispatch; }
goto P_0c0ba25e;
P_0c0ba25c: /* original 65b2, guest PC 0x0c0ba25c */
if(!s->budget--) { s->failed_pc=0x0c0ba25cu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0ba25e;
P_0c0ba25e: /* original 947e, guest PC 0x0c0ba25e */
if(!s->budget--) { s->failed_pc=0x0c0ba25eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba35eu,2);
goto P_0c0ba260;
P_0c0ba260: /* original 4e0b, guest PC 0x0c0ba260 */
if(!s->budget--) { s->failed_pc=0x0c0ba260u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba264u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba264u) { target=s->pc; goto dispatch; }
goto P_0c0ba264;
P_0c0ba262: /* original 65b2, guest PC 0x0c0ba262 */
if(!s->budget--) { s->failed_pc=0x0c0ba262u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0ba264;
P_0c0ba264: /* original 947c, guest PC 0x0c0ba264 */
if(!s->budget--) { s->failed_pc=0x0c0ba264u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba360u,2);
goto P_0c0ba266;
P_0c0ba266: /* original 4e0b, guest PC 0x0c0ba266 */
if(!s->budget--) { s->failed_pc=0x0c0ba266u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba26au;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba26au) { target=s->pc; goto dispatch; }
goto P_0c0ba26a;
P_0c0ba268: /* original 65a2, guest PC 0x0c0ba268 */
if(!s->budget--) { s->failed_pc=0x0c0ba268u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0ba26a;
P_0c0ba26a: /* original 947a, guest PC 0x0c0ba26a */
if(!s->budget--) { s->failed_pc=0x0c0ba26au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba362u,2);
goto P_0c0ba26c;
P_0c0ba26c: /* original 4e0b, guest PC 0x0c0ba26c */
if(!s->budget--) { s->failed_pc=0x0c0ba26cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba270u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba270u) { target=s->pc; goto dispatch; }
goto P_0c0ba270;
P_0c0ba26e: /* original 65a2, guest PC 0x0c0ba26e */
if(!s->budget--) { s->failed_pc=0x0c0ba26eu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0ba270;
P_0c0ba270: /* original 9478, guest PC 0x0c0ba270 */
if(!s->budget--) { s->failed_pc=0x0c0ba270u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba364u,2);
goto P_0c0ba272;
P_0c0ba272: /* original 4e0b, guest PC 0x0c0ba272 */
if(!s->budget--) { s->failed_pc=0x0c0ba272u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba276u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba276u) { target=s->pc; goto dispatch; }
goto P_0c0ba276;
P_0c0ba274: /* original 65a2, guest PC 0x0c0ba274 */
if(!s->budget--) { s->failed_pc=0x0c0ba274u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0ba276;
P_0c0ba276: /* original 9476, guest PC 0x0c0ba276 */
if(!s->budget--) { s->failed_pc=0x0c0ba276u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba366u,2);
goto P_0c0ba278;
P_0c0ba278: /* original 4e0b, guest PC 0x0c0ba278 */
if(!s->budget--) { s->failed_pc=0x0c0ba278u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba27cu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba27cu) { target=s->pc; goto dispatch; }
goto P_0c0ba27c;
P_0c0ba27a: /* original 65a2, guest PC 0x0c0ba27a */
if(!s->budget--) { s->failed_pc=0x0c0ba27au; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0ba27c;
P_0c0ba27c: /* original 9574, guest PC 0x0c0ba27c */
if(!s->budget--) { s->failed_pc=0x0c0ba27cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba368u,2);
goto P_0c0ba27e;
P_0c0ba27e: /* original 35dc, guest PC 0x0c0ba27e */
if(!s->budget--) { s->failed_pc=0x0c0ba27eu; return 0; }
r[5]+=r[13];
goto P_0c0ba280;
P_0c0ba280: /* original 2f52, guest PC 0x0c0ba280 */
if(!s->budget--) { s->failed_pc=0x0c0ba280u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ba282;
P_0c0ba282: /* original 9472, guest PC 0x0c0ba282 */
if(!s->budget--) { s->failed_pc=0x0c0ba282u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba36au,2);
goto P_0c0ba284;
P_0c0ba284: /* original 4e0b, guest PC 0x0c0ba284 */
if(!s->budget--) { s->failed_pc=0x0c0ba284u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba288u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba288u) { target=s->pc; goto dispatch; }
goto P_0c0ba288;
P_0c0ba286: /* original 6552, guest PC 0x0c0ba286 */
if(!s->budget--) { s->failed_pc=0x0c0ba286u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0ba288;
P_0c0ba288: /* original 9470, guest PC 0x0c0ba288 */
if(!s->budget--) { s->failed_pc=0x0c0ba288u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba36cu,2);
goto P_0c0ba28a;
P_0c0ba28a: /* original 65f2, guest PC 0x0c0ba28a */
if(!s->budget--) { s->failed_pc=0x0c0ba28au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ba28c;
P_0c0ba28c: /* original 4e0b, guest PC 0x0c0ba28c */
if(!s->budget--) { s->failed_pc=0x0c0ba28cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba290u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba290u) { target=s->pc; goto dispatch; }
goto P_0c0ba290;
P_0c0ba28e: /* original 6552, guest PC 0x0c0ba28e */
if(!s->budget--) { s->failed_pc=0x0c0ba28eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0ba290;
P_0c0ba290: /* original 956d, guest PC 0x0c0ba290 */
if(!s->budget--) { s->failed_pc=0x0c0ba290u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba36eu,2);
goto P_0c0ba292;
P_0c0ba292: /* original 35dc, guest PC 0x0c0ba292 */
if(!s->budget--) { s->failed_pc=0x0c0ba292u; return 0; }
r[5]+=r[13];
goto P_0c0ba294;
P_0c0ba294: /* original 2f52, guest PC 0x0c0ba294 */
if(!s->budget--) { s->failed_pc=0x0c0ba294u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ba296;
P_0c0ba296: /* original 946b, guest PC 0x0c0ba296 */
if(!s->budget--) { s->failed_pc=0x0c0ba296u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba370u,2);
goto P_0c0ba298;
P_0c0ba298: /* original 4e0b, guest PC 0x0c0ba298 */
if(!s->budget--) { s->failed_pc=0x0c0ba298u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba29cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba29cu) { target=s->pc; goto dispatch; }
goto P_0c0ba29c;
P_0c0ba29a: /* original 6552, guest PC 0x0c0ba29a */
if(!s->budget--) { s->failed_pc=0x0c0ba29au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0ba29c;
P_0c0ba29c: /* original 9469, guest PC 0x0c0ba29c */
if(!s->budget--) { s->failed_pc=0x0c0ba29cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba372u,2);
goto P_0c0ba29e;
P_0c0ba29e: /* original 65f2, guest PC 0x0c0ba29e */
if(!s->budget--) { s->failed_pc=0x0c0ba29eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ba2a0;
P_0c0ba2a0: /* original 4e0b, guest PC 0x0c0ba2a0 */
if(!s->budget--) { s->failed_pc=0x0c0ba2a0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba2a4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba2a4u) { target=s->pc; goto dispatch; }
goto P_0c0ba2a4;
P_0c0ba2a2: /* original 6552, guest PC 0x0c0ba2a2 */
if(!s->budget--) { s->failed_pc=0x0c0ba2a2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0ba2a4;
P_0c0ba2a4: /* original 9467, guest PC 0x0c0ba2a4 */
if(!s->budget--) { s->failed_pc=0x0c0ba2a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba376u,2);
goto P_0c0ba2a6;
P_0c0ba2a6: /* original 9065, guest PC 0x0c0ba2a6 */
if(!s->budget--) { s->failed_pc=0x0c0ba2a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba374u,2);
goto P_0c0ba2a8;
P_0c0ba2a8: /* original 4e0b, guest PC 0x0c0ba2a8 */
if(!s->budget--) { s->failed_pc=0x0c0ba2a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba2acu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba2acu) { target=s->pc; goto dispatch; }
goto P_0c0ba2ac;
P_0c0ba2aa: /* original 05de, guest PC 0x0c0ba2aa */
if(!s->budget--) { s->failed_pc=0x0c0ba2aau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba2ac;
P_0c0ba2ac: /* original 9564, guest PC 0x0c0ba2ac */
if(!s->budget--) { s->failed_pc=0x0c0ba2acu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba378u,2);
goto P_0c0ba2ae;
P_0c0ba2ae: /* original 35dc, guest PC 0x0c0ba2ae */
if(!s->budget--) { s->failed_pc=0x0c0ba2aeu; return 0; }
r[5]+=r[13];
goto P_0c0ba2b0;
P_0c0ba2b0: /* original 2f52, guest PC 0x0c0ba2b0 */
if(!s->budget--) { s->failed_pc=0x0c0ba2b0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ba2b2;
P_0c0ba2b2: /* original 9462, guest PC 0x0c0ba2b2 */
if(!s->budget--) { s->failed_pc=0x0c0ba2b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba37au,2);
goto P_0c0ba2b4;
P_0c0ba2b4: /* original 4e0b, guest PC 0x0c0ba2b4 */
if(!s->budget--) { s->failed_pc=0x0c0ba2b4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba2b8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba2b8u) { target=s->pc; goto dispatch; }
goto P_0c0ba2b8;
P_0c0ba2b6: /* original 6552, guest PC 0x0c0ba2b6 */
if(!s->budget--) { s->failed_pc=0x0c0ba2b6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0ba2b8;
P_0c0ba2b8: /* original 9460, guest PC 0x0c0ba2b8 */
if(!s->budget--) { s->failed_pc=0x0c0ba2b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba37cu,2);
goto P_0c0ba2ba;
P_0c0ba2ba: /* original 65f2, guest PC 0x0c0ba2ba */
if(!s->budget--) { s->failed_pc=0x0c0ba2bau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ba2bc;
P_0c0ba2bc: /* original 4e0b, guest PC 0x0c0ba2bc */
if(!s->budget--) { s->failed_pc=0x0c0ba2bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba2c0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba2c0u) { target=s->pc; goto dispatch; }
goto P_0c0ba2c0;
P_0c0ba2be: /* original 6552, guest PC 0x0c0ba2be */
if(!s->budget--) { s->failed_pc=0x0c0ba2beu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0ba2c0;
P_0c0ba2c0: /* original 945e, guest PC 0x0c0ba2c0 */
if(!s->budget--) { s->failed_pc=0x0c0ba2c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba380u,2);
goto P_0c0ba2c2;
P_0c0ba2c2: /* original 905c, guest PC 0x0c0ba2c2 */
if(!s->budget--) { s->failed_pc=0x0c0ba2c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba37eu,2);
goto P_0c0ba2c4;
P_0c0ba2c4: /* original 4e0b, guest PC 0x0c0ba2c4 */
if(!s->budget--) { s->failed_pc=0x0c0ba2c4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba2c8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba2c8u) { target=s->pc; goto dispatch; }
goto P_0c0ba2c8;
P_0c0ba2c6: /* original 05de, guest PC 0x0c0ba2c6 */
if(!s->budget--) { s->failed_pc=0x0c0ba2c6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba2c8;
P_0c0ba2c8: /* original 955b, guest PC 0x0c0ba2c8 */
if(!s->budget--) { s->failed_pc=0x0c0ba2c8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba382u,2);
goto P_0c0ba2ca;
P_0c0ba2ca: /* original 35dc, guest PC 0x0c0ba2ca */
if(!s->budget--) { s->failed_pc=0x0c0ba2cau; return 0; }
r[5]+=r[13];
goto P_0c0ba2cc;
P_0c0ba2cc: /* original 2f52, guest PC 0x0c0ba2cc */
if(!s->budget--) { s->failed_pc=0x0c0ba2ccu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ba2ce;
P_0c0ba2ce: /* original 9459, guest PC 0x0c0ba2ce */
if(!s->budget--) { s->failed_pc=0x0c0ba2ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba384u,2);
goto P_0c0ba2d0;
P_0c0ba2d0: /* original 4e0b, guest PC 0x0c0ba2d0 */
if(!s->budget--) { s->failed_pc=0x0c0ba2d0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba2d4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba2d4u) { target=s->pc; goto dispatch; }
goto P_0c0ba2d4;
P_0c0ba2d2: /* original 6552, guest PC 0x0c0ba2d2 */
if(!s->budget--) { s->failed_pc=0x0c0ba2d2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0ba2d4;
P_0c0ba2d4: /* original 9457, guest PC 0x0c0ba2d4 */
if(!s->budget--) { s->failed_pc=0x0c0ba2d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba386u,2);
goto P_0c0ba2d6;
P_0c0ba2d6: /* original 65f2, guest PC 0x0c0ba2d6 */
if(!s->budget--) { s->failed_pc=0x0c0ba2d6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ba2d8;
P_0c0ba2d8: /* original 4e0b, guest PC 0x0c0ba2d8 */
if(!s->budget--) { s->failed_pc=0x0c0ba2d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba2dcu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba2dcu) { target=s->pc; goto dispatch; }
goto P_0c0ba2dc;
P_0c0ba2da: /* original 6552, guest PC 0x0c0ba2da */
if(!s->budget--) { s->failed_pc=0x0c0ba2dau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0ba2dc;
P_0c0ba2dc: /* original 9455, guest PC 0x0c0ba2dc */
if(!s->budget--) { s->failed_pc=0x0c0ba2dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba38au,2);
goto P_0c0ba2de;
P_0c0ba2de: /* original 9053, guest PC 0x0c0ba2de */
if(!s->budget--) { s->failed_pc=0x0c0ba2deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba388u,2);
goto P_0c0ba2e0;
P_0c0ba2e0: /* original 4e0b, guest PC 0x0c0ba2e0 */
if(!s->budget--) { s->failed_pc=0x0c0ba2e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba2e4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba2e4u) { target=s->pc; goto dispatch; }
goto P_0c0ba2e4;
P_0c0ba2e2: /* original 05de, guest PC 0x0c0ba2e2 */
if(!s->budget--) { s->failed_pc=0x0c0ba2e2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba2e4;
P_0c0ba2e4: /* original 9552, guest PC 0x0c0ba2e4 */
if(!s->budget--) { s->failed_pc=0x0c0ba2e4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba38cu,2);
goto P_0c0ba2e6;
P_0c0ba2e6: /* original 35dc, guest PC 0x0c0ba2e6 */
if(!s->budget--) { s->failed_pc=0x0c0ba2e6u; return 0; }
r[5]+=r[13];
goto P_0c0ba2e8;
P_0c0ba2e8: /* original 2f52, guest PC 0x0c0ba2e8 */
if(!s->budget--) { s->failed_pc=0x0c0ba2e8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ba2ea;
P_0c0ba2ea: /* original 9450, guest PC 0x0c0ba2ea */
if(!s->budget--) { s->failed_pc=0x0c0ba2eau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba38eu,2);
goto P_0c0ba2ec;
P_0c0ba2ec: /* original 4e0b, guest PC 0x0c0ba2ec */
if(!s->budget--) { s->failed_pc=0x0c0ba2ecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba2f0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba2f0u) { target=s->pc; goto dispatch; }
goto P_0c0ba2f0;
P_0c0ba2ee: /* original 6552, guest PC 0x0c0ba2ee */
if(!s->budget--) { s->failed_pc=0x0c0ba2eeu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0ba2f0;
P_0c0ba2f0: /* original 944e, guest PC 0x0c0ba2f0 */
if(!s->budget--) { s->failed_pc=0x0c0ba2f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba390u,2);
goto P_0c0ba2f2;
P_0c0ba2f2: /* original 65f2, guest PC 0x0c0ba2f2 */
if(!s->budget--) { s->failed_pc=0x0c0ba2f2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ba2f4;
P_0c0ba2f4: /* original 4e0b, guest PC 0x0c0ba2f4 */
if(!s->budget--) { s->failed_pc=0x0c0ba2f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba2f8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba2f8u) { target=s->pc; goto dispatch; }
goto P_0c0ba2f8;
P_0c0ba2f6: /* original 6552, guest PC 0x0c0ba2f6 */
if(!s->budget--) { s->failed_pc=0x0c0ba2f6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0ba2f8;
P_0c0ba2f8: /* original 954b, guest PC 0x0c0ba2f8 */
if(!s->budget--) { s->failed_pc=0x0c0ba2f8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba392u,2);
goto P_0c0ba2fa;
P_0c0ba2fa: /* original 35dc, guest PC 0x0c0ba2fa */
if(!s->budget--) { s->failed_pc=0x0c0ba2fau; return 0; }
r[5]+=r[13];
goto P_0c0ba2fc;
P_0c0ba2fc: /* original 2f52, guest PC 0x0c0ba2fc */
if(!s->budget--) { s->failed_pc=0x0c0ba2fcu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ba2fe;
P_0c0ba2fe: /* original 9449, guest PC 0x0c0ba2fe */
if(!s->budget--) { s->failed_pc=0x0c0ba2feu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba394u,2);
goto P_0c0ba300;
P_0c0ba300: /* original 4e0b, guest PC 0x0c0ba300 */
if(!s->budget--) { s->failed_pc=0x0c0ba300u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba304u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba304u) { target=s->pc; goto dispatch; }
goto P_0c0ba304;
P_0c0ba302: /* original 6552, guest PC 0x0c0ba302 */
if(!s->budget--) { s->failed_pc=0x0c0ba302u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0ba304;
P_0c0ba304: /* original 9447, guest PC 0x0c0ba304 */
if(!s->budget--) { s->failed_pc=0x0c0ba304u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba396u,2);
goto P_0c0ba306;
P_0c0ba306: /* original 65f2, guest PC 0x0c0ba306 */
if(!s->budget--) { s->failed_pc=0x0c0ba306u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ba308;
P_0c0ba308: /* original 4e0b, guest PC 0x0c0ba308 */
if(!s->budget--) { s->failed_pc=0x0c0ba308u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba30cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba30cu) { target=s->pc; goto dispatch; }
goto P_0c0ba30c;
P_0c0ba30a: /* original 6552, guest PC 0x0c0ba30a */
if(!s->budget--) { s->failed_pc=0x0c0ba30au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0ba30c;
P_0c0ba30c: /* original 9445, guest PC 0x0c0ba30c */
if(!s->budget--) { s->failed_pc=0x0c0ba30cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba39au,2);
goto P_0c0ba30e;
P_0c0ba30e: /* original 9043, guest PC 0x0c0ba30e */
if(!s->budget--) { s->failed_pc=0x0c0ba30eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba398u,2);
goto P_0c0ba310;
P_0c0ba310: /* original 4e0b, guest PC 0x0c0ba310 */
if(!s->budget--) { s->failed_pc=0x0c0ba310u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba314u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba314u) { target=s->pc; goto dispatch; }
goto P_0c0ba314;
P_0c0ba312: /* original 05de, guest PC 0x0c0ba312 */
if(!s->budget--) { s->failed_pc=0x0c0ba312u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba314;
P_0c0ba314: /* original 9443, guest PC 0x0c0ba314 */
if(!s->budget--) { s->failed_pc=0x0c0ba314u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba39eu,2);
goto P_0c0ba316;
P_0c0ba316: /* original 9041, guest PC 0x0c0ba316 */
if(!s->budget--) { s->failed_pc=0x0c0ba316u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba39cu,2);
goto P_0c0ba318;
P_0c0ba318: /* original 4e0b, guest PC 0x0c0ba318 */
if(!s->budget--) { s->failed_pc=0x0c0ba318u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba31cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba31cu) { target=s->pc; goto dispatch; }
goto P_0c0ba31c;
P_0c0ba31a: /* original 05de, guest PC 0x0c0ba31a */
if(!s->budget--) { s->failed_pc=0x0c0ba31au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba31c;
P_0c0ba31c: /* original 9441, guest PC 0x0c0ba31c */
if(!s->budget--) { s->failed_pc=0x0c0ba31cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba3a2u,2);
goto P_0c0ba31e;
P_0c0ba31e: /* original 903f, guest PC 0x0c0ba31e */
if(!s->budget--) { s->failed_pc=0x0c0ba31eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba3a0u,2);
goto P_0c0ba320;
P_0c0ba320: /* original 4e0b, guest PC 0x0c0ba320 */
if(!s->budget--) { s->failed_pc=0x0c0ba320u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba324u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba324u) { target=s->pc; goto dispatch; }
goto P_0c0ba324;
P_0c0ba322: /* original 05de, guest PC 0x0c0ba322 */
if(!s->budget--) { s->failed_pc=0x0c0ba322u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba324;
P_0c0ba324: /* original 943f, guest PC 0x0c0ba324 */
if(!s->budget--) { s->failed_pc=0x0c0ba324u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba3a6u,2);
goto P_0c0ba326;
P_0c0ba326: /* original 903d, guest PC 0x0c0ba326 */
if(!s->budget--) { s->failed_pc=0x0c0ba326u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba3a4u,2);
goto P_0c0ba328;
P_0c0ba328: /* original 4e0b, guest PC 0x0c0ba328 */
if(!s->budget--) { s->failed_pc=0x0c0ba328u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba32cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba32cu) { target=s->pc; goto dispatch; }
goto P_0c0ba32c;
P_0c0ba32a: /* original 05de, guest PC 0x0c0ba32a */
if(!s->budget--) { s->failed_pc=0x0c0ba32au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba32c;
P_0c0ba32c: /* original 903c, guest PC 0x0c0ba32c */
if(!s->budget--) { s->failed_pc=0x0c0ba32cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba3a8u,2);
goto P_0c0ba32e;
P_0c0ba32e: /* original a03c, guest PC 0x0c0ba32e */
if(!s->budget--) { s->failed_pc=0x0c0ba32eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba3aa;
P_0c0ba330: /* original 05de, guest PC 0x0c0ba330 */
if(!s->budget--) { s->failed_pc=0x0c0ba330u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0ba332u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ba332u; return 0; } return 1;
P_0c0ba3aa: /* original 943e, guest PC 0x0c0ba3aa */
if(!s->budget--) { s->failed_pc=0x0c0ba3aau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba42au,2);
goto P_0c0ba3ac;
P_0c0ba3ac: /* original 4e0b, guest PC 0x0c0ba3ac */
if(!s->budget--) { s->failed_pc=0x0c0ba3acu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba3b0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba3b0u) { target=s->pc; goto dispatch; }
goto P_0c0ba3b0;
P_0c0ba3ae: /* original 0009, guest PC 0x0c0ba3ae */
if(!s->budget--) { s->failed_pc=0x0c0ba3aeu; return 0; }
goto P_0c0ba3b0;
P_0c0ba3b0: /* original 943d, guest PC 0x0c0ba3b0 */
if(!s->budget--) { s->failed_pc=0x0c0ba3b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba42eu,2);
goto P_0c0ba3b2;
P_0c0ba3b2: /* original 903b, guest PC 0x0c0ba3b2 */
if(!s->budget--) { s->failed_pc=0x0c0ba3b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba42cu,2);
goto P_0c0ba3b4;
P_0c0ba3b4: /* original 4e0b, guest PC 0x0c0ba3b4 */
if(!s->budget--) { s->failed_pc=0x0c0ba3b4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba3b8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba3b8u) { target=s->pc; goto dispatch; }
goto P_0c0ba3b8;
P_0c0ba3b6: /* original 05de, guest PC 0x0c0ba3b6 */
if(!s->budget--) { s->failed_pc=0x0c0ba3b6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba3b8;
P_0c0ba3b8: /* original 943b, guest PC 0x0c0ba3b8 */
if(!s->budget--) { s->failed_pc=0x0c0ba3b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba432u,2);
goto P_0c0ba3ba;
P_0c0ba3ba: /* original 9039, guest PC 0x0c0ba3ba */
if(!s->budget--) { s->failed_pc=0x0c0ba3bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba430u,2);
goto P_0c0ba3bc;
P_0c0ba3bc: /* original 4e0b, guest PC 0x0c0ba3bc */
if(!s->budget--) { s->failed_pc=0x0c0ba3bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba3c0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba3c0u) { target=s->pc; goto dispatch; }
goto P_0c0ba3c0;
P_0c0ba3be: /* original 05de, guest PC 0x0c0ba3be */
if(!s->budget--) { s->failed_pc=0x0c0ba3beu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba3c0;
P_0c0ba3c0: /* original 9439, guest PC 0x0c0ba3c0 */
if(!s->budget--) { s->failed_pc=0x0c0ba3c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba436u,2);
goto P_0c0ba3c2;
P_0c0ba3c2: /* original 9037, guest PC 0x0c0ba3c2 */
if(!s->budget--) { s->failed_pc=0x0c0ba3c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba434u,2);
goto P_0c0ba3c4;
P_0c0ba3c4: /* original 4e0b, guest PC 0x0c0ba3c4 */
if(!s->budget--) { s->failed_pc=0x0c0ba3c4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba3c8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba3c8u) { target=s->pc; goto dispatch; }
goto P_0c0ba3c8;
P_0c0ba3c6: /* original 05de, guest PC 0x0c0ba3c6 */
if(!s->budget--) { s->failed_pc=0x0c0ba3c6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba3c8;
P_0c0ba3c8: /* original 9437, guest PC 0x0c0ba3c8 */
if(!s->budget--) { s->failed_pc=0x0c0ba3c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba43au,2);
goto P_0c0ba3ca;
P_0c0ba3ca: /* original 9035, guest PC 0x0c0ba3ca */
if(!s->budget--) { s->failed_pc=0x0c0ba3cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba438u,2);
goto P_0c0ba3cc;
P_0c0ba3cc: /* original 4e0b, guest PC 0x0c0ba3cc */
if(!s->budget--) { s->failed_pc=0x0c0ba3ccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba3d0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba3d0u) { target=s->pc; goto dispatch; }
goto P_0c0ba3d0;
P_0c0ba3ce: /* original 05de, guest PC 0x0c0ba3ce */
if(!s->budget--) { s->failed_pc=0x0c0ba3ceu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba3d0;
P_0c0ba3d0: /* original 9435, guest PC 0x0c0ba3d0 */
if(!s->budget--) { s->failed_pc=0x0c0ba3d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba43eu,2);
goto P_0c0ba3d2;
P_0c0ba3d2: /* original 9033, guest PC 0x0c0ba3d2 */
if(!s->budget--) { s->failed_pc=0x0c0ba3d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba43cu,2);
goto P_0c0ba3d4;
P_0c0ba3d4: /* original 4e0b, guest PC 0x0c0ba3d4 */
if(!s->budget--) { s->failed_pc=0x0c0ba3d4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba3d8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba3d8u) { target=s->pc; goto dispatch; }
goto P_0c0ba3d8;
P_0c0ba3d6: /* original 05de, guest PC 0x0c0ba3d6 */
if(!s->budget--) { s->failed_pc=0x0c0ba3d6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba3d8;
P_0c0ba3d8: /* original 9433, guest PC 0x0c0ba3d8 */
if(!s->budget--) { s->failed_pc=0x0c0ba3d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba442u,2);
goto P_0c0ba3da;
P_0c0ba3da: /* original 9031, guest PC 0x0c0ba3da */
if(!s->budget--) { s->failed_pc=0x0c0ba3dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba440u,2);
goto P_0c0ba3dc;
P_0c0ba3dc: /* original 4e0b, guest PC 0x0c0ba3dc */
if(!s->budget--) { s->failed_pc=0x0c0ba3dcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba3e0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba3e0u) { target=s->pc; goto dispatch; }
goto P_0c0ba3e0;
P_0c0ba3de: /* original 05de, guest PC 0x0c0ba3de */
if(!s->budget--) { s->failed_pc=0x0c0ba3deu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba3e0;
P_0c0ba3e0: /* original 9431, guest PC 0x0c0ba3e0 */
if(!s->budget--) { s->failed_pc=0x0c0ba3e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba446u,2);
goto P_0c0ba3e2;
P_0c0ba3e2: /* original 902f, guest PC 0x0c0ba3e2 */
if(!s->budget--) { s->failed_pc=0x0c0ba3e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba444u,2);
goto P_0c0ba3e4;
P_0c0ba3e4: /* original 4e0b, guest PC 0x0c0ba3e4 */
if(!s->budget--) { s->failed_pc=0x0c0ba3e4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba3e8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba3e8u) { target=s->pc; goto dispatch; }
goto P_0c0ba3e8;
P_0c0ba3e6: /* original 05de, guest PC 0x0c0ba3e6 */
if(!s->budget--) { s->failed_pc=0x0c0ba3e6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba3e8;
P_0c0ba3e8: /* original 942f, guest PC 0x0c0ba3e8 */
if(!s->budget--) { s->failed_pc=0x0c0ba3e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba44au,2);
goto P_0c0ba3ea;
P_0c0ba3ea: /* original 902d, guest PC 0x0c0ba3ea */
if(!s->budget--) { s->failed_pc=0x0c0ba3eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba448u,2);
goto P_0c0ba3ec;
P_0c0ba3ec: /* original 4e0b, guest PC 0x0c0ba3ec */
if(!s->budget--) { s->failed_pc=0x0c0ba3ecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba3f0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba3f0u) { target=s->pc; goto dispatch; }
goto P_0c0ba3f0;
P_0c0ba3ee: /* original 05de, guest PC 0x0c0ba3ee */
if(!s->budget--) { s->failed_pc=0x0c0ba3eeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba3f0;
P_0c0ba3f0: /* original 942d, guest PC 0x0c0ba3f0 */
if(!s->budget--) { s->failed_pc=0x0c0ba3f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba44eu,2);
goto P_0c0ba3f2;
P_0c0ba3f2: /* original 902b, guest PC 0x0c0ba3f2 */
if(!s->budget--) { s->failed_pc=0x0c0ba3f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba44cu,2);
goto P_0c0ba3f4;
P_0c0ba3f4: /* original 4e0b, guest PC 0x0c0ba3f4 */
if(!s->budget--) { s->failed_pc=0x0c0ba3f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba3f8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba3f8u) { target=s->pc; goto dispatch; }
goto P_0c0ba3f8;
P_0c0ba3f6: /* original 05de, guest PC 0x0c0ba3f6 */
if(!s->budget--) { s->failed_pc=0x0c0ba3f6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba3f8;
P_0c0ba3f8: /* original 942b, guest PC 0x0c0ba3f8 */
if(!s->budget--) { s->failed_pc=0x0c0ba3f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba452u,2);
goto P_0c0ba3fa;
P_0c0ba3fa: /* original 9029, guest PC 0x0c0ba3fa */
if(!s->budget--) { s->failed_pc=0x0c0ba3fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba450u,2);
goto P_0c0ba3fc;
P_0c0ba3fc: /* original 4e0b, guest PC 0x0c0ba3fc */
if(!s->budget--) { s->failed_pc=0x0c0ba3fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba400u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba400u) { target=s->pc; goto dispatch; }
goto P_0c0ba400;
P_0c0ba3fe: /* original 05de, guest PC 0x0c0ba3fe */
if(!s->budget--) { s->failed_pc=0x0c0ba3feu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba400;
P_0c0ba400: /* original 9429, guest PC 0x0c0ba400 */
if(!s->budget--) { s->failed_pc=0x0c0ba400u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba456u,2);
goto P_0c0ba402;
P_0c0ba402: /* original 9027, guest PC 0x0c0ba402 */
if(!s->budget--) { s->failed_pc=0x0c0ba402u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba454u,2);
goto P_0c0ba404;
P_0c0ba404: /* original 4e0b, guest PC 0x0c0ba404 */
if(!s->budget--) { s->failed_pc=0x0c0ba404u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba408u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba408u) { target=s->pc; goto dispatch; }
goto P_0c0ba408;
P_0c0ba406: /* original 05de, guest PC 0x0c0ba406 */
if(!s->budget--) { s->failed_pc=0x0c0ba406u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba408;
P_0c0ba408: /* original 9427, guest PC 0x0c0ba408 */
if(!s->budget--) { s->failed_pc=0x0c0ba408u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba45au,2);
goto P_0c0ba40a;
P_0c0ba40a: /* original 9025, guest PC 0x0c0ba40a */
if(!s->budget--) { s->failed_pc=0x0c0ba40au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba458u,2);
goto P_0c0ba40c;
P_0c0ba40c: /* original 4e0b, guest PC 0x0c0ba40c */
if(!s->budget--) { s->failed_pc=0x0c0ba40cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba410u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba410u) { target=s->pc; goto dispatch; }
goto P_0c0ba410;
P_0c0ba40e: /* original 05de, guest PC 0x0c0ba40e */
if(!s->budget--) { s->failed_pc=0x0c0ba40eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba410;
P_0c0ba410: /* original 9425, guest PC 0x0c0ba410 */
if(!s->budget--) { s->failed_pc=0x0c0ba410u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba45eu,2);
goto P_0c0ba412;
P_0c0ba412: /* original 9023, guest PC 0x0c0ba412 */
if(!s->budget--) { s->failed_pc=0x0c0ba412u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ba45cu,2);
goto P_0c0ba414;
P_0c0ba414: /* original 4e0b, guest PC 0x0c0ba414 */
if(!s->budget--) { s->failed_pc=0x0c0ba414u; return 0; }
target=r[14];
r[16]=code_base|0x0c0ba418u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ba418u) { target=s->pc; goto dispatch; }
goto P_0c0ba418;
P_0c0ba416: /* original 05de, guest PC 0x0c0ba416 */
if(!s->budget--) { s->failed_pc=0x0c0ba416u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0ba418;
P_0c0ba418: /* original 7f08, guest PC 0x0c0ba418 */
if(!s->budget--) { s->failed_pc=0x0c0ba418u; return 0; }
r[15]+=0x00000008u;
goto P_0c0ba41a;
P_0c0ba41a: /* original 4f26, guest PC 0x0c0ba41a */
if(!s->budget--) { s->failed_pc=0x0c0ba41au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ba41c;
P_0c0ba41c: /* original 69f6, guest PC 0x0c0ba41c */
if(!s->budget--) { s->failed_pc=0x0c0ba41cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0ba41e;
P_0c0ba41e: /* original 6af6, guest PC 0x0c0ba41e */
if(!s->budget--) { s->failed_pc=0x0c0ba41eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0ba420;
P_0c0ba420: /* original 6bf6, guest PC 0x0c0ba420 */
if(!s->budget--) { s->failed_pc=0x0c0ba420u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ba422;
P_0c0ba422: /* original 6cf6, guest PC 0x0c0ba422 */
if(!s->budget--) { s->failed_pc=0x0c0ba422u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ba424;
P_0c0ba424: /* original 6df6, guest PC 0x0c0ba424 */
if(!s->budget--) { s->failed_pc=0x0c0ba424u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ba426;
P_0c0ba426: /* original 000b, guest PC 0x0c0ba426 */
if(!s->budget--) { s->failed_pc=0x0c0ba426u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ba428: /* original 6ef6, guest PC 0x0c0ba428 */
if(!s->budget--) { s->failed_pc=0x0c0ba428u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ba42au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ba42au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
