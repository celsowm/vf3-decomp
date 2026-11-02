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
int vf3_away_batch24_adapter_11(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0bc5aeu: goto P_0c0bc5ae;
case 0x0c0bc5b0u: goto P_0c0bc5b0;
case 0x0c0bc5b2u: goto P_0c0bc5b2;
case 0x0c0bc5b4u: goto P_0c0bc5b4;
case 0x0c0bc5b6u: goto P_0c0bc5b6;
case 0x0c0bc5b8u: goto P_0c0bc5b8;
case 0x0c0bc5bau: goto P_0c0bc5ba;
case 0x0c0bc5bcu: goto P_0c0bc5bc;
case 0x0c0bc5beu: goto P_0c0bc5be;
case 0x0c0bc5c0u: goto P_0c0bc5c0;
case 0x0c0bc5c2u: goto P_0c0bc5c2;
case 0x0c0bc5c4u: goto P_0c0bc5c4;
case 0x0c0bc5c6u: goto P_0c0bc5c6;
case 0x0c0bc5c8u: goto P_0c0bc5c8;
case 0x0c0bc5cau: goto P_0c0bc5ca;
case 0x0c0bc5ccu: goto P_0c0bc5cc;
case 0x0c0bc5ceu: goto P_0c0bc5ce;
case 0x0c0bc5d0u: goto P_0c0bc5d0;
case 0x0c0bc5d2u: goto P_0c0bc5d2;
case 0x0c0bc5d4u: goto P_0c0bc5d4;
case 0x0c0bc5d6u: goto P_0c0bc5d6;
case 0x0c0bc5d8u: goto P_0c0bc5d8;
case 0x0c0bc5dau: goto P_0c0bc5da;
case 0x0c0bc5dcu: goto P_0c0bc5dc;
case 0x0c0bc5deu: goto P_0c0bc5de;
case 0x0c0bc5e0u: goto P_0c0bc5e0;
case 0x0c0bc5e2u: goto P_0c0bc5e2;
case 0x0c0bc5e4u: goto P_0c0bc5e4;
case 0x0c0bc5e6u: goto P_0c0bc5e6;
case 0x0c0bc5e8u: goto P_0c0bc5e8;
case 0x0c0bc5eau: goto P_0c0bc5ea;
case 0x0c0bc5ecu: goto P_0c0bc5ec;
case 0x0c0bc5eeu: goto P_0c0bc5ee;
case 0x0c0bc5f0u: goto P_0c0bc5f0;
case 0x0c0bc5f2u: goto P_0c0bc5f2;
case 0x0c0bc5f4u: goto P_0c0bc5f4;
case 0x0c0bc5f6u: goto P_0c0bc5f6;
case 0x0c0bc5f8u: goto P_0c0bc5f8;
case 0x0c0bc5fau: goto P_0c0bc5fa;
case 0x0c0bc5fcu: goto P_0c0bc5fc;
case 0x0c0bc5feu: goto P_0c0bc5fe;
case 0x0c0bc600u: goto P_0c0bc600;
case 0x0c0bc602u: goto P_0c0bc602;
case 0x0c0bc604u: goto P_0c0bc604;
case 0x0c0bc606u: goto P_0c0bc606;
case 0x0c0bc608u: goto P_0c0bc608;
case 0x0c0bc60au: goto P_0c0bc60a;
case 0x0c0bc60cu: goto P_0c0bc60c;
case 0x0c0bc60eu: goto P_0c0bc60e;
case 0x0c0bc610u: goto P_0c0bc610;
case 0x0c0bc612u: goto P_0c0bc612;
case 0x0c0bc614u: goto P_0c0bc614;
case 0x0c0bc616u: goto P_0c0bc616;
case 0x0c0bc618u: goto P_0c0bc618;
case 0x0c0bc61au: goto P_0c0bc61a;
case 0x0c0bc61cu: goto P_0c0bc61c;
case 0x0c0bc61eu: goto P_0c0bc61e;
case 0x0c0bc620u: goto P_0c0bc620;
case 0x0c0bc622u: goto P_0c0bc622;
case 0x0c0bc624u: goto P_0c0bc624;
case 0x0c0bc626u: goto P_0c0bc626;
case 0x0c0bc628u: goto P_0c0bc628;
case 0x0c0bc62au: goto P_0c0bc62a;
case 0x0c0bc62cu: goto P_0c0bc62c;
case 0x0c0bc62eu: goto P_0c0bc62e;
case 0x0c0bc630u: goto P_0c0bc630;
case 0x0c0bc632u: goto P_0c0bc632;
case 0x0c0bc634u: goto P_0c0bc634;
case 0x0c0bc636u: goto P_0c0bc636;
case 0x0c0bc638u: goto P_0c0bc638;
case 0x0c0bc63au: goto P_0c0bc63a;
case 0x0c0bc63cu: goto P_0c0bc63c;
case 0x0c0bc63eu: goto P_0c0bc63e;
case 0x0c0bc640u: goto P_0c0bc640;
case 0x0c0bc642u: goto P_0c0bc642;
case 0x0c0bc644u: goto P_0c0bc644;
case 0x0c0bc646u: goto P_0c0bc646;
case 0x0c0bc648u: goto P_0c0bc648;
case 0x0c0bc64au: goto P_0c0bc64a;
case 0x0c0bc64cu: goto P_0c0bc64c;
case 0x0c0bc64eu: goto P_0c0bc64e;
case 0x0c0bc650u: goto P_0c0bc650;
case 0x0c0bc652u: goto P_0c0bc652;
case 0x0c0bc654u: goto P_0c0bc654;
case 0x0c0bc656u: goto P_0c0bc656;
case 0x0c0bc658u: goto P_0c0bc658;
case 0x0c0bc65au: goto P_0c0bc65a;
case 0x0c0bc65cu: goto P_0c0bc65c;
case 0x0c0bc65eu: goto P_0c0bc65e;
case 0x0c0bc660u: goto P_0c0bc660;
case 0x0c0bc662u: goto P_0c0bc662;
case 0x0c0bc664u: goto P_0c0bc664;
case 0x0c0bc666u: goto P_0c0bc666;
case 0x0c0bc668u: goto P_0c0bc668;
case 0x0c0bc66au: goto P_0c0bc66a;
case 0x0c0bc66cu: goto P_0c0bc66c;
case 0x0c0bc66eu: goto P_0c0bc66e;
case 0x0c0bc670u: goto P_0c0bc670;
case 0x0c0bc672u: goto P_0c0bc672;
case 0x0c0bc674u: goto P_0c0bc674;
case 0x0c0bc676u: goto P_0c0bc676;
case 0x0c0bc678u: goto P_0c0bc678;
case 0x0c0bc67au: goto P_0c0bc67a;
case 0x0c0bc67cu: goto P_0c0bc67c;
case 0x0c0bc67eu: goto P_0c0bc67e;
case 0x0c0bc680u: goto P_0c0bc680;
case 0x0c0bc682u: goto P_0c0bc682;
case 0x0c0bc684u: goto P_0c0bc684;
case 0x0c0bc686u: goto P_0c0bc686;
case 0x0c0bc688u: goto P_0c0bc688;
case 0x0c0bc68au: goto P_0c0bc68a;
case 0x0c0bc68cu: goto P_0c0bc68c;
case 0x0c0bc68eu: goto P_0c0bc68e;
case 0x0c0bc690u: goto P_0c0bc690;
case 0x0c0bc692u: goto P_0c0bc692;
case 0x0c0bc694u: goto P_0c0bc694;
case 0x0c0bc696u: goto P_0c0bc696;
case 0x0c0bc698u: goto P_0c0bc698;
case 0x0c0bc69au: goto P_0c0bc69a;
case 0x0c0bc69cu: goto P_0c0bc69c;
case 0x0c0bc69eu: goto P_0c0bc69e;
case 0x0c0bc6a0u: goto P_0c0bc6a0;
case 0x0c0bc6a2u: goto P_0c0bc6a2;
case 0x0c0bc6a4u: goto P_0c0bc6a4;
case 0x0c0bc6a6u: goto P_0c0bc6a6;
case 0x0c0bc6a8u: goto P_0c0bc6a8;
case 0x0c0bc6aau: goto P_0c0bc6aa;
case 0x0c0bc6acu: goto P_0c0bc6ac;
case 0x0c0bc6aeu: goto P_0c0bc6ae;
case 0x0c0bc6b0u: goto P_0c0bc6b0;
case 0x0c0bc6b2u: goto P_0c0bc6b2;
case 0x0c0bc6b4u: goto P_0c0bc6b4;
case 0x0c0bc6b6u: goto P_0c0bc6b6;
case 0x0c0bc6b8u: goto P_0c0bc6b8;
case 0x0c0bc6bau: goto P_0c0bc6ba;
case 0x0c0bc6bcu: goto P_0c0bc6bc;
case 0x0c0bc6beu: goto P_0c0bc6be;
case 0x0c0bc6c0u: goto P_0c0bc6c0;
case 0x0c0bc6c2u: goto P_0c0bc6c2;
case 0x0c0bc6c4u: goto P_0c0bc6c4;
case 0x0c0bc6c6u: goto P_0c0bc6c6;
case 0x0c0bc6c8u: goto P_0c0bc6c8;
case 0x0c0bc6cau: goto P_0c0bc6ca;
case 0x0c0bc6ccu: goto P_0c0bc6cc;
case 0x0c0bc6ceu: goto P_0c0bc6ce;
case 0x0c0bc6d0u: goto P_0c0bc6d0;
case 0x0c0bc6d2u: goto P_0c0bc6d2;
case 0x0c0bc6d4u: goto P_0c0bc6d4;
case 0x0c0bc6d6u: goto P_0c0bc6d6;
case 0x0c0bc6d8u: goto P_0c0bc6d8;
case 0x0c0bc6dau: goto P_0c0bc6da;
case 0x0c0bc6dcu: goto P_0c0bc6dc;
case 0x0c0bc6deu: goto P_0c0bc6de;
case 0x0c0bc6e0u: goto P_0c0bc6e0;
case 0x0c0bc6e2u: goto P_0c0bc6e2;
case 0x0c0bc6e4u: goto P_0c0bc6e4;
case 0x0c0bc6e6u: goto P_0c0bc6e6;
case 0x0c0bc6e8u: goto P_0c0bc6e8;
case 0x0c0bc6eau: goto P_0c0bc6ea;
case 0x0c0bc6ecu: goto P_0c0bc6ec;
case 0x0c0bc6eeu: goto P_0c0bc6ee;
case 0x0c0bc6f0u: goto P_0c0bc6f0;
case 0x0c0bc6f2u: goto P_0c0bc6f2;
case 0x0c0bc6f4u: goto P_0c0bc6f4;
case 0x0c0bc6f6u: goto P_0c0bc6f6;
case 0x0c0bc6f8u: goto P_0c0bc6f8;
case 0x0c0bc6fau: goto P_0c0bc6fa;
case 0x0c0bc6fcu: goto P_0c0bc6fc;
case 0x0c0bc6feu: goto P_0c0bc6fe;
case 0x0c0bc700u: goto P_0c0bc700;
case 0x0c0bc702u: goto P_0c0bc702;
case 0x0c0bc704u: goto P_0c0bc704;
case 0x0c0bc706u: goto P_0c0bc706;
case 0x0c0bc708u: goto P_0c0bc708;
case 0x0c0bc70au: goto P_0c0bc70a;
case 0x0c0bc70cu: goto P_0c0bc70c;
case 0x0c0bc70eu: goto P_0c0bc70e;
case 0x0c0bc710u: goto P_0c0bc710;
case 0x0c0bc780u: goto P_0c0bc780;
case 0x0c0bc782u: goto P_0c0bc782;
case 0x0c0bc784u: goto P_0c0bc784;
case 0x0c0bc786u: goto P_0c0bc786;
case 0x0c0bc788u: goto P_0c0bc788;
case 0x0c0bc78au: goto P_0c0bc78a;
case 0x0c0bc78cu: goto P_0c0bc78c;
case 0x0c0bc78eu: goto P_0c0bc78e;
case 0x0c0bc790u: goto P_0c0bc790;
case 0x0c0bc792u: goto P_0c0bc792;
case 0x0c0bc794u: goto P_0c0bc794;
case 0x0c0bc796u: goto P_0c0bc796;
case 0x0c0bc798u: goto P_0c0bc798;
case 0x0c0bc79au: goto P_0c0bc79a;
case 0x0c0bc79cu: goto P_0c0bc79c;
case 0x0c0bc79eu: goto P_0c0bc79e;
case 0x0c0bc7a0u: goto P_0c0bc7a0;
case 0x0c0bc7a2u: goto P_0c0bc7a2;
case 0x0c0bc7a4u: goto P_0c0bc7a4;
case 0x0c0bc7a6u: goto P_0c0bc7a6;
case 0x0c0bc7a8u: goto P_0c0bc7a8;
case 0x0c0bc7aau: goto P_0c0bc7aa;
case 0x0c0bc7acu: goto P_0c0bc7ac;
case 0x0c0bc7aeu: goto P_0c0bc7ae;
case 0x0c0bc7b0u: goto P_0c0bc7b0;
case 0x0c0bc7b2u: goto P_0c0bc7b2;
case 0x0c0bc7b4u: goto P_0c0bc7b4;
case 0x0c0bc7b6u: goto P_0c0bc7b6;
case 0x0c0bc7b8u: goto P_0c0bc7b8;
case 0x0c0bc7bau: goto P_0c0bc7ba;
case 0x0c0bc7bcu: goto P_0c0bc7bc;
case 0x0c0bc7beu: goto P_0c0bc7be;
case 0x0c0bc7c0u: goto P_0c0bc7c0;
case 0x0c0bc7c2u: goto P_0c0bc7c2;
case 0x0c0bc7c4u: goto P_0c0bc7c4;
case 0x0c0bc7c6u: goto P_0c0bc7c6;
case 0x0c0bc7c8u: goto P_0c0bc7c8;
case 0x0c0bc7cau: goto P_0c0bc7ca;
case 0x0c0bc7ccu: goto P_0c0bc7cc;
case 0x0c0bc7ceu: goto P_0c0bc7ce;
case 0x0c0bc7d0u: goto P_0c0bc7d0;
case 0x0c0bc7d2u: goto P_0c0bc7d2;
case 0x0c0bc7d4u: goto P_0c0bc7d4;
case 0x0c0bc7d6u: goto P_0c0bc7d6;
case 0x0c0bc7d8u: goto P_0c0bc7d8;
case 0x0c0bc7dau: goto P_0c0bc7da;
case 0x0c0bc7dcu: goto P_0c0bc7dc;
case 0x0c0bc7deu: goto P_0c0bc7de;
case 0x0c0bc7e0u: goto P_0c0bc7e0;
case 0x0c0bc7e2u: goto P_0c0bc7e2;
case 0x0c0bc7e4u: goto P_0c0bc7e4;
case 0x0c0bc7e6u: goto P_0c0bc7e6;
case 0x0c0bc7e8u: goto P_0c0bc7e8;
case 0x0c0bc7eau: goto P_0c0bc7ea;
case 0x0c0bc7ecu: goto P_0c0bc7ec;
case 0x0c0bc7eeu: goto P_0c0bc7ee;
case 0x0c0bc7f0u: goto P_0c0bc7f0;
case 0x0c0bc7f2u: goto P_0c0bc7f2;
case 0x0c0bc7f4u: goto P_0c0bc7f4;
case 0x0c0bc7f6u: goto P_0c0bc7f6;
case 0x0c0bc7f8u: goto P_0c0bc7f8;
case 0x0c0bc7fau: goto P_0c0bc7fa;
case 0x0c0bc7fcu: goto P_0c0bc7fc;
case 0x0c0bc7feu: goto P_0c0bc7fe;
case 0x0c0bc800u: goto P_0c0bc800;
case 0x0c0bc802u: goto P_0c0bc802;
case 0x0c0bc804u: goto P_0c0bc804;
case 0x0c0bc806u: goto P_0c0bc806;
case 0x0c0bc808u: goto P_0c0bc808;
case 0x0c0bc80au: goto P_0c0bc80a;
case 0x0c0bc80cu: goto P_0c0bc80c;
case 0x0c0bc80eu: goto P_0c0bc80e;
case 0x0c0bc810u: goto P_0c0bc810;
case 0x0c0bc812u: goto P_0c0bc812;
case 0x0c0bc814u: goto P_0c0bc814;
case 0x0c0bc816u: goto P_0c0bc816;
case 0x0c0bc818u: goto P_0c0bc818;
case 0x0c0bc81au: goto P_0c0bc81a;
case 0x0c0bc81cu: goto P_0c0bc81c;
case 0x0c0bc81eu: goto P_0c0bc81e;
case 0x0c0bc820u: goto P_0c0bc820;
case 0x0c0bc822u: goto P_0c0bc822;
case 0x0c0bc824u: goto P_0c0bc824;
case 0x0c0bc826u: goto P_0c0bc826;
case 0x0c0bc828u: goto P_0c0bc828;
case 0x0c0bc82au: goto P_0c0bc82a;
case 0x0c0bc82cu: goto P_0c0bc82c;
case 0x0c0bc82eu: goto P_0c0bc82e;
case 0x0c0bc830u: goto P_0c0bc830;
case 0x0c0bc832u: goto P_0c0bc832;
case 0x0c0bc834u: goto P_0c0bc834;
case 0x0c0bc836u: goto P_0c0bc836;
case 0x0c0bc838u: goto P_0c0bc838;
case 0x0c0bc83au: goto P_0c0bc83a;
case 0x0c0bc83cu: goto P_0c0bc83c;
case 0x0c0bc83eu: goto P_0c0bc83e;
case 0x0c0bc840u: goto P_0c0bc840;
case 0x0c0bc842u: goto P_0c0bc842;
case 0x0c0bc844u: goto P_0c0bc844;
case 0x0c0bc846u: goto P_0c0bc846;
case 0x0c0bc848u: goto P_0c0bc848;
case 0x0c0bc84au: goto P_0c0bc84a;
case 0x0c0bc84cu: goto P_0c0bc84c;
case 0x0c0bc84eu: goto P_0c0bc84e;
case 0x0c0bc850u: goto P_0c0bc850;
case 0x0c0bc852u: goto P_0c0bc852;
case 0x0c0bc854u: goto P_0c0bc854;
case 0x0c0bc856u: goto P_0c0bc856;
case 0x0c0bc858u: goto P_0c0bc858;
case 0x0c0bc85au: goto P_0c0bc85a;
case 0x0c0bc85cu: goto P_0c0bc85c;
case 0x0c0bc85eu: goto P_0c0bc85e;
case 0x0c0bc860u: goto P_0c0bc860;
case 0x0c0bc862u: goto P_0c0bc862;
case 0x0c0bc864u: goto P_0c0bc864;
case 0x0c0bc866u: goto P_0c0bc866;
case 0x0c0bc868u: goto P_0c0bc868;
case 0x0c0bc86au: goto P_0c0bc86a;
case 0x0c0bc86cu: goto P_0c0bc86c;
case 0x0c0bc86eu: goto P_0c0bc86e;
case 0x0c0bc870u: goto P_0c0bc870;
case 0x0c0bc872u: goto P_0c0bc872;
case 0x0c0bc874u: goto P_0c0bc874;
case 0x0c0bc876u: goto P_0c0bc876;
case 0x0c0bc878u: goto P_0c0bc878;
case 0x0c0bc87au: goto P_0c0bc87a;
case 0x0c0bc87cu: goto P_0c0bc87c;
case 0x0c0bc87eu: goto P_0c0bc87e;
case 0x0c0bc880u: goto P_0c0bc880;
case 0x0c0bc882u: goto P_0c0bc882;
case 0x0c0bc884u: goto P_0c0bc884;
case 0x0c0bc886u: goto P_0c0bc886;
case 0x0c0bc888u: goto P_0c0bc888;
case 0x0c0bc88au: goto P_0c0bc88a;
case 0x0c0bc88cu: goto P_0c0bc88c;
case 0x0c0bc88eu: goto P_0c0bc88e;
case 0x0c0bc890u: goto P_0c0bc890;
case 0x0c0bc892u: goto P_0c0bc892;
case 0x0c0bc894u: goto P_0c0bc894;
case 0x0c0bc896u: goto P_0c0bc896;
case 0x0c0bc898u: goto P_0c0bc898;
case 0x0c0bc89au: goto P_0c0bc89a;
case 0x0c0bc89cu: goto P_0c0bc89c;
case 0x0c0bc89eu: goto P_0c0bc89e;
case 0x0c0bc8a0u: goto P_0c0bc8a0;
case 0x0c0bc8a2u: goto P_0c0bc8a2;
case 0x0c0bc8a4u: goto P_0c0bc8a4;
case 0x0c0bc8a6u: goto P_0c0bc8a6;
case 0x0c0bc8a8u: goto P_0c0bc8a8;
case 0x0c0bc8aau: goto P_0c0bc8aa;
case 0x0c0bc8acu: goto P_0c0bc8ac;
case 0x0c0bc8aeu: goto P_0c0bc8ae;
case 0x0c0bc8b0u: goto P_0c0bc8b0;
case 0x0c0bc8b2u: goto P_0c0bc8b2;
case 0x0c0bc8b4u: goto P_0c0bc8b4;
case 0x0c0bc8b6u: goto P_0c0bc8b6;
case 0x0c0bc8b8u: goto P_0c0bc8b8;
case 0x0c0bc8bau: goto P_0c0bc8ba;
case 0x0c0bc8bcu: goto P_0c0bc8bc;
case 0x0c0bc8beu: goto P_0c0bc8be;
case 0x0c0bc8c0u: goto P_0c0bc8c0;
case 0x0c0bc8c2u: goto P_0c0bc8c2;
case 0x0c0bc8c4u: goto P_0c0bc8c4;
case 0x0c0bc8c6u: goto P_0c0bc8c6;
case 0x0c0bc8c8u: goto P_0c0bc8c8;
case 0x0c0bc8cau: goto P_0c0bc8ca;
case 0x0c0bc8ccu: goto P_0c0bc8cc;
case 0x0c0bc8ceu: goto P_0c0bc8ce;
case 0x0c0bc8d0u: goto P_0c0bc8d0;
case 0x0c0bc8d2u: goto P_0c0bc8d2;
case 0x0c0bc8d4u: goto P_0c0bc8d4;
case 0x0c0bc8d6u: goto P_0c0bc8d6;
case 0x0c0bc8d8u: goto P_0c0bc8d8;
case 0x0c0bc952u: goto P_0c0bc952;
case 0x0c0bc954u: goto P_0c0bc954;
case 0x0c0bc956u: goto P_0c0bc956;
case 0x0c0bc958u: goto P_0c0bc958;
case 0x0c0bc95au: goto P_0c0bc95a;
case 0x0c0bc95cu: goto P_0c0bc95c;
case 0x0c0bc95eu: goto P_0c0bc95e;
case 0x0c0bc960u: goto P_0c0bc960;
case 0x0c0bc962u: goto P_0c0bc962;
case 0x0c0bc964u: goto P_0c0bc964;
case 0x0c0bc966u: goto P_0c0bc966;
case 0x0c0bc968u: goto P_0c0bc968;
case 0x0c0bc96au: goto P_0c0bc96a;
case 0x0c0bc96cu: goto P_0c0bc96c;
case 0x0c0bc96eu: goto P_0c0bc96e;
case 0x0c0bc970u: goto P_0c0bc970;
case 0x0c0bc972u: goto P_0c0bc972;
case 0x0c0bc974u: goto P_0c0bc974;
case 0x0c0bc976u: goto P_0c0bc976;
case 0x0c0bc978u: goto P_0c0bc978;
case 0x0c0bc97au: goto P_0c0bc97a;
case 0x0c0bc97cu: goto P_0c0bc97c;
case 0x0c0bc97eu: goto P_0c0bc97e;
case 0x0c0bc980u: goto P_0c0bc980;
case 0x0c0bc982u: goto P_0c0bc982;
case 0x0c0bc984u: goto P_0c0bc984;
case 0x0c0bc986u: goto P_0c0bc986;
case 0x0c0bc988u: goto P_0c0bc988;
case 0x0c0bc98au: goto P_0c0bc98a;
case 0x0c0bc98cu: goto P_0c0bc98c;
case 0x0c0bc98eu: goto P_0c0bc98e;
case 0x0c0bc990u: goto P_0c0bc990;
case 0x0c0bc992u: goto P_0c0bc992;
case 0x0c0bc994u: goto P_0c0bc994;
case 0x0c0bc996u: goto P_0c0bc996;
case 0x0c0bc998u: goto P_0c0bc998;
case 0x0c0bc99au: goto P_0c0bc99a;
case 0x0c0bc99cu: goto P_0c0bc99c;
case 0x0c0bc99eu: goto P_0c0bc99e;
case 0x0c0bc9a0u: goto P_0c0bc9a0;
case 0x0c0bc9a2u: goto P_0c0bc9a2;
case 0x0c0bc9a4u: goto P_0c0bc9a4;
case 0x0c0bc9a6u: goto P_0c0bc9a6;
case 0x0c0bc9a8u: goto P_0c0bc9a8;
case 0x0c0bc9aau: goto P_0c0bc9aa;
case 0x0c0bc9acu: goto P_0c0bc9ac;
case 0x0c0bc9aeu: goto P_0c0bc9ae;
case 0x0c0bc9b0u: goto P_0c0bc9b0;
case 0x0c0bc9b2u: goto P_0c0bc9b2;
case 0x0c0bc9b4u: goto P_0c0bc9b4;
case 0x0c0bc9b6u: goto P_0c0bc9b6;
case 0x0c0bc9b8u: goto P_0c0bc9b8;
case 0x0c0bc9bau: goto P_0c0bc9ba;
case 0x0c0bc9bcu: goto P_0c0bc9bc;
case 0x0c0bc9beu: goto P_0c0bc9be;
case 0x0c0bc9c0u: goto P_0c0bc9c0;
case 0x0c0bc9c2u: goto P_0c0bc9c2;
case 0x0c0bc9c4u: goto P_0c0bc9c4;
case 0x0c0bc9c6u: goto P_0c0bc9c6;
case 0x0c0bc9c8u: goto P_0c0bc9c8;
case 0x0c0bc9cau: goto P_0c0bc9ca;
case 0x0c0bc9ccu: goto P_0c0bc9cc;
case 0x0c0bc9ceu: goto P_0c0bc9ce;
case 0x0c0bc9d0u: goto P_0c0bc9d0;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0bc5ae: /* original 2fe6, guest PC 0x0c0bc5ae */
if(!s->budget--) { s->failed_pc=0x0c0bc5aeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bc5b0;
P_0c0bc5b0: /* original 2fd6, guest PC 0x0c0bc5b0 */
if(!s->budget--) { s->failed_pc=0x0c0bc5b0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bc5b2;
P_0c0bc5b2: /* original 2fc6, guest PC 0x0c0bc5b2 */
if(!s->budget--) { s->failed_pc=0x0c0bc5b2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bc5b4;
P_0c0bc5b4: /* original 2fb6, guest PC 0x0c0bc5b4 */
if(!s->budget--) { s->failed_pc=0x0c0bc5b4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bc5b6;
P_0c0bc5b6: /* original 2fa6, guest PC 0x0c0bc5b6 */
if(!s->budget--) { s->failed_pc=0x0c0bc5b6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bc5b8;
P_0c0bc5b8: /* original 2f96, guest PC 0x0c0bc5b8 */
if(!s->budget--) { s->failed_pc=0x0c0bc5b8u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bc5ba;
P_0c0bc5ba: /* original 4f22, guest PC 0x0c0bc5ba */
if(!s->budget--) { s->failed_pc=0x0c0bc5bau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0bc5bc;
P_0c0bc5bc: /* original 5d44, guest PC 0x0c0bc5bc */
if(!s->budget--) { s->failed_pc=0x0c0bc5bcu; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0bc5be;
P_0c0bc5be: /* original 94a8, guest PC 0x0c0bc5be */
if(!s->budget--) { s->failed_pc=0x0c0bc5beu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc712u,2);
goto P_0c0bc5c0;
P_0c0bc5c0: /* original de6e, guest PC 0x0c0bc5c0 */
if(!s->budget--) { s->failed_pc=0x0c0bc5c0u; return 0; }
r[14]=read(ram,0x0c0bc77cu,4);
goto P_0c0bc5c2;
P_0c0bc5c2: /* original 7ff8, guest PC 0x0c0bc5c2 */
if(!s->budget--) { s->failed_pc=0x0c0bc5c2u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0bc5c4;
P_0c0bc5c4: /* original 4e0b, guest PC 0x0c0bc5c4 */
if(!s->budget--) { s->failed_pc=0x0c0bc5c4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc5c8u;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc5c8u) { target=s->pc; goto dispatch; }
goto P_0c0bc5c8;
P_0c0bc5c6: /* original 65d2, guest PC 0x0c0bc5c6 */
if(!s->budget--) { s->failed_pc=0x0c0bc5c6u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0bc5c8;
P_0c0bc5c8: /* original 94a4, guest PC 0x0c0bc5c8 */
if(!s->budget--) { s->failed_pc=0x0c0bc5c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc714u,2);
goto P_0c0bc5ca;
P_0c0bc5ca: /* original 4e0b, guest PC 0x0c0bc5ca */
if(!s->budget--) { s->failed_pc=0x0c0bc5cau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc5ceu;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc5ceu) { target=s->pc; goto dispatch; }
goto P_0c0bc5ce;
P_0c0bc5cc: /* original 55d1, guest PC 0x0c0bc5cc */
if(!s->budget--) { s->failed_pc=0x0c0bc5ccu; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0bc5ce;
P_0c0bc5ce: /* original 94a2, guest PC 0x0c0bc5ce */
if(!s->budget--) { s->failed_pc=0x0c0bc5ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc716u,2);
goto P_0c0bc5d0;
P_0c0bc5d0: /* original 4e0b, guest PC 0x0c0bc5d0 */
if(!s->budget--) { s->failed_pc=0x0c0bc5d0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc5d4u;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc5d4u) { target=s->pc; goto dispatch; }
goto P_0c0bc5d4;
P_0c0bc5d2: /* original 55d2, guest PC 0x0c0bc5d2 */
if(!s->budget--) { s->failed_pc=0x0c0bc5d2u; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0bc5d4;
P_0c0bc5d4: /* original 94a0, guest PC 0x0c0bc5d4 */
if(!s->budget--) { s->failed_pc=0x0c0bc5d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc718u,2);
goto P_0c0bc5d6;
P_0c0bc5d6: /* original 4e0b, guest PC 0x0c0bc5d6 */
if(!s->budget--) { s->failed_pc=0x0c0bc5d6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc5dau;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc5dau) { target=s->pc; goto dispatch; }
goto P_0c0bc5da;
P_0c0bc5d8: /* original 55d3, guest PC 0x0c0bc5d8 */
if(!s->budget--) { s->failed_pc=0x0c0bc5d8u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0bc5da;
P_0c0bc5da: /* original 949e, guest PC 0x0c0bc5da */
if(!s->budget--) { s->failed_pc=0x0c0bc5dau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc71au,2);
goto P_0c0bc5dc;
P_0c0bc5dc: /* original 4e0b, guest PC 0x0c0bc5dc */
if(!s->budget--) { s->failed_pc=0x0c0bc5dcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc5e0u;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc5e0u) { target=s->pc; goto dispatch; }
goto P_0c0bc5e0;
P_0c0bc5de: /* original 55d4, guest PC 0x0c0bc5de */
if(!s->budget--) { s->failed_pc=0x0c0bc5deu; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0bc5e0;
P_0c0bc5e0: /* original 949c, guest PC 0x0c0bc5e0 */
if(!s->budget--) { s->failed_pc=0x0c0bc5e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc71cu,2);
goto P_0c0bc5e2;
P_0c0bc5e2: /* original 4e0b, guest PC 0x0c0bc5e2 */
if(!s->budget--) { s->failed_pc=0x0c0bc5e2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc5e6u;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc5e6u) { target=s->pc; goto dispatch; }
goto P_0c0bc5e6;
P_0c0bc5e4: /* original 55d5, guest PC 0x0c0bc5e4 */
if(!s->budget--) { s->failed_pc=0x0c0bc5e4u; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0bc5e6;
P_0c0bc5e6: /* original 949a, guest PC 0x0c0bc5e6 */
if(!s->budget--) { s->failed_pc=0x0c0bc5e6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc71eu,2);
goto P_0c0bc5e8;
P_0c0bc5e8: /* original 4e0b, guest PC 0x0c0bc5e8 */
if(!s->budget--) { s->failed_pc=0x0c0bc5e8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc5ecu;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc5ecu) { target=s->pc; goto dispatch; }
goto P_0c0bc5ec;
P_0c0bc5ea: /* original 55d6, guest PC 0x0c0bc5ea */
if(!s->budget--) { s->failed_pc=0x0c0bc5eau; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0bc5ec;
P_0c0bc5ec: /* original 9498, guest PC 0x0c0bc5ec */
if(!s->budget--) { s->failed_pc=0x0c0bc5ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc720u,2);
goto P_0c0bc5ee;
P_0c0bc5ee: /* original 4e0b, guest PC 0x0c0bc5ee */
if(!s->budget--) { s->failed_pc=0x0c0bc5eeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc5f2u;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc5f2u) { target=s->pc; goto dispatch; }
goto P_0c0bc5f2;
P_0c0bc5f0: /* original 55d7, guest PC 0x0c0bc5f0 */
if(!s->budget--) { s->failed_pc=0x0c0bc5f0u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0bc5f2;
P_0c0bc5f2: /* original 9496, guest PC 0x0c0bc5f2 */
if(!s->budget--) { s->failed_pc=0x0c0bc5f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc722u,2);
goto P_0c0bc5f4;
P_0c0bc5f4: /* original 4e0b, guest PC 0x0c0bc5f4 */
if(!s->budget--) { s->failed_pc=0x0c0bc5f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc5f8u;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc5f8u) { target=s->pc; goto dispatch; }
goto P_0c0bc5f8;
P_0c0bc5f6: /* original 55d8, guest PC 0x0c0bc5f6 */
if(!s->budget--) { s->failed_pc=0x0c0bc5f6u; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0bc5f8;
P_0c0bc5f8: /* original 9494, guest PC 0x0c0bc5f8 */
if(!s->budget--) { s->failed_pc=0x0c0bc5f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc724u,2);
goto P_0c0bc5fa;
P_0c0bc5fa: /* original 4e0b, guest PC 0x0c0bc5fa */
if(!s->budget--) { s->failed_pc=0x0c0bc5fau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc5feu;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc5feu) { target=s->pc; goto dispatch; }
goto P_0c0bc5fe;
P_0c0bc5fc: /* original 55d9, guest PC 0x0c0bc5fc */
if(!s->budget--) { s->failed_pc=0x0c0bc5fcu; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0bc5fe;
P_0c0bc5fe: /* original 9492, guest PC 0x0c0bc5fe */
if(!s->budget--) { s->failed_pc=0x0c0bc5feu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc726u,2);
goto P_0c0bc600;
P_0c0bc600: /* original 4e0b, guest PC 0x0c0bc600 */
if(!s->budget--) { s->failed_pc=0x0c0bc600u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc604u;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc604u) { target=s->pc; goto dispatch; }
goto P_0c0bc604;
P_0c0bc602: /* original 55da, guest PC 0x0c0bc602 */
if(!s->budget--) { s->failed_pc=0x0c0bc602u; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0bc604;
P_0c0bc604: /* original 9490, guest PC 0x0c0bc604 */
if(!s->budget--) { s->failed_pc=0x0c0bc604u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc728u,2);
goto P_0c0bc606;
P_0c0bc606: /* original 4e0b, guest PC 0x0c0bc606 */
if(!s->budget--) { s->failed_pc=0x0c0bc606u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc60au;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc60au) { target=s->pc; goto dispatch; }
goto P_0c0bc60a;
P_0c0bc608: /* original 55db, guest PC 0x0c0bc608 */
if(!s->budget--) { s->failed_pc=0x0c0bc608u; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0bc60a;
P_0c0bc60a: /* original 948e, guest PC 0x0c0bc60a */
if(!s->budget--) { s->failed_pc=0x0c0bc60au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc72au,2);
goto P_0c0bc60c;
P_0c0bc60c: /* original 4e0b, guest PC 0x0c0bc60c */
if(!s->budget--) { s->failed_pc=0x0c0bc60cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc610u;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc610u) { target=s->pc; goto dispatch; }
goto P_0c0bc610;
P_0c0bc60e: /* original 55dc, guest PC 0x0c0bc60e */
if(!s->budget--) { s->failed_pc=0x0c0bc60eu; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0bc610;
P_0c0bc610: /* original 948c, guest PC 0x0c0bc610 */
if(!s->budget--) { s->failed_pc=0x0c0bc610u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc72cu,2);
goto P_0c0bc612;
P_0c0bc612: /* original 4e0b, guest PC 0x0c0bc612 */
if(!s->budget--) { s->failed_pc=0x0c0bc612u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc616u;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc616u) { target=s->pc; goto dispatch; }
goto P_0c0bc616;
P_0c0bc614: /* original 55dd, guest PC 0x0c0bc614 */
if(!s->budget--) { s->failed_pc=0x0c0bc614u; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0bc616;
P_0c0bc616: /* original 948a, guest PC 0x0c0bc616 */
if(!s->budget--) { s->failed_pc=0x0c0bc616u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc72eu,2);
goto P_0c0bc618;
P_0c0bc618: /* original 4e0b, guest PC 0x0c0bc618 */
if(!s->budget--) { s->failed_pc=0x0c0bc618u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc61cu;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc61cu) { target=s->pc; goto dispatch; }
goto P_0c0bc61c;
P_0c0bc61a: /* original 55de, guest PC 0x0c0bc61a */
if(!s->budget--) { s->failed_pc=0x0c0bc61au; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0bc61c;
P_0c0bc61c: /* original 9488, guest PC 0x0c0bc61c */
if(!s->budget--) { s->failed_pc=0x0c0bc61cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc730u,2);
goto P_0c0bc61e;
P_0c0bc61e: /* original 4e0b, guest PC 0x0c0bc61e */
if(!s->budget--) { s->failed_pc=0x0c0bc61eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc622u;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc622u) { target=s->pc; goto dispatch; }
goto P_0c0bc622;
P_0c0bc620: /* original 55df, guest PC 0x0c0bc620 */
if(!s->budget--) { s->failed_pc=0x0c0bc620u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0bc622;
P_0c0bc622: /* original 9486, guest PC 0x0c0bc622 */
if(!s->budget--) { s->failed_pc=0x0c0bc622u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc732u,2);
goto P_0c0bc624;
P_0c0bc624: /* original e040, guest PC 0x0c0bc624 */
if(!s->budget--) { s->failed_pc=0x0c0bc624u; return 0; }
r[0]=0x00000040u;
goto P_0c0bc626;
P_0c0bc626: /* original 4e0b, guest PC 0x0c0bc626 */
if(!s->budget--) { s->failed_pc=0x0c0bc626u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc62au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc62au) { target=s->pc; goto dispatch; }
goto P_0c0bc62a;
P_0c0bc628: /* original 05de, guest PC 0x0c0bc628 */
if(!s->budget--) { s->failed_pc=0x0c0bc628u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc62a;
P_0c0bc62a: /* original 9483, guest PC 0x0c0bc62a */
if(!s->budget--) { s->failed_pc=0x0c0bc62au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc734u,2);
goto P_0c0bc62c;
P_0c0bc62c: /* original e044, guest PC 0x0c0bc62c */
if(!s->budget--) { s->failed_pc=0x0c0bc62cu; return 0; }
r[0]=0x00000044u;
goto P_0c0bc62e;
P_0c0bc62e: /* original 4e0b, guest PC 0x0c0bc62e */
if(!s->budget--) { s->failed_pc=0x0c0bc62eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc632u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc632u) { target=s->pc; goto dispatch; }
goto P_0c0bc632;
P_0c0bc630: /* original 05de, guest PC 0x0c0bc630 */
if(!s->budget--) { s->failed_pc=0x0c0bc630u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc632;
P_0c0bc632: /* original 9480, guest PC 0x0c0bc632 */
if(!s->budget--) { s->failed_pc=0x0c0bc632u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc736u,2);
goto P_0c0bc634;
P_0c0bc634: /* original e048, guest PC 0x0c0bc634 */
if(!s->budget--) { s->failed_pc=0x0c0bc634u; return 0; }
r[0]=0x00000048u;
goto P_0c0bc636;
P_0c0bc636: /* original 4e0b, guest PC 0x0c0bc636 */
if(!s->budget--) { s->failed_pc=0x0c0bc636u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc63au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc63au) { target=s->pc; goto dispatch; }
goto P_0c0bc63a;
P_0c0bc638: /* original 05de, guest PC 0x0c0bc638 */
if(!s->budget--) { s->failed_pc=0x0c0bc638u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc63a;
P_0c0bc63a: /* original 947d, guest PC 0x0c0bc63a */
if(!s->budget--) { s->failed_pc=0x0c0bc63au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc738u,2);
goto P_0c0bc63c;
P_0c0bc63c: /* original e04c, guest PC 0x0c0bc63c */
if(!s->budget--) { s->failed_pc=0x0c0bc63cu; return 0; }
r[0]=0x0000004cu;
goto P_0c0bc63e;
P_0c0bc63e: /* original 4e0b, guest PC 0x0c0bc63e */
if(!s->budget--) { s->failed_pc=0x0c0bc63eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc642u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc642u) { target=s->pc; goto dispatch; }
goto P_0c0bc642;
P_0c0bc640: /* original 05de, guest PC 0x0c0bc640 */
if(!s->budget--) { s->failed_pc=0x0c0bc640u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc642;
P_0c0bc642: /* original 947a, guest PC 0x0c0bc642 */
if(!s->budget--) { s->failed_pc=0x0c0bc642u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc73au,2);
goto P_0c0bc644;
P_0c0bc644: /* original e050, guest PC 0x0c0bc644 */
if(!s->budget--) { s->failed_pc=0x0c0bc644u; return 0; }
r[0]=0x00000050u;
goto P_0c0bc646;
P_0c0bc646: /* original 4e0b, guest PC 0x0c0bc646 */
if(!s->budget--) { s->failed_pc=0x0c0bc646u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc64au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc64au) { target=s->pc; goto dispatch; }
goto P_0c0bc64a;
P_0c0bc648: /* original 05de, guest PC 0x0c0bc648 */
if(!s->budget--) { s->failed_pc=0x0c0bc648u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc64a;
P_0c0bc64a: /* original 9477, guest PC 0x0c0bc64a */
if(!s->budget--) { s->failed_pc=0x0c0bc64au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc73cu,2);
goto P_0c0bc64c;
P_0c0bc64c: /* original e054, guest PC 0x0c0bc64c */
if(!s->budget--) { s->failed_pc=0x0c0bc64cu; return 0; }
r[0]=0x00000054u;
goto P_0c0bc64e;
P_0c0bc64e: /* original 4e0b, guest PC 0x0c0bc64e */
if(!s->budget--) { s->failed_pc=0x0c0bc64eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc652u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc652u) { target=s->pc; goto dispatch; }
goto P_0c0bc652;
P_0c0bc650: /* original 05de, guest PC 0x0c0bc650 */
if(!s->budget--) { s->failed_pc=0x0c0bc650u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc652;
P_0c0bc652: /* original 9474, guest PC 0x0c0bc652 */
if(!s->budget--) { s->failed_pc=0x0c0bc652u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc73eu,2);
goto P_0c0bc654;
P_0c0bc654: /* original e058, guest PC 0x0c0bc654 */
if(!s->budget--) { s->failed_pc=0x0c0bc654u; return 0; }
r[0]=0x00000058u;
goto P_0c0bc656;
P_0c0bc656: /* original 4e0b, guest PC 0x0c0bc656 */
if(!s->budget--) { s->failed_pc=0x0c0bc656u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc65au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc65au) { target=s->pc; goto dispatch; }
goto P_0c0bc65a;
P_0c0bc658: /* original 05de, guest PC 0x0c0bc658 */
if(!s->budget--) { s->failed_pc=0x0c0bc658u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc65a;
P_0c0bc65a: /* original 9471, guest PC 0x0c0bc65a */
if(!s->budget--) { s->failed_pc=0x0c0bc65au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc740u,2);
goto P_0c0bc65c;
P_0c0bc65c: /* original e05c, guest PC 0x0c0bc65c */
if(!s->budget--) { s->failed_pc=0x0c0bc65cu; return 0; }
r[0]=0x0000005cu;
goto P_0c0bc65e;
P_0c0bc65e: /* original 4e0b, guest PC 0x0c0bc65e */
if(!s->budget--) { s->failed_pc=0x0c0bc65eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc662u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc662u) { target=s->pc; goto dispatch; }
goto P_0c0bc662;
P_0c0bc660: /* original 05de, guest PC 0x0c0bc660 */
if(!s->budget--) { s->failed_pc=0x0c0bc660u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc662;
P_0c0bc662: /* original 946e, guest PC 0x0c0bc662 */
if(!s->budget--) { s->failed_pc=0x0c0bc662u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc742u,2);
goto P_0c0bc664;
P_0c0bc664: /* original e060, guest PC 0x0c0bc664 */
if(!s->budget--) { s->failed_pc=0x0c0bc664u; return 0; }
r[0]=0x00000060u;
goto P_0c0bc666;
P_0c0bc666: /* original 4e0b, guest PC 0x0c0bc666 */
if(!s->budget--) { s->failed_pc=0x0c0bc666u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc66au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc66au) { target=s->pc; goto dispatch; }
goto P_0c0bc66a;
P_0c0bc668: /* original 05de, guest PC 0x0c0bc668 */
if(!s->budget--) { s->failed_pc=0x0c0bc668u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc66a;
P_0c0bc66a: /* original 946b, guest PC 0x0c0bc66a */
if(!s->budget--) { s->failed_pc=0x0c0bc66au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc744u,2);
goto P_0c0bc66c;
P_0c0bc66c: /* original e064, guest PC 0x0c0bc66c */
if(!s->budget--) { s->failed_pc=0x0c0bc66cu; return 0; }
r[0]=0x00000064u;
goto P_0c0bc66e;
P_0c0bc66e: /* original 4e0b, guest PC 0x0c0bc66e */
if(!s->budget--) { s->failed_pc=0x0c0bc66eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc672u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc672u) { target=s->pc; goto dispatch; }
goto P_0c0bc672;
P_0c0bc670: /* original 05de, guest PC 0x0c0bc670 */
if(!s->budget--) { s->failed_pc=0x0c0bc670u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc672;
P_0c0bc672: /* original 9468, guest PC 0x0c0bc672 */
if(!s->budget--) { s->failed_pc=0x0c0bc672u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc746u,2);
goto P_0c0bc674;
P_0c0bc674: /* original e068, guest PC 0x0c0bc674 */
if(!s->budget--) { s->failed_pc=0x0c0bc674u; return 0; }
r[0]=0x00000068u;
goto P_0c0bc676;
P_0c0bc676: /* original 4e0b, guest PC 0x0c0bc676 */
if(!s->budget--) { s->failed_pc=0x0c0bc676u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc67au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc67au) { target=s->pc; goto dispatch; }
goto P_0c0bc67a;
P_0c0bc678: /* original 05de, guest PC 0x0c0bc678 */
if(!s->budget--) { s->failed_pc=0x0c0bc678u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc67a;
P_0c0bc67a: /* original 9465, guest PC 0x0c0bc67a */
if(!s->budget--) { s->failed_pc=0x0c0bc67au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc748u,2);
goto P_0c0bc67c;
P_0c0bc67c: /* original e06c, guest PC 0x0c0bc67c */
if(!s->budget--) { s->failed_pc=0x0c0bc67cu; return 0; }
r[0]=0x0000006cu;
goto P_0c0bc67e;
P_0c0bc67e: /* original 4e0b, guest PC 0x0c0bc67e */
if(!s->budget--) { s->failed_pc=0x0c0bc67eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc682u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc682u) { target=s->pc; goto dispatch; }
goto P_0c0bc682;
P_0c0bc680: /* original 05de, guest PC 0x0c0bc680 */
if(!s->budget--) { s->failed_pc=0x0c0bc680u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc682;
P_0c0bc682: /* original 9462, guest PC 0x0c0bc682 */
if(!s->budget--) { s->failed_pc=0x0c0bc682u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc74au,2);
goto P_0c0bc684;
P_0c0bc684: /* original e070, guest PC 0x0c0bc684 */
if(!s->budget--) { s->failed_pc=0x0c0bc684u; return 0; }
r[0]=0x00000070u;
goto P_0c0bc686;
P_0c0bc686: /* original 4e0b, guest PC 0x0c0bc686 */
if(!s->budget--) { s->failed_pc=0x0c0bc686u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc68au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc68au) { target=s->pc; goto dispatch; }
goto P_0c0bc68a;
P_0c0bc688: /* original 05de, guest PC 0x0c0bc688 */
if(!s->budget--) { s->failed_pc=0x0c0bc688u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc68a;
P_0c0bc68a: /* original 945f, guest PC 0x0c0bc68a */
if(!s->budget--) { s->failed_pc=0x0c0bc68au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc74cu,2);
goto P_0c0bc68c;
P_0c0bc68c: /* original e074, guest PC 0x0c0bc68c */
if(!s->budget--) { s->failed_pc=0x0c0bc68cu; return 0; }
r[0]=0x00000074u;
goto P_0c0bc68e;
P_0c0bc68e: /* original 4e0b, guest PC 0x0c0bc68e */
if(!s->budget--) { s->failed_pc=0x0c0bc68eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc692u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc692u) { target=s->pc; goto dispatch; }
goto P_0c0bc692;
P_0c0bc690: /* original 05de, guest PC 0x0c0bc690 */
if(!s->budget--) { s->failed_pc=0x0c0bc690u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc692;
P_0c0bc692: /* original 945c, guest PC 0x0c0bc692 */
if(!s->budget--) { s->failed_pc=0x0c0bc692u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc74eu,2);
goto P_0c0bc694;
P_0c0bc694: /* original e078, guest PC 0x0c0bc694 */
if(!s->budget--) { s->failed_pc=0x0c0bc694u; return 0; }
r[0]=0x00000078u;
goto P_0c0bc696;
P_0c0bc696: /* original 4e0b, guest PC 0x0c0bc696 */
if(!s->budget--) { s->failed_pc=0x0c0bc696u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc69au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc69au) { target=s->pc; goto dispatch; }
goto P_0c0bc69a;
P_0c0bc698: /* original 05de, guest PC 0x0c0bc698 */
if(!s->budget--) { s->failed_pc=0x0c0bc698u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc69a;
P_0c0bc69a: /* original 9459, guest PC 0x0c0bc69a */
if(!s->budget--) { s->failed_pc=0x0c0bc69au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc750u,2);
goto P_0c0bc69c;
P_0c0bc69c: /* original e07c, guest PC 0x0c0bc69c */
if(!s->budget--) { s->failed_pc=0x0c0bc69cu; return 0; }
r[0]=0x0000007cu;
goto P_0c0bc69e;
P_0c0bc69e: /* original 4e0b, guest PC 0x0c0bc69e */
if(!s->budget--) { s->failed_pc=0x0c0bc69eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc6a2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc6a2u) { target=s->pc; goto dispatch; }
goto P_0c0bc6a2;
P_0c0bc6a0: /* original 05de, guest PC 0x0c0bc6a0 */
if(!s->budget--) { s->failed_pc=0x0c0bc6a0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc6a2;
P_0c0bc6a2: /* original 9457, guest PC 0x0c0bc6a2 */
if(!s->budget--) { s->failed_pc=0x0c0bc6a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc754u,2);
goto P_0c0bc6a4;
P_0c0bc6a4: /* original 9055, guest PC 0x0c0bc6a4 */
if(!s->budget--) { s->failed_pc=0x0c0bc6a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc752u,2);
goto P_0c0bc6a6;
P_0c0bc6a6: /* original 4e0b, guest PC 0x0c0bc6a6 */
if(!s->budget--) { s->failed_pc=0x0c0bc6a6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc6aau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc6aau) { target=s->pc; goto dispatch; }
goto P_0c0bc6aa;
P_0c0bc6a8: /* original 05de, guest PC 0x0c0bc6a8 */
if(!s->budget--) { s->failed_pc=0x0c0bc6a8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc6aa;
P_0c0bc6aa: /* original 9554, guest PC 0x0c0bc6aa */
if(!s->budget--) { s->failed_pc=0x0c0bc6aau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc756u,2);
goto P_0c0bc6ac;
P_0c0bc6ac: /* original 35dc, guest PC 0x0c0bc6ac */
if(!s->budget--) { s->failed_pc=0x0c0bc6acu; return 0; }
r[5]+=r[13];
goto P_0c0bc6ae;
P_0c0bc6ae: /* original 2f52, guest PC 0x0c0bc6ae */
if(!s->budget--) { s->failed_pc=0x0c0bc6aeu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bc6b0;
P_0c0bc6b0: /* original 9452, guest PC 0x0c0bc6b0 */
if(!s->budget--) { s->failed_pc=0x0c0bc6b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc758u,2);
goto P_0c0bc6b2;
P_0c0bc6b2: /* original 4e0b, guest PC 0x0c0bc6b2 */
if(!s->budget--) { s->failed_pc=0x0c0bc6b2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc6b6u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc6b6u) { target=s->pc; goto dispatch; }
goto P_0c0bc6b6;
P_0c0bc6b4: /* original 6552, guest PC 0x0c0bc6b4 */
if(!s->budget--) { s->failed_pc=0x0c0bc6b4u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc6b6;
P_0c0bc6b6: /* original 9550, guest PC 0x0c0bc6b6 */
if(!s->budget--) { s->failed_pc=0x0c0bc6b6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc75au,2);
goto P_0c0bc6b8;
P_0c0bc6b8: /* original 35dc, guest PC 0x0c0bc6b8 */
if(!s->budget--) { s->failed_pc=0x0c0bc6b8u; return 0; }
r[5]+=r[13];
goto P_0c0bc6ba;
P_0c0bc6ba: /* original 1f51, guest PC 0x0c0bc6ba */
if(!s->budget--) { s->failed_pc=0x0c0bc6bau; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0bc6bc;
P_0c0bc6bc: /* original 944e, guest PC 0x0c0bc6bc */
if(!s->budget--) { s->failed_pc=0x0c0bc6bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc75cu,2);
goto P_0c0bc6be;
P_0c0bc6be: /* original 4e0b, guest PC 0x0c0bc6be */
if(!s->budget--) { s->failed_pc=0x0c0bc6beu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc6c2u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc6c2u) { target=s->pc; goto dispatch; }
goto P_0c0bc6c2;
P_0c0bc6c0: /* original 6552, guest PC 0x0c0bc6c0 */
if(!s->budget--) { s->failed_pc=0x0c0bc6c0u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc6c2;
P_0c0bc6c2: /* original 944d, guest PC 0x0c0bc6c2 */
if(!s->budget--) { s->failed_pc=0x0c0bc6c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc760u,2);
goto P_0c0bc6c4;
P_0c0bc6c4: /* original 904b, guest PC 0x0c0bc6c4 */
if(!s->budget--) { s->failed_pc=0x0c0bc6c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc75eu,2);
goto P_0c0bc6c6;
P_0c0bc6c6: /* original 4e0b, guest PC 0x0c0bc6c6 */
if(!s->budget--) { s->failed_pc=0x0c0bc6c6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc6cau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc6cau) { target=s->pc; goto dispatch; }
goto P_0c0bc6ca;
P_0c0bc6c8: /* original 05de, guest PC 0x0c0bc6c8 */
if(!s->budget--) { s->failed_pc=0x0c0bc6c8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc6ca;
P_0c0bc6ca: /* original 944b, guest PC 0x0c0bc6ca */
if(!s->budget--) { s->failed_pc=0x0c0bc6cau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc764u,2);
goto P_0c0bc6cc;
P_0c0bc6cc: /* original 9049, guest PC 0x0c0bc6cc */
if(!s->budget--) { s->failed_pc=0x0c0bc6ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc762u,2);
goto P_0c0bc6ce;
P_0c0bc6ce: /* original 4e0b, guest PC 0x0c0bc6ce */
if(!s->budget--) { s->failed_pc=0x0c0bc6ceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc6d2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc6d2u) { target=s->pc; goto dispatch; }
goto P_0c0bc6d2;
P_0c0bc6d0: /* original 05de, guest PC 0x0c0bc6d0 */
if(!s->budget--) { s->failed_pc=0x0c0bc6d0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc6d2;
P_0c0bc6d2: /* original 9948, guest PC 0x0c0bc6d2 */
if(!s->budget--) { s->failed_pc=0x0c0bc6d2u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc766u,2);
goto P_0c0bc6d4;
P_0c0bc6d4: /* original 9448, guest PC 0x0c0bc6d4 */
if(!s->budget--) { s->failed_pc=0x0c0bc6d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc768u,2);
goto P_0c0bc6d6;
P_0c0bc6d6: /* original 39dc, guest PC 0x0c0bc6d6 */
if(!s->budget--) { s->failed_pc=0x0c0bc6d6u; return 0; }
r[9]+=r[13];
goto P_0c0bc6d8;
P_0c0bc6d8: /* original 4e0b, guest PC 0x0c0bc6d8 */
if(!s->budget--) { s->failed_pc=0x0c0bc6d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc6dcu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc6dcu) { target=s->pc; goto dispatch; }
goto P_0c0bc6dc;
P_0c0bc6da: /* original 6592, guest PC 0x0c0bc6da */
if(!s->budget--) { s->failed_pc=0x0c0bc6dau; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bc6dc;
P_0c0bc6dc: /* original 9445, guest PC 0x0c0bc6dc */
if(!s->budget--) { s->failed_pc=0x0c0bc6dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc76au,2);
goto P_0c0bc6de;
P_0c0bc6de: /* original 4e0b, guest PC 0x0c0bc6de */
if(!s->budget--) { s->failed_pc=0x0c0bc6deu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc6e2u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc6e2u) { target=s->pc; goto dispatch; }
goto P_0c0bc6e2;
P_0c0bc6e0: /* original 6592, guest PC 0x0c0bc6e0 */
if(!s->budget--) { s->failed_pc=0x0c0bc6e0u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bc6e2;
P_0c0bc6e2: /* original 9443, guest PC 0x0c0bc6e2 */
if(!s->budget--) { s->failed_pc=0x0c0bc6e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc76cu,2);
goto P_0c0bc6e4;
P_0c0bc6e4: /* original 4e0b, guest PC 0x0c0bc6e4 */
if(!s->budget--) { s->failed_pc=0x0c0bc6e4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc6e8u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc6e8u) { target=s->pc; goto dispatch; }
goto P_0c0bc6e8;
P_0c0bc6e6: /* original 6592, guest PC 0x0c0bc6e6 */
if(!s->budget--) { s->failed_pc=0x0c0bc6e6u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bc6e8;
P_0c0bc6e8: /* original 9441, guest PC 0x0c0bc6e8 */
if(!s->budget--) { s->failed_pc=0x0c0bc6e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc76eu,2);
goto P_0c0bc6ea;
P_0c0bc6ea: /* original 4e0b, guest PC 0x0c0bc6ea */
if(!s->budget--) { s->failed_pc=0x0c0bc6eau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc6eeu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc6eeu) { target=s->pc; goto dispatch; }
goto P_0c0bc6ee;
P_0c0bc6ec: /* original 6592, guest PC 0x0c0bc6ec */
if(!s->budget--) { s->failed_pc=0x0c0bc6ecu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bc6ee;
P_0c0bc6ee: /* original 9c3f, guest PC 0x0c0bc6ee */
if(!s->budget--) { s->failed_pc=0x0c0bc6eeu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc770u,2);
goto P_0c0bc6f0;
P_0c0bc6f0: /* original 943f, guest PC 0x0c0bc6f0 */
if(!s->budget--) { s->failed_pc=0x0c0bc6f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc772u,2);
goto P_0c0bc6f2;
P_0c0bc6f2: /* original 3cdc, guest PC 0x0c0bc6f2 */
if(!s->budget--) { s->failed_pc=0x0c0bc6f2u; return 0; }
r[12]+=r[13];
goto P_0c0bc6f4;
P_0c0bc6f4: /* original 4e0b, guest PC 0x0c0bc6f4 */
if(!s->budget--) { s->failed_pc=0x0c0bc6f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc6f8u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc6f8u) { target=s->pc; goto dispatch; }
goto P_0c0bc6f8;
P_0c0bc6f6: /* original 65c2, guest PC 0x0c0bc6f6 */
if(!s->budget--) { s->failed_pc=0x0c0bc6f6u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bc6f8;
P_0c0bc6f8: /* original 943c, guest PC 0x0c0bc6f8 */
if(!s->budget--) { s->failed_pc=0x0c0bc6f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc774u,2);
goto P_0c0bc6fa;
P_0c0bc6fa: /* original 4e0b, guest PC 0x0c0bc6fa */
if(!s->budget--) { s->failed_pc=0x0c0bc6fau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc6feu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc6feu) { target=s->pc; goto dispatch; }
goto P_0c0bc6fe;
P_0c0bc6fc: /* original 65c2, guest PC 0x0c0bc6fc */
if(!s->budget--) { s->failed_pc=0x0c0bc6fcu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bc6fe;
P_0c0bc6fe: /* original 943a, guest PC 0x0c0bc6fe */
if(!s->budget--) { s->failed_pc=0x0c0bc6feu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc776u,2);
goto P_0c0bc700;
P_0c0bc700: /* original 4e0b, guest PC 0x0c0bc700 */
if(!s->budget--) { s->failed_pc=0x0c0bc700u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc704u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc704u) { target=s->pc; goto dispatch; }
goto P_0c0bc704;
P_0c0bc702: /* original 65c2, guest PC 0x0c0bc702 */
if(!s->budget--) { s->failed_pc=0x0c0bc702u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bc704;
P_0c0bc704: /* original 9438, guest PC 0x0c0bc704 */
if(!s->budget--) { s->failed_pc=0x0c0bc704u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc778u,2);
goto P_0c0bc706;
P_0c0bc706: /* original 4e0b, guest PC 0x0c0bc706 */
if(!s->budget--) { s->failed_pc=0x0c0bc706u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc70au;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc70au) { target=s->pc; goto dispatch; }
goto P_0c0bc70a;
P_0c0bc708: /* original 65c2, guest PC 0x0c0bc708 */
if(!s->budget--) { s->failed_pc=0x0c0bc708u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bc70a;
P_0c0bc70a: /* original 9b36, guest PC 0x0c0bc70a */
if(!s->budget--) { s->failed_pc=0x0c0bc70au; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc77au,2);
goto P_0c0bc70c;
P_0c0bc70c: /* original 3bdc, guest PC 0x0c0bc70c */
if(!s->budget--) { s->failed_pc=0x0c0bc70cu; return 0; }
r[11]+=r[13];
goto P_0c0bc70e;
P_0c0bc70e: /* original a037, guest PC 0x0c0bc70e */
if(!s->budget--) { s->failed_pc=0x0c0bc70eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bc780;
P_0c0bc710: /* original 65b2, guest PC 0x0c0bc710 */
if(!s->budget--) { s->failed_pc=0x0c0bc710u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0bc712u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bc712u; return 0; } return 1;
P_0c0bc780: /* original 94ab, guest PC 0x0c0bc780 */
if(!s->budget--) { s->failed_pc=0x0c0bc780u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc8dau,2);
goto P_0c0bc782;
P_0c0bc782: /* original 4e0b, guest PC 0x0c0bc782 */
if(!s->budget--) { s->failed_pc=0x0c0bc782u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc786u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc786u) { target=s->pc; goto dispatch; }
goto P_0c0bc786;
P_0c0bc784: /* original 0009, guest PC 0x0c0bc784 */
if(!s->budget--) { s->failed_pc=0x0c0bc784u; return 0; }
goto P_0c0bc786;
P_0c0bc786: /* original 94a9, guest PC 0x0c0bc786 */
if(!s->budget--) { s->failed_pc=0x0c0bc786u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc8dcu,2);
goto P_0c0bc788;
P_0c0bc788: /* original 4e0b, guest PC 0x0c0bc788 */
if(!s->budget--) { s->failed_pc=0x0c0bc788u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc78cu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc78cu) { target=s->pc; goto dispatch; }
goto P_0c0bc78c;
P_0c0bc78a: /* original 65b2, guest PC 0x0c0bc78a */
if(!s->budget--) { s->failed_pc=0x0c0bc78au; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bc78c;
P_0c0bc78c: /* original 94a7, guest PC 0x0c0bc78c */
if(!s->budget--) { s->failed_pc=0x0c0bc78cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc8deu,2);
goto P_0c0bc78e;
P_0c0bc78e: /* original 4e0b, guest PC 0x0c0bc78e */
if(!s->budget--) { s->failed_pc=0x0c0bc78eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc792u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc792u) { target=s->pc; goto dispatch; }
goto P_0c0bc792;
P_0c0bc790: /* original 65b2, guest PC 0x0c0bc790 */
if(!s->budget--) { s->failed_pc=0x0c0bc790u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bc792;
P_0c0bc792: /* original 94a5, guest PC 0x0c0bc792 */
if(!s->budget--) { s->failed_pc=0x0c0bc792u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc8e0u,2);
goto P_0c0bc794;
P_0c0bc794: /* original 4e0b, guest PC 0x0c0bc794 */
if(!s->budget--) { s->failed_pc=0x0c0bc794u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc798u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc798u) { target=s->pc; goto dispatch; }
goto P_0c0bc798;
P_0c0bc796: /* original 65b2, guest PC 0x0c0bc796 */
if(!s->budget--) { s->failed_pc=0x0c0bc796u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bc798;
P_0c0bc798: /* original 9aa3, guest PC 0x0c0bc798 */
if(!s->budget--) { s->failed_pc=0x0c0bc798u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc8e2u,2);
goto P_0c0bc79a;
P_0c0bc79a: /* original 94a3, guest PC 0x0c0bc79a */
if(!s->budget--) { s->failed_pc=0x0c0bc79au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc8e4u,2);
goto P_0c0bc79c;
P_0c0bc79c: /* original 3adc, guest PC 0x0c0bc79c */
if(!s->budget--) { s->failed_pc=0x0c0bc79cu; return 0; }
r[10]+=r[13];
goto P_0c0bc79e;
P_0c0bc79e: /* original 4e0b, guest PC 0x0c0bc79e */
if(!s->budget--) { s->failed_pc=0x0c0bc79eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc7a2u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc7a2u) { target=s->pc; goto dispatch; }
goto P_0c0bc7a2;
P_0c0bc7a0: /* original 65a2, guest PC 0x0c0bc7a0 */
if(!s->budget--) { s->failed_pc=0x0c0bc7a0u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bc7a2;
P_0c0bc7a2: /* original 94a0, guest PC 0x0c0bc7a2 */
if(!s->budget--) { s->failed_pc=0x0c0bc7a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc8e6u,2);
goto P_0c0bc7a4;
P_0c0bc7a4: /* original 4e0b, guest PC 0x0c0bc7a4 */
if(!s->budget--) { s->failed_pc=0x0c0bc7a4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc7a8u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc7a8u) { target=s->pc; goto dispatch; }
goto P_0c0bc7a8;
P_0c0bc7a6: /* original 65a2, guest PC 0x0c0bc7a6 */
if(!s->budget--) { s->failed_pc=0x0c0bc7a6u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bc7a8;
P_0c0bc7a8: /* original 949e, guest PC 0x0c0bc7a8 */
if(!s->budget--) { s->failed_pc=0x0c0bc7a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc8e8u,2);
goto P_0c0bc7aa;
P_0c0bc7aa: /* original 4e0b, guest PC 0x0c0bc7aa */
if(!s->budget--) { s->failed_pc=0x0c0bc7aau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc7aeu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc7aeu) { target=s->pc; goto dispatch; }
goto P_0c0bc7ae;
P_0c0bc7ac: /* original 65a2, guest PC 0x0c0bc7ac */
if(!s->budget--) { s->failed_pc=0x0c0bc7acu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bc7ae;
P_0c0bc7ae: /* original 949c, guest PC 0x0c0bc7ae */
if(!s->budget--) { s->failed_pc=0x0c0bc7aeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc8eau,2);
goto P_0c0bc7b0;
P_0c0bc7b0: /* original 4e0b, guest PC 0x0c0bc7b0 */
if(!s->budget--) { s->failed_pc=0x0c0bc7b0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc7b4u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc7b4u) { target=s->pc; goto dispatch; }
goto P_0c0bc7b4;
P_0c0bc7b2: /* original 65a2, guest PC 0x0c0bc7b2 */
if(!s->budget--) { s->failed_pc=0x0c0bc7b2u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bc7b4;
P_0c0bc7b4: /* original 949a, guest PC 0x0c0bc7b4 */
if(!s->budget--) { s->failed_pc=0x0c0bc7b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc8ecu,2);
goto P_0c0bc7b6;
P_0c0bc7b6: /* original 65f2, guest PC 0x0c0bc7b6 */
if(!s->budget--) { s->failed_pc=0x0c0bc7b6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bc7b8;
P_0c0bc7b8: /* original 4e0b, guest PC 0x0c0bc7b8 */
if(!s->budget--) { s->failed_pc=0x0c0bc7b8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc7bcu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc7bcu) { target=s->pc; goto dispatch; }
goto P_0c0bc7bc;
P_0c0bc7ba: /* original 6552, guest PC 0x0c0bc7ba */
if(!s->budget--) { s->failed_pc=0x0c0bc7bau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc7bc;
P_0c0bc7bc: /* original 9497, guest PC 0x0c0bc7bc */
if(!s->budget--) { s->failed_pc=0x0c0bc7bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc8eeu,2);
goto P_0c0bc7be;
P_0c0bc7be: /* original 55f1, guest PC 0x0c0bc7be */
if(!s->budget--) { s->failed_pc=0x0c0bc7beu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0bc7c0;
P_0c0bc7c0: /* original 4e0b, guest PC 0x0c0bc7c0 */
if(!s->budget--) { s->failed_pc=0x0c0bc7c0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc7c4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc7c4u) { target=s->pc; goto dispatch; }
goto P_0c0bc7c4;
P_0c0bc7c2: /* original 6552, guest PC 0x0c0bc7c2 */
if(!s->budget--) { s->failed_pc=0x0c0bc7c2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc7c4;
P_0c0bc7c4: /* original 9494, guest PC 0x0c0bc7c4 */
if(!s->budget--) { s->failed_pc=0x0c0bc7c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc8f0u,2);
goto P_0c0bc7c6;
P_0c0bc7c6: /* original 4e0b, guest PC 0x0c0bc7c6 */
if(!s->budget--) { s->failed_pc=0x0c0bc7c6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc7cau;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc7cau) { target=s->pc; goto dispatch; }
goto P_0c0bc7ca;
P_0c0bc7c8: /* original 6592, guest PC 0x0c0bc7c8 */
if(!s->budget--) { s->failed_pc=0x0c0bc7c8u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bc7ca;
P_0c0bc7ca: /* original 9492, guest PC 0x0c0bc7ca */
if(!s->budget--) { s->failed_pc=0x0c0bc7cau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc8f2u,2);
goto P_0c0bc7cc;
P_0c0bc7cc: /* original 4e0b, guest PC 0x0c0bc7cc */
if(!s->budget--) { s->failed_pc=0x0c0bc7ccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc7d0u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc7d0u) { target=s->pc; goto dispatch; }
goto P_0c0bc7d0;
P_0c0bc7ce: /* original 6592, guest PC 0x0c0bc7ce */
if(!s->budget--) { s->failed_pc=0x0c0bc7ceu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bc7d0;
P_0c0bc7d0: /* original 9490, guest PC 0x0c0bc7d0 */
if(!s->budget--) { s->failed_pc=0x0c0bc7d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc8f4u,2);
goto P_0c0bc7d2;
P_0c0bc7d2: /* original 4e0b, guest PC 0x0c0bc7d2 */
if(!s->budget--) { s->failed_pc=0x0c0bc7d2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc7d6u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc7d6u) { target=s->pc; goto dispatch; }
goto P_0c0bc7d6;
P_0c0bc7d4: /* original 6592, guest PC 0x0c0bc7d4 */
if(!s->budget--) { s->failed_pc=0x0c0bc7d4u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bc7d6;
P_0c0bc7d6: /* original 948e, guest PC 0x0c0bc7d6 */
if(!s->budget--) { s->failed_pc=0x0c0bc7d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc8f6u,2);
goto P_0c0bc7d8;
P_0c0bc7d8: /* original 4e0b, guest PC 0x0c0bc7d8 */
if(!s->budget--) { s->failed_pc=0x0c0bc7d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc7dcu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc7dcu) { target=s->pc; goto dispatch; }
goto P_0c0bc7dc;
P_0c0bc7da: /* original 6592, guest PC 0x0c0bc7da */
if(!s->budget--) { s->failed_pc=0x0c0bc7dau; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bc7dc;
P_0c0bc7dc: /* original 948c, guest PC 0x0c0bc7dc */
if(!s->budget--) { s->failed_pc=0x0c0bc7dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc8f8u,2);
goto P_0c0bc7de;
P_0c0bc7de: /* original 4e0b, guest PC 0x0c0bc7de */
if(!s->budget--) { s->failed_pc=0x0c0bc7deu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc7e2u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc7e2u) { target=s->pc; goto dispatch; }
goto P_0c0bc7e2;
P_0c0bc7e0: /* original 65c2, guest PC 0x0c0bc7e0 */
if(!s->budget--) { s->failed_pc=0x0c0bc7e0u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bc7e2;
P_0c0bc7e2: /* original 948a, guest PC 0x0c0bc7e2 */
if(!s->budget--) { s->failed_pc=0x0c0bc7e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc8fau,2);
goto P_0c0bc7e4;
P_0c0bc7e4: /* original 4e0b, guest PC 0x0c0bc7e4 */
if(!s->budget--) { s->failed_pc=0x0c0bc7e4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc7e8u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc7e8u) { target=s->pc; goto dispatch; }
goto P_0c0bc7e8;
P_0c0bc7e6: /* original 65c2, guest PC 0x0c0bc7e6 */
if(!s->budget--) { s->failed_pc=0x0c0bc7e6u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bc7e8;
P_0c0bc7e8: /* original 9488, guest PC 0x0c0bc7e8 */
if(!s->budget--) { s->failed_pc=0x0c0bc7e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc8fcu,2);
goto P_0c0bc7ea;
P_0c0bc7ea: /* original 4e0b, guest PC 0x0c0bc7ea */
if(!s->budget--) { s->failed_pc=0x0c0bc7eau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc7eeu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc7eeu) { target=s->pc; goto dispatch; }
goto P_0c0bc7ee;
P_0c0bc7ec: /* original 65c2, guest PC 0x0c0bc7ec */
if(!s->budget--) { s->failed_pc=0x0c0bc7ecu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bc7ee;
P_0c0bc7ee: /* original 9486, guest PC 0x0c0bc7ee */
if(!s->budget--) { s->failed_pc=0x0c0bc7eeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc8feu,2);
goto P_0c0bc7f0;
P_0c0bc7f0: /* original 4e0b, guest PC 0x0c0bc7f0 */
if(!s->budget--) { s->failed_pc=0x0c0bc7f0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc7f4u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc7f4u) { target=s->pc; goto dispatch; }
goto P_0c0bc7f4;
P_0c0bc7f2: /* original 65c2, guest PC 0x0c0bc7f2 */
if(!s->budget--) { s->failed_pc=0x0c0bc7f2u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bc7f4;
P_0c0bc7f4: /* original 9484, guest PC 0x0c0bc7f4 */
if(!s->budget--) { s->failed_pc=0x0c0bc7f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc900u,2);
goto P_0c0bc7f6;
P_0c0bc7f6: /* original 4e0b, guest PC 0x0c0bc7f6 */
if(!s->budget--) { s->failed_pc=0x0c0bc7f6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc7fau;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc7fau) { target=s->pc; goto dispatch; }
goto P_0c0bc7fa;
P_0c0bc7f8: /* original 65b2, guest PC 0x0c0bc7f8 */
if(!s->budget--) { s->failed_pc=0x0c0bc7f8u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bc7fa;
P_0c0bc7fa: /* original 9482, guest PC 0x0c0bc7fa */
if(!s->budget--) { s->failed_pc=0x0c0bc7fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc902u,2);
goto P_0c0bc7fc;
P_0c0bc7fc: /* original 4e0b, guest PC 0x0c0bc7fc */
if(!s->budget--) { s->failed_pc=0x0c0bc7fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc800u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc800u) { target=s->pc; goto dispatch; }
goto P_0c0bc800;
P_0c0bc7fe: /* original 65b2, guest PC 0x0c0bc7fe */
if(!s->budget--) { s->failed_pc=0x0c0bc7feu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bc800;
P_0c0bc800: /* original 9480, guest PC 0x0c0bc800 */
if(!s->budget--) { s->failed_pc=0x0c0bc800u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc904u,2);
goto P_0c0bc802;
P_0c0bc802: /* original 4e0b, guest PC 0x0c0bc802 */
if(!s->budget--) { s->failed_pc=0x0c0bc802u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc806u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc806u) { target=s->pc; goto dispatch; }
goto P_0c0bc806;
P_0c0bc804: /* original 65b2, guest PC 0x0c0bc804 */
if(!s->budget--) { s->failed_pc=0x0c0bc804u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bc806;
P_0c0bc806: /* original 947e, guest PC 0x0c0bc806 */
if(!s->budget--) { s->failed_pc=0x0c0bc806u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc906u,2);
goto P_0c0bc808;
P_0c0bc808: /* original 4e0b, guest PC 0x0c0bc808 */
if(!s->budget--) { s->failed_pc=0x0c0bc808u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc80cu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc80cu) { target=s->pc; goto dispatch; }
goto P_0c0bc80c;
P_0c0bc80a: /* original 65b2, guest PC 0x0c0bc80a */
if(!s->budget--) { s->failed_pc=0x0c0bc80au; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bc80c;
P_0c0bc80c: /* original 947c, guest PC 0x0c0bc80c */
if(!s->budget--) { s->failed_pc=0x0c0bc80cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc908u,2);
goto P_0c0bc80e;
P_0c0bc80e: /* original 4e0b, guest PC 0x0c0bc80e */
if(!s->budget--) { s->failed_pc=0x0c0bc80eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc812u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc812u) { target=s->pc; goto dispatch; }
goto P_0c0bc812;
P_0c0bc810: /* original 65a2, guest PC 0x0c0bc810 */
if(!s->budget--) { s->failed_pc=0x0c0bc810u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bc812;
P_0c0bc812: /* original 947a, guest PC 0x0c0bc812 */
if(!s->budget--) { s->failed_pc=0x0c0bc812u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc90au,2);
goto P_0c0bc814;
P_0c0bc814: /* original 4e0b, guest PC 0x0c0bc814 */
if(!s->budget--) { s->failed_pc=0x0c0bc814u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc818u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc818u) { target=s->pc; goto dispatch; }
goto P_0c0bc818;
P_0c0bc816: /* original 65a2, guest PC 0x0c0bc816 */
if(!s->budget--) { s->failed_pc=0x0c0bc816u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bc818;
P_0c0bc818: /* original 9478, guest PC 0x0c0bc818 */
if(!s->budget--) { s->failed_pc=0x0c0bc818u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc90cu,2);
goto P_0c0bc81a;
P_0c0bc81a: /* original 4e0b, guest PC 0x0c0bc81a */
if(!s->budget--) { s->failed_pc=0x0c0bc81au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc81eu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc81eu) { target=s->pc; goto dispatch; }
goto P_0c0bc81e;
P_0c0bc81c: /* original 65a2, guest PC 0x0c0bc81c */
if(!s->budget--) { s->failed_pc=0x0c0bc81cu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bc81e;
P_0c0bc81e: /* original 9476, guest PC 0x0c0bc81e */
if(!s->budget--) { s->failed_pc=0x0c0bc81eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc90eu,2);
goto P_0c0bc820;
P_0c0bc820: /* original 4e0b, guest PC 0x0c0bc820 */
if(!s->budget--) { s->failed_pc=0x0c0bc820u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc824u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc824u) { target=s->pc; goto dispatch; }
goto P_0c0bc824;
P_0c0bc822: /* original 65a2, guest PC 0x0c0bc822 */
if(!s->budget--) { s->failed_pc=0x0c0bc822u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bc824;
P_0c0bc824: /* original 9574, guest PC 0x0c0bc824 */
if(!s->budget--) { s->failed_pc=0x0c0bc824u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc910u,2);
goto P_0c0bc826;
P_0c0bc826: /* original 35dc, guest PC 0x0c0bc826 */
if(!s->budget--) { s->failed_pc=0x0c0bc826u; return 0; }
r[5]+=r[13];
goto P_0c0bc828;
P_0c0bc828: /* original 2f52, guest PC 0x0c0bc828 */
if(!s->budget--) { s->failed_pc=0x0c0bc828u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bc82a;
P_0c0bc82a: /* original 9472, guest PC 0x0c0bc82a */
if(!s->budget--) { s->failed_pc=0x0c0bc82au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc912u,2);
goto P_0c0bc82c;
P_0c0bc82c: /* original 4e0b, guest PC 0x0c0bc82c */
if(!s->budget--) { s->failed_pc=0x0c0bc82cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc830u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc830u) { target=s->pc; goto dispatch; }
goto P_0c0bc830;
P_0c0bc82e: /* original 6552, guest PC 0x0c0bc82e */
if(!s->budget--) { s->failed_pc=0x0c0bc82eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc830;
P_0c0bc830: /* original 9470, guest PC 0x0c0bc830 */
if(!s->budget--) { s->failed_pc=0x0c0bc830u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc914u,2);
goto P_0c0bc832;
P_0c0bc832: /* original 65f2, guest PC 0x0c0bc832 */
if(!s->budget--) { s->failed_pc=0x0c0bc832u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bc834;
P_0c0bc834: /* original 4e0b, guest PC 0x0c0bc834 */
if(!s->budget--) { s->failed_pc=0x0c0bc834u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc838u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc838u) { target=s->pc; goto dispatch; }
goto P_0c0bc838;
P_0c0bc836: /* original 6552, guest PC 0x0c0bc836 */
if(!s->budget--) { s->failed_pc=0x0c0bc836u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc838;
P_0c0bc838: /* original 956d, guest PC 0x0c0bc838 */
if(!s->budget--) { s->failed_pc=0x0c0bc838u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc916u,2);
goto P_0c0bc83a;
P_0c0bc83a: /* original 35dc, guest PC 0x0c0bc83a */
if(!s->budget--) { s->failed_pc=0x0c0bc83au; return 0; }
r[5]+=r[13];
goto P_0c0bc83c;
P_0c0bc83c: /* original 2f52, guest PC 0x0c0bc83c */
if(!s->budget--) { s->failed_pc=0x0c0bc83cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bc83e;
P_0c0bc83e: /* original 946b, guest PC 0x0c0bc83e */
if(!s->budget--) { s->failed_pc=0x0c0bc83eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc918u,2);
goto P_0c0bc840;
P_0c0bc840: /* original 4e0b, guest PC 0x0c0bc840 */
if(!s->budget--) { s->failed_pc=0x0c0bc840u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc844u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc844u) { target=s->pc; goto dispatch; }
goto P_0c0bc844;
P_0c0bc842: /* original 6552, guest PC 0x0c0bc842 */
if(!s->budget--) { s->failed_pc=0x0c0bc842u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc844;
P_0c0bc844: /* original 9469, guest PC 0x0c0bc844 */
if(!s->budget--) { s->failed_pc=0x0c0bc844u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc91au,2);
goto P_0c0bc846;
P_0c0bc846: /* original 65f2, guest PC 0x0c0bc846 */
if(!s->budget--) { s->failed_pc=0x0c0bc846u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bc848;
P_0c0bc848: /* original 4e0b, guest PC 0x0c0bc848 */
if(!s->budget--) { s->failed_pc=0x0c0bc848u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc84cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc84cu) { target=s->pc; goto dispatch; }
goto P_0c0bc84c;
P_0c0bc84a: /* original 6552, guest PC 0x0c0bc84a */
if(!s->budget--) { s->failed_pc=0x0c0bc84au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc84c;
P_0c0bc84c: /* original 9467, guest PC 0x0c0bc84c */
if(!s->budget--) { s->failed_pc=0x0c0bc84cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc91eu,2);
goto P_0c0bc84e;
P_0c0bc84e: /* original 9065, guest PC 0x0c0bc84e */
if(!s->budget--) { s->failed_pc=0x0c0bc84eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc91cu,2);
goto P_0c0bc850;
P_0c0bc850: /* original 4e0b, guest PC 0x0c0bc850 */
if(!s->budget--) { s->failed_pc=0x0c0bc850u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc854u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc854u) { target=s->pc; goto dispatch; }
goto P_0c0bc854;
P_0c0bc852: /* original 05de, guest PC 0x0c0bc852 */
if(!s->budget--) { s->failed_pc=0x0c0bc852u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc854;
P_0c0bc854: /* original 9564, guest PC 0x0c0bc854 */
if(!s->budget--) { s->failed_pc=0x0c0bc854u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc920u,2);
goto P_0c0bc856;
P_0c0bc856: /* original 35dc, guest PC 0x0c0bc856 */
if(!s->budget--) { s->failed_pc=0x0c0bc856u; return 0; }
r[5]+=r[13];
goto P_0c0bc858;
P_0c0bc858: /* original 2f52, guest PC 0x0c0bc858 */
if(!s->budget--) { s->failed_pc=0x0c0bc858u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bc85a;
P_0c0bc85a: /* original 9462, guest PC 0x0c0bc85a */
if(!s->budget--) { s->failed_pc=0x0c0bc85au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc922u,2);
goto P_0c0bc85c;
P_0c0bc85c: /* original 4e0b, guest PC 0x0c0bc85c */
if(!s->budget--) { s->failed_pc=0x0c0bc85cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc860u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc860u) { target=s->pc; goto dispatch; }
goto P_0c0bc860;
P_0c0bc85e: /* original 6552, guest PC 0x0c0bc85e */
if(!s->budget--) { s->failed_pc=0x0c0bc85eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc860;
P_0c0bc860: /* original 9460, guest PC 0x0c0bc860 */
if(!s->budget--) { s->failed_pc=0x0c0bc860u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc924u,2);
goto P_0c0bc862;
P_0c0bc862: /* original 65f2, guest PC 0x0c0bc862 */
if(!s->budget--) { s->failed_pc=0x0c0bc862u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bc864;
P_0c0bc864: /* original 4e0b, guest PC 0x0c0bc864 */
if(!s->budget--) { s->failed_pc=0x0c0bc864u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc868u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc868u) { target=s->pc; goto dispatch; }
goto P_0c0bc868;
P_0c0bc866: /* original 6552, guest PC 0x0c0bc866 */
if(!s->budget--) { s->failed_pc=0x0c0bc866u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc868;
P_0c0bc868: /* original 945e, guest PC 0x0c0bc868 */
if(!s->budget--) { s->failed_pc=0x0c0bc868u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc928u,2);
goto P_0c0bc86a;
P_0c0bc86a: /* original 905c, guest PC 0x0c0bc86a */
if(!s->budget--) { s->failed_pc=0x0c0bc86au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc926u,2);
goto P_0c0bc86c;
P_0c0bc86c: /* original 4e0b, guest PC 0x0c0bc86c */
if(!s->budget--) { s->failed_pc=0x0c0bc86cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc870u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc870u) { target=s->pc; goto dispatch; }
goto P_0c0bc870;
P_0c0bc86e: /* original 05de, guest PC 0x0c0bc86e */
if(!s->budget--) { s->failed_pc=0x0c0bc86eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc870;
P_0c0bc870: /* original 955b, guest PC 0x0c0bc870 */
if(!s->budget--) { s->failed_pc=0x0c0bc870u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc92au,2);
goto P_0c0bc872;
P_0c0bc872: /* original 35dc, guest PC 0x0c0bc872 */
if(!s->budget--) { s->failed_pc=0x0c0bc872u; return 0; }
r[5]+=r[13];
goto P_0c0bc874;
P_0c0bc874: /* original 2f52, guest PC 0x0c0bc874 */
if(!s->budget--) { s->failed_pc=0x0c0bc874u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bc876;
P_0c0bc876: /* original 9459, guest PC 0x0c0bc876 */
if(!s->budget--) { s->failed_pc=0x0c0bc876u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc92cu,2);
goto P_0c0bc878;
P_0c0bc878: /* original 4e0b, guest PC 0x0c0bc878 */
if(!s->budget--) { s->failed_pc=0x0c0bc878u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc87cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc87cu) { target=s->pc; goto dispatch; }
goto P_0c0bc87c;
P_0c0bc87a: /* original 6552, guest PC 0x0c0bc87a */
if(!s->budget--) { s->failed_pc=0x0c0bc87au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc87c;
P_0c0bc87c: /* original 9457, guest PC 0x0c0bc87c */
if(!s->budget--) { s->failed_pc=0x0c0bc87cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc92eu,2);
goto P_0c0bc87e;
P_0c0bc87e: /* original 65f2, guest PC 0x0c0bc87e */
if(!s->budget--) { s->failed_pc=0x0c0bc87eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bc880;
P_0c0bc880: /* original 4e0b, guest PC 0x0c0bc880 */
if(!s->budget--) { s->failed_pc=0x0c0bc880u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc884u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc884u) { target=s->pc; goto dispatch; }
goto P_0c0bc884;
P_0c0bc882: /* original 6552, guest PC 0x0c0bc882 */
if(!s->budget--) { s->failed_pc=0x0c0bc882u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc884;
P_0c0bc884: /* original 9455, guest PC 0x0c0bc884 */
if(!s->budget--) { s->failed_pc=0x0c0bc884u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc932u,2);
goto P_0c0bc886;
P_0c0bc886: /* original 9053, guest PC 0x0c0bc886 */
if(!s->budget--) { s->failed_pc=0x0c0bc886u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc930u,2);
goto P_0c0bc888;
P_0c0bc888: /* original 4e0b, guest PC 0x0c0bc888 */
if(!s->budget--) { s->failed_pc=0x0c0bc888u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc88cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc88cu) { target=s->pc; goto dispatch; }
goto P_0c0bc88c;
P_0c0bc88a: /* original 05de, guest PC 0x0c0bc88a */
if(!s->budget--) { s->failed_pc=0x0c0bc88au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc88c;
P_0c0bc88c: /* original 9552, guest PC 0x0c0bc88c */
if(!s->budget--) { s->failed_pc=0x0c0bc88cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc934u,2);
goto P_0c0bc88e;
P_0c0bc88e: /* original 35dc, guest PC 0x0c0bc88e */
if(!s->budget--) { s->failed_pc=0x0c0bc88eu; return 0; }
r[5]+=r[13];
goto P_0c0bc890;
P_0c0bc890: /* original 2f52, guest PC 0x0c0bc890 */
if(!s->budget--) { s->failed_pc=0x0c0bc890u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bc892;
P_0c0bc892: /* original 9450, guest PC 0x0c0bc892 */
if(!s->budget--) { s->failed_pc=0x0c0bc892u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc936u,2);
goto P_0c0bc894;
P_0c0bc894: /* original 4e0b, guest PC 0x0c0bc894 */
if(!s->budget--) { s->failed_pc=0x0c0bc894u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc898u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc898u) { target=s->pc; goto dispatch; }
goto P_0c0bc898;
P_0c0bc896: /* original 6552, guest PC 0x0c0bc896 */
if(!s->budget--) { s->failed_pc=0x0c0bc896u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc898;
P_0c0bc898: /* original 944e, guest PC 0x0c0bc898 */
if(!s->budget--) { s->failed_pc=0x0c0bc898u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc938u,2);
goto P_0c0bc89a;
P_0c0bc89a: /* original 65f2, guest PC 0x0c0bc89a */
if(!s->budget--) { s->failed_pc=0x0c0bc89au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bc89c;
P_0c0bc89c: /* original 4e0b, guest PC 0x0c0bc89c */
if(!s->budget--) { s->failed_pc=0x0c0bc89cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc8a0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc8a0u) { target=s->pc; goto dispatch; }
goto P_0c0bc8a0;
P_0c0bc89e: /* original 6552, guest PC 0x0c0bc89e */
if(!s->budget--) { s->failed_pc=0x0c0bc89eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc8a0;
P_0c0bc8a0: /* original 954b, guest PC 0x0c0bc8a0 */
if(!s->budget--) { s->failed_pc=0x0c0bc8a0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc93au,2);
goto P_0c0bc8a2;
P_0c0bc8a2: /* original 35dc, guest PC 0x0c0bc8a2 */
if(!s->budget--) { s->failed_pc=0x0c0bc8a2u; return 0; }
r[5]+=r[13];
goto P_0c0bc8a4;
P_0c0bc8a4: /* original 2f52, guest PC 0x0c0bc8a4 */
if(!s->budget--) { s->failed_pc=0x0c0bc8a4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bc8a6;
P_0c0bc8a6: /* original 9449, guest PC 0x0c0bc8a6 */
if(!s->budget--) { s->failed_pc=0x0c0bc8a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc93cu,2);
goto P_0c0bc8a8;
P_0c0bc8a8: /* original 4e0b, guest PC 0x0c0bc8a8 */
if(!s->budget--) { s->failed_pc=0x0c0bc8a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc8acu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc8acu) { target=s->pc; goto dispatch; }
goto P_0c0bc8ac;
P_0c0bc8aa: /* original 6552, guest PC 0x0c0bc8aa */
if(!s->budget--) { s->failed_pc=0x0c0bc8aau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc8ac;
P_0c0bc8ac: /* original 9447, guest PC 0x0c0bc8ac */
if(!s->budget--) { s->failed_pc=0x0c0bc8acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc93eu,2);
goto P_0c0bc8ae;
P_0c0bc8ae: /* original 65f2, guest PC 0x0c0bc8ae */
if(!s->budget--) { s->failed_pc=0x0c0bc8aeu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bc8b0;
P_0c0bc8b0: /* original 4e0b, guest PC 0x0c0bc8b0 */
if(!s->budget--) { s->failed_pc=0x0c0bc8b0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc8b4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc8b4u) { target=s->pc; goto dispatch; }
goto P_0c0bc8b4;
P_0c0bc8b2: /* original 6552, guest PC 0x0c0bc8b2 */
if(!s->budget--) { s->failed_pc=0x0c0bc8b2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc8b4;
P_0c0bc8b4: /* original 9445, guest PC 0x0c0bc8b4 */
if(!s->budget--) { s->failed_pc=0x0c0bc8b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc942u,2);
goto P_0c0bc8b6;
P_0c0bc8b6: /* original 9043, guest PC 0x0c0bc8b6 */
if(!s->budget--) { s->failed_pc=0x0c0bc8b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc940u,2);
goto P_0c0bc8b8;
P_0c0bc8b8: /* original 4e0b, guest PC 0x0c0bc8b8 */
if(!s->budget--) { s->failed_pc=0x0c0bc8b8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc8bcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc8bcu) { target=s->pc; goto dispatch; }
goto P_0c0bc8bc;
P_0c0bc8ba: /* original 05de, guest PC 0x0c0bc8ba */
if(!s->budget--) { s->failed_pc=0x0c0bc8bau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc8bc;
P_0c0bc8bc: /* original 9443, guest PC 0x0c0bc8bc */
if(!s->budget--) { s->failed_pc=0x0c0bc8bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc946u,2);
goto P_0c0bc8be;
P_0c0bc8be: /* original 9041, guest PC 0x0c0bc8be */
if(!s->budget--) { s->failed_pc=0x0c0bc8beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc944u,2);
goto P_0c0bc8c0;
P_0c0bc8c0: /* original 4e0b, guest PC 0x0c0bc8c0 */
if(!s->budget--) { s->failed_pc=0x0c0bc8c0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc8c4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc8c4u) { target=s->pc; goto dispatch; }
goto P_0c0bc8c4;
P_0c0bc8c2: /* original 05de, guest PC 0x0c0bc8c2 */
if(!s->budget--) { s->failed_pc=0x0c0bc8c2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc8c4;
P_0c0bc8c4: /* original 9441, guest PC 0x0c0bc8c4 */
if(!s->budget--) { s->failed_pc=0x0c0bc8c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc94au,2);
goto P_0c0bc8c6;
P_0c0bc8c6: /* original 903f, guest PC 0x0c0bc8c6 */
if(!s->budget--) { s->failed_pc=0x0c0bc8c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc948u,2);
goto P_0c0bc8c8;
P_0c0bc8c8: /* original 4e0b, guest PC 0x0c0bc8c8 */
if(!s->budget--) { s->failed_pc=0x0c0bc8c8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc8ccu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc8ccu) { target=s->pc; goto dispatch; }
goto P_0c0bc8cc;
P_0c0bc8ca: /* original 05de, guest PC 0x0c0bc8ca */
if(!s->budget--) { s->failed_pc=0x0c0bc8cau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc8cc;
P_0c0bc8cc: /* original 943f, guest PC 0x0c0bc8cc */
if(!s->budget--) { s->failed_pc=0x0c0bc8ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc94eu,2);
goto P_0c0bc8ce;
P_0c0bc8ce: /* original 903d, guest PC 0x0c0bc8ce */
if(!s->budget--) { s->failed_pc=0x0c0bc8ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc94cu,2);
goto P_0c0bc8d0;
P_0c0bc8d0: /* original 4e0b, guest PC 0x0c0bc8d0 */
if(!s->budget--) { s->failed_pc=0x0c0bc8d0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc8d4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc8d4u) { target=s->pc; goto dispatch; }
goto P_0c0bc8d4;
P_0c0bc8d2: /* original 05de, guest PC 0x0c0bc8d2 */
if(!s->budget--) { s->failed_pc=0x0c0bc8d2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc8d4;
P_0c0bc8d4: /* original 903c, guest PC 0x0c0bc8d4 */
if(!s->budget--) { s->failed_pc=0x0c0bc8d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc950u,2);
goto P_0c0bc8d6;
P_0c0bc8d6: /* original a03c, guest PC 0x0c0bc8d6 */
if(!s->budget--) { s->failed_pc=0x0c0bc8d6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc952;
P_0c0bc8d8: /* original 05de, guest PC 0x0c0bc8d8 */
if(!s->budget--) { s->failed_pc=0x0c0bc8d8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0bc8dau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bc8dau; return 0; } return 1;
P_0c0bc952: /* original 943e, guest PC 0x0c0bc952 */
if(!s->budget--) { s->failed_pc=0x0c0bc952u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9d2u,2);
goto P_0c0bc954;
P_0c0bc954: /* original 4e0b, guest PC 0x0c0bc954 */
if(!s->budget--) { s->failed_pc=0x0c0bc954u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc958u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc958u) { target=s->pc; goto dispatch; }
goto P_0c0bc958;
P_0c0bc956: /* original 0009, guest PC 0x0c0bc956 */
if(!s->budget--) { s->failed_pc=0x0c0bc956u; return 0; }
goto P_0c0bc958;
P_0c0bc958: /* original 943d, guest PC 0x0c0bc958 */
if(!s->budget--) { s->failed_pc=0x0c0bc958u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9d6u,2);
goto P_0c0bc95a;
P_0c0bc95a: /* original 903b, guest PC 0x0c0bc95a */
if(!s->budget--) { s->failed_pc=0x0c0bc95au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9d4u,2);
goto P_0c0bc95c;
P_0c0bc95c: /* original 4e0b, guest PC 0x0c0bc95c */
if(!s->budget--) { s->failed_pc=0x0c0bc95cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc960u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc960u) { target=s->pc; goto dispatch; }
goto P_0c0bc960;
P_0c0bc95e: /* original 05de, guest PC 0x0c0bc95e */
if(!s->budget--) { s->failed_pc=0x0c0bc95eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc960;
P_0c0bc960: /* original 943b, guest PC 0x0c0bc960 */
if(!s->budget--) { s->failed_pc=0x0c0bc960u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9dau,2);
goto P_0c0bc962;
P_0c0bc962: /* original 9039, guest PC 0x0c0bc962 */
if(!s->budget--) { s->failed_pc=0x0c0bc962u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9d8u,2);
goto P_0c0bc964;
P_0c0bc964: /* original 4e0b, guest PC 0x0c0bc964 */
if(!s->budget--) { s->failed_pc=0x0c0bc964u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc968u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc968u) { target=s->pc; goto dispatch; }
goto P_0c0bc968;
P_0c0bc966: /* original 05de, guest PC 0x0c0bc966 */
if(!s->budget--) { s->failed_pc=0x0c0bc966u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc968;
P_0c0bc968: /* original 9439, guest PC 0x0c0bc968 */
if(!s->budget--) { s->failed_pc=0x0c0bc968u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9deu,2);
goto P_0c0bc96a;
P_0c0bc96a: /* original 9037, guest PC 0x0c0bc96a */
if(!s->budget--) { s->failed_pc=0x0c0bc96au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9dcu,2);
goto P_0c0bc96c;
P_0c0bc96c: /* original 4e0b, guest PC 0x0c0bc96c */
if(!s->budget--) { s->failed_pc=0x0c0bc96cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc970u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc970u) { target=s->pc; goto dispatch; }
goto P_0c0bc970;
P_0c0bc96e: /* original 05de, guest PC 0x0c0bc96e */
if(!s->budget--) { s->failed_pc=0x0c0bc96eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc970;
P_0c0bc970: /* original 9437, guest PC 0x0c0bc970 */
if(!s->budget--) { s->failed_pc=0x0c0bc970u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9e2u,2);
goto P_0c0bc972;
P_0c0bc972: /* original 9035, guest PC 0x0c0bc972 */
if(!s->budget--) { s->failed_pc=0x0c0bc972u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9e0u,2);
goto P_0c0bc974;
P_0c0bc974: /* original 4e0b, guest PC 0x0c0bc974 */
if(!s->budget--) { s->failed_pc=0x0c0bc974u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc978u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc978u) { target=s->pc; goto dispatch; }
goto P_0c0bc978;
P_0c0bc976: /* original 05de, guest PC 0x0c0bc976 */
if(!s->budget--) { s->failed_pc=0x0c0bc976u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc978;
P_0c0bc978: /* original 9435, guest PC 0x0c0bc978 */
if(!s->budget--) { s->failed_pc=0x0c0bc978u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9e6u,2);
goto P_0c0bc97a;
P_0c0bc97a: /* original 9033, guest PC 0x0c0bc97a */
if(!s->budget--) { s->failed_pc=0x0c0bc97au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9e4u,2);
goto P_0c0bc97c;
P_0c0bc97c: /* original 4e0b, guest PC 0x0c0bc97c */
if(!s->budget--) { s->failed_pc=0x0c0bc97cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc980u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc980u) { target=s->pc; goto dispatch; }
goto P_0c0bc980;
P_0c0bc97e: /* original 05de, guest PC 0x0c0bc97e */
if(!s->budget--) { s->failed_pc=0x0c0bc97eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc980;
P_0c0bc980: /* original 9433, guest PC 0x0c0bc980 */
if(!s->budget--) { s->failed_pc=0x0c0bc980u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9eau,2);
goto P_0c0bc982;
P_0c0bc982: /* original 9031, guest PC 0x0c0bc982 */
if(!s->budget--) { s->failed_pc=0x0c0bc982u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9e8u,2);
goto P_0c0bc984;
P_0c0bc984: /* original 4e0b, guest PC 0x0c0bc984 */
if(!s->budget--) { s->failed_pc=0x0c0bc984u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc988u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc988u) { target=s->pc; goto dispatch; }
goto P_0c0bc988;
P_0c0bc986: /* original 05de, guest PC 0x0c0bc986 */
if(!s->budget--) { s->failed_pc=0x0c0bc986u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc988;
P_0c0bc988: /* original 9431, guest PC 0x0c0bc988 */
if(!s->budget--) { s->failed_pc=0x0c0bc988u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9eeu,2);
goto P_0c0bc98a;
P_0c0bc98a: /* original 902f, guest PC 0x0c0bc98a */
if(!s->budget--) { s->failed_pc=0x0c0bc98au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9ecu,2);
goto P_0c0bc98c;
P_0c0bc98c: /* original 4e0b, guest PC 0x0c0bc98c */
if(!s->budget--) { s->failed_pc=0x0c0bc98cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc990u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc990u) { target=s->pc; goto dispatch; }
goto P_0c0bc990;
P_0c0bc98e: /* original 05de, guest PC 0x0c0bc98e */
if(!s->budget--) { s->failed_pc=0x0c0bc98eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc990;
P_0c0bc990: /* original 942f, guest PC 0x0c0bc990 */
if(!s->budget--) { s->failed_pc=0x0c0bc990u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9f2u,2);
goto P_0c0bc992;
P_0c0bc992: /* original 902d, guest PC 0x0c0bc992 */
if(!s->budget--) { s->failed_pc=0x0c0bc992u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9f0u,2);
goto P_0c0bc994;
P_0c0bc994: /* original 4e0b, guest PC 0x0c0bc994 */
if(!s->budget--) { s->failed_pc=0x0c0bc994u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc998u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc998u) { target=s->pc; goto dispatch; }
goto P_0c0bc998;
P_0c0bc996: /* original 05de, guest PC 0x0c0bc996 */
if(!s->budget--) { s->failed_pc=0x0c0bc996u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc998;
P_0c0bc998: /* original 942d, guest PC 0x0c0bc998 */
if(!s->budget--) { s->failed_pc=0x0c0bc998u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9f6u,2);
goto P_0c0bc99a;
P_0c0bc99a: /* original 902b, guest PC 0x0c0bc99a */
if(!s->budget--) { s->failed_pc=0x0c0bc99au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9f4u,2);
goto P_0c0bc99c;
P_0c0bc99c: /* original 4e0b, guest PC 0x0c0bc99c */
if(!s->budget--) { s->failed_pc=0x0c0bc99cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc9a0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc9a0u) { target=s->pc; goto dispatch; }
goto P_0c0bc9a0;
P_0c0bc99e: /* original 05de, guest PC 0x0c0bc99e */
if(!s->budget--) { s->failed_pc=0x0c0bc99eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc9a0;
P_0c0bc9a0: /* original 942b, guest PC 0x0c0bc9a0 */
if(!s->budget--) { s->failed_pc=0x0c0bc9a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9fau,2);
goto P_0c0bc9a2;
P_0c0bc9a2: /* original 9029, guest PC 0x0c0bc9a2 */
if(!s->budget--) { s->failed_pc=0x0c0bc9a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9f8u,2);
goto P_0c0bc9a4;
P_0c0bc9a4: /* original 4e0b, guest PC 0x0c0bc9a4 */
if(!s->budget--) { s->failed_pc=0x0c0bc9a4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc9a8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc9a8u) { target=s->pc; goto dispatch; }
goto P_0c0bc9a8;
P_0c0bc9a6: /* original 05de, guest PC 0x0c0bc9a6 */
if(!s->budget--) { s->failed_pc=0x0c0bc9a6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc9a8;
P_0c0bc9a8: /* original 9429, guest PC 0x0c0bc9a8 */
if(!s->budget--) { s->failed_pc=0x0c0bc9a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9feu,2);
goto P_0c0bc9aa;
P_0c0bc9aa: /* original 9027, guest PC 0x0c0bc9aa */
if(!s->budget--) { s->failed_pc=0x0c0bc9aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc9fcu,2);
goto P_0c0bc9ac;
P_0c0bc9ac: /* original 4e0b, guest PC 0x0c0bc9ac */
if(!s->budget--) { s->failed_pc=0x0c0bc9acu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc9b0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc9b0u) { target=s->pc; goto dispatch; }
goto P_0c0bc9b0;
P_0c0bc9ae: /* original 05de, guest PC 0x0c0bc9ae */
if(!s->budget--) { s->failed_pc=0x0c0bc9aeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc9b0;
P_0c0bc9b0: /* original 9427, guest PC 0x0c0bc9b0 */
if(!s->budget--) { s->failed_pc=0x0c0bc9b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bca02u,2);
goto P_0c0bc9b2;
P_0c0bc9b2: /* original 9025, guest PC 0x0c0bc9b2 */
if(!s->budget--) { s->failed_pc=0x0c0bc9b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bca00u,2);
goto P_0c0bc9b4;
P_0c0bc9b4: /* original 4e0b, guest PC 0x0c0bc9b4 */
if(!s->budget--) { s->failed_pc=0x0c0bc9b4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc9b8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc9b8u) { target=s->pc; goto dispatch; }
goto P_0c0bc9b8;
P_0c0bc9b6: /* original 05de, guest PC 0x0c0bc9b6 */
if(!s->budget--) { s->failed_pc=0x0c0bc9b6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc9b8;
P_0c0bc9b8: /* original 9425, guest PC 0x0c0bc9b8 */
if(!s->budget--) { s->failed_pc=0x0c0bc9b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bca06u,2);
goto P_0c0bc9ba;
P_0c0bc9ba: /* original 9023, guest PC 0x0c0bc9ba */
if(!s->budget--) { s->failed_pc=0x0c0bc9bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bca04u,2);
goto P_0c0bc9bc;
P_0c0bc9bc: /* original 4e0b, guest PC 0x0c0bc9bc */
if(!s->budget--) { s->failed_pc=0x0c0bc9bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc9c0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc9c0u) { target=s->pc; goto dispatch; }
goto P_0c0bc9c0;
P_0c0bc9be: /* original 05de, guest PC 0x0c0bc9be */
if(!s->budget--) { s->failed_pc=0x0c0bc9beu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc9c0;
P_0c0bc9c0: /* original 7f08, guest PC 0x0c0bc9c0 */
if(!s->budget--) { s->failed_pc=0x0c0bc9c0u; return 0; }
r[15]+=0x00000008u;
goto P_0c0bc9c2;
P_0c0bc9c2: /* original 4f26, guest PC 0x0c0bc9c2 */
if(!s->budget--) { s->failed_pc=0x0c0bc9c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0bc9c4;
P_0c0bc9c4: /* original 69f6, guest PC 0x0c0bc9c4 */
if(!s->budget--) { s->failed_pc=0x0c0bc9c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0bc9c6;
P_0c0bc9c6: /* original 6af6, guest PC 0x0c0bc9c6 */
if(!s->budget--) { s->failed_pc=0x0c0bc9c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0bc9c8;
P_0c0bc9c8: /* original 6bf6, guest PC 0x0c0bc9c8 */
if(!s->budget--) { s->failed_pc=0x0c0bc9c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0bc9ca;
P_0c0bc9ca: /* original 6cf6, guest PC 0x0c0bc9ca */
if(!s->budget--) { s->failed_pc=0x0c0bc9cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0bc9cc;
P_0c0bc9cc: /* original 6df6, guest PC 0x0c0bc9cc */
if(!s->budget--) { s->failed_pc=0x0c0bc9ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0bc9ce;
P_0c0bc9ce: /* original 000b, guest PC 0x0c0bc9ce */
if(!s->budget--) { s->failed_pc=0x0c0bc9ceu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0bc9d0: /* original 6ef6, guest PC 0x0c0bc9d0 */
if(!s->budget--) { s->failed_pc=0x0c0bc9d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0bc9d2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bc9d2u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
