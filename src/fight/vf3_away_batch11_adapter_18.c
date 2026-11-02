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
int vf3_away_batch11_adapter_18(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06233eu: goto P_0c06233e;
case 0x0c062340u: goto P_0c062340;
case 0x0c062342u: goto P_0c062342;
case 0x0c062344u: goto P_0c062344;
case 0x0c062346u: goto P_0c062346;
case 0x0c062348u: goto P_0c062348;
case 0x0c06234au: goto P_0c06234a;
case 0x0c06234cu: goto P_0c06234c;
case 0x0c06234eu: goto P_0c06234e;
case 0x0c062350u: goto P_0c062350;
case 0x0c062352u: goto P_0c062352;
case 0x0c062354u: goto P_0c062354;
case 0x0c062356u: goto P_0c062356;
case 0x0c062358u: goto P_0c062358;
case 0x0c06235au: goto P_0c06235a;
case 0x0c06235cu: goto P_0c06235c;
case 0x0c06235eu: goto P_0c06235e;
case 0x0c062360u: goto P_0c062360;
case 0x0c062362u: goto P_0c062362;
case 0x0c062364u: goto P_0c062364;
case 0x0c062366u: goto P_0c062366;
case 0x0c062368u: goto P_0c062368;
case 0x0c06236au: goto P_0c06236a;
case 0x0c06236cu: goto P_0c06236c;
case 0x0c06236eu: goto P_0c06236e;
case 0x0c062370u: goto P_0c062370;
case 0x0c062372u: goto P_0c062372;
case 0x0c062374u: goto P_0c062374;
case 0x0c062376u: goto P_0c062376;
case 0x0c062378u: goto P_0c062378;
case 0x0c06237au: goto P_0c06237a;
case 0x0c062390u: goto P_0c062390;
case 0x0c062392u: goto P_0c062392;
case 0x0c062394u: goto P_0c062394;
case 0x0c062396u: goto P_0c062396;
case 0x0c062398u: goto P_0c062398;
case 0x0c06239au: goto P_0c06239a;
case 0x0c06239cu: goto P_0c06239c;
case 0x0c06239eu: goto P_0c06239e;
case 0x0c0623a0u: goto P_0c0623a0;
case 0x0c0623a2u: goto P_0c0623a2;
case 0x0c0623a4u: goto P_0c0623a4;
case 0x0c0623a6u: goto P_0c0623a6;
case 0x0c0623a8u: goto P_0c0623a8;
case 0x0c0623aau: goto P_0c0623aa;
case 0x0c0623acu: goto P_0c0623ac;
case 0x0c0623aeu: goto P_0c0623ae;
case 0x0c0623b0u: goto P_0c0623b0;
case 0x0c0623b2u: goto P_0c0623b2;
case 0x0c0623b4u: goto P_0c0623b4;
case 0x0c0623b6u: goto P_0c0623b6;
case 0x0c0623b8u: goto P_0c0623b8;
case 0x0c0623bau: goto P_0c0623ba;
case 0x0c0623bcu: goto P_0c0623bc;
case 0x0c0623beu: goto P_0c0623be;
case 0x0c0623c0u: goto P_0c0623c0;
case 0x0c0623c2u: goto P_0c0623c2;
case 0x0c0623c4u: goto P_0c0623c4;
case 0x0c0623c6u: goto P_0c0623c6;
case 0x0c0623c8u: goto P_0c0623c8;
case 0x0c0623cau: goto P_0c0623ca;
case 0x0c0623ccu: goto P_0c0623cc;
case 0x0c0623ceu: goto P_0c0623ce;
case 0x0c0623d0u: goto P_0c0623d0;
case 0x0c0623d2u: goto P_0c0623d2;
case 0x0c0623d4u: goto P_0c0623d4;
case 0x0c0623d6u: goto P_0c0623d6;
case 0x0c0623d8u: goto P_0c0623d8;
case 0x0c0623dau: goto P_0c0623da;
case 0x0c0623dcu: goto P_0c0623dc;
case 0x0c0623deu: goto P_0c0623de;
case 0x0c0623e0u: goto P_0c0623e0;
case 0x0c0623e2u: goto P_0c0623e2;
case 0x0c0623e4u: goto P_0c0623e4;
case 0x0c0623e6u: goto P_0c0623e6;
case 0x0c0623e8u: goto P_0c0623e8;
case 0x0c0623eau: goto P_0c0623ea;
case 0x0c0623ecu: goto P_0c0623ec;
case 0x0c0623eeu: goto P_0c0623ee;
case 0x0c0623f0u: goto P_0c0623f0;
case 0x0c0623f2u: goto P_0c0623f2;
case 0x0c0623f4u: goto P_0c0623f4;
case 0x0c0623f6u: goto P_0c0623f6;
case 0x0c0623f8u: goto P_0c0623f8;
case 0x0c0623fau: goto P_0c0623fa;
case 0x0c0623fcu: goto P_0c0623fc;
case 0x0c0623feu: goto P_0c0623fe;
case 0x0c062400u: goto P_0c062400;
case 0x0c062402u: goto P_0c062402;
case 0x0c062404u: goto P_0c062404;
case 0x0c062406u: goto P_0c062406;
case 0x0c062408u: goto P_0c062408;
case 0x0c06240au: goto P_0c06240a;
case 0x0c06240cu: goto P_0c06240c;
case 0x0c06240eu: goto P_0c06240e;
case 0x0c062410u: goto P_0c062410;
case 0x0c062412u: goto P_0c062412;
case 0x0c062414u: goto P_0c062414;
case 0x0c062416u: goto P_0c062416;
case 0x0c062418u: goto P_0c062418;
case 0x0c06241au: goto P_0c06241a;
case 0x0c06241cu: goto P_0c06241c;
case 0x0c06241eu: goto P_0c06241e;
case 0x0c062420u: goto P_0c062420;
case 0x0c062422u: goto P_0c062422;
case 0x0c062424u: goto P_0c062424;
case 0x0c062426u: goto P_0c062426;
case 0x0c062428u: goto P_0c062428;
case 0x0c06242au: goto P_0c06242a;
case 0x0c06242cu: goto P_0c06242c;
case 0x0c06242eu: goto P_0c06242e;
case 0x0c062430u: goto P_0c062430;
case 0x0c062432u: goto P_0c062432;
case 0x0c062434u: goto P_0c062434;
case 0x0c062436u: goto P_0c062436;
case 0x0c062438u: goto P_0c062438;
case 0x0c06243au: goto P_0c06243a;
case 0x0c06243cu: goto P_0c06243c;
case 0x0c06243eu: goto P_0c06243e;
case 0x0c062440u: goto P_0c062440;
case 0x0c062442u: goto P_0c062442;
case 0x0c062444u: goto P_0c062444;
case 0x0c062446u: goto P_0c062446;
case 0x0c062448u: goto P_0c062448;
case 0x0c06244au: goto P_0c06244a;
case 0x0c06244cu: goto P_0c06244c;
case 0x0c06244eu: goto P_0c06244e;
case 0x0c062450u: goto P_0c062450;
case 0x0c062452u: goto P_0c062452;
case 0x0c062454u: goto P_0c062454;
case 0x0c062456u: goto P_0c062456;
case 0x0c062458u: goto P_0c062458;
case 0x0c06245au: goto P_0c06245a;
case 0x0c06245cu: goto P_0c06245c;
case 0x0c06245eu: goto P_0c06245e;
case 0x0c062460u: goto P_0c062460;
case 0x0c062462u: goto P_0c062462;
case 0x0c062464u: goto P_0c062464;
case 0x0c062466u: goto P_0c062466;
case 0x0c062468u: goto P_0c062468;
case 0x0c06246au: goto P_0c06246a;
case 0x0c06246cu: goto P_0c06246c;
case 0x0c06246eu: goto P_0c06246e;
case 0x0c062470u: goto P_0c062470;
case 0x0c062472u: goto P_0c062472;
case 0x0c062474u: goto P_0c062474;
case 0x0c062476u: goto P_0c062476;
case 0x0c062478u: goto P_0c062478;
case 0x0c06247au: goto P_0c06247a;
case 0x0c06247cu: goto P_0c06247c;
case 0x0c06247eu: goto P_0c06247e;
case 0x0c062480u: goto P_0c062480;
case 0x0c062482u: goto P_0c062482;
case 0x0c062484u: goto P_0c062484;
case 0x0c062486u: goto P_0c062486;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c06233e: /* original d213, guest PC 0x0c06233e */
if(!s->budget--) { s->failed_pc=0x0c06233eu; return 0; }
r[2]=read(ram,0x0c06238cu,4);
goto P_0c062340;
P_0c062340: /* original 6322, guest PC 0x0c062340 */
if(!s->budget--) { s->failed_pc=0x0c062340u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c062342;
P_0c062342: /* original 3433, guest PC 0x0c062342 */
if(!s->budget--) { s->failed_pc=0x0c062342u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c062344;
P_0c062344: /* original 8d03, guest PC 0x0c062344 */
if(!s->budget--) { s->failed_pc=0x0c062344u; return 0; }
cond=r[17]&1u;
r[6]=0x00000000u;
if(cond) { goto P_0c06234e; }
goto P_0c062348;
P_0c062346: /* original e600, guest PC 0x0c062346 */
if(!s->budget--) { s->failed_pc=0x0c062346u; return 0; }
r[6]=0x00000000u;
goto P_0c062348;
P_0c062348: /* original e000, guest PC 0x0c062348 */
if(!s->budget--) { s->failed_pc=0x0c062348u; return 0; }
r[0]=0x00000000u;
goto P_0c06234a;
P_0c06234a: /* original a002, guest PC 0x0c06234a */
if(!s->budget--) { s->failed_pc=0x0c06234au; return 0; }
write(ram,r[5],r[0],2);
goto P_0c062352;
P_0c06234c: /* original 2501, guest PC 0x0c06234c */
if(!s->budget--) { s->failed_pc=0x0c06234cu; return 0; }
write(ram,r[5],r[0],2);
goto P_0c06234e;
P_0c06234e: /* original e101, guest PC 0x0c06234e */
if(!s->budget--) { s->failed_pc=0x0c06234eu; return 0; }
r[1]=0x00000001u;
goto P_0c062350;
P_0c062350: /* original 2511, guest PC 0x0c062350 */
if(!s->budget--) { s->failed_pc=0x0c062350u; return 0; }
write(ram,r[5],r[1],2);
goto P_0c062352;
P_0c062352: /* original 6350, guest PC 0x0c062352 */
if(!s->budget--) { s->failed_pc=0x0c062352u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[3]=tmp;
goto P_0c062354;
P_0c062354: /* original d00b, guest PC 0x0c062354 */
if(!s->budget--) { s->failed_pc=0x0c062354u; return 0; }
r[0]=read(ram,0x0c062384u,4);
goto P_0c062356;
P_0c062356: /* original 6233, guest PC 0x0c062356 */
if(!s->budget--) { s->failed_pc=0x0c062356u; return 0; }
r[2]=r[3];
goto P_0c062358;
P_0c062358: /* original 4308, guest PC 0x0c062358 */
if(!s->budget--) { s->failed_pc=0x0c062358u; return 0; }
r[3]<<=2;
goto P_0c06235a;
P_0c06235a: /* original 332c, guest PC 0x0c06235a */
if(!s->budget--) { s->failed_pc=0x0c06235au; return 0; }
r[3]+=r[2];
goto P_0c06235c;
P_0c06235c: /* original 4308, guest PC 0x0c06235c */
if(!s->budget--) { s->failed_pc=0x0c06235cu; return 0; }
r[3]<<=2;
goto P_0c06235e;
P_0c06235e: /* original 633e, guest PC 0x0c06235e */
if(!s->budget--) { s->failed_pc=0x0c06235eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c062360;
P_0c062360: /* original 053e, guest PC 0x0c062360 */
if(!s->budget--) { s->failed_pc=0x0c062360u; return 0; }
r[5]=read(ram,r[3]+r[0],4);
goto P_0c062362;
P_0c062362: /* original 2558, guest PC 0x0c062362 */
if(!s->budget--) { s->failed_pc=0x0c062362u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c062364;
P_0c062364: /* original 8908, guest PC 0x0c062364 */
if(!s->budget--) { s->failed_pc=0x0c062364u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062378; }
goto P_0c062366;
P_0c062366: /* original 5153, guest PC 0x0c062366 */
if(!s->budget--) { s->failed_pc=0x0c062366u; return 0; }
r[1]=read(ram,r[5]+12,4);
goto P_0c062368;
P_0c062368: /* original 3140, guest PC 0x0c062368 */
if(!s->budget--) { s->failed_pc=0x0c062368u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[4])!=0);
goto P_0c06236a;
P_0c06236a: /* original 8b02, guest PC 0x0c06236a */
if(!s->budget--) { s->failed_pc=0x0c06236au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062372; }
goto P_0c06236c;
P_0c06236c: /* original 6653, guest PC 0x0c06236c */
if(!s->budget--) { s->failed_pc=0x0c06236cu; return 0; }
r[6]=r[5];
goto P_0c06236e;
P_0c06236e: /* original a001, guest PC 0x0c06236e */
if(!s->budget--) { s->failed_pc=0x0c06236eu; return 0; }
r[5]=0x00000000u;
goto P_0c062374;
P_0c062370: /* original e500, guest PC 0x0c062370 */
if(!s->budget--) { s->failed_pc=0x0c062370u; return 0; }
r[5]=0x00000000u;
goto P_0c062372;
P_0c062372: /* original 5552, guest PC 0x0c062372 */
if(!s->budget--) { s->failed_pc=0x0c062372u; return 0; }
r[5]=read(ram,r[5]+8,4);
goto P_0c062374;
P_0c062374: /* original 2558, guest PC 0x0c062374 */
if(!s->budget--) { s->failed_pc=0x0c062374u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c062376;
P_0c062376: /* original 8bf6, guest PC 0x0c062376 */
if(!s->budget--) { s->failed_pc=0x0c062376u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062366; }
goto P_0c062378;
P_0c062378: /* original 000b, guest PC 0x0c062378 */
if(!s->budget--) { s->failed_pc=0x0c062378u; return 0; }
target=r[16];
r[0]=r[6];
s->pc=target; return ram->oob==0;
P_0c06237a: /* original 6063, guest PC 0x0c06237a */
if(!s->budget--) { s->failed_pc=0x0c06237au; return 0; }
r[0]=r[6];
if(!vf3_matrix_family(0x0c06237cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06237cu; return 0; } return 1;
P_0c062390: /* original 2fe6, guest PC 0x0c062390 */
if(!s->budget--) { s->failed_pc=0x0c062390u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062392;
P_0c062392: /* original 6e53, guest PC 0x0c062392 */
if(!s->budget--) { s->failed_pc=0x0c062392u; return 0; }
r[14]=r[5];
goto P_0c062394;
P_0c062394: /* original d33d, guest PC 0x0c062394 */
if(!s->budget--) { s->failed_pc=0x0c062394u; return 0; }
r[3]=read(ram,0x0c06248cu,4);
goto P_0c062396;
P_0c062396: /* original 66e3, guest PC 0x0c062396 */
if(!s->budget--) { s->failed_pc=0x0c062396u; return 0; }
r[6]=r[14];
goto P_0c062398;
P_0c062398: /* original 2fd6, guest PC 0x0c062398 */
if(!s->budget--) { s->failed_pc=0x0c062398u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06239a;
P_0c06239a: /* original 2fc6, guest PC 0x0c06239a */
if(!s->budget--) { s->failed_pc=0x0c06239au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06239c;
P_0c06239c: /* original 2fb6, guest PC 0x0c06239c */
if(!s->budget--) { s->failed_pc=0x0c06239cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06239e;
P_0c06239e: /* original 6c43, guest PC 0x0c06239e */
if(!s->budget--) { s->failed_pc=0x0c06239eu; return 0; }
r[12]=r[4];
goto P_0c0623a0;
P_0c0623a0: /* original 2fa6, guest PC 0x0c0623a0 */
if(!s->budget--) { s->failed_pc=0x0c0623a0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0623a2;
P_0c0623a2: /* original 6ac3, guest PC 0x0c0623a2 */
if(!s->budget--) { s->failed_pc=0x0c0623a2u; return 0; }
r[10]=r[12];
goto P_0c0623a4;
P_0c0623a4: /* original 4f22, guest PC 0x0c0623a4 */
if(!s->budget--) { s->failed_pc=0x0c0623a4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0623a6;
P_0c0623a6: /* original 4a08, guest PC 0x0c0623a6 */
if(!s->budget--) { s->failed_pc=0x0c0623a6u; return 0; }
r[10]<<=2;
goto P_0c0623a8;
P_0c0623a8: /* original db37, guest PC 0x0c0623a8 */
if(!s->budget--) { s->failed_pc=0x0c0623a8u; return 0; }
r[11]=read(ram,0x0c062488u,4);
goto P_0c0623aa;
P_0c0623aa: /* original 7ffc, guest PC 0x0c0623aa */
if(!s->budget--) { s->failed_pc=0x0c0623aau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0623ac;
P_0c0623ac: /* original 62e1, guest PC 0x0c0623ac */
if(!s->budget--) { s->failed_pc=0x0c0623acu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c0623ae;
P_0c0623ae: /* original 2239, guest PC 0x0c0623ae */
if(!s->budget--) { s->failed_pc=0x0c0623aeu; return 0; }
r[2]&=r[3];
goto P_0c0623b0;
P_0c0623b0: /* original 2e21, guest PC 0x0c0623b0 */
if(!s->budget--) { s->failed_pc=0x0c0623b0u; return 0; }
write(ram,r[14],r[2],2);
goto P_0c0623b2;
P_0c0623b2: /* original 62c3, guest PC 0x0c0623b2 */
if(!s->budget--) { s->failed_pc=0x0c0623b2u; return 0; }
r[2]=r[12];
goto P_0c0623b4;
P_0c0623b4: /* original 3a2c, guest PC 0x0c0623b4 */
if(!s->budget--) { s->failed_pc=0x0c0623b4u; return 0; }
r[10]+=r[2];
goto P_0c0623b6;
P_0c0623b6: /* original 4a08, guest PC 0x0c0623b6 */
if(!s->budget--) { s->failed_pc=0x0c0623b6u; return 0; }
r[10]<<=2;
goto P_0c0623b8;
P_0c0623b8: /* original 6aae, guest PC 0x0c0623b8 */
if(!s->budget--) { s->failed_pc=0x0c0623b8u; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)r[10];
goto P_0c0623ba;
P_0c0623ba: /* original 3abc, guest PC 0x0c0623ba */
if(!s->budget--) { s->failed_pc=0x0c0623bau; return 0; }
r[10]+=r[11];
goto P_0c0623bc;
P_0c0623bc: /* original 65a3, guest PC 0x0c0623bc */
if(!s->budget--) { s->failed_pc=0x0c0623bcu; return 0; }
r[5]=r[10];
goto P_0c0623be;
P_0c0623be: /* original 7504, guest PC 0x0c0623be */
if(!s->budget--) { s->failed_pc=0x0c0623beu; return 0; }
r[5]+=0x00000004u;
goto P_0c0623c0;
P_0c0623c0: /* original b0b0, guest PC 0x0c0623c0 */
if(!s->budget--) { s->failed_pc=0x0c0623c0u; return 0; }
target=code_base|0x0c062524u; r[16]=code_base|0x0c0623c4u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0623c4u) { target=s->pc; goto dispatch; }
goto P_0c0623c4;
P_0c0623c2: /* original 64a3, guest PC 0x0c0623c2 */
if(!s->budget--) { s->failed_pc=0x0c0623c2u; return 0; }
r[4]=r[10];
goto P_0c0623c4;
P_0c0623c4: /* original 53e4, guest PC 0x0c0623c4 */
if(!s->budget--) { s->failed_pc=0x0c0623c4u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c0623c6;
P_0c0623c6: /* original 52a4, guest PC 0x0c0623c6 */
if(!s->budget--) { s->failed_pc=0x0c0623c6u; return 0; }
r[2]=read(ram,r[10]+16,4);
goto P_0c0623c8;
P_0c0623c8: /* original 323c, guest PC 0x0c0623c8 */
if(!s->budget--) { s->failed_pc=0x0c0623c8u; return 0; }
r[2]+=r[3];
goto P_0c0623ca;
P_0c0623ca: /* original 1a24, guest PC 0x0c0623ca */
if(!s->budget--) { s->failed_pc=0x0c0623cau; return 0; }
write(ram,r[10]+16,r[2],4);
goto P_0c0623cc;
P_0c0623cc: /* original 54a2, guest PC 0x0c0623cc */
if(!s->budget--) { s->failed_pc=0x0c0623ccu; return 0; }
r[4]=read(ram,r[10]+8,4);
goto P_0c0623ce;
P_0c0623ce: /* original 2448, guest PC 0x0c0623ce */
if(!s->budget--) { s->failed_pc=0x0c0623ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0623d0;
P_0c0623d0: /* original 8d10, guest PC 0x0c0623d0 */
if(!s->budget--) { s->failed_pc=0x0c0623d0u; return 0; }
cond=r[17]&1u;
r[13]=0x00000000u;
if(cond) { goto P_0c0623f4; }
goto P_0c0623d4;
P_0c0623d2: /* original ed00, guest PC 0x0c0623d2 */
if(!s->budget--) { s->failed_pc=0x0c0623d2u; return 0; }
r[13]=0x00000000u;
goto P_0c0623d4;
P_0c0623d4: /* original 5543, guest PC 0x0c0623d4 */
if(!s->budget--) { s->failed_pc=0x0c0623d4u; return 0; }
r[5]=read(ram,r[4]+12,4);
goto P_0c0623d6;
P_0c0623d6: /* original 56e3, guest PC 0x0c0623d6 */
if(!s->budget--) { s->failed_pc=0x0c0623d6u; return 0; }
r[6]=read(ram,r[14]+12,4);
goto P_0c0623d8;
P_0c0623d8: /* original 52e4, guest PC 0x0c0623d8 */
if(!s->budget--) { s->failed_pc=0x0c0623d8u; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c0623da;
P_0c0623da: /* original 326c, guest PC 0x0c0623da */
if(!s->budget--) { s->failed_pc=0x0c0623dau; return 0; }
r[2]+=r[6];
goto P_0c0623dc;
P_0c0623dc: /* original 3520, guest PC 0x0c0623dc */
if(!s->budget--) { s->failed_pc=0x0c0623dcu; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[2])!=0);
goto P_0c0623de;
P_0c0623de: /* original 8903, guest PC 0x0c0623de */
if(!s->budget--) { s->failed_pc=0x0c0623deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0623e8; }
goto P_0c0623e0;
P_0c0623e0: /* original 5244, guest PC 0x0c0623e0 */
if(!s->budget--) { s->failed_pc=0x0c0623e0u; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c0623e2;
P_0c0623e2: /* original 325c, guest PC 0x0c0623e2 */
if(!s->budget--) { s->failed_pc=0x0c0623e2u; return 0; }
r[2]+=r[5];
goto P_0c0623e4;
P_0c0623e4: /* original 3620, guest PC 0x0c0623e4 */
if(!s->budget--) { s->failed_pc=0x0c0623e4u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[2])!=0);
goto P_0c0623e6;
P_0c0623e6: /* original 8b02, guest PC 0x0c0623e6 */
if(!s->budget--) { s->failed_pc=0x0c0623e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0623ee; }
goto P_0c0623e8;
P_0c0623e8: /* original 6d43, guest PC 0x0c0623e8 */
if(!s->budget--) { s->failed_pc=0x0c0623e8u; return 0; }
r[13]=r[4];
goto P_0c0623ea;
P_0c0623ea: /* original a001, guest PC 0x0c0623ea */
if(!s->budget--) { s->failed_pc=0x0c0623eau; return 0; }
r[4]=0x00000000u;
goto P_0c0623f0;
P_0c0623ec: /* original e400, guest PC 0x0c0623ec */
if(!s->budget--) { s->failed_pc=0x0c0623ecu; return 0; }
r[4]=0x00000000u;
goto P_0c0623ee;
P_0c0623ee: /* original 5442, guest PC 0x0c0623ee */
if(!s->budget--) { s->failed_pc=0x0c0623eeu; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c0623f0;
P_0c0623f0: /* original 2448, guest PC 0x0c0623f0 */
if(!s->budget--) { s->failed_pc=0x0c0623f0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0623f2;
P_0c0623f2: /* original 8bef, guest PC 0x0c0623f2 */
if(!s->budget--) { s->failed_pc=0x0c0623f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0623d4; }
goto P_0c0623f4;
P_0c0623f4: /* original 2dd8, guest PC 0x0c0623f4 */
if(!s->budget--) { s->failed_pc=0x0c0623f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0623f6;
P_0c0623f6: /* original 8931, guest PC 0x0c0623f6 */
if(!s->budget--) { s->failed_pc=0x0c0623f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06245c; }
goto P_0c0623f8;
P_0c0623f8: /* original 6ac3, guest PC 0x0c0623f8 */
if(!s->budget--) { s->failed_pc=0x0c0623f8u; return 0; }
r[10]=r[12];
goto P_0c0623fa;
P_0c0623fa: /* original 63c3, guest PC 0x0c0623fa */
if(!s->budget--) { s->failed_pc=0x0c0623fau; return 0; }
r[3]=r[12];
goto P_0c0623fc;
P_0c0623fc: /* original 4a08, guest PC 0x0c0623fc */
if(!s->budget--) { s->failed_pc=0x0c0623fcu; return 0; }
r[10]<<=2;
goto P_0c0623fe;
P_0c0623fe: /* original 3a3c, guest PC 0x0c0623fe */
if(!s->budget--) { s->failed_pc=0x0c0623feu; return 0; }
r[10]+=r[3];
goto P_0c062400;
P_0c062400: /* original 4a08, guest PC 0x0c062400 */
if(!s->budget--) { s->failed_pc=0x0c062400u; return 0; }
r[10]<<=2;
goto P_0c062402;
P_0c062402: /* original 6aae, guest PC 0x0c062402 */
if(!s->budget--) { s->failed_pc=0x0c062402u; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)r[10];
goto P_0c062404;
P_0c062404: /* original 3abc, guest PC 0x0c062404 */
if(!s->budget--) { s->failed_pc=0x0c062404u; return 0; }
r[10]+=r[11];
goto P_0c062406;
P_0c062406: /* original 53e4, guest PC 0x0c062406 */
if(!s->budget--) { s->failed_pc=0x0c062406u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c062408;
P_0c062408: /* original 52e3, guest PC 0x0c062408 */
if(!s->budget--) { s->failed_pc=0x0c062408u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c06240a;
P_0c06240a: /* original 323c, guest PC 0x0c06240a */
if(!s->budget--) { s->failed_pc=0x0c06240au; return 0; }
r[2]+=r[3];
goto P_0c06240c;
P_0c06240c: /* original 51d3, guest PC 0x0c06240c */
if(!s->budget--) { s->failed_pc=0x0c06240cu; return 0; }
r[1]=read(ram,r[13]+12,4);
goto P_0c06240e;
P_0c06240e: /* original 3120, guest PC 0x0c06240e */
if(!s->budget--) { s->failed_pc=0x0c06240eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c062410;
P_0c062410: /* original 8b01, guest PC 0x0c062410 */
if(!s->budget--) { s->failed_pc=0x0c062410u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062416; }
goto P_0c062412;
P_0c062412: /* original 52e3, guest PC 0x0c062412 */
if(!s->budget--) { s->failed_pc=0x0c062412u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c062414;
P_0c062414: /* original 1d23, guest PC 0x0c062414 */
if(!s->budget--) { s->failed_pc=0x0c062414u; return 0; }
write(ram,r[13]+12,r[2],4);
goto P_0c062416;
P_0c062416: /* original 53e4, guest PC 0x0c062416 */
if(!s->budget--) { s->failed_pc=0x0c062416u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c062418;
P_0c062418: /* original 51d4, guest PC 0x0c062418 */
if(!s->budget--) { s->failed_pc=0x0c062418u; return 0; }
r[1]=read(ram,r[13]+16,4);
goto P_0c06241a;
P_0c06241a: /* original 313c, guest PC 0x0c06241a */
if(!s->budget--) { s->failed_pc=0x0c06241au; return 0; }
r[1]+=r[3];
goto P_0c06241c;
P_0c06241c: /* original 1d14, guest PC 0x0c06241c */
if(!s->budget--) { s->failed_pc=0x0c06241cu; return 0; }
write(ram,r[13]+16,r[1],4);
goto P_0c06241e;
P_0c06241e: /* original b04c, guest PC 0x0c06241e */
if(!s->budget--) { s->failed_pc=0x0c06241eu; return 0; }
target=code_base|0x0c0624bau; r[16]=code_base|0x0c062422u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c062422u) { target=s->pc; goto dispatch; }
goto P_0c062422;
P_0c062420: /* original 64e3, guest PC 0x0c062420 */
if(!s->budget--) { s->failed_pc=0x0c062420u; return 0; }
r[4]=r[14];
goto P_0c062422;
P_0c062422: /* original 66d3, guest PC 0x0c062422 */
if(!s->budget--) { s->failed_pc=0x0c062422u; return 0; }
r[6]=r[13];
goto P_0c062424;
P_0c062424: /* original 65a3, guest PC 0x0c062424 */
if(!s->budget--) { s->failed_pc=0x0c062424u; return 0; }
r[5]=r[10];
goto P_0c062426;
P_0c062426: /* original 750c, guest PC 0x0c062426 */
if(!s->budget--) { s->failed_pc=0x0c062426u; return 0; }
r[5]+=0x0000000cu;
goto P_0c062428;
P_0c062428: /* original 64a3, guest PC 0x0c062428 */
if(!s->budget--) { s->failed_pc=0x0c062428u; return 0; }
r[4]=r[10];
goto P_0c06242a;
P_0c06242a: /* original b07b, guest PC 0x0c06242a */
if(!s->budget--) { s->failed_pc=0x0c06242au; return 0; }
target=code_base|0x0c062524u; r[16]=code_base|0x0c06242eu;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06242eu) { target=s->pc; goto dispatch; }
goto P_0c06242e;
P_0c06242c: /* original 7408, guest PC 0x0c06242c */
if(!s->budget--) { s->failed_pc=0x0c06242cu; return 0; }
r[4]+=0x00000008u;
goto P_0c06242e;
P_0c06242e: /* original 6ed3, guest PC 0x0c06242e */
if(!s->budget--) { s->failed_pc=0x0c06242eu; return 0; }
r[14]=r[13];
goto P_0c062430;
P_0c062430: /* original 54a2, guest PC 0x0c062430 */
if(!s->budget--) { s->failed_pc=0x0c062430u; return 0; }
r[4]=read(ram,r[10]+8,4);
goto P_0c062432;
P_0c062432: /* original 2448, guest PC 0x0c062432 */
if(!s->budget--) { s->failed_pc=0x0c062432u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c062434;
P_0c062434: /* original 8d10, guest PC 0x0c062434 */
if(!s->budget--) { s->failed_pc=0x0c062434u; return 0; }
cond=r[17]&1u;
r[13]=0x00000000u;
if(cond) { goto P_0c062458; }
goto P_0c062438;
P_0c062436: /* original ed00, guest PC 0x0c062436 */
if(!s->budget--) { s->failed_pc=0x0c062436u; return 0; }
r[13]=0x00000000u;
goto P_0c062438;
P_0c062438: /* original 5643, guest PC 0x0c062438 */
if(!s->budget--) { s->failed_pc=0x0c062438u; return 0; }
r[6]=read(ram,r[4]+12,4);
goto P_0c06243a;
P_0c06243a: /* original 55e3, guest PC 0x0c06243a */
if(!s->budget--) { s->failed_pc=0x0c06243au; return 0; }
r[5]=read(ram,r[14]+12,4);
goto P_0c06243c;
P_0c06243c: /* original 52e4, guest PC 0x0c06243c */
if(!s->budget--) { s->failed_pc=0x0c06243cu; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c06243e;
P_0c06243e: /* original 325c, guest PC 0x0c06243e */
if(!s->budget--) { s->failed_pc=0x0c06243eu; return 0; }
r[2]+=r[5];
goto P_0c062440;
P_0c062440: /* original 3620, guest PC 0x0c062440 */
if(!s->budget--) { s->failed_pc=0x0c062440u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[2])!=0);
goto P_0c062442;
P_0c062442: /* original 8903, guest PC 0x0c062442 */
if(!s->budget--) { s->failed_pc=0x0c062442u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06244c; }
goto P_0c062444;
P_0c062444: /* original 5244, guest PC 0x0c062444 */
if(!s->budget--) { s->failed_pc=0x0c062444u; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c062446;
P_0c062446: /* original 326c, guest PC 0x0c062446 */
if(!s->budget--) { s->failed_pc=0x0c062446u; return 0; }
r[2]+=r[6];
goto P_0c062448;
P_0c062448: /* original 3520, guest PC 0x0c062448 */
if(!s->budget--) { s->failed_pc=0x0c062448u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[2])!=0);
goto P_0c06244a;
P_0c06244a: /* original 8b02, guest PC 0x0c06244a */
if(!s->budget--) { s->failed_pc=0x0c06244au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062452; }
goto P_0c06244c;
P_0c06244c: /* original 6d43, guest PC 0x0c06244c */
if(!s->budget--) { s->failed_pc=0x0c06244cu; return 0; }
r[13]=r[4];
goto P_0c06244e;
P_0c06244e: /* original a001, guest PC 0x0c06244e */
if(!s->budget--) { s->failed_pc=0x0c06244eu; return 0; }
r[4]=0x00000000u;
goto P_0c062454;
P_0c062450: /* original e400, guest PC 0x0c062450 */
if(!s->budget--) { s->failed_pc=0x0c062450u; return 0; }
r[4]=0x00000000u;
goto P_0c062452;
P_0c062452: /* original 5442, guest PC 0x0c062452 */
if(!s->budget--) { s->failed_pc=0x0c062452u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c062454;
P_0c062454: /* original 2448, guest PC 0x0c062454 */
if(!s->budget--) { s->failed_pc=0x0c062454u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c062456;
P_0c062456: /* original 8bef, guest PC 0x0c062456 */
if(!s->budget--) { s->failed_pc=0x0c062456u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062438; }
goto P_0c062458;
P_0c062458: /* original 2dd8, guest PC 0x0c062458 */
if(!s->budget--) { s->failed_pc=0x0c062458u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c06245a;
P_0c06245a: /* original 8bd4, guest PC 0x0c06245a */
if(!s->budget--) { s->failed_pc=0x0c06245au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062406; }
goto P_0c06245c;
P_0c06245c: /* original 66e3, guest PC 0x0c06245c */
if(!s->budget--) { s->failed_pc=0x0c06245cu; return 0; }
r[6]=r[14];
goto P_0c06245e;
P_0c06245e: /* original 65c3, guest PC 0x0c06245e */
if(!s->budget--) { s->failed_pc=0x0c06245eu; return 0; }
r[5]=r[12];
goto P_0c062460;
P_0c062460: /* original 63c3, guest PC 0x0c062460 */
if(!s->budget--) { s->failed_pc=0x0c062460u; return 0; }
r[3]=r[12];
goto P_0c062462;
P_0c062462: /* original 4508, guest PC 0x0c062462 */
if(!s->budget--) { s->failed_pc=0x0c062462u; return 0; }
r[5]<<=2;
goto P_0c062464;
P_0c062464: /* original 353c, guest PC 0x0c062464 */
if(!s->budget--) { s->failed_pc=0x0c062464u; return 0; }
r[5]+=r[3];
goto P_0c062466;
P_0c062466: /* original 4508, guest PC 0x0c062466 */
if(!s->budget--) { s->failed_pc=0x0c062466u; return 0; }
r[5]<<=2;
goto P_0c062468;
P_0c062468: /* original 655e, guest PC 0x0c062468 */
if(!s->budget--) { s->failed_pc=0x0c062468u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c06246a;
P_0c06246a: /* original 35bc, guest PC 0x0c06246a */
if(!s->budget--) { s->failed_pc=0x0c06246au; return 0; }
r[5]+=r[11];
goto P_0c06246c;
P_0c06246c: /* original 2f52, guest PC 0x0c06246c */
if(!s->budget--) { s->failed_pc=0x0c06246cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c06246e;
P_0c06246e: /* original 750c, guest PC 0x0c06246e */
if(!s->budget--) { s->failed_pc=0x0c06246eu; return 0; }
r[5]+=0x0000000cu;
goto P_0c062470;
P_0c062470: /* original 64f2, guest PC 0x0c062470 */
if(!s->budget--) { s->failed_pc=0x0c062470u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c062472;
P_0c062472: /* original b037, guest PC 0x0c062472 */
if(!s->budget--) { s->failed_pc=0x0c062472u; return 0; }
target=code_base|0x0c0624e4u; r[16]=code_base|0x0c062476u;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c062476u) { target=s->pc; goto dispatch; }
goto P_0c062476;
P_0c062474: /* original 7408, guest PC 0x0c062474 */
if(!s->budget--) { s->failed_pc=0x0c062474u; return 0; }
r[4]+=0x00000008u;
goto P_0c062476;
P_0c062476: /* original e000, guest PC 0x0c062476 */
if(!s->budget--) { s->failed_pc=0x0c062476u; return 0; }
r[0]=0x00000000u;
goto P_0c062478;
P_0c062478: /* original 7f04, guest PC 0x0c062478 */
if(!s->budget--) { s->failed_pc=0x0c062478u; return 0; }
r[15]+=0x00000004u;
goto P_0c06247a;
P_0c06247a: /* original 4f26, guest PC 0x0c06247a */
if(!s->budget--) { s->failed_pc=0x0c06247au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06247c;
P_0c06247c: /* original 6af6, guest PC 0x0c06247c */
if(!s->budget--) { s->failed_pc=0x0c06247cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06247e;
P_0c06247e: /* original 6bf6, guest PC 0x0c06247e */
if(!s->budget--) { s->failed_pc=0x0c06247eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c062480;
P_0c062480: /* original 6cf6, guest PC 0x0c062480 */
if(!s->budget--) { s->failed_pc=0x0c062480u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c062482;
P_0c062482: /* original 6df6, guest PC 0x0c062482 */
if(!s->budget--) { s->failed_pc=0x0c062482u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c062484;
P_0c062484: /* original 000b, guest PC 0x0c062484 */
if(!s->budget--) { s->failed_pc=0x0c062484u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c062486: /* original 6ef6, guest PC 0x0c062486 */
if(!s->budget--) { s->failed_pc=0x0c062486u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c062488u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062488u; return 0; } return 1;
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
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
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
return vf3_matrix_family(0x0c062508u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
