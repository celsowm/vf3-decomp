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
int vf3_away_batch10_adapter_15(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06c360u: goto P_0c06c360;
case 0x0c06c362u: goto P_0c06c362;
case 0x0c06c364u: goto P_0c06c364;
case 0x0c06c366u: goto P_0c06c366;
case 0x0c06c368u: goto P_0c06c368;
case 0x0c06c36au: goto P_0c06c36a;
case 0x0c06c36cu: goto P_0c06c36c;
case 0x0c06c36eu: goto P_0c06c36e;
case 0x0c06c370u: goto P_0c06c370;
case 0x0c06c372u: goto P_0c06c372;
case 0x0c06c374u: goto P_0c06c374;
case 0x0c06c376u: goto P_0c06c376;
case 0x0c06c378u: goto P_0c06c378;
case 0x0c06c37au: goto P_0c06c37a;
case 0x0c06c37cu: goto P_0c06c37c;
case 0x0c06c37eu: goto P_0c06c37e;
case 0x0c06c380u: goto P_0c06c380;
case 0x0c06c382u: goto P_0c06c382;
case 0x0c06c384u: goto P_0c06c384;
case 0x0c06c386u: goto P_0c06c386;
case 0x0c06c388u: goto P_0c06c388;
case 0x0c06c38au: goto P_0c06c38a;
case 0x0c06c38cu: goto P_0c06c38c;
case 0x0c06c38eu: goto P_0c06c38e;
case 0x0c06c390u: goto P_0c06c390;
case 0x0c06c392u: goto P_0c06c392;
case 0x0c06c394u: goto P_0c06c394;
case 0x0c06c396u: goto P_0c06c396;
case 0x0c06c398u: goto P_0c06c398;
case 0x0c06c39au: goto P_0c06c39a;
case 0x0c06c39cu: goto P_0c06c39c;
case 0x0c06c39eu: goto P_0c06c39e;
case 0x0c06c3a0u: goto P_0c06c3a0;
case 0x0c06c3a2u: goto P_0c06c3a2;
case 0x0c06c3a4u: goto P_0c06c3a4;
case 0x0c06c3a6u: goto P_0c06c3a6;
case 0x0c06c3a8u: goto P_0c06c3a8;
case 0x0c06c3aau: goto P_0c06c3aa;
case 0x0c06c3acu: goto P_0c06c3ac;
case 0x0c06c3aeu: goto P_0c06c3ae;
case 0x0c06c3b0u: goto P_0c06c3b0;
case 0x0c06c3b2u: goto P_0c06c3b2;
case 0x0c06c3b4u: goto P_0c06c3b4;
case 0x0c06c3b6u: goto P_0c06c3b6;
case 0x0c06c3b8u: goto P_0c06c3b8;
case 0x0c06c3bau: goto P_0c06c3ba;
case 0x0c06c3bcu: goto P_0c06c3bc;
case 0x0c06c3beu: goto P_0c06c3be;
case 0x0c06c3c0u: goto P_0c06c3c0;
case 0x0c06c3c2u: goto P_0c06c3c2;
case 0x0c06c3c4u: goto P_0c06c3c4;
case 0x0c06c3c6u: goto P_0c06c3c6;
case 0x0c06c3c8u: goto P_0c06c3c8;
case 0x0c06c3cau: goto P_0c06c3ca;
case 0x0c06c3ccu: goto P_0c06c3cc;
case 0x0c06c3ceu: goto P_0c06c3ce;
case 0x0c06c3d0u: goto P_0c06c3d0;
case 0x0c06c3d2u: goto P_0c06c3d2;
case 0x0c06c3d4u: goto P_0c06c3d4;
case 0x0c06c3d6u: goto P_0c06c3d6;
case 0x0c06c3d8u: goto P_0c06c3d8;
case 0x0c06c3dau: goto P_0c06c3da;
case 0x0c06c3dcu: goto P_0c06c3dc;
case 0x0c06c3deu: goto P_0c06c3de;
case 0x0c06c3e0u: goto P_0c06c3e0;
case 0x0c06c3e2u: goto P_0c06c3e2;
case 0x0c06c3e4u: goto P_0c06c3e4;
case 0x0c06c3e6u: goto P_0c06c3e6;
case 0x0c06c3e8u: goto P_0c06c3e8;
case 0x0c06c3eau: goto P_0c06c3ea;
case 0x0c06c3ecu: goto P_0c06c3ec;
case 0x0c06c3eeu: goto P_0c06c3ee;
case 0x0c06c3f0u: goto P_0c06c3f0;
case 0x0c06c3f2u: goto P_0c06c3f2;
case 0x0c06c3f4u: goto P_0c06c3f4;
case 0x0c06c3f6u: goto P_0c06c3f6;
case 0x0c06c3f8u: goto P_0c06c3f8;
case 0x0c06c3fau: goto P_0c06c3fa;
case 0x0c06c3fcu: goto P_0c06c3fc;
case 0x0c06c3feu: goto P_0c06c3fe;
case 0x0c06c400u: goto P_0c06c400;
case 0x0c06c402u: goto P_0c06c402;
case 0x0c06c404u: goto P_0c06c404;
case 0x0c06c406u: goto P_0c06c406;
case 0x0c06c408u: goto P_0c06c408;
case 0x0c06c40au: goto P_0c06c40a;
case 0x0c06c40cu: goto P_0c06c40c;
case 0x0c06c40eu: goto P_0c06c40e;
case 0x0c06c410u: goto P_0c06c410;
case 0x0c06c412u: goto P_0c06c412;
case 0x0c06c414u: goto P_0c06c414;
case 0x0c06c416u: goto P_0c06c416;
case 0x0c06c418u: goto P_0c06c418;
case 0x0c06c41au: goto P_0c06c41a;
case 0x0c06c41cu: goto P_0c06c41c;
case 0x0c06c41eu: goto P_0c06c41e;
case 0x0c06c420u: goto P_0c06c420;
case 0x0c06c422u: goto P_0c06c422;
case 0x0c06c424u: goto P_0c06c424;
case 0x0c06c426u: goto P_0c06c426;
case 0x0c06c428u: goto P_0c06c428;
case 0x0c06c42au: goto P_0c06c42a;
case 0x0c06c42cu: goto P_0c06c42c;
case 0x0c06c42eu: goto P_0c06c42e;
case 0x0c06c430u: goto P_0c06c430;
case 0x0c06c432u: goto P_0c06c432;
case 0x0c06c434u: goto P_0c06c434;
case 0x0c06c436u: goto P_0c06c436;
case 0x0c06c438u: goto P_0c06c438;
case 0x0c06c43au: goto P_0c06c43a;
case 0x0c06c43cu: goto P_0c06c43c;
case 0x0c06c43eu: goto P_0c06c43e;
case 0x0c06c440u: goto P_0c06c440;
case 0x0c06c442u: goto P_0c06c442;
case 0x0c06c444u: goto P_0c06c444;
case 0x0c06c446u: goto P_0c06c446;
case 0x0c06c448u: goto P_0c06c448;
case 0x0c06c44au: goto P_0c06c44a;
case 0x0c06c44cu: goto P_0c06c44c;
case 0x0c06c44eu: goto P_0c06c44e;
case 0x0c06c450u: goto P_0c06c450;
case 0x0c06c452u: goto P_0c06c452;
case 0x0c06c454u: goto P_0c06c454;
case 0x0c06c456u: goto P_0c06c456;
case 0x0c06c458u: goto P_0c06c458;
case 0x0c06c45au: goto P_0c06c45a;
case 0x0c06c45cu: goto P_0c06c45c;
case 0x0c06c45eu: goto P_0c06c45e;
case 0x0c06c460u: goto P_0c06c460;
case 0x0c06c462u: goto P_0c06c462;
case 0x0c06c464u: goto P_0c06c464;
case 0x0c06c466u: goto P_0c06c466;
case 0x0c06c468u: goto P_0c06c468;
case 0x0c06c46au: goto P_0c06c46a;
case 0x0c06c46cu: goto P_0c06c46c;
case 0x0c06c46eu: goto P_0c06c46e;
case 0x0c06c470u: goto P_0c06c470;
case 0x0c06c472u: goto P_0c06c472;
case 0x0c06c474u: goto P_0c06c474;
case 0x0c06c476u: goto P_0c06c476;
case 0x0c06c478u: goto P_0c06c478;
case 0x0c06c51eu: goto P_0c06c51e;
case 0x0c06c520u: goto P_0c06c520;
case 0x0c06c522u: goto P_0c06c522;
case 0x0c06c524u: goto P_0c06c524;
case 0x0c06c526u: goto P_0c06c526;
case 0x0c06c528u: goto P_0c06c528;
case 0x0c06c52au: goto P_0c06c52a;
case 0x0c06c52cu: goto P_0c06c52c;
case 0x0c06c52eu: goto P_0c06c52e;
case 0x0c06c530u: goto P_0c06c530;
case 0x0c06c532u: goto P_0c06c532;
case 0x0c06c534u: goto P_0c06c534;
case 0x0c06c536u: goto P_0c06c536;
case 0x0c06c538u: goto P_0c06c538;
case 0x0c06c53au: goto P_0c06c53a;
case 0x0c06c53cu: goto P_0c06c53c;
case 0x0c06c53eu: goto P_0c06c53e;
case 0x0c06c540u: goto P_0c06c540;
case 0x0c06c542u: goto P_0c06c542;
case 0x0c06c544u: goto P_0c06c544;
case 0x0c06c546u: goto P_0c06c546;
case 0x0c06c548u: goto P_0c06c548;
case 0x0c06c54au: goto P_0c06c54a;
case 0x0c06c54cu: goto P_0c06c54c;
case 0x0c06c54eu: goto P_0c06c54e;
case 0x0c06c550u: goto P_0c06c550;
case 0x0c06c552u: goto P_0c06c552;
case 0x0c06c554u: goto P_0c06c554;
case 0x0c06c556u: goto P_0c06c556;
case 0x0c06c558u: goto P_0c06c558;
case 0x0c06c55au: goto P_0c06c55a;
case 0x0c06c55cu: goto P_0c06c55c;
case 0x0c06c55eu: goto P_0c06c55e;
case 0x0c06c560u: goto P_0c06c560;
case 0x0c06c562u: goto P_0c06c562;
case 0x0c06c564u: goto P_0c06c564;
case 0x0c06c566u: goto P_0c06c566;
case 0x0c06c568u: goto P_0c06c568;
case 0x0c06c56au: goto P_0c06c56a;
case 0x0c06c56cu: goto P_0c06c56c;
case 0x0c06c56eu: goto P_0c06c56e;
case 0x0c06c570u: goto P_0c06c570;
case 0x0c06c572u: goto P_0c06c572;
case 0x0c06c574u: goto P_0c06c574;
case 0x0c06c576u: goto P_0c06c576;
case 0x0c06c578u: goto P_0c06c578;
case 0x0c06c57au: goto P_0c06c57a;
case 0x0c06c57cu: goto P_0c06c57c;
case 0x0c06c57eu: goto P_0c06c57e;
case 0x0c06c580u: goto P_0c06c580;
case 0x0c06c582u: goto P_0c06c582;
case 0x0c06c584u: goto P_0c06c584;
case 0x0c06c586u: goto P_0c06c586;
case 0x0c06c588u: goto P_0c06c588;
case 0x0c06c58au: goto P_0c06c58a;
case 0x0c06c58cu: goto P_0c06c58c;
case 0x0c06c58eu: goto P_0c06c58e;
case 0x0c06c590u: goto P_0c06c590;
case 0x0c06c592u: goto P_0c06c592;
case 0x0c06c594u: goto P_0c06c594;
case 0x0c06c596u: goto P_0c06c596;
case 0x0c06c598u: goto P_0c06c598;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06c360: /* original 4f22, guest PC 0x0c06c360 */
if(!s->budget--) { s->failed_pc=0x0c06c360u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c362;
P_0c06c362: /* original e21f, guest PC 0x0c06c362 */
if(!s->budget--) { s->failed_pc=0x0c06c362u; return 0; }
r[2]=0x0000001fu;
goto P_0c06c364;
P_0c06c364: /* original e108, guest PC 0x0c06c364 */
if(!s->budget--) { s->failed_pc=0x0c06c364u; return 0; }
r[1]=0x00000008u;
goto P_0c06c366;
P_0c06c366: /* original 7ffc, guest PC 0x0c06c366 */
if(!s->budget--) { s->failed_pc=0x0c06c366u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c368;
P_0c06c368: /* original 2f42, guest PC 0x0c06c368 */
if(!s->budget--) { s->failed_pc=0x0c06c368u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06c36a;
P_0c06c36a: /* original d345, guest PC 0x0c06c36a */
if(!s->budget--) { s->failed_pc=0x0c06c36au; return 0; }
r[3]=read(ram,0x0c06c480u,4);
goto P_0c06c36c;
P_0c06c36c: /* original d443, guest PC 0x0c06c36c */
if(!s->budget--) { s->failed_pc=0x0c06c36cu; return 0; }
r[4]=read(ram,0x0c06c47cu,4);
goto P_0c06c36e;
P_0c06c36e: /* original 6532, guest PC 0x0c06c36e */
if(!s->budget--) { s->failed_pc=0x0c06c36eu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06c370;
P_0c06c370: /* original 2529, guest PC 0x0c06c370 */
if(!s->budget--) { s->failed_pc=0x0c06c370u; return 0; }
r[5]&=r[2];
goto P_0c06c372;
P_0c06c372: /* original 3513, guest PC 0x0c06c372 */
if(!s->budget--) { s->failed_pc=0x0c06c372u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[1])!=0);
goto P_0c06c374;
P_0c06c374: /* original 8b03, guest PC 0x0c06c374 */
if(!s->budget--) { s->failed_pc=0x0c06c374u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c37e; }
goto P_0c06c376;
P_0c06c376: /* original 7f04, guest PC 0x0c06c376 */
if(!s->budget--) { s->failed_pc=0x0c06c376u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c378;
P_0c06c378: /* original 4f26, guest PC 0x0c06c378 */
if(!s->budget--) { s->failed_pc=0x0c06c378u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c37a;
P_0c06c37a: /* original 000b, guest PC 0x0c06c37a */
if(!s->budget--) { s->failed_pc=0x0c06c37au; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c06c37c: /* original 6053, guest PC 0x0c06c37c */
if(!s->budget--) { s->failed_pc=0x0c06c37cu; return 0; }
r[0]=r[5];
goto P_0c06c37e;
P_0c06c37e: /* original e220, guest PC 0x0c06c37e */
if(!s->budget--) { s->failed_pc=0x0c06c37eu; return 0; }
r[2]=0x00000020u;
goto P_0c06c380;
P_0c06c380: /* original e615, guest PC 0x0c06c380 */
if(!s->budget--) { s->failed_pc=0x0c06c380u; return 0; }
r[6]=0x00000015u;
goto P_0c06c382;
P_0c06c382: /* original 2f26, guest PC 0x0c06c382 */
if(!s->budget--) { s->failed_pc=0x0c06c382u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c384;
P_0c06c384: /* original d33f, guest PC 0x0c06c384 */
if(!s->budget--) { s->failed_pc=0x0c06c384u; return 0; }
r[3]=read(ram,0x0c06c484u,4);
goto P_0c06c386;
P_0c06c386: /* original e701, guest PC 0x0c06c386 */
if(!s->budget--) { s->failed_pc=0x0c06c386u; return 0; }
r[7]=0x00000001u;
goto P_0c06c388;
P_0c06c388: /* original 430b, guest PC 0x0c06c388 */
if(!s->budget--) { s->failed_pc=0x0c06c388u; return 0; }
target=r[3];
r[16]=code_base|0x0c06c38cu;
r[5]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c38cu) { target=s->pc; goto dispatch; }
goto P_0c06c38c;
P_0c06c38a: /* original 55f1, guest PC 0x0c06c38a */
if(!s->budget--) { s->failed_pc=0x0c06c38au; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c06c38c;
P_0c06c38c: /* original e000, guest PC 0x0c06c38c */
if(!s->budget--) { s->failed_pc=0x0c06c38cu; return 0; }
r[0]=0x00000000u;
goto P_0c06c38e;
P_0c06c38e: /* original 7f04, guest PC 0x0c06c38e */
if(!s->budget--) { s->failed_pc=0x0c06c38eu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c390;
P_0c06c390: /* original 7f04, guest PC 0x0c06c390 */
if(!s->budget--) { s->failed_pc=0x0c06c390u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c392;
P_0c06c392: /* original 4f26, guest PC 0x0c06c392 */
if(!s->budget--) { s->failed_pc=0x0c06c392u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c394;
P_0c06c394: /* original 000b, guest PC 0x0c06c394 */
if(!s->budget--) { s->failed_pc=0x0c06c394u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06c396: /* original 0009, guest PC 0x0c06c396 */
if(!s->budget--) { s->failed_pc=0x0c06c396u; return 0; }
goto P_0c06c398;
P_0c06c398: /* original 4f22, guest PC 0x0c06c398 */
if(!s->budget--) { s->failed_pc=0x0c06c398u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c39a;
P_0c06c39a: /* original e21f, guest PC 0x0c06c39a */
if(!s->budget--) { s->failed_pc=0x0c06c39au; return 0; }
r[2]=0x0000001fu;
goto P_0c06c39c;
P_0c06c39c: /* original e108, guest PC 0x0c06c39c */
if(!s->budget--) { s->failed_pc=0x0c06c39cu; return 0; }
r[1]=0x00000008u;
goto P_0c06c39e;
P_0c06c39e: /* original 7ffc, guest PC 0x0c06c39e */
if(!s->budget--) { s->failed_pc=0x0c06c39eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c3a0;
P_0c06c3a0: /* original 2f42, guest PC 0x0c06c3a0 */
if(!s->budget--) { s->failed_pc=0x0c06c3a0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06c3a2;
P_0c06c3a2: /* original d337, guest PC 0x0c06c3a2 */
if(!s->budget--) { s->failed_pc=0x0c06c3a2u; return 0; }
r[3]=read(ram,0x0c06c480u,4);
goto P_0c06c3a4;
P_0c06c3a4: /* original d435, guest PC 0x0c06c3a4 */
if(!s->budget--) { s->failed_pc=0x0c06c3a4u; return 0; }
r[4]=read(ram,0x0c06c47cu,4);
goto P_0c06c3a6;
P_0c06c3a6: /* original 6532, guest PC 0x0c06c3a6 */
if(!s->budget--) { s->failed_pc=0x0c06c3a6u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06c3a8;
P_0c06c3a8: /* original 2529, guest PC 0x0c06c3a8 */
if(!s->budget--) { s->failed_pc=0x0c06c3a8u; return 0; }
r[5]&=r[2];
goto P_0c06c3aa;
P_0c06c3aa: /* original 3513, guest PC 0x0c06c3aa */
if(!s->budget--) { s->failed_pc=0x0c06c3aau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[1])!=0);
goto P_0c06c3ac;
P_0c06c3ac: /* original 8b03, guest PC 0x0c06c3ac */
if(!s->budget--) { s->failed_pc=0x0c06c3acu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c3b6; }
goto P_0c06c3ae;
P_0c06c3ae: /* original 7f04, guest PC 0x0c06c3ae */
if(!s->budget--) { s->failed_pc=0x0c06c3aeu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c3b0;
P_0c06c3b0: /* original 4f26, guest PC 0x0c06c3b0 */
if(!s->budget--) { s->failed_pc=0x0c06c3b0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c3b2;
P_0c06c3b2: /* original 000b, guest PC 0x0c06c3b2 */
if(!s->budget--) { s->failed_pc=0x0c06c3b2u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c06c3b4: /* original 6053, guest PC 0x0c06c3b4 */
if(!s->budget--) { s->failed_pc=0x0c06c3b4u; return 0; }
r[0]=r[5];
goto P_0c06c3b6;
P_0c06c3b6: /* original e220, guest PC 0x0c06c3b6 */
if(!s->budget--) { s->failed_pc=0x0c06c3b6u; return 0; }
r[2]=0x00000020u;
goto P_0c06c3b8;
P_0c06c3b8: /* original e618, guest PC 0x0c06c3b8 */
if(!s->budget--) { s->failed_pc=0x0c06c3b8u; return 0; }
r[6]=0x00000018u;
goto P_0c06c3ba;
P_0c06c3ba: /* original 2f26, guest PC 0x0c06c3ba */
if(!s->budget--) { s->failed_pc=0x0c06c3bau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c3bc;
P_0c06c3bc: /* original d331, guest PC 0x0c06c3bc */
if(!s->budget--) { s->failed_pc=0x0c06c3bcu; return 0; }
r[3]=read(ram,0x0c06c484u,4);
goto P_0c06c3be;
P_0c06c3be: /* original e701, guest PC 0x0c06c3be */
if(!s->budget--) { s->failed_pc=0x0c06c3beu; return 0; }
r[7]=0x00000001u;
goto P_0c06c3c0;
P_0c06c3c0: /* original 430b, guest PC 0x0c06c3c0 */
if(!s->budget--) { s->failed_pc=0x0c06c3c0u; return 0; }
target=r[3];
r[16]=code_base|0x0c06c3c4u;
r[5]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c3c4u) { target=s->pc; goto dispatch; }
goto P_0c06c3c4;
P_0c06c3c2: /* original 55f1, guest PC 0x0c06c3c2 */
if(!s->budget--) { s->failed_pc=0x0c06c3c2u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c06c3c4;
P_0c06c3c4: /* original e000, guest PC 0x0c06c3c4 */
if(!s->budget--) { s->failed_pc=0x0c06c3c4u; return 0; }
r[0]=0x00000000u;
goto P_0c06c3c6;
P_0c06c3c6: /* original 7f04, guest PC 0x0c06c3c6 */
if(!s->budget--) { s->failed_pc=0x0c06c3c6u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c3c8;
P_0c06c3c8: /* original 7f04, guest PC 0x0c06c3c8 */
if(!s->budget--) { s->failed_pc=0x0c06c3c8u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c3ca;
P_0c06c3ca: /* original 4f26, guest PC 0x0c06c3ca */
if(!s->budget--) { s->failed_pc=0x0c06c3cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c3cc;
P_0c06c3cc: /* original 000b, guest PC 0x0c06c3cc */
if(!s->budget--) { s->failed_pc=0x0c06c3ccu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06c3ce: /* original 0009, guest PC 0x0c06c3ce */
if(!s->budget--) { s->failed_pc=0x0c06c3ceu; return 0; }
goto P_0c06c3d0;
P_0c06c3d0: /* original d32d, guest PC 0x0c06c3d0 */
if(!s->budget--) { s->failed_pc=0x0c06c3d0u; return 0; }
r[3]=read(ram,0x0c06c488u,4);
goto P_0c06c3d2;
P_0c06c3d2: /* original e208, guest PC 0x0c06c3d2 */
if(!s->budget--) { s->failed_pc=0x0c06c3d2u; return 0; }
r[2]=0x00000008u;
goto P_0c06c3d4;
P_0c06c3d4: /* original 4f22, guest PC 0x0c06c3d4 */
if(!s->budget--) { s->failed_pc=0x0c06c3d4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c3d6;
P_0c06c3d6: /* original 6032, guest PC 0x0c06c3d6 */
if(!s->budget--) { s->failed_pc=0x0c06c3d6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c06c3d8;
P_0c06c3d8: /* original c91f, guest PC 0x0c06c3d8 */
if(!s->budget--) { s->failed_pc=0x0c06c3d8u; return 0; }
r[0]&=31u;
goto P_0c06c3da;
P_0c06c3da: /* original 7ff8, guest PC 0x0c06c3da */
if(!s->budget--) { s->failed_pc=0x0c06c3dau; return 0; }
r[15]+=0xfffffff8u;
goto P_0c06c3dc;
P_0c06c3dc: /* original 3022, guest PC 0x0c06c3dc */
if(!s->budget--) { s->failed_pc=0x0c06c3dcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>=r[2])!=0);
goto P_0c06c3de;
P_0c06c3de: /* original 2f02, guest PC 0x0c06c3de */
if(!s->budget--) { s->failed_pc=0x0c06c3deu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06c3e0;
P_0c06c3e0: /* original 890d, guest PC 0x0c06c3e0 */
if(!s->budget--) { s->failed_pc=0x0c06c3e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c3fe; }
goto P_0c06c3e2;
P_0c06c3e2: /* original e307, guest PC 0x0c06c3e2 */
if(!s->budget--) { s->failed_pc=0x0c06c3e2u; return 0; }
r[3]=0x00000007u;
goto P_0c06c3e4;
P_0c06c3e4: /* original 453d, guest PC 0x0c06c3e4 */
if(!s->budget--) { s->failed_pc=0x0c06c3e4u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c06c3e6;
P_0c06c3e6: /* original 4400, guest PC 0x0c06c3e6 */
if(!s->budget--) { s->failed_pc=0x0c06c3e6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c3e8;
P_0c06c3e8: /* original 245b, guest PC 0x0c06c3e8 */
if(!s->budget--) { s->failed_pc=0x0c06c3e8u; return 0; }
r[4]|=r[5];
goto P_0c06c3ea;
P_0c06c3ea: /* original e120, guest PC 0x0c06c3ea */
if(!s->budget--) { s->failed_pc=0x0c06c3eau; return 0; }
r[1]=0x00000020u;
goto P_0c06c3ec;
P_0c06c3ec: /* original 2f42, guest PC 0x0c06c3ec */
if(!s->budget--) { s->failed_pc=0x0c06c3ecu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06c3ee;
P_0c06c3ee: /* original d223, guest PC 0x0c06c3ee */
if(!s->budget--) { s->failed_pc=0x0c06c3eeu; return 0; }
r[2]=read(ram,0x0c06c47cu,4);
goto P_0c06c3f0;
P_0c06c3f0: /* original 1f21, guest PC 0x0c06c3f0 */
if(!s->budget--) { s->failed_pc=0x0c06c3f0u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c06c3f2;
P_0c06c3f2: /* original 2f16, guest PC 0x0c06c3f2 */
if(!s->budget--) { s->failed_pc=0x0c06c3f2u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c3f4;
P_0c06c3f4: /* original d223, guest PC 0x0c06c3f4 */
if(!s->budget--) { s->failed_pc=0x0c06c3f4u; return 0; }
r[2]=read(ram,0x0c06c484u,4);
goto P_0c06c3f6;
P_0c06c3f6: /* original 55f1, guest PC 0x0c06c3f6 */
if(!s->budget--) { s->failed_pc=0x0c06c3f6u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c06c3f8;
P_0c06c3f8: /* original 420b, guest PC 0x0c06c3f8 */
if(!s->budget--) { s->failed_pc=0x0c06c3f8u; return 0; }
target=r[2];
r[16]=code_base|0x0c06c3fcu;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c3fcu) { target=s->pc; goto dispatch; }
goto P_0c06c3fc;
P_0c06c3fa: /* original 54f2, guest PC 0x0c06c3fa */
if(!s->budget--) { s->failed_pc=0x0c06c3fau; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c06c3fc;
P_0c06c3fc: /* original 7f04, guest PC 0x0c06c3fc */
if(!s->budget--) { s->failed_pc=0x0c06c3fcu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c3fe;
P_0c06c3fe: /* original 7f08, guest PC 0x0c06c3fe */
if(!s->budget--) { s->failed_pc=0x0c06c3feu; return 0; }
r[15]+=0x00000008u;
goto P_0c06c400;
P_0c06c400: /* original 4f26, guest PC 0x0c06c400 */
if(!s->budget--) { s->failed_pc=0x0c06c400u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c402;
P_0c06c402: /* original 000b, guest PC 0x0c06c402 */
if(!s->budget--) { s->failed_pc=0x0c06c402u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06c404: /* original 0009, guest PC 0x0c06c404 */
if(!s->budget--) { s->failed_pc=0x0c06c404u; return 0; }
goto P_0c06c406;
P_0c06c406: /* original 4f22, guest PC 0x0c06c406 */
if(!s->budget--) { s->failed_pc=0x0c06c406u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c408;
P_0c06c408: /* original 53f1, guest PC 0x0c06c408 */
if(!s->budget--) { s->failed_pc=0x0c06c408u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06c40a;
P_0c06c40a: /* original 2f36, guest PC 0x0c06c40a */
if(!s->budget--) { s->failed_pc=0x0c06c40au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c40c;
P_0c06c40c: /* original 2f76, guest PC 0x0c06c40c */
if(!s->budget--) { s->failed_pc=0x0c06c40cu; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c40e;
P_0c06c40e: /* original 2f66, guest PC 0x0c06c40e */
if(!s->budget--) { s->failed_pc=0x0c06c40eu; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c410;
P_0c06c410: /* original 2f56, guest PC 0x0c06c410 */
if(!s->budget--) { s->failed_pc=0x0c06c410u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c412;
P_0c06c412: /* original d31e, guest PC 0x0c06c412 */
if(!s->budget--) { s->failed_pc=0x0c06c412u; return 0; }
r[3]=read(ram,0x0c06c48cu,4);
goto P_0c06c414;
P_0c06c414: /* original d21e, guest PC 0x0c06c414 */
if(!s->budget--) { s->failed_pc=0x0c06c414u; return 0; }
r[2]=read(ram,0x0c06c490u,4);
goto P_0c06c416;
P_0c06c416: /* original 420b, guest PC 0x0c06c416 */
if(!s->budget--) { s->failed_pc=0x0c06c416u; return 0; }
target=r[2];
r[16]=code_base|0x0c06c41au;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c41au) { target=s->pc; goto dispatch; }
goto P_0c06c41a;
P_0c06c418: /* original 2f36, guest PC 0x0c06c418 */
if(!s->budget--) { s->failed_pc=0x0c06c418u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c41a;
P_0c06c41a: /* original 7f14, guest PC 0x0c06c41a */
if(!s->budget--) { s->failed_pc=0x0c06c41au; return 0; }
r[15]+=0x00000014u;
goto P_0c06c41c;
P_0c06c41c: /* original 4f26, guest PC 0x0c06c41c */
if(!s->budget--) { s->failed_pc=0x0c06c41cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c41e;
P_0c06c41e: /* original 000b, guest PC 0x0c06c41e */
if(!s->budget--) { s->failed_pc=0x0c06c41eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06c420: /* original 0009, guest PC 0x0c06c420 */
if(!s->budget--) { s->failed_pc=0x0c06c420u; return 0; }
goto P_0c06c422;
P_0c06c422: /* original 2fe6, guest PC 0x0c06c422 */
if(!s->budget--) { s->failed_pc=0x0c06c422u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c424;
P_0c06c424: /* original 4400, guest PC 0x0c06c424 */
if(!s->budget--) { s->failed_pc=0x0c06c424u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c426;
P_0c06c426: /* original 2fd6, guest PC 0x0c06c426 */
if(!s->budget--) { s->failed_pc=0x0c06c426u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c428;
P_0c06c428: /* original 6d43, guest PC 0x0c06c428 */
if(!s->budget--) { s->failed_pc=0x0c06c428u; return 0; }
r[13]=r[4];
goto P_0c06c42a;
P_0c06c42a: /* original 4f22, guest PC 0x0c06c42a */
if(!s->budget--) { s->failed_pc=0x0c06c42au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c42c;
P_0c06c42c: /* original d313, guest PC 0x0c06c42c */
if(!s->budget--) { s->failed_pc=0x0c06c42cu; return 0; }
r[3]=read(ram,0x0c06c47cu,4);
goto P_0c06c42e;
P_0c06c42e: /* original 6e63, guest PC 0x0c06c42e */
if(!s->budget--) { s->failed_pc=0x0c06c42eu; return 0; }
r[14]=r[6];
goto P_0c06c430;
P_0c06c430: /* original 7ffc, guest PC 0x0c06c430 */
if(!s->budget--) { s->failed_pc=0x0c06c430u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c432;
P_0c06c432: /* original 2f32, guest PC 0x0c06c432 */
if(!s->budget--) { s->failed_pc=0x0c06c432u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c434;
P_0c06c434: /* original e307, guest PC 0x0c06c434 */
if(!s->budget--) { s->failed_pc=0x0c06c434u; return 0; }
r[3]=0x00000007u;
goto P_0c06c436;
P_0c06c436: /* original d217, guest PC 0x0c06c436 */
if(!s->budget--) { s->failed_pc=0x0c06c436u; return 0; }
r[2]=read(ram,0x0c06c494u,4);
goto P_0c06c438;
P_0c06c438: /* original 453d, guest PC 0x0c06c438 */
if(!s->budget--) { s->failed_pc=0x0c06c438u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c06c43a;
P_0c06c43a: /* original 2d5b, guest PC 0x0c06c43a */
if(!s->budget--) { s->failed_pc=0x0c06c43au; return 0; }
r[13]|=r[5];
goto P_0c06c43c;
P_0c06c43c: /* original 6020, guest PC 0x0c06c43c */
if(!s->budget--) { s->failed_pc=0x0c06c43cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[0]=tmp;
goto P_0c06c43e;
P_0c06c43e: /* original 8801, guest PC 0x0c06c43e */
if(!s->budget--) { s->failed_pc=0x0c06c43eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c440;
P_0c06c440: /* original 8d0d, guest PC 0x0c06c440 */
if(!s->budget--) { s->failed_pc=0x0c06c440u; return 0; }
cond=r[17]&1u;
r[6]=r[0];
if(cond) { goto P_0c06c45e; }
goto P_0c06c444;
P_0c06c442: /* original 6603, guest PC 0x0c06c442 */
if(!s->budget--) { s->failed_pc=0x0c06c442u; return 0; }
r[6]=r[0];
goto P_0c06c444;
P_0c06c444: /* original 36e0, guest PC 0x0c06c444 */
if(!s->budget--) { s->failed_pc=0x0c06c444u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[14])!=0);
goto P_0c06c446;
P_0c06c446: /* original 890a, guest PC 0x0c06c446 */
if(!s->budget--) { s->failed_pc=0x0c06c446u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c45e; }
goto P_0c06c448;
P_0c06c448: /* original 2ee8, guest PC 0x0c06c448 */
if(!s->budget--) { s->failed_pc=0x0c06c448u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c06c44a;
P_0c06c44a: /* original 8908, guest PC 0x0c06c44a */
if(!s->budget--) { s->failed_pc=0x0c06c44au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c45e; }
goto P_0c06c44c;
P_0c06c44c: /* original 2f66, guest PC 0x0c06c44c */
if(!s->budget--) { s->failed_pc=0x0c06c44cu; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c44e;
P_0c06c44e: /* original 2fe6, guest PC 0x0c06c44e */
if(!s->budget--) { s->failed_pc=0x0c06c44eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c450;
P_0c06c450: /* original d311, guest PC 0x0c06c450 */
if(!s->budget--) { s->failed_pc=0x0c06c450u; return 0; }
r[3]=read(ram,0x0c06c498u,4);
goto P_0c06c452;
P_0c06c452: /* original 2f36, guest PC 0x0c06c452 */
if(!s->budget--) { s->failed_pc=0x0c06c452u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c454;
P_0c06c454: /* original d20e, guest PC 0x0c06c454 */
if(!s->budget--) { s->failed_pc=0x0c06c454u; return 0; }
r[2]=read(ram,0x0c06c490u,4);
goto P_0c06c456;
P_0c06c456: /* original 420b, guest PC 0x0c06c456 */
if(!s->budget--) { s->failed_pc=0x0c06c456u; return 0; }
target=r[2];
r[16]=code_base|0x0c06c45au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c45au) { target=s->pc; goto dispatch; }
goto P_0c06c45a;
P_0c06c458: /* original 64d3, guest PC 0x0c06c458 */
if(!s->budget--) { s->failed_pc=0x0c06c458u; return 0; }
r[4]=r[13];
goto P_0c06c45a;
P_0c06c45a: /* original a009, guest PC 0x0c06c45a */
if(!s->budget--) { s->failed_pc=0x0c06c45au; return 0; }
r[15]+=0x0000000cu;
goto P_0c06c470;
P_0c06c45c: /* original 7f0c, guest PC 0x0c06c45c */
if(!s->budget--) { s->failed_pc=0x0c06c45cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c06c45e;
P_0c06c45e: /* original e320, guest PC 0x0c06c45e */
if(!s->budget--) { s->failed_pc=0x0c06c45eu; return 0; }
r[3]=0x00000020u;
goto P_0c06c460;
P_0c06c460: /* original 65d3, guest PC 0x0c06c460 */
if(!s->budget--) { s->failed_pc=0x0c06c460u; return 0; }
r[5]=r[13];
goto P_0c06c462;
P_0c06c462: /* original e608, guest PC 0x0c06c462 */
if(!s->budget--) { s->failed_pc=0x0c06c462u; return 0; }
r[6]=0x00000008u;
goto P_0c06c464;
P_0c06c464: /* original 2f36, guest PC 0x0c06c464 */
if(!s->budget--) { s->failed_pc=0x0c06c464u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c466;
P_0c06c466: /* original d207, guest PC 0x0c06c466 */
if(!s->budget--) { s->failed_pc=0x0c06c466u; return 0; }
r[2]=read(ram,0x0c06c484u,4);
goto P_0c06c468;
P_0c06c468: /* original e701, guest PC 0x0c06c468 */
if(!s->budget--) { s->failed_pc=0x0c06c468u; return 0; }
r[7]=0x00000001u;
goto P_0c06c46a;
P_0c06c46a: /* original 420b, guest PC 0x0c06c46a */
if(!s->budget--) { s->failed_pc=0x0c06c46au; return 0; }
target=r[2];
r[16]=code_base|0x0c06c46eu;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c46eu) { target=s->pc; goto dispatch; }
goto P_0c06c46e;
P_0c06c46c: /* original 54f1, guest PC 0x0c06c46c */
if(!s->budget--) { s->failed_pc=0x0c06c46cu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c06c46e;
P_0c06c46e: /* original 7f04, guest PC 0x0c06c46e */
if(!s->budget--) { s->failed_pc=0x0c06c46eu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c470;
P_0c06c470: /* original 7f04, guest PC 0x0c06c470 */
if(!s->budget--) { s->failed_pc=0x0c06c470u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c472;
P_0c06c472: /* original 4f26, guest PC 0x0c06c472 */
if(!s->budget--) { s->failed_pc=0x0c06c472u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c474;
P_0c06c474: /* original 6df6, guest PC 0x0c06c474 */
if(!s->budget--) { s->failed_pc=0x0c06c474u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06c476;
P_0c06c476: /* original 000b, guest PC 0x0c06c476 */
if(!s->budget--) { s->failed_pc=0x0c06c476u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06c478: /* original 6ef6, guest PC 0x0c06c478 */
if(!s->budget--) { s->failed_pc=0x0c06c478u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06c47au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06c47au; return 0; } return 1;
P_0c06c51e: /* original 2fe6, guest PC 0x0c06c51e */
if(!s->budget--) { s->failed_pc=0x0c06c51eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c520;
P_0c06c520: /* original 2fd6, guest PC 0x0c06c520 */
if(!s->budget--) { s->failed_pc=0x0c06c520u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c522;
P_0c06c522: /* original 2fc6, guest PC 0x0c06c522 */
if(!s->budget--) { s->failed_pc=0x0c06c522u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c524;
P_0c06c524: /* original 2fb6, guest PC 0x0c06c524 */
if(!s->budget--) { s->failed_pc=0x0c06c524u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c526;
P_0c06c526: /* original 903c, guest PC 0x0c06c526 */
if(!s->budget--) { s->failed_pc=0x0c06c526u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c5a2u,2);
goto P_0c06c528;
P_0c06c528: /* original d423, guest PC 0x0c06c528 */
if(!s->budget--) { s->failed_pc=0x0c06c528u; return 0; }
r[4]=read(ram,0x0c06c5b8u,4);
goto P_0c06c52a;
P_0c06c52a: /* original 4f22, guest PC 0x0c06c52a */
if(!s->budget--) { s->failed_pc=0x0c06c52au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c52c;
P_0c06c52c: /* original 034c, guest PC 0x0c06c52c */
if(!s->budget--) { s->failed_pc=0x0c06c52cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c52e;
P_0c06c52e: /* original 7ffc, guest PC 0x0c06c52e */
if(!s->budget--) { s->failed_pc=0x0c06c52eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c530;
P_0c06c530: /* original 2f32, guest PC 0x0c06c530 */
if(!s->budget--) { s->failed_pc=0x0c06c530u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c532;
P_0c06c532: /* original 9037, guest PC 0x0c06c532 */
if(!s->budget--) { s->failed_pc=0x0c06c532u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c5a4u,2);
goto P_0c06c534;
P_0c06c534: /* original 0b4c, guest PC 0x0c06c534 */
if(!s->budget--) { s->failed_pc=0x0c06c534u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c536;
P_0c06c536: /* original 9036, guest PC 0x0c06c536 */
if(!s->budget--) { s->failed_pc=0x0c06c536u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c5a6u,2);
goto P_0c06c538;
P_0c06c538: /* original 064c, guest PC 0x0c06c538 */
if(!s->budget--) { s->failed_pc=0x0c06c538u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c53a;
P_0c06c53a: /* original 7001, guest PC 0x0c06c53a */
if(!s->budget--) { s->failed_pc=0x0c06c53au; return 0; }
r[0]+=0x00000001u;
goto P_0c06c53c;
P_0c06c53c: /* original 074c, guest PC 0x0c06c53c */
if(!s->budget--) { s->failed_pc=0x0c06c53cu; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c53e;
P_0c06c53e: /* original 700d, guest PC 0x0c06c53e */
if(!s->budget--) { s->failed_pc=0x0c06c53eu; return 0; }
r[0]+=0x0000000du;
goto P_0c06c540;
P_0c06c540: /* original 054c, guest PC 0x0c06c540 */
if(!s->budget--) { s->failed_pc=0x0c06c540u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c542;
P_0c06c542: /* original 6033, guest PC 0x0c06c542 */
if(!s->budget--) { s->failed_pc=0x0c06c542u; return 0; }
r[0]=r[3];
goto P_0c06c544;
P_0c06c544: /* original 8801, guest PC 0x0c06c544 */
if(!s->budget--) { s->failed_pc=0x0c06c544u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c546;
P_0c06c546: /* original 8907, guest PC 0x0c06c546 */
if(!s->budget--) { s->failed_pc=0x0c06c546u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c558; }
goto P_0c06c548;
P_0c06c548: /* original 60b3, guest PC 0x0c06c548 */
if(!s->budget--) { s->failed_pc=0x0c06c548u; return 0; }
r[0]=r[11];
goto P_0c06c54a;
P_0c06c54a: /* original 8801, guest PC 0x0c06c54a */
if(!s->budget--) { s->failed_pc=0x0c06c54au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c54c;
P_0c06c54c: /* original 8f01, guest PC 0x0c06c54c */
if(!s->budget--) { s->failed_pc=0x0c06c54cu; return 0; }
cond=r[17]&1u;
r[14]=0x00000005u;
if(!cond) { goto P_0c06c552; }
goto P_0c06c550;
P_0c06c54e: /* original ee05, guest PC 0x0c06c54e */
if(!s->budget--) { s->failed_pc=0x0c06c54eu; return 0; }
r[14]=0x00000005u;
goto P_0c06c550;
P_0c06c550: /* original ee27, guest PC 0x0c06c550 */
if(!s->budget--) { s->failed_pc=0x0c06c550u; return 0; }
r[14]=0x00000027u;
goto P_0c06c552;
P_0c06c552: /* original 6d63, guest PC 0x0c06c552 */
if(!s->budget--) { s->failed_pc=0x0c06c552u; return 0; }
r[13]=r[6];
goto P_0c06c554;
P_0c06c554: /* original a00b, guest PC 0x0c06c554 */
if(!s->budget--) { s->failed_pc=0x0c06c554u; return 0; }
r[12]=r[7];
goto P_0c06c56e;
P_0c06c556: /* original 6c73, guest PC 0x0c06c556 */
if(!s->budget--) { s->failed_pc=0x0c06c556u; return 0; }
r[12]=r[7];
goto P_0c06c558;
P_0c06c558: /* original 60b3, guest PC 0x0c06c558 */
if(!s->budget--) { s->failed_pc=0x0c06c558u; return 0; }
r[0]=r[11];
goto P_0c06c55a;
P_0c06c55a: /* original 8801, guest PC 0x0c06c55a */
if(!s->budget--) { s->failed_pc=0x0c06c55au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c55c;
P_0c06c55c: /* original ee05, guest PC 0x0c06c55c */
if(!s->budget--) { s->failed_pc=0x0c06c55cu; return 0; }
r[14]=0x00000005u;
goto P_0c06c55e;
P_0c06c55e: /* original 6d63, guest PC 0x0c06c55e */
if(!s->budget--) { s->failed_pc=0x0c06c55eu; return 0; }
r[13]=r[6];
goto P_0c06c560;
P_0c06c560: /* original 8f05, guest PC 0x0c06c560 */
if(!s->budget--) { s->failed_pc=0x0c06c560u; return 0; }
cond=r[17]&1u;
r[12]=r[7];
if(!cond) { goto P_0c06c56e; }
goto P_0c06c564;
P_0c06c562: /* original 6c73, guest PC 0x0c06c562 */
if(!s->budget--) { s->failed_pc=0x0c06c562u; return 0; }
r[12]=r[7];
goto P_0c06c564;
P_0c06c564: /* original 9020, guest PC 0x0c06c564 */
if(!s->budget--) { s->failed_pc=0x0c06c564u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c5a8u,2);
goto P_0c06c566;
P_0c06c566: /* original ee27, guest PC 0x0c06c566 */
if(!s->budget--) { s->failed_pc=0x0c06c566u; return 0; }
r[14]=0x00000027u;
goto P_0c06c568;
P_0c06c568: /* original 0d4c, guest PC 0x0c06c568 */
if(!s->budget--) { s->failed_pc=0x0c06c568u; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c56a;
P_0c06c56a: /* original 7001, guest PC 0x0c06c56a */
if(!s->budget--) { s->failed_pc=0x0c06c56au; return 0; }
r[0]+=0x00000001u;
goto P_0c06c56c;
P_0c06c56c: /* original 0c4c, guest PC 0x0c06c56c */
if(!s->budget--) { s->failed_pc=0x0c06c56cu; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c56e;
P_0c06c56e: /* original 9316, guest PC 0x0c06c56e */
if(!s->budget--) { s->failed_pc=0x0c06c56eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c59eu,2);
goto P_0c06c570;
P_0c06c570: /* original 64e3, guest PC 0x0c06c570 */
if(!s->budget--) { s->failed_pc=0x0c06c570u; return 0; }
r[4]=r[14];
goto P_0c06c572;
P_0c06c572: /* original 6b53, guest PC 0x0c06c572 */
if(!s->budget--) { s->failed_pc=0x0c06c572u; return 0; }
r[11]=r[5];
goto P_0c06c574;
P_0c06c574: /* original 4400, guest PC 0x0c06c574 */
if(!s->budget--) { s->failed_pc=0x0c06c574u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c576;
P_0c06c576: /* original bef3, guest PC 0x0c06c576 */
if(!s->budget--) { s->failed_pc=0x0c06c576u; return 0; }
target=code_base|0x0c06c360u; r[16]=code_base|0x0c06c57au;
r[4]|=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c57au) { target=s->pc; goto dispatch; }
goto P_0c06c57a;
P_0c06c578: /* original 243b, guest PC 0x0c06c578 */
if(!s->budget--) { s->failed_pc=0x0c06c578u; return 0; }
r[4]|=r[3];
goto P_0c06c57a;
P_0c06c57a: /* original 2008, guest PC 0x0c06c57a */
if(!s->budget--) { s->failed_pc=0x0c06c57au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06c57c;
P_0c06c57c: /* original 8906, guest PC 0x0c06c57c */
if(!s->budget--) { s->failed_pc=0x0c06c57cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c58c; }
goto P_0c06c57e;
P_0c06c57e: /* original 66d3, guest PC 0x0c06c57e */
if(!s->budget--) { s->failed_pc=0x0c06c57eu; return 0; }
r[6]=r[13];
goto P_0c06c580;
P_0c06c580: /* original e52e, guest PC 0x0c06c580 */
if(!s->budget--) { s->failed_pc=0x0c06c580u; return 0; }
r[5]=0x0000002eu;
goto P_0c06c582;
P_0c06c582: /* original 2fb6, guest PC 0x0c06c582 */
if(!s->budget--) { s->failed_pc=0x0c06c582u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c584;
P_0c06c584: /* original 67c3, guest PC 0x0c06c584 */
if(!s->budget--) { s->failed_pc=0x0c06c584u; return 0; }
r[7]=r[12];
goto P_0c06c586;
P_0c06c586: /* original b2ae, guest PC 0x0c06c586 */
if(!s->budget--) { s->failed_pc=0x0c06c586u; return 0; }
target=code_base|0x0c06cae6u; r[16]=code_base|0x0c06c58au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c58au) { target=s->pc; goto dispatch; }
goto P_0c06c58a;
P_0c06c588: /* original 64e3, guest PC 0x0c06c588 */
if(!s->budget--) { s->failed_pc=0x0c06c588u; return 0; }
r[4]=r[14];
goto P_0c06c58a;
P_0c06c58a: /* original 7f04, guest PC 0x0c06c58a */
if(!s->budget--) { s->failed_pc=0x0c06c58au; return 0; }
r[15]+=0x00000004u;
goto P_0c06c58c;
P_0c06c58c: /* original 7f04, guest PC 0x0c06c58c */
if(!s->budget--) { s->failed_pc=0x0c06c58cu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c58e;
P_0c06c58e: /* original 4f26, guest PC 0x0c06c58e */
if(!s->budget--) { s->failed_pc=0x0c06c58eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c590;
P_0c06c590: /* original 6bf6, guest PC 0x0c06c590 */
if(!s->budget--) { s->failed_pc=0x0c06c590u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06c592;
P_0c06c592: /* original 6cf6, guest PC 0x0c06c592 */
if(!s->budget--) { s->failed_pc=0x0c06c592u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06c594;
P_0c06c594: /* original 6df6, guest PC 0x0c06c594 */
if(!s->budget--) { s->failed_pc=0x0c06c594u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06c596;
P_0c06c596: /* original 000b, guest PC 0x0c06c596 */
if(!s->budget--) { s->failed_pc=0x0c06c596u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06c598: /* original 6ef6, guest PC 0x0c06c598 */
if(!s->budget--) { s->failed_pc=0x0c06c598u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06c59au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06c59au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
