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
int vf3_away_batch34_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06a348u: goto P_0c06a348;
case 0x0c06a34au: goto P_0c06a34a;
case 0x0c06a34cu: goto P_0c06a34c;
case 0x0c06a34eu: goto P_0c06a34e;
case 0x0c06a350u: goto P_0c06a350;
case 0x0c06a352u: goto P_0c06a352;
case 0x0c06a354u: goto P_0c06a354;
case 0x0c06a356u: goto P_0c06a356;
case 0x0c06a358u: goto P_0c06a358;
case 0x0c06a35au: goto P_0c06a35a;
case 0x0c06a35cu: goto P_0c06a35c;
case 0x0c06a35eu: goto P_0c06a35e;
case 0x0c06a360u: goto P_0c06a360;
case 0x0c06a362u: goto P_0c06a362;
case 0x0c06a364u: goto P_0c06a364;
case 0x0c06a366u: goto P_0c06a366;
case 0x0c06a368u: goto P_0c06a368;
case 0x0c06a36au: goto P_0c06a36a;
case 0x0c06a36cu: goto P_0c06a36c;
case 0x0c06a36eu: goto P_0c06a36e;
case 0x0c06a370u: goto P_0c06a370;
case 0x0c06a372u: goto P_0c06a372;
case 0x0c06a374u: goto P_0c06a374;
case 0x0c06a376u: goto P_0c06a376;
case 0x0c06a378u: goto P_0c06a378;
case 0x0c06a37au: goto P_0c06a37a;
case 0x0c06a37cu: goto P_0c06a37c;
case 0x0c06a37eu: goto P_0c06a37e;
case 0x0c06a380u: goto P_0c06a380;
case 0x0c06a382u: goto P_0c06a382;
case 0x0c06a384u: goto P_0c06a384;
case 0x0c06a386u: goto P_0c06a386;
case 0x0c06a388u: goto P_0c06a388;
case 0x0c06a38au: goto P_0c06a38a;
case 0x0c06a38cu: goto P_0c06a38c;
case 0x0c06a38eu: goto P_0c06a38e;
case 0x0c06a390u: goto P_0c06a390;
case 0x0c06a392u: goto P_0c06a392;
case 0x0c06a394u: goto P_0c06a394;
case 0x0c06a396u: goto P_0c06a396;
case 0x0c06a398u: goto P_0c06a398;
case 0x0c06a39au: goto P_0c06a39a;
case 0x0c06a39cu: goto P_0c06a39c;
case 0x0c06a39eu: goto P_0c06a39e;
case 0x0c06a3a0u: goto P_0c06a3a0;
case 0x0c06a3a2u: goto P_0c06a3a2;
case 0x0c06a3a4u: goto P_0c06a3a4;
case 0x0c06a3a6u: goto P_0c06a3a6;
case 0x0c06a3a8u: goto P_0c06a3a8;
case 0x0c06a3aau: goto P_0c06a3aa;
case 0x0c06a3acu: goto P_0c06a3ac;
case 0x0c06a3aeu: goto P_0c06a3ae;
case 0x0c06a3b0u: goto P_0c06a3b0;
case 0x0c06a3b2u: goto P_0c06a3b2;
case 0x0c06a3b4u: goto P_0c06a3b4;
case 0x0c06a3b6u: goto P_0c06a3b6;
case 0x0c06a3b8u: goto P_0c06a3b8;
case 0x0c06a3bau: goto P_0c06a3ba;
case 0x0c06a3bcu: goto P_0c06a3bc;
case 0x0c06a3beu: goto P_0c06a3be;
case 0x0c06a3c0u: goto P_0c06a3c0;
case 0x0c06a3c2u: goto P_0c06a3c2;
case 0x0c06a3c4u: goto P_0c06a3c4;
case 0x0c06a3c6u: goto P_0c06a3c6;
case 0x0c06a3c8u: goto P_0c06a3c8;
case 0x0c06a3cau: goto P_0c06a3ca;
case 0x0c06a3ccu: goto P_0c06a3cc;
case 0x0c06a3ceu: goto P_0c06a3ce;
case 0x0c06a3d0u: goto P_0c06a3d0;
case 0x0c06a3d2u: goto P_0c06a3d2;
case 0x0c06a3d4u: goto P_0c06a3d4;
case 0x0c06a3d6u: goto P_0c06a3d6;
case 0x0c06a3d8u: goto P_0c06a3d8;
case 0x0c06a3dau: goto P_0c06a3da;
case 0x0c06a3dcu: goto P_0c06a3dc;
case 0x0c06a3deu: goto P_0c06a3de;
case 0x0c06a3e0u: goto P_0c06a3e0;
case 0x0c06a3e2u: goto P_0c06a3e2;
case 0x0c06a3e4u: goto P_0c06a3e4;
case 0x0c06a3e6u: goto P_0c06a3e6;
case 0x0c06a3e8u: goto P_0c06a3e8;
case 0x0c06a3eau: goto P_0c06a3ea;
case 0x0c06a3ecu: goto P_0c06a3ec;
case 0x0c06a3eeu: goto P_0c06a3ee;
case 0x0c06a3f0u: goto P_0c06a3f0;
case 0x0c06a3f2u: goto P_0c06a3f2;
case 0x0c06a3f4u: goto P_0c06a3f4;
case 0x0c06a3f6u: goto P_0c06a3f6;
case 0x0c06a3f8u: goto P_0c06a3f8;
case 0x0c06a3fau: goto P_0c06a3fa;
case 0x0c06a3fcu: goto P_0c06a3fc;
case 0x0c06a3feu: goto P_0c06a3fe;
case 0x0c06a400u: goto P_0c06a400;
case 0x0c06a402u: goto P_0c06a402;
case 0x0c06a404u: goto P_0c06a404;
case 0x0c06a406u: goto P_0c06a406;
case 0x0c06a408u: goto P_0c06a408;
case 0x0c06a40au: goto P_0c06a40a;
case 0x0c06a40cu: goto P_0c06a40c;
case 0x0c06a40eu: goto P_0c06a40e;
case 0x0c06a410u: goto P_0c06a410;
case 0x0c06a412u: goto P_0c06a412;
case 0x0c06a414u: goto P_0c06a414;
case 0x0c06a416u: goto P_0c06a416;
case 0x0c06a418u: goto P_0c06a418;
case 0x0c06a41au: goto P_0c06a41a;
case 0x0c06a41cu: goto P_0c06a41c;
case 0x0c06a41eu: goto P_0c06a41e;
case 0x0c06a420u: goto P_0c06a420;
case 0x0c06a422u: goto P_0c06a422;
case 0x0c06a424u: goto P_0c06a424;
case 0x0c06a426u: goto P_0c06a426;
case 0x0c06a428u: goto P_0c06a428;
case 0x0c06a42au: goto P_0c06a42a;
case 0x0c06a42cu: goto P_0c06a42c;
case 0x0c06a42eu: goto P_0c06a42e;
case 0x0c06a430u: goto P_0c06a430;
case 0x0c06a432u: goto P_0c06a432;
case 0x0c06a434u: goto P_0c06a434;
case 0x0c06a436u: goto P_0c06a436;
case 0x0c06a438u: goto P_0c06a438;
case 0x0c06a43au: goto P_0c06a43a;
case 0x0c06a43cu: goto P_0c06a43c;
case 0x0c06a43eu: goto P_0c06a43e;
case 0x0c06a440u: goto P_0c06a440;
case 0x0c06a442u: goto P_0c06a442;
case 0x0c06a444u: goto P_0c06a444;
case 0x0c06a446u: goto P_0c06a446;
case 0x0c06a448u: goto P_0c06a448;
case 0x0c06a44au: goto P_0c06a44a;
case 0x0c06a44cu: goto P_0c06a44c;
case 0x0c06a44eu: goto P_0c06a44e;
case 0x0c06a450u: goto P_0c06a450;
case 0x0c06a480u: goto P_0c06a480;
case 0x0c06a482u: goto P_0c06a482;
case 0x0c06a484u: goto P_0c06a484;
case 0x0c06a486u: goto P_0c06a486;
case 0x0c06a488u: goto P_0c06a488;
case 0x0c06a48au: goto P_0c06a48a;
case 0x0c06a48cu: goto P_0c06a48c;
case 0x0c06a48eu: goto P_0c06a48e;
case 0x0c06a490u: goto P_0c06a490;
case 0x0c06a492u: goto P_0c06a492;
case 0x0c06a494u: goto P_0c06a494;
case 0x0c06a496u: goto P_0c06a496;
case 0x0c06a498u: goto P_0c06a498;
case 0x0c06a49au: goto P_0c06a49a;
case 0x0c06a49cu: goto P_0c06a49c;
case 0x0c06a49eu: goto P_0c06a49e;
case 0x0c06a4a0u: goto P_0c06a4a0;
case 0x0c06a4a2u: goto P_0c06a4a2;
case 0x0c06a4a4u: goto P_0c06a4a4;
case 0x0c06a4a6u: goto P_0c06a4a6;
case 0x0c06a4a8u: goto P_0c06a4a8;
case 0x0c06a4aau: goto P_0c06a4aa;
case 0x0c06a4acu: goto P_0c06a4ac;
case 0x0c06a4aeu: goto P_0c06a4ae;
case 0x0c06a4b0u: goto P_0c06a4b0;
case 0x0c06a4b2u: goto P_0c06a4b2;
case 0x0c06a4b4u: goto P_0c06a4b4;
case 0x0c06a4b6u: goto P_0c06a4b6;
case 0x0c06a4b8u: goto P_0c06a4b8;
case 0x0c06a4bau: goto P_0c06a4ba;
case 0x0c06a4bcu: goto P_0c06a4bc;
case 0x0c06a4beu: goto P_0c06a4be;
case 0x0c06a4c0u: goto P_0c06a4c0;
case 0x0c06a4c2u: goto P_0c06a4c2;
case 0x0c06a4c4u: goto P_0c06a4c4;
case 0x0c06a4c6u: goto P_0c06a4c6;
case 0x0c06a4c8u: goto P_0c06a4c8;
case 0x0c06a4cau: goto P_0c06a4ca;
case 0x0c06a4ccu: goto P_0c06a4cc;
case 0x0c06a4ceu: goto P_0c06a4ce;
case 0x0c06a4d0u: goto P_0c06a4d0;
case 0x0c06a4d2u: goto P_0c06a4d2;
case 0x0c06a4d4u: goto P_0c06a4d4;
case 0x0c06a4d6u: goto P_0c06a4d6;
case 0x0c06a4d8u: goto P_0c06a4d8;
case 0x0c06a4dau: goto P_0c06a4da;
case 0x0c06a4dcu: goto P_0c06a4dc;
case 0x0c06a4deu: goto P_0c06a4de;
case 0x0c06a4e0u: goto P_0c06a4e0;
case 0x0c06a4e2u: goto P_0c06a4e2;
case 0x0c06a4e4u: goto P_0c06a4e4;
case 0x0c06a4e6u: goto P_0c06a4e6;
case 0x0c06a4e8u: goto P_0c06a4e8;
case 0x0c06a4eau: goto P_0c06a4ea;
case 0x0c06a4ecu: goto P_0c06a4ec;
case 0x0c06a4eeu: goto P_0c06a4ee;
case 0x0c06a4f0u: goto P_0c06a4f0;
case 0x0c06a4f2u: goto P_0c06a4f2;
case 0x0c06a4f4u: goto P_0c06a4f4;
case 0x0c06a4f6u: goto P_0c06a4f6;
case 0x0c06a4f8u: goto P_0c06a4f8;
case 0x0c06a4fau: goto P_0c06a4fa;
case 0x0c06a4fcu: goto P_0c06a4fc;
case 0x0c06a4feu: goto P_0c06a4fe;
case 0x0c06a500u: goto P_0c06a500;
case 0x0c06a502u: goto P_0c06a502;
case 0x0c06a504u: goto P_0c06a504;
case 0x0c06a506u: goto P_0c06a506;
case 0x0c06a508u: goto P_0c06a508;
case 0x0c06a50au: goto P_0c06a50a;
case 0x0c06a50cu: goto P_0c06a50c;
case 0x0c06a50eu: goto P_0c06a50e;
case 0x0c06a510u: goto P_0c06a510;
case 0x0c06a512u: goto P_0c06a512;
case 0x0c06a514u: goto P_0c06a514;
case 0x0c06a516u: goto P_0c06a516;
case 0x0c06a518u: goto P_0c06a518;
case 0x0c06a51au: goto P_0c06a51a;
case 0x0c06a51cu: goto P_0c06a51c;
case 0x0c06a51eu: goto P_0c06a51e;
case 0x0c06a520u: goto P_0c06a520;
case 0x0c06a522u: goto P_0c06a522;
case 0x0c06a524u: goto P_0c06a524;
case 0x0c06a526u: goto P_0c06a526;
case 0x0c06a528u: goto P_0c06a528;
case 0x0c06a52au: goto P_0c06a52a;
case 0x0c06a52cu: goto P_0c06a52c;
case 0x0c06a52eu: goto P_0c06a52e;
case 0x0c06a530u: goto P_0c06a530;
case 0x0c06a532u: goto P_0c06a532;
case 0x0c06a534u: goto P_0c06a534;
case 0x0c06a536u: goto P_0c06a536;
case 0x0c06a538u: goto P_0c06a538;
case 0x0c06a53au: goto P_0c06a53a;
case 0x0c06a53cu: goto P_0c06a53c;
case 0x0c06a53eu: goto P_0c06a53e;
case 0x0c06a540u: goto P_0c06a540;
case 0x0c06a542u: goto P_0c06a542;
case 0x0c06a544u: goto P_0c06a544;
case 0x0c06a546u: goto P_0c06a546;
case 0x0c06a548u: goto P_0c06a548;
case 0x0c06a54au: goto P_0c06a54a;
case 0x0c06a54cu: goto P_0c06a54c;
case 0x0c06a54eu: goto P_0c06a54e;
case 0x0c06a550u: goto P_0c06a550;
case 0x0c06a552u: goto P_0c06a552;
case 0x0c06a554u: goto P_0c06a554;
case 0x0c06a556u: goto P_0c06a556;
case 0x0c06a558u: goto P_0c06a558;
case 0x0c06a55au: goto P_0c06a55a;
case 0x0c06a55cu: goto P_0c06a55c;
case 0x0c06a55eu: goto P_0c06a55e;
case 0x0c06a560u: goto P_0c06a560;
case 0x0c06a562u: goto P_0c06a562;
case 0x0c06a564u: goto P_0c06a564;
case 0x0c06a566u: goto P_0c06a566;
case 0x0c06a568u: goto P_0c06a568;
case 0x0c06a56au: goto P_0c06a56a;
case 0x0c06a56cu: goto P_0c06a56c;
case 0x0c06a56eu: goto P_0c06a56e;
case 0x0c06a570u: goto P_0c06a570;
case 0x0c06a572u: goto P_0c06a572;
case 0x0c06a574u: goto P_0c06a574;
case 0x0c06a576u: goto P_0c06a576;
case 0x0c06a578u: goto P_0c06a578;
case 0x0c06a57au: goto P_0c06a57a;
case 0x0c06a57cu: goto P_0c06a57c;
case 0x0c06a57eu: goto P_0c06a57e;
case 0x0c06a580u: goto P_0c06a580;
case 0x0c06a582u: goto P_0c06a582;
case 0x0c06a584u: goto P_0c06a584;
case 0x0c06a586u: goto P_0c06a586;
case 0x0c06a588u: goto P_0c06a588;
case 0x0c06a58au: goto P_0c06a58a;
case 0x0c06a58cu: goto P_0c06a58c;
case 0x0c06a58eu: goto P_0c06a58e;
case 0x0c06a590u: goto P_0c06a590;
case 0x0c06a592u: goto P_0c06a592;
case 0x0c06a594u: goto P_0c06a594;
case 0x0c06a596u: goto P_0c06a596;
case 0x0c06a598u: goto P_0c06a598;
case 0x0c06a59au: goto P_0c06a59a;
case 0x0c06a59cu: goto P_0c06a59c;
case 0x0c06a59eu: goto P_0c06a59e;
case 0x0c06a5a0u: goto P_0c06a5a0;
case 0x0c06a5a2u: goto P_0c06a5a2;
case 0x0c06a5a4u: goto P_0c06a5a4;
case 0x0c06a5a6u: goto P_0c06a5a6;
case 0x0c06a5a8u: goto P_0c06a5a8;
case 0x0c06a5aau: goto P_0c06a5aa;
case 0x0c06a5acu: goto P_0c06a5ac;
case 0x0c06a5aeu: goto P_0c06a5ae;
case 0x0c06a5b0u: goto P_0c06a5b0;
case 0x0c06a5b2u: goto P_0c06a5b2;
case 0x0c06a5b4u: goto P_0c06a5b4;
case 0x0c06a5b6u: goto P_0c06a5b6;
case 0x0c06a5b8u: goto P_0c06a5b8;
case 0x0c06a5bau: goto P_0c06a5ba;
case 0x0c06a5bcu: goto P_0c06a5bc;
case 0x0c06a5beu: goto P_0c06a5be;
case 0x0c06a5c0u: goto P_0c06a5c0;
case 0x0c06a5c2u: goto P_0c06a5c2;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06a348: /* original 2fe6, guest PC 0x0c06a348 */
if(!s->budget--) { s->failed_pc=0x0c06a348u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a34a;
P_0c06a34a: /* original 2fd6, guest PC 0x0c06a34a */
if(!s->budget--) { s->failed_pc=0x0c06a34au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a34c;
P_0c06a34c: /* original 2fc6, guest PC 0x0c06a34c */
if(!s->budget--) { s->failed_pc=0x0c06a34cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a34e;
P_0c06a34e: /* original 2fb6, guest PC 0x0c06a34e */
if(!s->budget--) { s->failed_pc=0x0c06a34eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a350;
P_0c06a350: /* original 2fa6, guest PC 0x0c06a350 */
if(!s->budget--) { s->failed_pc=0x0c06a350u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a352;
P_0c06a352: /* original 2f96, guest PC 0x0c06a352 */
if(!s->budget--) { s->failed_pc=0x0c06a352u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a354;
P_0c06a354: /* original 2f86, guest PC 0x0c06a354 */
if(!s->budget--) { s->failed_pc=0x0c06a354u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a356;
P_0c06a356: /* original 9e7c, guest PC 0x0c06a356 */
if(!s->budget--) { s->failed_pc=0x0c06a356u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a452u,2);
goto P_0c06a358;
P_0c06a358: /* original dc44, guest PC 0x0c06a358 */
if(!s->budget--) { s->failed_pc=0x0c06a358u; return 0; }
r[12]=read(ram,0x0c06a46cu,4);
goto P_0c06a35a;
P_0c06a35a: /* original 907b, guest PC 0x0c06a35a */
if(!s->budget--) { s->failed_pc=0x0c06a35au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a454u,2);
goto P_0c06a35c;
P_0c06a35c: /* original 4f22, guest PC 0x0c06a35c */
if(!s->budget--) { s->failed_pc=0x0c06a35cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06a35e;
P_0c06a35e: /* original d442, guest PC 0x0c06a35e */
if(!s->budget--) { s->failed_pc=0x0c06a35eu; return 0; }
r[4]=read(ram,0x0c06a468u,4);
goto P_0c06a360;
P_0c06a360: /* original 09ce, guest PC 0x0c06a360 */
if(!s->budget--) { s->failed_pc=0x0c06a360u; return 0; }
r[9]=read(ram,r[12]+r[0],4);
goto P_0c06a362;
P_0c06a362: /* original 3e4c, guest PC 0x0c06a362 */
if(!s->budget--) { s->failed_pc=0x0c06a362u; return 0; }
r[14]+=r[4];
goto P_0c06a364;
P_0c06a364: /* original db42, guest PC 0x0c06a364 */
if(!s->budget--) { s->failed_pc=0x0c06a364u; return 0; }
r[11]=read(ram,0x0c06a470u,4);
goto P_0c06a366;
P_0c06a366: /* original 64e3, guest PC 0x0c06a366 */
if(!s->budget--) { s->failed_pc=0x0c06a366u; return 0; }
r[4]=r[14];
goto P_0c06a368;
P_0c06a368: /* original 7ff8, guest PC 0x0c06a368 */
if(!s->budget--) { s->failed_pc=0x0c06a368u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c06a36a;
P_0c06a36a: /* original 4b0b, guest PC 0x0c06a36a */
if(!s->budget--) { s->failed_pc=0x0c06a36au; return 0; }
target=r[11];
r[16]=code_base|0x0c06a36eu;
r[4]+=0x00000024u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a36eu) { target=s->pc; goto dispatch; }
goto P_0c06a36e;
P_0c06a36c: /* original 7424, guest PC 0x0c06a36c */
if(!s->budget--) { s->failed_pc=0x0c06a36cu; return 0; }
r[4]+=0x00000024u;
goto P_0c06a36e;
P_0c06a36e: /* original 6a03, guest PC 0x0c06a36e */
if(!s->budget--) { s->failed_pc=0x0c06a36eu; return 0; }
r[10]=r[0];
goto P_0c06a370;
P_0c06a370: /* original dd40, guest PC 0x0c06a370 */
if(!s->budget--) { s->failed_pc=0x0c06a370u; return 0; }
r[13]=read(ram,0x0c06a474u,4);
goto P_0c06a372;
P_0c06a372: /* original 3a9c, guest PC 0x0c06a372 */
if(!s->budget--) { s->failed_pc=0x0c06a372u; return 0; }
r[10]+=r[9];
goto P_0c06a374;
P_0c06a374: /* original 64e3, guest PC 0x0c06a374 */
if(!s->budget--) { s->failed_pc=0x0c06a374u; return 0; }
r[4]=r[14];
goto P_0c06a376;
P_0c06a376: /* original 65a3, guest PC 0x0c06a376 */
if(!s->budget--) { s->failed_pc=0x0c06a376u; return 0; }
r[5]=r[10];
goto P_0c06a378;
P_0c06a378: /* original 4d0b, guest PC 0x0c06a378 */
if(!s->budget--) { s->failed_pc=0x0c06a378u; return 0; }
target=r[13];
r[16]=code_base|0x0c06a37cu;
r[4]+=0x00000024u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a37cu) { target=s->pc; goto dispatch; }
goto P_0c06a37c;
P_0c06a37a: /* original 7424, guest PC 0x0c06a37a */
if(!s->budget--) { s->failed_pc=0x0c06a37au; return 0; }
r[4]+=0x00000024u;
goto P_0c06a37c;
P_0c06a37c: /* original 64e3, guest PC 0x0c06a37c */
if(!s->budget--) { s->failed_pc=0x0c06a37cu; return 0; }
r[4]=r[14];
goto P_0c06a37e;
P_0c06a37e: /* original 6593, guest PC 0x0c06a37e */
if(!s->budget--) { s->failed_pc=0x0c06a37eu; return 0; }
r[5]=r[9];
goto P_0c06a380;
P_0c06a380: /* original b9a1, guest PC 0x0c06a380 */
if(!s->budget--) { s->failed_pc=0x0c06a380u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c06a384u;
r[4]+=0x00000030u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a384u) { target=s->pc; goto dispatch; }
goto P_0c06a384;
P_0c06a382: /* original 7430, guest PC 0x0c06a382 */
if(!s->budget--) { s->failed_pc=0x0c06a382u; return 0; }
r[4]+=0x00000030u;
goto P_0c06a384;
P_0c06a384: /* original 9067, guest PC 0x0c06a384 */
if(!s->budget--) { s->failed_pc=0x0c06a384u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a456u,2);
goto P_0c06a386;
P_0c06a386: /* original 64e3, guest PC 0x0c06a386 */
if(!s->budget--) { s->failed_pc=0x0c06a386u; return 0; }
r[4]=r[14];
goto P_0c06a388;
P_0c06a388: /* original 02ce, guest PC 0x0c06a388 */
if(!s->budget--) { s->failed_pc=0x0c06a388u; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c06a38a;
P_0c06a38a: /* original 2f22, guest PC 0x0c06a38a */
if(!s->budget--) { s->failed_pc=0x0c06a38au; return 0; }
write(ram,r[15],r[2],4);
goto P_0c06a38c;
P_0c06a38c: /* original 4b0b, guest PC 0x0c06a38c */
if(!s->budget--) { s->failed_pc=0x0c06a38cu; return 0; }
target=r[11];
r[16]=code_base|0x0c06a390u;
r[4]+=0x0000001cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a390u) { target=s->pc; goto dispatch; }
goto P_0c06a390;
P_0c06a38e: /* original 741c, guest PC 0x0c06a38e */
if(!s->budget--) { s->failed_pc=0x0c06a38eu; return 0; }
r[4]+=0x0000001cu;
goto P_0c06a390;
P_0c06a390: /* original 64e3, guest PC 0x0c06a390 */
if(!s->budget--) { s->failed_pc=0x0c06a390u; return 0; }
r[4]=r[14];
goto P_0c06a392;
P_0c06a392: /* original 6903, guest PC 0x0c06a392 */
if(!s->budget--) { s->failed_pc=0x0c06a392u; return 0; }
r[9]=r[0];
goto P_0c06a394;
P_0c06a394: /* original 4b0b, guest PC 0x0c06a394 */
if(!s->budget--) { s->failed_pc=0x0c06a394u; return 0; }
target=r[11];
r[16]=code_base|0x0c06a398u;
r[4]+=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a398u) { target=s->pc; goto dispatch; }
goto P_0c06a398;
P_0c06a396: /* original 7434, guest PC 0x0c06a396 */
if(!s->budget--) { s->failed_pc=0x0c06a396u; return 0; }
r[4]+=0x00000034u;
goto P_0c06a398;
P_0c06a398: /* original 63f2, guest PC 0x0c06a398 */
if(!s->budget--) { s->failed_pc=0x0c06a398u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06a39a;
P_0c06a39a: /* original 6803, guest PC 0x0c06a39a */
if(!s->budget--) { s->failed_pc=0x0c06a39au; return 0; }
r[8]=r[0];
goto P_0c06a39c;
P_0c06a39c: /* original 2338, guest PC 0x0c06a39c */
if(!s->budget--) { s->failed_pc=0x0c06a39cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06a39e;
P_0c06a39e: /* original 8905, guest PC 0x0c06a39e */
if(!s->budget--) { s->failed_pc=0x0c06a39eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06a3ac; }
goto P_0c06a3a0;
P_0c06a3a0: /* original 63f2, guest PC 0x0c06a3a0 */
if(!s->budget--) { s->failed_pc=0x0c06a3a0u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06a3a2;
P_0c06a3a2: /* original 64e3, guest PC 0x0c06a3a2 */
if(!s->budget--) { s->failed_pc=0x0c06a3a2u; return 0; }
r[4]=r[14];
goto P_0c06a3a4;
P_0c06a3a4: /* original 383c, guest PC 0x0c06a3a4 */
if(!s->budget--) { s->failed_pc=0x0c06a3a4u; return 0; }
r[8]+=r[3];
goto P_0c06a3a6;
P_0c06a3a6: /* original 6583, guest PC 0x0c06a3a6 */
if(!s->budget--) { s->failed_pc=0x0c06a3a6u; return 0; }
r[5]=r[8];
goto P_0c06a3a8;
P_0c06a3a8: /* original 4d0b, guest PC 0x0c06a3a8 */
if(!s->budget--) { s->failed_pc=0x0c06a3a8u; return 0; }
target=r[13];
r[16]=code_base|0x0c06a3acu;
r[4]+=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a3acu) { target=s->pc; goto dispatch; }
goto P_0c06a3ac;
P_0c06a3aa: /* original 7434, guest PC 0x0c06a3aa */
if(!s->budget--) { s->failed_pc=0x0c06a3aau; return 0; }
r[4]+=0x00000034u;
goto P_0c06a3ac;
P_0c06a3ac: /* original 3988, guest PC 0x0c06a3ac */
if(!s->budget--) { s->failed_pc=0x0c06a3acu; return 0; }
r[9]-=r[8];
goto P_0c06a3ae;
P_0c06a3ae: /* original 64e3, guest PC 0x0c06a3ae */
if(!s->budget--) { s->failed_pc=0x0c06a3aeu; return 0; }
r[4]=r[14];
goto P_0c06a3b0;
P_0c06a3b0: /* original 495a, guest PC 0x0c06a3b0 */
if(!s->budget--) { s->failed_pc=0x0c06a3b0u; return 0; }
r[53]=r[9];
goto P_0c06a3b2;
P_0c06a3b2: /* original c731, guest PC 0x0c06a3b2 */
if(!s->budget--) { s->failed_pc=0x0c06a3b2u; return 0; }
r[0]=code_base|0x0006a478u;
goto P_0c06a3b4;
P_0c06a3b4: /* original f508, guest PC 0x0c06a3b4 */
if(!s->budget--) { s->failed_pc=0x0c06a3b4u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c06a3b6;
P_0c06a3b6: /* original f32d, guest PC 0x0c06a3b6 */
if(!s->budget--) { s->failed_pc=0x0c06a3b6u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c06a3b8;
P_0c06a3b8: /* original 4a5a, guest PC 0x0c06a3b8 */
if(!s->budget--) { s->failed_pc=0x0c06a3b8u; return 0; }
r[53]=r[10];
goto P_0c06a3ba;
P_0c06a3ba: /* original f22d, guest PC 0x0c06a3ba */
if(!s->budget--) { s->failed_pc=0x0c06a3bau; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c06a3bc;
P_0c06a3bc: /* original f63c, guest PC 0x0c06a3bc */
if(!s->budget--) { s->failed_pc=0x0c06a3bcu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c06a3be;
P_0c06a3be: /* original f42c, guest PC 0x0c06a3be */
if(!s->budget--) { s->failed_pc=0x0c06a3beu; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c06a3c0;
P_0c06a3c0: /* original f452, guest PC 0x0c06a3c0 */
if(!s->budget--) { s->failed_pc=0x0c06a3c0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c06a3c2;
P_0c06a3c2: /* original f463, guest PC 0x0c06a3c2 */
if(!s->budget--) { s->failed_pc=0x0c06a3c2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
goto P_0c06a3c4;
P_0c06a3c4: /* original f43d, guest PC 0x0c06a3c4 */
if(!s->budget--) { s->failed_pc=0x0c06a3c4u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c06a3c6;
P_0c06a3c6: /* original 055a, guest PC 0x0c06a3c6 */
if(!s->budget--) { s->failed_pc=0x0c06a3c6u; return 0; }
r[5]=r[53];
goto P_0c06a3c8;
P_0c06a3c8: /* original 4d0b, guest PC 0x0c06a3c8 */
if(!s->budget--) { s->failed_pc=0x0c06a3c8u; return 0; }
target=r[13];
r[16]=code_base|0x0c06a3ccu;
r[4]+=0x0000003cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a3ccu) { target=s->pc; goto dispatch; }
goto P_0c06a3cc;
P_0c06a3ca: /* original 743c, guest PC 0x0c06a3ca */
if(!s->budget--) { s->failed_pc=0x0c06a3cau; return 0; }
r[4]+=0x0000003cu;
goto P_0c06a3cc;
P_0c06a3cc: /* original 9444, guest PC 0x0c06a3cc */
if(!s->budget--) { s->failed_pc=0x0c06a3ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a458u,2);
goto P_0c06a3ce;
P_0c06a3ce: /* original e500, guest PC 0x0c06a3ce */
if(!s->budget--) { s->failed_pc=0x0c06a3ceu; return 0; }
r[5]=0x00000000u;
goto P_0c06a3d0;
P_0c06a3d0: /* original 4d0b, guest PC 0x0c06a3d0 */
if(!s->budget--) { s->failed_pc=0x0c06a3d0u; return 0; }
target=r[13];
r[16]=code_base|0x0c06a3d4u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a3d4u) { target=s->pc; goto dispatch; }
goto P_0c06a3d4;
P_0c06a3d2: /* original 34ec, guest PC 0x0c06a3d2 */
if(!s->budget--) { s->failed_pc=0x0c06a3d2u; return 0; }
r[4]+=r[14];
goto P_0c06a3d4;
P_0c06a3d4: /* original 9041, guest PC 0x0c06a3d4 */
if(!s->budget--) { s->failed_pc=0x0c06a3d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a45au,2);
goto P_0c06a3d6;
P_0c06a3d6: /* original 0ace, guest PC 0x0c06a3d6 */
if(!s->budget--) { s->failed_pc=0x0c06a3d6u; return 0; }
r[10]=read(ram,r[12]+r[0],4);
goto P_0c06a3d8;
P_0c06a3d8: /* original 2aa8, guest PC 0x0c06a3d8 */
if(!s->budget--) { s->failed_pc=0x0c06a3d8u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c06a3da;
P_0c06a3da: /* original 8f02, guest PC 0x0c06a3da */
if(!s->budget--) { s->failed_pc=0x0c06a3dau; return 0; }
cond=r[17]&1u;
r[9]=0x00000000u;
if(!cond) { goto P_0c06a3e2; }
goto P_0c06a3de;
P_0c06a3dc: /* original e900, guest PC 0x0c06a3dc */
if(!s->budget--) { s->failed_pc=0x0c06a3dcu; return 0; }
r[9]=0x00000000u;
goto P_0c06a3de;
P_0c06a3de: /* original a0cc, guest PC 0x0c06a3de */
if(!s->budget--) { s->failed_pc=0x0c06a3deu; return 0; }
goto P_0c06a57a;
P_0c06a3e0: /* original 0009, guest PC 0x0c06a3e0 */
if(!s->budget--) { s->failed_pc=0x0c06a3e0u; return 0; }
goto P_0c06a3e2;
P_0c06a3e2: /* original 903b, guest PC 0x0c06a3e2 */
if(!s->budget--) { s->failed_pc=0x0c06a3e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a45cu,2);
goto P_0c06a3e4;
P_0c06a3e4: /* original 05cc, guest PC 0x0c06a3e4 */
if(!s->budget--) { s->failed_pc=0x0c06a3e4u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c06a3e6;
P_0c06a3e6: /* original 903a, guest PC 0x0c06a3e6 */
if(!s->budget--) { s->failed_pc=0x0c06a3e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a45eu,2);
goto P_0c06a3e8;
P_0c06a3e8: /* original 04cc, guest PC 0x0c06a3e8 */
if(!s->budget--) { s->failed_pc=0x0c06a3e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c06a3ea;
P_0c06a3ea: /* original 6043, guest PC 0x0c06a3ea */
if(!s->budget--) { s->failed_pc=0x0c06a3eau; return 0; }
r[0]=r[4];
goto P_0c06a3ec;
P_0c06a3ec: /* original 8803, guest PC 0x0c06a3ec */
if(!s->budget--) { s->failed_pc=0x0c06a3ecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c06a3ee;
P_0c06a3ee: /* original 8d47, guest PC 0x0c06a3ee */
if(!s->budget--) { s->failed_pc=0x0c06a3eeu; return 0; }
cond=r[17]&1u;
r[8]=0x00000014u;
if(cond) { goto P_0c06a480; }
goto P_0c06a3f2;
P_0c06a3f0: /* original e814, guest PC 0x0c06a3f0 */
if(!s->budget--) { s->failed_pc=0x0c06a3f0u; return 0; }
r[8]=0x00000014u;
goto P_0c06a3f2;
P_0c06a3f2: /* original 2448, guest PC 0x0c06a3f2 */
if(!s->budget--) { s->failed_pc=0x0c06a3f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06a3f4;
P_0c06a3f4: /* original 8901, guest PC 0x0c06a3f4 */
if(!s->budget--) { s->failed_pc=0x0c06a3f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06a3fa; }
goto P_0c06a3f6;
P_0c06a3f6: /* original 3540, guest PC 0x0c06a3f6 */
if(!s->budget--) { s->failed_pc=0x0c06a3f6u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[4])!=0);
goto P_0c06a3f8;
P_0c06a3f8: /* original 8942, guest PC 0x0c06a3f8 */
if(!s->budget--) { s->failed_pc=0x0c06a3f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06a480; }
goto P_0c06a3fa;
P_0c06a3fa: /* original 64e3, guest PC 0x0c06a3fa */
if(!s->budget--) { s->failed_pc=0x0c06a3fau; return 0; }
r[4]=r[14];
goto P_0c06a3fc;
P_0c06a3fc: /* original 4b0b, guest PC 0x0c06a3fc */
if(!s->budget--) { s->failed_pc=0x0c06a3fcu; return 0; }
target=r[11];
r[16]=code_base|0x0c06a400u;
r[4]+=0x00000060u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a400u) { target=s->pc; goto dispatch; }
goto P_0c06a400;
P_0c06a3fe: /* original 7460, guest PC 0x0c06a3fe */
if(!s->budget--) { s->failed_pc=0x0c06a3feu; return 0; }
r[4]+=0x00000060u;
goto P_0c06a400;
P_0c06a400: /* original 6403, guest PC 0x0c06a400 */
if(!s->budget--) { s->failed_pc=0x0c06a400u; return 0; }
r[4]=r[0];
goto P_0c06a402;
P_0c06a402: /* original 7401, guest PC 0x0c06a402 */
if(!s->budget--) { s->failed_pc=0x0c06a402u; return 0; }
r[4]+=0x00000001u;
goto P_0c06a404;
P_0c06a404: /* original 6543, guest PC 0x0c06a404 */
if(!s->budget--) { s->failed_pc=0x0c06a404u; return 0; }
r[5]=r[4];
goto P_0c06a406;
P_0c06a406: /* original 1f41, guest PC 0x0c06a406 */
if(!s->budget--) { s->failed_pc=0x0c06a406u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c06a408;
P_0c06a408: /* original 64e3, guest PC 0x0c06a408 */
if(!s->budget--) { s->failed_pc=0x0c06a408u; return 0; }
r[4]=r[14];
goto P_0c06a40a;
P_0c06a40a: /* original 4d0b, guest PC 0x0c06a40a */
if(!s->budget--) { s->failed_pc=0x0c06a40au; return 0; }
target=r[13];
r[16]=code_base|0x0c06a40eu;
r[4]+=0x00000060u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a40eu) { target=s->pc; goto dispatch; }
goto P_0c06a40e;
P_0c06a40c: /* original 7460, guest PC 0x0c06a40c */
if(!s->budget--) { s->failed_pc=0x0c06a40cu; return 0; }
r[4]+=0x00000060u;
goto P_0c06a40e;
P_0c06a40e: /* original 9427, guest PC 0x0c06a40e */
if(!s->budget--) { s->failed_pc=0x0c06a40eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a460u,2);
goto P_0c06a410;
P_0c06a410: /* original 4b0b, guest PC 0x0c06a410 */
if(!s->budget--) { s->failed_pc=0x0c06a410u; return 0; }
target=r[11];
r[16]=code_base|0x0c06a414u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a414u) { target=s->pc; goto dispatch; }
goto P_0c06a414;
P_0c06a412: /* original 34ec, guest PC 0x0c06a412 */
if(!s->budget--) { s->failed_pc=0x0c06a412u; return 0; }
r[4]+=r[14];
goto P_0c06a414;
P_0c06a414: /* original 30ac, guest PC 0x0c06a414 */
if(!s->budget--) { s->failed_pc=0x0c06a414u; return 0; }
r[0]+=r[10];
goto P_0c06a416;
P_0c06a416: /* original 6503, guest PC 0x0c06a416 */
if(!s->budget--) { s->failed_pc=0x0c06a416u; return 0; }
r[5]=r[0];
goto P_0c06a418;
P_0c06a418: /* original 2f02, guest PC 0x0c06a418 */
if(!s->budget--) { s->failed_pc=0x0c06a418u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a41a;
P_0c06a41a: /* original 9421, guest PC 0x0c06a41a */
if(!s->budget--) { s->failed_pc=0x0c06a41au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a460u,2);
goto P_0c06a41c;
P_0c06a41c: /* original 4d0b, guest PC 0x0c06a41c */
if(!s->budget--) { s->failed_pc=0x0c06a41cu; return 0; }
target=r[13];
r[16]=code_base|0x0c06a420u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a420u) { target=s->pc; goto dispatch; }
goto P_0c06a420;
P_0c06a41e: /* original 34ec, guest PC 0x0c06a41e */
if(!s->budget--) { s->failed_pc=0x0c06a41eu; return 0; }
r[4]+=r[14];
goto P_0c06a420;
P_0c06a420: /* original d316, guest PC 0x0c06a420 */
if(!s->budget--) { s->failed_pc=0x0c06a420u; return 0; }
r[3]=read(ram,0x0c06a47cu,4);
goto P_0c06a422;
P_0c06a422: /* original 61f2, guest PC 0x0c06a422 */
if(!s->budget--) { s->failed_pc=0x0c06a422u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c06a424;
P_0c06a424: /* original 430b, guest PC 0x0c06a424 */
if(!s->budget--) { s->failed_pc=0x0c06a424u; return 0; }
target=r[3];
r[16]=code_base|0x0c06a428u;
r[0]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a428u) { target=s->pc; goto dispatch; }
goto P_0c06a428;
P_0c06a426: /* original 50f1, guest PC 0x0c06a426 */
if(!s->budget--) { s->failed_pc=0x0c06a426u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c06a428;
P_0c06a428: /* original 64e3, guest PC 0x0c06a428 */
if(!s->budget--) { s->failed_pc=0x0c06a428u; return 0; }
r[4]=r[14];
goto P_0c06a42a;
P_0c06a42a: /* original 6503, guest PC 0x0c06a42a */
if(!s->budget--) { s->failed_pc=0x0c06a42au; return 0; }
r[5]=r[0];
goto P_0c06a42c;
P_0c06a42c: /* original 2f02, guest PC 0x0c06a42c */
if(!s->budget--) { s->failed_pc=0x0c06a42cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a42e;
P_0c06a42e: /* original 4d0b, guest PC 0x0c06a42e */
if(!s->budget--) { s->failed_pc=0x0c06a42eu; return 0; }
target=r[13];
r[16]=code_base|0x0c06a432u;
r[4]+=0x00000070u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a432u) { target=s->pc; goto dispatch; }
goto P_0c06a432;
P_0c06a430: /* original 7470, guest PC 0x0c06a430 */
if(!s->budget--) { s->failed_pc=0x0c06a430u; return 0; }
r[4]+=0x00000070u;
goto P_0c06a432;
P_0c06a432: /* original d312, guest PC 0x0c06a432 */
if(!s->budget--) { s->failed_pc=0x0c06a432u; return 0; }
r[3]=read(ram,0x0c06a47cu,4);
goto P_0c06a434;
P_0c06a434: /* original 61a3, guest PC 0x0c06a434 */
if(!s->budget--) { s->failed_pc=0x0c06a434u; return 0; }
r[1]=r[10];
goto P_0c06a436;
P_0c06a436: /* original 9414, guest PC 0x0c06a436 */
if(!s->budget--) { s->failed_pc=0x0c06a436u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a462u,2);
goto P_0c06a438;
P_0c06a438: /* original 430b, guest PC 0x0c06a438 */
if(!s->budget--) { s->failed_pc=0x0c06a438u; return 0; }
target=r[3];
r[16]=code_base|0x0c06a43cu;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a43cu) { target=s->pc; goto dispatch; }
goto P_0c06a43c;
P_0c06a43a: /* original 6043, guest PC 0x0c06a43a */
if(!s->budget--) { s->failed_pc=0x0c06a43au; return 0; }
r[0]=r[4];
goto P_0c06a43c;
P_0c06a43c: /* original 3087, guest PC 0x0c06a43c */
if(!s->budget--) { s->failed_pc=0x0c06a43cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>(int32_t)r[8])!=0);
goto P_0c06a43e;
P_0c06a43e: /* original 8f01, guest PC 0x0c06a43e */
if(!s->budget--) { s->failed_pc=0x0c06a43eu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[0],4);
if(!cond) { goto P_0c06a444; }
goto P_0c06a442;
P_0c06a440: /* original 2f02, guest PC 0x0c06a440 */
if(!s->budget--) { s->failed_pc=0x0c06a440u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a442;
P_0c06a442: /* original 2f82, guest PC 0x0c06a442 */
if(!s->budget--) { s->failed_pc=0x0c06a442u; return 0; }
write(ram,r[15],r[8],4);
goto P_0c06a444;
P_0c06a444: /* original 930e, guest PC 0x0c06a444 */
if(!s->budget--) { s->failed_pc=0x0c06a444u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a464u,2);
goto P_0c06a446;
P_0c06a446: /* original 64f2, guest PC 0x0c06a446 */
if(!s->budget--) { s->failed_pc=0x0c06a446u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06a448;
P_0c06a448: /* original 33ec, guest PC 0x0c06a448 */
if(!s->budget--) { s->failed_pc=0x0c06a448u; return 0; }
r[3]+=r[14];
goto P_0c06a44a;
P_0c06a44a: /* original 4408, guest PC 0x0c06a44a */
if(!s->budget--) { s->failed_pc=0x0c06a44au; return 0; }
r[4]<<=2;
goto P_0c06a44c;
P_0c06a44c: /* original 343c, guest PC 0x0c06a44c */
if(!s->budget--) { s->failed_pc=0x0c06a44cu; return 0; }
r[4]+=r[3];
goto P_0c06a44e;
P_0c06a44e: /* original a046, guest PC 0x0c06a44e */
if(!s->budget--) { s->failed_pc=0x0c06a44eu; return 0; }
r[5]=0x00000001u;
goto P_0c06a4de;
P_0c06a450: /* original e501, guest PC 0x0c06a450 */
if(!s->budget--) { s->failed_pc=0x0c06a450u; return 0; }
r[5]=0x00000001u;
if(!vf3_matrix_family(0x0c06a452u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06a452u; return 0; } return 1;
P_0c06a480: /* original 64e3, guest PC 0x0c06a480 */
if(!s->budget--) { s->failed_pc=0x0c06a480u; return 0; }
r[4]=r[14];
goto P_0c06a482;
P_0c06a482: /* original 4b0b, guest PC 0x0c06a482 */
if(!s->budget--) { s->failed_pc=0x0c06a482u; return 0; }
target=r[11];
r[16]=code_base|0x0c06a486u;
r[4]+=0x00000064u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a486u) { target=s->pc; goto dispatch; }
goto P_0c06a486;
P_0c06a484: /* original 7464, guest PC 0x0c06a484 */
if(!s->budget--) { s->failed_pc=0x0c06a484u; return 0; }
r[4]+=0x00000064u;
goto P_0c06a486;
P_0c06a486: /* original 6403, guest PC 0x0c06a486 */
if(!s->budget--) { s->failed_pc=0x0c06a486u; return 0; }
r[4]=r[0];
goto P_0c06a488;
P_0c06a488: /* original 7401, guest PC 0x0c06a488 */
if(!s->budget--) { s->failed_pc=0x0c06a488u; return 0; }
r[4]+=0x00000001u;
goto P_0c06a48a;
P_0c06a48a: /* original 6543, guest PC 0x0c06a48a */
if(!s->budget--) { s->failed_pc=0x0c06a48au; return 0; }
r[5]=r[4];
goto P_0c06a48c;
P_0c06a48c: /* original 1f41, guest PC 0x0c06a48c */
if(!s->budget--) { s->failed_pc=0x0c06a48cu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c06a48e;
P_0c06a48e: /* original 64e3, guest PC 0x0c06a48e */
if(!s->budget--) { s->failed_pc=0x0c06a48eu; return 0; }
r[4]=r[14];
goto P_0c06a490;
P_0c06a490: /* original 4d0b, guest PC 0x0c06a490 */
if(!s->budget--) { s->failed_pc=0x0c06a490u; return 0; }
target=r[13];
r[16]=code_base|0x0c06a494u;
r[4]+=0x00000064u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a494u) { target=s->pc; goto dispatch; }
goto P_0c06a494;
P_0c06a492: /* original 7464, guest PC 0x0c06a492 */
if(!s->budget--) { s->failed_pc=0x0c06a492u; return 0; }
r[4]+=0x00000064u;
goto P_0c06a494;
P_0c06a494: /* original 9496, guest PC 0x0c06a494 */
if(!s->budget--) { s->failed_pc=0x0c06a494u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5c4u,2);
goto P_0c06a496;
P_0c06a496: /* original 55f1, guest PC 0x0c06a496 */
if(!s->budget--) { s->failed_pc=0x0c06a496u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c06a498;
P_0c06a498: /* original 4d0b, guest PC 0x0c06a498 */
if(!s->budget--) { s->failed_pc=0x0c06a498u; return 0; }
target=r[13];
r[16]=code_base|0x0c06a49cu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a49cu) { target=s->pc; goto dispatch; }
goto P_0c06a49c;
P_0c06a49a: /* original 34ec, guest PC 0x0c06a49a */
if(!s->budget--) { s->failed_pc=0x0c06a49au; return 0; }
r[4]+=r[14];
goto P_0c06a49c;
P_0c06a49c: /* original 9493, guest PC 0x0c06a49c */
if(!s->budget--) { s->failed_pc=0x0c06a49cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5c6u,2);
goto P_0c06a49e;
P_0c06a49e: /* original 4b0b, guest PC 0x0c06a49e */
if(!s->budget--) { s->failed_pc=0x0c06a49eu; return 0; }
target=r[11];
r[16]=code_base|0x0c06a4a2u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a4a2u) { target=s->pc; goto dispatch; }
goto P_0c06a4a2;
P_0c06a4a0: /* original 34ec, guest PC 0x0c06a4a0 */
if(!s->budget--) { s->failed_pc=0x0c06a4a0u; return 0; }
r[4]+=r[14];
goto P_0c06a4a2;
P_0c06a4a2: /* original 30ac, guest PC 0x0c06a4a2 */
if(!s->budget--) { s->failed_pc=0x0c06a4a2u; return 0; }
r[0]+=r[10];
goto P_0c06a4a4;
P_0c06a4a4: /* original 6503, guest PC 0x0c06a4a4 */
if(!s->budget--) { s->failed_pc=0x0c06a4a4u; return 0; }
r[5]=r[0];
goto P_0c06a4a6;
P_0c06a4a6: /* original 2f02, guest PC 0x0c06a4a6 */
if(!s->budget--) { s->failed_pc=0x0c06a4a6u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a4a8;
P_0c06a4a8: /* original 948d, guest PC 0x0c06a4a8 */
if(!s->budget--) { s->failed_pc=0x0c06a4a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5c6u,2);
goto P_0c06a4aa;
P_0c06a4aa: /* original 4d0b, guest PC 0x0c06a4aa */
if(!s->budget--) { s->failed_pc=0x0c06a4aau; return 0; }
target=r[13];
r[16]=code_base|0x0c06a4aeu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a4aeu) { target=s->pc; goto dispatch; }
goto P_0c06a4ae;
P_0c06a4ac: /* original 34ec, guest PC 0x0c06a4ac */
if(!s->budget--) { s->failed_pc=0x0c06a4acu; return 0; }
r[4]+=r[14];
goto P_0c06a4ae;
P_0c06a4ae: /* original d34b, guest PC 0x0c06a4ae */
if(!s->budget--) { s->failed_pc=0x0c06a4aeu; return 0; }
r[3]=read(ram,0x0c06a5dcu,4);
goto P_0c06a4b0;
P_0c06a4b0: /* original 61f2, guest PC 0x0c06a4b0 */
if(!s->budget--) { s->failed_pc=0x0c06a4b0u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c06a4b2;
P_0c06a4b2: /* original 430b, guest PC 0x0c06a4b2 */
if(!s->budget--) { s->failed_pc=0x0c06a4b2u; return 0; }
target=r[3];
r[16]=code_base|0x0c06a4b6u;
r[0]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a4b6u) { target=s->pc; goto dispatch; }
goto P_0c06a4b6;
P_0c06a4b4: /* original 50f1, guest PC 0x0c06a4b4 */
if(!s->budget--) { s->failed_pc=0x0c06a4b4u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c06a4b6;
P_0c06a4b6: /* original 64e3, guest PC 0x0c06a4b6 */
if(!s->budget--) { s->failed_pc=0x0c06a4b6u; return 0; }
r[4]=r[14];
goto P_0c06a4b8;
P_0c06a4b8: /* original 6503, guest PC 0x0c06a4b8 */
if(!s->budget--) { s->failed_pc=0x0c06a4b8u; return 0; }
r[5]=r[0];
goto P_0c06a4ba;
P_0c06a4ba: /* original 2f02, guest PC 0x0c06a4ba */
if(!s->budget--) { s->failed_pc=0x0c06a4bau; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a4bc;
P_0c06a4bc: /* original 4d0b, guest PC 0x0c06a4bc */
if(!s->budget--) { s->failed_pc=0x0c06a4bcu; return 0; }
target=r[13];
r[16]=code_base|0x0c06a4c0u;
r[4]+=0x00000074u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a4c0u) { target=s->pc; goto dispatch; }
goto P_0c06a4c0;
P_0c06a4be: /* original 7474, guest PC 0x0c06a4be */
if(!s->budget--) { s->failed_pc=0x0c06a4beu; return 0; }
r[4]+=0x00000074u;
goto P_0c06a4c0;
P_0c06a4c0: /* original d346, guest PC 0x0c06a4c0 */
if(!s->budget--) { s->failed_pc=0x0c06a4c0u; return 0; }
r[3]=read(ram,0x0c06a5dcu,4);
goto P_0c06a4c2;
P_0c06a4c2: /* original 61a3, guest PC 0x0c06a4c2 */
if(!s->budget--) { s->failed_pc=0x0c06a4c2u; return 0; }
r[1]=r[10];
goto P_0c06a4c4;
P_0c06a4c4: /* original 9480, guest PC 0x0c06a4c4 */
if(!s->budget--) { s->failed_pc=0x0c06a4c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5c8u,2);
goto P_0c06a4c6;
P_0c06a4c6: /* original 430b, guest PC 0x0c06a4c6 */
if(!s->budget--) { s->failed_pc=0x0c06a4c6u; return 0; }
target=r[3];
r[16]=code_base|0x0c06a4cau;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a4cau) { target=s->pc; goto dispatch; }
goto P_0c06a4ca;
P_0c06a4c8: /* original 6043, guest PC 0x0c06a4c8 */
if(!s->budget--) { s->failed_pc=0x0c06a4c8u; return 0; }
r[0]=r[4];
goto P_0c06a4ca;
P_0c06a4ca: /* original 3087, guest PC 0x0c06a4ca */
if(!s->budget--) { s->failed_pc=0x0c06a4cau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>(int32_t)r[8])!=0);
goto P_0c06a4cc;
P_0c06a4cc: /* original 8f01, guest PC 0x0c06a4cc */
if(!s->budget--) { s->failed_pc=0x0c06a4ccu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[0],4);
if(!cond) { goto P_0c06a4d2; }
goto P_0c06a4d0;
P_0c06a4ce: /* original 2f02, guest PC 0x0c06a4ce */
if(!s->budget--) { s->failed_pc=0x0c06a4ceu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a4d0;
P_0c06a4d0: /* original 2f82, guest PC 0x0c06a4d0 */
if(!s->budget--) { s->failed_pc=0x0c06a4d0u; return 0; }
write(ram,r[15],r[8],4);
goto P_0c06a4d2;
P_0c06a4d2: /* original 937a, guest PC 0x0c06a4d2 */
if(!s->budget--) { s->failed_pc=0x0c06a4d2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5cau,2);
goto P_0c06a4d4;
P_0c06a4d4: /* original e501, guest PC 0x0c06a4d4 */
if(!s->budget--) { s->failed_pc=0x0c06a4d4u; return 0; }
r[5]=0x00000001u;
goto P_0c06a4d6;
P_0c06a4d6: /* original 64f2, guest PC 0x0c06a4d6 */
if(!s->budget--) { s->failed_pc=0x0c06a4d6u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06a4d8;
P_0c06a4d8: /* original 33ec, guest PC 0x0c06a4d8 */
if(!s->budget--) { s->failed_pc=0x0c06a4d8u; return 0; }
r[3]+=r[14];
goto P_0c06a4da;
P_0c06a4da: /* original 4408, guest PC 0x0c06a4da */
if(!s->budget--) { s->failed_pc=0x0c06a4dau; return 0; }
r[4]<<=2;
goto P_0c06a4dc;
P_0c06a4dc: /* original 343c, guest PC 0x0c06a4dc */
if(!s->budget--) { s->failed_pc=0x0c06a4dcu; return 0; }
r[4]+=r[3];
goto P_0c06a4de;
P_0c06a4de: /* original b8f2, guest PC 0x0c06a4de */
if(!s->budget--) { s->failed_pc=0x0c06a4deu; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c06a4e2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a4e2u) { target=s->pc; goto dispatch; }
goto P_0c06a4e2;
P_0c06a4e0: /* original 0009, guest PC 0x0c06a4e0 */
if(!s->budget--) { s->failed_pc=0x0c06a4e0u; return 0; }
goto P_0c06a4e2;
P_0c06a4e2: /* original 9473, guest PC 0x0c06a4e2 */
if(!s->budget--) { s->failed_pc=0x0c06a4e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5ccu,2);
goto P_0c06a4e4;
P_0c06a4e4: /* original 4b0b, guest PC 0x0c06a4e4 */
if(!s->budget--) { s->failed_pc=0x0c06a4e4u; return 0; }
target=r[11];
r[16]=code_base|0x0c06a4e8u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a4e8u) { target=s->pc; goto dispatch; }
goto P_0c06a4e8;
P_0c06a4e6: /* original 34ec, guest PC 0x0c06a4e6 */
if(!s->budget--) { s->failed_pc=0x0c06a4e6u; return 0; }
r[4]+=r[14];
goto P_0c06a4e8;
P_0c06a4e8: /* original 6403, guest PC 0x0c06a4e8 */
if(!s->budget--) { s->failed_pc=0x0c06a4e8u; return 0; }
r[4]=r[0];
goto P_0c06a4ea;
P_0c06a4ea: /* original 34ac, guest PC 0x0c06a4ea */
if(!s->budget--) { s->failed_pc=0x0c06a4eau; return 0; }
r[4]+=r[10];
goto P_0c06a4ec;
P_0c06a4ec: /* original 6543, guest PC 0x0c06a4ec */
if(!s->budget--) { s->failed_pc=0x0c06a4ecu; return 0; }
r[5]=r[4];
goto P_0c06a4ee;
P_0c06a4ee: /* original 2f42, guest PC 0x0c06a4ee */
if(!s->budget--) { s->failed_pc=0x0c06a4eeu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06a4f0;
P_0c06a4f0: /* original 946c, guest PC 0x0c06a4f0 */
if(!s->budget--) { s->failed_pc=0x0c06a4f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5ccu,2);
goto P_0c06a4f2;
P_0c06a4f2: /* original 4d0b, guest PC 0x0c06a4f2 */
if(!s->budget--) { s->failed_pc=0x0c06a4f2u; return 0; }
target=r[13];
r[16]=code_base|0x0c06a4f6u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a4f6u) { target=s->pc; goto dispatch; }
goto P_0c06a4f6;
P_0c06a4f4: /* original 34ec, guest PC 0x0c06a4f4 */
if(!s->budget--) { s->failed_pc=0x0c06a4f4u; return 0; }
r[4]+=r[14];
goto P_0c06a4f6;
P_0c06a4f6: /* original 946a, guest PC 0x0c06a4f6 */
if(!s->budget--) { s->failed_pc=0x0c06a4f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5ceu,2);
goto P_0c06a4f8;
P_0c06a4f8: /* original 4b0b, guest PC 0x0c06a4f8 */
if(!s->budget--) { s->failed_pc=0x0c06a4f8u; return 0; }
target=r[11];
r[16]=code_base|0x0c06a4fcu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a4fcu) { target=s->pc; goto dispatch; }
goto P_0c06a4fc;
P_0c06a4fa: /* original 34ec, guest PC 0x0c06a4fa */
if(!s->budget--) { s->failed_pc=0x0c06a4fau; return 0; }
r[4]+=r[14];
goto P_0c06a4fc;
P_0c06a4fc: /* original 6803, guest PC 0x0c06a4fc */
if(!s->budget--) { s->failed_pc=0x0c06a4fcu; return 0; }
r[8]=r[0];
goto P_0c06a4fe;
P_0c06a4fe: /* original 9466, guest PC 0x0c06a4fe */
if(!s->budget--) { s->failed_pc=0x0c06a4feu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5ceu,2);
goto P_0c06a500;
P_0c06a500: /* original 7801, guest PC 0x0c06a500 */
if(!s->budget--) { s->failed_pc=0x0c06a500u; return 0; }
r[8]+=0x00000001u;
goto P_0c06a502;
P_0c06a502: /* original 6583, guest PC 0x0c06a502 */
if(!s->budget--) { s->failed_pc=0x0c06a502u; return 0; }
r[5]=r[8];
goto P_0c06a504;
P_0c06a504: /* original 4d0b, guest PC 0x0c06a504 */
if(!s->budget--) { s->failed_pc=0x0c06a504u; return 0; }
target=r[13];
r[16]=code_base|0x0c06a508u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a508u) { target=s->pc; goto dispatch; }
goto P_0c06a508;
P_0c06a506: /* original 34ec, guest PC 0x0c06a506 */
if(!s->budget--) { s->failed_pc=0x0c06a506u; return 0; }
r[4]+=r[14];
goto P_0c06a508;
P_0c06a508: /* original d334, guest PC 0x0c06a508 */
if(!s->budget--) { s->failed_pc=0x0c06a508u; return 0; }
r[3]=read(ram,0x0c06a5dcu,4);
goto P_0c06a50a;
P_0c06a50a: /* original 61f2, guest PC 0x0c06a50a */
if(!s->budget--) { s->failed_pc=0x0c06a50au; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c06a50c;
P_0c06a50c: /* original 430b, guest PC 0x0c06a50c */
if(!s->budget--) { s->failed_pc=0x0c06a50cu; return 0; }
target=r[3];
r[16]=code_base|0x0c06a510u;
r[0]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a510u) { target=s->pc; goto dispatch; }
goto P_0c06a510;
P_0c06a50e: /* original 6083, guest PC 0x0c06a50e */
if(!s->budget--) { s->failed_pc=0x0c06a50eu; return 0; }
r[0]=r[8];
goto P_0c06a510;
P_0c06a510: /* original 945e, guest PC 0x0c06a510 */
if(!s->budget--) { s->failed_pc=0x0c06a510u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5d0u,2);
goto P_0c06a512;
P_0c06a512: /* original 6503, guest PC 0x0c06a512 */
if(!s->budget--) { s->failed_pc=0x0c06a512u; return 0; }
r[5]=r[0];
goto P_0c06a514;
P_0c06a514: /* original 6803, guest PC 0x0c06a514 */
if(!s->budget--) { s->failed_pc=0x0c06a514u; return 0; }
r[8]=r[0];
goto P_0c06a516;
P_0c06a516: /* original 4d0b, guest PC 0x0c06a516 */
if(!s->budget--) { s->failed_pc=0x0c06a516u; return 0; }
target=r[13];
r[16]=code_base|0x0c06a51au;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a51au) { target=s->pc; goto dispatch; }
goto P_0c06a51a;
P_0c06a518: /* original 34ec, guest PC 0x0c06a518 */
if(!s->budget--) { s->failed_pc=0x0c06a518u; return 0; }
r[4]+=r[14];
goto P_0c06a51a;
P_0c06a51a: /* original 945a, guest PC 0x0c06a51a */
if(!s->budget--) { s->failed_pc=0x0c06a51au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5d2u,2);
goto P_0c06a51c;
P_0c06a51c: /* original 4b0b, guest PC 0x0c06a51c */
if(!s->budget--) { s->failed_pc=0x0c06a51cu; return 0; }
target=r[11];
r[16]=code_base|0x0c06a520u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a520u) { target=s->pc; goto dispatch; }
goto P_0c06a520;
P_0c06a51e: /* original 34ec, guest PC 0x0c06a51e */
if(!s->budget--) { s->failed_pc=0x0c06a51eu; return 0; }
r[4]+=r[14];
goto P_0c06a520;
P_0c06a520: /* original 6403, guest PC 0x0c06a520 */
if(!s->budget--) { s->failed_pc=0x0c06a520u; return 0; }
r[4]=r[0];
goto P_0c06a522;
P_0c06a522: /* original 2448, guest PC 0x0c06a522 */
if(!s->budget--) { s->failed_pc=0x0c06a522u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06a524;
P_0c06a524: /* original 8901, guest PC 0x0c06a524 */
if(!s->budget--) { s->failed_pc=0x0c06a524u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06a52a; }
goto P_0c06a526;
P_0c06a526: /* original 34a7, guest PC 0x0c06a526 */
if(!s->budget--) { s->failed_pc=0x0c06a526u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[10])!=0);
goto P_0c06a528;
P_0c06a528: /* original 8b03, guest PC 0x0c06a528 */
if(!s->budget--) { s->failed_pc=0x0c06a528u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06a532; }
goto P_0c06a52a;
P_0c06a52a: /* original 9452, guest PC 0x0c06a52a */
if(!s->budget--) { s->failed_pc=0x0c06a52au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5d2u,2);
goto P_0c06a52c;
P_0c06a52c: /* original 65a3, guest PC 0x0c06a52c */
if(!s->budget--) { s->failed_pc=0x0c06a52cu; return 0; }
r[5]=r[10];
goto P_0c06a52e;
P_0c06a52e: /* original 4d0b, guest PC 0x0c06a52e */
if(!s->budget--) { s->failed_pc=0x0c06a52eu; return 0; }
target=r[13];
r[16]=code_base|0x0c06a532u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a532u) { target=s->pc; goto dispatch; }
goto P_0c06a532;
P_0c06a530: /* original 34ec, guest PC 0x0c06a530 */
if(!s->budget--) { s->failed_pc=0x0c06a530u; return 0; }
r[4]+=r[14];
goto P_0c06a532;
P_0c06a532: /* original 944f, guest PC 0x0c06a532 */
if(!s->budget--) { s->failed_pc=0x0c06a532u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5d4u,2);
goto P_0c06a534;
P_0c06a534: /* original 4b0b, guest PC 0x0c06a534 */
if(!s->budget--) { s->failed_pc=0x0c06a534u; return 0; }
target=r[11];
r[16]=code_base|0x0c06a538u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a538u) { target=s->pc; goto dispatch; }
goto P_0c06a538;
P_0c06a536: /* original 34ec, guest PC 0x0c06a536 */
if(!s->budget--) { s->failed_pc=0x0c06a536u; return 0; }
r[4]+=r[14];
goto P_0c06a538;
P_0c06a538: /* original 6403, guest PC 0x0c06a538 */
if(!s->budget--) { s->failed_pc=0x0c06a538u; return 0; }
r[4]=r[0];
goto P_0c06a53a;
P_0c06a53a: /* original 2448, guest PC 0x0c06a53a */
if(!s->budget--) { s->failed_pc=0x0c06a53au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06a53c;
P_0c06a53c: /* original 8901, guest PC 0x0c06a53c */
if(!s->budget--) { s->failed_pc=0x0c06a53cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06a542; }
goto P_0c06a53e;
P_0c06a53e: /* original 34a3, guest PC 0x0c06a53e */
if(!s->budget--) { s->failed_pc=0x0c06a53eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[10])!=0);
goto P_0c06a540;
P_0c06a540: /* original 8903, guest PC 0x0c06a540 */
if(!s->budget--) { s->failed_pc=0x0c06a540u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06a54a; }
goto P_0c06a542;
P_0c06a542: /* original 9447, guest PC 0x0c06a542 */
if(!s->budget--) { s->failed_pc=0x0c06a542u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5d4u,2);
goto P_0c06a544;
P_0c06a544: /* original 65a3, guest PC 0x0c06a544 */
if(!s->budget--) { s->failed_pc=0x0c06a544u; return 0; }
r[5]=r[10];
goto P_0c06a546;
P_0c06a546: /* original 4d0b, guest PC 0x0c06a546 */
if(!s->budget--) { s->failed_pc=0x0c06a546u; return 0; }
target=r[13];
r[16]=code_base|0x0c06a54au;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a54au) { target=s->pc; goto dispatch; }
goto P_0c06a54a;
P_0c06a548: /* original 34ec, guest PC 0x0c06a548 */
if(!s->budget--) { s->failed_pc=0x0c06a548u; return 0; }
r[4]+=r[14];
goto P_0c06a54a;
P_0c06a54a: /* original 9044, guest PC 0x0c06a54a */
if(!s->budget--) { s->failed_pc=0x0c06a54au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5d6u,2);
goto P_0c06a54c;
P_0c06a54c: /* original 04ce, guest PC 0x0c06a54c */
if(!s->budget--) { s->failed_pc=0x0c06a54cu; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c06a54e;
P_0c06a54e: /* original 6043, guest PC 0x0c06a54e */
if(!s->budget--) { s->failed_pc=0x0c06a54eu; return 0; }
r[0]=r[4];
goto P_0c06a550;
P_0c06a550: /* original 8801, guest PC 0x0c06a550 */
if(!s->budget--) { s->failed_pc=0x0c06a550u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06a552;
P_0c06a552: /* original 8d0b, guest PC 0x0c06a552 */
if(!s->budget--) { s->failed_pc=0x0c06a552u; return 0; }
cond=r[17]&1u;
r[13]=r[9];
if(cond) { goto P_0c06a56c; }
goto P_0c06a556;
P_0c06a554: /* original 6d93, guest PC 0x0c06a554 */
if(!s->budget--) { s->failed_pc=0x0c06a554u; return 0; }
r[13]=r[9];
goto P_0c06a556;
P_0c06a556: /* original e205, guest PC 0x0c06a556 */
if(!s->budget--) { s->failed_pc=0x0c06a556u; return 0; }
r[2]=0x00000005u;
goto P_0c06a558;
P_0c06a558: /* original 3423, guest PC 0x0c06a558 */
if(!s->budget--) { s->failed_pc=0x0c06a558u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c06a55a;
P_0c06a55a: /* original 8f07, guest PC 0x0c06a55a */
if(!s->budget--) { s->failed_pc=0x0c06a55au; return 0; }
cond=r[17]&1u;
r[13]+=0x00000001u;
if(!cond) { goto P_0c06a56c; }
goto P_0c06a55e;
P_0c06a55c: /* original 7d01, guest PC 0x0c06a55c */
if(!s->budget--) { s->failed_pc=0x0c06a55cu; return 0; }
r[13]+=0x00000001u;
goto P_0c06a55e;
P_0c06a55e: /* original d31f, guest PC 0x0c06a55e */
if(!s->budget--) { s->failed_pc=0x0c06a55eu; return 0; }
r[3]=read(ram,0x0c06a5dcu,4);
goto P_0c06a560;
P_0c06a560: /* original 6143, guest PC 0x0c06a560 */
if(!s->budget--) { s->failed_pc=0x0c06a560u; return 0; }
r[1]=r[4];
goto P_0c06a562;
P_0c06a562: /* original e50a, guest PC 0x0c06a562 */
if(!s->budget--) { s->failed_pc=0x0c06a562u; return 0; }
r[5]=0x0000000au;
goto P_0c06a564;
P_0c06a564: /* original 430b, guest PC 0x0c06a564 */
if(!s->budget--) { s->failed_pc=0x0c06a564u; return 0; }
target=r[3];
r[16]=code_base|0x0c06a568u;
r[0]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a568u) { target=s->pc; goto dispatch; }
goto P_0c06a568;
P_0c06a566: /* original 6053, guest PC 0x0c06a566 */
if(!s->budget--) { s->failed_pc=0x0c06a566u; return 0; }
r[0]=r[5];
goto P_0c06a568;
P_0c06a568: /* original 6d03, guest PC 0x0c06a568 */
if(!s->budget--) { s->failed_pc=0x0c06a568u; return 0; }
r[13]=r[0];
goto P_0c06a56a;
P_0c06a56a: /* original 7d02, guest PC 0x0c06a56a */
if(!s->budget--) { s->failed_pc=0x0c06a56au; return 0; }
r[13]+=0x00000002u;
goto P_0c06a56c;
P_0c06a56c: /* original 9333, guest PC 0x0c06a56c */
if(!s->budget--) { s->failed_pc=0x0c06a56cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5d6u,2);
goto P_0c06a56e;
P_0c06a56e: /* original 64d3, guest PC 0x0c06a56e */
if(!s->budget--) { s->failed_pc=0x0c06a56eu; return 0; }
r[4]=r[13];
goto P_0c06a570;
P_0c06a570: /* original e501, guest PC 0x0c06a570 */
if(!s->budget--) { s->failed_pc=0x0c06a570u; return 0; }
r[5]=0x00000001u;
goto P_0c06a572;
P_0c06a572: /* original 33ec, guest PC 0x0c06a572 */
if(!s->budget--) { s->failed_pc=0x0c06a572u; return 0; }
r[3]+=r[14];
goto P_0c06a574;
P_0c06a574: /* original 4408, guest PC 0x0c06a574 */
if(!s->budget--) { s->failed_pc=0x0c06a574u; return 0; }
r[4]<<=2;
goto P_0c06a576;
P_0c06a576: /* original b8a6, guest PC 0x0c06a576 */
if(!s->budget--) { s->failed_pc=0x0c06a576u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c06a57au;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a57au) { target=s->pc; goto dispatch; }
goto P_0c06a57a;
P_0c06a578: /* original 343c, guest PC 0x0c06a578 */
if(!s->budget--) { s->failed_pc=0x0c06a578u; return 0; }
r[4]+=r[3];
goto P_0c06a57a;
P_0c06a57a: /* original 54c2, guest PC 0x0c06a57a */
if(!s->budget--) { s->failed_pc=0x0c06a57au; return 0; }
r[4]=read(ram,r[12]+8,4);
goto P_0c06a57c;
P_0c06a57c: /* original e304, guest PC 0x0c06a57c */
if(!s->budget--) { s->failed_pc=0x0c06a57cu; return 0; }
r[3]=0x00000004u;
goto P_0c06a57e;
P_0c06a57e: /* original 2438, guest PC 0x0c06a57e */
if(!s->budget--) { s->failed_pc=0x0c06a57eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c06a580;
P_0c06a580: /* original 8b0d, guest PC 0x0c06a580 */
if(!s->budget--) { s->failed_pc=0x0c06a580u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06a59e; }
goto P_0c06a582;
P_0c06a582: /* original e029, guest PC 0x0c06a582 */
if(!s->budget--) { s->failed_pc=0x0c06a582u; return 0; }
r[0]=0x00000029u;
goto P_0c06a584;
P_0c06a584: /* original d516, guest PC 0x0c06a584 */
if(!s->budget--) { s->failed_pc=0x0c06a584u; return 0; }
r[5]=read(ram,0x0c06a5e0u,4);
goto P_0c06a586;
P_0c06a586: /* original 06cc, guest PC 0x0c06a586 */
if(!s->budget--) { s->failed_pc=0x0c06a586u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c06a588;
P_0c06a588: /* original e01d, guest PC 0x0c06a588 */
if(!s->budget--) { s->failed_pc=0x0c06a588u; return 0; }
r[0]=0x0000001du;
goto P_0c06a58a;
P_0c06a58a: /* original 07cc, guest PC 0x0c06a58a */
if(!s->budget--) { s->failed_pc=0x0c06a58au; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c06a58c;
P_0c06a58c: /* original 666c, guest PC 0x0c06a58c */
if(!s->budget--) { s->failed_pc=0x0c06a58cu; return 0; }
r[6]=r[6]&255u;
goto P_0c06a58e;
P_0c06a58e: /* original 5454, guest PC 0x0c06a58e */
if(!s->budget--) { s->failed_pc=0x0c06a58eu; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c06a590;
P_0c06a590: /* original 6063, guest PC 0x0c06a590 */
if(!s->budget--) { s->failed_pc=0x0c06a590u; return 0; }
r[0]=r[6];
goto P_0c06a592;
P_0c06a592: /* original 8803, guest PC 0x0c06a592 */
if(!s->budget--) { s->failed_pc=0x0c06a592u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c06a594;
P_0c06a594: /* original 8d03, guest PC 0x0c06a594 */
if(!s->budget--) { s->failed_pc=0x0c06a594u; return 0; }
cond=r[17]&1u;
r[7]=r[7]&255u;
if(cond) { goto P_0c06a59e; }
goto P_0c06a598;
P_0c06a596: /* original 677c, guest PC 0x0c06a596 */
if(!s->budget--) { s->failed_pc=0x0c06a596u; return 0; }
r[7]=r[7]&255u;
goto P_0c06a598;
P_0c06a598: /* original 2778, guest PC 0x0c06a598 */
if(!s->budget--) { s->failed_pc=0x0c06a598u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c06a59a;
P_0c06a59a: /* original 8900, guest PC 0x0c06a59a */
if(!s->budget--) { s->failed_pc=0x0c06a59au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06a59e; }
goto P_0c06a59c;
P_0c06a59c: /* original 5455, guest PC 0x0c06a59c */
if(!s->budget--) { s->failed_pc=0x0c06a59cu; return 0; }
r[4]=read(ram,r[5]+20,4);
goto P_0c06a59e;
P_0c06a59e: /* original 901b, guest PC 0x0c06a59e */
if(!s->budget--) { s->failed_pc=0x0c06a59eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5d8u,2);
goto P_0c06a5a0;
P_0c06a5a0: /* original 7f08, guest PC 0x0c06a5a0 */
if(!s->budget--) { s->failed_pc=0x0c06a5a0u; return 0; }
r[15]+=0x00000008u;
goto P_0c06a5a2;
P_0c06a5a2: /* original 4f26, guest PC 0x0c06a5a2 */
if(!s->budget--) { s->failed_pc=0x0c06a5a2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06a5a4;
P_0c06a5a4: /* original 0c96, guest PC 0x0c06a5a4 */
if(!s->budget--) { s->failed_pc=0x0c06a5a4u; return 0; }
write(ram,r[12]+r[0],r[9],4);
goto P_0c06a5a6;
P_0c06a5a6: /* original 7008, guest PC 0x0c06a5a6 */
if(!s->budget--) { s->failed_pc=0x0c06a5a6u; return 0; }
r[0]+=0x00000008u;
goto P_0c06a5a8;
P_0c06a5a8: /* original 0c96, guest PC 0x0c06a5a8 */
if(!s->budget--) { s->failed_pc=0x0c06a5a8u; return 0; }
write(ram,r[12]+r[0],r[9],4);
goto P_0c06a5aa;
P_0c06a5aa: /* original e301, guest PC 0x0c06a5aa */
if(!s->budget--) { s->failed_pc=0x0c06a5aau; return 0; }
r[3]=0x00000001u;
goto P_0c06a5ac;
P_0c06a5ac: /* original 900a, guest PC 0x0c06a5ac */
if(!s->budget--) { s->failed_pc=0x0c06a5acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5c4u,2);
goto P_0c06a5ae;
P_0c06a5ae: /* original 0c96, guest PC 0x0c06a5ae */
if(!s->budget--) { s->failed_pc=0x0c06a5aeu; return 0; }
write(ram,r[12]+r[0],r[9],4);
goto P_0c06a5b0;
P_0c06a5b0: /* original 701c, guest PC 0x0c06a5b0 */
if(!s->budget--) { s->failed_pc=0x0c06a5b0u; return 0; }
r[0]+=0x0000001cu;
goto P_0c06a5b2;
P_0c06a5b2: /* original 0c36, guest PC 0x0c06a5b2 */
if(!s->budget--) { s->failed_pc=0x0c06a5b2u; return 0; }
write(ram,r[12]+r[0],r[3],4);
goto P_0c06a5b4;
P_0c06a5b4: /* original 68f6, guest PC 0x0c06a5b4 */
if(!s->budget--) { s->failed_pc=0x0c06a5b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06a5b6;
P_0c06a5b6: /* original 69f6, guest PC 0x0c06a5b6 */
if(!s->budget--) { s->failed_pc=0x0c06a5b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06a5b8;
P_0c06a5b8: /* original 6af6, guest PC 0x0c06a5b8 */
if(!s->budget--) { s->failed_pc=0x0c06a5b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06a5ba;
P_0c06a5ba: /* original 6bf6, guest PC 0x0c06a5ba */
if(!s->budget--) { s->failed_pc=0x0c06a5bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06a5bc;
P_0c06a5bc: /* original 6cf6, guest PC 0x0c06a5bc */
if(!s->budget--) { s->failed_pc=0x0c06a5bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06a5be;
P_0c06a5be: /* original 6df6, guest PC 0x0c06a5be */
if(!s->budget--) { s->failed_pc=0x0c06a5beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06a5c0;
P_0c06a5c0: /* original 000b, guest PC 0x0c06a5c0 */
if(!s->budget--) { s->failed_pc=0x0c06a5c0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06a5c2: /* original 6ef6, guest PC 0x0c06a5c2 */
if(!s->budget--) { s->failed_pc=0x0c06a5c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06a5c4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06a5c4u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
