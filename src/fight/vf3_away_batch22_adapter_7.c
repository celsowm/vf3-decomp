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
int vf3_away_batch22_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
return vf3_matrix_family(0x0c0ae29cu,s,ram);
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
return vf3_matrix_family(0x0c0ae29cu,s,ram);
P_0c0ae7aa: /* original 6ef6, guest PC 0x0c0ae7aa */
if(!s->budget--) { s->failed_pc=0x0c0ae7aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ae7acu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ae7acu; return 0; } return 1;
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
return vf3_matrix_family(0x0c0ae29cu,s,ram);
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
return vf3_matrix_family(0x0c0aea5cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
