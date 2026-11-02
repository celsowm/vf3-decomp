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
int vf3_away_batch204_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0aa0aau: goto P_0c0aa0aa;
case 0x0c0aa0acu: goto P_0c0aa0ac;
case 0x0c0aa0aeu: goto P_0c0aa0ae;
case 0x0c0aa0b0u: goto P_0c0aa0b0;
case 0x0c0aa0b2u: goto P_0c0aa0b2;
case 0x0c0aa0b4u: goto P_0c0aa0b4;
case 0x0c0aa0b6u: goto P_0c0aa0b6;
case 0x0c0aa0b8u: goto P_0c0aa0b8;
case 0x0c0aa0bau: goto P_0c0aa0ba;
case 0x0c0aa0bcu: goto P_0c0aa0bc;
case 0x0c0aa0beu: goto P_0c0aa0be;
case 0x0c0aa0c0u: goto P_0c0aa0c0;
case 0x0c0aa0d0u: goto P_0c0aa0d0;
case 0x0c0aa0d2u: goto P_0c0aa0d2;
case 0x0c0aa0d4u: goto P_0c0aa0d4;
case 0x0c0aa0d6u: goto P_0c0aa0d6;
case 0x0c0aa0d8u: goto P_0c0aa0d8;
case 0x0c0aa0dau: goto P_0c0aa0da;
case 0x0c0aa0dcu: goto P_0c0aa0dc;
case 0x0c0aa0deu: goto P_0c0aa0de;
case 0x0c0aa0e0u: goto P_0c0aa0e0;
case 0x0c0aa0e2u: goto P_0c0aa0e2;
case 0x0c0aa0e4u: goto P_0c0aa0e4;
case 0x0c0aa0e6u: goto P_0c0aa0e6;
case 0x0c0aa0e8u: goto P_0c0aa0e8;
case 0x0c0aa0eau: goto P_0c0aa0ea;
case 0x0c0aa0ecu: goto P_0c0aa0ec;
case 0x0c0aa0eeu: goto P_0c0aa0ee;
case 0x0c0aa0f0u: goto P_0c0aa0f0;
case 0x0c0aa0f2u: goto P_0c0aa0f2;
case 0x0c0aa0f4u: goto P_0c0aa0f4;
case 0x0c0aa0f6u: goto P_0c0aa0f6;
case 0x0c0aa0f8u: goto P_0c0aa0f8;
case 0x0c0aa0fau: goto P_0c0aa0fa;
case 0x0c0aa0fcu: goto P_0c0aa0fc;
case 0x0c0aa0feu: goto P_0c0aa0fe;
case 0x0c0aa1ecu: goto P_0c0aa1ec;
case 0x0c0aa1eeu: goto P_0c0aa1ee;
case 0x0c0aa1f0u: goto P_0c0aa1f0;
case 0x0c0aa1f2u: goto P_0c0aa1f2;
case 0x0c0aa1f4u: goto P_0c0aa1f4;
case 0x0c0aa1f6u: goto P_0c0aa1f6;
case 0x0c0aa1f8u: goto P_0c0aa1f8;
case 0x0c0aa1fau: goto P_0c0aa1fa;
case 0x0c0aa1fcu: goto P_0c0aa1fc;
case 0x0c0aa1feu: goto P_0c0aa1fe;
case 0x0c0aa200u: goto P_0c0aa200;
case 0x0c0aa202u: goto P_0c0aa202;
case 0x0c0aa204u: goto P_0c0aa204;
case 0x0c0aa206u: goto P_0c0aa206;
case 0x0c0aa208u: goto P_0c0aa208;
case 0x0c0aa20au: goto P_0c0aa20a;
case 0x0c0aa20cu: goto P_0c0aa20c;
case 0x0c0aa20eu: goto P_0c0aa20e;
case 0x0c0aa210u: goto P_0c0aa210;
case 0x0c0aa212u: goto P_0c0aa212;
case 0x0c0aa214u: goto P_0c0aa214;
case 0x0c0aa216u: goto P_0c0aa216;
case 0x0c0aa218u: goto P_0c0aa218;
case 0x0c0aa21au: goto P_0c0aa21a;
case 0x0c0aa21cu: goto P_0c0aa21c;
case 0x0c0aa21eu: goto P_0c0aa21e;
case 0x0c0aa220u: goto P_0c0aa220;
case 0x0c0aa222u: goto P_0c0aa222;
case 0x0c0aa224u: goto P_0c0aa224;
case 0x0c0aa226u: goto P_0c0aa226;
case 0x0c0aa228u: goto P_0c0aa228;
case 0x0c0aa22au: goto P_0c0aa22a;
case 0x0c0aa22cu: goto P_0c0aa22c;
case 0x0c0aa22eu: goto P_0c0aa22e;
case 0x0c0aa230u: goto P_0c0aa230;
case 0x0c0aa232u: goto P_0c0aa232;
case 0x0c0aa234u: goto P_0c0aa234;
case 0x0c0aa236u: goto P_0c0aa236;
case 0x0c0aa238u: goto P_0c0aa238;
case 0x0c0aa23au: goto P_0c0aa23a;
case 0x0c0aa23cu: goto P_0c0aa23c;
case 0x0c0aa23eu: goto P_0c0aa23e;
case 0x0c0aa240u: goto P_0c0aa240;
case 0x0c0aa242u: goto P_0c0aa242;
case 0x0c0aa244u: goto P_0c0aa244;
case 0x0c0aa246u: goto P_0c0aa246;
case 0x0c0aa248u: goto P_0c0aa248;
case 0x0c0aa24au: goto P_0c0aa24a;
case 0x0c0aa24cu: goto P_0c0aa24c;
case 0x0c0aa24eu: goto P_0c0aa24e;
case 0x0c0aa250u: goto P_0c0aa250;
case 0x0c0aa252u: goto P_0c0aa252;
case 0x0c0aa254u: goto P_0c0aa254;
case 0x0c0aa256u: goto P_0c0aa256;
case 0x0c0aa258u: goto P_0c0aa258;
case 0x0c0aa25au: goto P_0c0aa25a;
case 0x0c0aa25cu: goto P_0c0aa25c;
case 0x0c0aa25eu: goto P_0c0aa25e;
case 0x0c0aa260u: goto P_0c0aa260;
case 0x0c0aa262u: goto P_0c0aa262;
case 0x0c0aa264u: goto P_0c0aa264;
case 0x0c0aa266u: goto P_0c0aa266;
case 0x0c0aa268u: goto P_0c0aa268;
case 0x0c0aa26au: goto P_0c0aa26a;
case 0x0c0aa26cu: goto P_0c0aa26c;
case 0x0c0aa26eu: goto P_0c0aa26e;
case 0x0c0aa270u: goto P_0c0aa270;
case 0x0c0aa272u: goto P_0c0aa272;
case 0x0c0aa274u: goto P_0c0aa274;
case 0x0c0aa276u: goto P_0c0aa276;
case 0x0c0aa278u: goto P_0c0aa278;
case 0x0c0aa27au: goto P_0c0aa27a;
case 0x0c0aa27cu: goto P_0c0aa27c;
case 0x0c0aa27eu: goto P_0c0aa27e;
case 0x0c0aa280u: goto P_0c0aa280;
case 0x0c0aa282u: goto P_0c0aa282;
case 0x0c0aa284u: goto P_0c0aa284;
case 0x0c0aa286u: goto P_0c0aa286;
case 0x0c0aa288u: goto P_0c0aa288;
case 0x0c0aa28au: goto P_0c0aa28a;
case 0x0c0aa28cu: goto P_0c0aa28c;
case 0x0c0aa28eu: goto P_0c0aa28e;
case 0x0c0aa290u: goto P_0c0aa290;
case 0x0c0aa292u: goto P_0c0aa292;
case 0x0c0aa294u: goto P_0c0aa294;
case 0x0c0aa296u: goto P_0c0aa296;
case 0x0c0aa298u: goto P_0c0aa298;
case 0x0c0aa29au: goto P_0c0aa29a;
case 0x0c0aa29cu: goto P_0c0aa29c;
case 0x0c0aa29eu: goto P_0c0aa29e;
case 0x0c0aa2a0u: goto P_0c0aa2a0;
case 0x0c0aa2a2u: goto P_0c0aa2a2;
case 0x0c0aa2c8u: goto P_0c0aa2c8;
case 0x0c0aa2cau: goto P_0c0aa2ca;
case 0x0c0aa2ccu: goto P_0c0aa2cc;
case 0x0c0aa2ceu: goto P_0c0aa2ce;
case 0x0c0aa2d0u: goto P_0c0aa2d0;
case 0x0c0aa2d2u: goto P_0c0aa2d2;
case 0x0c0aa2d4u: goto P_0c0aa2d4;
case 0x0c0aa2d6u: goto P_0c0aa2d6;
case 0x0c0aa2d8u: goto P_0c0aa2d8;
case 0x0c0aa2dau: goto P_0c0aa2da;
case 0x0c0aa2dcu: goto P_0c0aa2dc;
case 0x0c0aa2deu: goto P_0c0aa2de;
case 0x0c0aa2e0u: goto P_0c0aa2e0;
case 0x0c0aa2e2u: goto P_0c0aa2e2;
case 0x0c0aa2e4u: goto P_0c0aa2e4;
case 0x0c0aa2e6u: goto P_0c0aa2e6;
case 0x0c0aa2e8u: goto P_0c0aa2e8;
case 0x0c0aa2eau: goto P_0c0aa2ea;
case 0x0c0aa2ecu: goto P_0c0aa2ec;
case 0x0c0aa2eeu: goto P_0c0aa2ee;
case 0x0c0aa2f0u: goto P_0c0aa2f0;
case 0x0c0aa2f2u: goto P_0c0aa2f2;
case 0x0c0aa2f4u: goto P_0c0aa2f4;
case 0x0c0aa2f6u: goto P_0c0aa2f6;
case 0x0c0aa2f8u: goto P_0c0aa2f8;
case 0x0c0aa2fau: goto P_0c0aa2fa;
case 0x0c0aa2fcu: goto P_0c0aa2fc;
case 0x0c0aa2feu: goto P_0c0aa2fe;
case 0x0c0aa300u: goto P_0c0aa300;
case 0x0c0aa302u: goto P_0c0aa302;
case 0x0c0aa304u: goto P_0c0aa304;
case 0x0c0aa306u: goto P_0c0aa306;
case 0x0c0aa308u: goto P_0c0aa308;
case 0x0c0aa30au: goto P_0c0aa30a;
case 0x0c0aa30cu: goto P_0c0aa30c;
case 0x0c0aa30eu: goto P_0c0aa30e;
case 0x0c0aa310u: goto P_0c0aa310;
case 0x0c0aa312u: goto P_0c0aa312;
case 0x0c0aa314u: goto P_0c0aa314;
case 0x0c0aa316u: goto P_0c0aa316;
case 0x0c0aa318u: goto P_0c0aa318;
case 0x0c0aa31au: goto P_0c0aa31a;
case 0x0c0aa31cu: goto P_0c0aa31c;
case 0x0c0aa31eu: goto P_0c0aa31e;
case 0x0c0aa320u: goto P_0c0aa320;
case 0x0c0aa322u: goto P_0c0aa322;
case 0x0c0aa324u: goto P_0c0aa324;
case 0x0c0aa326u: goto P_0c0aa326;
case 0x0c0aa328u: goto P_0c0aa328;
case 0x0c0aa32au: goto P_0c0aa32a;
case 0x0c0aa32cu: goto P_0c0aa32c;
case 0x0c0aa32eu: goto P_0c0aa32e;
case 0x0c0aa330u: goto P_0c0aa330;
case 0x0c0aa332u: goto P_0c0aa332;
case 0x0c0aa334u: goto P_0c0aa334;
case 0x0c0aa336u: goto P_0c0aa336;
case 0x0c0aa338u: goto P_0c0aa338;
case 0x0c0aa33au: goto P_0c0aa33a;
case 0x0c0aa33cu: goto P_0c0aa33c;
case 0x0c0aa33eu: goto P_0c0aa33e;
case 0x0c0aa340u: goto P_0c0aa340;
case 0x0c0aa342u: goto P_0c0aa342;
case 0x0c0aa344u: goto P_0c0aa344;
case 0x0c0aa346u: goto P_0c0aa346;
case 0x0c0aa348u: goto P_0c0aa348;
case 0x0c0aa34au: goto P_0c0aa34a;
case 0x0c0aa34cu: goto P_0c0aa34c;
case 0x0c0aa34eu: goto P_0c0aa34e;
case 0x0c0aa350u: goto P_0c0aa350;
case 0x0c0aa352u: goto P_0c0aa352;
case 0x0c0aa354u: goto P_0c0aa354;
case 0x0c0aa356u: goto P_0c0aa356;
case 0x0c0aa358u: goto P_0c0aa358;
case 0x0c0aa35au: goto P_0c0aa35a;
case 0x0c0aa35cu: goto P_0c0aa35c;
case 0x0c0aa35eu: goto P_0c0aa35e;
case 0x0c0aa360u: goto P_0c0aa360;
case 0x0c0aa362u: goto P_0c0aa362;
case 0x0c0aa364u: goto P_0c0aa364;
case 0x0c0aa380u: goto P_0c0aa380;
case 0x0c0aa382u: goto P_0c0aa382;
case 0x0c0aa384u: goto P_0c0aa384;
case 0x0c0aa386u: goto P_0c0aa386;
case 0x0c0aa388u: goto P_0c0aa388;
case 0x0c0aa38au: goto P_0c0aa38a;
case 0x0c0aa38cu: goto P_0c0aa38c;
case 0x0c0aa38eu: goto P_0c0aa38e;
case 0x0c0aa390u: goto P_0c0aa390;
case 0x0c0aa392u: goto P_0c0aa392;
case 0x0c0aa394u: goto P_0c0aa394;
case 0x0c0aa396u: goto P_0c0aa396;
case 0x0c0aa398u: goto P_0c0aa398;
case 0x0c0aa39au: goto P_0c0aa39a;
case 0x0c0aa39cu: goto P_0c0aa39c;
case 0x0c0aa39eu: goto P_0c0aa39e;
case 0x0c0aa3a0u: goto P_0c0aa3a0;
case 0x0c0aa3a2u: goto P_0c0aa3a2;
case 0x0c0aa3a4u: goto P_0c0aa3a4;
case 0x0c0aa3a6u: goto P_0c0aa3a6;
case 0x0c0aa3a8u: goto P_0c0aa3a8;
case 0x0c0aa3aau: goto P_0c0aa3aa;
case 0x0c0aa3acu: goto P_0c0aa3ac;
case 0x0c0aa3aeu: goto P_0c0aa3ae;
case 0x0c0aa3b0u: goto P_0c0aa3b0;
case 0x0c0aa3b2u: goto P_0c0aa3b2;
case 0x0c0aa3b4u: goto P_0c0aa3b4;
case 0x0c0aa3b6u: goto P_0c0aa3b6;
case 0x0c0aa3b8u: goto P_0c0aa3b8;
case 0x0c0aa3bau: goto P_0c0aa3ba;
case 0x0c0aa3bcu: goto P_0c0aa3bc;
case 0x0c0aa3beu: goto P_0c0aa3be;
case 0x0c0aa3c0u: goto P_0c0aa3c0;
case 0x0c0aa3c2u: goto P_0c0aa3c2;
case 0x0c0aa3c4u: goto P_0c0aa3c4;
case 0x0c0aa3c6u: goto P_0c0aa3c6;
case 0x0c0aa3c8u: goto P_0c0aa3c8;
case 0x0c0aa3cau: goto P_0c0aa3ca;
case 0x0c0aa3ccu: goto P_0c0aa3cc;
case 0x0c0aa3ceu: goto P_0c0aa3ce;
case 0x0c0aa3d0u: goto P_0c0aa3d0;
case 0x0c0aa3d2u: goto P_0c0aa3d2;
case 0x0c0aa3d4u: goto P_0c0aa3d4;
case 0x0c0aa3d6u: goto P_0c0aa3d6;
case 0x0c0aa3d8u: goto P_0c0aa3d8;
case 0x0c0aa3dau: goto P_0c0aa3da;
case 0x0c0aa3dcu: goto P_0c0aa3dc;
case 0x0c0aa3deu: goto P_0c0aa3de;
case 0x0c0aa3e0u: goto P_0c0aa3e0;
case 0x0c0aa3e2u: goto P_0c0aa3e2;
case 0x0c0aa3e4u: goto P_0c0aa3e4;
case 0x0c0aa3e6u: goto P_0c0aa3e6;
case 0x0c0aa3e8u: goto P_0c0aa3e8;
case 0x0c0aa3eau: goto P_0c0aa3ea;
case 0x0c0aa3ecu: goto P_0c0aa3ec;
case 0x0c0aa3eeu: goto P_0c0aa3ee;
case 0x0c0aa3f0u: goto P_0c0aa3f0;
case 0x0c0aa3f2u: goto P_0c0aa3f2;
case 0x0c0aa3f4u: goto P_0c0aa3f4;
case 0x0c0aa3f6u: goto P_0c0aa3f6;
case 0x0c0aa3f8u: goto P_0c0aa3f8;
case 0x0c0ad178u: goto P_0c0ad178;
case 0x0c0ad17au: goto P_0c0ad17a;
case 0x0c0ad17cu: goto P_0c0ad17c;
case 0x0c0ad17eu: goto P_0c0ad17e;
case 0x0c0ad180u: goto P_0c0ad180;
case 0x0c0ad182u: goto P_0c0ad182;
case 0x0c0ad184u: goto P_0c0ad184;
case 0x0c0ad186u: goto P_0c0ad186;
case 0x0c0ad188u: goto P_0c0ad188;
case 0x0c0ad18au: goto P_0c0ad18a;
case 0x0c0ad18cu: goto P_0c0ad18c;
case 0x0c0ad18eu: goto P_0c0ad18e;
case 0x0c0ad190u: goto P_0c0ad190;
case 0x0c0ad192u: goto P_0c0ad192;
case 0x0c0ad194u: goto P_0c0ad194;
case 0x0c0ad196u: goto P_0c0ad196;
case 0x0c0ad198u: goto P_0c0ad198;
case 0x0c0ad19au: goto P_0c0ad19a;
case 0x0c0ad19cu: goto P_0c0ad19c;
case 0x0c0ad19eu: goto P_0c0ad19e;
case 0x0c0ad1a0u: goto P_0c0ad1a0;
case 0x0c0ad1a2u: goto P_0c0ad1a2;
case 0x0c0ad1a4u: goto P_0c0ad1a4;
case 0x0c0ad1a6u: goto P_0c0ad1a6;
case 0x0c0ad1a8u: goto P_0c0ad1a8;
case 0x0c0ad1aau: goto P_0c0ad1aa;
case 0x0c0ad1acu: goto P_0c0ad1ac;
case 0x0c0ad1aeu: goto P_0c0ad1ae;
case 0x0c0ad1b0u: goto P_0c0ad1b0;
case 0x0c0ad1b2u: goto P_0c0ad1b2;
case 0x0c0ad1b4u: goto P_0c0ad1b4;
case 0x0c0ad1b6u: goto P_0c0ad1b6;
case 0x0c0ad1b8u: goto P_0c0ad1b8;
case 0x0c0ad1bau: goto P_0c0ad1ba;
case 0x0c0ad1bcu: goto P_0c0ad1bc;
case 0x0c0ad1beu: goto P_0c0ad1be;
case 0x0c0ad1c0u: goto P_0c0ad1c0;
case 0x0c0ad1c2u: goto P_0c0ad1c2;
case 0x0c0ad1c4u: goto P_0c0ad1c4;
case 0x0c0ad1c6u: goto P_0c0ad1c6;
case 0x0c0ad1c8u: goto P_0c0ad1c8;
case 0x0c0ad1cau: goto P_0c0ad1ca;
case 0x0c0ad1ccu: goto P_0c0ad1cc;
case 0x0c0ad1ceu: goto P_0c0ad1ce;
case 0x0c0ad1d0u: goto P_0c0ad1d0;
case 0x0c0ad1d2u: goto P_0c0ad1d2;
case 0x0c0ad1d4u: goto P_0c0ad1d4;
case 0x0c0ad1d6u: goto P_0c0ad1d6;
case 0x0c0ad1d8u: goto P_0c0ad1d8;
case 0x0c0ad1dau: goto P_0c0ad1da;
case 0x0c0ad1dcu: goto P_0c0ad1dc;
case 0x0c0ad1deu: goto P_0c0ad1de;
case 0x0c0ad1e0u: goto P_0c0ad1e0;
case 0x0c0ad1e2u: goto P_0c0ad1e2;
case 0x0c0ad1e4u: goto P_0c0ad1e4;
case 0x0c0ad1e6u: goto P_0c0ad1e6;
case 0x0c0ad1e8u: goto P_0c0ad1e8;
case 0x0c0ad1eau: goto P_0c0ad1ea;
case 0x0c0ad1ecu: goto P_0c0ad1ec;
case 0x0c0ad1eeu: goto P_0c0ad1ee;
case 0x0c0ad1f0u: goto P_0c0ad1f0;
case 0x0c0ad1f2u: goto P_0c0ad1f2;
case 0x0c0ad1f4u: goto P_0c0ad1f4;
case 0x0c0ad1f6u: goto P_0c0ad1f6;
case 0x0c0ad1f8u: goto P_0c0ad1f8;
case 0x0c0ad1fau: goto P_0c0ad1fa;
case 0x0c0ad1fcu: goto P_0c0ad1fc;
case 0x0c0ad1feu: goto P_0c0ad1fe;
case 0x0c0ad200u: goto P_0c0ad200;
case 0x0c0ad202u: goto P_0c0ad202;
case 0x0c0ad204u: goto P_0c0ad204;
case 0x0c0ad206u: goto P_0c0ad206;
case 0x0c0ad208u: goto P_0c0ad208;
case 0x0c0ad20au: goto P_0c0ad20a;
case 0x0c0ad20cu: goto P_0c0ad20c;
case 0x0c0ad20eu: goto P_0c0ad20e;
case 0x0c0ad210u: goto P_0c0ad210;
case 0x0c0ad212u: goto P_0c0ad212;
case 0x0c0ad214u: goto P_0c0ad214;
case 0x0c0ad216u: goto P_0c0ad216;
case 0x0c0ad218u: goto P_0c0ad218;
case 0x0c0ad21au: goto P_0c0ad21a;
case 0x0c0ad21cu: goto P_0c0ad21c;
case 0x0c0ad21eu: goto P_0c0ad21e;
case 0x0c0ad220u: goto P_0c0ad220;
case 0x0c0ad222u: goto P_0c0ad222;
case 0x0c0ad224u: goto P_0c0ad224;
case 0x0c0ad226u: goto P_0c0ad226;
case 0x0c0ad228u: goto P_0c0ad228;
case 0x0c0ad22au: goto P_0c0ad22a;
case 0x0c0ad22cu: goto P_0c0ad22c;
case 0x0c0ad22eu: goto P_0c0ad22e;
case 0x0c0ad230u: goto P_0c0ad230;
case 0x0c0ad232u: goto P_0c0ad232;
case 0x0c0ad234u: goto P_0c0ad234;
case 0x0c0ad236u: goto P_0c0ad236;
case 0x0c0ad238u: goto P_0c0ad238;
case 0x0c0ad26cu: goto P_0c0ad26c;
case 0x0c0ad26eu: goto P_0c0ad26e;
case 0x0c0ad270u: goto P_0c0ad270;
case 0x0c0ad272u: goto P_0c0ad272;
case 0x0c0ad274u: goto P_0c0ad274;
case 0x0c0ad276u: goto P_0c0ad276;
case 0x0c0ad278u: goto P_0c0ad278;
case 0x0c0ad27au: goto P_0c0ad27a;
case 0x0c0ad27cu: goto P_0c0ad27c;
case 0x0c0ad27eu: goto P_0c0ad27e;
case 0x0c0ad280u: goto P_0c0ad280;
case 0x0c0ad282u: goto P_0c0ad282;
case 0x0c0ad284u: goto P_0c0ad284;
case 0x0c0ad286u: goto P_0c0ad286;
case 0x0c0ad288u: goto P_0c0ad288;
case 0x0c0ad28au: goto P_0c0ad28a;
case 0x0c0ad28cu: goto P_0c0ad28c;
case 0x0c0ad28eu: goto P_0c0ad28e;
case 0x0c0ad290u: goto P_0c0ad290;
case 0x0c0ad292u: goto P_0c0ad292;
case 0x0c0ad294u: goto P_0c0ad294;
case 0x0c0ad296u: goto P_0c0ad296;
case 0x0c0ad298u: goto P_0c0ad298;
case 0x0c0ad29au: goto P_0c0ad29a;
case 0x0c0ad29cu: goto P_0c0ad29c;
case 0x0c0ad29eu: goto P_0c0ad29e;
case 0x0c0ad2a0u: goto P_0c0ad2a0;
case 0x0c0ad2a2u: goto P_0c0ad2a2;
case 0x0c0ad2a4u: goto P_0c0ad2a4;
case 0x0c0ad2a6u: goto P_0c0ad2a6;
case 0x0c0ad2a8u: goto P_0c0ad2a8;
case 0x0c0ad2aau: goto P_0c0ad2aa;
case 0x0c0ad2acu: goto P_0c0ad2ac;
case 0x0c0ad2aeu: goto P_0c0ad2ae;
case 0x0c0ad2b0u: goto P_0c0ad2b0;
case 0x0c0ad2b2u: goto P_0c0ad2b2;
case 0x0c0ad2b4u: goto P_0c0ad2b4;
case 0x0c0ad2b6u: goto P_0c0ad2b6;
case 0x0c0ad2b8u: goto P_0c0ad2b8;
case 0x0c0ad2bau: goto P_0c0ad2ba;
case 0x0c0ad2bcu: goto P_0c0ad2bc;
case 0x0c0ad2beu: goto P_0c0ad2be;
case 0x0c0ad2c0u: goto P_0c0ad2c0;
case 0x0c0ad2c2u: goto P_0c0ad2c2;
case 0x0c0ad2c4u: goto P_0c0ad2c4;
case 0x0c0ad2c6u: goto P_0c0ad2c6;
case 0x0c0ad2c8u: goto P_0c0ad2c8;
case 0x0c0ad2cau: goto P_0c0ad2ca;
case 0x0c0ad2ccu: goto P_0c0ad2cc;
case 0x0c0ad2ceu: goto P_0c0ad2ce;
case 0x0c0ad2d0u: goto P_0c0ad2d0;
case 0x0c0ad2d2u: goto P_0c0ad2d2;
case 0x0c0ad2d4u: goto P_0c0ad2d4;
case 0x0c0ad2d6u: goto P_0c0ad2d6;
case 0x0c0ad2d8u: goto P_0c0ad2d8;
case 0x0c0ad2dau: goto P_0c0ad2da;
case 0x0c0ad2dcu: goto P_0c0ad2dc;
case 0x0c0ad2deu: goto P_0c0ad2de;
case 0x0c0ad2e0u: goto P_0c0ad2e0;
case 0x0c0ad2e2u: goto P_0c0ad2e2;
case 0x0c0ad2e4u: goto P_0c0ad2e4;
case 0x0c0ad2e6u: goto P_0c0ad2e6;
case 0x0c0ad2e8u: goto P_0c0ad2e8;
case 0x0c0ad2eau: goto P_0c0ad2ea;
case 0x0c0ad2ecu: goto P_0c0ad2ec;
case 0x0c0ad2eeu: goto P_0c0ad2ee;
case 0x0c0ad2f0u: goto P_0c0ad2f0;
case 0x0c0ad2f2u: goto P_0c0ad2f2;
case 0x0c0ad2f4u: goto P_0c0ad2f4;
case 0x0c0ad2f6u: goto P_0c0ad2f6;
case 0x0c0ad2f8u: goto P_0c0ad2f8;
case 0x0c0ad2fau: goto P_0c0ad2fa;
case 0x0c0ad2fcu: goto P_0c0ad2fc;
case 0x0c0ad2feu: goto P_0c0ad2fe;
case 0x0c0ad300u: goto P_0c0ad300;
case 0x0c0ad302u: goto P_0c0ad302;
case 0x0c0ad304u: goto P_0c0ad304;
case 0x0c0ad306u: goto P_0c0ad306;
case 0x0c0ad308u: goto P_0c0ad308;
case 0x0c0ad30au: goto P_0c0ad30a;
case 0x0c0ad30cu: goto P_0c0ad30c;
case 0x0c0ad30eu: goto P_0c0ad30e;
case 0x0c0ad310u: goto P_0c0ad310;
case 0x0c0ad312u: goto P_0c0ad312;
case 0x0c0ad314u: goto P_0c0ad314;
case 0x0c0ad316u: goto P_0c0ad316;
case 0x0c0ad318u: goto P_0c0ad318;
case 0x0c0ad31au: goto P_0c0ad31a;
case 0x0c0ad31cu: goto P_0c0ad31c;
case 0x0c0ad31eu: goto P_0c0ad31e;
case 0x0c0ad320u: goto P_0c0ad320;
case 0x0c0ad322u: goto P_0c0ad322;
case 0x0c0ad324u: goto P_0c0ad324;
case 0x0c0ad326u: goto P_0c0ad326;
case 0x0c0ad328u: goto P_0c0ad328;
case 0x0c0ad32au: goto P_0c0ad32a;
case 0x0c0ad32cu: goto P_0c0ad32c;
case 0x0c0ad32eu: goto P_0c0ad32e;
case 0x0c0ad330u: goto P_0c0ad330;
case 0x0c0ad332u: goto P_0c0ad332;
case 0x0c0ad334u: goto P_0c0ad334;
case 0x0c0ad336u: goto P_0c0ad336;
case 0x0c0ad338u: goto P_0c0ad338;
case 0x0c0ad33au: goto P_0c0ad33a;
case 0x0c0ad33cu: goto P_0c0ad33c;
case 0x0c0ad33eu: goto P_0c0ad33e;
case 0x0c0ad340u: goto P_0c0ad340;
case 0x0c0ad342u: goto P_0c0ad342;
case 0x0c0ad344u: goto P_0c0ad344;
case 0x0c0ad346u: goto P_0c0ad346;
case 0x0c0ad348u: goto P_0c0ad348;
case 0x0c0ad34au: goto P_0c0ad34a;
case 0x0c0ad34cu: goto P_0c0ad34c;
case 0x0c0ad34eu: goto P_0c0ad34e;
case 0x0c0ad350u: goto P_0c0ad350;
case 0x0c0ad352u: goto P_0c0ad352;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0aa0aa: /* original 2fe6, guest PC 0x0c0aa0aa */
if(!s->budget--) { s->failed_pc=0x0c0aa0aau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aa0ac;
P_0c0aa0ac: /* original 6e63, guest PC 0x0c0aa0ac */
if(!s->budget--) { s->failed_pc=0x0c0aa0acu; return 0; }
r[14]=r[6];
goto P_0c0aa0ae;
P_0c0aa0ae: /* original 53e1, guest PC 0x0c0aa0ae */
if(!s->budget--) { s->failed_pc=0x0c0aa0aeu; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0aa0b0;
P_0c0aa0b0: /* original 7ffc, guest PC 0x0c0aa0b0 */
if(!s->budget--) { s->failed_pc=0x0c0aa0b0u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0aa0b2;
P_0c0aa0b2: /* original 62e2, guest PC 0x0c0aa0b2 */
if(!s->budget--) { s->failed_pc=0x0c0aa0b2u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0aa0b4;
P_0c0aa0b4: /* original e058, guest PC 0x0c0aa0b4 */
if(!s->budget--) { s->failed_pc=0x0c0aa0b4u; return 0; }
r[0]=0x00000058u;
goto P_0c0aa0b6;
P_0c0aa0b6: /* original 3230, guest PC 0x0c0aa0b6 */
if(!s->budget--) { s->failed_pc=0x0c0aa0b6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0aa0b8;
P_0c0aa0b8: /* original 8f0a, guest PC 0x0c0aa0b8 */
if(!s->budget--) { s->failed_pc=0x0c0aa0b8u; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[4]+r[0],4);
if(!cond) { goto P_0c0aa0d0; }
goto P_0c0aa0bc;
P_0c0aa0ba: /* original 054e, guest PC 0x0c0aa0ba */
if(!s->budget--) { s->failed_pc=0x0c0aa0bau; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0aa0bc;
P_0c0aa0bc: /* original 7f04, guest PC 0x0c0aa0bc */
if(!s->budget--) { s->failed_pc=0x0c0aa0bcu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aa0be;
P_0c0aa0be: /* original af74, guest PC 0x0c0aa0be */
if(!s->budget--) { s->failed_pc=0x0c0aa0beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a9faau,s,ram);
P_0c0aa0c0: /* original 6ef6, guest PC 0x0c0aa0c0 */
if(!s->budget--) { s->failed_pc=0x0c0aa0c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0aa0c2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aa0c2u; return 0; } return 1;
P_0c0aa0d0: /* original 752c, guest PC 0x0c0aa0d0 */
if(!s->budget--) { s->failed_pc=0x0c0aa0d0u; return 0; }
r[5]+=0x0000002cu;
goto P_0c0aa0d2;
P_0c0aa0d2: /* original 6251, guest PC 0x0c0aa0d2 */
if(!s->budget--) { s->failed_pc=0x0c0aa0d2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c0aa0d4;
P_0c0aa0d4: /* original 622d, guest PC 0x0c0aa0d4 */
if(!s->budget--) { s->failed_pc=0x0c0aa0d4u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0aa0d6;
P_0c0aa0d6: /* original 2f22, guest PC 0x0c0aa0d6 */
if(!s->budget--) { s->failed_pc=0x0c0aa0d6u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0aa0d8;
P_0c0aa0d8: /* original 7f04, guest PC 0x0c0aa0d8 */
if(!s->budget--) { s->failed_pc=0x0c0aa0d8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0aa0da;
P_0c0aa0da: /* original 56e2, guest PC 0x0c0aa0da */
if(!s->budget--) { s->failed_pc=0x0c0aa0dau; return 0; }
r[6]=read(ram,r[14]+8,4);
goto P_0c0aa0dc;
P_0c0aa0dc: /* original 6523, guest PC 0x0c0aa0dc */
if(!s->budget--) { s->failed_pc=0x0c0aa0dcu; return 0; }
r[5]=r[2];
goto P_0c0aa0de;
P_0c0aa0de: /* original a000, guest PC 0x0c0aa0de */
if(!s->budget--) { s->failed_pc=0x0c0aa0deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aa0e2;
P_0c0aa0e0: /* original 6ef6, guest PC 0x0c0aa0e0 */
if(!s->budget--) { s->failed_pc=0x0c0aa0e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aa0e2;
P_0c0aa0e2: /* original 2fe6, guest PC 0x0c0aa0e2 */
if(!s->budget--) { s->failed_pc=0x0c0aa0e2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aa0e4;
P_0c0aa0e4: /* original 6e43, guest PC 0x0c0aa0e4 */
if(!s->budget--) { s->failed_pc=0x0c0aa0e4u; return 0; }
r[14]=r[4];
goto P_0c0aa0e6;
P_0c0aa0e6: /* original 4f22, guest PC 0x0c0aa0e6 */
if(!s->budget--) { s->failed_pc=0x0c0aa0e6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aa0e8;
P_0c0aa0e8: /* original 7ffc, guest PC 0x0c0aa0e8 */
if(!s->budget--) { s->failed_pc=0x0c0aa0e8u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0aa0ea;
P_0c0aa0ea: /* original 2f62, guest PC 0x0c0aa0ea */
if(!s->budget--) { s->failed_pc=0x0c0aa0eau; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0aa0ec;
P_0c0aa0ec: /* original d333, guest PC 0x0c0aa0ec */
if(!s->budget--) { s->failed_pc=0x0c0aa0ecu; return 0; }
r[3]=read(ram,0x0c0aa1bcu,4);
goto P_0c0aa0ee;
P_0c0aa0ee: /* original 430b, guest PC 0x0c0aa0ee */
if(!s->budget--) { s->failed_pc=0x0c0aa0eeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0aa0f2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aa0f2u) { target=s->pc; goto dispatch; }
goto P_0c0aa0f2;
P_0c0aa0f0: /* original 64e3, guest PC 0x0c0aa0f0 */
if(!s->budget--) { s->failed_pc=0x0c0aa0f0u; return 0; }
r[4]=r[14];
goto P_0c0aa0f2;
P_0c0aa0f2: /* original 62f2, guest PC 0x0c0aa0f2 */
if(!s->budget--) { s->failed_pc=0x0c0aa0f2u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0aa0f4;
P_0c0aa0f4: /* original 7f04, guest PC 0x0c0aa0f4 */
if(!s->budget--) { s->failed_pc=0x0c0aa0f4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0aa0f6;
P_0c0aa0f6: /* original 4f26, guest PC 0x0c0aa0f6 */
if(!s->budget--) { s->failed_pc=0x0c0aa0f6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aa0f8;
P_0c0aa0f8: /* original 1e2e, guest PC 0x0c0aa0f8 */
if(!s->budget--) { s->failed_pc=0x0c0aa0f8u; return 0; }
write(ram,r[14]+56,r[2],4);
goto P_0c0aa0fa;
P_0c0aa0fa: /* original 64e3, guest PC 0x0c0aa0fa */
if(!s->budget--) { s->failed_pc=0x0c0aa0fau; return 0; }
r[4]=r[14];
goto P_0c0aa0fc;
P_0c0aa0fc: /* original af55, guest PC 0x0c0aa0fc */
if(!s->budget--) { s->failed_pc=0x0c0aa0fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a9faau,s,ram);
P_0c0aa0fe: /* original 6ef6, guest PC 0x0c0aa0fe */
if(!s->budget--) { s->failed_pc=0x0c0aa0feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0aa100u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aa100u; return 0; } return 1;
P_0c0aa1ec: /* original 2fe6, guest PC 0x0c0aa1ec */
if(!s->budget--) { s->failed_pc=0x0c0aa1ecu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aa1ee;
P_0c0aa1ee: /* original 6e43, guest PC 0x0c0aa1ee */
if(!s->budget--) { s->failed_pc=0x0c0aa1eeu; return 0; }
r[14]=r[4];
goto P_0c0aa1f0;
P_0c0aa1f0: /* original 2fd6, guest PC 0x0c0aa1f0 */
if(!s->budget--) { s->failed_pc=0x0c0aa1f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aa1f2;
P_0c0aa1f2: /* original e058, guest PC 0x0c0aa1f2 */
if(!s->budget--) { s->failed_pc=0x0c0aa1f2u; return 0; }
r[0]=0x00000058u;
goto P_0c0aa1f4;
P_0c0aa1f4: /* original 2fc6, guest PC 0x0c0aa1f4 */
if(!s->budget--) { s->failed_pc=0x0c0aa1f4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aa1f6;
P_0c0aa1f6: /* original 6d63, guest PC 0x0c0aa1f6 */
if(!s->budget--) { s->failed_pc=0x0c0aa1f6u; return 0; }
r[13]=r[6];
goto P_0c0aa1f8;
P_0c0aa1f8: /* original 2fb6, guest PC 0x0c0aa1f8 */
if(!s->budget--) { s->failed_pc=0x0c0aa1f8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aa1fa;
P_0c0aa1fa: /* original 66e3, guest PC 0x0c0aa1fa */
if(!s->budget--) { s->failed_pc=0x0c0aa1fau; return 0; }
r[6]=r[14];
goto P_0c0aa1fc;
P_0c0aa1fc: /* original 2fa6, guest PC 0x0c0aa1fc */
if(!s->budget--) { s->failed_pc=0x0c0aa1fcu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aa1fe;
P_0c0aa1fe: /* original 7638, guest PC 0x0c0aa1fe */
if(!s->budget--) { s->failed_pc=0x0c0aa1feu; return 0; }
r[6]+=0x00000038u;
goto P_0c0aa200;
P_0c0aa200: /* original 2f96, guest PC 0x0c0aa200 */
if(!s->budget--) { s->failed_pc=0x0c0aa200u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aa202;
P_0c0aa202: /* original e400, guest PC 0x0c0aa202 */
if(!s->budget--) { s->failed_pc=0x0c0aa202u; return 0; }
r[4]=0x00000000u;
goto P_0c0aa204;
P_0c0aa204: /* original 2f86, guest PC 0x0c0aa204 */
if(!s->budget--) { s->failed_pc=0x0c0aa204u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aa206;
P_0c0aa206: /* original 6b43, guest PC 0x0c0aa206 */
if(!s->budget--) { s->failed_pc=0x0c0aa206u; return 0; }
r[11]=r[4];
goto P_0c0aa208;
P_0c0aa208: /* original 4f22, guest PC 0x0c0aa208 */
if(!s->budget--) { s->failed_pc=0x0c0aa208u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aa20a;
P_0c0aa20a: /* original 7ffc, guest PC 0x0c0aa20a */
if(!s->budget--) { s->failed_pc=0x0c0aa20au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0aa20c;
P_0c0aa20c: /* original 2f52, guest PC 0x0c0aa20c */
if(!s->budget--) { s->failed_pc=0x0c0aa20cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0aa20e;
P_0c0aa20e: /* original 09ee, guest PC 0x0c0aa20e */
if(!s->budget--) { s->failed_pc=0x0c0aa20eu; return 0; }
r[9]=read(ram,r[14]+r[0],4);
goto P_0c0aa210;
P_0c0aa210: /* original e048, guest PC 0x0c0aa210 */
if(!s->budget--) { s->failed_pc=0x0c0aa210u; return 0; }
r[0]=0x00000048u;
goto P_0c0aa212;
P_0c0aa212: /* original 07ee, guest PC 0x0c0aa212 */
if(!s->budget--) { s->failed_pc=0x0c0aa212u; return 0; }
r[7]=read(ram,r[14]+r[0],4);
goto P_0c0aa214;
P_0c0aa214: /* original 8463, guest PC 0x0c0aa214 */
if(!s->budget--) { s->failed_pc=0x0c0aa214u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+3,1);
goto P_0c0aa216;
P_0c0aa216: /* original 65d2, guest PC 0x0c0aa216 */
if(!s->budget--) { s->failed_pc=0x0c0aa216u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0aa218;
P_0c0aa218: /* original da24, guest PC 0x0c0aa218 */
if(!s->budget--) { s->failed_pc=0x0c0aa218u; return 0; }
r[10]=read(ram,0x0c0aa2acu,4);
goto P_0c0aa21a;
P_0c0aa21a: /* original 660c, guest PC 0x0c0aa21a */
if(!s->budget--) { s->failed_pc=0x0c0aa21au; return 0; }
r[6]=r[0]&255u;
goto P_0c0aa21c;
P_0c0aa21c: /* original 3560, guest PC 0x0c0aa21c */
if(!s->budget--) { s->failed_pc=0x0c0aa21cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c0aa21e;
P_0c0aa21e: /* original 8f20, guest PC 0x0c0aa21e */
if(!s->budget--) { s->failed_pc=0x0c0aa21eu; return 0; }
cond=r[17]&1u;
r[8]=0x00000001u;
if(!cond) { goto P_0c0aa262; }
goto P_0c0aa222;
P_0c0aa220: /* original e801, guest PC 0x0c0aa220 */
if(!s->budget--) { s->failed_pc=0x0c0aa220u; return 0; }
r[8]=0x00000001u;
goto P_0c0aa222;
P_0c0aa222: /* original d222, guest PC 0x0c0aa222 */
if(!s->budget--) { s->failed_pc=0x0c0aa222u; return 0; }
r[2]=read(ram,0x0c0aa2acu,4);
goto P_0c0aa224;
P_0c0aa224: /* original 2728, guest PC 0x0c0aa224 */
if(!s->budget--) { s->failed_pc=0x0c0aa224u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[2])==0)!=0);
goto P_0c0aa226;
P_0c0aa226: /* original 891c, guest PC 0x0c0aa226 */
if(!s->budget--) { s->failed_pc=0x0c0aa226u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa262; }
goto P_0c0aa228;
P_0c0aa228: /* original e062, guest PC 0x0c0aa228 */
if(!s->budget--) { s->failed_pc=0x0c0aa228u; return 0; }
r[0]=0x00000062u;
goto P_0c0aa22a;
P_0c0aa22a: /* original 01ec, guest PC 0x0c0aa22a */
if(!s->budget--) { s->failed_pc=0x0c0aa22au; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0aa22c;
P_0c0aa22c: /* original 611c, guest PC 0x0c0aa22c */
if(!s->budget--) { s->failed_pc=0x0c0aa22cu; return 0; }
r[1]=r[1]&255u;
goto P_0c0aa22e;
P_0c0aa22e: /* original 4115, guest PC 0x0c0aa22e */
if(!s->budget--) { s->failed_pc=0x0c0aa22eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c0aa230;
P_0c0aa230: /* original 8907, guest PC 0x0c0aa230 */
if(!s->budget--) { s->failed_pc=0x0c0aa230u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa242; }
goto P_0c0aa232;
P_0c0aa232: /* original d21f, guest PC 0x0c0aa232 */
if(!s->budget--) { s->failed_pc=0x0c0aa232u; return 0; }
r[2]=read(ram,0x0c0aa2b0u,4);
goto P_0c0aa234;
P_0c0aa234: /* original 6b83, guest PC 0x0c0aa234 */
if(!s->budget--) { s->failed_pc=0x0c0aa234u; return 0; }
r[11]=r[8];
goto P_0c0aa236;
P_0c0aa236: /* original 54ee, guest PC 0x0c0aa236 */
if(!s->budget--) { s->failed_pc=0x0c0aa236u; return 0; }
r[4]=read(ram,r[14]+56,4);
goto P_0c0aa238;
P_0c0aa238: /* original 53d2, guest PC 0x0c0aa238 */
if(!s->budget--) { s->failed_pc=0x0c0aa238u; return 0; }
r[3]=read(ram,r[13]+8,4);
goto P_0c0aa23a;
P_0c0aa23a: /* original 2429, guest PC 0x0c0aa23a */
if(!s->budget--) { s->failed_pc=0x0c0aa23au; return 0; }
r[4]&=r[2];
goto P_0c0aa23c;
P_0c0aa23c: /* original 234b, guest PC 0x0c0aa23c */
if(!s->budget--) { s->failed_pc=0x0c0aa23cu; return 0; }
r[3]|=r[4];
goto P_0c0aa23e;
P_0c0aa23e: /* original a024, guest PC 0x0c0aa23e */
if(!s->budget--) { s->failed_pc=0x0c0aa23eu; return 0; }
write(ram,r[13]+8,r[3],4);
goto P_0c0aa28a;
P_0c0aa240: /* original 1d32, guest PC 0x0c0aa240 */
if(!s->budget--) { s->failed_pc=0x0c0aa240u; return 0; }
write(ram,r[13]+8,r[3],4);
goto P_0c0aa242;
P_0c0aa242: /* original 55d2, guest PC 0x0c0aa242 */
if(!s->budget--) { s->failed_pc=0x0c0aa242u; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0aa244;
P_0c0aa244: /* original 655d, guest PC 0x0c0aa244 */
if(!s->budget--) { s->failed_pc=0x0c0aa244u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0aa246;
P_0c0aa246: /* original 2558, guest PC 0x0c0aa246 */
if(!s->budget--) { s->failed_pc=0x0c0aa246u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0aa248;
P_0c0aa248: /* original 8b01, guest PC 0x0c0aa248 */
if(!s->budget--) { s->failed_pc=0x0c0aa248u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aa24e; }
goto P_0c0aa24a;
P_0c0aa24a: /* original a0cb, guest PC 0x0c0aa24a */
if(!s->budget--) { s->failed_pc=0x0c0aa24au; return 0; }
goto P_0c0aa3e4;
P_0c0aa24c: /* original 0009, guest PC 0x0c0aa24c */
if(!s->budget--) { s->failed_pc=0x0c0aa24cu; return 0; }
goto P_0c0aa24e;
P_0c0aa24e: /* original 53d2, guest PC 0x0c0aa24e */
if(!s->budget--) { s->failed_pc=0x0c0aa24eu; return 0; }
r[3]=read(ram,r[13]+8,4);
goto P_0c0aa250;
P_0c0aa250: /* original 2a38, guest PC 0x0c0aa250 */
if(!s->budget--) { s->failed_pc=0x0c0aa250u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[3])==0)!=0);
goto P_0c0aa252;
P_0c0aa252: /* original 8901, guest PC 0x0c0aa252 */
if(!s->budget--) { s->failed_pc=0x0c0aa252u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa258; }
goto P_0c0aa254;
P_0c0aa254: /* original a0b3, guest PC 0x0c0aa254 */
if(!s->budget--) { s->failed_pc=0x0c0aa254u; return 0; }
goto P_0c0aa3be;
P_0c0aa256: /* original 0009, guest PC 0x0c0aa256 */
if(!s->budget--) { s->failed_pc=0x0c0aa256u; return 0; }
goto P_0c0aa258;
P_0c0aa258: /* original d316, guest PC 0x0c0aa258 */
if(!s->budget--) { s->failed_pc=0x0c0aa258u; return 0; }
r[3]=read(ram,0x0c0aa2b4u,4);
goto P_0c0aa25a;
P_0c0aa25a: /* original 430b, guest PC 0x0c0aa25a */
if(!s->budget--) { s->failed_pc=0x0c0aa25au; return 0; }
target=r[3];
r[16]=code_base|0x0c0aa25eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aa25eu) { target=s->pc; goto dispatch; }
goto P_0c0aa25e;
P_0c0aa25c: /* original 64e3, guest PC 0x0c0aa25c */
if(!s->budget--) { s->failed_pc=0x0c0aa25cu; return 0; }
r[4]=r[14];
goto P_0c0aa25e;
P_0c0aa25e: /* original a0bf, guest PC 0x0c0aa25e */
if(!s->budget--) { s->failed_pc=0x0c0aa25eu; return 0; }
goto P_0c0aa3e0;
P_0c0aa260: /* original 0009, guest PC 0x0c0aa260 */
if(!s->budget--) { s->failed_pc=0x0c0aa260u; return 0; }
goto P_0c0aa262;
P_0c0aa262: /* original e03c, guest PC 0x0c0aa262 */
if(!s->budget--) { s->failed_pc=0x0c0aa262u; return 0; }
r[0]=0x0000003cu;
goto P_0c0aa264;
P_0c0aa264: /* original 0e45, guest PC 0x0c0aa264 */
if(!s->budget--) { s->failed_pc=0x0c0aa264u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0aa266;
P_0c0aa266: /* original e062, guest PC 0x0c0aa266 */
if(!s->budget--) { s->failed_pc=0x0c0aa266u; return 0; }
r[0]=0x00000062u;
goto P_0c0aa268;
P_0c0aa268: /* original 0e44, guest PC 0x0c0aa268 */
if(!s->budget--) { s->failed_pc=0x0c0aa268u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0aa26a;
P_0c0aa26a: /* original d313, guest PC 0x0c0aa26a */
if(!s->budget--) { s->failed_pc=0x0c0aa26au; return 0; }
r[3]=read(ram,0x0c0aa2b8u,4);
goto P_0c0aa26c;
P_0c0aa26c: /* original 52d2, guest PC 0x0c0aa26c */
if(!s->budget--) { s->failed_pc=0x0c0aa26cu; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c0aa26e;
P_0c0aa26e: /* original 2238, guest PC 0x0c0aa26e */
if(!s->budget--) { s->failed_pc=0x0c0aa26eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aa270;
P_0c0aa270: /* original 8901, guest PC 0x0c0aa270 */
if(!s->budget--) { s->failed_pc=0x0c0aa270u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa276; }
goto P_0c0aa272;
P_0c0aa272: /* original a008, guest PC 0x0c0aa272 */
if(!s->budget--) { s->failed_pc=0x0c0aa272u; return 0; }
fr[4]=0x3f800000u;
goto P_0c0aa286;
P_0c0aa274: /* original f49d, guest PC 0x0c0aa274 */
if(!s->budget--) { s->failed_pc=0x0c0aa274u; return 0; }
fr[4]=0x3f800000u;
goto P_0c0aa276;
P_0c0aa276: /* original 51d2, guest PC 0x0c0aa276 */
if(!s->budget--) { s->failed_pc=0x0c0aa276u; return 0; }
r[1]=read(ram,r[13]+8,4);
goto P_0c0aa278;
P_0c0aa278: /* original d210, guest PC 0x0c0aa278 */
if(!s->budget--) { s->failed_pc=0x0c0aa278u; return 0; }
r[2]=read(ram,0x0c0aa2bcu,4);
goto P_0c0aa27a;
P_0c0aa27a: /* original 2128, guest PC 0x0c0aa27a */
if(!s->budget--) { s->failed_pc=0x0c0aa27au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0aa27c;
P_0c0aa27c: /* original 8902, guest PC 0x0c0aa27c */
if(!s->budget--) { s->failed_pc=0x0c0aa27cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa284; }
goto P_0c0aa27e;
P_0c0aa27e: /* original c710, guest PC 0x0c0aa27e */
if(!s->budget--) { s->failed_pc=0x0c0aa27eu; return 0; }
r[0]=code_base|0x000aa2c0u;
goto P_0c0aa280;
P_0c0aa280: /* original a001, guest PC 0x0c0aa280 */
if(!s->budget--) { s->failed_pc=0x0c0aa280u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0aa286;
P_0c0aa282: /* original f408, guest PC 0x0c0aa282 */
if(!s->budget--) { s->failed_pc=0x0c0aa282u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0aa284;
P_0c0aa284: /* original f48d, guest PC 0x0c0aa284 */
if(!s->budget--) { s->failed_pc=0x0c0aa284u; return 0; }
fr[4]=0;
goto P_0c0aa286;
P_0c0aa286: /* original 900f, guest PC 0x0c0aa286 */
if(!s->budget--) { s->failed_pc=0x0c0aa286u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa2a8u,2);
goto P_0c0aa288;
P_0c0aa288: /* original fe47, guest PC 0x0c0aa288 */
if(!s->budget--) { s->failed_pc=0x0c0aa288u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0aa28a;
P_0c0aa28a: /* original 52d2, guest PC 0x0c0aa28a */
if(!s->budget--) { s->failed_pc=0x0c0aa28au; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c0aa28c;
P_0c0aa28c: /* original e054, guest PC 0x0c0aa28c */
if(!s->budget--) { s->failed_pc=0x0c0aa28cu; return 0; }
r[0]=0x00000054u;
goto P_0c0aa28e;
P_0c0aa28e: /* original d30d, guest PC 0x0c0aa28e */
if(!s->budget--) { s->failed_pc=0x0c0aa28eu; return 0; }
r[3]=read(ram,0x0c0aa2c4u,4);
goto P_0c0aa290;
P_0c0aa290: /* original 2238, guest PC 0x0c0aa290 */
if(!s->budget--) { s->failed_pc=0x0c0aa290u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aa292;
P_0c0aa292: /* original 8d19, guest PC 0x0c0aa292 */
if(!s->budget--) { s->failed_pc=0x0c0aa292u; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[14]+r[0],4);
if(cond) { goto P_0c0aa2c8; }
goto P_0c0aa296;
P_0c0aa294: /* original 05ee, guest PC 0x0c0aa294 */
if(!s->budget--) { s->failed_pc=0x0c0aa294u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0aa296;
P_0c0aa296: /* original e021, guest PC 0x0c0aa296 */
if(!s->budget--) { s->failed_pc=0x0c0aa296u; return 0; }
r[0]=0x00000021u;
goto P_0c0aa298;
P_0c0aa298: /* original 045c, guest PC 0x0c0aa298 */
if(!s->budget--) { s->failed_pc=0x0c0aa298u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0aa29a;
P_0c0aa29a: /* original 6243, guest PC 0x0c0aa29a */
if(!s->budget--) { s->failed_pc=0x0c0aa29au; return 0; }
r[2]=r[4];
goto P_0c0aa29c;
P_0c0aa29c: /* original 4400, guest PC 0x0c0aa29c */
if(!s->budget--) { s->failed_pc=0x0c0aa29cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0aa29e;
P_0c0aa29e: /* original 342c, guest PC 0x0c0aa29e */
if(!s->budget--) { s->failed_pc=0x0c0aa29eu; return 0; }
r[4]+=r[2];
goto P_0c0aa2a0;
P_0c0aa2a0: /* original a014, guest PC 0x0c0aa2a0 */
if(!s->budget--) { s->failed_pc=0x0c0aa2a0u; return 0; }
r[4]>>=2;
goto P_0c0aa2cc;
P_0c0aa2a2: /* original 4409, guest PC 0x0c0aa2a2 */
if(!s->budget--) { s->failed_pc=0x0c0aa2a2u; return 0; }
r[4]>>=2;
if(!vf3_matrix_family(0x0c0aa2a4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aa2a4u; return 0; } return 1;
P_0c0aa2c8: /* original e020, guest PC 0x0c0aa2c8 */
if(!s->budget--) { s->failed_pc=0x0c0aa2c8u; return 0; }
r[0]=0x00000020u;
goto P_0c0aa2ca;
P_0c0aa2ca: /* original 045c, guest PC 0x0c0aa2ca */
if(!s->budget--) { s->failed_pc=0x0c0aa2cau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0aa2cc;
P_0c0aa2cc: /* original 904b, guest PC 0x0c0aa2cc */
if(!s->budget--) { s->failed_pc=0x0c0aa2ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa366u,2);
goto P_0c0aa2ce;
P_0c0aa2ce: /* original 0e44, guest PC 0x0c0aa2ce */
if(!s->budget--) { s->failed_pc=0x0c0aa2ceu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0aa2d0;
P_0c0aa2d0: /* original 5cd2, guest PC 0x0c0aa2d0 */
if(!s->budget--) { s->failed_pc=0x0c0aa2d0u; return 0; }
r[12]=read(ram,r[13]+8,4);
goto P_0c0aa2d2;
P_0c0aa2d2: /* original 6ccd, guest PC 0x0c0aa2d2 */
if(!s->budget--) { s->failed_pc=0x0c0aa2d2u; return 0; }
r[12]=r[12]&65535u;
goto P_0c0aa2d4;
P_0c0aa2d4: /* original 2cc8, guest PC 0x0c0aa2d4 */
if(!s->budget--) { s->failed_pc=0x0c0aa2d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0aa2d6;
P_0c0aa2d6: /* original 8912, guest PC 0x0c0aa2d6 */
if(!s->budget--) { s->failed_pc=0x0c0aa2d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa2fe; }
goto P_0c0aa2d8;
P_0c0aa2d8: /* original d224, guest PC 0x0c0aa2d8 */
if(!s->budget--) { s->failed_pc=0x0c0aa2d8u; return 0; }
r[2]=read(ram,0x0c0aa36cu,4);
goto P_0c0aa2da;
P_0c0aa2da: /* original e503, guest PC 0x0c0aa2da */
if(!s->budget--) { s->failed_pc=0x0c0aa2dau; return 0; }
r[5]=0x00000003u;
goto P_0c0aa2dc;
P_0c0aa2dc: /* original 420b, guest PC 0x0c0aa2dc */
if(!s->budget--) { s->failed_pc=0x0c0aa2dcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0aa2e0u;
r[4]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aa2e0u) { target=s->pc; goto dispatch; }
goto P_0c0aa2e0;
P_0c0aa2de: /* original 54d2, guest PC 0x0c0aa2de */
if(!s->budget--) { s->failed_pc=0x0c0aa2deu; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c0aa2e0;
P_0c0aa2e0: /* original 6403, guest PC 0x0c0aa2e0 */
if(!s->budget--) { s->failed_pc=0x0c0aa2e0u; return 0; }
r[4]=r[0];
goto P_0c0aa2e2;
P_0c0aa2e2: /* original 8442, guest PC 0x0c0aa2e2 */
if(!s->budget--) { s->failed_pc=0x0c0aa2e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c0aa2e4;
P_0c0aa2e4: /* original d322, guest PC 0x0c0aa2e4 */
if(!s->budget--) { s->failed_pc=0x0c0aa2e4u; return 0; }
r[3]=read(ram,0x0c0aa370u,4);
goto P_0c0aa2e6;
P_0c0aa2e6: /* original 600c, guest PC 0x0c0aa2e6 */
if(!s->budget--) { s->failed_pc=0x0c0aa2e6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aa2e8;
P_0c0aa2e8: /* original 4018, guest PC 0x0c0aa2e8 */
if(!s->budget--) { s->failed_pc=0x0c0aa2e8u; return 0; }
r[0]<<=8;
goto P_0c0aa2ea;
P_0c0aa2ea: /* original 2039, guest PC 0x0c0aa2ea */
if(!s->budget--) { s->failed_pc=0x0c0aa2eau; return 0; }
r[0]&=r[3];
goto P_0c0aa2ec;
P_0c0aa2ec: /* original 6203, guest PC 0x0c0aa2ec */
if(!s->budget--) { s->failed_pc=0x0c0aa2ecu; return 0; }
r[2]=r[0];
goto P_0c0aa2ee;
P_0c0aa2ee: /* original 8441, guest PC 0x0c0aa2ee */
if(!s->budget--) { s->failed_pc=0x0c0aa2eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c0aa2f0;
P_0c0aa2f0: /* original 6423, guest PC 0x0c0aa2f0 */
if(!s->budget--) { s->failed_pc=0x0c0aa2f0u; return 0; }
r[4]=r[2];
goto P_0c0aa2f2;
P_0c0aa2f2: /* original 600c, guest PC 0x0c0aa2f2 */
if(!s->budget--) { s->failed_pc=0x0c0aa2f2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aa2f4;
P_0c0aa2f4: /* original 240b, guest PC 0x0c0aa2f4 */
if(!s->budget--) { s->failed_pc=0x0c0aa2f4u; return 0; }
r[4]|=r[0];
goto P_0c0aa2f6;
P_0c0aa2f6: /* original 2448, guest PC 0x0c0aa2f6 */
if(!s->budget--) { s->failed_pc=0x0c0aa2f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0aa2f8;
P_0c0aa2f8: /* original 8b15, guest PC 0x0c0aa2f8 */
if(!s->budget--) { s->failed_pc=0x0c0aa2f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aa326; }
goto P_0c0aa2fa;
P_0c0aa2fa: /* original e302, guest PC 0x0c0aa2fa */
if(!s->budget--) { s->failed_pc=0x0c0aa2fau; return 0; }
r[3]=0x00000002u;
goto P_0c0aa2fc;
P_0c0aa2fc: /* original 2b3b, guest PC 0x0c0aa2fc */
if(!s->budget--) { s->failed_pc=0x0c0aa2fcu; return 0; }
r[11]|=r[3];
goto P_0c0aa2fe;
P_0c0aa2fe: /* original 52d2, guest PC 0x0c0aa2fe */
if(!s->budget--) { s->failed_pc=0x0c0aa2feu; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c0aa300;
P_0c0aa300: /* original d31c, guest PC 0x0c0aa300 */
if(!s->budget--) { s->failed_pc=0x0c0aa300u; return 0; }
r[3]=read(ram,0x0c0aa374u,4);
goto P_0c0aa302;
P_0c0aa302: /* original 2238, guest PC 0x0c0aa302 */
if(!s->budget--) { s->failed_pc=0x0c0aa302u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aa304;
P_0c0aa304: /* original 8b04, guest PC 0x0c0aa304 */
if(!s->budget--) { s->failed_pc=0x0c0aa304u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aa310; }
goto P_0c0aa306;
P_0c0aa306: /* original 6c93, guest PC 0x0c0aa306 */
if(!s->budget--) { s->failed_pc=0x0c0aa306u; return 0; }
r[12]=r[9];
goto P_0c0aa308;
P_0c0aa308: /* original 7c48, guest PC 0x0c0aa308 */
if(!s->budget--) { s->failed_pc=0x0c0aa308u; return 0; }
r[12]+=0x00000048u;
goto P_0c0aa30a;
P_0c0aa30a: /* original 6cc1, guest PC 0x0c0aa30a */
if(!s->budget--) { s->failed_pc=0x0c0aa30au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[12]=tmp;
goto P_0c0aa30c;
P_0c0aa30c: /* original a00b, guest PC 0x0c0aa30c */
if(!s->budget--) { s->failed_pc=0x0c0aa30cu; return 0; }
r[12]=r[12]&65535u;
goto P_0c0aa326;
P_0c0aa30e: /* original 6ccd, guest PC 0x0c0aa30e */
if(!s->budget--) { s->failed_pc=0x0c0aa30eu; return 0; }
r[12]=r[12]&65535u;
goto P_0c0aa310;
P_0c0aa310: /* original 51d2, guest PC 0x0c0aa310 */
if(!s->budget--) { s->failed_pc=0x0c0aa310u; return 0; }
r[1]=read(ram,r[13]+8,4);
goto P_0c0aa312;
P_0c0aa312: /* original d219, guest PC 0x0c0aa312 */
if(!s->budget--) { s->failed_pc=0x0c0aa312u; return 0; }
r[2]=read(ram,0x0c0aa378u,4);
goto P_0c0aa314;
P_0c0aa314: /* original 2128, guest PC 0x0c0aa314 */
if(!s->budget--) { s->failed_pc=0x0c0aa314u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0aa316;
P_0c0aa316: /* original 8b02, guest PC 0x0c0aa316 */
if(!s->budget--) { s->failed_pc=0x0c0aa316u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aa31e; }
goto P_0c0aa318;
P_0c0aa318: /* original 6c93, guest PC 0x0c0aa318 */
if(!s->budget--) { s->failed_pc=0x0c0aa318u; return 0; }
r[12]=r[9];
goto P_0c0aa31a;
P_0c0aa31a: /* original a002, guest PC 0x0c0aa31a */
if(!s->budget--) { s->failed_pc=0x0c0aa31au; return 0; }
r[12]+=0x0000004eu;
goto P_0c0aa322;
P_0c0aa31c: /* original 7c4e, guest PC 0x0c0aa31c */
if(!s->budget--) { s->failed_pc=0x0c0aa31cu; return 0; }
r[12]+=0x0000004eu;
goto P_0c0aa31e;
P_0c0aa31e: /* original 6c93, guest PC 0x0c0aa31e */
if(!s->budget--) { s->failed_pc=0x0c0aa31eu; return 0; }
r[12]=r[9];
goto P_0c0aa320;
P_0c0aa320: /* original 7c50, guest PC 0x0c0aa320 */
if(!s->budget--) { s->failed_pc=0x0c0aa320u; return 0; }
r[12]+=0x00000050u;
goto P_0c0aa322;
P_0c0aa322: /* original 6cc1, guest PC 0x0c0aa322 */
if(!s->budget--) { s->failed_pc=0x0c0aa322u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[12]=tmp;
goto P_0c0aa324;
P_0c0aa324: /* original 6ccd, guest PC 0x0c0aa324 */
if(!s->budget--) { s->failed_pc=0x0c0aa324u; return 0; }
r[12]=r[12]&65535u;
goto P_0c0aa326;
P_0c0aa326: /* original e03c, guest PC 0x0c0aa326 */
if(!s->budget--) { s->failed_pc=0x0c0aa326u; return 0; }
r[0]=0x0000003cu;
goto P_0c0aa328;
P_0c0aa328: /* original 03ed, guest PC 0x0c0aa328 */
if(!s->budget--) { s->failed_pc=0x0c0aa328u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aa32a;
P_0c0aa32a: /* original 633d, guest PC 0x0c0aa32a */
if(!s->budget--) { s->failed_pc=0x0c0aa32au; return 0; }
r[3]=r[3]&65535u;
goto P_0c0aa32c;
P_0c0aa32c: /* original 3c30, guest PC 0x0c0aa32c */
if(!s->budget--) { s->failed_pc=0x0c0aa32cu; return 0; }
r[17]=(r[17]&~1u)|((r[12]==r[3])!=0);
goto P_0c0aa32e;
P_0c0aa32e: /* original 8929, guest PC 0x0c0aa32e */
if(!s->budget--) { s->failed_pc=0x0c0aa32eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa384; }
goto P_0c0aa330;
P_0c0aa330: /* original e03e, guest PC 0x0c0aa330 */
if(!s->budget--) { s->failed_pc=0x0c0aa330u; return 0; }
r[0]=0x0000003eu;
goto P_0c0aa332;
P_0c0aa332: /* original d312, guest PC 0x0c0aa332 */
if(!s->budget--) { s->failed_pc=0x0c0aa332u; return 0; }
r[3]=read(ram,0x0c0aa37cu,4);
goto P_0c0aa334;
P_0c0aa334: /* original 09ed, guest PC 0x0c0aa334 */
if(!s->budget--) { s->failed_pc=0x0c0aa334u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aa336;
P_0c0aa336: /* original 65c3, guest PC 0x0c0aa336 */
if(!s->budget--) { s->failed_pc=0x0c0aa336u; return 0; }
r[5]=r[12];
goto P_0c0aa338;
P_0c0aa338: /* original 699d, guest PC 0x0c0aa338 */
if(!s->budget--) { s->failed_pc=0x0c0aa338u; return 0; }
r[9]=r[9]&65535u;
goto P_0c0aa33a;
P_0c0aa33a: /* original 430b, guest PC 0x0c0aa33a */
if(!s->budget--) { s->failed_pc=0x0c0aa33au; return 0; }
target=r[3];
r[16]=code_base|0x0c0aa33eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aa33eu) { target=s->pc; goto dispatch; }
goto P_0c0aa33e;
P_0c0aa33c: /* original 64e3, guest PC 0x0c0aa33c */
if(!s->budget--) { s->failed_pc=0x0c0aa33cu; return 0; }
r[4]=r[14];
goto P_0c0aa33e;
P_0c0aa33e: /* original e048, guest PC 0x0c0aa33e */
if(!s->budget--) { s->failed_pc=0x0c0aa33eu; return 0; }
r[0]=0x00000048u;
goto P_0c0aa340;
P_0c0aa340: /* original 04ee, guest PC 0x0c0aa340 */
if(!s->budget--) { s->failed_pc=0x0c0aa340u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0aa342;
P_0c0aa342: /* original 24a8, guest PC 0x0c0aa342 */
if(!s->budget--) { s->failed_pc=0x0c0aa342u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[10])==0)!=0);
goto P_0c0aa344;
P_0c0aa344: /* original 8b05, guest PC 0x0c0aa344 */
if(!s->budget--) { s->failed_pc=0x0c0aa344u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aa352; }
goto P_0c0aa346;
P_0c0aa346: /* original 52d2, guest PC 0x0c0aa346 */
if(!s->budget--) { s->failed_pc=0x0c0aa346u; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c0aa348;
P_0c0aa348: /* original e062, guest PC 0x0c0aa348 */
if(!s->budget--) { s->failed_pc=0x0c0aa348u; return 0; }
r[0]=0x00000062u;
goto P_0c0aa34a;
P_0c0aa34a: /* original 622d, guest PC 0x0c0aa34a */
if(!s->budget--) { s->failed_pc=0x0c0aa34au; return 0; }
r[2]=r[2]&65535u;
goto P_0c0aa34c;
P_0c0aa34c: /* original 1d22, guest PC 0x0c0aa34c */
if(!s->budget--) { s->failed_pc=0x0c0aa34cu; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c0aa34e;
P_0c0aa34e: /* original a047, guest PC 0x0c0aa34e */
if(!s->budget--) { s->failed_pc=0x0c0aa34eu; return 0; }
write(ram,r[14]+r[0],r[8],1);
goto P_0c0aa3e0;
P_0c0aa350: /* original 0e84, guest PC 0x0c0aa350 */
if(!s->budget--) { s->failed_pc=0x0c0aa350u; return 0; }
write(ram,r[14]+r[0],r[8],1);
goto P_0c0aa352;
P_0c0aa352: /* original 2b88, guest PC 0x0c0aa352 */
if(!s->budget--) { s->failed_pc=0x0c0aa352u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[8])==0)!=0);
goto P_0c0aa354;
P_0c0aa354: /* original 8916, guest PC 0x0c0aa354 */
if(!s->budget--) { s->failed_pc=0x0c0aa354u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa384; }
goto P_0c0aa356;
P_0c0aa356: /* original 9007, guest PC 0x0c0aa356 */
if(!s->budget--) { s->failed_pc=0x0c0aa356u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa368u,2);
goto P_0c0aa358;
P_0c0aa358: /* original 04ed, guest PC 0x0c0aa358 */
if(!s->budget--) { s->failed_pc=0x0c0aa358u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aa35a;
P_0c0aa35a: /* original 644d, guest PC 0x0c0aa35a */
if(!s->budget--) { s->failed_pc=0x0c0aa35au; return 0; }
r[4]=r[4]&65535u;
goto P_0c0aa35c;
P_0c0aa35c: /* original 3492, guest PC 0x0c0aa35c */
if(!s->budget--) { s->failed_pc=0x0c0aa35cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[9])!=0);
goto P_0c0aa35e;
P_0c0aa35e: /* original 890f, guest PC 0x0c0aa35e */
if(!s->budget--) { s->failed_pc=0x0c0aa35eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa380; }
goto P_0c0aa360;
P_0c0aa360: /* original e03e, guest PC 0x0c0aa360 */
if(!s->budget--) { s->failed_pc=0x0c0aa360u; return 0; }
r[0]=0x0000003eu;
goto P_0c0aa362;
P_0c0aa362: /* original a00f, guest PC 0x0c0aa362 */
if(!s->budget--) { s->failed_pc=0x0c0aa362u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0aa384;
P_0c0aa364: /* original 0e45, guest PC 0x0c0aa364 */
if(!s->budget--) { s->failed_pc=0x0c0aa364u; return 0; }
write(ram,r[14]+r[0],r[4],2);
if(!vf3_matrix_family(0x0c0aa366u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aa366u; return 0; } return 1;
P_0c0aa380: /* original e03e, guest PC 0x0c0aa380 */
if(!s->budget--) { s->failed_pc=0x0c0aa380u; return 0; }
r[0]=0x0000003eu;
goto P_0c0aa382;
P_0c0aa382: /* original 0e95, guest PC 0x0c0aa382 */
if(!s->budget--) { s->failed_pc=0x0c0aa382u; return 0; }
write(ram,r[14]+r[0],r[9],2);
goto P_0c0aa384;
P_0c0aa384: /* original 52d2, guest PC 0x0c0aa384 */
if(!s->budget--) { s->failed_pc=0x0c0aa384u; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c0aa386;
P_0c0aa386: /* original d346, guest PC 0x0c0aa386 */
if(!s->budget--) { s->failed_pc=0x0c0aa386u; return 0; }
r[3]=read(ram,0x0c0aa4a0u,4);
goto P_0c0aa388;
P_0c0aa388: /* original 2238, guest PC 0x0c0aa388 */
if(!s->budget--) { s->failed_pc=0x0c0aa388u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aa38a;
P_0c0aa38a: /* original 8915, guest PC 0x0c0aa38a */
if(!s->budget--) { s->failed_pc=0x0c0aa38au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa3b8; }
goto P_0c0aa38c;
P_0c0aa38c: /* original 9080, guest PC 0x0c0aa38c */
if(!s->budget--) { s->failed_pc=0x0c0aa38cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa490u,2);
goto P_0c0aa38e;
P_0c0aa38e: /* original 64f2, guest PC 0x0c0aa38e */
if(!s->budget--) { s->failed_pc=0x0c0aa38eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0aa390;
P_0c0aa390: /* original 01ec, guest PC 0x0c0aa390 */
if(!s->budget--) { s->failed_pc=0x0c0aa390u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0aa392;
P_0c0aa392: /* original e030, guest PC 0x0c0aa392 */
if(!s->budget--) { s->failed_pc=0x0c0aa392u; return 0; }
r[0]=0x00000030u;
goto P_0c0aa394;
P_0c0aa394: /* original 927b, guest PC 0x0c0aa394 */
if(!s->budget--) { s->failed_pc=0x0c0aa394u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa48eu,2);
goto P_0c0aa396;
P_0c0aa396: /* original 611c, guest PC 0x0c0aa396 */
if(!s->budget--) { s->failed_pc=0x0c0aa396u; return 0; }
r[1]=r[1]&255u;
goto P_0c0aa398;
P_0c0aa398: /* original 4108, guest PC 0x0c0aa398 */
if(!s->budget--) { s->failed_pc=0x0c0aa398u; return 0; }
r[1]<<=2;
goto P_0c0aa39a;
P_0c0aa39a: /* original 4108, guest PC 0x0c0aa39a */
if(!s->budget--) { s->failed_pc=0x0c0aa39au; return 0; }
r[1]<<=2;
goto P_0c0aa39c;
P_0c0aa39c: /* original 4108, guest PC 0x0c0aa39c */
if(!s->budget--) { s->failed_pc=0x0c0aa39cu; return 0; }
r[1]<<=2;
goto P_0c0aa39e;
P_0c0aa39e: /* original 342c, guest PC 0x0c0aa39e */
if(!s->budget--) { s->failed_pc=0x0c0aa39eu; return 0; }
r[4]+=r[2];
goto P_0c0aa3a0;
P_0c0aa3a0: /* original 341c, guest PC 0x0c0aa3a0 */
if(!s->budget--) { s->failed_pc=0x0c0aa3a0u; return 0; }
r[4]+=r[1];
goto P_0c0aa3a2;
P_0c0aa3a2: /* original f346, guest PC 0x0c0aa3a2 */
if(!s->budget--) { s->failed_pc=0x0c0aa3a2u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0aa3a4;
P_0c0aa3a4: /* original 9075, guest PC 0x0c0aa3a4 */
if(!s->budget--) { s->failed_pc=0x0c0aa3a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa492u,2);
goto P_0c0aa3a6;
P_0c0aa3a6: /* original fe37, guest PC 0x0c0aa3a6 */
if(!s->budget--) { s->failed_pc=0x0c0aa3a6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0aa3a8;
P_0c0aa3a8: /* original e034, guest PC 0x0c0aa3a8 */
if(!s->budget--) { s->failed_pc=0x0c0aa3a8u; return 0; }
r[0]=0x00000034u;
goto P_0c0aa3aa;
P_0c0aa3aa: /* original f346, guest PC 0x0c0aa3aa */
if(!s->budget--) { s->failed_pc=0x0c0aa3aau; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0aa3ac;
P_0c0aa3ac: /* original 9072, guest PC 0x0c0aa3ac */
if(!s->budget--) { s->failed_pc=0x0c0aa3acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa494u,2);
goto P_0c0aa3ae;
P_0c0aa3ae: /* original fe37, guest PC 0x0c0aa3ae */
if(!s->budget--) { s->failed_pc=0x0c0aa3aeu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0aa3b0;
P_0c0aa3b0: /* original e038, guest PC 0x0c0aa3b0 */
if(!s->budget--) { s->failed_pc=0x0c0aa3b0u; return 0; }
r[0]=0x00000038u;
goto P_0c0aa3b2;
P_0c0aa3b2: /* original f346, guest PC 0x0c0aa3b2 */
if(!s->budget--) { s->failed_pc=0x0c0aa3b2u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0aa3b4;
P_0c0aa3b4: /* original 906f, guest PC 0x0c0aa3b4 */
if(!s->budget--) { s->failed_pc=0x0c0aa3b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa496u,2);
goto P_0c0aa3b6;
P_0c0aa3b6: /* original fe37, guest PC 0x0c0aa3b6 */
if(!s->budget--) { s->failed_pc=0x0c0aa3b6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0aa3b8;
P_0c0aa3b8: /* original 53d2, guest PC 0x0c0aa3b8 */
if(!s->budget--) { s->failed_pc=0x0c0aa3b8u; return 0; }
r[3]=read(ram,r[13]+8,4);
goto P_0c0aa3ba;
P_0c0aa3ba: /* original 2a38, guest PC 0x0c0aa3ba */
if(!s->budget--) { s->failed_pc=0x0c0aa3bau; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[3])==0)!=0);
goto P_0c0aa3bc;
P_0c0aa3bc: /* original 8910, guest PC 0x0c0aa3bc */
if(!s->budget--) { s->failed_pc=0x0c0aa3bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa3e0; }
goto P_0c0aa3be;
P_0c0aa3be: /* original 54d2, guest PC 0x0c0aa3be */
if(!s->budget--) { s->failed_pc=0x0c0aa3beu; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c0aa3c0;
P_0c0aa3c0: /* original d338, guest PC 0x0c0aa3c0 */
if(!s->budget--) { s->failed_pc=0x0c0aa3c0u; return 0; }
r[3]=read(ram,0x0c0aa4a4u,4);
goto P_0c0aa3c2;
P_0c0aa3c2: /* original 644d, guest PC 0x0c0aa3c2 */
if(!s->budget--) { s->failed_pc=0x0c0aa3c2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0aa3c4;
P_0c0aa3c4: /* original 430b, guest PC 0x0c0aa3c4 */
if(!s->budget--) { s->failed_pc=0x0c0aa3c4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0aa3c8u;
r[5]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aa3c8u) { target=s->pc; goto dispatch; }
goto P_0c0aa3c8;
P_0c0aa3c6: /* original e503, guest PC 0x0c0aa3c6 */
if(!s->budget--) { s->failed_pc=0x0c0aa3c6u; return 0; }
r[5]=0x00000003u;
goto P_0c0aa3c8;
P_0c0aa3c8: /* original 6403, guest PC 0x0c0aa3c8 */
if(!s->budget--) { s->failed_pc=0x0c0aa3c8u; return 0; }
r[4]=r[0];
goto P_0c0aa3ca;
P_0c0aa3ca: /* original 8446, guest PC 0x0c0aa3ca */
if(!s->budget--) { s->failed_pc=0x0c0aa3cau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+6,1);
goto P_0c0aa3cc;
P_0c0aa3cc: /* original 9364, guest PC 0x0c0aa3cc */
if(!s->budget--) { s->failed_pc=0x0c0aa3ccu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa498u,2);
goto P_0c0aa3ce;
P_0c0aa3ce: /* original 600c, guest PC 0x0c0aa3ce */
if(!s->budget--) { s->failed_pc=0x0c0aa3ceu; return 0; }
r[0]=r[0]&255u;
goto P_0c0aa3d0;
P_0c0aa3d0: /* original 4018, guest PC 0x0c0aa3d0 */
if(!s->budget--) { s->failed_pc=0x0c0aa3d0u; return 0; }
r[0]<<=8;
goto P_0c0aa3d2;
P_0c0aa3d2: /* original 2039, guest PC 0x0c0aa3d2 */
if(!s->budget--) { s->failed_pc=0x0c0aa3d2u; return 0; }
r[0]&=r[3];
goto P_0c0aa3d4;
P_0c0aa3d4: /* original 6203, guest PC 0x0c0aa3d4 */
if(!s->budget--) { s->failed_pc=0x0c0aa3d4u; return 0; }
r[2]=r[0];
goto P_0c0aa3d6;
P_0c0aa3d6: /* original 8445, guest PC 0x0c0aa3d6 */
if(!s->budget--) { s->failed_pc=0x0c0aa3d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+5,1);
goto P_0c0aa3d8;
P_0c0aa3d8: /* original 600c, guest PC 0x0c0aa3d8 */
if(!s->budget--) { s->failed_pc=0x0c0aa3d8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aa3da;
P_0c0aa3da: /* original 220b, guest PC 0x0c0aa3da */
if(!s->budget--) { s->failed_pc=0x0c0aa3dau; return 0; }
r[2]|=r[0];
goto P_0c0aa3dc;
P_0c0aa3dc: /* original 905d, guest PC 0x0c0aa3dc */
if(!s->budget--) { s->failed_pc=0x0c0aa3dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa49au,2);
goto P_0c0aa3de;
P_0c0aa3de: /* original 0e25, guest PC 0x0c0aa3de */
if(!s->budget--) { s->failed_pc=0x0c0aa3deu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0aa3e0;
P_0c0aa3e0: /* original 53d2, guest PC 0x0c0aa3e0 */
if(!s->budget--) { s->failed_pc=0x0c0aa3e0u; return 0; }
r[3]=read(ram,r[13]+8,4);
goto P_0c0aa3e2;
P_0c0aa3e2: /* original 1e3e, guest PC 0x0c0aa3e2 */
if(!s->budget--) { s->failed_pc=0x0c0aa3e2u; return 0; }
write(ram,r[14]+56,r[3],4);
goto P_0c0aa3e4;
P_0c0aa3e4: /* original 7f04, guest PC 0x0c0aa3e4 */
if(!s->budget--) { s->failed_pc=0x0c0aa3e4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0aa3e6;
P_0c0aa3e6: /* original 64e3, guest PC 0x0c0aa3e6 */
if(!s->budget--) { s->failed_pc=0x0c0aa3e6u; return 0; }
r[4]=r[14];
goto P_0c0aa3e8;
P_0c0aa3e8: /* original 4f26, guest PC 0x0c0aa3e8 */
if(!s->budget--) { s->failed_pc=0x0c0aa3e8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aa3ea;
P_0c0aa3ea: /* original 68f6, guest PC 0x0c0aa3ea */
if(!s->budget--) { s->failed_pc=0x0c0aa3eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0aa3ec;
P_0c0aa3ec: /* original 69f6, guest PC 0x0c0aa3ec */
if(!s->budget--) { s->failed_pc=0x0c0aa3ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0aa3ee;
P_0c0aa3ee: /* original 6af6, guest PC 0x0c0aa3ee */
if(!s->budget--) { s->failed_pc=0x0c0aa3eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0aa3f0;
P_0c0aa3f0: /* original 6bf6, guest PC 0x0c0aa3f0 */
if(!s->budget--) { s->failed_pc=0x0c0aa3f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0aa3f2;
P_0c0aa3f2: /* original 6cf6, guest PC 0x0c0aa3f2 */
if(!s->budget--) { s->failed_pc=0x0c0aa3f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0aa3f4;
P_0c0aa3f4: /* original 6df6, guest PC 0x0c0aa3f4 */
if(!s->budget--) { s->failed_pc=0x0c0aa3f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aa3f6;
P_0c0aa3f6: /* original add8, guest PC 0x0c0aa3f6 */
if(!s->budget--) { s->failed_pc=0x0c0aa3f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a9faau,s,ram);
P_0c0aa3f8: /* original 6ef6, guest PC 0x0c0aa3f8 */
if(!s->budget--) { s->failed_pc=0x0c0aa3f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0aa3fau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aa3fau; return 0; } return 1;
P_0c0ad178: /* original 2fe6, guest PC 0x0c0ad178 */
if(!s->budget--) { s->failed_pc=0x0c0ad178u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad17a;
P_0c0ad17a: /* original 6e43, guest PC 0x0c0ad17a */
if(!s->budget--) { s->failed_pc=0x0c0ad17au; return 0; }
r[14]=r[4];
goto P_0c0ad17c;
P_0c0ad17c: /* original 4f22, guest PC 0x0c0ad17c */
if(!s->budget--) { s->failed_pc=0x0c0ad17cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ad17e;
P_0c0ad17e: /* original 7ffc, guest PC 0x0c0ad17e */
if(!s->budget--) { s->failed_pc=0x0c0ad17eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ad180;
P_0c0ad180: /* original 2f52, guest PC 0x0c0ad180 */
if(!s->budget--) { s->failed_pc=0x0c0ad180u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ad182;
P_0c0ad182: /* original 905a, guest PC 0x0c0ad182 */
if(!s->budget--) { s->failed_pc=0x0c0ad182u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad23au,2);
goto P_0c0ad184;
P_0c0ad184: /* original 03ec, guest PC 0x0c0ad184 */
if(!s->budget--) { s->failed_pc=0x0c0ad184u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ad186;
P_0c0ad186: /* original 633c, guest PC 0x0c0ad186 */
if(!s->budget--) { s->failed_pc=0x0c0ad186u; return 0; }
r[3]=r[3]&255u;
goto P_0c0ad188;
P_0c0ad188: /* original 4315, guest PC 0x0c0ad188 */
if(!s->budget--) { s->failed_pc=0x0c0ad188u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c0ad18a;
P_0c0ad18a: /* original 8b04, guest PC 0x0c0ad18a */
if(!s->budget--) { s->failed_pc=0x0c0ad18au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ad196; }
goto P_0c0ad18c;
P_0c0ad18c: /* original d22e, guest PC 0x0c0ad18c */
if(!s->budget--) { s->failed_pc=0x0c0ad18cu; return 0; }
r[2]=read(ram,0x0c0ad248u,4);
goto P_0c0ad18e;
P_0c0ad18e: /* original 420b, guest PC 0x0c0ad18e */
if(!s->budget--) { s->failed_pc=0x0c0ad18eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0ad192u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ad192u) { target=s->pc; goto dispatch; }
goto P_0c0ad192;
P_0c0ad190: /* original 64e3, guest PC 0x0c0ad190 */
if(!s->budget--) { s->failed_pc=0x0c0ad190u; return 0; }
r[4]=r[14];
goto P_0c0ad192;
P_0c0ad192: /* original a003, guest PC 0x0c0ad192 */
if(!s->budget--) { s->failed_pc=0x0c0ad192u; return 0; }
goto P_0c0ad19c;
P_0c0ad194: /* original 0009, guest PC 0x0c0ad194 */
if(!s->budget--) { s->failed_pc=0x0c0ad194u; return 0; }
goto P_0c0ad196;
P_0c0ad196: /* original d22d, guest PC 0x0c0ad196 */
if(!s->budget--) { s->failed_pc=0x0c0ad196u; return 0; }
r[2]=read(ram,0x0c0ad24cu,4);
goto P_0c0ad198;
P_0c0ad198: /* original 420b, guest PC 0x0c0ad198 */
if(!s->budget--) { s->failed_pc=0x0c0ad198u; return 0; }
target=r[2];
r[16]=code_base|0x0c0ad19cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ad19cu) { target=s->pc; goto dispatch; }
goto P_0c0ad19c;
P_0c0ad19a: /* original 64e3, guest PC 0x0c0ad19a */
if(!s->budget--) { s->failed_pc=0x0c0ad19au; return 0; }
r[4]=r[14];
goto P_0c0ad19c;
P_0c0ad19c: /* original 65f2, guest PC 0x0c0ad19c */
if(!s->budget--) { s->failed_pc=0x0c0ad19cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ad19e;
P_0c0ad19e: /* original 7f04, guest PC 0x0c0ad19e */
if(!s->budget--) { s->failed_pc=0x0c0ad19eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0ad1a0;
P_0c0ad1a0: /* original 4f26, guest PC 0x0c0ad1a0 */
if(!s->budget--) { s->failed_pc=0x0c0ad1a0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ad1a2;
P_0c0ad1a2: /* original e600, guest PC 0x0c0ad1a2 */
if(!s->budget--) { s->failed_pc=0x0c0ad1a2u; return 0; }
r[6]=0x00000000u;
goto P_0c0ad1a4;
P_0c0ad1a4: /* original 64e3, guest PC 0x0c0ad1a4 */
if(!s->budget--) { s->failed_pc=0x0c0ad1a4u; return 0; }
r[4]=r[14];
goto P_0c0ad1a6;
P_0c0ad1a6: /* original a000, guest PC 0x0c0ad1a6 */
if(!s->budget--) { s->failed_pc=0x0c0ad1a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ad1aa;
P_0c0ad1a8: /* original 6ef6, guest PC 0x0c0ad1a8 */
if(!s->budget--) { s->failed_pc=0x0c0ad1a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ad1aa;
P_0c0ad1aa: /* original 2fe6, guest PC 0x0c0ad1aa */
if(!s->budget--) { s->failed_pc=0x0c0ad1aau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad1ac;
P_0c0ad1ac: /* original 6e43, guest PC 0x0c0ad1ac */
if(!s->budget--) { s->failed_pc=0x0c0ad1acu; return 0; }
r[14]=r[4];
goto P_0c0ad1ae;
P_0c0ad1ae: /* original 2fd6, guest PC 0x0c0ad1ae */
if(!s->budget--) { s->failed_pc=0x0c0ad1aeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad1b0;
P_0c0ad1b0: /* original 2fc6, guest PC 0x0c0ad1b0 */
if(!s->budget--) { s->failed_pc=0x0c0ad1b0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad1b2;
P_0c0ad1b2: /* original 2fb6, guest PC 0x0c0ad1b2 */
if(!s->budget--) { s->failed_pc=0x0c0ad1b2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad1b4;
P_0c0ad1b4: /* original 2fa6, guest PC 0x0c0ad1b4 */
if(!s->budget--) { s->failed_pc=0x0c0ad1b4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad1b6;
P_0c0ad1b6: /* original 84e4, guest PC 0x0c0ad1b6 */
if(!s->budget--) { s->failed_pc=0x0c0ad1b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0ad1b8;
P_0c0ad1b8: /* original 4f22, guest PC 0x0c0ad1b8 */
if(!s->budget--) { s->failed_pc=0x0c0ad1b8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ad1ba;
P_0c0ad1ba: /* original d425, guest PC 0x0c0ad1ba */
if(!s->budget--) { s->failed_pc=0x0c0ad1bau; return 0; }
r[4]=read(ram,0x0c0ad250u,4);
goto P_0c0ad1bc;
P_0c0ad1bc: /* original 2008, guest PC 0x0c0ad1bc */
if(!s->budget--) { s->failed_pc=0x0c0ad1bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0ad1be;
P_0c0ad1be: /* original 8f02, guest PC 0x0c0ad1be */
if(!s->budget--) { s->failed_pc=0x0c0ad1beu; return 0; }
cond=r[17]&1u;
r[0]=0x00000048u;
if(!cond) { goto P_0c0ad1c6; }
goto P_0c0ad1c2;
P_0c0ad1c0: /* original e048, guest PC 0x0c0ad1c0 */
if(!s->budget--) { s->failed_pc=0x0c0ad1c0u; return 0; }
r[0]=0x00000048u;
goto P_0c0ad1c2;
P_0c0ad1c2: /* original a001, guest PC 0x0c0ad1c2 */
if(!s->budget--) { s->failed_pc=0x0c0ad1c2u; return 0; }
r[12]=read(ram,r[4]+20,4);
goto P_0c0ad1c8;
P_0c0ad1c4: /* original 5c45, guest PC 0x0c0ad1c4 */
if(!s->budget--) { s->failed_pc=0x0c0ad1c4u; return 0; }
r[12]=read(ram,r[4]+20,4);
goto P_0c0ad1c6;
P_0c0ad1c6: /* original 5c44, guest PC 0x0c0ad1c6 */
if(!s->budget--) { s->failed_pc=0x0c0ad1c6u; return 0; }
r[12]=read(ram,r[4]+16,4);
goto P_0c0ad1c8;
P_0c0ad1c8: /* original 04ee, guest PC 0x0c0ad1c8 */
if(!s->budget--) { s->failed_pc=0x0c0ad1c8u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0ad1ca;
P_0c0ad1ca: /* original ed00, guest PC 0x0c0ad1ca */
if(!s->budget--) { s->failed_pc=0x0c0ad1cau; return 0; }
r[13]=0x00000000u;
goto P_0c0ad1cc;
P_0c0ad1cc: /* original 9036, guest PC 0x0c0ad1cc */
if(!s->budget--) { s->failed_pc=0x0c0ad1ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad23cu,2);
goto P_0c0ad1ce;
P_0c0ad1ce: /* original 2558, guest PC 0x0c0ad1ce */
if(!s->budget--) { s->failed_pc=0x0c0ad1ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0ad1d0;
P_0c0ad1d0: /* original f38d, guest PC 0x0c0ad1d0 */
if(!s->budget--) { s->failed_pc=0x0c0ad1d0u; return 0; }
fr[3]=0;
goto P_0c0ad1d2;
P_0c0ad1d2: /* original fe37, guest PC 0x0c0ad1d2 */
if(!s->budget--) { s->failed_pc=0x0c0ad1d2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ad1d4;
P_0c0ad1d4: /* original 7066, guest PC 0x0c0ad1d4 */
if(!s->budget--) { s->failed_pc=0x0c0ad1d4u; return 0; }
r[0]+=0x00000066u;
goto P_0c0ad1d6;
P_0c0ad1d6: /* original 0ed4, guest PC 0x0c0ad1d6 */
if(!s->budget--) { s->failed_pc=0x0c0ad1d6u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0ad1d8;
P_0c0ad1d8: /* original 8f08, guest PC 0x0c0ad1d8 */
if(!s->budget--) { s->failed_pc=0x0c0ad1d8u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[14],4);
r[7]=tmp;
if(!cond) { goto P_0c0ad1ec; }
goto P_0c0ad1dc;
P_0c0ad1da: /* original 67e2, guest PC 0x0c0ad1da */
if(!s->budget--) { s->failed_pc=0x0c0ad1dau; return 0; }
tmp=read(ram,r[14],4);
r[7]=tmp;
goto P_0c0ad1dc;
P_0c0ad1dc: /* original e048, guest PC 0x0c0ad1dc */
if(!s->budget--) { s->failed_pc=0x0c0ad1dcu; return 0; }
r[0]=0x00000048u;
goto P_0c0ad1de;
P_0c0ad1de: /* original d31d, guest PC 0x0c0ad1de */
if(!s->budget--) { s->failed_pc=0x0c0ad1deu; return 0; }
r[3]=read(ram,0x0c0ad254u,4);
goto P_0c0ad1e0;
P_0c0ad1e0: /* original 02ee, guest PC 0x0c0ad1e0 */
if(!s->budget--) { s->failed_pc=0x0c0ad1e0u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ad1e2;
P_0c0ad1e2: /* original 2239, guest PC 0x0c0ad1e2 */
if(!s->budget--) { s->failed_pc=0x0c0ad1e2u; return 0; }
r[2]&=r[3];
goto P_0c0ad1e4;
P_0c0ad1e4: /* original 0e26, guest PC 0x0c0ad1e4 */
if(!s->budget--) { s->failed_pc=0x0c0ad1e4u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0ad1e6;
P_0c0ad1e6: /* original e03c, guest PC 0x0c0ad1e6 */
if(!s->budget--) { s->failed_pc=0x0c0ad1e6u; return 0; }
r[0]=0x0000003cu;
goto P_0c0ad1e8;
P_0c0ad1e8: /* original a0ad, guest PC 0x0c0ad1e8 */
if(!s->budget--) { s->failed_pc=0x0c0ad1e8u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0ad346;
P_0c0ad1ea: /* original 0e55, guest PC 0x0c0ad1ea */
if(!s->budget--) { s->failed_pc=0x0c0ad1eau; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0ad1ec;
P_0c0ad1ec: /* original d31a, guest PC 0x0c0ad1ec */
if(!s->budget--) { s->failed_pc=0x0c0ad1ecu; return 0; }
r[3]=read(ram,0x0c0ad258u,4);
goto P_0c0ad1ee;
P_0c0ad1ee: /* original e2ef, guest PC 0x0c0ad1ee */
if(!s->budget--) { s->failed_pc=0x0c0ad1eeu; return 0; }
r[2]=0xffffffefu;
goto P_0c0ad1f0;
P_0c0ad1f0: /* original 273b, guest PC 0x0c0ad1f0 */
if(!s->budget--) { s->failed_pc=0x0c0ad1f0u; return 0; }
r[7]|=r[3];
goto P_0c0ad1f2;
P_0c0ad1f2: /* original 2729, guest PC 0x0c0ad1f2 */
if(!s->budget--) { s->failed_pc=0x0c0ad1f2u; return 0; }
r[7]&=r[2];
goto P_0c0ad1f4;
P_0c0ad1f4: /* original 2e72, guest PC 0x0c0ad1f4 */
if(!s->budget--) { s->failed_pc=0x0c0ad1f4u; return 0; }
write(ram,r[14],r[7],4);
goto P_0c0ad1f6;
P_0c0ad1f6: /* original 9122, guest PC 0x0c0ad1f6 */
if(!s->budget--) { s->failed_pc=0x0c0ad1f6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad23eu,2);
goto P_0c0ad1f8;
P_0c0ad1f8: /* original 2158, guest PC 0x0c0ad1f8 */
if(!s->budget--) { s->failed_pc=0x0c0ad1f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[5])==0)!=0);
goto P_0c0ad1fa;
P_0c0ad1fa: /* original 8d04, guest PC 0x0c0ad1fa */
if(!s->budget--) { s->failed_pc=0x0c0ad1fau; return 0; }
cond=r[17]&1u;
r[7]=0x00000001u;
if(cond) { goto P_0c0ad206; }
goto P_0c0ad1fe;
P_0c0ad1fc: /* original e701, guest PC 0x0c0ad1fc */
if(!s->budget--) { s->failed_pc=0x0c0ad1fcu; return 0; }
r[7]=0x00000001u;
goto P_0c0ad1fe;
P_0c0ad1fe: /* original 901f, guest PC 0x0c0ad1fe */
if(!s->budget--) { s->failed_pc=0x0c0ad1feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad240u,2);
goto P_0c0ad200;
P_0c0ad200: /* original 0e74, guest PC 0x0c0ad200 */
if(!s->budget--) { s->failed_pc=0x0c0ad200u; return 0; }
write(ram,r[14]+r[0],r[7],1);
goto P_0c0ad202;
P_0c0ad202: /* original d316, guest PC 0x0c0ad202 */
if(!s->budget--) { s->failed_pc=0x0c0ad202u; return 0; }
r[3]=read(ram,0x0c0ad25cu,4);
goto P_0c0ad204;
P_0c0ad204: /* original 2439, guest PC 0x0c0ad204 */
if(!s->budget--) { s->failed_pc=0x0c0ad204u; return 0; }
r[4]&=r[3];
goto P_0c0ad206;
P_0c0ad206: /* original 6243, guest PC 0x0c0ad206 */
if(!s->budget--) { s->failed_pc=0x0c0ad206u; return 0; }
r[2]=r[4];
goto P_0c0ad208;
P_0c0ad208: /* original 2278, guest PC 0x0c0ad208 */
if(!s->budget--) { s->failed_pc=0x0c0ad208u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[7])==0)!=0);
goto P_0c0ad20a;
P_0c0ad20a: /* original 8902, guest PC 0x0c0ad20a */
if(!s->budget--) { s->failed_pc=0x0c0ad20au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad212; }
goto P_0c0ad20c;
P_0c0ad20c: /* original 60e2, guest PC 0x0c0ad20c */
if(!s->budget--) { s->failed_pc=0x0c0ad20cu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0ad20e;
P_0c0ad20e: /* original cb04, guest PC 0x0c0ad20e */
if(!s->budget--) { s->failed_pc=0x0c0ad20eu; return 0; }
r[0]|=4u;
goto P_0c0ad210;
P_0c0ad210: /* original 2e02, guest PC 0x0c0ad210 */
if(!s->budget--) { s->failed_pc=0x0c0ad210u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c0ad212;
P_0c0ad212: /* original 9216, guest PC 0x0c0ad212 */
if(!s->budget--) { s->failed_pc=0x0c0ad212u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad242u,2);
goto P_0c0ad214;
P_0c0ad214: /* original 2258, guest PC 0x0c0ad214 */
if(!s->budget--) { s->failed_pc=0x0c0ad214u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0ad216;
P_0c0ad216: /* original 8903, guest PC 0x0c0ad216 */
if(!s->budget--) { s->failed_pc=0x0c0ad216u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad220; }
goto P_0c0ad218;
P_0c0ad218: /* original 9012, guest PC 0x0c0ad218 */
if(!s->budget--) { s->failed_pc=0x0c0ad218u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad240u,2);
goto P_0c0ad21a;
P_0c0ad21a: /* original 0e74, guest PC 0x0c0ad21a */
if(!s->budget--) { s->failed_pc=0x0c0ad21au; return 0; }
write(ram,r[14]+r[0],r[7],1);
goto P_0c0ad21c;
P_0c0ad21c: /* original d310, guest PC 0x0c0ad21c */
if(!s->budget--) { s->failed_pc=0x0c0ad21cu; return 0; }
r[3]=read(ram,0x0c0ad260u,4);
goto P_0c0ad21e;
P_0c0ad21e: /* original 2439, guest PC 0x0c0ad21e */
if(!s->budget--) { s->failed_pc=0x0c0ad21eu; return 0; }
r[4]&=r[3];
goto P_0c0ad220;
P_0c0ad220: /* original d710, guest PC 0x0c0ad220 */
if(!s->budget--) { s->failed_pc=0x0c0ad220u; return 0; }
r[7]=read(ram,0x0c0ad264u,4);
goto P_0c0ad222;
P_0c0ad222: /* original 6243, guest PC 0x0c0ad222 */
if(!s->budget--) { s->failed_pc=0x0c0ad222u; return 0; }
r[2]=r[4];
goto P_0c0ad224;
P_0c0ad224: /* original 2278, guest PC 0x0c0ad224 */
if(!s->budget--) { s->failed_pc=0x0c0ad224u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[7])==0)!=0);
goto P_0c0ad226;
P_0c0ad226: /* original 8926, guest PC 0x0c0ad226 */
if(!s->budget--) { s->failed_pc=0x0c0ad226u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad276; }
goto P_0c0ad228;
P_0c0ad228: /* original 6063, guest PC 0x0c0ad228 */
if(!s->budget--) { s->failed_pc=0x0c0ad228u; return 0; }
r[0]=r[6];
goto P_0c0ad22a;
P_0c0ad22a: /* original 8801, guest PC 0x0c0ad22a */
if(!s->budget--) { s->failed_pc=0x0c0ad22au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0ad22c;
P_0c0ad22c: /* original 8b1e, guest PC 0x0c0ad22c */
if(!s->budget--) { s->failed_pc=0x0c0ad22cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ad26c; }
goto P_0c0ad22e;
P_0c0ad22e: /* original d30e, guest PC 0x0c0ad22e */
if(!s->budget--) { s->failed_pc=0x0c0ad22eu; return 0; }
r[3]=read(ram,0x0c0ad268u,4);
goto P_0c0ad230;
P_0c0ad230: /* original 2348, guest PC 0x0c0ad230 */
if(!s->budget--) { s->failed_pc=0x0c0ad230u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0ad232;
P_0c0ad232: /* original 891b, guest PC 0x0c0ad232 */
if(!s->budget--) { s->failed_pc=0x0c0ad232u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad26c; }
goto P_0c0ad234;
P_0c0ad234: /* original 9006, guest PC 0x0c0ad234 */
if(!s->budget--) { s->failed_pc=0x0c0ad234u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad244u,2);
goto P_0c0ad236;
P_0c0ad236: /* original a01d, guest PC 0x0c0ad236 */
if(!s->budget--) { s->failed_pc=0x0c0ad236u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad274;
P_0c0ad238: /* original 00ed, guest PC 0x0c0ad238 */
if(!s->budget--) { s->failed_pc=0x0c0ad238u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(!vf3_matrix_family(0x0c0ad23au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ad23au; return 0; } return 1;
P_0c0ad26c: /* original 9072, guest PC 0x0c0ad26c */
if(!s->budget--) { s->failed_pc=0x0c0ad26cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad354u,2);
goto P_0c0ad26e;
P_0c0ad26e: /* original 03ed, guest PC 0x0c0ad26e */
if(!s->budget--) { s->failed_pc=0x0c0ad26eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad270;
P_0c0ad270: /* original 85ef, guest PC 0x0c0ad270 */
if(!s->budget--) { s->failed_pc=0x0c0ad270u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0ad272;
P_0c0ad272: /* original 303c, guest PC 0x0c0ad272 */
if(!s->budget--) { s->failed_pc=0x0c0ad272u; return 0; }
r[0]+=r[3];
goto P_0c0ad274;
P_0c0ad274: /* original 81ef, guest PC 0x0c0ad274 */
if(!s->budget--) { s->failed_pc=0x0c0ad274u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0ad276;
P_0c0ad276: /* original da3e, guest PC 0x0c0ad276 */
if(!s->budget--) { s->failed_pc=0x0c0ad276u; return 0; }
r[10]=read(ram,0x0c0ad370u,4);
goto P_0c0ad278;
P_0c0ad278: /* original 2a49, guest PC 0x0c0ad278 */
if(!s->budget--) { s->failed_pc=0x0c0ad278u; return 0; }
r[10]&=r[4];
goto P_0c0ad27a;
P_0c0ad27a: /* original 2aa8, guest PC 0x0c0ad27a */
if(!s->budget--) { s->failed_pc=0x0c0ad27au; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0ad27c;
P_0c0ad27c: /* original 8907, guest PC 0x0c0ad27c */
if(!s->budget--) { s->failed_pc=0x0c0ad27cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad28e; }
goto P_0c0ad27e;
P_0c0ad27e: /* original 906a, guest PC 0x0c0ad27e */
if(!s->budget--) { s->failed_pc=0x0c0ad27eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad356u,2);
goto P_0c0ad280;
P_0c0ad280: /* original f3e6, guest PC 0x0c0ad280 */
if(!s->budget--) { s->failed_pc=0x0c0ad280u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ad282;
P_0c0ad282: /* original e010, guest PC 0x0c0ad282 */
if(!s->budget--) { s->failed_pc=0x0c0ad282u; return 0; }
r[0]=0x00000010u;
goto P_0c0ad284;
P_0c0ad284: /* original fe37, guest PC 0x0c0ad284 */
if(!s->budget--) { s->failed_pc=0x0c0ad284u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ad286;
P_0c0ad286: /* original 9067, guest PC 0x0c0ad286 */
if(!s->budget--) { s->failed_pc=0x0c0ad286u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad358u,2);
goto P_0c0ad288;
P_0c0ad288: /* original f3e6, guest PC 0x0c0ad288 */
if(!s->budget--) { s->failed_pc=0x0c0ad288u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ad28a;
P_0c0ad28a: /* original e018, guest PC 0x0c0ad28a */
if(!s->budget--) { s->failed_pc=0x0c0ad28au; return 0; }
r[0]=0x00000018u;
goto P_0c0ad28c;
P_0c0ad28c: /* original fe37, guest PC 0x0c0ad28c */
if(!s->budget--) { s->failed_pc=0x0c0ad28cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ad28e;
P_0c0ad28e: /* original 9164, guest PC 0x0c0ad28e */
if(!s->budget--) { s->failed_pc=0x0c0ad28eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad35au,2);
goto P_0c0ad290;
P_0c0ad290: /* original e014, guest PC 0x0c0ad290 */
if(!s->budget--) { s->failed_pc=0x0c0ad290u; return 0; }
r[0]=0x00000014u;
goto P_0c0ad292;
P_0c0ad292: /* original f2e6, guest PC 0x0c0ad292 */
if(!s->budget--) { s->failed_pc=0x0c0ad292u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0ad294;
P_0c0ad294: /* original 31ec, guest PC 0x0c0ad294 */
if(!s->budget--) { s->failed_pc=0x0c0ad294u; return 0; }
r[1]+=r[14];
goto P_0c0ad296;
P_0c0ad296: /* original 9361, guest PC 0x0c0ad296 */
if(!s->budget--) { s->failed_pc=0x0c0ad296u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad35cu,2);
goto P_0c0ad298;
P_0c0ad298: /* original f318, guest PC 0x0c0ad298 */
if(!s->budget--) { s->failed_pc=0x0c0ad298u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0ad29a;
P_0c0ad29a: /* original 2438, guest PC 0x0c0ad29a */
if(!s->budget--) { s->failed_pc=0x0c0ad29au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0ad29c;
P_0c0ad29c: /* original f230, guest PC 0x0c0ad29c */
if(!s->budget--) { s->failed_pc=0x0c0ad29cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0ad29e;
P_0c0ad29e: /* original 8d03, guest PC 0x0c0ad29e */
if(!s->budget--) { s->failed_pc=0x0c0ad29eu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,2,r[14]+r[0]);
if(cond) { goto P_0c0ad2a8; }
goto P_0c0ad2a2;
P_0c0ad2a0: /* original fe27, guest PC 0x0c0ad2a0 */
if(!s->budget--) { s->failed_pc=0x0c0ad2a0u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0ad2a2;
P_0c0ad2a2: /* original 61e2, guest PC 0x0c0ad2a2 */
if(!s->budget--) { s->failed_pc=0x0c0ad2a2u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0ad2a4;
P_0c0ad2a4: /* original 217a, guest PC 0x0c0ad2a4 */
if(!s->budget--) { s->failed_pc=0x0c0ad2a4u; return 0; }
r[1]^=r[7];
goto P_0c0ad2a6;
P_0c0ad2a6: /* original 2e12, guest PC 0x0c0ad2a6 */
if(!s->budget--) { s->failed_pc=0x0c0ad2a6u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0ad2a8;
P_0c0ad2a8: /* original db32, guest PC 0x0c0ad2a8 */
if(!s->budget--) { s->failed_pc=0x0c0ad2a8u; return 0; }
r[11]=read(ram,0x0c0ad374u,4);
goto P_0c0ad2aa;
P_0c0ad2aa: /* original 2b59, guest PC 0x0c0ad2aa */
if(!s->budget--) { s->failed_pc=0x0c0ad2aau; return 0; }
r[11]&=r[5];
goto P_0c0ad2ac;
P_0c0ad2ac: /* original 2bb8, guest PC 0x0c0ad2ac */
if(!s->budget--) { s->failed_pc=0x0c0ad2acu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0ad2ae;
P_0c0ad2ae: /* original 8902, guest PC 0x0c0ad2ae */
if(!s->budget--) { s->failed_pc=0x0c0ad2aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad2b6; }
goto P_0c0ad2b0;
P_0c0ad2b0: /* original 62e2, guest PC 0x0c0ad2b0 */
if(!s->budget--) { s->failed_pc=0x0c0ad2b0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0ad2b2;
P_0c0ad2b2: /* original 227a, guest PC 0x0c0ad2b2 */
if(!s->budget--) { s->failed_pc=0x0c0ad2b2u; return 0; }
r[2]^=r[7];
goto P_0c0ad2b4;
P_0c0ad2b4: /* original 2e22, guest PC 0x0c0ad2b4 */
if(!s->budget--) { s->failed_pc=0x0c0ad2b4u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0ad2b6;
P_0c0ad2b6: /* original 9352, guest PC 0x0c0ad2b6 */
if(!s->budget--) { s->failed_pc=0x0c0ad2b6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad35eu,2);
goto P_0c0ad2b8;
P_0c0ad2b8: /* original e03c, guest PC 0x0c0ad2b8 */
if(!s->budget--) { s->failed_pc=0x0c0ad2b8u; return 0; }
r[0]=0x0000003cu;
goto P_0c0ad2ba;
P_0c0ad2ba: /* original 2539, guest PC 0x0c0ad2ba */
if(!s->budget--) { s->failed_pc=0x0c0ad2bau; return 0; }
r[5]&=r[3];
goto P_0c0ad2bc;
P_0c0ad2bc: /* original 0e55, guest PC 0x0c0ad2bc */
if(!s->budget--) { s->failed_pc=0x0c0ad2bcu; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0ad2be;
P_0c0ad2be: /* original 65c3, guest PC 0x0c0ad2be */
if(!s->budget--) { s->failed_pc=0x0c0ad2beu; return 0; }
r[5]=r[12];
goto P_0c0ad2c0;
P_0c0ad2c0: /* original 06ed, guest PC 0x0c0ad2c0 */
if(!s->budget--) { s->failed_pc=0x0c0ad2c0u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad2c2;
P_0c0ad2c2: /* original 666d, guest PC 0x0c0ad2c2 */
if(!s->budget--) { s->failed_pc=0x0c0ad2c2u; return 0; }
r[6]=r[6]&65535u;
goto P_0c0ad2c4;
P_0c0ad2c4: /* original b064, guest PC 0x0c0ad2c4 */
if(!s->budget--) { s->failed_pc=0x0c0ad2c4u; return 0; }
target=code_base|0x0c0ad390u; r[16]=code_base|0x0c0ad2c8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ad2c8u) { target=s->pc; goto dispatch; }
goto P_0c0ad2c8;
P_0c0ad2c6: /* original 64e3, guest PC 0x0c0ad2c6 */
if(!s->budget--) { s->failed_pc=0x0c0ad2c6u; return 0; }
r[4]=r[14];
goto P_0c0ad2c8;
P_0c0ad2c8: /* original d32b, guest PC 0x0c0ad2c8 */
if(!s->budget--) { s->failed_pc=0x0c0ad2c8u; return 0; }
r[3]=read(ram,0x0c0ad378u,4);
goto P_0c0ad2ca;
P_0c0ad2ca: /* original 430b, guest PC 0x0c0ad2ca */
if(!s->budget--) { s->failed_pc=0x0c0ad2cau; return 0; }
target=r[3];
r[16]=code_base|0x0c0ad2ceu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ad2ceu) { target=s->pc; goto dispatch; }
goto P_0c0ad2ce;
P_0c0ad2cc: /* original 64e3, guest PC 0x0c0ad2cc */
if(!s->budget--) { s->failed_pc=0x0c0ad2ccu; return 0; }
r[4]=r[14];
goto P_0c0ad2ce;
P_0c0ad2ce: /* original d22b, guest PC 0x0c0ad2ce */
if(!s->budget--) { s->failed_pc=0x0c0ad2ceu; return 0; }
r[2]=read(ram,0x0c0ad37cu,4);
goto P_0c0ad2d0;
P_0c0ad2d0: /* original 420b, guest PC 0x0c0ad2d0 */
if(!s->budget--) { s->failed_pc=0x0c0ad2d0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0ad2d4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ad2d4u) { target=s->pc; goto dispatch; }
goto P_0c0ad2d4;
P_0c0ad2d2: /* original 64e3, guest PC 0x0c0ad2d2 */
if(!s->budget--) { s->failed_pc=0x0c0ad2d2u; return 0; }
r[4]=r[14];
goto P_0c0ad2d4;
P_0c0ad2d4: /* original 2bb8, guest PC 0x0c0ad2d4 */
if(!s->budget--) { s->failed_pc=0x0c0ad2d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0ad2d6;
P_0c0ad2d6: /* original e048, guest PC 0x0c0ad2d6 */
if(!s->budget--) { s->failed_pc=0x0c0ad2d6u; return 0; }
r[0]=0x00000048u;
goto P_0c0ad2d8;
P_0c0ad2d8: /* original 8d02, guest PC 0x0c0ad2d8 */
if(!s->budget--) { s->failed_pc=0x0c0ad2d8u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[14]+r[0],4);
if(cond) { goto P_0c0ad2e0; }
goto P_0c0ad2dc;
P_0c0ad2da: /* original 04ee, guest PC 0x0c0ad2da */
if(!s->budget--) { s->failed_pc=0x0c0ad2dau; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0ad2dc;
P_0c0ad2dc: /* original 923e, guest PC 0x0c0ad2dc */
if(!s->budget--) { s->failed_pc=0x0c0ad2dcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad35cu,2);
goto P_0c0ad2de;
P_0c0ad2de: /* original 242a, guest PC 0x0c0ad2de */
if(!s->budget--) { s->failed_pc=0x0c0ad2deu; return 0; }
r[4]^=r[2];
goto P_0c0ad2e0;
P_0c0ad2e0: /* original 2aa8, guest PC 0x0c0ad2e0 */
if(!s->budget--) { s->failed_pc=0x0c0ad2e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0ad2e2;
P_0c0ad2e2: /* original 8901, guest PC 0x0c0ad2e2 */
if(!s->budget--) { s->failed_pc=0x0c0ad2e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad2e8; }
goto P_0c0ad2e4;
P_0c0ad2e4: /* original d126, guest PC 0x0c0ad2e4 */
if(!s->budget--) { s->failed_pc=0x0c0ad2e4u; return 0; }
r[1]=read(ram,0x0c0ad380u,4);
goto P_0c0ad2e6;
P_0c0ad2e6: /* original 241b, guest PC 0x0c0ad2e6 */
if(!s->budget--) { s->failed_pc=0x0c0ad2e6u; return 0; }
r[4]|=r[1];
goto P_0c0ad2e8;
P_0c0ad2e8: /* original d626, guest PC 0x0c0ad2e8 */
if(!s->budget--) { s->failed_pc=0x0c0ad2e8u; return 0; }
r[6]=read(ram,0x0c0ad384u,4);
goto P_0c0ad2ea;
P_0c0ad2ea: /* original 2649, guest PC 0x0c0ad2ea */
if(!s->budget--) { s->failed_pc=0x0c0ad2eau; return 0; }
r[6]&=r[4];
goto P_0c0ad2ec;
P_0c0ad2ec: /* original 2668, guest PC 0x0c0ad2ec */
if(!s->budget--) { s->failed_pc=0x0c0ad2ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0ad2ee;
P_0c0ad2ee: /* original 8905, guest PC 0x0c0ad2ee */
if(!s->budget--) { s->failed_pc=0x0c0ad2eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad2fc; }
goto P_0c0ad2f0;
P_0c0ad2f0: /* original 9036, guest PC 0x0c0ad2f0 */
if(!s->budget--) { s->failed_pc=0x0c0ad2f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad360u,2);
goto P_0c0ad2f2;
P_0c0ad2f2: /* original 02ed, guest PC 0x0c0ad2f2 */
if(!s->budget--) { s->failed_pc=0x0c0ad2f2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad2f4;
P_0c0ad2f4: /* original 7201, guest PC 0x0c0ad2f4 */
if(!s->budget--) { s->failed_pc=0x0c0ad2f4u; return 0; }
r[2]+=0x00000001u;
goto P_0c0ad2f6;
P_0c0ad2f6: /* original 0e25, guest PC 0x0c0ad2f6 */
if(!s->budget--) { s->failed_pc=0x0c0ad2f6u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0ad2f8;
P_0c0ad2f8: /* original 70d6, guest PC 0x0c0ad2f8 */
if(!s->budget--) { s->failed_pc=0x0c0ad2f8u; return 0; }
r[0]+=0xffffffd6u;
goto P_0c0ad2fa;
P_0c0ad2fa: /* original 0ed6, guest PC 0x0c0ad2fa */
if(!s->budget--) { s->failed_pc=0x0c0ad2fau; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0ad2fc;
P_0c0ad2fc: /* original 9331, guest PC 0x0c0ad2fc */
if(!s->budget--) { s->failed_pc=0x0c0ad2fcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad362u,2);
goto P_0c0ad2fe;
P_0c0ad2fe: /* original 2348, guest PC 0x0c0ad2fe */
if(!s->budget--) { s->failed_pc=0x0c0ad2feu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0ad300;
P_0c0ad300: /* original 8904, guest PC 0x0c0ad300 */
if(!s->budget--) { s->failed_pc=0x0c0ad300u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad30c; }
goto P_0c0ad302;
P_0c0ad302: /* original 902f, guest PC 0x0c0ad302 */
if(!s->budget--) { s->failed_pc=0x0c0ad302u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad364u,2);
goto P_0c0ad304;
P_0c0ad304: /* original 00ed, guest PC 0x0c0ad304 */
if(!s->budget--) { s->failed_pc=0x0c0ad304u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad306;
P_0c0ad306: /* original 81ef, guest PC 0x0c0ad306 */
if(!s->budget--) { s->failed_pc=0x0c0ad306u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0ad308;
P_0c0ad308: /* original 902d, guest PC 0x0c0ad308 */
if(!s->budget--) { s->failed_pc=0x0c0ad308u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad366u,2);
goto P_0c0ad30a;
P_0c0ad30a: /* original 0ed6, guest PC 0x0c0ad30a */
if(!s->budget--) { s->failed_pc=0x0c0ad30au; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0ad30c;
P_0c0ad30c: /* original 902c, guest PC 0x0c0ad30c */
if(!s->budget--) { s->failed_pc=0x0c0ad30cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad368u,2);
goto P_0c0ad30e;
P_0c0ad30e: /* original 05ed, guest PC 0x0c0ad30e */
if(!s->budget--) { s->failed_pc=0x0c0ad30eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad310;
P_0c0ad310: /* original 0ed5, guest PC 0x0c0ad310 */
if(!s->budget--) { s->failed_pc=0x0c0ad310u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0ad312;
P_0c0ad312: /* original 62e2, guest PC 0x0c0ad312 */
if(!s->budget--) { s->failed_pc=0x0c0ad312u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0ad314;
P_0c0ad314: /* original d31c, guest PC 0x0c0ad314 */
if(!s->budget--) { s->failed_pc=0x0c0ad314u; return 0; }
r[3]=read(ram,0x0c0ad388u,4);
goto P_0c0ad316;
P_0c0ad316: /* original 2238, guest PC 0x0c0ad316 */
if(!s->budget--) { s->failed_pc=0x0c0ad316u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ad318;
P_0c0ad318: /* original 8b0a, guest PC 0x0c0ad318 */
if(!s->budget--) { s->failed_pc=0x0c0ad318u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ad330; }
goto P_0c0ad31a;
P_0c0ad31a: /* original 2668, guest PC 0x0c0ad31a */
if(!s->budget--) { s->failed_pc=0x0c0ad31au; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0ad31c;
P_0c0ad31c: /* original 8908, guest PC 0x0c0ad31c */
if(!s->budget--) { s->failed_pc=0x0c0ad31cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad330; }
goto P_0c0ad31e;
P_0c0ad31e: /* original 2558, guest PC 0x0c0ad31e */
if(!s->budget--) { s->failed_pc=0x0c0ad31eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0ad320;
P_0c0ad320: /* original 8906, guest PC 0x0c0ad320 */
if(!s->budget--) { s->failed_pc=0x0c0ad320u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad330; }
goto P_0c0ad322;
P_0c0ad322: /* original 9022, guest PC 0x0c0ad322 */
if(!s->budget--) { s->failed_pc=0x0c0ad322u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad36au,2);
goto P_0c0ad324;
P_0c0ad324: /* original 0e55, guest PC 0x0c0ad324 */
if(!s->budget--) { s->failed_pc=0x0c0ad324u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0ad326;
P_0c0ad326: /* original 7008, guest PC 0x0c0ad326 */
if(!s->budget--) { s->failed_pc=0x0c0ad326u; return 0; }
r[0]+=0x00000008u;
goto P_0c0ad328;
P_0c0ad328: /* original 03ee, guest PC 0x0c0ad328 */
if(!s->budget--) { s->failed_pc=0x0c0ad328u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0ad32a;
P_0c0ad32a: /* original 70fc, guest PC 0x0c0ad32a */
if(!s->budget--) { s->failed_pc=0x0c0ad32au; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0ad32c;
P_0c0ad32c: /* original a002, guest PC 0x0c0ad32c */
if(!s->budget--) { s->failed_pc=0x0c0ad32cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0ad334;
P_0c0ad32e: /* original 0e36, guest PC 0x0c0ad32e */
if(!s->budget--) { s->failed_pc=0x0c0ad32eu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0ad330;
P_0c0ad330: /* original 901b, guest PC 0x0c0ad330 */
if(!s->budget--) { s->failed_pc=0x0c0ad330u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad36au,2);
goto P_0c0ad332;
P_0c0ad332: /* original 0ed5, guest PC 0x0c0ad332 */
if(!s->budget--) { s->failed_pc=0x0c0ad332u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0ad334;
P_0c0ad334: /* original d515, guest PC 0x0c0ad334 */
if(!s->budget--) { s->failed_pc=0x0c0ad334u; return 0; }
r[5]=read(ram,0x0c0ad38cu,4);
goto P_0c0ad336;
P_0c0ad336: /* original 2548, guest PC 0x0c0ad336 */
if(!s->budget--) { s->failed_pc=0x0c0ad336u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[4])==0)!=0);
goto P_0c0ad338;
P_0c0ad338: /* original 8903, guest PC 0x0c0ad338 */
if(!s->budget--) { s->failed_pc=0x0c0ad338u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad342; }
goto P_0c0ad33a;
P_0c0ad33a: /* original 9017, guest PC 0x0c0ad33a */
if(!s->budget--) { s->failed_pc=0x0c0ad33au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad36cu,2);
goto P_0c0ad33c;
P_0c0ad33c: /* original 0ed6, guest PC 0x0c0ad33c */
if(!s->budget--) { s->failed_pc=0x0c0ad33cu; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0ad33e;
P_0c0ad33e: /* original 7004, guest PC 0x0c0ad33e */
if(!s->budget--) { s->failed_pc=0x0c0ad33eu; return 0; }
r[0]+=0x00000004u;
goto P_0c0ad340;
P_0c0ad340: /* original 0ed6, guest PC 0x0c0ad340 */
if(!s->budget--) { s->failed_pc=0x0c0ad340u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0ad342;
P_0c0ad342: /* original e048, guest PC 0x0c0ad342 */
if(!s->budget--) { s->failed_pc=0x0c0ad342u; return 0; }
r[0]=0x00000048u;
goto P_0c0ad344;
P_0c0ad344: /* original 0e46, guest PC 0x0c0ad344 */
if(!s->budget--) { s->failed_pc=0x0c0ad344u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0ad346;
P_0c0ad346: /* original 4f26, guest PC 0x0c0ad346 */
if(!s->budget--) { s->failed_pc=0x0c0ad346u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ad348;
P_0c0ad348: /* original 6af6, guest PC 0x0c0ad348 */
if(!s->budget--) { s->failed_pc=0x0c0ad348u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0ad34a;
P_0c0ad34a: /* original 6bf6, guest PC 0x0c0ad34a */
if(!s->budget--) { s->failed_pc=0x0c0ad34au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ad34c;
P_0c0ad34c: /* original 6cf6, guest PC 0x0c0ad34c */
if(!s->budget--) { s->failed_pc=0x0c0ad34cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ad34e;
P_0c0ad34e: /* original 6df6, guest PC 0x0c0ad34e */
if(!s->budget--) { s->failed_pc=0x0c0ad34eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ad350;
P_0c0ad350: /* original 000b, guest PC 0x0c0ad350 */
if(!s->budget--) { s->failed_pc=0x0c0ad350u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ad352: /* original 6ef6, guest PC 0x0c0ad352 */
if(!s->budget--) { s->failed_pc=0x0c0ad352u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ad354u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ad354u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
