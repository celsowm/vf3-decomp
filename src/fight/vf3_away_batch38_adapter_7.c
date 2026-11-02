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
int vf3_away_batch38_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c07b6c4u: goto P_0c07b6c4;
case 0x0c07b6c6u: goto P_0c07b6c6;
case 0x0c07b6c8u: goto P_0c07b6c8;
case 0x0c07b6cau: goto P_0c07b6ca;
case 0x0c07b6ccu: goto P_0c07b6cc;
case 0x0c07b6ceu: goto P_0c07b6ce;
case 0x0c07b6d0u: goto P_0c07b6d0;
case 0x0c07b6d2u: goto P_0c07b6d2;
case 0x0c07b6d4u: goto P_0c07b6d4;
case 0x0c07b6d6u: goto P_0c07b6d6;
case 0x0c07b6d8u: goto P_0c07b6d8;
case 0x0c07b6dau: goto P_0c07b6da;
case 0x0c07b6dcu: goto P_0c07b6dc;
case 0x0c07b6deu: goto P_0c07b6de;
case 0x0c07b6e0u: goto P_0c07b6e0;
case 0x0c07b6e2u: goto P_0c07b6e2;
case 0x0c07b6e4u: goto P_0c07b6e4;
case 0x0c07b6e6u: goto P_0c07b6e6;
case 0x0c07b6e8u: goto P_0c07b6e8;
case 0x0c07b6eau: goto P_0c07b6ea;
case 0x0c07b6ecu: goto P_0c07b6ec;
case 0x0c07b6eeu: goto P_0c07b6ee;
case 0x0c07b6f0u: goto P_0c07b6f0;
case 0x0c07b6f2u: goto P_0c07b6f2;
case 0x0c091dbeu: goto P_0c091dbe;
case 0x0c091dc0u: goto P_0c091dc0;
case 0x0c091dc2u: goto P_0c091dc2;
case 0x0c091dc4u: goto P_0c091dc4;
case 0x0c091dc6u: goto P_0c091dc6;
case 0x0c091dc8u: goto P_0c091dc8;
case 0x0c091dcau: goto P_0c091dca;
case 0x0c091dccu: goto P_0c091dcc;
case 0x0c091dceu: goto P_0c091dce;
case 0x0c091dd0u: goto P_0c091dd0;
case 0x0c091dd2u: goto P_0c091dd2;
case 0x0c091dd4u: goto P_0c091dd4;
case 0x0c091dd6u: goto P_0c091dd6;
case 0x0c091dd8u: goto P_0c091dd8;
case 0x0c091ddau: goto P_0c091dda;
case 0x0c091ddcu: goto P_0c091ddc;
case 0x0c091ddeu: goto P_0c091dde;
case 0x0c091de0u: goto P_0c091de0;
case 0x0c091de2u: goto P_0c091de2;
case 0x0c091de4u: goto P_0c091de4;
case 0x0c091de6u: goto P_0c091de6;
case 0x0c091de8u: goto P_0c091de8;
case 0x0c091deau: goto P_0c091dea;
case 0x0c091decu: goto P_0c091dec;
case 0x0c091deeu: goto P_0c091dee;
case 0x0c091df0u: goto P_0c091df0;
case 0x0c091df2u: goto P_0c091df2;
case 0x0c091df4u: goto P_0c091df4;
case 0x0c091df6u: goto P_0c091df6;
case 0x0c091df8u: goto P_0c091df8;
case 0x0c091dfau: goto P_0c091dfa;
case 0x0c091dfcu: goto P_0c091dfc;
case 0x0c091dfeu: goto P_0c091dfe;
case 0x0c091e00u: goto P_0c091e00;
case 0x0c091e02u: goto P_0c091e02;
case 0x0c091e04u: goto P_0c091e04;
case 0x0c091e06u: goto P_0c091e06;
case 0x0c091e08u: goto P_0c091e08;
case 0x0c091e0au: goto P_0c091e0a;
case 0x0c091e0cu: goto P_0c091e0c;
case 0x0c091e0eu: goto P_0c091e0e;
case 0x0c091e10u: goto P_0c091e10;
case 0x0c091e12u: goto P_0c091e12;
case 0x0c091e14u: goto P_0c091e14;
case 0x0c091e16u: goto P_0c091e16;
case 0x0c091e18u: goto P_0c091e18;
case 0x0c091e1au: goto P_0c091e1a;
case 0x0c091e1cu: goto P_0c091e1c;
case 0x0c091e1eu: goto P_0c091e1e;
case 0x0c091e20u: goto P_0c091e20;
case 0x0c091e22u: goto P_0c091e22;
case 0x0c091e24u: goto P_0c091e24;
case 0x0c091e26u: goto P_0c091e26;
case 0x0c091e28u: goto P_0c091e28;
case 0x0c091e2au: goto P_0c091e2a;
case 0x0c091e2cu: goto P_0c091e2c;
case 0x0c091e2eu: goto P_0c091e2e;
case 0x0c091e30u: goto P_0c091e30;
case 0x0c091e32u: goto P_0c091e32;
case 0x0c091e34u: goto P_0c091e34;
case 0x0c091e36u: goto P_0c091e36;
case 0x0c091e38u: goto P_0c091e38;
case 0x0c091e3au: goto P_0c091e3a;
case 0x0c091e3cu: goto P_0c091e3c;
case 0x0c091e3eu: goto P_0c091e3e;
case 0x0c091e40u: goto P_0c091e40;
case 0x0c091e42u: goto P_0c091e42;
case 0x0c091e44u: goto P_0c091e44;
case 0x0c091e46u: goto P_0c091e46;
case 0x0c091e48u: goto P_0c091e48;
case 0x0c091e4au: goto P_0c091e4a;
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
P_0c07b6c4: /* original 4f22, guest PC 0x0c07b6c4 */
if(!s->budget--) { s->failed_pc=0x0c07b6c4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b6c6;
P_0c07b6c6: /* original 7ffc, guest PC 0x0c07b6c6 */
if(!s->budget--) { s->failed_pc=0x0c07b6c6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07b6c8;
P_0c07b6c8: /* original 2f72, guest PC 0x0c07b6c8 */
if(!s->budget--) { s->failed_pc=0x0c07b6c8u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c07b6ca;
P_0c07b6ca: /* original 53f2, guest PC 0x0c07b6ca */
if(!s->budget--) { s->failed_pc=0x0c07b6cau; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07b6cc;
P_0c07b6cc: /* original 2f36, guest PC 0x0c07b6cc */
if(!s->budget--) { s->failed_pc=0x0c07b6ccu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b6ce;
P_0c07b6ce: /* original 52f1, guest PC 0x0c07b6ce */
if(!s->budget--) { s->failed_pc=0x0c07b6ceu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07b6d0;
P_0c07b6d0: /* original 2f26, guest PC 0x0c07b6d0 */
if(!s->budget--) { s->failed_pc=0x0c07b6d0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b6d2;
P_0c07b6d2: /* original b004, guest PC 0x0c07b6d2 */
if(!s->budget--) { s->failed_pc=0x0c07b6d2u; return 0; }
target=code_base|0x0c07b6deu; r[16]=code_base|0x0c07b6d6u;
r[7]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b6d6u) { target=s->pc; goto dispatch; }
goto P_0c07b6d6;
P_0c07b6d4: /* original e700, guest PC 0x0c07b6d4 */
if(!s->budget--) { s->failed_pc=0x0c07b6d4u; return 0; }
r[7]=0x00000000u;
goto P_0c07b6d6;
P_0c07b6d6: /* original 7f0c, guest PC 0x0c07b6d6 */
if(!s->budget--) { s->failed_pc=0x0c07b6d6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07b6d8;
P_0c07b6d8: /* original 4f26, guest PC 0x0c07b6d8 */
if(!s->budget--) { s->failed_pc=0x0c07b6d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b6da;
P_0c07b6da: /* original 000b, guest PC 0x0c07b6da */
if(!s->budget--) { s->failed_pc=0x0c07b6dau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07b6dc: /* original 0009, guest PC 0x0c07b6dc */
if(!s->budget--) { s->failed_pc=0x0c07b6dcu; return 0; }
goto P_0c07b6de;
P_0c07b6de: /* original 4f22, guest PC 0x0c07b6de */
if(!s->budget--) { s->failed_pc=0x0c07b6deu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b6e0;
P_0c07b6e0: /* original 53f2, guest PC 0x0c07b6e0 */
if(!s->budget--) { s->failed_pc=0x0c07b6e0u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07b6e2;
P_0c07b6e2: /* original 2f36, guest PC 0x0c07b6e2 */
if(!s->budget--) { s->failed_pc=0x0c07b6e2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b6e4;
P_0c07b6e4: /* original d311, guest PC 0x0c07b6e4 */
if(!s->budget--) { s->failed_pc=0x0c07b6e4u; return 0; }
r[3]=read(ram,0x0c07b72cu,4);
goto P_0c07b6e6;
P_0c07b6e6: /* original 52f2, guest PC 0x0c07b6e6 */
if(!s->budget--) { s->failed_pc=0x0c07b6e6u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c07b6e8;
P_0c07b6e8: /* original 430b, guest PC 0x0c07b6e8 */
if(!s->budget--) { s->failed_pc=0x0c07b6e8u; return 0; }
target=r[3];
r[16]=code_base|0x0c07b6ecu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b6ecu) { target=s->pc; goto dispatch; }
goto P_0c07b6ec;
P_0c07b6ea: /* original 2f26, guest PC 0x0c07b6ea */
if(!s->budget--) { s->failed_pc=0x0c07b6eau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b6ec;
P_0c07b6ec: /* original 7f08, guest PC 0x0c07b6ec */
if(!s->budget--) { s->failed_pc=0x0c07b6ecu; return 0; }
r[15]+=0x00000008u;
goto P_0c07b6ee;
P_0c07b6ee: /* original 4f26, guest PC 0x0c07b6ee */
if(!s->budget--) { s->failed_pc=0x0c07b6eeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b6f0;
P_0c07b6f0: /* original 000b, guest PC 0x0c07b6f0 */
if(!s->budget--) { s->failed_pc=0x0c07b6f0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07b6f2: /* original 0009, guest PC 0x0c07b6f2 */
if(!s->budget--) { s->failed_pc=0x0c07b6f2u; return 0; }
if(!vf3_matrix_family(0x0c07b6f4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b6f4u; return 0; } return 1;
P_0c091dbe: /* original 4f22, guest PC 0x0c091dbe */
if(!s->budget--) { s->failed_pc=0x0c091dbeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c091dc0;
P_0c091dc0: /* original 7ffc, guest PC 0x0c091dc0 */
if(!s->budget--) { s->failed_pc=0x0c091dc0u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c091dc2;
P_0c091dc2: /* original 2f42, guest PC 0x0c091dc2 */
if(!s->budget--) { s->failed_pc=0x0c091dc2u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c091dc4;
P_0c091dc4: /* original d12b, guest PC 0x0c091dc4 */
if(!s->budget--) { s->failed_pc=0x0c091dc4u; return 0; }
r[1]=read(ram,0x0c091e74u,4);
goto P_0c091dc6;
P_0c091dc6: /* original d32a, guest PC 0x0c091dc6 */
if(!s->budget--) { s->failed_pc=0x0c091dc6u; return 0; }
r[3]=read(ram,0x0c091e70u,4);
goto P_0c091dc8;
P_0c091dc8: /* original 6212, guest PC 0x0c091dc8 */
if(!s->budget--) { s->failed_pc=0x0c091dc8u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c091dca;
P_0c091dca: /* original 2238, guest PC 0x0c091dca */
if(!s->budget--) { s->failed_pc=0x0c091dcau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c091dcc;
P_0c091dcc: /* original 8b07, guest PC 0x0c091dcc */
if(!s->budget--) { s->failed_pc=0x0c091dccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091dde; }
goto P_0c091dce;
P_0c091dce: /* original 9348, guest PC 0x0c091dce */
if(!s->budget--) { s->failed_pc=0x0c091dceu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091e62u,2);
goto P_0c091dd0;
P_0c091dd0: /* original 64f2, guest PC 0x0c091dd0 */
if(!s->budget--) { s->failed_pc=0x0c091dd0u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c091dd2;
P_0c091dd2: /* original b008, guest PC 0x0c091dd2 */
if(!s->budget--) { s->failed_pc=0x0c091dd2u; return 0; }
target=code_base|0x0c091de6u; r[16]=code_base|0x0c091dd6u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091dd6u) { target=s->pc; goto dispatch; }
goto P_0c091dd6;
P_0c091dd4: /* original 343c, guest PC 0x0c091dd4 */
if(!s->budget--) { s->failed_pc=0x0c091dd4u; return 0; }
r[4]+=r[3];
goto P_0c091dd6;
P_0c091dd6: /* original 9345, guest PC 0x0c091dd6 */
if(!s->budget--) { s->failed_pc=0x0c091dd6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091e64u,2);
goto P_0c091dd8;
P_0c091dd8: /* original 64f2, guest PC 0x0c091dd8 */
if(!s->budget--) { s->failed_pc=0x0c091dd8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c091dda;
P_0c091dda: /* original b004, guest PC 0x0c091dda */
if(!s->budget--) { s->failed_pc=0x0c091ddau; return 0; }
target=code_base|0x0c091de6u; r[16]=code_base|0x0c091ddeu;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091ddeu) { target=s->pc; goto dispatch; }
goto P_0c091dde;
P_0c091ddc: /* original 343c, guest PC 0x0c091ddc */
if(!s->budget--) { s->failed_pc=0x0c091ddcu; return 0; }
r[4]+=r[3];
goto P_0c091dde;
P_0c091dde: /* original 7f04, guest PC 0x0c091dde */
if(!s->budget--) { s->failed_pc=0x0c091ddeu; return 0; }
r[15]+=0x00000004u;
goto P_0c091de0;
P_0c091de0: /* original 4f26, guest PC 0x0c091de0 */
if(!s->budget--) { s->failed_pc=0x0c091de0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c091de2;
P_0c091de2: /* original 000b, guest PC 0x0c091de2 */
if(!s->budget--) { s->failed_pc=0x0c091de2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c091de4: /* original 0009, guest PC 0x0c091de4 */
if(!s->budget--) { s->failed_pc=0x0c091de4u; return 0; }
goto P_0c091de6;
P_0c091de6: /* original 2fe6, guest PC 0x0c091de6 */
if(!s->budget--) { s->failed_pc=0x0c091de6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091de8;
P_0c091de8: /* original 6e43, guest PC 0x0c091de8 */
if(!s->budget--) { s->failed_pc=0x0c091de8u; return 0; }
r[14]=r[4];
goto P_0c091dea;
P_0c091dea: /* original 903c, guest PC 0x0c091dea */
if(!s->budget--) { s->failed_pc=0x0c091deau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091e66u,2);
goto P_0c091dec;
P_0c091dec: /* original f4e6, guest PC 0x0c091dec */
if(!s->budget--) { s->failed_pc=0x0c091decu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c091dee;
P_0c091dee: /* original 7004, guest PC 0x0c091dee */
if(!s->budget--) { s->failed_pc=0x0c091deeu; return 0; }
r[0]+=0x00000004u;
goto P_0c091df0;
P_0c091df0: /* original f5e6, guest PC 0x0c091df0 */
if(!s->budget--) { s->failed_pc=0x0c091df0u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c091df2;
P_0c091df2: /* original f450, guest PC 0x0c091df2 */
if(!s->budget--) { s->failed_pc=0x0c091df2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c091df4;
P_0c091df4: /* original f59d, guest PC 0x0c091df4 */
if(!s->budget--) { s->failed_pc=0x0c091df4u; return 0; }
fr[5]=0x3f800000u;
goto P_0c091df6;
P_0c091df6: /* original f455, guest PC 0x0c091df6 */
if(!s->budget--) { s->failed_pc=0x0c091df6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c091df8;
P_0c091df8: /* original 8b00, guest PC 0x0c091df8 */
if(!s->budget--) { s->failed_pc=0x0c091df8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091dfc; }
goto P_0c091dfa;
P_0c091dfa: /* original f45c, guest PC 0x0c091dfa */
if(!s->budget--) { s->failed_pc=0x0c091dfau; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c091dfc;
P_0c091dfc: /* original 9033, guest PC 0x0c091dfc */
if(!s->budget--) { s->failed_pc=0x0c091dfcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091e66u,2);
goto P_0c091dfe;
P_0c091dfe: /* original 65e3, guest PC 0x0c091dfe */
if(!s->budget--) { s->failed_pc=0x0c091dfeu; return 0; }
r[5]=r[14];
goto P_0c091e00;
P_0c091e00: /* original 66e3, guest PC 0x0c091e00 */
if(!s->budget--) { s->failed_pc=0x0c091e00u; return 0; }
r[6]=r[14];
goto P_0c091e02;
P_0c091e02: /* original 64e3, guest PC 0x0c091e02 */
if(!s->budget--) { s->failed_pc=0x0c091e02u; return 0; }
r[4]=r[14];
goto P_0c091e04;
P_0c091e04: /* original 7534, guest PC 0x0c091e04 */
if(!s->budget--) { s->failed_pc=0x0c091e04u; return 0; }
r[5]+=0x00000034u;
goto P_0c091e06;
P_0c091e06: /* original fe47, guest PC 0x0c091e06 */
if(!s->budget--) { s->failed_pc=0x0c091e06u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c091e08;
P_0c091e08: /* original 7668, guest PC 0x0c091e08 */
if(!s->budget--) { s->failed_pc=0x0c091e08u; return 0; }
r[6]+=0x00000068u;
goto P_0c091e0a;
P_0c091e0a: /* original a000, guest PC 0x0c091e0a */
if(!s->budget--) { s->failed_pc=0x0c091e0au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c091e0e;
P_0c091e0c: /* original 6ef6, guest PC 0x0c091e0c */
if(!s->budget--) { s->failed_pc=0x0c091e0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c091e0e;
P_0c091e0e: /* original c71a, guest PC 0x0c091e0e */
if(!s->budget--) { s->failed_pc=0x0c091e0eu; return 0; }
r[0]=code_base|0x00091e78u;
goto P_0c091e10;
P_0c091e10: /* original 2fd6, guest PC 0x0c091e10 */
if(!s->budget--) { s->failed_pc=0x0c091e10u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091e12;
P_0c091e12: /* original 2fc6, guest PC 0x0c091e12 */
if(!s->budget--) { s->failed_pc=0x0c091e12u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091e14;
P_0c091e14: /* original 6163, guest PC 0x0c091e14 */
if(!s->budget--) { s->failed_pc=0x0c091e14u; return 0; }
r[1]=r[6];
goto P_0c091e16;
P_0c091e16: /* original f308, guest PC 0x0c091e16 */
if(!s->budget--) { s->failed_pc=0x0c091e16u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c091e18;
P_0c091e18: /* original e61a, guest PC 0x0c091e18 */
if(!s->budget--) { s->failed_pc=0x0c091e18u; return 0; }
r[6]=0x0000001au;
goto P_0c091e1a;
P_0c091e1a: /* original 4f12, guest PC 0x0c091e1a */
if(!s->budget--) { s->failed_pc=0x0c091e1au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c091e1c;
P_0c091e1c: /* original f432, guest PC 0x0c091e1c */
if(!s->budget--) { s->failed_pc=0x0c091e1cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c091e1e;
P_0c091e1e: /* original 9023, guest PC 0x0c091e1e */
if(!s->budget--) { s->failed_pc=0x0c091e1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091e68u,2);
goto P_0c091e20;
P_0c091e20: /* original 6d53, guest PC 0x0c091e20 */
if(!s->budget--) { s->failed_pc=0x0c091e20u; return 0; }
r[13]=r[5];
goto P_0c091e22;
P_0c091e22: /* original 6c43, guest PC 0x0c091e22 */
if(!s->budget--) { s->failed_pc=0x0c091e22u; return 0; }
r[12]=r[4];
goto P_0c091e24;
P_0c091e24: /* original f43d, guest PC 0x0c091e24 */
if(!s->budget--) { s->failed_pc=0x0c091e24u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c091e26;
P_0c091e26: /* original 075a, guest PC 0x0c091e26 */
if(!s->budget--) { s->failed_pc=0x0c091e26u; return 0; }
r[7]=r[53];
goto P_0c091e28;
P_0c091e28: /* original 3078, guest PC 0x0c091e28 */
if(!s->budget--) { s->failed_pc=0x0c091e28u; return 0; }
r[0]-=r[7];
goto P_0c091e2a;
P_0c091e2a: /* original 64c5, guest PC 0x0c091e2a */
if(!s->budget--) { s->failed_pc=0x0c091e2au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[12]+=2;
r[4]=tmp;
goto P_0c091e2c;
P_0c091e2c: /* original e3f2, guest PC 0x0c091e2c */
if(!s->budget--) { s->failed_pc=0x0c091e2cu; return 0; }
r[3]=0xfffffff2u;
goto P_0c091e2e;
P_0c091e2e: /* original 65d5, guest PC 0x0c091e2e */
if(!s->budget--) { s->failed_pc=0x0c091e2eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[13]+=2;
r[5]=tmp;
goto P_0c091e30;
P_0c091e30: /* original 4610, guest PC 0x0c091e30 */
if(!s->budget--) { s->failed_pc=0x0c091e30u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c091e32;
P_0c091e32: /* original 0047, guest PC 0x0c091e32 */
if(!s->budget--) { s->failed_pc=0x0c091e32u; return 0; }
r[19]=r[0]*r[4];
goto P_0c091e34;
P_0c091e34: /* original 041a, guest PC 0x0c091e34 */
if(!s->budget--) { s->failed_pc=0x0c091e34u; return 0; }
r[4]=r[19];
goto P_0c091e36;
P_0c091e36: /* original 0757, guest PC 0x0c091e36 */
if(!s->budget--) { s->failed_pc=0x0c091e36u; return 0; }
r[19]=r[7]*r[5];
goto P_0c091e38;
P_0c091e38: /* original 051a, guest PC 0x0c091e38 */
if(!s->budget--) { s->failed_pc=0x0c091e38u; return 0; }
r[5]=r[19];
goto P_0c091e3a;
P_0c091e3a: /* original 345c, guest PC 0x0c091e3a */
if(!s->budget--) { s->failed_pc=0x0c091e3au; return 0; }
r[4]+=r[5];
goto P_0c091e3c;
P_0c091e3c: /* original 443c, guest PC 0x0c091e3c */
if(!s->budget--) { s->failed_pc=0x0c091e3cu; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c091e3e;
P_0c091e3e: /* original 2141, guest PC 0x0c091e3e */
if(!s->budget--) { s->failed_pc=0x0c091e3eu; return 0; }
write(ram,r[1],r[4],2);
goto P_0c091e40;
P_0c091e40: /* original 8ff3, guest PC 0x0c091e40 */
if(!s->budget--) { s->failed_pc=0x0c091e40u; return 0; }
cond=r[17]&1u;
r[1]+=0x00000002u;
if(!cond) { goto P_0c091e2a; }
goto P_0c091e44;
P_0c091e42: /* original 7102, guest PC 0x0c091e42 */
if(!s->budget--) { s->failed_pc=0x0c091e42u; return 0; }
r[1]+=0x00000002u;
goto P_0c091e44;
P_0c091e44: /* original 4f16, guest PC 0x0c091e44 */
if(!s->budget--) { s->failed_pc=0x0c091e44u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c091e46;
P_0c091e46: /* original 6cf6, guest PC 0x0c091e46 */
if(!s->budget--) { s->failed_pc=0x0c091e46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c091e48;
P_0c091e48: /* original 000b, guest PC 0x0c091e48 */
if(!s->budget--) { s->failed_pc=0x0c091e48u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c091e4a: /* original 6df6, guest PC 0x0c091e4a */
if(!s->budget--) { s->failed_pc=0x0c091e4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
if(!vf3_matrix_family(0x0c091e4cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c091e4cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
