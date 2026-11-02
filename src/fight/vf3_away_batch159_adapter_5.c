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
int vf3_away_batch159_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c1192u: goto P_0c0c1192;
case 0x0c0c1194u: goto P_0c0c1194;
case 0x0c0c1196u: goto P_0c0c1196;
case 0x0c0c1198u: goto P_0c0c1198;
case 0x0c0c119au: goto P_0c0c119a;
case 0x0c0c119cu: goto P_0c0c119c;
case 0x0c0c119eu: goto P_0c0c119e;
case 0x0c0c11a0u: goto P_0c0c11a0;
case 0x0c0c11a2u: goto P_0c0c11a2;
case 0x0c0c11a4u: goto P_0c0c11a4;
case 0x0c0c11a6u: goto P_0c0c11a6;
case 0x0c0c11a8u: goto P_0c0c11a8;
case 0x0c0c11aau: goto P_0c0c11aa;
case 0x0c0c11acu: goto P_0c0c11ac;
case 0x0c0c11aeu: goto P_0c0c11ae;
case 0x0c0c11b0u: goto P_0c0c11b0;
case 0x0c0c11b2u: goto P_0c0c11b2;
case 0x0c0c11b4u: goto P_0c0c11b4;
case 0x0c0c11b6u: goto P_0c0c11b6;
case 0x0c0c11b8u: goto P_0c0c11b8;
case 0x0c0c11bau: goto P_0c0c11ba;
case 0x0c0c11bcu: goto P_0c0c11bc;
case 0x0c0c11beu: goto P_0c0c11be;
case 0x0c0c11c0u: goto P_0c0c11c0;
case 0x0c0c11c2u: goto P_0c0c11c2;
case 0x0c0c11c4u: goto P_0c0c11c4;
case 0x0c0c11c6u: goto P_0c0c11c6;
case 0x0c0c11c8u: goto P_0c0c11c8;
case 0x0c0c11cau: goto P_0c0c11ca;
case 0x0c0c11ccu: goto P_0c0c11cc;
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
P_0c0c1192: /* original 2fe6, guest PC 0x0c0c1192 */
if(!s->budget--) { s->failed_pc=0x0c0c1192u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1194;
P_0c0c1194: /* original d314, guest PC 0x0c0c1194 */
if(!s->budget--) { s->failed_pc=0x0c0c1194u; return 0; }
r[3]=read(ram,0x0c0c11e8u,4);
goto P_0c0c1196;
P_0c0c1196: /* original 7ffc, guest PC 0x0c0c1196 */
if(!s->budget--) { s->failed_pc=0x0c0c1196u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c1198;
P_0c0c1198: /* original d114, guest PC 0x0c0c1198 */
if(!s->budget--) { s->failed_pc=0x0c0c1198u; return 0; }
r[1]=read(ram,0x0c0c11ecu,4);
goto P_0c0c119a;
P_0c0c119a: /* original 6e32, guest PC 0x0c0c119a */
if(!s->budget--) { s->failed_pc=0x0c0c119au; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c0c119c;
P_0c0c119c: /* original 6210, guest PC 0x0c0c119c */
if(!s->budget--) { s->failed_pc=0x0c0c119cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[2]=tmp;
goto P_0c0c119e;
P_0c0c119e: /* original 622c, guest PC 0x0c0c119e */
if(!s->budget--) { s->failed_pc=0x0c0c119eu; return 0; }
r[2]=r[2]&255u;
goto P_0c0c11a0;
P_0c0c11a0: /* original 2f22, guest PC 0x0c0c11a0 */
if(!s->budget--) { s->failed_pc=0x0c0c11a0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c11a2;
P_0c0c11a2: /* original d313, guest PC 0x0c0c11a2 */
if(!s->budget--) { s->failed_pc=0x0c0c11a2u; return 0; }
r[3]=read(ram,0x0c0c11f0u,4);
goto P_0c0c11a4;
P_0c0c11a4: /* original 2e39, guest PC 0x0c0c11a4 */
if(!s->budget--) { s->failed_pc=0x0c0c11a4u; return 0; }
r[14]&=r[3];
goto P_0c0c11a6;
P_0c0c11a6: /* original 2ee8, guest PC 0x0c0c11a6 */
if(!s->budget--) { s->failed_pc=0x0c0c11a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c11a8;
P_0c0c11a8: /* original 8b0e, guest PC 0x0c0c11a8 */
if(!s->budget--) { s->failed_pc=0x0c0c11a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c11c8; }
goto P_0c0c11aa;
P_0c0c11aa: /* original 60f2, guest PC 0x0c0c11aa */
if(!s->budget--) { s->failed_pc=0x0c0c11aau; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0c11ac;
P_0c0c11ac: /* original 8801, guest PC 0x0c0c11ac */
if(!s->budget--) { s->failed_pc=0x0c0c11acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c11ae;
P_0c0c11ae: /* original 890b, guest PC 0x0c0c11ae */
if(!s->budget--) { s->failed_pc=0x0c0c11aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c11c8; }
goto P_0c0c11b0;
P_0c0c11b0: /* original ee3f, guest PC 0x0c0c11b0 */
if(!s->budget--) { s->failed_pc=0x0c0c11b0u; return 0; }
r[14]=0x0000003fu;
goto P_0c0c11b2;
P_0c0c11b2: /* original 26e9, guest PC 0x0c0c11b2 */
if(!s->budget--) { s->failed_pc=0x0c0c11b2u; return 0; }
r[6]&=r[14];
goto P_0c0c11b4;
P_0c0c11b4: /* original 4618, guest PC 0x0c0c11b4 */
if(!s->budget--) { s->failed_pc=0x0c0c11b4u; return 0; }
r[6]<<=8;
goto P_0c0c11b6;
P_0c0c11b6: /* original 25e9, guest PC 0x0c0c11b6 */
if(!s->budget--) { s->failed_pc=0x0c0c11b6u; return 0; }
r[5]&=r[14];
goto P_0c0c11b8;
P_0c0c11b8: /* original 27e9, guest PC 0x0c0c11b8 */
if(!s->budget--) { s->failed_pc=0x0c0c11b8u; return 0; }
r[7]&=r[14];
goto P_0c0c11ba;
P_0c0c11ba: /* original 4728, guest PC 0x0c0c11ba */
if(!s->budget--) { s->failed_pc=0x0c0c11bau; return 0; }
r[7]<<=16;
goto P_0c0c11bc;
P_0c0c11bc: /* original 4508, guest PC 0x0c0c11bc */
if(!s->budget--) { s->failed_pc=0x0c0c11bcu; return 0; }
r[5]<<=2;
goto P_0c0c11be;
P_0c0c11be: /* original 4608, guest PC 0x0c0c11be */
if(!s->budget--) { s->failed_pc=0x0c0c11beu; return 0; }
r[6]<<=2;
goto P_0c0c11c0;
P_0c0c11c0: /* original 4708, guest PC 0x0c0c11c0 */
if(!s->budget--) { s->failed_pc=0x0c0c11c0u; return 0; }
r[7]<<=2;
goto P_0c0c11c2;
P_0c0c11c2: /* original 256b, guest PC 0x0c0c11c2 */
if(!s->budget--) { s->failed_pc=0x0c0c11c2u; return 0; }
r[5]|=r[6];
goto P_0c0c11c4;
P_0c0c11c4: /* original 257b, guest PC 0x0c0c11c4 */
if(!s->budget--) { s->failed_pc=0x0c0c11c4u; return 0; }
r[5]|=r[7];
goto P_0c0c11c6;
P_0c0c11c6: /* original 2452, guest PC 0x0c0c11c6 */
if(!s->budget--) { s->failed_pc=0x0c0c11c6u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c0c11c8;
P_0c0c11c8: /* original 7f04, guest PC 0x0c0c11c8 */
if(!s->budget--) { s->failed_pc=0x0c0c11c8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c11ca;
P_0c0c11ca: /* original 000b, guest PC 0x0c0c11ca */
if(!s->budget--) { s->failed_pc=0x0c0c11cau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c11cc: /* original 6ef6, guest PC 0x0c0c11cc */
if(!s->budget--) { s->failed_pc=0x0c0c11ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c11ceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c11ceu; return 0; } return 1;
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
