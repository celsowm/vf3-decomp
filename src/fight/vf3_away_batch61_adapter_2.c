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
int vf3_away_batch61_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08d512u: goto P_0c08d512;
case 0x0c08d514u: goto P_0c08d514;
case 0x0c08d516u: goto P_0c08d516;
case 0x0c08d518u: goto P_0c08d518;
case 0x0c08d51au: goto P_0c08d51a;
case 0x0c08d51cu: goto P_0c08d51c;
case 0x0c08d51eu: goto P_0c08d51e;
case 0x0c08d520u: goto P_0c08d520;
case 0x0c08d522u: goto P_0c08d522;
case 0x0c08d524u: goto P_0c08d524;
case 0x0c08d526u: goto P_0c08d526;
case 0x0c08d528u: goto P_0c08d528;
case 0x0c08d52au: goto P_0c08d52a;
case 0x0c08d52cu: goto P_0c08d52c;
case 0x0c08d52eu: goto P_0c08d52e;
case 0x0c08d530u: goto P_0c08d530;
case 0x0c08d532u: goto P_0c08d532;
case 0x0c08d534u: goto P_0c08d534;
case 0x0c08d536u: goto P_0c08d536;
case 0x0c08d538u: goto P_0c08d538;
case 0x0c08d53au: goto P_0c08d53a;
case 0x0c08d53cu: goto P_0c08d53c;
case 0x0c08d53eu: goto P_0c08d53e;
case 0x0c08d540u: goto P_0c08d540;
case 0x0c08d542u: goto P_0c08d542;
case 0x0c08d544u: goto P_0c08d544;
case 0x0c08d546u: goto P_0c08d546;
case 0x0c08d548u: goto P_0c08d548;
case 0x0c08d54au: goto P_0c08d54a;
case 0x0c08d54cu: goto P_0c08d54c;
case 0x0c08d54eu: goto P_0c08d54e;
case 0x0c08d550u: goto P_0c08d550;
case 0x0c08d552u: goto P_0c08d552;
case 0x0c08d554u: goto P_0c08d554;
case 0x0c08d556u: goto P_0c08d556;
case 0x0c08d558u: goto P_0c08d558;
case 0x0c08d55au: goto P_0c08d55a;
case 0x0c08d55cu: goto P_0c08d55c;
case 0x0c08d55eu: goto P_0c08d55e;
case 0x0c08d560u: goto P_0c08d560;
case 0x0c08d562u: goto P_0c08d562;
case 0x0c08d564u: goto P_0c08d564;
case 0x0c08d566u: goto P_0c08d566;
case 0x0c08d568u: goto P_0c08d568;
case 0x0c08d56au: goto P_0c08d56a;
case 0x0c08d56cu: goto P_0c08d56c;
case 0x0c08d56eu: goto P_0c08d56e;
case 0x0c08d570u: goto P_0c08d570;
case 0x0c08d572u: goto P_0c08d572;
case 0x0c08d574u: goto P_0c08d574;
case 0x0c08d5a4u: goto P_0c08d5a4;
case 0x0c08d5a6u: goto P_0c08d5a6;
case 0x0c08d5a8u: goto P_0c08d5a8;
case 0x0c08d5aau: goto P_0c08d5aa;
case 0x0c08d5acu: goto P_0c08d5ac;
case 0x0c08d5aeu: goto P_0c08d5ae;
case 0x0c08d5b0u: goto P_0c08d5b0;
case 0x0c08d5b2u: goto P_0c08d5b2;
case 0x0c08d5b4u: goto P_0c08d5b4;
case 0x0c08d5b6u: goto P_0c08d5b6;
case 0x0c08d5b8u: goto P_0c08d5b8;
case 0x0c08d5bau: goto P_0c08d5ba;
case 0x0c08d5bcu: goto P_0c08d5bc;
case 0x0c08d5beu: goto P_0c08d5be;
case 0x0c08d5c0u: goto P_0c08d5c0;
case 0x0c08d5c2u: goto P_0c08d5c2;
case 0x0c08d5c4u: goto P_0c08d5c4;
case 0x0c08d5c6u: goto P_0c08d5c6;
case 0x0c08d5c8u: goto P_0c08d5c8;
case 0x0c08d5cau: goto P_0c08d5ca;
case 0x0c08d5ccu: goto P_0c08d5cc;
case 0x0c08d5ceu: goto P_0c08d5ce;
case 0x0c08d5d0u: goto P_0c08d5d0;
case 0x0c08d5d2u: goto P_0c08d5d2;
case 0x0c08d5d4u: goto P_0c08d5d4;
case 0x0c08d5d6u: goto P_0c08d5d6;
case 0x0c08d5d8u: goto P_0c08d5d8;
case 0x0c08d5dau: goto P_0c08d5da;
case 0x0c08d5dcu: goto P_0c08d5dc;
case 0x0c08d5deu: goto P_0c08d5de;
case 0x0c08d5e0u: goto P_0c08d5e0;
case 0x0c08d5e2u: goto P_0c08d5e2;
case 0x0c08d5e4u: goto P_0c08d5e4;
case 0x0c08d5e6u: goto P_0c08d5e6;
case 0x0c08d5e8u: goto P_0c08d5e8;
case 0x0c08d5eau: goto P_0c08d5ea;
case 0x0c08d5ecu: goto P_0c08d5ec;
case 0x0c08d5eeu: goto P_0c08d5ee;
case 0x0c08d5f0u: goto P_0c08d5f0;
case 0x0c08d5f2u: goto P_0c08d5f2;
case 0x0c08d5f4u: goto P_0c08d5f4;
case 0x0c08d5f6u: goto P_0c08d5f6;
case 0x0c08d5f8u: goto P_0c08d5f8;
case 0x0c08d5fau: goto P_0c08d5fa;
case 0x0c08d5fcu: goto P_0c08d5fc;
case 0x0c08d5feu: goto P_0c08d5fe;
case 0x0c08d600u: goto P_0c08d600;
case 0x0c08d602u: goto P_0c08d602;
case 0x0c08d604u: goto P_0c08d604;
case 0x0c08d606u: goto P_0c08d606;
case 0x0c08d608u: goto P_0c08d608;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08d512: /* original 2fe6, guest PC 0x0c08d512 */
if(!s->budget--) { s->failed_pc=0x0c08d512u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d514;
P_0c08d514: /* original e048, guest PC 0x0c08d514 */
if(!s->budget--) { s->failed_pc=0x0c08d514u; return 0; }
r[0]=0x00000048u;
goto P_0c08d516;
P_0c08d516: /* original 2fd6, guest PC 0x0c08d516 */
if(!s->budget--) { s->failed_pc=0x0c08d516u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d518;
P_0c08d518: /* original 6d43, guest PC 0x0c08d518 */
if(!s->budget--) { s->failed_pc=0x0c08d518u; return 0; }
r[13]=r[4];
goto P_0c08d51a;
P_0c08d51a: /* original 2fc6, guest PC 0x0c08d51a */
if(!s->budget--) { s->failed_pc=0x0c08d51au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d51c;
P_0c08d51c: /* original 00dc, guest PC 0x0c08d51c */
if(!s->budget--) { s->failed_pc=0x0c08d51cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08d51e;
P_0c08d51e: /* original 4f22, guest PC 0x0c08d51e */
if(!s->budget--) { s->failed_pc=0x0c08d51eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08d520;
P_0c08d520: /* original 8801, guest PC 0x0c08d520 */
if(!s->budget--) { s->failed_pc=0x0c08d520u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08d522;
P_0c08d522: /* original 8d6d, guest PC 0x0c08d522 */
if(!s->budget--) { s->failed_pc=0x0c08d522u; return 0; }
cond=r[17]&1u;
r[14]=r[5];
if(cond) { goto P_0c08d600; }
goto P_0c08d526;
P_0c08d524: /* original 6e53, guest PC 0x0c08d524 */
if(!s->budget--) { s->failed_pc=0x0c08d524u; return 0; }
r[14]=r[5];
goto P_0c08d526;
P_0c08d526: /* original 60e2, guest PC 0x0c08d526 */
if(!s->budget--) { s->failed_pc=0x0c08d526u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c08d528;
P_0c08d528: /* original cb01, guest PC 0x0c08d528 */
if(!s->budget--) { s->failed_pc=0x0c08d528u; return 0; }
r[0]|=1u;
goto P_0c08d52a;
P_0c08d52a: /* original 2e02, guest PC 0x0c08d52a */
if(!s->budget--) { s->failed_pc=0x0c08d52au; return 0; }
write(ram,r[14],r[0],4);
goto P_0c08d52c;
P_0c08d52c: /* original e04c, guest PC 0x0c08d52c */
if(!s->budget--) { s->failed_pc=0x0c08d52cu; return 0; }
r[0]=0x0000004cu;
goto P_0c08d52e;
P_0c08d52e: /* original 02ee, guest PC 0x0c08d52e */
if(!s->budget--) { s->failed_pc=0x0c08d52eu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c08d530;
P_0c08d530: /* original e048, guest PC 0x0c08d530 */
if(!s->budget--) { s->failed_pc=0x0c08d530u; return 0; }
r[0]=0x00000048u;
goto P_0c08d532;
P_0c08d532: /* original d316, guest PC 0x0c08d532 */
if(!s->budget--) { s->failed_pc=0x0c08d532u; return 0; }
r[3]=read(ram,0x0c08d58cu,4);
goto P_0c08d534;
P_0c08d534: /* original 012e, guest PC 0x0c08d534 */
if(!s->budget--) { s->failed_pc=0x0c08d534u; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c08d536;
P_0c08d536: /* original 2138, guest PC 0x0c08d536 */
if(!s->budget--) { s->failed_pc=0x0c08d536u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c08d538;
P_0c08d538: /* original 8903, guest PC 0x0c08d538 */
if(!s->budget--) { s->failed_pc=0x0c08d538u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08d542; }
goto P_0c08d53a;
P_0c08d53a: /* original d115, guest PC 0x0c08d53a */
if(!s->budget--) { s->failed_pc=0x0c08d53au; return 0; }
r[1]=read(ram,0x0c08d590u,4);
goto P_0c08d53c;
P_0c08d53c: /* original 84e8, guest PC 0x0c08d53c */
if(!s->budget--) { s->failed_pc=0x0c08d53cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08d53e;
P_0c08d53e: /* original a003, guest PC 0x0c08d53e */
if(!s->budget--) { s->failed_pc=0x0c08d53eu; return 0; }
r[0]=r[0]&255u;
goto P_0c08d548;
P_0c08d540: /* original 600c, guest PC 0x0c08d540 */
if(!s->budget--) { s->failed_pc=0x0c08d540u; return 0; }
r[0]=r[0]&255u;
goto P_0c08d542;
P_0c08d542: /* original 84e8, guest PC 0x0c08d542 */
if(!s->budget--) { s->failed_pc=0x0c08d542u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08d544;
P_0c08d544: /* original d113, guest PC 0x0c08d544 */
if(!s->budget--) { s->failed_pc=0x0c08d544u; return 0; }
r[1]=read(ram,0x0c08d594u,4);
goto P_0c08d546;
P_0c08d546: /* original 600c, guest PC 0x0c08d546 */
if(!s->budget--) { s->failed_pc=0x0c08d546u; return 0; }
r[0]=r[0]&255u;
goto P_0c08d548;
P_0c08d548: /* original d313, guest PC 0x0c08d548 */
if(!s->budget--) { s->failed_pc=0x0c08d548u; return 0; }
r[3]=read(ram,0x0c08d598u,4);
goto P_0c08d54a;
P_0c08d54a: /* original 0c1c, guest PC 0x0c08d54a */
if(!s->budget--) { s->failed_pc=0x0c08d54au; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c08d54c;
P_0c08d54c: /* original 430b, guest PC 0x0c08d54c */
if(!s->budget--) { s->failed_pc=0x0c08d54cu; return 0; }
target=r[3];
r[16]=code_base|0x0c08d550u;
r[12]=r[12]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d550u) { target=s->pc; goto dispatch; }
goto P_0c08d550;
P_0c08d54e: /* original 6ccc, guest PC 0x0c08d54e */
if(!s->budget--) { s->failed_pc=0x0c08d54eu; return 0; }
r[12]=r[12]&255u;
goto P_0c08d550;
P_0c08d550: /* original d212, guest PC 0x0c08d550 */
if(!s->budget--) { s->failed_pc=0x0c08d550u; return 0; }
r[2]=read(ram,0x0c08d59cu,4);
goto P_0c08d552;
P_0c08d552: /* original 6103, guest PC 0x0c08d552 */
if(!s->budget--) { s->failed_pc=0x0c08d552u; return 0; }
r[1]=r[0];
goto P_0c08d554;
P_0c08d554: /* original 420b, guest PC 0x0c08d554 */
if(!s->budget--) { s->failed_pc=0x0c08d554u; return 0; }
target=r[2];
r[16]=code_base|0x0c08d558u;
r[0]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d558u) { target=s->pc; goto dispatch; }
goto P_0c08d558;
P_0c08d556: /* original 60c3, guest PC 0x0c08d556 */
if(!s->budget--) { s->failed_pc=0x0c08d556u; return 0; }
r[0]=r[12];
goto P_0c08d558;
P_0c08d558: /* original 6403, guest PC 0x0c08d558 */
if(!s->budget--) { s->failed_pc=0x0c08d558u; return 0; }
r[4]=r[0];
goto P_0c08d55a;
P_0c08d55a: /* original 6c03, guest PC 0x0c08d55a */
if(!s->budget--) { s->failed_pc=0x0c08d55au; return 0; }
r[12]=r[0];
goto P_0c08d55c;
P_0c08d55c: /* original e04c, guest PC 0x0c08d55c */
if(!s->budget--) { s->failed_pc=0x0c08d55cu; return 0; }
r[0]=0x0000004cu;
goto P_0c08d55e;
P_0c08d55e: /* original d20b, guest PC 0x0c08d55e */
if(!s->budget--) { s->failed_pc=0x0c08d55eu; return 0; }
r[2]=read(ram,0x0c08d58cu,4);
goto P_0c08d560;
P_0c08d560: /* original 03ee, guest PC 0x0c08d560 */
if(!s->budget--) { s->failed_pc=0x0c08d560u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c08d562;
P_0c08d562: /* original e048, guest PC 0x0c08d562 */
if(!s->budget--) { s->failed_pc=0x0c08d562u; return 0; }
r[0]=0x00000048u;
goto P_0c08d564;
P_0c08d564: /* original 4400, guest PC 0x0c08d564 */
if(!s->budget--) { s->failed_pc=0x0c08d564u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08d566;
P_0c08d566: /* original 013e, guest PC 0x0c08d566 */
if(!s->budget--) { s->failed_pc=0x0c08d566u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c08d568;
P_0c08d568: /* original 2128, guest PC 0x0c08d568 */
if(!s->budget--) { s->failed_pc=0x0c08d568u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c08d56a;
P_0c08d56a: /* original 891b, guest PC 0x0c08d56a */
if(!s->budget--) { s->failed_pc=0x0c08d56au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08d5a4; }
goto P_0c08d56c;
P_0c08d56c: /* original 84e8, guest PC 0x0c08d56c */
if(!s->budget--) { s->failed_pc=0x0c08d56cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08d56e;
P_0c08d56e: /* original d10c, guest PC 0x0c08d56e */
if(!s->budget--) { s->failed_pc=0x0c08d56eu; return 0; }
r[1]=read(ram,0x0c08d5a0u,4);
goto P_0c08d570;
P_0c08d570: /* original 600c, guest PC 0x0c08d570 */
if(!s->budget--) { s->failed_pc=0x0c08d570u; return 0; }
r[0]=r[0]&255u;
goto P_0c08d572;
P_0c08d572: /* original a01b, guest PC 0x0c08d572 */
if(!s->budget--) { s->failed_pc=0x0c08d572u; return 0; }
r[0]<<=2;
goto P_0c08d5ac;
P_0c08d574: /* original 4008, guest PC 0x0c08d574 */
if(!s->budget--) { s->failed_pc=0x0c08d574u; return 0; }
r[0]<<=2;
if(!vf3_matrix_family(0x0c08d576u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08d576u; return 0; } return 1;
P_0c08d5a4: /* original 84e8, guest PC 0x0c08d5a4 */
if(!s->budget--) { s->failed_pc=0x0c08d5a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08d5a6;
P_0c08d5a6: /* original d121, guest PC 0x0c08d5a6 */
if(!s->budget--) { s->failed_pc=0x0c08d5a6u; return 0; }
r[1]=read(ram,0x0c08d62cu,4);
goto P_0c08d5a8;
P_0c08d5a8: /* original 600c, guest PC 0x0c08d5a8 */
if(!s->budget--) { s->failed_pc=0x0c08d5a8u; return 0; }
r[0]=r[0]&255u;
goto P_0c08d5aa;
P_0c08d5aa: /* original 4008, guest PC 0x0c08d5aa */
if(!s->budget--) { s->failed_pc=0x0c08d5aau; return 0; }
r[0]<<=2;
goto P_0c08d5ac;
P_0c08d5ac: /* original 001e, guest PC 0x0c08d5ac */
if(!s->budget--) { s->failed_pc=0x0c08d5acu; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c08d5ae;
P_0c08d5ae: /* original e300, guest PC 0x0c08d5ae */
if(!s->budget--) { s->failed_pc=0x0c08d5aeu; return 0; }
r[3]=0x00000000u;
goto P_0c08d5b0;
P_0c08d5b0: /* original 054d, guest PC 0x0c08d5b0 */
if(!s->budget--) { s->failed_pc=0x0c08d5b0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08d5b2;
P_0c08d5b2: /* original e028, guest PC 0x0c08d5b2 */
if(!s->budget--) { s->failed_pc=0x0c08d5b2u; return 0; }
r[0]=0x00000028u;
goto P_0c08d5b4;
P_0c08d5b4: /* original 655d, guest PC 0x0c08d5b4 */
if(!s->budget--) { s->failed_pc=0x0c08d5b4u; return 0; }
r[5]=r[5]&65535u;
goto P_0c08d5b6;
P_0c08d5b6: /* original 0d55, guest PC 0x0c08d5b6 */
if(!s->budget--) { s->failed_pc=0x0c08d5b6u; return 0; }
write(ram,r[13]+r[0],r[5],2);
goto P_0c08d5b8;
P_0c08d5b8: /* original e040, guest PC 0x0c08d5b8 */
if(!s->budget--) { s->failed_pc=0x0c08d5b8u; return 0; }
r[0]=0x00000040u;
goto P_0c08d5ba;
P_0c08d5ba: /* original 1e5d, guest PC 0x0c08d5ba */
if(!s->budget--) { s->failed_pc=0x0c08d5bau; return 0; }
write(ram,r[14]+52,r[5],4);
goto P_0c08d5bc;
P_0c08d5bc: /* original 0e36, guest PC 0x0c08d5bc */
if(!s->budget--) { s->failed_pc=0x0c08d5bcu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c08d5be;
P_0c08d5be: /* original bdcb, guest PC 0x0c08d5be */
if(!s->budget--) { s->failed_pc=0x0c08d5beu; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08d5c2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d5c2u) { target=s->pc; goto dispatch; }
goto P_0c08d5c2;
P_0c08d5c0: /* original 64e3, guest PC 0x0c08d5c0 */
if(!s->budget--) { s->failed_pc=0x0c08d5c0u; return 0; }
r[4]=r[14];
goto P_0c08d5c2;
P_0c08d5c2: /* original e200, guest PC 0x0c08d5c2 */
if(!s->budget--) { s->failed_pc=0x0c08d5c2u; return 0; }
r[2]=0x00000000u;
goto P_0c08d5c4;
P_0c08d5c4: /* original 55ee, guest PC 0x0c08d5c4 */
if(!s->budget--) { s->failed_pc=0x0c08d5c4u; return 0; }
r[5]=read(ram,r[14]+56,4);
goto P_0c08d5c6;
P_0c08d5c6: /* original e02c, guest PC 0x0c08d5c6 */
if(!s->budget--) { s->failed_pc=0x0c08d5c6u; return 0; }
r[0]=0x0000002cu;
goto P_0c08d5c8;
P_0c08d5c8: /* original 54ef, guest PC 0x0c08d5c8 */
if(!s->budget--) { s->failed_pc=0x0c08d5c8u; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c08d5ca;
P_0c08d5ca: /* original 0d24, guest PC 0x0c08d5ca */
if(!s->budget--) { s->failed_pc=0x0c08d5cau; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c08d5cc;
P_0c08d5cc: /* original e02d, guest PC 0x0c08d5cc */
if(!s->budget--) { s->failed_pc=0x0c08d5ccu; return 0; }
r[0]=0x0000002du;
goto P_0c08d5ce;
P_0c08d5ce: /* original 0d54, guest PC 0x0c08d5ce */
if(!s->budget--) { s->failed_pc=0x0c08d5ceu; return 0; }
write(ram,r[13]+r[0],r[5],1);
goto P_0c08d5d0;
P_0c08d5d0: /* original 6043, guest PC 0x0c08d5d0 */
if(!s->budget--) { s->failed_pc=0x0c08d5d0u; return 0; }
r[0]=r[4];
goto P_0c08d5d2;
P_0c08d5d2: /* original 81da, guest PC 0x0c08d5d2 */
if(!s->budget--) { s->failed_pc=0x0c08d5d2u; return 0; }
write(ram,r[13]+20,r[0],2);
goto P_0c08d5d4;
P_0c08d5d4: /* original e04c, guest PC 0x0c08d5d4 */
if(!s->budget--) { s->failed_pc=0x0c08d5d4u; return 0; }
r[0]=0x0000004cu;
goto P_0c08d5d6;
P_0c08d5d6: /* original 04ee, guest PC 0x0c08d5d6 */
if(!s->budget--) { s->failed_pc=0x0c08d5d6u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c08d5d8;
P_0c08d5d8: /* original e60a, guest PC 0x0c08d5d8 */
if(!s->budget--) { s->failed_pc=0x0c08d5d8u; return 0; }
r[6]=0x0000000au;
goto P_0c08d5da;
P_0c08d5da: /* original 9025, guest PC 0x0c08d5da */
if(!s->budget--) { s->failed_pc=0x0c08d5dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08d628u,2);
goto P_0c08d5dc;
P_0c08d5dc: /* original 6c63, guest PC 0x0c08d5dc */
if(!s->budget--) { s->failed_pc=0x0c08d5dcu; return 0; }
r[12]=r[6];
goto P_0c08d5de;
P_0c08d5de: /* original 044d, guest PC 0x0c08d5de */
if(!s->budget--) { s->failed_pc=0x0c08d5deu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08d5e0;
P_0c08d5e0: /* original 3467, guest PC 0x0c08d5e0 */
if(!s->budget--) { s->failed_pc=0x0c08d5e0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[6])!=0);
goto P_0c08d5e2;
P_0c08d5e2: /* original 8f01, guest PC 0x0c08d5e2 */
if(!s->budget--) { s->failed_pc=0x0c08d5e2u; return 0; }
cond=r[17]&1u;
r[5]=r[4];
if(!cond) { goto P_0c08d5e8; }
goto P_0c08d5e6;
P_0c08d5e4: /* original 6543, guest PC 0x0c08d5e4 */
if(!s->budget--) { s->failed_pc=0x0c08d5e4u; return 0; }
r[5]=r[4];
goto P_0c08d5e6;
P_0c08d5e6: /* original 6c53, guest PC 0x0c08d5e6 */
if(!s->budget--) { s->failed_pc=0x0c08d5e6u; return 0; }
r[12]=r[5];
goto P_0c08d5e8;
P_0c08d5e8: /* original d211, guest PC 0x0c08d5e8 */
if(!s->budget--) { s->failed_pc=0x0c08d5e8u; return 0; }
r[2]=read(ram,0x0c08d630u,4);
goto P_0c08d5ea;
P_0c08d5ea: /* original 420b, guest PC 0x0c08d5ea */
if(!s->budget--) { s->failed_pc=0x0c08d5eau; return 0; }
target=r[2];
r[16]=code_base|0x0c08d5eeu;
r[17]=(r[17]&~1u)|((r[12]&1)!=0);
r[12]>>=1;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d5eeu) { target=s->pc; goto dispatch; }
goto P_0c08d5ee;
P_0c08d5ec: /* original 4c01, guest PC 0x0c08d5ec */
if(!s->budget--) { s->failed_pc=0x0c08d5ecu; return 0; }
r[17]=(r[17]&~1u)|((r[12]&1)!=0);
r[12]>>=1;
goto P_0c08d5ee;
P_0c08d5ee: /* original d311, guest PC 0x0c08d5ee */
if(!s->budget--) { s->failed_pc=0x0c08d5eeu; return 0; }
r[3]=read(ram,0x0c08d634u,4);
goto P_0c08d5f0;
P_0c08d5f0: /* original 6103, guest PC 0x0c08d5f0 */
if(!s->budget--) { s->failed_pc=0x0c08d5f0u; return 0; }
r[1]=r[0];
goto P_0c08d5f2;
P_0c08d5f2: /* original 430b, guest PC 0x0c08d5f2 */
if(!s->budget--) { s->failed_pc=0x0c08d5f2u; return 0; }
target=r[3];
r[16]=code_base|0x0c08d5f6u;
r[0]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d5f6u) { target=s->pc; goto dispatch; }
goto P_0c08d5f6;
P_0c08d5f4: /* original 60c3, guest PC 0x0c08d5f4 */
if(!s->budget--) { s->failed_pc=0x0c08d5f4u; return 0; }
r[0]=r[12];
goto P_0c08d5f6;
P_0c08d5f6: /* original 81dc, guest PC 0x0c08d5f6 */
if(!s->budget--) { s->failed_pc=0x0c08d5f6u; return 0; }
write(ram,r[13]+24,r[0],2);
goto P_0c08d5f8;
P_0c08d5f8: /* original e048, guest PC 0x0c08d5f8 */
if(!s->budget--) { s->failed_pc=0x0c08d5f8u; return 0; }
r[0]=0x00000048u;
goto P_0c08d5fa;
P_0c08d5fa: /* original 03dc, guest PC 0x0c08d5fa */
if(!s->budget--) { s->failed_pc=0x0c08d5fau; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08d5fc;
P_0c08d5fc: /* original 7301, guest PC 0x0c08d5fc */
if(!s->budget--) { s->failed_pc=0x0c08d5fcu; return 0; }
r[3]+=0x00000001u;
goto P_0c08d5fe;
P_0c08d5fe: /* original 0d34, guest PC 0x0c08d5fe */
if(!s->budget--) { s->failed_pc=0x0c08d5feu; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c08d600;
P_0c08d600: /* original 4f26, guest PC 0x0c08d600 */
if(!s->budget--) { s->failed_pc=0x0c08d600u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08d602;
P_0c08d602: /* original 6cf6, guest PC 0x0c08d602 */
if(!s->budget--) { s->failed_pc=0x0c08d602u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08d604;
P_0c08d604: /* original 6df6, guest PC 0x0c08d604 */
if(!s->budget--) { s->failed_pc=0x0c08d604u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08d606;
P_0c08d606: /* original 000b, guest PC 0x0c08d606 */
if(!s->budget--) { s->failed_pc=0x0c08d606u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08d608: /* original 6ef6, guest PC 0x0c08d608 */
if(!s->budget--) { s->failed_pc=0x0c08d608u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08d60au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08d60au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
