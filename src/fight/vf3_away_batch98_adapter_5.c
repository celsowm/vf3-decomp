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
int vf3_away_batch98_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c060d14u: goto P_0c060d14;
case 0x0c060d16u: goto P_0c060d16;
case 0x0c060d18u: goto P_0c060d18;
case 0x0c060d1au: goto P_0c060d1a;
case 0x0c060d1cu: goto P_0c060d1c;
case 0x0c07b35cu: goto P_0c07b35c;
case 0x0c07b35eu: goto P_0c07b35e;
case 0x0c07b360u: goto P_0c07b360;
case 0x0c07b362u: goto P_0c07b362;
case 0x0c07b364u: goto P_0c07b364;
case 0x0c07b366u: goto P_0c07b366;
case 0x0c07b368u: goto P_0c07b368;
case 0x0c07b36au: goto P_0c07b36a;
case 0x0c07b36cu: goto P_0c07b36c;
case 0x0c07b36eu: goto P_0c07b36e;
case 0x0c07b370u: goto P_0c07b370;
case 0x0c07b372u: goto P_0c07b372;
case 0x0c07b374u: goto P_0c07b374;
case 0x0c07b376u: goto P_0c07b376;
case 0x0c07b378u: goto P_0c07b378;
case 0x0c07b37au: goto P_0c07b37a;
case 0x0c07b37cu: goto P_0c07b37c;
case 0x0c07b37eu: goto P_0c07b37e;
case 0x0c07b380u: goto P_0c07b380;
case 0x0c07b382u: goto P_0c07b382;
case 0x0c07b384u: goto P_0c07b384;
case 0x0c07b386u: goto P_0c07b386;
case 0x0c07b388u: goto P_0c07b388;
case 0x0c07b38au: goto P_0c07b38a;
case 0x0c07b38cu: goto P_0c07b38c;
case 0x0c07b38eu: goto P_0c07b38e;
case 0x0c07b390u: goto P_0c07b390;
case 0x0c07b392u: goto P_0c07b392;
case 0x0c07b394u: goto P_0c07b394;
case 0x0c07b396u: goto P_0c07b396;
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
case 0x0c0a71acu: goto P_0c0a71ac;
case 0x0c0a71aeu: goto P_0c0a71ae;
case 0x0c0a71b0u: goto P_0c0a71b0;
case 0x0c0a71b2u: goto P_0c0a71b2;
case 0x0c0a71b4u: goto P_0c0a71b4;
case 0x0c0a71b6u: goto P_0c0a71b6;
case 0x0c0a71b8u: goto P_0c0a71b8;
case 0x0c0a71bau: goto P_0c0a71ba;
case 0x0c0a71bcu: goto P_0c0a71bc;
case 0x0c0a71beu: goto P_0c0a71be;
case 0x0c0a71c0u: goto P_0c0a71c0;
case 0x0c0a71c2u: goto P_0c0a71c2;
case 0x0c0a71c4u: goto P_0c0a71c4;
case 0x0c0a71c6u: goto P_0c0a71c6;
case 0x0c0a71c8u: goto P_0c0a71c8;
case 0x0c0a71cau: goto P_0c0a71ca;
case 0x0c0a71ccu: goto P_0c0a71cc;
case 0x0c0a71ceu: goto P_0c0a71ce;
case 0x0c0a71d0u: goto P_0c0a71d0;
case 0x0c0a71d2u: goto P_0c0a71d2;
case 0x0c0a7204u: goto P_0c0a7204;
case 0x0c0a7206u: goto P_0c0a7206;
case 0x0c0a7208u: goto P_0c0a7208;
case 0x0c0a720au: goto P_0c0a720a;
case 0x0c0a720cu: goto P_0c0a720c;
case 0x0c0a720eu: goto P_0c0a720e;
case 0x0c0a7210u: goto P_0c0a7210;
case 0x0c0a7212u: goto P_0c0a7212;
case 0x0c0a7214u: goto P_0c0a7214;
case 0x0c0a7216u: goto P_0c0a7216;
case 0x0c0a7218u: goto P_0c0a7218;
case 0x0c0a7250u: goto P_0c0a7250;
case 0x0c0a7252u: goto P_0c0a7252;
case 0x0c0a7254u: goto P_0c0a7254;
case 0x0c0a7256u: goto P_0c0a7256;
case 0x0c0a7258u: goto P_0c0a7258;
case 0x0c0a725au: goto P_0c0a725a;
case 0x0c0a725cu: goto P_0c0a725c;
case 0x0c0a725eu: goto P_0c0a725e;
case 0x0c0a7260u: goto P_0c0a7260;
case 0x0c0a7262u: goto P_0c0a7262;
case 0x0c0a7442u: goto P_0c0a7442;
case 0x0c0a7444u: goto P_0c0a7444;
case 0x0c0a7446u: goto P_0c0a7446;
case 0x0c0a7448u: goto P_0c0a7448;
case 0x0c0a744au: goto P_0c0a744a;
case 0x0c0a744cu: goto P_0c0a744c;
case 0x0c0a744eu: goto P_0c0a744e;
case 0x0c0a7662u: goto P_0c0a7662;
case 0x0c0a7664u: goto P_0c0a7664;
case 0x0c0a7666u: goto P_0c0a7666;
case 0x0c0a7668u: goto P_0c0a7668;
case 0x0c0a766au: goto P_0c0a766a;
case 0x0c0a766cu: goto P_0c0a766c;
case 0x0c0a766eu: goto P_0c0a766e;
case 0x0c0a7670u: goto P_0c0a7670;
case 0x0c0a7672u: goto P_0c0a7672;
case 0x0c0a7674u: goto P_0c0a7674;
case 0x0c0a7676u: goto P_0c0a7676;
case 0x0c0a7678u: goto P_0c0a7678;
case 0x0c0a767au: goto P_0c0a767a;
case 0x0c0a767cu: goto P_0c0a767c;
case 0x0c0a767eu: goto P_0c0a767e;
case 0x0c0a7680u: goto P_0c0a7680;
case 0x0c0a7682u: goto P_0c0a7682;
case 0x0c0a7684u: goto P_0c0a7684;
case 0x0c0a7686u: goto P_0c0a7686;
case 0x0c0a7688u: goto P_0c0a7688;
case 0x0c0a768au: goto P_0c0a768a;
case 0x0c0a768cu: goto P_0c0a768c;
case 0x0c0a768eu: goto P_0c0a768e;
case 0x0c0a7690u: goto P_0c0a7690;
case 0x0c0a7692u: goto P_0c0a7692;
case 0x0c0a7694u: goto P_0c0a7694;
case 0x0c0a7696u: goto P_0c0a7696;
case 0x0c0a7698u: goto P_0c0a7698;
case 0x0c0a769au: goto P_0c0a769a;
case 0x0c0a769cu: goto P_0c0a769c;
case 0x0c0a769eu: goto P_0c0a769e;
case 0x0c0a76a0u: goto P_0c0a76a0;
case 0x0c0a76a2u: goto P_0c0a76a2;
case 0x0c0a76a4u: goto P_0c0a76a4;
case 0x0c0a76a6u: goto P_0c0a76a6;
case 0x0c0a76a8u: goto P_0c0a76a8;
case 0x0c0a76aau: goto P_0c0a76aa;
case 0x0c0a76acu: goto P_0c0a76ac;
case 0x0c0a76aeu: goto P_0c0a76ae;
case 0x0c0a76b0u: goto P_0c0a76b0;
case 0x0c0a76b2u: goto P_0c0a76b2;
case 0x0c0a76b4u: goto P_0c0a76b4;
case 0x0c0a76b6u: goto P_0c0a76b6;
case 0x0c0a76b8u: goto P_0c0a76b8;
case 0x0c0a76bau: goto P_0c0a76ba;
case 0x0c0a76bcu: goto P_0c0a76bc;
default: return vf3_matrix_family(target,s,ram);
}
P_0c060d14: /* original d344, guest PC 0x0c060d14 */
if(!s->budget--) { s->failed_pc=0x0c060d14u; return 0; }
r[3]=read(ram,0x0c060e28u,4);
goto P_0c060d16;
P_0c060d16: /* original 343c, guest PC 0x0c060d16 */
if(!s->budget--) { s->failed_pc=0x0c060d16u; return 0; }
r[4]+=r[3];
goto P_0c060d18;
P_0c060d18: /* original 2452, guest PC 0x0c060d18 */
if(!s->budget--) { s->failed_pc=0x0c060d18u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c060d1a;
P_0c060d1a: /* original 000b, guest PC 0x0c060d1a */
if(!s->budget--) { s->failed_pc=0x0c060d1au; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c060d1c: /* original e001, guest PC 0x0c060d1c */
if(!s->budget--) { s->failed_pc=0x0c060d1cu; return 0; }
r[0]=0x00000001u;
if(!vf3_matrix_family(0x0c060d1eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c060d1eu; return 0; } return 1;
P_0c07b35c: /* original d553, guest PC 0x0c07b35c */
if(!s->budget--) { s->failed_pc=0x0c07b35cu; return 0; }
r[5]=read(ram,0x0c07b4acu,4);
goto P_0c07b35e;
P_0c07b35e: /* original 7ffc, guest PC 0x0c07b35e */
if(!s->budget--) { s->failed_pc=0x0c07b35eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07b360;
P_0c07b360: /* original e004, guest PC 0x0c07b360 */
if(!s->budget--) { s->failed_pc=0x0c07b360u; return 0; }
r[0]=0x00000004u;
goto P_0c07b362;
P_0c07b362: /* original f358, guest PC 0x0c07b362 */
if(!s->budget--) { s->failed_pc=0x0c07b362u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c07b364;
P_0c07b364: /* original f432, guest PC 0x0c07b364 */
if(!s->budget--) { s->failed_pc=0x0c07b364u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c07b366;
P_0c07b366: /* original ff3a, guest PC 0x0c07b366 */
if(!s->budget--) { s->failed_pc=0x0c07b366u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c07b368;
P_0c07b368: /* original d651, guest PC 0x0c07b368 */
if(!s->budget--) { s->failed_pc=0x0c07b368u; return 0; }
r[6]=read(ram,0x0c07b4b0u,4);
goto P_0c07b36a;
P_0c07b36a: /* original d352, guest PC 0x0c07b36a */
if(!s->budget--) { s->failed_pc=0x0c07b36au; return 0; }
r[3]=read(ram,0x0c07b4b4u,4);
goto P_0c07b36c;
P_0c07b36c: /* original f968, guest PC 0x0c07b36c */
if(!s->budget--) { s->failed_pc=0x0c07b36cu; return 0; }
vf3_matrix_load(s,ram,9,r[6]);
goto P_0c07b36e;
P_0c07b36e: /* original d252, guest PC 0x0c07b36e */
if(!s->budget--) { s->failed_pc=0x0c07b36eu; return 0; }
r[2]=read(ram,0x0c07b4b8u,4);
goto P_0c07b370;
P_0c07b370: /* original f592, guest PC 0x0c07b370 */
if(!s->budget--) { s->failed_pc=0x0c07b370u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[9],r[18],'*');
goto P_0c07b372;
P_0c07b372: /* original fa38, guest PC 0x0c07b372 */
if(!s->budget--) { s->failed_pc=0x0c07b372u; return 0; }
vf3_matrix_load(s,ram,10,r[3]);
goto P_0c07b374;
P_0c07b374: /* original fb28, guest PC 0x0c07b374 */
if(!s->budget--) { s->failed_pc=0x0c07b374u; return 0; }
vf3_matrix_load(s,ram,11,r[2]);
goto P_0c07b376;
P_0c07b376: /* original f4a0, guest PC 0x0c07b376 */
if(!s->budget--) { s->failed_pc=0x0c07b376u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[10],r[18],'+');
goto P_0c07b378;
P_0c07b378: /* original f5b0, guest PC 0x0c07b378 */
if(!s->budget--) { s->failed_pc=0x0c07b378u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[11],r[18],'+');
goto P_0c07b37a;
P_0c07b37a: /* original f447, guest PC 0x0c07b37a */
if(!s->budget--) { s->failed_pc=0x0c07b37au; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c07b37c;
P_0c07b37c: /* original e008, guest PC 0x0c07b37c */
if(!s->budget--) { s->failed_pc=0x0c07b37cu; return 0; }
r[0]=0x00000008u;
goto P_0c07b37e;
P_0c07b37e: /* original f457, guest PC 0x0c07b37e */
if(!s->budget--) { s->failed_pc=0x0c07b37eu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c07b380;
P_0c07b380: /* original e00c, guest PC 0x0c07b380 */
if(!s->budget--) { s->failed_pc=0x0c07b380u; return 0; }
r[0]=0x0000000cu;
goto P_0c07b382;
P_0c07b382: /* original f487, guest PC 0x0c07b382 */
if(!s->budget--) { s->failed_pc=0x0c07b382u; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c07b384;
P_0c07b384: /* original e010, guest PC 0x0c07b384 */
if(!s->budget--) { s->failed_pc=0x0c07b384u; return 0; }
r[0]=0x00000010u;
goto P_0c07b386;
P_0c07b386: /* original f358, guest PC 0x0c07b386 */
if(!s->budget--) { s->failed_pc=0x0c07b386u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c07b388;
P_0c07b388: /* original f362, guest PC 0x0c07b388 */
if(!s->budget--) { s->failed_pc=0x0c07b388u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c07b38a;
P_0c07b38a: /* original f437, guest PC 0x0c07b38a */
if(!s->budget--) { s->failed_pc=0x0c07b38au; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07b38c;
P_0c07b38c: /* original e014, guest PC 0x0c07b38c */
if(!s->budget--) { s->failed_pc=0x0c07b38cu; return 0; }
r[0]=0x00000014u;
goto P_0c07b38e;
P_0c07b38e: /* original f368, guest PC 0x0c07b38e */
if(!s->budget--) { s->failed_pc=0x0c07b38eu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
goto P_0c07b390;
P_0c07b390: /* original f372, guest PC 0x0c07b390 */
if(!s->budget--) { s->failed_pc=0x0c07b390u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c07b392;
P_0c07b392: /* original f437, guest PC 0x0c07b392 */
if(!s->budget--) { s->failed_pc=0x0c07b392u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07b394;
P_0c07b394: /* original 000b, guest PC 0x0c07b394 */
if(!s->budget--) { s->failed_pc=0x0c07b394u; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c07b396: /* original 7f04, guest PC 0x0c07b396 */
if(!s->budget--) { s->failed_pc=0x0c07b396u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c07b398u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b398u; return 0; } return 1;
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
P_0c0a71ac: /* original 4f22, guest PC 0x0c0a71ac */
if(!s->budget--) { s->failed_pc=0x0c0a71acu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a71ae;
P_0c0a71ae: /* original d31e, guest PC 0x0c0a71ae */
if(!s->budget--) { s->failed_pc=0x0c0a71aeu; return 0; }
r[3]=read(ram,0x0c0a7228u,4);
goto P_0c0a71b0;
P_0c0a71b0: /* original 430b, guest PC 0x0c0a71b0 */
if(!s->budget--) { s->failed_pc=0x0c0a71b0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a71b4u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a71b4u) { target=s->pc; goto dispatch; }
goto P_0c0a71b4;
P_0c0a71b2: /* original e400, guest PC 0x0c0a71b2 */
if(!s->budget--) { s->failed_pc=0x0c0a71b2u; return 0; }
r[4]=0x00000000u;
goto P_0c0a71b4;
P_0c0a71b4: /* original d31d, guest PC 0x0c0a71b4 */
if(!s->budget--) { s->failed_pc=0x0c0a71b4u; return 0; }
r[3]=read(ram,0x0c0a722cu,4);
goto P_0c0a71b6;
P_0c0a71b6: /* original d21e, guest PC 0x0c0a71b6 */
if(!s->budget--) { s->failed_pc=0x0c0a71b6u; return 0; }
r[2]=read(ram,0x0c0a7230u,4);
goto P_0c0a71b8;
P_0c0a71b8: /* original 6132, guest PC 0x0c0a71b8 */
if(!s->budget--) { s->failed_pc=0x0c0a71b8u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0a71ba;
P_0c0a71ba: /* original 212b, guest PC 0x0c0a71ba */
if(!s->budget--) { s->failed_pc=0x0c0a71bau; return 0; }
r[1]|=r[2];
goto P_0c0a71bc;
P_0c0a71bc: /* original 2312, guest PC 0x0c0a71bc */
if(!s->budget--) { s->failed_pc=0x0c0a71bcu; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0a71be;
P_0c0a71be: /* original d31e, guest PC 0x0c0a71be */
if(!s->budget--) { s->failed_pc=0x0c0a71beu; return 0; }
r[3]=read(ram,0x0c0a7238u,4);
goto P_0c0a71c0;
P_0c0a71c0: /* original d41c, guest PC 0x0c0a71c0 */
if(!s->budget--) { s->failed_pc=0x0c0a71c0u; return 0; }
r[4]=read(ram,0x0c0a7234u,4);
goto P_0c0a71c2;
P_0c0a71c2: /* original 430b, guest PC 0x0c0a71c2 */
if(!s->budget--) { s->failed_pc=0x0c0a71c2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a71c6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a71c6u) { target=s->pc; goto dispatch; }
goto P_0c0a71c6;
P_0c0a71c4: /* original 0009, guest PC 0x0c0a71c4 */
if(!s->budget--) { s->failed_pc=0x0c0a71c4u; return 0; }
goto P_0c0a71c6;
P_0c0a71c6: /* original d21d, guest PC 0x0c0a71c6 */
if(!s->budget--) { s->failed_pc=0x0c0a71c6u; return 0; }
r[2]=read(ram,0x0c0a723cu,4);
goto P_0c0a71c8;
P_0c0a71c8: /* original 420b, guest PC 0x0c0a71c8 */
if(!s->budget--) { s->failed_pc=0x0c0a71c8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a71ccu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a71ccu) { target=s->pc; goto dispatch; }
goto P_0c0a71cc;
P_0c0a71ca: /* original 0009, guest PC 0x0c0a71ca */
if(!s->budget--) { s->failed_pc=0x0c0a71cau; return 0; }
goto P_0c0a71cc;
P_0c0a71cc: /* original d31c, guest PC 0x0c0a71cc */
if(!s->budget--) { s->failed_pc=0x0c0a71ccu; return 0; }
r[3]=read(ram,0x0c0a7240u,4);
goto P_0c0a71ce;
P_0c0a71ce: /* original e401, guest PC 0x0c0a71ce */
if(!s->budget--) { s->failed_pc=0x0c0a71ceu; return 0; }
r[4]=0x00000001u;
goto P_0c0a71d0;
P_0c0a71d0: /* original 432b, guest PC 0x0c0a71d0 */
if(!s->budget--) { s->failed_pc=0x0c0a71d0u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c0a71d2: /* original 4f26, guest PC 0x0c0a71d2 */
if(!s->budget--) { s->failed_pc=0x0c0a71d2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c0a71d4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a71d4u; return 0; } return 1;
P_0c0a7204: /* original d509, guest PC 0x0c0a7204 */
if(!s->budget--) { s->failed_pc=0x0c0a7204u; return 0; }
r[5]=read(ram,0x0c0a722cu,4);
goto P_0c0a7206;
P_0c0a7206: /* original d30f, guest PC 0x0c0a7206 */
if(!s->budget--) { s->failed_pc=0x0c0a7206u; return 0; }
r[3]=read(ram,0x0c0a7244u,4);
goto P_0c0a7208;
P_0c0a7208: /* original 6252, guest PC 0x0c0a7208 */
if(!s->budget--) { s->failed_pc=0x0c0a7208u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c0a720a;
P_0c0a720a: /* original 223b, guest PC 0x0c0a720a */
if(!s->budget--) { s->failed_pc=0x0c0a720au; return 0; }
r[2]|=r[3];
goto P_0c0a720c;
P_0c0a720c: /* original 2522, guest PC 0x0c0a720c */
if(!s->budget--) { s->failed_pc=0x0c0a720cu; return 0; }
write(ram,r[5],r[2],4);
goto P_0c0a720e;
P_0c0a720e: /* original 6152, guest PC 0x0c0a720e */
if(!s->budget--) { s->failed_pc=0x0c0a720eu; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c0a7210;
P_0c0a7210: /* original d20d, guest PC 0x0c0a7210 */
if(!s->budget--) { s->failed_pc=0x0c0a7210u; return 0; }
r[2]=read(ram,0x0c0a7248u,4);
goto P_0c0a7212;
P_0c0a7212: /* original 2129, guest PC 0x0c0a7212 */
if(!s->budget--) { s->failed_pc=0x0c0a7212u; return 0; }
r[1]&=r[2];
goto P_0c0a7214;
P_0c0a7214: /* original 2512, guest PC 0x0c0a7214 */
if(!s->budget--) { s->failed_pc=0x0c0a7214u; return 0; }
write(ram,r[5],r[1],4);
goto P_0c0a7216;
P_0c0a7216: /* original 000b, guest PC 0x0c0a7216 */
if(!s->budget--) { s->failed_pc=0x0c0a7216u; return 0; }
target=r[16];
write(ram,r[5]+24,r[4],4);
s->pc=target; return ram->oob==0;
P_0c0a7218: /* original 1546, guest PC 0x0c0a7218 */
if(!s->budget--) { s->failed_pc=0x0c0a7218u; return 0; }
write(ram,r[5]+24,r[4],4);
if(!vf3_matrix_family(0x0c0a721au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a721au; return 0; } return 1;
P_0c0a7250: /* original 4615, guest PC 0x0c0a7250 */
if(!s->budget--) { s->failed_pc=0x0c0a7250u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c0a7252;
P_0c0a7252: /* original 8b05, guest PC 0x0c0a7252 */
if(!s->budget--) { s->failed_pc=0x0c0a7252u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7260; }
goto P_0c0a7254;
P_0c0a7254: /* original 6756, guest PC 0x0c0a7254 */
if(!s->budget--) { s->failed_pc=0x0c0a7254u; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[7]=tmp;
goto P_0c0a7256;
P_0c0a7256: /* original 76ff, guest PC 0x0c0a7256 */
if(!s->budget--) { s->failed_pc=0x0c0a7256u; return 0; }
r[6]+=0xffffffffu;
goto P_0c0a7258;
P_0c0a7258: /* original 4615, guest PC 0x0c0a7258 */
if(!s->budget--) { s->failed_pc=0x0c0a7258u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c0a725a;
P_0c0a725a: /* original 2472, guest PC 0x0c0a725a */
if(!s->budget--) { s->failed_pc=0x0c0a725au; return 0; }
write(ram,r[4],r[7],4);
goto P_0c0a725c;
P_0c0a725c: /* original 8dfa, guest PC 0x0c0a725c */
if(!s->budget--) { s->failed_pc=0x0c0a725cu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(cond) { goto P_0c0a7254; }
goto P_0c0a7260;
P_0c0a725e: /* original 7404, guest PC 0x0c0a725e */
if(!s->budget--) { s->failed_pc=0x0c0a725eu; return 0; }
r[4]+=0x00000004u;
goto P_0c0a7260;
P_0c0a7260: /* original 000b, guest PC 0x0c0a7260 */
if(!s->budget--) { s->failed_pc=0x0c0a7260u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a7262: /* original 0009, guest PC 0x0c0a7262 */
if(!s->budget--) { s->failed_pc=0x0c0a7262u; return 0; }
if(!vf3_matrix_family(0x0c0a7264u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7264u; return 0; } return 1;
P_0c0a7442: /* original d024, guest PC 0x0c0a7442 */
if(!s->budget--) { s->failed_pc=0x0c0a7442u; return 0; }
r[0]=read(ram,0x0c0a74d4u,4);
goto P_0c0a7444;
P_0c0a7444: /* original 7ffc, guest PC 0x0c0a7444 */
if(!s->budget--) { s->failed_pc=0x0c0a7444u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a7446;
P_0c0a7446: /* original e635, guest PC 0x0c0a7446 */
if(!s->budget--) { s->failed_pc=0x0c0a7446u; return 0; }
r[6]=0x00000035u;
goto P_0c0a7448;
P_0c0a7448: /* original 6503, guest PC 0x0c0a7448 */
if(!s->budget--) { s->failed_pc=0x0c0a7448u; return 0; }
r[5]=r[0];
goto P_0c0a744a;
P_0c0a744a: /* original 2f02, guest PC 0x0c0a744a */
if(!s->budget--) { s->failed_pc=0x0c0a744au; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0a744c;
P_0c0a744c: /* original af00, guest PC 0x0c0a744c */
if(!s->budget--) { s->failed_pc=0x0c0a744cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0a7250;
P_0c0a744e: /* original 7f04, guest PC 0x0c0a744e */
if(!s->budget--) { s->failed_pc=0x0c0a744eu; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c0a7450u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7450u; return 0; } return 1;
P_0c0a7662: /* original 2fe6, guest PC 0x0c0a7662 */
if(!s->budget--) { s->failed_pc=0x0c0a7662u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7664;
P_0c0a7664: /* original 932b, guest PC 0x0c0a7664 */
if(!s->budget--) { s->failed_pc=0x0c0a7664u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a76beu,2);
goto P_0c0a7666;
P_0c0a7666: /* original 4f22, guest PC 0x0c0a7666 */
if(!s->budget--) { s->failed_pc=0x0c0a7666u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7668;
P_0c0a7668: /* original 3433, guest PC 0x0c0a7668 */
if(!s->budget--) { s->failed_pc=0x0c0a7668u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0a766a;
P_0c0a766a: /* original 8925, guest PC 0x0c0a766a */
if(!s->budget--) { s->failed_pc=0x0c0a766au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a766c;
P_0c0a766c: /* original d014, guest PC 0x0c0a766c */
if(!s->budget--) { s->failed_pc=0x0c0a766cu; return 0; }
r[0]=read(ram,0x0c0a76c0u,4);
goto P_0c0a766e;
P_0c0a766e: /* original 6e43, guest PC 0x0c0a766e */
if(!s->budget--) { s->failed_pc=0x0c0a766eu; return 0; }
r[14]=r[4];
goto P_0c0a7670;
P_0c0a7670: /* original 4e08, guest PC 0x0c0a7670 */
if(!s->budget--) { s->failed_pc=0x0c0a7670u; return 0; }
r[14]<<=2;
goto P_0c0a7672;
P_0c0a7672: /* original 0eee, guest PC 0x0c0a7672 */
if(!s->budget--) { s->failed_pc=0x0c0a7672u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c0a7674;
P_0c0a7674: /* original 2ee8, guest PC 0x0c0a7674 */
if(!s->budget--) { s->failed_pc=0x0c0a7674u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a7676;
P_0c0a7676: /* original 891f, guest PC 0x0c0a7676 */
if(!s->budget--) { s->failed_pc=0x0c0a7676u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a7678;
P_0c0a7678: /* original 60e3, guest PC 0x0c0a7678 */
if(!s->budget--) { s->failed_pc=0x0c0a7678u; return 0; }
r[0]=r[14];
goto P_0c0a767a;
P_0c0a767a: /* original 88ff, guest PC 0x0c0a767a */
if(!s->budget--) { s->failed_pc=0x0c0a767au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0a767c;
P_0c0a767c: /* original 891c, guest PC 0x0c0a767c */
if(!s->budget--) { s->failed_pc=0x0c0a767cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a767e;
P_0c0a767e: /* original d311, guest PC 0x0c0a767e */
if(!s->budget--) { s->failed_pc=0x0c0a767eu; return 0; }
r[3]=read(ram,0x0c0a76c4u,4);
goto P_0c0a7680;
P_0c0a7680: /* original 430b, guest PC 0x0c0a7680 */
if(!s->budget--) { s->failed_pc=0x0c0a7680u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7684u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7684u) { target=s->pc; goto dispatch; }
goto P_0c0a7684;
P_0c0a7682: /* original e400, guest PC 0x0c0a7682 */
if(!s->budget--) { s->failed_pc=0x0c0a7682u; return 0; }
r[4]=0x00000000u;
goto P_0c0a7684;
P_0c0a7684: /* original d211, guest PC 0x0c0a7684 */
if(!s->budget--) { s->failed_pc=0x0c0a7684u; return 0; }
r[2]=read(ram,0x0c0a76ccu,4);
goto P_0c0a7686;
P_0c0a7686: /* original d410, guest PC 0x0c0a7686 */
if(!s->budget--) { s->failed_pc=0x0c0a7686u; return 0; }
r[4]=read(ram,0x0c0a76c8u,4);
goto P_0c0a7688;
P_0c0a7688: /* original 420b, guest PC 0x0c0a7688 */
if(!s->budget--) { s->failed_pc=0x0c0a7688u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a768cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a768cu) { target=s->pc; goto dispatch; }
goto P_0c0a768c;
P_0c0a768a: /* original 0009, guest PC 0x0c0a768a */
if(!s->budget--) { s->failed_pc=0x0c0a768au; return 0; }
goto P_0c0a768c;
P_0c0a768c: /* original 50e1, guest PC 0x0c0a768c */
if(!s->budget--) { s->failed_pc=0x0c0a768cu; return 0; }
r[0]=read(ram,r[14]+4,4);
goto P_0c0a768e;
P_0c0a768e: /* original c801, guest PC 0x0c0a768e */
if(!s->budget--) { s->failed_pc=0x0c0a768eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a7690;
P_0c0a7690: /* original 8904, guest PC 0x0c0a7690 */
if(!s->budget--) { s->failed_pc=0x0c0a7690u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a769c; }
goto P_0c0a7692;
P_0c0a7692: /* original d213, guest PC 0x0c0a7692 */
if(!s->budget--) { s->failed_pc=0x0c0a7692u; return 0; }
r[2]=read(ram,0x0c0a76e0u,4);
goto P_0c0a7694;
P_0c0a7694: /* original 420b, guest PC 0x0c0a7694 */
if(!s->budget--) { s->failed_pc=0x0c0a7694u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7698u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7698u) { target=s->pc; goto dispatch; }
goto P_0c0a7698;
P_0c0a7696: /* original 64e3, guest PC 0x0c0a7696 */
if(!s->budget--) { s->failed_pc=0x0c0a7696u; return 0; }
r[4]=r[14];
goto P_0c0a7698;
P_0c0a7698: /* original a009, guest PC 0x0c0a7698 */
if(!s->budget--) { s->failed_pc=0x0c0a7698u; return 0; }
goto P_0c0a76ae;
P_0c0a769a: /* original 0009, guest PC 0x0c0a769a */
if(!s->budget--) { s->failed_pc=0x0c0a769au; return 0; }
goto P_0c0a769c;
P_0c0a769c: /* original d20d, guest PC 0x0c0a769c */
if(!s->budget--) { s->failed_pc=0x0c0a769cu; return 0; }
r[2]=read(ram,0x0c0a76d4u,4);
goto P_0c0a769e;
P_0c0a769e: /* original 420b, guest PC 0x0c0a769e */
if(!s->budget--) { s->failed_pc=0x0c0a769eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a76a2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a76a2u) { target=s->pc; goto dispatch; }
goto P_0c0a76a2;
P_0c0a76a0: /* original 0009, guest PC 0x0c0a76a0 */
if(!s->budget--) { s->failed_pc=0x0c0a76a0u; return 0; }
goto P_0c0a76a2;
P_0c0a76a2: /* original d310, guest PC 0x0c0a76a2 */
if(!s->budget--) { s->failed_pc=0x0c0a76a2u; return 0; }
r[3]=read(ram,0x0c0a76e4u,4);
goto P_0c0a76a4;
P_0c0a76a4: /* original 23e8, guest PC 0x0c0a76a4 */
if(!s->budget--) { s->failed_pc=0x0c0a76a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c0a76a6;
P_0c0a76a6: /* original 8902, guest PC 0x0c0a76a6 */
if(!s->budget--) { s->failed_pc=0x0c0a76a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76ae; }
goto P_0c0a76a8;
P_0c0a76a8: /* original d30f, guest PC 0x0c0a76a8 */
if(!s->budget--) { s->failed_pc=0x0c0a76a8u; return 0; }
r[3]=read(ram,0x0c0a76e8u,4);
goto P_0c0a76aa;
P_0c0a76aa: /* original 430b, guest PC 0x0c0a76aa */
if(!s->budget--) { s->failed_pc=0x0c0a76aau; return 0; }
target=r[3];
r[16]=code_base|0x0c0a76aeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a76aeu) { target=s->pc; goto dispatch; }
goto P_0c0a76ae;
P_0c0a76ac: /* original 64e3, guest PC 0x0c0a76ac */
if(!s->budget--) { s->failed_pc=0x0c0a76acu; return 0; }
r[4]=r[14];
goto P_0c0a76ae;
P_0c0a76ae: /* original 4f26, guest PC 0x0c0a76ae */
if(!s->budget--) { s->failed_pc=0x0c0a76aeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a76b0;
P_0c0a76b0: /* original d30a, guest PC 0x0c0a76b0 */
if(!s->budget--) { s->failed_pc=0x0c0a76b0u; return 0; }
r[3]=read(ram,0x0c0a76dcu,4);
goto P_0c0a76b2;
P_0c0a76b2: /* original e401, guest PC 0x0c0a76b2 */
if(!s->budget--) { s->failed_pc=0x0c0a76b2u; return 0; }
r[4]=0x00000001u;
goto P_0c0a76b4;
P_0c0a76b4: /* original 432b, guest PC 0x0c0a76b4 */
if(!s->budget--) { s->failed_pc=0x0c0a76b4u; return 0; }
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
P_0c0a76b6: /* original 6ef6, guest PC 0x0c0a76b6 */
if(!s->budget--) { s->failed_pc=0x0c0a76b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a76b8;
P_0c0a76b8: /* original 4f26, guest PC 0x0c0a76b8 */
if(!s->budget--) { s->failed_pc=0x0c0a76b8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a76ba;
P_0c0a76ba: /* original 000b, guest PC 0x0c0a76ba */
if(!s->budget--) { s->failed_pc=0x0c0a76bau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a76bc: /* original 6ef6, guest PC 0x0c0a76bc */
if(!s->budget--) { s->failed_pc=0x0c0a76bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a76beu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a76beu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
