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
int vf3_away_batch11_adapter_46(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09e060u: goto P_0c09e060;
case 0x0c09e062u: goto P_0c09e062;
case 0x0c09e064u: goto P_0c09e064;
case 0x0c09e066u: goto P_0c09e066;
case 0x0c09e068u: goto P_0c09e068;
case 0x0c09e06au: goto P_0c09e06a;
case 0x0c09e06cu: goto P_0c09e06c;
case 0x0c09e06eu: goto P_0c09e06e;
case 0x0c09e070u: goto P_0c09e070;
case 0x0c09e072u: goto P_0c09e072;
case 0x0c09e074u: goto P_0c09e074;
case 0x0c09e076u: goto P_0c09e076;
case 0x0c09e078u: goto P_0c09e078;
case 0x0c09e07au: goto P_0c09e07a;
case 0x0c09e07cu: goto P_0c09e07c;
case 0x0c09e07eu: goto P_0c09e07e;
case 0x0c09e080u: goto P_0c09e080;
case 0x0c09e082u: goto P_0c09e082;
case 0x0c09e084u: goto P_0c09e084;
case 0x0c09e086u: goto P_0c09e086;
case 0x0c09e088u: goto P_0c09e088;
case 0x0c09e08au: goto P_0c09e08a;
case 0x0c09e08cu: goto P_0c09e08c;
case 0x0c09e08eu: goto P_0c09e08e;
case 0x0c09e090u: goto P_0c09e090;
case 0x0c09e092u: goto P_0c09e092;
case 0x0c09e094u: goto P_0c09e094;
case 0x0c09e096u: goto P_0c09e096;
case 0x0c09e098u: goto P_0c09e098;
case 0x0c09e09au: goto P_0c09e09a;
case 0x0c09e09cu: goto P_0c09e09c;
case 0x0c09e09eu: goto P_0c09e09e;
case 0x0c09e0a0u: goto P_0c09e0a0;
case 0x0c09e0a2u: goto P_0c09e0a2;
case 0x0c09e0a4u: goto P_0c09e0a4;
case 0x0c09e0a6u: goto P_0c09e0a6;
case 0x0c09e0a8u: goto P_0c09e0a8;
case 0x0c09e0aau: goto P_0c09e0aa;
case 0x0c09e0acu: goto P_0c09e0ac;
case 0x0c09e0aeu: goto P_0c09e0ae;
case 0x0c09e0b0u: goto P_0c09e0b0;
case 0x0c09e0b2u: goto P_0c09e0b2;
case 0x0c09e0b4u: goto P_0c09e0b4;
case 0x0c09e0b6u: goto P_0c09e0b6;
case 0x0c09e0b8u: goto P_0c09e0b8;
case 0x0c09e0bau: goto P_0c09e0ba;
case 0x0c09e0bcu: goto P_0c09e0bc;
case 0x0c09e0beu: goto P_0c09e0be;
case 0x0c09e0c0u: goto P_0c09e0c0;
case 0x0c09e0c2u: goto P_0c09e0c2;
case 0x0c09e0c4u: goto P_0c09e0c4;
case 0x0c09e0c6u: goto P_0c09e0c6;
case 0x0c09e0c8u: goto P_0c09e0c8;
case 0x0c09e0cau: goto P_0c09e0ca;
case 0x0c09e0ccu: goto P_0c09e0cc;
case 0x0c09e0ceu: goto P_0c09e0ce;
case 0x0c09e0d0u: goto P_0c09e0d0;
case 0x0c09e0d2u: goto P_0c09e0d2;
case 0x0c09e0d4u: goto P_0c09e0d4;
case 0x0c09e0d6u: goto P_0c09e0d6;
case 0x0c09e0d8u: goto P_0c09e0d8;
case 0x0c09e0dau: goto P_0c09e0da;
case 0x0c09e0dcu: goto P_0c09e0dc;
case 0x0c09e0deu: goto P_0c09e0de;
case 0x0c09e0e0u: goto P_0c09e0e0;
case 0x0c09e0e2u: goto P_0c09e0e2;
case 0x0c09e0e4u: goto P_0c09e0e4;
case 0x0c09e0e6u: goto P_0c09e0e6;
case 0x0c09e0e8u: goto P_0c09e0e8;
case 0x0c09e0eau: goto P_0c09e0ea;
case 0x0c09e0ecu: goto P_0c09e0ec;
case 0x0c09e0eeu: goto P_0c09e0ee;
case 0x0c09e0f0u: goto P_0c09e0f0;
case 0x0c09e0f2u: goto P_0c09e0f2;
case 0x0c09e0f4u: goto P_0c09e0f4;
case 0x0c09e0f6u: goto P_0c09e0f6;
case 0x0c09e0f8u: goto P_0c09e0f8;
case 0x0c09e0fau: goto P_0c09e0fa;
case 0x0c09e0fcu: goto P_0c09e0fc;
case 0x0c09e0feu: goto P_0c09e0fe;
case 0x0c09e100u: goto P_0c09e100;
case 0x0c09e102u: goto P_0c09e102;
case 0x0c09e104u: goto P_0c09e104;
case 0x0c09e106u: goto P_0c09e106;
case 0x0c09e108u: goto P_0c09e108;
case 0x0c09e10au: goto P_0c09e10a;
case 0x0c09e10cu: goto P_0c09e10c;
case 0x0c09e10eu: goto P_0c09e10e;
case 0x0c09e110u: goto P_0c09e110;
case 0x0c09e112u: goto P_0c09e112;
case 0x0c09e114u: goto P_0c09e114;
case 0x0c09e116u: goto P_0c09e116;
case 0x0c09e118u: goto P_0c09e118;
case 0x0c09e11au: goto P_0c09e11a;
case 0x0c09e11cu: goto P_0c09e11c;
case 0x0c09e11eu: goto P_0c09e11e;
case 0x0c09e120u: goto P_0c09e120;
case 0x0c09e122u: goto P_0c09e122;
case 0x0c09e124u: goto P_0c09e124;
case 0x0c09e126u: goto P_0c09e126;
case 0x0c09e128u: goto P_0c09e128;
case 0x0c09e12au: goto P_0c09e12a;
case 0x0c09e12cu: goto P_0c09e12c;
case 0x0c09e12eu: goto P_0c09e12e;
case 0x0c09e130u: goto P_0c09e130;
case 0x0c09e132u: goto P_0c09e132;
case 0x0c09e134u: goto P_0c09e134;
case 0x0c09e136u: goto P_0c09e136;
case 0x0c09e138u: goto P_0c09e138;
case 0x0c09e13au: goto P_0c09e13a;
case 0x0c09e13cu: goto P_0c09e13c;
case 0x0c09e13eu: goto P_0c09e13e;
case 0x0c09e140u: goto P_0c09e140;
case 0x0c09e142u: goto P_0c09e142;
case 0x0c09e144u: goto P_0c09e144;
case 0x0c09e146u: goto P_0c09e146;
case 0x0c09e148u: goto P_0c09e148;
case 0x0c09e14au: goto P_0c09e14a;
case 0x0c09e14cu: goto P_0c09e14c;
case 0x0c09e14eu: goto P_0c09e14e;
case 0x0c09e150u: goto P_0c09e150;
case 0x0c09e152u: goto P_0c09e152;
case 0x0c09e154u: goto P_0c09e154;
case 0x0c09e156u: goto P_0c09e156;
case 0x0c09e158u: goto P_0c09e158;
case 0x0c09e15au: goto P_0c09e15a;
case 0x0c09e15cu: goto P_0c09e15c;
case 0x0c09e15eu: goto P_0c09e15e;
case 0x0c09e160u: goto P_0c09e160;
case 0x0c09e162u: goto P_0c09e162;
case 0x0c09e164u: goto P_0c09e164;
case 0x0c09e166u: goto P_0c09e166;
case 0x0c09e168u: goto P_0c09e168;
case 0x0c09e16au: goto P_0c09e16a;
case 0x0c09e16cu: goto P_0c09e16c;
case 0x0c09e16eu: goto P_0c09e16e;
case 0x0c09e170u: goto P_0c09e170;
case 0x0c09e172u: goto P_0c09e172;
case 0x0c09e174u: goto P_0c09e174;
case 0x0c09e176u: goto P_0c09e176;
case 0x0c09e178u: goto P_0c09e178;
case 0x0c09e17au: goto P_0c09e17a;
case 0x0c09e17cu: goto P_0c09e17c;
case 0x0c09e17eu: goto P_0c09e17e;
case 0x0c09e180u: goto P_0c09e180;
case 0x0c09e182u: goto P_0c09e182;
case 0x0c09e184u: goto P_0c09e184;
case 0x0c09e186u: goto P_0c09e186;
case 0x0c09e188u: goto P_0c09e188;
case 0x0c09e18au: goto P_0c09e18a;
case 0x0c09e18cu: goto P_0c09e18c;
case 0x0c09e18eu: goto P_0c09e18e;
case 0x0c09e190u: goto P_0c09e190;
case 0x0c09e192u: goto P_0c09e192;
case 0x0c09e194u: goto P_0c09e194;
case 0x0c09e196u: goto P_0c09e196;
case 0x0c09e198u: goto P_0c09e198;
case 0x0c09e19au: goto P_0c09e19a;
case 0x0c09e19cu: goto P_0c09e19c;
case 0x0c09e19eu: goto P_0c09e19e;
case 0x0c09e1a0u: goto P_0c09e1a0;
case 0x0c09e1a2u: goto P_0c09e1a2;
case 0x0c09e1a4u: goto P_0c09e1a4;
case 0x0c09e1a6u: goto P_0c09e1a6;
case 0x0c09e1a8u: goto P_0c09e1a8;
case 0x0c09e1aau: goto P_0c09e1aa;
case 0x0c09e1acu: goto P_0c09e1ac;
case 0x0c09e1aeu: goto P_0c09e1ae;
case 0x0c09e1b0u: goto P_0c09e1b0;
case 0x0c09e1b2u: goto P_0c09e1b2;
case 0x0c09e1b4u: goto P_0c09e1b4;
case 0x0c09e1b6u: goto P_0c09e1b6;
case 0x0c09e1b8u: goto P_0c09e1b8;
case 0x0c09e1bau: goto P_0c09e1ba;
case 0x0c09e1bcu: goto P_0c09e1bc;
case 0x0c09e1beu: goto P_0c09e1be;
case 0x0c09e1c0u: goto P_0c09e1c0;
case 0x0c09e1c2u: goto P_0c09e1c2;
case 0x0c09e1c4u: goto P_0c09e1c4;
case 0x0c09e1c6u: goto P_0c09e1c6;
case 0x0c09e1c8u: goto P_0c09e1c8;
case 0x0c09e1cau: goto P_0c09e1ca;
case 0x0c09e1ccu: goto P_0c09e1cc;
case 0x0c09e1ceu: goto P_0c09e1ce;
case 0x0c09e1d0u: goto P_0c09e1d0;
case 0x0c09e214u: goto P_0c09e214;
case 0x0c09e216u: goto P_0c09e216;
case 0x0c09e218u: goto P_0c09e218;
case 0x0c09e21au: goto P_0c09e21a;
case 0x0c09e21cu: goto P_0c09e21c;
case 0x0c09e21eu: goto P_0c09e21e;
case 0x0c09e220u: goto P_0c09e220;
case 0x0c09e222u: goto P_0c09e222;
case 0x0c09e224u: goto P_0c09e224;
case 0x0c09e226u: goto P_0c09e226;
case 0x0c09e228u: goto P_0c09e228;
case 0x0c09e22au: goto P_0c09e22a;
case 0x0c09e22cu: goto P_0c09e22c;
case 0x0c09e22eu: goto P_0c09e22e;
case 0x0c09e230u: goto P_0c09e230;
case 0x0c09e232u: goto P_0c09e232;
case 0x0c09e234u: goto P_0c09e234;
case 0x0c09e236u: goto P_0c09e236;
case 0x0c09e238u: goto P_0c09e238;
case 0x0c09e23au: goto P_0c09e23a;
case 0x0c09e23cu: goto P_0c09e23c;
case 0x0c09e23eu: goto P_0c09e23e;
case 0x0c09e240u: goto P_0c09e240;
case 0x0c09e242u: goto P_0c09e242;
case 0x0c09e244u: goto P_0c09e244;
case 0x0c09e246u: goto P_0c09e246;
case 0x0c09e248u: goto P_0c09e248;
case 0x0c09e24au: goto P_0c09e24a;
case 0x0c09e24cu: goto P_0c09e24c;
case 0x0c09e24eu: goto P_0c09e24e;
case 0x0c09e250u: goto P_0c09e250;
case 0x0c09e252u: goto P_0c09e252;
case 0x0c09e254u: goto P_0c09e254;
case 0x0c09e256u: goto P_0c09e256;
case 0x0c09e258u: goto P_0c09e258;
case 0x0c09e25au: goto P_0c09e25a;
case 0x0c09e25cu: goto P_0c09e25c;
case 0x0c09e25eu: goto P_0c09e25e;
case 0x0c09e260u: goto P_0c09e260;
case 0x0c09e262u: goto P_0c09e262;
case 0x0c09e264u: goto P_0c09e264;
case 0x0c09e266u: goto P_0c09e266;
case 0x0c09e268u: goto P_0c09e268;
case 0x0c09e26au: goto P_0c09e26a;
case 0x0c09e26cu: goto P_0c09e26c;
case 0x0c09e26eu: goto P_0c09e26e;
case 0x0c09e270u: goto P_0c09e270;
case 0x0c09e272u: goto P_0c09e272;
case 0x0c09e274u: goto P_0c09e274;
case 0x0c09e276u: goto P_0c09e276;
case 0x0c09e278u: goto P_0c09e278;
case 0x0c09e27au: goto P_0c09e27a;
case 0x0c09e27cu: goto P_0c09e27c;
case 0x0c09e27eu: goto P_0c09e27e;
case 0x0c09e280u: goto P_0c09e280;
case 0x0c09e282u: goto P_0c09e282;
case 0x0c09e284u: goto P_0c09e284;
case 0x0c09e286u: goto P_0c09e286;
case 0x0c09e288u: goto P_0c09e288;
case 0x0c09e28au: goto P_0c09e28a;
case 0x0c09e28cu: goto P_0c09e28c;
case 0x0c09e28eu: goto P_0c09e28e;
case 0x0c09e290u: goto P_0c09e290;
case 0x0c09e292u: goto P_0c09e292;
case 0x0c09e294u: goto P_0c09e294;
case 0x0c09e296u: goto P_0c09e296;
case 0x0c09e298u: goto P_0c09e298;
case 0x0c09e29au: goto P_0c09e29a;
case 0x0c09e29cu: goto P_0c09e29c;
case 0x0c09e29eu: goto P_0c09e29e;
case 0x0c09e2a0u: goto P_0c09e2a0;
case 0x0c09e2a2u: goto P_0c09e2a2;
case 0x0c09e2a4u: goto P_0c09e2a4;
case 0x0c09e2a6u: goto P_0c09e2a6;
case 0x0c09e2a8u: goto P_0c09e2a8;
case 0x0c09e2aau: goto P_0c09e2aa;
case 0x0c09e2acu: goto P_0c09e2ac;
case 0x0c09e2aeu: goto P_0c09e2ae;
case 0x0c09e2b0u: goto P_0c09e2b0;
case 0x0c09e2b2u: goto P_0c09e2b2;
case 0x0c09e2b4u: goto P_0c09e2b4;
case 0x0c09e2b6u: goto P_0c09e2b6;
case 0x0c09e2b8u: goto P_0c09e2b8;
case 0x0c09e2bau: goto P_0c09e2ba;
case 0x0c09e2bcu: goto P_0c09e2bc;
case 0x0c09e2beu: goto P_0c09e2be;
case 0x0c09e2c0u: goto P_0c09e2c0;
case 0x0c09e2c2u: goto P_0c09e2c2;
case 0x0c09e2c4u: goto P_0c09e2c4;
case 0x0c09e2c6u: goto P_0c09e2c6;
case 0x0c09e2c8u: goto P_0c09e2c8;
case 0x0c09e2cau: goto P_0c09e2ca;
case 0x0c09e2ccu: goto P_0c09e2cc;
case 0x0c09e2ceu: goto P_0c09e2ce;
case 0x0c09e2d0u: goto P_0c09e2d0;
case 0x0c09e2d2u: goto P_0c09e2d2;
case 0x0c09e2d4u: goto P_0c09e2d4;
case 0x0c09e2d6u: goto P_0c09e2d6;
case 0x0c09e2d8u: goto P_0c09e2d8;
case 0x0c09e2dau: goto P_0c09e2da;
case 0x0c09e2dcu: goto P_0c09e2dc;
case 0x0c09e2f4u: goto P_0c09e2f4;
case 0x0c09e2f6u: goto P_0c09e2f6;
case 0x0c09e2f8u: goto P_0c09e2f8;
case 0x0c09e2fau: goto P_0c09e2fa;
case 0x0c09e2fcu: goto P_0c09e2fc;
case 0x0c09e2feu: goto P_0c09e2fe;
case 0x0c09e300u: goto P_0c09e300;
case 0x0c09e302u: goto P_0c09e302;
case 0x0c09e304u: goto P_0c09e304;
case 0x0c09e306u: goto P_0c09e306;
case 0x0c09e308u: goto P_0c09e308;
case 0x0c09e30au: goto P_0c09e30a;
case 0x0c09e30cu: goto P_0c09e30c;
case 0x0c09e30eu: goto P_0c09e30e;
case 0x0c09e310u: goto P_0c09e310;
case 0x0c09e312u: goto P_0c09e312;
case 0x0c09e314u: goto P_0c09e314;
case 0x0c09e316u: goto P_0c09e316;
case 0x0c09e318u: goto P_0c09e318;
case 0x0c09e31au: goto P_0c09e31a;
case 0x0c09e31cu: goto P_0c09e31c;
case 0x0c09e31eu: goto P_0c09e31e;
case 0x0c09e320u: goto P_0c09e320;
case 0x0c09e322u: goto P_0c09e322;
case 0x0c09e324u: goto P_0c09e324;
case 0x0c09e326u: goto P_0c09e326;
case 0x0c09e328u: goto P_0c09e328;
case 0x0c09e32au: goto P_0c09e32a;
case 0x0c09e32cu: goto P_0c09e32c;
case 0x0c09e32eu: goto P_0c09e32e;
case 0x0c09e330u: goto P_0c09e330;
case 0x0c09e332u: goto P_0c09e332;
case 0x0c09e334u: goto P_0c09e334;
case 0x0c09e336u: goto P_0c09e336;
case 0x0c09e338u: goto P_0c09e338;
case 0x0c09e33au: goto P_0c09e33a;
case 0x0c09e33cu: goto P_0c09e33c;
case 0x0c09e33eu: goto P_0c09e33e;
case 0x0c09e340u: goto P_0c09e340;
case 0x0c09e342u: goto P_0c09e342;
case 0x0c09e344u: goto P_0c09e344;
case 0x0c09e346u: goto P_0c09e346;
case 0x0c09e348u: goto P_0c09e348;
case 0x0c09e34au: goto P_0c09e34a;
case 0x0c09e34cu: goto P_0c09e34c;
case 0x0c09e34eu: goto P_0c09e34e;
case 0x0c09e350u: goto P_0c09e350;
case 0x0c09e352u: goto P_0c09e352;
case 0x0c09e354u: goto P_0c09e354;
case 0x0c09e356u: goto P_0c09e356;
case 0x0c09e358u: goto P_0c09e358;
case 0x0c09e35au: goto P_0c09e35a;
case 0x0c09e35cu: goto P_0c09e35c;
case 0x0c09e35eu: goto P_0c09e35e;
case 0x0c09e360u: goto P_0c09e360;
case 0x0c09e362u: goto P_0c09e362;
case 0x0c09e364u: goto P_0c09e364;
case 0x0c09e366u: goto P_0c09e366;
case 0x0c09e368u: goto P_0c09e368;
case 0x0c09e36au: goto P_0c09e36a;
case 0x0c09e36cu: goto P_0c09e36c;
case 0x0c09e36eu: goto P_0c09e36e;
case 0x0c09e370u: goto P_0c09e370;
case 0x0c09e372u: goto P_0c09e372;
case 0x0c09e374u: goto P_0c09e374;
case 0x0c09e376u: goto P_0c09e376;
case 0x0c09e378u: goto P_0c09e378;
case 0x0c09e37au: goto P_0c09e37a;
case 0x0c09e37cu: goto P_0c09e37c;
case 0x0c09e37eu: goto P_0c09e37e;
case 0x0c09e380u: goto P_0c09e380;
case 0x0c09e382u: goto P_0c09e382;
case 0x0c09e384u: goto P_0c09e384;
case 0x0c09e386u: goto P_0c09e386;
case 0x0c09e388u: goto P_0c09e388;
case 0x0c09e38au: goto P_0c09e38a;
case 0x0c09e38cu: goto P_0c09e38c;
case 0x0c09e38eu: goto P_0c09e38e;
case 0x0c09e390u: goto P_0c09e390;
case 0x0c09e392u: goto P_0c09e392;
case 0x0c09e394u: goto P_0c09e394;
case 0x0c09e396u: goto P_0c09e396;
case 0x0c09e398u: goto P_0c09e398;
case 0x0c09e39au: goto P_0c09e39a;
case 0x0c09e39cu: goto P_0c09e39c;
case 0x0c09e39eu: goto P_0c09e39e;
case 0x0c09e3a0u: goto P_0c09e3a0;
case 0x0c09e3a2u: goto P_0c09e3a2;
case 0x0c09e3a4u: goto P_0c09e3a4;
case 0x0c09e3a6u: goto P_0c09e3a6;
case 0x0c09e3a8u: goto P_0c09e3a8;
case 0x0c09e3aau: goto P_0c09e3aa;
case 0x0c09e3acu: goto P_0c09e3ac;
case 0x0c09e3aeu: goto P_0c09e3ae;
case 0x0c09e3b0u: goto P_0c09e3b0;
case 0x0c09e3b2u: goto P_0c09e3b2;
case 0x0c09e3b4u: goto P_0c09e3b4;
case 0x0c09e3b6u: goto P_0c09e3b6;
case 0x0c09e3b8u: goto P_0c09e3b8;
case 0x0c09e3bau: goto P_0c09e3ba;
case 0x0c09e3bcu: goto P_0c09e3bc;
case 0x0c09e3beu: goto P_0c09e3be;
case 0x0c09e3c0u: goto P_0c09e3c0;
case 0x0c09e3c2u: goto P_0c09e3c2;
case 0x0c09e3c4u: goto P_0c09e3c4;
case 0x0c09e3c6u: goto P_0c09e3c6;
case 0x0c09e3c8u: goto P_0c09e3c8;
case 0x0c09e3cau: goto P_0c09e3ca;
case 0x0c09e3ccu: goto P_0c09e3cc;
case 0x0c09e3ceu: goto P_0c09e3ce;
case 0x0c09e3d0u: goto P_0c09e3d0;
case 0x0c09e3d2u: goto P_0c09e3d2;
case 0x0c09e3d4u: goto P_0c09e3d4;
case 0x0c09e3d6u: goto P_0c09e3d6;
case 0x0c09e3d8u: goto P_0c09e3d8;
case 0x0c09e3dau: goto P_0c09e3da;
case 0x0c09e3dcu: goto P_0c09e3dc;
case 0x0c09e3deu: goto P_0c09e3de;
case 0x0c09e3e0u: goto P_0c09e3e0;
case 0x0c09e3e2u: goto P_0c09e3e2;
case 0x0c09e3e4u: goto P_0c09e3e4;
case 0x0c09e3e6u: goto P_0c09e3e6;
case 0x0c09e3e8u: goto P_0c09e3e8;
case 0x0c09e3eau: goto P_0c09e3ea;
case 0x0c09e3ecu: goto P_0c09e3ec;
case 0x0c09e3eeu: goto P_0c09e3ee;
case 0x0c09e3f0u: goto P_0c09e3f0;
case 0x0c09e3f2u: goto P_0c09e3f2;
case 0x0c09e3f4u: goto P_0c09e3f4;
case 0x0c09e3f6u: goto P_0c09e3f6;
case 0x0c09e3f8u: goto P_0c09e3f8;
case 0x0c09e3fau: goto P_0c09e3fa;
case 0x0c09e3fcu: goto P_0c09e3fc;
case 0x0c09e3feu: goto P_0c09e3fe;
case 0x0c09e400u: goto P_0c09e400;
case 0x0c09e402u: goto P_0c09e402;
case 0x0c09e404u: goto P_0c09e404;
case 0x0c09e406u: goto P_0c09e406;
case 0x0c09e408u: goto P_0c09e408;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09e060: /* original 2fe6, guest PC 0x0c09e060 */
if(!s->budget--) { s->failed_pc=0x0c09e060u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09e062;
P_0c09e062: /* original 2fd6, guest PC 0x0c09e062 */
if(!s->budget--) { s->failed_pc=0x0c09e062u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09e064;
P_0c09e064: /* original 6d43, guest PC 0x0c09e064 */
if(!s->budget--) { s->failed_pc=0x0c09e064u; return 0; }
r[13]=r[4];
goto P_0c09e066;
P_0c09e066: /* original 2fc6, guest PC 0x0c09e066 */
if(!s->budget--) { s->failed_pc=0x0c09e066u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09e068;
P_0c09e068: /* original 2fb6, guest PC 0x0c09e068 */
if(!s->budget--) { s->failed_pc=0x0c09e068u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09e06a;
P_0c09e06a: /* original 6b53, guest PC 0x0c09e06a */
if(!s->budget--) { s->failed_pc=0x0c09e06au; return 0; }
r[11]=r[5];
goto P_0c09e06c;
P_0c09e06c: /* original 2fa6, guest PC 0x0c09e06c */
if(!s->budget--) { s->failed_pc=0x0c09e06cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09e06e;
P_0c09e06e: /* original 2f96, guest PC 0x0c09e06e */
if(!s->budget--) { s->failed_pc=0x0c09e06eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09e070;
P_0c09e070: /* original 2f86, guest PC 0x0c09e070 */
if(!s->budget--) { s->failed_pc=0x0c09e070u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09e072;
P_0c09e072: /* original fffb, guest PC 0x0c09e072 */
if(!s->budget--) { s->failed_pc=0x0c09e072u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09e074;
P_0c09e074: /* original ffeb, guest PC 0x0c09e074 */
if(!s->budget--) { s->failed_pc=0x0c09e074u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c09e076;
P_0c09e076: /* original ffdb, guest PC 0x0c09e076 */
if(!s->budget--) { s->failed_pc=0x0c09e076u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c09e078;
P_0c09e078: /* original 4f22, guest PC 0x0c09e078 */
if(!s->budget--) { s->failed_pc=0x0c09e078u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09e07a;
P_0c09e07a: /* original 90aa, guest PC 0x0c09e07a */
if(!s->budget--) { s->failed_pc=0x0c09e07au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1d2u,2);
goto P_0c09e07c;
P_0c09e07c: /* original 3f0c, guest PC 0x0c09e07c */
if(!s->budget--) { s->failed_pc=0x0c09e07cu; return 0; }
r[15]+=r[0];
goto P_0c09e07e;
P_0c09e07e: /* original 2f62, guest PC 0x0c09e07e */
if(!s->budget--) { s->failed_pc=0x0c09e07eu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c09e080;
P_0c09e080: /* original 1f71, guest PC 0x0c09e080 */
if(!s->budget--) { s->failed_pc=0x0c09e080u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c09e082;
P_0c09e082: /* original 90a7, guest PC 0x0c09e082 */
if(!s->budget--) { s->failed_pc=0x0c09e082u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1d4u,2);
goto P_0c09e084;
P_0c09e084: /* original d85c, guest PC 0x0c09e084 */
if(!s->budget--) { s->failed_pc=0x0c09e084u; return 0; }
r[8]=read(ram,0x0c09e1f8u,4);
goto P_0c09e086;
P_0c09e086: /* original 0afe, guest PC 0x0c09e086 */
if(!s->budget--) { s->failed_pc=0x0c09e086u; return 0; }
r[10]=read(ram,r[15]+r[0],4);
goto P_0c09e088;
P_0c09e088: /* original 480b, guest PC 0x0c09e088 */
if(!s->budget--) { s->failed_pc=0x0c09e088u; return 0; }
target=r[8];
r[16]=code_base|0x0c09e08cu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e08cu) { target=s->pc; goto dispatch; }
goto P_0c09e08c;
P_0c09e08a: /* original e400, guest PC 0x0c09e08a */
if(!s->budget--) { s->failed_pc=0x0c09e08au; return 0; }
r[4]=0x00000000u;
goto P_0c09e08c;
P_0c09e08c: /* original d35b, guest PC 0x0c09e08c */
if(!s->budget--) { s->failed_pc=0x0c09e08cu; return 0; }
r[3]=read(ram,0x0c09e1fcu,4);
goto P_0c09e08e;
P_0c09e08e: /* original 430b, guest PC 0x0c09e08e */
if(!s->budget--) { s->failed_pc=0x0c09e08eu; return 0; }
target=r[3];
r[16]=code_base|0x0c09e092u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e092u) { target=s->pc; goto dispatch; }
goto P_0c09e092;
P_0c09e090: /* original 0009, guest PC 0x0c09e090 */
if(!s->budget--) { s->failed_pc=0x0c09e090u; return 0; }
goto P_0c09e092;
P_0c09e092: /* original 94a0, guest PC 0x0c09e092 */
if(!s->budget--) { s->failed_pc=0x0c09e092u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1d6u,2);
goto P_0c09e094;
P_0c09e094: /* original de5a, guest PC 0x0c09e094 */
if(!s->budget--) { s->failed_pc=0x0c09e094u; return 0; }
r[14]=read(ram,0x0c09e200u,4);
goto P_0c09e096;
P_0c09e096: /* original 4e0b, guest PC 0x0c09e096 */
if(!s->budget--) { s->failed_pc=0x0c09e096u; return 0; }
target=r[14];
r[16]=code_base|0x0c09e09au;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e09au) { target=s->pc; goto dispatch; }
goto P_0c09e09a;
P_0c09e098: /* original 34fc, guest PC 0x0c09e098 */
if(!s->budget--) { s->failed_pc=0x0c09e098u; return 0; }
r[4]+=r[15];
goto P_0c09e09a;
P_0c09e09a: /* original 64f3, guest PC 0x0c09e09a */
if(!s->budget--) { s->failed_pc=0x0c09e09au; return 0; }
r[4]=r[15];
goto P_0c09e09c;
P_0c09e09c: /* original 4e0b, guest PC 0x0c09e09c */
if(!s->budget--) { s->failed_pc=0x0c09e09cu; return 0; }
target=r[14];
r[16]=code_base|0x0c09e0a0u;
r[4]+=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e0a0u) { target=s->pc; goto dispatch; }
goto P_0c09e0a0;
P_0c09e09e: /* original 7450, guest PC 0x0c09e09e */
if(!s->budget--) { s->failed_pc=0x0c09e09eu; return 0; }
r[4]+=0x00000050u;
goto P_0c09e0a0;
P_0c09e0a0: /* original d958, guest PC 0x0c09e0a0 */
if(!s->budget--) { s->failed_pc=0x0c09e0a0u; return 0; }
r[9]=read(ram,0x0c09e204u,4);
goto P_0c09e0a2;
P_0c09e0a2: /* original 490b, guest PC 0x0c09e0a2 */
if(!s->budget--) { s->failed_pc=0x0c09e0a2u; return 0; }
target=r[9];
r[16]=code_base|0x0c09e0a6u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e0a6u) { target=s->pc; goto dispatch; }
goto P_0c09e0a6;
P_0c09e0a4: /* original e401, guest PC 0x0c09e0a4 */
if(!s->budget--) { s->failed_pc=0x0c09e0a4u; return 0; }
r[4]=0x00000001u;
goto P_0c09e0a6;
P_0c09e0a6: /* original e008, guest PC 0x0c09e0a6 */
if(!s->budget--) { s->failed_pc=0x0c09e0a6u; return 0; }
r[0]=0x00000008u;
goto P_0c09e0a8;
P_0c09e0a8: /* original f4d8, guest PC 0x0c09e0a8 */
if(!s->budget--) { s->failed_pc=0x0c09e0a8u; return 0; }
vf3_matrix_load(s,ram,4,r[13]);
goto P_0c09e0aa;
P_0c09e0aa: /* original f5d6, guest PC 0x0c09e0aa */
if(!s->budget--) { s->failed_pc=0x0c09e0aau; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c09e0ac;
P_0c09e0ac: /* original 9494, guest PC 0x0c09e0ac */
if(!s->budget--) { s->failed_pc=0x0c09e0acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1d8u,2);
goto P_0c09e0ae;
P_0c09e0ae: /* original f54d, guest PC 0x0c09e0ae */
if(!s->budget--) { s->failed_pc=0x0c09e0aeu; return 0; }
fr[5]^=0x80000000u;
goto P_0c09e0b0;
P_0c09e0b0: /* original b9bc, guest PC 0x0c09e0b0 */
if(!s->budget--) { s->failed_pc=0x0c09e0b0u; return 0; }
target=code_base|0x0c09d42cu; r[16]=code_base|0x0c09e0b4u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e0b4u) { target=s->pc; goto dispatch; }
goto P_0c09e0b4;
P_0c09e0b2: /* original 34fc, guest PC 0x0c09e0b2 */
if(!s->budget--) { s->failed_pc=0x0c09e0b2u; return 0; }
r[4]+=r[15];
goto P_0c09e0b4;
P_0c09e0b4: /* original 9491, guest PC 0x0c09e0b4 */
if(!s->budget--) { s->failed_pc=0x0c09e0b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1dau,2);
goto P_0c09e0b6;
P_0c09e0b6: /* original 4e0b, guest PC 0x0c09e0b6 */
if(!s->budget--) { s->failed_pc=0x0c09e0b6u; return 0; }
target=r[14];
r[16]=code_base|0x0c09e0bau;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e0bau) { target=s->pc; goto dispatch; }
goto P_0c09e0ba;
P_0c09e0b8: /* original 34fc, guest PC 0x0c09e0b8 */
if(!s->budget--) { s->failed_pc=0x0c09e0b8u; return 0; }
r[4]+=r[15];
goto P_0c09e0ba;
P_0c09e0ba: /* original 908d, guest PC 0x0c09e0ba */
if(!s->budget--) { s->failed_pc=0x0c09e0bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1d8u,2);
goto P_0c09e0bc;
P_0c09e0bc: /* original f3f6, guest PC 0x0c09e0bc */
if(!s->budget--) { s->failed_pc=0x0c09e0bcu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e0be;
P_0c09e0be: /* original 908d, guest PC 0x0c09e0be */
if(!s->budget--) { s->failed_pc=0x0c09e0beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1dcu,2);
goto P_0c09e0c0;
P_0c09e0c0: /* original ff37, guest PC 0x0c09e0c0 */
if(!s->budget--) { s->failed_pc=0x0c09e0c0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e0c2;
P_0c09e0c2: /* original 908c, guest PC 0x0c09e0c2 */
if(!s->budget--) { s->failed_pc=0x0c09e0c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1deu,2);
goto P_0c09e0c4;
P_0c09e0c4: /* original f3f6, guest PC 0x0c09e0c4 */
if(!s->budget--) { s->failed_pc=0x0c09e0c4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e0c6;
P_0c09e0c6: /* original 908b, guest PC 0x0c09e0c6 */
if(!s->budget--) { s->failed_pc=0x0c09e0c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1e0u,2);
goto P_0c09e0c8;
P_0c09e0c8: /* original ff37, guest PC 0x0c09e0c8 */
if(!s->budget--) { s->failed_pc=0x0c09e0c8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e0ca;
P_0c09e0ca: /* original 908a, guest PC 0x0c09e0ca */
if(!s->budget--) { s->failed_pc=0x0c09e0cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1e2u,2);
goto P_0c09e0cc;
P_0c09e0cc: /* original f3f6, guest PC 0x0c09e0cc */
if(!s->budget--) { s->failed_pc=0x0c09e0ccu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e0ce;
P_0c09e0ce: /* original 9089, guest PC 0x0c09e0ce */
if(!s->budget--) { s->failed_pc=0x0c09e0ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1e4u,2);
goto P_0c09e0d0;
P_0c09e0d0: /* original ff37, guest PC 0x0c09e0d0 */
if(!s->budget--) { s->failed_pc=0x0c09e0d0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e0d2;
P_0c09e0d2: /* original e004, guest PC 0x0c09e0d2 */
if(!s->budget--) { s->failed_pc=0x0c09e0d2u; return 0; }
r[0]=0x00000004u;
goto P_0c09e0d4;
P_0c09e0d4: /* original 63f2, guest PC 0x0c09e0d4 */
if(!s->budget--) { s->failed_pc=0x0c09e0d4u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09e0d6;
P_0c09e0d6: /* original d24c, guest PC 0x0c09e0d6 */
if(!s->budget--) { s->failed_pc=0x0c09e0d6u; return 0; }
r[2]=read(ram,0x0c09e208u,4);
goto P_0c09e0d8;
P_0c09e0d8: /* original f636, guest PC 0x0c09e0d8 */
if(!s->budget--) { s->failed_pc=0x0c09e0d8u; return 0; }
vf3_matrix_load(s,ram,6,r[3]+r[0]);
goto P_0c09e0da;
P_0c09e0da: /* original ff8d, guest PC 0x0c09e0da */
if(!s->budget--) { s->failed_pc=0x0c09e0dau; return 0; }
fr[15]=0;
goto P_0c09e0dc;
P_0c09e0dc: /* original f5fc, guest PC 0x0c09e0dc */
if(!s->budget--) { s->failed_pc=0x0c09e0dcu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09e0de;
P_0c09e0de: /* original 420b, guest PC 0x0c09e0de */
if(!s->budget--) { s->failed_pc=0x0c09e0deu; return 0; }
target=r[2];
r[16]=code_base|0x0c09e0e2u;
vf3_matrix_load(s,ram,4,r[3]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e0e2u) { target=s->pc; goto dispatch; }
goto P_0c09e0e2;
P_0c09e0e0: /* original f438, guest PC 0x0c09e0e0 */
if(!s->budget--) { s->failed_pc=0x0c09e0e0u; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c09e0e2;
P_0c09e0e2: /* original 9080, guest PC 0x0c09e0e2 */
if(!s->budget--) { s->failed_pc=0x0c09e0e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1e6u,2);
goto P_0c09e0e4;
P_0c09e0e4: /* original b9cc, guest PC 0x0c09e0e4 */
if(!s->budget--) { s->failed_pc=0x0c09e0e4u; return 0; }
target=code_base|0x0c09d480u; r[16]=code_base|0x0c09e0e8u;
r[4]=read(ram,r[15]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e0e8u) { target=s->pc; goto dispatch; }
goto P_0c09e0e8;
P_0c09e0e6: /* original 04fe, guest PC 0x0c09e0e6 */
if(!s->budget--) { s->failed_pc=0x0c09e0e6u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c09e0e8;
P_0c09e0e8: /* original 9477, guest PC 0x0c09e0e8 */
if(!s->budget--) { s->failed_pc=0x0c09e0e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1dau,2);
goto P_0c09e0ea;
P_0c09e0ea: /* original b9fc, guest PC 0x0c09e0ea */
if(!s->budget--) { s->failed_pc=0x0c09e0eau; return 0; }
target=code_base|0x0c09d4e6u; r[16]=code_base|0x0c09e0eeu;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e0eeu) { target=s->pc; goto dispatch; }
goto P_0c09e0ee;
P_0c09e0ec: /* original 34fc, guest PC 0x0c09e0ec */
if(!s->budget--) { s->failed_pc=0x0c09e0ecu; return 0; }
r[4]+=r[15];
goto P_0c09e0ee;
P_0c09e0ee: /* original 9574, guest PC 0x0c09e0ee */
if(!s->budget--) { s->failed_pc=0x0c09e0eeu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1dau,2);
goto P_0c09e0f0;
P_0c09e0f0: /* original d346, guest PC 0x0c09e0f0 */
if(!s->budget--) { s->failed_pc=0x0c09e0f0u; return 0; }
r[3]=read(ram,0x0c09e20cu,4);
goto P_0c09e0f2;
P_0c09e0f2: /* original 35fc, guest PC 0x0c09e0f2 */
if(!s->budget--) { s->failed_pc=0x0c09e0f2u; return 0; }
r[5]+=r[15];
goto P_0c09e0f4;
P_0c09e0f4: /* original 430b, guest PC 0x0c09e0f4 */
if(!s->budget--) { s->failed_pc=0x0c09e0f4u; return 0; }
target=r[3];
r[16]=code_base|0x0c09e0f8u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e0f8u) { target=s->pc; goto dispatch; }
goto P_0c09e0f8;
P_0c09e0f6: /* original 64b3, guest PC 0x0c09e0f6 */
if(!s->budget--) { s->failed_pc=0x0c09e0f6u; return 0; }
r[4]=r[11];
goto P_0c09e0f8;
P_0c09e0f8: /* original 946d, guest PC 0x0c09e0f8 */
if(!s->budget--) { s->failed_pc=0x0c09e0f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1d6u,2);
goto P_0c09e0fa;
P_0c09e0fa: /* original b9f4, guest PC 0x0c09e0fa */
if(!s->budget--) { s->failed_pc=0x0c09e0fau; return 0; }
target=code_base|0x0c09d4e6u; r[16]=code_base|0x0c09e0feu;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e0feu) { target=s->pc; goto dispatch; }
goto P_0c09e0fe;
P_0c09e0fc: /* original 34fc, guest PC 0x0c09e0fc */
if(!s->budget--) { s->failed_pc=0x0c09e0fcu; return 0; }
r[4]+=r[15];
goto P_0c09e0fe;
P_0c09e0fe: /* original 906d, guest PC 0x0c09e0fe */
if(!s->budget--) { s->failed_pc=0x0c09e0feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1dcu,2);
goto P_0c09e100;
P_0c09e100: /* original 64f3, guest PC 0x0c09e100 */
if(!s->budget--) { s->failed_pc=0x0c09e100u; return 0; }
r[4]=r[15];
goto P_0c09e102;
P_0c09e102: /* original f3f6, guest PC 0x0c09e102 */
if(!s->budget--) { s->failed_pc=0x0c09e102u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e104;
P_0c09e104: /* original 9070, guest PC 0x0c09e104 */
if(!s->budget--) { s->failed_pc=0x0c09e104u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1e8u,2);
goto P_0c09e106;
P_0c09e106: /* original ff37, guest PC 0x0c09e106 */
if(!s->budget--) { s->failed_pc=0x0c09e106u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e108;
P_0c09e108: /* original 906a, guest PC 0x0c09e108 */
if(!s->budget--) { s->failed_pc=0x0c09e108u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1e0u,2);
goto P_0c09e10a;
P_0c09e10a: /* original f3f6, guest PC 0x0c09e10a */
if(!s->budget--) { s->failed_pc=0x0c09e10au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e10c;
P_0c09e10c: /* original 906d, guest PC 0x0c09e10c */
if(!s->budget--) { s->failed_pc=0x0c09e10cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1eau,2);
goto P_0c09e10e;
P_0c09e10e: /* original ff37, guest PC 0x0c09e10e */
if(!s->budget--) { s->failed_pc=0x0c09e10eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e110;
P_0c09e110: /* original 9068, guest PC 0x0c09e110 */
if(!s->budget--) { s->failed_pc=0x0c09e110u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1e4u,2);
goto P_0c09e112;
P_0c09e112: /* original f3f6, guest PC 0x0c09e112 */
if(!s->budget--) { s->failed_pc=0x0c09e112u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e114;
P_0c09e114: /* original 906a, guest PC 0x0c09e114 */
if(!s->budget--) { s->failed_pc=0x0c09e114u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1ecu,2);
goto P_0c09e116;
P_0c09e116: /* original ff37, guest PC 0x0c09e116 */
if(!s->budget--) { s->failed_pc=0x0c09e116u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e118;
P_0c09e118: /* original 4e0b, guest PC 0x0c09e118 */
if(!s->budget--) { s->failed_pc=0x0c09e118u; return 0; }
target=r[14];
r[16]=code_base|0x0c09e11cu;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e11cu) { target=s->pc; goto dispatch; }
goto P_0c09e11c;
P_0c09e11a: /* original 7410, guest PC 0x0c09e11a */
if(!s->budget--) { s->failed_pc=0x0c09e11au; return 0; }
r[4]+=0x00000010u;
goto P_0c09e11c;
P_0c09e11c: /* original 480b, guest PC 0x0c09e11c */
if(!s->budget--) { s->failed_pc=0x0c09e11cu; return 0; }
target=r[8];
r[16]=code_base|0x0c09e120u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e120u) { target=s->pc; goto dispatch; }
goto P_0c09e120;
P_0c09e11e: /* original e400, guest PC 0x0c09e11e */
if(!s->budget--) { s->failed_pc=0x0c09e11eu; return 0; }
r[4]=0x00000000u;
goto P_0c09e120;
P_0c09e120: /* original 9459, guest PC 0x0c09e120 */
if(!s->budget--) { s->failed_pc=0x0c09e120u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1d6u,2);
goto P_0c09e122;
P_0c09e122: /* original dc3b, guest PC 0x0c09e122 */
if(!s->budget--) { s->failed_pc=0x0c09e122u; return 0; }
r[12]=read(ram,0x0c09e210u,4);
goto P_0c09e124;
P_0c09e124: /* original 4c0b, guest PC 0x0c09e124 */
if(!s->budget--) { s->failed_pc=0x0c09e124u; return 0; }
target=r[12];
r[16]=code_base|0x0c09e128u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e128u) { target=s->pc; goto dispatch; }
goto P_0c09e128;
P_0c09e126: /* original 34fc, guest PC 0x0c09e126 */
if(!s->budget--) { s->failed_pc=0x0c09e126u; return 0; }
r[4]+=r[15];
goto P_0c09e128;
P_0c09e128: /* original e014, guest PC 0x0c09e128 */
if(!s->budget--) { s->failed_pc=0x0c09e128u; return 0; }
r[0]=0x00000014u;
goto P_0c09e12a;
P_0c09e12a: /* original d337, guest PC 0x0c09e12a */
if(!s->budget--) { s->failed_pc=0x0c09e12au; return 0; }
r[3]=read(ram,0x0c09e208u,4);
goto P_0c09e12c;
P_0c09e12c: /* original f6d6, guest PC 0x0c09e12c */
if(!s->budget--) { s->failed_pc=0x0c09e12cu; return 0; }
vf3_matrix_load(s,ram,6,r[13]+r[0]);
goto P_0c09e12e;
P_0c09e12e: /* original e00c, guest PC 0x0c09e12e */
if(!s->budget--) { s->failed_pc=0x0c09e12eu; return 0; }
r[0]=0x0000000cu;
goto P_0c09e130;
P_0c09e130: /* original f5fc, guest PC 0x0c09e130 */
if(!s->budget--) { s->failed_pc=0x0c09e130u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09e132;
P_0c09e132: /* original f64d, guest PC 0x0c09e132 */
if(!s->budget--) { s->failed_pc=0x0c09e132u; return 0; }
fr[6]^=0x80000000u;
goto P_0c09e134;
P_0c09e134: /* original 430b, guest PC 0x0c09e134 */
if(!s->budget--) { s->failed_pc=0x0c09e134u; return 0; }
target=r[3];
r[16]=code_base|0x0c09e138u;
vf3_matrix_load(s,ram,4,r[13]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e138u) { target=s->pc; goto dispatch; }
goto P_0c09e138;
P_0c09e136: /* original f4d6, guest PC 0x0c09e136 */
if(!s->budget--) { s->failed_pc=0x0c09e136u; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c09e138;
P_0c09e138: /* original 944f, guest PC 0x0c09e138 */
if(!s->budget--) { s->failed_pc=0x0c09e138u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1dau,2);
goto P_0c09e13a;
P_0c09e13a: /* original 4e0b, guest PC 0x0c09e13a */
if(!s->budget--) { s->failed_pc=0x0c09e13au; return 0; }
target=r[14];
r[16]=code_base|0x0c09e13eu;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e13eu) { target=s->pc; goto dispatch; }
goto P_0c09e13e;
P_0c09e13c: /* original 34fc, guest PC 0x0c09e13c */
if(!s->budget--) { s->failed_pc=0x0c09e13cu; return 0; }
r[4]+=r[15];
goto P_0c09e13e;
P_0c09e13e: /* original 490b, guest PC 0x0c09e13e */
if(!s->budget--) { s->failed_pc=0x0c09e13eu; return 0; }
target=r[9];
r[16]=code_base|0x0c09e142u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e142u) { target=s->pc; goto dispatch; }
goto P_0c09e142;
P_0c09e140: /* original e401, guest PC 0x0c09e140 */
if(!s->budget--) { s->failed_pc=0x0c09e140u; return 0; }
r[4]=0x00000001u;
goto P_0c09e142;
P_0c09e142: /* original 62f2, guest PC 0x0c09e142 */
if(!s->budget--) { s->failed_pc=0x0c09e142u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09e144;
P_0c09e144: /* original e008, guest PC 0x0c09e144 */
if(!s->budget--) { s->failed_pc=0x0c09e144u; return 0; }
r[0]=0x00000008u;
goto P_0c09e146;
P_0c09e146: /* original 64f3, guest PC 0x0c09e146 */
if(!s->budget--) { s->failed_pc=0x0c09e146u; return 0; }
r[4]=r[15];
goto P_0c09e148;
P_0c09e148: /* original f426, guest PC 0x0c09e148 */
if(!s->budget--) { s->failed_pc=0x0c09e148u; return 0; }
vf3_matrix_load(s,ram,4,r[2]+r[0]);
goto P_0c09e14a;
P_0c09e14a: /* original e040, guest PC 0x0c09e14a */
if(!s->budget--) { s->failed_pc=0x0c09e14au; return 0; }
r[0]=0x00000040u;
goto P_0c09e14c;
P_0c09e14c: /* original f3f6, guest PC 0x0c09e14c */
if(!s->budget--) { s->failed_pc=0x0c09e14cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e14e;
P_0c09e14e: /* original e030, guest PC 0x0c09e14e */
if(!s->budget--) { s->failed_pc=0x0c09e14eu; return 0; }
r[0]=0x00000030u;
goto P_0c09e150;
P_0c09e150: /* original f2f6, guest PC 0x0c09e150 */
if(!s->budget--) { s->failed_pc=0x0c09e150u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09e152;
P_0c09e152: /* original e040, guest PC 0x0c09e152 */
if(!s->budget--) { s->failed_pc=0x0c09e152u; return 0; }
r[0]=0x00000040u;
goto P_0c09e154;
P_0c09e154: /* original f04c, guest PC 0x0c09e154 */
if(!s->budget--) { s->failed_pc=0x0c09e154u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c09e156;
P_0c09e156: /* original f32e, guest PC 0x0c09e156 */
if(!s->budget--) { s->failed_pc=0x0c09e156u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09e158;
P_0c09e158: /* original ff37, guest PC 0x0c09e158 */
if(!s->budget--) { s->failed_pc=0x0c09e158u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e15a;
P_0c09e15a: /* original e044, guest PC 0x0c09e15a */
if(!s->budget--) { s->failed_pc=0x0c09e15au; return 0; }
r[0]=0x00000044u;
goto P_0c09e15c;
P_0c09e15c: /* original f3f6, guest PC 0x0c09e15c */
if(!s->budget--) { s->failed_pc=0x0c09e15cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e15e;
P_0c09e15e: /* original e034, guest PC 0x0c09e15e */
if(!s->budget--) { s->failed_pc=0x0c09e15eu; return 0; }
r[0]=0x00000034u;
goto P_0c09e160;
P_0c09e160: /* original f2f6, guest PC 0x0c09e160 */
if(!s->budget--) { s->failed_pc=0x0c09e160u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09e162;
P_0c09e162: /* original e044, guest PC 0x0c09e162 */
if(!s->budget--) { s->failed_pc=0x0c09e162u; return 0; }
r[0]=0x00000044u;
goto P_0c09e164;
P_0c09e164: /* original f32e, guest PC 0x0c09e164 */
if(!s->budget--) { s->failed_pc=0x0c09e164u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09e166;
P_0c09e166: /* original ff37, guest PC 0x0c09e166 */
if(!s->budget--) { s->failed_pc=0x0c09e166u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e168;
P_0c09e168: /* original e048, guest PC 0x0c09e168 */
if(!s->budget--) { s->failed_pc=0x0c09e168u; return 0; }
r[0]=0x00000048u;
goto P_0c09e16a;
P_0c09e16a: /* original f3f6, guest PC 0x0c09e16a */
if(!s->budget--) { s->failed_pc=0x0c09e16au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e16c;
P_0c09e16c: /* original e038, guest PC 0x0c09e16c */
if(!s->budget--) { s->failed_pc=0x0c09e16cu; return 0; }
r[0]=0x00000038u;
goto P_0c09e16e;
P_0c09e16e: /* original f2f6, guest PC 0x0c09e16e */
if(!s->budget--) { s->failed_pc=0x0c09e16eu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09e170;
P_0c09e170: /* original e048, guest PC 0x0c09e170 */
if(!s->budget--) { s->failed_pc=0x0c09e170u; return 0; }
r[0]=0x00000048u;
goto P_0c09e172;
P_0c09e172: /* original f32e, guest PC 0x0c09e172 */
if(!s->budget--) { s->failed_pc=0x0c09e172u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09e174;
P_0c09e174: /* original ff37, guest PC 0x0c09e174 */
if(!s->budget--) { s->failed_pc=0x0c09e174u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e176;
P_0c09e176: /* original 4c0b, guest PC 0x0c09e176 */
if(!s->budget--) { s->failed_pc=0x0c09e176u; return 0; }
target=r[12];
r[16]=code_base|0x0c09e17au;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e17au) { target=s->pc; goto dispatch; }
goto P_0c09e17a;
P_0c09e178: /* original 7410, guest PC 0x0c09e178 */
if(!s->budget--) { s->failed_pc=0x0c09e178u; return 0; }
r[4]+=0x00000010u;
goto P_0c09e17a;
P_0c09e17a: /* original 9034, guest PC 0x0c09e17a */
if(!s->budget--) { s->failed_pc=0x0c09e17au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1e6u,2);
goto P_0c09e17c;
P_0c09e17c: /* original 04fe, guest PC 0x0c09e17c */
if(!s->budget--) { s->failed_pc=0x0c09e17cu; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c09e17e;
P_0c09e17e: /* original b97f, guest PC 0x0c09e17e */
if(!s->budget--) { s->failed_pc=0x0c09e17eu; return 0; }
target=code_base|0x0c09d480u; r[16]=code_base|0x0c09e182u;
r[4]+=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e182u) { target=s->pc; goto dispatch; }
goto P_0c09e182;
P_0c09e180: /* original 7406, guest PC 0x0c09e180 */
if(!s->budget--) { s->failed_pc=0x0c09e180u; return 0; }
r[4]+=0x00000006u;
goto P_0c09e182;
P_0c09e182: /* original 9034, guest PC 0x0c09e182 */
if(!s->budget--) { s->failed_pc=0x0c09e182u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1eeu,2);
goto P_0c09e184;
P_0c09e184: /* original 65f3, guest PC 0x0c09e184 */
if(!s->budget--) { s->failed_pc=0x0c09e184u; return 0; }
r[5]=r[15];
goto P_0c09e186;
P_0c09e186: /* original 52f1, guest PC 0x0c09e186 */
if(!s->budget--) { s->failed_pc=0x0c09e186u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c09e188;
P_0c09e188: /* original 66f3, guest PC 0x0c09e188 */
if(!s->budget--) { s->failed_pc=0x0c09e188u; return 0; }
r[6]=r[15];
goto P_0c09e18a;
P_0c09e18a: /* original 03fe, guest PC 0x0c09e18a */
if(!s->budget--) { s->failed_pc=0x0c09e18au; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c09e18c;
P_0c09e18c: /* original 7508, guest PC 0x0c09e18c */
if(!s->budget--) { s->failed_pc=0x0c09e18cu; return 0; }
r[5]+=0x00000008u;
goto P_0c09e18e;
P_0c09e18e: /* original f228, guest PC 0x0c09e18e */
if(!s->budget--) { s->failed_pc=0x0c09e18eu; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
goto P_0c09e190;
P_0c09e190: /* original 760c, guest PC 0x0c09e190 */
if(!s->budget--) { s->failed_pc=0x0c09e190u; return 0; }
r[6]+=0x0000000cu;
goto P_0c09e192;
P_0c09e192: /* original f338, guest PC 0x0c09e192 */
if(!s->budget--) { s->failed_pc=0x0c09e192u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c09e194;
P_0c09e194: /* original 902c, guest PC 0x0c09e194 */
if(!s->budget--) { s->failed_pc=0x0c09e194u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1f0u,2);
goto P_0c09e196;
P_0c09e196: /* original f230, guest PC 0x0c09e196 */
if(!s->budget--) { s->failed_pc=0x0c09e196u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c09e198;
P_0c09e198: /* original ff27, guest PC 0x0c09e198 */
if(!s->budget--) { s->failed_pc=0x0c09e198u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c09e19a;
P_0c09e19a: /* original 9028, guest PC 0x0c09e19a */
if(!s->budget--) { s->failed_pc=0x0c09e19au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1eeu,2);
goto P_0c09e19c;
P_0c09e19c: /* original 53f1, guest PC 0x0c09e19c */
if(!s->budget--) { s->failed_pc=0x0c09e19cu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09e19e;
P_0c09e19e: /* original 02fe, guest PC 0x0c09e19e */
if(!s->budget--) { s->failed_pc=0x0c09e19eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c09e1a0;
P_0c09e1a0: /* original e004, guest PC 0x0c09e1a0 */
if(!s->budget--) { s->failed_pc=0x0c09e1a0u; return 0; }
r[0]=0x00000004u;
goto P_0c09e1a2;
P_0c09e1a2: /* original f236, guest PC 0x0c09e1a2 */
if(!s->budget--) { s->failed_pc=0x0c09e1a2u; return 0; }
vf3_matrix_load(s,ram,2,r[3]+r[0]);
goto P_0c09e1a4;
P_0c09e1a4: /* original f326, guest PC 0x0c09e1a4 */
if(!s->budget--) { s->failed_pc=0x0c09e1a4u; return 0; }
vf3_matrix_load(s,ram,3,r[2]+r[0]);
goto P_0c09e1a6;
P_0c09e1a6: /* original 9024, guest PC 0x0c09e1a6 */
if(!s->budget--) { s->failed_pc=0x0c09e1a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1f2u,2);
goto P_0c09e1a8;
P_0c09e1a8: /* original f230, guest PC 0x0c09e1a8 */
if(!s->budget--) { s->failed_pc=0x0c09e1a8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c09e1aa;
P_0c09e1aa: /* original ff27, guest PC 0x0c09e1aa */
if(!s->budget--) { s->failed_pc=0x0c09e1aau; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c09e1ac;
P_0c09e1ac: /* original 901f, guest PC 0x0c09e1ac */
if(!s->budget--) { s->failed_pc=0x0c09e1acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1eeu,2);
goto P_0c09e1ae;
P_0c09e1ae: /* original 53f1, guest PC 0x0c09e1ae */
if(!s->budget--) { s->failed_pc=0x0c09e1aeu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09e1b0;
P_0c09e1b0: /* original 02fe, guest PC 0x0c09e1b0 */
if(!s->budget--) { s->failed_pc=0x0c09e1b0u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c09e1b2;
P_0c09e1b2: /* original e008, guest PC 0x0c09e1b2 */
if(!s->budget--) { s->failed_pc=0x0c09e1b2u; return 0; }
r[0]=0x00000008u;
goto P_0c09e1b4;
P_0c09e1b4: /* original f236, guest PC 0x0c09e1b4 */
if(!s->budget--) { s->failed_pc=0x0c09e1b4u; return 0; }
vf3_matrix_load(s,ram,2,r[3]+r[0]);
goto P_0c09e1b6;
P_0c09e1b6: /* original f326, guest PC 0x0c09e1b6 */
if(!s->budget--) { s->failed_pc=0x0c09e1b6u; return 0; }
vf3_matrix_load(s,ram,3,r[2]+r[0]);
goto P_0c09e1b8;
P_0c09e1b8: /* original 901c, guest PC 0x0c09e1b8 */
if(!s->budget--) { s->failed_pc=0x0c09e1b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1f4u,2);
goto P_0c09e1ba;
P_0c09e1ba: /* original f230, guest PC 0x0c09e1ba */
if(!s->budget--) { s->failed_pc=0x0c09e1bau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c09e1bc;
P_0c09e1bc: /* original ff27, guest PC 0x0c09e1bc */
if(!s->budget--) { s->failed_pc=0x0c09e1bcu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c09e1be;
P_0c09e1be: /* original 9417, guest PC 0x0c09e1be */
if(!s->budget--) { s->failed_pc=0x0c09e1beu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1f0u,2);
goto P_0c09e1c0;
P_0c09e1c0: /* original bd38, guest PC 0x0c09e1c0 */
if(!s->budget--) { s->failed_pc=0x0c09e1c0u; return 0; }
target=code_base|0x0c09dc34u; r[16]=code_base|0x0c09e1c4u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e1c4u) { target=s->pc; goto dispatch; }
goto P_0c09e1c4;
P_0c09e1c2: /* original 34fc, guest PC 0x0c09e1c2 */
if(!s->budget--) { s->failed_pc=0x0c09e1c2u; return 0; }
r[4]+=r[15];
goto P_0c09e1c4;
P_0c09e1c4: /* original 9210, guest PC 0x0c09e1c4 */
if(!s->budget--) { s->failed_pc=0x0c09e1c4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e1e8u,2);
goto P_0c09e1c6;
P_0c09e1c6: /* original 64b3, guest PC 0x0c09e1c6 */
if(!s->budget--) { s->failed_pc=0x0c09e1c6u; return 0; }
r[4]=r[11];
goto P_0c09e1c8;
P_0c09e1c8: /* original b98d, guest PC 0x0c09e1c8 */
if(!s->budget--) { s->failed_pc=0x0c09e1c8u; return 0; }
target=code_base|0x0c09d4e6u; r[16]=code_base|0x0c09e1ccu;
r[4]+=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e1ccu) { target=s->pc; goto dispatch; }
goto P_0c09e1cc;
P_0c09e1ca: /* original 342c, guest PC 0x0c09e1ca */
if(!s->budget--) { s->failed_pc=0x0c09e1cau; return 0; }
r[4]+=r[2];
goto P_0c09e1cc;
P_0c09e1cc: /* original 62f2, guest PC 0x0c09e1cc */
if(!s->budget--) { s->failed_pc=0x0c09e1ccu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09e1ce;
P_0c09e1ce: /* original a021, guest PC 0x0c09e1ce */
if(!s->budget--) { s->failed_pc=0x0c09e1ceu; return 0; }
goto P_0c09e214;
P_0c09e1d0: /* original 0009, guest PC 0x0c09e1d0 */
if(!s->budget--) { s->failed_pc=0x0c09e1d0u; return 0; }
if(!vf3_matrix_family(0x0c09e1d2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09e1d2u; return 0; } return 1;
P_0c09e214: /* original e00c, guest PC 0x0c09e214 */
if(!s->budget--) { s->failed_pc=0x0c09e214u; return 0; }
r[0]=0x0000000cu;
goto P_0c09e216;
P_0c09e216: /* original f626, guest PC 0x0c09e216 */
if(!s->budget--) { s->failed_pc=0x0c09e216u; return 0; }
vf3_matrix_load(s,ram,6,r[2]+r[0]);
goto P_0c09e218;
P_0c09e218: /* original e010, guest PC 0x0c09e218 */
if(!s->budget--) { s->failed_pc=0x0c09e218u; return 0; }
r[0]=0x00000010u;
goto P_0c09e21a;
P_0c09e21a: /* original f426, guest PC 0x0c09e21a */
if(!s->budget--) { s->failed_pc=0x0c09e21au; return 0; }
vf3_matrix_load(s,ram,4,r[2]+r[0]);
goto P_0c09e21c;
P_0c09e21c: /* original e008, guest PC 0x0c09e21c */
if(!s->budget--) { s->failed_pc=0x0c09e21cu; return 0; }
r[0]=0x00000008u;
goto P_0c09e21e;
P_0c09e21e: /* original f5f6, guest PC 0x0c09e21e */
if(!s->budget--) { s->failed_pc=0x0c09e21eu; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c09e220;
P_0c09e220: /* original f74c, guest PC 0x0c09e220 */
if(!s->budget--) { s->failed_pc=0x0c09e220u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c09e222;
P_0c09e222: /* original f760, guest PC 0x0c09e222 */
if(!s->budget--) { s->failed_pc=0x0c09e222u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'+');
goto P_0c09e224;
P_0c09e224: /* original f755, guest PC 0x0c09e224 */
if(!s->budget--) { s->failed_pc=0x0c09e224u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[5]))!=0);
goto P_0c09e226;
P_0c09e226: /* original 8f65, guest PC 0x0c09e226 */
if(!s->budget--) { s->failed_pc=0x0c09e226u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,14,15);
if(!cond) { goto P_0c09e2f4; }
goto P_0c09e22a;
P_0c09e228: /* original fefc, guest PC 0x0c09e228 */
if(!s->budget--) { s->failed_pc=0x0c09e228u; return 0; }
vf3_matrix_move(s,14,15);
goto P_0c09e22a;
P_0c09e22a: /* original fa5c, guest PC 0x0c09e22a */
if(!s->budget--) { s->failed_pc=0x0c09e22au; return 0; }
vf3_matrix_move(s,10,5);
goto P_0c09e22c;
P_0c09e22c: /* original fa52, guest PC 0x0c09e22c */
if(!s->budget--) { s->failed_pc=0x0c09e22cu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[5],r[18],'*');
goto P_0c09e22e;
P_0c09e22e: /* original f96c, guest PC 0x0c09e22e */
if(!s->budget--) { s->failed_pc=0x0c09e22eu; return 0; }
vf3_matrix_move(s,9,6);
goto P_0c09e230;
P_0c09e230: /* original f962, guest PC 0x0c09e230 */
if(!s->budget--) { s->failed_pc=0x0c09e230u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[6],r[18],'*');
goto P_0c09e232;
P_0c09e232: /* original f84c, guest PC 0x0c09e232 */
if(!s->budget--) { s->failed_pc=0x0c09e232u; return 0; }
vf3_matrix_move(s,8,4);
goto P_0c09e234;
P_0c09e234: /* original f842, guest PC 0x0c09e234 */
if(!s->budget--) { s->failed_pc=0x0c09e234u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'*');
goto P_0c09e236;
P_0c09e236: /* original f24c, guest PC 0x0c09e236 */
if(!s->budget--) { s->failed_pc=0x0c09e236u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c09e238;
P_0c09e238: /* original f462, guest PC 0x0c09e238 */
if(!s->budget--) { s->failed_pc=0x0c09e238u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c09e23a;
P_0c09e23a: /* original f3ac, guest PC 0x0c09e23a */
if(!s->budget--) { s->failed_pc=0x0c09e23au; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c09e23c;
P_0c09e23c: /* original c728, guest PC 0x0c09e23c */
if(!s->budget--) { s->failed_pc=0x0c09e23cu; return 0; }
r[0]=code_base|0x0009e2e0u;
goto P_0c09e23e;
P_0c09e23e: /* original f391, guest PC 0x0c09e23e */
if(!s->budget--) { s->failed_pc=0x0c09e23eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[9],r[18],'-');
goto P_0c09e240;
P_0c09e240: /* original f708, guest PC 0x0c09e240 */
if(!s->budget--) { s->failed_pc=0x0c09e240u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c09e242;
P_0c09e242: /* original f252, guest PC 0x0c09e242 */
if(!s->budget--) { s->failed_pc=0x0c09e242u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'*');
goto P_0c09e244;
P_0c09e244: /* original c727, guest PC 0x0c09e244 */
if(!s->budget--) { s->failed_pc=0x0c09e244u; return 0; }
r[0]=code_base|0x0009e2e4u;
goto P_0c09e246;
P_0c09e246: /* original f472, guest PC 0x0c09e246 */
if(!s->budget--) { s->failed_pc=0x0c09e246u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c09e248;
P_0c09e248: /* original f380, guest PC 0x0c09e248 */
if(!s->budget--) { s->failed_pc=0x0c09e248u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'+');
goto P_0c09e24a;
P_0c09e24a: /* original f890, guest PC 0x0c09e24a */
if(!s->budget--) { s->failed_pc=0x0c09e24au; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[9],r[18],'+');
goto P_0c09e24c;
P_0c09e24c: /* original f272, guest PC 0x0c09e24c */
if(!s->budget--) { s->failed_pc=0x0c09e24cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c09e24e;
P_0c09e24e: /* original f53c, guest PC 0x0c09e24e */
if(!s->budget--) { s->failed_pc=0x0c09e24eu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c09e250;
P_0c09e250: /* original f8a1, guest PC 0x0c09e250 */
if(!s->budget--) { s->failed_pc=0x0c09e250u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[10],r[18],'-');
goto P_0c09e252;
P_0c09e252: /* original f523, guest PC 0x0c09e252 */
if(!s->budget--) { s->failed_pc=0x0c09e252u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
goto P_0c09e254;
P_0c09e254: /* original fe8c, guest PC 0x0c09e254 */
if(!s->budget--) { s->failed_pc=0x0c09e254u; return 0; }
vf3_matrix_move(s,14,8);
goto P_0c09e256;
P_0c09e256: /* original fe43, guest PC 0x0c09e256 */
if(!s->budget--) { s->failed_pc=0x0c09e256u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'/');
goto P_0c09e258;
P_0c09e258: /* original f49d, guest PC 0x0c09e258 */
if(!s->budget--) { s->failed_pc=0x0c09e258u; return 0; }
fr[4]=0x3f800000u;
goto P_0c09e25a;
P_0c09e25a: /* original fe45, guest PC 0x0c09e25a */
if(!s->budget--) { s->failed_pc=0x0c09e25au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[4]))!=0);
goto P_0c09e25c;
P_0c09e25c: /* original 8f02, guest PC 0x0c09e25c */
if(!s->budget--) { s->failed_pc=0x0c09e25cu; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,6,r[0]);
if(!cond) { goto P_0c09e264; }
goto P_0c09e260;
P_0c09e25e: /* original f608, guest PC 0x0c09e25e */
if(!s->budget--) { s->failed_pc=0x0c09e25eu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c09e260;
P_0c09e260: /* original a003, guest PC 0x0c09e260 */
if(!s->budget--) { s->failed_pc=0x0c09e260u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c09e26a;
P_0c09e262: /* original fe4c, guest PC 0x0c09e262 */
if(!s->budget--) { s->failed_pc=0x0c09e262u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c09e264;
P_0c09e264: /* original f6e5, guest PC 0x0c09e264 */
if(!s->budget--) { s->failed_pc=0x0c09e264u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[14]))!=0);
goto P_0c09e266;
P_0c09e266: /* original 8b00, guest PC 0x0c09e266 */
if(!s->budget--) { s->failed_pc=0x0c09e266u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09e26a; }
goto P_0c09e268;
P_0c09e268: /* original fe6c, guest PC 0x0c09e268 */
if(!s->budget--) { s->failed_pc=0x0c09e268u; return 0; }
vf3_matrix_move(s,14,6);
goto P_0c09e26a;
P_0c09e26a: /* original f545, guest PC 0x0c09e26a */
if(!s->budget--) { s->failed_pc=0x0c09e26au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c09e26c;
P_0c09e26c: /* original 8b01, guest PC 0x0c09e26c */
if(!s->budget--) { s->failed_pc=0x0c09e26cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09e272; }
goto P_0c09e26e;
P_0c09e26e: /* original a003, guest PC 0x0c09e26e */
if(!s->budget--) { s->failed_pc=0x0c09e26eu; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c09e278;
P_0c09e270: /* original f54c, guest PC 0x0c09e270 */
if(!s->budget--) { s->failed_pc=0x0c09e270u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c09e272;
P_0c09e272: /* original f655, guest PC 0x0c09e272 */
if(!s->budget--) { s->failed_pc=0x0c09e272u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[5]))!=0);
goto P_0c09e274;
P_0c09e274: /* original 8b00, guest PC 0x0c09e274 */
if(!s->budget--) { s->failed_pc=0x0c09e274u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09e278; }
goto P_0c09e276;
P_0c09e276: /* original f56c, guest PC 0x0c09e276 */
if(!s->budget--) { s->failed_pc=0x0c09e276u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c09e278;
P_0c09e278: /* original f35c, guest PC 0x0c09e278 */
if(!s->budget--) { s->failed_pc=0x0c09e278u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c09e27a;
P_0c09e27a: /* original f352, guest PC 0x0c09e27a */
if(!s->budget--) { s->failed_pc=0x0c09e27au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c09e27c;
P_0c09e27c: /* original c71a, guest PC 0x0c09e27c */
if(!s->budget--) { s->failed_pc=0x0c09e27cu; return 0; }
r[0]=code_base|0x0009e2e8u;
goto P_0c09e27e;
P_0c09e27e: /* original fd08, guest PC 0x0c09e27e */
if(!s->budget--) { s->failed_pc=0x0c09e27eu; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c09e280;
P_0c09e280: /* original f431, guest PC 0x0c09e280 */
if(!s->budget--) { s->failed_pc=0x0c09e280u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c09e282;
P_0c09e282: /* original fd45, guest PC 0x0c09e282 */
if(!s->budget--) { s->failed_pc=0x0c09e282u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[13])>as_float(fr[4]))!=0);
goto P_0c09e284;
P_0c09e284: /* original 8b01, guest PC 0x0c09e284 */
if(!s->budget--) { s->failed_pc=0x0c09e284u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09e28a; }
goto P_0c09e286;
P_0c09e286: /* original a001, guest PC 0x0c09e286 */
if(!s->budget--) { s->failed_pc=0x0c09e286u; return 0; }
fr[4]=0;
goto P_0c09e28c;
P_0c09e288: /* original f48d, guest PC 0x0c09e288 */
if(!s->budget--) { s->failed_pc=0x0c09e288u; return 0; }
fr[4]=0;
goto P_0c09e28a;
P_0c09e28a: /* original f46d, guest PC 0x0c09e28a */
if(!s->budget--) { s->failed_pc=0x0c09e28au; return 0; }
fr[4]=vf3_fpu_sqrt(fr[4],r[18]);
goto P_0c09e28c;
P_0c09e28c: /* original d317, guest PC 0x0c09e28c */
if(!s->budget--) { s->failed_pc=0x0c09e28cu; return 0; }
r[3]=read(ram,0x0c09e2ecu,4);
goto P_0c09e28e;
P_0c09e28e: /* original 430b, guest PC 0x0c09e28e */
if(!s->budget--) { s->failed_pc=0x0c09e28eu; return 0; }
target=r[3];
r[16]=code_base|0x0c09e292u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e292u) { target=s->pc; goto dispatch; }
goto P_0c09e292;
P_0c09e290: /* original 0009, guest PC 0x0c09e290 */
if(!s->budget--) { s->failed_pc=0x0c09e290u; return 0; }
goto P_0c09e292;
P_0c09e292: /* original 64f3, guest PC 0x0c09e292 */
if(!s->budget--) { s->failed_pc=0x0c09e292u; return 0; }
r[4]=r[15];
goto P_0c09e294;
P_0c09e294: /* original b927, guest PC 0x0c09e294 */
if(!s->budget--) { s->failed_pc=0x0c09e294u; return 0; }
target=code_base|0x0c09d4e6u; r[16]=code_base|0x0c09e298u;
r[4]+=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e298u) { target=s->pc; goto dispatch; }
goto P_0c09e298;
P_0c09e296: /* original 7450, guest PC 0x0c09e296 */
if(!s->budget--) { s->failed_pc=0x0c09e296u; return 0; }
r[4]+=0x00000050u;
goto P_0c09e298;
P_0c09e298: /* original c715, guest PC 0x0c09e298 */
if(!s->budget--) { s->failed_pc=0x0c09e298u; return 0; }
r[0]=code_base|0x0009e2f0u;
goto P_0c09e29a;
P_0c09e29a: /* original f6ec, guest PC 0x0c09e29a */
if(!s->budget--) { s->failed_pc=0x0c09e29au; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c09e29c;
P_0c09e29c: /* original f508, guest PC 0x0c09e29c */
if(!s->budget--) { s->failed_pc=0x0c09e29cu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c09e29e;
P_0c09e29e: /* original f652, guest PC 0x0c09e29e */
if(!s->budget--) { s->failed_pc=0x0c09e29eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c09e2a0;
P_0c09e2a0: /* original f46c, guest PC 0x0c09e2a0 */
if(!s->budget--) { s->failed_pc=0x0c09e2a0u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c09e2a2;
P_0c09e2a2: /* original f450, guest PC 0x0c09e2a2 */
if(!s->budget--) { s->failed_pc=0x0c09e2a2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c09e2a4;
P_0c09e2a4: /* original fd45, guest PC 0x0c09e2a4 */
if(!s->budget--) { s->failed_pc=0x0c09e2a4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[13])>as_float(fr[4]))!=0);
goto P_0c09e2a6;
P_0c09e2a6: /* original 8b01, guest PC 0x0c09e2a6 */
if(!s->budget--) { s->failed_pc=0x0c09e2a6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09e2ac; }
goto P_0c09e2a8;
P_0c09e2a8: /* original a002, guest PC 0x0c09e2a8 */
if(!s->budget--) { s->failed_pc=0x0c09e2a8u; return 0; }
fr[3]=0;
goto P_0c09e2b0;
P_0c09e2aa: /* original f38d, guest PC 0x0c09e2aa */
if(!s->budget--) { s->failed_pc=0x0c09e2aau; return 0; }
fr[3]=0;
goto P_0c09e2ac;
P_0c09e2ac: /* original f34c, guest PC 0x0c09e2ac */
if(!s->budget--) { s->failed_pc=0x0c09e2acu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c09e2ae;
P_0c09e2ae: /* original f36d, guest PC 0x0c09e2ae */
if(!s->budget--) { s->failed_pc=0x0c09e2aeu; return 0; }
fr[3]=vf3_fpu_sqrt(fr[3],r[18]);
goto P_0c09e2b0;
P_0c09e2b0: /* original f45c, guest PC 0x0c09e2b0 */
if(!s->budget--) { s->failed_pc=0x0c09e2b0u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c09e2b2;
P_0c09e2b2: /* original f461, guest PC 0x0c09e2b2 */
if(!s->budget--) { s->failed_pc=0x0c09e2b2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
goto P_0c09e2b4;
P_0c09e2b4: /* original fe3c, guest PC 0x0c09e2b4 */
if(!s->budget--) { s->failed_pc=0x0c09e2b4u; return 0; }
vf3_matrix_move(s,14,3);
goto P_0c09e2b6;
P_0c09e2b6: /* original fd45, guest PC 0x0c09e2b6 */
if(!s->budget--) { s->failed_pc=0x0c09e2b6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[13])>as_float(fr[4]))!=0);
goto P_0c09e2b8;
P_0c09e2b8: /* original 8f02, guest PC 0x0c09e2b8 */
if(!s->budget--) { s->failed_pc=0x0c09e2b8u; return 0; }
cond=r[17]&1u;
fr[14]^=0x80000000u;
if(!cond) { goto P_0c09e2c0; }
goto P_0c09e2bc;
P_0c09e2ba: /* original fe4d, guest PC 0x0c09e2ba */
if(!s->budget--) { s->failed_pc=0x0c09e2bau; return 0; }
fr[14]^=0x80000000u;
goto P_0c09e2bc;
P_0c09e2bc: /* original a002, guest PC 0x0c09e2bc */
if(!s->budget--) { s->failed_pc=0x0c09e2bcu; return 0; }
fr[13]=0;
goto P_0c09e2c4;
P_0c09e2be: /* original fd8d, guest PC 0x0c09e2be */
if(!s->budget--) { s->failed_pc=0x0c09e2beu; return 0; }
fr[13]=0;
goto P_0c09e2c0;
P_0c09e2c0: /* original fd4c, guest PC 0x0c09e2c0 */
if(!s->budget--) { s->failed_pc=0x0c09e2c0u; return 0; }
vf3_matrix_move(s,13,4);
goto P_0c09e2c2;
P_0c09e2c2: /* original fd6d, guest PC 0x0c09e2c2 */
if(!s->budget--) { s->failed_pc=0x0c09e2c2u; return 0; }
fr[13]=vf3_fpu_sqrt(fr[13],r[18]);
goto P_0c09e2c4;
P_0c09e2c4: /* original d309, guest PC 0x0c09e2c4 */
if(!s->budget--) { s->failed_pc=0x0c09e2c4u; return 0; }
r[3]=read(ram,0x0c09e2ecu,4);
goto P_0c09e2c6;
P_0c09e2c6: /* original f5dc, guest PC 0x0c09e2c6 */
if(!s->budget--) { s->failed_pc=0x0c09e2c6u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c09e2c8;
P_0c09e2c8: /* original 430b, guest PC 0x0c09e2c8 */
if(!s->budget--) { s->failed_pc=0x0c09e2c8u; return 0; }
target=r[3];
r[16]=code_base|0x0c09e2ccu;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e2ccu) { target=s->pc; goto dispatch; }
goto P_0c09e2cc;
P_0c09e2ca: /* original f4ec, guest PC 0x0c09e2ca */
if(!s->budget--) { s->failed_pc=0x0c09e2cau; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c09e2cc;
P_0c09e2cc: /* original 9007, guest PC 0x0c09e2cc */
if(!s->budget--) { s->failed_pc=0x0c09e2ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e2deu,2);
goto P_0c09e2ce;
P_0c09e2ce: /* original b90a, guest PC 0x0c09e2ce */
if(!s->budget--) { s->failed_pc=0x0c09e2ceu; return 0; }
target=code_base|0x0c09d4e6u; r[16]=code_base|0x0c09e2d2u;
r[4]=read(ram,r[15]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e2d2u) { target=s->pc; goto dispatch; }
goto P_0c09e2d2;
P_0c09e2d0: /* original 04fe, guest PC 0x0c09e2d0 */
if(!s->budget--) { s->failed_pc=0x0c09e2d0u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c09e2d2;
P_0c09e2d2: /* original d206, guest PC 0x0c09e2d2 */
if(!s->budget--) { s->failed_pc=0x0c09e2d2u; return 0; }
r[2]=read(ram,0x0c09e2ecu,4);
goto P_0c09e2d4;
P_0c09e2d4: /* original f5dc, guest PC 0x0c09e2d4 */
if(!s->budget--) { s->failed_pc=0x0c09e2d4u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c09e2d6;
P_0c09e2d6: /* original 420b, guest PC 0x0c09e2d6 */
if(!s->budget--) { s->failed_pc=0x0c09e2d6u; return 0; }
target=r[2];
r[16]=code_base|0x0c09e2dau;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e2dau) { target=s->pc; goto dispatch; }
goto P_0c09e2da;
P_0c09e2d8: /* original f4ec, guest PC 0x0c09e2d8 */
if(!s->budget--) { s->failed_pc=0x0c09e2d8u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c09e2da;
P_0c09e2da: /* original a011, guest PC 0x0c09e2da */
if(!s->budget--) { s->failed_pc=0x0c09e2dau; return 0; }
goto P_0c09e300;
P_0c09e2dc: /* original 0009, guest PC 0x0c09e2dc */
if(!s->budget--) { s->failed_pc=0x0c09e2dcu; return 0; }
if(!vf3_matrix_family(0x0c09e2deu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09e2deu; return 0; } return 1;
P_0c09e2f4: /* original 64f3, guest PC 0x0c09e2f4 */
if(!s->budget--) { s->failed_pc=0x0c09e2f4u; return 0; }
r[4]=r[15];
goto P_0c09e2f6;
P_0c09e2f6: /* original b8f6, guest PC 0x0c09e2f6 */
if(!s->budget--) { s->failed_pc=0x0c09e2f6u; return 0; }
target=code_base|0x0c09d4e6u; r[16]=code_base|0x0c09e2fau;
r[4]+=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e2fau) { target=s->pc; goto dispatch; }
goto P_0c09e2fa;
P_0c09e2f8: /* original 7450, guest PC 0x0c09e2f8 */
if(!s->budget--) { s->failed_pc=0x0c09e2f8u; return 0; }
r[4]+=0x00000050u;
goto P_0c09e2fa;
P_0c09e2fa: /* original 9086, guest PC 0x0c09e2fa */
if(!s->budget--) { s->failed_pc=0x0c09e2fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e40au,2);
goto P_0c09e2fc;
P_0c09e2fc: /* original b8f3, guest PC 0x0c09e2fc */
if(!s->budget--) { s->failed_pc=0x0c09e2fcu; return 0; }
target=code_base|0x0c09d4e6u; r[16]=code_base|0x0c09e300u;
r[4]=read(ram,r[15]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e300u) { target=s->pc; goto dispatch; }
goto P_0c09e300;
P_0c09e2fe: /* original 04fe, guest PC 0x0c09e2fe */
if(!s->budget--) { s->failed_pc=0x0c09e2feu; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c09e300;
P_0c09e300: /* original 62b3, guest PC 0x0c09e300 */
if(!s->budget--) { s->failed_pc=0x0c09e300u; return 0; }
r[2]=r[11];
goto P_0c09e302;
P_0c09e302: /* original 7240, guest PC 0x0c09e302 */
if(!s->budget--) { s->failed_pc=0x0c09e302u; return 0; }
r[2]+=0x00000040u;
goto P_0c09e304;
P_0c09e304: /* original 2f22, guest PC 0x0c09e304 */
if(!s->budget--) { s->failed_pc=0x0c09e304u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c09e306;
P_0c09e306: /* original 9481, guest PC 0x0c09e306 */
if(!s->budget--) { s->failed_pc=0x0c09e306u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e40cu,2);
goto P_0c09e308;
P_0c09e308: /* original b8ed, guest PC 0x0c09e308 */
if(!s->budget--) { s->failed_pc=0x0c09e308u; return 0; }
target=code_base|0x0c09d4e6u; r[16]=code_base|0x0c09e30cu;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e30cu) { target=s->pc; goto dispatch; }
goto P_0c09e30c;
P_0c09e30a: /* original 34fc, guest PC 0x0c09e30a */
if(!s->budget--) { s->failed_pc=0x0c09e30au; return 0; }
r[4]+=r[15];
goto P_0c09e30c;
P_0c09e30c: /* original 480b, guest PC 0x0c09e30c */
if(!s->budget--) { s->failed_pc=0x0c09e30cu; return 0; }
target=r[8];
r[16]=code_base|0x0c09e310u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e310u) { target=s->pc; goto dispatch; }
goto P_0c09e310;
P_0c09e30e: /* original e400, guest PC 0x0c09e30e */
if(!s->budget--) { s->failed_pc=0x0c09e30eu; return 0; }
r[4]=0x00000000u;
goto P_0c09e310;
P_0c09e310: /* original 947c, guest PC 0x0c09e310 */
if(!s->budget--) { s->failed_pc=0x0c09e310u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e40cu,2);
goto P_0c09e312;
P_0c09e312: /* original 4c0b, guest PC 0x0c09e312 */
if(!s->budget--) { s->failed_pc=0x0c09e312u; return 0; }
target=r[12];
r[16]=code_base|0x0c09e316u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e316u) { target=s->pc; goto dispatch; }
goto P_0c09e316;
P_0c09e314: /* original 34fc, guest PC 0x0c09e314 */
if(!s->budget--) { s->failed_pc=0x0c09e314u; return 0; }
r[4]+=r[15];
goto P_0c09e316;
P_0c09e316: /* original d241, guest PC 0x0c09e316 */
if(!s->budget--) { s->failed_pc=0x0c09e316u; return 0; }
r[2]=read(ram,0x0c09e41cu,4);
goto P_0c09e318;
P_0c09e318: /* original 9479, guest PC 0x0c09e318 */
if(!s->budget--) { s->failed_pc=0x0c09e318u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e40eu,2);
goto P_0c09e31a;
P_0c09e31a: /* original 420b, guest PC 0x0c09e31a */
if(!s->budget--) { s->failed_pc=0x0c09e31au; return 0; }
target=r[2];
r[16]=code_base|0x0c09e31eu;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e31eu) { target=s->pc; goto dispatch; }
goto P_0c09e31e;
P_0c09e31c: /* original 34fc, guest PC 0x0c09e31c */
if(!s->budget--) { s->failed_pc=0x0c09e31cu; return 0; }
r[4]+=r[15];
goto P_0c09e31e;
P_0c09e31e: /* original 4e0b, guest PC 0x0c09e31e */
if(!s->budget--) { s->failed_pc=0x0c09e31eu; return 0; }
target=r[14];
r[16]=code_base|0x0c09e322u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e322u) { target=s->pc; goto dispatch; }
goto P_0c09e322;
P_0c09e320: /* original 64f2, guest PC 0x0c09e320 */
if(!s->budget--) { s->failed_pc=0x0c09e320u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c09e322;
P_0c09e322: /* original 490b, guest PC 0x0c09e322 */
if(!s->budget--) { s->failed_pc=0x0c09e322u; return 0; }
target=r[9];
r[16]=code_base|0x0c09e326u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e326u) { target=s->pc; goto dispatch; }
goto P_0c09e326;
P_0c09e324: /* original e401, guest PC 0x0c09e324 */
if(!s->budget--) { s->failed_pc=0x0c09e324u; return 0; }
r[4]=0x00000001u;
goto P_0c09e326;
P_0c09e326: /* original d33e, guest PC 0x0c09e326 */
if(!s->budget--) { s->failed_pc=0x0c09e326u; return 0; }
r[3]=read(ram,0x0c09e420u,4);
goto P_0c09e328;
P_0c09e328: /* original 9471, guest PC 0x0c09e328 */
if(!s->budget--) { s->failed_pc=0x0c09e328u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e40eu,2);
goto P_0c09e32a;
P_0c09e32a: /* original 430b, guest PC 0x0c09e32a */
if(!s->budget--) { s->failed_pc=0x0c09e32au; return 0; }
target=r[3];
r[16]=code_base|0x0c09e32eu;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e32eu) { target=s->pc; goto dispatch; }
goto P_0c09e32e;
P_0c09e32c: /* original 34fc, guest PC 0x0c09e32c */
if(!s->budget--) { s->failed_pc=0x0c09e32cu; return 0; }
r[4]+=r[15];
goto P_0c09e32e;
P_0c09e32e: /* original d23b, guest PC 0x0c09e32e */
if(!s->budget--) { s->failed_pc=0x0c09e32eu; return 0; }
r[2]=read(ram,0x0c09e41cu,4);
goto P_0c09e330;
P_0c09e330: /* original 420b, guest PC 0x0c09e330 */
if(!s->budget--) { s->failed_pc=0x0c09e330u; return 0; }
target=r[2];
r[16]=code_base|0x0c09e334u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e334u) { target=s->pc; goto dispatch; }
goto P_0c09e334;
P_0c09e332: /* original 64a3, guest PC 0x0c09e332 */
if(!s->budget--) { s->failed_pc=0x0c09e332u; return 0; }
r[4]=r[10];
goto P_0c09e334;
P_0c09e334: /* original 906c, guest PC 0x0c09e334 */
if(!s->budget--) { s->failed_pc=0x0c09e334u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e410u,2);
goto P_0c09e336;
P_0c09e336: /* original 64a3, guest PC 0x0c09e336 */
if(!s->budget--) { s->failed_pc=0x0c09e336u; return 0; }
r[4]=r[10];
goto P_0c09e338;
P_0c09e338: /* original 740c, guest PC 0x0c09e338 */
if(!s->budget--) { s->failed_pc=0x0c09e338u; return 0; }
r[4]+=0x0000000cu;
goto P_0c09e33a;
P_0c09e33a: /* original 03fe, guest PC 0x0c09e33a */
if(!s->budget--) { s->failed_pc=0x0c09e33au; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c09e33c;
P_0c09e33c: /* original b8f7, guest PC 0x0c09e33c */
if(!s->budget--) { s->failed_pc=0x0c09e33cu; return 0; }
target=code_base|0x0c09d52eu; r[16]=code_base|0x0c09e340u;
vf3_matrix_load(s,ram,4,r[3]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e340u) { target=s->pc; goto dispatch; }
goto P_0c09e340;
P_0c09e33e: /* original f438, guest PC 0x0c09e33e */
if(!s->budget--) { s->failed_pc=0x0c09e33eu; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c09e340;
P_0c09e340: /* original 64f3, guest PC 0x0c09e340 */
if(!s->budget--) { s->failed_pc=0x0c09e340u; return 0; }
r[4]=r[15];
goto P_0c09e342;
P_0c09e342: /* original 4e0b, guest PC 0x0c09e342 */
if(!s->budget--) { s->failed_pc=0x0c09e342u; return 0; }
target=r[14];
r[16]=code_base|0x0c09e346u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e346u) { target=s->pc; goto dispatch; }
goto P_0c09e346;
P_0c09e344: /* original 7410, guest PC 0x0c09e344 */
if(!s->budget--) { s->failed_pc=0x0c09e344u; return 0; }
r[4]+=0x00000010u;
goto P_0c09e346;
P_0c09e346: /* original e018, guest PC 0x0c09e346 */
if(!s->budget--) { s->failed_pc=0x0c09e346u; return 0; }
r[0]=0x00000018u;
goto P_0c09e348;
P_0c09e348: /* original 64f3, guest PC 0x0c09e348 */
if(!s->budget--) { s->failed_pc=0x0c09e348u; return 0; }
r[4]=r[15];
goto P_0c09e34a;
P_0c09e34a: /* original f4d6, guest PC 0x0c09e34a */
if(!s->budget--) { s->failed_pc=0x0c09e34au; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c09e34c;
P_0c09e34c: /* original e040, guest PC 0x0c09e34c */
if(!s->budget--) { s->failed_pc=0x0c09e34cu; return 0; }
r[0]=0x00000040u;
goto P_0c09e34e;
P_0c09e34e: /* original f3f6, guest PC 0x0c09e34e */
if(!s->budget--) { s->failed_pc=0x0c09e34eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e350;
P_0c09e350: /* original e010, guest PC 0x0c09e350 */
if(!s->budget--) { s->failed_pc=0x0c09e350u; return 0; }
r[0]=0x00000010u;
goto P_0c09e352;
P_0c09e352: /* original f2f6, guest PC 0x0c09e352 */
if(!s->budget--) { s->failed_pc=0x0c09e352u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09e354;
P_0c09e354: /* original e040, guest PC 0x0c09e354 */
if(!s->budget--) { s->failed_pc=0x0c09e354u; return 0; }
r[0]=0x00000040u;
goto P_0c09e356;
P_0c09e356: /* original f04c, guest PC 0x0c09e356 */
if(!s->budget--) { s->failed_pc=0x0c09e356u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c09e358;
P_0c09e358: /* original f32e, guest PC 0x0c09e358 */
if(!s->budget--) { s->failed_pc=0x0c09e358u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09e35a;
P_0c09e35a: /* original ff37, guest PC 0x0c09e35a */
if(!s->budget--) { s->failed_pc=0x0c09e35au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e35c;
P_0c09e35c: /* original e044, guest PC 0x0c09e35c */
if(!s->budget--) { s->failed_pc=0x0c09e35cu; return 0; }
r[0]=0x00000044u;
goto P_0c09e35e;
P_0c09e35e: /* original f3f6, guest PC 0x0c09e35e */
if(!s->budget--) { s->failed_pc=0x0c09e35eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e360;
P_0c09e360: /* original e014, guest PC 0x0c09e360 */
if(!s->budget--) { s->failed_pc=0x0c09e360u; return 0; }
r[0]=0x00000014u;
goto P_0c09e362;
P_0c09e362: /* original f2f6, guest PC 0x0c09e362 */
if(!s->budget--) { s->failed_pc=0x0c09e362u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09e364;
P_0c09e364: /* original e044, guest PC 0x0c09e364 */
if(!s->budget--) { s->failed_pc=0x0c09e364u; return 0; }
r[0]=0x00000044u;
goto P_0c09e366;
P_0c09e366: /* original f32e, guest PC 0x0c09e366 */
if(!s->budget--) { s->failed_pc=0x0c09e366u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09e368;
P_0c09e368: /* original ff37, guest PC 0x0c09e368 */
if(!s->budget--) { s->failed_pc=0x0c09e368u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e36a;
P_0c09e36a: /* original e048, guest PC 0x0c09e36a */
if(!s->budget--) { s->failed_pc=0x0c09e36au; return 0; }
r[0]=0x00000048u;
goto P_0c09e36c;
P_0c09e36c: /* original f3f6, guest PC 0x0c09e36c */
if(!s->budget--) { s->failed_pc=0x0c09e36cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e36e;
P_0c09e36e: /* original e018, guest PC 0x0c09e36e */
if(!s->budget--) { s->failed_pc=0x0c09e36eu; return 0; }
r[0]=0x00000018u;
goto P_0c09e370;
P_0c09e370: /* original f2f6, guest PC 0x0c09e370 */
if(!s->budget--) { s->failed_pc=0x0c09e370u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09e372;
P_0c09e372: /* original e048, guest PC 0x0c09e372 */
if(!s->budget--) { s->failed_pc=0x0c09e372u; return 0; }
r[0]=0x00000048u;
goto P_0c09e374;
P_0c09e374: /* original f32e, guest PC 0x0c09e374 */
if(!s->budget--) { s->failed_pc=0x0c09e374u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09e376;
P_0c09e376: /* original ff37, guest PC 0x0c09e376 */
if(!s->budget--) { s->failed_pc=0x0c09e376u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e378;
P_0c09e378: /* original 9047, guest PC 0x0c09e378 */
if(!s->budget--) { s->failed_pc=0x0c09e378u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e40au,2);
goto P_0c09e37a;
P_0c09e37a: /* original 03fe, guest PC 0x0c09e37a */
if(!s->budget--) { s->failed_pc=0x0c09e37au; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c09e37c;
P_0c09e37c: /* original e030, guest PC 0x0c09e37c */
if(!s->budget--) { s->failed_pc=0x0c09e37cu; return 0; }
r[0]=0x00000030u;
goto P_0c09e37e;
P_0c09e37e: /* original f3e7, guest PC 0x0c09e37e */
if(!s->budget--) { s->failed_pc=0x0c09e37eu; return 0; }
vf3_matrix_store(s,ram,14,r[3]+r[0]);
goto P_0c09e380;
P_0c09e380: /* original 9347, guest PC 0x0c09e380 */
if(!s->budget--) { s->failed_pc=0x0c09e380u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e412u,2);
goto P_0c09e382;
P_0c09e382: /* original 33bc, guest PC 0x0c09e382 */
if(!s->budget--) { s->failed_pc=0x0c09e382u; return 0; }
r[3]+=r[11];
goto P_0c09e384;
P_0c09e384: /* original 2f32, guest PC 0x0c09e384 */
if(!s->budget--) { s->failed_pc=0x0c09e384u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09e386;
P_0c09e386: /* original 4c0b, guest PC 0x0c09e386 */
if(!s->budget--) { s->failed_pc=0x0c09e386u; return 0; }
target=r[12];
r[16]=code_base|0x0c09e38au;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e38au) { target=s->pc; goto dispatch; }
goto P_0c09e38a;
P_0c09e388: /* original 7410, guest PC 0x0c09e388 */
if(!s->budget--) { s->failed_pc=0x0c09e388u; return 0; }
r[4]+=0x00000010u;
goto P_0c09e38a;
P_0c09e38a: /* original d324, guest PC 0x0c09e38a */
if(!s->budget--) { s->failed_pc=0x0c09e38au; return 0; }
r[3]=read(ram,0x0c09e41cu,4);
goto P_0c09e38c;
P_0c09e38c: /* original 9441, guest PC 0x0c09e38c */
if(!s->budget--) { s->failed_pc=0x0c09e38cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e412u,2);
goto P_0c09e38e;
P_0c09e38e: /* original 430b, guest PC 0x0c09e38e */
if(!s->budget--) { s->failed_pc=0x0c09e38eu; return 0; }
target=r[3];
r[16]=code_base|0x0c09e392u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e392u) { target=s->pc; goto dispatch; }
goto P_0c09e392;
P_0c09e390: /* original 34fc, guest PC 0x0c09e390 */
if(!s->budget--) { s->failed_pc=0x0c09e390u; return 0; }
r[4]+=r[15];
goto P_0c09e392;
P_0c09e392: /* original 480b, guest PC 0x0c09e392 */
if(!s->budget--) { s->failed_pc=0x0c09e392u; return 0; }
target=r[8];
r[16]=code_base|0x0c09e396u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e396u) { target=s->pc; goto dispatch; }
goto P_0c09e396;
P_0c09e394: /* original e400, guest PC 0x0c09e394 */
if(!s->budget--) { s->failed_pc=0x0c09e394u; return 0; }
r[4]=0x00000000u;
goto P_0c09e396;
P_0c09e396: /* original 64f3, guest PC 0x0c09e396 */
if(!s->budget--) { s->failed_pc=0x0c09e396u; return 0; }
r[4]=r[15];
goto P_0c09e398;
P_0c09e398: /* original 4c0b, guest PC 0x0c09e398 */
if(!s->budget--) { s->failed_pc=0x0c09e398u; return 0; }
target=r[12];
r[16]=code_base|0x0c09e39cu;
r[4]+=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e39cu) { target=s->pc; goto dispatch; }
goto P_0c09e39c;
P_0c09e39a: /* original 7450, guest PC 0x0c09e39a */
if(!s->budget--) { s->failed_pc=0x0c09e39au; return 0; }
r[4]+=0x00000050u;
goto P_0c09e39c;
P_0c09e39c: /* original 64f3, guest PC 0x0c09e39c */
if(!s->budget--) { s->failed_pc=0x0c09e39cu; return 0; }
r[4]=r[15];
goto P_0c09e39e;
P_0c09e39e: /* original 4e0b, guest PC 0x0c09e39e */
if(!s->budget--) { s->failed_pc=0x0c09e39eu; return 0; }
target=r[14];
r[16]=code_base|0x0c09e3a2u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e3a2u) { target=s->pc; goto dispatch; }
goto P_0c09e3a2;
P_0c09e3a0: /* original 7410, guest PC 0x0c09e3a0 */
if(!s->budget--) { s->failed_pc=0x0c09e3a0u; return 0; }
r[4]+=0x00000010u;
goto P_0c09e3a2;
P_0c09e3a2: /* original 4e0b, guest PC 0x0c09e3a2 */
if(!s->budget--) { s->failed_pc=0x0c09e3a2u; return 0; }
target=r[14];
r[16]=code_base|0x0c09e3a6u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e3a6u) { target=s->pc; goto dispatch; }
goto P_0c09e3a6;
P_0c09e3a4: /* original 64f2, guest PC 0x0c09e3a4 */
if(!s->budget--) { s->failed_pc=0x0c09e3a4u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c09e3a6;
P_0c09e3a6: /* original 490b, guest PC 0x0c09e3a6 */
if(!s->budget--) { s->failed_pc=0x0c09e3a6u; return 0; }
target=r[9];
r[16]=code_base|0x0c09e3aau;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e3aau) { target=s->pc; goto dispatch; }
goto P_0c09e3aa;
P_0c09e3a8: /* original e401, guest PC 0x0c09e3a8 */
if(!s->budget--) { s->failed_pc=0x0c09e3a8u; return 0; }
r[4]=0x00000001u;
goto P_0c09e3aa;
P_0c09e3aa: /* original 64f3, guest PC 0x0c09e3aa */
if(!s->budget--) { s->failed_pc=0x0c09e3aau; return 0; }
r[4]=r[15];
goto P_0c09e3ac;
P_0c09e3ac: /* original 4c0b, guest PC 0x0c09e3ac */
if(!s->budget--) { s->failed_pc=0x0c09e3acu; return 0; }
target=r[12];
r[16]=code_base|0x0c09e3b0u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e3b0u) { target=s->pc; goto dispatch; }
goto P_0c09e3b0;
P_0c09e3ae: /* original 7410, guest PC 0x0c09e3ae */
if(!s->budget--) { s->failed_pc=0x0c09e3aeu; return 0; }
r[4]+=0x00000010u;
goto P_0c09e3b0;
P_0c09e3b0: /* original d31a, guest PC 0x0c09e3b0 */
if(!s->budget--) { s->failed_pc=0x0c09e3b0u; return 0; }
r[3]=read(ram,0x0c09e41cu,4);
goto P_0c09e3b2;
P_0c09e3b2: /* original 64a3, guest PC 0x0c09e3b2 */
if(!s->budget--) { s->failed_pc=0x0c09e3b2u; return 0; }
r[4]=r[10];
goto P_0c09e3b4;
P_0c09e3b4: /* original 430b, guest PC 0x0c09e3b4 */
if(!s->budget--) { s->failed_pc=0x0c09e3b4u; return 0; }
target=r[3];
r[16]=code_base|0x0c09e3b8u;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e3b8u) { target=s->pc; goto dispatch; }
goto P_0c09e3b8;
P_0c09e3b6: /* original 7418, guest PC 0x0c09e3b6 */
if(!s->budget--) { s->failed_pc=0x0c09e3b6u; return 0; }
r[4]+=0x00000018u;
goto P_0c09e3b8;
P_0c09e3b8: /* original 902a, guest PC 0x0c09e3b8 */
if(!s->budget--) { s->failed_pc=0x0c09e3b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e410u,2);
goto P_0c09e3ba;
P_0c09e3ba: /* original 64a3, guest PC 0x0c09e3ba */
if(!s->budget--) { s->failed_pc=0x0c09e3bau; return 0; }
r[4]=r[10];
goto P_0c09e3bc;
P_0c09e3bc: /* original 7424, guest PC 0x0c09e3bc */
if(!s->budget--) { s->failed_pc=0x0c09e3bcu; return 0; }
r[4]+=0x00000024u;
goto P_0c09e3be;
P_0c09e3be: /* original 02fe, guest PC 0x0c09e3be */
if(!s->budget--) { s->failed_pc=0x0c09e3beu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c09e3c0;
P_0c09e3c0: /* original e004, guest PC 0x0c09e3c0 */
if(!s->budget--) { s->failed_pc=0x0c09e3c0u; return 0; }
r[0]=0x00000004u;
goto P_0c09e3c2;
P_0c09e3c2: /* original b8b4, guest PC 0x0c09e3c2 */
if(!s->budget--) { s->failed_pc=0x0c09e3c2u; return 0; }
target=code_base|0x0c09d52eu; r[16]=code_base|0x0c09e3c6u;
vf3_matrix_load(s,ram,4,r[2]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e3c6u) { target=s->pc; goto dispatch; }
goto P_0c09e3c6;
P_0c09e3c4: /* original f426, guest PC 0x0c09e3c4 */
if(!s->budget--) { s->failed_pc=0x0c09e3c4u; return 0; }
vf3_matrix_load(s,ram,4,r[2]+r[0]);
goto P_0c09e3c6;
P_0c09e3c6: /* original e024, guest PC 0x0c09e3c6 */
if(!s->budget--) { s->failed_pc=0x0c09e3c6u; return 0; }
r[0]=0x00000024u;
goto P_0c09e3c8;
P_0c09e3c8: /* original d316, guest PC 0x0c09e3c8 */
if(!s->budget--) { s->failed_pc=0x0c09e3c8u; return 0; }
r[3]=read(ram,0x0c09e424u,4);
goto P_0c09e3ca;
P_0c09e3ca: /* original f4d6, guest PC 0x0c09e3ca */
if(!s->budget--) { s->failed_pc=0x0c09e3cau; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c09e3cc;
P_0c09e3cc: /* original f6fc, guest PC 0x0c09e3cc */
if(!s->budget--) { s->failed_pc=0x0c09e3ccu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c09e3ce;
P_0c09e3ce: /* original 430b, guest PC 0x0c09e3ce */
if(!s->budget--) { s->failed_pc=0x0c09e3ceu; return 0; }
target=r[3];
r[16]=code_base|0x0c09e3d2u;
vf3_matrix_move(s,5,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e3d2u) { target=s->pc; goto dispatch; }
goto P_0c09e3d2;
P_0c09e3d0: /* original f5fc, guest PC 0x0c09e3d0 */
if(!s->budget--) { s->failed_pc=0x0c09e3d0u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09e3d2;
P_0c09e3d2: /* original 901f, guest PC 0x0c09e3d2 */
if(!s->budget--) { s->failed_pc=0x0c09e3d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e414u,2);
goto P_0c09e3d4;
P_0c09e3d4: /* original 04fe, guest PC 0x0c09e3d4 */
if(!s->budget--) { s->failed_pc=0x0c09e3d4u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c09e3d6;
P_0c09e3d6: /* original b853, guest PC 0x0c09e3d6 */
if(!s->budget--) { s->failed_pc=0x0c09e3d6u; return 0; }
target=code_base|0x0c09d480u; r[16]=code_base|0x0c09e3dau;
r[4]+=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e3dau) { target=s->pc; goto dispatch; }
goto P_0c09e3da;
P_0c09e3d8: /* original 740c, guest PC 0x0c09e3d8 */
if(!s->budget--) { s->failed_pc=0x0c09e3d8u; return 0; }
r[4]+=0x0000000cu;
goto P_0c09e3da;
P_0c09e3da: /* original 941c, guest PC 0x0c09e3da */
if(!s->budget--) { s->failed_pc=0x0c09e3dau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e416u,2);
goto P_0c09e3dc;
P_0c09e3dc: /* original 4e0b, guest PC 0x0c09e3dc */
if(!s->budget--) { s->failed_pc=0x0c09e3dcu; return 0; }
target=r[14];
r[16]=code_base|0x0c09e3e0u;
r[4]+=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e3e0u) { target=s->pc; goto dispatch; }
goto P_0c09e3e0;
P_0c09e3de: /* original 34bc, guest PC 0x0c09e3de */
if(!s->budget--) { s->failed_pc=0x0c09e3deu; return 0; }
r[4]+=r[11];
goto P_0c09e3e0;
P_0c09e3e0: /* original 9016, guest PC 0x0c09e3e0 */
if(!s->budget--) { s->failed_pc=0x0c09e3e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e410u,2);
goto P_0c09e3e2;
P_0c09e3e2: /* original 64a3, guest PC 0x0c09e3e2 */
if(!s->budget--) { s->failed_pc=0x0c09e3e2u; return 0; }
r[4]=r[10];
goto P_0c09e3e4;
P_0c09e3e4: /* original 7430, guest PC 0x0c09e3e4 */
if(!s->budget--) { s->failed_pc=0x0c09e3e4u; return 0; }
r[4]+=0x00000030u;
goto P_0c09e3e6;
P_0c09e3e6: /* original 02fe, guest PC 0x0c09e3e6 */
if(!s->budget--) { s->failed_pc=0x0c09e3e6u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c09e3e8;
P_0c09e3e8: /* original e008, guest PC 0x0c09e3e8 */
if(!s->budget--) { s->failed_pc=0x0c09e3e8u; return 0; }
r[0]=0x00000008u;
goto P_0c09e3ea;
P_0c09e3ea: /* original b8a0, guest PC 0x0c09e3ea */
if(!s->budget--) { s->failed_pc=0x0c09e3eau; return 0; }
target=code_base|0x0c09d52eu; r[16]=code_base|0x0c09e3eeu;
vf3_matrix_load(s,ram,4,r[2]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e3eeu) { target=s->pc; goto dispatch; }
goto P_0c09e3ee;
P_0c09e3ec: /* original f426, guest PC 0x0c09e3ec */
if(!s->budget--) { s->failed_pc=0x0c09e3ecu; return 0; }
vf3_matrix_load(s,ram,4,r[2]+r[0]);
goto P_0c09e3ee;
P_0c09e3ee: /* original 9113, guest PC 0x0c09e3ee */
if(!s->budget--) { s->failed_pc=0x0c09e3eeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e418u,2);
goto P_0c09e3f0;
P_0c09e3f0: /* original 3f1c, guest PC 0x0c09e3f0 */
if(!s->budget--) { s->failed_pc=0x0c09e3f0u; return 0; }
r[15]+=r[1];
goto P_0c09e3f2;
P_0c09e3f2: /* original 4f26, guest PC 0x0c09e3f2 */
if(!s->budget--) { s->failed_pc=0x0c09e3f2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09e3f4;
P_0c09e3f4: /* original fdf9, guest PC 0x0c09e3f4 */
if(!s->budget--) { s->failed_pc=0x0c09e3f4u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09e3f6;
P_0c09e3f6: /* original fef9, guest PC 0x0c09e3f6 */
if(!s->budget--) { s->failed_pc=0x0c09e3f6u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09e3f8;
P_0c09e3f8: /* original fff9, guest PC 0x0c09e3f8 */
if(!s->budget--) { s->failed_pc=0x0c09e3f8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09e3fa;
P_0c09e3fa: /* original 68f6, guest PC 0x0c09e3fa */
if(!s->budget--) { s->failed_pc=0x0c09e3fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09e3fc;
P_0c09e3fc: /* original 69f6, guest PC 0x0c09e3fc */
if(!s->budget--) { s->failed_pc=0x0c09e3fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09e3fe;
P_0c09e3fe: /* original 6af6, guest PC 0x0c09e3fe */
if(!s->budget--) { s->failed_pc=0x0c09e3feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09e400;
P_0c09e400: /* original 6bf6, guest PC 0x0c09e400 */
if(!s->budget--) { s->failed_pc=0x0c09e400u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09e402;
P_0c09e402: /* original 6cf6, guest PC 0x0c09e402 */
if(!s->budget--) { s->failed_pc=0x0c09e402u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09e404;
P_0c09e404: /* original 6df6, guest PC 0x0c09e404 */
if(!s->budget--) { s->failed_pc=0x0c09e404u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09e406;
P_0c09e406: /* original 000b, guest PC 0x0c09e406 */
if(!s->budget--) { s->failed_pc=0x0c09e406u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09e408: /* original 6ef6, guest PC 0x0c09e408 */
if(!s->budget--) { s->failed_pc=0x0c09e408u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09e40au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09e40au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
