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
int vf3_away_batch43_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03fda0u: goto P_0c03fda0;
case 0x0c03fda2u: goto P_0c03fda2;
case 0x0c03fda4u: goto P_0c03fda4;
case 0x0c03fda6u: goto P_0c03fda6;
case 0x0c03fda8u: goto P_0c03fda8;
case 0x0c03fdaau: goto P_0c03fdaa;
case 0x0c03fdacu: goto P_0c03fdac;
case 0x0c03fdaeu: goto P_0c03fdae;
case 0x0c03fdb0u: goto P_0c03fdb0;
case 0x0c03fdb2u: goto P_0c03fdb2;
case 0x0c03fdb4u: goto P_0c03fdb4;
case 0x0c03fdb6u: goto P_0c03fdb6;
case 0x0c03fdb8u: goto P_0c03fdb8;
case 0x0c03fdbau: goto P_0c03fdba;
case 0x0c03fdbcu: goto P_0c03fdbc;
case 0x0c042460u: goto P_0c042460;
case 0x0c042462u: goto P_0c042462;
case 0x0c042464u: goto P_0c042464;
case 0x0c042466u: goto P_0c042466;
case 0x0c042468u: goto P_0c042468;
case 0x0c04246au: goto P_0c04246a;
case 0x0c04246cu: goto P_0c04246c;
case 0x0c04246eu: goto P_0c04246e;
case 0x0c042490u: goto P_0c042490;
case 0x0c042492u: goto P_0c042492;
case 0x0c042494u: goto P_0c042494;
case 0x0c042496u: goto P_0c042496;
case 0x0c042498u: goto P_0c042498;
case 0x0c04249au: goto P_0c04249a;
case 0x0c04249cu: goto P_0c04249c;
case 0x0c04249eu: goto P_0c04249e;
case 0x0c0424a0u: goto P_0c0424a0;
case 0x0c0424a2u: goto P_0c0424a2;
case 0x0c0424a4u: goto P_0c0424a4;
case 0x0c0424a6u: goto P_0c0424a6;
case 0x0c0424a8u: goto P_0c0424a8;
case 0x0c0424aau: goto P_0c0424aa;
case 0x0c0424acu: goto P_0c0424ac;
case 0x0c0424aeu: goto P_0c0424ae;
case 0x0c0424b0u: goto P_0c0424b0;
case 0x0c0424b2u: goto P_0c0424b2;
case 0x0c0424b4u: goto P_0c0424b4;
case 0x0c0424b6u: goto P_0c0424b6;
case 0x0c0425f0u: goto P_0c0425f0;
case 0x0c0425f2u: goto P_0c0425f2;
case 0x0c0425f4u: goto P_0c0425f4;
case 0x0c0425f6u: goto P_0c0425f6;
case 0x0c0425f8u: goto P_0c0425f8;
case 0x0c0425fau: goto P_0c0425fa;
case 0x0c0425fcu: goto P_0c0425fc;
case 0x0c042660u: goto P_0c042660;
case 0x0c042662u: goto P_0c042662;
case 0x0c042664u: goto P_0c042664;
case 0x0c042666u: goto P_0c042666;
case 0x0c042668u: goto P_0c042668;
case 0x0c04266au: goto P_0c04266a;
case 0x0c04266cu: goto P_0c04266c;
case 0x0c04266eu: goto P_0c04266e;
case 0x0c042670u: goto P_0c042670;
case 0x0c042672u: goto P_0c042672;
case 0x0c042674u: goto P_0c042674;
case 0x0c042676u: goto P_0c042676;
case 0x0c042678u: goto P_0c042678;
case 0x0c04267au: goto P_0c04267a;
case 0x0c04267cu: goto P_0c04267c;
case 0x0c04267eu: goto P_0c04267e;
case 0x0c042680u: goto P_0c042680;
case 0x0c042682u: goto P_0c042682;
case 0x0c042684u: goto P_0c042684;
case 0x0c042686u: goto P_0c042686;
case 0x0c042688u: goto P_0c042688;
case 0x0c04268au: goto P_0c04268a;
case 0x0c04268cu: goto P_0c04268c;
case 0x0c04268eu: goto P_0c04268e;
case 0x0c042690u: goto P_0c042690;
case 0x0c042692u: goto P_0c042692;
case 0x0c042694u: goto P_0c042694;
case 0x0c042696u: goto P_0c042696;
case 0x0c042698u: goto P_0c042698;
case 0x0c04269au: goto P_0c04269a;
case 0x0c04269cu: goto P_0c04269c;
case 0x0c04269eu: goto P_0c04269e;
case 0x0c0426a0u: goto P_0c0426a0;
case 0x0c0426a2u: goto P_0c0426a2;
case 0x0c0426a4u: goto P_0c0426a4;
case 0x0c0426a6u: goto P_0c0426a6;
case 0x0c0426a8u: goto P_0c0426a8;
case 0x0c0426aau: goto P_0c0426aa;
case 0x0c0426acu: goto P_0c0426ac;
case 0x0c0426aeu: goto P_0c0426ae;
case 0x0c0426b0u: goto P_0c0426b0;
case 0x0c0426b2u: goto P_0c0426b2;
case 0x0c0426b4u: goto P_0c0426b4;
case 0x0c0426b6u: goto P_0c0426b6;
case 0x0c0426b8u: goto P_0c0426b8;
case 0x0c0426bau: goto P_0c0426ba;
case 0x0c0426c0u: goto P_0c0426c0;
case 0x0c0426c2u: goto P_0c0426c2;
case 0x0c0426c4u: goto P_0c0426c4;
case 0x0c0426c6u: goto P_0c0426c6;
case 0x0c0426d0u: goto P_0c0426d0;
case 0x0c0426d2u: goto P_0c0426d2;
case 0x0c0426d4u: goto P_0c0426d4;
case 0x0c0426d6u: goto P_0c0426d6;
case 0x0c0426d8u: goto P_0c0426d8;
case 0x0c0426dau: goto P_0c0426da;
case 0x0c0426dcu: goto P_0c0426dc;
case 0x0c0426deu: goto P_0c0426de;
case 0x0c0426e0u: goto P_0c0426e0;
case 0x0c0426e2u: goto P_0c0426e2;
case 0x0c0426e4u: goto P_0c0426e4;
case 0x0c0426e6u: goto P_0c0426e6;
case 0x0c0426e8u: goto P_0c0426e8;
case 0x0c0426eau: goto P_0c0426ea;
case 0x0c0426ecu: goto P_0c0426ec;
case 0x0c0426eeu: goto P_0c0426ee;
case 0x0c0426f0u: goto P_0c0426f0;
case 0x0c0426f2u: goto P_0c0426f2;
case 0x0c0426f4u: goto P_0c0426f4;
case 0x0c0426f6u: goto P_0c0426f6;
case 0x0c0426f8u: goto P_0c0426f8;
case 0x0c0426fau: goto P_0c0426fa;
case 0x0c0426fcu: goto P_0c0426fc;
case 0x0c0426feu: goto P_0c0426fe;
case 0x0c042700u: goto P_0c042700;
case 0x0c042702u: goto P_0c042702;
case 0x0c042704u: goto P_0c042704;
case 0x0c042706u: goto P_0c042706;
case 0x0c042708u: goto P_0c042708;
case 0x0c04270au: goto P_0c04270a;
case 0x0c04270cu: goto P_0c04270c;
case 0x0c04270eu: goto P_0c04270e;
case 0x0c042710u: goto P_0c042710;
case 0x0c042740u: goto P_0c042740;
case 0x0c042742u: goto P_0c042742;
case 0x0c042744u: goto P_0c042744;
case 0x0c042746u: goto P_0c042746;
case 0x0c042748u: goto P_0c042748;
case 0x0c04274au: goto P_0c04274a;
case 0x0c04274cu: goto P_0c04274c;
case 0x0c04274eu: goto P_0c04274e;
case 0x0c042750u: goto P_0c042750;
case 0x0c042752u: goto P_0c042752;
case 0x0c042754u: goto P_0c042754;
case 0x0c042756u: goto P_0c042756;
case 0x0c042758u: goto P_0c042758;
case 0x0c04275au: goto P_0c04275a;
case 0x0c04275cu: goto P_0c04275c;
case 0x0c04275eu: goto P_0c04275e;
case 0x0c042760u: goto P_0c042760;
case 0x0c042762u: goto P_0c042762;
case 0x0c042764u: goto P_0c042764;
case 0x0c042766u: goto P_0c042766;
case 0x0c042768u: goto P_0c042768;
case 0x0c04276au: goto P_0c04276a;
case 0x0c04276cu: goto P_0c04276c;
case 0x0c04276eu: goto P_0c04276e;
case 0x0c042770u: goto P_0c042770;
case 0x0c042772u: goto P_0c042772;
case 0x0c042774u: goto P_0c042774;
case 0x0c042776u: goto P_0c042776;
case 0x0c042778u: goto P_0c042778;
case 0x0c04277au: goto P_0c04277a;
case 0x0c04277cu: goto P_0c04277c;
case 0x0c04277eu: goto P_0c04277e;
case 0x0c042780u: goto P_0c042780;
case 0x0c042782u: goto P_0c042782;
case 0x0c042784u: goto P_0c042784;
case 0x0c042786u: goto P_0c042786;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c03fda0: /* original e31f, guest PC 0x0c03fda0 */
if(!s->budget--) { s->failed_pc=0x0c03fda0u; return 0; }
r[3]=0x0000001fu;
goto P_0c03fda2;
P_0c03fda2: /* original d208, guest PC 0x0c03fda2 */
if(!s->budget--) { s->failed_pc=0x0c03fda2u; return 0; }
r[2]=read(ram,0x0c03fdc4u,4);
goto P_0c03fda4;
P_0c03fda4: /* original e501, guest PC 0x0c03fda4 */
if(!s->budget--) { s->failed_pc=0x0c03fda4u; return 0; }
r[5]=0x00000001u;
goto P_0c03fda6;
P_0c03fda6: /* original 2349, guest PC 0x0c03fda6 */
if(!s->budget--) { s->failed_pc=0x0c03fda6u; return 0; }
r[3]&=r[4];
goto P_0c03fda8;
P_0c03fda8: /* original 6022, guest PC 0x0c03fda8 */
if(!s->budget--) { s->failed_pc=0x0c03fda8u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c03fdaa;
P_0c03fdaa: /* original 453c, guest PC 0x0c03fdaa */
if(!s->budget--) { s->failed_pc=0x0c03fdaau; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c03fdac;
P_0c03fdac: /* original e3fb, guest PC 0x0c03fdac */
if(!s->budget--) { s->failed_pc=0x0c03fdacu; return 0; }
r[3]=0xfffffffbu;
goto P_0c03fdae;
P_0c03fdae: /* original 443c, guest PC 0x0c03fdae */
if(!s->budget--) { s->failed_pc=0x0c03fdaeu; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c03fdb0;
P_0c03fdb0: /* original 6343, guest PC 0x0c03fdb0 */
if(!s->budget--) { s->failed_pc=0x0c03fdb0u; return 0; }
r[3]=r[4];
goto P_0c03fdb2;
P_0c03fdb2: /* original 4308, guest PC 0x0c03fdb2 */
if(!s->budget--) { s->failed_pc=0x0c03fdb2u; return 0; }
r[3]<<=2;
goto P_0c03fdb4;
P_0c03fdb4: /* original 013e, guest PC 0x0c03fdb4 */
if(!s->budget--) { s->failed_pc=0x0c03fdb4u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c03fdb6;
P_0c03fdb6: /* original 6557, guest PC 0x0c03fdb6 */
if(!s->budget--) { s->failed_pc=0x0c03fdb6u; return 0; }
r[5]=~r[5];
goto P_0c03fdb8;
P_0c03fdb8: /* original 2159, guest PC 0x0c03fdb8 */
if(!s->budget--) { s->failed_pc=0x0c03fdb8u; return 0; }
r[1]&=r[5];
goto P_0c03fdba;
P_0c03fdba: /* original 000b, guest PC 0x0c03fdba */
if(!s->budget--) { s->failed_pc=0x0c03fdbau; return 0; }
target=r[16];
write(ram,r[3]+r[0],r[1],4);
s->pc=target; return ram->oob==0;
P_0c03fdbc: /* original 0316, guest PC 0x0c03fdbc */
if(!s->budget--) { s->failed_pc=0x0c03fdbcu; return 0; }
write(ram,r[3]+r[0],r[1],4);
if(!vf3_matrix_family(0x0c03fdbeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fdbeu; return 0; } return 1;
P_0c042460: /* original d207, guest PC 0x0c042460 */
if(!s->budget--) { s->failed_pc=0x0c042460u; return 0; }
r[2]=read(ram,0x0c042480u,4);
goto P_0c042462;
P_0c042462: /* original e303, guest PC 0x0c042462 */
if(!s->budget--) { s->failed_pc=0x0c042462u; return 0; }
r[3]=0x00000003u;
goto P_0c042464;
P_0c042464: /* original 2439, guest PC 0x0c042464 */
if(!s->budget--) { s->failed_pc=0x0c042464u; return 0; }
r[4]&=r[3];
goto P_0c042466;
P_0c042466: /* original 2539, guest PC 0x0c042466 */
if(!s->budget--) { s->failed_pc=0x0c042466u; return 0; }
r[5]&=r[3];
goto P_0c042468;
P_0c042468: /* original 2240, guest PC 0x0c042468 */
if(!s->budget--) { s->failed_pc=0x0c042468u; return 0; }
write(ram,r[2],r[4],1);
goto P_0c04246a;
P_0c04246a: /* original d106, guest PC 0x0c04246a */
if(!s->budget--) { s->failed_pc=0x0c04246au; return 0; }
r[1]=read(ram,0x0c042484u,4);
goto P_0c04246c;
P_0c04246c: /* original 000b, guest PC 0x0c04246c */
if(!s->budget--) { s->failed_pc=0x0c04246cu; return 0; }
target=r[16];
write(ram,r[1],r[5],1);
s->pc=target; return ram->oob==0;
P_0c04246e: /* original 2150, guest PC 0x0c04246e */
if(!s->budget--) { s->failed_pc=0x0c04246eu; return 0; }
write(ram,r[1],r[5],1);
if(!vf3_matrix_family(0x0c042470u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042470u; return 0; } return 1;
P_0c042490: /* original d30a, guest PC 0x0c042490 */
if(!s->budget--) { s->failed_pc=0x0c042490u; return 0; }
r[3]=read(ram,0x0c0424bcu,4);
goto P_0c042492;
P_0c042492: /* original d20b, guest PC 0x0c042492 */
if(!s->budget--) { s->failed_pc=0x0c042492u; return 0; }
r[2]=read(ram,0x0c0424c0u,4);
goto P_0c042494;
P_0c042494: /* original 6530, guest PC 0x0c042494 */
if(!s->budget--) { s->failed_pc=0x0c042494u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[5]=tmp;
goto P_0c042496;
P_0c042496: /* original d10b, guest PC 0x0c042496 */
if(!s->budget--) { s->failed_pc=0x0c042496u; return 0; }
r[1]=read(ram,0x0c0424c4u,4);
goto P_0c042498;
P_0c042498: /* original 4f12, guest PC 0x0c042498 */
if(!s->budget--) { s->failed_pc=0x0c042498u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04249a;
P_0c04249a: /* original 0527, guest PC 0x0c04249a */
if(!s->budget--) { s->failed_pc=0x0c04249au; return 0; }
r[19]=r[5]*r[2];
goto P_0c04249c;
P_0c04249c: /* original 6412, guest PC 0x0c04249c */
if(!s->budget--) { s->failed_pc=0x0c04249cu; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c04249e;
P_0c04249e: /* original 2448, guest PC 0x0c04249e */
if(!s->budget--) { s->failed_pc=0x0c04249eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0424a0;
P_0c0424a0: /* original 8d08, guest PC 0x0c0424a0 */
if(!s->budget--) { s->failed_pc=0x0c0424a0u; return 0; }
cond=r[17]&1u;
r[5]=r[19];
if(cond) { goto P_0c0424b4; }
goto P_0c0424a4;
P_0c0424a2: /* original 051a, guest PC 0x0c0424a2 */
if(!s->budget--) { s->failed_pc=0x0c0424a2u; return 0; }
r[5]=r[19];
goto P_0c0424a4;
P_0c0424a4: /* original 9608, guest PC 0x0c0424a4 */
if(!s->budget--) { s->failed_pc=0x0c0424a4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0424b8u,2);
goto P_0c0424a6;
P_0c0424a6: /* original 364c, guest PC 0x0c0424a6 */
if(!s->budget--) { s->failed_pc=0x0c0424a6u; return 0; }
r[6]+=r[4];
goto P_0c0424a8;
P_0c0424a8: /* original d407, guest PC 0x0c0424a8 */
if(!s->budget--) { s->failed_pc=0x0c0424a8u; return 0; }
r[4]=read(ram,0x0c0424c8u,4);
goto P_0c0424aa;
P_0c0424aa: /* original 74ff, guest PC 0x0c0424aa */
if(!s->budget--) { s->failed_pc=0x0c0424aau; return 0; }
r[4]+=0xffffffffu;
goto P_0c0424ac;
P_0c0424ac: /* original 2652, guest PC 0x0c0424ac */
if(!s->budget--) { s->failed_pc=0x0c0424acu; return 0; }
write(ram,r[6],r[5],4);
goto P_0c0424ae;
P_0c0424ae: /* original 4411, guest PC 0x0c0424ae */
if(!s->budget--) { s->failed_pc=0x0c0424aeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0424b0;
P_0c0424b0: /* original 8dfb, guest PC 0x0c0424b0 */
if(!s->budget--) { s->failed_pc=0x0c0424b0u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000004u;
if(cond) { goto P_0c0424aa; }
goto P_0c0424b4;
P_0c0424b2: /* original 7604, guest PC 0x0c0424b2 */
if(!s->budget--) { s->failed_pc=0x0c0424b2u; return 0; }
r[6]+=0x00000004u;
goto P_0c0424b4;
P_0c0424b4: /* original 000b, guest PC 0x0c0424b4 */
if(!s->budget--) { s->failed_pc=0x0c0424b4u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c0424b6: /* original 4f16, guest PC 0x0c0424b6 */
if(!s->budget--) { s->failed_pc=0x0c0424b6u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c0424b8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0424b8u; return 0; } return 1;
P_0c0425f0: /* original d316, guest PC 0x0c0425f0 */
if(!s->budget--) { s->failed_pc=0x0c0425f0u; return 0; }
r[3]=read(ram,0x0c04264cu,4);
goto P_0c0425f2;
P_0c0425f2: /* original 2342, guest PC 0x0c0425f2 */
if(!s->budget--) { s->failed_pc=0x0c0425f2u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0425f4;
P_0c0425f4: /* original d216, guest PC 0x0c0425f4 */
if(!s->budget--) { s->failed_pc=0x0c0425f4u; return 0; }
r[2]=read(ram,0x0c042650u,4);
goto P_0c0425f6;
P_0c0425f6: /* original 2242, guest PC 0x0c0425f6 */
if(!s->budget--) { s->failed_pc=0x0c0425f6u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c0425f8;
P_0c0425f8: /* original d116, guest PC 0x0c0425f8 */
if(!s->budget--) { s->failed_pc=0x0c0425f8u; return 0; }
r[1]=read(ram,0x0c042654u,4);
goto P_0c0425fa;
P_0c0425fa: /* original 000b, guest PC 0x0c0425fa */
if(!s->budget--) { s->failed_pc=0x0c0425fau; return 0; }
target=r[16];
write(ram,r[1],r[5],4);
s->pc=target; return ram->oob==0;
P_0c0425fc: /* original 2152, guest PC 0x0c0425fc */
if(!s->budget--) { s->failed_pc=0x0c0425fcu; return 0; }
write(ram,r[1],r[5],4);
if(!vf3_matrix_family(0x0c0425feu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0425feu; return 0; } return 1;
P_0c042660: /* original 2fe6, guest PC 0x0c042660 */
if(!s->budget--) { s->failed_pc=0x0c042660u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042662;
P_0c042662: /* original 6e43, guest PC 0x0c042662 */
if(!s->budget--) { s->failed_pc=0x0c042662u; return 0; }
r[14]=r[4];
goto P_0c042664;
P_0c042664: /* original 2fd6, guest PC 0x0c042664 */
if(!s->budget--) { s->failed_pc=0x0c042664u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042666;
P_0c042666: /* original e418, guest PC 0x0c042666 */
if(!s->budget--) { s->failed_pc=0x0c042666u; return 0; }
r[4]=0x00000018u;
goto P_0c042668;
P_0c042668: /* original 2fc6, guest PC 0x0c042668 */
if(!s->budget--) { s->failed_pc=0x0c042668u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04266a;
P_0c04266a: /* original 2fb6, guest PC 0x0c04266a */
if(!s->budget--) { s->failed_pc=0x0c04266au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04266c;
P_0c04266c: /* original 2fa6, guest PC 0x0c04266c */
if(!s->budget--) { s->failed_pc=0x0c04266cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04266e;
P_0c04266e: /* original 2f96, guest PC 0x0c04266e */
if(!s->budget--) { s->failed_pc=0x0c04266eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042670;
P_0c042670: /* original 2f86, guest PC 0x0c042670 */
if(!s->budget--) { s->failed_pc=0x0c042670u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042672;
P_0c042672: /* original 4f22, guest PC 0x0c042672 */
if(!s->budget--) { s->failed_pc=0x0c042672u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c042674;
P_0c042674: /* original 7fa4, guest PC 0x0c042674 */
if(!s->budget--) { s->failed_pc=0x0c042674u; return 0; }
r[15]+=0xffffffa4u;
goto P_0c042676;
P_0c042676: /* original 6df3, guest PC 0x0c042676 */
if(!s->budget--) { s->failed_pc=0x0c042676u; return 0; }
r[13]=r[15];
goto P_0c042678;
P_0c042678: /* original 7d58, guest PC 0x0c042678 */
if(!s->budget--) { s->failed_pc=0x0c042678u; return 0; }
r[13]+=0x00000058u;
goto P_0c04267a;
P_0c04267a: /* original 6043, guest PC 0x0c04267a */
if(!s->budget--) { s->failed_pc=0x0c04267au; return 0; }
r[0]=r[4];
goto P_0c04267c;
P_0c04267c: /* original 0009, guest PC 0x0c04267c */
if(!s->budget--) { s->failed_pc=0x0c04267cu; return 0; }
goto P_0c04267e;
P_0c04267e: /* original 80d1, guest PC 0x0c04267e */
if(!s->budget--) { s->failed_pc=0x0c04267eu; return 0; }
write(ram,r[13]+1,r[0],1);
goto P_0c042680;
P_0c042680: /* original 9347, guest PC 0x0c042680 */
if(!s->budget--) { s->failed_pc=0x0c042680u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042712u,2);
goto P_0c042682;
P_0c042682: /* original 3e33, guest PC 0x0c042682 */
if(!s->budget--) { s->failed_pc=0x0c042682u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c042684;
P_0c042684: /* original 8d02, guest PC 0x0c042684 */
if(!s->budget--) { s->failed_pc=0x0c042684u; return 0; }
cond=r[17]&1u;
write(ram,r[13],r[0],1);
if(cond) { goto P_0c04268c; }
goto P_0c042688;
P_0c042686: /* original 2d00, guest PC 0x0c042686 */
if(!s->budget--) { s->failed_pc=0x0c042686u; return 0; }
write(ram,r[13],r[0],1);
goto P_0c042688;
P_0c042688: /* original e10c, guest PC 0x0c042688 */
if(!s->budget--) { s->failed_pc=0x0c042688u; return 0; }
r[1]=0x0000000cu;
goto P_0c04268a;
P_0c04268a: /* original 2d10, guest PC 0x0c04268a */
if(!s->budget--) { s->failed_pc=0x0c04268au; return 0; }
write(ram,r[13],r[1],1);
goto P_0c04268c;
P_0c04268c: /* original d222, guest PC 0x0c04268c */
if(!s->budget--) { s->failed_pc=0x0c04268cu; return 0; }
r[2]=read(ram,0x0c042718u,4);
goto P_0c04268e;
P_0c04268e: /* original 6320, guest PC 0x0c04268e */
if(!s->budget--) { s->failed_pc=0x0c04268eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c042690;
P_0c042690: /* original 1f32, guest PC 0x0c042690 */
if(!s->budget--) { s->failed_pc=0x0c042690u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c042692;
P_0c042692: /* original d323, guest PC 0x0c042692 */
if(!s->budget--) { s->failed_pc=0x0c042692u; return 0; }
r[3]=read(ram,0x0c042720u,4);
goto P_0c042694;
P_0c042694: /* original d121, guest PC 0x0c042694 */
if(!s->budget--) { s->failed_pc=0x0c042694u; return 0; }
r[1]=read(ram,0x0c04271cu,4);
goto P_0c042696;
P_0c042696: /* original 6030, guest PC 0x0c042696 */
if(!s->budget--) { s->failed_pc=0x0c042696u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c042698;
P_0c042698: /* original 8801, guest PC 0x0c042698 */
if(!s->budget--) { s->failed_pc=0x0c042698u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c04269a;
P_0c04269a: /* original 8f01, guest PC 0x0c04269a */
if(!s->budget--) { s->failed_pc=0x0c04269au; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[8]=tmp;
if(!cond) { goto P_0c0426a0; }
goto P_0c04269e;
P_0c04269c: /* original 6810, guest PC 0x0c04269c */
if(!s->budget--) { s->failed_pc=0x0c04269cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[8]=tmp;
goto P_0c04269e;
P_0c04269e: /* original e8ff, guest PC 0x0c04269e */
if(!s->budget--) { s->failed_pc=0x0c04269eu; return 0; }
r[8]=0xffffffffu;
goto P_0c0426a0;
P_0c0426a0: /* original b21e, guest PC 0x0c0426a0 */
if(!s->budget--) { s->failed_pc=0x0c0426a0u; return 0; }
target=code_base|0x0c042ae0u; r[16]=code_base|0x0c0426a4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0426a4u) { target=s->pc; goto dispatch; }
goto P_0c0426a4;
P_0c0426a2: /* original 64e3, guest PC 0x0c0426a2 */
if(!s->budget--) { s->failed_pc=0x0c0426a2u; return 0; }
r[4]=r[14];
goto P_0c0426a4;
P_0c0426a4: /* original d21f, guest PC 0x0c0426a4 */
if(!s->budget--) { s->failed_pc=0x0c0426a4u; return 0; }
r[2]=read(ram,0x0c042724u,4);
goto P_0c0426a6;
P_0c0426a6: /* original d320, guest PC 0x0c0426a6 */
if(!s->budget--) { s->failed_pc=0x0c0426a6u; return 0; }
r[3]=read(ram,0x0c042728u,4);
goto P_0c0426a8;
P_0c0426a8: /* original 6c22, guest PC 0x0c0426a8 */
if(!s->budget--) { s->failed_pc=0x0c0426a8u; return 0; }
tmp=read(ram,r[2],4);
r[12]=tmp;
goto P_0c0426aa;
P_0c0426aa: /* original 430b, guest PC 0x0c0426aa */
if(!s->budget--) { s->failed_pc=0x0c0426aau; return 0; }
target=r[3];
r[16]=code_base|0x0c0426aeu;
r[12]+=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0426aeu) { target=s->pc; goto dispatch; }
goto P_0c0426ae;
P_0c0426ac: /* original 3c0c, guest PC 0x0c0426ac */
if(!s->budget--) { s->failed_pc=0x0c0426acu; return 0; }
r[12]+=r[0];
goto P_0c0426ae;
P_0c0426ae: /* original 2008, guest PC 0x0c0426ae */
if(!s->budget--) { s->failed_pc=0x0c0426aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0426b0;
P_0c0426b0: /* original 8b5a, guest PC 0x0c0426b0 */
if(!s->budget--) { s->failed_pc=0x0c0426b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042768; }
goto P_0c0426b2;
P_0c0426b2: /* original 932e, guest PC 0x0c0426b2 */
if(!s->budget--) { s->failed_pc=0x0c0426b2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042712u,2);
goto P_0c0426b4;
P_0c0426b4: /* original 3e33, guest PC 0x0c0426b4 */
if(!s->budget--) { s->failed_pc=0x0c0426b4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c0426b6;
P_0c0426b6: /* original 8903, guest PC 0x0c0426b6 */
if(!s->budget--) { s->failed_pc=0x0c0426b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0426c0; }
goto P_0c0426b8;
P_0c0426b8: /* original a003, guest PC 0x0c0426b8 */
if(!s->budget--) { s->failed_pc=0x0c0426b8u; return 0; }
r[4]=0x00000024u;
goto P_0c0426c2;
P_0c0426ba: /* original e424, guest PC 0x0c0426ba */
if(!s->budget--) { s->failed_pc=0x0c0426bau; return 0; }
r[4]=0x00000024u;
if(!vf3_matrix_family(0x0c0426bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0426bcu; return 0; } return 1;
P_0c0426c0: /* original e448, guest PC 0x0c0426c0 */
if(!s->budget--) { s->failed_pc=0x0c0426c0u; return 0; }
r[4]=0x00000048u;
goto P_0c0426c2;
P_0c0426c2: /* original 65f3, guest PC 0x0c0426c2 */
if(!s->budget--) { s->failed_pc=0x0c0426c2u; return 0; }
r[5]=r[15];
goto P_0c0426c4;
P_0c0426c4: /* original a007, guest PC 0x0c0426c4 */
if(!s->budget--) { s->failed_pc=0x0c0426c4u; return 0; }
r[5]+=0x00000010u;
goto P_0c0426d6;
P_0c0426c6: /* original 7510, guest PC 0x0c0426c6 */
if(!s->budget--) { s->failed_pc=0x0c0426c6u; return 0; }
r[5]+=0x00000010u;
if(!vf3_matrix_family(0x0c0426c8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0426c8u; return 0; } return 1;
P_0c0426d0: /* original 63c4, guest PC 0x0c0426d0 */
if(!s->budget--) { s->failed_pc=0x0c0426d0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[12]+=1;
r[3]=tmp;
goto P_0c0426d2;
P_0c0426d2: /* original 2530, guest PC 0x0c0426d2 */
if(!s->budget--) { s->failed_pc=0x0c0426d2u; return 0; }
write(ram,r[5],r[3],1);
goto P_0c0426d4;
P_0c0426d4: /* original 7501, guest PC 0x0c0426d4 */
if(!s->budget--) { s->failed_pc=0x0c0426d4u; return 0; }
r[5]+=0x00000001u;
goto P_0c0426d6;
P_0c0426d6: /* original 4415, guest PC 0x0c0426d6 */
if(!s->budget--) { s->failed_pc=0x0c0426d6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0426d8;
P_0c0426d8: /* original 8dfa, guest PC 0x0c0426d8 */
if(!s->budget--) { s->failed_pc=0x0c0426d8u; return 0; }
cond=r[17]&1u;
r[4]+=0xffffffffu;
if(cond) { goto P_0c0426d0; }
goto P_0c0426dc;
P_0c0426da: /* original 74ff, guest PC 0x0c0426da */
if(!s->budget--) { s->failed_pc=0x0c0426dau; return 0; }
r[4]+=0xffffffffu;
goto P_0c0426dc;
P_0c0426dc: /* original d213, guest PC 0x0c0426dc */
if(!s->budget--) { s->failed_pc=0x0c0426dcu; return 0; }
r[2]=read(ram,0x0c04272cu,4);
goto P_0c0426de;
P_0c0426de: /* original 420b, guest PC 0x0c0426de */
if(!s->budget--) { s->failed_pc=0x0c0426deu; return 0; }
target=r[2];
r[16]=code_base|0x0c0426e2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0426e2u) { target=s->pc; goto dispatch; }
goto P_0c0426e2;
P_0c0426e0: /* original 0009, guest PC 0x0c0426e0 */
if(!s->budget--) { s->failed_pc=0x0c0426e0u; return 0; }
goto P_0c0426e2;
P_0c0426e2: /* original 63f3, guest PC 0x0c0426e2 */
if(!s->budget--) { s->failed_pc=0x0c0426e2u; return 0; }
r[3]=r[15];
goto P_0c0426e4;
P_0c0426e4: /* original 7310, guest PC 0x0c0426e4 */
if(!s->budget--) { s->failed_pc=0x0c0426e4u; return 0; }
r[3]+=0x00000010u;
goto P_0c0426e6;
P_0c0426e6: /* original 1f33, guest PC 0x0c0426e6 */
if(!s->budget--) { s->failed_pc=0x0c0426e6u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0426e8;
P_0c0426e8: /* original e900, guest PC 0x0c0426e8 */
if(!s->budget--) { s->failed_pc=0x0c0426e8u; return 0; }
r[9]=0x00000000u;
goto P_0c0426ea;
P_0c0426ea: /* original d111, guest PC 0x0c0426ea */
if(!s->budget--) { s->failed_pc=0x0c0426eau; return 0; }
r[1]=read(ram,0x0c042730u,4);
goto P_0c0426ec;
P_0c0426ec: /* original 6c93, guest PC 0x0c0426ec */
if(!s->budget--) { s->failed_pc=0x0c0426ecu; return 0; }
r[12]=r[9];
goto P_0c0426ee;
P_0c0426ee: /* original 6e93, guest PC 0x0c0426ee */
if(!s->budget--) { s->failed_pc=0x0c0426eeu; return 0; }
r[14]=r[9];
goto P_0c0426f0;
P_0c0426f0: /* original 6212, guest PC 0x0c0426f0 */
if(!s->budget--) { s->failed_pc=0x0c0426f0u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0426f2;
P_0c0426f2: /* original 2f22, guest PC 0x0c0426f2 */
if(!s->budget--) { s->failed_pc=0x0c0426f2u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0426f4;
P_0c0426f4: /* original d20f, guest PC 0x0c0426f4 */
if(!s->budget--) { s->failed_pc=0x0c0426f4u; return 0; }
r[2]=read(ram,0x0c042734u,4);
goto P_0c0426f6;
P_0c0426f6: /* original 6322, guest PC 0x0c0426f6 */
if(!s->budget--) { s->failed_pc=0x0c0426f6u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0426f8;
P_0c0426f8: /* original 1f31, guest PC 0x0c0426f8 */
if(!s->budget--) { s->failed_pc=0x0c0426f8u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0426fa;
P_0c0426fa: /* original 5bf3, guest PC 0x0c0426fa */
if(!s->budget--) { s->failed_pc=0x0c0426fau; return 0; }
r[11]=read(ram,r[15]+12,4);
goto P_0c0426fc;
P_0c0426fc: /* original ea08, guest PC 0x0c0426fc */
if(!s->budget--) { s->failed_pc=0x0c0426fcu; return 0; }
r[10]=0x00000008u;
goto P_0c0426fe;
P_0c0426fe: /* original 7b01, guest PC 0x0c0426fe */
if(!s->budget--) { s->failed_pc=0x0c0426feu; return 0; }
r[11]+=0x00000001u;
goto P_0c042700;
P_0c042700: /* original 1fb3, guest PC 0x0c042700 */
if(!s->budget--) { s->failed_pc=0x0c042700u; return 0; }
write(ram,r[15]+12,r[11],4);
goto P_0c042702;
P_0c042702: /* original 7bff, guest PC 0x0c042702 */
if(!s->budget--) { s->failed_pc=0x0c042702u; return 0; }
r[11]+=0xffffffffu;
goto P_0c042704;
P_0c042704: /* original 6bb0, guest PC 0x0c042704 */
if(!s->budget--) { s->failed_pc=0x0c042704u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[11],1);
r[11]=tmp;
goto P_0c042706;
P_0c042706: /* original 9605, guest PC 0x0c042706 */
if(!s->budget--) { s->failed_pc=0x0c042706u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042714u,2);
goto P_0c042708;
P_0c042708: /* original 60bc, guest PC 0x0c042708 */
if(!s->budget--) { s->failed_pc=0x0c042708u; return 0; }
r[0]=r[11]&255u;
goto P_0c04270a;
P_0c04270a: /* original 2608, guest PC 0x0c04270a */
if(!s->budget--) { s->failed_pc=0x0c04270au; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[0])==0)!=0);
goto P_0c04270c;
P_0c04270c: /* original 8918, guest PC 0x0c04270c */
if(!s->budget--) { s->failed_pc=0x0c04270cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042740; }
goto P_0c04270e;
P_0c04270e: /* original a018, guest PC 0x0c04270e */
if(!s->budget--) { s->failed_pc=0x0c04270eu; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c042742;
P_0c042710: /* original 56f2, guest PC 0x0c042710 */
if(!s->budget--) { s->failed_pc=0x0c042710u; return 0; }
r[6]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(0x0c042712u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042712u; return 0; } return 1;
P_0c042740: /* original 6683, guest PC 0x0c042740 */
if(!s->budget--) { s->failed_pc=0x0c042740u; return 0; }
r[6]=r[8];
goto P_0c042742;
P_0c042742: /* original 55f1, guest PC 0x0c042742 */
if(!s->budget--) { s->failed_pc=0x0c042742u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c042744;
P_0c042744: /* original 64f2, guest PC 0x0c042744 */
if(!s->budget--) { s->failed_pc=0x0c042744u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c042746;
P_0c042746: /* original 35cc, guest PC 0x0c042746 */
if(!s->budget--) { s->failed_pc=0x0c042746u; return 0; }
r[5]+=r[12];
goto P_0c042748;
P_0c042748: /* original b132, guest PC 0x0c042748 */
if(!s->budget--) { s->failed_pc=0x0c042748u; return 0; }
target=code_base|0x0c0429b0u; r[16]=code_base|0x0c04274cu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04274cu) { target=s->pc; goto dispatch; }
goto P_0c04274c;
P_0c04274a: /* original 34ec, guest PC 0x0c04274a */
if(!s->budget--) { s->failed_pc=0x0c04274au; return 0; }
r[4]+=r[14];
goto P_0c04274c;
P_0c04274c: /* original 62d0, guest PC 0x0c04274c */
if(!s->budget--) { s->failed_pc=0x0c04274cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[2]=tmp;
goto P_0c04274e;
P_0c04274e: /* original 7e01, guest PC 0x0c04274e */
if(!s->budget--) { s->failed_pc=0x0c04274eu; return 0; }
r[14]+=0x00000001u;
goto P_0c042750;
P_0c042750: /* original 4b00, guest PC 0x0c042750 */
if(!s->budget--) { s->failed_pc=0x0c042750u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c042752;
P_0c042752: /* original 622c, guest PC 0x0c042752 */
if(!s->budget--) { s->failed_pc=0x0c042752u; return 0; }
r[2]=r[2]&255u;
goto P_0c042754;
P_0c042754: /* original 3e23, guest PC 0x0c042754 */
if(!s->budget--) { s->failed_pc=0x0c042754u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c042756;
P_0c042756: /* original 8b01, guest PC 0x0c042756 */
if(!s->budget--) { s->failed_pc=0x0c042756u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04275c; }
goto P_0c042758;
P_0c042758: /* original 7c01, guest PC 0x0c042758 */
if(!s->budget--) { s->failed_pc=0x0c042758u; return 0; }
r[12]+=0x00000001u;
goto P_0c04275a;
P_0c04275a: /* original 6e93, guest PC 0x0c04275a */
if(!s->budget--) { s->failed_pc=0x0c04275au; return 0; }
r[14]=r[9];
goto P_0c04275c;
P_0c04275c: /* original 4a10, guest PC 0x0c04275c */
if(!s->budget--) { s->failed_pc=0x0c04275cu; return 0; }
--r[10];
r[17]=(r[17]&~1u)|((r[10]==0)!=0);
goto P_0c04275e;
P_0c04275e: /* original 8bd2, guest PC 0x0c04275e */
if(!s->budget--) { s->failed_pc=0x0c04275eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042706; }
goto P_0c042760;
P_0c042760: /* original 84d1, guest PC 0x0c042760 */
if(!s->budget--) { s->failed_pc=0x0c042760u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+1,1);
goto P_0c042762;
P_0c042762: /* original 600c, guest PC 0x0c042762 */
if(!s->budget--) { s->failed_pc=0x0c042762u; return 0; }
r[0]=r[0]&255u;
goto P_0c042764;
P_0c042764: /* original 3c03, guest PC 0x0c042764 */
if(!s->budget--) { s->failed_pc=0x0c042764u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[0])!=0);
goto P_0c042766;
P_0c042766: /* original 8bc8, guest PC 0x0c042766 */
if(!s->budget--) { s->failed_pc=0x0c042766u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0426fa; }
goto P_0c042768;
P_0c042768: /* original 7f5c, guest PC 0x0c042768 */
if(!s->budget--) { s->failed_pc=0x0c042768u; return 0; }
r[15]+=0x0000005cu;
goto P_0c04276a;
P_0c04276a: /* original d230, guest PC 0x0c04276a */
if(!s->budget--) { s->failed_pc=0x0c04276au; return 0; }
r[2]=read(ram,0x0c04282cu,4);
goto P_0c04276c;
P_0c04276c: /* original 4f26, guest PC 0x0c04276c */
if(!s->budget--) { s->failed_pc=0x0c04276cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04276e;
P_0c04276e: /* original 63d0, guest PC 0x0c04276e */
if(!s->budget--) { s->failed_pc=0x0c04276eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[3]=tmp;
goto P_0c042770;
P_0c042770: /* original 6122, guest PC 0x0c042770 */
if(!s->budget--) { s->failed_pc=0x0c042770u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c042772;
P_0c042772: /* original 633c, guest PC 0x0c042772 */
if(!s->budget--) { s->failed_pc=0x0c042772u; return 0; }
r[3]=r[3]&255u;
goto P_0c042774;
P_0c042774: /* original 313c, guest PC 0x0c042774 */
if(!s->budget--) { s->failed_pc=0x0c042774u; return 0; }
r[1]+=r[3];
goto P_0c042776;
P_0c042776: /* original 2212, guest PC 0x0c042776 */
if(!s->budget--) { s->failed_pc=0x0c042776u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c042778;
P_0c042778: /* original 68f6, guest PC 0x0c042778 */
if(!s->budget--) { s->failed_pc=0x0c042778u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04277a;
P_0c04277a: /* original 69f6, guest PC 0x0c04277a */
if(!s->budget--) { s->failed_pc=0x0c04277au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04277c;
P_0c04277c: /* original 6af6, guest PC 0x0c04277c */
if(!s->budget--) { s->failed_pc=0x0c04277cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04277e;
P_0c04277e: /* original 6bf6, guest PC 0x0c04277e */
if(!s->budget--) { s->failed_pc=0x0c04277eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c042780;
P_0c042780: /* original 6cf6, guest PC 0x0c042780 */
if(!s->budget--) { s->failed_pc=0x0c042780u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c042782;
P_0c042782: /* original 6df6, guest PC 0x0c042782 */
if(!s->budget--) { s->failed_pc=0x0c042782u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c042784;
P_0c042784: /* original 000b, guest PC 0x0c042784 */
if(!s->budget--) { s->failed_pc=0x0c042784u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c042786: /* original 6ef6, guest PC 0x0c042786 */
if(!s->budget--) { s->failed_pc=0x0c042786u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c042788u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042788u; return 0; } return 1;
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
unsupported: s->failed_pc=target; return 0;
}
