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
int vf3_away_batch138_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c0ab18cu: goto P_0c0ab18c;
case 0x0c0ab18eu: goto P_0c0ab18e;
case 0x0c0ab190u: goto P_0c0ab190;
case 0x0c0ab192u: goto P_0c0ab192;
case 0x0c0ab194u: goto P_0c0ab194;
case 0x0c0ab196u: goto P_0c0ab196;
case 0x0c0ab198u: goto P_0c0ab198;
case 0x0c0ab19au: goto P_0c0ab19a;
case 0x0c0ab19cu: goto P_0c0ab19c;
case 0x0c0ab19eu: goto P_0c0ab19e;
case 0x0c0ab1a0u: goto P_0c0ab1a0;
case 0x0c0ab1a2u: goto P_0c0ab1a2;
case 0x0c0ab1a4u: goto P_0c0ab1a4;
case 0x0c0ab1a6u: goto P_0c0ab1a6;
case 0x0c0ab1a8u: goto P_0c0ab1a8;
case 0x0c0ab1aau: goto P_0c0ab1aa;
case 0x0c0ab1acu: goto P_0c0ab1ac;
case 0x0c0ab1aeu: goto P_0c0ab1ae;
case 0x0c0ab1b0u: goto P_0c0ab1b0;
case 0x0c0ab1b2u: goto P_0c0ab1b2;
case 0x0c0ab1b4u: goto P_0c0ab1b4;
case 0x0c0ab1b6u: goto P_0c0ab1b6;
case 0x0c0ab1b8u: goto P_0c0ab1b8;
case 0x0c0ab1bau: goto P_0c0ab1ba;
case 0x0c0ab1bcu: goto P_0c0ab1bc;
case 0x0c0ab1beu: goto P_0c0ab1be;
case 0x0c0ab1c0u: goto P_0c0ab1c0;
case 0x0c0ab1c2u: goto P_0c0ab1c2;
case 0x0c0ab1c4u: goto P_0c0ab1c4;
case 0x0c0ab1c6u: goto P_0c0ab1c6;
case 0x0c0ab1c8u: goto P_0c0ab1c8;
case 0x0c0ab1cau: goto P_0c0ab1ca;
case 0x0c0ab1ccu: goto P_0c0ab1cc;
case 0x0c0ab1ceu: goto P_0c0ab1ce;
case 0x0c0ab1d0u: goto P_0c0ab1d0;
case 0x0c0ab1d2u: goto P_0c0ab1d2;
case 0x0c0ab1d4u: goto P_0c0ab1d4;
case 0x0c0ab1d6u: goto P_0c0ab1d6;
case 0x0c0ab1d8u: goto P_0c0ab1d8;
case 0x0c0ab1dau: goto P_0c0ab1da;
case 0x0c0ab1dcu: goto P_0c0ab1dc;
case 0x0c0ab1deu: goto P_0c0ab1de;
case 0x0c0ab1e0u: goto P_0c0ab1e0;
case 0x0c0ab1e2u: goto P_0c0ab1e2;
case 0x0c0ab1e4u: goto P_0c0ab1e4;
case 0x0c0ab1e6u: goto P_0c0ab1e6;
case 0x0c0ab1e8u: goto P_0c0ab1e8;
case 0x0c0ab1eau: goto P_0c0ab1ea;
case 0x0c0ab1ecu: goto P_0c0ab1ec;
case 0x0c0ab1eeu: goto P_0c0ab1ee;
case 0x0c0ab1f0u: goto P_0c0ab1f0;
case 0x0c0ab1f2u: goto P_0c0ab1f2;
case 0x0c0ab1f4u: goto P_0c0ab1f4;
case 0x0c0ab1f6u: goto P_0c0ab1f6;
case 0x0c0ab1f8u: goto P_0c0ab1f8;
case 0x0c0ab1fau: goto P_0c0ab1fa;
case 0x0c0ab1fcu: goto P_0c0ab1fc;
case 0x0c0ab1feu: goto P_0c0ab1fe;
case 0x0c0ab200u: goto P_0c0ab200;
case 0x0c0ab202u: goto P_0c0ab202;
case 0x0c0ab204u: goto P_0c0ab204;
case 0x0c0ab206u: goto P_0c0ab206;
case 0x0c0ab208u: goto P_0c0ab208;
case 0x0c0ab20au: goto P_0c0ab20a;
case 0x0c0ab20cu: goto P_0c0ab20c;
case 0x0c0ab20eu: goto P_0c0ab20e;
case 0x0c0ab210u: goto P_0c0ab210;
case 0x0c0ab212u: goto P_0c0ab212;
case 0x0c0ab214u: goto P_0c0ab214;
case 0x0c0ab216u: goto P_0c0ab216;
case 0x0c0ab218u: goto P_0c0ab218;
case 0x0c0ab21au: goto P_0c0ab21a;
case 0x0c0ab21cu: goto P_0c0ab21c;
case 0x0c0ab21eu: goto P_0c0ab21e;
case 0x0c0ab220u: goto P_0c0ab220;
case 0x0c0ab222u: goto P_0c0ab222;
case 0x0c0ab224u: goto P_0c0ab224;
case 0x0c0ab226u: goto P_0c0ab226;
case 0x0c0ab228u: goto P_0c0ab228;
case 0x0c0ab22au: goto P_0c0ab22a;
case 0x0c0ab22cu: goto P_0c0ab22c;
case 0x0c0ab22eu: goto P_0c0ab22e;
case 0x0c0ab230u: goto P_0c0ab230;
case 0x0c0ab232u: goto P_0c0ab232;
case 0x0c0ab234u: goto P_0c0ab234;
case 0x0c0ab236u: goto P_0c0ab236;
case 0x0c0ab238u: goto P_0c0ab238;
case 0x0c0ab23au: goto P_0c0ab23a;
case 0x0c0ab23cu: goto P_0c0ab23c;
case 0x0c0ab23eu: goto P_0c0ab23e;
case 0x0c0ab240u: goto P_0c0ab240;
case 0x0c0ab242u: goto P_0c0ab242;
case 0x0c0ab244u: goto P_0c0ab244;
case 0x0c0ab246u: goto P_0c0ab246;
case 0x0c0ab248u: goto P_0c0ab248;
case 0x0c0ab24au: goto P_0c0ab24a;
case 0x0c0ab24cu: goto P_0c0ab24c;
case 0x0c0ab24eu: goto P_0c0ab24e;
case 0x0c0ab250u: goto P_0c0ab250;
case 0x0c0ab252u: goto P_0c0ab252;
case 0x0c0ab254u: goto P_0c0ab254;
case 0x0c0ab256u: goto P_0c0ab256;
case 0x0c0ab258u: goto P_0c0ab258;
case 0x0c0ab25au: goto P_0c0ab25a;
case 0x0c0ab25cu: goto P_0c0ab25c;
case 0x0c0ab25eu: goto P_0c0ab25e;
case 0x0c0ab260u: goto P_0c0ab260;
case 0x0c0ab262u: goto P_0c0ab262;
case 0x0c0ab264u: goto P_0c0ab264;
case 0x0c0ab266u: goto P_0c0ab266;
case 0x0c0ab268u: goto P_0c0ab268;
case 0x0c0ab26au: goto P_0c0ab26a;
case 0x0c0ab26cu: goto P_0c0ab26c;
case 0x0c0ab26eu: goto P_0c0ab26e;
case 0x0c0ab270u: goto P_0c0ab270;
case 0x0c0ab272u: goto P_0c0ab272;
case 0x0c0ab274u: goto P_0c0ab274;
case 0x0c0ab276u: goto P_0c0ab276;
case 0x0c0ab278u: goto P_0c0ab278;
case 0x0c0ab27au: goto P_0c0ab27a;
case 0x0c0ab27cu: goto P_0c0ab27c;
case 0x0c0ab27eu: goto P_0c0ab27e;
case 0x0c0ab280u: goto P_0c0ab280;
case 0x0c0ab282u: goto P_0c0ab282;
case 0x0c0ab284u: goto P_0c0ab284;
case 0x0c0ab286u: goto P_0c0ab286;
case 0x0c0ab288u: goto P_0c0ab288;
case 0x0c0ab2a8u: goto P_0c0ab2a8;
case 0x0c0ab2aau: goto P_0c0ab2aa;
case 0x0c0ab2acu: goto P_0c0ab2ac;
case 0x0c0ab2aeu: goto P_0c0ab2ae;
case 0x0c0ab2b0u: goto P_0c0ab2b0;
case 0x0c0ab2b2u: goto P_0c0ab2b2;
case 0x0c0ab2b4u: goto P_0c0ab2b4;
case 0x0c0ab2b6u: goto P_0c0ab2b6;
case 0x0c0ab2b8u: goto P_0c0ab2b8;
case 0x0c0ab2bau: goto P_0c0ab2ba;
case 0x0c0ab2bcu: goto P_0c0ab2bc;
case 0x0c0ab2beu: goto P_0c0ab2be;
case 0x0c0ab2c0u: goto P_0c0ab2c0;
case 0x0c0ab2c2u: goto P_0c0ab2c2;
case 0x0c0ab2c4u: goto P_0c0ab2c4;
case 0x0c0ab2c6u: goto P_0c0ab2c6;
case 0x0c0ab2c8u: goto P_0c0ab2c8;
case 0x0c0ab2cau: goto P_0c0ab2ca;
case 0x0c0ab2ccu: goto P_0c0ab2cc;
case 0x0c0ab2ceu: goto P_0c0ab2ce;
case 0x0c0ab2d0u: goto P_0c0ab2d0;
case 0x0c0ab2d2u: goto P_0c0ab2d2;
case 0x0c0ab2d4u: goto P_0c0ab2d4;
case 0x0c0ab2d6u: goto P_0c0ab2d6;
case 0x0c0ab2d8u: goto P_0c0ab2d8;
case 0x0c0ab2dau: goto P_0c0ab2da;
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
P_0c0ab18c: /* original 2fe6, guest PC 0x0c0ab18c */
if(!s->budget--) { s->failed_pc=0x0c0ab18cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ab18e;
P_0c0ab18e: /* original 6e43, guest PC 0x0c0ab18e */
if(!s->budget--) { s->failed_pc=0x0c0ab18eu; return 0; }
r[14]=r[4];
goto P_0c0ab190;
P_0c0ab190: /* original 2fd6, guest PC 0x0c0ab190 */
if(!s->budget--) { s->failed_pc=0x0c0ab190u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ab192;
P_0c0ab192: /* original 6d63, guest PC 0x0c0ab192 */
if(!s->budget--) { s->failed_pc=0x0c0ab192u; return 0; }
r[13]=r[6];
goto P_0c0ab194;
P_0c0ab194: /* original d140, guest PC 0x0c0ab194 */
if(!s->budget--) { s->failed_pc=0x0c0ab194u; return 0; }
r[1]=read(ram,0x0c0ab298u,4);
goto P_0c0ab196;
P_0c0ab196: /* original 9078, guest PC 0x0c0ab196 */
if(!s->budget--) { s->failed_pc=0x0c0ab196u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab28au,2);
goto P_0c0ab198;
P_0c0ab198: /* original 415a, guest PC 0x0c0ab198 */
if(!s->budget--) { s->failed_pc=0x0c0ab198u; return 0; }
r[53]=r[1];
goto P_0c0ab19a;
P_0c0ab19a: /* original f2e6, guest PC 0x0c0ab19a */
if(!s->budget--) { s->failed_pc=0x0c0ab19au; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0ab19c;
P_0c0ab19c: /* original 4f22, guest PC 0x0c0ab19c */
if(!s->budget--) { s->failed_pc=0x0c0ab19cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ab19e;
P_0c0ab19e: /* original f30d, guest PC 0x0c0ab19e */
if(!s->budget--) { s->failed_pc=0x0c0ab19eu; return 0; }
fr[3]=r[53];
goto P_0c0ab1a0;
P_0c0ab1a0: /* original f230, guest PC 0x0c0ab1a0 */
if(!s->budget--) { s->failed_pc=0x0c0ab1a0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0ab1a2;
P_0c0ab1a2: /* original 7fec, guest PC 0x0c0ab1a2 */
if(!s->budget--) { s->failed_pc=0x0c0ab1a2u; return 0; }
r[15]+=0xffffffecu;
goto P_0c0ab1a4;
P_0c0ab1a4: /* original fe27, guest PC 0x0c0ab1a4 */
if(!s->budget--) { s->failed_pc=0x0c0ab1a4u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0ab1a6;
P_0c0ab1a6: /* original e066, guest PC 0x0c0ab1a6 */
if(!s->budget--) { s->failed_pc=0x0c0ab1a6u; return 0; }
r[0]=0x00000066u;
goto P_0c0ab1a8;
P_0c0ab1a8: /* original 04ed, guest PC 0x0c0ab1a8 */
if(!s->budget--) { s->failed_pc=0x0c0ab1a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab1aa;
P_0c0ab1aa: /* original 74ff, guest PC 0x0c0ab1aa */
if(!s->budget--) { s->failed_pc=0x0c0ab1aau; return 0; }
r[4]+=0xffffffffu;
goto P_0c0ab1ac;
P_0c0ab1ac: /* original 4411, guest PC 0x0c0ab1ac */
if(!s->budget--) { s->failed_pc=0x0c0ab1acu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0ab1ae;
P_0c0ab1ae: /* original 8d01, guest PC 0x0c0ab1ae */
if(!s->budget--) { s->failed_pc=0x0c0ab1aeu; return 0; }
cond=r[17]&1u;
r[6]=0x00000000u;
if(cond) { goto P_0c0ab1b4; }
goto P_0c0ab1b2;
P_0c0ab1b0: /* original e600, guest PC 0x0c0ab1b0 */
if(!s->budget--) { s->failed_pc=0x0c0ab1b0u; return 0; }
r[6]=0x00000000u;
goto P_0c0ab1b2;
P_0c0ab1b2: /* original 6463, guest PC 0x0c0ab1b2 */
if(!s->budget--) { s->failed_pc=0x0c0ab1b2u; return 0; }
r[4]=r[6];
goto P_0c0ab1b4;
P_0c0ab1b4: /* original 0e45, guest PC 0x0c0ab1b4 */
if(!s->budget--) { s->failed_pc=0x0c0ab1b4u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0ab1b6;
P_0c0ab1b6: /* original 50d1, guest PC 0x0c0ab1b6 */
if(!s->budget--) { s->failed_pc=0x0c0ab1b6u; return 0; }
r[0]=read(ram,r[13]+4,4);
goto P_0c0ab1b8;
P_0c0ab1b8: /* original 8800, guest PC 0x0c0ab1b8 */
if(!s->budget--) { s->failed_pc=0x0c0ab1b8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0ab1ba;
P_0c0ab1ba: /* original 8905, guest PC 0x0c0ab1ba */
if(!s->budget--) { s->failed_pc=0x0c0ab1bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab1c8; }
goto P_0c0ab1bc;
P_0c0ab1bc: /* original 8801, guest PC 0x0c0ab1bc */
if(!s->budget--) { s->failed_pc=0x0c0ab1bcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0ab1be;
P_0c0ab1be: /* original 8948, guest PC 0x0c0ab1be */
if(!s->budget--) { s->failed_pc=0x0c0ab1beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab252; }
goto P_0c0ab1c0;
P_0c0ab1c0: /* original 8802, guest PC 0x0c0ab1c0 */
if(!s->budget--) { s->failed_pc=0x0c0ab1c0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0ab1c2;
P_0c0ab1c2: /* original 8955, guest PC 0x0c0ab1c2 */
if(!s->budget--) { s->failed_pc=0x0c0ab1c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab270; }
goto P_0c0ab1c4;
P_0c0ab1c4: /* original 8803, guest PC 0x0c0ab1c4 */
if(!s->budget--) { s->failed_pc=0x0c0ab1c4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0ab1c6;
P_0c0ab1c6: /* original 8979, guest PC 0x0c0ab1c6 */
if(!s->budget--) { s->failed_pc=0x0c0ab1c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab2bc; }
goto P_0c0ab1c8;
P_0c0ab1c8: /* original 9060, guest PC 0x0c0ab1c8 */
if(!s->budget--) { s->failed_pc=0x0c0ab1c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab28cu,2);
goto P_0c0ab1ca;
P_0c0ab1ca: /* original e201, guest PC 0x0c0ab1ca */
if(!s->budget--) { s->failed_pc=0x0c0ab1cau; return 0; }
r[2]=0x00000001u;
goto P_0c0ab1cc;
P_0c0ab1cc: /* original 0e24, guest PC 0x0c0ab1cc */
if(!s->budget--) { s->failed_pc=0x0c0ab1ccu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0ab1ce;
P_0c0ab1ce: /* original 61e2, guest PC 0x0c0ab1ce */
if(!s->budget--) { s->failed_pc=0x0c0ab1ceu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0ab1d0;
P_0c0ab1d0: /* original d332, guest PC 0x0c0ab1d0 */
if(!s->budget--) { s->failed_pc=0x0c0ab1d0u; return 0; }
r[3]=read(ram,0x0c0ab29cu,4);
goto P_0c0ab1d2;
P_0c0ab1d2: /* original 213b, guest PC 0x0c0ab1d2 */
if(!s->budget--) { s->failed_pc=0x0c0ab1d2u; return 0; }
r[1]|=r[3];
goto P_0c0ab1d4;
P_0c0ab1d4: /* original 2e12, guest PC 0x0c0ab1d4 */
if(!s->budget--) { s->failed_pc=0x0c0ab1d4u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0ab1d6;
P_0c0ab1d6: /* original 64d2, guest PC 0x0c0ab1d6 */
if(!s->budget--) { s->failed_pc=0x0c0ab1d6u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0ab1d8;
P_0c0ab1d8: /* original 4429, guest PC 0x0c0ab1d8 */
if(!s->budget--) { s->failed_pc=0x0c0ab1d8u; return 0; }
r[4]>>=16;
goto P_0c0ab1da;
P_0c0ab1da: /* original 644c, guest PC 0x0c0ab1da */
if(!s->budget--) { s->failed_pc=0x0c0ab1dau; return 0; }
r[4]=r[4]&255u;
goto P_0c0ab1dc;
P_0c0ab1dc: /* original 6043, guest PC 0x0c0ab1dc */
if(!s->budget--) { s->failed_pc=0x0c0ab1dcu; return 0; }
r[0]=r[4];
goto P_0c0ab1de;
P_0c0ab1de: /* original 8801, guest PC 0x0c0ab1de */
if(!s->budget--) { s->failed_pc=0x0c0ab1deu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0ab1e0;
P_0c0ab1e0: /* original 8926, guest PC 0x0c0ab1e0 */
if(!s->budget--) { s->failed_pc=0x0c0ab1e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab230; }
goto P_0c0ab1e2;
P_0c0ab1e2: /* original c72f, guest PC 0x0c0ab1e2 */
if(!s->budget--) { s->failed_pc=0x0c0ab1e2u; return 0; }
r[0]=code_base|0x000ab2a0u;
goto P_0c0ab1e4;
P_0c0ab1e4: /* original f79d, guest PC 0x0c0ab1e4 */
if(!s->budget--) { s->failed_pc=0x0c0ab1e4u; return 0; }
fr[7]=0x3f800000u;
goto P_0c0ab1e6;
P_0c0ab1e6: /* original f408, guest PC 0x0c0ab1e6 */
if(!s->budget--) { s->failed_pc=0x0c0ab1e6u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0ab1e8;
P_0c0ab1e8: /* original 65f3, guest PC 0x0c0ab1e8 */
if(!s->budget--) { s->failed_pc=0x0c0ab1e8u; return 0; }
r[5]=r[15];
goto P_0c0ab1ea;
P_0c0ab1ea: /* original 9050, guest PC 0x0c0ab1ea */
if(!s->budget--) { s->failed_pc=0x0c0ab1eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab28eu,2);
goto P_0c0ab1ec;
P_0c0ab1ec: /* original 64f3, guest PC 0x0c0ab1ec */
if(!s->budget--) { s->failed_pc=0x0c0ab1ecu; return 0; }
r[4]=r[15];
goto P_0c0ab1ee;
P_0c0ab1ee: /* original f37c, guest PC 0x0c0ab1ee */
if(!s->budget--) { s->failed_pc=0x0c0ab1eeu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c0ab1f0;
P_0c0ab1f0: /* original f5e6, guest PC 0x0c0ab1f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab1f0u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0ab1f2;
P_0c0ab1f2: /* original 7008, guest PC 0x0c0ab1f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab1f2u; return 0; }
r[0]+=0x00000008u;
goto P_0c0ab1f4;
P_0c0ab1f4: /* original f6e6, guest PC 0x0c0ab1f4 */
if(!s->budget--) { s->failed_pc=0x0c0ab1f4u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0ab1f6;
P_0c0ab1f6: /* original e010, guest PC 0x0c0ab1f6 */
if(!s->budget--) { s->failed_pc=0x0c0ab1f6u; return 0; }
r[0]=0x00000010u;
goto P_0c0ab1f8;
P_0c0ab1f8: /* original f352, guest PC 0x0c0ab1f8 */
if(!s->budget--) { s->failed_pc=0x0c0ab1f8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c0ab1fa;
P_0c0ab1fa: /* original f762, guest PC 0x0c0ab1fa */
if(!s->budget--) { s->failed_pc=0x0c0ab1fau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'*');
goto P_0c0ab1fc;
P_0c0ab1fc: /* original ff37, guest PC 0x0c0ab1fc */
if(!s->budget--) { s->failed_pc=0x0c0ab1fcu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab1fe;
P_0c0ab1fe: /* original e00c, guest PC 0x0c0ab1fe */
if(!s->budget--) { s->failed_pc=0x0c0ab1feu; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab200;
P_0c0ab200: /* original ff77, guest PC 0x0c0ab200 */
if(!s->budget--) { s->failed_pc=0x0c0ab200u; return 0; }
vf3_matrix_store(s,ram,7,r[15]+r[0]);
goto P_0c0ab202;
P_0c0ab202: /* original e004, guest PC 0x0c0ab202 */
if(!s->budget--) { s->failed_pc=0x0c0ab202u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab204;
P_0c0ab204: /* original f24c, guest PC 0x0c0ab204 */
if(!s->budget--) { s->failed_pc=0x0c0ab204u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0ab206;
P_0c0ab206: /* original f252, guest PC 0x0c0ab206 */
if(!s->budget--) { s->failed_pc=0x0c0ab206u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'*');
goto P_0c0ab208;
P_0c0ab208: /* original f462, guest PC 0x0c0ab208 */
if(!s->budget--) { s->failed_pc=0x0c0ab208u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0ab20a;
P_0c0ab20a: /* original ff27, guest PC 0x0c0ab20a */
if(!s->budget--) { s->failed_pc=0x0c0ab20au; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0ab20c;
P_0c0ab20c: /* original ff4a, guest PC 0x0c0ab20c */
if(!s->budget--) { s->failed_pc=0x0c0ab20cu; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c0ab20e;
P_0c0ab20e: /* original ba8e, guest PC 0x0c0ab20e */
if(!s->budget--) { s->failed_pc=0x0c0ab20eu; return 0; }
target=code_base|0x0c0aa72eu; r[16]=code_base|0x0c0ab212u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab212u) { target=s->pc; goto dispatch; }
goto P_0c0ab212;
P_0c0ab210: /* original 7404, guest PC 0x0c0ab210 */
if(!s->budget--) { s->failed_pc=0x0c0ab210u; return 0; }
r[4]+=0x00000004u;
goto P_0c0ab212;
P_0c0ab212: /* original e010, guest PC 0x0c0ab212 */
if(!s->budget--) { s->failed_pc=0x0c0ab212u; return 0; }
r[0]=0x00000010u;
goto P_0c0ab214;
P_0c0ab214: /* original f3f6, guest PC 0x0c0ab214 */
if(!s->budget--) { s->failed_pc=0x0c0ab214u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab216;
P_0c0ab216: /* original e024, guest PC 0x0c0ab216 */
if(!s->budget--) { s->failed_pc=0x0c0ab216u; return 0; }
r[0]=0x00000024u;
goto P_0c0ab218;
P_0c0ab218: /* original fe37, guest PC 0x0c0ab218 */
if(!s->budget--) { s->failed_pc=0x0c0ab218u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab21a;
P_0c0ab21a: /* original e00c, guest PC 0x0c0ab21a */
if(!s->budget--) { s->failed_pc=0x0c0ab21au; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab21c;
P_0c0ab21c: /* original f3f6, guest PC 0x0c0ab21c */
if(!s->budget--) { s->failed_pc=0x0c0ab21cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab21e;
P_0c0ab21e: /* original e02c, guest PC 0x0c0ab21e */
if(!s->budget--) { s->failed_pc=0x0c0ab21eu; return 0; }
r[0]=0x0000002cu;
goto P_0c0ab220;
P_0c0ab220: /* original fe37, guest PC 0x0c0ab220 */
if(!s->budget--) { s->failed_pc=0x0c0ab220u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab222;
P_0c0ab222: /* original e004, guest PC 0x0c0ab222 */
if(!s->budget--) { s->failed_pc=0x0c0ab222u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab224;
P_0c0ab224: /* original f3f6, guest PC 0x0c0ab224 */
if(!s->budget--) { s->failed_pc=0x0c0ab224u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab226;
P_0c0ab226: /* original 9033, guest PC 0x0c0ab226 */
if(!s->budget--) { s->failed_pc=0x0c0ab226u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab290u,2);
goto P_0c0ab228;
P_0c0ab228: /* original fe37, guest PC 0x0c0ab228 */
if(!s->budget--) { s->failed_pc=0x0c0ab228u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab22a;
P_0c0ab22a: /* original 9032, guest PC 0x0c0ab22a */
if(!s->budget--) { s->failed_pc=0x0c0ab22au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab292u,2);
goto P_0c0ab22c;
P_0c0ab22c: /* original f3f8, guest PC 0x0c0ab22c */
if(!s->budget--) { s->failed_pc=0x0c0ab22cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0ab22e;
P_0c0ab22e: /* original fe37, guest PC 0x0c0ab22e */
if(!s->budget--) { s->failed_pc=0x0c0ab22eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab230;
P_0c0ab230: /* original 63d2, guest PC 0x0c0ab230 */
if(!s->budget--) { s->failed_pc=0x0c0ab230u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ab232;
P_0c0ab232: /* original 633d, guest PC 0x0c0ab232 */
if(!s->budget--) { s->failed_pc=0x0c0ab232u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0ab234;
P_0c0ab234: /* original 6233, guest PC 0x0c0ab234 */
if(!s->budget--) { s->failed_pc=0x0c0ab234u; return 0; }
r[2]=r[3];
goto P_0c0ab236;
P_0c0ab236: /* original 2228, guest PC 0x0c0ab236 */
if(!s->budget--) { s->failed_pc=0x0c0ab236u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0ab238;
P_0c0ab238: /* original 8d04, guest PC 0x0c0ab238 */
if(!s->budget--) { s->failed_pc=0x0c0ab238u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[3],4);
if(cond) { goto P_0c0ab244; }
goto P_0c0ab23c;
P_0c0ab23a: /* original 1f32, guest PC 0x0c0ab23a */
if(!s->budget--) { s->failed_pc=0x0c0ab23au; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0ab23c;
P_0c0ab23c: /* original d219, guest PC 0x0c0ab23c */
if(!s->budget--) { s->failed_pc=0x0c0ab23cu; return 0; }
r[2]=read(ram,0x0c0ab2a4u,4);
goto P_0c0ab23e;
P_0c0ab23e: /* original 6533, guest PC 0x0c0ab23e */
if(!s->budget--) { s->failed_pc=0x0c0ab23eu; return 0; }
r[5]=r[3];
goto P_0c0ab240;
P_0c0ab240: /* original 420b, guest PC 0x0c0ab240 */
if(!s->budget--) { s->failed_pc=0x0c0ab240u; return 0; }
target=r[2];
r[16]=code_base|0x0c0ab244u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab244u) { target=s->pc; goto dispatch; }
goto P_0c0ab244;
P_0c0ab242: /* original 64e3, guest PC 0x0c0ab242 */
if(!s->budget--) { s->failed_pc=0x0c0ab242u; return 0; }
r[4]=r[14];
goto P_0c0ab244;
P_0c0ab244: /* original 53d1, guest PC 0x0c0ab244 */
if(!s->budget--) { s->failed_pc=0x0c0ab244u; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0ab246;
P_0c0ab246: /* original e062, guest PC 0x0c0ab246 */
if(!s->budget--) { s->failed_pc=0x0c0ab246u; return 0; }
r[0]=0x00000062u;
goto P_0c0ab248;
P_0c0ab248: /* original 7301, guest PC 0x0c0ab248 */
if(!s->budget--) { s->failed_pc=0x0c0ab248u; return 0; }
r[3]+=0x00000001u;
goto P_0c0ab24a;
P_0c0ab24a: /* original 6233, guest PC 0x0c0ab24a */
if(!s->budget--) { s->failed_pc=0x0c0ab24au; return 0; }
r[2]=r[3];
goto P_0c0ab24c;
P_0c0ab24c: /* original 1d31, guest PC 0x0c0ab24c */
if(!s->budget--) { s->failed_pc=0x0c0ab24cu; return 0; }
write(ram,r[13]+4,r[3],4);
goto P_0c0ab24e;
P_0c0ab24e: /* original a040, guest PC 0x0c0ab24e */
if(!s->budget--) { s->failed_pc=0x0c0ab24eu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0ab2d2;
P_0c0ab250: /* original 0e24, guest PC 0x0c0ab250 */
if(!s->budget--) { s->failed_pc=0x0c0ab250u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0ab252;
P_0c0ab252: /* original 901f, guest PC 0x0c0ab252 */
if(!s->budget--) { s->failed_pc=0x0c0ab252u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab294u,2);
goto P_0c0ab254;
P_0c0ab254: /* original 05ed, guest PC 0x0c0ab254 */
if(!s->budget--) { s->failed_pc=0x0c0ab254u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab256;
P_0c0ab256: /* original e03e, guest PC 0x0c0ab256 */
if(!s->budget--) { s->failed_pc=0x0c0ab256u; return 0; }
r[0]=0x0000003eu;
goto P_0c0ab258;
P_0c0ab258: /* original 07ed, guest PC 0x0c0ab258 */
if(!s->budget--) { s->failed_pc=0x0c0ab258u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab25a;
P_0c0ab25a: /* original 655d, guest PC 0x0c0ab25a */
if(!s->budget--) { s->failed_pc=0x0c0ab25au; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ab25c;
P_0c0ab25c: /* original 75ff, guest PC 0x0c0ab25c */
if(!s->budget--) { s->failed_pc=0x0c0ab25cu; return 0; }
r[5]+=0xffffffffu;
goto P_0c0ab25e;
P_0c0ab25e: /* original 677d, guest PC 0x0c0ab25e */
if(!s->budget--) { s->failed_pc=0x0c0ab25eu; return 0; }
r[7]=r[7]&65535u;
goto P_0c0ab260;
P_0c0ab260: /* original 3752, guest PC 0x0c0ab260 */
if(!s->budget--) { s->failed_pc=0x0c0ab260u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[5])!=0);
goto P_0c0ab262;
P_0c0ab262: /* original 8b36, guest PC 0x0c0ab262 */
if(!s->budget--) { s->failed_pc=0x0c0ab262u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab2d2; }
goto P_0c0ab264;
P_0c0ab264: /* original 52d1, guest PC 0x0c0ab264 */
if(!s->budget--) { s->failed_pc=0x0c0ab264u; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0ab266;
P_0c0ab266: /* original e062, guest PC 0x0c0ab266 */
if(!s->budget--) { s->failed_pc=0x0c0ab266u; return 0; }
r[0]=0x00000062u;
goto P_0c0ab268;
P_0c0ab268: /* original 7201, guest PC 0x0c0ab268 */
if(!s->budget--) { s->failed_pc=0x0c0ab268u; return 0; }
r[2]+=0x00000001u;
goto P_0c0ab26a;
P_0c0ab26a: /* original 6323, guest PC 0x0c0ab26a */
if(!s->budget--) { s->failed_pc=0x0c0ab26au; return 0; }
r[3]=r[2];
goto P_0c0ab26c;
P_0c0ab26c: /* original 1d21, guest PC 0x0c0ab26c */
if(!s->budget--) { s->failed_pc=0x0c0ab26cu; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0ab26e;
P_0c0ab26e: /* original 0e34, guest PC 0x0c0ab26e */
if(!s->budget--) { s->failed_pc=0x0c0ab26eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ab270;
P_0c0ab270: /* original 9010, guest PC 0x0c0ab270 */
if(!s->budget--) { s->failed_pc=0x0c0ab270u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab294u,2);
goto P_0c0ab272;
P_0c0ab272: /* original 07ed, guest PC 0x0c0ab272 */
if(!s->budget--) { s->failed_pc=0x0c0ab272u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab274;
P_0c0ab274: /* original 7002, guest PC 0x0c0ab274 */
if(!s->budget--) { s->failed_pc=0x0c0ab274u; return 0; }
r[0]+=0x00000002u;
goto P_0c0ab276;
P_0c0ab276: /* original 05ed, guest PC 0x0c0ab276 */
if(!s->budget--) { s->failed_pc=0x0c0ab276u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab278;
P_0c0ab278: /* original 677d, guest PC 0x0c0ab278 */
if(!s->budget--) { s->failed_pc=0x0c0ab278u; return 0; }
r[7]=r[7]&65535u;
goto P_0c0ab27a;
P_0c0ab27a: /* original 655d, guest PC 0x0c0ab27a */
if(!s->budget--) { s->failed_pc=0x0c0ab27au; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ab27c;
P_0c0ab27c: /* original 3548, guest PC 0x0c0ab27c */
if(!s->budget--) { s->failed_pc=0x0c0ab27cu; return 0; }
r[5]-=r[4];
goto P_0c0ab27e;
P_0c0ab27e: /* original 77ff, guest PC 0x0c0ab27e */
if(!s->budget--) { s->failed_pc=0x0c0ab27eu; return 0; }
r[7]+=0xffffffffu;
goto P_0c0ab280;
P_0c0ab280: /* original 3753, guest PC 0x0c0ab280 */
if(!s->budget--) { s->failed_pc=0x0c0ab280u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[5])!=0);
goto P_0c0ab282;
P_0c0ab282: /* original 8b11, guest PC 0x0c0ab282 */
if(!s->budget--) { s->failed_pc=0x0c0ab282u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab2a8; }
goto P_0c0ab284;
P_0c0ab284: /* original e03e, guest PC 0x0c0ab284 */
if(!s->budget--) { s->failed_pc=0x0c0ab284u; return 0; }
r[0]=0x0000003eu;
goto P_0c0ab286;
P_0c0ab286: /* original a024, guest PC 0x0c0ab286 */
if(!s->budget--) { s->failed_pc=0x0c0ab286u; return 0; }
write(ram,r[14]+r[0],r[7],2);
goto P_0c0ab2d2;
P_0c0ab288: /* original 0e75, guest PC 0x0c0ab288 */
if(!s->budget--) { s->failed_pc=0x0c0ab288u; return 0; }
write(ram,r[14]+r[0],r[7],2);
if(!vf3_matrix_family(0x0c0ab28au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ab28au; return 0; } return 1;
P_0c0ab2a8: /* original 62e2, guest PC 0x0c0ab2a8 */
if(!s->budget--) { s->failed_pc=0x0c0ab2a8u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0ab2aa;
P_0c0ab2aa: /* original e062, guest PC 0x0c0ab2aa */
if(!s->budget--) { s->failed_pc=0x0c0ab2aau; return 0; }
r[0]=0x00000062u;
goto P_0c0ab2ac;
P_0c0ab2ac: /* original d320, guest PC 0x0c0ab2ac */
if(!s->budget--) { s->failed_pc=0x0c0ab2acu; return 0; }
r[3]=read(ram,0x0c0ab330u,4);
goto P_0c0ab2ae;
P_0c0ab2ae: /* original 2239, guest PC 0x0c0ab2ae */
if(!s->budget--) { s->failed_pc=0x0c0ab2aeu; return 0; }
r[2]&=r[3];
goto P_0c0ab2b0;
P_0c0ab2b0: /* original 2e22, guest PC 0x0c0ab2b0 */
if(!s->budget--) { s->failed_pc=0x0c0ab2b0u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0ab2b2;
P_0c0ab2b2: /* original 51d1, guest PC 0x0c0ab2b2 */
if(!s->budget--) { s->failed_pc=0x0c0ab2b2u; return 0; }
r[1]=read(ram,r[13]+4,4);
goto P_0c0ab2b4;
P_0c0ab2b4: /* original 7101, guest PC 0x0c0ab2b4 */
if(!s->budget--) { s->failed_pc=0x0c0ab2b4u; return 0; }
r[1]+=0x00000001u;
goto P_0c0ab2b6;
P_0c0ab2b6: /* original 6213, guest PC 0x0c0ab2b6 */
if(!s->budget--) { s->failed_pc=0x0c0ab2b6u; return 0; }
r[2]=r[1];
goto P_0c0ab2b8;
P_0c0ab2b8: /* original 1d11, guest PC 0x0c0ab2b8 */
if(!s->budget--) { s->failed_pc=0x0c0ab2b8u; return 0; }
write(ram,r[13]+4,r[1],4);
goto P_0c0ab2ba;
P_0c0ab2ba: /* original 0e24, guest PC 0x0c0ab2ba */
if(!s->budget--) { s->failed_pc=0x0c0ab2bau; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0ab2bc;
P_0c0ab2bc: /* original 4415, guest PC 0x0c0ab2bc */
if(!s->budget--) { s->failed_pc=0x0c0ab2bcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0ab2be;
P_0c0ab2be: /* original 8908, guest PC 0x0c0ab2be */
if(!s->budget--) { s->failed_pc=0x0c0ab2beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab2d2; }
goto P_0c0ab2c0;
P_0c0ab2c0: /* original e048, guest PC 0x0c0ab2c0 */
if(!s->budget--) { s->failed_pc=0x0c0ab2c0u; return 0; }
r[0]=0x00000048u;
goto P_0c0ab2c2;
P_0c0ab2c2: /* original 1e6e, guest PC 0x0c0ab2c2 */
if(!s->budget--) { s->failed_pc=0x0c0ab2c2u; return 0; }
write(ram,r[14]+56,r[6],4);
goto P_0c0ab2c4;
P_0c0ab2c4: /* original 9330, guest PC 0x0c0ab2c4 */
if(!s->budget--) { s->failed_pc=0x0c0ab2c4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab328u,2);
goto P_0c0ab2c6;
P_0c0ab2c6: /* original 04ee, guest PC 0x0c0ab2c6 */
if(!s->budget--) { s->failed_pc=0x0c0ab2c6u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0ab2c8;
P_0c0ab2c8: /* original 2348, guest PC 0x0c0ab2c8 */
if(!s->budget--) { s->failed_pc=0x0c0ab2c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0ab2ca;
P_0c0ab2ca: /* original 8b02, guest PC 0x0c0ab2ca */
if(!s->budget--) { s->failed_pc=0x0c0ab2cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab2d2; }
goto P_0c0ab2cc;
P_0c0ab2cc: /* original d119, guest PC 0x0c0ab2cc */
if(!s->budget--) { s->failed_pc=0x0c0ab2ccu; return 0; }
r[1]=read(ram,0x0c0ab334u,4);
goto P_0c0ab2ce;
P_0c0ab2ce: /* original 2419, guest PC 0x0c0ab2ce */
if(!s->budget--) { s->failed_pc=0x0c0ab2ceu; return 0; }
r[4]&=r[1];
goto P_0c0ab2d0;
P_0c0ab2d0: /* original 0e46, guest PC 0x0c0ab2d0 */
if(!s->budget--) { s->failed_pc=0x0c0ab2d0u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0ab2d2;
P_0c0ab2d2: /* original 7f14, guest PC 0x0c0ab2d2 */
if(!s->budget--) { s->failed_pc=0x0c0ab2d2u; return 0; }
r[15]+=0x00000014u;
goto P_0c0ab2d4;
P_0c0ab2d4: /* original 4f26, guest PC 0x0c0ab2d4 */
if(!s->budget--) { s->failed_pc=0x0c0ab2d4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ab2d6;
P_0c0ab2d6: /* original 6df6, guest PC 0x0c0ab2d6 */
if(!s->budget--) { s->failed_pc=0x0c0ab2d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ab2d8;
P_0c0ab2d8: /* original 000b, guest PC 0x0c0ab2d8 */
if(!s->budget--) { s->failed_pc=0x0c0ab2d8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ab2da: /* original 6ef6, guest PC 0x0c0ab2da */
if(!s->budget--) { s->failed_pc=0x0c0ab2dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ab2dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ab2dcu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
