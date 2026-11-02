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
int vf3_away_batch42_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07413eu: goto P_0c07413e;
case 0x0c074140u: goto P_0c074140;
case 0x0c074142u: goto P_0c074142;
case 0x0c074144u: goto P_0c074144;
case 0x0c074146u: goto P_0c074146;
case 0x0c074148u: goto P_0c074148;
case 0x0c07414au: goto P_0c07414a;
case 0x0c07414cu: goto P_0c07414c;
case 0x0c07414eu: goto P_0c07414e;
case 0x0c074150u: goto P_0c074150;
case 0x0c074152u: goto P_0c074152;
case 0x0c074154u: goto P_0c074154;
case 0x0c074156u: goto P_0c074156;
case 0x0c074158u: goto P_0c074158;
case 0x0c07415au: goto P_0c07415a;
case 0x0c07415cu: goto P_0c07415c;
case 0x0c07415eu: goto P_0c07415e;
case 0x0c074160u: goto P_0c074160;
case 0x0c074162u: goto P_0c074162;
case 0x0c074164u: goto P_0c074164;
case 0x0c074166u: goto P_0c074166;
case 0x0c074168u: goto P_0c074168;
case 0x0c07416au: goto P_0c07416a;
case 0x0c07416cu: goto P_0c07416c;
case 0x0c07416eu: goto P_0c07416e;
case 0x0c074170u: goto P_0c074170;
case 0x0c074172u: goto P_0c074172;
case 0x0c074174u: goto P_0c074174;
case 0x0c074176u: goto P_0c074176;
case 0x0c074178u: goto P_0c074178;
case 0x0c07417au: goto P_0c07417a;
case 0x0c07417cu: goto P_0c07417c;
case 0x0c07417eu: goto P_0c07417e;
case 0x0c074180u: goto P_0c074180;
case 0x0c074182u: goto P_0c074182;
case 0x0c074184u: goto P_0c074184;
case 0x0c074186u: goto P_0c074186;
case 0x0c074188u: goto P_0c074188;
case 0x0c07418au: goto P_0c07418a;
case 0x0c07418cu: goto P_0c07418c;
case 0x0c07418eu: goto P_0c07418e;
case 0x0c074190u: goto P_0c074190;
case 0x0c074192u: goto P_0c074192;
case 0x0c074194u: goto P_0c074194;
case 0x0c074196u: goto P_0c074196;
case 0x0c074198u: goto P_0c074198;
case 0x0c07419au: goto P_0c07419a;
case 0x0c07419cu: goto P_0c07419c;
case 0x0c07419eu: goto P_0c07419e;
case 0x0c0741a0u: goto P_0c0741a0;
case 0x0c0741a2u: goto P_0c0741a2;
case 0x0c0741a4u: goto P_0c0741a4;
case 0x0c0741a6u: goto P_0c0741a6;
case 0x0c0741a8u: goto P_0c0741a8;
case 0x0c0741aau: goto P_0c0741aa;
case 0x0c0741acu: goto P_0c0741ac;
case 0x0c0741aeu: goto P_0c0741ae;
case 0x0c0741b0u: goto P_0c0741b0;
case 0x0c0741b2u: goto P_0c0741b2;
case 0x0c0741b4u: goto P_0c0741b4;
case 0x0c0741b6u: goto P_0c0741b6;
case 0x0c0741b8u: goto P_0c0741b8;
case 0x0c0741bau: goto P_0c0741ba;
case 0x0c0741bcu: goto P_0c0741bc;
case 0x0c0741beu: goto P_0c0741be;
case 0x0c0741c0u: goto P_0c0741c0;
case 0x0c0741c2u: goto P_0c0741c2;
case 0x0c0741c4u: goto P_0c0741c4;
case 0x0c0741c6u: goto P_0c0741c6;
case 0x0c0741c8u: goto P_0c0741c8;
case 0x0c0741cau: goto P_0c0741ca;
case 0x0c0741ccu: goto P_0c0741cc;
case 0x0c0741ceu: goto P_0c0741ce;
case 0x0c0741d0u: goto P_0c0741d0;
case 0x0c0741d2u: goto P_0c0741d2;
case 0x0c0741d4u: goto P_0c0741d4;
case 0x0c0741d6u: goto P_0c0741d6;
case 0x0c0741d8u: goto P_0c0741d8;
case 0x0c0741dau: goto P_0c0741da;
case 0x0c0741dcu: goto P_0c0741dc;
case 0x0c0741deu: goto P_0c0741de;
case 0x0c0741e0u: goto P_0c0741e0;
case 0x0c0741e2u: goto P_0c0741e2;
case 0x0c0741e4u: goto P_0c0741e4;
case 0x0c0741e6u: goto P_0c0741e6;
case 0x0c0741e8u: goto P_0c0741e8;
case 0x0c0741eau: goto P_0c0741ea;
case 0x0c0741ecu: goto P_0c0741ec;
case 0x0c0741eeu: goto P_0c0741ee;
case 0x0c0741f0u: goto P_0c0741f0;
case 0x0c0741f2u: goto P_0c0741f2;
case 0x0c0741f4u: goto P_0c0741f4;
case 0x0c0741f6u: goto P_0c0741f6;
case 0x0c0741f8u: goto P_0c0741f8;
case 0x0c0741fau: goto P_0c0741fa;
case 0x0c0741fcu: goto P_0c0741fc;
case 0x0c0741feu: goto P_0c0741fe;
case 0x0c074200u: goto P_0c074200;
case 0x0c074202u: goto P_0c074202;
case 0x0c074204u: goto P_0c074204;
case 0x0c074206u: goto P_0c074206;
case 0x0c074208u: goto P_0c074208;
case 0x0c07420au: goto P_0c07420a;
case 0x0c07420cu: goto P_0c07420c;
case 0x0c07420eu: goto P_0c07420e;
case 0x0c074210u: goto P_0c074210;
case 0x0c074212u: goto P_0c074212;
case 0x0c074214u: goto P_0c074214;
case 0x0c074216u: goto P_0c074216;
case 0x0c074218u: goto P_0c074218;
case 0x0c07421au: goto P_0c07421a;
case 0x0c07421cu: goto P_0c07421c;
case 0x0c07421eu: goto P_0c07421e;
case 0x0c074220u: goto P_0c074220;
case 0x0c074222u: goto P_0c074222;
case 0x0c074224u: goto P_0c074224;
case 0x0c074226u: goto P_0c074226;
case 0x0c074228u: goto P_0c074228;
case 0x0c07422au: goto P_0c07422a;
case 0x0c07422cu: goto P_0c07422c;
case 0x0c07422eu: goto P_0c07422e;
case 0x0c074230u: goto P_0c074230;
case 0x0c074232u: goto P_0c074232;
case 0x0c074234u: goto P_0c074234;
case 0x0c074236u: goto P_0c074236;
case 0x0c074254u: goto P_0c074254;
case 0x0c074256u: goto P_0c074256;
case 0x0c074258u: goto P_0c074258;
case 0x0c07425au: goto P_0c07425a;
case 0x0c07425cu: goto P_0c07425c;
case 0x0c07425eu: goto P_0c07425e;
case 0x0c074260u: goto P_0c074260;
case 0x0c074262u: goto P_0c074262;
case 0x0c074264u: goto P_0c074264;
case 0x0c074266u: goto P_0c074266;
case 0x0c074268u: goto P_0c074268;
case 0x0c07426au: goto P_0c07426a;
case 0x0c07426cu: goto P_0c07426c;
case 0x0c07426eu: goto P_0c07426e;
case 0x0c074270u: goto P_0c074270;
case 0x0c074272u: goto P_0c074272;
case 0x0c074274u: goto P_0c074274;
case 0x0c074276u: goto P_0c074276;
case 0x0c074278u: goto P_0c074278;
case 0x0c07427au: goto P_0c07427a;
case 0x0c07427cu: goto P_0c07427c;
case 0x0c07427eu: goto P_0c07427e;
case 0x0c074280u: goto P_0c074280;
case 0x0c074282u: goto P_0c074282;
case 0x0c074284u: goto P_0c074284;
case 0x0c074286u: goto P_0c074286;
case 0x0c074288u: goto P_0c074288;
case 0x0c07428au: goto P_0c07428a;
case 0x0c07428cu: goto P_0c07428c;
case 0x0c07428eu: goto P_0c07428e;
case 0x0c074290u: goto P_0c074290;
case 0x0c074292u: goto P_0c074292;
case 0x0c074294u: goto P_0c074294;
case 0x0c074296u: goto P_0c074296;
case 0x0c074298u: goto P_0c074298;
case 0x0c07429au: goto P_0c07429a;
case 0x0c07429cu: goto P_0c07429c;
case 0x0c07429eu: goto P_0c07429e;
case 0x0c0742a0u: goto P_0c0742a0;
case 0x0c0742a2u: goto P_0c0742a2;
case 0x0c0742a4u: goto P_0c0742a4;
case 0x0c0742a6u: goto P_0c0742a6;
case 0x0c0742a8u: goto P_0c0742a8;
case 0x0c0742aau: goto P_0c0742aa;
case 0x0c0742acu: goto P_0c0742ac;
case 0x0c0742aeu: goto P_0c0742ae;
case 0x0c0742b0u: goto P_0c0742b0;
case 0x0c0742b2u: goto P_0c0742b2;
case 0x0c0742b4u: goto P_0c0742b4;
case 0x0c0742b6u: goto P_0c0742b6;
case 0x0c0742b8u: goto P_0c0742b8;
case 0x0c0742bau: goto P_0c0742ba;
case 0x0c0742bcu: goto P_0c0742bc;
case 0x0c0742beu: goto P_0c0742be;
case 0x0c0742c0u: goto P_0c0742c0;
case 0x0c0742c2u: goto P_0c0742c2;
case 0x0c0742c4u: goto P_0c0742c4;
case 0x0c0742c6u: goto P_0c0742c6;
case 0x0c0742c8u: goto P_0c0742c8;
case 0x0c0742cau: goto P_0c0742ca;
case 0x0c0742ccu: goto P_0c0742cc;
case 0x0c0742ceu: goto P_0c0742ce;
case 0x0c0742d0u: goto P_0c0742d0;
case 0x0c0742d2u: goto P_0c0742d2;
case 0x0c0742d4u: goto P_0c0742d4;
case 0x0c0742d6u: goto P_0c0742d6;
case 0x0c0742d8u: goto P_0c0742d8;
case 0x0c0742dau: goto P_0c0742da;
case 0x0c0742dcu: goto P_0c0742dc;
case 0x0c0742deu: goto P_0c0742de;
case 0x0c0742e0u: goto P_0c0742e0;
case 0x0c0742e2u: goto P_0c0742e2;
case 0x0c0742e4u: goto P_0c0742e4;
case 0x0c0742e6u: goto P_0c0742e6;
case 0x0c074300u: goto P_0c074300;
case 0x0c074302u: goto P_0c074302;
case 0x0c074304u: goto P_0c074304;
case 0x0c074306u: goto P_0c074306;
case 0x0c074308u: goto P_0c074308;
case 0x0c07430au: goto P_0c07430a;
case 0x0c07430cu: goto P_0c07430c;
case 0x0c07430eu: goto P_0c07430e;
case 0x0c074310u: goto P_0c074310;
case 0x0c074312u: goto P_0c074312;
case 0x0c074314u: goto P_0c074314;
case 0x0c074316u: goto P_0c074316;
case 0x0c074318u: goto P_0c074318;
case 0x0c07431au: goto P_0c07431a;
case 0x0c07431cu: goto P_0c07431c;
case 0x0c07431eu: goto P_0c07431e;
case 0x0c074320u: goto P_0c074320;
case 0x0c074322u: goto P_0c074322;
case 0x0c074324u: goto P_0c074324;
case 0x0c074326u: goto P_0c074326;
case 0x0c074328u: goto P_0c074328;
case 0x0c07432au: goto P_0c07432a;
case 0x0c07432cu: goto P_0c07432c;
case 0x0c07432eu: goto P_0c07432e;
case 0x0c074330u: goto P_0c074330;
case 0x0c074332u: goto P_0c074332;
case 0x0c074334u: goto P_0c074334;
case 0x0c074336u: goto P_0c074336;
case 0x0c074338u: goto P_0c074338;
case 0x0c07433au: goto P_0c07433a;
case 0x0c07433cu: goto P_0c07433c;
case 0x0c07433eu: goto P_0c07433e;
case 0x0c074340u: goto P_0c074340;
case 0x0c074342u: goto P_0c074342;
case 0x0c074344u: goto P_0c074344;
case 0x0c074346u: goto P_0c074346;
case 0x0c074348u: goto P_0c074348;
case 0x0c07434au: goto P_0c07434a;
case 0x0c07434cu: goto P_0c07434c;
case 0x0c07434eu: goto P_0c07434e;
case 0x0c074350u: goto P_0c074350;
case 0x0c074352u: goto P_0c074352;
case 0x0c074354u: goto P_0c074354;
case 0x0c074356u: goto P_0c074356;
case 0x0c074358u: goto P_0c074358;
case 0x0c07435au: goto P_0c07435a;
case 0x0c07435cu: goto P_0c07435c;
case 0x0c07435eu: goto P_0c07435e;
case 0x0c074360u: goto P_0c074360;
case 0x0c074362u: goto P_0c074362;
case 0x0c074364u: goto P_0c074364;
case 0x0c074366u: goto P_0c074366;
case 0x0c074368u: goto P_0c074368;
case 0x0c07436au: goto P_0c07436a;
case 0x0c07436cu: goto P_0c07436c;
case 0x0c07436eu: goto P_0c07436e;
case 0x0c074370u: goto P_0c074370;
case 0x0c074372u: goto P_0c074372;
case 0x0c074374u: goto P_0c074374;
case 0x0c074376u: goto P_0c074376;
case 0x0c074378u: goto P_0c074378;
case 0x0c07437au: goto P_0c07437a;
case 0x0c07437cu: goto P_0c07437c;
case 0x0c07437eu: goto P_0c07437e;
case 0x0c074380u: goto P_0c074380;
case 0x0c074382u: goto P_0c074382;
case 0x0c074384u: goto P_0c074384;
case 0x0c074386u: goto P_0c074386;
case 0x0c074388u: goto P_0c074388;
case 0x0c07438au: goto P_0c07438a;
case 0x0c07438cu: goto P_0c07438c;
case 0x0c07438eu: goto P_0c07438e;
case 0x0c074390u: goto P_0c074390;
case 0x0c074392u: goto P_0c074392;
case 0x0c074394u: goto P_0c074394;
case 0x0c074396u: goto P_0c074396;
case 0x0c074398u: goto P_0c074398;
case 0x0c07439au: goto P_0c07439a;
case 0x0c07439cu: goto P_0c07439c;
case 0x0c07439eu: goto P_0c07439e;
case 0x0c0743a0u: goto P_0c0743a0;
case 0x0c0743a2u: goto P_0c0743a2;
case 0x0c0743a4u: goto P_0c0743a4;
case 0x0c0743a6u: goto P_0c0743a6;
case 0x0c0743a8u: goto P_0c0743a8;
case 0x0c0743aau: goto P_0c0743aa;
case 0x0c0743acu: goto P_0c0743ac;
case 0x0c0743aeu: goto P_0c0743ae;
case 0x0c0743b0u: goto P_0c0743b0;
case 0x0c0743b2u: goto P_0c0743b2;
case 0x0c0743c8u: goto P_0c0743c8;
case 0x0c0743cau: goto P_0c0743ca;
case 0x0c0743ccu: goto P_0c0743cc;
case 0x0c0743ceu: goto P_0c0743ce;
case 0x0c0743d0u: goto P_0c0743d0;
case 0x0c0743d2u: goto P_0c0743d2;
case 0x0c0743d4u: goto P_0c0743d4;
case 0x0c0743d6u: goto P_0c0743d6;
case 0x0c0743d8u: goto P_0c0743d8;
case 0x0c0743dau: goto P_0c0743da;
case 0x0c0743dcu: goto P_0c0743dc;
case 0x0c0743deu: goto P_0c0743de;
case 0x0c0743e0u: goto P_0c0743e0;
case 0x0c0743e2u: goto P_0c0743e2;
case 0x0c0743e4u: goto P_0c0743e4;
case 0x0c0743e6u: goto P_0c0743e6;
case 0x0c0743e8u: goto P_0c0743e8;
case 0x0c0743eau: goto P_0c0743ea;
case 0x0c0743ecu: goto P_0c0743ec;
case 0x0c0743eeu: goto P_0c0743ee;
case 0x0c0743f0u: goto P_0c0743f0;
case 0x0c0743f2u: goto P_0c0743f2;
case 0x0c0743f4u: goto P_0c0743f4;
case 0x0c0743f6u: goto P_0c0743f6;
case 0x0c0743f8u: goto P_0c0743f8;
case 0x0c0743fau: goto P_0c0743fa;
case 0x0c0743fcu: goto P_0c0743fc;
case 0x0c0743feu: goto P_0c0743fe;
case 0x0c074400u: goto P_0c074400;
case 0x0c074402u: goto P_0c074402;
case 0x0c074404u: goto P_0c074404;
case 0x0c074406u: goto P_0c074406;
case 0x0c074408u: goto P_0c074408;
case 0x0c07440au: goto P_0c07440a;
case 0x0c07440cu: goto P_0c07440c;
case 0x0c07440eu: goto P_0c07440e;
case 0x0c074410u: goto P_0c074410;
case 0x0c074412u: goto P_0c074412;
case 0x0c074414u: goto P_0c074414;
case 0x0c074416u: goto P_0c074416;
case 0x0c074418u: goto P_0c074418;
case 0x0c07441au: goto P_0c07441a;
case 0x0c07441cu: goto P_0c07441c;
case 0x0c07441eu: goto P_0c07441e;
case 0x0c074420u: goto P_0c074420;
case 0x0c074422u: goto P_0c074422;
case 0x0c074424u: goto P_0c074424;
case 0x0c074426u: goto P_0c074426;
case 0x0c074428u: goto P_0c074428;
case 0x0c07442au: goto P_0c07442a;
case 0x0c07442cu: goto P_0c07442c;
case 0x0c07442eu: goto P_0c07442e;
case 0x0c074430u: goto P_0c074430;
case 0x0c074432u: goto P_0c074432;
case 0x0c074434u: goto P_0c074434;
case 0x0c074436u: goto P_0c074436;
case 0x0c074438u: goto P_0c074438;
case 0x0c07443au: goto P_0c07443a;
case 0x0c07443cu: goto P_0c07443c;
case 0x0c07443eu: goto P_0c07443e;
case 0x0c074440u: goto P_0c074440;
case 0x0c074442u: goto P_0c074442;
case 0x0c074444u: goto P_0c074444;
case 0x0c074446u: goto P_0c074446;
case 0x0c074448u: goto P_0c074448;
case 0x0c07444au: goto P_0c07444a;
case 0x0c07444cu: goto P_0c07444c;
case 0x0c07444eu: goto P_0c07444e;
case 0x0c074450u: goto P_0c074450;
case 0x0c074452u: goto P_0c074452;
case 0x0c074454u: goto P_0c074454;
case 0x0c074456u: goto P_0c074456;
case 0x0c074458u: goto P_0c074458;
case 0x0c07445au: goto P_0c07445a;
case 0x0c07445cu: goto P_0c07445c;
case 0x0c07445eu: goto P_0c07445e;
case 0x0c074460u: goto P_0c074460;
case 0x0c074462u: goto P_0c074462;
case 0x0c074464u: goto P_0c074464;
case 0x0c074466u: goto P_0c074466;
case 0x0c074468u: goto P_0c074468;
case 0x0c07446au: goto P_0c07446a;
case 0x0c07446cu: goto P_0c07446c;
case 0x0c07446eu: goto P_0c07446e;
case 0x0c074470u: goto P_0c074470;
case 0x0c074472u: goto P_0c074472;
case 0x0c074474u: goto P_0c074474;
case 0x0c074476u: goto P_0c074476;
case 0x0c074478u: goto P_0c074478;
case 0x0c07447au: goto P_0c07447a;
case 0x0c07447cu: goto P_0c07447c;
case 0x0c07447eu: goto P_0c07447e;
case 0x0c074480u: goto P_0c074480;
case 0x0c074482u: goto P_0c074482;
case 0x0c074484u: goto P_0c074484;
case 0x0c074486u: goto P_0c074486;
case 0x0c074488u: goto P_0c074488;
case 0x0c07448au: goto P_0c07448a;
case 0x0c07448cu: goto P_0c07448c;
case 0x0c07448eu: goto P_0c07448e;
case 0x0c074490u: goto P_0c074490;
case 0x0c074492u: goto P_0c074492;
case 0x0c074494u: goto P_0c074494;
case 0x0c074496u: goto P_0c074496;
case 0x0c074498u: goto P_0c074498;
case 0x0c07449au: goto P_0c07449a;
case 0x0c07449cu: goto P_0c07449c;
case 0x0c07449eu: goto P_0c07449e;
case 0x0c0744a0u: goto P_0c0744a0;
case 0x0c0744a2u: goto P_0c0744a2;
case 0x0c0744a4u: goto P_0c0744a4;
case 0x0c0744a6u: goto P_0c0744a6;
case 0x0c0744a8u: goto P_0c0744a8;
case 0x0c0744aau: goto P_0c0744aa;
case 0x0c0744acu: goto P_0c0744ac;
case 0x0c0744aeu: goto P_0c0744ae;
case 0x0c0744b0u: goto P_0c0744b0;
case 0x0c0744b2u: goto P_0c0744b2;
case 0x0c0744b4u: goto P_0c0744b4;
case 0x0c0744b6u: goto P_0c0744b6;
case 0x0c0744b8u: goto P_0c0744b8;
case 0x0c0744bau: goto P_0c0744ba;
case 0x0c0744bcu: goto P_0c0744bc;
case 0x0c0744beu: goto P_0c0744be;
case 0x0c0744c0u: goto P_0c0744c0;
case 0x0c0744c2u: goto P_0c0744c2;
case 0x0c0744c4u: goto P_0c0744c4;
case 0x0c0744c6u: goto P_0c0744c6;
case 0x0c0744c8u: goto P_0c0744c8;
case 0x0c0744cau: goto P_0c0744ca;
case 0x0c0744ccu: goto P_0c0744cc;
case 0x0c0744ceu: goto P_0c0744ce;
case 0x0c0744d0u: goto P_0c0744d0;
case 0x0c0744d2u: goto P_0c0744d2;
case 0x0c0744d4u: goto P_0c0744d4;
case 0x0c0744d6u: goto P_0c0744d6;
case 0x0c0744d8u: goto P_0c0744d8;
case 0x0c0744dau: goto P_0c0744da;
case 0x0c0744dcu: goto P_0c0744dc;
case 0x0c0744deu: goto P_0c0744de;
case 0x0c0744e0u: goto P_0c0744e0;
case 0x0c0744e2u: goto P_0c0744e2;
case 0x0c0744e4u: goto P_0c0744e4;
case 0x0c0744e6u: goto P_0c0744e6;
case 0x0c0744e8u: goto P_0c0744e8;
case 0x0c0744eau: goto P_0c0744ea;
case 0x0c0744ecu: goto P_0c0744ec;
case 0x0c0744eeu: goto P_0c0744ee;
case 0x0c0744f0u: goto P_0c0744f0;
case 0x0c0744f2u: goto P_0c0744f2;
case 0x0c0744f4u: goto P_0c0744f4;
case 0x0c0744f6u: goto P_0c0744f6;
case 0x0c0744f8u: goto P_0c0744f8;
case 0x0c0744fau: goto P_0c0744fa;
case 0x0c0744fcu: goto P_0c0744fc;
case 0x0c0744feu: goto P_0c0744fe;
case 0x0c074500u: goto P_0c074500;
case 0x0c074502u: goto P_0c074502;
case 0x0c074504u: goto P_0c074504;
case 0x0c074506u: goto P_0c074506;
case 0x0c074508u: goto P_0c074508;
case 0x0c07450au: goto P_0c07450a;
case 0x0c074534u: goto P_0c074534;
case 0x0c074536u: goto P_0c074536;
case 0x0c074538u: goto P_0c074538;
case 0x0c07453au: goto P_0c07453a;
case 0x0c07453cu: goto P_0c07453c;
case 0x0c07453eu: goto P_0c07453e;
case 0x0c074540u: goto P_0c074540;
case 0x0c074542u: goto P_0c074542;
case 0x0c074544u: goto P_0c074544;
case 0x0c074546u: goto P_0c074546;
case 0x0c074548u: goto P_0c074548;
case 0x0c07454au: goto P_0c07454a;
case 0x0c07454cu: goto P_0c07454c;
case 0x0c07454eu: goto P_0c07454e;
case 0x0c074550u: goto P_0c074550;
case 0x0c074552u: goto P_0c074552;
case 0x0c074554u: goto P_0c074554;
case 0x0c074556u: goto P_0c074556;
case 0x0c074558u: goto P_0c074558;
case 0x0c07455au: goto P_0c07455a;
case 0x0c07455cu: goto P_0c07455c;
case 0x0c07455eu: goto P_0c07455e;
case 0x0c074560u: goto P_0c074560;
case 0x0c074562u: goto P_0c074562;
case 0x0c074564u: goto P_0c074564;
case 0x0c074566u: goto P_0c074566;
case 0x0c074568u: goto P_0c074568;
case 0x0c07456au: goto P_0c07456a;
case 0x0c07456cu: goto P_0c07456c;
case 0x0c07456eu: goto P_0c07456e;
case 0x0c074570u: goto P_0c074570;
case 0x0c074572u: goto P_0c074572;
case 0x0c074574u: goto P_0c074574;
case 0x0c074576u: goto P_0c074576;
case 0x0c074578u: goto P_0c074578;
case 0x0c07457au: goto P_0c07457a;
case 0x0c07457cu: goto P_0c07457c;
case 0x0c07457eu: goto P_0c07457e;
case 0x0c074580u: goto P_0c074580;
case 0x0c074582u: goto P_0c074582;
case 0x0c074584u: goto P_0c074584;
case 0x0c074586u: goto P_0c074586;
case 0x0c074588u: goto P_0c074588;
case 0x0c07458au: goto P_0c07458a;
case 0x0c07458cu: goto P_0c07458c;
case 0x0c07458eu: goto P_0c07458e;
case 0x0c074590u: goto P_0c074590;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07413e: /* original 2fe6, guest PC 0x0c07413e */
if(!s->budget--) { s->failed_pc=0x0c07413eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c074140;
P_0c074140: /* original e034, guest PC 0x0c074140 */
if(!s->budget--) { s->failed_pc=0x0c074140u; return 0; }
r[0]=0x00000034u;
goto P_0c074142;
P_0c074142: /* original 2fd6, guest PC 0x0c074142 */
if(!s->budget--) { s->failed_pc=0x0c074142u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c074144;
P_0c074144: /* original 6d53, guest PC 0x0c074144 */
if(!s->budget--) { s->failed_pc=0x0c074144u; return 0; }
r[13]=r[5];
goto P_0c074146;
P_0c074146: /* original 2fc6, guest PC 0x0c074146 */
if(!s->budget--) { s->failed_pc=0x0c074146u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c074148;
P_0c074148: /* original 2fb6, guest PC 0x0c074148 */
if(!s->budget--) { s->failed_pc=0x0c074148u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07414a;
P_0c07414a: /* original 2fa6, guest PC 0x0c07414a */
if(!s->budget--) { s->failed_pc=0x0c07414au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07414c;
P_0c07414c: /* original 2f96, guest PC 0x0c07414c */
if(!s->budget--) { s->failed_pc=0x0c07414cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07414e;
P_0c07414e: /* original 6943, guest PC 0x0c07414e */
if(!s->budget--) { s->failed_pc=0x0c07414eu; return 0; }
r[9]=r[4];
goto P_0c074150;
P_0c074150: /* original 2f86, guest PC 0x0c074150 */
if(!s->budget--) { s->failed_pc=0x0c074150u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c074152;
P_0c074152: /* original fffb, guest PC 0x0c074152 */
if(!s->budget--) { s->failed_pc=0x0c074152u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c074154;
P_0c074154: /* original ffeb, guest PC 0x0c074154 */
if(!s->budget--) { s->failed_pc=0x0c074154u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c074156;
P_0c074156: /* original ffdb, guest PC 0x0c074156 */
if(!s->budget--) { s->failed_pc=0x0c074156u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c074158;
P_0c074158: /* original 4f22, guest PC 0x0c074158 */
if(!s->budget--) { s->failed_pc=0x0c074158u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07415a;
P_0c07415a: /* original 039c, guest PC 0x0c07415a */
if(!s->budget--) { s->failed_pc=0x0c07415au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[9]+r[0],1);
goto P_0c07415c;
P_0c07415c: /* original e018, guest PC 0x0c07415c */
if(!s->budget--) { s->failed_pc=0x0c07415cu; return 0; }
r[0]=0x00000018u;
goto P_0c07415e;
P_0c07415e: /* original db38, guest PC 0x0c07415e */
if(!s->budget--) { s->failed_pc=0x0c07415eu; return 0; }
r[11]=read(ram,0x0c074240u,4);
goto P_0c074160;
P_0c074160: /* original 7fc4, guest PC 0x0c074160 */
if(!s->budget--) { s->failed_pc=0x0c074160u; return 0; }
r[15]+=0xffffffc4u;
goto P_0c074162;
P_0c074162: /* original 0f34, guest PC 0x0c074162 */
if(!s->budget--) { s->failed_pc=0x0c074162u; return 0; }
write(ram,r[15]+r[0],r[3],1);
goto P_0c074164;
P_0c074164: /* original e030, guest PC 0x0c074164 */
if(!s->budget--) { s->failed_pc=0x0c074164u; return 0; }
r[0]=0x00000030u;
goto P_0c074166;
P_0c074166: /* original d138, guest PC 0x0c074166 */
if(!s->budget--) { s->failed_pc=0x0c074166u; return 0; }
r[1]=read(ram,0x0c074248u,4);
goto P_0c074168;
P_0c074168: /* original d336, guest PC 0x0c074168 */
if(!s->budget--) { s->failed_pc=0x0c074168u; return 0; }
r[3]=read(ram,0x0c074244u,4);
goto P_0c07416a;
P_0c07416a: /* original 6212, guest PC 0x0c07416a */
if(!s->budget--) { s->failed_pc=0x0c07416au; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c07416c;
P_0c07416c: /* original fe96, guest PC 0x0c07416c */
if(!s->budget--) { s->failed_pc=0x0c07416cu; return 0; }
vf3_matrix_load(s,ram,14,r[9]+r[0]);
goto P_0c07416e;
P_0c07416e: /* original 2238, guest PC 0x0c07416e */
if(!s->budget--) { s->failed_pc=0x0c07416eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c074170;
P_0c074170: /* original 8d02, guest PC 0x0c074170 */
if(!s->budget--) { s->failed_pc=0x0c074170u; return 0; }
cond=r[17]&1u;
r[14]=r[6];
if(cond) { goto P_0c074178; }
goto P_0c074174;
P_0c074172: /* original 6e63, guest PC 0x0c074172 */
if(!s->budget--) { s->failed_pc=0x0c074172u; return 0; }
r[14]=r[6];
goto P_0c074174;
P_0c074174: /* original a200, guest PC 0x0c074174 */
if(!s->budget--) { s->failed_pc=0x0c074174u; return 0; }
goto P_0c074578;
P_0c074176: /* original 0009, guest PC 0x0c074176 */
if(!s->budget--) { s->failed_pc=0x0c074176u; return 0; }
goto P_0c074178;
P_0c074178: /* original e018, guest PC 0x0c074178 */
if(!s->budget--) { s->failed_pc=0x0c074178u; return 0; }
r[0]=0x00000018u;
goto P_0c07417a;
P_0c07417a: /* original 00fc, guest PC 0x0c07417a */
if(!s->budget--) { s->failed_pc=0x0c07417au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c07417c;
P_0c07417c: /* original 2008, guest PC 0x0c07417c */
if(!s->budget--) { s->failed_pc=0x0c07417cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c07417e;
P_0c07417e: /* original 8922, guest PC 0x0c07417e */
if(!s->budget--) { s->failed_pc=0x0c07417eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0741c6; }
goto P_0c074180;
P_0c074180: /* original e048, guest PC 0x0c074180 */
if(!s->budget--) { s->failed_pc=0x0c074180u; return 0; }
r[0]=0x00000048u;
goto P_0c074182;
P_0c074182: /* original 63e2, guest PC 0x0c074182 */
if(!s->budget--) { s->failed_pc=0x0c074182u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c074184;
P_0c074184: /* original 68d2, guest PC 0x0c074184 */
if(!s->budget--) { s->failed_pc=0x0c074184u; return 0; }
tmp=read(ram,r[13],4);
r[8]=tmp;
goto P_0c074186;
P_0c074186: /* original 1f32, guest PC 0x0c074186 */
if(!s->budget--) { s->failed_pc=0x0c074186u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c074188;
P_0c074188: /* original 04de, guest PC 0x0c074188 */
if(!s->budget--) { s->failed_pc=0x0c074188u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c07418a;
P_0c07418a: /* original 05ee, guest PC 0x0c07418a */
if(!s->budget--) { s->failed_pc=0x0c07418au; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c07418c;
P_0c07418c: /* original 9055, guest PC 0x0c07418c */
if(!s->budget--) { s->failed_pc=0x0c07418cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07423au,2);
goto P_0c07418e;
P_0c07418e: /* original 6643, guest PC 0x0c07418e */
if(!s->budget--) { s->failed_pc=0x0c07418eu; return 0; }
r[6]=r[4];
goto P_0c074190;
P_0c074190: /* original 265b, guest PC 0x0c074190 */
if(!s->budget--) { s->failed_pc=0x0c074190u; return 0; }
r[6]|=r[5];
goto P_0c074192;
P_0c074192: /* original 6743, guest PC 0x0c074192 */
if(!s->budget--) { s->failed_pc=0x0c074192u; return 0; }
r[7]=r[4];
goto P_0c074194;
P_0c074194: /* original 03de, guest PC 0x0c074194 */
if(!s->budget--) { s->failed_pc=0x0c074194u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c074196;
P_0c074196: /* original 1f31, guest PC 0x0c074196 */
if(!s->budget--) { s->failed_pc=0x0c074196u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c074198;
P_0c074198: /* original 904f, guest PC 0x0c074198 */
if(!s->budget--) { s->failed_pc=0x0c074198u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07423au,2);
goto P_0c07419a;
P_0c07419a: /* original 02ee, guest PC 0x0c07419a */
if(!s->budget--) { s->failed_pc=0x0c07419au; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c07419c;
P_0c07419c: /* original e04c, guest PC 0x0c07419c */
if(!s->budget--) { s->failed_pc=0x0c07419cu; return 0; }
r[0]=0x0000004cu;
goto P_0c07419e;
P_0c07419e: /* original 1f24, guest PC 0x0c07419e */
if(!s->budget--) { s->failed_pc=0x0c07419eu; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0741a0;
P_0c0741a0: /* original 6323, guest PC 0x0c0741a0 */
if(!s->budget--) { s->failed_pc=0x0c0741a0u; return 0; }
r[3]=r[2];
goto P_0c0741a2;
P_0c0741a2: /* original 52f1, guest PC 0x0c0741a2 */
if(!s->budget--) { s->failed_pc=0x0c0741a2u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0741a4;
P_0c0741a4: /* original 0cde, guest PC 0x0c0741a4 */
if(!s->budget--) { s->failed_pc=0x0c0741a4u; return 0; }
r[12]=read(ram,r[13]+r[0],4);
goto P_0c0741a6;
P_0c0741a6: /* original 223b, guest PC 0x0c0741a6 */
if(!s->budget--) { s->failed_pc=0x0c0741a6u; return 0; }
r[2]|=r[3];
goto P_0c0741a8;
P_0c0741a8: /* original 0aee, guest PC 0x0c0741a8 */
if(!s->budget--) { s->failed_pc=0x0c0741a8u; return 0; }
r[10]=read(ram,r[14]+r[0],4);
goto P_0c0741aa;
P_0c0741aa: /* original 1f2e, guest PC 0x0c0741aa */
if(!s->budget--) { s->failed_pc=0x0c0741aau; return 0; }
write(ram,r[15]+56,r[2],4);
goto P_0c0741ac;
P_0c0741ac: /* original 51f1, guest PC 0x0c0741ac */
if(!s->budget--) { s->failed_pc=0x0c0741acu; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0741ae;
P_0c0741ae: /* original 2319, guest PC 0x0c0741ae */
if(!s->budget--) { s->failed_pc=0x0c0741aeu; return 0; }
r[3]&=r[1];
goto P_0c0741b0;
P_0c0741b0: /* original 1f3c, guest PC 0x0c0741b0 */
if(!s->budget--) { s->failed_pc=0x0c0741b0u; return 0; }
write(ram,r[15]+48,r[3],4);
goto P_0c0741b2;
P_0c0741b2: /* original 51f2, guest PC 0x0c0741b2 */
if(!s->budget--) { s->failed_pc=0x0c0741b2u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c0741b4;
P_0c0741b4: /* original 218b, guest PC 0x0c0741b4 */
if(!s->budget--) { s->failed_pc=0x0c0741b4u; return 0; }
r[1]|=r[8];
goto P_0c0741b6;
P_0c0741b6: /* original 1f1b, guest PC 0x0c0741b6 */
if(!s->budget--) { s->failed_pc=0x0c0741b6u; return 0; }
write(ram,r[15]+44,r[1],4);
goto P_0c0741b8;
P_0c0741b8: /* original 9340, guest PC 0x0c0741b8 */
if(!s->budget--) { s->failed_pc=0x0c0741b8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07423cu,2);
goto P_0c0741ba;
P_0c0741ba: /* original 2369, guest PC 0x0c0741ba */
if(!s->budget--) { s->failed_pc=0x0c0741bau; return 0; }
r[3]&=r[6];
goto P_0c0741bc;
P_0c0741bc: /* original 2f32, guest PC 0x0c0741bc */
if(!s->budget--) { s->failed_pc=0x0c0741bcu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0741be;
P_0c0741be: /* original 923d, guest PC 0x0c0741be */
if(!s->budget--) { s->failed_pc=0x0c0741beu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07423cu,2);
goto P_0c0741c0;
P_0c0741c0: /* original 3320, guest PC 0x0c0741c0 */
if(!s->budget--) { s->failed_pc=0x0c0741c0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0741c2;
P_0c0741c2: /* original 8f06, guest PC 0x0c0741c2 */
if(!s->budget--) { s->failed_pc=0x0c0741c2u; return 0; }
cond=r[17]&1u;
r[7]&=r[5];
if(!cond) { goto P_0c0741d2; }
goto P_0c0741c6;
P_0c0741c4: /* original 2759, guest PC 0x0c0741c4 */
if(!s->budget--) { s->failed_pc=0x0c0741c4u; return 0; }
r[7]&=r[5];
goto P_0c0741c6;
P_0c0741c6: /* original 65d3, guest PC 0x0c0741c6 */
if(!s->budget--) { s->failed_pc=0x0c0741c6u; return 0; }
r[5]=r[13];
goto P_0c0741c8;
P_0c0741c8: /* original 66e3, guest PC 0x0c0741c8 */
if(!s->budget--) { s->failed_pc=0x0c0741c8u; return 0; }
r[6]=r[14];
goto P_0c0741ca;
P_0c0741ca: /* original b1e2, guest PC 0x0c0741ca */
if(!s->budget--) { s->failed_pc=0x0c0741cau; return 0; }
target=code_base|0x0c074592u; r[16]=code_base|0x0c0741ceu;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0741ceu) { target=s->pc; goto dispatch; }
goto P_0c0741ce;
P_0c0741cc: /* original 6493, guest PC 0x0c0741cc */
if(!s->budget--) { s->failed_pc=0x0c0741ccu; return 0; }
r[4]=r[9];
goto P_0c0741ce;
P_0c0741ce: /* original a1d3, guest PC 0x0c0741ce */
if(!s->budget--) { s->failed_pc=0x0c0741ceu; return 0; }
goto P_0c074578;
P_0c0741d0: /* original 0009, guest PC 0x0c0741d0 */
if(!s->budget--) { s->failed_pc=0x0c0741d0u; return 0; }
goto P_0c0741d2;
P_0c0741d2: /* original e018, guest PC 0x0c0741d2 */
if(!s->budget--) { s->failed_pc=0x0c0741d2u; return 0; }
r[0]=0x00000018u;
goto P_0c0741d4;
P_0c0741d4: /* original 03fc, guest PC 0x0c0741d4 */
if(!s->budget--) { s->failed_pc=0x0c0741d4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c0741d6;
P_0c0741d6: /* original e00c, guest PC 0x0c0741d6 */
if(!s->budget--) { s->failed_pc=0x0c0741d6u; return 0; }
r[0]=0x0000000cu;
goto P_0c0741d8;
P_0c0741d8: /* original 1f3d, guest PC 0x0c0741d8 */
if(!s->budget--) { s->failed_pc=0x0c0741d8u; return 0; }
write(ram,r[15]+52,r[3],4);
goto P_0c0741da;
P_0c0741da: /* original 73ff, guest PC 0x0c0741da */
if(!s->budget--) { s->failed_pc=0x0c0741dau; return 0; }
r[3]+=0xffffffffu;
goto P_0c0741dc;
P_0c0741dc: /* original 435a, guest PC 0x0c0741dc */
if(!s->budget--) { s->failed_pc=0x0c0741dcu; return 0; }
r[53]=r[3];
goto P_0c0741de;
P_0c0741de: /* original f32d, guest PC 0x0c0741de */
if(!s->budget--) { s->failed_pc=0x0c0741deu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0741e0;
P_0c0741e0: /* original ff37, guest PC 0x0c0741e0 */
if(!s->budget--) { s->failed_pc=0x0c0741e0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0741e2;
P_0c0741e2: /* original c71a, guest PC 0x0c0741e2 */
if(!s->budget--) { s->failed_pc=0x0c0741e2u; return 0; }
r[0]=code_base|0x0007424cu;
goto P_0c0741e4;
P_0c0741e4: /* original f608, guest PC 0x0c0741e4 */
if(!s->budget--) { s->failed_pc=0x0c0741e4u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0741e6;
P_0c0741e6: /* original c71a, guest PC 0x0c0741e6 */
if(!s->budget--) { s->failed_pc=0x0c0741e6u; return 0; }
r[0]=code_base|0x00074250u;
goto P_0c0741e8;
P_0c0741e8: /* original f008, guest PC 0x0c0741e8 */
if(!s->budget--) { s->failed_pc=0x0c0741e8u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c0741ea;
P_0c0741ea: /* original f46c, guest PC 0x0c0741ea */
if(!s->budget--) { s->failed_pc=0x0c0741eau; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0741ec;
P_0c0741ec: /* original f43e, guest PC 0x0c0741ec */
if(!s->budget--) { s->failed_pc=0x0c0741ecu; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[3],fr[4],r[18]);
goto P_0c0741ee;
P_0c0741ee: /* original 9326, guest PC 0x0c0741ee */
if(!s->budget--) { s->failed_pc=0x0c0741eeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07423eu,2);
goto P_0c0741f0;
P_0c0741f0: /* original 2368, guest PC 0x0c0741f0 */
if(!s->budget--) { s->failed_pc=0x0c0741f0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0741f2;
P_0c0741f2: /* original 8d05, guest PC 0x0c0741f2 */
if(!s->budget--) { s->failed_pc=0x0c0741f2u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,4);
if(cond) { goto P_0c074200; }
goto P_0c0741f6;
P_0c0741f4: /* original f54c, guest PC 0x0c0741f4 */
if(!s->budget--) { s->failed_pc=0x0c0741f4u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0741f6;
P_0c0741f6: /* original 9122, guest PC 0x0c0741f6 */
if(!s->budget--) { s->failed_pc=0x0c0741f6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07423eu,2);
goto P_0c0741f8;
P_0c0741f8: /* original 2178, guest PC 0x0c0741f8 */
if(!s->budget--) { s->failed_pc=0x0c0741f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[7])==0)!=0);
goto P_0c0741fa;
P_0c0741fa: /* original 8b01, guest PC 0x0c0741fa */
if(!s->budget--) { s->failed_pc=0x0c0741fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074200; }
goto P_0c0741fc;
P_0c0741fc: /* original a1bc, guest PC 0x0c0741fc */
if(!s->budget--) { s->failed_pc=0x0c0741fcu; return 0; }
goto P_0c074578;
P_0c0741fe: /* original 0009, guest PC 0x0c0741fe */
if(!s->budget--) { s->failed_pc=0x0c0741feu; return 0; }
goto P_0c074200;
P_0c074200: /* original 53fb, guest PC 0x0c074200 */
if(!s->budget--) { s->failed_pc=0x0c074200u; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c074202;
P_0c074202: /* original 23b8, guest PC 0x0c074202 */
if(!s->budget--) { s->failed_pc=0x0c074202u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c074204;
P_0c074204: /* original 8d26, guest PC 0x0c074204 */
if(!s->budget--) { s->failed_pc=0x0c074204u; return 0; }
cond=r[17]&1u;
fr[15]=0;
if(cond) { goto P_0c074254; }
goto P_0c074208;
P_0c074206: /* original ff8d, guest PC 0x0c074206 */
if(!s->budget--) { s->failed_pc=0x0c074206u; return 0; }
fr[15]=0;
goto P_0c074208;
P_0c074208: /* original fa5c, guest PC 0x0c074208 */
if(!s->budget--) { s->failed_pc=0x0c074208u; return 0; }
vf3_matrix_move(s,10,5);
goto P_0c07420a;
P_0c07420a: /* original 28b8, guest PC 0x0c07420a */
if(!s->budget--) { s->failed_pc=0x0c07420au; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[11])==0)!=0);
goto P_0c07420c;
P_0c07420c: /* original f64c, guest PC 0x0c07420c */
if(!s->budget--) { s->failed_pc=0x0c07420cu; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c07420e;
P_0c07420e: /* original f94c, guest PC 0x0c07420e */
if(!s->budget--) { s->failed_pc=0x0c07420eu; return 0; }
vf3_matrix_move(s,9,4);
goto P_0c074210;
P_0c074210: /* original 8d08, guest PC 0x0c074210 */
if(!s->budget--) { s->failed_pc=0x0c074210u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,8,5);
if(cond) { goto P_0c074224; }
goto P_0c074214;
P_0c074212: /* original f85c, guest PC 0x0c074212 */
if(!s->budget--) { s->failed_pc=0x0c074212u; return 0; }
vf3_matrix_move(s,8,5);
goto P_0c074214;
P_0c074214: /* original f3ac, guest PC 0x0c074214 */
if(!s->budget--) { s->failed_pc=0x0c074214u; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c074216;
P_0c074216: /* original fa6c, guest PC 0x0c074216 */
if(!s->budget--) { s->failed_pc=0x0c074216u; return 0; }
vf3_matrix_move(s,10,6);
goto P_0c074218;
P_0c074218: /* original fa30, guest PC 0x0c074218 */
if(!s->budget--) { s->failed_pc=0x0c074218u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[3],r[18],'+');
goto P_0c07421a;
P_0c07421a: /* original f38c, guest PC 0x0c07421a */
if(!s->budget--) { s->failed_pc=0x0c07421au; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c07421c;
P_0c07421c: /* original f89c, guest PC 0x0c07421c */
if(!s->budget--) { s->failed_pc=0x0c07421cu; return 0; }
vf3_matrix_move(s,8,9);
goto P_0c07421e;
P_0c07421e: /* original f830, guest PC 0x0c07421e */
if(!s->budget--) { s->failed_pc=0x0c07421eu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'+');
goto P_0c074220;
P_0c074220: /* original f9fc, guest PC 0x0c074220 */
if(!s->budget--) { s->failed_pc=0x0c074220u; return 0; }
vf3_matrix_move(s,9,15);
goto P_0c074222;
P_0c074222: /* original f6fc, guest PC 0x0c074222 */
if(!s->budget--) { s->failed_pc=0x0c074222u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c074224;
P_0c074224: /* original 53f2, guest PC 0x0c074224 */
if(!s->budget--) { s->failed_pc=0x0c074224u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c074226;
P_0c074226: /* original 23b8, guest PC 0x0c074226 */
if(!s->budget--) { s->failed_pc=0x0c074226u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c074228;
P_0c074228: /* original 8b01, guest PC 0x0c074228 */
if(!s->budget--) { s->failed_pc=0x0c074228u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07422e; }
goto P_0c07422a;
P_0c07422a: /* original a15f, guest PC 0x0c07422a */
if(!s->budget--) { s->failed_pc=0x0c07422au; return 0; }
goto P_0c0744ec;
P_0c07422c: /* original 0009, guest PC 0x0c07422c */
if(!s->budget--) { s->failed_pc=0x0c07422cu; return 0; }
goto P_0c07422e;
P_0c07422e: /* original f980, guest PC 0x0c07422e */
if(!s->budget--) { s->failed_pc=0x0c07422eu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[8],r[18],'+');
goto P_0c074230;
P_0c074230: /* original f6a0, guest PC 0x0c074230 */
if(!s->budget--) { s->failed_pc=0x0c074230u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[10],r[18],'+');
goto P_0c074232;
P_0c074232: /* original fafc, guest PC 0x0c074232 */
if(!s->budget--) { s->failed_pc=0x0c074232u; return 0; }
vf3_matrix_move(s,10,15);
goto P_0c074234;
P_0c074234: /* original a15a, guest PC 0x0c074234 */
if(!s->budget--) { s->failed_pc=0x0c074234u; return 0; }
vf3_matrix_move(s,8,15);
goto P_0c0744ec;
P_0c074236: /* original f8fc, guest PC 0x0c074236 */
if(!s->budget--) { s->failed_pc=0x0c074236u; return 0; }
vf3_matrix_move(s,8,15);
if(!vf3_matrix_family(0x0c074238u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c074238u; return 0; } return 1;
P_0c074254: /* original d225, guest PC 0x0c074254 */
if(!s->budget--) { s->failed_pc=0x0c074254u; return 0; }
r[2]=read(ram,0x0c0742ecu,4);
goto P_0c074256;
P_0c074256: /* original 2259, guest PC 0x0c074256 */
if(!s->budget--) { s->failed_pc=0x0c074256u; return 0; }
r[2]&=r[5];
goto P_0c074258;
P_0c074258: /* original 1f22, guest PC 0x0c074258 */
if(!s->budget--) { s->failed_pc=0x0c074258u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c07425a;
P_0c07425a: /* original d325, guest PC 0x0c07425a */
if(!s->budget--) { s->failed_pc=0x0c07425au; return 0; }
r[3]=read(ram,0x0c0742f0u,4);
goto P_0c07425c;
P_0c07425c: /* original d823, guest PC 0x0c07425c */
if(!s->budget--) { s->failed_pc=0x0c07425cu; return 0; }
r[8]=read(ram,0x0c0742ecu,4);
goto P_0c07425e;
P_0c07425e: /* original 2368, guest PC 0x0c07425e */
if(!s->budget--) { s->failed_pc=0x0c07425eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c074260;
P_0c074260: /* original 8d23, guest PC 0x0c074260 */
if(!s->budget--) { s->failed_pc=0x0c074260u; return 0; }
cond=r[17]&1u;
r[8]&=r[4];
if(cond) { goto P_0c0742aa; }
goto P_0c074264;
P_0c074262: /* original 2849, guest PC 0x0c074262 */
if(!s->budget--) { s->failed_pc=0x0c074262u; return 0; }
r[8]&=r[4];
goto P_0c074264;
P_0c074264: /* original d222, guest PC 0x0c074264 */
if(!s->budget--) { s->failed_pc=0x0c074264u; return 0; }
r[2]=read(ram,0x0c0742f0u,4);
goto P_0c074266;
P_0c074266: /* original 2728, guest PC 0x0c074266 */
if(!s->budget--) { s->failed_pc=0x0c074266u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[2])==0)!=0);
goto P_0c074268;
P_0c074268: /* original 8b12, guest PC 0x0c074268 */
if(!s->budget--) { s->failed_pc=0x0c074268u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074290; }
goto P_0c07426a;
P_0c07426a: /* original d321, guest PC 0x0c07426a */
if(!s->budget--) { s->failed_pc=0x0c07426au; return 0; }
r[3]=read(ram,0x0c0742f0u,4);
goto P_0c07426c;
P_0c07426c: /* original 2348, guest PC 0x0c07426c */
if(!s->budget--) { s->failed_pc=0x0c07426cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c07426e;
P_0c07426e: /* original 8d08, guest PC 0x0c07426e */
if(!s->budget--) { s->failed_pc=0x0c07426eu; return 0; }
cond=r[17]&1u;
r[6]=0x00000030u;
if(cond) { goto P_0c074282; }
goto P_0c074272;
P_0c074270: /* original e630, guest PC 0x0c074270 */
if(!s->budget--) { s->failed_pc=0x0c074270u; return 0; }
r[6]=0x00000030u;
goto P_0c074272;
P_0c074272: /* original 52f2, guest PC 0x0c074272 */
if(!s->budget--) { s->failed_pc=0x0c074272u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c074274;
P_0c074274: /* original 2228, guest PC 0x0c074274 */
if(!s->budget--) { s->failed_pc=0x0c074274u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c074276;
P_0c074276: /* original 8b09, guest PC 0x0c074276 */
if(!s->budget--) { s->failed_pc=0x0c074276u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07428c; }
goto P_0c074278;
P_0c074278: /* original 51de, guest PC 0x0c074278 */
if(!s->budget--) { s->failed_pc=0x0c074278u; return 0; }
r[1]=read(ram,r[13]+56,4);
goto P_0c07427a;
P_0c07427a: /* original 2618, guest PC 0x0c07427a */
if(!s->budget--) { s->failed_pc=0x0c07427au; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[1])==0)!=0);
goto P_0c07427c;
P_0c07427c: /* original 8b08, guest PC 0x0c07427c */
if(!s->budget--) { s->failed_pc=0x0c07427cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074290; }
goto P_0c07427e;
P_0c07427e: /* original a135, guest PC 0x0c07427e */
if(!s->budget--) { s->failed_pc=0x0c07427eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0744ec;
P_0c074280: /* original f4fc, guest PC 0x0c074280 */
if(!s->budget--) { s->failed_pc=0x0c074280u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c074282;
P_0c074282: /* original 2888, guest PC 0x0c074282 */
if(!s->budget--) { s->failed_pc=0x0c074282u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c074284;
P_0c074284: /* original 8bfb, guest PC 0x0c074284 */
if(!s->budget--) { s->failed_pc=0x0c074284u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07427e; }
goto P_0c074286;
P_0c074286: /* original 52ee, guest PC 0x0c074286 */
if(!s->budget--) { s->failed_pc=0x0c074286u; return 0; }
r[2]=read(ram,r[14]+56,4);
goto P_0c074288;
P_0c074288: /* original 2628, guest PC 0x0c074288 */
if(!s->budget--) { s->failed_pc=0x0c074288u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c07428a;
P_0c07428a: /* original 8b01, guest PC 0x0c07428a */
if(!s->budget--) { s->failed_pc=0x0c07428au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074290; }
goto P_0c07428c;
P_0c07428c: /* original a12e, guest PC 0x0c07428c */
if(!s->budget--) { s->failed_pc=0x0c07428cu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0744ec;
P_0c07428e: /* original f5fc, guest PC 0x0c07428e */
if(!s->budget--) { s->failed_pc=0x0c07428eu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c074290;
P_0c074290: /* original d318, guest PC 0x0c074290 */
if(!s->budget--) { s->failed_pc=0x0c074290u; return 0; }
r[3]=read(ram,0x0c0742f4u,4);
goto P_0c074292;
P_0c074292: /* original 245a, guest PC 0x0c074292 */
if(!s->budget--) { s->failed_pc=0x0c074292u; return 0; }
r[4]^=r[5];
goto P_0c074294;
P_0c074294: /* original 6243, guest PC 0x0c074294 */
if(!s->budget--) { s->failed_pc=0x0c074294u; return 0; }
r[2]=r[4];
goto P_0c074296;
P_0c074296: /* original 2238, guest PC 0x0c074296 */
if(!s->budget--) { s->failed_pc=0x0c074296u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c074298;
P_0c074298: /* original 8f02, guest PC 0x0c074298 */
if(!s->budget--) { s->failed_pc=0x0c074298u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+20,r[4],4);
if(!cond) { goto P_0c0742a0; }
goto P_0c07429c;
P_0c07429a: /* original 1f45, guest PC 0x0c07429a */
if(!s->budget--) { s->failed_pc=0x0c07429au; return 0; }
write(ram,r[15]+20,r[4],4);
goto P_0c07429c;
P_0c07429c: /* original a126, guest PC 0x0c07429c */
if(!s->budget--) { s->failed_pc=0x0c07429cu; return 0; }
goto P_0c0744ec;
P_0c07429e: /* original 0009, guest PC 0x0c07429e */
if(!s->budget--) { s->failed_pc=0x0c07429eu; return 0; }
goto P_0c0742a0;
P_0c0742a0: /* original d114, guest PC 0x0c0742a0 */
if(!s->budget--) { s->failed_pc=0x0c0742a0u; return 0; }
r[1]=read(ram,0x0c0742f4u,4);
goto P_0c0742a2;
P_0c0742a2: /* original 2518, guest PC 0x0c0742a2 */
if(!s->budget--) { s->failed_pc=0x0c0742a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[1])==0)!=0);
goto P_0c0742a4;
P_0c0742a4: /* original 8beb, guest PC 0x0c0742a4 */
if(!s->budget--) { s->failed_pc=0x0c0742a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07427e; }
goto P_0c0742a6;
P_0c0742a6: /* original aff1, guest PC 0x0c0742a6 */
if(!s->budget--) { s->failed_pc=0x0c0742a6u; return 0; }
goto P_0c07428c;
P_0c0742a8: /* original 0009, guest PC 0x0c0742a8 */
if(!s->budget--) { s->failed_pc=0x0c0742a8u; return 0; }
goto P_0c0742aa;
P_0c0742aa: /* original 931d, guest PC 0x0c0742aa */
if(!s->budget--) { s->failed_pc=0x0c0742aau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0742e8u,2);
goto P_0c0742ac;
P_0c0742ac: /* original c712, guest PC 0x0c0742ac */
if(!s->budget--) { s->failed_pc=0x0c0742acu; return 0; }
r[0]=code_base|0x000742f8u;
goto P_0c0742ae;
P_0c0742ae: /* original 2348, guest PC 0x0c0742ae */
if(!s->budget--) { s->failed_pc=0x0c0742aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0742b0;
P_0c0742b0: /* original 8d0c, guest PC 0x0c0742b0 */
if(!s->budget--) { s->failed_pc=0x0c0742b0u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,7,r[0]);
if(cond) { goto P_0c0742cc; }
goto P_0c0742b4;
P_0c0742b2: /* original f708, guest PC 0x0c0742b2 */
if(!s->budget--) { s->failed_pc=0x0c0742b2u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0742b4;
P_0c0742b4: /* original 52f2, guest PC 0x0c0742b4 */
if(!s->budget--) { s->failed_pc=0x0c0742b4u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0742b6;
P_0c0742b6: /* original 2228, guest PC 0x0c0742b6 */
if(!s->budget--) { s->failed_pc=0x0c0742b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0742b8;
P_0c0742b8: /* original 8908, guest PC 0x0c0742b8 */
if(!s->budget--) { s->failed_pc=0x0c0742b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0742cc; }
goto P_0c0742ba;
P_0c0742ba: /* original d310, guest PC 0x0c0742ba */
if(!s->budget--) { s->failed_pc=0x0c0742bau; return 0; }
r[3]=read(ram,0x0c0742fcu,4);
goto P_0c0742bc;
P_0c0742bc: /* original f5fc, guest PC 0x0c0742bc */
if(!s->budget--) { s->failed_pc=0x0c0742bcu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0742be;
P_0c0742be: /* original 2438, guest PC 0x0c0742be */
if(!s->budget--) { s->failed_pc=0x0c0742beu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0742c0;
P_0c0742c0: /* original 8d02, guest PC 0x0c0742c0 */
if(!s->budget--) { s->failed_pc=0x0c0742c0u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
if(cond) { goto P_0c0742c8; }
goto P_0c0742c4;
P_0c0742c2: /* original f472, guest PC 0x0c0742c2 */
if(!s->budget--) { s->failed_pc=0x0c0742c2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c0742c4;
P_0c0742c4: /* original a151, guest PC 0x0c0742c4 */
if(!s->budget--) { s->failed_pc=0x0c0742c4u; return 0; }
goto P_0c07456a;
P_0c0742c6: /* original 0009, guest PC 0x0c0742c6 */
if(!s->budget--) { s->failed_pc=0x0c0742c6u; return 0; }
goto P_0c0742c8;
P_0c0742c8: /* original a14f, guest PC 0x0c0742c8 */
if(!s->budget--) { s->failed_pc=0x0c0742c8u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c07456a;
P_0c0742ca: /* original f4fc, guest PC 0x0c0742ca */
if(!s->budget--) { s->failed_pc=0x0c0742cau; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0742cc;
P_0c0742cc: /* original 930c, guest PC 0x0c0742cc */
if(!s->budget--) { s->failed_pc=0x0c0742ccu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0742e8u,2);
goto P_0c0742ce;
P_0c0742ce: /* original 2358, guest PC 0x0c0742ce */
if(!s->budget--) { s->failed_pc=0x0c0742ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0742d0;
P_0c0742d0: /* original 8916, guest PC 0x0c0742d0 */
if(!s->budget--) { s->failed_pc=0x0c0742d0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074300; }
goto P_0c0742d2;
P_0c0742d2: /* original 2888, guest PC 0x0c0742d2 */
if(!s->budget--) { s->failed_pc=0x0c0742d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c0742d4;
P_0c0742d4: /* original 8914, guest PC 0x0c0742d4 */
if(!s->budget--) { s->failed_pc=0x0c0742d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074300; }
goto P_0c0742d6;
P_0c0742d6: /* original d309, guest PC 0x0c0742d6 */
if(!s->budget--) { s->failed_pc=0x0c0742d6u; return 0; }
r[3]=read(ram,0x0c0742fcu,4);
goto P_0c0742d8;
P_0c0742d8: /* original f4fc, guest PC 0x0c0742d8 */
if(!s->budget--) { s->failed_pc=0x0c0742d8u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0742da;
P_0c0742da: /* original 2538, guest PC 0x0c0742da */
if(!s->budget--) { s->failed_pc=0x0c0742dau; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0742dc;
P_0c0742dc: /* original 8d02, guest PC 0x0c0742dc */
if(!s->budget--) { s->failed_pc=0x0c0742dcu; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
if(cond) { goto P_0c0742e4; }
goto P_0c0742e0;
P_0c0742de: /* original f572, guest PC 0x0c0742de */
if(!s->budget--) { s->failed_pc=0x0c0742deu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c0742e0;
P_0c0742e0: /* original a143, guest PC 0x0c0742e0 */
if(!s->budget--) { s->failed_pc=0x0c0742e0u; return 0; }
goto P_0c07456a;
P_0c0742e2: /* original 0009, guest PC 0x0c0742e2 */
if(!s->budget--) { s->failed_pc=0x0c0742e2u; return 0; }
goto P_0c0742e4;
P_0c0742e4: /* original a141, guest PC 0x0c0742e4 */
if(!s->budget--) { s->failed_pc=0x0c0742e4u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c07456a;
P_0c0742e6: /* original f5fc, guest PC 0x0c0742e6 */
if(!s->budget--) { s->failed_pc=0x0c0742e6u; return 0; }
vf3_matrix_move(s,5,15);
if(!vf3_matrix_family(0x0c0742e8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0742e8u; return 0; } return 1;
P_0c074300: /* original 9058, guest PC 0x0c074300 */
if(!s->budget--) { s->failed_pc=0x0c074300u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0743b4u,2);
goto P_0c074302;
P_0c074302: /* original 02dc, guest PC 0x0c074302 */
if(!s->budget--) { s->failed_pc=0x0c074302u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c074304;
P_0c074304: /* original 622c, guest PC 0x0c074304 */
if(!s->budget--) { s->failed_pc=0x0c074304u; return 0; }
r[2]=r[2]&255u;
goto P_0c074306;
P_0c074306: /* original 2f22, guest PC 0x0c074306 */
if(!s->budget--) { s->failed_pc=0x0c074306u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c074308;
P_0c074308: /* original 9054, guest PC 0x0c074308 */
if(!s->budget--) { s->failed_pc=0x0c074308u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0743b4u,2);
goto P_0c07430a;
P_0c07430a: /* original 03ec, guest PC 0x0c07430a */
if(!s->budget--) { s->failed_pc=0x0c07430au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07430c;
P_0c07430c: /* original 633c, guest PC 0x0c07430c */
if(!s->budget--) { s->failed_pc=0x0c07430cu; return 0; }
r[3]=r[3]&255u;
goto P_0c07430e;
P_0c07430e: /* original 223b, guest PC 0x0c07430e */
if(!s->budget--) { s->failed_pc=0x0c07430eu; return 0; }
r[2]|=r[3];
goto P_0c074310;
P_0c074310: /* original e340, guest PC 0x0c074310 */
if(!s->budget--) { s->failed_pc=0x0c074310u; return 0; }
r[3]=0x00000040u;
goto P_0c074312;
P_0c074312: /* original 2f22, guest PC 0x0c074312 */
if(!s->budget--) { s->failed_pc=0x0c074312u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c074314;
P_0c074314: /* original 2238, guest PC 0x0c074314 */
if(!s->budget--) { s->failed_pc=0x0c074314u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c074316;
P_0c074316: /* original fd4c, guest PC 0x0c074316 */
if(!s->budget--) { s->failed_pc=0x0c074316u; return 0; }
vf3_matrix_move(s,13,4);
goto P_0c074318;
P_0c074318: /* original 8f2c, guest PC 0x0c074318 */
if(!s->budget--) { s->failed_pc=0x0c074318u; return 0; }
cond=r[17]&1u;
fr[13]=vf3_fpu_binary(fr[13],fr[5],r[18],'+');
if(!cond) { goto P_0c074374; }
goto P_0c07431c;
P_0c07431a: /* original fd50, guest PC 0x0c07431a */
if(!s->budget--) { s->failed_pc=0x0c07431au; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[5],r[18],'+');
goto P_0c07431c;
P_0c07431c: /* original d227, guest PC 0x0c07431c */
if(!s->budget--) { s->failed_pc=0x0c07431cu; return 0; }
r[2]=read(ram,0x0c0743bcu,4);
goto P_0c07431e;
P_0c07431e: /* original 53fe, guest PC 0x0c07431e */
if(!s->budget--) { s->failed_pc=0x0c07431eu; return 0; }
r[3]=read(ram,r[15]+56,4);
goto P_0c074320;
P_0c074320: /* original d825, guest PC 0x0c074320 */
if(!s->budget--) { s->failed_pc=0x0c074320u; return 0; }
r[8]=read(ram,0x0c0743b8u,4);
goto P_0c074322;
P_0c074322: /* original 2268, guest PC 0x0c074322 */
if(!s->budget--) { s->failed_pc=0x0c074322u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c074324;
P_0c074324: /* original 2389, guest PC 0x0c074324 */
if(!s->budget--) { s->failed_pc=0x0c074324u; return 0; }
r[3]&=r[8];
goto P_0c074326;
P_0c074326: /* original 8d4f, guest PC 0x0c074326 */
if(!s->budget--) { s->failed_pc=0x0c074326u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+40,r[3],4);
if(cond) { goto P_0c0743c8; }
goto P_0c07432a;
P_0c074328: /* original 1f3a, guest PC 0x0c074328 */
if(!s->budget--) { s->failed_pc=0x0c074328u; return 0; }
write(ram,r[15]+40,r[3],4);
goto P_0c07432a;
P_0c07432a: /* original d324, guest PC 0x0c07432a */
if(!s->budget--) { s->failed_pc=0x0c07432au; return 0; }
r[3]=read(ram,0x0c0743bcu,4);
goto P_0c07432c;
P_0c07432c: /* original 2378, guest PC 0x0c07432c */
if(!s->budget--) { s->failed_pc=0x0c07432cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c07432e;
P_0c07432e: /* original 8b14, guest PC 0x0c07432e */
if(!s->budget--) { s->failed_pc=0x0c07432eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07435a; }
goto P_0c074330;
P_0c074330: /* original 52f2, guest PC 0x0c074330 */
if(!s->budget--) { s->failed_pc=0x0c074330u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c074332;
P_0c074332: /* original 2228, guest PC 0x0c074332 */
if(!s->budget--) { s->failed_pc=0x0c074332u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c074334;
P_0c074334: /* original 8b08, guest PC 0x0c074334 */
if(!s->budget--) { s->failed_pc=0x0c074334u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074348; }
goto P_0c074336;
P_0c074336: /* original d322, guest PC 0x0c074336 */
if(!s->budget--) { s->failed_pc=0x0c074336u; return 0; }
r[3]=read(ram,0x0c0743c0u,4);
goto P_0c074338;
P_0c074338: /* original f5dc, guest PC 0x0c074338 */
if(!s->budget--) { s->failed_pc=0x0c074338u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c07433a;
P_0c07433a: /* original 2a38, guest PC 0x0c07433a */
if(!s->budget--) { s->failed_pc=0x0c07433au; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[3])==0)!=0);
goto P_0c07433c;
P_0c07433c: /* original 8f02, guest PC 0x0c07433c */
if(!s->budget--) { s->failed_pc=0x0c07433cu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,15);
if(!cond) { goto P_0c074344; }
goto P_0c074340;
P_0c07433e: /* original f4fc, guest PC 0x0c07433e */
if(!s->budget--) { s->failed_pc=0x0c07433eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c074340;
P_0c074340: /* original a0d4, guest PC 0x0c074340 */
if(!s->budget--) { s->failed_pc=0x0c074340u; return 0; }
goto P_0c0744ec;
P_0c074342: /* original 0009, guest PC 0x0c074342 */
if(!s->budget--) { s->failed_pc=0x0c074342u; return 0; }
goto P_0c074344;
P_0c074344: /* original a09d, guest PC 0x0c074344 */
if(!s->budget--) { s->failed_pc=0x0c074344u; return 0; }
goto P_0c074482;
P_0c074346: /* original 0009, guest PC 0x0c074346 */
if(!s->budget--) { s->failed_pc=0x0c074346u; return 0; }
goto P_0c074348;
P_0c074348: /* original d31d, guest PC 0x0c074348 */
if(!s->budget--) { s->failed_pc=0x0c074348u; return 0; }
r[3]=read(ram,0x0c0743c0u,4);
goto P_0c07434a;
P_0c07434a: /* original f4dc, guest PC 0x0c07434a */
if(!s->budget--) { s->failed_pc=0x0c07434au; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c07434c;
P_0c07434c: /* original 2c38, guest PC 0x0c07434c */
if(!s->budget--) { s->failed_pc=0x0c07434cu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[3])==0)!=0);
goto P_0c07434e;
P_0c07434e: /* original 8f02, guest PC 0x0c07434e */
if(!s->budget--) { s->failed_pc=0x0c07434eu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,15);
if(!cond) { goto P_0c074356; }
goto P_0c074352;
P_0c074350: /* original f5fc, guest PC 0x0c074350 */
if(!s->budget--) { s->failed_pc=0x0c074350u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c074352;
P_0c074352: /* original a0cb, guest PC 0x0c074352 */
if(!s->budget--) { s->failed_pc=0x0c074352u; return 0; }
goto P_0c0744ec;
P_0c074354: /* original 0009, guest PC 0x0c074354 */
if(!s->budget--) { s->failed_pc=0x0c074354u; return 0; }
goto P_0c074356;
P_0c074356: /* original a086, guest PC 0x0c074356 */
if(!s->budget--) { s->failed_pc=0x0c074356u; return 0; }
goto P_0c074466;
P_0c074358: /* original 0009, guest PC 0x0c074358 */
if(!s->budget--) { s->failed_pc=0x0c074358u; return 0; }
goto P_0c07435a;
P_0c07435a: /* original 52fa, guest PC 0x0c07435a */
if(!s->budget--) { s->failed_pc=0x0c07435au; return 0; }
r[2]=read(ram,r[15]+40,4);
goto P_0c07435c;
P_0c07435c: /* original 2228, guest PC 0x0c07435c */
if(!s->budget--) { s->failed_pc=0x0c07435cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07435e;
P_0c07435e: /* original 8b01, guest PC 0x0c07435e */
if(!s->budget--) { s->failed_pc=0x0c07435eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074364; }
goto P_0c074360;
P_0c074360: /* original a0c4, guest PC 0x0c074360 */
if(!s->budget--) { s->failed_pc=0x0c074360u; return 0; }
goto P_0c0744ec;
P_0c074362: /* original 0009, guest PC 0x0c074362 */
if(!s->budget--) { s->failed_pc=0x0c074362u; return 0; }
goto P_0c074364;
P_0c074364: /* original 51fc, guest PC 0x0c074364 */
if(!s->budget--) { s->failed_pc=0x0c074364u; return 0; }
r[1]=read(ram,r[15]+48,4);
goto P_0c074366;
P_0c074366: /* original 2188, guest PC 0x0c074366 */
if(!s->budget--) { s->failed_pc=0x0c074366u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[8])==0)!=0);
goto P_0c074368;
P_0c074368: /* original 8b2e, guest PC 0x0c074368 */
if(!s->budget--) { s->failed_pc=0x0c074368u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0743c8; }
goto P_0c07436a;
P_0c07436a: /* original 53f1, guest PC 0x0c07436a */
if(!s->budget--) { s->failed_pc=0x0c07436au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07436c;
P_0c07436c: /* original 2838, guest PC 0x0c07436c */
if(!s->budget--) { s->failed_pc=0x0c07436cu; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[3])==0)!=0);
goto P_0c07436e;
P_0c07436e: /* original 8beb, guest PC 0x0c07436e */
if(!s->budget--) { s->failed_pc=0x0c07436eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074348; }
goto P_0c074370;
P_0c074370: /* original afe1, guest PC 0x0c074370 */
if(!s->budget--) { s->failed_pc=0x0c074370u; return 0; }
goto P_0c074336;
P_0c074372: /* original 0009, guest PC 0x0c074372 */
if(!s->budget--) { s->failed_pc=0x0c074372u; return 0; }
goto P_0c074374;
P_0c074374: /* original 61f3, guest PC 0x0c074374 */
if(!s->budget--) { s->failed_pc=0x0c074374u; return 0; }
r[1]=r[15];
goto P_0c074376;
P_0c074376: /* original 2f16, guest PC 0x0c074376 */
if(!s->budget--) { s->failed_pc=0x0c074376u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c074378;
P_0c074378: /* original 65f3, guest PC 0x0c074378 */
if(!s->budget--) { s->failed_pc=0x0c074378u; return 0; }
r[5]=r[15];
goto P_0c07437a;
P_0c07437a: /* original d312, guest PC 0x0c07437a */
if(!s->budget--) { s->failed_pc=0x0c07437au; return 0; }
r[3]=read(ram,0x0c0743c4u,4);
goto P_0c07437c;
P_0c07437c: /* original 66f3, guest PC 0x0c07437c */
if(!s->budget--) { s->failed_pc=0x0c07437cu; return 0; }
r[6]=r[15];
goto P_0c07437e;
P_0c07437e: /* original 67f3, guest PC 0x0c07437e */
if(!s->budget--) { s->failed_pc=0x0c07437eu; return 0; }
r[7]=r[15];
goto P_0c074380;
P_0c074380: /* original 7510, guest PC 0x0c074380 */
if(!s->budget--) { s->failed_pc=0x0c074380u; return 0; }
r[5]+=0x00000010u;
goto P_0c074382;
P_0c074382: /* original 7624, guest PC 0x0c074382 */
if(!s->budget--) { s->failed_pc=0x0c074382u; return 0; }
r[6]+=0x00000024u;
goto P_0c074384;
P_0c074384: /* original 7728, guest PC 0x0c074384 */
if(!s->budget--) { s->failed_pc=0x0c074384u; return 0; }
r[7]+=0x00000028u;
goto P_0c074386;
P_0c074386: /* original 430b, guest PC 0x0c074386 */
if(!s->budget--) { s->failed_pc=0x0c074386u; return 0; }
target=r[3];
r[16]=code_base|0x0c07438au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07438au) { target=s->pc; goto dispatch; }
goto P_0c07438a;
P_0c074388: /* original 64d3, guest PC 0x0c074388 */
if(!s->budget--) { s->failed_pc=0x0c074388u; return 0; }
r[4]=r[13];
goto P_0c07438a;
P_0c07438a: /* original 62f3, guest PC 0x0c07438a */
if(!s->budget--) { s->failed_pc=0x0c07438au; return 0; }
r[2]=r[15];
goto P_0c07438c;
P_0c07438c: /* original 7218, guest PC 0x0c07438c */
if(!s->budget--) { s->failed_pc=0x0c07438cu; return 0; }
r[2]+=0x00000018u;
goto P_0c07438e;
P_0c07438e: /* original 2f26, guest PC 0x0c07438e */
if(!s->budget--) { s->failed_pc=0x0c07438eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c074390;
P_0c074390: /* original 66f3, guest PC 0x0c074390 */
if(!s->budget--) { s->failed_pc=0x0c074390u; return 0; }
r[6]=r[15];
goto P_0c074392;
P_0c074392: /* original 65f3, guest PC 0x0c074392 */
if(!s->budget--) { s->failed_pc=0x0c074392u; return 0; }
r[5]=r[15];
goto P_0c074394;
P_0c074394: /* original 67f3, guest PC 0x0c074394 */
if(!s->budget--) { s->failed_pc=0x0c074394u; return 0; }
r[7]=r[15];
goto P_0c074396;
P_0c074396: /* original d30b, guest PC 0x0c074396 */
if(!s->budget--) { s->failed_pc=0x0c074396u; return 0; }
r[3]=read(ram,0x0c0743c4u,4);
goto P_0c074398;
P_0c074398: /* original 7514, guest PC 0x0c074398 */
if(!s->budget--) { s->failed_pc=0x0c074398u; return 0; }
r[5]+=0x00000014u;
goto P_0c07439a;
P_0c07439a: /* original 7724, guest PC 0x0c07439a */
if(!s->budget--) { s->failed_pc=0x0c07439au; return 0; }
r[7]+=0x00000024u;
goto P_0c07439c;
P_0c07439c: /* original 7628, guest PC 0x0c07439c */
if(!s->budget--) { s->failed_pc=0x0c07439cu; return 0; }
r[6]+=0x00000028u;
goto P_0c07439e;
P_0c07439e: /* original 430b, guest PC 0x0c07439e */
if(!s->budget--) { s->failed_pc=0x0c07439eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0743a2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0743a2u) { target=s->pc; goto dispatch; }
goto P_0c0743a2;
P_0c0743a0: /* original 64e3, guest PC 0x0c0743a0 */
if(!s->budget--) { s->failed_pc=0x0c0743a0u; return 0; }
r[4]=r[14];
goto P_0c0743a2;
P_0c0743a2: /* original e024, guest PC 0x0c0743a2 */
if(!s->budget--) { s->failed_pc=0x0c0743a2u; return 0; }
r[0]=0x00000024u;
goto P_0c0743a4;
P_0c0743a4: /* original 7f08, guest PC 0x0c0743a4 */
if(!s->budget--) { s->failed_pc=0x0c0743a4u; return 0; }
r[15]+=0x00000008u;
goto P_0c0743a6;
P_0c0743a6: /* original f3f6, guest PC 0x0c0743a6 */
if(!s->budget--) { s->failed_pc=0x0c0743a6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0743a8;
P_0c0743a8: /* original e01c, guest PC 0x0c0743a8 */
if(!s->budget--) { s->failed_pc=0x0c0743a8u; return 0; }
r[0]=0x0000001cu;
goto P_0c0743aa;
P_0c0743aa: /* original f2f6, guest PC 0x0c0743aa */
if(!s->budget--) { s->failed_pc=0x0c0743aau; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0743ac;
P_0c0743ac: /* original f325, guest PC 0x0c0743ac */
if(!s->budget--) { s->failed_pc=0x0c0743acu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0743ae;
P_0c0743ae: /* original 89cb, guest PC 0x0c0743ae */
if(!s->budget--) { s->failed_pc=0x0c0743aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074348; }
goto P_0c0743b0;
P_0c0743b0: /* original afc1, guest PC 0x0c0743b0 */
if(!s->budget--) { s->failed_pc=0x0c0743b0u; return 0; }
goto P_0c074336;
P_0c0743b2: /* original 0009, guest PC 0x0c0743b2 */
if(!s->budget--) { s->failed_pc=0x0c0743b2u; return 0; }
if(!vf3_matrix_family(0x0c0743b4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0743b4u; return 0; } return 1;
P_0c0743c8: /* original 53fa, guest PC 0x0c0743c8 */
if(!s->budget--) { s->failed_pc=0x0c0743c8u; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c0743ca;
P_0c0743ca: /* original c750, guest PC 0x0c0743ca */
if(!s->budget--) { s->failed_pc=0x0c0743cau; return 0; }
r[0]=code_base|0x0007450cu;
goto P_0c0743cc;
P_0c0743cc: /* original f708, guest PC 0x0c0743cc */
if(!s->budget--) { s->failed_pc=0x0c0743ccu; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0743ce;
P_0c0743ce: /* original 2338, guest PC 0x0c0743ce */
if(!s->budget--) { s->failed_pc=0x0c0743ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0743d0;
P_0c0743d0: /* original 8d5c, guest PC 0x0c0743d0 */
if(!s->budget--) { s->failed_pc=0x0c0743d0u; return 0; }
cond=r[17]&1u;
fr[9]=0x3f800000u;
if(cond) { goto P_0c07448c; }
goto P_0c0743d4;
P_0c0743d2: /* original f99d, guest PC 0x0c0743d2 */
if(!s->budget--) { s->failed_pc=0x0c0743d2u; return 0; }
fr[9]=0x3f800000u;
goto P_0c0743d4;
P_0c0743d4: /* original 52fd, guest PC 0x0c0743d4 */
if(!s->budget--) { s->failed_pc=0x0c0743d4u; return 0; }
r[2]=read(ram,r[15]+52,4);
goto P_0c0743d6;
P_0c0743d6: /* original e31e, guest PC 0x0c0743d6 */
if(!s->budget--) { s->failed_pc=0x0c0743d6u; return 0; }
r[3]=0x0000001eu;
goto P_0c0743d8;
P_0c0743d8: /* original 3233, guest PC 0x0c0743d8 */
if(!s->budget--) { s->failed_pc=0x0c0743d8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c0743da;
P_0c0743da: /* original 8f08, guest PC 0x0c0743da */
if(!s->budget--) { s->failed_pc=0x0c0743dau; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,6,7);
if(!cond) { goto P_0c0743ee; }
goto P_0c0743de;
P_0c0743dc: /* original f67c, guest PC 0x0c0743dc */
if(!s->budget--) { s->failed_pc=0x0c0743dcu; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c0743de;
P_0c0743de: /* original e018, guest PC 0x0c0743de */
if(!s->budget--) { s->failed_pc=0x0c0743deu; return 0; }
r[0]=0x00000018u;
goto P_0c0743e0;
P_0c0743e0: /* original f67c, guest PC 0x0c0743e0 */
if(!s->budget--) { s->failed_pc=0x0c0743e0u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c0743e2;
P_0c0743e2: /* original 02fc, guest PC 0x0c0743e2 */
if(!s->budget--) { s->failed_pc=0x0c0743e2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c0743e4;
P_0c0743e4: /* original c74a, guest PC 0x0c0743e4 */
if(!s->budget--) { s->failed_pc=0x0c0743e4u; return 0; }
r[0]=code_base|0x00074510u;
goto P_0c0743e6;
P_0c0743e6: /* original f008, guest PC 0x0c0743e6 */
if(!s->budget--) { s->failed_pc=0x0c0743e6u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c0743e8;
P_0c0743e8: /* original 425a, guest PC 0x0c0743e8 */
if(!s->budget--) { s->failed_pc=0x0c0743e8u; return 0; }
r[53]=r[2];
goto P_0c0743ea;
P_0c0743ea: /* original f32d, guest PC 0x0c0743ea */
if(!s->budget--) { s->failed_pc=0x0c0743eau; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0743ec;
P_0c0743ec: /* original f63e, guest PC 0x0c0743ec */
if(!s->budget--) { s->failed_pc=0x0c0743ecu; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[3],fr[6],r[18]);
goto P_0c0743ee;
P_0c0743ee: /* original e340, guest PC 0x0c0743ee */
if(!s->budget--) { s->failed_pc=0x0c0743eeu; return 0; }
r[3]=0x00000040u;
goto P_0c0743f0;
P_0c0743f0: /* original 23c8, guest PC 0x0c0743f0 */
if(!s->budget--) { s->failed_pc=0x0c0743f0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0743f2;
P_0c0743f2: /* original c748, guest PC 0x0c0743f2 */
if(!s->budget--) { s->failed_pc=0x0c0743f2u; return 0; }
r[0]=code_base|0x00074514u;
goto P_0c0743f4;
P_0c0743f4: /* original 8d01, guest PC 0x0c0743f4 */
if(!s->budget--) { s->failed_pc=0x0c0743f4u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,8,r[0]);
if(cond) { goto P_0c0743fa; }
goto P_0c0743f8;
P_0c0743f6: /* original f808, guest PC 0x0c0743f6 */
if(!s->budget--) { s->failed_pc=0x0c0743f6u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c0743f8;
P_0c0743f8: /* original f681, guest PC 0x0c0743f8 */
if(!s->budget--) { s->failed_pc=0x0c0743f8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[8],r[18],'-');
goto P_0c0743fa;
P_0c0743fa: /* original e340, guest PC 0x0c0743fa */
if(!s->budget--) { s->failed_pc=0x0c0743fau; return 0; }
r[3]=0x00000040u;
goto P_0c0743fc;
P_0c0743fc: /* original 23a8, guest PC 0x0c0743fc */
if(!s->budget--) { s->failed_pc=0x0c0743fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[10])==0)!=0);
goto P_0c0743fe;
P_0c0743fe: /* original 8d01, guest PC 0x0c0743fe */
if(!s->budget--) { s->failed_pc=0x0c0743feu; return 0; }
cond=r[17]&1u;
r[6]=0x00000020u;
if(cond) { goto P_0c074404; }
goto P_0c074402;
P_0c074400: /* original e620, guest PC 0x0c074400 */
if(!s->budget--) { s->failed_pc=0x0c074400u; return 0; }
r[6]=0x00000020u;
goto P_0c074402;
P_0c074402: /* original f681, guest PC 0x0c074402 */
if(!s->budget--) { s->failed_pc=0x0c074402u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[8],r[18],'-');
goto P_0c074404;
P_0c074404: /* original 2c68, guest PC 0x0c074404 */
if(!s->budget--) { s->failed_pc=0x0c074404u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[6])==0)!=0);
goto P_0c074406;
P_0c074406: /* original 8900, guest PC 0x0c074406 */
if(!s->budget--) { s->failed_pc=0x0c074406u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07440a; }
goto P_0c074408;
P_0c074408: /* original f680, guest PC 0x0c074408 */
if(!s->budget--) { s->failed_pc=0x0c074408u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[8],r[18],'+');
goto P_0c07440a;
P_0c07440a: /* original 2a68, guest PC 0x0c07440a */
if(!s->budget--) { s->failed_pc=0x0c07440au; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[6])==0)!=0);
goto P_0c07440c;
P_0c07440c: /* original 8900, guest PC 0x0c07440c */
if(!s->budget--) { s->failed_pc=0x0c07440cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074410; }
goto P_0c07440e;
P_0c07440e: /* original f680, guest PC 0x0c07440e */
if(!s->budget--) { s->failed_pc=0x0c07440eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[8],r[18],'+');
goto P_0c074410;
P_0c074410: /* original d641, guest PC 0x0c074410 */
if(!s->budget--) { s->failed_pc=0x0c074410u; return 0; }
r[6]=read(ram,0x0c074518u,4);
goto P_0c074412;
P_0c074412: /* original 6c43, guest PC 0x0c074412 */
if(!s->budget--) { s->failed_pc=0x0c074412u; return 0; }
r[12]=r[4];
goto P_0c074414;
P_0c074414: /* original 2c69, guest PC 0x0c074414 */
if(!s->budget--) { s->failed_pc=0x0c074414u; return 0; }
r[12]&=r[6];
goto P_0c074416;
P_0c074416: /* original 2cc8, guest PC 0x0c074416 */
if(!s->budget--) { s->failed_pc=0x0c074416u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c074418;
P_0c074418: /* original 8902, guest PC 0x0c074418 */
if(!s->budget--) { s->failed_pc=0x0c074418u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074420; }
goto P_0c07441a;
P_0c07441a: /* original 6243, guest PC 0x0c07441a */
if(!s->budget--) { s->failed_pc=0x0c07441au; return 0; }
r[2]=r[4];
goto P_0c07441c;
P_0c07441c: /* original 22b8, guest PC 0x0c07441c */
if(!s->budget--) { s->failed_pc=0x0c07441cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[11])==0)!=0);
goto P_0c07441e;
P_0c07441e: /* original 8b0b, guest PC 0x0c07441e */
if(!s->budget--) { s->failed_pc=0x0c07441eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074438; }
goto P_0c074420;
P_0c074420: /* original 6353, guest PC 0x0c074420 */
if(!s->budget--) { s->failed_pc=0x0c074420u; return 0; }
r[3]=r[5];
goto P_0c074422;
P_0c074422: /* original 2368, guest PC 0x0c074422 */
if(!s->budget--) { s->failed_pc=0x0c074422u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c074424;
P_0c074424: /* original 8909, guest PC 0x0c074424 */
if(!s->budget--) { s->failed_pc=0x0c074424u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07443a; }
goto P_0c074426;
P_0c074426: /* original 6253, guest PC 0x0c074426 */
if(!s->budget--) { s->failed_pc=0x0c074426u; return 0; }
r[2]=r[5];
goto P_0c074428;
P_0c074428: /* original 22b8, guest PC 0x0c074428 */
if(!s->budget--) { s->failed_pc=0x0c074428u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[11])==0)!=0);
goto P_0c07442a;
P_0c07442a: /* original 8b05, guest PC 0x0c07442a */
if(!s->budget--) { s->failed_pc=0x0c07442au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074438; }
goto P_0c07442c;
P_0c07442c: /* original 2cc8, guest PC 0x0c07442c */
if(!s->budget--) { s->failed_pc=0x0c07442cu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c07442e;
P_0c07442e: /* original 8904, guest PC 0x0c07442e */
if(!s->budget--) { s->failed_pc=0x0c07442eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07443a; }
goto P_0c074430;
P_0c074430: /* original 2658, guest PC 0x0c074430 */
if(!s->budget--) { s->failed_pc=0x0c074430u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[5])==0)!=0);
goto P_0c074432;
P_0c074432: /* original 8902, guest PC 0x0c074432 */
if(!s->budget--) { s->failed_pc=0x0c074432u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07443a; }
goto P_0c074434;
P_0c074434: /* original a001, guest PC 0x0c074434 */
if(!s->budget--) { s->failed_pc=0x0c074434u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[8],r[18],'+');
goto P_0c07443a;
P_0c074436: /* original f680, guest PC 0x0c074436 */
if(!s->budget--) { s->failed_pc=0x0c074436u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[8],r[18],'+');
goto P_0c074438;
P_0c074438: /* original f672, guest PC 0x0c074438 */
if(!s->budget--) { s->failed_pc=0x0c074438u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c07443a;
P_0c07443a: /* original c738, guest PC 0x0c07443a */
if(!s->budget--) { s->failed_pc=0x0c07443au; return 0; }
r[0]=code_base|0x0007451cu;
goto P_0c07443c;
P_0c07443c: /* original f808, guest PC 0x0c07443c */
if(!s->budget--) { s->failed_pc=0x0c07443cu; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c07443e;
P_0c07443e: /* original f865, guest PC 0x0c07443e */
if(!s->budget--) { s->failed_pc=0x0c07443eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[6]))!=0);
goto P_0c074440;
P_0c074440: /* original 8b00, guest PC 0x0c074440 */
if(!s->budget--) { s->failed_pc=0x0c074440u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074444; }
goto P_0c074442;
P_0c074442: /* original f68c, guest PC 0x0c074442 */
if(!s->budget--) { s->failed_pc=0x0c074442u; return 0; }
vf3_matrix_move(s,6,8);
goto P_0c074444;
P_0c074444: /* original f695, guest PC 0x0c074444 */
if(!s->budget--) { s->failed_pc=0x0c074444u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[9]))!=0);
goto P_0c074446;
P_0c074446: /* original 8b00, guest PC 0x0c074446 */
if(!s->budget--) { s->failed_pc=0x0c074446u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07444a; }
goto P_0c074448;
P_0c074448: /* original f69c, guest PC 0x0c074448 */
if(!s->budget--) { s->failed_pc=0x0c074448u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c07444a;
P_0c07444a: /* original f462, guest PC 0x0c07444a */
if(!s->budget--) { s->failed_pc=0x0c07444au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c07444c;
P_0c07444c: /* original 2788, guest PC 0x0c07444c */
if(!s->budget--) { s->failed_pc=0x0c07444cu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[8])==0)!=0);
goto P_0c07444e;
P_0c07444e: /* original 8f4d, guest PC 0x0c07444e */
if(!s->budget--) { s->failed_pc=0x0c07444eu; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
if(!cond) { goto P_0c0744ec; }
goto P_0c074452;
P_0c074450: /* original f562, guest PC 0x0c074450 */
if(!s->budget--) { s->failed_pc=0x0c074450u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c074452;
P_0c074452: /* original 2488, guest PC 0x0c074452 */
if(!s->budget--) { s->failed_pc=0x0c074452u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[8])==0)!=0);
goto P_0c074454;
P_0c074454: /* original 8909, guest PC 0x0c074454 */
if(!s->budget--) { s->failed_pc=0x0c074454u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07446a; }
goto P_0c074456;
P_0c074456: /* original 52f1, guest PC 0x0c074456 */
if(!s->budget--) { s->failed_pc=0x0c074456u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c074458;
P_0c074458: /* original d331, guest PC 0x0c074458 */
if(!s->budget--) { s->failed_pc=0x0c074458u; return 0; }
r[3]=read(ram,0x0c074520u,4);
goto P_0c07445a;
P_0c07445a: /* original 2238, guest PC 0x0c07445a */
if(!s->budget--) { s->failed_pc=0x0c07445au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07445c;
P_0c07445c: /* original 8902, guest PC 0x0c07445c */
if(!s->budget--) { s->failed_pc=0x0c07445cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074464; }
goto P_0c07445e;
P_0c07445e: /* original f472, guest PC 0x0c07445e */
if(!s->budget--) { s->failed_pc=0x0c07445eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c074460;
P_0c074460: /* original a044, guest PC 0x0c074460 */
if(!s->budget--) { s->failed_pc=0x0c074460u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'+');
goto P_0c0744ec;
P_0c074462: /* original f540, guest PC 0x0c074462 */
if(!s->budget--) { s->failed_pc=0x0c074462u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'+');
goto P_0c074464;
P_0c074464: /* original f540, guest PC 0x0c074464 */
if(!s->budget--) { s->failed_pc=0x0c074464u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'+');
goto P_0c074466;
P_0c074466: /* original a041, guest PC 0x0c074466 */
if(!s->budget--) { s->failed_pc=0x0c074466u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0744ec;
P_0c074468: /* original f4fc, guest PC 0x0c074468 */
if(!s->budget--) { s->failed_pc=0x0c074468u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c07446a;
P_0c07446a: /* original 2589, guest PC 0x0c07446a */
if(!s->budget--) { s->failed_pc=0x0c07446au; return 0; }
r[5]&=r[8];
goto P_0c07446c;
P_0c07446c: /* original 6353, guest PC 0x0c07446c */
if(!s->budget--) { s->failed_pc=0x0c07446cu; return 0; }
r[3]=r[5];
goto P_0c07446e;
P_0c07446e: /* original 2338, guest PC 0x0c07446e */
if(!s->budget--) { s->failed_pc=0x0c07446eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c074470;
P_0c074470: /* original 8d3c, guest PC 0x0c074470 */
if(!s->budget--) { s->failed_pc=0x0c074470u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[5],4);
if(cond) { goto P_0c0744ec; }
goto P_0c074474;
P_0c074472: /* original 2f52, guest PC 0x0c074472 */
if(!s->budget--) { s->failed_pc=0x0c074472u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c074474;
P_0c074474: /* original 52f4, guest PC 0x0c074474 */
if(!s->budget--) { s->failed_pc=0x0c074474u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c074476;
P_0c074476: /* original d32a, guest PC 0x0c074476 */
if(!s->budget--) { s->failed_pc=0x0c074476u; return 0; }
r[3]=read(ram,0x0c074520u,4);
goto P_0c074478;
P_0c074478: /* original 2239, guest PC 0x0c074478 */
if(!s->budget--) { s->failed_pc=0x0c074478u; return 0; }
r[2]&=r[3];
goto P_0c07447a;
P_0c07447a: /* original 2228, guest PC 0x0c07447a */
if(!s->budget--) { s->failed_pc=0x0c07447au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07447c;
P_0c07447c: /* original 8f03, guest PC 0x0c07447c */
if(!s->budget--) { s->failed_pc=0x0c07447cu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[2],4);
if(!cond) { goto P_0c074486; }
goto P_0c074480;
P_0c07447e: /* original 2f22, guest PC 0x0c07447e */
if(!s->budget--) { s->failed_pc=0x0c07447eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c074480;
P_0c074480: /* original f450, guest PC 0x0c074480 */
if(!s->budget--) { s->failed_pc=0x0c074480u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c074482;
P_0c074482: /* original a033, guest PC 0x0c074482 */
if(!s->budget--) { s->failed_pc=0x0c074482u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0744ec;
P_0c074484: /* original f5fc, guest PC 0x0c074484 */
if(!s->budget--) { s->failed_pc=0x0c074484u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c074486;
P_0c074486: /* original f572, guest PC 0x0c074486 */
if(!s->budget--) { s->failed_pc=0x0c074486u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c074488;
P_0c074488: /* original a030, guest PC 0x0c074488 */
if(!s->budget--) { s->failed_pc=0x0c074488u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c0744ec;
P_0c07448a: /* original f450, guest PC 0x0c07448a */
if(!s->budget--) { s->failed_pc=0x0c07448au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c07448c;
P_0c07448c: /* original 62c3, guest PC 0x0c07448c */
if(!s->budget--) { s->failed_pc=0x0c07448cu; return 0; }
r[2]=r[12];
goto P_0c07448e;
P_0c07448e: /* original 22ab, guest PC 0x0c07448e */
if(!s->budget--) { s->failed_pc=0x0c07448eu; return 0; }
r[2]|=r[10];
goto P_0c074490;
P_0c074490: /* original 1f21, guest PC 0x0c074490 */
if(!s->budget--) { s->failed_pc=0x0c074490u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c074492;
P_0c074492: /* original 2ac9, guest PC 0x0c074492 */
if(!s->budget--) { s->failed_pc=0x0c074492u; return 0; }
r[10]&=r[12];
goto P_0c074494;
P_0c074494: /* original d523, guest PC 0x0c074494 */
if(!s->budget--) { s->failed_pc=0x0c074494u; return 0; }
r[5]=read(ram,0x0c074524u,4);
goto P_0c074496;
P_0c074496: /* original 2258, guest PC 0x0c074496 */
if(!s->budget--) { s->failed_pc=0x0c074496u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c074498;
P_0c074498: /* original 8d0b, guest PC 0x0c074498 */
if(!s->budget--) { s->failed_pc=0x0c074498u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+16,r[10],4);
if(cond) { goto P_0c0744b2; }
goto P_0c07449c;
P_0c07449a: /* original 1fa4, guest PC 0x0c07449a */
if(!s->budget--) { s->failed_pc=0x0c07449au; return 0; }
write(ram,r[15]+16,r[10],4);
goto P_0c07449c;
P_0c07449c: /* original 51f4, guest PC 0x0c07449c */
if(!s->budget--) { s->failed_pc=0x0c07449cu; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c07449e;
P_0c07449e: /* original 2158, guest PC 0x0c07449e */
if(!s->budget--) { s->failed_pc=0x0c07449eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[5])==0)!=0);
goto P_0c0744a0;
P_0c0744a0: /* original 8b07, guest PC 0x0c0744a0 */
if(!s->budget--) { s->failed_pc=0x0c0744a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0744b2; }
goto P_0c0744a2;
P_0c0744a2: /* original 2c58, guest PC 0x0c0744a2 */
if(!s->budget--) { s->failed_pc=0x0c0744a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[5])==0)!=0);
goto P_0c0744a4;
P_0c0744a4: /* original 8d02, guest PC 0x0c0744a4 */
if(!s->budget--) { s->failed_pc=0x0c0744a4u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,6,7);
if(cond) { goto P_0c0744ac; }
goto P_0c0744a8;
P_0c0744a6: /* original f67c, guest PC 0x0c0744a6 */
if(!s->budget--) { s->failed_pc=0x0c0744a6u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c0744a8;
P_0c0744a8: /* original afee, guest PC 0x0c0744a8 */
if(!s->budget--) { s->failed_pc=0x0c0744a8u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c074488;
P_0c0744aa: /* original f562, guest PC 0x0c0744aa */
if(!s->budget--) { s->failed_pc=0x0c0744aau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c0744ac;
P_0c0744ac: /* original f462, guest PC 0x0c0744ac */
if(!s->budget--) { s->failed_pc=0x0c0744acu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0744ae;
P_0c0744ae: /* original a01d, guest PC 0x0c0744ae */
if(!s->budget--) { s->failed_pc=0x0c0744aeu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'+');
goto P_0c0744ec;
P_0c0744b0: /* original f540, guest PC 0x0c0744b0 */
if(!s->budget--) { s->failed_pc=0x0c0744b0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'+');
goto P_0c0744b2;
P_0c0744b2: /* original 6363, guest PC 0x0c0744b2 */
if(!s->budget--) { s->failed_pc=0x0c0744b2u; return 0; }
r[3]=r[6];
goto P_0c0744b4;
P_0c0744b4: /* original e504, guest PC 0x0c0744b4 */
if(!s->budget--) { s->failed_pc=0x0c0744b4u; return 0; }
r[5]=0x00000004u;
goto P_0c0744b6;
P_0c0744b6: /* original 2358, guest PC 0x0c0744b6 */
if(!s->budget--) { s->failed_pc=0x0c0744b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0744b8;
P_0c0744b8: /* original 890e, guest PC 0x0c0744b8 */
if(!s->budget--) { s->failed_pc=0x0c0744b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0744d8; }
goto P_0c0744ba;
P_0c0744ba: /* original 2758, guest PC 0x0c0744ba */
if(!s->budget--) { s->failed_pc=0x0c0744bau; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[5])==0)!=0);
goto P_0c0744bc;
P_0c0744bc: /* original 8902, guest PC 0x0c0744bc */
if(!s->budget--) { s->failed_pc=0x0c0744bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0744c4; }
goto P_0c0744be;
P_0c0744be: /* original f49c, guest PC 0x0c0744be */
if(!s->budget--) { s->failed_pc=0x0c0744beu; return 0; }
vf3_matrix_move(s,4,9);
goto P_0c0744c0;
P_0c0744c0: /* original a014, guest PC 0x0c0744c0 */
if(!s->budget--) { s->failed_pc=0x0c0744c0u; return 0; }
vf3_matrix_move(s,5,9);
goto P_0c0744ec;
P_0c0744c2: /* original f59c, guest PC 0x0c0744c2 */
if(!s->budget--) { s->failed_pc=0x0c0744c2u; return 0; }
vf3_matrix_move(s,5,9);
goto P_0c0744c4;
P_0c0744c4: /* original 2458, guest PC 0x0c0744c4 */
if(!s->budget--) { s->failed_pc=0x0c0744c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[5])==0)!=0);
goto P_0c0744c6;
P_0c0744c6: /* original c718, guest PC 0x0c0744c6 */
if(!s->budget--) { s->failed_pc=0x0c0744c6u; return 0; }
r[0]=code_base|0x00074528u;
goto P_0c0744c8;
P_0c0744c8: /* original 8d03, guest PC 0x0c0744c8 */
if(!s->budget--) { s->failed_pc=0x0c0744c8u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,7,r[0]);
if(cond) { goto P_0c0744d2; }
goto P_0c0744cc;
P_0c0744ca: /* original f708, guest PC 0x0c0744ca */
if(!s->budget--) { s->failed_pc=0x0c0744cau; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0744cc;
P_0c0744cc: /* original f472, guest PC 0x0c0744cc */
if(!s->budget--) { s->failed_pc=0x0c0744ccu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c0744ce;
P_0c0744ce: /* original a00d, guest PC 0x0c0744ce */
if(!s->budget--) { s->failed_pc=0x0c0744ceu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c0744ec;
P_0c0744d0: /* original f562, guest PC 0x0c0744d0 */
if(!s->budget--) { s->failed_pc=0x0c0744d0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c0744d2;
P_0c0744d2: /* original f462, guest PC 0x0c0744d2 */
if(!s->budget--) { s->failed_pc=0x0c0744d2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0744d4;
P_0c0744d4: /* original a00a, guest PC 0x0c0744d4 */
if(!s->budget--) { s->failed_pc=0x0c0744d4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c0744ec;
P_0c0744d6: /* original f572, guest PC 0x0c0744d6 */
if(!s->budget--) { s->failed_pc=0x0c0744d6u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c0744d8;
P_0c0744d8: /* original d414, guest PC 0x0c0744d8 */
if(!s->budget--) { s->failed_pc=0x0c0744d8u; return 0; }
r[4]=read(ram,0x0c07452cu,4);
goto P_0c0744da;
P_0c0744da: /* original 2648, guest PC 0x0c0744da */
if(!s->budget--) { s->failed_pc=0x0c0744dau; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[4])==0)!=0);
goto P_0c0744dc;
P_0c0744dc: /* original 8906, guest PC 0x0c0744dc */
if(!s->budget--) { s->failed_pc=0x0c0744dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0744ec; }
goto P_0c0744de;
P_0c0744de: /* original 2748, guest PC 0x0c0744de */
if(!s->budget--) { s->failed_pc=0x0c0744deu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[4])==0)!=0);
goto P_0c0744e0;
P_0c0744e0: /* original 8f02, guest PC 0x0c0744e0 */
if(!s->budget--) { s->failed_pc=0x0c0744e0u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,6,7);
if(!cond) { goto P_0c0744e8; }
goto P_0c0744e4;
P_0c0744e2: /* original f67c, guest PC 0x0c0744e2 */
if(!s->budget--) { s->failed_pc=0x0c0744e2u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c0744e4;
P_0c0744e4: /* original c712, guest PC 0x0c0744e4 */
if(!s->budget--) { s->failed_pc=0x0c0744e4u; return 0; }
r[0]=code_base|0x00074530u;
goto P_0c0744e6;
P_0c0744e6: /* original f608, guest PC 0x0c0744e6 */
if(!s->budget--) { s->failed_pc=0x0c0744e6u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0744e8;
P_0c0744e8: /* original f562, guest PC 0x0c0744e8 */
if(!s->budget--) { s->failed_pc=0x0c0744e8u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c0744ea;
P_0c0744ea: /* original f462, guest PC 0x0c0744ea */
if(!s->budget--) { s->failed_pc=0x0c0744eau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0744ec;
P_0c0744ec: /* original e038, guest PC 0x0c0744ec */
if(!s->budget--) { s->failed_pc=0x0c0744ecu; return 0; }
r[0]=0x00000038u;
goto P_0c0744ee;
P_0c0744ee: /* original 53fb, guest PC 0x0c0744ee */
if(!s->budget--) { s->failed_pc=0x0c0744eeu; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c0744f0;
P_0c0744f0: /* original fb96, guest PC 0x0c0744f0 */
if(!s->budget--) { s->failed_pc=0x0c0744f0u; return 0; }
vf3_matrix_load(s,ram,11,r[9]+r[0]);
goto P_0c0744f2;
P_0c0744f2: /* original e03c, guest PC 0x0c0744f2 */
if(!s->budget--) { s->failed_pc=0x0c0744f2u; return 0; }
r[0]=0x0000003cu;
goto P_0c0744f4;
P_0c0744f4: /* original f796, guest PC 0x0c0744f4 */
if(!s->budget--) { s->failed_pc=0x0c0744f4u; return 0; }
vf3_matrix_load(s,ram,7,r[9]+r[0]);
goto P_0c0744f6;
P_0c0744f6: /* original 23b8, guest PC 0x0c0744f6 */
if(!s->budget--) { s->failed_pc=0x0c0744f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c0744f8;
P_0c0744f8: /* original 891c, guest PC 0x0c0744f8 */
if(!s->budget--) { s->failed_pc=0x0c0744f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074534; }
goto P_0c0744fa;
P_0c0744fa: /* original f5ac, guest PC 0x0c0744fa */
if(!s->budget--) { s->failed_pc=0x0c0744fau; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c0744fc;
P_0c0744fc: /* original fa6c, guest PC 0x0c0744fc */
if(!s->budget--) { s->failed_pc=0x0c0744fcu; return 0; }
vf3_matrix_move(s,10,6);
goto P_0c0744fe;
P_0c0744fe: /* original fab2, guest PC 0x0c0744fe */
if(!s->budget--) { s->failed_pc=0x0c0744feu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[11],r[18],'*');
goto P_0c074500;
P_0c074500: /* original f49c, guest PC 0x0c074500 */
if(!s->budget--) { s->failed_pc=0x0c074500u; return 0; }
vf3_matrix_move(s,4,9);
goto P_0c074502;
P_0c074502: /* original f472, guest PC 0x0c074502 */
if(!s->budget--) { s->failed_pc=0x0c074502u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c074504;
P_0c074504: /* original f84d, guest PC 0x0c074504 */
if(!s->budget--) { s->failed_pc=0x0c074504u; return 0; }
fr[8]^=0x80000000u;
goto P_0c074506;
P_0c074506: /* original f54d, guest PC 0x0c074506 */
if(!s->budget--) { s->failed_pc=0x0c074506u; return 0; }
fr[5]^=0x80000000u;
goto P_0c074508;
P_0c074508: /* original a01a, guest PC 0x0c074508 */
if(!s->budget--) { s->failed_pc=0x0c074508u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c074540;
P_0c07450a: /* original f65c, guest PC 0x0c07450a */
if(!s->budget--) { s->failed_pc=0x0c07450au; return 0; }
vf3_matrix_move(s,6,5);
if(!vf3_matrix_family(0x0c07450cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07450cu; return 0; } return 1;
P_0c074534: /* original fa4c, guest PC 0x0c074534 */
if(!s->budget--) { s->failed_pc=0x0c074534u; return 0; }
vf3_matrix_move(s,10,4);
goto P_0c074536;
P_0c074536: /* original fab2, guest PC 0x0c074536 */
if(!s->budget--) { s->failed_pc=0x0c074536u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[11],r[18],'*');
goto P_0c074538;
P_0c074538: /* original f472, guest PC 0x0c074538 */
if(!s->budget--) { s->failed_pc=0x0c074538u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c07453a;
P_0c07453a: /* original f85c, guest PC 0x0c07453a */
if(!s->budget--) { s->failed_pc=0x0c07453au; return 0; }
vf3_matrix_move(s,8,5);
goto P_0c07453c;
P_0c07453c: /* original f84d, guest PC 0x0c07453c */
if(!s->budget--) { s->failed_pc=0x0c07453cu; return 0; }
fr[8]^=0x80000000u;
goto P_0c07453e;
P_0c07453e: /* original f68c, guest PC 0x0c07453e */
if(!s->budget--) { s->failed_pc=0x0c07453eu; return 0; }
vf3_matrix_move(s,6,8);
goto P_0c074540;
P_0c074540: /* original f58c, guest PC 0x0c074540 */
if(!s->budget--) { s->failed_pc=0x0c074540u; return 0; }
vf3_matrix_move(s,5,8);
goto P_0c074542;
P_0c074542: /* original f572, guest PC 0x0c074542 */
if(!s->budget--) { s->failed_pc=0x0c074542u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c074544;
P_0c074544: /* original f6b2, guest PC 0x0c074544 */
if(!s->budget--) { s->failed_pc=0x0c074544u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'*');
goto P_0c074546;
P_0c074546: /* original f7ec, guest PC 0x0c074546 */
if(!s->budget--) { s->failed_pc=0x0c074546u; return 0; }
vf3_matrix_move(s,7,14);
goto P_0c074548;
P_0c074548: /* original f7a2, guest PC 0x0c074548 */
if(!s->budget--) { s->failed_pc=0x0c074548u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[10],r[18],'*');
goto P_0c07454a;
P_0c07454a: /* original f8ec, guest PC 0x0c07454a */
if(!s->budget--) { s->failed_pc=0x0c07454au; return 0; }
vf3_matrix_move(s,8,14);
goto P_0c07454c;
P_0c07454c: /* original 9068, guest PC 0x0c07454c */
if(!s->budget--) { s->failed_pc=0x0c07454cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074620u,2);
goto P_0c07454e;
P_0c07454e: /* original f842, guest PC 0x0c07454e */
if(!s->budget--) { s->failed_pc=0x0c07454eu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'*');
goto P_0c074550;
P_0c074550: /* original f4ec, guest PC 0x0c074550 */
if(!s->budget--) { s->failed_pc=0x0c074550u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c074552;
P_0c074552: /* original f452, guest PC 0x0c074552 */
if(!s->budget--) { s->failed_pc=0x0c074552u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c074554;
P_0c074554: /* original f36c, guest PC 0x0c074554 */
if(!s->budget--) { s->failed_pc=0x0c074554u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c074556;
P_0c074556: /* original f6ec, guest PC 0x0c074556 */
if(!s->budget--) { s->failed_pc=0x0c074556u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c074558;
P_0c074558: /* original f632, guest PC 0x0c074558 */
if(!s->budget--) { s->failed_pc=0x0c074558u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c07455a;
P_0c07455a: /* original fd77, guest PC 0x0c07455a */
if(!s->budget--) { s->failed_pc=0x0c07455au; return 0; }
vf3_matrix_store(s,ram,7,r[13]+r[0]);
goto P_0c07455c;
P_0c07455c: /* original 7008, guest PC 0x0c07455c */
if(!s->budget--) { s->failed_pc=0x0c07455cu; return 0; }
r[0]+=0x00000008u;
goto P_0c07455e;
P_0c07455e: /* original fd87, guest PC 0x0c07455e */
if(!s->budget--) { s->failed_pc=0x0c07455eu; return 0; }
vf3_matrix_store(s,ram,8,r[13]+r[0]);
goto P_0c074560;
P_0c074560: /* original 70f8, guest PC 0x0c074560 */
if(!s->budget--) { s->failed_pc=0x0c074560u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c074562;
P_0c074562: /* original fe67, guest PC 0x0c074562 */
if(!s->budget--) { s->failed_pc=0x0c074562u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c074564;
P_0c074564: /* original 7008, guest PC 0x0c074564 */
if(!s->budget--) { s->failed_pc=0x0c074564u; return 0; }
r[0]+=0x00000008u;
goto P_0c074566;
P_0c074566: /* original a007, guest PC 0x0c074566 */
if(!s->budget--) { s->failed_pc=0x0c074566u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c074578;
P_0c074568: /* original fe47, guest PC 0x0c074568 */
if(!s->budget--) { s->failed_pc=0x0c074568u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c07456a;
P_0c07456a: /* original f6ec, guest PC 0x0c07456a */
if(!s->budget--) { s->failed_pc=0x0c07456au; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c07456c;
P_0c07456c: /* original f642, guest PC 0x0c07456c */
if(!s->budget--) { s->failed_pc=0x0c07456cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c07456e;
P_0c07456e: /* original f4ec, guest PC 0x0c07456e */
if(!s->budget--) { s->failed_pc=0x0c07456eu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c074570;
P_0c074570: /* original f452, guest PC 0x0c074570 */
if(!s->budget--) { s->failed_pc=0x0c074570u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c074572;
P_0c074572: /* original 9056, guest PC 0x0c074572 */
if(!s->budget--) { s->failed_pc=0x0c074572u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074622u,2);
goto P_0c074574;
P_0c074574: /* original fd67, guest PC 0x0c074574 */
if(!s->budget--) { s->failed_pc=0x0c074574u; return 0; }
vf3_matrix_store(s,ram,6,r[13]+r[0]);
goto P_0c074576;
P_0c074576: /* original fe47, guest PC 0x0c074576 */
if(!s->budget--) { s->failed_pc=0x0c074576u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c074578;
P_0c074578: /* original 7f3c, guest PC 0x0c074578 */
if(!s->budget--) { s->failed_pc=0x0c074578u; return 0; }
r[15]+=0x0000003cu;
goto P_0c07457a;
P_0c07457a: /* original 4f26, guest PC 0x0c07457a */
if(!s->budget--) { s->failed_pc=0x0c07457au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07457c;
P_0c07457c: /* original fdf9, guest PC 0x0c07457c */
if(!s->budget--) { s->failed_pc=0x0c07457cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07457e;
P_0c07457e: /* original fef9, guest PC 0x0c07457e */
if(!s->budget--) { s->failed_pc=0x0c07457eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c074580;
P_0c074580: /* original fff9, guest PC 0x0c074580 */
if(!s->budget--) { s->failed_pc=0x0c074580u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c074582;
P_0c074582: /* original 68f6, guest PC 0x0c074582 */
if(!s->budget--) { s->failed_pc=0x0c074582u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c074584;
P_0c074584: /* original 69f6, guest PC 0x0c074584 */
if(!s->budget--) { s->failed_pc=0x0c074584u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c074586;
P_0c074586: /* original 6af6, guest PC 0x0c074586 */
if(!s->budget--) { s->failed_pc=0x0c074586u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c074588;
P_0c074588: /* original 6bf6, guest PC 0x0c074588 */
if(!s->budget--) { s->failed_pc=0x0c074588u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07458a;
P_0c07458a: /* original 6cf6, guest PC 0x0c07458a */
if(!s->budget--) { s->failed_pc=0x0c07458au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07458c;
P_0c07458c: /* original 6df6, guest PC 0x0c07458c */
if(!s->budget--) { s->failed_pc=0x0c07458cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07458e;
P_0c07458e: /* original 000b, guest PC 0x0c07458e */
if(!s->budget--) { s->failed_pc=0x0c07458eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c074590: /* original 6ef6, guest PC 0x0c074590 */
if(!s->budget--) { s->failed_pc=0x0c074590u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c074592u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
