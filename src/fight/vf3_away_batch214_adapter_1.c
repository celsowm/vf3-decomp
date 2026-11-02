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
int vf3_away_batch214_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0b12acu: goto P_0c0b12ac;
case 0x0c0b12aeu: goto P_0c0b12ae;
case 0x0c0b12b0u: goto P_0c0b12b0;
case 0x0c0b12d4u: goto P_0c0b12d4;
case 0x0c0b12d6u: goto P_0c0b12d6;
case 0x0c0b12d8u: goto P_0c0b12d8;
case 0x0c0b12dau: goto P_0c0b12da;
case 0x0c0b12dcu: goto P_0c0b12dc;
case 0x0c0b12deu: goto P_0c0b12de;
case 0x0c0b12e0u: goto P_0c0b12e0;
case 0x0c0b12e2u: goto P_0c0b12e2;
case 0x0c0b12e4u: goto P_0c0b12e4;
case 0x0c0b12e6u: goto P_0c0b12e6;
case 0x0c0b12e8u: goto P_0c0b12e8;
case 0x0c0b12eau: goto P_0c0b12ea;
case 0x0c0b12ecu: goto P_0c0b12ec;
case 0x0c0b12eeu: goto P_0c0b12ee;
case 0x0c0b12f0u: goto P_0c0b12f0;
case 0x0c0b12f2u: goto P_0c0b12f2;
case 0x0c0b12f4u: goto P_0c0b12f4;
case 0x0c0b12f6u: goto P_0c0b12f6;
case 0x0c0b12f8u: goto P_0c0b12f8;
case 0x0c0b12fau: goto P_0c0b12fa;
case 0x0c0b12fcu: goto P_0c0b12fc;
case 0x0c0b12feu: goto P_0c0b12fe;
case 0x0c0b1300u: goto P_0c0b1300;
case 0x0c0b1302u: goto P_0c0b1302;
case 0x0c0b1304u: goto P_0c0b1304;
case 0x0c0b1306u: goto P_0c0b1306;
case 0x0c0b1308u: goto P_0c0b1308;
case 0x0c0b130au: goto P_0c0b130a;
case 0x0c0b130cu: goto P_0c0b130c;
case 0x0c0b130eu: goto P_0c0b130e;
case 0x0c0b1310u: goto P_0c0b1310;
case 0x0c0b1312u: goto P_0c0b1312;
case 0x0c0b1314u: goto P_0c0b1314;
case 0x0c0b1316u: goto P_0c0b1316;
case 0x0c0b1318u: goto P_0c0b1318;
case 0x0c0b131au: goto P_0c0b131a;
case 0x0c0b131cu: goto P_0c0b131c;
case 0x0c0b131eu: goto P_0c0b131e;
case 0x0c0b1320u: goto P_0c0b1320;
case 0x0c0b1322u: goto P_0c0b1322;
case 0x0c0b1324u: goto P_0c0b1324;
case 0x0c0b1326u: goto P_0c0b1326;
case 0x0c0b1328u: goto P_0c0b1328;
case 0x0c0b132au: goto P_0c0b132a;
case 0x0c0b132cu: goto P_0c0b132c;
case 0x0c0b132eu: goto P_0c0b132e;
case 0x0c0b1330u: goto P_0c0b1330;
case 0x0c0b1332u: goto P_0c0b1332;
case 0x0c0b1334u: goto P_0c0b1334;
case 0x0c0b1336u: goto P_0c0b1336;
case 0x0c0c66b8u: goto P_0c0c66b8;
case 0x0c0c66bau: goto P_0c0c66ba;
case 0x0c0c66d8u: goto P_0c0c66d8;
case 0x0c0c66dau: goto P_0c0c66da;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0b12ac: /* original 9005, guest PC 0x0c0b12ac */
if(!s->budget--) { s->failed_pc=0x0c0b12acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b12bau,2);
goto P_0c0b12ae;
P_0c0b12ae: /* original a011, guest PC 0x0c0b12ae */
if(!s->budget--) { s->failed_pc=0x0c0b12aeu; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c0b12d4;
P_0c0b12b0: /* original 0465, guest PC 0x0c0b12b0 */
if(!s->budget--) { s->failed_pc=0x0c0b12b0u; return 0; }
write(ram,r[4]+r[0],r[6],2);
if(!vf3_matrix_family(0x0c0b12b2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b12b2u; return 0; } return 1;
P_0c0b12d4: /* original e046, guest PC 0x0c0b12d4 */
if(!s->budget--) { s->failed_pc=0x0c0b12d4u; return 0; }
r[0]=0x00000046u;
goto P_0c0b12d6;
P_0c0b12d6: /* original 2fe6, guest PC 0x0c0b12d6 */
if(!s->budget--) { s->failed_pc=0x0c0b12d6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b12d8;
P_0c0b12d8: /* original d31f, guest PC 0x0c0b12d8 */
if(!s->budget--) { s->failed_pc=0x0c0b12d8u; return 0; }
r[3]=read(ram,0x0c0b1358u,4);
goto P_0c0b12da;
P_0c0b12da: /* original 7ffc, guest PC 0x0c0b12da */
if(!s->budget--) { s->failed_pc=0x0c0b12dau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0b12dc;
P_0c0b12dc: /* original 2f32, guest PC 0x0c0b12dc */
if(!s->budget--) { s->failed_pc=0x0c0b12dcu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0b12de;
P_0c0b12de: /* original 074d, guest PC 0x0c0b12de */
if(!s->budget--) { s->failed_pc=0x0c0b12deu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0b12e0;
P_0c0b12e0: /* original de1e, guest PC 0x0c0b12e0 */
if(!s->budget--) { s->failed_pc=0x0c0b12e0u; return 0; }
r[14]=read(ram,0x0c0b135cu,4);
goto P_0c0b12e2;
P_0c0b12e2: /* original 677d, guest PC 0x0c0b12e2 */
if(!s->budget--) { s->failed_pc=0x0c0b12e2u; return 0; }
r[7]=r[7]&65535u;
goto P_0c0b12e4;
P_0c0b12e4: /* original 4715, guest PC 0x0c0b12e4 */
if(!s->budget--) { s->failed_pc=0x0c0b12e4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>0)!=0);
goto P_0c0b12e6;
P_0c0b12e6: /* original 8b0b, guest PC 0x0c0b12e6 */
if(!s->budget--) { s->failed_pc=0x0c0b12e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1300; }
goto P_0c0b12e8;
P_0c0b12e8: /* original 9032, guest PC 0x0c0b12e8 */
if(!s->budget--) { s->failed_pc=0x0c0b12e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1350u,2);
goto P_0c0b12ea;
P_0c0b12ea: /* original 4615, guest PC 0x0c0b12ea */
if(!s->budget--) { s->failed_pc=0x0c0b12eau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c0b12ec;
P_0c0b12ec: /* original 8f08, guest PC 0x0c0b12ec */
if(!s->budget--) { s->failed_pc=0x0c0b12ecu; return 0; }
cond=r[17]&1u;
write(ram,r[5]+r[0],r[6],2);
if(!cond) { goto P_0c0b1300; }
goto P_0c0b12f0;
P_0c0b12ee: /* original 0565, guest PC 0x0c0b12ee */
if(!s->budget--) { s->failed_pc=0x0c0b12eeu; return 0; }
write(ram,r[5]+r[0],r[6],2);
goto P_0c0b12f0;
P_0c0b12f0: /* original e061, guest PC 0x0c0b12f0 */
if(!s->budget--) { s->failed_pc=0x0c0b12f0u; return 0; }
r[0]=0x00000061u;
goto P_0c0b12f2;
P_0c0b12f2: /* original 004c, guest PC 0x0c0b12f2 */
if(!s->budget--) { s->failed_pc=0x0c0b12f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0b12f4;
P_0c0b12f4: /* original 600c, guest PC 0x0c0b12f4 */
if(!s->budget--) { s->failed_pc=0x0c0b12f4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0b12f6;
P_0c0b12f6: /* original 8809, guest PC 0x0c0b12f6 */
if(!s->budget--) { s->failed_pc=0x0c0b12f6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0b12f8;
P_0c0b12f8: /* original 8b02, guest PC 0x0c0b12f8 */
if(!s->budget--) { s->failed_pc=0x0c0b12f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1300; }
goto P_0c0b12fa;
P_0c0b12fa: /* original 902a, guest PC 0x0c0b12fa */
if(!s->budget--) { s->failed_pc=0x0c0b12fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1352u,2);
goto P_0c0b12fc;
P_0c0b12fc: /* original e320, guest PC 0x0c0b12fc */
if(!s->budget--) { s->failed_pc=0x0c0b12fcu; return 0; }
r[3]=0x00000020u;
goto P_0c0b12fe;
P_0c0b12fe: /* original 0e34, guest PC 0x0c0b12fe */
if(!s->budget--) { s->failed_pc=0x0c0b12feu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0b1300;
P_0c0b1300: /* original 65f2, guest PC 0x0c0b1300 */
if(!s->budget--) { s->failed_pc=0x0c0b1300u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b1302;
P_0c0b1302: /* original 9327, guest PC 0x0c0b1302 */
if(!s->budget--) { s->failed_pc=0x0c0b1302u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1354u,2);
goto P_0c0b1304;
P_0c0b1304: /* original 6552, guest PC 0x0c0b1304 */
if(!s->budget--) { s->failed_pc=0x0c0b1304u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b1306;
P_0c0b1306: /* original 2358, guest PC 0x0c0b1306 */
if(!s->budget--) { s->failed_pc=0x0c0b1306u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0b1308;
P_0c0b1308: /* original 8b11, guest PC 0x0c0b1308 */
if(!s->budget--) { s->failed_pc=0x0c0b1308u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b132e; }
goto P_0c0b130a;
P_0c0b130a: /* original d215, guest PC 0x0c0b130a */
if(!s->budget--) { s->failed_pc=0x0c0b130au; return 0; }
r[2]=read(ram,0x0c0b1360u,4);
goto P_0c0b130c;
P_0c0b130c: /* original 2258, guest PC 0x0c0b130c */
if(!s->budget--) { s->failed_pc=0x0c0b130cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0b130e;
P_0c0b130e: /* original 8b10, guest PC 0x0c0b130e */
if(!s->budget--) { s->failed_pc=0x0c0b130eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1332; }
goto P_0c0b1310;
P_0c0b1310: /* original d314, guest PC 0x0c0b1310 */
if(!s->budget--) { s->failed_pc=0x0c0b1310u; return 0; }
r[3]=read(ram,0x0c0b1364u,4);
goto P_0c0b1312;
P_0c0b1312: /* original 2538, guest PC 0x0c0b1312 */
if(!s->budget--) { s->failed_pc=0x0c0b1312u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0b1314;
P_0c0b1314: /* original 8b0d, guest PC 0x0c0b1314 */
if(!s->budget--) { s->failed_pc=0x0c0b1314u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1332; }
goto P_0c0b1316;
P_0c0b1316: /* original 52e2, guest PC 0x0c0b1316 */
if(!s->budget--) { s->failed_pc=0x0c0b1316u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c0b1318;
P_0c0b1318: /* original d313, guest PC 0x0c0b1318 */
if(!s->budget--) { s->failed_pc=0x0c0b1318u; return 0; }
r[3]=read(ram,0x0c0b1368u,4);
goto P_0c0b131a;
P_0c0b131a: /* original 2238, guest PC 0x0c0b131a */
if(!s->budget--) { s->failed_pc=0x0c0b131au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0b131c;
P_0c0b131c: /* original 8b00, guest PC 0x0c0b131c */
if(!s->budget--) { s->failed_pc=0x0c0b131cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1320; }
goto P_0c0b131e;
P_0c0b131e: /* original 3768, guest PC 0x0c0b131e */
if(!s->budget--) { s->failed_pc=0x0c0b131eu; return 0; }
r[7]-=r[6];
goto P_0c0b1320;
P_0c0b1320: /* original 4715, guest PC 0x0c0b1320 */
if(!s->budget--) { s->failed_pc=0x0c0b1320u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>0)!=0);
goto P_0c0b1322;
P_0c0b1322: /* original 8904, guest PC 0x0c0b1322 */
if(!s->budget--) { s->failed_pc=0x0c0b1322u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b132e; }
goto P_0c0b1324;
P_0c0b1324: /* original 6242, guest PC 0x0c0b1324 */
if(!s->budget--) { s->failed_pc=0x0c0b1324u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0b1326;
P_0c0b1326: /* original e700, guest PC 0x0c0b1326 */
if(!s->budget--) { s->failed_pc=0x0c0b1326u; return 0; }
r[7]=0x00000000u;
goto P_0c0b1328;
P_0c0b1328: /* original d310, guest PC 0x0c0b1328 */
if(!s->budget--) { s->failed_pc=0x0c0b1328u; return 0; }
r[3]=read(ram,0x0c0b136cu,4);
goto P_0c0b132a;
P_0c0b132a: /* original 223b, guest PC 0x0c0b132a */
if(!s->budget--) { s->failed_pc=0x0c0b132au; return 0; }
r[2]|=r[3];
goto P_0c0b132c;
P_0c0b132c: /* original 2422, guest PC 0x0c0b132c */
if(!s->budget--) { s->failed_pc=0x0c0b132cu; return 0; }
write(ram,r[4],r[2],4);
goto P_0c0b132e;
P_0c0b132e: /* original e046, guest PC 0x0c0b132e */
if(!s->budget--) { s->failed_pc=0x0c0b132eu; return 0; }
r[0]=0x00000046u;
goto P_0c0b1330;
P_0c0b1330: /* original 0475, guest PC 0x0c0b1330 */
if(!s->budget--) { s->failed_pc=0x0c0b1330u; return 0; }
write(ram,r[4]+r[0],r[7],2);
goto P_0c0b1332;
P_0c0b1332: /* original 7f04, guest PC 0x0c0b1332 */
if(!s->budget--) { s->failed_pc=0x0c0b1332u; return 0; }
r[15]+=0x00000004u;
goto P_0c0b1334;
P_0c0b1334: /* original 000b, guest PC 0x0c0b1334 */
if(!s->budget--) { s->failed_pc=0x0c0b1334u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b1336: /* original 6ef6, guest PC 0x0c0b1336 */
if(!s->budget--) { s->failed_pc=0x0c0b1336u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b1338u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b1338u; return 0; } return 1;
P_0c0c66b8: /* original 000b, guest PC 0x0c0c66b8 */
if(!s->budget--) { s->failed_pc=0x0c0c66b8u; return 0; }
target=r[16];
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c66ba: /* original 6040, guest PC 0x0c0c66ba */
if(!s->budget--) { s->failed_pc=0x0c0c66bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
if(!vf3_matrix_family(0x0c0c66bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66bcu; return 0; } return 1;
P_0c0c66d8: /* original 000b, guest PC 0x0c0c66d8 */
if(!s->budget--) { s->failed_pc=0x0c0c66d8u; return 0; }
target=r[16];
write(ram,r[4],r[5],4);
s->pc=target; return ram->oob==0;
P_0c0c66da: /* original 2452, guest PC 0x0c0c66da */
if(!s->budget--) { s->failed_pc=0x0c0c66dau; return 0; }
write(ram,r[4],r[5],4);
if(!vf3_matrix_family(0x0c0c66dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66dcu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
