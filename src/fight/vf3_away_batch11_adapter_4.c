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
int vf3_away_batch11_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03f690u: goto P_0c03f690;
case 0x0c03f692u: goto P_0c03f692;
case 0x0c03f694u: goto P_0c03f694;
case 0x0c03f696u: goto P_0c03f696;
case 0x0c03f698u: goto P_0c03f698;
case 0x0c03f69au: goto P_0c03f69a;
case 0x0c03f69cu: goto P_0c03f69c;
case 0x0c03f69eu: goto P_0c03f69e;
case 0x0c03f6a0u: goto P_0c03f6a0;
case 0x0c03f6a2u: goto P_0c03f6a2;
case 0x0c03f6a4u: goto P_0c03f6a4;
case 0x0c03f6a6u: goto P_0c03f6a6;
case 0x0c03f6a8u: goto P_0c03f6a8;
case 0x0c03f6aau: goto P_0c03f6aa;
case 0x0c03f6acu: goto P_0c03f6ac;
case 0x0c03f6aeu: goto P_0c03f6ae;
case 0x0c03f6b0u: goto P_0c03f6b0;
case 0x0c03f6b2u: goto P_0c03f6b2;
case 0x0c03f6b4u: goto P_0c03f6b4;
case 0x0c03f6b6u: goto P_0c03f6b6;
case 0x0c03f6b8u: goto P_0c03f6b8;
case 0x0c03f6c0u: goto P_0c03f6c0;
case 0x0c03f6c2u: goto P_0c03f6c2;
case 0x0c03f6c4u: goto P_0c03f6c4;
case 0x0c03f6c6u: goto P_0c03f6c6;
case 0x0c03f6c8u: goto P_0c03f6c8;
case 0x0c03f6cau: goto P_0c03f6ca;
case 0x0c03f6ccu: goto P_0c03f6cc;
case 0x0c03f6ceu: goto P_0c03f6ce;
case 0x0c03f6d0u: goto P_0c03f6d0;
case 0x0c03f6d2u: goto P_0c03f6d2;
case 0x0c03f6d4u: goto P_0c03f6d4;
case 0x0c03f6d6u: goto P_0c03f6d6;
case 0x0c03f6d8u: goto P_0c03f6d8;
case 0x0c03f6dau: goto P_0c03f6da;
case 0x0c03f6dcu: goto P_0c03f6dc;
case 0x0c03f6deu: goto P_0c03f6de;
case 0x0c03f6e0u: goto P_0c03f6e0;
case 0x0c03f6e2u: goto P_0c03f6e2;
case 0x0c03f6e4u: goto P_0c03f6e4;
case 0x0c03f6e6u: goto P_0c03f6e6;
case 0x0c03f6e8u: goto P_0c03f6e8;
case 0x0c03f6eau: goto P_0c03f6ea;
case 0x0c03f6ecu: goto P_0c03f6ec;
case 0x0c03f6eeu: goto P_0c03f6ee;
case 0x0c03f6f0u: goto P_0c03f6f0;
case 0x0c03f6f2u: goto P_0c03f6f2;
case 0x0c03f6f4u: goto P_0c03f6f4;
case 0x0c03f6f6u: goto P_0c03f6f6;
case 0x0c03f6f8u: goto P_0c03f6f8;
case 0x0c03f6fau: goto P_0c03f6fa;
case 0x0c03f6fcu: goto P_0c03f6fc;
case 0x0c03f6feu: goto P_0c03f6fe;
case 0x0c03f700u: goto P_0c03f700;
case 0x0c03f702u: goto P_0c03f702;
case 0x0c03f704u: goto P_0c03f704;
case 0x0c03f706u: goto P_0c03f706;
case 0x0c03f708u: goto P_0c03f708;
case 0x0c03f70au: goto P_0c03f70a;
case 0x0c03f70cu: goto P_0c03f70c;
case 0x0c03f70eu: goto P_0c03f70e;
case 0x0c03f710u: goto P_0c03f710;
case 0x0c03f712u: goto P_0c03f712;
case 0x0c03f714u: goto P_0c03f714;
case 0x0c03f716u: goto P_0c03f716;
case 0x0c03f718u: goto P_0c03f718;
case 0x0c03f71au: goto P_0c03f71a;
case 0x0c03f71cu: goto P_0c03f71c;
case 0x0c03f71eu: goto P_0c03f71e;
case 0x0c03f720u: goto P_0c03f720;
case 0x0c03f722u: goto P_0c03f722;
case 0x0c03f724u: goto P_0c03f724;
case 0x0c03f726u: goto P_0c03f726;
case 0x0c03f728u: goto P_0c03f728;
case 0x0c03f72au: goto P_0c03f72a;
case 0x0c03f72cu: goto P_0c03f72c;
case 0x0c03f72eu: goto P_0c03f72e;
case 0x0c03f730u: goto P_0c03f730;
case 0x0c03f732u: goto P_0c03f732;
case 0x0c03f734u: goto P_0c03f734;
case 0x0c03f736u: goto P_0c03f736;
case 0x0c03f738u: goto P_0c03f738;
case 0x0c03f73au: goto P_0c03f73a;
case 0x0c03f73cu: goto P_0c03f73c;
case 0x0c03f73eu: goto P_0c03f73e;
case 0x0c03f740u: goto P_0c03f740;
case 0x0c03f742u: goto P_0c03f742;
case 0x0c03f744u: goto P_0c03f744;
case 0x0c03f746u: goto P_0c03f746;
case 0x0c03f748u: goto P_0c03f748;
case 0x0c03f74au: goto P_0c03f74a;
case 0x0c03f74cu: goto P_0c03f74c;
case 0x0c03f74eu: goto P_0c03f74e;
case 0x0c03f750u: goto P_0c03f750;
case 0x0c03f752u: goto P_0c03f752;
case 0x0c03f754u: goto P_0c03f754;
case 0x0c03f756u: goto P_0c03f756;
case 0x0c03f758u: goto P_0c03f758;
case 0x0c03f75au: goto P_0c03f75a;
case 0x0c03f75cu: goto P_0c03f75c;
case 0x0c03f75eu: goto P_0c03f75e;
case 0x0c03f760u: goto P_0c03f760;
case 0x0c03f762u: goto P_0c03f762;
case 0x0c03f764u: goto P_0c03f764;
case 0x0c03f830u: goto P_0c03f830;
case 0x0c03f832u: goto P_0c03f832;
case 0x0c03f834u: goto P_0c03f834;
case 0x0c03f836u: goto P_0c03f836;
case 0x0c03f838u: goto P_0c03f838;
case 0x0c03f83au: goto P_0c03f83a;
case 0x0c03f83cu: goto P_0c03f83c;
case 0x0c03f83eu: goto P_0c03f83e;
case 0x0c03f840u: goto P_0c03f840;
case 0x0c03f842u: goto P_0c03f842;
case 0x0c03f844u: goto P_0c03f844;
case 0x0c03f846u: goto P_0c03f846;
case 0x0c03f848u: goto P_0c03f848;
case 0x0c03f84au: goto P_0c03f84a;
case 0x0c03f84cu: goto P_0c03f84c;
case 0x0c03f84eu: goto P_0c03f84e;
case 0x0c03f850u: goto P_0c03f850;
case 0x0c03f852u: goto P_0c03f852;
case 0x0c03f854u: goto P_0c03f854;
case 0x0c03f856u: goto P_0c03f856;
case 0x0c03f858u: goto P_0c03f858;
case 0x0c03f85au: goto P_0c03f85a;
case 0x0c03f85cu: goto P_0c03f85c;
case 0x0c03f85eu: goto P_0c03f85e;
case 0x0c03f860u: goto P_0c03f860;
case 0x0c03f862u: goto P_0c03f862;
case 0x0c03f864u: goto P_0c03f864;
case 0x0c03f866u: goto P_0c03f866;
case 0x0c03f868u: goto P_0c03f868;
case 0x0c03f86au: goto P_0c03f86a;
case 0x0c03f86cu: goto P_0c03f86c;
case 0x0c03f86eu: goto P_0c03f86e;
case 0x0c03f870u: goto P_0c03f870;
case 0x0c03f872u: goto P_0c03f872;
case 0x0c03f874u: goto P_0c03f874;
case 0x0c03f876u: goto P_0c03f876;
case 0x0c03f878u: goto P_0c03f878;
case 0x0c03f87au: goto P_0c03f87a;
case 0x0c03f87cu: goto P_0c03f87c;
case 0x0c03f87eu: goto P_0c03f87e;
case 0x0c03f880u: goto P_0c03f880;
case 0x0c03f882u: goto P_0c03f882;
case 0x0c03f884u: goto P_0c03f884;
case 0x0c03f886u: goto P_0c03f886;
case 0x0c03f888u: goto P_0c03f888;
case 0x0c03f88au: goto P_0c03f88a;
case 0x0c03f88cu: goto P_0c03f88c;
case 0x0c03f88eu: goto P_0c03f88e;
case 0x0c03f890u: goto P_0c03f890;
case 0x0c03f892u: goto P_0c03f892;
case 0x0c03f894u: goto P_0c03f894;
case 0x0c03f896u: goto P_0c03f896;
case 0x0c03f898u: goto P_0c03f898;
case 0x0c03f89au: goto P_0c03f89a;
case 0x0c03f89cu: goto P_0c03f89c;
case 0x0c03f89eu: goto P_0c03f89e;
case 0x0c03f8a0u: goto P_0c03f8a0;
case 0x0c03f8a2u: goto P_0c03f8a2;
case 0x0c03f8a4u: goto P_0c03f8a4;
case 0x0c03f8a6u: goto P_0c03f8a6;
case 0x0c03f8a8u: goto P_0c03f8a8;
case 0x0c03f8aau: goto P_0c03f8aa;
case 0x0c03f8acu: goto P_0c03f8ac;
case 0x0c03f8aeu: goto P_0c03f8ae;
case 0x0c03f8b0u: goto P_0c03f8b0;
case 0x0c03f8b2u: goto P_0c03f8b2;
case 0x0c03f8b4u: goto P_0c03f8b4;
case 0x0c03f8b6u: goto P_0c03f8b6;
case 0x0c03f8b8u: goto P_0c03f8b8;
case 0x0c03f8bau: goto P_0c03f8ba;
case 0x0c03f8bcu: goto P_0c03f8bc;
case 0x0c03f8beu: goto P_0c03f8be;
case 0x0c03f8c0u: goto P_0c03f8c0;
case 0x0c03f8c2u: goto P_0c03f8c2;
case 0x0c03f8c4u: goto P_0c03f8c4;
case 0x0c03f8c6u: goto P_0c03f8c6;
case 0x0c03f8c8u: goto P_0c03f8c8;
case 0x0c03f8cau: goto P_0c03f8ca;
case 0x0c03f8ccu: goto P_0c03f8cc;
case 0x0c03f8ceu: goto P_0c03f8ce;
case 0x0c03f8d0u: goto P_0c03f8d0;
case 0x0c03f8d2u: goto P_0c03f8d2;
case 0x0c03f8d4u: goto P_0c03f8d4;
case 0x0c03f8d6u: goto P_0c03f8d6;
case 0x0c03f8d8u: goto P_0c03f8d8;
case 0x0c03f8dau: goto P_0c03f8da;
case 0x0c03f8dcu: goto P_0c03f8dc;
case 0x0c03f8deu: goto P_0c03f8de;
case 0x0c03f8e0u: goto P_0c03f8e0;
case 0x0c03f8e2u: goto P_0c03f8e2;
case 0x0c03f8e4u: goto P_0c03f8e4;
case 0x0c03f8e6u: goto P_0c03f8e6;
case 0x0c03f8e8u: goto P_0c03f8e8;
case 0x0c03f8eau: goto P_0c03f8ea;
case 0x0c03f8ecu: goto P_0c03f8ec;
case 0x0c03f8eeu: goto P_0c03f8ee;
case 0x0c03f8f0u: goto P_0c03f8f0;
case 0x0c03f8f2u: goto P_0c03f8f2;
case 0x0c03f8f4u: goto P_0c03f8f4;
case 0x0c03f8f6u: goto P_0c03f8f6;
case 0x0c03f8f8u: goto P_0c03f8f8;
case 0x0c03f8fau: goto P_0c03f8fa;
case 0x0c03f8fcu: goto P_0c03f8fc;
case 0x0c03f8feu: goto P_0c03f8fe;
case 0x0c03f900u: goto P_0c03f900;
case 0x0c03f902u: goto P_0c03f902;
case 0x0c03f904u: goto P_0c03f904;
case 0x0c03f906u: goto P_0c03f906;
case 0x0c03f908u: goto P_0c03f908;
case 0x0c03f90au: goto P_0c03f90a;
case 0x0c03f90cu: goto P_0c03f90c;
case 0x0c03f90eu: goto P_0c03f90e;
case 0x0c03f910u: goto P_0c03f910;
case 0x0c03f912u: goto P_0c03f912;
case 0x0c03f914u: goto P_0c03f914;
case 0x0c03f916u: goto P_0c03f916;
case 0x0c03f918u: goto P_0c03f918;
case 0x0c03f91au: goto P_0c03f91a;
case 0x0c03f91cu: goto P_0c03f91c;
case 0x0c03f91eu: goto P_0c03f91e;
case 0x0c03f920u: goto P_0c03f920;
case 0x0c03f922u: goto P_0c03f922;
case 0x0c03f924u: goto P_0c03f924;
case 0x0c03f926u: goto P_0c03f926;
case 0x0c03f928u: goto P_0c03f928;
case 0x0c03f92au: goto P_0c03f92a;
case 0x0c03f92cu: goto P_0c03f92c;
case 0x0c03f92eu: goto P_0c03f92e;
case 0x0c03f930u: goto P_0c03f930;
case 0x0c03f932u: goto P_0c03f932;
case 0x0c03f934u: goto P_0c03f934;
case 0x0c03f936u: goto P_0c03f936;
case 0x0c03f938u: goto P_0c03f938;
case 0x0c03f93au: goto P_0c03f93a;
case 0x0c03f93cu: goto P_0c03f93c;
case 0x0c03f93eu: goto P_0c03f93e;
case 0x0c03f940u: goto P_0c03f940;
case 0x0c03f942u: goto P_0c03f942;
case 0x0c03f944u: goto P_0c03f944;
case 0x0c03f946u: goto P_0c03f946;
case 0x0c03f948u: goto P_0c03f948;
case 0x0c03f94au: goto P_0c03f94a;
case 0x0c03f94cu: goto P_0c03f94c;
case 0x0c03f94eu: goto P_0c03f94e;
case 0x0c03f950u: goto P_0c03f950;
case 0x0c03f952u: goto P_0c03f952;
case 0x0c03f954u: goto P_0c03f954;
case 0x0c03f956u: goto P_0c03f956;
case 0x0c03f958u: goto P_0c03f958;
case 0x0c03f95au: goto P_0c03f95a;
case 0x0c03f95cu: goto P_0c03f95c;
case 0x0c03f95eu: goto P_0c03f95e;
case 0x0c03f960u: goto P_0c03f960;
case 0x0c03f962u: goto P_0c03f962;
case 0x0c03f964u: goto P_0c03f964;
case 0x0c03f966u: goto P_0c03f966;
case 0x0c03f968u: goto P_0c03f968;
case 0x0c03f9b0u: goto P_0c03f9b0;
case 0x0c03f9b2u: goto P_0c03f9b2;
case 0x0c03f9b4u: goto P_0c03f9b4;
case 0x0c03f9b6u: goto P_0c03f9b6;
case 0x0c03f9b8u: goto P_0c03f9b8;
case 0x0c03f9c0u: goto P_0c03f9c0;
case 0x0c03f9c2u: goto P_0c03f9c2;
case 0x0c03f9c4u: goto P_0c03f9c4;
case 0x0c03f9c6u: goto P_0c03f9c6;
case 0x0c03f9c8u: goto P_0c03f9c8;
case 0x0c03f9cau: goto P_0c03f9ca;
case 0x0c03f9ccu: goto P_0c03f9cc;
case 0x0c03f9ceu: goto P_0c03f9ce;
case 0x0c03f9d0u: goto P_0c03f9d0;
case 0x0c03f9d2u: goto P_0c03f9d2;
case 0x0c03f9d4u: goto P_0c03f9d4;
case 0x0c03f9d6u: goto P_0c03f9d6;
case 0x0c03f9d8u: goto P_0c03f9d8;
case 0x0c03f9dau: goto P_0c03f9da;
case 0x0c03f9dcu: goto P_0c03f9dc;
case 0x0c03f9deu: goto P_0c03f9de;
case 0x0c03f9e0u: goto P_0c03f9e0;
case 0x0c03f9e2u: goto P_0c03f9e2;
case 0x0c03f9e4u: goto P_0c03f9e4;
case 0x0c03f9e6u: goto P_0c03f9e6;
case 0x0c03f9e8u: goto P_0c03f9e8;
case 0x0c03f9eau: goto P_0c03f9ea;
case 0x0c03f9ecu: goto P_0c03f9ec;
case 0x0c03f9eeu: goto P_0c03f9ee;
case 0x0c03f9f0u: goto P_0c03f9f0;
case 0x0c03f9f2u: goto P_0c03f9f2;
case 0x0c03f9f4u: goto P_0c03f9f4;
case 0x0c03f9f6u: goto P_0c03f9f6;
case 0x0c03f9f8u: goto P_0c03f9f8;
case 0x0c03f9fau: goto P_0c03f9fa;
case 0x0c03f9fcu: goto P_0c03f9fc;
case 0x0c03f9feu: goto P_0c03f9fe;
case 0x0c03fa00u: goto P_0c03fa00;
case 0x0c03fa02u: goto P_0c03fa02;
case 0x0c03fa04u: goto P_0c03fa04;
case 0x0c03fa06u: goto P_0c03fa06;
case 0x0c03fa08u: goto P_0c03fa08;
case 0x0c03fa0au: goto P_0c03fa0a;
case 0x0c03fa0cu: goto P_0c03fa0c;
case 0x0c03fa0eu: goto P_0c03fa0e;
case 0x0c03fa10u: goto P_0c03fa10;
case 0x0c03fa12u: goto P_0c03fa12;
case 0x0c03fa14u: goto P_0c03fa14;
case 0x0c03fa16u: goto P_0c03fa16;
case 0x0c03fa18u: goto P_0c03fa18;
case 0x0c03fa1au: goto P_0c03fa1a;
case 0x0c03fa1cu: goto P_0c03fa1c;
case 0x0c03fa1eu: goto P_0c03fa1e;
case 0x0c03fa20u: goto P_0c03fa20;
case 0x0c03fa22u: goto P_0c03fa22;
case 0x0c03fa24u: goto P_0c03fa24;
case 0x0c03fa26u: goto P_0c03fa26;
case 0x0c03fa28u: goto P_0c03fa28;
case 0x0c03fa2au: goto P_0c03fa2a;
case 0x0c03fa2cu: goto P_0c03fa2c;
case 0x0c03fa2eu: goto P_0c03fa2e;
case 0x0c03fa30u: goto P_0c03fa30;
case 0x0c03fa32u: goto P_0c03fa32;
case 0x0c03fa34u: goto P_0c03fa34;
case 0x0c03fa36u: goto P_0c03fa36;
case 0x0c03fa38u: goto P_0c03fa38;
case 0x0c03fa3au: goto P_0c03fa3a;
case 0x0c03fa3cu: goto P_0c03fa3c;
case 0x0c03fa3eu: goto P_0c03fa3e;
case 0x0c03fa40u: goto P_0c03fa40;
case 0x0c03fa42u: goto P_0c03fa42;
case 0x0c03fa44u: goto P_0c03fa44;
case 0x0c03fa46u: goto P_0c03fa46;
case 0x0c03fa48u: goto P_0c03fa48;
case 0x0c03fa4au: goto P_0c03fa4a;
case 0x0c03fa4cu: goto P_0c03fa4c;
case 0x0c03fa4eu: goto P_0c03fa4e;
case 0x0c03fa50u: goto P_0c03fa50;
case 0x0c03fa52u: goto P_0c03fa52;
case 0x0c03fa54u: goto P_0c03fa54;
case 0x0c03fa56u: goto P_0c03fa56;
case 0x0c03fa58u: goto P_0c03fa58;
case 0x0c03fa5au: goto P_0c03fa5a;
case 0x0c03fa5cu: goto P_0c03fa5c;
case 0x0c03fa5eu: goto P_0c03fa5e;
case 0x0c03fa60u: goto P_0c03fa60;
case 0x0c03fa62u: goto P_0c03fa62;
case 0x0c03fa64u: goto P_0c03fa64;
case 0x0c03fa66u: goto P_0c03fa66;
case 0x0c03fa68u: goto P_0c03fa68;
case 0x0c03fa6au: goto P_0c03fa6a;
case 0x0c03fa6cu: goto P_0c03fa6c;
case 0x0c03fa6eu: goto P_0c03fa6e;
case 0x0c03fa70u: goto P_0c03fa70;
case 0x0c03fa72u: goto P_0c03fa72;
case 0x0c03fa74u: goto P_0c03fa74;
case 0x0c03fa76u: goto P_0c03fa76;
case 0x0c03fa78u: goto P_0c03fa78;
case 0x0c03fa7au: goto P_0c03fa7a;
case 0x0c03fa7cu: goto P_0c03fa7c;
case 0x0c03fa7eu: goto P_0c03fa7e;
case 0x0c03fa80u: goto P_0c03fa80;
case 0x0c03fa82u: goto P_0c03fa82;
case 0x0c03fa84u: goto P_0c03fa84;
case 0x0c03fa86u: goto P_0c03fa86;
case 0x0c03fa88u: goto P_0c03fa88;
case 0x0c03fa8au: goto P_0c03fa8a;
case 0x0c03fa8cu: goto P_0c03fa8c;
case 0x0c03fa8eu: goto P_0c03fa8e;
case 0x0c03fa90u: goto P_0c03fa90;
case 0x0c03fa92u: goto P_0c03fa92;
case 0x0c03fa94u: goto P_0c03fa94;
case 0x0c03fa96u: goto P_0c03fa96;
case 0x0c03fa98u: goto P_0c03fa98;
case 0x0c03fa9au: goto P_0c03fa9a;
case 0x0c03fa9cu: goto P_0c03fa9c;
case 0x0c03fa9eu: goto P_0c03fa9e;
case 0x0c03faa0u: goto P_0c03faa0;
case 0x0c03faa2u: goto P_0c03faa2;
case 0x0c03faa4u: goto P_0c03faa4;
case 0x0c03faa6u: goto P_0c03faa6;
case 0x0c03faa8u: goto P_0c03faa8;
case 0x0c03faaau: goto P_0c03faaa;
case 0x0c03faacu: goto P_0c03faac;
case 0x0c03faaeu: goto P_0c03faae;
case 0x0c03fab0u: goto P_0c03fab0;
case 0x0c03fab2u: goto P_0c03fab2;
case 0x0c03fab4u: goto P_0c03fab4;
case 0x0c03fab6u: goto P_0c03fab6;
case 0x0c03fab8u: goto P_0c03fab8;
case 0x0c03fabau: goto P_0c03faba;
case 0x0c03fabcu: goto P_0c03fabc;
case 0x0c03fabeu: goto P_0c03fabe;
case 0x0c03fac0u: goto P_0c03fac0;
case 0x0c03fac2u: goto P_0c03fac2;
case 0x0c03fac4u: goto P_0c03fac4;
case 0x0c03fac6u: goto P_0c03fac6;
case 0x0c03fac8u: goto P_0c03fac8;
case 0x0c03facau: goto P_0c03faca;
case 0x0c03faccu: goto P_0c03facc;
case 0x0c03faceu: goto P_0c03face;
case 0x0c03fad0u: goto P_0c03fad0;
case 0x0c03fad2u: goto P_0c03fad2;
case 0x0c03fad4u: goto P_0c03fad4;
case 0x0c03fad6u: goto P_0c03fad6;
case 0x0c03fad8u: goto P_0c03fad8;
case 0x0c03fadau: goto P_0c03fada;
case 0x0c03fadcu: goto P_0c03fadc;
case 0x0c03fadeu: goto P_0c03fade;
case 0x0c03fae0u: goto P_0c03fae0;
case 0x0c03fae2u: goto P_0c03fae2;
case 0x0c03fae4u: goto P_0c03fae4;
case 0x0c03fae6u: goto P_0c03fae6;
case 0x0c03fae8u: goto P_0c03fae8;
case 0x0c03faeau: goto P_0c03faea;
case 0x0c03faecu: goto P_0c03faec;
case 0x0c03faeeu: goto P_0c03faee;
case 0x0c03faf0u: goto P_0c03faf0;
case 0x0c03faf2u: goto P_0c03faf2;
case 0x0c03faf4u: goto P_0c03faf4;
case 0x0c03faf6u: goto P_0c03faf6;
case 0x0c03faf8u: goto P_0c03faf8;
case 0x0c03fafau: goto P_0c03fafa;
case 0x0c03fafcu: goto P_0c03fafc;
case 0x0c03fafeu: goto P_0c03fafe;
case 0x0c03fb00u: goto P_0c03fb00;
case 0x0c03fb02u: goto P_0c03fb02;
case 0x0c03fb04u: goto P_0c03fb04;
case 0x0c03fb06u: goto P_0c03fb06;
case 0x0c03fb08u: goto P_0c03fb08;
case 0x0c03fb0au: goto P_0c03fb0a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03f690: /* original 2fe6, guest PC 0x0c03f690 */
if(!s->budget--) { s->failed_pc=0x0c03f690u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f692;
P_0c03f692: /* original e300, guest PC 0x0c03f692 */
if(!s->budget--) { s->failed_pc=0x0c03f692u; return 0; }
r[3]=0x00000000u;
goto P_0c03f694;
P_0c03f694: /* original 2fd6, guest PC 0x0c03f694 */
if(!s->budget--) { s->failed_pc=0x0c03f694u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f696;
P_0c03f696: /* original edff, guest PC 0x0c03f696 */
if(!s->budget--) { s->failed_pc=0x0c03f696u; return 0; }
r[13]=0xffffffffu;
goto P_0c03f698;
P_0c03f698: /* original 2fc6, guest PC 0x0c03f698 */
if(!s->budget--) { s->failed_pc=0x0c03f698u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f69a;
P_0c03f69a: /* original 2fb6, guest PC 0x0c03f69a */
if(!s->budget--) { s->failed_pc=0x0c03f69au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f69c;
P_0c03f69c: /* original 2fa6, guest PC 0x0c03f69c */
if(!s->budget--) { s->failed_pc=0x0c03f69cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f69e;
P_0c03f69e: /* original 2f96, guest PC 0x0c03f69e */
if(!s->budget--) { s->failed_pc=0x0c03f69eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f6a0;
P_0c03f6a0: /* original 2f86, guest PC 0x0c03f6a0 */
if(!s->budget--) { s->failed_pc=0x0c03f6a0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f6a2;
P_0c03f6a2: /* original 4f22, guest PC 0x0c03f6a2 */
if(!s->budget--) { s->failed_pc=0x0c03f6a2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f6a4;
P_0c03f6a4: /* original 4f12, guest PC 0x0c03f6a4 */
if(!s->budget--) { s->failed_pc=0x0c03f6a4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03f6a6;
P_0c03f6a6: /* original 7ff0, guest PC 0x0c03f6a6 */
if(!s->budget--) { s->failed_pc=0x0c03f6a6u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c03f6a8;
P_0c03f6a8: /* original 1f33, guest PC 0x0c03f6a8 */
if(!s->budget--) { s->failed_pc=0x0c03f6a8u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c03f6aa;
P_0c03f6aa: /* original de3d, guest PC 0x0c03f6aa */
if(!s->budget--) { s->failed_pc=0x0c03f6aau; return 0; }
r[14]=read(ram,0x0c03f7a0u,4);
goto P_0c03f6ac;
P_0c03f6ac: /* original d838, guest PC 0x0c03f6ac */
if(!s->budget--) { s->failed_pc=0x0c03f6acu; return 0; }
r[8]=read(ram,0x0c03f790u,4);
goto P_0c03f6ae;
P_0c03f6ae: /* original dc3f, guest PC 0x0c03f6ae */
if(!s->budget--) { s->failed_pc=0x0c03f6aeu; return 0; }
r[12]=read(ram,0x0c03f7acu,4);
goto P_0c03f6b0;
P_0c03f6b0: /* original 2f42, guest PC 0x0c03f6b0 */
if(!s->budget--) { s->failed_pc=0x0c03f6b0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c03f6b2;
P_0c03f6b2: /* original d23c, guest PC 0x0c03f6b2 */
if(!s->budget--) { s->failed_pc=0x0c03f6b2u; return 0; }
r[2]=read(ram,0x0c03f7a4u,4);
goto P_0c03f6b4;
P_0c03f6b4: /* original 6322, guest PC 0x0c03f6b4 */
if(!s->budget--) { s->failed_pc=0x0c03f6b4u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f6b6;
P_0c03f6b6: /* original a046, guest PC 0x0c03f6b6 */
if(!s->budget--) { s->failed_pc=0x0c03f6b6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c03f746;
P_0c03f6b8: /* original 1f31, guest PC 0x0c03f6b8 */
if(!s->budget--) { s->failed_pc=0x0c03f6b8u; return 0; }
write(ram,r[15]+4,r[3],4);
if(!vf3_matrix_family(0x0c03f6bau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f6bau; return 0; } return 1;
P_0c03f6c0: /* original 59f1, guest PC 0x0c03f6c0 */
if(!s->budget--) { s->failed_pc=0x0c03f6c0u; return 0; }
r[9]=read(ram,r[15]+4,4);
goto P_0c03f6c2;
P_0c03f6c2: /* original e200, guest PC 0x0c03f6c2 */
if(!s->budget--) { s->failed_pc=0x0c03f6c2u; return 0; }
r[2]=0x00000000u;
goto P_0c03f6c4;
P_0c03f6c4: /* original 63e2, guest PC 0x0c03f6c4 */
if(!s->budget--) { s->failed_pc=0x0c03f6c4u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03f6c6;
P_0c03f6c6: /* original 6b93, guest PC 0x0c03f6c6 */
if(!s->budget--) { s->failed_pc=0x0c03f6c6u; return 0; }
r[11]=r[9];
goto P_0c03f6c8;
P_0c03f6c8: /* original 4b08, guest PC 0x0c03f6c8 */
if(!s->budget--) { s->failed_pc=0x0c03f6c8u; return 0; }
r[11]<<=2;
goto P_0c03f6ca;
P_0c03f6ca: /* original 4b00, guest PC 0x0c03f6ca */
if(!s->budget--) { s->failed_pc=0x0c03f6cau; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c03f6cc;
P_0c03f6cc: /* original 33bc, guest PC 0x0c03f6cc */
if(!s->budget--) { s->failed_pc=0x0c03f6ccu; return 0; }
r[3]+=r[11];
goto P_0c03f6ce;
P_0c03f6ce: /* original 6132, guest PC 0x0c03f6ce */
if(!s->budget--) { s->failed_pc=0x0c03f6ceu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c03f6d0;
P_0c03f6d0: /* original 3126, guest PC 0x0c03f6d0 */
if(!s->budget--) { s->failed_pc=0x0c03f6d0u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[2])!=0);
goto P_0c03f6d2;
P_0c03f6d2: /* original 8b32, guest PC 0x0c03f6d2 */
if(!s->budget--) { s->failed_pc=0x0c03f6d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f73a; }
goto P_0c03f6d4;
P_0c03f6d4: /* original 60e2, guest PC 0x0c03f6d4 */
if(!s->budget--) { s->failed_pc=0x0c03f6d4u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c03f6d6;
P_0c03f6d6: /* original 30bc, guest PC 0x0c03f6d6 */
if(!s->budget--) { s->failed_pc=0x0c03f6d6u; return 0; }
r[0]+=r[11];
goto P_0c03f6d8;
P_0c03f6d8: /* original 6302, guest PC 0x0c03f6d8 */
if(!s->budget--) { s->failed_pc=0x0c03f6d8u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c03f6da;
P_0c03f6da: /* original 73ff, guest PC 0x0c03f6da */
if(!s->budget--) { s->failed_pc=0x0c03f6dau; return 0; }
r[3]+=0xffffffffu;
goto P_0c03f6dc;
P_0c03f6dc: /* original 2032, guest PC 0x0c03f6dc */
if(!s->budget--) { s->failed_pc=0x0c03f6dcu; return 0; }
write(ram,r[0],r[3],4);
goto P_0c03f6de;
P_0c03f6de: /* original 61e2, guest PC 0x0c03f6de */
if(!s->budget--) { s->failed_pc=0x0c03f6deu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c03f6e0;
P_0c03f6e0: /* original 31bc, guest PC 0x0c03f6e0 */
if(!s->budget--) { s->failed_pc=0x0c03f6e0u; return 0; }
r[1]+=r[11];
goto P_0c03f6e2;
P_0c03f6e2: /* original 6312, guest PC 0x0c03f6e2 */
if(!s->budget--) { s->failed_pc=0x0c03f6e2u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c03f6e4;
P_0c03f6e4: /* original 2338, guest PC 0x0c03f6e4 */
if(!s->budget--) { s->failed_pc=0x0c03f6e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03f6e6;
P_0c03f6e6: /* original 8b28, guest PC 0x0c03f6e6 */
if(!s->budget--) { s->failed_pc=0x0c03f6e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f73a; }
goto P_0c03f6e8;
P_0c03f6e8: /* original 63e2, guest PC 0x0c03f6e8 */
if(!s->budget--) { s->failed_pc=0x0c03f6e8u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03f6ea;
P_0c03f6ea: /* original 33bc, guest PC 0x0c03f6ea */
if(!s->budget--) { s->failed_pc=0x0c03f6eau; return 0; }
r[3]+=r[11];
goto P_0c03f6ec;
P_0c03f6ec: /* original 5131, guest PC 0x0c03f6ec */
if(!s->budget--) { s->failed_pc=0x0c03f6ecu; return 0; }
r[1]=read(ram,r[3]+4,4);
goto P_0c03f6ee;
P_0c03f6ee: /* original e33c, guest PC 0x0c03f6ee */
if(!s->budget--) { s->failed_pc=0x0c03f6eeu; return 0; }
r[3]=0x0000003cu;
goto P_0c03f6f0;
P_0c03f6f0: /* original 0137, guest PC 0x0c03f6f0 */
if(!s->budget--) { s->failed_pc=0x0c03f6f0u; return 0; }
r[19]=r[1]*r[3];
goto P_0c03f6f2;
P_0c03f6f2: /* original 1f12, guest PC 0x0c03f6f2 */
if(!s->budget--) { s->failed_pc=0x0c03f6f2u; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c03f6f4;
P_0c03f6f4: /* original 61c2, guest PC 0x0c03f6f4 */
if(!s->budget--) { s->failed_pc=0x0c03f6f4u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c03f6f6;
P_0c03f6f6: /* original 0a1a, guest PC 0x0c03f6f6 */
if(!s->budget--) { s->failed_pc=0x0c03f6f6u; return 0; }
r[10]=r[19];
goto P_0c03f6f8;
P_0c03f6f8: /* original 31ac, guest PC 0x0c03f6f8 */
if(!s->budget--) { s->failed_pc=0x0c03f6f8u; return 0; }
r[1]+=r[10];
goto P_0c03f6fa;
P_0c03f6fa: /* original 501a, guest PC 0x0c03f6fa */
if(!s->budget--) { s->failed_pc=0x0c03f6fau; return 0; }
r[0]=read(ram,r[1]+40,4);
goto P_0c03f6fc;
P_0c03f6fc: /* original 2008, guest PC 0x0c03f6fc */
if(!s->budget--) { s->failed_pc=0x0c03f6fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c03f6fe;
P_0c03f6fe: /* original 8b08, guest PC 0x0c03f6fe */
if(!s->budget--) { s->failed_pc=0x0c03f6feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f712; }
goto P_0c03f700;
P_0c03f700: /* original d12d, guest PC 0x0c03f700 */
if(!s->budget--) { s->failed_pc=0x0c03f700u; return 0; }
r[1]=read(ram,0x0c03f7b8u,4);
goto P_0c03f702;
P_0c03f702: /* original 64c2, guest PC 0x0c03f702 */
if(!s->budget--) { s->failed_pc=0x0c03f702u; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c03f704;
P_0c03f704: /* original 410b, guest PC 0x0c03f704 */
if(!s->budget--) { s->failed_pc=0x0c03f704u; return 0; }
target=r[1];
r[16]=code_base|0x0c03f708u;
r[4]+=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f708u) { target=s->pc; goto dispatch; }
goto P_0c03f708;
P_0c03f706: /* original 34ac, guest PC 0x0c03f706 */
if(!s->budget--) { s->failed_pc=0x0c03f706u; return 0; }
r[4]+=r[10];
goto P_0c03f708;
P_0c03f708: /* original 6403, guest PC 0x0c03f708 */
if(!s->budget--) { s->failed_pc=0x0c03f708u; return 0; }
r[4]=r[0];
goto P_0c03f70a;
P_0c03f70a: /* original 2448, guest PC 0x0c03f70a */
if(!s->budget--) { s->failed_pc=0x0c03f70au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03f70c;
P_0c03f70c: /* original 8901, guest PC 0x0c03f70c */
if(!s->budget--) { s->failed_pc=0x0c03f70cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03f712; }
goto P_0c03f70e;
P_0c03f70e: /* original e201, guest PC 0x0c03f70e */
if(!s->budget--) { s->failed_pc=0x0c03f70eu; return 0; }
r[2]=0x00000001u;
goto P_0c03f710;
P_0c03f710: /* original 1f23, guest PC 0x0c03f710 */
if(!s->budget--) { s->failed_pc=0x0c03f710u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c03f712;
P_0c03f712: /* original 63c2, guest PC 0x0c03f712 */
if(!s->budget--) { s->failed_pc=0x0c03f712u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c03f714;
P_0c03f714: /* original e200, guest PC 0x0c03f714 */
if(!s->budget--) { s->failed_pc=0x0c03f714u; return 0; }
r[2]=0x00000000u;
goto P_0c03f716;
P_0c03f716: /* original 33ac, guest PC 0x0c03f716 */
if(!s->budget--) { s->failed_pc=0x0c03f716u; return 0; }
r[3]+=r[10];
goto P_0c03f718;
P_0c03f718: /* original 132b, guest PC 0x0c03f718 */
if(!s->budget--) { s->failed_pc=0x0c03f718u; return 0; }
write(ram,r[3]+44,r[2],4);
goto P_0c03f71a;
P_0c03f71a: /* original 63c2, guest PC 0x0c03f71a */
if(!s->budget--) { s->failed_pc=0x0c03f71au; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c03f71c;
P_0c03f71c: /* original 33ac, guest PC 0x0c03f71c */
if(!s->budget--) { s->failed_pc=0x0c03f71cu; return 0; }
r[3]+=r[10];
goto P_0c03f71e;
P_0c03f71e: /* original 13de, guest PC 0x0c03f71e */
if(!s->budget--) { s->failed_pc=0x0c03f71eu; return 0; }
write(ram,r[3]+56,r[13],4);
goto P_0c03f720;
P_0c03f720: /* original d326, guest PC 0x0c03f720 */
if(!s->budget--) { s->failed_pc=0x0c03f720u; return 0; }
r[3]=read(ram,0x0c03f7bcu,4);
goto P_0c03f722;
P_0c03f722: /* original 430b, guest PC 0x0c03f722 */
if(!s->budget--) { s->failed_pc=0x0c03f722u; return 0; }
target=r[3];
r[16]=code_base|0x0c03f726u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f726u) { target=s->pc; goto dispatch; }
goto P_0c03f726;
P_0c03f724: /* original 54f2, guest PC 0x0c03f724 */
if(!s->budget--) { s->failed_pc=0x0c03f724u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c03f726;
P_0c03f726: /* original 6082, guest PC 0x0c03f726 */
if(!s->budget--) { s->failed_pc=0x0c03f726u; return 0; }
tmp=read(ram,r[8],4);
r[0]=tmp;
goto P_0c03f728;
P_0c03f728: /* original 6a93, guest PC 0x0c03f728 */
if(!s->budget--) { s->failed_pc=0x0c03f728u; return 0; }
r[10]=r[9];
goto P_0c03f72a;
P_0c03f72a: /* original 4a00, guest PC 0x0c03f72a */
if(!s->budget--) { s->failed_pc=0x0c03f72au; return 0; }
r[17]=(r[17]&~1u)|((r[10]>>31)!=0);
r[10]<<=1;
goto P_0c03f72c;
P_0c03f72c: /* original b338, guest PC 0x0c03f72c */
if(!s->budget--) { s->failed_pc=0x0c03f72cu; return 0; }
target=code_base|0x0c03fda0u; r[16]=code_base|0x0c03f730u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f730u) { target=s->pc; goto dispatch; }
goto P_0c03f730;
P_0c03f72e: /* original 04ad, guest PC 0x0c03f72e */
if(!s->budget--) { s->failed_pc=0x0c03f72eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c03f730;
P_0c03f730: /* original 62e2, guest PC 0x0c03f730 */
if(!s->budget--) { s->failed_pc=0x0c03f730u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f732;
P_0c03f732: /* original 32bc, guest PC 0x0c03f732 */
if(!s->budget--) { s->failed_pc=0x0c03f732u; return 0; }
r[2]+=r[11];
goto P_0c03f734;
P_0c03f734: /* original 12d1, guest PC 0x0c03f734 */
if(!s->budget--) { s->failed_pc=0x0c03f734u; return 0; }
write(ram,r[2]+4,r[13],4);
goto P_0c03f736;
P_0c03f736: /* original 6082, guest PC 0x0c03f736 */
if(!s->budget--) { s->failed_pc=0x0c03f736u; return 0; }
tmp=read(ram,r[8],4);
r[0]=tmp;
goto P_0c03f738;
P_0c03f738: /* original 0ad5, guest PC 0x0c03f738 */
if(!s->budget--) { s->failed_pc=0x0c03f738u; return 0; }
write(ram,r[10]+r[0],r[13],2);
goto P_0c03f73a;
P_0c03f73a: /* original 63f2, guest PC 0x0c03f73a */
if(!s->budget--) { s->failed_pc=0x0c03f73au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c03f73c;
P_0c03f73c: /* original 7310, guest PC 0x0c03f73c */
if(!s->budget--) { s->failed_pc=0x0c03f73cu; return 0; }
r[3]+=0x00000010u;
goto P_0c03f73e;
P_0c03f73e: /* original 2f32, guest PC 0x0c03f73e */
if(!s->budget--) { s->failed_pc=0x0c03f73eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c03f740;
P_0c03f740: /* original 52f1, guest PC 0x0c03f740 */
if(!s->budget--) { s->failed_pc=0x0c03f740u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c03f742;
P_0c03f742: /* original 7201, guest PC 0x0c03f742 */
if(!s->budget--) { s->failed_pc=0x0c03f742u; return 0; }
r[2]+=0x00000001u;
goto P_0c03f744;
P_0c03f744: /* original 1f21, guest PC 0x0c03f744 */
if(!s->budget--) { s->failed_pc=0x0c03f744u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c03f746;
P_0c03f746: /* original 60f2, guest PC 0x0c03f746 */
if(!s->budget--) { s->failed_pc=0x0c03f746u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c03f748;
P_0c03f748: /* original 5001, guest PC 0x0c03f748 */
if(!s->budget--) { s->failed_pc=0x0c03f748u; return 0; }
r[0]=read(ram,r[0]+4,4);
goto P_0c03f74a;
P_0c03f74a: /* original 88ff, guest PC 0x0c03f74a */
if(!s->budget--) { s->failed_pc=0x0c03f74au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03f74c;
P_0c03f74c: /* original 8bb8, guest PC 0x0c03f74c */
if(!s->budget--) { s->failed_pc=0x0c03f74cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f6c0; }
goto P_0c03f74e;
P_0c03f74e: /* original 50f3, guest PC 0x0c03f74e */
if(!s->budget--) { s->failed_pc=0x0c03f74eu; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c03f750;
P_0c03f750: /* original 7f10, guest PC 0x0c03f750 */
if(!s->budget--) { s->failed_pc=0x0c03f750u; return 0; }
r[15]+=0x00000010u;
goto P_0c03f752;
P_0c03f752: /* original 4f16, guest PC 0x0c03f752 */
if(!s->budget--) { s->failed_pc=0x0c03f752u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f754;
P_0c03f754: /* original 4f26, guest PC 0x0c03f754 */
if(!s->budget--) { s->failed_pc=0x0c03f754u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f756;
P_0c03f756: /* original 68f6, guest PC 0x0c03f756 */
if(!s->budget--) { s->failed_pc=0x0c03f756u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03f758;
P_0c03f758: /* original 69f6, guest PC 0x0c03f758 */
if(!s->budget--) { s->failed_pc=0x0c03f758u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03f75a;
P_0c03f75a: /* original 6af6, guest PC 0x0c03f75a */
if(!s->budget--) { s->failed_pc=0x0c03f75au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03f75c;
P_0c03f75c: /* original 6bf6, guest PC 0x0c03f75c */
if(!s->budget--) { s->failed_pc=0x0c03f75cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03f75e;
P_0c03f75e: /* original 6cf6, guest PC 0x0c03f75e */
if(!s->budget--) { s->failed_pc=0x0c03f75eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03f760;
P_0c03f760: /* original 6df6, guest PC 0x0c03f760 */
if(!s->budget--) { s->failed_pc=0x0c03f760u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03f762;
P_0c03f762: /* original 000b, guest PC 0x0c03f762 */
if(!s->budget--) { s->failed_pc=0x0c03f762u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03f764: /* original 6ef6, guest PC 0x0c03f764 */
if(!s->budget--) { s->failed_pc=0x0c03f764u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03f766u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f766u; return 0; } return 1;
P_0c03f830: /* original 2fe6, guest PC 0x0c03f830 */
if(!s->budget--) { s->failed_pc=0x0c03f830u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f832;
P_0c03f832: /* original 2fd6, guest PC 0x0c03f832 */
if(!s->budget--) { s->failed_pc=0x0c03f832u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f834;
P_0c03f834: /* original 6d43, guest PC 0x0c03f834 */
if(!s->budget--) { s->failed_pc=0x0c03f834u; return 0; }
r[13]=r[4];
goto P_0c03f836;
P_0c03f836: /* original 2fc6, guest PC 0x0c03f836 */
if(!s->budget--) { s->failed_pc=0x0c03f836u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f838;
P_0c03f838: /* original 2fb6, guest PC 0x0c03f838 */
if(!s->budget--) { s->failed_pc=0x0c03f838u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f83a;
P_0c03f83a: /* original 2fa6, guest PC 0x0c03f83a */
if(!s->budget--) { s->failed_pc=0x0c03f83au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f83c;
P_0c03f83c: /* original 2f96, guest PC 0x0c03f83c */
if(!s->budget--) { s->failed_pc=0x0c03f83cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f83e;
P_0c03f83e: /* original 2f86, guest PC 0x0c03f83e */
if(!s->budget--) { s->failed_pc=0x0c03f83eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f840;
P_0c03f840: /* original fffb, guest PC 0x0c03f840 */
if(!s->budget--) { s->failed_pc=0x0c03f840u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c03f842;
P_0c03f842: /* original ffeb, guest PC 0x0c03f842 */
if(!s->budget--) { s->failed_pc=0x0c03f842u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c03f844;
P_0c03f844: /* original ffdb, guest PC 0x0c03f844 */
if(!s->budget--) { s->failed_pc=0x0c03f844u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c03f846;
P_0c03f846: /* original d34a, guest PC 0x0c03f846 */
if(!s->budget--) { s->failed_pc=0x0c03f846u; return 0; }
r[3]=read(ram,0x0c03f970u,4);
goto P_0c03f848;
P_0c03f848: /* original 69d2, guest PC 0x0c03f848 */
if(!s->budget--) { s->failed_pc=0x0c03f848u; return 0; }
tmp=read(ram,r[13],4);
r[9]=tmp;
goto P_0c03f84a;
P_0c03f84a: /* original 4f22, guest PC 0x0c03f84a */
if(!s->budget--) { s->failed_pc=0x0c03f84au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f84c;
P_0c03f84c: /* original 6032, guest PC 0x0c03f84c */
if(!s->budget--) { s->failed_pc=0x0c03f84cu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c03f84e;
P_0c03f84e: /* original 4900, guest PC 0x0c03f84e */
if(!s->budget--) { s->failed_pc=0x0c03f84eu; return 0; }
r[17]=(r[17]&~1u)|((r[9]>>31)!=0);
r[9]<<=1;
goto P_0c03f850;
P_0c03f850: /* original 099d, guest PC 0x0c03f850 */
if(!s->budget--) { s->failed_pc=0x0c03f850u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,r[9]+r[0],2);
goto P_0c03f852;
P_0c03f852: /* original 7fc4, guest PC 0x0c03f852 */
if(!s->budget--) { s->failed_pc=0x0c03f852u; return 0; }
r[15]+=0xffffffc4u;
goto P_0c03f854;
P_0c03f854: /* original 6093, guest PC 0x0c03f854 */
if(!s->budget--) { s->failed_pc=0x0c03f854u; return 0; }
r[0]=r[9];
goto P_0c03f856;
P_0c03f856: /* original 0009, guest PC 0x0c03f856 */
if(!s->budget--) { s->failed_pc=0x0c03f856u; return 0; }
goto P_0c03f858;
P_0c03f858: /* original 88ff, guest PC 0x0c03f858 */
if(!s->budget--) { s->failed_pc=0x0c03f858u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03f85a;
P_0c03f85a: /* original 8b01, guest PC 0x0c03f85a */
if(!s->budget--) { s->failed_pc=0x0c03f85au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f860; }
goto P_0c03f85c;
P_0c03f85c: /* original a149, guest PC 0x0c03f85c */
if(!s->budget--) { s->failed_pc=0x0c03f85cu; return 0; }
goto P_0c03faf2;
P_0c03f85e: /* original 0009, guest PC 0x0c03f85e */
if(!s->budget--) { s->failed_pc=0x0c03f85eu; return 0; }
goto P_0c03f860;
P_0c03f860: /* original e030, guest PC 0x0c03f860 */
if(!s->budget--) { s->failed_pc=0x0c03f860u; return 0; }
r[0]=0x00000030u;
goto P_0c03f862;
P_0c03f862: /* original d244, guest PC 0x0c03f862 */
if(!s->budget--) { s->failed_pc=0x0c03f862u; return 0; }
r[2]=read(ram,0x0c03f974u,4);
goto P_0c03f864;
P_0c03f864: /* original fed6, guest PC 0x0c03f864 */
if(!s->budget--) { s->failed_pc=0x0c03f864u; return 0; }
vf3_matrix_load(s,ram,14,r[13]+r[0]);
goto P_0c03f866;
P_0c03f866: /* original 6e93, guest PC 0x0c03f866 */
if(!s->budget--) { s->failed_pc=0x0c03f866u; return 0; }
r[14]=r[9];
goto P_0c03f868;
P_0c03f868: /* original ff9d, guest PC 0x0c03f868 */
if(!s->budget--) { s->failed_pc=0x0c03f868u; return 0; }
fr[15]=0x3f800000u;
goto P_0c03f86a;
P_0c03f86a: /* original 4e08, guest PC 0x0c03f86a */
if(!s->budget--) { s->failed_pc=0x0c03f86au; return 0; }
r[14]<<=2;
goto P_0c03f86c;
P_0c03f86c: /* original 6322, guest PC 0x0c03f86c */
if(!s->budget--) { s->failed_pc=0x0c03f86cu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f86e;
P_0c03f86e: /* original 4e08, guest PC 0x0c03f86e */
if(!s->budget--) { s->failed_pc=0x0c03f86eu; return 0; }
r[14]<<=2;
goto P_0c03f870;
P_0c03f870: /* original 4e00, guest PC 0x0c03f870 */
if(!s->budget--) { s->failed_pc=0x0c03f870u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c03f872;
P_0c03f872: /* original ffe5, guest PC 0x0c03f872 */
if(!s->budget--) { s->failed_pc=0x0c03f872u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[14]))!=0);
goto P_0c03f874;
P_0c03f874: /* original 3e3c, guest PC 0x0c03f874 */
if(!s->budget--) { s->failed_pc=0x0c03f874u; return 0; }
r[14]+=r[3];
goto P_0c03f876;
P_0c03f876: /* original e800, guest PC 0x0c03f876 */
if(!s->budget--) { s->failed_pc=0x0c03f876u; return 0; }
r[8]=0x00000000u;
goto P_0c03f878;
P_0c03f878: /* original 8d03, guest PC 0x0c03f878 */
if(!s->budget--) { s->failed_pc=0x0c03f878u; return 0; }
cond=r[17]&1u;
r[10]=r[8];
if(cond) { goto P_0c03f882; }
goto P_0c03f87c;
P_0c03f87a: /* original 6a83, guest PC 0x0c03f87a */
if(!s->budget--) { s->failed_pc=0x0c03f87au; return 0; }
r[10]=r[8];
goto P_0c03f87c;
P_0c03f87c: /* original 51e5, guest PC 0x0c03f87c */
if(!s->budget--) { s->failed_pc=0x0c03f87cu; return 0; }
r[1]=read(ram,r[14]+20,4);
goto P_0c03f87e;
P_0c03f87e: /* original 2118, guest PC 0x0c03f87e */
if(!s->budget--) { s->failed_pc=0x0c03f87eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c03f880;
P_0c03f880: /* original 8900, guest PC 0x0c03f880 */
if(!s->budget--) { s->failed_pc=0x0c03f880u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03f884; }
goto P_0c03f882;
P_0c03f882: /* original ea01, guest PC 0x0c03f882 */
if(!s->budget--) { s->failed_pc=0x0c03f882u; return 0; }
r[10]=0x00000001u;
goto P_0c03f884;
P_0c03f884: /* original c73c, guest PC 0x0c03f884 */
if(!s->budget--) { s->failed_pc=0x0c03f884u; return 0; }
r[0]=code_base|0x0003f978u;
goto P_0c03f886;
P_0c03f886: /* original f408, guest PC 0x0c03f886 */
if(!s->budget--) { s->failed_pc=0x0c03f886u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c03f888;
P_0c03f888: /* original e010, guest PC 0x0c03f888 */
if(!s->budget--) { s->failed_pc=0x0c03f888u; return 0; }
r[0]=0x00000010u;
goto P_0c03f88a;
P_0c03f88a: /* original f3d6, guest PC 0x0c03f88a */
if(!s->budget--) { s->failed_pc=0x0c03f88au; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03f88c;
P_0c03f88c: /* original e018, guest PC 0x0c03f88c */
if(!s->budget--) { s->failed_pc=0x0c03f88cu; return 0; }
r[0]=0x00000018u;
goto P_0c03f88e;
P_0c03f88e: /* original f2e6, guest PC 0x0c03f88e */
if(!s->budget--) { s->failed_pc=0x0c03f88eu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c03f890;
P_0c03f890: /* original e008, guest PC 0x0c03f890 */
if(!s->budget--) { s->failed_pc=0x0c03f890u; return 0; }
r[0]=0x00000008u;
goto P_0c03f892;
P_0c03f892: /* original f232, guest PC 0x0c03f892 */
if(!s->budget--) { s->failed_pc=0x0c03f892u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03f894;
P_0c03f894: /* original f242, guest PC 0x0c03f894 */
if(!s->budget--) { s->failed_pc=0x0c03f894u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c03f896;
P_0c03f896: /* original ff27, guest PC 0x0c03f896 */
if(!s->budget--) { s->failed_pc=0x0c03f896u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c03f898;
P_0c03f898: /* original e014, guest PC 0x0c03f898 */
if(!s->budget--) { s->failed_pc=0x0c03f898u; return 0; }
r[0]=0x00000014u;
goto P_0c03f89a;
P_0c03f89a: /* original f3d6, guest PC 0x0c03f89a */
if(!s->budget--) { s->failed_pc=0x0c03f89au; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03f89c;
P_0c03f89c: /* original e01c, guest PC 0x0c03f89c */
if(!s->budget--) { s->failed_pc=0x0c03f89cu; return 0; }
r[0]=0x0000001cu;
goto P_0c03f89e;
P_0c03f89e: /* original f2e6, guest PC 0x0c03f89e */
if(!s->budget--) { s->failed_pc=0x0c03f89eu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c03f8a0;
P_0c03f8a0: /* original e004, guest PC 0x0c03f8a0 */
if(!s->budget--) { s->failed_pc=0x0c03f8a0u; return 0; }
r[0]=0x00000004u;
goto P_0c03f8a2;
P_0c03f8a2: /* original f232, guest PC 0x0c03f8a2 */
if(!s->budget--) { s->failed_pc=0x0c03f8a2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03f8a4;
P_0c03f8a4: /* original f242, guest PC 0x0c03f8a4 */
if(!s->budget--) { s->failed_pc=0x0c03f8a4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c03f8a6;
P_0c03f8a6: /* original ff27, guest PC 0x0c03f8a6 */
if(!s->budget--) { s->failed_pc=0x0c03f8a6u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c03f8a8;
P_0c03f8a8: /* original e00c, guest PC 0x0c03f8a8 */
if(!s->budget--) { s->failed_pc=0x0c03f8a8u; return 0; }
r[0]=0x0000000cu;
goto P_0c03f8aa;
P_0c03f8aa: /* original f3d6, guest PC 0x0c03f8aa */
if(!s->budget--) { s->failed_pc=0x0c03f8aau; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03f8ac;
P_0c03f8ac: /* original fdfc, guest PC 0x0c03f8ac */
if(!s->budget--) { s->failed_pc=0x0c03f8acu; return 0; }
vf3_matrix_move(s,13,15);
goto P_0c03f8ae;
P_0c03f8ae: /* original fd33, guest PC 0x0c03f8ae */
if(!s->budget--) { s->failed_pc=0x0c03f8aeu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'/');
goto P_0c03f8b0;
P_0c03f8b0: /* original d332, guest PC 0x0c03f8b0 */
if(!s->budget--) { s->failed_pc=0x0c03f8b0u; return 0; }
r[3]=read(ram,0x0c03f97cu,4);
goto P_0c03f8b2;
P_0c03f8b2: /* original 430b, guest PC 0x0c03f8b2 */
if(!s->budget--) { s->failed_pc=0x0c03f8b2u; return 0; }
target=r[3];
r[16]=code_base|0x0c03f8b6u;
r[4]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f8b6u) { target=s->pc; goto dispatch; }
goto P_0c03f8b6;
P_0c03f8b4: /* original 54da, guest PC 0x0c03f8b4 */
if(!s->budget--) { s->failed_pc=0x0c03f8b4u; return 0; }
r[4]=read(ram,r[13]+40,4);
goto P_0c03f8b6;
P_0c03f8b6: /* original ff0a, guest PC 0x0c03f8b6 */
if(!s->budget--) { s->failed_pc=0x0c03f8b6u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c03f8b8;
P_0c03f8b8: /* original d331, guest PC 0x0c03f8b8 */
if(!s->budget--) { s->failed_pc=0x0c03f8b8u; return 0; }
r[3]=read(ram,0x0c03f980u,4);
goto P_0c03f8ba;
P_0c03f8ba: /* original 430b, guest PC 0x0c03f8ba */
if(!s->budget--) { s->failed_pc=0x0c03f8bau; return 0; }
target=r[3];
r[16]=code_base|0x0c03f8beu;
r[4]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f8beu) { target=s->pc; goto dispatch; }
goto P_0c03f8be;
P_0c03f8bc: /* original 54da, guest PC 0x0c03f8bc */
if(!s->budget--) { s->failed_pc=0x0c03f8bcu; return 0; }
r[4]=read(ram,r[13]+40,4);
goto P_0c03f8be;
P_0c03f8be: /* original e004, guest PC 0x0c03f8be */
if(!s->budget--) { s->failed_pc=0x0c03f8beu; return 0; }
r[0]=0x00000004u;
goto P_0c03f8c0;
P_0c03f8c0: /* original 6cf3, guest PC 0x0c03f8c0 */
if(!s->budget--) { s->failed_pc=0x0c03f8c0u; return 0; }
r[12]=r[15];
goto P_0c03f8c2;
P_0c03f8c2: /* original f5f6, guest PC 0x0c03f8c2 */
if(!s->budget--) { s->failed_pc=0x0c03f8c2u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c03f8c4;
P_0c03f8c4: /* original 6bf3, guest PC 0x0c03f8c4 */
if(!s->budget--) { s->failed_pc=0x0c03f8c4u; return 0; }
r[11]=r[15];
goto P_0c03f8c6;
P_0c03f8c6: /* original e008, guest PC 0x0c03f8c6 */
if(!s->budget--) { s->failed_pc=0x0c03f8c6u; return 0; }
r[0]=0x00000008u;
goto P_0c03f8c8;
P_0c03f8c8: /* original f6f8, guest PC 0x0c03f8c8 */
if(!s->budget--) { s->failed_pc=0x0c03f8c8u; return 0; }
vf3_matrix_load(s,ram,6,r[15]);
goto P_0c03f8ca;
P_0c03f8ca: /* original f4f6, guest PC 0x0c03f8ca */
if(!s->budget--) { s->failed_pc=0x0c03f8cau; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c03f8cc;
P_0c03f8cc: /* original 7b2c, guest PC 0x0c03f8cc */
if(!s->budget--) { s->failed_pc=0x0c03f8ccu; return 0; }
r[11]+=0x0000002cu;
goto P_0c03f8ce;
P_0c03f8ce: /* original 7c1c, guest PC 0x0c03f8ce */
if(!s->budget--) { s->failed_pc=0x0c03f8ceu; return 0; }
r[12]+=0x0000001cu;
goto P_0c03f8d0;
P_0c03f8d0: /* original 65b3, guest PC 0x0c03f8d0 */
if(!s->budget--) { s->failed_pc=0x0c03f8d0u; return 0; }
r[5]=r[11];
goto P_0c03f8d2;
P_0c03f8d2: /* original 66c3, guest PC 0x0c03f8d2 */
if(!s->budget--) { s->failed_pc=0x0c03f8d2u; return 0; }
r[6]=r[12];
goto P_0c03f8d4;
P_0c03f8d4: /* original f70c, guest PC 0x0c03f8d4 */
if(!s->budget--) { s->failed_pc=0x0c03f8d4u; return 0; }
vf3_matrix_move(s,7,0);
goto P_0c03f8d6;
P_0c03f8d6: /* original b11b, guest PC 0x0c03f8d6 */
if(!s->budget--) { s->failed_pc=0x0c03f8d6u; return 0; }
target=code_base|0x0c03fb10u; r[16]=code_base|0x0c03f8dau;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f8dau) { target=s->pc; goto dispatch; }
goto P_0c03f8da;
P_0c03f8d8: /* original 64d3, guest PC 0x0c03f8d8 */
if(!s->budget--) { s->failed_pc=0x0c03f8d8u; return 0; }
r[4]=r[13];
goto P_0c03f8da;
P_0c03f8da: /* original d22c, guest PC 0x0c03f8da */
if(!s->budget--) { s->failed_pc=0x0c03f8dau; return 0; }
r[2]=read(ram,0x0c03f98cu,4);
goto P_0c03f8dc;
P_0c03f8dc: /* original e004, guest PC 0x0c03f8dc */
if(!s->budget--) { s->failed_pc=0x0c03f8dcu; return 0; }
r[0]=0x00000004u;
goto P_0c03f8de;
P_0c03f8de: /* original d32a, guest PC 0x0c03f8de */
if(!s->budget--) { s->failed_pc=0x0c03f8deu; return 0; }
r[3]=read(ram,0x0c03f988u,4);
goto P_0c03f8e0;
P_0c03f8e0: /* original 6603, guest PC 0x0c03f8e0 */
if(!s->budget--) { s->failed_pc=0x0c03f8e0u; return 0; }
r[6]=r[0];
goto P_0c03f8e2;
P_0c03f8e2: /* original d428, guest PC 0x0c03f8e2 */
if(!s->budget--) { s->failed_pc=0x0c03f8e2u; return 0; }
r[4]=read(ram,0x0c03f984u,4);
goto P_0c03f8e4;
P_0c03f8e4: /* original 6583, guest PC 0x0c03f8e4 */
if(!s->budget--) { s->failed_pc=0x0c03f8e4u; return 0; }
r[5]=r[8];
goto P_0c03f8e6;
P_0c03f8e6: /* original f228, guest PC 0x0c03f8e6 */
if(!s->budget--) { s->failed_pc=0x0c03f8e6u; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
goto P_0c03f8e8;
P_0c03f8e8: /* original f546, guest PC 0x0c03f8e8 */
if(!s->budget--) { s->failed_pc=0x0c03f8e8u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c03f8ea;
P_0c03f8ea: /* original f338, guest PC 0x0c03f8ea */
if(!s->budget--) { s->failed_pc=0x0c03f8eau; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c03f8ec;
P_0c03f8ec: /* original f448, guest PC 0x0c03f8ec */
if(!s->budget--) { s->failed_pc=0x0c03f8ecu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c03f8ee;
P_0c03f8ee: /* original f522, guest PC 0x0c03f8ee */
if(!s->budget--) { s->failed_pc=0x0c03f8eeu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'*');
goto P_0c03f8f0;
P_0c03f8f0: /* original 6483, guest PC 0x0c03f8f0 */
if(!s->budget--) { s->failed_pc=0x0c03f8f0u; return 0; }
r[4]=r[8];
goto P_0c03f8f2;
P_0c03f8f2: /* original f432, guest PC 0x0c03f8f2 */
if(!s->budget--) { s->failed_pc=0x0c03f8f2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c03f8f4;
P_0c03f8f4: /* original 6043, guest PC 0x0c03f8f4 */
if(!s->budget--) { s->failed_pc=0x0c03f8f4u; return 0; }
r[0]=r[4];
goto P_0c03f8f6;
P_0c03f8f6: /* original 0009, guest PC 0x0c03f8f6 */
if(!s->budget--) { s->failed_pc=0x0c03f8f6u; return 0; }
goto P_0c03f8f8;
P_0c03f8f8: /* original f3b6, guest PC 0x0c03f8f8 */
if(!s->budget--) { s->failed_pc=0x0c03f8f8u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c03f8fa;
P_0c03f8fa: /* original 7501, guest PC 0x0c03f8fa */
if(!s->budget--) { s->failed_pc=0x0c03f8fau; return 0; }
r[5]+=0x00000001u;
goto P_0c03f8fc;
P_0c03f8fc: /* original 3563, guest PC 0x0c03f8fc */
if(!s->budget--) { s->failed_pc=0x0c03f8fcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c03f8fe;
P_0c03f8fe: /* original f342, guest PC 0x0c03f8fe */
if(!s->budget--) { s->failed_pc=0x0c03f8feu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c03f900;
P_0c03f900: /* original fb37, guest PC 0x0c03f900 */
if(!s->budget--) { s->failed_pc=0x0c03f900u; return 0; }
vf3_matrix_store(s,ram,3,r[11]+r[0]);
goto P_0c03f902;
P_0c03f902: /* original f2c6, guest PC 0x0c03f902 */
if(!s->budget--) { s->failed_pc=0x0c03f902u; return 0; }
vf3_matrix_load(s,ram,2,r[12]+r[0]);
goto P_0c03f904;
P_0c03f904: /* original f252, guest PC 0x0c03f904 */
if(!s->budget--) { s->failed_pc=0x0c03f904u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'*');
goto P_0c03f906;
P_0c03f906: /* original fc27, guest PC 0x0c03f906 */
if(!s->budget--) { s->failed_pc=0x0c03f906u; return 0; }
vf3_matrix_store(s,ram,2,r[12]+r[0]);
goto P_0c03f908;
P_0c03f908: /* original 8ff4, guest PC 0x0c03f908 */
if(!s->budget--) { s->failed_pc=0x0c03f908u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c03f8f4; }
goto P_0c03f90c;
P_0c03f90a: /* original 7404, guest PC 0x0c03f90a */
if(!s->budget--) { s->failed_pc=0x0c03f90au; return 0; }
r[4]+=0x00000004u;
goto P_0c03f90c;
P_0c03f90c: /* original 62e2, guest PC 0x0c03f90c */
if(!s->budget--) { s->failed_pc=0x0c03f90cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f90e;
P_0c03f90e: /* original d320, guest PC 0x0c03f90e */
if(!s->budget--) { s->failed_pc=0x0c03f90eu; return 0; }
r[3]=read(ram,0x0c03f990u,4);
goto P_0c03f910;
P_0c03f910: /* original 2239, guest PC 0x0c03f910 */
if(!s->budget--) { s->failed_pc=0x0c03f910u; return 0; }
r[2]&=r[3];
goto P_0c03f912;
P_0c03f912: /* original 2e22, guest PC 0x0c03f912 */
if(!s->budget--) { s->failed_pc=0x0c03f912u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c03f914;
P_0c03f914: /* original 51e2, guest PC 0x0c03f914 */
if(!s->budget--) { s->failed_pc=0x0c03f914u; return 0; }
r[1]=read(ram,r[14]+8,4);
goto P_0c03f916;
P_0c03f916: /* original d21f, guest PC 0x0c03f916 */
if(!s->budget--) { s->failed_pc=0x0c03f916u; return 0; }
r[2]=read(ram,0x0c03f994u,4);
goto P_0c03f918;
P_0c03f918: /* original 2129, guest PC 0x0c03f918 */
if(!s->budget--) { s->failed_pc=0x0c03f918u; return 0; }
r[1]&=r[2];
goto P_0c03f91a;
P_0c03f91a: /* original 1e12, guest PC 0x0c03f91a */
if(!s->budget--) { s->failed_pc=0x0c03f91au; return 0; }
write(ram,r[14]+8,r[1],4);
goto P_0c03f91c;
P_0c03f91c: /* original 50db, guest PC 0x0c03f91c */
if(!s->budget--) { s->failed_pc=0x0c03f91cu; return 0; }
r[0]=read(ram,r[13]+44,4);
goto P_0c03f91e;
P_0c03f91e: /* original 9124, guest PC 0x0c03f91e */
if(!s->budget--) { s->failed_pc=0x0c03f91eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03f96au,2);
goto P_0c03f920;
P_0c03f920: /* original 2018, guest PC 0x0c03f920 */
if(!s->budget--) { s->failed_pc=0x0c03f920u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c03f922;
P_0c03f922: /* original 8b03, guest PC 0x0c03f922 */
if(!s->budget--) { s->failed_pc=0x0c03f922u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f92c; }
goto P_0c03f924;
P_0c03f924: /* original 50e2, guest PC 0x0c03f924 */
if(!s->budget--) { s->failed_pc=0x0c03f924u; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c03f926;
P_0c03f926: /* original d31c, guest PC 0x0c03f926 */
if(!s->budget--) { s->failed_pc=0x0c03f926u; return 0; }
r[3]=read(ram,0x0c03f998u,4);
goto P_0c03f928;
P_0c03f928: /* original 203b, guest PC 0x0c03f928 */
if(!s->budget--) { s->failed_pc=0x0c03f928u; return 0; }
r[0]|=r[3];
goto P_0c03f92a;
P_0c03f92a: /* original 1e02, guest PC 0x0c03f92a */
if(!s->budget--) { s->failed_pc=0x0c03f92au; return 0; }
write(ram,r[14]+8,r[0],4);
goto P_0c03f92c;
P_0c03f92c: /* original 52db, guest PC 0x0c03f92c */
if(!s->budget--) { s->failed_pc=0x0c03f92cu; return 0; }
r[2]=read(ram,r[13]+44,4);
goto P_0c03f92e;
P_0c03f92e: /* original 931e, guest PC 0x0c03f92e */
if(!s->budget--) { s->failed_pc=0x0c03f92eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03f96eu,2);
goto P_0c03f930;
P_0c03f930: /* original 951c, guest PC 0x0c03f930 */
if(!s->budget--) { s->failed_pc=0x0c03f930u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03f96cu,2);
goto P_0c03f932;
P_0c03f932: /* original 2238, guest PC 0x0c03f932 */
if(!s->budget--) { s->failed_pc=0x0c03f932u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c03f934;
P_0c03f934: /* original 8902, guest PC 0x0c03f934 */
if(!s->budget--) { s->failed_pc=0x0c03f934u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03f93c; }
goto P_0c03f936;
P_0c03f936: /* original 50e2, guest PC 0x0c03f936 */
if(!s->budget--) { s->failed_pc=0x0c03f936u; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c03f938;
P_0c03f938: /* original 205b, guest PC 0x0c03f938 */
if(!s->budget--) { s->failed_pc=0x0c03f938u; return 0; }
r[0]|=r[5];
goto P_0c03f93a;
P_0c03f93a: /* original 1e02, guest PC 0x0c03f93a */
if(!s->budget--) { s->failed_pc=0x0c03f93au; return 0; }
write(ram,r[14]+8,r[0],4);
goto P_0c03f93c;
P_0c03f93c: /* original 50db, guest PC 0x0c03f93c */
if(!s->budget--) { s->failed_pc=0x0c03f93cu; return 0; }
r[0]=read(ram,r[13]+44,4);
goto P_0c03f93e;
P_0c03f93e: /* original e3f8, guest PC 0x0c03f93e */
if(!s->budget--) { s->failed_pc=0x0c03f93eu; return 0; }
r[3]=0xfffffff8u;
goto P_0c03f940;
P_0c03f940: /* original e407, guest PC 0x0c03f940 */
if(!s->budget--) { s->failed_pc=0x0c03f940u; return 0; }
r[4]=0x00000007u;
goto P_0c03f942;
P_0c03f942: /* original 403c, guest PC 0x0c03f942 */
if(!s->budget--) { s->failed_pc=0x0c03f942u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c03f944;
P_0c03f944: /* original 2409, guest PC 0x0c03f944 */
if(!s->budget--) { s->failed_pc=0x0c03f944u; return 0; }
r[4]&=r[0];
goto P_0c03f946;
P_0c03f946: /* original 2448, guest PC 0x0c03f946 */
if(!s->budget--) { s->failed_pc=0x0c03f946u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03f948;
P_0c03f948: /* original 8b00, guest PC 0x0c03f948 */
if(!s->budget--) { s->failed_pc=0x0c03f948u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f94c; }
goto P_0c03f94a;
P_0c03f94a: /* original 6463, guest PC 0x0c03f94a */
if(!s->budget--) { s->failed_pc=0x0c03f94au; return 0; }
r[4]=r[6];
goto P_0c03f94c;
P_0c03f94c: /* original 52e1, guest PC 0x0c03f94c */
if(!s->budget--) { s->failed_pc=0x0c03f94cu; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c03f94e;
P_0c03f94e: /* original e11d, guest PC 0x0c03f94e */
if(!s->budget--) { s->failed_pc=0x0c03f94eu; return 0; }
r[1]=0x0000001du;
goto P_0c03f950;
P_0c03f950: /* original d312, guest PC 0x0c03f950 */
if(!s->budget--) { s->failed_pc=0x0c03f950u; return 0; }
r[3]=read(ram,0x0c03f99cu,4);
goto P_0c03f952;
P_0c03f952: /* original 441c, guest PC 0x0c03f952 */
if(!s->budget--) { s->failed_pc=0x0c03f952u; return 0; }
r[4]=(r[1]&0x80000000u)?((r[1]&31u)?(uint32_t)((int32_t)r[4]>>((-r[1])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[1]&31u);
goto P_0c03f954;
P_0c03f954: /* original 2aa8, guest PC 0x0c03f954 */
if(!s->budget--) { s->failed_pc=0x0c03f954u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c03f956;
P_0c03f956: /* original 2239, guest PC 0x0c03f956 */
if(!s->budget--) { s->failed_pc=0x0c03f956u; return 0; }
r[2]&=r[3];
goto P_0c03f958;
P_0c03f958: /* original 224b, guest PC 0x0c03f958 */
if(!s->budget--) { s->failed_pc=0x0c03f958u; return 0; }
r[2]|=r[4];
goto P_0c03f95a;
P_0c03f95a: /* original 8d31, guest PC 0x0c03f95a */
if(!s->budget--) { s->failed_pc=0x0c03f95au; return 0; }
cond=r[17]&1u;
write(ram,r[14]+4,r[2],4);
if(cond) { goto P_0c03f9c0; }
goto P_0c03f95e;
P_0c03f95c: /* original 1e21, guest PC 0x0c03f95c */
if(!s->budget--) { s->failed_pc=0x0c03f95cu; return 0; }
write(ram,r[14]+4,r[2],4);
goto P_0c03f95e;
P_0c03f95e: /* original 60e2, guest PC 0x0c03f95e */
if(!s->budget--) { s->failed_pc=0x0c03f95eu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c03f960;
P_0c03f960: /* original d20f, guest PC 0x0c03f960 */
if(!s->budget--) { s->failed_pc=0x0c03f960u; return 0; }
r[2]=read(ram,0x0c03f9a0u,4);
goto P_0c03f962;
P_0c03f962: /* original 202b, guest PC 0x0c03f962 */
if(!s->budget--) { s->failed_pc=0x0c03f962u; return 0; }
r[0]|=r[2];
goto P_0c03f964;
P_0c03f964: /* original 2e02, guest PC 0x0c03f964 */
if(!s->budget--) { s->failed_pc=0x0c03f964u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c03f966;
P_0c03f966: /* original a023, guest PC 0x0c03f966 */
if(!s->budget--) { s->failed_pc=0x0c03f966u; return 0; }
goto P_0c03f9b0;
P_0c03f968: /* original 0009, guest PC 0x0c03f968 */
if(!s->budget--) { s->failed_pc=0x0c03f968u; return 0; }
if(!vf3_matrix_family(0x0c03f96au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f96au; return 0; } return 1;
P_0c03f9b0: /* original 50e2, guest PC 0x0c03f9b0 */
if(!s->budget--) { s->failed_pc=0x0c03f9b0u; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c03f9b2;
P_0c03f9b2: /* original d395, guest PC 0x0c03f9b2 */
if(!s->budget--) { s->failed_pc=0x0c03f9b2u; return 0; }
r[3]=read(ram,0x0c03fc08u,4);
goto P_0c03f9b4;
P_0c03f9b4: /* original 203b, guest PC 0x0c03f9b4 */
if(!s->budget--) { s->failed_pc=0x0c03f9b4u; return 0; }
r[0]|=r[3];
goto P_0c03f9b6;
P_0c03f9b6: /* original a008, guest PC 0x0c03f9b6 */
if(!s->budget--) { s->failed_pc=0x0c03f9b6u; return 0; }
write(ram,r[14]+8,r[0],4);
goto P_0c03f9ca;
P_0c03f9b8: /* original 1e02, guest PC 0x0c03f9b8 */
if(!s->budget--) { s->failed_pc=0x0c03f9b8u; return 0; }
write(ram,r[14]+8,r[0],4);
if(!vf3_matrix_family(0x0c03f9bau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f9bau; return 0; } return 1;
P_0c03f9c0: /* original 50e2, guest PC 0x0c03f9c0 */
if(!s->budget--) { s->failed_pc=0x0c03f9c0u; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c03f9c2;
P_0c03f9c2: /* original d292, guest PC 0x0c03f9c2 */
if(!s->budget--) { s->failed_pc=0x0c03f9c2u; return 0; }
r[2]=read(ram,0x0c03fc0cu,4);
goto P_0c03f9c4;
P_0c03f9c4: /* original 202b, guest PC 0x0c03f9c4 */
if(!s->budget--) { s->failed_pc=0x0c03f9c4u; return 0; }
r[0]|=r[2];
goto P_0c03f9c6;
P_0c03f9c6: /* original 1e02, guest PC 0x0c03f9c6 */
if(!s->budget--) { s->failed_pc=0x0c03f9c6u; return 0; }
write(ram,r[14]+8,r[0],4);
goto P_0c03f9c8;
P_0c03f9c8: /* original fefc, guest PC 0x0c03f9c8 */
if(!s->budget--) { s->failed_pc=0x0c03f9c8u; return 0; }
vf3_matrix_move(s,14,15);
goto P_0c03f9ca;
P_0c03f9ca: /* original 53db, guest PC 0x0c03f9ca */
if(!s->budget--) { s->failed_pc=0x0c03f9cau; return 0; }
r[3]=read(ram,r[13]+44,4);
goto P_0c03f9cc;
P_0c03f9cc: /* original 2538, guest PC 0x0c03f9cc */
if(!s->budget--) { s->failed_pc=0x0c03f9ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c03f9ce;
P_0c03f9ce: /* original 8d07, guest PC 0x0c03f9ce */
if(!s->budget--) { s->failed_pc=0x0c03f9ceu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,14);
if(cond) { goto P_0c03f9e0; }
goto P_0c03f9d2;
P_0c03f9d0: /* original f4ec, guest PC 0x0c03f9d0 */
if(!s->budget--) { s->failed_pc=0x0c03f9d0u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c03f9d2;
P_0c03f9d2: /* original d88f, guest PC 0x0c03f9d2 */
if(!s->budget--) { s->failed_pc=0x0c03f9d2u; return 0; }
r[8]=read(ram,0x0c03fc10u,4);
goto P_0c03f9d4;
P_0c03f9d4: /* original e008, guest PC 0x0c03f9d4 */
if(!s->budget--) { s->failed_pc=0x0c03f9d4u; return 0; }
r[0]=0x00000008u;
goto P_0c03f9d6;
P_0c03f9d6: /* original f786, guest PC 0x0c03f9d6 */
if(!s->budget--) { s->failed_pc=0x0c03f9d6u; return 0; }
vf3_matrix_load(s,ram,7,r[8]+r[0]);
goto P_0c03f9d8;
P_0c03f9d8: /* original e004, guest PC 0x0c03f9d8 */
if(!s->budget--) { s->failed_pc=0x0c03f9d8u; return 0; }
r[0]=0x00000004u;
goto P_0c03f9da;
P_0c03f9da: /* original f686, guest PC 0x0c03f9da */
if(!s->budget--) { s->failed_pc=0x0c03f9dau; return 0; }
vf3_matrix_load(s,ram,6,r[8]+r[0]);
goto P_0c03f9dc;
P_0c03f9dc: /* original a003, guest PC 0x0c03f9dc */
if(!s->budget--) { s->failed_pc=0x0c03f9dcu; return 0; }
vf3_matrix_load(s,ram,5,r[8]);
goto P_0c03f9e6;
P_0c03f9de: /* original f588, guest PC 0x0c03f9de */
if(!s->budget--) { s->failed_pc=0x0c03f9deu; return 0; }
vf3_matrix_load(s,ram,5,r[8]);
goto P_0c03f9e0;
P_0c03f9e0: /* original f5fc, guest PC 0x0c03f9e0 */
if(!s->budget--) { s->failed_pc=0x0c03f9e0u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c03f9e2;
P_0c03f9e2: /* original f6fc, guest PC 0x0c03f9e2 */
if(!s->budget--) { s->failed_pc=0x0c03f9e2u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c03f9e4;
P_0c03f9e4: /* original f7fc, guest PC 0x0c03f9e4 */
if(!s->budget--) { s->failed_pc=0x0c03f9e4u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c03f9e6;
P_0c03f9e6: /* original b0cb, guest PC 0x0c03f9e6 */
if(!s->budget--) { s->failed_pc=0x0c03f9e6u; return 0; }
target=code_base|0x0c03fb80u; r[16]=code_base|0x0c03f9eau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f9eau) { target=s->pc; goto dispatch; }
goto P_0c03f9ea;
P_0c03f9e8: /* original 0009, guest PC 0x0c03f9e8 */
if(!s->budget--) { s->failed_pc=0x0c03f9e8u; return 0; }
goto P_0c03f9ea;
P_0c03f9ea: /* original 1e04, guest PC 0x0c03f9ea */
if(!s->budget--) { s->failed_pc=0x0c03f9eau; return 0; }
write(ram,r[14]+16,r[0],4);
goto P_0c03f9ec;
P_0c03f9ec: /* original e310, guest PC 0x0c03f9ec */
if(!s->budget--) { s->failed_pc=0x0c03f9ecu; return 0; }
r[3]=0x00000010u;
goto P_0c03f9ee;
P_0c03f9ee: /* original 50db, guest PC 0x0c03f9ee */
if(!s->budget--) { s->failed_pc=0x0c03f9eeu; return 0; }
r[0]=read(ram,r[13]+44,4);
goto P_0c03f9f0;
P_0c03f9f0: /* original c930, guest PC 0x0c03f9f0 */
if(!s->budget--) { s->failed_pc=0x0c03f9f0u; return 0; }
r[0]&=48u;
goto P_0c03f9f2;
P_0c03f9f2: /* original 6403, guest PC 0x0c03f9f2 */
if(!s->budget--) { s->failed_pc=0x0c03f9f2u; return 0; }
r[4]=r[0];
goto P_0c03f9f4;
P_0c03f9f4: /* original e018, guest PC 0x0c03f9f4 */
if(!s->budget--) { s->failed_pc=0x0c03f9f4u; return 0; }
r[0]=0x00000018u;
goto P_0c03f9f6;
P_0c03f9f6: /* original f7d6, guest PC 0x0c03f9f6 */
if(!s->budget--) { s->failed_pc=0x0c03f9f6u; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c03f9f8;
P_0c03f9f8: /* original 2348, guest PC 0x0c03f9f8 */
if(!s->budget--) { s->failed_pc=0x0c03f9f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c03f9fa;
P_0c03f9fa: /* original e020, guest PC 0x0c03f9fa */
if(!s->budget--) { s->failed_pc=0x0c03f9fau; return 0; }
r[0]=0x00000020u;
goto P_0c03f9fc;
P_0c03f9fc: /* original 8d06, guest PC 0x0c03f9fc */
if(!s->budget--) { s->failed_pc=0x0c03f9fcu; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,6,r[13]+r[0]);
if(cond) { goto P_0c03fa0c; }
goto P_0c03fa00;
P_0c03f9fe: /* original f6d6, guest PC 0x0c03f9fe */
if(!s->budget--) { s->failed_pc=0x0c03f9feu; return 0; }
vf3_matrix_load(s,ram,6,r[13]+r[0]);
goto P_0c03fa00;
P_0c03fa00: /* original f37c, guest PC 0x0c03fa00 */
if(!s->budget--) { s->failed_pc=0x0c03fa00u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c03fa02;
P_0c03fa02: /* original f7fc, guest PC 0x0c03fa02 */
if(!s->budget--) { s->failed_pc=0x0c03fa02u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c03fa04;
P_0c03fa04: /* original f731, guest PC 0x0c03fa04 */
if(!s->budget--) { s->failed_pc=0x0c03fa04u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c03fa06;
P_0c03fa06: /* original f36c, guest PC 0x0c03fa06 */
if(!s->budget--) { s->failed_pc=0x0c03fa06u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c03fa08;
P_0c03fa08: /* original f6fc, guest PC 0x0c03fa08 */
if(!s->budget--) { s->failed_pc=0x0c03fa08u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c03fa0a;
P_0c03fa0a: /* original f631, guest PC 0x0c03fa0a */
if(!s->budget--) { s->failed_pc=0x0c03fa0au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c03fa0c;
P_0c03fa0c: /* original e01c, guest PC 0x0c03fa0c */
if(!s->budget--) { s->failed_pc=0x0c03fa0cu; return 0; }
r[0]=0x0000001cu;
goto P_0c03fa0e;
P_0c03fa0e: /* original e320, guest PC 0x0c03fa0e */
if(!s->budget--) { s->failed_pc=0x0c03fa0eu; return 0; }
r[3]=0x00000020u;
goto P_0c03fa10;
P_0c03fa10: /* original f5d6, guest PC 0x0c03fa10 */
if(!s->budget--) { s->failed_pc=0x0c03fa10u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c03fa12;
P_0c03fa12: /* original 2438, guest PC 0x0c03fa12 */
if(!s->budget--) { s->failed_pc=0x0c03fa12u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c03fa14;
P_0c03fa14: /* original e024, guest PC 0x0c03fa14 */
if(!s->budget--) { s->failed_pc=0x0c03fa14u; return 0; }
r[0]=0x00000024u;
goto P_0c03fa16;
P_0c03fa16: /* original 8f06, guest PC 0x0c03fa16 */
if(!s->budget--) { s->failed_pc=0x0c03fa16u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[13]+r[0]);
if(!cond) { goto P_0c03fa26; }
goto P_0c03fa1a;
P_0c03fa18: /* original f4d6, guest PC 0x0c03fa18 */
if(!s->budget--) { s->failed_pc=0x0c03fa18u; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c03fa1a;
P_0c03fa1a: /* original f35c, guest PC 0x0c03fa1a */
if(!s->budget--) { s->failed_pc=0x0c03fa1au; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c03fa1c;
P_0c03fa1c: /* original f5fc, guest PC 0x0c03fa1c */
if(!s->budget--) { s->failed_pc=0x0c03fa1cu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c03fa1e;
P_0c03fa1e: /* original f531, guest PC 0x0c03fa1e */
if(!s->budget--) { s->failed_pc=0x0c03fa1eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c03fa20;
P_0c03fa20: /* original f34c, guest PC 0x0c03fa20 */
if(!s->budget--) { s->failed_pc=0x0c03fa20u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03fa22;
P_0c03fa22: /* original f4fc, guest PC 0x0c03fa22 */
if(!s->budget--) { s->failed_pc=0x0c03fa22u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c03fa24;
P_0c03fa24: /* original f431, guest PC 0x0c03fa24 */
if(!s->budget--) { s->failed_pc=0x0c03fa24u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c03fa26;
P_0c03fa26: /* original 64f3, guest PC 0x0c03fa26 */
if(!s->budget--) { s->failed_pc=0x0c03fa26u; return 0; }
r[4]=r[15];
goto P_0c03fa28;
P_0c03fa28: /* original 7418, guest PC 0x0c03fa28 */
if(!s->budget--) { s->failed_pc=0x0c03fa28u; return 0; }
r[4]+=0x00000018u;
goto P_0c03fa2a;
P_0c03fa2a: /* original f47a, guest PC 0x0c03fa2a */
if(!s->budget--) { s->failed_pc=0x0c03fa2au; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c03fa2c;
P_0c03fa2c: /* original 2aa8, guest PC 0x0c03fa2c */
if(!s->budget--) { s->failed_pc=0x0c03fa2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c03fa2e;
P_0c03fa2e: /* original 6342, guest PC 0x0c03fa2e */
if(!s->budget--) { s->failed_pc=0x0c03fa2eu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c03fa30;
P_0c03fa30: /* original d578, guest PC 0x0c03fa30 */
if(!s->budget--) { s->failed_pc=0x0c03fa30u; return 0; }
r[5]=read(ram,0x0c03fc14u,4);
goto P_0c03fa32;
P_0c03fa32: /* original 2359, guest PC 0x0c03fa32 */
if(!s->budget--) { s->failed_pc=0x0c03fa32u; return 0; }
r[3]&=r[5];
goto P_0c03fa34;
P_0c03fa34: /* original 1f35, guest PC 0x0c03fa34 */
if(!s->budget--) { s->failed_pc=0x0c03fa34u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c03fa36;
P_0c03fa36: /* original f46a, guest PC 0x0c03fa36 */
if(!s->budget--) { s->failed_pc=0x0c03fa36u; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c03fa38;
P_0c03fa38: /* original 6d42, guest PC 0x0c03fa38 */
if(!s->budget--) { s->failed_pc=0x0c03fa38u; return 0; }
tmp=read(ram,r[4],4);
r[13]=tmp;
goto P_0c03fa3a;
P_0c03fa3a: /* original f45a, guest PC 0x0c03fa3a */
if(!s->budget--) { s->failed_pc=0x0c03fa3au; return 0; }
vf3_matrix_store(s,ram,5,r[4]);
goto P_0c03fa3c;
P_0c03fa3c: /* original 6742, guest PC 0x0c03fa3c */
if(!s->budget--) { s->failed_pc=0x0c03fa3cu; return 0; }
tmp=read(ram,r[4],4);
r[7]=tmp;
goto P_0c03fa3e;
P_0c03fa3e: /* original 2d59, guest PC 0x0c03fa3e */
if(!s->budget--) { s->failed_pc=0x0c03fa3eu; return 0; }
r[13]&=r[5];
goto P_0c03fa40;
P_0c03fa40: /* original f44a, guest PC 0x0c03fa40 */
if(!s->budget--) { s->failed_pc=0x0c03fa40u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c03fa42;
P_0c03fa42: /* original 6342, guest PC 0x0c03fa42 */
if(!s->budget--) { s->failed_pc=0x0c03fa42u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c03fa44;
P_0c03fa44: /* original 4729, guest PC 0x0c03fa44 */
if(!s->budget--) { s->failed_pc=0x0c03fa44u; return 0; }
r[7]>>=16;
goto P_0c03fa46;
P_0c03fa46: /* original 4329, guest PC 0x0c03fa46 */
if(!s->budget--) { s->failed_pc=0x0c03fa46u; return 0; }
r[3]>>=16;
goto P_0c03fa48;
P_0c03fa48: /* original 8d02, guest PC 0x0c03fa48 */
if(!s->budget--) { s->failed_pc=0x0c03fa48u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+16,r[3],4);
if(cond) { goto P_0c03fa50; }
goto P_0c03fa4c;
P_0c03fa4a: /* original 1f34, guest PC 0x0c03fa4a */
if(!s->budget--) { s->failed_pc=0x0c03fa4au; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c03fa4c;
P_0c03fa4c: /* original a001, guest PC 0x0c03fa4c */
if(!s->budget--) { s->failed_pc=0x0c03fa4cu; return 0; }
r[4]=0x00000002u;
goto P_0c03fa52;
P_0c03fa4e: /* original e402, guest PC 0x0c03fa4e */
if(!s->budget--) { s->failed_pc=0x0c03fa4eu; return 0; }
r[4]=0x00000002u;
goto P_0c03fa50;
P_0c03fa50: /* original e400, guest PC 0x0c03fa50 */
if(!s->budget--) { s->failed_pc=0x0c03fa50u; return 0; }
r[4]=0x00000000u;
goto P_0c03fa52;
P_0c03fa52: /* original 4408, guest PC 0x0c03fa52 */
if(!s->budget--) { s->failed_pc=0x0c03fa52u; return 0; }
r[4]<<=2;
goto P_0c03fa54;
P_0c03fa54: /* original 1f43, guest PC 0x0c03fa54 */
if(!s->budget--) { s->failed_pc=0x0c03fa54u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c03fa56;
P_0c03fa56: /* original d370, guest PC 0x0c03fa56 */
if(!s->budget--) { s->failed_pc=0x0c03fa56u; return 0; }
r[3]=read(ram,0x0c03fc18u,4);
goto P_0c03fa58;
P_0c03fa58: /* original d170, guest PC 0x0c03fa58 */
if(!s->budget--) { s->failed_pc=0x0c03fa58u; return 0; }
r[1]=read(ram,0x0c03fc1cu,4);
goto P_0c03fa5a;
P_0c03fa5a: /* original 6032, guest PC 0x0c03fa5a */
if(!s->budget--) { s->failed_pc=0x0c03fa5au; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c03fa5c;
P_0c03fa5c: /* original 044e, guest PC 0x0c03fa5c */
if(!s->budget--) { s->failed_pc=0x0c03fa5cu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c03fa5e;
P_0c03fa5e: /* original 6243, guest PC 0x0c03fa5e */
if(!s->budget--) { s->failed_pc=0x0c03fa5eu; return 0; }
r[2]=r[4];
goto P_0c03fa60;
P_0c03fa60: /* original 4229, guest PC 0x0c03fa60 */
if(!s->budget--) { s->failed_pc=0x0c03fa60u; return 0; }
r[2]>>=16;
goto P_0c03fa62;
P_0c03fa62: /* original 4219, guest PC 0x0c03fa62 */
if(!s->budget--) { s->failed_pc=0x0c03fa62u; return 0; }
r[2]>>=8;
goto P_0c03fa64;
P_0c03fa64: /* original 2122, guest PC 0x0c03fa64 */
if(!s->budget--) { s->failed_pc=0x0c03fa64u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c03fa66;
P_0c03fa66: /* original d36e, guest PC 0x0c03fa66 */
if(!s->budget--) { s->failed_pc=0x0c03fa66u; return 0; }
r[3]=read(ram,0x0c03fc20u,4);
goto P_0c03fa68;
P_0c03fa68: /* original 2322, guest PC 0x0c03fa68 */
if(!s->budget--) { s->failed_pc=0x0c03fa68u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c03fa6a;
P_0c03fa6a: /* original d06e, guest PC 0x0c03fa6a */
if(!s->budget--) { s->failed_pc=0x0c03fa6au; return 0; }
r[0]=read(ram,0x0c03fc24u,4);
goto P_0c03fa6c;
P_0c03fa6c: /* original d36e, guest PC 0x0c03fa6c */
if(!s->budget--) { s->failed_pc=0x0c03fa6cu; return 0; }
r[3]=read(ram,0x0c03fc28u,4);
goto P_0c03fa6e;
P_0c03fa6e: /* original 62e2, guest PC 0x0c03fa6e */
if(!s->budget--) { s->failed_pc=0x0c03fa6eu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03fa70;
P_0c03fa70: /* original 2409, guest PC 0x0c03fa70 */
if(!s->budget--) { s->failed_pc=0x0c03fa70u; return 0; }
r[4]&=r[0];
goto P_0c03fa72;
P_0c03fa72: /* original 243b, guest PC 0x0c03fa72 */
if(!s->budget--) { s->failed_pc=0x0c03fa72u; return 0; }
r[4]|=r[3];
goto P_0c03fa74;
P_0c03fa74: /* original 2422, guest PC 0x0c03fa74 */
if(!s->budget--) { s->failed_pc=0x0c03fa74u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c03fa76;
P_0c03fa76: /* original 51e1, guest PC 0x0c03fa76 */
if(!s->budget--) { s->failed_pc=0x0c03fa76u; return 0; }
r[1]=read(ram,r[14]+4,4);
goto P_0c03fa78;
P_0c03fa78: /* original 1411, guest PC 0x0c03fa78 */
if(!s->budget--) { s->failed_pc=0x0c03fa78u; return 0; }
write(ram,r[4]+4,r[1],4);
goto P_0c03fa7a;
P_0c03fa7a: /* original 52e2, guest PC 0x0c03fa7a */
if(!s->budget--) { s->failed_pc=0x0c03fa7au; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c03fa7c;
P_0c03fa7c: /* original 1422, guest PC 0x0c03fa7c */
if(!s->budget--) { s->failed_pc=0x0c03fa7cu; return 0; }
write(ram,r[4]+8,r[2],4);
goto P_0c03fa7e;
P_0c03fa7e: /* original 51e3, guest PC 0x0c03fa7e */
if(!s->budget--) { s->failed_pc=0x0c03fa7eu; return 0; }
r[1]=read(ram,r[14]+12,4);
goto P_0c03fa80;
P_0c03fa80: /* original 1413, guest PC 0x0c03fa80 */
if(!s->budget--) { s->failed_pc=0x0c03fa80u; return 0; }
write(ram,r[4]+12,r[1],4);
goto P_0c03fa82;
P_0c03fa82: /* original 52e4, guest PC 0x0c03fa82 */
if(!s->budget--) { s->failed_pc=0x0c03fa82u; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c03fa84;
P_0c03fa84: /* original 1424, guest PC 0x0c03fa84 */
if(!s->budget--) { s->failed_pc=0x0c03fa84u; return 0; }
write(ram,r[4]+16,r[2],4);
goto P_0c03fa86;
P_0c03fa86: /* original 0483, guest PC 0x0c03fa86 */
if(!s->budget--) { s->failed_pc=0x0c03fa86u; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c03fa88;
P_0c03fa88: /* original 66b3, guest PC 0x0c03fa88 */
if(!s->budget--) { s->failed_pc=0x0c03fa88u; return 0; }
r[6]=r[11];
goto P_0c03fa8a;
P_0c03fa8a: /* original e1ff, guest PC 0x0c03fa8a */
if(!s->budget--) { s->failed_pc=0x0c03fa8au; return 0; }
r[1]=0xffffffffu;
goto P_0c03fa8c;
P_0c03fa8c: /* original 7420, guest PC 0x0c03fa8c */
if(!s->budget--) { s->failed_pc=0x0c03fa8cu; return 0; }
r[4]+=0x00000020u;
goto P_0c03fa8e;
P_0c03fa8e: /* original 65c3, guest PC 0x0c03fa8e */
if(!s->budget--) { s->failed_pc=0x0c03fa8eu; return 0; }
r[5]=r[12];
goto P_0c03fa90;
P_0c03fa90: /* original 2412, guest PC 0x0c03fa90 */
if(!s->budget--) { s->failed_pc=0x0c03fa90u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c03fa92;
P_0c03fa92: /* original e00c, guest PC 0x0c03fa92 */
if(!s->budget--) { s->failed_pc=0x0c03fa92u; return 0; }
r[0]=0x0000000cu;
goto P_0c03fa94;
P_0c03fa94: /* original 6262, guest PC 0x0c03fa94 */
if(!s->budget--) { s->failed_pc=0x0c03fa94u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c03fa96;
P_0c03fa96: /* original 1421, guest PC 0x0c03fa96 */
if(!s->budget--) { s->failed_pc=0x0c03fa96u; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c03fa98;
P_0c03fa98: /* original 6152, guest PC 0x0c03fa98 */
if(!s->budget--) { s->failed_pc=0x0c03fa98u; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c03fa9a;
P_0c03fa9a: /* original 1412, guest PC 0x0c03fa9a */
if(!s->budget--) { s->failed_pc=0x0c03fa9au; return 0; }
write(ram,r[4]+8,r[1],4);
goto P_0c03fa9c;
P_0c03fa9c: /* original f4d7, guest PC 0x0c03fa9c */
if(!s->budget--) { s->failed_pc=0x0c03fa9cu; return 0; }
vf3_matrix_store(s,ram,13,r[4]+r[0]);
goto P_0c03fa9e;
P_0c03fa9e: /* original e018, guest PC 0x0c03fa9e */
if(!s->budget--) { s->failed_pc=0x0c03fa9eu; return 0; }
r[0]=0x00000018u;
goto P_0c03faa0;
P_0c03faa0: /* original 5261, guest PC 0x0c03faa0 */
if(!s->budget--) { s->failed_pc=0x0c03faa0u; return 0; }
r[2]=read(ram,r[6]+4,4);
goto P_0c03faa2;
P_0c03faa2: /* original 1424, guest PC 0x0c03faa2 */
if(!s->budget--) { s->failed_pc=0x0c03faa2u; return 0; }
write(ram,r[4]+16,r[2],4);
goto P_0c03faa4;
P_0c03faa4: /* original 5151, guest PC 0x0c03faa4 */
if(!s->budget--) { s->failed_pc=0x0c03faa4u; return 0; }
r[1]=read(ram,r[5]+4,4);
goto P_0c03faa6;
P_0c03faa6: /* original 1415, guest PC 0x0c03faa6 */
if(!s->budget--) { s->failed_pc=0x0c03faa6u; return 0; }
write(ram,r[4]+20,r[1],4);
goto P_0c03faa8;
P_0c03faa8: /* original f4d7, guest PC 0x0c03faa8 */
if(!s->budget--) { s->failed_pc=0x0c03faa8u; return 0; }
vf3_matrix_store(s,ram,13,r[4]+r[0]);
goto P_0c03faaa;
P_0c03faaa: /* original e024, guest PC 0x0c03faaa */
if(!s->budget--) { s->failed_pc=0x0c03faaau; return 0; }
r[0]=0x00000024u;
goto P_0c03faac;
P_0c03faac: /* original 5262, guest PC 0x0c03faac */
if(!s->budget--) { s->failed_pc=0x0c03faacu; return 0; }
r[2]=read(ram,r[6]+8,4);
goto P_0c03faae;
P_0c03faae: /* original 1427, guest PC 0x0c03faae */
if(!s->budget--) { s->failed_pc=0x0c03faaeu; return 0; }
write(ram,r[4]+28,r[2],4);
goto P_0c03fab0;
P_0c03fab0: /* original 5152, guest PC 0x0c03fab0 */
if(!s->budget--) { s->failed_pc=0x0c03fab0u; return 0; }
r[1]=read(ram,r[5]+8,4);
goto P_0c03fab2;
P_0c03fab2: /* original 1418, guest PC 0x0c03fab2 */
if(!s->budget--) { s->failed_pc=0x0c03fab2u; return 0; }
write(ram,r[4]+32,r[1],4);
goto P_0c03fab4;
P_0c03fab4: /* original f4d7, guest PC 0x0c03fab4 */
if(!s->budget--) { s->failed_pc=0x0c03fab4u; return 0; }
vf3_matrix_store(s,ram,13,r[4]+r[0]);
goto P_0c03fab6;
P_0c03fab6: /* original 5263, guest PC 0x0c03fab6 */
if(!s->budget--) { s->failed_pc=0x0c03fab6u; return 0; }
r[2]=read(ram,r[6]+12,4);
goto P_0c03fab8;
P_0c03fab8: /* original 142a, guest PC 0x0c03fab8 */
if(!s->budget--) { s->failed_pc=0x0c03fab8u; return 0; }
write(ram,r[4]+40,r[2],4);
goto P_0c03faba;
P_0c03faba: /* original 5153, guest PC 0x0c03faba */
if(!s->budget--) { s->failed_pc=0x0c03fabau; return 0; }
r[1]=read(ram,r[5]+12,4);
goto P_0c03fabc;
P_0c03fabc: /* original 141b, guest PC 0x0c03fabc */
if(!s->budget--) { s->failed_pc=0x0c03fabcu; return 0; }
write(ram,r[4]+44,r[1],4);
goto P_0c03fabe;
P_0c03fabe: /* original d25b, guest PC 0x0c03fabe */
if(!s->budget--) { s->failed_pc=0x0c03fabeu; return 0; }
r[2]=read(ram,0x0c03fc2cu,4);
goto P_0c03fac0;
P_0c03fac0: /* original 292b, guest PC 0x0c03fac0 */
if(!s->budget--) { s->failed_pc=0x0c03fac0u; return 0; }
r[9]|=r[2];
goto P_0c03fac2;
P_0c03fac2: /* original 149c, guest PC 0x0c03fac2 */
if(!s->budget--) { s->failed_pc=0x0c03fac2u; return 0; }
write(ram,r[4]+48,r[9],4);
goto P_0c03fac4;
P_0c03fac4: /* original 51f5, guest PC 0x0c03fac4 */
if(!s->budget--) { s->failed_pc=0x0c03fac4u; return 0; }
r[1]=read(ram,r[15]+20,4);
goto P_0c03fac6;
P_0c03fac6: /* original 217b, guest PC 0x0c03fac6 */
if(!s->budget--) { s->failed_pc=0x0c03fac6u; return 0; }
r[1]|=r[7];
goto P_0c03fac8;
P_0c03fac8: /* original 141d, guest PC 0x0c03fac8 */
if(!s->budget--) { s->failed_pc=0x0c03fac8u; return 0; }
write(ram,r[4]+52,r[1],4);
goto P_0c03faca;
P_0c03faca: /* original 27db, guest PC 0x0c03faca */
if(!s->budget--) { s->failed_pc=0x0c03facau; return 0; }
r[7]|=r[13];
goto P_0c03facc;
P_0c03facc: /* original 147e, guest PC 0x0c03facc */
if(!s->budget--) { s->failed_pc=0x0c03faccu; return 0; }
write(ram,r[4]+56,r[7],4);
goto P_0c03face;
P_0c03face: /* original 51f4, guest PC 0x0c03face */
if(!s->budget--) { s->failed_pc=0x0c03faceu; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c03fad0;
P_0c03fad0: /* original 2d1b, guest PC 0x0c03fad0 */
if(!s->budget--) { s->failed_pc=0x0c03fad0u; return 0; }
r[13]|=r[1];
goto P_0c03fad2;
P_0c03fad2: /* original 14df, guest PC 0x0c03fad2 */
if(!s->budget--) { s->failed_pc=0x0c03fad2u; return 0; }
write(ram,r[4]+60,r[13],4);
goto P_0c03fad4;
P_0c03fad4: /* original 0483, guest PC 0x0c03fad4 */
if(!s->budget--) { s->failed_pc=0x0c03fad4u; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c03fad6;
P_0c03fad6: /* original 7420, guest PC 0x0c03fad6 */
if(!s->budget--) { s->failed_pc=0x0c03fad6u; return 0; }
r[4]+=0x00000020u;
goto P_0c03fad8;
P_0c03fad8: /* original 0483, guest PC 0x0c03fad8 */
if(!s->budget--) { s->failed_pc=0x0c03fad8u; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c03fada;
P_0c03fada: /* original d14f, guest PC 0x0c03fada */
if(!s->budget--) { s->failed_pc=0x0c03fadau; return 0; }
r[1]=read(ram,0x0c03fc18u,4);
goto P_0c03fadc;
P_0c03fadc: /* original 7420, guest PC 0x0c03fadc */
if(!s->budget--) { s->failed_pc=0x0c03fadcu; return 0; }
r[4]+=0x00000020u;
goto P_0c03fade;
P_0c03fade: /* original 55f3, guest PC 0x0c03fade */
if(!s->budget--) { s->failed_pc=0x0c03fadeu; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c03fae0;
P_0c03fae0: /* original 6312, guest PC 0x0c03fae0 */
if(!s->budget--) { s->failed_pc=0x0c03fae0u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c03fae2;
P_0c03fae2: /* original d253, guest PC 0x0c03fae2 */
if(!s->budget--) { s->failed_pc=0x0c03fae2u; return 0; }
r[2]=read(ram,0x0c03fc30u,4);
goto P_0c03fae4;
P_0c03fae4: /* original 353c, guest PC 0x0c03fae4 */
if(!s->budget--) { s->failed_pc=0x0c03fae4u; return 0; }
r[5]+=r[3];
goto P_0c03fae6;
P_0c03fae6: /* original d34f, guest PC 0x0c03fae6 */
if(!s->budget--) { s->failed_pc=0x0c03fae6u; return 0; }
r[3]=read(ram,0x0c03fc24u,4);
goto P_0c03fae8;
P_0c03fae8: /* original 6052, guest PC 0x0c03fae8 */
if(!s->budget--) { s->failed_pc=0x0c03fae8u; return 0; }
tmp=read(ram,r[5],4);
r[0]=tmp;
goto P_0c03faea;
P_0c03faea: /* original 2439, guest PC 0x0c03faea */
if(!s->budget--) { s->failed_pc=0x0c03faeau; return 0; }
r[4]&=r[3];
goto P_0c03faec;
P_0c03faec: /* original 2029, guest PC 0x0c03faec */
if(!s->budget--) { s->failed_pc=0x0c03faecu; return 0; }
r[0]&=r[2];
goto P_0c03faee;
P_0c03faee: /* original 204b, guest PC 0x0c03faee */
if(!s->budget--) { s->failed_pc=0x0c03faeeu; return 0; }
r[0]|=r[4];
goto P_0c03faf0;
P_0c03faf0: /* original 2502, guest PC 0x0c03faf0 */
if(!s->budget--) { s->failed_pc=0x0c03faf0u; return 0; }
write(ram,r[5],r[0],4);
goto P_0c03faf2;
P_0c03faf2: /* original 7f3c, guest PC 0x0c03faf2 */
if(!s->budget--) { s->failed_pc=0x0c03faf2u; return 0; }
r[15]+=0x0000003cu;
goto P_0c03faf4;
P_0c03faf4: /* original 4f26, guest PC 0x0c03faf4 */
if(!s->budget--) { s->failed_pc=0x0c03faf4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03faf6;
P_0c03faf6: /* original fdf9, guest PC 0x0c03faf6 */
if(!s->budget--) { s->failed_pc=0x0c03faf6u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03faf8;
P_0c03faf8: /* original fef9, guest PC 0x0c03faf8 */
if(!s->budget--) { s->failed_pc=0x0c03faf8u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03fafa;
P_0c03fafa: /* original fff9, guest PC 0x0c03fafa */
if(!s->budget--) { s->failed_pc=0x0c03fafau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03fafc;
P_0c03fafc: /* original 68f6, guest PC 0x0c03fafc */
if(!s->budget--) { s->failed_pc=0x0c03fafcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03fafe;
P_0c03fafe: /* original 69f6, guest PC 0x0c03fafe */
if(!s->budget--) { s->failed_pc=0x0c03fafeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03fb00;
P_0c03fb00: /* original 6af6, guest PC 0x0c03fb00 */
if(!s->budget--) { s->failed_pc=0x0c03fb00u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03fb02;
P_0c03fb02: /* original 6bf6, guest PC 0x0c03fb02 */
if(!s->budget--) { s->failed_pc=0x0c03fb02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03fb04;
P_0c03fb04: /* original 6cf6, guest PC 0x0c03fb04 */
if(!s->budget--) { s->failed_pc=0x0c03fb04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03fb06;
P_0c03fb06: /* original 6df6, guest PC 0x0c03fb06 */
if(!s->budget--) { s->failed_pc=0x0c03fb06u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03fb08;
P_0c03fb08: /* original 000b, guest PC 0x0c03fb08 */
if(!s->budget--) { s->failed_pc=0x0c03fb08u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03fb0a: /* original 6ef6, guest PC 0x0c03fb0a */
if(!s->budget--) { s->failed_pc=0x0c03fb0au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03fb0cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fb0cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
