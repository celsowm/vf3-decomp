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
int vf3_away_batch105_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08f4aeu: goto P_0c08f4ae;
case 0x0c08f4b0u: goto P_0c08f4b0;
case 0x0c08f4b2u: goto P_0c08f4b2;
case 0x0c08f4b4u: goto P_0c08f4b4;
case 0x0c08f4b6u: goto P_0c08f4b6;
case 0x0c08f4b8u: goto P_0c08f4b8;
case 0x0c08f4bau: goto P_0c08f4ba;
case 0x0c08f4bcu: goto P_0c08f4bc;
case 0x0c08f4beu: goto P_0c08f4be;
case 0x0c08f4c0u: goto P_0c08f4c0;
case 0x0c08f582u: goto P_0c08f582;
case 0x0c08f584u: goto P_0c08f584;
case 0x0c08f586u: goto P_0c08f586;
case 0x0c08f588u: goto P_0c08f588;
case 0x0c08f58au: goto P_0c08f58a;
case 0x0c08f58cu: goto P_0c08f58c;
case 0x0c08f58eu: goto P_0c08f58e;
case 0x0c08f590u: goto P_0c08f590;
case 0x0c08f592u: goto P_0c08f592;
case 0x0c08f594u: goto P_0c08f594;
case 0x0c08f596u: goto P_0c08f596;
case 0x0c08f598u: goto P_0c08f598;
case 0x0c08f59au: goto P_0c08f59a;
case 0x0c08f59cu: goto P_0c08f59c;
case 0x0c08f59eu: goto P_0c08f59e;
case 0x0c08f5a0u: goto P_0c08f5a0;
case 0x0c08f5a2u: goto P_0c08f5a2;
case 0x0c08f5a4u: goto P_0c08f5a4;
case 0x0c08f5a6u: goto P_0c08f5a6;
case 0x0c08f5a8u: goto P_0c08f5a8;
case 0x0c08f5aau: goto P_0c08f5aa;
case 0x0c08f5acu: goto P_0c08f5ac;
case 0x0c08f5aeu: goto P_0c08f5ae;
case 0x0c08f5b0u: goto P_0c08f5b0;
case 0x0c08f5b2u: goto P_0c08f5b2;
case 0x0c08f5b4u: goto P_0c08f5b4;
case 0x0c08f5b6u: goto P_0c08f5b6;
case 0x0c08f5b8u: goto P_0c08f5b8;
case 0x0c08f5bau: goto P_0c08f5ba;
case 0x0c08f5bcu: goto P_0c08f5bc;
case 0x0c08f632u: goto P_0c08f632;
case 0x0c08f634u: goto P_0c08f634;
case 0x0c08f636u: goto P_0c08f636;
case 0x0c08f638u: goto P_0c08f638;
case 0x0c08f63au: goto P_0c08f63a;
case 0x0c08f63cu: goto P_0c08f63c;
case 0x0c08f63eu: goto P_0c08f63e;
case 0x0c08f640u: goto P_0c08f640;
case 0x0c08f642u: goto P_0c08f642;
case 0x0c08f644u: goto P_0c08f644;
case 0x0c08f646u: goto P_0c08f646;
case 0x0c08f648u: goto P_0c08f648;
case 0x0c08f64au: goto P_0c08f64a;
case 0x0c08f64cu: goto P_0c08f64c;
case 0x0c08f64eu: goto P_0c08f64e;
case 0x0c08f650u: goto P_0c08f650;
case 0x0c08f652u: goto P_0c08f652;
case 0x0c08f654u: goto P_0c08f654;
case 0x0c08f656u: goto P_0c08f656;
case 0x0c08f658u: goto P_0c08f658;
case 0x0c08f65au: goto P_0c08f65a;
case 0x0c08f65cu: goto P_0c08f65c;
case 0x0c08f65eu: goto P_0c08f65e;
case 0x0c08f660u: goto P_0c08f660;
case 0x0c08f662u: goto P_0c08f662;
case 0x0c08f664u: goto P_0c08f664;
case 0x0c08f666u: goto P_0c08f666;
case 0x0c08f668u: goto P_0c08f668;
case 0x0c08f66au: goto P_0c08f66a;
case 0x0c08f66cu: goto P_0c08f66c;
case 0x0c08f66eu: goto P_0c08f66e;
case 0x0c08f670u: goto P_0c08f670;
case 0x0c08f672u: goto P_0c08f672;
case 0x0c08f674u: goto P_0c08f674;
case 0x0c08f676u: goto P_0c08f676;
case 0x0c08f678u: goto P_0c08f678;
case 0x0c08f67au: goto P_0c08f67a;
case 0x0c08f67cu: goto P_0c08f67c;
case 0x0c08f67eu: goto P_0c08f67e;
case 0x0c08f680u: goto P_0c08f680;
case 0x0c08f682u: goto P_0c08f682;
case 0x0c08f684u: goto P_0c08f684;
case 0x0c08f686u: goto P_0c08f686;
case 0x0c08f688u: goto P_0c08f688;
case 0x0c08f68au: goto P_0c08f68a;
case 0x0c08f68cu: goto P_0c08f68c;
case 0x0c08f68eu: goto P_0c08f68e;
case 0x0c08f690u: goto P_0c08f690;
case 0x0c08f692u: goto P_0c08f692;
case 0x0c08f6a8u: goto P_0c08f6a8;
case 0x0c08f6aau: goto P_0c08f6aa;
case 0x0c08f6acu: goto P_0c08f6ac;
case 0x0c08f6aeu: goto P_0c08f6ae;
case 0x0c08f6b0u: goto P_0c08f6b0;
case 0x0c08f6b2u: goto P_0c08f6b2;
case 0x0c08f6b4u: goto P_0c08f6b4;
case 0x0c08f6b6u: goto P_0c08f6b6;
case 0x0c08f6b8u: goto P_0c08f6b8;
case 0x0c08f6bau: goto P_0c08f6ba;
case 0x0c08f6bcu: goto P_0c08f6bc;
case 0x0c08f6beu: goto P_0c08f6be;
case 0x0c08f6c0u: goto P_0c08f6c0;
case 0x0c08f6c2u: goto P_0c08f6c2;
case 0x0c08f6c4u: goto P_0c08f6c4;
case 0x0c08f6c6u: goto P_0c08f6c6;
case 0x0c08f6c8u: goto P_0c08f6c8;
case 0x0c08f6cau: goto P_0c08f6ca;
case 0x0c08f6ccu: goto P_0c08f6cc;
case 0x0c08f6ceu: goto P_0c08f6ce;
case 0x0c08f6d0u: goto P_0c08f6d0;
case 0x0c08f6d2u: goto P_0c08f6d2;
case 0x0c08f6d4u: goto P_0c08f6d4;
case 0x0c08f6d6u: goto P_0c08f6d6;
case 0x0c08f6d8u: goto P_0c08f6d8;
case 0x0c08f6dau: goto P_0c08f6da;
case 0x0c08f6dcu: goto P_0c08f6dc;
case 0x0c08f6deu: goto P_0c08f6de;
case 0x0c08f6e0u: goto P_0c08f6e0;
case 0x0c08f6e2u: goto P_0c08f6e2;
case 0x0c08f6e4u: goto P_0c08f6e4;
case 0x0c08f6e6u: goto P_0c08f6e6;
case 0x0c08f6e8u: goto P_0c08f6e8;
case 0x0c08f6eau: goto P_0c08f6ea;
case 0x0c08f6ecu: goto P_0c08f6ec;
case 0x0c08f6eeu: goto P_0c08f6ee;
case 0x0c08f6f0u: goto P_0c08f6f0;
case 0x0c08f6f2u: goto P_0c08f6f2;
case 0x0c08f6f4u: goto P_0c08f6f4;
case 0x0c08f6f6u: goto P_0c08f6f6;
case 0x0c08f6f8u: goto P_0c08f6f8;
case 0x0c08f6fau: goto P_0c08f6fa;
case 0x0c08f6fcu: goto P_0c08f6fc;
case 0x0c08f6feu: goto P_0c08f6fe;
case 0x0c08f700u: goto P_0c08f700;
case 0x0c08f702u: goto P_0c08f702;
case 0x0c08f704u: goto P_0c08f704;
case 0x0c08f706u: goto P_0c08f706;
case 0x0c08f708u: goto P_0c08f708;
case 0x0c08f70au: goto P_0c08f70a;
case 0x0c08f70cu: goto P_0c08f70c;
case 0x0c08f70eu: goto P_0c08f70e;
case 0x0c08f710u: goto P_0c08f710;
case 0x0c08f712u: goto P_0c08f712;
case 0x0c08f714u: goto P_0c08f714;
case 0x0c08f716u: goto P_0c08f716;
case 0x0c08f718u: goto P_0c08f718;
case 0x0c08f71au: goto P_0c08f71a;
case 0x0c08f71cu: goto P_0c08f71c;
case 0x0c08f71eu: goto P_0c08f71e;
case 0x0c08f720u: goto P_0c08f720;
case 0x0c08f722u: goto P_0c08f722;
case 0x0c08f724u: goto P_0c08f724;
case 0x0c08f726u: goto P_0c08f726;
case 0x0c08f728u: goto P_0c08f728;
case 0x0c08f72au: goto P_0c08f72a;
case 0x0c08f72cu: goto P_0c08f72c;
case 0x0c08f72eu: goto P_0c08f72e;
case 0x0c08f730u: goto P_0c08f730;
case 0x0c08f732u: goto P_0c08f732;
case 0x0c08f734u: goto P_0c08f734;
case 0x0c08f736u: goto P_0c08f736;
case 0x0c08f738u: goto P_0c08f738;
case 0x0c08f73au: goto P_0c08f73a;
case 0x0c08f73cu: goto P_0c08f73c;
case 0x0c08f73eu: goto P_0c08f73e;
case 0x0c08f740u: goto P_0c08f740;
case 0x0c08f742u: goto P_0c08f742;
case 0x0c08f744u: goto P_0c08f744;
case 0x0c08f746u: goto P_0c08f746;
case 0x0c08f748u: goto P_0c08f748;
case 0x0c08f74au: goto P_0c08f74a;
case 0x0c08f74cu: goto P_0c08f74c;
case 0x0c08f74eu: goto P_0c08f74e;
case 0x0c08f750u: goto P_0c08f750;
case 0x0c08f752u: goto P_0c08f752;
case 0x0c08f754u: goto P_0c08f754;
case 0x0c08f756u: goto P_0c08f756;
case 0x0c08f758u: goto P_0c08f758;
case 0x0c08f75au: goto P_0c08f75a;
case 0x0c08f75cu: goto P_0c08f75c;
case 0x0c08f75eu: goto P_0c08f75e;
case 0x0c08f760u: goto P_0c08f760;
case 0x0c08f762u: goto P_0c08f762;
case 0x0c08f764u: goto P_0c08f764;
case 0x0c08f766u: goto P_0c08f766;
case 0x0c08f768u: goto P_0c08f768;
case 0x0c08f76au: goto P_0c08f76a;
case 0x0c08f76cu: goto P_0c08f76c;
case 0x0c08f76eu: goto P_0c08f76e;
case 0x0c08f770u: goto P_0c08f770;
case 0x0c08f772u: goto P_0c08f772;
case 0x0c08f774u: goto P_0c08f774;
case 0x0c08f776u: goto P_0c08f776;
case 0x0c08f778u: goto P_0c08f778;
case 0x0c08f77au: goto P_0c08f77a;
case 0x0c08f77cu: goto P_0c08f77c;
case 0x0c08f77eu: goto P_0c08f77e;
case 0x0c08f780u: goto P_0c08f780;
case 0x0c08f782u: goto P_0c08f782;
case 0x0c08f784u: goto P_0c08f784;
case 0x0c08f786u: goto P_0c08f786;
case 0x0c08f788u: goto P_0c08f788;
case 0x0c08f78au: goto P_0c08f78a;
case 0x0c08f78cu: goto P_0c08f78c;
case 0x0c08f78eu: goto P_0c08f78e;
case 0x0c08f790u: goto P_0c08f790;
case 0x0c08f792u: goto P_0c08f792;
case 0x0c08f794u: goto P_0c08f794;
case 0x0c08f796u: goto P_0c08f796;
case 0x0c08f798u: goto P_0c08f798;
case 0x0c08f79au: goto P_0c08f79a;
case 0x0c08f79cu: goto P_0c08f79c;
case 0x0c08f79eu: goto P_0c08f79e;
case 0x0c08f7a0u: goto P_0c08f7a0;
case 0x0c08f7a2u: goto P_0c08f7a2;
case 0x0c08f7a4u: goto P_0c08f7a4;
case 0x0c08f7a6u: goto P_0c08f7a6;
case 0x0c08f7a8u: goto P_0c08f7a8;
case 0x0c08f7aau: goto P_0c08f7aa;
case 0x0c08f7acu: goto P_0c08f7ac;
case 0x0c08f7aeu: goto P_0c08f7ae;
case 0x0c08f7b0u: goto P_0c08f7b0;
case 0x0c08f7b2u: goto P_0c08f7b2;
case 0x0c08f7b4u: goto P_0c08f7b4;
case 0x0c08f7b6u: goto P_0c08f7b6;
case 0x0c08f7b8u: goto P_0c08f7b8;
case 0x0c08f7bau: goto P_0c08f7ba;
case 0x0c08f7bcu: goto P_0c08f7bc;
case 0x0c08f7beu: goto P_0c08f7be;
case 0x0c08f7c0u: goto P_0c08f7c0;
case 0x0c08f7c2u: goto P_0c08f7c2;
case 0x0c08f7c4u: goto P_0c08f7c4;
case 0x0c08f7c6u: goto P_0c08f7c6;
case 0x0c08f7c8u: goto P_0c08f7c8;
case 0x0c08f7cau: goto P_0c08f7ca;
case 0x0c08f7ccu: goto P_0c08f7cc;
case 0x0c08f7ceu: goto P_0c08f7ce;
case 0x0c08f7d0u: goto P_0c08f7d0;
case 0x0c08f7d2u: goto P_0c08f7d2;
case 0x0c08f7d4u: goto P_0c08f7d4;
case 0x0c08f7d6u: goto P_0c08f7d6;
case 0x0c08f7d8u: goto P_0c08f7d8;
case 0x0c08f7dau: goto P_0c08f7da;
case 0x0c08f7dcu: goto P_0c08f7dc;
case 0x0c08f7deu: goto P_0c08f7de;
case 0x0c08f7e0u: goto P_0c08f7e0;
case 0x0c08f7e2u: goto P_0c08f7e2;
case 0x0c08f7e4u: goto P_0c08f7e4;
case 0x0c08f7e6u: goto P_0c08f7e6;
case 0x0c08f7e8u: goto P_0c08f7e8;
case 0x0c08f7eau: goto P_0c08f7ea;
case 0x0c08f7ecu: goto P_0c08f7ec;
case 0x0c08f7eeu: goto P_0c08f7ee;
case 0x0c08f7f0u: goto P_0c08f7f0;
case 0x0c08f7f2u: goto P_0c08f7f2;
case 0x0c08f7f4u: goto P_0c08f7f4;
case 0x0c08f7f6u: goto P_0c08f7f6;
case 0x0c08f7f8u: goto P_0c08f7f8;
case 0x0c08f7fau: goto P_0c08f7fa;
case 0x0c08f7fcu: goto P_0c08f7fc;
case 0x0c08f7feu: goto P_0c08f7fe;
case 0x0c08f800u: goto P_0c08f800;
case 0x0c08f802u: goto P_0c08f802;
case 0x0c08f804u: goto P_0c08f804;
case 0x0c08f806u: goto P_0c08f806;
case 0x0c08f808u: goto P_0c08f808;
case 0x0c08f80au: goto P_0c08f80a;
case 0x0c08f80cu: goto P_0c08f80c;
case 0x0c08f80eu: goto P_0c08f80e;
case 0x0c08f810u: goto P_0c08f810;
case 0x0c08f824u: goto P_0c08f824;
case 0x0c08f826u: goto P_0c08f826;
case 0x0c08f828u: goto P_0c08f828;
case 0x0c08f82au: goto P_0c08f82a;
case 0x0c08f82cu: goto P_0c08f82c;
case 0x0c08f82eu: goto P_0c08f82e;
case 0x0c08f830u: goto P_0c08f830;
case 0x0c08f832u: goto P_0c08f832;
case 0x0c08f834u: goto P_0c08f834;
case 0x0c08f836u: goto P_0c08f836;
case 0x0c08f838u: goto P_0c08f838;
case 0x0c08f83au: goto P_0c08f83a;
case 0x0c08f83cu: goto P_0c08f83c;
case 0x0c08f83eu: goto P_0c08f83e;
case 0x0c08f840u: goto P_0c08f840;
case 0x0c08f842u: goto P_0c08f842;
case 0x0c08f844u: goto P_0c08f844;
case 0x0c08f846u: goto P_0c08f846;
case 0x0c08f848u: goto P_0c08f848;
case 0x0c08f84au: goto P_0c08f84a;
case 0x0c08f84cu: goto P_0c08f84c;
case 0x0c08f84eu: goto P_0c08f84e;
case 0x0c08f850u: goto P_0c08f850;
case 0x0c08f852u: goto P_0c08f852;
case 0x0c08f854u: goto P_0c08f854;
case 0x0c08f856u: goto P_0c08f856;
case 0x0c08f858u: goto P_0c08f858;
case 0x0c08f85au: goto P_0c08f85a;
case 0x0c08f85cu: goto P_0c08f85c;
case 0x0c08f85eu: goto P_0c08f85e;
case 0x0c08f860u: goto P_0c08f860;
case 0x0c08f862u: goto P_0c08f862;
case 0x0c08f864u: goto P_0c08f864;
case 0x0c08f866u: goto P_0c08f866;
case 0x0c08f868u: goto P_0c08f868;
case 0x0c08f86au: goto P_0c08f86a;
case 0x0c08f86cu: goto P_0c08f86c;
case 0x0c08f86eu: goto P_0c08f86e;
case 0x0c08f870u: goto P_0c08f870;
case 0x0c08f872u: goto P_0c08f872;
case 0x0c08f874u: goto P_0c08f874;
case 0x0c08f876u: goto P_0c08f876;
case 0x0c08f878u: goto P_0c08f878;
case 0x0c08f87au: goto P_0c08f87a;
case 0x0c08f87cu: goto P_0c08f87c;
case 0x0c08f87eu: goto P_0c08f87e;
case 0x0c08f880u: goto P_0c08f880;
case 0x0c08f882u: goto P_0c08f882;
case 0x0c08f884u: goto P_0c08f884;
case 0x0c08f886u: goto P_0c08f886;
case 0x0c08f888u: goto P_0c08f888;
case 0x0c08f88au: goto P_0c08f88a;
case 0x0c08f88cu: goto P_0c08f88c;
case 0x0c08f88eu: goto P_0c08f88e;
case 0x0c08f890u: goto P_0c08f890;
case 0x0c08f892u: goto P_0c08f892;
case 0x0c08f894u: goto P_0c08f894;
case 0x0c08f896u: goto P_0c08f896;
case 0x0c08f898u: goto P_0c08f898;
case 0x0c08f89au: goto P_0c08f89a;
case 0x0c08f89cu: goto P_0c08f89c;
case 0x0c08f89eu: goto P_0c08f89e;
case 0x0c08f8a0u: goto P_0c08f8a0;
case 0x0c08f8a2u: goto P_0c08f8a2;
case 0x0c08f8a4u: goto P_0c08f8a4;
case 0x0c08f8a6u: goto P_0c08f8a6;
case 0x0c08f8a8u: goto P_0c08f8a8;
case 0x0c08f8aau: goto P_0c08f8aa;
case 0x0c08f8acu: goto P_0c08f8ac;
case 0x0c08f8aeu: goto P_0c08f8ae;
case 0x0c08f8b0u: goto P_0c08f8b0;
case 0x0c08f8b2u: goto P_0c08f8b2;
case 0x0c08f8b4u: goto P_0c08f8b4;
case 0x0c08f8b6u: goto P_0c08f8b6;
case 0x0c08f8b8u: goto P_0c08f8b8;
case 0x0c08f8bau: goto P_0c08f8ba;
case 0x0c08f8bcu: goto P_0c08f8bc;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08f4ae: /* original 5641, guest PC 0x0c08f4ae */
if(!s->budget--) { s->failed_pc=0x0c08f4aeu; return 0; }
r[6]=read(ram,r[4]+4,4);
goto P_0c08f4b0;
P_0c08f4b0: /* original 6752, guest PC 0x0c08f4b0 */
if(!s->budget--) { s->failed_pc=0x0c08f4b0u; return 0; }
tmp=read(ram,r[5],4);
r[7]=tmp;
goto P_0c08f4b2;
P_0c08f4b2: /* original 5061, guest PC 0x0c08f4b2 */
if(!s->budget--) { s->failed_pc=0x0c08f4b2u; return 0; }
r[0]=read(ram,r[6]+4,4);
goto P_0c08f4b4;
P_0c08f4b4: /* original 2672, guest PC 0x0c08f4b4 */
if(!s->budget--) { s->failed_pc=0x0c08f4b4u; return 0; }
write(ram,r[6],r[7],4);
goto P_0c08f4b6;
P_0c08f4b6: /* original 1651, guest PC 0x0c08f4b6 */
if(!s->budget--) { s->failed_pc=0x0c08f4b6u; return 0; }
write(ram,r[6]+4,r[5],4);
goto P_0c08f4b8;
P_0c08f4b8: /* original 2042, guest PC 0x0c08f4b8 */
if(!s->budget--) { s->failed_pc=0x0c08f4b8u; return 0; }
write(ram,r[0],r[4],4);
goto P_0c08f4ba;
P_0c08f4ba: /* original 1401, guest PC 0x0c08f4ba */
if(!s->budget--) { s->failed_pc=0x0c08f4bau; return 0; }
write(ram,r[4]+4,r[0],4);
goto P_0c08f4bc;
P_0c08f4bc: /* original 2562, guest PC 0x0c08f4bc */
if(!s->budget--) { s->failed_pc=0x0c08f4bcu; return 0; }
write(ram,r[5],r[6],4);
goto P_0c08f4be;
P_0c08f4be: /* original 000b, guest PC 0x0c08f4be */
if(!s->budget--) { s->failed_pc=0x0c08f4beu; return 0; }
target=r[16];
write(ram,r[7]+4,r[6],4);
s->pc=target; return ram->oob==0;
P_0c08f4c0: /* original 1761, guest PC 0x0c08f4c0 */
if(!s->budget--) { s->failed_pc=0x0c08f4c0u; return 0; }
write(ram,r[7]+4,r[6],4);
if(!vf3_matrix_family(0x0c08f4c2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08f4c2u; return 0; } return 1;
P_0c08f582: /* original fa4c, guest PC 0x0c08f582 */
if(!s->budget--) { s->failed_pc=0x0c08f582u; return 0; }
vf3_matrix_move(s,10,4);
goto P_0c08f584;
P_0c08f584: /* original fa53, guest PC 0x0c08f584 */
if(!s->budget--) { s->failed_pc=0x0c08f584u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[5],r[18],'/');
goto P_0c08f586;
P_0c08f586: /* original fb9d, guest PC 0x0c08f586 */
if(!s->budget--) { s->failed_pc=0x0c08f586u; return 0; }
fr[11]=0x3f800000u;
goto P_0c08f588;
P_0c08f588: /* original f28c, guest PC 0x0c08f588 */
if(!s->budget--) { s->failed_pc=0x0c08f588u; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c08f58a;
P_0c08f58a: /* original f5ac, guest PC 0x0c08f58a */
if(!s->budget--) { s->failed_pc=0x0c08f58au; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c08f58c;
P_0c08f58c: /* original f6a2, guest PC 0x0c08f58c */
if(!s->budget--) { s->failed_pc=0x0c08f58cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[10],r[18],'*');
goto P_0c08f58e;
P_0c08f58e: /* original f5b1, guest PC 0x0c08f58e */
if(!s->budget--) { s->failed_pc=0x0c08f58eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[11],r[18],'-');
goto P_0c08f590;
P_0c08f590: /* original f36c, guest PC 0x0c08f590 */
if(!s->budget--) { s->failed_pc=0x0c08f590u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c08f592;
P_0c08f592: /* original f05c, guest PC 0x0c08f592 */
if(!s->budget--) { s->failed_pc=0x0c08f592u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c08f594;
P_0c08f594: /* original f37e, guest PC 0x0c08f594 */
if(!s->budget--) { s->failed_pc=0x0c08f594u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[7],fr[3],r[18]);
goto P_0c08f596;
P_0c08f596: /* original f65c, guest PC 0x0c08f596 */
if(!s->budget--) { s->failed_pc=0x0c08f596u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c08f598;
P_0c08f598: /* original f632, guest PC 0x0c08f598 */
if(!s->budget--) { s->failed_pc=0x0c08f598u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c08f59a;
P_0c08f59a: /* original f35c, guest PC 0x0c08f59a */
if(!s->budget--) { s->failed_pc=0x0c08f59au; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c08f59c;
P_0c08f59c: /* original f530, guest PC 0x0c08f59c */
if(!s->budget--) { s->failed_pc=0x0c08f59cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c08f59e;
P_0c08f59e: /* original f06c, guest PC 0x0c08f59e */
if(!s->budget--) { s->failed_pc=0x0c08f59eu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c08f5a0;
P_0c08f5a0: /* original f24e, guest PC 0x0c08f5a0 */
if(!s->budget--) { s->failed_pc=0x0c08f5a0u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[4],fr[2],r[18]);
goto P_0c08f5a2;
P_0c08f5a2: /* original f5b1, guest PC 0x0c08f5a2 */
if(!s->budget--) { s->failed_pc=0x0c08f5a2u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[11],r[18],'-');
goto P_0c08f5a4;
P_0c08f5a4: /* original f68c, guest PC 0x0c08f5a4 */
if(!s->budget--) { s->failed_pc=0x0c08f5a4u; return 0; }
vf3_matrix_move(s,6,8);
goto P_0c08f5a6;
P_0c08f5a6: /* original f691, guest PC 0x0c08f5a6 */
if(!s->budget--) { s->failed_pc=0x0c08f5a6u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[9],r[18],'-');
goto P_0c08f5a8;
P_0c08f5a8: /* original f42c, guest PC 0x0c08f5a8 */
if(!s->budget--) { s->failed_pc=0x0c08f5a8u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c08f5aa;
P_0c08f5aa: /* original f35c, guest PC 0x0c08f5aa */
if(!s->budget--) { s->failed_pc=0x0c08f5aau; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c08f5ac;
P_0c08f5ac: /* original f56c, guest PC 0x0c08f5ac */
if(!s->budget--) { s->failed_pc=0x0c08f5acu; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c08f5ae;
P_0c08f5ae: /* original f532, guest PC 0x0c08f5ae */
if(!s->budget--) { s->failed_pc=0x0c08f5aeu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c08f5b0;
P_0c08f5b0: /* original f35c, guest PC 0x0c08f5b0 */
if(!s->budget--) { s->failed_pc=0x0c08f5b0u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c08f5b2;
P_0c08f5b2: /* original f5ac, guest PC 0x0c08f5b2 */
if(!s->budget--) { s->failed_pc=0x0c08f5b2u; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c08f5b4;
P_0c08f5b4: /* original f532, guest PC 0x0c08f5b4 */
if(!s->budget--) { s->failed_pc=0x0c08f5b4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c08f5b6;
P_0c08f5b6: /* original f05c, guest PC 0x0c08f5b6 */
if(!s->budget--) { s->failed_pc=0x0c08f5b6u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c08f5b8;
P_0c08f5b8: /* original f4ae, guest PC 0x0c08f5b8 */
if(!s->budget--) { s->failed_pc=0x0c08f5b8u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[10],fr[4],r[18]);
goto P_0c08f5ba;
P_0c08f5ba: /* original 000b, guest PC 0x0c08f5ba */
if(!s->budget--) { s->failed_pc=0x0c08f5bau; return 0; }
target=r[16];
vf3_matrix_move(s,0,4);
s->pc=target; return ram->oob==0;
P_0c08f5bc: /* original f04c, guest PC 0x0c08f5bc */
if(!s->budget--) { s->failed_pc=0x0c08f5bcu; return 0; }
vf3_matrix_move(s,0,4);
if(!vf3_matrix_family(0x0c08f5beu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08f5beu; return 0; } return 1;
P_0c08f632: /* original 2fe6, guest PC 0x0c08f632 */
if(!s->budget--) { s->failed_pc=0x0c08f632u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08f634;
P_0c08f634: /* original 6e43, guest PC 0x0c08f634 */
if(!s->budget--) { s->failed_pc=0x0c08f634u; return 0; }
r[14]=r[4];
goto P_0c08f636;
P_0c08f636: /* original 2fd6, guest PC 0x0c08f636 */
if(!s->budget--) { s->failed_pc=0x0c08f636u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08f638;
P_0c08f638: /* original 2fc6, guest PC 0x0c08f638 */
if(!s->budget--) { s->failed_pc=0x0c08f638u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08f63a;
P_0c08f63a: /* original fffb, guest PC 0x0c08f63a */
if(!s->budget--) { s->failed_pc=0x0c08f63au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08f63c;
P_0c08f63c: /* original ffeb, guest PC 0x0c08f63c */
if(!s->budget--) { s->failed_pc=0x0c08f63cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c08f63e;
P_0c08f63e: /* original ffdb, guest PC 0x0c08f63e */
if(!s->budget--) { s->failed_pc=0x0c08f63eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c08f640;
P_0c08f640: /* original 902b, guest PC 0x0c08f640 */
if(!s->budget--) { s->failed_pc=0x0c08f640u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f69au,2);
goto P_0c08f642;
P_0c08f642: /* original 4f22, guest PC 0x0c08f642 */
if(!s->budget--) { s->failed_pc=0x0c08f642u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08f644;
P_0c08f644: /* original fee6, guest PC 0x0c08f644 */
if(!s->budget--) { s->failed_pc=0x0c08f644u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c08f646;
P_0c08f646: /* original 7004, guest PC 0x0c08f646 */
if(!s->budget--) { s->failed_pc=0x0c08f646u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f648;
P_0c08f648: /* original ffe6, guest PC 0x0c08f648 */
if(!s->budget--) { s->failed_pc=0x0c08f648u; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c08f64a;
P_0c08f64a: /* original 7ffc, guest PC 0x0c08f64a */
if(!s->budget--) { s->failed_pc=0x0c08f64au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08f64c;
P_0c08f64c: /* original ffe5, guest PC 0x0c08f64c */
if(!s->budget--) { s->failed_pc=0x0c08f64cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[14]))!=0);
goto P_0c08f64e;
P_0c08f64e: /* original 8d02, guest PC 0x0c08f64e */
if(!s->budget--) { s->failed_pc=0x0c08f64eu; return 0; }
cond=r[17]&1u;
fr[13]=0x3f800000u;
if(cond) { goto P_0c08f656; }
goto P_0c08f652;
P_0c08f650: /* original fd9d, guest PC 0x0c08f650 */
if(!s->budget--) { s->failed_pc=0x0c08f650u; return 0; }
fr[13]=0x3f800000u;
goto P_0c08f652;
P_0c08f652: /* original a0c3, guest PC 0x0c08f652 */
if(!s->budget--) { s->failed_pc=0x0c08f652u; return 0; }
goto P_0c08f7dc;
P_0c08f654: /* original 0009, guest PC 0x0c08f654 */
if(!s->budget--) { s->failed_pc=0x0c08f654u; return 0; }
goto P_0c08f656;
P_0c08f656: /* original 9024, guest PC 0x0c08f656 */
if(!s->budget--) { s->failed_pc=0x0c08f656u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f6a2u,2);
goto P_0c08f658;
P_0c08f658: /* original 0dee, guest PC 0x0c08f658 */
if(!s->budget--) { s->failed_pc=0x0c08f658u; return 0; }
r[13]=read(ram,r[14]+r[0],4);
goto P_0c08f65a;
P_0c08f65a: /* original 7004, guest PC 0x0c08f65a */
if(!s->budget--) { s->failed_pc=0x0c08f65au; return 0; }
r[0]+=0x00000004u;
goto P_0c08f65c;
P_0c08f65c: /* original 04ee, guest PC 0x0c08f65c */
if(!s->budget--) { s->failed_pc=0x0c08f65cu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c08f65e;
P_0c08f65e: /* original 9c1a, guest PC 0x0c08f65e */
if(!s->budget--) { s->failed_pc=0x0c08f65eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f696u,2);
goto P_0c08f660;
P_0c08f660: /* original 65d3, guest PC 0x0c08f660 */
if(!s->budget--) { s->failed_pc=0x0c08f660u; return 0; }
r[5]=r[13];
goto P_0c08f662;
P_0c08f662: /* original 6d43, guest PC 0x0c08f662 */
if(!s->budget--) { s->failed_pc=0x0c08f662u; return 0; }
r[13]=r[4];
goto P_0c08f664;
P_0c08f664: /* original 3cec, guest PC 0x0c08f664 */
if(!s->budget--) { s->failed_pc=0x0c08f664u; return 0; }
r[12]+=r[14];
goto P_0c08f666;
P_0c08f666: /* original 54c1, guest PC 0x0c08f666 */
if(!s->budget--) { s->failed_pc=0x0c08f666u; return 0; }
r[4]=read(ram,r[12]+4,4);
goto P_0c08f668;
P_0c08f668: /* original 3540, guest PC 0x0c08f668 */
if(!s->budget--) { s->failed_pc=0x0c08f668u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[4])!=0);
goto P_0c08f66a;
P_0c08f66a: /* original 8903, guest PC 0x0c08f66a */
if(!s->budget--) { s->failed_pc=0x0c08f66au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08f674; }
goto P_0c08f66c;
P_0c08f66c: /* original 9512, guest PC 0x0c08f66c */
if(!s->budget--) { s->failed_pc=0x0c08f66cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f694u,2);
goto P_0c08f66e;
P_0c08f66e: /* original 35ec, guest PC 0x0c08f66e */
if(!s->budget--) { s->failed_pc=0x0c08f66eu; return 0; }
r[5]+=r[14];
goto P_0c08f670;
P_0c08f670: /* original bf1d, guest PC 0x0c08f670 */
if(!s->budget--) { s->failed_pc=0x0c08f670u; return 0; }
target=code_base|0x0c08f4aeu; r[16]=code_base|0x0c08f674u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f674u) { target=s->pc; goto dispatch; }
goto P_0c08f674;
P_0c08f672: /* original 64c3, guest PC 0x0c08f672 */
if(!s->budget--) { s->failed_pc=0x0c08f672u; return 0; }
r[4]=r[12];
goto P_0c08f674;
P_0c08f674: /* original 54d1, guest PC 0x0c08f674 */
if(!s->budget--) { s->failed_pc=0x0c08f674u; return 0; }
r[4]=read(ram,r[13]+4,4);
goto P_0c08f676;
P_0c08f676: /* original 34c0, guest PC 0x0c08f676 */
if(!s->budget--) { s->failed_pc=0x0c08f676u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[12])!=0);
goto P_0c08f678;
P_0c08f678: /* original 8b01, guest PC 0x0c08f678 */
if(!s->budget--) { s->failed_pc=0x0c08f678u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08f67e; }
goto P_0c08f67a;
P_0c08f67a: /* original a015, guest PC 0x0c08f67a */
if(!s->budget--) { s->failed_pc=0x0c08f67au; return 0; }
r[4]=r[13];
goto P_0c08f6a8;
P_0c08f67c: /* original 64d3, guest PC 0x0c08f67c */
if(!s->budget--) { s->failed_pc=0x0c08f67cu; return 0; }
r[4]=r[13];
goto P_0c08f67e;
P_0c08f67e: /* original 5542, guest PC 0x0c08f67e */
if(!s->budget--) { s->failed_pc=0x0c08f67eu; return 0; }
r[5]=read(ram,r[4]+8,4);
goto P_0c08f680;
P_0c08f680: /* original 56d2, guest PC 0x0c08f680 */
if(!s->budget--) { s->failed_pc=0x0c08f680u; return 0; }
r[6]=read(ram,r[13]+8,4);
goto P_0c08f682;
P_0c08f682: /* original f558, guest PC 0x0c08f682 */
if(!s->budget--) { s->failed_pc=0x0c08f682u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
goto P_0c08f684;
P_0c08f684: /* original f468, guest PC 0x0c08f684 */
if(!s->budget--) { s->failed_pc=0x0c08f684u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
goto P_0c08f686;
P_0c08f686: /* original f545, guest PC 0x0c08f686 */
if(!s->budget--) { s->failed_pc=0x0c08f686u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c08f688;
P_0c08f688: /* original 890e, guest PC 0x0c08f688 */
if(!s->budget--) { s->failed_pc=0x0c08f688u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08f6a8; }
goto P_0c08f68a;
P_0c08f68a: /* original 55ec, guest PC 0x0c08f68a */
if(!s->budget--) { s->failed_pc=0x0c08f68au; return 0; }
r[5]=read(ram,r[14]+48,4);
goto P_0c08f68c;
P_0c08f68c: /* original e302, guest PC 0x0c08f68c */
if(!s->budget--) { s->failed_pc=0x0c08f68cu; return 0; }
r[3]=0x00000002u;
goto P_0c08f68e;
P_0c08f68e: /* original 253b, guest PC 0x0c08f68e */
if(!s->budget--) { s->failed_pc=0x0c08f68eu; return 0; }
r[5]|=r[3];
goto P_0c08f690;
P_0c08f690: /* original afe5, guest PC 0x0c08f690 */
if(!s->budget--) { s->failed_pc=0x0c08f690u; return 0; }
write(ram,r[14]+48,r[5],4);
goto P_0c08f65e;
P_0c08f692: /* original 1e5c, guest PC 0x0c08f692 */
if(!s->budget--) { s->failed_pc=0x0c08f692u; return 0; }
write(ram,r[14]+48,r[5],4);
if(!vf3_matrix_family(0x0c08f694u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08f694u; return 0; } return 1;
P_0c08f6a8: /* original 65d2, guest PC 0x0c08f6a8 */
if(!s->budget--) { s->failed_pc=0x0c08f6a8u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c08f6aa;
P_0c08f6aa: /* original 35c0, guest PC 0x0c08f6aa */
if(!s->budget--) { s->failed_pc=0x0c08f6aau; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[12])!=0);
goto P_0c08f6ac;
P_0c08f6ac: /* original 8905, guest PC 0x0c08f6ac */
if(!s->budget--) { s->failed_pc=0x0c08f6acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08f6ba; }
goto P_0c08f6ae;
P_0c08f6ae: /* original 56d2, guest PC 0x0c08f6ae */
if(!s->budget--) { s->failed_pc=0x0c08f6aeu; return 0; }
r[6]=read(ram,r[13]+8,4);
goto P_0c08f6b0;
P_0c08f6b0: /* original 5752, guest PC 0x0c08f6b0 */
if(!s->budget--) { s->failed_pc=0x0c08f6b0u; return 0; }
r[7]=read(ram,r[5]+8,4);
goto P_0c08f6b2;
P_0c08f6b2: /* original f568, guest PC 0x0c08f6b2 */
if(!s->budget--) { s->failed_pc=0x0c08f6b2u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c08f6b4;
P_0c08f6b4: /* original f478, guest PC 0x0c08f6b4 */
if(!s->budget--) { s->failed_pc=0x0c08f6b4u; return 0; }
vf3_matrix_load(s,ram,4,r[7]);
goto P_0c08f6b6;
P_0c08f6b6: /* original f545, guest PC 0x0c08f6b6 */
if(!s->budget--) { s->failed_pc=0x0c08f6b6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c08f6b8;
P_0c08f6b8: /* original 8900, guest PC 0x0c08f6b8 */
if(!s->budget--) { s->failed_pc=0x0c08f6b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08f6bc; }
goto P_0c08f6ba;
P_0c08f6ba: /* original 6543, guest PC 0x0c08f6ba */
if(!s->budget--) { s->failed_pc=0x0c08f6bau; return 0; }
r[5]=r[4];
goto P_0c08f6bc;
P_0c08f6bc: /* original 5741, guest PC 0x0c08f6bc */
if(!s->budget--) { s->failed_pc=0x0c08f6bcu; return 0; }
r[7]=read(ram,r[4]+4,4);
goto P_0c08f6be;
P_0c08f6be: /* original 37c0, guest PC 0x0c08f6be */
if(!s->budget--) { s->failed_pc=0x0c08f6beu; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[12])!=0);
goto P_0c08f6c0;
P_0c08f6c0: /* original 8906, guest PC 0x0c08f6c0 */
if(!s->budget--) { s->failed_pc=0x0c08f6c0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08f6d0; }
goto P_0c08f6c2;
P_0c08f6c2: /* original 5342, guest PC 0x0c08f6c2 */
if(!s->budget--) { s->failed_pc=0x0c08f6c2u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c08f6c4;
P_0c08f6c4: /* original 2f32, guest PC 0x0c08f6c4 */
if(!s->budget--) { s->failed_pc=0x0c08f6c4u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08f6c6;
P_0c08f6c6: /* original 5672, guest PC 0x0c08f6c6 */
if(!s->budget--) { s->failed_pc=0x0c08f6c6u; return 0; }
r[6]=read(ram,r[7]+8,4);
goto P_0c08f6c8;
P_0c08f6c8: /* original f438, guest PC 0x0c08f6c8 */
if(!s->budget--) { s->failed_pc=0x0c08f6c8u; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c08f6ca;
P_0c08f6ca: /* original f568, guest PC 0x0c08f6ca */
if(!s->budget--) { s->failed_pc=0x0c08f6cau; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c08f6cc;
P_0c08f6cc: /* original f545, guest PC 0x0c08f6cc */
if(!s->budget--) { s->failed_pc=0x0c08f6ccu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c08f6ce;
P_0c08f6ce: /* original 8900, guest PC 0x0c08f6ce */
if(!s->budget--) { s->failed_pc=0x0c08f6ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08f6d2; }
goto P_0c08f6d0;
P_0c08f6d0: /* original 67d3, guest PC 0x0c08f6d0 */
if(!s->budget--) { s->failed_pc=0x0c08f6d0u; return 0; }
r[7]=r[13];
goto P_0c08f6d2;
P_0c08f6d2: /* original 909e, guest PC 0x0c08f6d2 */
if(!s->budget--) { s->failed_pc=0x0c08f6d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f812u,2);
goto P_0c08f6d4;
P_0c08f6d4: /* original 0ed6, guest PC 0x0c08f6d4 */
if(!s->budget--) { s->failed_pc=0x0c08f6d4u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c08f6d6;
P_0c08f6d6: /* original 7004, guest PC 0x0c08f6d6 */
if(!s->budget--) { s->failed_pc=0x0c08f6d6u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f6d8;
P_0c08f6d8: /* original 0e46, guest PC 0x0c08f6d8 */
if(!s->budget--) { s->failed_pc=0x0c08f6d8u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c08f6da;
P_0c08f6da: /* original 5442, guest PC 0x0c08f6da */
if(!s->budget--) { s->failed_pc=0x0c08f6dau; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c08f6dc;
P_0c08f6dc: /* original 56d2, guest PC 0x0c08f6dc */
if(!s->budget--) { s->failed_pc=0x0c08f6dcu; return 0; }
r[6]=read(ram,r[13]+8,4);
goto P_0c08f6de;
P_0c08f6de: /* original f748, guest PC 0x0c08f6de */
if(!s->budget--) { s->failed_pc=0x0c08f6deu; return 0; }
vf3_matrix_load(s,ram,7,r[4]);
goto P_0c08f6e0;
P_0c08f6e0: /* original f668, guest PC 0x0c08f6e0 */
if(!s->budget--) { s->failed_pc=0x0c08f6e0u; return 0; }
vf3_matrix_load(s,ram,6,r[6]);
goto P_0c08f6e2;
P_0c08f6e2: /* original fe7c, guest PC 0x0c08f6e2 */
if(!s->budget--) { s->failed_pc=0x0c08f6e2u; return 0; }
vf3_matrix_move(s,14,7);
goto P_0c08f6e4;
P_0c08f6e4: /* original fe61, guest PC 0x0c08f6e4 */
if(!s->budget--) { s->failed_pc=0x0c08f6e4u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[6],r[18],'-');
goto P_0c08f6e6;
P_0c08f6e6: /* original f38d, guest PC 0x0c08f6e6 */
if(!s->budget--) { s->failed_pc=0x0c08f6e6u; return 0; }
fr[3]=0;
goto P_0c08f6e8;
P_0c08f6e8: /* original 5552, guest PC 0x0c08f6e8 */
if(!s->budget--) { s->failed_pc=0x0c08f6e8u; return 0; }
r[5]=read(ram,r[5]+8,4);
goto P_0c08f6ea;
P_0c08f6ea: /* original 5772, guest PC 0x0c08f6ea */
if(!s->budget--) { s->failed_pc=0x0c08f6eau; return 0; }
r[7]=read(ram,r[7]+8,4);
goto P_0c08f6ec;
P_0c08f6ec: /* original f558, guest PC 0x0c08f6ec */
if(!s->budget--) { s->failed_pc=0x0c08f6ecu; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
goto P_0c08f6ee;
P_0c08f6ee: /* original fe34, guest PC 0x0c08f6ee */
if(!s->budget--) { s->failed_pc=0x0c08f6eeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])==as_float(fr[3]))!=0);
goto P_0c08f6f0;
P_0c08f6f0: /* original ffdc, guest PC 0x0c08f6f0 */
if(!s->budget--) { s->failed_pc=0x0c08f6f0u; return 0; }
vf3_matrix_move(s,15,13);
goto P_0c08f6f2;
P_0c08f6f2: /* original 8f01, guest PC 0x0c08f6f2 */
if(!s->budget--) { s->failed_pc=0x0c08f6f2u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[7]);
if(!cond) { goto P_0c08f6f8; }
goto P_0c08f6f6;
P_0c08f6f4: /* original f478, guest PC 0x0c08f6f4 */
if(!s->budget--) { s->failed_pc=0x0c08f6f4u; return 0; }
vf3_matrix_load(s,ram,4,r[7]);
goto P_0c08f6f6;
P_0c08f6f6: /* original fefc, guest PC 0x0c08f6f6 */
if(!s->budget--) { s->failed_pc=0x0c08f6f6u; return 0; }
vf3_matrix_move(s,14,15);
goto P_0c08f6f8;
P_0c08f6f8: /* original f35c, guest PC 0x0c08f6f8 */
if(!s->budget--) { s->failed_pc=0x0c08f6f8u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c08f6fa;
P_0c08f6fa: /* original f57c, guest PC 0x0c08f6fa */
if(!s->budget--) { s->failed_pc=0x0c08f6fau; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c08f6fc;
P_0c08f6fc: /* original f531, guest PC 0x0c08f6fc */
if(!s->budget--) { s->failed_pc=0x0c08f6fcu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c08f6fe;
P_0c08f6fe: /* original f28d, guest PC 0x0c08f6fe */
if(!s->budget--) { s->failed_pc=0x0c08f6feu; return 0; }
fr[2]=0;
goto P_0c08f700;
P_0c08f700: /* original f524, guest PC 0x0c08f700 */
if(!s->budget--) { s->failed_pc=0x0c08f700u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])==as_float(fr[2]))!=0);
goto P_0c08f702;
P_0c08f702: /* original 8f01, guest PC 0x0c08f702 */
if(!s->budget--) { s->failed_pc=0x0c08f702u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
if(!cond) { goto P_0c08f708; }
goto P_0c08f706;
P_0c08f704: /* original f461, guest PC 0x0c08f704 */
if(!s->budget--) { s->failed_pc=0x0c08f704u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
goto P_0c08f706;
P_0c08f706: /* original f5fc, guest PC 0x0c08f706 */
if(!s->budget--) { s->failed_pc=0x0c08f706u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08f708;
P_0c08f708: /* original f38d, guest PC 0x0c08f708 */
if(!s->budget--) { s->failed_pc=0x0c08f708u; return 0; }
fr[3]=0;
goto P_0c08f70a;
P_0c08f70a: /* original f434, guest PC 0x0c08f70a */
if(!s->budget--) { s->failed_pc=0x0c08f70au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c08f70c;
P_0c08f70c: /* original 8b00, guest PC 0x0c08f70c */
if(!s->budget--) { s->failed_pc=0x0c08f70cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08f710; }
goto P_0c08f70e;
P_0c08f70e: /* original f4fc, guest PC 0x0c08f70e */
if(!s->budget--) { s->failed_pc=0x0c08f70eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08f710;
P_0c08f710: /* original 9080, guest PC 0x0c08f710 */
if(!s->budget--) { s->failed_pc=0x0c08f710u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f814u,2);
goto P_0c08f712;
P_0c08f712: /* original fee7, guest PC 0x0c08f712 */
if(!s->budget--) { s->failed_pc=0x0c08f712u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c08f714;
P_0c08f714: /* original e004, guest PC 0x0c08f714 */
if(!s->budget--) { s->failed_pc=0x0c08f714u; return 0; }
r[0]=0x00000004u;
goto P_0c08f716;
P_0c08f716: /* original f35c, guest PC 0x0c08f716 */
if(!s->budget--) { s->failed_pc=0x0c08f716u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c08f718;
P_0c08f718: /* original f5dc, guest PC 0x0c08f718 */
if(!s->budget--) { s->failed_pc=0x0c08f718u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c08f71a;
P_0c08f71a: /* original f533, guest PC 0x0c08f71a */
if(!s->budget--) { s->failed_pc=0x0c08f71au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'/');
goto P_0c08f71c;
P_0c08f71c: /* original f34c, guest PC 0x0c08f71c */
if(!s->budget--) { s->failed_pc=0x0c08f71cu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c08f71e;
P_0c08f71e: /* original f4dc, guest PC 0x0c08f71e */
if(!s->budget--) { s->failed_pc=0x0c08f71eu; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c08f720;
P_0c08f720: /* original f433, guest PC 0x0c08f720 */
if(!s->budget--) { s->failed_pc=0x0c08f720u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c08f722;
P_0c08f722: /* original f656, guest PC 0x0c08f722 */
if(!s->budget--) { s->failed_pc=0x0c08f722u; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c08f724;
P_0c08f724: /* original f846, guest PC 0x0c08f724 */
if(!s->budget--) { s->failed_pc=0x0c08f724u; return 0; }
vf3_matrix_load(s,ram,8,r[4]+r[0]);
goto P_0c08f726;
P_0c08f726: /* original f36c, guest PC 0x0c08f726 */
if(!s->budget--) { s->failed_pc=0x0c08f726u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c08f728;
P_0c08f728: /* original f68c, guest PC 0x0c08f728 */
if(!s->budget--) { s->failed_pc=0x0c08f728u; return 0; }
vf3_matrix_move(s,6,8);
goto P_0c08f72a;
P_0c08f72a: /* original f631, guest PC 0x0c08f72a */
if(!s->budget--) { s->failed_pc=0x0c08f72au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c08f72c;
P_0c08f72c: /* original f966, guest PC 0x0c08f72c */
if(!s->budget--) { s->failed_pc=0x0c08f72cu; return 0; }
vf3_matrix_load(s,ram,9,r[6]+r[0]);
goto P_0c08f72e;
P_0c08f72e: /* original f776, guest PC 0x0c08f72e */
if(!s->budget--) { s->failed_pc=0x0c08f72eu; return 0; }
vf3_matrix_load(s,ram,7,r[7]+r[0]);
goto P_0c08f730;
P_0c08f730: /* original 9071, guest PC 0x0c08f730 */
if(!s->budget--) { s->failed_pc=0x0c08f730u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f816u,2);
goto P_0c08f732;
P_0c08f732: /* original f791, guest PC 0x0c08f732 */
if(!s->budget--) { s->failed_pc=0x0c08f732u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[9],r[18],'-');
goto P_0c08f734;
P_0c08f734: /* original f652, guest PC 0x0c08f734 */
if(!s->budget--) { s->failed_pc=0x0c08f734u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c08f736;
P_0c08f736: /* original f742, guest PC 0x0c08f736 */
if(!s->budget--) { s->failed_pc=0x0c08f736u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c08f738;
P_0c08f738: /* original fe67, guest PC 0x0c08f738 */
if(!s->budget--) { s->failed_pc=0x0c08f738u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c08f73a;
P_0c08f73a: /* original 7004, guest PC 0x0c08f73a */
if(!s->budget--) { s->failed_pc=0x0c08f73au; return 0; }
r[0]+=0x00000004u;
goto P_0c08f73c;
P_0c08f73c: /* original fe77, guest PC 0x0c08f73c */
if(!s->budget--) { s->failed_pc=0x0c08f73cu; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c08f73e;
P_0c08f73e: /* original e008, guest PC 0x0c08f73e */
if(!s->budget--) { s->failed_pc=0x0c08f73eu; return 0; }
r[0]=0x00000008u;
goto P_0c08f740;
P_0c08f740: /* original f746, guest PC 0x0c08f740 */
if(!s->budget--) { s->failed_pc=0x0c08f740u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c08f742;
P_0c08f742: /* original f676, guest PC 0x0c08f742 */
if(!s->budget--) { s->failed_pc=0x0c08f742u; return 0; }
vf3_matrix_load(s,ram,6,r[7]+r[0]);
goto P_0c08f744;
P_0c08f744: /* original f356, guest PC 0x0c08f744 */
if(!s->budget--) { s->failed_pc=0x0c08f744u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c08f746;
P_0c08f746: /* original f966, guest PC 0x0c08f746 */
if(!s->budget--) { s->failed_pc=0x0c08f746u; return 0; }
vf3_matrix_load(s,ram,9,r[6]+r[0]);
goto P_0c08f748;
P_0c08f748: /* original f731, guest PC 0x0c08f748 */
if(!s->budget--) { s->failed_pc=0x0c08f748u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c08f74a;
P_0c08f74a: /* original f691, guest PC 0x0c08f74a */
if(!s->budget--) { s->failed_pc=0x0c08f74au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[9],r[18],'-');
goto P_0c08f74c;
P_0c08f74c: /* original f752, guest PC 0x0c08f74c */
if(!s->budget--) { s->failed_pc=0x0c08f74cu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'*');
goto P_0c08f74e;
P_0c08f74e: /* original f642, guest PC 0x0c08f74e */
if(!s->budget--) { s->failed_pc=0x0c08f74eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c08f750;
P_0c08f750: /* original 9062, guest PC 0x0c08f750 */
if(!s->budget--) { s->failed_pc=0x0c08f750u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f818u,2);
goto P_0c08f752;
P_0c08f752: /* original fe77, guest PC 0x0c08f752 */
if(!s->budget--) { s->failed_pc=0x0c08f752u; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c08f754;
P_0c08f754: /* original 7004, guest PC 0x0c08f754 */
if(!s->budget--) { s->failed_pc=0x0c08f754u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f756;
P_0c08f756: /* original fe67, guest PC 0x0c08f756 */
if(!s->budget--) { s->failed_pc=0x0c08f756u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c08f758;
P_0c08f758: /* original e00c, guest PC 0x0c08f758 */
if(!s->budget--) { s->failed_pc=0x0c08f758u; return 0; }
r[0]=0x0000000cu;
goto P_0c08f75a;
P_0c08f75a: /* original f746, guest PC 0x0c08f75a */
if(!s->budget--) { s->failed_pc=0x0c08f75au; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c08f75c;
P_0c08f75c: /* original f356, guest PC 0x0c08f75c */
if(!s->budget--) { s->failed_pc=0x0c08f75cu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c08f75e;
P_0c08f75e: /* original f676, guest PC 0x0c08f75e */
if(!s->budget--) { s->failed_pc=0x0c08f75eu; return 0; }
vf3_matrix_load(s,ram,6,r[7]+r[0]);
goto P_0c08f760;
P_0c08f760: /* original f731, guest PC 0x0c08f760 */
if(!s->budget--) { s->failed_pc=0x0c08f760u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c08f762;
P_0c08f762: /* original f966, guest PC 0x0c08f762 */
if(!s->budget--) { s->failed_pc=0x0c08f762u; return 0; }
vf3_matrix_load(s,ram,9,r[6]+r[0]);
goto P_0c08f764;
P_0c08f764: /* original 9059, guest PC 0x0c08f764 */
if(!s->budget--) { s->failed_pc=0x0c08f764u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f81au,2);
goto P_0c08f766;
P_0c08f766: /* original f691, guest PC 0x0c08f766 */
if(!s->budget--) { s->failed_pc=0x0c08f766u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[9],r[18],'-');
goto P_0c08f768;
P_0c08f768: /* original f752, guest PC 0x0c08f768 */
if(!s->budget--) { s->failed_pc=0x0c08f768u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'*');
goto P_0c08f76a;
P_0c08f76a: /* original f642, guest PC 0x0c08f76a */
if(!s->budget--) { s->failed_pc=0x0c08f76au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c08f76c;
P_0c08f76c: /* original fe77, guest PC 0x0c08f76c */
if(!s->budget--) { s->failed_pc=0x0c08f76cu; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c08f76e;
P_0c08f76e: /* original 7004, guest PC 0x0c08f76e */
if(!s->budget--) { s->failed_pc=0x0c08f76eu; return 0; }
r[0]+=0x00000004u;
goto P_0c08f770;
P_0c08f770: /* original fe67, guest PC 0x0c08f770 */
if(!s->budget--) { s->failed_pc=0x0c08f770u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c08f772;
P_0c08f772: /* original e010, guest PC 0x0c08f772 */
if(!s->budget--) { s->failed_pc=0x0c08f772u; return 0; }
r[0]=0x00000010u;
goto P_0c08f774;
P_0c08f774: /* original f746, guest PC 0x0c08f774 */
if(!s->budget--) { s->failed_pc=0x0c08f774u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c08f776;
P_0c08f776: /* original f356, guest PC 0x0c08f776 */
if(!s->budget--) { s->failed_pc=0x0c08f776u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c08f778;
P_0c08f778: /* original f676, guest PC 0x0c08f778 */
if(!s->budget--) { s->failed_pc=0x0c08f778u; return 0; }
vf3_matrix_load(s,ram,6,r[7]+r[0]);
goto P_0c08f77a;
P_0c08f77a: /* original f731, guest PC 0x0c08f77a */
if(!s->budget--) { s->failed_pc=0x0c08f77au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c08f77c;
P_0c08f77c: /* original f966, guest PC 0x0c08f77c */
if(!s->budget--) { s->failed_pc=0x0c08f77cu; return 0; }
vf3_matrix_load(s,ram,9,r[6]+r[0]);
goto P_0c08f77e;
P_0c08f77e: /* original 904d, guest PC 0x0c08f77e */
if(!s->budget--) { s->failed_pc=0x0c08f77eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f81cu,2);
goto P_0c08f780;
P_0c08f780: /* original f691, guest PC 0x0c08f780 */
if(!s->budget--) { s->failed_pc=0x0c08f780u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[9],r[18],'-');
goto P_0c08f782;
P_0c08f782: /* original f752, guest PC 0x0c08f782 */
if(!s->budget--) { s->failed_pc=0x0c08f782u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'*');
goto P_0c08f784;
P_0c08f784: /* original f642, guest PC 0x0c08f784 */
if(!s->budget--) { s->failed_pc=0x0c08f784u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c08f786;
P_0c08f786: /* original fe77, guest PC 0x0c08f786 */
if(!s->budget--) { s->failed_pc=0x0c08f786u; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c08f788;
P_0c08f788: /* original 7004, guest PC 0x0c08f788 */
if(!s->budget--) { s->failed_pc=0x0c08f788u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f78a;
P_0c08f78a: /* original fe67, guest PC 0x0c08f78a */
if(!s->budget--) { s->failed_pc=0x0c08f78au; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c08f78c;
P_0c08f78c: /* original e014, guest PC 0x0c08f78c */
if(!s->budget--) { s->failed_pc=0x0c08f78cu; return 0; }
r[0]=0x00000014u;
goto P_0c08f78e;
P_0c08f78e: /* original f356, guest PC 0x0c08f78e */
if(!s->budget--) { s->failed_pc=0x0c08f78eu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c08f790;
P_0c08f790: /* original f746, guest PC 0x0c08f790 */
if(!s->budget--) { s->failed_pc=0x0c08f790u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c08f792;
P_0c08f792: /* original f676, guest PC 0x0c08f792 */
if(!s->budget--) { s->failed_pc=0x0c08f792u; return 0; }
vf3_matrix_load(s,ram,6,r[7]+r[0]);
goto P_0c08f794;
P_0c08f794: /* original f731, guest PC 0x0c08f794 */
if(!s->budget--) { s->failed_pc=0x0c08f794u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c08f796;
P_0c08f796: /* original f966, guest PC 0x0c08f796 */
if(!s->budget--) { s->failed_pc=0x0c08f796u; return 0; }
vf3_matrix_load(s,ram,9,r[6]+r[0]);
goto P_0c08f798;
P_0c08f798: /* original 9041, guest PC 0x0c08f798 */
if(!s->budget--) { s->failed_pc=0x0c08f798u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f81eu,2);
goto P_0c08f79a;
P_0c08f79a: /* original f691, guest PC 0x0c08f79a */
if(!s->budget--) { s->failed_pc=0x0c08f79au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[9],r[18],'-');
goto P_0c08f79c;
P_0c08f79c: /* original f752, guest PC 0x0c08f79c */
if(!s->budget--) { s->failed_pc=0x0c08f79cu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'*');
goto P_0c08f79e;
P_0c08f79e: /* original f642, guest PC 0x0c08f79e */
if(!s->budget--) { s->failed_pc=0x0c08f79eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c08f7a0;
P_0c08f7a0: /* original fe77, guest PC 0x0c08f7a0 */
if(!s->budget--) { s->failed_pc=0x0c08f7a0u; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c08f7a2;
P_0c08f7a2: /* original 7004, guest PC 0x0c08f7a2 */
if(!s->budget--) { s->failed_pc=0x0c08f7a2u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f7a4;
P_0c08f7a4: /* original fe67, guest PC 0x0c08f7a4 */
if(!s->budget--) { s->failed_pc=0x0c08f7a4u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c08f7a6;
P_0c08f7a6: /* original e018, guest PC 0x0c08f7a6 */
if(!s->budget--) { s->failed_pc=0x0c08f7a6u; return 0; }
r[0]=0x00000018u;
goto P_0c08f7a8;
P_0c08f7a8: /* original f646, guest PC 0x0c08f7a8 */
if(!s->budget--) { s->failed_pc=0x0c08f7a8u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c08f7aa;
P_0c08f7aa: /* original f356, guest PC 0x0c08f7aa */
if(!s->budget--) { s->failed_pc=0x0c08f7aau; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c08f7ac;
P_0c08f7ac: /* original f776, guest PC 0x0c08f7ac */
if(!s->budget--) { s->failed_pc=0x0c08f7acu; return 0; }
vf3_matrix_load(s,ram,7,r[7]+r[0]);
goto P_0c08f7ae;
P_0c08f7ae: /* original f631, guest PC 0x0c08f7ae */
if(!s->budget--) { s->failed_pc=0x0c08f7aeu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c08f7b0;
P_0c08f7b0: /* original f966, guest PC 0x0c08f7b0 */
if(!s->budget--) { s->failed_pc=0x0c08f7b0u; return 0; }
vf3_matrix_load(s,ram,9,r[6]+r[0]);
goto P_0c08f7b2;
P_0c08f7b2: /* original 9035, guest PC 0x0c08f7b2 */
if(!s->budget--) { s->failed_pc=0x0c08f7b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f820u,2);
goto P_0c08f7b4;
P_0c08f7b4: /* original f791, guest PC 0x0c08f7b4 */
if(!s->budget--) { s->failed_pc=0x0c08f7b4u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[9],r[18],'-');
goto P_0c08f7b6;
P_0c08f7b6: /* original f652, guest PC 0x0c08f7b6 */
if(!s->budget--) { s->failed_pc=0x0c08f7b6u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c08f7b8;
P_0c08f7b8: /* original f742, guest PC 0x0c08f7b8 */
if(!s->budget--) { s->failed_pc=0x0c08f7b8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c08f7ba;
P_0c08f7ba: /* original fe67, guest PC 0x0c08f7ba */
if(!s->budget--) { s->failed_pc=0x0c08f7bau; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c08f7bc;
P_0c08f7bc: /* original 7004, guest PC 0x0c08f7bc */
if(!s->budget--) { s->failed_pc=0x0c08f7bcu; return 0; }
r[0]+=0x00000004u;
goto P_0c08f7be;
P_0c08f7be: /* original fe77, guest PC 0x0c08f7be */
if(!s->budget--) { s->failed_pc=0x0c08f7beu; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c08f7c0;
P_0c08f7c0: /* original e01c, guest PC 0x0c08f7c0 */
if(!s->budget--) { s->failed_pc=0x0c08f7c0u; return 0; }
r[0]=0x0000001cu;
goto P_0c08f7c2;
P_0c08f7c2: /* original f946, guest PC 0x0c08f7c2 */
if(!s->budget--) { s->failed_pc=0x0c08f7c2u; return 0; }
vf3_matrix_load(s,ram,9,r[4]+r[0]);
goto P_0c08f7c4;
P_0c08f7c4: /* original f356, guest PC 0x0c08f7c4 */
if(!s->budget--) { s->failed_pc=0x0c08f7c4u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c08f7c6;
P_0c08f7c6: /* original f69c, guest PC 0x0c08f7c6 */
if(!s->budget--) { s->failed_pc=0x0c08f7c6u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c08f7c8;
P_0c08f7c8: /* original f631, guest PC 0x0c08f7c8 */
if(!s->budget--) { s->failed_pc=0x0c08f7c8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c08f7ca;
P_0c08f7ca: /* original f866, guest PC 0x0c08f7ca */
if(!s->budget--) { s->failed_pc=0x0c08f7cau; return 0; }
vf3_matrix_load(s,ram,8,r[6]+r[0]);
goto P_0c08f7cc;
P_0c08f7cc: /* original f776, guest PC 0x0c08f7cc */
if(!s->budget--) { s->failed_pc=0x0c08f7ccu; return 0; }
vf3_matrix_load(s,ram,7,r[7]+r[0]);
goto P_0c08f7ce;
P_0c08f7ce: /* original f652, guest PC 0x0c08f7ce */
if(!s->budget--) { s->failed_pc=0x0c08f7ceu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c08f7d0;
P_0c08f7d0: /* original f781, guest PC 0x0c08f7d0 */
if(!s->budget--) { s->failed_pc=0x0c08f7d0u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[8],r[18],'-');
goto P_0c08f7d2;
P_0c08f7d2: /* original 9026, guest PC 0x0c08f7d2 */
if(!s->budget--) { s->failed_pc=0x0c08f7d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f822u,2);
goto P_0c08f7d4;
P_0c08f7d4: /* original fe67, guest PC 0x0c08f7d4 */
if(!s->budget--) { s->failed_pc=0x0c08f7d4u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c08f7d6;
P_0c08f7d6: /* original 7004, guest PC 0x0c08f7d6 */
if(!s->budget--) { s->failed_pc=0x0c08f7d6u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f7d8;
P_0c08f7d8: /* original f742, guest PC 0x0c08f7d8 */
if(!s->budget--) { s->failed_pc=0x0c08f7d8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c08f7da;
P_0c08f7da: /* original fe77, guest PC 0x0c08f7da */
if(!s->budget--) { s->failed_pc=0x0c08f7dau; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c08f7dc;
P_0c08f7dc: /* original 9019, guest PC 0x0c08f7dc */
if(!s->budget--) { s->failed_pc=0x0c08f7dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f812u,2);
goto P_0c08f7de;
P_0c08f7de: /* original f5ec, guest PC 0x0c08f7de */
if(!s->budget--) { s->failed_pc=0x0c08f7deu; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c08f7e0;
P_0c08f7e0: /* original 05ee, guest PC 0x0c08f7e0 */
if(!s->budget--) { s->failed_pc=0x0c08f7e0u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c08f7e2;
P_0c08f7e2: /* original 7004, guest PC 0x0c08f7e2 */
if(!s->budget--) { s->failed_pc=0x0c08f7e2u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f7e4;
P_0c08f7e4: /* original 04ee, guest PC 0x0c08f7e4 */
if(!s->budget--) { s->failed_pc=0x0c08f7e4u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c08f7e6;
P_0c08f7e6: /* original e004, guest PC 0x0c08f7e6 */
if(!s->budget--) { s->failed_pc=0x0c08f7e6u; return 0; }
r[0]=0x00000004u;
goto P_0c08f7e8;
P_0c08f7e8: /* original 5d52, guest PC 0x0c08f7e8 */
if(!s->budget--) { s->failed_pc=0x0c08f7e8u; return 0; }
r[13]=read(ram,r[5]+8,4);
goto P_0c08f7ea;
P_0c08f7ea: /* original 5c42, guest PC 0x0c08f7ea */
if(!s->budget--) { s->failed_pc=0x0c08f7eau; return 0; }
r[12]=read(ram,r[4]+8,4);
goto P_0c08f7ec;
P_0c08f7ec: /* original f8d6, guest PC 0x0c08f7ec */
if(!s->budget--) { s->failed_pc=0x0c08f7ecu; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c08f7ee;
P_0c08f7ee: /* original f9c6, guest PC 0x0c08f7ee */
if(!s->budget--) { s->failed_pc=0x0c08f7eeu; return 0; }
vf3_matrix_load(s,ram,9,r[12]+r[0]);
goto P_0c08f7f0;
P_0c08f7f0: /* original 9011, guest PC 0x0c08f7f0 */
if(!s->budget--) { s->failed_pc=0x0c08f7f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f816u,2);
goto P_0c08f7f2;
P_0c08f7f2: /* original f7e6, guest PC 0x0c08f7f2 */
if(!s->budget--) { s->failed_pc=0x0c08f7f2u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c08f7f4;
P_0c08f7f4: /* original 7004, guest PC 0x0c08f7f4 */
if(!s->budget--) { s->failed_pc=0x0c08f7f4u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f7f6;
P_0c08f7f6: /* original f6e6, guest PC 0x0c08f7f6 */
if(!s->budget--) { s->failed_pc=0x0c08f7f6u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08f7f8;
P_0c08f7f8: /* original bec3, guest PC 0x0c08f7f8 */
if(!s->budget--) { s->failed_pc=0x0c08f7f8u; return 0; }
target=code_base|0x0c08f582u; r[16]=code_base|0x0c08f7fcu;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f7fcu) { target=s->pc; goto dispatch; }
goto P_0c08f7fc;
P_0c08f7fa: /* original f4fc, guest PC 0x0c08f7fa */
if(!s->budget--) { s->failed_pc=0x0c08f7fau; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08f7fc;
P_0c08f7fc: /* original e06c, guest PC 0x0c08f7fc */
if(!s->budget--) { s->failed_pc=0x0c08f7fcu; return 0; }
r[0]=0x0000006cu;
goto P_0c08f7fe;
P_0c08f7fe: /* original fe07, guest PC 0x0c08f7fe */
if(!s->budget--) { s->failed_pc=0x0c08f7feu; return 0; }
vf3_matrix_store(s,ram,0,r[14]+r[0]);
goto P_0c08f800;
P_0c08f800: /* original e008, guest PC 0x0c08f800 */
if(!s->budget--) { s->failed_pc=0x0c08f800u; return 0; }
r[0]=0x00000008u;
goto P_0c08f802;
P_0c08f802: /* original f9c6, guest PC 0x0c08f802 */
if(!s->budget--) { s->failed_pc=0x0c08f802u; return 0; }
vf3_matrix_load(s,ram,9,r[12]+r[0]);
goto P_0c08f804;
P_0c08f804: /* original f8d6, guest PC 0x0c08f804 */
if(!s->budget--) { s->failed_pc=0x0c08f804u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c08f806;
P_0c08f806: /* original 9007, guest PC 0x0c08f806 */
if(!s->budget--) { s->failed_pc=0x0c08f806u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f818u,2);
goto P_0c08f808;
P_0c08f808: /* original f7e6, guest PC 0x0c08f808 */
if(!s->budget--) { s->failed_pc=0x0c08f808u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c08f80a;
P_0c08f80a: /* original 7004, guest PC 0x0c08f80a */
if(!s->budget--) { s->failed_pc=0x0c08f80au; return 0; }
r[0]+=0x00000004u;
goto P_0c08f80c;
P_0c08f80c: /* original f6e6, guest PC 0x0c08f80c */
if(!s->budget--) { s->failed_pc=0x0c08f80cu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08f80e;
P_0c08f80e: /* original a009, guest PC 0x0c08f80e */
if(!s->budget--) { s->failed_pc=0x0c08f80eu; return 0; }
goto P_0c08f824;
P_0c08f810: /* original 0009, guest PC 0x0c08f810 */
if(!s->budget--) { s->failed_pc=0x0c08f810u; return 0; }
if(!vf3_matrix_family(0x0c08f812u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08f812u; return 0; } return 1;
P_0c08f824: /* original f5ec, guest PC 0x0c08f824 */
if(!s->budget--) { s->failed_pc=0x0c08f824u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c08f826;
P_0c08f826: /* original beac, guest PC 0x0c08f826 */
if(!s->budget--) { s->failed_pc=0x0c08f826u; return 0; }
target=code_base|0x0c08f582u; r[16]=code_base|0x0c08f82au;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f82au) { target=s->pc; goto dispatch; }
goto P_0c08f82a;
P_0c08f828: /* original f4fc, guest PC 0x0c08f828 */
if(!s->budget--) { s->failed_pc=0x0c08f828u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08f82a;
P_0c08f82a: /* original 90a9, guest PC 0x0c08f82a */
if(!s->budget--) { s->failed_pc=0x0c08f82au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f980u,2);
goto P_0c08f82c;
P_0c08f82c: /* original fe07, guest PC 0x0c08f82c */
if(!s->budget--) { s->failed_pc=0x0c08f82cu; return 0; }
vf3_matrix_store(s,ram,0,r[14]+r[0]);
goto P_0c08f82e;
P_0c08f82e: /* original e00c, guest PC 0x0c08f82e */
if(!s->budget--) { s->failed_pc=0x0c08f82eu; return 0; }
r[0]=0x0000000cu;
goto P_0c08f830;
P_0c08f830: /* original f9c6, guest PC 0x0c08f830 */
if(!s->budget--) { s->failed_pc=0x0c08f830u; return 0; }
vf3_matrix_load(s,ram,9,r[12]+r[0]);
goto P_0c08f832;
P_0c08f832: /* original f8d6, guest PC 0x0c08f832 */
if(!s->budget--) { s->failed_pc=0x0c08f832u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c08f834;
P_0c08f834: /* original 90a5, guest PC 0x0c08f834 */
if(!s->budget--) { s->failed_pc=0x0c08f834u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f982u,2);
goto P_0c08f836;
P_0c08f836: /* original f5ec, guest PC 0x0c08f836 */
if(!s->budget--) { s->failed_pc=0x0c08f836u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c08f838;
P_0c08f838: /* original f7e6, guest PC 0x0c08f838 */
if(!s->budget--) { s->failed_pc=0x0c08f838u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c08f83a;
P_0c08f83a: /* original 7004, guest PC 0x0c08f83a */
if(!s->budget--) { s->failed_pc=0x0c08f83au; return 0; }
r[0]+=0x00000004u;
goto P_0c08f83c;
P_0c08f83c: /* original f6e6, guest PC 0x0c08f83c */
if(!s->budget--) { s->failed_pc=0x0c08f83cu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08f83e;
P_0c08f83e: /* original bea0, guest PC 0x0c08f83e */
if(!s->budget--) { s->failed_pc=0x0c08f83eu; return 0; }
target=code_base|0x0c08f582u; r[16]=code_base|0x0c08f842u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f842u) { target=s->pc; goto dispatch; }
goto P_0c08f842;
P_0c08f840: /* original f4fc, guest PC 0x0c08f840 */
if(!s->budget--) { s->failed_pc=0x0c08f840u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08f842;
P_0c08f842: /* original 909f, guest PC 0x0c08f842 */
if(!s->budget--) { s->failed_pc=0x0c08f842u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f984u,2);
goto P_0c08f844;
P_0c08f844: /* original fe07, guest PC 0x0c08f844 */
if(!s->budget--) { s->failed_pc=0x0c08f844u; return 0; }
vf3_matrix_store(s,ram,0,r[14]+r[0]);
goto P_0c08f846;
P_0c08f846: /* original e010, guest PC 0x0c08f846 */
if(!s->budget--) { s->failed_pc=0x0c08f846u; return 0; }
r[0]=0x00000010u;
goto P_0c08f848;
P_0c08f848: /* original f9c6, guest PC 0x0c08f848 */
if(!s->budget--) { s->failed_pc=0x0c08f848u; return 0; }
vf3_matrix_load(s,ram,9,r[12]+r[0]);
goto P_0c08f84a;
P_0c08f84a: /* original f8d6, guest PC 0x0c08f84a */
if(!s->budget--) { s->failed_pc=0x0c08f84au; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c08f84c;
P_0c08f84c: /* original 909b, guest PC 0x0c08f84c */
if(!s->budget--) { s->failed_pc=0x0c08f84cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f986u,2);
goto P_0c08f84e;
P_0c08f84e: /* original f5ec, guest PC 0x0c08f84e */
if(!s->budget--) { s->failed_pc=0x0c08f84eu; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c08f850;
P_0c08f850: /* original f7e6, guest PC 0x0c08f850 */
if(!s->budget--) { s->failed_pc=0x0c08f850u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c08f852;
P_0c08f852: /* original 7004, guest PC 0x0c08f852 */
if(!s->budget--) { s->failed_pc=0x0c08f852u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f854;
P_0c08f854: /* original f6e6, guest PC 0x0c08f854 */
if(!s->budget--) { s->failed_pc=0x0c08f854u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08f856;
P_0c08f856: /* original be94, guest PC 0x0c08f856 */
if(!s->budget--) { s->failed_pc=0x0c08f856u; return 0; }
target=code_base|0x0c08f582u; r[16]=code_base|0x0c08f85au;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f85au) { target=s->pc; goto dispatch; }
goto P_0c08f85a;
P_0c08f858: /* original f4fc, guest PC 0x0c08f858 */
if(!s->budget--) { s->failed_pc=0x0c08f858u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08f85a;
P_0c08f85a: /* original 9095, guest PC 0x0c08f85a */
if(!s->budget--) { s->failed_pc=0x0c08f85au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f988u,2);
goto P_0c08f85c;
P_0c08f85c: /* original fe07, guest PC 0x0c08f85c */
if(!s->budget--) { s->failed_pc=0x0c08f85cu; return 0; }
vf3_matrix_store(s,ram,0,r[14]+r[0]);
goto P_0c08f85e;
P_0c08f85e: /* original e014, guest PC 0x0c08f85e */
if(!s->budget--) { s->failed_pc=0x0c08f85eu; return 0; }
r[0]=0x00000014u;
goto P_0c08f860;
P_0c08f860: /* original f9c6, guest PC 0x0c08f860 */
if(!s->budget--) { s->failed_pc=0x0c08f860u; return 0; }
vf3_matrix_load(s,ram,9,r[12]+r[0]);
goto P_0c08f862;
P_0c08f862: /* original f8d6, guest PC 0x0c08f862 */
if(!s->budget--) { s->failed_pc=0x0c08f862u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c08f864;
P_0c08f864: /* original 9091, guest PC 0x0c08f864 */
if(!s->budget--) { s->failed_pc=0x0c08f864u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f98au,2);
goto P_0c08f866;
P_0c08f866: /* original f5ec, guest PC 0x0c08f866 */
if(!s->budget--) { s->failed_pc=0x0c08f866u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c08f868;
P_0c08f868: /* original f7e6, guest PC 0x0c08f868 */
if(!s->budget--) { s->failed_pc=0x0c08f868u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c08f86a;
P_0c08f86a: /* original 7004, guest PC 0x0c08f86a */
if(!s->budget--) { s->failed_pc=0x0c08f86au; return 0; }
r[0]+=0x00000004u;
goto P_0c08f86c;
P_0c08f86c: /* original f6e6, guest PC 0x0c08f86c */
if(!s->budget--) { s->failed_pc=0x0c08f86cu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08f86e;
P_0c08f86e: /* original be88, guest PC 0x0c08f86e */
if(!s->budget--) { s->failed_pc=0x0c08f86eu; return 0; }
target=code_base|0x0c08f582u; r[16]=code_base|0x0c08f872u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f872u) { target=s->pc; goto dispatch; }
goto P_0c08f872;
P_0c08f870: /* original f4fc, guest PC 0x0c08f870 */
if(!s->budget--) { s->failed_pc=0x0c08f870u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08f872;
P_0c08f872: /* original 908b, guest PC 0x0c08f872 */
if(!s->budget--) { s->failed_pc=0x0c08f872u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f98cu,2);
goto P_0c08f874;
P_0c08f874: /* original fe07, guest PC 0x0c08f874 */
if(!s->budget--) { s->failed_pc=0x0c08f874u; return 0; }
vf3_matrix_store(s,ram,0,r[14]+r[0]);
goto P_0c08f876;
P_0c08f876: /* original e018, guest PC 0x0c08f876 */
if(!s->budget--) { s->failed_pc=0x0c08f876u; return 0; }
r[0]=0x00000018u;
goto P_0c08f878;
P_0c08f878: /* original f9c6, guest PC 0x0c08f878 */
if(!s->budget--) { s->failed_pc=0x0c08f878u; return 0; }
vf3_matrix_load(s,ram,9,r[12]+r[0]);
goto P_0c08f87a;
P_0c08f87a: /* original f8d6, guest PC 0x0c08f87a */
if(!s->budget--) { s->failed_pc=0x0c08f87au; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c08f87c;
P_0c08f87c: /* original 9087, guest PC 0x0c08f87c */
if(!s->budget--) { s->failed_pc=0x0c08f87cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f98eu,2);
goto P_0c08f87e;
P_0c08f87e: /* original f5ec, guest PC 0x0c08f87e */
if(!s->budget--) { s->failed_pc=0x0c08f87eu; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c08f880;
P_0c08f880: /* original f7e6, guest PC 0x0c08f880 */
if(!s->budget--) { s->failed_pc=0x0c08f880u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c08f882;
P_0c08f882: /* original 7004, guest PC 0x0c08f882 */
if(!s->budget--) { s->failed_pc=0x0c08f882u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f884;
P_0c08f884: /* original f6e6, guest PC 0x0c08f884 */
if(!s->budget--) { s->failed_pc=0x0c08f884u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08f886;
P_0c08f886: /* original be7c, guest PC 0x0c08f886 */
if(!s->budget--) { s->failed_pc=0x0c08f886u; return 0; }
target=code_base|0x0c08f582u; r[16]=code_base|0x0c08f88au;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f88au) { target=s->pc; goto dispatch; }
goto P_0c08f88a;
P_0c08f888: /* original f4fc, guest PC 0x0c08f888 */
if(!s->budget--) { s->failed_pc=0x0c08f888u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08f88a;
P_0c08f88a: /* original 9081, guest PC 0x0c08f88a */
if(!s->budget--) { s->failed_pc=0x0c08f88au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f990u,2);
goto P_0c08f88c;
P_0c08f88c: /* original fe07, guest PC 0x0c08f88c */
if(!s->budget--) { s->failed_pc=0x0c08f88cu; return 0; }
vf3_matrix_store(s,ram,0,r[14]+r[0]);
goto P_0c08f88e;
P_0c08f88e: /* original e01c, guest PC 0x0c08f88e */
if(!s->budget--) { s->failed_pc=0x0c08f88eu; return 0; }
r[0]=0x0000001cu;
goto P_0c08f890;
P_0c08f890: /* original f9c6, guest PC 0x0c08f890 */
if(!s->budget--) { s->failed_pc=0x0c08f890u; return 0; }
vf3_matrix_load(s,ram,9,r[12]+r[0]);
goto P_0c08f892;
P_0c08f892: /* original f8d6, guest PC 0x0c08f892 */
if(!s->budget--) { s->failed_pc=0x0c08f892u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c08f894;
P_0c08f894: /* original 907d, guest PC 0x0c08f894 */
if(!s->budget--) { s->failed_pc=0x0c08f894u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f992u,2);
goto P_0c08f896;
P_0c08f896: /* original f5ec, guest PC 0x0c08f896 */
if(!s->budget--) { s->failed_pc=0x0c08f896u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c08f898;
P_0c08f898: /* original f7e6, guest PC 0x0c08f898 */
if(!s->budget--) { s->failed_pc=0x0c08f898u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c08f89a;
P_0c08f89a: /* original 7004, guest PC 0x0c08f89a */
if(!s->budget--) { s->failed_pc=0x0c08f89au; return 0; }
r[0]+=0x00000004u;
goto P_0c08f89c;
P_0c08f89c: /* original f6e6, guest PC 0x0c08f89c */
if(!s->budget--) { s->failed_pc=0x0c08f89cu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08f89e;
P_0c08f89e: /* original be70, guest PC 0x0c08f89e */
if(!s->budget--) { s->failed_pc=0x0c08f89eu; return 0; }
target=code_base|0x0c08f582u; r[16]=code_base|0x0c08f8a2u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f8a2u) { target=s->pc; goto dispatch; }
goto P_0c08f8a2;
P_0c08f8a0: /* original f4fc, guest PC 0x0c08f8a0 */
if(!s->budget--) { s->failed_pc=0x0c08f8a0u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08f8a2;
P_0c08f8a2: /* original 7f04, guest PC 0x0c08f8a2 */
if(!s->budget--) { s->failed_pc=0x0c08f8a2u; return 0; }
r[15]+=0x00000004u;
goto P_0c08f8a4;
P_0c08f8a4: /* original 9076, guest PC 0x0c08f8a4 */
if(!s->budget--) { s->failed_pc=0x0c08f8a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f994u,2);
goto P_0c08f8a6;
P_0c08f8a6: /* original 4f26, guest PC 0x0c08f8a6 */
if(!s->budget--) { s->failed_pc=0x0c08f8a6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08f8a8;
P_0c08f8a8: /* original ffd0, guest PC 0x0c08f8a8 */
if(!s->budget--) { s->failed_pc=0x0c08f8a8u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[13],r[18],'+');
goto P_0c08f8aa;
P_0c08f8aa: /* original fe07, guest PC 0x0c08f8aa */
if(!s->budget--) { s->failed_pc=0x0c08f8aau; return 0; }
vf3_matrix_store(s,ram,0,r[14]+r[0]);
goto P_0c08f8ac;
P_0c08f8ac: /* original 9073, guest PC 0x0c08f8ac */
if(!s->budget--) { s->failed_pc=0x0c08f8acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f996u,2);
goto P_0c08f8ae;
P_0c08f8ae: /* original fef7, guest PC 0x0c08f8ae */
if(!s->budget--) { s->failed_pc=0x0c08f8aeu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c08f8b0;
P_0c08f8b0: /* original fdf9, guest PC 0x0c08f8b0 */
if(!s->budget--) { s->failed_pc=0x0c08f8b0u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08f8b2;
P_0c08f8b2: /* original fef9, guest PC 0x0c08f8b2 */
if(!s->budget--) { s->failed_pc=0x0c08f8b2u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08f8b4;
P_0c08f8b4: /* original fff9, guest PC 0x0c08f8b4 */
if(!s->budget--) { s->failed_pc=0x0c08f8b4u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08f8b6;
P_0c08f8b6: /* original 6cf6, guest PC 0x0c08f8b6 */
if(!s->budget--) { s->failed_pc=0x0c08f8b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08f8b8;
P_0c08f8b8: /* original 6df6, guest PC 0x0c08f8b8 */
if(!s->budget--) { s->failed_pc=0x0c08f8b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08f8ba;
P_0c08f8ba: /* original 000b, guest PC 0x0c08f8ba */
if(!s->budget--) { s->failed_pc=0x0c08f8bau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08f8bc: /* original 6ef6, guest PC 0x0c08f8bc */
if(!s->budget--) { s->failed_pc=0x0c08f8bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08f8beu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
