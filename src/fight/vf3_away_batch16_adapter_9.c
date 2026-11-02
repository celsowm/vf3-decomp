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
int vf3_away_batch16_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c08d898u: goto P_0c08d898;
case 0x0c08d89au: goto P_0c08d89a;
case 0x0c08d89cu: goto P_0c08d89c;
case 0x0c08d89eu: goto P_0c08d89e;
case 0x0c08d8a0u: goto P_0c08d8a0;
case 0x0c08d8a2u: goto P_0c08d8a2;
case 0x0c08d8a4u: goto P_0c08d8a4;
case 0x0c08d8a6u: goto P_0c08d8a6;
case 0x0c08d8a8u: goto P_0c08d8a8;
case 0x0c08d8aau: goto P_0c08d8aa;
case 0x0c08d8acu: goto P_0c08d8ac;
case 0x0c08d8aeu: goto P_0c08d8ae;
case 0x0c08d8b0u: goto P_0c08d8b0;
case 0x0c08d8b2u: goto P_0c08d8b2;
case 0x0c08d8b4u: goto P_0c08d8b4;
case 0x0c08d8b6u: goto P_0c08d8b6;
case 0x0c08d8b8u: goto P_0c08d8b8;
case 0x0c08d8bau: goto P_0c08d8ba;
case 0x0c08d8bcu: goto P_0c08d8bc;
case 0x0c08d8beu: goto P_0c08d8be;
case 0x0c08d8c0u: goto P_0c08d8c0;
case 0x0c08d8c2u: goto P_0c08d8c2;
case 0x0c08d8c4u: goto P_0c08d8c4;
case 0x0c08d8c6u: goto P_0c08d8c6;
case 0x0c08d8c8u: goto P_0c08d8c8;
case 0x0c08d8cau: goto P_0c08d8ca;
case 0x0c08d8ccu: goto P_0c08d8cc;
case 0x0c08d8ceu: goto P_0c08d8ce;
case 0x0c08d8d0u: goto P_0c08d8d0;
case 0x0c08d8d2u: goto P_0c08d8d2;
case 0x0c08d8d4u: goto P_0c08d8d4;
case 0x0c08d8d6u: goto P_0c08d8d6;
case 0x0c08d8d8u: goto P_0c08d8d8;
case 0x0c08d8dau: goto P_0c08d8da;
case 0x0c08d8dcu: goto P_0c08d8dc;
case 0x0c08d8deu: goto P_0c08d8de;
case 0x0c08d8e0u: goto P_0c08d8e0;
case 0x0c08d8e2u: goto P_0c08d8e2;
case 0x0c08d8e4u: goto P_0c08d8e4;
case 0x0c08d8e6u: goto P_0c08d8e6;
case 0x0c08d8e8u: goto P_0c08d8e8;
case 0x0c08d8eau: goto P_0c08d8ea;
case 0x0c08d8ecu: goto P_0c08d8ec;
case 0x0c08d8eeu: goto P_0c08d8ee;
case 0x0c08d8f0u: goto P_0c08d8f0;
case 0x0c08d8f2u: goto P_0c08d8f2;
case 0x0c08d8f4u: goto P_0c08d8f4;
case 0x0c08d8f6u: goto P_0c08d8f6;
case 0x0c08d8f8u: goto P_0c08d8f8;
case 0x0c08d8fau: goto P_0c08d8fa;
case 0x0c08d8fcu: goto P_0c08d8fc;
case 0x0c08d8feu: goto P_0c08d8fe;
case 0x0c08d900u: goto P_0c08d900;
case 0x0c08d902u: goto P_0c08d902;
case 0x0c08d904u: goto P_0c08d904;
case 0x0c08d906u: goto P_0c08d906;
case 0x0c08d908u: goto P_0c08d908;
case 0x0c08d90au: goto P_0c08d90a;
case 0x0c08d90cu: goto P_0c08d90c;
case 0x0c08d90eu: goto P_0c08d90e;
case 0x0c08d910u: goto P_0c08d910;
case 0x0c08d912u: goto P_0c08d912;
case 0x0c08d914u: goto P_0c08d914;
case 0x0c08d916u: goto P_0c08d916;
case 0x0c08d918u: goto P_0c08d918;
case 0x0c08d91au: goto P_0c08d91a;
case 0x0c08d91cu: goto P_0c08d91c;
case 0x0c08d91eu: goto P_0c08d91e;
case 0x0c08d920u: goto P_0c08d920;
case 0x0c08d922u: goto P_0c08d922;
case 0x0c08d924u: goto P_0c08d924;
case 0x0c08d926u: goto P_0c08d926;
case 0x0c08d928u: goto P_0c08d928;
case 0x0c08d92au: goto P_0c08d92a;
case 0x0c08d92cu: goto P_0c08d92c;
case 0x0c08d92eu: goto P_0c08d92e;
case 0x0c08d930u: goto P_0c08d930;
case 0x0c08d932u: goto P_0c08d932;
case 0x0c08d934u: goto P_0c08d934;
case 0x0c08d936u: goto P_0c08d936;
case 0x0c08d938u: goto P_0c08d938;
case 0x0c08d93au: goto P_0c08d93a;
case 0x0c08d93cu: goto P_0c08d93c;
case 0x0c08d93eu: goto P_0c08d93e;
case 0x0c08d940u: goto P_0c08d940;
case 0x0c08d942u: goto P_0c08d942;
case 0x0c08d944u: goto P_0c08d944;
case 0x0c08d946u: goto P_0c08d946;
case 0x0c08d948u: goto P_0c08d948;
case 0x0c08d94au: goto P_0c08d94a;
case 0x0c08d94cu: goto P_0c08d94c;
case 0x0c08d94eu: goto P_0c08d94e;
case 0x0c08d950u: goto P_0c08d950;
case 0x0c08d952u: goto P_0c08d952;
case 0x0c08d954u: goto P_0c08d954;
case 0x0c08d956u: goto P_0c08d956;
case 0x0c08d990u: goto P_0c08d990;
case 0x0c08d992u: goto P_0c08d992;
case 0x0c08d994u: goto P_0c08d994;
case 0x0c08d996u: goto P_0c08d996;
case 0x0c08d998u: goto P_0c08d998;
case 0x0c08d99au: goto P_0c08d99a;
case 0x0c08d99cu: goto P_0c08d99c;
case 0x0c08d99eu: goto P_0c08d99e;
case 0x0c08d9a0u: goto P_0c08d9a0;
case 0x0c08d9a2u: goto P_0c08d9a2;
case 0x0c08d9a4u: goto P_0c08d9a4;
case 0x0c08d9a6u: goto P_0c08d9a6;
case 0x0c08d9a8u: goto P_0c08d9a8;
case 0x0c08d9aau: goto P_0c08d9aa;
case 0x0c08d9acu: goto P_0c08d9ac;
case 0x0c08d9aeu: goto P_0c08d9ae;
case 0x0c08d9b0u: goto P_0c08d9b0;
case 0x0c08d9b2u: goto P_0c08d9b2;
case 0x0c08d9b4u: goto P_0c08d9b4;
case 0x0c08d9b6u: goto P_0c08d9b6;
case 0x0c08d9b8u: goto P_0c08d9b8;
case 0x0c08d9bau: goto P_0c08d9ba;
case 0x0c08d9bcu: goto P_0c08d9bc;
case 0x0c08d9beu: goto P_0c08d9be;
case 0x0c08d9c0u: goto P_0c08d9c0;
case 0x0c08d9c2u: goto P_0c08d9c2;
case 0x0c08d9c4u: goto P_0c08d9c4;
case 0x0c08d9c6u: goto P_0c08d9c6;
case 0x0c08d9c8u: goto P_0c08d9c8;
case 0x0c08d9cau: goto P_0c08d9ca;
case 0x0c08d9ccu: goto P_0c08d9cc;
case 0x0c08d9ceu: goto P_0c08d9ce;
case 0x0c08d9d0u: goto P_0c08d9d0;
case 0x0c08d9d2u: goto P_0c08d9d2;
case 0x0c08d9d4u: goto P_0c08d9d4;
case 0x0c08d9d6u: goto P_0c08d9d6;
case 0x0c08d9d8u: goto P_0c08d9d8;
case 0x0c08d9dau: goto P_0c08d9da;
case 0x0c08d9dcu: goto P_0c08d9dc;
case 0x0c08d9deu: goto P_0c08d9de;
case 0x0c08d9e0u: goto P_0c08d9e0;
case 0x0c08d9e2u: goto P_0c08d9e2;
case 0x0c08d9e4u: goto P_0c08d9e4;
case 0x0c08d9e6u: goto P_0c08d9e6;
case 0x0c08d9e8u: goto P_0c08d9e8;
case 0x0c08d9eau: goto P_0c08d9ea;
case 0x0c08d9ecu: goto P_0c08d9ec;
case 0x0c08d9eeu: goto P_0c08d9ee;
case 0x0c08d9f0u: goto P_0c08d9f0;
case 0x0c08d9f2u: goto P_0c08d9f2;
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
P_0c08d898: /* original 2fe6, guest PC 0x0c08d898 */
if(!s->budget--) { s->failed_pc=0x0c08d898u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d89a;
P_0c08d89a: /* original d530, guest PC 0x0c08d89a */
if(!s->budget--) { s->failed_pc=0x0c08d89au; return 0; }
r[5]=read(ram,0x0c08d95cu,4);
goto P_0c08d89c;
P_0c08d89c: /* original 5354, guest PC 0x0c08d89c */
if(!s->budget--) { s->failed_pc=0x0c08d89cu; return 0; }
r[3]=read(ram,r[5]+16,4);
goto P_0c08d89e;
P_0c08d89e: /* original 3430, guest PC 0x0c08d89e */
if(!s->budget--) { s->failed_pc=0x0c08d89eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c08d8a0;
P_0c08d8a0: /* original 8b01, guest PC 0x0c08d8a0 */
if(!s->budget--) { s->failed_pc=0x0c08d8a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08d8a6; }
goto P_0c08d8a2;
P_0c08d8a2: /* original a001, guest PC 0x0c08d8a2 */
if(!s->budget--) { s->failed_pc=0x0c08d8a2u; return 0; }
r[14]=read(ram,r[5]+20,4);
goto P_0c08d8a8;
P_0c08d8a4: /* original 5e55, guest PC 0x0c08d8a4 */
if(!s->budget--) { s->failed_pc=0x0c08d8a4u; return 0; }
r[14]=read(ram,r[5]+20,4);
goto P_0c08d8a6;
P_0c08d8a6: /* original 5e54, guest PC 0x0c08d8a6 */
if(!s->budget--) { s->failed_pc=0x0c08d8a6u; return 0; }
r[14]=read(ram,r[5]+16,4);
goto P_0c08d8a8;
P_0c08d8a8: /* original d72d, guest PC 0x0c08d8a8 */
if(!s->budget--) { s->failed_pc=0x0c08d8a8u; return 0; }
r[7]=read(ram,0x0c08d960u,4);
goto P_0c08d8aa;
P_0c08d8aa: /* original d62e, guest PC 0x0c08d8aa */
if(!s->budget--) { s->failed_pc=0x0c08d8aau; return 0; }
r[6]=read(ram,0x0c08d964u,4);
goto P_0c08d8ac;
P_0c08d8ac: /* original 6572, guest PC 0x0c08d8ac */
if(!s->budget--) { s->failed_pc=0x0c08d8acu; return 0; }
tmp=read(ram,r[7],4);
r[5]=tmp;
goto P_0c08d8ae;
P_0c08d8ae: /* original 6253, guest PC 0x0c08d8ae */
if(!s->budget--) { s->failed_pc=0x0c08d8aeu; return 0; }
r[2]=r[5];
goto P_0c08d8b0;
P_0c08d8b0: /* original 2268, guest PC 0x0c08d8b0 */
if(!s->budget--) { s->failed_pc=0x0c08d8b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c08d8b2;
P_0c08d8b2: /* original 8b0c, guest PC 0x0c08d8b2 */
if(!s->budget--) { s->failed_pc=0x0c08d8b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08d8ce; }
goto P_0c08d8b4;
P_0c08d8b4: /* original d32c, guest PC 0x0c08d8b4 */
if(!s->budget--) { s->failed_pc=0x0c08d8b4u; return 0; }
r[3]=read(ram,0x0c08d968u,4);
goto P_0c08d8b6;
P_0c08d8b6: /* original 2538, guest PC 0x0c08d8b6 */
if(!s->budget--) { s->failed_pc=0x0c08d8b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c08d8b8;
P_0c08d8b8: /* original 8902, guest PC 0x0c08d8b8 */
if(!s->budget--) { s->failed_pc=0x0c08d8b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08d8c0; }
goto P_0c08d8ba;
P_0c08d8ba: /* original 5571, guest PC 0x0c08d8ba */
if(!s->budget--) { s->failed_pc=0x0c08d8bau; return 0; }
r[5]=read(ram,r[7]+4,4);
goto P_0c08d8bc;
P_0c08d8bc: /* original 2568, guest PC 0x0c08d8bc */
if(!s->budget--) { s->failed_pc=0x0c08d8bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[6])==0)!=0);
goto P_0c08d8be;
P_0c08d8be: /* original 8b06, guest PC 0x0c08d8be */
if(!s->budget--) { s->failed_pc=0x0c08d8beu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08d8ce; }
goto P_0c08d8c0;
P_0c08d8c0: /* original 6542, guest PC 0x0c08d8c0 */
if(!s->budget--) { s->failed_pc=0x0c08d8c0u; return 0; }
tmp=read(ram,r[4],4);
r[5]=tmp;
goto P_0c08d8c2;
P_0c08d8c2: /* original e301, guest PC 0x0c08d8c2 */
if(!s->budget--) { s->failed_pc=0x0c08d8c2u; return 0; }
r[3]=0x00000001u;
goto P_0c08d8c4;
P_0c08d8c4: /* original 2358, guest PC 0x0c08d8c4 */
if(!s->budget--) { s->failed_pc=0x0c08d8c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c08d8c6;
P_0c08d8c6: /* original 8905, guest PC 0x0c08d8c6 */
if(!s->budget--) { s->failed_pc=0x0c08d8c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08d8d4; }
goto P_0c08d8c8;
P_0c08d8c8: /* original d128, guest PC 0x0c08d8c8 */
if(!s->budget--) { s->failed_pc=0x0c08d8c8u; return 0; }
r[1]=read(ram,0x0c08d96cu,4);
goto P_0c08d8ca;
P_0c08d8ca: /* original 2518, guest PC 0x0c08d8ca */
if(!s->budget--) { s->failed_pc=0x0c08d8cau; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[1])==0)!=0);
goto P_0c08d8cc;
P_0c08d8cc: /* original 8902, guest PC 0x0c08d8cc */
if(!s->budget--) { s->failed_pc=0x0c08d8ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08d8d4; }
goto P_0c08d8ce;
P_0c08d8ce: /* original 65e3, guest PC 0x0c08d8ce */
if(!s->budget--) { s->failed_pc=0x0c08d8ceu; return 0; }
r[5]=r[14];
goto P_0c08d8d0;
P_0c08d8d0: /* original a002, guest PC 0x0c08d8d0 */
if(!s->budget--) { s->failed_pc=0x0c08d8d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08d8d8;
P_0c08d8d2: /* original 6ef6, guest PC 0x0c08d8d2 */
if(!s->budget--) { s->failed_pc=0x0c08d8d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08d8d4;
P_0c08d8d4: /* original 000b, guest PC 0x0c08d8d4 */
if(!s->budget--) { s->failed_pc=0x0c08d8d4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08d8d6: /* original 6ef6, guest PC 0x0c08d8d6 */
if(!s->budget--) { s->failed_pc=0x0c08d8d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08d8d8;
P_0c08d8d8: /* original 2fe6, guest PC 0x0c08d8d8 */
if(!s->budget--) { s->failed_pc=0x0c08d8d8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d8da;
P_0c08d8da: /* original 6e43, guest PC 0x0c08d8da */
if(!s->budget--) { s->failed_pc=0x0c08d8dau; return 0; }
r[14]=r[4];
goto P_0c08d8dc;
P_0c08d8dc: /* original 2fd6, guest PC 0x0c08d8dc */
if(!s->budget--) { s->failed_pc=0x0c08d8dcu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d8de;
P_0c08d8de: /* original 6d53, guest PC 0x0c08d8de */
if(!s->budget--) { s->failed_pc=0x0c08d8deu; return 0; }
r[13]=r[5];
goto P_0c08d8e0;
P_0c08d8e0: /* original 4f22, guest PC 0x0c08d8e0 */
if(!s->budget--) { s->failed_pc=0x0c08d8e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08d8e2;
P_0c08d8e2: /* original d323, guest PC 0x0c08d8e2 */
if(!s->budget--) { s->failed_pc=0x0c08d8e2u; return 0; }
r[3]=read(ram,0x0c08d970u,4);
goto P_0c08d8e4;
P_0c08d8e4: /* original 7ffc, guest PC 0x0c08d8e4 */
if(!s->budget--) { s->failed_pc=0x0c08d8e4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08d8e6;
P_0c08d8e6: /* original 430b, guest PC 0x0c08d8e6 */
if(!s->budget--) { s->failed_pc=0x0c08d8e6u; return 0; }
target=r[3];
r[16]=code_base|0x0c08d8eau;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d8eau) { target=s->pc; goto dispatch; }
goto P_0c08d8ea;
P_0c08d8e8: /* original e400, guest PC 0x0c08d8e8 */
if(!s->budget--) { s->failed_pc=0x0c08d8e8u; return 0; }
r[4]=0x00000000u;
goto P_0c08d8ea;
P_0c08d8ea: /* original d222, guest PC 0x0c08d8ea */
if(!s->budget--) { s->failed_pc=0x0c08d8eau; return 0; }
r[2]=read(ram,0x0c08d974u,4);
goto P_0c08d8ec;
P_0c08d8ec: /* original 9434, guest PC 0x0c08d8ec */
if(!s->budget--) { s->failed_pc=0x0c08d8ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08d958u,2);
goto P_0c08d8ee;
P_0c08d8ee: /* original 420b, guest PC 0x0c08d8ee */
if(!s->budget--) { s->failed_pc=0x0c08d8eeu; return 0; }
target=r[2];
r[16]=code_base|0x0c08d8f2u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d8f2u) { target=s->pc; goto dispatch; }
goto P_0c08d8f2;
P_0c08d8f0: /* original 34ec, guest PC 0x0c08d8f0 */
if(!s->budget--) { s->failed_pc=0x0c08d8f0u; return 0; }
r[4]+=r[14];
goto P_0c08d8f2;
P_0c08d8f2: /* original d122, guest PC 0x0c08d8f2 */
if(!s->budget--) { s->failed_pc=0x0c08d8f2u; return 0; }
r[1]=read(ram,0x0c08d97cu,4);
goto P_0c08d8f4;
P_0c08d8f4: /* original d320, guest PC 0x0c08d8f4 */
if(!s->budget--) { s->failed_pc=0x0c08d8f4u; return 0; }
r[3]=read(ram,0x0c08d978u,4);
goto P_0c08d8f6;
P_0c08d8f6: /* original 6212, guest PC 0x0c08d8f6 */
if(!s->budget--) { s->failed_pc=0x0c08d8f6u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c08d8f8;
P_0c08d8f8: /* original 2238, guest PC 0x0c08d8f8 */
if(!s->budget--) { s->failed_pc=0x0c08d8f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c08d8fa;
P_0c08d8fa: /* original 8b19, guest PC 0x0c08d8fa */
if(!s->budget--) { s->failed_pc=0x0c08d8fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08d930; }
goto P_0c08d8fc;
P_0c08d8fc: /* original d418, guest PC 0x0c08d8fc */
if(!s->budget--) { s->failed_pc=0x0c08d8fcu; return 0; }
r[4]=read(ram,0x0c08d960u,4);
goto P_0c08d8fe;
P_0c08d8fe: /* original d320, guest PC 0x0c08d8fe */
if(!s->budget--) { s->failed_pc=0x0c08d8feu; return 0; }
r[3]=read(ram,0x0c08d980u,4);
goto P_0c08d900;
P_0c08d900: /* original 6542, guest PC 0x0c08d900 */
if(!s->budget--) { s->failed_pc=0x0c08d900u; return 0; }
tmp=read(ram,r[4],4);
r[5]=tmp;
goto P_0c08d902;
P_0c08d902: /* original 8449, guest PC 0x0c08d902 */
if(!s->budget--) { s->failed_pc=0x0c08d902u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+9,1);
goto P_0c08d904;
P_0c08d904: /* original 2358, guest PC 0x0c08d904 */
if(!s->budget--) { s->failed_pc=0x0c08d904u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c08d906;
P_0c08d906: /* original 8d06, guest PC 0x0c08d906 */
if(!s->budget--) { s->failed_pc=0x0c08d906u; return 0; }
cond=r[17]&1u;
r[6]=r[0]&255u;
if(cond) { goto P_0c08d916; }
goto P_0c08d90a;
P_0c08d908: /* original 660c, guest PC 0x0c08d908 */
if(!s->budget--) { s->failed_pc=0x0c08d908u; return 0; }
r[6]=r[0]&255u;
goto P_0c08d90a;
P_0c08d90a: /* original d31e, guest PC 0x0c08d90a */
if(!s->budget--) { s->failed_pc=0x0c08d90au; return 0; }
r[3]=read(ram,0x0c08d984u,4);
goto P_0c08d90c;
P_0c08d90c: /* original 5441, guest PC 0x0c08d90c */
if(!s->budget--) { s->failed_pc=0x0c08d90cu; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c08d90e;
P_0c08d90e: /* original 2438, guest PC 0x0c08d90e */
if(!s->budget--) { s->failed_pc=0x0c08d90eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c08d910;
P_0c08d910: /* original 8b13, guest PC 0x0c08d910 */
if(!s->budget--) { s->failed_pc=0x0c08d910u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08d93a; }
goto P_0c08d912;
P_0c08d912: /* original a044, guest PC 0x0c08d912 */
if(!s->budget--) { s->failed_pc=0x0c08d912u; return 0; }
goto P_0c08d99e;
P_0c08d914: /* original 0009, guest PC 0x0c08d914 */
if(!s->budget--) { s->failed_pc=0x0c08d914u; return 0; }
goto P_0c08d916;
P_0c08d916: /* original d71c, guest PC 0x0c08d916 */
if(!s->budget--) { s->failed_pc=0x0c08d916u; return 0; }
r[7]=read(ram,0x0c08d988u,4);
goto P_0c08d918;
P_0c08d918: /* original 2578, guest PC 0x0c08d918 */
if(!s->budget--) { s->failed_pc=0x0c08d918u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[7])==0)!=0);
goto P_0c08d91a;
P_0c08d91a: /* original 8939, guest PC 0x0c08d91a */
if(!s->budget--) { s->failed_pc=0x0c08d91au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08d990; }
goto P_0c08d91c;
P_0c08d91c: /* original 6063, guest PC 0x0c08d91c */
if(!s->budget--) { s->failed_pc=0x0c08d91cu; return 0; }
r[0]=r[6];
goto P_0c08d91e;
P_0c08d91e: /* original 880e, guest PC 0x0c08d91e */
if(!s->budget--) { s->failed_pc=0x0c08d91eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c08d920;
P_0c08d920: /* original 8b04, guest PC 0x0c08d920 */
if(!s->budget--) { s->failed_pc=0x0c08d920u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08d92c; }
goto P_0c08d922;
P_0c08d922: /* original 65d3, guest PC 0x0c08d922 */
if(!s->budget--) { s->failed_pc=0x0c08d922u; return 0; }
r[5]=r[13];
goto P_0c08d924;
P_0c08d924: /* original b04d, guest PC 0x0c08d924 */
if(!s->budget--) { s->failed_pc=0x0c08d924u; return 0; }
target=code_base|0x0c08d9c2u; r[16]=code_base|0x0c08d928u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d928u) { target=s->pc; goto dispatch; }
goto P_0c08d928;
P_0c08d926: /* original 64e3, guest PC 0x0c08d926 */
if(!s->budget--) { s->failed_pc=0x0c08d926u; return 0; }
r[4]=r[14];
goto P_0c08d928;
P_0c08d928: /* original a044, guest PC 0x0c08d928 */
if(!s->budget--) { s->failed_pc=0x0c08d928u; return 0; }
goto P_0c08d9b4;
P_0c08d92a: /* original 0009, guest PC 0x0c08d92a */
if(!s->budget--) { s->failed_pc=0x0c08d92au; return 0; }
goto P_0c08d92c;
P_0c08d92c: /* original 880f, guest PC 0x0c08d92c */
if(!s->budget--) { s->failed_pc=0x0c08d92cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c08d92e;
P_0c08d92e: /* original 8b04, guest PC 0x0c08d92e */
if(!s->budget--) { s->failed_pc=0x0c08d92eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08d93a; }
goto P_0c08d930;
P_0c08d930: /* original 65d3, guest PC 0x0c08d930 */
if(!s->budget--) { s->failed_pc=0x0c08d930u; return 0; }
r[5]=r[13];
goto P_0c08d932;
P_0c08d932: /* original b0b6, guest PC 0x0c08d932 */
if(!s->budget--) { s->failed_pc=0x0c08d932u; return 0; }
target=code_base|0x0c08daa2u; r[16]=code_base|0x0c08d936u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d936u) { target=s->pc; goto dispatch; }
goto P_0c08d936;
P_0c08d934: /* original 64e3, guest PC 0x0c08d934 */
if(!s->budget--) { s->failed_pc=0x0c08d934u; return 0; }
r[4]=r[14];
goto P_0c08d936;
P_0c08d936: /* original a03d, guest PC 0x0c08d936 */
if(!s->budget--) { s->failed_pc=0x0c08d936u; return 0; }
goto P_0c08d9b4;
P_0c08d938: /* original 0009, guest PC 0x0c08d938 */
if(!s->budget--) { s->failed_pc=0x0c08d938u; return 0; }
goto P_0c08d93a;
P_0c08d93a: /* original e048, guest PC 0x0c08d93a */
if(!s->budget--) { s->failed_pc=0x0c08d93au; return 0; }
r[0]=0x00000048u;
goto P_0c08d93c;
P_0c08d93c: /* original d313, guest PC 0x0c08d93c */
if(!s->budget--) { s->failed_pc=0x0c08d93cu; return 0; }
r[3]=read(ram,0x0c08d98cu,4);
goto P_0c08d93e;
P_0c08d93e: /* original 04ee, guest PC 0x0c08d93e */
if(!s->budget--) { s->failed_pc=0x0c08d93eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c08d940;
P_0c08d940: /* original 2438, guest PC 0x0c08d940 */
if(!s->budget--) { s->failed_pc=0x0c08d940u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c08d942;
P_0c08d942: /* original 8904, guest PC 0x0c08d942 */
if(!s->budget--) { s->failed_pc=0x0c08d942u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08d94e; }
goto P_0c08d944;
P_0c08d944: /* original 65d3, guest PC 0x0c08d944 */
if(!s->budget--) { s->failed_pc=0x0c08d944u; return 0; }
r[5]=r[13];
goto P_0c08d946;
P_0c08d946: /* original b055, guest PC 0x0c08d946 */
if(!s->budget--) { s->failed_pc=0x0c08d946u; return 0; }
target=code_base|0x0c08d9f4u; r[16]=code_base|0x0c08d94au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d94au) { target=s->pc; goto dispatch; }
goto P_0c08d94a;
P_0c08d948: /* original 64e3, guest PC 0x0c08d948 */
if(!s->budget--) { s->failed_pc=0x0c08d948u; return 0; }
r[4]=r[14];
goto P_0c08d94a;
P_0c08d94a: /* original a033, guest PC 0x0c08d94a */
if(!s->budget--) { s->failed_pc=0x0c08d94au; return 0; }
goto P_0c08d9b4;
P_0c08d94c: /* original 0009, guest PC 0x0c08d94c */
if(!s->budget--) { s->failed_pc=0x0c08d94cu; return 0; }
goto P_0c08d94e;
P_0c08d94e: /* original 65d3, guest PC 0x0c08d94e */
if(!s->budget--) { s->failed_pc=0x0c08d94eu; return 0; }
r[5]=r[13];
goto P_0c08d950;
P_0c08d950: /* original b0d0, guest PC 0x0c08d950 */
if(!s->budget--) { s->failed_pc=0x0c08d950u; return 0; }
target=code_base|0x0c08daf4u; r[16]=code_base|0x0c08d954u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d954u) { target=s->pc; goto dispatch; }
goto P_0c08d954;
P_0c08d952: /* original 64e3, guest PC 0x0c08d952 */
if(!s->budget--) { s->failed_pc=0x0c08d952u; return 0; }
r[4]=r[14];
goto P_0c08d954;
P_0c08d954: /* original a02e, guest PC 0x0c08d954 */
if(!s->budget--) { s->failed_pc=0x0c08d954u; return 0; }
goto P_0c08d9b4;
P_0c08d956: /* original 0009, guest PC 0x0c08d956 */
if(!s->budget--) { s->failed_pc=0x0c08d956u; return 0; }
if(!vf3_matrix_family(0x0c08d958u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08d958u; return 0; } return 1;
P_0c08d990: /* original d355, guest PC 0x0c08d990 */
if(!s->budget--) { s->failed_pc=0x0c08d990u; return 0; }
r[3]=read(ram,0x0c08dae8u,4);
goto P_0c08d992;
P_0c08d992: /* original 6442, guest PC 0x0c08d992 */
if(!s->budget--) { s->failed_pc=0x0c08d992u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c08d994;
P_0c08d994: /* original 2438, guest PC 0x0c08d994 */
if(!s->budget--) { s->failed_pc=0x0c08d994u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c08d996;
P_0c08d996: /* original 8902, guest PC 0x0c08d996 */
if(!s->budget--) { s->failed_pc=0x0c08d996u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08d99e; }
goto P_0c08d998;
P_0c08d998: /* original 909f, guest PC 0x0c08d998 */
if(!s->budget--) { s->failed_pc=0x0c08d998u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dadau,2);
goto P_0c08d99a;
P_0c08d99a: /* original e200, guest PC 0x0c08d99a */
if(!s->budget--) { s->failed_pc=0x0c08d99au; return 0; }
r[2]=0x00000000u;
goto P_0c08d99c;
P_0c08d99c: /* original 0e24, guest PC 0x0c08d99c */
if(!s->budget--) { s->failed_pc=0x0c08d99cu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c08d99e;
P_0c08d99e: /* original 909c, guest PC 0x0c08d99e */
if(!s->budget--) { s->failed_pc=0x0c08d99eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dadau,2);
goto P_0c08d9a0;
P_0c08d9a0: /* original 65d3, guest PC 0x0c08d9a0 */
if(!s->budget--) { s->failed_pc=0x0c08d9a0u; return 0; }
r[5]=r[13];
goto P_0c08d9a2;
P_0c08d9a2: /* original 03ec, guest PC 0x0c08d9a2 */
if(!s->budget--) { s->failed_pc=0x0c08d9a2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08d9a4;
P_0c08d9a4: /* original d051, guest PC 0x0c08d9a4 */
if(!s->budget--) { s->failed_pc=0x0c08d9a4u; return 0; }
r[0]=read(ram,0x0c08daecu,4);
goto P_0c08d9a6;
P_0c08d9a6: /* original 633c, guest PC 0x0c08d9a6 */
if(!s->budget--) { s->failed_pc=0x0c08d9a6u; return 0; }
r[3]=r[3]&255u;
goto P_0c08d9a8;
P_0c08d9a8: /* original 4308, guest PC 0x0c08d9a8 */
if(!s->budget--) { s->failed_pc=0x0c08d9a8u; return 0; }
r[3]<<=2;
goto P_0c08d9aa;
P_0c08d9aa: /* original 023e, guest PC 0x0c08d9aa */
if(!s->budget--) { s->failed_pc=0x0c08d9aau; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c08d9ac;
P_0c08d9ac: /* original 6323, guest PC 0x0c08d9ac */
if(!s->budget--) { s->failed_pc=0x0c08d9acu; return 0; }
r[3]=r[2];
goto P_0c08d9ae;
P_0c08d9ae: /* original 2f22, guest PC 0x0c08d9ae */
if(!s->budget--) { s->failed_pc=0x0c08d9aeu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c08d9b0;
P_0c08d9b0: /* original 430b, guest PC 0x0c08d9b0 */
if(!s->budget--) { s->failed_pc=0x0c08d9b0u; return 0; }
target=r[3];
r[16]=code_base|0x0c08d9b4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d9b4u) { target=s->pc; goto dispatch; }
goto P_0c08d9b4;
P_0c08d9b2: /* original 64e3, guest PC 0x0c08d9b2 */
if(!s->budget--) { s->failed_pc=0x0c08d9b2u; return 0; }
r[4]=r[14];
goto P_0c08d9b4;
P_0c08d9b4: /* original 7f04, guest PC 0x0c08d9b4 */
if(!s->budget--) { s->failed_pc=0x0c08d9b4u; return 0; }
r[15]+=0x00000004u;
goto P_0c08d9b6;
P_0c08d9b6: /* original d34e, guest PC 0x0c08d9b6 */
if(!s->budget--) { s->failed_pc=0x0c08d9b6u; return 0; }
r[3]=read(ram,0x0c08daf0u,4);
goto P_0c08d9b8;
P_0c08d9b8: /* original 4f26, guest PC 0x0c08d9b8 */
if(!s->budget--) { s->failed_pc=0x0c08d9b8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08d9ba;
P_0c08d9ba: /* original e401, guest PC 0x0c08d9ba */
if(!s->budget--) { s->failed_pc=0x0c08d9bau; return 0; }
r[4]=0x00000001u;
goto P_0c08d9bc;
P_0c08d9bc: /* original 6df6, guest PC 0x0c08d9bc */
if(!s->budget--) { s->failed_pc=0x0c08d9bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08d9be;
P_0c08d9be: /* original 432b, guest PC 0x0c08d9be */
if(!s->budget--) { s->failed_pc=0x0c08d9beu; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c03b450u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c08d9c0: /* original 6ef6, guest PC 0x0c08d9c0 */
if(!s->budget--) { s->failed_pc=0x0c08d9c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08d9c2;
P_0c08d9c2: /* original 2fe6, guest PC 0x0c08d9c2 */
if(!s->budget--) { s->failed_pc=0x0c08d9c2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d9c4;
P_0c08d9c4: /* original ee00, guest PC 0x0c08d9c4 */
if(!s->budget--) { s->failed_pc=0x0c08d9c4u; return 0; }
r[14]=0x00000000u;
goto P_0c08d9c6;
P_0c08d9c6: /* original 9089, guest PC 0x0c08d9c6 */
if(!s->budget--) { s->failed_pc=0x0c08d9c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dadcu,2);
goto P_0c08d9c8;
P_0c08d9c8: /* original e301, guest PC 0x0c08d9c8 */
if(!s->budget--) { s->failed_pc=0x0c08d9c8u; return 0; }
r[3]=0x00000001u;
goto P_0c08d9ca;
P_0c08d9ca: /* original 4f22, guest PC 0x0c08d9ca */
if(!s->budget--) { s->failed_pc=0x0c08d9cau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08d9cc;
P_0c08d9cc: /* original 04e5, guest PC 0x0c08d9cc */
if(!s->budget--) { s->failed_pc=0x0c08d9ccu; return 0; }
write(ram,r[4]+r[0],r[14],2);
goto P_0c08d9ce;
P_0c08d9ce: /* original 7002, guest PC 0x0c08d9ce */
if(!s->budget--) { s->failed_pc=0x0c08d9ceu; return 0; }
r[0]+=0x00000002u;
goto P_0c08d9d0;
P_0c08d9d0: /* original 04e5, guest PC 0x0c08d9d0 */
if(!s->budget--) { s->failed_pc=0x0c08d9d0u; return 0; }
write(ram,r[4]+r[0],r[14],2);
goto P_0c08d9d2;
P_0c08d9d2: /* original 7002, guest PC 0x0c08d9d2 */
if(!s->budget--) { s->failed_pc=0x0c08d9d2u; return 0; }
r[0]+=0x00000002u;
goto P_0c08d9d4;
P_0c08d9d4: /* original 04e5, guest PC 0x0c08d9d4 */
if(!s->budget--) { s->failed_pc=0x0c08d9d4u; return 0; }
write(ram,r[4]+r[0],r[14],2);
goto P_0c08d9d6;
P_0c08d9d6: /* original 70fb, guest PC 0x0c08d9d6 */
if(!s->budget--) { s->failed_pc=0x0c08d9d6u; return 0; }
r[0]+=0xfffffffbu;
goto P_0c08d9d8;
P_0c08d9d8: /* original 04e4, guest PC 0x0c08d9d8 */
if(!s->budget--) { s->failed_pc=0x0c08d9d8u; return 0; }
write(ram,r[4]+r[0],r[14],1);
goto P_0c08d9da;
P_0c08d9da: /* original 70ff, guest PC 0x0c08d9da */
if(!s->budget--) { s->failed_pc=0x0c08d9dau; return 0; }
r[0]+=0xffffffffu;
goto P_0c08d9dc;
P_0c08d9dc: /* original 67e3, guest PC 0x0c08d9dc */
if(!s->budget--) { s->failed_pc=0x0c08d9dcu; return 0; }
r[7]=r[14];
goto P_0c08d9de;
P_0c08d9de: /* original 66e3, guest PC 0x0c08d9de */
if(!s->budget--) { s->failed_pc=0x0c08d9deu; return 0; }
r[6]=r[14];
goto P_0c08d9e0;
P_0c08d9e0: /* original 0434, guest PC 0x0c08d9e0 */
if(!s->budget--) { s->failed_pc=0x0c08d9e0u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c08d9e2;
P_0c08d9e2: /* original 2fe6, guest PC 0x0c08d9e2 */
if(!s->budget--) { s->failed_pc=0x0c08d9e2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d9e4;
P_0c08d9e4: /* original 2fe6, guest PC 0x0c08d9e4 */
if(!s->budget--) { s->failed_pc=0x0c08d9e4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d9e6;
P_0c08d9e6: /* original 2fe6, guest PC 0x0c08d9e6 */
if(!s->budget--) { s->failed_pc=0x0c08d9e6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d9e8;
P_0c08d9e8: /* original b27d, guest PC 0x0c08d9e8 */
if(!s->budget--) { s->failed_pc=0x0c08d9e8u; return 0; }
target=code_base|0x0c08dee6u; r[16]=code_base|0x0c08d9ecu;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d9ecu) { target=s->pc; goto dispatch; }
goto P_0c08d9ec;
P_0c08d9ea: /* original 65e3, guest PC 0x0c08d9ea */
if(!s->budget--) { s->failed_pc=0x0c08d9eau; return 0; }
r[5]=r[14];
goto P_0c08d9ec;
P_0c08d9ec: /* original 7f0c, guest PC 0x0c08d9ec */
if(!s->budget--) { s->failed_pc=0x0c08d9ecu; return 0; }
r[15]+=0x0000000cu;
goto P_0c08d9ee;
P_0c08d9ee: /* original 4f26, guest PC 0x0c08d9ee */
if(!s->budget--) { s->failed_pc=0x0c08d9eeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08d9f0;
P_0c08d9f0: /* original 000b, guest PC 0x0c08d9f0 */
if(!s->budget--) { s->failed_pc=0x0c08d9f0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08d9f2: /* original 6ef6, guest PC 0x0c08d9f2 */
if(!s->budget--) { s->failed_pc=0x0c08d9f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08d9f4u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
