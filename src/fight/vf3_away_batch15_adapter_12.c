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
int vf3_away_batch15_adapter_12(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08d158u: goto P_0c08d158;
case 0x0c08d15au: goto P_0c08d15a;
case 0x0c08d15cu: goto P_0c08d15c;
case 0x0c08d15eu: goto P_0c08d15e;
case 0x0c08d160u: goto P_0c08d160;
case 0x0c08d162u: goto P_0c08d162;
case 0x0c08d164u: goto P_0c08d164;
case 0x0c08d166u: goto P_0c08d166;
case 0x0c08d168u: goto P_0c08d168;
case 0x0c08d16au: goto P_0c08d16a;
case 0x0c08d16cu: goto P_0c08d16c;
case 0x0c08d16eu: goto P_0c08d16e;
case 0x0c08d170u: goto P_0c08d170;
case 0x0c08d172u: goto P_0c08d172;
case 0x0c08d174u: goto P_0c08d174;
case 0x0c08d176u: goto P_0c08d176;
case 0x0c08d178u: goto P_0c08d178;
case 0x0c08d17au: goto P_0c08d17a;
case 0x0c08d17cu: goto P_0c08d17c;
case 0x0c08d17eu: goto P_0c08d17e;
case 0x0c08d180u: goto P_0c08d180;
case 0x0c08d182u: goto P_0c08d182;
case 0x0c08d184u: goto P_0c08d184;
case 0x0c08d186u: goto P_0c08d186;
case 0x0c08d188u: goto P_0c08d188;
case 0x0c08d18au: goto P_0c08d18a;
case 0x0c08d18cu: goto P_0c08d18c;
case 0x0c08d18eu: goto P_0c08d18e;
case 0x0c08d190u: goto P_0c08d190;
case 0x0c09553cu: goto P_0c09553c;
case 0x0c09553eu: goto P_0c09553e;
case 0x0c095540u: goto P_0c095540;
case 0x0c095542u: goto P_0c095542;
case 0x0c095544u: goto P_0c095544;
case 0x0c095546u: goto P_0c095546;
case 0x0c095548u: goto P_0c095548;
case 0x0c09554au: goto P_0c09554a;
case 0x0c09554cu: goto P_0c09554c;
case 0x0c09554eu: goto P_0c09554e;
case 0x0c095550u: goto P_0c095550;
case 0x0c095552u: goto P_0c095552;
case 0x0c095554u: goto P_0c095554;
case 0x0c095556u: goto P_0c095556;
case 0x0c095558u: goto P_0c095558;
case 0x0c09555au: goto P_0c09555a;
case 0x0c09555cu: goto P_0c09555c;
case 0x0c09555eu: goto P_0c09555e;
case 0x0c095560u: goto P_0c095560;
case 0x0c095562u: goto P_0c095562;
case 0x0c095564u: goto P_0c095564;
case 0x0c095566u: goto P_0c095566;
case 0x0c095568u: goto P_0c095568;
case 0x0c09556au: goto P_0c09556a;
case 0x0c09556cu: goto P_0c09556c;
case 0x0c09556eu: goto P_0c09556e;
case 0x0c095570u: goto P_0c095570;
case 0x0c095572u: goto P_0c095572;
case 0x0c095574u: goto P_0c095574;
case 0x0c095576u: goto P_0c095576;
case 0x0c095578u: goto P_0c095578;
case 0x0c09557au: goto P_0c09557a;
case 0x0c09557cu: goto P_0c09557c;
case 0x0c09557eu: goto P_0c09557e;
case 0x0c095580u: goto P_0c095580;
case 0x0c095582u: goto P_0c095582;
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
case 0x0c0c9ce6u: goto P_0c0c9ce6;
case 0x0c0c9ce8u: goto P_0c0c9ce8;
case 0x0c0c9ceau: goto P_0c0c9cea;
case 0x0c0c9cecu: goto P_0c0c9cec;
case 0x0c0c9ceeu: goto P_0c0c9cee;
case 0x0c0c9cf0u: goto P_0c0c9cf0;
case 0x0c0c9cf2u: goto P_0c0c9cf2;
case 0x0c0c9cf4u: goto P_0c0c9cf4;
case 0x0c0c9cf6u: goto P_0c0c9cf6;
case 0x0c0c9cf8u: goto P_0c0c9cf8;
case 0x0c0c9cfau: goto P_0c0c9cfa;
case 0x0c0c9cfcu: goto P_0c0c9cfc;
case 0x0c0c9cfeu: goto P_0c0c9cfe;
case 0x0c0c9d00u: goto P_0c0c9d00;
case 0x0c0c9d02u: goto P_0c0c9d02;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08d158: /* original d335, guest PC 0x0c08d158 */
if(!s->budget--) { s->failed_pc=0x0c08d158u; return 0; }
r[3]=read(ram,0x0c08d230u,4);
goto P_0c08d15a;
P_0c08d15a: /* original 7ffc, guest PC 0x0c08d15a */
if(!s->budget--) { s->failed_pc=0x0c08d15au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08d15c;
P_0c08d15c: /* original 554d, guest PC 0x0c08d15c */
if(!s->budget--) { s->failed_pc=0x0c08d15cu; return 0; }
r[5]=read(ram,r[4]+52,4);
goto P_0c08d15e;
P_0c08d15e: /* original e040, guest PC 0x0c08d15e */
if(!s->budget--) { s->failed_pc=0x0c08d15eu; return 0; }
r[0]=0x00000040u;
goto P_0c08d160;
P_0c08d160: /* original d732, guest PC 0x0c08d160 */
if(!s->budget--) { s->failed_pc=0x0c08d160u; return 0; }
r[7]=read(ram,0x0c08d22cu,4);
goto P_0c08d162;
P_0c08d162: /* original 4508, guest PC 0x0c08d162 */
if(!s->budget--) { s->failed_pc=0x0c08d162u; return 0; }
r[5]<<=2;
goto P_0c08d164;
P_0c08d164: /* original 064e, guest PC 0x0c08d164 */
if(!s->budget--) { s->failed_pc=0x0c08d164u; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c08d166;
P_0c08d166: /* original 2f32, guest PC 0x0c08d166 */
if(!s->budget--) { s->failed_pc=0x0c08d166u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08d168;
P_0c08d168: /* original 335c, guest PC 0x0c08d168 */
if(!s->budget--) { s->failed_pc=0x0c08d168u; return 0; }
r[3]+=r[5];
goto P_0c08d16a;
P_0c08d16a: /* original 375c, guest PC 0x0c08d16a */
if(!s->budget--) { s->failed_pc=0x0c08d16au; return 0; }
r[7]+=r[5];
goto P_0c08d16c;
P_0c08d16c: /* original 6232, guest PC 0x0c08d16c */
if(!s->budget--) { s->failed_pc=0x0c08d16cu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c08d16e;
P_0c08d16e: /* original 6772, guest PC 0x0c08d16e */
if(!s->budget--) { s->failed_pc=0x0c08d16eu; return 0; }
tmp=read(ram,r[7],4);
r[7]=tmp;
goto P_0c08d170;
P_0c08d170: /* original e040, guest PC 0x0c08d170 */
if(!s->budget--) { s->failed_pc=0x0c08d170u; return 0; }
r[0]=0x00000040u;
goto P_0c08d172;
P_0c08d172: /* original 6323, guest PC 0x0c08d172 */
if(!s->budget--) { s->failed_pc=0x0c08d172u; return 0; }
r[3]=r[2];
goto P_0c08d174;
P_0c08d174: /* original 336c, guest PC 0x0c08d174 */
if(!s->budget--) { s->failed_pc=0x0c08d174u; return 0; }
r[3]+=r[6];
goto P_0c08d176;
P_0c08d176: /* original 376c, guest PC 0x0c08d176 */
if(!s->budget--) { s->failed_pc=0x0c08d176u; return 0; }
r[7]+=r[6];
goto P_0c08d178;
P_0c08d178: /* original 2f22, guest PC 0x0c08d178 */
if(!s->budget--) { s->failed_pc=0x0c08d178u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c08d17a;
P_0c08d17a: /* original 6230, guest PC 0x0c08d17a */
if(!s->budget--) { s->failed_pc=0x0c08d17au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c08d17c;
P_0c08d17c: /* original 6770, guest PC 0x0c08d17c */
if(!s->budget--) { s->failed_pc=0x0c08d17cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]=tmp;
goto P_0c08d17e;
P_0c08d17e: /* original 622c, guest PC 0x0c08d17e */
if(!s->budget--) { s->failed_pc=0x0c08d17eu; return 0; }
r[2]=r[2]&255u;
goto P_0c08d180;
P_0c08d180: /* original 677c, guest PC 0x0c08d180 */
if(!s->budget--) { s->failed_pc=0x0c08d180u; return 0; }
r[7]=r[7]&255u;
goto P_0c08d182;
P_0c08d182: /* original 2f22, guest PC 0x0c08d182 */
if(!s->budget--) { s->failed_pc=0x0c08d182u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c08d184;
P_0c08d184: /* original 145d, guest PC 0x0c08d184 */
if(!s->budget--) { s->failed_pc=0x0c08d184u; return 0; }
write(ram,r[4]+52,r[5],4);
goto P_0c08d186;
P_0c08d186: /* original 0466, guest PC 0x0c08d186 */
if(!s->budget--) { s->failed_pc=0x0c08d186u; return 0; }
write(ram,r[4]+r[0],r[6],4);
goto P_0c08d188;
P_0c08d188: /* original 147e, guest PC 0x0c08d188 */
if(!s->budget--) { s->failed_pc=0x0c08d188u; return 0; }
write(ram,r[4]+56,r[7],4);
goto P_0c08d18a;
P_0c08d18a: /* original 63f2, guest PC 0x0c08d18a */
if(!s->budget--) { s->failed_pc=0x0c08d18au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c08d18c;
P_0c08d18c: /* original 143f, guest PC 0x0c08d18c */
if(!s->budget--) { s->failed_pc=0x0c08d18cu; return 0; }
write(ram,r[4]+60,r[3],4);
goto P_0c08d18e;
P_0c08d18e: /* original 000b, guest PC 0x0c08d18e */
if(!s->budget--) { s->failed_pc=0x0c08d18eu; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c08d190: /* original 7f04, guest PC 0x0c08d190 */
if(!s->budget--) { s->failed_pc=0x0c08d190u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c08d192u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08d192u; return 0; } return 1;
P_0c09553c: /* original fffb, guest PC 0x0c09553c */
if(!s->budget--) { s->failed_pc=0x0c09553cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09553e;
P_0c09553e: /* original 4f22, guest PC 0x0c09553e */
if(!s->budget--) { s->failed_pc=0x0c09553eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c095540;
P_0c095540: /* original 7ff0, guest PC 0x0c095540 */
if(!s->budget--) { s->failed_pc=0x0c095540u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c095542;
P_0c095542: /* original 1f42, guest PC 0x0c095542 */
if(!s->budget--) { s->failed_pc=0x0c095542u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c095544;
P_0c095544: /* original 2f52, guest PC 0x0c095544 */
if(!s->budget--) { s->failed_pc=0x0c095544u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c095546;
P_0c095546: /* original 1f61, guest PC 0x0c095546 */
if(!s->budget--) { s->failed_pc=0x0c095546u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c095548;
P_0c095548: /* original 54f2, guest PC 0x0c095548 */
if(!s->budget--) { s->failed_pc=0x0c095548u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c09554a;
P_0c09554a: /* original d369, guest PC 0x0c09554a */
if(!s->budget--) { s->failed_pc=0x0c09554au; return 0; }
r[3]=read(ram,0x0c0956f0u,4);
goto P_0c09554c;
P_0c09554c: /* original 644f, guest PC 0x0c09554c */
if(!s->budget--) { s->failed_pc=0x0c09554cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c09554e;
P_0c09554e: /* original 430b, guest PC 0x0c09554e */
if(!s->budget--) { s->failed_pc=0x0c09554eu; return 0; }
target=r[3];
r[16]=code_base|0x0c095552u;
write(ram,r[15]+12,r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c095552u) { target=s->pc; goto dispatch; }
goto P_0c095552;
P_0c095550: /* original 1f43, guest PC 0x0c095550 */
if(!s->budget--) { s->failed_pc=0x0c095550u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c095552;
P_0c095552: /* original d368, guest PC 0x0c095552 */
if(!s->budget--) { s->failed_pc=0x0c095552u; return 0; }
r[3]=read(ram,0x0c0956f4u,4);
goto P_0c095554;
P_0c095554: /* original ff0c, guest PC 0x0c095554 */
if(!s->budget--) { s->failed_pc=0x0c095554u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c095556;
P_0c095556: /* original 430b, guest PC 0x0c095556 */
if(!s->budget--) { s->failed_pc=0x0c095556u; return 0; }
target=r[3];
r[16]=code_base|0x0c09555au;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09555au) { target=s->pc; goto dispatch; }
goto P_0c09555a;
P_0c095558: /* original 54f3, guest PC 0x0c095558 */
if(!s->budget--) { s->failed_pc=0x0c095558u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c09555a;
P_0c09555a: /* original 62f2, guest PC 0x0c09555a */
if(!s->budget--) { s->failed_pc=0x0c09555au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09555c;
P_0c09555c: /* original f70c, guest PC 0x0c09555c */
if(!s->budget--) { s->failed_pc=0x0c09555cu; return 0; }
vf3_matrix_move(s,7,0);
goto P_0c09555e;
P_0c09555e: /* original f628, guest PC 0x0c09555e */
if(!s->budget--) { s->failed_pc=0x0c09555eu; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
goto P_0c095560;
P_0c095560: /* original 53f1, guest PC 0x0c095560 */
if(!s->budget--) { s->failed_pc=0x0c095560u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c095562;
P_0c095562: /* original f762, guest PC 0x0c095562 */
if(!s->budget--) { s->failed_pc=0x0c095562u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'*');
goto P_0c095564;
P_0c095564: /* original f40c, guest PC 0x0c095564 */
if(!s->budget--) { s->failed_pc=0x0c095564u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c095566;
P_0c095566: /* original f538, guest PC 0x0c095566 */
if(!s->budget--) { s->failed_pc=0x0c095566u; return 0; }
vf3_matrix_load(s,ram,5,r[3]);
goto P_0c095568;
P_0c095568: /* original 6323, guest PC 0x0c095568 */
if(!s->budget--) { s->failed_pc=0x0c095568u; return 0; }
r[3]=r[2];
goto P_0c09556a;
P_0c09556a: /* original f05c, guest PC 0x0c09556a */
if(!s->budget--) { s->failed_pc=0x0c09556au; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c09556c;
P_0c09556c: /* original f452, guest PC 0x0c09556c */
if(!s->budget--) { s->failed_pc=0x0c09556cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c09556e;
P_0c09556e: /* original f7fe, guest PC 0x0c09556e */
if(!s->budget--) { s->failed_pc=0x0c09556eu; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[15],fr[7],r[18]);
goto P_0c095570;
P_0c095570: /* original ff62, guest PC 0x0c095570 */
if(!s->budget--) { s->failed_pc=0x0c095570u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[6],r[18],'*');
goto P_0c095572;
P_0c095572: /* original f57c, guest PC 0x0c095572 */
if(!s->budget--) { s->failed_pc=0x0c095572u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c095574;
P_0c095574: /* original f35a, guest PC 0x0c095574 */
if(!s->budget--) { s->failed_pc=0x0c095574u; return 0; }
vf3_matrix_store(s,ram,5,r[3]);
goto P_0c095576;
P_0c095576: /* original f4f1, guest PC 0x0c095576 */
if(!s->budget--) { s->failed_pc=0x0c095576u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
goto P_0c095578;
P_0c095578: /* original 53f1, guest PC 0x0c095578 */
if(!s->budget--) { s->failed_pc=0x0c095578u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09557a;
P_0c09557a: /* original 7f10, guest PC 0x0c09557a */
if(!s->budget--) { s->failed_pc=0x0c09557au; return 0; }
r[15]+=0x00000010u;
goto P_0c09557c;
P_0c09557c: /* original 4f26, guest PC 0x0c09557c */
if(!s->budget--) { s->failed_pc=0x0c09557cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09557e;
P_0c09557e: /* original f34a, guest PC 0x0c09557e */
if(!s->budget--) { s->failed_pc=0x0c09557eu; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c095580;
P_0c095580: /* original 000b, guest PC 0x0c095580 */
if(!s->budget--) { s->failed_pc=0x0c095580u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c095582: /* original fff9, guest PC 0x0c095582 */
if(!s->budget--) { s->failed_pc=0x0c095582u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c095584u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095584u; return 0; } return 1;
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
P_0c0c9ce6: /* original 901d, guest PC 0x0c0c9ce6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ce6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9d24u,2);
goto P_0c0c9ce8;
P_0c0c9ce8: /* original d412, guest PC 0x0c0c9ce8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ce8u; return 0; }
r[4]=read(ram,0x0c0c9d34u,4);
goto P_0c0c9cea;
P_0c0c9cea: /* original d316, guest PC 0x0c0c9cea */
if(!s->budget--) { s->failed_pc=0x0c0c9ceau; return 0; }
r[3]=read(ram,0x0c0c9d44u,4);
goto P_0c0c9cec;
P_0c0c9cec: /* original 054e, guest PC 0x0c0c9cec */
if(!s->budget--) { s->failed_pc=0x0c0c9cecu; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0c9cee;
P_0c0c9cee: /* original 4f12, guest PC 0x0c0c9cee */
if(!s->budget--) { s->failed_pc=0x0c0c9ceeu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c9cf0;
P_0c0c9cf0: /* original 0537, guest PC 0x0c0c9cf0 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf0u; return 0; }
r[19]=r[5]*r[3];
goto P_0c0c9cf2;
P_0c0c9cf2: /* original 051a, guest PC 0x0c0c9cf2 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf2u; return 0; }
r[5]=r[19];
goto P_0c0c9cf4;
P_0c0c9cf4: /* original 7501, guest PC 0x0c0c9cf4 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf4u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c9cf6;
P_0c0c9cf6: /* original 0456, guest PC 0x0c0c9cf6 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf6u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c0c9cf8;
P_0c0c9cf8: /* original 4529, guest PC 0x0c0c9cf8 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf8u; return 0; }
r[5]>>=16;
goto P_0c0c9cfa;
P_0c0c9cfa: /* original 9412, guest PC 0x0c0c9cfa */
if(!s->budget--) { s->failed_pc=0x0c0c9cfau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9d22u,2);
goto P_0c0c9cfc;
P_0c0c9cfc: /* original 2459, guest PC 0x0c0c9cfc */
if(!s->budget--) { s->failed_pc=0x0c0c9cfcu; return 0; }
r[4]&=r[5];
goto P_0c0c9cfe;
P_0c0c9cfe: /* original 6043, guest PC 0x0c0c9cfe */
if(!s->budget--) { s->failed_pc=0x0c0c9cfeu; return 0; }
r[0]=r[4];
goto P_0c0c9d00;
P_0c0c9d00: /* original 000b, guest PC 0x0c0c9d00 */
if(!s->budget--) { s->failed_pc=0x0c0c9d00u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c0c9d02: /* original 4f16, guest PC 0x0c0c9d02 */
if(!s->budget--) { s->failed_pc=0x0c0c9d02u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c0c9d04u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9d04u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
