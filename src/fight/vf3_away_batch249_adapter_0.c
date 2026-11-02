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
int vf3_away_batch249_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c038600u: goto P_0c038600;
case 0x0c038602u: goto P_0c038602;
case 0x0c038604u: goto P_0c038604;
case 0x0c038606u: goto P_0c038606;
case 0x0c038608u: goto P_0c038608;
case 0x0c03860au: goto P_0c03860a;
case 0x0c03860cu: goto P_0c03860c;
case 0x0c03860eu: goto P_0c03860e;
case 0x0c038610u: goto P_0c038610;
case 0x0c038612u: goto P_0c038612;
case 0x0c038614u: goto P_0c038614;
case 0x0c038616u: goto P_0c038616;
case 0x0c038618u: goto P_0c038618;
case 0x0c03861au: goto P_0c03861a;
case 0x0c03861cu: goto P_0c03861c;
case 0x0c03861eu: goto P_0c03861e;
case 0x0c038620u: goto P_0c038620;
case 0x0c038622u: goto P_0c038622;
case 0x0c038624u: goto P_0c038624;
case 0x0c038626u: goto P_0c038626;
case 0x0c038628u: goto P_0c038628;
case 0x0c03862au: goto P_0c03862a;
case 0x0c03862cu: goto P_0c03862c;
case 0x0c03862eu: goto P_0c03862e;
case 0x0c038630u: goto P_0c038630;
case 0x0c038632u: goto P_0c038632;
case 0x0c038634u: goto P_0c038634;
case 0x0c038636u: goto P_0c038636;
case 0x0c038638u: goto P_0c038638;
case 0x0c03863au: goto P_0c03863a;
case 0x0c03863cu: goto P_0c03863c;
case 0x0c03863eu: goto P_0c03863e;
case 0x0c038640u: goto P_0c038640;
case 0x0c038642u: goto P_0c038642;
case 0x0c038644u: goto P_0c038644;
case 0x0c038646u: goto P_0c038646;
case 0x0c038648u: goto P_0c038648;
case 0x0c03864au: goto P_0c03864a;
case 0x0c03864cu: goto P_0c03864c;
case 0x0c03864eu: goto P_0c03864e;
case 0x0c038650u: goto P_0c038650;
case 0x0c038652u: goto P_0c038652;
case 0x0c038654u: goto P_0c038654;
case 0x0c038656u: goto P_0c038656;
case 0x0c038658u: goto P_0c038658;
case 0x0c03865au: goto P_0c03865a;
case 0x0c03865cu: goto P_0c03865c;
case 0x0c038860u: goto P_0c038860;
case 0x0c038862u: goto P_0c038862;
case 0x0c038864u: goto P_0c038864;
case 0x0c038866u: goto P_0c038866;
case 0x0c038868u: goto P_0c038868;
case 0x0c03886au: goto P_0c03886a;
case 0x0c03886cu: goto P_0c03886c;
case 0x0c03886eu: goto P_0c03886e;
case 0x0c038870u: goto P_0c038870;
case 0x0c038872u: goto P_0c038872;
case 0x0c038874u: goto P_0c038874;
case 0x0c038876u: goto P_0c038876;
case 0x0c038878u: goto P_0c038878;
case 0x0c03887au: goto P_0c03887a;
case 0x0c03887cu: goto P_0c03887c;
case 0x0c038880u: goto P_0c038880;
case 0x0c038882u: goto P_0c038882;
case 0x0c038884u: goto P_0c038884;
case 0x0c038886u: goto P_0c038886;
case 0x0c038888u: goto P_0c038888;
case 0x0c03888au: goto P_0c03888a;
case 0x0c03888cu: goto P_0c03888c;
case 0x0c03888eu: goto P_0c03888e;
case 0x0c038890u: goto P_0c038890;
case 0x0c038892u: goto P_0c038892;
case 0x0c038894u: goto P_0c038894;
case 0x0c038896u: goto P_0c038896;
case 0x0c038898u: goto P_0c038898;
case 0x0c03889au: goto P_0c03889a;
case 0x0c03889cu: goto P_0c03889c;
case 0x0c03889eu: goto P_0c03889e;
case 0x0c0388a0u: goto P_0c0388a0;
case 0x0c0388b0u: goto P_0c0388b0;
case 0x0c0388b2u: goto P_0c0388b2;
case 0x0c0388b4u: goto P_0c0388b4;
case 0x0c0388c0u: goto P_0c0388c0;
case 0x0c0388c2u: goto P_0c0388c2;
case 0x0c0388c4u: goto P_0c0388c4;
case 0x0c0388c6u: goto P_0c0388c6;
case 0x0c0388c8u: goto P_0c0388c8;
case 0x0c0388cau: goto P_0c0388ca;
case 0x0c0388ccu: goto P_0c0388cc;
case 0x0c0388ceu: goto P_0c0388ce;
case 0x0c0388d0u: goto P_0c0388d0;
case 0x0c0388d2u: goto P_0c0388d2;
case 0x0c0388d4u: goto P_0c0388d4;
case 0x0c0388d6u: goto P_0c0388d6;
case 0x0c0388d8u: goto P_0c0388d8;
case 0x0c0388dau: goto P_0c0388da;
case 0x0c0388dcu: goto P_0c0388dc;
case 0x0c03e130u: goto P_0c03e130;
case 0x0c03e132u: goto P_0c03e132;
case 0x0c03e134u: goto P_0c03e134;
case 0x0c03e136u: goto P_0c03e136;
case 0x0c03e138u: goto P_0c03e138;
case 0x0c03e13au: goto P_0c03e13a;
case 0x0c03e13cu: goto P_0c03e13c;
case 0x0c03e13eu: goto P_0c03e13e;
case 0x0c03e140u: goto P_0c03e140;
case 0x0c03e142u: goto P_0c03e142;
case 0x0c03e144u: goto P_0c03e144;
case 0x0c03e146u: goto P_0c03e146;
case 0x0c03e148u: goto P_0c03e148;
case 0x0c03e14au: goto P_0c03e14a;
case 0x0c03e150u: goto P_0c03e150;
case 0x0c03e152u: goto P_0c03e152;
case 0x0c03e154u: goto P_0c03e154;
case 0x0c03e156u: goto P_0c03e156;
case 0x0c03e158u: goto P_0c03e158;
case 0x0c03e15au: goto P_0c03e15a;
case 0x0c03e160u: goto P_0c03e160;
case 0x0c03e162u: goto P_0c03e162;
case 0x0c03e164u: goto P_0c03e164;
case 0x0c03e166u: goto P_0c03e166;
case 0x0c03e168u: goto P_0c03e168;
case 0x0c03e16au: goto P_0c03e16a;
case 0x0c03e16cu: goto P_0c03e16c;
case 0x0c03e16eu: goto P_0c03e16e;
case 0x0c03e170u: goto P_0c03e170;
case 0x0c03e172u: goto P_0c03e172;
case 0x0c03e174u: goto P_0c03e174;
case 0x0c03e176u: goto P_0c03e176;
case 0x0c03e178u: goto P_0c03e178;
case 0x0c03e17au: goto P_0c03e17a;
case 0x0c03e17cu: goto P_0c03e17c;
case 0x0c03e17eu: goto P_0c03e17e;
case 0x0c03e180u: goto P_0c03e180;
case 0x0c03e182u: goto P_0c03e182;
case 0x0c03e184u: goto P_0c03e184;
case 0x0c03e186u: goto P_0c03e186;
case 0x0c03e188u: goto P_0c03e188;
case 0x0c03e18au: goto P_0c03e18a;
case 0x0c03e18cu: goto P_0c03e18c;
case 0x0c03e2a0u: goto P_0c03e2a0;
case 0x0c03e2a2u: goto P_0c03e2a2;
case 0x0c03e2b0u: goto P_0c03e2b0;
case 0x0c03e2b2u: goto P_0c03e2b2;
case 0x0c03e2b4u: goto P_0c03e2b4;
case 0x0c03e2b6u: goto P_0c03e2b6;
case 0x0c03e2b8u: goto P_0c03e2b8;
case 0x0c03e2bau: goto P_0c03e2ba;
case 0x0c03e2bcu: goto P_0c03e2bc;
case 0x0c03e2beu: goto P_0c03e2be;
case 0x0c03e2c0u: goto P_0c03e2c0;
case 0x0c03e2c2u: goto P_0c03e2c2;
case 0x0c03e2c4u: goto P_0c03e2c4;
case 0x0c03e2c6u: goto P_0c03e2c6;
case 0x0c03e2c8u: goto P_0c03e2c8;
case 0x0c03e2cau: goto P_0c03e2ca;
case 0x0c03e2ccu: goto P_0c03e2cc;
case 0x0c03e2ceu: goto P_0c03e2ce;
case 0x0c03e2d0u: goto P_0c03e2d0;
case 0x0c03e2d2u: goto P_0c03e2d2;
case 0x0c03e2d4u: goto P_0c03e2d4;
case 0x0c03e2d6u: goto P_0c03e2d6;
case 0x0c03e2d8u: goto P_0c03e2d8;
case 0x0c03e2dau: goto P_0c03e2da;
case 0x0c03e2dcu: goto P_0c03e2dc;
case 0x0c03e2deu: goto P_0c03e2de;
case 0x0c03e2f0u: goto P_0c03e2f0;
case 0x0c03e2f2u: goto P_0c03e2f2;
case 0x0c03e2f4u: goto P_0c03e2f4;
case 0x0c03e2f6u: goto P_0c03e2f6;
case 0x0c03e2f8u: goto P_0c03e2f8;
case 0x0c03e2fau: goto P_0c03e2fa;
case 0x0c03e2fcu: goto P_0c03e2fc;
case 0x0c03e2feu: goto P_0c03e2fe;
case 0x0c03e300u: goto P_0c03e300;
case 0x0c03e302u: goto P_0c03e302;
case 0x0c03e304u: goto P_0c03e304;
case 0x0c03e306u: goto P_0c03e306;
case 0x0c03e308u: goto P_0c03e308;
case 0x0c03e30au: goto P_0c03e30a;
case 0x0c03e30cu: goto P_0c03e30c;
case 0x0c03e30eu: goto P_0c03e30e;
case 0x0c03e310u: goto P_0c03e310;
case 0x0c03e312u: goto P_0c03e312;
case 0x0c03e314u: goto P_0c03e314;
case 0x0c03e316u: goto P_0c03e316;
case 0x0c03e318u: goto P_0c03e318;
case 0x0c03e31au: goto P_0c03e31a;
case 0x0c03e31cu: goto P_0c03e31c;
case 0x0c03e31eu: goto P_0c03e31e;
case 0x0c03e320u: goto P_0c03e320;
case 0x0c03e322u: goto P_0c03e322;
case 0x0c03e324u: goto P_0c03e324;
case 0x0c03e326u: goto P_0c03e326;
case 0x0c03e330u: goto P_0c03e330;
case 0x0c03e332u: goto P_0c03e332;
case 0x0c03e334u: goto P_0c03e334;
case 0x0c03e336u: goto P_0c03e336;
case 0x0c03e338u: goto P_0c03e338;
case 0x0c03f0e0u: goto P_0c03f0e0;
case 0x0c03f0e2u: goto P_0c03f0e2;
case 0x0c03f0e4u: goto P_0c03f0e4;
case 0x0c03f0e6u: goto P_0c03f0e6;
case 0x0c03f0e8u: goto P_0c03f0e8;
case 0x0c03f0eau: goto P_0c03f0ea;
case 0x0c03f0ecu: goto P_0c03f0ec;
case 0x0c03f0eeu: goto P_0c03f0ee;
case 0x0c03f0f0u: goto P_0c03f0f0;
case 0x0c03f0f2u: goto P_0c03f0f2;
case 0x0c03f0f4u: goto P_0c03f0f4;
case 0x0c03f0f6u: goto P_0c03f0f6;
case 0x0c03f0f8u: goto P_0c03f0f8;
case 0x0c03f0fau: goto P_0c03f0fa;
case 0x0c03f0fcu: goto P_0c03f0fc;
case 0x0c03f0feu: goto P_0c03f0fe;
case 0x0c03f100u: goto P_0c03f100;
case 0x0c03f102u: goto P_0c03f102;
case 0x0c03f104u: goto P_0c03f104;
case 0x0c03f106u: goto P_0c03f106;
case 0x0c03f108u: goto P_0c03f108;
case 0x0c03f10au: goto P_0c03f10a;
case 0x0c03f10cu: goto P_0c03f10c;
case 0x0c03f10eu: goto P_0c03f10e;
case 0x0c03f110u: goto P_0c03f110;
case 0x0c03f112u: goto P_0c03f112;
case 0x0c03f114u: goto P_0c03f114;
case 0x0c03f116u: goto P_0c03f116;
case 0x0c03f118u: goto P_0c03f118;
case 0x0c03f11au: goto P_0c03f11a;
case 0x0c03f11cu: goto P_0c03f11c;
case 0x0c03f11eu: goto P_0c03f11e;
case 0x0c03f120u: goto P_0c03f120;
case 0x0c03f122u: goto P_0c03f122;
case 0x0c03f124u: goto P_0c03f124;
case 0x0c03f126u: goto P_0c03f126;
case 0x0c03f128u: goto P_0c03f128;
case 0x0c03f12au: goto P_0c03f12a;
case 0x0c03f12cu: goto P_0c03f12c;
case 0x0c03f12eu: goto P_0c03f12e;
case 0x0c03f130u: goto P_0c03f130;
case 0x0c03f132u: goto P_0c03f132;
case 0x0c03f134u: goto P_0c03f134;
case 0x0c03f136u: goto P_0c03f136;
case 0x0c03f138u: goto P_0c03f138;
case 0x0c03f13au: goto P_0c03f13a;
case 0x0c03f13cu: goto P_0c03f13c;
case 0x0c03f13eu: goto P_0c03f13e;
case 0x0c03f140u: goto P_0c03f140;
case 0x0c03f142u: goto P_0c03f142;
case 0x0c03f144u: goto P_0c03f144;
case 0x0c03f146u: goto P_0c03f146;
case 0x0c03f148u: goto P_0c03f148;
case 0x0c03f14au: goto P_0c03f14a;
case 0x0c03f14cu: goto P_0c03f14c;
case 0x0c03f14eu: goto P_0c03f14e;
case 0x0c03f150u: goto P_0c03f150;
case 0x0c03f152u: goto P_0c03f152;
case 0x0c03f154u: goto P_0c03f154;
case 0x0c03f156u: goto P_0c03f156;
case 0x0c03f158u: goto P_0c03f158;
case 0x0c03f15au: goto P_0c03f15a;
case 0x0c03f15cu: goto P_0c03f15c;
case 0x0c03f15eu: goto P_0c03f15e;
case 0x0c03f160u: goto P_0c03f160;
case 0x0c03f162u: goto P_0c03f162;
case 0x0c03f164u: goto P_0c03f164;
case 0x0c03f166u: goto P_0c03f166;
case 0x0c03f168u: goto P_0c03f168;
case 0x0c03f16au: goto P_0c03f16a;
case 0x0c03f16cu: goto P_0c03f16c;
case 0x0c03f16eu: goto P_0c03f16e;
case 0x0c03f170u: goto P_0c03f170;
case 0x0c03f172u: goto P_0c03f172;
case 0x0c03f174u: goto P_0c03f174;
case 0x0c03f176u: goto P_0c03f176;
case 0x0c03f178u: goto P_0c03f178;
case 0x0c03f17au: goto P_0c03f17a;
case 0x0c03f17cu: goto P_0c03f17c;
case 0x0c03f17eu: goto P_0c03f17e;
case 0x0c03f180u: goto P_0c03f180;
case 0x0c03f182u: goto P_0c03f182;
case 0x0c03f184u: goto P_0c03f184;
case 0x0c03f186u: goto P_0c03f186;
case 0x0c03f188u: goto P_0c03f188;
case 0x0c03f18au: goto P_0c03f18a;
case 0x0c03f18cu: goto P_0c03f18c;
case 0x0c03f18eu: goto P_0c03f18e;
case 0x0c03f190u: goto P_0c03f190;
case 0x0c03f192u: goto P_0c03f192;
case 0x0c03f194u: goto P_0c03f194;
case 0x0c03f196u: goto P_0c03f196;
case 0x0c03f198u: goto P_0c03f198;
case 0x0c03f19au: goto P_0c03f19a;
case 0x0c03f19cu: goto P_0c03f19c;
case 0x0c03f19eu: goto P_0c03f19e;
case 0x0c03f1a0u: goto P_0c03f1a0;
case 0x0c03f1a2u: goto P_0c03f1a2;
case 0x0c03f1a4u: goto P_0c03f1a4;
case 0x0c03f1a6u: goto P_0c03f1a6;
case 0x0c03f1a8u: goto P_0c03f1a8;
case 0x0c03f1aau: goto P_0c03f1aa;
case 0x0c03f1acu: goto P_0c03f1ac;
case 0x0c03f1aeu: goto P_0c03f1ae;
case 0x0c03f1b0u: goto P_0c03f1b0;
case 0x0c03f1b2u: goto P_0c03f1b2;
case 0x0c03f1b4u: goto P_0c03f1b4;
case 0x0c03f1b6u: goto P_0c03f1b6;
case 0x0c03f1b8u: goto P_0c03f1b8;
case 0x0c03f1bau: goto P_0c03f1ba;
case 0x0c03f1bcu: goto P_0c03f1bc;
case 0x0c03f1beu: goto P_0c03f1be;
case 0x0c03f1c0u: goto P_0c03f1c0;
case 0x0c03f1c2u: goto P_0c03f1c2;
case 0x0c03f1c4u: goto P_0c03f1c4;
case 0x0c03f1c6u: goto P_0c03f1c6;
case 0x0c03f1c8u: goto P_0c03f1c8;
case 0x0c03f1cau: goto P_0c03f1ca;
case 0x0c03f1ccu: goto P_0c03f1cc;
case 0x0c03f1ceu: goto P_0c03f1ce;
case 0x0c03f1d0u: goto P_0c03f1d0;
case 0x0c03f1d2u: goto P_0c03f1d2;
case 0x0c03f1d4u: goto P_0c03f1d4;
case 0x0c03f1d6u: goto P_0c03f1d6;
case 0x0c03f1d8u: goto P_0c03f1d8;
case 0x0c03f1dau: goto P_0c03f1da;
case 0x0c03f1e0u: goto P_0c03f1e0;
case 0x0c03f1e2u: goto P_0c03f1e2;
case 0x0c03f1e4u: goto P_0c03f1e4;
case 0x0c03f1e6u: goto P_0c03f1e6;
case 0x0c03f1e8u: goto P_0c03f1e8;
case 0x0c03f1eau: goto P_0c03f1ea;
case 0x0c03f1ecu: goto P_0c03f1ec;
case 0x0c03f1eeu: goto P_0c03f1ee;
case 0x0c03f1f0u: goto P_0c03f1f0;
case 0x0c03f1f2u: goto P_0c03f1f2;
case 0x0c03f1f4u: goto P_0c03f1f4;
case 0x0c03f1f6u: goto P_0c03f1f6;
case 0x0c03f1f8u: goto P_0c03f1f8;
case 0x0c03f1fau: goto P_0c03f1fa;
case 0x0c03f1fcu: goto P_0c03f1fc;
case 0x0c03f1feu: goto P_0c03f1fe;
case 0x0c03f200u: goto P_0c03f200;
case 0x0c03f202u: goto P_0c03f202;
case 0x0c03f204u: goto P_0c03f204;
case 0x0c03f206u: goto P_0c03f206;
case 0x0c03f208u: goto P_0c03f208;
case 0x0c03f20au: goto P_0c03f20a;
case 0x0c03f20cu: goto P_0c03f20c;
case 0x0c03f20eu: goto P_0c03f20e;
case 0x0c03f210u: goto P_0c03f210;
case 0x0c03f212u: goto P_0c03f212;
case 0x0c03f214u: goto P_0c03f214;
case 0x0c03f216u: goto P_0c03f216;
case 0x0c03f218u: goto P_0c03f218;
case 0x0c03f21au: goto P_0c03f21a;
case 0x0c03f21cu: goto P_0c03f21c;
case 0x0c03f21eu: goto P_0c03f21e;
case 0x0c03f220u: goto P_0c03f220;
case 0x0c03f222u: goto P_0c03f222;
case 0x0c03f224u: goto P_0c03f224;
case 0x0c03f226u: goto P_0c03f226;
case 0x0c03f228u: goto P_0c03f228;
case 0x0c03f22au: goto P_0c03f22a;
case 0x0c03f22cu: goto P_0c03f22c;
case 0x0c03f22eu: goto P_0c03f22e;
case 0x0c03f230u: goto P_0c03f230;
case 0x0c03f232u: goto P_0c03f232;
case 0x0c03f234u: goto P_0c03f234;
case 0x0c03f240u: goto P_0c03f240;
case 0x0c03f242u: goto P_0c03f242;
case 0x0c03f244u: goto P_0c03f244;
case 0x0c03f246u: goto P_0c03f246;
case 0x0c03f248u: goto P_0c03f248;
case 0x0c03f24au: goto P_0c03f24a;
case 0x0c03f24cu: goto P_0c03f24c;
case 0x0c03f24eu: goto P_0c03f24e;
case 0x0c03f250u: goto P_0c03f250;
case 0x0c03f252u: goto P_0c03f252;
case 0x0c03f254u: goto P_0c03f254;
case 0x0c03f256u: goto P_0c03f256;
case 0x0c03f258u: goto P_0c03f258;
case 0x0c03f25au: goto P_0c03f25a;
case 0x0c03f25cu: goto P_0c03f25c;
case 0x0c03f25eu: goto P_0c03f25e;
case 0x0c03f260u: goto P_0c03f260;
case 0x0c03f262u: goto P_0c03f262;
case 0x0c03f264u: goto P_0c03f264;
case 0x0c03f266u: goto P_0c03f266;
case 0x0c03f268u: goto P_0c03f268;
case 0x0c03f26au: goto P_0c03f26a;
case 0x0c03f26cu: goto P_0c03f26c;
case 0x0c03f26eu: goto P_0c03f26e;
case 0x0c03f270u: goto P_0c03f270;
case 0x0c03f272u: goto P_0c03f272;
case 0x0c03f274u: goto P_0c03f274;
case 0x0c03f276u: goto P_0c03f276;
case 0x0c03f278u: goto P_0c03f278;
case 0x0c03f27au: goto P_0c03f27a;
case 0x0c03f27cu: goto P_0c03f27c;
case 0x0c03f27eu: goto P_0c03f27e;
case 0x0c03f280u: goto P_0c03f280;
case 0x0c03f282u: goto P_0c03f282;
case 0x0c03f284u: goto P_0c03f284;
case 0x0c03f290u: goto P_0c03f290;
case 0x0c03f292u: goto P_0c03f292;
case 0x0c03f294u: goto P_0c03f294;
case 0x0c03f296u: goto P_0c03f296;
case 0x0c03f298u: goto P_0c03f298;
case 0x0c03f29au: goto P_0c03f29a;
case 0x0c03f29cu: goto P_0c03f29c;
case 0x0c03f29eu: goto P_0c03f29e;
case 0x0c03f2a0u: goto P_0c03f2a0;
case 0x0c03f2a2u: goto P_0c03f2a2;
case 0x0c03f2a4u: goto P_0c03f2a4;
case 0x0c03f2a6u: goto P_0c03f2a6;
case 0x0c03f2a8u: goto P_0c03f2a8;
case 0x0c03f2aau: goto P_0c03f2aa;
case 0x0c03f2acu: goto P_0c03f2ac;
case 0x0c03f2aeu: goto P_0c03f2ae;
case 0x0c03f2b0u: goto P_0c03f2b0;
case 0x0c03f2b2u: goto P_0c03f2b2;
case 0x0c03f2b4u: goto P_0c03f2b4;
case 0x0c03f2b6u: goto P_0c03f2b6;
case 0x0c03f2b8u: goto P_0c03f2b8;
case 0x0c03f2bau: goto P_0c03f2ba;
case 0x0c03f2bcu: goto P_0c03f2bc;
case 0x0c03f2beu: goto P_0c03f2be;
case 0x0c03f2c0u: goto P_0c03f2c0;
case 0x0c03f2c2u: goto P_0c03f2c2;
case 0x0c03f2c4u: goto P_0c03f2c4;
case 0x0c03f2c6u: goto P_0c03f2c6;
case 0x0c03f2c8u: goto P_0c03f2c8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c038600: /* original 2fe6, guest PC 0x0c038600 */
if(!s->budget--) { s->failed_pc=0x0c038600u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038602;
P_0c038602: /* original 6e43, guest PC 0x0c038602 */
if(!s->budget--) { s->failed_pc=0x0c038602u; return 0; }
r[14]=r[4];
goto P_0c038604;
P_0c038604: /* original 2fd6, guest PC 0x0c038604 */
if(!s->budget--) { s->failed_pc=0x0c038604u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038606;
P_0c038606: /* original ed3c, guest PC 0x0c038606 */
if(!s->budget--) { s->failed_pc=0x0c038606u; return 0; }
r[13]=0x0000003cu;
goto P_0c038608;
P_0c038608: /* original 4f22, guest PC 0x0c038608 */
if(!s->budget--) { s->failed_pc=0x0c038608u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03860a;
P_0c03860a: /* original 4f12, guest PC 0x0c03860a */
if(!s->budget--) { s->failed_pc=0x0c03860au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03860c;
P_0c03860c: /* original 05d7, guest PC 0x0c03860c */
if(!s->budget--) { s->failed_pc=0x0c03860cu; return 0; }
r[19]=r[5]*r[13];
goto P_0c03860e;
P_0c03860e: /* original 7ff8, guest PC 0x0c03860e */
if(!s->budget--) { s->failed_pc=0x0c03860eu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c038610;
P_0c038610: /* original 2f62, guest PC 0x0c038610 */
if(!s->budget--) { s->failed_pc=0x0c038610u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c038612;
P_0c038612: /* original 0d1a, guest PC 0x0c038612 */
if(!s->budget--) { s->failed_pc=0x0c038612u; return 0; }
r[13]=r[19];
goto P_0c038614;
P_0c038614: /* original 1fd1, guest PC 0x0c038614 */
if(!s->budget--) { s->failed_pc=0x0c038614u; return 0; }
write(ram,r[15]+4,r[13],4);
goto P_0c038616;
P_0c038616: /* original d284, guest PC 0x0c038616 */
if(!s->budget--) { s->failed_pc=0x0c038616u; return 0; }
r[2]=read(ram,0x0c038828u,4);
goto P_0c038618;
P_0c038618: /* original d484, guest PC 0x0c038618 */
if(!s->budget--) { s->failed_pc=0x0c038618u; return 0; }
r[4]=read(ram,0x0c03882cu,4);
goto P_0c03861a;
P_0c03861a: /* original 6322, guest PC 0x0c03861a */
if(!s->budget--) { s->failed_pc=0x0c03861au; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03861c;
P_0c03861c: /* original 6142, guest PC 0x0c03861c */
if(!s->budget--) { s->failed_pc=0x0c03861cu; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c03861e;
P_0c03861e: /* original 3d3c, guest PC 0x0c03861e */
if(!s->budget--) { s->failed_pc=0x0c03861eu; return 0; }
r[13]+=r[3];
goto P_0c038620;
P_0c038620: /* original 7101, guest PC 0x0c038620 */
if(!s->budget--) { s->failed_pc=0x0c038620u; return 0; }
r[1]+=0x00000001u;
goto P_0c038622;
P_0c038622: /* original 2412, guest PC 0x0c038622 */
if(!s->budget--) { s->failed_pc=0x0c038622u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c038624;
P_0c038624: /* original 85e1, guest PC 0x0c038624 */
if(!s->budget--) { s->failed_pc=0x0c038624u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c038626;
P_0c038626: /* original 57e1, guest PC 0x0c038626 */
if(!s->budget--) { s->failed_pc=0x0c038626u; return 0; }
r[7]=read(ram,r[14]+4,4);
goto P_0c038628;
P_0c038628: /* original 65e1, guest PC 0x0c038628 */
if(!s->budget--) { s->failed_pc=0x0c038628u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[5]=tmp;
goto P_0c03862a;
P_0c03862a: /* original 6603, guest PC 0x0c03862a */
if(!s->budget--) { s->failed_pc=0x0c03862au; return 0; }
r[6]=r[0];
goto P_0c03862c;
P_0c03862c: /* original d380, guest PC 0x0c03862c */
if(!s->budget--) { s->failed_pc=0x0c03862cu; return 0; }
r[3]=read(ram,0x0c038830u,4);
goto P_0c03862e;
P_0c03862e: /* original 430b, guest PC 0x0c03862e */
if(!s->budget--) { s->failed_pc=0x0c03862eu; return 0; }
target=r[3];
r[16]=code_base|0x0c038632u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c038632u) { target=s->pc; goto dispatch; }
goto P_0c038632;
P_0c038630: /* original 64d3, guest PC 0x0c038630 */
if(!s->budget--) { s->failed_pc=0x0c038630u; return 0; }
r[4]=r[13];
goto P_0c038632;
P_0c038632: /* original 6403, guest PC 0x0c038632 */
if(!s->budget--) { s->failed_pc=0x0c038632u; return 0; }
r[4]=r[0];
goto P_0c038634;
P_0c038634: /* original 2448, guest PC 0x0c038634 */
if(!s->budget--) { s->failed_pc=0x0c038634u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c038636;
P_0c038636: /* original 8f0b, guest PC 0x0c038636 */
if(!s->budget--) { s->failed_pc=0x0c038636u; return 0; }
cond=r[17]&1u;
write(ram,r[13]+40,r[0],4);
if(!cond) { goto P_0c038650; }
goto P_0c03863a;
P_0c038638: /* original 1d0a, guest PC 0x0c038638 */
if(!s->budget--) { s->failed_pc=0x0c038638u; return 0; }
write(ram,r[13]+40,r[0],4);
goto P_0c03863a;
P_0c03863a: /* original d27b, guest PC 0x0c03863a */
if(!s->budget--) { s->failed_pc=0x0c03863au; return 0; }
r[2]=read(ram,0x0c038828u,4);
goto P_0c03863c;
P_0c03863c: /* original e700, guest PC 0x0c03863c */
if(!s->budget--) { s->failed_pc=0x0c03863cu; return 0; }
r[7]=0x00000000u;
goto P_0c03863e;
P_0c03863e: /* original 54f1, guest PC 0x0c03863e */
if(!s->budget--) { s->failed_pc=0x0c03863eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c038640;
P_0c038640: /* original 6322, guest PC 0x0c038640 */
if(!s->budget--) { s->failed_pc=0x0c038640u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c038642;
P_0c038642: /* original 65f2, guest PC 0x0c038642 */
if(!s->budget--) { s->failed_pc=0x0c038642u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c038644;
P_0c038644: /* original 343c, guest PC 0x0c038644 */
if(!s->budget--) { s->failed_pc=0x0c038644u; return 0; }
r[4]+=r[3];
goto P_0c038646;
P_0c038646: /* original d37b, guest PC 0x0c038646 */
if(!s->budget--) { s->failed_pc=0x0c038646u; return 0; }
r[3]=read(ram,0x0c038834u,4);
goto P_0c038648;
P_0c038648: /* original 430b, guest PC 0x0c038648 */
if(!s->budget--) { s->failed_pc=0x0c038648u; return 0; }
target=r[3];
r[16]=code_base|0x0c03864cu;
r[6]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03864cu) { target=s->pc; goto dispatch; }
goto P_0c03864c;
P_0c03864a: /* original 6673, guest PC 0x0c03864a */
if(!s->budget--) { s->failed_pc=0x0c03864au; return 0; }
r[6]=r[7];
goto P_0c03864c;
P_0c03864c: /* original a001, guest PC 0x0c03864c */
if(!s->budget--) { s->failed_pc=0x0c03864cu; return 0; }
r[0]=0x00000000u;
goto P_0c038652;
P_0c03864e: /* original e000, guest PC 0x0c03864e */
if(!s->budget--) { s->failed_pc=0x0c03864eu; return 0; }
r[0]=0x00000000u;
goto P_0c038650;
P_0c038650: /* original e001, guest PC 0x0c038650 */
if(!s->budget--) { s->failed_pc=0x0c038650u; return 0; }
r[0]=0x00000001u;
goto P_0c038652;
P_0c038652: /* original 7f08, guest PC 0x0c038652 */
if(!s->budget--) { s->failed_pc=0x0c038652u; return 0; }
r[15]+=0x00000008u;
goto P_0c038654;
P_0c038654: /* original 4f16, guest PC 0x0c038654 */
if(!s->budget--) { s->failed_pc=0x0c038654u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c038656;
P_0c038656: /* original 4f26, guest PC 0x0c038656 */
if(!s->budget--) { s->failed_pc=0x0c038656u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c038658;
P_0c038658: /* original 6df6, guest PC 0x0c038658 */
if(!s->budget--) { s->failed_pc=0x0c038658u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03865a;
P_0c03865a: /* original 000b, guest PC 0x0c03865a */
if(!s->budget--) { s->failed_pc=0x0c03865au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03865c: /* original 6ef6, guest PC 0x0c03865c */
if(!s->budget--) { s->failed_pc=0x0c03865cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03865eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03865eu; return 0; } return 1;
P_0c038860: /* original 2fe6, guest PC 0x0c038860 */
if(!s->budget--) { s->failed_pc=0x0c038860u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038862;
P_0c038862: /* original e700, guest PC 0x0c038862 */
if(!s->budget--) { s->failed_pc=0x0c038862u; return 0; }
r[7]=0x00000000u;
goto P_0c038864;
P_0c038864: /* original 2fd6, guest PC 0x0c038864 */
if(!s->budget--) { s->failed_pc=0x0c038864u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038866;
P_0c038866: /* original 6573, guest PC 0x0c038866 */
if(!s->budget--) { s->failed_pc=0x0c038866u; return 0; }
r[5]=r[7];
goto P_0c038868;
P_0c038868: /* original 2fb6, guest PC 0x0c038868 */
if(!s->budget--) { s->failed_pc=0x0c038868u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03886a;
P_0c03886a: /* original 6e73, guest PC 0x0c03886a */
if(!s->budget--) { s->failed_pc=0x0c03886au; return 0; }
r[14]=r[7];
goto P_0c03886c;
P_0c03886c: /* original 2fa6, guest PC 0x0c03886c */
if(!s->budget--) { s->failed_pc=0x0c03886cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03886e;
P_0c03886e: /* original 6a73, guest PC 0x0c03886e */
if(!s->budget--) { s->failed_pc=0x0c03886eu; return 0; }
r[10]=r[7];
goto P_0c038870;
P_0c038870: /* original 2f96, guest PC 0x0c038870 */
if(!s->budget--) { s->failed_pc=0x0c038870u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038872;
P_0c038872: /* original e901, guest PC 0x0c038872 */
if(!s->budget--) { s->failed_pc=0x0c038872u; return 0; }
r[9]=0x00000001u;
goto P_0c038874;
P_0c038874: /* original 2f86, guest PC 0x0c038874 */
if(!s->budget--) { s->failed_pc=0x0c038874u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038876;
P_0c038876: /* original d854, guest PC 0x0c038876 */
if(!s->budget--) { s->failed_pc=0x0c038876u; return 0; }
r[8]=read(ram,0x0c0389c8u,4);
goto P_0c038878;
P_0c038878: /* original dd54, guest PC 0x0c038878 */
if(!s->budget--) { s->failed_pc=0x0c038878u; return 0; }
r[13]=read(ram,0x0c0389ccu,4);
goto P_0c03887a;
P_0c03887a: /* original a025, guest PC 0x0c03887a */
if(!s->budget--) { s->failed_pc=0x0c03887au; return 0; }
r[11]=r[7];
goto P_0c0388c8;
P_0c03887c: /* original 6b73, guest PC 0x0c03887c */
if(!s->budget--) { s->failed_pc=0x0c03887cu; return 0; }
r[11]=r[7];
if(!vf3_matrix_family(0x0c03887eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03887eu; return 0; } return 1;
P_0c038880: /* original 60d2, guest PC 0x0c038880 */
if(!s->budget--) { s->failed_pc=0x0c038880u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c038882;
P_0c038882: /* original 00be, guest PC 0x0c038882 */
if(!s->budget--) { s->failed_pc=0x0c038882u; return 0; }
r[0]=read(ram,r[11]+r[0],4);
goto P_0c038884;
P_0c038884: /* original 88ff, guest PC 0x0c038884 */
if(!s->budget--) { s->failed_pc=0x0c038884u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c038886;
P_0c038886: /* original 8d1b, guest PC 0x0c038886 */
if(!s->budget--) { s->failed_pc=0x0c038886u; return 0; }
cond=r[17]&1u;
r[1]=r[0];
if(cond) { goto P_0c0388c0; }
goto P_0c03888a;
P_0c038888: /* original 6103, guest PC 0x0c038888 */
if(!s->budget--) { s->failed_pc=0x0c038888u; return 0; }
r[1]=r[0];
goto P_0c03888a;
P_0c03888a: /* original 6493, guest PC 0x0c03888a */
if(!s->budget--) { s->failed_pc=0x0c03888au; return 0; }
r[4]=r[9];
goto P_0c03888c;
P_0c03888c: /* original 6673, guest PC 0x0c03888c */
if(!s->budget--) { s->failed_pc=0x0c03888cu; return 0; }
r[6]=r[7];
goto P_0c03888e;
P_0c03888e: /* original 6213, guest PC 0x0c03888e */
if(!s->budget--) { s->failed_pc=0x0c03888eu; return 0; }
r[2]=r[1];
goto P_0c038890;
P_0c038890: /* original 2248, guest PC 0x0c038890 */
if(!s->budget--) { s->failed_pc=0x0c038890u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c038892;
P_0c038892: /* original 8b0d, guest PC 0x0c038892 */
if(!s->budget--) { s->failed_pc=0x0c038892u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0388b0; }
goto P_0c038894;
P_0c038894: /* original 60d2, guest PC 0x0c038894 */
if(!s->budget--) { s->failed_pc=0x0c038894u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c038896;
P_0c038896: /* original 02ee, guest PC 0x0c038896 */
if(!s->budget--) { s->failed_pc=0x0c038896u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c038898;
P_0c038898: /* original 224b, guest PC 0x0c038898 */
if(!s->budget--) { s->failed_pc=0x0c038898u; return 0; }
r[2]|=r[4];
goto P_0c03889a;
P_0c03889a: /* original 0e26, guest PC 0x0c03889a */
if(!s->budget--) { s->failed_pc=0x0c03889au; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c03889c;
P_0c03889c: /* original 6053, guest PC 0x0c03889c */
if(!s->budget--) { s->failed_pc=0x0c03889cu; return 0; }
r[0]=r[5];
goto P_0c03889e;
P_0c03889e: /* original a017, guest PC 0x0c03889e */
if(!s->budget--) { s->failed_pc=0x0c03889eu; return 0; }
r[0]+=r[6];
goto P_0c0388d0;
P_0c0388a0: /* original 306c, guest PC 0x0c0388a0 */
if(!s->budget--) { s->failed_pc=0x0c0388a0u; return 0; }
r[0]+=r[6];
if(!vf3_matrix_family(0x0c0388a2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0388a2u; return 0; } return 1;
P_0c0388b0: /* original 4400, guest PC 0x0c0388b0 */
if(!s->budget--) { s->failed_pc=0x0c0388b0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0388b2;
P_0c0388b2: /* original afec, guest PC 0x0c0388b2 */
if(!s->budget--) { s->failed_pc=0x0c0388b2u; return 0; }
r[6]+=0x00000001u;
goto P_0c03888e;
P_0c0388b4: /* original 7601, guest PC 0x0c0388b4 */
if(!s->budget--) { s->failed_pc=0x0c0388b4u; return 0; }
r[6]+=0x00000001u;
if(!vf3_matrix_family(0x0c0388b6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0388b6u; return 0; } return 1;
P_0c0388c0: /* original 7e04, guest PC 0x0c0388c0 */
if(!s->budget--) { s->failed_pc=0x0c0388c0u; return 0; }
r[14]+=0x00000004u;
goto P_0c0388c2;
P_0c0388c2: /* original 7b04, guest PC 0x0c0388c2 */
if(!s->budget--) { s->failed_pc=0x0c0388c2u; return 0; }
r[11]+=0x00000004u;
goto P_0c0388c4;
P_0c0388c4: /* original 7a01, guest PC 0x0c0388c4 */
if(!s->budget--) { s->failed_pc=0x0c0388c4u; return 0; }
r[10]+=0x00000001u;
goto P_0c0388c6;
P_0c0388c6: /* original 7520, guest PC 0x0c0388c6 */
if(!s->budget--) { s->failed_pc=0x0c0388c6u; return 0; }
r[5]+=0x00000020u;
goto P_0c0388c8;
P_0c0388c8: /* original 6382, guest PC 0x0c0388c8 */
if(!s->budget--) { s->failed_pc=0x0c0388c8u; return 0; }
tmp=read(ram,r[8],4);
r[3]=tmp;
goto P_0c0388ca;
P_0c0388ca: /* original 3a33, guest PC 0x0c0388ca */
if(!s->budget--) { s->failed_pc=0x0c0388cau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[3])!=0);
goto P_0c0388cc;
P_0c0388cc: /* original 8bd8, guest PC 0x0c0388cc */
if(!s->budget--) { s->failed_pc=0x0c0388ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c038880; }
goto P_0c0388ce;
P_0c0388ce: /* original e0ff, guest PC 0x0c0388ce */
if(!s->budget--) { s->failed_pc=0x0c0388ceu; return 0; }
r[0]=0xffffffffu;
goto P_0c0388d0;
P_0c0388d0: /* original 68f6, guest PC 0x0c0388d0 */
if(!s->budget--) { s->failed_pc=0x0c0388d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0388d2;
P_0c0388d2: /* original 69f6, guest PC 0x0c0388d2 */
if(!s->budget--) { s->failed_pc=0x0c0388d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0388d4;
P_0c0388d4: /* original 6af6, guest PC 0x0c0388d4 */
if(!s->budget--) { s->failed_pc=0x0c0388d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0388d6;
P_0c0388d6: /* original 6bf6, guest PC 0x0c0388d6 */
if(!s->budget--) { s->failed_pc=0x0c0388d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0388d8;
P_0c0388d8: /* original 6df6, guest PC 0x0c0388d8 */
if(!s->budget--) { s->failed_pc=0x0c0388d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0388da;
P_0c0388da: /* original 000b, guest PC 0x0c0388da */
if(!s->budget--) { s->failed_pc=0x0c0388dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0388dc: /* original 6ef6, guest PC 0x0c0388dc */
if(!s->budget--) { s->failed_pc=0x0c0388dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0388deu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0388deu; return 0; } return 1;
P_0c03e130: /* original 2fe6, guest PC 0x0c03e130 */
if(!s->budget--) { s->failed_pc=0x0c03e130u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e132;
P_0c03e132: /* original 2558, guest PC 0x0c03e132 */
if(!s->budget--) { s->failed_pc=0x0c03e132u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c03e134;
P_0c03e134: /* original 2fd6, guest PC 0x0c03e134 */
if(!s->budget--) { s->failed_pc=0x0c03e134u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e136;
P_0c03e136: /* original 2fc6, guest PC 0x0c03e136 */
if(!s->budget--) { s->failed_pc=0x0c03e136u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e138;
P_0c03e138: /* original 2fb6, guest PC 0x0c03e138 */
if(!s->budget--) { s->failed_pc=0x0c03e138u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e13a;
P_0c03e13a: /* original 2fa6, guest PC 0x0c03e13a */
if(!s->budget--) { s->failed_pc=0x0c03e13au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e13c;
P_0c03e13c: /* original 2f96, guest PC 0x0c03e13c */
if(!s->budget--) { s->failed_pc=0x0c03e13cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e13e;
P_0c03e13e: /* original 2f86, guest PC 0x0c03e13e */
if(!s->budget--) { s->failed_pc=0x0c03e13eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e140;
P_0c03e140: /* original 4f22, guest PC 0x0c03e140 */
if(!s->budget--) { s->failed_pc=0x0c03e140u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03e142;
P_0c03e142: /* original 7ff8, guest PC 0x0c03e142 */
if(!s->budget--) { s->failed_pc=0x0c03e142u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c03e144;
P_0c03e144: /* original 8d04, guest PC 0x0c03e144 */
if(!s->budget--) { s->failed_pc=0x0c03e144u; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(cond) { goto P_0c03e150; }
goto P_0c03e148;
P_0c03e146: /* original ec00, guest PC 0x0c03e146 */
if(!s->budget--) { s->failed_pc=0x0c03e146u; return 0; }
r[12]=0x00000000u;
goto P_0c03e148;
P_0c03e148: /* original a003, guest PC 0x0c03e148 */
if(!s->budget--) { s->failed_pc=0x0c03e148u; return 0; }
tmp=read(ram,r[5],4);
r[8]=tmp;
goto P_0c03e152;
P_0c03e14a: /* original 6852, guest PC 0x0c03e14a */
if(!s->budget--) { s->failed_pc=0x0c03e14au; return 0; }
tmp=read(ram,r[5],4);
r[8]=tmp;
if(!vf3_matrix_family(0x0c03e14cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e14cu; return 0; } return 1;
P_0c03e150: /* original 68c3, guest PC 0x0c03e150 */
if(!s->budget--) { s->failed_pc=0x0c03e150u; return 0; }
r[8]=r[12];
goto P_0c03e152;
P_0c03e152: /* original 2668, guest PC 0x0c03e152 */
if(!s->budget--) { s->failed_pc=0x0c03e152u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c03e154;
P_0c03e154: /* original 8904, guest PC 0x0c03e154 */
if(!s->budget--) { s->failed_pc=0x0c03e154u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03e160; }
goto P_0c03e156;
P_0c03e156: /* original 6262, guest PC 0x0c03e156 */
if(!s->budget--) { s->failed_pc=0x0c03e156u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c03e158;
P_0c03e158: /* original a003, guest PC 0x0c03e158 */
if(!s->budget--) { s->failed_pc=0x0c03e158u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c03e162;
P_0c03e15a: /* original 1f21, guest PC 0x0c03e15a */
if(!s->budget--) { s->failed_pc=0x0c03e15au; return 0; }
write(ram,r[15]+4,r[2],4);
if(!vf3_matrix_family(0x0c03e15cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e15cu; return 0; } return 1;
P_0c03e160: /* original 1fc1, guest PC 0x0c03e160 */
if(!s->budget--) { s->failed_pc=0x0c03e160u; return 0; }
write(ram,r[15]+4,r[12],4);
goto P_0c03e162;
P_0c03e162: /* original d90b, guest PC 0x0c03e162 */
if(!s->budget--) { s->failed_pc=0x0c03e162u; return 0; }
r[9]=read(ram,0x0c03e190u,4);
goto P_0c03e164;
P_0c03e164: /* original 6ec3, guest PC 0x0c03e164 */
if(!s->budget--) { s->failed_pc=0x0c03e164u; return 0; }
r[14]=r[12];
goto P_0c03e166;
P_0c03e166: /* original da0b, guest PC 0x0c03e166 */
if(!s->budget--) { s->failed_pc=0x0c03e166u; return 0; }
r[10]=read(ram,0x0c03e194u,4);
goto P_0c03e168;
P_0c03e168: /* original ebff, guest PC 0x0c03e168 */
if(!s->budget--) { s->failed_pc=0x0c03e168u; return 0; }
r[11]=0xffffffffu;
goto P_0c03e16a;
P_0c03e16a: /* original 5d43, guest PC 0x0c03e16a */
if(!s->budget--) { s->failed_pc=0x0c03e16au; return 0; }
r[13]=read(ram,r[4]+12,4);
goto P_0c03e16c;
P_0c03e16c: /* original 64d5, guest PC 0x0c03e16c */
if(!s->budget--) { s->failed_pc=0x0c03e16cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[13]+=2;
r[4]=tmp;
goto P_0c03e16e;
P_0c03e16e: /* original 4415, guest PC 0x0c03e16e */
if(!s->budget--) { s->failed_pc=0x0c03e16eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c03e170;
P_0c03e170: /* original 8901, guest PC 0x0c03e170 */
if(!s->budget--) { s->failed_pc=0x0c03e170u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03e176; }
goto P_0c03e172;
P_0c03e172: /* original a09d, guest PC 0x0c03e172 */
if(!s->budget--) { s->failed_pc=0x0c03e172u; return 0; }
goto P_0c03e2b0;
P_0c03e174: /* original 0009, guest PC 0x0c03e174 */
if(!s->budget--) { s->failed_pc=0x0c03e174u; return 0; }
goto P_0c03e176;
P_0c03e176: /* original 604c, guest PC 0x0c03e176 */
if(!s->budget--) { s->failed_pc=0x0c03e176u; return 0; }
r[0]=r[4]&255u;
goto P_0c03e178;
P_0c03e178: /* original e11e, guest PC 0x0c03e178 */
if(!s->budget--) { s->failed_pc=0x0c03e178u; return 0; }
r[1]=0x0000001eu;
goto P_0c03e17a;
P_0c03e17a: /* original 3012, guest PC 0x0c03e17a */
if(!s->budget--) { s->failed_pc=0x0c03e17au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>=r[1])!=0);
goto P_0c03e17c;
P_0c03e17c: /* original 8b01, guest PC 0x0c03e17c */
if(!s->budget--) { s->failed_pc=0x0c03e17cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03e182; }
goto P_0c03e17e;
P_0c03e17e: /* original a08f, guest PC 0x0c03e17e */
if(!s->budget--) { s->failed_pc=0x0c03e17eu; return 0; }
goto P_0c03e2a0;
P_0c03e180: /* original 0009, guest PC 0x0c03e180 */
if(!s->budget--) { s->failed_pc=0x0c03e180u; return 0; }
goto P_0c03e182;
P_0c03e182: /* original 4000, guest PC 0x0c03e182 */
if(!s->budget--) { s->failed_pc=0x0c03e182u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c03e184;
P_0c03e184: /* original 6103, guest PC 0x0c03e184 */
if(!s->budget--) { s->failed_pc=0x0c03e184u; return 0; }
r[1]=r[0];
goto P_0c03e186;
P_0c03e186: /* original c704, guest PC 0x0c03e186 */
if(!s->budget--) { s->failed_pc=0x0c03e186u; return 0; }
r[0]=code_base|0x0003e198u;
goto P_0c03e188;
P_0c03e188: /* original 001d, guest PC 0x0c03e188 */
if(!s->budget--) { s->failed_pc=0x0c03e188u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c03e18a;
P_0c03e18a: /* original 0023, guest PC 0x0c03e18a */
if(!s->budget--) { s->failed_pc=0x0c03e18au; return 0; }
target=r[0]+0x0c03e18eu;
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
P_0c03e18c: /* original 0009, guest PC 0x0c03e18c */
if(!s->budget--) { s->failed_pc=0x0c03e18cu; return 0; }
if(!vf3_matrix_family(0x0c03e18eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e18eu; return 0; } return 1;
P_0c03e2a0: /* original a014, guest PC 0x0c03e2a0 */
if(!s->budget--) { s->failed_pc=0x0c03e2a0u; return 0; }
r[0]=0xffffffffu;
goto P_0c03e2cc;
P_0c03e2a2: /* original e0ff, guest PC 0x0c03e2a2 */
if(!s->budget--) { s->failed_pc=0x0c03e2a2u; return 0; }
r[0]=0xffffffffu;
if(!vf3_matrix_family(0x0c03e2a4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e2a4u; return 0; } return 1;
P_0c03e2b0: /* original 2ee8, guest PC 0x0c03e2b0 */
if(!s->budget--) { s->failed_pc=0x0c03e2b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c03e2b2;
P_0c03e2b2: /* original 890a, guest PC 0x0c03e2b2 */
if(!s->budget--) { s->failed_pc=0x0c03e2b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03e2ca; }
goto P_0c03e2b4;
P_0c03e2b4: /* original d20b, guest PC 0x0c03e2b4 */
if(!s->budget--) { s->failed_pc=0x0c03e2b4u; return 0; }
r[2]=read(ram,0x0c03e2e4u,4);
goto P_0c03e2b6;
P_0c03e2b6: /* original 420b, guest PC 0x0c03e2b6 */
if(!s->budget--) { s->failed_pc=0x0c03e2b6u; return 0; }
target=r[2];
r[16]=code_base|0x0c03e2bau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e2bau) { target=s->pc; goto dispatch; }
goto P_0c03e2ba;
P_0c03e2b8: /* original 64e3, guest PC 0x0c03e2b8 */
if(!s->budget--) { s->failed_pc=0x0c03e2b8u; return 0; }
r[4]=r[14];
goto P_0c03e2ba;
P_0c03e2ba: /* original 60e2, guest PC 0x0c03e2ba */
if(!s->budget--) { s->failed_pc=0x0c03e2bau; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c03e2bc;
P_0c03e2bc: /* original cb0d, guest PC 0x0c03e2bc */
if(!s->budget--) { s->failed_pc=0x0c03e2bcu; return 0; }
r[0]|=13u;
goto P_0c03e2be;
P_0c03e2be: /* original 2e02, guest PC 0x0c03e2be */
if(!s->budget--) { s->failed_pc=0x0c03e2beu; return 0; }
write(ram,r[14],r[0],4);
goto P_0c03e2c0;
P_0c03e2c0: /* original 50e2, guest PC 0x0c03e2c0 */
if(!s->budget--) { s->failed_pc=0x0c03e2c0u; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c03e2c2;
P_0c03e2c2: /* original 930d, guest PC 0x0c03e2c2 */
if(!s->budget--) { s->failed_pc=0x0c03e2c2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e2e0u,2);
goto P_0c03e2c4;
P_0c03e2c4: /* original 2039, guest PC 0x0c03e2c4 */
if(!s->budget--) { s->failed_pc=0x0c03e2c4u; return 0; }
r[0]&=r[3];
goto P_0c03e2c6;
P_0c03e2c6: /* original cbc0, guest PC 0x0c03e2c6 */
if(!s->budget--) { s->failed_pc=0x0c03e2c6u; return 0; }
r[0]|=192u;
goto P_0c03e2c8;
P_0c03e2c8: /* original 1e02, guest PC 0x0c03e2c8 */
if(!s->budget--) { s->failed_pc=0x0c03e2c8u; return 0; }
write(ram,r[14]+8,r[0],4);
goto P_0c03e2ca;
P_0c03e2ca: /* original e000, guest PC 0x0c03e2ca */
if(!s->budget--) { s->failed_pc=0x0c03e2cau; return 0; }
r[0]=0x00000000u;
goto P_0c03e2cc;
P_0c03e2cc: /* original 7f08, guest PC 0x0c03e2cc */
if(!s->budget--) { s->failed_pc=0x0c03e2ccu; return 0; }
r[15]+=0x00000008u;
goto P_0c03e2ce;
P_0c03e2ce: /* original 4f26, guest PC 0x0c03e2ce */
if(!s->budget--) { s->failed_pc=0x0c03e2ceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03e2d0;
P_0c03e2d0: /* original 68f6, guest PC 0x0c03e2d0 */
if(!s->budget--) { s->failed_pc=0x0c03e2d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03e2d2;
P_0c03e2d2: /* original 69f6, guest PC 0x0c03e2d2 */
if(!s->budget--) { s->failed_pc=0x0c03e2d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03e2d4;
P_0c03e2d4: /* original 6af6, guest PC 0x0c03e2d4 */
if(!s->budget--) { s->failed_pc=0x0c03e2d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03e2d6;
P_0c03e2d6: /* original 6bf6, guest PC 0x0c03e2d6 */
if(!s->budget--) { s->failed_pc=0x0c03e2d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03e2d8;
P_0c03e2d8: /* original 6cf6, guest PC 0x0c03e2d8 */
if(!s->budget--) { s->failed_pc=0x0c03e2d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03e2da;
P_0c03e2da: /* original 6df6, guest PC 0x0c03e2da */
if(!s->budget--) { s->failed_pc=0x0c03e2dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03e2dc;
P_0c03e2dc: /* original 000b, guest PC 0x0c03e2dc */
if(!s->budget--) { s->failed_pc=0x0c03e2dcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03e2de: /* original 6ef6, guest PC 0x0c03e2de */
if(!s->budget--) { s->failed_pc=0x0c03e2deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03e2e0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e2e0u; return 0; } return 1;
P_0c03e2f0: /* original 2fe6, guest PC 0x0c03e2f0 */
if(!s->budget--) { s->failed_pc=0x0c03e2f0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e2f2;
P_0c03e2f2: /* original 6e43, guest PC 0x0c03e2f2 */
if(!s->budget--) { s->failed_pc=0x0c03e2f2u; return 0; }
r[14]=r[4];
goto P_0c03e2f4;
P_0c03e2f4: /* original 2fd6, guest PC 0x0c03e2f4 */
if(!s->budget--) { s->failed_pc=0x0c03e2f4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e2f6;
P_0c03e2f6: /* original 6d63, guest PC 0x0c03e2f6 */
if(!s->budget--) { s->failed_pc=0x0c03e2f6u; return 0; }
r[13]=r[6];
goto P_0c03e2f8;
P_0c03e2f8: /* original 2fc6, guest PC 0x0c03e2f8 */
if(!s->budget--) { s->failed_pc=0x0c03e2f8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e2fa;
P_0c03e2fa: /* original 6c53, guest PC 0x0c03e2fa */
if(!s->budget--) { s->failed_pc=0x0c03e2fau; return 0; }
r[12]=r[5];
goto P_0c03e2fc;
P_0c03e2fc: /* original 4f22, guest PC 0x0c03e2fc */
if(!s->budget--) { s->failed_pc=0x0c03e2fcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03e2fe;
P_0c03e2fe: /* original 53e1, guest PC 0x0c03e2fe */
if(!s->budget--) { s->failed_pc=0x0c03e2feu; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c03e300;
P_0c03e300: /* original 2338, guest PC 0x0c03e300 */
if(!s->budget--) { s->failed_pc=0x0c03e300u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03e302;
P_0c03e302: /* original 8903, guest PC 0x0c03e302 */
if(!s->budget--) { s->failed_pc=0x0c03e302u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03e30c; }
goto P_0c03e304;
P_0c03e304: /* original 65c3, guest PC 0x0c03e304 */
if(!s->budget--) { s->failed_pc=0x0c03e304u; return 0; }
r[5]=r[12];
goto P_0c03e306;
P_0c03e306: /* original 66d3, guest PC 0x0c03e306 */
if(!s->budget--) { s->failed_pc=0x0c03e306u; return 0; }
r[6]=r[13];
goto P_0c03e308;
P_0c03e308: /* original bf12, guest PC 0x0c03e308 */
if(!s->budget--) { s->failed_pc=0x0c03e308u; return 0; }
target=code_base|0x0c03e130u; r[16]=code_base|0x0c03e30cu;
r[4]=read(ram,r[14]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e30cu) { target=s->pc; goto dispatch; }
goto P_0c03e30c;
P_0c03e30a: /* original 54e1, guest PC 0x0c03e30a */
if(!s->budget--) { s->failed_pc=0x0c03e30au; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c03e30c;
P_0c03e30c: /* original 52eb, guest PC 0x0c03e30c */
if(!s->budget--) { s->failed_pc=0x0c03e30cu; return 0; }
r[2]=read(ram,r[14]+44,4);
goto P_0c03e30e;
P_0c03e30e: /* original 2228, guest PC 0x0c03e30e */
if(!s->budget--) { s->failed_pc=0x0c03e30eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03e310;
P_0c03e310: /* original 8903, guest PC 0x0c03e310 */
if(!s->budget--) { s->failed_pc=0x0c03e310u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03e31a; }
goto P_0c03e312;
P_0c03e312: /* original 65c3, guest PC 0x0c03e312 */
if(!s->budget--) { s->failed_pc=0x0c03e312u; return 0; }
r[5]=r[12];
goto P_0c03e314;
P_0c03e314: /* original 66d3, guest PC 0x0c03e314 */
if(!s->budget--) { s->failed_pc=0x0c03e314u; return 0; }
r[6]=r[13];
goto P_0c03e316;
P_0c03e316: /* original bfeb, guest PC 0x0c03e316 */
if(!s->budget--) { s->failed_pc=0x0c03e316u; return 0; }
target=code_base|0x0c03e2f0u; r[16]=code_base|0x0c03e31au;
r[4]=read(ram,r[14]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e31au) { target=s->pc; goto dispatch; }
goto P_0c03e31a;
P_0c03e318: /* original 54eb, guest PC 0x0c03e318 */
if(!s->budget--) { s->failed_pc=0x0c03e318u; return 0; }
r[4]=read(ram,r[14]+44,4);
goto P_0c03e31a;
P_0c03e31a: /* original 52ec, guest PC 0x0c03e31a */
if(!s->budget--) { s->failed_pc=0x0c03e31au; return 0; }
r[2]=read(ram,r[14]+48,4);
goto P_0c03e31c;
P_0c03e31c: /* original 2228, guest PC 0x0c03e31c */
if(!s->budget--) { s->failed_pc=0x0c03e31cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03e31e;
P_0c03e31e: /* original 8907, guest PC 0x0c03e31e */
if(!s->budget--) { s->failed_pc=0x0c03e31eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03e330; }
goto P_0c03e320;
P_0c03e320: /* original 64c3, guest PC 0x0c03e320 */
if(!s->budget--) { s->failed_pc=0x0c03e320u; return 0; }
r[4]=r[12];
goto P_0c03e322;
P_0c03e322: /* original 65d3, guest PC 0x0c03e322 */
if(!s->budget--) { s->failed_pc=0x0c03e322u; return 0; }
r[5]=r[13];
goto P_0c03e324;
P_0c03e324: /* original afeb, guest PC 0x0c03e324 */
if(!s->budget--) { s->failed_pc=0x0c03e324u; return 0; }
r[14]=read(ram,r[14]+48,4);
goto P_0c03e2fe;
P_0c03e326: /* original 5eec, guest PC 0x0c03e326 */
if(!s->budget--) { s->failed_pc=0x0c03e326u; return 0; }
r[14]=read(ram,r[14]+48,4);
if(!vf3_matrix_family(0x0c03e328u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e328u; return 0; } return 1;
P_0c03e330: /* original 4f26, guest PC 0x0c03e330 */
if(!s->budget--) { s->failed_pc=0x0c03e330u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03e332;
P_0c03e332: /* original 6cf6, guest PC 0x0c03e332 */
if(!s->budget--) { s->failed_pc=0x0c03e332u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03e334;
P_0c03e334: /* original 6df6, guest PC 0x0c03e334 */
if(!s->budget--) { s->failed_pc=0x0c03e334u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03e336;
P_0c03e336: /* original 000b, guest PC 0x0c03e336 */
if(!s->budget--) { s->failed_pc=0x0c03e336u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03e338: /* original 6ef6, guest PC 0x0c03e338 */
if(!s->budget--) { s->failed_pc=0x0c03e338u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03e33au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e33au; return 0; } return 1;
P_0c03f0e0: /* original 2fe6, guest PC 0x0c03f0e0 */
if(!s->budget--) { s->failed_pc=0x0c03f0e0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f0e2;
P_0c03f0e2: /* original e300, guest PC 0x0c03f0e2 */
if(!s->budget--) { s->failed_pc=0x0c03f0e2u; return 0; }
r[3]=0x00000000u;
goto P_0c03f0e4;
P_0c03f0e4: /* original 2fd6, guest PC 0x0c03f0e4 */
if(!s->budget--) { s->failed_pc=0x0c03f0e4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f0e6;
P_0c03f0e6: /* original 2fc6, guest PC 0x0c03f0e6 */
if(!s->budget--) { s->failed_pc=0x0c03f0e6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f0e8;
P_0c03f0e8: /* original 2fb6, guest PC 0x0c03f0e8 */
if(!s->budget--) { s->failed_pc=0x0c03f0e8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f0ea;
P_0c03f0ea: /* original eb01, guest PC 0x0c03f0ea */
if(!s->budget--) { s->failed_pc=0x0c03f0eau; return 0; }
r[11]=0x00000001u;
goto P_0c03f0ec;
P_0c03f0ec: /* original 2fa6, guest PC 0x0c03f0ec */
if(!s->budget--) { s->failed_pc=0x0c03f0ecu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f0ee;
P_0c03f0ee: /* original 2f96, guest PC 0x0c03f0ee */
if(!s->budget--) { s->failed_pc=0x0c03f0eeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f0f0;
P_0c03f0f0: /* original 2f86, guest PC 0x0c03f0f0 */
if(!s->budget--) { s->failed_pc=0x0c03f0f0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f0f2;
P_0c03f0f2: /* original fffb, guest PC 0x0c03f0f2 */
if(!s->budget--) { s->failed_pc=0x0c03f0f2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c03f0f4;
P_0c03f0f4: /* original 4f22, guest PC 0x0c03f0f4 */
if(!s->budget--) { s->failed_pc=0x0c03f0f4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f0f6;
P_0c03f0f6: /* original 4f12, guest PC 0x0c03f0f6 */
if(!s->budget--) { s->failed_pc=0x0c03f0f6u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03f0f8;
P_0c03f0f8: /* original 7ff0, guest PC 0x0c03f0f8 */
if(!s->budget--) { s->failed_pc=0x0c03f0f8u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c03f0fa;
P_0c03f0fa: /* original 1f52, guest PC 0x0c03f0fa */
if(!s->budget--) { s->failed_pc=0x0c03f0fau; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c03f0fc;
P_0c03f0fc: /* original 1fb3, guest PC 0x0c03f0fc */
if(!s->budget--) { s->failed_pc=0x0c03f0fcu; return 0; }
write(ram,r[15]+12,r[11],4);
goto P_0c03f0fe;
P_0c03f0fe: /* original 1f31, guest PC 0x0c03f0fe */
if(!s->budget--) { s->failed_pc=0x0c03f0feu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c03f100;
P_0c03f100: /* original 6242, guest PC 0x0c03f100 */
if(!s->budget--) { s->failed_pc=0x0c03f100u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c03f102;
P_0c03f102: /* original 4211, guest PC 0x0c03f102 */
if(!s->budget--) { s->failed_pc=0x0c03f102u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c03f104;
P_0c03f104: /* original 8b02, guest PC 0x0c03f104 */
if(!s->budget--) { s->failed_pc=0x0c03f104u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f10c; }
goto P_0c03f106;
P_0c03f106: /* original 5146, guest PC 0x0c03f106 */
if(!s->budget--) { s->failed_pc=0x0c03f106u; return 0; }
r[1]=read(ram,r[4]+24,4);
goto P_0c03f108;
P_0c03f108: /* original 2118, guest PC 0x0c03f108 */
if(!s->budget--) { s->failed_pc=0x0c03f108u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c03f10a;
P_0c03f10a: /* original 8b01, guest PC 0x0c03f10a */
if(!s->budget--) { s->failed_pc=0x0c03f10au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f110; }
goto P_0c03f10c;
P_0c03f10c: /* original a0d1, guest PC 0x0c03f10c */
if(!s->budget--) { s->failed_pc=0x0c03f10cu; return 0; }
r[0]=0x00000000u;
goto P_0c03f2b2;
P_0c03f10e: /* original e000, guest PC 0x0c03f10e */
if(!s->budget--) { s->failed_pc=0x0c03f10eu; return 0; }
r[0]=0x00000000u;
goto P_0c03f110;
P_0c03f110: /* original c77a, guest PC 0x0c03f110 */
if(!s->budget--) { s->failed_pc=0x0c03f110u; return 0; }
r[0]=code_base|0x0003f2fcu;
goto P_0c03f112;
P_0c03f112: /* original d97b, guest PC 0x0c03f112 */
if(!s->budget--) { s->failed_pc=0x0c03f112u; return 0; }
r[9]=read(ram,0x0c03f300u,4);
goto P_0c03f114;
P_0c03f114: /* original ff08, guest PC 0x0c03f114 */
if(!s->budget--) { s->failed_pc=0x0c03f114u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c03f116;
P_0c03f116: /* original 6843, guest PC 0x0c03f116 */
if(!s->budget--) { s->failed_pc=0x0c03f116u; return 0; }
r[8]=r[4];
goto P_0c03f118;
P_0c03f118: /* original 7818, guest PC 0x0c03f118 */
if(!s->budget--) { s->failed_pc=0x0c03f118u; return 0; }
r[8]+=0x00000018u;
goto P_0c03f11a;
P_0c03f11a: /* original 6e83, guest PC 0x0c03f11a */
if(!s->budget--) { s->failed_pc=0x0c03f11au; return 0; }
r[14]=r[8];
goto P_0c03f11c;
P_0c03f11c: /* original 5ae8, guest PC 0x0c03f11c */
if(!s->budget--) { s->failed_pc=0x0c03f11cu; return 0; }
r[10]=read(ram,r[14]+32,4);
goto P_0c03f11e;
P_0c03f11e: /* original 6da3, guest PC 0x0c03f11e */
if(!s->budget--) { s->failed_pc=0x0c03f11eu; return 0; }
r[13]=r[10];
goto P_0c03f120;
P_0c03f120: /* original 4d11, guest PC 0x0c03f120 */
if(!s->budget--) { s->failed_pc=0x0c03f120u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=0)!=0);
goto P_0c03f122;
P_0c03f122: /* original 8f3a, guest PC 0x0c03f122 */
if(!s->budget--) { s->failed_pc=0x0c03f122u; return 0; }
cond=r[17]&1u;
r[8]+=0x00000050u;
if(!cond) { goto P_0c03f19a; }
goto P_0c03f126;
P_0c03f124: /* original 7850, guest PC 0x0c03f124 */
if(!s->budget--) { s->failed_pc=0x0c03f124u; return 0; }
r[8]+=0x00000050u;
goto P_0c03f126;
P_0c03f126: /* original d273, guest PC 0x0c03f126 */
if(!s->budget--) { s->failed_pc=0x0c03f126u; return 0; }
r[2]=read(ram,0x0c03f2f4u,4);
goto P_0c03f128;
P_0c03f128: /* original 6192, guest PC 0x0c03f128 */
if(!s->budget--) { s->failed_pc=0x0c03f128u; return 0; }
tmp=read(ram,r[9],4);
r[1]=tmp;
goto P_0c03f12a;
P_0c03f12a: /* original 6322, guest PC 0x0c03f12a */
if(!s->budget--) { s->failed_pc=0x0c03f12au; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f12c;
P_0c03f12c: /* original 3d3c, guest PC 0x0c03f12c */
if(!s->budget--) { s->failed_pc=0x0c03f12cu; return 0; }
r[13]+=r[3];
goto P_0c03f12e;
P_0c03f12e: /* original 6cd3, guest PC 0x0c03f12e */
if(!s->budget--) { s->failed_pc=0x0c03f12eu; return 0; }
r[12]=r[13];
goto P_0c03f130;
P_0c03f130: /* original 4c08, guest PC 0x0c03f130 */
if(!s->budget--) { s->failed_pc=0x0c03f130u; return 0; }
r[12]<<=2;
goto P_0c03f132;
P_0c03f132: /* original 4c00, guest PC 0x0c03f132 */
if(!s->budget--) { s->failed_pc=0x0c03f132u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c03f134;
P_0c03f134: /* original 31cc, guest PC 0x0c03f134 */
if(!s->budget--) { s->failed_pc=0x0c03f134u; return 0; }
r[1]+=r[12];
goto P_0c03f136;
P_0c03f136: /* original 6012, guest PC 0x0c03f136 */
if(!s->budget--) { s->failed_pc=0x0c03f136u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c03f138;
P_0c03f138: /* original 2008, guest PC 0x0c03f138 */
if(!s->budget--) { s->failed_pc=0x0c03f138u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c03f13a;
P_0c03f13a: /* original 8b08, guest PC 0x0c03f13a */
if(!s->budget--) { s->failed_pc=0x0c03f13au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f14e; }
goto P_0c03f13c;
P_0c03f13c: /* original 6392, guest PC 0x0c03f13c */
if(!s->budget--) { s->failed_pc=0x0c03f13cu; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c03f13e;
P_0c03f13e: /* original e204, guest PC 0x0c03f13e */
if(!s->budget--) { s->failed_pc=0x0c03f13eu; return 0; }
r[2]=0x00000004u;
goto P_0c03f140;
P_0c03f140: /* original d170, guest PC 0x0c03f140 */
if(!s->budget--) { s->failed_pc=0x0c03f140u; return 0; }
r[1]=read(ram,0x0c03f304u,4);
goto P_0c03f142;
P_0c03f142: /* original 33cc, guest PC 0x0c03f142 */
if(!s->budget--) { s->failed_pc=0x0c03f142u; return 0; }
r[3]+=r[12];
goto P_0c03f144;
P_0c03f144: /* original 323c, guest PC 0x0c03f144 */
if(!s->budget--) { s->failed_pc=0x0c03f144u; return 0; }
r[2]+=r[3];
goto P_0c03f146;
P_0c03f146: /* original 410b, guest PC 0x0c03f146 */
if(!s->budget--) { s->failed_pc=0x0c03f146u; return 0; }
target=r[1];
r[16]=code_base|0x0c03f14au;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f14au) { target=s->pc; goto dispatch; }
goto P_0c03f14a;
P_0c03f148: /* original 2f26, guest PC 0x0c03f148 */
if(!s->budget--) { s->failed_pc=0x0c03f148u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f14a;
P_0c03f14a: /* original 61f6, guest PC 0x0c03f14a */
if(!s->budget--) { s->failed_pc=0x0c03f14au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c03f14c;
P_0c03f14c: /* original 2102, guest PC 0x0c03f14c */
if(!s->budget--) { s->failed_pc=0x0c03f14cu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c03f14e;
P_0c03f14e: /* original 6392, guest PC 0x0c03f14e */
if(!s->budget--) { s->failed_pc=0x0c03f14eu; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c03f150;
P_0c03f150: /* original 33cc, guest PC 0x0c03f150 */
if(!s->budget--) { s->failed_pc=0x0c03f150u; return 0; }
r[3]+=r[12];
goto P_0c03f152;
P_0c03f152: /* original 6232, guest PC 0x0c03f152 */
if(!s->budget--) { s->failed_pc=0x0c03f152u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c03f154;
P_0c03f154: /* original 7201, guest PC 0x0c03f154 */
if(!s->budget--) { s->failed_pc=0x0c03f154u; return 0; }
r[2]+=0x00000001u;
goto P_0c03f156;
P_0c03f156: /* original 2322, guest PC 0x0c03f156 */
if(!s->budget--) { s->failed_pc=0x0c03f156u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c03f158;
P_0c03f158: /* original 6d92, guest PC 0x0c03f158 */
if(!s->budget--) { s->failed_pc=0x0c03f158u; return 0; }
tmp=read(ram,r[9],4);
r[13]=tmp;
goto P_0c03f15a;
P_0c03f15a: /* original d26b, guest PC 0x0c03f15a */
if(!s->budget--) { s->failed_pc=0x0c03f15au; return 0; }
r[2]=read(ram,0x0c03f308u,4);
goto P_0c03f15c;
P_0c03f15c: /* original 3dcc, guest PC 0x0c03f15c */
if(!s->budget--) { s->failed_pc=0x0c03f15cu; return 0; }
r[13]+=r[12];
goto P_0c03f15e;
P_0c03f15e: /* original 5dd1, guest PC 0x0c03f15e */
if(!s->budget--) { s->failed_pc=0x0c03f15eu; return 0; }
r[13]=read(ram,r[13]+4,4);
goto P_0c03f160;
P_0c03f160: /* original ec3c, guest PC 0x0c03f160 */
if(!s->budget--) { s->failed_pc=0x0c03f160u; return 0; }
r[12]=0x0000003cu;
goto P_0c03f162;
P_0c03f162: /* original 6322, guest PC 0x0c03f162 */
if(!s->budget--) { s->failed_pc=0x0c03f162u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f164;
P_0c03f164: /* original 0dc7, guest PC 0x0c03f164 */
if(!s->budget--) { s->failed_pc=0x0c03f164u; return 0; }
r[19]=r[13]*r[12];
goto P_0c03f166;
P_0c03f166: /* original 0c1a, guest PC 0x0c03f166 */
if(!s->budget--) { s->failed_pc=0x0c03f166u; return 0; }
r[12]=r[19];
goto P_0c03f168;
P_0c03f168: /* original 3c3c, guest PC 0x0c03f168 */
if(!s->budget--) { s->failed_pc=0x0c03f168u; return 0; }
r[12]+=r[3];
goto P_0c03f16a;
P_0c03f16a: /* original 51cb, guest PC 0x0c03f16a */
if(!s->budget--) { s->failed_pc=0x0c03f16au; return 0; }
r[1]=read(ram,r[12]+44,4);
goto P_0c03f16c;
P_0c03f16c: /* original 2118, guest PC 0x0c03f16c */
if(!s->budget--) { s->failed_pc=0x0c03f16cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c03f16e;
P_0c03f16e: /* original 8b11, guest PC 0x0c03f16e */
if(!s->budget--) { s->failed_pc=0x0c03f16eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f194; }
goto P_0c03f170;
P_0c03f170: /* original 61a3, guest PC 0x0c03f170 */
if(!s->budget--) { s->failed_pc=0x0c03f170u; return 0; }
r[1]=r[10];
goto P_0c03f172;
P_0c03f172: /* original 53f2, guest PC 0x0c03f172 */
if(!s->budget--) { s->failed_pc=0x0c03f172u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c03f174;
P_0c03f174: /* original 4108, guest PC 0x0c03f174 */
if(!s->budget--) { s->failed_pc=0x0c03f174u; return 0; }
r[1]<<=2;
goto P_0c03f176;
P_0c03f176: /* original 65d3, guest PC 0x0c03f176 */
if(!s->budget--) { s->failed_pc=0x0c03f176u; return 0; }
r[5]=r[13];
goto P_0c03f178;
P_0c03f178: /* original 4108, guest PC 0x0c03f178 */
if(!s->budget--) { s->failed_pc=0x0c03f178u; return 0; }
r[1]<<=2;
goto P_0c03f17a;
P_0c03f17a: /* original 313c, guest PC 0x0c03f17a */
if(!s->budget--) { s->failed_pc=0x0c03f17au; return 0; }
r[1]+=r[3];
goto P_0c03f17c;
P_0c03f17c: /* original 2f12, guest PC 0x0c03f17c */
if(!s->budget--) { s->failed_pc=0x0c03f17cu; return 0; }
write(ram,r[15],r[1],4);
goto P_0c03f17e;
P_0c03f17e: /* original d363, guest PC 0x0c03f17e */
if(!s->budget--) { s->failed_pc=0x0c03f17eu; return 0; }
r[3]=read(ram,0x0c03f30cu,4);
goto P_0c03f180;
P_0c03f180: /* original 5612, guest PC 0x0c03f180 */
if(!s->budget--) { s->failed_pc=0x0c03f180u; return 0; }
r[6]=read(ram,r[1]+8,4);
goto P_0c03f182;
P_0c03f182: /* original 430b, guest PC 0x0c03f182 */
if(!s->budget--) { s->failed_pc=0x0c03f182u; return 0; }
target=r[3];
r[16]=code_base|0x0c03f186u;
r[4]=r[1];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f186u) { target=s->pc; goto dispatch; }
goto P_0c03f186;
P_0c03f184: /* original 6413, guest PC 0x0c03f184 */
if(!s->budget--) { s->failed_pc=0x0c03f184u; return 0; }
r[4]=r[1];
goto P_0c03f186;
P_0c03f186: /* original 52f1, guest PC 0x0c03f186 */
if(!s->budget--) { s->failed_pc=0x0c03f186u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c03f188;
P_0c03f188: /* original 220b, guest PC 0x0c03f188 */
if(!s->budget--) { s->failed_pc=0x0c03f188u; return 0; }
r[2]|=r[0];
goto P_0c03f18a;
P_0c03f18a: /* original 1f21, guest PC 0x0c03f18a */
if(!s->budget--) { s->failed_pc=0x0c03f18au; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c03f18c;
P_0c03f18c: /* original d360, guest PC 0x0c03f18c */
if(!s->budget--) { s->failed_pc=0x0c03f18cu; return 0; }
r[3]=read(ram,0x0c03f310u,4);
goto P_0c03f18e;
P_0c03f18e: /* original 430b, guest PC 0x0c03f18e */
if(!s->budget--) { s->failed_pc=0x0c03f18eu; return 0; }
target=r[3];
r[16]=code_base|0x0c03f192u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f192u) { target=s->pc; goto dispatch; }
goto P_0c03f192;
P_0c03f190: /* original 64d3, guest PC 0x0c03f190 */
if(!s->budget--) { s->failed_pc=0x0c03f190u; return 0; }
r[4]=r[13];
goto P_0c03f192;
P_0c03f192: /* original 1cde, guest PC 0x0c03f192 */
if(!s->budget--) { s->failed_pc=0x0c03f192u; return 0; }
write(ram,r[12]+56,r[13],4);
goto P_0c03f194;
P_0c03f194: /* original 52cb, guest PC 0x0c03f194 */
if(!s->budget--) { s->failed_pc=0x0c03f194u; return 0; }
r[2]=read(ram,r[12]+44,4);
goto P_0c03f196;
P_0c03f196: /* original 7201, guest PC 0x0c03f196 */
if(!s->budget--) { s->failed_pc=0x0c03f196u; return 0; }
r[2]+=0x00000001u;
goto P_0c03f198;
P_0c03f198: /* original 1c2b, guest PC 0x0c03f198 */
if(!s->budget--) { s->failed_pc=0x0c03f198u; return 0; }
write(ram,r[12]+44,r[2],4);
goto P_0c03f19a;
P_0c03f19a: /* original 4a11, guest PC 0x0c03f19a */
if(!s->budget--) { s->failed_pc=0x0c03f19au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=0)!=0);
goto P_0c03f19c;
P_0c03f19c: /* original 8906, guest PC 0x0c03f19c */
if(!s->budget--) { s->failed_pc=0x0c03f19cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03f1ac; }
goto P_0c03f19e;
P_0c03f19e: /* original 62e2, guest PC 0x0c03f19e */
if(!s->budget--) { s->failed_pc=0x0c03f19eu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f1a0;
P_0c03f1a0: /* original 22bb, guest PC 0x0c03f1a0 */
if(!s->budget--) { s->failed_pc=0x0c03f1a0u; return 0; }
r[2]|=r[11];
goto P_0c03f1a2;
P_0c03f1a2: /* original 2e22, guest PC 0x0c03f1a2 */
if(!s->budget--) { s->failed_pc=0x0c03f1a2u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c03f1a4;
P_0c03f1a4: /* original d35b, guest PC 0x0c03f1a4 */
if(!s->budget--) { s->failed_pc=0x0c03f1a4u; return 0; }
r[3]=read(ram,0x0c03f314u,4);
goto P_0c03f1a6;
P_0c03f1a6: /* original 51e1, guest PC 0x0c03f1a6 */
if(!s->budget--) { s->failed_pc=0x0c03f1a6u; return 0; }
r[1]=read(ram,r[14]+4,4);
goto P_0c03f1a8;
P_0c03f1a8: /* original 213b, guest PC 0x0c03f1a8 */
if(!s->budget--) { s->failed_pc=0x0c03f1a8u; return 0; }
r[1]|=r[3];
goto P_0c03f1aa;
P_0c03f1aa: /* original 1e11, guest PC 0x0c03f1aa */
if(!s->budget--) { s->failed_pc=0x0c03f1aau; return 0; }
write(ram,r[14]+4,r[1],4);
goto P_0c03f1ac;
P_0c03f1ac: /* original 52f3, guest PC 0x0c03f1ac */
if(!s->budget--) { s->failed_pc=0x0c03f1acu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c03f1ae;
P_0c03f1ae: /* original 22bb, guest PC 0x0c03f1ae */
if(!s->budget--) { s->failed_pc=0x0c03f1aeu; return 0; }
r[2]|=r[11];
goto P_0c03f1b0;
P_0c03f1b0: /* original 2228, guest PC 0x0c03f1b0 */
if(!s->budget--) { s->failed_pc=0x0c03f1b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03f1b2;
P_0c03f1b2: /* original 890b, guest PC 0x0c03f1b2 */
if(!s->budget--) { s->failed_pc=0x0c03f1b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03f1cc; }
goto P_0c03f1b4;
P_0c03f1b4: /* original d059, guest PC 0x0c03f1b4 */
if(!s->budget--) { s->failed_pc=0x0c03f1b4u; return 0; }
r[0]=read(ram,0x0c03f31cu,4);
goto P_0c03f1b6;
P_0c03f1b6: /* original 61e2, guest PC 0x0c03f1b6 */
if(!s->budget--) { s->failed_pc=0x0c03f1b6u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c03f1b8;
P_0c03f1b8: /* original d357, guest PC 0x0c03f1b8 */
if(!s->budget--) { s->failed_pc=0x0c03f1b8u; return 0; }
r[3]=read(ram,0x0c03f318u,4);
goto P_0c03f1ba;
P_0c03f1ba: /* original 6202, guest PC 0x0c03f1ba */
if(!s->budget--) { s->failed_pc=0x0c03f1bau; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c03f1bc;
P_0c03f1bc: /* original 2139, guest PC 0x0c03f1bc */
if(!s->budget--) { s->failed_pc=0x0c03f1bcu; return 0; }
r[1]&=r[3];
goto P_0c03f1be;
P_0c03f1be: /* original d358, guest PC 0x0c03f1be */
if(!s->budget--) { s->failed_pc=0x0c03f1beu; return 0; }
r[3]=read(ram,0x0c03f320u,4);
goto P_0c03f1c0;
P_0c03f1c0: /* original 4228, guest PC 0x0c03f1c0 */
if(!s->budget--) { s->failed_pc=0x0c03f1c0u; return 0; }
r[2]<<=16;
goto P_0c03f1c2;
P_0c03f1c2: /* original 223b, guest PC 0x0c03f1c2 */
if(!s->budget--) { s->failed_pc=0x0c03f1c2u; return 0; }
r[2]|=r[3];
goto P_0c03f1c4;
P_0c03f1c4: /* original 212b, guest PC 0x0c03f1c4 */
if(!s->budget--) { s->failed_pc=0x0c03f1c4u; return 0; }
r[1]|=r[2];
goto P_0c03f1c6;
P_0c03f1c6: /* original e200, guest PC 0x0c03f1c6 */
if(!s->budget--) { s->failed_pc=0x0c03f1c6u; return 0; }
r[2]=0x00000000u;
goto P_0c03f1c8;
P_0c03f1c8: /* original 2e12, guest PC 0x0c03f1c8 */
if(!s->budget--) { s->failed_pc=0x0c03f1c8u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c03f1ca;
P_0c03f1ca: /* original 1f23, guest PC 0x0c03f1ca */
if(!s->budget--) { s->failed_pc=0x0c03f1cau; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c03f1cc;
P_0c03f1cc: /* original 4d11, guest PC 0x0c03f1cc */
if(!s->budget--) { s->failed_pc=0x0c03f1ccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=0)!=0);
goto P_0c03f1ce;
P_0c03f1ce: /* original 8b07, guest PC 0x0c03f1ce */
if(!s->budget--) { s->failed_pc=0x0c03f1ceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f1e0; }
goto P_0c03f1d0;
P_0c03f1d0: /* original d254, guest PC 0x0c03f1d0 */
if(!s->budget--) { s->failed_pc=0x0c03f1d0u; return 0; }
r[2]=read(ram,0x0c03f324u,4);
goto P_0c03f1d2;
P_0c03f1d2: /* original 65d3, guest PC 0x0c03f1d2 */
if(!s->budget--) { s->failed_pc=0x0c03f1d2u; return 0; }
r[5]=r[13];
goto P_0c03f1d4;
P_0c03f1d4: /* original 420b, guest PC 0x0c03f1d4 */
if(!s->budget--) { s->failed_pc=0x0c03f1d4u; return 0; }
target=r[2];
r[16]=code_base|0x0c03f1d8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f1d8u) { target=s->pc; goto dispatch; }
goto P_0c03f1d8;
P_0c03f1d6: /* original 64e3, guest PC 0x0c03f1d6 */
if(!s->budget--) { s->failed_pc=0x0c03f1d6u; return 0; }
r[4]=r[14];
goto P_0c03f1d8;
P_0c03f1d8: /* original a005, guest PC 0x0c03f1d8 */
if(!s->budget--) { s->failed_pc=0x0c03f1d8u; return 0; }
goto P_0c03f1e6;
P_0c03f1da: /* original 0009, guest PC 0x0c03f1da */
if(!s->budget--) { s->failed_pc=0x0c03f1dau; return 0; }
if(!vf3_matrix_family(0x0c03f1dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f1dcu; return 0; } return 1;
P_0c03f1e0: /* original d251, guest PC 0x0c03f1e0 */
if(!s->budget--) { s->failed_pc=0x0c03f1e0u; return 0; }
r[2]=read(ram,0x0c03f328u,4);
goto P_0c03f1e2;
P_0c03f1e2: /* original 420b, guest PC 0x0c03f1e2 */
if(!s->budget--) { s->failed_pc=0x0c03f1e2u; return 0; }
target=r[2];
r[16]=code_base|0x0c03f1e6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f1e6u) { target=s->pc; goto dispatch; }
goto P_0c03f1e6;
P_0c03f1e4: /* original 64e3, guest PC 0x0c03f1e4 */
if(!s->budget--) { s->failed_pc=0x0c03f1e4u; return 0; }
r[4]=r[14];
goto P_0c03f1e6;
P_0c03f1e6: /* original d244, guest PC 0x0c03f1e6 */
if(!s->budget--) { s->failed_pc=0x0c03f1e6u; return 0; }
r[2]=read(ram,0x0c03f2f8u,4);
goto P_0c03f1e8;
P_0c03f1e8: /* original e3e5, guest PC 0x0c03f1e8 */
if(!s->budget--) { s->failed_pc=0x0c03f1e8u; return 0; }
r[3]=0xffffffe5u;
goto P_0c03f1ea;
P_0c03f1ea: /* original 50e3, guest PC 0x0c03f1ea */
if(!s->budget--) { s->failed_pc=0x0c03f1eau; return 0; }
r[0]=read(ram,r[14]+12,4);
goto P_0c03f1ec;
P_0c03f1ec: /* original e407, guest PC 0x0c03f1ec */
if(!s->budget--) { s->failed_pc=0x0c03f1ecu; return 0; }
r[4]=0x00000007u;
goto P_0c03f1ee;
P_0c03f1ee: /* original 6522, guest PC 0x0c03f1ee */
if(!s->budget--) { s->failed_pc=0x0c03f1eeu; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c03f1f0;
P_0c03f1f0: /* original 403d, guest PC 0x0c03f1f0 */
if(!s->budget--) { s->failed_pc=0x0c03f1f0u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?r[0]>>((-r[3])&31u):0):r[0]<<(r[3]&31u);
goto P_0c03f1f2;
P_0c03f1f2: /* original 2558, guest PC 0x0c03f1f2 */
if(!s->budget--) { s->failed_pc=0x0c03f1f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c03f1f4;
P_0c03f1f4: /* original 8d54, guest PC 0x0c03f1f4 */
if(!s->budget--) { s->failed_pc=0x0c03f1f4u; return 0; }
cond=r[17]&1u;
r[4]&=r[0];
if(cond) { goto P_0c03f2a0; }
goto P_0c03f1f8;
P_0c03f1f6: /* original 2409, guest PC 0x0c03f1f6 */
if(!s->budget--) { s->failed_pc=0x0c03f1f6u; return 0; }
r[4]&=r[0];
goto P_0c03f1f8;
P_0c03f1f8: /* original 6043, guest PC 0x0c03f1f8 */
if(!s->budget--) { s->failed_pc=0x0c03f1f8u; return 0; }
r[0]=r[4];
goto P_0c03f1fa;
P_0c03f1fa: /* original 8805, guest PC 0x0c03f1fa */
if(!s->budget--) { s->failed_pc=0x0c03f1fau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c03f1fc;
P_0c03f1fc: /* original 8902, guest PC 0x0c03f1fc */
if(!s->budget--) { s->failed_pc=0x0c03f1fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03f204; }
goto P_0c03f1fe;
P_0c03f1fe: /* original 6043, guest PC 0x0c03f1fe */
if(!s->budget--) { s->failed_pc=0x0c03f1feu; return 0; }
r[0]=r[4];
goto P_0c03f200;
P_0c03f200: /* original 8806, guest PC 0x0c03f200 */
if(!s->budget--) { s->failed_pc=0x0c03f200u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c03f202;
P_0c03f202: /* original 8b4d, guest PC 0x0c03f202 */
if(!s->budget--) { s->failed_pc=0x0c03f202u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f2a0; }
goto P_0c03f204;
P_0c03f204: /* original d349, guest PC 0x0c03f204 */
if(!s->budget--) { s->failed_pc=0x0c03f204u; return 0; }
r[3]=read(ram,0x0c03f32cu,4);
goto P_0c03f206;
P_0c03f206: /* original 54ef, guest PC 0x0c03f206 */
if(!s->budget--) { s->failed_pc=0x0c03f206u; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c03f208;
P_0c03f208: /* original 6231, guest PC 0x0c03f208 */
if(!s->budget--) { s->failed_pc=0x0c03f208u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[2]=tmp;
goto P_0c03f20a;
P_0c03f20a: /* original 3423, guest PC 0x0c03f20a */
if(!s->budget--) { s->failed_pc=0x0c03f20au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c03f20c;
P_0c03f20c: /* original 8948, guest PC 0x0c03f20c */
if(!s->budget--) { s->failed_pc=0x0c03f20cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03f2a0; }
goto P_0c03f20e;
P_0c03f20e: /* original d148, guest PC 0x0c03f20e */
if(!s->budget--) { s->failed_pc=0x0c03f20eu; return 0; }
r[1]=read(ram,0x0c03f330u,4);
goto P_0c03f210;
P_0c03f210: /* original 6043, guest PC 0x0c03f210 */
if(!s->budget--) { s->failed_pc=0x0c03f210u; return 0; }
r[0]=r[4];
goto P_0c03f212;
P_0c03f212: /* original 4008, guest PC 0x0c03f212 */
if(!s->budget--) { s->failed_pc=0x0c03f212u; return 0; }
r[0]<<=2;
goto P_0c03f214;
P_0c03f214: /* original 6a43, guest PC 0x0c03f214 */
if(!s->budget--) { s->failed_pc=0x0c03f214u; return 0; }
r[10]=r[4];
goto P_0c03f216;
P_0c03f216: /* original 6d12, guest PC 0x0c03f216 */
if(!s->budget--) { s->failed_pc=0x0c03f216u; return 0; }
tmp=read(ram,r[1],4);
r[13]=tmp;
goto P_0c03f218;
P_0c03f218: /* original 6243, guest PC 0x0c03f218 */
if(!s->budget--) { s->failed_pc=0x0c03f218u; return 0; }
r[2]=r[4];
goto P_0c03f21a;
P_0c03f21a: /* original 4a00, guest PC 0x0c03f21a */
if(!s->budget--) { s->failed_pc=0x0c03f21au; return 0; }
r[17]=(r[17]&~1u)|((r[10]>>31)!=0);
r[10]<<=1;
goto P_0c03f21c;
P_0c03f21c: /* original 4000, guest PC 0x0c03f21c */
if(!s->budget--) { s->failed_pc=0x0c03f21cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c03f21e;
P_0c03f21e: /* original 3d0c, guest PC 0x0c03f21e */
if(!s->budget--) { s->failed_pc=0x0c03f21eu; return 0; }
r[13]+=r[0];
goto P_0c03f220;
P_0c03f220: /* original 85d2, guest PC 0x0c03f220 */
if(!s->budget--) { s->failed_pc=0x0c03f220u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+4,2);
goto P_0c03f222;
P_0c03f222: /* original 3a2c, guest PC 0x0c03f222 */
if(!s->budget--) { s->failed_pc=0x0c03f222u; return 0; }
r[10]+=r[2];
goto P_0c03f224;
P_0c03f224: /* original 4a08, guest PC 0x0c03f224 */
if(!s->budget--) { s->failed_pc=0x0c03f224u; return 0; }
r[10]<<=2;
goto P_0c03f226;
P_0c03f226: /* original 2008, guest PC 0x0c03f226 */
if(!s->budget--) { s->failed_pc=0x0c03f226u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c03f228;
P_0c03f228: /* original 8d0a, guest PC 0x0c03f228 */
if(!s->budget--) { s->failed_pc=0x0c03f228u; return 0; }
cond=r[17]&1u;
r[10]+=r[5];
if(cond) { goto P_0c03f240; }
goto P_0c03f22c;
P_0c03f22a: /* original 3a5c, guest PC 0x0c03f22a */
if(!s->budget--) { s->failed_pc=0x0c03f22au; return 0; }
r[10]+=r[5];
goto P_0c03f22c;
P_0c03f22c: /* original 85d2, guest PC 0x0c03f22c */
if(!s->budget--) { s->failed_pc=0x0c03f22cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+4,2);
goto P_0c03f22e;
P_0c03f22e: /* original 7001, guest PC 0x0c03f22e */
if(!s->budget--) { s->failed_pc=0x0c03f22eu; return 0; }
r[0]+=0x00000001u;
goto P_0c03f230;
P_0c03f230: /* original 81d2, guest PC 0x0c03f230 */
if(!s->budget--) { s->failed_pc=0x0c03f230u; return 0; }
write(ram,r[13]+4,r[0],2);
goto P_0c03f232;
P_0c03f232: /* original a02e, guest PC 0x0c03f232 */
if(!s->budget--) { s->failed_pc=0x0c03f232u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[12]=tmp;
goto P_0c03f292;
P_0c03f234: /* original 6cd1, guest PC 0x0c03f234 */
if(!s->budget--) { s->failed_pc=0x0c03f234u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[12]=tmp;
if(!vf3_matrix_family(0x0c03f236u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f236u; return 0; } return 1;
P_0c03f240: /* original 84a2, guest PC 0x0c03f240 */
if(!s->budget--) { s->failed_pc=0x0c03f240u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+2,1);
goto P_0c03f242;
P_0c03f242: /* original e2fc, guest PC 0x0c03f242 */
if(!s->budget--) { s->failed_pc=0x0c03f242u; return 0; }
r[2]=0xfffffffcu;
goto P_0c03f244;
P_0c03f244: /* original 80d2, guest PC 0x0c03f244 */
if(!s->budget--) { s->failed_pc=0x0c03f244u; return 0; }
write(ram,r[13]+2,r[0],1);
goto P_0c03f246;
P_0c03f246: /* original 50a2, guest PC 0x0c03f246 */
if(!s->budget--) { s->failed_pc=0x0c03f246u; return 0; }
r[0]=read(ram,r[10]+8,4);
goto P_0c03f248;
P_0c03f248: /* original 700f, guest PC 0x0c03f248 */
if(!s->budget--) { s->failed_pc=0x0c03f248u; return 0; }
r[0]+=0x0000000fu;
goto P_0c03f24a;
P_0c03f24a: /* original 402c, guest PC 0x0c03f24a */
if(!s->budget--) { s->failed_pc=0x0c03f24au; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[0]>>((-r[2])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[2]&31u);
goto P_0c03f24c;
P_0c03f24c: /* original 80d3, guest PC 0x0c03f24c */
if(!s->budget--) { s->failed_pc=0x0c03f24cu; return 0; }
write(ram,r[13]+3,r[0],1);
goto P_0c03f24e;
P_0c03f24e: /* original 60b3, guest PC 0x0c03f24e */
if(!s->budget--) { s->failed_pc=0x0c03f24eu; return 0; }
r[0]=r[11];
goto P_0c03f250;
P_0c03f250: /* original 81d2, guest PC 0x0c03f250 */
if(!s->budget--) { s->failed_pc=0x0c03f250u; return 0; }
write(ram,r[13]+4,r[0],2);
goto P_0c03f252;
P_0c03f252: /* original 6043, guest PC 0x0c03f252 */
if(!s->budget--) { s->failed_pc=0x0c03f252u; return 0; }
r[0]=r[4];
goto P_0c03f254;
P_0c03f254: /* original 81d3, guest PC 0x0c03f254 */
if(!s->budget--) { s->failed_pc=0x0c03f254u; return 0; }
write(ram,r[13]+6,r[0],2);
goto P_0c03f256;
P_0c03f256: /* original 52a2, guest PC 0x0c03f256 */
if(!s->budget--) { s->failed_pc=0x0c03f256u; return 0; }
r[2]=read(ram,r[10]+8,4);
goto P_0c03f258;
P_0c03f258: /* original 6523, guest PC 0x0c03f258 */
if(!s->budget--) { s->failed_pc=0x0c03f258u; return 0; }
r[5]=r[2];
goto P_0c03f25a;
P_0c03f25a: /* original 2f22, guest PC 0x0c03f25a */
if(!s->budget--) { s->failed_pc=0x0c03f25au; return 0; }
write(ram,r[15],r[2],4);
goto P_0c03f25c;
P_0c03f25c: /* original d235, guest PC 0x0c03f25c */
if(!s->budget--) { s->failed_pc=0x0c03f25cu; return 0; }
r[2]=read(ram,0x0c03f334u,4);
goto P_0c03f25e;
P_0c03f25e: /* original 85a1, guest PC 0x0c03f25e */
if(!s->budget--) { s->failed_pc=0x0c03f25eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+2,2);
goto P_0c03f260;
P_0c03f260: /* original 420b, guest PC 0x0c03f260 */
if(!s->budget--) { s->failed_pc=0x0c03f260u; return 0; }
target=r[2];
r[16]=code_base|0x0c03f264u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f264u) { target=s->pc; goto dispatch; }
goto P_0c03f264;
P_0c03f262: /* original 6403, guest PC 0x0c03f262 */
if(!s->budget--) { s->failed_pc=0x0c03f262u; return 0; }
r[4]=r[0];
goto P_0c03f264;
P_0c03f264: /* original 6c03, guest PC 0x0c03f264 */
if(!s->budget--) { s->failed_pc=0x0c03f264u; return 0; }
r[12]=r[0];
goto P_0c03f266;
P_0c03f266: /* original 4c11, guest PC 0x0c03f266 */
if(!s->budget--) { s->failed_pc=0x0c03f266u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=0)!=0);
goto P_0c03f268;
P_0c03f268: /* original 8b12, guest PC 0x0c03f268 */
if(!s->budget--) { s->failed_pc=0x0c03f268u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f290; }
goto P_0c03f26a;
P_0c03f26a: /* original 2dc1, guest PC 0x0c03f26a */
if(!s->budget--) { s->failed_pc=0x0c03f26au; return 0; }
write(ram,r[13],r[12],2);
goto P_0c03f26c;
P_0c03f26c: /* original d332, guest PC 0x0c03f26c */
if(!s->budget--) { s->failed_pc=0x0c03f26cu; return 0; }
r[3]=read(ram,0x0c03f338u,4);
goto P_0c03f26e;
P_0c03f26e: /* original 65f2, guest PC 0x0c03f26e */
if(!s->budget--) { s->failed_pc=0x0c03f26eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c03f270;
P_0c03f270: /* original 430b, guest PC 0x0c03f270 */
if(!s->budget--) { s->failed_pc=0x0c03f270u; return 0; }
target=r[3];
r[16]=code_base|0x0c03f274u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f274u) { target=s->pc; goto dispatch; }
goto P_0c03f274;
P_0c03f272: /* original 64c3, guest PC 0x0c03f272 */
if(!s->budget--) { s->failed_pc=0x0c03f272u; return 0; }
r[4]=r[12];
goto P_0c03f274;
P_0c03f274: /* original 64c3, guest PC 0x0c03f274 */
if(!s->budget--) { s->failed_pc=0x0c03f274u; return 0; }
r[4]=r[12];
goto P_0c03f276;
P_0c03f276: /* original d331, guest PC 0x0c03f276 */
if(!s->budget--) { s->failed_pc=0x0c03f276u; return 0; }
r[3]=read(ram,0x0c03f33cu,4);
goto P_0c03f278;
P_0c03f278: /* original 66f2, guest PC 0x0c03f278 */
if(!s->budget--) { s->failed_pc=0x0c03f278u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c03f27a;
P_0c03f27a: /* original 4408, guest PC 0x0c03f27a */
if(!s->budget--) { s->failed_pc=0x0c03f27au; return 0; }
r[4]<<=2;
goto P_0c03f27c;
P_0c03f27c: /* original 55a1, guest PC 0x0c03f27c */
if(!s->budget--) { s->failed_pc=0x0c03f27cu; return 0; }
r[5]=read(ram,r[10]+4,4);
goto P_0c03f27e;
P_0c03f27e: /* original 430b, guest PC 0x0c03f27e */
if(!s->budget--) { s->failed_pc=0x0c03f27eu; return 0; }
target=r[3];
r[16]=code_base|0x0c03f282u;
r[4]<<=2;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f282u) { target=s->pc; goto dispatch; }
goto P_0c03f282;
P_0c03f280: /* original 4408, guest PC 0x0c03f280 */
if(!s->budget--) { s->failed_pc=0x0c03f280u; return 0; }
r[4]<<=2;
goto P_0c03f282;
P_0c03f282: /* original a006, guest PC 0x0c03f282 */
if(!s->budget--) { s->failed_pc=0x0c03f282u; return 0; }
goto P_0c03f292;
P_0c03f284: /* original 0009, guest PC 0x0c03f284 */
if(!s->budget--) { s->failed_pc=0x0c03f284u; return 0; }
if(!vf3_matrix_family(0x0c03f286u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f286u; return 0; } return 1;
P_0c03f290: /* original ec00, guest PC 0x0c03f290 */
if(!s->budget--) { s->failed_pc=0x0c03f290u; return 0; }
r[12]=0x00000000u;
goto P_0c03f292;
P_0c03f292: /* original 52e3, guest PC 0x0c03f292 */
if(!s->budget--) { s->failed_pc=0x0c03f292u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c03f294;
P_0c03f294: /* original e115, guest PC 0x0c03f294 */
if(!s->budget--) { s->failed_pc=0x0c03f294u; return 0; }
r[1]=0x00000015u;
goto P_0c03f296;
P_0c03f296: /* original d32a, guest PC 0x0c03f296 */
if(!s->budget--) { s->failed_pc=0x0c03f296u; return 0; }
r[3]=read(ram,0x0c03f340u,4);
goto P_0c03f298;
P_0c03f298: /* original 4c1c, guest PC 0x0c03f298 */
if(!s->budget--) { s->failed_pc=0x0c03f298u; return 0; }
r[12]=(r[1]&0x80000000u)?((r[1]&31u)?(uint32_t)((int32_t)r[12]>>((-r[1])&31u)):((int32_t)r[12]<0?0xffffffffu:0)):r[12]<<(r[1]&31u);
goto P_0c03f29a;
P_0c03f29a: /* original 2239, guest PC 0x0c03f29a */
if(!s->budget--) { s->failed_pc=0x0c03f29au; return 0; }
r[2]&=r[3];
goto P_0c03f29c;
P_0c03f29c: /* original 22cb, guest PC 0x0c03f29c */
if(!s->budget--) { s->failed_pc=0x0c03f29cu; return 0; }
r[2]|=r[12];
goto P_0c03f29e;
P_0c03f29e: /* original 1e23, guest PC 0x0c03f29e */
if(!s->budget--) { s->failed_pc=0x0c03f29eu; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c03f2a0;
P_0c03f2a0: /* original e04c, guest PC 0x0c03f2a0 */
if(!s->budget--) { s->failed_pc=0x0c03f2a0u; return 0; }
r[0]=0x0000004cu;
goto P_0c03f2a2;
P_0c03f2a2: /* original 03ee, guest PC 0x0c03f2a2 */
if(!s->budget--) { s->failed_pc=0x0c03f2a2u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c03f2a4;
P_0c03f2a4: /* original 383c, guest PC 0x0c03f2a4 */
if(!s->budget--) { s->failed_pc=0x0c03f2a4u; return 0; }
r[8]+=r[3];
goto P_0c03f2a6;
P_0c03f2a6: /* original 6482, guest PC 0x0c03f2a6 */
if(!s->budget--) { s->failed_pc=0x0c03f2a6u; return 0; }
tmp=read(ram,r[8],4);
r[4]=tmp;
goto P_0c03f2a8;
P_0c03f2a8: /* original 2448, guest PC 0x0c03f2a8 */
if(!s->budget--) { s->failed_pc=0x0c03f2a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03f2aa;
P_0c03f2aa: /* original 8901, guest PC 0x0c03f2aa */
if(!s->budget--) { s->failed_pc=0x0c03f2aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03f2b0; }
goto P_0c03f2ac;
P_0c03f2ac: /* original af35, guest PC 0x0c03f2ac */
if(!s->budget--) { s->failed_pc=0x0c03f2acu; return 0; }
goto P_0c03f11a;
P_0c03f2ae: /* original 0009, guest PC 0x0c03f2ae */
if(!s->budget--) { s->failed_pc=0x0c03f2aeu; return 0; }
goto P_0c03f2b0;
P_0c03f2b0: /* original 50f1, guest PC 0x0c03f2b0 */
if(!s->budget--) { s->failed_pc=0x0c03f2b0u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c03f2b2;
P_0c03f2b2: /* original 7f10, guest PC 0x0c03f2b2 */
if(!s->budget--) { s->failed_pc=0x0c03f2b2u; return 0; }
r[15]+=0x00000010u;
goto P_0c03f2b4;
P_0c03f2b4: /* original 4f16, guest PC 0x0c03f2b4 */
if(!s->budget--) { s->failed_pc=0x0c03f2b4u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f2b6;
P_0c03f2b6: /* original 4f26, guest PC 0x0c03f2b6 */
if(!s->budget--) { s->failed_pc=0x0c03f2b6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f2b8;
P_0c03f2b8: /* original fff9, guest PC 0x0c03f2b8 */
if(!s->budget--) { s->failed_pc=0x0c03f2b8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03f2ba;
P_0c03f2ba: /* original 68f6, guest PC 0x0c03f2ba */
if(!s->budget--) { s->failed_pc=0x0c03f2bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03f2bc;
P_0c03f2bc: /* original 69f6, guest PC 0x0c03f2bc */
if(!s->budget--) { s->failed_pc=0x0c03f2bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03f2be;
P_0c03f2be: /* original 6af6, guest PC 0x0c03f2be */
if(!s->budget--) { s->failed_pc=0x0c03f2beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03f2c0;
P_0c03f2c0: /* original 6bf6, guest PC 0x0c03f2c0 */
if(!s->budget--) { s->failed_pc=0x0c03f2c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03f2c2;
P_0c03f2c2: /* original 6cf6, guest PC 0x0c03f2c2 */
if(!s->budget--) { s->failed_pc=0x0c03f2c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03f2c4;
P_0c03f2c4: /* original 6df6, guest PC 0x0c03f2c4 */
if(!s->budget--) { s->failed_pc=0x0c03f2c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03f2c6;
P_0c03f2c6: /* original 000b, guest PC 0x0c03f2c6 */
if(!s->budget--) { s->failed_pc=0x0c03f2c6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03f2c8: /* original 6ef6, guest PC 0x0c03f2c8 */
if(!s->budget--) { s->failed_pc=0x0c03f2c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03f2cau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f2cau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
