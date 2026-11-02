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
int vf3_away_batch182_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09b298u: goto P_0c09b298;
case 0x0c09b29au: goto P_0c09b29a;
case 0x0c09b29cu: goto P_0c09b29c;
case 0x0c09b29eu: goto P_0c09b29e;
case 0x0c09b2a0u: goto P_0c09b2a0;
case 0x0c09b2a2u: goto P_0c09b2a2;
case 0x0c09b2a4u: goto P_0c09b2a4;
case 0x0c09b2a6u: goto P_0c09b2a6;
case 0x0c09b2a8u: goto P_0c09b2a8;
case 0x0c09b2aau: goto P_0c09b2aa;
case 0x0c09b2acu: goto P_0c09b2ac;
case 0x0c09b2aeu: goto P_0c09b2ae;
case 0x0c09b2b0u: goto P_0c09b2b0;
case 0x0c09b2b2u: goto P_0c09b2b2;
case 0x0c09b2b4u: goto P_0c09b2b4;
case 0x0c09b2b6u: goto P_0c09b2b6;
case 0x0c09b2b8u: goto P_0c09b2b8;
case 0x0c09b2bau: goto P_0c09b2ba;
case 0x0c09b2bcu: goto P_0c09b2bc;
case 0x0c09b2beu: goto P_0c09b2be;
case 0x0c09b2c0u: goto P_0c09b2c0;
case 0x0c09b2c2u: goto P_0c09b2c2;
case 0x0c09b2c4u: goto P_0c09b2c4;
case 0x0c09b2c6u: goto P_0c09b2c6;
case 0x0c09b2c8u: goto P_0c09b2c8;
case 0x0c09b2cau: goto P_0c09b2ca;
case 0x0c09b2ccu: goto P_0c09b2cc;
case 0x0c09b2ceu: goto P_0c09b2ce;
case 0x0c09b2d0u: goto P_0c09b2d0;
case 0x0c09b2d2u: goto P_0c09b2d2;
case 0x0c09b2d4u: goto P_0c09b2d4;
case 0x0c09b2d6u: goto P_0c09b2d6;
case 0x0c09b2d8u: goto P_0c09b2d8;
case 0x0c09b2dau: goto P_0c09b2da;
case 0x0c09b2dcu: goto P_0c09b2dc;
case 0x0c09b2deu: goto P_0c09b2de;
case 0x0c09b2e0u: goto P_0c09b2e0;
case 0x0c09b2e2u: goto P_0c09b2e2;
case 0x0c09b2e4u: goto P_0c09b2e4;
case 0x0c09b2e6u: goto P_0c09b2e6;
case 0x0c09b2e8u: goto P_0c09b2e8;
case 0x0c09b2eau: goto P_0c09b2ea;
case 0x0c09b2ecu: goto P_0c09b2ec;
case 0x0c09b2eeu: goto P_0c09b2ee;
case 0x0c09b2f0u: goto P_0c09b2f0;
case 0x0c09b2f2u: goto P_0c09b2f2;
case 0x0c09b2f4u: goto P_0c09b2f4;
case 0x0c09b2f6u: goto P_0c09b2f6;
case 0x0c09b2f8u: goto P_0c09b2f8;
case 0x0c09b2fau: goto P_0c09b2fa;
case 0x0c09b2fcu: goto P_0c09b2fc;
case 0x0c09b2feu: goto P_0c09b2fe;
case 0x0c09b300u: goto P_0c09b300;
case 0x0c09b302u: goto P_0c09b302;
case 0x0c09b304u: goto P_0c09b304;
case 0x0c09b306u: goto P_0c09b306;
case 0x0c09b308u: goto P_0c09b308;
case 0x0c09b30au: goto P_0c09b30a;
case 0x0c09b30cu: goto P_0c09b30c;
case 0x0c09b30eu: goto P_0c09b30e;
case 0x0c09b310u: goto P_0c09b310;
case 0x0c09b312u: goto P_0c09b312;
case 0x0c09b314u: goto P_0c09b314;
case 0x0c09b316u: goto P_0c09b316;
case 0x0c09b318u: goto P_0c09b318;
case 0x0c09b31au: goto P_0c09b31a;
case 0x0c09b31cu: goto P_0c09b31c;
case 0x0c09b31eu: goto P_0c09b31e;
case 0x0c09b320u: goto P_0c09b320;
case 0x0c09b322u: goto P_0c09b322;
case 0x0c09b324u: goto P_0c09b324;
case 0x0c09b326u: goto P_0c09b326;
case 0x0c09b328u: goto P_0c09b328;
case 0x0c09b32au: goto P_0c09b32a;
case 0x0c09b32cu: goto P_0c09b32c;
case 0x0c09b32eu: goto P_0c09b32e;
case 0x0c09b330u: goto P_0c09b330;
case 0x0c09b332u: goto P_0c09b332;
case 0x0c09b334u: goto P_0c09b334;
case 0x0c09b336u: goto P_0c09b336;
case 0x0c09b338u: goto P_0c09b338;
case 0x0c09b33au: goto P_0c09b33a;
case 0x0c09b33cu: goto P_0c09b33c;
case 0x0c09b33eu: goto P_0c09b33e;
case 0x0c09b340u: goto P_0c09b340;
case 0x0c09b36cu: goto P_0c09b36c;
case 0x0c09b36eu: goto P_0c09b36e;
case 0x0c09b370u: goto P_0c09b370;
case 0x0c09b372u: goto P_0c09b372;
case 0x0c09b374u: goto P_0c09b374;
case 0x0c09b376u: goto P_0c09b376;
case 0x0c09b378u: goto P_0c09b378;
case 0x0c09b37au: goto P_0c09b37a;
case 0x0c09b37cu: goto P_0c09b37c;
case 0x0c09b37eu: goto P_0c09b37e;
case 0x0c09b380u: goto P_0c09b380;
case 0x0c09b382u: goto P_0c09b382;
case 0x0c09b384u: goto P_0c09b384;
case 0x0c09b386u: goto P_0c09b386;
case 0x0c09b388u: goto P_0c09b388;
case 0x0c09b38au: goto P_0c09b38a;
case 0x0c09b38cu: goto P_0c09b38c;
case 0x0c09b38eu: goto P_0c09b38e;
case 0x0c09b390u: goto P_0c09b390;
case 0x0c09b392u: goto P_0c09b392;
case 0x0c09b394u: goto P_0c09b394;
case 0x0c09b396u: goto P_0c09b396;
case 0x0c09b398u: goto P_0c09b398;
case 0x0c09b39au: goto P_0c09b39a;
case 0x0c09b39cu: goto P_0c09b39c;
case 0x0c09b39eu: goto P_0c09b39e;
case 0x0c09b3a0u: goto P_0c09b3a0;
case 0x0c09b3a2u: goto P_0c09b3a2;
case 0x0c09b3a4u: goto P_0c09b3a4;
case 0x0c09b3a6u: goto P_0c09b3a6;
case 0x0c09b3a8u: goto P_0c09b3a8;
case 0x0c09b3aau: goto P_0c09b3aa;
case 0x0c09b3acu: goto P_0c09b3ac;
case 0x0c09b3aeu: goto P_0c09b3ae;
case 0x0c09b3b0u: goto P_0c09b3b0;
case 0x0c09b3b2u: goto P_0c09b3b2;
case 0x0c09b3b4u: goto P_0c09b3b4;
case 0x0c09b3b6u: goto P_0c09b3b6;
case 0x0c09b3b8u: goto P_0c09b3b8;
case 0x0c09b3bau: goto P_0c09b3ba;
case 0x0c09b3bcu: goto P_0c09b3bc;
case 0x0c09b3beu: goto P_0c09b3be;
case 0x0c09b3c0u: goto P_0c09b3c0;
case 0x0c09b3c2u: goto P_0c09b3c2;
case 0x0c09b3c4u: goto P_0c09b3c4;
case 0x0c09b3c6u: goto P_0c09b3c6;
case 0x0c09b3c8u: goto P_0c09b3c8;
case 0x0c09b3cau: goto P_0c09b3ca;
case 0x0c09b3ccu: goto P_0c09b3cc;
case 0x0c09b3ceu: goto P_0c09b3ce;
case 0x0c09b3d0u: goto P_0c09b3d0;
case 0x0c09b3d2u: goto P_0c09b3d2;
case 0x0c09b3d4u: goto P_0c09b3d4;
case 0x0c09b3d6u: goto P_0c09b3d6;
case 0x0c09b3d8u: goto P_0c09b3d8;
case 0x0c09b3dau: goto P_0c09b3da;
case 0x0c09b3dcu: goto P_0c09b3dc;
case 0x0c09b3deu: goto P_0c09b3de;
case 0x0c09b3e0u: goto P_0c09b3e0;
case 0x0c09b3e2u: goto P_0c09b3e2;
case 0x0c09b3e4u: goto P_0c09b3e4;
case 0x0c09b3e6u: goto P_0c09b3e6;
case 0x0c09b3e8u: goto P_0c09b3e8;
case 0x0c09b3eau: goto P_0c09b3ea;
case 0x0c09b3ecu: goto P_0c09b3ec;
case 0x0c09b3eeu: goto P_0c09b3ee;
case 0x0c09b3f0u: goto P_0c09b3f0;
case 0x0c09b3f2u: goto P_0c09b3f2;
case 0x0c09b3f4u: goto P_0c09b3f4;
case 0x0c09b3f6u: goto P_0c09b3f6;
case 0x0c09b3f8u: goto P_0c09b3f8;
case 0x0c09b3fau: goto P_0c09b3fa;
case 0x0c09b3fcu: goto P_0c09b3fc;
case 0x0c09b3feu: goto P_0c09b3fe;
case 0x0c09b400u: goto P_0c09b400;
case 0x0c09b402u: goto P_0c09b402;
case 0x0c09b404u: goto P_0c09b404;
case 0x0c09b406u: goto P_0c09b406;
case 0x0c09b408u: goto P_0c09b408;
case 0x0c09b40au: goto P_0c09b40a;
case 0x0c09b40cu: goto P_0c09b40c;
case 0x0c09b40eu: goto P_0c09b40e;
case 0x0c09b410u: goto P_0c09b410;
case 0x0c09b412u: goto P_0c09b412;
case 0x0c09b414u: goto P_0c09b414;
case 0x0c09b416u: goto P_0c09b416;
case 0x0c09b418u: goto P_0c09b418;
case 0x0c09b41au: goto P_0c09b41a;
case 0x0c09b41cu: goto P_0c09b41c;
case 0x0c09b41eu: goto P_0c09b41e;
case 0x0c09b420u: goto P_0c09b420;
case 0x0c09b422u: goto P_0c09b422;
case 0x0c09b424u: goto P_0c09b424;
case 0x0c09b426u: goto P_0c09b426;
case 0x0c09b428u: goto P_0c09b428;
case 0x0c09b42au: goto P_0c09b42a;
case 0x0c09b42cu: goto P_0c09b42c;
case 0x0c09b42eu: goto P_0c09b42e;
case 0x0c09b430u: goto P_0c09b430;
case 0x0c09b432u: goto P_0c09b432;
case 0x0c09b434u: goto P_0c09b434;
case 0x0c09b436u: goto P_0c09b436;
case 0x0c09b438u: goto P_0c09b438;
case 0x0c09b43au: goto P_0c09b43a;
case 0x0c09b43cu: goto P_0c09b43c;
case 0x0c09b43eu: goto P_0c09b43e;
case 0x0c09b440u: goto P_0c09b440;
case 0x0c09b442u: goto P_0c09b442;
case 0x0c09b45cu: goto P_0c09b45c;
case 0x0c09b45eu: goto P_0c09b45e;
case 0x0c09b460u: goto P_0c09b460;
case 0x0c09b462u: goto P_0c09b462;
case 0x0c09b464u: goto P_0c09b464;
case 0x0c09b466u: goto P_0c09b466;
case 0x0c09b468u: goto P_0c09b468;
case 0x0c09b46au: goto P_0c09b46a;
case 0x0c09b46cu: goto P_0c09b46c;
case 0x0c09b46eu: goto P_0c09b46e;
case 0x0c09b470u: goto P_0c09b470;
case 0x0c09b472u: goto P_0c09b472;
case 0x0c09b474u: goto P_0c09b474;
case 0x0c09b476u: goto P_0c09b476;
case 0x0c09b478u: goto P_0c09b478;
case 0x0c09b47au: goto P_0c09b47a;
case 0x0c09b47cu: goto P_0c09b47c;
case 0x0c09b47eu: goto P_0c09b47e;
case 0x0c09b480u: goto P_0c09b480;
case 0x0c09b482u: goto P_0c09b482;
case 0x0c09b484u: goto P_0c09b484;
case 0x0c09b486u: goto P_0c09b486;
case 0x0c09b488u: goto P_0c09b488;
case 0x0c09b48au: goto P_0c09b48a;
case 0x0c09b48cu: goto P_0c09b48c;
case 0x0c09b48eu: goto P_0c09b48e;
case 0x0c09b490u: goto P_0c09b490;
case 0x0c09b492u: goto P_0c09b492;
case 0x0c09b494u: goto P_0c09b494;
case 0x0c09b496u: goto P_0c09b496;
case 0x0c09b498u: goto P_0c09b498;
case 0x0c09b49au: goto P_0c09b49a;
case 0x0c09b49cu: goto P_0c09b49c;
case 0x0c09b49eu: goto P_0c09b49e;
case 0x0c09b4a0u: goto P_0c09b4a0;
case 0x0c09b4a2u: goto P_0c09b4a2;
case 0x0c09b4a4u: goto P_0c09b4a4;
case 0x0c09b4a6u: goto P_0c09b4a6;
case 0x0c09b4a8u: goto P_0c09b4a8;
case 0x0c09b4aau: goto P_0c09b4aa;
case 0x0c09b4acu: goto P_0c09b4ac;
case 0x0c09b4aeu: goto P_0c09b4ae;
case 0x0c09b4b0u: goto P_0c09b4b0;
case 0x0c09b4b2u: goto P_0c09b4b2;
case 0x0c09b4b4u: goto P_0c09b4b4;
case 0x0c09b4b6u: goto P_0c09b4b6;
case 0x0c09b4b8u: goto P_0c09b4b8;
case 0x0c09b4bau: goto P_0c09b4ba;
case 0x0c09b4bcu: goto P_0c09b4bc;
case 0x0c09b4beu: goto P_0c09b4be;
case 0x0c09b4c0u: goto P_0c09b4c0;
case 0x0c09b4c2u: goto P_0c09b4c2;
case 0x0c09b4c4u: goto P_0c09b4c4;
case 0x0c09b4c6u: goto P_0c09b4c6;
case 0x0c09b4c8u: goto P_0c09b4c8;
case 0x0c09b4cau: goto P_0c09b4ca;
case 0x0c09b4ccu: goto P_0c09b4cc;
case 0x0c09b4ceu: goto P_0c09b4ce;
case 0x0c09b4d0u: goto P_0c09b4d0;
case 0x0c09b4d2u: goto P_0c09b4d2;
case 0x0c09b4d4u: goto P_0c09b4d4;
case 0x0c09b4d6u: goto P_0c09b4d6;
case 0x0c09b4d8u: goto P_0c09b4d8;
case 0x0c09b4dau: goto P_0c09b4da;
case 0x0c09b4dcu: goto P_0c09b4dc;
case 0x0c09b4deu: goto P_0c09b4de;
case 0x0c09b4e0u: goto P_0c09b4e0;
case 0x0c09b4e2u: goto P_0c09b4e2;
case 0x0c09b4e4u: goto P_0c09b4e4;
case 0x0c09b4e6u: goto P_0c09b4e6;
case 0x0c09b4e8u: goto P_0c09b4e8;
case 0x0c09b4eau: goto P_0c09b4ea;
case 0x0c09b4ecu: goto P_0c09b4ec;
case 0x0c09b4eeu: goto P_0c09b4ee;
case 0x0c09b4f0u: goto P_0c09b4f0;
case 0x0c09b4f2u: goto P_0c09b4f2;
case 0x0c09b4f4u: goto P_0c09b4f4;
case 0x0c09b4f6u: goto P_0c09b4f6;
case 0x0c09b4f8u: goto P_0c09b4f8;
case 0x0c09b4fau: goto P_0c09b4fa;
case 0x0c09b4fcu: goto P_0c09b4fc;
case 0x0c09b4feu: goto P_0c09b4fe;
case 0x0c09b500u: goto P_0c09b500;
case 0x0c09b502u: goto P_0c09b502;
case 0x0c09b504u: goto P_0c09b504;
case 0x0c09b506u: goto P_0c09b506;
case 0x0c09b508u: goto P_0c09b508;
case 0x0c09b50au: goto P_0c09b50a;
case 0x0c09b50cu: goto P_0c09b50c;
case 0x0c09b50eu: goto P_0c09b50e;
case 0x0c09b510u: goto P_0c09b510;
case 0x0c09b512u: goto P_0c09b512;
case 0x0c09b514u: goto P_0c09b514;
case 0x0c09b516u: goto P_0c09b516;
case 0x0c09b518u: goto P_0c09b518;
case 0x0c09b51au: goto P_0c09b51a;
case 0x0c09b51cu: goto P_0c09b51c;
case 0x0c09b51eu: goto P_0c09b51e;
case 0x0c09b520u: goto P_0c09b520;
case 0x0c09b522u: goto P_0c09b522;
case 0x0c09b524u: goto P_0c09b524;
case 0x0c09b526u: goto P_0c09b526;
case 0x0c09b528u: goto P_0c09b528;
case 0x0c09b52au: goto P_0c09b52a;
case 0x0c09b52cu: goto P_0c09b52c;
case 0x0c09b52eu: goto P_0c09b52e;
case 0x0c09b530u: goto P_0c09b530;
case 0x0c09b532u: goto P_0c09b532;
case 0x0c09b534u: goto P_0c09b534;
case 0x0c09b536u: goto P_0c09b536;
case 0x0c09b538u: goto P_0c09b538;
case 0x0c09b54cu: goto P_0c09b54c;
case 0x0c09b54eu: goto P_0c09b54e;
case 0x0c09b550u: goto P_0c09b550;
case 0x0c09b552u: goto P_0c09b552;
case 0x0c09b554u: goto P_0c09b554;
case 0x0c09b556u: goto P_0c09b556;
case 0x0c09b558u: goto P_0c09b558;
case 0x0c09b55au: goto P_0c09b55a;
case 0x0c09b55cu: goto P_0c09b55c;
case 0x0c09b55eu: goto P_0c09b55e;
case 0x0c09b560u: goto P_0c09b560;
case 0x0c09b562u: goto P_0c09b562;
case 0x0c09b564u: goto P_0c09b564;
case 0x0c09b566u: goto P_0c09b566;
case 0x0c09b568u: goto P_0c09b568;
case 0x0c09b56au: goto P_0c09b56a;
case 0x0c09b56cu: goto P_0c09b56c;
case 0x0c09b56eu: goto P_0c09b56e;
case 0x0c09b570u: goto P_0c09b570;
case 0x0c09b572u: goto P_0c09b572;
case 0x0c09b574u: goto P_0c09b574;
case 0x0c09b576u: goto P_0c09b576;
case 0x0c09b578u: goto P_0c09b578;
case 0x0c09b57au: goto P_0c09b57a;
case 0x0c09b57cu: goto P_0c09b57c;
case 0x0c09b57eu: goto P_0c09b57e;
case 0x0c09b580u: goto P_0c09b580;
case 0x0c09b582u: goto P_0c09b582;
case 0x0c09b584u: goto P_0c09b584;
case 0x0c09b586u: goto P_0c09b586;
case 0x0c09b588u: goto P_0c09b588;
case 0x0c09b58au: goto P_0c09b58a;
case 0x0c09b58cu: goto P_0c09b58c;
case 0x0c09b58eu: goto P_0c09b58e;
case 0x0c09b590u: goto P_0c09b590;
case 0x0c09b592u: goto P_0c09b592;
case 0x0c09b594u: goto P_0c09b594;
case 0x0c09b596u: goto P_0c09b596;
case 0x0c09b598u: goto P_0c09b598;
case 0x0c09b59au: goto P_0c09b59a;
case 0x0c09b59cu: goto P_0c09b59c;
case 0x0c09b59eu: goto P_0c09b59e;
case 0x0c09b5a0u: goto P_0c09b5a0;
case 0x0c09b5a2u: goto P_0c09b5a2;
case 0x0c09b5a4u: goto P_0c09b5a4;
case 0x0c09b5a6u: goto P_0c09b5a6;
case 0x0c09b5a8u: goto P_0c09b5a8;
case 0x0c09b5aau: goto P_0c09b5aa;
case 0x0c09b5acu: goto P_0c09b5ac;
case 0x0c09b5aeu: goto P_0c09b5ae;
case 0x0c09b5b0u: goto P_0c09b5b0;
case 0x0c09b5b2u: goto P_0c09b5b2;
case 0x0c09b5b4u: goto P_0c09b5b4;
case 0x0c09b5b6u: goto P_0c09b5b6;
case 0x0c09b5b8u: goto P_0c09b5b8;
case 0x0c09b5bau: goto P_0c09b5ba;
case 0x0c09b5bcu: goto P_0c09b5bc;
case 0x0c09b5beu: goto P_0c09b5be;
case 0x0c09b5c0u: goto P_0c09b5c0;
case 0x0c09b5c2u: goto P_0c09b5c2;
case 0x0c09b5c4u: goto P_0c09b5c4;
case 0x0c09b5c6u: goto P_0c09b5c6;
case 0x0c09b5c8u: goto P_0c09b5c8;
case 0x0c09b5cau: goto P_0c09b5ca;
case 0x0c09b5ccu: goto P_0c09b5cc;
case 0x0c09b5ceu: goto P_0c09b5ce;
case 0x0c09b5d0u: goto P_0c09b5d0;
case 0x0c09b5d2u: goto P_0c09b5d2;
case 0x0c09b5d4u: goto P_0c09b5d4;
case 0x0c09b5d6u: goto P_0c09b5d6;
case 0x0c09b5d8u: goto P_0c09b5d8;
case 0x0c09b5dau: goto P_0c09b5da;
case 0x0c09b5dcu: goto P_0c09b5dc;
case 0x0c09b5deu: goto P_0c09b5de;
case 0x0c09b5e0u: goto P_0c09b5e0;
case 0x0c09b5e2u: goto P_0c09b5e2;
case 0x0c09b5e4u: goto P_0c09b5e4;
case 0x0c09b5e6u: goto P_0c09b5e6;
case 0x0c09b5e8u: goto P_0c09b5e8;
case 0x0c09b5eau: goto P_0c09b5ea;
case 0x0c09b5ecu: goto P_0c09b5ec;
case 0x0c09b5eeu: goto P_0c09b5ee;
case 0x0c09b5f0u: goto P_0c09b5f0;
case 0x0c09b5f2u: goto P_0c09b5f2;
case 0x0c09b5f4u: goto P_0c09b5f4;
case 0x0c09b614u: goto P_0c09b614;
case 0x0c09b616u: goto P_0c09b616;
case 0x0c09b618u: goto P_0c09b618;
case 0x0c09b61au: goto P_0c09b61a;
case 0x0c09b61cu: goto P_0c09b61c;
case 0x0c09b61eu: goto P_0c09b61e;
case 0x0c09b620u: goto P_0c09b620;
case 0x0c09b622u: goto P_0c09b622;
case 0x0c09b624u: goto P_0c09b624;
case 0x0c09b626u: goto P_0c09b626;
case 0x0c09b628u: goto P_0c09b628;
case 0x0c09b62au: goto P_0c09b62a;
case 0x0c09b62cu: goto P_0c09b62c;
case 0x0c09b62eu: goto P_0c09b62e;
case 0x0c09b630u: goto P_0c09b630;
case 0x0c09b632u: goto P_0c09b632;
case 0x0c09b634u: goto P_0c09b634;
case 0x0c09b636u: goto P_0c09b636;
case 0x0c09b638u: goto P_0c09b638;
case 0x0c09b63au: goto P_0c09b63a;
case 0x0c09b63cu: goto P_0c09b63c;
case 0x0c09b63eu: goto P_0c09b63e;
case 0x0c09b640u: goto P_0c09b640;
case 0x0c09b642u: goto P_0c09b642;
case 0x0c09b644u: goto P_0c09b644;
case 0x0c09b646u: goto P_0c09b646;
case 0x0c09b648u: goto P_0c09b648;
case 0x0c09b64au: goto P_0c09b64a;
case 0x0c09b64cu: goto P_0c09b64c;
case 0x0c09b64eu: goto P_0c09b64e;
case 0x0c09b650u: goto P_0c09b650;
case 0x0c09b652u: goto P_0c09b652;
case 0x0c09b654u: goto P_0c09b654;
case 0x0c09b656u: goto P_0c09b656;
case 0x0c09b658u: goto P_0c09b658;
case 0x0c09b65au: goto P_0c09b65a;
case 0x0c09b65cu: goto P_0c09b65c;
case 0x0c09b65eu: goto P_0c09b65e;
case 0x0c09b660u: goto P_0c09b660;
case 0x0c09b662u: goto P_0c09b662;
case 0x0c09b664u: goto P_0c09b664;
case 0x0c09b666u: goto P_0c09b666;
case 0x0c09b668u: goto P_0c09b668;
case 0x0c09b66au: goto P_0c09b66a;
case 0x0c09b66cu: goto P_0c09b66c;
case 0x0c09b66eu: goto P_0c09b66e;
case 0x0c09b670u: goto P_0c09b670;
case 0x0c09b672u: goto P_0c09b672;
case 0x0c09b674u: goto P_0c09b674;
case 0x0c09b676u: goto P_0c09b676;
case 0x0c09b678u: goto P_0c09b678;
case 0x0c09b67au: goto P_0c09b67a;
case 0x0c09b67cu: goto P_0c09b67c;
case 0x0c09b67eu: goto P_0c09b67e;
case 0x0c09b680u: goto P_0c09b680;
case 0x0c09b682u: goto P_0c09b682;
case 0x0c09b684u: goto P_0c09b684;
case 0x0c09b686u: goto P_0c09b686;
case 0x0c09b688u: goto P_0c09b688;
case 0x0c09b68au: goto P_0c09b68a;
case 0x0c09b68cu: goto P_0c09b68c;
case 0x0c09b68eu: goto P_0c09b68e;
case 0x0c09b690u: goto P_0c09b690;
case 0x0c09b692u: goto P_0c09b692;
case 0x0c09b694u: goto P_0c09b694;
case 0x0c09b696u: goto P_0c09b696;
case 0x0c09b698u: goto P_0c09b698;
case 0x0c09b69au: goto P_0c09b69a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09b298: /* original 2fe6, guest PC 0x0c09b298 */
if(!s->budget--) { s->failed_pc=0x0c09b298u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b29a;
P_0c09b29a: /* original 2fd6, guest PC 0x0c09b29a */
if(!s->budget--) { s->failed_pc=0x0c09b29au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b29c;
P_0c09b29c: /* original 2fc6, guest PC 0x0c09b29c */
if(!s->budget--) { s->failed_pc=0x0c09b29cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b29e;
P_0c09b29e: /* original 2fb6, guest PC 0x0c09b29e */
if(!s->budget--) { s->failed_pc=0x0c09b29eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b2a0;
P_0c09b2a0: /* original 2fa6, guest PC 0x0c09b2a0 */
if(!s->budget--) { s->failed_pc=0x0c09b2a0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b2a2;
P_0c09b2a2: /* original 2f96, guest PC 0x0c09b2a2 */
if(!s->budget--) { s->failed_pc=0x0c09b2a2u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b2a4;
P_0c09b2a4: /* original 4f22, guest PC 0x0c09b2a4 */
if(!s->budget--) { s->failed_pc=0x0c09b2a4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09b2a6;
P_0c09b2a6: /* original de2b, guest PC 0x0c09b2a6 */
if(!s->budget--) { s->failed_pc=0x0c09b2a6u; return 0; }
r[14]=read(ram,0x0c09b354u,4);
goto P_0c09b2a8;
P_0c09b2a8: /* original 7ff8, guest PC 0x0c09b2a8 */
if(!s->budget--) { s->failed_pc=0x0c09b2a8u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c09b2aa;
P_0c09b2aa: /* original be5f, guest PC 0x0c09b2aa */
if(!s->budget--) { s->failed_pc=0x0c09b2aau; return 0; }
target=code_base|0x0c09af6cu; r[16]=code_base|0x0c09b2aeu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b2aeu) { target=s->pc; goto dispatch; }
goto P_0c09b2ae;
P_0c09b2ac: /* original 0009, guest PC 0x0c09b2ac */
if(!s->budget--) { s->failed_pc=0x0c09b2acu; return 0; }
goto P_0c09b2ae;
P_0c09b2ae: /* original db2a, guest PC 0x0c09b2ae */
if(!s->budget--) { s->failed_pc=0x0c09b2aeu; return 0; }
r[11]=read(ram,0x0c09b358u,4);
goto P_0c09b2b0;
P_0c09b2b0: /* original e101, guest PC 0x0c09b2b0 */
if(!s->budget--) { s->failed_pc=0x0c09b2b0u; return 0; }
r[1]=0x00000001u;
goto P_0c09b2b2;
P_0c09b2b2: /* original d32a, guest PC 0x0c09b2b2 */
if(!s->budget--) { s->failed_pc=0x0c09b2b2u; return 0; }
r[3]=read(ram,0x0c09b35cu,4);
goto P_0c09b2b4;
P_0c09b2b4: /* original ed00, guest PC 0x0c09b2b4 */
if(!s->budget--) { s->failed_pc=0x0c09b2b4u; return 0; }
r[13]=0x00000000u;
goto P_0c09b2b6;
P_0c09b2b6: /* original 62b2, guest PC 0x0c09b2b6 */
if(!s->budget--) { s->failed_pc=0x0c09b2b6u; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c09b2b8;
P_0c09b2b8: /* original 2239, guest PC 0x0c09b2b8 */
if(!s->budget--) { s->failed_pc=0x0c09b2b8u; return 0; }
r[2]&=r[3];
goto P_0c09b2ba;
P_0c09b2ba: /* original 2b22, guest PC 0x0c09b2ba */
if(!s->budget--) { s->failed_pc=0x0c09b2bau; return 0; }
write(ram,r[11],r[2],4);
goto P_0c09b2bc;
P_0c09b2bc: /* original 9043, guest PC 0x0c09b2bc */
if(!s->budget--) { s->failed_pc=0x0c09b2bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b346u,2);
goto P_0c09b2be;
P_0c09b2be: /* original 0e14, guest PC 0x0c09b2be */
if(!s->budget--) { s->failed_pc=0x0c09b2beu; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c09b2c0;
P_0c09b2c0: /* original 7004, guest PC 0x0c09b2c0 */
if(!s->budget--) { s->failed_pc=0x0c09b2c0u; return 0; }
r[0]+=0x00000004u;
goto P_0c09b2c2;
P_0c09b2c2: /* original 0ed4, guest PC 0x0c09b2c2 */
if(!s->budget--) { s->failed_pc=0x0c09b2c2u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c09b2c4;
P_0c09b2c4: /* original d426, guest PC 0x0c09b2c4 */
if(!s->budget--) { s->failed_pc=0x0c09b2c4u; return 0; }
r[4]=read(ram,0x0c09b360u,4);
goto P_0c09b2c6;
P_0c09b2c6: /* original 6243, guest PC 0x0c09b2c6 */
if(!s->budget--) { s->failed_pc=0x0c09b2c6u; return 0; }
r[2]=r[4];
goto P_0c09b2c8;
P_0c09b2c8: /* original 722c, guest PC 0x0c09b2c8 */
if(!s->budget--) { s->failed_pc=0x0c09b2c8u; return 0; }
r[2]+=0x0000002cu;
goto P_0c09b2ca;
P_0c09b2ca: /* original 2f22, guest PC 0x0c09b2ca */
if(!s->budget--) { s->failed_pc=0x0c09b2cau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c09b2cc;
P_0c09b2cc: /* original 6a43, guest PC 0x0c09b2cc */
if(!s->budget--) { s->failed_pc=0x0c09b2ccu; return 0; }
r[10]=r[4];
goto P_0c09b2ce;
P_0c09b2ce: /* original 913b, guest PC 0x0c09b2ce */
if(!s->budget--) { s->failed_pc=0x0c09b2ceu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b348u,2);
goto P_0c09b2d0;
P_0c09b2d0: /* original 6943, guest PC 0x0c09b2d0 */
if(!s->budget--) { s->failed_pc=0x0c09b2d0u; return 0; }
r[9]=r[4];
goto P_0c09b2d2;
P_0c09b2d2: /* original 7a58, guest PC 0x0c09b2d2 */
if(!s->budget--) { s->failed_pc=0x0c09b2d2u; return 0; }
r[10]+=0x00000058u;
goto P_0c09b2d4;
P_0c09b2d4: /* original 314c, guest PC 0x0c09b2d4 */
if(!s->budget--) { s->failed_pc=0x0c09b2d4u; return 0; }
r[1]+=r[4];
goto P_0c09b2d6;
P_0c09b2d6: /* original 66a3, guest PC 0x0c09b2d6 */
if(!s->budget--) { s->failed_pc=0x0c09b2d6u; return 0; }
r[6]=r[10];
goto P_0c09b2d8;
P_0c09b2d8: /* original 1f11, guest PC 0x0c09b2d8 */
if(!s->budget--) { s->failed_pc=0x0c09b2d8u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c09b2da;
P_0c09b2da: /* original d222, guest PC 0x0c09b2da */
if(!s->budget--) { s->failed_pc=0x0c09b2dau; return 0; }
r[2]=read(ram,0x0c09b364u,4);
goto P_0c09b2dc;
P_0c09b2dc: /* original 9435, guest PC 0x0c09b2dc */
if(!s->budget--) { s->failed_pc=0x0c09b2dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b34au,2);
goto P_0c09b2de;
P_0c09b2de: /* original 420b, guest PC 0x0c09b2de */
if(!s->budget--) { s->failed_pc=0x0c09b2deu; return 0; }
target=r[2];
r[16]=code_base|0x0c09b2e2u;
r[5]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b2e2u) { target=s->pc; goto dispatch; }
goto P_0c09b2e2;
P_0c09b2e0: /* original 6593, guest PC 0x0c09b2e0 */
if(!s->budget--) { s->failed_pc=0x0c09b2e0u; return 0; }
r[5]=r[9];
goto P_0c09b2e2;
P_0c09b2e2: /* original dc21, guest PC 0x0c09b2e2 */
if(!s->budget--) { s->failed_pc=0x0c09b2e2u; return 0; }
r[12]=read(ram,0x0c09b368u,4);
goto P_0c09b2e4;
P_0c09b2e4: /* original 4c0b, guest PC 0x0c09b2e4 */
if(!s->budget--) { s->failed_pc=0x0c09b2e4u; return 0; }
target=r[12];
r[16]=code_base|0x0c09b2e8u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b2e8u) { target=s->pc; goto dispatch; }
goto P_0c09b2e8;
P_0c09b2e6: /* original 6493, guest PC 0x0c09b2e6 */
if(!s->budget--) { s->failed_pc=0x0c09b2e6u; return 0; }
r[4]=r[9];
goto P_0c09b2e8;
P_0c09b2e8: /* original 4c0b, guest PC 0x0c09b2e8 */
if(!s->budget--) { s->failed_pc=0x0c09b2e8u; return 0; }
target=r[12];
r[16]=code_base|0x0c09b2ecu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b2ecu) { target=s->pc; goto dispatch; }
goto P_0c09b2ec;
P_0c09b2ea: /* original 64a3, guest PC 0x0c09b2ea */
if(!s->budget--) { s->failed_pc=0x0c09b2eau; return 0; }
r[4]=r[10];
goto P_0c09b2ec;
P_0c09b2ec: /* original 4c0b, guest PC 0x0c09b2ec */
if(!s->budget--) { s->failed_pc=0x0c09b2ecu; return 0; }
target=r[12];
r[16]=code_base|0x0c09b2f0u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b2f0u) { target=s->pc; goto dispatch; }
goto P_0c09b2f0;
P_0c09b2ee: /* original 64f2, guest PC 0x0c09b2ee */
if(!s->budget--) { s->failed_pc=0x0c09b2eeu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c09b2f0;
P_0c09b2f0: /* original 4c0b, guest PC 0x0c09b2f0 */
if(!s->budget--) { s->failed_pc=0x0c09b2f0u; return 0; }
target=r[12];
r[16]=code_base|0x0c09b2f4u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b2f4u) { target=s->pc; goto dispatch; }
goto P_0c09b2f4;
P_0c09b2f2: /* original 54f1, guest PC 0x0c09b2f2 */
if(!s->budget--) { s->failed_pc=0x0c09b2f2u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c09b2f4;
P_0c09b2f4: /* original e07d, guest PC 0x0c09b2f4 */
if(!s->budget--) { s->failed_pc=0x0c09b2f4u; return 0; }
r[0]=0x0000007du;
goto P_0c09b2f6;
P_0c09b2f6: /* original e320, guest PC 0x0c09b2f6 */
if(!s->budget--) { s->failed_pc=0x0c09b2f6u; return 0; }
r[3]=0x00000020u;
goto P_0c09b2f8;
P_0c09b2f8: /* original 1e33, guest PC 0x0c09b2f8 */
if(!s->budget--) { s->failed_pc=0x0c09b2f8u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c09b2fa;
P_0c09b2fa: /* original e373, guest PC 0x0c09b2fa */
if(!s->budget--) { s->failed_pc=0x0c09b2fau; return 0; }
r[3]=0x00000073u;
goto P_0c09b2fc;
P_0c09b2fc: /* original 7f08, guest PC 0x0c09b2fc */
if(!s->budget--) { s->failed_pc=0x0c09b2fcu; return 0; }
r[15]+=0x00000008u;
goto P_0c09b2fe;
P_0c09b2fe: /* original 1ed6, guest PC 0x0c09b2fe */
if(!s->budget--) { s->failed_pc=0x0c09b2feu; return 0; }
write(ram,r[14]+24,r[13],4);
goto P_0c09b300;
P_0c09b300: /* original 0ed4, guest PC 0x0c09b300 */
if(!s->budget--) { s->failed_pc=0x0c09b300u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c09b302;
P_0c09b302: /* original 4f26, guest PC 0x0c09b302 */
if(!s->budget--) { s->failed_pc=0x0c09b302u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09b304;
P_0c09b304: /* original 1ed5, guest PC 0x0c09b304 */
if(!s->budget--) { s->failed_pc=0x0c09b304u; return 0; }
write(ram,r[14]+20,r[13],4);
goto P_0c09b306;
P_0c09b306: /* original 9021, guest PC 0x0c09b306 */
if(!s->budget--) { s->failed_pc=0x0c09b306u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b34cu,2);
goto P_0c09b308;
P_0c09b308: /* original 0ed6, guest PC 0x0c09b308 */
if(!s->budget--) { s->failed_pc=0x0c09b308u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c09b30a;
P_0c09b30a: /* original 70fc, guest PC 0x0c09b30a */
if(!s->budget--) { s->failed_pc=0x0c09b30au; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09b30c;
P_0c09b30c: /* original 0ed6, guest PC 0x0c09b30c */
if(!s->budget--) { s->failed_pc=0x0c09b30cu; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c09b30e;
P_0c09b30e: /* original 70fc, guest PC 0x0c09b30e */
if(!s->budget--) { s->failed_pc=0x0c09b30eu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09b310;
P_0c09b310: /* original 0ed6, guest PC 0x0c09b310 */
if(!s->budget--) { s->failed_pc=0x0c09b310u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c09b312;
P_0c09b312: /* original 700c, guest PC 0x0c09b312 */
if(!s->budget--) { s->failed_pc=0x0c09b312u; return 0; }
r[0]+=0x0000000cu;
goto P_0c09b314;
P_0c09b314: /* original 0ed6, guest PC 0x0c09b314 */
if(!s->budget--) { s->failed_pc=0x0c09b314u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c09b316;
P_0c09b316: /* original 7004, guest PC 0x0c09b316 */
if(!s->budget--) { s->failed_pc=0x0c09b316u; return 0; }
r[0]+=0x00000004u;
goto P_0c09b318;
P_0c09b318: /* original 0ed6, guest PC 0x0c09b318 */
if(!s->budget--) { s->failed_pc=0x0c09b318u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c09b31a;
P_0c09b31a: /* original 7004, guest PC 0x0c09b31a */
if(!s->budget--) { s->failed_pc=0x0c09b31au; return 0; }
r[0]+=0x00000004u;
goto P_0c09b31c;
P_0c09b31c: /* original 0ed6, guest PC 0x0c09b31c */
if(!s->budget--) { s->failed_pc=0x0c09b31cu; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c09b31e;
P_0c09b31e: /* original 7004, guest PC 0x0c09b31e */
if(!s->budget--) { s->failed_pc=0x0c09b31eu; return 0; }
r[0]+=0x00000004u;
goto P_0c09b320;
P_0c09b320: /* original 0ed6, guest PC 0x0c09b320 */
if(!s->budget--) { s->failed_pc=0x0c09b320u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c09b322;
P_0c09b322: /* original 84eb, guest PC 0x0c09b322 */
if(!s->budget--) { s->failed_pc=0x0c09b322u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c09b324;
P_0c09b324: /* original 7001, guest PC 0x0c09b324 */
if(!s->budget--) { s->failed_pc=0x0c09b324u; return 0; }
r[0]+=0x00000001u;
goto P_0c09b326;
P_0c09b326: /* original 80eb, guest PC 0x0c09b326 */
if(!s->budget--) { s->failed_pc=0x0c09b326u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09b328;
P_0c09b328: /* original e010, guest PC 0x0c09b328 */
if(!s->budget--) { s->failed_pc=0x0c09b328u; return 0; }
r[0]=0x00000010u;
goto P_0c09b32a;
P_0c09b32a: /* original 0e34, guest PC 0x0c09b32a */
if(!s->budget--) { s->failed_pc=0x0c09b32au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09b32c;
P_0c09b32c: /* original e3fe, guest PC 0x0c09b32c */
if(!s->budget--) { s->failed_pc=0x0c09b32cu; return 0; }
r[3]=0xfffffffeu;
goto P_0c09b32e;
P_0c09b32e: /* original 62b2, guest PC 0x0c09b32e */
if(!s->budget--) { s->failed_pc=0x0c09b32eu; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c09b330;
P_0c09b330: /* original 2239, guest PC 0x0c09b330 */
if(!s->budget--) { s->failed_pc=0x0c09b330u; return 0; }
r[2]&=r[3];
goto P_0c09b332;
P_0c09b332: /* original 2b22, guest PC 0x0c09b332 */
if(!s->budget--) { s->failed_pc=0x0c09b332u; return 0; }
write(ram,r[11],r[2],4);
goto P_0c09b334;
P_0c09b334: /* original 69f6, guest PC 0x0c09b334 */
if(!s->budget--) { s->failed_pc=0x0c09b334u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09b336;
P_0c09b336: /* original 6af6, guest PC 0x0c09b336 */
if(!s->budget--) { s->failed_pc=0x0c09b336u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09b338;
P_0c09b338: /* original 6bf6, guest PC 0x0c09b338 */
if(!s->budget--) { s->failed_pc=0x0c09b338u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09b33a;
P_0c09b33a: /* original 6cf6, guest PC 0x0c09b33a */
if(!s->budget--) { s->failed_pc=0x0c09b33au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09b33c;
P_0c09b33c: /* original 6df6, guest PC 0x0c09b33c */
if(!s->budget--) { s->failed_pc=0x0c09b33cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09b33e;
P_0c09b33e: /* original a015, guest PC 0x0c09b33e */
if(!s->budget--) { s->failed_pc=0x0c09b33eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09b36c;
P_0c09b340: /* original 6ef6, guest PC 0x0c09b340 */
if(!s->budget--) { s->failed_pc=0x0c09b340u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09b342u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09b342u; return 0; } return 1;
P_0c09b36c: /* original 2fe6, guest PC 0x0c09b36c */
if(!s->budget--) { s->failed_pc=0x0c09b36cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b36e;
P_0c09b36e: /* original 2fd6, guest PC 0x0c09b36e */
if(!s->budget--) { s->failed_pc=0x0c09b36eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b370;
P_0c09b370: /* original ed00, guest PC 0x0c09b370 */
if(!s->budget--) { s->failed_pc=0x0c09b370u; return 0; }
r[13]=0x00000000u;
goto P_0c09b372;
P_0c09b372: /* original 2fc6, guest PC 0x0c09b372 */
if(!s->budget--) { s->failed_pc=0x0c09b372u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b374;
P_0c09b374: /* original 2fb6, guest PC 0x0c09b374 */
if(!s->budget--) { s->failed_pc=0x0c09b374u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b376;
P_0c09b376: /* original eb05, guest PC 0x0c09b376 */
if(!s->budget--) { s->failed_pc=0x0c09b376u; return 0; }
r[11]=0x00000005u;
goto P_0c09b378;
P_0c09b378: /* original 2fa6, guest PC 0x0c09b378 */
if(!s->budget--) { s->failed_pc=0x0c09b378u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b37a;
P_0c09b37a: /* original 2f96, guest PC 0x0c09b37a */
if(!s->budget--) { s->failed_pc=0x0c09b37au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b37c;
P_0c09b37c: /* original 2f86, guest PC 0x0c09b37c */
if(!s->budget--) { s->failed_pc=0x0c09b37cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b37e;
P_0c09b37e: /* original 4f22, guest PC 0x0c09b37e */
if(!s->budget--) { s->failed_pc=0x0c09b37eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09b380;
P_0c09b380: /* original da33, guest PC 0x0c09b380 */
if(!s->budget--) { s->failed_pc=0x0c09b380u; return 0; }
r[10]=read(ram,0x0c09b450u,4);
goto P_0c09b382;
P_0c09b382: /* original de34, guest PC 0x0c09b382 */
if(!s->budget--) { s->failed_pc=0x0c09b382u; return 0; }
r[14]=read(ram,0x0c09b454u,4);
goto P_0c09b384;
P_0c09b384: /* original d334, guest PC 0x0c09b384 */
if(!s->budget--) { s->failed_pc=0x0c09b384u; return 0; }
r[3]=read(ram,0x0c09b458u,4);
goto P_0c09b386;
P_0c09b386: /* original 7ffc, guest PC 0x0c09b386 */
if(!s->budget--) { s->failed_pc=0x0c09b386u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09b388;
P_0c09b388: /* original 985c, guest PC 0x0c09b388 */
if(!s->budget--) { s->failed_pc=0x0c09b388u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b444u,2);
goto P_0c09b38a;
P_0c09b38a: /* original bdef, guest PC 0x0c09b38a */
if(!s->budget--) { s->failed_pc=0x0c09b38au; return 0; }
target=code_base|0x0c09af6cu; r[16]=code_base|0x0c09b38eu;
write(ram,r[15],r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b38eu) { target=s->pc; goto dispatch; }
goto P_0c09b38e;
P_0c09b38c: /* original 2f32, guest PC 0x0c09b38c */
if(!s->budget--) { s->failed_pc=0x0c09b38cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09b38e;
P_0c09b38e: /* original 6c03, guest PC 0x0c09b38e */
if(!s->budget--) { s->failed_pc=0x0c09b38eu; return 0; }
r[12]=r[0];
goto P_0c09b390;
P_0c09b390: /* original e07d, guest PC 0x0c09b390 */
if(!s->budget--) { s->failed_pc=0x0c09b390u; return 0; }
r[0]=0x0000007du;
goto P_0c09b392;
P_0c09b392: /* original 1ed6, guest PC 0x0c09b392 */
if(!s->budget--) { s->failed_pc=0x0c09b392u; return 0; }
write(ram,r[14]+24,r[13],4);
goto P_0c09b394;
P_0c09b394: /* original 0ed4, guest PC 0x0c09b394 */
if(!s->budget--) { s->failed_pc=0x0c09b394u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c09b396;
P_0c09b396: /* original 1ed5, guest PC 0x0c09b396 */
if(!s->budget--) { s->failed_pc=0x0c09b396u; return 0; }
write(ram,r[14]+20,r[13],4);
goto P_0c09b398;
P_0c09b398: /* original 53e3, guest PC 0x0c09b398 */
if(!s->budget--) { s->failed_pc=0x0c09b398u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c09b39a;
P_0c09b39a: /* original 4315, guest PC 0x0c09b39a */
if(!s->budget--) { s->failed_pc=0x0c09b39au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c09b39c;
P_0c09b39c: /* original 8b01, guest PC 0x0c09b39c */
if(!s->budget--) { s->failed_pc=0x0c09b39cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b3a2; }
goto P_0c09b39e;
P_0c09b39e: /* original a173, guest PC 0x0c09b39e */
if(!s->budget--) { s->failed_pc=0x0c09b39eu; return 0; }
goto P_0c09b688;
P_0c09b3a0: /* original 0009, guest PC 0x0c09b3a0 */
if(!s->budget--) { s->failed_pc=0x0c09b3a0u; return 0; }
goto P_0c09b3a2;
P_0c09b3a2: /* original e340, guest PC 0x0c09b3a2 */
if(!s->budget--) { s->failed_pc=0x0c09b3a2u; return 0; }
r[3]=0x00000040u;
goto P_0c09b3a4;
P_0c09b3a4: /* original 23c8, guest PC 0x0c09b3a4 */
if(!s->budget--) { s->failed_pc=0x0c09b3a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c09b3a6;
P_0c09b3a6: /* original 8d21, guest PC 0x0c09b3a6 */
if(!s->budget--) { s->failed_pc=0x0c09b3a6u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+12,r[13],4);
if(cond) { goto P_0c09b3ec; }
goto P_0c09b3aa;
P_0c09b3a8: /* original 1ed3, guest PC 0x0c09b3a8 */
if(!s->budget--) { s->failed_pc=0x0c09b3a8u; return 0; }
write(ram,r[14]+12,r[13],4);
goto P_0c09b3aa;
P_0c09b3aa: /* original 4a0b, guest PC 0x0c09b3aa */
if(!s->budget--) { s->failed_pc=0x0c09b3aau; return 0; }
target=r[10];
r[16]=code_base|0x0c09b3aeu;
r[4]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b3aeu) { target=s->pc; goto dispatch; }
goto P_0c09b3ae;
P_0c09b3ac: /* original 6483, guest PC 0x0c09b3ac */
if(!s->budget--) { s->failed_pc=0x0c09b3acu; return 0; }
r[4]=r[8];
goto P_0c09b3ae;
P_0c09b3ae: /* original 904a, guest PC 0x0c09b3ae */
if(!s->budget--) { s->failed_pc=0x0c09b3aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b446u,2);
goto P_0c09b3b0;
P_0c09b3b0: /* original 03ee, guest PC 0x0c09b3b0 */
if(!s->budget--) { s->failed_pc=0x0c09b3b0u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b3b2;
P_0c09b3b2: /* original 73ff, guest PC 0x0c09b3b2 */
if(!s->budget--) { s->failed_pc=0x0c09b3b2u; return 0; }
r[3]+=0xffffffffu;
goto P_0c09b3b4;
P_0c09b3b4: /* original 0e36, guest PC 0x0c09b3b4 */
if(!s->budget--) { s->failed_pc=0x0c09b3b4u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b3b6;
P_0c09b3b6: /* original 02ee, guest PC 0x0c09b3b6 */
if(!s->budget--) { s->failed_pc=0x0c09b3b6u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b3b8;
P_0c09b3b8: /* original 4211, guest PC 0x0c09b3b8 */
if(!s->budget--) { s->failed_pc=0x0c09b3b8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09b3ba;
P_0c09b3ba: /* original 890d, guest PC 0x0c09b3ba */
if(!s->budget--) { s->failed_pc=0x0c09b3bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b3d8; }
goto P_0c09b3bc;
P_0c09b3bc: /* original 9044, guest PC 0x0c09b3bc */
if(!s->budget--) { s->failed_pc=0x0c09b3bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b448u,2);
goto P_0c09b3be;
P_0c09b3be: /* original 00ee, guest PC 0x0c09b3be */
if(!s->budget--) { s->failed_pc=0x0c09b3beu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b3c0;
P_0c09b3c0: /* original 8802, guest PC 0x0c09b3c0 */
if(!s->budget--) { s->failed_pc=0x0c09b3c0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09b3c2;
P_0c09b3c2: /* original 8b07, guest PC 0x0c09b3c2 */
if(!s->budget--) { s->failed_pc=0x0c09b3c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b3d4; }
goto P_0c09b3c4;
P_0c09b3c4: /* original 9041, guest PC 0x0c09b3c4 */
if(!s->budget--) { s->failed_pc=0x0c09b3c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b44au,2);
goto P_0c09b3c6;
P_0c09b3c6: /* original 02ee, guest PC 0x0c09b3c6 */
if(!s->budget--) { s->failed_pc=0x0c09b3c6u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b3c8;
P_0c09b3c8: /* original 2228, guest PC 0x0c09b3c8 */
if(!s->budget--) { s->failed_pc=0x0c09b3c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09b3ca;
P_0c09b3ca: /* original 8b03, guest PC 0x0c09b3ca */
if(!s->budget--) { s->failed_pc=0x0c09b3cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b3d4; }
goto P_0c09b3cc;
P_0c09b3cc: /* original 903b, guest PC 0x0c09b3cc */
if(!s->budget--) { s->failed_pc=0x0c09b3ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b446u,2);
goto P_0c09b3ce;
P_0c09b3ce: /* original e306, guest PC 0x0c09b3ce */
if(!s->budget--) { s->failed_pc=0x0c09b3ceu; return 0; }
r[3]=0x00000006u;
goto P_0c09b3d0;
P_0c09b3d0: /* original a002, guest PC 0x0c09b3d0 */
if(!s->budget--) { s->failed_pc=0x0c09b3d0u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b3d8;
P_0c09b3d2: /* original 0e36, guest PC 0x0c09b3d2 */
if(!s->budget--) { s->failed_pc=0x0c09b3d2u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b3d4;
P_0c09b3d4: /* original 9037, guest PC 0x0c09b3d4 */
if(!s->budget--) { s->failed_pc=0x0c09b3d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b446u,2);
goto P_0c09b3d6;
P_0c09b3d6: /* original 0eb6, guest PC 0x0c09b3d6 */
if(!s->budget--) { s->failed_pc=0x0c09b3d6u; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c09b3d8;
P_0c09b3d8: /* original 9038, guest PC 0x0c09b3d8 */
if(!s->budget--) { s->failed_pc=0x0c09b3d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b44cu,2);
goto P_0c09b3da;
P_0c09b3da: /* original 00ee, guest PC 0x0c09b3da */
if(!s->budget--) { s->failed_pc=0x0c09b3dau; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b3dc;
P_0c09b3dc: /* original 8803, guest PC 0x0c09b3dc */
if(!s->budget--) { s->failed_pc=0x0c09b3dcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09b3de;
P_0c09b3de: /* original 8b03, guest PC 0x0c09b3de */
if(!s->budget--) { s->failed_pc=0x0c09b3deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b3e8; }
goto P_0c09b3e0;
P_0c09b3e0: /* original 9034, guest PC 0x0c09b3e0 */
if(!s->budget--) { s->failed_pc=0x0c09b3e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b44cu,2);
goto P_0c09b3e2;
P_0c09b3e2: /* original e204, guest PC 0x0c09b3e2 */
if(!s->budget--) { s->failed_pc=0x0c09b3e2u; return 0; }
r[2]=0x00000004u;
goto P_0c09b3e4;
P_0c09b3e4: /* original a002, guest PC 0x0c09b3e4 */
if(!s->budget--) { s->failed_pc=0x0c09b3e4u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09b3ec;
P_0c09b3e6: /* original 0e26, guest PC 0x0c09b3e6 */
if(!s->budget--) { s->failed_pc=0x0c09b3e6u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09b3e8;
P_0c09b3e8: /* original 9030, guest PC 0x0c09b3e8 */
if(!s->budget--) { s->failed_pc=0x0c09b3e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b44cu,2);
goto P_0c09b3ea;
P_0c09b3ea: /* original 0ed6, guest PC 0x0c09b3ea */
if(!s->budget--) { s->failed_pc=0x0c09b3eau; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c09b3ec;
P_0c09b3ec: /* original 932f, guest PC 0x0c09b3ec */
if(!s->budget--) { s->failed_pc=0x0c09b3ecu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b44eu,2);
goto P_0c09b3ee;
P_0c09b3ee: /* original 23c8, guest PC 0x0c09b3ee */
if(!s->budget--) { s->failed_pc=0x0c09b3eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c09b3f0;
P_0c09b3f0: /* original 8936, guest PC 0x0c09b3f0 */
if(!s->budget--) { s->failed_pc=0x0c09b3f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b460; }
goto P_0c09b3f2;
P_0c09b3f2: /* original 4a0b, guest PC 0x0c09b3f2 */
if(!s->budget--) { s->failed_pc=0x0c09b3f2u; return 0; }
target=r[10];
r[16]=code_base|0x0c09b3f6u;
r[4]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b3f6u) { target=s->pc; goto dispatch; }
goto P_0c09b3f6;
P_0c09b3f4: /* original 6483, guest PC 0x0c09b3f4 */
if(!s->budget--) { s->failed_pc=0x0c09b3f4u; return 0; }
r[4]=r[8];
goto P_0c09b3f6;
P_0c09b3f6: /* original 9026, guest PC 0x0c09b3f6 */
if(!s->budget--) { s->failed_pc=0x0c09b3f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b446u,2);
goto P_0c09b3f8;
P_0c09b3f8: /* original 03ee, guest PC 0x0c09b3f8 */
if(!s->budget--) { s->failed_pc=0x0c09b3f8u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b3fa;
P_0c09b3fa: /* original 7301, guest PC 0x0c09b3fa */
if(!s->budget--) { s->failed_pc=0x0c09b3fau; return 0; }
r[3]+=0x00000001u;
goto P_0c09b3fc;
P_0c09b3fc: /* original 0e36, guest PC 0x0c09b3fc */
if(!s->budget--) { s->failed_pc=0x0c09b3fcu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b3fe;
P_0c09b3fe: /* original 70fc, guest PC 0x0c09b3fe */
if(!s->budget--) { s->failed_pc=0x0c09b3feu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09b400;
P_0c09b400: /* original 00ee, guest PC 0x0c09b400 */
if(!s->budget--) { s->failed_pc=0x0c09b400u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b402;
P_0c09b402: /* original 8802, guest PC 0x0c09b402 */
if(!s->budget--) { s->failed_pc=0x0c09b402u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09b404;
P_0c09b404: /* original 8905, guest PC 0x0c09b404 */
if(!s->budget--) { s->failed_pc=0x0c09b404u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b412; }
goto P_0c09b406;
P_0c09b406: /* original 901e, guest PC 0x0c09b406 */
if(!s->budget--) { s->failed_pc=0x0c09b406u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b446u,2);
goto P_0c09b408;
P_0c09b408: /* original 02ee, guest PC 0x0c09b408 */
if(!s->budget--) { s->failed_pc=0x0c09b408u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b40a;
P_0c09b40a: /* original 32b7, guest PC 0x0c09b40a */
if(!s->budget--) { s->failed_pc=0x0c09b40au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[11])!=0);
goto P_0c09b40c;
P_0c09b40c: /* original 8910, guest PC 0x0c09b40c */
if(!s->budget--) { s->failed_pc=0x0c09b40cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b430; }
goto P_0c09b40e;
P_0c09b40e: /* original a011, guest PC 0x0c09b40e */
if(!s->budget--) { s->failed_pc=0x0c09b40eu; return 0; }
goto P_0c09b434;
P_0c09b410: /* original 0009, guest PC 0x0c09b410 */
if(!s->budget--) { s->failed_pc=0x0c09b410u; return 0; }
goto P_0c09b412;
P_0c09b412: /* original 901a, guest PC 0x0c09b412 */
if(!s->budget--) { s->failed_pc=0x0c09b412u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b44au,2);
goto P_0c09b414;
P_0c09b414: /* original 03ee, guest PC 0x0c09b414 */
if(!s->budget--) { s->failed_pc=0x0c09b414u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b416;
P_0c09b416: /* original 2338, guest PC 0x0c09b416 */
if(!s->budget--) { s->failed_pc=0x0c09b416u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09b418;
P_0c09b418: /* original 8b06, guest PC 0x0c09b418 */
if(!s->budget--) { s->failed_pc=0x0c09b418u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b428; }
goto P_0c09b41a;
P_0c09b41a: /* original 9014, guest PC 0x0c09b41a */
if(!s->budget--) { s->failed_pc=0x0c09b41au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b446u,2);
goto P_0c09b41c;
P_0c09b41c: /* original e306, guest PC 0x0c09b41c */
if(!s->budget--) { s->failed_pc=0x0c09b41cu; return 0; }
r[3]=0x00000006u;
goto P_0c09b41e;
P_0c09b41e: /* original 01ee, guest PC 0x0c09b41e */
if(!s->budget--) { s->failed_pc=0x0c09b41eu; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09b420;
P_0c09b420: /* original 3137, guest PC 0x0c09b420 */
if(!s->budget--) { s->failed_pc=0x0c09b420u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[3])!=0);
goto P_0c09b422;
P_0c09b422: /* original 8b07, guest PC 0x0c09b422 */
if(!s->budget--) { s->failed_pc=0x0c09b422u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b434; }
goto P_0c09b424;
P_0c09b424: /* original a004, guest PC 0x0c09b424 */
if(!s->budget--) { s->failed_pc=0x0c09b424u; return 0; }
goto P_0c09b430;
P_0c09b426: /* original 0009, guest PC 0x0c09b426 */
if(!s->budget--) { s->failed_pc=0x0c09b426u; return 0; }
goto P_0c09b428;
P_0c09b428: /* original 900d, guest PC 0x0c09b428 */
if(!s->budget--) { s->failed_pc=0x0c09b428u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b446u,2);
goto P_0c09b42a;
P_0c09b42a: /* original 03ee, guest PC 0x0c09b42a */
if(!s->budget--) { s->failed_pc=0x0c09b42au; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b42c;
P_0c09b42c: /* original 33b7, guest PC 0x0c09b42c */
if(!s->budget--) { s->failed_pc=0x0c09b42cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[11])!=0);
goto P_0c09b42e;
P_0c09b42e: /* original 8b01, guest PC 0x0c09b42e */
if(!s->budget--) { s->failed_pc=0x0c09b42eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b434; }
goto P_0c09b430;
P_0c09b430: /* original 9009, guest PC 0x0c09b430 */
if(!s->budget--) { s->failed_pc=0x0c09b430u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b446u,2);
goto P_0c09b432;
P_0c09b432: /* original 0ed6, guest PC 0x0c09b432 */
if(!s->budget--) { s->failed_pc=0x0c09b432u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c09b434;
P_0c09b434: /* original 900a, guest PC 0x0c09b434 */
if(!s->budget--) { s->failed_pc=0x0c09b434u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b44cu,2);
goto P_0c09b436;
P_0c09b436: /* original 00ee, guest PC 0x0c09b436 */
if(!s->budget--) { s->failed_pc=0x0c09b436u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b438;
P_0c09b438: /* original 8802, guest PC 0x0c09b438 */
if(!s->budget--) { s->failed_pc=0x0c09b438u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09b43a;
P_0c09b43a: /* original 8b0f, guest PC 0x0c09b43a */
if(!s->budget--) { s->failed_pc=0x0c09b43au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b45c; }
goto P_0c09b43c;
P_0c09b43c: /* original 9006, guest PC 0x0c09b43c */
if(!s->budget--) { s->failed_pc=0x0c09b43cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b44cu,2);
goto P_0c09b43e;
P_0c09b43e: /* original e203, guest PC 0x0c09b43e */
if(!s->budget--) { s->failed_pc=0x0c09b43eu; return 0; }
r[2]=0x00000003u;
goto P_0c09b440;
P_0c09b440: /* original a00e, guest PC 0x0c09b440 */
if(!s->budget--) { s->failed_pc=0x0c09b440u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09b460;
P_0c09b442: /* original 0e26, guest PC 0x0c09b442 */
if(!s->budget--) { s->failed_pc=0x0c09b442u; return 0; }
write(ram,r[14]+r[0],r[2],4);
if(!vf3_matrix_family(0x0c09b444u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09b444u; return 0; } return 1;
P_0c09b45c: /* original 906d, guest PC 0x0c09b45c */
if(!s->budget--) { s->failed_pc=0x0c09b45cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53au,2);
goto P_0c09b45e;
P_0c09b45e: /* original 0ed6, guest PC 0x0c09b45e */
if(!s->budget--) { s->failed_pc=0x0c09b45eu; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c09b460;
P_0c09b460: /* original e330, guest PC 0x0c09b460 */
if(!s->budget--) { s->failed_pc=0x0c09b460u; return 0; }
r[3]=0x00000030u;
goto P_0c09b462;
P_0c09b462: /* original 23c8, guest PC 0x0c09b462 */
if(!s->budget--) { s->failed_pc=0x0c09b462u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c09b464;
P_0c09b464: /* original 8d1f, guest PC 0x0c09b464 */
if(!s->budget--) { s->failed_pc=0x0c09b464u; return 0; }
cond=r[17]&1u;
r[9]=0x00000020u;
if(cond) { goto P_0c09b4a6; }
goto P_0c09b468;
P_0c09b466: /* original e920, guest PC 0x0c09b466 */
if(!s->budget--) { s->failed_pc=0x0c09b466u; return 0; }
r[9]=0x00000020u;
goto P_0c09b468;
P_0c09b468: /* original 4a0b, guest PC 0x0c09b468 */
if(!s->budget--) { s->failed_pc=0x0c09b468u; return 0; }
target=r[10];
r[16]=code_base|0x0c09b46cu;
r[4]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b46cu) { target=s->pc; goto dispatch; }
goto P_0c09b46c;
P_0c09b46a: /* original 6483, guest PC 0x0c09b46a */
if(!s->budget--) { s->failed_pc=0x0c09b46au; return 0; }
r[4]=r[8];
goto P_0c09b46c;
P_0c09b46c: /* original 9066, guest PC 0x0c09b46c */
if(!s->budget--) { s->failed_pc=0x0c09b46cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53cu,2);
goto P_0c09b46e;
P_0c09b46e: /* original e401, guest PC 0x0c09b46e */
if(!s->budget--) { s->failed_pc=0x0c09b46eu; return 0; }
r[4]=0x00000001u;
goto P_0c09b470;
P_0c09b470: /* original 03ee, guest PC 0x0c09b470 */
if(!s->budget--) { s->failed_pc=0x0c09b470u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b472;
P_0c09b472: /* original 234a, guest PC 0x0c09b472 */
if(!s->budget--) { s->failed_pc=0x0c09b472u; return 0; }
r[3]^=r[4];
goto P_0c09b474;
P_0c09b474: /* original 0e36, guest PC 0x0c09b474 */
if(!s->budget--) { s->failed_pc=0x0c09b474u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b476;
P_0c09b476: /* original 00ee, guest PC 0x0c09b476 */
if(!s->budget--) { s->failed_pc=0x0c09b476u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b478;
P_0c09b478: /* original 8801, guest PC 0x0c09b478 */
if(!s->budget--) { s->failed_pc=0x0c09b478u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09b47a;
P_0c09b47a: /* original 8b04, guest PC 0x0c09b47a */
if(!s->budget--) { s->failed_pc=0x0c09b47au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b486; }
goto P_0c09b47c;
P_0c09b47c: /* original 905f, guest PC 0x0c09b47c */
if(!s->budget--) { s->failed_pc=0x0c09b47cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53eu,2);
goto P_0c09b47e;
P_0c09b47e: /* original 02ee, guest PC 0x0c09b47e */
if(!s->budget--) { s->failed_pc=0x0c09b47eu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b480;
P_0c09b480: /* original 32b7, guest PC 0x0c09b480 */
if(!s->budget--) { s->failed_pc=0x0c09b480u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[11])!=0);
goto P_0c09b482;
P_0c09b482: /* original 8b00, guest PC 0x0c09b482 */
if(!s->budget--) { s->failed_pc=0x0c09b482u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b486; }
goto P_0c09b484;
P_0c09b484: /* original 0eb6, guest PC 0x0c09b484 */
if(!s->budget--) { s->failed_pc=0x0c09b484u; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c09b486;
P_0c09b486: /* original 63c3, guest PC 0x0c09b486 */
if(!s->budget--) { s->failed_pc=0x0c09b486u; return 0; }
r[3]=r[12];
goto P_0c09b488;
P_0c09b488: /* original 2398, guest PC 0x0c09b488 */
if(!s->budget--) { s->failed_pc=0x0c09b488u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c09b48a;
P_0c09b48a: /* original 8902, guest PC 0x0c09b48a */
if(!s->budget--) { s->failed_pc=0x0c09b48au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b492; }
goto P_0c09b48c;
P_0c09b48c: /* original 9055, guest PC 0x0c09b48c */
if(!s->budget--) { s->failed_pc=0x0c09b48cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53au,2);
goto P_0c09b48e;
P_0c09b48e: /* original a00a, guest PC 0x0c09b48e */
if(!s->budget--) { s->failed_pc=0x0c09b48eu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09b4a6;
P_0c09b490: /* original 0e46, guest PC 0x0c09b490 */
if(!s->budget--) { s->failed_pc=0x0c09b490u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09b492;
P_0c09b492: /* original 9052, guest PC 0x0c09b492 */
if(!s->budget--) { s->failed_pc=0x0c09b492u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53au,2);
goto P_0c09b494;
P_0c09b494: /* original 00ee, guest PC 0x0c09b494 */
if(!s->budget--) { s->failed_pc=0x0c09b494u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b496;
P_0c09b496: /* original 8801, guest PC 0x0c09b496 */
if(!s->budget--) { s->failed_pc=0x0c09b496u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09b498;
P_0c09b498: /* original 8b03, guest PC 0x0c09b498 */
if(!s->budget--) { s->failed_pc=0x0c09b498u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b4a2; }
goto P_0c09b49a;
P_0c09b49a: /* original 904e, guest PC 0x0c09b49a */
if(!s->budget--) { s->failed_pc=0x0c09b49au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53au,2);
goto P_0c09b49c;
P_0c09b49c: /* original e202, guest PC 0x0c09b49c */
if(!s->budget--) { s->failed_pc=0x0c09b49cu; return 0; }
r[2]=0x00000002u;
goto P_0c09b49e;
P_0c09b49e: /* original a002, guest PC 0x0c09b49e */
if(!s->budget--) { s->failed_pc=0x0c09b49eu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09b4a6;
P_0c09b4a0: /* original 0e26, guest PC 0x0c09b4a0 */
if(!s->budget--) { s->failed_pc=0x0c09b4a0u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09b4a2;
P_0c09b4a2: /* original 904a, guest PC 0x0c09b4a2 */
if(!s->budget--) { s->failed_pc=0x0c09b4a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53au,2);
goto P_0c09b4a4;
P_0c09b4a4: /* original 0ed6, guest PC 0x0c09b4a4 */
if(!s->budget--) { s->failed_pc=0x0c09b4a4u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c09b4a6;
P_0c09b4a6: /* original e308, guest PC 0x0c09b4a6 */
if(!s->budget--) { s->failed_pc=0x0c09b4a6u; return 0; }
r[3]=0x00000008u;
goto P_0c09b4a8;
P_0c09b4a8: /* original 23c8, guest PC 0x0c09b4a8 */
if(!s->budget--) { s->failed_pc=0x0c09b4a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c09b4aa;
P_0c09b4aa: /* original 8905, guest PC 0x0c09b4aa */
if(!s->budget--) { s->failed_pc=0x0c09b4aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b4b8; }
goto P_0c09b4ac;
P_0c09b4ac: /* original 9045, guest PC 0x0c09b4ac */
if(!s->budget--) { s->failed_pc=0x0c09b4acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53au,2);
goto P_0c09b4ae;
P_0c09b4ae: /* original 00ee, guest PC 0x0c09b4ae */
if(!s->budget--) { s->failed_pc=0x0c09b4aeu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b4b0;
P_0c09b4b0: /* original 8804, guest PC 0x0c09b4b0 */
if(!s->budget--) { s->failed_pc=0x0c09b4b0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c09b4b2;
P_0c09b4b2: /* original 8b01, guest PC 0x0c09b4b2 */
if(!s->budget--) { s->failed_pc=0x0c09b4b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b4b8; }
goto P_0c09b4b4;
P_0c09b4b4: /* original 9041, guest PC 0x0c09b4b4 */
if(!s->budget--) { s->failed_pc=0x0c09b4b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53au,2);
goto P_0c09b4b6;
P_0c09b4b6: /* original 0eb6, guest PC 0x0c09b4b6 */
if(!s->budget--) { s->failed_pc=0x0c09b4b6u; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c09b4b8;
P_0c09b4b8: /* original 9042, guest PC 0x0c09b4b8 */
if(!s->budget--) { s->failed_pc=0x0c09b4b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b540u,2);
goto P_0c09b4ba;
P_0c09b4ba: /* original d423, guest PC 0x0c09b4ba */
if(!s->budget--) { s->failed_pc=0x0c09b4bau; return 0; }
r[4]=read(ram,0x0c09b548u,4);
goto P_0c09b4bc;
P_0c09b4bc: /* original 03ee, guest PC 0x0c09b4bc */
if(!s->budget--) { s->failed_pc=0x0c09b4bcu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b4be;
P_0c09b4be: /* original 2338, guest PC 0x0c09b4be */
if(!s->budget--) { s->failed_pc=0x0c09b4beu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09b4c0;
P_0c09b4c0: /* original 8f1c, guest PC 0x0c09b4c0 */
if(!s->budget--) { s->failed_pc=0x0c09b4c0u; return 0; }
cond=r[17]&1u;
r[5]=0x00000009u;
if(!cond) { goto P_0c09b4fc; }
goto P_0c09b4c4;
P_0c09b4c2: /* original e509, guest PC 0x0c09b4c2 */
if(!s->budget--) { s->failed_pc=0x0c09b4c2u; return 0; }
r[5]=0x00000009u;
goto P_0c09b4c4;
P_0c09b4c4: /* original 903a, guest PC 0x0c09b4c4 */
if(!s->budget--) { s->failed_pc=0x0c09b4c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53cu,2);
goto P_0c09b4c6;
P_0c09b4c6: /* original 923a, guest PC 0x0c09b4c6 */
if(!s->budget--) { s->failed_pc=0x0c09b4c6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53eu,2);
goto P_0c09b4c8;
P_0c09b4c8: /* original 00ee, guest PC 0x0c09b4c8 */
if(!s->budget--) { s->failed_pc=0x0c09b4c8u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b4ca;
P_0c09b4ca: /* original 32ec, guest PC 0x0c09b4ca */
if(!s->budget--) { s->failed_pc=0x0c09b4cau; return 0; }
r[2]+=r[14];
goto P_0c09b4cc;
P_0c09b4cc: /* original 6303, guest PC 0x0c09b4cc */
if(!s->budget--) { s->failed_pc=0x0c09b4ccu; return 0; }
r[3]=r[0];
goto P_0c09b4ce;
P_0c09b4ce: /* original 4008, guest PC 0x0c09b4ce */
if(!s->budget--) { s->failed_pc=0x0c09b4ceu; return 0; }
r[0]<<=2;
goto P_0c09b4d0;
P_0c09b4d0: /* original 6222, guest PC 0x0c09b4d0 */
if(!s->budget--) { s->failed_pc=0x0c09b4d0u; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c09b4d2;
P_0c09b4d2: /* original 4000, guest PC 0x0c09b4d2 */
if(!s->budget--) { s->failed_pc=0x0c09b4d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c09b4d4;
P_0c09b4d4: /* original 3038, guest PC 0x0c09b4d4 */
if(!s->budget--) { s->failed_pc=0x0c09b4d4u; return 0; }
r[0]-=r[3];
goto P_0c09b4d6;
P_0c09b4d6: /* original 302c, guest PC 0x0c09b4d6 */
if(!s->budget--) { s->failed_pc=0x0c09b4d6u; return 0; }
r[0]+=r[2];
goto P_0c09b4d8;
P_0c09b4d8: /* original 034c, guest PC 0x0c09b4d8 */
if(!s->budget--) { s->failed_pc=0x0c09b4d8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09b4da;
P_0c09b4da: /* original 9032, guest PC 0x0c09b4da */
if(!s->budget--) { s->failed_pc=0x0c09b4dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b542u,2);
goto P_0c09b4dc;
P_0c09b4dc: /* original 0e36, guest PC 0x0c09b4dc */
if(!s->budget--) { s->failed_pc=0x0c09b4dcu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b4de;
P_0c09b4de: /* original 700c, guest PC 0x0c09b4de */
if(!s->budget--) { s->failed_pc=0x0c09b4deu; return 0; }
r[0]+=0x0000000cu;
goto P_0c09b4e0;
P_0c09b4e0: /* original 00ee, guest PC 0x0c09b4e0 */
if(!s->budget--) { s->failed_pc=0x0c09b4e0u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b4e2;
P_0c09b4e2: /* original 8805, guest PC 0x0c09b4e2 */
if(!s->budget--) { s->failed_pc=0x0c09b4e2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c09b4e4;
P_0c09b4e4: /* original 8b01, guest PC 0x0c09b4e4 */
if(!s->budget--) { s->failed_pc=0x0c09b4e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b4ea; }
goto P_0c09b4e6;
P_0c09b4e6: /* original 902c, guest PC 0x0c09b4e6 */
if(!s->budget--) { s->failed_pc=0x0c09b4e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b542u,2);
goto P_0c09b4e8;
P_0c09b4e8: /* original 0e56, guest PC 0x0c09b4e8 */
if(!s->budget--) { s->failed_pc=0x0c09b4e8u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c09b4ea;
P_0c09b4ea: /* original bd69, guest PC 0x0c09b4ea */
if(!s->budget--) { s->failed_pc=0x0c09b4eau; return 0; }
target=code_base|0x0c09afc0u; r[16]=code_base|0x0c09b4eeu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b4eeu) { target=s->pc; goto dispatch; }
goto P_0c09b4ee;
P_0c09b4ec: /* original 0009, guest PC 0x0c09b4ec */
if(!s->budget--) { s->failed_pc=0x0c09b4ecu; return 0; }
goto P_0c09b4ee;
P_0c09b4ee: /* original c808, guest PC 0x0c09b4ee */
if(!s->budget--) { s->failed_pc=0x0c09b4eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c09b4f0;
P_0c09b4f0: /* original 895d, guest PC 0x0c09b4f0 */
if(!s->budget--) { s->failed_pc=0x0c09b4f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b5ae; }
goto P_0c09b4f2;
P_0c09b4f2: /* original 9026, guest PC 0x0c09b4f2 */
if(!s->budget--) { s->failed_pc=0x0c09b4f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b542u,2);
goto P_0c09b4f4;
P_0c09b4f4: /* original 03ee, guest PC 0x0c09b4f4 */
if(!s->budget--) { s->failed_pc=0x0c09b4f4u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b4f6;
P_0c09b4f6: /* original 730d, guest PC 0x0c09b4f6 */
if(!s->budget--) { s->failed_pc=0x0c09b4f6u; return 0; }
r[3]+=0x0000000du;
goto P_0c09b4f8;
P_0c09b4f8: /* original a059, guest PC 0x0c09b4f8 */
if(!s->budget--) { s->failed_pc=0x0c09b4f8u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b5ae;
P_0c09b4fa: /* original 0e36, guest PC 0x0c09b4fa */
if(!s->budget--) { s->failed_pc=0x0c09b4fau; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b4fc;
P_0c09b4fc: /* original 00ee, guest PC 0x0c09b4fc */
if(!s->budget--) { s->failed_pc=0x0c09b4fcu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b4fe;
P_0c09b4fe: /* original 8801, guest PC 0x0c09b4fe */
if(!s->budget--) { s->failed_pc=0x0c09b4feu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09b500;
P_0c09b500: /* original 8b24, guest PC 0x0c09b500 */
if(!s->budget--) { s->failed_pc=0x0c09b500u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b54c; }
goto P_0c09b502;
P_0c09b502: /* original 901b, guest PC 0x0c09b502 */
if(!s->budget--) { s->failed_pc=0x0c09b502u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53cu,2);
goto P_0c09b504;
P_0c09b504: /* original 921b, guest PC 0x0c09b504 */
if(!s->budget--) { s->failed_pc=0x0c09b504u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53eu,2);
goto P_0c09b506;
P_0c09b506: /* original 00ee, guest PC 0x0c09b506 */
if(!s->budget--) { s->failed_pc=0x0c09b506u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b508;
P_0c09b508: /* original 32ec, guest PC 0x0c09b508 */
if(!s->budget--) { s->failed_pc=0x0c09b508u; return 0; }
r[2]+=r[14];
goto P_0c09b50a;
P_0c09b50a: /* original 6303, guest PC 0x0c09b50a */
if(!s->budget--) { s->failed_pc=0x0c09b50au; return 0; }
r[3]=r[0];
goto P_0c09b50c;
P_0c09b50c: /* original 4008, guest PC 0x0c09b50c */
if(!s->budget--) { s->failed_pc=0x0c09b50cu; return 0; }
r[0]<<=2;
goto P_0c09b50e;
P_0c09b50e: /* original 6222, guest PC 0x0c09b50e */
if(!s->budget--) { s->failed_pc=0x0c09b50eu; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c09b510;
P_0c09b510: /* original 4000, guest PC 0x0c09b510 */
if(!s->budget--) { s->failed_pc=0x0c09b510u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c09b512;
P_0c09b512: /* original 3038, guest PC 0x0c09b512 */
if(!s->budget--) { s->failed_pc=0x0c09b512u; return 0; }
r[0]-=r[3];
goto P_0c09b514;
P_0c09b514: /* original 302c, guest PC 0x0c09b514 */
if(!s->budget--) { s->failed_pc=0x0c09b514u; return 0; }
r[0]+=r[2];
goto P_0c09b516;
P_0c09b516: /* original 034c, guest PC 0x0c09b516 */
if(!s->budget--) { s->failed_pc=0x0c09b516u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09b518;
P_0c09b518: /* original 9014, guest PC 0x0c09b518 */
if(!s->budget--) { s->failed_pc=0x0c09b518u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b544u,2);
goto P_0c09b51a;
P_0c09b51a: /* original 0e36, guest PC 0x0c09b51a */
if(!s->budget--) { s->failed_pc=0x0c09b51au; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b51c;
P_0c09b51c: /* original 7008, guest PC 0x0c09b51c */
if(!s->budget--) { s->failed_pc=0x0c09b51cu; return 0; }
r[0]+=0x00000008u;
goto P_0c09b51e;
P_0c09b51e: /* original 00ee, guest PC 0x0c09b51e */
if(!s->budget--) { s->failed_pc=0x0c09b51eu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b520;
P_0c09b520: /* original 8805, guest PC 0x0c09b520 */
if(!s->budget--) { s->failed_pc=0x0c09b520u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c09b522;
P_0c09b522: /* original 8b01, guest PC 0x0c09b522 */
if(!s->budget--) { s->failed_pc=0x0c09b522u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b528; }
goto P_0c09b524;
P_0c09b524: /* original 900e, guest PC 0x0c09b524 */
if(!s->budget--) { s->failed_pc=0x0c09b524u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b544u,2);
goto P_0c09b526;
P_0c09b526: /* original 0e56, guest PC 0x0c09b526 */
if(!s->budget--) { s->failed_pc=0x0c09b526u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c09b528;
P_0c09b528: /* original bd4a, guest PC 0x0c09b528 */
if(!s->budget--) { s->failed_pc=0x0c09b528u; return 0; }
target=code_base|0x0c09afc0u; r[16]=code_base|0x0c09b52cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b52cu) { target=s->pc; goto dispatch; }
goto P_0c09b52c;
P_0c09b52a: /* original 0009, guest PC 0x0c09b52a */
if(!s->budget--) { s->failed_pc=0x0c09b52au; return 0; }
goto P_0c09b52c;
P_0c09b52c: /* original c808, guest PC 0x0c09b52c */
if(!s->budget--) { s->failed_pc=0x0c09b52cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c09b52e;
P_0c09b52e: /* original 893e, guest PC 0x0c09b52e */
if(!s->budget--) { s->failed_pc=0x0c09b52eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b5ae; }
goto P_0c09b530;
P_0c09b530: /* original 9008, guest PC 0x0c09b530 */
if(!s->budget--) { s->failed_pc=0x0c09b530u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b544u,2);
goto P_0c09b532;
P_0c09b532: /* original 03ee, guest PC 0x0c09b532 */
if(!s->budget--) { s->failed_pc=0x0c09b532u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b534;
P_0c09b534: /* original 730d, guest PC 0x0c09b534 */
if(!s->budget--) { s->failed_pc=0x0c09b534u; return 0; }
r[3]+=0x0000000du;
goto P_0c09b536;
P_0c09b536: /* original a03a, guest PC 0x0c09b536 */
if(!s->budget--) { s->failed_pc=0x0c09b536u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b5ae;
P_0c09b538: /* original 0e36, guest PC 0x0c09b538 */
if(!s->budget--) { s->failed_pc=0x0c09b538u; return 0; }
write(ram,r[14]+r[0],r[3],4);
if(!vf3_matrix_family(0x0c09b53au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09b53au; return 0; } return 1;
P_0c09b54c: /* original 9053, guest PC 0x0c09b54c */
if(!s->budget--) { s->failed_pc=0x0c09b54cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b5f6u,2);
goto P_0c09b54e;
P_0c09b54e: /* original 00ee, guest PC 0x0c09b54e */
if(!s->budget--) { s->failed_pc=0x0c09b54eu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b550;
P_0c09b550: /* original 8802, guest PC 0x0c09b550 */
if(!s->budget--) { s->failed_pc=0x0c09b550u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09b552;
P_0c09b552: /* original 8b0d, guest PC 0x0c09b552 */
if(!s->budget--) { s->failed_pc=0x0c09b552u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b570; }
goto P_0c09b554;
P_0c09b554: /* original 9050, guest PC 0x0c09b554 */
if(!s->budget--) { s->failed_pc=0x0c09b554u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b5f8u,2);
goto P_0c09b556;
P_0c09b556: /* original 02ee, guest PC 0x0c09b556 */
if(!s->budget--) { s->failed_pc=0x0c09b556u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b558;
P_0c09b558: /* original 70fc, guest PC 0x0c09b558 */
if(!s->budget--) { s->failed_pc=0x0c09b558u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09b55a;
P_0c09b55a: /* original 01ee, guest PC 0x0c09b55a */
if(!s->budget--) { s->failed_pc=0x0c09b55au; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09b55c;
P_0c09b55c: /* original 6323, guest PC 0x0c09b55c */
if(!s->budget--) { s->failed_pc=0x0c09b55cu; return 0; }
r[3]=r[2];
goto P_0c09b55e;
P_0c09b55e: /* original 4208, guest PC 0x0c09b55e */
if(!s->budget--) { s->failed_pc=0x0c09b55eu; return 0; }
r[2]<<=2;
goto P_0c09b560;
P_0c09b560: /* original 4200, guest PC 0x0c09b560 */
if(!s->budget--) { s->failed_pc=0x0c09b560u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c09b562;
P_0c09b562: /* original d028, guest PC 0x0c09b562 */
if(!s->budget--) { s->failed_pc=0x0c09b562u; return 0; }
r[0]=read(ram,0x0c09b604u,4);
goto P_0c09b564;
P_0c09b564: /* original 3238, guest PC 0x0c09b564 */
if(!s->budget--) { s->failed_pc=0x0c09b564u; return 0; }
r[2]-=r[3];
goto P_0c09b566;
P_0c09b566: /* original 321c, guest PC 0x0c09b566 */
if(!s->budget--) { s->failed_pc=0x0c09b566u; return 0; }
r[2]+=r[1];
goto P_0c09b568;
P_0c09b568: /* original 032c, guest PC 0x0c09b568 */
if(!s->budget--) { s->failed_pc=0x0c09b568u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c09b56a;
P_0c09b56a: /* original 9046, guest PC 0x0c09b56a */
if(!s->budget--) { s->failed_pc=0x0c09b56au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b5fau,2);
goto P_0c09b56c;
P_0c09b56c: /* original a01f, guest PC 0x0c09b56c */
if(!s->budget--) { s->failed_pc=0x0c09b56cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b5ae;
P_0c09b56e: /* original 0e36, guest PC 0x0c09b56e */
if(!s->budget--) { s->failed_pc=0x0c09b56eu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b570;
P_0c09b570: /* original 9041, guest PC 0x0c09b570 */
if(!s->budget--) { s->failed_pc=0x0c09b570u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b5f6u,2);
goto P_0c09b572;
P_0c09b572: /* original e102, guest PC 0x0c09b572 */
if(!s->budget--) { s->failed_pc=0x0c09b572u; return 0; }
r[1]=0x00000002u;
goto P_0c09b574;
P_0c09b574: /* original 02ee, guest PC 0x0c09b574 */
if(!s->budget--) { s->failed_pc=0x0c09b574u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b576;
P_0c09b576: /* original 3217, guest PC 0x0c09b576 */
if(!s->budget--) { s->failed_pc=0x0c09b576u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[1])!=0);
goto P_0c09b578;
P_0c09b578: /* original 8b19, guest PC 0x0c09b578 */
if(!s->budget--) { s->failed_pc=0x0c09b578u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b5ae; }
goto P_0c09b57a;
P_0c09b57a: /* original 53e3, guest PC 0x0c09b57a */
if(!s->budget--) { s->failed_pc=0x0c09b57au; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c09b57c;
P_0c09b57c: /* original 4315, guest PC 0x0c09b57c */
if(!s->budget--) { s->failed_pc=0x0c09b57cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c09b57e;
P_0c09b57e: /* original 8916, guest PC 0x0c09b57e */
if(!s->budget--) { s->failed_pc=0x0c09b57eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b5ae; }
goto P_0c09b580;
P_0c09b580: /* original 63f2, guest PC 0x0c09b580 */
if(!s->budget--) { s->failed_pc=0x0c09b580u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09b582;
P_0c09b582: /* original 7f04, guest PC 0x0c09b582 */
if(!s->budget--) { s->failed_pc=0x0c09b582u; return 0; }
r[15]+=0x00000004u;
goto P_0c09b584;
P_0c09b584: /* original 4f26, guest PC 0x0c09b584 */
if(!s->budget--) { s->failed_pc=0x0c09b584u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09b586;
P_0c09b586: /* original e006, guest PC 0x0c09b586 */
if(!s->budget--) { s->failed_pc=0x0c09b586u; return 0; }
r[0]=0x00000006u;
goto P_0c09b588;
P_0c09b588: /* original 5132, guest PC 0x0c09b588 */
if(!s->budget--) { s->failed_pc=0x0c09b588u; return 0; }
r[1]=read(ram,r[3]+8,4);
goto P_0c09b58a;
P_0c09b58a: /* original d21f, guest PC 0x0c09b58a */
if(!s->budget--) { s->failed_pc=0x0c09b58au; return 0; }
r[2]=read(ram,0x0c09b608u,4);
goto P_0c09b58c;
P_0c09b58c: /* original 2129, guest PC 0x0c09b58c */
if(!s->budget--) { s->failed_pc=0x0c09b58cu; return 0; }
r[1]&=r[2];
goto P_0c09b58e;
P_0c09b58e: /* original 1312, guest PC 0x0c09b58e */
if(!s->budget--) { s->failed_pc=0x0c09b58eu; return 0; }
write(ram,r[3]+8,r[1],4);
goto P_0c09b590;
P_0c09b590: /* original 80ea, guest PC 0x0c09b590 */
if(!s->budget--) { s->failed_pc=0x0c09b590u; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c09b592;
P_0c09b592: /* original 68f6, guest PC 0x0c09b592 */
if(!s->budget--) { s->failed_pc=0x0c09b592u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09b594;
P_0c09b594: /* original 9031, guest PC 0x0c09b594 */
if(!s->budget--) { s->failed_pc=0x0c09b594u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b5fau,2);
goto P_0c09b596;
P_0c09b596: /* original 69f6, guest PC 0x0c09b596 */
if(!s->budget--) { s->failed_pc=0x0c09b596u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09b598;
P_0c09b598: /* original 04ee, guest PC 0x0c09b598 */
if(!s->budget--) { s->failed_pc=0x0c09b598u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09b59a;
P_0c09b59a: /* original 6af6, guest PC 0x0c09b59a */
if(!s->budget--) { s->failed_pc=0x0c09b59au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09b59c;
P_0c09b59c: /* original d01b, guest PC 0x0c09b59c */
if(!s->budget--) { s->failed_pc=0x0c09b59cu; return 0; }
r[0]=read(ram,0x0c09b60cu,4);
goto P_0c09b59e;
P_0c09b59e: /* original 4408, guest PC 0x0c09b59e */
if(!s->budget--) { s->failed_pc=0x0c09b59eu; return 0; }
r[4]<<=2;
goto P_0c09b5a0;
P_0c09b5a0: /* original 6bf6, guest PC 0x0c09b5a0 */
if(!s->budget--) { s->failed_pc=0x0c09b5a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09b5a2;
P_0c09b5a2: /* original d31b, guest PC 0x0c09b5a2 */
if(!s->budget--) { s->failed_pc=0x0c09b5a2u; return 0; }
r[3]=read(ram,0x0c09b610u,4);
goto P_0c09b5a4;
P_0c09b5a4: /* original 6cf6, guest PC 0x0c09b5a4 */
if(!s->budget--) { s->failed_pc=0x0c09b5a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09b5a6;
P_0c09b5a6: /* original 044e, guest PC 0x0c09b5a6 */
if(!s->budget--) { s->failed_pc=0x0c09b5a6u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c09b5a8;
P_0c09b5a8: /* original 6df6, guest PC 0x0c09b5a8 */
if(!s->budget--) { s->failed_pc=0x0c09b5a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09b5aa;
P_0c09b5aa: /* original 432b, guest PC 0x0c09b5aa */
if(!s->budget--) { s->failed_pc=0x0c09b5aau; return 0; }
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
P_0c09b5ac: /* original 6ef6, guest PC 0x0c09b5ac */
if(!s->budget--) { s->failed_pc=0x0c09b5acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09b5ae;
P_0c09b5ae: /* original e204, guest PC 0x0c09b5ae */
if(!s->budget--) { s->failed_pc=0x0c09b5aeu; return 0; }
r[2]=0x00000004u;
goto P_0c09b5b0;
P_0c09b5b0: /* original 22c8, guest PC 0x0c09b5b0 */
if(!s->budget--) { s->failed_pc=0x0c09b5b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c09b5b2;
P_0c09b5b2: /* original 895c, guest PC 0x0c09b5b2 */
if(!s->budget--) { s->failed_pc=0x0c09b5b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b66e; }
goto P_0c09b5b4;
P_0c09b5b4: /* original 9423, guest PC 0x0c09b5b4 */
if(!s->budget--) { s->failed_pc=0x0c09b5b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b5feu,2);
goto P_0c09b5b6;
P_0c09b5b6: /* original 9021, guest PC 0x0c09b5b6 */
if(!s->budget--) { s->failed_pc=0x0c09b5b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b5fcu,2);
goto P_0c09b5b8;
P_0c09b5b8: /* original 4a0b, guest PC 0x0c09b5b8 */
if(!s->budget--) { s->failed_pc=0x0c09b5b8u; return 0; }
target=r[10];
r[16]=code_base|0x0c09b5bcu;
write(ram,r[14]+r[0],r[13],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b5bcu) { target=s->pc; goto dispatch; }
goto P_0c09b5bc;
P_0c09b5ba: /* original 0ed6, guest PC 0x0c09b5ba */
if(!s->budget--) { s->failed_pc=0x0c09b5bau; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c09b5bc;
P_0c09b5bc: /* original 901b, guest PC 0x0c09b5bc */
if(!s->budget--) { s->failed_pc=0x0c09b5bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b5f6u,2);
goto P_0c09b5be;
P_0c09b5be: /* original 00ee, guest PC 0x0c09b5be */
if(!s->budget--) { s->failed_pc=0x0c09b5beu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b5c0;
P_0c09b5c0: /* original 8802, guest PC 0x0c09b5c0 */
if(!s->budget--) { s->failed_pc=0x0c09b5c0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09b5c2;
P_0c09b5c2: /* original 8927, guest PC 0x0c09b5c2 */
if(!s->budget--) { s->failed_pc=0x0c09b5c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b614; }
goto P_0c09b5c4;
P_0c09b5c4: /* original 9017, guest PC 0x0c09b5c4 */
if(!s->budget--) { s->failed_pc=0x0c09b5c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b5f6u,2);
goto P_0c09b5c6;
P_0c09b5c6: /* original 00ee, guest PC 0x0c09b5c6 */
if(!s->budget--) { s->failed_pc=0x0c09b5c6u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b5c8;
P_0c09b5c8: /* original 8801, guest PC 0x0c09b5c8 */
if(!s->budget--) { s->failed_pc=0x0c09b5c8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09b5ca;
P_0c09b5ca: /* original 8b4a, guest PC 0x0c09b5ca */
if(!s->budget--) { s->failed_pc=0x0c09b5cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b662; }
goto P_0c09b5cc;
P_0c09b5cc: /* original 9018, guest PC 0x0c09b5cc */
if(!s->budget--) { s->failed_pc=0x0c09b5ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b600u,2);
goto P_0c09b5ce;
P_0c09b5ce: /* original 02ee, guest PC 0x0c09b5ce */
if(!s->budget--) { s->failed_pc=0x0c09b5ceu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b5d0;
P_0c09b5d0: /* original 70fc, guest PC 0x0c09b5d0 */
if(!s->budget--) { s->failed_pc=0x0c09b5d0u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09b5d2;
P_0c09b5d2: /* original 03ee, guest PC 0x0c09b5d2 */
if(!s->budget--) { s->failed_pc=0x0c09b5d2u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b5d4;
P_0c09b5d4: /* original 3320, guest PC 0x0c09b5d4 */
if(!s->budget--) { s->failed_pc=0x0c09b5d4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c09b5d6;
P_0c09b5d6: /* original 8b44, guest PC 0x0c09b5d6 */
if(!s->budget--) { s->failed_pc=0x0c09b5d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b662; }
goto P_0c09b5d8;
P_0c09b5d8: /* original 9013, guest PC 0x0c09b5d8 */
if(!s->budget--) { s->failed_pc=0x0c09b5d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b602u,2);
goto P_0c09b5da;
P_0c09b5da: /* original e30d, guest PC 0x0c09b5da */
if(!s->budget--) { s->failed_pc=0x0c09b5dau; return 0; }
r[3]=0x0000000du;
goto P_0c09b5dc;
P_0c09b5dc: /* original 01ee, guest PC 0x0c09b5dc */
if(!s->budget--) { s->failed_pc=0x0c09b5dcu; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09b5de;
P_0c09b5de: /* original 3133, guest PC 0x0c09b5de */
if(!s->budget--) { s->failed_pc=0x0c09b5deu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c09b5e0;
P_0c09b5e0: /* original 8b04, guest PC 0x0c09b5e0 */
if(!s->budget--) { s->failed_pc=0x0c09b5e0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b5ec; }
goto P_0c09b5e2;
P_0c09b5e2: /* original 900d, guest PC 0x0c09b5e2 */
if(!s->budget--) { s->failed_pc=0x0c09b5e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b600u,2);
goto P_0c09b5e4;
P_0c09b5e4: /* original 02ee, guest PC 0x0c09b5e4 */
if(!s->budget--) { s->failed_pc=0x0c09b5e4u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b5e6;
P_0c09b5e6: /* original 72f3, guest PC 0x0c09b5e6 */
if(!s->budget--) { s->failed_pc=0x0c09b5e6u; return 0; }
r[2]+=0xfffffff3u;
goto P_0c09b5e8;
P_0c09b5e8: /* original a03b, guest PC 0x0c09b5e8 */
if(!s->budget--) { s->failed_pc=0x0c09b5e8u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09b662;
P_0c09b5ea: /* original 0e26, guest PC 0x0c09b5ea */
if(!s->budget--) { s->failed_pc=0x0c09b5eau; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09b5ec;
P_0c09b5ec: /* original 9008, guest PC 0x0c09b5ec */
if(!s->budget--) { s->failed_pc=0x0c09b5ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b600u,2);
goto P_0c09b5ee;
P_0c09b5ee: /* original 02ee, guest PC 0x0c09b5ee */
if(!s->budget--) { s->failed_pc=0x0c09b5eeu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b5f0;
P_0c09b5f0: /* original 332c, guest PC 0x0c09b5f0 */
if(!s->budget--) { s->failed_pc=0x0c09b5f0u; return 0; }
r[3]+=r[2];
goto P_0c09b5f2;
P_0c09b5f2: /* original a036, guest PC 0x0c09b5f2 */
if(!s->budget--) { s->failed_pc=0x0c09b5f2u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b662;
P_0c09b5f4: /* original 0e36, guest PC 0x0c09b5f4 */
if(!s->budget--) { s->failed_pc=0x0c09b5f4u; return 0; }
write(ram,r[14]+r[0],r[3],4);
if(!vf3_matrix_family(0x0c09b5f6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09b5f6u; return 0; } return 1;
P_0c09b614: /* original bcd4, guest PC 0x0c09b614 */
if(!s->budget--) { s->failed_pc=0x0c09b614u; return 0; }
target=code_base|0x0c09afc0u; r[16]=code_base|0x0c09b618u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b618u) { target=s->pc; goto dispatch; }
goto P_0c09b618;
P_0c09b616: /* original 0009, guest PC 0x0c09b616 */
if(!s->budget--) { s->failed_pc=0x0c09b616u; return 0; }
goto P_0c09b618;
P_0c09b618: /* original c808, guest PC 0x0c09b618 */
if(!s->budget--) { s->failed_pc=0x0c09b618u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c09b61a;
P_0c09b61a: /* original 8903, guest PC 0x0c09b61a */
if(!s->budget--) { s->failed_pc=0x0c09b61au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b624; }
goto P_0c09b61c;
P_0c09b61c: /* original 9079, guest PC 0x0c09b61c */
if(!s->budget--) { s->failed_pc=0x0c09b61cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b712u,2);
goto P_0c09b61e;
P_0c09b61e: /* original 02ee, guest PC 0x0c09b61e */
if(!s->budget--) { s->failed_pc=0x0c09b61eu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b620;
P_0c09b620: /* original 7210, guest PC 0x0c09b620 */
if(!s->budget--) { s->failed_pc=0x0c09b620u; return 0; }
r[2]+=0x00000010u;
goto P_0c09b622;
P_0c09b622: /* original 0e26, guest PC 0x0c09b622 */
if(!s->budget--) { s->failed_pc=0x0c09b622u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09b624;
P_0c09b624: /* original bccc, guest PC 0x0c09b624 */
if(!s->budget--) { s->failed_pc=0x0c09b624u; return 0; }
target=code_base|0x0c09afc0u; r[16]=code_base|0x0c09b628u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b628u) { target=s->pc; goto dispatch; }
goto P_0c09b628;
P_0c09b626: /* original 0009, guest PC 0x0c09b626 */
if(!s->budget--) { s->failed_pc=0x0c09b626u; return 0; }
goto P_0c09b628;
P_0c09b628: /* original 9174, guest PC 0x0c09b628 */
if(!s->budget--) { s->failed_pc=0x0c09b628u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b714u,2);
goto P_0c09b62a;
P_0c09b62a: /* original 2018, guest PC 0x0c09b62a */
if(!s->budget--) { s->failed_pc=0x0c09b62au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c09b62c;
P_0c09b62c: /* original 8903, guest PC 0x0c09b62c */
if(!s->budget--) { s->failed_pc=0x0c09b62cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b636; }
goto P_0c09b62e;
P_0c09b62e: /* original 9070, guest PC 0x0c09b62e */
if(!s->budget--) { s->failed_pc=0x0c09b62eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b712u,2);
goto P_0c09b630;
P_0c09b630: /* original 02ee, guest PC 0x0c09b630 */
if(!s->budget--) { s->failed_pc=0x0c09b630u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b632;
P_0c09b632: /* original 7210, guest PC 0x0c09b632 */
if(!s->budget--) { s->failed_pc=0x0c09b632u; return 0; }
r[2]+=0x00000010u;
goto P_0c09b634;
P_0c09b634: /* original 0e26, guest PC 0x0c09b634 */
if(!s->budget--) { s->failed_pc=0x0c09b634u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09b636;
P_0c09b636: /* original 906c, guest PC 0x0c09b636 */
if(!s->budget--) { s->failed_pc=0x0c09b636u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b712u,2);
goto P_0c09b638;
P_0c09b638: /* original e330, guest PC 0x0c09b638 */
if(!s->budget--) { s->failed_pc=0x0c09b638u; return 0; }
r[3]=0x00000030u;
goto P_0c09b63a;
P_0c09b63a: /* original 01ee, guest PC 0x0c09b63a */
if(!s->budget--) { s->failed_pc=0x0c09b63au; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09b63c;
P_0c09b63c: /* original 3137, guest PC 0x0c09b63c */
if(!s->budget--) { s->failed_pc=0x0c09b63cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[3])!=0);
goto P_0c09b63e;
P_0c09b63e: /* original 8b03, guest PC 0x0c09b63e */
if(!s->budget--) { s->failed_pc=0x0c09b63eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b648; }
goto P_0c09b640;
P_0c09b640: /* original 01ee, guest PC 0x0c09b640 */
if(!s->budget--) { s->failed_pc=0x0c09b640u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09b642;
P_0c09b642: /* original e21f, guest PC 0x0c09b642 */
if(!s->budget--) { s->failed_pc=0x0c09b642u; return 0; }
r[2]=0x0000001fu;
goto P_0c09b644;
P_0c09b644: /* original 2129, guest PC 0x0c09b644 */
if(!s->budget--) { s->failed_pc=0x0c09b644u; return 0; }
r[1]&=r[2];
goto P_0c09b646;
P_0c09b646: /* original 0e16, guest PC 0x0c09b646 */
if(!s->budget--) { s->failed_pc=0x0c09b646u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09b648;
P_0c09b648: /* original 63f2, guest PC 0x0c09b648 */
if(!s->budget--) { s->failed_pc=0x0c09b648u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09b64a;
P_0c09b64a: /* original d234, guest PC 0x0c09b64a */
if(!s->budget--) { s->failed_pc=0x0c09b64au; return 0; }
r[2]=read(ram,0x0c09b71cu,4);
goto P_0c09b64c;
P_0c09b64c: /* original 5132, guest PC 0x0c09b64c */
if(!s->budget--) { s->failed_pc=0x0c09b64cu; return 0; }
r[1]=read(ram,r[3]+8,4);
goto P_0c09b64e;
P_0c09b64e: /* original 2128, guest PC 0x0c09b64e */
if(!s->budget--) { s->failed_pc=0x0c09b64eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c09b650;
P_0c09b650: /* original 8907, guest PC 0x0c09b650 */
if(!s->budget--) { s->failed_pc=0x0c09b650u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b662; }
goto P_0c09b652;
P_0c09b652: /* original 9060, guest PC 0x0c09b652 */
if(!s->budget--) { s->failed_pc=0x0c09b652u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b716u,2);
goto P_0c09b654;
P_0c09b654: /* original 04ee, guest PC 0x0c09b654 */
if(!s->budget--) { s->failed_pc=0x0c09b654u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09b656;
P_0c09b656: /* original 7004, guest PC 0x0c09b656 */
if(!s->budget--) { s->failed_pc=0x0c09b656u; return 0; }
r[0]+=0x00000004u;
goto P_0c09b658;
P_0c09b658: /* original 03ee, guest PC 0x0c09b658 */
if(!s->budget--) { s->failed_pc=0x0c09b658u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b65a;
P_0c09b65a: /* original 70fc, guest PC 0x0c09b65a */
if(!s->budget--) { s->failed_pc=0x0c09b65au; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09b65c;
P_0c09b65c: /* original 0e36, guest PC 0x0c09b65c */
if(!s->budget--) { s->failed_pc=0x0c09b65cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b65e;
P_0c09b65e: /* original 7004, guest PC 0x0c09b65e */
if(!s->budget--) { s->failed_pc=0x0c09b65eu; return 0; }
r[0]+=0x00000004u;
goto P_0c09b660;
P_0c09b660: /* original 0e46, guest PC 0x0c09b660 */
if(!s->budget--) { s->failed_pc=0x0c09b660u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09b662;
P_0c09b662: /* original 9059, guest PC 0x0c09b662 */
if(!s->budget--) { s->failed_pc=0x0c09b662u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b718u,2);
goto P_0c09b664;
P_0c09b664: /* original 03ee, guest PC 0x0c09b664 */
if(!s->budget--) { s->failed_pc=0x0c09b664u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b666;
P_0c09b666: /* original 7301, guest PC 0x0c09b666 */
if(!s->budget--) { s->failed_pc=0x0c09b666u; return 0; }
r[3]+=0x00000001u;
goto P_0c09b668;
P_0c09b668: /* original 0e36, guest PC 0x0c09b668 */
if(!s->budget--) { s->failed_pc=0x0c09b668u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b66a;
P_0c09b66a: /* original a00d, guest PC 0x0c09b66a */
if(!s->budget--) { s->failed_pc=0x0c09b66au; return 0; }
write(ram,r[14]+12,r[9],4);
goto P_0c09b688;
P_0c09b66c: /* original 1e93, guest PC 0x0c09b66c */
if(!s->budget--) { s->failed_pc=0x0c09b66cu; return 0; }
write(ram,r[14]+12,r[9],4);
goto P_0c09b66e;
P_0c09b66e: /* original e302, guest PC 0x0c09b66e */
if(!s->budget--) { s->failed_pc=0x0c09b66eu; return 0; }
r[3]=0x00000002u;
goto P_0c09b670;
P_0c09b670: /* original 2c38, guest PC 0x0c09b670 */
if(!s->budget--) { s->failed_pc=0x0c09b670u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[3])==0)!=0);
goto P_0c09b672;
P_0c09b672: /* original 8909, guest PC 0x0c09b672 */
if(!s->budget--) { s->failed_pc=0x0c09b672u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b688; }
goto P_0c09b674;
P_0c09b674: /* original 9050, guest PC 0x0c09b674 */
if(!s->budget--) { s->failed_pc=0x0c09b674u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b718u,2);
goto P_0c09b676;
P_0c09b676: /* original 01ee, guest PC 0x0c09b676 */
if(!s->budget--) { s->failed_pc=0x0c09b676u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09b678;
P_0c09b678: /* original 4115, guest PC 0x0c09b678 */
if(!s->budget--) { s->failed_pc=0x0c09b678u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c09b67a;
P_0c09b67a: /* original 8b05, guest PC 0x0c09b67a */
if(!s->budget--) { s->failed_pc=0x0c09b67au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b688; }
goto P_0c09b67c;
P_0c09b67c: /* original 01ee, guest PC 0x0c09b67c */
if(!s->budget--) { s->failed_pc=0x0c09b67cu; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09b67e;
P_0c09b67e: /* original 71ff, guest PC 0x0c09b67e */
if(!s->budget--) { s->failed_pc=0x0c09b67eu; return 0; }
r[1]+=0xffffffffu;
goto P_0c09b680;
P_0c09b680: /* original 0e16, guest PC 0x0c09b680 */
if(!s->budget--) { s->failed_pc=0x0c09b680u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09b682;
P_0c09b682: /* original 7018, guest PC 0x0c09b682 */
if(!s->budget--) { s->failed_pc=0x0c09b682u; return 0; }
r[0]+=0x00000018u;
goto P_0c09b684;
P_0c09b684: /* original 1e93, guest PC 0x0c09b684 */
if(!s->budget--) { s->failed_pc=0x0c09b684u; return 0; }
write(ram,r[14]+12,r[9],4);
goto P_0c09b686;
P_0c09b686: /* original 0ed6, guest PC 0x0c09b686 */
if(!s->budget--) { s->failed_pc=0x0c09b686u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c09b688;
P_0c09b688: /* original 7f04, guest PC 0x0c09b688 */
if(!s->budget--) { s->failed_pc=0x0c09b688u; return 0; }
r[15]+=0x00000004u;
goto P_0c09b68a;
P_0c09b68a: /* original 4f26, guest PC 0x0c09b68a */
if(!s->budget--) { s->failed_pc=0x0c09b68au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09b68c;
P_0c09b68c: /* original 68f6, guest PC 0x0c09b68c */
if(!s->budget--) { s->failed_pc=0x0c09b68cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09b68e;
P_0c09b68e: /* original 69f6, guest PC 0x0c09b68e */
if(!s->budget--) { s->failed_pc=0x0c09b68eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09b690;
P_0c09b690: /* original 6af6, guest PC 0x0c09b690 */
if(!s->budget--) { s->failed_pc=0x0c09b690u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09b692;
P_0c09b692: /* original 6bf6, guest PC 0x0c09b692 */
if(!s->budget--) { s->failed_pc=0x0c09b692u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09b694;
P_0c09b694: /* original 6cf6, guest PC 0x0c09b694 */
if(!s->budget--) { s->failed_pc=0x0c09b694u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09b696;
P_0c09b696: /* original 6df6, guest PC 0x0c09b696 */
if(!s->budget--) { s->failed_pc=0x0c09b696u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09b698;
P_0c09b698: /* original 000b, guest PC 0x0c09b698 */
if(!s->budget--) { s->failed_pc=0x0c09b698u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09b69a: /* original 6ef6, guest PC 0x0c09b69a */
if(!s->budget--) { s->failed_pc=0x0c09b69au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09b69cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09b69cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
