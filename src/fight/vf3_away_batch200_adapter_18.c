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
int vf3_away_batch200_adapter_18(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0ad390u: goto P_0c0ad390;
case 0x0c0ad392u: goto P_0c0ad392;
case 0x0c0ad394u: goto P_0c0ad394;
case 0x0c0ad396u: goto P_0c0ad396;
case 0x0c0ad398u: goto P_0c0ad398;
case 0x0c0ad39au: goto P_0c0ad39a;
case 0x0c0ad39cu: goto P_0c0ad39c;
case 0x0c0ad39eu: goto P_0c0ad39e;
case 0x0c0ad3a0u: goto P_0c0ad3a0;
case 0x0c0ad3a2u: goto P_0c0ad3a2;
case 0x0c0ad3a4u: goto P_0c0ad3a4;
case 0x0c0ad3a6u: goto P_0c0ad3a6;
case 0x0c0ad3a8u: goto P_0c0ad3a8;
case 0x0c0ad3aau: goto P_0c0ad3aa;
case 0x0c0ad3acu: goto P_0c0ad3ac;
case 0x0c0ad3aeu: goto P_0c0ad3ae;
case 0x0c0ad3b0u: goto P_0c0ad3b0;
case 0x0c0ad3b2u: goto P_0c0ad3b2;
case 0x0c0ad3b4u: goto P_0c0ad3b4;
case 0x0c0ad3b6u: goto P_0c0ad3b6;
case 0x0c0ad3b8u: goto P_0c0ad3b8;
case 0x0c0ad3bau: goto P_0c0ad3ba;
case 0x0c0ad3bcu: goto P_0c0ad3bc;
case 0x0c0ad3beu: goto P_0c0ad3be;
case 0x0c0ad3c0u: goto P_0c0ad3c0;
case 0x0c0ad3c2u: goto P_0c0ad3c2;
case 0x0c0ad3c4u: goto P_0c0ad3c4;
case 0x0c0ad3c6u: goto P_0c0ad3c6;
case 0x0c0ad3c8u: goto P_0c0ad3c8;
case 0x0c0ad3cau: goto P_0c0ad3ca;
case 0x0c0ad3ccu: goto P_0c0ad3cc;
case 0x0c0ad3ceu: goto P_0c0ad3ce;
case 0x0c0ad3d0u: goto P_0c0ad3d0;
case 0x0c0ad3d2u: goto P_0c0ad3d2;
case 0x0c0ad3d4u: goto P_0c0ad3d4;
case 0x0c0ad3d6u: goto P_0c0ad3d6;
case 0x0c0ad3d8u: goto P_0c0ad3d8;
case 0x0c0ad3dau: goto P_0c0ad3da;
case 0x0c0ad3dcu: goto P_0c0ad3dc;
case 0x0c0ad3deu: goto P_0c0ad3de;
case 0x0c0ad3e0u: goto P_0c0ad3e0;
case 0x0c0ad3e2u: goto P_0c0ad3e2;
case 0x0c0ad3e4u: goto P_0c0ad3e4;
case 0x0c0ad3e6u: goto P_0c0ad3e6;
case 0x0c0ad3e8u: goto P_0c0ad3e8;
case 0x0c0ad3eau: goto P_0c0ad3ea;
case 0x0c0ad3ecu: goto P_0c0ad3ec;
case 0x0c0ad3eeu: goto P_0c0ad3ee;
case 0x0c0ad3f0u: goto P_0c0ad3f0;
case 0x0c0ad3f2u: goto P_0c0ad3f2;
case 0x0c0ad3f4u: goto P_0c0ad3f4;
case 0x0c0ad3f6u: goto P_0c0ad3f6;
case 0x0c0ad3f8u: goto P_0c0ad3f8;
case 0x0c0ad3fau: goto P_0c0ad3fa;
case 0x0c0ad3fcu: goto P_0c0ad3fc;
case 0x0c0ad3feu: goto P_0c0ad3fe;
case 0x0c0ad400u: goto P_0c0ad400;
case 0x0c0ad402u: goto P_0c0ad402;
case 0x0c0ad404u: goto P_0c0ad404;
case 0x0c0ad406u: goto P_0c0ad406;
case 0x0c0ad408u: goto P_0c0ad408;
case 0x0c0ad40au: goto P_0c0ad40a;
case 0x0c0ad40cu: goto P_0c0ad40c;
case 0x0c0ad40eu: goto P_0c0ad40e;
case 0x0c0ad410u: goto P_0c0ad410;
case 0x0c0ad412u: goto P_0c0ad412;
case 0x0c0ad414u: goto P_0c0ad414;
case 0x0c0ad416u: goto P_0c0ad416;
case 0x0c0ad418u: goto P_0c0ad418;
case 0x0c0ad41au: goto P_0c0ad41a;
case 0x0c0ad41cu: goto P_0c0ad41c;
case 0x0c0ad41eu: goto P_0c0ad41e;
case 0x0c0ad420u: goto P_0c0ad420;
case 0x0c0ad422u: goto P_0c0ad422;
case 0x0c0ad424u: goto P_0c0ad424;
case 0x0c0ad426u: goto P_0c0ad426;
case 0x0c0ad428u: goto P_0c0ad428;
case 0x0c0ad42au: goto P_0c0ad42a;
case 0x0c0ad42cu: goto P_0c0ad42c;
case 0x0c0ad42eu: goto P_0c0ad42e;
case 0x0c0ad430u: goto P_0c0ad430;
case 0x0c0ad432u: goto P_0c0ad432;
case 0x0c0ad434u: goto P_0c0ad434;
case 0x0c0ad436u: goto P_0c0ad436;
case 0x0c0ad438u: goto P_0c0ad438;
case 0x0c0ad43au: goto P_0c0ad43a;
case 0x0c0ad43cu: goto P_0c0ad43c;
case 0x0c0ad43eu: goto P_0c0ad43e;
case 0x0c0ad440u: goto P_0c0ad440;
case 0x0c0ad442u: goto P_0c0ad442;
case 0x0c0ad444u: goto P_0c0ad444;
case 0x0c0ad446u: goto P_0c0ad446;
case 0x0c0ad448u: goto P_0c0ad448;
case 0x0c0ad44au: goto P_0c0ad44a;
case 0x0c0ad44cu: goto P_0c0ad44c;
case 0x0c0ad44eu: goto P_0c0ad44e;
case 0x0c0ad450u: goto P_0c0ad450;
case 0x0c0ad452u: goto P_0c0ad452;
case 0x0c0ad454u: goto P_0c0ad454;
case 0x0c0ad456u: goto P_0c0ad456;
case 0x0c0ad458u: goto P_0c0ad458;
case 0x0c0ad45au: goto P_0c0ad45a;
case 0x0c0ad45cu: goto P_0c0ad45c;
case 0x0c0ad45eu: goto P_0c0ad45e;
case 0x0c0ad460u: goto P_0c0ad460;
case 0x0c0ad462u: goto P_0c0ad462;
case 0x0c0ad464u: goto P_0c0ad464;
case 0x0c0ad466u: goto P_0c0ad466;
case 0x0c0ad468u: goto P_0c0ad468;
case 0x0c0ad46au: goto P_0c0ad46a;
case 0x0c0ad46cu: goto P_0c0ad46c;
case 0x0c0ad46eu: goto P_0c0ad46e;
case 0x0c0ad470u: goto P_0c0ad470;
case 0x0c0ad472u: goto P_0c0ad472;
case 0x0c0ad474u: goto P_0c0ad474;
case 0x0c0ad476u: goto P_0c0ad476;
case 0x0c0ad478u: goto P_0c0ad478;
case 0x0c0ad47au: goto P_0c0ad47a;
case 0x0c0ad47cu: goto P_0c0ad47c;
case 0x0c0ad47eu: goto P_0c0ad47e;
case 0x0c0ad480u: goto P_0c0ad480;
case 0x0c0ad482u: goto P_0c0ad482;
case 0x0c0ad484u: goto P_0c0ad484;
case 0x0c0ad486u: goto P_0c0ad486;
case 0x0c0ad488u: goto P_0c0ad488;
case 0x0c0ad48au: goto P_0c0ad48a;
case 0x0c0ad48cu: goto P_0c0ad48c;
case 0x0c0ad48eu: goto P_0c0ad48e;
case 0x0c0ad490u: goto P_0c0ad490;
case 0x0c0ad492u: goto P_0c0ad492;
case 0x0c0ad494u: goto P_0c0ad494;
case 0x0c0ad496u: goto P_0c0ad496;
case 0x0c0ad498u: goto P_0c0ad498;
case 0x0c0ad49au: goto P_0c0ad49a;
case 0x0c0ad49cu: goto P_0c0ad49c;
case 0x0c0ad49eu: goto P_0c0ad49e;
case 0x0c0ad4a0u: goto P_0c0ad4a0;
case 0x0c0ad4a2u: goto P_0c0ad4a2;
case 0x0c0ad4a4u: goto P_0c0ad4a4;
case 0x0c0ad4a6u: goto P_0c0ad4a6;
case 0x0c0ad4a8u: goto P_0c0ad4a8;
case 0x0c0ad4aau: goto P_0c0ad4aa;
case 0x0c0ad4acu: goto P_0c0ad4ac;
case 0x0c0ad4aeu: goto P_0c0ad4ae;
case 0x0c0ad4b0u: goto P_0c0ad4b0;
case 0x0c0ad4b2u: goto P_0c0ad4b2;
case 0x0c0ad4b4u: goto P_0c0ad4b4;
case 0x0c0ad4b6u: goto P_0c0ad4b6;
case 0x0c0ad4b8u: goto P_0c0ad4b8;
case 0x0c0ad4bau: goto P_0c0ad4ba;
case 0x0c0ad4bcu: goto P_0c0ad4bc;
case 0x0c0ad4beu: goto P_0c0ad4be;
case 0x0c0ad4c0u: goto P_0c0ad4c0;
case 0x0c0ad4c2u: goto P_0c0ad4c2;
case 0x0c0ad4c4u: goto P_0c0ad4c4;
case 0x0c0ad4c6u: goto P_0c0ad4c6;
case 0x0c0ad4c8u: goto P_0c0ad4c8;
case 0x0c0ad4cau: goto P_0c0ad4ca;
case 0x0c0ad4ccu: goto P_0c0ad4cc;
case 0x0c0ad4ceu: goto P_0c0ad4ce;
case 0x0c0ad4d0u: goto P_0c0ad4d0;
case 0x0c0ad4d2u: goto P_0c0ad4d2;
case 0x0c0ad4d4u: goto P_0c0ad4d4;
case 0x0c0ad4d6u: goto P_0c0ad4d6;
case 0x0c0ad4d8u: goto P_0c0ad4d8;
case 0x0c0ad4dau: goto P_0c0ad4da;
case 0x0c0ad4dcu: goto P_0c0ad4dc;
case 0x0c0ad524u: goto P_0c0ad524;
case 0x0c0ad526u: goto P_0c0ad526;
case 0x0c0ad528u: goto P_0c0ad528;
case 0x0c0ad52au: goto P_0c0ad52a;
case 0x0c0ad52cu: goto P_0c0ad52c;
case 0x0c0ad52eu: goto P_0c0ad52e;
case 0x0c0ad530u: goto P_0c0ad530;
case 0x0c0ad532u: goto P_0c0ad532;
case 0x0c0ad534u: goto P_0c0ad534;
case 0x0c0ad536u: goto P_0c0ad536;
case 0x0c0ad538u: goto P_0c0ad538;
case 0x0c0ad53au: goto P_0c0ad53a;
case 0x0c0ad53cu: goto P_0c0ad53c;
case 0x0c0ad53eu: goto P_0c0ad53e;
case 0x0c0ad540u: goto P_0c0ad540;
case 0x0c0ad542u: goto P_0c0ad542;
case 0x0c0ad544u: goto P_0c0ad544;
case 0x0c0ad546u: goto P_0c0ad546;
case 0x0c0ad548u: goto P_0c0ad548;
case 0x0c0ad54au: goto P_0c0ad54a;
case 0x0c0ad54cu: goto P_0c0ad54c;
case 0x0c0ad54eu: goto P_0c0ad54e;
case 0x0c0ad550u: goto P_0c0ad550;
case 0x0c0ad552u: goto P_0c0ad552;
case 0x0c0ad554u: goto P_0c0ad554;
case 0x0c0ad556u: goto P_0c0ad556;
case 0x0c0ad558u: goto P_0c0ad558;
case 0x0c0ad55au: goto P_0c0ad55a;
case 0x0c0ad55cu: goto P_0c0ad55c;
case 0x0c0ad55eu: goto P_0c0ad55e;
case 0x0c0ad560u: goto P_0c0ad560;
case 0x0c0ad562u: goto P_0c0ad562;
case 0x0c0ad564u: goto P_0c0ad564;
case 0x0c0ad566u: goto P_0c0ad566;
case 0x0c0ad568u: goto P_0c0ad568;
case 0x0c0ad56au: goto P_0c0ad56a;
case 0x0c0ad56cu: goto P_0c0ad56c;
case 0x0c0ad56eu: goto P_0c0ad56e;
case 0x0c0ad570u: goto P_0c0ad570;
case 0x0c0ad572u: goto P_0c0ad572;
case 0x0c0ad574u: goto P_0c0ad574;
case 0x0c0ad576u: goto P_0c0ad576;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0ad390: /* original 2fe6, guest PC 0x0c0ad390 */
if(!s->budget--) { s->failed_pc=0x0c0ad390u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad392;
P_0c0ad392: /* original e700, guest PC 0x0c0ad392 */
if(!s->budget--) { s->failed_pc=0x0c0ad392u; return 0; }
r[7]=0x00000000u;
goto P_0c0ad394;
P_0c0ad394: /* original 2fd6, guest PC 0x0c0ad394 */
if(!s->budget--) { s->failed_pc=0x0c0ad394u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad396;
P_0c0ad396: /* original 2fc6, guest PC 0x0c0ad396 */
if(!s->budget--) { s->failed_pc=0x0c0ad396u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad398;
P_0c0ad398: /* original dd5a, guest PC 0x0c0ad398 */
if(!s->budget--) { s->failed_pc=0x0c0ad398u; return 0; }
r[13]=read(ram,0x0c0ad504u,4);
goto P_0c0ad39a;
P_0c0ad39a: /* original 7ff8, guest PC 0x0c0ad39a */
if(!s->budget--) { s->failed_pc=0x0c0ad39au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0ad39c;
P_0c0ad39c: /* original 909f, guest PC 0x0c0ad39c */
if(!s->budget--) { s->failed_pc=0x0c0ad39cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4deu,2);
goto P_0c0ad39e;
P_0c0ad39e: /* original 0ede, guest PC 0x0c0ad39e */
if(!s->budget--) { s->failed_pc=0x0c0ad39eu; return 0; }
r[14]=read(ram,r[13]+r[0],4);
goto P_0c0ad3a0;
P_0c0ad3a0: /* original 70fc, guest PC 0x0c0ad3a0 */
if(!s->budget--) { s->failed_pc=0x0c0ad3a0u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0ad3a2;
P_0c0ad3a2: /* original 0cde, guest PC 0x0c0ad3a2 */
if(!s->budget--) { s->failed_pc=0x0c0ad3a2u; return 0; }
r[12]=read(ram,r[13]+r[0],4);
goto P_0c0ad3a4;
P_0c0ad3a4: /* original 909c, guest PC 0x0c0ad3a4 */
if(!s->budget--) { s->failed_pc=0x0c0ad3a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4e0u,2);
goto P_0c0ad3a6;
P_0c0ad3a6: /* original 0475, guest PC 0x0c0ad3a6 */
if(!s->budget--) { s->failed_pc=0x0c0ad3a6u; return 0; }
write(ram,r[4]+r[0],r[7],2);
goto P_0c0ad3a8;
P_0c0ad3a8: /* original 7028, guest PC 0x0c0ad3a8 */
if(!s->budget--) { s->failed_pc=0x0c0ad3a8u; return 0; }
r[0]+=0x00000028u;
goto P_0c0ad3aa;
P_0c0ad3aa: /* original 0475, guest PC 0x0c0ad3aa */
if(!s->budget--) { s->failed_pc=0x0c0ad3aau; return 0; }
write(ram,r[4]+r[0],r[7],2);
goto P_0c0ad3ac;
P_0c0ad3ac: /* original e063, guest PC 0x0c0ad3ac */
if(!s->budget--) { s->failed_pc=0x0c0ad3acu; return 0; }
r[0]=0x00000063u;
goto P_0c0ad3ae;
P_0c0ad3ae: /* original 0474, guest PC 0x0c0ad3ae */
if(!s->budget--) { s->failed_pc=0x0c0ad3aeu; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c0ad3b0;
P_0c0ad3b0: /* original 9097, guest PC 0x0c0ad3b0 */
if(!s->budget--) { s->failed_pc=0x0c0ad3b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4e2u,2);
goto P_0c0ad3b2;
P_0c0ad3b2: /* original 0475, guest PC 0x0c0ad3b2 */
if(!s->budget--) { s->failed_pc=0x0c0ad3b2u; return 0; }
write(ram,r[4]+r[0],r[7],2);
goto P_0c0ad3b4;
P_0c0ad3b4: /* original 7022, guest PC 0x0c0ad3b4 */
if(!s->budget--) { s->failed_pc=0x0c0ad3b4u; return 0; }
r[0]+=0x00000022u;
goto P_0c0ad3b6;
P_0c0ad3b6: /* original 0476, guest PC 0x0c0ad3b6 */
if(!s->budget--) { s->failed_pc=0x0c0ad3b6u; return 0; }
write(ram,r[4]+r[0],r[7],4);
goto P_0c0ad3b8;
P_0c0ad3b8: /* original 702c, guest PC 0x0c0ad3b8 */
if(!s->budget--) { s->failed_pc=0x0c0ad3b8u; return 0; }
r[0]+=0x0000002cu;
goto P_0c0ad3ba;
P_0c0ad3ba: /* original 0474, guest PC 0x0c0ad3ba */
if(!s->budget--) { s->failed_pc=0x0c0ad3bau; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c0ad3bc;
P_0c0ad3bc: /* original 7001, guest PC 0x0c0ad3bc */
if(!s->budget--) { s->failed_pc=0x0c0ad3bcu; return 0; }
r[0]+=0x00000001u;
goto P_0c0ad3be;
P_0c0ad3be: /* original 0474, guest PC 0x0c0ad3be */
if(!s->budget--) { s->failed_pc=0x0c0ad3beu; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c0ad3c0;
P_0c0ad3c0: /* original 701b, guest PC 0x0c0ad3c0 */
if(!s->budget--) { s->failed_pc=0x0c0ad3c0u; return 0; }
r[0]+=0x0000001bu;
goto P_0c0ad3c2;
P_0c0ad3c2: /* original f48d, guest PC 0x0c0ad3c2 */
if(!s->budget--) { s->failed_pc=0x0c0ad3c2u; return 0; }
fr[4]=0;
goto P_0c0ad3c4;
P_0c0ad3c4: /* original f447, guest PC 0x0c0ad3c4 */
if(!s->budget--) { s->failed_pc=0x0c0ad3c4u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0ad3c6;
P_0c0ad3c6: /* original 908d, guest PC 0x0c0ad3c6 */
if(!s->budget--) { s->failed_pc=0x0c0ad3c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4e4u,2);
goto P_0c0ad3c8;
P_0c0ad3c8: /* original f447, guest PC 0x0c0ad3c8 */
if(!s->budget--) { s->failed_pc=0x0c0ad3c8u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0ad3ca;
P_0c0ad3ca: /* original 908c, guest PC 0x0c0ad3ca */
if(!s->budget--) { s->failed_pc=0x0c0ad3cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4e6u,2);
goto P_0c0ad3cc;
P_0c0ad3cc: /* original 0474, guest PC 0x0c0ad3cc */
if(!s->budget--) { s->failed_pc=0x0c0ad3ccu; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c0ad3ce;
P_0c0ad3ce: /* original 908b, guest PC 0x0c0ad3ce */
if(!s->budget--) { s->failed_pc=0x0c0ad3ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4e8u,2);
goto P_0c0ad3d0;
P_0c0ad3d0: /* original 2668, guest PC 0x0c0ad3d0 */
if(!s->budget--) { s->failed_pc=0x0c0ad3d0u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0ad3d2;
P_0c0ad3d2: /* original 8f02, guest PC 0x0c0ad3d2 */
if(!s->budget--) { s->failed_pc=0x0c0ad3d2u; return 0; }
cond=r[17]&1u;
write(ram,r[4]+r[0],r[7],1);
if(!cond) { goto P_0c0ad3da; }
goto P_0c0ad3d6;
P_0c0ad3d4: /* original 0474, guest PC 0x0c0ad3d4 */
if(!s->budget--) { s->failed_pc=0x0c0ad3d4u; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c0ad3d6;
P_0c0ad3d6: /* original a0ca, guest PC 0x0c0ad3d6 */
if(!s->budget--) { s->failed_pc=0x0c0ad3d6u; return 0; }
goto P_0c0ad56e;
P_0c0ad3d8: /* original 0009, guest PC 0x0c0ad3d8 */
if(!s->budget--) { s->failed_pc=0x0c0ad3d8u; return 0; }
goto P_0c0ad3da;
P_0c0ad3da: /* original 6263, guest PC 0x0c0ad3da */
if(!s->budget--) { s->failed_pc=0x0c0ad3dau; return 0; }
r[2]=r[6];
goto P_0c0ad3dc;
P_0c0ad3dc: /* original 72ff, guest PC 0x0c0ad3dc */
if(!s->budget--) { s->failed_pc=0x0c0ad3dcu; return 0; }
r[2]+=0xffffffffu;
goto P_0c0ad3de;
P_0c0ad3de: /* original 6323, guest PC 0x0c0ad3de */
if(!s->budget--) { s->failed_pc=0x0c0ad3deu; return 0; }
r[3]=r[2];
goto P_0c0ad3e0;
P_0c0ad3e0: /* original 4200, guest PC 0x0c0ad3e0 */
if(!s->budget--) { s->failed_pc=0x0c0ad3e0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0ad3e2;
P_0c0ad3e2: /* original 323c, guest PC 0x0c0ad3e2 */
if(!s->budget--) { s->failed_pc=0x0c0ad3e2u; return 0; }
r[2]+=r[3];
goto P_0c0ad3e4;
P_0c0ad3e4: /* original 4208, guest PC 0x0c0ad3e4 */
if(!s->budget--) { s->failed_pc=0x0c0ad3e4u; return 0; }
r[2]<<=2;
goto P_0c0ad3e6;
P_0c0ad3e6: /* original 32ec, guest PC 0x0c0ad3e6 */
if(!s->budget--) { s->failed_pc=0x0c0ad3e6u; return 0; }
r[2]+=r[14];
goto P_0c0ad3e8;
P_0c0ad3e8: /* original 6122, guest PC 0x0c0ad3e8 */
if(!s->budget--) { s->failed_pc=0x0c0ad3e8u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0ad3ea;
P_0c0ad3ea: /* original 2118, guest PC 0x0c0ad3ea */
if(!s->budget--) { s->failed_pc=0x0c0ad3eau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0ad3ec;
P_0c0ad3ec: /* original 8b07, guest PC 0x0c0ad3ec */
if(!s->budget--) { s->failed_pc=0x0c0ad3ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ad3fe; }
goto P_0c0ad3ee;
P_0c0ad3ee: /* original e054, guest PC 0x0c0ad3ee */
if(!s->budget--) { s->failed_pc=0x0c0ad3eeu; return 0; }
r[0]=0x00000054u;
goto P_0c0ad3f0;
P_0c0ad3f0: /* original d245, guest PC 0x0c0ad3f0 */
if(!s->budget--) { s->failed_pc=0x0c0ad3f0u; return 0; }
r[2]=read(ram,0x0c0ad508u,4);
goto P_0c0ad3f2;
P_0c0ad3f2: /* original 064e, guest PC 0x0c0ad3f2 */
if(!s->budget--) { s->failed_pc=0x0c0ad3f2u; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c0ad3f4;
P_0c0ad3f4: /* original e03c, guest PC 0x0c0ad3f4 */
if(!s->budget--) { s->failed_pc=0x0c0ad3f4u; return 0; }
r[0]=0x0000003cu;
goto P_0c0ad3f6;
P_0c0ad3f6: /* original 5362, guest PC 0x0c0ad3f6 */
if(!s->budget--) { s->failed_pc=0x0c0ad3f6u; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c0ad3f8;
P_0c0ad3f8: /* original 6631, guest PC 0x0c0ad3f8 */
if(!s->budget--) { s->failed_pc=0x0c0ad3f8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[6]=tmp;
goto P_0c0ad3fa;
P_0c0ad3fa: /* original 142e, guest PC 0x0c0ad3fa */
if(!s->budget--) { s->failed_pc=0x0c0ad3fau; return 0; }
write(ram,r[4]+56,r[2],4);
goto P_0c0ad3fc;
P_0c0ad3fc: /* original 0465, guest PC 0x0c0ad3fc */
if(!s->budget--) { s->failed_pc=0x0c0ad3fcu; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c0ad3fe;
P_0c0ad3fe: /* original 9074, guest PC 0x0c0ad3fe */
if(!s->budget--) { s->failed_pc=0x0c0ad3feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4eau,2);
goto P_0c0ad400;
P_0c0ad400: /* original f447, guest PC 0x0c0ad400 */
if(!s->budget--) { s->failed_pc=0x0c0ad400u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0ad402;
P_0c0ad402: /* original 6063, guest PC 0x0c0ad402 */
if(!s->budget--) { s->failed_pc=0x0c0ad402u; return 0; }
r[0]=r[6];
goto P_0c0ad404;
P_0c0ad404: /* original 70ff, guest PC 0x0c0ad404 */
if(!s->budget--) { s->failed_pc=0x0c0ad404u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0ad406;
P_0c0ad406: /* original 2f02, guest PC 0x0c0ad406 */
if(!s->budget--) { s->failed_pc=0x0c0ad406u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0ad408;
P_0c0ad408: /* original 4008, guest PC 0x0c0ad408 */
if(!s->budget--) { s->failed_pc=0x0c0ad408u; return 0; }
r[0]<<=2;
goto P_0c0ad40a;
P_0c0ad40a: /* original 63f2, guest PC 0x0c0ad40a */
if(!s->budget--) { s->failed_pc=0x0c0ad40au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0ad40c;
P_0c0ad40c: /* original 07ce, guest PC 0x0c0ad40c */
if(!s->budget--) { s->failed_pc=0x0c0ad40cu; return 0; }
r[7]=read(ram,r[12]+r[0],4);
goto P_0c0ad40e;
P_0c0ad40e: /* original 6233, guest PC 0x0c0ad40e */
if(!s->budget--) { s->failed_pc=0x0c0ad40eu; return 0; }
r[2]=r[3];
goto P_0c0ad410;
P_0c0ad410: /* original 4300, guest PC 0x0c0ad410 */
if(!s->budget--) { s->failed_pc=0x0c0ad410u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0ad412;
P_0c0ad412: /* original 332c, guest PC 0x0c0ad412 */
if(!s->budget--) { s->failed_pc=0x0c0ad412u; return 0; }
r[3]+=r[2];
goto P_0c0ad414;
P_0c0ad414: /* original 4308, guest PC 0x0c0ad414 */
if(!s->budget--) { s->failed_pc=0x0c0ad414u; return 0; }
r[3]<<=2;
goto P_0c0ad416;
P_0c0ad416: /* original 33ec, guest PC 0x0c0ad416 */
if(!s->budget--) { s->failed_pc=0x0c0ad416u; return 0; }
r[3]+=r[14];
goto P_0c0ad418;
P_0c0ad418: /* original 6232, guest PC 0x0c0ad418 */
if(!s->budget--) { s->failed_pc=0x0c0ad418u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0ad41a;
P_0c0ad41a: /* original 37cc, guest PC 0x0c0ad41a */
if(!s->budget--) { s->failed_pc=0x0c0ad41au; return 0; }
r[7]+=r[12];
goto P_0c0ad41c;
P_0c0ad41c: /* original dc3b, guest PC 0x0c0ad41c */
if(!s->budget--) { s->failed_pc=0x0c0ad41cu; return 0; }
r[12]=read(ram,0x0c0ad50cu,4);
goto P_0c0ad41e;
P_0c0ad41e: /* original 32ec, guest PC 0x0c0ad41e */
if(!s->budget--) { s->failed_pc=0x0c0ad41eu; return 0; }
r[2]+=r[14];
goto P_0c0ad420;
P_0c0ad420: /* original 1f21, guest PC 0x0c0ad420 */
if(!s->budget--) { s->failed_pc=0x0c0ad420u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0ad422;
P_0c0ad422: /* original 8421, guest PC 0x0c0ad422 */
if(!s->budget--) { s->failed_pc=0x0c0ad422u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+1,1);
goto P_0c0ad424;
P_0c0ad424: /* original 6320, guest PC 0x0c0ad424 */
if(!s->budget--) { s->failed_pc=0x0c0ad424u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c0ad426;
P_0c0ad426: /* original 600c, guest PC 0x0c0ad426 */
if(!s->budget--) { s->failed_pc=0x0c0ad426u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad428;
P_0c0ad428: /* original 9160, guest PC 0x0c0ad428 */
if(!s->budget--) { s->failed_pc=0x0c0ad428u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4ecu,2);
goto P_0c0ad42a;
P_0c0ad42a: /* original 4018, guest PC 0x0c0ad42a */
if(!s->budget--) { s->failed_pc=0x0c0ad42au; return 0; }
r[0]<<=8;
goto P_0c0ad42c;
P_0c0ad42c: /* original 20c9, guest PC 0x0c0ad42c */
if(!s->budget--) { s->failed_pc=0x0c0ad42cu; return 0; }
r[0]&=r[12];
goto P_0c0ad42e;
P_0c0ad42e: /* original 6e03, guest PC 0x0c0ad42e */
if(!s->budget--) { s->failed_pc=0x0c0ad42eu; return 0; }
r[14]=r[0];
goto P_0c0ad430;
P_0c0ad430: /* original 905d, guest PC 0x0c0ad430 */
if(!s->budget--) { s->failed_pc=0x0c0ad430u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4eeu,2);
goto P_0c0ad432;
P_0c0ad432: /* original 633c, guest PC 0x0c0ad432 */
if(!s->budget--) { s->failed_pc=0x0c0ad432u; return 0; }
r[3]=r[3]&255u;
goto P_0c0ad434;
P_0c0ad434: /* original 2e3b, guest PC 0x0c0ad434 */
if(!s->budget--) { s->failed_pc=0x0c0ad434u; return 0; }
r[14]|=r[3];
goto P_0c0ad436;
P_0c0ad436: /* original 034d, guest PC 0x0c0ad436 */
if(!s->budget--) { s->failed_pc=0x0c0ad436u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0ad438;
P_0c0ad438: /* original 905a, guest PC 0x0c0ad438 */
if(!s->budget--) { s->failed_pc=0x0c0ad438u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4f0u,2);
goto P_0c0ad43a;
P_0c0ad43a: /* original 2e19, guest PC 0x0c0ad43a */
if(!s->budget--) { s->failed_pc=0x0c0ad43au; return 0; }
r[14]&=r[1];
goto P_0c0ad43c;
P_0c0ad43c: /* original 0435, guest PC 0x0c0ad43c */
if(!s->budget--) { s->failed_pc=0x0c0ad43cu; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c0ad43e;
P_0c0ad43e: /* original 9058, guest PC 0x0c0ad43e */
if(!s->budget--) { s->failed_pc=0x0c0ad43eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4f2u,2);
goto P_0c0ad440;
P_0c0ad440: /* original 04e5, guest PC 0x0c0ad440 */
if(!s->budget--) { s->failed_pc=0x0c0ad440u; return 0; }
write(ram,r[4]+r[0],r[14],2);
goto P_0c0ad442;
P_0c0ad442: /* original 700e, guest PC 0x0c0ad442 */
if(!s->budget--) { s->failed_pc=0x0c0ad442u; return 0; }
r[0]+=0x0000000eu;
goto P_0c0ad444;
P_0c0ad444: /* original 04e5, guest PC 0x0c0ad444 */
if(!s->budget--) { s->failed_pc=0x0c0ad444u; return 0; }
write(ram,r[4]+r[0],r[14],2);
goto P_0c0ad446;
P_0c0ad446: /* original 7002, guest PC 0x0c0ad446 */
if(!s->budget--) { s->failed_pc=0x0c0ad446u; return 0; }
r[0]+=0x00000002u;
goto P_0c0ad448;
P_0c0ad448: /* original 04e5, guest PC 0x0c0ad448 */
if(!s->budget--) { s->failed_pc=0x0c0ad448u; return 0; }
write(ram,r[4]+r[0],r[14],2);
goto P_0c0ad44a;
P_0c0ad44a: /* original 70f4, guest PC 0x0c0ad44a */
if(!s->budget--) { s->failed_pc=0x0c0ad44au; return 0; }
r[0]+=0xfffffff4u;
goto P_0c0ad44c;
P_0c0ad44c: /* original 034e, guest PC 0x0c0ad44c */
if(!s->budget--) { s->failed_pc=0x0c0ad44cu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0ad44e;
P_0c0ad44e: /* original 9051, guest PC 0x0c0ad44e */
if(!s->budget--) { s->failed_pc=0x0c0ad44eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4f4u,2);
goto P_0c0ad450;
P_0c0ad450: /* original 0436, guest PC 0x0c0ad450 */
if(!s->budget--) { s->failed_pc=0x0c0ad450u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c0ad452;
P_0c0ad452: /* original 8473, guest PC 0x0c0ad452 */
if(!s->budget--) { s->failed_pc=0x0c0ad452u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+3,1);
goto P_0c0ad454;
P_0c0ad454: /* original de2e, guest PC 0x0c0ad454 */
if(!s->budget--) { s->failed_pc=0x0c0ad454u; return 0; }
r[14]=read(ram,0x0c0ad510u,4);
goto P_0c0ad456;
P_0c0ad456: /* original 600c, guest PC 0x0c0ad456 */
if(!s->budget--) { s->failed_pc=0x0c0ad456u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad458;
P_0c0ad458: /* original d32e, guest PC 0x0c0ad458 */
if(!s->budget--) { s->failed_pc=0x0c0ad458u; return 0; }
r[3]=read(ram,0x0c0ad514u,4);
goto P_0c0ad45a;
P_0c0ad45a: /* original 4028, guest PC 0x0c0ad45a */
if(!s->budget--) { s->failed_pc=0x0c0ad45au; return 0; }
r[0]<<=16;
goto P_0c0ad45c;
P_0c0ad45c: /* original 6270, guest PC 0x0c0ad45c */
if(!s->budget--) { s->failed_pc=0x0c0ad45cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[2]=tmp;
goto P_0c0ad45e;
P_0c0ad45e: /* original 4018, guest PC 0x0c0ad45e */
if(!s->budget--) { s->failed_pc=0x0c0ad45eu; return 0; }
r[0]<<=8;
goto P_0c0ad460;
P_0c0ad460: /* original 2e09, guest PC 0x0c0ad460 */
if(!s->budget--) { s->failed_pc=0x0c0ad460u; return 0; }
r[14]&=r[0];
goto P_0c0ad462;
P_0c0ad462: /* original 8472, guest PC 0x0c0ad462 */
if(!s->budget--) { s->failed_pc=0x0c0ad462u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+2,1);
goto P_0c0ad464;
P_0c0ad464: /* original 622c, guest PC 0x0c0ad464 */
if(!s->budget--) { s->failed_pc=0x0c0ad464u; return 0; }
r[2]=r[2]&255u;
goto P_0c0ad466;
P_0c0ad466: /* original 600c, guest PC 0x0c0ad466 */
if(!s->budget--) { s->failed_pc=0x0c0ad466u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad468;
P_0c0ad468: /* original 4028, guest PC 0x0c0ad468 */
if(!s->budget--) { s->failed_pc=0x0c0ad468u; return 0; }
r[0]<<=16;
goto P_0c0ad46a;
P_0c0ad46a: /* original 2039, guest PC 0x0c0ad46a */
if(!s->budget--) { s->failed_pc=0x0c0ad46au; return 0; }
r[0]&=r[3];
goto P_0c0ad46c;
P_0c0ad46c: /* original 2e0b, guest PC 0x0c0ad46c */
if(!s->budget--) { s->failed_pc=0x0c0ad46cu; return 0; }
r[14]|=r[0];
goto P_0c0ad46e;
P_0c0ad46e: /* original 8471, guest PC 0x0c0ad46e */
if(!s->budget--) { s->failed_pc=0x0c0ad46eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+1,1);
goto P_0c0ad470;
P_0c0ad470: /* original 600c, guest PC 0x0c0ad470 */
if(!s->budget--) { s->failed_pc=0x0c0ad470u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad472;
P_0c0ad472: /* original 4018, guest PC 0x0c0ad472 */
if(!s->budget--) { s->failed_pc=0x0c0ad472u; return 0; }
r[0]<<=8;
goto P_0c0ad474;
P_0c0ad474: /* original 20c9, guest PC 0x0c0ad474 */
if(!s->budget--) { s->failed_pc=0x0c0ad474u; return 0; }
r[0]&=r[12];
goto P_0c0ad476;
P_0c0ad476: /* original 2e0b, guest PC 0x0c0ad476 */
if(!s->budget--) { s->failed_pc=0x0c0ad476u; return 0; }
r[14]|=r[0];
goto P_0c0ad478;
P_0c0ad478: /* original 903d, guest PC 0x0c0ad478 */
if(!s->budget--) { s->failed_pc=0x0c0ad478u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4f6u,2);
goto P_0c0ad47a;
P_0c0ad47a: /* original 2e2b, guest PC 0x0c0ad47a */
if(!s->budget--) { s->failed_pc=0x0c0ad47au; return 0; }
r[14]|=r[2];
goto P_0c0ad47c;
P_0c0ad47c: /* original 04e6, guest PC 0x0c0ad47c */
if(!s->budget--) { s->failed_pc=0x0c0ad47cu; return 0; }
write(ram,r[4]+r[0],r[14],4);
goto P_0c0ad47e;
P_0c0ad47e: /* original 923b, guest PC 0x0c0ad47e */
if(!s->budget--) { s->failed_pc=0x0c0ad47eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4f8u,2);
goto P_0c0ad480;
P_0c0ad480: /* original d325, guest PC 0x0c0ad480 */
if(!s->budget--) { s->failed_pc=0x0c0ad480u; return 0; }
r[3]=read(ram,0x0c0ad518u,4);
goto P_0c0ad482;
P_0c0ad482: /* original 2e29, guest PC 0x0c0ad482 */
if(!s->budget--) { s->failed_pc=0x0c0ad482u; return 0; }
r[14]&=r[2];
goto P_0c0ad484;
P_0c0ad484: /* original 23e8, guest PC 0x0c0ad484 */
if(!s->budget--) { s->failed_pc=0x0c0ad484u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c0ad486;
P_0c0ad486: /* original 8902, guest PC 0x0c0ad486 */
if(!s->budget--) { s->failed_pc=0x0c0ad486u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad48e; }
goto P_0c0ad488;
P_0c0ad488: /* original 9038, guest PC 0x0c0ad488 */
if(!s->budget--) { s->failed_pc=0x0c0ad488u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4fcu,2);
goto P_0c0ad48a;
P_0c0ad48a: /* original 9236, guest PC 0x0c0ad48a */
if(!s->budget--) { s->failed_pc=0x0c0ad48au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4fau,2);
goto P_0c0ad48c;
P_0c0ad48c: /* original 0425, guest PC 0x0c0ad48c */
if(!s->budget--) { s->failed_pc=0x0c0ad48cu; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0ad48e;
P_0c0ad48e: /* original 9336, guest PC 0x0c0ad48e */
if(!s->budget--) { s->failed_pc=0x0c0ad48eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4feu,2);
goto P_0c0ad490;
P_0c0ad490: /* original 23e8, guest PC 0x0c0ad490 */
if(!s->budget--) { s->failed_pc=0x0c0ad490u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c0ad492;
P_0c0ad492: /* original 8d02, guest PC 0x0c0ad492 */
if(!s->budget--) { s->failed_pc=0x0c0ad492u; return 0; }
cond=r[17]&1u;
r[3]=r[6]&65535u;
if(cond) { goto P_0c0ad49a; }
goto P_0c0ad496;
P_0c0ad494: /* original 636d, guest PC 0x0c0ad494 */
if(!s->budget--) { s->failed_pc=0x0c0ad494u; return 0; }
r[3]=r[6]&65535u;
goto P_0c0ad496;
P_0c0ad496: /* original d121, guest PC 0x0c0ad496 */
if(!s->budget--) { s->failed_pc=0x0c0ad496u; return 0; }
r[1]=read(ram,0x0c0ad51cu,4);
goto P_0c0ad498;
P_0c0ad498: /* original 2e19, guest PC 0x0c0ad498 */
if(!s->budget--) { s->failed_pc=0x0c0ad498u; return 0; }
r[14]&=r[1];
goto P_0c0ad49a;
P_0c0ad49a: /* original e048, guest PC 0x0c0ad49a */
if(!s->budget--) { s->failed_pc=0x0c0ad49au; return 0; }
r[0]=0x00000048u;
goto P_0c0ad49c;
P_0c0ad49c: /* original 2f32, guest PC 0x0c0ad49c */
if(!s->budget--) { s->failed_pc=0x0c0ad49cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ad49e;
P_0c0ad49e: /* original 922f, guest PC 0x0c0ad49e */
if(!s->budget--) { s->failed_pc=0x0c0ad49eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad500u,2);
goto P_0c0ad4a0;
P_0c0ad4a0: /* original 04e6, guest PC 0x0c0ad4a0 */
if(!s->budget--) { s->failed_pc=0x0c0ad4a0u; return 0; }
write(ram,r[4]+r[0],r[14],4);
goto P_0c0ad4a2;
P_0c0ad4a2: /* original 847b, guest PC 0x0c0ad4a2 */
if(!s->budget--) { s->failed_pc=0x0c0ad4a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+11,1);
goto P_0c0ad4a4;
P_0c0ad4a4: /* original 3320, guest PC 0x0c0ad4a4 */
if(!s->budget--) { s->failed_pc=0x0c0ad4a4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0ad4a6;
P_0c0ad4a6: /* original de1a, guest PC 0x0c0ad4a6 */
if(!s->budget--) { s->failed_pc=0x0c0ad4a6u; return 0; }
r[14]=read(ram,0x0c0ad510u,4);
goto P_0c0ad4a8;
P_0c0ad4a8: /* original 600c, guest PC 0x0c0ad4a8 */
if(!s->budget--) { s->failed_pc=0x0c0ad4a8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad4aa;
P_0c0ad4aa: /* original d31a, guest PC 0x0c0ad4aa */
if(!s->budget--) { s->failed_pc=0x0c0ad4aau; return 0; }
r[3]=read(ram,0x0c0ad514u,4);
goto P_0c0ad4ac;
P_0c0ad4ac: /* original 4028, guest PC 0x0c0ad4ac */
if(!s->budget--) { s->failed_pc=0x0c0ad4acu; return 0; }
r[0]<<=16;
goto P_0c0ad4ae;
P_0c0ad4ae: /* original d21c, guest PC 0x0c0ad4ae */
if(!s->budget--) { s->failed_pc=0x0c0ad4aeu; return 0; }
r[2]=read(ram,0x0c0ad520u,4);
goto P_0c0ad4b0;
P_0c0ad4b0: /* original 4018, guest PC 0x0c0ad4b0 */
if(!s->budget--) { s->failed_pc=0x0c0ad4b0u; return 0; }
r[0]<<=8;
goto P_0c0ad4b2;
P_0c0ad4b2: /* original 51d1, guest PC 0x0c0ad4b2 */
if(!s->budget--) { s->failed_pc=0x0c0ad4b2u; return 0; }
r[1]=read(ram,r[13]+4,4);
goto P_0c0ad4b4;
P_0c0ad4b4: /* original 2e09, guest PC 0x0c0ad4b4 */
if(!s->budget--) { s->failed_pc=0x0c0ad4b4u; return 0; }
r[14]&=r[0];
goto P_0c0ad4b6;
P_0c0ad4b6: /* original 847a, guest PC 0x0c0ad4b6 */
if(!s->budget--) { s->failed_pc=0x0c0ad4b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+10,1);
goto P_0c0ad4b8;
P_0c0ad4b8: /* original 2128, guest PC 0x0c0ad4b8 */
if(!s->budget--) { s->failed_pc=0x0c0ad4b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0ad4ba;
P_0c0ad4ba: /* original 600c, guest PC 0x0c0ad4ba */
if(!s->budget--) { s->failed_pc=0x0c0ad4bau; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad4bc;
P_0c0ad4bc: /* original 4028, guest PC 0x0c0ad4bc */
if(!s->budget--) { s->failed_pc=0x0c0ad4bcu; return 0; }
r[0]<<=16;
goto P_0c0ad4be;
P_0c0ad4be: /* original 2039, guest PC 0x0c0ad4be */
if(!s->budget--) { s->failed_pc=0x0c0ad4beu; return 0; }
r[0]&=r[3];
goto P_0c0ad4c0;
P_0c0ad4c0: /* original 2e0b, guest PC 0x0c0ad4c0 */
if(!s->budget--) { s->failed_pc=0x0c0ad4c0u; return 0; }
r[14]|=r[0];
goto P_0c0ad4c2;
P_0c0ad4c2: /* original 8479, guest PC 0x0c0ad4c2 */
if(!s->budget--) { s->failed_pc=0x0c0ad4c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+9,1);
goto P_0c0ad4c4;
P_0c0ad4c4: /* original 600c, guest PC 0x0c0ad4c4 */
if(!s->budget--) { s->failed_pc=0x0c0ad4c4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad4c6;
P_0c0ad4c6: /* original 4018, guest PC 0x0c0ad4c6 */
if(!s->budget--) { s->failed_pc=0x0c0ad4c6u; return 0; }
r[0]<<=8;
goto P_0c0ad4c8;
P_0c0ad4c8: /* original 20c9, guest PC 0x0c0ad4c8 */
if(!s->budget--) { s->failed_pc=0x0c0ad4c8u; return 0; }
r[0]&=r[12];
goto P_0c0ad4ca;
P_0c0ad4ca: /* original 2e0b, guest PC 0x0c0ad4ca */
if(!s->budget--) { s->failed_pc=0x0c0ad4cau; return 0; }
r[14]|=r[0];
goto P_0c0ad4cc;
P_0c0ad4cc: /* original 8478, guest PC 0x0c0ad4cc */
if(!s->budget--) { s->failed_pc=0x0c0ad4ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+8,1);
goto P_0c0ad4ce;
P_0c0ad4ce: /* original 600c, guest PC 0x0c0ad4ce */
if(!s->budget--) { s->failed_pc=0x0c0ad4ceu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad4d0;
P_0c0ad4d0: /* original 2e0b, guest PC 0x0c0ad4d0 */
if(!s->budget--) { s->failed_pc=0x0c0ad4d0u; return 0; }
r[14]|=r[0];
goto P_0c0ad4d2;
P_0c0ad4d2: /* original 892c, guest PC 0x0c0ad4d2 */
if(!s->budget--) { s->failed_pc=0x0c0ad4d2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad52e; }
goto P_0c0ad4d4;
P_0c0ad4d4: /* original 6063, guest PC 0x0c0ad4d4 */
if(!s->budget--) { s->failed_pc=0x0c0ad4d4u; return 0; }
r[0]=r[6];
goto P_0c0ad4d6;
P_0c0ad4d6: /* original 8840, guest PC 0x0c0ad4d6 */
if(!s->budget--) { s->failed_pc=0x0c0ad4d6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c0ad4d8;
P_0c0ad4d8: /* original 8927, guest PC 0x0c0ad4d8 */
if(!s->budget--) { s->failed_pc=0x0c0ad4d8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad52a; }
goto P_0c0ad4da;
P_0c0ad4da: /* original a023, guest PC 0x0c0ad4da */
if(!s->budget--) { s->failed_pc=0x0c0ad4dau; return 0; }
goto P_0c0ad524;
P_0c0ad4dc: /* original 0009, guest PC 0x0c0ad4dc */
if(!s->budget--) { s->failed_pc=0x0c0ad4dcu; return 0; }
if(!vf3_matrix_family(0x0c0ad4deu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ad4deu; return 0; } return 1;
P_0c0ad524: /* original 9033, guest PC 0x0c0ad524 */
if(!s->budget--) { s->failed_pc=0x0c0ad524u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad58eu,2);
goto P_0c0ad526;
P_0c0ad526: /* original 3600, guest PC 0x0c0ad526 */
if(!s->budget--) { s->failed_pc=0x0c0ad526u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[0])!=0);
goto P_0c0ad528;
P_0c0ad528: /* original 8b01, guest PC 0x0c0ad528 */
if(!s->budget--) { s->failed_pc=0x0c0ad528u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ad52e; }
goto P_0c0ad52a;
P_0c0ad52a: /* original d21b, guest PC 0x0c0ad52a */
if(!s->budget--) { s->failed_pc=0x0c0ad52au; return 0; }
r[2]=read(ram,0x0c0ad598u,4);
goto P_0c0ad52c;
P_0c0ad52c: /* original 2e2b, guest PC 0x0c0ad52c */
if(!s->budget--) { s->failed_pc=0x0c0ad52cu; return 0; }
r[14]|=r[2];
goto P_0c0ad52e;
P_0c0ad52e: /* original 902f, guest PC 0x0c0ad52e */
if(!s->budget--) { s->failed_pc=0x0c0ad52eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad590u,2);
goto P_0c0ad530;
P_0c0ad530: /* original 04e6, guest PC 0x0c0ad530 */
if(!s->budget--) { s->failed_pc=0x0c0ad530u; return 0; }
write(ram,r[4]+r[0],r[14],4);
goto P_0c0ad532;
P_0c0ad532: /* original e04c, guest PC 0x0c0ad532 */
if(!s->budget--) { s->failed_pc=0x0c0ad532u; return 0; }
r[0]=0x0000004cu;
goto P_0c0ad534;
P_0c0ad534: /* original 04e6, guest PC 0x0c0ad534 */
if(!s->budget--) { s->failed_pc=0x0c0ad534u; return 0; }
write(ram,r[4]+r[0],r[14],4);
goto P_0c0ad536;
P_0c0ad536: /* original 8475, guest PC 0x0c0ad536 */
if(!s->budget--) { s->failed_pc=0x0c0ad536u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+5,1);
goto P_0c0ad538;
P_0c0ad538: /* original 600c, guest PC 0x0c0ad538 */
if(!s->budget--) { s->failed_pc=0x0c0ad538u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad53a;
P_0c0ad53a: /* original 4018, guest PC 0x0c0ad53a */
if(!s->budget--) { s->failed_pc=0x0c0ad53au; return 0; }
r[0]<<=8;
goto P_0c0ad53c;
P_0c0ad53c: /* original 20c9, guest PC 0x0c0ad53c */
if(!s->budget--) { s->failed_pc=0x0c0ad53cu; return 0; }
r[0]&=r[12];
goto P_0c0ad53e;
P_0c0ad53e: /* original 6303, guest PC 0x0c0ad53e */
if(!s->budget--) { s->failed_pc=0x0c0ad53eu; return 0; }
r[3]=r[0];
goto P_0c0ad540;
P_0c0ad540: /* original 8474, guest PC 0x0c0ad540 */
if(!s->budget--) { s->failed_pc=0x0c0ad540u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+4,1);
goto P_0c0ad542;
P_0c0ad542: /* original 600c, guest PC 0x0c0ad542 */
if(!s->budget--) { s->failed_pc=0x0c0ad542u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad544;
P_0c0ad544: /* original 230b, guest PC 0x0c0ad544 */
if(!s->budget--) { s->failed_pc=0x0c0ad544u; return 0; }
r[3]|=r[0];
goto P_0c0ad546;
P_0c0ad546: /* original 9024, guest PC 0x0c0ad546 */
if(!s->budget--) { s->failed_pc=0x0c0ad546u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad592u,2);
goto P_0c0ad548;
P_0c0ad548: /* original 0435, guest PC 0x0c0ad548 */
if(!s->budget--) { s->failed_pc=0x0c0ad548u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c0ad54a;
P_0c0ad54a: /* original 8477, guest PC 0x0c0ad54a */
if(!s->budget--) { s->failed_pc=0x0c0ad54au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+7,1);
goto P_0c0ad54c;
P_0c0ad54c: /* original 600c, guest PC 0x0c0ad54c */
if(!s->budget--) { s->failed_pc=0x0c0ad54cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad54e;
P_0c0ad54e: /* original 4018, guest PC 0x0c0ad54e */
if(!s->budget--) { s->failed_pc=0x0c0ad54eu; return 0; }
r[0]<<=8;
goto P_0c0ad550;
P_0c0ad550: /* original 20c9, guest PC 0x0c0ad550 */
if(!s->budget--) { s->failed_pc=0x0c0ad550u; return 0; }
r[0]&=r[12];
goto P_0c0ad552;
P_0c0ad552: /* original 6303, guest PC 0x0c0ad552 */
if(!s->budget--) { s->failed_pc=0x0c0ad552u; return 0; }
r[3]=r[0];
goto P_0c0ad554;
P_0c0ad554: /* original 8476, guest PC 0x0c0ad554 */
if(!s->budget--) { s->failed_pc=0x0c0ad554u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+6,1);
goto P_0c0ad556;
P_0c0ad556: /* original 770c, guest PC 0x0c0ad556 */
if(!s->budget--) { s->failed_pc=0x0c0ad556u; return 0; }
r[7]+=0x0000000cu;
goto P_0c0ad558;
P_0c0ad558: /* original 600c, guest PC 0x0c0ad558 */
if(!s->budget--) { s->failed_pc=0x0c0ad558u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad55a;
P_0c0ad55a: /* original 6673, guest PC 0x0c0ad55a */
if(!s->budget--) { s->failed_pc=0x0c0ad55au; return 0; }
r[6]=r[7];
goto P_0c0ad55c;
P_0c0ad55c: /* original 230b, guest PC 0x0c0ad55c */
if(!s->budget--) { s->failed_pc=0x0c0ad55cu; return 0; }
r[3]|=r[0];
goto P_0c0ad55e;
P_0c0ad55e: /* original 9019, guest PC 0x0c0ad55e */
if(!s->budget--) { s->failed_pc=0x0c0ad55eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad594u,2);
goto P_0c0ad560;
P_0c0ad560: /* original 0435, guest PC 0x0c0ad560 */
if(!s->budget--) { s->failed_pc=0x0c0ad560u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c0ad562;
P_0c0ad562: /* original 2f72, guest PC 0x0c0ad562 */
if(!s->budget--) { s->failed_pc=0x0c0ad562u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c0ad564;
P_0c0ad564: /* original 7f08, guest PC 0x0c0ad564 */
if(!s->budget--) { s->failed_pc=0x0c0ad564u; return 0; }
r[15]+=0x00000008u;
goto P_0c0ad566;
P_0c0ad566: /* original 6cf6, guest PC 0x0c0ad566 */
if(!s->budget--) { s->failed_pc=0x0c0ad566u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ad568;
P_0c0ad568: /* original 6df6, guest PC 0x0c0ad568 */
if(!s->budget--) { s->failed_pc=0x0c0ad568u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ad56a;
P_0c0ad56a: /* original a005, guest PC 0x0c0ad56a */
if(!s->budget--) { s->failed_pc=0x0c0ad56au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ad578u,s,ram);
P_0c0ad56c: /* original 6ef6, guest PC 0x0c0ad56c */
if(!s->budget--) { s->failed_pc=0x0c0ad56cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ad56e;
P_0c0ad56e: /* original 7f08, guest PC 0x0c0ad56e */
if(!s->budget--) { s->failed_pc=0x0c0ad56eu; return 0; }
r[15]+=0x00000008u;
goto P_0c0ad570;
P_0c0ad570: /* original 6cf6, guest PC 0x0c0ad570 */
if(!s->budget--) { s->failed_pc=0x0c0ad570u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ad572;
P_0c0ad572: /* original 6df6, guest PC 0x0c0ad572 */
if(!s->budget--) { s->failed_pc=0x0c0ad572u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ad574;
P_0c0ad574: /* original 000b, guest PC 0x0c0ad574 */
if(!s->budget--) { s->failed_pc=0x0c0ad574u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ad576: /* original 6ef6, guest PC 0x0c0ad576 */
if(!s->budget--) { s->failed_pc=0x0c0ad576u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ad578u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
