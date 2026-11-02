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
int vf3_away_batch262_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08675eu: goto P_0c08675e;
case 0x0c086760u: goto P_0c086760;
case 0x0c086762u: goto P_0c086762;
case 0x0c086764u: goto P_0c086764;
case 0x0c086766u: goto P_0c086766;
case 0x0c086768u: goto P_0c086768;
case 0x0c08676au: goto P_0c08676a;
case 0x0c08676cu: goto P_0c08676c;
case 0x0c08676eu: goto P_0c08676e;
case 0x0c086770u: goto P_0c086770;
case 0x0c086772u: goto P_0c086772;
case 0x0c086774u: goto P_0c086774;
case 0x0c086776u: goto P_0c086776;
case 0x0c086778u: goto P_0c086778;
case 0x0c08677au: goto P_0c08677a;
case 0x0c08677cu: goto P_0c08677c;
case 0x0c08677eu: goto P_0c08677e;
case 0x0c086780u: goto P_0c086780;
case 0x0c086782u: goto P_0c086782;
case 0x0c086784u: goto P_0c086784;
case 0x0c086786u: goto P_0c086786;
case 0x0c086788u: goto P_0c086788;
case 0x0c08678au: goto P_0c08678a;
case 0x0c08678cu: goto P_0c08678c;
case 0x0c08678eu: goto P_0c08678e;
case 0x0c086790u: goto P_0c086790;
case 0x0c086792u: goto P_0c086792;
case 0x0c086794u: goto P_0c086794;
case 0x0c086796u: goto P_0c086796;
case 0x0c086798u: goto P_0c086798;
case 0x0c08679au: goto P_0c08679a;
case 0x0c08679cu: goto P_0c08679c;
case 0x0c08679eu: goto P_0c08679e;
case 0x0c0867a0u: goto P_0c0867a0;
case 0x0c0867a2u: goto P_0c0867a2;
case 0x0c0867a4u: goto P_0c0867a4;
case 0x0c0867a6u: goto P_0c0867a6;
case 0x0c0867a8u: goto P_0c0867a8;
case 0x0c0867aau: goto P_0c0867aa;
case 0x0c0867acu: goto P_0c0867ac;
case 0x0c0867aeu: goto P_0c0867ae;
case 0x0c0867b0u: goto P_0c0867b0;
case 0x0c0867b2u: goto P_0c0867b2;
case 0x0c0867b4u: goto P_0c0867b4;
case 0x0c0867b6u: goto P_0c0867b6;
case 0x0c0867b8u: goto P_0c0867b8;
case 0x0c0867d0u: goto P_0c0867d0;
case 0x0c0867d2u: goto P_0c0867d2;
case 0x0c0867d4u: goto P_0c0867d4;
case 0x0c0867d6u: goto P_0c0867d6;
case 0x0c0867d8u: goto P_0c0867d8;
case 0x0c0867dau: goto P_0c0867da;
case 0x0c0867dcu: goto P_0c0867dc;
case 0x0c0867deu: goto P_0c0867de;
case 0x0c0867e0u: goto P_0c0867e0;
case 0x0c0867e2u: goto P_0c0867e2;
case 0x0c0867e4u: goto P_0c0867e4;
case 0x0c0867e6u: goto P_0c0867e6;
case 0x0c0867e8u: goto P_0c0867e8;
case 0x0c0867eau: goto P_0c0867ea;
case 0x0c0867ecu: goto P_0c0867ec;
case 0x0c0867eeu: goto P_0c0867ee;
case 0x0c0867f0u: goto P_0c0867f0;
case 0x0c0867f2u: goto P_0c0867f2;
case 0x0c0867f4u: goto P_0c0867f4;
case 0x0c0867f6u: goto P_0c0867f6;
case 0x0c0867f8u: goto P_0c0867f8;
case 0x0c0867fau: goto P_0c0867fa;
case 0x0c0867fcu: goto P_0c0867fc;
case 0x0c0867feu: goto P_0c0867fe;
case 0x0c086800u: goto P_0c086800;
case 0x0c086802u: goto P_0c086802;
case 0x0c086804u: goto P_0c086804;
case 0x0c086806u: goto P_0c086806;
case 0x0c086808u: goto P_0c086808;
case 0x0c08680au: goto P_0c08680a;
case 0x0c08680cu: goto P_0c08680c;
case 0x0c08680eu: goto P_0c08680e;
case 0x0c086810u: goto P_0c086810;
case 0x0c086812u: goto P_0c086812;
case 0x0c086814u: goto P_0c086814;
case 0x0c086816u: goto P_0c086816;
case 0x0c086818u: goto P_0c086818;
case 0x0c08681au: goto P_0c08681a;
case 0x0c08681cu: goto P_0c08681c;
case 0x0c08681eu: goto P_0c08681e;
case 0x0c086820u: goto P_0c086820;
case 0x0c086822u: goto P_0c086822;
case 0x0c086824u: goto P_0c086824;
case 0x0c086826u: goto P_0c086826;
case 0x0c086828u: goto P_0c086828;
case 0x0c08682au: goto P_0c08682a;
case 0x0c08682cu: goto P_0c08682c;
case 0x0c08682eu: goto P_0c08682e;
case 0x0c086830u: goto P_0c086830;
case 0x0c086832u: goto P_0c086832;
case 0x0c086834u: goto P_0c086834;
case 0x0c086836u: goto P_0c086836;
case 0x0c086838u: goto P_0c086838;
case 0x0c08683au: goto P_0c08683a;
case 0x0c08683cu: goto P_0c08683c;
case 0x0c08683eu: goto P_0c08683e;
case 0x0c086840u: goto P_0c086840;
case 0x0c086842u: goto P_0c086842;
case 0x0c086844u: goto P_0c086844;
case 0x0c086846u: goto P_0c086846;
case 0x0c086848u: goto P_0c086848;
case 0x0c08684au: goto P_0c08684a;
case 0x0c08684cu: goto P_0c08684c;
case 0x0c08684eu: goto P_0c08684e;
case 0x0c086850u: goto P_0c086850;
case 0x0c086852u: goto P_0c086852;
case 0x0c086854u: goto P_0c086854;
case 0x0c086856u: goto P_0c086856;
case 0x0c086858u: goto P_0c086858;
case 0x0c08685au: goto P_0c08685a;
case 0x0c08685cu: goto P_0c08685c;
case 0x0c08685eu: goto P_0c08685e;
case 0x0c086860u: goto P_0c086860;
case 0x0c086862u: goto P_0c086862;
case 0x0c086864u: goto P_0c086864;
case 0x0c086866u: goto P_0c086866;
case 0x0c086868u: goto P_0c086868;
case 0x0c08686au: goto P_0c08686a;
case 0x0c08686cu: goto P_0c08686c;
case 0x0c08686eu: goto P_0c08686e;
case 0x0c086870u: goto P_0c086870;
case 0x0c086872u: goto P_0c086872;
case 0x0c086874u: goto P_0c086874;
case 0x0c086876u: goto P_0c086876;
case 0x0c086878u: goto P_0c086878;
case 0x0c08687au: goto P_0c08687a;
case 0x0c08687cu: goto P_0c08687c;
case 0x0c08687eu: goto P_0c08687e;
case 0x0c086880u: goto P_0c086880;
case 0x0c086882u: goto P_0c086882;
case 0x0c086884u: goto P_0c086884;
case 0x0c086886u: goto P_0c086886;
case 0x0c086888u: goto P_0c086888;
case 0x0c08688au: goto P_0c08688a;
case 0x0c08688cu: goto P_0c08688c;
case 0x0c08688eu: goto P_0c08688e;
case 0x0c086890u: goto P_0c086890;
case 0x0c086892u: goto P_0c086892;
case 0x0c086894u: goto P_0c086894;
case 0x0c086896u: goto P_0c086896;
case 0x0c086898u: goto P_0c086898;
case 0x0c08689au: goto P_0c08689a;
case 0x0c08689cu: goto P_0c08689c;
case 0x0c08689eu: goto P_0c08689e;
case 0x0c0868a0u: goto P_0c0868a0;
case 0x0c0868a2u: goto P_0c0868a2;
case 0x0c0868a4u: goto P_0c0868a4;
case 0x0c0868a6u: goto P_0c0868a6;
case 0x0c0868a8u: goto P_0c0868a8;
case 0x0c0868aau: goto P_0c0868aa;
case 0x0c0868acu: goto P_0c0868ac;
case 0x0c0868aeu: goto P_0c0868ae;
case 0x0c0868b0u: goto P_0c0868b0;
case 0x0c0868b2u: goto P_0c0868b2;
case 0x0c0868b4u: goto P_0c0868b4;
case 0x0c0868b6u: goto P_0c0868b6;
case 0x0c0868b8u: goto P_0c0868b8;
case 0x0c0868bau: goto P_0c0868ba;
case 0x0c0868bcu: goto P_0c0868bc;
case 0x0c0868beu: goto P_0c0868be;
case 0x0c0868c0u: goto P_0c0868c0;
case 0x0c0868c2u: goto P_0c0868c2;
case 0x0c0868c4u: goto P_0c0868c4;
case 0x0c0868c6u: goto P_0c0868c6;
case 0x0c0868c8u: goto P_0c0868c8;
case 0x0c0868cau: goto P_0c0868ca;
case 0x0c0868ccu: goto P_0c0868cc;
case 0x0c0868ceu: goto P_0c0868ce;
case 0x0c0868d0u: goto P_0c0868d0;
case 0x0c0868d2u: goto P_0c0868d2;
case 0x0c0868d4u: goto P_0c0868d4;
case 0x0c0868d6u: goto P_0c0868d6;
case 0x0c0868d8u: goto P_0c0868d8;
case 0x0c0868dau: goto P_0c0868da;
case 0x0c0868dcu: goto P_0c0868dc;
case 0x0c0868deu: goto P_0c0868de;
case 0x0c0868e0u: goto P_0c0868e0;
case 0x0c0868e2u: goto P_0c0868e2;
case 0x0c0868e4u: goto P_0c0868e4;
case 0x0c0868e6u: goto P_0c0868e6;
case 0x0c0868e8u: goto P_0c0868e8;
case 0x0c0868eau: goto P_0c0868ea;
case 0x0c0868ecu: goto P_0c0868ec;
case 0x0c0868eeu: goto P_0c0868ee;
case 0x0c0868f0u: goto P_0c0868f0;
case 0x0c086910u: goto P_0c086910;
case 0x0c086912u: goto P_0c086912;
case 0x0c086914u: goto P_0c086914;
case 0x0c086916u: goto P_0c086916;
case 0x0c086918u: goto P_0c086918;
case 0x0c08691au: goto P_0c08691a;
case 0x0c08691cu: goto P_0c08691c;
case 0x0c08691eu: goto P_0c08691e;
case 0x0c086920u: goto P_0c086920;
case 0x0c086922u: goto P_0c086922;
case 0x0c086924u: goto P_0c086924;
case 0x0c086926u: goto P_0c086926;
case 0x0c086928u: goto P_0c086928;
case 0x0c08692au: goto P_0c08692a;
case 0x0c08692cu: goto P_0c08692c;
case 0x0c08692eu: goto P_0c08692e;
case 0x0c086930u: goto P_0c086930;
case 0x0c086932u: goto P_0c086932;
case 0x0c086934u: goto P_0c086934;
case 0x0c086936u: goto P_0c086936;
case 0x0c086938u: goto P_0c086938;
case 0x0c08693au: goto P_0c08693a;
case 0x0c08693cu: goto P_0c08693c;
case 0x0c08693eu: goto P_0c08693e;
case 0x0c086940u: goto P_0c086940;
case 0x0c086942u: goto P_0c086942;
case 0x0c086944u: goto P_0c086944;
case 0x0c086946u: goto P_0c086946;
case 0x0c086948u: goto P_0c086948;
case 0x0c08694au: goto P_0c08694a;
case 0x0c08694cu: goto P_0c08694c;
case 0x0c08694eu: goto P_0c08694e;
case 0x0c086950u: goto P_0c086950;
case 0x0c086952u: goto P_0c086952;
case 0x0c086954u: goto P_0c086954;
case 0x0c086956u: goto P_0c086956;
case 0x0c086958u: goto P_0c086958;
case 0x0c08695au: goto P_0c08695a;
case 0x0c08695cu: goto P_0c08695c;
case 0x0c08695eu: goto P_0c08695e;
case 0x0c086960u: goto P_0c086960;
case 0x0c086962u: goto P_0c086962;
case 0x0c086964u: goto P_0c086964;
case 0x0c086966u: goto P_0c086966;
case 0x0c086968u: goto P_0c086968;
case 0x0c08696au: goto P_0c08696a;
case 0x0c08696cu: goto P_0c08696c;
case 0x0c08696eu: goto P_0c08696e;
case 0x0c086970u: goto P_0c086970;
case 0x0c086972u: goto P_0c086972;
case 0x0c086974u: goto P_0c086974;
case 0x0c086976u: goto P_0c086976;
case 0x0c086978u: goto P_0c086978;
case 0x0c08697au: goto P_0c08697a;
case 0x0c08697cu: goto P_0c08697c;
case 0x0c08697eu: goto P_0c08697e;
case 0x0c086980u: goto P_0c086980;
case 0x0c086982u: goto P_0c086982;
case 0x0c086984u: goto P_0c086984;
case 0x0c086986u: goto P_0c086986;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08675e: /* original e028, guest PC 0x0c08675e */
if(!s->budget--) { s->failed_pc=0x0c08675eu; return 0; }
r[0]=0x00000028u;
goto P_0c086760;
P_0c086760: /* original 6453, guest PC 0x0c086760 */
if(!s->budget--) { s->failed_pc=0x0c086760u; return 0; }
r[4]=r[5];
goto P_0c086762;
P_0c086762: /* original 034d, guest PC 0x0c086762 */
if(!s->budget--) { s->failed_pc=0x0c086762u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c086764;
P_0c086764: /* original e034, guest PC 0x0c086764 */
if(!s->budget--) { s->failed_pc=0x0c086764u; return 0; }
r[0]=0x00000034u;
goto P_0c086766;
P_0c086766: /* original 064d, guest PC 0x0c086766 */
if(!s->budget--) { s->failed_pc=0x0c086766u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c086768;
P_0c086768: /* original 3638, guest PC 0x0c086768 */
if(!s->budget--) { s->failed_pc=0x0c086768u; return 0; }
r[6]-=r[3];
goto P_0c08676a;
P_0c08676a: /* original 626f, guest PC 0x0c08676a */
if(!s->budget--) { s->failed_pc=0x0c08676au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c08676c;
P_0c08676c: /* original 4211, guest PC 0x0c08676c */
if(!s->budget--) { s->failed_pc=0x0c08676cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c08676e;
P_0c08676e: /* original 8900, guest PC 0x0c08676e */
if(!s->budget--) { s->failed_pc=0x0c08676eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086772; }
goto P_0c086770;
P_0c086770: /* original 666b, guest PC 0x0c086770 */
if(!s->budget--) { s->failed_pc=0x0c086770u; return 0; }
r[6]=0u-r[6];
goto P_0c086772;
P_0c086772: /* original 9523, guest PC 0x0c086772 */
if(!s->budget--) { s->failed_pc=0x0c086772u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0867bcu,2);
goto P_0c086774;
P_0c086774: /* original 666f, guest PC 0x0c086774 */
if(!s->budget--) { s->failed_pc=0x0c086774u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c086776;
P_0c086776: /* original 3653, guest PC 0x0c086776 */
if(!s->budget--) { s->failed_pc=0x0c086776u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[5])!=0);
goto P_0c086778;
P_0c086778: /* original 8b07, guest PC 0x0c086778 */
if(!s->budget--) { s->failed_pc=0x0c086778u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08678a; }
goto P_0c08677a;
P_0c08677a: /* original e32e, guest PC 0x0c08677a */
if(!s->budget--) { s->failed_pc=0x0c08677au; return 0; }
r[3]=0x0000002eu;
goto P_0c08677c;
P_0c08677c: /* original 334c, guest PC 0x0c08677c */
if(!s->budget--) { s->failed_pc=0x0c08677cu; return 0; }
r[3]+=r[4];
goto P_0c08677e;
P_0c08677e: /* original e028, guest PC 0x0c08677e */
if(!s->budget--) { s->failed_pc=0x0c08677eu; return 0; }
r[0]=0x00000028u;
goto P_0c086780;
P_0c086780: /* original 6331, guest PC 0x0c086780 */
if(!s->budget--) { s->failed_pc=0x0c086780u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[3]=tmp;
goto P_0c086782;
P_0c086782: /* original 024d, guest PC 0x0c086782 */
if(!s->budget--) { s->failed_pc=0x0c086782u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c086784;
P_0c086784: /* original 323c, guest PC 0x0c086784 */
if(!s->budget--) { s->failed_pc=0x0c086784u; return 0; }
r[2]+=r[3];
goto P_0c086786;
P_0c086786: /* original a004, guest PC 0x0c086786 */
if(!s->budget--) { s->failed_pc=0x0c086786u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c086792;
P_0c086788: /* original 0425, guest PC 0x0c086788 */
if(!s->budget--) { s->failed_pc=0x0c086788u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c08678a;
P_0c08678a: /* original e128, guest PC 0x0c08678a */
if(!s->budget--) { s->failed_pc=0x0c08678au; return 0; }
r[1]=0x00000028u;
goto P_0c08678c;
P_0c08678c: /* original 004d, guest PC 0x0c08678c */
if(!s->budget--) { s->failed_pc=0x0c08678cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08678e;
P_0c08678e: /* original 314c, guest PC 0x0c08678e */
if(!s->budget--) { s->failed_pc=0x0c08678eu; return 0; }
r[1]+=r[4];
goto P_0c086790;
P_0c086790: /* original 2101, guest PC 0x0c086790 */
if(!s->budget--) { s->failed_pc=0x0c086790u; return 0; }
write(ram,r[1],r[0],2);
goto P_0c086792;
P_0c086792: /* original e026, guest PC 0x0c086792 */
if(!s->budget--) { s->failed_pc=0x0c086792u; return 0; }
r[0]=0x00000026u;
goto P_0c086794;
P_0c086794: /* original 034d, guest PC 0x0c086794 */
if(!s->budget--) { s->failed_pc=0x0c086794u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c086796;
P_0c086796: /* original e032, guest PC 0x0c086796 */
if(!s->budget--) { s->failed_pc=0x0c086796u; return 0; }
r[0]=0x00000032u;
goto P_0c086798;
P_0c086798: /* original 064d, guest PC 0x0c086798 */
if(!s->budget--) { s->failed_pc=0x0c086798u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08679a;
P_0c08679a: /* original 3638, guest PC 0x0c08679a */
if(!s->budget--) { s->failed_pc=0x0c08679au; return 0; }
r[6]-=r[3];
goto P_0c08679c;
P_0c08679c: /* original 626f, guest PC 0x0c08679c */
if(!s->budget--) { s->failed_pc=0x0c08679cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c08679e;
P_0c08679e: /* original 4211, guest PC 0x0c08679e */
if(!s->budget--) { s->failed_pc=0x0c08679eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c0867a0;
P_0c0867a0: /* original 8900, guest PC 0x0c0867a0 */
if(!s->budget--) { s->failed_pc=0x0c0867a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0867a4; }
goto P_0c0867a2;
P_0c0867a2: /* original 666b, guest PC 0x0c0867a2 */
if(!s->budget--) { s->failed_pc=0x0c0867a2u; return 0; }
r[6]=0u-r[6];
goto P_0c0867a4;
P_0c0867a4: /* original 666f, guest PC 0x0c0867a4 */
if(!s->budget--) { s->failed_pc=0x0c0867a4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c0867a6;
P_0c0867a6: /* original 3653, guest PC 0x0c0867a6 */
if(!s->budget--) { s->failed_pc=0x0c0867a6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[5])!=0);
goto P_0c0867a8;
P_0c0867a8: /* original 8b12, guest PC 0x0c0867a8 */
if(!s->budget--) { s->failed_pc=0x0c0867a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0867d0; }
goto P_0c0867aa;
P_0c0867aa: /* original e32c, guest PC 0x0c0867aa */
if(!s->budget--) { s->failed_pc=0x0c0867aau; return 0; }
r[3]=0x0000002cu;
goto P_0c0867ac;
P_0c0867ac: /* original 334c, guest PC 0x0c0867ac */
if(!s->budget--) { s->failed_pc=0x0c0867acu; return 0; }
r[3]+=r[4];
goto P_0c0867ae;
P_0c0867ae: /* original e026, guest PC 0x0c0867ae */
if(!s->budget--) { s->failed_pc=0x0c0867aeu; return 0; }
r[0]=0x00000026u;
goto P_0c0867b0;
P_0c0867b0: /* original 6331, guest PC 0x0c0867b0 */
if(!s->budget--) { s->failed_pc=0x0c0867b0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[3]=tmp;
goto P_0c0867b2;
P_0c0867b2: /* original 024d, guest PC 0x0c0867b2 */
if(!s->budget--) { s->failed_pc=0x0c0867b2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0867b4;
P_0c0867b4: /* original 323c, guest PC 0x0c0867b4 */
if(!s->budget--) { s->failed_pc=0x0c0867b4u; return 0; }
r[2]+=r[3];
goto P_0c0867b6;
P_0c0867b6: /* original a00f, guest PC 0x0c0867b6 */
if(!s->budget--) { s->failed_pc=0x0c0867b6u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0867d8;
P_0c0867b8: /* original 0425, guest PC 0x0c0867b8 */
if(!s->budget--) { s->failed_pc=0x0c0867b8u; return 0; }
write(ram,r[4]+r[0],r[2],2);
if(!vf3_matrix_family(0x0c0867bau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0867bau; return 0; } return 1;
P_0c0867d0: /* original e126, guest PC 0x0c0867d0 */
if(!s->budget--) { s->failed_pc=0x0c0867d0u; return 0; }
r[1]=0x00000026u;
goto P_0c0867d2;
P_0c0867d2: /* original 004d, guest PC 0x0c0867d2 */
if(!s->budget--) { s->failed_pc=0x0c0867d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0867d4;
P_0c0867d4: /* original 314c, guest PC 0x0c0867d4 */
if(!s->budget--) { s->failed_pc=0x0c0867d4u; return 0; }
r[1]+=r[4];
goto P_0c0867d6;
P_0c0867d6: /* original 2101, guest PC 0x0c0867d6 */
if(!s->budget--) { s->failed_pc=0x0c0867d6u; return 0; }
write(ram,r[1],r[0],2);
goto P_0c0867d8;
P_0c0867d8: /* original e024, guest PC 0x0c0867d8 */
if(!s->budget--) { s->failed_pc=0x0c0867d8u; return 0; }
r[0]=0x00000024u;
goto P_0c0867da;
P_0c0867da: /* original 034d, guest PC 0x0c0867da */
if(!s->budget--) { s->failed_pc=0x0c0867dau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0867dc;
P_0c0867dc: /* original e030, guest PC 0x0c0867dc */
if(!s->budget--) { s->failed_pc=0x0c0867dcu; return 0; }
r[0]=0x00000030u;
goto P_0c0867de;
P_0c0867de: /* original 064d, guest PC 0x0c0867de */
if(!s->budget--) { s->failed_pc=0x0c0867deu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0867e0;
P_0c0867e0: /* original 3638, guest PC 0x0c0867e0 */
if(!s->budget--) { s->failed_pc=0x0c0867e0u; return 0; }
r[6]-=r[3];
goto P_0c0867e2;
P_0c0867e2: /* original 626f, guest PC 0x0c0867e2 */
if(!s->budget--) { s->failed_pc=0x0c0867e2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c0867e4;
P_0c0867e4: /* original 4211, guest PC 0x0c0867e4 */
if(!s->budget--) { s->failed_pc=0x0c0867e4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c0867e6;
P_0c0867e6: /* original 8900, guest PC 0x0c0867e6 */
if(!s->budget--) { s->failed_pc=0x0c0867e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0867ea; }
goto P_0c0867e8;
P_0c0867e8: /* original 666b, guest PC 0x0c0867e8 */
if(!s->budget--) { s->failed_pc=0x0c0867e8u; return 0; }
r[6]=0u-r[6];
goto P_0c0867ea;
P_0c0867ea: /* original 666f, guest PC 0x0c0867ea */
if(!s->budget--) { s->failed_pc=0x0c0867eau; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c0867ec;
P_0c0867ec: /* original 3653, guest PC 0x0c0867ec */
if(!s->budget--) { s->failed_pc=0x0c0867ecu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[5])!=0);
goto P_0c0867ee;
P_0c0867ee: /* original 8b07, guest PC 0x0c0867ee */
if(!s->budget--) { s->failed_pc=0x0c0867eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086800; }
goto P_0c0867f0;
P_0c0867f0: /* original e32a, guest PC 0x0c0867f0 */
if(!s->budget--) { s->failed_pc=0x0c0867f0u; return 0; }
r[3]=0x0000002au;
goto P_0c0867f2;
P_0c0867f2: /* original 334c, guest PC 0x0c0867f2 */
if(!s->budget--) { s->failed_pc=0x0c0867f2u; return 0; }
r[3]+=r[4];
goto P_0c0867f4;
P_0c0867f4: /* original e024, guest PC 0x0c0867f4 */
if(!s->budget--) { s->failed_pc=0x0c0867f4u; return 0; }
r[0]=0x00000024u;
goto P_0c0867f6;
P_0c0867f6: /* original 6331, guest PC 0x0c0867f6 */
if(!s->budget--) { s->failed_pc=0x0c0867f6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[3]=tmp;
goto P_0c0867f8;
P_0c0867f8: /* original 024d, guest PC 0x0c0867f8 */
if(!s->budget--) { s->failed_pc=0x0c0867f8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0867fa;
P_0c0867fa: /* original 323c, guest PC 0x0c0867fa */
if(!s->budget--) { s->failed_pc=0x0c0867fau; return 0; }
r[2]+=r[3];
goto P_0c0867fc;
P_0c0867fc: /* original 000b, guest PC 0x0c0867fc */
if(!s->budget--) { s->failed_pc=0x0c0867fcu; return 0; }
target=r[16];
write(ram,r[4]+r[0],r[2],2);
s->pc=target; return ram->oob==0;
P_0c0867fe: /* original 0425, guest PC 0x0c0867fe */
if(!s->budget--) { s->failed_pc=0x0c0867feu; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c086800;
P_0c086800: /* original 014d, guest PC 0x0c086800 */
if(!s->budget--) { s->failed_pc=0x0c086800u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c086802;
P_0c086802: /* original e024, guest PC 0x0c086802 */
if(!s->budget--) { s->failed_pc=0x0c086802u; return 0; }
r[0]=0x00000024u;
goto P_0c086804;
P_0c086804: /* original 0415, guest PC 0x0c086804 */
if(!s->budget--) { s->failed_pc=0x0c086804u; return 0; }
write(ram,r[4]+r[0],r[1],2);
goto P_0c086806;
P_0c086806: /* original 000b, guest PC 0x0c086806 */
if(!s->budget--) { s->failed_pc=0x0c086806u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c086808: /* original 0009, guest PC 0x0c086808 */
if(!s->budget--) { s->failed_pc=0x0c086808u; return 0; }
goto P_0c08680a;
P_0c08680a: /* original e024, guest PC 0x0c08680a */
if(!s->budget--) { s->failed_pc=0x0c08680au; return 0; }
r[0]=0x00000024u;
goto P_0c08680c;
P_0c08680c: /* original 6743, guest PC 0x0c08680c */
if(!s->budget--) { s->failed_pc=0x0c08680cu; return 0; }
r[7]=r[4];
goto P_0c08680e;
P_0c08680e: /* original f376, guest PC 0x0c08680e */
if(!s->budget--) { s->failed_pc=0x0c08680eu; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c086810;
P_0c086810: /* original 6453, guest PC 0x0c086810 */
if(!s->budget--) { s->failed_pc=0x0c086810u; return 0; }
r[4]=r[5];
goto P_0c086812;
P_0c086812: /* original 906e, guest PC 0x0c086812 */
if(!s->budget--) { s->failed_pc=0x0c086812u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0868f2u,2);
goto P_0c086814;
P_0c086814: /* original f266, guest PC 0x0c086814 */
if(!s->budget--) { s->failed_pc=0x0c086814u; return 0; }
vf3_matrix_load(s,ram,2,r[6]+r[0]);
goto P_0c086816;
P_0c086816: /* original e044, guest PC 0x0c086816 */
if(!s->budget--) { s->failed_pc=0x0c086816u; return 0; }
r[0]=0x00000044u;
goto P_0c086818;
P_0c086818: /* original f232, guest PC 0x0c086818 */
if(!s->budget--) { s->failed_pc=0x0c086818u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c08681a;
P_0c08681a: /* original f427, guest PC 0x0c08681a */
if(!s->budget--) { s->failed_pc=0x0c08681au; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c08681c;
P_0c08681c: /* original e020, guest PC 0x0c08681c */
if(!s->budget--) { s->failed_pc=0x0c08681cu; return 0; }
r[0]=0x00000020u;
goto P_0c08681e;
P_0c08681e: /* original f376, guest PC 0x0c08681e */
if(!s->budget--) { s->failed_pc=0x0c08681eu; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c086820;
P_0c086820: /* original 9068, guest PC 0x0c086820 */
if(!s->budget--) { s->failed_pc=0x0c086820u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0868f4u,2);
goto P_0c086822;
P_0c086822: /* original f266, guest PC 0x0c086822 */
if(!s->budget--) { s->failed_pc=0x0c086822u; return 0; }
vf3_matrix_load(s,ram,2,r[6]+r[0]);
goto P_0c086824;
P_0c086824: /* original e048, guest PC 0x0c086824 */
if(!s->budget--) { s->failed_pc=0x0c086824u; return 0; }
r[0]=0x00000048u;
goto P_0c086826;
P_0c086826: /* original f232, guest PC 0x0c086826 */
if(!s->budget--) { s->failed_pc=0x0c086826u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c086828;
P_0c086828: /* original f427, guest PC 0x0c086828 */
if(!s->budget--) { s->failed_pc=0x0c086828u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c08682a;
P_0c08682a: /* original e024, guest PC 0x0c08682a */
if(!s->budget--) { s->failed_pc=0x0c08682au; return 0; }
r[0]=0x00000024u;
goto P_0c08682c;
P_0c08682c: /* original f376, guest PC 0x0c08682c */
if(!s->budget--) { s->failed_pc=0x0c08682cu; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c08682e;
P_0c08682e: /* original 9062, guest PC 0x0c08682e */
if(!s->budget--) { s->failed_pc=0x0c08682eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0868f6u,2);
goto P_0c086830;
P_0c086830: /* original f266, guest PC 0x0c086830 */
if(!s->budget--) { s->failed_pc=0x0c086830u; return 0; }
vf3_matrix_load(s,ram,2,r[6]+r[0]);
goto P_0c086832;
P_0c086832: /* original e04c, guest PC 0x0c086832 */
if(!s->budget--) { s->failed_pc=0x0c086832u; return 0; }
r[0]=0x0000004cu;
goto P_0c086834;
P_0c086834: /* original f232, guest PC 0x0c086834 */
if(!s->budget--) { s->failed_pc=0x0c086834u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c086836;
P_0c086836: /* original f427, guest PC 0x0c086836 */
if(!s->budget--) { s->failed_pc=0x0c086836u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c086838;
P_0c086838: /* original e018, guest PC 0x0c086838 */
if(!s->budget--) { s->failed_pc=0x0c086838u; return 0; }
r[0]=0x00000018u;
goto P_0c08683a;
P_0c08683a: /* original f376, guest PC 0x0c08683a */
if(!s->budget--) { s->failed_pc=0x0c08683au; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c08683c;
P_0c08683c: /* original e044, guest PC 0x0c08683c */
if(!s->budget--) { s->failed_pc=0x0c08683cu; return 0; }
r[0]=0x00000044u;
goto P_0c08683e;
P_0c08683e: /* original f246, guest PC 0x0c08683e */
if(!s->budget--) { s->failed_pc=0x0c08683eu; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c086840;
P_0c086840: /* original e02a, guest PC 0x0c086840 */
if(!s->budget--) { s->failed_pc=0x0c086840u; return 0; }
r[0]=0x0000002au;
goto P_0c086842;
P_0c086842: /* original f232, guest PC 0x0c086842 */
if(!s->budget--) { s->failed_pc=0x0c086842u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c086844;
P_0c086844: /* original f23d, guest PC 0x0c086844 */
if(!s->budget--) { s->failed_pc=0x0c086844u; return 0; }
r[53]=truncate_float(fr[2]);
goto P_0c086846;
P_0c086846: /* original 035a, guest PC 0x0c086846 */
if(!s->budget--) { s->failed_pc=0x0c086846u; return 0; }
r[3]=r[53];
goto P_0c086848;
P_0c086848: /* original 0435, guest PC 0x0c086848 */
if(!s->budget--) { s->failed_pc=0x0c086848u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c08684a;
P_0c08684a: /* original e01c, guest PC 0x0c08684a */
if(!s->budget--) { s->failed_pc=0x0c08684au; return 0; }
r[0]=0x0000001cu;
goto P_0c08684c;
P_0c08684c: /* original f376, guest PC 0x0c08684c */
if(!s->budget--) { s->failed_pc=0x0c08684cu; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c08684e;
P_0c08684e: /* original e048, guest PC 0x0c08684e */
if(!s->budget--) { s->failed_pc=0x0c08684eu; return 0; }
r[0]=0x00000048u;
goto P_0c086850;
P_0c086850: /* original f246, guest PC 0x0c086850 */
if(!s->budget--) { s->failed_pc=0x0c086850u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c086852;
P_0c086852: /* original e02c, guest PC 0x0c086852 */
if(!s->budget--) { s->failed_pc=0x0c086852u; return 0; }
r[0]=0x0000002cu;
goto P_0c086854;
P_0c086854: /* original f232, guest PC 0x0c086854 */
if(!s->budget--) { s->failed_pc=0x0c086854u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c086856;
P_0c086856: /* original f23d, guest PC 0x0c086856 */
if(!s->budget--) { s->failed_pc=0x0c086856u; return 0; }
r[53]=truncate_float(fr[2]);
goto P_0c086858;
P_0c086858: /* original 035a, guest PC 0x0c086858 */
if(!s->budget--) { s->failed_pc=0x0c086858u; return 0; }
r[3]=r[53];
goto P_0c08685a;
P_0c08685a: /* original 0435, guest PC 0x0c08685a */
if(!s->budget--) { s->failed_pc=0x0c08685au; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c08685c;
P_0c08685c: /* original e018, guest PC 0x0c08685c */
if(!s->budget--) { s->failed_pc=0x0c08685cu; return 0; }
r[0]=0x00000018u;
goto P_0c08685e;
P_0c08685e: /* original f376, guest PC 0x0c08685e */
if(!s->budget--) { s->failed_pc=0x0c08685eu; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c086860;
P_0c086860: /* original e04c, guest PC 0x0c086860 */
if(!s->budget--) { s->failed_pc=0x0c086860u; return 0; }
r[0]=0x0000004cu;
goto P_0c086862;
P_0c086862: /* original f246, guest PC 0x0c086862 */
if(!s->budget--) { s->failed_pc=0x0c086862u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c086864;
P_0c086864: /* original e02e, guest PC 0x0c086864 */
if(!s->budget--) { s->failed_pc=0x0c086864u; return 0; }
r[0]=0x0000002eu;
goto P_0c086866;
P_0c086866: /* original f232, guest PC 0x0c086866 */
if(!s->budget--) { s->failed_pc=0x0c086866u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c086868;
P_0c086868: /* original f23d, guest PC 0x0c086868 */
if(!s->budget--) { s->failed_pc=0x0c086868u; return 0; }
r[53]=truncate_float(fr[2]);
goto P_0c08686a;
P_0c08686a: /* original 035a, guest PC 0x0c08686a */
if(!s->budget--) { s->failed_pc=0x0c08686au; return 0; }
r[3]=r[53];
goto P_0c08686c;
P_0c08686c: /* original 000b, guest PC 0x0c08686c */
if(!s->budget--) { s->failed_pc=0x0c08686cu; return 0; }
target=r[16];
write(ram,r[4]+r[0],r[3],2);
s->pc=target; return ram->oob==0;
P_0c08686e: /* original 0435, guest PC 0x0c08686e */
if(!s->budget--) { s->failed_pc=0x0c08686eu; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c086870;
P_0c086870: /* original 2fe6, guest PC 0x0c086870 */
if(!s->budget--) { s->failed_pc=0x0c086870u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086872;
P_0c086872: /* original e028, guest PC 0x0c086872 */
if(!s->budget--) { s->failed_pc=0x0c086872u; return 0; }
r[0]=0x00000028u;
goto P_0c086874;
P_0c086874: /* original 6e53, guest PC 0x0c086874 */
if(!s->budget--) { s->failed_pc=0x0c086874u; return 0; }
r[14]=r[5];
goto P_0c086876;
P_0c086876: /* original 2fd6, guest PC 0x0c086876 */
if(!s->budget--) { s->failed_pc=0x0c086876u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086878;
P_0c086878: /* original 2fc6, guest PC 0x0c086878 */
if(!s->budget--) { s->failed_pc=0x0c086878u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08687a;
P_0c08687a: /* original 6d63, guest PC 0x0c08687a */
if(!s->budget--) { s->failed_pc=0x0c08687au; return 0; }
r[13]=r[6];
goto P_0c08687c;
P_0c08687c: /* original 03ed, guest PC 0x0c08687c */
if(!s->budget--) { s->failed_pc=0x0c08687cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08687e;
P_0c08687e: /* original e060, guest PC 0x0c08687e */
if(!s->budget--) { s->failed_pc=0x0c08687eu; return 0; }
r[0]=0x00000060u;
goto P_0c086880;
P_0c086880: /* original 4f22, guest PC 0x0c086880 */
if(!s->budget--) { s->failed_pc=0x0c086880u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c086882;
P_0c086882: /* original 7ffc, guest PC 0x0c086882 */
if(!s->budget--) { s->failed_pc=0x0c086882u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c086884;
P_0c086884: /* original 2f31, guest PC 0x0c086884 */
if(!s->budget--) { s->failed_pc=0x0c086884u; return 0; }
write(ram,r[15],r[3],2);
goto P_0c086886;
P_0c086886: /* original 0cdc, guest PC 0x0c086886 */
if(!s->budget--) { s->failed_pc=0x0c086886u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c086888;
P_0c086888: /* original d01b, guest PC 0x0c086888 */
if(!s->budget--) { s->failed_pc=0x0c086888u; return 0; }
r[0]=read(ram,0x0c0868f8u,4);
goto P_0c08688a;
P_0c08688a: /* original 6ccc, guest PC 0x0c08688a */
if(!s->budget--) { s->failed_pc=0x0c08688au; return 0; }
r[12]=r[12]&255u;
goto P_0c08688c;
P_0c08688c: /* original d61b, guest PC 0x0c08688c */
if(!s->budget--) { s->failed_pc=0x0c08688cu; return 0; }
r[6]=read(ram,0x0c0868fcu,4);
goto P_0c08688e;
P_0c08688e: /* original 4c08, guest PC 0x0c08688e */
if(!s->budget--) { s->failed_pc=0x0c08688eu; return 0; }
r[12]<<=2;
goto P_0c086890;
P_0c086890: /* original 0cce, guest PC 0x0c086890 */
if(!s->budget--) { s->failed_pc=0x0c086890u; return 0; }
r[12]=read(ram,r[12]+r[0],4);
goto P_0c086892;
P_0c086892: /* original 65c3, guest PC 0x0c086892 */
if(!s->budget--) { s->failed_pc=0x0c086892u; return 0; }
r[5]=r[12];
goto P_0c086894;
P_0c086894: /* original b03c, guest PC 0x0c086894 */
if(!s->budget--) { s->failed_pc=0x0c086894u; return 0; }
target=code_base|0x0c086910u; r[16]=code_base|0x0c086898u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c086898u) { target=s->pc; goto dispatch; }
goto P_0c086898;
P_0c086896: /* original 64f3, guest PC 0x0c086896 */
if(!s->budget--) { s->failed_pc=0x0c086896u; return 0; }
r[4]=r[15];
goto P_0c086898;
P_0c086898: /* original 62f1, guest PC 0x0c086898 */
if(!s->budget--) { s->failed_pc=0x0c086898u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[2]=tmp;
goto P_0c08689a;
P_0c08689a: /* original e02e, guest PC 0x0c08689a */
if(!s->budget--) { s->failed_pc=0x0c08689au; return 0; }
r[0]=0x0000002eu;
goto P_0c08689c;
P_0c08689c: /* original 0e25, guest PC 0x0c08689c */
if(!s->budget--) { s->failed_pc=0x0c08689cu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c08689e;
P_0c08689e: /* original e034, guest PC 0x0c08689e */
if(!s->budget--) { s->failed_pc=0x0c08689eu; return 0; }
r[0]=0x00000034u;
goto P_0c0868a0;
P_0c0868a0: /* original 63c1, guest PC 0x0c0868a0 */
if(!s->budget--) { s->failed_pc=0x0c0868a0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[3]=tmp;
goto P_0c0868a2;
P_0c0868a2: /* original 0e35, guest PC 0x0c0868a2 */
if(!s->budget--) { s->failed_pc=0x0c0868a2u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0868a4;
P_0c0868a4: /* original e026, guest PC 0x0c0868a4 */
if(!s->budget--) { s->failed_pc=0x0c0868a4u; return 0; }
r[0]=0x00000026u;
goto P_0c0868a6;
P_0c0868a6: /* original 02ed, guest PC 0x0c0868a6 */
if(!s->budget--) { s->failed_pc=0x0c0868a6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0868a8;
P_0c0868a8: /* original 2f21, guest PC 0x0c0868a8 */
if(!s->budget--) { s->failed_pc=0x0c0868a8u; return 0; }
write(ram,r[15],r[2],2);
goto P_0c0868aa;
P_0c0868aa: /* original dc15, guest PC 0x0c0868aa */
if(!s->budget--) { s->failed_pc=0x0c0868aau; return 0; }
r[12]=read(ram,0x0c086900u,4);
goto P_0c0868ac;
P_0c0868ac: /* original d615, guest PC 0x0c0868ac */
if(!s->budget--) { s->failed_pc=0x0c0868acu; return 0; }
r[6]=read(ram,0x0c086904u,4);
goto P_0c0868ae;
P_0c0868ae: /* original 65c3, guest PC 0x0c0868ae */
if(!s->budget--) { s->failed_pc=0x0c0868aeu; return 0; }
r[5]=r[12];
goto P_0c0868b0;
P_0c0868b0: /* original b02e, guest PC 0x0c0868b0 */
if(!s->budget--) { s->failed_pc=0x0c0868b0u; return 0; }
target=code_base|0x0c086910u; r[16]=code_base|0x0c0868b4u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0868b4u) { target=s->pc; goto dispatch; }
goto P_0c0868b4;
P_0c0868b2: /* original 64f3, guest PC 0x0c0868b2 */
if(!s->budget--) { s->failed_pc=0x0c0868b2u; return 0; }
r[4]=r[15];
goto P_0c0868b4;
P_0c0868b4: /* original 62f1, guest PC 0x0c0868b4 */
if(!s->budget--) { s->failed_pc=0x0c0868b4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[2]=tmp;
goto P_0c0868b6;
P_0c0868b6: /* original e02c, guest PC 0x0c0868b6 */
if(!s->budget--) { s->failed_pc=0x0c0868b6u; return 0; }
r[0]=0x0000002cu;
goto P_0c0868b8;
P_0c0868b8: /* original 0e25, guest PC 0x0c0868b8 */
if(!s->budget--) { s->failed_pc=0x0c0868b8u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0868ba;
P_0c0868ba: /* original e032, guest PC 0x0c0868ba */
if(!s->budget--) { s->failed_pc=0x0c0868bau; return 0; }
r[0]=0x00000032u;
goto P_0c0868bc;
P_0c0868bc: /* original 63c1, guest PC 0x0c0868bc */
if(!s->budget--) { s->failed_pc=0x0c0868bcu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[3]=tmp;
goto P_0c0868be;
P_0c0868be: /* original 0e35, guest PC 0x0c0868be */
if(!s->budget--) { s->failed_pc=0x0c0868beu; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0868c0;
P_0c0868c0: /* original e024, guest PC 0x0c0868c0 */
if(!s->budget--) { s->failed_pc=0x0c0868c0u; return 0; }
r[0]=0x00000024u;
goto P_0c0868c2;
P_0c0868c2: /* original 02ed, guest PC 0x0c0868c2 */
if(!s->budget--) { s->failed_pc=0x0c0868c2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0868c4;
P_0c0868c4: /* original e060, guest PC 0x0c0868c4 */
if(!s->budget--) { s->failed_pc=0x0c0868c4u; return 0; }
r[0]=0x00000060u;
goto P_0c0868c6;
P_0c0868c6: /* original 2f21, guest PC 0x0c0868c6 */
if(!s->budget--) { s->failed_pc=0x0c0868c6u; return 0; }
write(ram,r[15],r[2],2);
goto P_0c0868c8;
P_0c0868c8: /* original 03dc, guest PC 0x0c0868c8 */
if(!s->budget--) { s->failed_pc=0x0c0868c8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0868ca;
P_0c0868ca: /* original d00f, guest PC 0x0c0868ca */
if(!s->budget--) { s->failed_pc=0x0c0868cau; return 0; }
r[0]=read(ram,0x0c086908u,4);
goto P_0c0868cc;
P_0c0868cc: /* original 633c, guest PC 0x0c0868cc */
if(!s->budget--) { s->failed_pc=0x0c0868ccu; return 0; }
r[3]=r[3]&255u;
goto P_0c0868ce;
P_0c0868ce: /* original d60f, guest PC 0x0c0868ce */
if(!s->budget--) { s->failed_pc=0x0c0868ceu; return 0; }
r[6]=read(ram,0x0c08690cu,4);
goto P_0c0868d0;
P_0c0868d0: /* original 4308, guest PC 0x0c0868d0 */
if(!s->budget--) { s->failed_pc=0x0c0868d0u; return 0; }
r[3]<<=2;
goto P_0c0868d2;
P_0c0868d2: /* original 0d3e, guest PC 0x0c0868d2 */
if(!s->budget--) { s->failed_pc=0x0c0868d2u; return 0; }
r[13]=read(ram,r[3]+r[0],4);
goto P_0c0868d4;
P_0c0868d4: /* original 65d3, guest PC 0x0c0868d4 */
if(!s->budget--) { s->failed_pc=0x0c0868d4u; return 0; }
r[5]=r[13];
goto P_0c0868d6;
P_0c0868d6: /* original b01b, guest PC 0x0c0868d6 */
if(!s->budget--) { s->failed_pc=0x0c0868d6u; return 0; }
target=code_base|0x0c086910u; r[16]=code_base|0x0c0868dau;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0868dau) { target=s->pc; goto dispatch; }
goto P_0c0868da;
P_0c0868d8: /* original 64f3, guest PC 0x0c0868d8 */
if(!s->budget--) { s->failed_pc=0x0c0868d8u; return 0; }
r[4]=r[15];
goto P_0c0868da;
P_0c0868da: /* original 62f1, guest PC 0x0c0868da */
if(!s->budget--) { s->failed_pc=0x0c0868dau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[2]=tmp;
goto P_0c0868dc;
P_0c0868dc: /* original 7f04, guest PC 0x0c0868dc */
if(!s->budget--) { s->failed_pc=0x0c0868dcu; return 0; }
r[15]+=0x00000004u;
goto P_0c0868de;
P_0c0868de: /* original 4f26, guest PC 0x0c0868de */
if(!s->budget--) { s->failed_pc=0x0c0868deu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0868e0;
P_0c0868e0: /* original e02a, guest PC 0x0c0868e0 */
if(!s->budget--) { s->failed_pc=0x0c0868e0u; return 0; }
r[0]=0x0000002au;
goto P_0c0868e2;
P_0c0868e2: /* original 0e25, guest PC 0x0c0868e2 */
if(!s->budget--) { s->failed_pc=0x0c0868e2u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0868e4;
P_0c0868e4: /* original e030, guest PC 0x0c0868e4 */
if(!s->budget--) { s->failed_pc=0x0c0868e4u; return 0; }
r[0]=0x00000030u;
goto P_0c0868e6;
P_0c0868e6: /* original 63d1, guest PC 0x0c0868e6 */
if(!s->budget--) { s->failed_pc=0x0c0868e6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[3]=tmp;
goto P_0c0868e8;
P_0c0868e8: /* original 0e35, guest PC 0x0c0868e8 */
if(!s->budget--) { s->failed_pc=0x0c0868e8u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0868ea;
P_0c0868ea: /* original 6cf6, guest PC 0x0c0868ea */
if(!s->budget--) { s->failed_pc=0x0c0868eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0868ec;
P_0c0868ec: /* original 6df6, guest PC 0x0c0868ec */
if(!s->budget--) { s->failed_pc=0x0c0868ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0868ee;
P_0c0868ee: /* original 000b, guest PC 0x0c0868ee */
if(!s->budget--) { s->failed_pc=0x0c0868eeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0868f0: /* original 6ef6, guest PC 0x0c0868f0 */
if(!s->budget--) { s->failed_pc=0x0c0868f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0868f2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0868f2u; return 0; } return 1;
P_0c086910: /* original 2fe6, guest PC 0x0c086910 */
if(!s->budget--) { s->failed_pc=0x0c086910u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086912;
P_0c086912: /* original 6e43, guest PC 0x0c086912 */
if(!s->budget--) { s->failed_pc=0x0c086912u; return 0; }
r[14]=r[4];
goto P_0c086914;
P_0c086914: /* original 2fd6, guest PC 0x0c086914 */
if(!s->budget--) { s->failed_pc=0x0c086914u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086916;
P_0c086916: /* original 2fc6, guest PC 0x0c086916 */
if(!s->budget--) { s->failed_pc=0x0c086916u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086918;
P_0c086918: /* original 6c63, guest PC 0x0c086918 */
if(!s->budget--) { s->failed_pc=0x0c086918u; return 0; }
r[12]=r[6];
goto P_0c08691a;
P_0c08691a: /* original 4f22, guest PC 0x0c08691a */
if(!s->budget--) { s->failed_pc=0x0c08691au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08691c;
P_0c08691c: /* original 7ff0, guest PC 0x0c08691c */
if(!s->budget--) { s->failed_pc=0x0c08691cu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c08691e;
P_0c08691e: /* original 1f51, guest PC 0x0c08691e */
if(!s->budget--) { s->failed_pc=0x0c08691eu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c086920;
P_0c086920: /* original 60e1, guest PC 0x0c086920 */
if(!s->budget--) { s->failed_pc=0x0c086920u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c086922;
P_0c086922: /* original 81f4, guest PC 0x0c086922 */
if(!s->budget--) { s->failed_pc=0x0c086922u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c086924;
P_0c086924: /* original 85f4, guest PC 0x0c086924 */
if(!s->budget--) { s->failed_pc=0x0c086924u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c086926;
P_0c086926: /* original b02f, guest PC 0x0c086926 */
if(!s->budget--) { s->failed_pc=0x0c086926u; return 0; }
target=code_base|0x0c086988u; r[16]=code_base|0x0c08692au;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08692au) { target=s->pc; goto dispatch; }
goto P_0c08692a;
P_0c086928: /* original 6403, guest PC 0x0c086928 */
if(!s->budget--) { s->failed_pc=0x0c086928u; return 0; }
r[4]=r[0];
goto P_0c08692a;
P_0c08692a: /* original 2f01, guest PC 0x0c08692a */
if(!s->budget--) { s->failed_pc=0x0c08692au; return 0; }
write(ram,r[15],r[0],2);
goto P_0c08692c;
P_0c08692c: /* original 63f1, guest PC 0x0c08692c */
if(!s->budget--) { s->failed_pc=0x0c08692cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c08692e;
P_0c08692e: /* original 4300, guest PC 0x0c08692e */
if(!s->budget--) { s->failed_pc=0x0c08692eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c086930;
P_0c086930: /* original 4300, guest PC 0x0c086930 */
if(!s->budget--) { s->failed_pc=0x0c086930u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c086932;
P_0c086932: /* original 1f33, guest PC 0x0c086932 */
if(!s->budget--) { s->failed_pc=0x0c086932u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c086934;
P_0c086934: /* original 52f1, guest PC 0x0c086934 */
if(!s->budget--) { s->failed_pc=0x0c086934u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c086936;
P_0c086936: /* original 323c, guest PC 0x0c086936 */
if(!s->budget--) { s->failed_pc=0x0c086936u; return 0; }
r[2]+=r[3];
goto P_0c086938;
P_0c086938: /* original 1f21, guest PC 0x0c086938 */
if(!s->budget--) { s->failed_pc=0x0c086938u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c08693a;
P_0c08693a: /* original 6d21, guest PC 0x0c08693a */
if(!s->budget--) { s->failed_pc=0x0c08693au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[13]=tmp;
goto P_0c08693c;
P_0c08693c: /* original b024, guest PC 0x0c08693c */
if(!s->budget--) { s->failed_pc=0x0c08693cu; return 0; }
target=code_base|0x0c086988u; r[16]=code_base|0x0c086940u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c086940u) { target=s->pc; goto dispatch; }
goto P_0c086940;
P_0c08693e: /* original 64d3, guest PC 0x0c08693e */
if(!s->budget--) { s->failed_pc=0x0c08693eu; return 0; }
r[4]=r[13];
goto P_0c086940;
P_0c086940: /* original 6403, guest PC 0x0c086940 */
if(!s->budget--) { s->failed_pc=0x0c086940u; return 0; }
r[4]=r[0];
goto P_0c086942;
P_0c086942: /* original 644f, guest PC 0x0c086942 */
if(!s->budget--) { s->failed_pc=0x0c086942u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c086944;
P_0c086944: /* original 4408, guest PC 0x0c086944 */
if(!s->budget--) { s->failed_pc=0x0c086944u; return 0; }
r[4]<<=2;
goto P_0c086946;
P_0c086946: /* original 53f3, guest PC 0x0c086946 */
if(!s->budget--) { s->failed_pc=0x0c086946u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c086948;
P_0c086948: /* original 4400, guest PC 0x0c086948 */
if(!s->budget--) { s->failed_pc=0x0c086948u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08694a;
P_0c08694a: /* original 4400, guest PC 0x0c08694a */
if(!s->budget--) { s->failed_pc=0x0c08694au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08694c;
P_0c08694c: /* original 3c3c, guest PC 0x0c08694c */
if(!s->budget--) { s->failed_pc=0x0c08694cu; return 0; }
r[12]+=r[3];
goto P_0c08694e;
P_0c08694e: /* original 3c4c, guest PC 0x0c08694e */
if(!s->budget--) { s->failed_pc=0x0c08694eu; return 0; }
r[12]+=r[4];
goto P_0c086950;
P_0c086950: /* original 62c1, guest PC 0x0c086950 */
if(!s->budget--) { s->failed_pc=0x0c086950u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[2]=tmp;
goto P_0c086952;
P_0c086952: /* original 65df, guest PC 0x0c086952 */
if(!s->budget--) { s->failed_pc=0x0c086952u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c086954;
P_0c086954: /* original 2e21, guest PC 0x0c086954 */
if(!s->budget--) { s->failed_pc=0x0c086954u; return 0; }
write(ram,r[14],r[2],2);
goto P_0c086956;
P_0c086956: /* original 85f4, guest PC 0x0c086956 */
if(!s->budget--) { s->failed_pc=0x0c086956u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c086958;
P_0c086958: /* original 6403, guest PC 0x0c086958 */
if(!s->budget--) { s->failed_pc=0x0c086958u; return 0; }
r[4]=r[0];
goto P_0c08695a;
P_0c08695a: /* original 3450, guest PC 0x0c08695a */
if(!s->budget--) { s->failed_pc=0x0c08695au; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c08695c;
P_0c08695c: /* original 8b01, guest PC 0x0c08695c */
if(!s->budget--) { s->failed_pc=0x0c08695cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086962; }
goto P_0c08695e;
P_0c08695e: /* original a006, guest PC 0x0c08695e */
if(!s->budget--) { s->failed_pc=0x0c08695eu; return 0; }
r[3]=0x00000000u;
goto P_0c08696e;
P_0c086960: /* original e300, guest PC 0x0c086960 */
if(!s->budget--) { s->failed_pc=0x0c086960u; return 0; }
r[3]=0x00000000u;
goto P_0c086962;
P_0c086962: /* original 62e1, guest PC 0x0c086962 */
if(!s->budget--) { s->failed_pc=0x0c086962u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c086964;
P_0c086964: /* original 2228, guest PC 0x0c086964 */
if(!s->budget--) { s->failed_pc=0x0c086964u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c086966;
P_0c086966: /* original 8b06, guest PC 0x0c086966 */
if(!s->budget--) { s->failed_pc=0x0c086966u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086976; }
goto P_0c086968;
P_0c086968: /* original 3453, guest PC 0x0c086968 */
if(!s->budget--) { s->failed_pc=0x0c086968u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c08696a;
P_0c08696a: /* original 8b02, guest PC 0x0c08696a */
if(!s->budget--) { s->failed_pc=0x0c08696au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086972; }
goto P_0c08696c;
P_0c08696c: /* original 9321, guest PC 0x0c08696c */
if(!s->budget--) { s->failed_pc=0x0c08696cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0869b2u,2);
goto P_0c08696e;
P_0c08696e: /* original a002, guest PC 0x0c08696e */
if(!s->budget--) { s->failed_pc=0x0c08696eu; return 0; }
write(ram,r[14],r[3],2);
goto P_0c086976;
P_0c086970: /* original 2e31, guest PC 0x0c086970 */
if(!s->budget--) { s->failed_pc=0x0c086970u; return 0; }
write(ram,r[14],r[3],2);
goto P_0c086972;
P_0c086972: /* original 911f, guest PC 0x0c086972 */
if(!s->budget--) { s->failed_pc=0x0c086972u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0869b4u,2);
goto P_0c086974;
P_0c086974: /* original 2e11, guest PC 0x0c086974 */
if(!s->budget--) { s->failed_pc=0x0c086974u; return 0; }
write(ram,r[14],r[1],2);
goto P_0c086976;
P_0c086976: /* original 7f10, guest PC 0x0c086976 */
if(!s->budget--) { s->failed_pc=0x0c086976u; return 0; }
r[15]+=0x00000010u;
goto P_0c086978;
P_0c086978: /* original 63e1, guest PC 0x0c086978 */
if(!s->budget--) { s->failed_pc=0x0c086978u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[3]=tmp;
goto P_0c08697a;
P_0c08697a: /* original 4f26, guest PC 0x0c08697a */
if(!s->budget--) { s->failed_pc=0x0c08697au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08697c;
P_0c08697c: /* original 4300, guest PC 0x0c08697c */
if(!s->budget--) { s->failed_pc=0x0c08697cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c08697e;
P_0c08697e: /* original 2e31, guest PC 0x0c08697e */
if(!s->budget--) { s->failed_pc=0x0c08697eu; return 0; }
write(ram,r[14],r[3],2);
goto P_0c086980;
P_0c086980: /* original 6cf6, guest PC 0x0c086980 */
if(!s->budget--) { s->failed_pc=0x0c086980u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c086982;
P_0c086982: /* original 6df6, guest PC 0x0c086982 */
if(!s->budget--) { s->failed_pc=0x0c086982u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c086984;
P_0c086984: /* original 000b, guest PC 0x0c086984 */
if(!s->budget--) { s->failed_pc=0x0c086984u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c086986: /* original 6ef6, guest PC 0x0c086986 */
if(!s->budget--) { s->failed_pc=0x0c086986u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c086988u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
