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
int vf3_away_batch7_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c055330u: goto P_0c055330;
case 0x0c055332u: goto P_0c055332;
case 0x0c055334u: goto P_0c055334;
case 0x0c055336u: goto P_0c055336;
case 0x0c055338u: goto P_0c055338;
case 0x0c05533au: goto P_0c05533a;
case 0x0c05533cu: goto P_0c05533c;
case 0x0c05533eu: goto P_0c05533e;
case 0x0c055340u: goto P_0c055340;
case 0x0c055342u: goto P_0c055342;
case 0x0c055344u: goto P_0c055344;
case 0x0c055346u: goto P_0c055346;
case 0x0c055348u: goto P_0c055348;
case 0x0c05534au: goto P_0c05534a;
case 0x0c05534cu: goto P_0c05534c;
case 0x0c05534eu: goto P_0c05534e;
case 0x0c055350u: goto P_0c055350;
case 0x0c055352u: goto P_0c055352;
case 0x0c055354u: goto P_0c055354;
case 0x0c055356u: goto P_0c055356;
case 0x0c055358u: goto P_0c055358;
case 0x0c05535au: goto P_0c05535a;
case 0x0c05535cu: goto P_0c05535c;
case 0x0c05535eu: goto P_0c05535e;
case 0x0c055360u: goto P_0c055360;
case 0x0c055362u: goto P_0c055362;
case 0x0c055364u: goto P_0c055364;
case 0x0c055366u: goto P_0c055366;
case 0x0c055368u: goto P_0c055368;
case 0x0c05536au: goto P_0c05536a;
case 0x0c05536cu: goto P_0c05536c;
case 0x0c05536eu: goto P_0c05536e;
case 0x0c055370u: goto P_0c055370;
case 0x0c055372u: goto P_0c055372;
case 0x0c055374u: goto P_0c055374;
case 0x0c055376u: goto P_0c055376;
case 0x0c055378u: goto P_0c055378;
case 0x0c05537au: goto P_0c05537a;
case 0x0c05537cu: goto P_0c05537c;
case 0x0c05537eu: goto P_0c05537e;
case 0x0c055380u: goto P_0c055380;
case 0x0c055382u: goto P_0c055382;
case 0x0c055384u: goto P_0c055384;
case 0x0c055386u: goto P_0c055386;
case 0x0c055388u: goto P_0c055388;
case 0x0c05538au: goto P_0c05538a;
case 0x0c05538cu: goto P_0c05538c;
case 0x0c05538eu: goto P_0c05538e;
case 0x0c055390u: goto P_0c055390;
case 0x0c055392u: goto P_0c055392;
case 0x0c055394u: goto P_0c055394;
case 0x0c055396u: goto P_0c055396;
case 0x0c055398u: goto P_0c055398;
case 0x0c05539au: goto P_0c05539a;
case 0x0c05539cu: goto P_0c05539c;
case 0x0c05539eu: goto P_0c05539e;
case 0x0c0553a0u: goto P_0c0553a0;
case 0x0c0553a2u: goto P_0c0553a2;
case 0x0c0553a4u: goto P_0c0553a4;
case 0x0c0553a6u: goto P_0c0553a6;
case 0x0c0553a8u: goto P_0c0553a8;
case 0x0c0553aau: goto P_0c0553aa;
case 0x0c0553acu: goto P_0c0553ac;
case 0x0c0553aeu: goto P_0c0553ae;
case 0x0c0553b0u: goto P_0c0553b0;
case 0x0c0553b2u: goto P_0c0553b2;
case 0x0c0553b4u: goto P_0c0553b4;
case 0x0c0553b6u: goto P_0c0553b6;
case 0x0c0553b8u: goto P_0c0553b8;
case 0x0c0553bau: goto P_0c0553ba;
case 0x0c055408u: goto P_0c055408;
case 0x0c05540au: goto P_0c05540a;
case 0x0c05540cu: goto P_0c05540c;
case 0x0c05540eu: goto P_0c05540e;
case 0x0c055410u: goto P_0c055410;
case 0x0c055412u: goto P_0c055412;
case 0x0c055414u: goto P_0c055414;
case 0x0c055416u: goto P_0c055416;
case 0x0c055418u: goto P_0c055418;
case 0x0c05541au: goto P_0c05541a;
case 0x0c05541cu: goto P_0c05541c;
case 0x0c05541eu: goto P_0c05541e;
case 0x0c055420u: goto P_0c055420;
case 0x0c055422u: goto P_0c055422;
case 0x0c055424u: goto P_0c055424;
case 0x0c055426u: goto P_0c055426;
case 0x0c055428u: goto P_0c055428;
case 0x0c05542au: goto P_0c05542a;
case 0x0c05542cu: goto P_0c05542c;
case 0x0c05542eu: goto P_0c05542e;
case 0x0c055430u: goto P_0c055430;
case 0x0c055432u: goto P_0c055432;
case 0x0c055434u: goto P_0c055434;
case 0x0c055436u: goto P_0c055436;
case 0x0c055438u: goto P_0c055438;
case 0x0c05543au: goto P_0c05543a;
case 0x0c05543cu: goto P_0c05543c;
case 0x0c05543eu: goto P_0c05543e;
case 0x0c055440u: goto P_0c055440;
case 0x0c055442u: goto P_0c055442;
case 0x0c055444u: goto P_0c055444;
case 0x0c055446u: goto P_0c055446;
case 0x0c055448u: goto P_0c055448;
case 0x0c05544au: goto P_0c05544a;
case 0x0c05544cu: goto P_0c05544c;
case 0x0c05544eu: goto P_0c05544e;
case 0x0c055450u: goto P_0c055450;
case 0x0c055452u: goto P_0c055452;
case 0x0c055454u: goto P_0c055454;
case 0x0c055456u: goto P_0c055456;
case 0x0c055458u: goto P_0c055458;
case 0x0c05545au: goto P_0c05545a;
case 0x0c05545cu: goto P_0c05545c;
case 0x0c05545eu: goto P_0c05545e;
case 0x0c055460u: goto P_0c055460;
case 0x0c055462u: goto P_0c055462;
case 0x0c055464u: goto P_0c055464;
case 0x0c055466u: goto P_0c055466;
case 0x0c055468u: goto P_0c055468;
case 0x0c05546au: goto P_0c05546a;
case 0x0c05546cu: goto P_0c05546c;
case 0x0c05546eu: goto P_0c05546e;
case 0x0c055470u: goto P_0c055470;
case 0x0c055472u: goto P_0c055472;
case 0x0c055474u: goto P_0c055474;
case 0x0c055476u: goto P_0c055476;
case 0x0c055478u: goto P_0c055478;
case 0x0c05547au: goto P_0c05547a;
case 0x0c05547cu: goto P_0c05547c;
case 0x0c05547eu: goto P_0c05547e;
case 0x0c055480u: goto P_0c055480;
case 0x0c055482u: goto P_0c055482;
case 0x0c055484u: goto P_0c055484;
case 0x0c055486u: goto P_0c055486;
case 0x0c055488u: goto P_0c055488;
case 0x0c05548au: goto P_0c05548a;
case 0x0c05548cu: goto P_0c05548c;
case 0x0c05548eu: goto P_0c05548e;
case 0x0c055490u: goto P_0c055490;
case 0x0c055492u: goto P_0c055492;
case 0x0c055494u: goto P_0c055494;
case 0x0c055496u: goto P_0c055496;
case 0x0c055498u: goto P_0c055498;
case 0x0c05549au: goto P_0c05549a;
case 0x0c05549cu: goto P_0c05549c;
case 0x0c05549eu: goto P_0c05549e;
case 0x0c0554a0u: goto P_0c0554a0;
case 0x0c0554a2u: goto P_0c0554a2;
case 0x0c0554a4u: goto P_0c0554a4;
case 0x0c0554a6u: goto P_0c0554a6;
case 0x0c0554a8u: goto P_0c0554a8;
case 0x0c0554aau: goto P_0c0554aa;
case 0x0c0554acu: goto P_0c0554ac;
case 0x0c0554aeu: goto P_0c0554ae;
case 0x0c0554b0u: goto P_0c0554b0;
case 0x0c0554b2u: goto P_0c0554b2;
case 0x0c0554b4u: goto P_0c0554b4;
case 0x0c0554b6u: goto P_0c0554b6;
case 0x0c0554b8u: goto P_0c0554b8;
case 0x0c0554bau: goto P_0c0554ba;
case 0x0c0554bcu: goto P_0c0554bc;
case 0x0c0554beu: goto P_0c0554be;
case 0x0c0554c0u: goto P_0c0554c0;
case 0x0c0554c2u: goto P_0c0554c2;
case 0x0c0554c4u: goto P_0c0554c4;
case 0x0c0554c6u: goto P_0c0554c6;
case 0x0c0554c8u: goto P_0c0554c8;
case 0x0c0554cau: goto P_0c0554ca;
case 0x0c0554dcu: goto P_0c0554dc;
case 0x0c0554deu: goto P_0c0554de;
case 0x0c0554e0u: goto P_0c0554e0;
case 0x0c0554e2u: goto P_0c0554e2;
case 0x0c0554e4u: goto P_0c0554e4;
case 0x0c0554e6u: goto P_0c0554e6;
case 0x0c0554e8u: goto P_0c0554e8;
case 0x0c0554eau: goto P_0c0554ea;
case 0x0c0554ecu: goto P_0c0554ec;
case 0x0c0554eeu: goto P_0c0554ee;
case 0x0c0554f0u: goto P_0c0554f0;
case 0x0c0554f2u: goto P_0c0554f2;
case 0x0c0554f4u: goto P_0c0554f4;
case 0x0c0554f6u: goto P_0c0554f6;
case 0x0c0554f8u: goto P_0c0554f8;
case 0x0c0554fau: goto P_0c0554fa;
case 0x0c0554fcu: goto P_0c0554fc;
case 0x0c0554feu: goto P_0c0554fe;
case 0x0c055500u: goto P_0c055500;
case 0x0c055502u: goto P_0c055502;
case 0x0c055504u: goto P_0c055504;
case 0x0c055506u: goto P_0c055506;
case 0x0c055508u: goto P_0c055508;
case 0x0c05550au: goto P_0c05550a;
case 0x0c05550cu: goto P_0c05550c;
case 0x0c05550eu: goto P_0c05550e;
case 0x0c055510u: goto P_0c055510;
case 0x0c055512u: goto P_0c055512;
case 0x0c055514u: goto P_0c055514;
case 0x0c055516u: goto P_0c055516;
case 0x0c055518u: goto P_0c055518;
case 0x0c05551au: goto P_0c05551a;
case 0x0c05551cu: goto P_0c05551c;
case 0x0c05551eu: goto P_0c05551e;
case 0x0c055520u: goto P_0c055520;
case 0x0c055522u: goto P_0c055522;
case 0x0c055524u: goto P_0c055524;
case 0x0c055526u: goto P_0c055526;
case 0x0c055528u: goto P_0c055528;
case 0x0c05552au: goto P_0c05552a;
case 0x0c05552cu: goto P_0c05552c;
case 0x0c05552eu: goto P_0c05552e;
case 0x0c055530u: goto P_0c055530;
case 0x0c055532u: goto P_0c055532;
case 0x0c055534u: goto P_0c055534;
case 0x0c055536u: goto P_0c055536;
case 0x0c055538u: goto P_0c055538;
case 0x0c05553au: goto P_0c05553a;
case 0x0c05553cu: goto P_0c05553c;
case 0x0c05553eu: goto P_0c05553e;
case 0x0c055540u: goto P_0c055540;
case 0x0c055542u: goto P_0c055542;
case 0x0c055544u: goto P_0c055544;
case 0x0c055546u: goto P_0c055546;
case 0x0c055548u: goto P_0c055548;
case 0x0c05554au: goto P_0c05554a;
case 0x0c05554cu: goto P_0c05554c;
case 0x0c05554eu: goto P_0c05554e;
case 0x0c055550u: goto P_0c055550;
case 0x0c055552u: goto P_0c055552;
case 0x0c055554u: goto P_0c055554;
case 0x0c055556u: goto P_0c055556;
case 0x0c055558u: goto P_0c055558;
case 0x0c05555au: goto P_0c05555a;
case 0x0c05555cu: goto P_0c05555c;
case 0x0c05555eu: goto P_0c05555e;
case 0x0c055560u: goto P_0c055560;
case 0x0c055562u: goto P_0c055562;
default: return vf3_matrix_family(target,s,ram);
}
P_0c055330: /* original 2f46, guest PC 0x0c055330 */
if(!s->budget--) { s->failed_pc=0x0c055330u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055332;
P_0c055332: /* original 2f56, guest PC 0x0c055332 */
if(!s->budget--) { s->failed_pc=0x0c055332u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055334;
P_0c055334: /* original 2f66, guest PC 0x0c055334 */
if(!s->budget--) { s->failed_pc=0x0c055334u; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055336;
P_0c055336: /* original 2f76, guest PC 0x0c055336 */
if(!s->budget--) { s->failed_pc=0x0c055336u; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055338;
P_0c055338: /* original 55f6, guest PC 0x0c055338 */
if(!s->budget--) { s->failed_pc=0x0c055338u; return 0; }
r[5]=read(ram,r[15]+24,4);
goto P_0c05533a;
P_0c05533a: /* original 54f7, guest PC 0x0c05533a */
if(!s->budget--) { s->failed_pc=0x0c05533au; return 0; }
r[4]=read(ram,r[15]+28,4);
goto P_0c05533c;
P_0c05533c: /* original 57f4, guest PC 0x0c05533c */
if(!s->budget--) { s->failed_pc=0x0c05533cu; return 0; }
r[7]=read(ram,r[15]+16,4);
goto P_0c05533e;
P_0c05533e: /* original 56f5, guest PC 0x0c05533e */
if(!s->budget--) { s->failed_pc=0x0c05533eu; return 0; }
r[6]=read(ram,r[15]+20,4);
goto P_0c055340;
P_0c055340: /* original 2f86, guest PC 0x0c055340 */
if(!s->budget--) { s->failed_pc=0x0c055340u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055342;
P_0c055342: /* original 2f96, guest PC 0x0c055342 */
if(!s->budget--) { s->failed_pc=0x0c055342u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055344;
P_0c055344: /* original 2fa6, guest PC 0x0c055344 */
if(!s->budget--) { s->failed_pc=0x0c055344u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055346;
P_0c055346: /* original 2fb6, guest PC 0x0c055346 */
if(!s->budget--) { s->failed_pc=0x0c055346u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055348;
P_0c055348: /* original d01c, guest PC 0x0c055348 */
if(!s->budget--) { s->failed_pc=0x0c055348u; return 0; }
r[0]=read(ram,0x0c0553bcu,4);
goto P_0c05534a;
P_0c05534a: /* original 6a43, guest PC 0x0c05534a */
if(!s->budget--) { s->failed_pc=0x0c05534au; return 0; }
r[10]=r[4];
goto P_0c05534c;
P_0c05534c: /* original 6b63, guest PC 0x0c05534c */
if(!s->budget--) { s->failed_pc=0x0c05534cu; return 0; }
r[11]=r[6];
goto P_0c05534e;
P_0c05534e: /* original 6843, guest PC 0x0c05534e */
if(!s->budget--) { s->failed_pc=0x0c05534eu; return 0; }
r[8]=r[4];
goto P_0c055350;
P_0c055350: /* original 2809, guest PC 0x0c055350 */
if(!s->budget--) { s->failed_pc=0x0c055350u; return 0; }
r[8]&=r[0];
goto P_0c055352;
P_0c055352: /* original 6963, guest PC 0x0c055352 */
if(!s->budget--) { s->failed_pc=0x0c055352u; return 0; }
r[9]=r[6];
goto P_0c055354;
P_0c055354: /* original 2909, guest PC 0x0c055354 */
if(!s->budget--) { s->failed_pc=0x0c055354u; return 0; }
r[9]&=r[0];
goto P_0c055356;
P_0c055356: /* original d01a, guest PC 0x0c055356 */
if(!s->budget--) { s->failed_pc=0x0c055356u; return 0; }
r[0]=read(ram,0x0c0553c0u,4);
goto P_0c055358;
P_0c055358: /* original 2409, guest PC 0x0c055358 */
if(!s->budget--) { s->failed_pc=0x0c055358u; return 0; }
r[4]&=r[0];
goto P_0c05535a;
P_0c05535a: /* original 2609, guest PC 0x0c05535a */
if(!s->budget--) { s->failed_pc=0x0c05535au; return 0; }
r[6]&=r[0];
goto P_0c05535c;
P_0c05535c: /* original d017, guest PC 0x0c05535c */
if(!s->budget--) { s->failed_pc=0x0c05535cu; return 0; }
r[0]=read(ram,0x0c0553bcu,4);
goto P_0c05535e;
P_0c05535e: /* original 3800, guest PC 0x0c05535e */
if(!s->budget--) { s->failed_pc=0x0c05535eu; return 0; }
r[17]=(r[17]&~1u)|((r[8]==r[0])!=0);
goto P_0c055360;
P_0c055360: /* original 8914, guest PC 0x0c055360 */
if(!s->budget--) { s->failed_pc=0x0c055360u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05538c; }
goto P_0c055362;
P_0c055362: /* original 3900, guest PC 0x0c055362 */
if(!s->budget--) { s->failed_pc=0x0c055362u; return 0; }
r[17]=(r[17]&~1u)|((r[9]==r[0])!=0);
goto P_0c055364;
P_0c055364: /* original 8918, guest PC 0x0c055364 */
if(!s->budget--) { s->failed_pc=0x0c055364u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055398; }
goto P_0c055366;
P_0c055366: /* original 2888, guest PC 0x0c055366 */
if(!s->budget--) { s->failed_pc=0x0c055366u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c055368;
P_0c055368: /* original 891c, guest PC 0x0c055368 */
if(!s->budget--) { s->failed_pc=0x0c055368u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0553a4; }
goto P_0c05536a;
P_0c05536a: /* original 3ba0, guest PC 0x0c05536a */
if(!s->budget--) { s->failed_pc=0x0c05536au; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[10])!=0);
goto P_0c05536c;
P_0c05536c: /* original 8b03, guest PC 0x0c05536c */
if(!s->budget--) { s->failed_pc=0x0c05536cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055376; }
goto P_0c05536e;
P_0c05536e: /* original 3750, guest PC 0x0c05536e */
if(!s->budget--) { s->failed_pc=0x0c05536eu; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[5])!=0);
goto P_0c055370;
P_0c055370: /* original 8b01, guest PC 0x0c055370 */
if(!s->budget--) { s->failed_pc=0x0c055370u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055376; }
goto P_0c055372;
P_0c055372: /* original a001, guest PC 0x0c055372 */
if(!s->budget--) { s->failed_pc=0x0c055372u; return 0; }
r[0]=0x00000000u;
goto P_0c055378;
P_0c055374: /* original e000, guest PC 0x0c055374 */
if(!s->budget--) { s->failed_pc=0x0c055374u; return 0; }
r[0]=0x00000000u;
goto P_0c055376;
P_0c055376: /* original e001, guest PC 0x0c055376 */
if(!s->budget--) { s->failed_pc=0x0c055376u; return 0; }
r[0]=0x00000001u;
goto P_0c055378;
P_0c055378: /* original 6bf6, guest PC 0x0c055378 */
if(!s->budget--) { s->failed_pc=0x0c055378u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05537a;
P_0c05537a: /* original 6af6, guest PC 0x0c05537a */
if(!s->budget--) { s->failed_pc=0x0c05537au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05537c;
P_0c05537c: /* original 69f6, guest PC 0x0c05537c */
if(!s->budget--) { s->failed_pc=0x0c05537cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05537e;
P_0c05537e: /* original 68f6, guest PC 0x0c05537e */
if(!s->budget--) { s->failed_pc=0x0c05537eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c055380;
P_0c055380: /* original 67f6, guest PC 0x0c055380 */
if(!s->budget--) { s->failed_pc=0x0c055380u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[7]=tmp;
goto P_0c055382;
P_0c055382: /* original 66f6, guest PC 0x0c055382 */
if(!s->budget--) { s->failed_pc=0x0c055382u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[6]=tmp;
goto P_0c055384;
P_0c055384: /* original 65f6, guest PC 0x0c055384 */
if(!s->budget--) { s->failed_pc=0x0c055384u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[5]=tmp;
goto P_0c055386;
P_0c055386: /* original 64f6, guest PC 0x0c055386 */
if(!s->budget--) { s->failed_pc=0x0c055386u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c055388;
P_0c055388: /* original 000b, guest PC 0x0c055388 */
if(!s->budget--) { s->failed_pc=0x0c055388u; return 0; }
target=r[16];
r[15]+=0x00000010u;
s->pc=target; return ram->oob==0;
P_0c05538a: /* original 7f10, guest PC 0x0c05538a */
if(!s->budget--) { s->failed_pc=0x0c05538au; return 0; }
r[15]+=0x00000010u;
goto P_0c05538c;
P_0c05538c: /* original 2448, guest PC 0x0c05538c */
if(!s->budget--) { s->failed_pc=0x0c05538cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c05538e;
P_0c05538e: /* original 8bf2, guest PC 0x0c05538e */
if(!s->budget--) { s->failed_pc=0x0c05538eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055376; }
goto P_0c055390;
P_0c055390: /* original 2558, guest PC 0x0c055390 */
if(!s->budget--) { s->failed_pc=0x0c055390u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c055392;
P_0c055392: /* original 8bf0, guest PC 0x0c055392 */
if(!s->budget--) { s->failed_pc=0x0c055392u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055376; }
goto P_0c055394;
P_0c055394: /* original afe5, guest PC 0x0c055394 */
if(!s->budget--) { s->failed_pc=0x0c055394u; return 0; }
goto P_0c055362;
P_0c055396: /* original 0009, guest PC 0x0c055396 */
if(!s->budget--) { s->failed_pc=0x0c055396u; return 0; }
goto P_0c055398;
P_0c055398: /* original 2668, guest PC 0x0c055398 */
if(!s->budget--) { s->failed_pc=0x0c055398u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c05539a;
P_0c05539a: /* original 8bec, guest PC 0x0c05539a */
if(!s->budget--) { s->failed_pc=0x0c05539au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055376; }
goto P_0c05539c;
P_0c05539c: /* original 2778, guest PC 0x0c05539c */
if(!s->budget--) { s->failed_pc=0x0c05539cu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c05539e;
P_0c05539e: /* original 8bea, guest PC 0x0c05539e */
if(!s->budget--) { s->failed_pc=0x0c05539eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055376; }
goto P_0c0553a0;
P_0c0553a0: /* original afe1, guest PC 0x0c0553a0 */
if(!s->budget--) { s->failed_pc=0x0c0553a0u; return 0; }
goto P_0c055366;
P_0c0553a2: /* original 0009, guest PC 0x0c0553a2 */
if(!s->budget--) { s->failed_pc=0x0c0553a2u; return 0; }
goto P_0c0553a4;
P_0c0553a4: /* original 2998, guest PC 0x0c0553a4 */
if(!s->budget--) { s->failed_pc=0x0c0553a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0553a6;
P_0c0553a6: /* original 8be6, guest PC 0x0c0553a6 */
if(!s->budget--) { s->failed_pc=0x0c0553a6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055376; }
goto P_0c0553a8;
P_0c0553a8: /* original 2448, guest PC 0x0c0553a8 */
if(!s->budget--) { s->failed_pc=0x0c0553a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0553aa;
P_0c0553aa: /* original 8bde, guest PC 0x0c0553aa */
if(!s->budget--) { s->failed_pc=0x0c0553aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05536a; }
goto P_0c0553ac;
P_0c0553ac: /* original 2558, guest PC 0x0c0553ac */
if(!s->budget--) { s->failed_pc=0x0c0553acu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0553ae;
P_0c0553ae: /* original 8bdc, guest PC 0x0c0553ae */
if(!s->budget--) { s->failed_pc=0x0c0553aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05536a; }
goto P_0c0553b0;
P_0c0553b0: /* original 2668, guest PC 0x0c0553b0 */
if(!s->budget--) { s->failed_pc=0x0c0553b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0553b2;
P_0c0553b2: /* original 8be0, guest PC 0x0c0553b2 */
if(!s->budget--) { s->failed_pc=0x0c0553b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055376; }
goto P_0c0553b4;
P_0c0553b4: /* original 2778, guest PC 0x0c0553b4 */
if(!s->budget--) { s->failed_pc=0x0c0553b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0553b6;
P_0c0553b6: /* original 8bde, guest PC 0x0c0553b6 */
if(!s->budget--) { s->failed_pc=0x0c0553b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055376; }
goto P_0c0553b8;
P_0c0553b8: /* original afde, guest PC 0x0c0553b8 */
if(!s->budget--) { s->failed_pc=0x0c0553b8u; return 0; }
r[0]=0x00000000u;
goto P_0c055378;
P_0c0553ba: /* original e000, guest PC 0x0c0553ba */
if(!s->budget--) { s->failed_pc=0x0c0553bau; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c0553bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0553bcu; return 0; } return 1;
P_0c055408: /* original 2fe6, guest PC 0x0c055408 */
if(!s->budget--) { s->failed_pc=0x0c055408u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05540a;
P_0c05540a: /* original 2fd6, guest PC 0x0c05540a */
if(!s->budget--) { s->failed_pc=0x0c05540au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05540c;
P_0c05540c: /* original 2fc6, guest PC 0x0c05540c */
if(!s->budget--) { s->failed_pc=0x0c05540cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05540e;
P_0c05540e: /* original 2fb6, guest PC 0x0c05540e */
if(!s->budget--) { s->failed_pc=0x0c05540eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055410;
P_0c055410: /* original 2fa6, guest PC 0x0c055410 */
if(!s->budget--) { s->failed_pc=0x0c055410u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055412;
P_0c055412: /* original 6a63, guest PC 0x0c055412 */
if(!s->budget--) { s->failed_pc=0x0c055412u; return 0; }
r[10]=r[6];
goto P_0c055414;
P_0c055414: /* original d32d, guest PC 0x0c055414 */
if(!s->budget--) { s->failed_pc=0x0c055414u; return 0; }
r[3]=read(ram,0x0c0554ccu,4);
goto P_0c055416;
P_0c055416: /* original e610, guest PC 0x0c055416 */
if(!s->budget--) { s->failed_pc=0x0c055416u; return 0; }
r[6]=0x00000010u;
goto P_0c055418;
P_0c055418: /* original 2f96, guest PC 0x0c055418 */
if(!s->budget--) { s->failed_pc=0x0c055418u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05541a;
P_0c05541a: /* original 6953, guest PC 0x0c05541a */
if(!s->budget--) { s->failed_pc=0x0c05541au; return 0; }
r[9]=r[5];
goto P_0c05541c;
P_0c05541c: /* original 2f86, guest PC 0x0c05541c */
if(!s->budget--) { s->failed_pc=0x0c05541cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05541e;
P_0c05541e: /* original e500, guest PC 0x0c05541e */
if(!s->budget--) { s->failed_pc=0x0c05541eu; return 0; }
r[5]=0x00000000u;
goto P_0c055420;
P_0c055420: /* original 4f22, guest PC 0x0c055420 */
if(!s->budget--) { s->failed_pc=0x0c055420u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c055422;
P_0c055422: /* original 4f12, guest PC 0x0c055422 */
if(!s->budget--) { s->failed_pc=0x0c055422u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c055424;
P_0c055424: /* original 7fe8, guest PC 0x0c055424 */
if(!s->budget--) { s->failed_pc=0x0c055424u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c055426;
P_0c055426: /* original 1f41, guest PC 0x0c055426 */
if(!s->budget--) { s->failed_pc=0x0c055426u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c055428;
P_0c055428: /* original 430b, guest PC 0x0c055428 */
if(!s->budget--) { s->failed_pc=0x0c055428u; return 0; }
target=r[3];
r[16]=code_base|0x0c05542cu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05542cu) { target=s->pc; goto dispatch; }
goto P_0c05542c;
P_0c05542a: /* original 64a3, guest PC 0x0c05542a */
if(!s->budget--) { s->failed_pc=0x0c05542au; return 0; }
r[4]=r[10];
goto P_0c05542c;
P_0c05542c: /* original d828, guest PC 0x0c05542c */
if(!s->budget--) { s->failed_pc=0x0c05542cu; return 0; }
r[8]=read(ram,0x0c0554d0u,4);
goto P_0c05542e;
P_0c05542e: /* original 6df3, guest PC 0x0c05542e */
if(!s->budget--) { s->failed_pc=0x0c05542eu; return 0; }
r[13]=r[15];
goto P_0c055430;
P_0c055430: /* original 7d08, guest PC 0x0c055430 */
if(!s->budget--) { s->failed_pc=0x0c055430u; return 0; }
r[13]+=0x00000008u;
goto P_0c055432;
P_0c055432: /* original eb07, guest PC 0x0c055432 */
if(!s->budget--) { s->failed_pc=0x0c055432u; return 0; }
r[11]=0x00000007u;
goto P_0c055434;
P_0c055434: /* original 6ebf, guest PC 0x0c055434 */
if(!s->budget--) { s->failed_pc=0x0c055434u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c055436;
P_0c055436: /* original 60e3, guest PC 0x0c055436 */
if(!s->budget--) { s->failed_pc=0x0c055436u; return 0; }
r[0]=r[14];
goto P_0c055438;
P_0c055438: /* original 0009, guest PC 0x0c055438 */
if(!s->budget--) { s->failed_pc=0x0c055438u; return 0; }
goto P_0c05543a;
P_0c05543a: /* original 039c, guest PC 0x0c05543a */
if(!s->budget--) { s->failed_pc=0x0c05543au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[9]+r[0],1);
goto P_0c05543c;
P_0c05543c: /* original 633c, guest PC 0x0c05543c */
if(!s->budget--) { s->failed_pc=0x0c05543cu; return 0; }
r[3]=r[3]&255u;
goto P_0c05543e;
P_0c05543e: /* original 2338, guest PC 0x0c05543e */
if(!s->budget--) { s->failed_pc=0x0c05543eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c055440;
P_0c055440: /* original 8d34, guest PC 0x0c055440 */
if(!s->budget--) { s->failed_pc=0x0c055440u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0554ac; }
goto P_0c055444;
P_0c055442: /* original 0009, guest PC 0x0c055442 */
if(!s->budget--) { s->failed_pc=0x0c055442u; return 0; }
goto P_0c055444;
P_0c055444: /* original d221, guest PC 0x0c055444 */
if(!s->budget--) { s->failed_pc=0x0c055444u; return 0; }
r[2]=read(ram,0x0c0554ccu,4);
goto P_0c055446;
P_0c055446: /* original e610, guest PC 0x0c055446 */
if(!s->budget--) { s->failed_pc=0x0c055446u; return 0; }
r[6]=0x00000010u;
goto P_0c055448;
P_0c055448: /* original e500, guest PC 0x0c055448 */
if(!s->budget--) { s->failed_pc=0x0c055448u; return 0; }
r[5]=0x00000000u;
goto P_0c05544a;
P_0c05544a: /* original 420b, guest PC 0x0c05544a */
if(!s->budget--) { s->failed_pc=0x0c05544au; return 0; }
target=r[2];
r[16]=code_base|0x0c05544eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05544eu) { target=s->pc; goto dispatch; }
goto P_0c05544e;
P_0c05544c: /* original 64d3, guest PC 0x0c05544c */
if(!s->budget--) { s->failed_pc=0x0c05544cu; return 0; }
r[4]=r[13];
goto P_0c05544e;
P_0c05544e: /* original ec07, guest PC 0x0c05544e */
if(!s->budget--) { s->failed_pc=0x0c05544eu; return 0; }
r[12]=0x00000007u;
goto P_0c055450;
P_0c055450: /* original 50f1, guest PC 0x0c055450 */
if(!s->budget--) { s->failed_pc=0x0c055450u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c055452;
P_0c055452: /* original 65cf, guest PC 0x0c055452 */
if(!s->budget--) { s->failed_pc=0x0c055452u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c055454;
P_0c055454: /* original 065c, guest PC 0x0c055454 */
if(!s->budget--) { s->failed_pc=0x0c055454u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c055456;
P_0c055456: /* original 666c, guest PC 0x0c055456 */
if(!s->budget--) { s->failed_pc=0x0c055456u; return 0; }
r[6]=r[6]&255u;
goto P_0c055458;
P_0c055458: /* original 6093, guest PC 0x0c055458 */
if(!s->budget--) { s->failed_pc=0x0c055458u; return 0; }
r[0]=r[9];
goto P_0c05545a;
P_0c05545a: /* original 0009, guest PC 0x0c05545a */
if(!s->budget--) { s->failed_pc=0x0c05545au; return 0; }
goto P_0c05545c;
P_0c05545c: /* original 03ec, guest PC 0x0c05545c */
if(!s->budget--) { s->failed_pc=0x0c05545cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c05545e;
P_0c05545e: /* original 64e3, guest PC 0x0c05545e */
if(!s->budget--) { s->failed_pc=0x0c05545eu; return 0; }
r[4]=r[14];
goto P_0c055460;
P_0c055460: /* original 633c, guest PC 0x0c055460 */
if(!s->budget--) { s->failed_pc=0x0c055460u; return 0; }
r[3]=r[3]&255u;
goto P_0c055462;
P_0c055462: /* original 345c, guest PC 0x0c055462 */
if(!s->budget--) { s->failed_pc=0x0c055462u; return 0; }
r[4]+=r[5];
goto P_0c055464;
P_0c055464: /* original 263e, guest PC 0x0c055464 */
if(!s->budget--) { s->failed_pc=0x0c055464u; return 0; }
r[19]=(r[6]&65535u)*(r[3]&65535u);
goto P_0c055466;
P_0c055466: /* original 34dc, guest PC 0x0c055466 */
if(!s->budget--) { s->failed_pc=0x0c055466u; return 0; }
r[4]+=r[13];
goto P_0c055468;
P_0c055468: /* original 8441, guest PC 0x0c055468 */
if(!s->budget--) { s->failed_pc=0x0c055468u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c05546a;
P_0c05546a: /* original 061a, guest PC 0x0c05546a */
if(!s->budget--) { s->failed_pc=0x0c05546au; return 0; }
r[6]=r[19];
goto P_0c05546c;
P_0c05546c: /* original 600c, guest PC 0x0c05546c */
if(!s->budget--) { s->failed_pc=0x0c05546cu; return 0; }
r[0]=r[0]&255u;
goto P_0c05546e;
P_0c05546e: /* original 2f01, guest PC 0x0c05546e */
if(!s->budget--) { s->failed_pc=0x0c05546eu; return 0; }
write(ram,r[15],r[0],2);
goto P_0c055470;
P_0c055470: /* original 63f1, guest PC 0x0c055470 */
if(!s->budget--) { s->failed_pc=0x0c055470u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c055472;
P_0c055472: /* original 336c, guest PC 0x0c055472 */
if(!s->budget--) { s->failed_pc=0x0c055472u; return 0; }
r[3]+=r[6];
goto P_0c055474;
P_0c055474: /* original 2f31, guest PC 0x0c055474 */
if(!s->budget--) { s->failed_pc=0x0c055474u; return 0; }
write(ram,r[15],r[3],2);
goto P_0c055476;
P_0c055476: /* original 480b, guest PC 0x0c055476 */
if(!s->budget--) { s->failed_pc=0x0c055476u; return 0; }
target=r[8];
r[16]=code_base|0x0c05547au;
r[5]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05547au) { target=s->pc; goto dispatch; }
goto P_0c05547a;
P_0c055478: /* original 65f3, guest PC 0x0c055478 */
if(!s->budget--) { s->failed_pc=0x0c055478u; return 0; }
r[5]=r[15];
goto P_0c05547a;
P_0c05547a: /* original 7cff, guest PC 0x0c05547a */
if(!s->budget--) { s->failed_pc=0x0c05547au; return 0; }
r[12]+=0xffffffffu;
goto P_0c05547c;
P_0c05547c: /* original 63cf, guest PC 0x0c05547c */
if(!s->budget--) { s->failed_pc=0x0c05547cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c05547e;
P_0c05547e: /* original 4311, guest PC 0x0c05547e */
if(!s->budget--) { s->failed_pc=0x0c05547eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c055480;
P_0c055480: /* original 8de6, guest PC 0x0c055480 */
if(!s->budget--) { s->failed_pc=0x0c055480u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055450; }
goto P_0c055484;
P_0c055482: /* original 0009, guest PC 0x0c055482 */
if(!s->budget--) { s->failed_pc=0x0c055482u; return 0; }
goto P_0c055484;
P_0c055484: /* original 60bf, guest PC 0x0c055484 */
if(!s->budget--) { s->failed_pc=0x0c055484u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c055486;
P_0c055486: /* original 8807, guest PC 0x0c055486 */
if(!s->budget--) { s->failed_pc=0x0c055486u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c055488;
P_0c055488: /* original 8f09, guest PC 0x0c055488 */
if(!s->budget--) { s->failed_pc=0x0c055488u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05549e; }
goto P_0c05548c;
P_0c05548a: /* original 0009, guest PC 0x0c05548a */
if(!s->budget--) { s->failed_pc=0x0c05548au; return 0; }
goto P_0c05548c;
P_0c05548c: /* original d211, guest PC 0x0c05548c */
if(!s->budget--) { s->failed_pc=0x0c05548cu; return 0; }
r[2]=read(ram,0x0c0554d4u,4);
goto P_0c05548e;
P_0c05548e: /* original e609, guest PC 0x0c05548e */
if(!s->budget--) { s->failed_pc=0x0c05548eu; return 0; }
r[6]=0x00000009u;
goto P_0c055490;
P_0c055490: /* original 65e3, guest PC 0x0c055490 */
if(!s->budget--) { s->failed_pc=0x0c055490u; return 0; }
r[5]=r[14];
goto P_0c055492;
P_0c055492: /* original 35dc, guest PC 0x0c055492 */
if(!s->budget--) { s->failed_pc=0x0c055492u; return 0; }
r[5]+=r[13];
goto P_0c055494;
P_0c055494: /* original 64e3, guest PC 0x0c055494 */
if(!s->budget--) { s->failed_pc=0x0c055494u; return 0; }
r[4]=r[14];
goto P_0c055496;
P_0c055496: /* original 420b, guest PC 0x0c055496 */
if(!s->budget--) { s->failed_pc=0x0c055496u; return 0; }
target=r[2];
r[16]=code_base|0x0c05549au;
r[4]+=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05549au) { target=s->pc; goto dispatch; }
goto P_0c05549a;
P_0c055498: /* original 34ac, guest PC 0x0c055498 */
if(!s->budget--) { s->failed_pc=0x0c055498u; return 0; }
r[4]+=r[10];
goto P_0c05549a;
P_0c05549a: /* original a007, guest PC 0x0c05549a */
if(!s->budget--) { s->failed_pc=0x0c05549au; return 0; }
goto P_0c0554ac;
P_0c05549c: /* original 0009, guest PC 0x0c05549c */
if(!s->budget--) { s->failed_pc=0x0c05549cu; return 0; }
goto P_0c05549e;
P_0c05549e: /* original e609, guest PC 0x0c05549e */
if(!s->budget--) { s->failed_pc=0x0c05549eu; return 0; }
r[6]=0x00000009u;
goto P_0c0554a0;
P_0c0554a0: /* original d20d, guest PC 0x0c0554a0 */
if(!s->budget--) { s->failed_pc=0x0c0554a0u; return 0; }
r[2]=read(ram,0x0c0554d8u,4);
goto P_0c0554a2;
P_0c0554a2: /* original 65e3, guest PC 0x0c0554a2 */
if(!s->budget--) { s->failed_pc=0x0c0554a2u; return 0; }
r[5]=r[14];
goto P_0c0554a4;
P_0c0554a4: /* original 35dc, guest PC 0x0c0554a4 */
if(!s->budget--) { s->failed_pc=0x0c0554a4u; return 0; }
r[5]+=r[13];
goto P_0c0554a6;
P_0c0554a6: /* original 64e3, guest PC 0x0c0554a6 */
if(!s->budget--) { s->failed_pc=0x0c0554a6u; return 0; }
r[4]=r[14];
goto P_0c0554a8;
P_0c0554a8: /* original 420b, guest PC 0x0c0554a8 */
if(!s->budget--) { s->failed_pc=0x0c0554a8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0554acu;
r[4]+=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0554acu) { target=s->pc; goto dispatch; }
goto P_0c0554ac;
P_0c0554aa: /* original 34ac, guest PC 0x0c0554aa */
if(!s->budget--) { s->failed_pc=0x0c0554aau; return 0; }
r[4]+=r[10];
goto P_0c0554ac;
P_0c0554ac: /* original 7bff, guest PC 0x0c0554ac */
if(!s->budget--) { s->failed_pc=0x0c0554acu; return 0; }
r[11]+=0xffffffffu;
goto P_0c0554ae;
P_0c0554ae: /* original 63bf, guest PC 0x0c0554ae */
if(!s->budget--) { s->failed_pc=0x0c0554aeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c0554b0;
P_0c0554b0: /* original 4311, guest PC 0x0c0554b0 */
if(!s->budget--) { s->failed_pc=0x0c0554b0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0554b2;
P_0c0554b2: /* original 8dbf, guest PC 0x0c0554b2 */
if(!s->budget--) { s->failed_pc=0x0c0554b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055434; }
goto P_0c0554b6;
P_0c0554b4: /* original 0009, guest PC 0x0c0554b4 */
if(!s->budget--) { s->failed_pc=0x0c0554b4u; return 0; }
goto P_0c0554b6;
P_0c0554b6: /* original 7f18, guest PC 0x0c0554b6 */
if(!s->budget--) { s->failed_pc=0x0c0554b6u; return 0; }
r[15]+=0x00000018u;
goto P_0c0554b8;
P_0c0554b8: /* original 4f16, guest PC 0x0c0554b8 */
if(!s->budget--) { s->failed_pc=0x0c0554b8u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0554ba;
P_0c0554ba: /* original 4f26, guest PC 0x0c0554ba */
if(!s->budget--) { s->failed_pc=0x0c0554bau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0554bc;
P_0c0554bc: /* original 68f6, guest PC 0x0c0554bc */
if(!s->budget--) { s->failed_pc=0x0c0554bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0554be;
P_0c0554be: /* original 69f6, guest PC 0x0c0554be */
if(!s->budget--) { s->failed_pc=0x0c0554beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0554c0;
P_0c0554c0: /* original 6af6, guest PC 0x0c0554c0 */
if(!s->budget--) { s->failed_pc=0x0c0554c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0554c2;
P_0c0554c2: /* original 6bf6, guest PC 0x0c0554c2 */
if(!s->budget--) { s->failed_pc=0x0c0554c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0554c4;
P_0c0554c4: /* original 6cf6, guest PC 0x0c0554c4 */
if(!s->budget--) { s->failed_pc=0x0c0554c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0554c6;
P_0c0554c6: /* original 6df6, guest PC 0x0c0554c6 */
if(!s->budget--) { s->failed_pc=0x0c0554c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0554c8;
P_0c0554c8: /* original 000b, guest PC 0x0c0554c8 */
if(!s->budget--) { s->failed_pc=0x0c0554c8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0554ca: /* original 6ef6, guest PC 0x0c0554ca */
if(!s->budget--) { s->failed_pc=0x0c0554cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0554ccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0554ccu; return 0; } return 1;
P_0c0554dc: /* original 2fe6, guest PC 0x0c0554dc */
if(!s->budget--) { s->failed_pc=0x0c0554dcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0554de;
P_0c0554de: /* original 6343, guest PC 0x0c0554de */
if(!s->budget--) { s->failed_pc=0x0c0554deu; return 0; }
r[3]=r[4];
goto P_0c0554e0;
P_0c0554e0: /* original d221, guest PC 0x0c0554e0 */
if(!s->budget--) { s->failed_pc=0x0c0554e0u; return 0; }
r[2]=read(ram,0x0c055568u,4);
goto P_0c0554e2;
P_0c0554e2: /* original 733f, guest PC 0x0c0554e2 */
if(!s->budget--) { s->failed_pc=0x0c0554e2u; return 0; }
r[3]+=0x0000003fu;
goto P_0c0554e4;
P_0c0554e4: /* original 2fd6, guest PC 0x0c0554e4 */
if(!s->budget--) { s->failed_pc=0x0c0554e4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0554e6;
P_0c0554e6: /* original 6d53, guest PC 0x0c0554e6 */
if(!s->budget--) { s->failed_pc=0x0c0554e6u; return 0; }
r[13]=r[5];
goto P_0c0554e8;
P_0c0554e8: /* original 2fc6, guest PC 0x0c0554e8 */
if(!s->budget--) { s->failed_pc=0x0c0554e8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0554ea;
P_0c0554ea: /* original 2fb6, guest PC 0x0c0554ea */
if(!s->budget--) { s->failed_pc=0x0c0554eau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0554ec;
P_0c0554ec: /* original 4f22, guest PC 0x0c0554ec */
if(!s->budget--) { s->failed_pc=0x0c0554ecu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0554ee;
P_0c0554ee: /* original 7ff0, guest PC 0x0c0554ee */
if(!s->budget--) { s->failed_pc=0x0c0554eeu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0554f0;
P_0c0554f0: /* original 2f62, guest PC 0x0c0554f0 */
if(!s->budget--) { s->failed_pc=0x0c0554f0u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0554f2;
P_0c0554f2: /* original 65f3, guest PC 0x0c0554f2 */
if(!s->budget--) { s->failed_pc=0x0c0554f2u; return 0; }
r[5]=r[15];
goto P_0c0554f4;
P_0c0554f4: /* original 2d31, guest PC 0x0c0554f4 */
if(!s->budget--) { s->failed_pc=0x0c0554f4u; return 0; }
write(ram,r[13],r[3],2);
goto P_0c0554f6;
P_0c0554f6: /* original 420b, guest PC 0x0c0554f6 */
if(!s->budget--) { s->failed_pc=0x0c0554f6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0554fau;
r[5]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0554fau) { target=s->pc; goto dispatch; }
goto P_0c0554fa;
P_0c0554f8: /* original 7508, guest PC 0x0c0554f8 */
if(!s->budget--) { s->failed_pc=0x0c0554f8u; return 0; }
r[5]+=0x00000008u;
goto P_0c0554fa;
P_0c0554fa: /* original e608, guest PC 0x0c0554fa */
if(!s->budget--) { s->failed_pc=0x0c0554fau; return 0; }
r[6]=0x00000008u;
goto P_0c0554fc;
P_0c0554fc: /* original d31b, guest PC 0x0c0554fc */
if(!s->budget--) { s->failed_pc=0x0c0554fcu; return 0; }
r[3]=read(ram,0x0c05556cu,4);
goto P_0c0554fe;
P_0c0554fe: /* original e500, guest PC 0x0c0554fe */
if(!s->budget--) { s->failed_pc=0x0c0554feu; return 0; }
r[5]=0x00000000u;
goto P_0c055500;
P_0c055500: /* original 430b, guest PC 0x0c055500 */
if(!s->budget--) { s->failed_pc=0x0c055500u; return 0; }
target=r[3];
r[16]=code_base|0x0c055504u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055504u) { target=s->pc; goto dispatch; }
goto P_0c055504;
P_0c055502: /* original 64f2, guest PC 0x0c055502 */
if(!s->budget--) { s->failed_pc=0x0c055502u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c055504;
P_0c055504: /* original eb00, guest PC 0x0c055504 */
if(!s->budget--) { s->failed_pc=0x0c055504u; return 0; }
r[11]=0x00000000u;
goto P_0c055506;
P_0c055506: /* original 6cb3, guest PC 0x0c055506 */
if(!s->budget--) { s->failed_pc=0x0c055506u; return 0; }
r[12]=r[11];
goto P_0c055508;
P_0c055508: /* original 6ef3, guest PC 0x0c055508 */
if(!s->budget--) { s->failed_pc=0x0c055508u; return 0; }
r[14]=r[15];
goto P_0c05550a;
P_0c05550a: /* original a005, guest PC 0x0c05550a */
if(!s->budget--) { s->failed_pc=0x0c05550au; return 0; }
r[14]+=0x00000008u;
goto P_0c055518;
P_0c05550c: /* original 7e08, guest PC 0x0c05550c */
if(!s->budget--) { s->failed_pc=0x0c05550cu; return 0; }
r[14]+=0x00000008u;
goto P_0c05550e;
P_0c05550e: /* original 7e01, guest PC 0x0c05550e */
if(!s->budget--) { s->failed_pc=0x0c05550eu; return 0; }
r[14]+=0x00000001u;
goto P_0c055510;
P_0c055510: /* original 63d1, guest PC 0x0c055510 */
if(!s->budget--) { s->failed_pc=0x0c055510u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[3]=tmp;
goto P_0c055512;
P_0c055512: /* original 7b01, guest PC 0x0c055512 */
if(!s->budget--) { s->failed_pc=0x0c055512u; return 0; }
r[11]+=0x00000001u;
goto P_0c055514;
P_0c055514: /* original 73f8, guest PC 0x0c055514 */
if(!s->budget--) { s->failed_pc=0x0c055514u; return 0; }
r[3]+=0xfffffff8u;
goto P_0c055516;
P_0c055516: /* original 2d31, guest PC 0x0c055516 */
if(!s->budget--) { s->failed_pc=0x0c055516u; return 0; }
write(ram,r[13],r[3],2);
goto P_0c055518;
P_0c055518: /* original 62e0, guest PC 0x0c055518 */
if(!s->budget--) { s->failed_pc=0x0c055518u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[2]=tmp;
goto P_0c05551a;
P_0c05551a: /* original 2228, guest PC 0x0c05551a */
if(!s->budget--) { s->failed_pc=0x0c05551au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c05551c;
P_0c05551c: /* original 8df7, guest PC 0x0c05551c */
if(!s->budget--) { s->failed_pc=0x0c05551cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05550e; }
goto P_0c055520;
P_0c05551e: /* original 0009, guest PC 0x0c05551e */
if(!s->budget--) { s->failed_pc=0x0c05551eu; return 0; }
goto P_0c055520;
P_0c055520: /* original 9420, guest PC 0x0c055520 */
if(!s->budget--) { s->failed_pc=0x0c055520u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c055564u,2);
goto P_0c055522;
P_0c055522: /* original a003, guest PC 0x0c055522 */
if(!s->budget--) { s->failed_pc=0x0c055522u; return 0; }
goto P_0c05552c;
P_0c055524: /* original 0009, guest PC 0x0c055524 */
if(!s->budget--) { s->failed_pc=0x0c055524u; return 0; }
goto P_0c055526;
P_0c055526: /* original 644c, guest PC 0x0c055526 */
if(!s->budget--) { s->failed_pc=0x0c055526u; return 0; }
r[4]=r[4]&255u;
goto P_0c055528;
P_0c055528: /* original 4401, guest PC 0x0c055528 */
if(!s->budget--) { s->failed_pc=0x0c055528u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c05552a;
P_0c05552a: /* original 7c01, guest PC 0x0c05552a */
if(!s->budget--) { s->failed_pc=0x0c05552au; return 0; }
r[12]+=0x00000001u;
goto P_0c05552c;
P_0c05552c: /* original 63e0, guest PC 0x0c05552c */
if(!s->budget--) { s->failed_pc=0x0c05552cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[3]=tmp;
goto P_0c05552e;
P_0c05552e: /* original 624c, guest PC 0x0c05552e */
if(!s->budget--) { s->failed_pc=0x0c05552eu; return 0; }
r[2]=r[4]&255u;
goto P_0c055530;
P_0c055530: /* original 633c, guest PC 0x0c055530 */
if(!s->budget--) { s->failed_pc=0x0c055530u; return 0; }
r[3]=r[3]&255u;
goto P_0c055532;
P_0c055532: /* original 2328, guest PC 0x0c055532 */
if(!s->budget--) { s->failed_pc=0x0c055532u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[2])==0)!=0);
goto P_0c055534;
P_0c055534: /* original 8df7, guest PC 0x0c055534 */
if(!s->budget--) { s->failed_pc=0x0c055534u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055526; }
goto P_0c055538;
P_0c055536: /* original 0009, guest PC 0x0c055536 */
if(!s->budget--) { s->failed_pc=0x0c055536u; return 0; }
goto P_0c055538;
P_0c055538: /* original d30d, guest PC 0x0c055538 */
if(!s->budget--) { s->failed_pc=0x0c055538u; return 0; }
r[3]=read(ram,0x0c055570u,4);
goto P_0c05553a;
P_0c05553a: /* original 66c3, guest PC 0x0c05553a */
if(!s->budget--) { s->failed_pc=0x0c05553au; return 0; }
r[6]=r[12];
goto P_0c05553c;
P_0c05553c: /* original e508, guest PC 0x0c05553c */
if(!s->budget--) { s->failed_pc=0x0c05553cu; return 0; }
r[5]=0x00000008u;
goto P_0c05553e;
P_0c05553e: /* original 35b8, guest PC 0x0c05553e */
if(!s->budget--) { s->failed_pc=0x0c05553eu; return 0; }
r[5]-=r[11];
goto P_0c055540;
P_0c055540: /* original 1f51, guest PC 0x0c055540 */
if(!s->budget--) { s->failed_pc=0x0c055540u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c055542;
P_0c055542: /* original 430b, guest PC 0x0c055542 */
if(!s->budget--) { s->failed_pc=0x0c055542u; return 0; }
target=r[3];
r[16]=code_base|0x0c055546u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055546u) { target=s->pc; goto dispatch; }
goto P_0c055546;
P_0c055544: /* original 64e3, guest PC 0x0c055544 */
if(!s->budget--) { s->failed_pc=0x0c055544u; return 0; }
r[4]=r[14];
goto P_0c055546;
P_0c055546: /* original 65e3, guest PC 0x0c055546 */
if(!s->budget--) { s->failed_pc=0x0c055546u; return 0; }
r[5]=r[14];
goto P_0c055548;
P_0c055548: /* original d30a, guest PC 0x0c055548 */
if(!s->budget--) { s->failed_pc=0x0c055548u; return 0; }
r[3]=read(ram,0x0c055574u,4);
goto P_0c05554a;
P_0c05554a: /* original 62d1, guest PC 0x0c05554a */
if(!s->budget--) { s->failed_pc=0x0c05554au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[2]=tmp;
goto P_0c05554c;
P_0c05554c: /* original 32c8, guest PC 0x0c05554c */
if(!s->budget--) { s->failed_pc=0x0c05554cu; return 0; }
r[2]-=r[12];
goto P_0c05554e;
P_0c05554e: /* original 2d21, guest PC 0x0c05554e */
if(!s->budget--) { s->failed_pc=0x0c05554eu; return 0; }
write(ram,r[13],r[2],2);
goto P_0c055550;
P_0c055550: /* original 56f1, guest PC 0x0c055550 */
if(!s->budget--) { s->failed_pc=0x0c055550u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c055552;
P_0c055552: /* original 430b, guest PC 0x0c055552 */
if(!s->budget--) { s->failed_pc=0x0c055552u; return 0; }
target=r[3];
r[16]=code_base|0x0c055556u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055556u) { target=s->pc; goto dispatch; }
goto P_0c055556;
P_0c055554: /* original 64f2, guest PC 0x0c055554 */
if(!s->budget--) { s->failed_pc=0x0c055554u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c055556;
P_0c055556: /* original 7f10, guest PC 0x0c055556 */
if(!s->budget--) { s->failed_pc=0x0c055556u; return 0; }
r[15]+=0x00000010u;
goto P_0c055558;
P_0c055558: /* original 4f26, guest PC 0x0c055558 */
if(!s->budget--) { s->failed_pc=0x0c055558u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05555a;
P_0c05555a: /* original 6bf6, guest PC 0x0c05555a */
if(!s->budget--) { s->failed_pc=0x0c05555au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05555c;
P_0c05555c: /* original 6cf6, guest PC 0x0c05555c */
if(!s->budget--) { s->failed_pc=0x0c05555cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05555e;
P_0c05555e: /* original 6df6, guest PC 0x0c05555e */
if(!s->budget--) { s->failed_pc=0x0c05555eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c055560;
P_0c055560: /* original 000b, guest PC 0x0c055560 */
if(!s->budget--) { s->failed_pc=0x0c055560u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c055562: /* original 6ef6, guest PC 0x0c055562 */
if(!s->budget--) { s->failed_pc=0x0c055562u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c055564u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c055564u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
