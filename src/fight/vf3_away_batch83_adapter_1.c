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
int vf3_away_batch83_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09f1acu: goto P_0c09f1ac;
case 0x0c09f1aeu: goto P_0c09f1ae;
case 0x0c09f1b0u: goto P_0c09f1b0;
case 0x0c09f1b2u: goto P_0c09f1b2;
case 0x0c09f1b4u: goto P_0c09f1b4;
case 0x0c09f1b6u: goto P_0c09f1b6;
case 0x0c09f1b8u: goto P_0c09f1b8;
case 0x0c09f1bau: goto P_0c09f1ba;
case 0x0c09f1bcu: goto P_0c09f1bc;
case 0x0c09f1beu: goto P_0c09f1be;
case 0x0c09f1c0u: goto P_0c09f1c0;
case 0x0c09f1c2u: goto P_0c09f1c2;
case 0x0c09f1c4u: goto P_0c09f1c4;
case 0x0c09f1c6u: goto P_0c09f1c6;
case 0x0c09f1c8u: goto P_0c09f1c8;
case 0x0c09f1cau: goto P_0c09f1ca;
case 0x0c09f1ccu: goto P_0c09f1cc;
case 0x0c09f1ceu: goto P_0c09f1ce;
case 0x0c09f1d0u: goto P_0c09f1d0;
case 0x0c09f1d2u: goto P_0c09f1d2;
case 0x0c09f1d4u: goto P_0c09f1d4;
case 0x0c09f1d6u: goto P_0c09f1d6;
case 0x0c09f1d8u: goto P_0c09f1d8;
case 0x0c09f1dau: goto P_0c09f1da;
case 0x0c09f1dcu: goto P_0c09f1dc;
case 0x0c09f1deu: goto P_0c09f1de;
case 0x0c09f1e0u: goto P_0c09f1e0;
case 0x0c09f1e2u: goto P_0c09f1e2;
case 0x0c09f1e4u: goto P_0c09f1e4;
case 0x0c09f1e6u: goto P_0c09f1e6;
case 0x0c09f1e8u: goto P_0c09f1e8;
case 0x0c09f1eau: goto P_0c09f1ea;
case 0x0c09f1ecu: goto P_0c09f1ec;
case 0x0c09f1eeu: goto P_0c09f1ee;
case 0x0c09f1f0u: goto P_0c09f1f0;
case 0x0c09f1f2u: goto P_0c09f1f2;
case 0x0c09f1f4u: goto P_0c09f1f4;
case 0x0c09f1f6u: goto P_0c09f1f6;
case 0x0c09f1f8u: goto P_0c09f1f8;
case 0x0c09f1fau: goto P_0c09f1fa;
case 0x0c09f1fcu: goto P_0c09f1fc;
case 0x0c09f1feu: goto P_0c09f1fe;
case 0x0c09f200u: goto P_0c09f200;
case 0x0c09f202u: goto P_0c09f202;
case 0x0c09f204u: goto P_0c09f204;
case 0x0c09f206u: goto P_0c09f206;
case 0x0c09f208u: goto P_0c09f208;
case 0x0c09f20au: goto P_0c09f20a;
case 0x0c09f20cu: goto P_0c09f20c;
case 0x0c09f20eu: goto P_0c09f20e;
case 0x0c09f210u: goto P_0c09f210;
case 0x0c09f212u: goto P_0c09f212;
case 0x0c09f214u: goto P_0c09f214;
case 0x0c09f216u: goto P_0c09f216;
case 0x0c09f218u: goto P_0c09f218;
case 0x0c09f21au: goto P_0c09f21a;
case 0x0c09f21cu: goto P_0c09f21c;
case 0x0c09f21eu: goto P_0c09f21e;
case 0x0c09f220u: goto P_0c09f220;
case 0x0c09f222u: goto P_0c09f222;
case 0x0c09f224u: goto P_0c09f224;
case 0x0c09f226u: goto P_0c09f226;
case 0x0c09f228u: goto P_0c09f228;
case 0x0c09f22au: goto P_0c09f22a;
case 0x0c09f22cu: goto P_0c09f22c;
case 0x0c09f22eu: goto P_0c09f22e;
case 0x0c09f230u: goto P_0c09f230;
case 0x0c09f232u: goto P_0c09f232;
case 0x0c09f234u: goto P_0c09f234;
case 0x0c09f236u: goto P_0c09f236;
case 0x0c09f238u: goto P_0c09f238;
case 0x0c09f23au: goto P_0c09f23a;
case 0x0c09f23cu: goto P_0c09f23c;
case 0x0c09f23eu: goto P_0c09f23e;
case 0x0c09f240u: goto P_0c09f240;
case 0x0c09f242u: goto P_0c09f242;
case 0x0c09f244u: goto P_0c09f244;
case 0x0c09f246u: goto P_0c09f246;
case 0x0c09f248u: goto P_0c09f248;
case 0x0c09f24au: goto P_0c09f24a;
case 0x0c09f24cu: goto P_0c09f24c;
case 0x0c09f24eu: goto P_0c09f24e;
case 0x0c09f250u: goto P_0c09f250;
case 0x0c09f268u: goto P_0c09f268;
case 0x0c09f26au: goto P_0c09f26a;
case 0x0c09f26cu: goto P_0c09f26c;
case 0x0c09f26eu: goto P_0c09f26e;
case 0x0c09f270u: goto P_0c09f270;
case 0x0c09f272u: goto P_0c09f272;
case 0x0c09f274u: goto P_0c09f274;
case 0x0c09f276u: goto P_0c09f276;
case 0x0c09f278u: goto P_0c09f278;
case 0x0c09f27au: goto P_0c09f27a;
case 0x0c09f27cu: goto P_0c09f27c;
case 0x0c09f27eu: goto P_0c09f27e;
case 0x0c09f280u: goto P_0c09f280;
case 0x0c09f282u: goto P_0c09f282;
case 0x0c09f284u: goto P_0c09f284;
case 0x0c09f286u: goto P_0c09f286;
case 0x0c09f288u: goto P_0c09f288;
case 0x0c09f28au: goto P_0c09f28a;
case 0x0c09f28cu: goto P_0c09f28c;
case 0x0c09f28eu: goto P_0c09f28e;
case 0x0c09f290u: goto P_0c09f290;
case 0x0c09f292u: goto P_0c09f292;
case 0x0c09f294u: goto P_0c09f294;
case 0x0c09f296u: goto P_0c09f296;
case 0x0c09f298u: goto P_0c09f298;
case 0x0c09f29au: goto P_0c09f29a;
case 0x0c09f29cu: goto P_0c09f29c;
case 0x0c09f29eu: goto P_0c09f29e;
case 0x0c09f2a0u: goto P_0c09f2a0;
case 0x0c09f2a2u: goto P_0c09f2a2;
case 0x0c09f2a4u: goto P_0c09f2a4;
case 0x0c09f2a6u: goto P_0c09f2a6;
case 0x0c09f2a8u: goto P_0c09f2a8;
case 0x0c09f2aau: goto P_0c09f2aa;
case 0x0c09f2acu: goto P_0c09f2ac;
case 0x0c09f2aeu: goto P_0c09f2ae;
case 0x0c09f2b0u: goto P_0c09f2b0;
case 0x0c09f2b2u: goto P_0c09f2b2;
case 0x0c09f2b4u: goto P_0c09f2b4;
case 0x0c09f2b6u: goto P_0c09f2b6;
case 0x0c09f2b8u: goto P_0c09f2b8;
case 0x0c09f2bau: goto P_0c09f2ba;
case 0x0c09f2bcu: goto P_0c09f2bc;
case 0x0c09f2beu: goto P_0c09f2be;
case 0x0c09f2c0u: goto P_0c09f2c0;
case 0x0c09f2c2u: goto P_0c09f2c2;
case 0x0c09f2c4u: goto P_0c09f2c4;
case 0x0c09f2c6u: goto P_0c09f2c6;
case 0x0c09f2c8u: goto P_0c09f2c8;
case 0x0c09f2cau: goto P_0c09f2ca;
case 0x0c09f2ccu: goto P_0c09f2cc;
case 0x0c09f2ceu: goto P_0c09f2ce;
case 0x0c09f2d0u: goto P_0c09f2d0;
case 0x0c09f2d2u: goto P_0c09f2d2;
case 0x0c09f2d4u: goto P_0c09f2d4;
case 0x0c09f2d6u: goto P_0c09f2d6;
case 0x0c09f2d8u: goto P_0c09f2d8;
case 0x0c09f2dau: goto P_0c09f2da;
case 0x0c09f2dcu: goto P_0c09f2dc;
case 0x0c09f2deu: goto P_0c09f2de;
case 0x0c09f2e0u: goto P_0c09f2e0;
case 0x0c09f2e2u: goto P_0c09f2e2;
case 0x0c09f2e4u: goto P_0c09f2e4;
case 0x0c09f2e6u: goto P_0c09f2e6;
case 0x0c09f2e8u: goto P_0c09f2e8;
case 0x0c09f2eau: goto P_0c09f2ea;
case 0x0c09f2ecu: goto P_0c09f2ec;
case 0x0c09f2eeu: goto P_0c09f2ee;
case 0x0c09f2f0u: goto P_0c09f2f0;
case 0x0c09f2f2u: goto P_0c09f2f2;
case 0x0c09f2f4u: goto P_0c09f2f4;
case 0x0c09f2f6u: goto P_0c09f2f6;
case 0x0c09f2f8u: goto P_0c09f2f8;
case 0x0c09f2fau: goto P_0c09f2fa;
case 0x0c09f2fcu: goto P_0c09f2fc;
case 0x0c09f2feu: goto P_0c09f2fe;
case 0x0c09f300u: goto P_0c09f300;
case 0x0c09f302u: goto P_0c09f302;
case 0x0c09f304u: goto P_0c09f304;
case 0x0c09f306u: goto P_0c09f306;
case 0x0c09f308u: goto P_0c09f308;
case 0x0c09f30au: goto P_0c09f30a;
case 0x0c09f30cu: goto P_0c09f30c;
case 0x0c09f30eu: goto P_0c09f30e;
case 0x0c09f310u: goto P_0c09f310;
case 0x0c09f312u: goto P_0c09f312;
case 0x0c09f314u: goto P_0c09f314;
case 0x0c09f316u: goto P_0c09f316;
case 0x0c09f318u: goto P_0c09f318;
case 0x0c09f31au: goto P_0c09f31a;
case 0x0c09f31cu: goto P_0c09f31c;
case 0x0c09f31eu: goto P_0c09f31e;
case 0x0c09f320u: goto P_0c09f320;
case 0x0c09f322u: goto P_0c09f322;
case 0x0c09f324u: goto P_0c09f324;
case 0x0c09f326u: goto P_0c09f326;
case 0x0c09f328u: goto P_0c09f328;
case 0x0c09f32au: goto P_0c09f32a;
case 0x0c09f32cu: goto P_0c09f32c;
case 0x0c09f32eu: goto P_0c09f32e;
case 0x0c09f330u: goto P_0c09f330;
case 0x0c09f332u: goto P_0c09f332;
case 0x0c09f334u: goto P_0c09f334;
case 0x0c0aa72eu: goto P_0c0aa72e;
case 0x0c0aa730u: goto P_0c0aa730;
case 0x0c0aa732u: goto P_0c0aa732;
case 0x0c0aa734u: goto P_0c0aa734;
case 0x0c0aa736u: goto P_0c0aa736;
case 0x0c0aa738u: goto P_0c0aa738;
case 0x0c0aa73au: goto P_0c0aa73a;
case 0x0c0aa73cu: goto P_0c0aa73c;
case 0x0c0aa73eu: goto P_0c0aa73e;
case 0x0c0aaf98u: goto P_0c0aaf98;
case 0x0c0aaf9au: goto P_0c0aaf9a;
case 0x0c0aaf9cu: goto P_0c0aaf9c;
case 0x0c0aaf9eu: goto P_0c0aaf9e;
case 0x0c0aafa0u: goto P_0c0aafa0;
case 0x0c0aafa2u: goto P_0c0aafa2;
case 0x0c0aafa4u: goto P_0c0aafa4;
case 0x0c0aafa6u: goto P_0c0aafa6;
case 0x0c0aafa8u: goto P_0c0aafa8;
case 0x0c0aafaau: goto P_0c0aafaa;
case 0x0c0aafacu: goto P_0c0aafac;
case 0x0c0aafaeu: goto P_0c0aafae;
case 0x0c0aafb0u: goto P_0c0aafb0;
case 0x0c0aafb2u: goto P_0c0aafb2;
case 0x0c0aafb4u: goto P_0c0aafb4;
case 0x0c0aafb6u: goto P_0c0aafb6;
case 0x0c0aafb8u: goto P_0c0aafb8;
case 0x0c0aafbau: goto P_0c0aafba;
case 0x0c0aafbcu: goto P_0c0aafbc;
case 0x0c0aafbeu: goto P_0c0aafbe;
case 0x0c0aafc0u: goto P_0c0aafc0;
case 0x0c0aafc2u: goto P_0c0aafc2;
case 0x0c0aafc4u: goto P_0c0aafc4;
case 0x0c0aafc6u: goto P_0c0aafc6;
case 0x0c0aafc8u: goto P_0c0aafc8;
case 0x0c0aafcau: goto P_0c0aafca;
case 0x0c0aafccu: goto P_0c0aafcc;
case 0x0c0aafceu: goto P_0c0aafce;
case 0x0c0aafd0u: goto P_0c0aafd0;
case 0x0c0aafd2u: goto P_0c0aafd2;
case 0x0c0aafd4u: goto P_0c0aafd4;
case 0x0c0aafd6u: goto P_0c0aafd6;
case 0x0c0aafd8u: goto P_0c0aafd8;
case 0x0c0aafdau: goto P_0c0aafda;
case 0x0c0aafdcu: goto P_0c0aafdc;
case 0x0c0aafdeu: goto P_0c0aafde;
case 0x0c0aafe0u: goto P_0c0aafe0;
case 0x0c0aafe2u: goto P_0c0aafe2;
case 0x0c0aafe4u: goto P_0c0aafe4;
case 0x0c0aafe6u: goto P_0c0aafe6;
case 0x0c0aafe8u: goto P_0c0aafe8;
case 0x0c0aafeau: goto P_0c0aafea;
case 0x0c0aafecu: goto P_0c0aafec;
case 0x0c0aafeeu: goto P_0c0aafee;
case 0x0c0aaff0u: goto P_0c0aaff0;
case 0x0c0aaff2u: goto P_0c0aaff2;
case 0x0c0aaff4u: goto P_0c0aaff4;
case 0x0c0aaff6u: goto P_0c0aaff6;
case 0x0c0aaff8u: goto P_0c0aaff8;
case 0x0c0aaffau: goto P_0c0aaffa;
case 0x0c0aaffcu: goto P_0c0aaffc;
case 0x0c0aaffeu: goto P_0c0aaffe;
case 0x0c0ab000u: goto P_0c0ab000;
case 0x0c0ab002u: goto P_0c0ab002;
case 0x0c0ab004u: goto P_0c0ab004;
case 0x0c0ab006u: goto P_0c0ab006;
case 0x0c0ab008u: goto P_0c0ab008;
case 0x0c0ab00au: goto P_0c0ab00a;
case 0x0c0ab00cu: goto P_0c0ab00c;
case 0x0c0ab00eu: goto P_0c0ab00e;
case 0x0c0ab010u: goto P_0c0ab010;
case 0x0c0ab012u: goto P_0c0ab012;
case 0x0c0ab014u: goto P_0c0ab014;
case 0x0c0ab016u: goto P_0c0ab016;
case 0x0c0ab018u: goto P_0c0ab018;
case 0x0c0ab01au: goto P_0c0ab01a;
case 0x0c0ab01cu: goto P_0c0ab01c;
case 0x0c0ab01eu: goto P_0c0ab01e;
case 0x0c0ab020u: goto P_0c0ab020;
case 0x0c0ab022u: goto P_0c0ab022;
case 0x0c0ab024u: goto P_0c0ab024;
case 0x0c0ab026u: goto P_0c0ab026;
case 0x0c0ab028u: goto P_0c0ab028;
case 0x0c0ab02au: goto P_0c0ab02a;
case 0x0c0ab02cu: goto P_0c0ab02c;
case 0x0c0ab02eu: goto P_0c0ab02e;
case 0x0c0ab030u: goto P_0c0ab030;
case 0x0c0ab032u: goto P_0c0ab032;
case 0x0c0ab034u: goto P_0c0ab034;
case 0x0c0ab036u: goto P_0c0ab036;
case 0x0c0ab038u: goto P_0c0ab038;
case 0x0c0ab03au: goto P_0c0ab03a;
case 0x0c0ab03cu: goto P_0c0ab03c;
case 0x0c0ab03eu: goto P_0c0ab03e;
case 0x0c0ab040u: goto P_0c0ab040;
case 0x0c0ab042u: goto P_0c0ab042;
case 0x0c0ab044u: goto P_0c0ab044;
case 0x0c0ab046u: goto P_0c0ab046;
case 0x0c0ab048u: goto P_0c0ab048;
case 0x0c0ab04au: goto P_0c0ab04a;
case 0x0c0ab04cu: goto P_0c0ab04c;
case 0x0c0ab04eu: goto P_0c0ab04e;
case 0x0c0ab050u: goto P_0c0ab050;
case 0x0c0ab052u: goto P_0c0ab052;
case 0x0c0ab054u: goto P_0c0ab054;
case 0x0c0ab056u: goto P_0c0ab056;
case 0x0c0ab058u: goto P_0c0ab058;
case 0x0c0ab05au: goto P_0c0ab05a;
case 0x0c0ab05cu: goto P_0c0ab05c;
case 0x0c0ab05eu: goto P_0c0ab05e;
case 0x0c0ab060u: goto P_0c0ab060;
case 0x0c0ab062u: goto P_0c0ab062;
case 0x0c0ab064u: goto P_0c0ab064;
case 0x0c0ab066u: goto P_0c0ab066;
case 0x0c0ab068u: goto P_0c0ab068;
case 0x0c0ab06au: goto P_0c0ab06a;
case 0x0c0ab06cu: goto P_0c0ab06c;
case 0x0c0ab06eu: goto P_0c0ab06e;
case 0x0c0ab070u: goto P_0c0ab070;
case 0x0c0ab072u: goto P_0c0ab072;
case 0x0c0ab074u: goto P_0c0ab074;
case 0x0c0ab076u: goto P_0c0ab076;
case 0x0c0ab078u: goto P_0c0ab078;
case 0x0c0ab07au: goto P_0c0ab07a;
case 0x0c0ab07cu: goto P_0c0ab07c;
case 0x0c0ab07eu: goto P_0c0ab07e;
case 0x0c0ab080u: goto P_0c0ab080;
case 0x0c0ab082u: goto P_0c0ab082;
case 0x0c0ab084u: goto P_0c0ab084;
case 0x0c0ab086u: goto P_0c0ab086;
case 0x0c0ab088u: goto P_0c0ab088;
case 0x0c0ab08au: goto P_0c0ab08a;
case 0x0c0ab08cu: goto P_0c0ab08c;
case 0x0c0ab08eu: goto P_0c0ab08e;
case 0x0c0ab090u: goto P_0c0ab090;
case 0x0c0ab092u: goto P_0c0ab092;
case 0x0c0ab094u: goto P_0c0ab094;
case 0x0c0ab096u: goto P_0c0ab096;
case 0x0c0ab098u: goto P_0c0ab098;
case 0x0c0ab09au: goto P_0c0ab09a;
case 0x0c0ab09cu: goto P_0c0ab09c;
case 0x0c0ab09eu: goto P_0c0ab09e;
case 0x0c0ab0a0u: goto P_0c0ab0a0;
case 0x0c0ab0a2u: goto P_0c0ab0a2;
case 0x0c0ab0a4u: goto P_0c0ab0a4;
case 0x0c0ab0a6u: goto P_0c0ab0a6;
case 0x0c0ab0a8u: goto P_0c0ab0a8;
case 0x0c0ab0aau: goto P_0c0ab0aa;
case 0x0c0ab0acu: goto P_0c0ab0ac;
case 0x0c0ab0aeu: goto P_0c0ab0ae;
case 0x0c0ab0b0u: goto P_0c0ab0b0;
case 0x0c0ab0b2u: goto P_0c0ab0b2;
case 0x0c0ab0b4u: goto P_0c0ab0b4;
case 0x0c0ab0b6u: goto P_0c0ab0b6;
case 0x0c0ab0b8u: goto P_0c0ab0b8;
case 0x0c0ab0bau: goto P_0c0ab0ba;
case 0x0c0ab0bcu: goto P_0c0ab0bc;
case 0x0c0ab0e4u: goto P_0c0ab0e4;
case 0x0c0ab0e6u: goto P_0c0ab0e6;
case 0x0c0ab0e8u: goto P_0c0ab0e8;
case 0x0c0ab0eau: goto P_0c0ab0ea;
case 0x0c0ab0ecu: goto P_0c0ab0ec;
case 0x0c0ab0eeu: goto P_0c0ab0ee;
case 0x0c0ab0f0u: goto P_0c0ab0f0;
case 0x0c0ab0f2u: goto P_0c0ab0f2;
case 0x0c0ab0f4u: goto P_0c0ab0f4;
case 0x0c0ab0f6u: goto P_0c0ab0f6;
case 0x0c0ab0f8u: goto P_0c0ab0f8;
case 0x0c0ab0fau: goto P_0c0ab0fa;
case 0x0c0ab0fcu: goto P_0c0ab0fc;
case 0x0c0ab0feu: goto P_0c0ab0fe;
case 0x0c0ab100u: goto P_0c0ab100;
case 0x0c0ab102u: goto P_0c0ab102;
case 0x0c0ab104u: goto P_0c0ab104;
case 0x0c0ab106u: goto P_0c0ab106;
case 0x0c0ab108u: goto P_0c0ab108;
case 0x0c0ab10au: goto P_0c0ab10a;
case 0x0c0ab10cu: goto P_0c0ab10c;
case 0x0c0ab10eu: goto P_0c0ab10e;
case 0x0c0ab110u: goto P_0c0ab110;
case 0x0c0ab112u: goto P_0c0ab112;
case 0x0c0ab114u: goto P_0c0ab114;
case 0x0c0ab116u: goto P_0c0ab116;
case 0x0c0ab118u: goto P_0c0ab118;
case 0x0c0ab11au: goto P_0c0ab11a;
case 0x0c0ab11cu: goto P_0c0ab11c;
case 0x0c0ab11eu: goto P_0c0ab11e;
case 0x0c0ab120u: goto P_0c0ab120;
case 0x0c0ab122u: goto P_0c0ab122;
case 0x0c0ab124u: goto P_0c0ab124;
case 0x0c0ab126u: goto P_0c0ab126;
case 0x0c0ab128u: goto P_0c0ab128;
case 0x0c0ab12au: goto P_0c0ab12a;
case 0x0c0ab12cu: goto P_0c0ab12c;
case 0x0c0ab12eu: goto P_0c0ab12e;
case 0x0c0ab130u: goto P_0c0ab130;
case 0x0c0ab132u: goto P_0c0ab132;
case 0x0c0ab134u: goto P_0c0ab134;
case 0x0c0ab136u: goto P_0c0ab136;
case 0x0c0ab138u: goto P_0c0ab138;
case 0x0c0ab13au: goto P_0c0ab13a;
case 0x0c0ab13cu: goto P_0c0ab13c;
case 0x0c0ab13eu: goto P_0c0ab13e;
case 0x0c0ab140u: goto P_0c0ab140;
case 0x0c0ab142u: goto P_0c0ab142;
case 0x0c0ab144u: goto P_0c0ab144;
case 0x0c0ab146u: goto P_0c0ab146;
case 0x0c0ab148u: goto P_0c0ab148;
case 0x0c0ab14au: goto P_0c0ab14a;
case 0x0c0ab14cu: goto P_0c0ab14c;
case 0x0c0ab14eu: goto P_0c0ab14e;
case 0x0c0ab150u: goto P_0c0ab150;
case 0x0c0ab152u: goto P_0c0ab152;
case 0x0c0ab154u: goto P_0c0ab154;
case 0x0c0ab156u: goto P_0c0ab156;
case 0x0c0ab158u: goto P_0c0ab158;
case 0x0c0ab15au: goto P_0c0ab15a;
case 0x0c0ab15cu: goto P_0c0ab15c;
case 0x0c0ab15eu: goto P_0c0ab15e;
case 0x0c0ab160u: goto P_0c0ab160;
case 0x0c0ab162u: goto P_0c0ab162;
case 0x0c0ab164u: goto P_0c0ab164;
case 0x0c0ab166u: goto P_0c0ab166;
case 0x0c0ab168u: goto P_0c0ab168;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09f1ac: /* original e048, guest PC 0x0c09f1ac */
if(!s->budget--) { s->failed_pc=0x0c09f1acu; return 0; }
r[0]=0x00000048u;
goto P_0c09f1ae;
P_0c09f1ae: /* original 2fe6, guest PC 0x0c09f1ae */
if(!s->budget--) { s->failed_pc=0x0c09f1aeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1b0;
P_0c09f1b0: /* original 2fd6, guest PC 0x0c09f1b0 */
if(!s->budget--) { s->failed_pc=0x0c09f1b0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1b2;
P_0c09f1b2: /* original e304, guest PC 0x0c09f1b2 */
if(!s->budget--) { s->failed_pc=0x0c09f1b2u; return 0; }
r[3]=0x00000004u;
goto P_0c09f1b4;
P_0c09f1b4: /* original 2fc6, guest PC 0x0c09f1b4 */
if(!s->budget--) { s->failed_pc=0x0c09f1b4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1b6;
P_0c09f1b6: /* original e520, guest PC 0x0c09f1b6 */
if(!s->budget--) { s->failed_pc=0x0c09f1b6u; return 0; }
r[5]=0x00000020u;
goto P_0c09f1b8;
P_0c09f1b8: /* original 2fb6, guest PC 0x0c09f1b8 */
if(!s->budget--) { s->failed_pc=0x0c09f1b8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1ba;
P_0c09f1ba: /* original e210, guest PC 0x0c09f1ba */
if(!s->budget--) { s->failed_pc=0x0c09f1bau; return 0; }
r[2]=0x00000010u;
goto P_0c09f1bc;
P_0c09f1bc: /* original 2fa6, guest PC 0x0c09f1bc */
if(!s->budget--) { s->failed_pc=0x0c09f1bcu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1be;
P_0c09f1be: /* original e700, guest PC 0x0c09f1be */
if(!s->budget--) { s->failed_pc=0x0c09f1beu; return 0; }
r[7]=0x00000000u;
goto P_0c09f1c0;
P_0c09f1c0: /* original 2f96, guest PC 0x0c09f1c0 */
if(!s->budget--) { s->failed_pc=0x0c09f1c0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1c2;
P_0c09f1c2: /* original 2f86, guest PC 0x0c09f1c2 */
if(!s->budget--) { s->failed_pc=0x0c09f1c2u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1c4;
P_0c09f1c4: /* original 064e, guest PC 0x0c09f1c4 */
if(!s->budget--) { s->failed_pc=0x0c09f1c4u; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c09f1c6;
P_0c09f1c6: /* original 7fec, guest PC 0x0c09f1c6 */
if(!s->budget--) { s->failed_pc=0x0c09f1c6u; return 0; }
r[15]+=0xffffffecu;
goto P_0c09f1c8;
P_0c09f1c8: /* original 2f32, guest PC 0x0c09f1c8 */
if(!s->budget--) { s->failed_pc=0x0c09f1c8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09f1ca;
P_0c09f1ca: /* original 9042, guest PC 0x0c09f1ca */
if(!s->budget--) { s->failed_pc=0x0c09f1cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f252u,2);
goto P_0c09f1cc;
P_0c09f1cc: /* original dc23, guest PC 0x0c09f1cc */
if(!s->budget--) { s->failed_pc=0x0c09f1ccu; return 0; }
r[12]=read(ram,0x0c09f25cu,4);
goto P_0c09f1ce;
P_0c09f1ce: /* original 0e4c, guest PC 0x0c09f1ce */
if(!s->budget--) { s->failed_pc=0x0c09f1ceu; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09f1d0;
P_0c09f1d0: /* original db21, guest PC 0x0c09f1d0 */
if(!s->budget--) { s->failed_pc=0x0c09f1d0u; return 0; }
r[11]=read(ram,0x0c09f258u,4);
goto P_0c09f1d2;
P_0c09f1d2: /* original 6eec, guest PC 0x0c09f1d2 */
if(!s->budget--) { s->failed_pc=0x0c09f1d2u; return 0; }
r[14]=r[14]&255u;
goto P_0c09f1d4;
P_0c09f1d4: /* original 60e3, guest PC 0x0c09f1d4 */
if(!s->budget--) { s->failed_pc=0x0c09f1d4u; return 0; }
r[0]=r[14];
goto P_0c09f1d6;
P_0c09f1d6: /* original 4001, guest PC 0x0c09f1d6 */
if(!s->budget--) { s->failed_pc=0x0c09f1d6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c09f1d8;
P_0c09f1d8: /* original 6303, guest PC 0x0c09f1d8 */
if(!s->budget--) { s->failed_pc=0x0c09f1d8u; return 0; }
r[3]=r[0];
goto P_0c09f1da;
P_0c09f1da: /* original 60e3, guest PC 0x0c09f1da */
if(!s->budget--) { s->failed_pc=0x0c09f1dau; return 0; }
r[0]=r[14];
goto P_0c09f1dc;
P_0c09f1dc: /* original c901, guest PC 0x0c09f1dc */
if(!s->budget--) { s->failed_pc=0x0c09f1dcu; return 0; }
r[0]&=1u;
goto P_0c09f1de;
P_0c09f1de: /* original 4005, guest PC 0x0c09f1de */
if(!s->budget--) { s->failed_pc=0x0c09f1deu; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1u)!=0);
r[0]=(r[0]>>1)|(r[0]<<31);
goto P_0c09f1e0;
P_0c09f1e0: /* original 203b, guest PC 0x0c09f1e0 */
if(!s->budget--) { s->failed_pc=0x0c09f1e0u; return 0; }
r[0]|=r[3];
goto P_0c09f1e2;
P_0c09f1e2: /* original 2509, guest PC 0x0c09f1e2 */
if(!s->budget--) { s->failed_pc=0x0c09f1e2u; return 0; }
r[5]&=r[0];
goto P_0c09f1e4;
P_0c09f1e4: /* original 9036, guest PC 0x0c09f1e4 */
if(!s->budget--) { s->failed_pc=0x0c09f1e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f254u,2);
goto P_0c09f1e6;
P_0c09f1e6: /* original 252b, guest PC 0x0c09f1e6 */
if(!s->budget--) { s->failed_pc=0x0c09f1e6u; return 0; }
r[5]|=r[2];
goto P_0c09f1e8;
P_0c09f1e8: /* original 034c, guest PC 0x0c09f1e8 */
if(!s->budget--) { s->failed_pc=0x0c09f1e8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09f1ea;
P_0c09f1ea: /* original 633c, guest PC 0x0c09f1ea */
if(!s->budget--) { s->failed_pc=0x0c09f1eau; return 0; }
r[3]=r[3]&255u;
goto P_0c09f1ec;
P_0c09f1ec: /* original 6853, guest PC 0x0c09f1ec */
if(!s->budget--) { s->failed_pc=0x0c09f1ecu; return 0; }
r[8]=r[5];
goto P_0c09f1ee;
P_0c09f1ee: /* original 1f31, guest PC 0x0c09f1ee */
if(!s->budget--) { s->failed_pc=0x0c09f1eeu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09f1f0;
P_0c09f1f0: /* original 61f2, guest PC 0x0c09f1f0 */
if(!s->budget--) { s->failed_pc=0x0c09f1f0u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c09f1f2;
P_0c09f1f2: /* original e902, guest PC 0x0c09f1f2 */
if(!s->budget--) { s->failed_pc=0x0c09f1f2u; return 0; }
r[9]=0x00000002u;
goto P_0c09f1f4;
P_0c09f1f4: /* original 2168, guest PC 0x0c09f1f4 */
if(!s->budget--) { s->failed_pc=0x0c09f1f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[6])==0)!=0);
goto P_0c09f1f6;
P_0c09f1f6: /* original 8f2a, guest PC 0x0c09f1f6 */
if(!s->budget--) { s->failed_pc=0x0c09f1f6u; return 0; }
cond=r[17]&1u;
r[8]|=r[9];
if(!cond) { goto P_0c09f24e; }
goto P_0c09f1fa;
P_0c09f1f8: /* original 289b, guest PC 0x0c09f1f8 */
if(!s->budget--) { s->failed_pc=0x0c09f1f8u; return 0; }
r[8]|=r[9];
goto P_0c09f1fa;
P_0c09f1fa: /* original 53f1, guest PC 0x0c09f1fa */
if(!s->budget--) { s->failed_pc=0x0c09f1fau; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09f1fc;
P_0c09f1fc: /* original 2338, guest PC 0x0c09f1fc */
if(!s->budget--) { s->failed_pc=0x0c09f1fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f1fe;
P_0c09f1fe: /* original 8b26, guest PC 0x0c09f1fe */
if(!s->budget--) { s->failed_pc=0x0c09f1feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f24e; }
goto P_0c09f200;
P_0c09f200: /* original d217, guest PC 0x0c09f200 */
if(!s->budget--) { s->failed_pc=0x0c09f200u; return 0; }
r[2]=read(ram,0x0c09f260u,4);
goto P_0c09f202;
P_0c09f202: /* original 2769, guest PC 0x0c09f202 */
if(!s->budget--) { s->failed_pc=0x0c09f202u; return 0; }
r[7]&=r[6];
goto P_0c09f204;
P_0c09f204: /* original 2b69, guest PC 0x0c09f204 */
if(!s->budget--) { s->failed_pc=0x0c09f204u; return 0; }
r[11]&=r[6];
goto P_0c09f206;
P_0c09f206: /* original 6323, guest PC 0x0c09f206 */
if(!s->budget--) { s->failed_pc=0x0c09f206u; return 0; }
r[3]=r[2];
goto P_0c09f208;
P_0c09f208: /* original 2f22, guest PC 0x0c09f208 */
if(!s->budget--) { s->failed_pc=0x0c09f208u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c09f20a;
P_0c09f20a: /* original 9d24, guest PC 0x0c09f20a */
if(!s->budget--) { s->failed_pc=0x0c09f20au; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f256u,2);
goto P_0c09f20c;
P_0c09f20c: /* original 2369, guest PC 0x0c09f20c */
if(!s->budget--) { s->failed_pc=0x0c09f20cu; return 0; }
r[3]&=r[6];
goto P_0c09f20e;
P_0c09f20e: /* original da15, guest PC 0x0c09f20e */
if(!s->budget--) { s->failed_pc=0x0c09f20eu; return 0; }
r[10]=read(ram,0x0c09f264u,4);
goto P_0c09f210;
P_0c09f210: /* original 2c69, guest PC 0x0c09f210 */
if(!s->budget--) { s->failed_pc=0x0c09f210u; return 0; }
r[12]&=r[6];
goto P_0c09f212;
P_0c09f212: /* original 2d69, guest PC 0x0c09f212 */
if(!s->budget--) { s->failed_pc=0x0c09f212u; return 0; }
r[13]&=r[6];
goto P_0c09f214;
P_0c09f214: /* original 1f31, guest PC 0x0c09f214 */
if(!s->budget--) { s->failed_pc=0x0c09f214u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09f216;
P_0c09f216: /* original 62f2, guest PC 0x0c09f216 */
if(!s->budget--) { s->failed_pc=0x0c09f216u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09f218;
P_0c09f218: /* original 26a9, guest PC 0x0c09f218 */
if(!s->budget--) { s->failed_pc=0x0c09f218u; return 0; }
r[6]&=r[10];
goto P_0c09f21a;
P_0c09f21a: /* original 3320, guest PC 0x0c09f21a */
if(!s->budget--) { s->failed_pc=0x0c09f21au; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c09f21c;
P_0c09f21c: /* original 0029, guest PC 0x0c09f21c */
if(!s->budget--) { s->failed_pc=0x0c09f21cu; return 0; }
r[0]=r[17]&1u;
goto P_0c09f21e;
P_0c09f21e: /* original 36a0, guest PC 0x0c09f21e */
if(!s->budget--) { s->failed_pc=0x0c09f21eu; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[10])!=0);
goto P_0c09f220;
P_0c09f220: /* original ca01, guest PC 0x0c09f220 */
if(!s->budget--) { s->failed_pc=0x0c09f220u; return 0; }
r[0]^=1u;
goto P_0c09f222;
P_0c09f222: /* original 2f02, guest PC 0x0c09f222 */
if(!s->budget--) { s->failed_pc=0x0c09f222u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c09f224;
P_0c09f224: /* original 0029, guest PC 0x0c09f224 */
if(!s->budget--) { s->failed_pc=0x0c09f224u; return 0; }
r[0]=r[17]&1u;
goto P_0c09f226;
P_0c09f226: /* original ca01, guest PC 0x0c09f226 */
if(!s->budget--) { s->failed_pc=0x0c09f226u; return 0; }
r[0]^=1u;
goto P_0c09f228;
P_0c09f228: /* original 1fb2, guest PC 0x0c09f228 */
if(!s->budget--) { s->failed_pc=0x0c09f228u; return 0; }
write(ram,r[15]+8,r[11],4);
goto P_0c09f22a;
P_0c09f22a: /* original 1fc3, guest PC 0x0c09f22a */
if(!s->budget--) { s->failed_pc=0x0c09f22au; return 0; }
write(ram,r[15]+12,r[12],4);
goto P_0c09f22c;
P_0c09f22c: /* original 1f04, guest PC 0x0c09f22c */
if(!s->budget--) { s->failed_pc=0x0c09f22cu; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c09f22e;
P_0c09f22e: /* original 1fd1, guest PC 0x0c09f22e */
if(!s->budget--) { s->failed_pc=0x0c09f22eu; return 0; }
write(ram,r[15]+4,r[13],4);
goto P_0c09f230;
P_0c09f230: /* original 62f2, guest PC 0x0c09f230 */
if(!s->budget--) { s->failed_pc=0x0c09f230u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09f232;
P_0c09f232: /* original 2228, guest PC 0x0c09f232 */
if(!s->budget--) { s->failed_pc=0x0c09f232u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09f234;
P_0c09f234: /* original 8d08, guest PC 0x0c09f234 */
if(!s->budget--) { s->failed_pc=0x0c09f234u; return 0; }
cond=r[17]&1u;
r[6]=0x00000001u;
if(cond) { goto P_0c09f248; }
goto P_0c09f238;
P_0c09f236: /* original e601, guest PC 0x0c09f236 */
if(!s->budget--) { s->failed_pc=0x0c09f236u; return 0; }
r[6]=0x00000001u;
goto P_0c09f238;
P_0c09f238: /* original 53f2, guest PC 0x0c09f238 */
if(!s->budget--) { s->failed_pc=0x0c09f238u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c09f23a;
P_0c09f23a: /* original 2338, guest PC 0x0c09f23a */
if(!s->budget--) { s->failed_pc=0x0c09f23au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f23c;
P_0c09f23c: /* original 8b14, guest PC 0x0c09f23c */
if(!s->budget--) { s->failed_pc=0x0c09f23cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f268; }
goto P_0c09f23e;
P_0c09f23e: /* original 2778, guest PC 0x0c09f23e */
if(!s->budget--) { s->failed_pc=0x0c09f23eu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c09f240;
P_0c09f240: /* original 8b03, guest PC 0x0c09f240 */
if(!s->budget--) { s->failed_pc=0x0c09f240u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f24a; }
goto P_0c09f242;
P_0c09f242: /* original 52f3, guest PC 0x0c09f242 */
if(!s->budget--) { s->failed_pc=0x0c09f242u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c09f244;
P_0c09f244: /* original 2228, guest PC 0x0c09f244 */
if(!s->budget--) { s->failed_pc=0x0c09f244u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09f246;
P_0c09f246: /* original 8b15, guest PC 0x0c09f246 */
if(!s->budget--) { s->failed_pc=0x0c09f246u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f274; }
goto P_0c09f248;
P_0c09f248: /* original 6583, guest PC 0x0c09f248 */
if(!s->budget--) { s->failed_pc=0x0c09f248u; return 0; }
r[5]=r[8];
goto P_0c09f24a;
P_0c09f24a: /* original a014, guest PC 0x0c09f24a */
if(!s->budget--) { s->failed_pc=0x0c09f24au; return 0; }
r[5]|=r[6];
goto P_0c09f276;
P_0c09f24c: /* original 256b, guest PC 0x0c09f24c */
if(!s->budget--) { s->failed_pc=0x0c09f24cu; return 0; }
r[5]|=r[6];
goto P_0c09f24e;
P_0c09f24e: /* original a012, guest PC 0x0c09f24e */
if(!s->budget--) { s->failed_pc=0x0c09f24eu; return 0; }
r[5]=r[8];
goto P_0c09f276;
P_0c09f250: /* original 6583, guest PC 0x0c09f250 */
if(!s->budget--) { s->failed_pc=0x0c09f250u; return 0; }
r[5]=r[8];
if(!vf3_matrix_family(0x0c09f252u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f252u; return 0; } return 1;
P_0c09f268: /* original e048, guest PC 0x0c09f268 */
if(!s->budget--) { s->failed_pc=0x0c09f268u; return 0; }
r[0]=0x00000048u;
goto P_0c09f26a;
P_0c09f26a: /* original d335, guest PC 0x0c09f26a */
if(!s->budget--) { s->failed_pc=0x0c09f26au; return 0; }
r[3]=read(ram,0x0c09f340u,4);
goto P_0c09f26c;
P_0c09f26c: /* original 024e, guest PC 0x0c09f26c */
if(!s->budget--) { s->failed_pc=0x0c09f26cu; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c09f26e;
P_0c09f26e: /* original 2238, guest PC 0x0c09f26e */
if(!s->budget--) { s->failed_pc=0x0c09f26eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09f270;
P_0c09f270: /* original 8b00, guest PC 0x0c09f270 */
if(!s->budget--) { s->failed_pc=0x0c09f270u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f274; }
goto P_0c09f272;
P_0c09f272: /* original 256b, guest PC 0x0c09f272 */
if(!s->budget--) { s->failed_pc=0x0c09f272u; return 0; }
r[5]|=r[6];
goto P_0c09f274;
P_0c09f274: /* original 259b, guest PC 0x0c09f274 */
if(!s->budget--) { s->failed_pc=0x0c09f274u; return 0; }
r[5]|=r[9];
goto P_0c09f276;
P_0c09f276: /* original 905e, guest PC 0x0c09f276 */
if(!s->budget--) { s->failed_pc=0x0c09f276u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f336u,2);
goto P_0c09f278;
P_0c09f278: /* original e30f, guest PC 0x0c09f278 */
if(!s->budget--) { s->failed_pc=0x0c09f278u; return 0; }
r[3]=0x0000000fu;
goto P_0c09f27a;
P_0c09f27a: /* original e208, guest PC 0x0c09f27a */
if(!s->budget--) { s->failed_pc=0x0c09f27au; return 0; }
r[2]=0x00000008u;
goto P_0c09f27c;
P_0c09f27c: /* original 0d4d, guest PC 0x0c09f27c */
if(!s->budget--) { s->failed_pc=0x0c09f27cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09f27e;
P_0c09f27e: /* original e03e, guest PC 0x0c09f27e */
if(!s->budget--) { s->failed_pc=0x0c09f27eu; return 0; }
r[0]=0x0000003eu;
goto P_0c09f280;
P_0c09f280: /* original 064d, guest PC 0x0c09f280 */
if(!s->budget--) { s->failed_pc=0x0c09f280u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09f282;
P_0c09f282: /* original 6ddd, guest PC 0x0c09f282 */
if(!s->budget--) { s->failed_pc=0x0c09f282u; return 0; }
r[13]=r[13]&65535u;
goto P_0c09f284;
P_0c09f284: /* original 67d3, guest PC 0x0c09f284 */
if(!s->budget--) { s->failed_pc=0x0c09f284u; return 0; }
r[7]=r[13];
goto P_0c09f286;
P_0c09f286: /* original 666d, guest PC 0x0c09f286 */
if(!s->budget--) { s->failed_pc=0x0c09f286u; return 0; }
r[6]=r[6]&65535u;
goto P_0c09f288;
P_0c09f288: /* original 3768, guest PC 0x0c09f288 */
if(!s->budget--) { s->failed_pc=0x0c09f288u; return 0; }
r[7]-=r[6];
goto P_0c09f28a;
P_0c09f28a: /* original 3732, guest PC 0x0c09f28a */
if(!s->budget--) { s->failed_pc=0x0c09f28au; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[3])!=0);
goto P_0c09f28c;
P_0c09f28c: /* original 0029, guest PC 0x0c09f28c */
if(!s->budget--) { s->failed_pc=0x0c09f28cu; return 0; }
r[0]=r[17]&1u;
goto P_0c09f28e;
P_0c09f28e: /* original 3726, guest PC 0x0c09f28e */
if(!s->budget--) { s->failed_pc=0x0c09f28eu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>r[2])!=0);
goto P_0c09f290;
P_0c09f290: /* original 1f02, guest PC 0x0c09f290 */
if(!s->budget--) { s->failed_pc=0x0c09f290u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c09f292;
P_0c09f292: /* original 0029, guest PC 0x0c09f292 */
if(!s->budget--) { s->failed_pc=0x0c09f292u; return 0; }
r[0]=r[17]&1u;
goto P_0c09f294;
P_0c09f294: /* original 1f03, guest PC 0x0c09f294 */
if(!s->budget--) { s->failed_pc=0x0c09f294u; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c09f296;
P_0c09f296: /* original 6763, guest PC 0x0c09f296 */
if(!s->budget--) { s->failed_pc=0x0c09f296u; return 0; }
r[7]=r[6];
goto P_0c09f298;
P_0c09f298: /* original 53f1, guest PC 0x0c09f298 */
if(!s->budget--) { s->failed_pc=0x0c09f298u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09f29a;
P_0c09f29a: /* original 2338, guest PC 0x0c09f29a */
if(!s->budget--) { s->failed_pc=0x0c09f29au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f29c;
P_0c09f29c: /* original 8f02, guest PC 0x0c09f29c */
if(!s->budget--) { s->failed_pc=0x0c09f29cu; return 0; }
cond=r[17]&1u;
r[7]+=0x0000000eu;
if(!cond) { goto P_0c09f2a4; }
goto P_0c09f2a0;
P_0c09f29e: /* original 770e, guest PC 0x0c09f29e */
if(!s->budget--) { s->failed_pc=0x0c09f29eu; return 0; }
r[7]+=0x0000000eu;
goto P_0c09f2a0;
P_0c09f2a0: /* original 6763, guest PC 0x0c09f2a0 */
if(!s->budget--) { s->failed_pc=0x0c09f2a0u; return 0; }
r[7]=r[6];
goto P_0c09f2a2;
P_0c09f2a2: /* original 7707, guest PC 0x0c09f2a2 */
if(!s->budget--) { s->failed_pc=0x0c09f2a2u; return 0; }
r[7]+=0x00000007u;
goto P_0c09f2a4;
P_0c09f2a4: /* original 6cd3, guest PC 0x0c09f2a4 */
if(!s->budget--) { s->failed_pc=0x0c09f2a4u; return 0; }
r[12]=r[13];
goto P_0c09f2a6;
P_0c09f2a6: /* original 7cf9, guest PC 0x0c09f2a6 */
if(!s->budget--) { s->failed_pc=0x0c09f2a6u; return 0; }
r[12]+=0xfffffff9u;
goto P_0c09f2a8;
P_0c09f2a8: /* original 2fc2, guest PC 0x0c09f2a8 */
if(!s->budget--) { s->failed_pc=0x0c09f2a8u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c09f2aa;
P_0c09f2aa: /* original 53f4, guest PC 0x0c09f2aa */
if(!s->budget--) { s->failed_pc=0x0c09f2aau; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c09f2ac;
P_0c09f2ac: /* original 2338, guest PC 0x0c09f2ac */
if(!s->budget--) { s->failed_pc=0x0c09f2acu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f2ae;
P_0c09f2ae: /* original 8b02, guest PC 0x0c09f2ae */
if(!s->budget--) { s->failed_pc=0x0c09f2aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f2b6; }
goto P_0c09f2b0;
P_0c09f2b0: /* original 6cf2, guest PC 0x0c09f2b0 */
if(!s->budget--) { s->failed_pc=0x0c09f2b0u; return 0; }
tmp=read(ram,r[15],4);
r[12]=tmp;
goto P_0c09f2b2;
P_0c09f2b2: /* original 6763, guest PC 0x0c09f2b2 */
if(!s->budget--) { s->failed_pc=0x0c09f2b2u; return 0; }
r[7]=r[6];
goto P_0c09f2b4;
P_0c09f2b4: /* original 7701, guest PC 0x0c09f2b4 */
if(!s->budget--) { s->failed_pc=0x0c09f2b4u; return 0; }
r[7]+=0x00000001u;
goto P_0c09f2b6;
P_0c09f2b6: /* original 53f2, guest PC 0x0c09f2b6 */
if(!s->budget--) { s->failed_pc=0x0c09f2b6u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c09f2b8;
P_0c09f2b8: /* original 2338, guest PC 0x0c09f2b8 */
if(!s->budget--) { s->failed_pc=0x0c09f2b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f2ba;
P_0c09f2ba: /* original 8b07, guest PC 0x0c09f2ba */
if(!s->budget--) { s->failed_pc=0x0c09f2bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f2cc; }
goto P_0c09f2bc;
P_0c09f2bc: /* original 52f3, guest PC 0x0c09f2bc */
if(!s->budget--) { s->failed_pc=0x0c09f2bcu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c09f2be;
P_0c09f2be: /* original 6c73, guest PC 0x0c09f2be */
if(!s->budget--) { s->failed_pc=0x0c09f2beu; return 0; }
r[12]=r[7];
goto P_0c09f2c0;
P_0c09f2c0: /* original 2228, guest PC 0x0c09f2c0 */
if(!s->budget--) { s->failed_pc=0x0c09f2c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09f2c2;
P_0c09f2c2: /* original 8f03, guest PC 0x0c09f2c2 */
if(!s->budget--) { s->failed_pc=0x0c09f2c2u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(!cond) { goto P_0c09f2cc; }
goto P_0c09f2c6;
P_0c09f2c4: /* original 7c01, guest PC 0x0c09f2c4 */
if(!s->budget--) { s->failed_pc=0x0c09f2c4u; return 0; }
r[12]+=0x00000001u;
goto P_0c09f2c6;
P_0c09f2c6: /* original 6cd3, guest PC 0x0c09f2c6 */
if(!s->budget--) { s->failed_pc=0x0c09f2c6u; return 0; }
r[12]=r[13];
goto P_0c09f2c8;
P_0c09f2c8: /* original 7c01, guest PC 0x0c09f2c8 */
if(!s->budget--) { s->failed_pc=0x0c09f2c8u; return 0; }
r[12]+=0x00000001u;
goto P_0c09f2ca;
P_0c09f2ca: /* original 67d3, guest PC 0x0c09f2ca */
if(!s->budget--) { s->failed_pc=0x0c09f2cau; return 0; }
r[7]=r[13];
goto P_0c09f2cc;
P_0c09f2cc: /* original 9034, guest PC 0x0c09f2cc */
if(!s->budget--) { s->failed_pc=0x0c09f2ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f338u,2);
goto P_0c09f2ce;
P_0c09f2ce: /* original e200, guest PC 0x0c09f2ce */
if(!s->budget--) { s->failed_pc=0x0c09f2ceu; return 0; }
r[2]=0x00000000u;
goto P_0c09f2d0;
P_0c09f2d0: /* original 76ff, guest PC 0x0c09f2d0 */
if(!s->budget--) { s->failed_pc=0x0c09f2d0u; return 0; }
r[6]+=0xffffffffu;
goto P_0c09f2d2;
P_0c09f2d2: /* original 0424, guest PC 0x0c09f2d2 */
if(!s->budget--) { s->failed_pc=0x0c09f2d2u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c09f2d4;
P_0c09f2d4: /* original 70f0, guest PC 0x0c09f2d4 */
if(!s->budget--) { s->failed_pc=0x0c09f2d4u; return 0; }
r[0]+=0xfffffff0u;
goto P_0c09f2d6;
P_0c09f2d6: /* original 0475, guest PC 0x0c09f2d6 */
if(!s->budget--) { s->failed_pc=0x0c09f2d6u; return 0; }
write(ram,r[4]+r[0],r[7],2);
goto P_0c09f2d8;
P_0c09f2d8: /* original 7002, guest PC 0x0c09f2d8 */
if(!s->budget--) { s->failed_pc=0x0c09f2d8u; return 0; }
r[0]+=0x00000002u;
goto P_0c09f2da;
P_0c09f2da: /* original 04c5, guest PC 0x0c09f2da */
if(!s->budget--) { s->failed_pc=0x0c09f2dau; return 0; }
write(ram,r[4]+r[0],r[12],2);
goto P_0c09f2dc;
P_0c09f2dc: /* original 7002, guest PC 0x0c09f2dc */
if(!s->budget--) { s->failed_pc=0x0c09f2dcu; return 0; }
r[0]+=0x00000002u;
goto P_0c09f2de;
P_0c09f2de: /* original 0465, guest PC 0x0c09f2de */
if(!s->budget--) { s->failed_pc=0x0c09f2deu; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c09f2e0;
P_0c09f2e0: /* original e04c, guest PC 0x0c09f2e0 */
if(!s->budget--) { s->failed_pc=0x0c09f2e0u; return 0; }
r[0]=0x0000004cu;
goto P_0c09f2e2;
P_0c09f2e2: /* original d318, guest PC 0x0c09f2e2 */
if(!s->budget--) { s->failed_pc=0x0c09f2e2u; return 0; }
r[3]=read(ram,0x0c09f344u,4);
goto P_0c09f2e4;
P_0c09f2e4: /* original 29e9, guest PC 0x0c09f2e4 */
if(!s->budget--) { s->failed_pc=0x0c09f2e4u; return 0; }
r[9]&=r[14];
goto P_0c09f2e6;
P_0c09f2e6: /* original 064e, guest PC 0x0c09f2e6 */
if(!s->budget--) { s->failed_pc=0x0c09f2e6u; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c09f2e8;
P_0c09f2e8: /* original 2369, guest PC 0x0c09f2e8 */
if(!s->budget--) { s->failed_pc=0x0c09f2e8u; return 0; }
r[3]&=r[6];
goto P_0c09f2ea;
P_0c09f2ea: /* original 1f31, guest PC 0x0c09f2ea */
if(!s->budget--) { s->failed_pc=0x0c09f2eau; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09f2ec;
P_0c09f2ec: /* original d716, guest PC 0x0c09f2ec */
if(!s->budget--) { s->failed_pc=0x0c09f2ecu; return 0; }
r[7]=read(ram,0x0c09f348u,4);
goto P_0c09f2ee;
P_0c09f2ee: /* original 2f92, guest PC 0x0c09f2ee */
if(!s->budget--) { s->failed_pc=0x0c09f2eeu; return 0; }
write(ram,r[15],r[9],4);
goto P_0c09f2f0;
P_0c09f2f0: /* original d216, guest PC 0x0c09f2f0 */
if(!s->budget--) { s->failed_pc=0x0c09f2f0u; return 0; }
r[2]=read(ram,0x0c09f34cu,4);
goto P_0c09f2f2;
P_0c09f2f2: /* original 2769, guest PC 0x0c09f2f2 */
if(!s->budget--) { s->failed_pc=0x0c09f2f2u; return 0; }
r[7]&=r[6];
goto P_0c09f2f4;
P_0c09f2f4: /* original 1f31, guest PC 0x0c09f2f4 */
if(!s->budget--) { s->failed_pc=0x0c09f2f4u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09f2f6;
P_0c09f2f6: /* original 2629, guest PC 0x0c09f2f6 */
if(!s->budget--) { s->failed_pc=0x0c09f2f6u; return 0; }
r[6]&=r[2];
goto P_0c09f2f8;
P_0c09f2f8: /* original 1f64, guest PC 0x0c09f2f8 */
if(!s->budget--) { s->failed_pc=0x0c09f2f8u; return 0; }
write(ram,r[15]+16,r[6],4);
goto P_0c09f2fa;
P_0c09f2fa: /* original 53f1, guest PC 0x0c09f2fa */
if(!s->budget--) { s->failed_pc=0x0c09f2fau; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09f2fc;
P_0c09f2fc: /* original 961d, guest PC 0x0c09f2fc */
if(!s->budget--) { s->failed_pc=0x0c09f2fcu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f33au,2);
goto P_0c09f2fe;
P_0c09f2fe: /* original 2338, guest PC 0x0c09f2fe */
if(!s->budget--) { s->failed_pc=0x0c09f2feu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f300;
P_0c09f300: /* original 8900, guest PC 0x0c09f300 */
if(!s->budget--) { s->failed_pc=0x0c09f300u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f304; }
goto P_0c09f302;
P_0c09f302: /* original 2569, guest PC 0x0c09f302 */
if(!s->budget--) { s->failed_pc=0x0c09f302u; return 0; }
r[5]&=r[6];
goto P_0c09f304;
P_0c09f304: /* original 2778, guest PC 0x0c09f304 */
if(!s->budget--) { s->failed_pc=0x0c09f304u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c09f306;
P_0c09f306: /* original 8901, guest PC 0x0c09f306 */
if(!s->budget--) { s->failed_pc=0x0c09f306u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f30c; }
goto P_0c09f308;
P_0c09f308: /* original 9218, guest PC 0x0c09f308 */
if(!s->budget--) { s->failed_pc=0x0c09f308u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f33cu,2);
goto P_0c09f30a;
P_0c09f30a: /* original 2529, guest PC 0x0c09f30a */
if(!s->budget--) { s->failed_pc=0x0c09f30au; return 0; }
r[5]&=r[2];
goto P_0c09f30c;
P_0c09f30c: /* original 63f2, guest PC 0x0c09f30c */
if(!s->budget--) { s->failed_pc=0x0c09f30cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09f30e;
P_0c09f30e: /* original 2338, guest PC 0x0c09f30e */
if(!s->budget--) { s->failed_pc=0x0c09f30eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f310;
P_0c09f310: /* original 8b00, guest PC 0x0c09f310 */
if(!s->budget--) { s->failed_pc=0x0c09f310u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f314; }
goto P_0c09f312;
P_0c09f312: /* original 2569, guest PC 0x0c09f312 */
if(!s->budget--) { s->failed_pc=0x0c09f312u; return 0; }
r[5]&=r[6];
goto P_0c09f314;
P_0c09f314: /* original 52f4, guest PC 0x0c09f314 */
if(!s->budget--) { s->failed_pc=0x0c09f314u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c09f316;
P_0c09f316: /* original 2228, guest PC 0x0c09f316 */
if(!s->budget--) { s->failed_pc=0x0c09f316u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09f318;
P_0c09f318: /* original 8901, guest PC 0x0c09f318 */
if(!s->budget--) { s->failed_pc=0x0c09f318u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f31e; }
goto P_0c09f31a;
P_0c09f31a: /* original e204, guest PC 0x0c09f31a */
if(!s->budget--) { s->failed_pc=0x0c09f31au; return 0; }
r[2]=0x00000004u;
goto P_0c09f31c;
P_0c09f31c: /* original 252b, guest PC 0x0c09f31c */
if(!s->budget--) { s->failed_pc=0x0c09f31cu; return 0; }
r[5]|=r[2];
goto P_0c09f31e;
P_0c09f31e: /* original 7f14, guest PC 0x0c09f31e */
if(!s->budget--) { s->failed_pc=0x0c09f31eu; return 0; }
r[15]+=0x00000014u;
goto P_0c09f320;
P_0c09f320: /* original 900d, guest PC 0x0c09f320 */
if(!s->budget--) { s->failed_pc=0x0c09f320u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f33eu,2);
goto P_0c09f322;
P_0c09f322: /* original 0454, guest PC 0x0c09f322 */
if(!s->budget--) { s->failed_pc=0x0c09f322u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c09f324;
P_0c09f324: /* original 68f6, guest PC 0x0c09f324 */
if(!s->budget--) { s->failed_pc=0x0c09f324u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09f326;
P_0c09f326: /* original d30a, guest PC 0x0c09f326 */
if(!s->budget--) { s->failed_pc=0x0c09f326u; return 0; }
r[3]=read(ram,0x0c09f350u,4);
goto P_0c09f328;
P_0c09f328: /* original 69f6, guest PC 0x0c09f328 */
if(!s->budget--) { s->failed_pc=0x0c09f328u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09f32a;
P_0c09f32a: /* original 6af6, guest PC 0x0c09f32a */
if(!s->budget--) { s->failed_pc=0x0c09f32au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09f32c;
P_0c09f32c: /* original 6bf6, guest PC 0x0c09f32c */
if(!s->budget--) { s->failed_pc=0x0c09f32cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09f32e;
P_0c09f32e: /* original 6cf6, guest PC 0x0c09f32e */
if(!s->budget--) { s->failed_pc=0x0c09f32eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09f330;
P_0c09f330: /* original 6df6, guest PC 0x0c09f330 */
if(!s->budget--) { s->failed_pc=0x0c09f330u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09f332;
P_0c09f332: /* original 432b, guest PC 0x0c09f332 */
if(!s->budget--) { s->failed_pc=0x0c09f332u; return 0; }
target=r[3];
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
P_0c09f334: /* original 6ef6, guest PC 0x0c09f334 */
if(!s->budget--) { s->failed_pc=0x0c09f334u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09f336u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f336u; return 0; } return 1;
P_0c0aa72e: /* original c73d, guest PC 0x0c0aa72e */
if(!s->budget--) { s->failed_pc=0x0c0aa72eu; return 0; }
r[0]=code_base|0x000aa824u;
goto P_0c0aa730;
P_0c0aa730: /* original f348, guest PC 0x0c0aa730 */
if(!s->budget--) { s->failed_pc=0x0c0aa730u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c0aa732;
P_0c0aa732: /* original f408, guest PC 0x0c0aa732 */
if(!s->budget--) { s->failed_pc=0x0c0aa732u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0aa734;
P_0c0aa734: /* original f342, guest PC 0x0c0aa734 */
if(!s->budget--) { s->failed_pc=0x0c0aa734u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0aa736;
P_0c0aa736: /* original f43a, guest PC 0x0c0aa736 */
if(!s->budget--) { s->failed_pc=0x0c0aa736u; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c0aa738;
P_0c0aa738: /* original f258, guest PC 0x0c0aa738 */
if(!s->budget--) { s->failed_pc=0x0c0aa738u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0aa73a;
P_0c0aa73a: /* original f242, guest PC 0x0c0aa73a */
if(!s->budget--) { s->failed_pc=0x0c0aa73au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c0aa73c;
P_0c0aa73c: /* original 000b, guest PC 0x0c0aa73c */
if(!s->budget--) { s->failed_pc=0x0c0aa73cu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,2,r[5]);
s->pc=target; return ram->oob==0;
P_0c0aa73e: /* original f52a, guest PC 0x0c0aa73e */
if(!s->budget--) { s->failed_pc=0x0c0aa73eu; return 0; }
vf3_matrix_store(s,ram,2,r[5]);
if(!vf3_matrix_family(0x0c0aa740u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aa740u; return 0; } return 1;
P_0c0aaf98: /* original 2fe6, guest PC 0x0c0aaf98 */
if(!s->budget--) { s->failed_pc=0x0c0aaf98u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aaf9a;
P_0c0aaf9a: /* original 6e43, guest PC 0x0c0aaf9a */
if(!s->budget--) { s->failed_pc=0x0c0aaf9au; return 0; }
r[14]=r[4];
goto P_0c0aaf9c;
P_0c0aaf9c: /* original 2fd6, guest PC 0x0c0aaf9c */
if(!s->budget--) { s->failed_pc=0x0c0aaf9cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aaf9e;
P_0c0aaf9e: /* original e058, guest PC 0x0c0aaf9e */
if(!s->budget--) { s->failed_pc=0x0c0aaf9eu; return 0; }
r[0]=0x00000058u;
goto P_0c0aafa0;
P_0c0aafa0: /* original 2fc6, guest PC 0x0c0aafa0 */
if(!s->budget--) { s->failed_pc=0x0c0aafa0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aafa2;
P_0c0aafa2: /* original 2fb6, guest PC 0x0c0aafa2 */
if(!s->budget--) { s->failed_pc=0x0c0aafa2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aafa4;
P_0c0aafa4: /* original 6b53, guest PC 0x0c0aafa4 */
if(!s->budget--) { s->failed_pc=0x0c0aafa4u; return 0; }
r[11]=r[5];
goto P_0c0aafa6;
P_0c0aafa6: /* original 2fa6, guest PC 0x0c0aafa6 */
if(!s->budget--) { s->failed_pc=0x0c0aafa6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aafa8;
P_0c0aafa8: /* original 0aee, guest PC 0x0c0aafa8 */
if(!s->budget--) { s->failed_pc=0x0c0aafa8u; return 0; }
r[10]=read(ram,r[14]+r[0],4);
goto P_0c0aafaa;
P_0c0aafaa: /* original 9088, guest PC 0x0c0aafaa */
if(!s->budget--) { s->failed_pc=0x0c0aafaau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab0beu,2);
goto P_0c0aafac;
P_0c0aafac: /* original f39d, guest PC 0x0c0aafac */
if(!s->budget--) { s->failed_pc=0x0c0aafacu; return 0; }
fr[3]=0x3f800000u;
goto P_0c0aafae;
P_0c0aafae: /* original f2e6, guest PC 0x0c0aafae */
if(!s->budget--) { s->failed_pc=0x0c0aafaeu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0aafb0;
P_0c0aafb0: /* original 4f22, guest PC 0x0c0aafb0 */
if(!s->budget--) { s->failed_pc=0x0c0aafb0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aafb2;
P_0c0aafb2: /* original f230, guest PC 0x0c0aafb2 */
if(!s->budget--) { s->failed_pc=0x0c0aafb2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0aafb4;
P_0c0aafb4: /* original 7ff0, guest PC 0x0c0aafb4 */
if(!s->budget--) { s->failed_pc=0x0c0aafb4u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0aafb6;
P_0c0aafb6: /* original fe27, guest PC 0x0c0aafb6 */
if(!s->budget--) { s->failed_pc=0x0c0aafb6u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0aafb8;
P_0c0aafb8: /* original e066, guest PC 0x0c0aafb8 */
if(!s->budget--) { s->failed_pc=0x0c0aafb8u; return 0; }
r[0]=0x00000066u;
goto P_0c0aafba;
P_0c0aafba: /* original 0ced, guest PC 0x0c0aafba */
if(!s->budget--) { s->failed_pc=0x0c0aafbau; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aafbc;
P_0c0aafbc: /* original 7cff, guest PC 0x0c0aafbc */
if(!s->budget--) { s->failed_pc=0x0c0aafbcu; return 0; }
r[12]+=0xffffffffu;
goto P_0c0aafbe;
P_0c0aafbe: /* original 4c11, guest PC 0x0c0aafbe */
if(!s->budget--) { s->failed_pc=0x0c0aafbeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=0)!=0);
goto P_0c0aafc0;
P_0c0aafc0: /* original 8d01, guest PC 0x0c0aafc0 */
if(!s->budget--) { s->failed_pc=0x0c0aafc0u; return 0; }
cond=r[17]&1u;
r[13]=r[6];
if(cond) { goto P_0c0aafc6; }
goto P_0c0aafc4;
P_0c0aafc2: /* original 6d63, guest PC 0x0c0aafc2 */
if(!s->budget--) { s->failed_pc=0x0c0aafc2u; return 0; }
r[13]=r[6];
goto P_0c0aafc4;
P_0c0aafc4: /* original ec00, guest PC 0x0c0aafc4 */
if(!s->budget--) { s->failed_pc=0x0c0aafc4u; return 0; }
r[12]=0x00000000u;
goto P_0c0aafc6;
P_0c0aafc6: /* original 0ec5, guest PC 0x0c0aafc6 */
if(!s->budget--) { s->failed_pc=0x0c0aafc6u; return 0; }
write(ram,r[14]+r[0],r[12],2);
goto P_0c0aafc8;
P_0c0aafc8: /* original 64d2, guest PC 0x0c0aafc8 */
if(!s->budget--) { s->failed_pc=0x0c0aafc8u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0aafca;
P_0c0aafca: /* original 4429, guest PC 0x0c0aafca */
if(!s->budget--) { s->failed_pc=0x0c0aafcau; return 0; }
r[4]>>=16;
goto P_0c0aafcc;
P_0c0aafcc: /* original 644c, guest PC 0x0c0aafcc */
if(!s->budget--) { s->failed_pc=0x0c0aafccu; return 0; }
r[4]=r[4]&255u;
goto P_0c0aafce;
P_0c0aafce: /* original 6043, guest PC 0x0c0aafce */
if(!s->budget--) { s->failed_pc=0x0c0aafceu; return 0; }
r[0]=r[4];
goto P_0c0aafd0;
P_0c0aafd0: /* original 8801, guest PC 0x0c0aafd0 */
if(!s->budget--) { s->failed_pc=0x0c0aafd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0aafd2;
P_0c0aafd2: /* original 8b03, guest PC 0x0c0aafd2 */
if(!s->budget--) { s->failed_pc=0x0c0aafd2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aafdc; }
goto P_0c0aafd4;
P_0c0aafd4: /* original d23d, guest PC 0x0c0aafd4 */
if(!s->budget--) { s->failed_pc=0x0c0aafd4u; return 0; }
r[2]=read(ram,0x0c0ab0ccu,4);
goto P_0c0aafd6;
P_0c0aafd6: /* original 65b3, guest PC 0x0c0aafd6 */
if(!s->budget--) { s->failed_pc=0x0c0aafd6u; return 0; }
r[5]=r[11];
goto P_0c0aafd8;
P_0c0aafd8: /* original 420b, guest PC 0x0c0aafd8 */
if(!s->budget--) { s->failed_pc=0x0c0aafd8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0aafdcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aafdcu) { target=s->pc; goto dispatch; }
goto P_0c0aafdc;
P_0c0aafda: /* original 64e3, guest PC 0x0c0aafda */
if(!s->budget--) { s->failed_pc=0x0c0aafdau; return 0; }
r[4]=r[14];
goto P_0c0aafdc;
P_0c0aafdc: /* original 50d1, guest PC 0x0c0aafdc */
if(!s->budget--) { s->failed_pc=0x0c0aafdcu; return 0; }
r[0]=read(ram,r[13]+4,4);
goto P_0c0aafde;
P_0c0aafde: /* original 8800, guest PC 0x0c0aafde */
if(!s->budget--) { s->failed_pc=0x0c0aafdeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0aafe0;
P_0c0aafe0: /* original 8907, guest PC 0x0c0aafe0 */
if(!s->budget--) { s->failed_pc=0x0c0aafe0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aaff2; }
goto P_0c0aafe2;
P_0c0aafe2: /* original 8801, guest PC 0x0c0aafe2 */
if(!s->budget--) { s->failed_pc=0x0c0aafe2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0aafe4;
P_0c0aafe4: /* original 894f, guest PC 0x0c0aafe4 */
if(!s->budget--) { s->failed_pc=0x0c0aafe4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab086; }
goto P_0c0aafe6;
P_0c0aafe6: /* original 8802, guest PC 0x0c0aafe6 */
if(!s->budget--) { s->failed_pc=0x0c0aafe6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0aafe8;
P_0c0aafe8: /* original 895c, guest PC 0x0c0aafe8 */
if(!s->budget--) { s->failed_pc=0x0c0aafe8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab0a4; }
goto P_0c0aafea;
P_0c0aafea: /* original 8803, guest PC 0x0c0aafea */
if(!s->budget--) { s->failed_pc=0x0c0aafeau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0aafec;
P_0c0aafec: /* original 8b01, guest PC 0x0c0aafec */
if(!s->budget--) { s->failed_pc=0x0c0aafecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aaff2; }
goto P_0c0aafee;
P_0c0aafee: /* original a083, guest PC 0x0c0aafee */
if(!s->budget--) { s->failed_pc=0x0c0aafeeu; return 0; }
goto P_0c0ab0f8;
P_0c0aaff0: /* original 0009, guest PC 0x0c0aaff0 */
if(!s->budget--) { s->failed_pc=0x0c0aaff0u; return 0; }
goto P_0c0aaff2;
P_0c0aaff2: /* original c738, guest PC 0x0c0aaff2 */
if(!s->budget--) { s->failed_pc=0x0c0aaff2u; return 0; }
r[0]=code_base|0x000ab0d4u;
goto P_0c0aaff4;
P_0c0aaff4: /* original d336, guest PC 0x0c0aaff4 */
if(!s->budget--) { s->failed_pc=0x0c0aaff4u; return 0; }
r[3]=read(ram,0x0c0ab0d0u,4);
goto P_0c0aaff6;
P_0c0aaff6: /* original 62e2, guest PC 0x0c0aaff6 */
if(!s->budget--) { s->failed_pc=0x0c0aaff6u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0aaff8;
P_0c0aaff8: /* original 65f3, guest PC 0x0c0aaff8 */
if(!s->budget--) { s->failed_pc=0x0c0aaff8u; return 0; }
r[5]=r[15];
goto P_0c0aaffa;
P_0c0aaffa: /* original 64f3, guest PC 0x0c0aaffa */
if(!s->budget--) { s->failed_pc=0x0c0aaffau; return 0; }
r[4]=r[15];
goto P_0c0aaffc;
P_0c0aaffc: /* original 223b, guest PC 0x0c0aaffc */
if(!s->budget--) { s->failed_pc=0x0c0aaffcu; return 0; }
r[2]|=r[3];
goto P_0c0aaffe;
P_0c0aaffe: /* original 2e22, guest PC 0x0c0aaffe */
if(!s->budget--) { s->failed_pc=0x0c0aaffeu; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0ab000;
P_0c0ab000: /* original f708, guest PC 0x0c0ab000 */
if(!s->budget--) { s->failed_pc=0x0c0ab000u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0ab002;
P_0c0ab002: /* original 905d, guest PC 0x0c0ab002 */
if(!s->budget--) { s->failed_pc=0x0c0ab002u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab0c0u,2);
goto P_0c0ab004;
P_0c0ab004: /* original f49d, guest PC 0x0c0ab004 */
if(!s->budget--) { s->failed_pc=0x0c0ab004u; return 0; }
fr[4]=0x3f800000u;
goto P_0c0ab006;
P_0c0ab006: /* original f5e6, guest PC 0x0c0ab006 */
if(!s->budget--) { s->failed_pc=0x0c0ab006u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0ab008;
P_0c0ab008: /* original 7008, guest PC 0x0c0ab008 */
if(!s->budget--) { s->failed_pc=0x0c0ab008u; return 0; }
r[0]+=0x00000008u;
goto P_0c0ab00a;
P_0c0ab00a: /* original f34c, guest PC 0x0c0ab00a */
if(!s->budget--) { s->failed_pc=0x0c0ab00au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0ab00c;
P_0c0ab00c: /* original f352, guest PC 0x0c0ab00c */
if(!s->budget--) { s->failed_pc=0x0c0ab00cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c0ab00e;
P_0c0ab00e: /* original f6e6, guest PC 0x0c0ab00e */
if(!s->budget--) { s->failed_pc=0x0c0ab00eu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0ab010;
P_0c0ab010: /* original e00c, guest PC 0x0c0ab010 */
if(!s->budget--) { s->failed_pc=0x0c0ab010u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab012;
P_0c0ab012: /* original f462, guest PC 0x0c0ab012 */
if(!s->budget--) { s->failed_pc=0x0c0ab012u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0ab014;
P_0c0ab014: /* original ff37, guest PC 0x0c0ab014 */
if(!s->budget--) { s->failed_pc=0x0c0ab014u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab016;
P_0c0ab016: /* original e008, guest PC 0x0c0ab016 */
if(!s->budget--) { s->failed_pc=0x0c0ab016u; return 0; }
r[0]=0x00000008u;
goto P_0c0ab018;
P_0c0ab018: /* original ff47, guest PC 0x0c0ab018 */
if(!s->budget--) { s->failed_pc=0x0c0ab018u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0ab01a;
P_0c0ab01a: /* original e004, guest PC 0x0c0ab01a */
if(!s->budget--) { s->failed_pc=0x0c0ab01au; return 0; }
r[0]=0x00000004u;
goto P_0c0ab01c;
P_0c0ab01c: /* original f27c, guest PC 0x0c0ab01c */
if(!s->budget--) { s->failed_pc=0x0c0ab01cu; return 0; }
vf3_matrix_move(s,2,7);
goto P_0c0ab01e;
P_0c0ab01e: /* original f252, guest PC 0x0c0ab01e */
if(!s->budget--) { s->failed_pc=0x0c0ab01eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'*');
goto P_0c0ab020;
P_0c0ab020: /* original f762, guest PC 0x0c0ab020 */
if(!s->budget--) { s->failed_pc=0x0c0ab020u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'*');
goto P_0c0ab022;
P_0c0ab022: /* original ff27, guest PC 0x0c0ab022 */
if(!s->budget--) { s->failed_pc=0x0c0ab022u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0ab024;
P_0c0ab024: /* original ff7a, guest PC 0x0c0ab024 */
if(!s->budget--) { s->failed_pc=0x0c0ab024u; return 0; }
vf3_matrix_store(s,ram,7,r[15]);
goto P_0c0ab026;
P_0c0ab026: /* original bb82, guest PC 0x0c0ab026 */
if(!s->budget--) { s->failed_pc=0x0c0ab026u; return 0; }
target=code_base|0x0c0aa72eu; r[16]=code_base|0x0c0ab02au;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab02au) { target=s->pc; goto dispatch; }
goto P_0c0ab02a;
P_0c0ab028: /* original 7404, guest PC 0x0c0ab028 */
if(!s->budget--) { s->failed_pc=0x0c0ab028u; return 0; }
r[4]+=0x00000004u;
goto P_0c0ab02a;
P_0c0ab02a: /* original e00c, guest PC 0x0c0ab02a */
if(!s->budget--) { s->failed_pc=0x0c0ab02au; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab02c;
P_0c0ab02c: /* original f3f6, guest PC 0x0c0ab02c */
if(!s->budget--) { s->failed_pc=0x0c0ab02cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab02e;
P_0c0ab02e: /* original e024, guest PC 0x0c0ab02e */
if(!s->budget--) { s->failed_pc=0x0c0ab02eu; return 0; }
r[0]=0x00000024u;
goto P_0c0ab030;
P_0c0ab030: /* original fe37, guest PC 0x0c0ab030 */
if(!s->budget--) { s->failed_pc=0x0c0ab030u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab032;
P_0c0ab032: /* original e008, guest PC 0x0c0ab032 */
if(!s->budget--) { s->failed_pc=0x0c0ab032u; return 0; }
r[0]=0x00000008u;
goto P_0c0ab034;
P_0c0ab034: /* original f3f6, guest PC 0x0c0ab034 */
if(!s->budget--) { s->failed_pc=0x0c0ab034u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab036;
P_0c0ab036: /* original e02c, guest PC 0x0c0ab036 */
if(!s->budget--) { s->failed_pc=0x0c0ab036u; return 0; }
r[0]=0x0000002cu;
goto P_0c0ab038;
P_0c0ab038: /* original fe37, guest PC 0x0c0ab038 */
if(!s->budget--) { s->failed_pc=0x0c0ab038u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab03a;
P_0c0ab03a: /* original e004, guest PC 0x0c0ab03a */
if(!s->budget--) { s->failed_pc=0x0c0ab03au; return 0; }
r[0]=0x00000004u;
goto P_0c0ab03c;
P_0c0ab03c: /* original f3f6, guest PC 0x0c0ab03c */
if(!s->budget--) { s->failed_pc=0x0c0ab03cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab03e;
P_0c0ab03e: /* original 9040, guest PC 0x0c0ab03e */
if(!s->budget--) { s->failed_pc=0x0c0ab03eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab0c2u,2);
goto P_0c0ab040;
P_0c0ab040: /* original fe37, guest PC 0x0c0ab040 */
if(!s->budget--) { s->failed_pc=0x0c0ab040u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab042;
P_0c0ab042: /* original 903f, guest PC 0x0c0ab042 */
if(!s->budget--) { s->failed_pc=0x0c0ab042u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab0c4u,2);
goto P_0c0ab044;
P_0c0ab044: /* original f3f8, guest PC 0x0c0ab044 */
if(!s->budget--) { s->failed_pc=0x0c0ab044u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0ab046;
P_0c0ab046: /* original fe37, guest PC 0x0c0ab046 */
if(!s->budget--) { s->failed_pc=0x0c0ab046u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab048;
P_0c0ab048: /* original 65d2, guest PC 0x0c0ab048 */
if(!s->budget--) { s->failed_pc=0x0c0ab048u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0ab04a;
P_0c0ab04a: /* original 655d, guest PC 0x0c0ab04a */
if(!s->budget--) { s->failed_pc=0x0c0ab04au; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ab04c;
P_0c0ab04c: /* original 2558, guest PC 0x0c0ab04c */
if(!s->budget--) { s->failed_pc=0x0c0ab04cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0ab04e;
P_0c0ab04e: /* original 8b08, guest PC 0x0c0ab04e */
if(!s->budget--) { s->failed_pc=0x0c0ab04eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab062; }
goto P_0c0ab050;
P_0c0ab050: /* original 85ae, guest PC 0x0c0ab050 */
if(!s->budget--) { s->failed_pc=0x0c0ab050u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+28,2);
goto P_0c0ab052;
P_0c0ab052: /* original d321, guest PC 0x0c0ab052 */
if(!s->budget--) { s->failed_pc=0x0c0ab052u; return 0; }
r[3]=read(ram,0x0c0ab0d8u,4);
goto P_0c0ab054;
P_0c0ab054: /* original 650d, guest PC 0x0c0ab054 */
if(!s->budget--) { s->failed_pc=0x0c0ab054u; return 0; }
r[5]=r[0]&65535u;
goto P_0c0ab056;
P_0c0ab056: /* original e048, guest PC 0x0c0ab056 */
if(!s->budget--) { s->failed_pc=0x0c0ab056u; return 0; }
r[0]=0x00000048u;
goto P_0c0ab058;
P_0c0ab058: /* original 02ee, guest PC 0x0c0ab058 */
if(!s->budget--) { s->failed_pc=0x0c0ab058u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ab05a;
P_0c0ab05a: /* original 2238, guest PC 0x0c0ab05a */
if(!s->budget--) { s->failed_pc=0x0c0ab05au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab05c;
P_0c0ab05c: /* original 8b01, guest PC 0x0c0ab05c */
if(!s->budget--) { s->failed_pc=0x0c0ab05cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab062; }
goto P_0c0ab05e;
P_0c0ab05e: /* original 85ac, guest PC 0x0c0ab05e */
if(!s->budget--) { s->failed_pc=0x0c0ab05eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+24,2);
goto P_0c0ab060;
P_0c0ab060: /* original 650d, guest PC 0x0c0ab060 */
if(!s->budget--) { s->failed_pc=0x0c0ab060u; return 0; }
r[5]=r[0]&65535u;
goto P_0c0ab062;
P_0c0ab062: /* original d31e, guest PC 0x0c0ab062 */
if(!s->budget--) { s->failed_pc=0x0c0ab062u; return 0; }
r[3]=read(ram,0x0c0ab0dcu,4);
goto P_0c0ab064;
P_0c0ab064: /* original 430b, guest PC 0x0c0ab064 */
if(!s->budget--) { s->failed_pc=0x0c0ab064u; return 0; }
target=r[3];
r[16]=code_base|0x0c0ab068u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab068u) { target=s->pc; goto dispatch; }
goto P_0c0ab068;
P_0c0ab066: /* original 64e3, guest PC 0x0c0ab066 */
if(!s->budget--) { s->failed_pc=0x0c0ab066u; return 0; }
r[4]=r[14];
goto P_0c0ab068;
P_0c0ab068: /* original e048, guest PC 0x0c0ab068 */
if(!s->budget--) { s->failed_pc=0x0c0ab068u; return 0; }
r[0]=0x00000048u;
goto P_0c0ab06a;
P_0c0ab06a: /* original d31d, guest PC 0x0c0ab06a */
if(!s->budget--) { s->failed_pc=0x0c0ab06au; return 0; }
r[3]=read(ram,0x0c0ab0e0u,4);
goto P_0c0ab06c;
P_0c0ab06c: /* original 02ee, guest PC 0x0c0ab06c */
if(!s->budget--) { s->failed_pc=0x0c0ab06cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ab06e;
P_0c0ab06e: /* original 223b, guest PC 0x0c0ab06e */
if(!s->budget--) { s->failed_pc=0x0c0ab06eu; return 0; }
r[2]|=r[3];
goto P_0c0ab070;
P_0c0ab070: /* original 0e26, guest PC 0x0c0ab070 */
if(!s->budget--) { s->failed_pc=0x0c0ab070u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0ab072;
P_0c0ab072: /* original 9028, guest PC 0x0c0ab072 */
if(!s->budget--) { s->failed_pc=0x0c0ab072u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab0c6u,2);
goto P_0c0ab074;
P_0c0ab074: /* original 01ed, guest PC 0x0c0ab074 */
if(!s->budget--) { s->failed_pc=0x0c0ab074u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab076;
P_0c0ab076: /* original e03e, guest PC 0x0c0ab076 */
if(!s->budget--) { s->failed_pc=0x0c0ab076u; return 0; }
r[0]=0x0000003eu;
goto P_0c0ab078;
P_0c0ab078: /* original 0e15, guest PC 0x0c0ab078 */
if(!s->budget--) { s->failed_pc=0x0c0ab078u; return 0; }
write(ram,r[14]+r[0],r[1],2);
goto P_0c0ab07a;
P_0c0ab07a: /* original e062, guest PC 0x0c0ab07a */
if(!s->budget--) { s->failed_pc=0x0c0ab07au; return 0; }
r[0]=0x00000062u;
goto P_0c0ab07c;
P_0c0ab07c: /* original 52d1, guest PC 0x0c0ab07c */
if(!s->budget--) { s->failed_pc=0x0c0ab07cu; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0ab07e;
P_0c0ab07e: /* original 7201, guest PC 0x0c0ab07e */
if(!s->budget--) { s->failed_pc=0x0c0ab07eu; return 0; }
r[2]+=0x00000001u;
goto P_0c0ab080;
P_0c0ab080: /* original 6123, guest PC 0x0c0ab080 */
if(!s->budget--) { s->failed_pc=0x0c0ab080u; return 0; }
r[1]=r[2];
goto P_0c0ab082;
P_0c0ab082: /* original 1d21, guest PC 0x0c0ab082 */
if(!s->budget--) { s->failed_pc=0x0c0ab082u; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0ab084;
P_0c0ab084: /* original 0e14, guest PC 0x0c0ab084 */
if(!s->budget--) { s->failed_pc=0x0c0ab084u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c0ab086;
P_0c0ab086: /* original e03e, guest PC 0x0c0ab086 */
if(!s->budget--) { s->failed_pc=0x0c0ab086u; return 0; }
r[0]=0x0000003eu;
goto P_0c0ab088;
P_0c0ab088: /* original 05ed, guest PC 0x0c0ab088 */
if(!s->budget--) { s->failed_pc=0x0c0ab088u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab08a;
P_0c0ab08a: /* original 901d, guest PC 0x0c0ab08a */
if(!s->budget--) { s->failed_pc=0x0c0ab08au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab0c8u,2);
goto P_0c0ab08c;
P_0c0ab08c: /* original 655d, guest PC 0x0c0ab08c */
if(!s->budget--) { s->failed_pc=0x0c0ab08cu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ab08e;
P_0c0ab08e: /* original 04ed, guest PC 0x0c0ab08e */
if(!s->budget--) { s->failed_pc=0x0c0ab08eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab090;
P_0c0ab090: /* original 644d, guest PC 0x0c0ab090 */
if(!s->budget--) { s->failed_pc=0x0c0ab090u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0ab092;
P_0c0ab092: /* original 74ff, guest PC 0x0c0ab092 */
if(!s->budget--) { s->failed_pc=0x0c0ab092u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0ab094;
P_0c0ab094: /* original 3542, guest PC 0x0c0ab094 */
if(!s->budget--) { s->failed_pc=0x0c0ab094u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[4])!=0);
goto P_0c0ab096;
P_0c0ab096: /* original 8b60, guest PC 0x0c0ab096 */
if(!s->budget--) { s->failed_pc=0x0c0ab096u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab15a; }
goto P_0c0ab098;
P_0c0ab098: /* original 52d1, guest PC 0x0c0ab098 */
if(!s->budget--) { s->failed_pc=0x0c0ab098u; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0ab09a;
P_0c0ab09a: /* original e062, guest PC 0x0c0ab09a */
if(!s->budget--) { s->failed_pc=0x0c0ab09au; return 0; }
r[0]=0x00000062u;
goto P_0c0ab09c;
P_0c0ab09c: /* original 7201, guest PC 0x0c0ab09c */
if(!s->budget--) { s->failed_pc=0x0c0ab09cu; return 0; }
r[2]+=0x00000001u;
goto P_0c0ab09e;
P_0c0ab09e: /* original 6323, guest PC 0x0c0ab09e */
if(!s->budget--) { s->failed_pc=0x0c0ab09eu; return 0; }
r[3]=r[2];
goto P_0c0ab0a0;
P_0c0ab0a0: /* original 1d21, guest PC 0x0c0ab0a0 */
if(!s->budget--) { s->failed_pc=0x0c0ab0a0u; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0ab0a2;
P_0c0ab0a2: /* original 0e34, guest PC 0x0c0ab0a2 */
if(!s->budget--) { s->failed_pc=0x0c0ab0a2u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ab0a4;
P_0c0ab0a4: /* original 9010, guest PC 0x0c0ab0a4 */
if(!s->budget--) { s->failed_pc=0x0c0ab0a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab0c8u,2);
goto P_0c0ab0a6;
P_0c0ab0a6: /* original 04ed, guest PC 0x0c0ab0a6 */
if(!s->budget--) { s->failed_pc=0x0c0ab0a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab0a8;
P_0c0ab0a8: /* original 7002, guest PC 0x0c0ab0a8 */
if(!s->budget--) { s->failed_pc=0x0c0ab0a8u; return 0; }
r[0]+=0x00000002u;
goto P_0c0ab0aa;
P_0c0ab0aa: /* original 05ed, guest PC 0x0c0ab0aa */
if(!s->budget--) { s->failed_pc=0x0c0ab0aau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab0ac;
P_0c0ab0ac: /* original 644d, guest PC 0x0c0ab0ac */
if(!s->budget--) { s->failed_pc=0x0c0ab0acu; return 0; }
r[4]=r[4]&65535u;
goto P_0c0ab0ae;
P_0c0ab0ae: /* original 655d, guest PC 0x0c0ab0ae */
if(!s->budget--) { s->failed_pc=0x0c0ab0aeu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ab0b0;
P_0c0ab0b0: /* original 35c8, guest PC 0x0c0ab0b0 */
if(!s->budget--) { s->failed_pc=0x0c0ab0b0u; return 0; }
r[5]-=r[12];
goto P_0c0ab0b2;
P_0c0ab0b2: /* original 74ff, guest PC 0x0c0ab0b2 */
if(!s->budget--) { s->failed_pc=0x0c0ab0b2u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0ab0b4;
P_0c0ab0b4: /* original 3453, guest PC 0x0c0ab0b4 */
if(!s->budget--) { s->failed_pc=0x0c0ab0b4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c0ab0b6;
P_0c0ab0b6: /* original 8b15, guest PC 0x0c0ab0b6 */
if(!s->budget--) { s->failed_pc=0x0c0ab0b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab0e4; }
goto P_0c0ab0b8;
P_0c0ab0b8: /* original e03e, guest PC 0x0c0ab0b8 */
if(!s->budget--) { s->failed_pc=0x0c0ab0b8u; return 0; }
r[0]=0x0000003eu;
goto P_0c0ab0ba;
P_0c0ab0ba: /* original a02a, guest PC 0x0c0ab0ba */
if(!s->budget--) { s->failed_pc=0x0c0ab0bau; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0ab112;
P_0c0ab0bc: /* original 0e45, guest PC 0x0c0ab0bc */
if(!s->budget--) { s->failed_pc=0x0c0ab0bcu; return 0; }
write(ram,r[14]+r[0],r[4],2);
if(!vf3_matrix_family(0x0c0ab0beu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ab0beu; return 0; } return 1;
P_0c0ab0e4: /* original 62e2, guest PC 0x0c0ab0e4 */
if(!s->budget--) { s->failed_pc=0x0c0ab0e4u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0ab0e6;
P_0c0ab0e6: /* original e062, guest PC 0x0c0ab0e6 */
if(!s->budget--) { s->failed_pc=0x0c0ab0e6u; return 0; }
r[0]=0x00000062u;
goto P_0c0ab0e8;
P_0c0ab0e8: /* original d321, guest PC 0x0c0ab0e8 */
if(!s->budget--) { s->failed_pc=0x0c0ab0e8u; return 0; }
r[3]=read(ram,0x0c0ab170u,4);
goto P_0c0ab0ea;
P_0c0ab0ea: /* original 2239, guest PC 0x0c0ab0ea */
if(!s->budget--) { s->failed_pc=0x0c0ab0eau; return 0; }
r[2]&=r[3];
goto P_0c0ab0ec;
P_0c0ab0ec: /* original 2e22, guest PC 0x0c0ab0ec */
if(!s->budget--) { s->failed_pc=0x0c0ab0ecu; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0ab0ee;
P_0c0ab0ee: /* original 51d1, guest PC 0x0c0ab0ee */
if(!s->budget--) { s->failed_pc=0x0c0ab0eeu; return 0; }
r[1]=read(ram,r[13]+4,4);
goto P_0c0ab0f0;
P_0c0ab0f0: /* original 7101, guest PC 0x0c0ab0f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab0f0u; return 0; }
r[1]+=0x00000001u;
goto P_0c0ab0f2;
P_0c0ab0f2: /* original 6213, guest PC 0x0c0ab0f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab0f2u; return 0; }
r[2]=r[1];
goto P_0c0ab0f4;
P_0c0ab0f4: /* original 1d11, guest PC 0x0c0ab0f4 */
if(!s->budget--) { s->failed_pc=0x0c0ab0f4u; return 0; }
write(ram,r[13]+4,r[1],4);
goto P_0c0ab0f6;
P_0c0ab0f6: /* original 0e24, guest PC 0x0c0ab0f6 */
if(!s->budget--) { s->failed_pc=0x0c0ab0f6u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0ab0f8;
P_0c0ab0f8: /* original 4c15, guest PC 0x0c0ab0f8 */
if(!s->budget--) { s->failed_pc=0x0c0ab0f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>0)!=0);
goto P_0c0ab0fa;
P_0c0ab0fa: /* original 890a, guest PC 0x0c0ab0fa */
if(!s->budget--) { s->failed_pc=0x0c0ab0fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab112; }
goto P_0c0ab0fc;
P_0c0ab0fc: /* original e300, guest PC 0x0c0ab0fc */
if(!s->budget--) { s->failed_pc=0x0c0ab0fcu; return 0; }
r[3]=0x00000000u;
goto P_0c0ab0fe;
P_0c0ab0fe: /* original e048, guest PC 0x0c0ab0fe */
if(!s->budget--) { s->failed_pc=0x0c0ab0feu; return 0; }
r[0]=0x00000048u;
goto P_0c0ab100;
P_0c0ab100: /* original 1e3e, guest PC 0x0c0ab100 */
if(!s->budget--) { s->failed_pc=0x0c0ab100u; return 0; }
write(ram,r[14]+56,r[3],4);
goto P_0c0ab102;
P_0c0ab102: /* original 02ee, guest PC 0x0c0ab102 */
if(!s->budget--) { s->failed_pc=0x0c0ab102u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ab104;
P_0c0ab104: /* original d31b, guest PC 0x0c0ab104 */
if(!s->budget--) { s->failed_pc=0x0c0ab104u; return 0; }
r[3]=read(ram,0x0c0ab174u,4);
goto P_0c0ab106;
P_0c0ab106: /* original 2239, guest PC 0x0c0ab106 */
if(!s->budget--) { s->failed_pc=0x0c0ab106u; return 0; }
r[2]&=r[3];
goto P_0c0ab108;
P_0c0ab108: /* original 0e26, guest PC 0x0c0ab108 */
if(!s->budget--) { s->failed_pc=0x0c0ab108u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0ab10a;
P_0c0ab10a: /* original 61e2, guest PC 0x0c0ab10a */
if(!s->budget--) { s->failed_pc=0x0c0ab10au; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0ab10c;
P_0c0ab10c: /* original d218, guest PC 0x0c0ab10c */
if(!s->budget--) { s->failed_pc=0x0c0ab10cu; return 0; }
r[2]=read(ram,0x0c0ab170u,4);
goto P_0c0ab10e;
P_0c0ab10e: /* original 2129, guest PC 0x0c0ab10e */
if(!s->budget--) { s->failed_pc=0x0c0ab10eu; return 0; }
r[1]&=r[2];
goto P_0c0ab110;
P_0c0ab110: /* original 2e12, guest PC 0x0c0ab110 */
if(!s->budget--) { s->failed_pc=0x0c0ab110u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0ab112;
P_0c0ab112: /* original 902a, guest PC 0x0c0ab112 */
if(!s->budget--) { s->failed_pc=0x0c0ab112u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab16au,2);
goto P_0c0ab114;
P_0c0ab114: /* original 03bd, guest PC 0x0c0ab114 */
if(!s->budget--) { s->failed_pc=0x0c0ab114u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c0ab116;
P_0c0ab116: /* original 7004, guest PC 0x0c0ab116 */
if(!s->budget--) { s->failed_pc=0x0c0ab116u; return 0; }
r[0]+=0x00000004u;
goto P_0c0ab118;
P_0c0ab118: /* original 02ed, guest PC 0x0c0ab118 */
if(!s->budget--) { s->failed_pc=0x0c0ab118u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab11a;
P_0c0ab11a: /* original 3320, guest PC 0x0c0ab11a */
if(!s->budget--) { s->failed_pc=0x0c0ab11au; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0ab11c;
P_0c0ab11c: /* original 891d, guest PC 0x0c0ab11c */
if(!s->budget--) { s->failed_pc=0x0c0ab11cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab15a; }
goto P_0c0ab11e;
P_0c0ab11e: /* original 9025, guest PC 0x0c0ab11e */
if(!s->budget--) { s->failed_pc=0x0c0ab11eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab16cu,2);
goto P_0c0ab120;
P_0c0ab120: /* original d315, guest PC 0x0c0ab120 */
if(!s->budget--) { s->failed_pc=0x0c0ab120u; return 0; }
r[3]=read(ram,0x0c0ab178u,4);
goto P_0c0ab122;
P_0c0ab122: /* original 04be, guest PC 0x0c0ab122 */
if(!s->budget--) { s->failed_pc=0x0c0ab122u; return 0; }
r[4]=read(ram,r[11]+r[0],4);
goto P_0c0ab124;
P_0c0ab124: /* original 2348, guest PC 0x0c0ab124 */
if(!s->budget--) { s->failed_pc=0x0c0ab124u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0ab126;
P_0c0ab126: /* original 8b02, guest PC 0x0c0ab126 */
if(!s->budget--) { s->failed_pc=0x0c0ab126u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab12e; }
goto P_0c0ab128;
P_0c0ab128: /* original d114, guest PC 0x0c0ab128 */
if(!s->budget--) { s->failed_pc=0x0c0ab128u; return 0; }
r[1]=read(ram,0x0c0ab17cu,4);
goto P_0c0ab12a;
P_0c0ab12a: /* original 2148, guest PC 0x0c0ab12a */
if(!s->budget--) { s->failed_pc=0x0c0ab12au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c0ab12c;
P_0c0ab12c: /* original 8915, guest PC 0x0c0ab12c */
if(!s->budget--) { s->failed_pc=0x0c0ab12cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab15a; }
goto P_0c0ab12e;
P_0c0ab12e: /* original e048, guest PC 0x0c0ab12e */
if(!s->budget--) { s->failed_pc=0x0c0ab12eu; return 0; }
r[0]=0x00000048u;
goto P_0c0ab130;
P_0c0ab130: /* original d313, guest PC 0x0c0ab130 */
if(!s->budget--) { s->failed_pc=0x0c0ab130u; return 0; }
r[3]=read(ram,0x0c0ab180u,4);
goto P_0c0ab132;
P_0c0ab132: /* original 02ee, guest PC 0x0c0ab132 */
if(!s->budget--) { s->failed_pc=0x0c0ab132u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ab134;
P_0c0ab134: /* original 2238, guest PC 0x0c0ab134 */
if(!s->budget--) { s->failed_pc=0x0c0ab134u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab136;
P_0c0ab136: /* original 8902, guest PC 0x0c0ab136 */
if(!s->budget--) { s->failed_pc=0x0c0ab136u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab13e; }
goto P_0c0ab138;
P_0c0ab138: /* original d212, guest PC 0x0c0ab138 */
if(!s->budget--) { s->failed_pc=0x0c0ab138u; return 0; }
r[2]=read(ram,0x0c0ab184u,4);
goto P_0c0ab13a;
P_0c0ab13a: /* original 2428, guest PC 0x0c0ab13a */
if(!s->budget--) { s->failed_pc=0x0c0ab13au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0ab13c;
P_0c0ab13c: /* original 8b0d, guest PC 0x0c0ab13c */
if(!s->budget--) { s->failed_pc=0x0c0ab13cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab15a; }
goto P_0c0ab13e;
P_0c0ab13e: /* original d212, guest PC 0x0c0ab13e */
if(!s->budget--) { s->failed_pc=0x0c0ab13eu; return 0; }
r[2]=read(ram,0x0c0ab188u,4);
goto P_0c0ab140;
P_0c0ab140: /* original 65b3, guest PC 0x0c0ab140 */
if(!s->budget--) { s->failed_pc=0x0c0ab140u; return 0; }
r[5]=r[11];
goto P_0c0ab142;
P_0c0ab142: /* original 420b, guest PC 0x0c0ab142 */
if(!s->budget--) { s->failed_pc=0x0c0ab142u; return 0; }
target=r[2];
r[16]=code_base|0x0c0ab146u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab146u) { target=s->pc; goto dispatch; }
goto P_0c0ab146;
P_0c0ab144: /* original 64e3, guest PC 0x0c0ab144 */
if(!s->budget--) { s->failed_pc=0x0c0ab144u; return 0; }
r[4]=r[14];
goto P_0c0ab146;
P_0c0ab146: /* original 6403, guest PC 0x0c0ab146 */
if(!s->budget--) { s->failed_pc=0x0c0ab146u; return 0; }
r[4]=r[0];
goto P_0c0ab148;
P_0c0ab148: /* original 2448, guest PC 0x0c0ab148 */
if(!s->budget--) { s->failed_pc=0x0c0ab148u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0ab14a;
P_0c0ab14a: /* original 8906, guest PC 0x0c0ab14a */
if(!s->budget--) { s->failed_pc=0x0c0ab14au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab15a; }
goto P_0c0ab14c;
P_0c0ab14c: /* original 62e3, guest PC 0x0c0ab14c */
if(!s->budget--) { s->failed_pc=0x0c0ab14cu; return 0; }
r[2]=r[14];
goto P_0c0ab14e;
P_0c0ab14e: /* original e001, guest PC 0x0c0ab14e */
if(!s->budget--) { s->failed_pc=0x0c0ab14eu; return 0; }
r[0]=0x00000001u;
goto P_0c0ab150;
P_0c0ab150: /* original 7238, guest PC 0x0c0ab150 */
if(!s->budget--) { s->failed_pc=0x0c0ab150u; return 0; }
r[2]+=0x00000038u;
goto P_0c0ab152;
P_0c0ab152: /* original 8022, guest PC 0x0c0ab152 */
if(!s->budget--) { s->failed_pc=0x0c0ab152u; return 0; }
write(ram,r[2]+2,r[0],1);
goto P_0c0ab154;
P_0c0ab154: /* original e062, guest PC 0x0c0ab154 */
if(!s->budget--) { s->failed_pc=0x0c0ab154u; return 0; }
r[0]=0x00000062u;
goto P_0c0ab156;
P_0c0ab156: /* original e303, guest PC 0x0c0ab156 */
if(!s->budget--) { s->failed_pc=0x0c0ab156u; return 0; }
r[3]=0x00000003u;
goto P_0c0ab158;
P_0c0ab158: /* original 0e34, guest PC 0x0c0ab158 */
if(!s->budget--) { s->failed_pc=0x0c0ab158u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ab15a;
P_0c0ab15a: /* original 7f10, guest PC 0x0c0ab15a */
if(!s->budget--) { s->failed_pc=0x0c0ab15au; return 0; }
r[15]+=0x00000010u;
goto P_0c0ab15c;
P_0c0ab15c: /* original 4f26, guest PC 0x0c0ab15c */
if(!s->budget--) { s->failed_pc=0x0c0ab15cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ab15e;
P_0c0ab15e: /* original 6af6, guest PC 0x0c0ab15e */
if(!s->budget--) { s->failed_pc=0x0c0ab15eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0ab160;
P_0c0ab160: /* original 6bf6, guest PC 0x0c0ab160 */
if(!s->budget--) { s->failed_pc=0x0c0ab160u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ab162;
P_0c0ab162: /* original 6cf6, guest PC 0x0c0ab162 */
if(!s->budget--) { s->failed_pc=0x0c0ab162u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ab164;
P_0c0ab164: /* original 6df6, guest PC 0x0c0ab164 */
if(!s->budget--) { s->failed_pc=0x0c0ab164u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ab166;
P_0c0ab166: /* original 000b, guest PC 0x0c0ab166 */
if(!s->budget--) { s->failed_pc=0x0c0ab166u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ab168: /* original 6ef6, guest PC 0x0c0ab168 */
if(!s->budget--) { s->failed_pc=0x0c0ab168u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ab16au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ab16au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
