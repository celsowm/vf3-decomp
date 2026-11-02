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
int vf3_away_batch245_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07b35cu: goto P_0c07b35c;
case 0x0c07b35eu: goto P_0c07b35e;
case 0x0c07b360u: goto P_0c07b360;
case 0x0c07b362u: goto P_0c07b362;
case 0x0c07b364u: goto P_0c07b364;
case 0x0c07b366u: goto P_0c07b366;
case 0x0c07b368u: goto P_0c07b368;
case 0x0c07b36au: goto P_0c07b36a;
case 0x0c07b36cu: goto P_0c07b36c;
case 0x0c07b36eu: goto P_0c07b36e;
case 0x0c07b370u: goto P_0c07b370;
case 0x0c07b372u: goto P_0c07b372;
case 0x0c07b374u: goto P_0c07b374;
case 0x0c07b376u: goto P_0c07b376;
case 0x0c07b378u: goto P_0c07b378;
case 0x0c07b37au: goto P_0c07b37a;
case 0x0c07b37cu: goto P_0c07b37c;
case 0x0c07b37eu: goto P_0c07b37e;
case 0x0c07b380u: goto P_0c07b380;
case 0x0c07b382u: goto P_0c07b382;
case 0x0c07b384u: goto P_0c07b384;
case 0x0c07b386u: goto P_0c07b386;
case 0x0c07b388u: goto P_0c07b388;
case 0x0c07b38au: goto P_0c07b38a;
case 0x0c07b38cu: goto P_0c07b38c;
case 0x0c07b38eu: goto P_0c07b38e;
case 0x0c07b390u: goto P_0c07b390;
case 0x0c07b392u: goto P_0c07b392;
case 0x0c07b394u: goto P_0c07b394;
case 0x0c07b396u: goto P_0c07b396;
case 0x0c07b4d4u: goto P_0c07b4d4;
case 0x0c07b4d6u: goto P_0c07b4d6;
case 0x0c07b4d8u: goto P_0c07b4d8;
case 0x0c07b4dau: goto P_0c07b4da;
case 0x0c07b4dcu: goto P_0c07b4dc;
case 0x0c07b4deu: goto P_0c07b4de;
case 0x0c07b4e0u: goto P_0c07b4e0;
case 0x0c07b4e2u: goto P_0c07b4e2;
case 0x0c07b4e4u: goto P_0c07b4e4;
case 0x0c07b4e6u: goto P_0c07b4e6;
case 0x0c07b4e8u: goto P_0c07b4e8;
case 0x0c07b4eau: goto P_0c07b4ea;
case 0x0c07b4ecu: goto P_0c07b4ec;
case 0x0c07b4eeu: goto P_0c07b4ee;
case 0x0c07b4f0u: goto P_0c07b4f0;
case 0x0c07b4f2u: goto P_0c07b4f2;
case 0x0c07b4f4u: goto P_0c07b4f4;
case 0x0c07b4f6u: goto P_0c07b4f6;
case 0x0c07b4f8u: goto P_0c07b4f8;
case 0x0c07b4fau: goto P_0c07b4fa;
case 0x0c07b4fcu: goto P_0c07b4fc;
case 0x0c07b4feu: goto P_0c07b4fe;
case 0x0c07b500u: goto P_0c07b500;
case 0x0c07b502u: goto P_0c07b502;
case 0x0c07b504u: goto P_0c07b504;
case 0x0c07b506u: goto P_0c07b506;
case 0x0c07b508u: goto P_0c07b508;
case 0x0c07b50au: goto P_0c07b50a;
case 0x0c07b50cu: goto P_0c07b50c;
case 0x0c07b50eu: goto P_0c07b50e;
case 0x0c07b510u: goto P_0c07b510;
case 0x0c07b512u: goto P_0c07b512;
case 0x0c07b514u: goto P_0c07b514;
case 0x0c07b516u: goto P_0c07b516;
case 0x0c07b518u: goto P_0c07b518;
case 0x0c07b51au: goto P_0c07b51a;
case 0x0c07b51cu: goto P_0c07b51c;
case 0x0c07b51eu: goto P_0c07b51e;
case 0x0c07b520u: goto P_0c07b520;
case 0x0c07b522u: goto P_0c07b522;
case 0x0c07b524u: goto P_0c07b524;
case 0x0c07b526u: goto P_0c07b526;
case 0x0c07b528u: goto P_0c07b528;
case 0x0c07b52au: goto P_0c07b52a;
case 0x0c07b52cu: goto P_0c07b52c;
case 0x0c07b52eu: goto P_0c07b52e;
case 0x0c07b530u: goto P_0c07b530;
case 0x0c07b532u: goto P_0c07b532;
case 0x0c07b534u: goto P_0c07b534;
case 0x0c07b536u: goto P_0c07b536;
case 0x0c07b538u: goto P_0c07b538;
case 0x0c07b53au: goto P_0c07b53a;
case 0x0c07b53cu: goto P_0c07b53c;
case 0x0c07b53eu: goto P_0c07b53e;
case 0x0c07b540u: goto P_0c07b540;
case 0x0c07b542u: goto P_0c07b542;
case 0x0c07b544u: goto P_0c07b544;
case 0x0c07b546u: goto P_0c07b546;
case 0x0c07b548u: goto P_0c07b548;
case 0x0c07b54au: goto P_0c07b54a;
case 0x0c07b54cu: goto P_0c07b54c;
case 0x0c07b54eu: goto P_0c07b54e;
case 0x0c07b550u: goto P_0c07b550;
case 0x0c07b552u: goto P_0c07b552;
case 0x0c07b554u: goto P_0c07b554;
case 0x0c07b556u: goto P_0c07b556;
case 0x0c07b558u: goto P_0c07b558;
case 0x0c07b55au: goto P_0c07b55a;
case 0x0c07b55cu: goto P_0c07b55c;
case 0x0c07b55eu: goto P_0c07b55e;
case 0x0c07b560u: goto P_0c07b560;
case 0x0c07b562u: goto P_0c07b562;
case 0x0c07b564u: goto P_0c07b564;
case 0x0c07b566u: goto P_0c07b566;
case 0x0c07b568u: goto P_0c07b568;
case 0x0c07b56au: goto P_0c07b56a;
case 0x0c07b56cu: goto P_0c07b56c;
case 0x0c07b56eu: goto P_0c07b56e;
case 0x0c07b570u: goto P_0c07b570;
case 0x0c07b572u: goto P_0c07b572;
case 0x0c07b574u: goto P_0c07b574;
case 0x0c07b576u: goto P_0c07b576;
case 0x0c07b578u: goto P_0c07b578;
case 0x0c07b57au: goto P_0c07b57a;
case 0x0c07b57cu: goto P_0c07b57c;
case 0x0c07b57eu: goto P_0c07b57e;
case 0x0c07b580u: goto P_0c07b580;
case 0x0c07b582u: goto P_0c07b582;
case 0x0c07b584u: goto P_0c07b584;
case 0x0c07b586u: goto P_0c07b586;
case 0x0c07b588u: goto P_0c07b588;
case 0x0c07b58au: goto P_0c07b58a;
case 0x0c07b58cu: goto P_0c07b58c;
case 0x0c07b58eu: goto P_0c07b58e;
case 0x0c07b590u: goto P_0c07b590;
case 0x0c07b592u: goto P_0c07b592;
case 0x0c07b594u: goto P_0c07b594;
case 0x0c07b596u: goto P_0c07b596;
case 0x0c07b598u: goto P_0c07b598;
case 0x0c07b59au: goto P_0c07b59a;
case 0x0c07b59cu: goto P_0c07b59c;
case 0x0c07b59eu: goto P_0c07b59e;
case 0x0c07b5a0u: goto P_0c07b5a0;
case 0x0c07b5a2u: goto P_0c07b5a2;
case 0x0c07b5a4u: goto P_0c07b5a4;
case 0x0c07b5a6u: goto P_0c07b5a6;
case 0x0c07b5a8u: goto P_0c07b5a8;
case 0x0c07b5aau: goto P_0c07b5aa;
case 0x0c07b5acu: goto P_0c07b5ac;
case 0x0c07b5aeu: goto P_0c07b5ae;
case 0x0c0c124eu: goto P_0c0c124e;
case 0x0c0c1250u: goto P_0c0c1250;
case 0x0c0c1252u: goto P_0c0c1252;
case 0x0c0c1254u: goto P_0c0c1254;
case 0x0c0c1256u: goto P_0c0c1256;
case 0x0c0c1258u: goto P_0c0c1258;
case 0x0c0c125au: goto P_0c0c125a;
case 0x0c0c125cu: goto P_0c0c125c;
case 0x0c0c125eu: goto P_0c0c125e;
case 0x0c0c1260u: goto P_0c0c1260;
case 0x0c0c1262u: goto P_0c0c1262;
case 0x0c0c1264u: goto P_0c0c1264;
case 0x0c0c1266u: goto P_0c0c1266;
case 0x0c0c1268u: goto P_0c0c1268;
case 0x0c0c126au: goto P_0c0c126a;
case 0x0c0c126cu: goto P_0c0c126c;
case 0x0c0c126eu: goto P_0c0c126e;
case 0x0c0c1270u: goto P_0c0c1270;
case 0x0c0c1272u: goto P_0c0c1272;
case 0x0c0c1274u: goto P_0c0c1274;
case 0x0c0c1276u: goto P_0c0c1276;
case 0x0c0c1278u: goto P_0c0c1278;
case 0x0c0c127au: goto P_0c0c127a;
case 0x0c0c127cu: goto P_0c0c127c;
case 0x0c0c127eu: goto P_0c0c127e;
case 0x0c0c1280u: goto P_0c0c1280;
case 0x0c0c1282u: goto P_0c0c1282;
case 0x0c0c1284u: goto P_0c0c1284;
case 0x0c0c1286u: goto P_0c0c1286;
case 0x0c0c1288u: goto P_0c0c1288;
case 0x0c0c128au: goto P_0c0c128a;
case 0x0c0c128cu: goto P_0c0c128c;
case 0x0c0c128eu: goto P_0c0c128e;
case 0x0c0c1290u: goto P_0c0c1290;
case 0x0c0c1292u: goto P_0c0c1292;
case 0x0c0c1294u: goto P_0c0c1294;
case 0x0c0c1296u: goto P_0c0c1296;
case 0x0c0c1298u: goto P_0c0c1298;
case 0x0c0c129au: goto P_0c0c129a;
case 0x0c0c129cu: goto P_0c0c129c;
case 0x0c0c129eu: goto P_0c0c129e;
case 0x0c0c12a0u: goto P_0c0c12a0;
case 0x0c0c12a2u: goto P_0c0c12a2;
case 0x0c0c12a4u: goto P_0c0c12a4;
case 0x0c0c12a6u: goto P_0c0c12a6;
case 0x0c0c12a8u: goto P_0c0c12a8;
case 0x0c0c12aau: goto P_0c0c12aa;
case 0x0c0c12acu: goto P_0c0c12ac;
case 0x0c0c12aeu: goto P_0c0c12ae;
case 0x0c0c12b0u: goto P_0c0c12b0;
case 0x0c0c12b2u: goto P_0c0c12b2;
case 0x0c0c12b4u: goto P_0c0c12b4;
case 0x0c0c12b6u: goto P_0c0c12b6;
case 0x0c0c12b8u: goto P_0c0c12b8;
case 0x0c0c12bau: goto P_0c0c12ba;
case 0x0c0c12bcu: goto P_0c0c12bc;
case 0x0c0c12beu: goto P_0c0c12be;
case 0x0c0c12c0u: goto P_0c0c12c0;
case 0x0c0c12c2u: goto P_0c0c12c2;
case 0x0c0c12c4u: goto P_0c0c12c4;
case 0x0c0c12c6u: goto P_0c0c12c6;
case 0x0c0c12c8u: goto P_0c0c12c8;
case 0x0c0c12cau: goto P_0c0c12ca;
case 0x0c0c12ccu: goto P_0c0c12cc;
case 0x0c0c12ceu: goto P_0c0c12ce;
case 0x0c0c12d0u: goto P_0c0c12d0;
case 0x0c0c12d2u: goto P_0c0c12d2;
case 0x0c0c12d4u: goto P_0c0c12d4;
case 0x0c0c12d6u: goto P_0c0c12d6;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07b35c: /* original d553, guest PC 0x0c07b35c */
if(!s->budget--) { s->failed_pc=0x0c07b35cu; return 0; }
r[5]=read(ram,0x0c07b4acu,4);
goto P_0c07b35e;
P_0c07b35e: /* original 7ffc, guest PC 0x0c07b35e */
if(!s->budget--) { s->failed_pc=0x0c07b35eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07b360;
P_0c07b360: /* original e004, guest PC 0x0c07b360 */
if(!s->budget--) { s->failed_pc=0x0c07b360u; return 0; }
r[0]=0x00000004u;
goto P_0c07b362;
P_0c07b362: /* original f358, guest PC 0x0c07b362 */
if(!s->budget--) { s->failed_pc=0x0c07b362u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c07b364;
P_0c07b364: /* original f432, guest PC 0x0c07b364 */
if(!s->budget--) { s->failed_pc=0x0c07b364u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c07b366;
P_0c07b366: /* original ff3a, guest PC 0x0c07b366 */
if(!s->budget--) { s->failed_pc=0x0c07b366u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c07b368;
P_0c07b368: /* original d651, guest PC 0x0c07b368 */
if(!s->budget--) { s->failed_pc=0x0c07b368u; return 0; }
r[6]=read(ram,0x0c07b4b0u,4);
goto P_0c07b36a;
P_0c07b36a: /* original d352, guest PC 0x0c07b36a */
if(!s->budget--) { s->failed_pc=0x0c07b36au; return 0; }
r[3]=read(ram,0x0c07b4b4u,4);
goto P_0c07b36c;
P_0c07b36c: /* original f968, guest PC 0x0c07b36c */
if(!s->budget--) { s->failed_pc=0x0c07b36cu; return 0; }
vf3_matrix_load(s,ram,9,r[6]);
goto P_0c07b36e;
P_0c07b36e: /* original d252, guest PC 0x0c07b36e */
if(!s->budget--) { s->failed_pc=0x0c07b36eu; return 0; }
r[2]=read(ram,0x0c07b4b8u,4);
goto P_0c07b370;
P_0c07b370: /* original f592, guest PC 0x0c07b370 */
if(!s->budget--) { s->failed_pc=0x0c07b370u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[9],r[18],'*');
goto P_0c07b372;
P_0c07b372: /* original fa38, guest PC 0x0c07b372 */
if(!s->budget--) { s->failed_pc=0x0c07b372u; return 0; }
vf3_matrix_load(s,ram,10,r[3]);
goto P_0c07b374;
P_0c07b374: /* original fb28, guest PC 0x0c07b374 */
if(!s->budget--) { s->failed_pc=0x0c07b374u; return 0; }
vf3_matrix_load(s,ram,11,r[2]);
goto P_0c07b376;
P_0c07b376: /* original f4a0, guest PC 0x0c07b376 */
if(!s->budget--) { s->failed_pc=0x0c07b376u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[10],r[18],'+');
goto P_0c07b378;
P_0c07b378: /* original f5b0, guest PC 0x0c07b378 */
if(!s->budget--) { s->failed_pc=0x0c07b378u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[11],r[18],'+');
goto P_0c07b37a;
P_0c07b37a: /* original f447, guest PC 0x0c07b37a */
if(!s->budget--) { s->failed_pc=0x0c07b37au; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c07b37c;
P_0c07b37c: /* original e008, guest PC 0x0c07b37c */
if(!s->budget--) { s->failed_pc=0x0c07b37cu; return 0; }
r[0]=0x00000008u;
goto P_0c07b37e;
P_0c07b37e: /* original f457, guest PC 0x0c07b37e */
if(!s->budget--) { s->failed_pc=0x0c07b37eu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c07b380;
P_0c07b380: /* original e00c, guest PC 0x0c07b380 */
if(!s->budget--) { s->failed_pc=0x0c07b380u; return 0; }
r[0]=0x0000000cu;
goto P_0c07b382;
P_0c07b382: /* original f487, guest PC 0x0c07b382 */
if(!s->budget--) { s->failed_pc=0x0c07b382u; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c07b384;
P_0c07b384: /* original e010, guest PC 0x0c07b384 */
if(!s->budget--) { s->failed_pc=0x0c07b384u; return 0; }
r[0]=0x00000010u;
goto P_0c07b386;
P_0c07b386: /* original f358, guest PC 0x0c07b386 */
if(!s->budget--) { s->failed_pc=0x0c07b386u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c07b388;
P_0c07b388: /* original f362, guest PC 0x0c07b388 */
if(!s->budget--) { s->failed_pc=0x0c07b388u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c07b38a;
P_0c07b38a: /* original f437, guest PC 0x0c07b38a */
if(!s->budget--) { s->failed_pc=0x0c07b38au; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07b38c;
P_0c07b38c: /* original e014, guest PC 0x0c07b38c */
if(!s->budget--) { s->failed_pc=0x0c07b38cu; return 0; }
r[0]=0x00000014u;
goto P_0c07b38e;
P_0c07b38e: /* original f368, guest PC 0x0c07b38e */
if(!s->budget--) { s->failed_pc=0x0c07b38eu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
goto P_0c07b390;
P_0c07b390: /* original f372, guest PC 0x0c07b390 */
if(!s->budget--) { s->failed_pc=0x0c07b390u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c07b392;
P_0c07b392: /* original f437, guest PC 0x0c07b392 */
if(!s->budget--) { s->failed_pc=0x0c07b392u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07b394;
P_0c07b394: /* original 000b, guest PC 0x0c07b394 */
if(!s->budget--) { s->failed_pc=0x0c07b394u; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c07b396: /* original 7f04, guest PC 0x0c07b396 */
if(!s->budget--) { s->failed_pc=0x0c07b396u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c07b398u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b398u; return 0; } return 1;
P_0c07b4d4: /* original 654d, guest PC 0x0c07b4d4 */
if(!s->budget--) { s->failed_pc=0x0c07b4d4u; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b4d6;
P_0c07b4d6: /* original 2fe6, guest PC 0x0c07b4d6 */
if(!s->budget--) { s->failed_pc=0x0c07b4d6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b4d8;
P_0c07b4d8: /* original 2fd6, guest PC 0x0c07b4d8 */
if(!s->budget--) { s->failed_pc=0x0c07b4d8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b4da;
P_0c07b4da: /* original 9378, guest PC 0x0c07b4da */
if(!s->budget--) { s->failed_pc=0x0c07b4dau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5ceu,2);
goto P_0c07b4dc;
P_0c07b4dc: /* original 2358, guest PC 0x0c07b4dc */
if(!s->budget--) { s->failed_pc=0x0c07b4dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c07b4de;
P_0c07b4de: /* original 8912, guest PC 0x0c07b4de */
if(!s->budget--) { s->failed_pc=0x0c07b4deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b506; }
goto P_0c07b4e0;
P_0c07b4e0: /* original 9476, guest PC 0x0c07b4e0 */
if(!s->budget--) { s->failed_pc=0x0c07b4e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5d0u,2);
goto P_0c07b4e2;
P_0c07b4e2: /* original d23c, guest PC 0x0c07b4e2 */
if(!s->budget--) { s->failed_pc=0x0c07b4e2u; return 0; }
r[2]=read(ram,0x0c07b5d4u,4);
goto P_0c07b4e4;
P_0c07b4e4: /* original 2459, guest PC 0x0c07b4e4 */
if(!s->budget--) { s->failed_pc=0x0c07b4e4u; return 0; }
r[4]&=r[5];
goto P_0c07b4e6;
P_0c07b4e6: /* original 6343, guest PC 0x0c07b4e6 */
if(!s->budget--) { s->failed_pc=0x0c07b4e6u; return 0; }
r[3]=r[4];
goto P_0c07b4e8;
P_0c07b4e8: /* original 6543, guest PC 0x0c07b4e8 */
if(!s->budget--) { s->failed_pc=0x0c07b4e8u; return 0; }
r[5]=r[4];
goto P_0c07b4ea;
P_0c07b4ea: /* original 4308, guest PC 0x0c07b4ea */
if(!s->budget--) { s->failed_pc=0x0c07b4eau; return 0; }
r[3]<<=2;
goto P_0c07b4ec;
P_0c07b4ec: /* original 4500, guest PC 0x0c07b4ec */
if(!s->budget--) { s->failed_pc=0x0c07b4ecu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07b4ee;
P_0c07b4ee: /* original 353c, guest PC 0x0c07b4ee */
if(!s->budget--) { s->failed_pc=0x0c07b4eeu; return 0; }
r[5]+=r[3];
goto P_0c07b4f0;
P_0c07b4f0: /* original 352c, guest PC 0x0c07b4f0 */
if(!s->budget--) { s->failed_pc=0x0c07b4f0u; return 0; }
r[5]+=r[2];
goto P_0c07b4f2;
P_0c07b4f2: /* original 8452, guest PC 0x0c07b4f2 */
if(!s->budget--) { s->failed_pc=0x0c07b4f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+2,1);
goto P_0c07b4f4;
P_0c07b4f4: /* original 6451, guest PC 0x0c07b4f4 */
if(!s->budget--) { s->failed_pc=0x0c07b4f4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[4]=tmp;
goto P_0c07b4f6;
P_0c07b4f6: /* original 660c, guest PC 0x0c07b4f6 */
if(!s->budget--) { s->failed_pc=0x0c07b4f6u; return 0; }
r[6]=r[0]&255u;
goto P_0c07b4f8;
P_0c07b4f8: /* original 8453, guest PC 0x0c07b4f8 */
if(!s->budget--) { s->failed_pc=0x0c07b4f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+3,1);
goto P_0c07b4fa;
P_0c07b4fa: /* original 670c, guest PC 0x0c07b4fa */
if(!s->budget--) { s->failed_pc=0x0c07b4fau; return 0; }
r[7]=r[0]&255u;
goto P_0c07b4fc;
P_0c07b4fc: /* original 8454, guest PC 0x0c07b4fc */
if(!s->budget--) { s->failed_pc=0x0c07b4fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+4,1);
goto P_0c07b4fe;
P_0c07b4fe: /* original 6e0c, guest PC 0x0c07b4fe */
if(!s->budget--) { s->failed_pc=0x0c07b4feu; return 0; }
r[14]=r[0]&255u;
goto P_0c07b500;
P_0c07b500: /* original 8455, guest PC 0x0c07b500 */
if(!s->budget--) { s->failed_pc=0x0c07b500u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+5,1);
goto P_0c07b502;
P_0c07b502: /* original a00a, guest PC 0x0c07b502 */
if(!s->budget--) { s->failed_pc=0x0c07b502u; return 0; }
r[13]=r[0]&255u;
goto P_0c07b51a;
P_0c07b504: /* original 6d0c, guest PC 0x0c07b504 */
if(!s->budget--) { s->failed_pc=0x0c07b504u; return 0; }
r[13]=r[0]&255u;
goto P_0c07b506;
P_0c07b506: /* original e500, guest PC 0x0c07b506 */
if(!s->budget--) { s->failed_pc=0x0c07b506u; return 0; }
r[5]=0x00000000u;
goto P_0c07b508;
P_0c07b508: /* original d333, guest PC 0x0c07b508 */
if(!s->budget--) { s->failed_pc=0x0c07b508u; return 0; }
r[3]=read(ram,0x0c07b5d8u,4);
goto P_0c07b50a;
P_0c07b50a: /* original 6753, guest PC 0x0c07b50a */
if(!s->budget--) { s->failed_pc=0x0c07b50au; return 0; }
r[7]=r[5];
goto P_0c07b50c;
P_0c07b50c: /* original 6653, guest PC 0x0c07b50c */
if(!s->budget--) { s->failed_pc=0x0c07b50cu; return 0; }
r[6]=r[5];
goto P_0c07b50e;
P_0c07b50e: /* original 654d, guest PC 0x0c07b50e */
if(!s->budget--) { s->failed_pc=0x0c07b50eu; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b510;
P_0c07b510: /* original 4508, guest PC 0x0c07b510 */
if(!s->budget--) { s->failed_pc=0x0c07b510u; return 0; }
r[5]<<=2;
goto P_0c07b512;
P_0c07b512: /* original 353c, guest PC 0x0c07b512 */
if(!s->budget--) { s->failed_pc=0x0c07b512u; return 0; }
r[5]+=r[3];
goto P_0c07b514;
P_0c07b514: /* original 8551, guest PC 0x0c07b514 */
if(!s->budget--) { s->failed_pc=0x0c07b514u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c07b516;
P_0c07b516: /* original 6e51, guest PC 0x0c07b516 */
if(!s->budget--) { s->failed_pc=0x0c07b516u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[14]=tmp;
goto P_0c07b518;
P_0c07b518: /* original 6d03, guest PC 0x0c07b518 */
if(!s->budget--) { s->failed_pc=0x0c07b518u; return 0; }
r[13]=r[0];
goto P_0c07b51a;
P_0c07b51a: /* original 666d, guest PC 0x0c07b51a */
if(!s->budget--) { s->failed_pc=0x0c07b51au; return 0; }
r[6]=r[6]&65535u;
goto P_0c07b51c;
P_0c07b51c: /* original d22f, guest PC 0x0c07b51c */
if(!s->budget--) { s->failed_pc=0x0c07b51cu; return 0; }
r[2]=read(ram,0x0c07b5dcu,4);
goto P_0c07b51e;
P_0c07b51e: /* original 4608, guest PC 0x0c07b51e */
if(!s->budget--) { s->failed_pc=0x0c07b51eu; return 0; }
r[6]<<=2;
goto P_0c07b520;
P_0c07b520: /* original 4600, guest PC 0x0c07b520 */
if(!s->budget--) { s->failed_pc=0x0c07b520u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c07b522;
P_0c07b522: /* original 677d, guest PC 0x0c07b522 */
if(!s->budget--) { s->failed_pc=0x0c07b522u; return 0; }
r[7]=r[7]&65535u;
goto P_0c07b524;
P_0c07b524: /* original 4708, guest PC 0x0c07b524 */
if(!s->budget--) { s->failed_pc=0x0c07b524u; return 0; }
r[7]<<=2;
goto P_0c07b526;
P_0c07b526: /* original 634d, guest PC 0x0c07b526 */
if(!s->budget--) { s->failed_pc=0x0c07b526u; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b528;
P_0c07b528: /* original 2232, guest PC 0x0c07b528 */
if(!s->budget--) { s->failed_pc=0x0c07b528u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c07b52a;
P_0c07b52a: /* original 4700, guest PC 0x0c07b52a */
if(!s->budget--) { s->failed_pc=0x0c07b52au; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c07b52c;
P_0c07b52c: /* original 465a, guest PC 0x0c07b52c */
if(!s->budget--) { s->failed_pc=0x0c07b52cu; return 0; }
r[53]=r[6];
goto P_0c07b52e;
P_0c07b52e: /* original 6eed, guest PC 0x0c07b52e */
if(!s->budget--) { s->failed_pc=0x0c07b52eu; return 0; }
r[14]=r[14]&65535u;
goto P_0c07b530;
P_0c07b530: /* original d32b, guest PC 0x0c07b530 */
if(!s->budget--) { s->failed_pc=0x0c07b530u; return 0; }
r[3]=read(ram,0x0c07b5e0u,4);
goto P_0c07b532;
P_0c07b532: /* original 4e08, guest PC 0x0c07b532 */
if(!s->budget--) { s->failed_pc=0x0c07b532u; return 0; }
r[14]<<=2;
goto P_0c07b534;
P_0c07b534: /* original 4e00, guest PC 0x0c07b534 */
if(!s->budget--) { s->failed_pc=0x0c07b534u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07b536;
P_0c07b536: /* original f32d, guest PC 0x0c07b536 */
if(!s->budget--) { s->failed_pc=0x0c07b536u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b538;
P_0c07b538: /* original 6ddd, guest PC 0x0c07b538 */
if(!s->budget--) { s->failed_pc=0x0c07b538u; return 0; }
r[13]=r[13]&65535u;
goto P_0c07b53a;
P_0c07b53a: /* original 4d08, guest PC 0x0c07b53a */
if(!s->budget--) { s->failed_pc=0x0c07b53au; return 0; }
r[13]<<=2;
goto P_0c07b53c;
P_0c07b53c: /* original 4d00, guest PC 0x0c07b53c */
if(!s->budget--) { s->failed_pc=0x0c07b53cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c07b53e;
P_0c07b53e: /* original 72e8, guest PC 0x0c07b53e */
if(!s->budget--) { s->failed_pc=0x0c07b53eu; return 0; }
r[2]+=0xffffffe8u;
goto P_0c07b540;
P_0c07b540: /* original 654d, guest PC 0x0c07b540 */
if(!s->budget--) { s->failed_pc=0x0c07b540u; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b542;
P_0c07b542: /* original f33a, guest PC 0x0c07b542 */
if(!s->budget--) { s->failed_pc=0x0c07b542u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c07b544;
P_0c07b544: /* original 730c, guest PC 0x0c07b544 */
if(!s->budget--) { s->failed_pc=0x0c07b544u; return 0; }
r[3]+=0x0000000cu;
goto P_0c07b546;
P_0c07b546: /* original 475a, guest PC 0x0c07b546 */
if(!s->budget--) { s->failed_pc=0x0c07b546u; return 0; }
r[53]=r[7];
goto P_0c07b548;
P_0c07b548: /* original d126, guest PC 0x0c07b548 */
if(!s->budget--) { s->failed_pc=0x0c07b548u; return 0; }
r[1]=read(ram,0x0c07b5e4u,4);
goto P_0c07b54a;
P_0c07b54a: /* original f32d, guest PC 0x0c07b54a */
if(!s->budget--) { s->failed_pc=0x0c07b54au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b54c;
P_0c07b54c: /* original f13a, guest PC 0x0c07b54c */
if(!s->budget--) { s->failed_pc=0x0c07b54cu; return 0; }
vf3_matrix_store(s,ram,3,r[1]);
goto P_0c07b54e;
P_0c07b54e: /* original 4e5a, guest PC 0x0c07b54e */
if(!s->budget--) { s->failed_pc=0x0c07b54eu; return 0; }
r[53]=r[14];
goto P_0c07b550;
P_0c07b550: /* original f32d, guest PC 0x0c07b550 */
if(!s->budget--) { s->failed_pc=0x0c07b550u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b552;
P_0c07b552: /* original f23a, guest PC 0x0c07b552 */
if(!s->budget--) { s->failed_pc=0x0c07b552u; return 0; }
vf3_matrix_store(s,ram,3,r[2]);
goto P_0c07b554;
P_0c07b554: /* original 4d5a, guest PC 0x0c07b554 */
if(!s->budget--) { s->failed_pc=0x0c07b554u; return 0; }
r[53]=r[13];
goto P_0c07b556;
P_0c07b556: /* original f32d, guest PC 0x0c07b556 */
if(!s->budget--) { s->failed_pc=0x0c07b556u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b558;
P_0c07b558: /* original f33a, guest PC 0x0c07b558 */
if(!s->budget--) { s->failed_pc=0x0c07b558u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c07b55a;
P_0c07b55a: /* original d11f, guest PC 0x0c07b55a */
if(!s->budget--) { s->failed_pc=0x0c07b55au; return 0; }
r[1]=read(ram,0x0c07b5d8u,4);
goto P_0c07b55c;
P_0c07b55c: /* original 4508, guest PC 0x0c07b55c */
if(!s->budget--) { s->failed_pc=0x0c07b55cu; return 0; }
r[5]<<=2;
goto P_0c07b55e;
P_0c07b55e: /* original f49d, guest PC 0x0c07b55e */
if(!s->budget--) { s->failed_pc=0x0c07b55eu; return 0; }
fr[4]=0x3f800000u;
goto P_0c07b560;
P_0c07b560: /* original 7308, guest PC 0x0c07b560 */
if(!s->budget--) { s->failed_pc=0x0c07b560u; return 0; }
r[3]+=0x00000008u;
goto P_0c07b562;
P_0c07b562: /* original 351c, guest PC 0x0c07b562 */
if(!s->budget--) { s->failed_pc=0x0c07b562u; return 0; }
r[5]+=r[1];
goto P_0c07b564;
P_0c07b564: /* original f24c, guest PC 0x0c07b564 */
if(!s->budget--) { s->failed_pc=0x0c07b564u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c07b566;
P_0c07b566: /* original 6251, guest PC 0x0c07b566 */
if(!s->budget--) { s->failed_pc=0x0c07b566u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c07b568;
P_0c07b568: /* original 8551, guest PC 0x0c07b568 */
if(!s->budget--) { s->failed_pc=0x0c07b568u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c07b56a;
P_0c07b56a: /* original 642d, guest PC 0x0c07b56a */
if(!s->budget--) { s->failed_pc=0x0c07b56au; return 0; }
r[4]=r[2]&65535u;
goto P_0c07b56c;
P_0c07b56c: /* original d21e, guest PC 0x0c07b56c */
if(!s->budget--) { s->failed_pc=0x0c07b56cu; return 0; }
r[2]=read(ram,0x0c07b5e8u,4);
goto P_0c07b56e;
P_0c07b56e: /* original 4408, guest PC 0x0c07b56e */
if(!s->budget--) { s->failed_pc=0x0c07b56eu; return 0; }
r[4]<<=2;
goto P_0c07b570;
P_0c07b570: /* original 4400, guest PC 0x0c07b570 */
if(!s->budget--) { s->failed_pc=0x0c07b570u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07b572;
P_0c07b572: /* original 6123, guest PC 0x0c07b572 */
if(!s->budget--) { s->failed_pc=0x0c07b572u; return 0; }
r[1]=r[2];
goto P_0c07b574;
P_0c07b574: /* original 644d, guest PC 0x0c07b574 */
if(!s->budget--) { s->failed_pc=0x0c07b574u; return 0; }
r[4]=r[4]&65535u;
goto P_0c07b576;
P_0c07b576: /* original 445a, guest PC 0x0c07b576 */
if(!s->budget--) { s->failed_pc=0x0c07b576u; return 0; }
r[53]=r[4];
goto P_0c07b578;
P_0c07b578: /* original 650d, guest PC 0x0c07b578 */
if(!s->budget--) { s->failed_pc=0x0c07b578u; return 0; }
r[5]=r[0]&65535u;
goto P_0c07b57a;
P_0c07b57a: /* original 4508, guest PC 0x0c07b57a */
if(!s->budget--) { s->failed_pc=0x0c07b57au; return 0; }
r[5]<<=2;
goto P_0c07b57c;
P_0c07b57c: /* original 4500, guest PC 0x0c07b57c */
if(!s->budget--) { s->failed_pc=0x0c07b57cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07b57e;
P_0c07b57e: /* original f32d, guest PC 0x0c07b57e */
if(!s->budget--) { s->failed_pc=0x0c07b57eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b580;
P_0c07b580: /* original 655d, guest PC 0x0c07b580 */
if(!s->budget--) { s->failed_pc=0x0c07b580u; return 0; }
r[5]=r[5]&65535u;
goto P_0c07b582;
P_0c07b582: /* original f233, guest PC 0x0c07b582 */
if(!s->budget--) { s->failed_pc=0x0c07b582u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'/');
goto P_0c07b584;
P_0c07b584: /* original f22a, guest PC 0x0c07b584 */
if(!s->budget--) { s->failed_pc=0x0c07b584u; return 0; }
vf3_matrix_store(s,ram,2,r[2]);
goto P_0c07b586;
P_0c07b586: /* original 72f8, guest PC 0x0c07b586 */
if(!s->budget--) { s->failed_pc=0x0c07b586u; return 0; }
r[2]+=0xfffffff8u;
goto P_0c07b588;
P_0c07b588: /* original 455a, guest PC 0x0c07b588 */
if(!s->budget--) { s->failed_pc=0x0c07b588u; return 0; }
r[53]=r[5];
goto P_0c07b58a;
P_0c07b58a: /* original f32d, guest PC 0x0c07b58a */
if(!s->budget--) { s->failed_pc=0x0c07b58au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b58c;
P_0c07b58c: /* original f433, guest PC 0x0c07b58c */
if(!s->budget--) { s->failed_pc=0x0c07b58cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c07b58e;
P_0c07b58e: /* original f34a, guest PC 0x0c07b58e */
if(!s->budget--) { s->failed_pc=0x0c07b58eu; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c07b590;
P_0c07b590: /* original 7304, guest PC 0x0c07b590 */
if(!s->budget--) { s->failed_pc=0x0c07b590u; return 0; }
r[3]+=0x00000004u;
goto P_0c07b592;
P_0c07b592: /* original f318, guest PC 0x0c07b592 */
if(!s->budget--) { s->failed_pc=0x0c07b592u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c07b594;
P_0c07b594: /* original f228, guest PC 0x0c07b594 */
if(!s->budget--) { s->failed_pc=0x0c07b594u; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
goto P_0c07b596;
P_0c07b596: /* original f232, guest PC 0x0c07b596 */
if(!s->budget--) { s->failed_pc=0x0c07b596u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07b598;
P_0c07b598: /* original f32a, guest PC 0x0c07b598 */
if(!s->budget--) { s->failed_pc=0x0c07b598u; return 0; }
vf3_matrix_store(s,ram,2,r[3]);
goto P_0c07b59a;
P_0c07b59a: /* original d014, guest PC 0x0c07b59a */
if(!s->budget--) { s->failed_pc=0x0c07b59au; return 0; }
r[0]=read(ram,0x0c07b5ecu,4);
goto P_0c07b59c;
P_0c07b59c: /* original 720c, guest PC 0x0c07b59c */
if(!s->budget--) { s->failed_pc=0x0c07b59cu; return 0; }
r[2]+=0x0000000cu;
goto P_0c07b59e;
P_0c07b59e: /* original f328, guest PC 0x0c07b59e */
if(!s->budget--) { s->failed_pc=0x0c07b59eu; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
goto P_0c07b5a0;
P_0c07b5a0: /* original 7304, guest PC 0x0c07b5a0 */
if(!s->budget--) { s->failed_pc=0x0c07b5a0u; return 0; }
r[3]+=0x00000004u;
goto P_0c07b5a2;
P_0c07b5a2: /* original f208, guest PC 0x0c07b5a2 */
if(!s->budget--) { s->failed_pc=0x0c07b5a2u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c07b5a4;
P_0c07b5a4: /* original 70f4, guest PC 0x0c07b5a4 */
if(!s->budget--) { s->failed_pc=0x0c07b5a4u; return 0; }
r[0]+=0xfffffff4u;
goto P_0c07b5a6;
P_0c07b5a6: /* original f232, guest PC 0x0c07b5a6 */
if(!s->budget--) { s->failed_pc=0x0c07b5a6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07b5a8;
P_0c07b5a8: /* original f32a, guest PC 0x0c07b5a8 */
if(!s->budget--) { s->failed_pc=0x0c07b5a8u; return 0; }
vf3_matrix_store(s,ram,2,r[3]);
goto P_0c07b5aa;
P_0c07b5aa: /* original 6df6, guest PC 0x0c07b5aa */
if(!s->budget--) { s->failed_pc=0x0c07b5aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b5ac;
P_0c07b5ac: /* original 000b, guest PC 0x0c07b5ac */
if(!s->budget--) { s->failed_pc=0x0c07b5acu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b5ae: /* original 6ef6, guest PC 0x0c07b5ae */
if(!s->budget--) { s->failed_pc=0x0c07b5aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07b5b0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b5b0u; return 0; } return 1;
P_0c0c124e: /* original e100, guest PC 0x0c0c124e */
if(!s->budget--) { s->failed_pc=0x0c0c124eu; return 0; }
r[1]=0x00000000u;
goto P_0c0c1250;
P_0c0c1250: /* original d324, guest PC 0x0c0c1250 */
if(!s->budget--) { s->failed_pc=0x0c0c1250u; return 0; }
r[3]=read(ram,0x0c0c12e4u,4);
goto P_0c0c1252;
P_0c0c1252: /* original e022, guest PC 0x0c0c1252 */
if(!s->budget--) { s->failed_pc=0x0c0c1252u; return 0; }
r[0]=0x00000022u;
goto P_0c0c1254;
P_0c0c1254: /* original 7ffc, guest PC 0x0c0c1254 */
if(!s->budget--) { s->failed_pc=0x0c0c1254u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c1256;
P_0c0c1256: /* original 2f32, guest PC 0x0c0c1256 */
if(!s->budget--) { s->failed_pc=0x0c0c1256u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c1258;
P_0c0c1258: /* original 0415, guest PC 0x0c0c1258 */
if(!s->budget--) { s->failed_pc=0x0c0c1258u; return 0; }
write(ram,r[4]+r[0],r[1],2);
goto P_0c0c125a;
P_0c0c125a: /* original 6063, guest PC 0x0c0c125a */
if(!s->budget--) { s->failed_pc=0x0c0c125au; return 0; }
r[0]=r[6];
goto P_0c0c125c;
P_0c0c125c: /* original 1474, guest PC 0x0c0c125c */
if(!s->budget--) { s->failed_pc=0x0c0c125cu; return 0; }
write(ram,r[4]+16,r[7],4);
goto P_0c0c125e;
P_0c0c125e: /* original 53f1, guest PC 0x0c0c125e */
if(!s->budget--) { s->failed_pc=0x0c0c125eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c1260;
P_0c0c1260: /* original 1433, guest PC 0x0c0c1260 */
if(!s->budget--) { s->failed_pc=0x0c0c1260u; return 0; }
write(ram,r[4]+12,r[3],4);
goto P_0c0c1262;
P_0c0c1262: /* original 2451, guest PC 0x0c0c1262 */
if(!s->budget--) { s->failed_pc=0x0c0c1262u; return 0; }
write(ram,r[4],r[5],2);
goto P_0c0c1264;
P_0c0c1264: /* original 8141, guest PC 0x0c0c1264 */
if(!s->budget--) { s->failed_pc=0x0c0c1264u; return 0; }
write(ram,r[4]+2,r[0],2);
goto P_0c0c1266;
P_0c0c1266: /* original e040, guest PC 0x0c0c1266 */
if(!s->budget--) { s->failed_pc=0x0c0c1266u; return 0; }
r[0]=0x00000040u;
goto P_0c0c1268;
P_0c0c1268: /* original 53f2, guest PC 0x0c0c1268 */
if(!s->budget--) { s->failed_pc=0x0c0c1268u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c126a;
P_0c0c126a: /* original 1436, guest PC 0x0c0c126a */
if(!s->budget--) { s->failed_pc=0x0c0c126au; return 0; }
write(ram,r[4]+24,r[3],4);
goto P_0c0c126c;
P_0c0c126c: /* original 52f3, guest PC 0x0c0c126c */
if(!s->budget--) { s->failed_pc=0x0c0c126cu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0c126e;
P_0c0c126e: /* original 1427, guest PC 0x0c0c126e */
if(!s->budget--) { s->failed_pc=0x0c0c126eu; return 0; }
write(ram,r[4]+28,r[2],4);
goto P_0c0c1270;
P_0c0c1270: /* original 8142, guest PC 0x0c0c1270 */
if(!s->budget--) { s->failed_pc=0x0c0c1270u; return 0; }
write(ram,r[4]+4,r[0],2);
goto P_0c0c1272;
P_0c0c1272: /* original e030, guest PC 0x0c0c1272 */
if(!s->budget--) { s->failed_pc=0x0c0c1272u; return 0; }
r[0]=0x00000030u;
goto P_0c0c1274;
P_0c0c1274: /* original 8143, guest PC 0x0c0c1274 */
if(!s->budget--) { s->failed_pc=0x0c0c1274u; return 0; }
write(ram,r[4]+6,r[0],2);
goto P_0c0c1276;
P_0c0c1276: /* original e03e, guest PC 0x0c0c1276 */
if(!s->budget--) { s->failed_pc=0x0c0c1276u; return 0; }
r[0]=0x0000003eu;
goto P_0c0c1278;
P_0c0c1278: /* original 8144, guest PC 0x0c0c1278 */
if(!s->budget--) { s->failed_pc=0x0c0c1278u; return 0; }
write(ram,r[4]+8,r[0],2);
goto P_0c0c127a;
P_0c0c127a: /* original e02e, guest PC 0x0c0c127a */
if(!s->budget--) { s->failed_pc=0x0c0c127au; return 0; }
r[0]=0x0000002eu;
goto P_0c0c127c;
P_0c0c127c: /* original 8145, guest PC 0x0c0c127c */
if(!s->budget--) { s->failed_pc=0x0c0c127cu; return 0; }
write(ram,r[4]+10,r[0],2);
goto P_0c0c127e;
P_0c0c127e: /* original 6013, guest PC 0x0c0c127e */
if(!s->budget--) { s->failed_pc=0x0c0c127eu; return 0; }
r[0]=r[1];
goto P_0c0c1280;
P_0c0c1280: /* original 814a, guest PC 0x0c0c1280 */
if(!s->budget--) { s->failed_pc=0x0c0c1280u; return 0; }
write(ram,r[4]+20,r[0],2);
goto P_0c0c1282;
P_0c0c1282: /* original 814b, guest PC 0x0c0c1282 */
if(!s->budget--) { s->failed_pc=0x0c0c1282u; return 0; }
write(ram,r[4]+22,r[0],2);
goto P_0c0c1284;
P_0c0c1284: /* original e020, guest PC 0x0c0c1284 */
if(!s->budget--) { s->failed_pc=0x0c0c1284u; return 0; }
r[0]=0x00000020u;
goto P_0c0c1286;
P_0c0c1286: /* original 932a, guest PC 0x0c0c1286 */
if(!s->budget--) { s->failed_pc=0x0c0c1286u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12deu,2);
goto P_0c0c1288;
P_0c0c1288: /* original 0435, guest PC 0x0c0c1288 */
if(!s->budget--) { s->failed_pc=0x0c0c1288u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c0c128a;
P_0c0c128a: /* original e3ff, guest PC 0x0c0c128a */
if(!s->budget--) { s->failed_pc=0x0c0c128au; return 0; }
r[3]=0xffffffffu;
goto P_0c0c128c;
P_0c0c128c: /* original 62f2, guest PC 0x0c0c128c */
if(!s->budget--) { s->failed_pc=0x0c0c128cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c128e;
P_0c0c128e: /* original 9027, guest PC 0x0c0c128e */
if(!s->budget--) { s->failed_pc=0x0c0c128eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12e0u,2);
goto P_0c0c1290;
P_0c0c1290: /* original 0236, guest PC 0x0c0c1290 */
if(!s->budget--) { s->failed_pc=0x0c0c1290u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0c1292;
P_0c0c1292: /* original a000, guest PC 0x0c0c1292 */
if(!s->budget--) { s->failed_pc=0x0c0c1292u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c1296;
P_0c0c1294: /* original 7f04, guest PC 0x0c0c1294 */
if(!s->budget--) { s->failed_pc=0x0c0c1294u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c1296;
P_0c0c1296: /* original 2fe6, guest PC 0x0c0c1296 */
if(!s->budget--) { s->failed_pc=0x0c0c1296u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1298;
P_0c0c1298: /* original 6e43, guest PC 0x0c0c1298 */
if(!s->budget--) { s->failed_pc=0x0c0c1298u; return 0; }
r[14]=r[4];
goto P_0c0c129a;
P_0c0c129a: /* original 2fd6, guest PC 0x0c0c129a */
if(!s->budget--) { s->failed_pc=0x0c0c129au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c129c;
P_0c0c129c: /* original ed00, guest PC 0x0c0c129c */
if(!s->budget--) { s->failed_pc=0x0c0c129cu; return 0; }
r[13]=0x00000000u;
goto P_0c0c129e;
P_0c0c129e: /* original 2fc6, guest PC 0x0c0c129e */
if(!s->budget--) { s->failed_pc=0x0c0c129eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c12a0;
P_0c0c12a0: /* original ec78, guest PC 0x0c0c12a0 */
if(!s->budget--) { s->failed_pc=0x0c0c12a0u; return 0; }
r[12]=0x00000078u;
goto P_0c0c12a2;
P_0c0c12a2: /* original 2fb6, guest PC 0x0c0c12a2 */
if(!s->budget--) { s->failed_pc=0x0c0c12a2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c12a4;
P_0c0c12a4: /* original 4f22, guest PC 0x0c0c12a4 */
if(!s->budget--) { s->failed_pc=0x0c0c12a4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c12a6;
P_0c0c12a6: /* original 7ffc, guest PC 0x0c0c12a6 */
if(!s->budget--) { s->failed_pc=0x0c0c12a6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c12a8;
P_0c0c12a8: /* original 2f42, guest PC 0x0c0c12a8 */
if(!s->budget--) { s->failed_pc=0x0c0c12a8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c12aa;
P_0c0c12aa: /* original 5ee3, guest PC 0x0c0c12aa */
if(!s->budget--) { s->failed_pc=0x0c0c12aau; return 0; }
r[14]=read(ram,r[14]+12,4);
goto P_0c0c12ac;
P_0c0c12ac: /* original db0f, guest PC 0x0c0c12ac */
if(!s->budget--) { s->failed_pc=0x0c0c12acu; return 0; }
r[11]=read(ram,0x0c0c12ecu,4);
goto P_0c0c12ae;
P_0c0c12ae: /* original e500, guest PC 0x0c0c12ae */
if(!s->budget--) { s->failed_pc=0x0c0c12aeu; return 0; }
r[5]=0x00000000u;
goto P_0c0c12b0;
P_0c0c12b0: /* original e644, guest PC 0x0c0c12b0 */
if(!s->budget--) { s->failed_pc=0x0c0c12b0u; return 0; }
r[6]=0x00000044u;
goto P_0c0c12b2;
P_0c0c12b2: /* original 4b0b, guest PC 0x0c0c12b2 */
if(!s->budget--) { s->failed_pc=0x0c0c12b2u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c12b6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c12b6u) { target=s->pc; goto dispatch; }
goto P_0c0c12b6;
P_0c0c12b4: /* original 64e3, guest PC 0x0c0c12b4 */
if(!s->budget--) { s->failed_pc=0x0c0c12b4u; return 0; }
r[4]=r[14];
goto P_0c0c12b6;
P_0c0c12b6: /* original 7d01, guest PC 0x0c0c12b6 */
if(!s->budget--) { s->failed_pc=0x0c0c12b6u; return 0; }
r[13]+=0x00000001u;
goto P_0c0c12b8;
P_0c0c12b8: /* original 3dc2, guest PC 0x0c0c12b8 */
if(!s->budget--) { s->failed_pc=0x0c0c12b8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[12])!=0);
goto P_0c0c12ba;
P_0c0c12ba: /* original 8ff8, guest PC 0x0c0c12ba */
if(!s->budget--) { s->failed_pc=0x0c0c12bau; return 0; }
cond=r[17]&1u;
r[14]+=0x00000044u;
if(!cond) { goto P_0c0c12ae; }
goto P_0c0c12be;
P_0c0c12bc: /* original 7e44, guest PC 0x0c0c12bc */
if(!s->budget--) { s->failed_pc=0x0c0c12bcu; return 0; }
r[14]+=0x00000044u;
goto P_0c0c12be;
P_0c0c12be: /* original 63f2, guest PC 0x0c0c12be */
if(!s->budget--) { s->failed_pc=0x0c0c12beu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c12c0;
P_0c0c12c0: /* original 7f04, guest PC 0x0c0c12c0 */
if(!s->budget--) { s->failed_pc=0x0c0c12c0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c12c2;
P_0c0c12c2: /* original 4f26, guest PC 0x0c0c12c2 */
if(!s->budget--) { s->failed_pc=0x0c0c12c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c12c4;
P_0c0c12c4: /* original e022, guest PC 0x0c0c12c4 */
if(!s->budget--) { s->failed_pc=0x0c0c12c4u; return 0; }
r[0]=0x00000022u;
goto P_0c0c12c6;
P_0c0c12c6: /* original 013d, guest PC 0x0c0c12c6 */
if(!s->budget--) { s->failed_pc=0x0c0c12c6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c12c8;
P_0c0c12c8: /* original e201, guest PC 0x0c0c12c8 */
if(!s->budget--) { s->failed_pc=0x0c0c12c8u; return 0; }
r[2]=0x00000001u;
goto P_0c0c12ca;
P_0c0c12ca: /* original 212b, guest PC 0x0c0c12ca */
if(!s->budget--) { s->failed_pc=0x0c0c12cau; return 0; }
r[1]|=r[2];
goto P_0c0c12cc;
P_0c0c12cc: /* original 0315, guest PC 0x0c0c12cc */
if(!s->budget--) { s->failed_pc=0x0c0c12ccu; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c0c12ce;
P_0c0c12ce: /* original 6bf6, guest PC 0x0c0c12ce */
if(!s->budget--) { s->failed_pc=0x0c0c12ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c12d0;
P_0c0c12d0: /* original 6cf6, guest PC 0x0c0c12d0 */
if(!s->budget--) { s->failed_pc=0x0c0c12d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c12d2;
P_0c0c12d2: /* original 6df6, guest PC 0x0c0c12d2 */
if(!s->budget--) { s->failed_pc=0x0c0c12d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c12d4;
P_0c0c12d4: /* original 000b, guest PC 0x0c0c12d4 */
if(!s->budget--) { s->failed_pc=0x0c0c12d4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c12d6: /* original 6ef6, guest PC 0x0c0c12d6 */
if(!s->budget--) { s->failed_pc=0x0c0c12d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c12d8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c12d8u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
