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
int vf3_away_batch48_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042790u: goto P_0c042790;
case 0x0c042792u: goto P_0c042792;
case 0x0c042794u: goto P_0c042794;
case 0x0c042796u: goto P_0c042796;
case 0x0c042798u: goto P_0c042798;
case 0x0c04279au: goto P_0c04279a;
case 0x0c04279cu: goto P_0c04279c;
case 0x0c04279eu: goto P_0c04279e;
case 0x0c0427a0u: goto P_0c0427a0;
case 0x0c0427a2u: goto P_0c0427a2;
case 0x0c0427b0u: goto P_0c0427b0;
case 0x0c0427b2u: goto P_0c0427b2;
case 0x0c0427b4u: goto P_0c0427b4;
case 0x0c0427b6u: goto P_0c0427b6;
case 0x0c0427b8u: goto P_0c0427b8;
case 0x0c0427bau: goto P_0c0427ba;
case 0x0c0427bcu: goto P_0c0427bc;
case 0x0c0427beu: goto P_0c0427be;
case 0x0c0427c0u: goto P_0c0427c0;
case 0x0c0427c2u: goto P_0c0427c2;
case 0x0c0427c4u: goto P_0c0427c4;
case 0x0c0427c6u: goto P_0c0427c6;
case 0x0c0427c8u: goto P_0c0427c8;
case 0x0c0427d0u: goto P_0c0427d0;
case 0x0c0427d2u: goto P_0c0427d2;
case 0x0c0427d4u: goto P_0c0427d4;
case 0x0c0427d6u: goto P_0c0427d6;
case 0x0c0427e0u: goto P_0c0427e0;
case 0x0c0427e2u: goto P_0c0427e2;
case 0x0c0427e4u: goto P_0c0427e4;
case 0x0c0427e6u: goto P_0c0427e6;
case 0x0c0427e8u: goto P_0c0427e8;
case 0x0c0427eau: goto P_0c0427ea;
case 0x0c0427ecu: goto P_0c0427ec;
case 0x0c0427eeu: goto P_0c0427ee;
case 0x0c0427f0u: goto P_0c0427f0;
case 0x0c042800u: goto P_0c042800;
case 0x0c042802u: goto P_0c042802;
case 0x0c042804u: goto P_0c042804;
case 0x0c042806u: goto P_0c042806;
case 0x0c042810u: goto P_0c042810;
case 0x0c042812u: goto P_0c042812;
case 0x0c042814u: goto P_0c042814;
case 0x0c042816u: goto P_0c042816;
case 0x0c042818u: goto P_0c042818;
case 0x0c04281au: goto P_0c04281a;
case 0x0c04281cu: goto P_0c04281c;
case 0x0c04281eu: goto P_0c04281e;
case 0x0c042820u: goto P_0c042820;
case 0x0c042822u: goto P_0c042822;
case 0x0c042824u: goto P_0c042824;
case 0x0c042840u: goto P_0c042840;
case 0x0c042842u: goto P_0c042842;
case 0x0c042844u: goto P_0c042844;
case 0x0c042846u: goto P_0c042846;
case 0x0c042848u: goto P_0c042848;
case 0x0c04284au: goto P_0c04284a;
case 0x0c04284cu: goto P_0c04284c;
case 0x0c04284eu: goto P_0c04284e;
case 0x0c042850u: goto P_0c042850;
case 0x0c042852u: goto P_0c042852;
case 0x0c042854u: goto P_0c042854;
case 0x0c042856u: goto P_0c042856;
case 0x0c042858u: goto P_0c042858;
case 0x0c04285au: goto P_0c04285a;
case 0x0c04285cu: goto P_0c04285c;
case 0x0c04285eu: goto P_0c04285e;
case 0x0c042860u: goto P_0c042860;
case 0x0c042862u: goto P_0c042862;
case 0x0c042864u: goto P_0c042864;
case 0x0c042866u: goto P_0c042866;
case 0x0c042868u: goto P_0c042868;
case 0x0c04286au: goto P_0c04286a;
case 0x0c04286cu: goto P_0c04286c;
case 0x0c04286eu: goto P_0c04286e;
case 0x0c042870u: goto P_0c042870;
case 0x0c042872u: goto P_0c042872;
case 0x0c042874u: goto P_0c042874;
case 0x0c042876u: goto P_0c042876;
case 0x0c042878u: goto P_0c042878;
case 0x0c04287au: goto P_0c04287a;
case 0x0c04287cu: goto P_0c04287c;
case 0x0c042880u: goto P_0c042880;
case 0x0c042882u: goto P_0c042882;
case 0x0c042884u: goto P_0c042884;
case 0x0c042886u: goto P_0c042886;
case 0x0c042888u: goto P_0c042888;
case 0x0c04288au: goto P_0c04288a;
case 0x0c04288cu: goto P_0c04288c;
case 0x0c04288eu: goto P_0c04288e;
case 0x0c042890u: goto P_0c042890;
case 0x0c042892u: goto P_0c042892;
case 0x0c042894u: goto P_0c042894;
case 0x0c042896u: goto P_0c042896;
case 0x0c042898u: goto P_0c042898;
case 0x0c04289au: goto P_0c04289a;
case 0x0c04289cu: goto P_0c04289c;
case 0x0c04289eu: goto P_0c04289e;
case 0x0c0428a0u: goto P_0c0428a0;
case 0x0c0428a2u: goto P_0c0428a2;
case 0x0c0428a4u: goto P_0c0428a4;
case 0x0c0428a6u: goto P_0c0428a6;
case 0x0c0428a8u: goto P_0c0428a8;
case 0x0c0428aau: goto P_0c0428aa;
case 0x0c0428acu: goto P_0c0428ac;
case 0x0c0428aeu: goto P_0c0428ae;
case 0x0c0428b0u: goto P_0c0428b0;
case 0x0c0428b2u: goto P_0c0428b2;
case 0x0c0428b4u: goto P_0c0428b4;
case 0x0c0428b6u: goto P_0c0428b6;
case 0x0c0428b8u: goto P_0c0428b8;
case 0x0c0428bau: goto P_0c0428ba;
case 0x0c0428bcu: goto P_0c0428bc;
case 0x0c0428beu: goto P_0c0428be;
case 0x0c0428c0u: goto P_0c0428c0;
case 0x0c0428d0u: goto P_0c0428d0;
case 0x0c0428d2u: goto P_0c0428d2;
case 0x0c0428d4u: goto P_0c0428d4;
case 0x0c0428d6u: goto P_0c0428d6;
case 0x0c0428d8u: goto P_0c0428d8;
case 0x0c0428dau: goto P_0c0428da;
case 0x0c0428dcu: goto P_0c0428dc;
case 0x0c0428deu: goto P_0c0428de;
case 0x0c0428e0u: goto P_0c0428e0;
case 0x0c0428e2u: goto P_0c0428e2;
case 0x0c0428e4u: goto P_0c0428e4;
case 0x0c0428e6u: goto P_0c0428e6;
case 0x0c0428e8u: goto P_0c0428e8;
case 0x0c0428eau: goto P_0c0428ea;
case 0x0c0428ecu: goto P_0c0428ec;
case 0x0c0428eeu: goto P_0c0428ee;
case 0x0c0428f0u: goto P_0c0428f0;
case 0x0c0428f2u: goto P_0c0428f2;
case 0x0c042900u: goto P_0c042900;
case 0x0c042902u: goto P_0c042902;
case 0x0c042904u: goto P_0c042904;
case 0x0c042906u: goto P_0c042906;
case 0x0c042908u: goto P_0c042908;
case 0x0c04290au: goto P_0c04290a;
case 0x0c04290cu: goto P_0c04290c;
case 0x0c04290eu: goto P_0c04290e;
case 0x0c042910u: goto P_0c042910;
case 0x0c042912u: goto P_0c042912;
case 0x0c042914u: goto P_0c042914;
case 0x0c042930u: goto P_0c042930;
case 0x0c042932u: goto P_0c042932;
case 0x0c042934u: goto P_0c042934;
case 0x0c042936u: goto P_0c042936;
case 0x0c042938u: goto P_0c042938;
case 0x0c04293au: goto P_0c04293a;
case 0x0c04293cu: goto P_0c04293c;
case 0x0c04293eu: goto P_0c04293e;
case 0x0c042940u: goto P_0c042940;
case 0x0c042942u: goto P_0c042942;
case 0x0c042944u: goto P_0c042944;
case 0x0c042946u: goto P_0c042946;
case 0x0c042948u: goto P_0c042948;
case 0x0c04294au: goto P_0c04294a;
case 0x0c042950u: goto P_0c042950;
case 0x0c042952u: goto P_0c042952;
case 0x0c042954u: goto P_0c042954;
case 0x0c042960u: goto P_0c042960;
case 0x0c042962u: goto P_0c042962;
case 0x0c042964u: goto P_0c042964;
case 0x0c042970u: goto P_0c042970;
case 0x0c042972u: goto P_0c042972;
case 0x0c042974u: goto P_0c042974;
case 0x0c0429b0u: goto P_0c0429b0;
case 0x0c0429b2u: goto P_0c0429b2;
case 0x0c0429b4u: goto P_0c0429b4;
case 0x0c0429b6u: goto P_0c0429b6;
case 0x0c0429b8u: goto P_0c0429b8;
case 0x0c0429bau: goto P_0c0429ba;
case 0x0c0429bcu: goto P_0c0429bc;
case 0x0c0429beu: goto P_0c0429be;
case 0x0c0429c0u: goto P_0c0429c0;
case 0x0c0429c2u: goto P_0c0429c2;
case 0x0c0429c4u: goto P_0c0429c4;
case 0x0c0429c6u: goto P_0c0429c6;
case 0x0c0429c8u: goto P_0c0429c8;
case 0x0c0429cau: goto P_0c0429ca;
case 0x0c0429ccu: goto P_0c0429cc;
case 0x0c0429ceu: goto P_0c0429ce;
case 0x0c0429d0u: goto P_0c0429d0;
case 0x0c0429d2u: goto P_0c0429d2;
case 0x0c0429d4u: goto P_0c0429d4;
case 0x0c0429d6u: goto P_0c0429d6;
case 0x0c0429d8u: goto P_0c0429d8;
case 0x0c0429dau: goto P_0c0429da;
case 0x0c0429dcu: goto P_0c0429dc;
case 0x0c0429deu: goto P_0c0429de;
case 0x0c0429e0u: goto P_0c0429e0;
case 0x0c0429e2u: goto P_0c0429e2;
case 0x0c0429e4u: goto P_0c0429e4;
case 0x0c0429e6u: goto P_0c0429e6;
case 0x0c0429e8u: goto P_0c0429e8;
case 0x0c0429eau: goto P_0c0429ea;
case 0x0c0429ecu: goto P_0c0429ec;
case 0x0c0429eeu: goto P_0c0429ee;
case 0x0c0429f0u: goto P_0c0429f0;
case 0x0c0429f2u: goto P_0c0429f2;
case 0x0c0429f4u: goto P_0c0429f4;
case 0x0c0429f6u: goto P_0c0429f6;
case 0x0c0429f8u: goto P_0c0429f8;
case 0x0c0429fau: goto P_0c0429fa;
case 0x0c0429fcu: goto P_0c0429fc;
case 0x0c0429feu: goto P_0c0429fe;
case 0x0c042a00u: goto P_0c042a00;
case 0x0c042a02u: goto P_0c042a02;
case 0x0c042a04u: goto P_0c042a04;
case 0x0c042a06u: goto P_0c042a06;
case 0x0c042a08u: goto P_0c042a08;
case 0x0c042a0au: goto P_0c042a0a;
case 0x0c042a0cu: goto P_0c042a0c;
case 0x0c042a0eu: goto P_0c042a0e;
case 0x0c042a10u: goto P_0c042a10;
case 0x0c042a12u: goto P_0c042a12;
case 0x0c042a14u: goto P_0c042a14;
case 0x0c042a16u: goto P_0c042a16;
case 0x0c042a18u: goto P_0c042a18;
case 0x0c042a1au: goto P_0c042a1a;
case 0x0c042a1cu: goto P_0c042a1c;
case 0x0c042a1eu: goto P_0c042a1e;
case 0x0c042a20u: goto P_0c042a20;
case 0x0c042a22u: goto P_0c042a22;
case 0x0c042a24u: goto P_0c042a24;
case 0x0c042a26u: goto P_0c042a26;
case 0x0c042a28u: goto P_0c042a28;
case 0x0c042a2au: goto P_0c042a2a;
case 0x0c042a2cu: goto P_0c042a2c;
case 0x0c042a2eu: goto P_0c042a2e;
case 0x0c042a30u: goto P_0c042a30;
case 0x0c042a32u: goto P_0c042a32;
case 0x0c042a34u: goto P_0c042a34;
case 0x0c042a36u: goto P_0c042a36;
case 0x0c042a38u: goto P_0c042a38;
case 0x0c042a3au: goto P_0c042a3a;
case 0x0c042a3cu: goto P_0c042a3c;
case 0x0c042a3eu: goto P_0c042a3e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c042790: /* original 2fe6, guest PC 0x0c042790 */
if(!s->budget--) { s->failed_pc=0x0c042790u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042792;
P_0c042792: /* original 2fd6, guest PC 0x0c042792 */
if(!s->budget--) { s->failed_pc=0x0c042792u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042794;
P_0c042794: /* original 2fc6, guest PC 0x0c042794 */
if(!s->budget--) { s->failed_pc=0x0c042794u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042796;
P_0c042796: /* original 2fb6, guest PC 0x0c042796 */
if(!s->budget--) { s->failed_pc=0x0c042796u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042798;
P_0c042798: /* original 2fa6, guest PC 0x0c042798 */
if(!s->budget--) { s->failed_pc=0x0c042798u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04279a;
P_0c04279a: /* original 2f96, guest PC 0x0c04279a */
if(!s->budget--) { s->failed_pc=0x0c04279au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04279c;
P_0c04279c: /* original 4f22, guest PC 0x0c04279c */
if(!s->budget--) { s->failed_pc=0x0c04279cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04279e;
P_0c04279e: /* original 4f12, guest PC 0x0c04279e */
if(!s->budget--) { s->failed_pc=0x0c04279eu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0427a0;
P_0c0427a0: /* original a099, guest PC 0x0c0427a0 */
if(!s->budget--) { s->failed_pc=0x0c0427a0u; return 0; }
r[13]=r[4];
goto P_0c0428d6;
P_0c0427a2: /* original 6d43, guest PC 0x0c0427a2 */
if(!s->budget--) { s->failed_pc=0x0c0427a2u; return 0; }
r[13]=r[4];
if(!vf3_matrix_family(0x0c0427a4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0427a4u; return 0; } return 1;
P_0c0427b0: /* original d41e, guest PC 0x0c0427b0 */
if(!s->budget--) { s->failed_pc=0x0c0427b0u; return 0; }
r[4]=read(ram,0x0c04282cu,4);
goto P_0c0427b2;
P_0c0427b2: /* original d61f, guest PC 0x0c0427b2 */
if(!s->budget--) { s->failed_pc=0x0c0427b2u; return 0; }
r[6]=read(ram,0x0c042830u,4);
goto P_0c0427b4;
P_0c0427b4: /* original 60e3, guest PC 0x0c0427b4 */
if(!s->budget--) { s->failed_pc=0x0c0427b4u; return 0; }
r[0]=r[14];
goto P_0c0427b6;
P_0c0427b6: /* original 0009, guest PC 0x0c0427b6 */
if(!s->budget--) { s->failed_pc=0x0c0427b6u; return 0; }
goto P_0c0427b8;
P_0c0427b8: /* original 880a, guest PC 0x0c0427b8 */
if(!s->budget--) { s->failed_pc=0x0c0427b8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c0427ba;
P_0c0427ba: /* original 8f09, guest PC 0x0c0427ba */
if(!s->budget--) { s->failed_pc=0x0c0427bau; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[6],4);
r[5]=tmp;
if(!cond) { goto P_0c0427d0; }
goto P_0c0427be;
P_0c0427bc: /* original 6562, guest PC 0x0c0427bc */
if(!s->budget--) { s->failed_pc=0x0c0427bcu; return 0; }
tmp=read(ram,r[6],4);
r[5]=tmp;
goto P_0c0427be;
P_0c0427be: /* original 2452, guest PC 0x0c0427be */
if(!s->budget--) { s->failed_pc=0x0c0427beu; return 0; }
write(ram,r[4],r[5],4);
goto P_0c0427c0;
P_0c0427c0: /* original d41c, guest PC 0x0c0427c0 */
if(!s->budget--) { s->failed_pc=0x0c0427c0u; return 0; }
r[4]=read(ram,0x0c042834u,4);
goto P_0c0427c2;
P_0c0427c2: /* original 6342, guest PC 0x0c0427c2 */
if(!s->budget--) { s->failed_pc=0x0c0427c2u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0427c4;
P_0c0427c4: /* original 7318, guest PC 0x0c0427c4 */
if(!s->budget--) { s->failed_pc=0x0c0427c4u; return 0; }
r[3]+=0x00000018u;
goto P_0c0427c6;
P_0c0427c6: /* original a086, guest PC 0x0c0427c6 */
if(!s->budget--) { s->failed_pc=0x0c0427c6u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c0428d6;
P_0c0427c8: /* original 2432, guest PC 0x0c0427c8 */
if(!s->budget--) { s->failed_pc=0x0c0427c8u; return 0; }
write(ram,r[4],r[3],4);
if(!vf3_matrix_family(0x0c0427cau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0427cau; return 0; } return 1;
P_0c0427d0: /* original 880d, guest PC 0x0c0427d0 */
if(!s->budget--) { s->failed_pc=0x0c0427d0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0427d2;
P_0c0427d2: /* original 8b05, guest PC 0x0c0427d2 */
if(!s->budget--) { s->failed_pc=0x0c0427d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0427e0; }
goto P_0c0427d4;
P_0c0427d4: /* original a07f, guest PC 0x0c0427d4 */
if(!s->budget--) { s->failed_pc=0x0c0427d4u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c0428d6;
P_0c0427d6: /* original 2452, guest PC 0x0c0427d6 */
if(!s->budget--) { s->failed_pc=0x0c0427d6u; return 0; }
write(ram,r[4],r[5],4);
if(!vf3_matrix_family(0x0c0427d8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0427d8u; return 0; } return 1;
P_0c0427e0: /* original d515, guest PC 0x0c0427e0 */
if(!s->budget--) { s->failed_pc=0x0c0427e0u; return 0; }
r[5]=read(ram,0x0c042838u,4);
goto P_0c0427e2;
P_0c0427e2: /* original 9420, guest PC 0x0c0427e2 */
if(!s->budget--) { s->failed_pc=0x0c0427e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042826u,2);
goto P_0c0427e4;
P_0c0427e4: /* original 6050, guest PC 0x0c0427e4 */
if(!s->budget--) { s->failed_pc=0x0c0427e4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[0]=tmp;
goto P_0c0427e6;
P_0c0427e6: /* original 8800, guest PC 0x0c0427e6 */
if(!s->budget--) { s->failed_pc=0x0c0427e6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0427e8;
P_0c0427e8: /* original 890a, guest PC 0x0c0427e8 */
if(!s->budget--) { s->failed_pc=0x0c0427e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042800; }
goto P_0c0427ea;
P_0c0427ea: /* original 8801, guest PC 0x0c0427ea */
if(!s->budget--) { s->failed_pc=0x0c0427eau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0427ec;
P_0c0427ec: /* original 8910, guest PC 0x0c0427ec */
if(!s->budget--) { s->failed_pc=0x0c0427ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042810; }
goto P_0c0427ee;
P_0c0427ee: /* original a047, guest PC 0x0c0427ee */
if(!s->budget--) { s->failed_pc=0x0c0427eeu; return 0; }
goto P_0c042880;
P_0c0427f0: /* original 0009, guest PC 0x0c0427f0 */
if(!s->budget--) { s->failed_pc=0x0c0427f0u; return 0; }
if(!vf3_matrix_family(0x0c0427f2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0427f2u; return 0; } return 1;
P_0c042800: /* original bf2e, guest PC 0x0c042800 */
if(!s->budget--) { s->failed_pc=0x0c042800u; return 0; }
target=code_base|0x0c042660u; r[16]=code_base|0x0c042804u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c042804u) { target=s->pc; goto dispatch; }
goto P_0c042804;
P_0c042802: /* original 64e3, guest PC 0x0c042802 */
if(!s->budget--) { s->failed_pc=0x0c042802u; return 0; }
r[4]=r[14];
goto P_0c042804;
P_0c042804: /* original a067, guest PC 0x0c042804 */
if(!s->budget--) { s->failed_pc=0x0c042804u; return 0; }
goto P_0c0428d6;
P_0c042806: /* original 0009, guest PC 0x0c042806 */
if(!s->budget--) { s->failed_pc=0x0c042806u; return 0; }
if(!vf3_matrix_family(0x0c042808u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042808u; return 0; } return 1;
P_0c042810: /* original 3e43, guest PC 0x0c042810 */
if(!s->budget--) { s->failed_pc=0x0c042810u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[4])!=0);
goto P_0c042812;
P_0c042812: /* original 8b5d, guest PC 0x0c042812 */
if(!s->budget--) { s->failed_pc=0x0c042812u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0428d0; }
goto P_0c042814;
P_0c042814: /* original 9408, guest PC 0x0c042814 */
if(!s->budget--) { s->failed_pc=0x0c042814u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042828u,2);
goto P_0c042816;
P_0c042816: /* original 3e40, guest PC 0x0c042816 */
if(!s->budget--) { s->failed_pc=0x0c042816u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[4])!=0);
goto P_0c042818;
P_0c042818: /* original 8b12, guest PC 0x0c042818 */
if(!s->budget--) { s->failed_pc=0x0c042818u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042840; }
goto P_0c04281a;
P_0c04281a: /* original 6ed4, guest PC 0x0c04281a */
if(!s->budget--) { s->failed_pc=0x0c04281au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[13]+=1;
r[14]=tmp;
goto P_0c04281c;
P_0c04281c: /* original 6eec, guest PC 0x0c04281c */
if(!s->budget--) { s->failed_pc=0x0c04281cu; return 0; }
r[14]=r[14]&255u;
goto P_0c04281e;
P_0c04281e: /* original 2ee8, guest PC 0x0c04281e */
if(!s->budget--) { s->failed_pc=0x0c04281eu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c042820;
P_0c042820: /* original 895f, guest PC 0x0c042820 */
if(!s->budget--) { s->failed_pc=0x0c042820u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0428e2; }
goto P_0c042822;
P_0c042822: /* original a055, guest PC 0x0c042822 */
if(!s->budget--) { s->failed_pc=0x0c042822u; return 0; }
goto P_0c0428d0;
P_0c042824: /* original 0009, guest PC 0x0c042824 */
if(!s->budget--) { s->failed_pc=0x0c042824u; return 0; }
if(!vf3_matrix_family(0x0c042826u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042826u; return 0; } return 1;
P_0c042840: /* original 9469, guest PC 0x0c042840 */
if(!s->budget--) { s->failed_pc=0x0c042840u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042916u,2);
goto P_0c042842;
P_0c042842: /* original 3e40, guest PC 0x0c042842 */
if(!s->budget--) { s->failed_pc=0x0c042842u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[4])!=0);
goto P_0c042844;
P_0c042844: /* original 8b0c, guest PC 0x0c042844 */
if(!s->budget--) { s->failed_pc=0x0c042844u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042860; }
goto P_0c042846;
P_0c042846: /* original 64d4, guest PC 0x0c042846 */
if(!s->budget--) { s->failed_pc=0x0c042846u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[13]+=1;
r[4]=tmp;
goto P_0c042848;
P_0c042848: /* original 644c, guest PC 0x0c042848 */
if(!s->budget--) { s->failed_pc=0x0c042848u; return 0; }
r[4]=r[4]&255u;
goto P_0c04284a;
P_0c04284a: /* original 2448, guest PC 0x0c04284a */
if(!s->budget--) { s->failed_pc=0x0c04284au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c04284c;
P_0c04284c: /* original 8949, guest PC 0x0c04284c */
if(!s->budget--) { s->failed_pc=0x0c04284cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0428e2; }
goto P_0c04284e;
P_0c04284e: /* original 64d4, guest PC 0x0c04284e */
if(!s->budget--) { s->failed_pc=0x0c04284eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[13]+=1;
r[4]=tmp;
goto P_0c042850;
P_0c042850: /* original 644c, guest PC 0x0c042850 */
if(!s->budget--) { s->failed_pc=0x0c042850u; return 0; }
r[4]=r[4]&255u;
goto P_0c042852;
P_0c042852: /* original 2448, guest PC 0x0c042852 */
if(!s->budget--) { s->failed_pc=0x0c042852u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c042854;
P_0c042854: /* original 8945, guest PC 0x0c042854 */
if(!s->budget--) { s->failed_pc=0x0c042854u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0428e2; }
goto P_0c042856;
P_0c042856: /* original 9e5f, guest PC 0x0c042856 */
if(!s->budget--) { s->failed_pc=0x0c042856u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042918u,2);
goto P_0c042858;
P_0c042858: /* original bf02, guest PC 0x0c042858 */
if(!s->budget--) { s->failed_pc=0x0c042858u; return 0; }
target=code_base|0x0c042660u; r[16]=code_base|0x0c04285cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04285cu) { target=s->pc; goto dispatch; }
goto P_0c04285c;
P_0c04285a: /* original 64e3, guest PC 0x0c04285a */
if(!s->budget--) { s->failed_pc=0x0c04285au; return 0; }
r[4]=r[14];
goto P_0c04285c;
P_0c04285c: /* original a03b, guest PC 0x0c04285c */
if(!s->budget--) { s->failed_pc=0x0c04285cu; return 0; }
goto P_0c0428d6;
P_0c04285e: /* original 0009, guest PC 0x0c04285e */
if(!s->budget--) { s->failed_pc=0x0c04285eu; return 0; }
goto P_0c042860;
P_0c042860: /* original 6cd4, guest PC 0x0c042860 */
if(!s->budget--) { s->failed_pc=0x0c042860u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[13]+=1;
r[12]=tmp;
goto P_0c042862;
P_0c042862: /* original 6ccc, guest PC 0x0c042862 */
if(!s->budget--) { s->failed_pc=0x0c042862u; return 0; }
r[12]=r[12]&255u;
goto P_0c042864;
P_0c042864: /* original 2cc8, guest PC 0x0c042864 */
if(!s->budget--) { s->failed_pc=0x0c042864u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c042866;
P_0c042866: /* original 893c, guest PC 0x0c042866 */
if(!s->budget--) { s->failed_pc=0x0c042866u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0428e2; }
goto P_0c042868;
P_0c042868: /* original 9b57, guest PC 0x0c042868 */
if(!s->budget--) { s->failed_pc=0x0c042868u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04291au,2);
goto P_0c04286a;
P_0c04286a: /* original 64e3, guest PC 0x0c04286a */
if(!s->budget--) { s->failed_pc=0x0c04286au; return 0; }
r[4]=r[14];
goto P_0c04286c;
P_0c04286c: /* original ea5e, guest PC 0x0c04286c */
if(!s->budget--) { s->failed_pc=0x0c04286cu; return 0; }
r[10]=0x0000005eu;
goto P_0c04286e;
P_0c04286e: /* original 34bc, guest PC 0x0c04286e */
if(!s->budget--) { s->failed_pc=0x0c04286eu; return 0; }
r[4]+=r[11];
goto P_0c042870;
P_0c042870: /* original 04a7, guest PC 0x0c042870 */
if(!s->budget--) { s->failed_pc=0x0c042870u; return 0; }
r[19]=r[4]*r[10];
goto P_0c042872;
P_0c042872: /* original 041a, guest PC 0x0c042872 */
if(!s->budget--) { s->failed_pc=0x0c042872u; return 0; }
r[4]=r[19];
goto P_0c042874;
P_0c042874: /* original 34cc, guest PC 0x0c042874 */
if(!s->budget--) { s->failed_pc=0x0c042874u; return 0; }
r[4]+=r[12];
goto P_0c042876;
P_0c042876: /* original bef3, guest PC 0x0c042876 */
if(!s->budget--) { s->failed_pc=0x0c042876u; return 0; }
target=code_base|0x0c042660u; r[16]=code_base|0x0c04287au;
r[4]+=0x0000005fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04287au) { target=s->pc; goto dispatch; }
goto P_0c04287a;
P_0c042878: /* original 745f, guest PC 0x0c042878 */
if(!s->budget--) { s->failed_pc=0x0c042878u; return 0; }
r[4]+=0x0000005fu;
goto P_0c04287a;
P_0c04287a: /* original a02c, guest PC 0x0c04287a */
if(!s->budget--) { s->failed_pc=0x0c04287au; return 0; }
goto P_0c0428d6;
P_0c04287c: /* original 0009, guest PC 0x0c04287c */
if(!s->budget--) { s->failed_pc=0x0c04287cu; return 0; }
if(!vf3_matrix_family(0x0c04287eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04287eu; return 0; } return 1;
P_0c042880: /* original 954c, guest PC 0x0c042880 */
if(!s->budget--) { s->failed_pc=0x0c042880u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04291cu,2);
goto P_0c042882;
P_0c042882: /* original 3e53, guest PC 0x0c042882 */
if(!s->budget--) { s->failed_pc=0x0c042882u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[5])!=0);
goto P_0c042884;
P_0c042884: /* original 8b02, guest PC 0x0c042884 */
if(!s->budget--) { s->failed_pc=0x0c042884u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04288c; }
goto P_0c042886;
P_0c042886: /* original 924a, guest PC 0x0c042886 */
if(!s->budget--) { s->failed_pc=0x0c042886u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04291eu,2);
goto P_0c042888;
P_0c042888: /* original 3e27, guest PC 0x0c042888 */
if(!s->budget--) { s->failed_pc=0x0c042888u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[2])!=0);
goto P_0c04288a;
P_0c04288a: /* original 8b05, guest PC 0x0c04288a */
if(!s->budget--) { s->failed_pc=0x0c04288au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042898; }
goto P_0c04288c;
P_0c04288c: /* original 9148, guest PC 0x0c04288c */
if(!s->budget--) { s->failed_pc=0x0c04288cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042920u,2);
goto P_0c04288e;
P_0c04288e: /* original 3e13, guest PC 0x0c04288e */
if(!s->budget--) { s->failed_pc=0x0c04288eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[1])!=0);
goto P_0c042890;
P_0c042890: /* original 8b1e, guest PC 0x0c042890 */
if(!s->budget--) { s->failed_pc=0x0c042890u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0428d0; }
goto P_0c042892;
P_0c042892: /* original 9246, guest PC 0x0c042892 */
if(!s->budget--) { s->failed_pc=0x0c042892u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042922u,2);
goto P_0c042894;
P_0c042894: /* original 3e27, guest PC 0x0c042894 */
if(!s->budget--) { s->failed_pc=0x0c042894u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[2])!=0);
goto P_0c042896;
P_0c042896: /* original 891b, guest PC 0x0c042896 */
if(!s->budget--) { s->failed_pc=0x0c042896u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0428d0; }
goto P_0c042898;
P_0c042898: /* original 6cd4, guest PC 0x0c042898 */
if(!s->budget--) { s->failed_pc=0x0c042898u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[13]+=1;
r[12]=tmp;
goto P_0c04289a;
P_0c04289a: /* original 6ccc, guest PC 0x0c04289a */
if(!s->budget--) { s->failed_pc=0x0c04289au; return 0; }
r[12]=r[12]&255u;
goto P_0c04289c;
P_0c04289c: /* original 2cc8, guest PC 0x0c04289c */
if(!s->budget--) { s->failed_pc=0x0c04289cu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c04289e;
P_0c04289e: /* original 8920, guest PC 0x0c04289e */
if(!s->budget--) { s->failed_pc=0x0c04289eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0428e2; }
goto P_0c0428a0;
P_0c0428a0: /* original 953e, guest PC 0x0c0428a0 */
if(!s->budget--) { s->failed_pc=0x0c0428a0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042920u,2);
goto P_0c0428a2;
P_0c0428a2: /* original 3e53, guest PC 0x0c0428a2 */
if(!s->budget--) { s->failed_pc=0x0c0428a2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[5])!=0);
goto P_0c0428a4;
P_0c0428a4: /* original 8b00, guest PC 0x0c0428a4 */
if(!s->budget--) { s->failed_pc=0x0c0428a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0428a8; }
goto P_0c0428a6;
P_0c0428a6: /* original 7ec0, guest PC 0x0c0428a6 */
if(!s->budget--) { s->failed_pc=0x0c0428a6u; return 0; }
r[14]+=0xffffffc0u;
goto P_0c0428a8;
P_0c0428a8: /* original 3c43, guest PC 0x0c0428a8 */
if(!s->budget--) { s->failed_pc=0x0c0428a8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[4])!=0);
goto P_0c0428aa;
P_0c0428aa: /* original 8b00, guest PC 0x0c0428aa */
if(!s->budget--) { s->failed_pc=0x0c0428aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0428ae; }
goto P_0c0428ac;
P_0c0428ac: /* original 7cff, guest PC 0x0c0428ac */
if(!s->budget--) { s->failed_pc=0x0c0428acu; return 0; }
r[12]+=0xffffffffu;
goto P_0c0428ae;
P_0c0428ae: /* original 9a3a, guest PC 0x0c0428ae */
if(!s->budget--) { s->failed_pc=0x0c0428aeu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042926u,2);
goto P_0c0428b0;
P_0c0428b0: /* original 64e3, guest PC 0x0c0428b0 */
if(!s->budget--) { s->failed_pc=0x0c0428b0u; return 0; }
r[4]=r[14];
goto P_0c0428b2;
P_0c0428b2: /* original 9b39, guest PC 0x0c0428b2 */
if(!s->budget--) { s->failed_pc=0x0c0428b2u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042928u,2);
goto P_0c0428b4;
P_0c0428b4: /* original 34ac, guest PC 0x0c0428b4 */
if(!s->budget--) { s->failed_pc=0x0c0428b4u; return 0; }
r[4]+=r[10];
goto P_0c0428b6;
P_0c0428b6: /* original 9935, guest PC 0x0c0428b6 */
if(!s->budget--) { s->failed_pc=0x0c0428b6u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042924u,2);
goto P_0c0428b8;
P_0c0428b8: /* original 04b7, guest PC 0x0c0428b8 */
if(!s->budget--) { s->failed_pc=0x0c0428b8u; return 0; }
r[19]=r[4]*r[11];
goto P_0c0428ba;
P_0c0428ba: /* original 041a, guest PC 0x0c0428ba */
if(!s->budget--) { s->failed_pc=0x0c0428bau; return 0; }
r[4]=r[19];
goto P_0c0428bc;
P_0c0428bc: /* original 34cc, guest PC 0x0c0428bc */
if(!s->budget--) { s->failed_pc=0x0c0428bcu; return 0; }
r[4]+=r[12];
goto P_0c0428be;
P_0c0428be: /* original a008, guest PC 0x0c0428be */
if(!s->budget--) { s->failed_pc=0x0c0428beu; return 0; }
r[4]+=r[9];
goto P_0c0428d2;
P_0c0428c0: /* original 349c, guest PC 0x0c0428c0 */
if(!s->budget--) { s->failed_pc=0x0c0428c0u; return 0; }
r[4]+=r[9];
if(!vf3_matrix_family(0x0c0428c2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0428c2u; return 0; } return 1;
P_0c0428d0: /* original 64e3, guest PC 0x0c0428d0 */
if(!s->budget--) { s->failed_pc=0x0c0428d0u; return 0; }
r[4]=r[14];
goto P_0c0428d2;
P_0c0428d2: /* original bec5, guest PC 0x0c0428d2 */
if(!s->budget--) { s->failed_pc=0x0c0428d2u; return 0; }
target=code_base|0x0c042660u; r[16]=code_base|0x0c0428d6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0428d6u) { target=s->pc; goto dispatch; }
goto P_0c0428d6;
P_0c0428d4: /* original 0009, guest PC 0x0c0428d4 */
if(!s->budget--) { s->failed_pc=0x0c0428d4u; return 0; }
goto P_0c0428d6;
P_0c0428d6: /* original 6ed4, guest PC 0x0c0428d6 */
if(!s->budget--) { s->failed_pc=0x0c0428d6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[13]+=1;
r[14]=tmp;
goto P_0c0428d8;
P_0c0428d8: /* original 6eec, guest PC 0x0c0428d8 */
if(!s->budget--) { s->failed_pc=0x0c0428d8u; return 0; }
r[14]=r[14]&255u;
goto P_0c0428da;
P_0c0428da: /* original 2ee8, guest PC 0x0c0428da */
if(!s->budget--) { s->failed_pc=0x0c0428dau; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0428dc;
P_0c0428dc: /* original 8901, guest PC 0x0c0428dc */
if(!s->budget--) { s->failed_pc=0x0c0428dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0428e2; }
goto P_0c0428de;
P_0c0428de: /* original af67, guest PC 0x0c0428de */
if(!s->budget--) { s->failed_pc=0x0c0428deu; return 0; }
goto P_0c0427b0;
P_0c0428e0: /* original 0009, guest PC 0x0c0428e0 */
if(!s->budget--) { s->failed_pc=0x0c0428e0u; return 0; }
goto P_0c0428e2;
P_0c0428e2: /* original 4f16, guest PC 0x0c0428e2 */
if(!s->budget--) { s->failed_pc=0x0c0428e2u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0428e4;
P_0c0428e4: /* original 4f26, guest PC 0x0c0428e4 */
if(!s->budget--) { s->failed_pc=0x0c0428e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0428e6;
P_0c0428e6: /* original 69f6, guest PC 0x0c0428e6 */
if(!s->budget--) { s->failed_pc=0x0c0428e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0428e8;
P_0c0428e8: /* original 6af6, guest PC 0x0c0428e8 */
if(!s->budget--) { s->failed_pc=0x0c0428e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0428ea;
P_0c0428ea: /* original 6bf6, guest PC 0x0c0428ea */
if(!s->budget--) { s->failed_pc=0x0c0428eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0428ec;
P_0c0428ec: /* original 6cf6, guest PC 0x0c0428ec */
if(!s->budget--) { s->failed_pc=0x0c0428ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0428ee;
P_0c0428ee: /* original 6df6, guest PC 0x0c0428ee */
if(!s->budget--) { s->failed_pc=0x0c0428eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0428f0;
P_0c0428f0: /* original 000b, guest PC 0x0c0428f0 */
if(!s->budget--) { s->failed_pc=0x0c0428f0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0428f2: /* original 6ef6, guest PC 0x0c0428f2 */
if(!s->budget--) { s->failed_pc=0x0c0428f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0428f4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0428f4u; return 0; } return 1;
P_0c042900: /* original 4f22, guest PC 0x0c042900 */
if(!s->budget--) { s->failed_pc=0x0c042900u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c042902;
P_0c042902: /* original e503, guest PC 0x0c042902 */
if(!s->budget--) { s->failed_pc=0x0c042902u; return 0; }
r[5]=0x00000003u;
goto P_0c042904;
P_0c042904: /* original 60f3, guest PC 0x0c042904 */
if(!s->budget--) { s->failed_pc=0x0c042904u; return 0; }
r[0]=r[15];
goto P_0c042906;
P_0c042906: /* original 7004, guest PC 0x0c042906 */
if(!s->budget--) { s->failed_pc=0x0c042906u; return 0; }
r[0]+=0x00000004u;
goto P_0c042908;
P_0c042908: /* original 7004, guest PC 0x0c042908 */
if(!s->budget--) { s->failed_pc=0x0c042908u; return 0; }
r[0]+=0x00000004u;
goto P_0c04290a;
P_0c04290a: /* original 2508, guest PC 0x0c04290a */
if(!s->budget--) { s->failed_pc=0x0c04290au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[0])==0)!=0);
goto P_0c04290c;
P_0c04290c: /* original 8910, guest PC 0x0c04290c */
if(!s->budget--) { s->failed_pc=0x0c04290cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042930; }
goto P_0c04290e;
P_0c04290e: /* original 65f3, guest PC 0x0c04290e */
if(!s->budget--) { s->failed_pc=0x0c04290eu; return 0; }
r[5]=r[15];
goto P_0c042910;
P_0c042910: /* original 7504, guest PC 0x0c042910 */
if(!s->budget--) { s->failed_pc=0x0c042910u; return 0; }
r[5]+=0x00000004u;
goto P_0c042912;
P_0c042912: /* original a010, guest PC 0x0c042912 */
if(!s->budget--) { s->failed_pc=0x0c042912u; return 0; }
r[5]+=0x00000008u;
goto P_0c042936;
P_0c042914: /* original 7508, guest PC 0x0c042914 */
if(!s->budget--) { s->failed_pc=0x0c042914u; return 0; }
r[5]+=0x00000008u;
if(!vf3_matrix_family(0x0c042916u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042916u; return 0; } return 1;
P_0c042930: /* original 65f3, guest PC 0x0c042930 */
if(!s->budget--) { s->failed_pc=0x0c042930u; return 0; }
r[5]=r[15];
goto P_0c042932;
P_0c042932: /* original 7504, guest PC 0x0c042932 */
if(!s->budget--) { s->failed_pc=0x0c042932u; return 0; }
r[5]+=0x00000004u;
goto P_0c042934;
P_0c042934: /* original 7504, guest PC 0x0c042934 */
if(!s->budget--) { s->failed_pc=0x0c042934u; return 0; }
r[5]+=0x00000004u;
goto P_0c042936;
P_0c042936: /* original d318, guest PC 0x0c042936 */
if(!s->budget--) { s->failed_pc=0x0c042936u; return 0; }
r[3]=read(ram,0x0c042998u,4);
goto P_0c042938;
P_0c042938: /* original 6653, guest PC 0x0c042938 */
if(!s->budget--) { s->failed_pc=0x0c042938u; return 0; }
r[6]=r[5];
goto P_0c04293a;
P_0c04293a: /* original d416, guest PC 0x0c04293a */
if(!s->budget--) { s->failed_pc=0x0c04293au; return 0; }
r[4]=read(ram,0x0c042994u,4);
goto P_0c04293c;
P_0c04293c: /* original 430b, guest PC 0x0c04293c */
if(!s->budget--) { s->failed_pc=0x0c04293cu; return 0; }
target=r[3];
r[16]=code_base|0x0c042940u;
r[5]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c042940u) { target=s->pc; goto dispatch; }
goto P_0c042940;
P_0c04293e: /* original 55f1, guest PC 0x0c04293e */
if(!s->budget--) { s->failed_pc=0x0c04293eu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c042940;
P_0c042940: /* original d414, guest PC 0x0c042940 */
if(!s->budget--) { s->failed_pc=0x0c042940u; return 0; }
r[4]=read(ram,0x0c042994u,4);
goto P_0c042942;
P_0c042942: /* original bf25, guest PC 0x0c042942 */
if(!s->budget--) { s->failed_pc=0x0c042942u; return 0; }
target=code_base|0x0c042790u; r[16]=code_base|0x0c042946u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c042946u) { target=s->pc; goto dispatch; }
goto P_0c042946;
P_0c042944: /* original 0009, guest PC 0x0c042944 */
if(!s->budget--) { s->failed_pc=0x0c042944u; return 0; }
goto P_0c042946;
P_0c042946: /* original 4f26, guest PC 0x0c042946 */
if(!s->budget--) { s->failed_pc=0x0c042946u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c042948;
P_0c042948: /* original 000b, guest PC 0x0c042948 */
if(!s->budget--) { s->failed_pc=0x0c042948u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c04294a: /* original e000, guest PC 0x0c04294a */
if(!s->budget--) { s->failed_pc=0x0c04294au; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c04294cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04294cu; return 0; } return 1;
P_0c042950: /* original d312, guest PC 0x0c042950 */
if(!s->budget--) { s->failed_pc=0x0c042950u; return 0; }
r[3]=read(ram,0x0c04299cu,4);
goto P_0c042952;
P_0c042952: /* original 000b, guest PC 0x0c042952 */
if(!s->budget--) { s->failed_pc=0x0c042952u; return 0; }
target=r[16];
write(ram,r[3],r[4],1);
s->pc=target; return ram->oob==0;
P_0c042954: /* original 2340, guest PC 0x0c042954 */
if(!s->budget--) { s->failed_pc=0x0c042954u; return 0; }
write(ram,r[3],r[4],1);
if(!vf3_matrix_family(0x0c042956u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042956u; return 0; } return 1;
P_0c042960: /* original d20f, guest PC 0x0c042960 */
if(!s->budget--) { s->failed_pc=0x0c042960u; return 0; }
r[2]=read(ram,0x0c0429a0u,4);
goto P_0c042962;
P_0c042962: /* original 000b, guest PC 0x0c042962 */
if(!s->budget--) { s->failed_pc=0x0c042962u; return 0; }
target=r[16];
write(ram,r[2],r[4],1);
s->pc=target; return ram->oob==0;
P_0c042964: /* original 2240, guest PC 0x0c042964 */
if(!s->budget--) { s->failed_pc=0x0c042964u; return 0; }
write(ram,r[2],r[4],1);
if(!vf3_matrix_family(0x0c042966u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042966u; return 0; } return 1;
P_0c042970: /* original d30c, guest PC 0x0c042970 */
if(!s->budget--) { s->failed_pc=0x0c042970u; return 0; }
r[3]=read(ram,0x0c0429a4u,4);
goto P_0c042972;
P_0c042972: /* original 000b, guest PC 0x0c042972 */
if(!s->budget--) { s->failed_pc=0x0c042972u; return 0; }
target=r[16];
write(ram,r[3],r[4],1);
s->pc=target; return ram->oob==0;
P_0c042974: /* original 2340, guest PC 0x0c042974 */
if(!s->budget--) { s->failed_pc=0x0c042974u; return 0; }
write(ram,r[3],r[4],1);
if(!vf3_matrix_family(0x0c042976u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042976u; return 0; } return 1;
P_0c0429b0: /* original 2fe6, guest PC 0x0c0429b0 */
if(!s->budget--) { s->failed_pc=0x0c0429b0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0429b2;
P_0c0429b2: /* original 2fb6, guest PC 0x0c0429b2 */
if(!s->budget--) { s->failed_pc=0x0c0429b2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0429b4;
P_0c0429b4: /* original 2fa6, guest PC 0x0c0429b4 */
if(!s->budget--) { s->failed_pc=0x0c0429b4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0429b6;
P_0c0429b6: /* original 2f96, guest PC 0x0c0429b6 */
if(!s->budget--) { s->failed_pc=0x0c0429b6u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0429b8;
P_0c0429b8: /* original d233, guest PC 0x0c0429b8 */
if(!s->budget--) { s->failed_pc=0x0c0429b8u; return 0; }
r[2]=read(ram,0x0c042a88u,4);
goto P_0c0429ba;
P_0c0429ba: /* original 6922, guest PC 0x0c0429ba */
if(!s->budget--) { s->failed_pc=0x0c0429bau; return 0; }
tmp=read(ram,r[2],4);
r[9]=tmp;
goto P_0c0429bc;
P_0c0429bc: /* original 2998, guest PC 0x0c0429bc */
if(!s->budget--) { s->failed_pc=0x0c0429bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0429be;
P_0c0429be: /* original 893a, guest PC 0x0c0429be */
if(!s->budget--) { s->failed_pc=0x0c0429beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a36; }
goto P_0c0429c0;
P_0c0429c0: /* original 4611, guest PC 0x0c0429c0 */
if(!s->budget--) { s->failed_pc=0x0c0429c0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=0)!=0);
goto P_0c0429c2;
P_0c0429c2: /* original 8b38, guest PC 0x0c0429c2 */
if(!s->budget--) { s->failed_pc=0x0c0429c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042a36; }
goto P_0c0429c4;
P_0c0429c4: /* original 975c, guest PC 0x0c0429c4 */
if(!s->budget--) { s->failed_pc=0x0c0429c4u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042a80u,2);
goto P_0c0429c6;
P_0c0429c6: /* original 3472, guest PC 0x0c0429c6 */
if(!s->budget--) { s->failed_pc=0x0c0429c6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[7])!=0);
goto P_0c0429c8;
P_0c0429c8: /* original 8935, guest PC 0x0c0429c8 */
if(!s->budget--) { s->failed_pc=0x0c0429c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a36; }
goto P_0c0429ca;
P_0c0429ca: /* original 3572, guest PC 0x0c0429ca */
if(!s->budget--) { s->failed_pc=0x0c0429cau; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[7])!=0);
goto P_0c0429cc;
P_0c0429cc: /* original 8933, guest PC 0x0c0429cc */
if(!s->budget--) { s->failed_pc=0x0c0429ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a36; }
goto P_0c0429ce;
P_0c0429ce: /* original 6343, guest PC 0x0c0429ce */
if(!s->budget--) { s->failed_pc=0x0c0429ceu; return 0; }
r[3]=r[4];
goto P_0c0429d0;
P_0c0429d0: /* original e701, guest PC 0x0c0429d0 */
if(!s->budget--) { s->failed_pc=0x0c0429d0u; return 0; }
r[7]=0x00000001u;
goto P_0c0429d2;
P_0c0429d2: /* original 2378, guest PC 0x0c0429d2 */
if(!s->budget--) { s->failed_pc=0x0c0429d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c0429d4;
P_0c0429d4: /* original 8d03, guest PC 0x0c0429d4 */
if(!s->budget--) { s->failed_pc=0x0c0429d4u; return 0; }
cond=r[17]&1u;
r[10]=0x00000003u;
if(cond) { goto P_0c0429de; }
goto P_0c0429d8;
P_0c0429d6: /* original ea03, guest PC 0x0c0429d6 */
if(!s->budget--) { s->failed_pc=0x0c0429d6u; return 0; }
r[10]=0x00000003u;
goto P_0c0429d8;
P_0c0429d8: /* original 4608, guest PC 0x0c0429d8 */
if(!s->budget--) { s->failed_pc=0x0c0429d8u; return 0; }
r[6]<<=2;
goto P_0c0429da;
P_0c0429da: /* original 4608, guest PC 0x0c0429da */
if(!s->budget--) { s->failed_pc=0x0c0429dau; return 0; }
r[6]<<=2;
goto P_0c0429dc;
P_0c0429dc: /* original ea30, guest PC 0x0c0429dc */
if(!s->budget--) { s->failed_pc=0x0c0429dcu; return 0; }
r[10]=0x00000030u;
goto P_0c0429de;
P_0c0429de: /* original 6353, guest PC 0x0c0429de */
if(!s->budget--) { s->failed_pc=0x0c0429deu; return 0; }
r[3]=r[5];
goto P_0c0429e0;
P_0c0429e0: /* original 2378, guest PC 0x0c0429e0 */
if(!s->budget--) { s->failed_pc=0x0c0429e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c0429e2;
P_0c0429e2: /* original 8901, guest PC 0x0c0429e2 */
if(!s->budget--) { s->failed_pc=0x0c0429e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0429e8; }
goto P_0c0429e4;
P_0c0429e4: /* original 4608, guest PC 0x0c0429e4 */
if(!s->budget--) { s->failed_pc=0x0c0429e4u; return 0; }
r[6]<<=2;
goto P_0c0429e6;
P_0c0429e6: /* original 4a08, guest PC 0x0c0429e6 */
if(!s->budget--) { s->failed_pc=0x0c0429e6u; return 0; }
r[10]<<=2;
goto P_0c0429e8;
P_0c0429e8: /* original 934b, guest PC 0x0c0429e8 */
if(!s->budget--) { s->failed_pc=0x0c0429e8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042a82u,2);
goto P_0c0429ea;
P_0c0429ea: /* original 6e73, guest PC 0x0c0429ea */
if(!s->budget--) { s->failed_pc=0x0c0429eau; return 0; }
r[14]=r[7];
goto P_0c0429ec;
P_0c0429ec: /* original 914a, guest PC 0x0c0429ec */
if(!s->budget--) { s->failed_pc=0x0c0429ecu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042a84u,2);
goto P_0c0429ee;
P_0c0429ee: /* original eb00, guest PC 0x0c0429ee */
if(!s->budget--) { s->failed_pc=0x0c0429eeu; return 0; }
r[11]=0x00000000u;
goto P_0c0429f0;
P_0c0429f0: /* original 9048, guest PC 0x0c0429f0 */
if(!s->budget--) { s->failed_pc=0x0c0429f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042a84u,2);
goto P_0c0429f2;
P_0c0429f2: /* original 33a8, guest PC 0x0c0429f2 */
if(!s->budget--) { s->failed_pc=0x0c0429f2u; return 0; }
r[3]-=r[10];
goto P_0c0429f4;
P_0c0429f4: /* original 6a33, guest PC 0x0c0429f4 */
if(!s->budget--) { s->failed_pc=0x0c0429f4u; return 0; }
r[10]=r[3];
goto P_0c0429f6;
P_0c0429f6: /* original 4401, guest PC 0x0c0429f6 */
if(!s->budget--) { s->failed_pc=0x0c0429f6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c0429f8;
P_0c0429f8: /* original 4501, guest PC 0x0c0429f8 */
if(!s->budget--) { s->failed_pc=0x0c0429f8u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c0429fa;
P_0c0429fa: /* original 2008, guest PC 0x0c0429fa */
if(!s->budget--) { s->failed_pc=0x0c0429fau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0429fc;
P_0c0429fc: /* original 8906, guest PC 0x0c0429fc */
if(!s->budget--) { s->failed_pc=0x0c0429fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a0c; }
goto P_0c0429fe;
P_0c0429fe: /* original 6353, guest PC 0x0c0429fe */
if(!s->budget--) { s->failed_pc=0x0c0429feu; return 0; }
r[3]=r[5];
goto P_0c042a00;
P_0c042a00: /* original 2378, guest PC 0x0c042a00 */
if(!s->budget--) { s->failed_pc=0x0c042a00u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c042a02;
P_0c042a02: /* original 8900, guest PC 0x0c042a02 */
if(!s->budget--) { s->failed_pc=0x0c042a02u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a06; }
goto P_0c042a04;
P_0c042a04: /* original 2beb, guest PC 0x0c042a04 */
if(!s->budget--) { s->failed_pc=0x0c042a04u; return 0; }
r[11]|=r[14];
goto P_0c042a06;
P_0c042a06: /* original 4e00, guest PC 0x0c042a06 */
if(!s->budget--) { s->failed_pc=0x0c042a06u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c042a08;
P_0c042a08: /* original 4501, guest PC 0x0c042a08 */
if(!s->budget--) { s->failed_pc=0x0c042a08u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c042a0a;
P_0c042a0a: /* original 4021, guest PC 0x0c042a0a */
if(!s->budget--) { s->failed_pc=0x0c042a0au; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c042a0c;
P_0c042a0c: /* original 2118, guest PC 0x0c042a0c */
if(!s->budget--) { s->failed_pc=0x0c042a0cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c042a0e;
P_0c042a0e: /* original 8906, guest PC 0x0c042a0e */
if(!s->budget--) { s->failed_pc=0x0c042a0eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a1e; }
goto P_0c042a10;
P_0c042a10: /* original 6243, guest PC 0x0c042a10 */
if(!s->budget--) { s->failed_pc=0x0c042a10u; return 0; }
r[2]=r[4];
goto P_0c042a12;
P_0c042a12: /* original 2278, guest PC 0x0c042a12 */
if(!s->budget--) { s->failed_pc=0x0c042a12u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[7])==0)!=0);
goto P_0c042a14;
P_0c042a14: /* original 8900, guest PC 0x0c042a14 */
if(!s->budget--) { s->failed_pc=0x0c042a14u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a18; }
goto P_0c042a16;
P_0c042a16: /* original 2beb, guest PC 0x0c042a16 */
if(!s->budget--) { s->failed_pc=0x0c042a16u; return 0; }
r[11]|=r[14];
goto P_0c042a18;
P_0c042a18: /* original 4e00, guest PC 0x0c042a18 */
if(!s->budget--) { s->failed_pc=0x0c042a18u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c042a1a;
P_0c042a1a: /* original 4401, guest PC 0x0c042a1a */
if(!s->budget--) { s->failed_pc=0x0c042a1au; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c042a1c;
P_0c042a1c: /* original 4121, guest PC 0x0c042a1c */
if(!s->budget--) { s->failed_pc=0x0c042a1cu; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]=(uint32_t)((int32_t)r[1]>>1);
goto P_0c042a1e;
P_0c042a1e: /* original 6213, guest PC 0x0c042a1e */
if(!s->budget--) { s->failed_pc=0x0c042a1eu; return 0; }
r[2]=r[1];
goto P_0c042a20;
P_0c042a20: /* original 220b, guest PC 0x0c042a20 */
if(!s->budget--) { s->failed_pc=0x0c042a20u; return 0; }
r[2]|=r[0];
goto P_0c042a22;
P_0c042a22: /* original 2228, guest PC 0x0c042a22 */
if(!s->budget--) { s->failed_pc=0x0c042a22u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c042a24;
P_0c042a24: /* original 8be9, guest PC 0x0c042a24 */
if(!s->budget--) { s->failed_pc=0x0c042a24u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0429fa; }
goto P_0c042a26;
P_0c042a26: /* original 932e, guest PC 0x0c042a26 */
if(!s->budget--) { s->failed_pc=0x0c042a26u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042a86u,2);
goto P_0c042a28;
P_0c042a28: /* original 64b3, guest PC 0x0c042a28 */
if(!s->budget--) { s->failed_pc=0x0c042a28u; return 0; }
r[4]=r[11];
goto P_0c042a2a;
P_0c042a2a: /* original 349c, guest PC 0x0c042a2a */
if(!s->budget--) { s->failed_pc=0x0c042a2au; return 0; }
r[4]+=r[9];
goto P_0c042a2c;
P_0c042a2c: /* original 343c, guest PC 0x0c042a2c */
if(!s->budget--) { s->failed_pc=0x0c042a2cu; return 0; }
r[4]+=r[3];
goto P_0c042a2e;
P_0c042a2e: /* original 6240, guest PC 0x0c042a2e */
if(!s->budget--) { s->failed_pc=0x0c042a2eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c042a30;
P_0c042a30: /* original 2a29, guest PC 0x0c042a30 */
if(!s->budget--) { s->failed_pc=0x0c042a30u; return 0; }
r[10]&=r[2];
goto P_0c042a32;
P_0c042a32: /* original 2a6b, guest PC 0x0c042a32 */
if(!s->budget--) { s->failed_pc=0x0c042a32u; return 0; }
r[10]|=r[6];
goto P_0c042a34;
P_0c042a34: /* original 24a0, guest PC 0x0c042a34 */
if(!s->budget--) { s->failed_pc=0x0c042a34u; return 0; }
write(ram,r[4],r[10],1);
goto P_0c042a36;
P_0c042a36: /* original 69f6, guest PC 0x0c042a36 */
if(!s->budget--) { s->failed_pc=0x0c042a36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c042a38;
P_0c042a38: /* original 6af6, guest PC 0x0c042a38 */
if(!s->budget--) { s->failed_pc=0x0c042a38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c042a3a;
P_0c042a3a: /* original 6bf6, guest PC 0x0c042a3a */
if(!s->budget--) { s->failed_pc=0x0c042a3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c042a3c;
P_0c042a3c: /* original 000b, guest PC 0x0c042a3c */
if(!s->budget--) { s->failed_pc=0x0c042a3cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c042a3e: /* original 6ef6, guest PC 0x0c042a3e */
if(!s->budget--) { s->failed_pc=0x0c042a3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c042a40u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042a40u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
