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
int vf3_away_batch10_adapter_24(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06f068u: goto P_0c06f068;
case 0x0c06f06au: goto P_0c06f06a;
case 0x0c06f06cu: goto P_0c06f06c;
case 0x0c06f06eu: goto P_0c06f06e;
case 0x0c06f070u: goto P_0c06f070;
case 0x0c06f072u: goto P_0c06f072;
case 0x0c06f074u: goto P_0c06f074;
case 0x0c06f076u: goto P_0c06f076;
case 0x0c06f078u: goto P_0c06f078;
case 0x0c06f07au: goto P_0c06f07a;
case 0x0c06f07cu: goto P_0c06f07c;
case 0x0c06f07eu: goto P_0c06f07e;
case 0x0c06f080u: goto P_0c06f080;
case 0x0c06f082u: goto P_0c06f082;
case 0x0c06f084u: goto P_0c06f084;
case 0x0c06f086u: goto P_0c06f086;
case 0x0c06f088u: goto P_0c06f088;
case 0x0c06f08au: goto P_0c06f08a;
case 0x0c06f08cu: goto P_0c06f08c;
case 0x0c06f08eu: goto P_0c06f08e;
case 0x0c06f090u: goto P_0c06f090;
case 0x0c06f092u: goto P_0c06f092;
case 0x0c06f094u: goto P_0c06f094;
case 0x0c06f096u: goto P_0c06f096;
case 0x0c06f098u: goto P_0c06f098;
case 0x0c06f09au: goto P_0c06f09a;
case 0x0c06f09cu: goto P_0c06f09c;
case 0x0c06f09eu: goto P_0c06f09e;
case 0x0c06f0a0u: goto P_0c06f0a0;
case 0x0c06f0a2u: goto P_0c06f0a2;
case 0x0c06f0a4u: goto P_0c06f0a4;
case 0x0c06f0a6u: goto P_0c06f0a6;
case 0x0c06f0a8u: goto P_0c06f0a8;
case 0x0c06f0aau: goto P_0c06f0aa;
case 0x0c06f0acu: goto P_0c06f0ac;
case 0x0c06f0aeu: goto P_0c06f0ae;
case 0x0c06f0b0u: goto P_0c06f0b0;
case 0x0c06f0b2u: goto P_0c06f0b2;
case 0x0c06f0b4u: goto P_0c06f0b4;
case 0x0c06f0b6u: goto P_0c06f0b6;
case 0x0c06f0b8u: goto P_0c06f0b8;
case 0x0c06f0bau: goto P_0c06f0ba;
case 0x0c06f0bcu: goto P_0c06f0bc;
case 0x0c06f0beu: goto P_0c06f0be;
case 0x0c06f0c0u: goto P_0c06f0c0;
case 0x0c06f0c2u: goto P_0c06f0c2;
case 0x0c06f0c4u: goto P_0c06f0c4;
case 0x0c06f0c6u: goto P_0c06f0c6;
case 0x0c06f0c8u: goto P_0c06f0c8;
case 0x0c06f0cau: goto P_0c06f0ca;
case 0x0c06f0ccu: goto P_0c06f0cc;
case 0x0c06f0ceu: goto P_0c06f0ce;
case 0x0c06f0d0u: goto P_0c06f0d0;
case 0x0c06f0d2u: goto P_0c06f0d2;
case 0x0c06f0d4u: goto P_0c06f0d4;
case 0x0c06f0d6u: goto P_0c06f0d6;
case 0x0c06f0d8u: goto P_0c06f0d8;
case 0x0c06f0dau: goto P_0c06f0da;
case 0x0c06f0dcu: goto P_0c06f0dc;
case 0x0c06f0deu: goto P_0c06f0de;
case 0x0c06f0e0u: goto P_0c06f0e0;
case 0x0c06f0e2u: goto P_0c06f0e2;
case 0x0c06f0e4u: goto P_0c06f0e4;
case 0x0c06f0e6u: goto P_0c06f0e6;
case 0x0c06f0e8u: goto P_0c06f0e8;
case 0x0c06f0eau: goto P_0c06f0ea;
case 0x0c06f0ecu: goto P_0c06f0ec;
case 0x0c06f0eeu: goto P_0c06f0ee;
case 0x0c06f0f0u: goto P_0c06f0f0;
case 0x0c06f0f2u: goto P_0c06f0f2;
case 0x0c06f0f4u: goto P_0c06f0f4;
case 0x0c06f0f6u: goto P_0c06f0f6;
case 0x0c06f0f8u: goto P_0c06f0f8;
case 0x0c06f0fau: goto P_0c06f0fa;
case 0x0c06f0fcu: goto P_0c06f0fc;
case 0x0c06f0feu: goto P_0c06f0fe;
case 0x0c06f100u: goto P_0c06f100;
case 0x0c06f102u: goto P_0c06f102;
case 0x0c06f104u: goto P_0c06f104;
case 0x0c06f106u: goto P_0c06f106;
case 0x0c06f108u: goto P_0c06f108;
case 0x0c06f10au: goto P_0c06f10a;
case 0x0c06f10cu: goto P_0c06f10c;
case 0x0c06f10eu: goto P_0c06f10e;
case 0x0c06f110u: goto P_0c06f110;
case 0x0c06f112u: goto P_0c06f112;
case 0x0c06f114u: goto P_0c06f114;
case 0x0c06f116u: goto P_0c06f116;
case 0x0c06f118u: goto P_0c06f118;
case 0x0c06f11au: goto P_0c06f11a;
case 0x0c06f11cu: goto P_0c06f11c;
case 0x0c06f11eu: goto P_0c06f11e;
case 0x0c06f120u: goto P_0c06f120;
case 0x0c06f122u: goto P_0c06f122;
case 0x0c06f124u: goto P_0c06f124;
case 0x0c06f126u: goto P_0c06f126;
case 0x0c06f128u: goto P_0c06f128;
case 0x0c06f12au: goto P_0c06f12a;
case 0x0c06f12cu: goto P_0c06f12c;
case 0x0c06f12eu: goto P_0c06f12e;
case 0x0c06f130u: goto P_0c06f130;
case 0x0c06f132u: goto P_0c06f132;
case 0x0c06f134u: goto P_0c06f134;
case 0x0c06f136u: goto P_0c06f136;
case 0x0c06f138u: goto P_0c06f138;
case 0x0c06f13au: goto P_0c06f13a;
case 0x0c06f13cu: goto P_0c06f13c;
case 0x0c06f13eu: goto P_0c06f13e;
case 0x0c06f140u: goto P_0c06f140;
case 0x0c06f142u: goto P_0c06f142;
case 0x0c06f144u: goto P_0c06f144;
case 0x0c06f146u: goto P_0c06f146;
case 0x0c06f148u: goto P_0c06f148;
case 0x0c06f14au: goto P_0c06f14a;
case 0x0c06f14cu: goto P_0c06f14c;
case 0x0c06f14eu: goto P_0c06f14e;
case 0x0c06f150u: goto P_0c06f150;
case 0x0c06f152u: goto P_0c06f152;
case 0x0c06f154u: goto P_0c06f154;
case 0x0c06f156u: goto P_0c06f156;
case 0x0c06f158u: goto P_0c06f158;
case 0x0c06f15au: goto P_0c06f15a;
case 0x0c06f15cu: goto P_0c06f15c;
case 0x0c06f15eu: goto P_0c06f15e;
case 0x0c06f160u: goto P_0c06f160;
case 0x0c06f162u: goto P_0c06f162;
case 0x0c06f164u: goto P_0c06f164;
case 0x0c06f166u: goto P_0c06f166;
case 0x0c06f168u: goto P_0c06f168;
case 0x0c06f16au: goto P_0c06f16a;
case 0x0c06f16cu: goto P_0c06f16c;
case 0x0c06f16eu: goto P_0c06f16e;
case 0x0c06f170u: goto P_0c06f170;
case 0x0c06f172u: goto P_0c06f172;
case 0x0c06f174u: goto P_0c06f174;
case 0x0c06f176u: goto P_0c06f176;
case 0x0c06f178u: goto P_0c06f178;
case 0x0c06f17au: goto P_0c06f17a;
case 0x0c06f17cu: goto P_0c06f17c;
case 0x0c06f17eu: goto P_0c06f17e;
case 0x0c06f180u: goto P_0c06f180;
case 0x0c06f182u: goto P_0c06f182;
case 0x0c06f184u: goto P_0c06f184;
case 0x0c06f186u: goto P_0c06f186;
case 0x0c06f188u: goto P_0c06f188;
case 0x0c06f18au: goto P_0c06f18a;
case 0x0c06f18cu: goto P_0c06f18c;
case 0x0c06f18eu: goto P_0c06f18e;
case 0x0c06f190u: goto P_0c06f190;
case 0x0c06f192u: goto P_0c06f192;
case 0x0c06f194u: goto P_0c06f194;
case 0x0c06f196u: goto P_0c06f196;
case 0x0c06f198u: goto P_0c06f198;
case 0x0c06f19au: goto P_0c06f19a;
case 0x0c06f19cu: goto P_0c06f19c;
case 0x0c06f19eu: goto P_0c06f19e;
case 0x0c06f1a0u: goto P_0c06f1a0;
case 0x0c06f1a2u: goto P_0c06f1a2;
case 0x0c06f1a4u: goto P_0c06f1a4;
case 0x0c06f1c8u: goto P_0c06f1c8;
case 0x0c06f1cau: goto P_0c06f1ca;
case 0x0c06f1ccu: goto P_0c06f1cc;
case 0x0c06f1ceu: goto P_0c06f1ce;
case 0x0c06f1d0u: goto P_0c06f1d0;
case 0x0c06f1d2u: goto P_0c06f1d2;
case 0x0c06f1d4u: goto P_0c06f1d4;
case 0x0c06f1d6u: goto P_0c06f1d6;
case 0x0c06f1d8u: goto P_0c06f1d8;
case 0x0c06f1dau: goto P_0c06f1da;
case 0x0c06f1dcu: goto P_0c06f1dc;
case 0x0c06f1deu: goto P_0c06f1de;
case 0x0c06f1e0u: goto P_0c06f1e0;
case 0x0c06f1e2u: goto P_0c06f1e2;
case 0x0c06f1e4u: goto P_0c06f1e4;
case 0x0c06f1e6u: goto P_0c06f1e6;
case 0x0c06f1e8u: goto P_0c06f1e8;
case 0x0c06f1eau: goto P_0c06f1ea;
case 0x0c06f1ecu: goto P_0c06f1ec;
case 0x0c06f1eeu: goto P_0c06f1ee;
case 0x0c06f1f0u: goto P_0c06f1f0;
case 0x0c06f1f2u: goto P_0c06f1f2;
case 0x0c06f1f4u: goto P_0c06f1f4;
case 0x0c06f1f6u: goto P_0c06f1f6;
case 0x0c06f1f8u: goto P_0c06f1f8;
case 0x0c06f1fau: goto P_0c06f1fa;
case 0x0c06f1fcu: goto P_0c06f1fc;
case 0x0c06f1feu: goto P_0c06f1fe;
case 0x0c06f200u: goto P_0c06f200;
case 0x0c06f202u: goto P_0c06f202;
case 0x0c06f204u: goto P_0c06f204;
case 0x0c06f206u: goto P_0c06f206;
case 0x0c06f208u: goto P_0c06f208;
case 0x0c06f20au: goto P_0c06f20a;
case 0x0c06f20cu: goto P_0c06f20c;
case 0x0c06f20eu: goto P_0c06f20e;
case 0x0c06f210u: goto P_0c06f210;
case 0x0c06f212u: goto P_0c06f212;
case 0x0c06f214u: goto P_0c06f214;
case 0x0c06f216u: goto P_0c06f216;
case 0x0c06f218u: goto P_0c06f218;
case 0x0c06f21au: goto P_0c06f21a;
case 0x0c06f21cu: goto P_0c06f21c;
case 0x0c06f21eu: goto P_0c06f21e;
case 0x0c06f220u: goto P_0c06f220;
case 0x0c06f222u: goto P_0c06f222;
case 0x0c06f224u: goto P_0c06f224;
case 0x0c06f226u: goto P_0c06f226;
case 0x0c06f228u: goto P_0c06f228;
case 0x0c06f22au: goto P_0c06f22a;
case 0x0c06f22cu: goto P_0c06f22c;
case 0x0c06f22eu: goto P_0c06f22e;
case 0x0c06f230u: goto P_0c06f230;
case 0x0c06f232u: goto P_0c06f232;
case 0x0c06f234u: goto P_0c06f234;
case 0x0c06f236u: goto P_0c06f236;
case 0x0c06f238u: goto P_0c06f238;
case 0x0c06f23au: goto P_0c06f23a;
case 0x0c06f23cu: goto P_0c06f23c;
case 0x0c06f23eu: goto P_0c06f23e;
case 0x0c06f240u: goto P_0c06f240;
case 0x0c06f242u: goto P_0c06f242;
case 0x0c06f244u: goto P_0c06f244;
case 0x0c06f246u: goto P_0c06f246;
case 0x0c06f248u: goto P_0c06f248;
case 0x0c06f24au: goto P_0c06f24a;
case 0x0c06f24cu: goto P_0c06f24c;
case 0x0c06f24eu: goto P_0c06f24e;
case 0x0c06f250u: goto P_0c06f250;
case 0x0c06f252u: goto P_0c06f252;
case 0x0c06f254u: goto P_0c06f254;
case 0x0c06f256u: goto P_0c06f256;
case 0x0c06f258u: goto P_0c06f258;
case 0x0c06f25au: goto P_0c06f25a;
case 0x0c06f25cu: goto P_0c06f25c;
case 0x0c06f25eu: goto P_0c06f25e;
case 0x0c06f260u: goto P_0c06f260;
case 0x0c06f262u: goto P_0c06f262;
case 0x0c06f264u: goto P_0c06f264;
case 0x0c06f266u: goto P_0c06f266;
case 0x0c06f268u: goto P_0c06f268;
case 0x0c06f26au: goto P_0c06f26a;
case 0x0c06f26cu: goto P_0c06f26c;
case 0x0c06f26eu: goto P_0c06f26e;
case 0x0c06f270u: goto P_0c06f270;
case 0x0c06f272u: goto P_0c06f272;
case 0x0c06f274u: goto P_0c06f274;
case 0x0c06f276u: goto P_0c06f276;
case 0x0c06f278u: goto P_0c06f278;
case 0x0c06f27au: goto P_0c06f27a;
case 0x0c06f27cu: goto P_0c06f27c;
case 0x0c06f27eu: goto P_0c06f27e;
case 0x0c06f280u: goto P_0c06f280;
case 0x0c06f282u: goto P_0c06f282;
case 0x0c06f284u: goto P_0c06f284;
case 0x0c06f286u: goto P_0c06f286;
case 0x0c06f288u: goto P_0c06f288;
case 0x0c06f28au: goto P_0c06f28a;
case 0x0c06f28cu: goto P_0c06f28c;
case 0x0c06f28eu: goto P_0c06f28e;
case 0x0c06f290u: goto P_0c06f290;
case 0x0c06f292u: goto P_0c06f292;
case 0x0c06f294u: goto P_0c06f294;
case 0x0c06f296u: goto P_0c06f296;
case 0x0c06f298u: goto P_0c06f298;
case 0x0c06f29au: goto P_0c06f29a;
case 0x0c06f29cu: goto P_0c06f29c;
case 0x0c06f29eu: goto P_0c06f29e;
case 0x0c06f2a0u: goto P_0c06f2a0;
case 0x0c06f2a2u: goto P_0c06f2a2;
case 0x0c06f2a4u: goto P_0c06f2a4;
case 0x0c06f2a6u: goto P_0c06f2a6;
case 0x0c06f2a8u: goto P_0c06f2a8;
case 0x0c06f2aau: goto P_0c06f2aa;
case 0x0c06f2acu: goto P_0c06f2ac;
case 0x0c06f2aeu: goto P_0c06f2ae;
case 0x0c06f2b0u: goto P_0c06f2b0;
case 0x0c06f2b2u: goto P_0c06f2b2;
case 0x0c06f2b4u: goto P_0c06f2b4;
case 0x0c06f2b6u: goto P_0c06f2b6;
case 0x0c06f2b8u: goto P_0c06f2b8;
case 0x0c06f2bau: goto P_0c06f2ba;
case 0x0c06f2bcu: goto P_0c06f2bc;
case 0x0c06f2beu: goto P_0c06f2be;
case 0x0c06f2c0u: goto P_0c06f2c0;
case 0x0c06f2c2u: goto P_0c06f2c2;
case 0x0c06f2c4u: goto P_0c06f2c4;
case 0x0c06f2c6u: goto P_0c06f2c6;
case 0x0c06f2c8u: goto P_0c06f2c8;
case 0x0c06f2cau: goto P_0c06f2ca;
case 0x0c06f2ccu: goto P_0c06f2cc;
case 0x0c06f2ceu: goto P_0c06f2ce;
case 0x0c06f2d0u: goto P_0c06f2d0;
case 0x0c06f2d2u: goto P_0c06f2d2;
case 0x0c06f2d4u: goto P_0c06f2d4;
case 0x0c06f2d6u: goto P_0c06f2d6;
case 0x0c06f2d8u: goto P_0c06f2d8;
case 0x0c06f2dau: goto P_0c06f2da;
case 0x0c06f2dcu: goto P_0c06f2dc;
case 0x0c06f2deu: goto P_0c06f2de;
case 0x0c06f2e0u: goto P_0c06f2e0;
case 0x0c06f2e2u: goto P_0c06f2e2;
case 0x0c06f2e4u: goto P_0c06f2e4;
case 0x0c06f2e6u: goto P_0c06f2e6;
case 0x0c06f2e8u: goto P_0c06f2e8;
case 0x0c06f2eau: goto P_0c06f2ea;
case 0x0c06f2ecu: goto P_0c06f2ec;
case 0x0c06f2eeu: goto P_0c06f2ee;
case 0x0c06f2f0u: goto P_0c06f2f0;
case 0x0c06f2f2u: goto P_0c06f2f2;
case 0x0c06f2f4u: goto P_0c06f2f4;
case 0x0c06f2f6u: goto P_0c06f2f6;
case 0x0c06f2f8u: goto P_0c06f2f8;
case 0x0c06f2fau: goto P_0c06f2fa;
case 0x0c06f2fcu: goto P_0c06f2fc;
case 0x0c06f2feu: goto P_0c06f2fe;
case 0x0c06f300u: goto P_0c06f300;
case 0x0c06f302u: goto P_0c06f302;
case 0x0c06f304u: goto P_0c06f304;
case 0x0c06f306u: goto P_0c06f306;
case 0x0c06f308u: goto P_0c06f308;
case 0x0c06f30au: goto P_0c06f30a;
case 0x0c06f30cu: goto P_0c06f30c;
case 0x0c06f30eu: goto P_0c06f30e;
case 0x0c06f310u: goto P_0c06f310;
case 0x0c06f312u: goto P_0c06f312;
case 0x0c06f314u: goto P_0c06f314;
case 0x0c06f316u: goto P_0c06f316;
case 0x0c06f318u: goto P_0c06f318;
case 0x0c06f31au: goto P_0c06f31a;
case 0x0c06f31cu: goto P_0c06f31c;
case 0x0c06f31eu: goto P_0c06f31e;
case 0x0c06f320u: goto P_0c06f320;
case 0x0c06f322u: goto P_0c06f322;
case 0x0c06f324u: goto P_0c06f324;
case 0x0c06f326u: goto P_0c06f326;
case 0x0c06f328u: goto P_0c06f328;
case 0x0c06f32au: goto P_0c06f32a;
case 0x0c06f32cu: goto P_0c06f32c;
case 0x0c06f32eu: goto P_0c06f32e;
case 0x0c06f330u: goto P_0c06f330;
case 0x0c06f332u: goto P_0c06f332;
case 0x0c06f334u: goto P_0c06f334;
case 0x0c06f336u: goto P_0c06f336;
case 0x0c06f338u: goto P_0c06f338;
case 0x0c06f33au: goto P_0c06f33a;
case 0x0c06f33cu: goto P_0c06f33c;
case 0x0c06f33eu: goto P_0c06f33e;
case 0x0c06f340u: goto P_0c06f340;
case 0x0c06f342u: goto P_0c06f342;
case 0x0c06f344u: goto P_0c06f344;
case 0x0c06f346u: goto P_0c06f346;
case 0x0c06f348u: goto P_0c06f348;
case 0x0c06f34au: goto P_0c06f34a;
case 0x0c06f34cu: goto P_0c06f34c;
case 0x0c06f34eu: goto P_0c06f34e;
case 0x0c06f350u: goto P_0c06f350;
case 0x0c06f352u: goto P_0c06f352;
case 0x0c06f354u: goto P_0c06f354;
case 0x0c06f356u: goto P_0c06f356;
case 0x0c06f358u: goto P_0c06f358;
case 0x0c06f35au: goto P_0c06f35a;
case 0x0c06f35cu: goto P_0c06f35c;
case 0x0c06f35eu: goto P_0c06f35e;
case 0x0c06f360u: goto P_0c06f360;
case 0x0c06f362u: goto P_0c06f362;
case 0x0c06f364u: goto P_0c06f364;
case 0x0c06f366u: goto P_0c06f366;
case 0x0c06f368u: goto P_0c06f368;
case 0x0c06f36au: goto P_0c06f36a;
case 0x0c06f36cu: goto P_0c06f36c;
case 0x0c06f36eu: goto P_0c06f36e;
case 0x0c06f370u: goto P_0c06f370;
case 0x0c06f372u: goto P_0c06f372;
case 0x0c06f374u: goto P_0c06f374;
case 0x0c06f376u: goto P_0c06f376;
case 0x0c06f378u: goto P_0c06f378;
case 0x0c06f37au: goto P_0c06f37a;
case 0x0c06f37cu: goto P_0c06f37c;
case 0x0c06f37eu: goto P_0c06f37e;
case 0x0c06f380u: goto P_0c06f380;
case 0x0c06f382u: goto P_0c06f382;
case 0x0c06f384u: goto P_0c06f384;
case 0x0c06f386u: goto P_0c06f386;
case 0x0c06f388u: goto P_0c06f388;
case 0x0c06f38au: goto P_0c06f38a;
case 0x0c06f38cu: goto P_0c06f38c;
case 0x0c06f39cu: goto P_0c06f39c;
case 0x0c06f39eu: goto P_0c06f39e;
case 0x0c06f3a0u: goto P_0c06f3a0;
case 0x0c06f3a2u: goto P_0c06f3a2;
case 0x0c06f3a4u: goto P_0c06f3a4;
case 0x0c06f3a6u: goto P_0c06f3a6;
case 0x0c06f3a8u: goto P_0c06f3a8;
case 0x0c06f3aau: goto P_0c06f3aa;
case 0x0c06f3acu: goto P_0c06f3ac;
case 0x0c06f3aeu: goto P_0c06f3ae;
case 0x0c06f3b0u: goto P_0c06f3b0;
case 0x0c06f3b2u: goto P_0c06f3b2;
case 0x0c06f3b4u: goto P_0c06f3b4;
case 0x0c06f3b6u: goto P_0c06f3b6;
case 0x0c06f3b8u: goto P_0c06f3b8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06f068: /* original 2fe6, guest PC 0x0c06f068 */
if(!s->budget--) { s->failed_pc=0x0c06f068u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f06a;
P_0c06f06a: /* original 6e53, guest PC 0x0c06f06a */
if(!s->budget--) { s->failed_pc=0x0c06f06au; return 0; }
r[14]=r[5];
goto P_0c06f06c;
P_0c06f06c: /* original 2fd6, guest PC 0x0c06f06c */
if(!s->budget--) { s->failed_pc=0x0c06f06cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f06e;
P_0c06f06e: /* original 6d63, guest PC 0x0c06f06e */
if(!s->budget--) { s->failed_pc=0x0c06f06eu; return 0; }
r[13]=r[6];
goto P_0c06f070;
P_0c06f070: /* original 2fc6, guest PC 0x0c06f070 */
if(!s->budget--) { s->failed_pc=0x0c06f070u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f072;
P_0c06f072: /* original 2fb6, guest PC 0x0c06f072 */
if(!s->budget--) { s->failed_pc=0x0c06f072u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f074;
P_0c06f074: /* original 6b73, guest PC 0x0c06f074 */
if(!s->budget--) { s->failed_pc=0x0c06f074u; return 0; }
r[11]=r[7];
goto P_0c06f076;
P_0c06f076: /* original 2fa6, guest PC 0x0c06f076 */
if(!s->budget--) { s->failed_pc=0x0c06f076u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f078;
P_0c06f078: /* original 6a43, guest PC 0x0c06f078 */
if(!s->budget--) { s->failed_pc=0x0c06f078u; return 0; }
r[10]=r[4];
goto P_0c06f07a;
P_0c06f07a: /* original 4f22, guest PC 0x0c06f07a */
if(!s->budget--) { s->failed_pc=0x0c06f07au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06f07c;
P_0c06f07c: /* original d34d, guest PC 0x0c06f07c */
if(!s->budget--) { s->failed_pc=0x0c06f07cu; return 0; }
r[3]=read(ram,0x0c06f1b4u,4);
goto P_0c06f07e;
P_0c06f07e: /* original 65a3, guest PC 0x0c06f07e */
if(!s->budget--) { s->failed_pc=0x0c06f07eu; return 0; }
r[5]=r[10];
goto P_0c06f080;
P_0c06f080: /* original 64e3, guest PC 0x0c06f080 */
if(!s->budget--) { s->failed_pc=0x0c06f080u; return 0; }
r[4]=r[14];
goto P_0c06f082;
P_0c06f082: /* original 4f12, guest PC 0x0c06f082 */
if(!s->budget--) { s->failed_pc=0x0c06f082u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c06f084;
P_0c06f084: /* original 7ffc, guest PC 0x0c06f084 */
if(!s->budget--) { s->failed_pc=0x0c06f084u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06f086;
P_0c06f086: /* original 2f32, guest PC 0x0c06f086 */
if(!s->budget--) { s->failed_pc=0x0c06f086u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06f088;
P_0c06f088: /* original 85d5, guest PC 0x0c06f088 */
if(!s->budget--) { s->failed_pc=0x0c06f088u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+10,2);
goto P_0c06f08a;
P_0c06f08a: /* original 6cd2, guest PC 0x0c06f08a */
if(!s->budget--) { s->failed_pc=0x0c06f08au; return 0; }
tmp=read(ram,r[13],4);
r[12]=tmp;
goto P_0c06f08c;
P_0c06f08c: /* original 600d, guest PC 0x0c06f08c */
if(!s->budget--) { s->failed_pc=0x0c06f08cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c06f08e;
P_0c06f08e: /* original 350c, guest PC 0x0c06f08e */
if(!s->budget--) { s->failed_pc=0x0c06f08eu; return 0; }
r[5]+=r[0];
goto P_0c06f090;
P_0c06f090: /* original 1e53, guest PC 0x0c06f090 */
if(!s->budget--) { s->failed_pc=0x0c06f090u; return 0; }
write(ram,r[14]+12,r[5],4);
goto P_0c06f092;
P_0c06f092: /* original d349, guest PC 0x0c06f092 */
if(!s->budget--) { s->failed_pc=0x0c06f092u; return 0; }
r[3]=read(ram,0x0c06f1b8u,4);
goto P_0c06f094;
P_0c06f094: /* original 430b, guest PC 0x0c06f094 */
if(!s->budget--) { s->failed_pc=0x0c06f094u; return 0; }
target=r[3];
r[16]=code_base|0x0c06f098u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06f098u) { target=s->pc; goto dispatch; }
goto P_0c06f098;
P_0c06f096: /* original 7410, guest PC 0x0c06f096 */
if(!s->budget--) { s->failed_pc=0x0c06f096u; return 0; }
r[4]+=0x00000010u;
goto P_0c06f098;
P_0c06f098: /* original e014, guest PC 0x0c06f098 */
if(!s->budget--) { s->failed_pc=0x0c06f098u; return 0; }
r[0]=0x00000014u;
goto P_0c06f09a;
P_0c06f09a: /* original 64a3, guest PC 0x0c06f09a */
if(!s->budget--) { s->failed_pc=0x0c06f09au; return 0; }
r[4]=r[10];
goto P_0c06f09c;
P_0c06f09c: /* original f3c6, guest PC 0x0c06f09c */
if(!s->budget--) { s->failed_pc=0x0c06f09cu; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c06f09e;
P_0c06f09e: /* original e050, guest PC 0x0c06f09e */
if(!s->budget--) { s->failed_pc=0x0c06f09eu; return 0; }
r[0]=0x00000050u;
goto P_0c06f0a0;
P_0c06f0a0: /* original 65a3, guest PC 0x0c06f0a0 */
if(!s->budget--) { s->failed_pc=0x0c06f0a0u; return 0; }
r[5]=r[10];
goto P_0c06f0a2;
P_0c06f0a2: /* original fe37, guest PC 0x0c06f0a2 */
if(!s->budget--) { s->failed_pc=0x0c06f0a2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c06f0a4;
P_0c06f0a4: /* original e024, guest PC 0x0c06f0a4 */
if(!s->budget--) { s->failed_pc=0x0c06f0a4u; return 0; }
r[0]=0x00000024u;
goto P_0c06f0a6;
P_0c06f0a6: /* original f3d6, guest PC 0x0c06f0a6 */
if(!s->budget--) { s->failed_pc=0x0c06f0a6u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c06f0a8;
P_0c06f0a8: /* original e054, guest PC 0x0c06f0a8 */
if(!s->budget--) { s->failed_pc=0x0c06f0a8u; return 0; }
r[0]=0x00000054u;
goto P_0c06f0aa;
P_0c06f0aa: /* original fe37, guest PC 0x0c06f0aa */
if(!s->budget--) { s->failed_pc=0x0c06f0aau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c06f0ac;
P_0c06f0ac: /* original e058, guest PC 0x0c06f0ac */
if(!s->budget--) { s->failed_pc=0x0c06f0acu; return 0; }
r[0]=0x00000058u;
goto P_0c06f0ae;
P_0c06f0ae: /* original 63c2, guest PC 0x0c06f0ae */
if(!s->budget--) { s->failed_pc=0x0c06f0aeu; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c06f0b0;
P_0c06f0b0: /* original 0e36, guest PC 0x0c06f0b0 */
if(!s->budget--) { s->failed_pc=0x0c06f0b0u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c06f0b2;
P_0c06f0b2: /* original e05c, guest PC 0x0c06f0b2 */
if(!s->budget--) { s->failed_pc=0x0c06f0b2u; return 0; }
r[0]=0x0000005cu;
goto P_0c06f0b4;
P_0c06f0b4: /* original 52c1, guest PC 0x0c06f0b4 */
if(!s->budget--) { s->failed_pc=0x0c06f0b4u; return 0; }
r[2]=read(ram,r[12]+4,4);
goto P_0c06f0b6;
P_0c06f0b6: /* original 0e26, guest PC 0x0c06f0b6 */
if(!s->budget--) { s->failed_pc=0x0c06f0b6u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c06f0b8;
P_0c06f0b8: /* original e008, guest PC 0x0c06f0b8 */
if(!s->budget--) { s->failed_pc=0x0c06f0b8u; return 0; }
r[0]=0x00000008u;
goto P_0c06f0ba;
P_0c06f0ba: /* original f3c6, guest PC 0x0c06f0ba */
if(!s->budget--) { s->failed_pc=0x0c06f0bau; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c06f0bc;
P_0c06f0bc: /* original e060, guest PC 0x0c06f0bc */
if(!s->budget--) { s->failed_pc=0x0c06f0bcu; return 0; }
r[0]=0x00000060u;
goto P_0c06f0be;
P_0c06f0be: /* original fe37, guest PC 0x0c06f0be */
if(!s->budget--) { s->failed_pc=0x0c06f0beu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c06f0c0;
P_0c06f0c0: /* original e00c, guest PC 0x0c06f0c0 */
if(!s->budget--) { s->failed_pc=0x0c06f0c0u; return 0; }
r[0]=0x0000000cu;
goto P_0c06f0c2;
P_0c06f0c2: /* original f3c6, guest PC 0x0c06f0c2 */
if(!s->budget--) { s->failed_pc=0x0c06f0c2u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c06f0c4;
P_0c06f0c4: /* original e064, guest PC 0x0c06f0c4 */
if(!s->budget--) { s->failed_pc=0x0c06f0c4u; return 0; }
r[0]=0x00000064u;
goto P_0c06f0c6;
P_0c06f0c6: /* original fe37, guest PC 0x0c06f0c6 */
if(!s->budget--) { s->failed_pc=0x0c06f0c6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c06f0c8;
P_0c06f0c8: /* original 85d3, guest PC 0x0c06f0c8 */
if(!s->budget--) { s->failed_pc=0x0c06f0c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+6,2);
goto P_0c06f0ca;
P_0c06f0ca: /* original 600d, guest PC 0x0c06f0ca */
if(!s->budget--) { s->failed_pc=0x0c06f0cau; return 0; }
r[0]=r[0]&65535u;
goto P_0c06f0cc;
P_0c06f0cc: /* original 340c, guest PC 0x0c06f0cc */
if(!s->budget--) { s->failed_pc=0x0c06f0ccu; return 0; }
r[4]+=r[0];
goto P_0c06f0ce;
P_0c06f0ce: /* original 85d4, guest PC 0x0c06f0ce */
if(!s->budget--) { s->failed_pc=0x0c06f0ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+8,2);
goto P_0c06f0d0;
P_0c06f0d0: /* original 600d, guest PC 0x0c06f0d0 */
if(!s->budget--) { s->failed_pc=0x0c06f0d0u; return 0; }
r[0]=r[0]&65535u;
goto P_0c06f0d2;
P_0c06f0d2: /* original 350c, guest PC 0x0c06f0d2 */
if(!s->budget--) { s->failed_pc=0x0c06f0d2u; return 0; }
r[5]+=r[0];
goto P_0c06f0d4;
P_0c06f0d4: /* original e06c, guest PC 0x0c06f0d4 */
if(!s->budget--) { s->failed_pc=0x0c06f0d4u; return 0; }
r[0]=0x0000006cu;
goto P_0c06f0d6;
P_0c06f0d6: /* original 0e46, guest PC 0x0c06f0d6 */
if(!s->budget--) { s->failed_pc=0x0c06f0d6u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c06f0d8;
P_0c06f0d8: /* original e070, guest PC 0x0c06f0d8 */
if(!s->budget--) { s->failed_pc=0x0c06f0d8u; return 0; }
r[0]=0x00000070u;
goto P_0c06f0da;
P_0c06f0da: /* original 0e56, guest PC 0x0c06f0da */
if(!s->budget--) { s->failed_pc=0x0c06f0dau; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c06f0dc;
P_0c06f0dc: /* original e00c, guest PC 0x0c06f0dc */
if(!s->budget--) { s->failed_pc=0x0c06f0dcu; return 0; }
r[0]=0x0000000cu;
goto P_0c06f0de;
P_0c06f0de: /* original f3d6, guest PC 0x0c06f0de */
if(!s->budget--) { s->failed_pc=0x0c06f0deu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c06f0e0;
P_0c06f0e0: /* original e300, guest PC 0x0c06f0e0 */
if(!s->budget--) { s->failed_pc=0x0c06f0e0u; return 0; }
r[3]=0x00000000u;
goto P_0c06f0e2;
P_0c06f0e2: /* original 9060, guest PC 0x0c06f0e2 */
if(!s->budget--) { s->failed_pc=0x0c06f0e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f1a6u,2);
goto P_0c06f0e4;
P_0c06f0e4: /* original fe37, guest PC 0x0c06f0e4 */
if(!s->budget--) { s->failed_pc=0x0c06f0e4u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c06f0e6;
P_0c06f0e6: /* original e010, guest PC 0x0c06f0e6 */
if(!s->budget--) { s->failed_pc=0x0c06f0e6u; return 0; }
r[0]=0x00000010u;
goto P_0c06f0e8;
P_0c06f0e8: /* original f3d6, guest PC 0x0c06f0e8 */
if(!s->budget--) { s->failed_pc=0x0c06f0e8u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c06f0ea;
P_0c06f0ea: /* original 905d, guest PC 0x0c06f0ea */
if(!s->budget--) { s->failed_pc=0x0c06f0eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f1a8u,2);
goto P_0c06f0ec;
P_0c06f0ec: /* original fe37, guest PC 0x0c06f0ec */
if(!s->budget--) { s->failed_pc=0x0c06f0ecu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c06f0ee;
P_0c06f0ee: /* original e014, guest PC 0x0c06f0ee */
if(!s->budget--) { s->failed_pc=0x0c06f0eeu; return 0; }
r[0]=0x00000014u;
goto P_0c06f0f0;
P_0c06f0f0: /* original f3d6, guest PC 0x0c06f0f0 */
if(!s->budget--) { s->failed_pc=0x0c06f0f0u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c06f0f2;
P_0c06f0f2: /* original 905a, guest PC 0x0c06f0f2 */
if(!s->budget--) { s->failed_pc=0x0c06f0f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f1aau,2);
goto P_0c06f0f4;
P_0c06f0f4: /* original fe37, guest PC 0x0c06f0f4 */
if(!s->budget--) { s->failed_pc=0x0c06f0f4u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c06f0f6;
P_0c06f0f6: /* original 7008, guest PC 0x0c06f0f6 */
if(!s->budget--) { s->failed_pc=0x0c06f0f6u; return 0; }
r[0]+=0x00000008u;
goto P_0c06f0f8;
P_0c06f0f8: /* original 0e36, guest PC 0x0c06f0f8 */
if(!s->budget--) { s->failed_pc=0x0c06f0f8u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c06f0fa;
P_0c06f0fa: /* original 85d2, guest PC 0x0c06f0fa */
if(!s->budget--) { s->failed_pc=0x0c06f0fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+4,2);
goto P_0c06f0fc;
P_0c06f0fc: /* original 640d, guest PC 0x0c06f0fc */
if(!s->budget--) { s->failed_pc=0x0c06f0fcu; return 0; }
r[4]=r[0]&65535u;
goto P_0c06f0fe;
P_0c06f0fe: /* original 9055, guest PC 0x0c06f0fe */
if(!s->budget--) { s->failed_pc=0x0c06f0feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f1acu,2);
goto P_0c06f100;
P_0c06f100: /* original 0e46, guest PC 0x0c06f100 */
if(!s->budget--) { s->failed_pc=0x0c06f100u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c06f102;
P_0c06f102: /* original 6043, guest PC 0x0c06f102 */
if(!s->budget--) { s->failed_pc=0x0c06f102u; return 0; }
r[0]=r[4];
goto P_0c06f104;
P_0c06f104: /* original d52d, guest PC 0x0c06f104 */
if(!s->budget--) { s->failed_pc=0x0c06f104u; return 0; }
r[5]=read(ram,0x0c06f1bcu,4);
goto P_0c06f106;
P_0c06f106: /* original 4008, guest PC 0x0c06f106 */
if(!s->budget--) { s->failed_pc=0x0c06f106u; return 0; }
r[0]<<=2;
goto P_0c06f108;
P_0c06f108: /* original 0c5e, guest PC 0x0c06f108 */
if(!s->budget--) { s->failed_pc=0x0c06f108u; return 0; }
r[12]=read(ram,r[5]+r[0],4);
goto P_0c06f10a;
P_0c06f10a: /* original 2cc8, guest PC 0x0c06f10a */
if(!s->budget--) { s->failed_pc=0x0c06f10au; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c06f10c;
P_0c06f10c: /* original 8b01, guest PC 0x0c06f10c */
if(!s->budget--) { s->failed_pc=0x0c06f10cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06f112; }
goto P_0c06f10e;
P_0c06f10e: /* original a14b, guest PC 0x0c06f10e */
if(!s->budget--) { s->failed_pc=0x0c06f10eu; return 0; }
r[0]=r[11];
goto P_0c06f3a8;
P_0c06f110: /* original 60b3, guest PC 0x0c06f110 */
if(!s->budget--) { s->failed_pc=0x0c06f110u; return 0; }
r[0]=r[11];
goto P_0c06f112;
P_0c06f112: /* original 85d2, guest PC 0x0c06f112 */
if(!s->budget--) { s->failed_pc=0x0c06f112u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+4,2);
goto P_0c06f114;
P_0c06f114: /* original 600d, guest PC 0x0c06f114 */
if(!s->budget--) { s->failed_pc=0x0c06f114u; return 0; }
r[0]=r[0]&65535u;
goto P_0c06f116;
P_0c06f116: /* original 4008, guest PC 0x0c06f116 */
if(!s->budget--) { s->failed_pc=0x0c06f116u; return 0; }
r[0]<<=2;
goto P_0c06f118;
P_0c06f118: /* original 005e, guest PC 0x0c06f118 */
if(!s->budget--) { s->failed_pc=0x0c06f118u; return 0; }
r[0]=read(ram,r[5]+r[0],4);
goto P_0c06f11a;
P_0c06f11a: /* original 5001, guest PC 0x0c06f11a */
if(!s->budget--) { s->failed_pc=0x0c06f11au; return 0; }
r[0]=read(ram,r[0]+4,4);
goto P_0c06f11c;
P_0c06f11c: /* original c801, guest PC 0x0c06f11c */
if(!s->budget--) { s->failed_pc=0x0c06f11cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c06f11e;
P_0c06f11e: /* original 8903, guest PC 0x0c06f11e */
if(!s->budget--) { s->failed_pc=0x0c06f11eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06f128; }
goto P_0c06f120;
P_0c06f120: /* original d227, guest PC 0x0c06f120 */
if(!s->budget--) { s->failed_pc=0x0c06f120u; return 0; }
r[2]=read(ram,0x0c06f1c0u,4);
goto P_0c06f122;
P_0c06f122: /* original 9544, guest PC 0x0c06f122 */
if(!s->budget--) { s->failed_pc=0x0c06f122u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f1aeu,2);
goto P_0c06f124;
P_0c06f124: /* original 420b, guest PC 0x0c06f124 */
if(!s->budget--) { s->failed_pc=0x0c06f124u; return 0; }
target=r[2];
r[16]=code_base|0x0c06f128u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06f128u) { target=s->pc; goto dispatch; }
goto P_0c06f128;
P_0c06f126: /* original e401, guest PC 0x0c06f126 */
if(!s->budget--) { s->failed_pc=0x0c06f126u; return 0; }
r[4]=0x00000001u;
goto P_0c06f128;
P_0c06f128: /* original 56c1, guest PC 0x0c06f128 */
if(!s->budget--) { s->failed_pc=0x0c06f128u; return 0; }
r[6]=read(ram,r[12]+4,4);
goto P_0c06f12a;
P_0c06f12a: /* original 5562, guest PC 0x0c06f12a */
if(!s->budget--) { s->failed_pc=0x0c06f12au; return 0; }
r[5]=read(ram,r[6]+8,4);
goto P_0c06f12c;
P_0c06f12c: /* original 5461, guest PC 0x0c06f12c */
if(!s->budget--) { s->failed_pc=0x0c06f12cu; return 0; }
r[4]=read(ram,r[6]+4,4);
goto P_0c06f12e;
P_0c06f12e: /* original 4515, guest PC 0x0c06f12e */
if(!s->budget--) { s->failed_pc=0x0c06f12eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>0)!=0);
goto P_0c06f130;
P_0c06f130: /* original 2e52, guest PC 0x0c06f130 */
if(!s->budget--) { s->failed_pc=0x0c06f130u; return 0; }
write(ram,r[14],r[5],4);
goto P_0c06f132;
P_0c06f132: /* original 1eb1, guest PC 0x0c06f132 */
if(!s->budget--) { s->failed_pc=0x0c06f132u; return 0; }
write(ram,r[14]+4,r[11],4);
goto P_0c06f134;
P_0c06f134: /* original 8f1b, guest PC 0x0c06f134 */
if(!s->budget--) { s->failed_pc=0x0c06f134u; return 0; }
cond=r[17]&1u;
r[7]=r[11];
if(!cond) { goto P_0c06f16e; }
goto P_0c06f138;
P_0c06f136: /* original 67b3, guest PC 0x0c06f136 */
if(!s->budget--) { s->failed_pc=0x0c06f136u; return 0; }
r[7]=r[11];
goto P_0c06f138;
P_0c06f138: /* original f348, guest PC 0x0c06f138 */
if(!s->budget--) { s->failed_pc=0x0c06f138u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c06f13a;
P_0c06f13a: /* original e004, guest PC 0x0c06f13a */
if(!s->budget--) { s->failed_pc=0x0c06f13au; return 0; }
r[0]=0x00000004u;
goto P_0c06f13c;
P_0c06f13c: /* original 75ff, guest PC 0x0c06f13c */
if(!s->budget--) { s->failed_pc=0x0c06f13cu; return 0; }
r[5]+=0xffffffffu;
goto P_0c06f13e;
P_0c06f13e: /* original f73a, guest PC 0x0c06f13e */
if(!s->budget--) { s->failed_pc=0x0c06f13eu; return 0; }
vf3_matrix_store(s,ram,3,r[7]);
goto P_0c06f140;
P_0c06f140: /* original 7704, guest PC 0x0c06f140 */
if(!s->budget--) { s->failed_pc=0x0c06f140u; return 0; }
r[7]+=0x00000004u;
goto P_0c06f142;
P_0c06f142: /* original f346, guest PC 0x0c06f142 */
if(!s->budget--) { s->failed_pc=0x0c06f142u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f144;
P_0c06f144: /* original e008, guest PC 0x0c06f144 */
if(!s->budget--) { s->failed_pc=0x0c06f144u; return 0; }
r[0]=0x00000008u;
goto P_0c06f146;
P_0c06f146: /* original 4515, guest PC 0x0c06f146 */
if(!s->budget--) { s->failed_pc=0x0c06f146u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>0)!=0);
goto P_0c06f148;
P_0c06f148: /* original f73a, guest PC 0x0c06f148 */
if(!s->budget--) { s->failed_pc=0x0c06f148u; return 0; }
vf3_matrix_store(s,ram,3,r[7]);
goto P_0c06f14a;
P_0c06f14a: /* original 7704, guest PC 0x0c06f14a */
if(!s->budget--) { s->failed_pc=0x0c06f14au; return 0; }
r[7]+=0x00000004u;
goto P_0c06f14c;
P_0c06f14c: /* original f346, guest PC 0x0c06f14c */
if(!s->budget--) { s->failed_pc=0x0c06f14cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f14e;
P_0c06f14e: /* original e00c, guest PC 0x0c06f14e */
if(!s->budget--) { s->failed_pc=0x0c06f14eu; return 0; }
r[0]=0x0000000cu;
goto P_0c06f150;
P_0c06f150: /* original f73a, guest PC 0x0c06f150 */
if(!s->budget--) { s->failed_pc=0x0c06f150u; return 0; }
vf3_matrix_store(s,ram,3,r[7]);
goto P_0c06f152;
P_0c06f152: /* original 7704, guest PC 0x0c06f152 */
if(!s->budget--) { s->failed_pc=0x0c06f152u; return 0; }
r[7]+=0x00000004u;
goto P_0c06f154;
P_0c06f154: /* original f346, guest PC 0x0c06f154 */
if(!s->budget--) { s->failed_pc=0x0c06f154u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f156;
P_0c06f156: /* original e010, guest PC 0x0c06f156 */
if(!s->budget--) { s->failed_pc=0x0c06f156u; return 0; }
r[0]=0x00000010u;
goto P_0c06f158;
P_0c06f158: /* original f73a, guest PC 0x0c06f158 */
if(!s->budget--) { s->failed_pc=0x0c06f158u; return 0; }
vf3_matrix_store(s,ram,3,r[7]);
goto P_0c06f15a;
P_0c06f15a: /* original 7704, guest PC 0x0c06f15a */
if(!s->budget--) { s->failed_pc=0x0c06f15au; return 0; }
r[7]+=0x00000004u;
goto P_0c06f15c;
P_0c06f15c: /* original f346, guest PC 0x0c06f15c */
if(!s->budget--) { s->failed_pc=0x0c06f15cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f15e;
P_0c06f15e: /* original e014, guest PC 0x0c06f15e */
if(!s->budget--) { s->failed_pc=0x0c06f15eu; return 0; }
r[0]=0x00000014u;
goto P_0c06f160;
P_0c06f160: /* original f73a, guest PC 0x0c06f160 */
if(!s->budget--) { s->failed_pc=0x0c06f160u; return 0; }
vf3_matrix_store(s,ram,3,r[7]);
goto P_0c06f162;
P_0c06f162: /* original 7704, guest PC 0x0c06f162 */
if(!s->budget--) { s->failed_pc=0x0c06f162u; return 0; }
r[7]+=0x00000004u;
goto P_0c06f164;
P_0c06f164: /* original f346, guest PC 0x0c06f164 */
if(!s->budget--) { s->failed_pc=0x0c06f164u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f166;
P_0c06f166: /* original 7418, guest PC 0x0c06f166 */
if(!s->budget--) { s->failed_pc=0x0c06f166u; return 0; }
r[4]+=0x00000018u;
goto P_0c06f168;
P_0c06f168: /* original f73a, guest PC 0x0c06f168 */
if(!s->budget--) { s->failed_pc=0x0c06f168u; return 0; }
vf3_matrix_store(s,ram,3,r[7]);
goto P_0c06f16a;
P_0c06f16a: /* original 8de5, guest PC 0x0c06f16a */
if(!s->budget--) { s->failed_pc=0x0c06f16au; return 0; }
cond=r[17]&1u;
r[7]+=0x00000004u;
if(cond) { goto P_0c06f138; }
goto P_0c06f16e;
P_0c06f16c: /* original 7704, guest PC 0x0c06f16c */
if(!s->budget--) { s->failed_pc=0x0c06f16cu; return 0; }
r[7]+=0x00000004u;
goto P_0c06f16e;
P_0c06f16e: /* original e061, guest PC 0x0c06f16e */
if(!s->budget--) { s->failed_pc=0x0c06f16eu; return 0; }
r[0]=0x00000061u;
goto P_0c06f170;
P_0c06f170: /* original 00ac, guest PC 0x0c06f170 */
if(!s->budget--) { s->failed_pc=0x0c06f170u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c06f172;
P_0c06f172: /* original 600c, guest PC 0x0c06f172 */
if(!s->budget--) { s->failed_pc=0x0c06f172u; return 0; }
r[0]=r[0]&255u;
goto P_0c06f174;
P_0c06f174: /* original 880b, guest PC 0x0c06f174 */
if(!s->budget--) { s->failed_pc=0x0c06f174u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c06f176;
P_0c06f176: /* original 8901, guest PC 0x0c06f176 */
if(!s->budget--) { s->failed_pc=0x0c06f176u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06f17c; }
goto P_0c06f178;
P_0c06f178: /* original a115, guest PC 0x0c06f178 */
if(!s->budget--) { s->failed_pc=0x0c06f178u; return 0; }
goto P_0c06f3a6;
P_0c06f17a: /* original 0009, guest PC 0x0c06f17a */
if(!s->budget--) { s->failed_pc=0x0c06f17au; return 0; }
goto P_0c06f17c;
P_0c06f17c: /* original 9018, guest PC 0x0c06f17c */
if(!s->budget--) { s->failed_pc=0x0c06f17cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f1b0u,2);
goto P_0c06f17e;
P_0c06f17e: /* original 62f2, guest PC 0x0c06f17e */
if(!s->budget--) { s->failed_pc=0x0c06f17eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c06f180;
P_0c06f180: /* original 032c, guest PC 0x0c06f180 */
if(!s->budget--) { s->failed_pc=0x0c06f180u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c06f182;
P_0c06f182: /* original 2338, guest PC 0x0c06f182 */
if(!s->budget--) { s->failed_pc=0x0c06f182u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06f184;
P_0c06f184: /* original 8b01, guest PC 0x0c06f184 */
if(!s->budget--) { s->failed_pc=0x0c06f184u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06f18a; }
goto P_0c06f186;
P_0c06f186: /* original a10e, guest PC 0x0c06f186 */
if(!s->budget--) { s->failed_pc=0x0c06f186u; return 0; }
goto P_0c06f3a6;
P_0c06f188: /* original 0009, guest PC 0x0c06f188 */
if(!s->budget--) { s->failed_pc=0x0c06f188u; return 0; }
goto P_0c06f18a;
P_0c06f18a: /* original e050, guest PC 0x0c06f18a */
if(!s->budget--) { s->failed_pc=0x0c06f18au; return 0; }
r[0]=0x00000050u;
goto P_0c06f18c;
P_0c06f18c: /* original f38d, guest PC 0x0c06f18c */
if(!s->budget--) { s->failed_pc=0x0c06f18cu; return 0; }
fr[3]=0;
goto P_0c06f18e;
P_0c06f18e: /* original f2e6, guest PC 0x0c06f18e */
if(!s->budget--) { s->failed_pc=0x0c06f18eu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c06f190;
P_0c06f190: /* original f325, guest PC 0x0c06f190 */
if(!s->budget--) { s->failed_pc=0x0c06f190u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c06f192;
P_0c06f192: /* original 8f19, guest PC 0x0c06f192 */
if(!s->budget--) { s->failed_pc=0x0c06f192u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[6]+4,4);
if(!cond) { goto P_0c06f1c8; }
goto P_0c06f196;
P_0c06f194: /* original 5461, guest PC 0x0c06f194 */
if(!s->budget--) { s->failed_pc=0x0c06f194u; return 0; }
r[4]=read(ram,r[6]+4,4);
goto P_0c06f196;
P_0c06f196: /* original 84a4, guest PC 0x0c06f196 */
if(!s->budget--) { s->failed_pc=0x0c06f196u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+4,1);
goto P_0c06f198;
P_0c06f198: /* original 950b, guest PC 0x0c06f198 */
if(!s->budget--) { s->failed_pc=0x0c06f198u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f1b2u,2);
goto P_0c06f19a;
P_0c06f19a: /* original 600c, guest PC 0x0c06f19a */
if(!s->budget--) { s->failed_pc=0x0c06f19au; return 0; }
r[0]=r[0]&255u;
goto P_0c06f19c;
P_0c06f19c: /* original d309, guest PC 0x0c06f19c */
if(!s->budget--) { s->failed_pc=0x0c06f19cu; return 0; }
r[3]=read(ram,0x0c06f1c4u,4);
goto P_0c06f19e;
P_0c06f19e: /* original 205f, guest PC 0x0c06f19e */
if(!s->budget--) { s->failed_pc=0x0c06f19eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[0]*(int32_t)(int16_t)r[5]);
goto P_0c06f1a0;
P_0c06f1a0: /* original 051a, guest PC 0x0c06f1a0 */
if(!s->budget--) { s->failed_pc=0x0c06f1a0u; return 0; }
r[5]=r[19];
goto P_0c06f1a2;
P_0c06f1a2: /* original a018, guest PC 0x0c06f1a2 */
if(!s->budget--) { s->failed_pc=0x0c06f1a2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c06f1d6;
P_0c06f1a4: /* original 655f, guest PC 0x0c06f1a4 */
if(!s->budget--) { s->failed_pc=0x0c06f1a4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
if(!vf3_matrix_family(0x0c06f1a6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06f1a6u; return 0; } return 1;
P_0c06f1c8: /* original 84a4, guest PC 0x0c06f1c8 */
if(!s->budget--) { s->failed_pc=0x0c06f1c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+4,1);
goto P_0c06f1ca;
P_0c06f1ca: /* original 95e0, guest PC 0x0c06f1ca */
if(!s->budget--) { s->failed_pc=0x0c06f1cau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f38eu,2);
goto P_0c06f1cc;
P_0c06f1cc: /* original 600c, guest PC 0x0c06f1cc */
if(!s->budget--) { s->failed_pc=0x0c06f1ccu; return 0; }
r[0]=r[0]&255u;
goto P_0c06f1ce;
P_0c06f1ce: /* original d371, guest PC 0x0c06f1ce */
if(!s->budget--) { s->failed_pc=0x0c06f1ceu; return 0; }
r[3]=read(ram,0x0c06f394u,4);
goto P_0c06f1d0;
P_0c06f1d0: /* original 205f, guest PC 0x0c06f1d0 */
if(!s->budget--) { s->failed_pc=0x0c06f1d0u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[0]*(int32_t)(int16_t)r[5]);
goto P_0c06f1d2;
P_0c06f1d2: /* original 051a, guest PC 0x0c06f1d2 */
if(!s->budget--) { s->failed_pc=0x0c06f1d2u; return 0; }
r[5]=r[19];
goto P_0c06f1d4;
P_0c06f1d4: /* original 655f, guest PC 0x0c06f1d4 */
if(!s->budget--) { s->failed_pc=0x0c06f1d4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c06f1d6;
P_0c06f1d6: /* original c770, guest PC 0x0c06f1d6 */
if(!s->budget--) { s->failed_pc=0x0c06f1d6u; return 0; }
r[0]=code_base|0x0006f398u;
goto P_0c06f1d8;
P_0c06f1d8: /* original 7430, guest PC 0x0c06f1d8 */
if(!s->budget--) { s->failed_pc=0x0c06f1d8u; return 0; }
r[4]+=0x00000030u;
goto P_0c06f1da;
P_0c06f1da: /* original f408, guest PC 0x0c06f1da */
if(!s->budget--) { s->failed_pc=0x0c06f1dau; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c06f1dc;
P_0c06f1dc: /* original f348, guest PC 0x0c06f1dc */
if(!s->budget--) { s->failed_pc=0x0c06f1dcu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c06f1de;
P_0c06f1de: /* original e004, guest PC 0x0c06f1de */
if(!s->budget--) { s->failed_pc=0x0c06f1deu; return 0; }
r[0]=0x00000004u;
goto P_0c06f1e0;
P_0c06f1e0: /* original 353c, guest PC 0x0c06f1e0 */
if(!s->budget--) { s->failed_pc=0x0c06f1e0u; return 0; }
r[5]+=r[3];
goto P_0c06f1e2;
P_0c06f1e2: /* original f340, guest PC 0x0c06f1e2 */
if(!s->budget--) { s->failed_pc=0x0c06f1e2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c06f1e4;
P_0c06f1e4: /* original f53a, guest PC 0x0c06f1e4 */
if(!s->budget--) { s->failed_pc=0x0c06f1e4u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c06f1e6;
P_0c06f1e6: /* original f246, guest PC 0x0c06f1e6 */
if(!s->budget--) { s->failed_pc=0x0c06f1e6u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c06f1e8;
P_0c06f1e8: /* original f527, guest PC 0x0c06f1e8 */
if(!s->budget--) { s->failed_pc=0x0c06f1e8u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c06f1ea;
P_0c06f1ea: /* original e008, guest PC 0x0c06f1ea */
if(!s->budget--) { s->failed_pc=0x0c06f1eau; return 0; }
r[0]=0x00000008u;
goto P_0c06f1ec;
P_0c06f1ec: /* original f346, guest PC 0x0c06f1ec */
if(!s->budget--) { s->failed_pc=0x0c06f1ecu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f1ee;
P_0c06f1ee: /* original 7418, guest PC 0x0c06f1ee */
if(!s->budget--) { s->failed_pc=0x0c06f1eeu; return 0; }
r[4]+=0x00000018u;
goto P_0c06f1f0;
P_0c06f1f0: /* original f537, guest PC 0x0c06f1f0 */
if(!s->budget--) { s->failed_pc=0x0c06f1f0u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c06f1f2;
P_0c06f1f2: /* original e004, guest PC 0x0c06f1f2 */
if(!s->budget--) { s->failed_pc=0x0c06f1f2u; return 0; }
r[0]=0x00000004u;
goto P_0c06f1f4;
P_0c06f1f4: /* original f348, guest PC 0x0c06f1f4 */
if(!s->budget--) { s->failed_pc=0x0c06f1f4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c06f1f6;
P_0c06f1f6: /* original 750c, guest PC 0x0c06f1f6 */
if(!s->budget--) { s->failed_pc=0x0c06f1f6u; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f1f8;
P_0c06f1f8: /* original f340, guest PC 0x0c06f1f8 */
if(!s->budget--) { s->failed_pc=0x0c06f1f8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c06f1fa;
P_0c06f1fa: /* original f53a, guest PC 0x0c06f1fa */
if(!s->budget--) { s->failed_pc=0x0c06f1fau; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c06f1fc;
P_0c06f1fc: /* original f246, guest PC 0x0c06f1fc */
if(!s->budget--) { s->failed_pc=0x0c06f1fcu; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c06f1fe;
P_0c06f1fe: /* original f527, guest PC 0x0c06f1fe */
if(!s->budget--) { s->failed_pc=0x0c06f1feu; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c06f200;
P_0c06f200: /* original e008, guest PC 0x0c06f200 */
if(!s->budget--) { s->failed_pc=0x0c06f200u; return 0; }
r[0]=0x00000008u;
goto P_0c06f202;
P_0c06f202: /* original f346, guest PC 0x0c06f202 */
if(!s->budget--) { s->failed_pc=0x0c06f202u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f204;
P_0c06f204: /* original 7418, guest PC 0x0c06f204 */
if(!s->budget--) { s->failed_pc=0x0c06f204u; return 0; }
r[4]+=0x00000018u;
goto P_0c06f206;
P_0c06f206: /* original f537, guest PC 0x0c06f206 */
if(!s->budget--) { s->failed_pc=0x0c06f206u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c06f208;
P_0c06f208: /* original e004, guest PC 0x0c06f208 */
if(!s->budget--) { s->failed_pc=0x0c06f208u; return 0; }
r[0]=0x00000004u;
goto P_0c06f20a;
P_0c06f20a: /* original f348, guest PC 0x0c06f20a */
if(!s->budget--) { s->failed_pc=0x0c06f20au; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c06f20c;
P_0c06f20c: /* original 750c, guest PC 0x0c06f20c */
if(!s->budget--) { s->failed_pc=0x0c06f20cu; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f20e;
P_0c06f20e: /* original f340, guest PC 0x0c06f20e */
if(!s->budget--) { s->failed_pc=0x0c06f20eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c06f210;
P_0c06f210: /* original f53a, guest PC 0x0c06f210 */
if(!s->budget--) { s->failed_pc=0x0c06f210u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c06f212;
P_0c06f212: /* original f246, guest PC 0x0c06f212 */
if(!s->budget--) { s->failed_pc=0x0c06f212u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c06f214;
P_0c06f214: /* original f527, guest PC 0x0c06f214 */
if(!s->budget--) { s->failed_pc=0x0c06f214u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c06f216;
P_0c06f216: /* original e008, guest PC 0x0c06f216 */
if(!s->budget--) { s->failed_pc=0x0c06f216u; return 0; }
r[0]=0x00000008u;
goto P_0c06f218;
P_0c06f218: /* original f346, guest PC 0x0c06f218 */
if(!s->budget--) { s->failed_pc=0x0c06f218u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f21a;
P_0c06f21a: /* original 7418, guest PC 0x0c06f21a */
if(!s->budget--) { s->failed_pc=0x0c06f21au; return 0; }
r[4]+=0x00000018u;
goto P_0c06f21c;
P_0c06f21c: /* original f537, guest PC 0x0c06f21c */
if(!s->budget--) { s->failed_pc=0x0c06f21cu; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c06f21e;
P_0c06f21e: /* original e004, guest PC 0x0c06f21e */
if(!s->budget--) { s->failed_pc=0x0c06f21eu; return 0; }
r[0]=0x00000004u;
goto P_0c06f220;
P_0c06f220: /* original f348, guest PC 0x0c06f220 */
if(!s->budget--) { s->failed_pc=0x0c06f220u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c06f222;
P_0c06f222: /* original 750c, guest PC 0x0c06f222 */
if(!s->budget--) { s->failed_pc=0x0c06f222u; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f224;
P_0c06f224: /* original f340, guest PC 0x0c06f224 */
if(!s->budget--) { s->failed_pc=0x0c06f224u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c06f226;
P_0c06f226: /* original f53a, guest PC 0x0c06f226 */
if(!s->budget--) { s->failed_pc=0x0c06f226u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c06f228;
P_0c06f228: /* original f246, guest PC 0x0c06f228 */
if(!s->budget--) { s->failed_pc=0x0c06f228u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c06f22a;
P_0c06f22a: /* original f527, guest PC 0x0c06f22a */
if(!s->budget--) { s->failed_pc=0x0c06f22au; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c06f22c;
P_0c06f22c: /* original e008, guest PC 0x0c06f22c */
if(!s->budget--) { s->failed_pc=0x0c06f22cu; return 0; }
r[0]=0x00000008u;
goto P_0c06f22e;
P_0c06f22e: /* original f346, guest PC 0x0c06f22e */
if(!s->budget--) { s->failed_pc=0x0c06f22eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f230;
P_0c06f230: /* original 7448, guest PC 0x0c06f230 */
if(!s->budget--) { s->failed_pc=0x0c06f230u; return 0; }
r[4]+=0x00000048u;
goto P_0c06f232;
P_0c06f232: /* original f537, guest PC 0x0c06f232 */
if(!s->budget--) { s->failed_pc=0x0c06f232u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c06f234;
P_0c06f234: /* original e004, guest PC 0x0c06f234 */
if(!s->budget--) { s->failed_pc=0x0c06f234u; return 0; }
r[0]=0x00000004u;
goto P_0c06f236;
P_0c06f236: /* original f348, guest PC 0x0c06f236 */
if(!s->budget--) { s->failed_pc=0x0c06f236u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c06f238;
P_0c06f238: /* original 750c, guest PC 0x0c06f238 */
if(!s->budget--) { s->failed_pc=0x0c06f238u; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f23a;
P_0c06f23a: /* original f340, guest PC 0x0c06f23a */
if(!s->budget--) { s->failed_pc=0x0c06f23au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c06f23c;
P_0c06f23c: /* original f53a, guest PC 0x0c06f23c */
if(!s->budget--) { s->failed_pc=0x0c06f23cu; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c06f23e;
P_0c06f23e: /* original f246, guest PC 0x0c06f23e */
if(!s->budget--) { s->failed_pc=0x0c06f23eu; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c06f240;
P_0c06f240: /* original f527, guest PC 0x0c06f240 */
if(!s->budget--) { s->failed_pc=0x0c06f240u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c06f242;
P_0c06f242: /* original e008, guest PC 0x0c06f242 */
if(!s->budget--) { s->failed_pc=0x0c06f242u; return 0; }
r[0]=0x00000008u;
goto P_0c06f244;
P_0c06f244: /* original f346, guest PC 0x0c06f244 */
if(!s->budget--) { s->failed_pc=0x0c06f244u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f246;
P_0c06f246: /* original 7418, guest PC 0x0c06f246 */
if(!s->budget--) { s->failed_pc=0x0c06f246u; return 0; }
r[4]+=0x00000018u;
goto P_0c06f248;
P_0c06f248: /* original f537, guest PC 0x0c06f248 */
if(!s->budget--) { s->failed_pc=0x0c06f248u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c06f24a;
P_0c06f24a: /* original e004, guest PC 0x0c06f24a */
if(!s->budget--) { s->failed_pc=0x0c06f24au; return 0; }
r[0]=0x00000004u;
goto P_0c06f24c;
P_0c06f24c: /* original f348, guest PC 0x0c06f24c */
if(!s->budget--) { s->failed_pc=0x0c06f24cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c06f24e;
P_0c06f24e: /* original 750c, guest PC 0x0c06f24e */
if(!s->budget--) { s->failed_pc=0x0c06f24eu; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f250;
P_0c06f250: /* original f340, guest PC 0x0c06f250 */
if(!s->budget--) { s->failed_pc=0x0c06f250u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c06f252;
P_0c06f252: /* original f53a, guest PC 0x0c06f252 */
if(!s->budget--) { s->failed_pc=0x0c06f252u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c06f254;
P_0c06f254: /* original f246, guest PC 0x0c06f254 */
if(!s->budget--) { s->failed_pc=0x0c06f254u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c06f256;
P_0c06f256: /* original f527, guest PC 0x0c06f256 */
if(!s->budget--) { s->failed_pc=0x0c06f256u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c06f258;
P_0c06f258: /* original e008, guest PC 0x0c06f258 */
if(!s->budget--) { s->failed_pc=0x0c06f258u; return 0; }
r[0]=0x00000008u;
goto P_0c06f25a;
P_0c06f25a: /* original f346, guest PC 0x0c06f25a */
if(!s->budget--) { s->failed_pc=0x0c06f25au; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f25c;
P_0c06f25c: /* original 7418, guest PC 0x0c06f25c */
if(!s->budget--) { s->failed_pc=0x0c06f25cu; return 0; }
r[4]+=0x00000018u;
goto P_0c06f25e;
P_0c06f25e: /* original f537, guest PC 0x0c06f25e */
if(!s->budget--) { s->failed_pc=0x0c06f25eu; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c06f260;
P_0c06f260: /* original e004, guest PC 0x0c06f260 */
if(!s->budget--) { s->failed_pc=0x0c06f260u; return 0; }
r[0]=0x00000004u;
goto P_0c06f262;
P_0c06f262: /* original f348, guest PC 0x0c06f262 */
if(!s->budget--) { s->failed_pc=0x0c06f262u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c06f264;
P_0c06f264: /* original 750c, guest PC 0x0c06f264 */
if(!s->budget--) { s->failed_pc=0x0c06f264u; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f266;
P_0c06f266: /* original f340, guest PC 0x0c06f266 */
if(!s->budget--) { s->failed_pc=0x0c06f266u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c06f268;
P_0c06f268: /* original f53a, guest PC 0x0c06f268 */
if(!s->budget--) { s->failed_pc=0x0c06f268u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c06f26a;
P_0c06f26a: /* original f246, guest PC 0x0c06f26a */
if(!s->budget--) { s->failed_pc=0x0c06f26au; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c06f26c;
P_0c06f26c: /* original f527, guest PC 0x0c06f26c */
if(!s->budget--) { s->failed_pc=0x0c06f26cu; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c06f26e;
P_0c06f26e: /* original e008, guest PC 0x0c06f26e */
if(!s->budget--) { s->failed_pc=0x0c06f26eu; return 0; }
r[0]=0x00000008u;
goto P_0c06f270;
P_0c06f270: /* original f346, guest PC 0x0c06f270 */
if(!s->budget--) { s->failed_pc=0x0c06f270u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f272;
P_0c06f272: /* original 7418, guest PC 0x0c06f272 */
if(!s->budget--) { s->failed_pc=0x0c06f272u; return 0; }
r[4]+=0x00000018u;
goto P_0c06f274;
P_0c06f274: /* original f537, guest PC 0x0c06f274 */
if(!s->budget--) { s->failed_pc=0x0c06f274u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c06f276;
P_0c06f276: /* original e004, guest PC 0x0c06f276 */
if(!s->budget--) { s->failed_pc=0x0c06f276u; return 0; }
r[0]=0x00000004u;
goto P_0c06f278;
P_0c06f278: /* original f348, guest PC 0x0c06f278 */
if(!s->budget--) { s->failed_pc=0x0c06f278u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c06f27a;
P_0c06f27a: /* original 750c, guest PC 0x0c06f27a */
if(!s->budget--) { s->failed_pc=0x0c06f27au; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f27c;
P_0c06f27c: /* original f340, guest PC 0x0c06f27c */
if(!s->budget--) { s->failed_pc=0x0c06f27cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c06f27e;
P_0c06f27e: /* original f53a, guest PC 0x0c06f27e */
if(!s->budget--) { s->failed_pc=0x0c06f27eu; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c06f280;
P_0c06f280: /* original f246, guest PC 0x0c06f280 */
if(!s->budget--) { s->failed_pc=0x0c06f280u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c06f282;
P_0c06f282: /* original f527, guest PC 0x0c06f282 */
if(!s->budget--) { s->failed_pc=0x0c06f282u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c06f284;
P_0c06f284: /* original e008, guest PC 0x0c06f284 */
if(!s->budget--) { s->failed_pc=0x0c06f284u; return 0; }
r[0]=0x00000008u;
goto P_0c06f286;
P_0c06f286: /* original f346, guest PC 0x0c06f286 */
if(!s->budget--) { s->failed_pc=0x0c06f286u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f288;
P_0c06f288: /* original 7448, guest PC 0x0c06f288 */
if(!s->budget--) { s->failed_pc=0x0c06f288u; return 0; }
r[4]+=0x00000048u;
goto P_0c06f28a;
P_0c06f28a: /* original f537, guest PC 0x0c06f28a */
if(!s->budget--) { s->failed_pc=0x0c06f28au; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c06f28c;
P_0c06f28c: /* original 750c, guest PC 0x0c06f28c */
if(!s->budget--) { s->failed_pc=0x0c06f28cu; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f28e;
P_0c06f28e: /* original f348, guest PC 0x0c06f28e */
if(!s->budget--) { s->failed_pc=0x0c06f28eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c06f290;
P_0c06f290: /* original e004, guest PC 0x0c06f290 */
if(!s->budget--) { s->failed_pc=0x0c06f290u; return 0; }
r[0]=0x00000004u;
goto P_0c06f292;
P_0c06f292: /* original f340, guest PC 0x0c06f292 */
if(!s->budget--) { s->failed_pc=0x0c06f292u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c06f294;
P_0c06f294: /* original f53a, guest PC 0x0c06f294 */
if(!s->budget--) { s->failed_pc=0x0c06f294u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c06f296;
P_0c06f296: /* original f246, guest PC 0x0c06f296 */
if(!s->budget--) { s->failed_pc=0x0c06f296u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c06f298;
P_0c06f298: /* original f527, guest PC 0x0c06f298 */
if(!s->budget--) { s->failed_pc=0x0c06f298u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c06f29a;
P_0c06f29a: /* original e008, guest PC 0x0c06f29a */
if(!s->budget--) { s->failed_pc=0x0c06f29au; return 0; }
r[0]=0x00000008u;
goto P_0c06f29c;
P_0c06f29c: /* original f346, guest PC 0x0c06f29c */
if(!s->budget--) { s->failed_pc=0x0c06f29cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f29e;
P_0c06f29e: /* original 7418, guest PC 0x0c06f29e */
if(!s->budget--) { s->failed_pc=0x0c06f29eu; return 0; }
r[4]+=0x00000018u;
goto P_0c06f2a0;
P_0c06f2a0: /* original f537, guest PC 0x0c06f2a0 */
if(!s->budget--) { s->failed_pc=0x0c06f2a0u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c06f2a2;
P_0c06f2a2: /* original e004, guest PC 0x0c06f2a2 */
if(!s->budget--) { s->failed_pc=0x0c06f2a2u; return 0; }
r[0]=0x00000004u;
goto P_0c06f2a4;
P_0c06f2a4: /* original f348, guest PC 0x0c06f2a4 */
if(!s->budget--) { s->failed_pc=0x0c06f2a4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c06f2a6;
P_0c06f2a6: /* original 750c, guest PC 0x0c06f2a6 */
if(!s->budget--) { s->failed_pc=0x0c06f2a6u; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f2a8;
P_0c06f2a8: /* original f340, guest PC 0x0c06f2a8 */
if(!s->budget--) { s->failed_pc=0x0c06f2a8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c06f2aa;
P_0c06f2aa: /* original f53a, guest PC 0x0c06f2aa */
if(!s->budget--) { s->failed_pc=0x0c06f2aau; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c06f2ac;
P_0c06f2ac: /* original f246, guest PC 0x0c06f2ac */
if(!s->budget--) { s->failed_pc=0x0c06f2acu; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c06f2ae;
P_0c06f2ae: /* original f527, guest PC 0x0c06f2ae */
if(!s->budget--) { s->failed_pc=0x0c06f2aeu; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c06f2b0;
P_0c06f2b0: /* original e008, guest PC 0x0c06f2b0 */
if(!s->budget--) { s->failed_pc=0x0c06f2b0u; return 0; }
r[0]=0x00000008u;
goto P_0c06f2b2;
P_0c06f2b2: /* original f346, guest PC 0x0c06f2b2 */
if(!s->budget--) { s->failed_pc=0x0c06f2b2u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f2b4;
P_0c06f2b4: /* original 7418, guest PC 0x0c06f2b4 */
if(!s->budget--) { s->failed_pc=0x0c06f2b4u; return 0; }
r[4]+=0x00000018u;
goto P_0c06f2b6;
P_0c06f2b6: /* original f537, guest PC 0x0c06f2b6 */
if(!s->budget--) { s->failed_pc=0x0c06f2b6u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c06f2b8;
P_0c06f2b8: /* original e004, guest PC 0x0c06f2b8 */
if(!s->budget--) { s->failed_pc=0x0c06f2b8u; return 0; }
r[0]=0x00000004u;
goto P_0c06f2ba;
P_0c06f2ba: /* original f348, guest PC 0x0c06f2ba */
if(!s->budget--) { s->failed_pc=0x0c06f2bau; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c06f2bc;
P_0c06f2bc: /* original 750c, guest PC 0x0c06f2bc */
if(!s->budget--) { s->failed_pc=0x0c06f2bcu; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f2be;
P_0c06f2be: /* original f340, guest PC 0x0c06f2be */
if(!s->budget--) { s->failed_pc=0x0c06f2beu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c06f2c0;
P_0c06f2c0: /* original f53a, guest PC 0x0c06f2c0 */
if(!s->budget--) { s->failed_pc=0x0c06f2c0u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c06f2c2;
P_0c06f2c2: /* original f246, guest PC 0x0c06f2c2 */
if(!s->budget--) { s->failed_pc=0x0c06f2c2u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c06f2c4;
P_0c06f2c4: /* original f527, guest PC 0x0c06f2c4 */
if(!s->budget--) { s->failed_pc=0x0c06f2c4u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c06f2c6;
P_0c06f2c6: /* original e008, guest PC 0x0c06f2c6 */
if(!s->budget--) { s->failed_pc=0x0c06f2c6u; return 0; }
r[0]=0x00000008u;
goto P_0c06f2c8;
P_0c06f2c8: /* original f346, guest PC 0x0c06f2c8 */
if(!s->budget--) { s->failed_pc=0x0c06f2c8u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f2ca;
P_0c06f2ca: /* original 7418, guest PC 0x0c06f2ca */
if(!s->budget--) { s->failed_pc=0x0c06f2cau; return 0; }
r[4]+=0x00000018u;
goto P_0c06f2cc;
P_0c06f2cc: /* original f537, guest PC 0x0c06f2cc */
if(!s->budget--) { s->failed_pc=0x0c06f2ccu; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c06f2ce;
P_0c06f2ce: /* original 750c, guest PC 0x0c06f2ce */
if(!s->budget--) { s->failed_pc=0x0c06f2ceu; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f2d0;
P_0c06f2d0: /* original f348, guest PC 0x0c06f2d0 */
if(!s->budget--) { s->failed_pc=0x0c06f2d0u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c06f2d2;
P_0c06f2d2: /* original f340, guest PC 0x0c06f2d2 */
if(!s->budget--) { s->failed_pc=0x0c06f2d2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c06f2d4;
P_0c06f2d4: /* original f53a, guest PC 0x0c06f2d4 */
if(!s->budget--) { s->failed_pc=0x0c06f2d4u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c06f2d6;
P_0c06f2d6: /* original e004, guest PC 0x0c06f2d6 */
if(!s->budget--) { s->failed_pc=0x0c06f2d6u; return 0; }
r[0]=0x00000004u;
goto P_0c06f2d8;
P_0c06f2d8: /* original f246, guest PC 0x0c06f2d8 */
if(!s->budget--) { s->failed_pc=0x0c06f2d8u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c06f2da;
P_0c06f2da: /* original f527, guest PC 0x0c06f2da */
if(!s->budget--) { s->failed_pc=0x0c06f2dau; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c06f2dc;
P_0c06f2dc: /* original e008, guest PC 0x0c06f2dc */
if(!s->budget--) { s->failed_pc=0x0c06f2dcu; return 0; }
r[0]=0x00000008u;
goto P_0c06f2de;
P_0c06f2de: /* original f346, guest PC 0x0c06f2de */
if(!s->budget--) { s->failed_pc=0x0c06f2deu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f2e0;
P_0c06f2e0: /* original f537, guest PC 0x0c06f2e0 */
if(!s->budget--) { s->failed_pc=0x0c06f2e0u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c06f2e2;
P_0c06f2e2: /* original e004, guest PC 0x0c06f2e2 */
if(!s->budget--) { s->failed_pc=0x0c06f2e2u; return 0; }
r[0]=0x00000004u;
goto P_0c06f2e4;
P_0c06f2e4: /* original 9354, guest PC 0x0c06f2e4 */
if(!s->budget--) { s->failed_pc=0x0c06f2e4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f390u,2);
goto P_0c06f2e6;
P_0c06f2e6: /* original 750c, guest PC 0x0c06f2e6 */
if(!s->budget--) { s->failed_pc=0x0c06f2e6u; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f2e8;
P_0c06f2e8: /* original 343c, guest PC 0x0c06f2e8 */
if(!s->budget--) { s->failed_pc=0x0c06f2e8u; return 0; }
r[4]+=r[3];
goto P_0c06f2ea;
P_0c06f2ea: /* original f348, guest PC 0x0c06f2ea */
if(!s->budget--) { s->failed_pc=0x0c06f2eau; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c06f2ec;
P_0c06f2ec: /* original f340, guest PC 0x0c06f2ec */
if(!s->budget--) { s->failed_pc=0x0c06f2ecu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c06f2ee;
P_0c06f2ee: /* original f53a, guest PC 0x0c06f2ee */
if(!s->budget--) { s->failed_pc=0x0c06f2eeu; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c06f2f0;
P_0c06f2f0: /* original f246, guest PC 0x0c06f2f0 */
if(!s->budget--) { s->failed_pc=0x0c06f2f0u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c06f2f2;
P_0c06f2f2: /* original f527, guest PC 0x0c06f2f2 */
if(!s->budget--) { s->failed_pc=0x0c06f2f2u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c06f2f4;
P_0c06f2f4: /* original e008, guest PC 0x0c06f2f4 */
if(!s->budget--) { s->failed_pc=0x0c06f2f4u; return 0; }
r[0]=0x00000008u;
goto P_0c06f2f6;
P_0c06f2f6: /* original f346, guest PC 0x0c06f2f6 */
if(!s->budget--) { s->failed_pc=0x0c06f2f6u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f2f8;
P_0c06f2f8: /* original 7418, guest PC 0x0c06f2f8 */
if(!s->budget--) { s->failed_pc=0x0c06f2f8u; return 0; }
r[4]+=0x00000018u;
goto P_0c06f2fa;
P_0c06f2fa: /* original f537, guest PC 0x0c06f2fa */
if(!s->budget--) { s->failed_pc=0x0c06f2fau; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c06f2fc;
P_0c06f2fc: /* original e004, guest PC 0x0c06f2fc */
if(!s->budget--) { s->failed_pc=0x0c06f2fcu; return 0; }
r[0]=0x00000004u;
goto P_0c06f2fe;
P_0c06f2fe: /* original f348, guest PC 0x0c06f2fe */
if(!s->budget--) { s->failed_pc=0x0c06f2feu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c06f300;
P_0c06f300: /* original 750c, guest PC 0x0c06f300 */
if(!s->budget--) { s->failed_pc=0x0c06f300u; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f302;
P_0c06f302: /* original f340, guest PC 0x0c06f302 */
if(!s->budget--) { s->failed_pc=0x0c06f302u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c06f304;
P_0c06f304: /* original f53a, guest PC 0x0c06f304 */
if(!s->budget--) { s->failed_pc=0x0c06f304u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c06f306;
P_0c06f306: /* original f246, guest PC 0x0c06f306 */
if(!s->budget--) { s->failed_pc=0x0c06f306u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c06f308;
P_0c06f308: /* original f527, guest PC 0x0c06f308 */
if(!s->budget--) { s->failed_pc=0x0c06f308u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c06f30a;
P_0c06f30a: /* original e008, guest PC 0x0c06f30a */
if(!s->budget--) { s->failed_pc=0x0c06f30au; return 0; }
r[0]=0x00000008u;
goto P_0c06f30c;
P_0c06f30c: /* original f346, guest PC 0x0c06f30c */
if(!s->budget--) { s->failed_pc=0x0c06f30cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f30e;
P_0c06f30e: /* original 7418, guest PC 0x0c06f30e */
if(!s->budget--) { s->failed_pc=0x0c06f30eu; return 0; }
r[4]+=0x00000018u;
goto P_0c06f310;
P_0c06f310: /* original f537, guest PC 0x0c06f310 */
if(!s->budget--) { s->failed_pc=0x0c06f310u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c06f312;
P_0c06f312: /* original 750c, guest PC 0x0c06f312 */
if(!s->budget--) { s->failed_pc=0x0c06f312u; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f314;
P_0c06f314: /* original f348, guest PC 0x0c06f314 */
if(!s->budget--) { s->failed_pc=0x0c06f314u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c06f316;
P_0c06f316: /* original e004, guest PC 0x0c06f316 */
if(!s->budget--) { s->failed_pc=0x0c06f316u; return 0; }
r[0]=0x00000004u;
goto P_0c06f318;
P_0c06f318: /* original f340, guest PC 0x0c06f318 */
if(!s->budget--) { s->failed_pc=0x0c06f318u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c06f31a;
P_0c06f31a: /* original f53a, guest PC 0x0c06f31a */
if(!s->budget--) { s->failed_pc=0x0c06f31au; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c06f31c;
P_0c06f31c: /* original f246, guest PC 0x0c06f31c */
if(!s->budget--) { s->failed_pc=0x0c06f31cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c06f31e;
P_0c06f31e: /* original f527, guest PC 0x0c06f31e */
if(!s->budget--) { s->failed_pc=0x0c06f31eu; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c06f320;
P_0c06f320: /* original e008, guest PC 0x0c06f320 */
if(!s->budget--) { s->failed_pc=0x0c06f320u; return 0; }
r[0]=0x00000008u;
goto P_0c06f322;
P_0c06f322: /* original f346, guest PC 0x0c06f322 */
if(!s->budget--) { s->failed_pc=0x0c06f322u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f324;
P_0c06f324: /* original 7418, guest PC 0x0c06f324 */
if(!s->budget--) { s->failed_pc=0x0c06f324u; return 0; }
r[4]+=0x00000018u;
goto P_0c06f326;
P_0c06f326: /* original f537, guest PC 0x0c06f326 */
if(!s->budget--) { s->failed_pc=0x0c06f326u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c06f328;
P_0c06f328: /* original e004, guest PC 0x0c06f328 */
if(!s->budget--) { s->failed_pc=0x0c06f328u; return 0; }
r[0]=0x00000004u;
goto P_0c06f32a;
P_0c06f32a: /* original f348, guest PC 0x0c06f32a */
if(!s->budget--) { s->failed_pc=0x0c06f32au; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c06f32c;
P_0c06f32c: /* original 750c, guest PC 0x0c06f32c */
if(!s->budget--) { s->failed_pc=0x0c06f32cu; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f32e;
P_0c06f32e: /* original f340, guest PC 0x0c06f32e */
if(!s->budget--) { s->failed_pc=0x0c06f32eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c06f330;
P_0c06f330: /* original f53a, guest PC 0x0c06f330 */
if(!s->budget--) { s->failed_pc=0x0c06f330u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c06f332;
P_0c06f332: /* original f246, guest PC 0x0c06f332 */
if(!s->budget--) { s->failed_pc=0x0c06f332u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c06f334;
P_0c06f334: /* original f527, guest PC 0x0c06f334 */
if(!s->budget--) { s->failed_pc=0x0c06f334u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c06f336;
P_0c06f336: /* original e008, guest PC 0x0c06f336 */
if(!s->budget--) { s->failed_pc=0x0c06f336u; return 0; }
r[0]=0x00000008u;
goto P_0c06f338;
P_0c06f338: /* original f346, guest PC 0x0c06f338 */
if(!s->budget--) { s->failed_pc=0x0c06f338u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f33a;
P_0c06f33a: /* original 7448, guest PC 0x0c06f33a */
if(!s->budget--) { s->failed_pc=0x0c06f33au; return 0; }
r[4]+=0x00000048u;
goto P_0c06f33c;
P_0c06f33c: /* original f537, guest PC 0x0c06f33c */
if(!s->budget--) { s->failed_pc=0x0c06f33cu; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c06f33e;
P_0c06f33e: /* original e004, guest PC 0x0c06f33e */
if(!s->budget--) { s->failed_pc=0x0c06f33eu; return 0; }
r[0]=0x00000004u;
goto P_0c06f340;
P_0c06f340: /* original f348, guest PC 0x0c06f340 */
if(!s->budget--) { s->failed_pc=0x0c06f340u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c06f342;
P_0c06f342: /* original 750c, guest PC 0x0c06f342 */
if(!s->budget--) { s->failed_pc=0x0c06f342u; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f344;
P_0c06f344: /* original f340, guest PC 0x0c06f344 */
if(!s->budget--) { s->failed_pc=0x0c06f344u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c06f346;
P_0c06f346: /* original f53a, guest PC 0x0c06f346 */
if(!s->budget--) { s->failed_pc=0x0c06f346u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c06f348;
P_0c06f348: /* original f246, guest PC 0x0c06f348 */
if(!s->budget--) { s->failed_pc=0x0c06f348u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c06f34a;
P_0c06f34a: /* original f527, guest PC 0x0c06f34a */
if(!s->budget--) { s->failed_pc=0x0c06f34au; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c06f34c;
P_0c06f34c: /* original e008, guest PC 0x0c06f34c */
if(!s->budget--) { s->failed_pc=0x0c06f34cu; return 0; }
r[0]=0x00000008u;
goto P_0c06f34e;
P_0c06f34e: /* original f346, guest PC 0x0c06f34e */
if(!s->budget--) { s->failed_pc=0x0c06f34eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f350;
P_0c06f350: /* original 7418, guest PC 0x0c06f350 */
if(!s->budget--) { s->failed_pc=0x0c06f350u; return 0; }
r[4]+=0x00000018u;
goto P_0c06f352;
P_0c06f352: /* original f537, guest PC 0x0c06f352 */
if(!s->budget--) { s->failed_pc=0x0c06f352u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c06f354;
P_0c06f354: /* original 750c, guest PC 0x0c06f354 */
if(!s->budget--) { s->failed_pc=0x0c06f354u; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f356;
P_0c06f356: /* original f348, guest PC 0x0c06f356 */
if(!s->budget--) { s->failed_pc=0x0c06f356u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c06f358;
P_0c06f358: /* original e004, guest PC 0x0c06f358 */
if(!s->budget--) { s->failed_pc=0x0c06f358u; return 0; }
r[0]=0x00000004u;
goto P_0c06f35a;
P_0c06f35a: /* original f340, guest PC 0x0c06f35a */
if(!s->budget--) { s->failed_pc=0x0c06f35au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c06f35c;
P_0c06f35c: /* original f53a, guest PC 0x0c06f35c */
if(!s->budget--) { s->failed_pc=0x0c06f35cu; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c06f35e;
P_0c06f35e: /* original f246, guest PC 0x0c06f35e */
if(!s->budget--) { s->failed_pc=0x0c06f35eu; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c06f360;
P_0c06f360: /* original f527, guest PC 0x0c06f360 */
if(!s->budget--) { s->failed_pc=0x0c06f360u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c06f362;
P_0c06f362: /* original e008, guest PC 0x0c06f362 */
if(!s->budget--) { s->failed_pc=0x0c06f362u; return 0; }
r[0]=0x00000008u;
goto P_0c06f364;
P_0c06f364: /* original f346, guest PC 0x0c06f364 */
if(!s->budget--) { s->failed_pc=0x0c06f364u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f366;
P_0c06f366: /* original 7418, guest PC 0x0c06f366 */
if(!s->budget--) { s->failed_pc=0x0c06f366u; return 0; }
r[4]+=0x00000018u;
goto P_0c06f368;
P_0c06f368: /* original f537, guest PC 0x0c06f368 */
if(!s->budget--) { s->failed_pc=0x0c06f368u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c06f36a;
P_0c06f36a: /* original e004, guest PC 0x0c06f36a */
if(!s->budget--) { s->failed_pc=0x0c06f36au; return 0; }
r[0]=0x00000004u;
goto P_0c06f36c;
P_0c06f36c: /* original f348, guest PC 0x0c06f36c */
if(!s->budget--) { s->failed_pc=0x0c06f36cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c06f36e;
P_0c06f36e: /* original 750c, guest PC 0x0c06f36e */
if(!s->budget--) { s->failed_pc=0x0c06f36eu; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f370;
P_0c06f370: /* original f340, guest PC 0x0c06f370 */
if(!s->budget--) { s->failed_pc=0x0c06f370u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c06f372;
P_0c06f372: /* original f53a, guest PC 0x0c06f372 */
if(!s->budget--) { s->failed_pc=0x0c06f372u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c06f374;
P_0c06f374: /* original f246, guest PC 0x0c06f374 */
if(!s->budget--) { s->failed_pc=0x0c06f374u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c06f376;
P_0c06f376: /* original f527, guest PC 0x0c06f376 */
if(!s->budget--) { s->failed_pc=0x0c06f376u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c06f378;
P_0c06f378: /* original e008, guest PC 0x0c06f378 */
if(!s->budget--) { s->failed_pc=0x0c06f378u; return 0; }
r[0]=0x00000008u;
goto P_0c06f37a;
P_0c06f37a: /* original f346, guest PC 0x0c06f37a */
if(!s->budget--) { s->failed_pc=0x0c06f37au; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f37c;
P_0c06f37c: /* original 7418, guest PC 0x0c06f37c */
if(!s->budget--) { s->failed_pc=0x0c06f37cu; return 0; }
r[4]+=0x00000018u;
goto P_0c06f37e;
P_0c06f37e: /* original f537, guest PC 0x0c06f37e */
if(!s->budget--) { s->failed_pc=0x0c06f37eu; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c06f380;
P_0c06f380: /* original 750c, guest PC 0x0c06f380 */
if(!s->budget--) { s->failed_pc=0x0c06f380u; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f382;
P_0c06f382: /* original f348, guest PC 0x0c06f382 */
if(!s->budget--) { s->failed_pc=0x0c06f382u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c06f384;
P_0c06f384: /* original e004, guest PC 0x0c06f384 */
if(!s->budget--) { s->failed_pc=0x0c06f384u; return 0; }
r[0]=0x00000004u;
goto P_0c06f386;
P_0c06f386: /* original f340, guest PC 0x0c06f386 */
if(!s->budget--) { s->failed_pc=0x0c06f386u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c06f388;
P_0c06f388: /* original f53a, guest PC 0x0c06f388 */
if(!s->budget--) { s->failed_pc=0x0c06f388u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c06f38a;
P_0c06f38a: /* original a007, guest PC 0x0c06f38a */
if(!s->budget--) { s->failed_pc=0x0c06f38au; return 0; }
goto P_0c06f39c;
P_0c06f38c: /* original 0009, guest PC 0x0c06f38c */
if(!s->budget--) { s->failed_pc=0x0c06f38cu; return 0; }
if(!vf3_matrix_family(0x0c06f38eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06f38eu; return 0; } return 1;
P_0c06f39c: /* original f246, guest PC 0x0c06f39c */
if(!s->budget--) { s->failed_pc=0x0c06f39cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c06f39e;
P_0c06f39e: /* original f527, guest PC 0x0c06f39e */
if(!s->budget--) { s->failed_pc=0x0c06f39eu; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c06f3a0;
P_0c06f3a0: /* original e008, guest PC 0x0c06f3a0 */
if(!s->budget--) { s->failed_pc=0x0c06f3a0u; return 0; }
r[0]=0x00000008u;
goto P_0c06f3a2;
P_0c06f3a2: /* original f346, guest PC 0x0c06f3a2 */
if(!s->budget--) { s->failed_pc=0x0c06f3a2u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06f3a4;
P_0c06f3a4: /* original f537, guest PC 0x0c06f3a4 */
if(!s->budget--) { s->failed_pc=0x0c06f3a4u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c06f3a6;
P_0c06f3a6: /* original 6073, guest PC 0x0c06f3a6 */
if(!s->budget--) { s->failed_pc=0x0c06f3a6u; return 0; }
r[0]=r[7];
goto P_0c06f3a8;
P_0c06f3a8: /* original 7f04, guest PC 0x0c06f3a8 */
if(!s->budget--) { s->failed_pc=0x0c06f3a8u; return 0; }
r[15]+=0x00000004u;
goto P_0c06f3aa;
P_0c06f3aa: /* original 4f16, guest PC 0x0c06f3aa */
if(!s->budget--) { s->failed_pc=0x0c06f3aau; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c06f3ac;
P_0c06f3ac: /* original 4f26, guest PC 0x0c06f3ac */
if(!s->budget--) { s->failed_pc=0x0c06f3acu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06f3ae;
P_0c06f3ae: /* original 6af6, guest PC 0x0c06f3ae */
if(!s->budget--) { s->failed_pc=0x0c06f3aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06f3b0;
P_0c06f3b0: /* original 6bf6, guest PC 0x0c06f3b0 */
if(!s->budget--) { s->failed_pc=0x0c06f3b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06f3b2;
P_0c06f3b2: /* original 6cf6, guest PC 0x0c06f3b2 */
if(!s->budget--) { s->failed_pc=0x0c06f3b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06f3b4;
P_0c06f3b4: /* original 6df6, guest PC 0x0c06f3b4 */
if(!s->budget--) { s->failed_pc=0x0c06f3b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06f3b6;
P_0c06f3b6: /* original 000b, guest PC 0x0c06f3b6 */
if(!s->budget--) { s->failed_pc=0x0c06f3b6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06f3b8: /* original 6ef6, guest PC 0x0c06f3b8 */
if(!s->budget--) { s->failed_pc=0x0c06f3b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06f3bau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06f3bau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
