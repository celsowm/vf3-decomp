/* Static C ABI adapters. Generated with tools/oracle/translate_adapters.py.
 * Matrix operations are hand-written in matrix_family.c; unknown code fails.
 * Executed opcodes are checked against the untouched identity image. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <math.h>
#include <string.h>
#define read vf3_matrix_read
#define write vf3_matrix_write
static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }
static uint32_t truncate_float(uint32_t u) { double d=as_float(u); if(isnan(d) || d< -2147483648.0) return 0x80000000u; if(d>=2147483648.0) return 0x7fffffffu; return (uint32_t)(int32_t)d; }
static void divide_step(vf3_matrix_state*s,unsigned n,unsigned m) { uint32_t *r=s->v; unsigned oldq=(r[17]>>8)&1u,sign=(r[17]>>9)&1u,q=r[n]>>31; uint32_t divisor=r[m],shifted=(r[n]<<1)|(r[17]&1u); r[n]=oldq==sign?shifted-divisor:shifted+divisor; unsigned carry=oldq==sign?r[n]>shifted:r[n]<shifted; q^=carry^sign; r[17]=(r[17]&~0x101u)|(q<<8)|(q==sign); }
int vf3_seventh_c7_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03550cu: goto P_0c03550c;
case 0x0c03550eu: goto P_0c03550e;
case 0x0c035510u: goto P_0c035510;
case 0x0c035512u: goto P_0c035512;
case 0x0c035514u: goto P_0c035514;
case 0x0c035516u: goto P_0c035516;
case 0x0c035518u: goto P_0c035518;
case 0x0c03551au: goto P_0c03551a;
case 0x0c03551cu: goto P_0c03551c;
case 0x0c03551eu: goto P_0c03551e;
case 0x0c035520u: goto P_0c035520;
case 0x0c035522u: goto P_0c035522;
case 0x0c035524u: goto P_0c035524;
case 0x0c035526u: goto P_0c035526;
case 0x0c035528u: goto P_0c035528;
case 0x0c03552au: goto P_0c03552a;
case 0x0c03552cu: goto P_0c03552c;
case 0x0c03552eu: goto P_0c03552e;
case 0x0c035530u: goto P_0c035530;
case 0x0c035532u: goto P_0c035532;
case 0x0c035534u: goto P_0c035534;
case 0x0c035536u: goto P_0c035536;
case 0x0c035538u: goto P_0c035538;
case 0x0c03553au: goto P_0c03553a;
case 0x0c03553cu: goto P_0c03553c;
case 0x0c03553eu: goto P_0c03553e;
case 0x0c035540u: goto P_0c035540;
case 0x0c035542u: goto P_0c035542;
case 0x0c035544u: goto P_0c035544;
case 0x0c035546u: goto P_0c035546;
case 0x0c035548u: goto P_0c035548;
case 0x0c03554au: goto P_0c03554a;
case 0x0c03554cu: goto P_0c03554c;
case 0x0c03554eu: goto P_0c03554e;
case 0x0c035550u: goto P_0c035550;
case 0x0c035552u: goto P_0c035552;
case 0x0c035554u: goto P_0c035554;
case 0x0c035556u: goto P_0c035556;
case 0x0c035558u: goto P_0c035558;
case 0x0c03555au: goto P_0c03555a;
case 0x0c03555cu: goto P_0c03555c;
case 0x0c03555eu: goto P_0c03555e;
case 0x0c035560u: goto P_0c035560;
case 0x0c035562u: goto P_0c035562;
case 0x0c035564u: goto P_0c035564;
case 0x0c035566u: goto P_0c035566;
case 0x0c035568u: goto P_0c035568;
case 0x0c03556au: goto P_0c03556a;
case 0x0c03556cu: goto P_0c03556c;
case 0x0c03556eu: goto P_0c03556e;
case 0x0c035570u: goto P_0c035570;
case 0x0c035572u: goto P_0c035572;
case 0x0c035574u: goto P_0c035574;
case 0x0c035576u: goto P_0c035576;
case 0x0c035578u: goto P_0c035578;
case 0x0c03557au: goto P_0c03557a;
case 0x0c03557cu: goto P_0c03557c;
case 0x0c03557eu: goto P_0c03557e;
case 0x0c035580u: goto P_0c035580;
case 0x0c035582u: goto P_0c035582;
case 0x0c035584u: goto P_0c035584;
case 0x0c035586u: goto P_0c035586;
case 0x0c035588u: goto P_0c035588;
case 0x0c03558au: goto P_0c03558a;
case 0x0c03558cu: goto P_0c03558c;
case 0x0c0355a4u: goto P_0c0355a4;
case 0x0c0355a6u: goto P_0c0355a6;
case 0x0c0355a8u: goto P_0c0355a8;
case 0x0c0355aau: goto P_0c0355aa;
case 0x0c0355acu: goto P_0c0355ac;
case 0x0c0355aeu: goto P_0c0355ae;
case 0x0c0355b0u: goto P_0c0355b0;
case 0x0c0355b2u: goto P_0c0355b2;
case 0x0c0355b4u: goto P_0c0355b4;
case 0x0c0355b6u: goto P_0c0355b6;
case 0x0c0355b8u: goto P_0c0355b8;
case 0x0c0355bau: goto P_0c0355ba;
case 0x0c0355bcu: goto P_0c0355bc;
case 0x0c0355beu: goto P_0c0355be;
case 0x0c0355c0u: goto P_0c0355c0;
case 0x0c0355c2u: goto P_0c0355c2;
case 0x0c0355c4u: goto P_0c0355c4;
case 0x0c0355c6u: goto P_0c0355c6;
case 0x0c0355c8u: goto P_0c0355c8;
case 0x0c035a20u: goto P_0c035a20;
case 0x0c035a22u: goto P_0c035a22;
case 0x0c035a24u: goto P_0c035a24;
case 0x0c035a26u: goto P_0c035a26;
case 0x0c035a28u: goto P_0c035a28;
case 0x0c035a2au: goto P_0c035a2a;
case 0x0c035a2cu: goto P_0c035a2c;
case 0x0c035a2eu: goto P_0c035a2e;
case 0x0c035a30u: goto P_0c035a30;
case 0x0c035a32u: goto P_0c035a32;
case 0x0c035a34u: goto P_0c035a34;
case 0x0c035a36u: goto P_0c035a36;
case 0x0c035a4eu: goto P_0c035a4e;
case 0x0c035a50u: goto P_0c035a50;
case 0x0c035a52u: goto P_0c035a52;
case 0x0c035a54u: goto P_0c035a54;
case 0x0c035a56u: goto P_0c035a56;
case 0x0c035a58u: goto P_0c035a58;
case 0x0c035a5au: goto P_0c035a5a;
case 0x0c035a5cu: goto P_0c035a5c;
case 0x0c035a5eu: goto P_0c035a5e;
case 0x0c035a60u: goto P_0c035a60;
case 0x0c035a62u: goto P_0c035a62;
case 0x0c035a64u: goto P_0c035a64;
case 0x0c035a66u: goto P_0c035a66;
case 0x0c035a68u: goto P_0c035a68;
case 0x0c035a6au: goto P_0c035a6a;
case 0x0c035a6cu: goto P_0c035a6c;
case 0x0c035a6eu: goto P_0c035a6e;
case 0x0c035a70u: goto P_0c035a70;
case 0x0c035a72u: goto P_0c035a72;
case 0x0c035a74u: goto P_0c035a74;
case 0x0c035a76u: goto P_0c035a76;
case 0x0c035a78u: goto P_0c035a78;
case 0x0c035a7au: goto P_0c035a7a;
case 0x0c035a7cu: goto P_0c035a7c;
case 0x0c035a7eu: goto P_0c035a7e;
case 0x0c035a80u: goto P_0c035a80;
case 0x0c035a82u: goto P_0c035a82;
case 0x0c035a84u: goto P_0c035a84;
case 0x0c035a86u: goto P_0c035a86;
case 0x0c035a88u: goto P_0c035a88;
case 0x0c035a8au: goto P_0c035a8a;
case 0x0c035a8cu: goto P_0c035a8c;
case 0x0c035a8eu: goto P_0c035a8e;
case 0x0c035a90u: goto P_0c035a90;
case 0x0c035a92u: goto P_0c035a92;
case 0x0c035a94u: goto P_0c035a94;
case 0x0c035a96u: goto P_0c035a96;
case 0x0c035a98u: goto P_0c035a98;
case 0x0c035a9au: goto P_0c035a9a;
case 0x0c035a9cu: goto P_0c035a9c;
case 0x0c035a9eu: goto P_0c035a9e;
case 0x0c035aa0u: goto P_0c035aa0;
case 0x0c06f892u: goto P_0c06f892;
case 0x0c06f894u: goto P_0c06f894;
case 0x0c06f896u: goto P_0c06f896;
case 0x0c06f898u: goto P_0c06f898;
case 0x0c06f89au: goto P_0c06f89a;
case 0x0c06f89cu: goto P_0c06f89c;
case 0x0c06f89eu: goto P_0c06f89e;
case 0x0c06f8a0u: goto P_0c06f8a0;
case 0x0c06f8a2u: goto P_0c06f8a2;
case 0x0c06f8a4u: goto P_0c06f8a4;
case 0x0c06f8a6u: goto P_0c06f8a6;
case 0x0c06f8a8u: goto P_0c06f8a8;
case 0x0c06f8aau: goto P_0c06f8aa;
case 0x0c06f8acu: goto P_0c06f8ac;
case 0x0c06f8aeu: goto P_0c06f8ae;
case 0x0c06f8b0u: goto P_0c06f8b0;
case 0x0c06f8b2u: goto P_0c06f8b2;
case 0x0c06f8b4u: goto P_0c06f8b4;
case 0x0c06f8b6u: goto P_0c06f8b6;
case 0x0c06f8b8u: goto P_0c06f8b8;
case 0x0c06f8bau: goto P_0c06f8ba;
case 0x0c06f8bcu: goto P_0c06f8bc;
case 0x0c06f8beu: goto P_0c06f8be;
case 0x0c06f8c0u: goto P_0c06f8c0;
case 0x0c06f8c2u: goto P_0c06f8c2;
case 0x0c06f8c4u: goto P_0c06f8c4;
case 0x0c06f8c6u: goto P_0c06f8c6;
case 0x0c06f8c8u: goto P_0c06f8c8;
case 0x0c06f8cau: goto P_0c06f8ca;
case 0x0c06f8ccu: goto P_0c06f8cc;
case 0x0c06f8ceu: goto P_0c06f8ce;
case 0x0c06f8d0u: goto P_0c06f8d0;
case 0x0c06f8d2u: goto P_0c06f8d2;
case 0x0c06f8d4u: goto P_0c06f8d4;
case 0x0c06f8d6u: goto P_0c06f8d6;
case 0x0c06f8d8u: goto P_0c06f8d8;
case 0x0c06f8dau: goto P_0c06f8da;
case 0x0c06f8dcu: goto P_0c06f8dc;
case 0x0c06f8deu: goto P_0c06f8de;
case 0x0c06f8e0u: goto P_0c06f8e0;
case 0x0c06f8e2u: goto P_0c06f8e2;
case 0x0c06f8e4u: goto P_0c06f8e4;
case 0x0c06f8e6u: goto P_0c06f8e6;
case 0x0c06f8e8u: goto P_0c06f8e8;
case 0x0c06f8eau: goto P_0c06f8ea;
case 0x0c06f8ecu: goto P_0c06f8ec;
case 0x0c06f8eeu: goto P_0c06f8ee;
case 0x0c06f8f0u: goto P_0c06f8f0;
case 0x0c06f8f2u: goto P_0c06f8f2;
case 0x0c06f8f4u: goto P_0c06f8f4;
case 0x0c06f8f6u: goto P_0c06f8f6;
case 0x0c06f8f8u: goto P_0c06f8f8;
case 0x0c06f8fau: goto P_0c06f8fa;
case 0x0c06f8fcu: goto P_0c06f8fc;
case 0x0c06f8feu: goto P_0c06f8fe;
case 0x0c06f900u: goto P_0c06f900;
case 0x0c06f902u: goto P_0c06f902;
case 0x0c06f904u: goto P_0c06f904;
case 0x0c06f906u: goto P_0c06f906;
case 0x0c06f908u: goto P_0c06f908;
case 0x0c06f90au: goto P_0c06f90a;
case 0x0c06f90cu: goto P_0c06f90c;
case 0x0c06f90eu: goto P_0c06f90e;
case 0x0c06f910u: goto P_0c06f910;
case 0x0c06f912u: goto P_0c06f912;
case 0x0c06f914u: goto P_0c06f914;
case 0x0c06f916u: goto P_0c06f916;
case 0x0c06f918u: goto P_0c06f918;
case 0x0c06f91au: goto P_0c06f91a;
case 0x0c06f91cu: goto P_0c06f91c;
case 0x0c06f91eu: goto P_0c06f91e;
case 0x0c06f920u: goto P_0c06f920;
case 0x0c06f922u: goto P_0c06f922;
case 0x0c06f924u: goto P_0c06f924;
case 0x0c06f926u: goto P_0c06f926;
case 0x0c06f928u: goto P_0c06f928;
case 0x0c06f92au: goto P_0c06f92a;
case 0x0c06f92cu: goto P_0c06f92c;
case 0x0c06f92eu: goto P_0c06f92e;
case 0x0c06f930u: goto P_0c06f930;
case 0x0c06f932u: goto P_0c06f932;
case 0x0c06f934u: goto P_0c06f934;
case 0x0c06f936u: goto P_0c06f936;
case 0x0c06f938u: goto P_0c06f938;
case 0x0c06f93au: goto P_0c06f93a;
case 0x0c06f93cu: goto P_0c06f93c;
case 0x0c06f93eu: goto P_0c06f93e;
case 0x0c06f940u: goto P_0c06f940;
case 0x0c06f942u: goto P_0c06f942;
case 0x0c06f944u: goto P_0c06f944;
case 0x0c06f946u: goto P_0c06f946;
case 0x0c06f948u: goto P_0c06f948;
case 0x0c06f94au: goto P_0c06f94a;
case 0x0c06f94cu: goto P_0c06f94c;
case 0x0c06f94eu: goto P_0c06f94e;
case 0x0c06f950u: goto P_0c06f950;
case 0x0c06f952u: goto P_0c06f952;
case 0x0c06f954u: goto P_0c06f954;
case 0x0c06f956u: goto P_0c06f956;
case 0x0c06f958u: goto P_0c06f958;
case 0x0c06f95au: goto P_0c06f95a;
case 0x0c06f95cu: goto P_0c06f95c;
case 0x0c06f95eu: goto P_0c06f95e;
case 0x0c06f960u: goto P_0c06f960;
case 0x0c06f962u: goto P_0c06f962;
case 0x0c06f964u: goto P_0c06f964;
case 0x0c06f966u: goto P_0c06f966;
case 0x0c06f968u: goto P_0c06f968;
case 0x0c06f96au: goto P_0c06f96a;
case 0x0c06f96cu: goto P_0c06f96c;
case 0x0c06f96eu: goto P_0c06f96e;
case 0x0c06f970u: goto P_0c06f970;
case 0x0c06f972u: goto P_0c06f972;
case 0x0c06f974u: goto P_0c06f974;
case 0x0c06f976u: goto P_0c06f976;
case 0x0c06f978u: goto P_0c06f978;
case 0x0c06f97au: goto P_0c06f97a;
case 0x0c06f97cu: goto P_0c06f97c;
case 0x0c06f97eu: goto P_0c06f97e;
case 0x0c06f980u: goto P_0c06f980;
case 0x0c06f982u: goto P_0c06f982;
case 0x0c06f984u: goto P_0c06f984;
case 0x0c06f986u: goto P_0c06f986;
case 0x0c06f988u: goto P_0c06f988;
case 0x0c06f98au: goto P_0c06f98a;
case 0x0c06f98cu: goto P_0c06f98c;
case 0x0c06f98eu: goto P_0c06f98e;
case 0x0c06f990u: goto P_0c06f990;
case 0x0c071806u: goto P_0c071806;
case 0x0c071808u: goto P_0c071808;
case 0x0c07180au: goto P_0c07180a;
case 0x0c07180cu: goto P_0c07180c;
case 0x0c07180eu: goto P_0c07180e;
case 0x0c071810u: goto P_0c071810;
case 0x0c071812u: goto P_0c071812;
case 0x0c071814u: goto P_0c071814;
case 0x0c071816u: goto P_0c071816;
case 0x0c071818u: goto P_0c071818;
case 0x0c07181au: goto P_0c07181a;
case 0x0c07181cu: goto P_0c07181c;
case 0x0c07181eu: goto P_0c07181e;
case 0x0c071820u: goto P_0c071820;
case 0x0c071822u: goto P_0c071822;
case 0x0c071824u: goto P_0c071824;
case 0x0c071826u: goto P_0c071826;
case 0x0c071828u: goto P_0c071828;
case 0x0c07182au: goto P_0c07182a;
case 0x0c07182cu: goto P_0c07182c;
case 0x0c07182eu: goto P_0c07182e;
case 0x0c071830u: goto P_0c071830;
case 0x0c071832u: goto P_0c071832;
case 0x0c071834u: goto P_0c071834;
case 0x0c071836u: goto P_0c071836;
case 0x0c071838u: goto P_0c071838;
case 0x0c07183au: goto P_0c07183a;
case 0x0c07183cu: goto P_0c07183c;
case 0x0c07183eu: goto P_0c07183e;
case 0x0c071840u: goto P_0c071840;
case 0x0c071842u: goto P_0c071842;
case 0x0c071844u: goto P_0c071844;
case 0x0c071846u: goto P_0c071846;
case 0x0c071848u: goto P_0c071848;
case 0x0c07184au: goto P_0c07184a;
case 0x0c07184cu: goto P_0c07184c;
case 0x0c07184eu: goto P_0c07184e;
case 0x0c071850u: goto P_0c071850;
case 0x0c071852u: goto P_0c071852;
case 0x0c071854u: goto P_0c071854;
case 0x0c071856u: goto P_0c071856;
case 0x0c071858u: goto P_0c071858;
case 0x0c07185au: goto P_0c07185a;
case 0x0c07185cu: goto P_0c07185c;
case 0x0c07185eu: goto P_0c07185e;
case 0x0c071860u: goto P_0c071860;
case 0x0c071862u: goto P_0c071862;
case 0x0c071864u: goto P_0c071864;
case 0x0c071866u: goto P_0c071866;
case 0x0c071868u: goto P_0c071868;
case 0x0c07186au: goto P_0c07186a;
case 0x0c07186cu: goto P_0c07186c;
case 0x0c07186eu: goto P_0c07186e;
case 0x0c071870u: goto P_0c071870;
case 0x0c071878u: goto P_0c071878;
case 0x0c07187au: goto P_0c07187a;
case 0x0c07187cu: goto P_0c07187c;
case 0x0c07187eu: goto P_0c07187e;
case 0x0c071880u: goto P_0c071880;
case 0x0c071882u: goto P_0c071882;
case 0x0c071884u: goto P_0c071884;
case 0x0c071886u: goto P_0c071886;
case 0x0c071888u: goto P_0c071888;
case 0x0c07188au: goto P_0c07188a;
case 0x0c07188cu: goto P_0c07188c;
case 0x0c07188eu: goto P_0c07188e;
case 0x0c071890u: goto P_0c071890;
case 0x0c071892u: goto P_0c071892;
case 0x0c071894u: goto P_0c071894;
case 0x0c071896u: goto P_0c071896;
case 0x0c071898u: goto P_0c071898;
case 0x0c07189au: goto P_0c07189a;
case 0x0c07189cu: goto P_0c07189c;
case 0x0c07189eu: goto P_0c07189e;
case 0x0c0718a0u: goto P_0c0718a0;
case 0x0c0718a2u: goto P_0c0718a2;
case 0x0c0718a4u: goto P_0c0718a4;
case 0x0c0718a6u: goto P_0c0718a6;
case 0x0c0718a8u: goto P_0c0718a8;
case 0x0c0718aau: goto P_0c0718aa;
case 0x0c0718acu: goto P_0c0718ac;
case 0x0c0718aeu: goto P_0c0718ae;
case 0x0c0718b0u: goto P_0c0718b0;
case 0x0c0718b2u: goto P_0c0718b2;
case 0x0c0718b4u: goto P_0c0718b4;
case 0x0c0718b6u: goto P_0c0718b6;
case 0x0c0718b8u: goto P_0c0718b8;
case 0x0c0718bau: goto P_0c0718ba;
case 0x0c0718bcu: goto P_0c0718bc;
case 0x0c0718beu: goto P_0c0718be;
case 0x0c0718c0u: goto P_0c0718c0;
case 0x0c0718c2u: goto P_0c0718c2;
case 0x0c0718c4u: goto P_0c0718c4;
case 0x0c0718c6u: goto P_0c0718c6;
case 0x0c0718c8u: goto P_0c0718c8;
case 0x0c0718cau: goto P_0c0718ca;
case 0x0c0718ccu: goto P_0c0718cc;
case 0x0c0718ceu: goto P_0c0718ce;
case 0x0c0718d0u: goto P_0c0718d0;
case 0x0c0718d2u: goto P_0c0718d2;
case 0x0c0718d4u: goto P_0c0718d4;
case 0x0c0718d6u: goto P_0c0718d6;
case 0x0c0718d8u: goto P_0c0718d8;
case 0x0c0718dau: goto P_0c0718da;
case 0x0c0718dcu: goto P_0c0718dc;
case 0x0c0718deu: goto P_0c0718de;
case 0x0c0718e0u: goto P_0c0718e0;
case 0x0c0718e2u: goto P_0c0718e2;
case 0x0c0718e4u: goto P_0c0718e4;
case 0x0c0718e6u: goto P_0c0718e6;
case 0x0c0718e8u: goto P_0c0718e8;
case 0x0c0718eau: goto P_0c0718ea;
case 0x0c0718ecu: goto P_0c0718ec;
case 0x0c0718eeu: goto P_0c0718ee;
case 0x0c0718f0u: goto P_0c0718f0;
case 0x0c0718f2u: goto P_0c0718f2;
case 0x0c0718f4u: goto P_0c0718f4;
case 0x0c0718f6u: goto P_0c0718f6;
case 0x0c0718f8u: goto P_0c0718f8;
case 0x0c0718fau: goto P_0c0718fa;
case 0x0c0718fcu: goto P_0c0718fc;
case 0x0c0718feu: goto P_0c0718fe;
case 0x0c071900u: goto P_0c071900;
case 0x0c071902u: goto P_0c071902;
case 0x0c071904u: goto P_0c071904;
case 0x0c071906u: goto P_0c071906;
case 0x0c071908u: goto P_0c071908;
case 0x0c07190au: goto P_0c07190a;
case 0x0c07190cu: goto P_0c07190c;
case 0x0c07190eu: goto P_0c07190e;
case 0x0c071910u: goto P_0c071910;
case 0x0c071912u: goto P_0c071912;
case 0x0c071914u: goto P_0c071914;
case 0x0c071916u: goto P_0c071916;
case 0x0c071918u: goto P_0c071918;
case 0x0c07191au: goto P_0c07191a;
case 0x0c07191cu: goto P_0c07191c;
case 0x0c07191eu: goto P_0c07191e;
case 0x0c071920u: goto P_0c071920;
case 0x0c071a32u: goto P_0c071a32;
case 0x0c071a34u: goto P_0c071a34;
case 0x0c071a36u: goto P_0c071a36;
case 0x0c071a38u: goto P_0c071a38;
case 0x0c071a3au: goto P_0c071a3a;
case 0x0c071a3cu: goto P_0c071a3c;
case 0x0c071a3eu: goto P_0c071a3e;
case 0x0c071a40u: goto P_0c071a40;
case 0x0c071a42u: goto P_0c071a42;
case 0x0c071a44u: goto P_0c071a44;
case 0x0c071a46u: goto P_0c071a46;
case 0x0c071a48u: goto P_0c071a48;
case 0x0c071a4au: goto P_0c071a4a;
case 0x0c071a4cu: goto P_0c071a4c;
case 0x0c071a4eu: goto P_0c071a4e;
case 0x0c071a50u: goto P_0c071a50;
case 0x0c071a52u: goto P_0c071a52;
case 0x0c071a54u: goto P_0c071a54;
case 0x0c071a56u: goto P_0c071a56;
case 0x0c071a58u: goto P_0c071a58;
case 0x0c071a5au: goto P_0c071a5a;
case 0x0c071a5cu: goto P_0c071a5c;
case 0x0c071a5eu: goto P_0c071a5e;
case 0x0c071a60u: goto P_0c071a60;
case 0x0c071a62u: goto P_0c071a62;
case 0x0c071a64u: goto P_0c071a64;
case 0x0c071a66u: goto P_0c071a66;
case 0x0c071a68u: goto P_0c071a68;
case 0x0c071a6au: goto P_0c071a6a;
case 0x0c071a6cu: goto P_0c071a6c;
case 0x0c071a6eu: goto P_0c071a6e;
case 0x0c071a70u: goto P_0c071a70;
case 0x0c071a72u: goto P_0c071a72;
case 0x0c071a74u: goto P_0c071a74;
case 0x0c071a76u: goto P_0c071a76;
case 0x0c071a78u: goto P_0c071a78;
case 0x0c071a7au: goto P_0c071a7a;
case 0x0c071a7cu: goto P_0c071a7c;
case 0x0c071a7eu: goto P_0c071a7e;
case 0x0c071a80u: goto P_0c071a80;
case 0x0c071a82u: goto P_0c071a82;
case 0x0c071a84u: goto P_0c071a84;
case 0x0c071a86u: goto P_0c071a86;
case 0x0c071a88u: goto P_0c071a88;
case 0x0c071a8au: goto P_0c071a8a;
case 0x0c071a8cu: goto P_0c071a8c;
case 0x0c071a8eu: goto P_0c071a8e;
case 0x0c071a90u: goto P_0c071a90;
case 0x0c071a92u: goto P_0c071a92;
case 0x0c071a94u: goto P_0c071a94;
case 0x0c071a96u: goto P_0c071a96;
case 0x0c071a98u: goto P_0c071a98;
case 0x0c071a9au: goto P_0c071a9a;
case 0x0c071a9cu: goto P_0c071a9c;
case 0x0c071a9eu: goto P_0c071a9e;
case 0x0c071aa4u: goto P_0c071aa4;
case 0x0c071aa6u: goto P_0c071aa6;
case 0x0c071aa8u: goto P_0c071aa8;
case 0x0c071aaau: goto P_0c071aaa;
case 0x0c071aacu: goto P_0c071aac;
case 0x0c071aaeu: goto P_0c071aae;
case 0x0c071ab0u: goto P_0c071ab0;
case 0x0c071ab2u: goto P_0c071ab2;
case 0x0c071ab4u: goto P_0c071ab4;
case 0x0c071ab6u: goto P_0c071ab6;
case 0x0c071ab8u: goto P_0c071ab8;
case 0x0c071abau: goto P_0c071aba;
case 0x0c071abcu: goto P_0c071abc;
case 0x0c071abeu: goto P_0c071abe;
case 0x0c071ac0u: goto P_0c071ac0;
case 0x0c071ac2u: goto P_0c071ac2;
case 0x0c071ac4u: goto P_0c071ac4;
case 0x0c071ac6u: goto P_0c071ac6;
case 0x0c071ac8u: goto P_0c071ac8;
case 0x0c071acau: goto P_0c071aca;
case 0x0c071accu: goto P_0c071acc;
case 0x0c071aceu: goto P_0c071ace;
case 0x0c071ad0u: goto P_0c071ad0;
case 0x0c071ad2u: goto P_0c071ad2;
case 0x0c071ad4u: goto P_0c071ad4;
case 0x0c071ad6u: goto P_0c071ad6;
case 0x0c071ad8u: goto P_0c071ad8;
case 0x0c071adau: goto P_0c071ada;
case 0x0c071adcu: goto P_0c071adc;
case 0x0c071adeu: goto P_0c071ade;
case 0x0c071ae0u: goto P_0c071ae0;
case 0x0c071ae2u: goto P_0c071ae2;
case 0x0c071ae4u: goto P_0c071ae4;
case 0x0c071ae6u: goto P_0c071ae6;
case 0x0c071ae8u: goto P_0c071ae8;
case 0x0c071aeau: goto P_0c071aea;
case 0x0c071aecu: goto P_0c071aec;
case 0x0c071aeeu: goto P_0c071aee;
case 0x0c071af0u: goto P_0c071af0;
case 0x0c071af2u: goto P_0c071af2;
case 0x0c071af4u: goto P_0c071af4;
case 0x0c071af6u: goto P_0c071af6;
case 0x0c071af8u: goto P_0c071af8;
case 0x0c071afau: goto P_0c071afa;
case 0x0c071afcu: goto P_0c071afc;
case 0x0c071afeu: goto P_0c071afe;
case 0x0c071b00u: goto P_0c071b00;
case 0x0c071b02u: goto P_0c071b02;
case 0x0c071b04u: goto P_0c071b04;
case 0x0c071b06u: goto P_0c071b06;
case 0x0c071b08u: goto P_0c071b08;
case 0x0c071b0au: goto P_0c071b0a;
case 0x0c071b0cu: goto P_0c071b0c;
case 0x0c071b0eu: goto P_0c071b0e;
case 0x0c071b10u: goto P_0c071b10;
case 0x0c071b12u: goto P_0c071b12;
case 0x0c071b14u: goto P_0c071b14;
case 0x0c071b16u: goto P_0c071b16;
case 0x0c071b18u: goto P_0c071b18;
case 0x0c071b1au: goto P_0c071b1a;
case 0x0c071b1cu: goto P_0c071b1c;
case 0x0c071b1eu: goto P_0c071b1e;
case 0x0c071b20u: goto P_0c071b20;
case 0x0c071b22u: goto P_0c071b22;
case 0x0c071b24u: goto P_0c071b24;
case 0x0c071b26u: goto P_0c071b26;
case 0x0c071b28u: goto P_0c071b28;
case 0x0c071b2au: goto P_0c071b2a;
case 0x0c071b2cu: goto P_0c071b2c;
case 0x0c071b2eu: goto P_0c071b2e;
case 0x0c071b30u: goto P_0c071b30;
case 0x0c071b32u: goto P_0c071b32;
case 0x0c071b34u: goto P_0c071b34;
case 0x0c071b36u: goto P_0c071b36;
case 0x0c071b38u: goto P_0c071b38;
case 0x0c071b3au: goto P_0c071b3a;
case 0x0c071b3cu: goto P_0c071b3c;
case 0x0c071b3eu: goto P_0c071b3e;
case 0x0c071b40u: goto P_0c071b40;
case 0x0c071b42u: goto P_0c071b42;
case 0x0c071b44u: goto P_0c071b44;
case 0x0c071b46u: goto P_0c071b46;
case 0x0c071b48u: goto P_0c071b48;
case 0x0c071b4au: goto P_0c071b4a;
case 0x0c071b4cu: goto P_0c071b4c;
case 0x0c071b4eu: goto P_0c071b4e;
case 0x0c071b50u: goto P_0c071b50;
case 0x0c071b52u: goto P_0c071b52;
case 0x0c071b54u: goto P_0c071b54;
case 0x0c071b56u: goto P_0c071b56;
case 0x0c071b58u: goto P_0c071b58;
case 0x0c071b5au: goto P_0c071b5a;
case 0x0c071b5cu: goto P_0c071b5c;
case 0x0c071b5eu: goto P_0c071b5e;
case 0x0c071b60u: goto P_0c071b60;
case 0x0c071b62u: goto P_0c071b62;
case 0x0c071b64u: goto P_0c071b64;
case 0x0c071b66u: goto P_0c071b66;
case 0x0c071b68u: goto P_0c071b68;
case 0x0c071b6au: goto P_0c071b6a;
case 0x0c071b6cu: goto P_0c071b6c;
case 0x0c071b6eu: goto P_0c071b6e;
case 0x0c071b70u: goto P_0c071b70;
case 0x0c071b72u: goto P_0c071b72;
case 0x0c071b74u: goto P_0c071b74;
case 0x0c071b76u: goto P_0c071b76;
case 0x0c071b78u: goto P_0c071b78;
case 0x0c071b7au: goto P_0c071b7a;
case 0x0c071b7cu: goto P_0c071b7c;
case 0x0c071b7eu: goto P_0c071b7e;
case 0x0c071b80u: goto P_0c071b80;
case 0x0c071b82u: goto P_0c071b82;
case 0x0c071b84u: goto P_0c071b84;
case 0x0c071b86u: goto P_0c071b86;
case 0x0c071b88u: goto P_0c071b88;
case 0x0c071b8au: goto P_0c071b8a;
case 0x0c071b8cu: goto P_0c071b8c;
case 0x0c071b8eu: goto P_0c071b8e;
case 0x0c071b90u: goto P_0c071b90;
case 0x0c071b92u: goto P_0c071b92;
case 0x0c071b94u: goto P_0c071b94;
case 0x0c071b96u: goto P_0c071b96;
case 0x0c071b98u: goto P_0c071b98;
case 0x0c071b9au: goto P_0c071b9a;
case 0x0c071b9cu: goto P_0c071b9c;
case 0x0c071b9eu: goto P_0c071b9e;
case 0x0c071ba0u: goto P_0c071ba0;
case 0x0c071ba2u: goto P_0c071ba2;
case 0x0c071ba4u: goto P_0c071ba4;
case 0x0c071ba6u: goto P_0c071ba6;
case 0x0c071ba8u: goto P_0c071ba8;
case 0x0c071baau: goto P_0c071baa;
case 0x0c071bacu: goto P_0c071bac;
case 0x0c071baeu: goto P_0c071bae;
case 0x0c071bb0u: goto P_0c071bb0;
case 0x0c071bb2u: goto P_0c071bb2;
case 0x0c071bb4u: goto P_0c071bb4;
case 0x0c071bb6u: goto P_0c071bb6;
case 0x0c071bb8u: goto P_0c071bb8;
case 0x0c071bbau: goto P_0c071bba;
case 0x0c071bbcu: goto P_0c071bbc;
case 0x0c071bbeu: goto P_0c071bbe;
case 0x0c071bc0u: goto P_0c071bc0;
case 0x0c071bc2u: goto P_0c071bc2;
case 0x0c071bc4u: goto P_0c071bc4;
case 0x0c071bc6u: goto P_0c071bc6;
case 0x0c071bc8u: goto P_0c071bc8;
case 0x0c071bcau: goto P_0c071bca;
case 0x0c071bccu: goto P_0c071bcc;
case 0x0c071bceu: goto P_0c071bce;
case 0x0c071bd0u: goto P_0c071bd0;
case 0x0c071bd2u: goto P_0c071bd2;
case 0x0c071bd4u: goto P_0c071bd4;
case 0x0c071bd6u: goto P_0c071bd6;
case 0x0c071bd8u: goto P_0c071bd8;
case 0x0c071bdau: goto P_0c071bda;
case 0x0c071bdcu: goto P_0c071bdc;
case 0x0c071bdeu: goto P_0c071bde;
case 0x0c071be0u: goto P_0c071be0;
case 0x0c071be2u: goto P_0c071be2;
case 0x0c071be4u: goto P_0c071be4;
case 0x0c071be6u: goto P_0c071be6;
case 0x0c071be8u: goto P_0c071be8;
case 0x0c071beau: goto P_0c071bea;
case 0x0c071becu: goto P_0c071bec;
case 0x0c071beeu: goto P_0c071bee;
case 0x0c071bf0u: goto P_0c071bf0;
case 0x0c071bf2u: goto P_0c071bf2;
case 0x0c071bf4u: goto P_0c071bf4;
case 0x0c071bf6u: goto P_0c071bf6;
case 0x0c071bf8u: goto P_0c071bf8;
case 0x0c071bfau: goto P_0c071bfa;
case 0x0c071bfcu: goto P_0c071bfc;
case 0x0c071bfeu: goto P_0c071bfe;
case 0x0c071c00u: goto P_0c071c00;
case 0x0c071c02u: goto P_0c071c02;
case 0x0c071c04u: goto P_0c071c04;
case 0x0c071c06u: goto P_0c071c06;
case 0x0c071c08u: goto P_0c071c08;
case 0x0c071c0au: goto P_0c071c0a;
case 0x0c071c0cu: goto P_0c071c0c;
case 0x0c071c0eu: goto P_0c071c0e;
case 0x0c071c10u: goto P_0c071c10;
case 0x0c071c12u: goto P_0c071c12;
case 0x0c071c14u: goto P_0c071c14;
case 0x0c071c16u: goto P_0c071c16;
case 0x0c071c18u: goto P_0c071c18;
case 0x0c071c1au: goto P_0c071c1a;
case 0x0c071c1cu: goto P_0c071c1c;
case 0x0c071c1eu: goto P_0c071c1e;
case 0x0c071c20u: goto P_0c071c20;
case 0x0c071c22u: goto P_0c071c22;
case 0x0c071c24u: goto P_0c071c24;
case 0x0c071c26u: goto P_0c071c26;
case 0x0c071c28u: goto P_0c071c28;
case 0x0c071c2au: goto P_0c071c2a;
case 0x0c071c2cu: goto P_0c071c2c;
case 0x0c071c2eu: goto P_0c071c2e;
case 0x0c071c30u: goto P_0c071c30;
case 0x0c071c32u: goto P_0c071c32;
case 0x0c071c38u: goto P_0c071c38;
case 0x0c071c3au: goto P_0c071c3a;
case 0x0c071c3cu: goto P_0c071c3c;
case 0x0c071c3eu: goto P_0c071c3e;
case 0x0c071c40u: goto P_0c071c40;
case 0x0c071c42u: goto P_0c071c42;
case 0x0c071c44u: goto P_0c071c44;
case 0x0c071c46u: goto P_0c071c46;
case 0x0c071c48u: goto P_0c071c48;
case 0x0c071c4au: goto P_0c071c4a;
case 0x0c071c4cu: goto P_0c071c4c;
case 0x0c071c4eu: goto P_0c071c4e;
case 0x0c071c50u: goto P_0c071c50;
case 0x0c071c52u: goto P_0c071c52;
case 0x0c071c54u: goto P_0c071c54;
case 0x0c071c56u: goto P_0c071c56;
case 0x0c071c58u: goto P_0c071c58;
case 0x0c071c5au: goto P_0c071c5a;
case 0x0c071c5cu: goto P_0c071c5c;
case 0x0c071c5eu: goto P_0c071c5e;
case 0x0c071c60u: goto P_0c071c60;
case 0x0c071c62u: goto P_0c071c62;
case 0x0c071c64u: goto P_0c071c64;
case 0x0c071c66u: goto P_0c071c66;
case 0x0c071c68u: goto P_0c071c68;
case 0x0c071c6au: goto P_0c071c6a;
case 0x0c071c6cu: goto P_0c071c6c;
case 0x0c071c6eu: goto P_0c071c6e;
case 0x0c071c70u: goto P_0c071c70;
case 0x0c071c72u: goto P_0c071c72;
case 0x0c071c74u: goto P_0c071c74;
case 0x0c071c76u: goto P_0c071c76;
case 0x0c071c78u: goto P_0c071c78;
case 0x0c071c7au: goto P_0c071c7a;
case 0x0c071c7cu: goto P_0c071c7c;
case 0x0c071c7eu: goto P_0c071c7e;
case 0x0c071c80u: goto P_0c071c80;
case 0x0c071c82u: goto P_0c071c82;
case 0x0c071c84u: goto P_0c071c84;
case 0x0c071c86u: goto P_0c071c86;
case 0x0c071c88u: goto P_0c071c88;
case 0x0c071c8au: goto P_0c071c8a;
case 0x0c071c8cu: goto P_0c071c8c;
case 0x0c071c8eu: goto P_0c071c8e;
case 0x0c071c90u: goto P_0c071c90;
case 0x0c071c92u: goto P_0c071c92;
case 0x0c071c94u: goto P_0c071c94;
case 0x0c071c96u: goto P_0c071c96;
case 0x0c071c98u: goto P_0c071c98;
case 0x0c071c9au: goto P_0c071c9a;
case 0x0c071c9cu: goto P_0c071c9c;
case 0x0c071c9eu: goto P_0c071c9e;
case 0x0c071ca0u: goto P_0c071ca0;
case 0x0c071ca2u: goto P_0c071ca2;
case 0x0c071ca4u: goto P_0c071ca4;
case 0x0c071ca6u: goto P_0c071ca6;
case 0x0c071ca8u: goto P_0c071ca8;
case 0x0c071caau: goto P_0c071caa;
case 0x0c071cacu: goto P_0c071cac;
case 0x0c071caeu: goto P_0c071cae;
case 0x0c071cb0u: goto P_0c071cb0;
case 0x0c071cb2u: goto P_0c071cb2;
case 0x0c071cb4u: goto P_0c071cb4;
case 0x0c071cb6u: goto P_0c071cb6;
case 0x0c071cb8u: goto P_0c071cb8;
case 0x0c071cbau: goto P_0c071cba;
case 0x0c071cbcu: goto P_0c071cbc;
case 0x0c071cbeu: goto P_0c071cbe;
case 0x0c071cc0u: goto P_0c071cc0;
case 0x0c071cc2u: goto P_0c071cc2;
case 0x0c071cc4u: goto P_0c071cc4;
case 0x0c071cc6u: goto P_0c071cc6;
case 0x0c071cc8u: goto P_0c071cc8;
case 0x0c071ccau: goto P_0c071cca;
case 0x0c071cccu: goto P_0c071ccc;
case 0x0c071cceu: goto P_0c071cce;
case 0x0c071cd0u: goto P_0c071cd0;
case 0x0c071cd2u: goto P_0c071cd2;
case 0x0c071cd4u: goto P_0c071cd4;
case 0x0c071cd6u: goto P_0c071cd6;
case 0x0c071cd8u: goto P_0c071cd8;
case 0x0c071cdau: goto P_0c071cda;
case 0x0c071cdcu: goto P_0c071cdc;
case 0x0c071cdeu: goto P_0c071cde;
case 0x0c071ce0u: goto P_0c071ce0;
case 0x0c071ce2u: goto P_0c071ce2;
case 0x0c071ce4u: goto P_0c071ce4;
case 0x0c071ce6u: goto P_0c071ce6;
case 0x0c071ce8u: goto P_0c071ce8;
case 0x0c071ceau: goto P_0c071cea;
case 0x0c071cecu: goto P_0c071cec;
case 0x0c071ceeu: goto P_0c071cee;
case 0x0c071cf0u: goto P_0c071cf0;
case 0x0c071cf2u: goto P_0c071cf2;
case 0x0c071cf4u: goto P_0c071cf4;
case 0x0c071cf6u: goto P_0c071cf6;
case 0x0c071cf8u: goto P_0c071cf8;
case 0x0c071cfau: goto P_0c071cfa;
case 0x0c071cfcu: goto P_0c071cfc;
case 0x0c071cfeu: goto P_0c071cfe;
case 0x0c071d00u: goto P_0c071d00;
case 0x0c071d02u: goto P_0c071d02;
case 0x0c071d04u: goto P_0c071d04;
case 0x0c071d06u: goto P_0c071d06;
case 0x0c071d08u: goto P_0c071d08;
case 0x0c071d0au: goto P_0c071d0a;
case 0x0c071d0cu: goto P_0c071d0c;
case 0x0c071d0eu: goto P_0c071d0e;
case 0x0c071d10u: goto P_0c071d10;
case 0x0c071d12u: goto P_0c071d12;
case 0x0c071d14u: goto P_0c071d14;
case 0x0c071d16u: goto P_0c071d16;
case 0x0c071d18u: goto P_0c071d18;
case 0x0c071d1au: goto P_0c071d1a;
case 0x0c071d1cu: goto P_0c071d1c;
case 0x0c071d1eu: goto P_0c071d1e;
case 0x0c071d20u: goto P_0c071d20;
case 0x0c071d22u: goto P_0c071d22;
case 0x0c071d24u: goto P_0c071d24;
case 0x0c071d26u: goto P_0c071d26;
case 0x0c071d28u: goto P_0c071d28;
case 0x0c071d2au: goto P_0c071d2a;
case 0x0c071d2cu: goto P_0c071d2c;
case 0x0c071d2eu: goto P_0c071d2e;
case 0x0c071d30u: goto P_0c071d30;
case 0x0c071d32u: goto P_0c071d32;
case 0x0c071d34u: goto P_0c071d34;
case 0x0c071d36u: goto P_0c071d36;
case 0x0c071d38u: goto P_0c071d38;
case 0x0c071d3au: goto P_0c071d3a;
case 0x0c071d3cu: goto P_0c071d3c;
case 0x0c071d3eu: goto P_0c071d3e;
case 0x0c071d40u: goto P_0c071d40;
case 0x0c071d42u: goto P_0c071d42;
case 0x0c071d44u: goto P_0c071d44;
case 0x0c071d46u: goto P_0c071d46;
case 0x0c071d48u: goto P_0c071d48;
case 0x0c071d4au: goto P_0c071d4a;
case 0x0c071d4cu: goto P_0c071d4c;
case 0x0c071d4eu: goto P_0c071d4e;
case 0x0c071d50u: goto P_0c071d50;
case 0x0c071d52u: goto P_0c071d52;
case 0x0c071d54u: goto P_0c071d54;
case 0x0c071d56u: goto P_0c071d56;
case 0x0c071d58u: goto P_0c071d58;
case 0x0c071d5au: goto P_0c071d5a;
case 0x0c071d5cu: goto P_0c071d5c;
case 0x0c071d5eu: goto P_0c071d5e;
case 0x0c071d60u: goto P_0c071d60;
case 0x0c071d62u: goto P_0c071d62;
case 0x0c071d64u: goto P_0c071d64;
case 0x0c071d66u: goto P_0c071d66;
case 0x0c071d68u: goto P_0c071d68;
case 0x0c071d6au: goto P_0c071d6a;
case 0x0c071d6cu: goto P_0c071d6c;
case 0x0c071d6eu: goto P_0c071d6e;
case 0x0c071d70u: goto P_0c071d70;
case 0x0c071d72u: goto P_0c071d72;
case 0x0c071d74u: goto P_0c071d74;
case 0x0c071d76u: goto P_0c071d76;
case 0x0c071d78u: goto P_0c071d78;
case 0x0c071d7au: goto P_0c071d7a;
case 0x0c071d7cu: goto P_0c071d7c;
case 0x0c071d7eu: goto P_0c071d7e;
case 0x0c071d80u: goto P_0c071d80;
case 0x0c071d82u: goto P_0c071d82;
case 0x0c071d84u: goto P_0c071d84;
case 0x0c071d86u: goto P_0c071d86;
case 0x0c071d88u: goto P_0c071d88;
case 0x0c071d8au: goto P_0c071d8a;
case 0x0c071d8cu: goto P_0c071d8c;
case 0x0c071d8eu: goto P_0c071d8e;
case 0x0c071d90u: goto P_0c071d90;
case 0x0c071d92u: goto P_0c071d92;
case 0x0c071d94u: goto P_0c071d94;
case 0x0c071d96u: goto P_0c071d96;
case 0x0c071d98u: goto P_0c071d98;
case 0x0c071d9au: goto P_0c071d9a;
case 0x0c071d9cu: goto P_0c071d9c;
case 0x0c071d9eu: goto P_0c071d9e;
case 0x0c071da0u: goto P_0c071da0;
case 0x0c071da2u: goto P_0c071da2;
case 0x0c071da4u: goto P_0c071da4;
case 0x0c071da6u: goto P_0c071da6;
case 0x0c071dacu: goto P_0c071dac;
case 0x0c071daeu: goto P_0c071dae;
case 0x0c071db0u: goto P_0c071db0;
case 0x0c071db2u: goto P_0c071db2;
case 0x0c071db4u: goto P_0c071db4;
case 0x0c071db6u: goto P_0c071db6;
case 0x0c071db8u: goto P_0c071db8;
case 0x0c071dbau: goto P_0c071dba;
case 0x0c071dbcu: goto P_0c071dbc;
case 0x0c071dbeu: goto P_0c071dbe;
case 0x0c071dc0u: goto P_0c071dc0;
case 0x0c071dc2u: goto P_0c071dc2;
case 0x0c071dc4u: goto P_0c071dc4;
case 0x0c071dc6u: goto P_0c071dc6;
case 0x0c071dc8u: goto P_0c071dc8;
case 0x0c071dcau: goto P_0c071dca;
case 0x0c071dccu: goto P_0c071dcc;
case 0x0c071dceu: goto P_0c071dce;
case 0x0c071dd0u: goto P_0c071dd0;
case 0x0c071dd2u: goto P_0c071dd2;
case 0x0c071dd4u: goto P_0c071dd4;
case 0x0c071dd6u: goto P_0c071dd6;
case 0x0c071dd8u: goto P_0c071dd8;
case 0x0c071ddau: goto P_0c071dda;
case 0x0c071ddcu: goto P_0c071ddc;
case 0x0c071ddeu: goto P_0c071dde;
case 0x0c071de0u: goto P_0c071de0;
case 0x0c071de2u: goto P_0c071de2;
case 0x0c071de4u: goto P_0c071de4;
case 0x0c071de6u: goto P_0c071de6;
case 0x0c071de8u: goto P_0c071de8;
case 0x0c071deau: goto P_0c071dea;
case 0x0c071decu: goto P_0c071dec;
case 0x0c071deeu: goto P_0c071dee;
case 0x0c071df0u: goto P_0c071df0;
case 0x0c071df2u: goto P_0c071df2;
case 0x0c071df4u: goto P_0c071df4;
case 0x0c071df6u: goto P_0c071df6;
case 0x0c071df8u: goto P_0c071df8;
case 0x0c071dfau: goto P_0c071dfa;
case 0x0c071dfcu: goto P_0c071dfc;
case 0x0c071dfeu: goto P_0c071dfe;
case 0x0c071e00u: goto P_0c071e00;
case 0x0c071e02u: goto P_0c071e02;
case 0x0c071e04u: goto P_0c071e04;
case 0x0c071e06u: goto P_0c071e06;
case 0x0c071e08u: goto P_0c071e08;
case 0x0c071e0au: goto P_0c071e0a;
case 0x0c071e0cu: goto P_0c071e0c;
case 0x0c071e0eu: goto P_0c071e0e;
case 0x0c071e10u: goto P_0c071e10;
case 0x0c071e12u: goto P_0c071e12;
case 0x0c071e14u: goto P_0c071e14;
case 0x0c071e16u: goto P_0c071e16;
case 0x0c071e18u: goto P_0c071e18;
case 0x0c071e1au: goto P_0c071e1a;
case 0x0c071e1cu: goto P_0c071e1c;
case 0x0c071e1eu: goto P_0c071e1e;
case 0x0c071e20u: goto P_0c071e20;
case 0x0c071e22u: goto P_0c071e22;
case 0x0c071e24u: goto P_0c071e24;
case 0x0c071e26u: goto P_0c071e26;
case 0x0c071e28u: goto P_0c071e28;
case 0x0c071e2au: goto P_0c071e2a;
case 0x0c071e2cu: goto P_0c071e2c;
case 0x0c071e2eu: goto P_0c071e2e;
case 0x0c071e30u: goto P_0c071e30;
case 0x0c071e32u: goto P_0c071e32;
case 0x0c071e34u: goto P_0c071e34;
case 0x0c071e36u: goto P_0c071e36;
case 0x0c071e38u: goto P_0c071e38;
case 0x0c071e3au: goto P_0c071e3a;
case 0x0c071e3cu: goto P_0c071e3c;
case 0x0c071e3eu: goto P_0c071e3e;
case 0x0c071e40u: goto P_0c071e40;
case 0x0c071e42u: goto P_0c071e42;
case 0x0c071e44u: goto P_0c071e44;
case 0x0c071e46u: goto P_0c071e46;
case 0x0c071e48u: goto P_0c071e48;
case 0x0c071e4au: goto P_0c071e4a;
case 0x0c071e4cu: goto P_0c071e4c;
case 0x0c071e4eu: goto P_0c071e4e;
case 0x0c071e50u: goto P_0c071e50;
case 0x0c071e52u: goto P_0c071e52;
case 0x0c071e54u: goto P_0c071e54;
case 0x0c071e56u: goto P_0c071e56;
case 0x0c071e58u: goto P_0c071e58;
case 0x0c071e5au: goto P_0c071e5a;
case 0x0c071e5cu: goto P_0c071e5c;
case 0x0c071e64u: goto P_0c071e64;
case 0x0c071e66u: goto P_0c071e66;
case 0x0c071e68u: goto P_0c071e68;
case 0x0c071e6au: goto P_0c071e6a;
case 0x0c071e6cu: goto P_0c071e6c;
case 0x0c071e6eu: goto P_0c071e6e;
case 0x0c071e70u: goto P_0c071e70;
case 0x0c071e72u: goto P_0c071e72;
case 0x0c071e74u: goto P_0c071e74;
case 0x0c071e76u: goto P_0c071e76;
case 0x0c071e78u: goto P_0c071e78;
case 0x0c071e7au: goto P_0c071e7a;
case 0x0c071e7cu: goto P_0c071e7c;
case 0x0c071e7eu: goto P_0c071e7e;
case 0x0c071e80u: goto P_0c071e80;
case 0x0c071e82u: goto P_0c071e82;
case 0x0c071e84u: goto P_0c071e84;
case 0x0c071e86u: goto P_0c071e86;
case 0x0c071e88u: goto P_0c071e88;
case 0x0c071e8au: goto P_0c071e8a;
case 0x0c071e8cu: goto P_0c071e8c;
case 0x0c071e8eu: goto P_0c071e8e;
case 0x0c071e90u: goto P_0c071e90;
case 0x0c071e92u: goto P_0c071e92;
case 0x0c071e94u: goto P_0c071e94;
case 0x0c071e96u: goto P_0c071e96;
case 0x0c071e98u: goto P_0c071e98;
case 0x0c071e9au: goto P_0c071e9a;
case 0x0c071e9cu: goto P_0c071e9c;
case 0x0c071e9eu: goto P_0c071e9e;
case 0x0c071ea0u: goto P_0c071ea0;
case 0x0c071ea2u: goto P_0c071ea2;
case 0x0c071ea4u: goto P_0c071ea4;
case 0x0c071ea6u: goto P_0c071ea6;
case 0x0c071ea8u: goto P_0c071ea8;
case 0x0c071eaau: goto P_0c071eaa;
case 0x0c071eacu: goto P_0c071eac;
case 0x0c071eaeu: goto P_0c071eae;
case 0x0c071eb0u: goto P_0c071eb0;
case 0x0c071eb2u: goto P_0c071eb2;
case 0x0c071eb4u: goto P_0c071eb4;
case 0x0c071eb6u: goto P_0c071eb6;
case 0x0c071eb8u: goto P_0c071eb8;
case 0x0c071ebau: goto P_0c071eba;
case 0x0c071ebcu: goto P_0c071ebc;
case 0x0c071ebeu: goto P_0c071ebe;
case 0x0c071ec0u: goto P_0c071ec0;
case 0x0c071ec2u: goto P_0c071ec2;
case 0x0c071ec4u: goto P_0c071ec4;
case 0x0c071ec6u: goto P_0c071ec6;
case 0x0c071ec8u: goto P_0c071ec8;
case 0x0c071ecau: goto P_0c071eca;
case 0x0c071eccu: goto P_0c071ecc;
case 0x0c071eceu: goto P_0c071ece;
case 0x0c071ed0u: goto P_0c071ed0;
case 0x0c071ed2u: goto P_0c071ed2;
case 0x0c071ed4u: goto P_0c071ed4;
case 0x0c071ed6u: goto P_0c071ed6;
case 0x0c071ed8u: goto P_0c071ed8;
case 0x0c071edau: goto P_0c071eda;
case 0x0c071edcu: goto P_0c071edc;
case 0x0c071edeu: goto P_0c071ede;
case 0x0c071ee0u: goto P_0c071ee0;
case 0x0c071ee2u: goto P_0c071ee2;
case 0x0c071ee4u: goto P_0c071ee4;
case 0x0c071ee6u: goto P_0c071ee6;
case 0x0c071ee8u: goto P_0c071ee8;
case 0x0c071eeau: goto P_0c071eea;
case 0x0c071eecu: goto P_0c071eec;
case 0x0c071eeeu: goto P_0c071eee;
case 0x0c071ef0u: goto P_0c071ef0;
case 0x0c071ef2u: goto P_0c071ef2;
case 0x0c071ef4u: goto P_0c071ef4;
case 0x0c071ef6u: goto P_0c071ef6;
case 0x0c071ef8u: goto P_0c071ef8;
case 0x0c071efau: goto P_0c071efa;
case 0x0c071efcu: goto P_0c071efc;
case 0x0c071efeu: goto P_0c071efe;
case 0x0c071f00u: goto P_0c071f00;
case 0x0c071f02u: goto P_0c071f02;
case 0x0c071f04u: goto P_0c071f04;
case 0x0c071f06u: goto P_0c071f06;
case 0x0c071f08u: goto P_0c071f08;
case 0x0c071f0au: goto P_0c071f0a;
case 0x0c071f0cu: goto P_0c071f0c;
case 0x0c071f0eu: goto P_0c071f0e;
case 0x0c071f10u: goto P_0c071f10;
case 0x0c071f12u: goto P_0c071f12;
case 0x0c071f14u: goto P_0c071f14;
case 0x0c071f16u: goto P_0c071f16;
case 0x0c071f18u: goto P_0c071f18;
case 0x0c071f1au: goto P_0c071f1a;
case 0x0c071f1cu: goto P_0c071f1c;
case 0x0c071f1eu: goto P_0c071f1e;
case 0x0c071f20u: goto P_0c071f20;
case 0x0c071f22u: goto P_0c071f22;
case 0x0c071f24u: goto P_0c071f24;
case 0x0c071f26u: goto P_0c071f26;
case 0x0c071f28u: goto P_0c071f28;
case 0x0c071f2au: goto P_0c071f2a;
case 0x0c071f2cu: goto P_0c071f2c;
case 0x0c071f2eu: goto P_0c071f2e;
case 0x0c071f30u: goto P_0c071f30;
case 0x0c071f32u: goto P_0c071f32;
case 0x0c071f34u: goto P_0c071f34;
case 0x0c071f36u: goto P_0c071f36;
case 0x0c071f38u: goto P_0c071f38;
case 0x0c071f3au: goto P_0c071f3a;
case 0x0c071f3cu: goto P_0c071f3c;
case 0x0c071f3eu: goto P_0c071f3e;
case 0x0c071f40u: goto P_0c071f40;
case 0x0c071f42u: goto P_0c071f42;
case 0x0c071f44u: goto P_0c071f44;
case 0x0c071f46u: goto P_0c071f46;
case 0x0c071f48u: goto P_0c071f48;
case 0x0c071f4au: goto P_0c071f4a;
case 0x0c071f4cu: goto P_0c071f4c;
case 0x0c071f4eu: goto P_0c071f4e;
case 0x0c071f50u: goto P_0c071f50;
case 0x0c071f52u: goto P_0c071f52;
case 0x0c071f54u: goto P_0c071f54;
case 0x0c071f56u: goto P_0c071f56;
case 0x0c071f58u: goto P_0c071f58;
case 0x0c071f5au: goto P_0c071f5a;
case 0x0c071f5cu: goto P_0c071f5c;
case 0x0c071f5eu: goto P_0c071f5e;
case 0x0c071f60u: goto P_0c071f60;
case 0x0c071f62u: goto P_0c071f62;
case 0x0c071f64u: goto P_0c071f64;
case 0x0c071f66u: goto P_0c071f66;
case 0x0c071f68u: goto P_0c071f68;
case 0x0c071f6au: goto P_0c071f6a;
case 0x0c071f6cu: goto P_0c071f6c;
case 0x0c071f6eu: goto P_0c071f6e;
case 0x0c071f70u: goto P_0c071f70;
case 0x0c071f72u: goto P_0c071f72;
case 0x0c071f74u: goto P_0c071f74;
case 0x0c071f76u: goto P_0c071f76;
case 0x0c071f78u: goto P_0c071f78;
case 0x0c071f7au: goto P_0c071f7a;
case 0x0c071f7cu: goto P_0c071f7c;
case 0x0c071f7eu: goto P_0c071f7e;
case 0x0c071f80u: goto P_0c071f80;
case 0x0c071f82u: goto P_0c071f82;
case 0x0c071f84u: goto P_0c071f84;
case 0x0c071f86u: goto P_0c071f86;
case 0x0c071f88u: goto P_0c071f88;
case 0x0c071f8au: goto P_0c071f8a;
case 0x0c071f8cu: goto P_0c071f8c;
case 0x0c071f8eu: goto P_0c071f8e;
case 0x0c071f90u: goto P_0c071f90;
case 0x0c071f92u: goto P_0c071f92;
case 0x0c071f94u: goto P_0c071f94;
case 0x0c071f96u: goto P_0c071f96;
case 0x0c071f98u: goto P_0c071f98;
case 0x0c071f9au: goto P_0c071f9a;
case 0x0c071f9cu: goto P_0c071f9c;
case 0x0c071f9eu: goto P_0c071f9e;
case 0x0c071fa0u: goto P_0c071fa0;
case 0x0c071fa2u: goto P_0c071fa2;
case 0x0c071fa4u: goto P_0c071fa4;
case 0x0c071fa6u: goto P_0c071fa6;
case 0x0c071fa8u: goto P_0c071fa8;
case 0x0c071faau: goto P_0c071faa;
case 0x0c071facu: goto P_0c071fac;
case 0x0c071faeu: goto P_0c071fae;
case 0x0c071fb0u: goto P_0c071fb0;
case 0x0c071fb2u: goto P_0c071fb2;
case 0x0c071fb4u: goto P_0c071fb4;
case 0x0c071fb6u: goto P_0c071fb6;
case 0x0c071fb8u: goto P_0c071fb8;
case 0x0c071fbau: goto P_0c071fba;
case 0x0c071fbcu: goto P_0c071fbc;
case 0x0c071fbeu: goto P_0c071fbe;
case 0x0c071fc0u: goto P_0c071fc0;
case 0x0c071fc2u: goto P_0c071fc2;
case 0x0c071fc4u: goto P_0c071fc4;
case 0x0c071fc6u: goto P_0c071fc6;
case 0x0c071fc8u: goto P_0c071fc8;
case 0x0c071fcau: goto P_0c071fca;
case 0x0c071fccu: goto P_0c071fcc;
case 0x0c071fd4u: goto P_0c071fd4;
case 0x0c071fd6u: goto P_0c071fd6;
case 0x0c071fd8u: goto P_0c071fd8;
case 0x0c071fdau: goto P_0c071fda;
case 0x0c071fdcu: goto P_0c071fdc;
case 0x0c071fdeu: goto P_0c071fde;
case 0x0c071fe0u: goto P_0c071fe0;
case 0x0c071fe2u: goto P_0c071fe2;
case 0x0c071fe4u: goto P_0c071fe4;
case 0x0c071fe6u: goto P_0c071fe6;
case 0x0c071fe8u: goto P_0c071fe8;
case 0x0c071feau: goto P_0c071fea;
case 0x0c071fecu: goto P_0c071fec;
case 0x0c071feeu: goto P_0c071fee;
case 0x0c071ff0u: goto P_0c071ff0;
case 0x0c071ff2u: goto P_0c071ff2;
case 0x0c071ff4u: goto P_0c071ff4;
case 0x0c071ff6u: goto P_0c071ff6;
case 0x0c071ff8u: goto P_0c071ff8;
case 0x0c071ffau: goto P_0c071ffa;
case 0x0c071ffcu: goto P_0c071ffc;
case 0x0c071ffeu: goto P_0c071ffe;
case 0x0c072000u: goto P_0c072000;
case 0x0c072002u: goto P_0c072002;
case 0x0c072004u: goto P_0c072004;
case 0x0c072006u: goto P_0c072006;
case 0x0c072008u: goto P_0c072008;
case 0x0c07200au: goto P_0c07200a;
case 0x0c07200cu: goto P_0c07200c;
case 0x0c07200eu: goto P_0c07200e;
case 0x0c072010u: goto P_0c072010;
case 0x0c072012u: goto P_0c072012;
case 0x0c072014u: goto P_0c072014;
case 0x0c072016u: goto P_0c072016;
case 0x0c072018u: goto P_0c072018;
case 0x0c07201au: goto P_0c07201a;
case 0x0c07201cu: goto P_0c07201c;
case 0x0c07201eu: goto P_0c07201e;
case 0x0c072020u: goto P_0c072020;
case 0x0c072022u: goto P_0c072022;
case 0x0c072024u: goto P_0c072024;
case 0x0c072026u: goto P_0c072026;
case 0x0c072028u: goto P_0c072028;
case 0x0c07202au: goto P_0c07202a;
case 0x0c07202cu: goto P_0c07202c;
case 0x0c07202eu: goto P_0c07202e;
case 0x0c072030u: goto P_0c072030;
case 0x0c072032u: goto P_0c072032;
case 0x0c072034u: goto P_0c072034;
case 0x0c072036u: goto P_0c072036;
case 0x0c072038u: goto P_0c072038;
case 0x0c07203au: goto P_0c07203a;
case 0x0c07203cu: goto P_0c07203c;
case 0x0c07203eu: goto P_0c07203e;
case 0x0c072040u: goto P_0c072040;
case 0x0c072042u: goto P_0c072042;
case 0x0c072044u: goto P_0c072044;
case 0x0c072046u: goto P_0c072046;
case 0x0c072048u: goto P_0c072048;
case 0x0c07204au: goto P_0c07204a;
case 0x0c07204cu: goto P_0c07204c;
case 0x0c07204eu: goto P_0c07204e;
case 0x0c072050u: goto P_0c072050;
case 0x0c072052u: goto P_0c072052;
case 0x0c072054u: goto P_0c072054;
case 0x0c072056u: goto P_0c072056;
case 0x0c072058u: goto P_0c072058;
case 0x0c07205au: goto P_0c07205a;
case 0x0c07205cu: goto P_0c07205c;
case 0x0c07205eu: goto P_0c07205e;
case 0x0c072060u: goto P_0c072060;
case 0x0c072062u: goto P_0c072062;
case 0x0c072064u: goto P_0c072064;
case 0x0c072066u: goto P_0c072066;
case 0x0c072068u: goto P_0c072068;
case 0x0c07206au: goto P_0c07206a;
case 0x0c07206cu: goto P_0c07206c;
case 0x0c07206eu: goto P_0c07206e;
case 0x0c072070u: goto P_0c072070;
case 0x0c072072u: goto P_0c072072;
case 0x0c072074u: goto P_0c072074;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03550c: /* original 2fe6, guest PC 0x0c03550c */
if(!s->budget--) { s->failed_pc=0x0c03550cu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c03550e;
P_0c03550e: /* original 6e43, guest PC 0x0c03550e */
if(!s->budget--) { s->failed_pc=0x0c03550eu; return 0; }
r[14]=r[4];
goto P_0c035510;
P_0c035510: /* original 2fd6, guest PC 0x0c035510 */
if(!s->budget--) { s->failed_pc=0x0c035510u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c035512;
P_0c035512: /* original 2fc6, guest PC 0x0c035512 */
if(!s->budget--) { s->failed_pc=0x0c035512u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c035514;
P_0c035514: /* original 2fb6, guest PC 0x0c035514 */
if(!s->budget--) { s->failed_pc=0x0c035514u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c035516;
P_0c035516: /* original 2fa6, guest PC 0x0c035516 */
if(!s->budget--) { s->failed_pc=0x0c035516u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c035518;
P_0c035518: /* original 4f22, guest PC 0x0c035518 */
if(!s->budget--) { s->failed_pc=0x0c035518u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03551a;
P_0c03551a: /* original d333, guest PC 0x0c03551a */
if(!s->budget--) { s->failed_pc=0x0c03551au; return 0; }
r[3]=read(ram,0x0c0355e8u,4);
goto P_0c03551c;
P_0c03551c: /* original 6d32, guest PC 0x0c03551c */
if(!s->budget--) { s->failed_pc=0x0c03551cu; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c03551e;
P_0c03551e: /* original 9c61, guest PC 0x0c03551e */
if(!s->budget--) { s->failed_pc=0x0c03551eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0355e4u,2);
goto P_0c035520;
P_0c035520: /* original da32, guest PC 0x0c035520 */
if(!s->budget--) { s->failed_pc=0x0c035520u; return 0; }
r[10]=read(ram,0x0c0355ecu,4);
goto P_0c035522;
P_0c035522: /* original 5be6, guest PC 0x0c035522 */
if(!s->budget--) { s->failed_pc=0x0c035522u; return 0; }
r[11]=read(ram,r[14]+24,4);
goto P_0c035524;
P_0c035524: /* original 60e2, guest PC 0x0c035524 */
if(!s->budget--) { s->failed_pc=0x0c035524u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c035526;
P_0c035526: /* original 5009, guest PC 0x0c035526 */
if(!s->budget--) { s->failed_pc=0x0c035526u; return 0; }
r[0]=read(ram,r[0]+36,4);
goto P_0c035528;
P_0c035528: /* original 8802, guest PC 0x0c035528 */
if(!s->budget--) { s->failed_pc=0x0c035528u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c03552a;
P_0c03552a: /* original 8901, guest PC 0x0c03552a */
if(!s->budget--) { s->failed_pc=0x0c03552au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035530; }
goto P_0c03552c;
P_0c03552c: /* original 4a0b, guest PC 0x0c03552c */
if(!s->budget--) { s->failed_pc=0x0c03552cu; return 0; }
target=r[10];
r[16]=0x0c035530u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c035530u) { target=s->pc; goto dispatch; }
goto P_0c035530;
P_0c03552e: /* original 0009, guest PC 0x0c03552e */
if(!s->budget--) { s->failed_pc=0x0c03552eu; return 0; }
goto P_0c035530;
P_0c035530: /* original b276, guest PC 0x0c035530 */
if(!s->budget--) { s->failed_pc=0x0c035530u; return 0; }
target=0x0c035a20u; r[16]=0x0c035534u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c035534u) { target=s->pc; goto dispatch; }
goto P_0c035534;
P_0c035532: /* original 64e3, guest PC 0x0c035532 */
if(!s->budget--) { s->failed_pc=0x0c035532u; return 0; }
r[4]=r[14];
goto P_0c035534;
P_0c035534: /* original 8800, guest PC 0x0c035534 */
if(!s->budget--) { s->failed_pc=0x0c035534u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c035536;
P_0c035536: /* original 8d0e, guest PC 0x0c035536 */
if(!s->budget--) { s->failed_pc=0x0c035536u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c035556; }
goto P_0c03553a;
P_0c035538: /* original 6403, guest PC 0x0c035538 */
if(!s->budget--) { s->failed_pc=0x0c035538u; return 0; }
r[4]=r[0];
goto P_0c03553a;
P_0c03553a: /* original 8801, guest PC 0x0c03553a */
if(!s->budget--) { s->failed_pc=0x0c03553au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c03553c;
P_0c03553c: /* original 890d, guest PC 0x0c03553c */
if(!s->budget--) { s->failed_pc=0x0c03553cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555a; }
goto P_0c03553e;
P_0c03553e: /* original 8802, guest PC 0x0c03553e */
if(!s->budget--) { s->failed_pc=0x0c03553eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c035540;
P_0c035540: /* original 890d, guest PC 0x0c035540 */
if(!s->budget--) { s->failed_pc=0x0c035540u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555e; }
goto P_0c035542;
P_0c035542: /* original 8803, guest PC 0x0c035542 */
if(!s->budget--) { s->failed_pc=0x0c035542u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c035544;
P_0c035544: /* original 890b, guest PC 0x0c035544 */
if(!s->budget--) { s->failed_pc=0x0c035544u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555e; }
goto P_0c035546;
P_0c035546: /* original 8804, guest PC 0x0c035546 */
if(!s->budget--) { s->failed_pc=0x0c035546u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c035548;
P_0c035548: /* original 8909, guest PC 0x0c035548 */
if(!s->budget--) { s->failed_pc=0x0c035548u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555e; }
goto P_0c03554a;
P_0c03554a: /* original 8805, guest PC 0x0c03554a */
if(!s->budget--) { s->failed_pc=0x0c03554au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c03554c;
P_0c03554c: /* original 890d, guest PC 0x0c03554c */
if(!s->budget--) { s->failed_pc=0x0c03554cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03556a; }
goto P_0c03554e;
P_0c03554e: /* original 8806, guest PC 0x0c03554e */
if(!s->budget--) { s->failed_pc=0x0c03554eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c035550;
P_0c035550: /* original 890b, guest PC 0x0c035550 */
if(!s->budget--) { s->failed_pc=0x0c035550u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03556a; }
goto P_0c035552;
P_0c035552: /* original a00d, guest PC 0x0c035552 */
if(!s->budget--) { s->failed_pc=0x0c035552u; return 0; }
goto P_0c035570;
P_0c035554: /* original 0009, guest PC 0x0c035554 */
if(!s->budget--) { s->failed_pc=0x0c035554u; return 0; }
goto P_0c035556;
P_0c035556: /* original a013, guest PC 0x0c035556 */
if(!s->budget--) { s->failed_pc=0x0c035556u; return 0; }
r[0]=0xffffffe0u;
goto P_0c035580;
P_0c035558: /* original e0e0, guest PC 0x0c035558 */
if(!s->budget--) { s->failed_pc=0x0c035558u; return 0; }
r[0]=0xffffffe0u;
goto P_0c03555a;
P_0c03555a: /* original a011, guest PC 0x0c03555a */
if(!s->budget--) { s->failed_pc=0x0c03555au; return 0; }
r[0]=0x00000000u;
goto P_0c035580;
P_0c03555c: /* original e000, guest PC 0x0c03555c */
if(!s->budget--) { s->failed_pc=0x0c03555cu; return 0; }
r[0]=0x00000000u;
goto P_0c03555e;
P_0c03555e: /* original 53e6, guest PC 0x0c03555e */
if(!s->budget--) { s->failed_pc=0x0c03555eu; return 0; }
r[3]=read(ram,r[14]+24,4);
goto P_0c035560;
P_0c035560: /* original 3b30, guest PC 0x0c035560 */
if(!s->budget--) { s->failed_pc=0x0c035560u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[3])!=0);
goto P_0c035562;
P_0c035562: /* original 8907, guest PC 0x0c035562 */
if(!s->budget--) { s->failed_pc=0x0c035562u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035574; }
goto P_0c035564;
P_0c035564: /* original d120, guest PC 0x0c035564 */
if(!s->budget--) { s->failed_pc=0x0c035564u; return 0; }
r[1]=read(ram,0x0c0355e8u,4);
goto P_0c035566;
P_0c035566: /* original a005, guest PC 0x0c035566 */
if(!s->budget--) { s->failed_pc=0x0c035566u; return 0; }
tmp=read(ram,r[1],4);
r[13]=tmp;
goto P_0c035574;
P_0c035568: /* original 6d12, guest PC 0x0c035568 */
if(!s->budget--) { s->failed_pc=0x0c035568u; return 0; }
tmp=read(ram,r[1],4);
r[13]=tmp;
goto P_0c03556a;
P_0c03556a: /* original e04e, guest PC 0x0c03556a */
if(!s->budget--) { s->failed_pc=0x0c03556au; return 0; }
r[0]=0x0000004eu;
goto P_0c03556c;
P_0c03556c: /* original a008, guest PC 0x0c03556c */
if(!s->budget--) { s->failed_pc=0x0c03556cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c035580;
P_0c03556e: /* original 00ed, guest PC 0x0c03556e */
if(!s->budget--) { s->failed_pc=0x0c03556eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c035570;
P_0c035570: /* original a006, guest PC 0x0c035570 */
if(!s->budget--) { s->failed_pc=0x0c035570u; return 0; }
r[0]=0xffffffe7u;
goto P_0c035580;
P_0c035572: /* original e0e7, guest PC 0x0c035572 */
if(!s->budget--) { s->failed_pc=0x0c035572u; return 0; }
r[0]=0xffffffe7u;
goto P_0c035574;
P_0c035574: /* original d31c, guest PC 0x0c035574 */
if(!s->budget--) { s->failed_pc=0x0c035574u; return 0; }
r[3]=read(ram,0x0c0355e8u,4);
goto P_0c035576;
P_0c035576: /* original 6432, guest PC 0x0c035576 */
if(!s->budget--) { s->failed_pc=0x0c035576u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c035578;
P_0c035578: /* original 34d8, guest PC 0x0c035578 */
if(!s->budget--) { s->failed_pc=0x0c035578u; return 0; }
r[4]-=r[13];
goto P_0c03557a;
P_0c03557a: /* original 34c6, guest PC 0x0c03557a */
if(!s->budget--) { s->failed_pc=0x0c03557au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[12])!=0);
goto P_0c03557c;
P_0c03557c: /* original 8bd2, guest PC 0x0c03557c */
if(!s->budget--) { s->failed_pc=0x0c03557cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c035524; }
goto P_0c03557e;
P_0c03557e: /* original e0eb, guest PC 0x0c03557e */
if(!s->budget--) { s->failed_pc=0x0c03557eu; return 0; }
r[0]=0xffffffebu;
goto P_0c035580;
P_0c035580: /* original 4f26, guest PC 0x0c035580 */
if(!s->budget--) { s->failed_pc=0x0c035580u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c035582;
P_0c035582: /* original 6af6, guest PC 0x0c035582 */
if(!s->budget--) { s->failed_pc=0x0c035582u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c035584;
P_0c035584: /* original 6bf6, guest PC 0x0c035584 */
if(!s->budget--) { s->failed_pc=0x0c035584u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c035586;
P_0c035586: /* original 6cf6, guest PC 0x0c035586 */
if(!s->budget--) { s->failed_pc=0x0c035586u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c035588;
P_0c035588: /* original 6df6, guest PC 0x0c035588 */
if(!s->budget--) { s->failed_pc=0x0c035588u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03558a;
P_0c03558a: /* original 000b, guest PC 0x0c03558a */
if(!s->budget--) { s->failed_pc=0x0c03558au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03558c: /* original 6ef6, guest PC 0x0c03558c */
if(!s->budget--) { s->failed_pc=0x0c03558cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03558eu,s,ram);
P_0c0355a4: /* original 4f22, guest PC 0x0c0355a4 */
if(!s->budget--) { s->failed_pc=0x0c0355a4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0355a6;
P_0c0355a6: /* original 2ee8, guest PC 0x0c0355a6 */
if(!s->budget--) { s->failed_pc=0x0c0355a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0355a8;
P_0c0355a8: /* original 890c, guest PC 0x0c0355a8 */
if(!s->budget--) { s->failed_pc=0x0c0355a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0355c4; }
goto P_0c0355aa;
P_0c0355aa: /* original e048, guest PC 0x0c0355aa */
if(!s->budget--) { s->failed_pc=0x0c0355aau; return 0; }
r[0]=0x00000048u;
goto P_0c0355ac;
P_0c0355ac: /* original 02ed, guest PC 0x0c0355ac */
if(!s->budget--) { s->failed_pc=0x0c0355acu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0355ae;
P_0c0355ae: /* original 2228, guest PC 0x0c0355ae */
if(!s->budget--) { s->failed_pc=0x0c0355aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0355b0;
P_0c0355b0: /* original 8908, guest PC 0x0c0355b0 */
if(!s->budget--) { s->failed_pc=0x0c0355b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0355c4; }
goto P_0c0355b2;
P_0c0355b2: /* original e04c, guest PC 0x0c0355b2 */
if(!s->budget--) { s->failed_pc=0x0c0355b2u; return 0; }
r[0]=0x0000004cu;
goto P_0c0355b4;
P_0c0355b4: /* original 00ed, guest PC 0x0c0355b4 */
if(!s->budget--) { s->failed_pc=0x0c0355b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0355b6;
P_0c0355b6: /* original 8802, guest PC 0x0c0355b6 */
if(!s->budget--) { s->failed_pc=0x0c0355b6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0355b8;
P_0c0355b8: /* original 8b01, guest PC 0x0c0355b8 */
if(!s->budget--) { s->failed_pc=0x0c0355b8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0355be; }
goto P_0c0355ba;
P_0c0355ba: /* original b248, guest PC 0x0c0355ba */
if(!s->budget--) { s->failed_pc=0x0c0355bau; return 0; }
target=0x0c035a4eu; r[16]=0x0c0355beu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0355beu) { target=s->pc; goto dispatch; }
goto P_0c0355be;
P_0c0355bc: /* original 64e3, guest PC 0x0c0355bc */
if(!s->budget--) { s->failed_pc=0x0c0355bcu; return 0; }
r[4]=r[14];
goto P_0c0355be;
P_0c0355be: /* original e048, guest PC 0x0c0355be */
if(!s->budget--) { s->failed_pc=0x0c0355beu; return 0; }
r[0]=0x00000048u;
goto P_0c0355c0;
P_0c0355c0: /* original e300, guest PC 0x0c0355c0 */
if(!s->budget--) { s->failed_pc=0x0c0355c0u; return 0; }
r[3]=0x00000000u;
goto P_0c0355c2;
P_0c0355c2: /* original 0e35, guest PC 0x0c0355c2 */
if(!s->budget--) { s->failed_pc=0x0c0355c2u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0355c4;
P_0c0355c4: /* original 4f26, guest PC 0x0c0355c4 */
if(!s->budget--) { s->failed_pc=0x0c0355c4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0355c6;
P_0c0355c6: /* original 000b, guest PC 0x0c0355c6 */
if(!s->budget--) { s->failed_pc=0x0c0355c6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0355c8: /* original 6ef6, guest PC 0x0c0355c8 */
if(!s->budget--) { s->failed_pc=0x0c0355c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0355cau,s,ram);
P_0c035a20: /* original 2448, guest PC 0x0c035a20 */
if(!s->budget--) { s->failed_pc=0x0c035a20u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c035a22;
P_0c035a22: /* original 8903, guest PC 0x0c035a22 */
if(!s->budget--) { s->failed_pc=0x0c035a22u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035a2c; }
goto P_0c035a24;
P_0c035a24: /* original e048, guest PC 0x0c035a24 */
if(!s->budget--) { s->failed_pc=0x0c035a24u; return 0; }
r[0]=0x00000048u;
goto P_0c035a26;
P_0c035a26: /* original 024d, guest PC 0x0c035a26 */
if(!s->budget--) { s->failed_pc=0x0c035a26u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c035a28;
P_0c035a28: /* original 2228, guest PC 0x0c035a28 */
if(!s->budget--) { s->failed_pc=0x0c035a28u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c035a2a;
P_0c035a2a: /* original 8b01, guest PC 0x0c035a2a */
if(!s->budget--) { s->failed_pc=0x0c035a2au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c035a30; }
goto P_0c035a2c;
P_0c035a2c: /* original 000b, guest PC 0x0c035a2c */
if(!s->budget--) { s->failed_pc=0x0c035a2cu; return 0; }
target=r[16];
r[0]=0xfffffff6u;
s->pc=target; return ram->oob==0;
P_0c035a2e: /* original e0f6, guest PC 0x0c035a2e */
if(!s->budget--) { s->failed_pc=0x0c035a2eu; return 0; }
r[0]=0xfffffff6u;
goto P_0c035a30;
P_0c035a30: /* original e04c, guest PC 0x0c035a30 */
if(!s->budget--) { s->failed_pc=0x0c035a30u; return 0; }
r[0]=0x0000004cu;
goto P_0c035a32;
P_0c035a32: /* original 004d, guest PC 0x0c035a32 */
if(!s->budget--) { s->failed_pc=0x0c035a32u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c035a34;
P_0c035a34: /* original 000b, guest PC 0x0c035a34 */
if(!s->budget--) { s->failed_pc=0x0c035a34u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c035a36: /* original 0009, guest PC 0x0c035a36 */
if(!s->budget--) { s->failed_pc=0x0c035a36u; return 0; }
return vf3_matrix_family(0x0c035a38u,s,ram);
P_0c035a4e: /* original 2fe6, guest PC 0x0c035a4e */
if(!s->budget--) { s->failed_pc=0x0c035a4eu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c035a50;
P_0c035a50: /* original 6e43, guest PC 0x0c035a50 */
if(!s->budget--) { s->failed_pc=0x0c035a50u; return 0; }
r[14]=r[4];
goto P_0c035a52;
P_0c035a52: /* original 4f22, guest PC 0x0c035a52 */
if(!s->budget--) { s->failed_pc=0x0c035a52u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c035a54;
P_0c035a54: /* original 2ee8, guest PC 0x0c035a54 */
if(!s->budget--) { s->failed_pc=0x0c035a54u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c035a56;
P_0c035a56: /* original 8903, guest PC 0x0c035a56 */
if(!s->budget--) { s->failed_pc=0x0c035a56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035a60; }
goto P_0c035a58;
P_0c035a58: /* original e048, guest PC 0x0c035a58 */
if(!s->budget--) { s->failed_pc=0x0c035a58u; return 0; }
r[0]=0x00000048u;
goto P_0c035a5a;
P_0c035a5a: /* original 02ed, guest PC 0x0c035a5a */
if(!s->budget--) { s->failed_pc=0x0c035a5au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c035a5c;
P_0c035a5c: /* original 2228, guest PC 0x0c035a5c */
if(!s->budget--) { s->failed_pc=0x0c035a5cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c035a5e;
P_0c035a5e: /* original 8b03, guest PC 0x0c035a5e */
if(!s->budget--) { s->failed_pc=0x0c035a5eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c035a68; }
goto P_0c035a60;
P_0c035a60: /* original 4f26, guest PC 0x0c035a60 */
if(!s->budget--) { s->failed_pc=0x0c035a60u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c035a62;
P_0c035a62: /* original e0f6, guest PC 0x0c035a62 */
if(!s->budget--) { s->failed_pc=0x0c035a62u; return 0; }
r[0]=0xfffffff6u;
goto P_0c035a64;
P_0c035a64: /* original 000b, guest PC 0x0c035a64 */
if(!s->budget--) { s->failed_pc=0x0c035a64u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c035a66: /* original 6ef6, guest PC 0x0c035a66 */
if(!s->budget--) { s->failed_pc=0x0c035a66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c035a68;
P_0c035a68: /* original e04c, guest PC 0x0c035a68 */
if(!s->budget--) { s->failed_pc=0x0c035a68u; return 0; }
r[0]=0x0000004cu;
goto P_0c035a6a;
P_0c035a6a: /* original 00ed, guest PC 0x0c035a6a */
if(!s->budget--) { s->failed_pc=0x0c035a6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c035a6c;
P_0c035a6c: /* original 8802, guest PC 0x0c035a6c */
if(!s->budget--) { s->failed_pc=0x0c035a6cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c035a6e;
P_0c035a6e: /* original 8906, guest PC 0x0c035a6e */
if(!s->budget--) { s->failed_pc=0x0c035a6eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035a7e; }
goto P_0c035a70;
P_0c035a70: /* original 4f26, guest PC 0x0c035a70 */
if(!s->budget--) { s->failed_pc=0x0c035a70u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c035a72;
P_0c035a72: /* original e04c, guest PC 0x0c035a72 */
if(!s->budget--) { s->failed_pc=0x0c035a72u; return 0; }
r[0]=0x0000004cu;
goto P_0c035a74;
P_0c035a74: /* original e200, guest PC 0x0c035a74 */
if(!s->budget--) { s->failed_pc=0x0c035a74u; return 0; }
r[2]=0x00000000u;
goto P_0c035a76;
P_0c035a76: /* original 0e25, guest PC 0x0c035a76 */
if(!s->budget--) { s->failed_pc=0x0c035a76u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c035a78;
P_0c035a78: /* original 6023, guest PC 0x0c035a78 */
if(!s->budget--) { s->failed_pc=0x0c035a78u; return 0; }
r[0]=r[2];
goto P_0c035a7a;
P_0c035a7a: /* original 000b, guest PC 0x0c035a7a */
if(!s->budget--) { s->failed_pc=0x0c035a7au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c035a7c: /* original 6ef6, guest PC 0x0c035a7c */
if(!s->budget--) { s->failed_pc=0x0c035a7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c035a7e;
P_0c035a7e: /* original 63e2, guest PC 0x0c035a7e */
if(!s->budget--) { s->failed_pc=0x0c035a7eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c035a80;
P_0c035a80: /* original 523a, guest PC 0x0c035a80 */
if(!s->budget--) { s->failed_pc=0x0c035a80u; return 0; }
r[2]=read(ram,r[3]+40,4);
goto P_0c035a82;
P_0c035a82: /* original 32e0, guest PC 0x0c035a82 */
if(!s->budget--) { s->failed_pc=0x0c035a82u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[14])!=0);
goto P_0c035a84;
P_0c035a84: /* original 8903, guest PC 0x0c035a84 */
if(!s->budget--) { s->failed_pc=0x0c035a84u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035a8e; }
goto P_0c035a86;
P_0c035a86: /* original 4f26, guest PC 0x0c035a86 */
if(!s->budget--) { s->failed_pc=0x0c035a86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c035a88;
P_0c035a88: /* original e0f3, guest PC 0x0c035a88 */
if(!s->budget--) { s->failed_pc=0x0c035a88u; return 0; }
r[0]=0xfffffff3u;
goto P_0c035a8a;
P_0c035a8a: /* original 000b, guest PC 0x0c035a8a */
if(!s->budget--) { s->failed_pc=0x0c035a8au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c035a8c: /* original 6ef6, guest PC 0x0c035a8c */
if(!s->budget--) { s->failed_pc=0x0c035a8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c035a8e;
P_0c035a8e: /* original 62e2, guest PC 0x0c035a8e */
if(!s->budget--) { s->failed_pc=0x0c035a8eu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c035a90;
P_0c035a90: /* original 5325, guest PC 0x0c035a90 */
if(!s->budget--) { s->failed_pc=0x0c035a90u; return 0; }
r[3]=read(ram,r[2]+20,4);
goto P_0c035a92;
P_0c035a92: /* original 5135, guest PC 0x0c035a92 */
if(!s->budget--) { s->failed_pc=0x0c035a92u; return 0; }
r[1]=read(ram,r[3]+20,4);
goto P_0c035a94;
P_0c035a94: /* original 410b, guest PC 0x0c035a94 */
if(!s->budget--) { s->failed_pc=0x0c035a94u; return 0; }
target=r[1];
r[16]=0x0c035a98u;
r[4]=read(ram,r[14]+60,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c035a98u) { target=s->pc; goto dispatch; }
goto P_0c035a98;
P_0c035a96: /* original 54ef, guest PC 0x0c035a96 */
if(!s->budget--) { s->failed_pc=0x0c035a96u; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c035a98;
P_0c035a98: /* original bd38, guest PC 0x0c035a98 */
if(!s->budget--) { s->failed_pc=0x0c035a98u; return 0; }
target=0x0c03550cu; r[16]=0x0c035a9cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c035a9cu) { target=s->pc; goto dispatch; }
goto P_0c035a9c;
P_0c035a9a: /* original 64e3, guest PC 0x0c035a9a */
if(!s->budget--) { s->failed_pc=0x0c035a9au; return 0; }
r[4]=r[14];
goto P_0c035a9c;
P_0c035a9c: /* original 4f26, guest PC 0x0c035a9c */
if(!s->budget--) { s->failed_pc=0x0c035a9cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c035a9e;
P_0c035a9e: /* original 000b, guest PC 0x0c035a9e */
if(!s->budget--) { s->failed_pc=0x0c035a9eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c035aa0: /* original 6ef6, guest PC 0x0c035aa0 */
if(!s->budget--) { s->failed_pc=0x0c035aa0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c035aa2u,s,ram);
P_0c06f892: /* original f40b, guest PC 0x0c06f892 */
if(!s->budget--) { s->failed_pc=0x0c06f892u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f894;
P_0c06f894: /* original 65f3, guest PC 0x0c06f894 */
if(!s->budget--) { s->failed_pc=0x0c06f894u; return 0; }
r[5]=r[15];
goto P_0c06f896;
P_0c06f896: /* original 64f3, guest PC 0x0c06f896 */
if(!s->budget--) { s->failed_pc=0x0c06f896u; return 0; }
r[4]=r[15];
goto P_0c06f898;
P_0c06f898: /* original 66f3, guest PC 0x0c06f898 */
if(!s->budget--) { s->failed_pc=0x0c06f898u; return 0; }
r[6]=r[15];
goto P_0c06f89a;
P_0c06f89a: /* original 742c, guest PC 0x0c06f89a */
if(!s->budget--) { s->failed_pc=0x0c06f89au; return 0; }
r[4]+=0x0000002cu;
goto P_0c06f89c;
P_0c06f89c: /* original 7644, guest PC 0x0c06f89c */
if(!s->budget--) { s->failed_pc=0x0c06f89cu; return 0; }
r[6]+=0x00000044u;
goto P_0c06f89e;
P_0c06f89e: /* original 7538, guest PC 0x0c06f89e */
if(!s->budget--) { s->failed_pc=0x0c06f89eu; return 0; }
r[5]+=0x00000038u;
goto P_0c06f8a0;
P_0c06f8a0: /* original f059, guest PC 0x0c06f8a0 */
if(!s->budget--) { s->failed_pc=0x0c06f8a0u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8a2;
P_0c06f8a2: /* original f369, guest PC 0x0c06f8a2 */
if(!s->budget--) { s->failed_pc=0x0c06f8a2u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8a4;
P_0c06f8a4: /* original f159, guest PC 0x0c06f8a4 */
if(!s->budget--) { s->failed_pc=0x0c06f8a4u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8a6;
P_0c06f8a6: /* original f469, guest PC 0x0c06f8a6 */
if(!s->budget--) { s->failed_pc=0x0c06f8a6u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8a8;
P_0c06f8a8: /* original f259, guest PC 0x0c06f8a8 */
if(!s->budget--) { s->failed_pc=0x0c06f8a8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8aa;
P_0c06f8aa: /* original f569, guest PC 0x0c06f8aa */
if(!s->budget--) { s->failed_pc=0x0c06f8aau; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8ac;
P_0c06f8ac: /* original 740c, guest PC 0x0c06f8ac */
if(!s->budget--) { s->failed_pc=0x0c06f8acu; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f8ae;
P_0c06f8ae: /* original f030, guest PC 0x0c06f8ae */
if(!s->budget--) { s->failed_pc=0x0c06f8aeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c06f8b0;
P_0c06f8b0: /* original f250, guest PC 0x0c06f8b0 */
if(!s->budget--) { s->failed_pc=0x0c06f8b0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c06f8b2;
P_0c06f8b2: /* original f140, guest PC 0x0c06f8b2 */
if(!s->budget--) { s->failed_pc=0x0c06f8b2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c06f8b4;
P_0c06f8b4: /* original f42b, guest PC 0x0c06f8b4 */
if(!s->budget--) { s->failed_pc=0x0c06f8b4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f8b6;
P_0c06f8b6: /* original f41b, guest PC 0x0c06f8b6 */
if(!s->budget--) { s->failed_pc=0x0c06f8b6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f8b8;
P_0c06f8b8: /* original f40b, guest PC 0x0c06f8b8 */
if(!s->budget--) { s->failed_pc=0x0c06f8b8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f8ba;
P_0c06f8ba: /* original 0009, guest PC 0x0c06f8ba */
if(!s->budget--) { s->failed_pc=0x0c06f8bau; return 0; }
goto P_0c06f8bc;
P_0c06f8bc: /* original 64f3, guest PC 0x0c06f8bc */
if(!s->budget--) { s->failed_pc=0x0c06f8bcu; return 0; }
r[4]=r[15];
goto P_0c06f8be;
P_0c06f8be: /* original 65f3, guest PC 0x0c06f8be */
if(!s->budget--) { s->failed_pc=0x0c06f8beu; return 0; }
r[5]=r[15];
goto P_0c06f8c0;
P_0c06f8c0: /* original 742c, guest PC 0x0c06f8c0 */
if(!s->budget--) { s->failed_pc=0x0c06f8c0u; return 0; }
r[4]+=0x0000002cu;
goto P_0c06f8c2;
P_0c06f8c2: /* original f4ec, guest PC 0x0c06f8c2 */
if(!s->budget--) { s->failed_pc=0x0c06f8c2u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06f8c4;
P_0c06f8c4: /* original 752c, guest PC 0x0c06f8c4 */
if(!s->budget--) { s->failed_pc=0x0c06f8c4u; return 0; }
r[5]+=0x0000002cu;
goto P_0c06f8c6;
P_0c06f8c6: /* original f059, guest PC 0x0c06f8c6 */
if(!s->budget--) { s->failed_pc=0x0c06f8c6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8c8;
P_0c06f8c8: /* original f159, guest PC 0x0c06f8c8 */
if(!s->budget--) { s->failed_pc=0x0c06f8c8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8ca;
P_0c06f8ca: /* original f259, guest PC 0x0c06f8ca */
if(!s->budget--) { s->failed_pc=0x0c06f8cau; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8cc;
P_0c06f8cc: /* original f38d, guest PC 0x0c06f8cc */
if(!s->budget--) { s->failed_pc=0x0c06f8ccu; return 0; }
fr[3]=0;
goto P_0c06f8ce;
P_0c06f8ce: /* original f0ed, guest PC 0x0c06f8ce */
if(!s->budget--) { s->failed_pc=0x0c06f8ceu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c06f8d0;
P_0c06f8d0: /* original f37d, guest PC 0x0c06f8d0 */
if(!s->budget--) { s->failed_pc=0x0c06f8d0u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c06f8d2;
P_0c06f8d2: /* original f342, guest PC 0x0c06f8d2 */
if(!s->budget--) { s->failed_pc=0x0c06f8d2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c06f8d4;
P_0c06f8d4: /* original 740c, guest PC 0x0c06f8d4 */
if(!s->budget--) { s->failed_pc=0x0c06f8d4u; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f8d6;
P_0c06f8d6: /* original f232, guest PC 0x0c06f8d6 */
if(!s->budget--) { s->failed_pc=0x0c06f8d6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c06f8d8;
P_0c06f8d8: /* original f132, guest PC 0x0c06f8d8 */
if(!s->budget--) { s->failed_pc=0x0c06f8d8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c06f8da;
P_0c06f8da: /* original f032, guest PC 0x0c06f8da */
if(!s->budget--) { s->failed_pc=0x0c06f8dau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c06f8dc;
P_0c06f8dc: /* original f42b, guest PC 0x0c06f8dc */
if(!s->budget--) { s->failed_pc=0x0c06f8dcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f8de;
P_0c06f8de: /* original f41b, guest PC 0x0c06f8de */
if(!s->budget--) { s->failed_pc=0x0c06f8deu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f8e0;
P_0c06f8e0: /* original f40b, guest PC 0x0c06f8e0 */
if(!s->budget--) { s->failed_pc=0x0c06f8e0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f8e2;
P_0c06f8e2: /* original 0009, guest PC 0x0c06f8e2 */
if(!s->budget--) { s->failed_pc=0x0c06f8e2u; return 0; }
goto P_0c06f8e4;
P_0c06f8e4: /* original 64f3, guest PC 0x0c06f8e4 */
if(!s->budget--) { s->failed_pc=0x0c06f8e4u; return 0; }
r[4]=r[15];
goto P_0c06f8e6;
P_0c06f8e6: /* original 66f3, guest PC 0x0c06f8e6 */
if(!s->budget--) { s->failed_pc=0x0c06f8e6u; return 0; }
r[6]=r[15];
goto P_0c06f8e8;
P_0c06f8e8: /* original 7450, guest PC 0x0c06f8e8 */
if(!s->budget--) { s->failed_pc=0x0c06f8e8u; return 0; }
r[4]+=0x00000050u;
goto P_0c06f8ea;
P_0c06f8ea: /* original 65c3, guest PC 0x0c06f8ea */
if(!s->budget--) { s->failed_pc=0x0c06f8eau; return 0; }
r[5]=r[12];
goto P_0c06f8ec;
P_0c06f8ec: /* original 762c, guest PC 0x0c06f8ec */
if(!s->budget--) { s->failed_pc=0x0c06f8ecu; return 0; }
r[6]+=0x0000002cu;
goto P_0c06f8ee;
P_0c06f8ee: /* original f059, guest PC 0x0c06f8ee */
if(!s->budget--) { s->failed_pc=0x0c06f8eeu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f0;
P_0c06f8f0: /* original f369, guest PC 0x0c06f8f0 */
if(!s->budget--) { s->failed_pc=0x0c06f8f0u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f2;
P_0c06f8f2: /* original f159, guest PC 0x0c06f8f2 */
if(!s->budget--) { s->failed_pc=0x0c06f8f2u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f4;
P_0c06f8f4: /* original f469, guest PC 0x0c06f8f4 */
if(!s->budget--) { s->failed_pc=0x0c06f8f4u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f6;
P_0c06f8f6: /* original f259, guest PC 0x0c06f8f6 */
if(!s->budget--) { s->failed_pc=0x0c06f8f6u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f8;
P_0c06f8f8: /* original f569, guest PC 0x0c06f8f8 */
if(!s->budget--) { s->failed_pc=0x0c06f8f8u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8fa;
P_0c06f8fa: /* original 740c, guest PC 0x0c06f8fa */
if(!s->budget--) { s->failed_pc=0x0c06f8fau; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f8fc;
P_0c06f8fc: /* original f030, guest PC 0x0c06f8fc */
if(!s->budget--) { s->failed_pc=0x0c06f8fcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c06f8fe;
P_0c06f8fe: /* original f250, guest PC 0x0c06f8fe */
if(!s->budget--) { s->failed_pc=0x0c06f8feu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c06f900;
P_0c06f900: /* original f140, guest PC 0x0c06f900 */
if(!s->budget--) { s->failed_pc=0x0c06f900u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c06f902;
P_0c06f902: /* original f42b, guest PC 0x0c06f902 */
if(!s->budget--) { s->failed_pc=0x0c06f902u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f904;
P_0c06f904: /* original f41b, guest PC 0x0c06f904 */
if(!s->budget--) { s->failed_pc=0x0c06f904u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f906;
P_0c06f906: /* original f40b, guest PC 0x0c06f906 */
if(!s->budget--) { s->failed_pc=0x0c06f906u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f908;
P_0c06f908: /* original 66f3, guest PC 0x0c06f908 */
if(!s->budget--) { s->failed_pc=0x0c06f908u; return 0; }
r[6]=r[15];
goto P_0c06f90a;
P_0c06f90a: /* original 64d3, guest PC 0x0c06f90a */
if(!s->budget--) { s->failed_pc=0x0c06f90au; return 0; }
r[4]=r[13];
goto P_0c06f90c;
P_0c06f90c: /* original 65c3, guest PC 0x0c06f90c */
if(!s->budget--) { s->failed_pc=0x0c06f90cu; return 0; }
r[5]=r[12];
goto P_0c06f90e;
P_0c06f90e: /* original 762c, guest PC 0x0c06f90e */
if(!s->budget--) { s->failed_pc=0x0c06f90eu; return 0; }
r[6]+=0x0000002cu;
goto P_0c06f910;
P_0c06f910: /* original f059, guest PC 0x0c06f910 */
if(!s->budget--) { s->failed_pc=0x0c06f910u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f912;
P_0c06f912: /* original f369, guest PC 0x0c06f912 */
if(!s->budget--) { s->failed_pc=0x0c06f912u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f914;
P_0c06f914: /* original f159, guest PC 0x0c06f914 */
if(!s->budget--) { s->failed_pc=0x0c06f914u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f916;
P_0c06f916: /* original f469, guest PC 0x0c06f916 */
if(!s->budget--) { s->failed_pc=0x0c06f916u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f918;
P_0c06f918: /* original f259, guest PC 0x0c06f918 */
if(!s->budget--) { s->failed_pc=0x0c06f918u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f91a;
P_0c06f91a: /* original f569, guest PC 0x0c06f91a */
if(!s->budget--) { s->failed_pc=0x0c06f91au; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f91c;
P_0c06f91c: /* original 740c, guest PC 0x0c06f91c */
if(!s->budget--) { s->failed_pc=0x0c06f91cu; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f91e;
P_0c06f91e: /* original f030, guest PC 0x0c06f91e */
if(!s->budget--) { s->failed_pc=0x0c06f91eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c06f920;
P_0c06f920: /* original f250, guest PC 0x0c06f920 */
if(!s->budget--) { s->failed_pc=0x0c06f920u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c06f922;
P_0c06f922: /* original f140, guest PC 0x0c06f922 */
if(!s->budget--) { s->failed_pc=0x0c06f922u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c06f924;
P_0c06f924: /* original f42b, guest PC 0x0c06f924 */
if(!s->budget--) { s->failed_pc=0x0c06f924u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f926;
P_0c06f926: /* original f41b, guest PC 0x0c06f926 */
if(!s->budget--) { s->failed_pc=0x0c06f926u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f928;
P_0c06f928: /* original f40b, guest PC 0x0c06f928 */
if(!s->budget--) { s->failed_pc=0x0c06f928u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f92a;
P_0c06f92a: /* original 0009, guest PC 0x0c06f92a */
if(!s->budget--) { s->failed_pc=0x0c06f92au; return 0; }
goto P_0c06f92c;
P_0c06f92c: /* original 7901, guest PC 0x0c06f92c */
if(!s->budget--) { s->failed_pc=0x0c06f92cu; return 0; }
r[9]+=0x00000001u;
goto P_0c06f92e;
P_0c06f92e: /* original 39a3, guest PC 0x0c06f92e */
if(!s->budget--) { s->failed_pc=0x0c06f92eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[10])!=0);
goto P_0c06f930;
P_0c06f930: /* original 7d18, guest PC 0x0c06f930 */
if(!s->budget--) { s->failed_pc=0x0c06f930u; return 0; }
r[13]+=0x00000018u;
goto P_0c06f932;
P_0c06f932: /* original 8d03, guest PC 0x0c06f932 */
if(!s->budget--) { s->failed_pc=0x0c06f932u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000018u;
if(cond) { goto P_0c06f93c; }
goto P_0c06f936;
P_0c06f934: /* original 7c18, guest PC 0x0c06f934 */
if(!s->budget--) { s->failed_pc=0x0c06f934u; return 0; }
r[12]+=0x00000018u;
goto P_0c06f936;
P_0c06f936: /* original d234, guest PC 0x0c06f936 */
if(!s->budget--) { s->failed_pc=0x0c06f936u; return 0; }
r[2]=read(ram,0x0c06fa08u,4);
goto P_0c06f938;
P_0c06f938: /* original 422b, guest PC 0x0c06f938 */
if(!s->budget--) { s->failed_pc=0x0c06f938u; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c06f93a: /* original 0009, guest PC 0x0c06f93a */
if(!s->budget--) { s->failed_pc=0x0c06f93au; return 0; }
goto P_0c06f93c;
P_0c06f93c: /* original d333, guest PC 0x0c06f93c */
if(!s->budget--) { s->failed_pc=0x0c06f93cu; return 0; }
r[3]=read(ram,0x0c06fa0cu,4);
goto P_0c06f93e;
P_0c06f93e: /* original 65e3, guest PC 0x0c06f93e */
if(!s->budget--) { s->failed_pc=0x0c06f93eu; return 0; }
r[5]=r[14];
goto P_0c06f940;
P_0c06f940: /* original 6783, guest PC 0x0c06f940 */
if(!s->budget--) { s->failed_pc=0x0c06f940u; return 0; }
r[7]=r[8];
goto P_0c06f942;
P_0c06f942: /* original 66d3, guest PC 0x0c06f942 */
if(!s->budget--) { s->failed_pc=0x0c06f942u; return 0; }
r[6]=r[13];
goto P_0c06f944;
P_0c06f944: /* original 430b, guest PC 0x0c06f944 */
if(!s->budget--) { s->failed_pc=0x0c06f944u; return 0; }
target=r[3];
r[16]=0x0c06f948u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f948u) { target=s->pc; goto dispatch; }
goto P_0c06f948;
P_0c06f946: /* original 64b3, guest PC 0x0c06f946 */
if(!s->budget--) { s->failed_pc=0x0c06f946u; return 0; }
r[4]=r[11];
goto P_0c06f948;
P_0c06f948: /* original 7801, guest PC 0x0c06f948 */
if(!s->budget--) { s->failed_pc=0x0c06f948u; return 0; }
r[8]+=0x00000001u;
goto P_0c06f94a;
P_0c06f94a: /* original 52f1, guest PC 0x0c06f94a */
if(!s->budget--) { s->failed_pc=0x0c06f94au; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c06f94c;
P_0c06f94c: /* original 3823, guest PC 0x0c06f94c */
if(!s->budget--) { s->failed_pc=0x0c06f94cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[2])!=0);
goto P_0c06f94e;
P_0c06f94e: /* original 8902, guest PC 0x0c06f94e */
if(!s->budget--) { s->failed_pc=0x0c06f94eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06f956; }
goto P_0c06f950;
P_0c06f950: /* original d32f, guest PC 0x0c06f950 */
if(!s->budget--) { s->failed_pc=0x0c06f950u; return 0; }
r[3]=read(ram,0x0c06fa10u,4);
goto P_0c06f952;
P_0c06f952: /* original 432b, guest PC 0x0c06f952 */
if(!s->budget--) { s->failed_pc=0x0c06f952u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c06f954: /* original 0009, guest PC 0x0c06f954 */
if(!s->budget--) { s->failed_pc=0x0c06f954u; return 0; }
goto P_0c06f956;
P_0c06f956: /* original d22f, guest PC 0x0c06f956 */
if(!s->budget--) { s->failed_pc=0x0c06f956u; return 0; }
r[2]=read(ram,0x0c06fa14u,4);
goto P_0c06f958;
P_0c06f958: /* original 420b, guest PC 0x0c06f958 */
if(!s->budget--) { s->failed_pc=0x0c06f958u; return 0; }
target=r[2];
r[16]=0x0c06f95cu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f95cu) { target=s->pc; goto dispatch; }
goto P_0c06f95c;
P_0c06f95a: /* original e401, guest PC 0x0c06f95a */
if(!s->budget--) { s->failed_pc=0x0c06f95au; return 0; }
r[4]=0x00000001u;
goto P_0c06f95c;
P_0c06f95c: /* original d32e, guest PC 0x0c06f95c */
if(!s->budget--) { s->failed_pc=0x0c06f95cu; return 0; }
r[3]=read(ram,0x0c06fa18u,4);
goto P_0c06f95e;
P_0c06f95e: /* original 430b, guest PC 0x0c06f95e */
if(!s->budget--) { s->failed_pc=0x0c06f95eu; return 0; }
target=r[3];
r[16]=0x0c06f962u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f962u) { target=s->pc; goto dispatch; }
goto P_0c06f962;
P_0c06f960: /* original 64e3, guest PC 0x0c06f960 */
if(!s->budget--) { s->failed_pc=0x0c06f960u; return 0; }
r[4]=r[14];
goto P_0c06f962;
P_0c06f962: /* original d22e, guest PC 0x0c06f962 */
if(!s->budget--) { s->failed_pc=0x0c06f962u; return 0; }
r[2]=read(ram,0x0c06fa1cu,4);
goto P_0c06f964;
P_0c06f964: /* original 65e3, guest PC 0x0c06f964 */
if(!s->budget--) { s->failed_pc=0x0c06f964u; return 0; }
r[5]=r[14];
goto P_0c06f966;
P_0c06f966: /* original 420b, guest PC 0x0c06f966 */
if(!s->budget--) { s->failed_pc=0x0c06f966u; return 0; }
target=r[2];
r[16]=0x0c06f96au;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f96au) { target=s->pc; goto dispatch; }
goto P_0c06f96a;
P_0c06f968: /* original 64b3, guest PC 0x0c06f968 */
if(!s->budget--) { s->failed_pc=0x0c06f968u; return 0; }
r[4]=r[11];
goto P_0c06f96a;
P_0c06f96a: /* original d32d, guest PC 0x0c06f96a */
if(!s->budget--) { s->failed_pc=0x0c06f96au; return 0; }
r[3]=read(ram,0x0c06fa20u,4);
goto P_0c06f96c;
P_0c06f96c: /* original 64e3, guest PC 0x0c06f96c */
if(!s->budget--) { s->failed_pc=0x0c06f96cu; return 0; }
r[4]=r[14];
goto P_0c06f96e;
P_0c06f96e: /* original 65f2, guest PC 0x0c06f96e */
if(!s->budget--) { s->failed_pc=0x0c06f96eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06f970;
P_0c06f970: /* original 430b, guest PC 0x0c06f970 */
if(!s->budget--) { s->failed_pc=0x0c06f970u; return 0; }
target=r[3];
r[16]=0x0c06f974u;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f974u) { target=s->pc; goto dispatch; }
goto P_0c06f974;
P_0c06f972: /* original 7410, guest PC 0x0c06f972 */
if(!s->budget--) { s->failed_pc=0x0c06f972u; return 0; }
r[4]+=0x00000010u;
goto P_0c06f974;
P_0c06f974: /* original 7f74, guest PC 0x0c06f974 */
if(!s->budget--) { s->failed_pc=0x0c06f974u; return 0; }
r[15]+=0x00000074u;
goto P_0c06f976;
P_0c06f976: /* original 4f16, guest PC 0x0c06f976 */
if(!s->budget--) { s->failed_pc=0x0c06f976u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c06f978;
P_0c06f978: /* original 4f26, guest PC 0x0c06f978 */
if(!s->budget--) { s->failed_pc=0x0c06f978u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06f97a;
P_0c06f97a: /* original fcf9, guest PC 0x0c06f97a */
if(!s->budget--) { s->failed_pc=0x0c06f97au; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f97c;
P_0c06f97c: /* original fdf9, guest PC 0x0c06f97c */
if(!s->budget--) { s->failed_pc=0x0c06f97cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f97e;
P_0c06f97e: /* original fef9, guest PC 0x0c06f97e */
if(!s->budget--) { s->failed_pc=0x0c06f97eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f980;
P_0c06f980: /* original fff9, guest PC 0x0c06f980 */
if(!s->budget--) { s->failed_pc=0x0c06f980u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f982;
P_0c06f982: /* original 68f6, guest PC 0x0c06f982 */
if(!s->budget--) { s->failed_pc=0x0c06f982u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06f984;
P_0c06f984: /* original 69f6, guest PC 0x0c06f984 */
if(!s->budget--) { s->failed_pc=0x0c06f984u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06f986;
P_0c06f986: /* original 6af6, guest PC 0x0c06f986 */
if(!s->budget--) { s->failed_pc=0x0c06f986u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06f988;
P_0c06f988: /* original 6bf6, guest PC 0x0c06f988 */
if(!s->budget--) { s->failed_pc=0x0c06f988u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06f98a;
P_0c06f98a: /* original 6cf6, guest PC 0x0c06f98a */
if(!s->budget--) { s->failed_pc=0x0c06f98au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06f98c;
P_0c06f98c: /* original 6df6, guest PC 0x0c06f98c */
if(!s->budget--) { s->failed_pc=0x0c06f98cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06f98e;
P_0c06f98e: /* original 000b, guest PC 0x0c06f98e */
if(!s->budget--) { s->failed_pc=0x0c06f98eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06f990: /* original 6ef6, guest PC 0x0c06f990 */
if(!s->budget--) { s->failed_pc=0x0c06f990u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06f992u,s,ram);
P_0c071806: /* original f40b, guest PC 0x0c071806 */
if(!s->budget--) { s->failed_pc=0x0c071806u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071808;
P_0c071808: /* original 65f3, guest PC 0x0c071808 */
if(!s->budget--) { s->failed_pc=0x0c071808u; return 0; }
r[5]=r[15];
goto P_0c07180a;
P_0c07180a: /* original 64e3, guest PC 0x0c07180a */
if(!s->budget--) { s->failed_pc=0x0c07180au; return 0; }
r[4]=r[14];
goto P_0c07180c;
P_0c07180c: /* original 66f3, guest PC 0x0c07180c */
if(!s->budget--) { s->failed_pc=0x0c07180cu; return 0; }
r[6]=r[15];
goto P_0c07180e;
P_0c07180e: /* original 740c, guest PC 0x0c07180e */
if(!s->budget--) { s->failed_pc=0x0c07180eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c071810;
P_0c071810: /* original 7618, guest PC 0x0c071810 */
if(!s->budget--) { s->failed_pc=0x0c071810u; return 0; }
r[6]+=0x00000018u;
goto P_0c071812;
P_0c071812: /* original 7524, guest PC 0x0c071812 */
if(!s->budget--) { s->failed_pc=0x0c071812u; return 0; }
r[5]+=0x00000024u;
goto P_0c071814;
P_0c071814: /* original f059, guest PC 0x0c071814 */
if(!s->budget--) { s->failed_pc=0x0c071814u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071816;
P_0c071816: /* original f369, guest PC 0x0c071816 */
if(!s->budget--) { s->failed_pc=0x0c071816u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071818;
P_0c071818: /* original f159, guest PC 0x0c071818 */
if(!s->budget--) { s->failed_pc=0x0c071818u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07181a;
P_0c07181a: /* original f469, guest PC 0x0c07181a */
if(!s->budget--) { s->failed_pc=0x0c07181au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07181c;
P_0c07181c: /* original f259, guest PC 0x0c07181c */
if(!s->budget--) { s->failed_pc=0x0c07181cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07181e;
P_0c07181e: /* original f569, guest PC 0x0c07181e */
if(!s->budget--) { s->failed_pc=0x0c07181eu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071820;
P_0c071820: /* original 740c, guest PC 0x0c071820 */
if(!s->budget--) { s->failed_pc=0x0c071820u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071822;
P_0c071822: /* original f030, guest PC 0x0c071822 */
if(!s->budget--) { s->failed_pc=0x0c071822u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c071824;
P_0c071824: /* original f250, guest PC 0x0c071824 */
if(!s->budget--) { s->failed_pc=0x0c071824u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c071826;
P_0c071826: /* original f140, guest PC 0x0c071826 */
if(!s->budget--) { s->failed_pc=0x0c071826u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071828;
P_0c071828: /* original f42b, guest PC 0x0c071828 */
if(!s->budget--) { s->failed_pc=0x0c071828u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07182a;
P_0c07182a: /* original f41b, guest PC 0x0c07182a */
if(!s->budget--) { s->failed_pc=0x0c07182au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07182c;
P_0c07182c: /* original f40b, guest PC 0x0c07182c */
if(!s->budget--) { s->failed_pc=0x0c07182cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07182e;
P_0c07182e: /* original 0009, guest PC 0x0c07182e */
if(!s->budget--) { s->failed_pc=0x0c07182eu; return 0; }
goto P_0c071830;
P_0c071830: /* original 64e3, guest PC 0x0c071830 */
if(!s->budget--) { s->failed_pc=0x0c071830u; return 0; }
r[4]=r[14];
goto P_0c071832;
P_0c071832: /* original 740c, guest PC 0x0c071832 */
if(!s->budget--) { s->failed_pc=0x0c071832u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071834;
P_0c071834: /* original f049, guest PC 0x0c071834 */
if(!s->budget--) { s->failed_pc=0x0c071834u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071836;
P_0c071836: /* original f149, guest PC 0x0c071836 */
if(!s->budget--) { s->failed_pc=0x0c071836u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071838;
P_0c071838: /* original f249, guest PC 0x0c071838 */
if(!s->budget--) { s->failed_pc=0x0c071838u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07183a;
P_0c07183a: /* original f38d, guest PC 0x0c07183a */
if(!s->budget--) { s->failed_pc=0x0c07183au; return 0; }
fr[3]=0;
goto P_0c07183c;
P_0c07183c: /* original f0ed, guest PC 0x0c07183c */
if(!s->budget--) { s->failed_pc=0x0c07183cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07183e;
P_0c07183e: /* original f37d, guest PC 0x0c07183e */
if(!s->budget--) { s->failed_pc=0x0c07183eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071840;
P_0c071840: /* original f232, guest PC 0x0c071840 */
if(!s->budget--) { s->failed_pc=0x0c071840u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071842;
P_0c071842: /* original f132, guest PC 0x0c071842 */
if(!s->budget--) { s->failed_pc=0x0c071842u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071844;
P_0c071844: /* original f032, guest PC 0x0c071844 */
if(!s->budget--) { s->failed_pc=0x0c071844u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071846;
P_0c071846: /* original f42b, guest PC 0x0c071846 */
if(!s->budget--) { s->failed_pc=0x0c071846u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071848;
P_0c071848: /* original f41b, guest PC 0x0c071848 */
if(!s->budget--) { s->failed_pc=0x0c071848u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07184a;
P_0c07184a: /* original f40b, guest PC 0x0c07184a */
if(!s->budget--) { s->failed_pc=0x0c07184au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07184c;
P_0c07184c: /* original 1fe1, guest PC 0x0c07184c */
if(!s->budget--) { s->failed_pc=0x0c07184cu; return 0; }
write(ram,r[15]+4,r[14],4);
goto P_0c07184e;
P_0c07184e: /* original 6eb3, guest PC 0x0c07184e */
if(!s->budget--) { s->failed_pc=0x0c07184eu; return 0; }
r[14]=r[11];
goto P_0c071850;
P_0c071850: /* original 63f2, guest PC 0x0c071850 */
if(!s->budget--) { s->failed_pc=0x0c071850u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c071852;
P_0c071852: /* original 7b18, guest PC 0x0c071852 */
if(!s->budget--) { s->failed_pc=0x0c071852u; return 0; }
r[11]+=0x00000018u;
goto P_0c071854;
P_0c071854: /* original 7318, guest PC 0x0c071854 */
if(!s->budget--) { s->failed_pc=0x0c071854u; return 0; }
r[3]+=0x00000018u;
goto P_0c071856;
P_0c071856: /* original 2f32, guest PC 0x0c071856 */
if(!s->budget--) { s->failed_pc=0x0c071856u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c071858;
P_0c071858: /* original 52f2, guest PC 0x0c071858 */
if(!s->budget--) { s->failed_pc=0x0c071858u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c07185a;
P_0c07185a: /* original 72ff, guest PC 0x0c07185a */
if(!s->budget--) { s->failed_pc=0x0c07185au; return 0; }
r[2]+=0xffffffffu;
goto P_0c07185c;
P_0c07185c: /* original 3297, guest PC 0x0c07185c */
if(!s->budget--) { s->failed_pc=0x0c07185cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[9])!=0);
goto P_0c07185e;
P_0c07185e: /* original 8f03, guest PC 0x0c07185e */
if(!s->budget--) { s->failed_pc=0x0c07185eu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[2],4);
if(!cond) { goto P_0c071868; }
goto P_0c071862;
P_0c071860: /* original 1f22, guest PC 0x0c071860 */
if(!s->budget--) { s->failed_pc=0x0c071860u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c071862;
P_0c071862: /* original d104, guest PC 0x0c071862 */
if(!s->budget--) { s->failed_pc=0x0c071862u; return 0; }
r[1]=read(ram,0x0c071874u,4);
goto P_0c071864;
P_0c071864: /* original 412b, guest PC 0x0c071864 */
if(!s->budget--) { s->failed_pc=0x0c071864u; return 0; }
target=r[1];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c071866: /* original 0009, guest PC 0x0c071866 */
if(!s->budget--) { s->failed_pc=0x0c071866u; return 0; }
goto P_0c071868;
P_0c071868: /* original 55f1, guest PC 0x0c071868 */
if(!s->budget--) { s->failed_pc=0x0c071868u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c07186a;
P_0c07186a: /* original 64d3, guest PC 0x0c07186a */
if(!s->budget--) { s->failed_pc=0x0c07186au; return 0; }
r[4]=r[13];
goto P_0c07186c;
P_0c07186c: /* original 66e3, guest PC 0x0c07186c */
if(!s->budget--) { s->failed_pc=0x0c07186cu; return 0; }
r[6]=r[14];
goto P_0c07186e;
P_0c07186e: /* original a003, guest PC 0x0c07186e */
if(!s->budget--) { s->failed_pc=0x0c07186eu; return 0; }
goto P_0c071878;
P_0c071870: /* original 0009, guest PC 0x0c071870 */
if(!s->budget--) { s->failed_pc=0x0c071870u; return 0; }
return vf3_matrix_family(0x0c071872u,s,ram);
P_0c071878: /* original f059, guest PC 0x0c071878 */
if(!s->budget--) { s->failed_pc=0x0c071878u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07187a;
P_0c07187a: /* original f369, guest PC 0x0c07187a */
if(!s->budget--) { s->failed_pc=0x0c07187au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07187c;
P_0c07187c: /* original f159, guest PC 0x0c07187c */
if(!s->budget--) { s->failed_pc=0x0c07187cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07187e;
P_0c07187e: /* original f469, guest PC 0x0c07187e */
if(!s->budget--) { s->failed_pc=0x0c07187eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071880;
P_0c071880: /* original f031, guest PC 0x0c071880 */
if(!s->budget--) { s->failed_pc=0x0c071880u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071882;
P_0c071882: /* original f258, guest PC 0x0c071882 */
if(!s->budget--) { s->failed_pc=0x0c071882u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071884;
P_0c071884: /* original f568, guest PC 0x0c071884 */
if(!s->budget--) { s->failed_pc=0x0c071884u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071886;
P_0c071886: /* original f141, guest PC 0x0c071886 */
if(!s->budget--) { s->failed_pc=0x0c071886u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071888;
P_0c071888: /* original f251, guest PC 0x0c071888 */
if(!s->budget--) { s->failed_pc=0x0c071888u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c07188a;
P_0c07188a: /* original 7408, guest PC 0x0c07188a */
if(!s->budget--) { s->failed_pc=0x0c07188au; return 0; }
r[4]+=0x00000008u;
goto P_0c07188c;
P_0c07188c: /* original f42a, guest PC 0x0c07188c */
if(!s->budget--) { s->failed_pc=0x0c07188cu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07188e;
P_0c07188e: /* original f41b, guest PC 0x0c07188e */
if(!s->budget--) { s->failed_pc=0x0c07188eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071890;
P_0c071890: /* original f40b, guest PC 0x0c071890 */
if(!s->budget--) { s->failed_pc=0x0c071890u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071892;
P_0c071892: /* original 0009, guest PC 0x0c071892 */
if(!s->budget--) { s->failed_pc=0x0c071892u; return 0; }
goto P_0c071894;
P_0c071894: /* original 65f2, guest PC 0x0c071894 */
if(!s->budget--) { s->failed_pc=0x0c071894u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c071896;
P_0c071896: /* original 64a3, guest PC 0x0c071896 */
if(!s->budget--) { s->failed_pc=0x0c071896u; return 0; }
r[4]=r[10];
goto P_0c071898;
P_0c071898: /* original 66e3, guest PC 0x0c071898 */
if(!s->budget--) { s->failed_pc=0x0c071898u; return 0; }
r[6]=r[14];
goto P_0c07189a;
P_0c07189a: /* original f059, guest PC 0x0c07189a */
if(!s->budget--) { s->failed_pc=0x0c07189au; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07189c;
P_0c07189c: /* original f369, guest PC 0x0c07189c */
if(!s->budget--) { s->failed_pc=0x0c07189cu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07189e;
P_0c07189e: /* original f159, guest PC 0x0c07189e */
if(!s->budget--) { s->failed_pc=0x0c07189eu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0718a0;
P_0c0718a0: /* original f469, guest PC 0x0c0718a0 */
if(!s->budget--) { s->failed_pc=0x0c0718a0u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0718a2;
P_0c0718a2: /* original f031, guest PC 0x0c0718a2 */
if(!s->budget--) { s->failed_pc=0x0c0718a2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0718a4;
P_0c0718a4: /* original f258, guest PC 0x0c0718a4 */
if(!s->budget--) { s->failed_pc=0x0c0718a4u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0718a6;
P_0c0718a6: /* original f568, guest PC 0x0c0718a6 */
if(!s->budget--) { s->failed_pc=0x0c0718a6u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0718a8;
P_0c0718a8: /* original f141, guest PC 0x0c0718a8 */
if(!s->budget--) { s->failed_pc=0x0c0718a8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0718aa;
P_0c0718aa: /* original f251, guest PC 0x0c0718aa */
if(!s->budget--) { s->failed_pc=0x0c0718aau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0718ac;
P_0c0718ac: /* original 7408, guest PC 0x0c0718ac */
if(!s->budget--) { s->failed_pc=0x0c0718acu; return 0; }
r[4]+=0x00000008u;
goto P_0c0718ae;
P_0c0718ae: /* original f42a, guest PC 0x0c0718ae */
if(!s->budget--) { s->failed_pc=0x0c0718aeu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0718b0;
P_0c0718b0: /* original f41b, guest PC 0x0c0718b0 */
if(!s->budget--) { s->failed_pc=0x0c0718b0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0718b2;
P_0c0718b2: /* original f40b, guest PC 0x0c0718b2 */
if(!s->budget--) { s->failed_pc=0x0c0718b2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0718b4;
P_0c0718b4: /* original 66e3, guest PC 0x0c0718b4 */
if(!s->budget--) { s->failed_pc=0x0c0718b4u; return 0; }
r[6]=r[14];
goto P_0c0718b6;
P_0c0718b6: /* original 64a3, guest PC 0x0c0718b6 */
if(!s->budget--) { s->failed_pc=0x0c0718b6u; return 0; }
r[4]=r[10];
goto P_0c0718b8;
P_0c0718b8: /* original 65d3, guest PC 0x0c0718b8 */
if(!s->budget--) { s->failed_pc=0x0c0718b8u; return 0; }
r[5]=r[13];
goto P_0c0718ba;
P_0c0718ba: /* original 760c, guest PC 0x0c0718ba */
if(!s->budget--) { s->failed_pc=0x0c0718bau; return 0; }
r[6]+=0x0000000cu;
goto P_0c0718bc;
P_0c0718bc: /* original f049, guest PC 0x0c0718bc */
if(!s->budget--) { s->failed_pc=0x0c0718bcu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0718be;
P_0c0718be: /* original f549, guest PC 0x0c0718be */
if(!s->budget--) { s->failed_pc=0x0c0718beu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0718c0;
P_0c0718c0: /* original f648, guest PC 0x0c0718c0 */
if(!s->budget--) { s->failed_pc=0x0c0718c0u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0718c2;
P_0c0718c2: /* original f859, guest PC 0x0c0718c2 */
if(!s->budget--) { s->failed_pc=0x0c0718c2u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0718c4;
P_0c0718c4: /* original f959, guest PC 0x0c0718c4 */
if(!s->budget--) { s->failed_pc=0x0c0718c4u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0718c6;
P_0c0718c6: /* original fa58, guest PC 0x0c0718c6 */
if(!s->budget--) { s->failed_pc=0x0c0718c6u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c0718c8;
P_0c0718c8: /* original 760c, guest PC 0x0c0718c8 */
if(!s->budget--) { s->failed_pc=0x0c0718c8u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0718ca;
P_0c0718ca: /* original f35c, guest PC 0x0c0718ca */
if(!s->budget--) { s->failed_pc=0x0c0718cau; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0718cc;
P_0c0718cc: /* original f382, guest PC 0x0c0718cc */
if(!s->budget--) { s->failed_pc=0x0c0718ccu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c0718ce;
P_0c0718ce: /* original f20c, guest PC 0x0c0718ce */
if(!s->budget--) { s->failed_pc=0x0c0718ceu; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c0718d0;
P_0c0718d0: /* original f2a2, guest PC 0x0c0718d0 */
if(!s->budget--) { s->failed_pc=0x0c0718d0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c0718d2;
P_0c0718d2: /* original f16c, guest PC 0x0c0718d2 */
if(!s->budget--) { s->failed_pc=0x0c0718d2u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c0718d4;
P_0c0718d4: /* original f192, guest PC 0x0c0718d4 */
if(!s->budget--) { s->failed_pc=0x0c0718d4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c0718d6;
P_0c0718d6: /* original f34d, guest PC 0x0c0718d6 */
if(!s->budget--) { s->failed_pc=0x0c0718d6u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0718d8;
P_0c0718d8: /* original f39e, guest PC 0x0c0718d8 */
if(!s->budget--) { s->failed_pc=0x0c0718d8u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c0718da;
P_0c0718da: /* original f24d, guest PC 0x0c0718da */
if(!s->budget--) { s->failed_pc=0x0c0718dau; return 0; }
fr[2]^=0x80000000u;
goto P_0c0718dc;
P_0c0718dc: /* original f06c, guest PC 0x0c0718dc */
if(!s->budget--) { s->failed_pc=0x0c0718dcu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0718de;
P_0c0718de: /* original f28e, guest PC 0x0c0718de */
if(!s->budget--) { s->failed_pc=0x0c0718deu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c0718e0;
P_0c0718e0: /* original f14d, guest PC 0x0c0718e0 */
if(!s->budget--) { s->failed_pc=0x0c0718e0u; return 0; }
fr[1]^=0x80000000u;
goto P_0c0718e2;
P_0c0718e2: /* original f63b, guest PC 0x0c0718e2 */
if(!s->budget--) { s->failed_pc=0x0c0718e2u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c0718e4;
P_0c0718e4: /* original f05c, guest PC 0x0c0718e4 */
if(!s->budget--) { s->failed_pc=0x0c0718e4u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0718e6;
P_0c0718e6: /* original f1ae, guest PC 0x0c0718e6 */
if(!s->budget--) { s->failed_pc=0x0c0718e6u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c0718e8;
P_0c0718e8: /* original f62b, guest PC 0x0c0718e8 */
if(!s->budget--) { s->failed_pc=0x0c0718e8u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c0718ea;
P_0c0718ea: /* original f61b, guest PC 0x0c0718ea */
if(!s->budget--) { s->failed_pc=0x0c0718eau; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c0718ec;
P_0c0718ec: /* original 64e3, guest PC 0x0c0718ec */
if(!s->budget--) { s->failed_pc=0x0c0718ecu; return 0; }
r[4]=r[14];
goto P_0c0718ee;
P_0c0718ee: /* original 740c, guest PC 0x0c0718ee */
if(!s->budget--) { s->failed_pc=0x0c0718eeu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0718f0;
P_0c0718f0: /* original f049, guest PC 0x0c0718f0 */
if(!s->budget--) { s->failed_pc=0x0c0718f0u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0718f2;
P_0c0718f2: /* original f149, guest PC 0x0c0718f2 */
if(!s->budget--) { s->failed_pc=0x0c0718f2u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0718f4;
P_0c0718f4: /* original f249, guest PC 0x0c0718f4 */
if(!s->budget--) { s->failed_pc=0x0c0718f4u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0718f6;
P_0c0718f6: /* original f38d, guest PC 0x0c0718f6 */
if(!s->budget--) { s->failed_pc=0x0c0718f6u; return 0; }
fr[3]=0;
goto P_0c0718f8;
P_0c0718f8: /* original f0ed, guest PC 0x0c0718f8 */
if(!s->budget--) { s->failed_pc=0x0c0718f8u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0718fa;
P_0c0718fa: /* original f37d, guest PC 0x0c0718fa */
if(!s->budget--) { s->failed_pc=0x0c0718fau; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0718fc;
P_0c0718fc: /* original f232, guest PC 0x0c0718fc */
if(!s->budget--) { s->failed_pc=0x0c0718fcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0718fe;
P_0c0718fe: /* original f132, guest PC 0x0c0718fe */
if(!s->budget--) { s->failed_pc=0x0c0718feu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071900;
P_0c071900: /* original f032, guest PC 0x0c071900 */
if(!s->budget--) { s->failed_pc=0x0c071900u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071902;
P_0c071902: /* original f42b, guest PC 0x0c071902 */
if(!s->budget--) { s->failed_pc=0x0c071902u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071904;
P_0c071904: /* original f41b, guest PC 0x0c071904 */
if(!s->budget--) { s->failed_pc=0x0c071904u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071906;
P_0c071906: /* original f40b, guest PC 0x0c071906 */
if(!s->budget--) { s->failed_pc=0x0c071906u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071908;
P_0c071908: /* original 61f3, guest PC 0x0c071908 */
if(!s->budget--) { s->failed_pc=0x0c071908u; return 0; }
r[1]=r[15];
goto P_0c07190a;
P_0c07190a: /* original 7154, guest PC 0x0c07190a */
if(!s->budget--) { s->failed_pc=0x0c07190au; return 0; }
r[1]+=0x00000054u;
goto P_0c07190c;
P_0c07190c: /* original 62f2, guest PC 0x0c07190c */
if(!s->budget--) { s->failed_pc=0x0c07190cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07190e;
P_0c07190e: /* original 6eb3, guest PC 0x0c07190e */
if(!s->budget--) { s->failed_pc=0x0c07190eu; return 0; }
r[14]=r[11];
goto P_0c071910;
P_0c071910: /* original 7218, guest PC 0x0c071910 */
if(!s->budget--) { s->failed_pc=0x0c071910u; return 0; }
r[2]+=0x00000018u;
goto P_0c071912;
P_0c071912: /* original 2f22, guest PC 0x0c071912 */
if(!s->budget--) { s->failed_pc=0x0c071912u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c071914;
P_0c071914: /* original 53f3, guest PC 0x0c071914 */
if(!s->budget--) { s->failed_pc=0x0c071914u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c071916;
P_0c071916: /* original 73ff, guest PC 0x0c071916 */
if(!s->budget--) { s->failed_pc=0x0c071916u; return 0; }
r[3]+=0xffffffffu;
goto P_0c071918;
P_0c071918: /* original 1f34, guest PC 0x0c071918 */
if(!s->budget--) { s->failed_pc=0x0c071918u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c07191a;
P_0c07191a: /* original 1f13, guest PC 0x0c07191a */
if(!s->budget--) { s->failed_pc=0x0c07191au; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c07191c;
P_0c07191c: /* original d103, guest PC 0x0c07191c */
if(!s->budget--) { s->failed_pc=0x0c07191cu; return 0; }
r[1]=read(ram,0x0c07192cu,4);
goto P_0c07191e;
P_0c07191e: /* original 412b, guest PC 0x0c07191e */
if(!s->budget--) { s->failed_pc=0x0c07191eu; return 0; }
target=r[1];
r[11]+=0x00000018u;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c071920: /* original 7b18, guest PC 0x0c071920 */
if(!s->budget--) { s->failed_pc=0x0c071920u; return 0; }
r[11]+=0x00000018u;
return vf3_matrix_family(0x0c071922u,s,ram);
P_0c071a32: /* original f40b, guest PC 0x0c071a32 */
if(!s->budget--) { s->failed_pc=0x0c071a32u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071a34;
P_0c071a34: /* original 65f3, guest PC 0x0c071a34 */
if(!s->budget--) { s->failed_pc=0x0c071a34u; return 0; }
r[5]=r[15];
goto P_0c071a36;
P_0c071a36: /* original 64e3, guest PC 0x0c071a36 */
if(!s->budget--) { s->failed_pc=0x0c071a36u; return 0; }
r[4]=r[14];
goto P_0c071a38;
P_0c071a38: /* original 66f3, guest PC 0x0c071a38 */
if(!s->budget--) { s->failed_pc=0x0c071a38u; return 0; }
r[6]=r[15];
goto P_0c071a3a;
P_0c071a3a: /* original 740c, guest PC 0x0c071a3a */
if(!s->budget--) { s->failed_pc=0x0c071a3au; return 0; }
r[4]+=0x0000000cu;
goto P_0c071a3c;
P_0c071a3c: /* original 7618, guest PC 0x0c071a3c */
if(!s->budget--) { s->failed_pc=0x0c071a3cu; return 0; }
r[6]+=0x00000018u;
goto P_0c071a3e;
P_0c071a3e: /* original 7524, guest PC 0x0c071a3e */
if(!s->budget--) { s->failed_pc=0x0c071a3eu; return 0; }
r[5]+=0x00000024u;
goto P_0c071a40;
P_0c071a40: /* original f059, guest PC 0x0c071a40 */
if(!s->budget--) { s->failed_pc=0x0c071a40u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071a42;
P_0c071a42: /* original f369, guest PC 0x0c071a42 */
if(!s->budget--) { s->failed_pc=0x0c071a42u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071a44;
P_0c071a44: /* original f159, guest PC 0x0c071a44 */
if(!s->budget--) { s->failed_pc=0x0c071a44u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071a46;
P_0c071a46: /* original f469, guest PC 0x0c071a46 */
if(!s->budget--) { s->failed_pc=0x0c071a46u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071a48;
P_0c071a48: /* original f259, guest PC 0x0c071a48 */
if(!s->budget--) { s->failed_pc=0x0c071a48u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071a4a;
P_0c071a4a: /* original f569, guest PC 0x0c071a4a */
if(!s->budget--) { s->failed_pc=0x0c071a4au; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071a4c;
P_0c071a4c: /* original 740c, guest PC 0x0c071a4c */
if(!s->budget--) { s->failed_pc=0x0c071a4cu; return 0; }
r[4]+=0x0000000cu;
goto P_0c071a4e;
P_0c071a4e: /* original f030, guest PC 0x0c071a4e */
if(!s->budget--) { s->failed_pc=0x0c071a4eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c071a50;
P_0c071a50: /* original f250, guest PC 0x0c071a50 */
if(!s->budget--) { s->failed_pc=0x0c071a50u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c071a52;
P_0c071a52: /* original f140, guest PC 0x0c071a52 */
if(!s->budget--) { s->failed_pc=0x0c071a52u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071a54;
P_0c071a54: /* original f42b, guest PC 0x0c071a54 */
if(!s->budget--) { s->failed_pc=0x0c071a54u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071a56;
P_0c071a56: /* original f41b, guest PC 0x0c071a56 */
if(!s->budget--) { s->failed_pc=0x0c071a56u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071a58;
P_0c071a58: /* original f40b, guest PC 0x0c071a58 */
if(!s->budget--) { s->failed_pc=0x0c071a58u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071a5a;
P_0c071a5a: /* original 0009, guest PC 0x0c071a5a */
if(!s->budget--) { s->failed_pc=0x0c071a5au; return 0; }
goto P_0c071a5c;
P_0c071a5c: /* original 64e3, guest PC 0x0c071a5c */
if(!s->budget--) { s->failed_pc=0x0c071a5cu; return 0; }
r[4]=r[14];
goto P_0c071a5e;
P_0c071a5e: /* original 740c, guest PC 0x0c071a5e */
if(!s->budget--) { s->failed_pc=0x0c071a5eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c071a60;
P_0c071a60: /* original f049, guest PC 0x0c071a60 */
if(!s->budget--) { s->failed_pc=0x0c071a60u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071a62;
P_0c071a62: /* original f149, guest PC 0x0c071a62 */
if(!s->budget--) { s->failed_pc=0x0c071a62u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071a64;
P_0c071a64: /* original f249, guest PC 0x0c071a64 */
if(!s->budget--) { s->failed_pc=0x0c071a64u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071a66;
P_0c071a66: /* original f38d, guest PC 0x0c071a66 */
if(!s->budget--) { s->failed_pc=0x0c071a66u; return 0; }
fr[3]=0;
goto P_0c071a68;
P_0c071a68: /* original f0ed, guest PC 0x0c071a68 */
if(!s->budget--) { s->failed_pc=0x0c071a68u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071a6a;
P_0c071a6a: /* original f37d, guest PC 0x0c071a6a */
if(!s->budget--) { s->failed_pc=0x0c071a6au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071a6c;
P_0c071a6c: /* original f232, guest PC 0x0c071a6c */
if(!s->budget--) { s->failed_pc=0x0c071a6cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071a6e;
P_0c071a6e: /* original f132, guest PC 0x0c071a6e */
if(!s->budget--) { s->failed_pc=0x0c071a6eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071a70;
P_0c071a70: /* original f032, guest PC 0x0c071a70 */
if(!s->budget--) { s->failed_pc=0x0c071a70u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071a72;
P_0c071a72: /* original f42b, guest PC 0x0c071a72 */
if(!s->budget--) { s->failed_pc=0x0c071a72u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071a74;
P_0c071a74: /* original f41b, guest PC 0x0c071a74 */
if(!s->budget--) { s->failed_pc=0x0c071a74u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071a76;
P_0c071a76: /* original f40b, guest PC 0x0c071a76 */
if(!s->budget--) { s->failed_pc=0x0c071a76u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071a78;
P_0c071a78: /* original 1fe1, guest PC 0x0c071a78 */
if(!s->budget--) { s->failed_pc=0x0c071a78u; return 0; }
write(ram,r[15]+4,r[14],4);
goto P_0c071a7a;
P_0c071a7a: /* original 6eb3, guest PC 0x0c071a7a */
if(!s->budget--) { s->failed_pc=0x0c071a7au; return 0; }
r[14]=r[11];
goto P_0c071a7c;
P_0c071a7c: /* original 63f2, guest PC 0x0c071a7c */
if(!s->budget--) { s->failed_pc=0x0c071a7cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c071a7e;
P_0c071a7e: /* original 7b18, guest PC 0x0c071a7e */
if(!s->budget--) { s->failed_pc=0x0c071a7eu; return 0; }
r[11]+=0x00000018u;
goto P_0c071a80;
P_0c071a80: /* original 7318, guest PC 0x0c071a80 */
if(!s->budget--) { s->failed_pc=0x0c071a80u; return 0; }
r[3]+=0x00000018u;
goto P_0c071a82;
P_0c071a82: /* original 2f32, guest PC 0x0c071a82 */
if(!s->budget--) { s->failed_pc=0x0c071a82u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c071a84;
P_0c071a84: /* original 52f5, guest PC 0x0c071a84 */
if(!s->budget--) { s->failed_pc=0x0c071a84u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c071a86;
P_0c071a86: /* original 6123, guest PC 0x0c071a86 */
if(!s->budget--) { s->failed_pc=0x0c071a86u; return 0; }
r[1]=r[2];
goto P_0c071a88;
P_0c071a88: /* original 3197, guest PC 0x0c071a88 */
if(!s->budget--) { s->failed_pc=0x0c071a88u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[9])!=0);
goto P_0c071a8a;
P_0c071a8a: /* original 1f22, guest PC 0x0c071a8a */
if(!s->budget--) { s->failed_pc=0x0c071a8au; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c071a8c;
P_0c071a8c: /* original 8d03, guest PC 0x0c071a8c */
if(!s->budget--) { s->failed_pc=0x0c071a8cu; return 0; }
cond=r[17]&1u;
r[8]+=0x00000018u;
if(cond) { goto P_0c071a96; }
goto P_0c071a90;
P_0c071a8e: /* original 7818, guest PC 0x0c071a8e */
if(!s->budget--) { s->failed_pc=0x0c071a8eu; return 0; }
r[8]+=0x00000018u;
goto P_0c071a90;
P_0c071a90: /* original d203, guest PC 0x0c071a90 */
if(!s->budget--) { s->failed_pc=0x0c071a90u; return 0; }
r[2]=read(ram,0x0c071aa0u,4);
goto P_0c071a92;
P_0c071a92: /* original 422b, guest PC 0x0c071a92 */
if(!s->budget--) { s->failed_pc=0x0c071a92u; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c071a94: /* original 0009, guest PC 0x0c071a94 */
if(!s->budget--) { s->failed_pc=0x0c071a94u; return 0; }
goto P_0c071a96;
P_0c071a96: /* original 55f1, guest PC 0x0c071a96 */
if(!s->budget--) { s->failed_pc=0x0c071a96u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c071a98;
P_0c071a98: /* original 64d3, guest PC 0x0c071a98 */
if(!s->budget--) { s->failed_pc=0x0c071a98u; return 0; }
r[4]=r[13];
goto P_0c071a9a;
P_0c071a9a: /* original 66e3, guest PC 0x0c071a9a */
if(!s->budget--) { s->failed_pc=0x0c071a9au; return 0; }
r[6]=r[14];
goto P_0c071a9c;
P_0c071a9c: /* original a002, guest PC 0x0c071a9c */
if(!s->budget--) { s->failed_pc=0x0c071a9cu; return 0; }
goto P_0c071aa4;
P_0c071a9e: /* original 0009, guest PC 0x0c071a9e */
if(!s->budget--) { s->failed_pc=0x0c071a9eu; return 0; }
return vf3_matrix_family(0x0c071aa0u,s,ram);
P_0c071aa4: /* original f059, guest PC 0x0c071aa4 */
if(!s->budget--) { s->failed_pc=0x0c071aa4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071aa6;
P_0c071aa6: /* original f369, guest PC 0x0c071aa6 */
if(!s->budget--) { s->failed_pc=0x0c071aa6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071aa8;
P_0c071aa8: /* original f159, guest PC 0x0c071aa8 */
if(!s->budget--) { s->failed_pc=0x0c071aa8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071aaa;
P_0c071aaa: /* original f469, guest PC 0x0c071aaa */
if(!s->budget--) { s->failed_pc=0x0c071aaau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071aac;
P_0c071aac: /* original f031, guest PC 0x0c071aac */
if(!s->budget--) { s->failed_pc=0x0c071aacu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071aae;
P_0c071aae: /* original f258, guest PC 0x0c071aae */
if(!s->budget--) { s->failed_pc=0x0c071aaeu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071ab0;
P_0c071ab0: /* original f568, guest PC 0x0c071ab0 */
if(!s->budget--) { s->failed_pc=0x0c071ab0u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071ab2;
P_0c071ab2: /* original f141, guest PC 0x0c071ab2 */
if(!s->budget--) { s->failed_pc=0x0c071ab2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071ab4;
P_0c071ab4: /* original f251, guest PC 0x0c071ab4 */
if(!s->budget--) { s->failed_pc=0x0c071ab4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071ab6;
P_0c071ab6: /* original 7408, guest PC 0x0c071ab6 */
if(!s->budget--) { s->failed_pc=0x0c071ab6u; return 0; }
r[4]+=0x00000008u;
goto P_0c071ab8;
P_0c071ab8: /* original f42a, guest PC 0x0c071ab8 */
if(!s->budget--) { s->failed_pc=0x0c071ab8u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071aba;
P_0c071aba: /* original f41b, guest PC 0x0c071aba */
if(!s->budget--) { s->failed_pc=0x0c071abau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071abc;
P_0c071abc: /* original f40b, guest PC 0x0c071abc */
if(!s->budget--) { s->failed_pc=0x0c071abcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071abe;
P_0c071abe: /* original 0009, guest PC 0x0c071abe */
if(!s->budget--) { s->failed_pc=0x0c071abeu; return 0; }
goto P_0c071ac0;
P_0c071ac0: /* original 64a3, guest PC 0x0c071ac0 */
if(!s->budget--) { s->failed_pc=0x0c071ac0u; return 0; }
r[4]=r[10];
goto P_0c071ac2;
P_0c071ac2: /* original 65b3, guest PC 0x0c071ac2 */
if(!s->budget--) { s->failed_pc=0x0c071ac2u; return 0; }
r[5]=r[11];
goto P_0c071ac4;
P_0c071ac4: /* original 66e3, guest PC 0x0c071ac4 */
if(!s->budget--) { s->failed_pc=0x0c071ac4u; return 0; }
r[6]=r[14];
goto P_0c071ac6;
P_0c071ac6: /* original f059, guest PC 0x0c071ac6 */
if(!s->budget--) { s->failed_pc=0x0c071ac6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ac8;
P_0c071ac8: /* original f369, guest PC 0x0c071ac8 */
if(!s->budget--) { s->failed_pc=0x0c071ac8u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071aca;
P_0c071aca: /* original f159, guest PC 0x0c071aca */
if(!s->budget--) { s->failed_pc=0x0c071acau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071acc;
P_0c071acc: /* original f469, guest PC 0x0c071acc */
if(!s->budget--) { s->failed_pc=0x0c071accu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071ace;
P_0c071ace: /* original f031, guest PC 0x0c071ace */
if(!s->budget--) { s->failed_pc=0x0c071aceu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071ad0;
P_0c071ad0: /* original f258, guest PC 0x0c071ad0 */
if(!s->budget--) { s->failed_pc=0x0c071ad0u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071ad2;
P_0c071ad2: /* original f568, guest PC 0x0c071ad2 */
if(!s->budget--) { s->failed_pc=0x0c071ad2u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071ad4;
P_0c071ad4: /* original f141, guest PC 0x0c071ad4 */
if(!s->budget--) { s->failed_pc=0x0c071ad4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071ad6;
P_0c071ad6: /* original f251, guest PC 0x0c071ad6 */
if(!s->budget--) { s->failed_pc=0x0c071ad6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071ad8;
P_0c071ad8: /* original 7408, guest PC 0x0c071ad8 */
if(!s->budget--) { s->failed_pc=0x0c071ad8u; return 0; }
r[4]+=0x00000008u;
goto P_0c071ada;
P_0c071ada: /* original f42a, guest PC 0x0c071ada */
if(!s->budget--) { s->failed_pc=0x0c071adau; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071adc;
P_0c071adc: /* original f41b, guest PC 0x0c071adc */
if(!s->budget--) { s->failed_pc=0x0c071adcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071ade;
P_0c071ade: /* original f40b, guest PC 0x0c071ade */
if(!s->budget--) { s->failed_pc=0x0c071adeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071ae0;
P_0c071ae0: /* original 65f2, guest PC 0x0c071ae0 */
if(!s->budget--) { s->failed_pc=0x0c071ae0u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c071ae2;
P_0c071ae2: /* original 64c3, guest PC 0x0c071ae2 */
if(!s->budget--) { s->failed_pc=0x0c071ae2u; return 0; }
r[4]=r[12];
goto P_0c071ae4;
P_0c071ae4: /* original 66e3, guest PC 0x0c071ae4 */
if(!s->budget--) { s->failed_pc=0x0c071ae4u; return 0; }
r[6]=r[14];
goto P_0c071ae6;
P_0c071ae6: /* original f059, guest PC 0x0c071ae6 */
if(!s->budget--) { s->failed_pc=0x0c071ae6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ae8;
P_0c071ae8: /* original f369, guest PC 0x0c071ae8 */
if(!s->budget--) { s->failed_pc=0x0c071ae8u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071aea;
P_0c071aea: /* original f159, guest PC 0x0c071aea */
if(!s->budget--) { s->failed_pc=0x0c071aeau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071aec;
P_0c071aec: /* original f469, guest PC 0x0c071aec */
if(!s->budget--) { s->failed_pc=0x0c071aecu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071aee;
P_0c071aee: /* original f031, guest PC 0x0c071aee */
if(!s->budget--) { s->failed_pc=0x0c071aeeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071af0;
P_0c071af0: /* original f258, guest PC 0x0c071af0 */
if(!s->budget--) { s->failed_pc=0x0c071af0u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071af2;
P_0c071af2: /* original f568, guest PC 0x0c071af2 */
if(!s->budget--) { s->failed_pc=0x0c071af2u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071af4;
P_0c071af4: /* original f141, guest PC 0x0c071af4 */
if(!s->budget--) { s->failed_pc=0x0c071af4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071af6;
P_0c071af6: /* original f251, guest PC 0x0c071af6 */
if(!s->budget--) { s->failed_pc=0x0c071af6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071af8;
P_0c071af8: /* original 7408, guest PC 0x0c071af8 */
if(!s->budget--) { s->failed_pc=0x0c071af8u; return 0; }
r[4]+=0x00000008u;
goto P_0c071afa;
P_0c071afa: /* original f42a, guest PC 0x0c071afa */
if(!s->budget--) { s->failed_pc=0x0c071afau; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071afc;
P_0c071afc: /* original f41b, guest PC 0x0c071afc */
if(!s->budget--) { s->failed_pc=0x0c071afcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071afe;
P_0c071afe: /* original f40b, guest PC 0x0c071afe */
if(!s->budget--) { s->failed_pc=0x0c071afeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071b00;
P_0c071b00: /* original 54f3, guest PC 0x0c071b00 */
if(!s->budget--) { s->failed_pc=0x0c071b00u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c071b02;
P_0c071b02: /* original 6583, guest PC 0x0c071b02 */
if(!s->budget--) { s->failed_pc=0x0c071b02u; return 0; }
r[5]=r[8];
goto P_0c071b04;
P_0c071b04: /* original 66e3, guest PC 0x0c071b04 */
if(!s->budget--) { s->failed_pc=0x0c071b04u; return 0; }
r[6]=r[14];
goto P_0c071b06;
P_0c071b06: /* original f059, guest PC 0x0c071b06 */
if(!s->budget--) { s->failed_pc=0x0c071b06u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071b08;
P_0c071b08: /* original f369, guest PC 0x0c071b08 */
if(!s->budget--) { s->failed_pc=0x0c071b08u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071b0a;
P_0c071b0a: /* original f159, guest PC 0x0c071b0a */
if(!s->budget--) { s->failed_pc=0x0c071b0au; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071b0c;
P_0c071b0c: /* original f469, guest PC 0x0c071b0c */
if(!s->budget--) { s->failed_pc=0x0c071b0cu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071b0e;
P_0c071b0e: /* original f031, guest PC 0x0c071b0e */
if(!s->budget--) { s->failed_pc=0x0c071b0eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071b10;
P_0c071b10: /* original f258, guest PC 0x0c071b10 */
if(!s->budget--) { s->failed_pc=0x0c071b10u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071b12;
P_0c071b12: /* original f568, guest PC 0x0c071b12 */
if(!s->budget--) { s->failed_pc=0x0c071b12u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071b14;
P_0c071b14: /* original f141, guest PC 0x0c071b14 */
if(!s->budget--) { s->failed_pc=0x0c071b14u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071b16;
P_0c071b16: /* original f251, guest PC 0x0c071b16 */
if(!s->budget--) { s->failed_pc=0x0c071b16u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071b18;
P_0c071b18: /* original 7408, guest PC 0x0c071b18 */
if(!s->budget--) { s->failed_pc=0x0c071b18u; return 0; }
r[4]+=0x00000008u;
goto P_0c071b1a;
P_0c071b1a: /* original f42a, guest PC 0x0c071b1a */
if(!s->budget--) { s->failed_pc=0x0c071b1au; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071b1c;
P_0c071b1c: /* original f41b, guest PC 0x0c071b1c */
if(!s->budget--) { s->failed_pc=0x0c071b1cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071b1e;
P_0c071b1e: /* original f40b, guest PC 0x0c071b1e */
if(!s->budget--) { s->failed_pc=0x0c071b1eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071b20;
P_0c071b20: /* original 66f3, guest PC 0x0c071b20 */
if(!s->budget--) { s->failed_pc=0x0c071b20u; return 0; }
r[6]=r[15];
goto P_0c071b22;
P_0c071b22: /* original 64c3, guest PC 0x0c071b22 */
if(!s->budget--) { s->failed_pc=0x0c071b22u; return 0; }
r[4]=r[12];
goto P_0c071b24;
P_0c071b24: /* original 65d3, guest PC 0x0c071b24 */
if(!s->budget--) { s->failed_pc=0x0c071b24u; return 0; }
r[5]=r[13];
goto P_0c071b26;
P_0c071b26: /* original 7624, guest PC 0x0c071b26 */
if(!s->budget--) { s->failed_pc=0x0c071b26u; return 0; }
r[6]+=0x00000024u;
goto P_0c071b28;
P_0c071b28: /* original f049, guest PC 0x0c071b28 */
if(!s->budget--) { s->failed_pc=0x0c071b28u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071b2a;
P_0c071b2a: /* original f549, guest PC 0x0c071b2a */
if(!s->budget--) { s->failed_pc=0x0c071b2au; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071b2c;
P_0c071b2c: /* original f648, guest PC 0x0c071b2c */
if(!s->budget--) { s->failed_pc=0x0c071b2cu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c071b2e;
P_0c071b2e: /* original f859, guest PC 0x0c071b2e */
if(!s->budget--) { s->failed_pc=0x0c071b2eu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071b30;
P_0c071b30: /* original f959, guest PC 0x0c071b30 */
if(!s->budget--) { s->failed_pc=0x0c071b30u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071b32;
P_0c071b32: /* original fa58, guest PC 0x0c071b32 */
if(!s->budget--) { s->failed_pc=0x0c071b32u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c071b34;
P_0c071b34: /* original 760c, guest PC 0x0c071b34 */
if(!s->budget--) { s->failed_pc=0x0c071b34u; return 0; }
r[6]+=0x0000000cu;
goto P_0c071b36;
P_0c071b36: /* original f35c, guest PC 0x0c071b36 */
if(!s->budget--) { s->failed_pc=0x0c071b36u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c071b38;
P_0c071b38: /* original f382, guest PC 0x0c071b38 */
if(!s->budget--) { s->failed_pc=0x0c071b38u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c071b3a;
P_0c071b3a: /* original f20c, guest PC 0x0c071b3a */
if(!s->budget--) { s->failed_pc=0x0c071b3au; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c071b3c;
P_0c071b3c: /* original f2a2, guest PC 0x0c071b3c */
if(!s->budget--) { s->failed_pc=0x0c071b3cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c071b3e;
P_0c071b3e: /* original f16c, guest PC 0x0c071b3e */
if(!s->budget--) { s->failed_pc=0x0c071b3eu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c071b40;
P_0c071b40: /* original f192, guest PC 0x0c071b40 */
if(!s->budget--) { s->failed_pc=0x0c071b40u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c071b42;
P_0c071b42: /* original f34d, guest PC 0x0c071b42 */
if(!s->budget--) { s->failed_pc=0x0c071b42u; return 0; }
fr[3]^=0x80000000u;
goto P_0c071b44;
P_0c071b44: /* original f39e, guest PC 0x0c071b44 */
if(!s->budget--) { s->failed_pc=0x0c071b44u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071b46;
P_0c071b46: /* original f24d, guest PC 0x0c071b46 */
if(!s->budget--) { s->failed_pc=0x0c071b46u; return 0; }
fr[2]^=0x80000000u;
goto P_0c071b48;
P_0c071b48: /* original f06c, guest PC 0x0c071b48 */
if(!s->budget--) { s->failed_pc=0x0c071b48u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c071b4a;
P_0c071b4a: /* original f28e, guest PC 0x0c071b4a */
if(!s->budget--) { s->failed_pc=0x0c071b4au; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c071b4c;
P_0c071b4c: /* original f14d, guest PC 0x0c071b4c */
if(!s->budget--) { s->failed_pc=0x0c071b4cu; return 0; }
fr[1]^=0x80000000u;
goto P_0c071b4e;
P_0c071b4e: /* original f63b, guest PC 0x0c071b4e */
if(!s->budget--) { s->failed_pc=0x0c071b4eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c071b50;
P_0c071b50: /* original f05c, guest PC 0x0c071b50 */
if(!s->budget--) { s->failed_pc=0x0c071b50u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c071b52;
P_0c071b52: /* original f1ae, guest PC 0x0c071b52 */
if(!s->budget--) { s->failed_pc=0x0c071b52u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c071b54;
P_0c071b54: /* original f62b, guest PC 0x0c071b54 */
if(!s->budget--) { s->failed_pc=0x0c071b54u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c071b56;
P_0c071b56: /* original f61b, guest PC 0x0c071b56 */
if(!s->budget--) { s->failed_pc=0x0c071b56u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c071b58;
P_0c071b58: /* original 54f3, guest PC 0x0c071b58 */
if(!s->budget--) { s->failed_pc=0x0c071b58u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c071b5a;
P_0c071b5a: /* original 66f3, guest PC 0x0c071b5a */
if(!s->budget--) { s->failed_pc=0x0c071b5au; return 0; }
r[6]=r[15];
goto P_0c071b5c;
P_0c071b5c: /* original 65a3, guest PC 0x0c071b5c */
if(!s->budget--) { s->failed_pc=0x0c071b5cu; return 0; }
r[5]=r[10];
goto P_0c071b5e;
P_0c071b5e: /* original 7618, guest PC 0x0c071b5e */
if(!s->budget--) { s->failed_pc=0x0c071b5eu; return 0; }
r[6]+=0x00000018u;
goto P_0c071b60;
P_0c071b60: /* original f049, guest PC 0x0c071b60 */
if(!s->budget--) { s->failed_pc=0x0c071b60u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071b62;
P_0c071b62: /* original f549, guest PC 0x0c071b62 */
if(!s->budget--) { s->failed_pc=0x0c071b62u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071b64;
P_0c071b64: /* original f648, guest PC 0x0c071b64 */
if(!s->budget--) { s->failed_pc=0x0c071b64u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c071b66;
P_0c071b66: /* original f859, guest PC 0x0c071b66 */
if(!s->budget--) { s->failed_pc=0x0c071b66u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071b68;
P_0c071b68: /* original f959, guest PC 0x0c071b68 */
if(!s->budget--) { s->failed_pc=0x0c071b68u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071b6a;
P_0c071b6a: /* original fa58, guest PC 0x0c071b6a */
if(!s->budget--) { s->failed_pc=0x0c071b6au; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c071b6c;
P_0c071b6c: /* original 760c, guest PC 0x0c071b6c */
if(!s->budget--) { s->failed_pc=0x0c071b6cu; return 0; }
r[6]+=0x0000000cu;
goto P_0c071b6e;
P_0c071b6e: /* original f35c, guest PC 0x0c071b6e */
if(!s->budget--) { s->failed_pc=0x0c071b6eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c071b70;
P_0c071b70: /* original f382, guest PC 0x0c071b70 */
if(!s->budget--) { s->failed_pc=0x0c071b70u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c071b72;
P_0c071b72: /* original f20c, guest PC 0x0c071b72 */
if(!s->budget--) { s->failed_pc=0x0c071b72u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c071b74;
P_0c071b74: /* original f2a2, guest PC 0x0c071b74 */
if(!s->budget--) { s->failed_pc=0x0c071b74u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c071b76;
P_0c071b76: /* original f16c, guest PC 0x0c071b76 */
if(!s->budget--) { s->failed_pc=0x0c071b76u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c071b78;
P_0c071b78: /* original f192, guest PC 0x0c071b78 */
if(!s->budget--) { s->failed_pc=0x0c071b78u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c071b7a;
P_0c071b7a: /* original f34d, guest PC 0x0c071b7a */
if(!s->budget--) { s->failed_pc=0x0c071b7au; return 0; }
fr[3]^=0x80000000u;
goto P_0c071b7c;
P_0c071b7c: /* original f39e, guest PC 0x0c071b7c */
if(!s->budget--) { s->failed_pc=0x0c071b7cu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071b7e;
P_0c071b7e: /* original f24d, guest PC 0x0c071b7e */
if(!s->budget--) { s->failed_pc=0x0c071b7eu; return 0; }
fr[2]^=0x80000000u;
goto P_0c071b80;
P_0c071b80: /* original f06c, guest PC 0x0c071b80 */
if(!s->budget--) { s->failed_pc=0x0c071b80u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c071b82;
P_0c071b82: /* original f28e, guest PC 0x0c071b82 */
if(!s->budget--) { s->failed_pc=0x0c071b82u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c071b84;
P_0c071b84: /* original f14d, guest PC 0x0c071b84 */
if(!s->budget--) { s->failed_pc=0x0c071b84u; return 0; }
fr[1]^=0x80000000u;
goto P_0c071b86;
P_0c071b86: /* original f63b, guest PC 0x0c071b86 */
if(!s->budget--) { s->failed_pc=0x0c071b86u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c071b88;
P_0c071b88: /* original f05c, guest PC 0x0c071b88 */
if(!s->budget--) { s->failed_pc=0x0c071b88u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c071b8a;
P_0c071b8a: /* original f1ae, guest PC 0x0c071b8a */
if(!s->budget--) { s->failed_pc=0x0c071b8au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c071b8c;
P_0c071b8c: /* original f62b, guest PC 0x0c071b8c */
if(!s->budget--) { s->failed_pc=0x0c071b8cu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c071b8e;
P_0c071b8e: /* original f61b, guest PC 0x0c071b8e */
if(!s->budget--) { s->failed_pc=0x0c071b8eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c071b90;
P_0c071b90: /* original 64f3, guest PC 0x0c071b90 */
if(!s->budget--) { s->failed_pc=0x0c071b90u; return 0; }
r[4]=r[15];
goto P_0c071b92;
P_0c071b92: /* original 7424, guest PC 0x0c071b92 */
if(!s->budget--) { s->failed_pc=0x0c071b92u; return 0; }
r[4]+=0x00000024u;
goto P_0c071b94;
P_0c071b94: /* original f049, guest PC 0x0c071b94 */
if(!s->budget--) { s->failed_pc=0x0c071b94u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071b96;
P_0c071b96: /* original f149, guest PC 0x0c071b96 */
if(!s->budget--) { s->failed_pc=0x0c071b96u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071b98;
P_0c071b98: /* original f249, guest PC 0x0c071b98 */
if(!s->budget--) { s->failed_pc=0x0c071b98u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071b9a;
P_0c071b9a: /* original f38d, guest PC 0x0c071b9a */
if(!s->budget--) { s->failed_pc=0x0c071b9au; return 0; }
fr[3]=0;
goto P_0c071b9c;
P_0c071b9c: /* original f0ed, guest PC 0x0c071b9c */
if(!s->budget--) { s->failed_pc=0x0c071b9cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071b9e;
P_0c071b9e: /* original f37d, guest PC 0x0c071b9e */
if(!s->budget--) { s->failed_pc=0x0c071b9eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071ba0;
P_0c071ba0: /* original f232, guest PC 0x0c071ba0 */
if(!s->budget--) { s->failed_pc=0x0c071ba0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071ba2;
P_0c071ba2: /* original f132, guest PC 0x0c071ba2 */
if(!s->budget--) { s->failed_pc=0x0c071ba2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071ba4;
P_0c071ba4: /* original f032, guest PC 0x0c071ba4 */
if(!s->budget--) { s->failed_pc=0x0c071ba4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071ba6;
P_0c071ba6: /* original f42b, guest PC 0x0c071ba6 */
if(!s->budget--) { s->failed_pc=0x0c071ba6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071ba8;
P_0c071ba8: /* original f41b, guest PC 0x0c071ba8 */
if(!s->budget--) { s->failed_pc=0x0c071ba8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071baa;
P_0c071baa: /* original f40b, guest PC 0x0c071baa */
if(!s->budget--) { s->failed_pc=0x0c071baau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071bac;
P_0c071bac: /* original 64f3, guest PC 0x0c071bac */
if(!s->budget--) { s->failed_pc=0x0c071bacu; return 0; }
r[4]=r[15];
goto P_0c071bae;
P_0c071bae: /* original 7418, guest PC 0x0c071bae */
if(!s->budget--) { s->failed_pc=0x0c071baeu; return 0; }
r[4]+=0x00000018u;
goto P_0c071bb0;
P_0c071bb0: /* original f049, guest PC 0x0c071bb0 */
if(!s->budget--) { s->failed_pc=0x0c071bb0u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071bb2;
P_0c071bb2: /* original f149, guest PC 0x0c071bb2 */
if(!s->budget--) { s->failed_pc=0x0c071bb2u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071bb4;
P_0c071bb4: /* original f249, guest PC 0x0c071bb4 */
if(!s->budget--) { s->failed_pc=0x0c071bb4u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071bb6;
P_0c071bb6: /* original f38d, guest PC 0x0c071bb6 */
if(!s->budget--) { s->failed_pc=0x0c071bb6u; return 0; }
fr[3]=0;
goto P_0c071bb8;
P_0c071bb8: /* original f0ed, guest PC 0x0c071bb8 */
if(!s->budget--) { s->failed_pc=0x0c071bb8u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071bba;
P_0c071bba: /* original f37d, guest PC 0x0c071bba */
if(!s->budget--) { s->failed_pc=0x0c071bbau; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071bbc;
P_0c071bbc: /* original f232, guest PC 0x0c071bbc */
if(!s->budget--) { s->failed_pc=0x0c071bbcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071bbe;
P_0c071bbe: /* original f132, guest PC 0x0c071bbe */
if(!s->budget--) { s->failed_pc=0x0c071bbeu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071bc0;
P_0c071bc0: /* original f032, guest PC 0x0c071bc0 */
if(!s->budget--) { s->failed_pc=0x0c071bc0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071bc2;
P_0c071bc2: /* original f42b, guest PC 0x0c071bc2 */
if(!s->budget--) { s->failed_pc=0x0c071bc2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071bc4;
P_0c071bc4: /* original f41b, guest PC 0x0c071bc4 */
if(!s->budget--) { s->failed_pc=0x0c071bc4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071bc6;
P_0c071bc6: /* original f40b, guest PC 0x0c071bc6 */
if(!s->budget--) { s->failed_pc=0x0c071bc6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071bc8;
P_0c071bc8: /* original 65f3, guest PC 0x0c071bc8 */
if(!s->budget--) { s->failed_pc=0x0c071bc8u; return 0; }
r[5]=r[15];
goto P_0c071bca;
P_0c071bca: /* original 64e3, guest PC 0x0c071bca */
if(!s->budget--) { s->failed_pc=0x0c071bcau; return 0; }
r[4]=r[14];
goto P_0c071bcc;
P_0c071bcc: /* original 66f3, guest PC 0x0c071bcc */
if(!s->budget--) { s->failed_pc=0x0c071bccu; return 0; }
r[6]=r[15];
goto P_0c071bce;
P_0c071bce: /* original 740c, guest PC 0x0c071bce */
if(!s->budget--) { s->failed_pc=0x0c071bceu; return 0; }
r[4]+=0x0000000cu;
goto P_0c071bd0;
P_0c071bd0: /* original 7618, guest PC 0x0c071bd0 */
if(!s->budget--) { s->failed_pc=0x0c071bd0u; return 0; }
r[6]+=0x00000018u;
goto P_0c071bd2;
P_0c071bd2: /* original 7524, guest PC 0x0c071bd2 */
if(!s->budget--) { s->failed_pc=0x0c071bd2u; return 0; }
r[5]+=0x00000024u;
goto P_0c071bd4;
P_0c071bd4: /* original f059, guest PC 0x0c071bd4 */
if(!s->budget--) { s->failed_pc=0x0c071bd4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071bd6;
P_0c071bd6: /* original f369, guest PC 0x0c071bd6 */
if(!s->budget--) { s->failed_pc=0x0c071bd6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071bd8;
P_0c071bd8: /* original f159, guest PC 0x0c071bd8 */
if(!s->budget--) { s->failed_pc=0x0c071bd8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071bda;
P_0c071bda: /* original f469, guest PC 0x0c071bda */
if(!s->budget--) { s->failed_pc=0x0c071bdau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071bdc;
P_0c071bdc: /* original f259, guest PC 0x0c071bdc */
if(!s->budget--) { s->failed_pc=0x0c071bdcu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071bde;
P_0c071bde: /* original f569, guest PC 0x0c071bde */
if(!s->budget--) { s->failed_pc=0x0c071bdeu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071be0;
P_0c071be0: /* original 740c, guest PC 0x0c071be0 */
if(!s->budget--) { s->failed_pc=0x0c071be0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071be2;
P_0c071be2: /* original f030, guest PC 0x0c071be2 */
if(!s->budget--) { s->failed_pc=0x0c071be2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c071be4;
P_0c071be4: /* original f250, guest PC 0x0c071be4 */
if(!s->budget--) { s->failed_pc=0x0c071be4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c071be6;
P_0c071be6: /* original f140, guest PC 0x0c071be6 */
if(!s->budget--) { s->failed_pc=0x0c071be6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071be8;
P_0c071be8: /* original f42b, guest PC 0x0c071be8 */
if(!s->budget--) { s->failed_pc=0x0c071be8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071bea;
P_0c071bea: /* original f41b, guest PC 0x0c071bea */
if(!s->budget--) { s->failed_pc=0x0c071beau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071bec;
P_0c071bec: /* original f40b, guest PC 0x0c071bec */
if(!s->budget--) { s->failed_pc=0x0c071becu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071bee;
P_0c071bee: /* original 0009, guest PC 0x0c071bee */
if(!s->budget--) { s->failed_pc=0x0c071beeu; return 0; }
goto P_0c071bf0;
P_0c071bf0: /* original 64e3, guest PC 0x0c071bf0 */
if(!s->budget--) { s->failed_pc=0x0c071bf0u; return 0; }
r[4]=r[14];
goto P_0c071bf2;
P_0c071bf2: /* original 740c, guest PC 0x0c071bf2 */
if(!s->budget--) { s->failed_pc=0x0c071bf2u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071bf4;
P_0c071bf4: /* original f049, guest PC 0x0c071bf4 */
if(!s->budget--) { s->failed_pc=0x0c071bf4u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071bf6;
P_0c071bf6: /* original f149, guest PC 0x0c071bf6 */
if(!s->budget--) { s->failed_pc=0x0c071bf6u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071bf8;
P_0c071bf8: /* original f249, guest PC 0x0c071bf8 */
if(!s->budget--) { s->failed_pc=0x0c071bf8u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071bfa;
P_0c071bfa: /* original f38d, guest PC 0x0c071bfa */
if(!s->budget--) { s->failed_pc=0x0c071bfau; return 0; }
fr[3]=0;
goto P_0c071bfc;
P_0c071bfc: /* original f0ed, guest PC 0x0c071bfc */
if(!s->budget--) { s->failed_pc=0x0c071bfcu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071bfe;
P_0c071bfe: /* original f37d, guest PC 0x0c071bfe */
if(!s->budget--) { s->failed_pc=0x0c071bfeu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071c00;
P_0c071c00: /* original f232, guest PC 0x0c071c00 */
if(!s->budget--) { s->failed_pc=0x0c071c00u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071c02;
P_0c071c02: /* original f132, guest PC 0x0c071c02 */
if(!s->budget--) { s->failed_pc=0x0c071c02u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071c04;
P_0c071c04: /* original f032, guest PC 0x0c071c04 */
if(!s->budget--) { s->failed_pc=0x0c071c04u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071c06;
P_0c071c06: /* original f42b, guest PC 0x0c071c06 */
if(!s->budget--) { s->failed_pc=0x0c071c06u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071c08;
P_0c071c08: /* original f41b, guest PC 0x0c071c08 */
if(!s->budget--) { s->failed_pc=0x0c071c08u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071c0a;
P_0c071c0a: /* original f40b, guest PC 0x0c071c0a */
if(!s->budget--) { s->failed_pc=0x0c071c0au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071c0c;
P_0c071c0c: /* original 1fe1, guest PC 0x0c071c0c */
if(!s->budget--) { s->failed_pc=0x0c071c0cu; return 0; }
write(ram,r[15]+4,r[14],4);
goto P_0c071c0e;
P_0c071c0e: /* original 6eb3, guest PC 0x0c071c0e */
if(!s->budget--) { s->failed_pc=0x0c071c0eu; return 0; }
r[14]=r[11];
goto P_0c071c10;
P_0c071c10: /* original 63f2, guest PC 0x0c071c10 */
if(!s->budget--) { s->failed_pc=0x0c071c10u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c071c12;
P_0c071c12: /* original 7b18, guest PC 0x0c071c12 */
if(!s->budget--) { s->failed_pc=0x0c071c12u; return 0; }
r[11]+=0x00000018u;
goto P_0c071c14;
P_0c071c14: /* original 7818, guest PC 0x0c071c14 */
if(!s->budget--) { s->failed_pc=0x0c071c14u; return 0; }
r[8]+=0x00000018u;
goto P_0c071c16;
P_0c071c16: /* original 7318, guest PC 0x0c071c16 */
if(!s->budget--) { s->failed_pc=0x0c071c16u; return 0; }
r[3]+=0x00000018u;
goto P_0c071c18;
P_0c071c18: /* original 2f32, guest PC 0x0c071c18 */
if(!s->budget--) { s->failed_pc=0x0c071c18u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c071c1a;
P_0c071c1a: /* original 52f2, guest PC 0x0c071c1a */
if(!s->budget--) { s->failed_pc=0x0c071c1au; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c071c1c;
P_0c071c1c: /* original 72ff, guest PC 0x0c071c1c */
if(!s->budget--) { s->failed_pc=0x0c071c1cu; return 0; }
r[2]+=0xffffffffu;
goto P_0c071c1e;
P_0c071c1e: /* original 3297, guest PC 0x0c071c1e */
if(!s->budget--) { s->failed_pc=0x0c071c1eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[9])!=0);
goto P_0c071c20;
P_0c071c20: /* original 8f03, guest PC 0x0c071c20 */
if(!s->budget--) { s->failed_pc=0x0c071c20u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[2],4);
if(!cond) { goto P_0c071c2a; }
goto P_0c071c24;
P_0c071c22: /* original 1f22, guest PC 0x0c071c22 */
if(!s->budget--) { s->failed_pc=0x0c071c22u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c071c24;
P_0c071c24: /* original d103, guest PC 0x0c071c24 */
if(!s->budget--) { s->failed_pc=0x0c071c24u; return 0; }
r[1]=read(ram,0x0c071c34u,4);
goto P_0c071c26;
P_0c071c26: /* original 412b, guest PC 0x0c071c26 */
if(!s->budget--) { s->failed_pc=0x0c071c26u; return 0; }
target=r[1];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c071c28: /* original 0009, guest PC 0x0c071c28 */
if(!s->budget--) { s->failed_pc=0x0c071c28u; return 0; }
goto P_0c071c2a;
P_0c071c2a: /* original 55f1, guest PC 0x0c071c2a */
if(!s->budget--) { s->failed_pc=0x0c071c2au; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c071c2c;
P_0c071c2c: /* original 64d3, guest PC 0x0c071c2c */
if(!s->budget--) { s->failed_pc=0x0c071c2cu; return 0; }
r[4]=r[13];
goto P_0c071c2e;
P_0c071c2e: /* original 66e3, guest PC 0x0c071c2e */
if(!s->budget--) { s->failed_pc=0x0c071c2eu; return 0; }
r[6]=r[14];
goto P_0c071c30;
P_0c071c30: /* original a002, guest PC 0x0c071c30 */
if(!s->budget--) { s->failed_pc=0x0c071c30u; return 0; }
goto P_0c071c38;
P_0c071c32: /* original 0009, guest PC 0x0c071c32 */
if(!s->budget--) { s->failed_pc=0x0c071c32u; return 0; }
return vf3_matrix_family(0x0c071c34u,s,ram);
P_0c071c38: /* original f059, guest PC 0x0c071c38 */
if(!s->budget--) { s->failed_pc=0x0c071c38u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071c3a;
P_0c071c3a: /* original f369, guest PC 0x0c071c3a */
if(!s->budget--) { s->failed_pc=0x0c071c3au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071c3c;
P_0c071c3c: /* original f159, guest PC 0x0c071c3c */
if(!s->budget--) { s->failed_pc=0x0c071c3cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071c3e;
P_0c071c3e: /* original f469, guest PC 0x0c071c3e */
if(!s->budget--) { s->failed_pc=0x0c071c3eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071c40;
P_0c071c40: /* original f031, guest PC 0x0c071c40 */
if(!s->budget--) { s->failed_pc=0x0c071c40u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071c42;
P_0c071c42: /* original f258, guest PC 0x0c071c42 */
if(!s->budget--) { s->failed_pc=0x0c071c42u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071c44;
P_0c071c44: /* original f568, guest PC 0x0c071c44 */
if(!s->budget--) { s->failed_pc=0x0c071c44u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071c46;
P_0c071c46: /* original f141, guest PC 0x0c071c46 */
if(!s->budget--) { s->failed_pc=0x0c071c46u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071c48;
P_0c071c48: /* original f251, guest PC 0x0c071c48 */
if(!s->budget--) { s->failed_pc=0x0c071c48u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071c4a;
P_0c071c4a: /* original 7408, guest PC 0x0c071c4a */
if(!s->budget--) { s->failed_pc=0x0c071c4au; return 0; }
r[4]+=0x00000008u;
goto P_0c071c4c;
P_0c071c4c: /* original f42a, guest PC 0x0c071c4c */
if(!s->budget--) { s->failed_pc=0x0c071c4cu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071c4e;
P_0c071c4e: /* original f41b, guest PC 0x0c071c4e */
if(!s->budget--) { s->failed_pc=0x0c071c4eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071c50;
P_0c071c50: /* original f40b, guest PC 0x0c071c50 */
if(!s->budget--) { s->failed_pc=0x0c071c50u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071c52;
P_0c071c52: /* original 0009, guest PC 0x0c071c52 */
if(!s->budget--) { s->failed_pc=0x0c071c52u; return 0; }
goto P_0c071c54;
P_0c071c54: /* original 65f2, guest PC 0x0c071c54 */
if(!s->budget--) { s->failed_pc=0x0c071c54u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c071c56;
P_0c071c56: /* original 64a3, guest PC 0x0c071c56 */
if(!s->budget--) { s->failed_pc=0x0c071c56u; return 0; }
r[4]=r[10];
goto P_0c071c58;
P_0c071c58: /* original 66e3, guest PC 0x0c071c58 */
if(!s->budget--) { s->failed_pc=0x0c071c58u; return 0; }
r[6]=r[14];
goto P_0c071c5a;
P_0c071c5a: /* original f059, guest PC 0x0c071c5a */
if(!s->budget--) { s->failed_pc=0x0c071c5au; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071c5c;
P_0c071c5c: /* original f369, guest PC 0x0c071c5c */
if(!s->budget--) { s->failed_pc=0x0c071c5cu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071c5e;
P_0c071c5e: /* original f159, guest PC 0x0c071c5e */
if(!s->budget--) { s->failed_pc=0x0c071c5eu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071c60;
P_0c071c60: /* original f469, guest PC 0x0c071c60 */
if(!s->budget--) { s->failed_pc=0x0c071c60u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071c62;
P_0c071c62: /* original f031, guest PC 0x0c071c62 */
if(!s->budget--) { s->failed_pc=0x0c071c62u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071c64;
P_0c071c64: /* original f258, guest PC 0x0c071c64 */
if(!s->budget--) { s->failed_pc=0x0c071c64u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071c66;
P_0c071c66: /* original f568, guest PC 0x0c071c66 */
if(!s->budget--) { s->failed_pc=0x0c071c66u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071c68;
P_0c071c68: /* original f141, guest PC 0x0c071c68 */
if(!s->budget--) { s->failed_pc=0x0c071c68u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071c6a;
P_0c071c6a: /* original f251, guest PC 0x0c071c6a */
if(!s->budget--) { s->failed_pc=0x0c071c6au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071c6c;
P_0c071c6c: /* original 7408, guest PC 0x0c071c6c */
if(!s->budget--) { s->failed_pc=0x0c071c6cu; return 0; }
r[4]+=0x00000008u;
goto P_0c071c6e;
P_0c071c6e: /* original f42a, guest PC 0x0c071c6e */
if(!s->budget--) { s->failed_pc=0x0c071c6eu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071c70;
P_0c071c70: /* original f41b, guest PC 0x0c071c70 */
if(!s->budget--) { s->failed_pc=0x0c071c70u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071c72;
P_0c071c72: /* original f40b, guest PC 0x0c071c72 */
if(!s->budget--) { s->failed_pc=0x0c071c72u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071c74;
P_0c071c74: /* original 64c3, guest PC 0x0c071c74 */
if(!s->budget--) { s->failed_pc=0x0c071c74u; return 0; }
r[4]=r[12];
goto P_0c071c76;
P_0c071c76: /* original 6583, guest PC 0x0c071c76 */
if(!s->budget--) { s->failed_pc=0x0c071c76u; return 0; }
r[5]=r[8];
goto P_0c071c78;
P_0c071c78: /* original 66e3, guest PC 0x0c071c78 */
if(!s->budget--) { s->failed_pc=0x0c071c78u; return 0; }
r[6]=r[14];
goto P_0c071c7a;
P_0c071c7a: /* original f059, guest PC 0x0c071c7a */
if(!s->budget--) { s->failed_pc=0x0c071c7au; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071c7c;
P_0c071c7c: /* original f369, guest PC 0x0c071c7c */
if(!s->budget--) { s->failed_pc=0x0c071c7cu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071c7e;
P_0c071c7e: /* original f159, guest PC 0x0c071c7e */
if(!s->budget--) { s->failed_pc=0x0c071c7eu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071c80;
P_0c071c80: /* original f469, guest PC 0x0c071c80 */
if(!s->budget--) { s->failed_pc=0x0c071c80u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071c82;
P_0c071c82: /* original f031, guest PC 0x0c071c82 */
if(!s->budget--) { s->failed_pc=0x0c071c82u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071c84;
P_0c071c84: /* original f258, guest PC 0x0c071c84 */
if(!s->budget--) { s->failed_pc=0x0c071c84u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071c86;
P_0c071c86: /* original f568, guest PC 0x0c071c86 */
if(!s->budget--) { s->failed_pc=0x0c071c86u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071c88;
P_0c071c88: /* original f141, guest PC 0x0c071c88 */
if(!s->budget--) { s->failed_pc=0x0c071c88u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071c8a;
P_0c071c8a: /* original f251, guest PC 0x0c071c8a */
if(!s->budget--) { s->failed_pc=0x0c071c8au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071c8c;
P_0c071c8c: /* original 7408, guest PC 0x0c071c8c */
if(!s->budget--) { s->failed_pc=0x0c071c8cu; return 0; }
r[4]+=0x00000008u;
goto P_0c071c8e;
P_0c071c8e: /* original f42a, guest PC 0x0c071c8e */
if(!s->budget--) { s->failed_pc=0x0c071c8eu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071c90;
P_0c071c90: /* original f41b, guest PC 0x0c071c90 */
if(!s->budget--) { s->failed_pc=0x0c071c90u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071c92;
P_0c071c92: /* original f40b, guest PC 0x0c071c92 */
if(!s->budget--) { s->failed_pc=0x0c071c92u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071c94;
P_0c071c94: /* original 66f3, guest PC 0x0c071c94 */
if(!s->budget--) { s->failed_pc=0x0c071c94u; return 0; }
r[6]=r[15];
goto P_0c071c96;
P_0c071c96: /* original 64d3, guest PC 0x0c071c96 */
if(!s->budget--) { s->failed_pc=0x0c071c96u; return 0; }
r[4]=r[13];
goto P_0c071c98;
P_0c071c98: /* original 65c3, guest PC 0x0c071c98 */
if(!s->budget--) { s->failed_pc=0x0c071c98u; return 0; }
r[5]=r[12];
goto P_0c071c9a;
P_0c071c9a: /* original 7624, guest PC 0x0c071c9a */
if(!s->budget--) { s->failed_pc=0x0c071c9au; return 0; }
r[6]+=0x00000024u;
goto P_0c071c9c;
P_0c071c9c: /* original f049, guest PC 0x0c071c9c */
if(!s->budget--) { s->failed_pc=0x0c071c9cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071c9e;
P_0c071c9e: /* original f549, guest PC 0x0c071c9e */
if(!s->budget--) { s->failed_pc=0x0c071c9eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071ca0;
P_0c071ca0: /* original f648, guest PC 0x0c071ca0 */
if(!s->budget--) { s->failed_pc=0x0c071ca0u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c071ca2;
P_0c071ca2: /* original f859, guest PC 0x0c071ca2 */
if(!s->budget--) { s->failed_pc=0x0c071ca2u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ca4;
P_0c071ca4: /* original f959, guest PC 0x0c071ca4 */
if(!s->budget--) { s->failed_pc=0x0c071ca4u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ca6;
P_0c071ca6: /* original fa58, guest PC 0x0c071ca6 */
if(!s->budget--) { s->failed_pc=0x0c071ca6u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c071ca8;
P_0c071ca8: /* original 760c, guest PC 0x0c071ca8 */
if(!s->budget--) { s->failed_pc=0x0c071ca8u; return 0; }
r[6]+=0x0000000cu;
goto P_0c071caa;
P_0c071caa: /* original f35c, guest PC 0x0c071caa */
if(!s->budget--) { s->failed_pc=0x0c071caau; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c071cac;
P_0c071cac: /* original f382, guest PC 0x0c071cac */
if(!s->budget--) { s->failed_pc=0x0c071cacu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c071cae;
P_0c071cae: /* original f20c, guest PC 0x0c071cae */
if(!s->budget--) { s->failed_pc=0x0c071caeu; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c071cb0;
P_0c071cb0: /* original f2a2, guest PC 0x0c071cb0 */
if(!s->budget--) { s->failed_pc=0x0c071cb0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c071cb2;
P_0c071cb2: /* original f16c, guest PC 0x0c071cb2 */
if(!s->budget--) { s->failed_pc=0x0c071cb2u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c071cb4;
P_0c071cb4: /* original f192, guest PC 0x0c071cb4 */
if(!s->budget--) { s->failed_pc=0x0c071cb4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c071cb6;
P_0c071cb6: /* original f34d, guest PC 0x0c071cb6 */
if(!s->budget--) { s->failed_pc=0x0c071cb6u; return 0; }
fr[3]^=0x80000000u;
goto P_0c071cb8;
P_0c071cb8: /* original f39e, guest PC 0x0c071cb8 */
if(!s->budget--) { s->failed_pc=0x0c071cb8u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071cba;
P_0c071cba: /* original f24d, guest PC 0x0c071cba */
if(!s->budget--) { s->failed_pc=0x0c071cbau; return 0; }
fr[2]^=0x80000000u;
goto P_0c071cbc;
P_0c071cbc: /* original f06c, guest PC 0x0c071cbc */
if(!s->budget--) { s->failed_pc=0x0c071cbcu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c071cbe;
P_0c071cbe: /* original f28e, guest PC 0x0c071cbe */
if(!s->budget--) { s->failed_pc=0x0c071cbeu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c071cc0;
P_0c071cc0: /* original f14d, guest PC 0x0c071cc0 */
if(!s->budget--) { s->failed_pc=0x0c071cc0u; return 0; }
fr[1]^=0x80000000u;
goto P_0c071cc2;
P_0c071cc2: /* original f63b, guest PC 0x0c071cc2 */
if(!s->budget--) { s->failed_pc=0x0c071cc2u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c071cc4;
P_0c071cc4: /* original f05c, guest PC 0x0c071cc4 */
if(!s->budget--) { s->failed_pc=0x0c071cc4u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c071cc6;
P_0c071cc6: /* original f1ae, guest PC 0x0c071cc6 */
if(!s->budget--) { s->failed_pc=0x0c071cc6u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c071cc8;
P_0c071cc8: /* original f62b, guest PC 0x0c071cc8 */
if(!s->budget--) { s->failed_pc=0x0c071cc8u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c071cca;
P_0c071cca: /* original f61b, guest PC 0x0c071cca */
if(!s->budget--) { s->failed_pc=0x0c071ccau; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c071ccc;
P_0c071ccc: /* original 66f3, guest PC 0x0c071ccc */
if(!s->budget--) { s->failed_pc=0x0c071cccu; return 0; }
r[6]=r[15];
goto P_0c071cce;
P_0c071cce: /* original 64a3, guest PC 0x0c071cce */
if(!s->budget--) { s->failed_pc=0x0c071cceu; return 0; }
r[4]=r[10];
goto P_0c071cd0;
P_0c071cd0: /* original 65d3, guest PC 0x0c071cd0 */
if(!s->budget--) { s->failed_pc=0x0c071cd0u; return 0; }
r[5]=r[13];
goto P_0c071cd2;
P_0c071cd2: /* original 7618, guest PC 0x0c071cd2 */
if(!s->budget--) { s->failed_pc=0x0c071cd2u; return 0; }
r[6]+=0x00000018u;
goto P_0c071cd4;
P_0c071cd4: /* original f049, guest PC 0x0c071cd4 */
if(!s->budget--) { s->failed_pc=0x0c071cd4u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071cd6;
P_0c071cd6: /* original f549, guest PC 0x0c071cd6 */
if(!s->budget--) { s->failed_pc=0x0c071cd6u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071cd8;
P_0c071cd8: /* original f648, guest PC 0x0c071cd8 */
if(!s->budget--) { s->failed_pc=0x0c071cd8u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c071cda;
P_0c071cda: /* original f859, guest PC 0x0c071cda */
if(!s->budget--) { s->failed_pc=0x0c071cdau; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071cdc;
P_0c071cdc: /* original f959, guest PC 0x0c071cdc */
if(!s->budget--) { s->failed_pc=0x0c071cdcu; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071cde;
P_0c071cde: /* original fa58, guest PC 0x0c071cde */
if(!s->budget--) { s->failed_pc=0x0c071cdeu; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c071ce0;
P_0c071ce0: /* original 760c, guest PC 0x0c071ce0 */
if(!s->budget--) { s->failed_pc=0x0c071ce0u; return 0; }
r[6]+=0x0000000cu;
goto P_0c071ce2;
P_0c071ce2: /* original f35c, guest PC 0x0c071ce2 */
if(!s->budget--) { s->failed_pc=0x0c071ce2u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c071ce4;
P_0c071ce4: /* original f382, guest PC 0x0c071ce4 */
if(!s->budget--) { s->failed_pc=0x0c071ce4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c071ce6;
P_0c071ce6: /* original f20c, guest PC 0x0c071ce6 */
if(!s->budget--) { s->failed_pc=0x0c071ce6u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c071ce8;
P_0c071ce8: /* original f2a2, guest PC 0x0c071ce8 */
if(!s->budget--) { s->failed_pc=0x0c071ce8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c071cea;
P_0c071cea: /* original f16c, guest PC 0x0c071cea */
if(!s->budget--) { s->failed_pc=0x0c071ceau; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c071cec;
P_0c071cec: /* original f192, guest PC 0x0c071cec */
if(!s->budget--) { s->failed_pc=0x0c071cecu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c071cee;
P_0c071cee: /* original f34d, guest PC 0x0c071cee */
if(!s->budget--) { s->failed_pc=0x0c071ceeu; return 0; }
fr[3]^=0x80000000u;
goto P_0c071cf0;
P_0c071cf0: /* original f39e, guest PC 0x0c071cf0 */
if(!s->budget--) { s->failed_pc=0x0c071cf0u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071cf2;
P_0c071cf2: /* original f24d, guest PC 0x0c071cf2 */
if(!s->budget--) { s->failed_pc=0x0c071cf2u; return 0; }
fr[2]^=0x80000000u;
goto P_0c071cf4;
P_0c071cf4: /* original f06c, guest PC 0x0c071cf4 */
if(!s->budget--) { s->failed_pc=0x0c071cf4u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c071cf6;
P_0c071cf6: /* original f28e, guest PC 0x0c071cf6 */
if(!s->budget--) { s->failed_pc=0x0c071cf6u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c071cf8;
P_0c071cf8: /* original f14d, guest PC 0x0c071cf8 */
if(!s->budget--) { s->failed_pc=0x0c071cf8u; return 0; }
fr[1]^=0x80000000u;
goto P_0c071cfa;
P_0c071cfa: /* original f63b, guest PC 0x0c071cfa */
if(!s->budget--) { s->failed_pc=0x0c071cfau; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c071cfc;
P_0c071cfc: /* original f05c, guest PC 0x0c071cfc */
if(!s->budget--) { s->failed_pc=0x0c071cfcu; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c071cfe;
P_0c071cfe: /* original f1ae, guest PC 0x0c071cfe */
if(!s->budget--) { s->failed_pc=0x0c071cfeu; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c071d00;
P_0c071d00: /* original f62b, guest PC 0x0c071d00 */
if(!s->budget--) { s->failed_pc=0x0c071d00u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c071d02;
P_0c071d02: /* original f61b, guest PC 0x0c071d02 */
if(!s->budget--) { s->failed_pc=0x0c071d02u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c071d04;
P_0c071d04: /* original 64f3, guest PC 0x0c071d04 */
if(!s->budget--) { s->failed_pc=0x0c071d04u; return 0; }
r[4]=r[15];
goto P_0c071d06;
P_0c071d06: /* original 7424, guest PC 0x0c071d06 */
if(!s->budget--) { s->failed_pc=0x0c071d06u; return 0; }
r[4]+=0x00000024u;
goto P_0c071d08;
P_0c071d08: /* original f049, guest PC 0x0c071d08 */
if(!s->budget--) { s->failed_pc=0x0c071d08u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071d0a;
P_0c071d0a: /* original f149, guest PC 0x0c071d0a */
if(!s->budget--) { s->failed_pc=0x0c071d0au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071d0c;
P_0c071d0c: /* original f249, guest PC 0x0c071d0c */
if(!s->budget--) { s->failed_pc=0x0c071d0cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071d0e;
P_0c071d0e: /* original f38d, guest PC 0x0c071d0e */
if(!s->budget--) { s->failed_pc=0x0c071d0eu; return 0; }
fr[3]=0;
goto P_0c071d10;
P_0c071d10: /* original f0ed, guest PC 0x0c071d10 */
if(!s->budget--) { s->failed_pc=0x0c071d10u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071d12;
P_0c071d12: /* original f37d, guest PC 0x0c071d12 */
if(!s->budget--) { s->failed_pc=0x0c071d12u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071d14;
P_0c071d14: /* original f232, guest PC 0x0c071d14 */
if(!s->budget--) { s->failed_pc=0x0c071d14u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071d16;
P_0c071d16: /* original f132, guest PC 0x0c071d16 */
if(!s->budget--) { s->failed_pc=0x0c071d16u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071d18;
P_0c071d18: /* original f032, guest PC 0x0c071d18 */
if(!s->budget--) { s->failed_pc=0x0c071d18u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071d1a;
P_0c071d1a: /* original f42b, guest PC 0x0c071d1a */
if(!s->budget--) { s->failed_pc=0x0c071d1au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071d1c;
P_0c071d1c: /* original f41b, guest PC 0x0c071d1c */
if(!s->budget--) { s->failed_pc=0x0c071d1cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071d1e;
P_0c071d1e: /* original f40b, guest PC 0x0c071d1e */
if(!s->budget--) { s->failed_pc=0x0c071d1eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071d20;
P_0c071d20: /* original 64f3, guest PC 0x0c071d20 */
if(!s->budget--) { s->failed_pc=0x0c071d20u; return 0; }
r[4]=r[15];
goto P_0c071d22;
P_0c071d22: /* original 7418, guest PC 0x0c071d22 */
if(!s->budget--) { s->failed_pc=0x0c071d22u; return 0; }
r[4]+=0x00000018u;
goto P_0c071d24;
P_0c071d24: /* original f049, guest PC 0x0c071d24 */
if(!s->budget--) { s->failed_pc=0x0c071d24u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071d26;
P_0c071d26: /* original f149, guest PC 0x0c071d26 */
if(!s->budget--) { s->failed_pc=0x0c071d26u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071d28;
P_0c071d28: /* original f249, guest PC 0x0c071d28 */
if(!s->budget--) { s->failed_pc=0x0c071d28u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071d2a;
P_0c071d2a: /* original f38d, guest PC 0x0c071d2a */
if(!s->budget--) { s->failed_pc=0x0c071d2au; return 0; }
fr[3]=0;
goto P_0c071d2c;
P_0c071d2c: /* original f0ed, guest PC 0x0c071d2c */
if(!s->budget--) { s->failed_pc=0x0c071d2cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071d2e;
P_0c071d2e: /* original f37d, guest PC 0x0c071d2e */
if(!s->budget--) { s->failed_pc=0x0c071d2eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071d30;
P_0c071d30: /* original f232, guest PC 0x0c071d30 */
if(!s->budget--) { s->failed_pc=0x0c071d30u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071d32;
P_0c071d32: /* original f132, guest PC 0x0c071d32 */
if(!s->budget--) { s->failed_pc=0x0c071d32u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071d34;
P_0c071d34: /* original f032, guest PC 0x0c071d34 */
if(!s->budget--) { s->failed_pc=0x0c071d34u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071d36;
P_0c071d36: /* original f42b, guest PC 0x0c071d36 */
if(!s->budget--) { s->failed_pc=0x0c071d36u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071d38;
P_0c071d38: /* original f41b, guest PC 0x0c071d38 */
if(!s->budget--) { s->failed_pc=0x0c071d38u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071d3a;
P_0c071d3a: /* original f40b, guest PC 0x0c071d3a */
if(!s->budget--) { s->failed_pc=0x0c071d3au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071d3c;
P_0c071d3c: /* original 65f3, guest PC 0x0c071d3c */
if(!s->budget--) { s->failed_pc=0x0c071d3cu; return 0; }
r[5]=r[15];
goto P_0c071d3e;
P_0c071d3e: /* original 64e3, guest PC 0x0c071d3e */
if(!s->budget--) { s->failed_pc=0x0c071d3eu; return 0; }
r[4]=r[14];
goto P_0c071d40;
P_0c071d40: /* original 66f3, guest PC 0x0c071d40 */
if(!s->budget--) { s->failed_pc=0x0c071d40u; return 0; }
r[6]=r[15];
goto P_0c071d42;
P_0c071d42: /* original 740c, guest PC 0x0c071d42 */
if(!s->budget--) { s->failed_pc=0x0c071d42u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071d44;
P_0c071d44: /* original 7618, guest PC 0x0c071d44 */
if(!s->budget--) { s->failed_pc=0x0c071d44u; return 0; }
r[6]+=0x00000018u;
goto P_0c071d46;
P_0c071d46: /* original 7524, guest PC 0x0c071d46 */
if(!s->budget--) { s->failed_pc=0x0c071d46u; return 0; }
r[5]+=0x00000024u;
goto P_0c071d48;
P_0c071d48: /* original f059, guest PC 0x0c071d48 */
if(!s->budget--) { s->failed_pc=0x0c071d48u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071d4a;
P_0c071d4a: /* original f369, guest PC 0x0c071d4a */
if(!s->budget--) { s->failed_pc=0x0c071d4au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071d4c;
P_0c071d4c: /* original f159, guest PC 0x0c071d4c */
if(!s->budget--) { s->failed_pc=0x0c071d4cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071d4e;
P_0c071d4e: /* original f469, guest PC 0x0c071d4e */
if(!s->budget--) { s->failed_pc=0x0c071d4eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071d50;
P_0c071d50: /* original f259, guest PC 0x0c071d50 */
if(!s->budget--) { s->failed_pc=0x0c071d50u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071d52;
P_0c071d52: /* original f569, guest PC 0x0c071d52 */
if(!s->budget--) { s->failed_pc=0x0c071d52u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071d54;
P_0c071d54: /* original 740c, guest PC 0x0c071d54 */
if(!s->budget--) { s->failed_pc=0x0c071d54u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071d56;
P_0c071d56: /* original f030, guest PC 0x0c071d56 */
if(!s->budget--) { s->failed_pc=0x0c071d56u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c071d58;
P_0c071d58: /* original f250, guest PC 0x0c071d58 */
if(!s->budget--) { s->failed_pc=0x0c071d58u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c071d5a;
P_0c071d5a: /* original f140, guest PC 0x0c071d5a */
if(!s->budget--) { s->failed_pc=0x0c071d5au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071d5c;
P_0c071d5c: /* original f42b, guest PC 0x0c071d5c */
if(!s->budget--) { s->failed_pc=0x0c071d5cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071d5e;
P_0c071d5e: /* original f41b, guest PC 0x0c071d5e */
if(!s->budget--) { s->failed_pc=0x0c071d5eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071d60;
P_0c071d60: /* original f40b, guest PC 0x0c071d60 */
if(!s->budget--) { s->failed_pc=0x0c071d60u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071d62;
P_0c071d62: /* original 0009, guest PC 0x0c071d62 */
if(!s->budget--) { s->failed_pc=0x0c071d62u; return 0; }
goto P_0c071d64;
P_0c071d64: /* original 64e3, guest PC 0x0c071d64 */
if(!s->budget--) { s->failed_pc=0x0c071d64u; return 0; }
r[4]=r[14];
goto P_0c071d66;
P_0c071d66: /* original 740c, guest PC 0x0c071d66 */
if(!s->budget--) { s->failed_pc=0x0c071d66u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071d68;
P_0c071d68: /* original f049, guest PC 0x0c071d68 */
if(!s->budget--) { s->failed_pc=0x0c071d68u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071d6a;
P_0c071d6a: /* original f149, guest PC 0x0c071d6a */
if(!s->budget--) { s->failed_pc=0x0c071d6au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071d6c;
P_0c071d6c: /* original f249, guest PC 0x0c071d6c */
if(!s->budget--) { s->failed_pc=0x0c071d6cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071d6e;
P_0c071d6e: /* original f38d, guest PC 0x0c071d6e */
if(!s->budget--) { s->failed_pc=0x0c071d6eu; return 0; }
fr[3]=0;
goto P_0c071d70;
P_0c071d70: /* original f0ed, guest PC 0x0c071d70 */
if(!s->budget--) { s->failed_pc=0x0c071d70u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071d72;
P_0c071d72: /* original f37d, guest PC 0x0c071d72 */
if(!s->budget--) { s->failed_pc=0x0c071d72u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071d74;
P_0c071d74: /* original f232, guest PC 0x0c071d74 */
if(!s->budget--) { s->failed_pc=0x0c071d74u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071d76;
P_0c071d76: /* original f132, guest PC 0x0c071d76 */
if(!s->budget--) { s->failed_pc=0x0c071d76u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071d78;
P_0c071d78: /* original f032, guest PC 0x0c071d78 */
if(!s->budget--) { s->failed_pc=0x0c071d78u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071d7a;
P_0c071d7a: /* original f42b, guest PC 0x0c071d7a */
if(!s->budget--) { s->failed_pc=0x0c071d7au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071d7c;
P_0c071d7c: /* original f41b, guest PC 0x0c071d7c */
if(!s->budget--) { s->failed_pc=0x0c071d7cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071d7e;
P_0c071d7e: /* original f40b, guest PC 0x0c071d7e */
if(!s->budget--) { s->failed_pc=0x0c071d7eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071d80;
P_0c071d80: /* original 63f2, guest PC 0x0c071d80 */
if(!s->budget--) { s->failed_pc=0x0c071d80u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c071d82;
P_0c071d82: /* original 6eb3, guest PC 0x0c071d82 */
if(!s->budget--) { s->failed_pc=0x0c071d82u; return 0; }
r[14]=r[11];
goto P_0c071d84;
P_0c071d84: /* original 7b18, guest PC 0x0c071d84 */
if(!s->budget--) { s->failed_pc=0x0c071d84u; return 0; }
r[11]+=0x00000018u;
goto P_0c071d86;
P_0c071d86: /* original 7318, guest PC 0x0c071d86 */
if(!s->budget--) { s->failed_pc=0x0c071d86u; return 0; }
r[3]+=0x00000018u;
goto P_0c071d88;
P_0c071d88: /* original 2f32, guest PC 0x0c071d88 */
if(!s->budget--) { s->failed_pc=0x0c071d88u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c071d8a;
P_0c071d8a: /* original 7818, guest PC 0x0c071d8a */
if(!s->budget--) { s->failed_pc=0x0c071d8au; return 0; }
r[8]+=0x00000018u;
goto P_0c071d8c;
P_0c071d8c: /* original 52f4, guest PC 0x0c071d8c */
if(!s->budget--) { s->failed_pc=0x0c071d8cu; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c071d8e;
P_0c071d8e: /* original 72ff, guest PC 0x0c071d8e */
if(!s->budget--) { s->failed_pc=0x0c071d8eu; return 0; }
r[2]+=0xffffffffu;
goto P_0c071d90;
P_0c071d90: /* original 1f24, guest PC 0x0c071d90 */
if(!s->budget--) { s->failed_pc=0x0c071d90u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c071d92;
P_0c071d92: /* original 53f4, guest PC 0x0c071d92 */
if(!s->budget--) { s->failed_pc=0x0c071d92u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c071d94;
P_0c071d94: /* original 3397, guest PC 0x0c071d94 */
if(!s->budget--) { s->failed_pc=0x0c071d94u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[9])!=0);
goto P_0c071d96;
P_0c071d96: /* original 8b02, guest PC 0x0c071d96 */
if(!s->budget--) { s->failed_pc=0x0c071d96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c071d9e; }
goto P_0c071d98;
P_0c071d98: /* original d203, guest PC 0x0c071d98 */
if(!s->budget--) { s->failed_pc=0x0c071d98u; return 0; }
r[2]=read(ram,0x0c071da8u,4);
goto P_0c071d9a;
P_0c071d9a: /* original 422b, guest PC 0x0c071d9a */
if(!s->budget--) { s->failed_pc=0x0c071d9au; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c071d9c: /* original 0009, guest PC 0x0c071d9c */
if(!s->budget--) { s->failed_pc=0x0c071d9cu; return 0; }
goto P_0c071d9e;
P_0c071d9e: /* original 64d3, guest PC 0x0c071d9e */
if(!s->budget--) { s->failed_pc=0x0c071d9eu; return 0; }
r[4]=r[13];
goto P_0c071da0;
P_0c071da0: /* original 65b3, guest PC 0x0c071da0 */
if(!s->budget--) { s->failed_pc=0x0c071da0u; return 0; }
r[5]=r[11];
goto P_0c071da2;
P_0c071da2: /* original 66e3, guest PC 0x0c071da2 */
if(!s->budget--) { s->failed_pc=0x0c071da2u; return 0; }
r[6]=r[14];
goto P_0c071da4;
P_0c071da4: /* original a002, guest PC 0x0c071da4 */
if(!s->budget--) { s->failed_pc=0x0c071da4u; return 0; }
goto P_0c071dac;
P_0c071da6: /* original 0009, guest PC 0x0c071da6 */
if(!s->budget--) { s->failed_pc=0x0c071da6u; return 0; }
return vf3_matrix_family(0x0c071da8u,s,ram);
P_0c071dac: /* original f059, guest PC 0x0c071dac */
if(!s->budget--) { s->failed_pc=0x0c071dacu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071dae;
P_0c071dae: /* original f369, guest PC 0x0c071dae */
if(!s->budget--) { s->failed_pc=0x0c071daeu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071db0;
P_0c071db0: /* original f159, guest PC 0x0c071db0 */
if(!s->budget--) { s->failed_pc=0x0c071db0u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071db2;
P_0c071db2: /* original f469, guest PC 0x0c071db2 */
if(!s->budget--) { s->failed_pc=0x0c071db2u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071db4;
P_0c071db4: /* original f031, guest PC 0x0c071db4 */
if(!s->budget--) { s->failed_pc=0x0c071db4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071db6;
P_0c071db6: /* original f258, guest PC 0x0c071db6 */
if(!s->budget--) { s->failed_pc=0x0c071db6u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071db8;
P_0c071db8: /* original f568, guest PC 0x0c071db8 */
if(!s->budget--) { s->failed_pc=0x0c071db8u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071dba;
P_0c071dba: /* original f141, guest PC 0x0c071dba */
if(!s->budget--) { s->failed_pc=0x0c071dbau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071dbc;
P_0c071dbc: /* original f251, guest PC 0x0c071dbc */
if(!s->budget--) { s->failed_pc=0x0c071dbcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071dbe;
P_0c071dbe: /* original 7408, guest PC 0x0c071dbe */
if(!s->budget--) { s->failed_pc=0x0c071dbeu; return 0; }
r[4]+=0x00000008u;
goto P_0c071dc0;
P_0c071dc0: /* original f42a, guest PC 0x0c071dc0 */
if(!s->budget--) { s->failed_pc=0x0c071dc0u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071dc2;
P_0c071dc2: /* original f41b, guest PC 0x0c071dc2 */
if(!s->budget--) { s->failed_pc=0x0c071dc2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071dc4;
P_0c071dc4: /* original f40b, guest PC 0x0c071dc4 */
if(!s->budget--) { s->failed_pc=0x0c071dc4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071dc6;
P_0c071dc6: /* original 0009, guest PC 0x0c071dc6 */
if(!s->budget--) { s->failed_pc=0x0c071dc6u; return 0; }
goto P_0c071dc8;
P_0c071dc8: /* original 64a3, guest PC 0x0c071dc8 */
if(!s->budget--) { s->failed_pc=0x0c071dc8u; return 0; }
r[4]=r[10];
goto P_0c071dca;
P_0c071dca: /* original 6583, guest PC 0x0c071dca */
if(!s->budget--) { s->failed_pc=0x0c071dcau; return 0; }
r[5]=r[8];
goto P_0c071dcc;
P_0c071dcc: /* original 66e3, guest PC 0x0c071dcc */
if(!s->budget--) { s->failed_pc=0x0c071dccu; return 0; }
r[6]=r[14];
goto P_0c071dce;
P_0c071dce: /* original f059, guest PC 0x0c071dce */
if(!s->budget--) { s->failed_pc=0x0c071dceu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071dd0;
P_0c071dd0: /* original f369, guest PC 0x0c071dd0 */
if(!s->budget--) { s->failed_pc=0x0c071dd0u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071dd2;
P_0c071dd2: /* original f159, guest PC 0x0c071dd2 */
if(!s->budget--) { s->failed_pc=0x0c071dd2u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071dd4;
P_0c071dd4: /* original f469, guest PC 0x0c071dd4 */
if(!s->budget--) { s->failed_pc=0x0c071dd4u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071dd6;
P_0c071dd6: /* original f031, guest PC 0x0c071dd6 */
if(!s->budget--) { s->failed_pc=0x0c071dd6u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071dd8;
P_0c071dd8: /* original f258, guest PC 0x0c071dd8 */
if(!s->budget--) { s->failed_pc=0x0c071dd8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071dda;
P_0c071dda: /* original f568, guest PC 0x0c071dda */
if(!s->budget--) { s->failed_pc=0x0c071ddau; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071ddc;
P_0c071ddc: /* original f141, guest PC 0x0c071ddc */
if(!s->budget--) { s->failed_pc=0x0c071ddcu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071dde;
P_0c071dde: /* original f251, guest PC 0x0c071dde */
if(!s->budget--) { s->failed_pc=0x0c071ddeu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071de0;
P_0c071de0: /* original 7408, guest PC 0x0c071de0 */
if(!s->budget--) { s->failed_pc=0x0c071de0u; return 0; }
r[4]+=0x00000008u;
goto P_0c071de2;
P_0c071de2: /* original f42a, guest PC 0x0c071de2 */
if(!s->budget--) { s->failed_pc=0x0c071de2u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071de4;
P_0c071de4: /* original f41b, guest PC 0x0c071de4 */
if(!s->budget--) { s->failed_pc=0x0c071de4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071de6;
P_0c071de6: /* original f40b, guest PC 0x0c071de6 */
if(!s->budget--) { s->failed_pc=0x0c071de6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071de8;
P_0c071de8: /* original 66e3, guest PC 0x0c071de8 */
if(!s->budget--) { s->failed_pc=0x0c071de8u; return 0; }
r[6]=r[14];
goto P_0c071dea;
P_0c071dea: /* original 64a3, guest PC 0x0c071dea */
if(!s->budget--) { s->failed_pc=0x0c071deau; return 0; }
r[4]=r[10];
goto P_0c071dec;
P_0c071dec: /* original 65d3, guest PC 0x0c071dec */
if(!s->budget--) { s->failed_pc=0x0c071decu; return 0; }
r[5]=r[13];
goto P_0c071dee;
P_0c071dee: /* original 760c, guest PC 0x0c071dee */
if(!s->budget--) { s->failed_pc=0x0c071deeu; return 0; }
r[6]+=0x0000000cu;
goto P_0c071df0;
P_0c071df0: /* original f049, guest PC 0x0c071df0 */
if(!s->budget--) { s->failed_pc=0x0c071df0u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071df2;
P_0c071df2: /* original f549, guest PC 0x0c071df2 */
if(!s->budget--) { s->failed_pc=0x0c071df2u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071df4;
P_0c071df4: /* original f648, guest PC 0x0c071df4 */
if(!s->budget--) { s->failed_pc=0x0c071df4u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c071df6;
P_0c071df6: /* original f859, guest PC 0x0c071df6 */
if(!s->budget--) { s->failed_pc=0x0c071df6u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071df8;
P_0c071df8: /* original f959, guest PC 0x0c071df8 */
if(!s->budget--) { s->failed_pc=0x0c071df8u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071dfa;
P_0c071dfa: /* original fa58, guest PC 0x0c071dfa */
if(!s->budget--) { s->failed_pc=0x0c071dfau; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c071dfc;
P_0c071dfc: /* original 760c, guest PC 0x0c071dfc */
if(!s->budget--) { s->failed_pc=0x0c071dfcu; return 0; }
r[6]+=0x0000000cu;
goto P_0c071dfe;
P_0c071dfe: /* original f35c, guest PC 0x0c071dfe */
if(!s->budget--) { s->failed_pc=0x0c071dfeu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c071e00;
P_0c071e00: /* original f382, guest PC 0x0c071e00 */
if(!s->budget--) { s->failed_pc=0x0c071e00u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c071e02;
P_0c071e02: /* original f20c, guest PC 0x0c071e02 */
if(!s->budget--) { s->failed_pc=0x0c071e02u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c071e04;
P_0c071e04: /* original f2a2, guest PC 0x0c071e04 */
if(!s->budget--) { s->failed_pc=0x0c071e04u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c071e06;
P_0c071e06: /* original f16c, guest PC 0x0c071e06 */
if(!s->budget--) { s->failed_pc=0x0c071e06u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c071e08;
P_0c071e08: /* original f192, guest PC 0x0c071e08 */
if(!s->budget--) { s->failed_pc=0x0c071e08u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c071e0a;
P_0c071e0a: /* original f34d, guest PC 0x0c071e0a */
if(!s->budget--) { s->failed_pc=0x0c071e0au; return 0; }
fr[3]^=0x80000000u;
goto P_0c071e0c;
P_0c071e0c: /* original f39e, guest PC 0x0c071e0c */
if(!s->budget--) { s->failed_pc=0x0c071e0cu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071e0e;
P_0c071e0e: /* original f24d, guest PC 0x0c071e0e */
if(!s->budget--) { s->failed_pc=0x0c071e0eu; return 0; }
fr[2]^=0x80000000u;
goto P_0c071e10;
P_0c071e10: /* original f06c, guest PC 0x0c071e10 */
if(!s->budget--) { s->failed_pc=0x0c071e10u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c071e12;
P_0c071e12: /* original f28e, guest PC 0x0c071e12 */
if(!s->budget--) { s->failed_pc=0x0c071e12u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c071e14;
P_0c071e14: /* original f14d, guest PC 0x0c071e14 */
if(!s->budget--) { s->failed_pc=0x0c071e14u; return 0; }
fr[1]^=0x80000000u;
goto P_0c071e16;
P_0c071e16: /* original f63b, guest PC 0x0c071e16 */
if(!s->budget--) { s->failed_pc=0x0c071e16u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c071e18;
P_0c071e18: /* original f05c, guest PC 0x0c071e18 */
if(!s->budget--) { s->failed_pc=0x0c071e18u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c071e1a;
P_0c071e1a: /* original f1ae, guest PC 0x0c071e1a */
if(!s->budget--) { s->failed_pc=0x0c071e1au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c071e1c;
P_0c071e1c: /* original f62b, guest PC 0x0c071e1c */
if(!s->budget--) { s->failed_pc=0x0c071e1cu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c071e1e;
P_0c071e1e: /* original f61b, guest PC 0x0c071e1e */
if(!s->budget--) { s->failed_pc=0x0c071e1eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c071e20;
P_0c071e20: /* original 64e3, guest PC 0x0c071e20 */
if(!s->budget--) { s->failed_pc=0x0c071e20u; return 0; }
r[4]=r[14];
goto P_0c071e22;
P_0c071e22: /* original 740c, guest PC 0x0c071e22 */
if(!s->budget--) { s->failed_pc=0x0c071e22u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071e24;
P_0c071e24: /* original f049, guest PC 0x0c071e24 */
if(!s->budget--) { s->failed_pc=0x0c071e24u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071e26;
P_0c071e26: /* original f149, guest PC 0x0c071e26 */
if(!s->budget--) { s->failed_pc=0x0c071e26u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071e28;
P_0c071e28: /* original f249, guest PC 0x0c071e28 */
if(!s->budget--) { s->failed_pc=0x0c071e28u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071e2a;
P_0c071e2a: /* original f38d, guest PC 0x0c071e2a */
if(!s->budget--) { s->failed_pc=0x0c071e2au; return 0; }
fr[3]=0;
goto P_0c071e2c;
P_0c071e2c: /* original f0ed, guest PC 0x0c071e2c */
if(!s->budget--) { s->failed_pc=0x0c071e2cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071e2e;
P_0c071e2e: /* original f37d, guest PC 0x0c071e2e */
if(!s->budget--) { s->failed_pc=0x0c071e2eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071e30;
P_0c071e30: /* original f232, guest PC 0x0c071e30 */
if(!s->budget--) { s->failed_pc=0x0c071e30u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071e32;
P_0c071e32: /* original f132, guest PC 0x0c071e32 */
if(!s->budget--) { s->failed_pc=0x0c071e32u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071e34;
P_0c071e34: /* original f032, guest PC 0x0c071e34 */
if(!s->budget--) { s->failed_pc=0x0c071e34u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071e36;
P_0c071e36: /* original f42b, guest PC 0x0c071e36 */
if(!s->budget--) { s->failed_pc=0x0c071e36u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071e38;
P_0c071e38: /* original f41b, guest PC 0x0c071e38 */
if(!s->budget--) { s->failed_pc=0x0c071e38u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071e3a;
P_0c071e3a: /* original f40b, guest PC 0x0c071e3a */
if(!s->budget--) { s->failed_pc=0x0c071e3au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071e3c;
P_0c071e3c: /* original 2fe2, guest PC 0x0c071e3c */
if(!s->budget--) { s->failed_pc=0x0c071e3cu; return 0; }
write(ram,r[15],r[14],4);
goto P_0c071e3e;
P_0c071e3e: /* original 6eb3, guest PC 0x0c071e3e */
if(!s->budget--) { s->failed_pc=0x0c071e3eu; return 0; }
r[14]=r[11];
goto P_0c071e40;
P_0c071e40: /* original 53f5, guest PC 0x0c071e40 */
if(!s->budget--) { s->failed_pc=0x0c071e40u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c071e42;
P_0c071e42: /* original 7b18, guest PC 0x0c071e42 */
if(!s->budget--) { s->failed_pc=0x0c071e42u; return 0; }
r[11]+=0x00000018u;
goto P_0c071e44;
P_0c071e44: /* original 6233, guest PC 0x0c071e44 */
if(!s->budget--) { s->failed_pc=0x0c071e44u; return 0; }
r[2]=r[3];
goto P_0c071e46;
P_0c071e46: /* original 3297, guest PC 0x0c071e46 */
if(!s->budget--) { s->failed_pc=0x0c071e46u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[9])!=0);
goto P_0c071e48;
P_0c071e48: /* original 1f31, guest PC 0x0c071e48 */
if(!s->budget--) { s->failed_pc=0x0c071e48u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c071e4a;
P_0c071e4a: /* original 8d03, guest PC 0x0c071e4a */
if(!s->budget--) { s->failed_pc=0x0c071e4au; return 0; }
cond=r[17]&1u;
r[8]+=0x00000018u;
if(cond) { goto P_0c071e54; }
goto P_0c071e4e;
P_0c071e4c: /* original 7818, guest PC 0x0c071e4c */
if(!s->budget--) { s->failed_pc=0x0c071e4cu; return 0; }
r[8]+=0x00000018u;
goto P_0c071e4e;
P_0c071e4e: /* original d304, guest PC 0x0c071e4e */
if(!s->budget--) { s->failed_pc=0x0c071e4eu; return 0; }
r[3]=read(ram,0x0c071e60u,4);
goto P_0c071e50;
P_0c071e50: /* original 432b, guest PC 0x0c071e50 */
if(!s->budget--) { s->failed_pc=0x0c071e50u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c071e52: /* original 0009, guest PC 0x0c071e52 */
if(!s->budget--) { s->failed_pc=0x0c071e52u; return 0; }
goto P_0c071e54;
P_0c071e54: /* original 65f2, guest PC 0x0c071e54 */
if(!s->budget--) { s->failed_pc=0x0c071e54u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c071e56;
P_0c071e56: /* original 64d3, guest PC 0x0c071e56 */
if(!s->budget--) { s->failed_pc=0x0c071e56u; return 0; }
r[4]=r[13];
goto P_0c071e58;
P_0c071e58: /* original 66e3, guest PC 0x0c071e58 */
if(!s->budget--) { s->failed_pc=0x0c071e58u; return 0; }
r[6]=r[14];
goto P_0c071e5a;
P_0c071e5a: /* original a003, guest PC 0x0c071e5a */
if(!s->budget--) { s->failed_pc=0x0c071e5au; return 0; }
goto P_0c071e64;
P_0c071e5c: /* original 0009, guest PC 0x0c071e5c */
if(!s->budget--) { s->failed_pc=0x0c071e5cu; return 0; }
return vf3_matrix_family(0x0c071e5eu,s,ram);
P_0c071e64: /* original f059, guest PC 0x0c071e64 */
if(!s->budget--) { s->failed_pc=0x0c071e64u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071e66;
P_0c071e66: /* original f369, guest PC 0x0c071e66 */
if(!s->budget--) { s->failed_pc=0x0c071e66u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071e68;
P_0c071e68: /* original f159, guest PC 0x0c071e68 */
if(!s->budget--) { s->failed_pc=0x0c071e68u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071e6a;
P_0c071e6a: /* original f469, guest PC 0x0c071e6a */
if(!s->budget--) { s->failed_pc=0x0c071e6au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071e6c;
P_0c071e6c: /* original f031, guest PC 0x0c071e6c */
if(!s->budget--) { s->failed_pc=0x0c071e6cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071e6e;
P_0c071e6e: /* original f258, guest PC 0x0c071e6e */
if(!s->budget--) { s->failed_pc=0x0c071e6eu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071e70;
P_0c071e70: /* original f568, guest PC 0x0c071e70 */
if(!s->budget--) { s->failed_pc=0x0c071e70u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071e72;
P_0c071e72: /* original f141, guest PC 0x0c071e72 */
if(!s->budget--) { s->failed_pc=0x0c071e72u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071e74;
P_0c071e74: /* original f251, guest PC 0x0c071e74 */
if(!s->budget--) { s->failed_pc=0x0c071e74u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071e76;
P_0c071e76: /* original 7408, guest PC 0x0c071e76 */
if(!s->budget--) { s->failed_pc=0x0c071e76u; return 0; }
r[4]+=0x00000008u;
goto P_0c071e78;
P_0c071e78: /* original f42a, guest PC 0x0c071e78 */
if(!s->budget--) { s->failed_pc=0x0c071e78u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071e7a;
P_0c071e7a: /* original f41b, guest PC 0x0c071e7a */
if(!s->budget--) { s->failed_pc=0x0c071e7au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071e7c;
P_0c071e7c: /* original f40b, guest PC 0x0c071e7c */
if(!s->budget--) { s->failed_pc=0x0c071e7cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071e7e;
P_0c071e7e: /* original 0009, guest PC 0x0c071e7e */
if(!s->budget--) { s->failed_pc=0x0c071e7eu; return 0; }
goto P_0c071e80;
P_0c071e80: /* original 64a3, guest PC 0x0c071e80 */
if(!s->budget--) { s->failed_pc=0x0c071e80u; return 0; }
r[4]=r[10];
goto P_0c071e82;
P_0c071e82: /* original 65b3, guest PC 0x0c071e82 */
if(!s->budget--) { s->failed_pc=0x0c071e82u; return 0; }
r[5]=r[11];
goto P_0c071e84;
P_0c071e84: /* original 66e3, guest PC 0x0c071e84 */
if(!s->budget--) { s->failed_pc=0x0c071e84u; return 0; }
r[6]=r[14];
goto P_0c071e86;
P_0c071e86: /* original f059, guest PC 0x0c071e86 */
if(!s->budget--) { s->failed_pc=0x0c071e86u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071e88;
P_0c071e88: /* original f369, guest PC 0x0c071e88 */
if(!s->budget--) { s->failed_pc=0x0c071e88u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071e8a;
P_0c071e8a: /* original f159, guest PC 0x0c071e8a */
if(!s->budget--) { s->failed_pc=0x0c071e8au; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071e8c;
P_0c071e8c: /* original f469, guest PC 0x0c071e8c */
if(!s->budget--) { s->failed_pc=0x0c071e8cu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071e8e;
P_0c071e8e: /* original f031, guest PC 0x0c071e8e */
if(!s->budget--) { s->failed_pc=0x0c071e8eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071e90;
P_0c071e90: /* original f258, guest PC 0x0c071e90 */
if(!s->budget--) { s->failed_pc=0x0c071e90u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071e92;
P_0c071e92: /* original f568, guest PC 0x0c071e92 */
if(!s->budget--) { s->failed_pc=0x0c071e92u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071e94;
P_0c071e94: /* original f141, guest PC 0x0c071e94 */
if(!s->budget--) { s->failed_pc=0x0c071e94u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071e96;
P_0c071e96: /* original f251, guest PC 0x0c071e96 */
if(!s->budget--) { s->failed_pc=0x0c071e96u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071e98;
P_0c071e98: /* original 7408, guest PC 0x0c071e98 */
if(!s->budget--) { s->failed_pc=0x0c071e98u; return 0; }
r[4]+=0x00000008u;
goto P_0c071e9a;
P_0c071e9a: /* original f42a, guest PC 0x0c071e9a */
if(!s->budget--) { s->failed_pc=0x0c071e9au; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071e9c;
P_0c071e9c: /* original f41b, guest PC 0x0c071e9c */
if(!s->budget--) { s->failed_pc=0x0c071e9cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071e9e;
P_0c071e9e: /* original f40b, guest PC 0x0c071e9e */
if(!s->budget--) { s->failed_pc=0x0c071e9eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071ea0;
P_0c071ea0: /* original 64c3, guest PC 0x0c071ea0 */
if(!s->budget--) { s->failed_pc=0x0c071ea0u; return 0; }
r[4]=r[12];
goto P_0c071ea2;
P_0c071ea2: /* original 6583, guest PC 0x0c071ea2 */
if(!s->budget--) { s->failed_pc=0x0c071ea2u; return 0; }
r[5]=r[8];
goto P_0c071ea4;
P_0c071ea4: /* original 66e3, guest PC 0x0c071ea4 */
if(!s->budget--) { s->failed_pc=0x0c071ea4u; return 0; }
r[6]=r[14];
goto P_0c071ea6;
P_0c071ea6: /* original f059, guest PC 0x0c071ea6 */
if(!s->budget--) { s->failed_pc=0x0c071ea6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ea8;
P_0c071ea8: /* original f369, guest PC 0x0c071ea8 */
if(!s->budget--) { s->failed_pc=0x0c071ea8u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071eaa;
P_0c071eaa: /* original f159, guest PC 0x0c071eaa */
if(!s->budget--) { s->failed_pc=0x0c071eaau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071eac;
P_0c071eac: /* original f469, guest PC 0x0c071eac */
if(!s->budget--) { s->failed_pc=0x0c071eacu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071eae;
P_0c071eae: /* original f031, guest PC 0x0c071eae */
if(!s->budget--) { s->failed_pc=0x0c071eaeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071eb0;
P_0c071eb0: /* original f258, guest PC 0x0c071eb0 */
if(!s->budget--) { s->failed_pc=0x0c071eb0u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071eb2;
P_0c071eb2: /* original f568, guest PC 0x0c071eb2 */
if(!s->budget--) { s->failed_pc=0x0c071eb2u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071eb4;
P_0c071eb4: /* original f141, guest PC 0x0c071eb4 */
if(!s->budget--) { s->failed_pc=0x0c071eb4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071eb6;
P_0c071eb6: /* original f251, guest PC 0x0c071eb6 */
if(!s->budget--) { s->failed_pc=0x0c071eb6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071eb8;
P_0c071eb8: /* original 7408, guest PC 0x0c071eb8 */
if(!s->budget--) { s->failed_pc=0x0c071eb8u; return 0; }
r[4]+=0x00000008u;
goto P_0c071eba;
P_0c071eba: /* original f42a, guest PC 0x0c071eba */
if(!s->budget--) { s->failed_pc=0x0c071ebau; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071ebc;
P_0c071ebc: /* original f41b, guest PC 0x0c071ebc */
if(!s->budget--) { s->failed_pc=0x0c071ebcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071ebe;
P_0c071ebe: /* original f40b, guest PC 0x0c071ebe */
if(!s->budget--) { s->failed_pc=0x0c071ebeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071ec0;
P_0c071ec0: /* original 66f3, guest PC 0x0c071ec0 */
if(!s->budget--) { s->failed_pc=0x0c071ec0u; return 0; }
r[6]=r[15];
goto P_0c071ec2;
P_0c071ec2: /* original 64c3, guest PC 0x0c071ec2 */
if(!s->budget--) { s->failed_pc=0x0c071ec2u; return 0; }
r[4]=r[12];
goto P_0c071ec4;
P_0c071ec4: /* original 65a3, guest PC 0x0c071ec4 */
if(!s->budget--) { s->failed_pc=0x0c071ec4u; return 0; }
r[5]=r[10];
goto P_0c071ec6;
P_0c071ec6: /* original 7624, guest PC 0x0c071ec6 */
if(!s->budget--) { s->failed_pc=0x0c071ec6u; return 0; }
r[6]+=0x00000024u;
goto P_0c071ec8;
P_0c071ec8: /* original f049, guest PC 0x0c071ec8 */
if(!s->budget--) { s->failed_pc=0x0c071ec8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071eca;
P_0c071eca: /* original f549, guest PC 0x0c071eca */
if(!s->budget--) { s->failed_pc=0x0c071ecau; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071ecc;
P_0c071ecc: /* original f648, guest PC 0x0c071ecc */
if(!s->budget--) { s->failed_pc=0x0c071eccu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c071ece;
P_0c071ece: /* original f859, guest PC 0x0c071ece */
if(!s->budget--) { s->failed_pc=0x0c071eceu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ed0;
P_0c071ed0: /* original f959, guest PC 0x0c071ed0 */
if(!s->budget--) { s->failed_pc=0x0c071ed0u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ed2;
P_0c071ed2: /* original fa58, guest PC 0x0c071ed2 */
if(!s->budget--) { s->failed_pc=0x0c071ed2u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c071ed4;
P_0c071ed4: /* original 760c, guest PC 0x0c071ed4 */
if(!s->budget--) { s->failed_pc=0x0c071ed4u; return 0; }
r[6]+=0x0000000cu;
goto P_0c071ed6;
P_0c071ed6: /* original f35c, guest PC 0x0c071ed6 */
if(!s->budget--) { s->failed_pc=0x0c071ed6u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c071ed8;
P_0c071ed8: /* original f382, guest PC 0x0c071ed8 */
if(!s->budget--) { s->failed_pc=0x0c071ed8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c071eda;
P_0c071eda: /* original f20c, guest PC 0x0c071eda */
if(!s->budget--) { s->failed_pc=0x0c071edau; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c071edc;
P_0c071edc: /* original f2a2, guest PC 0x0c071edc */
if(!s->budget--) { s->failed_pc=0x0c071edcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c071ede;
P_0c071ede: /* original f16c, guest PC 0x0c071ede */
if(!s->budget--) { s->failed_pc=0x0c071edeu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c071ee0;
P_0c071ee0: /* original f192, guest PC 0x0c071ee0 */
if(!s->budget--) { s->failed_pc=0x0c071ee0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c071ee2;
P_0c071ee2: /* original f34d, guest PC 0x0c071ee2 */
if(!s->budget--) { s->failed_pc=0x0c071ee2u; return 0; }
fr[3]^=0x80000000u;
goto P_0c071ee4;
P_0c071ee4: /* original f39e, guest PC 0x0c071ee4 */
if(!s->budget--) { s->failed_pc=0x0c071ee4u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071ee6;
P_0c071ee6: /* original f24d, guest PC 0x0c071ee6 */
if(!s->budget--) { s->failed_pc=0x0c071ee6u; return 0; }
fr[2]^=0x80000000u;
goto P_0c071ee8;
P_0c071ee8: /* original f06c, guest PC 0x0c071ee8 */
if(!s->budget--) { s->failed_pc=0x0c071ee8u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c071eea;
P_0c071eea: /* original f28e, guest PC 0x0c071eea */
if(!s->budget--) { s->failed_pc=0x0c071eeau; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c071eec;
P_0c071eec: /* original f14d, guest PC 0x0c071eec */
if(!s->budget--) { s->failed_pc=0x0c071eecu; return 0; }
fr[1]^=0x80000000u;
goto P_0c071eee;
P_0c071eee: /* original f63b, guest PC 0x0c071eee */
if(!s->budget--) { s->failed_pc=0x0c071eeeu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c071ef0;
P_0c071ef0: /* original f05c, guest PC 0x0c071ef0 */
if(!s->budget--) { s->failed_pc=0x0c071ef0u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c071ef2;
P_0c071ef2: /* original f1ae, guest PC 0x0c071ef2 */
if(!s->budget--) { s->failed_pc=0x0c071ef2u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c071ef4;
P_0c071ef4: /* original f62b, guest PC 0x0c071ef4 */
if(!s->budget--) { s->failed_pc=0x0c071ef4u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c071ef6;
P_0c071ef6: /* original f61b, guest PC 0x0c071ef6 */
if(!s->budget--) { s->failed_pc=0x0c071ef6u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c071ef8;
P_0c071ef8: /* original 66f3, guest PC 0x0c071ef8 */
if(!s->budget--) { s->failed_pc=0x0c071ef8u; return 0; }
r[6]=r[15];
goto P_0c071efa;
P_0c071efa: /* original 64d3, guest PC 0x0c071efa */
if(!s->budget--) { s->failed_pc=0x0c071efau; return 0; }
r[4]=r[13];
goto P_0c071efc;
P_0c071efc: /* original 65c3, guest PC 0x0c071efc */
if(!s->budget--) { s->failed_pc=0x0c071efcu; return 0; }
r[5]=r[12];
goto P_0c071efe;
P_0c071efe: /* original 7618, guest PC 0x0c071efe */
if(!s->budget--) { s->failed_pc=0x0c071efeu; return 0; }
r[6]+=0x00000018u;
goto P_0c071f00;
P_0c071f00: /* original f049, guest PC 0x0c071f00 */
if(!s->budget--) { s->failed_pc=0x0c071f00u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f02;
P_0c071f02: /* original f549, guest PC 0x0c071f02 */
if(!s->budget--) { s->failed_pc=0x0c071f02u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f04;
P_0c071f04: /* original f648, guest PC 0x0c071f04 */
if(!s->budget--) { s->failed_pc=0x0c071f04u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c071f06;
P_0c071f06: /* original f859, guest PC 0x0c071f06 */
if(!s->budget--) { s->failed_pc=0x0c071f06u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071f08;
P_0c071f08: /* original f959, guest PC 0x0c071f08 */
if(!s->budget--) { s->failed_pc=0x0c071f08u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071f0a;
P_0c071f0a: /* original fa58, guest PC 0x0c071f0a */
if(!s->budget--) { s->failed_pc=0x0c071f0au; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c071f0c;
P_0c071f0c: /* original 760c, guest PC 0x0c071f0c */
if(!s->budget--) { s->failed_pc=0x0c071f0cu; return 0; }
r[6]+=0x0000000cu;
goto P_0c071f0e;
P_0c071f0e: /* original f35c, guest PC 0x0c071f0e */
if(!s->budget--) { s->failed_pc=0x0c071f0eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c071f10;
P_0c071f10: /* original f382, guest PC 0x0c071f10 */
if(!s->budget--) { s->failed_pc=0x0c071f10u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c071f12;
P_0c071f12: /* original f20c, guest PC 0x0c071f12 */
if(!s->budget--) { s->failed_pc=0x0c071f12u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c071f14;
P_0c071f14: /* original f2a2, guest PC 0x0c071f14 */
if(!s->budget--) { s->failed_pc=0x0c071f14u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c071f16;
P_0c071f16: /* original f16c, guest PC 0x0c071f16 */
if(!s->budget--) { s->failed_pc=0x0c071f16u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c071f18;
P_0c071f18: /* original f192, guest PC 0x0c071f18 */
if(!s->budget--) { s->failed_pc=0x0c071f18u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c071f1a;
P_0c071f1a: /* original f34d, guest PC 0x0c071f1a */
if(!s->budget--) { s->failed_pc=0x0c071f1au; return 0; }
fr[3]^=0x80000000u;
goto P_0c071f1c;
P_0c071f1c: /* original f39e, guest PC 0x0c071f1c */
if(!s->budget--) { s->failed_pc=0x0c071f1cu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071f1e;
P_0c071f1e: /* original f24d, guest PC 0x0c071f1e */
if(!s->budget--) { s->failed_pc=0x0c071f1eu; return 0; }
fr[2]^=0x80000000u;
goto P_0c071f20;
P_0c071f20: /* original f06c, guest PC 0x0c071f20 */
if(!s->budget--) { s->failed_pc=0x0c071f20u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c071f22;
P_0c071f22: /* original f28e, guest PC 0x0c071f22 */
if(!s->budget--) { s->failed_pc=0x0c071f22u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c071f24;
P_0c071f24: /* original f14d, guest PC 0x0c071f24 */
if(!s->budget--) { s->failed_pc=0x0c071f24u; return 0; }
fr[1]^=0x80000000u;
goto P_0c071f26;
P_0c071f26: /* original f63b, guest PC 0x0c071f26 */
if(!s->budget--) { s->failed_pc=0x0c071f26u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c071f28;
P_0c071f28: /* original f05c, guest PC 0x0c071f28 */
if(!s->budget--) { s->failed_pc=0x0c071f28u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c071f2a;
P_0c071f2a: /* original f1ae, guest PC 0x0c071f2a */
if(!s->budget--) { s->failed_pc=0x0c071f2au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c071f2c;
P_0c071f2c: /* original f62b, guest PC 0x0c071f2c */
if(!s->budget--) { s->failed_pc=0x0c071f2cu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c071f2e;
P_0c071f2e: /* original f61b, guest PC 0x0c071f2e */
if(!s->budget--) { s->failed_pc=0x0c071f2eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c071f30;
P_0c071f30: /* original 64f3, guest PC 0x0c071f30 */
if(!s->budget--) { s->failed_pc=0x0c071f30u; return 0; }
r[4]=r[15];
goto P_0c071f32;
P_0c071f32: /* original 7424, guest PC 0x0c071f32 */
if(!s->budget--) { s->failed_pc=0x0c071f32u; return 0; }
r[4]+=0x00000024u;
goto P_0c071f34;
P_0c071f34: /* original f049, guest PC 0x0c071f34 */
if(!s->budget--) { s->failed_pc=0x0c071f34u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f36;
P_0c071f36: /* original f149, guest PC 0x0c071f36 */
if(!s->budget--) { s->failed_pc=0x0c071f36u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f38;
P_0c071f38: /* original f249, guest PC 0x0c071f38 */
if(!s->budget--) { s->failed_pc=0x0c071f38u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f3a;
P_0c071f3a: /* original f38d, guest PC 0x0c071f3a */
if(!s->budget--) { s->failed_pc=0x0c071f3au; return 0; }
fr[3]=0;
goto P_0c071f3c;
P_0c071f3c: /* original f0ed, guest PC 0x0c071f3c */
if(!s->budget--) { s->failed_pc=0x0c071f3cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071f3e;
P_0c071f3e: /* original f37d, guest PC 0x0c071f3e */
if(!s->budget--) { s->failed_pc=0x0c071f3eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071f40;
P_0c071f40: /* original f232, guest PC 0x0c071f40 */
if(!s->budget--) { s->failed_pc=0x0c071f40u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071f42;
P_0c071f42: /* original f132, guest PC 0x0c071f42 */
if(!s->budget--) { s->failed_pc=0x0c071f42u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071f44;
P_0c071f44: /* original f032, guest PC 0x0c071f44 */
if(!s->budget--) { s->failed_pc=0x0c071f44u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071f46;
P_0c071f46: /* original f42b, guest PC 0x0c071f46 */
if(!s->budget--) { s->failed_pc=0x0c071f46u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071f48;
P_0c071f48: /* original f41b, guest PC 0x0c071f48 */
if(!s->budget--) { s->failed_pc=0x0c071f48u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071f4a;
P_0c071f4a: /* original f40b, guest PC 0x0c071f4a */
if(!s->budget--) { s->failed_pc=0x0c071f4au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071f4c;
P_0c071f4c: /* original 64f3, guest PC 0x0c071f4c */
if(!s->budget--) { s->failed_pc=0x0c071f4cu; return 0; }
r[4]=r[15];
goto P_0c071f4e;
P_0c071f4e: /* original 7418, guest PC 0x0c071f4e */
if(!s->budget--) { s->failed_pc=0x0c071f4eu; return 0; }
r[4]+=0x00000018u;
goto P_0c071f50;
P_0c071f50: /* original f049, guest PC 0x0c071f50 */
if(!s->budget--) { s->failed_pc=0x0c071f50u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f52;
P_0c071f52: /* original f149, guest PC 0x0c071f52 */
if(!s->budget--) { s->failed_pc=0x0c071f52u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f54;
P_0c071f54: /* original f249, guest PC 0x0c071f54 */
if(!s->budget--) { s->failed_pc=0x0c071f54u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f56;
P_0c071f56: /* original f38d, guest PC 0x0c071f56 */
if(!s->budget--) { s->failed_pc=0x0c071f56u; return 0; }
fr[3]=0;
goto P_0c071f58;
P_0c071f58: /* original f0ed, guest PC 0x0c071f58 */
if(!s->budget--) { s->failed_pc=0x0c071f58u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071f5a;
P_0c071f5a: /* original f37d, guest PC 0x0c071f5a */
if(!s->budget--) { s->failed_pc=0x0c071f5au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071f5c;
P_0c071f5c: /* original f232, guest PC 0x0c071f5c */
if(!s->budget--) { s->failed_pc=0x0c071f5cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071f5e;
P_0c071f5e: /* original f132, guest PC 0x0c071f5e */
if(!s->budget--) { s->failed_pc=0x0c071f5eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071f60;
P_0c071f60: /* original f032, guest PC 0x0c071f60 */
if(!s->budget--) { s->failed_pc=0x0c071f60u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071f62;
P_0c071f62: /* original f42b, guest PC 0x0c071f62 */
if(!s->budget--) { s->failed_pc=0x0c071f62u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071f64;
P_0c071f64: /* original f41b, guest PC 0x0c071f64 */
if(!s->budget--) { s->failed_pc=0x0c071f64u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071f66;
P_0c071f66: /* original f40b, guest PC 0x0c071f66 */
if(!s->budget--) { s->failed_pc=0x0c071f66u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071f68;
P_0c071f68: /* original 65f3, guest PC 0x0c071f68 */
if(!s->budget--) { s->failed_pc=0x0c071f68u; return 0; }
r[5]=r[15];
goto P_0c071f6a;
P_0c071f6a: /* original 64e3, guest PC 0x0c071f6a */
if(!s->budget--) { s->failed_pc=0x0c071f6au; return 0; }
r[4]=r[14];
goto P_0c071f6c;
P_0c071f6c: /* original 66f3, guest PC 0x0c071f6c */
if(!s->budget--) { s->failed_pc=0x0c071f6cu; return 0; }
r[6]=r[15];
goto P_0c071f6e;
P_0c071f6e: /* original 740c, guest PC 0x0c071f6e */
if(!s->budget--) { s->failed_pc=0x0c071f6eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c071f70;
P_0c071f70: /* original 7618, guest PC 0x0c071f70 */
if(!s->budget--) { s->failed_pc=0x0c071f70u; return 0; }
r[6]+=0x00000018u;
goto P_0c071f72;
P_0c071f72: /* original 7524, guest PC 0x0c071f72 */
if(!s->budget--) { s->failed_pc=0x0c071f72u; return 0; }
r[5]+=0x00000024u;
goto P_0c071f74;
P_0c071f74: /* original f059, guest PC 0x0c071f74 */
if(!s->budget--) { s->failed_pc=0x0c071f74u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071f76;
P_0c071f76: /* original f369, guest PC 0x0c071f76 */
if(!s->budget--) { s->failed_pc=0x0c071f76u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071f78;
P_0c071f78: /* original f159, guest PC 0x0c071f78 */
if(!s->budget--) { s->failed_pc=0x0c071f78u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071f7a;
P_0c071f7a: /* original f469, guest PC 0x0c071f7a */
if(!s->budget--) { s->failed_pc=0x0c071f7au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071f7c;
P_0c071f7c: /* original f259, guest PC 0x0c071f7c */
if(!s->budget--) { s->failed_pc=0x0c071f7cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071f7e;
P_0c071f7e: /* original f569, guest PC 0x0c071f7e */
if(!s->budget--) { s->failed_pc=0x0c071f7eu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071f80;
P_0c071f80: /* original 740c, guest PC 0x0c071f80 */
if(!s->budget--) { s->failed_pc=0x0c071f80u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071f82;
P_0c071f82: /* original f030, guest PC 0x0c071f82 */
if(!s->budget--) { s->failed_pc=0x0c071f82u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c071f84;
P_0c071f84: /* original f250, guest PC 0x0c071f84 */
if(!s->budget--) { s->failed_pc=0x0c071f84u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c071f86;
P_0c071f86: /* original f140, guest PC 0x0c071f86 */
if(!s->budget--) { s->failed_pc=0x0c071f86u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071f88;
P_0c071f88: /* original f42b, guest PC 0x0c071f88 */
if(!s->budget--) { s->failed_pc=0x0c071f88u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071f8a;
P_0c071f8a: /* original f41b, guest PC 0x0c071f8a */
if(!s->budget--) { s->failed_pc=0x0c071f8au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071f8c;
P_0c071f8c: /* original f40b, guest PC 0x0c071f8c */
if(!s->budget--) { s->failed_pc=0x0c071f8cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071f8e;
P_0c071f8e: /* original 0009, guest PC 0x0c071f8e */
if(!s->budget--) { s->failed_pc=0x0c071f8eu; return 0; }
goto P_0c071f90;
P_0c071f90: /* original 64e3, guest PC 0x0c071f90 */
if(!s->budget--) { s->failed_pc=0x0c071f90u; return 0; }
r[4]=r[14];
goto P_0c071f92;
P_0c071f92: /* original 740c, guest PC 0x0c071f92 */
if(!s->budget--) { s->failed_pc=0x0c071f92u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071f94;
P_0c071f94: /* original f049, guest PC 0x0c071f94 */
if(!s->budget--) { s->failed_pc=0x0c071f94u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f96;
P_0c071f96: /* original f149, guest PC 0x0c071f96 */
if(!s->budget--) { s->failed_pc=0x0c071f96u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f98;
P_0c071f98: /* original f249, guest PC 0x0c071f98 */
if(!s->budget--) { s->failed_pc=0x0c071f98u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f9a;
P_0c071f9a: /* original f38d, guest PC 0x0c071f9a */
if(!s->budget--) { s->failed_pc=0x0c071f9au; return 0; }
fr[3]=0;
goto P_0c071f9c;
P_0c071f9c: /* original f0ed, guest PC 0x0c071f9c */
if(!s->budget--) { s->failed_pc=0x0c071f9cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071f9e;
P_0c071f9e: /* original f37d, guest PC 0x0c071f9e */
if(!s->budget--) { s->failed_pc=0x0c071f9eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071fa0;
P_0c071fa0: /* original f232, guest PC 0x0c071fa0 */
if(!s->budget--) { s->failed_pc=0x0c071fa0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071fa2;
P_0c071fa2: /* original f132, guest PC 0x0c071fa2 */
if(!s->budget--) { s->failed_pc=0x0c071fa2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071fa4;
P_0c071fa4: /* original f032, guest PC 0x0c071fa4 */
if(!s->budget--) { s->failed_pc=0x0c071fa4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071fa6;
P_0c071fa6: /* original f42b, guest PC 0x0c071fa6 */
if(!s->budget--) { s->failed_pc=0x0c071fa6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071fa8;
P_0c071fa8: /* original f41b, guest PC 0x0c071fa8 */
if(!s->budget--) { s->failed_pc=0x0c071fa8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071faa;
P_0c071faa: /* original f40b, guest PC 0x0c071faa */
if(!s->budget--) { s->failed_pc=0x0c071faau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071fac;
P_0c071fac: /* original 2fe2, guest PC 0x0c071fac */
if(!s->budget--) { s->failed_pc=0x0c071facu; return 0; }
write(ram,r[15],r[14],4);
goto P_0c071fae;
P_0c071fae: /* original 6eb3, guest PC 0x0c071fae */
if(!s->budget--) { s->failed_pc=0x0c071faeu; return 0; }
r[14]=r[11];
goto P_0c071fb0;
P_0c071fb0: /* original 53f1, guest PC 0x0c071fb0 */
if(!s->budget--) { s->failed_pc=0x0c071fb0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c071fb2;
P_0c071fb2: /* original 7b18, guest PC 0x0c071fb2 */
if(!s->budget--) { s->failed_pc=0x0c071fb2u; return 0; }
r[11]+=0x00000018u;
goto P_0c071fb4;
P_0c071fb4: /* original 7818, guest PC 0x0c071fb4 */
if(!s->budget--) { s->failed_pc=0x0c071fb4u; return 0; }
r[8]+=0x00000018u;
goto P_0c071fb6;
P_0c071fb6: /* original 73ff, guest PC 0x0c071fb6 */
if(!s->budget--) { s->failed_pc=0x0c071fb6u; return 0; }
r[3]+=0xffffffffu;
goto P_0c071fb8;
P_0c071fb8: /* original 3397, guest PC 0x0c071fb8 */
if(!s->budget--) { s->failed_pc=0x0c071fb8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[9])!=0);
goto P_0c071fba;
P_0c071fba: /* original 8f03, guest PC 0x0c071fba */
if(!s->budget--) { s->failed_pc=0x0c071fbau; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[3],4);
if(!cond) { goto P_0c071fc4; }
goto P_0c071fbe;
P_0c071fbc: /* original 1f31, guest PC 0x0c071fbc */
if(!s->budget--) { s->failed_pc=0x0c071fbcu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c071fbe;
P_0c071fbe: /* original d204, guest PC 0x0c071fbe */
if(!s->budget--) { s->failed_pc=0x0c071fbeu; return 0; }
r[2]=read(ram,0x0c071fd0u,4);
goto P_0c071fc0;
P_0c071fc0: /* original 422b, guest PC 0x0c071fc0 */
if(!s->budget--) { s->failed_pc=0x0c071fc0u; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c071fc2: /* original 0009, guest PC 0x0c071fc2 */
if(!s->budget--) { s->failed_pc=0x0c071fc2u; return 0; }
goto P_0c071fc4;
P_0c071fc4: /* original 65f2, guest PC 0x0c071fc4 */
if(!s->budget--) { s->failed_pc=0x0c071fc4u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c071fc6;
P_0c071fc6: /* original 64d3, guest PC 0x0c071fc6 */
if(!s->budget--) { s->failed_pc=0x0c071fc6u; return 0; }
r[4]=r[13];
goto P_0c071fc8;
P_0c071fc8: /* original 66e3, guest PC 0x0c071fc8 */
if(!s->budget--) { s->failed_pc=0x0c071fc8u; return 0; }
r[6]=r[14];
goto P_0c071fca;
P_0c071fca: /* original a003, guest PC 0x0c071fca */
if(!s->budget--) { s->failed_pc=0x0c071fcau; return 0; }
goto P_0c071fd4;
P_0c071fcc: /* original 0009, guest PC 0x0c071fcc */
if(!s->budget--) { s->failed_pc=0x0c071fccu; return 0; }
return vf3_matrix_family(0x0c071fceu,s,ram);
P_0c071fd4: /* original f059, guest PC 0x0c071fd4 */
if(!s->budget--) { s->failed_pc=0x0c071fd4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071fd6;
P_0c071fd6: /* original f369, guest PC 0x0c071fd6 */
if(!s->budget--) { s->failed_pc=0x0c071fd6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071fd8;
P_0c071fd8: /* original f159, guest PC 0x0c071fd8 */
if(!s->budget--) { s->failed_pc=0x0c071fd8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071fda;
P_0c071fda: /* original f469, guest PC 0x0c071fda */
if(!s->budget--) { s->failed_pc=0x0c071fdau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071fdc;
P_0c071fdc: /* original f031, guest PC 0x0c071fdc */
if(!s->budget--) { s->failed_pc=0x0c071fdcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071fde;
P_0c071fde: /* original f258, guest PC 0x0c071fde */
if(!s->budget--) { s->failed_pc=0x0c071fdeu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071fe0;
P_0c071fe0: /* original f568, guest PC 0x0c071fe0 */
if(!s->budget--) { s->failed_pc=0x0c071fe0u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071fe2;
P_0c071fe2: /* original f141, guest PC 0x0c071fe2 */
if(!s->budget--) { s->failed_pc=0x0c071fe2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071fe4;
P_0c071fe4: /* original f251, guest PC 0x0c071fe4 */
if(!s->budget--) { s->failed_pc=0x0c071fe4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071fe6;
P_0c071fe6: /* original 7408, guest PC 0x0c071fe6 */
if(!s->budget--) { s->failed_pc=0x0c071fe6u; return 0; }
r[4]+=0x00000008u;
goto P_0c071fe8;
P_0c071fe8: /* original f42a, guest PC 0x0c071fe8 */
if(!s->budget--) { s->failed_pc=0x0c071fe8u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071fea;
P_0c071fea: /* original f41b, guest PC 0x0c071fea */
if(!s->budget--) { s->failed_pc=0x0c071feau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071fec;
P_0c071fec: /* original f40b, guest PC 0x0c071fec */
if(!s->budget--) { s->failed_pc=0x0c071fecu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071fee;
P_0c071fee: /* original 0009, guest PC 0x0c071fee */
if(!s->budget--) { s->failed_pc=0x0c071feeu; return 0; }
goto P_0c071ff0;
P_0c071ff0: /* original 64a3, guest PC 0x0c071ff0 */
if(!s->budget--) { s->failed_pc=0x0c071ff0u; return 0; }
r[4]=r[10];
goto P_0c071ff2;
P_0c071ff2: /* original 6583, guest PC 0x0c071ff2 */
if(!s->budget--) { s->failed_pc=0x0c071ff2u; return 0; }
r[5]=r[8];
goto P_0c071ff4;
P_0c071ff4: /* original 66e3, guest PC 0x0c071ff4 */
if(!s->budget--) { s->failed_pc=0x0c071ff4u; return 0; }
r[6]=r[14];
goto P_0c071ff6;
P_0c071ff6: /* original f059, guest PC 0x0c071ff6 */
if(!s->budget--) { s->failed_pc=0x0c071ff6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ff8;
P_0c071ff8: /* original f369, guest PC 0x0c071ff8 */
if(!s->budget--) { s->failed_pc=0x0c071ff8u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071ffa;
P_0c071ffa: /* original f159, guest PC 0x0c071ffa */
if(!s->budget--) { s->failed_pc=0x0c071ffau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ffc;
P_0c071ffc: /* original f469, guest PC 0x0c071ffc */
if(!s->budget--) { s->failed_pc=0x0c071ffcu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071ffe;
P_0c071ffe: /* original f031, guest PC 0x0c071ffe */
if(!s->budget--) { s->failed_pc=0x0c071ffeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c072000;
P_0c072000: /* original f258, guest PC 0x0c072000 */
if(!s->budget--) { s->failed_pc=0x0c072000u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c072002;
P_0c072002: /* original f568, guest PC 0x0c072002 */
if(!s->budget--) { s->failed_pc=0x0c072002u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c072004;
P_0c072004: /* original f141, guest PC 0x0c072004 */
if(!s->budget--) { s->failed_pc=0x0c072004u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c072006;
P_0c072006: /* original f251, guest PC 0x0c072006 */
if(!s->budget--) { s->failed_pc=0x0c072006u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c072008;
P_0c072008: /* original 7408, guest PC 0x0c072008 */
if(!s->budget--) { s->failed_pc=0x0c072008u; return 0; }
r[4]+=0x00000008u;
goto P_0c07200a;
P_0c07200a: /* original f42a, guest PC 0x0c07200a */
if(!s->budget--) { s->failed_pc=0x0c07200au; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07200c;
P_0c07200c: /* original f41b, guest PC 0x0c07200c */
if(!s->budget--) { s->failed_pc=0x0c07200cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07200e;
P_0c07200e: /* original f40b, guest PC 0x0c07200e */
if(!s->budget--) { s->failed_pc=0x0c07200eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072010;
P_0c072010: /* original 66e3, guest PC 0x0c072010 */
if(!s->budget--) { s->failed_pc=0x0c072010u; return 0; }
r[6]=r[14];
goto P_0c072012;
P_0c072012: /* original 64d3, guest PC 0x0c072012 */
if(!s->budget--) { s->failed_pc=0x0c072012u; return 0; }
r[4]=r[13];
goto P_0c072014;
P_0c072014: /* original 65a3, guest PC 0x0c072014 */
if(!s->budget--) { s->failed_pc=0x0c072014u; return 0; }
r[5]=r[10];
goto P_0c072016;
P_0c072016: /* original 760c, guest PC 0x0c072016 */
if(!s->budget--) { s->failed_pc=0x0c072016u; return 0; }
r[6]+=0x0000000cu;
goto P_0c072018;
P_0c072018: /* original f049, guest PC 0x0c072018 */
if(!s->budget--) { s->failed_pc=0x0c072018u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07201a;
P_0c07201a: /* original f549, guest PC 0x0c07201a */
if(!s->budget--) { s->failed_pc=0x0c07201au; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07201c;
P_0c07201c: /* original f648, guest PC 0x0c07201c */
if(!s->budget--) { s->failed_pc=0x0c07201cu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c07201e;
P_0c07201e: /* original f859, guest PC 0x0c07201e */
if(!s->budget--) { s->failed_pc=0x0c07201eu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072020;
P_0c072020: /* original f959, guest PC 0x0c072020 */
if(!s->budget--) { s->failed_pc=0x0c072020u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072022;
P_0c072022: /* original fa58, guest PC 0x0c072022 */
if(!s->budget--) { s->failed_pc=0x0c072022u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c072024;
P_0c072024: /* original 760c, guest PC 0x0c072024 */
if(!s->budget--) { s->failed_pc=0x0c072024u; return 0; }
r[6]+=0x0000000cu;
goto P_0c072026;
P_0c072026: /* original f35c, guest PC 0x0c072026 */
if(!s->budget--) { s->failed_pc=0x0c072026u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c072028;
P_0c072028: /* original f382, guest PC 0x0c072028 */
if(!s->budget--) { s->failed_pc=0x0c072028u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c07202a;
P_0c07202a: /* original f20c, guest PC 0x0c07202a */
if(!s->budget--) { s->failed_pc=0x0c07202au; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c07202c;
P_0c07202c: /* original f2a2, guest PC 0x0c07202c */
if(!s->budget--) { s->failed_pc=0x0c07202cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c07202e;
P_0c07202e: /* original f16c, guest PC 0x0c07202e */
if(!s->budget--) { s->failed_pc=0x0c07202eu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c072030;
P_0c072030: /* original f192, guest PC 0x0c072030 */
if(!s->budget--) { s->failed_pc=0x0c072030u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c072032;
P_0c072032: /* original f34d, guest PC 0x0c072032 */
if(!s->budget--) { s->failed_pc=0x0c072032u; return 0; }
fr[3]^=0x80000000u;
goto P_0c072034;
P_0c072034: /* original f39e, guest PC 0x0c072034 */
if(!s->budget--) { s->failed_pc=0x0c072034u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c072036;
P_0c072036: /* original f24d, guest PC 0x0c072036 */
if(!s->budget--) { s->failed_pc=0x0c072036u; return 0; }
fr[2]^=0x80000000u;
goto P_0c072038;
P_0c072038: /* original f06c, guest PC 0x0c072038 */
if(!s->budget--) { s->failed_pc=0x0c072038u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c07203a;
P_0c07203a: /* original f28e, guest PC 0x0c07203a */
if(!s->budget--) { s->failed_pc=0x0c07203au; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c07203c;
P_0c07203c: /* original f14d, guest PC 0x0c07203c */
if(!s->budget--) { s->failed_pc=0x0c07203cu; return 0; }
fr[1]^=0x80000000u;
goto P_0c07203e;
P_0c07203e: /* original f63b, guest PC 0x0c07203e */
if(!s->budget--) { s->failed_pc=0x0c07203eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c072040;
P_0c072040: /* original f05c, guest PC 0x0c072040 */
if(!s->budget--) { s->failed_pc=0x0c072040u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c072042;
P_0c072042: /* original f1ae, guest PC 0x0c072042 */
if(!s->budget--) { s->failed_pc=0x0c072042u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c072044;
P_0c072044: /* original f62b, guest PC 0x0c072044 */
if(!s->budget--) { s->failed_pc=0x0c072044u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c072046;
P_0c072046: /* original f61b, guest PC 0x0c072046 */
if(!s->budget--) { s->failed_pc=0x0c072046u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c072048;
P_0c072048: /* original 64e3, guest PC 0x0c072048 */
if(!s->budget--) { s->failed_pc=0x0c072048u; return 0; }
r[4]=r[14];
goto P_0c07204a;
P_0c07204a: /* original 740c, guest PC 0x0c07204a */
if(!s->budget--) { s->failed_pc=0x0c07204au; return 0; }
r[4]+=0x0000000cu;
goto P_0c07204c;
P_0c07204c: /* original f049, guest PC 0x0c07204c */
if(!s->budget--) { s->failed_pc=0x0c07204cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07204e;
P_0c07204e: /* original f149, guest PC 0x0c07204e */
if(!s->budget--) { s->failed_pc=0x0c07204eu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072050;
P_0c072050: /* original f249, guest PC 0x0c072050 */
if(!s->budget--) { s->failed_pc=0x0c072050u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072052;
P_0c072052: /* original f38d, guest PC 0x0c072052 */
if(!s->budget--) { s->failed_pc=0x0c072052u; return 0; }
fr[3]=0;
goto P_0c072054;
P_0c072054: /* original f0ed, guest PC 0x0c072054 */
if(!s->budget--) { s->failed_pc=0x0c072054u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c072056;
P_0c072056: /* original f37d, guest PC 0x0c072056 */
if(!s->budget--) { s->failed_pc=0x0c072056u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c072058;
P_0c072058: /* original f232, guest PC 0x0c072058 */
if(!s->budget--) { s->failed_pc=0x0c072058u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07205a;
P_0c07205a: /* original f132, guest PC 0x0c07205a */
if(!s->budget--) { s->failed_pc=0x0c07205au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c07205c;
P_0c07205c: /* original f032, guest PC 0x0c07205c */
if(!s->budget--) { s->failed_pc=0x0c07205cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c07205e;
P_0c07205e: /* original f42b, guest PC 0x0c07205e */
if(!s->budget--) { s->failed_pc=0x0c07205eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c072060;
P_0c072060: /* original f41b, guest PC 0x0c072060 */
if(!s->budget--) { s->failed_pc=0x0c072060u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c072062;
P_0c072062: /* original f40b, guest PC 0x0c072062 */
if(!s->budget--) { s->failed_pc=0x0c072062u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072064;
P_0c072064: /* original 7f60, guest PC 0x0c072064 */
if(!s->budget--) { s->failed_pc=0x0c072064u; return 0; }
r[15]+=0x00000060u;
goto P_0c072066;
P_0c072066: /* original 68f6, guest PC 0x0c072066 */
if(!s->budget--) { s->failed_pc=0x0c072066u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c072068;
P_0c072068: /* original 69f6, guest PC 0x0c072068 */
if(!s->budget--) { s->failed_pc=0x0c072068u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07206a;
P_0c07206a: /* original 6af6, guest PC 0x0c07206a */
if(!s->budget--) { s->failed_pc=0x0c07206au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07206c;
P_0c07206c: /* original 6bf6, guest PC 0x0c07206c */
if(!s->budget--) { s->failed_pc=0x0c07206cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07206e;
P_0c07206e: /* original 6cf6, guest PC 0x0c07206e */
if(!s->budget--) { s->failed_pc=0x0c07206eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c072070;
P_0c072070: /* original 6df6, guest PC 0x0c072070 */
if(!s->budget--) { s->failed_pc=0x0c072070u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c072072;
P_0c072072: /* original 000b, guest PC 0x0c072072 */
if(!s->budget--) { s->failed_pc=0x0c072072u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c072074: /* original 6ef6, guest PC 0x0c072074 */
if(!s->budget--) { s->failed_pc=0x0c072074u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c072076u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c03550cu,0x0c03550eu,0x0c035510u,0x0c035512u,0x0c035514u,0x0c035516u,0x0c035518u,0x0c03551au,0x0c03551cu,0x0c03551eu,0x0c035520u,0x0c035522u,0x0c035524u,0x0c035526u,0x0c035528u,0x0c03552au,
0x0c03552cu,0x0c03552eu,0x0c035530u,0x0c035532u,0x0c035534u,0x0c035536u,0x0c035538u,0x0c03553au,0x0c03553cu,0x0c03553eu,0x0c035540u,0x0c035542u,0x0c035544u,0x0c035546u,0x0c035548u,0x0c03554au,
0x0c03554cu,0x0c03554eu,0x0c035550u,0x0c035552u,0x0c035554u,0x0c035556u,0x0c035558u,0x0c03555au,0x0c03555cu,0x0c03555eu,0x0c035560u,0x0c035562u,0x0c035564u,0x0c035566u,0x0c035568u,0x0c03556au,
0x0c03556cu,0x0c03556eu,0x0c035570u,0x0c035572u,0x0c035574u,0x0c035576u,0x0c035578u,0x0c03557au,0x0c03557cu,0x0c03557eu,0x0c035580u,0x0c035582u,0x0c035584u,0x0c035586u,0x0c035588u,0x0c03558au,
0x0c03558cu,0x0c0355a4u,0x0c0355a6u,0x0c0355a8u,0x0c0355aau,0x0c0355acu,0x0c0355aeu,0x0c0355b0u,0x0c0355b2u,0x0c0355b4u,0x0c0355b6u,0x0c0355b8u,0x0c0355bau,0x0c0355bcu,0x0c0355beu,0x0c0355c0u,
0x0c0355c2u,0x0c0355c4u,0x0c0355c6u,0x0c0355c8u,0x0c035a20u,0x0c035a22u,0x0c035a24u,0x0c035a26u,0x0c035a28u,0x0c035a2au,0x0c035a2cu,0x0c035a2eu,0x0c035a30u,0x0c035a32u,0x0c035a34u,0x0c035a36u,
0x0c035a4eu,0x0c035a50u,0x0c035a52u,0x0c035a54u,0x0c035a56u,0x0c035a58u,0x0c035a5au,0x0c035a5cu,0x0c035a5eu,0x0c035a60u,0x0c035a62u,0x0c035a64u,0x0c035a66u,0x0c035a68u,0x0c035a6au,0x0c035a6cu,
0x0c035a6eu,0x0c035a70u,0x0c035a72u,0x0c035a74u,0x0c035a76u,0x0c035a78u,0x0c035a7au,0x0c035a7cu,0x0c035a7eu,0x0c035a80u,0x0c035a82u,0x0c035a84u,0x0c035a86u,0x0c035a88u,0x0c035a8au,0x0c035a8cu,
0x0c035a8eu,0x0c035a90u,0x0c035a92u,0x0c035a94u,0x0c035a96u,0x0c035a98u,0x0c035a9au,0x0c035a9cu,0x0c035a9eu,0x0c035aa0u,0x0c06f892u,0x0c06f894u,0x0c06f896u,0x0c06f898u,0x0c06f89au,0x0c06f89cu,
0x0c06f89eu,0x0c06f8a0u,0x0c06f8a2u,0x0c06f8a4u,0x0c06f8a6u,0x0c06f8a8u,0x0c06f8aau,0x0c06f8acu,0x0c06f8aeu,0x0c06f8b0u,0x0c06f8b2u,0x0c06f8b4u,0x0c06f8b6u,0x0c06f8b8u,0x0c06f8bau,0x0c06f8bcu,
0x0c06f8beu,0x0c06f8c0u,0x0c06f8c2u,0x0c06f8c4u,0x0c06f8c6u,0x0c06f8c8u,0x0c06f8cau,0x0c06f8ccu,0x0c06f8ceu,0x0c06f8d0u,0x0c06f8d2u,0x0c06f8d4u,0x0c06f8d6u,0x0c06f8d8u,0x0c06f8dau,0x0c06f8dcu,
0x0c06f8deu,0x0c06f8e0u,0x0c06f8e2u,0x0c06f8e4u,0x0c06f8e6u,0x0c06f8e8u,0x0c06f8eau,0x0c06f8ecu,0x0c06f8eeu,0x0c06f8f0u,0x0c06f8f2u,0x0c06f8f4u,0x0c06f8f6u,0x0c06f8f8u,0x0c06f8fau,0x0c06f8fcu,
0x0c06f8feu,0x0c06f900u,0x0c06f902u,0x0c06f904u,0x0c06f906u,0x0c06f908u,0x0c06f90au,0x0c06f90cu,0x0c06f90eu,0x0c06f910u,0x0c06f912u,0x0c06f914u,0x0c06f916u,0x0c06f918u,0x0c06f91au,0x0c06f91cu,
0x0c06f91eu,0x0c06f920u,0x0c06f922u,0x0c06f924u,0x0c06f926u,0x0c06f928u,0x0c06f92au,0x0c06f92cu,0x0c06f92eu,0x0c06f930u,0x0c06f932u,0x0c06f934u,0x0c06f936u,0x0c06f938u,0x0c06f93au,0x0c06f93cu,
0x0c06f93eu,0x0c06f940u,0x0c06f942u,0x0c06f944u,0x0c06f946u,0x0c06f948u,0x0c06f94au,0x0c06f94cu,0x0c06f94eu,0x0c06f950u,0x0c06f952u,0x0c06f954u,0x0c06f956u,0x0c06f958u,0x0c06f95au,0x0c06f95cu,
0x0c06f95eu,0x0c06f960u,0x0c06f962u,0x0c06f964u,0x0c06f966u,0x0c06f968u,0x0c06f96au,0x0c06f96cu,0x0c06f96eu,0x0c06f970u,0x0c06f972u,0x0c06f974u,0x0c06f976u,0x0c06f978u,0x0c06f97au,0x0c06f97cu,
0x0c06f97eu,0x0c06f980u,0x0c06f982u,0x0c06f984u,0x0c06f986u,0x0c06f988u,0x0c06f98au,0x0c06f98cu,0x0c06f98eu,0x0c06f990u,0x0c071806u,0x0c071808u,0x0c07180au,0x0c07180cu,0x0c07180eu,0x0c071810u,
0x0c071812u,0x0c071814u,0x0c071816u,0x0c071818u,0x0c07181au,0x0c07181cu,0x0c07181eu,0x0c071820u,0x0c071822u,0x0c071824u,0x0c071826u,0x0c071828u,0x0c07182au,0x0c07182cu,0x0c07182eu,0x0c071830u,
0x0c071832u,0x0c071834u,0x0c071836u,0x0c071838u,0x0c07183au,0x0c07183cu,0x0c07183eu,0x0c071840u,0x0c071842u,0x0c071844u,0x0c071846u,0x0c071848u,0x0c07184au,0x0c07184cu,0x0c07184eu,0x0c071850u,
0x0c071852u,0x0c071854u,0x0c071856u,0x0c071858u,0x0c07185au,0x0c07185cu,0x0c07185eu,0x0c071860u,0x0c071862u,0x0c071864u,0x0c071866u,0x0c071868u,0x0c07186au,0x0c07186cu,0x0c07186eu,0x0c071870u,
0x0c071878u,0x0c07187au,0x0c07187cu,0x0c07187eu,0x0c071880u,0x0c071882u,0x0c071884u,0x0c071886u,0x0c071888u,0x0c07188au,0x0c07188cu,0x0c07188eu,0x0c071890u,0x0c071892u,0x0c071894u,0x0c071896u,
0x0c071898u,0x0c07189au,0x0c07189cu,0x0c07189eu,0x0c0718a0u,0x0c0718a2u,0x0c0718a4u,0x0c0718a6u,0x0c0718a8u,0x0c0718aau,0x0c0718acu,0x0c0718aeu,0x0c0718b0u,0x0c0718b2u,0x0c0718b4u,0x0c0718b6u,
0x0c0718b8u,0x0c0718bau,0x0c0718bcu,0x0c0718beu,0x0c0718c0u,0x0c0718c2u,0x0c0718c4u,0x0c0718c6u,0x0c0718c8u,0x0c0718cau,0x0c0718ccu,0x0c0718ceu,0x0c0718d0u,0x0c0718d2u,0x0c0718d4u,0x0c0718d6u,
0x0c0718d8u,0x0c0718dau,0x0c0718dcu,0x0c0718deu,0x0c0718e0u,0x0c0718e2u,0x0c0718e4u,0x0c0718e6u,0x0c0718e8u,0x0c0718eau,0x0c0718ecu,0x0c0718eeu,0x0c0718f0u,0x0c0718f2u,0x0c0718f4u,0x0c0718f6u,
0x0c0718f8u,0x0c0718fau,0x0c0718fcu,0x0c0718feu,0x0c071900u,0x0c071902u,0x0c071904u,0x0c071906u,0x0c071908u,0x0c07190au,0x0c07190cu,0x0c07190eu,0x0c071910u,0x0c071912u,0x0c071914u,0x0c071916u,
0x0c071918u,0x0c07191au,0x0c07191cu,0x0c07191eu,0x0c071920u,0x0c071a32u,0x0c071a34u,0x0c071a36u,0x0c071a38u,0x0c071a3au,0x0c071a3cu,0x0c071a3eu,0x0c071a40u,0x0c071a42u,0x0c071a44u,0x0c071a46u,
0x0c071a48u,0x0c071a4au,0x0c071a4cu,0x0c071a4eu,0x0c071a50u,0x0c071a52u,0x0c071a54u,0x0c071a56u,0x0c071a58u,0x0c071a5au,0x0c071a5cu,0x0c071a5eu,0x0c071a60u,0x0c071a62u,0x0c071a64u,0x0c071a66u,
0x0c071a68u,0x0c071a6au,0x0c071a6cu,0x0c071a6eu,0x0c071a70u,0x0c071a72u,0x0c071a74u,0x0c071a76u,0x0c071a78u,0x0c071a7au,0x0c071a7cu,0x0c071a7eu,0x0c071a80u,0x0c071a82u,0x0c071a84u,0x0c071a86u,
0x0c071a88u,0x0c071a8au,0x0c071a8cu,0x0c071a8eu,0x0c071a90u,0x0c071a92u,0x0c071a94u,0x0c071a96u,0x0c071a98u,0x0c071a9au,0x0c071a9cu,0x0c071a9eu,0x0c071aa4u,0x0c071aa6u,0x0c071aa8u,0x0c071aaau,
0x0c071aacu,0x0c071aaeu,0x0c071ab0u,0x0c071ab2u,0x0c071ab4u,0x0c071ab6u,0x0c071ab8u,0x0c071abau,0x0c071abcu,0x0c071abeu,0x0c071ac0u,0x0c071ac2u,0x0c071ac4u,0x0c071ac6u,0x0c071ac8u,0x0c071acau,
0x0c071accu,0x0c071aceu,0x0c071ad0u,0x0c071ad2u,0x0c071ad4u,0x0c071ad6u,0x0c071ad8u,0x0c071adau,0x0c071adcu,0x0c071adeu,0x0c071ae0u,0x0c071ae2u,0x0c071ae4u,0x0c071ae6u,0x0c071ae8u,0x0c071aeau,
0x0c071aecu,0x0c071aeeu,0x0c071af0u,0x0c071af2u,0x0c071af4u,0x0c071af6u,0x0c071af8u,0x0c071afau,0x0c071afcu,0x0c071afeu,0x0c071b00u,0x0c071b02u,0x0c071b04u,0x0c071b06u,0x0c071b08u,0x0c071b0au,
0x0c071b0cu,0x0c071b0eu,0x0c071b10u,0x0c071b12u,0x0c071b14u,0x0c071b16u,0x0c071b18u,0x0c071b1au,0x0c071b1cu,0x0c071b1eu,0x0c071b20u,0x0c071b22u,0x0c071b24u,0x0c071b26u,0x0c071b28u,0x0c071b2au,
0x0c071b2cu,0x0c071b2eu,0x0c071b30u,0x0c071b32u,0x0c071b34u,0x0c071b36u,0x0c071b38u,0x0c071b3au,0x0c071b3cu,0x0c071b3eu,0x0c071b40u,0x0c071b42u,0x0c071b44u,0x0c071b46u,0x0c071b48u,0x0c071b4au,
0x0c071b4cu,0x0c071b4eu,0x0c071b50u,0x0c071b52u,0x0c071b54u,0x0c071b56u,0x0c071b58u,0x0c071b5au,0x0c071b5cu,0x0c071b5eu,0x0c071b60u,0x0c071b62u,0x0c071b64u,0x0c071b66u,0x0c071b68u,0x0c071b6au,
0x0c071b6cu,0x0c071b6eu,0x0c071b70u,0x0c071b72u,0x0c071b74u,0x0c071b76u,0x0c071b78u,0x0c071b7au,0x0c071b7cu,0x0c071b7eu,0x0c071b80u,0x0c071b82u,0x0c071b84u,0x0c071b86u,0x0c071b88u,0x0c071b8au,
0x0c071b8cu,0x0c071b8eu,0x0c071b90u,0x0c071b92u,0x0c071b94u,0x0c071b96u,0x0c071b98u,0x0c071b9au,0x0c071b9cu,0x0c071b9eu,0x0c071ba0u,0x0c071ba2u,0x0c071ba4u,0x0c071ba6u,0x0c071ba8u,0x0c071baau,
0x0c071bacu,0x0c071baeu,0x0c071bb0u,0x0c071bb2u,0x0c071bb4u,0x0c071bb6u,0x0c071bb8u,0x0c071bbau,0x0c071bbcu,0x0c071bbeu,0x0c071bc0u,0x0c071bc2u,0x0c071bc4u,0x0c071bc6u,0x0c071bc8u,0x0c071bcau,
0x0c071bccu,0x0c071bceu,0x0c071bd0u,0x0c071bd2u,0x0c071bd4u,0x0c071bd6u,0x0c071bd8u,0x0c071bdau,0x0c071bdcu,0x0c071bdeu,0x0c071be0u,0x0c071be2u,0x0c071be4u,0x0c071be6u,0x0c071be8u,0x0c071beau,
0x0c071becu,0x0c071beeu,0x0c071bf0u,0x0c071bf2u,0x0c071bf4u,0x0c071bf6u,0x0c071bf8u,0x0c071bfau,0x0c071bfcu,0x0c071bfeu,0x0c071c00u,0x0c071c02u,0x0c071c04u,0x0c071c06u,0x0c071c08u,0x0c071c0au,
0x0c071c0cu,0x0c071c0eu,0x0c071c10u,0x0c071c12u,0x0c071c14u,0x0c071c16u,0x0c071c18u,0x0c071c1au,0x0c071c1cu,0x0c071c1eu,0x0c071c20u,0x0c071c22u,0x0c071c24u,0x0c071c26u,0x0c071c28u,0x0c071c2au,
0x0c071c2cu,0x0c071c2eu,0x0c071c30u,0x0c071c32u,0x0c071c38u,0x0c071c3au,0x0c071c3cu,0x0c071c3eu,0x0c071c40u,0x0c071c42u,0x0c071c44u,0x0c071c46u,0x0c071c48u,0x0c071c4au,0x0c071c4cu,0x0c071c4eu,
0x0c071c50u,0x0c071c52u,0x0c071c54u,0x0c071c56u,0x0c071c58u,0x0c071c5au,0x0c071c5cu,0x0c071c5eu,0x0c071c60u,0x0c071c62u,0x0c071c64u,0x0c071c66u,0x0c071c68u,0x0c071c6au,0x0c071c6cu,0x0c071c6eu,
0x0c071c70u,0x0c071c72u,0x0c071c74u,0x0c071c76u,0x0c071c78u,0x0c071c7au,0x0c071c7cu,0x0c071c7eu,0x0c071c80u,0x0c071c82u,0x0c071c84u,0x0c071c86u,0x0c071c88u,0x0c071c8au,0x0c071c8cu,0x0c071c8eu,
0x0c071c90u,0x0c071c92u,0x0c071c94u,0x0c071c96u,0x0c071c98u,0x0c071c9au,0x0c071c9cu,0x0c071c9eu,0x0c071ca0u,0x0c071ca2u,0x0c071ca4u,0x0c071ca6u,0x0c071ca8u,0x0c071caau,0x0c071cacu,0x0c071caeu,
0x0c071cb0u,0x0c071cb2u,0x0c071cb4u,0x0c071cb6u,0x0c071cb8u,0x0c071cbau,0x0c071cbcu,0x0c071cbeu,0x0c071cc0u,0x0c071cc2u,0x0c071cc4u,0x0c071cc6u,0x0c071cc8u,0x0c071ccau,0x0c071cccu,0x0c071cceu,
0x0c071cd0u,0x0c071cd2u,0x0c071cd4u,0x0c071cd6u,0x0c071cd8u,0x0c071cdau,0x0c071cdcu,0x0c071cdeu,0x0c071ce0u,0x0c071ce2u,0x0c071ce4u,0x0c071ce6u,0x0c071ce8u,0x0c071ceau,0x0c071cecu,0x0c071ceeu,
0x0c071cf0u,0x0c071cf2u,0x0c071cf4u,0x0c071cf6u,0x0c071cf8u,0x0c071cfau,0x0c071cfcu,0x0c071cfeu,0x0c071d00u,0x0c071d02u,0x0c071d04u,0x0c071d06u,0x0c071d08u,0x0c071d0au,0x0c071d0cu,0x0c071d0eu,
0x0c071d10u,0x0c071d12u,0x0c071d14u,0x0c071d16u,0x0c071d18u,0x0c071d1au,0x0c071d1cu,0x0c071d1eu,0x0c071d20u,0x0c071d22u,0x0c071d24u,0x0c071d26u,0x0c071d28u,0x0c071d2au,0x0c071d2cu,0x0c071d2eu,
0x0c071d30u,0x0c071d32u,0x0c071d34u,0x0c071d36u,0x0c071d38u,0x0c071d3au,0x0c071d3cu,0x0c071d3eu,0x0c071d40u,0x0c071d42u,0x0c071d44u,0x0c071d46u,0x0c071d48u,0x0c071d4au,0x0c071d4cu,0x0c071d4eu,
0x0c071d50u,0x0c071d52u,0x0c071d54u,0x0c071d56u,0x0c071d58u,0x0c071d5au,0x0c071d5cu,0x0c071d5eu,0x0c071d60u,0x0c071d62u,0x0c071d64u,0x0c071d66u,0x0c071d68u,0x0c071d6au,0x0c071d6cu,0x0c071d6eu,
0x0c071d70u,0x0c071d72u,0x0c071d74u,0x0c071d76u,0x0c071d78u,0x0c071d7au,0x0c071d7cu,0x0c071d7eu,0x0c071d80u,0x0c071d82u,0x0c071d84u,0x0c071d86u,0x0c071d88u,0x0c071d8au,0x0c071d8cu,0x0c071d8eu,
0x0c071d90u,0x0c071d92u,0x0c071d94u,0x0c071d96u,0x0c071d98u,0x0c071d9au,0x0c071d9cu,0x0c071d9eu,0x0c071da0u,0x0c071da2u,0x0c071da4u,0x0c071da6u,0x0c071dacu,0x0c071daeu,0x0c071db0u,0x0c071db2u,
0x0c071db4u,0x0c071db6u,0x0c071db8u,0x0c071dbau,0x0c071dbcu,0x0c071dbeu,0x0c071dc0u,0x0c071dc2u,0x0c071dc4u,0x0c071dc6u,0x0c071dc8u,0x0c071dcau,0x0c071dccu,0x0c071dceu,0x0c071dd0u,0x0c071dd2u,
0x0c071dd4u,0x0c071dd6u,0x0c071dd8u,0x0c071ddau,0x0c071ddcu,0x0c071ddeu,0x0c071de0u,0x0c071de2u,0x0c071de4u,0x0c071de6u,0x0c071de8u,0x0c071deau,0x0c071decu,0x0c071deeu,0x0c071df0u,0x0c071df2u,
0x0c071df4u,0x0c071df6u,0x0c071df8u,0x0c071dfau,0x0c071dfcu,0x0c071dfeu,0x0c071e00u,0x0c071e02u,0x0c071e04u,0x0c071e06u,0x0c071e08u,0x0c071e0au,0x0c071e0cu,0x0c071e0eu,0x0c071e10u,0x0c071e12u,
0x0c071e14u,0x0c071e16u,0x0c071e18u,0x0c071e1au,0x0c071e1cu,0x0c071e1eu,0x0c071e20u,0x0c071e22u,0x0c071e24u,0x0c071e26u,0x0c071e28u,0x0c071e2au,0x0c071e2cu,0x0c071e2eu,0x0c071e30u,0x0c071e32u,
0x0c071e34u,0x0c071e36u,0x0c071e38u,0x0c071e3au,0x0c071e3cu,0x0c071e3eu,0x0c071e40u,0x0c071e42u,0x0c071e44u,0x0c071e46u,0x0c071e48u,0x0c071e4au,0x0c071e4cu,0x0c071e4eu,0x0c071e50u,0x0c071e52u,
0x0c071e54u,0x0c071e56u,0x0c071e58u,0x0c071e5au,0x0c071e5cu,0x0c071e64u,0x0c071e66u,0x0c071e68u,0x0c071e6au,0x0c071e6cu,0x0c071e6eu,0x0c071e70u,0x0c071e72u,0x0c071e74u,0x0c071e76u,0x0c071e78u,
0x0c071e7au,0x0c071e7cu,0x0c071e7eu,0x0c071e80u,0x0c071e82u,0x0c071e84u,0x0c071e86u,0x0c071e88u,0x0c071e8au,0x0c071e8cu,0x0c071e8eu,0x0c071e90u,0x0c071e92u,0x0c071e94u,0x0c071e96u,0x0c071e98u,
0x0c071e9au,0x0c071e9cu,0x0c071e9eu,0x0c071ea0u,0x0c071ea2u,0x0c071ea4u,0x0c071ea6u,0x0c071ea8u,0x0c071eaau,0x0c071eacu,0x0c071eaeu,0x0c071eb0u,0x0c071eb2u,0x0c071eb4u,0x0c071eb6u,0x0c071eb8u,
0x0c071ebau,0x0c071ebcu,0x0c071ebeu,0x0c071ec0u,0x0c071ec2u,0x0c071ec4u,0x0c071ec6u,0x0c071ec8u,0x0c071ecau,0x0c071eccu,0x0c071eceu,0x0c071ed0u,0x0c071ed2u,0x0c071ed4u,0x0c071ed6u,0x0c071ed8u,
0x0c071edau,0x0c071edcu,0x0c071edeu,0x0c071ee0u,0x0c071ee2u,0x0c071ee4u,0x0c071ee6u,0x0c071ee8u,0x0c071eeau,0x0c071eecu,0x0c071eeeu,0x0c071ef0u,0x0c071ef2u,0x0c071ef4u,0x0c071ef6u,0x0c071ef8u,
0x0c071efau,0x0c071efcu,0x0c071efeu,0x0c071f00u,0x0c071f02u,0x0c071f04u,0x0c071f06u,0x0c071f08u,0x0c071f0au,0x0c071f0cu,0x0c071f0eu,0x0c071f10u,0x0c071f12u,0x0c071f14u,0x0c071f16u,0x0c071f18u,
0x0c071f1au,0x0c071f1cu,0x0c071f1eu,0x0c071f20u,0x0c071f22u,0x0c071f24u,0x0c071f26u,0x0c071f28u,0x0c071f2au,0x0c071f2cu,0x0c071f2eu,0x0c071f30u,0x0c071f32u,0x0c071f34u,0x0c071f36u,0x0c071f38u,
0x0c071f3au,0x0c071f3cu,0x0c071f3eu,0x0c071f40u,0x0c071f42u,0x0c071f44u,0x0c071f46u,0x0c071f48u,0x0c071f4au,0x0c071f4cu,0x0c071f4eu,0x0c071f50u,0x0c071f52u,0x0c071f54u,0x0c071f56u,0x0c071f58u,
0x0c071f5au,0x0c071f5cu,0x0c071f5eu,0x0c071f60u,0x0c071f62u,0x0c071f64u,0x0c071f66u,0x0c071f68u,0x0c071f6au,0x0c071f6cu,0x0c071f6eu,0x0c071f70u,0x0c071f72u,0x0c071f74u,0x0c071f76u,0x0c071f78u,
0x0c071f7au,0x0c071f7cu,0x0c071f7eu,0x0c071f80u,0x0c071f82u,0x0c071f84u,0x0c071f86u,0x0c071f88u,0x0c071f8au,0x0c071f8cu,0x0c071f8eu,0x0c071f90u,0x0c071f92u,0x0c071f94u,0x0c071f96u,0x0c071f98u,
0x0c071f9au,0x0c071f9cu,0x0c071f9eu,0x0c071fa0u,0x0c071fa2u,0x0c071fa4u,0x0c071fa6u,0x0c071fa8u,0x0c071faau,0x0c071facu,0x0c071faeu,0x0c071fb0u,0x0c071fb2u,0x0c071fb4u,0x0c071fb6u,0x0c071fb8u,
0x0c071fbau,0x0c071fbcu,0x0c071fbeu,0x0c071fc0u,0x0c071fc2u,0x0c071fc4u,0x0c071fc6u,0x0c071fc8u,0x0c071fcau,0x0c071fccu,0x0c071fd4u,0x0c071fd6u,0x0c071fd8u,0x0c071fdau,0x0c071fdcu,0x0c071fdeu,
0x0c071fe0u,0x0c071fe2u,0x0c071fe4u,0x0c071fe6u,0x0c071fe8u,0x0c071feau,0x0c071fecu,0x0c071feeu,0x0c071ff0u,0x0c071ff2u,0x0c071ff4u,0x0c071ff6u,0x0c071ff8u,0x0c071ffau,0x0c071ffcu,0x0c071ffeu,
0x0c072000u,0x0c072002u,0x0c072004u,0x0c072006u,0x0c072008u,0x0c07200au,0x0c07200cu,0x0c07200eu,0x0c072010u,0x0c072012u,0x0c072014u,0x0c072016u,0x0c072018u,0x0c07201au,0x0c07201cu,0x0c07201eu,
0x0c072020u,0x0c072022u,0x0c072024u,0x0c072026u,0x0c072028u,0x0c07202au,0x0c07202cu,0x0c07202eu,0x0c072030u,0x0c072032u,0x0c072034u,0x0c072036u,0x0c072038u,0x0c07203au,0x0c07203cu,0x0c07203eu,
0x0c072040u,0x0c072042u,0x0c072044u,0x0c072046u,0x0c072048u,0x0c07204au,0x0c07204cu,0x0c07204eu,0x0c072050u,0x0c072052u,0x0c072054u,0x0c072056u,0x0c072058u,0x0c07205au,0x0c07205cu,0x0c07205eu,
0x0c072060u,0x0c072062u,0x0c072064u,0x0c072066u,0x0c072068u,0x0c07206au,0x0c07206cu,0x0c07206eu,0x0c072070u,0x0c072072u,0x0c072074u,
};
int vf3_seventh_c7_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
