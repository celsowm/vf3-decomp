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
int vf3_away_batch215_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03a140u: goto P_0c03a140;
case 0x0c03a142u: goto P_0c03a142;
case 0x0c03a144u: goto P_0c03a144;
case 0x0c03a146u: goto P_0c03a146;
case 0x0c03a148u: goto P_0c03a148;
case 0x0c03a14au: goto P_0c03a14a;
case 0x0c03a14cu: goto P_0c03a14c;
case 0x0c03a14eu: goto P_0c03a14e;
case 0x0c03a150u: goto P_0c03a150;
case 0x0c03a152u: goto P_0c03a152;
case 0x0c03a154u: goto P_0c03a154;
case 0x0c03a156u: goto P_0c03a156;
case 0x0c03a6e0u: goto P_0c03a6e0;
case 0x0c03a6e2u: goto P_0c03a6e2;
case 0x0c03a6e4u: goto P_0c03a6e4;
case 0x0c03a6e6u: goto P_0c03a6e6;
case 0x0c03a6e8u: goto P_0c03a6e8;
case 0x0c03a6eau: goto P_0c03a6ea;
case 0x0c03a6ecu: goto P_0c03a6ec;
case 0x0c03a6eeu: goto P_0c03a6ee;
case 0x0c03a6f0u: goto P_0c03a6f0;
case 0x0c03a6f2u: goto P_0c03a6f2;
case 0x0c03a6f4u: goto P_0c03a6f4;
case 0x0c03a6f6u: goto P_0c03a6f6;
case 0x0c03a6f8u: goto P_0c03a6f8;
case 0x0c03a6fau: goto P_0c03a6fa;
case 0x0c03a6fcu: goto P_0c03a6fc;
case 0x0c03a6feu: goto P_0c03a6fe;
case 0x0c03a700u: goto P_0c03a700;
case 0x0c03a702u: goto P_0c03a702;
case 0x0c03a704u: goto P_0c03a704;
case 0x0c03a706u: goto P_0c03a706;
case 0x0c03a708u: goto P_0c03a708;
case 0x0c03a70au: goto P_0c03a70a;
case 0x0c03a70cu: goto P_0c03a70c;
case 0x0c03a70eu: goto P_0c03a70e;
case 0x0c03a710u: goto P_0c03a710;
case 0x0c03a712u: goto P_0c03a712;
case 0x0c03a714u: goto P_0c03a714;
case 0x0c03a716u: goto P_0c03a716;
case 0x0c03a718u: goto P_0c03a718;
case 0x0c03a71au: goto P_0c03a71a;
case 0x0c03a71cu: goto P_0c03a71c;
case 0x0c03a71eu: goto P_0c03a71e;
case 0x0c03a720u: goto P_0c03a720;
case 0x0c03a722u: goto P_0c03a722;
case 0x0c03a724u: goto P_0c03a724;
case 0x0c03a726u: goto P_0c03a726;
case 0x0c03a728u: goto P_0c03a728;
case 0x0c03a72au: goto P_0c03a72a;
case 0x0c03a72cu: goto P_0c03a72c;
case 0x0c03a72eu: goto P_0c03a72e;
case 0x0c03a730u: goto P_0c03a730;
case 0x0c03a732u: goto P_0c03a732;
case 0x0c03a734u: goto P_0c03a734;
case 0x0c03a736u: goto P_0c03a736;
case 0x0c03a738u: goto P_0c03a738;
case 0x0c03a73au: goto P_0c03a73a;
case 0x0c03a73cu: goto P_0c03a73c;
case 0x0c03a73eu: goto P_0c03a73e;
case 0x0c03a740u: goto P_0c03a740;
case 0x0c03a742u: goto P_0c03a742;
case 0x0c03a744u: goto P_0c03a744;
case 0x0c03a746u: goto P_0c03a746;
case 0x0c03a748u: goto P_0c03a748;
case 0x0c03a74au: goto P_0c03a74a;
case 0x0c03a750u: goto P_0c03a750;
case 0x0c03a752u: goto P_0c03a752;
case 0x0c03a754u: goto P_0c03a754;
case 0x0c03a756u: goto P_0c03a756;
case 0x0c09553cu: goto P_0c09553c;
case 0x0c09553eu: goto P_0c09553e;
case 0x0c095540u: goto P_0c095540;
case 0x0c095542u: goto P_0c095542;
case 0x0c095544u: goto P_0c095544;
case 0x0c095546u: goto P_0c095546;
case 0x0c095548u: goto P_0c095548;
case 0x0c09554au: goto P_0c09554a;
case 0x0c09554cu: goto P_0c09554c;
case 0x0c09554eu: goto P_0c09554e;
case 0x0c095550u: goto P_0c095550;
case 0x0c095552u: goto P_0c095552;
case 0x0c095554u: goto P_0c095554;
case 0x0c095556u: goto P_0c095556;
case 0x0c095558u: goto P_0c095558;
case 0x0c09555au: goto P_0c09555a;
case 0x0c09555cu: goto P_0c09555c;
case 0x0c09555eu: goto P_0c09555e;
case 0x0c095560u: goto P_0c095560;
case 0x0c095562u: goto P_0c095562;
case 0x0c095564u: goto P_0c095564;
case 0x0c095566u: goto P_0c095566;
case 0x0c095568u: goto P_0c095568;
case 0x0c09556au: goto P_0c09556a;
case 0x0c09556cu: goto P_0c09556c;
case 0x0c09556eu: goto P_0c09556e;
case 0x0c095570u: goto P_0c095570;
case 0x0c095572u: goto P_0c095572;
case 0x0c095574u: goto P_0c095574;
case 0x0c095576u: goto P_0c095576;
case 0x0c095578u: goto P_0c095578;
case 0x0c09557au: goto P_0c09557a;
case 0x0c09557cu: goto P_0c09557c;
case 0x0c09557eu: goto P_0c09557e;
case 0x0c095580u: goto P_0c095580;
case 0x0c095582u: goto P_0c095582;
case 0x0c0ae29cu: goto P_0c0ae29c;
case 0x0c0ae29eu: goto P_0c0ae29e;
case 0x0c0ae2a0u: goto P_0c0ae2a0;
case 0x0c0ae2a2u: goto P_0c0ae2a2;
case 0x0c0ae2a4u: goto P_0c0ae2a4;
case 0x0c0ae2a6u: goto P_0c0ae2a6;
case 0x0c0ae2a8u: goto P_0c0ae2a8;
case 0x0c0ae2aau: goto P_0c0ae2aa;
case 0x0c0ae2acu: goto P_0c0ae2ac;
case 0x0c0ae2aeu: goto P_0c0ae2ae;
case 0x0c0ae2b0u: goto P_0c0ae2b0;
case 0x0c0ae2b2u: goto P_0c0ae2b2;
case 0x0c0ae2b4u: goto P_0c0ae2b4;
case 0x0c0ae2b6u: goto P_0c0ae2b6;
case 0x0c0ae2b8u: goto P_0c0ae2b8;
case 0x0c0ae2bau: goto P_0c0ae2ba;
case 0x0c0ae2bcu: goto P_0c0ae2bc;
case 0x0c0ae2beu: goto P_0c0ae2be;
case 0x0c0ae2c0u: goto P_0c0ae2c0;
case 0x0c0ae2c2u: goto P_0c0ae2c2;
case 0x0c0ae2c4u: goto P_0c0ae2c4;
case 0x0c0ae2c6u: goto P_0c0ae2c6;
case 0x0c0ae2c8u: goto P_0c0ae2c8;
case 0x0c0ae2cau: goto P_0c0ae2ca;
case 0x0c0ae2ccu: goto P_0c0ae2cc;
case 0x0c0ae2ceu: goto P_0c0ae2ce;
case 0x0c0ae2d0u: goto P_0c0ae2d0;
case 0x0c0ae2d2u: goto P_0c0ae2d2;
case 0x0c0ae2d4u: goto P_0c0ae2d4;
case 0x0c0ae2d6u: goto P_0c0ae2d6;
case 0x0c0ae2d8u: goto P_0c0ae2d8;
case 0x0c0ae2dau: goto P_0c0ae2da;
case 0x0c0ae7e0u: goto P_0c0ae7e0;
case 0x0c0ae7e2u: goto P_0c0ae7e2;
case 0x0c0ae7e4u: goto P_0c0ae7e4;
case 0x0c0ae7e6u: goto P_0c0ae7e6;
case 0x0c0ae7e8u: goto P_0c0ae7e8;
case 0x0c0ae7eau: goto P_0c0ae7ea;
case 0x0c0ae7ecu: goto P_0c0ae7ec;
case 0x0c0ae7eeu: goto P_0c0ae7ee;
case 0x0c0ae7f0u: goto P_0c0ae7f0;
case 0x0c0ae7f2u: goto P_0c0ae7f2;
case 0x0c0ae7f4u: goto P_0c0ae7f4;
case 0x0c0ae7f6u: goto P_0c0ae7f6;
case 0x0c0ae7f8u: goto P_0c0ae7f8;
case 0x0c0ae7fau: goto P_0c0ae7fa;
case 0x0c0ae7fcu: goto P_0c0ae7fc;
case 0x0c0ae7feu: goto P_0c0ae7fe;
case 0x0c0ae800u: goto P_0c0ae800;
case 0x0c0ae802u: goto P_0c0ae802;
case 0x0c0ae804u: goto P_0c0ae804;
case 0x0c0ae806u: goto P_0c0ae806;
case 0x0c0ae808u: goto P_0c0ae808;
case 0x0c0ae80au: goto P_0c0ae80a;
case 0x0c0ae80cu: goto P_0c0ae80c;
case 0x0c0ae80eu: goto P_0c0ae80e;
case 0x0c0ae810u: goto P_0c0ae810;
case 0x0c0ae812u: goto P_0c0ae812;
case 0x0c0ae814u: goto P_0c0ae814;
case 0x0c0ae816u: goto P_0c0ae816;
case 0x0c0ae818u: goto P_0c0ae818;
case 0x0c0ae81au: goto P_0c0ae81a;
case 0x0c0ae81cu: goto P_0c0ae81c;
case 0x0c0ae81eu: goto P_0c0ae81e;
case 0x0c0ae820u: goto P_0c0ae820;
case 0x0c0ae822u: goto P_0c0ae822;
case 0x0c0ae824u: goto P_0c0ae824;
case 0x0c0ae826u: goto P_0c0ae826;
case 0x0c0ae828u: goto P_0c0ae828;
case 0x0c0ae82au: goto P_0c0ae82a;
case 0x0c0ae82cu: goto P_0c0ae82c;
case 0x0c0ae82eu: goto P_0c0ae82e;
case 0x0c0ae830u: goto P_0c0ae830;
case 0x0c0ae832u: goto P_0c0ae832;
case 0x0c0ae834u: goto P_0c0ae834;
case 0x0c0ae836u: goto P_0c0ae836;
case 0x0c0ae838u: goto P_0c0ae838;
case 0x0c0ae83au: goto P_0c0ae83a;
case 0x0c0ae83cu: goto P_0c0ae83c;
case 0x0c0ae83eu: goto P_0c0ae83e;
case 0x0c0ae840u: goto P_0c0ae840;
case 0x0c0ae842u: goto P_0c0ae842;
case 0x0c0ae844u: goto P_0c0ae844;
case 0x0c0ae846u: goto P_0c0ae846;
case 0x0c0ae848u: goto P_0c0ae848;
case 0x0c0ae84au: goto P_0c0ae84a;
case 0x0c0ae84cu: goto P_0c0ae84c;
case 0x0c0ae84eu: goto P_0c0ae84e;
case 0x0c0ae850u: goto P_0c0ae850;
case 0x0c0ae852u: goto P_0c0ae852;
case 0x0c0ae854u: goto P_0c0ae854;
case 0x0c0ae856u: goto P_0c0ae856;
case 0x0c0ae858u: goto P_0c0ae858;
case 0x0c0ae85au: goto P_0c0ae85a;
case 0x0c0ae85cu: goto P_0c0ae85c;
case 0x0c0ae85eu: goto P_0c0ae85e;
case 0x0c0ae860u: goto P_0c0ae860;
case 0x0c0ae862u: goto P_0c0ae862;
case 0x0c0ae864u: goto P_0c0ae864;
case 0x0c0ae866u: goto P_0c0ae866;
case 0x0c0ae868u: goto P_0c0ae868;
case 0x0c0ae86au: goto P_0c0ae86a;
case 0x0c0ae86cu: goto P_0c0ae86c;
case 0x0c0ae86eu: goto P_0c0ae86e;
case 0x0c0ae870u: goto P_0c0ae870;
case 0x0c0ae872u: goto P_0c0ae872;
case 0x0c0ae874u: goto P_0c0ae874;
case 0x0c0ae876u: goto P_0c0ae876;
case 0x0c0ae878u: goto P_0c0ae878;
case 0x0c0ae87au: goto P_0c0ae87a;
case 0x0c0ae87cu: goto P_0c0ae87c;
case 0x0c0ae87eu: goto P_0c0ae87e;
case 0x0c0ae880u: goto P_0c0ae880;
case 0x0c0ae882u: goto P_0c0ae882;
case 0x0c0ae884u: goto P_0c0ae884;
case 0x0c0ae886u: goto P_0c0ae886;
case 0x0c0ae888u: goto P_0c0ae888;
case 0x0c0ae88au: goto P_0c0ae88a;
case 0x0c0ae88cu: goto P_0c0ae88c;
case 0x0c0ae88eu: goto P_0c0ae88e;
case 0x0c0ae890u: goto P_0c0ae890;
case 0x0c0ae892u: goto P_0c0ae892;
case 0x0c0ae894u: goto P_0c0ae894;
case 0x0c0ae896u: goto P_0c0ae896;
case 0x0c0ae898u: goto P_0c0ae898;
case 0x0c0ae89au: goto P_0c0ae89a;
case 0x0c0ae89cu: goto P_0c0ae89c;
case 0x0c0ae89eu: goto P_0c0ae89e;
case 0x0c0ae8a0u: goto P_0c0ae8a0;
case 0x0c0ae8a2u: goto P_0c0ae8a2;
case 0x0c0ae8a4u: goto P_0c0ae8a4;
case 0x0c0ae8a6u: goto P_0c0ae8a6;
case 0x0c0ae8a8u: goto P_0c0ae8a8;
case 0x0c0ae8aau: goto P_0c0ae8aa;
case 0x0c0ae8bcu: goto P_0c0ae8bc;
case 0x0c0ae8beu: goto P_0c0ae8be;
case 0x0c0ae8c0u: goto P_0c0ae8c0;
case 0x0c0ae8c2u: goto P_0c0ae8c2;
case 0x0c0ae8c4u: goto P_0c0ae8c4;
case 0x0c0ae8c6u: goto P_0c0ae8c6;
case 0x0c0ae8c8u: goto P_0c0ae8c8;
case 0x0c0ae8cau: goto P_0c0ae8ca;
case 0x0c0ae8ccu: goto P_0c0ae8cc;
case 0x0c0ae8ceu: goto P_0c0ae8ce;
case 0x0c0ae8d0u: goto P_0c0ae8d0;
case 0x0c0ae8d2u: goto P_0c0ae8d2;
case 0x0c0ae8d4u: goto P_0c0ae8d4;
case 0x0c0ae8d6u: goto P_0c0ae8d6;
case 0x0c0ae8d8u: goto P_0c0ae8d8;
case 0x0c0ae8dau: goto P_0c0ae8da;
case 0x0c0ae8dcu: goto P_0c0ae8dc;
case 0x0c0ae8deu: goto P_0c0ae8de;
case 0x0c0ae8e0u: goto P_0c0ae8e0;
case 0x0c0ae8e2u: goto P_0c0ae8e2;
case 0x0c0ae8e4u: goto P_0c0ae8e4;
case 0x0c0ae8e6u: goto P_0c0ae8e6;
case 0x0c0ae8e8u: goto P_0c0ae8e8;
case 0x0c0ae8eau: goto P_0c0ae8ea;
case 0x0c0ae8ecu: goto P_0c0ae8ec;
case 0x0c0ae8eeu: goto P_0c0ae8ee;
case 0x0c0ae8f0u: goto P_0c0ae8f0;
case 0x0c0ae8f2u: goto P_0c0ae8f2;
case 0x0c0ae8f4u: goto P_0c0ae8f4;
case 0x0c0ae8f6u: goto P_0c0ae8f6;
case 0x0c0ae8f8u: goto P_0c0ae8f8;
case 0x0c0ae8fau: goto P_0c0ae8fa;
case 0x0c0ae8fcu: goto P_0c0ae8fc;
case 0x0c0ae8feu: goto P_0c0ae8fe;
case 0x0c0ae900u: goto P_0c0ae900;
case 0x0c0ae902u: goto P_0c0ae902;
case 0x0c0ae904u: goto P_0c0ae904;
case 0x0c0ae906u: goto P_0c0ae906;
case 0x0c0ae908u: goto P_0c0ae908;
case 0x0c0ae90au: goto P_0c0ae90a;
case 0x0c0ae90cu: goto P_0c0ae90c;
case 0x0c0ae90eu: goto P_0c0ae90e;
case 0x0c0ae910u: goto P_0c0ae910;
case 0x0c0ae912u: goto P_0c0ae912;
case 0x0c0ae914u: goto P_0c0ae914;
case 0x0c0ae916u: goto P_0c0ae916;
case 0x0c0ae918u: goto P_0c0ae918;
case 0x0c0ae91au: goto P_0c0ae91a;
case 0x0c0ae91cu: goto P_0c0ae91c;
case 0x0c0ae91eu: goto P_0c0ae91e;
case 0x0c0ae920u: goto P_0c0ae920;
case 0x0c0ae922u: goto P_0c0ae922;
case 0x0c0ae924u: goto P_0c0ae924;
case 0x0c0ae9ecu: goto P_0c0ae9ec;
case 0x0c0ae9eeu: goto P_0c0ae9ee;
case 0x0c0ae9f0u: goto P_0c0ae9f0;
case 0x0c0ae9f2u: goto P_0c0ae9f2;
case 0x0c0ae9f4u: goto P_0c0ae9f4;
case 0x0c0ae9f6u: goto P_0c0ae9f6;
case 0x0c0ae9f8u: goto P_0c0ae9f8;
case 0x0c0ae9fau: goto P_0c0ae9fa;
case 0x0c0ae9fcu: goto P_0c0ae9fc;
case 0x0c0ae9feu: goto P_0c0ae9fe;
case 0x0c0aea00u: goto P_0c0aea00;
case 0x0c0aea02u: goto P_0c0aea02;
case 0x0c0aea04u: goto P_0c0aea04;
case 0x0c0aea06u: goto P_0c0aea06;
case 0x0c0aea08u: goto P_0c0aea08;
case 0x0c0aea0au: goto P_0c0aea0a;
case 0x0c0aea0cu: goto P_0c0aea0c;
case 0x0c0aea0eu: goto P_0c0aea0e;
case 0x0c0aea10u: goto P_0c0aea10;
case 0x0c0aea12u: goto P_0c0aea12;
case 0x0c0aea14u: goto P_0c0aea14;
case 0x0c0aea16u: goto P_0c0aea16;
case 0x0c0aea18u: goto P_0c0aea18;
case 0x0c0aea1au: goto P_0c0aea1a;
case 0x0c0aea1cu: goto P_0c0aea1c;
case 0x0c0aea1eu: goto P_0c0aea1e;
case 0x0c0aea20u: goto P_0c0aea20;
case 0x0c0aea22u: goto P_0c0aea22;
case 0x0c0aea24u: goto P_0c0aea24;
case 0x0c0aea26u: goto P_0c0aea26;
case 0x0c0aea28u: goto P_0c0aea28;
case 0x0c0aea2au: goto P_0c0aea2a;
case 0x0c0aea2cu: goto P_0c0aea2c;
case 0x0c0aea2eu: goto P_0c0aea2e;
case 0x0c0aea30u: goto P_0c0aea30;
case 0x0c0aea32u: goto P_0c0aea32;
case 0x0c0aea34u: goto P_0c0aea34;
case 0x0c0aea36u: goto P_0c0aea36;
case 0x0c0aea38u: goto P_0c0aea38;
case 0x0c0aea3au: goto P_0c0aea3a;
case 0x0c0aea3cu: goto P_0c0aea3c;
case 0x0c0aea3eu: goto P_0c0aea3e;
case 0x0c0aea40u: goto P_0c0aea40;
case 0x0c0aea42u: goto P_0c0aea42;
case 0x0c0aea44u: goto P_0c0aea44;
case 0x0c0aea46u: goto P_0c0aea46;
case 0x0c0aea48u: goto P_0c0aea48;
case 0x0c0aea4au: goto P_0c0aea4a;
case 0x0c0aea4cu: goto P_0c0aea4c;
case 0x0c0aea4eu: goto P_0c0aea4e;
case 0x0c0aea50u: goto P_0c0aea50;
case 0x0c0aea52u: goto P_0c0aea52;
case 0x0c0aea54u: goto P_0c0aea54;
case 0x0c0aea56u: goto P_0c0aea56;
case 0x0c0aea58u: goto P_0c0aea58;
case 0x0c0aea5au: goto P_0c0aea5a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03a140: /* original 2fe6, guest PC 0x0c03a140 */
if(!s->budget--) { s->failed_pc=0x0c03a140u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03a142;
P_0c03a142: /* original 6e4d, guest PC 0x0c03a142 */
if(!s->budget--) { s->failed_pc=0x0c03a142u; return 0; }
r[14]=r[4]&65535u;
goto P_0c03a144;
P_0c03a144: /* original d337, guest PC 0x0c03a144 */
if(!s->budget--) { s->failed_pc=0x0c03a144u; return 0; }
r[3]=read(ram,0x0c03a224u,4);
goto P_0c03a146;
P_0c03a146: /* original 3e37, guest PC 0x0c03a146 */
if(!s->budget--) { s->failed_pc=0x0c03a146u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[3])!=0);
goto P_0c03a148;
P_0c03a148: /* original 8b02, guest PC 0x0c03a148 */
if(!s->budget--) { s->failed_pc=0x0c03a148u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a150; }
goto P_0c03a14a;
P_0c03a14a: /* original d137, guest PC 0x0c03a14a */
if(!s->budget--) { s->failed_pc=0x0c03a14au; return 0; }
r[1]=read(ram,0x0c03a228u,4);
goto P_0c03a14c;
P_0c03a14c: /* original 31e8, guest PC 0x0c03a14c */
if(!s->budget--) { s->failed_pc=0x0c03a14cu; return 0; }
r[1]-=r[14];
goto P_0c03a14e;
P_0c03a14e: /* original 6e13, guest PC 0x0c03a14e */
if(!s->budget--) { s->failed_pc=0x0c03a14eu; return 0; }
r[14]=r[1];
goto P_0c03a150;
P_0c03a150: /* original 9466, guest PC 0x0c03a150 */
if(!s->budget--) { s->failed_pc=0x0c03a150u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03a220u,2);
goto P_0c03a152;
P_0c03a152: /* original 34e8, guest PC 0x0c03a152 */
if(!s->budget--) { s->failed_pc=0x0c03a152u; return 0; }
r[4]-=r[14];
goto P_0c03a154;
P_0c03a154: /* original a2c4, guest PC 0x0c03a154 */
if(!s->budget--) { s->failed_pc=0x0c03a154u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c03a6e0;
P_0c03a156: /* original 6ef6, guest PC 0x0c03a156 */
if(!s->budget--) { s->failed_pc=0x0c03a156u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03a158u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a158u; return 0; } return 1;
P_0c03a6e0: /* original 644d, guest PC 0x0c03a6e0 */
if(!s->budget--) { s->failed_pc=0x0c03a6e0u; return 0; }
r[4]=r[4]&65535u;
goto P_0c03a6e2;
P_0c03a6e2: /* original 445a, guest PC 0x0c03a6e2 */
if(!s->budget--) { s->failed_pc=0x0c03a6e2u; return 0; }
r[53]=r[4];
goto P_0c03a6e4;
P_0c03a6e4: /* original c78d, guest PC 0x0c03a6e4 */
if(!s->budget--) { s->failed_pc=0x0c03a6e4u; return 0; }
r[0]=code_base|0x0003a91cu;
goto P_0c03a6e6;
P_0c03a6e6: /* original f708, guest PC 0x0c03a6e6 */
if(!s->budget--) { s->failed_pc=0x0c03a6e6u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c03a6e8;
P_0c03a6e8: /* original c78d, guest PC 0x0c03a6e8 */
if(!s->budget--) { s->failed_pc=0x0c03a6e8u; return 0; }
r[0]=code_base|0x0003a920u;
goto P_0c03a6ea;
P_0c03a6ea: /* original f208, guest PC 0x0c03a6ea */
if(!s->budget--) { s->failed_pc=0x0c03a6eau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03a6ec;
P_0c03a6ec: /* original c78d, guest PC 0x0c03a6ec */
if(!s->budget--) { s->failed_pc=0x0c03a6ecu; return 0; }
r[0]=code_base|0x0003a924u;
goto P_0c03a6ee;
P_0c03a6ee: /* original f32d, guest PC 0x0c03a6ee */
if(!s->budget--) { s->failed_pc=0x0c03a6eeu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a6f0;
P_0c03a6f0: /* original f108, guest PC 0x0c03a6f0 */
if(!s->budget--) { s->failed_pc=0x0c03a6f0u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c03a6f2;
P_0c03a6f2: /* original c78d, guest PC 0x0c03a6f2 */
if(!s->budget--) { s->failed_pc=0x0c03a6f2u; return 0; }
r[0]=code_base|0x0003a928u;
goto P_0c03a6f4;
P_0c03a6f4: /* original f508, guest PC 0x0c03a6f4 */
if(!s->budget--) { s->failed_pc=0x0c03a6f4u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c03a6f6;
P_0c03a6f6: /* original c78d, guest PC 0x0c03a6f6 */
if(!s->budget--) { s->failed_pc=0x0c03a6f6u; return 0; }
r[0]=code_base|0x0003a92cu;
goto P_0c03a6f8;
P_0c03a6f8: /* original f008, guest PC 0x0c03a6f8 */
if(!s->budget--) { s->failed_pc=0x0c03a6f8u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c03a6fa;
P_0c03a6fa: /* original e40b, guest PC 0x0c03a6fa */
if(!s->budget--) { s->failed_pc=0x0c03a6fau; return 0; }
r[4]=0x0000000bu;
goto P_0c03a6fc;
P_0c03a6fc: /* original e503, guest PC 0x0c03a6fc */
if(!s->budget--) { s->failed_pc=0x0c03a6fcu; return 0; }
r[5]=0x00000003u;
goto P_0c03a6fe;
P_0c03a6fe: /* original f322, guest PC 0x0c03a6fe */
if(!s->budget--) { s->failed_pc=0x0c03a6feu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c03a700;
P_0c03a700: /* original f313, guest PC 0x0c03a700 */
if(!s->budget--) { s->failed_pc=0x0c03a700u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'/');
goto P_0c03a702;
P_0c03a702: /* original f43c, guest PC 0x0c03a702 */
if(!s->budget--) { s->failed_pc=0x0c03a702u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c03a704;
P_0c03a704: /* original f473, guest PC 0x0c03a704 */
if(!s->budget--) { s->failed_pc=0x0c03a704u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'/');
goto P_0c03a706;
P_0c03a706: /* original f34c, guest PC 0x0c03a706 */
if(!s->budget--) { s->failed_pc=0x0c03a706u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03a708;
P_0c03a708: /* original f353, guest PC 0x0c03a708 */
if(!s->budget--) { s->failed_pc=0x0c03a708u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'/');
goto P_0c03a70a;
P_0c03a70a: /* original f300, guest PC 0x0c03a70a */
if(!s->budget--) { s->failed_pc=0x0c03a70au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'+');
goto P_0c03a70c;
P_0c03a70c: /* original f33d, guest PC 0x0c03a70c */
if(!s->budget--) { s->failed_pc=0x0c03a70cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03a70e;
P_0c03a70e: /* original 065a, guest PC 0x0c03a70e */
if(!s->budget--) { s->failed_pc=0x0c03a70eu; return 0; }
r[6]=r[53];
goto P_0c03a710;
P_0c03a710: /* original 465a, guest PC 0x0c03a710 */
if(!s->budget--) { s->failed_pc=0x0c03a710u; return 0; }
r[53]=r[6];
goto P_0c03a712;
P_0c03a712: /* original f32d, guest PC 0x0c03a712 */
if(!s->budget--) { s->failed_pc=0x0c03a712u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a714;
P_0c03a714: /* original f352, guest PC 0x0c03a714 */
if(!s->budget--) { s->failed_pc=0x0c03a714u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03a716;
P_0c03a716: /* original f58d, guest PC 0x0c03a716 */
if(!s->budget--) { s->failed_pc=0x0c03a716u; return 0; }
fr[5]=0;
goto P_0c03a718;
P_0c03a718: /* original f431, guest PC 0x0c03a718 */
if(!s->budget--) { s->failed_pc=0x0c03a718u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c03a71a;
P_0c03a71a: /* original f64c, guest PC 0x0c03a71a */
if(!s->budget--) { s->failed_pc=0x0c03a71au; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c03a71c;
P_0c03a71c: /* original f642, guest PC 0x0c03a71c */
if(!s->budget--) { s->failed_pc=0x0c03a71cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c03a71e;
P_0c03a71e: /* original 445a, guest PC 0x0c03a71e */
if(!s->budget--) { s->failed_pc=0x0c03a71eu; return 0; }
r[53]=r[4];
goto P_0c03a720;
P_0c03a720: /* original 74fe, guest PC 0x0c03a720 */
if(!s->budget--) { s->failed_pc=0x0c03a720u; return 0; }
r[4]+=0xfffffffeu;
goto P_0c03a722;
P_0c03a722: /* original 3453, guest PC 0x0c03a722 */
if(!s->budget--) { s->failed_pc=0x0c03a722u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c03a724;
P_0c03a724: /* original f22d, guest PC 0x0c03a724 */
if(!s->budget--) { s->failed_pc=0x0c03a724u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a726;
P_0c03a726: /* original f251, guest PC 0x0c03a726 */
if(!s->budget--) { s->failed_pc=0x0c03a726u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c03a728;
P_0c03a728: /* original f56c, guest PC 0x0c03a728 */
if(!s->budget--) { s->failed_pc=0x0c03a728u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c03a72a;
P_0c03a72a: /* original 8df8, guest PC 0x0c03a72a */
if(!s->budget--) { s->failed_pc=0x0c03a72au; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
if(cond) { goto P_0c03a71e; }
goto P_0c03a72e;
P_0c03a72c: /* original f523, guest PC 0x0c03a72c */
if(!s->budget--) { s->failed_pc=0x0c03a72cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
goto P_0c03a72e;
P_0c03a72e: /* original f69d, guest PC 0x0c03a72e */
if(!s->budget--) { s->failed_pc=0x0c03a72eu; return 0; }
fr[6]=0x3f800000u;
goto P_0c03a730;
P_0c03a730: /* original e301, guest PC 0x0c03a730 */
if(!s->budget--) { s->failed_pc=0x0c03a730u; return 0; }
r[3]=0x00000001u;
goto P_0c03a732;
P_0c03a732: /* original f36c, guest PC 0x0c03a732 */
if(!s->budget--) { s->failed_pc=0x0c03a732u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c03a734;
P_0c03a734: /* original f351, guest PC 0x0c03a734 */
if(!s->budget--) { s->failed_pc=0x0c03a734u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c03a736;
P_0c03a736: /* original 2638, guest PC 0x0c03a736 */
if(!s->budget--) { s->failed_pc=0x0c03a736u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c03a738;
P_0c03a738: /* original f433, guest PC 0x0c03a738 */
if(!s->budget--) { s->failed_pc=0x0c03a738u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c03a73a;
P_0c03a73a: /* original f24c, guest PC 0x0c03a73a */
if(!s->budget--) { s->failed_pc=0x0c03a73au; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03a73c;
P_0c03a73c: /* original f272, guest PC 0x0c03a73c */
if(!s->budget--) { s->failed_pc=0x0c03a73cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c03a73e;
P_0c03a73e: /* original f04c, guest PC 0x0c03a73e */
if(!s->budget--) { s->failed_pc=0x0c03a73eu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c03a740;
P_0c03a740: /* original f64e, guest PC 0x0c03a740 */
if(!s->budget--) { s->failed_pc=0x0c03a740u; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[4],fr[6],r[18]);
goto P_0c03a742;
P_0c03a742: /* original f42c, guest PC 0x0c03a742 */
if(!s->budget--) { s->failed_pc=0x0c03a742u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c03a744;
P_0c03a744: /* original 8f04, guest PC 0x0c03a744 */
if(!s->budget--) { s->failed_pc=0x0c03a744u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
if(!cond) { goto P_0c03a750; }
goto P_0c03a748;
P_0c03a746: /* original f463, guest PC 0x0c03a746 */
if(!s->budget--) { s->failed_pc=0x0c03a746u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
goto P_0c03a748;
P_0c03a748: /* original 000b, guest PC 0x0c03a748 */
if(!s->budget--) { s->failed_pc=0x0c03a748u; return 0; }
target=r[16];
vf3_matrix_move(s,0,4);
s->pc=target; return ram->oob==0;
P_0c03a74a: /* original f04c, guest PC 0x0c03a74a */
if(!s->budget--) { s->failed_pc=0x0c03a74au; return 0; }
vf3_matrix_move(s,0,4);
if(!vf3_matrix_family(0x0c03a74cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a74cu; return 0; } return 1;
P_0c03a750: /* original f04c, guest PC 0x0c03a750 */
if(!s->budget--) { s->failed_pc=0x0c03a750u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c03a752;
P_0c03a752: /* original f04d, guest PC 0x0c03a752 */
if(!s->budget--) { s->failed_pc=0x0c03a752u; return 0; }
fr[0]^=0x80000000u;
goto P_0c03a754;
P_0c03a754: /* original 000b, guest PC 0x0c03a754 */
if(!s->budget--) { s->failed_pc=0x0c03a754u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03a756: /* original 0009, guest PC 0x0c03a756 */
if(!s->budget--) { s->failed_pc=0x0c03a756u; return 0; }
if(!vf3_matrix_family(0x0c03a758u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a758u; return 0; } return 1;
P_0c09553c: /* original fffb, guest PC 0x0c09553c */
if(!s->budget--) { s->failed_pc=0x0c09553cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09553e;
P_0c09553e: /* original 4f22, guest PC 0x0c09553e */
if(!s->budget--) { s->failed_pc=0x0c09553eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c095540;
P_0c095540: /* original 7ff0, guest PC 0x0c095540 */
if(!s->budget--) { s->failed_pc=0x0c095540u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c095542;
P_0c095542: /* original 1f42, guest PC 0x0c095542 */
if(!s->budget--) { s->failed_pc=0x0c095542u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c095544;
P_0c095544: /* original 2f52, guest PC 0x0c095544 */
if(!s->budget--) { s->failed_pc=0x0c095544u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c095546;
P_0c095546: /* original 1f61, guest PC 0x0c095546 */
if(!s->budget--) { s->failed_pc=0x0c095546u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c095548;
P_0c095548: /* original 54f2, guest PC 0x0c095548 */
if(!s->budget--) { s->failed_pc=0x0c095548u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c09554a;
P_0c09554a: /* original d369, guest PC 0x0c09554a */
if(!s->budget--) { s->failed_pc=0x0c09554au; return 0; }
r[3]=read(ram,0x0c0956f0u,4);
goto P_0c09554c;
P_0c09554c: /* original 644f, guest PC 0x0c09554c */
if(!s->budget--) { s->failed_pc=0x0c09554cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c09554e;
P_0c09554e: /* original 430b, guest PC 0x0c09554e */
if(!s->budget--) { s->failed_pc=0x0c09554eu; return 0; }
target=r[3];
r[16]=code_base|0x0c095552u;
write(ram,r[15]+12,r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c095552u) { target=s->pc; goto dispatch; }
goto P_0c095552;
P_0c095550: /* original 1f43, guest PC 0x0c095550 */
if(!s->budget--) { s->failed_pc=0x0c095550u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c095552;
P_0c095552: /* original d368, guest PC 0x0c095552 */
if(!s->budget--) { s->failed_pc=0x0c095552u; return 0; }
r[3]=read(ram,0x0c0956f4u,4);
goto P_0c095554;
P_0c095554: /* original ff0c, guest PC 0x0c095554 */
if(!s->budget--) { s->failed_pc=0x0c095554u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c095556;
P_0c095556: /* original 430b, guest PC 0x0c095556 */
if(!s->budget--) { s->failed_pc=0x0c095556u; return 0; }
target=r[3];
r[16]=code_base|0x0c09555au;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09555au) { target=s->pc; goto dispatch; }
goto P_0c09555a;
P_0c095558: /* original 54f3, guest PC 0x0c095558 */
if(!s->budget--) { s->failed_pc=0x0c095558u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c09555a;
P_0c09555a: /* original 62f2, guest PC 0x0c09555a */
if(!s->budget--) { s->failed_pc=0x0c09555au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09555c;
P_0c09555c: /* original f70c, guest PC 0x0c09555c */
if(!s->budget--) { s->failed_pc=0x0c09555cu; return 0; }
vf3_matrix_move(s,7,0);
goto P_0c09555e;
P_0c09555e: /* original f628, guest PC 0x0c09555e */
if(!s->budget--) { s->failed_pc=0x0c09555eu; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
goto P_0c095560;
P_0c095560: /* original 53f1, guest PC 0x0c095560 */
if(!s->budget--) { s->failed_pc=0x0c095560u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c095562;
P_0c095562: /* original f762, guest PC 0x0c095562 */
if(!s->budget--) { s->failed_pc=0x0c095562u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'*');
goto P_0c095564;
P_0c095564: /* original f40c, guest PC 0x0c095564 */
if(!s->budget--) { s->failed_pc=0x0c095564u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c095566;
P_0c095566: /* original f538, guest PC 0x0c095566 */
if(!s->budget--) { s->failed_pc=0x0c095566u; return 0; }
vf3_matrix_load(s,ram,5,r[3]);
goto P_0c095568;
P_0c095568: /* original 6323, guest PC 0x0c095568 */
if(!s->budget--) { s->failed_pc=0x0c095568u; return 0; }
r[3]=r[2];
goto P_0c09556a;
P_0c09556a: /* original f05c, guest PC 0x0c09556a */
if(!s->budget--) { s->failed_pc=0x0c09556au; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c09556c;
P_0c09556c: /* original f452, guest PC 0x0c09556c */
if(!s->budget--) { s->failed_pc=0x0c09556cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c09556e;
P_0c09556e: /* original f7fe, guest PC 0x0c09556e */
if(!s->budget--) { s->failed_pc=0x0c09556eu; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[15],fr[7],r[18]);
goto P_0c095570;
P_0c095570: /* original ff62, guest PC 0x0c095570 */
if(!s->budget--) { s->failed_pc=0x0c095570u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[6],r[18],'*');
goto P_0c095572;
P_0c095572: /* original f57c, guest PC 0x0c095572 */
if(!s->budget--) { s->failed_pc=0x0c095572u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c095574;
P_0c095574: /* original f35a, guest PC 0x0c095574 */
if(!s->budget--) { s->failed_pc=0x0c095574u; return 0; }
vf3_matrix_store(s,ram,5,r[3]);
goto P_0c095576;
P_0c095576: /* original f4f1, guest PC 0x0c095576 */
if(!s->budget--) { s->failed_pc=0x0c095576u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
goto P_0c095578;
P_0c095578: /* original 53f1, guest PC 0x0c095578 */
if(!s->budget--) { s->failed_pc=0x0c095578u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09557a;
P_0c09557a: /* original 7f10, guest PC 0x0c09557a */
if(!s->budget--) { s->failed_pc=0x0c09557au; return 0; }
r[15]+=0x00000010u;
goto P_0c09557c;
P_0c09557c: /* original 4f26, guest PC 0x0c09557c */
if(!s->budget--) { s->failed_pc=0x0c09557cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09557e;
P_0c09557e: /* original f34a, guest PC 0x0c09557e */
if(!s->budget--) { s->failed_pc=0x0c09557eu; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c095580;
P_0c095580: /* original 000b, guest PC 0x0c095580 */
if(!s->budget--) { s->failed_pc=0x0c095580u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c095582: /* original fff9, guest PC 0x0c095582 */
if(!s->budget--) { s->failed_pc=0x0c095582u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c095584u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095584u; return 0; } return 1;
P_0c0ae29c: /* original 5762, guest PC 0x0c0ae29c */
if(!s->budget--) { s->failed_pc=0x0c0ae29cu; return 0; }
r[7]=read(ram,r[6]+8,4);
goto P_0c0ae29e;
P_0c0ae29e: /* original 7ffc, guest PC 0x0c0ae29e */
if(!s->budget--) { s->failed_pc=0x0c0ae29eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ae2a0;
P_0c0ae2a0: /* original 6770, guest PC 0x0c0ae2a0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]=tmp;
goto P_0c0ae2a2;
P_0c0ae2a2: /* original 677c, guest PC 0x0c0ae2a2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a2u; return 0; }
r[7]=r[7]&255u;
goto P_0c0ae2a4;
P_0c0ae2a4: /* original 2778, guest PC 0x0c0ae2a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0ae2a6;
P_0c0ae2a6: /* original 8910, guest PC 0x0c0ae2a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae2ca; }
goto P_0c0ae2a8;
P_0c0ae2a8: /* original 5362, guest PC 0x0c0ae2a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a8u; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c0ae2aa;
P_0c0ae2aa: /* original 2f32, guest PC 0x0c0ae2aa */
if(!s->budget--) { s->failed_pc=0x0c0ae2aau; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ae2ac;
P_0c0ae2ac: /* original 62f2, guest PC 0x0c0ae2ac */
if(!s->budget--) { s->failed_pc=0x0c0ae2acu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0ae2ae;
P_0c0ae2ae: /* original 8432, guest PC 0x0c0ae2ae */
if(!s->budget--) { s->failed_pc=0x0c0ae2aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+2,1);
goto P_0c0ae2b0;
P_0c0ae2b0: /* original 7201, guest PC 0x0c0ae2b0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b0u; return 0; }
r[2]+=0x00000001u;
goto P_0c0ae2b2;
P_0c0ae2b2: /* original d315, guest PC 0x0c0ae2b2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b2u; return 0; }
r[3]=read(ram,0x0c0ae308u,4);
goto P_0c0ae2b4;
P_0c0ae2b4: /* original 600c, guest PC 0x0c0ae2b4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae2b6;
P_0c0ae2b6: /* original 6220, guest PC 0x0c0ae2b6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[2]=tmp;
goto P_0c0ae2b8;
P_0c0ae2b8: /* original 4018, guest PC 0x0c0ae2b8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b8u; return 0; }
r[0]<<=8;
goto P_0c0ae2ba;
P_0c0ae2ba: /* original 622c, guest PC 0x0c0ae2ba */
if(!s->budget--) { s->failed_pc=0x0c0ae2bau; return 0; }
r[2]=r[2]&255u;
goto P_0c0ae2bc;
P_0c0ae2bc: /* original 2039, guest PC 0x0c0ae2bc */
if(!s->budget--) { s->failed_pc=0x0c0ae2bcu; return 0; }
r[0]&=r[3];
goto P_0c0ae2be;
P_0c0ae2be: /* original 202b, guest PC 0x0c0ae2be */
if(!s->budget--) { s->failed_pc=0x0c0ae2beu; return 0; }
r[0]|=r[2];
goto P_0c0ae2c0;
P_0c0ae2c0: /* original 6103, guest PC 0x0c0ae2c0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c0u; return 0; }
r[1]=r[0];
goto P_0c0ae2c2;
P_0c0ae2c2: /* original 1601, guest PC 0x0c0ae2c2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c2u; return 0; }
write(ram,r[6]+4,r[0],4);
goto P_0c0ae2c4;
P_0c0ae2c4: /* original 6262, guest PC 0x0c0ae2c4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c4u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c0ae2c6;
P_0c0ae2c6: /* original 3212, guest PC 0x0c0ae2c6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[1])!=0);
goto P_0c0ae2c8;
P_0c0ae2c8: /* original 8902, guest PC 0x0c0ae2c8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae2d0; }
goto P_0c0ae2ca;
P_0c0ae2ca: /* original d310, guest PC 0x0c0ae2ca */
if(!s->budget--) { s->failed_pc=0x0c0ae2cau; return 0; }
r[3]=read(ram,0x0c0ae30cu,4);
goto P_0c0ae2cc;
P_0c0ae2cc: /* original 432b, guest PC 0x0c0ae2cc */
if(!s->budget--) { s->failed_pc=0x0c0ae2ccu; return 0; }
target=r[3];
r[15]+=0x00000004u;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0af728u: return vf3_matrix_family(0x0c0af728u,s,ram);
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
P_0c0ae2ce: /* original 7f04, guest PC 0x0c0ae2ce */
if(!s->budget--) { s->failed_pc=0x0c0ae2ceu; return 0; }
r[15]+=0x00000004u;
goto P_0c0ae2d0;
P_0c0ae2d0: /* original d00f, guest PC 0x0c0ae2d0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d0u; return 0; }
r[0]=read(ram,0x0c0ae310u,4);
goto P_0c0ae2d2;
P_0c0ae2d2: /* original 4708, guest PC 0x0c0ae2d2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d2u; return 0; }
r[7]<<=2;
goto P_0c0ae2d4;
P_0c0ae2d4: /* original 027e, guest PC 0x0c0ae2d4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d4u; return 0; }
r[2]=read(ram,r[7]+r[0],4);
goto P_0c0ae2d6;
P_0c0ae2d6: /* original 2f22, guest PC 0x0c0ae2d6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d6u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ae2d8;
P_0c0ae2d8: /* original 422b, guest PC 0x0c0ae2d8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d8u; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c0ae2da: /* original 7f04, guest PC 0x0c0ae2da */
if(!s->budget--) { s->failed_pc=0x0c0ae2dau; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c0ae2dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ae2dcu; return 0; } return 1;
P_0c0ae7e0: /* original 2fe6, guest PC 0x0c0ae7e0 */
if(!s->budget--) { s->failed_pc=0x0c0ae7e0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae7e2;
P_0c0ae7e2: /* original 2fd6, guest PC 0x0c0ae7e2 */
if(!s->budget--) { s->failed_pc=0x0c0ae7e2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae7e4;
P_0c0ae7e4: /* original 2fc6, guest PC 0x0c0ae7e4 */
if(!s->budget--) { s->failed_pc=0x0c0ae7e4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae7e6;
P_0c0ae7e6: /* original 2fb6, guest PC 0x0c0ae7e6 */
if(!s->budget--) { s->failed_pc=0x0c0ae7e6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae7e8;
P_0c0ae7e8: /* original 2fa6, guest PC 0x0c0ae7e8 */
if(!s->budget--) { s->failed_pc=0x0c0ae7e8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae7ea;
P_0c0ae7ea: /* original 2f96, guest PC 0x0c0ae7ea */
if(!s->budget--) { s->failed_pc=0x0c0ae7eau; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae7ec;
P_0c0ae7ec: /* original 905e, guest PC 0x0c0ae7ec */
if(!s->budget--) { s->failed_pc=0x0c0ae7ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae8acu,2);
goto P_0c0ae7ee;
P_0c0ae7ee: /* original 7ff8, guest PC 0x0c0ae7ee */
if(!s->budget--) { s->failed_pc=0x0c0ae7eeu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0ae7f0;
P_0c0ae7f0: /* original 074c, guest PC 0x0c0ae7f0 */
if(!s->budget--) { s->failed_pc=0x0c0ae7f0u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0ae7f2;
P_0c0ae7f2: /* original 7002, guest PC 0x0c0ae7f2 */
if(!s->budget--) { s->failed_pc=0x0c0ae7f2u; return 0; }
r[0]+=0x00000002u;
goto P_0c0ae7f4;
P_0c0ae7f4: /* original 0b4c, guest PC 0x0c0ae7f4 */
if(!s->budget--) { s->failed_pc=0x0c0ae7f4u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0ae7f6;
P_0c0ae7f6: /* original 677c, guest PC 0x0c0ae7f6 */
if(!s->budget--) { s->failed_pc=0x0c0ae7f6u; return 0; }
r[7]=r[7]&255u;
goto P_0c0ae7f8;
P_0c0ae7f8: /* original 6bbc, guest PC 0x0c0ae7f8 */
if(!s->budget--) { s->failed_pc=0x0c0ae7f8u; return 0; }
r[11]=r[11]&255u;
goto P_0c0ae7fa;
P_0c0ae7fa: /* original 37b0, guest PC 0x0c0ae7fa */
if(!s->budget--) { s->failed_pc=0x0c0ae7fau; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[11])!=0);
goto P_0c0ae7fc;
P_0c0ae7fc: /* original 8b01, guest PC 0x0c0ae7fc */
if(!s->budget--) { s->failed_pc=0x0c0ae7fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae802; }
goto P_0c0ae7fe;
P_0c0ae7fe: /* original a087, guest PC 0x0c0ae7fe */
if(!s->budget--) { s->failed_pc=0x0c0ae7feu; return 0; }
goto P_0c0ae910;
P_0c0ae800: /* original 0009, guest PC 0x0c0ae800 */
if(!s->budget--) { s->failed_pc=0x0c0ae800u; return 0; }
goto P_0c0ae802;
P_0c0ae802: /* original 5d62, guest PC 0x0c0ae802 */
if(!s->budget--) { s->failed_pc=0x0c0ae802u; return 0; }
r[13]=read(ram,r[6]+8,4);
goto P_0c0ae804;
P_0c0ae804: /* original d92b, guest PC 0x0c0ae804 */
if(!s->budget--) { s->failed_pc=0x0c0ae804u; return 0; }
r[9]=read(ram,0x0c0ae8b4u,4);
goto P_0c0ae806;
P_0c0ae806: /* original 2fd2, guest PC 0x0c0ae806 */
if(!s->budget--) { s->failed_pc=0x0c0ae806u; return 0; }
write(ram,r[15],r[13],4);
goto P_0c0ae808;
P_0c0ae808: /* original 84d7, guest PC 0x0c0ae808 */
if(!s->budget--) { s->failed_pc=0x0c0ae808u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+7,1);
goto P_0c0ae80a;
P_0c0ae80a: /* original 63f2, guest PC 0x0c0ae80a */
if(!s->budget--) { s->failed_pc=0x0c0ae80au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0ae80c;
P_0c0ae80c: /* original 600c, guest PC 0x0c0ae80c */
if(!s->budget--) { s->failed_pc=0x0c0ae80cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae80e;
P_0c0ae80e: /* original 7306, guest PC 0x0c0ae80e */
if(!s->budget--) { s->failed_pc=0x0c0ae80eu; return 0; }
r[3]+=0x00000006u;
goto P_0c0ae810;
P_0c0ae810: /* original 4018, guest PC 0x0c0ae810 */
if(!s->budget--) { s->failed_pc=0x0c0ae810u; return 0; }
r[0]<<=8;
goto P_0c0ae812;
P_0c0ae812: /* original 6230, guest PC 0x0c0ae812 */
if(!s->budget--) { s->failed_pc=0x0c0ae812u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c0ae814;
P_0c0ae814: /* original 6d03, guest PC 0x0c0ae814 */
if(!s->budget--) { s->failed_pc=0x0c0ae814u; return 0; }
r[13]=r[0];
goto P_0c0ae816;
P_0c0ae816: /* original 2d99, guest PC 0x0c0ae816 */
if(!s->budget--) { s->failed_pc=0x0c0ae816u; return 0; }
r[13]&=r[9];
goto P_0c0ae818;
P_0c0ae818: /* original 622c, guest PC 0x0c0ae818 */
if(!s->budget--) { s->failed_pc=0x0c0ae818u; return 0; }
r[2]=r[2]&255u;
goto P_0c0ae81a;
P_0c0ae81a: /* original 2d2b, guest PC 0x0c0ae81a */
if(!s->budget--) { s->failed_pc=0x0c0ae81au; return 0; }
r[13]|=r[2];
goto P_0c0ae81c;
P_0c0ae81c: /* original e33f, guest PC 0x0c0ae81c */
if(!s->budget--) { s->failed_pc=0x0c0ae81cu; return 0; }
r[3]=0x0000003fu;
goto P_0c0ae81e;
P_0c0ae81e: /* original 77ff, guest PC 0x0c0ae81e */
if(!s->budget--) { s->failed_pc=0x0c0ae81eu; return 0; }
r[7]+=0xffffffffu;
goto P_0c0ae820;
P_0c0ae820: /* original 2739, guest PC 0x0c0ae820 */
if(!s->budget--) { s->failed_pc=0x0c0ae820u; return 0; }
r[7]&=r[3];
goto P_0c0ae822;
P_0c0ae822: /* original 6273, guest PC 0x0c0ae822 */
if(!s->budget--) { s->failed_pc=0x0c0ae822u; return 0; }
r[2]=r[7];
goto P_0c0ae824;
P_0c0ae824: /* original 4208, guest PC 0x0c0ae824 */
if(!s->budget--) { s->failed_pc=0x0c0ae824u; return 0; }
r[2]<<=2;
goto P_0c0ae826;
P_0c0ae826: /* original e10f, guest PC 0x0c0ae826 */
if(!s->budget--) { s->failed_pc=0x0c0ae826u; return 0; }
r[1]=0x0000000fu;
goto P_0c0ae828;
P_0c0ae828: /* original 1f21, guest PC 0x0c0ae828 */
if(!s->budget--) { s->failed_pc=0x0c0ae828u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0ae82a;
P_0c0ae82a: /* original 9e40, guest PC 0x0c0ae82a */
if(!s->budget--) { s->failed_pc=0x0c0ae82au; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae8aeu,2);
goto P_0c0ae82c;
P_0c0ae82c: /* original 2dd8, guest PC 0x0c0ae82c */
if(!s->budget--) { s->failed_pc=0x0c0ae82cu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0ae82e;
P_0c0ae82e: /* original 3e4c, guest PC 0x0c0ae82e */
if(!s->budget--) { s->failed_pc=0x0c0ae82eu; return 0; }
r[14]+=r[4];
goto P_0c0ae830;
P_0c0ae830: /* original 3e2c, guest PC 0x0c0ae830 */
if(!s->budget--) { s->failed_pc=0x0c0ae830u; return 0; }
r[14]+=r[2];
goto P_0c0ae832;
P_0c0ae832: /* original 2fe2, guest PC 0x0c0ae832 */
if(!s->budget--) { s->failed_pc=0x0c0ae832u; return 0; }
write(ram,r[15],r[14],4);
goto P_0c0ae834;
P_0c0ae834: /* original 84e2, guest PC 0x0c0ae834 */
if(!s->budget--) { s->failed_pc=0x0c0ae834u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c0ae836;
P_0c0ae836: /* original 6cf2, guest PC 0x0c0ae836 */
if(!s->budget--) { s->failed_pc=0x0c0ae836u; return 0; }
tmp=read(ram,r[15],4);
r[12]=tmp;
goto P_0c0ae838;
P_0c0ae838: /* original 6e0c, guest PC 0x0c0ae838 */
if(!s->budget--) { s->failed_pc=0x0c0ae838u; return 0; }
r[14]=r[0]&255u;
goto P_0c0ae83a;
P_0c0ae83a: /* original 2e19, guest PC 0x0c0ae83a */
if(!s->budget--) { s->failed_pc=0x0c0ae83au; return 0; }
r[14]&=r[1];
goto P_0c0ae83c;
P_0c0ae83c: /* original 6cc0, guest PC 0x0c0ae83c */
if(!s->budget--) { s->failed_pc=0x0c0ae83cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[12]=tmp;
goto P_0c0ae83e;
P_0c0ae83e: /* original 63e3, guest PC 0x0c0ae83e */
if(!s->budget--) { s->failed_pc=0x0c0ae83eu; return 0; }
r[3]=r[14];
goto P_0c0ae840;
P_0c0ae840: /* original 23d9, guest PC 0x0c0ae840 */
if(!s->budget--) { s->failed_pc=0x0c0ae840u; return 0; }
r[3]&=r[13];
goto P_0c0ae842;
P_0c0ae842: /* original 6ccc, guest PC 0x0c0ae842 */
if(!s->budget--) { s->failed_pc=0x0c0ae842u; return 0; }
r[12]=r[12]&255u;
goto P_0c0ae844;
P_0c0ae844: /* original 8d09, guest PC 0x0c0ae844 */
if(!s->budget--) { s->failed_pc=0x0c0ae844u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(cond) { goto P_0c0ae85a; }
goto P_0c0ae848;
P_0c0ae846: /* original 2f32, guest PC 0x0c0ae846 */
if(!s->budget--) { s->failed_pc=0x0c0ae846u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ae848;
P_0c0ae848: /* original 33d0, guest PC 0x0c0ae848 */
if(!s->budget--) { s->failed_pc=0x0c0ae848u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[13])!=0);
goto P_0c0ae84a;
P_0c0ae84a: /* original 8906, guest PC 0x0c0ae84a */
if(!s->budget--) { s->failed_pc=0x0c0ae84au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae85a; }
goto P_0c0ae84c;
P_0c0ae84c: /* original e204, guest PC 0x0c0ae84c */
if(!s->budget--) { s->failed_pc=0x0c0ae84cu; return 0; }
r[2]=0x00000004u;
goto P_0c0ae84e;
P_0c0ae84e: /* original 2e28, guest PC 0x0c0ae84e */
if(!s->budget--) { s->failed_pc=0x0c0ae84eu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[2])==0)!=0);
goto P_0c0ae850;
P_0c0ae850: /* original 8b5e, guest PC 0x0c0ae850 */
if(!s->budget--) { s->failed_pc=0x0c0ae850u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae910; }
goto P_0c0ae852;
P_0c0ae852: /* original 37b0, guest PC 0x0c0ae852 */
if(!s->budget--) { s->failed_pc=0x0c0ae852u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[11])!=0);
goto P_0c0ae854;
P_0c0ae854: /* original 8be2, guest PC 0x0c0ae854 */
if(!s->budget--) { s->failed_pc=0x0c0ae854u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae81c; }
goto P_0c0ae856;
P_0c0ae856: /* original a05b, guest PC 0x0c0ae856 */
if(!s->budget--) { s->failed_pc=0x0c0ae856u; return 0; }
goto P_0c0ae910;
P_0c0ae858: /* original 0009, guest PC 0x0c0ae858 */
if(!s->budget--) { s->failed_pc=0x0c0ae858u; return 0; }
goto P_0c0ae85a;
P_0c0ae85a: /* original 5e62, guest PC 0x0c0ae85a */
if(!s->budget--) { s->failed_pc=0x0c0ae85au; return 0; }
r[14]=read(ram,r[6]+8,4);
goto P_0c0ae85c;
P_0c0ae85c: /* original 6242, guest PC 0x0c0ae85c */
if(!s->budget--) { s->failed_pc=0x0c0ae85cu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0ae85e;
P_0c0ae85e: /* original 84e3, guest PC 0x0c0ae85e */
if(!s->budget--) { s->failed_pc=0x0c0ae85eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+3,1);
goto P_0c0ae860;
P_0c0ae860: /* original 6d0c, guest PC 0x0c0ae860 */
if(!s->budget--) { s->failed_pc=0x0c0ae860u; return 0; }
r[13]=r[0]&255u;
goto P_0c0ae862;
P_0c0ae862: /* original 84e5, guest PC 0x0c0ae862 */
if(!s->budget--) { s->failed_pc=0x0c0ae862u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+5,1);
goto P_0c0ae864;
P_0c0ae864: /* original 600c, guest PC 0x0c0ae864 */
if(!s->budget--) { s->failed_pc=0x0c0ae864u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae866;
P_0c0ae866: /* original 4018, guest PC 0x0c0ae866 */
if(!s->budget--) { s->failed_pc=0x0c0ae866u; return 0; }
r[0]<<=8;
goto P_0c0ae868;
P_0c0ae868: /* original 2099, guest PC 0x0c0ae868 */
if(!s->budget--) { s->failed_pc=0x0c0ae868u; return 0; }
r[0]&=r[9];
goto P_0c0ae86a;
P_0c0ae86a: /* original 6303, guest PC 0x0c0ae86a */
if(!s->budget--) { s->failed_pc=0x0c0ae86au; return 0; }
r[3]=r[0];
goto P_0c0ae86c;
P_0c0ae86c: /* original 84e4, guest PC 0x0c0ae86c */
if(!s->budget--) { s->failed_pc=0x0c0ae86cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0ae86e;
P_0c0ae86e: /* original 6e33, guest PC 0x0c0ae86e */
if(!s->budget--) { s->failed_pc=0x0c0ae86eu; return 0; }
r[14]=r[3];
goto P_0c0ae870;
P_0c0ae870: /* original d311, guest PC 0x0c0ae870 */
if(!s->budget--) { s->failed_pc=0x0c0ae870u; return 0; }
r[3]=read(ram,0x0c0ae8b8u,4);
goto P_0c0ae872;
P_0c0ae872: /* original 600c, guest PC 0x0c0ae872 */
if(!s->budget--) { s->failed_pc=0x0c0ae872u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae874;
P_0c0ae874: /* original 2238, guest PC 0x0c0ae874 */
if(!s->budget--) { s->failed_pc=0x0c0ae874u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ae876;
P_0c0ae876: /* original 8f04, guest PC 0x0c0ae876 */
if(!s->budget--) { s->failed_pc=0x0c0ae876u; return 0; }
cond=r[17]&1u;
r[14]|=r[0];
if(!cond) { goto P_0c0ae882; }
goto P_0c0ae87a;
P_0c0ae878: /* original 2e0b, guest PC 0x0c0ae878 */
if(!s->budget--) { s->failed_pc=0x0c0ae878u; return 0; }
r[14]|=r[0];
goto P_0c0ae87a;
P_0c0ae87a: /* original ea40, guest PC 0x0c0ae87a */
if(!s->budget--) { s->failed_pc=0x0c0ae87au; return 0; }
r[10]=0x00000040u;
goto P_0c0ae87c;
P_0c0ae87c: /* original 6ba3, guest PC 0x0c0ae87c */
if(!s->budget--) { s->failed_pc=0x0c0ae87cu; return 0; }
r[11]=r[10];
goto P_0c0ae87e;
P_0c0ae87e: /* original a002, guest PC 0x0c0ae87e */
if(!s->budget--) { s->failed_pc=0x0c0ae87eu; return 0; }
r[11]+=0x00000040u;
goto P_0c0ae886;
P_0c0ae880: /* original 7b40, guest PC 0x0c0ae880 */
if(!s->budget--) { s->failed_pc=0x0c0ae880u; return 0; }
r[11]+=0x00000040u;
goto P_0c0ae882;
P_0c0ae882: /* original 9a15, guest PC 0x0c0ae882 */
if(!s->budget--) { s->failed_pc=0x0c0ae882u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae8b0u,2);
goto P_0c0ae884;
P_0c0ae884: /* original eb40, guest PC 0x0c0ae884 */
if(!s->budget--) { s->failed_pc=0x0c0ae884u; return 0; }
r[11]=0x00000040u;
goto P_0c0ae886;
P_0c0ae886: /* original 9214, guest PC 0x0c0ae886 */
if(!s->budget--) { s->failed_pc=0x0c0ae886u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae8b2u,2);
goto P_0c0ae888;
P_0c0ae888: /* original 2dd8, guest PC 0x0c0ae888 */
if(!s->budget--) { s->failed_pc=0x0c0ae888u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0ae88a;
P_0c0ae88a: /* original 8d17, guest PC 0x0c0ae88a */
if(!s->budget--) { s->failed_pc=0x0c0ae88au; return 0; }
cond=r[17]&1u;
r[12]&=r[2];
if(cond) { goto P_0c0ae8bc; }
goto P_0c0ae88e;
P_0c0ae88c: /* original 2c29, guest PC 0x0c0ae88c */
if(!s->budget--) { s->failed_pc=0x0c0ae88cu; return 0; }
r[12]&=r[2];
goto P_0c0ae88e;
P_0c0ae88e: /* original 60d3, guest PC 0x0c0ae88e */
if(!s->budget--) { s->failed_pc=0x0c0ae88eu; return 0; }
r[0]=r[13];
goto P_0c0ae890;
P_0c0ae890: /* original 8817, guest PC 0x0c0ae890 */
if(!s->budget--) { s->failed_pc=0x0c0ae890u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000017u)!=0);
goto P_0c0ae892;
P_0c0ae892: /* original 8b01, guest PC 0x0c0ae892 */
if(!s->budget--) { s->failed_pc=0x0c0ae892u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae898; }
goto P_0c0ae894;
P_0c0ae894: /* original a006, guest PC 0x0c0ae894 */
if(!s->budget--) { s->failed_pc=0x0c0ae894u; return 0; }
r[14]=r[10];
goto P_0c0ae8a4;
P_0c0ae896: /* original 6ea3, guest PC 0x0c0ae896 */
if(!s->budget--) { s->failed_pc=0x0c0ae896u; return 0; }
r[14]=r[10];
goto P_0c0ae898;
P_0c0ae898: /* original 8816, guest PC 0x0c0ae898 */
if(!s->budget--) { s->failed_pc=0x0c0ae898u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000016u)!=0);
goto P_0c0ae89a;
P_0c0ae89a: /* original 8b01, guest PC 0x0c0ae89a */
if(!s->budget--) { s->failed_pc=0x0c0ae89au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae8a0; }
goto P_0c0ae89c;
P_0c0ae89c: /* original a002, guest PC 0x0c0ae89c */
if(!s->budget--) { s->failed_pc=0x0c0ae89cu; return 0; }
r[14]=r[11];
goto P_0c0ae8a4;
P_0c0ae89e: /* original 6eb3, guest PC 0x0c0ae89e */
if(!s->budget--) { s->failed_pc=0x0c0ae89eu; return 0; }
r[14]=r[11];
goto P_0c0ae8a0;
P_0c0ae8a0: /* original ee01, guest PC 0x0c0ae8a0 */
if(!s->budget--) { s->failed_pc=0x0c0ae8a0u; return 0; }
r[14]=0x00000001u;
goto P_0c0ae8a2;
P_0c0ae8a2: /* original 4edd, guest PC 0x0c0ae8a2 */
if(!s->budget--) { s->failed_pc=0x0c0ae8a2u; return 0; }
r[14]=(r[13]&0x80000000u)?((r[13]&31u)?r[14]>>((-r[13])&31u):0):r[14]<<(r[13]&31u);
goto P_0c0ae8a4;
P_0c0ae8a4: /* original 2ce8, guest PC 0x0c0ae8a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae8a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[14])==0)!=0);
goto P_0c0ae8a6;
P_0c0ae8a6: /* original 8933, guest PC 0x0c0ae8a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae8a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae910; }
goto P_0c0ae8a8;
P_0c0ae8a8: /* original a017, guest PC 0x0c0ae8a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae8a8u; return 0; }
goto P_0c0ae8da;
P_0c0ae8aa: /* original 0009, guest PC 0x0c0ae8aa */
if(!s->budget--) { s->failed_pc=0x0c0ae8aau; return 0; }
if(!vf3_matrix_family(0x0c0ae8acu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ae8acu; return 0; } return 1;
P_0c0ae8bc: /* original 2ee8, guest PC 0x0c0ae8bc */
if(!s->budget--) { s->failed_pc=0x0c0ae8bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0ae8be;
P_0c0ae8be: /* original 890c, guest PC 0x0c0ae8be */
if(!s->budget--) { s->failed_pc=0x0c0ae8beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae8da; }
goto P_0c0ae8c0;
P_0c0ae8c0: /* original 9286, guest PC 0x0c0ae8c0 */
if(!s->budget--) { s->failed_pc=0x0c0ae8c0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae9d0u,2);
goto P_0c0ae8c2;
P_0c0ae8c2: /* original 22e8, guest PC 0x0c0ae8c2 */
if(!s->budget--) { s->failed_pc=0x0c0ae8c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[14])==0)!=0);
goto P_0c0ae8c4;
P_0c0ae8c4: /* original 8900, guest PC 0x0c0ae8c4 */
if(!s->budget--) { s->failed_pc=0x0c0ae8c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae8c8; }
goto P_0c0ae8c6;
P_0c0ae8c6: /* original 2eab, guest PC 0x0c0ae8c6 */
if(!s->budget--) { s->failed_pc=0x0c0ae8c6u; return 0; }
r[14]|=r[10];
goto P_0c0ae8c8;
P_0c0ae8c8: /* original 9383, guest PC 0x0c0ae8c8 */
if(!s->budget--) { s->failed_pc=0x0c0ae8c8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae9d2u,2);
goto P_0c0ae8ca;
P_0c0ae8ca: /* original 23e8, guest PC 0x0c0ae8ca */
if(!s->budget--) { s->failed_pc=0x0c0ae8cau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c0ae8cc;
P_0c0ae8cc: /* original 8900, guest PC 0x0c0ae8cc */
if(!s->budget--) { s->failed_pc=0x0c0ae8ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae8d0; }
goto P_0c0ae8ce;
P_0c0ae8ce: /* original 2ebb, guest PC 0x0c0ae8ce */
if(!s->budget--) { s->failed_pc=0x0c0ae8ceu; return 0; }
r[14]|=r[11];
goto P_0c0ae8d0;
P_0c0ae8d0: /* original 6eec, guest PC 0x0c0ae8d0 */
if(!s->budget--) { s->failed_pc=0x0c0ae8d0u; return 0; }
r[14]=r[14]&255u;
goto P_0c0ae8d2;
P_0c0ae8d2: /* original 63e3, guest PC 0x0c0ae8d2 */
if(!s->budget--) { s->failed_pc=0x0c0ae8d2u; return 0; }
r[3]=r[14];
goto P_0c0ae8d4;
P_0c0ae8d4: /* original 3c30, guest PC 0x0c0ae8d4 */
if(!s->budget--) { s->failed_pc=0x0c0ae8d4u; return 0; }
r[17]=(r[17]&~1u)|((r[12]==r[3])!=0);
goto P_0c0ae8d6;
P_0c0ae8d6: /* original 8f1b, guest PC 0x0c0ae8d6 */
if(!s->budget--) { s->failed_pc=0x0c0ae8d6u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[14],4);
if(!cond) { goto P_0c0ae910; }
goto P_0c0ae8da;
P_0c0ae8d8: /* original 2fe2, guest PC 0x0c0ae8d8 */
if(!s->budget--) { s->failed_pc=0x0c0ae8d8u; return 0; }
write(ram,r[15],r[14],4);
goto P_0c0ae8da;
P_0c0ae8da: /* original 907b, guest PC 0x0c0ae8da */
if(!s->budget--) { s->failed_pc=0x0c0ae8dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae9d4u,2);
goto P_0c0ae8dc;
P_0c0ae8dc: /* original e21f, guest PC 0x0c0ae8dc */
if(!s->budget--) { s->failed_pc=0x0c0ae8dcu; return 0; }
r[2]=0x0000001fu;
goto P_0c0ae8de;
P_0c0ae8de: /* original 7701, guest PC 0x0c0ae8de */
if(!s->budget--) { s->failed_pc=0x0c0ae8deu; return 0; }
r[7]+=0x00000001u;
goto P_0c0ae8e0;
P_0c0ae8e0: /* original 0424, guest PC 0x0c0ae8e0 */
if(!s->budget--) { s->failed_pc=0x0c0ae8e0u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c0ae8e2;
P_0c0ae8e2: /* original 5362, guest PC 0x0c0ae8e2 */
if(!s->budget--) { s->failed_pc=0x0c0ae8e2u; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c0ae8e4;
P_0c0ae8e4: /* original 2f32, guest PC 0x0c0ae8e4 */
if(!s->budget--) { s->failed_pc=0x0c0ae8e4u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ae8e6;
P_0c0ae8e6: /* original 8439, guest PC 0x0c0ae8e6 */
if(!s->budget--) { s->failed_pc=0x0c0ae8e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+9,1);
goto P_0c0ae8e8;
P_0c0ae8e8: /* original 7308, guest PC 0x0c0ae8e8 */
if(!s->budget--) { s->failed_pc=0x0c0ae8e8u; return 0; }
r[3]+=0x00000008u;
goto P_0c0ae8ea;
P_0c0ae8ea: /* original 6230, guest PC 0x0c0ae8ea */
if(!s->budget--) { s->failed_pc=0x0c0ae8eau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c0ae8ec;
P_0c0ae8ec: /* original e33f, guest PC 0x0c0ae8ec */
if(!s->budget--) { s->failed_pc=0x0c0ae8ecu; return 0; }
r[3]=0x0000003fu;
goto P_0c0ae8ee;
P_0c0ae8ee: /* original 600c, guest PC 0x0c0ae8ee */
if(!s->budget--) { s->failed_pc=0x0c0ae8eeu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae8f0;
P_0c0ae8f0: /* original 9171, guest PC 0x0c0ae8f0 */
if(!s->budget--) { s->failed_pc=0x0c0ae8f0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae9d6u,2);
goto P_0c0ae8f2;
P_0c0ae8f2: /* original 4018, guest PC 0x0c0ae8f2 */
if(!s->budget--) { s->failed_pc=0x0c0ae8f2u; return 0; }
r[0]<<=8;
goto P_0c0ae8f4;
P_0c0ae8f4: /* original 622c, guest PC 0x0c0ae8f4 */
if(!s->budget--) { s->failed_pc=0x0c0ae8f4u; return 0; }
r[2]=r[2]&255u;
goto P_0c0ae8f6;
P_0c0ae8f6: /* original 2099, guest PC 0x0c0ae8f6 */
if(!s->budget--) { s->failed_pc=0x0c0ae8f6u; return 0; }
r[0]&=r[9];
goto P_0c0ae8f8;
P_0c0ae8f8: /* original 314c, guest PC 0x0c0ae8f8 */
if(!s->budget--) { s->failed_pc=0x0c0ae8f8u; return 0; }
r[1]+=r[4];
goto P_0c0ae8fa;
P_0c0ae8fa: /* original 202b, guest PC 0x0c0ae8fa */
if(!s->budget--) { s->failed_pc=0x0c0ae8fau; return 0; }
r[0]|=r[2];
goto P_0c0ae8fc;
P_0c0ae8fc: /* original 2102, guest PC 0x0c0ae8fc */
if(!s->budget--) { s->failed_pc=0x0c0ae8fcu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0ae8fe;
P_0c0ae8fe: /* original 2739, guest PC 0x0c0ae8fe */
if(!s->budget--) { s->failed_pc=0x0c0ae8feu; return 0; }
r[7]&=r[3];
goto P_0c0ae900;
P_0c0ae900: /* original 906a, guest PC 0x0c0ae900 */
if(!s->budget--) { s->failed_pc=0x0c0ae900u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae9d8u,2);
goto P_0c0ae902;
P_0c0ae902: /* original 0474, guest PC 0x0c0ae902 */
if(!s->budget--) { s->failed_pc=0x0c0ae902u; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c0ae904;
P_0c0ae904: /* original 7001, guest PC 0x0c0ae904 */
if(!s->budget--) { s->failed_pc=0x0c0ae904u; return 0; }
r[0]+=0x00000001u;
goto P_0c0ae906;
P_0c0ae906: /* original 0474, guest PC 0x0c0ae906 */
if(!s->budget--) { s->failed_pc=0x0c0ae906u; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c0ae908;
P_0c0ae908: /* original 7001, guest PC 0x0c0ae908 */
if(!s->budget--) { s->failed_pc=0x0c0ae908u; return 0; }
r[0]+=0x00000001u;
goto P_0c0ae90a;
P_0c0ae90a: /* original 0474, guest PC 0x0c0ae90a */
if(!s->budget--) { s->failed_pc=0x0c0ae90au; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c0ae90c;
P_0c0ae90c: /* original 7001, guest PC 0x0c0ae90c */
if(!s->budget--) { s->failed_pc=0x0c0ae90cu; return 0; }
r[0]+=0x00000001u;
goto P_0c0ae90e;
P_0c0ae90e: /* original 0474, guest PC 0x0c0ae90e */
if(!s->budget--) { s->failed_pc=0x0c0ae90eu; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c0ae910;
P_0c0ae910: /* original 7f08, guest PC 0x0c0ae910 */
if(!s->budget--) { s->failed_pc=0x0c0ae910u; return 0; }
r[15]+=0x00000008u;
goto P_0c0ae912;
P_0c0ae912: /* original 5362, guest PC 0x0c0ae912 */
if(!s->budget--) { s->failed_pc=0x0c0ae912u; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c0ae914;
P_0c0ae914: /* original 730a, guest PC 0x0c0ae914 */
if(!s->budget--) { s->failed_pc=0x0c0ae914u; return 0; }
r[3]+=0x0000000au;
goto P_0c0ae916;
P_0c0ae916: /* original 1632, guest PC 0x0c0ae916 */
if(!s->budget--) { s->failed_pc=0x0c0ae916u; return 0; }
write(ram,r[6]+8,r[3],4);
goto P_0c0ae918;
P_0c0ae918: /* original 69f6, guest PC 0x0c0ae918 */
if(!s->budget--) { s->failed_pc=0x0c0ae918u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0ae91a;
P_0c0ae91a: /* original 6af6, guest PC 0x0c0ae91a */
if(!s->budget--) { s->failed_pc=0x0c0ae91au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0ae91c;
P_0c0ae91c: /* original 6bf6, guest PC 0x0c0ae91c */
if(!s->budget--) { s->failed_pc=0x0c0ae91cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ae91e;
P_0c0ae91e: /* original 6cf6, guest PC 0x0c0ae91e */
if(!s->budget--) { s->failed_pc=0x0c0ae91eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ae920;
P_0c0ae920: /* original 6df6, guest PC 0x0c0ae920 */
if(!s->budget--) { s->failed_pc=0x0c0ae920u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ae922;
P_0c0ae922: /* original acbb, guest PC 0x0c0ae922 */
if(!s->budget--) { s->failed_pc=0x0c0ae922u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ae29c;
P_0c0ae924: /* original 6ef6, guest PC 0x0c0ae924 */
if(!s->budget--) { s->failed_pc=0x0c0ae924u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ae926u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ae926u; return 0; } return 1;
P_0c0ae9ec: /* original 2fe6, guest PC 0x0c0ae9ec */
if(!s->budget--) { s->failed_pc=0x0c0ae9ecu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae9ee;
P_0c0ae9ee: /* original 6e63, guest PC 0x0c0ae9ee */
if(!s->budget--) { s->failed_pc=0x0c0ae9eeu; return 0; }
r[14]=r[6];
goto P_0c0ae9f0;
P_0c0ae9f0: /* original 2fd6, guest PC 0x0c0ae9f0 */
if(!s->budget--) { s->failed_pc=0x0c0ae9f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae9f2;
P_0c0ae9f2: /* original 2fc6, guest PC 0x0c0ae9f2 */
if(!s->budget--) { s->failed_pc=0x0c0ae9f2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae9f4;
P_0c0ae9f4: /* original 6c43, guest PC 0x0c0ae9f4 */
if(!s->budget--) { s->failed_pc=0x0c0ae9f4u; return 0; }
r[12]=r[4];
goto P_0c0ae9f6;
P_0c0ae9f6: /* original 4f22, guest PC 0x0c0ae9f6 */
if(!s->budget--) { s->failed_pc=0x0c0ae9f6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ae9f8;
P_0c0ae9f8: /* original 7fdc, guest PC 0x0c0ae9f8 */
if(!s->budget--) { s->failed_pc=0x0c0ae9f8u; return 0; }
r[15]+=0xffffffdcu;
goto P_0c0ae9fa;
P_0c0ae9fa: /* original 2f52, guest PC 0x0c0ae9fa */
if(!s->budget--) { s->failed_pc=0x0c0ae9fau; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ae9fc;
P_0c0ae9fc: /* original 53e1, guest PC 0x0c0ae9fc */
if(!s->budget--) { s->failed_pc=0x0c0ae9fcu; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0ae9fe;
P_0c0ae9fe: /* original 62e2, guest PC 0x0c0ae9fe */
if(!s->budget--) { s->failed_pc=0x0c0ae9feu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0aea00;
P_0c0aea00: /* original d439, guest PC 0x0c0aea00 */
if(!s->budget--) { s->failed_pc=0x0c0aea00u; return 0; }
r[4]=read(ram,0x0c0aeae8u,4);
goto P_0c0aea02;
P_0c0aea02: /* original dd38, guest PC 0x0c0aea02 */
if(!s->budget--) { s->failed_pc=0x0c0aea02u; return 0; }
r[13]=read(ram,0x0c0aeae4u,4);
goto P_0c0aea04;
P_0c0aea04: /* original 3230, guest PC 0x0c0aea04 */
if(!s->budget--) { s->failed_pc=0x0c0aea04u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0aea06;
P_0c0aea06: /* original 8b1c, guest PC 0x0c0aea06 */
if(!s->budget--) { s->failed_pc=0x0c0aea06u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aea42; }
goto P_0c0aea08;
P_0c0aea08: /* original 51d1, guest PC 0x0c0aea08 */
if(!s->budget--) { s->failed_pc=0x0c0aea08u; return 0; }
r[1]=read(ram,r[13]+4,4);
goto P_0c0aea0a;
P_0c0aea0a: /* original d338, guest PC 0x0c0aea0a */
if(!s->budget--) { s->failed_pc=0x0c0aea0au; return 0; }
r[3]=read(ram,0x0c0aeaecu,4);
goto P_0c0aea0c;
P_0c0aea0c: /* original 2138, guest PC 0x0c0aea0c */
if(!s->budget--) { s->failed_pc=0x0c0aea0cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0aea0e;
P_0c0aea0e: /* original 8b18, guest PC 0x0c0aea0e */
if(!s->budget--) { s->failed_pc=0x0c0aea0eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aea42; }
goto P_0c0aea10;
P_0c0aea10: /* original 5245, guest PC 0x0c0aea10 */
if(!s->budget--) { s->failed_pc=0x0c0aea10u; return 0; }
r[2]=read(ram,r[4]+20,4);
goto P_0c0aea12;
P_0c0aea12: /* original 4215, guest PC 0x0c0aea12 */
if(!s->budget--) { s->failed_pc=0x0c0aea12u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0aea14;
P_0c0aea14: /* original 8b15, guest PC 0x0c0aea14 */
if(!s->budget--) { s->failed_pc=0x0c0aea14u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aea42; }
goto P_0c0aea16;
P_0c0aea16: /* original 54e2, guest PC 0x0c0aea16 */
if(!s->budget--) { s->failed_pc=0x0c0aea16u; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c0aea18;
P_0c0aea18: /* original 9063, guest PC 0x0c0aea18 */
if(!s->budget--) { s->failed_pc=0x0c0aea18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aeae2u,2);
goto P_0c0aea1a;
P_0c0aea1a: /* original 7403, guest PC 0x0c0aea1a */
if(!s->budget--) { s->failed_pc=0x0c0aea1au; return 0; }
r[4]+=0x00000003u;
goto P_0c0aea1c;
P_0c0aea1c: /* original 05cc, guest PC 0x0c0aea1c */
if(!s->budget--) { s->failed_pc=0x0c0aea1cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0aea1e;
P_0c0aea1e: /* original 6440, guest PC 0x0c0aea1e */
if(!s->budget--) { s->failed_pc=0x0c0aea1eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]=tmp;
goto P_0c0aea20;
P_0c0aea20: /* original 655c, guest PC 0x0c0aea20 */
if(!s->budget--) { s->failed_pc=0x0c0aea20u; return 0; }
r[5]=r[5]&255u;
goto P_0c0aea22;
P_0c0aea22: /* original 354c, guest PC 0x0c0aea22 */
if(!s->budget--) { s->failed_pc=0x0c0aea22u; return 0; }
r[5]+=r[4];
goto P_0c0aea24;
P_0c0aea24: /* original e428, guest PC 0x0c0aea24 */
if(!s->budget--) { s->failed_pc=0x0c0aea24u; return 0; }
r[4]=0x00000028u;
goto P_0c0aea26;
P_0c0aea26: /* original 3547, guest PC 0x0c0aea26 */
if(!s->budget--) { s->failed_pc=0x0c0aea26u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[4])!=0);
goto P_0c0aea28;
P_0c0aea28: /* original 8b00, guest PC 0x0c0aea28 */
if(!s->budget--) { s->failed_pc=0x0c0aea28u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aea2c; }
goto P_0c0aea2a;
P_0c0aea2a: /* original 6543, guest PC 0x0c0aea2a */
if(!s->budget--) { s->failed_pc=0x0c0aea2au; return 0; }
r[5]=r[4];
goto P_0c0aea2c;
P_0c0aea2c: /* original 0c54, guest PC 0x0c0aea2c */
if(!s->budget--) { s->failed_pc=0x0c0aea2cu; return 0; }
write(ram,r[12]+r[0],r[5],1);
goto P_0c0aea2e;
P_0c0aea2e: /* original d330, guest PC 0x0c0aea2e */
if(!s->budget--) { s->failed_pc=0x0c0aea2eu; return 0; }
r[3]=read(ram,0x0c0aeaf0u,4);
goto P_0c0aea30;
P_0c0aea30: /* original 430b, guest PC 0x0c0aea30 */
if(!s->budget--) { s->failed_pc=0x0c0aea30u; return 0; }
target=r[3];
r[16]=code_base|0x0c0aea34u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aea34u) { target=s->pc; goto dispatch; }
goto P_0c0aea34;
P_0c0aea32: /* original 64c3, guest PC 0x0c0aea32 */
if(!s->budget--) { s->failed_pc=0x0c0aea32u; return 0; }
r[4]=r[12];
goto P_0c0aea34;
P_0c0aea34: /* original 84d8, guest PC 0x0c0aea34 */
if(!s->budget--) { s->failed_pc=0x0c0aea34u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+8,1);
goto P_0c0aea36;
P_0c0aea36: /* original 600c, guest PC 0x0c0aea36 */
if(!s->budget--) { s->failed_pc=0x0c0aea36u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aea38;
P_0c0aea38: /* original 8807, guest PC 0x0c0aea38 */
if(!s->budget--) { s->failed_pc=0x0c0aea38u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0aea3a;
P_0c0aea3a: /* original 8b02, guest PC 0x0c0aea3a */
if(!s->budget--) { s->failed_pc=0x0c0aea3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aea42; }
goto P_0c0aea3c;
P_0c0aea3c: /* original 62d2, guest PC 0x0c0aea3c */
if(!s->budget--) { s->failed_pc=0x0c0aea3cu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0aea3e;
P_0c0aea3e: /* original d32d, guest PC 0x0c0aea3e */
if(!s->budget--) { s->failed_pc=0x0c0aea3eu; return 0; }
r[3]=read(ram,0x0c0aeaf4u,4);
goto P_0c0aea40;
P_0c0aea40: /* original 2238, guest PC 0x0c0aea40 */
if(!s->budget--) { s->failed_pc=0x0c0aea40u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aea42;
P_0c0aea42: /* original 51e2, guest PC 0x0c0aea42 */
if(!s->budget--) { s->failed_pc=0x0c0aea42u; return 0; }
r[1]=read(ram,r[14]+8,4);
goto P_0c0aea44;
P_0c0aea44: /* original 66e3, guest PC 0x0c0aea44 */
if(!s->budget--) { s->failed_pc=0x0c0aea44u; return 0; }
r[6]=r[14];
goto P_0c0aea46;
P_0c0aea46: /* original 7104, guest PC 0x0c0aea46 */
if(!s->budget--) { s->failed_pc=0x0c0aea46u; return 0; }
r[1]+=0x00000004u;
goto P_0c0aea48;
P_0c0aea48: /* original 1e12, guest PC 0x0c0aea48 */
if(!s->budget--) { s->failed_pc=0x0c0aea48u; return 0; }
write(ram,r[14]+8,r[1],4);
goto P_0c0aea4a;
P_0c0aea4a: /* original 65f2, guest PC 0x0c0aea4a */
if(!s->budget--) { s->failed_pc=0x0c0aea4au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0aea4c;
P_0c0aea4c: /* original bc26, guest PC 0x0c0aea4c */
if(!s->budget--) { s->failed_pc=0x0c0aea4cu; return 0; }
target=code_base|0x0c0ae29cu; r[16]=code_base|0x0c0aea50u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aea50u) { target=s->pc; goto dispatch; }
goto P_0c0aea50;
P_0c0aea4e: /* original 64c3, guest PC 0x0c0aea4e */
if(!s->budget--) { s->failed_pc=0x0c0aea4eu; return 0; }
r[4]=r[12];
goto P_0c0aea50;
P_0c0aea50: /* original 7f24, guest PC 0x0c0aea50 */
if(!s->budget--) { s->failed_pc=0x0c0aea50u; return 0; }
r[15]+=0x00000024u;
goto P_0c0aea52;
P_0c0aea52: /* original 4f26, guest PC 0x0c0aea52 */
if(!s->budget--) { s->failed_pc=0x0c0aea52u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aea54;
P_0c0aea54: /* original 6cf6, guest PC 0x0c0aea54 */
if(!s->budget--) { s->failed_pc=0x0c0aea54u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0aea56;
P_0c0aea56: /* original 6df6, guest PC 0x0c0aea56 */
if(!s->budget--) { s->failed_pc=0x0c0aea56u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aea58;
P_0c0aea58: /* original 000b, guest PC 0x0c0aea58 */
if(!s->budget--) { s->failed_pc=0x0c0aea58u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0aea5a: /* original 6ef6, guest PC 0x0c0aea5a */
if(!s->budget--) { s->failed_pc=0x0c0aea5au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0aea5cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aea5cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
