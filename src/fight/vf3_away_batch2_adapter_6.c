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
int vf3_away_batch2_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03d4f0u: goto P_0c03d4f0;
case 0x0c03d4f2u: goto P_0c03d4f2;
case 0x0c03d4f4u: goto P_0c03d4f4;
case 0x0c03d4f6u: goto P_0c03d4f6;
case 0x0c03d4f8u: goto P_0c03d4f8;
case 0x0c03d4fau: goto P_0c03d4fa;
case 0x0c03d4fcu: goto P_0c03d4fc;
case 0x0c03d4feu: goto P_0c03d4fe;
case 0x0c03d500u: goto P_0c03d500;
case 0x0c03d502u: goto P_0c03d502;
case 0x0c03d504u: goto P_0c03d504;
case 0x0c03d506u: goto P_0c03d506;
case 0x0c03d508u: goto P_0c03d508;
case 0x0c03d50au: goto P_0c03d50a;
case 0x0c03d50cu: goto P_0c03d50c;
case 0x0c03d50eu: goto P_0c03d50e;
case 0x0c03d510u: goto P_0c03d510;
case 0x0c03d512u: goto P_0c03d512;
case 0x0c03d514u: goto P_0c03d514;
case 0x0c03d516u: goto P_0c03d516;
case 0x0c03d518u: goto P_0c03d518;
case 0x0c03d51au: goto P_0c03d51a;
case 0x0c03d51cu: goto P_0c03d51c;
case 0x0c03d51eu: goto P_0c03d51e;
case 0x0c03d520u: goto P_0c03d520;
case 0x0c03d522u: goto P_0c03d522;
case 0x0c03d524u: goto P_0c03d524;
case 0x0c03d526u: goto P_0c03d526;
case 0x0c03d528u: goto P_0c03d528;
case 0x0c03d52au: goto P_0c03d52a;
case 0x0c03d52cu: goto P_0c03d52c;
case 0x0c03d52eu: goto P_0c03d52e;
case 0x0c03d530u: goto P_0c03d530;
case 0x0c03d532u: goto P_0c03d532;
case 0x0c03d534u: goto P_0c03d534;
case 0x0c03d536u: goto P_0c03d536;
case 0x0c03d538u: goto P_0c03d538;
case 0x0c03d53au: goto P_0c03d53a;
case 0x0c03d53cu: goto P_0c03d53c;
case 0x0c03d53eu: goto P_0c03d53e;
case 0x0c03d540u: goto P_0c03d540;
case 0x0c03d542u: goto P_0c03d542;
case 0x0c03d544u: goto P_0c03d544;
case 0x0c03d546u: goto P_0c03d546;
case 0x0c03d548u: goto P_0c03d548;
case 0x0c03d54au: goto P_0c03d54a;
case 0x0c03d54cu: goto P_0c03d54c;
case 0x0c03d54eu: goto P_0c03d54e;
case 0x0c03d550u: goto P_0c03d550;
case 0x0c03d552u: goto P_0c03d552;
case 0x0c03d554u: goto P_0c03d554;
case 0x0c03d556u: goto P_0c03d556;
case 0x0c03d558u: goto P_0c03d558;
case 0x0c03d55au: goto P_0c03d55a;
case 0x0c03d55cu: goto P_0c03d55c;
case 0x0c03d55eu: goto P_0c03d55e;
case 0x0c03d560u: goto P_0c03d560;
case 0x0c03d562u: goto P_0c03d562;
case 0x0c03d564u: goto P_0c03d564;
case 0x0c03d566u: goto P_0c03d566;
case 0x0c03d568u: goto P_0c03d568;
case 0x0c03d56au: goto P_0c03d56a;
case 0x0c03d56cu: goto P_0c03d56c;
case 0x0c03d56eu: goto P_0c03d56e;
case 0x0c03d570u: goto P_0c03d570;
case 0x0c03d572u: goto P_0c03d572;
case 0x0c03d574u: goto P_0c03d574;
case 0x0c03d576u: goto P_0c03d576;
case 0x0c03d578u: goto P_0c03d578;
case 0x0c03d57au: goto P_0c03d57a;
case 0x0c03d57cu: goto P_0c03d57c;
case 0x0c03d57eu: goto P_0c03d57e;
case 0x0c03d580u: goto P_0c03d580;
case 0x0c03d582u: goto P_0c03d582;
case 0x0c03d584u: goto P_0c03d584;
case 0x0c03d586u: goto P_0c03d586;
case 0x0c03d588u: goto P_0c03d588;
case 0x0c03d58au: goto P_0c03d58a;
case 0x0c03d58cu: goto P_0c03d58c;
case 0x0c03d58eu: goto P_0c03d58e;
case 0x0c03d590u: goto P_0c03d590;
case 0x0c03d592u: goto P_0c03d592;
case 0x0c03d5a0u: goto P_0c03d5a0;
case 0x0c03d5a2u: goto P_0c03d5a2;
case 0x0c03d5a4u: goto P_0c03d5a4;
case 0x0c03d5a6u: goto P_0c03d5a6;
case 0x0c03d5a8u: goto P_0c03d5a8;
case 0x0c03d5aau: goto P_0c03d5aa;
case 0x0c03d5acu: goto P_0c03d5ac;
case 0x0c03d5aeu: goto P_0c03d5ae;
case 0x0c03d5b0u: goto P_0c03d5b0;
case 0x0c03d5b2u: goto P_0c03d5b2;
case 0x0c03d5b4u: goto P_0c03d5b4;
case 0x0c03d5b6u: goto P_0c03d5b6;
case 0x0c03d5b8u: goto P_0c03d5b8;
case 0x0c03d5bau: goto P_0c03d5ba;
case 0x0c03d5bcu: goto P_0c03d5bc;
case 0x0c03d5beu: goto P_0c03d5be;
case 0x0c03d5c0u: goto P_0c03d5c0;
case 0x0c03d5c2u: goto P_0c03d5c2;
case 0x0c03d5c4u: goto P_0c03d5c4;
case 0x0c03d5c6u: goto P_0c03d5c6;
case 0x0c03d5c8u: goto P_0c03d5c8;
case 0x0c03d5cau: goto P_0c03d5ca;
case 0x0c03d5ccu: goto P_0c03d5cc;
case 0x0c03d5ceu: goto P_0c03d5ce;
case 0x0c03d5d0u: goto P_0c03d5d0;
case 0x0c03d5d2u: goto P_0c03d5d2;
case 0x0c03d5d4u: goto P_0c03d5d4;
case 0x0c03d5d6u: goto P_0c03d5d6;
case 0x0c03d5d8u: goto P_0c03d5d8;
case 0x0c03d5dau: goto P_0c03d5da;
case 0x0c03d5dcu: goto P_0c03d5dc;
case 0x0c03d5deu: goto P_0c03d5de;
case 0x0c03d5e0u: goto P_0c03d5e0;
case 0x0c03d5e2u: goto P_0c03d5e2;
case 0x0c03d5e4u: goto P_0c03d5e4;
case 0x0c03d5e6u: goto P_0c03d5e6;
case 0x0c03d5e8u: goto P_0c03d5e8;
case 0x0c03d5eau: goto P_0c03d5ea;
case 0x0c03d5ecu: goto P_0c03d5ec;
case 0x0c03d5eeu: goto P_0c03d5ee;
case 0x0c03d5f0u: goto P_0c03d5f0;
case 0x0c03d5f2u: goto P_0c03d5f2;
case 0x0c03d5f4u: goto P_0c03d5f4;
case 0x0c03d5f6u: goto P_0c03d5f6;
case 0x0c03d5f8u: goto P_0c03d5f8;
case 0x0c03d5fau: goto P_0c03d5fa;
case 0x0c03d5fcu: goto P_0c03d5fc;
case 0x0c03d5feu: goto P_0c03d5fe;
case 0x0c03d600u: goto P_0c03d600;
case 0x0c03d602u: goto P_0c03d602;
case 0x0c03d604u: goto P_0c03d604;
case 0x0c03d606u: goto P_0c03d606;
case 0x0c03d608u: goto P_0c03d608;
case 0x0c03d60au: goto P_0c03d60a;
case 0x0c03d60cu: goto P_0c03d60c;
case 0x0c03d60eu: goto P_0c03d60e;
case 0x0c03d610u: goto P_0c03d610;
case 0x0c03d612u: goto P_0c03d612;
case 0x0c03d614u: goto P_0c03d614;
case 0x0c03d616u: goto P_0c03d616;
case 0x0c03d618u: goto P_0c03d618;
case 0x0c03d61au: goto P_0c03d61a;
case 0x0c03d61cu: goto P_0c03d61c;
case 0x0c03d61eu: goto P_0c03d61e;
case 0x0c03d620u: goto P_0c03d620;
case 0x0c03d622u: goto P_0c03d622;
case 0x0c03d624u: goto P_0c03d624;
case 0x0c03d626u: goto P_0c03d626;
case 0x0c03d628u: goto P_0c03d628;
case 0x0c03d62au: goto P_0c03d62a;
case 0x0c03d62cu: goto P_0c03d62c;
case 0x0c03d62eu: goto P_0c03d62e;
case 0x0c03d630u: goto P_0c03d630;
case 0x0c03d632u: goto P_0c03d632;
case 0x0c03d634u: goto P_0c03d634;
case 0x0c03d636u: goto P_0c03d636;
case 0x0c03d638u: goto P_0c03d638;
case 0x0c03d63au: goto P_0c03d63a;
case 0x0c03d63cu: goto P_0c03d63c;
case 0x0c03d63eu: goto P_0c03d63e;
case 0x0c03d640u: goto P_0c03d640;
case 0x0c03d642u: goto P_0c03d642;
case 0x0c03d644u: goto P_0c03d644;
case 0x0c03d646u: goto P_0c03d646;
case 0x0c03d648u: goto P_0c03d648;
case 0x0c03d64au: goto P_0c03d64a;
case 0x0c03d64cu: goto P_0c03d64c;
case 0x0c03d64eu: goto P_0c03d64e;
case 0x0c03d650u: goto P_0c03d650;
case 0x0c03d652u: goto P_0c03d652;
case 0x0c03d654u: goto P_0c03d654;
case 0x0c03d656u: goto P_0c03d656;
case 0x0c03d658u: goto P_0c03d658;
case 0x0c03d65au: goto P_0c03d65a;
case 0x0c03d65cu: goto P_0c03d65c;
case 0x0c03d65eu: goto P_0c03d65e;
case 0x0c03d660u: goto P_0c03d660;
case 0x0c03d662u: goto P_0c03d662;
case 0x0c03d664u: goto P_0c03d664;
case 0x0c03d666u: goto P_0c03d666;
case 0x0c03d668u: goto P_0c03d668;
case 0x0c03d66au: goto P_0c03d66a;
case 0x0c03d66cu: goto P_0c03d66c;
case 0x0c03d66eu: goto P_0c03d66e;
case 0x0c03d670u: goto P_0c03d670;
case 0x0c03d672u: goto P_0c03d672;
case 0x0c03d674u: goto P_0c03d674;
case 0x0c03d676u: goto P_0c03d676;
case 0x0c03d678u: goto P_0c03d678;
case 0x0c03d67au: goto P_0c03d67a;
case 0x0c03d67cu: goto P_0c03d67c;
case 0x0c03d67eu: goto P_0c03d67e;
case 0x0c03d680u: goto P_0c03d680;
case 0x0c03d682u: goto P_0c03d682;
case 0x0c03d684u: goto P_0c03d684;
case 0x0c03d686u: goto P_0c03d686;
case 0x0c03d688u: goto P_0c03d688;
case 0x0c03d68au: goto P_0c03d68a;
case 0x0c03d68cu: goto P_0c03d68c;
case 0x0c03d68eu: goto P_0c03d68e;
case 0x0c03d690u: goto P_0c03d690;
case 0x0c03d692u: goto P_0c03d692;
case 0x0c03d694u: goto P_0c03d694;
case 0x0c03d696u: goto P_0c03d696;
case 0x0c03d698u: goto P_0c03d698;
case 0x0c03d69au: goto P_0c03d69a;
case 0x0c03d69cu: goto P_0c03d69c;
case 0x0c03d69eu: goto P_0c03d69e;
case 0x0c03d6a0u: goto P_0c03d6a0;
case 0x0c03d6a2u: goto P_0c03d6a2;
case 0x0c03d6a4u: goto P_0c03d6a4;
case 0x0c03d6a6u: goto P_0c03d6a6;
case 0x0c03d6a8u: goto P_0c03d6a8;
case 0x0c03d6aau: goto P_0c03d6aa;
case 0x0c03d6acu: goto P_0c03d6ac;
case 0x0c03d6aeu: goto P_0c03d6ae;
case 0x0c03d6b0u: goto P_0c03d6b0;
case 0x0c03d6b2u: goto P_0c03d6b2;
case 0x0c03d6b4u: goto P_0c03d6b4;
case 0x0c03d6b6u: goto P_0c03d6b6;
case 0x0c03d6b8u: goto P_0c03d6b8;
case 0x0c03d6bau: goto P_0c03d6ba;
case 0x0c03d6bcu: goto P_0c03d6bc;
case 0x0c03d6beu: goto P_0c03d6be;
case 0x0c03d6c0u: goto P_0c03d6c0;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03d4f0: /* original 2fe6, guest PC 0x0c03d4f0 */
if(!s->budget--) { s->failed_pc=0x0c03d4f0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03d4f2;
P_0c03d4f2: /* original e00c, guest PC 0x0c03d4f2 */
if(!s->budget--) { s->failed_pc=0x0c03d4f2u; return 0; }
r[0]=0x0000000cu;
goto P_0c03d4f4;
P_0c03d4f4: /* original 2fd6, guest PC 0x0c03d4f4 */
if(!s->budget--) { s->failed_pc=0x0c03d4f4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03d4f6;
P_0c03d4f6: /* original 2fc6, guest PC 0x0c03d4f6 */
if(!s->budget--) { s->failed_pc=0x0c03d4f6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03d4f8;
P_0c03d4f8: /* original 2fb6, guest PC 0x0c03d4f8 */
if(!s->budget--) { s->failed_pc=0x0c03d4f8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03d4fa;
P_0c03d4fa: /* original 2fa6, guest PC 0x0c03d4fa */
if(!s->budget--) { s->failed_pc=0x0c03d4fau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03d4fc;
P_0c03d4fc: /* original 2f96, guest PC 0x0c03d4fc */
if(!s->budget--) { s->failed_pc=0x0c03d4fcu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03d4fe;
P_0c03d4fe: /* original fffb, guest PC 0x0c03d4fe */
if(!s->budget--) { s->failed_pc=0x0c03d4feu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c03d500;
P_0c03d500: /* original ffeb, guest PC 0x0c03d500 */
if(!s->budget--) { s->failed_pc=0x0c03d500u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c03d502;
P_0c03d502: /* original ffdb, guest PC 0x0c03d502 */
if(!s->budget--) { s->failed_pc=0x0c03d502u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c03d504;
P_0c03d504: /* original ffcb, guest PC 0x0c03d504 */
if(!s->budget--) { s->failed_pc=0x0c03d504u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c03d506;
P_0c03d506: /* original 4f22, guest PC 0x0c03d506 */
if(!s->budget--) { s->failed_pc=0x0c03d506u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03d508;
P_0c03d508: /* original 7fa8, guest PC 0x0c03d508 */
if(!s->budget--) { s->failed_pc=0x0c03d508u; return 0; }
r[15]+=0xffffffa8u;
goto P_0c03d50a;
P_0c03d50a: /* original 1f41, guest PC 0x0c03d50a */
if(!s->budget--) { s->failed_pc=0x0c03d50au; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c03d50c;
P_0c03d50c: /* original ff47, guest PC 0x0c03d50c */
if(!s->budget--) { s->failed_pc=0x0c03d50cu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c03d50e;
P_0c03d50e: /* original 5af1, guest PC 0x0c03d50e */
if(!s->budget--) { s->failed_pc=0x0c03d50eu; return 0; }
r[10]=read(ram,r[15]+4,4);
goto P_0c03d510;
P_0c03d510: /* original d36c, guest PC 0x0c03d510 */
if(!s->budget--) { s->failed_pc=0x0c03d510u; return 0; }
r[3]=read(ram,0x0c03d6c4u,4);
goto P_0c03d512;
P_0c03d512: /* original fd9d, guest PC 0x0c03d512 */
if(!s->budget--) { s->failed_pc=0x0c03d512u; return 0; }
fr[13]=0x3f800000u;
goto P_0c03d514;
P_0c03d514: /* original 4a21, guest PC 0x0c03d514 */
if(!s->budget--) { s->failed_pc=0x0c03d514u; return 0; }
r[17]=(r[17]&~1u)|((r[10]&1)!=0);
r[10]=(uint32_t)((int32_t)r[10]>>1);
goto P_0c03d516;
P_0c03d516: /* original fc6c, guest PC 0x0c03d516 */
if(!s->budget--) { s->failed_pc=0x0c03d516u; return 0; }
vf3_matrix_move(s,12,6);
goto P_0c03d518;
P_0c03d518: /* original fe5c, guest PC 0x0c03d518 */
if(!s->budget--) { s->failed_pc=0x0c03d518u; return 0; }
vf3_matrix_move(s,14,5);
goto P_0c03d51a;
P_0c03d51a: /* original 430b, guest PC 0x0c03d51a */
if(!s->budget--) { s->failed_pc=0x0c03d51au; return 0; }
target=r[3];
r[16]=code_base|0x0c03d51eu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d51eu) { target=s->pc; goto dispatch; }
goto P_0c03d51e;
P_0c03d51c: /* original 64a3, guest PC 0x0c03d51c */
if(!s->budget--) { s->failed_pc=0x0c03d51cu; return 0; }
r[4]=r[10];
goto P_0c03d51e;
P_0c03d51e: /* original f3dc, guest PC 0x0c03d51e */
if(!s->budget--) { s->failed_pc=0x0c03d51eu; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c03d520;
P_0c03d520: /* original f303, guest PC 0x0c03d520 */
if(!s->budget--) { s->failed_pc=0x0c03d520u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'/');
goto P_0c03d522;
P_0c03d522: /* original ff3a, guest PC 0x0c03d522 */
if(!s->budget--) { s->failed_pc=0x0c03d522u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c03d524;
P_0c03d524: /* original de70, guest PC 0x0c03d524 */
if(!s->budget--) { s->failed_pc=0x0c03d524u; return 0; }
r[14]=read(ram,0x0c03d6e8u,4);
goto P_0c03d526;
P_0c03d526: /* original 4e0b, guest PC 0x0c03d526 */
if(!s->budget--) { s->failed_pc=0x0c03d526u; return 0; }
target=r[14];
r[16]=code_base|0x0c03d52au;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d52au) { target=s->pc; goto dispatch; }
goto P_0c03d52a;
P_0c03d528: /* original 64a3, guest PC 0x0c03d528 */
if(!s->budget--) { s->failed_pc=0x0c03d528u; return 0; }
r[4]=r[10];
goto P_0c03d52a;
P_0c03d52a: /* original f3dc, guest PC 0x0c03d52a */
if(!s->budget--) { s->failed_pc=0x0c03d52au; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c03d52c;
P_0c03d52c: /* original f303, guest PC 0x0c03d52c */
if(!s->budget--) { s->failed_pc=0x0c03d52cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'/');
goto P_0c03d52e;
P_0c03d52e: /* original e014, guest PC 0x0c03d52e */
if(!s->budget--) { s->failed_pc=0x0c03d52eu; return 0; }
r[0]=0x00000014u;
goto P_0c03d530;
P_0c03d530: /* original ff37, guest PC 0x0c03d530 */
if(!s->budget--) { s->failed_pc=0x0c03d530u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03d532;
P_0c03d532: /* original e00c, guest PC 0x0c03d532 */
if(!s->budget--) { s->failed_pc=0x0c03d532u; return 0; }
r[0]=0x0000000cu;
goto P_0c03d534;
P_0c03d534: /* original f1f6, guest PC 0x0c03d534 */
if(!s->budget--) { s->failed_pc=0x0c03d534u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c03d536;
P_0c03d536: /* original e008, guest PC 0x0c03d536 */
if(!s->budget--) { s->failed_pc=0x0c03d536u; return 0; }
r[0]=0x00000008u;
goto P_0c03d538;
P_0c03d538: /* original f2f8, guest PC 0x0c03d538 */
if(!s->budget--) { s->failed_pc=0x0c03d538u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c03d53a;
P_0c03d53a: /* original f122, guest PC 0x0c03d53a */
if(!s->budget--) { s->failed_pc=0x0c03d53au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c03d53c;
P_0c03d53c: /* original ff17, guest PC 0x0c03d53c */
if(!s->budget--) { s->failed_pc=0x0c03d53cu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c03d53e;
P_0c03d53e: /* original d362, guest PC 0x0c03d53e */
if(!s->budget--) { s->failed_pc=0x0c03d53eu; return 0; }
r[3]=read(ram,0x0c03d6c8u,4);
goto P_0c03d540;
P_0c03d540: /* original f4dc, guest PC 0x0c03d540 */
if(!s->budget--) { s->failed_pc=0x0c03d540u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c03d542;
P_0c03d542: /* original 430b, guest PC 0x0c03d542 */
if(!s->budget--) { s->failed_pc=0x0c03d542u; return 0; }
target=r[3];
r[16]=code_base|0x0c03d546u;
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'/');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d546u) { target=s->pc; goto dispatch; }
goto P_0c03d546;
P_0c03d544: /* original f413, guest PC 0x0c03d544 */
if(!s->budget--) { s->failed_pc=0x0c03d544u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'/');
goto P_0c03d546;
P_0c03d546: /* original 4e0b, guest PC 0x0c03d546 */
if(!s->budget--) { s->failed_pc=0x0c03d546u; return 0; }
target=r[14];
r[16]=code_base|0x0c03d54au;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d54au) { target=s->pc; goto dispatch; }
goto P_0c03d54a;
P_0c03d548: /* original 6403, guest PC 0x0c03d548 */
if(!s->budget--) { s->failed_pc=0x0c03d548u; return 0; }
r[4]=r[0];
goto P_0c03d54a;
P_0c03d54a: /* original f5dc, guest PC 0x0c03d54a */
if(!s->budget--) { s->failed_pc=0x0c03d54au; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c03d54c;
P_0c03d54c: /* original f503, guest PC 0x0c03d54c */
if(!s->budget--) { s->failed_pc=0x0c03d54cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[0],r[18],'/');
goto P_0c03d54e;
P_0c03d54e: /* original c768, guest PC 0x0c03d54e */
if(!s->budget--) { s->failed_pc=0x0c03d54eu; return 0; }
r[0]=code_base|0x0003d6f0u;
goto P_0c03d550;
P_0c03d550: /* original f2f8, guest PC 0x0c03d550 */
if(!s->budget--) { s->failed_pc=0x0c03d550u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c03d552;
P_0c03d552: /* original f408, guest PC 0x0c03d552 */
if(!s->budget--) { s->failed_pc=0x0c03d552u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c03d554;
P_0c03d554: /* original e014, guest PC 0x0c03d554 */
if(!s->budget--) { s->failed_pc=0x0c03d554u; return 0; }
r[0]=0x00000014u;
goto P_0c03d556;
P_0c03d556: /* original f3f6, guest PC 0x0c03d556 */
if(!s->budget--) { s->failed_pc=0x0c03d556u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c03d558;
P_0c03d558: /* original e008, guest PC 0x0c03d558 */
if(!s->budget--) { s->failed_pc=0x0c03d558u; return 0; }
r[0]=0x00000008u;
goto P_0c03d55a;
P_0c03d55a: /* original d464, guest PC 0x0c03d55a */
if(!s->budget--) { s->failed_pc=0x0c03d55au; return 0; }
r[4]=read(ram,0x0c03d6ecu,4);
goto P_0c03d55c;
P_0c03d55c: /* original f232, guest PC 0x0c03d55c */
if(!s->budget--) { s->failed_pc=0x0c03d55cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03d55e;
P_0c03d55e: /* original f242, guest PC 0x0c03d55e */
if(!s->budget--) { s->failed_pc=0x0c03d55eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c03d560;
P_0c03d560: /* original f42a, guest PC 0x0c03d560 */
if(!s->budget--) { s->failed_pc=0x0c03d560u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c03d562;
P_0c03d562: /* original f3f6, guest PC 0x0c03d562 */
if(!s->budget--) { s->failed_pc=0x0c03d562u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c03d564;
P_0c03d564: /* original d563, guest PC 0x0c03d564 */
if(!s->budget--) { s->failed_pc=0x0c03d564u; return 0; }
r[5]=read(ram,0x0c03d6f4u,4);
goto P_0c03d566;
P_0c03d566: /* original f352, guest PC 0x0c03d566 */
if(!s->budget--) { s->failed_pc=0x0c03d566u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03d568;
P_0c03d568: /* original f342, guest PC 0x0c03d568 */
if(!s->budget--) { s->failed_pc=0x0c03d568u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c03d56a;
P_0c03d56a: /* original f53a, guest PC 0x0c03d56a */
if(!s->budget--) { s->failed_pc=0x0c03d56au; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c03d56c;
P_0c03d56c: /* original d363, guest PC 0x0c03d56c */
if(!s->budget--) { s->failed_pc=0x0c03d56cu; return 0; }
r[3]=read(ram,0x0c03d6fcu,4);
goto P_0c03d56e;
P_0c03d56e: /* original f348, guest PC 0x0c03d56e */
if(!s->budget--) { s->failed_pc=0x0c03d56eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c03d570;
P_0c03d570: /* original f238, guest PC 0x0c03d570 */
if(!s->budget--) { s->failed_pc=0x0c03d570u; return 0; }
vf3_matrix_load(s,ram,2,r[3]);
goto P_0c03d572;
P_0c03d572: /* original d661, guest PC 0x0c03d572 */
if(!s->budget--) { s->failed_pc=0x0c03d572u; return 0; }
r[6]=read(ram,0x0c03d6f8u,4);
goto P_0c03d574;
P_0c03d574: /* original f232, guest PC 0x0c03d574 */
if(!s->budget--) { s->failed_pc=0x0c03d574u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03d576;
P_0c03d576: /* original f62a, guest PC 0x0c03d576 */
if(!s->budget--) { s->failed_pc=0x0c03d576u; return 0; }
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c03d578;
P_0c03d578: /* original d262, guest PC 0x0c03d578 */
if(!s->budget--) { s->failed_pc=0x0c03d578u; return 0; }
r[2]=read(ram,0x0c03d704u,4);
goto P_0c03d57a;
P_0c03d57a: /* original f358, guest PC 0x0c03d57a */
if(!s->budget--) { s->failed_pc=0x0c03d57au; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c03d57c;
P_0c03d57c: /* original f228, guest PC 0x0c03d57c */
if(!s->budget--) { s->failed_pc=0x0c03d57cu; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
goto P_0c03d57e;
P_0c03d57e: /* original d460, guest PC 0x0c03d57e */
if(!s->budget--) { s->failed_pc=0x0c03d57eu; return 0; }
r[4]=read(ram,0x0c03d700u,4);
goto P_0c03d580;
P_0c03d580: /* original f232, guest PC 0x0c03d580 */
if(!s->budget--) { s->failed_pc=0x0c03d580u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03d582;
P_0c03d582: /* original f42a, guest PC 0x0c03d582 */
if(!s->budget--) { s->failed_pc=0x0c03d582u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c03d584;
P_0c03d584: /* original d560, guest PC 0x0c03d584 */
if(!s->budget--) { s->failed_pc=0x0c03d584u; return 0; }
r[5]=read(ram,0x0c03d708u,4);
goto P_0c03d586;
P_0c03d586: /* original f568, guest PC 0x0c03d586 */
if(!s->budget--) { s->failed_pc=0x0c03d586u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c03d588;
P_0c03d588: /* original f42c, guest PC 0x0c03d588 */
if(!s->budget--) { s->failed_pc=0x0c03d588u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c03d58a;
P_0c03d58a: /* original f545, guest PC 0x0c03d58a */
if(!s->budget--) { s->failed_pc=0x0c03d58au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c03d58c;
P_0c03d58c: /* original 8f08, guest PC 0x0c03d58c */
if(!s->budget--) { s->failed_pc=0x0c03d58cu; return 0; }
cond=r[17]&1u;
r[4]=r[10];
if(!cond) { goto P_0c03d5a0; }
goto P_0c03d590;
P_0c03d58e: /* original 64a3, guest PC 0x0c03d58e */
if(!s->budget--) { s->failed_pc=0x0c03d58eu; return 0; }
r[4]=r[10];
goto P_0c03d590;
P_0c03d590: /* original a007, guest PC 0x0c03d590 */
if(!s->budget--) { s->failed_pc=0x0c03d590u; return 0; }
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c03d5a2;
P_0c03d592: /* original f55a, guest PC 0x0c03d592 */
if(!s->budget--) { s->failed_pc=0x0c03d592u; return 0; }
vf3_matrix_store(s,ram,5,r[5]);
if(!vf3_matrix_family(0x0c03d594u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03d594u; return 0; } return 1;
P_0c03d5a0: /* original f54a, guest PC 0x0c03d5a0 */
if(!s->budget--) { s->failed_pc=0x0c03d5a0u; return 0; }
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c03d5a2;
P_0c03d5a2: /* original d348, guest PC 0x0c03d5a2 */
if(!s->budget--) { s->failed_pc=0x0c03d5a2u; return 0; }
r[3]=read(ram,0x0c03d6c4u,4);
goto P_0c03d5a4;
P_0c03d5a4: /* original 430b, guest PC 0x0c03d5a4 */
if(!s->budget--) { s->failed_pc=0x0c03d5a4u; return 0; }
target=r[3];
r[16]=code_base|0x0c03d5a8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d5a8u) { target=s->pc; goto dispatch; }
goto P_0c03d5a8;
P_0c03d5a6: /* original 0009, guest PC 0x0c03d5a6 */
if(!s->budget--) { s->failed_pc=0x0c03d5a6u; return 0; }
goto P_0c03d5a8;
P_0c03d5a8: /* original e00c, guest PC 0x0c03d5a8 */
if(!s->budget--) { s->failed_pc=0x0c03d5a8u; return 0; }
r[0]=0x0000000cu;
goto P_0c03d5aa;
P_0c03d5aa: /* original d347, guest PC 0x0c03d5aa */
if(!s->budget--) { s->failed_pc=0x0c03d5aau; return 0; }
r[3]=read(ram,0x0c03d6c8u,4);
goto P_0c03d5ac;
P_0c03d5ac: /* original f3f6, guest PC 0x0c03d5ac */
if(!s->budget--) { s->failed_pc=0x0c03d5acu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c03d5ae;
P_0c03d5ae: /* original f40c, guest PC 0x0c03d5ae */
if(!s->budget--) { s->failed_pc=0x0c03d5aeu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c03d5b0;
P_0c03d5b0: /* original 430b, guest PC 0x0c03d5b0 */
if(!s->budget--) { s->failed_pc=0x0c03d5b0u; return 0; }
target=r[3];
r[16]=code_base|0x0c03d5b4u;
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d5b4u) { target=s->pc; goto dispatch; }
goto P_0c03d5b4;
P_0c03d5b2: /* original f433, guest PC 0x0c03d5b2 */
if(!s->budget--) { s->failed_pc=0x0c03d5b2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c03d5b4;
P_0c03d5b4: /* original 405a, guest PC 0x0c03d5b4 */
if(!s->budget--) { s->failed_pc=0x0c03d5b4u; return 0; }
r[53]=r[0];
goto P_0c03d5b6;
P_0c03d5b6: /* original e010, guest PC 0x0c03d5b6 */
if(!s->budget--) { s->failed_pc=0x0c03d5b6u; return 0; }
r[0]=0x00000010u;
goto P_0c03d5b8;
P_0c03d5b8: /* original f32d, guest PC 0x0c03d5b8 */
if(!s->budget--) { s->failed_pc=0x0c03d5b8u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03d5ba;
P_0c03d5ba: /* original ff37, guest PC 0x0c03d5ba */
if(!s->budget--) { s->failed_pc=0x0c03d5bau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03d5bc;
P_0c03d5bc: /* original e004, guest PC 0x0c03d5bc */
if(!s->budget--) { s->failed_pc=0x0c03d5bcu; return 0; }
r[0]=0x00000004u;
goto P_0c03d5be;
P_0c03d5be: /* original d443, guest PC 0x0c03d5be */
if(!s->budget--) { s->failed_pc=0x0c03d5beu; return 0; }
r[4]=read(ram,0x0c03d6ccu,4);
goto P_0c03d5c0;
P_0c03d5c0: /* original ff8d, guest PC 0x0c03d5c0 */
if(!s->budget--) { s->failed_pc=0x0c03d5c0u; return 0; }
fr[15]=0;
goto P_0c03d5c2;
P_0c03d5c2: /* original 6c43, guest PC 0x0c03d5c2 */
if(!s->budget--) { s->failed_pc=0x0c03d5c2u; return 0; }
r[12]=r[4];
goto P_0c03d5c4;
P_0c03d5c4: /* original 69c3, guest PC 0x0c03d5c4 */
if(!s->budget--) { s->failed_pc=0x0c03d5c4u; return 0; }
r[9]=r[12];
goto P_0c03d5c6;
P_0c03d5c6: /* original 6b43, guest PC 0x0c03d5c6 */
if(!s->budget--) { s->failed_pc=0x0c03d5c6u; return 0; }
r[11]=r[4];
goto P_0c03d5c8;
P_0c03d5c8: /* original 6dc3, guest PC 0x0c03d5c8 */
if(!s->budget--) { s->failed_pc=0x0c03d5c8u; return 0; }
r[13]=r[12];
goto P_0c03d5ca;
P_0c03d5ca: /* original 7d20, guest PC 0x0c03d5ca */
if(!s->budget--) { s->failed_pc=0x0c03d5cau; return 0; }
r[13]+=0x00000020u;
goto P_0c03d5cc;
P_0c03d5cc: /* original 7930, guest PC 0x0c03d5cc */
if(!s->budget--) { s->failed_pc=0x0c03d5ccu; return 0; }
r[9]+=0x00000030u;
goto P_0c03d5ce;
P_0c03d5ce: /* original 7b10, guest PC 0x0c03d5ce */
if(!s->budget--) { s->failed_pc=0x0c03d5ceu; return 0; }
r[11]+=0x00000010u;
goto P_0c03d5d0;
P_0c03d5d0: /* original fbf7, guest PC 0x0c03d5d0 */
if(!s->budget--) { s->failed_pc=0x0c03d5d0u; return 0; }
vf3_matrix_store(s,ram,15,r[11]+r[0]);
goto P_0c03d5d2;
P_0c03d5d2: /* original fcf7, guest PC 0x0c03d5d2 */
if(!s->budget--) { s->failed_pc=0x0c03d5d2u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c03d5d4;
P_0c03d5d4: /* original f9fa, guest PC 0x0c03d5d4 */
if(!s->budget--) { s->failed_pc=0x0c03d5d4u; return 0; }
vf3_matrix_store(s,ram,15,r[9]);
goto P_0c03d5d6;
P_0c03d5d6: /* original fdfa, guest PC 0x0c03d5d6 */
if(!s->budget--) { s->failed_pc=0x0c03d5d6u; return 0; }
vf3_matrix_store(s,ram,15,r[13]);
goto P_0c03d5d8;
P_0c03d5d8: /* original 4e0b, guest PC 0x0c03d5d8 */
if(!s->budget--) { s->failed_pc=0x0c03d5d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c03d5dcu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d5dcu) { target=s->pc; goto dispatch; }
goto P_0c03d5dc;
P_0c03d5da: /* original 64a3, guest PC 0x0c03d5da */
if(!s->budget--) { s->failed_pc=0x0c03d5dau; return 0; }
r[4]=r[10];
goto P_0c03d5dc;
P_0c03d5dc: /* original fc0a, guest PC 0x0c03d5dc */
if(!s->budget--) { s->failed_pc=0x0c03d5dcu; return 0; }
vf3_matrix_store(s,ram,0,r[12]);
goto P_0c03d5de;
P_0c03d5de: /* original f30c, guest PC 0x0c03d5de */
if(!s->budget--) { s->failed_pc=0x0c03d5deu; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c03d5e0;
P_0c03d5e0: /* original f34d, guest PC 0x0c03d5e0 */
if(!s->budget--) { s->failed_pc=0x0c03d5e0u; return 0; }
fr[3]^=0x80000000u;
goto P_0c03d5e2;
P_0c03d5e2: /* original fb3a, guest PC 0x0c03d5e2 */
if(!s->budget--) { s->failed_pc=0x0c03d5e2u; return 0; }
vf3_matrix_store(s,ram,3,r[11]);
goto P_0c03d5e4;
P_0c03d5e4: /* original d33a, guest PC 0x0c03d5e4 */
if(!s->budget--) { s->failed_pc=0x0c03d5e4u; return 0; }
r[3]=read(ram,0x0c03d6d0u,4);
goto P_0c03d5e6;
P_0c03d5e6: /* original 430b, guest PC 0x0c03d5e6 */
if(!s->budget--) { s->failed_pc=0x0c03d5e6u; return 0; }
target=r[3];
r[16]=code_base|0x0c03d5eau;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d5eau) { target=s->pc; goto dispatch; }
goto P_0c03d5ea;
P_0c03d5e8: /* original 64a3, guest PC 0x0c03d5e8 */
if(!s->budget--) { s->failed_pc=0x0c03d5e8u; return 0; }
r[4]=r[10];
goto P_0c03d5ea;
P_0c03d5ea: /* original e008, guest PC 0x0c03d5ea */
if(!s->budget--) { s->failed_pc=0x0c03d5eau; return 0; }
r[0]=0x00000008u;
goto P_0c03d5ec;
P_0c03d5ec: /* original fb07, guest PC 0x0c03d5ec */
if(!s->budget--) { s->failed_pc=0x0c03d5ecu; return 0; }
vf3_matrix_store(s,ram,0,r[11]+r[0]);
goto P_0c03d5ee;
P_0c03d5ee: /* original fc07, guest PC 0x0c03d5ee */
if(!s->budget--) { s->failed_pc=0x0c03d5eeu; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
goto P_0c03d5f0;
P_0c03d5f0: /* original e010, guest PC 0x0c03d5f0 */
if(!s->budget--) { s->failed_pc=0x0c03d5f0u; return 0; }
r[0]=0x00000010u;
goto P_0c03d5f2;
P_0c03d5f2: /* original f3f6, guest PC 0x0c03d5f2 */
if(!s->budget--) { s->failed_pc=0x0c03d5f2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c03d5f4;
P_0c03d5f4: /* original f33d, guest PC 0x0c03d5f4 */
if(!s->budget--) { s->failed_pc=0x0c03d5f4u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03d5f6;
P_0c03d5f6: /* original 045a, guest PC 0x0c03d5f6 */
if(!s->budget--) { s->failed_pc=0x0c03d5f6u; return 0; }
r[4]=r[53];
goto P_0c03d5f8;
P_0c03d5f8: /* original 4e0b, guest PC 0x0c03d5f8 */
if(!s->budget--) { s->failed_pc=0x0c03d5f8u; return 0; }
target=r[14];
r[16]=code_base|0x0c03d5fcu;
write(ram,r[15]+4,r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d5fcu) { target=s->pc; goto dispatch; }
goto P_0c03d5fc;
P_0c03d5fa: /* original 1f41, guest PC 0x0c03d5fa */
if(!s->budget--) { s->failed_pc=0x0c03d5fau; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c03d5fc;
P_0c03d5fc: /* original e004, guest PC 0x0c03d5fc */
if(!s->budget--) { s->failed_pc=0x0c03d5fcu; return 0; }
r[0]=0x00000004u;
goto P_0c03d5fe;
P_0c03d5fe: /* original fd07, guest PC 0x0c03d5fe */
if(!s->budget--) { s->failed_pc=0x0c03d5feu; return 0; }
vf3_matrix_store(s,ram,0,r[13]+r[0]);
goto P_0c03d600;
P_0c03d600: /* original f30c, guest PC 0x0c03d600 */
if(!s->budget--) { s->failed_pc=0x0c03d600u; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c03d602;
P_0c03d602: /* original f34d, guest PC 0x0c03d602 */
if(!s->budget--) { s->failed_pc=0x0c03d602u; return 0; }
fr[3]^=0x80000000u;
goto P_0c03d604;
P_0c03d604: /* original f937, guest PC 0x0c03d604 */
if(!s->budget--) { s->failed_pc=0x0c03d604u; return 0; }
vf3_matrix_store(s,ram,3,r[9]+r[0]);
goto P_0c03d606;
P_0c03d606: /* original d332, guest PC 0x0c03d606 */
if(!s->budget--) { s->failed_pc=0x0c03d606u; return 0; }
r[3]=read(ram,0x0c03d6d0u,4);
goto P_0c03d608;
P_0c03d608: /* original 430b, guest PC 0x0c03d608 */
if(!s->budget--) { s->failed_pc=0x0c03d608u; return 0; }
target=r[3];
r[16]=code_base|0x0c03d60cu;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d60cu) { target=s->pc; goto dispatch; }
goto P_0c03d60c;
P_0c03d60a: /* original 54f1, guest PC 0x0c03d60a */
if(!s->budget--) { s->failed_pc=0x0c03d60au; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c03d60c;
P_0c03d60c: /* original e008, guest PC 0x0c03d60c */
if(!s->budget--) { s->failed_pc=0x0c03d60cu; return 0; }
r[0]=0x00000008u;
goto P_0c03d60e;
P_0c03d60e: /* original f907, guest PC 0x0c03d60e */
if(!s->budget--) { s->failed_pc=0x0c03d60eu; return 0; }
vf3_matrix_store(s,ram,0,r[9]+r[0]);
goto P_0c03d610;
P_0c03d610: /* original fd07, guest PC 0x0c03d610 */
if(!s->budget--) { s->failed_pc=0x0c03d610u; return 0; }
vf3_matrix_store(s,ram,0,r[13]+r[0]);
goto P_0c03d612;
P_0c03d612: /* original e00c, guest PC 0x0c03d612 */
if(!s->budget--) { s->failed_pc=0x0c03d612u; return 0; }
r[0]=0x0000000cu;
goto P_0c03d614;
P_0c03d614: /* original fbf7, guest PC 0x0c03d614 */
if(!s->budget--) { s->failed_pc=0x0c03d614u; return 0; }
vf3_matrix_store(s,ram,15,r[11]+r[0]);
goto P_0c03d616;
P_0c03d616: /* original fcf7, guest PC 0x0c03d616 */
if(!s->budget--) { s->failed_pc=0x0c03d616u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c03d618;
P_0c03d618: /* original f9f7, guest PC 0x0c03d618 */
if(!s->budget--) { s->failed_pc=0x0c03d618u; return 0; }
vf3_matrix_store(s,ram,15,r[9]+r[0]);
goto P_0c03d61a;
P_0c03d61a: /* original fdf7, guest PC 0x0c03d61a */
if(!s->budget--) { s->failed_pc=0x0c03d61au; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c03d61c;
P_0c03d61c: /* original e018, guest PC 0x0c03d61c */
if(!s->budget--) { s->failed_pc=0x0c03d61cu; return 0; }
r[0]=0x00000018u;
goto P_0c03d61e;
P_0c03d61e: /* original f3f8, guest PC 0x0c03d61e */
if(!s->budget--) { s->failed_pc=0x0c03d61eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c03d620;
P_0c03d620: /* original ff37, guest PC 0x0c03d620 */
if(!s->budget--) { s->failed_pc=0x0c03d620u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03d622;
P_0c03d622: /* original e01c, guest PC 0x0c03d622 */
if(!s->budget--) { s->failed_pc=0x0c03d622u; return 0; }
r[0]=0x0000001cu;
goto P_0c03d624;
P_0c03d624: /* original fff7, guest PC 0x0c03d624 */
if(!s->budget--) { s->failed_pc=0x0c03d624u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c03d626;
P_0c03d626: /* original e020, guest PC 0x0c03d626 */
if(!s->budget--) { s->failed_pc=0x0c03d626u; return 0; }
r[0]=0x00000020u;
goto P_0c03d628;
P_0c03d628: /* original fff7, guest PC 0x0c03d628 */
if(!s->budget--) { s->failed_pc=0x0c03d628u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c03d62a;
P_0c03d62a: /* original e024, guest PC 0x0c03d62a */
if(!s->budget--) { s->failed_pc=0x0c03d62au; return 0; }
r[0]=0x00000024u;
goto P_0c03d62c;
P_0c03d62c: /* original fff7, guest PC 0x0c03d62c */
if(!s->budget--) { s->failed_pc=0x0c03d62cu; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c03d62e;
P_0c03d62e: /* original e028, guest PC 0x0c03d62e */
if(!s->budget--) { s->failed_pc=0x0c03d62eu; return 0; }
r[0]=0x00000028u;
goto P_0c03d630;
P_0c03d630: /* original fff7, guest PC 0x0c03d630 */
if(!s->budget--) { s->failed_pc=0x0c03d630u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c03d632;
P_0c03d632: /* original e008, guest PC 0x0c03d632 */
if(!s->budget--) { s->failed_pc=0x0c03d632u; return 0; }
r[0]=0x00000008u;
goto P_0c03d634;
P_0c03d634: /* original f3f6, guest PC 0x0c03d634 */
if(!s->budget--) { s->failed_pc=0x0c03d634u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c03d636;
P_0c03d636: /* original e02c, guest PC 0x0c03d636 */
if(!s->budget--) { s->failed_pc=0x0c03d636u; return 0; }
r[0]=0x0000002cu;
goto P_0c03d638;
P_0c03d638: /* original ff37, guest PC 0x0c03d638 */
if(!s->budget--) { s->failed_pc=0x0c03d638u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03d63a;
P_0c03d63a: /* original e030, guest PC 0x0c03d63a */
if(!s->budget--) { s->failed_pc=0x0c03d63au; return 0; }
r[0]=0x00000030u;
goto P_0c03d63c;
P_0c03d63c: /* original fff7, guest PC 0x0c03d63c */
if(!s->budget--) { s->failed_pc=0x0c03d63cu; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c03d63e;
P_0c03d63e: /* original e034, guest PC 0x0c03d63e */
if(!s->budget--) { s->failed_pc=0x0c03d63eu; return 0; }
r[0]=0x00000034u;
goto P_0c03d640;
P_0c03d640: /* original fff7, guest PC 0x0c03d640 */
if(!s->budget--) { s->failed_pc=0x0c03d640u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c03d642;
P_0c03d642: /* original e038, guest PC 0x0c03d642 */
if(!s->budget--) { s->failed_pc=0x0c03d642u; return 0; }
r[0]=0x00000038u;
goto P_0c03d644;
P_0c03d644: /* original fff7, guest PC 0x0c03d644 */
if(!s->budget--) { s->failed_pc=0x0c03d644u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c03d646;
P_0c03d646: /* original e03c, guest PC 0x0c03d646 */
if(!s->budget--) { s->failed_pc=0x0c03d646u; return 0; }
r[0]=0x0000003cu;
goto P_0c03d648;
P_0c03d648: /* original fff7, guest PC 0x0c03d648 */
if(!s->budget--) { s->failed_pc=0x0c03d648u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c03d64a;
P_0c03d64a: /* original f3ec, guest PC 0x0c03d64a */
if(!s->budget--) { s->failed_pc=0x0c03d64au; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c03d64c;
P_0c03d64c: /* original f4ec, guest PC 0x0c03d64c */
if(!s->budget--) { s->failed_pc=0x0c03d64cu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c03d64e;
P_0c03d64e: /* original f4c1, guest PC 0x0c03d64e */
if(!s->budget--) { s->failed_pc=0x0c03d64eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[12],r[18],'-');
goto P_0c03d650;
P_0c03d650: /* original f3c0, guest PC 0x0c03d650 */
if(!s->budget--) { s->failed_pc=0x0c03d650u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'+');
goto P_0c03d652;
P_0c03d652: /* original e040, guest PC 0x0c03d652 */
if(!s->budget--) { s->failed_pc=0x0c03d652u; return 0; }
r[0]=0x00000040u;
goto P_0c03d654;
P_0c03d654: /* original f343, guest PC 0x0c03d654 */
if(!s->budget--) { s->failed_pc=0x0c03d654u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'/');
goto P_0c03d656;
P_0c03d656: /* original ff37, guest PC 0x0c03d656 */
if(!s->budget--) { s->failed_pc=0x0c03d656u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03d658;
P_0c03d658: /* original c71e, guest PC 0x0c03d658 */
if(!s->budget--) { s->failed_pc=0x0c03d658u; return 0; }
r[0]=code_base|0x0003d6d4u;
goto P_0c03d65a;
P_0c03d65a: /* original f308, guest PC 0x0c03d65a */
if(!s->budget--) { s->failed_pc=0x0c03d65au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03d65c;
P_0c03d65c: /* original e044, guest PC 0x0c03d65c */
if(!s->budget--) { s->failed_pc=0x0c03d65cu; return 0; }
r[0]=0x00000044u;
goto P_0c03d65e;
P_0c03d65e: /* original ff37, guest PC 0x0c03d65e */
if(!s->budget--) { s->failed_pc=0x0c03d65eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03d660;
P_0c03d660: /* original e048, guest PC 0x0c03d660 */
if(!s->budget--) { s->failed_pc=0x0c03d660u; return 0; }
r[0]=0x00000048u;
goto P_0c03d662;
P_0c03d662: /* original fff7, guest PC 0x0c03d662 */
if(!s->budget--) { s->failed_pc=0x0c03d662u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c03d664;
P_0c03d664: /* original e04c, guest PC 0x0c03d664 */
if(!s->budget--) { s->failed_pc=0x0c03d664u; return 0; }
r[0]=0x0000004cu;
goto P_0c03d666;
P_0c03d666: /* original fff7, guest PC 0x0c03d666 */
if(!s->budget--) { s->failed_pc=0x0c03d666u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c03d668;
P_0c03d668: /* original c71b, guest PC 0x0c03d668 */
if(!s->budget--) { s->failed_pc=0x0c03d668u; return 0; }
r[0]=code_base|0x0003d6d8u;
goto P_0c03d66a;
P_0c03d66a: /* original f3ec, guest PC 0x0c03d66a */
if(!s->budget--) { s->failed_pc=0x0c03d66au; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c03d66c;
P_0c03d66c: /* original f3c2, guest PC 0x0c03d66c */
if(!s->budget--) { s->failed_pc=0x0c03d66cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'*');
goto P_0c03d66e;
P_0c03d66e: /* original f208, guest PC 0x0c03d66e */
if(!s->budget--) { s->failed_pc=0x0c03d66eu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03d670;
P_0c03d670: /* original e050, guest PC 0x0c03d670 */
if(!s->budget--) { s->failed_pc=0x0c03d670u; return 0; }
r[0]=0x00000050u;
goto P_0c03d672;
P_0c03d672: /* original f322, guest PC 0x0c03d672 */
if(!s->budget--) { s->failed_pc=0x0c03d672u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c03d674;
P_0c03d674: /* original f343, guest PC 0x0c03d674 */
if(!s->budget--) { s->failed_pc=0x0c03d674u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'/');
goto P_0c03d676;
P_0c03d676: /* original ff37, guest PC 0x0c03d676 */
if(!s->budget--) { s->failed_pc=0x0c03d676u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03d678;
P_0c03d678: /* original e054, guest PC 0x0c03d678 */
if(!s->budget--) { s->failed_pc=0x0c03d678u; return 0; }
r[0]=0x00000054u;
goto P_0c03d67a;
P_0c03d67a: /* original fff7, guest PC 0x0c03d67a */
if(!s->budget--) { s->failed_pc=0x0c03d67au; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c03d67c;
P_0c03d67c: /* original e01c, guest PC 0x0c03d67c */
if(!s->budget--) { s->failed_pc=0x0c03d67cu; return 0; }
r[0]=0x0000001cu;
goto P_0c03d67e;
P_0c03d67e: /* original d417, guest PC 0x0c03d67e */
if(!s->budget--) { s->failed_pc=0x0c03d67eu; return 0; }
r[4]=read(ram,0x0c03d6dcu,4);
goto P_0c03d680;
P_0c03d680: /* original f4e7, guest PC 0x0c03d680 */
if(!s->budget--) { s->failed_pc=0x0c03d680u; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c03d682;
P_0c03d682: /* original e020, guest PC 0x0c03d682 */
if(!s->budget--) { s->failed_pc=0x0c03d682u; return 0; }
r[0]=0x00000020u;
goto P_0c03d684;
P_0c03d684: /* original f4c7, guest PC 0x0c03d684 */
if(!s->budget--) { s->failed_pc=0x0c03d684u; return 0; }
vf3_matrix_store(s,ram,12,r[4]+r[0]);
goto P_0c03d686;
P_0c03d686: /* original e024, guest PC 0x0c03d686 */
if(!s->budget--) { s->failed_pc=0x0c03d686u; return 0; }
r[0]=0x00000024u;
goto P_0c03d688;
P_0c03d688: /* original f4dc, guest PC 0x0c03d688 */
if(!s->budget--) { s->failed_pc=0x0c03d688u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c03d68a;
P_0c03d68a: /* original f4e3, guest PC 0x0c03d68a */
if(!s->budget--) { s->failed_pc=0x0c03d68au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'/');
goto P_0c03d68c;
P_0c03d68c: /* original f447, guest PC 0x0c03d68c */
if(!s->budget--) { s->failed_pc=0x0c03d68cu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c03d68e;
P_0c03d68e: /* original d414, guest PC 0x0c03d68e */
if(!s->budget--) { s->failed_pc=0x0c03d68eu; return 0; }
r[4]=read(ram,0x0c03d6e0u,4);
goto P_0c03d690;
P_0c03d690: /* original f4e7, guest PC 0x0c03d690 */
if(!s->budget--) { s->failed_pc=0x0c03d690u; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c03d692;
P_0c03d692: /* original e00c, guest PC 0x0c03d692 */
if(!s->budget--) { s->failed_pc=0x0c03d692u; return 0; }
r[0]=0x0000000cu;
goto P_0c03d694;
P_0c03d694: /* original fe4d, guest PC 0x0c03d694 */
if(!s->budget--) { s->failed_pc=0x0c03d694u; return 0; }
fr[14]^=0x80000000u;
goto P_0c03d696;
P_0c03d696: /* original f4e7, guest PC 0x0c03d696 */
if(!s->budget--) { s->failed_pc=0x0c03d696u; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c03d698;
P_0c03d698: /* original e028, guest PC 0x0c03d698 */
if(!s->budget--) { s->failed_pc=0x0c03d698u; return 0; }
r[0]=0x00000028u;
goto P_0c03d69a;
P_0c03d69a: /* original f4c7, guest PC 0x0c03d69a */
if(!s->budget--) { s->failed_pc=0x0c03d69au; return 0; }
vf3_matrix_store(s,ram,12,r[4]+r[0]);
goto P_0c03d69c;
P_0c03d69c: /* original e020, guest PC 0x0c03d69c */
if(!s->budget--) { s->failed_pc=0x0c03d69cu; return 0; }
r[0]=0x00000020u;
goto P_0c03d69e;
P_0c03d69e: /* original f447, guest PC 0x0c03d69e */
if(!s->budget--) { s->failed_pc=0x0c03d69eu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c03d6a0;
P_0c03d6a0: /* original 64f3, guest PC 0x0c03d6a0 */
if(!s->budget--) { s->failed_pc=0x0c03d6a0u; return 0; }
r[4]=r[15];
goto P_0c03d6a2;
P_0c03d6a2: /* original d310, guest PC 0x0c03d6a2 */
if(!s->budget--) { s->failed_pc=0x0c03d6a2u; return 0; }
r[3]=read(ram,0x0c03d6e4u,4);
goto P_0c03d6a4;
P_0c03d6a4: /* original 430b, guest PC 0x0c03d6a4 */
if(!s->budget--) { s->failed_pc=0x0c03d6a4u; return 0; }
target=r[3];
r[16]=code_base|0x0c03d6a8u;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d6a8u) { target=s->pc; goto dispatch; }
goto P_0c03d6a8;
P_0c03d6a6: /* original 7418, guest PC 0x0c03d6a6 */
if(!s->budget--) { s->failed_pc=0x0c03d6a6u; return 0; }
r[4]+=0x00000018u;
goto P_0c03d6a8;
P_0c03d6a8: /* original 7f58, guest PC 0x0c03d6a8 */
if(!s->budget--) { s->failed_pc=0x0c03d6a8u; return 0; }
r[15]+=0x00000058u;
goto P_0c03d6aa;
P_0c03d6aa: /* original 4f26, guest PC 0x0c03d6aa */
if(!s->budget--) { s->failed_pc=0x0c03d6aau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03d6ac;
P_0c03d6ac: /* original fcf9, guest PC 0x0c03d6ac */
if(!s->budget--) { s->failed_pc=0x0c03d6acu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03d6ae;
P_0c03d6ae: /* original fdf9, guest PC 0x0c03d6ae */
if(!s->budget--) { s->failed_pc=0x0c03d6aeu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03d6b0;
P_0c03d6b0: /* original fef9, guest PC 0x0c03d6b0 */
if(!s->budget--) { s->failed_pc=0x0c03d6b0u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03d6b2;
P_0c03d6b2: /* original fff9, guest PC 0x0c03d6b2 */
if(!s->budget--) { s->failed_pc=0x0c03d6b2u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03d6b4;
P_0c03d6b4: /* original 69f6, guest PC 0x0c03d6b4 */
if(!s->budget--) { s->failed_pc=0x0c03d6b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03d6b6;
P_0c03d6b6: /* original 6af6, guest PC 0x0c03d6b6 */
if(!s->budget--) { s->failed_pc=0x0c03d6b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03d6b8;
P_0c03d6b8: /* original 6bf6, guest PC 0x0c03d6b8 */
if(!s->budget--) { s->failed_pc=0x0c03d6b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03d6ba;
P_0c03d6ba: /* original 6cf6, guest PC 0x0c03d6ba */
if(!s->budget--) { s->failed_pc=0x0c03d6bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03d6bc;
P_0c03d6bc: /* original 6df6, guest PC 0x0c03d6bc */
if(!s->budget--) { s->failed_pc=0x0c03d6bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03d6be;
P_0c03d6be: /* original 000b, guest PC 0x0c03d6be */
if(!s->budget--) { s->failed_pc=0x0c03d6beu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03d6c0: /* original 6ef6, guest PC 0x0c03d6c0 */
if(!s->budget--) { s->failed_pc=0x0c03d6c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03d6c2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03d6c2u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
