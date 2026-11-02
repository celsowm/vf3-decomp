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
int vf3_away_batch239_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07b398u: goto P_0c07b398;
case 0x0c07b39au: goto P_0c07b39a;
case 0x0c07b39cu: goto P_0c07b39c;
case 0x0c07b39eu: goto P_0c07b39e;
case 0x0c07b3a0u: goto P_0c07b3a0;
case 0x0c07b3a2u: goto P_0c07b3a2;
case 0x0c07b3a4u: goto P_0c07b3a4;
case 0x0c07b3a6u: goto P_0c07b3a6;
case 0x0c07b3a8u: goto P_0c07b3a8;
case 0x0c07b3aau: goto P_0c07b3aa;
case 0x0c07b3acu: goto P_0c07b3ac;
case 0x0c07b3aeu: goto P_0c07b3ae;
case 0x0c07b3b0u: goto P_0c07b3b0;
case 0x0c07b3b2u: goto P_0c07b3b2;
case 0x0c07b3b4u: goto P_0c07b3b4;
case 0x0c07b3b6u: goto P_0c07b3b6;
case 0x0c07b3b8u: goto P_0c07b3b8;
case 0x0c07b3bau: goto P_0c07b3ba;
case 0x0c07b3bcu: goto P_0c07b3bc;
case 0x0c07b3beu: goto P_0c07b3be;
case 0x0c07b3c0u: goto P_0c07b3c0;
case 0x0c07b3c2u: goto P_0c07b3c2;
case 0x0c07b3c4u: goto P_0c07b3c4;
case 0x0c07b3c6u: goto P_0c07b3c6;
case 0x0c07b3c8u: goto P_0c07b3c8;
case 0x0c07b3cau: goto P_0c07b3ca;
case 0x0c07b3ccu: goto P_0c07b3cc;
case 0x0c07b3ceu: goto P_0c07b3ce;
case 0x0c07b3d0u: goto P_0c07b3d0;
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
case 0x0c0c12f0u: goto P_0c0c12f0;
case 0x0c0c12f2u: goto P_0c0c12f2;
case 0x0c0c12f4u: goto P_0c0c12f4;
case 0x0c0c12f6u: goto P_0c0c12f6;
case 0x0c0c12f8u: goto P_0c0c12f8;
case 0x0c0c12fau: goto P_0c0c12fa;
case 0x0c0c12fcu: goto P_0c0c12fc;
case 0x0c0c12feu: goto P_0c0c12fe;
case 0x0c0c1300u: goto P_0c0c1300;
case 0x0c0c1302u: goto P_0c0c1302;
case 0x0c0c1304u: goto P_0c0c1304;
case 0x0c0c1306u: goto P_0c0c1306;
case 0x0c0c1308u: goto P_0c0c1308;
case 0x0c0c130au: goto P_0c0c130a;
case 0x0c0c130cu: goto P_0c0c130c;
case 0x0c0c130eu: goto P_0c0c130e;
case 0x0c0c1310u: goto P_0c0c1310;
case 0x0c0c1312u: goto P_0c0c1312;
case 0x0c0c1314u: goto P_0c0c1314;
case 0x0c0c1316u: goto P_0c0c1316;
case 0x0c0c1318u: goto P_0c0c1318;
case 0x0c0c131au: goto P_0c0c131a;
case 0x0c0c131cu: goto P_0c0c131c;
case 0x0c0c131eu: goto P_0c0c131e;
case 0x0c0c1320u: goto P_0c0c1320;
case 0x0c0c1322u: goto P_0c0c1322;
case 0x0c0c1324u: goto P_0c0c1324;
case 0x0c0c1326u: goto P_0c0c1326;
case 0x0c0c1328u: goto P_0c0c1328;
case 0x0c0c132au: goto P_0c0c132a;
case 0x0c0c132cu: goto P_0c0c132c;
case 0x0c0c132eu: goto P_0c0c132e;
case 0x0c0c1330u: goto P_0c0c1330;
case 0x0c0c1332u: goto P_0c0c1332;
case 0x0c0c1334u: goto P_0c0c1334;
case 0x0c0c1336u: goto P_0c0c1336;
case 0x0c0c1338u: goto P_0c0c1338;
case 0x0c0c133au: goto P_0c0c133a;
case 0x0c0c133cu: goto P_0c0c133c;
case 0x0c0c133eu: goto P_0c0c133e;
case 0x0c0c1340u: goto P_0c0c1340;
case 0x0c0c1342u: goto P_0c0c1342;
case 0x0c0c1344u: goto P_0c0c1344;
case 0x0c0c1346u: goto P_0c0c1346;
case 0x0c0c1348u: goto P_0c0c1348;
case 0x0c0c134au: goto P_0c0c134a;
case 0x0c0c134cu: goto P_0c0c134c;
case 0x0c0c134eu: goto P_0c0c134e;
case 0x0c0c1350u: goto P_0c0c1350;
case 0x0c0c1352u: goto P_0c0c1352;
case 0x0c0c1354u: goto P_0c0c1354;
case 0x0c0c1356u: goto P_0c0c1356;
case 0x0c0c1358u: goto P_0c0c1358;
case 0x0c0c135au: goto P_0c0c135a;
case 0x0c0c135cu: goto P_0c0c135c;
case 0x0c0c135eu: goto P_0c0c135e;
case 0x0c0c1360u: goto P_0c0c1360;
case 0x0c0c1362u: goto P_0c0c1362;
case 0x0c0c1364u: goto P_0c0c1364;
case 0x0c0c1366u: goto P_0c0c1366;
case 0x0c0c1368u: goto P_0c0c1368;
case 0x0c0c136au: goto P_0c0c136a;
case 0x0c0c136cu: goto P_0c0c136c;
case 0x0c0c136eu: goto P_0c0c136e;
case 0x0c0c1370u: goto P_0c0c1370;
case 0x0c0c1372u: goto P_0c0c1372;
case 0x0c0c1374u: goto P_0c0c1374;
case 0x0c0c1376u: goto P_0c0c1376;
case 0x0c0c1378u: goto P_0c0c1378;
case 0x0c0c137au: goto P_0c0c137a;
case 0x0c0c137cu: goto P_0c0c137c;
case 0x0c0c137eu: goto P_0c0c137e;
case 0x0c0c1380u: goto P_0c0c1380;
case 0x0c0c1382u: goto P_0c0c1382;
case 0x0c0c1384u: goto P_0c0c1384;
case 0x0c0c1386u: goto P_0c0c1386;
case 0x0c0c1388u: goto P_0c0c1388;
case 0x0c0c138au: goto P_0c0c138a;
case 0x0c0c138cu: goto P_0c0c138c;
case 0x0c0c138eu: goto P_0c0c138e;
case 0x0c0c1390u: goto P_0c0c1390;
case 0x0c0c1392u: goto P_0c0c1392;
case 0x0c0c1394u: goto P_0c0c1394;
case 0x0c0c1396u: goto P_0c0c1396;
case 0x0c0c1398u: goto P_0c0c1398;
case 0x0c0c139au: goto P_0c0c139a;
case 0x0c0c139cu: goto P_0c0c139c;
case 0x0c0c139eu: goto P_0c0c139e;
case 0x0c0c13a0u: goto P_0c0c13a0;
case 0x0c0c13a2u: goto P_0c0c13a2;
case 0x0c0c13a4u: goto P_0c0c13a4;
case 0x0c0c13a6u: goto P_0c0c13a6;
case 0x0c0c13a8u: goto P_0c0c13a8;
case 0x0c0c13aau: goto P_0c0c13aa;
case 0x0c0c13acu: goto P_0c0c13ac;
case 0x0c0c13aeu: goto P_0c0c13ae;
case 0x0c0c13b0u: goto P_0c0c13b0;
case 0x0c0c13b2u: goto P_0c0c13b2;
case 0x0c0c13b4u: goto P_0c0c13b4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07b398: /* original c748, guest PC 0x0c07b398 */
if(!s->budget--) { s->failed_pc=0x0c07b398u; return 0; }
r[0]=code_base|0x0007b4bcu;
goto P_0c07b39a;
P_0c07b39a: /* original f24c, guest PC 0x0c07b39a */
if(!s->budget--) { s->failed_pc=0x0c07b39au; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c07b39c;
P_0c07b39c: /* original f308, guest PC 0x0c07b39c */
if(!s->budget--) { s->failed_pc=0x0c07b39cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07b39e;
P_0c07b39e: /* original e018, guest PC 0x0c07b39e */
if(!s->budget--) { s->failed_pc=0x0c07b39eu; return 0; }
r[0]=0x00000018u;
goto P_0c07b3a0;
P_0c07b3a0: /* original f460, guest PC 0x0c07b3a0 */
if(!s->budget--) { s->failed_pc=0x0c07b3a0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'+');
goto P_0c07b3a2;
P_0c07b3a2: /* original f230, guest PC 0x0c07b3a2 */
if(!s->budget--) { s->failed_pc=0x0c07b3a2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c07b3a4;
P_0c07b3a4: /* original f282, guest PC 0x0c07b3a4 */
if(!s->budget--) { s->failed_pc=0x0c07b3a4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[8],r[18],'*');
goto P_0c07b3a6;
P_0c07b3a6: /* original f427, guest PC 0x0c07b3a6 */
if(!s->budget--) { s->failed_pc=0x0c07b3a6u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c07b3a8;
P_0c07b3a8: /* original c745, guest PC 0x0c07b3a8 */
if(!s->budget--) { s->failed_pc=0x0c07b3a8u; return 0; }
r[0]=code_base|0x0007b4c0u;
goto P_0c07b3aa;
P_0c07b3aa: /* original f208, guest PC 0x0c07b3aa */
if(!s->budget--) { s->failed_pc=0x0c07b3aau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c07b3ac;
P_0c07b3ac: /* original e01c, guest PC 0x0c07b3ac */
if(!s->budget--) { s->failed_pc=0x0c07b3acu; return 0; }
r[0]=0x0000001cu;
goto P_0c07b3ae;
P_0c07b3ae: /* original f15c, guest PC 0x0c07b3ae */
if(!s->budget--) { s->failed_pc=0x0c07b3aeu; return 0; }
vf3_matrix_move(s,1,5);
goto P_0c07b3b0;
P_0c07b3b0: /* original f570, guest PC 0x0c07b3b0 */
if(!s->budget--) { s->failed_pc=0x0c07b3b0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'+');
goto P_0c07b3b2;
P_0c07b3b2: /* original f120, guest PC 0x0c07b3b2 */
if(!s->budget--) { s->failed_pc=0x0c07b3b2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'+');
goto P_0c07b3b4;
P_0c07b3b4: /* original f192, guest PC 0x0c07b3b4 */
if(!s->budget--) { s->failed_pc=0x0c07b3b4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c07b3b6;
P_0c07b3b6: /* original f417, guest PC 0x0c07b3b6 */
if(!s->budget--) { s->failed_pc=0x0c07b3b6u; return 0; }
vf3_matrix_store(s,ram,1,r[4]+r[0]);
goto P_0c07b3b8;
P_0c07b3b8: /* original c742, guest PC 0x0c07b3b8 */
if(!s->budget--) { s->failed_pc=0x0c07b3b8u; return 0; }
r[0]=code_base|0x0007b4c4u;
goto P_0c07b3ba;
P_0c07b3ba: /* original f108, guest PC 0x0c07b3ba */
if(!s->budget--) { s->failed_pc=0x0c07b3bau; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c07b3bc;
P_0c07b3bc: /* original e020, guest PC 0x0c07b3bc */
if(!s->budget--) { s->failed_pc=0x0c07b3bcu; return 0; }
r[0]=0x00000020u;
goto P_0c07b3be;
P_0c07b3be: /* original f410, guest PC 0x0c07b3be */
if(!s->budget--) { s->failed_pc=0x0c07b3beu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'+');
goto P_0c07b3c0;
P_0c07b3c0: /* original f482, guest PC 0x0c07b3c0 */
if(!s->budget--) { s->failed_pc=0x0c07b3c0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'*');
goto P_0c07b3c2;
P_0c07b3c2: /* original f447, guest PC 0x0c07b3c2 */
if(!s->budget--) { s->failed_pc=0x0c07b3c2u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c07b3c4;
P_0c07b3c4: /* original c740, guest PC 0x0c07b3c4 */
if(!s->budget--) { s->failed_pc=0x0c07b3c4u; return 0; }
r[0]=code_base|0x0007b4c8u;
goto P_0c07b3c6;
P_0c07b3c6: /* original f308, guest PC 0x0c07b3c6 */
if(!s->budget--) { s->failed_pc=0x0c07b3c6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07b3c8;
P_0c07b3c8: /* original e024, guest PC 0x0c07b3c8 */
if(!s->budget--) { s->failed_pc=0x0c07b3c8u; return 0; }
r[0]=0x00000024u;
goto P_0c07b3ca;
P_0c07b3ca: /* original f530, guest PC 0x0c07b3ca */
if(!s->budget--) { s->failed_pc=0x0c07b3cau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c07b3cc;
P_0c07b3cc: /* original f592, guest PC 0x0c07b3cc */
if(!s->budget--) { s->failed_pc=0x0c07b3ccu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[9],r[18],'*');
goto P_0c07b3ce;
P_0c07b3ce: /* original 000b, guest PC 0x0c07b3ce */
if(!s->budget--) { s->failed_pc=0x0c07b3ceu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,5,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c07b3d0: /* original f457, guest PC 0x0c07b3d0 */
if(!s->budget--) { s->failed_pc=0x0c07b3d0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
if(!vf3_matrix_family(0x0c07b3d2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b3d2u; return 0; } return 1;
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
P_0c0c12f0: /* original 2fe6, guest PC 0x0c0c12f0 */
if(!s->budget--) { s->failed_pc=0x0c0c12f0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c12f2;
P_0c0c12f2: /* original 6353, guest PC 0x0c0c12f2 */
if(!s->budget--) { s->failed_pc=0x0c0c12f2u; return 0; }
r[3]=r[5];
goto P_0c0c12f4;
P_0c0c12f4: /* original 2fc6, guest PC 0x0c0c12f4 */
if(!s->budget--) { s->failed_pc=0x0c0c12f4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c12f6;
P_0c0c12f6: /* original 6c53, guest PC 0x0c0c12f6 */
if(!s->budget--) { s->failed_pc=0x0c0c12f6u; return 0; }
r[12]=r[5];
goto P_0c0c12f8;
P_0c0c12f8: /* original 2fb6, guest PC 0x0c0c12f8 */
if(!s->budget--) { s->failed_pc=0x0c0c12f8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c12fa;
P_0c0c12fa: /* original 6b53, guest PC 0x0c0c12fa */
if(!s->budget--) { s->failed_pc=0x0c0c12fau; return 0; }
r[11]=r[5];
goto P_0c0c12fc;
P_0c0c12fc: /* original 2fa6, guest PC 0x0c0c12fc */
if(!s->budget--) { s->failed_pc=0x0c0c12fcu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c12fe;
P_0c0c12fe: /* original 4c29, guest PC 0x0c0c12fe */
if(!s->budget--) { s->failed_pc=0x0c0c12feu; return 0; }
r[12]>>=16;
goto P_0c0c1300;
P_0c0c1300: /* original 2f96, guest PC 0x0c0c1300 */
if(!s->budget--) { s->failed_pc=0x0c0c1300u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1302;
P_0c0c1302: /* original 6ccc, guest PC 0x0c0c1302 */
if(!s->budget--) { s->failed_pc=0x0c0c1302u; return 0; }
r[12]=r[12]&255u;
goto P_0c0c1304;
P_0c0c1304: /* original 2f86, guest PC 0x0c0c1304 */
if(!s->budget--) { s->failed_pc=0x0c0c1304u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1306;
P_0c0c1306: /* original 655c, guest PC 0x0c0c1306 */
if(!s->budget--) { s->failed_pc=0x0c0c1306u; return 0; }
r[5]=r[5]&255u;
goto P_0c0c1308;
P_0c0c1308: /* original 35cc, guest PC 0x0c0c1308 */
if(!s->budget--) { s->failed_pc=0x0c0c1308u; return 0; }
r[5]+=r[12];
goto P_0c0c130a;
P_0c0c130a: /* original 5743, guest PC 0x0c0c130a */
if(!s->budget--) { s->failed_pc=0x0c0c130au; return 0; }
r[7]=read(ram,r[4]+12,4);
goto P_0c0c130c;
P_0c0c130c: /* original 7ff8, guest PC 0x0c0c130c */
if(!s->budget--) { s->failed_pc=0x0c0c130cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c130e;
P_0c0c130e: /* original 4b29, guest PC 0x0c0c130e */
if(!s->budget--) { s->failed_pc=0x0c0c130eu; return 0; }
r[11]>>=16;
goto P_0c0c1310;
P_0c0c1310: /* original 4319, guest PC 0x0c0c1310 */
if(!s->budget--) { s->failed_pc=0x0c0c1310u; return 0; }
r[3]>>=8;
goto P_0c0c1312;
P_0c0c1312: /* original 4b19, guest PC 0x0c0c1312 */
if(!s->budget--) { s->failed_pc=0x0c0c1312u; return 0; }
r[11]>>=8;
goto P_0c0c1314;
P_0c0c1314: /* original 6bbc, guest PC 0x0c0c1314 */
if(!s->budget--) { s->failed_pc=0x0c0c1314u; return 0; }
r[11]=r[11]&255u;
goto P_0c0c1316;
P_0c0c1316: /* original 633c, guest PC 0x0c0c1316 */
if(!s->budget--) { s->failed_pc=0x0c0c1316u; return 0; }
r[3]=r[3]&255u;
goto P_0c0c1318;
P_0c0c1318: /* original 33bc, guest PC 0x0c0c1318 */
if(!s->budget--) { s->failed_pc=0x0c0c1318u; return 0; }
r[3]+=r[11];
goto P_0c0c131a;
P_0c0c131a: /* original c727, guest PC 0x0c0c131a */
if(!s->budget--) { s->failed_pc=0x0c0c131au; return 0; }
r[0]=code_base|0x000c13b8u;
goto P_0c0c131c;
P_0c0c131c: /* original 1f31, guest PC 0x0c0c131c */
if(!s->budget--) { s->failed_pc=0x0c0c131cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c131e;
P_0c0c131e: /* original 2f52, guest PC 0x0c0c131e */
if(!s->budget--) { s->failed_pc=0x0c0c131eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c1320;
P_0c0c1320: /* original 6563, guest PC 0x0c0c1320 */
if(!s->budget--) { s->failed_pc=0x0c0c1320u; return 0; }
r[5]=r[6];
goto P_0c0c1322;
P_0c0c1322: /* original 4529, guest PC 0x0c0c1322 */
if(!s->budget--) { s->failed_pc=0x0c0c1322u; return 0; }
r[5]>>=16;
goto P_0c0c1324;
P_0c0c1324: /* original 4629, guest PC 0x0c0c1324 */
if(!s->budget--) { s->failed_pc=0x0c0c1324u; return 0; }
r[6]>>=16;
goto P_0c0c1326;
P_0c0c1326: /* original 4519, guest PC 0x0c0c1326 */
if(!s->budget--) { s->failed_pc=0x0c0c1326u; return 0; }
r[5]>>=8;
goto P_0c0c1328;
P_0c0c1328: /* original 666c, guest PC 0x0c0c1328 */
if(!s->budget--) { s->failed_pc=0x0c0c1328u; return 0; }
r[6]=r[6]&255u;
goto P_0c0c132a;
P_0c0c132a: /* original 655c, guest PC 0x0c0c132a */
if(!s->budget--) { s->failed_pc=0x0c0c132au; return 0; }
r[5]=r[5]&255u;
goto P_0c0c132c;
P_0c0c132c: /* original 36c8, guest PC 0x0c0c132c */
if(!s->budget--) { s->failed_pc=0x0c0c132cu; return 0; }
r[6]-=r[12];
goto P_0c0c132e;
P_0c0c132e: /* original 35b8, guest PC 0x0c0c132e */
if(!s->budget--) { s->failed_pc=0x0c0c132eu; return 0; }
r[5]-=r[11];
goto P_0c0c1330;
P_0c0c1330: /* original 455a, guest PC 0x0c0c1330 */
if(!s->budget--) { s->failed_pc=0x0c0c1330u; return 0; }
r[53]=r[5];
goto P_0c0c1332;
P_0c0c1332: /* original ea00, guest PC 0x0c0c1332 */
if(!s->budget--) { s->failed_pc=0x0c0c1332u; return 0; }
r[10]=0x00000000u;
goto P_0c0c1334;
P_0c0c1334: /* original d221, guest PC 0x0c0c1334 */
if(!s->budget--) { s->failed_pc=0x0c0c1334u; return 0; }
r[2]=read(ram,0x0c0c13bcu,4);
goto P_0c0c1336;
P_0c0c1336: /* original e901, guest PC 0x0c0c1336 */
if(!s->budget--) { s->failed_pc=0x0c0c1336u; return 0; }
r[9]=0x00000001u;
goto P_0c0c1338;
P_0c0c1338: /* original d121, guest PC 0x0c0c1338 */
if(!s->budget--) { s->failed_pc=0x0c0c1338u; return 0; }
r[1]=read(ram,0x0c0c13c0u,4);
goto P_0c0c133a;
P_0c0c133a: /* original e878, guest PC 0x0c0c133a */
if(!s->budget--) { s->failed_pc=0x0c0c133au; return 0; }
r[8]=0x00000078u;
goto P_0c0c133c;
P_0c0c133c: /* original f32d, guest PC 0x0c0c133c */
if(!s->budget--) { s->failed_pc=0x0c0c133cu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c133e;
P_0c0c133e: /* original f228, guest PC 0x0c0c133e */
if(!s->budget--) { s->failed_pc=0x0c0c133eu; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
goto P_0c0c1340;
P_0c0c1340: /* original 465a, guest PC 0x0c0c1340 */
if(!s->budget--) { s->failed_pc=0x0c0c1340u; return 0; }
r[53]=r[6];
goto P_0c0c1342;
P_0c0c1342: /* original f118, guest PC 0x0c0c1342 */
if(!s->budget--) { s->failed_pc=0x0c0c1342u; return 0; }
vf3_matrix_load(s,ram,1,r[1]);
goto P_0c0c1344;
P_0c0c1344: /* original f608, guest PC 0x0c0c1344 */
if(!s->budget--) { s->failed_pc=0x0c0c1344u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0c1346;
P_0c0c1346: /* original f322, guest PC 0x0c0c1346 */
if(!s->budget--) { s->failed_pc=0x0c0c1346u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c0c1348;
P_0c0c1348: /* original f53c, guest PC 0x0c0c1348 */
if(!s->budget--) { s->failed_pc=0x0c0c1348u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0c134a;
P_0c0c134a: /* original f32d, guest PC 0x0c0c134a */
if(!s->budget--) { s->failed_pc=0x0c0c134au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c134c;
P_0c0c134c: /* original f562, guest PC 0x0c0c134c */
if(!s->budget--) { s->failed_pc=0x0c0c134cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c0c134e;
P_0c0c134e: /* original f312, guest PC 0x0c0c134e */
if(!s->budget--) { s->failed_pc=0x0c0c134eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'*');
goto P_0c0c1350;
P_0c0c1350: /* original f43c, guest PC 0x0c0c1350 */
if(!s->budget--) { s->failed_pc=0x0c0c1350u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0c1352;
P_0c0c1352: /* original f462, guest PC 0x0c0c1352 */
if(!s->budget--) { s->failed_pc=0x0c0c1352u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0c1354;
P_0c0c1354: /* original 6371, guest PC 0x0c0c1354 */
if(!s->budget--) { s->failed_pc=0x0c0c1354u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[3]=tmp;
goto P_0c0c1356;
P_0c0c1356: /* original 633d, guest PC 0x0c0c1356 */
if(!s->budget--) { s->failed_pc=0x0c0c1356u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c1358;
P_0c0c1358: /* original 2398, guest PC 0x0c0c1358 */
if(!s->budget--) { s->failed_pc=0x0c0c1358u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c0c135a;
P_0c0c135a: /* original 891b, guest PC 0x0c0c135a */
if(!s->budget--) { s->failed_pc=0x0c0c135au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1394; }
goto P_0c0c135c;
P_0c0c135c: /* original 8573, guest PC 0x0c0c135c */
if(!s->budget--) { s->failed_pc=0x0c0c135cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+6,2);
goto P_0c0c135e;
P_0c0c135e: /* original 610d, guest PC 0x0c0c135e */
if(!s->budget--) { s->failed_pc=0x0c0c135eu; return 0; }
r[1]=r[0]&65535u;
goto P_0c0c1360;
P_0c0c1360: /* original 8574, guest PC 0x0c0c1360 */
if(!s->budget--) { s->failed_pc=0x0c0c1360u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+8,2);
goto P_0c0c1362;
P_0c0c1362: /* original 31b3, guest PC 0x0c0c1362 */
if(!s->budget--) { s->failed_pc=0x0c0c1362u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[11])!=0);
goto P_0c0c1364;
P_0c0c1364: /* original 8f16, guest PC 0x0c0c1364 */
if(!s->budget--) { s->failed_pc=0x0c0c1364u; return 0; }
cond=r[17]&1u;
r[14]=r[0]&65535u;
if(!cond) { goto P_0c0c1394; }
goto P_0c0c1368;
P_0c0c1366: /* original 6e0d, guest PC 0x0c0c1366 */
if(!s->budget--) { s->failed_pc=0x0c0c1366u; return 0; }
r[14]=r[0]&65535u;
goto P_0c0c1368;
P_0c0c1368: /* original 52f1, guest PC 0x0c0c1368 */
if(!s->budget--) { s->failed_pc=0x0c0c1368u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0c136a;
P_0c0c136a: /* original 3127, guest PC 0x0c0c136a */
if(!s->budget--) { s->failed_pc=0x0c0c136au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[2])!=0);
goto P_0c0c136c;
P_0c0c136c: /* original 8912, guest PC 0x0c0c136c */
if(!s->budget--) { s->failed_pc=0x0c0c136cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1394; }
goto P_0c0c136e;
P_0c0c136e: /* original 3ec3, guest PC 0x0c0c136e */
if(!s->budget--) { s->failed_pc=0x0c0c136eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[12])!=0);
goto P_0c0c1370;
P_0c0c1370: /* original 8b10, guest PC 0x0c0c1370 */
if(!s->budget--) { s->failed_pc=0x0c0c1370u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1394; }
goto P_0c0c1372;
P_0c0c1372: /* original 63f2, guest PC 0x0c0c1372 */
if(!s->budget--) { s->failed_pc=0x0c0c1372u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c1374;
P_0c0c1374: /* original 3e37, guest PC 0x0c0c1374 */
if(!s->budget--) { s->failed_pc=0x0c0c1374u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[3])!=0);
goto P_0c0c1376;
P_0c0c1376: /* original 890d, guest PC 0x0c0c1376 */
if(!s->budget--) { s->failed_pc=0x0c0c1376u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1394; }
goto P_0c0c1378;
P_0c0c1378: /* original 8573, guest PC 0x0c0c1378 */
if(!s->budget--) { s->failed_pc=0x0c0c1378u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+6,2);
goto P_0c0c137a;
P_0c0c137a: /* original 305c, guest PC 0x0c0c137a */
if(!s->budget--) { s->failed_pc=0x0c0c137au; return 0; }
r[0]+=r[5];
goto P_0c0c137c;
P_0c0c137c: /* original 8173, guest PC 0x0c0c137c */
if(!s->budget--) { s->failed_pc=0x0c0c137cu; return 0; }
write(ram,r[7]+6,r[0],2);
goto P_0c0c137e;
P_0c0c137e: /* original 8574, guest PC 0x0c0c137e */
if(!s->budget--) { s->failed_pc=0x0c0c137eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+8,2);
goto P_0c0c1380;
P_0c0c1380: /* original 306c, guest PC 0x0c0c1380 */
if(!s->budget--) { s->failed_pc=0x0c0c1380u; return 0; }
r[0]+=r[6];
goto P_0c0c1382;
P_0c0c1382: /* original 8174, guest PC 0x0c0c1382 */
if(!s->budget--) { s->failed_pc=0x0c0c1382u; return 0; }
write(ram,r[7]+8,r[0],2);
goto P_0c0c1384;
P_0c0c1384: /* original e014, guest PC 0x0c0c1384 */
if(!s->budget--) { s->failed_pc=0x0c0c1384u; return 0; }
r[0]=0x00000014u;
goto P_0c0c1386;
P_0c0c1386: /* original f376, guest PC 0x0c0c1386 */
if(!s->budget--) { s->failed_pc=0x0c0c1386u; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c0c1388;
P_0c0c1388: /* original f350, guest PC 0x0c0c1388 */
if(!s->budget--) { s->failed_pc=0x0c0c1388u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'+');
goto P_0c0c138a;
P_0c0c138a: /* original f737, guest PC 0x0c0c138a */
if(!s->budget--) { s->failed_pc=0x0c0c138au; return 0; }
vf3_matrix_store(s,ram,3,r[7]+r[0]);
goto P_0c0c138c;
P_0c0c138c: /* original e018, guest PC 0x0c0c138c */
if(!s->budget--) { s->failed_pc=0x0c0c138cu; return 0; }
r[0]=0x00000018u;
goto P_0c0c138e;
P_0c0c138e: /* original f276, guest PC 0x0c0c138e */
if(!s->budget--) { s->failed_pc=0x0c0c138eu; return 0; }
vf3_matrix_load(s,ram,2,r[7]+r[0]);
goto P_0c0c1390;
P_0c0c1390: /* original f240, guest PC 0x0c0c1390 */
if(!s->budget--) { s->failed_pc=0x0c0c1390u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'+');
goto P_0c0c1392;
P_0c0c1392: /* original f727, guest PC 0x0c0c1392 */
if(!s->budget--) { s->failed_pc=0x0c0c1392u; return 0; }
vf3_matrix_store(s,ram,2,r[7]+r[0]);
goto P_0c0c1394;
P_0c0c1394: /* original 7a01, guest PC 0x0c0c1394 */
if(!s->budget--) { s->failed_pc=0x0c0c1394u; return 0; }
r[10]+=0x00000001u;
goto P_0c0c1396;
P_0c0c1396: /* original 3a82, guest PC 0x0c0c1396 */
if(!s->budget--) { s->failed_pc=0x0c0c1396u; return 0; }
r[17]=(r[17]&~1u)|((r[10]>=r[8])!=0);
goto P_0c0c1398;
P_0c0c1398: /* original 8fdc, guest PC 0x0c0c1398 */
if(!s->budget--) { s->failed_pc=0x0c0c1398u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000044u;
if(!cond) { goto P_0c0c1354; }
goto P_0c0c139c;
P_0c0c139a: /* original 7744, guest PC 0x0c0c139a */
if(!s->budget--) { s->failed_pc=0x0c0c139au; return 0; }
r[7]+=0x00000044u;
goto P_0c0c139c;
P_0c0c139c: /* original 7f08, guest PC 0x0c0c139c */
if(!s->budget--) { s->failed_pc=0x0c0c139cu; return 0; }
r[15]+=0x00000008u;
goto P_0c0c139e;
P_0c0c139e: /* original e022, guest PC 0x0c0c139e */
if(!s->budget--) { s->failed_pc=0x0c0c139eu; return 0; }
r[0]=0x00000022u;
goto P_0c0c13a0;
P_0c0c13a0: /* original 024d, guest PC 0x0c0c13a0 */
if(!s->budget--) { s->failed_pc=0x0c0c13a0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c13a2;
P_0c0c13a2: /* original e301, guest PC 0x0c0c13a2 */
if(!s->budget--) { s->failed_pc=0x0c0c13a2u; return 0; }
r[3]=0x00000001u;
goto P_0c0c13a4;
P_0c0c13a4: /* original 223b, guest PC 0x0c0c13a4 */
if(!s->budget--) { s->failed_pc=0x0c0c13a4u; return 0; }
r[2]|=r[3];
goto P_0c0c13a6;
P_0c0c13a6: /* original 0425, guest PC 0x0c0c13a6 */
if(!s->budget--) { s->failed_pc=0x0c0c13a6u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0c13a8;
P_0c0c13a8: /* original 68f6, guest PC 0x0c0c13a8 */
if(!s->budget--) { s->failed_pc=0x0c0c13a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c13aa;
P_0c0c13aa: /* original 69f6, guest PC 0x0c0c13aa */
if(!s->budget--) { s->failed_pc=0x0c0c13aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c13ac;
P_0c0c13ac: /* original 6af6, guest PC 0x0c0c13ac */
if(!s->budget--) { s->failed_pc=0x0c0c13acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c13ae;
P_0c0c13ae: /* original 6bf6, guest PC 0x0c0c13ae */
if(!s->budget--) { s->failed_pc=0x0c0c13aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c13b0;
P_0c0c13b0: /* original 6cf6, guest PC 0x0c0c13b0 */
if(!s->budget--) { s->failed_pc=0x0c0c13b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c13b2;
P_0c0c13b2: /* original 000b, guest PC 0x0c0c13b2 */
if(!s->budget--) { s->failed_pc=0x0c0c13b2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c13b4: /* original 6ef6, guest PC 0x0c0c13b4 */
if(!s->budget--) { s->failed_pc=0x0c0c13b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c13b6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c13b6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
