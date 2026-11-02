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
int vf3_away_batch16_adapter_12(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08dee6u: goto P_0c08dee6;
case 0x0c08dee8u: goto P_0c08dee8;
case 0x0c08deeau: goto P_0c08deea;
case 0x0c08deecu: goto P_0c08deec;
case 0x0c08deeeu: goto P_0c08deee;
case 0x0c08def0u: goto P_0c08def0;
case 0x0c08def2u: goto P_0c08def2;
case 0x0c08def4u: goto P_0c08def4;
case 0x0c08def6u: goto P_0c08def6;
case 0x0c08def8u: goto P_0c08def8;
case 0x0c08defau: goto P_0c08defa;
case 0x0c08defcu: goto P_0c08defc;
case 0x0c08defeu: goto P_0c08defe;
case 0x0c08df00u: goto P_0c08df00;
case 0x0c08df02u: goto P_0c08df02;
case 0x0c08df04u: goto P_0c08df04;
case 0x0c08df06u: goto P_0c08df06;
case 0x0c08df08u: goto P_0c08df08;
case 0x0c08df0au: goto P_0c08df0a;
case 0x0c08df0cu: goto P_0c08df0c;
case 0x0c08df0eu: goto P_0c08df0e;
case 0x0c08df10u: goto P_0c08df10;
case 0x0c08df12u: goto P_0c08df12;
case 0x0c08df14u: goto P_0c08df14;
case 0x0c08df16u: goto P_0c08df16;
case 0x0c08df18u: goto P_0c08df18;
case 0x0c08df1au: goto P_0c08df1a;
case 0x0c08df1cu: goto P_0c08df1c;
case 0x0c08df1eu: goto P_0c08df1e;
case 0x0c08df20u: goto P_0c08df20;
case 0x0c08df22u: goto P_0c08df22;
case 0x0c08df24u: goto P_0c08df24;
case 0x0c08df26u: goto P_0c08df26;
case 0x0c08df28u: goto P_0c08df28;
case 0x0c08df2au: goto P_0c08df2a;
case 0x0c08df2cu: goto P_0c08df2c;
case 0x0c08df2eu: goto P_0c08df2e;
case 0x0c08df30u: goto P_0c08df30;
case 0x0c08df32u: goto P_0c08df32;
case 0x0c08df34u: goto P_0c08df34;
case 0x0c08df36u: goto P_0c08df36;
case 0x0c08df6cu: goto P_0c08df6c;
case 0x0c08df6eu: goto P_0c08df6e;
case 0x0c08df70u: goto P_0c08df70;
case 0x0c08df72u: goto P_0c08df72;
case 0x0c08df74u: goto P_0c08df74;
case 0x0c08df76u: goto P_0c08df76;
case 0x0c08df78u: goto P_0c08df78;
case 0x0c08df7au: goto P_0c08df7a;
case 0x0c08df7cu: goto P_0c08df7c;
case 0x0c08df7eu: goto P_0c08df7e;
case 0x0c08df80u: goto P_0c08df80;
case 0x0c08df82u: goto P_0c08df82;
case 0x0c08df84u: goto P_0c08df84;
case 0x0c08df86u: goto P_0c08df86;
case 0x0c08df88u: goto P_0c08df88;
case 0x0c08df8au: goto P_0c08df8a;
case 0x0c08df8cu: goto P_0c08df8c;
case 0x0c08df8eu: goto P_0c08df8e;
case 0x0c08df90u: goto P_0c08df90;
case 0x0c08df92u: goto P_0c08df92;
case 0x0c08df94u: goto P_0c08df94;
case 0x0c08df96u: goto P_0c08df96;
case 0x0c08df98u: goto P_0c08df98;
case 0x0c08df9au: goto P_0c08df9a;
case 0x0c08df9cu: goto P_0c08df9c;
case 0x0c08df9eu: goto P_0c08df9e;
case 0x0c08dfa0u: goto P_0c08dfa0;
case 0x0c08dfa2u: goto P_0c08dfa2;
case 0x0c08dfa4u: goto P_0c08dfa4;
case 0x0c08dfa6u: goto P_0c08dfa6;
case 0x0c08dfa8u: goto P_0c08dfa8;
case 0x0c08dfaau: goto P_0c08dfaa;
case 0x0c08dfacu: goto P_0c08dfac;
case 0x0c08dfaeu: goto P_0c08dfae;
case 0x0c08dfb0u: goto P_0c08dfb0;
case 0x0c08dfb2u: goto P_0c08dfb2;
case 0x0c08dfb4u: goto P_0c08dfb4;
case 0x0c08dfb6u: goto P_0c08dfb6;
case 0x0c08dfb8u: goto P_0c08dfb8;
case 0x0c08dfbau: goto P_0c08dfba;
case 0x0c08dfbcu: goto P_0c08dfbc;
case 0x0c08dfbeu: goto P_0c08dfbe;
case 0x0c08dfc0u: goto P_0c08dfc0;
case 0x0c08dfc2u: goto P_0c08dfc2;
case 0x0c08dfc4u: goto P_0c08dfc4;
case 0x0c08dfc6u: goto P_0c08dfc6;
case 0x0c08dfc8u: goto P_0c08dfc8;
case 0x0c08dfcau: goto P_0c08dfca;
case 0x0c08dfccu: goto P_0c08dfcc;
case 0x0c08dfceu: goto P_0c08dfce;
case 0x0c08dfd0u: goto P_0c08dfd0;
case 0x0c08dfd2u: goto P_0c08dfd2;
case 0x0c08dfd4u: goto P_0c08dfd4;
case 0x0c08dfd6u: goto P_0c08dfd6;
case 0x0c08dfd8u: goto P_0c08dfd8;
case 0x0c08dfdau: goto P_0c08dfda;
case 0x0c08dfdcu: goto P_0c08dfdc;
case 0x0c08dfdeu: goto P_0c08dfde;
case 0x0c08dfe0u: goto P_0c08dfe0;
case 0x0c08dfe2u: goto P_0c08dfe2;
case 0x0c08dfe4u: goto P_0c08dfe4;
case 0x0c08dfe6u: goto P_0c08dfe6;
case 0x0c08dfe8u: goto P_0c08dfe8;
case 0x0c08dfeau: goto P_0c08dfea;
case 0x0c08dfecu: goto P_0c08dfec;
case 0x0c08dfeeu: goto P_0c08dfee;
case 0x0c08dff0u: goto P_0c08dff0;
case 0x0c08dff2u: goto P_0c08dff2;
case 0x0c08e5c4u: goto P_0c08e5c4;
case 0x0c08e5c6u: goto P_0c08e5c6;
case 0x0c08e5c8u: goto P_0c08e5c8;
case 0x0c08e5cau: goto P_0c08e5ca;
case 0x0c08e5ccu: goto P_0c08e5cc;
case 0x0c08e5ceu: goto P_0c08e5ce;
case 0x0c08e5d0u: goto P_0c08e5d0;
case 0x0c08e5d2u: goto P_0c08e5d2;
case 0x0c08e5d4u: goto P_0c08e5d4;
case 0x0c08e5d6u: goto P_0c08e5d6;
case 0x0c08e5d8u: goto P_0c08e5d8;
case 0x0c08e5dau: goto P_0c08e5da;
case 0x0c08e5dcu: goto P_0c08e5dc;
case 0x0c08e5deu: goto P_0c08e5de;
case 0x0c08e5e0u: goto P_0c08e5e0;
case 0x0c08e5e2u: goto P_0c08e5e2;
case 0x0c08e5e4u: goto P_0c08e5e4;
case 0x0c08e5e6u: goto P_0c08e5e6;
case 0x0c08e5e8u: goto P_0c08e5e8;
case 0x0c08e5eau: goto P_0c08e5ea;
case 0x0c08e5ecu: goto P_0c08e5ec;
case 0x0c08e5eeu: goto P_0c08e5ee;
case 0x0c08e5f0u: goto P_0c08e5f0;
case 0x0c08e5f2u: goto P_0c08e5f2;
case 0x0c08e5f4u: goto P_0c08e5f4;
case 0x0c08e5f6u: goto P_0c08e5f6;
case 0x0c08e5f8u: goto P_0c08e5f8;
case 0x0c08e5fau: goto P_0c08e5fa;
case 0x0c08e5fcu: goto P_0c08e5fc;
case 0x0c08e5feu: goto P_0c08e5fe;
case 0x0c08e600u: goto P_0c08e600;
case 0x0c08e602u: goto P_0c08e602;
case 0x0c08e604u: goto P_0c08e604;
case 0x0c08e606u: goto P_0c08e606;
case 0x0c08e608u: goto P_0c08e608;
case 0x0c08e60au: goto P_0c08e60a;
case 0x0c08e60cu: goto P_0c08e60c;
case 0x0c08e60eu: goto P_0c08e60e;
case 0x0c08e610u: goto P_0c08e610;
case 0x0c08e612u: goto P_0c08e612;
case 0x0c08e614u: goto P_0c08e614;
case 0x0c08e616u: goto P_0c08e616;
case 0x0c08e618u: goto P_0c08e618;
case 0x0c08e61au: goto P_0c08e61a;
case 0x0c08e61cu: goto P_0c08e61c;
case 0x0c08e61eu: goto P_0c08e61e;
case 0x0c08e620u: goto P_0c08e620;
case 0x0c08e622u: goto P_0c08e622;
case 0x0c08e624u: goto P_0c08e624;
case 0x0c08e626u: goto P_0c08e626;
case 0x0c08e628u: goto P_0c08e628;
case 0x0c08e62au: goto P_0c08e62a;
case 0x0c08e62cu: goto P_0c08e62c;
case 0x0c08e62eu: goto P_0c08e62e;
case 0x0c08e630u: goto P_0c08e630;
case 0x0c08e632u: goto P_0c08e632;
case 0x0c08e634u: goto P_0c08e634;
case 0x0c08e636u: goto P_0c08e636;
case 0x0c08e638u: goto P_0c08e638;
case 0x0c08e63au: goto P_0c08e63a;
case 0x0c08e63cu: goto P_0c08e63c;
case 0x0c08e63eu: goto P_0c08e63e;
case 0x0c08e640u: goto P_0c08e640;
case 0x0c08e642u: goto P_0c08e642;
case 0x0c08e644u: goto P_0c08e644;
case 0x0c08e646u: goto P_0c08e646;
case 0x0c08e648u: goto P_0c08e648;
case 0x0c08e64au: goto P_0c08e64a;
case 0x0c08e64cu: goto P_0c08e64c;
case 0x0c08e64eu: goto P_0c08e64e;
case 0x0c08e650u: goto P_0c08e650;
case 0x0c08e652u: goto P_0c08e652;
case 0x0c08e654u: goto P_0c08e654;
case 0x0c08e656u: goto P_0c08e656;
case 0x0c08e658u: goto P_0c08e658;
case 0x0c08e65au: goto P_0c08e65a;
case 0x0c08e65cu: goto P_0c08e65c;
case 0x0c08e65eu: goto P_0c08e65e;
case 0x0c08e660u: goto P_0c08e660;
case 0x0c08e662u: goto P_0c08e662;
case 0x0c08e664u: goto P_0c08e664;
case 0x0c08e666u: goto P_0c08e666;
case 0x0c08e668u: goto P_0c08e668;
case 0x0c08e66au: goto P_0c08e66a;
case 0x0c08e66cu: goto P_0c08e66c;
case 0x0c08e66eu: goto P_0c08e66e;
case 0x0c08e68cu: goto P_0c08e68c;
case 0x0c08e68eu: goto P_0c08e68e;
case 0x0c08e690u: goto P_0c08e690;
case 0x0c08e692u: goto P_0c08e692;
case 0x0c08e694u: goto P_0c08e694;
case 0x0c08e696u: goto P_0c08e696;
case 0x0c08e698u: goto P_0c08e698;
case 0x0c08e69au: goto P_0c08e69a;
case 0x0c08e69cu: goto P_0c08e69c;
case 0x0c08e69eu: goto P_0c08e69e;
case 0x0c08e6a0u: goto P_0c08e6a0;
case 0x0c08e6a2u: goto P_0c08e6a2;
case 0x0c08e6a4u: goto P_0c08e6a4;
case 0x0c08e6a6u: goto P_0c08e6a6;
case 0x0c08e6a8u: goto P_0c08e6a8;
case 0x0c08e6aau: goto P_0c08e6aa;
case 0x0c08e6acu: goto P_0c08e6ac;
case 0x0c08e6aeu: goto P_0c08e6ae;
case 0x0c08e6b0u: goto P_0c08e6b0;
case 0x0c08e6b2u: goto P_0c08e6b2;
case 0x0c08e6b4u: goto P_0c08e6b4;
case 0x0c08e6b6u: goto P_0c08e6b6;
case 0x0c08e6b8u: goto P_0c08e6b8;
case 0x0c08e6bau: goto P_0c08e6ba;
case 0x0c08e6bcu: goto P_0c08e6bc;
case 0x0c08e6beu: goto P_0c08e6be;
case 0x0c08e6c0u: goto P_0c08e6c0;
case 0x0c08e6c2u: goto P_0c08e6c2;
case 0x0c08e6c4u: goto P_0c08e6c4;
case 0x0c08e6c6u: goto P_0c08e6c6;
case 0x0c08e6c8u: goto P_0c08e6c8;
case 0x0c08e6cau: goto P_0c08e6ca;
case 0x0c08e6ccu: goto P_0c08e6cc;
case 0x0c08e6ceu: goto P_0c08e6ce;
case 0x0c08e6d0u: goto P_0c08e6d0;
case 0x0c08e6d2u: goto P_0c08e6d2;
case 0x0c08e6d4u: goto P_0c08e6d4;
case 0x0c08e6d6u: goto P_0c08e6d6;
case 0x0c08e6d8u: goto P_0c08e6d8;
case 0x0c08e6dau: goto P_0c08e6da;
case 0x0c08e6dcu: goto P_0c08e6dc;
case 0x0c08e6deu: goto P_0c08e6de;
case 0x0c08e6e0u: goto P_0c08e6e0;
case 0x0c08e6e2u: goto P_0c08e6e2;
case 0x0c08e6e4u: goto P_0c08e6e4;
case 0x0c08e6e6u: goto P_0c08e6e6;
case 0x0c08e6e8u: goto P_0c08e6e8;
case 0x0c08e6eau: goto P_0c08e6ea;
case 0x0c08e6ecu: goto P_0c08e6ec;
case 0x0c08e6eeu: goto P_0c08e6ee;
case 0x0c08e6f0u: goto P_0c08e6f0;
case 0x0c08e6f2u: goto P_0c08e6f2;
case 0x0c08e6f4u: goto P_0c08e6f4;
case 0x0c08e6f6u: goto P_0c08e6f6;
case 0x0c08e6f8u: goto P_0c08e6f8;
case 0x0c08e6fau: goto P_0c08e6fa;
case 0x0c08e6fcu: goto P_0c08e6fc;
case 0x0c08e6feu: goto P_0c08e6fe;
case 0x0c08e700u: goto P_0c08e700;
case 0x0c08e702u: goto P_0c08e702;
case 0x0c08e704u: goto P_0c08e704;
case 0x0c08e706u: goto P_0c08e706;
case 0x0c08e708u: goto P_0c08e708;
case 0x0c08e70au: goto P_0c08e70a;
case 0x0c08e70cu: goto P_0c08e70c;
case 0x0c08e70eu: goto P_0c08e70e;
case 0x0c08e710u: goto P_0c08e710;
case 0x0c08e712u: goto P_0c08e712;
case 0x0c08e714u: goto P_0c08e714;
case 0x0c08e716u: goto P_0c08e716;
case 0x0c08e718u: goto P_0c08e718;
case 0x0c08e71au: goto P_0c08e71a;
case 0x0c08e71cu: goto P_0c08e71c;
case 0x0c08e71eu: goto P_0c08e71e;
case 0x0c08e720u: goto P_0c08e720;
case 0x0c08e722u: goto P_0c08e722;
case 0x0c08e724u: goto P_0c08e724;
case 0x0c08e726u: goto P_0c08e726;
case 0x0c08e728u: goto P_0c08e728;
case 0x0c08e72au: goto P_0c08e72a;
case 0x0c08e72cu: goto P_0c08e72c;
case 0x0c08e72eu: goto P_0c08e72e;
case 0x0c08e730u: goto P_0c08e730;
case 0x0c08e732u: goto P_0c08e732;
case 0x0c08e734u: goto P_0c08e734;
case 0x0c08e736u: goto P_0c08e736;
case 0x0c08e738u: goto P_0c08e738;
case 0x0c08e73au: goto P_0c08e73a;
case 0x0c08e73cu: goto P_0c08e73c;
case 0x0c08e73eu: goto P_0c08e73e;
case 0x0c08e740u: goto P_0c08e740;
case 0x0c08e742u: goto P_0c08e742;
case 0x0c08e744u: goto P_0c08e744;
case 0x0c08e746u: goto P_0c08e746;
case 0x0c08e748u: goto P_0c08e748;
case 0x0c08e74au: goto P_0c08e74a;
case 0x0c08e74cu: goto P_0c08e74c;
case 0x0c08e74eu: goto P_0c08e74e;
case 0x0c08e750u: goto P_0c08e750;
case 0x0c08e752u: goto P_0c08e752;
case 0x0c08e754u: goto P_0c08e754;
case 0x0c08e774u: goto P_0c08e774;
case 0x0c08e776u: goto P_0c08e776;
case 0x0c08e778u: goto P_0c08e778;
case 0x0c08e77au: goto P_0c08e77a;
case 0x0c08e77cu: goto P_0c08e77c;
case 0x0c08e77eu: goto P_0c08e77e;
case 0x0c08e780u: goto P_0c08e780;
case 0x0c08e782u: goto P_0c08e782;
case 0x0c08e784u: goto P_0c08e784;
case 0x0c08e786u: goto P_0c08e786;
case 0x0c08e788u: goto P_0c08e788;
case 0x0c08e78au: goto P_0c08e78a;
case 0x0c08e78cu: goto P_0c08e78c;
case 0x0c08e78eu: goto P_0c08e78e;
case 0x0c08e790u: goto P_0c08e790;
case 0x0c08e792u: goto P_0c08e792;
case 0x0c08e794u: goto P_0c08e794;
case 0x0c08e796u: goto P_0c08e796;
case 0x0c08e798u: goto P_0c08e798;
case 0x0c08e79au: goto P_0c08e79a;
case 0x0c08e79cu: goto P_0c08e79c;
case 0x0c08e79eu: goto P_0c08e79e;
case 0x0c08e7a0u: goto P_0c08e7a0;
case 0x0c08e7a2u: goto P_0c08e7a2;
case 0x0c08e7a4u: goto P_0c08e7a4;
case 0x0c08e7a6u: goto P_0c08e7a6;
case 0x0c08e7a8u: goto P_0c08e7a8;
case 0x0c08e7aau: goto P_0c08e7aa;
case 0x0c08e7acu: goto P_0c08e7ac;
case 0x0c08e7aeu: goto P_0c08e7ae;
case 0x0c08e7b0u: goto P_0c08e7b0;
case 0x0c08e7b2u: goto P_0c08e7b2;
case 0x0c08e7b4u: goto P_0c08e7b4;
case 0x0c08e7b6u: goto P_0c08e7b6;
case 0x0c08e7b8u: goto P_0c08e7b8;
case 0x0c08e7bau: goto P_0c08e7ba;
case 0x0c08e7bcu: goto P_0c08e7bc;
case 0x0c08e7beu: goto P_0c08e7be;
case 0x0c08e7c0u: goto P_0c08e7c0;
case 0x0c08e7c2u: goto P_0c08e7c2;
case 0x0c08e7c4u: goto P_0c08e7c4;
case 0x0c08e7c6u: goto P_0c08e7c6;
case 0x0c08e7c8u: goto P_0c08e7c8;
case 0x0c08e7cau: goto P_0c08e7ca;
case 0x0c08e7ccu: goto P_0c08e7cc;
case 0x0c08e7ceu: goto P_0c08e7ce;
case 0x0c08e7d0u: goto P_0c08e7d0;
case 0x0c08e7d2u: goto P_0c08e7d2;
case 0x0c08e7d4u: goto P_0c08e7d4;
case 0x0c08e7d6u: goto P_0c08e7d6;
case 0x0c08e7d8u: goto P_0c08e7d8;
case 0x0c08e7dau: goto P_0c08e7da;
case 0x0c08e7dcu: goto P_0c08e7dc;
case 0x0c08e7deu: goto P_0c08e7de;
case 0x0c08e7e0u: goto P_0c08e7e0;
case 0x0c08e7e2u: goto P_0c08e7e2;
case 0x0c08e7e4u: goto P_0c08e7e4;
case 0x0c08e7e6u: goto P_0c08e7e6;
case 0x0c08e7e8u: goto P_0c08e7e8;
case 0x0c08e7eau: goto P_0c08e7ea;
case 0x0c08e7ecu: goto P_0c08e7ec;
case 0x0c08e7eeu: goto P_0c08e7ee;
case 0x0c08e7f0u: goto P_0c08e7f0;
case 0x0c08e7f2u: goto P_0c08e7f2;
case 0x0c08e7f4u: goto P_0c08e7f4;
case 0x0c08e7f6u: goto P_0c08e7f6;
case 0x0c08e7f8u: goto P_0c08e7f8;
case 0x0c08e7fau: goto P_0c08e7fa;
case 0x0c08e7fcu: goto P_0c08e7fc;
case 0x0c08e7feu: goto P_0c08e7fe;
case 0x0c08e800u: goto P_0c08e800;
case 0x0c08e802u: goto P_0c08e802;
case 0x0c08e804u: goto P_0c08e804;
case 0x0c08e806u: goto P_0c08e806;
case 0x0c08e808u: goto P_0c08e808;
case 0x0c08e80au: goto P_0c08e80a;
case 0x0c08e80cu: goto P_0c08e80c;
case 0x0c08e80eu: goto P_0c08e80e;
case 0x0c08e810u: goto P_0c08e810;
case 0x0c08e812u: goto P_0c08e812;
case 0x0c08e814u: goto P_0c08e814;
case 0x0c08e816u: goto P_0c08e816;
case 0x0c08e818u: goto P_0c08e818;
case 0x0c08e81au: goto P_0c08e81a;
case 0x0c08e81cu: goto P_0c08e81c;
case 0x0c08e81eu: goto P_0c08e81e;
case 0x0c08e820u: goto P_0c08e820;
case 0x0c08e822u: goto P_0c08e822;
case 0x0c08e824u: goto P_0c08e824;
case 0x0c08e826u: goto P_0c08e826;
case 0x0c08e828u: goto P_0c08e828;
case 0x0c08e82au: goto P_0c08e82a;
case 0x0c08e82cu: goto P_0c08e82c;
case 0x0c08e82eu: goto P_0c08e82e;
case 0x0c08e830u: goto P_0c08e830;
case 0x0c08e832u: goto P_0c08e832;
case 0x0c08e834u: goto P_0c08e834;
case 0x0c08e836u: goto P_0c08e836;
case 0x0c08e838u: goto P_0c08e838;
case 0x0c08e83au: goto P_0c08e83a;
case 0x0c08e83cu: goto P_0c08e83c;
case 0x0c08e83eu: goto P_0c08e83e;
case 0x0c08e840u: goto P_0c08e840;
case 0x0c08e842u: goto P_0c08e842;
case 0x0c08e844u: goto P_0c08e844;
case 0x0c08e846u: goto P_0c08e846;
case 0x0c08e860u: goto P_0c08e860;
case 0x0c08e862u: goto P_0c08e862;
case 0x0c08e864u: goto P_0c08e864;
case 0x0c08e866u: goto P_0c08e866;
case 0x0c08e868u: goto P_0c08e868;
case 0x0c08e86au: goto P_0c08e86a;
case 0x0c08e86cu: goto P_0c08e86c;
case 0x0c08e86eu: goto P_0c08e86e;
case 0x0c08e870u: goto P_0c08e870;
case 0x0c08e872u: goto P_0c08e872;
case 0x0c08e874u: goto P_0c08e874;
case 0x0c08e876u: goto P_0c08e876;
case 0x0c08e878u: goto P_0c08e878;
case 0x0c08e87au: goto P_0c08e87a;
case 0x0c08e87cu: goto P_0c08e87c;
case 0x0c08e87eu: goto P_0c08e87e;
case 0x0c08e880u: goto P_0c08e880;
case 0x0c08e882u: goto P_0c08e882;
case 0x0c08e884u: goto P_0c08e884;
case 0x0c08e886u: goto P_0c08e886;
case 0x0c08e888u: goto P_0c08e888;
case 0x0c08e88au: goto P_0c08e88a;
case 0x0c08e88cu: goto P_0c08e88c;
case 0x0c08e88eu: goto P_0c08e88e;
case 0x0c08e890u: goto P_0c08e890;
case 0x0c08e892u: goto P_0c08e892;
case 0x0c08e894u: goto P_0c08e894;
case 0x0c08e896u: goto P_0c08e896;
case 0x0c08e898u: goto P_0c08e898;
case 0x0c08e89au: goto P_0c08e89a;
case 0x0c08e89cu: goto P_0c08e89c;
case 0x0c08e89eu: goto P_0c08e89e;
case 0x0c08e8a0u: goto P_0c08e8a0;
case 0x0c08e8a2u: goto P_0c08e8a2;
case 0x0c08e8a4u: goto P_0c08e8a4;
case 0x0c08e8a6u: goto P_0c08e8a6;
case 0x0c08e8a8u: goto P_0c08e8a8;
case 0x0c08e8aau: goto P_0c08e8aa;
case 0x0c08e8acu: goto P_0c08e8ac;
case 0x0c08e8aeu: goto P_0c08e8ae;
case 0x0c08e8b0u: goto P_0c08e8b0;
case 0x0c08e8b2u: goto P_0c08e8b2;
case 0x0c08e8b4u: goto P_0c08e8b4;
case 0x0c08e8b6u: goto P_0c08e8b6;
case 0x0c08e8b8u: goto P_0c08e8b8;
case 0x0c08e8bau: goto P_0c08e8ba;
case 0x0c08e8bcu: goto P_0c08e8bc;
case 0x0c08e8beu: goto P_0c08e8be;
case 0x0c08e8c0u: goto P_0c08e8c0;
case 0x0c08e8c2u: goto P_0c08e8c2;
case 0x0c08e8c4u: goto P_0c08e8c4;
case 0x0c08e8c6u: goto P_0c08e8c6;
case 0x0c08e8c8u: goto P_0c08e8c8;
case 0x0c08e8cau: goto P_0c08e8ca;
case 0x0c08e8ccu: goto P_0c08e8cc;
case 0x0c08e8ceu: goto P_0c08e8ce;
case 0x0c08e8d0u: goto P_0c08e8d0;
case 0x0c08e8d2u: goto P_0c08e8d2;
case 0x0c08e8d4u: goto P_0c08e8d4;
case 0x0c08e8d6u: goto P_0c08e8d6;
case 0x0c08e8d8u: goto P_0c08e8d8;
case 0x0c08e8dau: goto P_0c08e8da;
case 0x0c08e8dcu: goto P_0c08e8dc;
case 0x0c08e8deu: goto P_0c08e8de;
case 0x0c08e8e0u: goto P_0c08e8e0;
case 0x0c08e8e2u: goto P_0c08e8e2;
case 0x0c08e8e4u: goto P_0c08e8e4;
case 0x0c08e8e6u: goto P_0c08e8e6;
case 0x0c08e8e8u: goto P_0c08e8e8;
case 0x0c08e8eau: goto P_0c08e8ea;
case 0x0c08e8ecu: goto P_0c08e8ec;
case 0x0c08e8eeu: goto P_0c08e8ee;
case 0x0c08e8f0u: goto P_0c08e8f0;
case 0x0c08e8f2u: goto P_0c08e8f2;
case 0x0c08e8f4u: goto P_0c08e8f4;
case 0x0c08e8f6u: goto P_0c08e8f6;
case 0x0c08e8f8u: goto P_0c08e8f8;
case 0x0c08e8fau: goto P_0c08e8fa;
case 0x0c08e8fcu: goto P_0c08e8fc;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08dee6: /* original 2fe6, guest PC 0x0c08dee6 */
if(!s->budget--) { s->failed_pc=0x0c08dee6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dee8;
P_0c08dee8: /* original 6e43, guest PC 0x0c08dee8 */
if(!s->budget--) { s->failed_pc=0x0c08dee8u; return 0; }
r[14]=r[4];
goto P_0c08deea;
P_0c08deea: /* original e060, guest PC 0x0c08deea */
if(!s->budget--) { s->failed_pc=0x0c08deeau; return 0; }
r[0]=0x00000060u;
goto P_0c08deec;
P_0c08deec: /* original 2fd6, guest PC 0x0c08deec */
if(!s->budget--) { s->failed_pc=0x0c08deecu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08deee;
P_0c08deee: /* original 2fc6, guest PC 0x0c08deee */
if(!s->budget--) { s->failed_pc=0x0c08deeeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08def0;
P_0c08def0: /* original 4f22, guest PC 0x0c08def0 */
if(!s->budget--) { s->failed_pc=0x0c08def0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08def2;
P_0c08def2: /* original 7fe8, guest PC 0x0c08def2 */
if(!s->budget--) { s->failed_pc=0x0c08def2u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c08def4;
P_0c08def4: /* original 1f52, guest PC 0x0c08def4 */
if(!s->budget--) { s->failed_pc=0x0c08def4u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c08def6;
P_0c08def6: /* original 1f61, guest PC 0x0c08def6 */
if(!s->budget--) { s->failed_pc=0x0c08def6u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c08def8;
P_0c08def8: /* original 2f72, guest PC 0x0c08def8 */
if(!s->budget--) { s->failed_pc=0x0c08def8u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c08defa;
P_0c08defa: /* original 0dec, guest PC 0x0c08defa */
if(!s->budget--) { s->failed_pc=0x0c08defau; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08defc;
P_0c08defc: /* original e00c, guest PC 0x0c08defc */
if(!s->budget--) { s->failed_pc=0x0c08defcu; return 0; }
r[0]=0x0000000cu;
goto P_0c08defe;
P_0c08defe: /* original d211, guest PC 0x0c08defe */
if(!s->budget--) { s->failed_pc=0x0c08defeu; return 0; }
r[2]=read(ram,0x0c08df44u,4);
goto P_0c08df00;
P_0c08df00: /* original 6ddc, guest PC 0x0c08df00 */
if(!s->budget--) { s->failed_pc=0x0c08df00u; return 0; }
r[13]=r[13]&255u;
goto P_0c08df02;
P_0c08df02: /* original 63d3, guest PC 0x0c08df02 */
if(!s->budget--) { s->failed_pc=0x0c08df02u; return 0; }
r[3]=r[13];
goto P_0c08df04;
P_0c08df04: /* original 4d00, guest PC 0x0c08df04 */
if(!s->budget--) { s->failed_pc=0x0c08df04u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c08df06;
P_0c08df06: /* original 3d3c, guest PC 0x0c08df06 */
if(!s->budget--) { s->failed_pc=0x0c08df06u; return 0; }
r[13]+=r[3];
goto P_0c08df08;
P_0c08df08: /* original 4d08, guest PC 0x0c08df08 */
if(!s->budget--) { s->failed_pc=0x0c08df08u; return 0; }
r[13]<<=2;
goto P_0c08df0a;
P_0c08df0a: /* original 6ddf, guest PC 0x0c08df0a */
if(!s->budget--) { s->failed_pc=0x0c08df0au; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c08df0c;
P_0c08df0c: /* original 3d2c, guest PC 0x0c08df0c */
if(!s->budget--) { s->failed_pc=0x0c08df0cu; return 0; }
r[13]+=r[2];
goto P_0c08df0e;
P_0c08df0e: /* original f3d8, guest PC 0x0c08df0e */
if(!s->budget--) { s->failed_pc=0x0c08df0eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c08df10;
P_0c08df10: /* original ff37, guest PC 0x0c08df10 */
if(!s->budget--) { s->failed_pc=0x0c08df10u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08df12;
P_0c08df12: /* original e004, guest PC 0x0c08df12 */
if(!s->budget--) { s->failed_pc=0x0c08df12u; return 0; }
r[0]=0x00000004u;
goto P_0c08df14;
P_0c08df14: /* original f3d6, guest PC 0x0c08df14 */
if(!s->budget--) { s->failed_pc=0x0c08df14u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c08df16;
P_0c08df16: /* original e010, guest PC 0x0c08df16 */
if(!s->budget--) { s->failed_pc=0x0c08df16u; return 0; }
r[0]=0x00000010u;
goto P_0c08df18;
P_0c08df18: /* original ff37, guest PC 0x0c08df18 */
if(!s->budget--) { s->failed_pc=0x0c08df18u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08df1a;
P_0c08df1a: /* original e008, guest PC 0x0c08df1a */
if(!s->budget--) { s->failed_pc=0x0c08df1au; return 0; }
r[0]=0x00000008u;
goto P_0c08df1c;
P_0c08df1c: /* original f3d6, guest PC 0x0c08df1c */
if(!s->budget--) { s->failed_pc=0x0c08df1cu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c08df1e;
P_0c08df1e: /* original e014, guest PC 0x0c08df1e */
if(!s->budget--) { s->failed_pc=0x0c08df1eu; return 0; }
r[0]=0x00000014u;
goto P_0c08df20;
P_0c08df20: /* original ff37, guest PC 0x0c08df20 */
if(!s->budget--) { s->failed_pc=0x0c08df20u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08df22;
P_0c08df22: /* original d310, guest PC 0x0c08df22 */
if(!s->budget--) { s->failed_pc=0x0c08df22u; return 0; }
r[3]=read(ram,0x0c08df64u,4);
goto P_0c08df24;
P_0c08df24: /* original d00e, guest PC 0x0c08df24 */
if(!s->budget--) { s->failed_pc=0x0c08df24u; return 0; }
r[0]=read(ram,0x0c08df60u,4);
goto P_0c08df26;
P_0c08df26: /* original 6102, guest PC 0x0c08df26 */
if(!s->budget--) { s->failed_pc=0x0c08df26u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c08df28;
P_0c08df28: /* original 2138, guest PC 0x0c08df28 */
if(!s->budget--) { s->failed_pc=0x0c08df28u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c08df2a;
P_0c08df2a: /* original 891f, guest PC 0x0c08df2a */
if(!s->budget--) { s->failed_pc=0x0c08df2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08df6c; }
goto P_0c08df2c;
P_0c08df2c: /* original e060, guest PC 0x0c08df2c */
if(!s->budget--) { s->failed_pc=0x0c08df2cu; return 0; }
r[0]=0x00000060u;
goto P_0c08df2e;
P_0c08df2e: /* original 0cec, guest PC 0x0c08df2e */
if(!s->budget--) { s->failed_pc=0x0c08df2eu; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08df30;
P_0c08df30: /* original d00d, guest PC 0x0c08df30 */
if(!s->budget--) { s->failed_pc=0x0c08df30u; return 0; }
r[0]=read(ram,0x0c08df68u,4);
goto P_0c08df32;
P_0c08df32: /* original 6ccc, guest PC 0x0c08df32 */
if(!s->budget--) { s->failed_pc=0x0c08df32u; return 0; }
r[12]=r[12]&255u;
goto P_0c08df34;
P_0c08df34: /* original a01f, guest PC 0x0c08df34 */
if(!s->budget--) { s->failed_pc=0x0c08df34u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c08df76;
P_0c08df36: /* original 4c00, guest PC 0x0c08df36 */
if(!s->budget--) { s->failed_pc=0x0c08df36u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
if(!vf3_matrix_family(0x0c08df38u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08df38u; return 0; } return 1;
P_0c08df6c: /* original e060, guest PC 0x0c08df6c */
if(!s->budget--) { s->failed_pc=0x0c08df6cu; return 0; }
r[0]=0x00000060u;
goto P_0c08df6e;
P_0c08df6e: /* original 0cec, guest PC 0x0c08df6e */
if(!s->budget--) { s->failed_pc=0x0c08df6eu; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08df70;
P_0c08df70: /* original d023, guest PC 0x0c08df70 */
if(!s->budget--) { s->failed_pc=0x0c08df70u; return 0; }
r[0]=read(ram,0x0c08e000u,4);
goto P_0c08df72;
P_0c08df72: /* original 6ccc, guest PC 0x0c08df72 */
if(!s->budget--) { s->failed_pc=0x0c08df72u; return 0; }
r[12]=r[12]&255u;
goto P_0c08df74;
P_0c08df74: /* original 4c00, guest PC 0x0c08df74 */
if(!s->budget--) { s->failed_pc=0x0c08df74u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c08df76;
P_0c08df76: /* original d323, guest PC 0x0c08df76 */
if(!s->budget--) { s->failed_pc=0x0c08df76u; return 0; }
r[3]=read(ram,0x0c08e004u,4);
goto P_0c08df78;
P_0c08df78: /* original 0ccd, guest PC 0x0c08df78 */
if(!s->budget--) { s->failed_pc=0x0c08df78u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c08df7a;
P_0c08df7a: /* original 430b, guest PC 0x0c08df7a */
if(!s->budget--) { s->failed_pc=0x0c08df7au; return 0; }
target=r[3];
r[16]=code_base|0x0c08df7eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08df7eu) { target=s->pc; goto dispatch; }
goto P_0c08df7e;
P_0c08df7c: /* original e400, guest PC 0x0c08df7c */
if(!s->budget--) { s->failed_pc=0x0c08df7cu; return 0; }
r[4]=0x00000000u;
goto P_0c08df7e;
P_0c08df7e: /* original d222, guest PC 0x0c08df7e */
if(!s->budget--) { s->failed_pc=0x0c08df7eu; return 0; }
r[2]=read(ram,0x0c08e008u,4);
goto P_0c08df80;
P_0c08df80: /* original 420b, guest PC 0x0c08df80 */
if(!s->budget--) { s->failed_pc=0x0c08df80u; return 0; }
target=r[2];
r[16]=code_base|0x0c08df84u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08df84u) { target=s->pc; goto dispatch; }
goto P_0c08df84;
P_0c08df82: /* original 64d3, guest PC 0x0c08df82 */
if(!s->budget--) { s->failed_pc=0x0c08df82u; return 0; }
r[4]=r[13];
goto P_0c08df84;
P_0c08df84: /* original d321, guest PC 0x0c08df84 */
if(!s->budget--) { s->failed_pc=0x0c08df84u; return 0; }
r[3]=read(ram,0x0c08e00cu,4);
goto P_0c08df86;
P_0c08df86: /* original 430b, guest PC 0x0c08df86 */
if(!s->budget--) { s->failed_pc=0x0c08df86u; return 0; }
target=r[3];
r[16]=code_base|0x0c08df8au;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08df8au) { target=s->pc; goto dispatch; }
goto P_0c08df8a;
P_0c08df88: /* original 64f2, guest PC 0x0c08df88 */
if(!s->budget--) { s->failed_pc=0x0c08df88u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c08df8a;
P_0c08df8a: /* original d321, guest PC 0x0c08df8a */
if(!s->budget--) { s->failed_pc=0x0c08df8au; return 0; }
r[3]=read(ram,0x0c08e010u,4);
goto P_0c08df8c;
P_0c08df8c: /* original 54fa, guest PC 0x0c08df8c */
if(!s->budget--) { s->failed_pc=0x0c08df8cu; return 0; }
r[4]=read(ram,r[15]+40,4);
goto P_0c08df8e;
P_0c08df8e: /* original 430b, guest PC 0x0c08df8e */
if(!s->budget--) { s->failed_pc=0x0c08df8eu; return 0; }
target=r[3];
r[16]=code_base|0x0c08df92u;
r[4]=0u-r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08df92u) { target=s->pc; goto dispatch; }
goto P_0c08df92;
P_0c08df90: /* original 644b, guest PC 0x0c08df90 */
if(!s->budget--) { s->failed_pc=0x0c08df90u; return 0; }
r[4]=0u-r[4];
goto P_0c08df92;
P_0c08df92: /* original d220, guest PC 0x0c08df92 */
if(!s->budget--) { s->failed_pc=0x0c08df92u; return 0; }
r[2]=read(ram,0x0c08e014u,4);
goto P_0c08df94;
P_0c08df94: /* original 420b, guest PC 0x0c08df94 */
if(!s->budget--) { s->failed_pc=0x0c08df94u; return 0; }
target=r[2];
r[16]=code_base|0x0c08df98u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08df98u) { target=s->pc; goto dispatch; }
goto P_0c08df98;
P_0c08df96: /* original 64c3, guest PC 0x0c08df96 */
if(!s->budget--) { s->failed_pc=0x0c08df96u; return 0; }
r[4]=r[12];
goto P_0c08df98;
P_0c08df98: /* original d31f, guest PC 0x0c08df98 */
if(!s->budget--) { s->failed_pc=0x0c08df98u; return 0; }
r[3]=read(ram,0x0c08e018u,4);
goto P_0c08df9a;
P_0c08df9a: /* original 430b, guest PC 0x0c08df9a */
if(!s->budget--) { s->failed_pc=0x0c08df9au; return 0; }
target=r[3];
r[16]=code_base|0x0c08df9eu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08df9eu) { target=s->pc; goto dispatch; }
goto P_0c08df9e;
P_0c08df9c: /* original e401, guest PC 0x0c08df9c */
if(!s->budget--) { s->failed_pc=0x0c08df9cu; return 0; }
r[4]=0x00000001u;
goto P_0c08df9e;
P_0c08df9e: /* original e014, guest PC 0x0c08df9e */
if(!s->budget--) { s->failed_pc=0x0c08df9eu; return 0; }
r[0]=0x00000014u;
goto P_0c08dfa0;
P_0c08dfa0: /* original d31e, guest PC 0x0c08dfa0 */
if(!s->budget--) { s->failed_pc=0x0c08dfa0u; return 0; }
r[3]=read(ram,0x0c08e01cu,4);
goto P_0c08dfa2;
P_0c08dfa2: /* original f6f6, guest PC 0x0c08dfa2 */
if(!s->budget--) { s->failed_pc=0x0c08dfa2u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c08dfa4;
P_0c08dfa4: /* original e010, guest PC 0x0c08dfa4 */
if(!s->budget--) { s->failed_pc=0x0c08dfa4u; return 0; }
r[0]=0x00000010u;
goto P_0c08dfa6;
P_0c08dfa6: /* original f5f6, guest PC 0x0c08dfa6 */
if(!s->budget--) { s->failed_pc=0x0c08dfa6u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c08dfa8;
P_0c08dfa8: /* original e00c, guest PC 0x0c08dfa8 */
if(!s->budget--) { s->failed_pc=0x0c08dfa8u; return 0; }
r[0]=0x0000000cu;
goto P_0c08dfaa;
P_0c08dfaa: /* original f54d, guest PC 0x0c08dfaa */
if(!s->budget--) { s->failed_pc=0x0c08dfaau; return 0; }
fr[5]^=0x80000000u;
goto P_0c08dfac;
P_0c08dfac: /* original 430b, guest PC 0x0c08dfac */
if(!s->budget--) { s->failed_pc=0x0c08dfacu; return 0; }
target=r[3];
r[16]=code_base|0x0c08dfb0u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08dfb0u) { target=s->pc; goto dispatch; }
goto P_0c08dfb0;
P_0c08dfae: /* original f4f6, guest PC 0x0c08dfae */
if(!s->budget--) { s->failed_pc=0x0c08dfaeu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08dfb0;
P_0c08dfb0: /* original d316, guest PC 0x0c08dfb0 */
if(!s->budget--) { s->failed_pc=0x0c08dfb0u; return 0; }
r[3]=read(ram,0x0c08e00cu,4);
goto P_0c08dfb2;
P_0c08dfb2: /* original 430b, guest PC 0x0c08dfb2 */
if(!s->budget--) { s->failed_pc=0x0c08dfb2u; return 0; }
target=r[3];
r[16]=code_base|0x0c08dfb6u;
r[4]=read(ram,r[15]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08dfb6u) { target=s->pc; goto dispatch; }
goto P_0c08dfb6;
P_0c08dfb4: /* original 54fb, guest PC 0x0c08dfb4 */
if(!s->budget--) { s->failed_pc=0x0c08dfb4u; return 0; }
r[4]=read(ram,r[15]+44,4);
goto P_0c08dfb6;
P_0c08dfb6: /* original d316, guest PC 0x0c08dfb6 */
if(!s->budget--) { s->failed_pc=0x0c08dfb6u; return 0; }
r[3]=read(ram,0x0c08e010u,4);
goto P_0c08dfb8;
P_0c08dfb8: /* original 54fc, guest PC 0x0c08dfb8 */
if(!s->budget--) { s->failed_pc=0x0c08dfb8u; return 0; }
r[4]=read(ram,r[15]+48,4);
goto P_0c08dfba;
P_0c08dfba: /* original 430b, guest PC 0x0c08dfba */
if(!s->budget--) { s->failed_pc=0x0c08dfbau; return 0; }
target=r[3];
r[16]=code_base|0x0c08dfbeu;
r[4]=0u-r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08dfbeu) { target=s->pc; goto dispatch; }
goto P_0c08dfbe;
P_0c08dfbc: /* original 644b, guest PC 0x0c08dfbc */
if(!s->budget--) { s->failed_pc=0x0c08dfbcu; return 0; }
r[4]=0u-r[4];
goto P_0c08dfbe;
P_0c08dfbe: /* original d215, guest PC 0x0c08dfbe */
if(!s->budget--) { s->failed_pc=0x0c08dfbeu; return 0; }
r[2]=read(ram,0x0c08e014u,4);
goto P_0c08dfc0;
P_0c08dfc0: /* original 420b, guest PC 0x0c08dfc0 */
if(!s->budget--) { s->failed_pc=0x0c08dfc0u; return 0; }
target=r[2];
r[16]=code_base|0x0c08dfc4u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08dfc4u) { target=s->pc; goto dispatch; }
goto P_0c08dfc4;
P_0c08dfc2: /* original 64c3, guest PC 0x0c08dfc2 */
if(!s->budget--) { s->failed_pc=0x0c08dfc2u; return 0; }
r[4]=r[12];
goto P_0c08dfc4;
P_0c08dfc4: /* original 9016, guest PC 0x0c08dfc4 */
if(!s->budget--) { s->failed_pc=0x0c08dfc4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dff4u,2);
goto P_0c08dfc6;
P_0c08dfc6: /* original 53f2, guest PC 0x0c08dfc6 */
if(!s->budget--) { s->failed_pc=0x0c08dfc6u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c08dfc8;
P_0c08dfc8: /* original 0e35, guest PC 0x0c08dfc8 */
if(!s->budget--) { s->failed_pc=0x0c08dfc8u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c08dfca;
P_0c08dfca: /* original 9014, guest PC 0x0c08dfca */
if(!s->budget--) { s->failed_pc=0x0c08dfcau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dff6u,2);
goto P_0c08dfcc;
P_0c08dfcc: /* original 52f1, guest PC 0x0c08dfcc */
if(!s->budget--) { s->failed_pc=0x0c08dfccu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c08dfce;
P_0c08dfce: /* original 0e25, guest PC 0x0c08dfce */
if(!s->budget--) { s->failed_pc=0x0c08dfceu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c08dfd0;
P_0c08dfd0: /* original 9012, guest PC 0x0c08dfd0 */
if(!s->budget--) { s->failed_pc=0x0c08dfd0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dff8u,2);
goto P_0c08dfd2;
P_0c08dfd2: /* original 63f2, guest PC 0x0c08dfd2 */
if(!s->budget--) { s->failed_pc=0x0c08dfd2u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c08dfd4;
P_0c08dfd4: /* original 0e35, guest PC 0x0c08dfd4 */
if(!s->budget--) { s->failed_pc=0x0c08dfd4u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c08dfd6;
P_0c08dfd6: /* original 9010, guest PC 0x0c08dfd6 */
if(!s->budget--) { s->failed_pc=0x0c08dfd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dffau,2);
goto P_0c08dfd8;
P_0c08dfd8: /* original 52fa, guest PC 0x0c08dfd8 */
if(!s->budget--) { s->failed_pc=0x0c08dfd8u; return 0; }
r[2]=read(ram,r[15]+40,4);
goto P_0c08dfda;
P_0c08dfda: /* original 0e25, guest PC 0x0c08dfda */
if(!s->budget--) { s->failed_pc=0x0c08dfdau; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c08dfdc;
P_0c08dfdc: /* original 53fb, guest PC 0x0c08dfdc */
if(!s->budget--) { s->failed_pc=0x0c08dfdcu; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c08dfde;
P_0c08dfde: /* original 900d, guest PC 0x0c08dfde */
if(!s->budget--) { s->failed_pc=0x0c08dfdeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dffcu,2);
goto P_0c08dfe0;
P_0c08dfe0: /* original 0e35, guest PC 0x0c08dfe0 */
if(!s->budget--) { s->failed_pc=0x0c08dfe0u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c08dfe2;
P_0c08dfe2: /* original 52fc, guest PC 0x0c08dfe2 */
if(!s->budget--) { s->failed_pc=0x0c08dfe2u; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c08dfe4;
P_0c08dfe4: /* original 7f18, guest PC 0x0c08dfe4 */
if(!s->budget--) { s->failed_pc=0x0c08dfe4u; return 0; }
r[15]+=0x00000018u;
goto P_0c08dfe6;
P_0c08dfe6: /* original 4f26, guest PC 0x0c08dfe6 */
if(!s->budget--) { s->failed_pc=0x0c08dfe6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08dfe8;
P_0c08dfe8: /* original 9009, guest PC 0x0c08dfe8 */
if(!s->budget--) { s->failed_pc=0x0c08dfe8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dffeu,2);
goto P_0c08dfea;
P_0c08dfea: /* original 0e25, guest PC 0x0c08dfea */
if(!s->budget--) { s->failed_pc=0x0c08dfeau; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c08dfec;
P_0c08dfec: /* original 6cf6, guest PC 0x0c08dfec */
if(!s->budget--) { s->failed_pc=0x0c08dfecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08dfee;
P_0c08dfee: /* original 6df6, guest PC 0x0c08dfee */
if(!s->budget--) { s->failed_pc=0x0c08dfeeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08dff0;
P_0c08dff0: /* original 000b, guest PC 0x0c08dff0 */
if(!s->budget--) { s->failed_pc=0x0c08dff0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08dff2: /* original 6ef6, guest PC 0x0c08dff2 */
if(!s->budget--) { s->failed_pc=0x0c08dff2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08dff4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08dff4u; return 0; } return 1;
P_0c08e5c4: /* original 2fe6, guest PC 0x0c08e5c4 */
if(!s->budget--) { s->failed_pc=0x0c08e5c4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08e5c6;
P_0c08e5c6: /* original e503, guest PC 0x0c08e5c6 */
if(!s->budget--) { s->failed_pc=0x0c08e5c6u; return 0; }
r[5]=0x00000003u;
goto P_0c08e5c8;
P_0c08e5c8: /* original 2fd6, guest PC 0x0c08e5c8 */
if(!s->budget--) { s->failed_pc=0x0c08e5c8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08e5ca;
P_0c08e5ca: /* original 2fc6, guest PC 0x0c08e5ca */
if(!s->budget--) { s->failed_pc=0x0c08e5cau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08e5cc;
P_0c08e5cc: /* original 2fb6, guest PC 0x0c08e5cc */
if(!s->budget--) { s->failed_pc=0x0c08e5ccu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08e5ce;
P_0c08e5ce: /* original 4f22, guest PC 0x0c08e5ce */
if(!s->budget--) { s->failed_pc=0x0c08e5ceu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08e5d0;
P_0c08e5d0: /* original dd2b, guest PC 0x0c08e5d0 */
if(!s->budget--) { s->failed_pc=0x0c08e5d0u; return 0; }
r[13]=read(ram,0x0c08e680u,4);
goto P_0c08e5d2;
P_0c08e5d2: /* original de2a, guest PC 0x0c08e5d2 */
if(!s->budget--) { s->failed_pc=0x0c08e5d2u; return 0; }
r[14]=read(ram,0x0c08e67cu,4);
goto P_0c08e5d4;
P_0c08e5d4: /* original 4d0b, guest PC 0x0c08e5d4 */
if(!s->budget--) { s->failed_pc=0x0c08e5d4u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e5d8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e5d8u) { target=s->pc; goto dispatch; }
goto P_0c08e5d8;
P_0c08e5d6: /* original 64e3, guest PC 0x0c08e5d6 */
if(!s->budget--) { s->failed_pc=0x0c08e5d6u; return 0; }
r[4]=r[14];
goto P_0c08e5d8;
P_0c08e5d8: /* original 64e3, guest PC 0x0c08e5d8 */
if(!s->budget--) { s->failed_pc=0x0c08e5d8u; return 0; }
r[4]=r[14];
goto P_0c08e5da;
P_0c08e5da: /* original e503, guest PC 0x0c08e5da */
if(!s->budget--) { s->failed_pc=0x0c08e5dau; return 0; }
r[5]=0x00000003u;
goto P_0c08e5dc;
P_0c08e5dc: /* original 4d0b, guest PC 0x0c08e5dc */
if(!s->budget--) { s->failed_pc=0x0c08e5dcu; return 0; }
target=r[13];
r[16]=code_base|0x0c08e5e0u;
r[4]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e5e0u) { target=s->pc; goto dispatch; }
goto P_0c08e5e0;
P_0c08e5de: /* original 7401, guest PC 0x0c08e5de */
if(!s->budget--) { s->failed_pc=0x0c08e5deu; return 0; }
r[4]+=0x00000001u;
goto P_0c08e5e0;
P_0c08e5e0: /* original 64e3, guest PC 0x0c08e5e0 */
if(!s->budget--) { s->failed_pc=0x0c08e5e0u; return 0; }
r[4]=r[14];
goto P_0c08e5e2;
P_0c08e5e2: /* original e501, guest PC 0x0c08e5e2 */
if(!s->budget--) { s->failed_pc=0x0c08e5e2u; return 0; }
r[5]=0x00000001u;
goto P_0c08e5e4;
P_0c08e5e4: /* original 4d0b, guest PC 0x0c08e5e4 */
if(!s->budget--) { s->failed_pc=0x0c08e5e4u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e5e8u;
r[4]+=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e5e8u) { target=s->pc; goto dispatch; }
goto P_0c08e5e8;
P_0c08e5e6: /* original 7402, guest PC 0x0c08e5e6 */
if(!s->budget--) { s->failed_pc=0x0c08e5e6u; return 0; }
r[4]+=0x00000002u;
goto P_0c08e5e8;
P_0c08e5e8: /* original 9b46, guest PC 0x0c08e5e8 */
if(!s->budget--) { s->failed_pc=0x0c08e5e8u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e678u,2);
goto P_0c08e5ea;
P_0c08e5ea: /* original 64e3, guest PC 0x0c08e5ea */
if(!s->budget--) { s->failed_pc=0x0c08e5eau; return 0; }
r[4]=r[14];
goto P_0c08e5ec;
P_0c08e5ec: /* original dc25, guest PC 0x0c08e5ec */
if(!s->budget--) { s->failed_pc=0x0c08e5ecu; return 0; }
r[12]=read(ram,0x0c08e684u,4);
goto P_0c08e5ee;
P_0c08e5ee: /* original 65b3, guest PC 0x0c08e5ee */
if(!s->budget--) { s->failed_pc=0x0c08e5eeu; return 0; }
r[5]=r[11];
goto P_0c08e5f0;
P_0c08e5f0: /* original 4c0b, guest PC 0x0c08e5f0 */
if(!s->budget--) { s->failed_pc=0x0c08e5f0u; return 0; }
target=r[12];
r[16]=code_base|0x0c08e5f4u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e5f4u) { target=s->pc; goto dispatch; }
goto P_0c08e5f4;
P_0c08e5f2: /* original 7404, guest PC 0x0c08e5f2 */
if(!s->budget--) { s->failed_pc=0x0c08e5f2u; return 0; }
r[4]+=0x00000004u;
goto P_0c08e5f4;
P_0c08e5f4: /* original 64e3, guest PC 0x0c08e5f4 */
if(!s->budget--) { s->failed_pc=0x0c08e5f4u; return 0; }
r[4]=r[14];
goto P_0c08e5f6;
P_0c08e5f6: /* original 65b3, guest PC 0x0c08e5f6 */
if(!s->budget--) { s->failed_pc=0x0c08e5f6u; return 0; }
r[5]=r[11];
goto P_0c08e5f8;
P_0c08e5f8: /* original 4c0b, guest PC 0x0c08e5f8 */
if(!s->budget--) { s->failed_pc=0x0c08e5f8u; return 0; }
target=r[12];
r[16]=code_base|0x0c08e5fcu;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e5fcu) { target=s->pc; goto dispatch; }
goto P_0c08e5fc;
P_0c08e5fa: /* original 7408, guest PC 0x0c08e5fa */
if(!s->budget--) { s->failed_pc=0x0c08e5fau; return 0; }
r[4]+=0x00000008u;
goto P_0c08e5fc;
P_0c08e5fc: /* original 64e3, guest PC 0x0c08e5fc */
if(!s->budget--) { s->failed_pc=0x0c08e5fcu; return 0; }
r[4]=r[14];
goto P_0c08e5fe;
P_0c08e5fe: /* original 65b3, guest PC 0x0c08e5fe */
if(!s->budget--) { s->failed_pc=0x0c08e5feu; return 0; }
r[5]=r[11];
goto P_0c08e600;
P_0c08e600: /* original 4c0b, guest PC 0x0c08e600 */
if(!s->budget--) { s->failed_pc=0x0c08e600u; return 0; }
target=r[12];
r[16]=code_base|0x0c08e604u;
r[4]+=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e604u) { target=s->pc; goto dispatch; }
goto P_0c08e604;
P_0c08e602: /* original 7406, guest PC 0x0c08e602 */
if(!s->budget--) { s->failed_pc=0x0c08e602u; return 0; }
r[4]+=0x00000006u;
goto P_0c08e604;
P_0c08e604: /* original 64e3, guest PC 0x0c08e604 */
if(!s->budget--) { s->failed_pc=0x0c08e604u; return 0; }
r[4]=r[14];
goto P_0c08e606;
P_0c08e606: /* original e501, guest PC 0x0c08e606 */
if(!s->budget--) { s->failed_pc=0x0c08e606u; return 0; }
r[5]=0x00000001u;
goto P_0c08e608;
P_0c08e608: /* original 4c0b, guest PC 0x0c08e608 */
if(!s->budget--) { s->failed_pc=0x0c08e608u; return 0; }
target=r[12];
r[16]=code_base|0x0c08e60cu;
r[4]+=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e60cu) { target=s->pc; goto dispatch; }
goto P_0c08e60c;
P_0c08e60a: /* original 740a, guest PC 0x0c08e60a */
if(!s->budget--) { s->failed_pc=0x0c08e60au; return 0; }
r[4]+=0x0000000au;
goto P_0c08e60c;
P_0c08e60c: /* original 64e3, guest PC 0x0c08e60c */
if(!s->budget--) { s->failed_pc=0x0c08e60cu; return 0; }
r[4]=r[14];
goto P_0c08e60e;
P_0c08e60e: /* original e500, guest PC 0x0c08e60e */
if(!s->budget--) { s->failed_pc=0x0c08e60eu; return 0; }
r[5]=0x00000000u;
goto P_0c08e610;
P_0c08e610: /* original 4d0b, guest PC 0x0c08e610 */
if(!s->budget--) { s->failed_pc=0x0c08e610u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e614u;
r[4]+=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e614u) { target=s->pc; goto dispatch; }
goto P_0c08e614;
P_0c08e612: /* original 7403, guest PC 0x0c08e612 */
if(!s->budget--) { s->failed_pc=0x0c08e612u; return 0; }
r[4]+=0x00000003u;
goto P_0c08e614;
P_0c08e614: /* original 64e3, guest PC 0x0c08e614 */
if(!s->budget--) { s->failed_pc=0x0c08e614u; return 0; }
r[4]=r[14];
goto P_0c08e616;
P_0c08e616: /* original e500, guest PC 0x0c08e616 */
if(!s->budget--) { s->failed_pc=0x0c08e616u; return 0; }
r[5]=0x00000000u;
goto P_0c08e618;
P_0c08e618: /* original 4d0b, guest PC 0x0c08e618 */
if(!s->budget--) { s->failed_pc=0x0c08e618u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e61cu;
r[4]+=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e61cu) { target=s->pc; goto dispatch; }
goto P_0c08e61c;
P_0c08e61a: /* original 740c, guest PC 0x0c08e61a */
if(!s->budget--) { s->failed_pc=0x0c08e61au; return 0; }
r[4]+=0x0000000cu;
goto P_0c08e61c;
P_0c08e61c: /* original 64e3, guest PC 0x0c08e61c */
if(!s->budget--) { s->failed_pc=0x0c08e61cu; return 0; }
r[4]=r[14];
goto P_0c08e61e;
P_0c08e61e: /* original e500, guest PC 0x0c08e61e */
if(!s->budget--) { s->failed_pc=0x0c08e61eu; return 0; }
r[5]=0x00000000u;
goto P_0c08e620;
P_0c08e620: /* original 4d0b, guest PC 0x0c08e620 */
if(!s->budget--) { s->failed_pc=0x0c08e620u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e624u;
r[4]+=0x0000000eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e624u) { target=s->pc; goto dispatch; }
goto P_0c08e624;
P_0c08e622: /* original 740e, guest PC 0x0c08e622 */
if(!s->budget--) { s->failed_pc=0x0c08e622u; return 0; }
r[4]+=0x0000000eu;
goto P_0c08e624;
P_0c08e624: /* original 64e3, guest PC 0x0c08e624 */
if(!s->budget--) { s->failed_pc=0x0c08e624u; return 0; }
r[4]=r[14];
goto P_0c08e626;
P_0c08e626: /* original e500, guest PC 0x0c08e626 */
if(!s->budget--) { s->failed_pc=0x0c08e626u; return 0; }
r[5]=0x00000000u;
goto P_0c08e628;
P_0c08e628: /* original 4d0b, guest PC 0x0c08e628 */
if(!s->budget--) { s->failed_pc=0x0c08e628u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e62cu;
r[4]+=0x0000000fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e62cu) { target=s->pc; goto dispatch; }
goto P_0c08e62c;
P_0c08e62a: /* original 740f, guest PC 0x0c08e62a */
if(!s->budget--) { s->failed_pc=0x0c08e62au; return 0; }
r[4]+=0x0000000fu;
goto P_0c08e62c;
P_0c08e62c: /* original 64e3, guest PC 0x0c08e62c */
if(!s->budget--) { s->failed_pc=0x0c08e62cu; return 0; }
r[4]=r[14];
goto P_0c08e62e;
P_0c08e62e: /* original e501, guest PC 0x0c08e62e */
if(!s->budget--) { s->failed_pc=0x0c08e62eu; return 0; }
r[5]=0x00000001u;
goto P_0c08e630;
P_0c08e630: /* original 4d0b, guest PC 0x0c08e630 */
if(!s->budget--) { s->failed_pc=0x0c08e630u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e634u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e634u) { target=s->pc; goto dispatch; }
goto P_0c08e634;
P_0c08e632: /* original 7410, guest PC 0x0c08e632 */
if(!s->budget--) { s->failed_pc=0x0c08e632u; return 0; }
r[4]+=0x00000010u;
goto P_0c08e634;
P_0c08e634: /* original 64e3, guest PC 0x0c08e634 */
if(!s->budget--) { s->failed_pc=0x0c08e634u; return 0; }
r[4]=r[14];
goto P_0c08e636;
P_0c08e636: /* original e500, guest PC 0x0c08e636 */
if(!s->budget--) { s->failed_pc=0x0c08e636u; return 0; }
r[5]=0x00000000u;
goto P_0c08e638;
P_0c08e638: /* original 4d0b, guest PC 0x0c08e638 */
if(!s->budget--) { s->failed_pc=0x0c08e638u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e63cu;
r[4]+=0x00000011u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e63cu) { target=s->pc; goto dispatch; }
goto P_0c08e63c;
P_0c08e63a: /* original 7411, guest PC 0x0c08e63a */
if(!s->budget--) { s->failed_pc=0x0c08e63au; return 0; }
r[4]+=0x00000011u;
goto P_0c08e63c;
P_0c08e63c: /* original 64e3, guest PC 0x0c08e63c */
if(!s->budget--) { s->failed_pc=0x0c08e63cu; return 0; }
r[4]=r[14];
goto P_0c08e63e;
P_0c08e63e: /* original e501, guest PC 0x0c08e63e */
if(!s->budget--) { s->failed_pc=0x0c08e63eu; return 0; }
r[5]=0x00000001u;
goto P_0c08e640;
P_0c08e640: /* original 4d0b, guest PC 0x0c08e640 */
if(!s->budget--) { s->failed_pc=0x0c08e640u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e644u;
r[4]+=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e644u) { target=s->pc; goto dispatch; }
goto P_0c08e644;
P_0c08e642: /* original 7412, guest PC 0x0c08e642 */
if(!s->budget--) { s->failed_pc=0x0c08e642u; return 0; }
r[4]+=0x00000012u;
goto P_0c08e644;
P_0c08e644: /* original 64e3, guest PC 0x0c08e644 */
if(!s->budget--) { s->failed_pc=0x0c08e644u; return 0; }
r[4]=r[14];
goto P_0c08e646;
P_0c08e646: /* original e500, guest PC 0x0c08e646 */
if(!s->budget--) { s->failed_pc=0x0c08e646u; return 0; }
r[5]=0x00000000u;
goto P_0c08e648;
P_0c08e648: /* original 4d0b, guest PC 0x0c08e648 */
if(!s->budget--) { s->failed_pc=0x0c08e648u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e64cu;
r[4]+=0x00000013u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e64cu) { target=s->pc; goto dispatch; }
goto P_0c08e64c;
P_0c08e64a: /* original 7413, guest PC 0x0c08e64a */
if(!s->budget--) { s->failed_pc=0x0c08e64au; return 0; }
r[4]+=0x00000013u;
goto P_0c08e64c;
P_0c08e64c: /* original 64e3, guest PC 0x0c08e64c */
if(!s->budget--) { s->failed_pc=0x0c08e64cu; return 0; }
r[4]=r[14];
goto P_0c08e64e;
P_0c08e64e: /* original e500, guest PC 0x0c08e64e */
if(!s->budget--) { s->failed_pc=0x0c08e64eu; return 0; }
r[5]=0x00000000u;
goto P_0c08e650;
P_0c08e650: /* original 4d0b, guest PC 0x0c08e650 */
if(!s->budget--) { s->failed_pc=0x0c08e650u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e654u;
r[4]+=0x00000015u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e654u) { target=s->pc; goto dispatch; }
goto P_0c08e654;
P_0c08e652: /* original 7415, guest PC 0x0c08e652 */
if(!s->budget--) { s->failed_pc=0x0c08e652u; return 0; }
r[4]+=0x00000015u;
goto P_0c08e654;
P_0c08e654: /* original 64e3, guest PC 0x0c08e654 */
if(!s->budget--) { s->failed_pc=0x0c08e654u; return 0; }
r[4]=r[14];
goto P_0c08e656;
P_0c08e656: /* original e500, guest PC 0x0c08e656 */
if(!s->budget--) { s->failed_pc=0x0c08e656u; return 0; }
r[5]=0x00000000u;
goto P_0c08e658;
P_0c08e658: /* original 4d0b, guest PC 0x0c08e658 */
if(!s->budget--) { s->failed_pc=0x0c08e658u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e65cu;
r[4]+=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e65cu) { target=s->pc; goto dispatch; }
goto P_0c08e65c;
P_0c08e65a: /* original 7414, guest PC 0x0c08e65a */
if(!s->budget--) { s->failed_pc=0x0c08e65au; return 0; }
r[4]+=0x00000014u;
goto P_0c08e65c;
P_0c08e65c: /* original 64e3, guest PC 0x0c08e65c */
if(!s->budget--) { s->failed_pc=0x0c08e65cu; return 0; }
r[4]=r[14];
goto P_0c08e65e;
P_0c08e65e: /* original e500, guest PC 0x0c08e65e */
if(!s->budget--) { s->failed_pc=0x0c08e65eu; return 0; }
r[5]=0x00000000u;
goto P_0c08e660;
P_0c08e660: /* original 4d0b, guest PC 0x0c08e660 */
if(!s->budget--) { s->failed_pc=0x0c08e660u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e664u;
r[4]+=0x00000016u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e664u) { target=s->pc; goto dispatch; }
goto P_0c08e664;
P_0c08e662: /* original 7416, guest PC 0x0c08e662 */
if(!s->budget--) { s->failed_pc=0x0c08e662u; return 0; }
r[4]+=0x00000016u;
goto P_0c08e664;
P_0c08e664: /* original 4f26, guest PC 0x0c08e664 */
if(!s->budget--) { s->failed_pc=0x0c08e664u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08e666;
P_0c08e666: /* original 6bf6, guest PC 0x0c08e666 */
if(!s->budget--) { s->failed_pc=0x0c08e666u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08e668;
P_0c08e668: /* original 6cf6, guest PC 0x0c08e668 */
if(!s->budget--) { s->failed_pc=0x0c08e668u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08e66a;
P_0c08e66a: /* original 6df6, guest PC 0x0c08e66a */
if(!s->budget--) { s->failed_pc=0x0c08e66au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08e66c;
P_0c08e66c: /* original 000b, guest PC 0x0c08e66c */
if(!s->budget--) { s->failed_pc=0x0c08e66cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08e66e: /* original 6ef6, guest PC 0x0c08e66e */
if(!s->budget--) { s->failed_pc=0x0c08e66eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08e670u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08e670u; return 0; } return 1;
P_0c08e68c: /* original 2fe6, guest PC 0x0c08e68c */
if(!s->budget--) { s->failed_pc=0x0c08e68cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08e68e;
P_0c08e68e: /* original 6e43, guest PC 0x0c08e68e */
if(!s->budget--) { s->failed_pc=0x0c08e68eu; return 0; }
r[14]=r[4];
goto P_0c08e690;
P_0c08e690: /* original 2fd6, guest PC 0x0c08e690 */
if(!s->budget--) { s->failed_pc=0x0c08e690u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08e692;
P_0c08e692: /* original e340, guest PC 0x0c08e692 */
if(!s->budget--) { s->failed_pc=0x0c08e692u; return 0; }
r[3]=0x00000040u;
goto P_0c08e694;
P_0c08e694: /* original 2fc6, guest PC 0x0c08e694 */
if(!s->budget--) { s->failed_pc=0x0c08e694u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08e696;
P_0c08e696: /* original 2fb6, guest PC 0x0c08e696 */
if(!s->budget--) { s->failed_pc=0x0c08e696u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08e698;
P_0c08e698: /* original 2fa6, guest PC 0x0c08e698 */
if(!s->budget--) { s->failed_pc=0x0c08e698u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08e69a;
P_0c08e69a: /* original 2f96, guest PC 0x0c08e69a */
if(!s->budget--) { s->failed_pc=0x0c08e69au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08e69c;
P_0c08e69c: /* original 2f86, guest PC 0x0c08e69c */
if(!s->budget--) { s->failed_pc=0x0c08e69cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08e69e;
P_0c08e69e: /* original fffb, guest PC 0x0c08e69e */
if(!s->budget--) { s->failed_pc=0x0c08e69eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08e6a0;
P_0c08e6a0: /* original ffeb, guest PC 0x0c08e6a0 */
if(!s->budget--) { s->failed_pc=0x0c08e6a0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c08e6a2;
P_0c08e6a2: /* original ffdb, guest PC 0x0c08e6a2 */
if(!s->budget--) { s->failed_pc=0x0c08e6a2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c08e6a4;
P_0c08e6a4: /* original ffcb, guest PC 0x0c08e6a4 */
if(!s->budget--) { s->failed_pc=0x0c08e6a4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c08e6a6;
P_0c08e6a6: /* original d52f, guest PC 0x0c08e6a6 */
if(!s->budget--) { s->failed_pc=0x0c08e6a6u; return 0; }
r[5]=read(ram,0x0c08e764u,4);
goto P_0c08e6a8;
P_0c08e6a8: /* original 4f22, guest PC 0x0c08e6a8 */
if(!s->budget--) { s->failed_pc=0x0c08e6a8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08e6aa;
P_0c08e6aa: /* original 56ec, guest PC 0x0c08e6aa */
if(!s->budget--) { s->failed_pc=0x0c08e6aau; return 0; }
r[6]=read(ram,r[14]+48,4);
goto P_0c08e6ac;
P_0c08e6ac: /* original d72e, guest PC 0x0c08e6ac */
if(!s->budget--) { s->failed_pc=0x0c08e6acu; return 0; }
r[7]=read(ram,0x0c08e768u,4);
goto P_0c08e6ae;
P_0c08e6ae: /* original 5454, guest PC 0x0c08e6ae */
if(!s->budget--) { s->failed_pc=0x0c08e6aeu; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c08e6b0;
P_0c08e6b0: /* original 2368, guest PC 0x0c08e6b0 */
if(!s->budget--) { s->failed_pc=0x0c08e6b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c08e6b2;
P_0c08e6b2: /* original 7fdc, guest PC 0x0c08e6b2 */
if(!s->budget--) { s->failed_pc=0x0c08e6b2u; return 0; }
r[15]+=0xffffffdcu;
goto P_0c08e6b4;
P_0c08e6b4: /* original 8f08, guest PC 0x0c08e6b4 */
if(!s->budget--) { s->failed_pc=0x0c08e6b4u; return 0; }
cond=r[17]&1u;
r[13]=read(ram,r[5]+20,4);
if(!cond) { goto P_0c08e6c8; }
goto P_0c08e6b8;
P_0c08e6b6: /* original 5d55, guest PC 0x0c08e6b6 */
if(!s->budget--) { s->failed_pc=0x0c08e6b6u; return 0; }
r[13]=read(ram,r[5]+20,4);
goto P_0c08e6b8;
P_0c08e6b8: /* original 924d, guest PC 0x0c08e6b8 */
if(!s->budget--) { s->failed_pc=0x0c08e6b8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e756u,2);
goto P_0c08e6ba;
P_0c08e6ba: /* original 2268, guest PC 0x0c08e6ba */
if(!s->budget--) { s->failed_pc=0x0c08e6bau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c08e6bc;
P_0c08e6bc: /* original 8b07, guest PC 0x0c08e6bc */
if(!s->budget--) { s->failed_pc=0x0c08e6bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08e6ce; }
goto P_0c08e6be;
P_0c08e6be: /* original 934b, guest PC 0x0c08e6be */
if(!s->budget--) { s->failed_pc=0x0c08e6beu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e758u,2);
goto P_0c08e6c0;
P_0c08e6c0: /* original 2368, guest PC 0x0c08e6c0 */
if(!s->budget--) { s->failed_pc=0x0c08e6c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c08e6c2;
P_0c08e6c2: /* original 8b04, guest PC 0x0c08e6c2 */
if(!s->budget--) { s->failed_pc=0x0c08e6c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08e6ce; }
goto P_0c08e6c4;
P_0c08e6c4: /* original a00b, guest PC 0x0c08e6c4 */
if(!s->budget--) { s->failed_pc=0x0c08e6c4u; return 0; }
goto P_0c08e6de;
P_0c08e6c6: /* original 0009, guest PC 0x0c08e6c6 */
if(!s->budget--) { s->failed_pc=0x0c08e6c6u; return 0; }
goto P_0c08e6c8;
P_0c08e6c8: /* original 9047, guest PC 0x0c08e6c8 */
if(!s->budget--) { s->failed_pc=0x0c08e6c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e75au,2);
goto P_0c08e6ca;
P_0c08e6ca: /* original a001, guest PC 0x0c08e6ca */
if(!s->budget--) { s->failed_pc=0x0c08e6cau; return 0; }
goto P_0c08e6d0;
P_0c08e6cc: /* original 0009, guest PC 0x0c08e6cc */
if(!s->budget--) { s->failed_pc=0x0c08e6ccu; return 0; }
goto P_0c08e6ce;
P_0c08e6ce: /* original 9045, guest PC 0x0c08e6ce */
if(!s->budget--) { s->failed_pc=0x0c08e6ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e75cu,2);
goto P_0c08e6d0;
P_0c08e6d0: /* original 047e, guest PC 0x0c08e6d0 */
if(!s->budget--) { s->failed_pc=0x0c08e6d0u; return 0; }
r[4]=read(ram,r[7]+r[0],4);
goto P_0c08e6d2;
P_0c08e6d2: /* original 34d0, guest PC 0x0c08e6d2 */
if(!s->budget--) { s->failed_pc=0x0c08e6d2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[13])!=0);
goto P_0c08e6d4;
P_0c08e6d4: /* original 8901, guest PC 0x0c08e6d4 */
if(!s->budget--) { s->failed_pc=0x0c08e6d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08e6da; }
goto P_0c08e6d6;
P_0c08e6d6: /* original a001, guest PC 0x0c08e6d6 */
if(!s->budget--) { s->failed_pc=0x0c08e6d6u; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c08e6dc;
P_0c08e6d8: /* original 5454, guest PC 0x0c08e6d8 */
if(!s->budget--) { s->failed_pc=0x0c08e6d8u; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c08e6da;
P_0c08e6da: /* original 5455, guest PC 0x0c08e6da */
if(!s->budget--) { s->failed_pc=0x0c08e6dau; return 0; }
r[4]=read(ram,r[5]+20,4);
goto P_0c08e6dc;
P_0c08e6dc: /* original 6d43, guest PC 0x0c08e6dc */
if(!s->budget--) { s->failed_pc=0x0c08e6dcu; return 0; }
r[13]=r[4];
goto P_0c08e6de;
P_0c08e6de: /* original 903e, guest PC 0x0c08e6de */
if(!s->budget--) { s->failed_pc=0x0c08e6deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e75eu,2);
goto P_0c08e6e0;
P_0c08e6e0: /* original 0c4e, guest PC 0x0c08e6e0 */
if(!s->budget--) { s->failed_pc=0x0c08e6e0u; return 0; }
r[12]=read(ram,r[4]+r[0],4);
goto P_0c08e6e2;
P_0c08e6e2: /* original e048, guest PC 0x0c08e6e2 */
if(!s->budget--) { s->failed_pc=0x0c08e6e2u; return 0; }
r[0]=0x00000048u;
goto P_0c08e6e4;
P_0c08e6e4: /* original 084e, guest PC 0x0c08e6e4 */
if(!s->budget--) { s->failed_pc=0x0c08e6e4u; return 0; }
r[8]=read(ram,r[4]+r[0],4);
goto P_0c08e6e6;
P_0c08e6e6: /* original e04c, guest PC 0x0c08e6e6 */
if(!s->budget--) { s->failed_pc=0x0c08e6e6u; return 0; }
r[0]=0x0000004cu;
goto P_0c08e6e8;
P_0c08e6e8: /* original 054e, guest PC 0x0c08e6e8 */
if(!s->budget--) { s->failed_pc=0x0c08e6e8u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c08e6ea;
P_0c08e6ea: /* original 9039, guest PC 0x0c08e6ea */
if(!s->budget--) { s->failed_pc=0x0c08e6eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e760u,2);
goto P_0c08e6ec;
P_0c08e6ec: /* original 6753, guest PC 0x0c08e6ec */
if(!s->budget--) { s->failed_pc=0x0c08e6ecu; return 0; }
r[7]=r[5];
goto P_0c08e6ee;
P_0c08e6ee: /* original 034e, guest PC 0x0c08e6ee */
if(!s->budget--) { s->failed_pc=0x0c08e6eeu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c08e6f0;
P_0c08e6f0: /* original 1f32, guest PC 0x0c08e6f0 */
if(!s->budget--) { s->failed_pc=0x0c08e6f0u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c08e6f2;
P_0c08e6f2: /* original 9034, guest PC 0x0c08e6f2 */
if(!s->budget--) { s->failed_pc=0x0c08e6f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e75eu,2);
goto P_0c08e6f4;
P_0c08e6f4: /* original 02de, guest PC 0x0c08e6f4 */
if(!s->budget--) { s->failed_pc=0x0c08e6f4u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c08e6f6;
P_0c08e6f6: /* original e048, guest PC 0x0c08e6f6 */
if(!s->budget--) { s->failed_pc=0x0c08e6f6u; return 0; }
r[0]=0x00000048u;
goto P_0c08e6f8;
P_0c08e6f8: /* original 1f23, guest PC 0x0c08e6f8 */
if(!s->budget--) { s->failed_pc=0x0c08e6f8u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c08e6fa;
P_0c08e6fa: /* original 0ade, guest PC 0x0c08e6fa */
if(!s->budget--) { s->failed_pc=0x0c08e6fau; return 0; }
r[10]=read(ram,r[13]+r[0],4);
goto P_0c08e6fc;
P_0c08e6fc: /* original e04c, guest PC 0x0c08e6fc */
if(!s->budget--) { s->failed_pc=0x0c08e6fcu; return 0; }
r[0]=0x0000004cu;
goto P_0c08e6fe;
P_0c08e6fe: /* original 0bde, guest PC 0x0c08e6fe */
if(!s->budget--) { s->failed_pc=0x0c08e6feu; return 0; }
r[11]=read(ram,r[13]+r[0],4);
goto P_0c08e700;
P_0c08e700: /* original 902e, guest PC 0x0c08e700 */
if(!s->budget--) { s->failed_pc=0x0c08e700u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e760u,2);
goto P_0c08e702;
P_0c08e702: /* original 27ba, guest PC 0x0c08e702 */
if(!s->budget--) { s->failed_pc=0x0c08e702u; return 0; }
r[7]^=r[11];
goto P_0c08e704;
P_0c08e704: /* original 03de, guest PC 0x0c08e704 */
if(!s->budget--) { s->failed_pc=0x0c08e704u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c08e706;
P_0c08e706: /* original e040, guest PC 0x0c08e706 */
if(!s->budget--) { s->failed_pc=0x0c08e706u; return 0; }
r[0]=0x00000040u;
goto P_0c08e708;
P_0c08e708: /* original 1f37, guest PC 0x0c08e708 */
if(!s->budget--) { s->failed_pc=0x0c08e708u; return 0; }
write(ram,r[15]+28,r[3],4);
goto P_0c08e70a;
P_0c08e70a: /* original 59f3, guest PC 0x0c08e70a */
if(!s->budget--) { s->failed_pc=0x0c08e70au; return 0; }
r[9]=read(ram,r[15]+12,4);
goto P_0c08e70c;
P_0c08e70c: /* original 1ecd, guest PC 0x0c08e70c */
if(!s->budget--) { s->failed_pc=0x0c08e70cu; return 0; }
write(ram,r[14]+52,r[12],4);
goto P_0c08e70e;
P_0c08e70e: /* original 29c9, guest PC 0x0c08e70e */
if(!s->budget--) { s->failed_pc=0x0c08e70eu; return 0; }
r[9]&=r[12];
goto P_0c08e710;
P_0c08e710: /* original 1e8f, guest PC 0x0c08e710 */
if(!s->budget--) { s->failed_pc=0x0c08e710u; return 0; }
write(ram,r[14]+60,r[8],4);
goto P_0c08e712;
P_0c08e712: /* original 0e56, guest PC 0x0c08e712 */
if(!s->budget--) { s->failed_pc=0x0c08e712u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c08e714;
P_0c08e714: /* original e044, guest PC 0x0c08e714 */
if(!s->budget--) { s->failed_pc=0x0c08e714u; return 0; }
r[0]=0x00000044u;
goto P_0c08e716;
P_0c08e716: /* original 53f2, guest PC 0x0c08e716 */
if(!s->budget--) { s->failed_pc=0x0c08e716u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c08e718;
P_0c08e718: /* original 0e36, guest PC 0x0c08e718 */
if(!s->budget--) { s->failed_pc=0x0c08e718u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c08e71a;
P_0c08e71a: /* original e301, guest PC 0x0c08e71a */
if(!s->budget--) { s->failed_pc=0x0c08e71au; return 0; }
r[3]=0x00000001u;
goto P_0c08e71c;
P_0c08e71c: /* original dc13, guest PC 0x0c08e71c */
if(!s->budget--) { s->failed_pc=0x0c08e71cu; return 0; }
r[12]=read(ram,0x0c08e76cu,4);
goto P_0c08e71e;
P_0c08e71e: /* original 2639, guest PC 0x0c08e71e */
if(!s->budget--) { s->failed_pc=0x0c08e71eu; return 0; }
r[6]&=r[3];
goto P_0c08e720;
P_0c08e720: /* original 6263, guest PC 0x0c08e720 */
if(!s->budget--) { s->failed_pc=0x0c08e720u; return 0; }
r[2]=r[6];
goto P_0c08e722;
P_0c08e722: /* original 2228, guest PC 0x0c08e722 */
if(!s->budget--) { s->failed_pc=0x0c08e722u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c08e724;
P_0c08e724: /* original 8f03, guest PC 0x0c08e724 */
if(!s->budget--) { s->failed_pc=0x0c08e724u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+16,r[6],4);
if(!cond) { goto P_0c08e72e; }
goto P_0c08e728;
P_0c08e726: /* original 1f64, guest PC 0x0c08e726 */
if(!s->budget--) { s->failed_pc=0x0c08e726u; return 0; }
write(ram,r[15]+16,r[6],4);
goto P_0c08e728;
P_0c08e728: /* original e304, guest PC 0x0c08e728 */
if(!s->budget--) { s->failed_pc=0x0c08e728u; return 0; }
r[3]=0x00000004u;
goto P_0c08e72a;
P_0c08e72a: /* original 2398, guest PC 0x0c08e72a */
if(!s->budget--) { s->failed_pc=0x0c08e72au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c08e72c;
P_0c08e72c: /* original 8922, guest PC 0x0c08e72c */
if(!s->budget--) { s->failed_pc=0x0c08e72cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08e774; }
goto P_0c08e72e;
P_0c08e72e: /* original 6283, guest PC 0x0c08e72e */
if(!s->budget--) { s->failed_pc=0x0c08e72eu; return 0; }
r[2]=r[8];
goto P_0c08e730;
P_0c08e730: /* original 22c8, guest PC 0x0c08e730 */
if(!s->budget--) { s->failed_pc=0x0c08e730u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c08e732;
P_0c08e732: /* original 8b1f, guest PC 0x0c08e732 */
if(!s->budget--) { s->failed_pc=0x0c08e732u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08e774; }
goto P_0c08e734;
P_0c08e734: /* original d30e, guest PC 0x0c08e734 */
if(!s->budget--) { s->failed_pc=0x0c08e734u; return 0; }
r[3]=read(ram,0x0c08e770u,4);
goto P_0c08e736;
P_0c08e736: /* original 2838, guest PC 0x0c08e736 */
if(!s->budget--) { s->failed_pc=0x0c08e736u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[3])==0)!=0);
goto P_0c08e738;
P_0c08e738: /* original 8b05, guest PC 0x0c08e738 */
if(!s->budget--) { s->failed_pc=0x0c08e738u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08e746; }
goto P_0c08e73a;
P_0c08e73a: /* original e010, guest PC 0x0c08e73a */
if(!s->budget--) { s->failed_pc=0x0c08e73au; return 0; }
r[0]=0x00000010u;
goto P_0c08e73c;
P_0c08e73c: /* original ff46, guest PC 0x0c08e73c */
if(!s->budget--) { s->failed_pc=0x0c08e73cu; return 0; }
vf3_matrix_load(s,ram,15,r[4]+r[0]);
goto P_0c08e73e;
P_0c08e73e: /* original e014, guest PC 0x0c08e73e */
if(!s->budget--) { s->failed_pc=0x0c08e73eu; return 0; }
r[0]=0x00000014u;
goto P_0c08e740;
P_0c08e740: /* original fe46, guest PC 0x0c08e740 */
if(!s->budget--) { s->failed_pc=0x0c08e740u; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c08e742;
P_0c08e742: /* original a005, guest PC 0x0c08e742 */
if(!s->budget--) { s->failed_pc=0x0c08e742u; return 0; }
r[0]=0x00000018u;
goto P_0c08e750;
P_0c08e744: /* original e018, guest PC 0x0c08e744 */
if(!s->budget--) { s->failed_pc=0x0c08e744u; return 0; }
r[0]=0x00000018u;
goto P_0c08e746;
P_0c08e746: /* original 900c, guest PC 0x0c08e746 */
if(!s->budget--) { s->failed_pc=0x0c08e746u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e762u,2);
goto P_0c08e748;
P_0c08e748: /* original ff46, guest PC 0x0c08e748 */
if(!s->budget--) { s->failed_pc=0x0c08e748u; return 0; }
vf3_matrix_load(s,ram,15,r[4]+r[0]);
goto P_0c08e74a;
P_0c08e74a: /* original 7004, guest PC 0x0c08e74a */
if(!s->budget--) { s->failed_pc=0x0c08e74au; return 0; }
r[0]+=0x00000004u;
goto P_0c08e74c;
P_0c08e74c: /* original fe46, guest PC 0x0c08e74c */
if(!s->budget--) { s->failed_pc=0x0c08e74cu; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c08e74e;
P_0c08e74e: /* original 7004, guest PC 0x0c08e74e */
if(!s->budget--) { s->failed_pc=0x0c08e74eu; return 0; }
r[0]+=0x00000004u;
goto P_0c08e750;
P_0c08e750: /* original fd46, guest PC 0x0c08e750 */
if(!s->budget--) { s->failed_pc=0x0c08e750u; return 0; }
vf3_matrix_load(s,ram,13,r[4]+r[0]);
goto P_0c08e752;
P_0c08e752: /* original a016, guest PC 0x0c08e752 */
if(!s->budget--) { s->failed_pc=0x0c08e752u; return 0; }
fr[13]^=0x80000000u;
goto P_0c08e782;
P_0c08e754: /* original fd4d, guest PC 0x0c08e754 */
if(!s->budget--) { s->failed_pc=0x0c08e754u; return 0; }
fr[13]^=0x80000000u;
if(!vf3_matrix_family(0x0c08e756u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08e756u; return 0; } return 1;
P_0c08e774: /* original 9068, guest PC 0x0c08e774 */
if(!s->budget--) { s->failed_pc=0x0c08e774u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e848u,2);
goto P_0c08e776;
P_0c08e776: /* original ff46, guest PC 0x0c08e776 */
if(!s->budget--) { s->failed_pc=0x0c08e776u; return 0; }
vf3_matrix_load(s,ram,15,r[4]+r[0]);
goto P_0c08e778;
P_0c08e778: /* original 7004, guest PC 0x0c08e778 */
if(!s->budget--) { s->failed_pc=0x0c08e778u; return 0; }
r[0]+=0x00000004u;
goto P_0c08e77a;
P_0c08e77a: /* original fe46, guest PC 0x0c08e77a */
if(!s->budget--) { s->failed_pc=0x0c08e77au; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c08e77c;
P_0c08e77c: /* original 7004, guest PC 0x0c08e77c */
if(!s->budget--) { s->failed_pc=0x0c08e77cu; return 0; }
r[0]+=0x00000004u;
goto P_0c08e77e;
P_0c08e77e: /* original fd46, guest PC 0x0c08e77e */
if(!s->budget--) { s->failed_pc=0x0c08e77eu; return 0; }
vf3_matrix_load(s,ram,13,r[4]+r[0]);
goto P_0c08e780;
P_0c08e780: /* original fd4d, guest PC 0x0c08e780 */
if(!s->budget--) { s->failed_pc=0x0c08e780u; return 0; }
fr[13]^=0x80000000u;
goto P_0c08e782;
P_0c08e782: /* original 9062, guest PC 0x0c08e782 */
if(!s->budget--) { s->failed_pc=0x0c08e782u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e84au,2);
goto P_0c08e784;
P_0c08e784: /* original 034d, guest PC 0x0c08e784 */
if(!s->budget--) { s->failed_pc=0x0c08e784u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08e786;
P_0c08e786: /* original e054, guest PC 0x0c08e786 */
if(!s->budget--) { s->failed_pc=0x0c08e786u; return 0; }
r[0]=0x00000054u;
goto P_0c08e788;
P_0c08e788: /* original 0e35, guest PC 0x0c08e788 */
if(!s->budget--) { s->failed_pc=0x0c08e788u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c08e78a;
P_0c08e78a: /* original e03e, guest PC 0x0c08e78a */
if(!s->budget--) { s->failed_pc=0x0c08e78au; return 0; }
r[0]=0x0000003eu;
goto P_0c08e78c;
P_0c08e78c: /* original 024d, guest PC 0x0c08e78c */
if(!s->budget--) { s->failed_pc=0x0c08e78cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08e78e;
P_0c08e78e: /* original e056, guest PC 0x0c08e78e */
if(!s->budget--) { s->failed_pc=0x0c08e78eu; return 0; }
r[0]=0x00000056u;
goto P_0c08e790;
P_0c08e790: /* original 6373, guest PC 0x0c08e790 */
if(!s->budget--) { s->failed_pc=0x0c08e790u; return 0; }
r[3]=r[7];
goto P_0c08e792;
P_0c08e792: /* original 23c9, guest PC 0x0c08e792 */
if(!s->budget--) { s->failed_pc=0x0c08e792u; return 0; }
r[3]&=r[12];
goto P_0c08e794;
P_0c08e794: /* original 0e25, guest PC 0x0c08e794 */
if(!s->budget--) { s->failed_pc=0x0c08e794u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c08e796;
P_0c08e796: /* original e070, guest PC 0x0c08e796 */
if(!s->budget--) { s->failed_pc=0x0c08e796u; return 0; }
r[0]=0x00000070u;
goto P_0c08e798;
P_0c08e798: /* original fef7, guest PC 0x0c08e798 */
if(!s->budget--) { s->failed_pc=0x0c08e798u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c08e79a;
P_0c08e79a: /* original e074, guest PC 0x0c08e79a */
if(!s->budget--) { s->failed_pc=0x0c08e79au; return 0; }
r[0]=0x00000074u;
goto P_0c08e79c;
P_0c08e79c: /* original fee7, guest PC 0x0c08e79c */
if(!s->budget--) { s->failed_pc=0x0c08e79cu; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c08e79e;
P_0c08e79e: /* original e078, guest PC 0x0c08e79e */
if(!s->budget--) { s->failed_pc=0x0c08e79eu; return 0; }
r[0]=0x00000078u;
goto P_0c08e7a0;
P_0c08e7a0: /* original fed7, guest PC 0x0c08e7a0 */
if(!s->budget--) { s->failed_pc=0x0c08e7a0u; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c08e7a2;
P_0c08e7a2: /* original 9853, guest PC 0x0c08e7a2 */
if(!s->budget--) { s->failed_pc=0x0c08e7a2u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e84cu,2);
goto P_0c08e7a4;
P_0c08e7a4: /* original 9252, guest PC 0x0c08e7a4 */
if(!s->budget--) { s->failed_pc=0x0c08e7a4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e84cu,2);
goto P_0c08e7a6;
P_0c08e7a6: /* original fc8d, guest PC 0x0c08e7a6 */
if(!s->budget--) { s->failed_pc=0x0c08e7a6u; return 0; }
fr[12]=0;
goto P_0c08e7a8;
P_0c08e7a8: /* original 2879, guest PC 0x0c08e7a8 */
if(!s->budget--) { s->failed_pc=0x0c08e7a8u; return 0; }
r[8]&=r[7];
goto P_0c08e7aa;
P_0c08e7aa: /* original 2258, guest PC 0x0c08e7aa */
if(!s->budget--) { s->failed_pc=0x0c08e7aau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c08e7ac;
P_0c08e7ac: /* original 8d23, guest PC 0x0c08e7ac */
if(!s->budget--) { s->failed_pc=0x0c08e7acu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[3],4);
if(cond) { goto P_0c08e7f6; }
goto P_0c08e7b0;
P_0c08e7ae: /* original 1f32, guest PC 0x0c08e7ae */
if(!s->budget--) { s->failed_pc=0x0c08e7aeu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c08e7b0;
P_0c08e7b0: /* original 2888, guest PC 0x0c08e7b0 */
if(!s->budget--) { s->failed_pc=0x0c08e7b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c08e7b2;
P_0c08e7b2: /* original 8b02, guest PC 0x0c08e7b2 */
if(!s->budget--) { s->failed_pc=0x0c08e7b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08e7ba; }
goto P_0c08e7b4;
P_0c08e7b4: /* original 53f2, guest PC 0x0c08e7b4 */
if(!s->budget--) { s->failed_pc=0x0c08e7b4u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c08e7b6;
P_0c08e7b6: /* original 2338, guest PC 0x0c08e7b6 */
if(!s->budget--) { s->failed_pc=0x0c08e7b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c08e7b8;
P_0c08e7b8: /* original 8b1d, guest PC 0x0c08e7b8 */
if(!s->budget--) { s->failed_pc=0x0c08e7b8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08e7f6; }
goto P_0c08e7ba;
P_0c08e7ba: /* original 9048, guest PC 0x0c08e7ba */
if(!s->budget--) { s->failed_pc=0x0c08e7bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e84eu,2);
goto P_0c08e7bc;
P_0c08e7bc: /* original 25c8, guest PC 0x0c08e7bc */
if(!s->budget--) { s->failed_pc=0x0c08e7bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[12])==0)!=0);
goto P_0c08e7be;
P_0c08e7be: /* original 014d, guest PC 0x0c08e7be */
if(!s->budget--) { s->failed_pc=0x0c08e7beu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08e7c0;
P_0c08e7c0: /* original c724, guest PC 0x0c08e7c0 */
if(!s->budget--) { s->failed_pc=0x0c08e7c0u; return 0; }
r[0]=code_base|0x0008e854u;
goto P_0c08e7c2;
P_0c08e7c2: /* original 1f18, guest PC 0x0c08e7c2 */
if(!s->budget--) { s->failed_pc=0x0c08e7c2u; return 0; }
write(ram,r[15]+32,r[1],4);
goto P_0c08e7c4;
P_0c08e7c4: /* original f308, guest PC 0x0c08e7c4 */
if(!s->budget--) { s->failed_pc=0x0c08e7c4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08e7c6;
P_0c08e7c6: /* original e018, guest PC 0x0c08e7c6 */
if(!s->budget--) { s->failed_pc=0x0c08e7c6u; return 0; }
r[0]=0x00000018u;
goto P_0c08e7c8;
P_0c08e7c8: /* original ff3a, guest PC 0x0c08e7c8 */
if(!s->budget--) { s->failed_pc=0x0c08e7c8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08e7ca;
P_0c08e7ca: /* original ffc7, guest PC 0x0c08e7ca */
if(!s->budget--) { s->failed_pc=0x0c08e7cau; return 0; }
vf3_matrix_store(s,ram,12,r[15]+r[0]);
goto P_0c08e7cc;
P_0c08e7cc: /* original e004, guest PC 0x0c08e7cc */
if(!s->budget--) { s->failed_pc=0x0c08e7ccu; return 0; }
r[0]=0x00000004u;
goto P_0c08e7ce;
P_0c08e7ce: /* original 8d03, guest PC 0x0c08e7ce */
if(!s->budget--) { s->failed_pc=0x0c08e7ceu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,12,r[15]+r[0]);
if(cond) { goto P_0c08e7d8; }
goto P_0c08e7d2;
P_0c08e7d0: /* original ffc7, guest PC 0x0c08e7d0 */
if(!s->budget--) { s->failed_pc=0x0c08e7d0u; return 0; }
vf3_matrix_store(s,ram,12,r[15]+r[0]);
goto P_0c08e7d2;
P_0c08e7d2: /* original f3f8, guest PC 0x0c08e7d2 */
if(!s->budget--) { s->failed_pc=0x0c08e7d2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c08e7d4;
P_0c08e7d4: /* original f34d, guest PC 0x0c08e7d4 */
if(!s->budget--) { s->failed_pc=0x0c08e7d4u; return 0; }
fr[3]^=0x80000000u;
goto P_0c08e7d6;
P_0c08e7d6: /* original ff3a, guest PC 0x0c08e7d6 */
if(!s->budget--) { s->failed_pc=0x0c08e7d6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08e7d8;
P_0c08e7d8: /* original 54f8, guest PC 0x0c08e7d8 */
if(!s->budget--) { s->failed_pc=0x0c08e7d8u; return 0; }
r[4]=read(ram,r[15]+32,4);
goto P_0c08e7da;
P_0c08e7da: /* original 66f3, guest PC 0x0c08e7da */
if(!s->budget--) { s->failed_pc=0x0c08e7dau; return 0; }
r[6]=r[15];
goto P_0c08e7dc;
P_0c08e7dc: /* original d31e, guest PC 0x0c08e7dc */
if(!s->budget--) { s->failed_pc=0x0c08e7dcu; return 0; }
r[3]=read(ram,0x0c08e858u,4);
goto P_0c08e7de;
P_0c08e7de: /* original 7604, guest PC 0x0c08e7de */
if(!s->budget--) { s->failed_pc=0x0c08e7deu; return 0; }
r[6]+=0x00000004u;
goto P_0c08e7e0;
P_0c08e7e0: /* original 65f3, guest PC 0x0c08e7e0 */
if(!s->budget--) { s->failed_pc=0x0c08e7e0u; return 0; }
r[5]=r[15];
goto P_0c08e7e2;
P_0c08e7e2: /* original 430b, guest PC 0x0c08e7e2 */
if(!s->budget--) { s->failed_pc=0x0c08e7e2u; return 0; }
target=r[3];
r[16]=code_base|0x0c08e7e6u;
r[4]=0u-r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e7e6u) { target=s->pc; goto dispatch; }
goto P_0c08e7e6;
P_0c08e7e4: /* original 644b, guest PC 0x0c08e7e4 */
if(!s->budget--) { s->failed_pc=0x0c08e7e4u; return 0; }
r[4]=0u-r[4];
goto P_0c08e7e6;
P_0c08e7e6: /* original e018, guest PC 0x0c08e7e6 */
if(!s->budget--) { s->failed_pc=0x0c08e7e6u; return 0; }
r[0]=0x00000018u;
goto P_0c08e7e8;
P_0c08e7e8: /* original f3f8, guest PC 0x0c08e7e8 */
if(!s->budget--) { s->failed_pc=0x0c08e7e8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c08e7ea;
P_0c08e7ea: /* original f2f6, guest PC 0x0c08e7ea */
if(!s->budget--) { s->failed_pc=0x0c08e7eau; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c08e7ec;
P_0c08e7ec: /* original e004, guest PC 0x0c08e7ec */
if(!s->budget--) { s->failed_pc=0x0c08e7ecu; return 0; }
r[0]=0x00000004u;
goto P_0c08e7ee;
P_0c08e7ee: /* original f1f6, guest PC 0x0c08e7ee */
if(!s->budget--) { s->failed_pc=0x0c08e7eeu; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c08e7f0;
P_0c08e7f0: /* original ff30, guest PC 0x0c08e7f0 */
if(!s->budget--) { s->failed_pc=0x0c08e7f0u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c08e7f2;
P_0c08e7f2: /* original fe20, guest PC 0x0c08e7f2 */
if(!s->budget--) { s->failed_pc=0x0c08e7f2u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[2],r[18],'+');
goto P_0c08e7f4;
P_0c08e7f4: /* original fd10, guest PC 0x0c08e7f4 */
if(!s->budget--) { s->failed_pc=0x0c08e7f4u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[1],r[18],'+');
goto P_0c08e7f6;
P_0c08e7f6: /* original e07c, guest PC 0x0c08e7f6 */
if(!s->budget--) { s->failed_pc=0x0c08e7f6u; return 0; }
r[0]=0x0000007cu;
goto P_0c08e7f8;
P_0c08e7f8: /* original fef7, guest PC 0x0c08e7f8 */
if(!s->budget--) { s->failed_pc=0x0c08e7f8u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c08e7fa;
P_0c08e7fa: /* original 7004, guest PC 0x0c08e7fa */
if(!s->budget--) { s->failed_pc=0x0c08e7fau; return 0; }
r[0]+=0x00000004u;
goto P_0c08e7fc;
P_0c08e7fc: /* original fee7, guest PC 0x0c08e7fc */
if(!s->budget--) { s->failed_pc=0x0c08e7fcu; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c08e7fe;
P_0c08e7fe: /* original 7004, guest PC 0x0c08e7fe */
if(!s->budget--) { s->failed_pc=0x0c08e7feu; return 0; }
r[0]+=0x00000004u;
goto P_0c08e800;
P_0c08e800: /* original fed7, guest PC 0x0c08e800 */
if(!s->budget--) { s->failed_pc=0x0c08e800u; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c08e802;
P_0c08e802: /* original e048, guest PC 0x0c08e802 */
if(!s->budget--) { s->failed_pc=0x0c08e802u; return 0; }
r[0]=0x00000048u;
goto P_0c08e804;
P_0c08e804: /* original 53f3, guest PC 0x0c08e804 */
if(!s->budget--) { s->failed_pc=0x0c08e804u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c08e806;
P_0c08e806: /* original 1e3e, guest PC 0x0c08e806 */
if(!s->budget--) { s->failed_pc=0x0c08e806u; return 0; }
write(ram,r[14]+56,r[3],4);
goto P_0c08e808;
P_0c08e808: /* original 0ea6, guest PC 0x0c08e808 */
if(!s->budget--) { s->failed_pc=0x0c08e808u; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c08e80a;
P_0c08e80a: /* original e04c, guest PC 0x0c08e80a */
if(!s->budget--) { s->failed_pc=0x0c08e80au; return 0; }
r[0]=0x0000004cu;
goto P_0c08e80c;
P_0c08e80c: /* original 0eb6, guest PC 0x0c08e80c */
if(!s->budget--) { s->failed_pc=0x0c08e80cu; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c08e80e;
P_0c08e80e: /* original e050, guest PC 0x0c08e80e */
if(!s->budget--) { s->failed_pc=0x0c08e80eu; return 0; }
r[0]=0x00000050u;
goto P_0c08e810;
P_0c08e810: /* original 53f7, guest PC 0x0c08e810 */
if(!s->budget--) { s->failed_pc=0x0c08e810u; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c08e812;
P_0c08e812: /* original 0e36, guest PC 0x0c08e812 */
if(!s->budget--) { s->failed_pc=0x0c08e812u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c08e814;
P_0c08e814: /* original 52f4, guest PC 0x0c08e814 */
if(!s->budget--) { s->failed_pc=0x0c08e814u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c08e816;
P_0c08e816: /* original 2228, guest PC 0x0c08e816 */
if(!s->budget--) { s->failed_pc=0x0c08e816u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c08e818;
P_0c08e818: /* original 8b02, guest PC 0x0c08e818 */
if(!s->budget--) { s->failed_pc=0x0c08e818u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08e820; }
goto P_0c08e81a;
P_0c08e81a: /* original e104, guest PC 0x0c08e81a */
if(!s->budget--) { s->failed_pc=0x0c08e81au; return 0; }
r[1]=0x00000004u;
goto P_0c08e81c;
P_0c08e81c: /* original 2918, guest PC 0x0c08e81c */
if(!s->budget--) { s->failed_pc=0x0c08e81cu; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[1])==0)!=0);
goto P_0c08e81e;
P_0c08e81e: /* original 891f, guest PC 0x0c08e81e */
if(!s->budget--) { s->failed_pc=0x0c08e81eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08e860; }
goto P_0c08e820;
P_0c08e820: /* original 63a3, guest PC 0x0c08e820 */
if(!s->budget--) { s->failed_pc=0x0c08e820u; return 0; }
r[3]=r[10];
goto P_0c08e822;
P_0c08e822: /* original 23c8, guest PC 0x0c08e822 */
if(!s->budget--) { s->failed_pc=0x0c08e822u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c08e824;
P_0c08e824: /* original 8b1c, guest PC 0x0c08e824 */
if(!s->budget--) { s->failed_pc=0x0c08e824u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08e860; }
goto P_0c08e826;
P_0c08e826: /* original d20d, guest PC 0x0c08e826 */
if(!s->budget--) { s->failed_pc=0x0c08e826u; return 0; }
r[2]=read(ram,0x0c08e85cu,4);
goto P_0c08e828;
P_0c08e828: /* original 2a28, guest PC 0x0c08e828 */
if(!s->budget--) { s->failed_pc=0x0c08e828u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[2])==0)!=0);
goto P_0c08e82a;
P_0c08e82a: /* original 8b05, guest PC 0x0c08e82a */
if(!s->budget--) { s->failed_pc=0x0c08e82au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08e838; }
goto P_0c08e82c;
P_0c08e82c: /* original e010, guest PC 0x0c08e82c */
if(!s->budget--) { s->failed_pc=0x0c08e82cu; return 0; }
r[0]=0x00000010u;
goto P_0c08e82e;
P_0c08e82e: /* original ffd6, guest PC 0x0c08e82e */
if(!s->budget--) { s->failed_pc=0x0c08e82eu; return 0; }
vf3_matrix_load(s,ram,15,r[13]+r[0]);
goto P_0c08e830;
P_0c08e830: /* original e014, guest PC 0x0c08e830 */
if(!s->budget--) { s->failed_pc=0x0c08e830u; return 0; }
r[0]=0x00000014u;
goto P_0c08e832;
P_0c08e832: /* original fed6, guest PC 0x0c08e832 */
if(!s->budget--) { s->failed_pc=0x0c08e832u; return 0; }
vf3_matrix_load(s,ram,14,r[13]+r[0]);
goto P_0c08e834;
P_0c08e834: /* original a005, guest PC 0x0c08e834 */
if(!s->budget--) { s->failed_pc=0x0c08e834u; return 0; }
r[0]=0x00000018u;
goto P_0c08e842;
P_0c08e836: /* original e018, guest PC 0x0c08e836 */
if(!s->budget--) { s->failed_pc=0x0c08e836u; return 0; }
r[0]=0x00000018u;
goto P_0c08e838;
P_0c08e838: /* original 900a, guest PC 0x0c08e838 */
if(!s->budget--) { s->failed_pc=0x0c08e838u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e850u,2);
goto P_0c08e83a;
P_0c08e83a: /* original ffd6, guest PC 0x0c08e83a */
if(!s->budget--) { s->failed_pc=0x0c08e83au; return 0; }
vf3_matrix_load(s,ram,15,r[13]+r[0]);
goto P_0c08e83c;
P_0c08e83c: /* original 7004, guest PC 0x0c08e83c */
if(!s->budget--) { s->failed_pc=0x0c08e83cu; return 0; }
r[0]+=0x00000004u;
goto P_0c08e83e;
P_0c08e83e: /* original fed6, guest PC 0x0c08e83e */
if(!s->budget--) { s->failed_pc=0x0c08e83eu; return 0; }
vf3_matrix_load(s,ram,14,r[13]+r[0]);
goto P_0c08e840;
P_0c08e840: /* original 7004, guest PC 0x0c08e840 */
if(!s->budget--) { s->failed_pc=0x0c08e840u; return 0; }
r[0]+=0x00000004u;
goto P_0c08e842;
P_0c08e842: /* original fdd6, guest PC 0x0c08e842 */
if(!s->budget--) { s->failed_pc=0x0c08e842u; return 0; }
vf3_matrix_load(s,ram,13,r[13]+r[0]);
goto P_0c08e844;
P_0c08e844: /* original a013, guest PC 0x0c08e844 */
if(!s->budget--) { s->failed_pc=0x0c08e844u; return 0; }
fr[13]^=0x80000000u;
goto P_0c08e86e;
P_0c08e846: /* original fd4d, guest PC 0x0c08e846 */
if(!s->budget--) { s->failed_pc=0x0c08e846u; return 0; }
fr[13]^=0x80000000u;
if(!vf3_matrix_family(0x0c08e848u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08e848u; return 0; } return 1;
P_0c08e860: /* original 904d, guest PC 0x0c08e860 */
if(!s->budget--) { s->failed_pc=0x0c08e860u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e8feu,2);
goto P_0c08e862;
P_0c08e862: /* original ffd6, guest PC 0x0c08e862 */
if(!s->budget--) { s->failed_pc=0x0c08e862u; return 0; }
vf3_matrix_load(s,ram,15,r[13]+r[0]);
goto P_0c08e864;
P_0c08e864: /* original 7004, guest PC 0x0c08e864 */
if(!s->budget--) { s->failed_pc=0x0c08e864u; return 0; }
r[0]+=0x00000004u;
goto P_0c08e866;
P_0c08e866: /* original fed6, guest PC 0x0c08e866 */
if(!s->budget--) { s->failed_pc=0x0c08e866u; return 0; }
vf3_matrix_load(s,ram,14,r[13]+r[0]);
goto P_0c08e868;
P_0c08e868: /* original 7004, guest PC 0x0c08e868 */
if(!s->budget--) { s->failed_pc=0x0c08e868u; return 0; }
r[0]+=0x00000004u;
goto P_0c08e86a;
P_0c08e86a: /* original fdd6, guest PC 0x0c08e86a */
if(!s->budget--) { s->failed_pc=0x0c08e86au; return 0; }
vf3_matrix_load(s,ram,13,r[13]+r[0]);
goto P_0c08e86c;
P_0c08e86c: /* original fd4d, guest PC 0x0c08e86c */
if(!s->budget--) { s->failed_pc=0x0c08e86cu; return 0; }
fr[13]^=0x80000000u;
goto P_0c08e86e;
P_0c08e86e: /* original 9047, guest PC 0x0c08e86e */
if(!s->budget--) { s->failed_pc=0x0c08e86eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e900u,2);
goto P_0c08e870;
P_0c08e870: /* original 03dd, guest PC 0x0c08e870 */
if(!s->budget--) { s->failed_pc=0x0c08e870u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c08e872;
P_0c08e872: /* original e058, guest PC 0x0c08e872 */
if(!s->budget--) { s->failed_pc=0x0c08e872u; return 0; }
r[0]=0x00000058u;
goto P_0c08e874;
P_0c08e874: /* original 0e35, guest PC 0x0c08e874 */
if(!s->budget--) { s->failed_pc=0x0c08e874u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c08e876;
P_0c08e876: /* original e03e, guest PC 0x0c08e876 */
if(!s->budget--) { s->failed_pc=0x0c08e876u; return 0; }
r[0]=0x0000003eu;
goto P_0c08e878;
P_0c08e878: /* original 02dd, guest PC 0x0c08e878 */
if(!s->budget--) { s->failed_pc=0x0c08e878u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c08e87a;
P_0c08e87a: /* original e05a, guest PC 0x0c08e87a */
if(!s->budget--) { s->failed_pc=0x0c08e87au; return 0; }
r[0]=0x0000005au;
goto P_0c08e87c;
P_0c08e87c: /* original 0e25, guest PC 0x0c08e87c */
if(!s->budget--) { s->failed_pc=0x0c08e87cu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c08e87e;
P_0c08e87e: /* original 705e, guest PC 0x0c08e87e */
if(!s->budget--) { s->failed_pc=0x0c08e87eu; return 0; }
r[0]+=0x0000005eu;
goto P_0c08e880;
P_0c08e880: /* original fef7, guest PC 0x0c08e880 */
if(!s->budget--) { s->failed_pc=0x0c08e880u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c08e882;
P_0c08e882: /* original 7004, guest PC 0x0c08e882 */
if(!s->budget--) { s->failed_pc=0x0c08e882u; return 0; }
r[0]+=0x00000004u;
goto P_0c08e884;
P_0c08e884: /* original fee7, guest PC 0x0c08e884 */
if(!s->budget--) { s->failed_pc=0x0c08e884u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c08e886;
P_0c08e886: /* original 7004, guest PC 0x0c08e886 */
if(!s->budget--) { s->failed_pc=0x0c08e886u; return 0; }
r[0]+=0x00000004u;
goto P_0c08e888;
P_0c08e888: /* original 933b, guest PC 0x0c08e888 */
if(!s->budget--) { s->failed_pc=0x0c08e888u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e902u,2);
goto P_0c08e88a;
P_0c08e88a: /* original 23b8, guest PC 0x0c08e88a */
if(!s->budget--) { s->failed_pc=0x0c08e88au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c08e88c;
P_0c08e88c: /* original 8d23, guest PC 0x0c08e88c */
if(!s->budget--) { s->failed_pc=0x0c08e88cu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,13,r[14]+r[0]);
if(cond) { goto P_0c08e8d6; }
goto P_0c08e890;
P_0c08e88e: /* original fed7, guest PC 0x0c08e88e */
if(!s->budget--) { s->failed_pc=0x0c08e88eu; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c08e890;
P_0c08e890: /* original 2888, guest PC 0x0c08e890 */
if(!s->budget--) { s->failed_pc=0x0c08e890u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c08e892;
P_0c08e892: /* original 8b02, guest PC 0x0c08e892 */
if(!s->budget--) { s->failed_pc=0x0c08e892u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08e89a; }
goto P_0c08e894;
P_0c08e894: /* original 52f2, guest PC 0x0c08e894 */
if(!s->budget--) { s->failed_pc=0x0c08e894u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c08e896;
P_0c08e896: /* original 2228, guest PC 0x0c08e896 */
if(!s->budget--) { s->failed_pc=0x0c08e896u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c08e898;
P_0c08e898: /* original 8b1d, guest PC 0x0c08e898 */
if(!s->budget--) { s->failed_pc=0x0c08e898u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08e8d6; }
goto P_0c08e89a;
P_0c08e89a: /* original 9033, guest PC 0x0c08e89a */
if(!s->budget--) { s->failed_pc=0x0c08e89au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e904u,2);
goto P_0c08e89c;
P_0c08e89c: /* original 2bc8, guest PC 0x0c08e89c */
if(!s->budget--) { s->failed_pc=0x0c08e89cu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[12])==0)!=0);
goto P_0c08e89e;
P_0c08e89e: /* original 01dd, guest PC 0x0c08e89e */
if(!s->budget--) { s->failed_pc=0x0c08e89eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c08e8a0;
P_0c08e8a0: /* original c719, guest PC 0x0c08e8a0 */
if(!s->budget--) { s->failed_pc=0x0c08e8a0u; return 0; }
r[0]=code_base|0x0008e908u;
goto P_0c08e8a2;
P_0c08e8a2: /* original 1f12, guest PC 0x0c08e8a2 */
if(!s->budget--) { s->failed_pc=0x0c08e8a2u; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c08e8a4;
P_0c08e8a4: /* original f308, guest PC 0x0c08e8a4 */
if(!s->budget--) { s->failed_pc=0x0c08e8a4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08e8a6;
P_0c08e8a6: /* original e014, guest PC 0x0c08e8a6 */
if(!s->budget--) { s->failed_pc=0x0c08e8a6u; return 0; }
r[0]=0x00000014u;
goto P_0c08e8a8;
P_0c08e8a8: /* original ff3a, guest PC 0x0c08e8a8 */
if(!s->budget--) { s->failed_pc=0x0c08e8a8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08e8aa;
P_0c08e8aa: /* original ffc7, guest PC 0x0c08e8aa */
if(!s->budget--) { s->failed_pc=0x0c08e8aau; return 0; }
vf3_matrix_store(s,ram,12,r[15]+r[0]);
goto P_0c08e8ac;
P_0c08e8ac: /* original e004, guest PC 0x0c08e8ac */
if(!s->budget--) { s->failed_pc=0x0c08e8acu; return 0; }
r[0]=0x00000004u;
goto P_0c08e8ae;
P_0c08e8ae: /* original 8d03, guest PC 0x0c08e8ae */
if(!s->budget--) { s->failed_pc=0x0c08e8aeu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,12,r[15]+r[0]);
if(cond) { goto P_0c08e8b8; }
goto P_0c08e8b2;
P_0c08e8b0: /* original ffc7, guest PC 0x0c08e8b0 */
if(!s->budget--) { s->failed_pc=0x0c08e8b0u; return 0; }
vf3_matrix_store(s,ram,12,r[15]+r[0]);
goto P_0c08e8b2;
P_0c08e8b2: /* original f3f8, guest PC 0x0c08e8b2 */
if(!s->budget--) { s->failed_pc=0x0c08e8b2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c08e8b4;
P_0c08e8b4: /* original f34d, guest PC 0x0c08e8b4 */
if(!s->budget--) { s->failed_pc=0x0c08e8b4u; return 0; }
fr[3]^=0x80000000u;
goto P_0c08e8b6;
P_0c08e8b6: /* original ff3a, guest PC 0x0c08e8b6 */
if(!s->budget--) { s->failed_pc=0x0c08e8b6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08e8b8;
P_0c08e8b8: /* original 54f2, guest PC 0x0c08e8b8 */
if(!s->budget--) { s->failed_pc=0x0c08e8b8u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c08e8ba;
P_0c08e8ba: /* original 66f3, guest PC 0x0c08e8ba */
if(!s->budget--) { s->failed_pc=0x0c08e8bau; return 0; }
r[6]=r[15];
goto P_0c08e8bc;
P_0c08e8bc: /* original d313, guest PC 0x0c08e8bc */
if(!s->budget--) { s->failed_pc=0x0c08e8bcu; return 0; }
r[3]=read(ram,0x0c08e90cu,4);
goto P_0c08e8be;
P_0c08e8be: /* original 7604, guest PC 0x0c08e8be */
if(!s->budget--) { s->failed_pc=0x0c08e8beu; return 0; }
r[6]+=0x00000004u;
goto P_0c08e8c0;
P_0c08e8c0: /* original 65f3, guest PC 0x0c08e8c0 */
if(!s->budget--) { s->failed_pc=0x0c08e8c0u; return 0; }
r[5]=r[15];
goto P_0c08e8c2;
P_0c08e8c2: /* original 430b, guest PC 0x0c08e8c2 */
if(!s->budget--) { s->failed_pc=0x0c08e8c2u; return 0; }
target=r[3];
r[16]=code_base|0x0c08e8c6u;
r[4]=0u-r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e8c6u) { target=s->pc; goto dispatch; }
goto P_0c08e8c6;
P_0c08e8c4: /* original 644b, guest PC 0x0c08e8c4 */
if(!s->budget--) { s->failed_pc=0x0c08e8c4u; return 0; }
r[4]=0u-r[4];
goto P_0c08e8c6;
P_0c08e8c6: /* original e014, guest PC 0x0c08e8c6 */
if(!s->budget--) { s->failed_pc=0x0c08e8c6u; return 0; }
r[0]=0x00000014u;
goto P_0c08e8c8;
P_0c08e8c8: /* original f3f8, guest PC 0x0c08e8c8 */
if(!s->budget--) { s->failed_pc=0x0c08e8c8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c08e8ca;
P_0c08e8ca: /* original f2f6, guest PC 0x0c08e8ca */
if(!s->budget--) { s->failed_pc=0x0c08e8cau; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c08e8cc;
P_0c08e8cc: /* original e004, guest PC 0x0c08e8cc */
if(!s->budget--) { s->failed_pc=0x0c08e8ccu; return 0; }
r[0]=0x00000004u;
goto P_0c08e8ce;
P_0c08e8ce: /* original f1f6, guest PC 0x0c08e8ce */
if(!s->budget--) { s->failed_pc=0x0c08e8ceu; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c08e8d0;
P_0c08e8d0: /* original ff30, guest PC 0x0c08e8d0 */
if(!s->budget--) { s->failed_pc=0x0c08e8d0u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c08e8d2;
P_0c08e8d2: /* original fe20, guest PC 0x0c08e8d2 */
if(!s->budget--) { s->failed_pc=0x0c08e8d2u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[2],r[18],'+');
goto P_0c08e8d4;
P_0c08e8d4: /* original fd10, guest PC 0x0c08e8d4 */
if(!s->budget--) { s->failed_pc=0x0c08e8d4u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[1],r[18],'+');
goto P_0c08e8d6;
P_0c08e8d6: /* original 9016, guest PC 0x0c08e8d6 */
if(!s->budget--) { s->failed_pc=0x0c08e8d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e906u,2);
goto P_0c08e8d8;
P_0c08e8d8: /* original 7f24, guest PC 0x0c08e8d8 */
if(!s->budget--) { s->failed_pc=0x0c08e8d8u; return 0; }
r[15]+=0x00000024u;
goto P_0c08e8da;
P_0c08e8da: /* original 4f26, guest PC 0x0c08e8da */
if(!s->budget--) { s->failed_pc=0x0c08e8dau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08e8dc;
P_0c08e8dc: /* original fef7, guest PC 0x0c08e8dc */
if(!s->budget--) { s->failed_pc=0x0c08e8dcu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c08e8de;
P_0c08e8de: /* original 7004, guest PC 0x0c08e8de */
if(!s->budget--) { s->failed_pc=0x0c08e8deu; return 0; }
r[0]+=0x00000004u;
goto P_0c08e8e0;
P_0c08e8e0: /* original fee7, guest PC 0x0c08e8e0 */
if(!s->budget--) { s->failed_pc=0x0c08e8e0u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c08e8e2;
P_0c08e8e2: /* original 7004, guest PC 0x0c08e8e2 */
if(!s->budget--) { s->failed_pc=0x0c08e8e2u; return 0; }
r[0]+=0x00000004u;
goto P_0c08e8e4;
P_0c08e8e4: /* original fed7, guest PC 0x0c08e8e4 */
if(!s->budget--) { s->failed_pc=0x0c08e8e4u; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c08e8e6;
P_0c08e8e6: /* original fcf9, guest PC 0x0c08e8e6 */
if(!s->budget--) { s->failed_pc=0x0c08e8e6u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08e8e8;
P_0c08e8e8: /* original fdf9, guest PC 0x0c08e8e8 */
if(!s->budget--) { s->failed_pc=0x0c08e8e8u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08e8ea;
P_0c08e8ea: /* original fef9, guest PC 0x0c08e8ea */
if(!s->budget--) { s->failed_pc=0x0c08e8eau; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08e8ec;
P_0c08e8ec: /* original fff9, guest PC 0x0c08e8ec */
if(!s->budget--) { s->failed_pc=0x0c08e8ecu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08e8ee;
P_0c08e8ee: /* original 68f6, guest PC 0x0c08e8ee */
if(!s->budget--) { s->failed_pc=0x0c08e8eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08e8f0;
P_0c08e8f0: /* original 69f6, guest PC 0x0c08e8f0 */
if(!s->budget--) { s->failed_pc=0x0c08e8f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08e8f2;
P_0c08e8f2: /* original 6af6, guest PC 0x0c08e8f2 */
if(!s->budget--) { s->failed_pc=0x0c08e8f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08e8f4;
P_0c08e8f4: /* original 6bf6, guest PC 0x0c08e8f4 */
if(!s->budget--) { s->failed_pc=0x0c08e8f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08e8f6;
P_0c08e8f6: /* original 6cf6, guest PC 0x0c08e8f6 */
if(!s->budget--) { s->failed_pc=0x0c08e8f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08e8f8;
P_0c08e8f8: /* original 6df6, guest PC 0x0c08e8f8 */
if(!s->budget--) { s->failed_pc=0x0c08e8f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08e8fa;
P_0c08e8fa: /* original 000b, guest PC 0x0c08e8fa */
if(!s->budget--) { s->failed_pc=0x0c08e8fau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08e8fc: /* original 6ef6, guest PC 0x0c08e8fc */
if(!s->budget--) { s->failed_pc=0x0c08e8fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08e8feu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08e8feu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
