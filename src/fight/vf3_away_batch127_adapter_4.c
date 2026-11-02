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
int vf3_away_batch127_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c0a03deu: goto P_0c0a03de;
case 0x0c0a03e0u: goto P_0c0a03e0;
case 0x0c0a03e2u: goto P_0c0a03e2;
case 0x0c0a03e4u: goto P_0c0a03e4;
case 0x0c0a03e6u: goto P_0c0a03e6;
case 0x0c0a03e8u: goto P_0c0a03e8;
case 0x0c0a03eau: goto P_0c0a03ea;
case 0x0c0a03ecu: goto P_0c0a03ec;
case 0x0c0a03eeu: goto P_0c0a03ee;
case 0x0c0a03f0u: goto P_0c0a03f0;
case 0x0c0a03f2u: goto P_0c0a03f2;
case 0x0c0a03f4u: goto P_0c0a03f4;
case 0x0c0a03f6u: goto P_0c0a03f6;
case 0x0c0a03f8u: goto P_0c0a03f8;
case 0x0c0a03fau: goto P_0c0a03fa;
case 0x0c0a03fcu: goto P_0c0a03fc;
case 0x0c0a03feu: goto P_0c0a03fe;
case 0x0c0a0400u: goto P_0c0a0400;
case 0x0c0a0402u: goto P_0c0a0402;
case 0x0c0a0404u: goto P_0c0a0404;
case 0x0c0a0406u: goto P_0c0a0406;
case 0x0c0a0408u: goto P_0c0a0408;
case 0x0c0a040au: goto P_0c0a040a;
case 0x0c0a040cu: goto P_0c0a040c;
case 0x0c0a040eu: goto P_0c0a040e;
case 0x0c0a0410u: goto P_0c0a0410;
case 0x0c0a0412u: goto P_0c0a0412;
case 0x0c0a0414u: goto P_0c0a0414;
case 0x0c0a0416u: goto P_0c0a0416;
case 0x0c0a0418u: goto P_0c0a0418;
case 0x0c0a041au: goto P_0c0a041a;
case 0x0c0a041cu: goto P_0c0a041c;
case 0x0c0a041eu: goto P_0c0a041e;
case 0x0c0a0420u: goto P_0c0a0420;
case 0x0c0a0422u: goto P_0c0a0422;
case 0x0c0a0424u: goto P_0c0a0424;
case 0x0c0a0426u: goto P_0c0a0426;
case 0x0c0a0428u: goto P_0c0a0428;
case 0x0c0a042au: goto P_0c0a042a;
case 0x0c0a042cu: goto P_0c0a042c;
case 0x0c0a042eu: goto P_0c0a042e;
case 0x0c0a0430u: goto P_0c0a0430;
case 0x0c0a0432u: goto P_0c0a0432;
case 0x0c0a0434u: goto P_0c0a0434;
case 0x0c0a0436u: goto P_0c0a0436;
case 0x0c0a0438u: goto P_0c0a0438;
case 0x0c0a043au: goto P_0c0a043a;
case 0x0c0a043cu: goto P_0c0a043c;
case 0x0c0a043eu: goto P_0c0a043e;
case 0x0c0a0440u: goto P_0c0a0440;
case 0x0c0a0442u: goto P_0c0a0442;
case 0x0c0a04dcu: goto P_0c0a04dc;
case 0x0c0a04deu: goto P_0c0a04de;
case 0x0c0a04e0u: goto P_0c0a04e0;
case 0x0c0a04e2u: goto P_0c0a04e2;
case 0x0c0a04e4u: goto P_0c0a04e4;
case 0x0c0a04e6u: goto P_0c0a04e6;
case 0x0c0a04e8u: goto P_0c0a04e8;
case 0x0c0a04eau: goto P_0c0a04ea;
case 0x0c0a04ecu: goto P_0c0a04ec;
case 0x0c0a04eeu: goto P_0c0a04ee;
case 0x0c0a04f0u: goto P_0c0a04f0;
case 0x0c0a04f2u: goto P_0c0a04f2;
case 0x0c0a04f4u: goto P_0c0a04f4;
case 0x0c0a04f6u: goto P_0c0a04f6;
case 0x0c0a04f8u: goto P_0c0a04f8;
case 0x0c0a04fau: goto P_0c0a04fa;
case 0x0c0a04fcu: goto P_0c0a04fc;
case 0x0c0a04feu: goto P_0c0a04fe;
case 0x0c0a0500u: goto P_0c0a0500;
case 0x0c0a0502u: goto P_0c0a0502;
case 0x0c0a0504u: goto P_0c0a0504;
case 0x0c0a0506u: goto P_0c0a0506;
case 0x0c0a0508u: goto P_0c0a0508;
case 0x0c0a050au: goto P_0c0a050a;
case 0x0c0a050cu: goto P_0c0a050c;
case 0x0c0a050eu: goto P_0c0a050e;
case 0x0c0a0510u: goto P_0c0a0510;
case 0x0c0a0512u: goto P_0c0a0512;
case 0x0c0a0514u: goto P_0c0a0514;
case 0x0c0a0516u: goto P_0c0a0516;
case 0x0c0a0518u: goto P_0c0a0518;
case 0x0c0a051au: goto P_0c0a051a;
case 0x0c0a051cu: goto P_0c0a051c;
case 0x0c0a051eu: goto P_0c0a051e;
case 0x0c0a0520u: goto P_0c0a0520;
case 0x0c0a0522u: goto P_0c0a0522;
case 0x0c0a0524u: goto P_0c0a0524;
case 0x0c0a0526u: goto P_0c0a0526;
case 0x0c0a0528u: goto P_0c0a0528;
case 0x0c0a052au: goto P_0c0a052a;
case 0x0c0a052cu: goto P_0c0a052c;
case 0x0c0a052eu: goto P_0c0a052e;
case 0x0c0a0530u: goto P_0c0a0530;
case 0x0c0a0532u: goto P_0c0a0532;
case 0x0c0a0534u: goto P_0c0a0534;
case 0x0c0a0536u: goto P_0c0a0536;
case 0x0c0a0538u: goto P_0c0a0538;
case 0x0c0a053au: goto P_0c0a053a;
case 0x0c0a053cu: goto P_0c0a053c;
case 0x0c0a053eu: goto P_0c0a053e;
case 0x0c0a0540u: goto P_0c0a0540;
case 0x0c0a0542u: goto P_0c0a0542;
case 0x0c0a0544u: goto P_0c0a0544;
case 0x0c0a0546u: goto P_0c0a0546;
case 0x0c0a0548u: goto P_0c0a0548;
case 0x0c0a054au: goto P_0c0a054a;
case 0x0c0a054cu: goto P_0c0a054c;
case 0x0c0a054eu: goto P_0c0a054e;
case 0x0c0a0550u: goto P_0c0a0550;
case 0x0c0a0552u: goto P_0c0a0552;
case 0x0c0a0554u: goto P_0c0a0554;
case 0x0c0a0556u: goto P_0c0a0556;
case 0x0c0a0558u: goto P_0c0a0558;
case 0x0c0a055au: goto P_0c0a055a;
case 0x0c0a055cu: goto P_0c0a055c;
case 0x0c0a055eu: goto P_0c0a055e;
case 0x0c0a0560u: goto P_0c0a0560;
case 0x0c0a0562u: goto P_0c0a0562;
case 0x0c0a0564u: goto P_0c0a0564;
case 0x0c0a0566u: goto P_0c0a0566;
case 0x0c0a0568u: goto P_0c0a0568;
case 0x0c0a056au: goto P_0c0a056a;
case 0x0c0a056cu: goto P_0c0a056c;
case 0x0c0a056eu: goto P_0c0a056e;
case 0x0c0a0570u: goto P_0c0a0570;
case 0x0c0a0572u: goto P_0c0a0572;
case 0x0c0a0574u: goto P_0c0a0574;
case 0x0c0a0576u: goto P_0c0a0576;
case 0x0c0a0578u: goto P_0c0a0578;
case 0x0c0a057au: goto P_0c0a057a;
case 0x0c0a057cu: goto P_0c0a057c;
case 0x0c0a057eu: goto P_0c0a057e;
case 0x0c0a0580u: goto P_0c0a0580;
case 0x0c0a0582u: goto P_0c0a0582;
case 0x0c0a0584u: goto P_0c0a0584;
case 0x0c0a0586u: goto P_0c0a0586;
case 0x0c0a0588u: goto P_0c0a0588;
case 0x0c0a058au: goto P_0c0a058a;
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
P_0c0a03de: /* original 2fe6, guest PC 0x0c0a03de */
if(!s->budget--) { s->failed_pc=0x0c0a03deu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a03e0;
P_0c0a03e0: /* original 2fd6, guest PC 0x0c0a03e0 */
if(!s->budget--) { s->failed_pc=0x0c0a03e0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a03e2;
P_0c0a03e2: /* original 2fc6, guest PC 0x0c0a03e2 */
if(!s->budget--) { s->failed_pc=0x0c0a03e2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a03e4;
P_0c0a03e4: /* original ec1f, guest PC 0x0c0a03e4 */
if(!s->budget--) { s->failed_pc=0x0c0a03e4u; return 0; }
r[12]=0x0000001fu;
goto P_0c0a03e6;
P_0c0a03e6: /* original d31a, guest PC 0x0c0a03e6 */
if(!s->budget--) { s->failed_pc=0x0c0a03e6u; return 0; }
r[3]=read(ram,0x0c0a0450u,4);
goto P_0c0a03e8;
P_0c0a03e8: /* original d417, guest PC 0x0c0a03e8 */
if(!s->budget--) { s->failed_pc=0x0c0a03e8u; return 0; }
r[4]=read(ram,0x0c0a0448u,4);
goto P_0c0a03ea;
P_0c0a03ea: /* original 902b, guest PC 0x0c0a03ea */
if(!s->budget--) { s->failed_pc=0x0c0a03eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0444u,2);
goto P_0c0a03ec;
P_0c0a03ec: /* original 6532, guest PC 0x0c0a03ec */
if(!s->budget--) { s->failed_pc=0x0c0a03ecu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c0a03ee;
P_0c0a03ee: /* original 0e4c, guest PC 0x0c0a03ee */
if(!s->budget--) { s->failed_pc=0x0c0a03eeu; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a03f0;
P_0c0a03f0: /* original 4f22, guest PC 0x0c0a03f0 */
if(!s->budget--) { s->failed_pc=0x0c0a03f0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a03f2;
P_0c0a03f2: /* original 3c58, guest PC 0x0c0a03f2 */
if(!s->budget--) { s->failed_pc=0x0c0a03f2u; return 0; }
r[12]-=r[5];
goto P_0c0a03f4;
P_0c0a03f4: /* original dd15, guest PC 0x0c0a03f4 */
if(!s->budget--) { s->failed_pc=0x0c0a03f4u; return 0; }
r[13]=read(ram,0x0c0a044cu,4);
goto P_0c0a03f6;
P_0c0a03f6: /* original 65e3, guest PC 0x0c0a03f6 */
if(!s->budget--) { s->failed_pc=0x0c0a03f6u; return 0; }
r[5]=r[14];
goto P_0c0a03f8;
P_0c0a03f8: /* original b011, guest PC 0x0c0a03f8 */
if(!s->budget--) { s->failed_pc=0x0c0a03f8u; return 0; }
target=code_base|0x0c0a041eu; r[16]=code_base|0x0c0a03fcu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a03fcu) { target=s->pc; goto dispatch; }
goto P_0c0a03fc;
P_0c0a03fa: /* original 64c3, guest PC 0x0c0a03fa */
if(!s->budget--) { s->failed_pc=0x0c0a03fau; return 0; }
r[4]=r[12];
goto P_0c0a03fc;
P_0c0a03fc: /* original 63d3, guest PC 0x0c0a03fc */
if(!s->budget--) { s->failed_pc=0x0c0a03fcu; return 0; }
r[3]=r[13];
goto P_0c0a03fe;
P_0c0a03fe: /* original 65e3, guest PC 0x0c0a03fe */
if(!s->budget--) { s->failed_pc=0x0c0a03feu; return 0; }
r[5]=r[14];
goto P_0c0a0400;
P_0c0a0400: /* original 7348, guest PC 0x0c0a0400 */
if(!s->budget--) { s->failed_pc=0x0c0a0400u; return 0; }
r[3]+=0x00000048u;
goto P_0c0a0402;
P_0c0a0402: /* original 4508, guest PC 0x0c0a0402 */
if(!s->budget--) { s->failed_pc=0x0c0a0402u; return 0; }
r[5]<<=2;
goto P_0c0a0404;
P_0c0a0404: /* original 353c, guest PC 0x0c0a0404 */
if(!s->budget--) { s->failed_pc=0x0c0a0404u; return 0; }
r[5]+=r[3];
goto P_0c0a0406;
P_0c0a0406: /* original b069, guest PC 0x0c0a0406 */
if(!s->budget--) { s->failed_pc=0x0c0a0406u; return 0; }
target=code_base|0x0c0a04dcu; r[16]=code_base|0x0c0a040au;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a040au) { target=s->pc; goto dispatch; }
goto P_0c0a040a;
P_0c0a0408: /* original 64c3, guest PC 0x0c0a0408 */
if(!s->budget--) { s->failed_pc=0x0c0a0408u; return 0; }
r[4]=r[12];
goto P_0c0a040a;
P_0c0a040a: /* original 4f26, guest PC 0x0c0a040a */
if(!s->budget--) { s->failed_pc=0x0c0a040au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a040c;
P_0c0a040c: /* original 64c3, guest PC 0x0c0a040c */
if(!s->budget--) { s->failed_pc=0x0c0a040cu; return 0; }
r[4]=r[12];
goto P_0c0a040e;
P_0c0a040e: /* original 961a, guest PC 0x0c0a040e */
if(!s->budget--) { s->failed_pc=0x0c0a040eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0446u,2);
goto P_0c0a0410;
P_0c0a0410: /* original 65e3, guest PC 0x0c0a0410 */
if(!s->budget--) { s->failed_pc=0x0c0a0410u; return 0; }
r[5]=r[14];
goto P_0c0a0412;
P_0c0a0412: /* original 6cf6, guest PC 0x0c0a0412 */
if(!s->budget--) { s->failed_pc=0x0c0a0412u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a0414;
P_0c0a0414: /* original 36dc, guest PC 0x0c0a0414 */
if(!s->budget--) { s->failed_pc=0x0c0a0414u; return 0; }
r[6]+=r[13];
goto P_0c0a0416;
P_0c0a0416: /* original 36ec, guest PC 0x0c0a0416 */
if(!s->budget--) { s->failed_pc=0x0c0a0416u; return 0; }
r[6]+=r[14];
goto P_0c0a0418;
P_0c0a0418: /* original 6df6, guest PC 0x0c0a0418 */
if(!s->budget--) { s->failed_pc=0x0c0a0418u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a041a;
P_0c0a041a: /* original a0b7, guest PC 0x0c0a041a */
if(!s->budget--) { s->failed_pc=0x0c0a041au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a058cu,s,ram);
P_0c0a041c: /* original 6ef6, guest PC 0x0c0a041c */
if(!s->budget--) { s->failed_pc=0x0c0a041cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a041e;
P_0c0a041e: /* original 4f22, guest PC 0x0c0a041e */
if(!s->budget--) { s->failed_pc=0x0c0a041eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a0420;
P_0c0a0420: /* original 6153, guest PC 0x0c0a0420 */
if(!s->budget--) { s->failed_pc=0x0c0a0420u; return 0; }
r[1]=r[5];
goto P_0c0a0422;
P_0c0a0422: /* original 7101, guest PC 0x0c0a0422 */
if(!s->budget--) { s->failed_pc=0x0c0a0422u; return 0; }
r[1]+=0x00000001u;
goto P_0c0a0424;
P_0c0a0424: /* original e307, guest PC 0x0c0a0424 */
if(!s->budget--) { s->failed_pc=0x0c0a0424u; return 0; }
r[3]=0x00000007u;
goto P_0c0a0426;
P_0c0a0426: /* original 7ffc, guest PC 0x0c0a0426 */
if(!s->budget--) { s->failed_pc=0x0c0a0426u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a0428;
P_0c0a0428: /* original 2f52, guest PC 0x0c0a0428 */
if(!s->budget--) { s->failed_pc=0x0c0a0428u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0a042a;
P_0c0a042a: /* original 740c, guest PC 0x0c0a042a */
if(!s->budget--) { s->failed_pc=0x0c0a042au; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a042c;
P_0c0a042c: /* original 2f16, guest PC 0x0c0a042c */
if(!s->budget--) { s->failed_pc=0x0c0a042cu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a042e;
P_0c0a042e: /* original 443c, guest PC 0x0c0a042e */
if(!s->budget--) { s->failed_pc=0x0c0a042eu; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c0a0430;
P_0c0a0430: /* original d309, guest PC 0x0c0a0430 */
if(!s->budget--) { s->failed_pc=0x0c0a0430u; return 0; }
r[3]=read(ram,0x0c0a0458u,4);
goto P_0c0a0432;
P_0c0a0432: /* original e20e, guest PC 0x0c0a0432 */
if(!s->budget--) { s->failed_pc=0x0c0a0432u; return 0; }
r[2]=0x0000000eu;
goto P_0c0a0434;
P_0c0a0434: /* original d107, guest PC 0x0c0a0434 */
if(!s->budget--) { s->failed_pc=0x0c0a0434u; return 0; }
r[1]=read(ram,0x0c0a0454u,4);
goto P_0c0a0436;
P_0c0a0436: /* original 242b, guest PC 0x0c0a0436 */
if(!s->budget--) { s->failed_pc=0x0c0a0436u; return 0; }
r[4]|=r[2];
goto P_0c0a0438;
P_0c0a0438: /* original 430b, guest PC 0x0c0a0438 */
if(!s->budget--) { s->failed_pc=0x0c0a0438u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a043cu;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a043cu) { target=s->pc; goto dispatch; }
goto P_0c0a043c;
P_0c0a043a: /* original 2f16, guest PC 0x0c0a043a */
if(!s->budget--) { s->failed_pc=0x0c0a043au; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a043c;
P_0c0a043c: /* original 7f0c, guest PC 0x0c0a043c */
if(!s->budget--) { s->failed_pc=0x0c0a043cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a043e;
P_0c0a043e: /* original 4f26, guest PC 0x0c0a043e */
if(!s->budget--) { s->failed_pc=0x0c0a043eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a0440;
P_0c0a0440: /* original 000b, guest PC 0x0c0a0440 */
if(!s->budget--) { s->failed_pc=0x0c0a0440u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a0442: /* original 0009, guest PC 0x0c0a0442 */
if(!s->budget--) { s->failed_pc=0x0c0a0442u; return 0; }
if(!vf3_matrix_family(0x0c0a0444u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a0444u; return 0; } return 1;
P_0c0a04dc: /* original 2fe6, guest PC 0x0c0a04dc */
if(!s->budget--) { s->failed_pc=0x0c0a04dcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a04de;
P_0c0a04de: /* original 2fd6, guest PC 0x0c0a04de */
if(!s->budget--) { s->failed_pc=0x0c0a04deu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a04e0;
P_0c0a04e0: /* original 2fc6, guest PC 0x0c0a04e0 */
if(!s->budget--) { s->failed_pc=0x0c0a04e0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a04e2;
P_0c0a04e2: /* original 4f22, guest PC 0x0c0a04e2 */
if(!s->budget--) { s->failed_pc=0x0c0a04e2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a04e4;
P_0c0a04e4: /* original 4f12, guest PC 0x0c0a04e4 */
if(!s->budget--) { s->failed_pc=0x0c0a04e4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a04e6;
P_0c0a04e6: /* original 7ff8, guest PC 0x0c0a04e6 */
if(!s->budget--) { s->failed_pc=0x0c0a04e6u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a04e8;
P_0c0a04e8: /* original 2f42, guest PC 0x0c0a04e8 */
if(!s->budget--) { s->failed_pc=0x0c0a04e8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a04ea;
P_0c0a04ea: /* original 1f51, guest PC 0x0c0a04ea */
if(!s->budget--) { s->failed_pc=0x0c0a04eau; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0a04ec;
P_0c0a04ec: /* original d33b, guest PC 0x0c0a04ec */
if(!s->budget--) { s->failed_pc=0x0c0a04ecu; return 0; }
r[3]=read(ram,0x0c0a05dcu,4);
goto P_0c0a04ee;
P_0c0a04ee: /* original 430b, guest PC 0x0c0a04ee */
if(!s->budget--) { s->failed_pc=0x0c0a04eeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a04f2u;
r[4]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a04f2u) { target=s->pc; goto dispatch; }
goto P_0c0a04f2;
P_0c0a04f0: /* original 6453, guest PC 0x0c0a04f0 */
if(!s->budget--) { s->failed_pc=0x0c0a04f0u; return 0; }
r[4]=r[5];
goto P_0c0a04f2;
P_0c0a04f2: /* original ee3f, guest PC 0x0c0a04f2 */
if(!s->budget--) { s->failed_pc=0x0c0a04f2u; return 0; }
r[14]=0x0000003fu;
goto P_0c0a04f4;
P_0c0a04f4: /* original 6403, guest PC 0x0c0a04f4 */
if(!s->budget--) { s->failed_pc=0x0c0a04f4u; return 0; }
r[4]=r[0];
goto P_0c0a04f6;
P_0c0a04f6: /* original 2e49, guest PC 0x0c0a04f6 */
if(!s->budget--) { s->failed_pc=0x0c0a04f6u; return 0; }
r[14]&=r[4];
goto P_0c0a04f8;
P_0c0a04f8: /* original e264, guest PC 0x0c0a04f8 */
if(!s->budget--) { s->failed_pc=0x0c0a04f8u; return 0; }
r[2]=0x00000064u;
goto P_0c0a04fa;
P_0c0a04fa: /* original 0e27, guest PC 0x0c0a04fa */
if(!s->budget--) { s->failed_pc=0x0c0a04fau; return 0; }
r[19]=r[14]*r[2];
goto P_0c0a04fc;
P_0c0a04fc: /* original e3fa, guest PC 0x0c0a04fc */
if(!s->budget--) { s->failed_pc=0x0c0a04fcu; return 0; }
r[3]=0xfffffffau;
goto P_0c0a04fe;
P_0c0a04fe: /* original e50a, guest PC 0x0c0a04fe */
if(!s->budget--) { s->failed_pc=0x0c0a04feu; return 0; }
r[5]=0x0000000au;
goto P_0c0a0500;
P_0c0a0500: /* original e73c, guest PC 0x0c0a0500 */
if(!s->budget--) { s->failed_pc=0x0c0a0500u; return 0; }
r[7]=0x0000003cu;
goto P_0c0a0502;
P_0c0a0502: /* original 0e1a, guest PC 0x0c0a0502 */
if(!s->budget--) { s->failed_pc=0x0c0a0502u; return 0; }
r[14]=r[19];
goto P_0c0a0504;
P_0c0a0504: /* original 4e3c, guest PC 0x0c0a0504 */
if(!s->budget--) { s->failed_pc=0x0c0a0504u; return 0; }
r[14]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[14]>>((-r[3])&31u)):((int32_t)r[14]<0?0xffffffffu:0)):r[14]<<(r[3]&31u);
goto P_0c0a0506;
P_0c0a0506: /* original d338, guest PC 0x0c0a0506 */
if(!s->budget--) { s->failed_pc=0x0c0a0506u; return 0; }
r[3]=read(ram,0x0c0a05e8u,4);
goto P_0c0a0508;
P_0c0a0508: /* original 61e3, guest PC 0x0c0a0508 */
if(!s->budget--) { s->failed_pc=0x0c0a0508u; return 0; }
r[1]=r[14];
goto P_0c0a050a;
P_0c0a050a: /* original 430b, guest PC 0x0c0a050a */
if(!s->budget--) { s->failed_pc=0x0c0a050au; return 0; }
target=r[3];
r[16]=code_base|0x0c0a050eu;
r[0]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a050eu) { target=s->pc; goto dispatch; }
goto P_0c0a050e;
P_0c0a050c: /* original 6053, guest PC 0x0c0a050c */
if(!s->budget--) { s->failed_pc=0x0c0a050cu; return 0; }
r[0]=r[5];
goto P_0c0a050e;
P_0c0a050e: /* original 6103, guest PC 0x0c0a050e */
if(!s->budget--) { s->failed_pc=0x0c0a050eu; return 0; }
r[1]=r[0];
goto P_0c0a0510;
P_0c0a0510: /* original 4108, guest PC 0x0c0a0510 */
if(!s->budget--) { s->failed_pc=0x0c0a0510u; return 0; }
r[1]<<=2;
goto P_0c0a0512;
P_0c0a0512: /* original 6303, guest PC 0x0c0a0512 */
if(!s->budget--) { s->failed_pc=0x0c0a0512u; return 0; }
r[3]=r[0];
goto P_0c0a0514;
P_0c0a0514: /* original 313c, guest PC 0x0c0a0514 */
if(!s->budget--) { s->failed_pc=0x0c0a0514u; return 0; }
r[1]+=r[3];
goto P_0c0a0516;
P_0c0a0516: /* original e3fa, guest PC 0x0c0a0516 */
if(!s->budget--) { s->failed_pc=0x0c0a0516u; return 0; }
r[3]=0xfffffffau;
goto P_0c0a0518;
P_0c0a0518: /* original 6c03, guest PC 0x0c0a0518 */
if(!s->budget--) { s->failed_pc=0x0c0a0518u; return 0; }
r[12]=r[0];
goto P_0c0a051a;
P_0c0a051a: /* original 443c, guest PC 0x0c0a051a */
if(!s->budget--) { s->failed_pc=0x0c0a051au; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c0a051c;
P_0c0a051c: /* original d332, guest PC 0x0c0a051c */
if(!s->budget--) { s->failed_pc=0x0c0a051cu; return 0; }
r[3]=read(ram,0x0c0a05e8u,4);
goto P_0c0a051e;
P_0c0a051e: /* original 4100, guest PC 0x0c0a051e */
if(!s->budget--) { s->failed_pc=0x0c0a051eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0a0520;
P_0c0a0520: /* original 3e18, guest PC 0x0c0a0520 */
if(!s->budget--) { s->failed_pc=0x0c0a0520u; return 0; }
r[14]-=r[1];
goto P_0c0a0522;
P_0c0a0522: /* original 6143, guest PC 0x0c0a0522 */
if(!s->budget--) { s->failed_pc=0x0c0a0522u; return 0; }
r[1]=r[4];
goto P_0c0a0524;
P_0c0a0524: /* original 430b, guest PC 0x0c0a0524 */
if(!s->budget--) { s->failed_pc=0x0c0a0524u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a0528u;
r[0]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0528u) { target=s->pc; goto dispatch; }
goto P_0c0a0528;
P_0c0a0526: /* original 6073, guest PC 0x0c0a0526 */
if(!s->budget--) { s->failed_pc=0x0c0a0526u; return 0; }
r[0]=r[7];
goto P_0c0a0528;
P_0c0a0528: /* original 6603, guest PC 0x0c0a0528 */
if(!s->budget--) { s->failed_pc=0x0c0a0528u; return 0; }
r[6]=r[0];
goto P_0c0a052a;
P_0c0a052a: /* original 6d43, guest PC 0x0c0a052a */
if(!s->budget--) { s->failed_pc=0x0c0a052au; return 0; }
r[13]=r[4];
goto P_0c0a052c;
P_0c0a052c: /* original 0677, guest PC 0x0c0a052c */
if(!s->budget--) { s->failed_pc=0x0c0a052cu; return 0; }
r[19]=r[6]*r[7];
goto P_0c0a052e;
P_0c0a052e: /* original d32e, guest PC 0x0c0a052e */
if(!s->budget--) { s->failed_pc=0x0c0a052eu; return 0; }
r[3]=read(ram,0x0c0a05e8u,4);
goto P_0c0a0530;
P_0c0a0530: /* original 071a, guest PC 0x0c0a0530 */
if(!s->budget--) { s->failed_pc=0x0c0a0530u; return 0; }
r[7]=r[19];
goto P_0c0a0532;
P_0c0a0532: /* original 3d78, guest PC 0x0c0a0532 */
if(!s->budget--) { s->failed_pc=0x0c0a0532u; return 0; }
r[13]-=r[7];
goto P_0c0a0534;
P_0c0a0534: /* original 61d3, guest PC 0x0c0a0534 */
if(!s->budget--) { s->failed_pc=0x0c0a0534u; return 0; }
r[1]=r[13];
goto P_0c0a0536;
P_0c0a0536: /* original 430b, guest PC 0x0c0a0536 */
if(!s->budget--) { s->failed_pc=0x0c0a0536u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a053au;
r[0]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a053au) { target=s->pc; goto dispatch; }
goto P_0c0a053a;
P_0c0a0538: /* original 6053, guest PC 0x0c0a0538 */
if(!s->budget--) { s->failed_pc=0x0c0a0538u; return 0; }
r[0]=r[5];
goto P_0c0a053a;
P_0c0a053a: /* original 6103, guest PC 0x0c0a053a */
if(!s->budget--) { s->failed_pc=0x0c0a053au; return 0; }
r[1]=r[0];
goto P_0c0a053c;
P_0c0a053c: /* original 4108, guest PC 0x0c0a053c */
if(!s->budget--) { s->failed_pc=0x0c0a053cu; return 0; }
r[1]<<=2;
goto P_0c0a053e;
P_0c0a053e: /* original 6303, guest PC 0x0c0a053e */
if(!s->budget--) { s->failed_pc=0x0c0a053eu; return 0; }
r[3]=r[0];
goto P_0c0a0540;
P_0c0a0540: /* original 313c, guest PC 0x0c0a0540 */
if(!s->budget--) { s->failed_pc=0x0c0a0540u; return 0; }
r[1]+=r[3];
goto P_0c0a0542;
P_0c0a0542: /* original 4100, guest PC 0x0c0a0542 */
if(!s->budget--) { s->failed_pc=0x0c0a0542u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0a0544;
P_0c0a0544: /* original d328, guest PC 0x0c0a0544 */
if(!s->budget--) { s->failed_pc=0x0c0a0544u; return 0; }
r[3]=read(ram,0x0c0a05e8u,4);
goto P_0c0a0546;
P_0c0a0546: /* original 3d18, guest PC 0x0c0a0546 */
if(!s->budget--) { s->failed_pc=0x0c0a0546u; return 0; }
r[13]-=r[1];
goto P_0c0a0548;
P_0c0a0548: /* original 6703, guest PC 0x0c0a0548 */
if(!s->budget--) { s->failed_pc=0x0c0a0548u; return 0; }
r[7]=r[0];
goto P_0c0a054a;
P_0c0a054a: /* original 6163, guest PC 0x0c0a054a */
if(!s->budget--) { s->failed_pc=0x0c0a054au; return 0; }
r[1]=r[6];
goto P_0c0a054c;
P_0c0a054c: /* original 430b, guest PC 0x0c0a054c */
if(!s->budget--) { s->failed_pc=0x0c0a054cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a0550u;
r[0]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0550u) { target=s->pc; goto dispatch; }
goto P_0c0a0550;
P_0c0a054e: /* original 6053, guest PC 0x0c0a054e */
if(!s->budget--) { s->failed_pc=0x0c0a054eu; return 0; }
r[0]=r[5];
goto P_0c0a0550;
P_0c0a0550: /* original 6103, guest PC 0x0c0a0550 */
if(!s->budget--) { s->failed_pc=0x0c0a0550u; return 0; }
r[1]=r[0];
goto P_0c0a0552;
P_0c0a0552: /* original 64f2, guest PC 0x0c0a0552 */
if(!s->budget--) { s->failed_pc=0x0c0a0552u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a0554;
P_0c0a0554: /* original 4108, guest PC 0x0c0a0554 */
if(!s->budget--) { s->failed_pc=0x0c0a0554u; return 0; }
r[1]<<=2;
goto P_0c0a0556;
P_0c0a0556: /* original 2fe6, guest PC 0x0c0a0556 */
if(!s->budget--) { s->failed_pc=0x0c0a0556u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0558;
P_0c0a0558: /* original 6303, guest PC 0x0c0a0558 */
if(!s->budget--) { s->failed_pc=0x0c0a0558u; return 0; }
r[3]=r[0];
goto P_0c0a055a;
P_0c0a055a: /* original 2fc6, guest PC 0x0c0a055a */
if(!s->budget--) { s->failed_pc=0x0c0a055au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a055c;
P_0c0a055c: /* original 313c, guest PC 0x0c0a055c */
if(!s->budget--) { s->failed_pc=0x0c0a055cu; return 0; }
r[1]+=r[3];
goto P_0c0a055e;
P_0c0a055e: /* original 2fd6, guest PC 0x0c0a055e */
if(!s->budget--) { s->failed_pc=0x0c0a055eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0560;
P_0c0a0560: /* original e307, guest PC 0x0c0a0560 */
if(!s->budget--) { s->failed_pc=0x0c0a0560u; return 0; }
r[3]=0x00000007u;
goto P_0c0a0562;
P_0c0a0562: /* original 2f76, guest PC 0x0c0a0562 */
if(!s->budget--) { s->failed_pc=0x0c0a0562u; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0564;
P_0c0a0564: /* original 740c, guest PC 0x0c0a0564 */
if(!s->budget--) { s->failed_pc=0x0c0a0564u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a0566;
P_0c0a0566: /* original 6503, guest PC 0x0c0a0566 */
if(!s->budget--) { s->failed_pc=0x0c0a0566u; return 0; }
r[5]=r[0];
goto P_0c0a0568;
P_0c0a0568: /* original 4100, guest PC 0x0c0a0568 */
if(!s->budget--) { s->failed_pc=0x0c0a0568u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0a056a;
P_0c0a056a: /* original 443c, guest PC 0x0c0a056a */
if(!s->budget--) { s->failed_pc=0x0c0a056au; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c0a056c;
P_0c0a056c: /* original 3618, guest PC 0x0c0a056c */
if(!s->budget--) { s->failed_pc=0x0c0a056cu; return 0; }
r[6]-=r[1];
goto P_0c0a056e;
P_0c0a056e: /* original 2f66, guest PC 0x0c0a056e */
if(!s->budget--) { s->failed_pc=0x0c0a056eu; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0570;
P_0c0a0570: /* original e12e, guest PC 0x0c0a0570 */
if(!s->budget--) { s->failed_pc=0x0c0a0570u; return 0; }
r[1]=0x0000002eu;
goto P_0c0a0572;
P_0c0a0572: /* original 241b, guest PC 0x0c0a0572 */
if(!s->budget--) { s->failed_pc=0x0c0a0572u; return 0; }
r[4]|=r[1];
goto P_0c0a0574;
P_0c0a0574: /* original 2f56, guest PC 0x0c0a0574 */
if(!s->budget--) { s->failed_pc=0x0c0a0574u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0576;
P_0c0a0576: /* original d31e, guest PC 0x0c0a0576 */
if(!s->budget--) { s->failed_pc=0x0c0a0576u; return 0; }
r[3]=read(ram,0x0c0a05f0u,4);
goto P_0c0a0578;
P_0c0a0578: /* original d21c, guest PC 0x0c0a0578 */
if(!s->budget--) { s->failed_pc=0x0c0a0578u; return 0; }
r[2]=read(ram,0x0c0a05ecu,4);
goto P_0c0a057a;
P_0c0a057a: /* original 430b, guest PC 0x0c0a057a */
if(!s->budget--) { s->failed_pc=0x0c0a057au; return 0; }
target=r[3];
r[16]=code_base|0x0c0a057eu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a057eu) { target=s->pc; goto dispatch; }
goto P_0c0a057e;
P_0c0a057c: /* original 2f26, guest PC 0x0c0a057c */
if(!s->budget--) { s->failed_pc=0x0c0a057cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a057e;
P_0c0a057e: /* original 7f24, guest PC 0x0c0a057e */
if(!s->budget--) { s->failed_pc=0x0c0a057eu; return 0; }
r[15]+=0x00000024u;
goto P_0c0a0580;
P_0c0a0580: /* original 4f16, guest PC 0x0c0a0580 */
if(!s->budget--) { s->failed_pc=0x0c0a0580u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a0582;
P_0c0a0582: /* original 4f26, guest PC 0x0c0a0582 */
if(!s->budget--) { s->failed_pc=0x0c0a0582u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a0584;
P_0c0a0584: /* original 6cf6, guest PC 0x0c0a0584 */
if(!s->budget--) { s->failed_pc=0x0c0a0584u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a0586;
P_0c0a0586: /* original 6df6, guest PC 0x0c0a0586 */
if(!s->budget--) { s->failed_pc=0x0c0a0586u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a0588;
P_0c0a0588: /* original 000b, guest PC 0x0c0a0588 */
if(!s->budget--) { s->failed_pc=0x0c0a0588u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a058a: /* original 6ef6, guest PC 0x0c0a058a */
if(!s->budget--) { s->failed_pc=0x0c0a058au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a058cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
