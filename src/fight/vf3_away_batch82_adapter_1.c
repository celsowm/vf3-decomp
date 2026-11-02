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
int vf3_away_batch82_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0aa080u: goto P_0c0aa080;
case 0x0c0aa082u: goto P_0c0aa082;
case 0x0c0aa084u: goto P_0c0aa084;
case 0x0c0aa086u: goto P_0c0aa086;
case 0x0c0aa088u: goto P_0c0aa088;
case 0x0c0aa08au: goto P_0c0aa08a;
case 0x0c0aa08cu: goto P_0c0aa08c;
case 0x0c0aa08eu: goto P_0c0aa08e;
case 0x0c0aa090u: goto P_0c0aa090;
case 0x0c0aa092u: goto P_0c0aa092;
case 0x0c0aa094u: goto P_0c0aa094;
case 0x0c0aa096u: goto P_0c0aa096;
case 0x0c0aa098u: goto P_0c0aa098;
case 0x0c0aa09au: goto P_0c0aa09a;
case 0x0c0aa09cu: goto P_0c0aa09c;
case 0x0c0aa09eu: goto P_0c0aa09e;
case 0x0c0aa0a0u: goto P_0c0aa0a0;
case 0x0c0aa0a2u: goto P_0c0aa0a2;
case 0x0c0aa0a4u: goto P_0c0aa0a4;
case 0x0c0aa0a6u: goto P_0c0aa0a6;
case 0x0c0aa0a8u: goto P_0c0aa0a8;
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
case 0x0c0aac14u: goto P_0c0aac14;
case 0x0c0aac16u: goto P_0c0aac16;
case 0x0c0aac18u: goto P_0c0aac18;
case 0x0c0aac1au: goto P_0c0aac1a;
case 0x0c0aac1cu: goto P_0c0aac1c;
case 0x0c0aac1eu: goto P_0c0aac1e;
case 0x0c0aac20u: goto P_0c0aac20;
case 0x0c0aac22u: goto P_0c0aac22;
case 0x0c0aac24u: goto P_0c0aac24;
case 0x0c0aac26u: goto P_0c0aac26;
case 0x0c0aac28u: goto P_0c0aac28;
case 0x0c0aac2au: goto P_0c0aac2a;
case 0x0c0aac2cu: goto P_0c0aac2c;
case 0x0c0aac2eu: goto P_0c0aac2e;
case 0x0c0aac30u: goto P_0c0aac30;
case 0x0c0aac32u: goto P_0c0aac32;
case 0x0c0aac34u: goto P_0c0aac34;
case 0x0c0aac36u: goto P_0c0aac36;
case 0x0c0aac38u: goto P_0c0aac38;
case 0x0c0aac3au: goto P_0c0aac3a;
case 0x0c0aac3cu: goto P_0c0aac3c;
case 0x0c0aac3eu: goto P_0c0aac3e;
case 0x0c0aac40u: goto P_0c0aac40;
case 0x0c0aac42u: goto P_0c0aac42;
case 0x0c0aac44u: goto P_0c0aac44;
case 0x0c0aac46u: goto P_0c0aac46;
case 0x0c0aac48u: goto P_0c0aac48;
case 0x0c0aac4au: goto P_0c0aac4a;
case 0x0c0aac4cu: goto P_0c0aac4c;
case 0x0c0aac4eu: goto P_0c0aac4e;
case 0x0c0aac50u: goto P_0c0aac50;
case 0x0c0aac52u: goto P_0c0aac52;
case 0x0c0aac54u: goto P_0c0aac54;
case 0x0c0aac56u: goto P_0c0aac56;
case 0x0c0aac58u: goto P_0c0aac58;
case 0x0c0aac5au: goto P_0c0aac5a;
case 0x0c0aac5cu: goto P_0c0aac5c;
case 0x0c0aac5eu: goto P_0c0aac5e;
case 0x0c0aac60u: goto P_0c0aac60;
case 0x0c0aac62u: goto P_0c0aac62;
case 0x0c0aac64u: goto P_0c0aac64;
case 0x0c0aac66u: goto P_0c0aac66;
case 0x0c0aac68u: goto P_0c0aac68;
case 0x0c0aac6au: goto P_0c0aac6a;
case 0x0c0aac6cu: goto P_0c0aac6c;
case 0x0c0aac6eu: goto P_0c0aac6e;
case 0x0c0aac70u: goto P_0c0aac70;
case 0x0c0aac72u: goto P_0c0aac72;
case 0x0c0aac74u: goto P_0c0aac74;
case 0x0c0aac76u: goto P_0c0aac76;
case 0x0c0aac78u: goto P_0c0aac78;
case 0x0c0aac7au: goto P_0c0aac7a;
case 0x0c0aac7cu: goto P_0c0aac7c;
case 0x0c0aac7eu: goto P_0c0aac7e;
case 0x0c0aac80u: goto P_0c0aac80;
case 0x0c0aac82u: goto P_0c0aac82;
case 0x0c0aac84u: goto P_0c0aac84;
case 0x0c0aac86u: goto P_0c0aac86;
case 0x0c0aac88u: goto P_0c0aac88;
case 0x0c0aac8au: goto P_0c0aac8a;
case 0x0c0aac8cu: goto P_0c0aac8c;
case 0x0c0aac8eu: goto P_0c0aac8e;
case 0x0c0aac90u: goto P_0c0aac90;
case 0x0c0aac92u: goto P_0c0aac92;
case 0x0c0aac94u: goto P_0c0aac94;
case 0x0c0aac96u: goto P_0c0aac96;
case 0x0c0aac98u: goto P_0c0aac98;
case 0x0c0aac9au: goto P_0c0aac9a;
case 0x0c0aac9cu: goto P_0c0aac9c;
case 0x0c0aac9eu: goto P_0c0aac9e;
case 0x0c0aaca0u: goto P_0c0aaca0;
case 0x0c0aaca2u: goto P_0c0aaca2;
case 0x0c0aaca4u: goto P_0c0aaca4;
case 0x0c0aaca6u: goto P_0c0aaca6;
case 0x0c0aaca8u: goto P_0c0aaca8;
case 0x0c0aacaau: goto P_0c0aacaa;
case 0x0c0aacacu: goto P_0c0aacac;
case 0x0c0aacaeu: goto P_0c0aacae;
case 0x0c0aacb0u: goto P_0c0aacb0;
case 0x0c0aacb2u: goto P_0c0aacb2;
case 0x0c0aacb4u: goto P_0c0aacb4;
case 0x0c0aacb6u: goto P_0c0aacb6;
case 0x0c0aacb8u: goto P_0c0aacb8;
case 0x0c0aacbau: goto P_0c0aacba;
case 0x0c0aacbcu: goto P_0c0aacbc;
case 0x0c0aacbeu: goto P_0c0aacbe;
case 0x0c0aacc0u: goto P_0c0aacc0;
case 0x0c0aacc2u: goto P_0c0aacc2;
case 0x0c0aacc4u: goto P_0c0aacc4;
case 0x0c0aacc6u: goto P_0c0aacc6;
case 0x0c0aacc8u: goto P_0c0aacc8;
case 0x0c0aaccau: goto P_0c0aacca;
case 0x0c0aacccu: goto P_0c0aaccc;
case 0x0c0aacceu: goto P_0c0aacce;
case 0x0c0aacd0u: goto P_0c0aacd0;
case 0x0c0aacd2u: goto P_0c0aacd2;
case 0x0c0aacd4u: goto P_0c0aacd4;
case 0x0c0aacd6u: goto P_0c0aacd6;
case 0x0c0aacd8u: goto P_0c0aacd8;
case 0x0c0aacdau: goto P_0c0aacda;
case 0x0c0aacdcu: goto P_0c0aacdc;
case 0x0c0aacdeu: goto P_0c0aacde;
case 0x0c0aace0u: goto P_0c0aace0;
case 0x0c0aace2u: goto P_0c0aace2;
case 0x0c0aace4u: goto P_0c0aace4;
case 0x0c0aace6u: goto P_0c0aace6;
case 0x0c0aace8u: goto P_0c0aace8;
case 0x0c0aaceau: goto P_0c0aacea;
case 0x0c0aacecu: goto P_0c0aacec;
case 0x0c0aaceeu: goto P_0c0aacee;
case 0x0c0aacf0u: goto P_0c0aacf0;
case 0x0c0aacf2u: goto P_0c0aacf2;
case 0x0c0aacf4u: goto P_0c0aacf4;
case 0x0c0aacf6u: goto P_0c0aacf6;
case 0x0c0aacf8u: goto P_0c0aacf8;
case 0x0c0aacfau: goto P_0c0aacfa;
case 0x0c0aacfcu: goto P_0c0aacfc;
case 0x0c0aacfeu: goto P_0c0aacfe;
case 0x0c0aad00u: goto P_0c0aad00;
case 0x0c0aad02u: goto P_0c0aad02;
case 0x0c0aad04u: goto P_0c0aad04;
case 0x0c0aad06u: goto P_0c0aad06;
case 0x0c0aad08u: goto P_0c0aad08;
case 0x0c0aad0au: goto P_0c0aad0a;
case 0x0c0aad0cu: goto P_0c0aad0c;
case 0x0c0aad0eu: goto P_0c0aad0e;
case 0x0c0aad10u: goto P_0c0aad10;
case 0x0c0aad12u: goto P_0c0aad12;
case 0x0c0aad14u: goto P_0c0aad14;
case 0x0c0aad16u: goto P_0c0aad16;
case 0x0c0aad18u: goto P_0c0aad18;
case 0x0c0aad1au: goto P_0c0aad1a;
case 0x0c0aad1cu: goto P_0c0aad1c;
case 0x0c0aad1eu: goto P_0c0aad1e;
case 0x0c0aad20u: goto P_0c0aad20;
case 0x0c0aad22u: goto P_0c0aad22;
case 0x0c0aad24u: goto P_0c0aad24;
case 0x0c0aad26u: goto P_0c0aad26;
case 0x0c0aad50u: goto P_0c0aad50;
case 0x0c0aad52u: goto P_0c0aad52;
case 0x0c0aad54u: goto P_0c0aad54;
case 0x0c0aad56u: goto P_0c0aad56;
case 0x0c0aad58u: goto P_0c0aad58;
case 0x0c0aad5au: goto P_0c0aad5a;
case 0x0c0aad5cu: goto P_0c0aad5c;
case 0x0c0aad5eu: goto P_0c0aad5e;
case 0x0c0aad60u: goto P_0c0aad60;
case 0x0c0aad62u: goto P_0c0aad62;
case 0x0c0aad64u: goto P_0c0aad64;
case 0x0c0aad66u: goto P_0c0aad66;
case 0x0c0aad68u: goto P_0c0aad68;
case 0x0c0aad6au: goto P_0c0aad6a;
case 0x0c0aad6cu: goto P_0c0aad6c;
case 0x0c0aad6eu: goto P_0c0aad6e;
case 0x0c0aad70u: goto P_0c0aad70;
case 0x0c0aad72u: goto P_0c0aad72;
case 0x0c0aad74u: goto P_0c0aad74;
case 0x0c0aad76u: goto P_0c0aad76;
case 0x0c0aad78u: goto P_0c0aad78;
case 0x0c0aad7au: goto P_0c0aad7a;
case 0x0c0aad7cu: goto P_0c0aad7c;
case 0x0c0aad7eu: goto P_0c0aad7e;
case 0x0c0aad80u: goto P_0c0aad80;
case 0x0c0aad82u: goto P_0c0aad82;
case 0x0c0aad84u: goto P_0c0aad84;
case 0x0c0aad86u: goto P_0c0aad86;
case 0x0c0aad88u: goto P_0c0aad88;
case 0x0c0aad8au: goto P_0c0aad8a;
case 0x0c0aad8cu: goto P_0c0aad8c;
case 0x0c0aad8eu: goto P_0c0aad8e;
case 0x0c0aad90u: goto P_0c0aad90;
case 0x0c0aad92u: goto P_0c0aad92;
case 0x0c0aad94u: goto P_0c0aad94;
case 0x0c0aad96u: goto P_0c0aad96;
case 0x0c0aad98u: goto P_0c0aad98;
case 0x0c0aad9au: goto P_0c0aad9a;
case 0x0c0aad9cu: goto P_0c0aad9c;
case 0x0c0aad9eu: goto P_0c0aad9e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0aa080: /* original 2fe6, guest PC 0x0c0aa080 */
if(!s->budget--) { s->failed_pc=0x0c0aa080u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aa082;
P_0c0aa082: /* original 6e63, guest PC 0x0c0aa082 */
if(!s->budget--) { s->failed_pc=0x0c0aa082u; return 0; }
r[14]=r[6];
goto P_0c0aa084;
P_0c0aa084: /* original 53e1, guest PC 0x0c0aa084 */
if(!s->budget--) { s->failed_pc=0x0c0aa084u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0aa086;
P_0c0aa086: /* original 7ffc, guest PC 0x0c0aa086 */
if(!s->budget--) { s->failed_pc=0x0c0aa086u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0aa088;
P_0c0aa088: /* original 62e2, guest PC 0x0c0aa088 */
if(!s->budget--) { s->failed_pc=0x0c0aa088u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0aa08a;
P_0c0aa08a: /* original e058, guest PC 0x0c0aa08a */
if(!s->budget--) { s->failed_pc=0x0c0aa08au; return 0; }
r[0]=0x00000058u;
goto P_0c0aa08c;
P_0c0aa08c: /* original 3230, guest PC 0x0c0aa08c */
if(!s->budget--) { s->failed_pc=0x0c0aa08cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0aa08e;
P_0c0aa08e: /* original 8f03, guest PC 0x0c0aa08e */
if(!s->budget--) { s->failed_pc=0x0c0aa08eu; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[4]+r[0],4);
if(!cond) { goto P_0c0aa098; }
goto P_0c0aa092;
P_0c0aa090: /* original 054e, guest PC 0x0c0aa090 */
if(!s->budget--) { s->failed_pc=0x0c0aa090u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0aa092;
P_0c0aa092: /* original 7f04, guest PC 0x0c0aa092 */
if(!s->budget--) { s->failed_pc=0x0c0aa092u; return 0; }
r[15]+=0x00000004u;
goto P_0c0aa094;
P_0c0aa094: /* original af89, guest PC 0x0c0aa094 */
if(!s->budget--) { s->failed_pc=0x0c0aa094u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a9faau,s,ram);
P_0c0aa096: /* original 6ef6, guest PC 0x0c0aa096 */
if(!s->budget--) { s->failed_pc=0x0c0aa096u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aa098;
P_0c0aa098: /* original 752e, guest PC 0x0c0aa098 */
if(!s->budget--) { s->failed_pc=0x0c0aa098u; return 0; }
r[5]+=0x0000002eu;
goto P_0c0aa09a;
P_0c0aa09a: /* original 6251, guest PC 0x0c0aa09a */
if(!s->budget--) { s->failed_pc=0x0c0aa09au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c0aa09c;
P_0c0aa09c: /* original 622d, guest PC 0x0c0aa09c */
if(!s->budget--) { s->failed_pc=0x0c0aa09cu; return 0; }
r[2]=r[2]&65535u;
goto P_0c0aa09e;
P_0c0aa09e: /* original 2f22, guest PC 0x0c0aa09e */
if(!s->budget--) { s->failed_pc=0x0c0aa09eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0aa0a0;
P_0c0aa0a0: /* original 7f04, guest PC 0x0c0aa0a0 */
if(!s->budget--) { s->failed_pc=0x0c0aa0a0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0aa0a2;
P_0c0aa0a2: /* original 56e2, guest PC 0x0c0aa0a2 */
if(!s->budget--) { s->failed_pc=0x0c0aa0a2u; return 0; }
r[6]=read(ram,r[14]+8,4);
goto P_0c0aa0a4;
P_0c0aa0a4: /* original 6523, guest PC 0x0c0aa0a4 */
if(!s->budget--) { s->failed_pc=0x0c0aa0a4u; return 0; }
r[5]=r[2];
goto P_0c0aa0a6;
P_0c0aa0a6: /* original a01c, guest PC 0x0c0aa0a6 */
if(!s->budget--) { s->failed_pc=0x0c0aa0a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aa0e2;
P_0c0aa0a8: /* original 6ef6, guest PC 0x0c0aa0a8 */
if(!s->budget--) { s->failed_pc=0x0c0aa0a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aa0aa;
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
P_0c0aac14: /* original 2fe6, guest PC 0x0c0aac14 */
if(!s->budget--) { s->failed_pc=0x0c0aac14u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aac16;
P_0c0aac16: /* original 6e43, guest PC 0x0c0aac16 */
if(!s->budget--) { s->failed_pc=0x0c0aac16u; return 0; }
r[14]=r[4];
goto P_0c0aac18;
P_0c0aac18: /* original 2fd6, guest PC 0x0c0aac18 */
if(!s->budget--) { s->failed_pc=0x0c0aac18u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aac1a;
P_0c0aac1a: /* original 6d63, guest PC 0x0c0aac1a */
if(!s->budget--) { s->failed_pc=0x0c0aac1au; return 0; }
r[13]=r[6];
goto P_0c0aac1c;
P_0c0aac1c: /* original 2fc6, guest PC 0x0c0aac1c */
if(!s->budget--) { s->failed_pc=0x0c0aac1cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aac1e;
P_0c0aac1e: /* original e401, guest PC 0x0c0aac1e */
if(!s->budget--) { s->failed_pc=0x0c0aac1eu; return 0; }
r[4]=0x00000001u;
goto P_0c0aac20;
P_0c0aac20: /* original 4f22, guest PC 0x0c0aac20 */
if(!s->budget--) { s->failed_pc=0x0c0aac20u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aac22;
P_0c0aac22: /* original d343, guest PC 0x0c0aac22 */
if(!s->budget--) { s->failed_pc=0x0c0aac22u; return 0; }
r[3]=read(ram,0x0c0aad30u,4);
goto P_0c0aac24;
P_0c0aac24: /* original e058, guest PC 0x0c0aac24 */
if(!s->budget--) { s->failed_pc=0x0c0aac24u; return 0; }
r[0]=0x00000058u;
goto P_0c0aac26;
P_0c0aac26: /* original 7fe8, guest PC 0x0c0aac26 */
if(!s->budget--) { s->failed_pc=0x0c0aac26u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0aac28;
P_0c0aac28: /* original 1f35, guest PC 0x0c0aac28 */
if(!s->budget--) { s->failed_pc=0x0c0aac28u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c0aac2a;
P_0c0aac2a: /* original 53d1, guest PC 0x0c0aac2a */
if(!s->budget--) { s->failed_pc=0x0c0aac2au; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0aac2c;
P_0c0aac2c: /* original 3342, guest PC 0x0c0aac2c */
if(!s->budget--) { s->failed_pc=0x0c0aac2cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[4])!=0);
goto P_0c0aac2e;
P_0c0aac2e: /* original 8f06, guest PC 0x0c0aac2e */
if(!s->budget--) { s->failed_pc=0x0c0aac2eu; return 0; }
cond=r[17]&1u;
r[12]=read(ram,r[14]+r[0],4);
if(!cond) { goto P_0c0aac3e; }
goto P_0c0aac32;
P_0c0aac30: /* original 0cee, guest PC 0x0c0aac30 */
if(!s->budget--) { s->failed_pc=0x0c0aac30u; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c0aac32;
P_0c0aac32: /* original 50d1, guest PC 0x0c0aac32 */
if(!s->budget--) { s->failed_pc=0x0c0aac32u; return 0; }
r[0]=read(ram,r[13]+4,4);
goto P_0c0aac34;
P_0c0aac34: /* original 8801, guest PC 0x0c0aac34 */
if(!s->budget--) { s->failed_pc=0x0c0aac34u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0aac36;
P_0c0aac36: /* original 8911, guest PC 0x0c0aac36 */
if(!s->budget--) { s->failed_pc=0x0c0aac36u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aac5c; }
goto P_0c0aac38;
P_0c0aac38: /* original 53d1, guest PC 0x0c0aac38 */
if(!s->budget--) { s->failed_pc=0x0c0aac38u; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0aac3a;
P_0c0aac3a: /* original 3346, guest PC 0x0c0aac3a */
if(!s->budget--) { s->failed_pc=0x0c0aac3au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[4])!=0);
goto P_0c0aac3c;
P_0c0aac3c: /* original 892e, guest PC 0x0c0aac3c */
if(!s->budget--) { s->failed_pc=0x0c0aac3cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aac9c; }
goto P_0c0aac3e;
P_0c0aac3e: /* original 62c3, guest PC 0x0c0aac3e */
if(!s->budget--) { s->failed_pc=0x0c0aac3eu; return 0; }
r[2]=r[12];
goto P_0c0aac40;
P_0c0aac40: /* original 7226, guest PC 0x0c0aac40 */
if(!s->budget--) { s->failed_pc=0x0c0aac40u; return 0; }
r[2]+=0x00000026u;
goto P_0c0aac42;
P_0c0aac42: /* original 6321, guest PC 0x0c0aac42 */
if(!s->budget--) { s->failed_pc=0x0c0aac42u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[3]=tmp;
goto P_0c0aac44;
P_0c0aac44: /* original 633d, guest PC 0x0c0aac44 */
if(!s->budget--) { s->failed_pc=0x0c0aac44u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0aac46;
P_0c0aac46: /* original 6533, guest PC 0x0c0aac46 */
if(!s->budget--) { s->failed_pc=0x0c0aac46u; return 0; }
r[5]=r[3];
goto P_0c0aac48;
P_0c0aac48: /* original 1f31, guest PC 0x0c0aac48 */
if(!s->budget--) { s->failed_pc=0x0c0aac48u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0aac4a;
P_0c0aac4a: /* original d23a, guest PC 0x0c0aac4a */
if(!s->budget--) { s->failed_pc=0x0c0aac4au; return 0; }
r[2]=read(ram,0x0c0aad34u,4);
goto P_0c0aac4c;
P_0c0aac4c: /* original 420b, guest PC 0x0c0aac4c */
if(!s->budget--) { s->failed_pc=0x0c0aac4cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0aac50u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aac50u) { target=s->pc; goto dispatch; }
goto P_0c0aac50;
P_0c0aac4e: /* original 64e3, guest PC 0x0c0aac4e */
if(!s->budget--) { s->failed_pc=0x0c0aac4eu; return 0; }
r[4]=r[14];
goto P_0c0aac50;
P_0c0aac50: /* original 53d1, guest PC 0x0c0aac50 */
if(!s->budget--) { s->failed_pc=0x0c0aac50u; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0aac52;
P_0c0aac52: /* original e062, guest PC 0x0c0aac52 */
if(!s->budget--) { s->failed_pc=0x0c0aac52u; return 0; }
r[0]=0x00000062u;
goto P_0c0aac54;
P_0c0aac54: /* original 7301, guest PC 0x0c0aac54 */
if(!s->budget--) { s->failed_pc=0x0c0aac54u; return 0; }
r[3]+=0x00000001u;
goto P_0c0aac56;
P_0c0aac56: /* original 6233, guest PC 0x0c0aac56 */
if(!s->budget--) { s->failed_pc=0x0c0aac56u; return 0; }
r[2]=r[3];
goto P_0c0aac58;
P_0c0aac58: /* original 1d31, guest PC 0x0c0aac58 */
if(!s->budget--) { s->failed_pc=0x0c0aac58u; return 0; }
write(ram,r[13]+4,r[3],4);
goto P_0c0aac5a;
P_0c0aac5a: /* original 0e24, guest PC 0x0c0aac5a */
if(!s->budget--) { s->failed_pc=0x0c0aac5au; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0aac5c;
P_0c0aac5c: /* original e03e, guest PC 0x0c0aac5c */
if(!s->budget--) { s->failed_pc=0x0c0aac5cu; return 0; }
r[0]=0x0000003eu;
goto P_0c0aac5e;
P_0c0aac5e: /* original 03ed, guest PC 0x0c0aac5e */
if(!s->budget--) { s->failed_pc=0x0c0aac5eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aac60;
P_0c0aac60: /* original e20a, guest PC 0x0c0aac60 */
if(!s->budget--) { s->failed_pc=0x0c0aac60u; return 0; }
r[2]=0x0000000au;
goto P_0c0aac62;
P_0c0aac62: /* original 633d, guest PC 0x0c0aac62 */
if(!s->budget--) { s->failed_pc=0x0c0aac62u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0aac64;
P_0c0aac64: /* original 3323, guest PC 0x0c0aac64 */
if(!s->budget--) { s->failed_pc=0x0c0aac64u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c0aac66;
P_0c0aac66: /* original 8901, guest PC 0x0c0aac66 */
if(!s->budget--) { s->failed_pc=0x0c0aac66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aac6c; }
goto P_0c0aac68;
P_0c0aac68: /* original a094, guest PC 0x0c0aac68 */
if(!s->budget--) { s->failed_pc=0x0c0aac68u; return 0; }
goto P_0c0aad94;
P_0c0aac6a: /* original 0009, guest PC 0x0c0aac6a */
if(!s->budget--) { s->failed_pc=0x0c0aac6au; return 0; }
goto P_0c0aac6c;
P_0c0aac6c: /* original e050, guest PC 0x0c0aac6c */
if(!s->budget--) { s->failed_pc=0x0c0aac6cu; return 0; }
r[0]=0x00000050u;
goto P_0c0aac6e;
P_0c0aac6e: /* original d332, guest PC 0x0c0aac6e */
if(!s->budget--) { s->failed_pc=0x0c0aac6eu; return 0; }
r[3]=read(ram,0x0c0aad38u,4);
goto P_0c0aac70;
P_0c0aac70: /* original 01ee, guest PC 0x0c0aac70 */
if(!s->budget--) { s->failed_pc=0x0c0aac70u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0aac72;
P_0c0aac72: /* original 2138, guest PC 0x0c0aac72 */
if(!s->budget--) { s->failed_pc=0x0c0aac72u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0aac74;
P_0c0aac74: /* original 8b01, guest PC 0x0c0aac74 */
if(!s->budget--) { s->failed_pc=0x0c0aac74u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aac7a; }
goto P_0c0aac76;
P_0c0aac76: /* original a08b, guest PC 0x0c0aac76 */
if(!s->budget--) { s->failed_pc=0x0c0aac76u; return 0; }
goto P_0c0aad90;
P_0c0aac78: /* original 0009, guest PC 0x0c0aac78 */
if(!s->budget--) { s->failed_pc=0x0c0aac78u; return 0; }
goto P_0c0aac7a;
P_0c0aac7a: /* original 9055, guest PC 0x0c0aac7a */
if(!s->budget--) { s->failed_pc=0x0c0aac7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aad28u,2);
goto P_0c0aac7c;
P_0c0aac7c: /* original 03cd, guest PC 0x0c0aac7c */
if(!s->budget--) { s->failed_pc=0x0c0aac7cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0aac7e;
P_0c0aac7e: /* original 633d, guest PC 0x0c0aac7e */
if(!s->budget--) { s->failed_pc=0x0c0aac7eu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0aac80;
P_0c0aac80: /* original 6533, guest PC 0x0c0aac80 */
if(!s->budget--) { s->failed_pc=0x0c0aac80u; return 0; }
r[5]=r[3];
goto P_0c0aac82;
P_0c0aac82: /* original 1f31, guest PC 0x0c0aac82 */
if(!s->budget--) { s->failed_pc=0x0c0aac82u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0aac84;
P_0c0aac84: /* original d22b, guest PC 0x0c0aac84 */
if(!s->budget--) { s->failed_pc=0x0c0aac84u; return 0; }
r[2]=read(ram,0x0c0aad34u,4);
goto P_0c0aac86;
P_0c0aac86: /* original 420b, guest PC 0x0c0aac86 */
if(!s->budget--) { s->failed_pc=0x0c0aac86u; return 0; }
target=r[2];
r[16]=code_base|0x0c0aac8au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aac8au) { target=s->pc; goto dispatch; }
goto P_0c0aac8a;
P_0c0aac88: /* original 64e3, guest PC 0x0c0aac88 */
if(!s->budget--) { s->failed_pc=0x0c0aac88u; return 0; }
r[4]=r[14];
goto P_0c0aac8a;
P_0c0aac8a: /* original e03e, guest PC 0x0c0aac8a */
if(!s->budget--) { s->failed_pc=0x0c0aac8au; return 0; }
r[0]=0x0000003eu;
goto P_0c0aac8c;
P_0c0aac8c: /* original e30a, guest PC 0x0c0aac8c */
if(!s->budget--) { s->failed_pc=0x0c0aac8cu; return 0; }
r[3]=0x0000000au;
goto P_0c0aac8e;
P_0c0aac8e: /* original 0e35, guest PC 0x0c0aac8e */
if(!s->budget--) { s->failed_pc=0x0c0aac8eu; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0aac90;
P_0c0aac90: /* original e062, guest PC 0x0c0aac90 */
if(!s->budget--) { s->failed_pc=0x0c0aac90u; return 0; }
r[0]=0x00000062u;
goto P_0c0aac92;
P_0c0aac92: /* original 52d1, guest PC 0x0c0aac92 */
if(!s->budget--) { s->failed_pc=0x0c0aac92u; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0aac94;
P_0c0aac94: /* original 7201, guest PC 0x0c0aac94 */
if(!s->budget--) { s->failed_pc=0x0c0aac94u; return 0; }
r[2]+=0x00000001u;
goto P_0c0aac96;
P_0c0aac96: /* original 6323, guest PC 0x0c0aac96 */
if(!s->budget--) { s->failed_pc=0x0c0aac96u; return 0; }
r[3]=r[2];
goto P_0c0aac98;
P_0c0aac98: /* original 1d21, guest PC 0x0c0aac98 */
if(!s->budget--) { s->failed_pc=0x0c0aac98u; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0aac9a;
P_0c0aac9a: /* original 0e34, guest PC 0x0c0aac9a */
if(!s->budget--) { s->failed_pc=0x0c0aac9au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0aac9c;
P_0c0aac9c: /* original 50f5, guest PC 0x0c0aac9c */
if(!s->budget--) { s->failed_pc=0x0c0aac9cu; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c0aac9e;
P_0c0aac9e: /* original e11c, guest PC 0x0c0aac9e */
if(!s->budget--) { s->failed_pc=0x0c0aac9eu; return 0; }
r[1]=0x0000001cu;
goto P_0c0aaca0;
P_0c0aaca0: /* original 001c, guest PC 0x0c0aaca0 */
if(!s->budget--) { s->failed_pc=0x0c0aaca0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0aaca2;
P_0c0aaca2: /* original 600c, guest PC 0x0c0aaca2 */
if(!s->budget--) { s->failed_pc=0x0c0aaca2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aaca4;
P_0c0aaca4: /* original c90f, guest PC 0x0c0aaca4 */
if(!s->budget--) { s->failed_pc=0x0c0aaca4u; return 0; }
r[0]&=15u;
goto P_0c0aaca6;
P_0c0aaca6: /* original 880d, guest PC 0x0c0aaca6 */
if(!s->budget--) { s->failed_pc=0x0c0aaca6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0aaca8;
P_0c0aaca8: /* original 8b0a, guest PC 0x0c0aaca8 */
if(!s->budget--) { s->failed_pc=0x0c0aaca8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aacc0; }
goto P_0c0aacaa;
P_0c0aacaa: /* original c724, guest PC 0x0c0aacaa */
if(!s->budget--) { s->failed_pc=0x0c0aacaau; return 0; }
r[0]=code_base|0x000aad3cu;
goto P_0c0aacac;
P_0c0aacac: /* original f308, guest PC 0x0c0aacac */
if(!s->budget--) { s->failed_pc=0x0c0aacacu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0aacae;
P_0c0aacae: /* original e05c, guest PC 0x0c0aacae */
if(!s->budget--) { s->failed_pc=0x0c0aacaeu; return 0; }
r[0]=0x0000005cu;
goto P_0c0aacb0;
P_0c0aacb0: /* original f2e6, guest PC 0x0c0aacb0 */
if(!s->budget--) { s->failed_pc=0x0c0aacb0u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0aacb2;
P_0c0aacb2: /* original f325, guest PC 0x0c0aacb2 */
if(!s->budget--) { s->failed_pc=0x0c0aacb2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0aacb4;
P_0c0aacb4: /* original 8904, guest PC 0x0c0aacb4 */
if(!s->budget--) { s->failed_pc=0x0c0aacb4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aacc0; }
goto P_0c0aacb6;
P_0c0aacb6: /* original e050, guest PC 0x0c0aacb6 */
if(!s->budget--) { s->failed_pc=0x0c0aacb6u; return 0; }
r[0]=0x00000050u;
goto P_0c0aacb8;
P_0c0aacb8: /* original d321, guest PC 0x0c0aacb8 */
if(!s->budget--) { s->failed_pc=0x0c0aacb8u; return 0; }
r[3]=read(ram,0x0c0aad40u,4);
goto P_0c0aacba;
P_0c0aacba: /* original 02ee, guest PC 0x0c0aacba */
if(!s->budget--) { s->failed_pc=0x0c0aacbau; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0aacbc;
P_0c0aacbc: /* original 2238, guest PC 0x0c0aacbc */
if(!s->budget--) { s->failed_pc=0x0c0aacbcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aacbe;
P_0c0aacbe: /* original 8b63, guest PC 0x0c0aacbe */
if(!s->budget--) { s->failed_pc=0x0c0aacbeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aad88; }
goto P_0c0aacc0;
P_0c0aacc0: /* original 61e2, guest PC 0x0c0aacc0 */
if(!s->budget--) { s->failed_pc=0x0c0aacc0u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0aacc2;
P_0c0aacc2: /* original d320, guest PC 0x0c0aacc2 */
if(!s->budget--) { s->failed_pc=0x0c0aacc2u; return 0; }
r[3]=read(ram,0x0c0aad44u,4);
goto P_0c0aacc4;
P_0c0aacc4: /* original 2138, guest PC 0x0c0aacc4 */
if(!s->budget--) { s->failed_pc=0x0c0aacc4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0aacc6;
P_0c0aacc6: /* original 891a, guest PC 0x0c0aacc6 */
if(!s->budget--) { s->failed_pc=0x0c0aacc6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aacfe; }
goto P_0c0aacc8;
P_0c0aacc8: /* original 62f3, guest PC 0x0c0aacc8 */
if(!s->budget--) { s->failed_pc=0x0c0aacc8u; return 0; }
r[2]=r[15];
goto P_0c0aacca;
P_0c0aacca: /* original 2f26, guest PC 0x0c0aacca */
if(!s->budget--) { s->failed_pc=0x0c0aaccau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aaccc;
P_0c0aaccc: /* original 65f3, guest PC 0x0c0aaccc */
if(!s->budget--) { s->failed_pc=0x0c0aacccu; return 0; }
r[5]=r[15];
goto P_0c0aacce;
P_0c0aacce: /* original d31e, guest PC 0x0c0aacce */
if(!s->budget--) { s->failed_pc=0x0c0aacceu; return 0; }
r[3]=read(ram,0x0c0aad48u,4);
goto P_0c0aacd0;
P_0c0aacd0: /* original 66f3, guest PC 0x0c0aacd0 */
if(!s->budget--) { s->failed_pc=0x0c0aacd0u; return 0; }
r[6]=r[15];
goto P_0c0aacd2;
P_0c0aacd2: /* original 67f3, guest PC 0x0c0aacd2 */
if(!s->budget--) { s->failed_pc=0x0c0aacd2u; return 0; }
r[7]=r[15];
goto P_0c0aacd4;
P_0c0aacd4: /* original 750c, guest PC 0x0c0aacd4 */
if(!s->budget--) { s->failed_pc=0x0c0aacd4u; return 0; }
r[5]+=0x0000000cu;
goto P_0c0aacd6;
P_0c0aacd6: /* original 7610, guest PC 0x0c0aacd6 */
if(!s->budget--) { s->failed_pc=0x0c0aacd6u; return 0; }
r[6]+=0x00000010u;
goto P_0c0aacd8;
P_0c0aacd8: /* original 7714, guest PC 0x0c0aacd8 */
if(!s->budget--) { s->failed_pc=0x0c0aacd8u; return 0; }
r[7]+=0x00000014u;
goto P_0c0aacda;
P_0c0aacda: /* original 430b, guest PC 0x0c0aacda */
if(!s->budget--) { s->failed_pc=0x0c0aacdau; return 0; }
target=r[3];
r[16]=code_base|0x0c0aacdeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aacdeu) { target=s->pc; goto dispatch; }
goto P_0c0aacde;
P_0c0aacdc: /* original 64e3, guest PC 0x0c0aacdc */
if(!s->budget--) { s->failed_pc=0x0c0aacdcu; return 0; }
r[4]=r[14];
goto P_0c0aacde;
P_0c0aacde: /* original 7f04, guest PC 0x0c0aacde */
if(!s->budget--) { s->failed_pc=0x0c0aacdeu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aace0;
P_0c0aace0: /* original 9323, guest PC 0x0c0aace0 */
if(!s->budget--) { s->failed_pc=0x0c0aace0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aad2au,2);
goto P_0c0aace2;
P_0c0aace2: /* original 62f2, guest PC 0x0c0aace2 */
if(!s->budget--) { s->failed_pc=0x0c0aace2u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0aace4;
P_0c0aace4: /* original 3328, guest PC 0x0c0aace4 */
if(!s->budget--) { s->failed_pc=0x0c0aace4u; return 0; }
r[3]-=r[2];
goto P_0c0aace6;
P_0c0aace6: /* original 633f, guest PC 0x0c0aace6 */
if(!s->budget--) { s->failed_pc=0x0c0aace6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c0aace8;
P_0c0aace8: /* original 2f32, guest PC 0x0c0aace8 */
if(!s->budget--) { s->failed_pc=0x0c0aace8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0aacea;
P_0c0aacea: /* original 85ef, guest PC 0x0c0aacea */
if(!s->budget--) { s->failed_pc=0x0c0aaceau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0aacec;
P_0c0aacec: /* original 6403, guest PC 0x0c0aacec */
if(!s->budget--) { s->failed_pc=0x0c0aacecu; return 0; }
r[4]=r[0];
goto P_0c0aacee;
P_0c0aacee: /* original 3438, guest PC 0x0c0aacee */
if(!s->budget--) { s->failed_pc=0x0c0aaceeu; return 0; }
r[4]-=r[3];
goto P_0c0aacf0;
P_0c0aacf0: /* original 644f, guest PC 0x0c0aacf0 */
if(!s->budget--) { s->failed_pc=0x0c0aacf0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0aacf2;
P_0c0aacf2: /* original 4411, guest PC 0x0c0aacf2 */
if(!s->budget--) { s->failed_pc=0x0c0aacf2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0aacf4;
P_0c0aacf4: /* original 8900, guest PC 0x0c0aacf4 */
if(!s->budget--) { s->failed_pc=0x0c0aacf4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aacf8; }
goto P_0c0aacf6;
P_0c0aacf6: /* original 644b, guest PC 0x0c0aacf6 */
if(!s->budget--) { s->failed_pc=0x0c0aacf6u; return 0; }
r[4]=0u-r[4];
goto P_0c0aacf8;
P_0c0aacf8: /* original 9218, guest PC 0x0c0aacf8 */
if(!s->budget--) { s->failed_pc=0x0c0aacf8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aad2cu,2);
goto P_0c0aacfa;
P_0c0aacfa: /* original 3427, guest PC 0x0c0aacfa */
if(!s->budget--) { s->failed_pc=0x0c0aacfau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[2])!=0);
goto P_0c0aacfc;
P_0c0aacfc: /* original 8b38, guest PC 0x0c0aacfc */
if(!s->budget--) { s->failed_pc=0x0c0aacfcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aad70; }
goto P_0c0aacfe;
P_0c0aacfe: /* original e050, guest PC 0x0c0aacfe */
if(!s->budget--) { s->failed_pc=0x0c0aacfeu; return 0; }
r[0]=0x00000050u;
goto P_0c0aad00;
P_0c0aad00: /* original d30d, guest PC 0x0c0aad00 */
if(!s->budget--) { s->failed_pc=0x0c0aad00u; return 0; }
r[3]=read(ram,0x0c0aad38u,4);
goto P_0c0aad02;
P_0c0aad02: /* original 01ee, guest PC 0x0c0aad02 */
if(!s->budget--) { s->failed_pc=0x0c0aad02u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0aad04;
P_0c0aad04: /* original 2138, guest PC 0x0c0aad04 */
if(!s->budget--) { s->failed_pc=0x0c0aad04u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0aad06;
P_0c0aad06: /* original 8933, guest PC 0x0c0aad06 */
if(!s->budget--) { s->failed_pc=0x0c0aad06u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aad70; }
goto P_0c0aad08;
P_0c0aad08: /* original 62e2, guest PC 0x0c0aad08 */
if(!s->budget--) { s->failed_pc=0x0c0aad08u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0aad0a;
P_0c0aad0a: /* original d30d, guest PC 0x0c0aad0a */
if(!s->budget--) { s->failed_pc=0x0c0aad0au; return 0; }
r[3]=read(ram,0x0c0aad40u,4);
goto P_0c0aad0c;
P_0c0aad0c: /* original 2238, guest PC 0x0c0aad0c */
if(!s->budget--) { s->failed_pc=0x0c0aad0cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aad0e;
P_0c0aad0e: /* original 8941, guest PC 0x0c0aad0e */
if(!s->budget--) { s->failed_pc=0x0c0aad0eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aad94; }
goto P_0c0aad10;
P_0c0aad10: /* original e048, guest PC 0x0c0aad10 */
if(!s->budget--) { s->failed_pc=0x0c0aad10u; return 0; }
r[0]=0x00000048u;
goto P_0c0aad12;
P_0c0aad12: /* original 01ee, guest PC 0x0c0aad12 */
if(!s->budget--) { s->failed_pc=0x0c0aad12u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0aad14;
P_0c0aad14: /* original 6213, guest PC 0x0c0aad14 */
if(!s->budget--) { s->failed_pc=0x0c0aad14u; return 0; }
r[2]=r[1];
goto P_0c0aad16;
P_0c0aad16: /* original 2f12, guest PC 0x0c0aad16 */
if(!s->budget--) { s->failed_pc=0x0c0aad16u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0aad18;
P_0c0aad18: /* original 9309, guest PC 0x0c0aad18 */
if(!s->budget--) { s->failed_pc=0x0c0aad18u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aad2eu,2);
goto P_0c0aad1a;
P_0c0aad1a: /* original d40c, guest PC 0x0c0aad1a */
if(!s->budget--) { s->failed_pc=0x0c0aad1au; return 0; }
r[4]=read(ram,0x0c0aad4cu,4);
goto P_0c0aad1c;
P_0c0aad1c: /* original 2238, guest PC 0x0c0aad1c */
if(!s->budget--) { s->failed_pc=0x0c0aad1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aad1e;
P_0c0aad1e: /* original 8917, guest PC 0x0c0aad1e */
if(!s->budget--) { s->failed_pc=0x0c0aad1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aad50; }
goto P_0c0aad20;
P_0c0aad20: /* original 62f2, guest PC 0x0c0aad20 */
if(!s->budget--) { s->failed_pc=0x0c0aad20u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0aad22;
P_0c0aad22: /* original 224b, guest PC 0x0c0aad22 */
if(!s->budget--) { s->failed_pc=0x0c0aad22u; return 0; }
r[2]|=r[4];
goto P_0c0aad24;
P_0c0aad24: /* original a018, guest PC 0x0c0aad24 */
if(!s->budget--) { s->failed_pc=0x0c0aad24u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0aad58;
P_0c0aad26: /* original 2f22, guest PC 0x0c0aad26 */
if(!s->budget--) { s->failed_pc=0x0c0aad26u; return 0; }
write(ram,r[15],r[2],4);
if(!vf3_matrix_family(0x0c0aad28u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aad28u; return 0; } return 1;
P_0c0aad50: /* original 61f2, guest PC 0x0c0aad50 */
if(!s->budget--) { s->failed_pc=0x0c0aad50u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0aad52;
P_0c0aad52: /* original d23e, guest PC 0x0c0aad52 */
if(!s->budget--) { s->failed_pc=0x0c0aad52u; return 0; }
r[2]=read(ram,0x0c0aae4cu,4);
goto P_0c0aad54;
P_0c0aad54: /* original 2129, guest PC 0x0c0aad54 */
if(!s->budget--) { s->failed_pc=0x0c0aad54u; return 0; }
r[1]&=r[2];
goto P_0c0aad56;
P_0c0aad56: /* original 2f12, guest PC 0x0c0aad56 */
if(!s->budget--) { s->failed_pc=0x0c0aad56u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0aad58;
P_0c0aad58: /* original 62f2, guest PC 0x0c0aad58 */
if(!s->budget--) { s->failed_pc=0x0c0aad58u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0aad5a;
P_0c0aad5a: /* original 63e2, guest PC 0x0c0aad5a */
if(!s->budget--) { s->failed_pc=0x0c0aad5au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0aad5c;
P_0c0aad5c: /* original 223a, guest PC 0x0c0aad5c */
if(!s->budget--) { s->failed_pc=0x0c0aad5cu; return 0; }
r[2]^=r[3];
goto P_0c0aad5e;
P_0c0aad5e: /* original 2248, guest PC 0x0c0aad5e */
if(!s->budget--) { s->failed_pc=0x0c0aad5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0aad60;
P_0c0aad60: /* original 2f22, guest PC 0x0c0aad60 */
if(!s->budget--) { s->failed_pc=0x0c0aad60u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0aad62;
P_0c0aad62: /* original 906b, guest PC 0x0c0aad62 */
if(!s->budget--) { s->failed_pc=0x0c0aad62u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aae3cu,2);
goto P_0c0aad64;
P_0c0aad64: /* original 0dcd, guest PC 0x0c0aad64 */
if(!s->budget--) { s->failed_pc=0x0c0aad64u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0aad66;
P_0c0aad66: /* original 8f09, guest PC 0x0c0aad66 */
if(!s->budget--) { s->failed_pc=0x0c0aad66u; return 0; }
cond=r[17]&1u;
r[13]=r[13]&65535u;
if(!cond) { goto P_0c0aad7c; }
goto P_0c0aad6a;
P_0c0aad68: /* original 6ddd, guest PC 0x0c0aad68 */
if(!s->budget--) { s->failed_pc=0x0c0aad68u; return 0; }
r[13]=r[13]&65535u;
goto P_0c0aad6a;
P_0c0aad6a: /* original 9068, guest PC 0x0c0aad6a */
if(!s->budget--) { s->failed_pc=0x0c0aad6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aae3eu,2);
goto P_0c0aad6c;
P_0c0aad6c: /* original a005, guest PC 0x0c0aad6c */
if(!s->budget--) { s->failed_pc=0x0c0aad6cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0aad7a;
P_0c0aad6e: /* original 0dcd, guest PC 0x0c0aad6e */
if(!s->budget--) { s->failed_pc=0x0c0aad6eu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0aad70;
P_0c0aad70: /* original 6dc3, guest PC 0x0c0aad70 */
if(!s->budget--) { s->failed_pc=0x0c0aad70u; return 0; }
r[13]=r[12];
goto P_0c0aad72;
P_0c0aad72: /* original 7d3a, guest PC 0x0c0aad72 */
if(!s->budget--) { s->failed_pc=0x0c0aad72u; return 0; }
r[13]+=0x0000003au;
goto P_0c0aad74;
P_0c0aad74: /* original d236, guest PC 0x0c0aad74 */
if(!s->budget--) { s->failed_pc=0x0c0aad74u; return 0; }
r[2]=read(ram,0x0c0aae50u,4);
goto P_0c0aad76;
P_0c0aad76: /* original 1e2d, guest PC 0x0c0aad76 */
if(!s->budget--) { s->failed_pc=0x0c0aad76u; return 0; }
write(ram,r[14]+52,r[2],4);
goto P_0c0aad78;
P_0c0aad78: /* original 6dd1, guest PC 0x0c0aad78 */
if(!s->budget--) { s->failed_pc=0x0c0aad78u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[13]=tmp;
goto P_0c0aad7a;
P_0c0aad7a: /* original 6ddd, guest PC 0x0c0aad7a */
if(!s->budget--) { s->failed_pc=0x0c0aad7au; return 0; }
r[13]=r[13]&65535u;
goto P_0c0aad7c;
P_0c0aad7c: /* original d335, guest PC 0x0c0aad7c */
if(!s->budget--) { s->failed_pc=0x0c0aad7cu; return 0; }
r[3]=read(ram,0x0c0aae54u,4);
goto P_0c0aad7e;
P_0c0aad7e: /* original 65d3, guest PC 0x0c0aad7e */
if(!s->budget--) { s->failed_pc=0x0c0aad7eu; return 0; }
r[5]=r[13];
goto P_0c0aad80;
P_0c0aad80: /* original 430b, guest PC 0x0c0aad80 */
if(!s->budget--) { s->failed_pc=0x0c0aad80u; return 0; }
target=r[3];
r[16]=code_base|0x0c0aad84u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aad84u) { target=s->pc; goto dispatch; }
goto P_0c0aad84;
P_0c0aad82: /* original 64e3, guest PC 0x0c0aad82 */
if(!s->budget--) { s->failed_pc=0x0c0aad82u; return 0; }
r[4]=r[14];
goto P_0c0aad84;
P_0c0aad84: /* original a006, guest PC 0x0c0aad84 */
if(!s->budget--) { s->failed_pc=0x0c0aad84u; return 0; }
goto P_0c0aad94;
P_0c0aad86: /* original 0009, guest PC 0x0c0aad86 */
if(!s->budget--) { s->failed_pc=0x0c0aad86u; return 0; }
goto P_0c0aad88;
P_0c0aad88: /* original d232, guest PC 0x0c0aad88 */
if(!s->budget--) { s->failed_pc=0x0c0aad88u; return 0; }
r[2]=read(ram,0x0c0aae54u,4);
goto P_0c0aad8a;
P_0c0aad8a: /* original 9559, guest PC 0x0c0aad8a */
if(!s->budget--) { s->failed_pc=0x0c0aad8au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aae40u,2);
goto P_0c0aad8c;
P_0c0aad8c: /* original 420b, guest PC 0x0c0aad8c */
if(!s->budget--) { s->failed_pc=0x0c0aad8cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0aad90u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aad90u) { target=s->pc; goto dispatch; }
goto P_0c0aad90;
P_0c0aad8e: /* original 64e3, guest PC 0x0c0aad8e */
if(!s->budget--) { s->failed_pc=0x0c0aad8eu; return 0; }
r[4]=r[14];
goto P_0c0aad90;
P_0c0aad90: /* original e300, guest PC 0x0c0aad90 */
if(!s->budget--) { s->failed_pc=0x0c0aad90u; return 0; }
r[3]=0x00000000u;
goto P_0c0aad92;
P_0c0aad92: /* original 1e3e, guest PC 0x0c0aad92 */
if(!s->budget--) { s->failed_pc=0x0c0aad92u; return 0; }
write(ram,r[14]+56,r[3],4);
goto P_0c0aad94;
P_0c0aad94: /* original 7f18, guest PC 0x0c0aad94 */
if(!s->budget--) { s->failed_pc=0x0c0aad94u; return 0; }
r[15]+=0x00000018u;
goto P_0c0aad96;
P_0c0aad96: /* original 4f26, guest PC 0x0c0aad96 */
if(!s->budget--) { s->failed_pc=0x0c0aad96u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aad98;
P_0c0aad98: /* original 6cf6, guest PC 0x0c0aad98 */
if(!s->budget--) { s->failed_pc=0x0c0aad98u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0aad9a;
P_0c0aad9a: /* original 6df6, guest PC 0x0c0aad9a */
if(!s->budget--) { s->failed_pc=0x0c0aad9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aad9c;
P_0c0aad9c: /* original 000b, guest PC 0x0c0aad9c */
if(!s->budget--) { s->failed_pc=0x0c0aad9cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0aad9e: /* original 6ef6, guest PC 0x0c0aad9e */
if(!s->budget--) { s->failed_pc=0x0c0aad9eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0aada0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
