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
int vf3_away_batch12_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04a330u: goto P_0c04a330;
case 0x0c04a332u: goto P_0c04a332;
case 0x0c04a334u: goto P_0c04a334;
case 0x0c04a336u: goto P_0c04a336;
case 0x0c04a338u: goto P_0c04a338;
case 0x0c04a33au: goto P_0c04a33a;
case 0x0c04a33cu: goto P_0c04a33c;
case 0x0c04a33eu: goto P_0c04a33e;
case 0x0c04a340u: goto P_0c04a340;
case 0x0c04a342u: goto P_0c04a342;
case 0x0c04a344u: goto P_0c04a344;
case 0x0c04a346u: goto P_0c04a346;
case 0x0c04a348u: goto P_0c04a348;
case 0x0c04a34au: goto P_0c04a34a;
case 0x0c04a34cu: goto P_0c04a34c;
case 0x0c04a34eu: goto P_0c04a34e;
case 0x0c04a350u: goto P_0c04a350;
case 0x0c04a352u: goto P_0c04a352;
case 0x0c04a354u: goto P_0c04a354;
case 0x0c04a356u: goto P_0c04a356;
case 0x0c04a358u: goto P_0c04a358;
case 0x0c04a35au: goto P_0c04a35a;
case 0x0c04a35cu: goto P_0c04a35c;
case 0x0c04a35eu: goto P_0c04a35e;
case 0x0c04a360u: goto P_0c04a360;
case 0x0c04a362u: goto P_0c04a362;
case 0x0c04a364u: goto P_0c04a364;
case 0x0c04a366u: goto P_0c04a366;
case 0x0c04a368u: goto P_0c04a368;
case 0x0c04a36au: goto P_0c04a36a;
case 0x0c04a36cu: goto P_0c04a36c;
case 0x0c04a36eu: goto P_0c04a36e;
case 0x0c04a370u: goto P_0c04a370;
case 0x0c04a372u: goto P_0c04a372;
case 0x0c04a374u: goto P_0c04a374;
case 0x0c04a376u: goto P_0c04a376;
case 0x0c04a378u: goto P_0c04a378;
case 0x0c04a37au: goto P_0c04a37a;
case 0x0c04a37cu: goto P_0c04a37c;
case 0x0c04a37eu: goto P_0c04a37e;
case 0x0c04a380u: goto P_0c04a380;
case 0x0c04a382u: goto P_0c04a382;
case 0x0c04a384u: goto P_0c04a384;
case 0x0c04a386u: goto P_0c04a386;
case 0x0c04a388u: goto P_0c04a388;
case 0x0c04a38au: goto P_0c04a38a;
case 0x0c04a38cu: goto P_0c04a38c;
case 0x0c04a38eu: goto P_0c04a38e;
case 0x0c04a390u: goto P_0c04a390;
case 0x0c04a392u: goto P_0c04a392;
case 0x0c04a394u: goto P_0c04a394;
case 0x0c04a396u: goto P_0c04a396;
case 0x0c04a398u: goto P_0c04a398;
case 0x0c04a39au: goto P_0c04a39a;
case 0x0c04a39cu: goto P_0c04a39c;
case 0x0c04a39eu: goto P_0c04a39e;
case 0x0c04a3a0u: goto P_0c04a3a0;
case 0x0c04a3a2u: goto P_0c04a3a2;
case 0x0c04a3a4u: goto P_0c04a3a4;
case 0x0c04a3a6u: goto P_0c04a3a6;
case 0x0c04a3a8u: goto P_0c04a3a8;
case 0x0c04a3aau: goto P_0c04a3aa;
case 0x0c04a3acu: goto P_0c04a3ac;
case 0x0c04a3aeu: goto P_0c04a3ae;
case 0x0c04a3b0u: goto P_0c04a3b0;
case 0x0c04a3b2u: goto P_0c04a3b2;
case 0x0c04a3b4u: goto P_0c04a3b4;
case 0x0c04a3b6u: goto P_0c04a3b6;
case 0x0c04a3b8u: goto P_0c04a3b8;
case 0x0c04a3bau: goto P_0c04a3ba;
case 0x0c04a3bcu: goto P_0c04a3bc;
case 0x0c04a3beu: goto P_0c04a3be;
case 0x0c04a3c0u: goto P_0c04a3c0;
case 0x0c04a3c2u: goto P_0c04a3c2;
case 0x0c04a3c4u: goto P_0c04a3c4;
case 0x0c04a3c6u: goto P_0c04a3c6;
case 0x0c04a3c8u: goto P_0c04a3c8;
case 0x0c04a3cau: goto P_0c04a3ca;
case 0x0c04a3ccu: goto P_0c04a3cc;
case 0x0c04a3ceu: goto P_0c04a3ce;
case 0x0c04a3d0u: goto P_0c04a3d0;
case 0x0c04a3d2u: goto P_0c04a3d2;
case 0x0c04a3d4u: goto P_0c04a3d4;
case 0x0c04a3d6u: goto P_0c04a3d6;
case 0x0c04a3d8u: goto P_0c04a3d8;
case 0x0c04a3dau: goto P_0c04a3da;
case 0x0c04a3dcu: goto P_0c04a3dc;
case 0x0c04a3deu: goto P_0c04a3de;
case 0x0c04a3e0u: goto P_0c04a3e0;
case 0x0c04a3e2u: goto P_0c04a3e2;
case 0x0c04a3e4u: goto P_0c04a3e4;
case 0x0c04a3e6u: goto P_0c04a3e6;
case 0x0c04a3e8u: goto P_0c04a3e8;
case 0x0c04a3eau: goto P_0c04a3ea;
case 0x0c04a3ecu: goto P_0c04a3ec;
case 0x0c04a3eeu: goto P_0c04a3ee;
case 0x0c04a3f0u: goto P_0c04a3f0;
case 0x0c04a3f2u: goto P_0c04a3f2;
case 0x0c04a3f4u: goto P_0c04a3f4;
case 0x0c04a3f6u: goto P_0c04a3f6;
case 0x0c04a3f8u: goto P_0c04a3f8;
case 0x0c04a3fau: goto P_0c04a3fa;
case 0x0c04a3fcu: goto P_0c04a3fc;
case 0x0c04a3feu: goto P_0c04a3fe;
case 0x0c04a400u: goto P_0c04a400;
case 0x0c04a402u: goto P_0c04a402;
case 0x0c04a404u: goto P_0c04a404;
case 0x0c04a406u: goto P_0c04a406;
case 0x0c04a408u: goto P_0c04a408;
case 0x0c04a40au: goto P_0c04a40a;
case 0x0c04a40cu: goto P_0c04a40c;
case 0x0c04a40eu: goto P_0c04a40e;
case 0x0c04a410u: goto P_0c04a410;
case 0x0c04a412u: goto P_0c04a412;
case 0x0c04a414u: goto P_0c04a414;
case 0x0c04a416u: goto P_0c04a416;
case 0x0c04a418u: goto P_0c04a418;
case 0x0c04a41au: goto P_0c04a41a;
case 0x0c04a41cu: goto P_0c04a41c;
case 0x0c04a41eu: goto P_0c04a41e;
case 0x0c04a420u: goto P_0c04a420;
case 0x0c04a422u: goto P_0c04a422;
case 0x0c04a424u: goto P_0c04a424;
case 0x0c04a426u: goto P_0c04a426;
case 0x0c04a428u: goto P_0c04a428;
case 0x0c04a42au: goto P_0c04a42a;
case 0x0c04a42cu: goto P_0c04a42c;
case 0x0c04a42eu: goto P_0c04a42e;
case 0x0c04a430u: goto P_0c04a430;
case 0x0c04a432u: goto P_0c04a432;
case 0x0c04a434u: goto P_0c04a434;
case 0x0c04a436u: goto P_0c04a436;
case 0x0c04a438u: goto P_0c04a438;
case 0x0c04a43au: goto P_0c04a43a;
case 0x0c04a43cu: goto P_0c04a43c;
case 0x0c04a43eu: goto P_0c04a43e;
case 0x0c04a440u: goto P_0c04a440;
case 0x0c04a442u: goto P_0c04a442;
case 0x0c04a444u: goto P_0c04a444;
case 0x0c04a446u: goto P_0c04a446;
case 0x0c04a448u: goto P_0c04a448;
case 0x0c04a4c4u: goto P_0c04a4c4;
case 0x0c04a4c6u: goto P_0c04a4c6;
case 0x0c04a4c8u: goto P_0c04a4c8;
case 0x0c04a4cau: goto P_0c04a4ca;
case 0x0c04a4ccu: goto P_0c04a4cc;
case 0x0c04a4ceu: goto P_0c04a4ce;
case 0x0c04a4d0u: goto P_0c04a4d0;
case 0x0c04a4d2u: goto P_0c04a4d2;
case 0x0c04a4d4u: goto P_0c04a4d4;
case 0x0c04a4d6u: goto P_0c04a4d6;
case 0x0c04a4d8u: goto P_0c04a4d8;
case 0x0c04a4dau: goto P_0c04a4da;
case 0x0c04a4dcu: goto P_0c04a4dc;
case 0x0c04a4deu: goto P_0c04a4de;
case 0x0c04a4e0u: goto P_0c04a4e0;
case 0x0c04a4e2u: goto P_0c04a4e2;
case 0x0c04a4e4u: goto P_0c04a4e4;
case 0x0c04a4e6u: goto P_0c04a4e6;
case 0x0c04a4e8u: goto P_0c04a4e8;
case 0x0c04a4eau: goto P_0c04a4ea;
case 0x0c04a4ecu: goto P_0c04a4ec;
case 0x0c04a4eeu: goto P_0c04a4ee;
case 0x0c04a4f0u: goto P_0c04a4f0;
case 0x0c04a4f2u: goto P_0c04a4f2;
case 0x0c04a4f4u: goto P_0c04a4f4;
case 0x0c04a4f6u: goto P_0c04a4f6;
case 0x0c04a4f8u: goto P_0c04a4f8;
case 0x0c04a4fau: goto P_0c04a4fa;
case 0x0c04a4fcu: goto P_0c04a4fc;
case 0x0c04a4feu: goto P_0c04a4fe;
case 0x0c04a500u: goto P_0c04a500;
case 0x0c04a502u: goto P_0c04a502;
case 0x0c04a504u: goto P_0c04a504;
case 0x0c04a506u: goto P_0c04a506;
case 0x0c04a508u: goto P_0c04a508;
case 0x0c04a50au: goto P_0c04a50a;
case 0x0c04a50cu: goto P_0c04a50c;
case 0x0c04a50eu: goto P_0c04a50e;
case 0x0c04a510u: goto P_0c04a510;
case 0x0c04a512u: goto P_0c04a512;
case 0x0c04a514u: goto P_0c04a514;
case 0x0c04a516u: goto P_0c04a516;
case 0x0c04a518u: goto P_0c04a518;
case 0x0c04a51au: goto P_0c04a51a;
case 0x0c04a51cu: goto P_0c04a51c;
case 0x0c04a51eu: goto P_0c04a51e;
case 0x0c04a520u: goto P_0c04a520;
case 0x0c04a522u: goto P_0c04a522;
case 0x0c04a524u: goto P_0c04a524;
case 0x0c04a526u: goto P_0c04a526;
case 0x0c04a528u: goto P_0c04a528;
case 0x0c04a52au: goto P_0c04a52a;
case 0x0c04a52cu: goto P_0c04a52c;
case 0x0c04a52eu: goto P_0c04a52e;
case 0x0c04a530u: goto P_0c04a530;
case 0x0c04a532u: goto P_0c04a532;
case 0x0c04a534u: goto P_0c04a534;
case 0x0c04a536u: goto P_0c04a536;
case 0x0c04a538u: goto P_0c04a538;
case 0x0c04a53au: goto P_0c04a53a;
case 0x0c04a53cu: goto P_0c04a53c;
case 0x0c04a53eu: goto P_0c04a53e;
case 0x0c04a540u: goto P_0c04a540;
case 0x0c04a542u: goto P_0c04a542;
case 0x0c04a544u: goto P_0c04a544;
case 0x0c04a546u: goto P_0c04a546;
case 0x0c04a548u: goto P_0c04a548;
case 0x0c04a54au: goto P_0c04a54a;
case 0x0c04a54cu: goto P_0c04a54c;
case 0x0c04a54eu: goto P_0c04a54e;
case 0x0c04a550u: goto P_0c04a550;
case 0x0c04a552u: goto P_0c04a552;
case 0x0c04a554u: goto P_0c04a554;
case 0x0c04a556u: goto P_0c04a556;
case 0x0c04a558u: goto P_0c04a558;
case 0x0c04a55au: goto P_0c04a55a;
case 0x0c04a55cu: goto P_0c04a55c;
case 0x0c04a55eu: goto P_0c04a55e;
case 0x0c04a560u: goto P_0c04a560;
case 0x0c04a562u: goto P_0c04a562;
case 0x0c04a564u: goto P_0c04a564;
case 0x0c04a566u: goto P_0c04a566;
case 0x0c04a568u: goto P_0c04a568;
case 0x0c04a56au: goto P_0c04a56a;
case 0x0c04a56cu: goto P_0c04a56c;
case 0x0c04a56eu: goto P_0c04a56e;
case 0x0c04a570u: goto P_0c04a570;
case 0x0c04a572u: goto P_0c04a572;
case 0x0c04a574u: goto P_0c04a574;
case 0x0c04a576u: goto P_0c04a576;
case 0x0c04a578u: goto P_0c04a578;
case 0x0c04a57au: goto P_0c04a57a;
case 0x0c04a57cu: goto P_0c04a57c;
case 0x0c04a57eu: goto P_0c04a57e;
case 0x0c04a580u: goto P_0c04a580;
case 0x0c04a582u: goto P_0c04a582;
case 0x0c04a584u: goto P_0c04a584;
case 0x0c04a586u: goto P_0c04a586;
case 0x0c04a588u: goto P_0c04a588;
case 0x0c04a58au: goto P_0c04a58a;
case 0x0c04a58cu: goto P_0c04a58c;
case 0x0c04a58eu: goto P_0c04a58e;
case 0x0c04a590u: goto P_0c04a590;
case 0x0c04a592u: goto P_0c04a592;
case 0x0c04a594u: goto P_0c04a594;
case 0x0c04a596u: goto P_0c04a596;
case 0x0c04a598u: goto P_0c04a598;
case 0x0c04a59au: goto P_0c04a59a;
case 0x0c04a59cu: goto P_0c04a59c;
case 0x0c04a59eu: goto P_0c04a59e;
case 0x0c04a5a0u: goto P_0c04a5a0;
case 0x0c04a5a2u: goto P_0c04a5a2;
case 0x0c06c5c8u: goto P_0c06c5c8;
case 0x0c06c5cau: goto P_0c06c5ca;
case 0x0c06c5ccu: goto P_0c06c5cc;
case 0x0c06c5ceu: goto P_0c06c5ce;
case 0x0c06c5d0u: goto P_0c06c5d0;
case 0x0c06c5d2u: goto P_0c06c5d2;
case 0x0c06c5d4u: goto P_0c06c5d4;
case 0x0c06c5d6u: goto P_0c06c5d6;
case 0x0c06c5d8u: goto P_0c06c5d8;
case 0x0c06c5dau: goto P_0c06c5da;
case 0x0c06c5dcu: goto P_0c06c5dc;
case 0x0c06c5deu: goto P_0c06c5de;
case 0x0c06c5e0u: goto P_0c06c5e0;
case 0x0c06c5e2u: goto P_0c06c5e2;
case 0x0c06c5e4u: goto P_0c06c5e4;
case 0x0c06c5e6u: goto P_0c06c5e6;
case 0x0c06c5e8u: goto P_0c06c5e8;
case 0x0c06c5eau: goto P_0c06c5ea;
case 0x0c06c5ecu: goto P_0c06c5ec;
case 0x0c06c5eeu: goto P_0c06c5ee;
case 0x0c06c5f0u: goto P_0c06c5f0;
case 0x0c06c5f2u: goto P_0c06c5f2;
case 0x0c06c5f4u: goto P_0c06c5f4;
case 0x0c06c5f6u: goto P_0c06c5f6;
case 0x0c06c5f8u: goto P_0c06c5f8;
case 0x0c06c5fau: goto P_0c06c5fa;
case 0x0c06c5fcu: goto P_0c06c5fc;
case 0x0c06c5feu: goto P_0c06c5fe;
case 0x0c06c600u: goto P_0c06c600;
case 0x0c06c602u: goto P_0c06c602;
case 0x0c06c604u: goto P_0c06c604;
case 0x0c06c606u: goto P_0c06c606;
case 0x0c06c608u: goto P_0c06c608;
case 0x0c06c60au: goto P_0c06c60a;
case 0x0c06c60cu: goto P_0c06c60c;
case 0x0c06c60eu: goto P_0c06c60e;
case 0x0c06c610u: goto P_0c06c610;
case 0x0c06c612u: goto P_0c06c612;
case 0x0c06c614u: goto P_0c06c614;
case 0x0c06c616u: goto P_0c06c616;
case 0x0c06c618u: goto P_0c06c618;
case 0x0c06c61au: goto P_0c06c61a;
case 0x0c06c61cu: goto P_0c06c61c;
case 0x0c06c61eu: goto P_0c06c61e;
case 0x0c06c620u: goto P_0c06c620;
case 0x0c06c622u: goto P_0c06c622;
case 0x0c06c624u: goto P_0c06c624;
case 0x0c06c626u: goto P_0c06c626;
case 0x0c06c628u: goto P_0c06c628;
case 0x0c06c62au: goto P_0c06c62a;
case 0x0c06c62cu: goto P_0c06c62c;
case 0x0c06c62eu: goto P_0c06c62e;
case 0x0c06c630u: goto P_0c06c630;
case 0x0c06c632u: goto P_0c06c632;
case 0x0c06c634u: goto P_0c06c634;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04a330: /* original 6e43, guest PC 0x0c04a330 */
if(!s->budget--) { s->failed_pc=0x0c04a330u; return 0; }
r[14]=r[4];
goto P_0c04a332;
P_0c04a332: /* original 6042, guest PC 0x0c04a332 */
if(!s->budget--) { s->failed_pc=0x0c04a332u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c04a334;
P_0c04a334: /* original 7420, guest PC 0x0c04a334 */
if(!s->budget--) { s->failed_pc=0x0c04a334u; return 0; }
r[4]+=0x00000020u;
goto P_0c04a336;
P_0c04a336: /* original f18d, guest PC 0x0c04a336 */
if(!s->budget--) { s->failed_pc=0x0c04a336u; return 0; }
fr[1]=0;
goto P_0c04a338;
P_0c04a338: /* original c801, guest PC 0x0c04a338 */
if(!s->budget--) { s->failed_pc=0x0c04a338u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c04a33a;
P_0c04a33a: /* original 0483, guest PC 0x0c04a33a */
if(!s->budget--) { s->failed_pc=0x0c04a33au; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c04a33c;
P_0c04a33c: /* original 8b02, guest PC 0x0c04a33c */
if(!s->budget--) { s->failed_pc=0x0c04a33cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04a344; }
goto P_0c04a33e;
P_0c04a33e: /* original 5ee1, guest PC 0x0c04a33e */
if(!s->budget--) { s->failed_pc=0x0c04a33eu; return 0; }
r[14]=read(ram,r[14]+4,4);
goto P_0c04a340;
P_0c04a340: /* original 74e8, guest PC 0x0c04a340 */
if(!s->budget--) { s->failed_pc=0x0c04a340u; return 0; }
r[4]+=0xffffffe8u;
goto P_0c04a342;
P_0c04a342: /* original 3e4c, guest PC 0x0c04a342 */
if(!s->budget--) { s->failed_pc=0x0c04a342u; return 0; }
r[14]+=r[4];
goto P_0c04a344;
P_0c04a344: /* original f4e9, guest PC 0x0c04a344 */
if(!s->budget--) { s->failed_pc=0x0c04a344u; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c04a346;
P_0c04a346: /* original f6e9, guest PC 0x0c04a346 */
if(!s->budget--) { s->failed_pc=0x0c04a346u; return 0; }
vf3_matrix_load(s,ram,6,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c04a348;
P_0c04a348: /* original f72d, guest PC 0x0c04a348 */
if(!s->budget--) { s->failed_pc=0x0c04a348u; return 0; }
fr[7]=vf3_fpu_float(r[53],r[18]);
goto P_0c04a34a;
P_0c04a34a: /* original 6e43, guest PC 0x0c04a34a */
if(!s->budget--) { s->failed_pc=0x0c04a34au; return 0; }
r[14]=r[4];
goto P_0c04a34c;
P_0c04a34c: /* original 6042, guest PC 0x0c04a34c */
if(!s->budget--) { s->failed_pc=0x0c04a34cu; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c04a34e;
P_0c04a34e: /* original 7420, guest PC 0x0c04a34e */
if(!s->budget--) { s->failed_pc=0x0c04a34eu; return 0; }
r[4]+=0x00000020u;
goto P_0c04a350;
P_0c04a350: /* original f5fd, guest PC 0x0c04a350 */
if(!s->budget--) { s->failed_pc=0x0c04a350u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c04a352;
P_0c04a352: /* original c801, guest PC 0x0c04a352 */
if(!s->budget--) { s->failed_pc=0x0c04a352u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c04a354;
P_0c04a354: /* original 0483, guest PC 0x0c04a354 */
if(!s->budget--) { s->failed_pc=0x0c04a354u; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c04a356;
P_0c04a356: /* original 8b02, guest PC 0x0c04a356 */
if(!s->budget--) { s->failed_pc=0x0c04a356u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04a35e; }
goto P_0c04a358;
P_0c04a358: /* original 5ee1, guest PC 0x0c04a358 */
if(!s->budget--) { s->failed_pc=0x0c04a358u; return 0; }
r[14]=read(ram,r[14]+4,4);
goto P_0c04a35a;
P_0c04a35a: /* original 74e8, guest PC 0x0c04a35a */
if(!s->budget--) { s->failed_pc=0x0c04a35au; return 0; }
r[4]+=0xffffffe8u;
goto P_0c04a35c;
P_0c04a35c: /* original 3e4c, guest PC 0x0c04a35c */
if(!s->budget--) { s->failed_pc=0x0c04a35cu; return 0; }
r[14]+=r[4];
goto P_0c04a35e;
P_0c04a35e: /* original f8e9, guest PC 0x0c04a35e */
if(!s->budget--) { s->failed_pc=0x0c04a35eu; return 0; }
vf3_matrix_load(s,ram,8,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c04a360;
P_0c04a360: /* original f170, guest PC 0x0c04a360 */
if(!s->budget--) { s->failed_pc=0x0c04a360u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[7],r[18],'+');
goto P_0c04a362;
P_0c04a362: /* original f79d, guest PC 0x0c04a362 */
if(!s->budget--) { s->failed_pc=0x0c04a362u; return 0; }
fr[7]=0x3f800000u;
goto P_0c04a364;
P_0c04a364: /* original f743, guest PC 0x0c04a364 */
if(!s->budget--) { s->failed_pc=0x0c04a364u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'/');
goto P_0c04a366;
P_0c04a366: /* original fae9, guest PC 0x0c04a366 */
if(!s->budget--) { s->failed_pc=0x0c04a366u; return 0; }
vf3_matrix_load(s,ram,10,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c04a368;
P_0c04a368: /* original fb2d, guest PC 0x0c04a368 */
if(!s->budget--) { s->failed_pc=0x0c04a368u; return 0; }
fr[11]=vf3_fpu_float(r[53],r[18]);
goto P_0c04a36a;
P_0c04a36a: /* original f48d, guest PC 0x0c04a36a */
if(!s->budget--) { s->failed_pc=0x0c04a36au; return 0; }
fr[4]=0;
goto P_0c04a36c;
P_0c04a36c: /* original f410, guest PC 0x0c04a36c */
if(!s->budget--) { s->failed_pc=0x0c04a36cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'+');
goto P_0c04a36e;
P_0c04a36e: /* original 6e43, guest PC 0x0c04a36e */
if(!s->budget--) { s->failed_pc=0x0c04a36eu; return 0; }
r[14]=r[4];
goto P_0c04a370;
P_0c04a370: /* original 6042, guest PC 0x0c04a370 */
if(!s->budget--) { s->failed_pc=0x0c04a370u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c04a372;
P_0c04a372: /* original 7420, guest PC 0x0c04a372 */
if(!s->budget--) { s->failed_pc=0x0c04a372u; return 0; }
r[4]+=0x00000020u;
goto P_0c04a374;
P_0c04a374: /* original f9fd, guest PC 0x0c04a374 */
if(!s->budget--) { s->failed_pc=0x0c04a374u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+8,r[18],fr+8)) goto unsupported;
goto P_0c04a376;
P_0c04a376: /* original f18d, guest PC 0x0c04a376 */
if(!s->budget--) { s->failed_pc=0x0c04a376u; return 0; }
fr[1]=0;
goto P_0c04a378;
P_0c04a378: /* original c801, guest PC 0x0c04a378 */
if(!s->budget--) { s->failed_pc=0x0c04a378u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c04a37a;
P_0c04a37a: /* original 0483, guest PC 0x0c04a37a */
if(!s->budget--) { s->failed_pc=0x0c04a37au; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c04a37c;
P_0c04a37c: /* original 8b02, guest PC 0x0c04a37c */
if(!s->budget--) { s->failed_pc=0x0c04a37cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04a384; }
goto P_0c04a37e;
P_0c04a37e: /* original 5ee1, guest PC 0x0c04a37e */
if(!s->budget--) { s->failed_pc=0x0c04a37eu; return 0; }
r[14]=read(ram,r[14]+4,4);
goto P_0c04a380;
P_0c04a380: /* original 74e8, guest PC 0x0c04a380 */
if(!s->budget--) { s->failed_pc=0x0c04a380u; return 0; }
r[4]+=0xffffffe8u;
goto P_0c04a382;
P_0c04a382: /* original 3e4c, guest PC 0x0c04a382 */
if(!s->budget--) { s->failed_pc=0x0c04a382u; return 0; }
r[14]+=r[4];
goto P_0c04a384;
P_0c04a384: /* original f1b0, guest PC 0x0c04a384 */
if(!s->budget--) { s->failed_pc=0x0c04a384u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[11],r[18],'+');
goto P_0c04a386;
P_0c04a386: /* original fb9d, guest PC 0x0c04a386 */
if(!s->budget--) { s->failed_pc=0x0c04a386u; return 0; }
fr[11]=0x3f800000u;
goto P_0c04a388;
P_0c04a388: /* original fb83, guest PC 0x0c04a388 */
if(!s->budget--) { s->failed_pc=0x0c04a388u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[8],r[18],'/');
goto P_0c04a38a;
P_0c04a38a: /* original fce9, guest PC 0x0c04a38a */
if(!s->budget--) { s->failed_pc=0x0c04a38au; return 0; }
vf3_matrix_load(s,ram,12,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c04a38c;
P_0c04a38c: /* original fee9, guest PC 0x0c04a38c */
if(!s->budget--) { s->failed_pc=0x0c04a38cu; return 0; }
vf3_matrix_load(s,ram,14,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c04a38e;
P_0c04a38e: /* original ff2d, guest PC 0x0c04a38e */
if(!s->budget--) { s->failed_pc=0x0c04a38eu; return 0; }
fr[15]=vf3_fpu_float(r[53],r[18]);
goto P_0c04a390;
P_0c04a390: /* original f88d, guest PC 0x0c04a390 */
if(!s->budget--) { s->failed_pc=0x0c04a390u; return 0; }
fr[8]=0;
goto P_0c04a392;
P_0c04a392: /* original f810, guest PC 0x0c04a392 */
if(!s->budget--) { s->failed_pc=0x0c04a392u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[1],r[18],'+');
goto P_0c04a394;
P_0c04a394: /* original fdfd, guest PC 0x0c04a394 */
if(!s->budget--) { s->failed_pc=0x0c04a394u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+12,r[18],fr+12)) goto unsupported;
goto P_0c04a396;
P_0c04a396: /* original f18d, guest PC 0x0c04a396 */
if(!s->budget--) { s->failed_pc=0x0c04a396u; return 0; }
fr[1]=0;
goto P_0c04a398;
P_0c04a398: /* original f1f0, guest PC 0x0c04a398 */
if(!s->budget--) { s->failed_pc=0x0c04a398u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[15],r[18],'+');
goto P_0c04a39a;
P_0c04a39a: /* original ff9d, guest PC 0x0c04a39a */
if(!s->budget--) { s->failed_pc=0x0c04a39au; return 0; }
fr[15]=0x3f800000u;
goto P_0c04a39c;
P_0c04a39c: /* original ffc3, guest PC 0x0c04a39c */
if(!s->budget--) { s->failed_pc=0x0c04a39cu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[12],r[18],'/');
goto P_0c04a39e;
P_0c04a39e: /* original fc8d, guest PC 0x0c04a39e */
if(!s->budget--) { s->failed_pc=0x0c04a39eu; return 0; }
fr[12]=0;
goto P_0c04a3a0;
P_0c04a3a0: /* original fc10, guest PC 0x0c04a3a0 */
if(!s->budget--) { s->failed_pc=0x0c04a3a0u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[1],r[18],'+');
goto P_0c04a3a2;
P_0c04a3a2: /* original e000, guest PC 0x0c04a3a2 */
if(!s->budget--) { s->failed_pc=0x0c04a3a2u; return 0; }
r[0]=0x00000000u;
goto P_0c04a3a4;
P_0c04a3a4: /* original f425, guest PC 0x0c04a3a4 */
if(!s->budget--) { s->failed_pc=0x0c04a3a4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c04a3a6;
P_0c04a3a6: /* original 4024, guest PC 0x0c04a3a6 */
if(!s->budget--) { s->failed_pc=0x0c04a3a6u; return 0; }
tmp=r[0]>>31; r[0]=(r[0]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c04a3a8;
P_0c04a3a8: /* original f825, guest PC 0x0c04a3a8 */
if(!s->budget--) { s->failed_pc=0x0c04a3a8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[2]))!=0);
goto P_0c04a3aa;
P_0c04a3aa: /* original 4024, guest PC 0x0c04a3aa */
if(!s->budget--) { s->failed_pc=0x0c04a3aau; return 0; }
tmp=r[0]>>31; r[0]=(r[0]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c04a3ac;
P_0c04a3ac: /* original fc25, guest PC 0x0c04a3ac */
if(!s->budget--) { s->failed_pc=0x0c04a3acu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[12])>as_float(fr[2]))!=0);
goto P_0c04a3ae;
P_0c04a3ae: /* original 4024, guest PC 0x0c04a3ae */
if(!s->budget--) { s->failed_pc=0x0c04a3aeu; return 0; }
tmp=r[0]>>31; r[0]=(r[0]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c04a3b0;
P_0c04a3b0: /* original c807, guest PC 0x0c04a3b0 */
if(!s->budget--) { s->failed_pc=0x0c04a3b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&7u)==0)!=0);
goto P_0c04a3b2;
P_0c04a3b2: /* original 8b41, guest PC 0x0c04a3b2 */
if(!s->budget--) { s->failed_pc=0x0c04a3b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04a438; }
goto P_0c04a3b4;
P_0c04a3b4: /* original fb1d, guest PC 0x0c04a3b4 */
if(!s->budget--) { s->failed_pc=0x0c04a3b4u; return 0; }
r[53]=fr[11];
goto P_0c04a3b6;
P_0c04a3b6: /* original e018, guest PC 0x0c04a3b6 */
if(!s->budget--) { s->failed_pc=0x0c04a3b6u; return 0; }
r[0]=0x00000018u;
goto P_0c04a3b8;
P_0c04a3b8: /* original 7610, guest PC 0x0c04a3b8 */
if(!s->budget--) { s->failed_pc=0x0c04a3b8u; return 0; }
r[6]+=0x00000010u;
goto P_0c04a3ba;
P_0c04a3ba: /* original f672, guest PC 0x0c04a3ba */
if(!s->budget--) { s->failed_pc=0x0c04a3bau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c04a3bc;
P_0c04a3bc: /* original f572, guest PC 0x0c04a3bc */
if(!s->budget--) { s->failed_pc=0x0c04a3bcu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c04a3be;
P_0c04a3be: /* original 015a, guest PC 0x0c04a3be */
if(!s->budget--) { s->failed_pc=0x0c04a3beu; return 0; }
r[1]=r[53];
goto P_0c04a3c0;
P_0c04a3c0: /* original f66b, guest PC 0x0c04a3c0 */
if(!s->budget--) { s->failed_pc=0x0c04a3c0u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c04a3c2;
P_0c04a3c2: /* original fef2, guest PC 0x0c04a3c2 */
if(!s->budget--) { s->failed_pc=0x0c04a3c2u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'*');
goto P_0c04a3c4;
P_0c04a3c4: /* original f64b, guest PC 0x0c04a3c4 */
if(!s->budget--) { s->failed_pc=0x0c04a3c4u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c04a3c6;
P_0c04a3c6: /* original fdf2, guest PC 0x0c04a3c6 */
if(!s->budget--) { s->failed_pc=0x0c04a3c6u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[15],r[18],'*');
goto P_0c04a3c8;
P_0c04a3c8: /* original f6c7, guest PC 0x0c04a3c8 */
if(!s->budget--) { s->failed_pc=0x0c04a3c8u; return 0; }
vf3_matrix_store(s,ram,12,r[6]+r[0]);
goto P_0c04a3ca;
P_0c04a3ca: /* original fab2, guest PC 0x0c04a3ca */
if(!s->budget--) { s->failed_pc=0x0c04a3cau; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[11],r[18],'*');
goto P_0c04a3cc;
P_0c04a3cc: /* original e020, guest PC 0x0c04a3cc */
if(!s->budget--) { s->failed_pc=0x0c04a3ccu; return 0; }
r[0]=0x00000020u;
goto P_0c04a3ce;
P_0c04a3ce: /* original f9b2, guest PC 0x0c04a3ce */
if(!s->budget--) { s->failed_pc=0x0c04a3ceu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[11],r[18],'*');
goto P_0c04a3d0;
P_0c04a3d0: /* original f6e7, guest PC 0x0c04a3d0 */
if(!s->budget--) { s->failed_pc=0x0c04a3d0u; return 0; }
vf3_matrix_store(s,ram,14,r[6]+r[0]);
goto P_0c04a3d2;
P_0c04a3d2: /* original e0ff, guest PC 0x0c04a3d2 */
if(!s->budget--) { s->failed_pc=0x0c04a3d2u; return 0; }
r[0]=0xffffffffu;
goto P_0c04a3d4;
P_0c04a3d4: /* original 1616, guest PC 0x0c04a3d4 */
if(!s->budget--) { s->failed_pc=0x0c04a3d4u; return 0; }
write(ram,r[6]+24,r[1],4);
goto P_0c04a3d6;
P_0c04a3d6: /* original f3fd, guest PC 0x0c04a3d6 */
if(!s->budget--) { s->failed_pc=0x0c04a3d6u; return 0; }
r[18]^=0x100000u;
goto P_0c04a3d8;
P_0c04a3d8: /* original 2602, guest PC 0x0c04a3d8 */
if(!s->budget--) { s->failed_pc=0x0c04a3d8u; return 0; }
write(ram,r[6],r[0],4);
goto P_0c04a3da;
P_0c04a3da: /* original e010, guest PC 0x0c04a3da */
if(!s->budget--) { s->failed_pc=0x0c04a3dau; return 0; }
r[0]=0x00000010u;
goto P_0c04a3dc;
P_0c04a3dc: /* original f697, guest PC 0x0c04a3dc */
if(!s->budget--) { s->failed_pc=0x0c04a3dcu; return 0; }
vf3_matrix_store(s,ram,9,r[6]+r[0]);
goto P_0c04a3de;
P_0c04a3de: /* original e014, guest PC 0x0c04a3de */
if(!s->budget--) { s->failed_pc=0x0c04a3deu; return 0; }
r[0]=0x00000014u;
goto P_0c04a3e0;
P_0c04a3e0: /* original f6a7, guest PC 0x0c04a3e0 */
if(!s->budget--) { s->failed_pc=0x0c04a3e0u; return 0; }
vf3_matrix_store(s,ram,10,r[6]+r[0]);
goto P_0c04a3e2;
P_0c04a3e2: /* original 7540, guest PC 0x0c04a3e2 */
if(!s->budget--) { s->failed_pc=0x0c04a3e2u; return 0; }
r[5]+=0x00000040u;
goto P_0c04a3e4;
P_0c04a3e4: /* original 0683, guest PC 0x0c04a3e4 */
if(!s->budget--) { s->failed_pc=0x0c04a3e4u; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a3e6;
P_0c04a3e6: /* original 7620, guest PC 0x0c04a3e6 */
if(!s->budget--) { s->failed_pc=0x0c04a3e6u; return 0; }
r[6]+=0x00000020u;
goto P_0c04a3e8;
P_0c04a3e8: /* original eb01, guest PC 0x0c04a3e8 */
if(!s->budget--) { s->failed_pc=0x0c04a3e8u; return 0; }
r[11]=0x00000001u;
goto P_0c04a3ea;
P_0c04a3ea: /* original f3fd, guest PC 0x0c04a3ea */
if(!s->budget--) { s->failed_pc=0x0c04a3eau; return 0; }
r[18]^=0x100000u;
goto P_0c04a3ec;
P_0c04a3ec: /* original 4b5a, guest PC 0x0c04a3ec */
if(!s->budget--) { s->failed_pc=0x0c04a3ecu; return 0; }
r[53]=r[11];
goto P_0c04a3ee;
P_0c04a3ee: /* original 0683, guest PC 0x0c04a3ee */
if(!s->budget--) { s->failed_pc=0x0c04a3eeu; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a3f0;
P_0c04a3f0: /* original 7620, guest PC 0x0c04a3f0 */
if(!s->budget--) { s->failed_pc=0x0c04a3f0u; return 0; }
r[6]+=0x00000020u;
goto P_0c04a3f2;
P_0c04a3f2: /* original 4310, guest PC 0x0c04a3f2 */
if(!s->budget--) { s->failed_pc=0x0c04a3f2u; return 0; }
--r[3];
r[17]=(r[17]&~1u)|((r[3]==0)!=0);
goto P_0c04a3f4;
P_0c04a3f4: /* original 6042, guest PC 0x0c04a3f4 */
if(!s->budget--) { s->failed_pc=0x0c04a3f4u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c04a3f6;
P_0c04a3f6: /* original 8b9b, guest PC 0x0c04a3f6 */
if(!s->budget--) { s->failed_pc=0x0c04a3f6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04a330; }
goto P_0c04a3f8;
P_0c04a3f8: /* original 4015, guest PC 0x0c04a3f8 */
if(!s->budget--) { s->failed_pc=0x0c04a3f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c04a3fa;
P_0c04a3fa: /* original 8b04, guest PC 0x0c04a3fa */
if(!s->budget--) { s->failed_pc=0x0c04a3fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04a406; }
goto P_0c04a3fc;
P_0c04a3fc: /* original c880, guest PC 0x0c04a3fc */
if(!s->budget--) { s->failed_pc=0x0c04a3fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c04a3fe;
P_0c04a3fe: /* original 7404, guest PC 0x0c04a3fe */
if(!s->budget--) { s->failed_pc=0x0c04a3feu; return 0; }
r[4]+=0x00000004u;
goto P_0c04a400;
P_0c04a400: /* original 8f96, guest PC 0x0c04a400 */
if(!s->budget--) { s->failed_pc=0x0c04a400u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[4],4);
r[4]+=4;
r[3]=tmp;
if(!cond) { goto P_0c04a330; }
goto P_0c04a404;
P_0c04a402: /* original 6346, guest PC 0x0c04a402 */
if(!s->budget--) { s->failed_pc=0x0c04a402u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[3]=tmp;
goto P_0c04a404;
P_0c04a404: /* original 74f8, guest PC 0x0c04a404 */
if(!s->budget--) { s->failed_pc=0x0c04a404u; return 0; }
r[4]+=0xfffffff8u;
goto P_0c04a406;
P_0c04a406: /* original 2bb8, guest PC 0x0c04a406 */
if(!s->budget--) { s->failed_pc=0x0c04a406u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c04a408;
P_0c04a408: /* original f3fd, guest PC 0x0c04a408 */
if(!s->budget--) { s->failed_pc=0x0c04a408u; return 0; }
r[18]^=0x100000u;
goto P_0c04a40a;
P_0c04a40a: /* original 8912, guest PC 0x0c04a40a */
if(!s->budget--) { s->failed_pc=0x0c04a40au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04a432; }
goto P_0c04a40c;
P_0c04a40c: /* original 0683, guest PC 0x0c04a40c */
if(!s->budget--) { s->failed_pc=0x0c04a40cu; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a40e;
P_0c04a40e: /* original 7620, guest PC 0x0c04a40e */
if(!s->budget--) { s->failed_pc=0x0c04a40eu; return 0; }
r[6]+=0x00000020u;
goto P_0c04a410;
P_0c04a410: /* original 50f5, guest PC 0x0c04a410 */
if(!s->budget--) { s->failed_pc=0x0c04a410u; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c04a412;
P_0c04a412: /* original 7540, guest PC 0x0c04a412 */
if(!s->budget--) { s->failed_pc=0x0c04a412u; return 0; }
r[5]+=0x00000040u;
goto P_0c04a414;
P_0c04a414: /* original 51f6, guest PC 0x0c04a414 */
if(!s->budget--) { s->failed_pc=0x0c04a414u; return 0; }
r[1]=read(ram,r[15]+24,4);
goto P_0c04a416;
P_0c04a416: /* original 52f7, guest PC 0x0c04a416 */
if(!s->budget--) { s->failed_pc=0x0c04a416u; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c04a418;
P_0c04a418: /* original 0683, guest PC 0x0c04a418 */
if(!s->budget--) { s->failed_pc=0x0c04a418u; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a41a;
P_0c04a41a: /* original 76a0, guest PC 0x0c04a41a */
if(!s->budget--) { s->failed_pc=0x0c04a41au; return 0; }
r[6]+=0xffffffa0u;
goto P_0c04a41c;
P_0c04a41c: /* original 2602, guest PC 0x0c04a41c */
if(!s->budget--) { s->failed_pc=0x0c04a41cu; return 0; }
write(ram,r[6],r[0],4);
goto P_0c04a41e;
P_0c04a41e: /* original cb40, guest PC 0x0c04a41e */
if(!s->budget--) { s->failed_pc=0x0c04a41eu; return 0; }
r[0]|=64u;
goto P_0c04a420;
P_0c04a420: /* original 1611, guest PC 0x0c04a420 */
if(!s->budget--) { s->failed_pc=0x0c04a420u; return 0; }
write(ram,r[6]+4,r[1],4);
goto P_0c04a422;
P_0c04a422: /* original 221b, guest PC 0x0c04a422 */
if(!s->budget--) { s->failed_pc=0x0c04a422u; return 0; }
r[2]|=r[1];
goto P_0c04a424;
P_0c04a424: /* original 0683, guest PC 0x0c04a424 */
if(!s->budget--) { s->failed_pc=0x0c04a424u; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a426;
P_0c04a426: /* original 7620, guest PC 0x0c04a426 */
if(!s->budget--) { s->failed_pc=0x0c04a426u; return 0; }
r[6]+=0x00000020u;
goto P_0c04a428;
P_0c04a428: /* original 2602, guest PC 0x0c04a428 */
if(!s->budget--) { s->failed_pc=0x0c04a428u; return 0; }
write(ram,r[6],r[0],4);
goto P_0c04a42a;
P_0c04a42a: /* original 1621, guest PC 0x0c04a42a */
if(!s->budget--) { s->failed_pc=0x0c04a42au; return 0; }
write(ram,r[6]+4,r[2],4);
goto P_0c04a42c;
P_0c04a42c: /* original 0683, guest PC 0x0c04a42c */
if(!s->budget--) { s->failed_pc=0x0c04a42cu; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a42e;
P_0c04a42e: /* original 000b, guest PC 0x0c04a42e */
if(!s->budget--) { s->failed_pc=0x0c04a42eu; return 0; }
target=r[16];
r[6]+=0x00000060u;
s->pc=target; return ram->oob==0;
P_0c04a430: /* original 7660, guest PC 0x0c04a430 */
if(!s->budget--) { s->failed_pc=0x0c04a430u; return 0; }
r[6]+=0x00000060u;
goto P_0c04a432;
P_0c04a432: /* original 76e0, guest PC 0x0c04a432 */
if(!s->budget--) { s->failed_pc=0x0c04a432u; return 0; }
r[6]+=0xffffffe0u;
goto P_0c04a434;
P_0c04a434: /* original 000b, guest PC 0x0c04a434 */
if(!s->budget--) { s->failed_pc=0x0c04a434u; return 0; }
target=r[16];
r[5]+=0xffffffe0u;
s->pc=target; return ram->oob==0;
P_0c04a436: /* original 75e0, guest PC 0x0c04a436 */
if(!s->budget--) { s->failed_pc=0x0c04a436u; return 0; }
r[5]+=0xffffffe0u;
goto P_0c04a438;
P_0c04a438: /* original 8807, guest PC 0x0c04a438 */
if(!s->budget--) { s->failed_pc=0x0c04a438u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c04a43a;
P_0c04a43a: /* original 70fe, guest PC 0x0c04a43a */
if(!s->budget--) { s->failed_pc=0x0c04a43au; return 0; }
r[0]+=0xfffffffeu;
goto P_0c04a43c;
P_0c04a43c: /* original 89d9, guest PC 0x0c04a43c */
if(!s->budget--) { s->failed_pc=0x0c04a43cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04a3f2; }
goto P_0c04a43e;
P_0c04a43e: /* original 4008, guest PC 0x0c04a43e */
if(!s->budget--) { s->failed_pc=0x0c04a43eu; return 0; }
r[0]<<=2;
goto P_0c04a440;
P_0c04a440: /* original 88fc, guest PC 0x0c04a440 */
if(!s->budget--) { s->failed_pc=0x0c04a440u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffcu)!=0);
goto P_0c04a442;
P_0c04a442: /* original 4008, guest PC 0x0c04a442 */
if(!s->budget--) { s->failed_pc=0x0c04a442u; return 0; }
r[0]<<=2;
goto P_0c04a444;
P_0c04a444: /* original 8955, guest PC 0x0c04a444 */
if(!s->budget--) { s->failed_pc=0x0c04a444u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04a4f2; }
goto P_0c04a446;
P_0c04a446: /* original 0023, guest PC 0x0c04a446 */
if(!s->budget--) { s->failed_pc=0x0c04a446u; return 0; }
target=r[0]+0x0c04a44au;
vf3_matrix_move(s,2,6);
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
P_0c04a448: /* original f26c, guest PC 0x0c04a448 */
if(!s->budget--) { s->failed_pc=0x0c04a448u; return 0; }
vf3_matrix_move(s,2,6);
if(!vf3_matrix_family(0x0c04a44au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04a44au; return 0; } return 1;
P_0c04a4c4: /* original f60b, guest PC 0x0c04a4c4 */
if(!s->budget--) { s->failed_pc=0x0c04a4c4u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c04a4c6;
P_0c04a4c6: /* original f3fd, guest PC 0x0c04a4c6 */
if(!s->budget--) { s->failed_pc=0x0c04a4c6u; return 0; }
r[18]^=0x100000u;
goto P_0c04a4c8;
P_0c04a4c8: /* original f0ec, guest PC 0x0c04a4c8 */
if(!s->budget--) { s->failed_pc=0x0c04a4c8u; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c04a4ca;
P_0c04a4ca: /* original fcae, guest PC 0x0c04a4ca */
if(!s->budget--) { s->failed_pc=0x0c04a4cau; return 0; }
fr[12]=vf3_fpu_mac(fr[0],fr[10],fr[12],r[18]);
goto P_0c04a4cc;
P_0c04a4cc: /* original 2602, guest PC 0x0c04a4cc */
if(!s->budget--) { s->failed_pc=0x0c04a4ccu; return 0; }
write(ram,r[6],r[0],4);
goto P_0c04a4ce;
P_0c04a4ce: /* original ff9e, guest PC 0x0c04a4ce */
if(!s->budget--) { s->failed_pc=0x0c04a4ceu; return 0; }
fr[15]=vf3_fpu_mac(fr[0],fr[9],fr[15],r[18]);
goto P_0c04a4d0;
P_0c04a4d0: /* original 761c, guest PC 0x0c04a4d0 */
if(!s->budget--) { s->failed_pc=0x0c04a4d0u; return 0; }
r[6]+=0x0000001cu;
goto P_0c04a4d2;
P_0c04a4d2: /* original f63b, guest PC 0x0c04a4d2 */
if(!s->budget--) { s->failed_pc=0x0c04a4d2u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c04a4d4;
P_0c04a4d4: /* original fc32, guest PC 0x0c04a4d4 */
if(!s->budget--) { s->failed_pc=0x0c04a4d4u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'*');
goto P_0c04a4d6;
P_0c04a4d6: /* original ff32, guest PC 0x0c04a4d6 */
if(!s->budget--) { s->failed_pc=0x0c04a4d6u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c04a4d8;
P_0c04a4d8: /* original f6cb, guest PC 0x0c04a4d8 */
if(!s->budget--) { s->failed_pc=0x0c04a4d8u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[6]);
goto P_0c04a4da;
P_0c04a4da: /* original f6fb, guest PC 0x0c04a4da */
if(!s->budget--) { s->failed_pc=0x0c04a4dau; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[6]);
goto P_0c04a4dc;
P_0c04a4dc: /* original 0683, guest PC 0x0c04a4dc */
if(!s->budget--) { s->failed_pc=0x0c04a4dcu; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a4de;
P_0c04a4de: /* original f3fd, guest PC 0x0c04a4de */
if(!s->budget--) { s->failed_pc=0x0c04a4deu; return 0; }
r[18]^=0x100000u;
goto P_0c04a4e0;
P_0c04a4e0: /* original 7610, guest PC 0x0c04a4e0 */
if(!s->budget--) { s->failed_pc=0x0c04a4e0u; return 0; }
r[6]+=0x00000010u;
goto P_0c04a4e2;
P_0c04a4e2: /* original 4c5a, guest PC 0x0c04a4e2 */
if(!s->budget--) { s->failed_pc=0x0c04a4e2u; return 0; }
r[53]=r[12];
goto P_0c04a4e4;
P_0c04a4e4: /* original eb01, guest PC 0x0c04a4e4 */
if(!s->budget--) { s->failed_pc=0x0c04a4e4u; return 0; }
r[11]=0x00000001u;
goto P_0c04a4e6;
P_0c04a4e6: /* original f20d, guest PC 0x0c04a4e6 */
if(!s->budget--) { s->failed_pc=0x0c04a4e6u; return 0; }
fr[2]=r[53];
goto P_0c04a4e8;
P_0c04a4e8: /* original 7540, guest PC 0x0c04a4e8 */
if(!s->budget--) { s->failed_pc=0x0c04a4e8u; return 0; }
r[5]+=0x00000040u;
goto P_0c04a4ea;
P_0c04a4ea: /* original 4b5a, guest PC 0x0c04a4ea */
if(!s->budget--) { s->failed_pc=0x0c04a4eau; return 0; }
r[53]=r[11];
goto P_0c04a4ec;
P_0c04a4ec: /* original 0683, guest PC 0x0c04a4ec */
if(!s->budget--) { s->failed_pc=0x0c04a4ecu; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a4ee;
P_0c04a4ee: /* original af80, guest PC 0x0c04a4ee */
if(!s->budget--) { s->failed_pc=0x0c04a4eeu; return 0; }
r[6]+=0x00000020u;
goto P_0c04a3f2;
P_0c04a4f0: /* original 7620, guest PC 0x0c04a4f0 */
if(!s->budget--) { s->failed_pc=0x0c04a4f0u; return 0; }
r[6]+=0x00000020u;
goto P_0c04a4f2;
P_0c04a4f2: /* original 4c5a, guest PC 0x0c04a4f2 */
if(!s->budget--) { s->failed_pc=0x0c04a4f2u; return 0; }
r[53]=r[12];
goto P_0c04a4f4;
P_0c04a4f4: /* original 7628, guest PC 0x0c04a4f4 */
if(!s->budget--) { s->failed_pc=0x0c04a4f4u; return 0; }
r[6]+=0x00000028u;
goto P_0c04a4f6;
P_0c04a4f6: /* original f26c, guest PC 0x0c04a4f6 */
if(!s->budget--) { s->failed_pc=0x0c04a4f6u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c04a4f8;
P_0c04a4f8: /* original f672, guest PC 0x0c04a4f8 */
if(!s->budget--) { s->failed_pc=0x0c04a4f8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c04a4fa;
P_0c04a4fa: /* original f04c, guest PC 0x0c04a4fa */
if(!s->budget--) { s->failed_pc=0x0c04a4fau; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c04a4fc;
P_0c04a4fc: /* original f572, guest PC 0x0c04a4fc */
if(!s->budget--) { s->failed_pc=0x0c04a4fcu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c04a4fe;
P_0c04a4fe: /* original f00d, guest PC 0x0c04a4fe */
if(!s->budget--) { s->failed_pc=0x0c04a4feu; return 0; }
fr[0]=r[53];
goto P_0c04a500;
P_0c04a500: /* original f041, guest PC 0x0c04a500 */
if(!s->budget--) { s->failed_pc=0x0c04a500u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'-');
goto P_0c04a502;
P_0c04a502: /* original fc1d, guest PC 0x0c04a502 */
if(!s->budget--) { s->failed_pc=0x0c04a502u; return 0; }
r[53]=fr[12];
goto P_0c04a504;
P_0c04a504: /* original ff0d, guest PC 0x0c04a504 */
if(!s->budget--) { s->failed_pc=0x0c04a504u; return 0; }
fr[15]=r[53];
goto P_0c04a506;
P_0c04a506: /* original ff41, guest PC 0x0c04a506 */
if(!s->budget--) { s->failed_pc=0x0c04a506u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'-');
goto P_0c04a508;
P_0c04a508: /* original fe1d, guest PC 0x0c04a508 */
if(!s->budget--) { s->failed_pc=0x0c04a508u; return 0; }
r[53]=fr[14];
goto P_0c04a50a;
P_0c04a50a: /* original f66b, guest PC 0x0c04a50a */
if(!s->budget--) { s->failed_pc=0x0c04a50au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c04a50c;
P_0c04a50c: /* original f64b, guest PC 0x0c04a50c */
if(!s->budget--) { s->failed_pc=0x0c04a50cu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c04a50e;
P_0c04a50e: /* original f0f3, guest PC 0x0c04a50e */
if(!s->budget--) { s->failed_pc=0x0c04a50eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'/');
goto P_0c04a510;
P_0c04a510: /* original f6ac, guest PC 0x0c04a510 */
if(!s->budget--) { s->failed_pc=0x0c04a510u; return 0; }
vf3_matrix_move(s,6,10);
goto P_0c04a512;
P_0c04a512: /* original f672, guest PC 0x0c04a512 */
if(!s->budget--) { s->failed_pc=0x0c04a512u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c04a514;
P_0c04a514: /* original f48c, guest PC 0x0c04a514 */
if(!s->budget--) { s->failed_pc=0x0c04a514u; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c04a516;
P_0c04a516: /* original f572, guest PC 0x0c04a516 */
if(!s->budget--) { s->failed_pc=0x0c04a516u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c04a518;
P_0c04a518: /* original 76f8, guest PC 0x0c04a518 */
if(!s->budget--) { s->failed_pc=0x0c04a518u; return 0; }
r[6]+=0xfffffff8u;
goto P_0c04a51a;
P_0c04a51a: /* original f66b, guest PC 0x0c04a51a */
if(!s->budget--) { s->failed_pc=0x0c04a51au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c04a51c;
P_0c04a51c: /* original e0ff, guest PC 0x0c04a51c */
if(!s->budget--) { s->failed_pc=0x0c04a51cu; return 0; }
r[0]=0xffffffffu;
goto P_0c04a51e;
P_0c04a51e: /* original f64b, guest PC 0x0c04a51e */
if(!s->budget--) { s->failed_pc=0x0c04a51eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c04a520;
P_0c04a520: /* original f3fd, guest PC 0x0c04a520 */
if(!s->budget--) { s->failed_pc=0x0c04a520u; return 0; }
r[18]^=0x100000u;
goto P_0c04a522;
P_0c04a522: /* original 2602, guest PC 0x0c04a522 */
if(!s->budget--) { s->failed_pc=0x0c04a522u; return 0; }
write(ram,r[6],r[0],4);
goto P_0c04a524;
P_0c04a524: /* original f60d, guest PC 0x0c04a524 */
if(!s->budget--) { s->failed_pc=0x0c04a524u; return 0; }
fr[6]=r[53];
goto P_0c04a526;
P_0c04a526: /* original f621, guest PC 0x0c04a526 */
if(!s->budget--) { s->failed_pc=0x0c04a526u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'-');
goto P_0c04a528;
P_0c04a528: /* original fd1d, guest PC 0x0c04a528 */
if(!s->budget--) { s->failed_pc=0x0c04a528u; return 0; }
r[53]=fr[13];
goto P_0c04a52a;
P_0c04a52a: /* original e004, guest PC 0x0c04a52a */
if(!s->budget--) { s->failed_pc=0x0c04a52au; return 0; }
r[0]=0x00000004u;
goto P_0c04a52c;
P_0c04a52c: /* original f50d, guest PC 0x0c04a52c */
if(!s->budget--) { s->failed_pc=0x0c04a52cu; return 0; }
fr[5]=r[53];
goto P_0c04a52e;
P_0c04a52e: /* original f511, guest PC 0x0c04a52e */
if(!s->budget--) { s->failed_pc=0x0c04a52eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[1],r[18],'-');
goto P_0c04a530;
P_0c04a530: /* original 7610, guest PC 0x0c04a530 */
if(!s->budget--) { s->failed_pc=0x0c04a530u; return 0; }
r[6]+=0x00000010u;
goto P_0c04a532;
P_0c04a532: /* original f26e, guest PC 0x0c04a532 */
if(!s->budget--) { s->failed_pc=0x0c04a532u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[6],fr[2],r[18]);
goto P_0c04a534;
P_0c04a534: /* original 475a, guest PC 0x0c04a534 */
if(!s->budget--) { s->failed_pc=0x0c04a534u; return 0; }
r[53]=r[7];
goto P_0c04a536;
P_0c04a536: /* original f15e, guest PC 0x0c04a536 */
if(!s->budget--) { s->failed_pc=0x0c04a536u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[5],fr[1],r[18]);
goto P_0c04a538;
P_0c04a538: /* original f00d, guest PC 0x0c04a538 */
if(!s->budget--) { s->failed_pc=0x0c04a538u; return 0; }
fr[0]=r[53];
goto P_0c04a53a;
P_0c04a53a: /* original f202, guest PC 0x0c04a53a */
if(!s->budget--) { s->failed_pc=0x0c04a53au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[0],r[18],'*');
goto P_0c04a53c;
P_0c04a53c: /* original 1672, guest PC 0x0c04a53c */
if(!s->budget--) { s->failed_pc=0x0c04a53cu; return 0; }
write(ram,r[6]+8,r[7],4);
goto P_0c04a53e;
P_0c04a53e: /* original f102, guest PC 0x0c04a53e */
if(!s->budget--) { s->failed_pc=0x0c04a53eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[0],r[18],'*');
goto P_0c04a540;
P_0c04a540: /* original f627, guest PC 0x0c04a540 */
if(!s->budget--) { s->failed_pc=0x0c04a540u; return 0; }
vf3_matrix_store(s,ram,2,r[6]+r[0]);
goto P_0c04a542;
P_0c04a542: /* original f61a, guest PC 0x0c04a542 */
if(!s->budget--) { s->failed_pc=0x0c04a542u; return 0; }
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c04a544;
P_0c04a544: /* original 76f0, guest PC 0x0c04a544 */
if(!s->budget--) { s->failed_pc=0x0c04a544u; return 0; }
r[6]+=0xfffffff0u;
goto P_0c04a546;
P_0c04a546: /* original 0683, guest PC 0x0c04a546 */
if(!s->budget--) { s->failed_pc=0x0c04a546u; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a548;
P_0c04a548: /* original f3fd, guest PC 0x0c04a548 */
if(!s->budget--) { s->failed_pc=0x0c04a548u; return 0; }
r[18]^=0x100000u;
goto P_0c04a54a;
P_0c04a54a: /* original 7620, guest PC 0x0c04a54a */
if(!s->budget--) { s->failed_pc=0x0c04a54au; return 0; }
r[6]+=0x00000020u;
goto P_0c04a54c;
P_0c04a54c: /* original 7540, guest PC 0x0c04a54c */
if(!s->budget--) { s->failed_pc=0x0c04a54cu; return 0; }
r[5]+=0x00000040u;
goto P_0c04a54e;
P_0c04a54e: /* original 0683, guest PC 0x0c04a54e */
if(!s->budget--) { s->failed_pc=0x0c04a54eu; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a550;
P_0c04a550: /* original 7620, guest PC 0x0c04a550 */
if(!s->budget--) { s->failed_pc=0x0c04a550u; return 0; }
r[6]+=0x00000020u;
goto P_0c04a552;
P_0c04a552: /* original 4c5a, guest PC 0x0c04a552 */
if(!s->budget--) { s->failed_pc=0x0c04a552u; return 0; }
r[53]=r[12];
goto P_0c04a554;
P_0c04a554: /* original 7628, guest PC 0x0c04a554 */
if(!s->budget--) { s->failed_pc=0x0c04a554u; return 0; }
r[6]+=0x00000028u;
goto P_0c04a556;
P_0c04a556: /* original f2ac, guest PC 0x0c04a556 */
if(!s->budget--) { s->failed_pc=0x0c04a556u; return 0; }
vf3_matrix_move(s,2,10);
goto P_0c04a558;
P_0c04a558: /* original fab2, guest PC 0x0c04a558 */
if(!s->budget--) { s->failed_pc=0x0c04a558u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[11],r[18],'*');
goto P_0c04a55a;
P_0c04a55a: /* original f08c, guest PC 0x0c04a55a */
if(!s->budget--) { s->failed_pc=0x0c04a55au; return 0; }
vf3_matrix_move(s,0,8);
goto P_0c04a55c;
P_0c04a55c: /* original f9b2, guest PC 0x0c04a55c */
if(!s->budget--) { s->failed_pc=0x0c04a55cu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[11],r[18],'*');
goto P_0c04a55e;
P_0c04a55e: /* original f00d, guest PC 0x0c04a55e */
if(!s->budget--) { s->failed_pc=0x0c04a55eu; return 0; }
fr[0]=r[53];
goto P_0c04a560;
P_0c04a560: /* original f081, guest PC 0x0c04a560 */
if(!s->budget--) { s->failed_pc=0x0c04a560u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[8],r[18],'-');
goto P_0c04a562;
P_0c04a562: /* original fc1d, guest PC 0x0c04a562 */
if(!s->budget--) { s->failed_pc=0x0c04a562u; return 0; }
r[53]=fr[12];
goto P_0c04a564;
P_0c04a564: /* original ff0d, guest PC 0x0c04a564 */
if(!s->budget--) { s->failed_pc=0x0c04a564u; return 0; }
fr[15]=r[53];
goto P_0c04a566;
P_0c04a566: /* original ff81, guest PC 0x0c04a566 */
if(!s->budget--) { s->failed_pc=0x0c04a566u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[8],r[18],'-');
goto P_0c04a568;
P_0c04a568: /* original f6ab, guest PC 0x0c04a568 */
if(!s->budget--) { s->failed_pc=0x0c04a568u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,10,r[6]);
goto P_0c04a56a;
P_0c04a56a: /* original f68b, guest PC 0x0c04a56a */
if(!s->budget--) { s->failed_pc=0x0c04a56au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[6]);
goto P_0c04a56c;
P_0c04a56c: /* original f0f3, guest PC 0x0c04a56c */
if(!s->budget--) { s->failed_pc=0x0c04a56cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'/');
goto P_0c04a56e;
P_0c04a56e: /* original f3fd, guest PC 0x0c04a56e */
if(!s->budget--) { s->failed_pc=0x0c04a56eu; return 0; }
r[18]^=0x100000u;
goto P_0c04a570;
P_0c04a570: /* original 2672, guest PC 0x0c04a570 */
if(!s->budget--) { s->failed_pc=0x0c04a570u; return 0; }
write(ram,r[6],r[7],4);
goto P_0c04a572;
P_0c04a572: /* original fe21, guest PC 0x0c04a572 */
if(!s->budget--) { s->failed_pc=0x0c04a572u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[2],r[18],'-');
goto P_0c04a574;
P_0c04a574: /* original e004, guest PC 0x0c04a574 */
if(!s->budget--) { s->failed_pc=0x0c04a574u; return 0; }
r[0]=0x00000004u;
goto P_0c04a576;
P_0c04a576: /* original fd11, guest PC 0x0c04a576 */
if(!s->budget--) { s->failed_pc=0x0c04a576u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[1],r[18],'-');
goto P_0c04a578;
P_0c04a578: /* original 76ec, guest PC 0x0c04a578 */
if(!s->budget--) { s->failed_pc=0x0c04a578u; return 0; }
r[6]+=0xffffffecu;
goto P_0c04a57a;
P_0c04a57a: /* original f2ee, guest PC 0x0c04a57a */
if(!s->budget--) { s->failed_pc=0x0c04a57au; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[14],fr[2],r[18]);
goto P_0c04a57c;
P_0c04a57c: /* original 475a, guest PC 0x0c04a57c */
if(!s->budget--) { s->failed_pc=0x0c04a57cu; return 0; }
r[53]=r[7];
goto P_0c04a57e;
P_0c04a57e: /* original f1de, guest PC 0x0c04a57e */
if(!s->budget--) { s->failed_pc=0x0c04a57eu; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[13],fr[1],r[18]);
goto P_0c04a580;
P_0c04a580: /* original f00d, guest PC 0x0c04a580 */
if(!s->budget--) { s->failed_pc=0x0c04a580u; return 0; }
fr[0]=r[53];
goto P_0c04a582;
P_0c04a582: /* original f202, guest PC 0x0c04a582 */
if(!s->budget--) { s->failed_pc=0x0c04a582u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[0],r[18],'*');
goto P_0c04a584;
P_0c04a584: /* original 1672, guest PC 0x0c04a584 */
if(!s->budget--) { s->failed_pc=0x0c04a584u; return 0; }
write(ram,r[6]+8,r[7],4);
goto P_0c04a586;
P_0c04a586: /* original f102, guest PC 0x0c04a586 */
if(!s->budget--) { s->failed_pc=0x0c04a586u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[0],r[18],'*');
goto P_0c04a588;
P_0c04a588: /* original f627, guest PC 0x0c04a588 */
if(!s->budget--) { s->failed_pc=0x0c04a588u; return 0; }
vf3_matrix_store(s,ram,2,r[6]+r[0]);
goto P_0c04a58a;
P_0c04a58a: /* original f61a, guest PC 0x0c04a58a */
if(!s->budget--) { s->failed_pc=0x0c04a58au; return 0; }
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c04a58c;
P_0c04a58c: /* original 76fc, guest PC 0x0c04a58c */
if(!s->budget--) { s->failed_pc=0x0c04a58cu; return 0; }
r[6]+=0xfffffffcu;
goto P_0c04a58e;
P_0c04a58e: /* original 0683, guest PC 0x0c04a58e */
if(!s->budget--) { s->failed_pc=0x0c04a58eu; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a590;
P_0c04a590: /* original f3fd, guest PC 0x0c04a590 */
if(!s->budget--) { s->failed_pc=0x0c04a590u; return 0; }
r[18]^=0x100000u;
goto P_0c04a592;
P_0c04a592: /* original 7620, guest PC 0x0c04a592 */
if(!s->budget--) { s->failed_pc=0x0c04a592u; return 0; }
r[6]+=0x00000020u;
goto P_0c04a594;
P_0c04a594: /* original 4c5a, guest PC 0x0c04a594 */
if(!s->budget--) { s->failed_pc=0x0c04a594u; return 0; }
r[53]=r[12];
goto P_0c04a596;
P_0c04a596: /* original eb01, guest PC 0x0c04a596 */
if(!s->budget--) { s->failed_pc=0x0c04a596u; return 0; }
r[11]=0x00000001u;
goto P_0c04a598;
P_0c04a598: /* original f20d, guest PC 0x0c04a598 */
if(!s->budget--) { s->failed_pc=0x0c04a598u; return 0; }
fr[2]=r[53];
goto P_0c04a59a;
P_0c04a59a: /* original 7540, guest PC 0x0c04a59a */
if(!s->budget--) { s->failed_pc=0x0c04a59au; return 0; }
r[5]+=0x00000040u;
goto P_0c04a59c;
P_0c04a59c: /* original 4b5a, guest PC 0x0c04a59c */
if(!s->budget--) { s->failed_pc=0x0c04a59cu; return 0; }
r[53]=r[11];
goto P_0c04a59e;
P_0c04a59e: /* original 0683, guest PC 0x0c04a59e */
if(!s->budget--) { s->failed_pc=0x0c04a59eu; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a5a0;
P_0c04a5a0: /* original af27, guest PC 0x0c04a5a0 */
if(!s->budget--) { s->failed_pc=0x0c04a5a0u; return 0; }
r[6]+=0x00000020u;
goto P_0c04a3f2;
P_0c04a5a2: /* original 7620, guest PC 0x0c04a5a2 */
if(!s->budget--) { s->failed_pc=0x0c04a5a2u; return 0; }
r[6]+=0x00000020u;
if(!vf3_matrix_family(0x0c04a5a4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04a5a4u; return 0; } return 1;
P_0c06c5c8: /* original 2fe6, guest PC 0x0c06c5c8 */
if(!s->budget--) { s->failed_pc=0x0c06c5c8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c5ca;
P_0c06c5ca: /* original d346, guest PC 0x0c06c5ca */
if(!s->budget--) { s->failed_pc=0x0c06c5cau; return 0; }
r[3]=read(ram,0x0c06c6e4u,4);
goto P_0c06c5cc;
P_0c06c5cc: /* original d246, guest PC 0x0c06c5cc */
if(!s->budget--) { s->failed_pc=0x0c06c5ccu; return 0; }
r[2]=read(ram,0x0c06c6e8u,4);
goto P_0c06c5ce;
P_0c06c5ce: /* original 6530, guest PC 0x0c06c5ce */
if(!s->budget--) { s->failed_pc=0x0c06c5ceu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[5]=tmp;
goto P_0c06c5d0;
P_0c06c5d0: /* original 4f22, guest PC 0x0c06c5d0 */
if(!s->budget--) { s->failed_pc=0x0c06c5d0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c5d2;
P_0c06c5d2: /* original 6422, guest PC 0x0c06c5d2 */
if(!s->budget--) { s->failed_pc=0x0c06c5d2u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c06c5d4;
P_0c06c5d4: /* original 655c, guest PC 0x0c06c5d4 */
if(!s->budget--) { s->failed_pc=0x0c06c5d4u; return 0; }
r[5]=r[5]&255u;
goto P_0c06c5d6;
P_0c06c5d6: /* original de42, guest PC 0x0c06c5d6 */
if(!s->budget--) { s->failed_pc=0x0c06c5d6u; return 0; }
r[14]=read(ram,0x0c06c6e0u,4);
goto P_0c06c5d8;
P_0c06c5d8: /* original 2558, guest PC 0x0c06c5d8 */
if(!s->budget--) { s->failed_pc=0x0c06c5d8u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06c5da;
P_0c06c5da: /* original 8d0f, guest PC 0x0c06c5da */
if(!s->budget--) { s->failed_pc=0x0c06c5dau; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(cond) { goto P_0c06c5fc; }
goto P_0c06c5de;
P_0c06c5dc: /* original 7401, guest PC 0x0c06c5dc */
if(!s->budget--) { s->failed_pc=0x0c06c5dcu; return 0; }
r[4]+=0x00000001u;
goto P_0c06c5de;
P_0c06c5de: /* original 6053, guest PC 0x0c06c5de */
if(!s->budget--) { s->failed_pc=0x0c06c5deu; return 0; }
r[0]=r[5];
goto P_0c06c5e0;
P_0c06c5e0: /* original 8801, guest PC 0x0c06c5e0 */
if(!s->budget--) { s->failed_pc=0x0c06c5e0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c5e2;
P_0c06c5e2: /* original 8b05, guest PC 0x0c06c5e2 */
if(!s->budget--) { s->failed_pc=0x0c06c5e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c5f0; }
goto P_0c06c5e4;
P_0c06c5e4: /* original 4f26, guest PC 0x0c06c5e4 */
if(!s->budget--) { s->failed_pc=0x0c06c5e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c5e6;
P_0c06c5e6: /* original 6543, guest PC 0x0c06c5e6 */
if(!s->budget--) { s->failed_pc=0x0c06c5e6u; return 0; }
r[5]=r[4];
goto P_0c06c5e8;
P_0c06c5e8: /* original e404, guest PC 0x0c06c5e8 */
if(!s->budget--) { s->failed_pc=0x0c06c5e8u; return 0; }
r[4]=0x00000004u;
goto P_0c06c5ea;
P_0c06c5ea: /* original e627, guest PC 0x0c06c5ea */
if(!s->budget--) { s->failed_pc=0x0c06c5eau; return 0; }
r[6]=0x00000027u;
goto P_0c06c5ec;
P_0c06c5ec: /* original a023, guest PC 0x0c06c5ec */
if(!s->budget--) { s->failed_pc=0x0c06c5ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06c636u,s,ram);
P_0c06c5ee: /* original 6ef6, guest PC 0x0c06c5ee */
if(!s->budget--) { s->failed_pc=0x0c06c5eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c5f0;
P_0c06c5f0: /* original 4f26, guest PC 0x0c06c5f0 */
if(!s->budget--) { s->failed_pc=0x0c06c5f0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c5f2;
P_0c06c5f2: /* original 6543, guest PC 0x0c06c5f2 */
if(!s->budget--) { s->failed_pc=0x0c06c5f2u; return 0; }
r[5]=r[4];
goto P_0c06c5f4;
P_0c06c5f4: /* original e427, guest PC 0x0c06c5f4 */
if(!s->budget--) { s->failed_pc=0x0c06c5f4u; return 0; }
r[4]=0x00000027u;
goto P_0c06c5f6;
P_0c06c5f6: /* original e604, guest PC 0x0c06c5f6 */
if(!s->budget--) { s->failed_pc=0x0c06c5f6u; return 0; }
r[6]=0x00000004u;
goto P_0c06c5f8;
P_0c06c5f8: /* original a01d, guest PC 0x0c06c5f8 */
if(!s->budget--) { s->failed_pc=0x0c06c5f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06c636u,s,ram);
P_0c06c5fa: /* original 6ef6, guest PC 0x0c06c5fa */
if(!s->budget--) { s->failed_pc=0x0c06c5fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c5fc;
P_0c06c5fc: /* original e307, guest PC 0x0c06c5fc */
if(!s->budget--) { s->failed_pc=0x0c06c5fcu; return 0; }
r[3]=0x00000007u;
goto P_0c06c5fe;
P_0c06c5fe: /* original e220, guest PC 0x0c06c5fe */
if(!s->budget--) { s->failed_pc=0x0c06c5feu; return 0; }
r[2]=0x00000020u;
goto P_0c06c600;
P_0c06c600: /* original e508, guest PC 0x0c06c600 */
if(!s->budget--) { s->failed_pc=0x0c06c600u; return 0; }
r[5]=0x00000008u;
goto P_0c06c602;
P_0c06c602: /* original 2f26, guest PC 0x0c06c602 */
if(!s->budget--) { s->failed_pc=0x0c06c602u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c604;
P_0c06c604: /* original d139, guest PC 0x0c06c604 */
if(!s->budget--) { s->failed_pc=0x0c06c604u; return 0; }
r[1]=read(ram,0x0c06c6ecu,4);
goto P_0c06c606;
P_0c06c606: /* original 443c, guest PC 0x0c06c606 */
if(!s->budget--) { s->failed_pc=0x0c06c606u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c06c608;
P_0c06c608: /* original e615, guest PC 0x0c06c608 */
if(!s->budget--) { s->failed_pc=0x0c06c608u; return 0; }
r[6]=0x00000015u;
goto P_0c06c60a;
P_0c06c60a: /* original e701, guest PC 0x0c06c60a */
if(!s->budget--) { s->failed_pc=0x0c06c60au; return 0; }
r[7]=0x00000001u;
goto P_0c06c60c;
P_0c06c60c: /* original 254b, guest PC 0x0c06c60c */
if(!s->budget--) { s->failed_pc=0x0c06c60cu; return 0; }
r[5]|=r[4];
goto P_0c06c60e;
P_0c06c60e: /* original 410b, guest PC 0x0c06c60e */
if(!s->budget--) { s->failed_pc=0x0c06c60eu; return 0; }
target=r[1];
r[16]=code_base|0x0c06c612u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c612u) { target=s->pc; goto dispatch; }
goto P_0c06c612;
P_0c06c610: /* original 64e3, guest PC 0x0c06c610 */
if(!s->budget--) { s->failed_pc=0x0c06c610u; return 0; }
r[4]=r[14];
goto P_0c06c612;
P_0c06c612: /* original d335, guest PC 0x0c06c612 */
if(!s->budget--) { s->failed_pc=0x0c06c612u; return 0; }
r[3]=read(ram,0x0c06c6e8u,4);
goto P_0c06c614;
P_0c06c614: /* original e207, guest PC 0x0c06c614 */
if(!s->budget--) { s->failed_pc=0x0c06c614u; return 0; }
r[2]=0x00000007u;
goto P_0c06c616;
P_0c06c616: /* original e120, guest PC 0x0c06c616 */
if(!s->budget--) { s->failed_pc=0x0c06c616u; return 0; }
r[1]=0x00000020u;
goto P_0c06c618;
P_0c06c618: /* original 6032, guest PC 0x0c06c618 */
if(!s->budget--) { s->failed_pc=0x0c06c618u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c06c61a;
P_0c06c61a: /* original e54e, guest PC 0x0c06c61a */
if(!s->budget--) { s->failed_pc=0x0c06c61au; return 0; }
r[5]=0x0000004eu;
goto P_0c06c61c;
P_0c06c61c: /* original e615, guest PC 0x0c06c61c */
if(!s->budget--) { s->failed_pc=0x0c06c61cu; return 0; }
r[6]=0x00000015u;
goto P_0c06c61e;
P_0c06c61e: /* original 2f16, guest PC 0x0c06c61e */
if(!s->budget--) { s->failed_pc=0x0c06c61eu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c620;
P_0c06c620: /* original 7001, guest PC 0x0c06c620 */
if(!s->budget--) { s->failed_pc=0x0c06c620u; return 0; }
r[0]+=0x00000001u;
goto P_0c06c622;
P_0c06c622: /* original d332, guest PC 0x0c06c622 */
if(!s->budget--) { s->failed_pc=0x0c06c622u; return 0; }
r[3]=read(ram,0x0c06c6ecu,4);
goto P_0c06c624;
P_0c06c624: /* original 402c, guest PC 0x0c06c624 */
if(!s->budget--) { s->failed_pc=0x0c06c624u; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[0]>>((-r[2])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[2]&31u);
goto P_0c06c626;
P_0c06c626: /* original e701, guest PC 0x0c06c626 */
if(!s->budget--) { s->failed_pc=0x0c06c626u; return 0; }
r[7]=0x00000001u;
goto P_0c06c628;
P_0c06c628: /* original 250b, guest PC 0x0c06c628 */
if(!s->budget--) { s->failed_pc=0x0c06c628u; return 0; }
r[5]|=r[0];
goto P_0c06c62a;
P_0c06c62a: /* original 430b, guest PC 0x0c06c62a */
if(!s->budget--) { s->failed_pc=0x0c06c62au; return 0; }
target=r[3];
r[16]=code_base|0x0c06c62eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c62eu) { target=s->pc; goto dispatch; }
goto P_0c06c62e;
P_0c06c62c: /* original 64e3, guest PC 0x0c06c62c */
if(!s->budget--) { s->failed_pc=0x0c06c62cu; return 0; }
r[4]=r[14];
goto P_0c06c62e;
P_0c06c62e: /* original 7f08, guest PC 0x0c06c62e */
if(!s->budget--) { s->failed_pc=0x0c06c62eu; return 0; }
r[15]+=0x00000008u;
goto P_0c06c630;
P_0c06c630: /* original 4f26, guest PC 0x0c06c630 */
if(!s->budget--) { s->failed_pc=0x0c06c630u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c632;
P_0c06c632: /* original 000b, guest PC 0x0c06c632 */
if(!s->budget--) { s->failed_pc=0x0c06c632u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06c634: /* original 6ef6, guest PC 0x0c06c634 */
if(!s->budget--) { s->failed_pc=0x0c06c634u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06c636u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
