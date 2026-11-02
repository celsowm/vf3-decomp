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
int vf3_away_batch21_adapter_16(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c0ab340u: goto P_0c0ab340;
case 0x0c0ab342u: goto P_0c0ab342;
case 0x0c0ab344u: goto P_0c0ab344;
case 0x0c0ab346u: goto P_0c0ab346;
case 0x0c0ab348u: goto P_0c0ab348;
case 0x0c0ab34au: goto P_0c0ab34a;
case 0x0c0ab34cu: goto P_0c0ab34c;
case 0x0c0ab34eu: goto P_0c0ab34e;
case 0x0c0ab350u: goto P_0c0ab350;
case 0x0c0ab352u: goto P_0c0ab352;
case 0x0c0ab354u: goto P_0c0ab354;
case 0x0c0ab356u: goto P_0c0ab356;
case 0x0c0ab358u: goto P_0c0ab358;
case 0x0c0ab35au: goto P_0c0ab35a;
case 0x0c0ab35cu: goto P_0c0ab35c;
case 0x0c0ab35eu: goto P_0c0ab35e;
case 0x0c0ab360u: goto P_0c0ab360;
case 0x0c0ab362u: goto P_0c0ab362;
case 0x0c0ab364u: goto P_0c0ab364;
case 0x0c0ab366u: goto P_0c0ab366;
case 0x0c0ab368u: goto P_0c0ab368;
case 0x0c0ab36au: goto P_0c0ab36a;
case 0x0c0ab36cu: goto P_0c0ab36c;
case 0x0c0ab36eu: goto P_0c0ab36e;
case 0x0c0ab370u: goto P_0c0ab370;
case 0x0c0ab372u: goto P_0c0ab372;
case 0x0c0ab374u: goto P_0c0ab374;
case 0x0c0ab376u: goto P_0c0ab376;
case 0x0c0ab378u: goto P_0c0ab378;
case 0x0c0ab37au: goto P_0c0ab37a;
case 0x0c0ab37cu: goto P_0c0ab37c;
case 0x0c0ab37eu: goto P_0c0ab37e;
case 0x0c0ab380u: goto P_0c0ab380;
case 0x0c0ab382u: goto P_0c0ab382;
case 0x0c0ab384u: goto P_0c0ab384;
case 0x0c0ab386u: goto P_0c0ab386;
case 0x0c0ab388u: goto P_0c0ab388;
case 0x0c0ab38au: goto P_0c0ab38a;
case 0x0c0ab38cu: goto P_0c0ab38c;
case 0x0c0ab38eu: goto P_0c0ab38e;
case 0x0c0ab390u: goto P_0c0ab390;
case 0x0c0ab392u: goto P_0c0ab392;
case 0x0c0ab394u: goto P_0c0ab394;
case 0x0c0ab396u: goto P_0c0ab396;
case 0x0c0ab398u: goto P_0c0ab398;
case 0x0c0ab39au: goto P_0c0ab39a;
case 0x0c0ab39cu: goto P_0c0ab39c;
case 0x0c0ab39eu: goto P_0c0ab39e;
case 0x0c0ab3a0u: goto P_0c0ab3a0;
case 0x0c0ab3a2u: goto P_0c0ab3a2;
case 0x0c0ab3a4u: goto P_0c0ab3a4;
case 0x0c0ab3a6u: goto P_0c0ab3a6;
case 0x0c0ab3a8u: goto P_0c0ab3a8;
case 0x0c0ab3aau: goto P_0c0ab3aa;
case 0x0c0ab3acu: goto P_0c0ab3ac;
case 0x0c0ab3aeu: goto P_0c0ab3ae;
case 0x0c0ab3b0u: goto P_0c0ab3b0;
case 0x0c0ab3b2u: goto P_0c0ab3b2;
case 0x0c0ab3b4u: goto P_0c0ab3b4;
case 0x0c0ab3b6u: goto P_0c0ab3b6;
case 0x0c0ab3b8u: goto P_0c0ab3b8;
case 0x0c0ab3bau: goto P_0c0ab3ba;
case 0x0c0ab3bcu: goto P_0c0ab3bc;
case 0x0c0ab3beu: goto P_0c0ab3be;
case 0x0c0ab3c0u: goto P_0c0ab3c0;
case 0x0c0ab3c2u: goto P_0c0ab3c2;
case 0x0c0ab3c4u: goto P_0c0ab3c4;
case 0x0c0ab3c6u: goto P_0c0ab3c6;
case 0x0c0ab3c8u: goto P_0c0ab3c8;
case 0x0c0ab3cau: goto P_0c0ab3ca;
case 0x0c0ab3ccu: goto P_0c0ab3cc;
case 0x0c0ab3ceu: goto P_0c0ab3ce;
case 0x0c0ab3d0u: goto P_0c0ab3d0;
case 0x0c0ab3d2u: goto P_0c0ab3d2;
case 0x0c0ab3d4u: goto P_0c0ab3d4;
case 0x0c0ab3d6u: goto P_0c0ab3d6;
case 0x0c0ab3d8u: goto P_0c0ab3d8;
case 0x0c0ab3dau: goto P_0c0ab3da;
case 0x0c0ab3dcu: goto P_0c0ab3dc;
case 0x0c0ab3deu: goto P_0c0ab3de;
case 0x0c0ab3e0u: goto P_0c0ab3e0;
case 0x0c0ab3e2u: goto P_0c0ab3e2;
case 0x0c0ab3e4u: goto P_0c0ab3e4;
case 0x0c0ab3e6u: goto P_0c0ab3e6;
case 0x0c0ab3e8u: goto P_0c0ab3e8;
case 0x0c0ab3eau: goto P_0c0ab3ea;
case 0x0c0ab3ecu: goto P_0c0ab3ec;
case 0x0c0ab3eeu: goto P_0c0ab3ee;
case 0x0c0ab3f0u: goto P_0c0ab3f0;
case 0x0c0ab3f2u: goto P_0c0ab3f2;
case 0x0c0ab3f4u: goto P_0c0ab3f4;
case 0x0c0ab3f6u: goto P_0c0ab3f6;
case 0x0c0ab3f8u: goto P_0c0ab3f8;
case 0x0c0ab3fau: goto P_0c0ab3fa;
case 0x0c0ab3fcu: goto P_0c0ab3fc;
case 0x0c0ab3feu: goto P_0c0ab3fe;
case 0x0c0ab400u: goto P_0c0ab400;
case 0x0c0ab402u: goto P_0c0ab402;
case 0x0c0ab404u: goto P_0c0ab404;
case 0x0c0ab406u: goto P_0c0ab406;
case 0x0c0ab408u: goto P_0c0ab408;
case 0x0c0ab40au: goto P_0c0ab40a;
case 0x0c0ab40cu: goto P_0c0ab40c;
case 0x0c0ab40eu: goto P_0c0ab40e;
case 0x0c0ab410u: goto P_0c0ab410;
case 0x0c0ab412u: goto P_0c0ab412;
case 0x0c0ab414u: goto P_0c0ab414;
case 0x0c0ab416u: goto P_0c0ab416;
case 0x0c0ab418u: goto P_0c0ab418;
case 0x0c0ab41au: goto P_0c0ab41a;
case 0x0c0ab41cu: goto P_0c0ab41c;
case 0x0c0ab41eu: goto P_0c0ab41e;
case 0x0c0ab420u: goto P_0c0ab420;
case 0x0c0ab422u: goto P_0c0ab422;
case 0x0c0ab424u: goto P_0c0ab424;
case 0x0c0ab426u: goto P_0c0ab426;
case 0x0c0ab428u: goto P_0c0ab428;
case 0x0c0ab42au: goto P_0c0ab42a;
case 0x0c0ab42cu: goto P_0c0ab42c;
case 0x0c0ab42eu: goto P_0c0ab42e;
case 0x0c0ab430u: goto P_0c0ab430;
case 0x0c0ab432u: goto P_0c0ab432;
case 0x0c0ab434u: goto P_0c0ab434;
case 0x0c0ab436u: goto P_0c0ab436;
case 0x0c0ab438u: goto P_0c0ab438;
case 0x0c0ab43au: goto P_0c0ab43a;
case 0x0c0ab43cu: goto P_0c0ab43c;
case 0x0c0ab43eu: goto P_0c0ab43e;
case 0x0c0ab440u: goto P_0c0ab440;
case 0x0c0ab442u: goto P_0c0ab442;
case 0x0c0ab444u: goto P_0c0ab444;
case 0x0c0ab446u: goto P_0c0ab446;
case 0x0c0ab448u: goto P_0c0ab448;
case 0x0c0ab44au: goto P_0c0ab44a;
case 0x0c0ab44cu: goto P_0c0ab44c;
case 0x0c0ab44eu: goto P_0c0ab44e;
case 0x0c0ab450u: goto P_0c0ab450;
case 0x0c0ab452u: goto P_0c0ab452;
case 0x0c0ab454u: goto P_0c0ab454;
case 0x0c0ab456u: goto P_0c0ab456;
case 0x0c0ab458u: goto P_0c0ab458;
case 0x0c0ab45au: goto P_0c0ab45a;
case 0x0c0ab45cu: goto P_0c0ab45c;
case 0x0c0ab45eu: goto P_0c0ab45e;
case 0x0c0ab460u: goto P_0c0ab460;
case 0x0c0ab462u: goto P_0c0ab462;
case 0x0c0ab464u: goto P_0c0ab464;
case 0x0c0ab466u: goto P_0c0ab466;
case 0x0c0ab468u: goto P_0c0ab468;
case 0x0c0ab46au: goto P_0c0ab46a;
case 0x0c0ab46cu: goto P_0c0ab46c;
case 0x0c0ab46eu: goto P_0c0ab46e;
case 0x0c0ab470u: goto P_0c0ab470;
case 0x0c0ab472u: goto P_0c0ab472;
case 0x0c0ab474u: goto P_0c0ab474;
case 0x0c0ab4b4u: goto P_0c0ab4b4;
case 0x0c0ab4b6u: goto P_0c0ab4b6;
case 0x0c0ab4b8u: goto P_0c0ab4b8;
case 0x0c0ab4bau: goto P_0c0ab4ba;
case 0x0c0ab4bcu: goto P_0c0ab4bc;
case 0x0c0ab4beu: goto P_0c0ab4be;
case 0x0c0ab4c0u: goto P_0c0ab4c0;
case 0x0c0ab4c2u: goto P_0c0ab4c2;
case 0x0c0ab4c4u: goto P_0c0ab4c4;
case 0x0c0ab4c6u: goto P_0c0ab4c6;
case 0x0c0ab4c8u: goto P_0c0ab4c8;
case 0x0c0ab4cau: goto P_0c0ab4ca;
case 0x0c0ab4ccu: goto P_0c0ab4cc;
case 0x0c0ab4ceu: goto P_0c0ab4ce;
case 0x0c0ab4d0u: goto P_0c0ab4d0;
case 0x0c0ab4d2u: goto P_0c0ab4d2;
case 0x0c0ab4d4u: goto P_0c0ab4d4;
case 0x0c0ab4d6u: goto P_0c0ab4d6;
case 0x0c0ab4d8u: goto P_0c0ab4d8;
case 0x0c0ab4dau: goto P_0c0ab4da;
case 0x0c0ab4dcu: goto P_0c0ab4dc;
case 0x0c0ab4deu: goto P_0c0ab4de;
case 0x0c0ab4e0u: goto P_0c0ab4e0;
case 0x0c0ab4e2u: goto P_0c0ab4e2;
case 0x0c0ab4e4u: goto P_0c0ab4e4;
case 0x0c0ab4e6u: goto P_0c0ab4e6;
case 0x0c0ab4e8u: goto P_0c0ab4e8;
case 0x0c0ab4eau: goto P_0c0ab4ea;
case 0x0c0ab4ecu: goto P_0c0ab4ec;
case 0x0c0ab4eeu: goto P_0c0ab4ee;
case 0x0c0ab4f0u: goto P_0c0ab4f0;
case 0x0c0ab4f2u: goto P_0c0ab4f2;
case 0x0c0ab4f4u: goto P_0c0ab4f4;
case 0x0c0ab4f6u: goto P_0c0ab4f6;
case 0x0c0ab4f8u: goto P_0c0ab4f8;
case 0x0c0ab4fau: goto P_0c0ab4fa;
case 0x0c0ab4fcu: goto P_0c0ab4fc;
case 0x0c0ab4feu: goto P_0c0ab4fe;
case 0x0c0ab500u: goto P_0c0ab500;
case 0x0c0ab502u: goto P_0c0ab502;
case 0x0c0ab504u: goto P_0c0ab504;
case 0x0c0ab506u: goto P_0c0ab506;
case 0x0c0ab508u: goto P_0c0ab508;
case 0x0c0ab50au: goto P_0c0ab50a;
case 0x0c0ab50cu: goto P_0c0ab50c;
case 0x0c0ab50eu: goto P_0c0ab50e;
case 0x0c0ab510u: goto P_0c0ab510;
case 0x0c0ab512u: goto P_0c0ab512;
case 0x0c0ab514u: goto P_0c0ab514;
case 0x0c0ab516u: goto P_0c0ab516;
case 0x0c0ab518u: goto P_0c0ab518;
case 0x0c0ab51au: goto P_0c0ab51a;
case 0x0c0ab51cu: goto P_0c0ab51c;
case 0x0c0ab51eu: goto P_0c0ab51e;
case 0x0c0ab520u: goto P_0c0ab520;
case 0x0c0ab522u: goto P_0c0ab522;
case 0x0c0ab524u: goto P_0c0ab524;
case 0x0c0ab526u: goto P_0c0ab526;
case 0x0c0ab528u: goto P_0c0ab528;
case 0x0c0ab52au: goto P_0c0ab52a;
case 0x0c0ab52cu: goto P_0c0ab52c;
case 0x0c0ab52eu: goto P_0c0ab52e;
case 0x0c0ab530u: goto P_0c0ab530;
case 0x0c0ab532u: goto P_0c0ab532;
case 0x0c0ab534u: goto P_0c0ab534;
case 0x0c0ab536u: goto P_0c0ab536;
case 0x0c0ab538u: goto P_0c0ab538;
case 0x0c0ab53au: goto P_0c0ab53a;
case 0x0c0ab53cu: goto P_0c0ab53c;
case 0x0c0ab53eu: goto P_0c0ab53e;
case 0x0c0ab540u: goto P_0c0ab540;
case 0x0c0ab542u: goto P_0c0ab542;
case 0x0c0ab544u: goto P_0c0ab544;
case 0x0c0ab546u: goto P_0c0ab546;
case 0x0c0ab548u: goto P_0c0ab548;
case 0x0c0ab54au: goto P_0c0ab54a;
case 0x0c0ab54cu: goto P_0c0ab54c;
case 0x0c0ab54eu: goto P_0c0ab54e;
case 0x0c0ab550u: goto P_0c0ab550;
case 0x0c0ab552u: goto P_0c0ab552;
case 0x0c0ab554u: goto P_0c0ab554;
case 0x0c0ab556u: goto P_0c0ab556;
case 0x0c0ab558u: goto P_0c0ab558;
case 0x0c0ab55au: goto P_0c0ab55a;
case 0x0c0ab55cu: goto P_0c0ab55c;
case 0x0c0ab55eu: goto P_0c0ab55e;
case 0x0c0ab560u: goto P_0c0ab560;
case 0x0c0ab562u: goto P_0c0ab562;
case 0x0c0ab564u: goto P_0c0ab564;
case 0x0c0ab566u: goto P_0c0ab566;
case 0x0c0ab568u: goto P_0c0ab568;
case 0x0c0ab56au: goto P_0c0ab56a;
case 0x0c0ab56cu: goto P_0c0ab56c;
case 0x0c0ab56eu: goto P_0c0ab56e;
case 0x0c0ab570u: goto P_0c0ab570;
case 0x0c0ab572u: goto P_0c0ab572;
case 0x0c0ab574u: goto P_0c0ab574;
case 0x0c0ab576u: goto P_0c0ab576;
case 0x0c0ab578u: goto P_0c0ab578;
case 0x0c0ab57au: goto P_0c0ab57a;
case 0x0c0ab57cu: goto P_0c0ab57c;
case 0x0c0ab57eu: goto P_0c0ab57e;
case 0x0c0ab580u: goto P_0c0ab580;
case 0x0c0ab582u: goto P_0c0ab582;
case 0x0c0ab584u: goto P_0c0ab584;
case 0x0c0ab586u: goto P_0c0ab586;
case 0x0c0ab588u: goto P_0c0ab588;
case 0x0c0ab58au: goto P_0c0ab58a;
case 0x0c0ab58cu: goto P_0c0ab58c;
case 0x0c0ab58eu: goto P_0c0ab58e;
case 0x0c0ab590u: goto P_0c0ab590;
case 0x0c0ab592u: goto P_0c0ab592;
case 0x0c0ab594u: goto P_0c0ab594;
case 0x0c0ab596u: goto P_0c0ab596;
case 0x0c0ab598u: goto P_0c0ab598;
case 0x0c0ab59au: goto P_0c0ab59a;
case 0x0c0ab59cu: goto P_0c0ab59c;
case 0x0c0ab59eu: goto P_0c0ab59e;
case 0x0c0ab5a0u: goto P_0c0ab5a0;
case 0x0c0ab5a2u: goto P_0c0ab5a2;
case 0x0c0ab5a4u: goto P_0c0ab5a4;
case 0x0c0ab5a6u: goto P_0c0ab5a6;
case 0x0c0ab5a8u: goto P_0c0ab5a8;
case 0x0c0ab5aau: goto P_0c0ab5aa;
case 0x0c0ab5acu: goto P_0c0ab5ac;
case 0x0c0ab5aeu: goto P_0c0ab5ae;
case 0x0c0ab5b0u: goto P_0c0ab5b0;
case 0x0c0ab5b2u: goto P_0c0ab5b2;
case 0x0c0ab5b4u: goto P_0c0ab5b4;
case 0x0c0ab5b6u: goto P_0c0ab5b6;
case 0x0c0ab5b8u: goto P_0c0ab5b8;
case 0x0c0ab5bau: goto P_0c0ab5ba;
case 0x0c0ab5bcu: goto P_0c0ab5bc;
case 0x0c0ab5beu: goto P_0c0ab5be;
case 0x0c0ab5c0u: goto P_0c0ab5c0;
case 0x0c0ab5e4u: goto P_0c0ab5e4;
case 0x0c0ab5e6u: goto P_0c0ab5e6;
case 0x0c0ab5e8u: goto P_0c0ab5e8;
case 0x0c0ab5eau: goto P_0c0ab5ea;
case 0x0c0ab5ecu: goto P_0c0ab5ec;
case 0x0c0ab5eeu: goto P_0c0ab5ee;
case 0x0c0ab5f0u: goto P_0c0ab5f0;
case 0x0c0ab5f2u: goto P_0c0ab5f2;
case 0x0c0ab5f4u: goto P_0c0ab5f4;
case 0x0c0ab5f6u: goto P_0c0ab5f6;
case 0x0c0ab5f8u: goto P_0c0ab5f8;
case 0x0c0ab5fau: goto P_0c0ab5fa;
case 0x0c0ab5fcu: goto P_0c0ab5fc;
case 0x0c0ab5feu: goto P_0c0ab5fe;
case 0x0c0ab600u: goto P_0c0ab600;
case 0x0c0ab602u: goto P_0c0ab602;
case 0x0c0ab604u: goto P_0c0ab604;
case 0x0c0ab606u: goto P_0c0ab606;
case 0x0c0ab608u: goto P_0c0ab608;
case 0x0c0ab60au: goto P_0c0ab60a;
case 0x0c0ab60cu: goto P_0c0ab60c;
case 0x0c0ab60eu: goto P_0c0ab60e;
case 0x0c0ab610u: goto P_0c0ab610;
case 0x0c0ab612u: goto P_0c0ab612;
case 0x0c0ab614u: goto P_0c0ab614;
case 0x0c0ab616u: goto P_0c0ab616;
case 0x0c0ab618u: goto P_0c0ab618;
case 0x0c0ab61au: goto P_0c0ab61a;
case 0x0c0ab61cu: goto P_0c0ab61c;
case 0x0c0ab61eu: goto P_0c0ab61e;
case 0x0c0ab620u: goto P_0c0ab620;
case 0x0c0ab622u: goto P_0c0ab622;
case 0x0c0ab624u: goto P_0c0ab624;
case 0x0c0ab626u: goto P_0c0ab626;
case 0x0c0ab628u: goto P_0c0ab628;
case 0x0c0ab62au: goto P_0c0ab62a;
case 0x0c0ab62cu: goto P_0c0ab62c;
case 0x0c0ab62eu: goto P_0c0ab62e;
case 0x0c0ab630u: goto P_0c0ab630;
case 0x0c0ab632u: goto P_0c0ab632;
case 0x0c0ab634u: goto P_0c0ab634;
case 0x0c0ab636u: goto P_0c0ab636;
case 0x0c0ab638u: goto P_0c0ab638;
case 0x0c0ab63au: goto P_0c0ab63a;
case 0x0c0ab63cu: goto P_0c0ab63c;
case 0x0c0ab63eu: goto P_0c0ab63e;
case 0x0c0ab640u: goto P_0c0ab640;
case 0x0c0ab642u: goto P_0c0ab642;
case 0x0c0ab644u: goto P_0c0ab644;
case 0x0c0ab646u: goto P_0c0ab646;
case 0x0c0ab648u: goto P_0c0ab648;
case 0x0c0ab64au: goto P_0c0ab64a;
case 0x0c0ab64cu: goto P_0c0ab64c;
case 0x0c0ab64eu: goto P_0c0ab64e;
case 0x0c0ab650u: goto P_0c0ab650;
case 0x0c0ab652u: goto P_0c0ab652;
case 0x0c0ab654u: goto P_0c0ab654;
case 0x0c0ab656u: goto P_0c0ab656;
case 0x0c0ab658u: goto P_0c0ab658;
case 0x0c0ab65au: goto P_0c0ab65a;
case 0x0c0ab65cu: goto P_0c0ab65c;
case 0x0c0ab65eu: goto P_0c0ab65e;
case 0x0c0ab660u: goto P_0c0ab660;
case 0x0c0ab662u: goto P_0c0ab662;
case 0x0c0ab664u: goto P_0c0ab664;
case 0x0c0ab666u: goto P_0c0ab666;
case 0x0c0ab668u: goto P_0c0ab668;
case 0x0c0ab66au: goto P_0c0ab66a;
case 0x0c0ab66cu: goto P_0c0ab66c;
case 0x0c0ab66eu: goto P_0c0ab66e;
case 0x0c0ab670u: goto P_0c0ab670;
case 0x0c0ab672u: goto P_0c0ab672;
case 0x0c0ab674u: goto P_0c0ab674;
case 0x0c0ab676u: goto P_0c0ab676;
case 0x0c0ab678u: goto P_0c0ab678;
case 0x0c0ab67au: goto P_0c0ab67a;
case 0x0c0ab67cu: goto P_0c0ab67c;
case 0x0c0ab67eu: goto P_0c0ab67e;
case 0x0c0ab680u: goto P_0c0ab680;
case 0x0c0ab682u: goto P_0c0ab682;
case 0x0c0ab684u: goto P_0c0ab684;
case 0x0c0ab686u: goto P_0c0ab686;
case 0x0c0ab688u: goto P_0c0ab688;
case 0x0c0ab68au: goto P_0c0ab68a;
case 0x0c0ab68cu: goto P_0c0ab68c;
case 0x0c0ab68eu: goto P_0c0ab68e;
case 0x0c0ab690u: goto P_0c0ab690;
case 0x0c0ab692u: goto P_0c0ab692;
case 0x0c0ab694u: goto P_0c0ab694;
case 0x0c0ab696u: goto P_0c0ab696;
case 0x0c0ab698u: goto P_0c0ab698;
case 0x0c0ab69au: goto P_0c0ab69a;
case 0x0c0ab69cu: goto P_0c0ab69c;
case 0x0c0ab69eu: goto P_0c0ab69e;
case 0x0c0ab6a0u: goto P_0c0ab6a0;
case 0x0c0ab6a2u: goto P_0c0ab6a2;
case 0x0c0ab6a4u: goto P_0c0ab6a4;
case 0x0c0ab6a6u: goto P_0c0ab6a6;
case 0x0c0ab6a8u: goto P_0c0ab6a8;
case 0x0c0ab6aau: goto P_0c0ab6aa;
case 0x0c0ab6acu: goto P_0c0ab6ac;
case 0x0c0ab6aeu: goto P_0c0ab6ae;
case 0x0c0ab6b0u: goto P_0c0ab6b0;
case 0x0c0ab6b2u: goto P_0c0ab6b2;
case 0x0c0ab6b4u: goto P_0c0ab6b4;
case 0x0c0ab6b6u: goto P_0c0ab6b6;
case 0x0c0ab6b8u: goto P_0c0ab6b8;
case 0x0c0ab6bau: goto P_0c0ab6ba;
case 0x0c0ab6bcu: goto P_0c0ab6bc;
case 0x0c0ab6beu: goto P_0c0ab6be;
case 0x0c0ab6c0u: goto P_0c0ab6c0;
case 0x0c0ab6c2u: goto P_0c0ab6c2;
case 0x0c0ab6c4u: goto P_0c0ab6c4;
case 0x0c0ab6c6u: goto P_0c0ab6c6;
case 0x0c0ab6c8u: goto P_0c0ab6c8;
case 0x0c0ab6cau: goto P_0c0ab6ca;
case 0x0c0ab6ccu: goto P_0c0ab6cc;
case 0x0c0ab6ceu: goto P_0c0ab6ce;
case 0x0c0ab6d0u: goto P_0c0ab6d0;
case 0x0c0ab6d2u: goto P_0c0ab6d2;
case 0x0c0ab6d4u: goto P_0c0ab6d4;
case 0x0c0ab6d6u: goto P_0c0ab6d6;
case 0x0c0ab6d8u: goto P_0c0ab6d8;
case 0x0c0ab6dau: goto P_0c0ab6da;
case 0x0c0ab6dcu: goto P_0c0ab6dc;
case 0x0c0ab6deu: goto P_0c0ab6de;
case 0x0c0ab6e0u: goto P_0c0ab6e0;
case 0x0c0ab6e2u: goto P_0c0ab6e2;
case 0x0c0ab6e4u: goto P_0c0ab6e4;
case 0x0c0ab6e6u: goto P_0c0ab6e6;
case 0x0c0ab6e8u: goto P_0c0ab6e8;
case 0x0c0ab6eau: goto P_0c0ab6ea;
case 0x0c0ab6ecu: goto P_0c0ab6ec;
case 0x0c0ab6eeu: goto P_0c0ab6ee;
case 0x0c0ab6f0u: goto P_0c0ab6f0;
case 0x0c0ab6f2u: goto P_0c0ab6f2;
case 0x0c0ab71cu: goto P_0c0ab71c;
case 0x0c0ab71eu: goto P_0c0ab71e;
case 0x0c0ab720u: goto P_0c0ab720;
case 0x0c0ab722u: goto P_0c0ab722;
case 0x0c0ab724u: goto P_0c0ab724;
case 0x0c0ab726u: goto P_0c0ab726;
case 0x0c0ab728u: goto P_0c0ab728;
case 0x0c0ab72au: goto P_0c0ab72a;
case 0x0c0ab72cu: goto P_0c0ab72c;
case 0x0c0ab72eu: goto P_0c0ab72e;
case 0x0c0ab730u: goto P_0c0ab730;
case 0x0c0ab732u: goto P_0c0ab732;
case 0x0c0ab734u: goto P_0c0ab734;
case 0x0c0ab736u: goto P_0c0ab736;
case 0x0c0ab738u: goto P_0c0ab738;
case 0x0c0ab73au: goto P_0c0ab73a;
case 0x0c0ab73cu: goto P_0c0ab73c;
case 0x0c0ab73eu: goto P_0c0ab73e;
case 0x0c0ab740u: goto P_0c0ab740;
case 0x0c0ab742u: goto P_0c0ab742;
case 0x0c0ab744u: goto P_0c0ab744;
case 0x0c0ab746u: goto P_0c0ab746;
case 0x0c0ab748u: goto P_0c0ab748;
case 0x0c0ab74au: goto P_0c0ab74a;
case 0x0c0ab74cu: goto P_0c0ab74c;
case 0x0c0ab74eu: goto P_0c0ab74e;
case 0x0c0ab750u: goto P_0c0ab750;
case 0x0c0ab752u: goto P_0c0ab752;
case 0x0c0ab754u: goto P_0c0ab754;
case 0x0c0ab756u: goto P_0c0ab756;
case 0x0c0ab758u: goto P_0c0ab758;
case 0x0c0ab75au: goto P_0c0ab75a;
case 0x0c0ab75cu: goto P_0c0ab75c;
case 0x0c0ab75eu: goto P_0c0ab75e;
case 0x0c0ab760u: goto P_0c0ab760;
case 0x0c0ab762u: goto P_0c0ab762;
case 0x0c0ab764u: goto P_0c0ab764;
case 0x0c0ab766u: goto P_0c0ab766;
case 0x0c0ab768u: goto P_0c0ab768;
case 0x0c0ab76au: goto P_0c0ab76a;
case 0x0c0ab76cu: goto P_0c0ab76c;
case 0x0c0ab76eu: goto P_0c0ab76e;
case 0x0c0ab770u: goto P_0c0ab770;
case 0x0c0ab772u: goto P_0c0ab772;
case 0x0c0ab774u: goto P_0c0ab774;
case 0x0c0ab776u: goto P_0c0ab776;
case 0x0c0ab778u: goto P_0c0ab778;
case 0x0c0ab77au: goto P_0c0ab77a;
case 0x0c0ab77cu: goto P_0c0ab77c;
case 0x0c0ab77eu: goto P_0c0ab77e;
case 0x0c0ab780u: goto P_0c0ab780;
case 0x0c0ab782u: goto P_0c0ab782;
case 0x0c0ab784u: goto P_0c0ab784;
case 0x0c0ab786u: goto P_0c0ab786;
case 0x0c0ab788u: goto P_0c0ab788;
case 0x0c0ab78au: goto P_0c0ab78a;
case 0x0c0ab78cu: goto P_0c0ab78c;
case 0x0c0ab78eu: goto P_0c0ab78e;
case 0x0c0ab790u: goto P_0c0ab790;
case 0x0c0ab792u: goto P_0c0ab792;
case 0x0c0ab794u: goto P_0c0ab794;
case 0x0c0ab796u: goto P_0c0ab796;
case 0x0c0ab798u: goto P_0c0ab798;
case 0x0c0ab79au: goto P_0c0ab79a;
case 0x0c0ab79cu: goto P_0c0ab79c;
case 0x0c0ab79eu: goto P_0c0ab79e;
case 0x0c0ab7a0u: goto P_0c0ab7a0;
case 0x0c0ab7a2u: goto P_0c0ab7a2;
case 0x0c0ab7a4u: goto P_0c0ab7a4;
case 0x0c0ab7a6u: goto P_0c0ab7a6;
case 0x0c0ab7a8u: goto P_0c0ab7a8;
case 0x0c0ab7aau: goto P_0c0ab7aa;
case 0x0c0ab7acu: goto P_0c0ab7ac;
case 0x0c0ab7aeu: goto P_0c0ab7ae;
case 0x0c0ab7b0u: goto P_0c0ab7b0;
case 0x0c0ab7b2u: goto P_0c0ab7b2;
case 0x0c0ab7b4u: goto P_0c0ab7b4;
case 0x0c0ab7b6u: goto P_0c0ab7b6;
case 0x0c0ab7b8u: goto P_0c0ab7b8;
case 0x0c0ab7bau: goto P_0c0ab7ba;
case 0x0c0ab7bcu: goto P_0c0ab7bc;
case 0x0c0ab7beu: goto P_0c0ab7be;
case 0x0c0ab7c0u: goto P_0c0ab7c0;
case 0x0c0ab7c2u: goto P_0c0ab7c2;
case 0x0c0ab7c4u: goto P_0c0ab7c4;
case 0x0c0ab7c6u: goto P_0c0ab7c6;
case 0x0c0ab7c8u: goto P_0c0ab7c8;
case 0x0c0ab7cau: goto P_0c0ab7ca;
case 0x0c0ab7ccu: goto P_0c0ab7cc;
case 0x0c0ab7ceu: goto P_0c0ab7ce;
case 0x0c0ab7d0u: goto P_0c0ab7d0;
case 0x0c0ab7d2u: goto P_0c0ab7d2;
case 0x0c0ab7d4u: goto P_0c0ab7d4;
case 0x0c0ab7d6u: goto P_0c0ab7d6;
case 0x0c0ab7d8u: goto P_0c0ab7d8;
case 0x0c0ab7dau: goto P_0c0ab7da;
case 0x0c0ab7dcu: goto P_0c0ab7dc;
case 0x0c0ab7deu: goto P_0c0ab7de;
case 0x0c0ab7e0u: goto P_0c0ab7e0;
case 0x0c0ab7e2u: goto P_0c0ab7e2;
case 0x0c0ab7e4u: goto P_0c0ab7e4;
case 0x0c0ab7e6u: goto P_0c0ab7e6;
case 0x0c0ab7e8u: goto P_0c0ab7e8;
case 0x0c0ab7eau: goto P_0c0ab7ea;
case 0x0c0ab7ecu: goto P_0c0ab7ec;
case 0x0c0ab7eeu: goto P_0c0ab7ee;
case 0x0c0ab7f0u: goto P_0c0ab7f0;
case 0x0c0ab7f2u: goto P_0c0ab7f2;
case 0x0c0ab7f4u: goto P_0c0ab7f4;
case 0x0c0ab7f6u: goto P_0c0ab7f6;
case 0x0c0ab7f8u: goto P_0c0ab7f8;
case 0x0c0ab7fau: goto P_0c0ab7fa;
case 0x0c0ab7fcu: goto P_0c0ab7fc;
case 0x0c0ab7feu: goto P_0c0ab7fe;
case 0x0c0ab800u: goto P_0c0ab800;
case 0x0c0ab802u: goto P_0c0ab802;
case 0x0c0ab804u: goto P_0c0ab804;
case 0x0c0ab806u: goto P_0c0ab806;
case 0x0c0ab808u: goto P_0c0ab808;
case 0x0c0ab80au: goto P_0c0ab80a;
case 0x0c0ab80cu: goto P_0c0ab80c;
case 0x0c0ab80eu: goto P_0c0ab80e;
case 0x0c0ab810u: goto P_0c0ab810;
case 0x0c0ab812u: goto P_0c0ab812;
case 0x0c0ab814u: goto P_0c0ab814;
case 0x0c0ab816u: goto P_0c0ab816;
case 0x0c0ab818u: goto P_0c0ab818;
case 0x0c0ab81au: goto P_0c0ab81a;
case 0x0c0ab81cu: goto P_0c0ab81c;
case 0x0c0ab81eu: goto P_0c0ab81e;
case 0x0c0ab820u: goto P_0c0ab820;
case 0x0c0ab822u: goto P_0c0ab822;
case 0x0c0ab824u: goto P_0c0ab824;
case 0x0c0ab826u: goto P_0c0ab826;
case 0x0c0ab828u: goto P_0c0ab828;
case 0x0c0ab82au: goto P_0c0ab82a;
case 0x0c0ab82cu: goto P_0c0ab82c;
case 0x0c0ab82eu: goto P_0c0ab82e;
case 0x0c0ab830u: goto P_0c0ab830;
case 0x0c0ab832u: goto P_0c0ab832;
case 0x0c0ab834u: goto P_0c0ab834;
case 0x0c0ab836u: goto P_0c0ab836;
case 0x0c0ab838u: goto P_0c0ab838;
case 0x0c0ab83au: goto P_0c0ab83a;
case 0x0c0ab83cu: goto P_0c0ab83c;
case 0x0c0ab83eu: goto P_0c0ab83e;
default: return vf3_matrix_family(target,s,ram);
}
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
P_0c0ab340: /* original 2fe6, guest PC 0x0c0ab340 */
if(!s->budget--) { s->failed_pc=0x0c0ab340u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ab342;
P_0c0ab342: /* original 6e43, guest PC 0x0c0ab342 */
if(!s->budget--) { s->failed_pc=0x0c0ab342u; return 0; }
r[14]=r[4];
goto P_0c0ab344;
P_0c0ab344: /* original 2fd6, guest PC 0x0c0ab344 */
if(!s->budget--) { s->failed_pc=0x0c0ab344u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ab346;
P_0c0ab346: /* original 6d63, guest PC 0x0c0ab346 */
if(!s->budget--) { s->failed_pc=0x0c0ab346u; return 0; }
r[13]=r[6];
goto P_0c0ab348;
P_0c0ab348: /* original 2fc6, guest PC 0x0c0ab348 */
if(!s->budget--) { s->failed_pc=0x0c0ab348u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ab34a;
P_0c0ab34a: /* original e048, guest PC 0x0c0ab34a */
if(!s->budget--) { s->failed_pc=0x0c0ab34au; return 0; }
r[0]=0x00000048u;
goto P_0c0ab34c;
P_0c0ab34c: /* original 2fb6, guest PC 0x0c0ab34c */
if(!s->budget--) { s->failed_pc=0x0c0ab34cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ab34e;
P_0c0ab34e: /* original 6b53, guest PC 0x0c0ab34e */
if(!s->budget--) { s->failed_pc=0x0c0ab34eu; return 0; }
r[11]=r[5];
goto P_0c0ab350;
P_0c0ab350: /* original 2fa6, guest PC 0x0c0ab350 */
if(!s->budget--) { s->failed_pc=0x0c0ab350u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ab352;
P_0c0ab352: /* original fffb, guest PC 0x0c0ab352 */
if(!s->budget--) { s->failed_pc=0x0c0ab352u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0ab354;
P_0c0ab354: /* original ffeb, guest PC 0x0c0ab354 */
if(!s->budget--) { s->failed_pc=0x0c0ab354u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0ab356;
P_0c0ab356: /* original ffdb, guest PC 0x0c0ab356 */
if(!s->budget--) { s->failed_pc=0x0c0ab356u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0ab358;
P_0c0ab358: /* original ffcb, guest PC 0x0c0ab358 */
if(!s->budget--) { s->failed_pc=0x0c0ab358u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0ab35a;
P_0c0ab35a: /* original 4f22, guest PC 0x0c0ab35a */
if(!s->budget--) { s->failed_pc=0x0c0ab35au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ab35c;
P_0c0ab35c: /* original d34a, guest PC 0x0c0ab35c */
if(!s->budget--) { s->failed_pc=0x0c0ab35cu; return 0; }
r[3]=read(ram,0x0c0ab488u,4);
goto P_0c0ab35e;
P_0c0ab35e: /* original 7fd8, guest PC 0x0c0ab35e */
if(!s->budget--) { s->failed_pc=0x0c0ab35eu; return 0; }
r[15]+=0xffffffd8u;
goto P_0c0ab360;
P_0c0ab360: /* original 1f39, guest PC 0x0c0ab360 */
if(!s->budget--) { s->failed_pc=0x0c0ab360u; return 0; }
write(ram,r[15]+36,r[3],4);
goto P_0c0ab362;
P_0c0ab362: /* original d24a, guest PC 0x0c0ab362 */
if(!s->budget--) { s->failed_pc=0x0c0ab362u; return 0; }
r[2]=read(ram,0x0c0ab48cu,4);
goto P_0c0ab364;
P_0c0ab364: /* original 1f27, guest PC 0x0c0ab364 */
if(!s->budget--) { s->failed_pc=0x0c0ab364u; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c0ab366;
P_0c0ab366: /* original 63e2, guest PC 0x0c0ab366 */
if(!s->budget--) { s->failed_pc=0x0c0ab366u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0ab368;
P_0c0ab368: /* original 0cee, guest PC 0x0c0ab368 */
if(!s->budget--) { s->failed_pc=0x0c0ab368u; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c0ab36a;
P_0c0ab36a: /* original 1f36, guest PC 0x0c0ab36a */
if(!s->budget--) { s->failed_pc=0x0c0ab36au; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0ab36c;
P_0c0ab36c: /* original 53d1, guest PC 0x0c0ab36c */
if(!s->budget--) { s->failed_pc=0x0c0ab36cu; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0ab36e;
P_0c0ab36e: /* original 2338, guest PC 0x0c0ab36e */
if(!s->budget--) { s->failed_pc=0x0c0ab36eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0ab370;
P_0c0ab370: /* original 8d05, guest PC 0x0c0ab370 */
if(!s->budget--) { s->failed_pc=0x0c0ab370u; return 0; }
cond=r[17]&1u;
fr[13]=0x3f800000u;
if(cond) { goto P_0c0ab37e; }
goto P_0c0ab374;
P_0c0ab372: /* original fd9d, guest PC 0x0c0ab372 */
if(!s->budget--) { s->failed_pc=0x0c0ab372u; return 0; }
fr[13]=0x3f800000u;
goto P_0c0ab374;
P_0c0ab374: /* original 50d1, guest PC 0x0c0ab374 */
if(!s->budget--) { s->failed_pc=0x0c0ab374u; return 0; }
r[0]=read(ram,r[13]+4,4);
goto P_0c0ab376;
P_0c0ab376: /* original 8801, guest PC 0x0c0ab376 */
if(!s->budget--) { s->failed_pc=0x0c0ab376u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0ab378;
P_0c0ab378: /* original 8b01, guest PC 0x0c0ab378 */
if(!s->budget--) { s->failed_pc=0x0c0ab378u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab37e; }
goto P_0c0ab37a;
P_0c0ab37a: /* original a1cf, guest PC 0x0c0ab37a */
if(!s->budget--) { s->failed_pc=0x0c0ab37au; return 0; }
goto P_0c0ab71c;
P_0c0ab37c: /* original 0009, guest PC 0x0c0ab37c */
if(!s->budget--) { s->failed_pc=0x0c0ab37cu; return 0; }
goto P_0c0ab37e;
P_0c0ab37e: /* original e03e, guest PC 0x0c0ab37e */
if(!s->budget--) { s->failed_pc=0x0c0ab37eu; return 0; }
r[0]=0x0000003eu;
goto P_0c0ab380;
P_0c0ab380: /* original 03ed, guest PC 0x0c0ab380 */
if(!s->budget--) { s->failed_pc=0x0c0ab380u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab382;
P_0c0ab382: /* original 633d, guest PC 0x0c0ab382 */
if(!s->budget--) { s->failed_pc=0x0c0ab382u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0ab384;
P_0c0ab384: /* original 1f32, guest PC 0x0c0ab384 */
if(!s->budget--) { s->failed_pc=0x0c0ab384u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0ab386;
P_0c0ab386: /* original 9076, guest PC 0x0c0ab386 */
if(!s->budget--) { s->failed_pc=0x0c0ab386u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab476u,2);
goto P_0c0ab388;
P_0c0ab388: /* original 02ed, guest PC 0x0c0ab388 */
if(!s->budget--) { s->failed_pc=0x0c0ab388u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab38a;
P_0c0ab38a: /* original 622d, guest PC 0x0c0ab38a */
if(!s->budget--) { s->failed_pc=0x0c0ab38au; return 0; }
r[2]=r[2]&65535u;
goto P_0c0ab38c;
P_0c0ab38c: /* original 1f24, guest PC 0x0c0ab38c */
if(!s->budget--) { s->failed_pc=0x0c0ab38cu; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0ab38e;
P_0c0ab38e: /* original 53f2, guest PC 0x0c0ab38e */
if(!s->budget--) { s->failed_pc=0x0c0ab38eu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0ab390;
P_0c0ab390: /* original 3322, guest PC 0x0c0ab390 */
if(!s->budget--) { s->failed_pc=0x0c0ab390u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c0ab392;
P_0c0ab392: /* original 8901, guest PC 0x0c0ab392 */
if(!s->budget--) { s->failed_pc=0x0c0ab392u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab398; }
goto P_0c0ab394;
P_0c0ab394: /* original a248, guest PC 0x0c0ab394 */
if(!s->budget--) { s->failed_pc=0x0c0ab394u; return 0; }
goto P_0c0ab828;
P_0c0ab396: /* original 0009, guest PC 0x0c0ab396 */
if(!s->budget--) { s->failed_pc=0x0c0ab396u; return 0; }
goto P_0c0ab398;
P_0c0ab398: /* original d23d, guest PC 0x0c0ab398 */
if(!s->budget--) { s->failed_pc=0x0c0ab398u; return 0; }
r[2]=read(ram,0x0c0ab490u,4);
goto P_0c0ab39a;
P_0c0ab39a: /* original e048, guest PC 0x0c0ab39a */
if(!s->budget--) { s->failed_pc=0x0c0ab39au; return 0; }
r[0]=0x00000048u;
goto P_0c0ab39c;
P_0c0ab39c: /* original 2c29, guest PC 0x0c0ab39c */
if(!s->budget--) { s->failed_pc=0x0c0ab39cu; return 0; }
r[12]&=r[2];
goto P_0c0ab39e;
P_0c0ab39e: /* original 0ec6, guest PC 0x0c0ab39e */
if(!s->budget--) { s->failed_pc=0x0c0ab39eu; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c0ab3a0;
P_0c0ab3a0: /* original 63d2, guest PC 0x0c0ab3a0 */
if(!s->budget--) { s->failed_pc=0x0c0ab3a0u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ab3a2;
P_0c0ab3a2: /* original 633d, guest PC 0x0c0ab3a2 */
if(!s->budget--) { s->failed_pc=0x0c0ab3a2u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0ab3a4;
P_0c0ab3a4: /* original 2338, guest PC 0x0c0ab3a4 */
if(!s->budget--) { s->failed_pc=0x0c0ab3a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0ab3a6;
P_0c0ab3a6: /* original 8d09, guest PC 0x0c0ab3a6 */
if(!s->budget--) { s->failed_pc=0x0c0ab3a6u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+16,r[3],4);
if(cond) { goto P_0c0ab3bc; }
goto P_0c0ab3aa;
P_0c0ab3a8: /* original 1f34, guest PC 0x0c0ab3a8 */
if(!s->budget--) { s->failed_pc=0x0c0ab3a8u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0ab3aa;
P_0c0ab3aa: /* original e03c, guest PC 0x0c0ab3aa */
if(!s->budget--) { s->failed_pc=0x0c0ab3aau; return 0; }
r[0]=0x0000003cu;
goto P_0c0ab3ac;
P_0c0ab3ac: /* original 01ed, guest PC 0x0c0ab3ac */
if(!s->budget--) { s->failed_pc=0x0c0ab3acu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab3ae;
P_0c0ab3ae: /* original 611d, guest PC 0x0c0ab3ae */
if(!s->budget--) { s->failed_pc=0x0c0ab3aeu; return 0; }
r[1]=r[1]&65535u;
goto P_0c0ab3b0;
P_0c0ab3b0: /* original 3310, guest PC 0x0c0ab3b0 */
if(!s->budget--) { s->failed_pc=0x0c0ab3b0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c0ab3b2;
P_0c0ab3b2: /* original 8903, guest PC 0x0c0ab3b2 */
if(!s->budget--) { s->failed_pc=0x0c0ab3b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab3bc; }
goto P_0c0ab3b4;
P_0c0ab3b4: /* original d337, guest PC 0x0c0ab3b4 */
if(!s->budget--) { s->failed_pc=0x0c0ab3b4u; return 0; }
r[3]=read(ram,0x0c0ab494u,4);
goto P_0c0ab3b6;
P_0c0ab3b6: /* original 55f4, guest PC 0x0c0ab3b6 */
if(!s->budget--) { s->failed_pc=0x0c0ab3b6u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c0ab3b8;
P_0c0ab3b8: /* original 430b, guest PC 0x0c0ab3b8 */
if(!s->budget--) { s->failed_pc=0x0c0ab3b8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0ab3bcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab3bcu) { target=s->pc; goto dispatch; }
goto P_0c0ab3bc;
P_0c0ab3ba: /* original 64e3, guest PC 0x0c0ab3ba */
if(!s->budget--) { s->failed_pc=0x0c0ab3bau; return 0; }
r[4]=r[14];
goto P_0c0ab3bc;
P_0c0ab3bc: /* original 905c, guest PC 0x0c0ab3bc */
if(!s->budget--) { s->failed_pc=0x0c0ab3bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab478u,2);
goto P_0c0ab3be;
P_0c0ab3be: /* original 02ec, guest PC 0x0c0ab3be */
if(!s->budget--) { s->failed_pc=0x0c0ab3beu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ab3c0;
P_0c0ab3c0: /* original e064, guest PC 0x0c0ab3c0 */
if(!s->budget--) { s->failed_pc=0x0c0ab3c0u; return 0; }
r[0]=0x00000064u;
goto P_0c0ab3c2;
P_0c0ab3c2: /* original 622c, guest PC 0x0c0ab3c2 */
if(!s->budget--) { s->failed_pc=0x0c0ab3c2u; return 0; }
r[2]=r[2]&255u;
goto P_0c0ab3c4;
P_0c0ab3c4: /* original 6323, guest PC 0x0c0ab3c4 */
if(!s->budget--) { s->failed_pc=0x0c0ab3c4u; return 0; }
r[3]=r[2];
goto P_0c0ab3c6;
P_0c0ab3c6: /* original 1f22, guest PC 0x0c0ab3c6 */
if(!s->budget--) { s->failed_pc=0x0c0ab3c6u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0ab3c8;
P_0c0ab3c8: /* original 0e35, guest PC 0x0c0ab3c8 */
if(!s->budget--) { s->failed_pc=0x0c0ab3c8u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0ab3ca;
P_0c0ab3ca: /* original 52f2, guest PC 0x0c0ab3ca */
if(!s->budget--) { s->failed_pc=0x0c0ab3cau; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0ab3cc;
P_0c0ab3cc: /* original f28d, guest PC 0x0c0ab3cc */
if(!s->budget--) { s->failed_pc=0x0c0ab3ccu; return 0; }
fr[2]=0;
goto P_0c0ab3ce;
P_0c0ab3ce: /* original 425a, guest PC 0x0c0ab3ce */
if(!s->budget--) { s->failed_pc=0x0c0ab3ceu; return 0; }
r[53]=r[2];
goto P_0c0ab3d0;
P_0c0ab3d0: /* original f32d, guest PC 0x0c0ab3d0 */
if(!s->budget--) { s->failed_pc=0x0c0ab3d0u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0ab3d2;
P_0c0ab3d2: /* original f235, guest PC 0x0c0ab3d2 */
if(!s->budget--) { s->failed_pc=0x0c0ab3d2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0ab3d4;
P_0c0ab3d4: /* original 8f03, guest PC 0x0c0ab3d4 */
if(!s->budget--) { s->failed_pc=0x0c0ab3d4u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,3);
if(!cond) { goto P_0c0ab3de; }
goto P_0c0ab3d8;
P_0c0ab3d6: /* original f43c, guest PC 0x0c0ab3d6 */
if(!s->budget--) { s->failed_pc=0x0c0ab3d6u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0ab3d8;
P_0c0ab3d8: /* original c72f, guest PC 0x0c0ab3d8 */
if(!s->budget--) { s->failed_pc=0x0c0ab3d8u; return 0; }
r[0]=code_base|0x000ab498u;
goto P_0c0ab3da;
P_0c0ab3da: /* original f308, guest PC 0x0c0ab3da */
if(!s->budget--) { s->failed_pc=0x0c0ab3dau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0ab3dc;
P_0c0ab3dc: /* original f430, guest PC 0x0c0ab3dc */
if(!s->budget--) { s->failed_pc=0x0c0ab3dcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0ab3de;
P_0c0ab3de: /* original 53f9, guest PC 0x0c0ab3de */
if(!s->budget--) { s->failed_pc=0x0c0ab3deu; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c0ab3e0;
P_0c0ab3e0: /* original 904b, guest PC 0x0c0ab3e0 */
if(!s->budget--) { s->failed_pc=0x0c0ab3e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab47au,2);
goto P_0c0ab3e2;
P_0c0ab3e2: /* original f138, guest PC 0x0c0ab3e2 */
if(!s->budget--) { s->failed_pc=0x0c0ab3e2u; return 0; }
vf3_matrix_load(s,ram,1,r[3]);
goto P_0c0ab3e4;
P_0c0ab3e4: /* original f2e6, guest PC 0x0c0ab3e4 */
if(!s->budget--) { s->failed_pc=0x0c0ab3e4u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0ab3e6;
P_0c0ab3e6: /* original c72d, guest PC 0x0c0ab3e6 */
if(!s->budget--) { s->failed_pc=0x0c0ab3e6u; return 0; }
r[0]=code_base|0x000ab49cu;
goto P_0c0ab3e8;
P_0c0ab3e8: /* original f34c, guest PC 0x0c0ab3e8 */
if(!s->budget--) { s->failed_pc=0x0c0ab3e8u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0ab3ea;
P_0c0ab3ea: /* original f3d0, guest PC 0x0c0ab3ea */
if(!s->budget--) { s->failed_pc=0x0c0ab3eau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[13],r[18],'+');
goto P_0c0ab3ec;
P_0c0ab3ec: /* original f121, guest PC 0x0c0ab3ec */
if(!s->budget--) { s->failed_pc=0x0c0ab3ecu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'-');
goto P_0c0ab3ee;
P_0c0ab3ee: /* original f208, guest PC 0x0c0ab3ee */
if(!s->budget--) { s->failed_pc=0x0c0ab3eeu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0ab3f0;
P_0c0ab3f0: /* original 9044, guest PC 0x0c0ab3f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab3f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab47cu,2);
goto P_0c0ab3f2;
P_0c0ab3f2: /* original f312, guest PC 0x0c0ab3f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab3f2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'*');
goto P_0c0ab3f4;
P_0c0ab3f4: /* original f53c, guest PC 0x0c0ab3f4 */
if(!s->budget--) { s->failed_pc=0x0c0ab3f4u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0ab3f6;
P_0c0ab3f6: /* original f522, guest PC 0x0c0ab3f6 */
if(!s->budget--) { s->failed_pc=0x0c0ab3f6u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'*');
goto P_0c0ab3f8;
P_0c0ab3f8: /* original f3e6, guest PC 0x0c0ab3f8 */
if(!s->budget--) { s->failed_pc=0x0c0ab3f8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab3fa;
P_0c0ab3fa: /* original 9040, guest PC 0x0c0ab3fa */
if(!s->budget--) { s->failed_pc=0x0c0ab3fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab47eu,2);
goto P_0c0ab3fc;
P_0c0ab3fc: /* original f1e6, guest PC 0x0c0ab3fc */
if(!s->budget--) { s->failed_pc=0x0c0ab3fcu; return 0; }
vf3_matrix_load(s,ram,1,r[14]+r[0]);
goto P_0c0ab3fe;
P_0c0ab3fe: /* original 903f, guest PC 0x0c0ab3fe */
if(!s->budget--) { s->failed_pc=0x0c0ab3feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab480u,2);
goto P_0c0ab400;
P_0c0ab400: /* original f130, guest PC 0x0c0ab400 */
if(!s->budget--) { s->failed_pc=0x0c0ab400u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'+');
goto P_0c0ab402;
P_0c0ab402: /* original f3e6, guest PC 0x0c0ab402 */
if(!s->budget--) { s->failed_pc=0x0c0ab402u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab404;
P_0c0ab404: /* original e028, guest PC 0x0c0ab404 */
if(!s->budget--) { s->failed_pc=0x0c0ab404u; return 0; }
r[0]=0x00000028u;
goto P_0c0ab406;
P_0c0ab406: /* original f131, guest PC 0x0c0ab406 */
if(!s->budget--) { s->failed_pc=0x0c0ab406u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'-');
goto P_0c0ab408;
P_0c0ab408: /* original f143, guest PC 0x0c0ab408 */
if(!s->budget--) { s->failed_pc=0x0c0ab408u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'/');
goto P_0c0ab40a;
P_0c0ab40a: /* original f510, guest PC 0x0c0ab40a */
if(!s->budget--) { s->failed_pc=0x0c0ab40au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[1],r[18],'+');
goto P_0c0ab40c;
P_0c0ab40c: /* original fe57, guest PC 0x0c0ab40c */
if(!s->budget--) { s->failed_pc=0x0c0ab40cu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0ab40e;
P_0c0ab40e: /* original d326, guest PC 0x0c0ab40e */
if(!s->budget--) { s->failed_pc=0x0c0ab40eu; return 0; }
r[3]=read(ram,0x0c0ab4a8u,4);
goto P_0c0ab410;
P_0c0ab410: /* original 62d2, guest PC 0x0c0ab410 */
if(!s->budget--) { s->failed_pc=0x0c0ab410u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ab412;
P_0c0ab412: /* original dc24, guest PC 0x0c0ab412 */
if(!s->budget--) { s->failed_pc=0x0c0ab412u; return 0; }
r[12]=read(ram,0x0c0ab4a4u,4);
goto P_0c0ab414;
P_0c0ab414: /* original da22, guest PC 0x0c0ab414 */
if(!s->budget--) { s->failed_pc=0x0c0ab414u; return 0; }
r[10]=read(ram,0x0c0ab4a0u,4);
goto P_0c0ab416;
P_0c0ab416: /* original 2238, guest PC 0x0c0ab416 */
if(!s->budget--) { s->failed_pc=0x0c0ab416u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab418;
P_0c0ab418: /* original 8b51, guest PC 0x0c0ab418 */
if(!s->budget--) { s->failed_pc=0x0c0ab418u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab4be; }
goto P_0c0ab41a;
P_0c0ab41a: /* original 9032, guest PC 0x0c0ab41a */
if(!s->budget--) { s->failed_pc=0x0c0ab41au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab482u,2);
goto P_0c0ab41c;
P_0c0ab41c: /* original f28d, guest PC 0x0c0ab41c */
if(!s->budget--) { s->failed_pc=0x0c0ab41cu; return 0; }
fr[2]=0;
goto P_0c0ab41e;
P_0c0ab41e: /* original ffe6, guest PC 0x0c0ab41e */
if(!s->budget--) { s->failed_pc=0x0c0ab41eu; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0ab420;
P_0c0ab420: /* original c722, guest PC 0x0c0ab420 */
if(!s->budget--) { s->failed_pc=0x0c0ab420u; return 0; }
r[0]=code_base|0x000ab4acu;
goto P_0c0ab422;
P_0c0ab422: /* original f308, guest PC 0x0c0ab422 */
if(!s->budget--) { s->failed_pc=0x0c0ab422u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0ab424;
P_0c0ab424: /* original ff24, guest PC 0x0c0ab424 */
if(!s->budget--) { s->failed_pc=0x0c0ab424u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])==as_float(fr[2]))!=0);
goto P_0c0ab426;
P_0c0ab426: /* original f54c, guest PC 0x0c0ab426 */
if(!s->budget--) { s->failed_pc=0x0c0ab426u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0ab428;
P_0c0ab428: /* original 8d0d, guest PC 0x0c0ab428 */
if(!s->budget--) { s->failed_pc=0x0c0ab428u; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
if(cond) { goto P_0c0ab446; }
goto P_0c0ab42c;
P_0c0ab42a: /* original f532, guest PC 0x0c0ab42a */
if(!s->budget--) { s->failed_pc=0x0c0ab42au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0ab42c;
P_0c0ab42c: /* original f38d, guest PC 0x0c0ab42c */
if(!s->budget--) { s->failed_pc=0x0c0ab42cu; return 0; }
fr[3]=0;
goto P_0c0ab42e;
P_0c0ab42e: /* original f3f5, guest PC 0x0c0ab42e */
if(!s->budget--) { s->failed_pc=0x0c0ab42eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0ab430;
P_0c0ab430: /* original 9028, guest PC 0x0c0ab430 */
if(!s->budget--) { s->failed_pc=0x0c0ab430u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab484u,2);
goto P_0c0ab432;
P_0c0ab432: /* original 8d02, guest PC 0x0c0ab432 */
if(!s->budget--) { s->failed_pc=0x0c0ab432u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,6,r[14]+r[0]);
if(cond) { goto P_0c0ab43a; }
goto P_0c0ab436;
P_0c0ab434: /* original f6e6, guest PC 0x0c0ab434 */
if(!s->budget--) { s->failed_pc=0x0c0ab434u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0ab436;
P_0c0ab436: /* original 9026, guest PC 0x0c0ab436 */
if(!s->budget--) { s->failed_pc=0x0c0ab436u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab486u,2);
goto P_0c0ab438;
P_0c0ab438: /* original f6e6, guest PC 0x0c0ab438 */
if(!s->budget--) { s->failed_pc=0x0c0ab438u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0ab43a;
P_0c0ab43a: /* original c71d, guest PC 0x0c0ab43a */
if(!s->budget--) { s->failed_pc=0x0c0ab43au; return 0; }
r[0]=code_base|0x000ab4b0u;
goto P_0c0ab43c;
P_0c0ab43c: /* original f308, guest PC 0x0c0ab43c */
if(!s->budget--) { s->failed_pc=0x0c0ab43cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0ab43e;
P_0c0ab43e: /* original f630, guest PC 0x0c0ab43e */
if(!s->budget--) { s->failed_pc=0x0c0ab43eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'+');
goto P_0c0ab440;
P_0c0ab440: /* original f565, guest PC 0x0c0ab440 */
if(!s->budget--) { s->failed_pc=0x0c0ab440u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[6]))!=0);
goto P_0c0ab442;
P_0c0ab442: /* original 8b00, guest PC 0x0c0ab442 */
if(!s->budget--) { s->failed_pc=0x0c0ab442u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab446; }
goto P_0c0ab444;
P_0c0ab444: /* original f56c, guest PC 0x0c0ab444 */
if(!s->budget--) { s->failed_pc=0x0c0ab444u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c0ab446;
P_0c0ab446: /* original f543, guest PC 0x0c0ab446 */
if(!s->budget--) { s->failed_pc=0x0c0ab446u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'/');
goto P_0c0ab448;
P_0c0ab448: /* original 85ef, guest PC 0x0c0ab448 */
if(!s->budget--) { s->failed_pc=0x0c0ab448u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0ab44a;
P_0c0ab44a: /* original 640f, guest PC 0x0c0ab44a */
if(!s->budget--) { s->failed_pc=0x0c0ab44au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0ab44c;
P_0c0ab44c: /* original 1f06, guest PC 0x0c0ab44c */
if(!s->budget--) { s->failed_pc=0x0c0ab44cu; return 0; }
write(ram,r[15]+24,r[0],4);
goto P_0c0ab44e;
P_0c0ab44e: /* original ff52, guest PC 0x0c0ab44e */
if(!s->budget--) { s->failed_pc=0x0c0ab44eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[5],r[18],'*');
goto P_0c0ab450;
P_0c0ab450: /* original 4a0b, guest PC 0x0c0ab450 */
if(!s->budget--) { s->failed_pc=0x0c0ab450u; return 0; }
target=r[10];
r[16]=code_base|0x0c0ab454u;
write(ram,r[15]+28,r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab454u) { target=s->pc; goto dispatch; }
goto P_0c0ab454;
P_0c0ab452: /* original 1f47, guest PC 0x0c0ab452 */
if(!s->budget--) { s->failed_pc=0x0c0ab452u; return 0; }
write(ram,r[15]+28,r[4],4);
goto P_0c0ab454;
P_0c0ab454: /* original e020, guest PC 0x0c0ab454 */
if(!s->budget--) { s->failed_pc=0x0c0ab454u; return 0; }
r[0]=0x00000020u;
goto P_0c0ab456;
P_0c0ab456: /* original ff0a, guest PC 0x0c0ab456 */
if(!s->budget--) { s->failed_pc=0x0c0ab456u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0ab458;
P_0c0ab458: /* original f2fc, guest PC 0x0c0ab458 */
if(!s->budget--) { s->failed_pc=0x0c0ab458u; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c0ab45a;
P_0c0ab45a: /* original f30c, guest PC 0x0c0ab45a */
if(!s->budget--) { s->failed_pc=0x0c0ab45au; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0ab45c;
P_0c0ab45c: /* original f232, guest PC 0x0c0ab45c */
if(!s->budget--) { s->failed_pc=0x0c0ab45cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0ab45e;
P_0c0ab45e: /* original f24d, guest PC 0x0c0ab45e */
if(!s->budget--) { s->failed_pc=0x0c0ab45eu; return 0; }
fr[2]^=0x80000000u;
goto P_0c0ab460;
P_0c0ab460: /* original ff27, guest PC 0x0c0ab460 */
if(!s->budget--) { s->failed_pc=0x0c0ab460u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0ab462;
P_0c0ab462: /* original 4c0b, guest PC 0x0c0ab462 */
if(!s->budget--) { s->failed_pc=0x0c0ab462u; return 0; }
target=r[12];
r[16]=code_base|0x0c0ab466u;
r[4]=read(ram,r[15]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab466u) { target=s->pc; goto dispatch; }
goto P_0c0ab466;
P_0c0ab464: /* original 54f7, guest PC 0x0c0ab464 */
if(!s->budget--) { s->failed_pc=0x0c0ab464u; return 0; }
r[4]=read(ram,r[15]+28,4);
goto P_0c0ab466;
P_0c0ab466: /* original ff02, guest PC 0x0c0ab466 */
if(!s->budget--) { s->failed_pc=0x0c0ab466u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[0],r[18],'*');
goto P_0c0ab468;
P_0c0ab468: /* original e020, guest PC 0x0c0ab468 */
if(!s->budget--) { s->failed_pc=0x0c0ab468u; return 0; }
r[0]=0x00000020u;
goto P_0c0ab46a;
P_0c0ab46a: /* original ff0a, guest PC 0x0c0ab46a */
if(!s->budget--) { s->failed_pc=0x0c0ab46au; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0ab46c;
P_0c0ab46c: /* original f3f6, guest PC 0x0c0ab46c */
if(!s->budget--) { s->failed_pc=0x0c0ab46cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab46e;
P_0c0ab46e: /* original f4fc, guest PC 0x0c0ab46e */
if(!s->budget--) { s->failed_pc=0x0c0ab46eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0ab470;
P_0c0ab470: /* original f44d, guest PC 0x0c0ab470 */
if(!s->budget--) { s->failed_pc=0x0c0ab470u; return 0; }
fr[4]^=0x80000000u;
goto P_0c0ab472;
P_0c0ab472: /* original a01f, guest PC 0x0c0ab472 */
if(!s->budget--) { s->failed_pc=0x0c0ab472u; return 0; }
goto P_0c0ab4b4;
P_0c0ab474: /* original 0009, guest PC 0x0c0ab474 */
if(!s->budget--) { s->failed_pc=0x0c0ab474u; return 0; }
if(!vf3_matrix_family(0x0c0ab476u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ab476u; return 0; } return 1;
P_0c0ab4b4: /* original e024, guest PC 0x0c0ab4b4 */
if(!s->budget--) { s->failed_pc=0x0c0ab4b4u; return 0; }
r[0]=0x00000024u;
goto P_0c0ab4b6;
P_0c0ab4b6: /* original fe37, guest PC 0x0c0ab4b6 */
if(!s->budget--) { s->failed_pc=0x0c0ab4b6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab4b8;
P_0c0ab4b8: /* original e02c, guest PC 0x0c0ab4b8 */
if(!s->budget--) { s->failed_pc=0x0c0ab4b8u; return 0; }
r[0]=0x0000002cu;
goto P_0c0ab4ba;
P_0c0ab4ba: /* original a0fd, guest PC 0x0c0ab4ba */
if(!s->budget--) { s->failed_pc=0x0c0ab4bau; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab6b8;
P_0c0ab4bc: /* original fe47, guest PC 0x0c0ab4bc */
if(!s->budget--) { s->failed_pc=0x0c0ab4bcu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab4be;
P_0c0ab4be: /* original 9080, guest PC 0x0c0ab4be */
if(!s->budget--) { s->failed_pc=0x0c0ab4beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab5c2u,2);
goto P_0c0ab4c0;
P_0c0ab4c0: /* original 62b2, guest PC 0x0c0ab4c0 */
if(!s->budget--) { s->failed_pc=0x0c0ab4c0u; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c0ab4c2;
P_0c0ab4c2: /* original d342, guest PC 0x0c0ab4c2 */
if(!s->budget--) { s->failed_pc=0x0c0ab4c2u; return 0; }
r[3]=read(ram,0x0c0ab5ccu,4);
goto P_0c0ab4c4;
P_0c0ab4c4: /* original fee6, guest PC 0x0c0ab4c4 */
if(!s->budget--) { s->failed_pc=0x0c0ab4c4u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c0ab4c6;
P_0c0ab4c6: /* original 7008, guest PC 0x0c0ab4c6 */
if(!s->budget--) { s->failed_pc=0x0c0ab4c6u; return 0; }
r[0]+=0x00000008u;
goto P_0c0ab4c8;
P_0c0ab4c8: /* original 2238, guest PC 0x0c0ab4c8 */
if(!s->budget--) { s->failed_pc=0x0c0ab4c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab4ca;
P_0c0ab4ca: /* original 8f07, guest PC 0x0c0ab4ca */
if(!s->budget--) { s->failed_pc=0x0c0ab4cau; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,15,r[14]+r[0]);
if(!cond) { goto P_0c0ab4dc; }
goto P_0c0ab4ce;
P_0c0ab4cc: /* original ffe6, guest PC 0x0c0ab4cc */
if(!s->budget--) { s->failed_pc=0x0c0ab4ccu; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0ab4ce;
P_0c0ab4ce: /* original 9079, guest PC 0x0c0ab4ce */
if(!s->budget--) { s->failed_pc=0x0c0ab4ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab5c4u,2);
goto P_0c0ab4d0;
P_0c0ab4d0: /* original 00bc, guest PC 0x0c0ab4d0 */
if(!s->budget--) { s->failed_pc=0x0c0ab4d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0ab4d2;
P_0c0ab4d2: /* original 600c, guest PC 0x0c0ab4d2 */
if(!s->budget--) { s->failed_pc=0x0c0ab4d2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ab4d4;
P_0c0ab4d4: /* original c840, guest PC 0x0c0ab4d4 */
if(!s->budget--) { s->failed_pc=0x0c0ab4d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c0ab4d6;
P_0c0ab4d6: /* original 8b01, guest PC 0x0c0ab4d6 */
if(!s->budget--) { s->failed_pc=0x0c0ab4d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab4dc; }
goto P_0c0ab4d8;
P_0c0ab4d8: /* original a084, guest PC 0x0c0ab4d8 */
if(!s->budget--) { s->failed_pc=0x0c0ab4d8u; return 0; }
goto P_0c0ab5e4;
P_0c0ab4da: /* original 0009, guest PC 0x0c0ab4da */
if(!s->budget--) { s->failed_pc=0x0c0ab4dau; return 0; }
goto P_0c0ab4dc;
P_0c0ab4dc: /* original 50f7, guest PC 0x0c0ab4dc */
if(!s->budget--) { s->failed_pc=0x0c0ab4dcu; return 0; }
r[0]=read(ram,r[15]+28,4);
goto P_0c0ab4de;
P_0c0ab4de: /* original e11c, guest PC 0x0c0ab4de */
if(!s->budget--) { s->failed_pc=0x0c0ab4deu; return 0; }
r[1]=0x0000001cu;
goto P_0c0ab4e0;
P_0c0ab4e0: /* original 001c, guest PC 0x0c0ab4e0 */
if(!s->budget--) { s->failed_pc=0x0c0ab4e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0ab4e2;
P_0c0ab4e2: /* original 600c, guest PC 0x0c0ab4e2 */
if(!s->budget--) { s->failed_pc=0x0c0ab4e2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ab4e4;
P_0c0ab4e4: /* original c90f, guest PC 0x0c0ab4e4 */
if(!s->budget--) { s->failed_pc=0x0c0ab4e4u; return 0; }
r[0]&=15u;
goto P_0c0ab4e6;
P_0c0ab4e6: /* original 880f, guest PC 0x0c0ab4e6 */
if(!s->budget--) { s->failed_pc=0x0c0ab4e6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c0ab4e8;
P_0c0ab4e8: /* original 8b31, guest PC 0x0c0ab4e8 */
if(!s->budget--) { s->failed_pc=0x0c0ab4e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab54e; }
goto P_0c0ab4ea;
P_0c0ab4ea: /* original e06a, guest PC 0x0c0ab4ea */
if(!s->budget--) { s->failed_pc=0x0c0ab4eau; return 0; }
r[0]=0x0000006au;
goto P_0c0ab4ec;
P_0c0ab4ec: /* original 03ed, guest PC 0x0c0ab4ec */
if(!s->budget--) { s->failed_pc=0x0c0ab4ecu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab4ee;
P_0c0ab4ee: /* original 1f32, guest PC 0x0c0ab4ee */
if(!s->budget--) { s->failed_pc=0x0c0ab4eeu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0ab4f0;
P_0c0ab4f0: /* original 4a0b, guest PC 0x0c0ab4f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab4f0u; return 0; }
target=r[10];
r[16]=code_base|0x0c0ab4f4u;
r[4]=(uint32_t)(int32_t)(int16_t)r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab4f4u) { target=s->pc; goto dispatch; }
goto P_0c0ab4f4;
P_0c0ab4f2: /* original 643f, guest PC 0x0c0ab4f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab4f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c0ab4f4;
P_0c0ab4f4: /* original ff0a, guest PC 0x0c0ab4f4 */
if(!s->budget--) { s->failed_pc=0x0c0ab4f4u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0ab4f6;
P_0c0ab4f6: /* original 54f2, guest PC 0x0c0ab4f6 */
if(!s->budget--) { s->failed_pc=0x0c0ab4f6u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0ab4f8;
P_0c0ab4f8: /* original 4c0b, guest PC 0x0c0ab4f8 */
if(!s->budget--) { s->failed_pc=0x0c0ab4f8u; return 0; }
target=r[12];
r[16]=code_base|0x0c0ab4fcu;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab4fcu) { target=s->pc; goto dispatch; }
goto P_0c0ab4fc;
P_0c0ab4fa: /* original 644f, guest PC 0x0c0ab4fa */
if(!s->budget--) { s->failed_pc=0x0c0ab4fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0ab4fc;
P_0c0ab4fc: /* original e004, guest PC 0x0c0ab4fc */
if(!s->budget--) { s->failed_pc=0x0c0ab4fcu; return 0; }
r[0]=0x00000004u;
goto P_0c0ab4fe;
P_0c0ab4fe: /* original ff07, guest PC 0x0c0ab4fe */
if(!s->budget--) { s->failed_pc=0x0c0ab4feu; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0ab500;
P_0c0ab500: /* original e050, guest PC 0x0c0ab500 */
if(!s->budget--) { s->failed_pc=0x0c0ab500u; return 0; }
r[0]=0x00000050u;
goto P_0c0ab502;
P_0c0ab502: /* original 02ee, guest PC 0x0c0ab502 */
if(!s->budget--) { s->failed_pc=0x0c0ab502u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ab504;
P_0c0ab504: /* original d332, guest PC 0x0c0ab504 */
if(!s->budget--) { s->failed_pc=0x0c0ab504u; return 0; }
r[3]=read(ram,0x0c0ab5d0u,4);
goto P_0c0ab506;
P_0c0ab506: /* original 2238, guest PC 0x0c0ab506 */
if(!s->budget--) { s->failed_pc=0x0c0ab506u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab508;
P_0c0ab508: /* original 8902, guest PC 0x0c0ab508 */
if(!s->budget--) { s->failed_pc=0x0c0ab508u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab510; }
goto P_0c0ab50a;
P_0c0ab50a: /* original 905c, guest PC 0x0c0ab50a */
if(!s->budget--) { s->failed_pc=0x0c0ab50au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab5c6u,2);
goto P_0c0ab50c;
P_0c0ab50c: /* original a001, guest PC 0x0c0ab50c */
if(!s->budget--) { s->failed_pc=0x0c0ab50cu; return 0; }
goto P_0c0ab512;
P_0c0ab50e: /* original 0009, guest PC 0x0c0ab50e */
if(!s->budget--) { s->failed_pc=0x0c0ab50eu; return 0; }
goto P_0c0ab510;
P_0c0ab510: /* original 905a, guest PC 0x0c0ab510 */
if(!s->budget--) { s->failed_pc=0x0c0ab510u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab5c8u,2);
goto P_0c0ab512;
P_0c0ab512: /* original f3e6, guest PC 0x0c0ab512 */
if(!s->budget--) { s->failed_pc=0x0c0ab512u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab514;
P_0c0ab514: /* original e00c, guest PC 0x0c0ab514 */
if(!s->budget--) { s->failed_pc=0x0c0ab514u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab516;
P_0c0ab516: /* original ff37, guest PC 0x0c0ab516 */
if(!s->budget--) { s->failed_pc=0x0c0ab516u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab518;
P_0c0ab518: /* original c72e, guest PC 0x0c0ab518 */
if(!s->budget--) { s->failed_pc=0x0c0ab518u; return 0; }
r[0]=code_base|0x000ab5d4u;
goto P_0c0ab51a;
P_0c0ab51a: /* original f308, guest PC 0x0c0ab51a */
if(!s->budget--) { s->failed_pc=0x0c0ab51au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0ab51c;
P_0c0ab51c: /* original e00c, guest PC 0x0c0ab51c */
if(!s->budget--) { s->failed_pc=0x0c0ab51cu; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab51e;
P_0c0ab51e: /* original f2f6, guest PC 0x0c0ab51e */
if(!s->budget--) { s->failed_pc=0x0c0ab51eu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0ab520;
P_0c0ab520: /* original e00c, guest PC 0x0c0ab520 */
if(!s->budget--) { s->failed_pc=0x0c0ab520u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab522;
P_0c0ab522: /* original f231, guest PC 0x0c0ab522 */
if(!s->budget--) { s->failed_pc=0x0c0ab522u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0ab524;
P_0c0ab524: /* original ff27, guest PC 0x0c0ab524 */
if(!s->budget--) { s->failed_pc=0x0c0ab524u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0ab526;
P_0c0ab526: /* original e00c, guest PC 0x0c0ab526 */
if(!s->budget--) { s->failed_pc=0x0c0ab526u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab528;
P_0c0ab528: /* original f1f8, guest PC 0x0c0ab528 */
if(!s->budget--) { s->failed_pc=0x0c0ab528u; return 0; }
vf3_matrix_load(s,ram,1,r[15]);
goto P_0c0ab52a;
P_0c0ab52a: /* original f122, guest PC 0x0c0ab52a */
if(!s->budget--) { s->failed_pc=0x0c0ab52au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c0ab52c;
P_0c0ab52c: /* original ff1a, guest PC 0x0c0ab52c */
if(!s->budget--) { s->failed_pc=0x0c0ab52cu; return 0; }
vf3_matrix_store(s,ram,1,r[15]);
goto P_0c0ab52e;
P_0c0ab52e: /* original f2f6, guest PC 0x0c0ab52e */
if(!s->budget--) { s->failed_pc=0x0c0ab52eu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0ab530;
P_0c0ab530: /* original e004, guest PC 0x0c0ab530 */
if(!s->budget--) { s->failed_pc=0x0c0ab530u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab532;
P_0c0ab532: /* original f1f6, guest PC 0x0c0ab532 */
if(!s->budget--) { s->failed_pc=0x0c0ab532u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0ab534;
P_0c0ab534: /* original e004, guest PC 0x0c0ab534 */
if(!s->budget--) { s->failed_pc=0x0c0ab534u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab536;
P_0c0ab536: /* original f122, guest PC 0x0c0ab536 */
if(!s->budget--) { s->failed_pc=0x0c0ab536u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c0ab538;
P_0c0ab538: /* original ff17, guest PC 0x0c0ab538 */
if(!s->budget--) { s->failed_pc=0x0c0ab538u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0ab53a;
P_0c0ab53a: /* original e014, guest PC 0x0c0ab53a */
if(!s->budget--) { s->failed_pc=0x0c0ab53au; return 0; }
r[0]=0x00000014u;
goto P_0c0ab53c;
P_0c0ab53c: /* original f3f8, guest PC 0x0c0ab53c */
if(!s->budget--) { s->failed_pc=0x0c0ab53cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0ab53e;
P_0c0ab53e: /* original f0ec, guest PC 0x0c0ab53e */
if(!s->budget--) { s->failed_pc=0x0c0ab53eu; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c0ab540;
P_0c0ab540: /* original f031, guest PC 0x0c0ab540 */
if(!s->budget--) { s->failed_pc=0x0c0ab540u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0ab542;
P_0c0ab542: /* original ff07, guest PC 0x0c0ab542 */
if(!s->budget--) { s->failed_pc=0x0c0ab542u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0ab544;
P_0c0ab544: /* original e004, guest PC 0x0c0ab544 */
if(!s->budget--) { s->failed_pc=0x0c0ab544u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab546;
P_0c0ab546: /* original f2f6, guest PC 0x0c0ab546 */
if(!s->budget--) { s->failed_pc=0x0c0ab546u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0ab548;
P_0c0ab548: /* original fcfc, guest PC 0x0c0ab548 */
if(!s->budget--) { s->failed_pc=0x0c0ab548u; return 0; }
vf3_matrix_move(s,12,15);
goto P_0c0ab54a;
P_0c0ab54a: /* original a07c, guest PC 0x0c0ab54a */
if(!s->budget--) { s->failed_pc=0x0c0ab54au; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[2],r[18],'-');
goto P_0c0ab646;
P_0c0ab54c: /* original fc21, guest PC 0x0c0ab54c */
if(!s->budget--) { s->failed_pc=0x0c0ab54cu; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[2],r[18],'-');
goto P_0c0ab54e;
P_0c0ab54e: /* original 9038, guest PC 0x0c0ab54e */
if(!s->budget--) { s->failed_pc=0x0c0ab54eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab5c2u,2);
goto P_0c0ab550;
P_0c0ab550: /* original 63f3, guest PC 0x0c0ab550 */
if(!s->budget--) { s->failed_pc=0x0c0ab550u; return 0; }
r[3]=r[15];
goto P_0c0ab552;
P_0c0ab552: /* original 7310, guest PC 0x0c0ab552 */
if(!s->budget--) { s->failed_pc=0x0c0ab552u; return 0; }
r[3]+=0x00000010u;
goto P_0c0ab554;
P_0c0ab554: /* original f4ec, guest PC 0x0c0ab554 */
if(!s->budget--) { s->failed_pc=0x0c0ab554u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0ab556;
P_0c0ab556: /* original f6b6, guest PC 0x0c0ab556 */
if(!s->budget--) { s->failed_pc=0x0c0ab556u; return 0; }
vf3_matrix_load(s,ram,6,r[11]+r[0]);
goto P_0c0ab558;
P_0c0ab558: /* original 7008, guest PC 0x0c0ab558 */
if(!s->budget--) { s->failed_pc=0x0c0ab558u; return 0; }
r[0]+=0x00000008u;
goto P_0c0ab55a;
P_0c0ab55a: /* original f7b6, guest PC 0x0c0ab55a */
if(!s->budget--) { s->failed_pc=0x0c0ab55au; return 0; }
vf3_matrix_load(s,ram,7,r[11]+r[0]);
goto P_0c0ab55c;
P_0c0ab55c: /* original f5fc, guest PC 0x0c0ab55c */
if(!s->budget--) { s->failed_pc=0x0c0ab55cu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0ab55e;
P_0c0ab55e: /* original 2f36, guest PC 0x0c0ab55e */
if(!s->budget--) { s->failed_pc=0x0c0ab55eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ab560;
P_0c0ab560: /* original 67f3, guest PC 0x0c0ab560 */
if(!s->budget--) { s->failed_pc=0x0c0ab560u; return 0; }
r[7]=r[15];
goto P_0c0ab562;
P_0c0ab562: /* original 66f3, guest PC 0x0c0ab562 */
if(!s->budget--) { s->failed_pc=0x0c0ab562u; return 0; }
r[6]=r[15];
goto P_0c0ab564;
P_0c0ab564: /* original 65f3, guest PC 0x0c0ab564 */
if(!s->budget--) { s->failed_pc=0x0c0ab564u; return 0; }
r[5]=r[15];
goto P_0c0ab566;
P_0c0ab566: /* original d21c, guest PC 0x0c0ab566 */
if(!s->budget--) { s->failed_pc=0x0c0ab566u; return 0; }
r[2]=read(ram,0x0c0ab5d8u,4);
goto P_0c0ab568;
P_0c0ab568: /* original 64f3, guest PC 0x0c0ab568 */
if(!s->budget--) { s->failed_pc=0x0c0ab568u; return 0; }
r[4]=r[15];
goto P_0c0ab56a;
P_0c0ab56a: /* original 7508, guest PC 0x0c0ab56a */
if(!s->budget--) { s->failed_pc=0x0c0ab56au; return 0; }
r[5]+=0x00000008u;
goto P_0c0ab56c;
P_0c0ab56c: /* original 7610, guest PC 0x0c0ab56c */
if(!s->budget--) { s->failed_pc=0x0c0ab56cu; return 0; }
r[6]+=0x00000010u;
goto P_0c0ab56e;
P_0c0ab56e: /* original 770c, guest PC 0x0c0ab56e */
if(!s->budget--) { s->failed_pc=0x0c0ab56eu; return 0; }
r[7]+=0x0000000cu;
goto P_0c0ab570;
P_0c0ab570: /* original 420b, guest PC 0x0c0ab570 */
if(!s->budget--) { s->failed_pc=0x0c0ab570u; return 0; }
target=r[2];
r[16]=code_base|0x0c0ab574u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab574u) { target=s->pc; goto dispatch; }
goto P_0c0ab574;
P_0c0ab572: /* original 7404, guest PC 0x0c0ab572 */
if(!s->budget--) { s->failed_pc=0x0c0ab572u; return 0; }
r[4]+=0x00000004u;
goto P_0c0ab574;
P_0c0ab574: /* original 9025, guest PC 0x0c0ab574 */
if(!s->budget--) { s->failed_pc=0x0c0ab574u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab5c2u,2);
goto P_0c0ab576;
P_0c0ab576: /* original 7f04, guest PC 0x0c0ab576 */
if(!s->budget--) { s->failed_pc=0x0c0ab576u; return 0; }
r[15]+=0x00000004u;
goto P_0c0ab578;
P_0c0ab578: /* original f5f8, guest PC 0x0c0ab578 */
if(!s->budget--) { s->failed_pc=0x0c0ab578u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c0ab57a;
P_0c0ab57a: /* original fee6, guest PC 0x0c0ab57a */
if(!s->budget--) { s->failed_pc=0x0c0ab57au; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c0ab57c;
P_0c0ab57c: /* original 7008, guest PC 0x0c0ab57c */
if(!s->budget--) { s->failed_pc=0x0c0ab57cu; return 0; }
r[0]+=0x00000008u;
goto P_0c0ab57e;
P_0c0ab57e: /* original ffe6, guest PC 0x0c0ab57e */
if(!s->budget--) { s->failed_pc=0x0c0ab57eu; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0ab580;
P_0c0ab580: /* original e00c, guest PC 0x0c0ab580 */
if(!s->budget--) { s->failed_pc=0x0c0ab580u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab582;
P_0c0ab582: /* original f5e1, guest PC 0x0c0ab582 */
if(!s->budget--) { s->failed_pc=0x0c0ab582u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'-');
goto P_0c0ab584;
P_0c0ab584: /* original f4f6, guest PC 0x0c0ab584 */
if(!s->budget--) { s->failed_pc=0x0c0ab584u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0ab586;
P_0c0ab586: /* original e004, guest PC 0x0c0ab586 */
if(!s->budget--) { s->failed_pc=0x0c0ab586u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab588;
P_0c0ab588: /* original f4f1, guest PC 0x0c0ab588 */
if(!s->budget--) { s->failed_pc=0x0c0ab588u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
goto P_0c0ab58a;
P_0c0ab58a: /* original f35c, guest PC 0x0c0ab58a */
if(!s->budget--) { s->failed_pc=0x0c0ab58au; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0ab58c;
P_0c0ab58c: /* original f352, guest PC 0x0c0ab58c */
if(!s->budget--) { s->failed_pc=0x0c0ab58cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c0ab58e;
P_0c0ab58e: /* original f04c, guest PC 0x0c0ab58e */
if(!s->budget--) { s->failed_pc=0x0c0ab58eu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0ab590;
P_0c0ab590: /* original f34e, guest PC 0x0c0ab590 */
if(!s->budget--) { s->failed_pc=0x0c0ab590u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c0ab592;
P_0c0ab592: /* original ff37, guest PC 0x0c0ab592 */
if(!s->budget--) { s->failed_pc=0x0c0ab592u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab594;
P_0c0ab594: /* original c711, guest PC 0x0c0ab594 */
if(!s->budget--) { s->failed_pc=0x0c0ab594u; return 0; }
r[0]=code_base|0x000ab5dcu;
goto P_0c0ab596;
P_0c0ab596: /* original f208, guest PC 0x0c0ab596 */
if(!s->budget--) { s->failed_pc=0x0c0ab596u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0ab598;
P_0c0ab598: /* original f235, guest PC 0x0c0ab598 */
if(!s->budget--) { s->failed_pc=0x0c0ab598u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0ab59a;
P_0c0ab59a: /* original 8b01, guest PC 0x0c0ab59a */
if(!s->budget--) { s->failed_pc=0x0c0ab59au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab5a0; }
goto P_0c0ab59c;
P_0c0ab59c: /* original a001, guest PC 0x0c0ab59c */
if(!s->budget--) { s->failed_pc=0x0c0ab59cu; return 0; }
fr[3]=0;
goto P_0c0ab5a2;
P_0c0ab59e: /* original f38d, guest PC 0x0c0ab59e */
if(!s->budget--) { s->failed_pc=0x0c0ab59eu; return 0; }
fr[3]=0;
goto P_0c0ab5a0;
P_0c0ab5a0: /* original f37d, guest PC 0x0c0ab5a0 */
if(!s->budget--) { s->failed_pc=0x0c0ab5a0u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0ab5a2;
P_0c0ab5a2: /* original e004, guest PC 0x0c0ab5a2 */
if(!s->budget--) { s->failed_pc=0x0c0ab5a2u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab5a4;
P_0c0ab5a4: /* original f532, guest PC 0x0c0ab5a4 */
if(!s->budget--) { s->failed_pc=0x0c0ab5a4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0ab5a6;
P_0c0ab5a6: /* original ff37, guest PC 0x0c0ab5a6 */
if(!s->budget--) { s->failed_pc=0x0c0ab5a6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab5a8;
P_0c0ab5a8: /* original c70d, guest PC 0x0c0ab5a8 */
if(!s->budget--) { s->failed_pc=0x0c0ab5a8u; return 0; }
r[0]=code_base|0x000ab5e0u;
goto P_0c0ab5aa;
P_0c0ab5aa: /* original f608, guest PC 0x0c0ab5aa */
if(!s->budget--) { s->failed_pc=0x0c0ab5aau; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0ab5ac;
P_0c0ab5ac: /* original f432, guest PC 0x0c0ab5ac */
if(!s->budget--) { s->failed_pc=0x0c0ab5acu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0ab5ae;
P_0c0ab5ae: /* original f3f8, guest PC 0x0c0ab5ae */
if(!s->budget--) { s->failed_pc=0x0c0ab5aeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0ab5b0;
P_0c0ab5b0: /* original e014, guest PC 0x0c0ab5b0 */
if(!s->budget--) { s->failed_pc=0x0c0ab5b0u; return 0; }
r[0]=0x00000014u;
goto P_0c0ab5b2;
P_0c0ab5b2: /* original f562, guest PC 0x0c0ab5b2 */
if(!s->budget--) { s->failed_pc=0x0c0ab5b2u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c0ab5b4;
P_0c0ab5b4: /* original f462, guest PC 0x0c0ab5b4 */
if(!s->budget--) { s->failed_pc=0x0c0ab5b4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0ab5b6;
P_0c0ab5b6: /* original f351, guest PC 0x0c0ab5b6 */
if(!s->budget--) { s->failed_pc=0x0c0ab5b6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c0ab5b8;
P_0c0ab5b8: /* original ff37, guest PC 0x0c0ab5b8 */
if(!s->budget--) { s->failed_pc=0x0c0ab5b8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab5ba;
P_0c0ab5ba: /* original e00c, guest PC 0x0c0ab5ba */
if(!s->budget--) { s->failed_pc=0x0c0ab5bau; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab5bc;
P_0c0ab5bc: /* original fcf6, guest PC 0x0c0ab5bc */
if(!s->budget--) { s->failed_pc=0x0c0ab5bcu; return 0; }
vf3_matrix_load(s,ram,12,r[15]+r[0]);
goto P_0c0ab5be;
P_0c0ab5be: /* original a042, guest PC 0x0c0ab5be */
if(!s->budget--) { s->failed_pc=0x0c0ab5beu; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'-');
goto P_0c0ab646;
P_0c0ab5c0: /* original fc41, guest PC 0x0c0ab5c0 */
if(!s->budget--) { s->failed_pc=0x0c0ab5c0u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'-');
if(!vf3_matrix_family(0x0c0ab5c2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ab5c2u; return 0; } return 1;
P_0c0ab5e4: /* original 9086, guest PC 0x0c0ab5e4 */
if(!s->budget--) { s->failed_pc=0x0c0ab5e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab6f4u,2);
goto P_0c0ab5e6;
P_0c0ab5e6: /* original f3e6, guest PC 0x0c0ab5e6 */
if(!s->budget--) { s->failed_pc=0x0c0ab5e6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab5e8;
P_0c0ab5e8: /* original e014, guest PC 0x0c0ab5e8 */
if(!s->budget--) { s->failed_pc=0x0c0ab5e8u; return 0; }
r[0]=0x00000014u;
goto P_0c0ab5ea;
P_0c0ab5ea: /* original ff37, guest PC 0x0c0ab5ea */
if(!s->budget--) { s->failed_pc=0x0c0ab5eau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab5ec;
P_0c0ab5ec: /* original 9083, guest PC 0x0c0ab5ec */
if(!s->budget--) { s->failed_pc=0x0c0ab5ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab6f6u,2);
goto P_0c0ab5ee;
P_0c0ab5ee: /* original f38d, guest PC 0x0c0ab5ee */
if(!s->budget--) { s->failed_pc=0x0c0ab5eeu; return 0; }
fr[3]=0;
goto P_0c0ab5f0;
P_0c0ab5f0: /* original fce6, guest PC 0x0c0ab5f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab5f0u; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c0ab5f2;
P_0c0ab5f2: /* original 70f0, guest PC 0x0c0ab5f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab5f2u; return 0; }
r[0]+=0xfffffff0u;
goto P_0c0ab5f4;
P_0c0ab5f4: /* original f2e6, guest PC 0x0c0ab5f4 */
if(!s->budget--) { s->failed_pc=0x0c0ab5f4u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0ab5f6;
P_0c0ab5f6: /* original f234, guest PC 0x0c0ab5f6 */
if(!s->budget--) { s->failed_pc=0x0c0ab5f6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])==as_float(fr[3]))!=0);
goto P_0c0ab5f8;
P_0c0ab5f8: /* original 892b, guest PC 0x0c0ab5f8 */
if(!s->budget--) { s->failed_pc=0x0c0ab5f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab652; }
goto P_0c0ab5fa;
P_0c0ab5fa: /* original f5cc, guest PC 0x0c0ab5fa */
if(!s->budget--) { s->failed_pc=0x0c0ab5fau; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c0ab5fc;
P_0c0ab5fc: /* original f5f1, guest PC 0x0c0ab5fc */
if(!s->budget--) { s->failed_pc=0x0c0ab5fcu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[15],r[18],'-');
goto P_0c0ab5fe;
P_0c0ab5fe: /* original e014, guest PC 0x0c0ab5fe */
if(!s->budget--) { s->failed_pc=0x0c0ab5feu; return 0; }
r[0]=0x00000014u;
goto P_0c0ab600;
P_0c0ab600: /* original d33f, guest PC 0x0c0ab600 */
if(!s->budget--) { s->failed_pc=0x0c0ab600u; return 0; }
r[3]=read(ram,0x0c0ab700u,4);
goto P_0c0ab602;
P_0c0ab602: /* original f4f6, guest PC 0x0c0ab602 */
if(!s->budget--) { s->failed_pc=0x0c0ab602u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0ab604;
P_0c0ab604: /* original 430b, guest PC 0x0c0ab604 */
if(!s->budget--) { s->failed_pc=0x0c0ab604u; return 0; }
target=r[3];
r[16]=code_base|0x0c0ab608u;
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab608u) { target=s->pc; goto dispatch; }
goto P_0c0ab608;
P_0c0ab606: /* original f4e1, guest PC 0x0c0ab606 */
if(!s->budget--) { s->failed_pc=0x0c0ab606u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'-');
goto P_0c0ab608;
P_0c0ab608: /* original 9376, guest PC 0x0c0ab608 */
if(!s->budget--) { s->failed_pc=0x0c0ab608u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab6f8u,2);
goto P_0c0ab60a;
P_0c0ab60a: /* original 600f, guest PC 0x0c0ab60a */
if(!s->budget--) { s->failed_pc=0x0c0ab60au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0ab60c;
P_0c0ab60c: /* original 6203, guest PC 0x0c0ab60c */
if(!s->budget--) { s->failed_pc=0x0c0ab60cu; return 0; }
r[2]=r[0];
goto P_0c0ab60e;
P_0c0ab60e: /* original 323c, guest PC 0x0c0ab60e */
if(!s->budget--) { s->failed_pc=0x0c0ab60eu; return 0; }
r[2]+=r[3];
goto P_0c0ab610;
P_0c0ab610: /* original 1f22, guest PC 0x0c0ab610 */
if(!s->budget--) { s->failed_pc=0x0c0ab610u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0ab612;
P_0c0ab612: /* original 4a0b, guest PC 0x0c0ab612 */
if(!s->budget--) { s->failed_pc=0x0c0ab612u; return 0; }
target=r[10];
r[16]=code_base|0x0c0ab616u;
r[4]=(uint32_t)(int32_t)(int16_t)r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab616u) { target=s->pc; goto dispatch; }
goto P_0c0ab616;
P_0c0ab614: /* original 642f, guest PC 0x0c0ab614 */
if(!s->budget--) { s->failed_pc=0x0c0ab614u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c0ab616;
P_0c0ab616: /* original ff0a, guest PC 0x0c0ab616 */
if(!s->budget--) { s->failed_pc=0x0c0ab616u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0ab618;
P_0c0ab618: /* original 54f2, guest PC 0x0c0ab618 */
if(!s->budget--) { s->failed_pc=0x0c0ab618u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0ab61a;
P_0c0ab61a: /* original 4c0b, guest PC 0x0c0ab61a */
if(!s->budget--) { s->failed_pc=0x0c0ab61au; return 0; }
target=r[12];
r[16]=code_base|0x0c0ab61eu;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab61eu) { target=s->pc; goto dispatch; }
goto P_0c0ab61e;
P_0c0ab61c: /* original 644f, guest PC 0x0c0ab61c */
if(!s->budget--) { s->failed_pc=0x0c0ab61cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0ab61e;
P_0c0ab61e: /* original e004, guest PC 0x0c0ab61e */
if(!s->budget--) { s->failed_pc=0x0c0ab61eu; return 0; }
r[0]=0x00000004u;
goto P_0c0ab620;
P_0c0ab620: /* original ff07, guest PC 0x0c0ab620 */
if(!s->budget--) { s->failed_pc=0x0c0ab620u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0ab622;
P_0c0ab622: /* original 906a, guest PC 0x0c0ab622 */
if(!s->budget--) { s->failed_pc=0x0c0ab622u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab6fau,2);
goto P_0c0ab624;
P_0c0ab624: /* original f3e6, guest PC 0x0c0ab624 */
if(!s->budget--) { s->failed_pc=0x0c0ab624u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab626;
P_0c0ab626: /* original e00c, guest PC 0x0c0ab626 */
if(!s->budget--) { s->failed_pc=0x0c0ab626u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab628;
P_0c0ab628: /* original ff37, guest PC 0x0c0ab628 */
if(!s->budget--) { s->failed_pc=0x0c0ab628u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab62a;
P_0c0ab62a: /* original e014, guest PC 0x0c0ab62a */
if(!s->budget--) { s->failed_pc=0x0c0ab62au; return 0; }
r[0]=0x00000014u;
goto P_0c0ab62c;
P_0c0ab62c: /* original f3f6, guest PC 0x0c0ab62c */
if(!s->budget--) { s->failed_pc=0x0c0ab62cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab62e;
P_0c0ab62e: /* original e00c, guest PC 0x0c0ab62e */
if(!s->budget--) { s->failed_pc=0x0c0ab62eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab630;
P_0c0ab630: /* original f0f6, guest PC 0x0c0ab630 */
if(!s->budget--) { s->failed_pc=0x0c0ab630u; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c0ab632;
P_0c0ab632: /* original e004, guest PC 0x0c0ab632 */
if(!s->budget--) { s->failed_pc=0x0c0ab632u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab634;
P_0c0ab634: /* original f2f6, guest PC 0x0c0ab634 */
if(!s->budget--) { s->failed_pc=0x0c0ab634u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0ab636;
P_0c0ab636: /* original e014, guest PC 0x0c0ab636 */
if(!s->budget--) { s->failed_pc=0x0c0ab636u; return 0; }
r[0]=0x00000014u;
goto P_0c0ab638;
P_0c0ab638: /* original f32e, guest PC 0x0c0ab638 */
if(!s->budget--) { s->failed_pc=0x0c0ab638u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0ab63a;
P_0c0ab63a: /* original ff37, guest PC 0x0c0ab63a */
if(!s->budget--) { s->failed_pc=0x0c0ab63au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab63c;
P_0c0ab63c: /* original e00c, guest PC 0x0c0ab63c */
if(!s->budget--) { s->failed_pc=0x0c0ab63cu; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab63e;
P_0c0ab63e: /* original f1f8, guest PC 0x0c0ab63e */
if(!s->budget--) { s->failed_pc=0x0c0ab63eu; return 0; }
vf3_matrix_load(s,ram,1,r[15]);
goto P_0c0ab640;
P_0c0ab640: /* original f2f6, guest PC 0x0c0ab640 */
if(!s->budget--) { s->failed_pc=0x0c0ab640u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0ab642;
P_0c0ab642: /* original f122, guest PC 0x0c0ab642 */
if(!s->budget--) { s->failed_pc=0x0c0ab642u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c0ab644;
P_0c0ab644: /* original fc11, guest PC 0x0c0ab644 */
if(!s->budget--) { s->failed_pc=0x0c0ab644u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[1],r[18],'-');
goto P_0c0ab646;
P_0c0ab646: /* original e014, guest PC 0x0c0ab646 */
if(!s->budget--) { s->failed_pc=0x0c0ab646u; return 0; }
r[0]=0x00000014u;
goto P_0c0ab648;
P_0c0ab648: /* original f3f6, guest PC 0x0c0ab648 */
if(!s->budget--) { s->failed_pc=0x0c0ab648u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab64a;
P_0c0ab64a: /* original 9053, guest PC 0x0c0ab64a */
if(!s->budget--) { s->failed_pc=0x0c0ab64au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab6f4u,2);
goto P_0c0ab64c;
P_0c0ab64c: /* original fe37, guest PC 0x0c0ab64c */
if(!s->budget--) { s->failed_pc=0x0c0ab64cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab64e;
P_0c0ab64e: /* original 7008, guest PC 0x0c0ab64e */
if(!s->budget--) { s->failed_pc=0x0c0ab64eu; return 0; }
r[0]+=0x00000008u;
goto P_0c0ab650;
P_0c0ab650: /* original fec7, guest PC 0x0c0ab650 */
if(!s->budget--) { s->failed_pc=0x0c0ab650u; return 0; }
vf3_matrix_store(s,ram,12,r[14]+r[0]);
goto P_0c0ab652;
P_0c0ab652: /* original e014, guest PC 0x0c0ab652 */
if(!s->budget--) { s->failed_pc=0x0c0ab652u; return 0; }
r[0]=0x00000014u;
goto P_0c0ab654;
P_0c0ab654: /* original f3f6, guest PC 0x0c0ab654 */
if(!s->budget--) { s->failed_pc=0x0c0ab654u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab656;
P_0c0ab656: /* original e00c, guest PC 0x0c0ab656 */
if(!s->budget--) { s->failed_pc=0x0c0ab656u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab658;
P_0c0ab658: /* original f3e1, guest PC 0x0c0ab658 */
if(!s->budget--) { s->failed_pc=0x0c0ab658u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'-');
goto P_0c0ab65a;
P_0c0ab65a: /* original ff37, guest PC 0x0c0ab65a */
if(!s->budget--) { s->failed_pc=0x0c0ab65au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab65c;
P_0c0ab65c: /* original f332, guest PC 0x0c0ab65c */
if(!s->budget--) { s->failed_pc=0x0c0ab65cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[3],r[18],'*');
goto P_0c0ab65e;
P_0c0ab65e: /* original f4cc, guest PC 0x0c0ab65e */
if(!s->budget--) { s->failed_pc=0x0c0ab65eu; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c0ab660;
P_0c0ab660: /* original f4f1, guest PC 0x0c0ab660 */
if(!s->budget--) { s->failed_pc=0x0c0ab660u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
goto P_0c0ab662;
P_0c0ab662: /* original f04c, guest PC 0x0c0ab662 */
if(!s->budget--) { s->failed_pc=0x0c0ab662u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0ab664;
P_0c0ab664: /* original f34e, guest PC 0x0c0ab664 */
if(!s->budget--) { s->failed_pc=0x0c0ab664u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c0ab666;
P_0c0ab666: /* original ff3a, guest PC 0x0c0ab666 */
if(!s->budget--) { s->failed_pc=0x0c0ab666u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0ab668;
P_0c0ab668: /* original 9048, guest PC 0x0c0ab668 */
if(!s->budget--) { s->failed_pc=0x0c0ab668u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab6fcu,2);
goto P_0c0ab66a;
P_0c0ab66a: /* original f5e6, guest PC 0x0c0ab66a */
if(!s->budget--) { s->failed_pc=0x0c0ab66au; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0ab66c;
P_0c0ab66c: /* original e004, guest PC 0x0c0ab66c */
if(!s->budget--) { s->failed_pc=0x0c0ab66cu; return 0; }
r[0]=0x00000004u;
goto P_0c0ab66e;
P_0c0ab66e: /* original f35c, guest PC 0x0c0ab66e */
if(!s->budget--) { s->failed_pc=0x0c0ab66eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0ab670;
P_0c0ab670: /* original f352, guest PC 0x0c0ab670 */
if(!s->budget--) { s->failed_pc=0x0c0ab670u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c0ab672;
P_0c0ab672: /* original ff37, guest PC 0x0c0ab672 */
if(!s->budget--) { s->failed_pc=0x0c0ab672u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab674;
P_0c0ab674: /* original f2f8, guest PC 0x0c0ab674 */
if(!s->budget--) { s->failed_pc=0x0c0ab674u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0ab676;
P_0c0ab676: /* original f235, guest PC 0x0c0ab676 */
if(!s->budget--) { s->failed_pc=0x0c0ab676u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0ab678;
P_0c0ab678: /* original 8b1e, guest PC 0x0c0ab678 */
if(!s->budget--) { s->failed_pc=0x0c0ab678u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab6b8; }
goto P_0c0ab67a;
P_0c0ab67a: /* original c722, guest PC 0x0c0ab67a */
if(!s->budget--) { s->failed_pc=0x0c0ab67au; return 0; }
r[0]=code_base|0x000ab704u;
goto P_0c0ab67c;
P_0c0ab67c: /* original f3f8, guest PC 0x0c0ab67c */
if(!s->budget--) { s->failed_pc=0x0c0ab67cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0ab67e;
P_0c0ab67e: /* original f208, guest PC 0x0c0ab67e */
if(!s->budget--) { s->failed_pc=0x0c0ab67eu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0ab680;
P_0c0ab680: /* original f235, guest PC 0x0c0ab680 */
if(!s->budget--) { s->failed_pc=0x0c0ab680u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0ab682;
P_0c0ab682: /* original 8b01, guest PC 0x0c0ab682 */
if(!s->budget--) { s->failed_pc=0x0c0ab682u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab688; }
goto P_0c0ab684;
P_0c0ab684: /* original a001, guest PC 0x0c0ab684 */
if(!s->budget--) { s->failed_pc=0x0c0ab684u; return 0; }
fr[3]=0;
goto P_0c0ab68a;
P_0c0ab686: /* original f38d, guest PC 0x0c0ab686 */
if(!s->budget--) { s->failed_pc=0x0c0ab686u; return 0; }
fr[3]=0;
goto P_0c0ab688;
P_0c0ab688: /* original f37d, guest PC 0x0c0ab688 */
if(!s->budget--) { s->failed_pc=0x0c0ab688u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0ab68a;
P_0c0ab68a: /* original e004, guest PC 0x0c0ab68a */
if(!s->budget--) { s->failed_pc=0x0c0ab68au; return 0; }
r[0]=0x00000004u;
goto P_0c0ab68c;
P_0c0ab68c: /* original ff37, guest PC 0x0c0ab68c */
if(!s->budget--) { s->failed_pc=0x0c0ab68cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab68e;
P_0c0ab68e: /* original c71e, guest PC 0x0c0ab68e */
if(!s->budget--) { s->failed_pc=0x0c0ab68eu; return 0; }
r[0]=code_base|0x000ab708u;
goto P_0c0ab690;
P_0c0ab690: /* original f6f8, guest PC 0x0c0ab690 */
if(!s->budget--) { s->failed_pc=0x0c0ab690u; return 0; }
vf3_matrix_load(s,ram,6,r[15]);
goto P_0c0ab692;
P_0c0ab692: /* original f632, guest PC 0x0c0ab692 */
if(!s->budget--) { s->failed_pc=0x0c0ab692u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c0ab694;
P_0c0ab694: /* original f26c, guest PC 0x0c0ab694 */
if(!s->budget--) { s->failed_pc=0x0c0ab694u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c0ab696;
P_0c0ab696: /* original f6dc, guest PC 0x0c0ab696 */
if(!s->budget--) { s->failed_pc=0x0c0ab696u; return 0; }
vf3_matrix_move(s,6,13);
goto P_0c0ab698;
P_0c0ab698: /* original f623, guest PC 0x0c0ab698 */
if(!s->budget--) { s->failed_pc=0x0c0ab698u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'/');
goto P_0c0ab69a;
P_0c0ab69a: /* original f208, guest PC 0x0c0ab69a */
if(!s->budget--) { s->failed_pc=0x0c0ab69au; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0ab69c;
P_0c0ab69c: /* original e00c, guest PC 0x0c0ab69c */
if(!s->budget--) { s->failed_pc=0x0c0ab69cu; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab69e;
P_0c0ab69e: /* original f521, guest PC 0x0c0ab69e */
if(!s->budget--) { s->failed_pc=0x0c0ab69eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'-');
goto P_0c0ab6a0;
P_0c0ab6a0: /* original f562, guest PC 0x0c0ab6a0 */
if(!s->budget--) { s->failed_pc=0x0c0ab6a0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c0ab6a2;
P_0c0ab6a2: /* original ff5a, guest PC 0x0c0ab6a2 */
if(!s->budget--) { s->failed_pc=0x0c0ab6a2u; return 0; }
vf3_matrix_store(s,ram,5,r[15]);
goto P_0c0ab6a4;
P_0c0ab6a4: /* original f1f6, guest PC 0x0c0ab6a4 */
if(!s->budget--) { s->failed_pc=0x0c0ab6a4u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0ab6a6;
P_0c0ab6a6: /* original f05c, guest PC 0x0c0ab6a6 */
if(!s->budget--) { s->failed_pc=0x0c0ab6a6u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0ab6a8;
P_0c0ab6a8: /* original ff4e, guest PC 0x0c0ab6a8 */
if(!s->budget--) { s->failed_pc=0x0c0ab6a8u; return 0; }
fr[15]=vf3_fpu_mac(fr[0],fr[4],fr[15],r[18]);
goto P_0c0ab6aa;
P_0c0ab6aa: /* original fe1e, guest PC 0x0c0ab6aa */
if(!s->budget--) { s->failed_pc=0x0c0ab6aau; return 0; }
fr[14]=vf3_fpu_mac(fr[0],fr[1],fr[14],r[18]);
goto P_0c0ab6ac;
P_0c0ab6ac: /* original 9022, guest PC 0x0c0ab6ac */
if(!s->budget--) { s->failed_pc=0x0c0ab6acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab6f4u,2);
goto P_0c0ab6ae;
P_0c0ab6ae: /* original f4fc, guest PC 0x0c0ab6ae */
if(!s->budget--) { s->failed_pc=0x0c0ab6aeu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0ab6b0;
P_0c0ab6b0: /* original f5ec, guest PC 0x0c0ab6b0 */
if(!s->budget--) { s->failed_pc=0x0c0ab6b0u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0ab6b2;
P_0c0ab6b2: /* original fe57, guest PC 0x0c0ab6b2 */
if(!s->budget--) { s->failed_pc=0x0c0ab6b2u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0ab6b4;
P_0c0ab6b4: /* original 7008, guest PC 0x0c0ab6b4 */
if(!s->budget--) { s->failed_pc=0x0c0ab6b4u; return 0; }
r[0]+=0x00000008u;
goto P_0c0ab6b6;
P_0c0ab6b6: /* original fe47, guest PC 0x0c0ab6b6 */
if(!s->budget--) { s->failed_pc=0x0c0ab6b6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab6b8;
P_0c0ab6b8: /* original d314, guest PC 0x0c0ab6b8 */
if(!s->budget--) { s->failed_pc=0x0c0ab6b8u; return 0; }
r[3]=read(ram,0x0c0ab70cu,4);
goto P_0c0ab6ba;
P_0c0ab6ba: /* original 66e3, guest PC 0x0c0ab6ba */
if(!s->budget--) { s->failed_pc=0x0c0ab6bau; return 0; }
r[6]=r[14];
goto P_0c0ab6bc;
P_0c0ab6bc: /* original 65e3, guest PC 0x0c0ab6bc */
if(!s->budget--) { s->failed_pc=0x0c0ab6bcu; return 0; }
r[5]=r[14];
goto P_0c0ab6be;
P_0c0ab6be: /* original 7648, guest PC 0x0c0ab6be */
if(!s->budget--) { s->failed_pc=0x0c0ab6beu; return 0; }
r[6]+=0x00000048u;
goto P_0c0ab6c0;
P_0c0ab6c0: /* original 430b, guest PC 0x0c0ab6c0 */
if(!s->budget--) { s->failed_pc=0x0c0ab6c0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0ab6c4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab6c4u) { target=s->pc; goto dispatch; }
goto P_0c0ab6c4;
P_0c0ab6c2: /* original 64e3, guest PC 0x0c0ab6c2 */
if(!s->budget--) { s->failed_pc=0x0c0ab6c2u; return 0; }
r[4]=r[14];
goto P_0c0ab6c4;
P_0c0ab6c4: /* original 52d1, guest PC 0x0c0ab6c4 */
if(!s->budget--) { s->failed_pc=0x0c0ab6c4u; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0ab6c6;
P_0c0ab6c6: /* original e062, guest PC 0x0c0ab6c6 */
if(!s->budget--) { s->failed_pc=0x0c0ab6c6u; return 0; }
r[0]=0x00000062u;
goto P_0c0ab6c8;
P_0c0ab6c8: /* original 7201, guest PC 0x0c0ab6c8 */
if(!s->budget--) { s->failed_pc=0x0c0ab6c8u; return 0; }
r[2]+=0x00000001u;
goto P_0c0ab6ca;
P_0c0ab6ca: /* original 6323, guest PC 0x0c0ab6ca */
if(!s->budget--) { s->failed_pc=0x0c0ab6cau; return 0; }
r[3]=r[2];
goto P_0c0ab6cc;
P_0c0ab6cc: /* original 1d21, guest PC 0x0c0ab6cc */
if(!s->budget--) { s->failed_pc=0x0c0ab6ccu; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0ab6ce;
P_0c0ab6ce: /* original 0e34, guest PC 0x0c0ab6ce */
if(!s->budget--) { s->failed_pc=0x0c0ab6ceu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ab6d0;
P_0c0ab6d0: /* original e377, guest PC 0x0c0ab6d0 */
if(!s->budget--) { s->failed_pc=0x0c0ab6d0u; return 0; }
r[3]=0x00000077u;
goto P_0c0ab6d2;
P_0c0ab6d2: /* original 52ee, guest PC 0x0c0ab6d2 */
if(!s->budget--) { s->failed_pc=0x0c0ab6d2u; return 0; }
r[2]=read(ram,r[14]+56,4);
goto P_0c0ab6d4;
P_0c0ab6d4: /* original 1f24, guest PC 0x0c0ab6d4 */
if(!s->budget--) { s->failed_pc=0x0c0ab6d4u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0ab6d6;
P_0c0ab6d6: /* original 1f32, guest PC 0x0c0ab6d6 */
if(!s->budget--) { s->failed_pc=0x0c0ab6d6u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0ab6d8;
P_0c0ab6d8: /* original 52f4, guest PC 0x0c0ab6d8 */
if(!s->budget--) { s->failed_pc=0x0c0ab6d8u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0ab6da;
P_0c0ab6da: /* original d30d, guest PC 0x0c0ab6da */
if(!s->budget--) { s->failed_pc=0x0c0ab6dau; return 0; }
r[3]=read(ram,0x0c0ab710u,4);
goto P_0c0ab6dc;
P_0c0ab6dc: /* original 2238, guest PC 0x0c0ab6dc */
if(!s->budget--) { s->failed_pc=0x0c0ab6dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab6de;
P_0c0ab6de: /* original 8901, guest PC 0x0c0ab6de */
if(!s->budget--) { s->failed_pc=0x0c0ab6deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab6e4; }
goto P_0c0ab6e0;
P_0c0ab6e0: /* original e174, guest PC 0x0c0ab6e0 */
if(!s->budget--) { s->failed_pc=0x0c0ab6e0u; return 0; }
r[1]=0x00000074u;
goto P_0c0ab6e2;
P_0c0ab6e2: /* original 1f12, guest PC 0x0c0ab6e2 */
if(!s->budget--) { s->failed_pc=0x0c0ab6e2u; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c0ab6e4;
P_0c0ab6e4: /* original d30b, guest PC 0x0c0ab6e4 */
if(!s->budget--) { s->failed_pc=0x0c0ab6e4u; return 0; }
r[3]=read(ram,0x0c0ab714u,4);
goto P_0c0ab6e6;
P_0c0ab6e6: /* original 430b, guest PC 0x0c0ab6e6 */
if(!s->budget--) { s->failed_pc=0x0c0ab6e6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0ab6eau;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab6eau) { target=s->pc; goto dispatch; }
goto P_0c0ab6ea;
P_0c0ab6e8: /* original 54f2, guest PC 0x0c0ab6e8 */
if(!s->budget--) { s->failed_pc=0x0c0ab6e8u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0ab6ea;
P_0c0ab6ea: /* original d30b, guest PC 0x0c0ab6ea */
if(!s->budget--) { s->failed_pc=0x0c0ab6eau; return 0; }
r[3]=read(ram,0x0c0ab718u,4);
goto P_0c0ab6ec;
P_0c0ab6ec: /* original 430b, guest PC 0x0c0ab6ec */
if(!s->budget--) { s->failed_pc=0x0c0ab6ecu; return 0; }
target=r[3];
r[16]=code_base|0x0c0ab6f0u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab6f0u) { target=s->pc; goto dispatch; }
goto P_0c0ab6f0;
P_0c0ab6ee: /* original 54f2, guest PC 0x0c0ab6ee */
if(!s->budget--) { s->failed_pc=0x0c0ab6eeu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0ab6f0;
P_0c0ab6f0: /* original a09a, guest PC 0x0c0ab6f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab6f0u; return 0; }
goto P_0c0ab828;
P_0c0ab6f2: /* original 0009, guest PC 0x0c0ab6f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab6f2u; return 0; }
if(!vf3_matrix_family(0x0c0ab6f4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ab6f4u; return 0; } return 1;
P_0c0ab71c: /* original 62d2, guest PC 0x0c0ab71c */
if(!s->budget--) { s->failed_pc=0x0c0ab71cu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ab71e;
P_0c0ab71e: /* original d34c, guest PC 0x0c0ab71e */
if(!s->budget--) { s->failed_pc=0x0c0ab71eu; return 0; }
r[3]=read(ram,0x0c0ab850u,4);
goto P_0c0ab720;
P_0c0ab720: /* original 2238, guest PC 0x0c0ab720 */
if(!s->budget--) { s->failed_pc=0x0c0ab720u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab722;
P_0c0ab722: /* original 8916, guest PC 0x0c0ab722 */
if(!s->budget--) { s->failed_pc=0x0c0ab722u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab752; }
goto P_0c0ab724;
P_0c0ab724: /* original e064, guest PC 0x0c0ab724 */
if(!s->budget--) { s->failed_pc=0x0c0ab724u; return 0; }
r[0]=0x00000064u;
goto P_0c0ab726;
P_0c0ab726: /* original 01ed, guest PC 0x0c0ab726 */
if(!s->budget--) { s->failed_pc=0x0c0ab726u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab728;
P_0c0ab728: /* original 611d, guest PC 0x0c0ab728 */
if(!s->budget--) { s->failed_pc=0x0c0ab728u; return 0; }
r[1]=r[1]&65535u;
goto P_0c0ab72a;
P_0c0ab72a: /* original 1f12, guest PC 0x0c0ab72a */
if(!s->budget--) { s->failed_pc=0x0c0ab72au; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c0ab72c;
P_0c0ab72c: /* original 9088, guest PC 0x0c0ab72c */
if(!s->budget--) { s->failed_pc=0x0c0ab72cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab840u,2);
goto P_0c0ab72e;
P_0c0ab72e: /* original 03ed, guest PC 0x0c0ab72e */
if(!s->budget--) { s->failed_pc=0x0c0ab72eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab730;
P_0c0ab730: /* original 1f34, guest PC 0x0c0ab730 */
if(!s->budget--) { s->failed_pc=0x0c0ab730u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0ab732;
P_0c0ab732: /* original 52f2, guest PC 0x0c0ab732 */
if(!s->budget--) { s->failed_pc=0x0c0ab732u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0ab734;
P_0c0ab734: /* original 3236, guest PC 0x0c0ab734 */
if(!s->budget--) { s->failed_pc=0x0c0ab734u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[3])!=0);
goto P_0c0ab736;
P_0c0ab736: /* original 890c, guest PC 0x0c0ab736 */
if(!s->budget--) { s->failed_pc=0x0c0ab736u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab752; }
goto P_0c0ab738;
P_0c0ab738: /* original 63d2, guest PC 0x0c0ab738 */
if(!s->budget--) { s->failed_pc=0x0c0ab738u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ab73a;
P_0c0ab73a: /* original 633d, guest PC 0x0c0ab73a */
if(!s->budget--) { s->failed_pc=0x0c0ab73au; return 0; }
r[3]=r[3]&65535u;
goto P_0c0ab73c;
P_0c0ab73c: /* original 6533, guest PC 0x0c0ab73c */
if(!s->budget--) { s->failed_pc=0x0c0ab73cu; return 0; }
r[5]=r[3];
goto P_0c0ab73e;
P_0c0ab73e: /* original 1f34, guest PC 0x0c0ab73e */
if(!s->budget--) { s->failed_pc=0x0c0ab73eu; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0ab740;
P_0c0ab740: /* original d244, guest PC 0x0c0ab740 */
if(!s->budget--) { s->failed_pc=0x0c0ab740u; return 0; }
r[2]=read(ram,0x0c0ab854u,4);
goto P_0c0ab742;
P_0c0ab742: /* original 420b, guest PC 0x0c0ab742 */
if(!s->budget--) { s->failed_pc=0x0c0ab742u; return 0; }
target=r[2];
r[16]=code_base|0x0c0ab746u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab746u) { target=s->pc; goto dispatch; }
goto P_0c0ab746;
P_0c0ab744: /* original 64e3, guest PC 0x0c0ab744 */
if(!s->budget--) { s->failed_pc=0x0c0ab744u; return 0; }
r[4]=r[14];
goto P_0c0ab746;
P_0c0ab746: /* original 62d2, guest PC 0x0c0ab746 */
if(!s->budget--) { s->failed_pc=0x0c0ab746u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ab748;
P_0c0ab748: /* original d343, guest PC 0x0c0ab748 */
if(!s->budget--) { s->failed_pc=0x0c0ab748u; return 0; }
r[3]=read(ram,0x0c0ab858u,4);
goto P_0c0ab74a;
P_0c0ab74a: /* original 2239, guest PC 0x0c0ab74a */
if(!s->budget--) { s->failed_pc=0x0c0ab74au; return 0; }
r[2]&=r[3];
goto P_0c0ab74c;
P_0c0ab74c: /* original 6123, guest PC 0x0c0ab74c */
if(!s->budget--) { s->failed_pc=0x0c0ab74cu; return 0; }
r[1]=r[2];
goto P_0c0ab74e;
P_0c0ab74e: /* original 2d22, guest PC 0x0c0ab74e */
if(!s->budget--) { s->failed_pc=0x0c0ab74eu; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0ab750;
P_0c0ab750: /* original 1e2e, guest PC 0x0c0ab750 */
if(!s->budget--) { s->failed_pc=0x0c0ab750u; return 0; }
write(ram,r[14]+56,r[2],4);
goto P_0c0ab752;
P_0c0ab752: /* original 62d2, guest PC 0x0c0ab752 */
if(!s->budget--) { s->failed_pc=0x0c0ab752u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ab754;
P_0c0ab754: /* original d341, guest PC 0x0c0ab754 */
if(!s->budget--) { s->failed_pc=0x0c0ab754u; return 0; }
r[3]=read(ram,0x0c0ab85cu,4);
goto P_0c0ab756;
P_0c0ab756: /* original 2238, guest PC 0x0c0ab756 */
if(!s->budget--) { s->failed_pc=0x0c0ab756u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab758;
P_0c0ab758: /* original 893d, guest PC 0x0c0ab758 */
if(!s->budget--) { s->failed_pc=0x0c0ab758u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab7d6; }
goto P_0c0ab75a;
P_0c0ab75a: /* original e064, guest PC 0x0c0ab75a */
if(!s->budget--) { s->failed_pc=0x0c0ab75au; return 0; }
r[0]=0x00000064u;
goto P_0c0ab75c;
P_0c0ab75c: /* original 04ed, guest PC 0x0c0ab75c */
if(!s->budget--) { s->failed_pc=0x0c0ab75cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab75e;
P_0c0ab75e: /* original e30a, guest PC 0x0c0ab75e */
if(!s->budget--) { s->failed_pc=0x0c0ab75eu; return 0; }
r[3]=0x0000000au;
goto P_0c0ab760;
P_0c0ab760: /* original 644d, guest PC 0x0c0ab760 */
if(!s->budget--) { s->failed_pc=0x0c0ab760u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0ab762;
P_0c0ab762: /* original 3437, guest PC 0x0c0ab762 */
if(!s->budget--) { s->failed_pc=0x0c0ab762u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c0ab764;
P_0c0ab764: /* original 8b02, guest PC 0x0c0ab764 */
if(!s->budget--) { s->failed_pc=0x0c0ab764u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab76c; }
goto P_0c0ab766;
P_0c0ab766: /* original 956c, guest PC 0x0c0ab766 */
if(!s->budget--) { s->failed_pc=0x0c0ab766u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab842u,2);
goto P_0c0ab768;
P_0c0ab768: /* original a009, guest PC 0x0c0ab768 */
if(!s->budget--) { s->failed_pc=0x0c0ab768u; return 0; }
r[5]+=r[14];
goto P_0c0ab77e;
P_0c0ab76a: /* original 35ec, guest PC 0x0c0ab76a */
if(!s->budget--) { s->failed_pc=0x0c0ab76au; return 0; }
r[5]+=r[14];
goto P_0c0ab76c;
P_0c0ab76c: /* original 906b, guest PC 0x0c0ab76c */
if(!s->budget--) { s->failed_pc=0x0c0ab76cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab846u,2);
goto P_0c0ab76e;
P_0c0ab76e: /* original 9569, guest PC 0x0c0ab76e */
if(!s->budget--) { s->failed_pc=0x0c0ab76eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab844u,2);
goto P_0c0ab770;
P_0c0ab770: /* original 03ec, guest PC 0x0c0ab770 */
if(!s->budget--) { s->failed_pc=0x0c0ab770u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ab772;
P_0c0ab772: /* original 35ec, guest PC 0x0c0ab772 */
if(!s->budget--) { s->failed_pc=0x0c0ab772u; return 0; }
r[5]+=r[14];
goto P_0c0ab774;
P_0c0ab774: /* original 633c, guest PC 0x0c0ab774 */
if(!s->budget--) { s->failed_pc=0x0c0ab774u; return 0; }
r[3]=r[3]&255u;
goto P_0c0ab776;
P_0c0ab776: /* original 4308, guest PC 0x0c0ab776 */
if(!s->budget--) { s->failed_pc=0x0c0ab776u; return 0; }
r[3]<<=2;
goto P_0c0ab778;
P_0c0ab778: /* original 4308, guest PC 0x0c0ab778 */
if(!s->budget--) { s->failed_pc=0x0c0ab778u; return 0; }
r[3]<<=2;
goto P_0c0ab77a;
P_0c0ab77a: /* original 4308, guest PC 0x0c0ab77a */
if(!s->budget--) { s->failed_pc=0x0c0ab77au; return 0; }
r[3]<<=2;
goto P_0c0ab77c;
P_0c0ab77c: /* original 353c, guest PC 0x0c0ab77c */
if(!s->budget--) { s->failed_pc=0x0c0ab77cu; return 0; }
r[5]+=r[3];
goto P_0c0ab77e;
P_0c0ab77e: /* original e030, guest PC 0x0c0ab77e */
if(!s->budget--) { s->failed_pc=0x0c0ab77eu; return 0; }
r[0]=0x00000030u;
goto P_0c0ab780;
P_0c0ab780: /* original f656, guest PC 0x0c0ab780 */
if(!s->budget--) { s->failed_pc=0x0c0ab780u; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c0ab782;
P_0c0ab782: /* original e038, guest PC 0x0c0ab782 */
if(!s->budget--) { s->failed_pc=0x0c0ab782u; return 0; }
r[0]=0x00000038u;
goto P_0c0ab784;
P_0c0ab784: /* original f856, guest PC 0x0c0ab784 */
if(!s->budget--) { s->failed_pc=0x0c0ab784u; return 0; }
vf3_matrix_load(s,ram,8,r[5]+r[0]);
goto P_0c0ab786;
P_0c0ab786: /* original 2448, guest PC 0x0c0ab786 */
if(!s->budget--) { s->failed_pc=0x0c0ab786u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0ab788;
P_0c0ab788: /* original 905e, guest PC 0x0c0ab788 */
if(!s->budget--) { s->failed_pc=0x0c0ab788u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab848u,2);
goto P_0c0ab78a;
P_0c0ab78a: /* original f7e6, guest PC 0x0c0ab78a */
if(!s->budget--) { s->failed_pc=0x0c0ab78au; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0ab78c;
P_0c0ab78c: /* original 7008, guest PC 0x0c0ab78c */
if(!s->budget--) { s->failed_pc=0x0c0ab78cu; return 0; }
r[0]+=0x00000008u;
goto P_0c0ab78e;
P_0c0ab78e: /* original 8d22, guest PC 0x0c0ab78e */
if(!s->budget--) { s->failed_pc=0x0c0ab78eu; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,9,r[14]+r[0]);
if(cond) { goto P_0c0ab7d6; }
goto P_0c0ab792;
P_0c0ab790: /* original f9e6, guest PC 0x0c0ab790 */
if(!s->budget--) { s->failed_pc=0x0c0ab790u; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c0ab792;
P_0c0ab792: /* original 445a, guest PC 0x0c0ab792 */
if(!s->budget--) { s->failed_pc=0x0c0ab792u; return 0; }
r[53]=r[4];
goto P_0c0ab794;
P_0c0ab794: /* original e010, guest PC 0x0c0ab794 */
if(!s->budget--) { s->failed_pc=0x0c0ab794u; return 0; }
r[0]=0x00000010u;
goto P_0c0ab796;
P_0c0ab796: /* original f2e6, guest PC 0x0c0ab796 */
if(!s->budget--) { s->failed_pc=0x0c0ab796u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0ab798;
P_0c0ab798: /* original e00c, guest PC 0x0c0ab798 */
if(!s->budget--) { s->failed_pc=0x0c0ab798u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab79a;
P_0c0ab79a: /* original f981, guest PC 0x0c0ab79a */
if(!s->budget--) { s->failed_pc=0x0c0ab79au; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[8],r[18],'-');
goto P_0c0ab79c;
P_0c0ab79c: /* original f32d, guest PC 0x0c0ab79c */
if(!s->budget--) { s->failed_pc=0x0c0ab79cu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0ab79e;
P_0c0ab79e: /* original ff27, guest PC 0x0c0ab79e */
if(!s->budget--) { s->failed_pc=0x0c0ab79eu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0ab7a0;
P_0c0ab7a0: /* original f4dc, guest PC 0x0c0ab7a0 */
if(!s->budget--) { s->failed_pc=0x0c0ab7a0u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0ab7a2;
P_0c0ab7a2: /* original e018, guest PC 0x0c0ab7a2 */
if(!s->budget--) { s->failed_pc=0x0c0ab7a2u; return 0; }
r[0]=0x00000018u;
goto P_0c0ab7a4;
P_0c0ab7a4: /* original f5e6, guest PC 0x0c0ab7a4 */
if(!s->budget--) { s->failed_pc=0x0c0ab7a4u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0ab7a6;
P_0c0ab7a6: /* original e004, guest PC 0x0c0ab7a6 */
if(!s->budget--) { s->failed_pc=0x0c0ab7a6u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab7a8;
P_0c0ab7a8: /* original f761, guest PC 0x0c0ab7a8 */
if(!s->budget--) { s->failed_pc=0x0c0ab7a8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'-');
goto P_0c0ab7aa;
P_0c0ab7aa: /* original f433, guest PC 0x0c0ab7aa */
if(!s->budget--) { s->failed_pc=0x0c0ab7aau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c0ab7ac;
P_0c0ab7ac: /* original ff7a, guest PC 0x0c0ab7ac */
if(!s->budget--) { s->failed_pc=0x0c0ab7acu; return 0; }
vf3_matrix_store(s,ram,7,r[15]);
goto P_0c0ab7ae;
P_0c0ab7ae: /* original ff97, guest PC 0x0c0ab7ae */
if(!s->budget--) { s->failed_pc=0x0c0ab7aeu; return 0; }
vf3_matrix_store(s,ram,9,r[15]+r[0]);
goto P_0c0ab7b0;
P_0c0ab7b0: /* original e004, guest PC 0x0c0ab7b0 */
if(!s->budget--) { s->failed_pc=0x0c0ab7b0u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab7b2;
P_0c0ab7b2: /* original f3f8, guest PC 0x0c0ab7b2 */
if(!s->budget--) { s->failed_pc=0x0c0ab7b2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0ab7b4;
P_0c0ab7b4: /* original f342, guest PC 0x0c0ab7b4 */
if(!s->budget--) { s->failed_pc=0x0c0ab7b4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0ab7b6;
P_0c0ab7b6: /* original ff3a, guest PC 0x0c0ab7b6 */
if(!s->budget--) { s->failed_pc=0x0c0ab7b6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0ab7b8;
P_0c0ab7b8: /* original f2f6, guest PC 0x0c0ab7b8 */
if(!s->budget--) { s->failed_pc=0x0c0ab7b8u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0ab7ba;
P_0c0ab7ba: /* original e004, guest PC 0x0c0ab7ba */
if(!s->budget--) { s->failed_pc=0x0c0ab7bau; return 0; }
r[0]=0x00000004u;
goto P_0c0ab7bc;
P_0c0ab7bc: /* original f242, guest PC 0x0c0ab7bc */
if(!s->budget--) { s->failed_pc=0x0c0ab7bcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c0ab7be;
P_0c0ab7be: /* original ff27, guest PC 0x0c0ab7be */
if(!s->budget--) { s->failed_pc=0x0c0ab7beu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0ab7c0;
P_0c0ab7c0: /* original e00c, guest PC 0x0c0ab7c0 */
if(!s->budget--) { s->failed_pc=0x0c0ab7c0u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab7c2;
P_0c0ab7c2: /* original f1f6, guest PC 0x0c0ab7c2 */
if(!s->budget--) { s->failed_pc=0x0c0ab7c2u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0ab7c4;
P_0c0ab7c4: /* original f520, guest PC 0x0c0ab7c4 */
if(!s->budget--) { s->failed_pc=0x0c0ab7c4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'+');
goto P_0c0ab7c6;
P_0c0ab7c6: /* original e00c, guest PC 0x0c0ab7c6 */
if(!s->budget--) { s->failed_pc=0x0c0ab7c6u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab7c8;
P_0c0ab7c8: /* original f130, guest PC 0x0c0ab7c8 */
if(!s->budget--) { s->failed_pc=0x0c0ab7c8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'+');
goto P_0c0ab7ca;
P_0c0ab7ca: /* original ff17, guest PC 0x0c0ab7ca */
if(!s->budget--) { s->failed_pc=0x0c0ab7cau; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0ab7cc;
P_0c0ab7cc: /* original e010, guest PC 0x0c0ab7cc */
if(!s->budget--) { s->failed_pc=0x0c0ab7ccu; return 0; }
r[0]=0x00000010u;
goto P_0c0ab7ce;
P_0c0ab7ce: /* original f31c, guest PC 0x0c0ab7ce */
if(!s->budget--) { s->failed_pc=0x0c0ab7ceu; return 0; }
vf3_matrix_move(s,3,1);
goto P_0c0ab7d0;
P_0c0ab7d0: /* original fe37, guest PC 0x0c0ab7d0 */
if(!s->budget--) { s->failed_pc=0x0c0ab7d0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab7d2;
P_0c0ab7d2: /* original e018, guest PC 0x0c0ab7d2 */
if(!s->budget--) { s->failed_pc=0x0c0ab7d2u; return 0; }
r[0]=0x00000018u;
goto P_0c0ab7d4;
P_0c0ab7d4: /* original fe57, guest PC 0x0c0ab7d4 */
if(!s->budget--) { s->failed_pc=0x0c0ab7d4u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0ab7d6;
P_0c0ab7d6: /* original 52f6, guest PC 0x0c0ab7d6 */
if(!s->budget--) { s->failed_pc=0x0c0ab7d6u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c0ab7d8;
P_0c0ab7d8: /* original d321, guest PC 0x0c0ab7d8 */
if(!s->budget--) { s->failed_pc=0x0c0ab7d8u; return 0; }
r[3]=read(ram,0x0c0ab860u,4);
goto P_0c0ab7da;
P_0c0ab7da: /* original 2238, guest PC 0x0c0ab7da */
if(!s->budget--) { s->failed_pc=0x0c0ab7dau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab7dc;
P_0c0ab7dc: /* original 8b24, guest PC 0x0c0ab7dc */
if(!s->budget--) { s->failed_pc=0x0c0ab7dcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab828; }
goto P_0c0ab7de;
P_0c0ab7de: /* original 51ee, guest PC 0x0c0ab7de */
if(!s->budget--) { s->failed_pc=0x0c0ab7deu; return 0; }
r[1]=read(ram,r[14]+56,4);
goto P_0c0ab7e0;
P_0c0ab7e0: /* original d320, guest PC 0x0c0ab7e0 */
if(!s->budget--) { s->failed_pc=0x0c0ab7e0u; return 0; }
r[3]=read(ram,0x0c0ab864u,4);
goto P_0c0ab7e2;
P_0c0ab7e2: /* original 2138, guest PC 0x0c0ab7e2 */
if(!s->budget--) { s->failed_pc=0x0c0ab7e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0ab7e4;
P_0c0ab7e4: /* original 8b02, guest PC 0x0c0ab7e4 */
if(!s->budget--) { s->failed_pc=0x0c0ab7e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab7ec; }
goto P_0c0ab7e6;
P_0c0ab7e6: /* original 65e3, guest PC 0x0c0ab7e6 */
if(!s->budget--) { s->failed_pc=0x0c0ab7e6u; return 0; }
r[5]=r[14];
goto P_0c0ab7e8;
P_0c0ab7e8: /* original a002, guest PC 0x0c0ab7e8 */
if(!s->budget--) { s->failed_pc=0x0c0ab7e8u; return 0; }
r[4]=0x00000001u;
goto P_0c0ab7f0;
P_0c0ab7ea: /* original e401, guest PC 0x0c0ab7ea */
if(!s->budget--) { s->failed_pc=0x0c0ab7eau; return 0; }
r[4]=0x00000001u;
goto P_0c0ab7ec;
P_0c0ab7ec: /* original e402, guest PC 0x0c0ab7ec */
if(!s->budget--) { s->failed_pc=0x0c0ab7ecu; return 0; }
r[4]=0x00000002u;
goto P_0c0ab7ee;
P_0c0ab7ee: /* original 65e3, guest PC 0x0c0ab7ee */
if(!s->budget--) { s->failed_pc=0x0c0ab7eeu; return 0; }
r[5]=r[14];
goto P_0c0ab7f0;
P_0c0ab7f0: /* original d31d, guest PC 0x0c0ab7f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab7f0u; return 0; }
r[3]=read(ram,0x0c0ab868u,4);
goto P_0c0ab7f2;
P_0c0ab7f2: /* original 430b, guest PC 0x0c0ab7f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab7f2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0ab7f6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab7f6u) { target=s->pc; goto dispatch; }
goto P_0c0ab7f6;
P_0c0ab7f4: /* original 0009, guest PC 0x0c0ab7f4 */
if(!s->budget--) { s->failed_pc=0x0c0ab7f4u; return 0; }
goto P_0c0ab7f6;
P_0c0ab7f6: /* original e024, guest PC 0x0c0ab7f6 */
if(!s->budget--) { s->failed_pc=0x0c0ab7f6u; return 0; }
r[0]=0x00000024u;
goto P_0c0ab7f8;
P_0c0ab7f8: /* original f48d, guest PC 0x0c0ab7f8 */
if(!s->budget--) { s->failed_pc=0x0c0ab7f8u; return 0; }
fr[4]=0;
goto P_0c0ab7fa;
P_0c0ab7fa: /* original fe47, guest PC 0x0c0ab7fa */
if(!s->budget--) { s->failed_pc=0x0c0ab7fau; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab7fc;
P_0c0ab7fc: /* original e028, guest PC 0x0c0ab7fc */
if(!s->budget--) { s->failed_pc=0x0c0ab7fcu; return 0; }
r[0]=0x00000028u;
goto P_0c0ab7fe;
P_0c0ab7fe: /* original fe47, guest PC 0x0c0ab7fe */
if(!s->budget--) { s->failed_pc=0x0c0ab7feu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab800;
P_0c0ab800: /* original e02c, guest PC 0x0c0ab800 */
if(!s->budget--) { s->failed_pc=0x0c0ab800u; return 0; }
r[0]=0x0000002cu;
goto P_0c0ab802;
P_0c0ab802: /* original fe47, guest PC 0x0c0ab802 */
if(!s->budget--) { s->failed_pc=0x0c0ab802u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab804;
P_0c0ab804: /* original e300, guest PC 0x0c0ab804 */
if(!s->budget--) { s->failed_pc=0x0c0ab804u; return 0; }
r[3]=0x00000000u;
goto P_0c0ab806;
P_0c0ab806: /* original 9020, guest PC 0x0c0ab806 */
if(!s->budget--) { s->failed_pc=0x0c0ab806u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab84au,2);
goto P_0c0ab808;
P_0c0ab808: /* original fe47, guest PC 0x0c0ab808 */
if(!s->budget--) { s->failed_pc=0x0c0ab808u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab80a;
P_0c0ab80a: /* original 7004, guest PC 0x0c0ab80a */
if(!s->budget--) { s->failed_pc=0x0c0ab80au; return 0; }
r[0]+=0x00000004u;
goto P_0c0ab80c;
P_0c0ab80c: /* original fe47, guest PC 0x0c0ab80c */
if(!s->budget--) { s->failed_pc=0x0c0ab80cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab80e;
P_0c0ab80e: /* original 7004, guest PC 0x0c0ab80e */
if(!s->budget--) { s->failed_pc=0x0c0ab80eu; return 0; }
r[0]+=0x00000004u;
goto P_0c0ab810;
P_0c0ab810: /* original fe47, guest PC 0x0c0ab810 */
if(!s->budget--) { s->failed_pc=0x0c0ab810u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab812;
P_0c0ab812: /* original e03e, guest PC 0x0c0ab812 */
if(!s->budget--) { s->failed_pc=0x0c0ab812u; return 0; }
r[0]=0x0000003eu;
goto P_0c0ab814;
P_0c0ab814: /* original 1e3e, guest PC 0x0c0ab814 */
if(!s->budget--) { s->failed_pc=0x0c0ab814u; return 0; }
write(ram,r[14]+56,r[3],4);
goto P_0c0ab816;
P_0c0ab816: /* original 02ed, guest PC 0x0c0ab816 */
if(!s->budget--) { s->failed_pc=0x0c0ab816u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab818;
P_0c0ab818: /* original 9018, guest PC 0x0c0ab818 */
if(!s->budget--) { s->failed_pc=0x0c0ab818u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab84cu,2);
goto P_0c0ab81a;
P_0c0ab81a: /* original 03ed, guest PC 0x0c0ab81a */
if(!s->budget--) { s->failed_pc=0x0c0ab81au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab81c;
P_0c0ab81c: /* original 3232, guest PC 0x0c0ab81c */
if(!s->budget--) { s->failed_pc=0x0c0ab81cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[3])!=0);
goto P_0c0ab81e;
P_0c0ab81e: /* original 8903, guest PC 0x0c0ab81e */
if(!s->budget--) { s->failed_pc=0x0c0ab81eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab828; }
goto P_0c0ab820;
P_0c0ab820: /* original d212, guest PC 0x0c0ab820 */
if(!s->budget--) { s->failed_pc=0x0c0ab820u; return 0; }
r[2]=read(ram,0x0c0ab86cu,4);
goto P_0c0ab822;
P_0c0ab822: /* original e048, guest PC 0x0c0ab822 */
if(!s->budget--) { s->failed_pc=0x0c0ab822u; return 0; }
r[0]=0x00000048u;
goto P_0c0ab824;
P_0c0ab824: /* original 2c2b, guest PC 0x0c0ab824 */
if(!s->budget--) { s->failed_pc=0x0c0ab824u; return 0; }
r[12]|=r[2];
goto P_0c0ab826;
P_0c0ab826: /* original 0ec6, guest PC 0x0c0ab826 */
if(!s->budget--) { s->failed_pc=0x0c0ab826u; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c0ab828;
P_0c0ab828: /* original 7f28, guest PC 0x0c0ab828 */
if(!s->budget--) { s->failed_pc=0x0c0ab828u; return 0; }
r[15]+=0x00000028u;
goto P_0c0ab82a;
P_0c0ab82a: /* original 4f26, guest PC 0x0c0ab82a */
if(!s->budget--) { s->failed_pc=0x0c0ab82au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ab82c;
P_0c0ab82c: /* original fcf9, guest PC 0x0c0ab82c */
if(!s->budget--) { s->failed_pc=0x0c0ab82cu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ab82e;
P_0c0ab82e: /* original fdf9, guest PC 0x0c0ab82e */
if(!s->budget--) { s->failed_pc=0x0c0ab82eu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ab830;
P_0c0ab830: /* original fef9, guest PC 0x0c0ab830 */
if(!s->budget--) { s->failed_pc=0x0c0ab830u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ab832;
P_0c0ab832: /* original fff9, guest PC 0x0c0ab832 */
if(!s->budget--) { s->failed_pc=0x0c0ab832u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ab834;
P_0c0ab834: /* original 6af6, guest PC 0x0c0ab834 */
if(!s->budget--) { s->failed_pc=0x0c0ab834u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0ab836;
P_0c0ab836: /* original 6bf6, guest PC 0x0c0ab836 */
if(!s->budget--) { s->failed_pc=0x0c0ab836u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ab838;
P_0c0ab838: /* original 6cf6, guest PC 0x0c0ab838 */
if(!s->budget--) { s->failed_pc=0x0c0ab838u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ab83a;
P_0c0ab83a: /* original 6df6, guest PC 0x0c0ab83a */
if(!s->budget--) { s->failed_pc=0x0c0ab83au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ab83c;
P_0c0ab83c: /* original 000b, guest PC 0x0c0ab83c */
if(!s->budget--) { s->failed_pc=0x0c0ab83cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ab83e: /* original 6ef6, guest PC 0x0c0ab83e */
if(!s->budget--) { s->failed_pc=0x0c0ab83eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ab840u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ab840u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
