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
int vf3_away_batch214_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c042c1eu: goto P_0c042c1e;
case 0x0c042c20u: goto P_0c042c20;
case 0x0c042c22u: goto P_0c042c22;
case 0x0c042c24u: goto P_0c042c24;
case 0x0c042c26u: goto P_0c042c26;
case 0x0c042c28u: goto P_0c042c28;
case 0x0c042c2au: goto P_0c042c2a;
case 0x0c042c2cu: goto P_0c042c2c;
case 0x0c042c2eu: goto P_0c042c2e;
case 0x0c042c30u: goto P_0c042c30;
case 0x0c042c32u: goto P_0c042c32;
case 0x0c042c34u: goto P_0c042c34;
case 0x0c042c36u: goto P_0c042c36;
case 0x0c042c38u: goto P_0c042c38;
case 0x0c042c3au: goto P_0c042c3a;
case 0x0c042c3cu: goto P_0c042c3c;
case 0x0c042c3eu: goto P_0c042c3e;
case 0x0c042c40u: goto P_0c042c40;
case 0x0c042c42u: goto P_0c042c42;
case 0x0c042c44u: goto P_0c042c44;
case 0x0c042c46u: goto P_0c042c46;
case 0x0c042c48u: goto P_0c042c48;
case 0x0c042c4au: goto P_0c042c4a;
case 0x0c042c4cu: goto P_0c042c4c;
case 0x0c042c4eu: goto P_0c042c4e;
case 0x0c042c50u: goto P_0c042c50;
case 0x0c042c52u: goto P_0c042c52;
case 0x0c042c54u: goto P_0c042c54;
case 0x0c042c56u: goto P_0c042c56;
case 0x0c042c58u: goto P_0c042c58;
case 0x0c042c5au: goto P_0c042c5a;
case 0x0c042c5cu: goto P_0c042c5c;
case 0x0c042c5eu: goto P_0c042c5e;
case 0x0c042c60u: goto P_0c042c60;
case 0x0c042c62u: goto P_0c042c62;
case 0x0c042c64u: goto P_0c042c64;
case 0x0c042c66u: goto P_0c042c66;
case 0x0c042c68u: goto P_0c042c68;
case 0x0c042c6au: goto P_0c042c6a;
case 0x0c042c6cu: goto P_0c042c6c;
case 0x0c042c6eu: goto P_0c042c6e;
case 0x0c042c70u: goto P_0c042c70;
case 0x0c042c72u: goto P_0c042c72;
case 0x0c042c74u: goto P_0c042c74;
case 0x0c042c76u: goto P_0c042c76;
case 0x0c042c78u: goto P_0c042c78;
case 0x0c042c7au: goto P_0c042c7a;
case 0x0c042c7cu: goto P_0c042c7c;
case 0x0c042c7eu: goto P_0c042c7e;
case 0x0c042c80u: goto P_0c042c80;
case 0x0c042c82u: goto P_0c042c82;
case 0x0c042c84u: goto P_0c042c84;
case 0x0c042c86u: goto P_0c042c86;
case 0x0c042c88u: goto P_0c042c88;
case 0x0c042c8au: goto P_0c042c8a;
case 0x0c042c8cu: goto P_0c042c8c;
case 0x0c042c8eu: goto P_0c042c8e;
case 0x0c042c90u: goto P_0c042c90;
case 0x0c042c92u: goto P_0c042c92;
case 0x0c042c94u: goto P_0c042c94;
case 0x0c042c96u: goto P_0c042c96;
case 0x0c042c98u: goto P_0c042c98;
case 0x0c042c9au: goto P_0c042c9a;
case 0x0c042c9cu: goto P_0c042c9c;
case 0x0c042c9eu: goto P_0c042c9e;
case 0x0c042ca0u: goto P_0c042ca0;
case 0x0c042ca2u: goto P_0c042ca2;
case 0x0c042ca4u: goto P_0c042ca4;
case 0x0c042ca6u: goto P_0c042ca6;
case 0x0c042ca8u: goto P_0c042ca8;
case 0x0c042caau: goto P_0c042caa;
case 0x0c042cacu: goto P_0c042cac;
case 0x0c042caeu: goto P_0c042cae;
case 0x0c042cb0u: goto P_0c042cb0;
case 0x0c042cb2u: goto P_0c042cb2;
case 0x0c042cb4u: goto P_0c042cb4;
case 0x0c042cb6u: goto P_0c042cb6;
case 0x0c042cb8u: goto P_0c042cb8;
case 0x0c042cbau: goto P_0c042cba;
case 0x0c042cbcu: goto P_0c042cbc;
case 0x0c042cbeu: goto P_0c042cbe;
case 0x0c042cc0u: goto P_0c042cc0;
case 0x0c042cc2u: goto P_0c042cc2;
case 0x0c042cc4u: goto P_0c042cc4;
case 0x0c042cc6u: goto P_0c042cc6;
case 0x0c042cc8u: goto P_0c042cc8;
case 0x0c042ccau: goto P_0c042cca;
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
case 0x0c0ae5a0u: goto P_0c0ae5a0;
case 0x0c0ae5a2u: goto P_0c0ae5a2;
case 0x0c0ae5a4u: goto P_0c0ae5a4;
case 0x0c0ae5a6u: goto P_0c0ae5a6;
case 0x0c0ae5a8u: goto P_0c0ae5a8;
case 0x0c0ae5aau: goto P_0c0ae5aa;
case 0x0c0ae5acu: goto P_0c0ae5ac;
case 0x0c0ae5aeu: goto P_0c0ae5ae;
case 0x0c0ae5b0u: goto P_0c0ae5b0;
case 0x0c0ae5b2u: goto P_0c0ae5b2;
case 0x0c0ae5b4u: goto P_0c0ae5b4;
case 0x0c0ae5b6u: goto P_0c0ae5b6;
case 0x0c0ae5b8u: goto P_0c0ae5b8;
case 0x0c0ae5bau: goto P_0c0ae5ba;
case 0x0c0ae5bcu: goto P_0c0ae5bc;
case 0x0c0ae5beu: goto P_0c0ae5be;
case 0x0c0ae5c0u: goto P_0c0ae5c0;
case 0x0c0ae5c2u: goto P_0c0ae5c2;
case 0x0c0ae5c4u: goto P_0c0ae5c4;
case 0x0c0ae5c6u: goto P_0c0ae5c6;
case 0x0c0ae5c8u: goto P_0c0ae5c8;
case 0x0c0ae5cau: goto P_0c0ae5ca;
case 0x0c0ae5ccu: goto P_0c0ae5cc;
case 0x0c0ae5ceu: goto P_0c0ae5ce;
case 0x0c0ae5d0u: goto P_0c0ae5d0;
case 0x0c0ae5d2u: goto P_0c0ae5d2;
case 0x0c0ae5d4u: goto P_0c0ae5d4;
case 0x0c0ae5d6u: goto P_0c0ae5d6;
case 0x0c0ae5d8u: goto P_0c0ae5d8;
case 0x0c0ae5dau: goto P_0c0ae5da;
case 0x0c0ae5dcu: goto P_0c0ae5dc;
case 0x0c0ae5deu: goto P_0c0ae5de;
case 0x0c0ae5e0u: goto P_0c0ae5e0;
case 0x0c0ae5e2u: goto P_0c0ae5e2;
case 0x0c0ae5e4u: goto P_0c0ae5e4;
case 0x0c0ae5e6u: goto P_0c0ae5e6;
case 0x0c0ae5e8u: goto P_0c0ae5e8;
case 0x0c0ae5eau: goto P_0c0ae5ea;
case 0x0c0ae5ecu: goto P_0c0ae5ec;
case 0x0c0ae5eeu: goto P_0c0ae5ee;
case 0x0c0ae5f0u: goto P_0c0ae5f0;
case 0x0c0ae5f2u: goto P_0c0ae5f2;
case 0x0c0ae5f4u: goto P_0c0ae5f4;
case 0x0c0ae5f6u: goto P_0c0ae5f6;
case 0x0c0ae5f8u: goto P_0c0ae5f8;
case 0x0c0ae5fau: goto P_0c0ae5fa;
case 0x0c0ae5fcu: goto P_0c0ae5fc;
case 0x0c0ae5feu: goto P_0c0ae5fe;
case 0x0c0ae600u: goto P_0c0ae600;
case 0x0c0ae602u: goto P_0c0ae602;
case 0x0c0ae604u: goto P_0c0ae604;
case 0x0c0ae606u: goto P_0c0ae606;
case 0x0c0ae608u: goto P_0c0ae608;
case 0x0c0ae60au: goto P_0c0ae60a;
case 0x0c0ae60cu: goto P_0c0ae60c;
case 0x0c0ae60eu: goto P_0c0ae60e;
case 0x0c0ae610u: goto P_0c0ae610;
case 0x0c0ae612u: goto P_0c0ae612;
case 0x0c0ae614u: goto P_0c0ae614;
case 0x0c0ae616u: goto P_0c0ae616;
case 0x0c0ae618u: goto P_0c0ae618;
case 0x0c0ae61au: goto P_0c0ae61a;
case 0x0c0ae61cu: goto P_0c0ae61c;
case 0x0c0ae61eu: goto P_0c0ae61e;
case 0x0c0ae620u: goto P_0c0ae620;
case 0x0c0ae622u: goto P_0c0ae622;
case 0x0c0ae624u: goto P_0c0ae624;
case 0x0c0ae626u: goto P_0c0ae626;
case 0x0c0ae628u: goto P_0c0ae628;
case 0x0c0ae62au: goto P_0c0ae62a;
case 0x0c0ae62cu: goto P_0c0ae62c;
case 0x0c0ae62eu: goto P_0c0ae62e;
case 0x0c0ae630u: goto P_0c0ae630;
case 0x0c0ae632u: goto P_0c0ae632;
case 0x0c0ae634u: goto P_0c0ae634;
case 0x0c0ae636u: goto P_0c0ae636;
case 0x0c0ae638u: goto P_0c0ae638;
case 0x0c0ae63au: goto P_0c0ae63a;
case 0x0c0ae63cu: goto P_0c0ae63c;
case 0x0c0ae63eu: goto P_0c0ae63e;
case 0x0c0ae640u: goto P_0c0ae640;
case 0x0c0ae642u: goto P_0c0ae642;
case 0x0c0ae644u: goto P_0c0ae644;
case 0x0c0ae646u: goto P_0c0ae646;
case 0x0c0ae648u: goto P_0c0ae648;
case 0x0c0ae64au: goto P_0c0ae64a;
case 0x0c0ae64cu: goto P_0c0ae64c;
case 0x0c0ae64eu: goto P_0c0ae64e;
case 0x0c0ae650u: goto P_0c0ae650;
case 0x0c0ae652u: goto P_0c0ae652;
case 0x0c0ae654u: goto P_0c0ae654;
case 0x0c0ae656u: goto P_0c0ae656;
case 0x0c0ae658u: goto P_0c0ae658;
case 0x0c0ae65au: goto P_0c0ae65a;
case 0x0c0ae65cu: goto P_0c0ae65c;
case 0x0c0ae65eu: goto P_0c0ae65e;
case 0x0c0ae660u: goto P_0c0ae660;
case 0x0c0ae662u: goto P_0c0ae662;
case 0x0c0ae664u: goto P_0c0ae664;
case 0x0c0ae666u: goto P_0c0ae666;
case 0x0c0ae668u: goto P_0c0ae668;
case 0x0c0ae66au: goto P_0c0ae66a;
case 0x0c0ae66cu: goto P_0c0ae66c;
case 0x0c0ae66eu: goto P_0c0ae66e;
case 0x0c0ae670u: goto P_0c0ae670;
case 0x0c0ae672u: goto P_0c0ae672;
case 0x0c0ae674u: goto P_0c0ae674;
case 0x0c0ae676u: goto P_0c0ae676;
case 0x0c0ae678u: goto P_0c0ae678;
case 0x0c0ae67au: goto P_0c0ae67a;
case 0x0c0ae67cu: goto P_0c0ae67c;
case 0x0c0ae67eu: goto P_0c0ae67e;
case 0x0c0ae680u: goto P_0c0ae680;
case 0x0c0ae682u: goto P_0c0ae682;
case 0x0c0ae684u: goto P_0c0ae684;
case 0x0c0ae686u: goto P_0c0ae686;
case 0x0c0ae688u: goto P_0c0ae688;
case 0x0c0ae68au: goto P_0c0ae68a;
case 0x0c0ae68cu: goto P_0c0ae68c;
case 0x0c0ae68eu: goto P_0c0ae68e;
case 0x0c0ae690u: goto P_0c0ae690;
case 0x0c0ae692u: goto P_0c0ae692;
case 0x0c0ae694u: goto P_0c0ae694;
case 0x0c0ae696u: goto P_0c0ae696;
case 0x0c0ae698u: goto P_0c0ae698;
case 0x0c0ae69au: goto P_0c0ae69a;
case 0x0c0ae69cu: goto P_0c0ae69c;
case 0x0c0ae69eu: goto P_0c0ae69e;
case 0x0c0ae6a0u: goto P_0c0ae6a0;
case 0x0c0ae6a2u: goto P_0c0ae6a2;
case 0x0c0ae6a4u: goto P_0c0ae6a4;
case 0x0c0ae6a6u: goto P_0c0ae6a6;
case 0x0c0ae6a8u: goto P_0c0ae6a8;
case 0x0c0ae6aau: goto P_0c0ae6aa;
case 0x0c0ae6acu: goto P_0c0ae6ac;
case 0x0c0ae6e8u: goto P_0c0ae6e8;
case 0x0c0ae6eau: goto P_0c0ae6ea;
case 0x0c0ae6ecu: goto P_0c0ae6ec;
case 0x0c0ae6eeu: goto P_0c0ae6ee;
case 0x0c0ae6f0u: goto P_0c0ae6f0;
case 0x0c0ae6f2u: goto P_0c0ae6f2;
case 0x0c0ae6f4u: goto P_0c0ae6f4;
case 0x0c0ae6f6u: goto P_0c0ae6f6;
case 0x0c0ae6f8u: goto P_0c0ae6f8;
case 0x0c0ae6fau: goto P_0c0ae6fa;
case 0x0c0ae6fcu: goto P_0c0ae6fc;
case 0x0c0ae6feu: goto P_0c0ae6fe;
case 0x0c0ae700u: goto P_0c0ae700;
case 0x0c0ae702u: goto P_0c0ae702;
case 0x0c0ae704u: goto P_0c0ae704;
case 0x0c0ae706u: goto P_0c0ae706;
case 0x0c0ae708u: goto P_0c0ae708;
case 0x0c0ae70au: goto P_0c0ae70a;
case 0x0c0ae70cu: goto P_0c0ae70c;
case 0x0c0ae70eu: goto P_0c0ae70e;
case 0x0c0ae710u: goto P_0c0ae710;
case 0x0c0ae712u: goto P_0c0ae712;
case 0x0c0ae714u: goto P_0c0ae714;
case 0x0c0ae716u: goto P_0c0ae716;
case 0x0c0ae718u: goto P_0c0ae718;
case 0x0c0ae71au: goto P_0c0ae71a;
case 0x0c0ae71cu: goto P_0c0ae71c;
case 0x0c0ae71eu: goto P_0c0ae71e;
case 0x0c0ae720u: goto P_0c0ae720;
case 0x0c0ae722u: goto P_0c0ae722;
case 0x0c0ae724u: goto P_0c0ae724;
case 0x0c0ae726u: goto P_0c0ae726;
case 0x0c0ae728u: goto P_0c0ae728;
case 0x0c0ae72au: goto P_0c0ae72a;
case 0x0c0ae72cu: goto P_0c0ae72c;
case 0x0c0ae72eu: goto P_0c0ae72e;
case 0x0c0ae730u: goto P_0c0ae730;
case 0x0c0ae732u: goto P_0c0ae732;
case 0x0c0ae734u: goto P_0c0ae734;
case 0x0c0ae736u: goto P_0c0ae736;
case 0x0c0ae738u: goto P_0c0ae738;
case 0x0c0ae73au: goto P_0c0ae73a;
case 0x0c0ae73cu: goto P_0c0ae73c;
case 0x0c0ae73eu: goto P_0c0ae73e;
case 0x0c0ae740u: goto P_0c0ae740;
case 0x0c0ae742u: goto P_0c0ae742;
case 0x0c0ae744u: goto P_0c0ae744;
case 0x0c0ae746u: goto P_0c0ae746;
case 0x0c0ae748u: goto P_0c0ae748;
case 0x0c0ae74au: goto P_0c0ae74a;
case 0x0c0ae74cu: goto P_0c0ae74c;
case 0x0c0ae74eu: goto P_0c0ae74e;
case 0x0c0ae750u: goto P_0c0ae750;
case 0x0c0ae752u: goto P_0c0ae752;
case 0x0c0ae754u: goto P_0c0ae754;
case 0x0c0ae756u: goto P_0c0ae756;
case 0x0c0ae758u: goto P_0c0ae758;
case 0x0c0ae75au: goto P_0c0ae75a;
case 0x0c0ae75cu: goto P_0c0ae75c;
case 0x0c0ae75eu: goto P_0c0ae75e;
case 0x0c0ae760u: goto P_0c0ae760;
case 0x0c0ae762u: goto P_0c0ae762;
case 0x0c0ae764u: goto P_0c0ae764;
case 0x0c0ae766u: goto P_0c0ae766;
case 0x0c0ae768u: goto P_0c0ae768;
case 0x0c0ae76au: goto P_0c0ae76a;
case 0x0c0ae76cu: goto P_0c0ae76c;
case 0x0c0ae76eu: goto P_0c0ae76e;
case 0x0c0ae770u: goto P_0c0ae770;
case 0x0c0ae772u: goto P_0c0ae772;
case 0x0c0ae774u: goto P_0c0ae774;
case 0x0c0ae776u: goto P_0c0ae776;
case 0x0c0ae778u: goto P_0c0ae778;
case 0x0c0ae77au: goto P_0c0ae77a;
case 0x0c0ae77cu: goto P_0c0ae77c;
case 0x0c0ae77eu: goto P_0c0ae77e;
case 0x0c0ae780u: goto P_0c0ae780;
case 0x0c0ae782u: goto P_0c0ae782;
case 0x0c0ae784u: goto P_0c0ae784;
case 0x0c0ae786u: goto P_0c0ae786;
case 0x0c0ae788u: goto P_0c0ae788;
case 0x0c0ae78au: goto P_0c0ae78a;
case 0x0c0ae78cu: goto P_0c0ae78c;
case 0x0c0ae78eu: goto P_0c0ae78e;
case 0x0c0ae790u: goto P_0c0ae790;
case 0x0c0ae792u: goto P_0c0ae792;
case 0x0c0ae794u: goto P_0c0ae794;
case 0x0c0ae796u: goto P_0c0ae796;
case 0x0c0ae798u: goto P_0c0ae798;
case 0x0c0ae79au: goto P_0c0ae79a;
case 0x0c0ae79cu: goto P_0c0ae79c;
case 0x0c0ae79eu: goto P_0c0ae79e;
case 0x0c0ae7a0u: goto P_0c0ae7a0;
case 0x0c0ae7a2u: goto P_0c0ae7a2;
case 0x0c0ae7a4u: goto P_0c0ae7a4;
case 0x0c0ae7a6u: goto P_0c0ae7a6;
case 0x0c0ae7a8u: goto P_0c0ae7a8;
case 0x0c0ae7aau: goto P_0c0ae7aa;
case 0x0c0af728u: goto P_0c0af728;
case 0x0c0af72au: goto P_0c0af72a;
case 0x0c0af72cu: goto P_0c0af72c;
case 0x0c0af72eu: goto P_0c0af72e;
case 0x0c0af730u: goto P_0c0af730;
case 0x0c0af732u: goto P_0c0af732;
case 0x0c0af734u: goto P_0c0af734;
case 0x0c0af736u: goto P_0c0af736;
case 0x0c0af738u: goto P_0c0af738;
case 0x0c0af73au: goto P_0c0af73a;
case 0x0c0af73cu: goto P_0c0af73c;
case 0x0c0af73eu: goto P_0c0af73e;
case 0x0c0af740u: goto P_0c0af740;
case 0x0c0af742u: goto P_0c0af742;
case 0x0c0af744u: goto P_0c0af744;
case 0x0c0af746u: goto P_0c0af746;
case 0x0c0af748u: goto P_0c0af748;
case 0x0c0af74au: goto P_0c0af74a;
case 0x0c0af74cu: goto P_0c0af74c;
case 0x0c0af74eu: goto P_0c0af74e;
case 0x0c0af750u: goto P_0c0af750;
case 0x0c0af752u: goto P_0c0af752;
case 0x0c0af754u: goto P_0c0af754;
case 0x0c0af756u: goto P_0c0af756;
case 0x0c0af758u: goto P_0c0af758;
case 0x0c0af75au: goto P_0c0af75a;
case 0x0c0af75cu: goto P_0c0af75c;
case 0x0c0af75eu: goto P_0c0af75e;
case 0x0c0af760u: goto P_0c0af760;
case 0x0c0af762u: goto P_0c0af762;
case 0x0c0af764u: goto P_0c0af764;
case 0x0c0af766u: goto P_0c0af766;
case 0x0c0af768u: goto P_0c0af768;
case 0x0c0af76au: goto P_0c0af76a;
case 0x0c0af76cu: goto P_0c0af76c;
case 0x0c0af76eu: goto P_0c0af76e;
case 0x0c0af770u: goto P_0c0af770;
case 0x0c0af772u: goto P_0c0af772;
case 0x0c0af774u: goto P_0c0af774;
case 0x0c0af776u: goto P_0c0af776;
case 0x0c0af778u: goto P_0c0af778;
case 0x0c0af77au: goto P_0c0af77a;
case 0x0c0af77cu: goto P_0c0af77c;
case 0x0c0af77eu: goto P_0c0af77e;
case 0x0c0af780u: goto P_0c0af780;
case 0x0c0af782u: goto P_0c0af782;
case 0x0c0af784u: goto P_0c0af784;
case 0x0c0af786u: goto P_0c0af786;
case 0x0c0af788u: goto P_0c0af788;
case 0x0c0af78au: goto P_0c0af78a;
case 0x0c0af78cu: goto P_0c0af78c;
case 0x0c0af78eu: goto P_0c0af78e;
case 0x0c0af790u: goto P_0c0af790;
case 0x0c0af792u: goto P_0c0af792;
case 0x0c0af794u: goto P_0c0af794;
case 0x0c0af796u: goto P_0c0af796;
case 0x0c0af798u: goto P_0c0af798;
case 0x0c0af79au: goto P_0c0af79a;
case 0x0c0af79cu: goto P_0c0af79c;
case 0x0c0af79eu: goto P_0c0af79e;
case 0x0c0af7a0u: goto P_0c0af7a0;
case 0x0c0af7a2u: goto P_0c0af7a2;
case 0x0c0af7a4u: goto P_0c0af7a4;
case 0x0c0af7a6u: goto P_0c0af7a6;
case 0x0c0af7a8u: goto P_0c0af7a8;
case 0x0c0af7aau: goto P_0c0af7aa;
case 0x0c0af7acu: goto P_0c0af7ac;
case 0x0c0af7aeu: goto P_0c0af7ae;
case 0x0c0af7b0u: goto P_0c0af7b0;
case 0x0c0af7b2u: goto P_0c0af7b2;
case 0x0c0af7b4u: goto P_0c0af7b4;
case 0x0c0af7b6u: goto P_0c0af7b6;
case 0x0c0af7b8u: goto P_0c0af7b8;
case 0x0c0af7bau: goto P_0c0af7ba;
case 0x0c0af7bcu: goto P_0c0af7bc;
case 0x0c0af7beu: goto P_0c0af7be;
case 0x0c0af7c0u: goto P_0c0af7c0;
case 0x0c0af7c2u: goto P_0c0af7c2;
case 0x0c0af7c4u: goto P_0c0af7c4;
case 0x0c0af7c6u: goto P_0c0af7c6;
case 0x0c0af7c8u: goto P_0c0af7c8;
case 0x0c0af7cau: goto P_0c0af7ca;
case 0x0c0af7ccu: goto P_0c0af7cc;
case 0x0c0af7ceu: goto P_0c0af7ce;
case 0x0c0af7d0u: goto P_0c0af7d0;
case 0x0c0af7d2u: goto P_0c0af7d2;
case 0x0c0af7d4u: goto P_0c0af7d4;
case 0x0c0af7d6u: goto P_0c0af7d6;
case 0x0c0af7d8u: goto P_0c0af7d8;
case 0x0c0af7dau: goto P_0c0af7da;
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
P_0c042c1e: /* original 4f22, guest PC 0x0c042c1e */
if(!s->budget--) { s->failed_pc=0x0c042c1eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c042c20;
P_0c042c20: /* original 2008, guest PC 0x0c042c20 */
if(!s->budget--) { s->failed_pc=0x0c042c20u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c042c22;
P_0c042c22: /* original 2f26, guest PC 0x0c042c22 */
if(!s->budget--) { s->failed_pc=0x0c042c22u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042c24;
P_0c042c24: /* original 8d4c, guest PC 0x0c042c24 */
if(!s->budget--) { s->failed_pc=0x0c042c24u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042cc0; }
goto P_0c042c28;
P_0c042c26: /* original 0009, guest PC 0x0c042c26 */
if(!s->budget--) { s->failed_pc=0x0c042c26u; return 0; }
goto P_0c042c28;
P_0c042c28: /* original 2f36, guest PC 0x0c042c28 */
if(!s->budget--) { s->failed_pc=0x0c042c28u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042c2a;
P_0c042c2a: /* original e200, guest PC 0x0c042c2a */
if(!s->budget--) { s->failed_pc=0x0c042c2au; return 0; }
r[2]=0x00000000u;
goto P_0c042c2c;
P_0c042c2c: /* original 2127, guest PC 0x0c042c2c */
if(!s->budget--) { s->failed_pc=0x0c042c2cu; return 0; }
r[17]=(r[17]&~0x301u)|((r[1]>>31)<<8)|((r[2]>>31)<<9)|(((r[1]^r[2])>>31)&1u);
goto P_0c042c2e;
P_0c042c2e: /* original 333a, guest PC 0x0c042c2e */
if(!s->budget--) { s->failed_pc=0x0c042c2eu; return 0; }
wide=(uint64_t)r[3]-r[3]-(r[17]&1u); r[3]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042c30;
P_0c042c30: /* original 312a, guest PC 0x0c042c30 */
if(!s->budget--) { s->failed_pc=0x0c042c30u; return 0; }
wide=(uint64_t)r[1]-r[2]-(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042c32;
P_0c042c32: /* original 2307, guest PC 0x0c042c32 */
if(!s->budget--) { s->failed_pc=0x0c042c32u; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[0]>>31)<<9)|(((r[3]^r[0])>>31)&1u);
goto P_0c042c34;
P_0c042c34: /* original 4124, guest PC 0x0c042c34 */
if(!s->budget--) { s->failed_pc=0x0c042c34u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c36;
P_0c042c36: /* original 3304, guest PC 0x0c042c36 */
if(!s->budget--) { s->failed_pc=0x0c042c36u; return 0; }
divide_step(s,3,0);
goto P_0c042c38;
P_0c042c38: /* original 4124, guest PC 0x0c042c38 */
if(!s->budget--) { s->failed_pc=0x0c042c38u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c3a;
P_0c042c3a: /* original 3304, guest PC 0x0c042c3a */
if(!s->budget--) { s->failed_pc=0x0c042c3au; return 0; }
divide_step(s,3,0);
goto P_0c042c3c;
P_0c042c3c: /* original 4124, guest PC 0x0c042c3c */
if(!s->budget--) { s->failed_pc=0x0c042c3cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c3e;
P_0c042c3e: /* original 3304, guest PC 0x0c042c3e */
if(!s->budget--) { s->failed_pc=0x0c042c3eu; return 0; }
divide_step(s,3,0);
goto P_0c042c40;
P_0c042c40: /* original 4124, guest PC 0x0c042c40 */
if(!s->budget--) { s->failed_pc=0x0c042c40u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c42;
P_0c042c42: /* original 3304, guest PC 0x0c042c42 */
if(!s->budget--) { s->failed_pc=0x0c042c42u; return 0; }
divide_step(s,3,0);
goto P_0c042c44;
P_0c042c44: /* original 4124, guest PC 0x0c042c44 */
if(!s->budget--) { s->failed_pc=0x0c042c44u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c46;
P_0c042c46: /* original 3304, guest PC 0x0c042c46 */
if(!s->budget--) { s->failed_pc=0x0c042c46u; return 0; }
divide_step(s,3,0);
goto P_0c042c48;
P_0c042c48: /* original 4124, guest PC 0x0c042c48 */
if(!s->budget--) { s->failed_pc=0x0c042c48u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c4a;
P_0c042c4a: /* original 3304, guest PC 0x0c042c4a */
if(!s->budget--) { s->failed_pc=0x0c042c4au; return 0; }
divide_step(s,3,0);
goto P_0c042c4c;
P_0c042c4c: /* original 4124, guest PC 0x0c042c4c */
if(!s->budget--) { s->failed_pc=0x0c042c4cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c4e;
P_0c042c4e: /* original 3304, guest PC 0x0c042c4e */
if(!s->budget--) { s->failed_pc=0x0c042c4eu; return 0; }
divide_step(s,3,0);
goto P_0c042c50;
P_0c042c50: /* original 4124, guest PC 0x0c042c50 */
if(!s->budget--) { s->failed_pc=0x0c042c50u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c52;
P_0c042c52: /* original 3304, guest PC 0x0c042c52 */
if(!s->budget--) { s->failed_pc=0x0c042c52u; return 0; }
divide_step(s,3,0);
goto P_0c042c54;
P_0c042c54: /* original 4124, guest PC 0x0c042c54 */
if(!s->budget--) { s->failed_pc=0x0c042c54u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c56;
P_0c042c56: /* original 3304, guest PC 0x0c042c56 */
if(!s->budget--) { s->failed_pc=0x0c042c56u; return 0; }
divide_step(s,3,0);
goto P_0c042c58;
P_0c042c58: /* original 4124, guest PC 0x0c042c58 */
if(!s->budget--) { s->failed_pc=0x0c042c58u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c5a;
P_0c042c5a: /* original 3304, guest PC 0x0c042c5a */
if(!s->budget--) { s->failed_pc=0x0c042c5au; return 0; }
divide_step(s,3,0);
goto P_0c042c5c;
P_0c042c5c: /* original 4124, guest PC 0x0c042c5c */
if(!s->budget--) { s->failed_pc=0x0c042c5cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c5e;
P_0c042c5e: /* original 3304, guest PC 0x0c042c5e */
if(!s->budget--) { s->failed_pc=0x0c042c5eu; return 0; }
divide_step(s,3,0);
goto P_0c042c60;
P_0c042c60: /* original 4124, guest PC 0x0c042c60 */
if(!s->budget--) { s->failed_pc=0x0c042c60u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c62;
P_0c042c62: /* original 3304, guest PC 0x0c042c62 */
if(!s->budget--) { s->failed_pc=0x0c042c62u; return 0; }
divide_step(s,3,0);
goto P_0c042c64;
P_0c042c64: /* original 4124, guest PC 0x0c042c64 */
if(!s->budget--) { s->failed_pc=0x0c042c64u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c66;
P_0c042c66: /* original 3304, guest PC 0x0c042c66 */
if(!s->budget--) { s->failed_pc=0x0c042c66u; return 0; }
divide_step(s,3,0);
goto P_0c042c68;
P_0c042c68: /* original 4124, guest PC 0x0c042c68 */
if(!s->budget--) { s->failed_pc=0x0c042c68u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c6a;
P_0c042c6a: /* original 3304, guest PC 0x0c042c6a */
if(!s->budget--) { s->failed_pc=0x0c042c6au; return 0; }
divide_step(s,3,0);
goto P_0c042c6c;
P_0c042c6c: /* original 4124, guest PC 0x0c042c6c */
if(!s->budget--) { s->failed_pc=0x0c042c6cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c6e;
P_0c042c6e: /* original 3304, guest PC 0x0c042c6e */
if(!s->budget--) { s->failed_pc=0x0c042c6eu; return 0; }
divide_step(s,3,0);
goto P_0c042c70;
P_0c042c70: /* original 4124, guest PC 0x0c042c70 */
if(!s->budget--) { s->failed_pc=0x0c042c70u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c72;
P_0c042c72: /* original 3304, guest PC 0x0c042c72 */
if(!s->budget--) { s->failed_pc=0x0c042c72u; return 0; }
divide_step(s,3,0);
goto P_0c042c74;
P_0c042c74: /* original 4124, guest PC 0x0c042c74 */
if(!s->budget--) { s->failed_pc=0x0c042c74u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c76;
P_0c042c76: /* original 3304, guest PC 0x0c042c76 */
if(!s->budget--) { s->failed_pc=0x0c042c76u; return 0; }
divide_step(s,3,0);
goto P_0c042c78;
P_0c042c78: /* original 4124, guest PC 0x0c042c78 */
if(!s->budget--) { s->failed_pc=0x0c042c78u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c7a;
P_0c042c7a: /* original 3304, guest PC 0x0c042c7a */
if(!s->budget--) { s->failed_pc=0x0c042c7au; return 0; }
divide_step(s,3,0);
goto P_0c042c7c;
P_0c042c7c: /* original 4124, guest PC 0x0c042c7c */
if(!s->budget--) { s->failed_pc=0x0c042c7cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c7e;
P_0c042c7e: /* original 3304, guest PC 0x0c042c7e */
if(!s->budget--) { s->failed_pc=0x0c042c7eu; return 0; }
divide_step(s,3,0);
goto P_0c042c80;
P_0c042c80: /* original 4124, guest PC 0x0c042c80 */
if(!s->budget--) { s->failed_pc=0x0c042c80u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c82;
P_0c042c82: /* original 3304, guest PC 0x0c042c82 */
if(!s->budget--) { s->failed_pc=0x0c042c82u; return 0; }
divide_step(s,3,0);
goto P_0c042c84;
P_0c042c84: /* original 4124, guest PC 0x0c042c84 */
if(!s->budget--) { s->failed_pc=0x0c042c84u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c86;
P_0c042c86: /* original 3304, guest PC 0x0c042c86 */
if(!s->budget--) { s->failed_pc=0x0c042c86u; return 0; }
divide_step(s,3,0);
goto P_0c042c88;
P_0c042c88: /* original 4124, guest PC 0x0c042c88 */
if(!s->budget--) { s->failed_pc=0x0c042c88u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c8a;
P_0c042c8a: /* original 3304, guest PC 0x0c042c8a */
if(!s->budget--) { s->failed_pc=0x0c042c8au; return 0; }
divide_step(s,3,0);
goto P_0c042c8c;
P_0c042c8c: /* original 4124, guest PC 0x0c042c8c */
if(!s->budget--) { s->failed_pc=0x0c042c8cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c8e;
P_0c042c8e: /* original 3304, guest PC 0x0c042c8e */
if(!s->budget--) { s->failed_pc=0x0c042c8eu; return 0; }
divide_step(s,3,0);
goto P_0c042c90;
P_0c042c90: /* original 4124, guest PC 0x0c042c90 */
if(!s->budget--) { s->failed_pc=0x0c042c90u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c92;
P_0c042c92: /* original 3304, guest PC 0x0c042c92 */
if(!s->budget--) { s->failed_pc=0x0c042c92u; return 0; }
divide_step(s,3,0);
goto P_0c042c94;
P_0c042c94: /* original 4124, guest PC 0x0c042c94 */
if(!s->budget--) { s->failed_pc=0x0c042c94u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c96;
P_0c042c96: /* original 3304, guest PC 0x0c042c96 */
if(!s->budget--) { s->failed_pc=0x0c042c96u; return 0; }
divide_step(s,3,0);
goto P_0c042c98;
P_0c042c98: /* original 4124, guest PC 0x0c042c98 */
if(!s->budget--) { s->failed_pc=0x0c042c98u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c9a;
P_0c042c9a: /* original 3304, guest PC 0x0c042c9a */
if(!s->budget--) { s->failed_pc=0x0c042c9au; return 0; }
divide_step(s,3,0);
goto P_0c042c9c;
P_0c042c9c: /* original 4124, guest PC 0x0c042c9c */
if(!s->budget--) { s->failed_pc=0x0c042c9cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c9e;
P_0c042c9e: /* original 3304, guest PC 0x0c042c9e */
if(!s->budget--) { s->failed_pc=0x0c042c9eu; return 0; }
divide_step(s,3,0);
goto P_0c042ca0;
P_0c042ca0: /* original 4124, guest PC 0x0c042ca0 */
if(!s->budget--) { s->failed_pc=0x0c042ca0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ca2;
P_0c042ca2: /* original 3304, guest PC 0x0c042ca2 */
if(!s->budget--) { s->failed_pc=0x0c042ca2u; return 0; }
divide_step(s,3,0);
goto P_0c042ca4;
P_0c042ca4: /* original 4124, guest PC 0x0c042ca4 */
if(!s->budget--) { s->failed_pc=0x0c042ca4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ca6;
P_0c042ca6: /* original 3304, guest PC 0x0c042ca6 */
if(!s->budget--) { s->failed_pc=0x0c042ca6u; return 0; }
divide_step(s,3,0);
goto P_0c042ca8;
P_0c042ca8: /* original 4124, guest PC 0x0c042ca8 */
if(!s->budget--) { s->failed_pc=0x0c042ca8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042caa;
P_0c042caa: /* original 3304, guest PC 0x0c042caa */
if(!s->budget--) { s->failed_pc=0x0c042caau; return 0; }
divide_step(s,3,0);
goto P_0c042cac;
P_0c042cac: /* original 4124, guest PC 0x0c042cac */
if(!s->budget--) { s->failed_pc=0x0c042cacu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cae;
P_0c042cae: /* original 3304, guest PC 0x0c042cae */
if(!s->budget--) { s->failed_pc=0x0c042caeu; return 0; }
divide_step(s,3,0);
goto P_0c042cb0;
P_0c042cb0: /* original 4124, guest PC 0x0c042cb0 */
if(!s->budget--) { s->failed_pc=0x0c042cb0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cb2;
P_0c042cb2: /* original 3304, guest PC 0x0c042cb2 */
if(!s->budget--) { s->failed_pc=0x0c042cb2u; return 0; }
divide_step(s,3,0);
goto P_0c042cb4;
P_0c042cb4: /* original 4124, guest PC 0x0c042cb4 */
if(!s->budget--) { s->failed_pc=0x0c042cb4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cb6;
P_0c042cb6: /* original 312e, guest PC 0x0c042cb6 */
if(!s->budget--) { s->failed_pc=0x0c042cb6u; return 0; }
wide=(uint64_t)r[1]+r[2]+(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042cb8;
P_0c042cb8: /* original 6013, guest PC 0x0c042cb8 */
if(!s->budget--) { s->failed_pc=0x0c042cb8u; return 0; }
r[0]=r[1];
goto P_0c042cba;
P_0c042cba: /* original 63f6, guest PC 0x0c042cba */
if(!s->budget--) { s->failed_pc=0x0c042cbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042cbc;
P_0c042cbc: /* original 000b, guest PC 0x0c042cbc */
if(!s->budget--) { s->failed_pc=0x0c042cbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042cbe: /* original 62f6, guest PC 0x0c042cbe */
if(!s->budget--) { s->failed_pc=0x0c042cbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c042cc0;
P_0c042cc0: /* original d102, guest PC 0x0c042cc0 */
if(!s->budget--) { s->failed_pc=0x0c042cc0u; return 0; }
r[1]=read(ram,0x0c042cccu,4);
goto P_0c042cc2;
P_0c042cc2: /* original d203, guest PC 0x0c042cc2 */
if(!s->budget--) { s->failed_pc=0x0c042cc2u; return 0; }
r[2]=read(ram,0x0c042cd0u,4);
goto P_0c042cc4;
P_0c042cc4: /* original e000, guest PC 0x0c042cc4 */
if(!s->budget--) { s->failed_pc=0x0c042cc4u; return 0; }
r[0]=0x00000000u;
goto P_0c042cc6;
P_0c042cc6: /* original 2122, guest PC 0x0c042cc6 */
if(!s->budget--) { s->failed_pc=0x0c042cc6u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c042cc8;
P_0c042cc8: /* original 000b, guest PC 0x0c042cc8 */
if(!s->budget--) { s->failed_pc=0x0c042cc8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042cca: /* original 62f6, guest PC 0x0c042cca */
if(!s->budget--) { s->failed_pc=0x0c042ccau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042cccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042cccu; return 0; } return 1;
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
case 0x0c0af728u: goto P_0c0af728;
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
P_0c0ae5a0: /* original 2fe6, guest PC 0x0c0ae5a0 */
if(!s->budget--) { s->failed_pc=0x0c0ae5a0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae5a2;
P_0c0ae5a2: /* original 6e43, guest PC 0x0c0ae5a2 */
if(!s->budget--) { s->failed_pc=0x0c0ae5a2u; return 0; }
r[14]=r[4];
goto P_0c0ae5a4;
P_0c0ae5a4: /* original 2fd6, guest PC 0x0c0ae5a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae5a4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae5a6;
P_0c0ae5a6: /* original 2fc6, guest PC 0x0c0ae5a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae5a6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae5a8;
P_0c0ae5a8: /* original 6c53, guest PC 0x0c0ae5a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae5a8u; return 0; }
r[12]=r[5];
goto P_0c0ae5aa;
P_0c0ae5aa: /* original 2fb6, guest PC 0x0c0ae5aa */
if(!s->budget--) { s->failed_pc=0x0c0ae5aau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae5ac;
P_0c0ae5ac: /* original 2fa6, guest PC 0x0c0ae5ac */
if(!s->budget--) { s->failed_pc=0x0c0ae5acu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae5ae;
P_0c0ae5ae: /* original 2f96, guest PC 0x0c0ae5ae */
if(!s->budget--) { s->failed_pc=0x0c0ae5aeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae5b0;
P_0c0ae5b0: /* original 4f22, guest PC 0x0c0ae5b0 */
if(!s->budget--) { s->failed_pc=0x0c0ae5b0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ae5b2;
P_0c0ae5b2: /* original d444, guest PC 0x0c0ae5b2 */
if(!s->budget--) { s->failed_pc=0x0c0ae5b2u; return 0; }
r[4]=read(ram,0x0c0ae6c4u,4);
goto P_0c0ae5b4;
P_0c0ae5b4: /* original d942, guest PC 0x0c0ae5b4 */
if(!s->budget--) { s->failed_pc=0x0c0ae5b4u; return 0; }
r[9]=read(ram,0x0c0ae6c0u,4);
goto P_0c0ae5b6;
P_0c0ae5b6: /* original 5345, guest PC 0x0c0ae5b6 */
if(!s->budget--) { s->failed_pc=0x0c0ae5b6u; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c0ae5b8;
P_0c0ae5b8: /* original 4f12, guest PC 0x0c0ae5b8 */
if(!s->budget--) { s->failed_pc=0x0c0ae5b8u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0ae5ba;
P_0c0ae5ba: /* original 4315, guest PC 0x0c0ae5ba */
if(!s->budget--) { s->failed_pc=0x0c0ae5bau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c0ae5bc;
P_0c0ae5bc: /* original 8f68, guest PC 0x0c0ae5bc */
if(!s->budget--) { s->failed_pc=0x0c0ae5bcu; return 0; }
cond=r[17]&1u;
r[10]=r[6];
if(!cond) { goto P_0c0ae690; }
goto P_0c0ae5c0;
P_0c0ae5be: /* original 6a63, guest PC 0x0c0ae5be */
if(!s->budget--) { s->failed_pc=0x0c0ae5beu; return 0; }
r[10]=r[6];
goto P_0c0ae5c0;
P_0c0ae5c0: /* original 9075, guest PC 0x0c0ae5c0 */
if(!s->budget--) { s->failed_pc=0x0c0ae5c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6aeu,2);
goto P_0c0ae5c2;
P_0c0ae5c2: /* original 5ba2, guest PC 0x0c0ae5c2 */
if(!s->budget--) { s->failed_pc=0x0c0ae5c2u; return 0; }
r[11]=read(ram,r[10]+8,4);
goto P_0c0ae5c4;
P_0c0ae5c4: /* original 03cc, guest PC 0x0c0ae5c4 */
if(!s->budget--) { s->failed_pc=0x0c0ae5c4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0ae5c6;
P_0c0ae5c6: /* original e064, guest PC 0x0c0ae5c6 */
if(!s->budget--) { s->failed_pc=0x0c0ae5c6u; return 0; }
r[0]=0x00000064u;
goto P_0c0ae5c8;
P_0c0ae5c8: /* original 7b03, guest PC 0x0c0ae5c8 */
if(!s->budget--) { s->failed_pc=0x0c0ae5c8u; return 0; }
r[11]+=0x00000003u;
goto P_0c0ae5ca;
P_0c0ae5ca: /* original 6bb0, guest PC 0x0c0ae5ca */
if(!s->budget--) { s->failed_pc=0x0c0ae5cau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[11],1);
r[11]=tmp;
goto P_0c0ae5cc;
P_0c0ae5cc: /* original 633c, guest PC 0x0c0ae5cc */
if(!s->budget--) { s->failed_pc=0x0c0ae5ccu; return 0; }
r[3]=r[3]&255u;
goto P_0c0ae5ce;
P_0c0ae5ce: /* original 7364, guest PC 0x0c0ae5ce */
if(!s->budget--) { s->failed_pc=0x0c0ae5ceu; return 0; }
r[3]+=0x00000064u;
goto P_0c0ae5d0;
P_0c0ae5d0: /* original 6bbc, guest PC 0x0c0ae5d0 */
if(!s->budget--) { s->failed_pc=0x0c0ae5d0u; return 0; }
r[11]=r[11]&255u;
goto P_0c0ae5d2;
P_0c0ae5d2: /* original 0b37, guest PC 0x0c0ae5d2 */
if(!s->budget--) { s->failed_pc=0x0c0ae5d2u; return 0; }
r[19]=r[11]*r[3];
goto P_0c0ae5d4;
P_0c0ae5d4: /* original d33c, guest PC 0x0c0ae5d4 */
if(!s->budget--) { s->failed_pc=0x0c0ae5d4u; return 0; }
r[3]=read(ram,0x0c0ae6c8u,4);
goto P_0c0ae5d6;
P_0c0ae5d6: /* original 0b1a, guest PC 0x0c0ae5d6 */
if(!s->budget--) { s->failed_pc=0x0c0ae5d6u; return 0; }
r[11]=r[19];
goto P_0c0ae5d8;
P_0c0ae5d8: /* original 430b, guest PC 0x0c0ae5d8 */
if(!s->budget--) { s->failed_pc=0x0c0ae5d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0ae5dcu;
r[1]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ae5dcu) { target=s->pc; goto dispatch; }
goto P_0c0ae5dc;
P_0c0ae5da: /* original 61b3, guest PC 0x0c0ae5da */
if(!s->budget--) { s->failed_pc=0x0c0ae5dau; return 0; }
r[1]=r[11];
goto P_0c0ae5dc;
P_0c0ae5dc: /* original 6b03, guest PC 0x0c0ae5dc */
if(!s->budget--) { s->failed_pc=0x0c0ae5dcu; return 0; }
r[11]=r[0];
goto P_0c0ae5de;
P_0c0ae5de: /* original 9067, guest PC 0x0c0ae5de */
if(!s->budget--) { s->failed_pc=0x0c0ae5deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6b0u,2);
goto P_0c0ae5e0;
P_0c0ae5e0: /* original 65c3, guest PC 0x0c0ae5e0 */
if(!s->budget--) { s->failed_pc=0x0c0ae5e0u; return 0; }
r[5]=r[12];
goto P_0c0ae5e2;
P_0c0ae5e2: /* original 66b3, guest PC 0x0c0ae5e2 */
if(!s->budget--) { s->failed_pc=0x0c0ae5e2u; return 0; }
r[6]=r[11];
goto P_0c0ae5e4;
P_0c0ae5e4: /* original 04ed, guest PC 0x0c0ae5e4 */
if(!s->budget--) { s->failed_pc=0x0c0ae5e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ae5e6;
P_0c0ae5e6: /* original 34bc, guest PC 0x0c0ae5e6 */
if(!s->budget--) { s->failed_pc=0x0c0ae5e6u; return 0; }
r[4]+=r[11];
goto P_0c0ae5e8;
P_0c0ae5e8: /* original 0e45, guest PC 0x0c0ae5e8 */
if(!s->budget--) { s->failed_pc=0x0c0ae5e8u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0ae5ea;
P_0c0ae5ea: /* original d338, guest PC 0x0c0ae5ea */
if(!s->budget--) { s->failed_pc=0x0c0ae5eau; return 0; }
r[3]=read(ram,0x0c0ae6ccu,4);
goto P_0c0ae5ec;
P_0c0ae5ec: /* original 430b, guest PC 0x0c0ae5ec */
if(!s->budget--) { s->failed_pc=0x0c0ae5ecu; return 0; }
target=r[3];
r[16]=code_base|0x0c0ae5f0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ae5f0u) { target=s->pc; goto dispatch; }
goto P_0c0ae5f0;
P_0c0ae5ee: /* original 64e3, guest PC 0x0c0ae5ee */
if(!s->budget--) { s->failed_pc=0x0c0ae5eeu; return 0; }
r[4]=r[14];
goto P_0c0ae5f0;
P_0c0ae5f0: /* original 905f, guest PC 0x0c0ae5f0 */
if(!s->budget--) { s->failed_pc=0x0c0ae5f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6b2u,2);
goto P_0c0ae5f2;
P_0c0ae5f2: /* original e401, guest PC 0x0c0ae5f2 */
if(!s->budget--) { s->failed_pc=0x0c0ae5f2u; return 0; }
r[4]=0x00000001u;
goto P_0c0ae5f4;
P_0c0ae5f4: /* original 02ec, guest PC 0x0c0ae5f4 */
if(!s->budget--) { s->failed_pc=0x0c0ae5f4u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ae5f6;
P_0c0ae5f6: /* original 7201, guest PC 0x0c0ae5f6 */
if(!s->budget--) { s->failed_pc=0x0c0ae5f6u; return 0; }
r[2]+=0x00000001u;
goto P_0c0ae5f8;
P_0c0ae5f8: /* original 0e24, guest PC 0x0c0ae5f8 */
if(!s->budget--) { s->failed_pc=0x0c0ae5f8u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0ae5fa;
P_0c0ae5fa: /* original 905b, guest PC 0x0c0ae5fa */
if(!s->budget--) { s->failed_pc=0x0c0ae5fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6b4u,2);
goto P_0c0ae5fc;
P_0c0ae5fc: /* original 06ec, guest PC 0x0c0ae5fc */
if(!s->budget--) { s->failed_pc=0x0c0ae5fcu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ae5fe;
P_0c0ae5fe: /* original 905a, guest PC 0x0c0ae5fe */
if(!s->budget--) { s->failed_pc=0x0c0ae5feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6b6u,2);
goto P_0c0ae600;
P_0c0ae600: /* original 666c, guest PC 0x0c0ae600 */
if(!s->budget--) { s->failed_pc=0x0c0ae600u; return 0; }
r[6]=r[6]&255u;
goto P_0c0ae602;
P_0c0ae602: /* original 05ec, guest PC 0x0c0ae602 */
if(!s->budget--) { s->failed_pc=0x0c0ae602u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ae604;
P_0c0ae604: /* original 3643, guest PC 0x0c0ae604 */
if(!s->budget--) { s->failed_pc=0x0c0ae604u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[4])!=0);
goto P_0c0ae606;
P_0c0ae606: /* original 655c, guest PC 0x0c0ae606 */
if(!s->budget--) { s->failed_pc=0x0c0ae606u; return 0; }
r[5]=r[5]&255u;
goto P_0c0ae608;
P_0c0ae608: /* original 8d02, guest PC 0x0c0ae608 */
if(!s->budget--) { s->failed_pc=0x0c0ae608u; return 0; }
cond=r[17]&1u;
r[13]=r[11];
if(cond) { goto P_0c0ae610; }
goto P_0c0ae60c;
P_0c0ae60a: /* original 6db3, guest PC 0x0c0ae60a */
if(!s->budget--) { s->failed_pc=0x0c0ae60au; return 0; }
r[13]=r[11];
goto P_0c0ae60c;
P_0c0ae60c: /* original 3543, guest PC 0x0c0ae60c */
if(!s->budget--) { s->failed_pc=0x0c0ae60cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[4])!=0);
goto P_0c0ae60e;
P_0c0ae60e: /* original 8b03, guest PC 0x0c0ae60e */
if(!s->budget--) { s->failed_pc=0x0c0ae60eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae618; }
goto P_0c0ae610;
P_0c0ae610: /* original 9052, guest PC 0x0c0ae610 */
if(!s->budget--) { s->failed_pc=0x0c0ae610u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6b8u,2);
goto P_0c0ae612;
P_0c0ae612: /* original 0dcd, guest PC 0x0c0ae612 */
if(!s->budget--) { s->failed_pc=0x0c0ae612u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0ae614;
P_0c0ae614: /* original 6ddd, guest PC 0x0c0ae614 */
if(!s->budget--) { s->failed_pc=0x0c0ae614u; return 0; }
r[13]=r[13]&65535u;
goto P_0c0ae616;
P_0c0ae616: /* original 3dbc, guest PC 0x0c0ae616 */
if(!s->budget--) { s->failed_pc=0x0c0ae616u; return 0; }
r[13]+=r[11];
goto P_0c0ae618;
P_0c0ae618: /* original 904e, guest PC 0x0c0ae618 */
if(!s->budget--) { s->failed_pc=0x0c0ae618u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6b8u,2);
goto P_0c0ae61a;
P_0c0ae61a: /* original 0cd5, guest PC 0x0c0ae61a */
if(!s->budget--) { s->failed_pc=0x0c0ae61au; return 0; }
write(ram,r[12]+r[0],r[13],2);
goto P_0c0ae61c;
P_0c0ae61c: /* original 6492, guest PC 0x0c0ae61c */
if(!s->budget--) { s->failed_pc=0x0c0ae61cu; return 0; }
tmp=read(ram,r[9],4);
r[4]=tmp;
goto P_0c0ae61e;
P_0c0ae61e: /* original 934c, guest PC 0x0c0ae61e */
if(!s->budget--) { s->failed_pc=0x0c0ae61eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6bau,2);
goto P_0c0ae620;
P_0c0ae620: /* original 2348, guest PC 0x0c0ae620 */
if(!s->budget--) { s->failed_pc=0x0c0ae620u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0ae622;
P_0c0ae622: /* original 8f06, guest PC 0x0c0ae622 */
if(!s->budget--) { s->failed_pc=0x0c0ae622u; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[9]+4,4);
if(!cond) { goto P_0c0ae632; }
goto P_0c0ae626;
P_0c0ae624: /* original 5591, guest PC 0x0c0ae624 */
if(!s->budget--) { s->failed_pc=0x0c0ae624u; return 0; }
r[5]=read(ram,r[9]+4,4);
goto P_0c0ae626;
P_0c0ae626: /* original d22a, guest PC 0x0c0ae626 */
if(!s->budget--) { s->failed_pc=0x0c0ae626u; return 0; }
r[2]=read(ram,0x0c0ae6d0u,4);
goto P_0c0ae628;
P_0c0ae628: /* original 2428, guest PC 0x0c0ae628 */
if(!s->budget--) { s->failed_pc=0x0c0ae628u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0ae62a;
P_0c0ae62a: /* original 8931, guest PC 0x0c0ae62a */
if(!s->budget--) { s->failed_pc=0x0c0ae62au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae690; }
goto P_0c0ae62c;
P_0c0ae62c: /* original d329, guest PC 0x0c0ae62c */
if(!s->budget--) { s->failed_pc=0x0c0ae62cu; return 0; }
r[3]=read(ram,0x0c0ae6d4u,4);
goto P_0c0ae62e;
P_0c0ae62e: /* original 2538, guest PC 0x0c0ae62e */
if(!s->budget--) { s->failed_pc=0x0c0ae62eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0ae630;
P_0c0ae630: /* original 892e, guest PC 0x0c0ae630 */
if(!s->budget--) { s->failed_pc=0x0c0ae630u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae690; }
goto P_0c0ae632;
P_0c0ae632: /* original d229, guest PC 0x0c0ae632 */
if(!s->budget--) { s->failed_pc=0x0c0ae632u; return 0; }
r[2]=read(ram,0x0c0ae6d8u,4);
goto P_0c0ae634;
P_0c0ae634: /* original 6020, guest PC 0x0c0ae634 */
if(!s->budget--) { s->failed_pc=0x0c0ae634u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[0]=tmp;
goto P_0c0ae636;
P_0c0ae636: /* original 600c, guest PC 0x0c0ae636 */
if(!s->budget--) { s->failed_pc=0x0c0ae636u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae638;
P_0c0ae638: /* original 8803, guest PC 0x0c0ae638 */
if(!s->budget--) { s->failed_pc=0x0c0ae638u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0ae63a;
P_0c0ae63a: /* original 8b29, guest PC 0x0c0ae63a */
if(!s->budget--) { s->failed_pc=0x0c0ae63au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae690; }
goto P_0c0ae63c;
P_0c0ae63c: /* original e061, guest PC 0x0c0ae63c */
if(!s->budget--) { s->failed_pc=0x0c0ae63cu; return 0; }
r[0]=0x00000061u;
goto P_0c0ae63e;
P_0c0ae63e: /* original db27, guest PC 0x0c0ae63e */
if(!s->budget--) { s->failed_pc=0x0c0ae63eu; return 0; }
r[11]=read(ram,0x0c0ae6dcu,4);
goto P_0c0ae640;
P_0c0ae640: /* original 04cc, guest PC 0x0c0ae640 */
if(!s->budget--) { s->failed_pc=0x0c0ae640u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0ae642;
P_0c0ae642: /* original 933b, guest PC 0x0c0ae642 */
if(!s->budget--) { s->failed_pc=0x0c0ae642u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6bcu,2);
goto P_0c0ae644;
P_0c0ae644: /* original 694c, guest PC 0x0c0ae644 */
if(!s->budget--) { s->failed_pc=0x0c0ae644u; return 0; }
r[9]=r[4]&255u;
goto P_0c0ae646;
P_0c0ae646: /* original d126, guest PC 0x0c0ae646 */
if(!s->budget--) { s->failed_pc=0x0c0ae646u; return 0; }
r[1]=read(ram,0x0c0ae6e0u,4);
goto P_0c0ae648;
P_0c0ae648: /* original 33bc, guest PC 0x0c0ae648 */
if(!s->budget--) { s->failed_pc=0x0c0ae648u; return 0; }
r[3]+=r[11];
goto P_0c0ae64a;
P_0c0ae64a: /* original 4908, guest PC 0x0c0ae64a */
if(!s->budget--) { s->failed_pc=0x0c0ae64au; return 0; }
r[9]<<=2;
goto P_0c0ae64c;
P_0c0ae64c: /* original 393c, guest PC 0x0c0ae64c */
if(!s->budget--) { s->failed_pc=0x0c0ae64cu; return 0; }
r[9]+=r[3];
goto P_0c0ae64e;
P_0c0ae64e: /* original 410b, guest PC 0x0c0ae64e */
if(!s->budget--) { s->failed_pc=0x0c0ae64eu; return 0; }
target=r[1];
r[16]=code_base|0x0c0ae652u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ae652u) { target=s->pc; goto dispatch; }
goto P_0c0ae652;
P_0c0ae650: /* original 6493, guest PC 0x0c0ae650 */
if(!s->budget--) { s->failed_pc=0x0c0ae650u; return 0; }
r[4]=r[9];
goto P_0c0ae652;
P_0c0ae652: /* original 6403, guest PC 0x0c0ae652 */
if(!s->budget--) { s->failed_pc=0x0c0ae652u; return 0; }
r[4]=r[0];
goto P_0c0ae654;
P_0c0ae654: /* original 34d3, guest PC 0x0c0ae654 */
if(!s->budget--) { s->failed_pc=0x0c0ae654u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[13])!=0);
goto P_0c0ae656;
P_0c0ae656: /* original 8903, guest PC 0x0c0ae656 */
if(!s->budget--) { s->failed_pc=0x0c0ae656u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae660; }
goto P_0c0ae658;
P_0c0ae658: /* original d322, guest PC 0x0c0ae658 */
if(!s->budget--) { s->failed_pc=0x0c0ae658u; return 0; }
r[3]=read(ram,0x0c0ae6e4u,4);
goto P_0c0ae65a;
P_0c0ae65a: /* original 65d3, guest PC 0x0c0ae65a */
if(!s->budget--) { s->failed_pc=0x0c0ae65au; return 0; }
r[5]=r[13];
goto P_0c0ae65c;
P_0c0ae65c: /* original 430b, guest PC 0x0c0ae65c */
if(!s->budget--) { s->failed_pc=0x0c0ae65cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0ae660u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ae660u) { target=s->pc; goto dispatch; }
goto P_0c0ae660;
P_0c0ae65e: /* original 6493, guest PC 0x0c0ae65e */
if(!s->budget--) { s->failed_pc=0x0c0ae65eu; return 0; }
r[4]=r[9];
goto P_0c0ae660;
P_0c0ae660: /* original 9028, guest PC 0x0c0ae660 */
if(!s->budget--) { s->failed_pc=0x0c0ae660u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6b4u,2);
goto P_0c0ae662;
P_0c0ae662: /* original 922c, guest PC 0x0c0ae662 */
if(!s->budget--) { s->failed_pc=0x0c0ae662u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6beu,2);
goto P_0c0ae664;
P_0c0ae664: /* original 0dec, guest PC 0x0c0ae664 */
if(!s->budget--) { s->failed_pc=0x0c0ae664u; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ae666;
P_0c0ae666: /* original 9026, guest PC 0x0c0ae666 */
if(!s->budget--) { s->failed_pc=0x0c0ae666u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6b6u,2);
goto P_0c0ae668;
P_0c0ae668: /* original 3b2c, guest PC 0x0c0ae668 */
if(!s->budget--) { s->failed_pc=0x0c0ae668u; return 0; }
r[11]+=r[2];
goto P_0c0ae66a;
P_0c0ae66a: /* original 6ddc, guest PC 0x0c0ae66a */
if(!s->budget--) { s->failed_pc=0x0c0ae66au; return 0; }
r[13]=r[13]&255u;
goto P_0c0ae66c;
P_0c0ae66c: /* original 04ec, guest PC 0x0c0ae66c */
if(!s->budget--) { s->failed_pc=0x0c0ae66cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ae66e;
P_0c0ae66e: /* original e061, guest PC 0x0c0ae66e */
if(!s->budget--) { s->failed_pc=0x0c0ae66eu; return 0; }
r[0]=0x00000061u;
goto P_0c0ae670;
P_0c0ae670: /* original 03cc, guest PC 0x0c0ae670 */
if(!s->budget--) { s->failed_pc=0x0c0ae670u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0ae672;
P_0c0ae672: /* original 644c, guest PC 0x0c0ae672 */
if(!s->budget--) { s->failed_pc=0x0c0ae672u; return 0; }
r[4]=r[4]&255u;
goto P_0c0ae674;
P_0c0ae674: /* original 633c, guest PC 0x0c0ae674 */
if(!s->budget--) { s->failed_pc=0x0c0ae674u; return 0; }
r[3]=r[3]&255u;
goto P_0c0ae676;
P_0c0ae676: /* original 4308, guest PC 0x0c0ae676 */
if(!s->budget--) { s->failed_pc=0x0c0ae676u; return 0; }
r[3]<<=2;
goto P_0c0ae678;
P_0c0ae678: /* original 3b3c, guest PC 0x0c0ae678 */
if(!s->budget--) { s->failed_pc=0x0c0ae678u; return 0; }
r[11]+=r[3];
goto P_0c0ae67a;
P_0c0ae67a: /* original d319, guest PC 0x0c0ae67a */
if(!s->budget--) { s->failed_pc=0x0c0ae67au; return 0; }
r[3]=read(ram,0x0c0ae6e0u,4);
goto P_0c0ae67c;
P_0c0ae67c: /* original 3d4c, guest PC 0x0c0ae67c */
if(!s->budget--) { s->failed_pc=0x0c0ae67cu; return 0; }
r[13]+=r[4];
goto P_0c0ae67e;
P_0c0ae67e: /* original 430b, guest PC 0x0c0ae67e */
if(!s->budget--) { s->failed_pc=0x0c0ae67eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0ae682u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ae682u) { target=s->pc; goto dispatch; }
goto P_0c0ae682;
P_0c0ae680: /* original 64b3, guest PC 0x0c0ae680 */
if(!s->budget--) { s->failed_pc=0x0c0ae680u; return 0; }
r[4]=r[11];
goto P_0c0ae682;
P_0c0ae682: /* original 6403, guest PC 0x0c0ae682 */
if(!s->budget--) { s->failed_pc=0x0c0ae682u; return 0; }
r[4]=r[0];
goto P_0c0ae684;
P_0c0ae684: /* original 34d3, guest PC 0x0c0ae684 */
if(!s->budget--) { s->failed_pc=0x0c0ae684u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[13])!=0);
goto P_0c0ae686;
P_0c0ae686: /* original 8903, guest PC 0x0c0ae686 */
if(!s->budget--) { s->failed_pc=0x0c0ae686u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae690; }
goto P_0c0ae688;
P_0c0ae688: /* original d216, guest PC 0x0c0ae688 */
if(!s->budget--) { s->failed_pc=0x0c0ae688u; return 0; }
r[2]=read(ram,0x0c0ae6e4u,4);
goto P_0c0ae68a;
P_0c0ae68a: /* original 65d3, guest PC 0x0c0ae68a */
if(!s->budget--) { s->failed_pc=0x0c0ae68au; return 0; }
r[5]=r[13];
goto P_0c0ae68c;
P_0c0ae68c: /* original 420b, guest PC 0x0c0ae68c */
if(!s->budget--) { s->failed_pc=0x0c0ae68cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0ae690u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ae690u) { target=s->pc; goto dispatch; }
goto P_0c0ae690;
P_0c0ae68e: /* original 64b3, guest PC 0x0c0ae68e */
if(!s->budget--) { s->failed_pc=0x0c0ae68eu; return 0; }
r[4]=r[11];
goto P_0c0ae690;
P_0c0ae690: /* original 4f16, guest PC 0x0c0ae690 */
if(!s->budget--) { s->failed_pc=0x0c0ae690u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ae692;
P_0c0ae692: /* original 53a2, guest PC 0x0c0ae692 */
if(!s->budget--) { s->failed_pc=0x0c0ae692u; return 0; }
r[3]=read(ram,r[10]+8,4);
goto P_0c0ae694;
P_0c0ae694: /* original 66a3, guest PC 0x0c0ae694 */
if(!s->budget--) { s->failed_pc=0x0c0ae694u; return 0; }
r[6]=r[10];
goto P_0c0ae696;
P_0c0ae696: /* original 65c3, guest PC 0x0c0ae696 */
if(!s->budget--) { s->failed_pc=0x0c0ae696u; return 0; }
r[5]=r[12];
goto P_0c0ae698;
P_0c0ae698: /* original 64e3, guest PC 0x0c0ae698 */
if(!s->budget--) { s->failed_pc=0x0c0ae698u; return 0; }
r[4]=r[14];
goto P_0c0ae69a;
P_0c0ae69a: /* original 4f26, guest PC 0x0c0ae69a */
if(!s->budget--) { s->failed_pc=0x0c0ae69au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ae69c;
P_0c0ae69c: /* original 7304, guest PC 0x0c0ae69c */
if(!s->budget--) { s->failed_pc=0x0c0ae69cu; return 0; }
r[3]+=0x00000004u;
goto P_0c0ae69e;
P_0c0ae69e: /* original 1a32, guest PC 0x0c0ae69e */
if(!s->budget--) { s->failed_pc=0x0c0ae69eu; return 0; }
write(ram,r[10]+8,r[3],4);
goto P_0c0ae6a0;
P_0c0ae6a0: /* original 69f6, guest PC 0x0c0ae6a0 */
if(!s->budget--) { s->failed_pc=0x0c0ae6a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0ae6a2;
P_0c0ae6a2: /* original 6af6, guest PC 0x0c0ae6a2 */
if(!s->budget--) { s->failed_pc=0x0c0ae6a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0ae6a4;
P_0c0ae6a4: /* original 6bf6, guest PC 0x0c0ae6a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae6a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ae6a6;
P_0c0ae6a6: /* original 6cf6, guest PC 0x0c0ae6a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae6a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ae6a8;
P_0c0ae6a8: /* original 6df6, guest PC 0x0c0ae6a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae6a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ae6aa;
P_0c0ae6aa: /* original adf7, guest PC 0x0c0ae6aa */
if(!s->budget--) { s->failed_pc=0x0c0ae6aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ae29c;
P_0c0ae6ac: /* original 6ef6, guest PC 0x0c0ae6ac */
if(!s->budget--) { s->failed_pc=0x0c0ae6acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ae6aeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ae6aeu; return 0; } return 1;
P_0c0ae6e8: /* original 2fe6, guest PC 0x0c0ae6e8 */
if(!s->budget--) { s->failed_pc=0x0c0ae6e8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae6ea;
P_0c0ae6ea: /* original 2fd6, guest PC 0x0c0ae6ea */
if(!s->budget--) { s->failed_pc=0x0c0ae6eau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae6ec;
P_0c0ae6ec: /* original 6d63, guest PC 0x0c0ae6ec */
if(!s->budget--) { s->failed_pc=0x0c0ae6ecu; return 0; }
r[13]=r[6];
goto P_0c0ae6ee;
P_0c0ae6ee: /* original 2fc6, guest PC 0x0c0ae6ee */
if(!s->budget--) { s->failed_pc=0x0c0ae6eeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae6f0;
P_0c0ae6f0: /* original 2fb6, guest PC 0x0c0ae6f0 */
if(!s->budget--) { s->failed_pc=0x0c0ae6f0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae6f2;
P_0c0ae6f2: /* original 2fa6, guest PC 0x0c0ae6f2 */
if(!s->budget--) { s->failed_pc=0x0c0ae6f2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae6f4;
P_0c0ae6f4: /* original 2f96, guest PC 0x0c0ae6f4 */
if(!s->budget--) { s->failed_pc=0x0c0ae6f4u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae6f6;
P_0c0ae6f6: /* original 4f22, guest PC 0x0c0ae6f6 */
if(!s->budget--) { s->failed_pc=0x0c0ae6f6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ae6f8;
P_0c0ae6f8: /* original 7ff4, guest PC 0x0c0ae6f8 */
if(!s->budget--) { s->failed_pc=0x0c0ae6f8u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0ae6fa;
P_0c0ae6fa: /* original 2f52, guest PC 0x0c0ae6fa */
if(!s->budget--) { s->failed_pc=0x0c0ae6fau; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ae6fc;
P_0c0ae6fc: /* original 53d1, guest PC 0x0c0ae6fc */
if(!s->budget--) { s->failed_pc=0x0c0ae6fcu; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0ae6fe;
P_0c0ae6fe: /* original 62d2, guest PC 0x0c0ae6fe */
if(!s->budget--) { s->failed_pc=0x0c0ae6feu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ae700;
P_0c0ae700: /* original de2e, guest PC 0x0c0ae700 */
if(!s->budget--) { s->failed_pc=0x0c0ae700u; return 0; }
r[14]=read(ram,0x0c0ae7bcu,4);
goto P_0c0ae702;
P_0c0ae702: /* original 3230, guest PC 0x0c0ae702 */
if(!s->budget--) { s->failed_pc=0x0c0ae702u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0ae704;
P_0c0ae704: /* original 8f43, guest PC 0x0c0ae704 */
if(!s->budget--) { s->failed_pc=0x0c0ae704u; return 0; }
cond=r[17]&1u;
r[12]=r[4];
if(!cond) { goto P_0c0ae78e; }
goto P_0c0ae708;
P_0c0ae706: /* original 6c43, guest PC 0x0c0ae706 */
if(!s->budget--) { s->failed_pc=0x0c0ae706u; return 0; }
r[12]=r[4];
goto P_0c0ae708;
P_0c0ae708: /* original 61e2, guest PC 0x0c0ae708 */
if(!s->budget--) { s->failed_pc=0x0c0ae708u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0ae70a;
P_0c0ae70a: /* original d32d, guest PC 0x0c0ae70a */
if(!s->budget--) { s->failed_pc=0x0c0ae70au; return 0; }
r[3]=read(ram,0x0c0ae7c0u,4);
goto P_0c0ae70c;
P_0c0ae70c: /* original 2138, guest PC 0x0c0ae70c */
if(!s->budget--) { s->failed_pc=0x0c0ae70cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0ae70e;
P_0c0ae70e: /* original 8b3e, guest PC 0x0c0ae70e */
if(!s->budget--) { s->failed_pc=0x0c0ae70eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae78e; }
goto P_0c0ae710;
P_0c0ae710: /* original 5bd2, guest PC 0x0c0ae710 */
if(!s->budget--) { s->failed_pc=0x0c0ae710u; return 0; }
r[11]=read(ram,r[13]+8,4);
goto P_0c0ae712;
P_0c0ae712: /* original e061, guest PC 0x0c0ae712 */
if(!s->budget--) { s->failed_pc=0x0c0ae712u; return 0; }
r[0]=0x00000061u;
goto P_0c0ae714;
P_0c0ae714: /* original 03cc, guest PC 0x0c0ae714 */
if(!s->budget--) { s->failed_pc=0x0c0ae714u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0ae716;
P_0c0ae716: /* original 7b03, guest PC 0x0c0ae716 */
if(!s->budget--) { s->failed_pc=0x0c0ae716u; return 0; }
r[11]+=0x00000003u;
goto P_0c0ae718;
P_0c0ae718: /* original 6bb0, guest PC 0x0c0ae718 */
if(!s->budget--) { s->failed_pc=0x0c0ae718u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[11],1);
r[11]=tmp;
goto P_0c0ae71a;
P_0c0ae71a: /* original 633c, guest PC 0x0c0ae71a */
if(!s->budget--) { s->failed_pc=0x0c0ae71au; return 0; }
r[3]=r[3]&255u;
goto P_0c0ae71c;
P_0c0ae71c: /* original 1f31, guest PC 0x0c0ae71c */
if(!s->budget--) { s->failed_pc=0x0c0ae71cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0ae71e;
P_0c0ae71e: /* original d22a, guest PC 0x0c0ae71e */
if(!s->budget--) { s->failed_pc=0x0c0ae71eu; return 0; }
r[2]=read(ram,0x0c0ae7c8u,4);
goto P_0c0ae720;
P_0c0ae720: /* original 6bbc, guest PC 0x0c0ae720 */
if(!s->budget--) { s->failed_pc=0x0c0ae720u; return 0; }
r[11]=r[11]&255u;
goto P_0c0ae722;
P_0c0ae722: /* original 69b3, guest PC 0x0c0ae722 */
if(!s->budget--) { s->failed_pc=0x0c0ae722u; return 0; }
r[9]=r[11];
goto P_0c0ae724;
P_0c0ae724: /* original da27, guest PC 0x0c0ae724 */
if(!s->budget--) { s->failed_pc=0x0c0ae724u; return 0; }
r[10]=read(ram,0x0c0ae7c4u,4);
goto P_0c0ae726;
P_0c0ae726: /* original 4908, guest PC 0x0c0ae726 */
if(!s->budget--) { s->failed_pc=0x0c0ae726u; return 0; }
r[9]<<=2;
goto P_0c0ae728;
P_0c0ae728: /* original 6423, guest PC 0x0c0ae728 */
if(!s->budget--) { s->failed_pc=0x0c0ae728u; return 0; }
r[4]=r[2];
goto P_0c0ae72a;
P_0c0ae72a: /* original 1f22, guest PC 0x0c0ae72a */
if(!s->budget--) { s->failed_pc=0x0c0ae72au; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0ae72c;
P_0c0ae72c: /* original d327, guest PC 0x0c0ae72c */
if(!s->budget--) { s->failed_pc=0x0c0ae72cu; return 0; }
r[3]=read(ram,0x0c0ae7ccu,4);
goto P_0c0ae72e;
P_0c0ae72e: /* original 430b, guest PC 0x0c0ae72e */
if(!s->budget--) { s->failed_pc=0x0c0ae72eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0ae732u;
r[4]+=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ae732u) { target=s->pc; goto dispatch; }
goto P_0c0ae732;
P_0c0ae730: /* original 7412, guest PC 0x0c0ae730 */
if(!s->budget--) { s->failed_pc=0x0c0ae730u; return 0; }
r[4]+=0x00000012u;
goto P_0c0ae732;
P_0c0ae732: /* original 640c, guest PC 0x0c0ae732 */
if(!s->budget--) { s->failed_pc=0x0c0ae732u; return 0; }
r[4]=r[0]&255u;
goto P_0c0ae734;
P_0c0ae734: /* original 6043, guest PC 0x0c0ae734 */
if(!s->budget--) { s->failed_pc=0x0c0ae734u; return 0; }
r[0]=r[4];
goto P_0c0ae736;
P_0c0ae736: /* original 8803, guest PC 0x0c0ae736 */
if(!s->budget--) { s->failed_pc=0x0c0ae736u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0ae738;
P_0c0ae738: /* original 8b00, guest PC 0x0c0ae738 */
if(!s->budget--) { s->failed_pc=0x0c0ae738u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae73c; }
goto P_0c0ae73a;
P_0c0ae73a: /* original da25, guest PC 0x0c0ae73a */
if(!s->budget--) { s->failed_pc=0x0c0ae73au; return 0; }
r[10]=read(ram,0x0c0ae7d0u,4);
goto P_0c0ae73c;
P_0c0ae73c: /* original 39ac, guest PC 0x0c0ae73c */
if(!s->budget--) { s->failed_pc=0x0c0ae73cu; return 0; }
r[9]+=r[10];
goto P_0c0ae73e;
P_0c0ae73e: /* original 54f1, guest PC 0x0c0ae73e */
if(!s->budget--) { s->failed_pc=0x0c0ae73eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0ae740;
P_0c0ae740: /* original 6592, guest PC 0x0c0ae740 */
if(!s->budget--) { s->failed_pc=0x0c0ae740u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0ae742;
P_0c0ae742: /* original 4408, guest PC 0x0c0ae742 */
if(!s->budget--) { s->failed_pc=0x0c0ae742u; return 0; }
r[4]<<=2;
goto P_0c0ae744;
P_0c0ae744: /* original 6a53, guest PC 0x0c0ae744 */
if(!s->budget--) { s->failed_pc=0x0c0ae744u; return 0; }
r[10]=r[5];
goto P_0c0ae746;
P_0c0ae746: /* original 3a4c, guest PC 0x0c0ae746 */
if(!s->budget--) { s->failed_pc=0x0c0ae746u; return 0; }
r[10]+=r[4];
goto P_0c0ae748;
P_0c0ae748: /* original 6aa2, guest PC 0x0c0ae748 */
if(!s->budget--) { s->failed_pc=0x0c0ae748u; return 0; }
tmp=read(ram,r[10],4);
r[10]=tmp;
goto P_0c0ae74a;
P_0c0ae74a: /* original 2aa8, guest PC 0x0c0ae74a */
if(!s->budget--) { s->failed_pc=0x0c0ae74au; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0ae74c;
P_0c0ae74c: /* original 891f, guest PC 0x0c0ae74c */
if(!s->budget--) { s->failed_pc=0x0c0ae74cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae78e; }
goto P_0c0ae74e;
P_0c0ae74e: /* original d421, guest PC 0x0c0ae74e */
if(!s->budget--) { s->failed_pc=0x0c0ae74eu; return 0; }
r[4]=read(ram,0x0c0ae7d4u,4);
goto P_0c0ae750;
P_0c0ae750: /* original 34bc, guest PC 0x0c0ae750 */
if(!s->budget--) { s->failed_pc=0x0c0ae750u; return 0; }
r[4]+=r[11];
goto P_0c0ae752;
P_0c0ae752: /* original 6440, guest PC 0x0c0ae752 */
if(!s->budget--) { s->failed_pc=0x0c0ae752u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]=tmp;
goto P_0c0ae754;
P_0c0ae754: /* original 644c, guest PC 0x0c0ae754 */
if(!s->budget--) { s->failed_pc=0x0c0ae754u; return 0; }
r[4]=r[4]&255u;
goto P_0c0ae756;
P_0c0ae756: /* original 2448, guest PC 0x0c0ae756 */
if(!s->budget--) { s->failed_pc=0x0c0ae756u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0ae758;
P_0c0ae758: /* original 8916, guest PC 0x0c0ae758 */
if(!s->budget--) { s->failed_pc=0x0c0ae758u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae788; }
goto P_0c0ae75a;
P_0c0ae75a: /* original 902b, guest PC 0x0c0ae75a */
if(!s->budget--) { s->failed_pc=0x0c0ae75au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae7b4u,2);
goto P_0c0ae75c;
P_0c0ae75c: /* original e301, guest PC 0x0c0ae75c */
if(!s->budget--) { s->failed_pc=0x0c0ae75cu; return 0; }
r[3]=0x00000001u;
goto P_0c0ae75e;
P_0c0ae75e: /* original 0e44, guest PC 0x0c0ae75e */
if(!s->budget--) { s->failed_pc=0x0c0ae75eu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0ae760;
P_0c0ae760: /* original 70d4, guest PC 0x0c0ae760 */
if(!s->budget--) { s->failed_pc=0x0c0ae760u; return 0; }
r[0]+=0xffffffd4u;
goto P_0c0ae762;
P_0c0ae762: /* original 05ee, guest PC 0x0c0ae762 */
if(!s->budget--) { s->failed_pc=0x0c0ae762u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0ae764;
P_0c0ae764: /* original e060, guest PC 0x0c0ae764 */
if(!s->budget--) { s->failed_pc=0x0c0ae764u; return 0; }
r[0]=0x00000060u;
goto P_0c0ae766;
P_0c0ae766: /* original 06cc, guest PC 0x0c0ae766 */
if(!s->budget--) { s->failed_pc=0x0c0ae766u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0ae768;
P_0c0ae768: /* original 7040, guest PC 0x0c0ae768 */
if(!s->budget--) { s->failed_pc=0x0c0ae768u; return 0; }
r[0]+=0x00000040u;
goto P_0c0ae76a;
P_0c0ae76a: /* original d41b, guest PC 0x0c0ae76a */
if(!s->budget--) { s->failed_pc=0x0c0ae76au; return 0; }
r[4]=read(ram,0x0c0ae7d8u,4);
goto P_0c0ae76c;
P_0c0ae76c: /* original 666c, guest PC 0x0c0ae76c */
if(!s->budget--) { s->failed_pc=0x0c0ae76cu; return 0; }
r[6]=r[6]&255u;
goto P_0c0ae76e;
P_0c0ae76e: /* original 666b, guest PC 0x0c0ae76e */
if(!s->budget--) { s->failed_pc=0x0c0ae76eu; return 0; }
r[6]=0u-r[6];
goto P_0c0ae770;
P_0c0ae770: /* original 446d, guest PC 0x0c0ae770 */
if(!s->budget--) { s->failed_pc=0x0c0ae770u; return 0; }
r[4]=(r[6]&0x80000000u)?((r[6]&31u)?r[4]>>((-r[6])&31u):0):r[4]<<(r[6]&31u);
goto P_0c0ae772;
P_0c0ae772: /* original 254b, guest PC 0x0c0ae772 */
if(!s->budget--) { s->failed_pc=0x0c0ae772u; return 0; }
r[5]|=r[4];
goto P_0c0ae774;
P_0c0ae774: /* original 0e56, guest PC 0x0c0ae774 */
if(!s->budget--) { s->failed_pc=0x0c0ae774u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c0ae776;
P_0c0ae776: /* original 901e, guest PC 0x0c0ae776 */
if(!s->budget--) { s->failed_pc=0x0c0ae776u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae7b6u,2);
goto P_0c0ae778;
P_0c0ae778: /* original 0e36, guest PC 0x0c0ae778 */
if(!s->budget--) { s->failed_pc=0x0c0ae778u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0ae77a;
P_0c0ae77a: /* original e054, guest PC 0x0c0ae77a */
if(!s->budget--) { s->failed_pc=0x0c0ae77au; return 0; }
r[0]=0x00000054u;
goto P_0c0ae77c;
P_0c0ae77c: /* original 02ce, guest PC 0x0c0ae77c */
if(!s->budget--) { s->failed_pc=0x0c0ae77cu; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0ae77e;
P_0c0ae77e: /* original e022, guest PC 0x0c0ae77e */
if(!s->budget--) { s->failed_pc=0x0c0ae77eu; return 0; }
r[0]=0x00000022u;
goto P_0c0ae780;
P_0c0ae780: /* original 032d, guest PC 0x0c0ae780 */
if(!s->budget--) { s->failed_pc=0x0c0ae780u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c0ae782;
P_0c0ae782: /* original 9019, guest PC 0x0c0ae782 */
if(!s->budget--) { s->failed_pc=0x0c0ae782u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae7b8u,2);
goto P_0c0ae784;
P_0c0ae784: /* original 7308, guest PC 0x0c0ae784 */
if(!s->budget--) { s->failed_pc=0x0c0ae784u; return 0; }
r[3]+=0x00000008u;
goto P_0c0ae786;
P_0c0ae786: /* original 0c35, guest PC 0x0c0ae786 */
if(!s->budget--) { s->failed_pc=0x0c0ae786u; return 0; }
write(ram,r[12]+r[0],r[3],2);
goto P_0c0ae788;
P_0c0ae788: /* original d314, guest PC 0x0c0ae788 */
if(!s->budget--) { s->failed_pc=0x0c0ae788u; return 0; }
r[3]=read(ram,0x0c0ae7dcu,4);
goto P_0c0ae78a;
P_0c0ae78a: /* original 430b, guest PC 0x0c0ae78a */
if(!s->budget--) { s->failed_pc=0x0c0ae78au; return 0; }
target=r[3];
r[16]=code_base|0x0c0ae78eu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ae78eu) { target=s->pc; goto dispatch; }
goto P_0c0ae78e;
P_0c0ae78c: /* original 64a3, guest PC 0x0c0ae78c */
if(!s->budget--) { s->failed_pc=0x0c0ae78cu; return 0; }
r[4]=r[10];
goto P_0c0ae78e;
P_0c0ae78e: /* original 52d2, guest PC 0x0c0ae78e */
if(!s->budget--) { s->failed_pc=0x0c0ae78eu; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c0ae790;
P_0c0ae790: /* original 64c3, guest PC 0x0c0ae790 */
if(!s->budget--) { s->failed_pc=0x0c0ae790u; return 0; }
r[4]=r[12];
goto P_0c0ae792;
P_0c0ae792: /* original 66d3, guest PC 0x0c0ae792 */
if(!s->budget--) { s->failed_pc=0x0c0ae792u; return 0; }
r[6]=r[13];
goto P_0c0ae794;
P_0c0ae794: /* original 7204, guest PC 0x0c0ae794 */
if(!s->budget--) { s->failed_pc=0x0c0ae794u; return 0; }
r[2]+=0x00000004u;
goto P_0c0ae796;
P_0c0ae796: /* original 1d22, guest PC 0x0c0ae796 */
if(!s->budget--) { s->failed_pc=0x0c0ae796u; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c0ae798;
P_0c0ae798: /* original 65f2, guest PC 0x0c0ae798 */
if(!s->budget--) { s->failed_pc=0x0c0ae798u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ae79a;
P_0c0ae79a: /* original 7f0c, guest PC 0x0c0ae79a */
if(!s->budget--) { s->failed_pc=0x0c0ae79au; return 0; }
r[15]+=0x0000000cu;
goto P_0c0ae79c;
P_0c0ae79c: /* original 4f26, guest PC 0x0c0ae79c */
if(!s->budget--) { s->failed_pc=0x0c0ae79cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ae79e;
P_0c0ae79e: /* original 69f6, guest PC 0x0c0ae79e */
if(!s->budget--) { s->failed_pc=0x0c0ae79eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0ae7a0;
P_0c0ae7a0: /* original 6af6, guest PC 0x0c0ae7a0 */
if(!s->budget--) { s->failed_pc=0x0c0ae7a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0ae7a2;
P_0c0ae7a2: /* original 6bf6, guest PC 0x0c0ae7a2 */
if(!s->budget--) { s->failed_pc=0x0c0ae7a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ae7a4;
P_0c0ae7a4: /* original 6cf6, guest PC 0x0c0ae7a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae7a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ae7a6;
P_0c0ae7a6: /* original 6df6, guest PC 0x0c0ae7a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae7a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ae7a8;
P_0c0ae7a8: /* original ad78, guest PC 0x0c0ae7a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae7a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ae29c;
P_0c0ae7aa: /* original 6ef6, guest PC 0x0c0ae7aa */
if(!s->budget--) { s->failed_pc=0x0c0ae7aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ae7acu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ae7acu; return 0; } return 1;
P_0c0af728: /* original 2fe6, guest PC 0x0c0af728 */
if(!s->budget--) { s->failed_pc=0x0c0af728u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af72a;
P_0c0af72a: /* original 6e43, guest PC 0x0c0af72a */
if(!s->budget--) { s->failed_pc=0x0c0af72au; return 0; }
r[14]=r[4];
goto P_0c0af72c;
P_0c0af72c: /* original 2fd6, guest PC 0x0c0af72c */
if(!s->budget--) { s->failed_pc=0x0c0af72cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af72e;
P_0c0af72e: /* original 6d63, guest PC 0x0c0af72e */
if(!s->budget--) { s->failed_pc=0x0c0af72eu; return 0; }
r[13]=r[6];
goto P_0c0af730;
P_0c0af730: /* original 53d2, guest PC 0x0c0af730 */
if(!s->budget--) { s->failed_pc=0x0c0af730u; return 0; }
r[3]=read(ram,r[13]+8,4);
goto P_0c0af732;
P_0c0af732: /* original 907a, guest PC 0x0c0af732 */
if(!s->budget--) { s->failed_pc=0x0c0af732u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af82au,2);
goto P_0c0af734;
P_0c0af734: /* original 4f22, guest PC 0x0c0af734 */
if(!s->budget--) { s->failed_pc=0x0c0af734u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0af736;
P_0c0af736: /* original d441, guest PC 0x0c0af736 */
if(!s->budget--) { s->failed_pc=0x0c0af736u; return 0; }
r[4]=read(ram,0x0c0af83cu,4);
goto P_0c0af738;
P_0c0af738: /* original 0e36, guest PC 0x0c0af738 */
if(!s->budget--) { s->failed_pc=0x0c0af738u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0af73a;
P_0c0af73a: /* original 9377, guest PC 0x0c0af73a */
if(!s->budget--) { s->failed_pc=0x0c0af73au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af82cu,2);
goto P_0c0af73c;
P_0c0af73c: /* original 7ff8, guest PC 0x0c0af73c */
if(!s->budget--) { s->failed_pc=0x0c0af73cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0af73e;
P_0c0af73e: /* original 52d3, guest PC 0x0c0af73e */
if(!s->budget--) { s->failed_pc=0x0c0af73eu; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0af740;
P_0c0af740: /* original 2238, guest PC 0x0c0af740 */
if(!s->budget--) { s->failed_pc=0x0c0af740u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0af742;
P_0c0af742: /* original 890e, guest PC 0x0c0af742 */
if(!s->budget--) { s->failed_pc=0x0c0af742u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af762; }
goto P_0c0af744;
P_0c0af744: /* original 51d3, guest PC 0x0c0af744 */
if(!s->budget--) { s->failed_pc=0x0c0af744u; return 0; }
r[1]=read(ram,r[13]+12,4);
goto P_0c0af746;
P_0c0af746: /* original 9372, guest PC 0x0c0af746 */
if(!s->budget--) { s->failed_pc=0x0c0af746u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af82eu,2);
goto P_0c0af748;
P_0c0af748: /* original 2139, guest PC 0x0c0af748 */
if(!s->budget--) { s->failed_pc=0x0c0af748u; return 0; }
r[1]&=r[3];
goto P_0c0af74a;
P_0c0af74a: /* original 1d13, guest PC 0x0c0af74a */
if(!s->budget--) { s->failed_pc=0x0c0af74au; return 0; }
write(ram,r[13]+12,r[1],4);
goto P_0c0af74c;
P_0c0af74c: /* original d53c, guest PC 0x0c0af74c */
if(!s->budget--) { s->failed_pc=0x0c0af74cu; return 0; }
r[5]=read(ram,0x0c0af840u,4);
goto P_0c0af74e;
P_0c0af74e: /* original 5241, guest PC 0x0c0af74e */
if(!s->budget--) { s->failed_pc=0x0c0af74eu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c0af750;
P_0c0af750: /* original 2258, guest PC 0x0c0af750 */
if(!s->budget--) { s->failed_pc=0x0c0af750u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0af752;
P_0c0af752: /* original 8b06, guest PC 0x0c0af752 */
if(!s->budget--) { s->failed_pc=0x0c0af752u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0af762; }
goto P_0c0af754;
P_0c0af754: /* original 6342, guest PC 0x0c0af754 */
if(!s->budget--) { s->failed_pc=0x0c0af754u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0af756;
P_0c0af756: /* original 2538, guest PC 0x0c0af756 */
if(!s->budget--) { s->failed_pc=0x0c0af756u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0af758;
P_0c0af758: /* original 8b03, guest PC 0x0c0af758 */
if(!s->budget--) { s->failed_pc=0x0c0af758u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0af762; }
goto P_0c0af75a;
P_0c0af75a: /* original 85ef, guest PC 0x0c0af75a */
if(!s->budget--) { s->failed_pc=0x0c0af75au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0af75c;
P_0c0af75c: /* original 9368, guest PC 0x0c0af75c */
if(!s->budget--) { s->failed_pc=0x0c0af75cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af830u,2);
goto P_0c0af75e;
P_0c0af75e: /* original 303c, guest PC 0x0c0af75e */
if(!s->budget--) { s->failed_pc=0x0c0af75eu; return 0; }
r[0]+=r[3];
goto P_0c0af760;
P_0c0af760: /* original 81ef, guest PC 0x0c0af760 */
if(!s->budget--) { s->failed_pc=0x0c0af760u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0af762;
P_0c0af762: /* original 53d4, guest PC 0x0c0af762 */
if(!s->budget--) { s->failed_pc=0x0c0af762u; return 0; }
r[3]=read(ram,r[13]+16,4);
goto P_0c0af764;
P_0c0af764: /* original d437, guest PC 0x0c0af764 */
if(!s->budget--) { s->failed_pc=0x0c0af764u; return 0; }
r[4]=read(ram,0x0c0af844u,4);
goto P_0c0af766;
P_0c0af766: /* original 2348, guest PC 0x0c0af766 */
if(!s->budget--) { s->failed_pc=0x0c0af766u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0af768;
P_0c0af768: /* original 8903, guest PC 0x0c0af768 */
if(!s->budget--) { s->failed_pc=0x0c0af768u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af772; }
goto P_0c0af76a;
P_0c0af76a: /* original 52d3, guest PC 0x0c0af76a */
if(!s->budget--) { s->failed_pc=0x0c0af76au; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0af76c;
P_0c0af76c: /* original d336, guest PC 0x0c0af76c */
if(!s->budget--) { s->failed_pc=0x0c0af76cu; return 0; }
r[3]=read(ram,0x0c0af848u,4);
goto P_0c0af76e;
P_0c0af76e: /* original 223b, guest PC 0x0c0af76e */
if(!s->budget--) { s->failed_pc=0x0c0af76eu; return 0; }
r[2]|=r[3];
goto P_0c0af770;
P_0c0af770: /* original 1d23, guest PC 0x0c0af770 */
if(!s->budget--) { s->failed_pc=0x0c0af770u; return 0; }
write(ram,r[13]+12,r[2],4);
goto P_0c0af772;
P_0c0af772: /* original 51d3, guest PC 0x0c0af772 */
if(!s->budget--) { s->failed_pc=0x0c0af772u; return 0; }
r[1]=read(ram,r[13]+12,4);
goto P_0c0af774;
P_0c0af774: /* original 2418, guest PC 0x0c0af774 */
if(!s->budget--) { s->failed_pc=0x0c0af774u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[1])==0)!=0);
goto P_0c0af776;
P_0c0af776: /* original 891e, guest PC 0x0c0af776 */
if(!s->budget--) { s->failed_pc=0x0c0af776u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af7b6; }
goto P_0c0af778;
P_0c0af778: /* original d334, guest PC 0x0c0af778 */
if(!s->budget--) { s->failed_pc=0x0c0af778u; return 0; }
r[3]=read(ram,0x0c0af84cu,4);
goto P_0c0af77a;
P_0c0af77a: /* original 65f3, guest PC 0x0c0af77a */
if(!s->budget--) { s->failed_pc=0x0c0af77au; return 0; }
r[5]=r[15];
goto P_0c0af77c;
P_0c0af77c: /* original 52d3, guest PC 0x0c0af77c */
if(!s->budget--) { s->failed_pc=0x0c0af77cu; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0af77e;
P_0c0af77e: /* original 66f3, guest PC 0x0c0af77e */
if(!s->budget--) { s->failed_pc=0x0c0af77eu; return 0; }
r[6]=r[15];
goto P_0c0af780;
P_0c0af780: /* original 2239, guest PC 0x0c0af780 */
if(!s->budget--) { s->failed_pc=0x0c0af780u; return 0; }
r[2]&=r[3];
goto P_0c0af782;
P_0c0af782: /* original 1d23, guest PC 0x0c0af782 */
if(!s->budget--) { s->failed_pc=0x0c0af782u; return 0; }
write(ram,r[13]+12,r[2],4);
goto P_0c0af784;
P_0c0af784: /* original 85ef, guest PC 0x0c0af784 */
if(!s->budget--) { s->failed_pc=0x0c0af784u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0af786;
P_0c0af786: /* original 640d, guest PC 0x0c0af786 */
if(!s->budget--) { s->failed_pc=0x0c0af786u; return 0; }
r[4]=r[0]&65535u;
goto P_0c0af788;
P_0c0af788: /* original 9053, guest PC 0x0c0af788 */
if(!s->budget--) { s->failed_pc=0x0c0af788u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af832u,2);
goto P_0c0af78a;
P_0c0af78a: /* original f3e6, guest PC 0x0c0af78a */
if(!s->budget--) { s->failed_pc=0x0c0af78au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0af78c;
P_0c0af78c: /* original e004, guest PC 0x0c0af78c */
if(!s->budget--) { s->failed_pc=0x0c0af78cu; return 0; }
r[0]=0x00000004u;
goto P_0c0af78e;
P_0c0af78e: /* original ff37, guest PC 0x0c0af78e */
if(!s->budget--) { s->failed_pc=0x0c0af78eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0af790;
P_0c0af790: /* original 9050, guest PC 0x0c0af790 */
if(!s->budget--) { s->failed_pc=0x0c0af790u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af834u,2);
goto P_0c0af792;
P_0c0af792: /* original f3e6, guest PC 0x0c0af792 */
if(!s->budget--) { s->failed_pc=0x0c0af792u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0af794;
P_0c0af794: /* original ff3a, guest PC 0x0c0af794 */
if(!s->budget--) { s->failed_pc=0x0c0af794u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0af796;
P_0c0af796: /* original d22e, guest PC 0x0c0af796 */
if(!s->budget--) { s->failed_pc=0x0c0af796u; return 0; }
r[2]=read(ram,0x0c0af850u,4);
goto P_0c0af798;
P_0c0af798: /* original 420b, guest PC 0x0c0af798 */
if(!s->budget--) { s->failed_pc=0x0c0af798u; return 0; }
target=r[2];
r[16]=code_base|0x0c0af79cu;
r[5]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0af79cu) { target=s->pc; goto dispatch; }
goto P_0c0af79c;
P_0c0af79a: /* original 7504, guest PC 0x0c0af79a */
if(!s->budget--) { s->failed_pc=0x0c0af79au; return 0; }
r[5]+=0x00000004u;
goto P_0c0af79c;
P_0c0af79c: /* original 904b, guest PC 0x0c0af79c */
if(!s->budget--) { s->failed_pc=0x0c0af79cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af836u,2);
goto P_0c0af79e;
P_0c0af79e: /* original f2f8, guest PC 0x0c0af79e */
if(!s->budget--) { s->failed_pc=0x0c0af79eu; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0af7a0;
P_0c0af7a0: /* original f5e6, guest PC 0x0c0af7a0 */
if(!s->budget--) { s->failed_pc=0x0c0af7a0u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0af7a2;
P_0c0af7a2: /* original 7008, guest PC 0x0c0af7a2 */
if(!s->budget--) { s->failed_pc=0x0c0af7a2u; return 0; }
r[0]+=0x00000008u;
goto P_0c0af7a4;
P_0c0af7a4: /* original f4e6, guest PC 0x0c0af7a4 */
if(!s->budget--) { s->failed_pc=0x0c0af7a4u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0af7a6;
P_0c0af7a6: /* original e004, guest PC 0x0c0af7a6 */
if(!s->budget--) { s->failed_pc=0x0c0af7a6u; return 0; }
r[0]=0x00000004u;
goto P_0c0af7a8;
P_0c0af7a8: /* original f3f6, guest PC 0x0c0af7a8 */
if(!s->budget--) { s->failed_pc=0x0c0af7a8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0af7aa;
P_0c0af7aa: /* original e010, guest PC 0x0c0af7aa */
if(!s->budget--) { s->failed_pc=0x0c0af7aau; return 0; }
r[0]=0x00000010u;
goto P_0c0af7ac;
P_0c0af7ac: /* original f421, guest PC 0x0c0af7ac */
if(!s->budget--) { s->failed_pc=0x0c0af7acu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'-');
goto P_0c0af7ae;
P_0c0af7ae: /* original f531, guest PC 0x0c0af7ae */
if(!s->budget--) { s->failed_pc=0x0c0af7aeu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c0af7b0;
P_0c0af7b0: /* original fe57, guest PC 0x0c0af7b0 */
if(!s->budget--) { s->failed_pc=0x0c0af7b0u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0af7b2;
P_0c0af7b2: /* original e018, guest PC 0x0c0af7b2 */
if(!s->budget--) { s->failed_pc=0x0c0af7b2u; return 0; }
r[0]=0x00000018u;
goto P_0c0af7b4;
P_0c0af7b4: /* original fe47, guest PC 0x0c0af7b4 */
if(!s->budget--) { s->failed_pc=0x0c0af7b4u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0af7b6;
P_0c0af7b6: /* original d327, guest PC 0x0c0af7b6 */
if(!s->budget--) { s->failed_pc=0x0c0af7b6u; return 0; }
r[3]=read(ram,0x0c0af854u,4);
goto P_0c0af7b8;
P_0c0af7b8: /* original 64e2, guest PC 0x0c0af7b8 */
if(!s->budget--) { s->failed_pc=0x0c0af7b8u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0af7ba;
P_0c0af7ba: /* original 2348, guest PC 0x0c0af7ba */
if(!s->budget--) { s->failed_pc=0x0c0af7bau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0af7bc;
P_0c0af7bc: /* original 8906, guest PC 0x0c0af7bc */
if(!s->budget--) { s->failed_pc=0x0c0af7bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af7cc; }
goto P_0c0af7be;
P_0c0af7be: /* original d226, guest PC 0x0c0af7be */
if(!s->budget--) { s->failed_pc=0x0c0af7beu; return 0; }
r[2]=read(ram,0x0c0af858u,4);
goto P_0c0af7c0;
P_0c0af7c0: /* original 2429, guest PC 0x0c0af7c0 */
if(!s->budget--) { s->failed_pc=0x0c0af7c0u; return 0; }
r[4]&=r[2];
goto P_0c0af7c2;
P_0c0af7c2: /* original 2e42, guest PC 0x0c0af7c2 */
if(!s->budget--) { s->failed_pc=0x0c0af7c2u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0af7c4;
P_0c0af7c4: /* original d325, guest PC 0x0c0af7c4 */
if(!s->budget--) { s->failed_pc=0x0c0af7c4u; return 0; }
r[3]=read(ram,0x0c0af85cu,4);
goto P_0c0af7c6;
P_0c0af7c6: /* original 51d3, guest PC 0x0c0af7c6 */
if(!s->budget--) { s->failed_pc=0x0c0af7c6u; return 0; }
r[1]=read(ram,r[13]+12,4);
goto P_0c0af7c8;
P_0c0af7c8: /* original 213b, guest PC 0x0c0af7c8 */
if(!s->budget--) { s->failed_pc=0x0c0af7c8u; return 0; }
r[1]|=r[3];
goto P_0c0af7ca;
P_0c0af7ca: /* original 1d13, guest PC 0x0c0af7ca */
if(!s->budget--) { s->failed_pc=0x0c0af7cau; return 0; }
write(ram,r[13]+12,r[1],4);
goto P_0c0af7cc;
P_0c0af7cc: /* original 7f08, guest PC 0x0c0af7cc */
if(!s->budget--) { s->failed_pc=0x0c0af7ccu; return 0; }
r[15]+=0x00000008u;
goto P_0c0af7ce;
P_0c0af7ce: /* original 52d3, guest PC 0x0c0af7ce */
if(!s->budget--) { s->failed_pc=0x0c0af7ceu; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0af7d0;
P_0c0af7d0: /* original 4f26, guest PC 0x0c0af7d0 */
if(!s->budget--) { s->failed_pc=0x0c0af7d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0af7d2;
P_0c0af7d2: /* original e048, guest PC 0x0c0af7d2 */
if(!s->budget--) { s->failed_pc=0x0c0af7d2u; return 0; }
r[0]=0x00000048u;
goto P_0c0af7d4;
P_0c0af7d4: /* original 0e26, guest PC 0x0c0af7d4 */
if(!s->budget--) { s->failed_pc=0x0c0af7d4u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0af7d6;
P_0c0af7d6: /* original 6df6, guest PC 0x0c0af7d6 */
if(!s->budget--) { s->failed_pc=0x0c0af7d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0af7d8;
P_0c0af7d8: /* original 000b, guest PC 0x0c0af7d8 */
if(!s->budget--) { s->failed_pc=0x0c0af7d8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0af7da: /* original 6ef6, guest PC 0x0c0af7da */
if(!s->budget--) { s->failed_pc=0x0c0af7dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0af7dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0af7dcu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
