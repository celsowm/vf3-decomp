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
int vf3_away_batch19_adapter_18(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07b0f4u: goto P_0c07b0f4;
case 0x0c07b0f6u: goto P_0c07b0f6;
case 0x0c07b0f8u: goto P_0c07b0f8;
case 0x0c07b0fau: goto P_0c07b0fa;
case 0x0c07b0fcu: goto P_0c07b0fc;
case 0x0c07b0feu: goto P_0c07b0fe;
case 0x0c07b100u: goto P_0c07b100;
case 0x0c07b102u: goto P_0c07b102;
case 0x0c07b104u: goto P_0c07b104;
case 0x0c07b106u: goto P_0c07b106;
case 0x0c07b108u: goto P_0c07b108;
case 0x0c07b10au: goto P_0c07b10a;
case 0x0c07b10cu: goto P_0c07b10c;
case 0x0c07b10eu: goto P_0c07b10e;
case 0x0c07b110u: goto P_0c07b110;
case 0x0c07b112u: goto P_0c07b112;
case 0x0c07b114u: goto P_0c07b114;
case 0x0c07b116u: goto P_0c07b116;
case 0x0c07b118u: goto P_0c07b118;
case 0x0c07b11au: goto P_0c07b11a;
case 0x0c07b11cu: goto P_0c07b11c;
case 0x0c07b11eu: goto P_0c07b11e;
case 0x0c07b120u: goto P_0c07b120;
case 0x0c07b122u: goto P_0c07b122;
case 0x0c07b124u: goto P_0c07b124;
case 0x0c07b126u: goto P_0c07b126;
case 0x0c07b128u: goto P_0c07b128;
case 0x0c07b12au: goto P_0c07b12a;
case 0x0c07b12cu: goto P_0c07b12c;
case 0x0c07b12eu: goto P_0c07b12e;
case 0x0c07b130u: goto P_0c07b130;
case 0x0c07b132u: goto P_0c07b132;
case 0x0c07b134u: goto P_0c07b134;
case 0x0c07b136u: goto P_0c07b136;
case 0x0c07b138u: goto P_0c07b138;
case 0x0c07b13au: goto P_0c07b13a;
case 0x0c07b13cu: goto P_0c07b13c;
case 0x0c07b13eu: goto P_0c07b13e;
case 0x0c07b140u: goto P_0c07b140;
case 0x0c07b142u: goto P_0c07b142;
case 0x0c07b144u: goto P_0c07b144;
case 0x0c07b146u: goto P_0c07b146;
case 0x0c07b148u: goto P_0c07b148;
case 0x0c07b14au: goto P_0c07b14a;
case 0x0c07b14cu: goto P_0c07b14c;
case 0x0c07b14eu: goto P_0c07b14e;
case 0x0c07b150u: goto P_0c07b150;
case 0x0c07b152u: goto P_0c07b152;
case 0x0c07b154u: goto P_0c07b154;
case 0x0c07b156u: goto P_0c07b156;
case 0x0c07b158u: goto P_0c07b158;
case 0x0c07b15au: goto P_0c07b15a;
case 0x0c07b15cu: goto P_0c07b15c;
case 0x0c07b15eu: goto P_0c07b15e;
case 0x0c07b160u: goto P_0c07b160;
case 0x0c07b162u: goto P_0c07b162;
case 0x0c07b164u: goto P_0c07b164;
case 0x0c07b166u: goto P_0c07b166;
case 0x0c07b168u: goto P_0c07b168;
case 0x0c07b16au: goto P_0c07b16a;
case 0x0c07b16cu: goto P_0c07b16c;
case 0x0c07b16eu: goto P_0c07b16e;
case 0x0c07b170u: goto P_0c07b170;
case 0x0c07b172u: goto P_0c07b172;
case 0x0c07b174u: goto P_0c07b174;
case 0x0c07b176u: goto P_0c07b176;
case 0x0c07b178u: goto P_0c07b178;
case 0x0c07b17au: goto P_0c07b17a;
case 0x0c07b17cu: goto P_0c07b17c;
case 0x0c07b17eu: goto P_0c07b17e;
case 0x0c07b180u: goto P_0c07b180;
case 0x0c07b182u: goto P_0c07b182;
case 0x0c07b184u: goto P_0c07b184;
case 0x0c07b186u: goto P_0c07b186;
case 0x0c07b188u: goto P_0c07b188;
case 0x0c07b18au: goto P_0c07b18a;
case 0x0c07b18cu: goto P_0c07b18c;
case 0x0c07b18eu: goto P_0c07b18e;
case 0x0c07b190u: goto P_0c07b190;
case 0x0c07b192u: goto P_0c07b192;
case 0x0c07b194u: goto P_0c07b194;
case 0x0c07b196u: goto P_0c07b196;
case 0x0c07b198u: goto P_0c07b198;
case 0x0c07b19au: goto P_0c07b19a;
case 0x0c07b19cu: goto P_0c07b19c;
case 0x0c07b19eu: goto P_0c07b19e;
case 0x0c07b1a0u: goto P_0c07b1a0;
case 0x0c07b1a2u: goto P_0c07b1a2;
case 0x0c07b1a4u: goto P_0c07b1a4;
case 0x0c07b1a6u: goto P_0c07b1a6;
case 0x0c07b1a8u: goto P_0c07b1a8;
case 0x0c07b1aau: goto P_0c07b1aa;
case 0x0c07b1acu: goto P_0c07b1ac;
case 0x0c07b1aeu: goto P_0c07b1ae;
case 0x0c07b1b0u: goto P_0c07b1b0;
case 0x0c07b1b2u: goto P_0c07b1b2;
case 0x0c07b1b4u: goto P_0c07b1b4;
case 0x0c07b1b6u: goto P_0c07b1b6;
case 0x0c07b1b8u: goto P_0c07b1b8;
case 0x0c07b1bau: goto P_0c07b1ba;
case 0x0c07b1bcu: goto P_0c07b1bc;
case 0x0c07b1beu: goto P_0c07b1be;
case 0x0c07b1c0u: goto P_0c07b1c0;
case 0x0c07b1c2u: goto P_0c07b1c2;
case 0x0c07b1c4u: goto P_0c07b1c4;
case 0x0c07b1c6u: goto P_0c07b1c6;
case 0x0c07b1c8u: goto P_0c07b1c8;
case 0x0c07b1cau: goto P_0c07b1ca;
case 0x0c07b1ccu: goto P_0c07b1cc;
case 0x0c07b1ceu: goto P_0c07b1ce;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c07b0f4: /* original 2fe6, guest PC 0x0c07b0f4 */
if(!s->budget--) { s->failed_pc=0x0c07b0f4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b0f6;
P_0c07b0f6: /* original 2fd6, guest PC 0x0c07b0f6 */
if(!s->budget--) { s->failed_pc=0x0c07b0f6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b0f8;
P_0c07b0f8: /* original 2fc6, guest PC 0x0c07b0f8 */
if(!s->budget--) { s->failed_pc=0x0c07b0f8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b0fa;
P_0c07b0fa: /* original 2fb6, guest PC 0x0c07b0fa */
if(!s->budget--) { s->failed_pc=0x0c07b0fau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b0fc;
P_0c07b0fc: /* original 2fa6, guest PC 0x0c07b0fc */
if(!s->budget--) { s->failed_pc=0x0c07b0fcu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b0fe;
P_0c07b0fe: /* original 2f96, guest PC 0x0c07b0fe */
if(!s->budget--) { s->failed_pc=0x0c07b0feu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b100;
P_0c07b100: /* original de35, guest PC 0x0c07b100 */
if(!s->budget--) { s->failed_pc=0x0c07b100u; return 0; }
r[14]=read(ram,0x0c07b1d8u,4);
goto P_0c07b102;
P_0c07b102: /* original 4f22, guest PC 0x0c07b102 */
if(!s->budget--) { s->failed_pc=0x0c07b102u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b104;
P_0c07b104: /* original d933, guest PC 0x0c07b104 */
if(!s->budget--) { s->failed_pc=0x0c07b104u; return 0; }
r[9]=read(ram,0x0c07b1d4u,4);
goto P_0c07b106;
P_0c07b106: /* original d335, guest PC 0x0c07b106 */
if(!s->budget--) { s->failed_pc=0x0c07b106u; return 0; }
r[3]=read(ram,0x0c07b1dcu,4);
goto P_0c07b108;
P_0c07b108: /* original 7ffc, guest PC 0x0c07b108 */
if(!s->budget--) { s->failed_pc=0x0c07b108u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07b10a;
P_0c07b10a: /* original 6b92, guest PC 0x0c07b10a */
if(!s->budget--) { s->failed_pc=0x0c07b10au; return 0; }
tmp=read(ram,r[9],4);
r[11]=tmp;
goto P_0c07b10c;
P_0c07b10c: /* original 2f32, guest PC 0x0c07b10c */
if(!s->budget--) { s->failed_pc=0x0c07b10cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07b10e;
P_0c07b10e: /* original 905f, guest PC 0x0c07b10e */
if(!s->budget--) { s->failed_pc=0x0c07b10eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b1d0u,2);
goto P_0c07b110;
P_0c07b110: /* original 02ed, guest PC 0x0c07b110 */
if(!s->budget--) { s->failed_pc=0x0c07b110u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c07b112;
P_0c07b112: /* original 4211, guest PC 0x0c07b112 */
if(!s->budget--) { s->failed_pc=0x0c07b112u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c07b114;
P_0c07b114: /* original 8f0f, guest PC 0x0c07b114 */
if(!s->budget--) { s->failed_pc=0x0c07b114u; return 0; }
cond=r[17]&1u;
r[12]=r[4];
if(!cond) { goto P_0c07b136; }
goto P_0c07b118;
P_0c07b116: /* original 6c43, guest PC 0x0c07b116 */
if(!s->budget--) { s->failed_pc=0x0c07b116u; return 0; }
r[12]=r[4];
goto P_0c07b118;
P_0c07b118: /* original b24a, guest PC 0x0c07b118 */
if(!s->budget--) { s->failed_pc=0x0c07b118u; return 0; }
target=code_base|0x0c07b5b0u; r[16]=code_base|0x0c07b11cu;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b11cu) { target=s->pc; goto dispatch; }
goto P_0c07b11c;
P_0c07b11a: /* original 04ed, guest PC 0x0c07b11a */
if(!s->budget--) { s->failed_pc=0x0c07b11au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c07b11c;
P_0c07b11c: /* original 6d03, guest PC 0x0c07b11c */
if(!s->budget--) { s->failed_pc=0x0c07b11cu; return 0; }
r[13]=r[0];
goto P_0c07b11e;
P_0c07b11e: /* original b267, guest PC 0x0c07b11e */
if(!s->budget--) { s->failed_pc=0x0c07b11eu; return 0; }
target=code_base|0x0c07b5f0u; r[16]=code_base|0x0c07b122u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b122u) { target=s->pc; goto dispatch; }
goto P_0c07b122;
P_0c07b120: /* original 6403, guest PC 0x0c07b120 */
if(!s->budget--) { s->failed_pc=0x0c07b120u; return 0; }
r[4]=r[0];
goto P_0c07b122;
P_0c07b122: /* original 64dd, guest PC 0x0c07b122 */
if(!s->budget--) { s->failed_pc=0x0c07b122u; return 0; }
r[4]=r[13]&65535u;
goto P_0c07b124;
P_0c07b124: /* original 6043, guest PC 0x0c07b124 */
if(!s->budget--) { s->failed_pc=0x0c07b124u; return 0; }
r[0]=r[4];
goto P_0c07b126;
P_0c07b126: /* original 882c, guest PC 0x0c07b126 */
if(!s->budget--) { s->failed_pc=0x0c07b126u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002cu)!=0);
goto P_0c07b128;
P_0c07b128: /* original 8902, guest PC 0x0c07b128 */
if(!s->budget--) { s->failed_pc=0x0c07b128u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b130; }
goto P_0c07b12a;
P_0c07b12a: /* original 6043, guest PC 0x0c07b12a */
if(!s->budget--) { s->failed_pc=0x0c07b12au; return 0; }
r[0]=r[4];
goto P_0c07b12c;
P_0c07b12c: /* original 8834, guest PC 0x0c07b12c */
if(!s->budget--) { s->failed_pc=0x0c07b12cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000034u)!=0);
goto P_0c07b12e;
P_0c07b12e: /* original 8b02, guest PC 0x0c07b12e */
if(!s->budget--) { s->failed_pc=0x0c07b12eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b136; }
goto P_0c07b130;
P_0c07b130: /* original 64d3, guest PC 0x0c07b130 */
if(!s->budget--) { s->failed_pc=0x0c07b130u; return 0; }
r[4]=r[13];
goto P_0c07b132;
P_0c07b132: /* original b25d, guest PC 0x0c07b132 */
if(!s->budget--) { s->failed_pc=0x0c07b132u; return 0; }
target=code_base|0x0c07b5f0u; r[16]=code_base|0x0c07b136u;
r[4]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b136u) { target=s->pc; goto dispatch; }
goto P_0c07b136;
P_0c07b134: /* original 7401, guest PC 0x0c07b134 */
if(!s->budget--) { s->failed_pc=0x0c07b134u; return 0; }
r[4]+=0x00000001u;
goto P_0c07b136;
P_0c07b136: /* original 904b, guest PC 0x0c07b136 */
if(!s->budget--) { s->failed_pc=0x0c07b136u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b1d0u,2);
goto P_0c07b138;
P_0c07b138: /* original e2ff, guest PC 0x0c07b138 */
if(!s->budget--) { s->failed_pc=0x0c07b138u; return 0; }
r[2]=0xffffffffu;
goto P_0c07b13a;
P_0c07b13a: /* original 0e25, guest PC 0x0c07b13a */
if(!s->budget--) { s->failed_pc=0x0c07b13au; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c07b13c;
P_0c07b13c: /* original d227, guest PC 0x0c07b13c */
if(!s->budget--) { s->failed_pc=0x0c07b13cu; return 0; }
r[2]=read(ram,0x0c07b1dcu,4);
goto P_0c07b13e;
P_0c07b13e: /* original d328, guest PC 0x0c07b13e */
if(!s->budget--) { s->failed_pc=0x0c07b13eu; return 0; }
r[3]=read(ram,0x0c07b1e0u,4);
goto P_0c07b140;
P_0c07b140: /* original 6122, guest PC 0x0c07b140 */
if(!s->budget--) { s->failed_pc=0x0c07b140u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c07b142;
P_0c07b142: /* original 2138, guest PC 0x0c07b142 */
if(!s->budget--) { s->failed_pc=0x0c07b142u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c07b144;
P_0c07b144: /* original 8b37, guest PC 0x0c07b144 */
if(!s->budget--) { s->failed_pc=0x0c07b144u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b1b6; }
goto P_0c07b146;
P_0c07b146: /* original d227, guest PC 0x0c07b146 */
if(!s->budget--) { s->failed_pc=0x0c07b146u; return 0; }
r[2]=read(ram,0x0c07b1e4u,4);
goto P_0c07b148;
P_0c07b148: /* original 63cd, guest PC 0x0c07b148 */
if(!s->budget--) { s->failed_pc=0x0c07b148u; return 0; }
r[3]=r[12]&65535u;
goto P_0c07b14a;
P_0c07b14a: /* original 9041, guest PC 0x0c07b14a */
if(!s->budget--) { s->failed_pc=0x0c07b14au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b1d0u,2);
goto P_0c07b14c;
P_0c07b14c: /* original 3320, guest PC 0x0c07b14c */
if(!s->budget--) { s->failed_pc=0x0c07b14cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c07b14e;
P_0c07b14e: /* original 8d32, guest PC 0x0c07b14e */
if(!s->budget--) { s->failed_pc=0x0c07b14eu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[12],2);
if(cond) { goto P_0c07b1b6; }
goto P_0c07b152;
P_0c07b150: /* original 0ec5, guest PC 0x0c07b150 */
if(!s->budget--) { s->failed_pc=0x0c07b150u; return 0; }
write(ram,r[14]+r[0],r[12],2);
goto P_0c07b152;
P_0c07b152: /* original b22d, guest PC 0x0c07b152 */
if(!s->budget--) { s->failed_pc=0x0c07b152u; return 0; }
target=code_base|0x0c07b5b0u; r[16]=code_base|0x0c07b156u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b156u) { target=s->pc; goto dispatch; }
goto P_0c07b156;
P_0c07b154: /* original 64c3, guest PC 0x0c07b154 */
if(!s->budget--) { s->failed_pc=0x0c07b154u; return 0; }
r[4]=r[12];
goto P_0c07b156;
P_0c07b156: /* original 6d03, guest PC 0x0c07b156 */
if(!s->budget--) { s->failed_pc=0x0c07b156u; return 0; }
r[13]=r[0];
goto P_0c07b158;
P_0c07b158: /* original 6cdd, guest PC 0x0c07b158 */
if(!s->budget--) { s->failed_pc=0x0c07b158u; return 0; }
r[12]=r[13]&65535u;
goto P_0c07b15a;
P_0c07b15a: /* original d023, guest PC 0x0c07b15a */
if(!s->budget--) { s->failed_pc=0x0c07b15au; return 0; }
r[0]=read(ram,0x0c07b1e8u,4);
goto P_0c07b15c;
P_0c07b15c: /* original 62c3, guest PC 0x0c07b15c */
if(!s->budget--) { s->failed_pc=0x0c07b15cu; return 0; }
r[2]=r[12];
goto P_0c07b15e;
P_0c07b15e: /* original 72db, guest PC 0x0c07b15e */
if(!s->budget--) { s->failed_pc=0x0c07b15eu; return 0; }
r[2]+=0xffffffdbu;
goto P_0c07b160;
P_0c07b160: /* original 032c, guest PC 0x0c07b160 */
if(!s->budget--) { s->failed_pc=0x0c07b160u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c07b162;
P_0c07b162: /* original 2338, guest PC 0x0c07b162 */
if(!s->budget--) { s->failed_pc=0x0c07b162u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07b164;
P_0c07b164: /* original 892b, guest PC 0x0c07b164 */
if(!s->budget--) { s->failed_pc=0x0c07b164u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b1be; }
goto P_0c07b166;
P_0c07b166: /* original d321, guest PC 0x0c07b166 */
if(!s->budget--) { s->failed_pc=0x0c07b166u; return 0; }
r[3]=read(ram,0x0c07b1ecu,4);
goto P_0c07b168;
P_0c07b168: /* original 64c3, guest PC 0x0c07b168 */
if(!s->budget--) { s->failed_pc=0x0c07b168u; return 0; }
r[4]=r[12];
goto P_0c07b16a;
P_0c07b16a: /* original 65b3, guest PC 0x0c07b16a */
if(!s->budget--) { s->failed_pc=0x0c07b16au; return 0; }
r[5]=r[11];
goto P_0c07b16c;
P_0c07b16c: /* original 74db, guest PC 0x0c07b16c */
if(!s->budget--) { s->failed_pc=0x0c07b16cu; return 0; }
r[4]+=0xffffffdbu;
goto P_0c07b16e;
P_0c07b16e: /* original 430b, guest PC 0x0c07b16e */
if(!s->budget--) { s->failed_pc=0x0c07b16eu; return 0; }
target=r[3];
r[16]=code_base|0x0c07b172u;
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b172u) { target=s->pc; goto dispatch; }
goto P_0c07b172;
P_0c07b170: /* original 044c, guest PC 0x0c07b170 */
if(!s->budget--) { s->failed_pc=0x0c07b170u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c07b172;
P_0c07b172: /* original 6edd, guest PC 0x0c07b172 */
if(!s->budget--) { s->failed_pc=0x0c07b172u; return 0; }
r[14]=r[13]&65535u;
goto P_0c07b174;
P_0c07b174: /* original da1e, guest PC 0x0c07b174 */
if(!s->budget--) { s->failed_pc=0x0c07b174u; return 0; }
r[10]=read(ram,0x0c07b1f0u,4);
goto P_0c07b176;
P_0c07b176: /* original 60e3, guest PC 0x0c07b176 */
if(!s->budget--) { s->failed_pc=0x0c07b176u; return 0; }
r[0]=r[14];
goto P_0c07b178;
P_0c07b178: /* original 882c, guest PC 0x0c07b178 */
if(!s->budget--) { s->failed_pc=0x0c07b178u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002cu)!=0);
goto P_0c07b17a;
P_0c07b17a: /* original 8b04, guest PC 0x0c07b17a */
if(!s->budget--) { s->failed_pc=0x0c07b17au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b186; }
goto P_0c07b17c;
P_0c07b17c: /* original 4a0b, guest PC 0x0c07b17c */
if(!s->budget--) { s->failed_pc=0x0c07b17cu; return 0; }
target=r[10];
r[16]=code_base|0x0c07b180u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b180u) { target=s->pc; goto dispatch; }
goto P_0c07b180;
P_0c07b17e: /* original 64e3, guest PC 0x0c07b17e */
if(!s->budget--) { s->failed_pc=0x0c07b17eu; return 0; }
r[4]=r[14];
goto P_0c07b180;
P_0c07b180: /* original d41c, guest PC 0x0c07b180 */
if(!s->budget--) { s->failed_pc=0x0c07b180u; return 0; }
r[4]=read(ram,0x0c07b1f4u,4);
goto P_0c07b182;
P_0c07b182: /* original a006, guest PC 0x0c07b182 */
if(!s->budget--) { s->failed_pc=0x0c07b182u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c07b192;
P_0c07b184: /* original 6592, guest PC 0x0c07b184 */
if(!s->budget--) { s->failed_pc=0x0c07b184u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c07b186;
P_0c07b186: /* original 8834, guest PC 0x0c07b186 */
if(!s->budget--) { s->failed_pc=0x0c07b186u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000034u)!=0);
goto P_0c07b188;
P_0c07b188: /* original 8b0c, guest PC 0x0c07b188 */
if(!s->budget--) { s->failed_pc=0x0c07b188u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b1a4; }
goto P_0c07b18a;
P_0c07b18a: /* original 4a0b, guest PC 0x0c07b18a */
if(!s->budget--) { s->failed_pc=0x0c07b18au; return 0; }
target=r[10];
r[16]=code_base|0x0c07b18eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b18eu) { target=s->pc; goto dispatch; }
goto P_0c07b18e;
P_0c07b18c: /* original 64e3, guest PC 0x0c07b18c */
if(!s->budget--) { s->failed_pc=0x0c07b18cu; return 0; }
r[4]=r[14];
goto P_0c07b18e;
P_0c07b18e: /* original d41a, guest PC 0x0c07b18e */
if(!s->budget--) { s->failed_pc=0x0c07b18eu; return 0; }
r[4]=read(ram,0x0c07b1f8u,4);
goto P_0c07b190;
P_0c07b190: /* original 6592, guest PC 0x0c07b190 */
if(!s->budget--) { s->failed_pc=0x0c07b190u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c07b192;
P_0c07b192: /* original bb38, guest PC 0x0c07b192 */
if(!s->budget--) { s->failed_pc=0x0c07b192u; return 0; }
target=code_base|0x0c07a806u; r[16]=code_base|0x0c07b196u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b196u) { target=s->pc; goto dispatch; }
goto P_0c07b196;
P_0c07b194: /* original 0009, guest PC 0x0c07b194 */
if(!s->budget--) { s->failed_pc=0x0c07b194u; return 0; }
goto P_0c07b196;
P_0c07b196: /* original d019, guest PC 0x0c07b196 */
if(!s->budget--) { s->failed_pc=0x0c07b196u; return 0; }
r[0]=read(ram,0x0c07b1fcu,4);
goto P_0c07b198;
P_0c07b198: /* original 62e3, guest PC 0x0c07b198 */
if(!s->budget--) { s->failed_pc=0x0c07b198u; return 0; }
r[2]=r[14];
goto P_0c07b19a;
P_0c07b19a: /* original 7c01, guest PC 0x0c07b19a */
if(!s->budget--) { s->failed_pc=0x0c07b19au; return 0; }
r[12]+=0x00000001u;
goto P_0c07b19c;
P_0c07b19c: /* original 7201, guest PC 0x0c07b19c */
if(!s->budget--) { s->failed_pc=0x0c07b19cu; return 0; }
r[2]+=0x00000001u;
goto P_0c07b19e;
P_0c07b19e: /* original 4c00, guest PC 0x0c07b19e */
if(!s->budget--) { s->failed_pc=0x0c07b19eu; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c07b1a0;
P_0c07b1a0: /* original a005, guest PC 0x0c07b1a0 */
if(!s->budget--) { s->failed_pc=0x0c07b1a0u; return 0; }
write(ram,r[12]+r[0],r[2],2);
goto P_0c07b1ae;
P_0c07b1a2: /* original 0c25, guest PC 0x0c07b1a2 */
if(!s->budget--) { s->failed_pc=0x0c07b1a2u; return 0; }
write(ram,r[12]+r[0],r[2],2);
goto P_0c07b1a4;
P_0c07b1a4: /* original 4a0b, guest PC 0x0c07b1a4 */
if(!s->budget--) { s->failed_pc=0x0c07b1a4u; return 0; }
target=r[10];
r[16]=code_base|0x0c07b1a8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b1a8u) { target=s->pc; goto dispatch; }
goto P_0c07b1a8;
P_0c07b1a6: /* original 64e3, guest PC 0x0c07b1a6 */
if(!s->budget--) { s->failed_pc=0x0c07b1a6u; return 0; }
r[4]=r[14];
goto P_0c07b1a8;
P_0c07b1a8: /* original d415, guest PC 0x0c07b1a8 */
if(!s->budget--) { s->failed_pc=0x0c07b1a8u; return 0; }
r[4]=read(ram,0x0c07b200u,4);
goto P_0c07b1aa;
P_0c07b1aa: /* original bb1d, guest PC 0x0c07b1aa */
if(!s->budget--) { s->failed_pc=0x0c07b1aau; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07b1aeu;
r[5]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b1aeu) { target=s->pc; goto dispatch; }
goto P_0c07b1ae;
P_0c07b1ac: /* original 65b3, guest PC 0x0c07b1ac */
if(!s->budget--) { s->failed_pc=0x0c07b1acu; return 0; }
r[5]=r[11];
goto P_0c07b1ae;
P_0c07b1ae: /* original d013, guest PC 0x0c07b1ae */
if(!s->budget--) { s->failed_pc=0x0c07b1aeu; return 0; }
r[0]=read(ram,0x0c07b1fcu,4);
goto P_0c07b1b0;
P_0c07b1b0: /* original 6ddd, guest PC 0x0c07b1b0 */
if(!s->budget--) { s->failed_pc=0x0c07b1b0u; return 0; }
r[13]=r[13]&65535u;
goto P_0c07b1b2;
P_0c07b1b2: /* original 4d00, guest PC 0x0c07b1b2 */
if(!s->budget--) { s->failed_pc=0x0c07b1b2u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c07b1b4;
P_0c07b1b4: /* original 0de5, guest PC 0x0c07b1b4 */
if(!s->budget--) { s->failed_pc=0x0c07b1b4u; return 0; }
write(ram,r[13]+r[0],r[14],2);
goto P_0c07b1b6;
P_0c07b1b6: /* original 900c, guest PC 0x0c07b1b6 */
if(!s->budget--) { s->failed_pc=0x0c07b1b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b1d2u,2);
goto P_0c07b1b8;
P_0c07b1b8: /* original e2ff, guest PC 0x0c07b1b8 */
if(!s->budget--) { s->failed_pc=0x0c07b1b8u; return 0; }
r[2]=0xffffffffu;
goto P_0c07b1ba;
P_0c07b1ba: /* original 63f2, guest PC 0x0c07b1ba */
if(!s->budget--) { s->failed_pc=0x0c07b1bau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07b1bc;
P_0c07b1bc: /* original 0326, guest PC 0x0c07b1bc */
if(!s->budget--) { s->failed_pc=0x0c07b1bcu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c07b1be;
P_0c07b1be: /* original 7f04, guest PC 0x0c07b1be */
if(!s->budget--) { s->failed_pc=0x0c07b1beu; return 0; }
r[15]+=0x00000004u;
goto P_0c07b1c0;
P_0c07b1c0: /* original 4f26, guest PC 0x0c07b1c0 */
if(!s->budget--) { s->failed_pc=0x0c07b1c0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b1c2;
P_0c07b1c2: /* original 69f6, guest PC 0x0c07b1c2 */
if(!s->budget--) { s->failed_pc=0x0c07b1c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07b1c4;
P_0c07b1c4: /* original 6af6, guest PC 0x0c07b1c4 */
if(!s->budget--) { s->failed_pc=0x0c07b1c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07b1c6;
P_0c07b1c6: /* original 6bf6, guest PC 0x0c07b1c6 */
if(!s->budget--) { s->failed_pc=0x0c07b1c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07b1c8;
P_0c07b1c8: /* original 6cf6, guest PC 0x0c07b1c8 */
if(!s->budget--) { s->failed_pc=0x0c07b1c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07b1ca;
P_0c07b1ca: /* original 6df6, guest PC 0x0c07b1ca */
if(!s->budget--) { s->failed_pc=0x0c07b1cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b1cc;
P_0c07b1cc: /* original 000b, guest PC 0x0c07b1cc */
if(!s->budget--) { s->failed_pc=0x0c07b1ccu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b1ce: /* original 6ef6, guest PC 0x0c07b1ce */
if(!s->budget--) { s->failed_pc=0x0c07b1ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07b1d0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b1d0u; return 0; } return 1;
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
return vf3_matrix_family(0x0c07b5b0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
