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
int vf3_away_batch5_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0453e8u: goto P_0c0453e8;
case 0x0c0453eau: goto P_0c0453ea;
case 0x0c0453ecu: goto P_0c0453ec;
case 0x0c0453eeu: goto P_0c0453ee;
case 0x0c0453f0u: goto P_0c0453f0;
case 0x0c0453f2u: goto P_0c0453f2;
case 0x0c0453f4u: goto P_0c0453f4;
case 0x0c0453f6u: goto P_0c0453f6;
case 0x0c0453f8u: goto P_0c0453f8;
case 0x0c0453fau: goto P_0c0453fa;
case 0x0c0453fcu: goto P_0c0453fc;
case 0x0c0453feu: goto P_0c0453fe;
case 0x0c045400u: goto P_0c045400;
case 0x0c045402u: goto P_0c045402;
case 0x0c045404u: goto P_0c045404;
case 0x0c045406u: goto P_0c045406;
case 0x0c045408u: goto P_0c045408;
case 0x0c04540au: goto P_0c04540a;
case 0x0c04540cu: goto P_0c04540c;
case 0x0c04540eu: goto P_0c04540e;
case 0x0c045410u: goto P_0c045410;
case 0x0c045412u: goto P_0c045412;
case 0x0c045414u: goto P_0c045414;
case 0x0c045416u: goto P_0c045416;
case 0x0c045418u: goto P_0c045418;
case 0x0c04541au: goto P_0c04541a;
case 0x0c04541cu: goto P_0c04541c;
case 0x0c04541eu: goto P_0c04541e;
case 0x0c045420u: goto P_0c045420;
case 0x0c045422u: goto P_0c045422;
case 0x0c045424u: goto P_0c045424;
case 0x0c045426u: goto P_0c045426;
case 0x0c045428u: goto P_0c045428;
case 0x0c04542au: goto P_0c04542a;
case 0x0c04542cu: goto P_0c04542c;
case 0x0c04542eu: goto P_0c04542e;
case 0x0c045430u: goto P_0c045430;
case 0x0c045432u: goto P_0c045432;
case 0x0c045434u: goto P_0c045434;
case 0x0c045436u: goto P_0c045436;
case 0x0c045438u: goto P_0c045438;
case 0x0c04543au: goto P_0c04543a;
case 0x0c04543cu: goto P_0c04543c;
case 0x0c04543eu: goto P_0c04543e;
case 0x0c045440u: goto P_0c045440;
case 0x0c045442u: goto P_0c045442;
case 0x0c045444u: goto P_0c045444;
case 0x0c045446u: goto P_0c045446;
case 0x0c045468u: goto P_0c045468;
case 0x0c04546au: goto P_0c04546a;
case 0x0c04546cu: goto P_0c04546c;
case 0x0c04546eu: goto P_0c04546e;
case 0x0c045470u: goto P_0c045470;
case 0x0c045472u: goto P_0c045472;
case 0x0c045474u: goto P_0c045474;
case 0x0c045476u: goto P_0c045476;
case 0x0c045478u: goto P_0c045478;
case 0x0c04547au: goto P_0c04547a;
case 0x0c04547cu: goto P_0c04547c;
case 0x0c04547eu: goto P_0c04547e;
case 0x0c045480u: goto P_0c045480;
case 0x0c045482u: goto P_0c045482;
case 0x0c045484u: goto P_0c045484;
case 0x0c045486u: goto P_0c045486;
case 0x0c045488u: goto P_0c045488;
case 0x0c04548au: goto P_0c04548a;
case 0x0c04548cu: goto P_0c04548c;
case 0x0c04548eu: goto P_0c04548e;
case 0x0c045490u: goto P_0c045490;
case 0x0c045492u: goto P_0c045492;
case 0x0c045494u: goto P_0c045494;
case 0x0c045496u: goto P_0c045496;
case 0x0c045498u: goto P_0c045498;
case 0x0c04549au: goto P_0c04549a;
case 0x0c04549cu: goto P_0c04549c;
case 0x0c04549eu: goto P_0c04549e;
case 0x0c0454a0u: goto P_0c0454a0;
case 0x0c0454a2u: goto P_0c0454a2;
case 0x0c0454a4u: goto P_0c0454a4;
case 0x0c0454a6u: goto P_0c0454a6;
case 0x0c0454a8u: goto P_0c0454a8;
case 0x0c0454aau: goto P_0c0454aa;
case 0x0c0454acu: goto P_0c0454ac;
case 0x0c0454aeu: goto P_0c0454ae;
case 0x0c0454b0u: goto P_0c0454b0;
case 0x0c0454b2u: goto P_0c0454b2;
case 0x0c0454b4u: goto P_0c0454b4;
case 0x0c0454b6u: goto P_0c0454b6;
case 0x0c0454b8u: goto P_0c0454b8;
case 0x0c0454bau: goto P_0c0454ba;
case 0x0c0454bcu: goto P_0c0454bc;
case 0x0c0454beu: goto P_0c0454be;
case 0x0c0454c0u: goto P_0c0454c0;
case 0x0c0454c2u: goto P_0c0454c2;
case 0x0c0454c4u: goto P_0c0454c4;
case 0x0c0454c6u: goto P_0c0454c6;
case 0x0c0454c8u: goto P_0c0454c8;
case 0x0c0454cau: goto P_0c0454ca;
case 0x0c0454ccu: goto P_0c0454cc;
case 0x0c0454ceu: goto P_0c0454ce;
case 0x0c0454d0u: goto P_0c0454d0;
case 0x0c0454d2u: goto P_0c0454d2;
case 0x0c0454d4u: goto P_0c0454d4;
case 0x0c0454d6u: goto P_0c0454d6;
case 0x0c0454d8u: goto P_0c0454d8;
case 0x0c0454dau: goto P_0c0454da;
case 0x0c0454dcu: goto P_0c0454dc;
case 0x0c0454deu: goto P_0c0454de;
case 0x0c0454e0u: goto P_0c0454e0;
case 0x0c0454e2u: goto P_0c0454e2;
case 0x0c0454e4u: goto P_0c0454e4;
case 0x0c0454e6u: goto P_0c0454e6;
case 0x0c0454e8u: goto P_0c0454e8;
case 0x0c0454eau: goto P_0c0454ea;
case 0x0c0454ecu: goto P_0c0454ec;
case 0x0c0454eeu: goto P_0c0454ee;
case 0x0c0454f0u: goto P_0c0454f0;
case 0x0c0454f2u: goto P_0c0454f2;
case 0x0c0454f4u: goto P_0c0454f4;
case 0x0c0454f6u: goto P_0c0454f6;
case 0x0c0454f8u: goto P_0c0454f8;
case 0x0c0454fau: goto P_0c0454fa;
case 0x0c0454fcu: goto P_0c0454fc;
case 0x0c0454feu: goto P_0c0454fe;
case 0x0c045500u: goto P_0c045500;
case 0x0c045502u: goto P_0c045502;
case 0x0c045504u: goto P_0c045504;
case 0x0c045506u: goto P_0c045506;
case 0x0c045508u: goto P_0c045508;
case 0x0c04550au: goto P_0c04550a;
case 0x0c04550cu: goto P_0c04550c;
case 0x0c04550eu: goto P_0c04550e;
case 0x0c045510u: goto P_0c045510;
case 0x0c045512u: goto P_0c045512;
case 0x0c045514u: goto P_0c045514;
case 0x0c045516u: goto P_0c045516;
case 0x0c045518u: goto P_0c045518;
case 0x0c04551au: goto P_0c04551a;
case 0x0c04551cu: goto P_0c04551c;
case 0x0c04551eu: goto P_0c04551e;
case 0x0c045520u: goto P_0c045520;
case 0x0c045522u: goto P_0c045522;
case 0x0c045524u: goto P_0c045524;
case 0x0c045526u: goto P_0c045526;
case 0x0c045528u: goto P_0c045528;
case 0x0c04552au: goto P_0c04552a;
case 0x0c04552cu: goto P_0c04552c;
case 0x0c04552eu: goto P_0c04552e;
case 0x0c045530u: goto P_0c045530;
case 0x0c045532u: goto P_0c045532;
case 0x0c045534u: goto P_0c045534;
case 0x0c045536u: goto P_0c045536;
case 0x0c045538u: goto P_0c045538;
case 0x0c04553au: goto P_0c04553a;
case 0x0c04553cu: goto P_0c04553c;
case 0x0c04553eu: goto P_0c04553e;
case 0x0c045540u: goto P_0c045540;
case 0x0c045542u: goto P_0c045542;
case 0x0c045544u: goto P_0c045544;
case 0x0c045546u: goto P_0c045546;
case 0x0c045548u: goto P_0c045548;
case 0x0c04554au: goto P_0c04554a;
case 0x0c04554cu: goto P_0c04554c;
case 0x0c04554eu: goto P_0c04554e;
case 0x0c045550u: goto P_0c045550;
case 0x0c045552u: goto P_0c045552;
case 0x0c045554u: goto P_0c045554;
case 0x0c045556u: goto P_0c045556;
case 0x0c045558u: goto P_0c045558;
case 0x0c04555au: goto P_0c04555a;
case 0x0c04555cu: goto P_0c04555c;
case 0x0c04555eu: goto P_0c04555e;
case 0x0c045560u: goto P_0c045560;
case 0x0c045562u: goto P_0c045562;
case 0x0c045564u: goto P_0c045564;
case 0x0c045566u: goto P_0c045566;
case 0x0c045568u: goto P_0c045568;
case 0x0c04556au: goto P_0c04556a;
case 0x0c04556cu: goto P_0c04556c;
case 0x0c04556eu: goto P_0c04556e;
case 0x0c045570u: goto P_0c045570;
case 0x0c04558cu: goto P_0c04558c;
case 0x0c04558eu: goto P_0c04558e;
case 0x0c045590u: goto P_0c045590;
case 0x0c045592u: goto P_0c045592;
case 0x0c045594u: goto P_0c045594;
case 0x0c045596u: goto P_0c045596;
case 0x0c045598u: goto P_0c045598;
case 0x0c04559au: goto P_0c04559a;
case 0x0c04559cu: goto P_0c04559c;
case 0x0c04559eu: goto P_0c04559e;
case 0x0c0455a0u: goto P_0c0455a0;
case 0x0c0455a2u: goto P_0c0455a2;
case 0x0c0455a4u: goto P_0c0455a4;
case 0x0c0455a6u: goto P_0c0455a6;
case 0x0c0455a8u: goto P_0c0455a8;
case 0x0c0455aau: goto P_0c0455aa;
case 0x0c0455acu: goto P_0c0455ac;
case 0x0c0455aeu: goto P_0c0455ae;
case 0x0c0455b0u: goto P_0c0455b0;
case 0x0c0455b2u: goto P_0c0455b2;
case 0x0c0455b4u: goto P_0c0455b4;
case 0x0c0455b6u: goto P_0c0455b6;
case 0x0c0455b8u: goto P_0c0455b8;
case 0x0c0455bau: goto P_0c0455ba;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0453e8: /* original 2fe6, guest PC 0x0c0453e8 */
if(!s->budget--) { s->failed_pc=0x0c0453e8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0453ea;
P_0c0453ea: /* original 6e63, guest PC 0x0c0453ea */
if(!s->budget--) { s->failed_pc=0x0c0453eau; return 0; }
r[14]=r[6];
goto P_0c0453ec;
P_0c0453ec: /* original 2fd6, guest PC 0x0c0453ec */
if(!s->budget--) { s->failed_pc=0x0c0453ecu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0453ee;
P_0c0453ee: /* original 6d73, guest PC 0x0c0453ee */
if(!s->budget--) { s->failed_pc=0x0c0453eeu; return 0; }
r[13]=r[7];
goto P_0c0453f0;
P_0c0453f0: /* original 2fc6, guest PC 0x0c0453f0 */
if(!s->budget--) { s->failed_pc=0x0c0453f0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0453f2;
P_0c0453f2: /* original 6c43, guest PC 0x0c0453f2 */
if(!s->budget--) { s->failed_pc=0x0c0453f2u; return 0; }
r[12]=r[4];
goto P_0c0453f4;
P_0c0453f4: /* original 2fb6, guest PC 0x0c0453f4 */
if(!s->budget--) { s->failed_pc=0x0c0453f4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0453f6;
P_0c0453f6: /* original 2fa6, guest PC 0x0c0453f6 */
if(!s->budget--) { s->failed_pc=0x0c0453f6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0453f8;
P_0c0453f8: /* original 2f96, guest PC 0x0c0453f8 */
if(!s->budget--) { s->failed_pc=0x0c0453f8u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0453fa;
P_0c0453fa: /* original 6953, guest PC 0x0c0453fa */
if(!s->budget--) { s->failed_pc=0x0c0453fau; return 0; }
r[9]=r[5];
goto P_0c0453fc;
P_0c0453fc: /* original 2f86, guest PC 0x0c0453fc */
if(!s->budget--) { s->failed_pc=0x0c0453fcu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0453fe;
P_0c0453fe: /* original 4f22, guest PC 0x0c0453fe */
if(!s->budget--) { s->failed_pc=0x0c0453feu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045400;
P_0c045400: /* original d815, guest PC 0x0c045400 */
if(!s->budget--) { s->failed_pc=0x0c045400u; return 0; }
r[8]=read(ram,0x0c045458u,4);
goto P_0c045402;
P_0c045402: /* original 2f46, guest PC 0x0c045402 */
if(!s->budget--) { s->failed_pc=0x0c045402u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045404;
P_0c045404: /* original d315, guest PC 0x0c045404 */
if(!s->budget--) { s->failed_pc=0x0c045404u; return 0; }
r[3]=read(ram,0x0c04545cu,4);
goto P_0c045406;
P_0c045406: /* original 480b, guest PC 0x0c045406 */
if(!s->budget--) { s->failed_pc=0x0c045406u; return 0; }
target=r[8];
r[16]=code_base|0x0c04540au;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04540au) { target=s->pc; goto dispatch; }
goto P_0c04540a;
P_0c045408: /* original 2f36, guest PC 0x0c045408 */
if(!s->budget--) { s->failed_pc=0x0c045408u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04540a;
P_0c04540a: /* original d212, guest PC 0x0c04540a */
if(!s->budget--) { s->failed_pc=0x0c04540au; return 0; }
r[2]=read(ram,0x0c045454u,4);
goto P_0c04540c;
P_0c04540c: /* original 901f, guest PC 0x0c04540c */
if(!s->budget--) { s->failed_pc=0x0c04540cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04544eu,2);
goto P_0c04540e;
P_0c04540e: /* original 6b22, guest PC 0x0c04540e */
if(!s->budget--) { s->failed_pc=0x0c04540eu; return 0; }
tmp=read(ram,r[2],4);
r[11]=tmp;
goto P_0c045410;
P_0c045410: /* original 03be, guest PC 0x0c045410 */
if(!s->budget--) { s->failed_pc=0x0c045410u; return 0; }
r[3]=read(ram,r[11]+r[0],4);
goto P_0c045412;
P_0c045412: /* original 33c0, guest PC 0x0c045412 */
if(!s->budget--) { s->failed_pc=0x0c045412u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[12])!=0);
goto P_0c045414;
P_0c045414: /* original 8d05, guest PC 0x0c045414 */
if(!s->budget--) { s->failed_pc=0x0c045414u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000008u;
if(cond) { goto P_0c045422; }
goto P_0c045418;
P_0c045416: /* original 7f08, guest PC 0x0c045416 */
if(!s->budget--) { s->failed_pc=0x0c045416u; return 0; }
r[15]+=0x00000008u;
goto P_0c045418;
P_0c045418: /* original d311, guest PC 0x0c045418 */
if(!s->budget--) { s->failed_pc=0x0c045418u; return 0; }
r[3]=read(ram,0x0c045460u,4);
goto P_0c04541a;
P_0c04541a: /* original 480b, guest PC 0x0c04541a */
if(!s->budget--) { s->failed_pc=0x0c04541au; return 0; }
target=r[8];
r[16]=code_base|0x0c04541eu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04541eu) { target=s->pc; goto dispatch; }
goto P_0c04541e;
P_0c04541c: /* original 2f36, guest PC 0x0c04541c */
if(!s->budget--) { s->failed_pc=0x0c04541cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04541e;
P_0c04541e: /* original a066, guest PC 0x0c04541e */
if(!s->budget--) { s->failed_pc=0x0c04541eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0454ee;
P_0c045420: /* original 7f04, guest PC 0x0c045420 */
if(!s->budget--) { s->failed_pc=0x0c045420u; return 0; }
r[15]+=0x00000004u;
goto P_0c045422;
P_0c045422: /* original 9015, guest PC 0x0c045422 */
if(!s->budget--) { s->failed_pc=0x0c045422u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c045450u,2);
goto P_0c045424;
P_0c045424: /* original ea01, guest PC 0x0c045424 */
if(!s->budget--) { s->failed_pc=0x0c045424u; return 0; }
r[10]=0x00000001u;
goto P_0c045426;
P_0c045426: /* original 63a3, guest PC 0x0c045426 */
if(!s->budget--) { s->failed_pc=0x0c045426u; return 0; }
r[3]=r[10];
goto P_0c045428;
P_0c045428: /* original 43cc, guest PC 0x0c045428 */
if(!s->budget--) { s->failed_pc=0x0c045428u; return 0; }
r[3]=(r[12]&0x80000000u)?((r[12]&31u)?(uint32_t)((int32_t)r[3]>>((-r[12])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[12]&31u);
goto P_0c04542a;
P_0c04542a: /* original 02be, guest PC 0x0c04542a */
if(!s->budget--) { s->failed_pc=0x0c04542au; return 0; }
r[2]=read(ram,r[11]+r[0],4);
goto P_0c04542c;
P_0c04542c: /* original 2328, guest PC 0x0c04542c */
if(!s->budget--) { s->failed_pc=0x0c04542cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[2])==0)!=0);
goto P_0c04542e;
P_0c04542e: /* original 891b, guest PC 0x0c04542e */
if(!s->budget--) { s->failed_pc=0x0c04542eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c045468; }
goto P_0c045430;
P_0c045430: /* original 2fc6, guest PC 0x0c045430 */
if(!s->budget--) { s->failed_pc=0x0c045430u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045432;
P_0c045432: /* original 03be, guest PC 0x0c045432 */
if(!s->budget--) { s->failed_pc=0x0c045432u; return 0; }
r[3]=read(ram,r[11]+r[0],4);
goto P_0c045434;
P_0c045434: /* original 2f36, guest PC 0x0c045434 */
if(!s->budget--) { s->failed_pc=0x0c045434u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045436;
P_0c045436: /* original d20b, guest PC 0x0c045436 */
if(!s->budget--) { s->failed_pc=0x0c045436u; return 0; }
r[2]=read(ram,0x0c045464u,4);
goto P_0c045438;
P_0c045438: /* original 480b, guest PC 0x0c045438 */
if(!s->budget--) { s->failed_pc=0x0c045438u; return 0; }
target=r[8];
r[16]=code_base|0x0c04543cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04543cu) { target=s->pc; goto dispatch; }
goto P_0c04543c;
P_0c04543a: /* original 2f26, guest PC 0x0c04543a */
if(!s->budget--) { s->failed_pc=0x0c04543au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04543c;
P_0c04543c: /* original 65d3, guest PC 0x0c04543c */
if(!s->budget--) { s->failed_pc=0x0c04543cu; return 0; }
r[5]=r[13];
goto P_0c04543e;
P_0c04543e: /* original 7f0c, guest PC 0x0c04543e */
if(!s->budget--) { s->failed_pc=0x0c04543eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c045440;
P_0c045440: /* original bfa3, guest PC 0x0c045440 */
if(!s->budget--) { s->failed_pc=0x0c045440u; return 0; }
target=code_base|0x0c04538au; r[16]=code_base|0x0c045444u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045444u) { target=s->pc; goto dispatch; }
goto P_0c045444;
P_0c045442: /* original 64e3, guest PC 0x0c045442 */
if(!s->budget--) { s->failed_pc=0x0c045442u; return 0; }
r[4]=r[14];
goto P_0c045444;
P_0c045444: /* original a01a, guest PC 0x0c045444 */
if(!s->budget--) { s->failed_pc=0x0c045444u; return 0; }
goto P_0c04547c;
P_0c045446: /* original 0009, guest PC 0x0c045446 */
if(!s->budget--) { s->failed_pc=0x0c045446u; return 0; }
if(!vf3_matrix_family(0x0c045448u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c045448u; return 0; } return 1;
P_0c045468: /* original 2fc6, guest PC 0x0c045468 */
if(!s->budget--) { s->failed_pc=0x0c045468u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04546a;
P_0c04546a: /* original 03be, guest PC 0x0c04546a */
if(!s->budget--) { s->failed_pc=0x0c04546au; return 0; }
r[3]=read(ram,r[11]+r[0],4);
goto P_0c04546c;
P_0c04546c: /* original 2f36, guest PC 0x0c04546c */
if(!s->budget--) { s->failed_pc=0x0c04546cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04546e;
P_0c04546e: /* original d242, guest PC 0x0c04546e */
if(!s->budget--) { s->failed_pc=0x0c04546eu; return 0; }
r[2]=read(ram,0x0c045578u,4);
goto P_0c045470;
P_0c045470: /* original 480b, guest PC 0x0c045470 */
if(!s->budget--) { s->failed_pc=0x0c045470u; return 0; }
target=r[8];
r[16]=code_base|0x0c045474u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045474u) { target=s->pc; goto dispatch; }
goto P_0c045474;
P_0c045472: /* original 2f26, guest PC 0x0c045472 */
if(!s->budget--) { s->failed_pc=0x0c045472u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045474;
P_0c045474: /* original 65d3, guest PC 0x0c045474 */
if(!s->budget--) { s->failed_pc=0x0c045474u; return 0; }
r[5]=r[13];
goto P_0c045476;
P_0c045476: /* original 7f0c, guest PC 0x0c045476 */
if(!s->budget--) { s->failed_pc=0x0c045476u; return 0; }
r[15]+=0x0000000cu;
goto P_0c045478;
P_0c045478: /* original bf7e, guest PC 0x0c045478 */
if(!s->budget--) { s->failed_pc=0x0c045478u; return 0; }
target=code_base|0x0c045378u; r[16]=code_base|0x0c04547cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04547cu) { target=s->pc; goto dispatch; }
goto P_0c04547c;
P_0c04547a: /* original 64e3, guest PC 0x0c04547a */
if(!s->budget--) { s->failed_pc=0x0c04547au; return 0; }
r[4]=r[14];
goto P_0c04547c;
P_0c04547c: /* original 65d3, guest PC 0x0c04547c */
if(!s->budget--) { s->failed_pc=0x0c04547cu; return 0; }
r[5]=r[13];
goto P_0c04547e;
P_0c04547e: /* original bf61, guest PC 0x0c04547e */
if(!s->budget--) { s->failed_pc=0x0c04547eu; return 0; }
target=code_base|0x0c045344u; r[16]=code_base|0x0c045482u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045482u) { target=s->pc; goto dispatch; }
goto P_0c045482;
P_0c045480: /* original 64e3, guest PC 0x0c045480 */
if(!s->budget--) { s->failed_pc=0x0c045480u; return 0; }
r[4]=r[14];
goto P_0c045482;
P_0c045482: /* original 84e1, guest PC 0x0c045482 */
if(!s->budget--) { s->failed_pc=0x0c045482u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+1,1);
goto P_0c045484;
P_0c045484: /* original 64e0, guest PC 0x0c045484 */
if(!s->budget--) { s->failed_pc=0x0c045484u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[4]=tmp;
goto P_0c045486;
P_0c045486: /* original 204a, guest PC 0x0c045486 */
if(!s->budget--) { s->failed_pc=0x0c045486u; return 0; }
r[0]^=r[4];
goto P_0c045488;
P_0c045488: /* original 2049, guest PC 0x0c045488 */
if(!s->budget--) { s->failed_pc=0x0c045488u; return 0; }
r[0]&=r[4];
goto P_0c04548a;
P_0c04548a: /* original 80e2, guest PC 0x0c04548a */
if(!s->budget--) { s->failed_pc=0x0c04548au; return 0; }
write(ram,r[14]+2,r[0],1);
goto P_0c04548c;
P_0c04548c: /* original 64e0, guest PC 0x0c04548c */
if(!s->budget--) { s->failed_pc=0x0c04548cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[4]=tmp;
goto P_0c04548e;
P_0c04548e: /* original 6047, guest PC 0x0c04548e */
if(!s->budget--) { s->failed_pc=0x0c04548eu; return 0; }
r[0]=~r[4];
goto P_0c045490;
P_0c045490: /* original 6303, guest PC 0x0c045490 */
if(!s->budget--) { s->failed_pc=0x0c045490u; return 0; }
r[3]=r[0];
goto P_0c045492;
P_0c045492: /* original 84e1, guest PC 0x0c045492 */
if(!s->budget--) { s->failed_pc=0x0c045492u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+1,1);
goto P_0c045494;
P_0c045494: /* original 204a, guest PC 0x0c045494 */
if(!s->budget--) { s->failed_pc=0x0c045494u; return 0; }
r[0]^=r[4];
goto P_0c045496;
P_0c045496: /* original 2039, guest PC 0x0c045496 */
if(!s->budget--) { s->failed_pc=0x0c045496u; return 0; }
r[0]&=r[3];
goto P_0c045498;
P_0c045498: /* original 80e3, guest PC 0x0c045498 */
if(!s->budget--) { s->failed_pc=0x0c045498u; return 0; }
write(ram,r[14]+3,r[0],1);
goto P_0c04549a;
P_0c04549a: /* original d338, guest PC 0x0c04549a */
if(!s->budget--) { s->failed_pc=0x0c04549au; return 0; }
r[3]=read(ram,0x0c04557cu,4);
goto P_0c04549c;
P_0c04549c: /* original 9169, guest PC 0x0c04549c */
if(!s->budget--) { s->failed_pc=0x0c04549cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c045572u,2);
goto P_0c04549e;
P_0c04549e: /* original 6032, guest PC 0x0c04549e */
if(!s->budget--) { s->failed_pc=0x0c04549eu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0454a0;
P_0c0454a0: /* original 001e, guest PC 0x0c0454a0 */
if(!s->budget--) { s->failed_pc=0x0c0454a0u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c0454a2;
P_0c0454a2: /* original 8801, guest PC 0x0c0454a2 */
if(!s->budget--) { s->failed_pc=0x0c0454a2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0454a4;
P_0c0454a4: /* original 8b0c, guest PC 0x0c0454a4 */
if(!s->budget--) { s->failed_pc=0x0c0454a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0454c0; }
goto P_0c0454a6;
P_0c0454a6: /* original 84e8, guest PC 0x0c0454a6 */
if(!s->budget--) { s->failed_pc=0x0c0454a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c0454a8;
P_0c0454a8: /* original 9264, guest PC 0x0c0454a8 */
if(!s->budget--) { s->failed_pc=0x0c0454a8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c045574u,2);
goto P_0c0454aa;
P_0c0454aa: /* original 640c, guest PC 0x0c0454aa */
if(!s->budget--) { s->failed_pc=0x0c0454aau; return 0; }
r[4]=r[0]&255u;
goto P_0c0454ac;
P_0c0454ac: /* original 3420, guest PC 0x0c0454ac */
if(!s->budget--) { s->failed_pc=0x0c0454acu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c0454ae;
P_0c0454ae: /* original 8907, guest PC 0x0c0454ae */
if(!s->budget--) { s->failed_pc=0x0c0454aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0454c0; }
goto P_0c0454b0;
P_0c0454b0: /* original 2448, guest PC 0x0c0454b0 */
if(!s->budget--) { s->failed_pc=0x0c0454b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0454b2;
P_0c0454b2: /* original 8905, guest PC 0x0c0454b2 */
if(!s->budget--) { s->failed_pc=0x0c0454b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0454c0; }
goto P_0c0454b4;
P_0c0454b4: /* original 65d2, guest PC 0x0c0454b4 */
if(!s->budget--) { s->failed_pc=0x0c0454b4u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0454b6;
P_0c0454b6: /* original d332, guest PC 0x0c0454b6 */
if(!s->budget--) { s->failed_pc=0x0c0454b6u; return 0; }
r[3]=read(ram,0x0c045580u,4);
goto P_0c0454b8;
P_0c0454b8: /* original 655c, guest PC 0x0c0454b8 */
if(!s->budget--) { s->failed_pc=0x0c0454b8u; return 0; }
r[5]=r[5]&255u;
goto P_0c0454ba;
P_0c0454ba: /* original 7501, guest PC 0x0c0454ba */
if(!s->budget--) { s->failed_pc=0x0c0454bau; return 0; }
r[5]+=0x00000001u;
goto P_0c0454bc;
P_0c0454bc: /* original 430b, guest PC 0x0c0454bc */
if(!s->budget--) { s->failed_pc=0x0c0454bcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0454c0u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0454c0u) { target=s->pc; goto dispatch; }
goto P_0c0454c0;
P_0c0454be: /* original 64d3, guest PC 0x0c0454be */
if(!s->budget--) { s->failed_pc=0x0c0454beu; return 0; }
r[4]=r[13];
goto P_0c0454c0;
P_0c0454c0: /* original 62e0, guest PC 0x0c0454c0 */
if(!s->budget--) { s->failed_pc=0x0c0454c0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[2]=tmp;
goto P_0c0454c2;
P_0c0454c2: /* original 2228, guest PC 0x0c0454c2 */
if(!s->budget--) { s->failed_pc=0x0c0454c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0454c4;
P_0c0454c4: /* original 8901, guest PC 0x0c0454c4 */
if(!s->budget--) { s->failed_pc=0x0c0454c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0454ca; }
goto P_0c0454c6;
P_0c0454c6: /* original a001, guest PC 0x0c0454c6 */
if(!s->budget--) { s->failed_pc=0x0c0454c6u; return 0; }
r[0]=0x00000009u;
goto P_0c0454cc;
P_0c0454c8: /* original e009, guest PC 0x0c0454c8 */
if(!s->budget--) { s->failed_pc=0x0c0454c8u; return 0; }
r[0]=0x00000009u;
goto P_0c0454ca;
P_0c0454ca: /* original 60a3, guest PC 0x0c0454ca */
if(!s->budget--) { s->failed_pc=0x0c0454cau; return 0; }
r[0]=r[10];
goto P_0c0454cc;
P_0c0454cc: /* original 80e4, guest PC 0x0c0454cc */
if(!s->budget--) { s->failed_pc=0x0c0454ccu; return 0; }
write(ram,r[14]+4,r[0],1);
goto P_0c0454ce;
P_0c0454ce: /* original 84e3, guest PC 0x0c0454ce */
if(!s->budget--) { s->failed_pc=0x0c0454ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+3,1);
goto P_0c0454d0;
P_0c0454d0: /* original 2008, guest PC 0x0c0454d0 */
if(!s->budget--) { s->failed_pc=0x0c0454d0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0454d2;
P_0c0454d2: /* original 84e2, guest PC 0x0c0454d2 */
if(!s->budget--) { s->failed_pc=0x0c0454d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c0454d4;
P_0c0454d4: /* original 2008, guest PC 0x0c0454d4 */
if(!s->budget--) { s->failed_pc=0x0c0454d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0454d6;
P_0c0454d6: /* original 8905, guest PC 0x0c0454d6 */
if(!s->budget--) { s->failed_pc=0x0c0454d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0454e4; }
goto P_0c0454d8;
P_0c0454d8: /* original e010, guest PC 0x0c0454d8 */
if(!s->budget--) { s->failed_pc=0x0c0454d8u; return 0; }
r[0]=0x00000010u;
goto P_0c0454da;
P_0c0454da: /* original 65e3, guest PC 0x0c0454da */
if(!s->budget--) { s->failed_pc=0x0c0454dau; return 0; }
r[5]=r[14];
goto P_0c0454dc;
P_0c0454dc: /* original 66d3, guest PC 0x0c0454dc */
if(!s->budget--) { s->failed_pc=0x0c0454dcu; return 0; }
r[6]=r[13];
goto P_0c0454de;
P_0c0454de: /* original 09a4, guest PC 0x0c0454de */
if(!s->budget--) { s->failed_pc=0x0c0454deu; return 0; }
write(ram,r[9]+r[0],r[10],1);
goto P_0c0454e0;
P_0c0454e0: /* original b195, guest PC 0x0c0454e0 */
if(!s->budget--) { s->failed_pc=0x0c0454e0u; return 0; }
target=code_base|0x0c04580eu; r[16]=code_base|0x0c0454e4u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0454e4u) { target=s->pc; goto dispatch; }
goto P_0c0454e4;
P_0c0454e2: /* original 6493, guest PC 0x0c0454e2 */
if(!s->budget--) { s->failed_pc=0x0c0454e2u; return 0; }
r[4]=r[9];
goto P_0c0454e4;
P_0c0454e4: /* original 84e3, guest PC 0x0c0454e4 */
if(!s->budget--) { s->failed_pc=0x0c0454e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+3,1);
goto P_0c0454e6;
P_0c0454e6: /* original 2008, guest PC 0x0c0454e6 */
if(!s->budget--) { s->failed_pc=0x0c0454e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0454e8;
P_0c0454e8: /* original 8901, guest PC 0x0c0454e8 */
if(!s->budget--) { s->failed_pc=0x0c0454e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0454ee; }
goto P_0c0454ea;
P_0c0454ea: /* original b23d, guest PC 0x0c0454ea */
if(!s->budget--) { s->failed_pc=0x0c0454eau; return 0; }
target=code_base|0x0c045968u; r[16]=code_base|0x0c0454eeu;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0454eeu) { target=s->pc; goto dispatch; }
goto P_0c0454ee;
P_0c0454ec: /* original 6493, guest PC 0x0c0454ec */
if(!s->budget--) { s->failed_pc=0x0c0454ecu; return 0; }
r[4]=r[9];
goto P_0c0454ee;
P_0c0454ee: /* original 4f26, guest PC 0x0c0454ee */
if(!s->budget--) { s->failed_pc=0x0c0454eeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0454f0;
P_0c0454f0: /* original e000, guest PC 0x0c0454f0 */
if(!s->budget--) { s->failed_pc=0x0c0454f0u; return 0; }
r[0]=0x00000000u;
goto P_0c0454f2;
P_0c0454f2: /* original 68f6, guest PC 0x0c0454f2 */
if(!s->budget--) { s->failed_pc=0x0c0454f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0454f4;
P_0c0454f4: /* original 69f6, guest PC 0x0c0454f4 */
if(!s->budget--) { s->failed_pc=0x0c0454f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0454f6;
P_0c0454f6: /* original 6af6, guest PC 0x0c0454f6 */
if(!s->budget--) { s->failed_pc=0x0c0454f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0454f8;
P_0c0454f8: /* original 6bf6, guest PC 0x0c0454f8 */
if(!s->budget--) { s->failed_pc=0x0c0454f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0454fa;
P_0c0454fa: /* original 6cf6, guest PC 0x0c0454fa */
if(!s->budget--) { s->failed_pc=0x0c0454fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0454fc;
P_0c0454fc: /* original 6df6, guest PC 0x0c0454fc */
if(!s->budget--) { s->failed_pc=0x0c0454fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0454fe;
P_0c0454fe: /* original 000b, guest PC 0x0c0454fe */
if(!s->budget--) { s->failed_pc=0x0c0454feu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c045500: /* original 6ef6, guest PC 0x0c045500 */
if(!s->budget--) { s->failed_pc=0x0c045500u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c045502;
P_0c045502: /* original 2fe6, guest PC 0x0c045502 */
if(!s->budget--) { s->failed_pc=0x0c045502u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045504;
P_0c045504: /* original 6e63, guest PC 0x0c045504 */
if(!s->budget--) { s->failed_pc=0x0c045504u; return 0; }
r[14]=r[6];
goto P_0c045506;
P_0c045506: /* original 2fd6, guest PC 0x0c045506 */
if(!s->budget--) { s->failed_pc=0x0c045506u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045508;
P_0c045508: /* original 6d73, guest PC 0x0c045508 */
if(!s->budget--) { s->failed_pc=0x0c045508u; return 0; }
r[13]=r[7];
goto P_0c04550a;
P_0c04550a: /* original 2fc6, guest PC 0x0c04550a */
if(!s->budget--) { s->failed_pc=0x0c04550au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04550c;
P_0c04550c: /* original 6c53, guest PC 0x0c04550c */
if(!s->budget--) { s->failed_pc=0x0c04550cu; return 0; }
r[12]=r[5];
goto P_0c04550e;
P_0c04550e: /* original 4f22, guest PC 0x0c04550e */
if(!s->budget--) { s->failed_pc=0x0c04550eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045510;
P_0c045510: /* original 2f46, guest PC 0x0c045510 */
if(!s->budget--) { s->failed_pc=0x0c045510u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045512;
P_0c045512: /* original d31c, guest PC 0x0c045512 */
if(!s->budget--) { s->failed_pc=0x0c045512u; return 0; }
r[3]=read(ram,0x0c045584u,4);
goto P_0c045514;
P_0c045514: /* original d21c, guest PC 0x0c045514 */
if(!s->budget--) { s->failed_pc=0x0c045514u; return 0; }
r[2]=read(ram,0x0c045588u,4);
goto P_0c045516;
P_0c045516: /* original 420b, guest PC 0x0c045516 */
if(!s->budget--) { s->failed_pc=0x0c045516u; return 0; }
target=r[2];
r[16]=code_base|0x0c04551au;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04551au) { target=s->pc; goto dispatch; }
goto P_0c04551a;
P_0c045518: /* original 2f36, guest PC 0x0c045518 */
if(!s->budget--) { s->failed_pc=0x0c045518u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04551a;
P_0c04551a: /* original 65d3, guest PC 0x0c04551a */
if(!s->budget--) { s->failed_pc=0x0c04551au; return 0; }
r[5]=r[13];
goto P_0c04551c;
P_0c04551c: /* original 7f08, guest PC 0x0c04551c */
if(!s->budget--) { s->failed_pc=0x0c04551cu; return 0; }
r[15]+=0x00000008u;
goto P_0c04551e;
P_0c04551e: /* original bf34, guest PC 0x0c04551e */
if(!s->budget--) { s->failed_pc=0x0c04551eu; return 0; }
target=code_base|0x0c04538au; r[16]=code_base|0x0c045522u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045522u) { target=s->pc; goto dispatch; }
goto P_0c045522;
P_0c045520: /* original 64e3, guest PC 0x0c045520 */
if(!s->budget--) { s->failed_pc=0x0c045520u; return 0; }
r[4]=r[14];
goto P_0c045522;
P_0c045522: /* original 65d3, guest PC 0x0c045522 */
if(!s->budget--) { s->failed_pc=0x0c045522u; return 0; }
r[5]=r[13];
goto P_0c045524;
P_0c045524: /* original bf0e, guest PC 0x0c045524 */
if(!s->budget--) { s->failed_pc=0x0c045524u; return 0; }
target=code_base|0x0c045344u; r[16]=code_base|0x0c045528u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045528u) { target=s->pc; goto dispatch; }
goto P_0c045528;
P_0c045526: /* original 64e3, guest PC 0x0c045526 */
if(!s->budget--) { s->failed_pc=0x0c045526u; return 0; }
r[4]=r[14];
goto P_0c045528;
P_0c045528: /* original 84e1, guest PC 0x0c045528 */
if(!s->budget--) { s->failed_pc=0x0c045528u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+1,1);
goto P_0c04552a;
P_0c04552a: /* original 64e0, guest PC 0x0c04552a */
if(!s->budget--) { s->failed_pc=0x0c04552au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[4]=tmp;
goto P_0c04552c;
P_0c04552c: /* original 204a, guest PC 0x0c04552c */
if(!s->budget--) { s->failed_pc=0x0c04552cu; return 0; }
r[0]^=r[4];
goto P_0c04552e;
P_0c04552e: /* original 2049, guest PC 0x0c04552e */
if(!s->budget--) { s->failed_pc=0x0c04552eu; return 0; }
r[0]&=r[4];
goto P_0c045530;
P_0c045530: /* original 80e2, guest PC 0x0c045530 */
if(!s->budget--) { s->failed_pc=0x0c045530u; return 0; }
write(ram,r[14]+2,r[0],1);
goto P_0c045532;
P_0c045532: /* original 64e0, guest PC 0x0c045532 */
if(!s->budget--) { s->failed_pc=0x0c045532u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[4]=tmp;
goto P_0c045534;
P_0c045534: /* original 6047, guest PC 0x0c045534 */
if(!s->budget--) { s->failed_pc=0x0c045534u; return 0; }
r[0]=~r[4];
goto P_0c045536;
P_0c045536: /* original 6303, guest PC 0x0c045536 */
if(!s->budget--) { s->failed_pc=0x0c045536u; return 0; }
r[3]=r[0];
goto P_0c045538;
P_0c045538: /* original 84e1, guest PC 0x0c045538 */
if(!s->budget--) { s->failed_pc=0x0c045538u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+1,1);
goto P_0c04553a;
P_0c04553a: /* original 204a, guest PC 0x0c04553a */
if(!s->budget--) { s->failed_pc=0x0c04553au; return 0; }
r[0]^=r[4];
goto P_0c04553c;
P_0c04553c: /* original 2039, guest PC 0x0c04553c */
if(!s->budget--) { s->failed_pc=0x0c04553cu; return 0; }
r[0]&=r[3];
goto P_0c04553e;
P_0c04553e: /* original 80e3, guest PC 0x0c04553e */
if(!s->budget--) { s->failed_pc=0x0c04553eu; return 0; }
write(ram,r[14]+3,r[0],1);
goto P_0c045540;
P_0c045540: /* original d30e, guest PC 0x0c045540 */
if(!s->budget--) { s->failed_pc=0x0c045540u; return 0; }
r[3]=read(ram,0x0c04557cu,4);
goto P_0c045542;
P_0c045542: /* original 9116, guest PC 0x0c045542 */
if(!s->budget--) { s->failed_pc=0x0c045542u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c045572u,2);
goto P_0c045544;
P_0c045544: /* original 6032, guest PC 0x0c045544 */
if(!s->budget--) { s->failed_pc=0x0c045544u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c045546;
P_0c045546: /* original 001e, guest PC 0x0c045546 */
if(!s->budget--) { s->failed_pc=0x0c045546u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c045548;
P_0c045548: /* original 8801, guest PC 0x0c045548 */
if(!s->budget--) { s->failed_pc=0x0c045548u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c04554a;
P_0c04554a: /* original 8b0c, guest PC 0x0c04554a */
if(!s->budget--) { s->failed_pc=0x0c04554au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c045566; }
goto P_0c04554c;
P_0c04554c: /* original 84e8, guest PC 0x0c04554c */
if(!s->budget--) { s->failed_pc=0x0c04554cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c04554e;
P_0c04554e: /* original 9211, guest PC 0x0c04554e */
if(!s->budget--) { s->failed_pc=0x0c04554eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c045574u,2);
goto P_0c045550;
P_0c045550: /* original 640c, guest PC 0x0c045550 */
if(!s->budget--) { s->failed_pc=0x0c045550u; return 0; }
r[4]=r[0]&255u;
goto P_0c045552;
P_0c045552: /* original 3420, guest PC 0x0c045552 */
if(!s->budget--) { s->failed_pc=0x0c045552u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c045554;
P_0c045554: /* original 8907, guest PC 0x0c045554 */
if(!s->budget--) { s->failed_pc=0x0c045554u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c045566; }
goto P_0c045556;
P_0c045556: /* original 2448, guest PC 0x0c045556 */
if(!s->budget--) { s->failed_pc=0x0c045556u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c045558;
P_0c045558: /* original 8905, guest PC 0x0c045558 */
if(!s->budget--) { s->failed_pc=0x0c045558u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c045566; }
goto P_0c04555a;
P_0c04555a: /* original 65d2, guest PC 0x0c04555a */
if(!s->budget--) { s->failed_pc=0x0c04555au; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c04555c;
P_0c04555c: /* original d308, guest PC 0x0c04555c */
if(!s->budget--) { s->failed_pc=0x0c04555cu; return 0; }
r[3]=read(ram,0x0c045580u,4);
goto P_0c04555e;
P_0c04555e: /* original 655c, guest PC 0x0c04555e */
if(!s->budget--) { s->failed_pc=0x0c04555eu; return 0; }
r[5]=r[5]&255u;
goto P_0c045560;
P_0c045560: /* original 7501, guest PC 0x0c045560 */
if(!s->budget--) { s->failed_pc=0x0c045560u; return 0; }
r[5]+=0x00000001u;
goto P_0c045562;
P_0c045562: /* original 430b, guest PC 0x0c045562 */
if(!s->budget--) { s->failed_pc=0x0c045562u; return 0; }
target=r[3];
r[16]=code_base|0x0c045566u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045566u) { target=s->pc; goto dispatch; }
goto P_0c045566;
P_0c045564: /* original 64d3, guest PC 0x0c045564 */
if(!s->budget--) { s->failed_pc=0x0c045564u; return 0; }
r[4]=r[13];
goto P_0c045566;
P_0c045566: /* original 62e0, guest PC 0x0c045566 */
if(!s->budget--) { s->failed_pc=0x0c045566u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[2]=tmp;
goto P_0c045568;
P_0c045568: /* original 2228, guest PC 0x0c045568 */
if(!s->budget--) { s->failed_pc=0x0c045568u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04556a;
P_0c04556a: /* original 8d0f, guest PC 0x0c04556a */
if(!s->budget--) { s->failed_pc=0x0c04556au; return 0; }
cond=r[17]&1u;
r[4]=0x00000001u;
if(cond) { goto P_0c04558c; }
goto P_0c04556e;
P_0c04556c: /* original e401, guest PC 0x0c04556c */
if(!s->budget--) { s->failed_pc=0x0c04556cu; return 0; }
r[4]=0x00000001u;
goto P_0c04556e;
P_0c04556e: /* original a00e, guest PC 0x0c04556e */
if(!s->budget--) { s->failed_pc=0x0c04556eu; return 0; }
r[0]=0x00000009u;
goto P_0c04558e;
P_0c045570: /* original e009, guest PC 0x0c045570 */
if(!s->budget--) { s->failed_pc=0x0c045570u; return 0; }
r[0]=0x00000009u;
if(!vf3_matrix_family(0x0c045572u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c045572u; return 0; } return 1;
P_0c04558c: /* original 6043, guest PC 0x0c04558c */
if(!s->budget--) { s->failed_pc=0x0c04558cu; return 0; }
r[0]=r[4];
goto P_0c04558e;
P_0c04558e: /* original 80e4, guest PC 0x0c04558e */
if(!s->budget--) { s->failed_pc=0x0c04558eu; return 0; }
write(ram,r[14]+4,r[0],1);
goto P_0c045590;
P_0c045590: /* original 84e3, guest PC 0x0c045590 */
if(!s->budget--) { s->failed_pc=0x0c045590u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+3,1);
goto P_0c045592;
P_0c045592: /* original 2008, guest PC 0x0c045592 */
if(!s->budget--) { s->failed_pc=0x0c045592u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c045594;
P_0c045594: /* original 84e2, guest PC 0x0c045594 */
if(!s->budget--) { s->failed_pc=0x0c045594u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c045596;
P_0c045596: /* original 2008, guest PC 0x0c045596 */
if(!s->budget--) { s->failed_pc=0x0c045596u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c045598;
P_0c045598: /* original 8905, guest PC 0x0c045598 */
if(!s->budget--) { s->failed_pc=0x0c045598u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0455a6; }
goto P_0c04559a;
P_0c04559a: /* original e010, guest PC 0x0c04559a */
if(!s->budget--) { s->failed_pc=0x0c04559au; return 0; }
r[0]=0x00000010u;
goto P_0c04559c;
P_0c04559c: /* original 65e3, guest PC 0x0c04559c */
if(!s->budget--) { s->failed_pc=0x0c04559cu; return 0; }
r[5]=r[14];
goto P_0c04559e;
P_0c04559e: /* original 66d3, guest PC 0x0c04559e */
if(!s->budget--) { s->failed_pc=0x0c04559eu; return 0; }
r[6]=r[13];
goto P_0c0455a0;
P_0c0455a0: /* original 0c44, guest PC 0x0c0455a0 */
if(!s->budget--) { s->failed_pc=0x0c0455a0u; return 0; }
write(ram,r[12]+r[0],r[4],1);
goto P_0c0455a2;
P_0c0455a2: /* original b134, guest PC 0x0c0455a2 */
if(!s->budget--) { s->failed_pc=0x0c0455a2u; return 0; }
target=code_base|0x0c04580eu; r[16]=code_base|0x0c0455a6u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0455a6u) { target=s->pc; goto dispatch; }
goto P_0c0455a6;
P_0c0455a4: /* original 64c3, guest PC 0x0c0455a4 */
if(!s->budget--) { s->failed_pc=0x0c0455a4u; return 0; }
r[4]=r[12];
goto P_0c0455a6;
P_0c0455a6: /* original 84e3, guest PC 0x0c0455a6 */
if(!s->budget--) { s->failed_pc=0x0c0455a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+3,1);
goto P_0c0455a8;
P_0c0455a8: /* original 2008, guest PC 0x0c0455a8 */
if(!s->budget--) { s->failed_pc=0x0c0455a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0455aa;
P_0c0455aa: /* original 8901, guest PC 0x0c0455aa */
if(!s->budget--) { s->failed_pc=0x0c0455aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0455b0; }
goto P_0c0455ac;
P_0c0455ac: /* original b1dc, guest PC 0x0c0455ac */
if(!s->budget--) { s->failed_pc=0x0c0455acu; return 0; }
target=code_base|0x0c045968u; r[16]=code_base|0x0c0455b0u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0455b0u) { target=s->pc; goto dispatch; }
goto P_0c0455b0;
P_0c0455ae: /* original 64c3, guest PC 0x0c0455ae */
if(!s->budget--) { s->failed_pc=0x0c0455aeu; return 0; }
r[4]=r[12];
goto P_0c0455b0;
P_0c0455b0: /* original 4f26, guest PC 0x0c0455b0 */
if(!s->budget--) { s->failed_pc=0x0c0455b0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0455b2;
P_0c0455b2: /* original e000, guest PC 0x0c0455b2 */
if(!s->budget--) { s->failed_pc=0x0c0455b2u; return 0; }
r[0]=0x00000000u;
goto P_0c0455b4;
P_0c0455b4: /* original 6cf6, guest PC 0x0c0455b4 */
if(!s->budget--) { s->failed_pc=0x0c0455b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0455b6;
P_0c0455b6: /* original 6df6, guest PC 0x0c0455b6 */
if(!s->budget--) { s->failed_pc=0x0c0455b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0455b8;
P_0c0455b8: /* original 000b, guest PC 0x0c0455b8 */
if(!s->budget--) { s->failed_pc=0x0c0455b8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0455ba: /* original 6ef6, guest PC 0x0c0455ba */
if(!s->budget--) { s->failed_pc=0x0c0455bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0455bcu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
