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
int vf3_away_batch134_adapter_13(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09f500u: goto P_0c09f500;
case 0x0c09f502u: goto P_0c09f502;
case 0x0c09f504u: goto P_0c09f504;
case 0x0c09f506u: goto P_0c09f506;
case 0x0c09f508u: goto P_0c09f508;
case 0x0c09f50au: goto P_0c09f50a;
case 0x0c09f50cu: goto P_0c09f50c;
case 0x0c09f50eu: goto P_0c09f50e;
case 0x0c09f510u: goto P_0c09f510;
case 0x0c09f512u: goto P_0c09f512;
case 0x0c09f514u: goto P_0c09f514;
case 0x0c09f516u: goto P_0c09f516;
case 0x0c09f518u: goto P_0c09f518;
case 0x0c09f51au: goto P_0c09f51a;
case 0x0c09f51cu: goto P_0c09f51c;
case 0x0c09f51eu: goto P_0c09f51e;
case 0x0c09f520u: goto P_0c09f520;
case 0x0c09f522u: goto P_0c09f522;
case 0x0c09f524u: goto P_0c09f524;
case 0x0c09f526u: goto P_0c09f526;
case 0x0c09f528u: goto P_0c09f528;
case 0x0c09f52au: goto P_0c09f52a;
case 0x0c09f52cu: goto P_0c09f52c;
case 0x0c09f52eu: goto P_0c09f52e;
case 0x0c09f530u: goto P_0c09f530;
case 0x0c09f532u: goto P_0c09f532;
case 0x0c09f534u: goto P_0c09f534;
case 0x0c09f536u: goto P_0c09f536;
case 0x0c09f538u: goto P_0c09f538;
case 0x0c09f53au: goto P_0c09f53a;
case 0x0c09f53cu: goto P_0c09f53c;
case 0x0c09f53eu: goto P_0c09f53e;
case 0x0c09f540u: goto P_0c09f540;
case 0x0c09f542u: goto P_0c09f542;
case 0x0c09f544u: goto P_0c09f544;
case 0x0c09f546u: goto P_0c09f546;
case 0x0c09f548u: goto P_0c09f548;
case 0x0c09f54au: goto P_0c09f54a;
case 0x0c09f54cu: goto P_0c09f54c;
case 0x0c09f54eu: goto P_0c09f54e;
case 0x0c09f550u: goto P_0c09f550;
case 0x0c09f552u: goto P_0c09f552;
case 0x0c09f554u: goto P_0c09f554;
case 0x0c09f556u: goto P_0c09f556;
case 0x0c09f558u: goto P_0c09f558;
case 0x0c09f55au: goto P_0c09f55a;
case 0x0c09f55cu: goto P_0c09f55c;
case 0x0c09f55eu: goto P_0c09f55e;
case 0x0c09f560u: goto P_0c09f560;
case 0x0c09f562u: goto P_0c09f562;
case 0x0c09f564u: goto P_0c09f564;
case 0x0c09f566u: goto P_0c09f566;
case 0x0c09f568u: goto P_0c09f568;
case 0x0c09f56au: goto P_0c09f56a;
case 0x0c09f56cu: goto P_0c09f56c;
case 0x0c09f56eu: goto P_0c09f56e;
case 0x0c09f570u: goto P_0c09f570;
case 0x0c09f572u: goto P_0c09f572;
case 0x0c09f574u: goto P_0c09f574;
case 0x0c09f576u: goto P_0c09f576;
case 0x0c09f578u: goto P_0c09f578;
case 0x0c09f57au: goto P_0c09f57a;
case 0x0c09f57cu: goto P_0c09f57c;
case 0x0c09f57eu: goto P_0c09f57e;
case 0x0c09f580u: goto P_0c09f580;
case 0x0c09f582u: goto P_0c09f582;
case 0x0c09f584u: goto P_0c09f584;
case 0x0c09f586u: goto P_0c09f586;
case 0x0c09f588u: goto P_0c09f588;
case 0x0c09f58au: goto P_0c09f58a;
case 0x0c09f58cu: goto P_0c09f58c;
case 0x0c09f58eu: goto P_0c09f58e;
case 0x0c09f590u: goto P_0c09f590;
case 0x0c09f592u: goto P_0c09f592;
case 0x0c09f594u: goto P_0c09f594;
case 0x0c09f596u: goto P_0c09f596;
case 0x0c09f598u: goto P_0c09f598;
case 0x0c09f59au: goto P_0c09f59a;
case 0x0c09f59cu: goto P_0c09f59c;
case 0x0c09f59eu: goto P_0c09f59e;
case 0x0c09f5a0u: goto P_0c09f5a0;
case 0x0c09f5a2u: goto P_0c09f5a2;
case 0x0c09f5a4u: goto P_0c09f5a4;
case 0x0c09f5a6u: goto P_0c09f5a6;
case 0x0c09f5a8u: goto P_0c09f5a8;
case 0x0c09f5aau: goto P_0c09f5aa;
case 0x0c09f5acu: goto P_0c09f5ac;
case 0x0c09f5aeu: goto P_0c09f5ae;
case 0x0c09f5b0u: goto P_0c09f5b0;
case 0x0c09f5b2u: goto P_0c09f5b2;
case 0x0c09f5b4u: goto P_0c09f5b4;
case 0x0c09f5b6u: goto P_0c09f5b6;
case 0x0c09f5b8u: goto P_0c09f5b8;
case 0x0c09f5bau: goto P_0c09f5ba;
case 0x0c09f5bcu: goto P_0c09f5bc;
case 0x0c09f5beu: goto P_0c09f5be;
case 0x0c09f5c0u: goto P_0c09f5c0;
case 0x0c09f5c2u: goto P_0c09f5c2;
case 0x0c09f5c4u: goto P_0c09f5c4;
case 0x0c09f5c6u: goto P_0c09f5c6;
case 0x0c09f5c8u: goto P_0c09f5c8;
case 0x0c09f5cau: goto P_0c09f5ca;
case 0x0c09f5ccu: goto P_0c09f5cc;
case 0x0c09f5ceu: goto P_0c09f5ce;
case 0x0c09f5d0u: goto P_0c09f5d0;
case 0x0c09f5d2u: goto P_0c09f5d2;
case 0x0c09f5d4u: goto P_0c09f5d4;
case 0x0c09f5d6u: goto P_0c09f5d6;
case 0x0c09f5d8u: goto P_0c09f5d8;
case 0x0c09f5dau: goto P_0c09f5da;
case 0x0c09f5dcu: goto P_0c09f5dc;
case 0x0c09f5deu: goto P_0c09f5de;
case 0x0c09f5e0u: goto P_0c09f5e0;
case 0x0c09f5e2u: goto P_0c09f5e2;
case 0x0c09f5e4u: goto P_0c09f5e4;
case 0x0c09f5e6u: goto P_0c09f5e6;
case 0x0c09f5f8u: goto P_0c09f5f8;
case 0x0c09f5fau: goto P_0c09f5fa;
case 0x0c09f5fcu: goto P_0c09f5fc;
case 0x0c09f5feu: goto P_0c09f5fe;
case 0x0c09f600u: goto P_0c09f600;
case 0x0c09f602u: goto P_0c09f602;
case 0x0c09f604u: goto P_0c09f604;
case 0x0c09f606u: goto P_0c09f606;
case 0x0c09f608u: goto P_0c09f608;
case 0x0c09f60au: goto P_0c09f60a;
case 0x0c09f60cu: goto P_0c09f60c;
case 0x0c09f60eu: goto P_0c09f60e;
case 0x0c09f610u: goto P_0c09f610;
case 0x0c09f612u: goto P_0c09f612;
case 0x0c09f614u: goto P_0c09f614;
case 0x0c09f616u: goto P_0c09f616;
case 0x0c09f618u: goto P_0c09f618;
case 0x0c09f61au: goto P_0c09f61a;
case 0x0c09f61cu: goto P_0c09f61c;
case 0x0c09f61eu: goto P_0c09f61e;
case 0x0c09f620u: goto P_0c09f620;
case 0x0c09f622u: goto P_0c09f622;
case 0x0c09f624u: goto P_0c09f624;
case 0x0c09f626u: goto P_0c09f626;
case 0x0c09f628u: goto P_0c09f628;
case 0x0c09f62au: goto P_0c09f62a;
case 0x0c09f62cu: goto P_0c09f62c;
case 0x0c09f62eu: goto P_0c09f62e;
case 0x0c09f630u: goto P_0c09f630;
case 0x0c09f632u: goto P_0c09f632;
case 0x0c09f634u: goto P_0c09f634;
case 0x0c09f636u: goto P_0c09f636;
case 0x0c09f638u: goto P_0c09f638;
case 0x0c09f63au: goto P_0c09f63a;
case 0x0c09f63cu: goto P_0c09f63c;
case 0x0c09f63eu: goto P_0c09f63e;
case 0x0c09f640u: goto P_0c09f640;
case 0x0c09f642u: goto P_0c09f642;
case 0x0c09f644u: goto P_0c09f644;
case 0x0c09f646u: goto P_0c09f646;
case 0x0c09f648u: goto P_0c09f648;
case 0x0c09f64au: goto P_0c09f64a;
case 0x0c09f64cu: goto P_0c09f64c;
case 0x0c09f64eu: goto P_0c09f64e;
case 0x0c09f650u: goto P_0c09f650;
case 0x0c09f652u: goto P_0c09f652;
case 0x0c09f654u: goto P_0c09f654;
case 0x0c09f656u: goto P_0c09f656;
case 0x0c09f658u: goto P_0c09f658;
case 0x0c09f65au: goto P_0c09f65a;
case 0x0c09f65cu: goto P_0c09f65c;
case 0x0c09f65eu: goto P_0c09f65e;
case 0x0c09f660u: goto P_0c09f660;
case 0x0c09f662u: goto P_0c09f662;
case 0x0c09f664u: goto P_0c09f664;
case 0x0c09f666u: goto P_0c09f666;
case 0x0c09f668u: goto P_0c09f668;
case 0x0c09f66au: goto P_0c09f66a;
case 0x0c09f66cu: goto P_0c09f66c;
case 0x0c09f66eu: goto P_0c09f66e;
case 0x0c09f670u: goto P_0c09f670;
case 0x0c09f672u: goto P_0c09f672;
case 0x0c09f674u: goto P_0c09f674;
case 0x0c09f676u: goto P_0c09f676;
case 0x0c09f678u: goto P_0c09f678;
case 0x0c09f67au: goto P_0c09f67a;
case 0x0c09f67cu: goto P_0c09f67c;
case 0x0c09f67eu: goto P_0c09f67e;
case 0x0c09f680u: goto P_0c09f680;
case 0x0c09f682u: goto P_0c09f682;
case 0x0c09f684u: goto P_0c09f684;
case 0x0c09f686u: goto P_0c09f686;
case 0x0c09f688u: goto P_0c09f688;
case 0x0c09f68au: goto P_0c09f68a;
case 0x0c09f68cu: goto P_0c09f68c;
case 0x0c09f68eu: goto P_0c09f68e;
case 0x0c09f690u: goto P_0c09f690;
case 0x0c09f692u: goto P_0c09f692;
case 0x0c09f694u: goto P_0c09f694;
case 0x0c09f696u: goto P_0c09f696;
case 0x0c09f698u: goto P_0c09f698;
case 0x0c09f69au: goto P_0c09f69a;
case 0x0c09f69cu: goto P_0c09f69c;
case 0x0c09f69eu: goto P_0c09f69e;
case 0x0c09f6a0u: goto P_0c09f6a0;
case 0x0c09f6a2u: goto P_0c09f6a2;
case 0x0c09f6a4u: goto P_0c09f6a4;
case 0x0c09f6a6u: goto P_0c09f6a6;
case 0x0c09f6a8u: goto P_0c09f6a8;
case 0x0c09f6aau: goto P_0c09f6aa;
case 0x0c09f6acu: goto P_0c09f6ac;
case 0x0c09f6aeu: goto P_0c09f6ae;
case 0x0c09f6b0u: goto P_0c09f6b0;
case 0x0c09f6b2u: goto P_0c09f6b2;
case 0x0c09f6b4u: goto P_0c09f6b4;
case 0x0c09f6b6u: goto P_0c09f6b6;
case 0x0c09f6b8u: goto P_0c09f6b8;
case 0x0c09f6bau: goto P_0c09f6ba;
case 0x0c09f6bcu: goto P_0c09f6bc;
case 0x0c09f6beu: goto P_0c09f6be;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09f500: /* original 2fe6, guest PC 0x0c09f500 */
if(!s->budget--) { s->failed_pc=0x0c09f500u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f502;
P_0c09f502: /* original 6353, guest PC 0x0c09f502 */
if(!s->budget--) { s->failed_pc=0x0c09f502u; return 0; }
r[3]=r[5];
goto P_0c09f504;
P_0c09f504: /* original 2fd6, guest PC 0x0c09f504 */
if(!s->budget--) { s->failed_pc=0x0c09f504u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f506;
P_0c09f506: /* original 7304, guest PC 0x0c09f506 */
if(!s->budget--) { s->failed_pc=0x0c09f506u; return 0; }
r[3]+=0x00000004u;
goto P_0c09f508;
P_0c09f508: /* original 2fc6, guest PC 0x0c09f508 */
if(!s->budget--) { s->failed_pc=0x0c09f508u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f50a;
P_0c09f50a: /* original 6c53, guest PC 0x0c09f50a */
if(!s->budget--) { s->failed_pc=0x0c09f50au; return 0; }
r[12]=r[5];
goto P_0c09f50c;
P_0c09f50c: /* original 62c3, guest PC 0x0c09f50c */
if(!s->budget--) { s->failed_pc=0x0c09f50cu; return 0; }
r[2]=r[12];
goto P_0c09f50e;
P_0c09f50e: /* original 7208, guest PC 0x0c09f50e */
if(!s->budget--) { s->failed_pc=0x0c09f50eu; return 0; }
r[2]+=0x00000008u;
goto P_0c09f510;
P_0c09f510: /* original 2fb6, guest PC 0x0c09f510 */
if(!s->budget--) { s->failed_pc=0x0c09f510u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f512;
P_0c09f512: /* original 2fa6, guest PC 0x0c09f512 */
if(!s->budget--) { s->failed_pc=0x0c09f512u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f514;
P_0c09f514: /* original 2f96, guest PC 0x0c09f514 */
if(!s->budget--) { s->failed_pc=0x0c09f514u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f516;
P_0c09f516: /* original 2f86, guest PC 0x0c09f516 */
if(!s->budget--) { s->failed_pc=0x0c09f516u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f518;
P_0c09f518: /* original f6c8, guest PC 0x0c09f518 */
if(!s->budget--) { s->failed_pc=0x0c09f518u; return 0; }
vf3_matrix_load(s,ram,6,r[12]);
goto P_0c09f51a;
P_0c09f51a: /* original 7ff4, guest PC 0x0c09f51a */
if(!s->budget--) { s->failed_pc=0x0c09f51au; return 0; }
r[15]+=0xfffffff4u;
goto P_0c09f51c;
P_0c09f51c: /* original 1f32, guest PC 0x0c09f51c */
if(!s->budget--) { s->failed_pc=0x0c09f51cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c09f51e;
P_0c09f51e: /* original f63d, guest PC 0x0c09f51e */
if(!s->budget--) { s->failed_pc=0x0c09f51eu; return 0; }
r[53]=truncate_float(fr[6]);
goto P_0c09f520;
P_0c09f520: /* original f438, guest PC 0x0c09f520 */
if(!s->budget--) { s->failed_pc=0x0c09f520u; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c09f522;
P_0c09f522: /* original 1f21, guest PC 0x0c09f522 */
if(!s->budget--) { s->failed_pc=0x0c09f522u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c09f524;
P_0c09f524: /* original f528, guest PC 0x0c09f524 */
if(!s->budget--) { s->failed_pc=0x0c09f524u; return 0; }
vf3_matrix_load(s,ram,5,r[2]);
goto P_0c09f526;
P_0c09f526: /* original 075a, guest PC 0x0c09f526 */
if(!s->budget--) { s->failed_pc=0x0c09f526u; return 0; }
r[7]=r[53];
goto P_0c09f528;
P_0c09f528: /* original f43d, guest PC 0x0c09f528 */
if(!s->budget--) { s->failed_pc=0x0c09f528u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c09f52a;
P_0c09f52a: /* original 677d, guest PC 0x0c09f52a */
if(!s->budget--) { s->failed_pc=0x0c09f52au; return 0; }
r[7]=r[7]&65535u;
goto P_0c09f52c;
P_0c09f52c: /* original 0d5a, guest PC 0x0c09f52c */
if(!s->budget--) { s->failed_pc=0x0c09f52cu; return 0; }
r[13]=r[53];
goto P_0c09f52e;
P_0c09f52e: /* original f53d, guest PC 0x0c09f52e */
if(!s->budget--) { s->failed_pc=0x0c09f52eu; return 0; }
r[53]=truncate_float(fr[5]);
goto P_0c09f530;
P_0c09f530: /* original 677f, guest PC 0x0c09f530 */
if(!s->budget--) { s->failed_pc=0x0c09f530u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)r[7];
goto P_0c09f532;
P_0c09f532: /* original 015a, guest PC 0x0c09f532 */
if(!s->budget--) { s->failed_pc=0x0c09f532u; return 0; }
r[1]=r[53];
goto P_0c09f534;
P_0c09f534: /* original 2f12, guest PC 0x0c09f534 */
if(!s->budget--) { s->failed_pc=0x0c09f534u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c09f536;
P_0c09f536: /* original 9357, guest PC 0x0c09f536 */
if(!s->budget--) { s->failed_pc=0x0c09f536u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f5e8u,2);
goto P_0c09f538;
P_0c09f538: /* original de2e, guest PC 0x0c09f538 */
if(!s->budget--) { s->failed_pc=0x0c09f538u; return 0; }
r[14]=read(ram,0x0c09f5f4u,4);
goto P_0c09f53a;
P_0c09f53a: /* original 3737, guest PC 0x0c09f53a */
if(!s->budget--) { s->failed_pc=0x0c09f53au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>(int32_t)r[3])!=0);
goto P_0c09f53c;
P_0c09f53c: /* original 8d03, guest PC 0x0c09f53c */
if(!s->budget--) { s->failed_pc=0x0c09f53cu; return 0; }
cond=r[17]&1u;
r[11]=r[1]&65535u;
if(cond) { goto P_0c09f546; }
goto P_0c09f540;
P_0c09f53e: /* original 6b1d, guest PC 0x0c09f53e */
if(!s->budget--) { s->failed_pc=0x0c09f53eu; return 0; }
r[11]=r[1]&65535u;
goto P_0c09f540;
P_0c09f540: /* original 9053, guest PC 0x0c09f540 */
if(!s->budget--) { s->failed_pc=0x0c09f540u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f5eau,2);
goto P_0c09f542;
P_0c09f542: /* original 3703, guest PC 0x0c09f542 */
if(!s->budget--) { s->failed_pc=0x0c09f542u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[0])!=0);
goto P_0c09f544;
P_0c09f544: /* original 8904, guest PC 0x0c09f544 */
if(!s->budget--) { s->failed_pc=0x0c09f544u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f550; }
goto P_0c09f546;
P_0c09f546: /* original 63e3, guest PC 0x0c09f546 */
if(!s->budget--) { s->failed_pc=0x0c09f546u; return 0; }
r[3]=r[14];
goto P_0c09f548;
P_0c09f548: /* original 33d8, guest PC 0x0c09f548 */
if(!s->budget--) { s->failed_pc=0x0c09f548u; return 0; }
r[3]-=r[13];
goto P_0c09f54a;
P_0c09f54a: /* original 6d33, guest PC 0x0c09f54a */
if(!s->budget--) { s->failed_pc=0x0c09f54au; return 0; }
r[13]=r[3];
goto P_0c09f54c;
P_0c09f54c: /* original 3bec, guest PC 0x0c09f54c */
if(!s->budget--) { s->failed_pc=0x0c09f54cu; return 0; }
r[11]+=r[14];
goto P_0c09f54e;
P_0c09f54e: /* original 37ec, guest PC 0x0c09f54e */
if(!s->budget--) { s->failed_pc=0x0c09f54eu; return 0; }
r[7]+=r[14];
goto P_0c09f550;
P_0c09f550: /* original 677d, guest PC 0x0c09f550 */
if(!s->budget--) { s->failed_pc=0x0c09f550u; return 0; }
r[7]=r[7]&65535u;
goto P_0c09f552;
P_0c09f552: /* original e03e, guest PC 0x0c09f552 */
if(!s->budget--) { s->failed_pc=0x0c09f552u; return 0; }
r[0]=0x0000003eu;
goto P_0c09f554;
P_0c09f554: /* original 697f, guest PC 0x0c09f554 */
if(!s->budget--) { s->failed_pc=0x0c09f554u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)r[7];
goto P_0c09f556;
P_0c09f556: /* original 6bbd, guest PC 0x0c09f556 */
if(!s->budget--) { s->failed_pc=0x0c09f556u; return 0; }
r[11]=r[11]&65535u;
goto P_0c09f558;
P_0c09f558: /* original 6ebf, guest PC 0x0c09f558 */
if(!s->budget--) { s->failed_pc=0x0c09f558u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c09f55a;
P_0c09f55a: /* original 2fb2, guest PC 0x0c09f55a */
if(!s->budget--) { s->failed_pc=0x0c09f55au; return 0; }
write(ram,r[15],r[11],4);
goto P_0c09f55c;
P_0c09f55c: /* original 074d, guest PC 0x0c09f55c */
if(!s->budget--) { s->failed_pc=0x0c09f55cu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09f55e;
P_0c09f55e: /* original 9045, guest PC 0x0c09f55e */
if(!s->budget--) { s->failed_pc=0x0c09f55eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f5ecu,2);
goto P_0c09f560;
P_0c09f560: /* original 677d, guest PC 0x0c09f560 */
if(!s->budget--) { s->failed_pc=0x0c09f560u; return 0; }
r[7]=r[7]&65535u;
goto P_0c09f562;
P_0c09f562: /* original 0a4d, guest PC 0x0c09f562 */
if(!s->budget--) { s->failed_pc=0x0c09f562u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09f564;
P_0c09f564: /* original 70fc, guest PC 0x0c09f564 */
if(!s->budget--) { s->failed_pc=0x0c09f564u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09f566;
P_0c09f566: /* original 084d, guest PC 0x0c09f566 */
if(!s->budget--) { s->failed_pc=0x0c09f566u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09f568;
P_0c09f568: /* original 9041, guest PC 0x0c09f568 */
if(!s->budget--) { s->failed_pc=0x0c09f568u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f5eeu,2);
goto P_0c09f56a;
P_0c09f56a: /* original 6aad, guest PC 0x0c09f56a */
if(!s->budget--) { s->failed_pc=0x0c09f56au; return 0; }
r[10]=r[10]&65535u;
goto P_0c09f56c;
P_0c09f56c: /* original 7a01, guest PC 0x0c09f56c */
if(!s->budget--) { s->failed_pc=0x0c09f56cu; return 0; }
r[10]+=0x00000001u;
goto P_0c09f56e;
P_0c09f56e: /* original 0b4d, guest PC 0x0c09f56e */
if(!s->budget--) { s->failed_pc=0x0c09f56eu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09f570;
P_0c09f570: /* original 37a0, guest PC 0x0c09f570 */
if(!s->budget--) { s->failed_pc=0x0c09f570u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[10])!=0);
goto P_0c09f572;
P_0c09f572: /* original 7801, guest PC 0x0c09f572 */
if(!s->budget--) { s->failed_pc=0x0c09f572u; return 0; }
r[8]+=0x00000001u;
goto P_0c09f574;
P_0c09f574: /* original 6bbd, guest PC 0x0c09f574 */
if(!s->budget--) { s->failed_pc=0x0c09f574u; return 0; }
r[11]=r[11]&65535u;
goto P_0c09f576;
P_0c09f576: /* original 63b3, guest PC 0x0c09f576 */
if(!s->budget--) { s->failed_pc=0x0c09f576u; return 0; }
r[3]=r[11];
goto P_0c09f578;
P_0c09f578: /* original 73f8, guest PC 0x0c09f578 */
if(!s->budget--) { s->failed_pc=0x0c09f578u; return 0; }
r[3]+=0xfffffff8u;
goto P_0c09f57a;
P_0c09f57a: /* original 2f32, guest PC 0x0c09f57a */
if(!s->budget--) { s->failed_pc=0x0c09f57au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09f57c;
P_0c09f57c: /* original 8d02, guest PC 0x0c09f57c */
if(!s->budget--) { s->failed_pc=0x0c09f57cu; return 0; }
cond=r[17]&1u;
r[11]+=0x00000001u;
if(cond) { goto P_0c09f584; }
goto P_0c09f580;
P_0c09f57e: /* original 7b01, guest PC 0x0c09f57e */
if(!s->budget--) { s->failed_pc=0x0c09f57eu; return 0; }
r[11]+=0x00000001u;
goto P_0c09f580;
P_0c09f580: /* original 3730, guest PC 0x0c09f580 */
if(!s->budget--) { s->failed_pc=0x0c09f580u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[3])!=0);
goto P_0c09f582;
P_0c09f582: /* original 8b04, guest PC 0x0c09f582 */
if(!s->budget--) { s->failed_pc=0x0c09f582u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f58e; }
goto P_0c09f584;
P_0c09f584: /* original 60d3, guest PC 0x0c09f584 */
if(!s->budget--) { s->failed_pc=0x0c09f584u; return 0; }
r[0]=r[13];
goto P_0c09f586;
P_0c09f586: /* original 2691, guest PC 0x0c09f586 */
if(!s->budget--) { s->failed_pc=0x0c09f586u; return 0; }
write(ram,r[6],r[9],2);
goto P_0c09f588;
P_0c09f588: /* original 8161, guest PC 0x0c09f588 */
if(!s->budget--) { s->failed_pc=0x0c09f588u; return 0; }
write(ram,r[6]+2,r[0],2);
goto P_0c09f58a;
P_0c09f58a: /* original 60e3, guest PC 0x0c09f58a */
if(!s->budget--) { s->failed_pc=0x0c09f58au; return 0; }
r[0]=r[14];
goto P_0c09f58c;
P_0c09f58c: /* original 8162, guest PC 0x0c09f58c */
if(!s->budget--) { s->failed_pc=0x0c09f58cu; return 0; }
write(ram,r[6]+4,r[0],2);
goto P_0c09f58e;
P_0c09f58e: /* original 37a7, guest PC 0x0c09f58e */
if(!s->budget--) { s->failed_pc=0x0c09f58eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>(int32_t)r[10])!=0);
goto P_0c09f590;
P_0c09f590: /* original 8b01, guest PC 0x0c09f590 */
if(!s->budget--) { s->failed_pc=0x0c09f590u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f596; }
goto P_0c09f592;
P_0c09f592: /* original 3783, guest PC 0x0c09f592 */
if(!s->budget--) { s->failed_pc=0x0c09f592u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[8])!=0);
goto P_0c09f594;
P_0c09f594: /* original 8b04, guest PC 0x0c09f594 */
if(!s->budget--) { s->failed_pc=0x0c09f594u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f5a0; }
goto P_0c09f596;
P_0c09f596: /* original 63f2, guest PC 0x0c09f596 */
if(!s->budget--) { s->failed_pc=0x0c09f596u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09f598;
P_0c09f598: /* original 3737, guest PC 0x0c09f598 */
if(!s->budget--) { s->failed_pc=0x0c09f598u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>(int32_t)r[3])!=0);
goto P_0c09f59a;
P_0c09f59a: /* original 8b0f, guest PC 0x0c09f59a */
if(!s->budget--) { s->failed_pc=0x0c09f59au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f5bc; }
goto P_0c09f59c;
P_0c09f59c: /* original 37b3, guest PC 0x0c09f59c */
if(!s->budget--) { s->failed_pc=0x0c09f59cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[11])!=0);
goto P_0c09f59e;
P_0c09f59e: /* original 890d, guest PC 0x0c09f59e */
if(!s->budget--) { s->failed_pc=0x0c09f59eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f5bc; }
goto P_0c09f5a0;
P_0c09f5a0: /* original e061, guest PC 0x0c09f5a0 */
if(!s->budget--) { s->failed_pc=0x0c09f5a0u; return 0; }
r[0]=0x00000061u;
goto P_0c09f5a2;
P_0c09f5a2: /* original 004c, guest PC 0x0c09f5a2 */
if(!s->budget--) { s->failed_pc=0x0c09f5a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09f5a4;
P_0c09f5a4: /* original 600c, guest PC 0x0c09f5a4 */
if(!s->budget--) { s->failed_pc=0x0c09f5a4u; return 0; }
r[0]=r[0]&255u;
goto P_0c09f5a6;
P_0c09f5a6: /* original 8803, guest PC 0x0c09f5a6 */
if(!s->budget--) { s->failed_pc=0x0c09f5a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09f5a8;
P_0c09f5a8: /* original 8b08, guest PC 0x0c09f5a8 */
if(!s->budget--) { s->failed_pc=0x0c09f5a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f5bc; }
goto P_0c09f5aa;
P_0c09f5aa: /* original 64e3, guest PC 0x0c09f5aa */
if(!s->budget--) { s->failed_pc=0x0c09f5aau; return 0; }
r[4]=r[14];
goto P_0c09f5ac;
P_0c09f5ac: /* original 4411, guest PC 0x0c09f5ac */
if(!s->budget--) { s->failed_pc=0x0c09f5acu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c09f5ae;
P_0c09f5ae: /* original 8d01, guest PC 0x0c09f5ae */
if(!s->budget--) { s->failed_pc=0x0c09f5aeu; return 0; }
cond=r[17]&1u;
r[6]=0u-r[14];
if(cond) { goto P_0c09f5b4; }
goto P_0c09f5b2;
P_0c09f5b0: /* original 66eb, guest PC 0x0c09f5b0 */
if(!s->budget--) { s->failed_pc=0x0c09f5b0u; return 0; }
r[6]=0u-r[14];
goto P_0c09f5b2;
P_0c09f5b2: /* original 6463, guest PC 0x0c09f5b2 */
if(!s->budget--) { s->failed_pc=0x0c09f5b2u; return 0; }
r[4]=r[6];
goto P_0c09f5b4;
P_0c09f5b4: /* original 931c, guest PC 0x0c09f5b4 */
if(!s->budget--) { s->failed_pc=0x0c09f5b4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f5f0u,2);
goto P_0c09f5b6;
P_0c09f5b6: /* original 3437, guest PC 0x0c09f5b6 */
if(!s->budget--) { s->failed_pc=0x0c09f5b6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c09f5b8;
P_0c09f5b8: /* original 8b00, guest PC 0x0c09f5b8 */
if(!s->budget--) { s->failed_pc=0x0c09f5b8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f5bc; }
goto P_0c09f5ba;
P_0c09f5ba: /* original 6e63, guest PC 0x0c09f5ba */
if(!s->budget--) { s->failed_pc=0x0c09f5bau; return 0; }
r[14]=r[6];
goto P_0c09f5bc;
P_0c09f5bc: /* original 495a, guest PC 0x0c09f5bc */
if(!s->budget--) { s->failed_pc=0x0c09f5bcu; return 0; }
r[53]=r[9];
goto P_0c09f5be;
P_0c09f5be: /* original 750c, guest PC 0x0c09f5be */
if(!s->budget--) { s->failed_pc=0x0c09f5beu; return 0; }
r[5]+=0x0000000cu;
goto P_0c09f5c0;
P_0c09f5c0: /* original 6053, guest PC 0x0c09f5c0 */
if(!s->budget--) { s->failed_pc=0x0c09f5c0u; return 0; }
r[0]=r[5];
goto P_0c09f5c2;
P_0c09f5c2: /* original f32d, guest PC 0x0c09f5c2 */
if(!s->budget--) { s->failed_pc=0x0c09f5c2u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c09f5c4;
P_0c09f5c4: /* original fc3a, guest PC 0x0c09f5c4 */
if(!s->budget--) { s->failed_pc=0x0c09f5c4u; return 0; }
vf3_matrix_store(s,ram,3,r[12]);
goto P_0c09f5c6;
P_0c09f5c6: /* original 4d5a, guest PC 0x0c09f5c6 */
if(!s->budget--) { s->failed_pc=0x0c09f5c6u; return 0; }
r[53]=r[13];
goto P_0c09f5c8;
P_0c09f5c8: /* original 53f2, guest PC 0x0c09f5c8 */
if(!s->budget--) { s->failed_pc=0x0c09f5c8u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c09f5ca;
P_0c09f5ca: /* original f32d, guest PC 0x0c09f5ca */
if(!s->budget--) { s->failed_pc=0x0c09f5cau; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c09f5cc;
P_0c09f5cc: /* original f33a, guest PC 0x0c09f5cc */
if(!s->budget--) { s->failed_pc=0x0c09f5ccu; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c09f5ce;
P_0c09f5ce: /* original 53f1, guest PC 0x0c09f5ce */
if(!s->budget--) { s->failed_pc=0x0c09f5ceu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09f5d0;
P_0c09f5d0: /* original 7f0c, guest PC 0x0c09f5d0 */
if(!s->budget--) { s->failed_pc=0x0c09f5d0u; return 0; }
r[15]+=0x0000000cu;
goto P_0c09f5d2;
P_0c09f5d2: /* original 4e5a, guest PC 0x0c09f5d2 */
if(!s->budget--) { s->failed_pc=0x0c09f5d2u; return 0; }
r[53]=r[14];
goto P_0c09f5d4;
P_0c09f5d4: /* original f32d, guest PC 0x0c09f5d4 */
if(!s->budget--) { s->failed_pc=0x0c09f5d4u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c09f5d6;
P_0c09f5d6: /* original f33a, guest PC 0x0c09f5d6 */
if(!s->budget--) { s->failed_pc=0x0c09f5d6u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c09f5d8;
P_0c09f5d8: /* original 68f6, guest PC 0x0c09f5d8 */
if(!s->budget--) { s->failed_pc=0x0c09f5d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09f5da;
P_0c09f5da: /* original 69f6, guest PC 0x0c09f5da */
if(!s->budget--) { s->failed_pc=0x0c09f5dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09f5dc;
P_0c09f5dc: /* original 6af6, guest PC 0x0c09f5dc */
if(!s->budget--) { s->failed_pc=0x0c09f5dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09f5de;
P_0c09f5de: /* original 6bf6, guest PC 0x0c09f5de */
if(!s->budget--) { s->failed_pc=0x0c09f5deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09f5e0;
P_0c09f5e0: /* original 6cf6, guest PC 0x0c09f5e0 */
if(!s->budget--) { s->failed_pc=0x0c09f5e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09f5e2;
P_0c09f5e2: /* original 6df6, guest PC 0x0c09f5e2 */
if(!s->budget--) { s->failed_pc=0x0c09f5e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09f5e4;
P_0c09f5e4: /* original 000b, guest PC 0x0c09f5e4 */
if(!s->budget--) { s->failed_pc=0x0c09f5e4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09f5e6: /* original 6ef6, guest PC 0x0c09f5e6 */
if(!s->budget--) { s->failed_pc=0x0c09f5e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09f5e8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f5e8u; return 0; } return 1;
P_0c09f5f8: /* original d531, guest PC 0x0c09f5f8 */
if(!s->budget--) { s->failed_pc=0x0c09f5f8u; return 0; }
r[5]=read(ram,0x0c09f6c0u,4);
goto P_0c09f5fa;
P_0c09f5fa: /* original 7ff8, guest PC 0x0c09f5fa */
if(!s->budget--) { s->failed_pc=0x0c09f5fau; return 0; }
r[15]+=0xfffffff8u;
goto P_0c09f5fc;
P_0c09f5fc: /* original d331, guest PC 0x0c09f5fc */
if(!s->budget--) { s->failed_pc=0x0c09f5fcu; return 0; }
r[3]=read(ram,0x0c09f6c4u,4);
goto P_0c09f5fe;
P_0c09f5fe: /* original 6252, guest PC 0x0c09f5fe */
if(!s->budget--) { s->failed_pc=0x0c09f5feu; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c09f600;
P_0c09f600: /* original 2238, guest PC 0x0c09f600 */
if(!s->budget--) { s->failed_pc=0x0c09f600u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09f602;
P_0c09f602: /* original 8b5a, guest PC 0x0c09f602 */
if(!s->budget--) { s->failed_pc=0x0c09f602u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f6ba; }
goto P_0c09f604;
P_0c09f604: /* original c730, guest PC 0x0c09f604 */
if(!s->budget--) { s->failed_pc=0x0c09f604u; return 0; }
r[0]=code_base|0x0009f6c8u;
goto P_0c09f606;
P_0c09f606: /* original fa48, guest PC 0x0c09f606 */
if(!s->budget--) { s->failed_pc=0x0c09f606u; return 0; }
vf3_matrix_load(s,ram,10,r[4]);
goto P_0c09f608;
P_0c09f608: /* original f108, guest PC 0x0c09f608 */
if(!s->budget--) { s->failed_pc=0x0c09f608u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c09f60a;
P_0c09f60a: /* original 6643, guest PC 0x0c09f60a */
if(!s->budget--) { s->failed_pc=0x0c09f60au; return 0; }
r[6]=r[4];
goto P_0c09f60c;
P_0c09f60c: /* original 6543, guest PC 0x0c09f60c */
if(!s->budget--) { s->failed_pc=0x0c09f60cu; return 0; }
r[5]=r[4];
goto P_0c09f60e;
P_0c09f60e: /* original 7608, guest PC 0x0c09f60e */
if(!s->budget--) { s->failed_pc=0x0c09f60eu; return 0; }
r[6]+=0x00000008u;
goto P_0c09f610;
P_0c09f610: /* original fa15, guest PC 0x0c09f610 */
if(!s->budget--) { s->failed_pc=0x0c09f610u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[1]))!=0);
goto P_0c09f612;
P_0c09f612: /* original 7504, guest PC 0x0c09f612 */
if(!s->budget--) { s->failed_pc=0x0c09f612u; return 0; }
r[5]+=0x00000004u;
goto P_0c09f614;
P_0c09f614: /* original f258, guest PC 0x0c09f614 */
if(!s->budget--) { s->failed_pc=0x0c09f614u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c09f616;
P_0c09f616: /* original c72d, guest PC 0x0c09f616 */
if(!s->budget--) { s->failed_pc=0x0c09f616u; return 0; }
r[0]=code_base|0x0009f6ccu;
goto P_0c09f618;
P_0c09f618: /* original fb68, guest PC 0x0c09f618 */
if(!s->budget--) { s->failed_pc=0x0c09f618u; return 0; }
vf3_matrix_load(s,ram,11,r[6]);
goto P_0c09f61a;
P_0c09f61a: /* original 8d06, guest PC 0x0c09f61a */
if(!s->budget--) { s->failed_pc=0x0c09f61au; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,0,r[0]);
if(cond) { goto P_0c09f62a; }
goto P_0c09f61e;
P_0c09f61c: /* original f008, guest PC 0x0c09f61c */
if(!s->budget--) { s->failed_pc=0x0c09f61cu; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c09f61e;
P_0c09f61e: /* original f0a5, guest PC 0x0c09f61e */
if(!s->budget--) { s->failed_pc=0x0c09f61eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[10]))!=0);
goto P_0c09f620;
P_0c09f620: /* original 8905, guest PC 0x0c09f620 */
if(!s->budget--) { s->failed_pc=0x0c09f620u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f62e; }
goto P_0c09f622;
P_0c09f622: /* original fa15, guest PC 0x0c09f622 */
if(!s->budget--) { s->failed_pc=0x0c09f622u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[1]))!=0);
goto P_0c09f624;
P_0c09f624: /* original 8901, guest PC 0x0c09f624 */
if(!s->budget--) { s->failed_pc=0x0c09f624u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f62a; }
goto P_0c09f626;
P_0c09f626: /* original f0a5, guest PC 0x0c09f626 */
if(!s->budget--) { s->failed_pc=0x0c09f626u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[10]))!=0);
goto P_0c09f628;
P_0c09f628: /* original 8b02, guest PC 0x0c09f628 */
if(!s->budget--) { s->failed_pc=0x0c09f628u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f630; }
goto P_0c09f62a;
P_0c09f62a: /* original a001, guest PC 0x0c09f62a */
if(!s->budget--) { s->failed_pc=0x0c09f62au; return 0; }
vf3_matrix_move(s,10,1);
goto P_0c09f630;
P_0c09f62c: /* original fa1c, guest PC 0x0c09f62c */
if(!s->budget--) { s->failed_pc=0x0c09f62cu; return 0; }
vf3_matrix_move(s,10,1);
goto P_0c09f62e;
P_0c09f62e: /* original fa0c, guest PC 0x0c09f62e */
if(!s->budget--) { s->failed_pc=0x0c09f62eu; return 0; }
vf3_matrix_move(s,10,0);
goto P_0c09f630;
P_0c09f630: /* original fb15, guest PC 0x0c09f630 */
if(!s->budget--) { s->failed_pc=0x0c09f630u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[1]))!=0);
goto P_0c09f632;
P_0c09f632: /* original 8905, guest PC 0x0c09f632 */
if(!s->budget--) { s->failed_pc=0x0c09f632u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f640; }
goto P_0c09f634;
P_0c09f634: /* original f0b5, guest PC 0x0c09f634 */
if(!s->budget--) { s->failed_pc=0x0c09f634u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[11]))!=0);
goto P_0c09f636;
P_0c09f636: /* original 8905, guest PC 0x0c09f636 */
if(!s->budget--) { s->failed_pc=0x0c09f636u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f644; }
goto P_0c09f638;
P_0c09f638: /* original fb15, guest PC 0x0c09f638 */
if(!s->budget--) { s->failed_pc=0x0c09f638u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[1]))!=0);
goto P_0c09f63a;
P_0c09f63a: /* original 8901, guest PC 0x0c09f63a */
if(!s->budget--) { s->failed_pc=0x0c09f63au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f640; }
goto P_0c09f63c;
P_0c09f63c: /* original f0b5, guest PC 0x0c09f63c */
if(!s->budget--) { s->failed_pc=0x0c09f63cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[11]))!=0);
goto P_0c09f63e;
P_0c09f63e: /* original 8b02, guest PC 0x0c09f63e */
if(!s->budget--) { s->failed_pc=0x0c09f63eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f646; }
goto P_0c09f640;
P_0c09f640: /* original a001, guest PC 0x0c09f640 */
if(!s->budget--) { s->failed_pc=0x0c09f640u; return 0; }
vf3_matrix_move(s,11,1);
goto P_0c09f646;
P_0c09f642: /* original fb1c, guest PC 0x0c09f642 */
if(!s->budget--) { s->failed_pc=0x0c09f642u; return 0; }
vf3_matrix_move(s,11,1);
goto P_0c09f644;
P_0c09f644: /* original fb0c, guest PC 0x0c09f644 */
if(!s->budget--) { s->failed_pc=0x0c09f644u; return 0; }
vf3_matrix_move(s,11,0);
goto P_0c09f646;
P_0c09f646: /* original f215, guest PC 0x0c09f646 */
if(!s->budget--) { s->failed_pc=0x0c09f646u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[1]))!=0);
goto P_0c09f648;
P_0c09f648: /* original 8905, guest PC 0x0c09f648 */
if(!s->budget--) { s->failed_pc=0x0c09f648u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f656; }
goto P_0c09f64a;
P_0c09f64a: /* original f025, guest PC 0x0c09f64a */
if(!s->budget--) { s->failed_pc=0x0c09f64au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[2]))!=0);
goto P_0c09f64c;
P_0c09f64c: /* original 8905, guest PC 0x0c09f64c */
if(!s->budget--) { s->failed_pc=0x0c09f64cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f65a; }
goto P_0c09f64e;
P_0c09f64e: /* original f215, guest PC 0x0c09f64e */
if(!s->budget--) { s->failed_pc=0x0c09f64eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[1]))!=0);
goto P_0c09f650;
P_0c09f650: /* original 8901, guest PC 0x0c09f650 */
if(!s->budget--) { s->failed_pc=0x0c09f650u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f656; }
goto P_0c09f652;
P_0c09f652: /* original f025, guest PC 0x0c09f652 */
if(!s->budget--) { s->failed_pc=0x0c09f652u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[2]))!=0);
goto P_0c09f654;
P_0c09f654: /* original 8b02, guest PC 0x0c09f654 */
if(!s->budget--) { s->failed_pc=0x0c09f654u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f65c; }
goto P_0c09f656;
P_0c09f656: /* original a001, guest PC 0x0c09f656 */
if(!s->budget--) { s->failed_pc=0x0c09f656u; return 0; }
vf3_matrix_move(s,2,1);
goto P_0c09f65c;
P_0c09f658: /* original f21c, guest PC 0x0c09f658 */
if(!s->budget--) { s->failed_pc=0x0c09f658u; return 0; }
vf3_matrix_move(s,2,1);
goto P_0c09f65a;
P_0c09f65a: /* original f20c, guest PC 0x0c09f65a */
if(!s->budget--) { s->failed_pc=0x0c09f65au; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c09f65c;
P_0c09f65c: /* original f8a5, guest PC 0x0c09f65c */
if(!s->budget--) { s->failed_pc=0x0c09f65cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[10]))!=0);
goto P_0c09f65e;
P_0c09f65e: /* original 8903, guest PC 0x0c09f65e */
if(!s->budget--) { s->failed_pc=0x0c09f65eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f668; }
goto P_0c09f660;
P_0c09f660: /* original fa45, guest PC 0x0c09f660 */
if(!s->budget--) { s->failed_pc=0x0c09f660u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[4]))!=0);
goto P_0c09f662;
P_0c09f662: /* original 8b07, guest PC 0x0c09f662 */
if(!s->budget--) { s->failed_pc=0x0c09f662u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f674; }
goto P_0c09f664;
P_0c09f664: /* original affa, guest PC 0x0c09f664 */
if(!s->budget--) { s->failed_pc=0x0c09f664u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[9],r[18],'-');
goto P_0c09f65c;
P_0c09f666: /* original fa91, guest PC 0x0c09f666 */
if(!s->budget--) { s->failed_pc=0x0c09f666u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[9],r[18],'-');
goto P_0c09f668;
P_0c09f668: /* original fa65, guest PC 0x0c09f668 */
if(!s->budget--) { s->failed_pc=0x0c09f668u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[6]))!=0);
goto P_0c09f66a;
P_0c09f66a: /* original 8903, guest PC 0x0c09f66a */
if(!s->budget--) { s->failed_pc=0x0c09f66au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f674; }
goto P_0c09f66c;
P_0c09f66c: /* original f3ac, guest PC 0x0c09f66c */
if(!s->budget--) { s->failed_pc=0x0c09f66cu; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c09f66e;
P_0c09f66e: /* original fa9c, guest PC 0x0c09f66e */
if(!s->budget--) { s->failed_pc=0x0c09f66eu; return 0; }
vf3_matrix_move(s,10,9);
goto P_0c09f670;
P_0c09f670: /* original aff4, guest PC 0x0c09f670 */
if(!s->budget--) { s->failed_pc=0x0c09f670u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[3],r[18],'+');
goto P_0c09f65c;
P_0c09f672: /* original fa30, guest PC 0x0c09f672 */
if(!s->budget--) { s->failed_pc=0x0c09f672u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[3],r[18],'+');
goto P_0c09f674;
P_0c09f674: /* original f8b5, guest PC 0x0c09f674 */
if(!s->budget--) { s->failed_pc=0x0c09f674u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[11]))!=0);
goto P_0c09f676;
P_0c09f676: /* original 8903, guest PC 0x0c09f676 */
if(!s->budget--) { s->failed_pc=0x0c09f676u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f680; }
goto P_0c09f678;
P_0c09f678: /* original fb45, guest PC 0x0c09f678 */
if(!s->budget--) { s->failed_pc=0x0c09f678u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[4]))!=0);
goto P_0c09f67a;
P_0c09f67a: /* original 8b07, guest PC 0x0c09f67a */
if(!s->budget--) { s->failed_pc=0x0c09f67au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f68c; }
goto P_0c09f67c;
P_0c09f67c: /* original affa, guest PC 0x0c09f67c */
if(!s->budget--) { s->failed_pc=0x0c09f67cu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[9],r[18],'-');
goto P_0c09f674;
P_0c09f67e: /* original fb91, guest PC 0x0c09f67e */
if(!s->budget--) { s->failed_pc=0x0c09f67eu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[9],r[18],'-');
goto P_0c09f680;
P_0c09f680: /* original fb65, guest PC 0x0c09f680 */
if(!s->budget--) { s->failed_pc=0x0c09f680u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[6]))!=0);
goto P_0c09f682;
P_0c09f682: /* original 8903, guest PC 0x0c09f682 */
if(!s->budget--) { s->failed_pc=0x0c09f682u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f68c; }
goto P_0c09f684;
P_0c09f684: /* original f3bc, guest PC 0x0c09f684 */
if(!s->budget--) { s->failed_pc=0x0c09f684u; return 0; }
vf3_matrix_move(s,3,11);
goto P_0c09f686;
P_0c09f686: /* original fb9c, guest PC 0x0c09f686 */
if(!s->budget--) { s->failed_pc=0x0c09f686u; return 0; }
vf3_matrix_move(s,11,9);
goto P_0c09f688;
P_0c09f688: /* original aff4, guest PC 0x0c09f688 */
if(!s->budget--) { s->failed_pc=0x0c09f688u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[3],r[18],'+');
goto P_0c09f674;
P_0c09f68a: /* original fb30, guest PC 0x0c09f68a */
if(!s->budget--) { s->failed_pc=0x0c09f68au; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[3],r[18],'+');
goto P_0c09f68c;
P_0c09f68c: /* original f3ac, guest PC 0x0c09f68c */
if(!s->budget--) { s->failed_pc=0x0c09f68cu; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c09f68e;
P_0c09f68e: /* original e004, guest PC 0x0c09f68e */
if(!s->budget--) { s->failed_pc=0x0c09f68eu; return 0; }
r[0]=0x00000004u;
goto P_0c09f690;
P_0c09f690: /* original f35d, guest PC 0x0c09f690 */
if(!s->budget--) { s->failed_pc=0x0c09f690u; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c09f692;
P_0c09f692: /* original f735, guest PC 0x0c09f692 */
if(!s->budget--) { s->failed_pc=0x0c09f692u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[3]))!=0);
goto P_0c09f694;
P_0c09f694: /* original 8d0d, guest PC 0x0c09f694 */
if(!s->budget--) { s->failed_pc=0x0c09f694u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[15]+r[0]);
if(cond) { goto P_0c09f6b2; }
goto P_0c09f698;
P_0c09f696: /* original ff37, guest PC 0x0c09f696 */
if(!s->budget--) { s->failed_pc=0x0c09f696u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09f698;
P_0c09f698: /* original f3bc, guest PC 0x0c09f698 */
if(!s->budget--) { s->failed_pc=0x0c09f698u; return 0; }
vf3_matrix_move(s,3,11);
goto P_0c09f69a;
P_0c09f69a: /* original f35d, guest PC 0x0c09f69a */
if(!s->budget--) { s->failed_pc=0x0c09f69au; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c09f69c;
P_0c09f69c: /* original f735, guest PC 0x0c09f69c */
if(!s->budget--) { s->failed_pc=0x0c09f69cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[3]))!=0);
goto P_0c09f69e;
P_0c09f69e: /* original 8d08, guest PC 0x0c09f69e */
if(!s->budget--) { s->failed_pc=0x0c09f69eu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[15]);
if(cond) { goto P_0c09f6b2; }
goto P_0c09f6a2;
P_0c09f6a0: /* original ff3a, guest PC 0x0c09f6a0 */
if(!s->budget--) { s->failed_pc=0x0c09f6a0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c09f6a2;
P_0c09f6a2: /* original f251, guest PC 0x0c09f6a2 */
if(!s->budget--) { s->failed_pc=0x0c09f6a2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c09f6a4;
P_0c09f6a4: /* original fa41, guest PC 0x0c09f6a4 */
if(!s->budget--) { s->failed_pc=0x0c09f6a4u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[4],r[18],'-');
goto P_0c09f6a6;
P_0c09f6a6: /* original fb41, guest PC 0x0c09f6a6 */
if(!s->budget--) { s->failed_pc=0x0c09f6a6u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[4],r[18],'-');
goto P_0c09f6a8;
P_0c09f6a8: /* original f24d, guest PC 0x0c09f6a8 */
if(!s->budget--) { s->failed_pc=0x0c09f6a8u; return 0; }
fr[2]^=0x80000000u;
goto P_0c09f6aa;
P_0c09f6aa: /* original f32c, guest PC 0x0c09f6aa */
if(!s->budget--) { s->failed_pc=0x0c09f6aau; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c09f6ac;
P_0c09f6ac: /* original f25c, guest PC 0x0c09f6ac */
if(!s->budget--) { s->failed_pc=0x0c09f6acu; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c09f6ae;
P_0c09f6ae: /* original afd5, guest PC 0x0c09f6ae */
if(!s->budget--) { s->failed_pc=0x0c09f6aeu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c09f65c;
P_0c09f6b0: /* original f230, guest PC 0x0c09f6b0 */
if(!s->budget--) { s->failed_pc=0x0c09f6b0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c09f6b2;
P_0c09f6b2: /* original f4aa, guest PC 0x0c09f6b2 */
if(!s->budget--) { s->failed_pc=0x0c09f6b2u; return 0; }
vf3_matrix_store(s,ram,10,r[4]);
goto P_0c09f6b4;
P_0c09f6b4: /* original 740c, guest PC 0x0c09f6b4 */
if(!s->budget--) { s->failed_pc=0x0c09f6b4u; return 0; }
r[4]+=0x0000000cu;
goto P_0c09f6b6;
P_0c09f6b6: /* original f52a, guest PC 0x0c09f6b6 */
if(!s->budget--) { s->failed_pc=0x0c09f6b6u; return 0; }
vf3_matrix_store(s,ram,2,r[5]);
goto P_0c09f6b8;
P_0c09f6b8: /* original f6ba, guest PC 0x0c09f6b8 */
if(!s->budget--) { s->failed_pc=0x0c09f6b8u; return 0; }
vf3_matrix_store(s,ram,11,r[6]);
goto P_0c09f6ba;
P_0c09f6ba: /* original 6043, guest PC 0x0c09f6ba */
if(!s->budget--) { s->failed_pc=0x0c09f6bau; return 0; }
r[0]=r[4];
goto P_0c09f6bc;
P_0c09f6bc: /* original 000b, guest PC 0x0c09f6bc */
if(!s->budget--) { s->failed_pc=0x0c09f6bcu; return 0; }
target=r[16];
r[15]+=0x00000008u;
s->pc=target; return ram->oob==0;
P_0c09f6be: /* original 7f08, guest PC 0x0c09f6be */
if(!s->budget--) { s->failed_pc=0x0c09f6beu; return 0; }
r[15]+=0x00000008u;
if(!vf3_matrix_family(0x0c09f6c0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f6c0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
