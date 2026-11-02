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
int vf3_away_batch189_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c0a0280u: goto P_0c0a0280;
case 0x0c0a0282u: goto P_0c0a0282;
case 0x0c0a0284u: goto P_0c0a0284;
case 0x0c0a0286u: goto P_0c0a0286;
case 0x0c0a0288u: goto P_0c0a0288;
case 0x0c0a028au: goto P_0c0a028a;
case 0x0c0a028cu: goto P_0c0a028c;
case 0x0c0a028eu: goto P_0c0a028e;
case 0x0c0a0290u: goto P_0c0a0290;
case 0x0c0a0292u: goto P_0c0a0292;
case 0x0c0a0294u: goto P_0c0a0294;
case 0x0c0a0296u: goto P_0c0a0296;
case 0x0c0a0298u: goto P_0c0a0298;
case 0x0c0a029au: goto P_0c0a029a;
case 0x0c0a029cu: goto P_0c0a029c;
case 0x0c0a029eu: goto P_0c0a029e;
case 0x0c0a02a0u: goto P_0c0a02a0;
case 0x0c0a02a2u: goto P_0c0a02a2;
case 0x0c0a02a4u: goto P_0c0a02a4;
case 0x0c0a02a6u: goto P_0c0a02a6;
case 0x0c0a02a8u: goto P_0c0a02a8;
case 0x0c0a02aau: goto P_0c0a02aa;
case 0x0c0a02acu: goto P_0c0a02ac;
case 0x0c0a02aeu: goto P_0c0a02ae;
case 0x0c0a02b0u: goto P_0c0a02b0;
case 0x0c0a02b2u: goto P_0c0a02b2;
case 0x0c0a02b4u: goto P_0c0a02b4;
case 0x0c0a02b6u: goto P_0c0a02b6;
case 0x0c0a02b8u: goto P_0c0a02b8;
case 0x0c0a02bau: goto P_0c0a02ba;
case 0x0c0a02bcu: goto P_0c0a02bc;
case 0x0c0a02beu: goto P_0c0a02be;
case 0x0c0a02c0u: goto P_0c0a02c0;
case 0x0c0a02c2u: goto P_0c0a02c2;
case 0x0c0a02c4u: goto P_0c0a02c4;
case 0x0c0a02c6u: goto P_0c0a02c6;
case 0x0c0a02c8u: goto P_0c0a02c8;
case 0x0c0a02cau: goto P_0c0a02ca;
case 0x0c0a02ccu: goto P_0c0a02cc;
case 0x0c0a02ceu: goto P_0c0a02ce;
case 0x0c0a02d0u: goto P_0c0a02d0;
case 0x0c0a02d2u: goto P_0c0a02d2;
case 0x0c0a02d4u: goto P_0c0a02d4;
case 0x0c0a02d6u: goto P_0c0a02d6;
case 0x0c0a02d8u: goto P_0c0a02d8;
case 0x0c0a02dau: goto P_0c0a02da;
case 0x0c0a02dcu: goto P_0c0a02dc;
case 0x0c0a02deu: goto P_0c0a02de;
case 0x0c0a02e0u: goto P_0c0a02e0;
case 0x0c0a02e2u: goto P_0c0a02e2;
case 0x0c0a02e4u: goto P_0c0a02e4;
case 0x0c0a02e6u: goto P_0c0a02e6;
case 0x0c0a02e8u: goto P_0c0a02e8;
case 0x0c0a02eau: goto P_0c0a02ea;
case 0x0c0a02ecu: goto P_0c0a02ec;
case 0x0c0a02eeu: goto P_0c0a02ee;
case 0x0c0a02f0u: goto P_0c0a02f0;
case 0x0c0a02f2u: goto P_0c0a02f2;
case 0x0c0a02f4u: goto P_0c0a02f4;
case 0x0c0a02f6u: goto P_0c0a02f6;
case 0x0c0a02f8u: goto P_0c0a02f8;
case 0x0c0a02fau: goto P_0c0a02fa;
case 0x0c0a02fcu: goto P_0c0a02fc;
case 0x0c0a02feu: goto P_0c0a02fe;
case 0x0c0a0300u: goto P_0c0a0300;
case 0x0c0a0302u: goto P_0c0a0302;
case 0x0c0a0304u: goto P_0c0a0304;
case 0x0c0a0306u: goto P_0c0a0306;
case 0x0c0a0308u: goto P_0c0a0308;
case 0x0c0a030au: goto P_0c0a030a;
case 0x0c0a030cu: goto P_0c0a030c;
case 0x0c0a030eu: goto P_0c0a030e;
case 0x0c0a0310u: goto P_0c0a0310;
case 0x0c0a0312u: goto P_0c0a0312;
case 0x0c0a0314u: goto P_0c0a0314;
case 0x0c0a0316u: goto P_0c0a0316;
case 0x0c0a0318u: goto P_0c0a0318;
case 0x0c0a031au: goto P_0c0a031a;
case 0x0c0a031cu: goto P_0c0a031c;
case 0x0c0a031eu: goto P_0c0a031e;
case 0x0c0a0320u: goto P_0c0a0320;
case 0x0c0a0322u: goto P_0c0a0322;
case 0x0c0a0324u: goto P_0c0a0324;
case 0x0c0a0326u: goto P_0c0a0326;
case 0x0c0a0328u: goto P_0c0a0328;
case 0x0c0a032au: goto P_0c0a032a;
case 0x0c0a032cu: goto P_0c0a032c;
case 0x0c0a032eu: goto P_0c0a032e;
case 0x0c0a036cu: goto P_0c0a036c;
case 0x0c0a036eu: goto P_0c0a036e;
case 0x0c0a0370u: goto P_0c0a0370;
case 0x0c0a0372u: goto P_0c0a0372;
case 0x0c0a0374u: goto P_0c0a0374;
case 0x0c0a0376u: goto P_0c0a0376;
case 0x0c0a0378u: goto P_0c0a0378;
case 0x0c0a037au: goto P_0c0a037a;
case 0x0c0a037cu: goto P_0c0a037c;
case 0x0c0a037eu: goto P_0c0a037e;
case 0x0c0a0380u: goto P_0c0a0380;
case 0x0c0a0382u: goto P_0c0a0382;
case 0x0c0a0384u: goto P_0c0a0384;
case 0x0c0a0386u: goto P_0c0a0386;
case 0x0c0a0388u: goto P_0c0a0388;
case 0x0c0a038au: goto P_0c0a038a;
case 0x0c0a038cu: goto P_0c0a038c;
case 0x0c0a038eu: goto P_0c0a038e;
case 0x0c0a0390u: goto P_0c0a0390;
case 0x0c0a0392u: goto P_0c0a0392;
case 0x0c0a0394u: goto P_0c0a0394;
case 0x0c0a0396u: goto P_0c0a0396;
case 0x0c0a0398u: goto P_0c0a0398;
case 0x0c0a039au: goto P_0c0a039a;
case 0x0c0a039cu: goto P_0c0a039c;
case 0x0c0a039eu: goto P_0c0a039e;
case 0x0c0a03a0u: goto P_0c0a03a0;
case 0x0c0a03a2u: goto P_0c0a03a2;
case 0x0c0a03a4u: goto P_0c0a03a4;
case 0x0c0a03a6u: goto P_0c0a03a6;
case 0x0c0a03a8u: goto P_0c0a03a8;
case 0x0c0a03aau: goto P_0c0a03aa;
case 0x0c0a03acu: goto P_0c0a03ac;
case 0x0c0a03aeu: goto P_0c0a03ae;
case 0x0c0a03b0u: goto P_0c0a03b0;
case 0x0c0a03b2u: goto P_0c0a03b2;
case 0x0c0a03b4u: goto P_0c0a03b4;
case 0x0c0a03b6u: goto P_0c0a03b6;
case 0x0c0a03b8u: goto P_0c0a03b8;
case 0x0c0a03bau: goto P_0c0a03ba;
case 0x0c0a03bcu: goto P_0c0a03bc;
case 0x0c0a03beu: goto P_0c0a03be;
case 0x0c0a03c0u: goto P_0c0a03c0;
case 0x0c0a03c2u: goto P_0c0a03c2;
case 0x0c0a03c4u: goto P_0c0a03c4;
case 0x0c0a03c6u: goto P_0c0a03c6;
case 0x0c0a03c8u: goto P_0c0a03c8;
case 0x0c0a03cau: goto P_0c0a03ca;
case 0x0c0a03ccu: goto P_0c0a03cc;
case 0x0c0a03ceu: goto P_0c0a03ce;
case 0x0c0a03d0u: goto P_0c0a03d0;
case 0x0c0a03d2u: goto P_0c0a03d2;
case 0x0c0a03d4u: goto P_0c0a03d4;
case 0x0c0a03d6u: goto P_0c0a03d6;
case 0x0c0a03d8u: goto P_0c0a03d8;
case 0x0c0a03dau: goto P_0c0a03da;
case 0x0c0a03dcu: goto P_0c0a03dc;
default: return vf3_matrix_family(target,s,ram);
}
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
P_0c0a0280: /* original 2fe6, guest PC 0x0c0a0280 */
if(!s->budget--) { s->failed_pc=0x0c0a0280u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0282;
P_0c0a0282: /* original 2fd6, guest PC 0x0c0a0282 */
if(!s->budget--) { s->failed_pc=0x0c0a0282u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0284;
P_0c0a0284: /* original 2fc6, guest PC 0x0c0a0284 */
if(!s->budget--) { s->failed_pc=0x0c0a0284u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0286;
P_0c0a0286: /* original ec2b, guest PC 0x0c0a0286 */
if(!s->budget--) { s->failed_pc=0x0c0a0286u; return 0; }
r[12]=0x0000002bu;
goto P_0c0a0288;
P_0c0a0288: /* original 2fb6, guest PC 0x0c0a0288 */
if(!s->budget--) { s->failed_pc=0x0c0a0288u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a028a;
P_0c0a028a: /* original 4f22, guest PC 0x0c0a028a */
if(!s->budget--) { s->failed_pc=0x0c0a028au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a028c;
P_0c0a028c: /* original d32f, guest PC 0x0c0a028c */
if(!s->budget--) { s->failed_pc=0x0c0a028cu; return 0; }
r[3]=read(ram,0x0c0a034cu,4);
goto P_0c0a028e;
P_0c0a028e: /* original de2e, guest PC 0x0c0a028e */
if(!s->budget--) { s->failed_pc=0x0c0a028eu; return 0; }
r[14]=read(ram,0x0c0a0348u,4);
goto P_0c0a0290;
P_0c0a0290: /* original 7ff8, guest PC 0x0c0a0290 */
if(!s->budget--) { s->failed_pc=0x0c0a0290u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a0292;
P_0c0a0292: /* original 1f31, guest PC 0x0c0a0292 */
if(!s->budget--) { s->failed_pc=0x0c0a0292u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0a0294;
P_0c0a0294: /* original e307, guest PC 0x0c0a0294 */
if(!s->budget--) { s->failed_pc=0x0c0a0294u; return 0; }
r[3]=0x00000007u;
goto P_0c0a0296;
P_0c0a0296: /* original d22e, guest PC 0x0c0a0296 */
if(!s->budget--) { s->failed_pc=0x0c0a0296u; return 0; }
r[2]=read(ram,0x0c0a0350u,4);
goto P_0c0a0298;
P_0c0a0298: /* original 6422, guest PC 0x0c0a0298 */
if(!s->budget--) { s->failed_pc=0x0c0a0298u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0a029a;
P_0c0a029a: /* original 3c48, guest PC 0x0c0a029a */
if(!s->budget--) { s->failed_pc=0x0c0a029au; return 0; }
r[12]-=r[4];
goto P_0c0a029c;
P_0c0a029c: /* original 2fc2, guest PC 0x0c0a029c */
if(!s->budget--) { s->failed_pc=0x0c0a029cu; return 0; }
write(ram,r[15],r[12],4);
goto P_0c0a029e;
P_0c0a029e: /* original e428, guest PC 0x0c0a029e */
if(!s->budget--) { s->failed_pc=0x0c0a029eu; return 0; }
r[4]=0x00000028u;
goto P_0c0a02a0;
P_0c0a02a0: /* original d52c, guest PC 0x0c0a02a0 */
if(!s->budget--) { s->failed_pc=0x0c0a02a0u; return 0; }
r[5]=read(ram,0x0c0a0354u,4);
goto P_0c0a02a2;
P_0c0a02a2: /* original 4c3c, guest PC 0x0c0a02a2 */
if(!s->budget--) { s->failed_pc=0x0c0a02a2u; return 0; }
r[12]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[12]>>((-r[3])&31u)):((int32_t)r[12]<0?0xffffffffu:0)):r[12]<<(r[3]&31u);
goto P_0c0a02a4;
P_0c0a02a4: /* original d12c, guest PC 0x0c0a02a4 */
if(!s->budget--) { s->failed_pc=0x0c0a02a4u; return 0; }
r[1]=read(ram,0x0c0a0358u,4);
goto P_0c0a02a6;
P_0c0a02a6: /* original 24cb, guest PC 0x0c0a02a6 */
if(!s->budget--) { s->failed_pc=0x0c0a02a6u; return 0; }
r[4]|=r[12];
goto P_0c0a02a8;
P_0c0a02a8: /* original 410b, guest PC 0x0c0a02a8 */
if(!s->budget--) { s->failed_pc=0x0c0a02a8u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a02acu;
r[6]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a02acu) { target=s->pc; goto dispatch; }
goto P_0c0a02ac;
P_0c0a02aa: /* original e601, guest PC 0x0c0a02aa */
if(!s->budget--) { s->failed_pc=0x0c0a02aau; return 0; }
r[6]=0x00000001u;
goto P_0c0a02ac;
P_0c0a02ac: /* original 9041, guest PC 0x0c0a02ac */
if(!s->budget--) { s->failed_pc=0x0c0a02acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0332u,2);
goto P_0c0a02ae;
P_0c0a02ae: /* original e41c, guest PC 0x0c0a02ae */
if(!s->budget--) { s->failed_pc=0x0c0a02aeu; return 0; }
r[4]=0x0000001cu;
goto P_0c0a02b0;
P_0c0a02b0: /* original dd2b, guest PC 0x0c0a02b0 */
if(!s->budget--) { s->failed_pc=0x0c0a02b0u; return 0; }
r[13]=read(ram,0x0c0a0360u,4);
goto P_0c0a02b2;
P_0c0a02b2: /* original 24cb, guest PC 0x0c0a02b2 */
if(!s->budget--) { s->failed_pc=0x0c0a02b2u; return 0; }
r[4]|=r[12];
goto P_0c0a02b4;
P_0c0a02b4: /* original 03ec, guest PC 0x0c0a02b4 */
if(!s->budget--) { s->failed_pc=0x0c0a02b4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02b6;
P_0c0a02b6: /* original db29, guest PC 0x0c0a02b6 */
if(!s->budget--) { s->failed_pc=0x0c0a02b6u; return 0; }
r[11]=read(ram,0x0c0a035cu,4);
goto P_0c0a02b8;
P_0c0a02b8: /* original 2f36, guest PC 0x0c0a02b8 */
if(!s->budget--) { s->failed_pc=0x0c0a02b8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02ba;
P_0c0a02ba: /* original 4d0b, guest PC 0x0c0a02ba */
if(!s->budget--) { s->failed_pc=0x0c0a02bau; return 0; }
target=r[13];
r[16]=code_base|0x0c0a02beu;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a02beu) { target=s->pc; goto dispatch; }
goto P_0c0a02be;
P_0c0a02bc: /* original 2fb6, guest PC 0x0c0a02bc */
if(!s->budget--) { s->failed_pc=0x0c0a02bcu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02be;
P_0c0a02be: /* original 903b, guest PC 0x0c0a02be */
if(!s->budget--) { s->failed_pc=0x0c0a02beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0338u,2);
goto P_0c0a02c0;
P_0c0a02c0: /* original e420, guest PC 0x0c0a02c0 */
if(!s->budget--) { s->failed_pc=0x0c0a02c0u; return 0; }
r[4]=0x00000020u;
goto P_0c0a02c2;
P_0c0a02c2: /* original 24cb, guest PC 0x0c0a02c2 */
if(!s->budget--) { s->failed_pc=0x0c0a02c2u; return 0; }
r[4]|=r[12];
goto P_0c0a02c4;
P_0c0a02c4: /* original 03ec, guest PC 0x0c0a02c4 */
if(!s->budget--) { s->failed_pc=0x0c0a02c4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02c6;
P_0c0a02c6: /* original 2f36, guest PC 0x0c0a02c6 */
if(!s->budget--) { s->failed_pc=0x0c0a02c6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02c8;
P_0c0a02c8: /* original 4d0b, guest PC 0x0c0a02c8 */
if(!s->budget--) { s->failed_pc=0x0c0a02c8u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a02ccu;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a02ccu) { target=s->pc; goto dispatch; }
goto P_0c0a02cc;
P_0c0a02ca: /* original 2fb6, guest PC 0x0c0a02ca */
if(!s->budget--) { s->failed_pc=0x0c0a02cau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02cc;
P_0c0a02cc: /* original 9035, guest PC 0x0c0a02cc */
if(!s->budget--) { s->failed_pc=0x0c0a02ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a033au,2);
goto P_0c0a02ce;
P_0c0a02ce: /* original e424, guest PC 0x0c0a02ce */
if(!s->budget--) { s->failed_pc=0x0c0a02ceu; return 0; }
r[4]=0x00000024u;
goto P_0c0a02d0;
P_0c0a02d0: /* original 24cb, guest PC 0x0c0a02d0 */
if(!s->budget--) { s->failed_pc=0x0c0a02d0u; return 0; }
r[4]|=r[12];
goto P_0c0a02d2;
P_0c0a02d2: /* original 03ec, guest PC 0x0c0a02d2 */
if(!s->budget--) { s->failed_pc=0x0c0a02d2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02d4;
P_0c0a02d4: /* original 2f36, guest PC 0x0c0a02d4 */
if(!s->budget--) { s->failed_pc=0x0c0a02d4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02d6;
P_0c0a02d6: /* original 4d0b, guest PC 0x0c0a02d6 */
if(!s->budget--) { s->failed_pc=0x0c0a02d6u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a02dau;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a02dau) { target=s->pc; goto dispatch; }
goto P_0c0a02da;
P_0c0a02d8: /* original 2fb6, guest PC 0x0c0a02d8 */
if(!s->budget--) { s->failed_pc=0x0c0a02d8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02da;
P_0c0a02da: /* original 902f, guest PC 0x0c0a02da */
if(!s->budget--) { s->failed_pc=0x0c0a02dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a033cu,2);
goto P_0c0a02dc;
P_0c0a02dc: /* original e428, guest PC 0x0c0a02dc */
if(!s->budget--) { s->failed_pc=0x0c0a02dcu; return 0; }
r[4]=0x00000028u;
goto P_0c0a02de;
P_0c0a02de: /* original 24cb, guest PC 0x0c0a02de */
if(!s->budget--) { s->failed_pc=0x0c0a02deu; return 0; }
r[4]|=r[12];
goto P_0c0a02e0;
P_0c0a02e0: /* original 03ec, guest PC 0x0c0a02e0 */
if(!s->budget--) { s->failed_pc=0x0c0a02e0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02e2;
P_0c0a02e2: /* original 2f36, guest PC 0x0c0a02e2 */
if(!s->budget--) { s->failed_pc=0x0c0a02e2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02e4;
P_0c0a02e4: /* original 4d0b, guest PC 0x0c0a02e4 */
if(!s->budget--) { s->failed_pc=0x0c0a02e4u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a02e8u;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a02e8u) { target=s->pc; goto dispatch; }
goto P_0c0a02e8;
P_0c0a02e6: /* original 2fb6, guest PC 0x0c0a02e6 */
if(!s->budget--) { s->failed_pc=0x0c0a02e6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02e8;
P_0c0a02e8: /* original 9029, guest PC 0x0c0a02e8 */
if(!s->budget--) { s->failed_pc=0x0c0a02e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a033eu,2);
goto P_0c0a02ea;
P_0c0a02ea: /* original e307, guest PC 0x0c0a02ea */
if(!s->budget--) { s->failed_pc=0x0c0a02eau; return 0; }
r[3]=0x00000007u;
goto P_0c0a02ec;
P_0c0a02ec: /* original e601, guest PC 0x0c0a02ec */
if(!s->budget--) { s->failed_pc=0x0c0a02ecu; return 0; }
r[6]=0x00000001u;
goto P_0c0a02ee;
P_0c0a02ee: /* original 04ec, guest PC 0x0c0a02ee */
if(!s->budget--) { s->failed_pc=0x0c0a02eeu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02f0;
P_0c0a02f0: /* original d01c, guest PC 0x0c0a02f0 */
if(!s->budget--) { s->failed_pc=0x0c0a02f0u; return 0; }
r[0]=read(ram,0x0c0a0364u,4);
goto P_0c0a02f2;
P_0c0a02f2: /* original 044c, guest PC 0x0c0a02f2 */
if(!s->budget--) { s->failed_pc=0x0c0a02f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a02f4;
P_0c0a02f4: /* original 9024, guest PC 0x0c0a02f4 */
if(!s->budget--) { s->failed_pc=0x0c0a02f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0340u,2);
goto P_0c0a02f6;
P_0c0a02f6: /* original 0e44, guest PC 0x0c0a02f6 */
if(!s->budget--) { s->failed_pc=0x0c0a02f6u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a02f8;
P_0c0a02f8: /* original 70f9, guest PC 0x0c0a02f8 */
if(!s->budget--) { s->failed_pc=0x0c0a02f8u; return 0; }
r[0]+=0xfffffff9u;
goto P_0c0a02fa;
P_0c0a02fa: /* original 04ec, guest PC 0x0c0a02fa */
if(!s->budget--) { s->failed_pc=0x0c0a02fau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02fc;
P_0c0a02fc: /* original 52f8, guest PC 0x0c0a02fc */
if(!s->budget--) { s->failed_pc=0x0c0a02fcu; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c0a02fe;
P_0c0a02fe: /* original 4400, guest PC 0x0c0a02fe */
if(!s->budget--) { s->failed_pc=0x0c0a02feu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a0300;
P_0c0a0300: /* original 951e, guest PC 0x0c0a0300 */
if(!s->budget--) { s->failed_pc=0x0c0a0300u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0340u,2);
goto P_0c0a0302;
P_0c0a0302: /* original 740e, guest PC 0x0c0a0302 */
if(!s->budget--) { s->failed_pc=0x0c0a0302u; return 0; }
r[4]+=0x0000000eu;
goto P_0c0a0304;
P_0c0a0304: /* original 423c, guest PC 0x0c0a0304 */
if(!s->budget--) { s->failed_pc=0x0c0a0304u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[2]>>((-r[3])&31u)):((int32_t)r[2]<0?0xffffffffu:0)):r[2]<<(r[3]&31u);
goto P_0c0a0306;
P_0c0a0306: /* original 4400, guest PC 0x0c0a0306 */
if(!s->budget--) { s->failed_pc=0x0c0a0306u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a0308;
P_0c0a0308: /* original 242b, guest PC 0x0c0a0308 */
if(!s->budget--) { s->failed_pc=0x0c0a0308u; return 0; }
r[4]|=r[2];
goto P_0c0a030a;
P_0c0a030a: /* original d213, guest PC 0x0c0a030a */
if(!s->budget--) { s->failed_pc=0x0c0a030au; return 0; }
r[2]=read(ram,0x0c0a0358u,4);
goto P_0c0a030c;
P_0c0a030c: /* original 420b, guest PC 0x0c0a030c */
if(!s->budget--) { s->failed_pc=0x0c0a030cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a0310u;
r[5]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0310u) { target=s->pc; goto dispatch; }
goto P_0c0a0310;
P_0c0a030e: /* original 35ec, guest PC 0x0c0a030e */
if(!s->budget--) { s->failed_pc=0x0c0a030eu; return 0; }
r[5]+=r[14];
goto P_0c0a0310;
P_0c0a0310: /* original 55f9, guest PC 0x0c0a0310 */
if(!s->budget--) { s->failed_pc=0x0c0a0310u; return 0; }
r[5]=read(ram,r[15]+36,4);
goto P_0c0a0312;
P_0c0a0312: /* original e3fa, guest PC 0x0c0a0312 */
if(!s->budget--) { s->failed_pc=0x0c0a0312u; return 0; }
r[3]=0xfffffffau;
goto P_0c0a0314;
P_0c0a0314: /* original 9415, guest PC 0x0c0a0314 */
if(!s->budget--) { s->failed_pc=0x0c0a0314u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0342u,2);
goto P_0c0a0316;
P_0c0a0316: /* original 5553, guest PC 0x0c0a0316 */
if(!s->budget--) { s->failed_pc=0x0c0a0316u; return 0; }
r[5]=read(ram,r[5]+12,4);
goto P_0c0a0318;
P_0c0a0318: /* original 453c, guest PC 0x0c0a0318 */
if(!s->budget--) { s->failed_pc=0x0c0a0318u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c0a031a;
P_0c0a031a: /* original 2f56, guest PC 0x0c0a031a */
if(!s->budget--) { s->failed_pc=0x0c0a031au; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a031c;
P_0c0a031c: /* original d212, guest PC 0x0c0a031c */
if(!s->budget--) { s->failed_pc=0x0c0a031cu; return 0; }
r[2]=read(ram,0x0c0a0368u,4);
goto P_0c0a031e;
P_0c0a031e: /* original 4d0b, guest PC 0x0c0a031e */
if(!s->budget--) { s->failed_pc=0x0c0a031eu; return 0; }
target=r[13];
r[16]=code_base|0x0c0a0322u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0322u) { target=s->pc; goto dispatch; }
goto P_0c0a0322;
P_0c0a0320: /* original 2f26, guest PC 0x0c0a0320 */
if(!s->budget--) { s->failed_pc=0x0c0a0320u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0322;
P_0c0a0322: /* original 7f30, guest PC 0x0c0a0322 */
if(!s->budget--) { s->failed_pc=0x0c0a0322u; return 0; }
r[15]+=0x00000030u;
goto P_0c0a0324;
P_0c0a0324: /* original 4f26, guest PC 0x0c0a0324 */
if(!s->budget--) { s->failed_pc=0x0c0a0324u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a0326;
P_0c0a0326: /* original 6bf6, guest PC 0x0c0a0326 */
if(!s->budget--) { s->failed_pc=0x0c0a0326u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a0328;
P_0c0a0328: /* original 6cf6, guest PC 0x0c0a0328 */
if(!s->budget--) { s->failed_pc=0x0c0a0328u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a032a;
P_0c0a032a: /* original 6df6, guest PC 0x0c0a032a */
if(!s->budget--) { s->failed_pc=0x0c0a032au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a032c;
P_0c0a032c: /* original 000b, guest PC 0x0c0a032c */
if(!s->budget--) { s->failed_pc=0x0c0a032cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a032e: /* original 6ef6, guest PC 0x0c0a032e */
if(!s->budget--) { s->failed_pc=0x0c0a032eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a0330u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a0330u; return 0; } return 1;
P_0c0a036c: /* original 2fe6, guest PC 0x0c0a036c */
if(!s->budget--) { s->failed_pc=0x0c0a036cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a036e;
P_0c0a036e: /* original e606, guest PC 0x0c0a036e */
if(!s->budget--) { s->failed_pc=0x0c0a036eu; return 0; }
r[6]=0x00000006u;
goto P_0c0a0370;
P_0c0a0370: /* original 2fd6, guest PC 0x0c0a0370 */
if(!s->budget--) { s->failed_pc=0x0c0a0370u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0372;
P_0c0a0372: /* original e700, guest PC 0x0c0a0372 */
if(!s->budget--) { s->failed_pc=0x0c0a0372u; return 0; }
r[7]=0x00000000u;
goto P_0c0a0374;
P_0c0a0374: /* original 2fc6, guest PC 0x0c0a0374 */
if(!s->budget--) { s->failed_pc=0x0c0a0374u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0376;
P_0c0a0376: /* original 2fb6, guest PC 0x0c0a0376 */
if(!s->budget--) { s->failed_pc=0x0c0a0376u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0378;
P_0c0a0378: /* original d433, guest PC 0x0c0a0378 */
if(!s->budget--) { s->failed_pc=0x0c0a0378u; return 0; }
r[4]=read(ram,0x0c0a0448u,4);
goto P_0c0a037a;
P_0c0a037a: /* original 9063, guest PC 0x0c0a037a */
if(!s->budget--) { s->failed_pc=0x0c0a037au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0444u,2);
goto P_0c0a037c;
P_0c0a037c: /* original 4f22, guest PC 0x0c0a037c */
if(!s->budget--) { s->failed_pc=0x0c0a037cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a037e;
P_0c0a037e: /* original 054c, guest PC 0x0c0a037e */
if(!s->budget--) { s->failed_pc=0x0c0a037eu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a0380;
P_0c0a0380: /* original dc32, guest PC 0x0c0a0380 */
if(!s->budget--) { s->failed_pc=0x0c0a0380u; return 0; }
r[12]=read(ram,0x0c0a044cu,4);
goto P_0c0a0382;
P_0c0a0382: /* original 3563, guest PC 0x0c0a0382 */
if(!s->budget--) { s->failed_pc=0x0c0a0382u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c0a0384;
P_0c0a0384: /* original 8f08, guest PC 0x0c0a0384 */
if(!s->budget--) { s->failed_pc=0x0c0a0384u; return 0; }
cond=r[17]&1u;
r[14]=r[7];
if(!cond) { goto P_0c0a0398; }
goto P_0c0a0388;
P_0c0a0386: /* original 6e73, guest PC 0x0c0a0386 */
if(!s->budget--) { s->failed_pc=0x0c0a0386u; return 0; }
r[14]=r[7];
goto P_0c0a0388;
P_0c0a0388: /* original e50c, guest PC 0x0c0a0388 */
if(!s->budget--) { s->failed_pc=0x0c0a0388u; return 0; }
r[5]=0x0000000cu;
goto P_0c0a038a;
P_0c0a038a: /* original 6053, guest PC 0x0c0a038a */
if(!s->budget--) { s->failed_pc=0x0c0a038au; return 0; }
r[0]=r[5];
goto P_0c0a038c;
P_0c0a038c: /* original 707c, guest PC 0x0c0a038c */
if(!s->budget--) { s->failed_pc=0x0c0a038cu; return 0; }
r[0]+=0x0000007cu;
goto P_0c0a038e;
P_0c0a038e: /* original 034c, guest PC 0x0c0a038e */
if(!s->budget--) { s->failed_pc=0x0c0a038eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a0390;
P_0c0a0390: /* original 3353, guest PC 0x0c0a0390 */
if(!s->budget--) { s->failed_pc=0x0c0a0390u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[5])!=0);
goto P_0c0a0392;
P_0c0a0392: /* original 8f01, guest PC 0x0c0a0392 */
if(!s->budget--) { s->failed_pc=0x0c0a0392u; return 0; }
cond=r[17]&1u;
r[14]=r[6];
if(!cond) { goto P_0c0a0398; }
goto P_0c0a0396;
P_0c0a0394: /* original 6e63, guest PC 0x0c0a0394 */
if(!s->budget--) { s->failed_pc=0x0c0a0394u; return 0; }
r[14]=r[6];
goto P_0c0a0396;
P_0c0a0396: /* original 6e53, guest PC 0x0c0a0396 */
if(!s->budget--) { s->failed_pc=0x0c0a0396u; return 0; }
r[14]=r[5];
goto P_0c0a0398;
P_0c0a0398: /* original eb18, guest PC 0x0c0a0398 */
if(!s->budget--) { s->failed_pc=0x0c0a0398u; return 0; }
r[11]=0x00000018u;
goto P_0c0a039a;
P_0c0a039a: /* original a018, guest PC 0x0c0a039a */
if(!s->budget--) { s->failed_pc=0x0c0a039au; return 0; }
r[13]=r[7];
goto P_0c0a03ce;
P_0c0a039c: /* original 6d73, guest PC 0x0c0a039c */
if(!s->budget--) { s->failed_pc=0x0c0a039cu; return 0; }
r[13]=r[7];
goto P_0c0a039e;
P_0c0a039e: /* original 65e3, guest PC 0x0c0a039e */
if(!s->budget--) { s->failed_pc=0x0c0a039eu; return 0; }
r[5]=r[14];
goto P_0c0a03a0;
P_0c0a03a0: /* original b03d, guest PC 0x0c0a03a0 */
if(!s->budget--) { s->failed_pc=0x0c0a03a0u; return 0; }
target=code_base|0x0c0a041eu; r[16]=code_base|0x0c0a03a4u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a03a4u) { target=s->pc; goto dispatch; }
goto P_0c0a03a4;
P_0c0a03a2: /* original 64d3, guest PC 0x0c0a03a2 */
if(!s->budget--) { s->failed_pc=0x0c0a03a2u; return 0; }
r[4]=r[13];
goto P_0c0a03a4;
P_0c0a03a4: /* original 65e3, guest PC 0x0c0a03a4 */
if(!s->budget--) { s->failed_pc=0x0c0a03a4u; return 0; }
r[5]=r[14];
goto P_0c0a03a6;
P_0c0a03a6: /* original 63c3, guest PC 0x0c0a03a6 */
if(!s->budget--) { s->failed_pc=0x0c0a03a6u; return 0; }
r[3]=r[12];
goto P_0c0a03a8;
P_0c0a03a8: /* original 4508, guest PC 0x0c0a03a8 */
if(!s->budget--) { s->failed_pc=0x0c0a03a8u; return 0; }
r[5]<<=2;
goto P_0c0a03aa;
P_0c0a03aa: /* original 353c, guest PC 0x0c0a03aa */
if(!s->budget--) { s->failed_pc=0x0c0a03aau; return 0; }
r[5]+=r[3];
goto P_0c0a03ac;
P_0c0a03ac: /* original b056, guest PC 0x0c0a03ac */
if(!s->budget--) { s->failed_pc=0x0c0a03acu; return 0; }
target=code_base|0x0c0a045cu; r[16]=code_base|0x0c0a03b0u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a03b0u) { target=s->pc; goto dispatch; }
goto P_0c0a03b0;
P_0c0a03ae: /* original 64d3, guest PC 0x0c0a03ae */
if(!s->budget--) { s->failed_pc=0x0c0a03aeu; return 0; }
r[4]=r[13];
goto P_0c0a03b0;
P_0c0a03b0: /* original 63c3, guest PC 0x0c0a03b0 */
if(!s->budget--) { s->failed_pc=0x0c0a03b0u; return 0; }
r[3]=r[12];
goto P_0c0a03b2;
P_0c0a03b2: /* original 65e3, guest PC 0x0c0a03b2 */
if(!s->budget--) { s->failed_pc=0x0c0a03b2u; return 0; }
r[5]=r[14];
goto P_0c0a03b4;
P_0c0a03b4: /* original 7348, guest PC 0x0c0a03b4 */
if(!s->budget--) { s->failed_pc=0x0c0a03b4u; return 0; }
r[3]+=0x00000048u;
goto P_0c0a03b6;
P_0c0a03b6: /* original 4508, guest PC 0x0c0a03b6 */
if(!s->budget--) { s->failed_pc=0x0c0a03b6u; return 0; }
r[5]<<=2;
goto P_0c0a03b8;
P_0c0a03b8: /* original 353c, guest PC 0x0c0a03b8 */
if(!s->budget--) { s->failed_pc=0x0c0a03b8u; return 0; }
r[5]+=r[3];
goto P_0c0a03ba;
P_0c0a03ba: /* original b08f, guest PC 0x0c0a03ba */
if(!s->budget--) { s->failed_pc=0x0c0a03bau; return 0; }
target=code_base|0x0c0a04dcu; r[16]=code_base|0x0c0a03beu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a03beu) { target=s->pc; goto dispatch; }
goto P_0c0a03be;
P_0c0a03bc: /* original 64d3, guest PC 0x0c0a03bc */
if(!s->budget--) { s->failed_pc=0x0c0a03bcu; return 0; }
r[4]=r[13];
goto P_0c0a03be;
P_0c0a03be: /* original 9642, guest PC 0x0c0a03be */
if(!s->budget--) { s->failed_pc=0x0c0a03beu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0446u,2);
goto P_0c0a03c0;
P_0c0a03c0: /* original 65e3, guest PC 0x0c0a03c0 */
if(!s->budget--) { s->failed_pc=0x0c0a03c0u; return 0; }
r[5]=r[14];
goto P_0c0a03c2;
P_0c0a03c2: /* original 36cc, guest PC 0x0c0a03c2 */
if(!s->budget--) { s->failed_pc=0x0c0a03c2u; return 0; }
r[6]+=r[12];
goto P_0c0a03c4;
P_0c0a03c4: /* original 36ec, guest PC 0x0c0a03c4 */
if(!s->budget--) { s->failed_pc=0x0c0a03c4u; return 0; }
r[6]+=r[14];
goto P_0c0a03c6;
P_0c0a03c6: /* original b0e1, guest PC 0x0c0a03c6 */
if(!s->budget--) { s->failed_pc=0x0c0a03c6u; return 0; }
target=code_base|0x0c0a058cu; r[16]=code_base|0x0c0a03cau;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a03cau) { target=s->pc; goto dispatch; }
goto P_0c0a03ca;
P_0c0a03c8: /* original 64d3, guest PC 0x0c0a03c8 */
if(!s->budget--) { s->failed_pc=0x0c0a03c8u; return 0; }
r[4]=r[13];
goto P_0c0a03ca;
P_0c0a03ca: /* original 7e01, guest PC 0x0c0a03ca */
if(!s->budget--) { s->failed_pc=0x0c0a03cau; return 0; }
r[14]+=0x00000001u;
goto P_0c0a03cc;
P_0c0a03cc: /* original 7d04, guest PC 0x0c0a03cc */
if(!s->budget--) { s->failed_pc=0x0c0a03ccu; return 0; }
r[13]+=0x00000004u;
goto P_0c0a03ce;
P_0c0a03ce: /* original 3db3, guest PC 0x0c0a03ce */
if(!s->budget--) { s->failed_pc=0x0c0a03ceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[11])!=0);
goto P_0c0a03d0;
P_0c0a03d0: /* original 8be5, guest PC 0x0c0a03d0 */
if(!s->budget--) { s->failed_pc=0x0c0a03d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a039e; }
goto P_0c0a03d2;
P_0c0a03d2: /* original 4f26, guest PC 0x0c0a03d2 */
if(!s->budget--) { s->failed_pc=0x0c0a03d2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a03d4;
P_0c0a03d4: /* original 6bf6, guest PC 0x0c0a03d4 */
if(!s->budget--) { s->failed_pc=0x0c0a03d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a03d6;
P_0c0a03d6: /* original 6cf6, guest PC 0x0c0a03d6 */
if(!s->budget--) { s->failed_pc=0x0c0a03d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a03d8;
P_0c0a03d8: /* original 6df6, guest PC 0x0c0a03d8 */
if(!s->budget--) { s->failed_pc=0x0c0a03d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a03da;
P_0c0a03da: /* original 000b, guest PC 0x0c0a03da */
if(!s->budget--) { s->failed_pc=0x0c0a03dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a03dc: /* original 6ef6, guest PC 0x0c0a03dc */
if(!s->budget--) { s->failed_pc=0x0c0a03dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a03deu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a03deu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
