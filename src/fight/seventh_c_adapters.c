/* Static C ABI adapters. Generated with tools/oracle/translate_adapters.py.
 * Matrix operations are hand-written in matrix_family.c; unknown code fails.
 * Executed opcodes are checked against the untouched identity image. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <math.h>
#include <string.h>
#define read vf3_matrix_read
#define write vf3_matrix_write
static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }
static uint32_t truncate_float(uint32_t u) { double d=as_float(u); if(isnan(d) || d< -2147483648.0) return 0x80000000u; if(d>=2147483648.0) return 0x7fffffffu; return (uint32_t)(int32_t)d; }
static void divide_step(vf3_matrix_state*s,unsigned n,unsigned m) { uint32_t *r=s->v; unsigned oldq=(r[17]>>8)&1u,sign=(r[17]>>9)&1u,q=r[n]>>31; uint32_t divisor=r[m],shifted=(r[n]<<1)|(r[17]&1u); r[n]=oldq==sign?shifted-divisor:shifted+divisor; unsigned carry=oldq==sign?r[n]>shifted:r[n]<shifted; q^=carry^sign; r[17]=(r[17]&~0x101u)|(q<<8)|(q==sign); }
int vf3_seventh_c_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c040154u: goto P_0c040154;
case 0x0c040156u: goto P_0c040156;
case 0x0c040158u: goto P_0c040158;
case 0x0c04015au: goto P_0c04015a;
case 0x0c04015cu: goto P_0c04015c;
case 0x0c04015eu: goto P_0c04015e;
case 0x0c040160u: goto P_0c040160;
case 0x0c040162u: goto P_0c040162;
case 0x0c040164u: goto P_0c040164;
case 0x0c040166u: goto P_0c040166;
case 0x0c040168u: goto P_0c040168;
case 0x0c04016au: goto P_0c04016a;
case 0x0c04016cu: goto P_0c04016c;
case 0x0c04016eu: goto P_0c04016e;
case 0x0c040174u: goto P_0c040174;
case 0x0c040176u: goto P_0c040176;
case 0x0c040178u: goto P_0c040178;
case 0x0c04017au: goto P_0c04017a;
case 0x0c04017cu: goto P_0c04017c;
case 0x0c04017eu: goto P_0c04017e;
case 0x0c040180u: goto P_0c040180;
case 0x0c040182u: goto P_0c040182;
case 0x0c040184u: goto P_0c040184;
case 0x0c040186u: goto P_0c040186;
case 0x0c040188u: goto P_0c040188;
case 0x0c04018au: goto P_0c04018a;
case 0x0c04018cu: goto P_0c04018c;
case 0x0c04018eu: goto P_0c04018e;
case 0x0c040190u: goto P_0c040190;
case 0x0c040192u: goto P_0c040192;
case 0x0c040194u: goto P_0c040194;
case 0x0c040196u: goto P_0c040196;
case 0x0c040198u: goto P_0c040198;
case 0x0c04019au: goto P_0c04019a;
case 0x0c04019cu: goto P_0c04019c;
case 0x0c04019eu: goto P_0c04019e;
case 0x0c0401a0u: goto P_0c0401a0;
case 0x0c0401a2u: goto P_0c0401a2;
case 0x0c0401a4u: goto P_0c0401a4;
case 0x0c0401a6u: goto P_0c0401a6;
case 0x0c0401a8u: goto P_0c0401a8;
case 0x0c0401aau: goto P_0c0401aa;
case 0x0c0401acu: goto P_0c0401ac;
case 0x0c0401aeu: goto P_0c0401ae;
case 0x0c0401b0u: goto P_0c0401b0;
case 0x0c0401b2u: goto P_0c0401b2;
case 0x0c0401b4u: goto P_0c0401b4;
case 0x0c0401b6u: goto P_0c0401b6;
case 0x0c0401b8u: goto P_0c0401b8;
case 0x0c0401bau: goto P_0c0401ba;
case 0x0c0401bcu: goto P_0c0401bc;
case 0x0c0401beu: goto P_0c0401be;
case 0x0c0401c0u: goto P_0c0401c0;
case 0x0c0401c2u: goto P_0c0401c2;
case 0x0c0401c4u: goto P_0c0401c4;
case 0x0c0401c6u: goto P_0c0401c6;
case 0x0c0401c8u: goto P_0c0401c8;
case 0x0c0401cau: goto P_0c0401ca;
case 0x0c0401ccu: goto P_0c0401cc;
case 0x0c0401ceu: goto P_0c0401ce;
case 0x0c0401d0u: goto P_0c0401d0;
case 0x0c0401d2u: goto P_0c0401d2;
case 0x0c0401d4u: goto P_0c0401d4;
case 0x0c0401d6u: goto P_0c0401d6;
case 0x0c0401d8u: goto P_0c0401d8;
case 0x0c0401dau: goto P_0c0401da;
case 0x0c0401dcu: goto P_0c0401dc;
case 0x0c0401deu: goto P_0c0401de;
case 0x0c0401e0u: goto P_0c0401e0;
case 0x0c0401e2u: goto P_0c0401e2;
case 0x0c0401e4u: goto P_0c0401e4;
case 0x0c0401e6u: goto P_0c0401e6;
case 0x0c0401e8u: goto P_0c0401e8;
case 0x0c0401eau: goto P_0c0401ea;
case 0x0c0401ecu: goto P_0c0401ec;
case 0x0c0401eeu: goto P_0c0401ee;
case 0x0c0401f0u: goto P_0c0401f0;
case 0x0c0401f2u: goto P_0c0401f2;
case 0x0c0401f4u: goto P_0c0401f4;
case 0x0c0401f6u: goto P_0c0401f6;
case 0x0c0401f8u: goto P_0c0401f8;
case 0x0c0401fau: goto P_0c0401fa;
case 0x0c0401fcu: goto P_0c0401fc;
case 0x0c0401feu: goto P_0c0401fe;
case 0x0c040200u: goto P_0c040200;
case 0x0c040202u: goto P_0c040202;
case 0x0c040204u: goto P_0c040204;
case 0x0c040206u: goto P_0c040206;
case 0x0c040222u: goto P_0c040222;
case 0x0c040224u: goto P_0c040224;
case 0x0c040226u: goto P_0c040226;
case 0x0c040228u: goto P_0c040228;
case 0x0c04022au: goto P_0c04022a;
case 0x0c04022cu: goto P_0c04022c;
case 0x0c04022eu: goto P_0c04022e;
case 0x0c040230u: goto P_0c040230;
case 0x0c040232u: goto P_0c040232;
case 0x0c040234u: goto P_0c040234;
case 0x0c040236u: goto P_0c040236;
case 0x0c040238u: goto P_0c040238;
case 0x0c04023au: goto P_0c04023a;
case 0x0c04023cu: goto P_0c04023c;
case 0x0c04023eu: goto P_0c04023e;
case 0x0c040240u: goto P_0c040240;
case 0x0c040242u: goto P_0c040242;
case 0x0c040244u: goto P_0c040244;
case 0x0c040246u: goto P_0c040246;
case 0x0c040248u: goto P_0c040248;
case 0x0c04024au: goto P_0c04024a;
case 0x0c04024cu: goto P_0c04024c;
case 0x0c04024eu: goto P_0c04024e;
case 0x0c040250u: goto P_0c040250;
case 0x0c040252u: goto P_0c040252;
case 0x0c040254u: goto P_0c040254;
case 0x0c040256u: goto P_0c040256;
case 0x0c040258u: goto P_0c040258;
case 0x0c04025au: goto P_0c04025a;
case 0x0c04025cu: goto P_0c04025c;
case 0x0c04025eu: goto P_0c04025e;
case 0x0c040260u: goto P_0c040260;
case 0x0c040262u: goto P_0c040262;
case 0x0c040264u: goto P_0c040264;
case 0x0c040266u: goto P_0c040266;
case 0x0c040268u: goto P_0c040268;
case 0x0c04026au: goto P_0c04026a;
case 0x0c04026cu: goto P_0c04026c;
case 0x0c04026eu: goto P_0c04026e;
case 0x0c040270u: goto P_0c040270;
case 0x0c040272u: goto P_0c040272;
case 0x0c040274u: goto P_0c040274;
case 0x0c040276u: goto P_0c040276;
case 0x0c040288u: goto P_0c040288;
case 0x0c04028au: goto P_0c04028a;
case 0x0c04028cu: goto P_0c04028c;
case 0x0c04028eu: goto P_0c04028e;
case 0x0c040290u: goto P_0c040290;
case 0x0c040292u: goto P_0c040292;
case 0x0c040294u: goto P_0c040294;
case 0x0c040296u: goto P_0c040296;
case 0x0c040298u: goto P_0c040298;
case 0x0c04029au: goto P_0c04029a;
case 0x0c04029cu: goto P_0c04029c;
case 0x0c04029eu: goto P_0c04029e;
case 0x0c0402a0u: goto P_0c0402a0;
case 0x0c0402a2u: goto P_0c0402a2;
case 0x0c0402a4u: goto P_0c0402a4;
case 0x0c0402a6u: goto P_0c0402a6;
case 0x0c0402a8u: goto P_0c0402a8;
case 0x0c0402aau: goto P_0c0402aa;
case 0x0c0402acu: goto P_0c0402ac;
case 0x0c0402aeu: goto P_0c0402ae;
case 0x0c0402b0u: goto P_0c0402b0;
case 0x0c0402b2u: goto P_0c0402b2;
case 0x0c0402b4u: goto P_0c0402b4;
case 0x0c0402b6u: goto P_0c0402b6;
case 0x0c0402b8u: goto P_0c0402b8;
case 0x0c0402bau: goto P_0c0402ba;
case 0x0c0402bcu: goto P_0c0402bc;
case 0x0c0402beu: goto P_0c0402be;
case 0x0c0402c0u: goto P_0c0402c0;
case 0x0c0402c2u: goto P_0c0402c2;
case 0x0c0402c4u: goto P_0c0402c4;
case 0x0c0402c6u: goto P_0c0402c6;
case 0x0c0402c8u: goto P_0c0402c8;
case 0x0c0402cau: goto P_0c0402ca;
case 0x0c0402ccu: goto P_0c0402cc;
case 0x0c0402ceu: goto P_0c0402ce;
case 0x0c0402d0u: goto P_0c0402d0;
case 0x0c0402d2u: goto P_0c0402d2;
case 0x0c0402d4u: goto P_0c0402d4;
case 0x0c0402d6u: goto P_0c0402d6;
case 0x0c0402d8u: goto P_0c0402d8;
case 0x0c0402dau: goto P_0c0402da;
case 0x0c0402dcu: goto P_0c0402dc;
case 0x0c0402deu: goto P_0c0402de;
case 0x0c0402e0u: goto P_0c0402e0;
case 0x0c0402e2u: goto P_0c0402e2;
case 0x0c0402e4u: goto P_0c0402e4;
case 0x0c0402e6u: goto P_0c0402e6;
case 0x0c0402e8u: goto P_0c0402e8;
case 0x0c0402eau: goto P_0c0402ea;
case 0x0c0402ecu: goto P_0c0402ec;
case 0x0c0402eeu: goto P_0c0402ee;
case 0x0c0402f0u: goto P_0c0402f0;
case 0x0c0402f2u: goto P_0c0402f2;
case 0x0c0402f4u: goto P_0c0402f4;
case 0x0c0402f6u: goto P_0c0402f6;
case 0x0c0402f8u: goto P_0c0402f8;
case 0x0c040308u: goto P_0c040308;
case 0x0c04030au: goto P_0c04030a;
case 0x0c04030cu: goto P_0c04030c;
case 0x0c04030eu: goto P_0c04030e;
case 0x0c040310u: goto P_0c040310;
case 0x0c040312u: goto P_0c040312;
case 0x0c040314u: goto P_0c040314;
case 0x0c040316u: goto P_0c040316;
case 0x0c040318u: goto P_0c040318;
case 0x0c04031au: goto P_0c04031a;
case 0x0c04031cu: goto P_0c04031c;
case 0x0c04031eu: goto P_0c04031e;
case 0x0c040320u: goto P_0c040320;
case 0x0c040322u: goto P_0c040322;
case 0x0c040324u: goto P_0c040324;
case 0x0c040326u: goto P_0c040326;
case 0x0c040328u: goto P_0c040328;
case 0x0c04032au: goto P_0c04032a;
case 0x0c04032cu: goto P_0c04032c;
case 0x0c04032eu: goto P_0c04032e;
case 0x0c040330u: goto P_0c040330;
case 0x0c040332u: goto P_0c040332;
case 0x0c040334u: goto P_0c040334;
case 0x0c040336u: goto P_0c040336;
case 0x0c040338u: goto P_0c040338;
case 0x0c04033au: goto P_0c04033a;
case 0x0c04033cu: goto P_0c04033c;
case 0x0c04033eu: goto P_0c04033e;
case 0x0c040340u: goto P_0c040340;
case 0x0c040342u: goto P_0c040342;
case 0x0c040344u: goto P_0c040344;
case 0x0c040346u: goto P_0c040346;
case 0x0c040348u: goto P_0c040348;
case 0x0c04034au: goto P_0c04034a;
case 0x0c04034cu: goto P_0c04034c;
case 0x0c04034eu: goto P_0c04034e;
case 0x0c040350u: goto P_0c040350;
case 0x0c040352u: goto P_0c040352;
case 0x0c040354u: goto P_0c040354;
case 0x0c040356u: goto P_0c040356;
case 0x0c040358u: goto P_0c040358;
case 0x0c04035au: goto P_0c04035a;
case 0x0c04035cu: goto P_0c04035c;
case 0x0c04035eu: goto P_0c04035e;
case 0x0c040360u: goto P_0c040360;
case 0x0c040362u: goto P_0c040362;
case 0x0c0403c0u: goto P_0c0403c0;
case 0x0c0403c2u: goto P_0c0403c2;
case 0x0c0403c4u: goto P_0c0403c4;
case 0x0c0403c6u: goto P_0c0403c6;
case 0x0c0403c8u: goto P_0c0403c8;
case 0x0c0403cau: goto P_0c0403ca;
case 0x0c0403ccu: goto P_0c0403cc;
case 0x0c0403ceu: goto P_0c0403ce;
case 0x0c0403d0u: goto P_0c0403d0;
case 0x0c0403d2u: goto P_0c0403d2;
case 0x0c0403d4u: goto P_0c0403d4;
case 0x0c0403d6u: goto P_0c0403d6;
case 0x0c0403d8u: goto P_0c0403d8;
case 0x0c0403dau: goto P_0c0403da;
case 0x0c0403dcu: goto P_0c0403dc;
case 0x0c0403deu: goto P_0c0403de;
case 0x0c0403e0u: goto P_0c0403e0;
case 0x0c0403e2u: goto P_0c0403e2;
case 0x0c0403e4u: goto P_0c0403e4;
case 0x0c0403e6u: goto P_0c0403e6;
case 0x0c0403e8u: goto P_0c0403e8;
case 0x0c0403eau: goto P_0c0403ea;
case 0x0c0403ecu: goto P_0c0403ec;
case 0x0c0403eeu: goto P_0c0403ee;
case 0x0c0403f0u: goto P_0c0403f0;
case 0x0c0403f2u: goto P_0c0403f2;
case 0x0c0403f4u: goto P_0c0403f4;
case 0x0c0403f6u: goto P_0c0403f6;
case 0x0c0403f8u: goto P_0c0403f8;
case 0x0c0403fau: goto P_0c0403fa;
case 0x0c0403fcu: goto P_0c0403fc;
case 0x0c0403feu: goto P_0c0403fe;
case 0x0c040400u: goto P_0c040400;
case 0x0c040410u: goto P_0c040410;
case 0x0c040412u: goto P_0c040412;
case 0x0c040414u: goto P_0c040414;
case 0x0c040416u: goto P_0c040416;
case 0x0c040418u: goto P_0c040418;
case 0x0c04041au: goto P_0c04041a;
case 0x0c04041cu: goto P_0c04041c;
case 0x0c04041eu: goto P_0c04041e;
case 0x0c040420u: goto P_0c040420;
case 0x0c040422u: goto P_0c040422;
case 0x0c040424u: goto P_0c040424;
case 0x0c040426u: goto P_0c040426;
case 0x0c040428u: goto P_0c040428;
case 0x0c04042au: goto P_0c04042a;
case 0x0c04042cu: goto P_0c04042c;
case 0x0c04042eu: goto P_0c04042e;
case 0x0c040430u: goto P_0c040430;
case 0x0c040432u: goto P_0c040432;
case 0x0c040434u: goto P_0c040434;
case 0x0c040436u: goto P_0c040436;
case 0x0c040438u: goto P_0c040438;
case 0x0c04043au: goto P_0c04043a;
case 0x0c04043cu: goto P_0c04043c;
case 0x0c04043eu: goto P_0c04043e;
case 0x0c040440u: goto P_0c040440;
case 0x0c040442u: goto P_0c040442;
case 0x0c040444u: goto P_0c040444;
case 0x0c040446u: goto P_0c040446;
case 0x0c040448u: goto P_0c040448;
case 0x0c04044au: goto P_0c04044a;
case 0x0c04044cu: goto P_0c04044c;
case 0x0c04044eu: goto P_0c04044e;
case 0x0c040450u: goto P_0c040450;
case 0x0c040452u: goto P_0c040452;
case 0x0c040454u: goto P_0c040454;
case 0x0c040456u: goto P_0c040456;
case 0x0c040458u: goto P_0c040458;
case 0x0c04045au: goto P_0c04045a;
case 0x0c04045cu: goto P_0c04045c;
case 0x0c04045eu: goto P_0c04045e;
case 0x0c040460u: goto P_0c040460;
case 0x0c040462u: goto P_0c040462;
case 0x0c040464u: goto P_0c040464;
case 0x0c040466u: goto P_0c040466;
case 0x0c040468u: goto P_0c040468;
case 0x0c04046au: goto P_0c04046a;
case 0x0c04046cu: goto P_0c04046c;
case 0x0c04046eu: goto P_0c04046e;
case 0x0c040470u: goto P_0c040470;
case 0x0c040472u: goto P_0c040472;
case 0x0c040474u: goto P_0c040474;
case 0x0c040476u: goto P_0c040476;
case 0x0c040478u: goto P_0c040478;
case 0x0c04047au: goto P_0c04047a;
case 0x0c04047cu: goto P_0c04047c;
case 0x0c04047eu: goto P_0c04047e;
case 0x0c040480u: goto P_0c040480;
case 0x0c040482u: goto P_0c040482;
case 0x0c040b7eu: goto P_0c040b7e;
case 0x0c040b80u: goto P_0c040b80;
case 0x0c040b82u: goto P_0c040b82;
case 0x0c040b84u: goto P_0c040b84;
case 0x0c040b86u: goto P_0c040b86;
case 0x0c040b88u: goto P_0c040b88;
case 0x0c040b8au: goto P_0c040b8a;
case 0x0c040b8cu: goto P_0c040b8c;
case 0x0c040b8eu: goto P_0c040b8e;
case 0x0c040b90u: goto P_0c040b90;
case 0x0c040b92u: goto P_0c040b92;
case 0x0c040b94u: goto P_0c040b94;
case 0x0c040b96u: goto P_0c040b96;
case 0x0c040b98u: goto P_0c040b98;
case 0x0c040b9au: goto P_0c040b9a;
case 0x0c040b9cu: goto P_0c040b9c;
case 0x0c040b9eu: goto P_0c040b9e;
case 0x0c040ba0u: goto P_0c040ba0;
case 0x0c040ba2u: goto P_0c040ba2;
case 0x0c040ba4u: goto P_0c040ba4;
case 0x0c040ba6u: goto P_0c040ba6;
case 0x0c040ba8u: goto P_0c040ba8;
case 0x0c040baau: goto P_0c040baa;
case 0x0c040bacu: goto P_0c040bac;
case 0x0c040baeu: goto P_0c040bae;
case 0x0c040bb0u: goto P_0c040bb0;
case 0x0c040bb2u: goto P_0c040bb2;
case 0x0c040bb4u: goto P_0c040bb4;
case 0x0c040bb6u: goto P_0c040bb6;
case 0x0c040bb8u: goto P_0c040bb8;
case 0x0c040bbau: goto P_0c040bba;
case 0x0c040bbcu: goto P_0c040bbc;
case 0x0c040bbeu: goto P_0c040bbe;
case 0x0c040bc0u: goto P_0c040bc0;
case 0x0c040bc2u: goto P_0c040bc2;
case 0x0c040bc4u: goto P_0c040bc4;
case 0x0c040bc6u: goto P_0c040bc6;
case 0x0c040bc8u: goto P_0c040bc8;
case 0x0c040bcau: goto P_0c040bca;
case 0x0c040bccu: goto P_0c040bcc;
case 0x0c040bceu: goto P_0c040bce;
case 0x0c040bd0u: goto P_0c040bd0;
case 0x0c040bd2u: goto P_0c040bd2;
case 0x0c040bd4u: goto P_0c040bd4;
case 0x0c040bd6u: goto P_0c040bd6;
case 0x0c040bd8u: goto P_0c040bd8;
case 0x0c040bdau: goto P_0c040bda;
case 0x0c040bdcu: goto P_0c040bdc;
case 0x0c040bdeu: goto P_0c040bde;
case 0x0c040be0u: goto P_0c040be0;
case 0x0c040be2u: goto P_0c040be2;
case 0x0c040be4u: goto P_0c040be4;
case 0x0c040be6u: goto P_0c040be6;
case 0x0c040be8u: goto P_0c040be8;
case 0x0c040beau: goto P_0c040bea;
case 0x0c040becu: goto P_0c040bec;
case 0x0c040beeu: goto P_0c040bee;
case 0x0c040bf0u: goto P_0c040bf0;
case 0x0c040bf2u: goto P_0c040bf2;
case 0x0c040bf4u: goto P_0c040bf4;
case 0x0c040bf6u: goto P_0c040bf6;
case 0x0c040c10u: goto P_0c040c10;
case 0x0c040c12u: goto P_0c040c12;
case 0x0c040c14u: goto P_0c040c14;
case 0x0c040c16u: goto P_0c040c16;
case 0x0c040c18u: goto P_0c040c18;
case 0x0c040c1au: goto P_0c040c1a;
case 0x0c040c1cu: goto P_0c040c1c;
case 0x0c040c1eu: goto P_0c040c1e;
case 0x0c040c20u: goto P_0c040c20;
case 0x0c040c22u: goto P_0c040c22;
case 0x0c040c24u: goto P_0c040c24;
case 0x0c040c26u: goto P_0c040c26;
case 0x0c040c28u: goto P_0c040c28;
case 0x0c040c2au: goto P_0c040c2a;
case 0x0c040c2cu: goto P_0c040c2c;
case 0x0c040c2eu: goto P_0c040c2e;
case 0x0c040c30u: goto P_0c040c30;
case 0x0c040c32u: goto P_0c040c32;
case 0x0c040c34u: goto P_0c040c34;
case 0x0c040c36u: goto P_0c040c36;
case 0x0c040c38u: goto P_0c040c38;
case 0x0c040c3au: goto P_0c040c3a;
case 0x0c040c3cu: goto P_0c040c3c;
case 0x0c040c3eu: goto P_0c040c3e;
case 0x0c040c40u: goto P_0c040c40;
case 0x0c040c42u: goto P_0c040c42;
case 0x0c040c44u: goto P_0c040c44;
case 0x0c040c46u: goto P_0c040c46;
case 0x0c040c48u: goto P_0c040c48;
case 0x0c040c4au: goto P_0c040c4a;
case 0x0c040c4cu: goto P_0c040c4c;
case 0x0c040c4eu: goto P_0c040c4e;
case 0x0c040c50u: goto P_0c040c50;
case 0x0c040c52u: goto P_0c040c52;
case 0x0c040c54u: goto P_0c040c54;
case 0x0c040c56u: goto P_0c040c56;
case 0x0c040c58u: goto P_0c040c58;
case 0x0c040c5au: goto P_0c040c5a;
case 0x0c040c5cu: goto P_0c040c5c;
case 0x0c040c5eu: goto P_0c040c5e;
case 0x0c040c60u: goto P_0c040c60;
case 0x0c040c62u: goto P_0c040c62;
case 0x0c040c64u: goto P_0c040c64;
case 0x0c040c66u: goto P_0c040c66;
case 0x0c040c68u: goto P_0c040c68;
case 0x0c040c6au: goto P_0c040c6a;
case 0x0c040c6cu: goto P_0c040c6c;
case 0x0c040c6eu: goto P_0c040c6e;
case 0x0c040c70u: goto P_0c040c70;
case 0x0c040c72u: goto P_0c040c72;
case 0x0c040c74u: goto P_0c040c74;
case 0x0c040c76u: goto P_0c040c76;
case 0x0c040f1eu: goto P_0c040f1e;
case 0x0c040f20u: goto P_0c040f20;
case 0x0c040f22u: goto P_0c040f22;
case 0x0c040f24u: goto P_0c040f24;
case 0x0c040f26u: goto P_0c040f26;
case 0x0c040f28u: goto P_0c040f28;
case 0x0c040f2au: goto P_0c040f2a;
case 0x0c040f2cu: goto P_0c040f2c;
case 0x0c040f2eu: goto P_0c040f2e;
case 0x0c040f30u: goto P_0c040f30;
case 0x0c040f32u: goto P_0c040f32;
case 0x0c040f34u: goto P_0c040f34;
case 0x0c040f36u: goto P_0c040f36;
case 0x0c040f38u: goto P_0c040f38;
case 0x0c040f3au: goto P_0c040f3a;
case 0x0c040f3cu: goto P_0c040f3c;
case 0x0c040f3eu: goto P_0c040f3e;
case 0x0c040f40u: goto P_0c040f40;
case 0x0c040f42u: goto P_0c040f42;
case 0x0c040f44u: goto P_0c040f44;
case 0x0c040f46u: goto P_0c040f46;
case 0x0c040f48u: goto P_0c040f48;
case 0x0c040f4au: goto P_0c040f4a;
case 0x0c040f4cu: goto P_0c040f4c;
case 0x0c040f4eu: goto P_0c040f4e;
case 0x0c040f50u: goto P_0c040f50;
case 0x0c040f52u: goto P_0c040f52;
case 0x0c040f54u: goto P_0c040f54;
case 0x0c040f56u: goto P_0c040f56;
case 0x0c040f58u: goto P_0c040f58;
case 0x0c040f5au: goto P_0c040f5a;
case 0x0c040f5cu: goto P_0c040f5c;
case 0x0c040f5eu: goto P_0c040f5e;
case 0x0c040f60u: goto P_0c040f60;
case 0x0c040f62u: goto P_0c040f62;
case 0x0c040f64u: goto P_0c040f64;
case 0x0c040f66u: goto P_0c040f66;
case 0x0c060d1eu: goto P_0c060d1e;
case 0x0c060d20u: goto P_0c060d20;
case 0x0c060d22u: goto P_0c060d22;
case 0x0c060d24u: goto P_0c060d24;
case 0x0c060d26u: goto P_0c060d26;
case 0x0c060d28u: goto P_0c060d28;
case 0x0c060d2au: goto P_0c060d2a;
case 0x0c060d2cu: goto P_0c060d2c;
case 0x0c060d2eu: goto P_0c060d2e;
case 0x0c060d30u: goto P_0c060d30;
case 0x0c060d32u: goto P_0c060d32;
case 0x0c060d34u: goto P_0c060d34;
case 0x0c060d36u: goto P_0c060d36;
case 0x0c060d38u: goto P_0c060d38;
case 0x0c060d3au: goto P_0c060d3a;
case 0x0c060d3cu: goto P_0c060d3c;
case 0x0c060d3eu: goto P_0c060d3e;
case 0x0c060d40u: goto P_0c060d40;
case 0x0c060d42u: goto P_0c060d42;
case 0x0c060d44u: goto P_0c060d44;
case 0x0c060d78u: goto P_0c060d78;
case 0x0c060d7au: goto P_0c060d7a;
case 0x0c060d7cu: goto P_0c060d7c;
case 0x0c060d7eu: goto P_0c060d7e;
case 0x0c060d80u: goto P_0c060d80;
case 0x0c060d82u: goto P_0c060d82;
case 0x0c060d84u: goto P_0c060d84;
case 0x0c060d86u: goto P_0c060d86;
case 0x0c060d88u: goto P_0c060d88;
case 0x0c060d8au: goto P_0c060d8a;
case 0x0c060d8cu: goto P_0c060d8c;
case 0x0c060d8eu: goto P_0c060d8e;
case 0x0c060d90u: goto P_0c060d90;
case 0x0c060d92u: goto P_0c060d92;
case 0x0c060d94u: goto P_0c060d94;
case 0x0c060d96u: goto P_0c060d96;
case 0x0c060d98u: goto P_0c060d98;
case 0x0c060d9au: goto P_0c060d9a;
case 0x0c060d9cu: goto P_0c060d9c;
case 0x0c060d9eu: goto P_0c060d9e;
case 0x0c060da0u: goto P_0c060da0;
case 0x0c060da2u: goto P_0c060da2;
case 0x0c060da4u: goto P_0c060da4;
case 0x0c060da6u: goto P_0c060da6;
case 0x0c060da8u: goto P_0c060da8;
case 0x0c060daau: goto P_0c060daa;
case 0x0c060dacu: goto P_0c060dac;
case 0x0c060daeu: goto P_0c060dae;
case 0x0c060db0u: goto P_0c060db0;
case 0x0c060db2u: goto P_0c060db2;
case 0x0c060db4u: goto P_0c060db4;
case 0x0c060db6u: goto P_0c060db6;
case 0x0c060db8u: goto P_0c060db8;
case 0x0c060dbau: goto P_0c060dba;
case 0x0c060dbcu: goto P_0c060dbc;
case 0x0c060dbeu: goto P_0c060dbe;
case 0x0c060dc0u: goto P_0c060dc0;
case 0x0c060dc2u: goto P_0c060dc2;
case 0x0c060dc4u: goto P_0c060dc4;
case 0x0c060dc6u: goto P_0c060dc6;
case 0x0c060dc8u: goto P_0c060dc8;
case 0x0c060dcau: goto P_0c060dca;
case 0x0c060dccu: goto P_0c060dcc;
case 0x0c060dceu: goto P_0c060dce;
case 0x0c060dd0u: goto P_0c060dd0;
case 0x0c060dd2u: goto P_0c060dd2;
case 0x0c060dd4u: goto P_0c060dd4;
case 0x0c060dd6u: goto P_0c060dd6;
case 0x0c060dd8u: goto P_0c060dd8;
case 0x0c060ddau: goto P_0c060dda;
case 0x0c060ddcu: goto P_0c060ddc;
case 0x0c060ddeu: goto P_0c060dde;
case 0x0c060de0u: goto P_0c060de0;
case 0x0c060de2u: goto P_0c060de2;
case 0x0c060de4u: goto P_0c060de4;
case 0x0c060de6u: goto P_0c060de6;
case 0x0c060de8u: goto P_0c060de8;
case 0x0c060deau: goto P_0c060dea;
case 0x0c060decu: goto P_0c060dec;
case 0x0c060deeu: goto P_0c060dee;
case 0x0c060df0u: goto P_0c060df0;
case 0x0c060df2u: goto P_0c060df2;
case 0x0c060df4u: goto P_0c060df4;
case 0x0c060df6u: goto P_0c060df6;
case 0x0c060df8u: goto P_0c060df8;
case 0x0c060dfau: goto P_0c060dfa;
case 0x0c060dfcu: goto P_0c060dfc;
case 0x0c060dfeu: goto P_0c060dfe;
case 0x0c060e00u: goto P_0c060e00;
case 0x0c060e02u: goto P_0c060e02;
case 0x0c060e04u: goto P_0c060e04;
case 0x0c060e06u: goto P_0c060e06;
case 0x0c060e08u: goto P_0c060e08;
case 0x0c060e0au: goto P_0c060e0a;
case 0x0c060e0cu: goto P_0c060e0c;
case 0x0c060e0eu: goto P_0c060e0e;
case 0x0c060e10u: goto P_0c060e10;
case 0x0c060e12u: goto P_0c060e12;
case 0x0c060e14u: goto P_0c060e14;
case 0x0c060e16u: goto P_0c060e16;
case 0x0c060e18u: goto P_0c060e18;
case 0x0c060e1au: goto P_0c060e1a;
case 0x0c060e1cu: goto P_0c060e1c;
case 0x0c060e1eu: goto P_0c060e1e;
case 0x0c060e20u: goto P_0c060e20;
case 0x0c060e22u: goto P_0c060e22;
case 0x0c060e24u: goto P_0c060e24;
case 0x0c062490u: goto P_0c062490;
case 0x0c062492u: goto P_0c062492;
case 0x0c062494u: goto P_0c062494;
case 0x0c062496u: goto P_0c062496;
case 0x0c062498u: goto P_0c062498;
case 0x0c06249au: goto P_0c06249a;
case 0x0c06249cu: goto P_0c06249c;
case 0x0c06249eu: goto P_0c06249e;
case 0x0c0624a0u: goto P_0c0624a0;
case 0x0c0624a2u: goto P_0c0624a2;
case 0x0c0624a4u: goto P_0c0624a4;
case 0x0c0624a6u: goto P_0c0624a6;
case 0x0c0624a8u: goto P_0c0624a8;
case 0x0c0624aau: goto P_0c0624aa;
case 0x0c0624acu: goto P_0c0624ac;
case 0x0c0624aeu: goto P_0c0624ae;
case 0x0c0624b0u: goto P_0c0624b0;
case 0x0c0624b2u: goto P_0c0624b2;
case 0x0c0624b4u: goto P_0c0624b4;
case 0x0c0624b6u: goto P_0c0624b6;
case 0x0c0624b8u: goto P_0c0624b8;
case 0x0c0624bau: goto P_0c0624ba;
case 0x0c0624bcu: goto P_0c0624bc;
case 0x0c0624beu: goto P_0c0624be;
case 0x0c0624c0u: goto P_0c0624c0;
case 0x0c0624c2u: goto P_0c0624c2;
case 0x0c0624c4u: goto P_0c0624c4;
case 0x0c0624c6u: goto P_0c0624c6;
case 0x0c0624c8u: goto P_0c0624c8;
case 0x0c0624cau: goto P_0c0624ca;
case 0x0c0624ccu: goto P_0c0624cc;
case 0x0c0624ceu: goto P_0c0624ce;
case 0x0c0624d0u: goto P_0c0624d0;
case 0x0c0624d2u: goto P_0c0624d2;
case 0x0c0624d4u: goto P_0c0624d4;
case 0x0c0624d6u: goto P_0c0624d6;
case 0x0c0624d8u: goto P_0c0624d8;
case 0x0c0624dau: goto P_0c0624da;
case 0x0c0624dcu: goto P_0c0624dc;
case 0x0c0624deu: goto P_0c0624de;
case 0x0c0624e0u: goto P_0c0624e0;
case 0x0c0624e2u: goto P_0c0624e2;
case 0x0c0624e4u: goto P_0c0624e4;
case 0x0c0624e6u: goto P_0c0624e6;
case 0x0c0624e8u: goto P_0c0624e8;
case 0x0c0624eau: goto P_0c0624ea;
case 0x0c0624ecu: goto P_0c0624ec;
case 0x0c0624eeu: goto P_0c0624ee;
case 0x0c0624f0u: goto P_0c0624f0;
case 0x0c0624f2u: goto P_0c0624f2;
case 0x0c0624f4u: goto P_0c0624f4;
case 0x0c0624f6u: goto P_0c0624f6;
case 0x0c0624f8u: goto P_0c0624f8;
case 0x0c0624fau: goto P_0c0624fa;
case 0x0c0624fcu: goto P_0c0624fc;
case 0x0c0624feu: goto P_0c0624fe;
case 0x0c062500u: goto P_0c062500;
case 0x0c062502u: goto P_0c062502;
case 0x0c062504u: goto P_0c062504;
case 0x0c062506u: goto P_0c062506;
case 0x0c062508u: goto P_0c062508;
case 0x0c06250au: goto P_0c06250a;
case 0x0c06250cu: goto P_0c06250c;
case 0x0c06250eu: goto P_0c06250e;
case 0x0c062510u: goto P_0c062510;
case 0x0c062512u: goto P_0c062512;
case 0x0c062514u: goto P_0c062514;
case 0x0c062516u: goto P_0c062516;
case 0x0c062518u: goto P_0c062518;
case 0x0c06251au: goto P_0c06251a;
case 0x0c06251cu: goto P_0c06251c;
case 0x0c06251eu: goto P_0c06251e;
case 0x0c062520u: goto P_0c062520;
case 0x0c062522u: goto P_0c062522;
case 0x0c062524u: goto P_0c062524;
case 0x0c062526u: goto P_0c062526;
case 0x0c062528u: goto P_0c062528;
case 0x0c06252au: goto P_0c06252a;
case 0x0c06252cu: goto P_0c06252c;
case 0x0c06252eu: goto P_0c06252e;
case 0x0c062530u: goto P_0c062530;
case 0x0c062532u: goto P_0c062532;
case 0x0c062534u: goto P_0c062534;
case 0x0c062536u: goto P_0c062536;
case 0x0c062538u: goto P_0c062538;
case 0x0c06253au: goto P_0c06253a;
case 0x0c06253cu: goto P_0c06253c;
case 0x0c06253eu: goto P_0c06253e;
case 0x0c062540u: goto P_0c062540;
case 0x0c062542u: goto P_0c062542;
case 0x0c062544u: goto P_0c062544;
case 0x0c062546u: goto P_0c062546;
case 0x0c062548u: goto P_0c062548;
case 0x0c06254au: goto P_0c06254a;
case 0x0c06254cu: goto P_0c06254c;
case 0x0c06254eu: goto P_0c06254e;
case 0x0c062550u: goto P_0c062550;
case 0x0c062552u: goto P_0c062552;
case 0x0c062554u: goto P_0c062554;
case 0x0c062556u: goto P_0c062556;
case 0x0c062558u: goto P_0c062558;
case 0x0c06255au: goto P_0c06255a;
case 0x0c06255cu: goto P_0c06255c;
case 0x0c06255eu: goto P_0c06255e;
case 0x0c062560u: goto P_0c062560;
case 0x0c062562u: goto P_0c062562;
case 0x0c062564u: goto P_0c062564;
case 0x0c062566u: goto P_0c062566;
case 0x0c062568u: goto P_0c062568;
case 0x0c06256au: goto P_0c06256a;
case 0x0c06256cu: goto P_0c06256c;
case 0x0c06256eu: goto P_0c06256e;
case 0x0c062570u: goto P_0c062570;
case 0x0c062572u: goto P_0c062572;
case 0x0c062574u: goto P_0c062574;
case 0x0c062576u: goto P_0c062576;
case 0x0c062578u: goto P_0c062578;
case 0x0c06257au: goto P_0c06257a;
case 0x0c06257cu: goto P_0c06257c;
case 0x0c06257eu: goto P_0c06257e;
case 0x0c062580u: goto P_0c062580;
case 0x0c062582u: goto P_0c062582;
case 0x0c062584u: goto P_0c062584;
case 0x0c062586u: goto P_0c062586;
case 0x0c062588u: goto P_0c062588;
case 0x0c0625a0u: goto P_0c0625a0;
case 0x0c0625a2u: goto P_0c0625a2;
case 0x0c0625a4u: goto P_0c0625a4;
case 0x0c0625a6u: goto P_0c0625a6;
case 0x0c0625a8u: goto P_0c0625a8;
case 0x0c0625aau: goto P_0c0625aa;
case 0x0c0625acu: goto P_0c0625ac;
case 0x0c0625aeu: goto P_0c0625ae;
case 0x0c0625b0u: goto P_0c0625b0;
case 0x0c0625b2u: goto P_0c0625b2;
case 0x0c0625b4u: goto P_0c0625b4;
case 0x0c0625b6u: goto P_0c0625b6;
case 0x0c0625b8u: goto P_0c0625b8;
case 0x0c0625bau: goto P_0c0625ba;
case 0x0c0625bcu: goto P_0c0625bc;
case 0x0c0625beu: goto P_0c0625be;
case 0x0c0625c0u: goto P_0c0625c0;
case 0x0c0625c2u: goto P_0c0625c2;
case 0x0c0625c4u: goto P_0c0625c4;
case 0x0c0625c6u: goto P_0c0625c6;
case 0x0c0625c8u: goto P_0c0625c8;
case 0x0c0625cau: goto P_0c0625ca;
case 0x0c0625ccu: goto P_0c0625cc;
case 0x0c0625ceu: goto P_0c0625ce;
case 0x0c0625d0u: goto P_0c0625d0;
case 0x0c0625d2u: goto P_0c0625d2;
case 0x0c0625d4u: goto P_0c0625d4;
case 0x0c0625d6u: goto P_0c0625d6;
case 0x0c0625d8u: goto P_0c0625d8;
case 0x0c0625dau: goto P_0c0625da;
case 0x0c0625dcu: goto P_0c0625dc;
case 0x0c0625deu: goto P_0c0625de;
case 0x0c0625e0u: goto P_0c0625e0;
case 0x0c0625e2u: goto P_0c0625e2;
case 0x0c0625e4u: goto P_0c0625e4;
case 0x0c0625e6u: goto P_0c0625e6;
case 0x0c0625e8u: goto P_0c0625e8;
case 0x0c0625eau: goto P_0c0625ea;
case 0x0c0625ecu: goto P_0c0625ec;
case 0x0c0625eeu: goto P_0c0625ee;
case 0x0c0625f0u: goto P_0c0625f0;
case 0x0c0625f2u: goto P_0c0625f2;
case 0x0c0625f4u: goto P_0c0625f4;
case 0x0c0625f6u: goto P_0c0625f6;
case 0x0c0625f8u: goto P_0c0625f8;
case 0x0c0625fau: goto P_0c0625fa;
case 0x0c0625fcu: goto P_0c0625fc;
case 0x0c0625feu: goto P_0c0625fe;
case 0x0c062600u: goto P_0c062600;
case 0x0c062602u: goto P_0c062602;
case 0x0c0626c0u: goto P_0c0626c0;
case 0x0c0626c2u: goto P_0c0626c2;
case 0x0c0626c4u: goto P_0c0626c4;
case 0x0c0626c6u: goto P_0c0626c6;
case 0x0c0626c8u: goto P_0c0626c8;
case 0x0c0626cau: goto P_0c0626ca;
case 0x0c0626ccu: goto P_0c0626cc;
case 0x0c0626ceu: goto P_0c0626ce;
case 0x0c0626d0u: goto P_0c0626d0;
case 0x0c0626d2u: goto P_0c0626d2;
case 0x0c0626d4u: goto P_0c0626d4;
case 0x0c0626d6u: goto P_0c0626d6;
case 0x0c0626d8u: goto P_0c0626d8;
case 0x0c0626dau: goto P_0c0626da;
case 0x0c0626dcu: goto P_0c0626dc;
case 0x0c0626deu: goto P_0c0626de;
case 0x0c0626e0u: goto P_0c0626e0;
case 0x0c0626e2u: goto P_0c0626e2;
case 0x0c0626e4u: goto P_0c0626e4;
case 0x0c0626e6u: goto P_0c0626e6;
case 0x0c0626e8u: goto P_0c0626e8;
case 0x0c0626eau: goto P_0c0626ea;
case 0x0c0626ecu: goto P_0c0626ec;
case 0x0c0626eeu: goto P_0c0626ee;
case 0x0c0626f0u: goto P_0c0626f0;
case 0x0c0626f2u: goto P_0c0626f2;
case 0x0c0626f4u: goto P_0c0626f4;
case 0x0c0626f6u: goto P_0c0626f6;
case 0x0c0626f8u: goto P_0c0626f8;
case 0x0c0626fau: goto P_0c0626fa;
case 0x0c0626fcu: goto P_0c0626fc;
case 0x0c0626feu: goto P_0c0626fe;
case 0x0c062700u: goto P_0c062700;
case 0x0c062702u: goto P_0c062702;
case 0x0c062704u: goto P_0c062704;
case 0x0c062706u: goto P_0c062706;
case 0x0c062708u: goto P_0c062708;
case 0x0c06270au: goto P_0c06270a;
case 0x0c06270cu: goto P_0c06270c;
case 0x0c06270eu: goto P_0c06270e;
case 0x0c062710u: goto P_0c062710;
case 0x0c062712u: goto P_0c062712;
case 0x0c062714u: goto P_0c062714;
case 0x0c062716u: goto P_0c062716;
case 0x0c062718u: goto P_0c062718;
case 0x0c06271au: goto P_0c06271a;
case 0x0c06271cu: goto P_0c06271c;
case 0x0c06271eu: goto P_0c06271e;
case 0x0c062720u: goto P_0c062720;
case 0x0c062722u: goto P_0c062722;
case 0x0c062724u: goto P_0c062724;
case 0x0c062726u: goto P_0c062726;
case 0x0c062728u: goto P_0c062728;
case 0x0c06272au: goto P_0c06272a;
case 0x0c06272cu: goto P_0c06272c;
case 0x0c06272eu: goto P_0c06272e;
case 0x0c062730u: goto P_0c062730;
case 0x0c062732u: goto P_0c062732;
case 0x0c062734u: goto P_0c062734;
case 0x0c062736u: goto P_0c062736;
case 0x0c062738u: goto P_0c062738;
case 0x0c06273au: goto P_0c06273a;
case 0x0c06273cu: goto P_0c06273c;
case 0x0c06273eu: goto P_0c06273e;
case 0x0c062740u: goto P_0c062740;
case 0x0c062742u: goto P_0c062742;
case 0x0c062744u: goto P_0c062744;
case 0x0c062746u: goto P_0c062746;
case 0x0c062748u: goto P_0c062748;
case 0x0c06274au: goto P_0c06274a;
case 0x0c06274cu: goto P_0c06274c;
case 0x0c06274eu: goto P_0c06274e;
case 0x0c062750u: goto P_0c062750;
case 0x0c062752u: goto P_0c062752;
case 0x0c062754u: goto P_0c062754;
case 0x0c062756u: goto P_0c062756;
case 0x0c062758u: goto P_0c062758;
case 0x0c06275au: goto P_0c06275a;
case 0x0c06275cu: goto P_0c06275c;
case 0x0c06275eu: goto P_0c06275e;
case 0x0c062760u: goto P_0c062760;
case 0x0c062762u: goto P_0c062762;
case 0x0c062764u: goto P_0c062764;
case 0x0c062766u: goto P_0c062766;
case 0x0c062768u: goto P_0c062768;
case 0x0c06276au: goto P_0c06276a;
case 0x0c06276cu: goto P_0c06276c;
case 0x0c06276eu: goto P_0c06276e;
case 0x0c062770u: goto P_0c062770;
case 0x0c062772u: goto P_0c062772;
case 0x0c062774u: goto P_0c062774;
case 0x0c062776u: goto P_0c062776;
case 0x0c062778u: goto P_0c062778;
case 0x0c06277au: goto P_0c06277a;
case 0x0c06277cu: goto P_0c06277c;
case 0x0c06277eu: goto P_0c06277e;
case 0x0c062780u: goto P_0c062780;
case 0x0c062782u: goto P_0c062782;
case 0x0c062784u: goto P_0c062784;
case 0x0c062786u: goto P_0c062786;
case 0x0c062788u: goto P_0c062788;
case 0x0c06278au: goto P_0c06278a;
case 0x0c06278cu: goto P_0c06278c;
case 0x0c0627a0u: goto P_0c0627a0;
case 0x0c0627a2u: goto P_0c0627a2;
case 0x0c0627a4u: goto P_0c0627a4;
case 0x0c0627a6u: goto P_0c0627a6;
case 0x0c0627a8u: goto P_0c0627a8;
case 0x0c0627aau: goto P_0c0627aa;
case 0x0c0627acu: goto P_0c0627ac;
case 0x0c0627aeu: goto P_0c0627ae;
case 0x0c0627b0u: goto P_0c0627b0;
case 0x0c0627b2u: goto P_0c0627b2;
case 0x0c0627b4u: goto P_0c0627b4;
case 0x0c0627b6u: goto P_0c0627b6;
case 0x0c0627b8u: goto P_0c0627b8;
case 0x0c0627bau: goto P_0c0627ba;
case 0x0c0627bcu: goto P_0c0627bc;
case 0x0c0627beu: goto P_0c0627be;
case 0x0c0627c0u: goto P_0c0627c0;
case 0x0c0627c2u: goto P_0c0627c2;
case 0x0c0627c4u: goto P_0c0627c4;
case 0x0c0627c6u: goto P_0c0627c6;
case 0x0c0627c8u: goto P_0c0627c8;
case 0x0c0627cau: goto P_0c0627ca;
case 0x0c0627ccu: goto P_0c0627cc;
case 0x0c0627ceu: goto P_0c0627ce;
case 0x0c0627d0u: goto P_0c0627d0;
case 0x0c0627d2u: goto P_0c0627d2;
case 0x0c0627d4u: goto P_0c0627d4;
case 0x0c0627d6u: goto P_0c0627d6;
case 0x0c0627d8u: goto P_0c0627d8;
case 0x0c0627dau: goto P_0c0627da;
case 0x0c0627dcu: goto P_0c0627dc;
case 0x0c0627deu: goto P_0c0627de;
case 0x0c0627e0u: goto P_0c0627e0;
case 0x0c0627e2u: goto P_0c0627e2;
case 0x0c0627e4u: goto P_0c0627e4;
case 0x0c0627e6u: goto P_0c0627e6;
case 0x0c0627e8u: goto P_0c0627e8;
case 0x0c0627eau: goto P_0c0627ea;
case 0x0c0627ecu: goto P_0c0627ec;
case 0x0c0627eeu: goto P_0c0627ee;
case 0x0c0627f0u: goto P_0c0627f0;
case 0x0c0627f2u: goto P_0c0627f2;
case 0x0c0627f4u: goto P_0c0627f4;
case 0x0c0627f6u: goto P_0c0627f6;
case 0x0c0627f8u: goto P_0c0627f8;
case 0x0c0627fau: goto P_0c0627fa;
case 0x0c0627fcu: goto P_0c0627fc;
case 0x0c0627feu: goto P_0c0627fe;
case 0x0c062800u: goto P_0c062800;
case 0x0c062802u: goto P_0c062802;
case 0x0c062804u: goto P_0c062804;
case 0x0c062806u: goto P_0c062806;
case 0x0c062808u: goto P_0c062808;
case 0x0c06280au: goto P_0c06280a;
case 0x0c06280cu: goto P_0c06280c;
case 0x0c06280eu: goto P_0c06280e;
case 0x0c062810u: goto P_0c062810;
case 0x0c062812u: goto P_0c062812;
case 0x0c062814u: goto P_0c062814;
case 0x0c062816u: goto P_0c062816;
case 0x0c062818u: goto P_0c062818;
case 0x0c06281au: goto P_0c06281a;
case 0x0c06281cu: goto P_0c06281c;
case 0x0c06281eu: goto P_0c06281e;
case 0x0c062820u: goto P_0c062820;
case 0x0c062822u: goto P_0c062822;
case 0x0c062824u: goto P_0c062824;
case 0x0c062826u: goto P_0c062826;
case 0x0c062828u: goto P_0c062828;
case 0x0c06282au: goto P_0c06282a;
case 0x0c06282cu: goto P_0c06282c;
case 0x0c06282eu: goto P_0c06282e;
case 0x0c062830u: goto P_0c062830;
case 0x0c062832u: goto P_0c062832;
case 0x0c062834u: goto P_0c062834;
case 0x0c062836u: goto P_0c062836;
case 0x0c062838u: goto P_0c062838;
case 0x0c06283au: goto P_0c06283a;
case 0x0c06283cu: goto P_0c06283c;
case 0x0c06283eu: goto P_0c06283e;
case 0x0c062840u: goto P_0c062840;
case 0x0c062842u: goto P_0c062842;
case 0x0c062844u: goto P_0c062844;
case 0x0c062846u: goto P_0c062846;
case 0x0c062848u: goto P_0c062848;
case 0x0c06284au: goto P_0c06284a;
case 0x0c06284cu: goto P_0c06284c;
case 0x0c06284eu: goto P_0c06284e;
case 0x0c062850u: goto P_0c062850;
case 0x0c062852u: goto P_0c062852;
case 0x0c062854u: goto P_0c062854;
case 0x0c062856u: goto P_0c062856;
case 0x0c062858u: goto P_0c062858;
case 0x0c06285au: goto P_0c06285a;
case 0x0c06285cu: goto P_0c06285c;
case 0x0c06285eu: goto P_0c06285e;
case 0x0c062860u: goto P_0c062860;
case 0x0c062862u: goto P_0c062862;
case 0x0c062864u: goto P_0c062864;
case 0x0c062866u: goto P_0c062866;
case 0x0c062868u: goto P_0c062868;
case 0x0c06286au: goto P_0c06286a;
case 0x0c06286cu: goto P_0c06286c;
case 0x0c06286eu: goto P_0c06286e;
case 0x0c062870u: goto P_0c062870;
case 0x0c062872u: goto P_0c062872;
case 0x0c062874u: goto P_0c062874;
case 0x0c062876u: goto P_0c062876;
case 0x0c062878u: goto P_0c062878;
case 0x0c06287au: goto P_0c06287a;
case 0x0c06287cu: goto P_0c06287c;
case 0x0c06287eu: goto P_0c06287e;
case 0x0c062880u: goto P_0c062880;
case 0x0c062882u: goto P_0c062882;
case 0x0c062884u: goto P_0c062884;
case 0x0c062886u: goto P_0c062886;
case 0x0c062888u: goto P_0c062888;
case 0x0c06288au: goto P_0c06288a;
case 0x0c062e7eu: goto P_0c062e7e;
case 0x0c062e80u: goto P_0c062e80;
case 0x0c062e82u: goto P_0c062e82;
case 0x0c062e84u: goto P_0c062e84;
case 0x0c062e86u: goto P_0c062e86;
case 0x0c062e88u: goto P_0c062e88;
case 0x0c062e8au: goto P_0c062e8a;
case 0x0c062e8cu: goto P_0c062e8c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c040154: /* original 7fe0, guest PC 0x0c040154 */
if(!s->budget--) { s->failed_pc=0x0c040154u; return 0; }
r[15]+=0xffffffe0u;
goto P_0c040156;
P_0c040156: /* original 1f47, guest PC 0x0c040156 */
if(!s->budget--) { s->failed_pc=0x0c040156u; return 0; }
write(ram,r[15]+28,r[4],4);
goto P_0c040158;
P_0c040158: /* original 1f56, guest PC 0x0c040158 */
if(!s->budget--) { s->failed_pc=0x0c040158u; return 0; }
write(ram,r[15]+24,r[5],4);
goto P_0c04015a;
P_0c04015a: /* original 53f6, guest PC 0x0c04015a */
if(!s->budget--) { s->failed_pc=0x0c04015au; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c04015c;
P_0c04015c: /* original 4311, guest PC 0x0c04015c */
if(!s->budget--) { s->failed_pc=0x0c04015cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c04015e;
P_0c04015e: /* original 8b03, guest PC 0x0c04015e */
if(!s->budget--) { s->failed_pc=0x0c04015eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040168; }
goto P_0c040160;
P_0c040160: /* original e108, guest PC 0x0c040160 */
if(!s->budget--) { s->failed_pc=0x0c040160u; return 0; }
r[1]=0x00000008u;
goto P_0c040162;
P_0c040162: /* original 52f6, guest PC 0x0c040162 */
if(!s->budget--) { s->failed_pc=0x0c040162u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c040164;
P_0c040164: /* original 3213, guest PC 0x0c040164 */
if(!s->budget--) { s->failed_pc=0x0c040164u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[1])!=0);
goto P_0c040166;
P_0c040166: /* original 8b05, guest PC 0x0c040166 */
if(!s->budget--) { s->failed_pc=0x0c040166u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040174; }
goto P_0c040168;
P_0c040168: /* original e0ff, guest PC 0x0c040168 */
if(!s->budget--) { s->failed_pc=0x0c040168u; return 0; }
r[0]=0xffffffffu;
goto P_0c04016a;
P_0c04016a: /* original 7f20, guest PC 0x0c04016a */
if(!s->budget--) { s->failed_pc=0x0c04016au; return 0; }
r[15]+=0x00000020u;
goto P_0c04016c;
P_0c04016c: /* original 000b, guest PC 0x0c04016c */
if(!s->budget--) { s->failed_pc=0x0c04016cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c04016e: /* original 0009, guest PC 0x0c04016e */
if(!s->budget--) { s->failed_pc=0x0c04016eu; return 0; }
return vf3_matrix_family(0x0c040170u,s,ram);
P_0c040174: /* original 52f7, guest PC 0x0c040174 */
if(!s->budget--) { s->failed_pc=0x0c040174u; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c040176;
P_0c040176: /* original 1f21, guest PC 0x0c040176 */
if(!s->budget--) { s->failed_pc=0x0c040176u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c040178;
P_0c040178: /* original d323, guest PC 0x0c040178 */
if(!s->budget--) { s->failed_pc=0x0c040178u; return 0; }
r[3]=read(ram,0x0c040208u,4);
goto P_0c04017a;
P_0c04017a: /* original 2f32, guest PC 0x0c04017a */
if(!s->budget--) { s->failed_pc=0x0c04017au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c04017c;
P_0c04017c: /* original e200, guest PC 0x0c04017c */
if(!s->budget--) { s->failed_pc=0x0c04017cu; return 0; }
r[2]=0x00000000u;
goto P_0c04017e;
P_0c04017e: /* original 1f23, guest PC 0x0c04017e */
if(!s->budget--) { s->failed_pc=0x0c04017eu; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c040180;
P_0c040180: /* original a013, guest PC 0x0c040180 */
if(!s->budget--) { s->failed_pc=0x0c040180u; return 0; }
goto P_0c0401aa;
P_0c040182: /* original 0009, guest PC 0x0c040182 */
if(!s->budget--) { s->failed_pc=0x0c040182u; return 0; }
goto P_0c040184;
P_0c040184: /* original 51f1, guest PC 0x0c040184 */
if(!s->budget--) { s->failed_pc=0x0c040184u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c040186;
P_0c040186: /* original 7101, guest PC 0x0c040186 */
if(!s->budget--) { s->failed_pc=0x0c040186u; return 0; }
r[1]+=0x00000001u;
goto P_0c040188;
P_0c040188: /* original 1f11, guest PC 0x0c040188 */
if(!s->budget--) { s->failed_pc=0x0c040188u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c04018a;
P_0c04018a: /* original 71ff, guest PC 0x0c04018a */
if(!s->budget--) { s->failed_pc=0x0c04018au; return 0; }
r[1]+=0xffffffffu;
goto P_0c04018c;
P_0c04018c: /* original 6310, guest PC 0x0c04018c */
if(!s->budget--) { s->failed_pc=0x0c04018cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[3]=tmp;
goto P_0c04018e;
P_0c04018e: /* original 62f2, guest PC 0x0c04018e */
if(!s->budget--) { s->failed_pc=0x0c04018eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c040190;
P_0c040190: /* original 7201, guest PC 0x0c040190 */
if(!s->budget--) { s->failed_pc=0x0c040190u; return 0; }
r[2]+=0x00000001u;
goto P_0c040192;
P_0c040192: /* original 2f22, guest PC 0x0c040192 */
if(!s->budget--) { s->failed_pc=0x0c040192u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c040194;
P_0c040194: /* original 72ff, guest PC 0x0c040194 */
if(!s->budget--) { s->failed_pc=0x0c040194u; return 0; }
r[2]+=0xffffffffu;
goto P_0c040196;
P_0c040196: /* original 6120, guest PC 0x0c040196 */
if(!s->budget--) { s->failed_pc=0x0c040196u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c040198;
P_0c040198: /* original 3310, guest PC 0x0c040198 */
if(!s->budget--) { s->failed_pc=0x0c040198u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c04019a;
P_0c04019a: /* original 8903, guest PC 0x0c04019a */
if(!s->budget--) { s->failed_pc=0x0c04019au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0401a4; }
goto P_0c04019c;
P_0c04019c: /* original e0fe, guest PC 0x0c04019c */
if(!s->budget--) { s->failed_pc=0x0c04019cu; return 0; }
r[0]=0xfffffffeu;
goto P_0c04019e;
P_0c04019e: /* original 7f20, guest PC 0x0c04019e */
if(!s->budget--) { s->failed_pc=0x0c04019eu; return 0; }
r[15]+=0x00000020u;
goto P_0c0401a0;
P_0c0401a0: /* original 000b, guest PC 0x0c0401a0 */
if(!s->budget--) { s->failed_pc=0x0c0401a0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0401a2: /* original 0009, guest PC 0x0c0401a2 */
if(!s->budget--) { s->failed_pc=0x0c0401a2u; return 0; }
goto P_0c0401a4;
P_0c0401a4: /* original 52f3, guest PC 0x0c0401a4 */
if(!s->budget--) { s->failed_pc=0x0c0401a4u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0401a6;
P_0c0401a6: /* original 7201, guest PC 0x0c0401a6 */
if(!s->budget--) { s->failed_pc=0x0c0401a6u; return 0; }
r[2]+=0x00000001u;
goto P_0c0401a8;
P_0c0401a8: /* original 1f23, guest PC 0x0c0401a8 */
if(!s->budget--) { s->failed_pc=0x0c0401a8u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0401aa;
P_0c0401aa: /* original e304, guest PC 0x0c0401aa */
if(!s->budget--) { s->failed_pc=0x0c0401aau; return 0; }
r[3]=0x00000004u;
goto P_0c0401ac;
P_0c0401ac: /* original 51f3, guest PC 0x0c0401ac */
if(!s->budget--) { s->failed_pc=0x0c0401acu; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c0401ae;
P_0c0401ae: /* original 3133, guest PC 0x0c0401ae */
if(!s->budget--) { s->failed_pc=0x0c0401aeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c0401b0;
P_0c0401b0: /* original 8be8, guest PC 0x0c0401b0 */
if(!s->budget--) { s->failed_pc=0x0c0401b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040184; }
goto P_0c0401b2;
P_0c0401b2: /* original 50f6, guest PC 0x0c0401b2 */
if(!s->budget--) { s->failed_pc=0x0c0401b2u; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c0401b4;
P_0c0401b4: /* original 6303, guest PC 0x0c0401b4 */
if(!s->budget--) { s->failed_pc=0x0c0401b4u; return 0; }
r[3]=r[0];
goto P_0c0401b6;
P_0c0401b6: /* original 4000, guest PC 0x0c0401b6 */
if(!s->budget--) { s->failed_pc=0x0c0401b6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0401b8;
P_0c0401b8: /* original 303c, guest PC 0x0c0401b8 */
if(!s->budget--) { s->failed_pc=0x0c0401b8u; return 0; }
r[0]+=r[3];
goto P_0c0401ba;
P_0c0401ba: /* original 4008, guest PC 0x0c0401ba */
if(!s->budget--) { s->failed_pc=0x0c0401bau; return 0; }
r[0]<<=2;
goto P_0c0401bc;
P_0c0401bc: /* original 600e, guest PC 0x0c0401bc */
if(!s->budget--) { s->failed_pc=0x0c0401bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c0401be;
P_0c0401be: /* original d113, guest PC 0x0c0401be */
if(!s->budget--) { s->failed_pc=0x0c0401beu; return 0; }
r[1]=read(ram,0x0c04020cu,4);
goto P_0c0401c0;
P_0c0401c0: /* original 001e, guest PC 0x0c0401c0 */
if(!s->budget--) { s->failed_pc=0x0c0401c0u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c0401c2;
P_0c0401c2: /* original 88ff, guest PC 0x0c0401c2 */
if(!s->budget--) { s->failed_pc=0x0c0401c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0401c4;
P_0c0401c4: /* original 8903, guest PC 0x0c0401c4 */
if(!s->budget--) { s->failed_pc=0x0c0401c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0401ce; }
goto P_0c0401c6;
P_0c0401c6: /* original e0fd, guest PC 0x0c0401c6 */
if(!s->budget--) { s->failed_pc=0x0c0401c6u; return 0; }
r[0]=0xfffffffdu;
goto P_0c0401c8;
P_0c0401c8: /* original 7f20, guest PC 0x0c0401c8 */
if(!s->budget--) { s->failed_pc=0x0c0401c8u; return 0; }
r[15]+=0x00000020u;
goto P_0c0401ca;
P_0c0401ca: /* original 000b, guest PC 0x0c0401ca */
if(!s->budget--) { s->failed_pc=0x0c0401cau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0401cc: /* original 0009, guest PC 0x0c0401cc */
if(!s->budget--) { s->failed_pc=0x0c0401ccu; return 0; }
goto P_0c0401ce;
P_0c0401ce: /* original 52f7, guest PC 0x0c0401ce */
if(!s->budget--) { s->failed_pc=0x0c0401ceu; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c0401d0;
P_0c0401d0: /* original 5322, guest PC 0x0c0401d0 */
if(!s->budget--) { s->failed_pc=0x0c0401d0u; return 0; }
r[3]=read(ram,r[2]+8,4);
goto P_0c0401d2;
P_0c0401d2: /* original 1f34, guest PC 0x0c0401d2 */
if(!s->budget--) { s->failed_pc=0x0c0401d2u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0401d4;
P_0c0401d4: /* original d30e, guest PC 0x0c0401d4 */
if(!s->budget--) { s->failed_pc=0x0c0401d4u; return 0; }
r[3]=read(ram,0x0c040210u,4);
goto P_0c0401d6;
P_0c0401d6: /* original 6132, guest PC 0x0c0401d6 */
if(!s->budget--) { s->failed_pc=0x0c0401d6u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0401d8;
P_0c0401d8: /* original 1f15, guest PC 0x0c0401d8 */
if(!s->budget--) { s->failed_pc=0x0c0401d8u; return 0; }
write(ram,r[15]+20,r[1],4);
goto P_0c0401da;
P_0c0401da: /* original 51f4, guest PC 0x0c0401da */
if(!s->budget--) { s->failed_pc=0x0c0401dau; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c0401dc;
P_0c0401dc: /* original d20d, guest PC 0x0c0401dc */
if(!s->budget--) { s->failed_pc=0x0c0401dcu; return 0; }
r[2]=read(ram,0x0c040214u,4);
goto P_0c0401de;
P_0c0401de: /* original 6022, guest PC 0x0c0401de */
if(!s->budget--) { s->failed_pc=0x0c0401deu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0401e0;
P_0c0401e0: /* original 301c, guest PC 0x0c0401e0 */
if(!s->budget--) { s->failed_pc=0x0c0401e0u; return 0; }
r[0]+=r[1];
goto P_0c0401e2;
P_0c0401e2: /* original 52f5, guest PC 0x0c0401e2 */
if(!s->budget--) { s->failed_pc=0x0c0401e2u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c0401e4;
P_0c0401e4: /* original 3027, guest PC 0x0c0401e4 */
if(!s->budget--) { s->failed_pc=0x0c0401e4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>(int32_t)r[2])!=0);
goto P_0c0401e6;
P_0c0401e6: /* original 8b03, guest PC 0x0c0401e6 */
if(!s->budget--) { s->failed_pc=0x0c0401e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0401f0; }
goto P_0c0401e8;
P_0c0401e8: /* original e0fc, guest PC 0x0c0401e8 */
if(!s->budget--) { s->failed_pc=0x0c0401e8u; return 0; }
r[0]=0xfffffffcu;
goto P_0c0401ea;
P_0c0401ea: /* original 7f20, guest PC 0x0c0401ea */
if(!s->budget--) { s->failed_pc=0x0c0401eau; return 0; }
r[15]+=0x00000020u;
goto P_0c0401ec;
P_0c0401ec: /* original 000b, guest PC 0x0c0401ec */
if(!s->budget--) { s->failed_pc=0x0c0401ecu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0401ee: /* original 0009, guest PC 0x0c0401ee */
if(!s->budget--) { s->failed_pc=0x0c0401eeu; return 0; }
goto P_0c0401f0;
P_0c0401f0: /* original d209, guest PC 0x0c0401f0 */
if(!s->budget--) { s->failed_pc=0x0c0401f0u; return 0; }
r[2]=read(ram,0x0c040218u,4);
goto P_0c0401f2;
P_0c0401f2: /* original 6322, guest PC 0x0c0401f2 */
if(!s->budget--) { s->failed_pc=0x0c0401f2u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0401f4;
P_0c0401f4: /* original 2338, guest PC 0x0c0401f4 */
if(!s->budget--) { s->failed_pc=0x0c0401f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0401f6;
P_0c0401f6: /* original 8903, guest PC 0x0c0401f6 */
if(!s->budget--) { s->failed_pc=0x0c0401f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040200; }
goto P_0c0401f8;
P_0c0401f8: /* original e0fb, guest PC 0x0c0401f8 */
if(!s->budget--) { s->failed_pc=0x0c0401f8u; return 0; }
r[0]=0xfffffffbu;
goto P_0c0401fa;
P_0c0401fa: /* original 7f20, guest PC 0x0c0401fa */
if(!s->budget--) { s->failed_pc=0x0c0401fau; return 0; }
r[15]+=0x00000020u;
goto P_0c0401fc;
P_0c0401fc: /* original 000b, guest PC 0x0c0401fc */
if(!s->budget--) { s->failed_pc=0x0c0401fcu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0401fe: /* original 0009, guest PC 0x0c0401fe */
if(!s->budget--) { s->failed_pc=0x0c0401feu; return 0; }
goto P_0c040200;
P_0c040200: /* original e000, guest PC 0x0c040200 */
if(!s->budget--) { s->failed_pc=0x0c040200u; return 0; }
r[0]=0x00000000u;
goto P_0c040202;
P_0c040202: /* original 7f20, guest PC 0x0c040202 */
if(!s->budget--) { s->failed_pc=0x0c040202u; return 0; }
r[15]+=0x00000020u;
goto P_0c040204;
P_0c040204: /* original 000b, guest PC 0x0c040204 */
if(!s->budget--) { s->failed_pc=0x0c040204u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040206: /* original 0009, guest PC 0x0c040206 */
if(!s->budget--) { s->failed_pc=0x0c040206u; return 0; }
return vf3_matrix_family(0x0c040208u,s,ram);
P_0c040222: /* original 7fe4, guest PC 0x0c040222 */
if(!s->budget--) { s->failed_pc=0x0c040222u; return 0; }
r[15]+=0xffffffe4u;
goto P_0c040224;
P_0c040224: /* original 1f46, guest PC 0x0c040224 */
if(!s->budget--) { s->failed_pc=0x0c040224u; return 0; }
write(ram,r[15]+24,r[4],4);
goto P_0c040226;
P_0c040226: /* original 1f55, guest PC 0x0c040226 */
if(!s->budget--) { s->failed_pc=0x0c040226u; return 0; }
write(ram,r[15]+20,r[5],4);
goto P_0c040228;
P_0c040228: /* original 1f64, guest PC 0x0c040228 */
if(!s->budget--) { s->failed_pc=0x0c040228u; return 0; }
write(ram,r[15]+16,r[6],4);
goto P_0c04022a;
P_0c04022a: /* original 1f73, guest PC 0x0c04022a */
if(!s->budget--) { s->failed_pc=0x0c04022au; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c04022c;
P_0c04022c: /* original d312, guest PC 0x0c04022c */
if(!s->budget--) { s->failed_pc=0x0c04022cu; return 0; }
r[3]=read(ram,0x0c040278u,4);
goto P_0c04022e;
P_0c04022e: /* original 52f4, guest PC 0x0c04022e */
if(!s->budget--) { s->failed_pc=0x0c04022eu; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c040230;
P_0c040230: /* original 6132, guest PC 0x0c040230 */
if(!s->budget--) { s->failed_pc=0x0c040230u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c040232;
P_0c040232: /* original 312c, guest PC 0x0c040232 */
if(!s->budget--) { s->failed_pc=0x0c040232u; return 0; }
r[1]+=r[2];
goto P_0c040234;
P_0c040234: /* original 2312, guest PC 0x0c040234 */
if(!s->budget--) { s->failed_pc=0x0c040234u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c040236;
P_0c040236: /* original 53f6, guest PC 0x0c040236 */
if(!s->budget--) { s->failed_pc=0x0c040236u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c040238;
P_0c040238: /* original 6033, guest PC 0x0c040238 */
if(!s->budget--) { s->failed_pc=0x0c040238u; return 0; }
r[0]=r[3];
goto P_0c04023a;
P_0c04023a: /* original 0009, guest PC 0x0c04023a */
if(!s->budget--) { s->failed_pc=0x0c04023au; return 0; }
goto P_0c04023c;
P_0c04023c: /* original 4300, guest PC 0x0c04023c */
if(!s->budget--) { s->failed_pc=0x0c04023cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c04023e;
P_0c04023e: /* original 330c, guest PC 0x0c04023e */
if(!s->budget--) { s->failed_pc=0x0c04023eu; return 0; }
r[3]+=r[0];
goto P_0c040240;
P_0c040240: /* original 4308, guest PC 0x0c040240 */
if(!s->budget--) { s->failed_pc=0x0c040240u; return 0; }
r[3]<<=2;
goto P_0c040242;
P_0c040242: /* original 633e, guest PC 0x0c040242 */
if(!s->budget--) { s->failed_pc=0x0c040242u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c040244;
P_0c040244: /* original 52f5, guest PC 0x0c040244 */
if(!s->budget--) { s->failed_pc=0x0c040244u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c040246;
P_0c040246: /* original d00d, guest PC 0x0c040246 */
if(!s->budget--) { s->failed_pc=0x0c040246u; return 0; }
r[0]=read(ram,0x0c04027cu,4);
goto P_0c040248;
P_0c040248: /* original 0326, guest PC 0x0c040248 */
if(!s->budget--) { s->failed_pc=0x0c040248u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c04024a;
P_0c04024a: /* original 53f6, guest PC 0x0c04024a */
if(!s->budget--) { s->failed_pc=0x0c04024au; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c04024c;
P_0c04024c: /* original 6233, guest PC 0x0c04024c */
if(!s->budget--) { s->failed_pc=0x0c04024cu; return 0; }
r[2]=r[3];
goto P_0c04024e;
P_0c04024e: /* original 4300, guest PC 0x0c04024e */
if(!s->budget--) { s->failed_pc=0x0c04024eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c040250;
P_0c040250: /* original 332c, guest PC 0x0c040250 */
if(!s->budget--) { s->failed_pc=0x0c040250u; return 0; }
r[3]+=r[2];
goto P_0c040252;
P_0c040252: /* original 4308, guest PC 0x0c040252 */
if(!s->budget--) { s->failed_pc=0x0c040252u; return 0; }
r[3]<<=2;
goto P_0c040254;
P_0c040254: /* original 633e, guest PC 0x0c040254 */
if(!s->budget--) { s->failed_pc=0x0c040254u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c040256;
P_0c040256: /* original 51f4, guest PC 0x0c040256 */
if(!s->budget--) { s->failed_pc=0x0c040256u; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c040258;
P_0c040258: /* original d009, guest PC 0x0c040258 */
if(!s->budget--) { s->failed_pc=0x0c040258u; return 0; }
r[0]=read(ram,0x0c040280u,4);
goto P_0c04025a;
P_0c04025a: /* original 0316, guest PC 0x0c04025a */
if(!s->budget--) { s->failed_pc=0x0c04025au; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c04025c;
P_0c04025c: /* original 53f6, guest PC 0x0c04025c */
if(!s->budget--) { s->failed_pc=0x0c04025cu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c04025e;
P_0c04025e: /* original 4308, guest PC 0x0c04025e */
if(!s->budget--) { s->failed_pc=0x0c04025eu; return 0; }
r[3]<<=2;
goto P_0c040260;
P_0c040260: /* original d208, guest PC 0x0c040260 */
if(!s->budget--) { s->failed_pc=0x0c040260u; return 0; }
r[2]=read(ram,0x0c040284u,4);
goto P_0c040262;
P_0c040262: /* original 332c, guest PC 0x0c040262 */
if(!s->budget--) { s->failed_pc=0x0c040262u; return 0; }
r[3]+=r[2];
goto P_0c040264;
P_0c040264: /* original 51f5, guest PC 0x0c040264 */
if(!s->budget--) { s->failed_pc=0x0c040264u; return 0; }
r[1]=read(ram,r[15]+20,4);
goto P_0c040266;
P_0c040266: /* original 2312, guest PC 0x0c040266 */
if(!s->budget--) { s->failed_pc=0x0c040266u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c040268;
P_0c040268: /* original e300, guest PC 0x0c040268 */
if(!s->budget--) { s->failed_pc=0x0c040268u; return 0; }
r[3]=0x00000000u;
goto P_0c04026a;
P_0c04026a: /* original 1f32, guest PC 0x0c04026a */
if(!s->budget--) { s->failed_pc=0x0c04026au; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c04026c;
P_0c04026c: /* original 2f32, guest PC 0x0c04026c */
if(!s->budget--) { s->failed_pc=0x0c04026cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c04026e;
P_0c04026e: /* original 51f6, guest PC 0x0c04026e */
if(!s->budget--) { s->failed_pc=0x0c04026eu; return 0; }
r[1]=read(ram,r[15]+24,4);
goto P_0c040270;
P_0c040270: /* original 71ff, guest PC 0x0c040270 */
if(!s->budget--) { s->failed_pc=0x0c040270u; return 0; }
r[1]+=0xffffffffu;
goto P_0c040272;
P_0c040272: /* original 1f11, guest PC 0x0c040272 */
if(!s->budget--) { s->failed_pc=0x0c040272u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c040274;
P_0c040274: /* original a02a, guest PC 0x0c040274 */
if(!s->budget--) { s->failed_pc=0x0c040274u; return 0; }
goto P_0c0402cc;
P_0c040276: /* original 0009, guest PC 0x0c040276 */
if(!s->budget--) { s->failed_pc=0x0c040276u; return 0; }
return vf3_matrix_family(0x0c040278u,s,ram);
P_0c040288: /* original 84f4, guest PC 0x0c040288 */
if(!s->budget--) { s->failed_pc=0x0c040288u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c04028a;
P_0c04028a: /* original 6303, guest PC 0x0c04028a */
if(!s->budget--) { s->failed_pc=0x0c04028au; return 0; }
r[3]=r[0];
goto P_0c04028c;
P_0c04028c: /* original 4000, guest PC 0x0c04028c */
if(!s->budget--) { s->failed_pc=0x0c04028cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c04028e;
P_0c04028e: /* original 303c, guest PC 0x0c04028e */
if(!s->budget--) { s->failed_pc=0x0c04028eu; return 0; }
r[0]+=r[3];
goto P_0c040290;
P_0c040290: /* original 4008, guest PC 0x0c040290 */
if(!s->budget--) { s->failed_pc=0x0c040290u; return 0; }
r[0]<<=2;
goto P_0c040292;
P_0c040292: /* original 600e, guest PC 0x0c040292 */
if(!s->budget--) { s->failed_pc=0x0c040292u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c040294;
P_0c040294: /* original d119, guest PC 0x0c040294 */
if(!s->budget--) { s->failed_pc=0x0c040294u; return 0; }
r[1]=read(ram,0x0c0402fcu,4);
goto P_0c040296;
P_0c040296: /* original 001e, guest PC 0x0c040296 */
if(!s->budget--) { s->failed_pc=0x0c040296u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c040298;
P_0c040298: /* original 88ff, guest PC 0x0c040298 */
if(!s->budget--) { s->failed_pc=0x0c040298u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c04029a;
P_0c04029a: /* original 8914, guest PC 0x0c04029a */
if(!s->budget--) { s->failed_pc=0x0c04029au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0402c6; }
goto P_0c04029c;
P_0c04029c: /* original 52f1, guest PC 0x0c04029c */
if(!s->budget--) { s->failed_pc=0x0c04029cu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c04029e;
P_0c04029e: /* original 6323, guest PC 0x0c04029e */
if(!s->budget--) { s->failed_pc=0x0c04029eu; return 0; }
r[3]=r[2];
goto P_0c0402a0;
P_0c0402a0: /* original 4200, guest PC 0x0c0402a0 */
if(!s->budget--) { s->failed_pc=0x0c0402a0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0402a2;
P_0c0402a2: /* original 323c, guest PC 0x0c0402a2 */
if(!s->budget--) { s->failed_pc=0x0c0402a2u; return 0; }
r[2]+=r[3];
goto P_0c0402a4;
P_0c0402a4: /* original 4208, guest PC 0x0c0402a4 */
if(!s->budget--) { s->failed_pc=0x0c0402a4u; return 0; }
r[2]<<=2;
goto P_0c0402a6;
P_0c0402a6: /* original 622e, guest PC 0x0c0402a6 */
if(!s->budget--) { s->failed_pc=0x0c0402a6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[2];
goto P_0c0402a8;
P_0c0402a8: /* original 50f1, guest PC 0x0c0402a8 */
if(!s->budget--) { s->failed_pc=0x0c0402a8u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0402aa;
P_0c0402aa: /* original 6303, guest PC 0x0c0402aa */
if(!s->budget--) { s->failed_pc=0x0c0402aau; return 0; }
r[3]=r[0];
goto P_0c0402ac;
P_0c0402ac: /* original 4000, guest PC 0x0c0402ac */
if(!s->budget--) { s->failed_pc=0x0c0402acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0402ae;
P_0c0402ae: /* original 303c, guest PC 0x0c0402ae */
if(!s->budget--) { s->failed_pc=0x0c0402aeu; return 0; }
r[0]+=r[3];
goto P_0c0402b0;
P_0c0402b0: /* original 4008, guest PC 0x0c0402b0 */
if(!s->budget--) { s->failed_pc=0x0c0402b0u; return 0; }
r[0]<<=2;
goto P_0c0402b2;
P_0c0402b2: /* original 600e, guest PC 0x0c0402b2 */
if(!s->budget--) { s->failed_pc=0x0c0402b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c0402b4;
P_0c0402b4: /* original 6313, guest PC 0x0c0402b4 */
if(!s->budget--) { s->failed_pc=0x0c0402b4u; return 0; }
r[3]=r[1];
goto P_0c0402b6;
P_0c0402b6: /* original 303c, guest PC 0x0c0402b6 */
if(!s->budget--) { s->failed_pc=0x0c0402b6u; return 0; }
r[0]+=r[3];
goto P_0c0402b8;
P_0c0402b8: /* original 5302, guest PC 0x0c0402b8 */
if(!s->budget--) { s->failed_pc=0x0c0402b8u; return 0; }
r[3]=read(ram,r[0]+8,4);
goto P_0c0402ba;
P_0c0402ba: /* original d011, guest PC 0x0c0402ba */
if(!s->budget--) { s->failed_pc=0x0c0402bau; return 0; }
r[0]=read(ram,0x0c040300u,4);
goto P_0c0402bc;
P_0c0402bc: /* original 022e, guest PC 0x0c0402bc */
if(!s->budget--) { s->failed_pc=0x0c0402bcu; return 0; }
r[2]=read(ram,r[2]+r[0],4);
goto P_0c0402be;
P_0c0402be: /* original 323c, guest PC 0x0c0402be */
if(!s->budget--) { s->failed_pc=0x0c0402beu; return 0; }
r[2]+=r[3];
goto P_0c0402c0;
P_0c0402c0: /* original 2f22, guest PC 0x0c0402c0 */
if(!s->budget--) { s->failed_pc=0x0c0402c0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0402c2;
P_0c0402c2: /* original a006, guest PC 0x0c0402c2 */
if(!s->budget--) { s->failed_pc=0x0c0402c2u; return 0; }
goto P_0c0402d2;
P_0c0402c4: /* original 0009, guest PC 0x0c0402c4 */
if(!s->budget--) { s->failed_pc=0x0c0402c4u; return 0; }
goto P_0c0402c6;
P_0c0402c6: /* original 51f1, guest PC 0x0c0402c6 */
if(!s->budget--) { s->failed_pc=0x0c0402c6u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0402c8;
P_0c0402c8: /* original 71ff, guest PC 0x0c0402c8 */
if(!s->budget--) { s->failed_pc=0x0c0402c8u; return 0; }
r[1]+=0xffffffffu;
goto P_0c0402ca;
P_0c0402ca: /* original 1f11, guest PC 0x0c0402ca */
if(!s->budget--) { s->failed_pc=0x0c0402cau; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0402cc;
P_0c0402cc: /* original 53f1, guest PC 0x0c0402cc */
if(!s->budget--) { s->failed_pc=0x0c0402ccu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0402ce;
P_0c0402ce: /* original 4311, guest PC 0x0c0402ce */
if(!s->budget--) { s->failed_pc=0x0c0402ceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0402d0;
P_0c0402d0: /* original 89da, guest PC 0x0c0402d0 */
if(!s->budget--) { s->failed_pc=0x0c0402d0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040288; }
goto P_0c0402d2;
P_0c0402d2: /* original 61f2, guest PC 0x0c0402d2 */
if(!s->budget--) { s->failed_pc=0x0c0402d2u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0402d4;
P_0c0402d4: /* original 2118, guest PC 0x0c0402d4 */
if(!s->budget--) { s->failed_pc=0x0c0402d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0402d6;
P_0c0402d6: /* original 8b02, guest PC 0x0c0402d6 */
if(!s->budget--) { s->failed_pc=0x0c0402d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0402de; }
goto P_0c0402d8;
P_0c0402d8: /* original d10a, guest PC 0x0c0402d8 */
if(!s->budget--) { s->failed_pc=0x0c0402d8u; return 0; }
r[1]=read(ram,0x0c040304u,4);
goto P_0c0402da;
P_0c0402da: /* original 6212, guest PC 0x0c0402da */
if(!s->budget--) { s->failed_pc=0x0c0402dau; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0402dc;
P_0c0402dc: /* original 2f22, guest PC 0x0c0402dc */
if(!s->budget--) { s->failed_pc=0x0c0402dcu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0402de;
P_0c0402de: /* original 53f6, guest PC 0x0c0402de */
if(!s->budget--) { s->failed_pc=0x0c0402deu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0402e0;
P_0c0402e0: /* original 6233, guest PC 0x0c0402e0 */
if(!s->budget--) { s->failed_pc=0x0c0402e0u; return 0; }
r[2]=r[3];
goto P_0c0402e2;
P_0c0402e2: /* original 4300, guest PC 0x0c0402e2 */
if(!s->budget--) { s->failed_pc=0x0c0402e2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0402e4;
P_0c0402e4: /* original 332c, guest PC 0x0c0402e4 */
if(!s->budget--) { s->failed_pc=0x0c0402e4u; return 0; }
r[3]+=r[2];
goto P_0c0402e6;
P_0c0402e6: /* original 4308, guest PC 0x0c0402e6 */
if(!s->budget--) { s->failed_pc=0x0c0402e6u; return 0; }
r[3]<<=2;
goto P_0c0402e8;
P_0c0402e8: /* original 633e, guest PC 0x0c0402e8 */
if(!s->budget--) { s->failed_pc=0x0c0402e8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c0402ea;
P_0c0402ea: /* original 61f2, guest PC 0x0c0402ea */
if(!s->budget--) { s->failed_pc=0x0c0402eau; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0402ec;
P_0c0402ec: /* original d004, guest PC 0x0c0402ec */
if(!s->budget--) { s->failed_pc=0x0c0402ecu; return 0; }
r[0]=read(ram,0x0c040300u,4);
goto P_0c0402ee;
P_0c0402ee: /* original 0316, guest PC 0x0c0402ee */
if(!s->budget--) { s->failed_pc=0x0c0402eeu; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c0402f0;
P_0c0402f0: /* original 53f6, guest PC 0x0c0402f0 */
if(!s->budget--) { s->failed_pc=0x0c0402f0u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0402f2;
P_0c0402f2: /* original 7301, guest PC 0x0c0402f2 */
if(!s->budget--) { s->failed_pc=0x0c0402f2u; return 0; }
r[3]+=0x00000001u;
goto P_0c0402f4;
P_0c0402f4: /* original 1f31, guest PC 0x0c0402f4 */
if(!s->budget--) { s->failed_pc=0x0c0402f4u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0402f6;
P_0c0402f6: /* original a02a, guest PC 0x0c0402f6 */
if(!s->budget--) { s->failed_pc=0x0c0402f6u; return 0; }
goto P_0c04034e;
P_0c0402f8: /* original 0009, guest PC 0x0c0402f8 */
if(!s->budget--) { s->failed_pc=0x0c0402f8u; return 0; }
return vf3_matrix_family(0x0c0402fau,s,ram);
P_0c040308: /* original 84f4, guest PC 0x0c040308 */
if(!s->budget--) { s->failed_pc=0x0c040308u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c04030a;
P_0c04030a: /* original 6303, guest PC 0x0c04030a */
if(!s->budget--) { s->failed_pc=0x0c04030au; return 0; }
r[3]=r[0];
goto P_0c04030c;
P_0c04030c: /* original 4000, guest PC 0x0c04030c */
if(!s->budget--) { s->failed_pc=0x0c04030cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c04030e;
P_0c04030e: /* original 303c, guest PC 0x0c04030e */
if(!s->budget--) { s->failed_pc=0x0c04030eu; return 0; }
r[0]+=r[3];
goto P_0c040310;
P_0c040310: /* original 4008, guest PC 0x0c040310 */
if(!s->budget--) { s->failed_pc=0x0c040310u; return 0; }
r[0]<<=2;
goto P_0c040312;
P_0c040312: /* original 600e, guest PC 0x0c040312 */
if(!s->budget--) { s->failed_pc=0x0c040312u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c040314;
P_0c040314: /* original d115, guest PC 0x0c040314 */
if(!s->budget--) { s->failed_pc=0x0c040314u; return 0; }
r[1]=read(ram,0x0c04036cu,4);
goto P_0c040316;
P_0c040316: /* original 001e, guest PC 0x0c040316 */
if(!s->budget--) { s->failed_pc=0x0c040316u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c040318;
P_0c040318: /* original 88ff, guest PC 0x0c040318 */
if(!s->budget--) { s->failed_pc=0x0c040318u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c04031a;
P_0c04031a: /* original 8915, guest PC 0x0c04031a */
if(!s->budget--) { s->failed_pc=0x0c04031au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040348; }
goto P_0c04031c;
P_0c04031c: /* original 52f1, guest PC 0x0c04031c */
if(!s->budget--) { s->failed_pc=0x0c04031cu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c04031e;
P_0c04031e: /* original 6323, guest PC 0x0c04031e */
if(!s->budget--) { s->failed_pc=0x0c04031eu; return 0; }
r[3]=r[2];
goto P_0c040320;
P_0c040320: /* original 4200, guest PC 0x0c040320 */
if(!s->budget--) { s->failed_pc=0x0c040320u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c040322;
P_0c040322: /* original 323c, guest PC 0x0c040322 */
if(!s->budget--) { s->failed_pc=0x0c040322u; return 0; }
r[2]+=r[3];
goto P_0c040324;
P_0c040324: /* original 4208, guest PC 0x0c040324 */
if(!s->budget--) { s->failed_pc=0x0c040324u; return 0; }
r[2]<<=2;
goto P_0c040326;
P_0c040326: /* original 622e, guest PC 0x0c040326 */
if(!s->budget--) { s->failed_pc=0x0c040326u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[2];
goto P_0c040328;
P_0c040328: /* original d011, guest PC 0x0c040328 */
if(!s->budget--) { s->failed_pc=0x0c040328u; return 0; }
r[0]=read(ram,0x0c040370u,4);
goto P_0c04032a;
P_0c04032a: /* original 032e, guest PC 0x0c04032a */
if(!s->budget--) { s->failed_pc=0x0c04032au; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c04032c;
P_0c04032c: /* original 50f2, guest PC 0x0c04032c */
if(!s->budget--) { s->failed_pc=0x0c04032cu; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c04032e;
P_0c04032e: /* original 303c, guest PC 0x0c04032e */
if(!s->budget--) { s->failed_pc=0x0c04032eu; return 0; }
r[0]+=r[3];
goto P_0c040330;
P_0c040330: /* original 1f02, guest PC 0x0c040330 */
if(!s->budget--) { s->failed_pc=0x0c040330u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c040332;
P_0c040332: /* original 52f1, guest PC 0x0c040332 */
if(!s->budget--) { s->failed_pc=0x0c040332u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c040334;
P_0c040334: /* original 6323, guest PC 0x0c040334 */
if(!s->budget--) { s->failed_pc=0x0c040334u; return 0; }
r[3]=r[2];
goto P_0c040336;
P_0c040336: /* original 4200, guest PC 0x0c040336 */
if(!s->budget--) { s->failed_pc=0x0c040336u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c040338;
P_0c040338: /* original 323c, guest PC 0x0c040338 */
if(!s->budget--) { s->failed_pc=0x0c040338u; return 0; }
r[2]+=r[3];
goto P_0c04033a;
P_0c04033a: /* original 4208, guest PC 0x0c04033a */
if(!s->budget--) { s->failed_pc=0x0c04033au; return 0; }
r[2]<<=2;
goto P_0c04033c;
P_0c04033c: /* original 622e, guest PC 0x0c04033c */
if(!s->budget--) { s->failed_pc=0x0c04033cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[2];
goto P_0c04033e;
P_0c04033e: /* original d00d, guest PC 0x0c04033e */
if(!s->budget--) { s->failed_pc=0x0c04033eu; return 0; }
r[0]=read(ram,0x0c040374u,4);
goto P_0c040340;
P_0c040340: /* original 53f4, guest PC 0x0c040340 */
if(!s->budget--) { s->failed_pc=0x0c040340u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c040342;
P_0c040342: /* original 012e, guest PC 0x0c040342 */
if(!s->budget--) { s->failed_pc=0x0c040342u; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c040344;
P_0c040344: /* original 313c, guest PC 0x0c040344 */
if(!s->budget--) { s->failed_pc=0x0c040344u; return 0; }
r[1]+=r[3];
goto P_0c040346;
P_0c040346: /* original 0216, guest PC 0x0c040346 */
if(!s->budget--) { s->failed_pc=0x0c040346u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c040348;
P_0c040348: /* original 52f1, guest PC 0x0c040348 */
if(!s->budget--) { s->failed_pc=0x0c040348u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c04034a;
P_0c04034a: /* original 7201, guest PC 0x0c04034a */
if(!s->budget--) { s->failed_pc=0x0c04034au; return 0; }
r[2]+=0x00000001u;
goto P_0c04034c;
P_0c04034c: /* original 1f21, guest PC 0x0c04034c */
if(!s->budget--) { s->failed_pc=0x0c04034cu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c04034e;
P_0c04034e: /* original e308, guest PC 0x0c04034e */
if(!s->budget--) { s->failed_pc=0x0c04034eu; return 0; }
r[3]=0x00000008u;
goto P_0c040350;
P_0c040350: /* original 51f1, guest PC 0x0c040350 */
if(!s->budget--) { s->failed_pc=0x0c040350u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c040352;
P_0c040352: /* original 3133, guest PC 0x0c040352 */
if(!s->budget--) { s->failed_pc=0x0c040352u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c040354;
P_0c040354: /* original 8bd8, guest PC 0x0c040354 */
if(!s->budget--) { s->failed_pc=0x0c040354u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040308; }
goto P_0c040356;
P_0c040356: /* original 53f3, guest PC 0x0c040356 */
if(!s->budget--) { s->failed_pc=0x0c040356u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c040358;
P_0c040358: /* original 52f2, guest PC 0x0c040358 */
if(!s->budget--) { s->failed_pc=0x0c040358u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c04035a;
P_0c04035a: /* original 2322, guest PC 0x0c04035a */
if(!s->budget--) { s->failed_pc=0x0c04035au; return 0; }
write(ram,r[3],r[2],4);
goto P_0c04035c;
P_0c04035c: /* original 60f2, guest PC 0x0c04035c */
if(!s->budget--) { s->failed_pc=0x0c04035cu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c04035e;
P_0c04035e: /* original 7f1c, guest PC 0x0c04035e */
if(!s->budget--) { s->failed_pc=0x0c04035eu; return 0; }
r[15]+=0x0000001cu;
goto P_0c040360;
P_0c040360: /* original 000b, guest PC 0x0c040360 */
if(!s->budget--) { s->failed_pc=0x0c040360u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040362: /* original 0009, guest PC 0x0c040362 */
if(!s->budget--) { s->failed_pc=0x0c040362u; return 0; }
return vf3_matrix_family(0x0c040364u,s,ram);
P_0c0403c0: /* original 7fe8, guest PC 0x0c0403c0 */
if(!s->budget--) { s->failed_pc=0x0c0403c0u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0403c2;
P_0c0403c2: /* original 1f45, guest PC 0x0c0403c2 */
if(!s->budget--) { s->failed_pc=0x0c0403c2u; return 0; }
write(ram,r[15]+20,r[4],4);
goto P_0c0403c4;
P_0c0403c4: /* original 1f54, guest PC 0x0c0403c4 */
if(!s->budget--) { s->failed_pc=0x0c0403c4u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c0403c6;
P_0c0403c6: /* original 1f63, guest PC 0x0c0403c6 */
if(!s->budget--) { s->failed_pc=0x0c0403c6u; return 0; }
write(ram,r[15]+12,r[6],4);
goto P_0c0403c8;
P_0c0403c8: /* original d20e, guest PC 0x0c0403c8 */
if(!s->budget--) { s->failed_pc=0x0c0403c8u; return 0; }
r[2]=read(ram,0x0c040404u,4);
goto P_0c0403ca;
P_0c0403ca: /* original 53f4, guest PC 0x0c0403ca */
if(!s->budget--) { s->failed_pc=0x0c0403cau; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c0403cc;
P_0c0403cc: /* original 6122, guest PC 0x0c0403cc */
if(!s->budget--) { s->failed_pc=0x0c0403ccu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0403ce;
P_0c0403ce: /* original 3138, guest PC 0x0c0403ce */
if(!s->budget--) { s->failed_pc=0x0c0403ceu; return 0; }
r[1]-=r[3];
goto P_0c0403d0;
P_0c0403d0: /* original 2212, guest PC 0x0c0403d0 */
if(!s->budget--) { s->failed_pc=0x0c0403d0u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c0403d2;
P_0c0403d2: /* original 52f5, guest PC 0x0c0403d2 */
if(!s->budget--) { s->failed_pc=0x0c0403d2u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c0403d4;
P_0c0403d4: /* original 6023, guest PC 0x0c0403d4 */
if(!s->budget--) { s->failed_pc=0x0c0403d4u; return 0; }
r[0]=r[2];
goto P_0c0403d6;
P_0c0403d6: /* original 0009, guest PC 0x0c0403d6 */
if(!s->budget--) { s->failed_pc=0x0c0403d6u; return 0; }
goto P_0c0403d8;
P_0c0403d8: /* original 4200, guest PC 0x0c0403d8 */
if(!s->budget--) { s->failed_pc=0x0c0403d8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0403da;
P_0c0403da: /* original 320c, guest PC 0x0c0403da */
if(!s->budget--) { s->failed_pc=0x0c0403dau; return 0; }
r[2]+=r[0];
goto P_0c0403dc;
P_0c0403dc: /* original 4208, guest PC 0x0c0403dc */
if(!s->budget--) { s->failed_pc=0x0c0403dcu; return 0; }
r[2]<<=2;
goto P_0c0403de;
P_0c0403de: /* original 622e, guest PC 0x0c0403de */
if(!s->budget--) { s->failed_pc=0x0c0403deu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[2];
goto P_0c0403e0;
P_0c0403e0: /* original e3ff, guest PC 0x0c0403e0 */
if(!s->budget--) { s->failed_pc=0x0c0403e0u; return 0; }
r[3]=0xffffffffu;
goto P_0c0403e2;
P_0c0403e2: /* original d009, guest PC 0x0c0403e2 */
if(!s->budget--) { s->failed_pc=0x0c0403e2u; return 0; }
r[0]=read(ram,0x0c040408u,4);
goto P_0c0403e4;
P_0c0403e4: /* original 0236, guest PC 0x0c0403e4 */
if(!s->budget--) { s->failed_pc=0x0c0403e4u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0403e6;
P_0c0403e6: /* original 52f5, guest PC 0x0c0403e6 */
if(!s->budget--) { s->failed_pc=0x0c0403e6u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c0403e8;
P_0c0403e8: /* original 4208, guest PC 0x0c0403e8 */
if(!s->budget--) { s->failed_pc=0x0c0403e8u; return 0; }
r[2]<<=2;
goto P_0c0403ea;
P_0c0403ea: /* original d308, guest PC 0x0c0403ea */
if(!s->budget--) { s->failed_pc=0x0c0403eau; return 0; }
r[3]=read(ram,0x0c04040cu,4);
goto P_0c0403ec;
P_0c0403ec: /* original 323c, guest PC 0x0c0403ec */
if(!s->budget--) { s->failed_pc=0x0c0403ecu; return 0; }
r[2]+=r[3];
goto P_0c0403ee;
P_0c0403ee: /* original e1ff, guest PC 0x0c0403ee */
if(!s->budget--) { s->failed_pc=0x0c0403eeu; return 0; }
r[1]=0xffffffffu;
goto P_0c0403f0;
P_0c0403f0: /* original 2212, guest PC 0x0c0403f0 */
if(!s->budget--) { s->failed_pc=0x0c0403f0u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c0403f2;
P_0c0403f2: /* original e200, guest PC 0x0c0403f2 */
if(!s->budget--) { s->failed_pc=0x0c0403f2u; return 0; }
r[2]=0x00000000u;
goto P_0c0403f4;
P_0c0403f4: /* original 1f22, guest PC 0x0c0403f4 */
if(!s->budget--) { s->failed_pc=0x0c0403f4u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0403f6;
P_0c0403f6: /* original 2f22, guest PC 0x0c0403f6 */
if(!s->budget--) { s->failed_pc=0x0c0403f6u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0403f8;
P_0c0403f8: /* original 51f5, guest PC 0x0c0403f8 */
if(!s->budget--) { s->failed_pc=0x0c0403f8u; return 0; }
r[1]=read(ram,r[15]+20,4);
goto P_0c0403fa;
P_0c0403fa: /* original 7101, guest PC 0x0c0403fa */
if(!s->budget--) { s->failed_pc=0x0c0403fau; return 0; }
r[1]+=0x00000001u;
goto P_0c0403fc;
P_0c0403fc: /* original 1f11, guest PC 0x0c0403fc */
if(!s->budget--) { s->failed_pc=0x0c0403fcu; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0403fe;
P_0c0403fe: /* original a036, guest PC 0x0c0403fe */
if(!s->budget--) { s->failed_pc=0x0c0403feu; return 0; }
goto P_0c04046e;
P_0c040400: /* original 0009, guest PC 0x0c040400 */
if(!s->budget--) { s->failed_pc=0x0c040400u; return 0; }
return vf3_matrix_family(0x0c040402u,s,ram);
P_0c040410: /* original 84f4, guest PC 0x0c040410 */
if(!s->budget--) { s->failed_pc=0x0c040410u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c040412;
P_0c040412: /* original 6303, guest PC 0x0c040412 */
if(!s->budget--) { s->failed_pc=0x0c040412u; return 0; }
r[3]=r[0];
goto P_0c040414;
P_0c040414: /* original 4000, guest PC 0x0c040414 */
if(!s->budget--) { s->failed_pc=0x0c040414u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c040416;
P_0c040416: /* original 303c, guest PC 0x0c040416 */
if(!s->budget--) { s->failed_pc=0x0c040416u; return 0; }
r[0]+=r[3];
goto P_0c040418;
P_0c040418: /* original 4008, guest PC 0x0c040418 */
if(!s->budget--) { s->failed_pc=0x0c040418u; return 0; }
r[0]<<=2;
goto P_0c04041a;
P_0c04041a: /* original 600e, guest PC 0x0c04041a */
if(!s->budget--) { s->failed_pc=0x0c04041au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c04041c;
P_0c04041c: /* original d11b, guest PC 0x0c04041c */
if(!s->budget--) { s->failed_pc=0x0c04041cu; return 0; }
r[1]=read(ram,0x0c04048cu,4);
goto P_0c04041e;
P_0c04041e: /* original 001e, guest PC 0x0c04041e */
if(!s->budget--) { s->failed_pc=0x0c04041eu; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c040420;
P_0c040420: /* original 88ff, guest PC 0x0c040420 */
if(!s->budget--) { s->failed_pc=0x0c040420u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c040422;
P_0c040422: /* original 8921, guest PC 0x0c040422 */
if(!s->budget--) { s->failed_pc=0x0c040422u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040468; }
goto P_0c040424;
P_0c040424: /* original 62f2, guest PC 0x0c040424 */
if(!s->budget--) { s->failed_pc=0x0c040424u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c040426;
P_0c040426: /* original 2228, guest PC 0x0c040426 */
if(!s->budget--) { s->failed_pc=0x0c040426u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c040428;
P_0c040428: /* original 8b08, guest PC 0x0c040428 */
if(!s->budget--) { s->failed_pc=0x0c040428u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04043c; }
goto P_0c04042a;
P_0c04042a: /* original 53f1, guest PC 0x0c04042a */
if(!s->budget--) { s->failed_pc=0x0c04042au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c04042c;
P_0c04042c: /* original 6233, guest PC 0x0c04042c */
if(!s->budget--) { s->failed_pc=0x0c04042cu; return 0; }
r[2]=r[3];
goto P_0c04042e;
P_0c04042e: /* original 4300, guest PC 0x0c04042e */
if(!s->budget--) { s->failed_pc=0x0c04042eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c040430;
P_0c040430: /* original 332c, guest PC 0x0c040430 */
if(!s->budget--) { s->failed_pc=0x0c040430u; return 0; }
r[3]+=r[2];
goto P_0c040432;
P_0c040432: /* original 4308, guest PC 0x0c040432 */
if(!s->budget--) { s->failed_pc=0x0c040432u; return 0; }
r[3]<<=2;
goto P_0c040434;
P_0c040434: /* original 633e, guest PC 0x0c040434 */
if(!s->budget--) { s->failed_pc=0x0c040434u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c040436;
P_0c040436: /* original d016, guest PC 0x0c040436 */
if(!s->budget--) { s->failed_pc=0x0c040436u; return 0; }
r[0]=read(ram,0x0c040490u,4);
goto P_0c040438;
P_0c040438: /* original 003e, guest PC 0x0c040438 */
if(!s->budget--) { s->failed_pc=0x0c040438u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c04043a;
P_0c04043a: /* original 2f02, guest PC 0x0c04043a */
if(!s->budget--) { s->failed_pc=0x0c04043au; return 0; }
write(ram,r[15],r[0],4);
goto P_0c04043c;
P_0c04043c: /* original 53f1, guest PC 0x0c04043c */
if(!s->budget--) { s->failed_pc=0x0c04043cu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c04043e;
P_0c04043e: /* original 6233, guest PC 0x0c04043e */
if(!s->budget--) { s->failed_pc=0x0c04043eu; return 0; }
r[2]=r[3];
goto P_0c040440;
P_0c040440: /* original 4300, guest PC 0x0c040440 */
if(!s->budget--) { s->failed_pc=0x0c040440u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c040442;
P_0c040442: /* original 332c, guest PC 0x0c040442 */
if(!s->budget--) { s->failed_pc=0x0c040442u; return 0; }
r[3]+=r[2];
goto P_0c040444;
P_0c040444: /* original 4308, guest PC 0x0c040444 */
if(!s->budget--) { s->failed_pc=0x0c040444u; return 0; }
r[3]<<=2;
goto P_0c040446;
P_0c040446: /* original 633e, guest PC 0x0c040446 */
if(!s->budget--) { s->failed_pc=0x0c040446u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c040448;
P_0c040448: /* original d012, guest PC 0x0c040448 */
if(!s->budget--) { s->failed_pc=0x0c040448u; return 0; }
r[0]=read(ram,0x0c040494u,4);
goto P_0c04044a;
P_0c04044a: /* original 033e, guest PC 0x0c04044a */
if(!s->budget--) { s->failed_pc=0x0c04044au; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c04044c;
P_0c04044c: /* original 52f2, guest PC 0x0c04044c */
if(!s->budget--) { s->failed_pc=0x0c04044cu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c04044e;
P_0c04044e: /* original 323c, guest PC 0x0c04044e */
if(!s->budget--) { s->failed_pc=0x0c04044eu; return 0; }
r[2]+=r[3];
goto P_0c040450;
P_0c040450: /* original 1f22, guest PC 0x0c040450 */
if(!s->budget--) { s->failed_pc=0x0c040450u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c040452;
P_0c040452: /* original 51f1, guest PC 0x0c040452 */
if(!s->budget--) { s->failed_pc=0x0c040452u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c040454;
P_0c040454: /* original 6313, guest PC 0x0c040454 */
if(!s->budget--) { s->failed_pc=0x0c040454u; return 0; }
r[3]=r[1];
goto P_0c040456;
P_0c040456: /* original 4100, guest PC 0x0c040456 */
if(!s->budget--) { s->failed_pc=0x0c040456u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c040458;
P_0c040458: /* original 313c, guest PC 0x0c040458 */
if(!s->budget--) { s->failed_pc=0x0c040458u; return 0; }
r[1]+=r[3];
goto P_0c04045a;
P_0c04045a: /* original 4108, guest PC 0x0c04045a */
if(!s->budget--) { s->failed_pc=0x0c04045au; return 0; }
r[1]<<=2;
goto P_0c04045c;
P_0c04045c: /* original 611e, guest PC 0x0c04045c */
if(!s->budget--) { s->failed_pc=0x0c04045cu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)r[1];
goto P_0c04045e;
P_0c04045e: /* original d00c, guest PC 0x0c04045e */
if(!s->budget--) { s->failed_pc=0x0c04045eu; return 0; }
r[0]=read(ram,0x0c040490u,4);
goto P_0c040460;
P_0c040460: /* original 53f4, guest PC 0x0c040460 */
if(!s->budget--) { s->failed_pc=0x0c040460u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c040462;
P_0c040462: /* original 021e, guest PC 0x0c040462 */
if(!s->budget--) { s->failed_pc=0x0c040462u; return 0; }
r[2]=read(ram,r[1]+r[0],4);
goto P_0c040464;
P_0c040464: /* original 3238, guest PC 0x0c040464 */
if(!s->budget--) { s->failed_pc=0x0c040464u; return 0; }
r[2]-=r[3];
goto P_0c040466;
P_0c040466: /* original 0126, guest PC 0x0c040466 */
if(!s->budget--) { s->failed_pc=0x0c040466u; return 0; }
write(ram,r[1]+r[0],r[2],4);
goto P_0c040468;
P_0c040468: /* original 51f1, guest PC 0x0c040468 */
if(!s->budget--) { s->failed_pc=0x0c040468u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c04046a;
P_0c04046a: /* original 7101, guest PC 0x0c04046a */
if(!s->budget--) { s->failed_pc=0x0c04046au; return 0; }
r[1]+=0x00000001u;
goto P_0c04046c;
P_0c04046c: /* original 1f11, guest PC 0x0c04046c */
if(!s->budget--) { s->failed_pc=0x0c04046cu; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c04046e;
P_0c04046e: /* original e308, guest PC 0x0c04046e */
if(!s->budget--) { s->failed_pc=0x0c04046eu; return 0; }
r[3]=0x00000008u;
goto P_0c040470;
P_0c040470: /* original 52f1, guest PC 0x0c040470 */
if(!s->budget--) { s->failed_pc=0x0c040470u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c040472;
P_0c040472: /* original 3233, guest PC 0x0c040472 */
if(!s->budget--) { s->failed_pc=0x0c040472u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c040474;
P_0c040474: /* original 8bcc, guest PC 0x0c040474 */
if(!s->budget--) { s->failed_pc=0x0c040474u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040410; }
goto P_0c040476;
P_0c040476: /* original 53f3, guest PC 0x0c040476 */
if(!s->budget--) { s->failed_pc=0x0c040476u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c040478;
P_0c040478: /* original 52f2, guest PC 0x0c040478 */
if(!s->budget--) { s->failed_pc=0x0c040478u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c04047a;
P_0c04047a: /* original 2322, guest PC 0x0c04047a */
if(!s->budget--) { s->failed_pc=0x0c04047au; return 0; }
write(ram,r[3],r[2],4);
goto P_0c04047c;
P_0c04047c: /* original 60f2, guest PC 0x0c04047c */
if(!s->budget--) { s->failed_pc=0x0c04047cu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c04047e;
P_0c04047e: /* original 7f18, guest PC 0x0c04047e */
if(!s->budget--) { s->failed_pc=0x0c04047eu; return 0; }
r[15]+=0x00000018u;
goto P_0c040480;
P_0c040480: /* original 000b, guest PC 0x0c040480 */
if(!s->budget--) { s->failed_pc=0x0c040480u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040482: /* original 0009, guest PC 0x0c040482 */
if(!s->budget--) { s->failed_pc=0x0c040482u; return 0; }
return vf3_matrix_family(0x0c040484u,s,ram);
P_0c040b7e: /* original 4f22, guest PC 0x0c040b7e */
if(!s->budget--) { s->failed_pc=0x0c040b7eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c040b80;
P_0c040b80: /* original 7ff0, guest PC 0x0c040b80 */
if(!s->budget--) { s->failed_pc=0x0c040b80u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c040b82;
P_0c040b82: /* original 63f3, guest PC 0x0c040b82 */
if(!s->budget--) { s->failed_pc=0x0c040b82u; return 0; }
r[3]=r[15];
goto P_0c040b84;
P_0c040b84: /* original 730e, guest PC 0x0c040b84 */
if(!s->budget--) { s->failed_pc=0x0c040b84u; return 0; }
r[3]+=0x0000000eu;
goto P_0c040b86;
P_0c040b86: /* original 2341, guest PC 0x0c040b86 */
if(!s->budget--) { s->failed_pc=0x0c040b86u; return 0; }
write(ram,r[3],r[4],2);
goto P_0c040b88;
P_0c040b88: /* original 1f52, guest PC 0x0c040b88 */
if(!s->budget--) { s->failed_pc=0x0c040b88u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c040b8a;
P_0c040b8a: /* original 1f61, guest PC 0x0c040b8a */
if(!s->budget--) { s->failed_pc=0x0c040b8au; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c040b8c;
P_0c040b8c: /* original 85f7, guest PC 0x0c040b8c */
if(!s->budget--) { s->failed_pc=0x0c040b8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+14,2);
goto P_0c040b8e;
P_0c040b8e: /* original 600d, guest PC 0x0c040b8e */
if(!s->budget--) { s->failed_pc=0x0c040b8eu; return 0; }
r[0]=r[0]&65535u;
goto P_0c040b90;
P_0c040b90: /* original ee0f, guest PC 0x0c040b90 */
if(!s->budget--) { s->failed_pc=0x0c040b90u; return 0; }
r[14]=0x0000000fu;
goto P_0c040b92;
P_0c040b92: /* original 2e09, guest PC 0x0c040b92 */
if(!s->budget--) { s->failed_pc=0x0c040b92u; return 0; }
r[14]&=r[0];
goto P_0c040b94;
P_0c040b94: /* original 4e28, guest PC 0x0c040b94 */
if(!s->budget--) { s->failed_pc=0x0c040b94u; return 0; }
r[14]<<=16;
goto P_0c040b96;
P_0c040b96: /* original 4e18, guest PC 0x0c040b96 */
if(!s->budget--) { s->failed_pc=0x0c040b96u; return 0; }
r[14]<<=8;
goto P_0c040b98;
P_0c040b98: /* original 53f2, guest PC 0x0c040b98 */
if(!s->budget--) { s->failed_pc=0x0c040b98u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c040b9a;
P_0c040b9a: /* original 3e3c, guest PC 0x0c040b9a */
if(!s->budget--) { s->failed_pc=0x0c040b9au; return 0; }
r[14]+=r[3];
goto P_0c040b9c;
P_0c040b9c: /* original d21b, guest PC 0x0c040b9c */
if(!s->budget--) { s->failed_pc=0x0c040b9cu; return 0; }
r[2]=read(ram,0x0c040c0cu,4);
goto P_0c040b9e;
P_0c040b9e: /* original 2328, guest PC 0x0c040b9e */
if(!s->budget--) { s->failed_pc=0x0c040b9eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[2])==0)!=0);
goto P_0c040ba0;
P_0c040ba0: /* original 8936, guest PC 0x0c040ba0 */
if(!s->budget--) { s->failed_pc=0x0c040ba0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040c10; }
goto P_0c040ba2;
P_0c040ba2: /* original 50f2, guest PC 0x0c040ba2 */
if(!s->budget--) { s->failed_pc=0x0c040ba2u; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c040ba4;
P_0c040ba4: /* original 9128, guest PC 0x0c040ba4 */
if(!s->budget--) { s->failed_pc=0x0c040ba4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040bf8u,2);
goto P_0c040ba6;
P_0c040ba6: /* original 3010, guest PC 0x0c040ba6 */
if(!s->budget--) { s->failed_pc=0x0c040ba6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c040ba8;
P_0c040ba8: /* original 8919, guest PC 0x0c040ba8 */
if(!s->budget--) { s->failed_pc=0x0c040ba8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040bde; }
goto P_0c040baa;
P_0c040baa: /* original 9126, guest PC 0x0c040baa */
if(!s->budget--) { s->failed_pc=0x0c040baau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040bfau,2);
goto P_0c040bac;
P_0c040bac: /* original 3010, guest PC 0x0c040bac */
if(!s->budget--) { s->failed_pc=0x0c040bacu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c040bae;
P_0c040bae: /* original 8916, guest PC 0x0c040bae */
if(!s->budget--) { s->failed_pc=0x0c040baeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040bde; }
goto P_0c040bb0;
P_0c040bb0: /* original 9124, guest PC 0x0c040bb0 */
if(!s->budget--) { s->failed_pc=0x0c040bb0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040bfcu,2);
goto P_0c040bb2;
P_0c040bb2: /* original 3010, guest PC 0x0c040bb2 */
if(!s->budget--) { s->failed_pc=0x0c040bb2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c040bb4;
P_0c040bb4: /* original 8919, guest PC 0x0c040bb4 */
if(!s->budget--) { s->failed_pc=0x0c040bb4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040bea; }
goto P_0c040bb6;
P_0c040bb6: /* original 9122, guest PC 0x0c040bb6 */
if(!s->budget--) { s->failed_pc=0x0c040bb6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040bfeu,2);
goto P_0c040bb8;
P_0c040bb8: /* original 3010, guest PC 0x0c040bb8 */
if(!s->budget--) { s->failed_pc=0x0c040bb8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c040bba;
P_0c040bba: /* original 8916, guest PC 0x0c040bba */
if(!s->budget--) { s->failed_pc=0x0c040bbau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040bea; }
goto P_0c040bbc;
P_0c040bbc: /* original 9120, guest PC 0x0c040bbc */
if(!s->budget--) { s->failed_pc=0x0c040bbcu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040c00u,2);
goto P_0c040bbe;
P_0c040bbe: /* original 3010, guest PC 0x0c040bbe */
if(!s->budget--) { s->failed_pc=0x0c040bbeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c040bc0;
P_0c040bc0: /* original 8913, guest PC 0x0c040bc0 */
if(!s->budget--) { s->failed_pc=0x0c040bc0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040bea; }
goto P_0c040bc2;
P_0c040bc2: /* original 911e, guest PC 0x0c040bc2 */
if(!s->budget--) { s->failed_pc=0x0c040bc2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040c02u,2);
goto P_0c040bc4;
P_0c040bc4: /* original 3010, guest PC 0x0c040bc4 */
if(!s->budget--) { s->failed_pc=0x0c040bc4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c040bc6;
P_0c040bc6: /* original 890a, guest PC 0x0c040bc6 */
if(!s->budget--) { s->failed_pc=0x0c040bc6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040bde; }
goto P_0c040bc8;
P_0c040bc8: /* original 911c, guest PC 0x0c040bc8 */
if(!s->budget--) { s->failed_pc=0x0c040bc8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040c04u,2);
goto P_0c040bca;
P_0c040bca: /* original 3010, guest PC 0x0c040bca */
if(!s->budget--) { s->failed_pc=0x0c040bcau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c040bcc;
P_0c040bcc: /* original 8907, guest PC 0x0c040bcc */
if(!s->budget--) { s->failed_pc=0x0c040bccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040bde; }
goto P_0c040bce;
P_0c040bce: /* original 911a, guest PC 0x0c040bce */
if(!s->budget--) { s->failed_pc=0x0c040bceu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040c06u,2);
goto P_0c040bd0;
P_0c040bd0: /* original 3010, guest PC 0x0c040bd0 */
if(!s->budget--) { s->failed_pc=0x0c040bd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c040bd2;
P_0c040bd2: /* original 8904, guest PC 0x0c040bd2 */
if(!s->budget--) { s->failed_pc=0x0c040bd2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040bde; }
goto P_0c040bd4;
P_0c040bd4: /* original 9118, guest PC 0x0c040bd4 */
if(!s->budget--) { s->failed_pc=0x0c040bd4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040c08u,2);
goto P_0c040bd6;
P_0c040bd6: /* original 3010, guest PC 0x0c040bd6 */
if(!s->budget--) { s->failed_pc=0x0c040bd6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c040bd8;
P_0c040bd8: /* original 8907, guest PC 0x0c040bd8 */
if(!s->budget--) { s->failed_pc=0x0c040bd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040bea; }
goto P_0c040bda;
P_0c040bda: /* original a019, guest PC 0x0c040bda */
if(!s->budget--) { s->failed_pc=0x0c040bdau; return 0; }
goto P_0c040c10;
P_0c040bdc: /* original 0009, guest PC 0x0c040bdc */
if(!s->budget--) { s->failed_pc=0x0c040bdcu; return 0; }
goto P_0c040bde;
P_0c040bde: /* original 50f1, guest PC 0x0c040bde */
if(!s->budget--) { s->failed_pc=0x0c040bdeu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c040be0;
P_0c040be0: /* original c97f, guest PC 0x0c040be0 */
if(!s->budget--) { s->failed_pc=0x0c040be0u; return 0; }
r[0]&=127u;
goto P_0c040be2;
P_0c040be2: /* original 4028, guest PC 0x0c040be2 */
if(!s->budget--) { s->failed_pc=0x0c040be2u; return 0; }
r[0]<<=16;
goto P_0c040be4;
P_0c040be4: /* original 3e0c, guest PC 0x0c040be4 */
if(!s->budget--) { s->failed_pc=0x0c040be4u; return 0; }
r[14]+=r[0];
goto P_0c040be6;
P_0c040be6: /* original a013, guest PC 0x0c040be6 */
if(!s->budget--) { s->failed_pc=0x0c040be6u; return 0; }
goto P_0c040c10;
P_0c040be8: /* original 0009, guest PC 0x0c040be8 */
if(!s->budget--) { s->failed_pc=0x0c040be8u; return 0; }
goto P_0c040bea;
P_0c040bea: /* original 50f1, guest PC 0x0c040bea */
if(!s->budget--) { s->failed_pc=0x0c040beau; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c040bec;
P_0c040bec: /* original 7040, guest PC 0x0c040bec */
if(!s->budget--) { s->failed_pc=0x0c040becu; return 0; }
r[0]+=0x00000040u;
goto P_0c040bee;
P_0c040bee: /* original c97f, guest PC 0x0c040bee */
if(!s->budget--) { s->failed_pc=0x0c040beeu; return 0; }
r[0]&=127u;
goto P_0c040bf0;
P_0c040bf0: /* original 4028, guest PC 0x0c040bf0 */
if(!s->budget--) { s->failed_pc=0x0c040bf0u; return 0; }
r[0]<<=16;
goto P_0c040bf2;
P_0c040bf2: /* original 3e0c, guest PC 0x0c040bf2 */
if(!s->budget--) { s->failed_pc=0x0c040bf2u; return 0; }
r[14]+=r[0];
goto P_0c040bf4;
P_0c040bf4: /* original a00c, guest PC 0x0c040bf4 */
if(!s->budget--) { s->failed_pc=0x0c040bf4u; return 0; }
goto P_0c040c10;
P_0c040bf6: /* original 0009, guest PC 0x0c040bf6 */
if(!s->budget--) { s->failed_pc=0x0c040bf6u; return 0; }
return vf3_matrix_family(0x0c040bf8u,s,ram);
P_0c040c10: /* original d21c, guest PC 0x0c040c10 */
if(!s->budget--) { s->failed_pc=0x0c040c10u; return 0; }
r[2]=read(ram,0x0c040c84u,4);
goto P_0c040c12;
P_0c040c12: /* original 53f2, guest PC 0x0c040c12 */
if(!s->budget--) { s->failed_pc=0x0c040c12u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c040c14;
P_0c040c14: /* original 3320, guest PC 0x0c040c14 */
if(!s->budget--) { s->failed_pc=0x0c040c14u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c040c16;
P_0c040c16: /* original 8b27, guest PC 0x0c040c16 */
if(!s->budget--) { s->failed_pc=0x0c040c16u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040c68; }
goto P_0c040c18;
P_0c040c18: /* original e301, guest PC 0x0c040c18 */
if(!s->budget--) { s->failed_pc=0x0c040c18u; return 0; }
r[3]=0x00000001u;
goto P_0c040c1a;
P_0c040c1a: /* original 2f32, guest PC 0x0c040c1a */
if(!s->budget--) { s->failed_pc=0x0c040c1au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c040c1c;
P_0c040c1c: /* original a01b, guest PC 0x0c040c1c */
if(!s->budget--) { s->failed_pc=0x0c040c1cu; return 0; }
goto P_0c040c56;
P_0c040c1e: /* original 0009, guest PC 0x0c040c1e */
if(!s->budget--) { s->failed_pc=0x0c040c1eu; return 0; }
goto P_0c040c20;
P_0c040c20: /* original 60f2, guest PC 0x0c040c20 */
if(!s->budget--) { s->failed_pc=0x0c040c20u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c040c22;
P_0c040c22: /* original 6303, guest PC 0x0c040c22 */
if(!s->budget--) { s->failed_pc=0x0c040c22u; return 0; }
r[3]=r[0];
goto P_0c040c24;
P_0c040c24: /* original 4000, guest PC 0x0c040c24 */
if(!s->budget--) { s->failed_pc=0x0c040c24u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c040c26;
P_0c040c26: /* original 303c, guest PC 0x0c040c26 */
if(!s->budget--) { s->failed_pc=0x0c040c26u; return 0; }
r[0]+=r[3];
goto P_0c040c28;
P_0c040c28: /* original 4008, guest PC 0x0c040c28 */
if(!s->budget--) { s->failed_pc=0x0c040c28u; return 0; }
r[0]<<=2;
goto P_0c040c2a;
P_0c040c2a: /* original 600e, guest PC 0x0c040c2a */
if(!s->budget--) { s->failed_pc=0x0c040c2au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c040c2c;
P_0c040c2c: /* original d116, guest PC 0x0c040c2c */
if(!s->budget--) { s->failed_pc=0x0c040c2cu; return 0; }
r[1]=read(ram,0x0c040c88u,4);
goto P_0c040c2e;
P_0c040c2e: /* original 001e, guest PC 0x0c040c2e */
if(!s->budget--) { s->failed_pc=0x0c040c2eu; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c040c30;
P_0c040c30: /* original 88ff, guest PC 0x0c040c30 */
if(!s->budget--) { s->failed_pc=0x0c040c30u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c040c32;
P_0c040c32: /* original 890d, guest PC 0x0c040c32 */
if(!s->budget--) { s->failed_pc=0x0c040c32u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040c50; }
goto P_0c040c34;
P_0c040c34: /* original 64f2, guest PC 0x0c040c34 */
if(!s->budget--) { s->failed_pc=0x0c040c34u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c040c36;
P_0c040c36: /* original 4428, guest PC 0x0c040c36 */
if(!s->budget--) { s->failed_pc=0x0c040c36u; return 0; }
r[4]<<=16;
goto P_0c040c38;
P_0c040c38: /* original 4418, guest PC 0x0c040c38 */
if(!s->budget--) { s->failed_pc=0x0c040c38u; return 0; }
r[4]<<=8;
goto P_0c040c3a;
P_0c040c3a: /* original d314, guest PC 0x0c040c3a */
if(!s->budget--) { s->failed_pc=0x0c040c3au; return 0; }
r[3]=read(ram,0x0c040c8cu,4);
goto P_0c040c3c;
P_0c040c3c: /* original 343c, guest PC 0x0c040c3c */
if(!s->budget--) { s->failed_pc=0x0c040c3cu; return 0; }
r[4]+=r[3];
goto P_0c040c3e;
P_0c040c3e: /* original b16e, guest PC 0x0c040c3e */
if(!s->budget--) { s->failed_pc=0x0c040c3eu; return 0; }
target=0x0c040f1eu; r[16]=0x0c040c42u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c040c42u) { target=s->pc; goto dispatch; }
goto P_0c040c42;
P_0c040c40: /* original 0009, guest PC 0x0c040c40 */
if(!s->budget--) { s->failed_pc=0x0c040c40u; return 0; }
goto P_0c040c42;
P_0c040c42: /* original 64f2, guest PC 0x0c040c42 */
if(!s->budget--) { s->failed_pc=0x0c040c42u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c040c44;
P_0c040c44: /* original 4428, guest PC 0x0c040c44 */
if(!s->budget--) { s->failed_pc=0x0c040c44u; return 0; }
r[4]<<=16;
goto P_0c040c46;
P_0c040c46: /* original 4418, guest PC 0x0c040c46 */
if(!s->budget--) { s->failed_pc=0x0c040c46u; return 0; }
r[4]<<=8;
goto P_0c040c48;
P_0c040c48: /* original 931b, guest PC 0x0c040c48 */
if(!s->budget--) { s->failed_pc=0x0c040c48u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040c82u,2);
goto P_0c040c4a;
P_0c040c4a: /* original 343c, guest PC 0x0c040c4a */
if(!s->budget--) { s->failed_pc=0x0c040c4au; return 0; }
r[4]+=r[3];
goto P_0c040c4c;
P_0c040c4c: /* original b167, guest PC 0x0c040c4c */
if(!s->budget--) { s->failed_pc=0x0c040c4cu; return 0; }
target=0x0c040f1eu; r[16]=0x0c040c50u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c040c50u) { target=s->pc; goto dispatch; }
goto P_0c040c50;
P_0c040c4e: /* original 0009, guest PC 0x0c040c4e */
if(!s->budget--) { s->failed_pc=0x0c040c4eu; return 0; }
goto P_0c040c50;
P_0c040c50: /* original 63f2, guest PC 0x0c040c50 */
if(!s->budget--) { s->failed_pc=0x0c040c50u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c040c52;
P_0c040c52: /* original 7301, guest PC 0x0c040c52 */
if(!s->budget--) { s->failed_pc=0x0c040c52u; return 0; }
r[3]+=0x00000001u;
goto P_0c040c54;
P_0c040c54: /* original 2f32, guest PC 0x0c040c54 */
if(!s->budget--) { s->failed_pc=0x0c040c54u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c040c56;
P_0c040c56: /* original e208, guest PC 0x0c040c56 */
if(!s->budget--) { s->failed_pc=0x0c040c56u; return 0; }
r[2]=0x00000008u;
goto P_0c040c58;
P_0c040c58: /* original 61f2, guest PC 0x0c040c58 */
if(!s->budget--) { s->failed_pc=0x0c040c58u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c040c5a;
P_0c040c5a: /* original 3123, guest PC 0x0c040c5a */
if(!s->budget--) { s->failed_pc=0x0c040c5au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c040c5c;
P_0c040c5c: /* original 8be0, guest PC 0x0c040c5c */
if(!s->budget--) { s->failed_pc=0x0c040c5cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040c20; }
goto P_0c040c5e;
P_0c040c5e: /* original 7f10, guest PC 0x0c040c5e */
if(!s->budget--) { s->failed_pc=0x0c040c5eu; return 0; }
r[15]+=0x00000010u;
goto P_0c040c60;
P_0c040c60: /* original 4f26, guest PC 0x0c040c60 */
if(!s->budget--) { s->failed_pc=0x0c040c60u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c040c62;
P_0c040c62: /* original 6ef6, guest PC 0x0c040c62 */
if(!s->budget--) { s->failed_pc=0x0c040c62u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c040c64;
P_0c040c64: /* original 000b, guest PC 0x0c040c64 */
if(!s->budget--) { s->failed_pc=0x0c040c64u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040c66: /* original 0009, guest PC 0x0c040c66 */
if(!s->budget--) { s->failed_pc=0x0c040c66u; return 0; }
goto P_0c040c68;
P_0c040c68: /* original 64e3, guest PC 0x0c040c68 */
if(!s->budget--) { s->failed_pc=0x0c040c68u; return 0; }
r[4]=r[14];
goto P_0c040c6a;
P_0c040c6a: /* original b158, guest PC 0x0c040c6a */
if(!s->budget--) { s->failed_pc=0x0c040c6au; return 0; }
target=0x0c040f1eu; r[16]=0x0c040c6eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c040c6eu) { target=s->pc; goto dispatch; }
goto P_0c040c6e;
P_0c040c6c: /* original 0009, guest PC 0x0c040c6c */
if(!s->budget--) { s->failed_pc=0x0c040c6cu; return 0; }
goto P_0c040c6e;
P_0c040c6e: /* original 7f10, guest PC 0x0c040c6e */
if(!s->budget--) { s->failed_pc=0x0c040c6eu; return 0; }
r[15]+=0x00000010u;
goto P_0c040c70;
P_0c040c70: /* original 4f26, guest PC 0x0c040c70 */
if(!s->budget--) { s->failed_pc=0x0c040c70u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c040c72;
P_0c040c72: /* original 6ef6, guest PC 0x0c040c72 */
if(!s->budget--) { s->failed_pc=0x0c040c72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c040c74;
P_0c040c74: /* original 000b, guest PC 0x0c040c74 */
if(!s->budget--) { s->failed_pc=0x0c040c74u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040c76: /* original 0009, guest PC 0x0c040c76 */
if(!s->budget--) { s->failed_pc=0x0c040c76u; return 0; }
return vf3_matrix_family(0x0c040c78u,s,ram);
P_0c040f1e: /* original 7ffc, guest PC 0x0c040f1e */
if(!s->budget--) { s->failed_pc=0x0c040f1eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c040f20;
P_0c040f20: /* original 2f42, guest PC 0x0c040f20 */
if(!s->budget--) { s->failed_pc=0x0c040f20u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c040f22;
P_0c040f22: /* original 60f2, guest PC 0x0c040f22 */
if(!s->budget--) { s->failed_pc=0x0c040f22u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c040f24;
P_0c040f24: /* original c880, guest PC 0x0c040f24 */
if(!s->budget--) { s->failed_pc=0x0c040f24u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c040f26;
P_0c040f26: /* original 8b03, guest PC 0x0c040f26 */
if(!s->budget--) { s->failed_pc=0x0c040f26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040f30; }
goto P_0c040f28;
P_0c040f28: /* original e0fe, guest PC 0x0c040f28 */
if(!s->budget--) { s->failed_pc=0x0c040f28u; return 0; }
r[0]=0xfffffffeu;
goto P_0c040f2a;
P_0c040f2a: /* original 7f04, guest PC 0x0c040f2a */
if(!s->budget--) { s->failed_pc=0x0c040f2au; return 0; }
r[15]+=0x00000004u;
goto P_0c040f2c;
P_0c040f2c: /* original 000b, guest PC 0x0c040f2c */
if(!s->budget--) { s->failed_pc=0x0c040f2cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f2e: /* original 0009, guest PC 0x0c040f2e */
if(!s->budget--) { s->failed_pc=0x0c040f2eu; return 0; }
goto P_0c040f30;
P_0c040f30: /* original d30d, guest PC 0x0c040f30 */
if(!s->budget--) { s->failed_pc=0x0c040f30u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f32;
P_0c040f32: /* original 6232, guest PC 0x0c040f32 */
if(!s->budget--) { s->failed_pc=0x0c040f32u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c040f34;
P_0c040f34: /* original 6122, guest PC 0x0c040f34 */
if(!s->budget--) { s->failed_pc=0x0c040f34u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c040f36;
P_0c040f36: /* original 2118, guest PC 0x0c040f36 */
if(!s->budget--) { s->failed_pc=0x0c040f36u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c040f38;
P_0c040f38: /* original 8903, guest PC 0x0c040f38 */
if(!s->budget--) { s->failed_pc=0x0c040f38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040f42; }
goto P_0c040f3a;
P_0c040f3a: /* original e0ff, guest PC 0x0c040f3a */
if(!s->budget--) { s->failed_pc=0x0c040f3au; return 0; }
r[0]=0xffffffffu;
goto P_0c040f3c;
P_0c040f3c: /* original 7f04, guest PC 0x0c040f3c */
if(!s->budget--) { s->failed_pc=0x0c040f3cu; return 0; }
r[15]+=0x00000004u;
goto P_0c040f3e;
P_0c040f3e: /* original 000b, guest PC 0x0c040f3e */
if(!s->budget--) { s->failed_pc=0x0c040f3eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f40: /* original 0009, guest PC 0x0c040f40 */
if(!s->budget--) { s->failed_pc=0x0c040f40u; return 0; }
goto P_0c040f42;
P_0c040f42: /* original d309, guest PC 0x0c040f42 */
if(!s->budget--) { s->failed_pc=0x0c040f42u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f44;
P_0c040f44: /* original 6232, guest PC 0x0c040f44 */
if(!s->budget--) { s->failed_pc=0x0c040f44u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c040f46;
P_0c040f46: /* original 7204, guest PC 0x0c040f46 */
if(!s->budget--) { s->failed_pc=0x0c040f46u; return 0; }
r[2]+=0x00000004u;
goto P_0c040f48;
P_0c040f48: /* original 2322, guest PC 0x0c040f48 */
if(!s->budget--) { s->failed_pc=0x0c040f48u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c040f4a;
P_0c040f4a: /* original 72fc, guest PC 0x0c040f4a */
if(!s->budget--) { s->failed_pc=0x0c040f4au; return 0; }
r[2]+=0xfffffffcu;
goto P_0c040f4c;
P_0c040f4c: /* original 63f2, guest PC 0x0c040f4c */
if(!s->budget--) { s->failed_pc=0x0c040f4cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c040f4e;
P_0c040f4e: /* original 2232, guest PC 0x0c040f4e */
if(!s->budget--) { s->failed_pc=0x0c040f4eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c040f50;
P_0c040f50: /* original d206, guest PC 0x0c040f50 */
if(!s->budget--) { s->failed_pc=0x0c040f50u; return 0; }
r[2]=read(ram,0x0c040f6cu,4);
goto P_0c040f52;
P_0c040f52: /* original d305, guest PC 0x0c040f52 */
if(!s->budget--) { s->failed_pc=0x0c040f52u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f54;
P_0c040f54: /* original 6132, guest PC 0x0c040f54 */
if(!s->budget--) { s->failed_pc=0x0c040f54u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c040f56;
P_0c040f56: /* original 3120, guest PC 0x0c040f56 */
if(!s->budget--) { s->failed_pc=0x0c040f56u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c040f58;
P_0c040f58: /* original 8b02, guest PC 0x0c040f58 */
if(!s->budget--) { s->failed_pc=0x0c040f58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040f60; }
goto P_0c040f5a;
P_0c040f5a: /* original d305, guest PC 0x0c040f5a */
if(!s->budget--) { s->failed_pc=0x0c040f5au; return 0; }
r[3]=read(ram,0x0c040f70u,4);
goto P_0c040f5c;
P_0c040f5c: /* original d002, guest PC 0x0c040f5c */
if(!s->budget--) { s->failed_pc=0x0c040f5cu; return 0; }
r[0]=read(ram,0x0c040f68u,4);
goto P_0c040f5e;
P_0c040f5e: /* original 2032, guest PC 0x0c040f5e */
if(!s->budget--) { s->failed_pc=0x0c040f5eu; return 0; }
write(ram,r[0],r[3],4);
goto P_0c040f60;
P_0c040f60: /* original e000, guest PC 0x0c040f60 */
if(!s->budget--) { s->failed_pc=0x0c040f60u; return 0; }
r[0]=0x00000000u;
goto P_0c040f62;
P_0c040f62: /* original 7f04, guest PC 0x0c040f62 */
if(!s->budget--) { s->failed_pc=0x0c040f62u; return 0; }
r[15]+=0x00000004u;
goto P_0c040f64;
P_0c040f64: /* original 000b, guest PC 0x0c040f64 */
if(!s->budget--) { s->failed_pc=0x0c040f64u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f66: /* original 0009, guest PC 0x0c040f66 */
if(!s->budget--) { s->failed_pc=0x0c040f66u; return 0; }
return vf3_matrix_family(0x0c040f68u,s,ram);
P_0c060d1e: /* original 2fe6, guest PC 0x0c060d1e */
if(!s->budget--) { s->failed_pc=0x0c060d1eu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c060d20;
P_0c060d20: /* original 2fd6, guest PC 0x0c060d20 */
if(!s->budget--) { s->failed_pc=0x0c060d20u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c060d22;
P_0c060d22: /* original 6e43, guest PC 0x0c060d22 */
if(!s->budget--) { s->failed_pc=0x0c060d22u; return 0; }
r[14]=r[4];
goto P_0c060d24;
P_0c060d24: /* original 2fc6, guest PC 0x0c060d24 */
if(!s->budget--) { s->failed_pc=0x0c060d24u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c060d26;
P_0c060d26: /* original 6d43, guest PC 0x0c060d26 */
if(!s->budget--) { s->failed_pc=0x0c060d26u; return 0; }
r[13]=r[4];
goto P_0c060d28;
P_0c060d28: /* original 4f22, guest PC 0x0c060d28 */
if(!s->budget--) { s->failed_pc=0x0c060d28u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c060d2a;
P_0c060d2a: /* original 3d5c, guest PC 0x0c060d2a */
if(!s->budget--) { s->failed_pc=0x0c060d2au; return 0; }
r[13]+=r[5];
goto P_0c060d2c;
P_0c060d2c: /* original dc3f, guest PC 0x0c060d2c */
if(!s->budget--) { s->failed_pc=0x0c060d2cu; return 0; }
r[12]=read(ram,0x0c060e2cu,4);
goto P_0c060d2e;
P_0c060d2e: /* original 3ed6, guest PC 0x0c060d2e */
if(!s->budget--) { s->failed_pc=0x0c060d2eu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[13])!=0);
goto P_0c060d30;
P_0c060d30: /* original 8904, guest PC 0x0c060d30 */
if(!s->budget--) { s->failed_pc=0x0c060d30u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060d3c; }
goto P_0c060d32;
P_0c060d32: /* original 4c0b, guest PC 0x0c060d32 */
if(!s->budget--) { s->failed_pc=0x0c060d32u; return 0; }
target=r[12];
r[16]=0x0c060d36u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c060d36u) { target=s->pc; goto dispatch; }
goto P_0c060d36;
P_0c060d34: /* original 64e3, guest PC 0x0c060d34 */
if(!s->budget--) { s->failed_pc=0x0c060d34u; return 0; }
r[4]=r[14];
goto P_0c060d36;
P_0c060d36: /* original 7e20, guest PC 0x0c060d36 */
if(!s->budget--) { s->failed_pc=0x0c060d36u; return 0; }
r[14]+=0x00000020u;
goto P_0c060d38;
P_0c060d38: /* original 3ed6, guest PC 0x0c060d38 */
if(!s->budget--) { s->failed_pc=0x0c060d38u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[13])!=0);
goto P_0c060d3a;
P_0c060d3a: /* original 8bfa, guest PC 0x0c060d3a */
if(!s->budget--) { s->failed_pc=0x0c060d3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060d32; }
goto P_0c060d3c;
P_0c060d3c: /* original 4f26, guest PC 0x0c060d3c */
if(!s->budget--) { s->failed_pc=0x0c060d3cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c060d3e;
P_0c060d3e: /* original 6cf6, guest PC 0x0c060d3e */
if(!s->budget--) { s->failed_pc=0x0c060d3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c060d40;
P_0c060d40: /* original 6df6, guest PC 0x0c060d40 */
if(!s->budget--) { s->failed_pc=0x0c060d40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c060d42;
P_0c060d42: /* original 000b, guest PC 0x0c060d42 */
if(!s->budget--) { s->failed_pc=0x0c060d42u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c060d44: /* original 6ef6, guest PC 0x0c060d44 */
if(!s->budget--) { s->failed_pc=0x0c060d44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c060d46u,s,ram);
P_0c060d78: /* original 2fe6, guest PC 0x0c060d78 */
if(!s->budget--) { s->failed_pc=0x0c060d78u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c060d7a;
P_0c060d7a: /* original 0002, guest PC 0x0c060d7a */
if(!s->budget--) { s->failed_pc=0x0c060d7au; return 0; }
r[0]=r[17];
goto P_0c060d7c;
P_0c060d7c: /* original 2fd6, guest PC 0x0c060d7c */
if(!s->budget--) { s->failed_pc=0x0c060d7cu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c060d7e;
P_0c060d7e: /* original 6e53, guest PC 0x0c060d7e */
if(!s->budget--) { s->failed_pc=0x0c060d7eu; return 0; }
r[14]=r[5];
goto P_0c060d80;
P_0c060d80: /* original 2fc6, guest PC 0x0c060d80 */
if(!s->budget--) { s->failed_pc=0x0c060d80u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c060d82;
P_0c060d82: /* original 6d43, guest PC 0x0c060d82 */
if(!s->budget--) { s->failed_pc=0x0c060d82u; return 0; }
r[13]=r[4];
goto P_0c060d84;
P_0c060d84: /* original 2fb6, guest PC 0x0c060d84 */
if(!s->budget--) { s->failed_pc=0x0c060d84u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c060d86;
P_0c060d86: /* original 4009, guest PC 0x0c060d86 */
if(!s->budget--) { s->failed_pc=0x0c060d86u; return 0; }
r[0]>>=2;
goto P_0c060d88;
P_0c060d88: /* original 2fa6, guest PC 0x0c060d88 */
if(!s->budget--) { s->failed_pc=0x0c060d88u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c060d8a;
P_0c060d8a: /* original 63d3, guest PC 0x0c060d8a */
if(!s->budget--) { s->failed_pc=0x0c060d8au; return 0; }
r[3]=r[13];
goto P_0c060d8c;
P_0c060d8c: /* original 2f96, guest PC 0x0c060d8c */
if(!s->budget--) { s->failed_pc=0x0c060d8cu; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c060d8e;
P_0c060d8e: /* original 6a63, guest PC 0x0c060d8e */
if(!s->budget--) { s->failed_pc=0x0c060d8eu; return 0; }
r[10]=r[6];
goto P_0c060d90;
P_0c060d90: /* original 2f86, guest PC 0x0c060d90 */
if(!s->budget--) { s->failed_pc=0x0c060d90u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c060d92;
P_0c060d92: /* original 4009, guest PC 0x0c060d92 */
if(!s->budget--) { s->failed_pc=0x0c060d92u; return 0; }
r[0]>>=2;
goto P_0c060d94;
P_0c060d94: /* original 4f22, guest PC 0x0c060d94 */
if(!s->budget--) { s->failed_pc=0x0c060d94u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c060d96;
P_0c060d96: /* original e91f, guest PC 0x0c060d96 */
if(!s->budget--) { s->failed_pc=0x0c060d96u; return 0; }
r[9]=0x0000001fu;
goto P_0c060d98;
P_0c060d98: /* original 7ffc, guest PC 0x0c060d98 */
if(!s->budget--) { s->failed_pc=0x0c060d98u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c060d9a;
P_0c060d9a: /* original c90f, guest PC 0x0c060d9a */
if(!s->budget--) { s->failed_pc=0x0c060d9au; return 0; }
r[0]&=15u;
goto P_0c060d9c;
P_0c060d9c: /* original 2398, guest PC 0x0c060d9c */
if(!s->budget--) { s->failed_pc=0x0c060d9cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c060d9e;
P_0c060d9e: /* original 8f31, guest PC 0x0c060d9e */
if(!s->budget--) { s->failed_pc=0x0c060d9eu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c060e04; }
goto P_0c060da2;
P_0c060da0: /* original 6403, guest PC 0x0c060da0 */
if(!s->budget--) { s->failed_pc=0x0c060da0u; return 0; }
r[4]=r[0];
goto P_0c060da2;
P_0c060da2: /* original 61e3, guest PC 0x0c060da2 */
if(!s->budget--) { s->failed_pc=0x0c060da2u; return 0; }
r[1]=r[14];
goto P_0c060da4;
P_0c060da4: /* original 2198, guest PC 0x0c060da4 */
if(!s->budget--) { s->failed_pc=0x0c060da4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[9])==0)!=0);
goto P_0c060da6;
P_0c060da6: /* original 8b2d, guest PC 0x0c060da6 */
if(!s->budget--) { s->failed_pc=0x0c060da6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060e04; }
goto P_0c060da8;
P_0c060da8: /* original 2448, guest PC 0x0c060da8 */
if(!s->budget--) { s->failed_pc=0x0c060da8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c060daa;
P_0c060daa: /* original 8b2b, guest PC 0x0c060daa */
if(!s->budget--) { s->failed_pc=0x0c060daau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060e04; }
goto P_0c060dac;
P_0c060dac: /* original 65a3, guest PC 0x0c060dac */
if(!s->budget--) { s->failed_pc=0x0c060dacu; return 0; }
r[5]=r[10];
goto P_0c060dae;
P_0c060dae: /* original bfb6, guest PC 0x0c060dae */
if(!s->budget--) { s->failed_pc=0x0c060daeu; return 0; }
target=0x0c060d1eu; r[16]=0x0c060db2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c060db2u) { target=s->pc; goto dispatch; }
goto P_0c060db2;
P_0c060db0: /* original 64e3, guest PC 0x0c060db0 */
if(!s->budget--) { s->failed_pc=0x0c060db0u; return 0; }
r[4]=r[14];
goto P_0c060db2;
P_0c060db2: /* original ece0, guest PC 0x0c060db2 */
if(!s->budget--) { s->failed_pc=0x0c060db2u; return 0; }
r[12]=0xffffffe0u;
goto P_0c060db4;
P_0c060db4: /* original d820, guest PC 0x0c060db4 */
if(!s->budget--) { s->failed_pc=0x0c060db4u; return 0; }
r[8]=read(ram,0x0c060e38u,4);
goto P_0c060db6;
P_0c060db6: /* original 2ca9, guest PC 0x0c060db6 */
if(!s->budget--) { s->failed_pc=0x0c060db6u; return 0; }
r[12]&=r[10];
goto P_0c060db8;
P_0c060db8: /* original 9b35, guest PC 0x0c060db8 */
if(!s->budget--) { s->failed_pc=0x0c060db8u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060e26u,2);
goto P_0c060dba;
P_0c060dba: /* original 38dc, guest PC 0x0c060dba */
if(!s->budget--) { s->failed_pc=0x0c060dbau; return 0; }
r[8]+=r[13];
goto P_0c060dbc;
P_0c060dbc: /* original d21f, guest PC 0x0c060dbc */
if(!s->budget--) { s->failed_pc=0x0c060dbcu; return 0; }
r[2]=read(ram,0x0c060e3cu,4);
goto P_0c060dbe;
P_0c060dbe: /* original 63f3, guest PC 0x0c060dbe */
if(!s->budget--) { s->failed_pc=0x0c060dbeu; return 0; }
r[3]=r[15];
goto P_0c060dc0;
P_0c060dc0: /* original 2f36, guest PC 0x0c060dc0 */
if(!s->budget--) { s->failed_pc=0x0c060dc0u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c060dc2;
P_0c060dc2: /* original e718, guest PC 0x0c060dc2 */
if(!s->budget--) { s->failed_pc=0x0c060dc2u; return 0; }
r[7]=0x00000018u;
goto P_0c060dc4;
P_0c060dc4: /* original 66c3, guest PC 0x0c060dc4 */
if(!s->budget--) { s->failed_pc=0x0c060dc4u; return 0; }
r[6]=r[12];
goto P_0c060dc6;
P_0c060dc6: /* original 65e3, guest PC 0x0c060dc6 */
if(!s->budget--) { s->failed_pc=0x0c060dc6u; return 0; }
r[5]=r[14];
goto P_0c060dc8;
P_0c060dc8: /* original 420b, guest PC 0x0c060dc8 */
if(!s->budget--) { s->failed_pc=0x0c060dc8u; return 0; }
target=r[2];
r[16]=0x0c060dccu;
r[4]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c060dccu) { target=s->pc; goto dispatch; }
goto P_0c060dcc;
P_0c060dca: /* original 6483, guest PC 0x0c060dca */
if(!s->budget--) { s->failed_pc=0x0c060dcau; return 0; }
r[4]=r[8];
goto P_0c060dcc;
P_0c060dcc: /* original 30b0, guest PC 0x0c060dcc */
if(!s->budget--) { s->failed_pc=0x0c060dccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[11])!=0);
goto P_0c060dce;
P_0c060dce: /* original 8df5, guest PC 0x0c060dce */
if(!s->budget--) { s->failed_pc=0x0c060dceu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c060dbc; }
goto P_0c060dd2;
P_0c060dd0: /* original 7f04, guest PC 0x0c060dd0 */
if(!s->budget--) { s->failed_pc=0x0c060dd0u; return 0; }
r[15]+=0x00000004u;
goto P_0c060dd2;
P_0c060dd2: /* original 62f2, guest PC 0x0c060dd2 */
if(!s->budget--) { s->failed_pc=0x0c060dd2u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c060dd4;
P_0c060dd4: /* original d11a, guest PC 0x0c060dd4 */
if(!s->budget--) { s->failed_pc=0x0c060dd4u; return 0; }
r[1]=read(ram,0x0c060e40u,4);
goto P_0c060dd6;
P_0c060dd6: /* original 6322, guest PC 0x0c060dd6 */
if(!s->budget--) { s->failed_pc=0x0c060dd6u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c060dd8;
P_0c060dd8: /* original 2132, guest PC 0x0c060dd8 */
if(!s->budget--) { s->failed_pc=0x0c060dd8u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c060dda;
P_0c060dda: /* original 66a3, guest PC 0x0c060dda */
if(!s->budget--) { s->failed_pc=0x0c060ddau; return 0; }
r[6]=r[10];
goto P_0c060ddc;
P_0c060ddc: /* original 2699, guest PC 0x0c060ddc */
if(!s->budget--) { s->failed_pc=0x0c060ddcu; return 0; }
r[6]&=r[9];
goto P_0c060dde;
P_0c060dde: /* original 2668, guest PC 0x0c060dde */
if(!s->budget--) { s->failed_pc=0x0c060ddeu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c060de0;
P_0c060de0: /* original 8906, guest PC 0x0c060de0 */
if(!s->budget--) { s->failed_pc=0x0c060de0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060df0; }
goto P_0c060de2;
P_0c060de2: /* original 3dcc, guest PC 0x0c060de2 */
if(!s->budget--) { s->failed_pc=0x0c060de2u; return 0; }
r[13]+=r[12];
goto P_0c060de4;
P_0c060de4: /* original d417, guest PC 0x0c060de4 */
if(!s->budget--) { s->failed_pc=0x0c060de4u; return 0; }
r[4]=read(ram,0x0c060e44u,4);
goto P_0c060de6;
P_0c060de6: /* original 3ecc, guest PC 0x0c060de6 */
if(!s->budget--) { s->failed_pc=0x0c060de6u; return 0; }
r[14]+=r[12];
goto P_0c060de8;
P_0c060de8: /* original d212, guest PC 0x0c060de8 */
if(!s->budget--) { s->failed_pc=0x0c060de8u; return 0; }
r[2]=read(ram,0x0c060e34u,4);
goto P_0c060dea;
P_0c060dea: /* original 65e3, guest PC 0x0c060dea */
if(!s->budget--) { s->failed_pc=0x0c060deau; return 0; }
r[5]=r[14];
goto P_0c060dec;
P_0c060dec: /* original 420b, guest PC 0x0c060dec */
if(!s->budget--) { s->failed_pc=0x0c060decu; return 0; }
target=r[2];
r[16]=0x0c060df0u;
r[4]+=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c060df0u) { target=s->pc; goto dispatch; }
goto P_0c060df0;
P_0c060dee: /* original 34dc, guest PC 0x0c060dee */
if(!s->budget--) { s->failed_pc=0x0c060deeu; return 0; }
r[4]+=r[13];
goto P_0c060df0;
P_0c060df0: /* original d315, guest PC 0x0c060df0 */
if(!s->budget--) { s->failed_pc=0x0c060df0u; return 0; }
r[3]=read(ram,0x0c060e48u,4);
goto P_0c060df2;
P_0c060df2: /* original 6032, guest PC 0x0c060df2 */
if(!s->budget--) { s->failed_pc=0x0c060df2u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060df4;
P_0c060df4: /* original 8801, guest PC 0x0c060df4 */
if(!s->budget--) { s->failed_pc=0x0c060df4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c060df6;
P_0c060df6: /* original 8b0b, guest PC 0x0c060df6 */
if(!s->budget--) { s->failed_pc=0x0c060df6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060e10; }
goto P_0c060df8;
P_0c060df8: /* original d111, guest PC 0x0c060df8 */
if(!s->budget--) { s->failed_pc=0x0c060df8u; return 0; }
r[1]=read(ram,0x0c060e40u,4);
goto P_0c060dfa;
P_0c060dfa: /* original d214, guest PC 0x0c060dfa */
if(!s->budget--) { s->failed_pc=0x0c060dfau; return 0; }
r[2]=read(ram,0x0c060e4cu,4);
goto P_0c060dfc;
P_0c060dfc: /* original 420b, guest PC 0x0c060dfc */
if(!s->budget--) { s->failed_pc=0x0c060dfcu; return 0; }
target=r[2];
r[16]=0x0c060e00u;
tmp=read(ram,r[1],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c060e00u) { target=s->pc; goto dispatch; }
goto P_0c060e00;
P_0c060dfe: /* original 6412, guest PC 0x0c060dfe */
if(!s->budget--) { s->failed_pc=0x0c060dfeu; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c060e00;
P_0c060e00: /* original a006, guest PC 0x0c060e00 */
if(!s->budget--) { s->failed_pc=0x0c060e00u; return 0; }
goto P_0c060e10;
P_0c060e02: /* original 0009, guest PC 0x0c060e02 */
if(!s->budget--) { s->failed_pc=0x0c060e02u; return 0; }
goto P_0c060e04;
P_0c060e04: /* original d40f, guest PC 0x0c060e04 */
if(!s->budget--) { s->failed_pc=0x0c060e04u; return 0; }
r[4]=read(ram,0x0c060e44u,4);
goto P_0c060e06;
P_0c060e06: /* original 66a3, guest PC 0x0c060e06 */
if(!s->budget--) { s->failed_pc=0x0c060e06u; return 0; }
r[6]=r[10];
goto P_0c060e08;
P_0c060e08: /* original d20a, guest PC 0x0c060e08 */
if(!s->budget--) { s->failed_pc=0x0c060e08u; return 0; }
r[2]=read(ram,0x0c060e34u,4);
goto P_0c060e0a;
P_0c060e0a: /* original 65e3, guest PC 0x0c060e0a */
if(!s->budget--) { s->failed_pc=0x0c060e0au; return 0; }
r[5]=r[14];
goto P_0c060e0c;
P_0c060e0c: /* original 420b, guest PC 0x0c060e0c */
if(!s->budget--) { s->failed_pc=0x0c060e0cu; return 0; }
target=r[2];
r[16]=0x0c060e10u;
r[4]+=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c060e10u) { target=s->pc; goto dispatch; }
goto P_0c060e10;
P_0c060e0e: /* original 34dc, guest PC 0x0c060e0e */
if(!s->budget--) { s->failed_pc=0x0c060e0eu; return 0; }
r[4]+=r[13];
goto P_0c060e10;
P_0c060e10: /* original e001, guest PC 0x0c060e10 */
if(!s->budget--) { s->failed_pc=0x0c060e10u; return 0; }
r[0]=0x00000001u;
goto P_0c060e12;
P_0c060e12: /* original 7f04, guest PC 0x0c060e12 */
if(!s->budget--) { s->failed_pc=0x0c060e12u; return 0; }
r[15]+=0x00000004u;
goto P_0c060e14;
P_0c060e14: /* original 4f26, guest PC 0x0c060e14 */
if(!s->budget--) { s->failed_pc=0x0c060e14u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c060e16;
P_0c060e16: /* original 68f6, guest PC 0x0c060e16 */
if(!s->budget--) { s->failed_pc=0x0c060e16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c060e18;
P_0c060e18: /* original 69f6, guest PC 0x0c060e18 */
if(!s->budget--) { s->failed_pc=0x0c060e18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c060e1a;
P_0c060e1a: /* original 6af6, guest PC 0x0c060e1a */
if(!s->budget--) { s->failed_pc=0x0c060e1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c060e1c;
P_0c060e1c: /* original 6bf6, guest PC 0x0c060e1c */
if(!s->budget--) { s->failed_pc=0x0c060e1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c060e1e;
P_0c060e1e: /* original 6cf6, guest PC 0x0c060e1e */
if(!s->budget--) { s->failed_pc=0x0c060e1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c060e20;
P_0c060e20: /* original 6df6, guest PC 0x0c060e20 */
if(!s->budget--) { s->failed_pc=0x0c060e20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c060e22;
P_0c060e22: /* original 000b, guest PC 0x0c060e22 */
if(!s->budget--) { s->failed_pc=0x0c060e22u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c060e24: /* original 6ef6, guest PC 0x0c060e24 */
if(!s->budget--) { s->failed_pc=0x0c060e24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c060e26u,s,ram);
P_0c062490: /* original d53f, guest PC 0x0c062490 */
if(!s->budget--) { s->failed_pc=0x0c062490u; return 0; }
r[5]=read(ram,0x0c062590u,4);
goto P_0c062492;
P_0c062492: /* original e700, guest PC 0x0c062492 */
if(!s->budget--) { s->failed_pc=0x0c062492u; return 0; }
r[7]=0x00000000u;
goto P_0c062494;
P_0c062494: /* original 9079, guest PC 0x0c062494 */
if(!s->budget--) { s->failed_pc=0x0c062494u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06258au,2);
goto P_0c062496;
P_0c062496: /* original 6453, guest PC 0x0c062496 */
if(!s->budget--) { s->failed_pc=0x0c062496u; return 0; }
r[4]=r[5];
goto P_0c062498;
P_0c062498: /* original 6653, guest PC 0x0c062498 */
if(!s->budget--) { s->failed_pc=0x0c062498u; return 0; }
r[6]=r[5];
goto P_0c06249a;
P_0c06249a: /* original e501, guest PC 0x0c06249a */
if(!s->budget--) { s->failed_pc=0x0c06249au; return 0; }
r[5]=0x00000001u;
goto P_0c06249c;
P_0c06249c: /* original 6361, guest PC 0x0c06249c */
if(!s->budget--) { s->failed_pc=0x0c06249cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[3]=tmp;
goto P_0c06249e;
P_0c06249e: /* original 633d, guest PC 0x0c06249e */
if(!s->budget--) { s->failed_pc=0x0c06249eu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0624a0;
P_0c0624a0: /* original 2358, guest PC 0x0c0624a0 */
if(!s->budget--) { s->failed_pc=0x0c0624a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0624a2;
P_0c0624a2: /* original 8b02, guest PC 0x0c0624a2 */
if(!s->budget--) { s->failed_pc=0x0c0624a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0624aa; }
goto P_0c0624a4;
P_0c0624a4: /* original 2451, guest PC 0x0c0624a4 */
if(!s->budget--) { s->failed_pc=0x0c0624a4u; return 0; }
write(ram,r[4],r[5],2);
goto P_0c0624a6;
P_0c0624a6: /* original 000b, guest PC 0x0c0624a6 */
if(!s->budget--) { s->failed_pc=0x0c0624a6u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c0624a8: /* original 6043, guest PC 0x0c0624a8 */
if(!s->budget--) { s->failed_pc=0x0c0624a8u; return 0; }
r[0]=r[4];
goto P_0c0624aa;
P_0c0624aa: /* original 7701, guest PC 0x0c0624aa */
if(!s->budget--) { s->failed_pc=0x0c0624aau; return 0; }
r[7]+=0x00000001u;
goto P_0c0624ac;
P_0c0624ac: /* original 7418, guest PC 0x0c0624ac */
if(!s->budget--) { s->failed_pc=0x0c0624acu; return 0; }
r[4]+=0x00000018u;
goto P_0c0624ae;
P_0c0624ae: /* original 3703, guest PC 0x0c0624ae */
if(!s->budget--) { s->failed_pc=0x0c0624aeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[0])!=0);
goto P_0c0624b0;
P_0c0624b0: /* original 8ff4, guest PC 0x0c0624b0 */
if(!s->budget--) { s->failed_pc=0x0c0624b0u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000018u;
if(!cond) { goto P_0c06249c; }
goto P_0c0624b4;
P_0c0624b2: /* original 7618, guest PC 0x0c0624b2 */
if(!s->budget--) { s->failed_pc=0x0c0624b2u; return 0; }
r[6]+=0x00000018u;
goto P_0c0624b4;
P_0c0624b4: /* original e000, guest PC 0x0c0624b4 */
if(!s->budget--) { s->failed_pc=0x0c0624b4u; return 0; }
r[0]=0x00000000u;
goto P_0c0624b6;
P_0c0624b6: /* original 000b, guest PC 0x0c0624b6 */
if(!s->budget--) { s->failed_pc=0x0c0624b6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0624b8: /* original 0009, guest PC 0x0c0624b8 */
if(!s->budget--) { s->failed_pc=0x0c0624b8u; return 0; }
goto P_0c0624ba;
P_0c0624ba: /* original e700, guest PC 0x0c0624ba */
if(!s->budget--) { s->failed_pc=0x0c0624bau; return 0; }
r[7]=0x00000000u;
goto P_0c0624bc;
P_0c0624bc: /* original d534, guest PC 0x0c0624bc */
if(!s->budget--) { s->failed_pc=0x0c0624bcu; return 0; }
r[5]=read(ram,0x0c062590u,4);
goto P_0c0624be;
P_0c0624be: /* original 2fd6, guest PC 0x0c0624be */
if(!s->budget--) { s->failed_pc=0x0c0624beu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0624c0;
P_0c0624c0: /* original dd34, guest PC 0x0c0624c0 */
if(!s->budget--) { s->failed_pc=0x0c0624c0u; return 0; }
r[13]=read(ram,0x0c062594u,4);
goto P_0c0624c2;
P_0c0624c2: /* original 6653, guest PC 0x0c0624c2 */
if(!s->budget--) { s->failed_pc=0x0c0624c2u; return 0; }
r[6]=r[5];
goto P_0c0624c4;
P_0c0624c4: /* original 9161, guest PC 0x0c0624c4 */
if(!s->budget--) { s->failed_pc=0x0c0624c4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06258au,2);
goto P_0c0624c6;
P_0c0624c6: /* original 7ffc, guest PC 0x0c0624c6 */
if(!s->budget--) { s->failed_pc=0x0c0624c6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0624c8;
P_0c0624c8: /* original 2f52, guest PC 0x0c0624c8 */
if(!s->budget--) { s->failed_pc=0x0c0624c8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0624ca;
P_0c0624ca: /* original 3640, guest PC 0x0c0624ca */
if(!s->budget--) { s->failed_pc=0x0c0624cau; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[4])!=0);
goto P_0c0624cc;
P_0c0624cc: /* original 8f03, guest PC 0x0c0624cc */
if(!s->budget--) { s->failed_pc=0x0c0624ccu; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(!cond) { goto P_0c0624d6; }
goto P_0c0624d0;
P_0c0624ce: /* original 7701, guest PC 0x0c0624ce */
if(!s->budget--) { s->failed_pc=0x0c0624ceu; return 0; }
r[7]+=0x00000001u;
goto P_0c0624d0;
P_0c0624d0: /* original 6251, guest PC 0x0c0624d0 */
if(!s->budget--) { s->failed_pc=0x0c0624d0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c0624d2;
P_0c0624d2: /* original 22d9, guest PC 0x0c0624d2 */
if(!s->budget--) { s->failed_pc=0x0c0624d2u; return 0; }
r[2]&=r[13];
goto P_0c0624d4;
P_0c0624d4: /* original 2521, guest PC 0x0c0624d4 */
if(!s->budget--) { s->failed_pc=0x0c0624d4u; return 0; }
write(ram,r[5],r[2],2);
goto P_0c0624d6;
P_0c0624d6: /* original 7518, guest PC 0x0c0624d6 */
if(!s->budget--) { s->failed_pc=0x0c0624d6u; return 0; }
r[5]+=0x00000018u;
goto P_0c0624d8;
P_0c0624d8: /* original 3713, guest PC 0x0c0624d8 */
if(!s->budget--) { s->failed_pc=0x0c0624d8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[1])!=0);
goto P_0c0624da;
P_0c0624da: /* original 8ff6, guest PC 0x0c0624da */
if(!s->budget--) { s->failed_pc=0x0c0624dau; return 0; }
cond=r[17]&1u;
r[6]+=0x00000018u;
if(!cond) { goto P_0c0624ca; }
goto P_0c0624de;
P_0c0624dc: /* original 7618, guest PC 0x0c0624dc */
if(!s->budget--) { s->failed_pc=0x0c0624dcu; return 0; }
r[6]+=0x00000018u;
goto P_0c0624de;
P_0c0624de: /* original 7f04, guest PC 0x0c0624de */
if(!s->budget--) { s->failed_pc=0x0c0624deu; return 0; }
r[15]+=0x00000004u;
goto P_0c0624e0;
P_0c0624e0: /* original 000b, guest PC 0x0c0624e0 */
if(!s->budget--) { s->failed_pc=0x0c0624e0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c0624e2: /* original 6df6, guest PC 0x0c0624e2 */
if(!s->budget--) { s->failed_pc=0x0c0624e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0624e4;
P_0c0624e4: /* original 6342, guest PC 0x0c0624e4 */
if(!s->budget--) { s->failed_pc=0x0c0624e4u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0624e6;
P_0c0624e6: /* original 2338, guest PC 0x0c0624e6 */
if(!s->budget--) { s->failed_pc=0x0c0624e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0624e8;
P_0c0624e8: /* original 8b05, guest PC 0x0c0624e8 */
if(!s->budget--) { s->failed_pc=0x0c0624e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0624f6; }
goto P_0c0624ea;
P_0c0624ea: /* original e700, guest PC 0x0c0624ea */
if(!s->budget--) { s->failed_pc=0x0c0624eau; return 0; }
r[7]=0x00000000u;
goto P_0c0624ec;
P_0c0624ec: /* original 1671, guest PC 0x0c0624ec */
if(!s->budget--) { s->failed_pc=0x0c0624ecu; return 0; }
write(ram,r[6]+4,r[7],4);
goto P_0c0624ee;
P_0c0624ee: /* original 1672, guest PC 0x0c0624ee */
if(!s->budget--) { s->failed_pc=0x0c0624eeu; return 0; }
write(ram,r[6]+8,r[7],4);
goto P_0c0624f0;
P_0c0624f0: /* original 2462, guest PC 0x0c0624f0 */
if(!s->budget--) { s->failed_pc=0x0c0624f0u; return 0; }
write(ram,r[4],r[6],4);
goto P_0c0624f2;
P_0c0624f2: /* original a007, guest PC 0x0c0624f2 */
if(!s->budget--) { s->failed_pc=0x0c0624f2u; return 0; }
write(ram,r[5],r[6],4);
goto P_0c062504;
P_0c0624f4: /* original 2562, guest PC 0x0c0624f4 */
if(!s->budget--) { s->failed_pc=0x0c0624f4u; return 0; }
write(ram,r[5],r[6],4);
goto P_0c0624f6;
P_0c0624f6: /* original 6542, guest PC 0x0c0624f6 */
if(!s->budget--) { s->failed_pc=0x0c0624f6u; return 0; }
tmp=read(ram,r[4],4);
r[5]=tmp;
goto P_0c0624f8;
P_0c0624f8: /* original 5251, guest PC 0x0c0624f8 */
if(!s->budget--) { s->failed_pc=0x0c0624f8u; return 0; }
r[2]=read(ram,r[5]+4,4);
goto P_0c0624fa;
P_0c0624fa: /* original 1621, guest PC 0x0c0624fa */
if(!s->budget--) { s->failed_pc=0x0c0624fau; return 0; }
write(ram,r[6]+4,r[2],4);
goto P_0c0624fc;
P_0c0624fc: /* original 6342, guest PC 0x0c0624fc */
if(!s->budget--) { s->failed_pc=0x0c0624fcu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0624fe;
P_0c0624fe: /* original 1632, guest PC 0x0c0624fe */
if(!s->budget--) { s->failed_pc=0x0c0624feu; return 0; }
write(ram,r[6]+8,r[3],4);
goto P_0c062500;
P_0c062500: /* original 1561, guest PC 0x0c062500 */
if(!s->budget--) { s->failed_pc=0x0c062500u; return 0; }
write(ram,r[5]+4,r[6],4);
goto P_0c062502;
P_0c062502: /* original 2462, guest PC 0x0c062502 */
if(!s->budget--) { s->failed_pc=0x0c062502u; return 0; }
write(ram,r[4],r[6],4);
goto P_0c062504;
P_0c062504: /* original 000b, guest PC 0x0c062504 */
if(!s->budget--) { s->failed_pc=0x0c062504u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062506: /* original 0009, guest PC 0x0c062506 */
if(!s->budget--) { s->failed_pc=0x0c062506u; return 0; }
goto P_0c062508;
P_0c062508: /* original 5362, guest PC 0x0c062508 */
if(!s->budget--) { s->failed_pc=0x0c062508u; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c06250a;
P_0c06250a: /* original 2338, guest PC 0x0c06250a */
if(!s->budget--) { s->failed_pc=0x0c06250au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06250c;
P_0c06250c: /* original 8b03, guest PC 0x0c06250c */
if(!s->budget--) { s->failed_pc=0x0c06250cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062516; }
goto P_0c06250e;
P_0c06250e: /* original 2452, guest PC 0x0c06250e */
if(!s->budget--) { s->failed_pc=0x0c06250eu; return 0; }
write(ram,r[4],r[5],4);
goto P_0c062510;
P_0c062510: /* original 1561, guest PC 0x0c062510 */
if(!s->budget--) { s->failed_pc=0x0c062510u; return 0; }
write(ram,r[5]+4,r[6],4);
goto P_0c062512;
P_0c062512: /* original a004, guest PC 0x0c062512 */
if(!s->budget--) { s->failed_pc=0x0c062512u; return 0; }
r[3]=0x00000000u;
goto P_0c06251e;
P_0c062514: /* original e300, guest PC 0x0c062514 */
if(!s->budget--) { s->failed_pc=0x0c062514u; return 0; }
r[3]=0x00000000u;
goto P_0c062516;
P_0c062516: /* original 5462, guest PC 0x0c062516 */
if(!s->budget--) { s->failed_pc=0x0c062516u; return 0; }
r[4]=read(ram,r[6]+8,4);
goto P_0c062518;
P_0c062518: /* original 1451, guest PC 0x0c062518 */
if(!s->budget--) { s->failed_pc=0x0c062518u; return 0; }
write(ram,r[4]+4,r[5],4);
goto P_0c06251a;
P_0c06251a: /* original 1561, guest PC 0x0c06251a */
if(!s->budget--) { s->failed_pc=0x0c06251au; return 0; }
write(ram,r[5]+4,r[6],4);
goto P_0c06251c;
P_0c06251c: /* original 5362, guest PC 0x0c06251c */
if(!s->budget--) { s->failed_pc=0x0c06251cu; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c06251e;
P_0c06251e: /* original 1532, guest PC 0x0c06251e */
if(!s->budget--) { s->failed_pc=0x0c06251eu; return 0; }
write(ram,r[5]+8,r[3],4);
goto P_0c062520;
P_0c062520: /* original 000b, guest PC 0x0c062520 */
if(!s->budget--) { s->failed_pc=0x0c062520u; return 0; }
target=r[16];
write(ram,r[6]+8,r[5],4);
s->pc=target; return ram->oob==0;
P_0c062522: /* original 1652, guest PC 0x0c062522 */
if(!s->budget--) { s->failed_pc=0x0c062522u; return 0; }
write(ram,r[6]+8,r[5],4);
goto P_0c062524;
P_0c062524: /* original 7ff8, guest PC 0x0c062524 */
if(!s->budget--) { s->failed_pc=0x0c062524u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c062526;
P_0c062526: /* original 5761, guest PC 0x0c062526 */
if(!s->budget--) { s->failed_pc=0x0c062526u; return 0; }
r[7]=read(ram,r[6]+4,4);
goto P_0c062528;
P_0c062528: /* original 2f72, guest PC 0x0c062528 */
if(!s->budget--) { s->failed_pc=0x0c062528u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c06252a;
P_0c06252a: /* original 2778, guest PC 0x0c06252a */
if(!s->budget--) { s->failed_pc=0x0c06252au; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c06252c;
P_0c06252c: /* original 5362, guest PC 0x0c06252c */
if(!s->budget--) { s->failed_pc=0x0c06252cu; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c06252e;
P_0c06252e: /* original 8f03, guest PC 0x0c06252e */
if(!s->budget--) { s->failed_pc=0x0c06252eu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[3],4);
if(!cond) { goto P_0c062538; }
goto P_0c062532;
P_0c062530: /* original 1f31, guest PC 0x0c062530 */
if(!s->budget--) { s->failed_pc=0x0c062530u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c062532;
P_0c062532: /* original 5162, guest PC 0x0c062532 */
if(!s->budget--) { s->failed_pc=0x0c062532u; return 0; }
r[1]=read(ram,r[6]+8,4);
goto P_0c062534;
P_0c062534: /* original a003, guest PC 0x0c062534 */
if(!s->budget--) { s->failed_pc=0x0c062534u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c06253e;
P_0c062536: /* original 2412, guest PC 0x0c062536 */
if(!s->budget--) { s->failed_pc=0x0c062536u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c062538;
P_0c062538: /* original 62f2, guest PC 0x0c062538 */
if(!s->budget--) { s->failed_pc=0x0c062538u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c06253a;
P_0c06253a: /* original 5362, guest PC 0x0c06253a */
if(!s->budget--) { s->failed_pc=0x0c06253au; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c06253c;
P_0c06253c: /* original 1232, guest PC 0x0c06253c */
if(!s->budget--) { s->failed_pc=0x0c06253cu; return 0; }
write(ram,r[2]+8,r[3],4);
goto P_0c06253e;
P_0c06253e: /* original 5262, guest PC 0x0c06253e */
if(!s->budget--) { s->failed_pc=0x0c06253eu; return 0; }
r[2]=read(ram,r[6]+8,4);
goto P_0c062540;
P_0c062540: /* original 2228, guest PC 0x0c062540 */
if(!s->budget--) { s->failed_pc=0x0c062540u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c062542;
P_0c062542: /* original 8b02, guest PC 0x0c062542 */
if(!s->budget--) { s->failed_pc=0x0c062542u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06254a; }
goto P_0c062544;
P_0c062544: /* original 5261, guest PC 0x0c062544 */
if(!s->budget--) { s->failed_pc=0x0c062544u; return 0; }
r[2]=read(ram,r[6]+4,4);
goto P_0c062546;
P_0c062546: /* original a003, guest PC 0x0c062546 */
if(!s->budget--) { s->failed_pc=0x0c062546u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c062550;
P_0c062548: /* original 2522, guest PC 0x0c062548 */
if(!s->budget--) { s->failed_pc=0x0c062548u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c06254a;
P_0c06254a: /* original 51f1, guest PC 0x0c06254a */
if(!s->budget--) { s->failed_pc=0x0c06254au; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c06254c;
P_0c06254c: /* original 5361, guest PC 0x0c06254c */
if(!s->budget--) { s->failed_pc=0x0c06254cu; return 0; }
r[3]=read(ram,r[6]+4,4);
goto P_0c06254e;
P_0c06254e: /* original 1131, guest PC 0x0c06254e */
if(!s->budget--) { s->failed_pc=0x0c06254eu; return 0; }
write(ram,r[1]+4,r[3],4);
goto P_0c062550;
P_0c062550: /* original 000b, guest PC 0x0c062550 */
if(!s->budget--) { s->failed_pc=0x0c062550u; return 0; }
target=r[16];
r[15]+=0x00000008u;
s->pc=target; return ram->oob==0;
P_0c062552: /* original 7f08, guest PC 0x0c062552 */
if(!s->budget--) { s->failed_pc=0x0c062552u; return 0; }
r[15]+=0x00000008u;
goto P_0c062554;
P_0c062554: /* original 2fe6, guest PC 0x0c062554 */
if(!s->budget--) { s->failed_pc=0x0c062554u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c062556;
P_0c062556: /* original 2fd6, guest PC 0x0c062556 */
if(!s->budget--) { s->failed_pc=0x0c062556u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c062558;
P_0c062558: /* original 2fc6, guest PC 0x0c062558 */
if(!s->budget--) { s->failed_pc=0x0c062558u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c06255a;
P_0c06255a: /* original 6d63, guest PC 0x0c06255a */
if(!s->budget--) { s->failed_pc=0x0c06255au; return 0; }
r[13]=r[6];
goto P_0c06255c;
P_0c06255c: /* original 9e17, guest PC 0x0c06255c */
if(!s->budget--) { s->failed_pc=0x0c06255cu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06258eu,2);
goto P_0c06255e;
P_0c06255e: /* original 2fb6, guest PC 0x0c06255e */
if(!s->budget--) { s->failed_pc=0x0c06255eu; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c062560;
P_0c062560: /* original 2fa6, guest PC 0x0c062560 */
if(!s->budget--) { s->failed_pc=0x0c062560u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c062562;
P_0c062562: /* original 3de6, guest PC 0x0c062562 */
if(!s->budget--) { s->failed_pc=0x0c062562u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>r[14])!=0);
goto P_0c062564;
P_0c062564: /* original 9012, guest PC 0x0c062564 */
if(!s->budget--) { s->failed_pc=0x0c062564u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06258cu,2);
goto P_0c062566;
P_0c062566: /* original 2f96, guest PC 0x0c062566 */
if(!s->budget--) { s->failed_pc=0x0c062566u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c062568;
P_0c062568: /* original 2f86, guest PC 0x0c062568 */
if(!s->budget--) { s->failed_pc=0x0c062568u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c06256a;
P_0c06256a: /* original 6943, guest PC 0x0c06256a */
if(!s->budget--) { s->failed_pc=0x0c06256au; return 0; }
r[9]=r[4];
goto P_0c06256c;
P_0c06256c: /* original da0a, guest PC 0x0c06256c */
if(!s->budget--) { s->failed_pc=0x0c06256cu; return 0; }
r[10]=read(ram,0x0c062598u,4);
goto P_0c06256e;
P_0c06256e: /* original 4f22, guest PC 0x0c06256e */
if(!s->budget--) { s->failed_pc=0x0c06256eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c062570;
P_0c062570: /* original 3f0c, guest PC 0x0c062570 */
if(!s->budget--) { s->failed_pc=0x0c062570u; return 0; }
r[15]+=r[0];
goto P_0c062572;
P_0c062572: /* original 8f27, guest PC 0x0c062572 */
if(!s->budget--) { s->failed_pc=0x0c062572u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[5],4);
if(!cond) { goto P_0c0625c4; }
goto P_0c062576;
P_0c062574: /* original 2f52, guest PC 0x0c062574 */
if(!s->budget--) { s->failed_pc=0x0c062574u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c062576;
P_0c062576: /* original 68f3, guest PC 0x0c062576 */
if(!s->budget--) { s->failed_pc=0x0c062576u; return 0; }
r[8]=r[15];
goto P_0c062578;
P_0c062578: /* original 7808, guest PC 0x0c062578 */
if(!s->budget--) { s->failed_pc=0x0c062578u; return 0; }
r[8]+=0x00000008u;
goto P_0c06257a;
P_0c06257a: /* original 66e3, guest PC 0x0c06257a */
if(!s->budget--) { s->failed_pc=0x0c06257au; return 0; }
r[6]=r[14];
goto P_0c06257c;
P_0c06257c: /* original 65f2, guest PC 0x0c06257c */
if(!s->budget--) { s->failed_pc=0x0c06257cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06257e;
P_0c06257e: /* original d307, guest PC 0x0c06257e */
if(!s->budget--) { s->failed_pc=0x0c06257eu; return 0; }
r[3]=read(ram,0x0c06259cu,4);
goto P_0c062580;
P_0c062580: /* original 430b, guest PC 0x0c062580 */
if(!s->budget--) { s->failed_pc=0x0c062580u; return 0; }
target=r[3];
r[16]=0x0c062584u;
r[4]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c062584u) { target=s->pc; goto dispatch; }
goto P_0c062584;
P_0c062582: /* original 6483, guest PC 0x0c062582 */
if(!s->budget--) { s->failed_pc=0x0c062582u; return 0; }
r[4]=r[8];
goto P_0c062584;
P_0c062584: /* original 6c83, guest PC 0x0c062584 */
if(!s->budget--) { s->failed_pc=0x0c062584u; return 0; }
r[12]=r[8];
goto P_0c062586;
P_0c062586: /* original a00f, guest PC 0x0c062586 */
if(!s->budget--) { s->failed_pc=0x0c062586u; return 0; }
r[11]=0x00000040u;
goto P_0c0625a8;
P_0c062588: /* original eb40, guest PC 0x0c062588 */
if(!s->budget--) { s->failed_pc=0x0c062588u; return 0; }
r[11]=0x00000040u;
return vf3_matrix_family(0x0c06258au,s,ram);
P_0c0625a0: /* original 4a0b, guest PC 0x0c0625a0 */
if(!s->budget--) { s->failed_pc=0x0c0625a0u; return 0; }
target=r[10];
r[16]=0x0c0625a4u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0625a4u) { target=s->pc; goto dispatch; }
goto P_0c0625a4;
P_0c0625a2: /* original 64c3, guest PC 0x0c0625a2 */
if(!s->budget--) { s->failed_pc=0x0c0625a2u; return 0; }
r[4]=r[12];
goto P_0c0625a4;
P_0c0625a4: /* original 7c20, guest PC 0x0c0625a4 */
if(!s->budget--) { s->failed_pc=0x0c0625a4u; return 0; }
r[12]+=0x00000020u;
goto P_0c0625a6;
P_0c0625a6: /* original 7bff, guest PC 0x0c0625a6 */
if(!s->budget--) { s->failed_pc=0x0c0625a6u; return 0; }
r[11]+=0xffffffffu;
goto P_0c0625a8;
P_0c0625a8: /* original 2bb8, guest PC 0x0c0625a8 */
if(!s->budget--) { s->failed_pc=0x0c0625a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0625aa;
P_0c0625aa: /* original 8bf9, guest PC 0x0c0625aa */
if(!s->budget--) { s->failed_pc=0x0c0625aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0625a0; }
goto P_0c0625ac;
P_0c0625ac: /* original d23e, guest PC 0x0c0625ac */
if(!s->budget--) { s->failed_pc=0x0c0625acu; return 0; }
r[2]=read(ram,0x0c0626a8u,4);
goto P_0c0625ae;
P_0c0625ae: /* original 66e3, guest PC 0x0c0625ae */
if(!s->budget--) { s->failed_pc=0x0c0625aeu; return 0; }
r[6]=r[14];
goto P_0c0625b0;
P_0c0625b0: /* original 6583, guest PC 0x0c0625b0 */
if(!s->budget--) { s->failed_pc=0x0c0625b0u; return 0; }
r[5]=r[8];
goto P_0c0625b2;
P_0c0625b2: /* original 420b, guest PC 0x0c0625b2 */
if(!s->budget--) { s->failed_pc=0x0c0625b2u; return 0; }
target=r[2];
r[16]=0x0c0625b6u;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0625b6u) { target=s->pc; goto dispatch; }
goto P_0c0625b6;
P_0c0625b4: /* original 6493, guest PC 0x0c0625b4 */
if(!s->budget--) { s->failed_pc=0x0c0625b4u; return 0; }
r[4]=r[9];
goto P_0c0625b6;
P_0c0625b6: /* original 3de8, guest PC 0x0c0625b6 */
if(!s->budget--) { s->failed_pc=0x0c0625b6u; return 0; }
r[13]-=r[14];
goto P_0c0625b8;
P_0c0625b8: /* original 63f2, guest PC 0x0c0625b8 */
if(!s->budget--) { s->failed_pc=0x0c0625b8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0625ba;
P_0c0625ba: /* original 3de6, guest PC 0x0c0625ba */
if(!s->budget--) { s->failed_pc=0x0c0625bau; return 0; }
r[17]=(r[17]&~1u)|((r[13]>r[14])!=0);
goto P_0c0625bc;
P_0c0625bc: /* original 33ec, guest PC 0x0c0625bc */
if(!s->budget--) { s->failed_pc=0x0c0625bcu; return 0; }
r[3]+=r[14];
goto P_0c0625be;
P_0c0625be: /* original 2f32, guest PC 0x0c0625be */
if(!s->budget--) { s->failed_pc=0x0c0625beu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0625c0;
P_0c0625c0: /* original 8ddb, guest PC 0x0c0625c0 */
if(!s->budget--) { s->failed_pc=0x0c0625c0u; return 0; }
cond=r[17]&1u;
r[9]+=r[14];
if(cond) { goto P_0c06257a; }
goto P_0c0625c4;
P_0c0625c2: /* original 39ec, guest PC 0x0c0625c2 */
if(!s->budget--) { s->failed_pc=0x0c0625c2u; return 0; }
r[9]+=r[14];
goto P_0c0625c4;
P_0c0625c4: /* original 65f2, guest PC 0x0c0625c4 */
if(!s->budget--) { s->failed_pc=0x0c0625c4u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0625c6;
P_0c0625c6: /* original 64f3, guest PC 0x0c0625c6 */
if(!s->budget--) { s->failed_pc=0x0c0625c6u; return 0; }
r[4]=r[15];
goto P_0c0625c8;
P_0c0625c8: /* original d338, guest PC 0x0c0625c8 */
if(!s->budget--) { s->failed_pc=0x0c0625c8u; return 0; }
r[3]=read(ram,0x0c0626acu,4);
goto P_0c0625ca;
P_0c0625ca: /* original 66d3, guest PC 0x0c0625ca */
if(!s->budget--) { s->failed_pc=0x0c0625cau; return 0; }
r[6]=r[13];
goto P_0c0625cc;
P_0c0625cc: /* original 7408, guest PC 0x0c0625cc */
if(!s->budget--) { s->failed_pc=0x0c0625ccu; return 0; }
r[4]+=0x00000008u;
goto P_0c0625ce;
P_0c0625ce: /* original 430b, guest PC 0x0c0625ce */
if(!s->budget--) { s->failed_pc=0x0c0625ceu; return 0; }
target=r[3];
r[16]=0x0c0625d2u;
write(ram,r[15]+4,r[4],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0625d2u) { target=s->pc; goto dispatch; }
goto P_0c0625d2;
P_0c0625d0: /* original 1f41, guest PC 0x0c0625d0 */
if(!s->budget--) { s->failed_pc=0x0c0625d0u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0625d2;
P_0c0625d2: /* original 5ef1, guest PC 0x0c0625d2 */
if(!s->budget--) { s->failed_pc=0x0c0625d2u; return 0; }
r[14]=read(ram,r[15]+4,4);
goto P_0c0625d4;
P_0c0625d4: /* original a004, guest PC 0x0c0625d4 */
if(!s->budget--) { s->failed_pc=0x0c0625d4u; return 0; }
r[12]=0x00000040u;
goto P_0c0625e0;
P_0c0625d6: /* original ec40, guest PC 0x0c0625d6 */
if(!s->budget--) { s->failed_pc=0x0c0625d6u; return 0; }
r[12]=0x00000040u;
goto P_0c0625d8;
P_0c0625d8: /* original 4a0b, guest PC 0x0c0625d8 */
if(!s->budget--) { s->failed_pc=0x0c0625d8u; return 0; }
target=r[10];
r[16]=0x0c0625dcu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0625dcu) { target=s->pc; goto dispatch; }
goto P_0c0625dc;
P_0c0625da: /* original 64e3, guest PC 0x0c0625da */
if(!s->budget--) { s->failed_pc=0x0c0625dau; return 0; }
r[4]=r[14];
goto P_0c0625dc;
P_0c0625dc: /* original 7e20, guest PC 0x0c0625dc */
if(!s->budget--) { s->failed_pc=0x0c0625dcu; return 0; }
r[14]+=0x00000020u;
goto P_0c0625de;
P_0c0625de: /* original 7cff, guest PC 0x0c0625de */
if(!s->budget--) { s->failed_pc=0x0c0625deu; return 0; }
r[12]+=0xffffffffu;
goto P_0c0625e0;
P_0c0625e0: /* original 2cc8, guest PC 0x0c0625e0 */
if(!s->budget--) { s->failed_pc=0x0c0625e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0625e2;
P_0c0625e2: /* original 8bf9, guest PC 0x0c0625e2 */
if(!s->budget--) { s->failed_pc=0x0c0625e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0625d8; }
goto P_0c0625e4;
P_0c0625e4: /* original 55f1, guest PC 0x0c0625e4 */
if(!s->budget--) { s->failed_pc=0x0c0625e4u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0625e6;
P_0c0625e6: /* original 66d3, guest PC 0x0c0625e6 */
if(!s->budget--) { s->failed_pc=0x0c0625e6u; return 0; }
r[6]=r[13];
goto P_0c0625e8;
P_0c0625e8: /* original d32f, guest PC 0x0c0625e8 */
if(!s->budget--) { s->failed_pc=0x0c0625e8u; return 0; }
r[3]=read(ram,0x0c0626a8u,4);
goto P_0c0625ea;
P_0c0625ea: /* original 430b, guest PC 0x0c0625ea */
if(!s->budget--) { s->failed_pc=0x0c0625eau; return 0; }
target=r[3];
r[16]=0x0c0625eeu;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0625eeu) { target=s->pc; goto dispatch; }
goto P_0c0625ee;
P_0c0625ec: /* original 6493, guest PC 0x0c0625ec */
if(!s->budget--) { s->failed_pc=0x0c0625ecu; return 0; }
r[4]=r[9];
goto P_0c0625ee;
P_0c0625ee: /* original 9159, guest PC 0x0c0625ee */
if(!s->budget--) { s->failed_pc=0x0c0625eeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0626a4u,2);
goto P_0c0625f0;
P_0c0625f0: /* original 3f1c, guest PC 0x0c0625f0 */
if(!s->budget--) { s->failed_pc=0x0c0625f0u; return 0; }
r[15]+=r[1];
goto P_0c0625f2;
P_0c0625f2: /* original 4f26, guest PC 0x0c0625f2 */
if(!s->budget--) { s->failed_pc=0x0c0625f2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0625f4;
P_0c0625f4: /* original 68f6, guest PC 0x0c0625f4 */
if(!s->budget--) { s->failed_pc=0x0c0625f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0625f6;
P_0c0625f6: /* original 69f6, guest PC 0x0c0625f6 */
if(!s->budget--) { s->failed_pc=0x0c0625f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0625f8;
P_0c0625f8: /* original 6af6, guest PC 0x0c0625f8 */
if(!s->budget--) { s->failed_pc=0x0c0625f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0625fa;
P_0c0625fa: /* original 6bf6, guest PC 0x0c0625fa */
if(!s->budget--) { s->failed_pc=0x0c0625fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0625fc;
P_0c0625fc: /* original 6cf6, guest PC 0x0c0625fc */
if(!s->budget--) { s->failed_pc=0x0c0625fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0625fe;
P_0c0625fe: /* original 6df6, guest PC 0x0c0625fe */
if(!s->budget--) { s->failed_pc=0x0c0625feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c062600;
P_0c062600: /* original 000b, guest PC 0x0c062600 */
if(!s->budget--) { s->failed_pc=0x0c062600u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c062602: /* original 6ef6, guest PC 0x0c062602 */
if(!s->budget--) { s->failed_pc=0x0c062602u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c062604u,s,ram);
P_0c0626c0: /* original 4f22, guest PC 0x0c0626c0 */
if(!s->budget--) { s->failed_pc=0x0c0626c0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0626c2;
P_0c0626c2: /* original 6e92, guest PC 0x0c0626c2 */
if(!s->budget--) { s->failed_pc=0x0c0626c2u; return 0; }
tmp=read(ram,r[9],4);
r[14]=tmp;
goto P_0c0626c4;
P_0c0626c4: /* original 2ee8, guest PC 0x0c0626c4 */
if(!s->budget--) { s->failed_pc=0x0c0626c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0626c6;
P_0c0626c6: /* original 8f02, guest PC 0x0c0626c6 */
if(!s->budget--) { s->failed_pc=0x0c0626c6u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[6],4);
r[13]=tmp;
if(!cond) { goto P_0c0626ce; }
goto P_0c0626ca;
P_0c0626c8: /* original 6d62, guest PC 0x0c0626c8 */
if(!s->budget--) { s->failed_pc=0x0c0626c8u; return 0; }
tmp=read(ram,r[6],4);
r[13]=tmp;
goto P_0c0626ca;
P_0c0626ca: /* original a0d6, guest PC 0x0c0626ca */
if(!s->budget--) { s->failed_pc=0x0c0626cau; return 0; }
goto P_0c06287a;
P_0c0626cc: /* original 0009, guest PC 0x0c0626cc */
if(!s->budget--) { s->failed_pc=0x0c0626ccu; return 0; }
goto P_0c0626ce;
P_0c0626ce: /* original 2dd8, guest PC 0x0c0626ce */
if(!s->budget--) { s->failed_pc=0x0c0626ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0626d0;
P_0c0626d0: /* original 8b01, guest PC 0x0c0626d0 */
if(!s->budget--) { s->failed_pc=0x0c0626d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0626d6; }
goto P_0c0626d2;
P_0c0626d2: /* original a0d2, guest PC 0x0c0626d2 */
if(!s->budget--) { s->failed_pc=0x0c0626d2u; return 0; }
goto P_0c06287a;
P_0c0626d4: /* original 0009, guest PC 0x0c0626d4 */
if(!s->budget--) { s->failed_pc=0x0c0626d4u; return 0; }
goto P_0c0626d6;
P_0c0626d6: /* original e520, guest PC 0x0c0626d6 */
if(!s->budget--) { s->failed_pc=0x0c0626d6u; return 0; }
r[5]=0x00000020u;
goto P_0c0626d8;
P_0c0626d8: /* original 64d1, guest PC 0x0c0626d8 */
if(!s->budget--) { s->failed_pc=0x0c0626d8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[4]=tmp;
goto P_0c0626da;
P_0c0626da: /* original 644d, guest PC 0x0c0626da */
if(!s->budget--) { s->failed_pc=0x0c0626dau; return 0; }
r[4]=r[4]&65535u;
goto P_0c0626dc;
P_0c0626dc: /* original 6243, guest PC 0x0c0626dc */
if(!s->budget--) { s->failed_pc=0x0c0626dcu; return 0; }
r[2]=r[4];
goto P_0c0626de;
P_0c0626de: /* original 2258, guest PC 0x0c0626de */
if(!s->budget--) { s->failed_pc=0x0c0626deu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0626e0;
P_0c0626e0: /* original 8f0f, guest PC 0x0c0626e0 */
if(!s->budget--) { s->failed_pc=0x0c0626e0u; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(!cond) { goto P_0c062702; }
goto P_0c0626e4;
P_0c0626e2: /* original ec00, guest PC 0x0c0626e2 */
if(!s->budget--) { s->failed_pc=0x0c0626e2u; return 0; }
r[12]=0x00000000u;
goto P_0c0626e4;
P_0c0626e4: /* original e140, guest PC 0x0c0626e4 */
if(!s->budget--) { s->failed_pc=0x0c0626e4u; return 0; }
r[1]=0x00000040u;
goto P_0c0626e6;
P_0c0626e6: /* original 2148, guest PC 0x0c0626e6 */
if(!s->budget--) { s->failed_pc=0x0c0626e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c0626e8;
P_0c0626e8: /* original 8b0b, guest PC 0x0c0626e8 */
if(!s->budget--) { s->failed_pc=0x0c0626e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062702; }
goto P_0c0626ea;
P_0c0626ea: /* original e202, guest PC 0x0c0626ea */
if(!s->budget--) { s->failed_pc=0x0c0626eau; return 0; }
r[2]=0x00000002u;
goto P_0c0626ec;
P_0c0626ec: /* original 2248, guest PC 0x0c0626ec */
if(!s->budget--) { s->failed_pc=0x0c0626ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0626ee;
P_0c0626ee: /* original 8b09, guest PC 0x0c0626ee */
if(!s->budget--) { s->failed_pc=0x0c0626eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062704; }
goto P_0c0626f0;
P_0c0626f0: /* original 914d, guest PC 0x0c0626f0 */
if(!s->budget--) { s->failed_pc=0x0c0626f0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06278eu,2);
goto P_0c0626f2;
P_0c0626f2: /* original 2148, guest PC 0x0c0626f2 */
if(!s->budget--) { s->failed_pc=0x0c0626f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c0626f4;
P_0c0626f4: /* original 8b05, guest PC 0x0c0626f4 */
if(!s->budget--) { s->failed_pc=0x0c0626f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062702; }
goto P_0c0626f6;
P_0c0626f6: /* original e202, guest PC 0x0c0626f6 */
if(!s->budget--) { s->failed_pc=0x0c0626f6u; return 0; }
r[2]=0x00000002u;
goto P_0c0626f8;
P_0c0626f8: /* original 2248, guest PC 0x0c0626f8 */
if(!s->budget--) { s->failed_pc=0x0c0626f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0626fa;
P_0c0626fa: /* original 8b03, guest PC 0x0c0626fa */
if(!s->budget--) { s->failed_pc=0x0c0626fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062704; }
goto P_0c0626fc;
P_0c0626fc: /* original 9148, guest PC 0x0c0626fc */
if(!s->budget--) { s->failed_pc=0x0c0626fcu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062790u,2);
goto P_0c0626fe;
P_0c0626fe: /* original 2148, guest PC 0x0c0626fe */
if(!s->budget--) { s->failed_pc=0x0c0626feu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c062700;
P_0c062700: /* original 8900, guest PC 0x0c062700 */
if(!s->budget--) { s->failed_pc=0x0c062700u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062704; }
goto P_0c062702;
P_0c062702: /* original ec01, guest PC 0x0c062702 */
if(!s->budget--) { s->failed_pc=0x0c062702u; return 0; }
r[12]=0x00000001u;
goto P_0c062704;
P_0c062704: /* original 9545, guest PC 0x0c062704 */
if(!s->budget--) { s->failed_pc=0x0c062704u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062792u,2);
goto P_0c062706;
P_0c062706: /* original 64d1, guest PC 0x0c062706 */
if(!s->budget--) { s->failed_pc=0x0c062706u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[4]=tmp;
goto P_0c062708;
P_0c062708: /* original 644d, guest PC 0x0c062708 */
if(!s->budget--) { s->failed_pc=0x0c062708u; return 0; }
r[4]=r[4]&65535u;
goto P_0c06270a;
P_0c06270a: /* original 6243, guest PC 0x0c06270a */
if(!s->budget--) { s->failed_pc=0x0c06270au; return 0; }
r[2]=r[4];
goto P_0c06270c;
P_0c06270c: /* original 2258, guest PC 0x0c06270c */
if(!s->budget--) { s->failed_pc=0x0c06270cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c06270e;
P_0c06270e: /* original 8b0e, guest PC 0x0c06270e */
if(!s->budget--) { s->failed_pc=0x0c06270eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06272e; }
goto P_0c062710;
P_0c062710: /* original 9140, guest PC 0x0c062710 */
if(!s->budget--) { s->failed_pc=0x0c062710u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062794u,2);
goto P_0c062712;
P_0c062712: /* original 2148, guest PC 0x0c062712 */
if(!s->budget--) { s->failed_pc=0x0c062712u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c062714;
P_0c062714: /* original 8b0b, guest PC 0x0c062714 */
if(!s->budget--) { s->failed_pc=0x0c062714u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06272e; }
goto P_0c062716;
P_0c062716: /* original e202, guest PC 0x0c062716 */
if(!s->budget--) { s->failed_pc=0x0c062716u; return 0; }
r[2]=0x00000002u;
goto P_0c062718;
P_0c062718: /* original 2248, guest PC 0x0c062718 */
if(!s->budget--) { s->failed_pc=0x0c062718u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c06271a;
P_0c06271a: /* original 8b09, guest PC 0x0c06271a */
if(!s->budget--) { s->failed_pc=0x0c06271au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062730; }
goto P_0c06271c;
P_0c06271c: /* original 913b, guest PC 0x0c06271c */
if(!s->budget--) { s->failed_pc=0x0c06271cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062796u,2);
goto P_0c06271e;
P_0c06271e: /* original 2148, guest PC 0x0c06271e */
if(!s->budget--) { s->failed_pc=0x0c06271eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c062720;
P_0c062720: /* original 8b05, guest PC 0x0c062720 */
if(!s->budget--) { s->failed_pc=0x0c062720u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06272e; }
goto P_0c062722;
P_0c062722: /* original e202, guest PC 0x0c062722 */
if(!s->budget--) { s->failed_pc=0x0c062722u; return 0; }
r[2]=0x00000002u;
goto P_0c062724;
P_0c062724: /* original 2248, guest PC 0x0c062724 */
if(!s->budget--) { s->failed_pc=0x0c062724u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c062726;
P_0c062726: /* original 8b03, guest PC 0x0c062726 */
if(!s->budget--) { s->failed_pc=0x0c062726u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062730; }
goto P_0c062728;
P_0c062728: /* original 9136, guest PC 0x0c062728 */
if(!s->budget--) { s->failed_pc=0x0c062728u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062798u,2);
goto P_0c06272a;
P_0c06272a: /* original 2148, guest PC 0x0c06272a */
if(!s->budget--) { s->failed_pc=0x0c06272au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c06272c;
P_0c06272c: /* original 8900, guest PC 0x0c06272c */
if(!s->budget--) { s->failed_pc=0x0c06272cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062730; }
goto P_0c06272e;
P_0c06272e: /* original ec02, guest PC 0x0c06272e */
if(!s->budget--) { s->failed_pc=0x0c06272eu; return 0; }
r[12]=0x00000002u;
goto P_0c062730;
P_0c062730: /* original 2cc8, guest PC 0x0c062730 */
if(!s->budget--) { s->failed_pc=0x0c062730u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c062732;
P_0c062732: /* original 8b01, guest PC 0x0c062732 */
if(!s->budget--) { s->failed_pc=0x0c062732u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062738; }
goto P_0c062734;
P_0c062734: /* original a08a, guest PC 0x0c062734 */
if(!s->budget--) { s->failed_pc=0x0c062734u; return 0; }
goto P_0c06284c;
P_0c062736: /* original 0009, guest PC 0x0c062736 */
if(!s->budget--) { s->failed_pc=0x0c062736u; return 0; }
goto P_0c062738;
P_0c062738: /* original 53e4, guest PC 0x0c062738 */
if(!s->budget--) { s->failed_pc=0x0c062738u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c06273a;
P_0c06273a: /* original 52e3, guest PC 0x0c06273a */
if(!s->budget--) { s->failed_pc=0x0c06273au; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c06273c;
P_0c06273c: /* original 51d3, guest PC 0x0c06273c */
if(!s->budget--) { s->failed_pc=0x0c06273cu; return 0; }
r[1]=read(ram,r[13]+12,4);
goto P_0c06273e;
P_0c06273e: /* original 323c, guest PC 0x0c06273e */
if(!s->budget--) { s->failed_pc=0x0c06273eu; return 0; }
r[2]+=r[3];
goto P_0c062740;
P_0c062740: /* original 3210, guest PC 0x0c062740 */
if(!s->budget--) { s->failed_pc=0x0c062740u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c062742;
P_0c062742: /* original 8b7a, guest PC 0x0c062742 */
if(!s->budget--) { s->failed_pc=0x0c062742u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06283a; }
goto P_0c062744;
P_0c062744: /* original 51e3, guest PC 0x0c062744 */
if(!s->budget--) { s->failed_pc=0x0c062744u; return 0; }
r[1]=read(ram,r[14]+12,4);
goto P_0c062746;
P_0c062746: /* original d215, guest PC 0x0c062746 */
if(!s->budget--) { s->failed_pc=0x0c062746u; return 0; }
r[2]=read(ram,0x0c06279cu,4);
goto P_0c062748;
P_0c062748: /* original 420b, guest PC 0x0c062748 */
if(!s->budget--) { s->failed_pc=0x0c062748u; return 0; }
target=r[2];
r[16]=0x0c06274cu;
r[0]=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06274cu) { target=s->pc; goto dispatch; }
goto P_0c06274c;
P_0c06274a: /* original e020, guest PC 0x0c06274a */
if(!s->budget--) { s->failed_pc=0x0c06274au; return 0; }
r[0]=0x00000020u;
goto P_0c06274c;
P_0c06274c: /* original 2008, guest PC 0x0c06274c */
if(!s->budget--) { s->failed_pc=0x0c06274cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06274e;
P_0c06274e: /* original 892a, guest PC 0x0c06274e */
if(!s->budget--) { s->failed_pc=0x0c06274eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0627a6; }
goto P_0c062750;
P_0c062750: /* original be9e, guest PC 0x0c062750 */
if(!s->budget--) { s->failed_pc=0x0c062750u; return 0; }
target=0x0c062490u; r[16]=0x0c062754u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c062754u) { target=s->pc; goto dispatch; }
goto P_0c062754;
P_0c062752: /* original 0009, guest PC 0x0c062752 */
if(!s->budget--) { s->failed_pc=0x0c062752u; return 0; }
goto P_0c062754;
P_0c062754: /* original 6a03, guest PC 0x0c062754 */
if(!s->budget--) { s->failed_pc=0x0c062754u; return 0; }
r[10]=r[0];
goto P_0c062756;
P_0c062756: /* original 2aa8, guest PC 0x0c062756 */
if(!s->budget--) { s->failed_pc=0x0c062756u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c062758;
P_0c062758: /* original 8b01, guest PC 0x0c062758 */
if(!s->budget--) { s->failed_pc=0x0c062758u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06275e; }
goto P_0c06275a;
P_0c06275a: /* original a08f, guest PC 0x0c06275a */
if(!s->budget--) { s->failed_pc=0x0c06275au; return 0; }
r[0]=0x00000003u;
goto P_0c06287c;
P_0c06275c: /* original e003, guest PC 0x0c06275c */
if(!s->budget--) { s->failed_pc=0x0c06275cu; return 0; }
r[0]=0x00000003u;
goto P_0c06275e;
P_0c06275e: /* original e4e0, guest PC 0x0c06275e */
if(!s->budget--) { s->failed_pc=0x0c06275eu; return 0; }
r[4]=0xffffffe0u;
goto P_0c062760;
P_0c062760: /* original 52e3, guest PC 0x0c062760 */
if(!s->budget--) { s->failed_pc=0x0c062760u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c062762;
P_0c062762: /* original 1a23, guest PC 0x0c062762 */
if(!s->budget--) { s->failed_pc=0x0c062762u; return 0; }
write(ram,r[10]+12,r[2],4);
goto P_0c062764;
P_0c062764: /* original 53e3, guest PC 0x0c062764 */
if(!s->budget--) { s->failed_pc=0x0c062764u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c062766;
P_0c062766: /* original 731f, guest PC 0x0c062766 */
if(!s->budget--) { s->failed_pc=0x0c062766u; return 0; }
r[3]+=0x0000001fu;
goto P_0c062768;
P_0c062768: /* original 2349, guest PC 0x0c062768 */
if(!s->budget--) { s->failed_pc=0x0c062768u; return 0; }
r[3]&=r[4];
goto P_0c06276a;
P_0c06276a: /* original 1e33, guest PC 0x0c06276a */
if(!s->budget--) { s->failed_pc=0x0c06276au; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c06276c;
P_0c06276c: /* original 53a3, guest PC 0x0c06276c */
if(!s->budget--) { s->failed_pc=0x0c06276cu; return 0; }
r[3]=read(ram,r[10]+12,4);
goto P_0c06276e;
P_0c06276e: /* original 52e3, guest PC 0x0c06276e */
if(!s->budget--) { s->failed_pc=0x0c06276eu; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c062770;
P_0c062770: /* original 3238, guest PC 0x0c062770 */
if(!s->budget--) { s->failed_pc=0x0c062770u; return 0; }
r[2]-=r[3];
goto P_0c062772;
P_0c062772: /* original 6323, guest PC 0x0c062772 */
if(!s->budget--) { s->failed_pc=0x0c062772u; return 0; }
r[3]=r[2];
goto P_0c062774;
P_0c062774: /* original 1a24, guest PC 0x0c062774 */
if(!s->budget--) { s->failed_pc=0x0c062774u; return 0; }
write(ram,r[10]+16,r[2],4);
goto P_0c062776;
P_0c062776: /* original 51e4, guest PC 0x0c062776 */
if(!s->budget--) { s->failed_pc=0x0c062776u; return 0; }
r[1]=read(ram,r[14]+16,4);
goto P_0c062778;
P_0c062778: /* original 3138, guest PC 0x0c062778 */
if(!s->budget--) { s->failed_pc=0x0c062778u; return 0; }
r[1]-=r[3];
goto P_0c06277a;
P_0c06277a: /* original 1e14, guest PC 0x0c06277a */
if(!s->budget--) { s->failed_pc=0x0c06277au; return 0; }
write(ram,r[14]+16,r[1],4);
goto P_0c06277c;
P_0c06277c: /* original 56e1, guest PC 0x0c06277c */
if(!s->budget--) { s->failed_pc=0x0c06277cu; return 0; }
r[6]=read(ram,r[14]+4,4);
goto P_0c06277e;
P_0c06277e: /* original 2668, guest PC 0x0c06277e */
if(!s->budget--) { s->failed_pc=0x0c06277eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c062780;
P_0c062780: /* original 8b0e, guest PC 0x0c062780 */
if(!s->budget--) { s->failed_pc=0x0c062780u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0627a0; }
goto P_0c062782;
P_0c062782: /* original 66a3, guest PC 0x0c062782 */
if(!s->budget--) { s->failed_pc=0x0c062782u; return 0; }
r[6]=r[10];
goto P_0c062784;
P_0c062784: /* original 65b3, guest PC 0x0c062784 */
if(!s->budget--) { s->failed_pc=0x0c062784u; return 0; }
r[5]=r[11];
goto P_0c062786;
P_0c062786: /* original bead, guest PC 0x0c062786 */
if(!s->budget--) { s->failed_pc=0x0c062786u; return 0; }
target=0x0c0624e4u; r[16]=0x0c06278au;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06278au) { target=s->pc; goto dispatch; }
goto P_0c06278a;
P_0c062788: /* original 6493, guest PC 0x0c062788 */
if(!s->budget--) { s->failed_pc=0x0c062788u; return 0; }
r[4]=r[9];
goto P_0c06278a;
P_0c06278a: /* original a00c, guest PC 0x0c06278a */
if(!s->budget--) { s->failed_pc=0x0c06278au; return 0; }
goto P_0c0627a6;
P_0c06278c: /* original 0009, guest PC 0x0c06278c */
if(!s->budget--) { s->failed_pc=0x0c06278cu; return 0; }
return vf3_matrix_family(0x0c06278eu,s,ram);
P_0c0627a0: /* original 65a3, guest PC 0x0c0627a0 */
if(!s->budget--) { s->failed_pc=0x0c0627a0u; return 0; }
r[5]=r[10];
goto P_0c0627a2;
P_0c0627a2: /* original beb1, guest PC 0x0c0627a2 */
if(!s->budget--) { s->failed_pc=0x0c0627a2u; return 0; }
target=0x0c062508u; r[16]=0x0c0627a6u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0627a6u) { target=s->pc; goto dispatch; }
goto P_0c0627a6;
P_0c0627a4: /* original 64b3, guest PC 0x0c0627a4 */
if(!s->budget--) { s->failed_pc=0x0c0627a4u; return 0; }
r[4]=r[11];
goto P_0c0627a6;
P_0c0627a6: /* original 56d4, guest PC 0x0c0627a6 */
if(!s->budget--) { s->failed_pc=0x0c0627a6u; return 0; }
r[6]=read(ram,r[13]+16,4);
goto P_0c0627a8;
P_0c0627a8: /* original 55d3, guest PC 0x0c0627a8 */
if(!s->budget--) { s->failed_pc=0x0c0627a8u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0627aa;
P_0c0627aa: /* original bed3, guest PC 0x0c0627aa */
if(!s->budget--) { s->failed_pc=0x0c0627aau; return 0; }
target=0x0c062554u; r[16]=0x0c0627aeu;
r[4]=read(ram,r[14]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0627aeu) { target=s->pc; goto dispatch; }
goto P_0c0627ae;
P_0c0627ac: /* original 54e3, guest PC 0x0c0627ac */
if(!s->budget--) { s->failed_pc=0x0c0627acu; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c0627ae;
P_0c0627ae: /* original 54e3, guest PC 0x0c0627ae */
if(!s->budget--) { s->failed_pc=0x0c0627aeu; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c0627b0;
P_0c0627b0: /* original 57d3, guest PC 0x0c0627b0 */
if(!s->budget--) { s->failed_pc=0x0c0627b0u; return 0; }
r[7]=read(ram,r[13]+12,4);
goto P_0c0627b2;
P_0c0627b2: /* original 3748, guest PC 0x0c0627b2 */
if(!s->budget--) { s->failed_pc=0x0c0627b2u; return 0; }
r[7]-=r[4];
goto P_0c0627b4;
P_0c0627b4: /* original 1d43, guest PC 0x0c0627b4 */
if(!s->budget--) { s->failed_pc=0x0c0627b4u; return 0; }
write(ram,r[13]+12,r[4],4);
goto P_0c0627b6;
P_0c0627b6: /* original 53d4, guest PC 0x0c0627b6 */
if(!s->budget--) { s->failed_pc=0x0c0627b6u; return 0; }
r[3]=read(ram,r[13]+16,4);
goto P_0c0627b8;
P_0c0627b8: /* original 52e3, guest PC 0x0c0627b8 */
if(!s->budget--) { s->failed_pc=0x0c0627b8u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c0627ba;
P_0c0627ba: /* original 323c, guest PC 0x0c0627ba */
if(!s->budget--) { s->failed_pc=0x0c0627bau; return 0; }
r[2]+=r[3];
goto P_0c0627bc;
P_0c0627bc: /* original 60c3, guest PC 0x0c0627bc */
if(!s->budget--) { s->failed_pc=0x0c0627bcu; return 0; }
r[0]=r[12];
goto P_0c0627be;
P_0c0627be: /* original 0009, guest PC 0x0c0627be */
if(!s->budget--) { s->failed_pc=0x0c0627beu; return 0; }
goto P_0c0627c0;
P_0c0627c0: /* original 8801, guest PC 0x0c0627c0 */
if(!s->budget--) { s->failed_pc=0x0c0627c0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0627c2;
P_0c0627c2: /* original 8f05, guest PC 0x0c0627c2 */
if(!s->budget--) { s->failed_pc=0x0c0627c2u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+12,r[2],4);
if(!cond) { goto P_0c0627d0; }
goto P_0c0627c6;
P_0c0627c4: /* original 1e23, guest PC 0x0c0627c4 */
if(!s->budget--) { s->failed_pc=0x0c0627c4u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c0627c6;
P_0c0627c6: /* original 52d5, guest PC 0x0c0627c6 */
if(!s->budget--) { s->failed_pc=0x0c0627c6u; return 0; }
r[2]=read(ram,r[13]+20,4);
goto P_0c0627c8;
P_0c0627c8: /* original 53d3, guest PC 0x0c0627c8 */
if(!s->budget--) { s->failed_pc=0x0c0627c8u; return 0; }
r[3]=read(ram,r[13]+12,4);
goto P_0c0627ca;
P_0c0627ca: /* original 1237, guest PC 0x0c0627ca */
if(!s->budget--) { s->failed_pc=0x0c0627cau; return 0; }
write(ram,r[2]+28,r[3],4);
goto P_0c0627cc;
P_0c0627cc: /* original a01f, guest PC 0x0c0627cc */
if(!s->budget--) { s->failed_pc=0x0c0627ccu; return 0; }
goto P_0c06280e;
P_0c0627ce: /* original 0009, guest PC 0x0c0627ce */
if(!s->budget--) { s->failed_pc=0x0c0627ceu; return 0; }
goto P_0c0627d0;
P_0c0627d0: /* original 51d5, guest PC 0x0c0627d0 */
if(!s->budget--) { s->failed_pc=0x0c0627d0u; return 0; }
r[1]=read(ram,r[13]+20,4);
goto P_0c0627d2;
P_0c0627d2: /* original e600, guest PC 0x0c0627d2 */
if(!s->budget--) { s->failed_pc=0x0c0627d2u; return 0; }
r[6]=0x00000000u;
goto P_0c0627d4;
P_0c0627d4: /* original 53d3, guest PC 0x0c0627d4 */
if(!s->budget--) { s->failed_pc=0x0c0627d4u; return 0; }
r[3]=read(ram,r[13]+12,4);
goto P_0c0627d6;
P_0c0627d6: /* original 4709, guest PC 0x0c0627d6 */
if(!s->budget--) { s->failed_pc=0x0c0627d6u; return 0; }
r[7]>>=2;
goto P_0c0627d8;
P_0c0627d8: /* original 1132, guest PC 0x0c0627d8 */
if(!s->budget--) { s->failed_pc=0x0c0627d8u; return 0; }
write(ram,r[1]+8,r[3],4);
goto P_0c0627da;
P_0c0627da: /* original 6563, guest PC 0x0c0627da */
if(!s->budget--) { s->failed_pc=0x0c0627dau; return 0; }
r[5]=r[6];
goto P_0c0627dc;
P_0c0627dc: /* original 6463, guest PC 0x0c0627dc */
if(!s->budget--) { s->failed_pc=0x0c0627dcu; return 0; }
r[4]=r[6];
goto P_0c0627de;
P_0c0627de: /* original 6c73, guest PC 0x0c0627de */
if(!s->budget--) { s->failed_pc=0x0c0627deu; return 0; }
r[12]=r[7];
goto P_0c0627e0;
P_0c0627e0: /* original a012, guest PC 0x0c0627e0 */
if(!s->budget--) { s->failed_pc=0x0c0627e0u; return 0; }
r[12]<<=2;
goto P_0c062808;
P_0c0627e2: /* original 4c08, guest PC 0x0c0627e2 */
if(!s->budget--) { s->failed_pc=0x0c0627e2u; return 0; }
r[12]<<=2;
goto P_0c0627e4;
P_0c0627e4: /* original 50d5, guest PC 0x0c0627e4 */
if(!s->budget--) { s->failed_pc=0x0c0627e4u; return 0; }
r[0]=read(ram,r[13]+20,4);
goto P_0c0627e6;
P_0c0627e6: /* original 6303, guest PC 0x0c0627e6 */
if(!s->budget--) { s->failed_pc=0x0c0627e6u; return 0; }
r[3]=r[0];
goto P_0c0627e8;
P_0c0627e8: /* original 730c, guest PC 0x0c0627e8 */
if(!s->budget--) { s->failed_pc=0x0c0627e8u; return 0; }
r[3]+=0x0000000cu;
goto P_0c0627ea;
P_0c0627ea: /* original 335c, guest PC 0x0c0627ea */
if(!s->budget--) { s->failed_pc=0x0c0627eau; return 0; }
r[3]+=r[5];
goto P_0c0627ec;
P_0c0627ec: /* original 6232, guest PC 0x0c0627ec */
if(!s->budget--) { s->failed_pc=0x0c0627ecu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0627ee;
P_0c0627ee: /* original 2228, guest PC 0x0c0627ee */
if(!s->budget--) { s->failed_pc=0x0c0627eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0627f0;
P_0c0627f0: /* original 8d08, guest PC 0x0c0627f0 */
if(!s->budget--) { s->failed_pc=0x0c0627f0u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000001u;
if(cond) { goto P_0c062804; }
goto P_0c0627f4;
P_0c0627f2: /* original 7601, guest PC 0x0c0627f2 */
if(!s->budget--) { s->failed_pc=0x0c0627f2u; return 0; }
r[6]+=0x00000001u;
goto P_0c0627f4;
P_0c0627f4: /* original 50d5, guest PC 0x0c0627f4 */
if(!s->budget--) { s->failed_pc=0x0c0627f4u; return 0; }
r[0]=read(ram,r[13]+20,4);
goto P_0c0627f6;
P_0c0627f6: /* original 6303, guest PC 0x0c0627f6 */
if(!s->budget--) { s->failed_pc=0x0c0627f6u; return 0; }
r[3]=r[0];
goto P_0c0627f8;
P_0c0627f8: /* original 730c, guest PC 0x0c0627f8 */
if(!s->budget--) { s->failed_pc=0x0c0627f8u; return 0; }
r[3]+=0x0000000cu;
goto P_0c0627fa;
P_0c0627fa: /* original 334c, guest PC 0x0c0627fa */
if(!s->budget--) { s->failed_pc=0x0c0627fau; return 0; }
r[3]+=r[4];
goto P_0c0627fc;
P_0c0627fc: /* original 6232, guest PC 0x0c0627fc */
if(!s->budget--) { s->failed_pc=0x0c0627fcu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0627fe;
P_0c0627fe: /* original 5127, guest PC 0x0c0627fe */
if(!s->budget--) { s->failed_pc=0x0c0627feu; return 0; }
r[1]=read(ram,r[2]+28,4);
goto P_0c062800;
P_0c062800: /* original 31c8, guest PC 0x0c062800 */
if(!s->budget--) { s->failed_pc=0x0c062800u; return 0; }
r[1]-=r[12];
goto P_0c062802;
P_0c062802: /* original 1217, guest PC 0x0c062802 */
if(!s->budget--) { s->failed_pc=0x0c062802u; return 0; }
write(ram,r[2]+28,r[1],4);
goto P_0c062804;
P_0c062804: /* original 7404, guest PC 0x0c062804 */
if(!s->budget--) { s->failed_pc=0x0c062804u; return 0; }
r[4]+=0x00000004u;
goto P_0c062806;
P_0c062806: /* original 7504, guest PC 0x0c062806 */
if(!s->budget--) { s->failed_pc=0x0c062806u; return 0; }
r[5]+=0x00000004u;
goto P_0c062808;
P_0c062808: /* original e710, guest PC 0x0c062808 */
if(!s->budget--) { s->failed_pc=0x0c062808u; return 0; }
r[7]=0x00000010u;
goto P_0c06280a;
P_0c06280a: /* original 3673, guest PC 0x0c06280a */
if(!s->budget--) { s->failed_pc=0x0c06280au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[7])!=0);
goto P_0c06280c;
P_0c06280c: /* original 8bea, guest PC 0x0c06280c */
if(!s->budget--) { s->failed_pc=0x0c06280cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0627e4; }
goto P_0c06280e;
P_0c06280e: /* original 5ce2, guest PC 0x0c06280e */
if(!s->budget--) { s->failed_pc=0x0c06280eu; return 0; }
r[12]=read(ram,r[14]+8,4);
goto P_0c062810;
P_0c062810: /* original 2cc8, guest PC 0x0c062810 */
if(!s->budget--) { s->failed_pc=0x0c062810u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c062812;
P_0c062812: /* original 8912, guest PC 0x0c062812 */
if(!s->budget--) { s->failed_pc=0x0c062812u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06283a; }
goto P_0c062814;
P_0c062814: /* original 53e4, guest PC 0x0c062814 */
if(!s->budget--) { s->failed_pc=0x0c062814u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c062816;
P_0c062816: /* original 52e3, guest PC 0x0c062816 */
if(!s->budget--) { s->failed_pc=0x0c062816u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c062818;
P_0c062818: /* original 51c3, guest PC 0x0c062818 */
if(!s->budget--) { s->failed_pc=0x0c062818u; return 0; }
r[1]=read(ram,r[12]+12,4);
goto P_0c06281a;
P_0c06281a: /* original 323c, guest PC 0x0c06281a */
if(!s->budget--) { s->failed_pc=0x0c06281au; return 0; }
r[2]+=r[3];
goto P_0c06281c;
P_0c06281c: /* original 3210, guest PC 0x0c06281c */
if(!s->budget--) { s->failed_pc=0x0c06281cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c06281e;
P_0c06281e: /* original 8b0c, guest PC 0x0c06281e */
if(!s->budget--) { s->failed_pc=0x0c06281eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06283a; }
goto P_0c062820;
P_0c062820: /* original 53c4, guest PC 0x0c062820 */
if(!s->budget--) { s->failed_pc=0x0c062820u; return 0; }
r[3]=read(ram,r[12]+16,4);
goto P_0c062822;
P_0c062822: /* original 66c3, guest PC 0x0c062822 */
if(!s->budget--) { s->failed_pc=0x0c062822u; return 0; }
r[6]=r[12];
goto P_0c062824;
P_0c062824: /* original 52e4, guest PC 0x0c062824 */
if(!s->budget--) { s->failed_pc=0x0c062824u; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c062826;
P_0c062826: /* original 65b3, guest PC 0x0c062826 */
if(!s->budget--) { s->failed_pc=0x0c062826u; return 0; }
r[5]=r[11];
goto P_0c062828;
P_0c062828: /* original 323c, guest PC 0x0c062828 */
if(!s->budget--) { s->failed_pc=0x0c062828u; return 0; }
r[2]+=r[3];
goto P_0c06282a;
P_0c06282a: /* original 1e24, guest PC 0x0c06282a */
if(!s->budget--) { s->failed_pc=0x0c06282au; return 0; }
write(ram,r[14]+16,r[2],4);
goto P_0c06282c;
P_0c06282c: /* original be7a, guest PC 0x0c06282c */
if(!s->budget--) { s->failed_pc=0x0c06282cu; return 0; }
target=0x0c062524u; r[16]=0x0c062830u;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c062830u) { target=s->pc; goto dispatch; }
goto P_0c062830;
P_0c06282e: /* original 6493, guest PC 0x0c06282e */
if(!s->budget--) { s->failed_pc=0x0c06282eu; return 0; }
r[4]=r[9];
goto P_0c062830;
P_0c062830: /* original be43, guest PC 0x0c062830 */
if(!s->budget--) { s->failed_pc=0x0c062830u; return 0; }
target=0x0c0624bau; r[16]=0x0c062834u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c062834u) { target=s->pc; goto dispatch; }
goto P_0c062834;
P_0c062832: /* original 64c3, guest PC 0x0c062832 */
if(!s->budget--) { s->failed_pc=0x0c062832u; return 0; }
r[4]=r[12];
goto P_0c062834;
P_0c062834: /* original a001, guest PC 0x0c062834 */
if(!s->budget--) { s->failed_pc=0x0c062834u; return 0; }
goto P_0c06283a;
P_0c062836: /* original 0009, guest PC 0x0c062836 */
if(!s->budget--) { s->failed_pc=0x0c062836u; return 0; }
goto P_0c062838;
P_0c062838: /* original 5dd2, guest PC 0x0c062838 */
if(!s->budget--) { s->failed_pc=0x0c062838u; return 0; }
r[13]=read(ram,r[13]+8,4);
goto P_0c06283a;
P_0c06283a: /* original 2dd8, guest PC 0x0c06283a */
if(!s->budget--) { s->failed_pc=0x0c06283au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c06283c;
P_0c06283c: /* original 891d, guest PC 0x0c06283c */
if(!s->budget--) { s->failed_pc=0x0c06283cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06287a; }
goto P_0c06283e;
P_0c06283e: /* original 53d3, guest PC 0x0c06283e */
if(!s->budget--) { s->failed_pc=0x0c06283eu; return 0; }
r[3]=read(ram,r[13]+12,4);
goto P_0c062840;
P_0c062840: /* original 52e3, guest PC 0x0c062840 */
if(!s->budget--) { s->failed_pc=0x0c062840u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c062842;
P_0c062842: /* original 3237, guest PC 0x0c062842 */
if(!s->budget--) { s->failed_pc=0x0c062842u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[3])!=0);
goto P_0c062844;
P_0c062844: /* original 89f8, guest PC 0x0c062844 */
if(!s->budget--) { s->failed_pc=0x0c062844u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062838; }
goto P_0c062846;
P_0c062846: /* original a012, guest PC 0x0c062846 */
if(!s->budget--) { s->failed_pc=0x0c062846u; return 0; }
goto P_0c06286e;
P_0c062848: /* original 0009, guest PC 0x0c062848 */
if(!s->budget--) { s->failed_pc=0x0c062848u; return 0; }
goto P_0c06284a;
P_0c06284a: /* original 5ee2, guest PC 0x0c06284a */
if(!s->budget--) { s->failed_pc=0x0c06284au; return 0; }
r[14]=read(ram,r[14]+8,4);
goto P_0c06284c;
P_0c06284c: /* original 2ee8, guest PC 0x0c06284c */
if(!s->budget--) { s->failed_pc=0x0c06284cu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c06284e;
P_0c06284e: /* original 8903, guest PC 0x0c06284e */
if(!s->budget--) { s->failed_pc=0x0c06284eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062858; }
goto P_0c062850;
P_0c062850: /* original 52d3, guest PC 0x0c062850 */
if(!s->budget--) { s->failed_pc=0x0c062850u; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c062852;
P_0c062852: /* original 53e3, guest PC 0x0c062852 */
if(!s->budget--) { s->failed_pc=0x0c062852u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c062854;
P_0c062854: /* original 3323, guest PC 0x0c062854 */
if(!s->budget--) { s->failed_pc=0x0c062854u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c062856;
P_0c062856: /* original 8bf8, guest PC 0x0c062856 */
if(!s->budget--) { s->failed_pc=0x0c062856u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06284a; }
goto P_0c062858;
P_0c062858: /* original 2ee8, guest PC 0x0c062858 */
if(!s->budget--) { s->failed_pc=0x0c062858u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c06285a;
P_0c06285a: /* original 8b02, guest PC 0x0c06285a */
if(!s->budget--) { s->failed_pc=0x0c06285au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062862; }
goto P_0c06285c;
P_0c06285c: /* original a00d, guest PC 0x0c06285c */
if(!s->budget--) { s->failed_pc=0x0c06285cu; return 0; }
goto P_0c06287a;
P_0c06285e: /* original 0009, guest PC 0x0c06285e */
if(!s->budget--) { s->failed_pc=0x0c06285eu; return 0; }
goto P_0c062860;
P_0c062860: /* original 5dd2, guest PC 0x0c062860 */
if(!s->budget--) { s->failed_pc=0x0c062860u; return 0; }
r[13]=read(ram,r[13]+8,4);
goto P_0c062862;
P_0c062862: /* original 2dd8, guest PC 0x0c062862 */
if(!s->budget--) { s->failed_pc=0x0c062862u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c062864;
P_0c062864: /* original 8909, guest PC 0x0c062864 */
if(!s->budget--) { s->failed_pc=0x0c062864u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06287a; }
goto P_0c062866;
P_0c062866: /* original 53d3, guest PC 0x0c062866 */
if(!s->budget--) { s->failed_pc=0x0c062866u; return 0; }
r[3]=read(ram,r[13]+12,4);
goto P_0c062868;
P_0c062868: /* original 52e3, guest PC 0x0c062868 */
if(!s->budget--) { s->failed_pc=0x0c062868u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c06286a;
P_0c06286a: /* original 3237, guest PC 0x0c06286a */
if(!s->budget--) { s->failed_pc=0x0c06286au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[3])!=0);
goto P_0c06286c;
P_0c06286c: /* original 89f8, guest PC 0x0c06286c */
if(!s->budget--) { s->failed_pc=0x0c06286cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062860; }
goto P_0c06286e;
P_0c06286e: /* original 2dd8, guest PC 0x0c06286e */
if(!s->budget--) { s->failed_pc=0x0c06286eu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c062870;
P_0c062870: /* original 8903, guest PC 0x0c062870 */
if(!s->budget--) { s->failed_pc=0x0c062870u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06287a; }
goto P_0c062872;
P_0c062872: /* original 2ee8, guest PC 0x0c062872 */
if(!s->budget--) { s->failed_pc=0x0c062872u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c062874;
P_0c062874: /* original 8901, guest PC 0x0c062874 */
if(!s->budget--) { s->failed_pc=0x0c062874u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06287a; }
goto P_0c062876;
P_0c062876: /* original af2e, guest PC 0x0c062876 */
if(!s->budget--) { s->failed_pc=0x0c062876u; return 0; }
goto P_0c0626d6;
P_0c062878: /* original 0009, guest PC 0x0c062878 */
if(!s->budget--) { s->failed_pc=0x0c062878u; return 0; }
goto P_0c06287a;
P_0c06287a: /* original e000, guest PC 0x0c06287a */
if(!s->budget--) { s->failed_pc=0x0c06287au; return 0; }
r[0]=0x00000000u;
goto P_0c06287c;
P_0c06287c: /* original 4f26, guest PC 0x0c06287c */
if(!s->budget--) { s->failed_pc=0x0c06287cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06287e;
P_0c06287e: /* original 69f6, guest PC 0x0c06287e */
if(!s->budget--) { s->failed_pc=0x0c06287eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c062880;
P_0c062880: /* original 6af6, guest PC 0x0c062880 */
if(!s->budget--) { s->failed_pc=0x0c062880u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c062882;
P_0c062882: /* original 6bf6, guest PC 0x0c062882 */
if(!s->budget--) { s->failed_pc=0x0c062882u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c062884;
P_0c062884: /* original 6cf6, guest PC 0x0c062884 */
if(!s->budget--) { s->failed_pc=0x0c062884u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c062886;
P_0c062886: /* original 6df6, guest PC 0x0c062886 */
if(!s->budget--) { s->failed_pc=0x0c062886u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c062888;
P_0c062888: /* original 000b, guest PC 0x0c062888 */
if(!s->budget--) { s->failed_pc=0x0c062888u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06288a: /* original 6ef6, guest PC 0x0c06288a */
if(!s->budget--) { s->failed_pc=0x0c06288au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06288cu,s,ram);
P_0c062e7e: /* original 4609, guest PC 0x0c062e7e */
if(!s->budget--) { s->failed_pc=0x0c062e7eu; return 0; }
r[6]>>=2;
goto P_0c062e80;
P_0c062e80: /* original 6056, guest PC 0x0c062e80 */
if(!s->budget--) { s->failed_pc=0x0c062e80u; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[0]=tmp;
goto P_0c062e82;
P_0c062e82: /* original 4610, guest PC 0x0c062e82 */
if(!s->budget--) { s->failed_pc=0x0c062e82u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c062e84;
P_0c062e84: /* original 2402, guest PC 0x0c062e84 */
if(!s->budget--) { s->failed_pc=0x0c062e84u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c062e86;
P_0c062e86: /* original 8ffb, guest PC 0x0c062e86 */
if(!s->budget--) { s->failed_pc=0x0c062e86u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c062e80; }
goto P_0c062e8a;
P_0c062e88: /* original 7404, guest PC 0x0c062e88 */
if(!s->budget--) { s->failed_pc=0x0c062e88u; return 0; }
r[4]+=0x00000004u;
goto P_0c062e8a;
P_0c062e8a: /* original 000b, guest PC 0x0c062e8a */
if(!s->budget--) { s->failed_pc=0x0c062e8au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062e8c: /* original 0009, guest PC 0x0c062e8c */
if(!s->budget--) { s->failed_pc=0x0c062e8cu; return 0; }
return vf3_matrix_family(0x0c062e8eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c040154u,0x0c040156u,0x0c040158u,0x0c04015au,0x0c04015cu,0x0c04015eu,0x0c040160u,0x0c040162u,0x0c040164u,0x0c040166u,0x0c040168u,0x0c04016au,0x0c04016cu,0x0c04016eu,0x0c040174u,0x0c040176u,
0x0c040178u,0x0c04017au,0x0c04017cu,0x0c04017eu,0x0c040180u,0x0c040182u,0x0c040184u,0x0c040186u,0x0c040188u,0x0c04018au,0x0c04018cu,0x0c04018eu,0x0c040190u,0x0c040192u,0x0c040194u,0x0c040196u,
0x0c040198u,0x0c04019au,0x0c04019cu,0x0c04019eu,0x0c0401a0u,0x0c0401a2u,0x0c0401a4u,0x0c0401a6u,0x0c0401a8u,0x0c0401aau,0x0c0401acu,0x0c0401aeu,0x0c0401b0u,0x0c0401b2u,0x0c0401b4u,0x0c0401b6u,
0x0c0401b8u,0x0c0401bau,0x0c0401bcu,0x0c0401beu,0x0c0401c0u,0x0c0401c2u,0x0c0401c4u,0x0c0401c6u,0x0c0401c8u,0x0c0401cau,0x0c0401ccu,0x0c0401ceu,0x0c0401d0u,0x0c0401d2u,0x0c0401d4u,0x0c0401d6u,
0x0c0401d8u,0x0c0401dau,0x0c0401dcu,0x0c0401deu,0x0c0401e0u,0x0c0401e2u,0x0c0401e4u,0x0c0401e6u,0x0c0401e8u,0x0c0401eau,0x0c0401ecu,0x0c0401eeu,0x0c0401f0u,0x0c0401f2u,0x0c0401f4u,0x0c0401f6u,
0x0c0401f8u,0x0c0401fau,0x0c0401fcu,0x0c0401feu,0x0c040200u,0x0c040202u,0x0c040204u,0x0c040206u,0x0c040222u,0x0c040224u,0x0c040226u,0x0c040228u,0x0c04022au,0x0c04022cu,0x0c04022eu,0x0c040230u,
0x0c040232u,0x0c040234u,0x0c040236u,0x0c040238u,0x0c04023au,0x0c04023cu,0x0c04023eu,0x0c040240u,0x0c040242u,0x0c040244u,0x0c040246u,0x0c040248u,0x0c04024au,0x0c04024cu,0x0c04024eu,0x0c040250u,
0x0c040252u,0x0c040254u,0x0c040256u,0x0c040258u,0x0c04025au,0x0c04025cu,0x0c04025eu,0x0c040260u,0x0c040262u,0x0c040264u,0x0c040266u,0x0c040268u,0x0c04026au,0x0c04026cu,0x0c04026eu,0x0c040270u,
0x0c040272u,0x0c040274u,0x0c040276u,0x0c040288u,0x0c04028au,0x0c04028cu,0x0c04028eu,0x0c040290u,0x0c040292u,0x0c040294u,0x0c040296u,0x0c040298u,0x0c04029au,0x0c04029cu,0x0c04029eu,0x0c0402a0u,
0x0c0402a2u,0x0c0402a4u,0x0c0402a6u,0x0c0402a8u,0x0c0402aau,0x0c0402acu,0x0c0402aeu,0x0c0402b0u,0x0c0402b2u,0x0c0402b4u,0x0c0402b6u,0x0c0402b8u,0x0c0402bau,0x0c0402bcu,0x0c0402beu,0x0c0402c0u,
0x0c0402c2u,0x0c0402c4u,0x0c0402c6u,0x0c0402c8u,0x0c0402cau,0x0c0402ccu,0x0c0402ceu,0x0c0402d0u,0x0c0402d2u,0x0c0402d4u,0x0c0402d6u,0x0c0402d8u,0x0c0402dau,0x0c0402dcu,0x0c0402deu,0x0c0402e0u,
0x0c0402e2u,0x0c0402e4u,0x0c0402e6u,0x0c0402e8u,0x0c0402eau,0x0c0402ecu,0x0c0402eeu,0x0c0402f0u,0x0c0402f2u,0x0c0402f4u,0x0c0402f6u,0x0c0402f8u,0x0c040308u,0x0c04030au,0x0c04030cu,0x0c04030eu,
0x0c040310u,0x0c040312u,0x0c040314u,0x0c040316u,0x0c040318u,0x0c04031au,0x0c04031cu,0x0c04031eu,0x0c040320u,0x0c040322u,0x0c040324u,0x0c040326u,0x0c040328u,0x0c04032au,0x0c04032cu,0x0c04032eu,
0x0c040330u,0x0c040332u,0x0c040334u,0x0c040336u,0x0c040338u,0x0c04033au,0x0c04033cu,0x0c04033eu,0x0c040340u,0x0c040342u,0x0c040344u,0x0c040346u,0x0c040348u,0x0c04034au,0x0c04034cu,0x0c04034eu,
0x0c040350u,0x0c040352u,0x0c040354u,0x0c040356u,0x0c040358u,0x0c04035au,0x0c04035cu,0x0c04035eu,0x0c040360u,0x0c040362u,0x0c0403c0u,0x0c0403c2u,0x0c0403c4u,0x0c0403c6u,0x0c0403c8u,0x0c0403cau,
0x0c0403ccu,0x0c0403ceu,0x0c0403d0u,0x0c0403d2u,0x0c0403d4u,0x0c0403d6u,0x0c0403d8u,0x0c0403dau,0x0c0403dcu,0x0c0403deu,0x0c0403e0u,0x0c0403e2u,0x0c0403e4u,0x0c0403e6u,0x0c0403e8u,0x0c0403eau,
0x0c0403ecu,0x0c0403eeu,0x0c0403f0u,0x0c0403f2u,0x0c0403f4u,0x0c0403f6u,0x0c0403f8u,0x0c0403fau,0x0c0403fcu,0x0c0403feu,0x0c040400u,0x0c040410u,0x0c040412u,0x0c040414u,0x0c040416u,0x0c040418u,
0x0c04041au,0x0c04041cu,0x0c04041eu,0x0c040420u,0x0c040422u,0x0c040424u,0x0c040426u,0x0c040428u,0x0c04042au,0x0c04042cu,0x0c04042eu,0x0c040430u,0x0c040432u,0x0c040434u,0x0c040436u,0x0c040438u,
0x0c04043au,0x0c04043cu,0x0c04043eu,0x0c040440u,0x0c040442u,0x0c040444u,0x0c040446u,0x0c040448u,0x0c04044au,0x0c04044cu,0x0c04044eu,0x0c040450u,0x0c040452u,0x0c040454u,0x0c040456u,0x0c040458u,
0x0c04045au,0x0c04045cu,0x0c04045eu,0x0c040460u,0x0c040462u,0x0c040464u,0x0c040466u,0x0c040468u,0x0c04046au,0x0c04046cu,0x0c04046eu,0x0c040470u,0x0c040472u,0x0c040474u,0x0c040476u,0x0c040478u,
0x0c04047au,0x0c04047cu,0x0c04047eu,0x0c040480u,0x0c040482u,0x0c040b7eu,0x0c040b80u,0x0c040b82u,0x0c040b84u,0x0c040b86u,0x0c040b88u,0x0c040b8au,0x0c040b8cu,0x0c040b8eu,0x0c040b90u,0x0c040b92u,
0x0c040b94u,0x0c040b96u,0x0c040b98u,0x0c040b9au,0x0c040b9cu,0x0c040b9eu,0x0c040ba0u,0x0c040ba2u,0x0c040ba4u,0x0c040ba6u,0x0c040ba8u,0x0c040baau,0x0c040bacu,0x0c040baeu,0x0c040bb0u,0x0c040bb2u,
0x0c040bb4u,0x0c040bb6u,0x0c040bb8u,0x0c040bbau,0x0c040bbcu,0x0c040bbeu,0x0c040bc0u,0x0c040bc2u,0x0c040bc4u,0x0c040bc6u,0x0c040bc8u,0x0c040bcau,0x0c040bccu,0x0c040bceu,0x0c040bd0u,0x0c040bd2u,
0x0c040bd4u,0x0c040bd6u,0x0c040bd8u,0x0c040bdau,0x0c040bdcu,0x0c040bdeu,0x0c040be0u,0x0c040be2u,0x0c040be4u,0x0c040be6u,0x0c040be8u,0x0c040beau,0x0c040becu,0x0c040beeu,0x0c040bf0u,0x0c040bf2u,
0x0c040bf4u,0x0c040bf6u,0x0c040c10u,0x0c040c12u,0x0c040c14u,0x0c040c16u,0x0c040c18u,0x0c040c1au,0x0c040c1cu,0x0c040c1eu,0x0c040c20u,0x0c040c22u,0x0c040c24u,0x0c040c26u,0x0c040c28u,0x0c040c2au,
0x0c040c2cu,0x0c040c2eu,0x0c040c30u,0x0c040c32u,0x0c040c34u,0x0c040c36u,0x0c040c38u,0x0c040c3au,0x0c040c3cu,0x0c040c3eu,0x0c040c40u,0x0c040c42u,0x0c040c44u,0x0c040c46u,0x0c040c48u,0x0c040c4au,
0x0c040c4cu,0x0c040c4eu,0x0c040c50u,0x0c040c52u,0x0c040c54u,0x0c040c56u,0x0c040c58u,0x0c040c5au,0x0c040c5cu,0x0c040c5eu,0x0c040c60u,0x0c040c62u,0x0c040c64u,0x0c040c66u,0x0c040c68u,0x0c040c6au,
0x0c040c6cu,0x0c040c6eu,0x0c040c70u,0x0c040c72u,0x0c040c74u,0x0c040c76u,0x0c040f1eu,0x0c040f20u,0x0c040f22u,0x0c040f24u,0x0c040f26u,0x0c040f28u,0x0c040f2au,0x0c040f2cu,0x0c040f2eu,0x0c040f30u,
0x0c040f32u,0x0c040f34u,0x0c040f36u,0x0c040f38u,0x0c040f3au,0x0c040f3cu,0x0c040f3eu,0x0c040f40u,0x0c040f42u,0x0c040f44u,0x0c040f46u,0x0c040f48u,0x0c040f4au,0x0c040f4cu,0x0c040f4eu,0x0c040f50u,
0x0c040f52u,0x0c040f54u,0x0c040f56u,0x0c040f58u,0x0c040f5au,0x0c040f5cu,0x0c040f5eu,0x0c040f60u,0x0c040f62u,0x0c040f64u,0x0c040f66u,0x0c060d1eu,0x0c060d20u,0x0c060d22u,0x0c060d24u,0x0c060d26u,
0x0c060d28u,0x0c060d2au,0x0c060d2cu,0x0c060d2eu,0x0c060d30u,0x0c060d32u,0x0c060d34u,0x0c060d36u,0x0c060d38u,0x0c060d3au,0x0c060d3cu,0x0c060d3eu,0x0c060d40u,0x0c060d42u,0x0c060d44u,0x0c060d78u,
0x0c060d7au,0x0c060d7cu,0x0c060d7eu,0x0c060d80u,0x0c060d82u,0x0c060d84u,0x0c060d86u,0x0c060d88u,0x0c060d8au,0x0c060d8cu,0x0c060d8eu,0x0c060d90u,0x0c060d92u,0x0c060d94u,0x0c060d96u,0x0c060d98u,
0x0c060d9au,0x0c060d9cu,0x0c060d9eu,0x0c060da0u,0x0c060da2u,0x0c060da4u,0x0c060da6u,0x0c060da8u,0x0c060daau,0x0c060dacu,0x0c060daeu,0x0c060db0u,0x0c060db2u,0x0c060db4u,0x0c060db6u,0x0c060db8u,
0x0c060dbau,0x0c060dbcu,0x0c060dbeu,0x0c060dc0u,0x0c060dc2u,0x0c060dc4u,0x0c060dc6u,0x0c060dc8u,0x0c060dcau,0x0c060dccu,0x0c060dceu,0x0c060dd0u,0x0c060dd2u,0x0c060dd4u,0x0c060dd6u,0x0c060dd8u,
0x0c060ddau,0x0c060ddcu,0x0c060ddeu,0x0c060de0u,0x0c060de2u,0x0c060de4u,0x0c060de6u,0x0c060de8u,0x0c060deau,0x0c060decu,0x0c060deeu,0x0c060df0u,0x0c060df2u,0x0c060df4u,0x0c060df6u,0x0c060df8u,
0x0c060dfau,0x0c060dfcu,0x0c060dfeu,0x0c060e00u,0x0c060e02u,0x0c060e04u,0x0c060e06u,0x0c060e08u,0x0c060e0au,0x0c060e0cu,0x0c060e0eu,0x0c060e10u,0x0c060e12u,0x0c060e14u,0x0c060e16u,0x0c060e18u,
0x0c060e1au,0x0c060e1cu,0x0c060e1eu,0x0c060e20u,0x0c060e22u,0x0c060e24u,0x0c062490u,0x0c062492u,0x0c062494u,0x0c062496u,0x0c062498u,0x0c06249au,0x0c06249cu,0x0c06249eu,0x0c0624a0u,0x0c0624a2u,
0x0c0624a4u,0x0c0624a6u,0x0c0624a8u,0x0c0624aau,0x0c0624acu,0x0c0624aeu,0x0c0624b0u,0x0c0624b2u,0x0c0624b4u,0x0c0624b6u,0x0c0624b8u,0x0c0624bau,0x0c0624bcu,0x0c0624beu,0x0c0624c0u,0x0c0624c2u,
0x0c0624c4u,0x0c0624c6u,0x0c0624c8u,0x0c0624cau,0x0c0624ccu,0x0c0624ceu,0x0c0624d0u,0x0c0624d2u,0x0c0624d4u,0x0c0624d6u,0x0c0624d8u,0x0c0624dau,0x0c0624dcu,0x0c0624deu,0x0c0624e0u,0x0c0624e2u,
0x0c0624e4u,0x0c0624e6u,0x0c0624e8u,0x0c0624eau,0x0c0624ecu,0x0c0624eeu,0x0c0624f0u,0x0c0624f2u,0x0c0624f4u,0x0c0624f6u,0x0c0624f8u,0x0c0624fau,0x0c0624fcu,0x0c0624feu,0x0c062500u,0x0c062502u,
0x0c062504u,0x0c062506u,0x0c062508u,0x0c06250au,0x0c06250cu,0x0c06250eu,0x0c062510u,0x0c062512u,0x0c062514u,0x0c062516u,0x0c062518u,0x0c06251au,0x0c06251cu,0x0c06251eu,0x0c062520u,0x0c062522u,
0x0c062524u,0x0c062526u,0x0c062528u,0x0c06252au,0x0c06252cu,0x0c06252eu,0x0c062530u,0x0c062532u,0x0c062534u,0x0c062536u,0x0c062538u,0x0c06253au,0x0c06253cu,0x0c06253eu,0x0c062540u,0x0c062542u,
0x0c062544u,0x0c062546u,0x0c062548u,0x0c06254au,0x0c06254cu,0x0c06254eu,0x0c062550u,0x0c062552u,0x0c062554u,0x0c062556u,0x0c062558u,0x0c06255au,0x0c06255cu,0x0c06255eu,0x0c062560u,0x0c062562u,
0x0c062564u,0x0c062566u,0x0c062568u,0x0c06256au,0x0c06256cu,0x0c06256eu,0x0c062570u,0x0c062572u,0x0c062574u,0x0c062576u,0x0c062578u,0x0c06257au,0x0c06257cu,0x0c06257eu,0x0c062580u,0x0c062582u,
0x0c062584u,0x0c062586u,0x0c062588u,0x0c0625a0u,0x0c0625a2u,0x0c0625a4u,0x0c0625a6u,0x0c0625a8u,0x0c0625aau,0x0c0625acu,0x0c0625aeu,0x0c0625b0u,0x0c0625b2u,0x0c0625b4u,0x0c0625b6u,0x0c0625b8u,
0x0c0625bau,0x0c0625bcu,0x0c0625beu,0x0c0625c0u,0x0c0625c2u,0x0c0625c4u,0x0c0625c6u,0x0c0625c8u,0x0c0625cau,0x0c0625ccu,0x0c0625ceu,0x0c0625d0u,0x0c0625d2u,0x0c0625d4u,0x0c0625d6u,0x0c0625d8u,
0x0c0625dau,0x0c0625dcu,0x0c0625deu,0x0c0625e0u,0x0c0625e2u,0x0c0625e4u,0x0c0625e6u,0x0c0625e8u,0x0c0625eau,0x0c0625ecu,0x0c0625eeu,0x0c0625f0u,0x0c0625f2u,0x0c0625f4u,0x0c0625f6u,0x0c0625f8u,
0x0c0625fau,0x0c0625fcu,0x0c0625feu,0x0c062600u,0x0c062602u,0x0c0626c0u,0x0c0626c2u,0x0c0626c4u,0x0c0626c6u,0x0c0626c8u,0x0c0626cau,0x0c0626ccu,0x0c0626ceu,0x0c0626d0u,0x0c0626d2u,0x0c0626d4u,
0x0c0626d6u,0x0c0626d8u,0x0c0626dau,0x0c0626dcu,0x0c0626deu,0x0c0626e0u,0x0c0626e2u,0x0c0626e4u,0x0c0626e6u,0x0c0626e8u,0x0c0626eau,0x0c0626ecu,0x0c0626eeu,0x0c0626f0u,0x0c0626f2u,0x0c0626f4u,
0x0c0626f6u,0x0c0626f8u,0x0c0626fau,0x0c0626fcu,0x0c0626feu,0x0c062700u,0x0c062702u,0x0c062704u,0x0c062706u,0x0c062708u,0x0c06270au,0x0c06270cu,0x0c06270eu,0x0c062710u,0x0c062712u,0x0c062714u,
0x0c062716u,0x0c062718u,0x0c06271au,0x0c06271cu,0x0c06271eu,0x0c062720u,0x0c062722u,0x0c062724u,0x0c062726u,0x0c062728u,0x0c06272au,0x0c06272cu,0x0c06272eu,0x0c062730u,0x0c062732u,0x0c062734u,
0x0c062736u,0x0c062738u,0x0c06273au,0x0c06273cu,0x0c06273eu,0x0c062740u,0x0c062742u,0x0c062744u,0x0c062746u,0x0c062748u,0x0c06274au,0x0c06274cu,0x0c06274eu,0x0c062750u,0x0c062752u,0x0c062754u,
0x0c062756u,0x0c062758u,0x0c06275au,0x0c06275cu,0x0c06275eu,0x0c062760u,0x0c062762u,0x0c062764u,0x0c062766u,0x0c062768u,0x0c06276au,0x0c06276cu,0x0c06276eu,0x0c062770u,0x0c062772u,0x0c062774u,
0x0c062776u,0x0c062778u,0x0c06277au,0x0c06277cu,0x0c06277eu,0x0c062780u,0x0c062782u,0x0c062784u,0x0c062786u,0x0c062788u,0x0c06278au,0x0c06278cu,0x0c0627a0u,0x0c0627a2u,0x0c0627a4u,0x0c0627a6u,
0x0c0627a8u,0x0c0627aau,0x0c0627acu,0x0c0627aeu,0x0c0627b0u,0x0c0627b2u,0x0c0627b4u,0x0c0627b6u,0x0c0627b8u,0x0c0627bau,0x0c0627bcu,0x0c0627beu,0x0c0627c0u,0x0c0627c2u,0x0c0627c4u,0x0c0627c6u,
0x0c0627c8u,0x0c0627cau,0x0c0627ccu,0x0c0627ceu,0x0c0627d0u,0x0c0627d2u,0x0c0627d4u,0x0c0627d6u,0x0c0627d8u,0x0c0627dau,0x0c0627dcu,0x0c0627deu,0x0c0627e0u,0x0c0627e2u,0x0c0627e4u,0x0c0627e6u,
0x0c0627e8u,0x0c0627eau,0x0c0627ecu,0x0c0627eeu,0x0c0627f0u,0x0c0627f2u,0x0c0627f4u,0x0c0627f6u,0x0c0627f8u,0x0c0627fau,0x0c0627fcu,0x0c0627feu,0x0c062800u,0x0c062802u,0x0c062804u,0x0c062806u,
0x0c062808u,0x0c06280au,0x0c06280cu,0x0c06280eu,0x0c062810u,0x0c062812u,0x0c062814u,0x0c062816u,0x0c062818u,0x0c06281au,0x0c06281cu,0x0c06281eu,0x0c062820u,0x0c062822u,0x0c062824u,0x0c062826u,
0x0c062828u,0x0c06282au,0x0c06282cu,0x0c06282eu,0x0c062830u,0x0c062832u,0x0c062834u,0x0c062836u,0x0c062838u,0x0c06283au,0x0c06283cu,0x0c06283eu,0x0c062840u,0x0c062842u,0x0c062844u,0x0c062846u,
0x0c062848u,0x0c06284au,0x0c06284cu,0x0c06284eu,0x0c062850u,0x0c062852u,0x0c062854u,0x0c062856u,0x0c062858u,0x0c06285au,0x0c06285cu,0x0c06285eu,0x0c062860u,0x0c062862u,0x0c062864u,0x0c062866u,
0x0c062868u,0x0c06286au,0x0c06286cu,0x0c06286eu,0x0c062870u,0x0c062872u,0x0c062874u,0x0c062876u,0x0c062878u,0x0c06287au,0x0c06287cu,0x0c06287eu,0x0c062880u,0x0c062882u,0x0c062884u,0x0c062886u,
0x0c062888u,0x0c06288au,0x0c062e7eu,0x0c062e80u,0x0c062e82u,0x0c062e84u,0x0c062e86u,0x0c062e88u,0x0c062e8au,0x0c062e8cu,
};
int vf3_seventh_c_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
