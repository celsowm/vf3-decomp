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
int vf3_tenpp_survey_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04625cu: goto P_0c04625c;
case 0x0c04625eu: goto P_0c04625e;
case 0x0c046260u: goto P_0c046260;
case 0x0c046262u: goto P_0c046262;
case 0x0c046264u: goto P_0c046264;
case 0x0c046266u: goto P_0c046266;
case 0x0c046268u: goto P_0c046268;
case 0x0c04626au: goto P_0c04626a;
case 0x0c04626cu: goto P_0c04626c;
case 0x0c04626eu: goto P_0c04626e;
case 0x0c046270u: goto P_0c046270;
case 0x0c046272u: goto P_0c046272;
case 0x0c046274u: goto P_0c046274;
case 0x0c046276u: goto P_0c046276;
case 0x0c046278u: goto P_0c046278;
case 0x0c04627au: goto P_0c04627a;
case 0x0c04627cu: goto P_0c04627c;
case 0x0c04627eu: goto P_0c04627e;
case 0x0c046280u: goto P_0c046280;
case 0x0c046282u: goto P_0c046282;
case 0x0c046284u: goto P_0c046284;
case 0x0c046286u: goto P_0c046286;
case 0x0c046288u: goto P_0c046288;
case 0x0c04628au: goto P_0c04628a;
case 0x0c04628cu: goto P_0c04628c;
case 0x0c04628eu: goto P_0c04628e;
case 0x0c046290u: goto P_0c046290;
case 0x0c046292u: goto P_0c046292;
case 0x0c046294u: goto P_0c046294;
case 0x0c046296u: goto P_0c046296;
case 0x0c046298u: goto P_0c046298;
case 0x0c04629au: goto P_0c04629a;
case 0x0c04629cu: goto P_0c04629c;
case 0x0c04629eu: goto P_0c04629e;
case 0x0c0462a0u: goto P_0c0462a0;
case 0x0c047230u: goto P_0c047230;
case 0x0c047232u: goto P_0c047232;
case 0x0c047234u: goto P_0c047234;
case 0x0c047236u: goto P_0c047236;
case 0x0c047238u: goto P_0c047238;
case 0x0c04723au: goto P_0c04723a;
case 0x0c04723cu: goto P_0c04723c;
case 0x0c04723eu: goto P_0c04723e;
case 0x0c047240u: goto P_0c047240;
case 0x0c047242u: goto P_0c047242;
case 0x0c047244u: goto P_0c047244;
case 0x0c047246u: goto P_0c047246;
case 0x0c047248u: goto P_0c047248;
case 0x0c04724au: goto P_0c04724a;
case 0x0c04724cu: goto P_0c04724c;
case 0x0c04724eu: goto P_0c04724e;
case 0x0c047250u: goto P_0c047250;
case 0x0c047252u: goto P_0c047252;
case 0x0c047254u: goto P_0c047254;
case 0x0c047256u: goto P_0c047256;
case 0x0c047258u: goto P_0c047258;
case 0x0c04725au: goto P_0c04725a;
case 0x0c04725cu: goto P_0c04725c;
case 0x0c04725eu: goto P_0c04725e;
case 0x0c047260u: goto P_0c047260;
case 0x0c047262u: goto P_0c047262;
case 0x0c047264u: goto P_0c047264;
case 0x0c047266u: goto P_0c047266;
case 0x0c047268u: goto P_0c047268;
case 0x0c04726au: goto P_0c04726a;
case 0x0c04726cu: goto P_0c04726c;
case 0x0c04726eu: goto P_0c04726e;
case 0x0c047270u: goto P_0c047270;
case 0x0c047272u: goto P_0c047272;
case 0x0c047274u: goto P_0c047274;
case 0x0c047276u: goto P_0c047276;
case 0x0c047278u: goto P_0c047278;
case 0x0c04727au: goto P_0c04727a;
case 0x0c04727cu: goto P_0c04727c;
case 0x0c04727eu: goto P_0c04727e;
case 0x0c047280u: goto P_0c047280;
case 0x0c047282u: goto P_0c047282;
case 0x0c047284u: goto P_0c047284;
case 0x0c047286u: goto P_0c047286;
case 0x0c047288u: goto P_0c047288;
case 0x0c04728au: goto P_0c04728a;
case 0x0c04728cu: goto P_0c04728c;
case 0x0c04fab4u: goto P_0c04fab4;
case 0x0c04fab6u: goto P_0c04fab6;
case 0x0c04fab8u: goto P_0c04fab8;
case 0x0c04fabau: goto P_0c04faba;
case 0x0c04fabcu: goto P_0c04fabc;
case 0x0c04fabeu: goto P_0c04fabe;
case 0x0c04fac0u: goto P_0c04fac0;
case 0x0c04fac2u: goto P_0c04fac2;
case 0x0c04fac4u: goto P_0c04fac4;
case 0x0c04fac6u: goto P_0c04fac6;
case 0x0c04fac8u: goto P_0c04fac8;
case 0x0c04facau: goto P_0c04faca;
case 0x0c04faccu: goto P_0c04facc;
case 0x0c04faceu: goto P_0c04face;
case 0x0c04fad0u: goto P_0c04fad0;
case 0x0c04fad2u: goto P_0c04fad2;
case 0x0c04fad4u: goto P_0c04fad4;
case 0x0c04fad6u: goto P_0c04fad6;
case 0x0c04fad8u: goto P_0c04fad8;
case 0x0c04fadau: goto P_0c04fada;
case 0x0c04fadcu: goto P_0c04fadc;
case 0x0c04fadeu: goto P_0c04fade;
case 0x0c04fae0u: goto P_0c04fae0;
case 0x0c04fae2u: goto P_0c04fae2;
case 0x0c050128u: goto P_0c050128;
case 0x0c05012au: goto P_0c05012a;
case 0x0c05012cu: goto P_0c05012c;
case 0x0c05012eu: goto P_0c05012e;
case 0x0c050130u: goto P_0c050130;
case 0x0c050132u: goto P_0c050132;
case 0x0c050134u: goto P_0c050134;
case 0x0c050136u: goto P_0c050136;
case 0x0c050138u: goto P_0c050138;
case 0x0c05013au: goto P_0c05013a;
case 0x0c05013cu: goto P_0c05013c;
case 0x0c05013eu: goto P_0c05013e;
case 0x0c050140u: goto P_0c050140;
case 0x0c050142u: goto P_0c050142;
case 0x0c050144u: goto P_0c050144;
case 0x0c050146u: goto P_0c050146;
case 0x0c050148u: goto P_0c050148;
case 0x0c05014au: goto P_0c05014a;
case 0x0c05014cu: goto P_0c05014c;
case 0x0c05014eu: goto P_0c05014e;
case 0x0c050150u: goto P_0c050150;
case 0x0c050152u: goto P_0c050152;
case 0x0c050154u: goto P_0c050154;
case 0x0c050156u: goto P_0c050156;
case 0x0c050158u: goto P_0c050158;
case 0x0c05015au: goto P_0c05015a;
case 0x0c05015cu: goto P_0c05015c;
case 0x0c05015eu: goto P_0c05015e;
case 0x0c050160u: goto P_0c050160;
case 0x0c050162u: goto P_0c050162;
case 0x0c050174u: goto P_0c050174;
case 0x0c050176u: goto P_0c050176;
case 0x0c050178u: goto P_0c050178;
case 0x0c05017au: goto P_0c05017a;
case 0x0c05017cu: goto P_0c05017c;
case 0x0c05017eu: goto P_0c05017e;
case 0x0c050180u: goto P_0c050180;
case 0x0c050182u: goto P_0c050182;
case 0x0c050184u: goto P_0c050184;
case 0x0c050186u: goto P_0c050186;
case 0x0c050188u: goto P_0c050188;
case 0x0c05018au: goto P_0c05018a;
case 0x0c05018cu: goto P_0c05018c;
case 0x0c05018eu: goto P_0c05018e;
case 0x0c050190u: goto P_0c050190;
case 0x0c050192u: goto P_0c050192;
case 0x0c050194u: goto P_0c050194;
case 0x0c050196u: goto P_0c050196;
case 0x0c050198u: goto P_0c050198;
case 0x0c05019au: goto P_0c05019a;
case 0x0c05019cu: goto P_0c05019c;
case 0x0c05019eu: goto P_0c05019e;
case 0x0c0501a0u: goto P_0c0501a0;
case 0x0c0501a2u: goto P_0c0501a2;
case 0x0c0501a4u: goto P_0c0501a4;
case 0x0c0501a6u: goto P_0c0501a6;
case 0x0c0501a8u: goto P_0c0501a8;
case 0x0c0501aau: goto P_0c0501aa;
case 0x0c0501acu: goto P_0c0501ac;
case 0x0c0501aeu: goto P_0c0501ae;
case 0x0c0501b0u: goto P_0c0501b0;
case 0x0c0501b2u: goto P_0c0501b2;
case 0x0c0501b4u: goto P_0c0501b4;
case 0x0c0501b6u: goto P_0c0501b6;
case 0x0c0501b8u: goto P_0c0501b8;
case 0x0c0501bau: goto P_0c0501ba;
case 0x0c0501bcu: goto P_0c0501bc;
case 0x0c0501beu: goto P_0c0501be;
case 0x0c0501c0u: goto P_0c0501c0;
case 0x0c0501c2u: goto P_0c0501c2;
case 0x0c0501c4u: goto P_0c0501c4;
case 0x0c0501c6u: goto P_0c0501c6;
case 0x0c0501c8u: goto P_0c0501c8;
case 0x0c0501cau: goto P_0c0501ca;
case 0x0c0501ccu: goto P_0c0501cc;
case 0x0c0501ceu: goto P_0c0501ce;
case 0x0c0501d0u: goto P_0c0501d0;
case 0x0c0501d2u: goto P_0c0501d2;
case 0x0c0501d4u: goto P_0c0501d4;
case 0x0c0501d6u: goto P_0c0501d6;
case 0x0c0501d8u: goto P_0c0501d8;
case 0x0c0501dau: goto P_0c0501da;
case 0x0c0501dcu: goto P_0c0501dc;
case 0x0c0501deu: goto P_0c0501de;
case 0x0c0501e0u: goto P_0c0501e0;
case 0x0c0501e2u: goto P_0c0501e2;
case 0x0c0501e4u: goto P_0c0501e4;
case 0x0c0501e6u: goto P_0c0501e6;
case 0x0c0501e8u: goto P_0c0501e8;
case 0x0c0501f4u: goto P_0c0501f4;
case 0x0c0501f6u: goto P_0c0501f6;
case 0x0c0501f8u: goto P_0c0501f8;
case 0x0c0501fau: goto P_0c0501fa;
case 0x0c0501fcu: goto P_0c0501fc;
case 0x0c0501feu: goto P_0c0501fe;
case 0x0c050200u: goto P_0c050200;
case 0x0c050202u: goto P_0c050202;
case 0x0c050204u: goto P_0c050204;
case 0x0c050206u: goto P_0c050206;
case 0x0c050208u: goto P_0c050208;
case 0x0c05020au: goto P_0c05020a;
case 0x0c05020cu: goto P_0c05020c;
case 0x0c05020eu: goto P_0c05020e;
case 0x0c050210u: goto P_0c050210;
case 0x0c050212u: goto P_0c050212;
case 0x0c050214u: goto P_0c050214;
case 0x0c050216u: goto P_0c050216;
case 0x0c050218u: goto P_0c050218;
case 0x0c05021au: goto P_0c05021a;
case 0x0c05021cu: goto P_0c05021c;
case 0x0c05021eu: goto P_0c05021e;
case 0x0c050220u: goto P_0c050220;
case 0x0c050222u: goto P_0c050222;
case 0x0c050224u: goto P_0c050224;
case 0x0c050226u: goto P_0c050226;
case 0x0c050228u: goto P_0c050228;
case 0x0c05022au: goto P_0c05022a;
case 0x0c05022cu: goto P_0c05022c;
case 0x0c05022eu: goto P_0c05022e;
case 0x0c050230u: goto P_0c050230;
case 0x0c050232u: goto P_0c050232;
case 0x0c050234u: goto P_0c050234;
case 0x0c050236u: goto P_0c050236;
case 0x0c050238u: goto P_0c050238;
case 0x0c05023au: goto P_0c05023a;
case 0x0c05023cu: goto P_0c05023c;
case 0x0c05023eu: goto P_0c05023e;
case 0x0c050240u: goto P_0c050240;
case 0x0c050242u: goto P_0c050242;
case 0x0c050244u: goto P_0c050244;
case 0x0c050246u: goto P_0c050246;
case 0x0c050248u: goto P_0c050248;
case 0x0c05024au: goto P_0c05024a;
case 0x0c05024cu: goto P_0c05024c;
case 0x0c05024eu: goto P_0c05024e;
case 0x0c0512dcu: goto P_0c0512dc;
case 0x0c0512deu: goto P_0c0512de;
case 0x0c0512e0u: goto P_0c0512e0;
case 0x0c0514f0u: goto P_0c0514f0;
case 0x0c0514f2u: goto P_0c0514f2;
case 0x0c0514f4u: goto P_0c0514f4;
case 0x0c0514f6u: goto P_0c0514f6;
case 0x0c0514f8u: goto P_0c0514f8;
case 0x0c05174cu: goto P_0c05174c;
case 0x0c05174eu: goto P_0c05174e;
case 0x0c051750u: goto P_0c051750;
case 0x0c051752u: goto P_0c051752;
case 0x0c051754u: goto P_0c051754;
case 0x0c051756u: goto P_0c051756;
case 0x0c051758u: goto P_0c051758;
case 0x0c05175au: goto P_0c05175a;
case 0x0c05175cu: goto P_0c05175c;
case 0x0c05175eu: goto P_0c05175e;
case 0x0c051760u: goto P_0c051760;
case 0x0c051762u: goto P_0c051762;
case 0x0c051764u: goto P_0c051764;
case 0x0c051766u: goto P_0c051766;
case 0x0c051768u: goto P_0c051768;
case 0x0c05176au: goto P_0c05176a;
case 0x0c051770u: goto P_0c051770;
case 0x0c051772u: goto P_0c051772;
case 0x0c051774u: goto P_0c051774;
case 0x0c051776u: goto P_0c051776;
case 0x0c051778u: goto P_0c051778;
case 0x0c05177au: goto P_0c05177a;
case 0x0c05177cu: goto P_0c05177c;
case 0x0c05177eu: goto P_0c05177e;
case 0x0c051780u: goto P_0c051780;
case 0x0c051782u: goto P_0c051782;
case 0x0c051784u: goto P_0c051784;
case 0x0c051786u: goto P_0c051786;
case 0x0c051788u: goto P_0c051788;
case 0x0c05178au: goto P_0c05178a;
case 0x0c05178cu: goto P_0c05178c;
case 0x0c05178eu: goto P_0c05178e;
case 0x0c051790u: goto P_0c051790;
case 0x0c051792u: goto P_0c051792;
case 0x0c051794u: goto P_0c051794;
case 0x0c051796u: goto P_0c051796;
case 0x0c051798u: goto P_0c051798;
case 0x0c05179au: goto P_0c05179a;
case 0x0c0517b8u: goto P_0c0517b8;
case 0x0c0517bau: goto P_0c0517ba;
case 0x0c0517bcu: goto P_0c0517bc;
case 0x0c0517beu: goto P_0c0517be;
case 0x0c0517c0u: goto P_0c0517c0;
case 0x0c0517c2u: goto P_0c0517c2;
case 0x0c0517c4u: goto P_0c0517c4;
case 0x0c0517c6u: goto P_0c0517c6;
case 0x0c0517c8u: goto P_0c0517c8;
case 0x0c0517cau: goto P_0c0517ca;
case 0x0c0517ccu: goto P_0c0517cc;
case 0x0c0517ceu: goto P_0c0517ce;
case 0x0c0517d0u: goto P_0c0517d0;
case 0x0c0517d2u: goto P_0c0517d2;
case 0x0c0517d4u: goto P_0c0517d4;
case 0x0c0517d6u: goto P_0c0517d6;
case 0x0c0517d8u: goto P_0c0517d8;
case 0x0c0517dau: goto P_0c0517da;
case 0x0c0517dcu: goto P_0c0517dc;
case 0x0c0517deu: goto P_0c0517de;
case 0x0c0517e0u: goto P_0c0517e0;
case 0x0c0517e2u: goto P_0c0517e2;
case 0x0c0517e4u: goto P_0c0517e4;
case 0x0c0517e6u: goto P_0c0517e6;
case 0x0c0517e8u: goto P_0c0517e8;
case 0x0c0517eau: goto P_0c0517ea;
case 0x0c0517ecu: goto P_0c0517ec;
case 0x0c0517eeu: goto P_0c0517ee;
case 0x0c0517f0u: goto P_0c0517f0;
case 0x0c0517f2u: goto P_0c0517f2;
case 0x0c0517f4u: goto P_0c0517f4;
case 0x0c0517f6u: goto P_0c0517f6;
case 0x0c0517f8u: goto P_0c0517f8;
case 0x0c05184cu: goto P_0c05184c;
case 0x0c05184eu: goto P_0c05184e;
case 0x0c051850u: goto P_0c051850;
case 0x0c051852u: goto P_0c051852;
case 0x0c051854u: goto P_0c051854;
case 0x0c051856u: goto P_0c051856;
case 0x0c051858u: goto P_0c051858;
case 0x0c05185au: goto P_0c05185a;
case 0x0c05185cu: goto P_0c05185c;
case 0x0c05185eu: goto P_0c05185e;
case 0x0c051860u: goto P_0c051860;
case 0x0c051862u: goto P_0c051862;
case 0x0c051864u: goto P_0c051864;
case 0x0c051866u: goto P_0c051866;
case 0x0c051868u: goto P_0c051868;
case 0x0c05186au: goto P_0c05186a;
case 0x0c05186cu: goto P_0c05186c;
case 0x0c05186eu: goto P_0c05186e;
case 0x0c051870u: goto P_0c051870;
case 0x0c051872u: goto P_0c051872;
case 0x0c051874u: goto P_0c051874;
case 0x0c051876u: goto P_0c051876;
case 0x0c051878u: goto P_0c051878;
case 0x0c05187au: goto P_0c05187a;
case 0x0c05187cu: goto P_0c05187c;
case 0x0c05187eu: goto P_0c05187e;
case 0x0c051880u: goto P_0c051880;
case 0x0c051882u: goto P_0c051882;
case 0x0c051884u: goto P_0c051884;
case 0x0c051886u: goto P_0c051886;
case 0x0c051888u: goto P_0c051888;
case 0x0c05188au: goto P_0c05188a;
case 0x0c05188cu: goto P_0c05188c;
case 0x0c05188eu: goto P_0c05188e;
case 0x0c051890u: goto P_0c051890;
case 0x0c051892u: goto P_0c051892;
case 0x0c051894u: goto P_0c051894;
case 0x0c051896u: goto P_0c051896;
case 0x0c051898u: goto P_0c051898;
case 0x0c05189au: goto P_0c05189a;
case 0x0c05189cu: goto P_0c05189c;
case 0x0c05189eu: goto P_0c05189e;
case 0x0c0518a0u: goto P_0c0518a0;
case 0x0c0518a2u: goto P_0c0518a2;
case 0x0c0518a4u: goto P_0c0518a4;
case 0x0c0518a6u: goto P_0c0518a6;
case 0x0c0518a8u: goto P_0c0518a8;
case 0x0c0518aau: goto P_0c0518aa;
case 0x0c0518acu: goto P_0c0518ac;
case 0x0c0518aeu: goto P_0c0518ae;
case 0x0c0518b0u: goto P_0c0518b0;
case 0x0c0518b2u: goto P_0c0518b2;
case 0x0c0518b4u: goto P_0c0518b4;
case 0x0c0518b6u: goto P_0c0518b6;
case 0x0c0518b8u: goto P_0c0518b8;
case 0x0c0518bau: goto P_0c0518ba;
case 0x0c0518bcu: goto P_0c0518bc;
case 0x0c0518beu: goto P_0c0518be;
case 0x0c0518c0u: goto P_0c0518c0;
case 0x0c0518c2u: goto P_0c0518c2;
case 0x0c0518c4u: goto P_0c0518c4;
case 0x0c0518c6u: goto P_0c0518c6;
case 0x0c0518c8u: goto P_0c0518c8;
case 0x0c0518cau: goto P_0c0518ca;
case 0x0c0518ccu: goto P_0c0518cc;
case 0x0c0518ceu: goto P_0c0518ce;
case 0x0c0518d0u: goto P_0c0518d0;
case 0x0c0518d2u: goto P_0c0518d2;
case 0x0c0518d4u: goto P_0c0518d4;
case 0x0c0518d6u: goto P_0c0518d6;
case 0x0c0518d8u: goto P_0c0518d8;
case 0x0c0518dau: goto P_0c0518da;
case 0x0c0518dcu: goto P_0c0518dc;
case 0x0c0518deu: goto P_0c0518de;
case 0x0c0518e0u: goto P_0c0518e0;
case 0x0c0518e2u: goto P_0c0518e2;
case 0x0c0518e4u: goto P_0c0518e4;
case 0x0c0518e6u: goto P_0c0518e6;
case 0x0c0518e8u: goto P_0c0518e8;
case 0x0c0518eau: goto P_0c0518ea;
case 0x0c0518ecu: goto P_0c0518ec;
case 0x0c0518eeu: goto P_0c0518ee;
case 0x0c0518f0u: goto P_0c0518f0;
case 0x0c0518f2u: goto P_0c0518f2;
case 0x0c0518f4u: goto P_0c0518f4;
case 0x0c0518f6u: goto P_0c0518f6;
case 0x0c0518f8u: goto P_0c0518f8;
case 0x0c0518fau: goto P_0c0518fa;
case 0x0c0518fcu: goto P_0c0518fc;
case 0x0c051e4cu: goto P_0c051e4c;
case 0x0c051e4eu: goto P_0c051e4e;
case 0x0c051e50u: goto P_0c051e50;
case 0x0c051e52u: goto P_0c051e52;
case 0x0c051e54u: goto P_0c051e54;
case 0x0c051e56u: goto P_0c051e56;
case 0x0c051e58u: goto P_0c051e58;
case 0x0c051e5au: goto P_0c051e5a;
case 0x0c051e5cu: goto P_0c051e5c;
case 0x0c051e5eu: goto P_0c051e5e;
case 0x0c051e60u: goto P_0c051e60;
case 0x0c051e62u: goto P_0c051e62;
case 0x0c051e64u: goto P_0c051e64;
case 0x0c051e66u: goto P_0c051e66;
case 0x0c051e68u: goto P_0c051e68;
case 0x0c051e70u: goto P_0c051e70;
case 0x0c051e72u: goto P_0c051e72;
case 0x0c051e74u: goto P_0c051e74;
case 0x0c051e76u: goto P_0c051e76;
case 0x0c051e78u: goto P_0c051e78;
case 0x0c051e7au: goto P_0c051e7a;
case 0x0c051e7cu: goto P_0c051e7c;
case 0x0c051e7eu: goto P_0c051e7e;
case 0x0c051e80u: goto P_0c051e80;
case 0x0c051e82u: goto P_0c051e82;
case 0x0c051e84u: goto P_0c051e84;
case 0x0c051e86u: goto P_0c051e86;
case 0x0c051e88u: goto P_0c051e88;
case 0x0c051e8au: goto P_0c051e8a;
case 0x0c051e8cu: goto P_0c051e8c;
case 0x0c051e8eu: goto P_0c051e8e;
case 0x0c051e90u: goto P_0c051e90;
case 0x0c051e92u: goto P_0c051e92;
case 0x0c051e94u: goto P_0c051e94;
case 0x0c051e96u: goto P_0c051e96;
case 0x0c051e98u: goto P_0c051e98;
case 0x0c051ecau: goto P_0c051eca;
case 0x0c051eccu: goto P_0c051ecc;
case 0x0c051eceu: goto P_0c051ece;
case 0x0c051ed0u: goto P_0c051ed0;
case 0x0c051ed2u: goto P_0c051ed2;
case 0x0c051ed4u: goto P_0c051ed4;
case 0x0c051ed6u: goto P_0c051ed6;
case 0x0c051ed8u: goto P_0c051ed8;
case 0x0c051edau: goto P_0c051eda;
case 0x0c051edcu: goto P_0c051edc;
case 0x0c051edeu: goto P_0c051ede;
case 0x0c051ee0u: goto P_0c051ee0;
case 0x0c051ee2u: goto P_0c051ee2;
case 0x0c051ee4u: goto P_0c051ee4;
case 0x0c051ee6u: goto P_0c051ee6;
case 0x0c051ee8u: goto P_0c051ee8;
case 0x0c051eeau: goto P_0c051eea;
case 0x0c051eecu: goto P_0c051eec;
case 0x0c051eeeu: goto P_0c051eee;
case 0x0c051ef0u: goto P_0c051ef0;
case 0x0c051ef2u: goto P_0c051ef2;
case 0x0c051ef4u: goto P_0c051ef4;
case 0x0c051ef6u: goto P_0c051ef6;
case 0x0c051ef8u: goto P_0c051ef8;
case 0x0c051efau: goto P_0c051efa;
case 0x0c051efcu: goto P_0c051efc;
case 0x0c051efeu: goto P_0c051efe;
case 0x0c051f00u: goto P_0c051f00;
case 0x0c051f02u: goto P_0c051f02;
case 0x0c051f04u: goto P_0c051f04;
case 0x0c051f06u: goto P_0c051f06;
case 0x0c051f08u: goto P_0c051f08;
case 0x0c051f0au: goto P_0c051f0a;
case 0x0c051f0cu: goto P_0c051f0c;
case 0x0c051f0eu: goto P_0c051f0e;
case 0x0c051f10u: goto P_0c051f10;
case 0x0c051f12u: goto P_0c051f12;
case 0x0c051f14u: goto P_0c051f14;
case 0x0c051f16u: goto P_0c051f16;
case 0x0c051f18u: goto P_0c051f18;
case 0x0c051f1au: goto P_0c051f1a;
case 0x0c051f1cu: goto P_0c051f1c;
case 0x0c051f1eu: goto P_0c051f1e;
case 0x0c051f20u: goto P_0c051f20;
case 0x0c051f22u: goto P_0c051f22;
case 0x0c051f24u: goto P_0c051f24;
case 0x0c051f26u: goto P_0c051f26;
case 0x0c051f28u: goto P_0c051f28;
case 0x0c051f2au: goto P_0c051f2a;
case 0x0c051f2cu: goto P_0c051f2c;
case 0x0c051f2eu: goto P_0c051f2e;
case 0x0c051f30u: goto P_0c051f30;
case 0x0c051f32u: goto P_0c051f32;
case 0x0c0524acu: goto P_0c0524ac;
case 0x0c0524aeu: goto P_0c0524ae;
case 0x0c0524b0u: goto P_0c0524b0;
case 0x0c0524b2u: goto P_0c0524b2;
case 0x0c0524b4u: goto P_0c0524b4;
case 0x0c0524b6u: goto P_0c0524b6;
case 0x0c0524b8u: goto P_0c0524b8;
case 0x0c0524bau: goto P_0c0524ba;
case 0x0c0524bcu: goto P_0c0524bc;
case 0x0c0524beu: goto P_0c0524be;
case 0x0c0524c0u: goto P_0c0524c0;
case 0x0c0524c2u: goto P_0c0524c2;
case 0x0c0524c4u: goto P_0c0524c4;
case 0x0c0524c6u: goto P_0c0524c6;
case 0x0c0524c8u: goto P_0c0524c8;
case 0x0c0524cau: goto P_0c0524ca;
case 0x0c0524ccu: goto P_0c0524cc;
case 0x0c0524ceu: goto P_0c0524ce;
case 0x0c0524d0u: goto P_0c0524d0;
case 0x0c0524d2u: goto P_0c0524d2;
case 0x0c0524d4u: goto P_0c0524d4;
case 0x0c0524dcu: goto P_0c0524dc;
case 0x0c0524deu: goto P_0c0524de;
case 0x0c0524e0u: goto P_0c0524e0;
case 0x0c0524e2u: goto P_0c0524e2;
case 0x0c0524e4u: goto P_0c0524e4;
case 0x0c0524e6u: goto P_0c0524e6;
case 0x0c0524e8u: goto P_0c0524e8;
case 0x0c0524eau: goto P_0c0524ea;
case 0x0c0524ecu: goto P_0c0524ec;
case 0x0c0524eeu: goto P_0c0524ee;
case 0x0c0524f0u: goto P_0c0524f0;
case 0x0c0524f2u: goto P_0c0524f2;
case 0x0c0524f4u: goto P_0c0524f4;
case 0x0c0524f6u: goto P_0c0524f6;
case 0x0c0524f8u: goto P_0c0524f8;
case 0x0c0524fau: goto P_0c0524fa;
case 0x0c0524fcu: goto P_0c0524fc;
case 0x0c0524feu: goto P_0c0524fe;
case 0x0c052500u: goto P_0c052500;
case 0x0c052502u: goto P_0c052502;
case 0x0c052504u: goto P_0c052504;
case 0x0c052506u: goto P_0c052506;
case 0x0c052508u: goto P_0c052508;
case 0x0c05250au: goto P_0c05250a;
case 0x0c05250cu: goto P_0c05250c;
case 0x0c05250eu: goto P_0c05250e;
case 0x0c052510u: goto P_0c052510;
case 0x0c052540u: goto P_0c052540;
case 0x0c052542u: goto P_0c052542;
case 0x0c052544u: goto P_0c052544;
case 0x0c052546u: goto P_0c052546;
case 0x0c052548u: goto P_0c052548;
case 0x0c05254au: goto P_0c05254a;
case 0x0c05254cu: goto P_0c05254c;
case 0x0c05254eu: goto P_0c05254e;
case 0x0c052550u: goto P_0c052550;
case 0x0c052552u: goto P_0c052552;
case 0x0c052554u: goto P_0c052554;
case 0x0c052556u: goto P_0c052556;
case 0x0c052558u: goto P_0c052558;
case 0x0c05255au: goto P_0c05255a;
case 0x0c05255cu: goto P_0c05255c;
case 0x0c05255eu: goto P_0c05255e;
case 0x0c052560u: goto P_0c052560;
case 0x0c052562u: goto P_0c052562;
case 0x0c052564u: goto P_0c052564;
case 0x0c052566u: goto P_0c052566;
case 0x0c052568u: goto P_0c052568;
case 0x0c05256au: goto P_0c05256a;
case 0x0c05256cu: goto P_0c05256c;
case 0x0c05256eu: goto P_0c05256e;
case 0x0c052570u: goto P_0c052570;
case 0x0c052572u: goto P_0c052572;
case 0x0c052574u: goto P_0c052574;
case 0x0c052576u: goto P_0c052576;
case 0x0c052578u: goto P_0c052578;
case 0x0c05257au: goto P_0c05257a;
case 0x0c05257cu: goto P_0c05257c;
case 0x0c05257eu: goto P_0c05257e;
case 0x0c052580u: goto P_0c052580;
case 0x0c052582u: goto P_0c052582;
case 0x0c052584u: goto P_0c052584;
case 0x0c052586u: goto P_0c052586;
case 0x0c052588u: goto P_0c052588;
case 0x0c05258au: goto P_0c05258a;
case 0x0c05258cu: goto P_0c05258c;
case 0x0c05258eu: goto P_0c05258e;
case 0x0c052590u: goto P_0c052590;
case 0x0c052592u: goto P_0c052592;
case 0x0c052594u: goto P_0c052594;
case 0x0c052596u: goto P_0c052596;
case 0x0c052598u: goto P_0c052598;
case 0x0c05259au: goto P_0c05259a;
case 0x0c05259cu: goto P_0c05259c;
case 0x0c05259eu: goto P_0c05259e;
case 0x0c0525a0u: goto P_0c0525a0;
case 0x0c052b3cu: goto P_0c052b3c;
case 0x0c052b3eu: goto P_0c052b3e;
case 0x0c052b40u: goto P_0c052b40;
case 0x0c052b42u: goto P_0c052b42;
case 0x0c052b44u: goto P_0c052b44;
case 0x0c052b46u: goto P_0c052b46;
case 0x0c052b48u: goto P_0c052b48;
case 0x0c052b4au: goto P_0c052b4a;
case 0x0c052b4cu: goto P_0c052b4c;
case 0x0c052b4eu: goto P_0c052b4e;
case 0x0c052b50u: goto P_0c052b50;
case 0x0c052b52u: goto P_0c052b52;
case 0x0c052b54u: goto P_0c052b54;
case 0x0c052b56u: goto P_0c052b56;
case 0x0c052b58u: goto P_0c052b58;
case 0x0c052b60u: goto P_0c052b60;
case 0x0c052b62u: goto P_0c052b62;
case 0x0c052b64u: goto P_0c052b64;
case 0x0c052b66u: goto P_0c052b66;
case 0x0c052b68u: goto P_0c052b68;
case 0x0c052b6au: goto P_0c052b6a;
case 0x0c052b6cu: goto P_0c052b6c;
case 0x0c052b6eu: goto P_0c052b6e;
case 0x0c052b70u: goto P_0c052b70;
case 0x0c052b72u: goto P_0c052b72;
case 0x0c052b74u: goto P_0c052b74;
case 0x0c052b76u: goto P_0c052b76;
case 0x0c052b78u: goto P_0c052b78;
case 0x0c052b7au: goto P_0c052b7a;
case 0x0c052b7cu: goto P_0c052b7c;
case 0x0c052b7eu: goto P_0c052b7e;
case 0x0c052b80u: goto P_0c052b80;
case 0x0c052b82u: goto P_0c052b82;
case 0x0c052b84u: goto P_0c052b84;
case 0x0c052b86u: goto P_0c052b86;
case 0x0c052b88u: goto P_0c052b88;
case 0x0c052b8au: goto P_0c052b8a;
case 0x0c052b8cu: goto P_0c052b8c;
case 0x0c052b8eu: goto P_0c052b8e;
case 0x0c052bbau: goto P_0c052bba;
case 0x0c052bbcu: goto P_0c052bbc;
case 0x0c052bbeu: goto P_0c052bbe;
case 0x0c052bc0u: goto P_0c052bc0;
case 0x0c052bc2u: goto P_0c052bc2;
case 0x0c052bc4u: goto P_0c052bc4;
case 0x0c052bc6u: goto P_0c052bc6;
case 0x0c052bc8u: goto P_0c052bc8;
case 0x0c052bcau: goto P_0c052bca;
case 0x0c052bccu: goto P_0c052bcc;
case 0x0c052bceu: goto P_0c052bce;
case 0x0c052bd0u: goto P_0c052bd0;
case 0x0c052bd2u: goto P_0c052bd2;
case 0x0c052bd4u: goto P_0c052bd4;
case 0x0c052bd6u: goto P_0c052bd6;
case 0x0c052bd8u: goto P_0c052bd8;
case 0x0c052bdau: goto P_0c052bda;
case 0x0c052bdcu: goto P_0c052bdc;
case 0x0c052bdeu: goto P_0c052bde;
case 0x0c052be0u: goto P_0c052be0;
case 0x0c052be2u: goto P_0c052be2;
case 0x0c052be4u: goto P_0c052be4;
case 0x0c052be6u: goto P_0c052be6;
case 0x0c052be8u: goto P_0c052be8;
case 0x0c052beau: goto P_0c052bea;
case 0x0c052becu: goto P_0c052bec;
case 0x0c052beeu: goto P_0c052bee;
case 0x0c052bf0u: goto P_0c052bf0;
case 0x0c052bf2u: goto P_0c052bf2;
case 0x0c052bf4u: goto P_0c052bf4;
case 0x0c052bf6u: goto P_0c052bf6;
case 0x0c052bf8u: goto P_0c052bf8;
case 0x0c052bfau: goto P_0c052bfa;
case 0x0c052bfcu: goto P_0c052bfc;
case 0x0c052bfeu: goto P_0c052bfe;
case 0x0c052c00u: goto P_0c052c00;
case 0x0c052c02u: goto P_0c052c02;
case 0x0c052c04u: goto P_0c052c04;
case 0x0c052c06u: goto P_0c052c06;
case 0x0c052c08u: goto P_0c052c08;
case 0x0c052c0au: goto P_0c052c0a;
case 0x0c052c0cu: goto P_0c052c0c;
case 0x0c052c0eu: goto P_0c052c0e;
case 0x0c052c10u: goto P_0c052c10;
case 0x0c052c12u: goto P_0c052c12;
case 0x0c052c14u: goto P_0c052c14;
case 0x0c052c16u: goto P_0c052c16;
case 0x0c052c18u: goto P_0c052c18;
case 0x0c052c1au: goto P_0c052c1a;
case 0x0c052e54u: goto P_0c052e54;
case 0x0c052e56u: goto P_0c052e56;
case 0x0c052e58u: goto P_0c052e58;
case 0x0c052e5au: goto P_0c052e5a;
case 0x0c052e5cu: goto P_0c052e5c;
case 0x0c052e5eu: goto P_0c052e5e;
case 0x0c052e60u: goto P_0c052e60;
case 0x0c052e62u: goto P_0c052e62;
case 0x0c052e64u: goto P_0c052e64;
case 0x0c052e66u: goto P_0c052e66;
case 0x0c052e68u: goto P_0c052e68;
case 0x0c052e6au: goto P_0c052e6a;
case 0x0c052e6cu: goto P_0c052e6c;
case 0x0c052e6eu: goto P_0c052e6e;
case 0x0c052e70u: goto P_0c052e70;
case 0x0c052e72u: goto P_0c052e72;
case 0x0c052e74u: goto P_0c052e74;
case 0x0c052e7cu: goto P_0c052e7c;
case 0x0c052e7eu: goto P_0c052e7e;
case 0x0c052e80u: goto P_0c052e80;
case 0x0c052e82u: goto P_0c052e82;
case 0x0c052e84u: goto P_0c052e84;
case 0x0c052e86u: goto P_0c052e86;
case 0x0c052e88u: goto P_0c052e88;
case 0x0c052e8au: goto P_0c052e8a;
case 0x0c052e8cu: goto P_0c052e8c;
case 0x0c052e8eu: goto P_0c052e8e;
case 0x0c052e90u: goto P_0c052e90;
case 0x0c052e92u: goto P_0c052e92;
case 0x0c052e94u: goto P_0c052e94;
case 0x0c052e96u: goto P_0c052e96;
case 0x0c052e98u: goto P_0c052e98;
case 0x0c052e9au: goto P_0c052e9a;
case 0x0c052e9cu: goto P_0c052e9c;
case 0x0c052e9eu: goto P_0c052e9e;
case 0x0c052ea0u: goto P_0c052ea0;
case 0x0c052ea2u: goto P_0c052ea2;
case 0x0c052ea4u: goto P_0c052ea4;
case 0x0c052ea6u: goto P_0c052ea6;
case 0x0c052ea8u: goto P_0c052ea8;
case 0x0c052eaau: goto P_0c052eaa;
case 0x0c052eacu: goto P_0c052eac;
case 0x0c052ecau: goto P_0c052eca;
case 0x0c052eccu: goto P_0c052ecc;
case 0x0c052eceu: goto P_0c052ece;
case 0x0c052ed0u: goto P_0c052ed0;
case 0x0c052ed2u: goto P_0c052ed2;
case 0x0c052ed4u: goto P_0c052ed4;
case 0x0c052ed6u: goto P_0c052ed6;
case 0x0c052ed8u: goto P_0c052ed8;
case 0x0c052edau: goto P_0c052eda;
case 0x0c052edcu: goto P_0c052edc;
case 0x0c052edeu: goto P_0c052ede;
case 0x0c052ee0u: goto P_0c052ee0;
case 0x0c052ee2u: goto P_0c052ee2;
case 0x0c052ee4u: goto P_0c052ee4;
case 0x0c052ee6u: goto P_0c052ee6;
case 0x0c052ee8u: goto P_0c052ee8;
case 0x0c052eeau: goto P_0c052eea;
case 0x0c052eecu: goto P_0c052eec;
case 0x0c052eeeu: goto P_0c052eee;
case 0x0c052ef0u: goto P_0c052ef0;
case 0x0c052ef2u: goto P_0c052ef2;
case 0x0c052ef4u: goto P_0c052ef4;
case 0x0c052ef6u: goto P_0c052ef6;
case 0x0c052ef8u: goto P_0c052ef8;
case 0x0c052efau: goto P_0c052efa;
case 0x0c052efcu: goto P_0c052efc;
case 0x0c052efeu: goto P_0c052efe;
case 0x0c052f00u: goto P_0c052f00;
case 0x0c052f02u: goto P_0c052f02;
case 0x0c052f04u: goto P_0c052f04;
case 0x0c052f06u: goto P_0c052f06;
case 0x0c052f08u: goto P_0c052f08;
case 0x0c052f0au: goto P_0c052f0a;
case 0x0c053ed4u: goto P_0c053ed4;
case 0x0c053ed6u: goto P_0c053ed6;
case 0x0c053ed8u: goto P_0c053ed8;
case 0x0c053edau: goto P_0c053eda;
case 0x0c053edcu: goto P_0c053edc;
case 0x0c053edeu: goto P_0c053ede;
case 0x0c053ee0u: goto P_0c053ee0;
case 0x0c053ee2u: goto P_0c053ee2;
case 0x0c053ee4u: goto P_0c053ee4;
case 0x0c053ee6u: goto P_0c053ee6;
case 0x0c053ee8u: goto P_0c053ee8;
case 0x0c053eeau: goto P_0c053eea;
case 0x0c053eecu: goto P_0c053eec;
case 0x0c053eeeu: goto P_0c053eee;
case 0x0c053ef0u: goto P_0c053ef0;
case 0x0c053ef2u: goto P_0c053ef2;
case 0x0c053ef4u: goto P_0c053ef4;
case 0x0c053ef6u: goto P_0c053ef6;
case 0x0c053ef8u: goto P_0c053ef8;
case 0x0c053efau: goto P_0c053efa;
case 0x0c053efcu: goto P_0c053efc;
case 0x0c053efeu: goto P_0c053efe;
case 0x0c053f00u: goto P_0c053f00;
case 0x0c053f02u: goto P_0c053f02;
case 0x0c053f04u: goto P_0c053f04;
case 0x0c053f06u: goto P_0c053f06;
case 0x0c053f08u: goto P_0c053f08;
case 0x0c053f0au: goto P_0c053f0a;
case 0x0c053f0cu: goto P_0c053f0c;
case 0x0c053f0eu: goto P_0c053f0e;
case 0x0c053f10u: goto P_0c053f10;
case 0x0c053f12u: goto P_0c053f12;
case 0x0c053f14u: goto P_0c053f14;
case 0x0c053f16u: goto P_0c053f16;
case 0x0c053f18u: goto P_0c053f18;
case 0x0c053f1au: goto P_0c053f1a;
case 0x0c053f1cu: goto P_0c053f1c;
case 0x0c053f1eu: goto P_0c053f1e;
case 0x0c053f20u: goto P_0c053f20;
case 0x0c053f22u: goto P_0c053f22;
case 0x0c053f24u: goto P_0c053f24;
case 0x0c053f26u: goto P_0c053f26;
case 0x0c053f28u: goto P_0c053f28;
case 0x0c053f2au: goto P_0c053f2a;
case 0x0c053f2cu: goto P_0c053f2c;
case 0x0c053f2eu: goto P_0c053f2e;
case 0x0c053f30u: goto P_0c053f30;
case 0x0c053f32u: goto P_0c053f32;
case 0x0c053f34u: goto P_0c053f34;
case 0x0c05480cu: goto P_0c05480c;
case 0x0c05480eu: goto P_0c05480e;
case 0x0c054810u: goto P_0c054810;
case 0x0c054812u: goto P_0c054812;
case 0x0c054814u: goto P_0c054814;
case 0x0c054816u: goto P_0c054816;
case 0x0c054818u: goto P_0c054818;
case 0x0c05481au: goto P_0c05481a;
case 0x0c05481cu: goto P_0c05481c;
case 0x0c05481eu: goto P_0c05481e;
case 0x0c054820u: goto P_0c054820;
case 0x0c054822u: goto P_0c054822;
case 0x0c054824u: goto P_0c054824;
case 0x0c054826u: goto P_0c054826;
case 0x0c054828u: goto P_0c054828;
case 0x0c05482au: goto P_0c05482a;
case 0x0c05482cu: goto P_0c05482c;
case 0x0c05482eu: goto P_0c05482e;
case 0x0c054830u: goto P_0c054830;
case 0x0c054832u: goto P_0c054832;
case 0x0c054834u: goto P_0c054834;
case 0x0c054836u: goto P_0c054836;
case 0x0c054838u: goto P_0c054838;
case 0x0c05483au: goto P_0c05483a;
case 0x0c05483cu: goto P_0c05483c;
case 0x0c054848u: goto P_0c054848;
case 0x0c05484au: goto P_0c05484a;
case 0x0c05484cu: goto P_0c05484c;
case 0x0c05484eu: goto P_0c05484e;
case 0x0c054850u: goto P_0c054850;
case 0x0c054852u: goto P_0c054852;
case 0x0c054854u: goto P_0c054854;
case 0x0c054856u: goto P_0c054856;
case 0x0c054858u: goto P_0c054858;
case 0x0c05485au: goto P_0c05485a;
case 0x0c05485cu: goto P_0c05485c;
case 0x0c05485eu: goto P_0c05485e;
case 0x0c054860u: goto P_0c054860;
case 0x0c054862u: goto P_0c054862;
case 0x0c054864u: goto P_0c054864;
case 0x0c054866u: goto P_0c054866;
case 0x0c054868u: goto P_0c054868;
case 0x0c05486au: goto P_0c05486a;
case 0x0c05486cu: goto P_0c05486c;
case 0x0c05486eu: goto P_0c05486e;
case 0x0c054870u: goto P_0c054870;
case 0x0c054872u: goto P_0c054872;
case 0x0c054874u: goto P_0c054874;
case 0x0c054876u: goto P_0c054876;
case 0x0c054878u: goto P_0c054878;
case 0x0c05487au: goto P_0c05487a;
case 0x0c05487cu: goto P_0c05487c;
case 0x0c05487eu: goto P_0c05487e;
case 0x0c054880u: goto P_0c054880;
case 0x0c054882u: goto P_0c054882;
case 0x0c054884u: goto P_0c054884;
case 0x0c054886u: goto P_0c054886;
case 0x0c054888u: goto P_0c054888;
case 0x0c05488au: goto P_0c05488a;
case 0x0c05488cu: goto P_0c05488c;
case 0x0c05488eu: goto P_0c05488e;
case 0x0c054890u: goto P_0c054890;
case 0x0c054892u: goto P_0c054892;
case 0x0c054894u: goto P_0c054894;
case 0x0c054c1cu: goto P_0c054c1c;
case 0x0c054c1eu: goto P_0c054c1e;
case 0x0c054c20u: goto P_0c054c20;
case 0x0c054c22u: goto P_0c054c22;
case 0x0c054c24u: goto P_0c054c24;
case 0x0c054c26u: goto P_0c054c26;
case 0x0c054c28u: goto P_0c054c28;
case 0x0c054c2au: goto P_0c054c2a;
case 0x0c054c2cu: goto P_0c054c2c;
case 0x0c054c2eu: goto P_0c054c2e;
case 0x0c054c30u: goto P_0c054c30;
case 0x0c054c32u: goto P_0c054c32;
case 0x0c054c34u: goto P_0c054c34;
case 0x0c054c36u: goto P_0c054c36;
case 0x0c054c38u: goto P_0c054c38;
case 0x0c054c3au: goto P_0c054c3a;
case 0x0c054c3cu: goto P_0c054c3c;
case 0x0c054c3eu: goto P_0c054c3e;
case 0x0c054c40u: goto P_0c054c40;
case 0x0c054c42u: goto P_0c054c42;
case 0x0c054c44u: goto P_0c054c44;
case 0x0c054c46u: goto P_0c054c46;
case 0x0c054c48u: goto P_0c054c48;
case 0x0c054c4au: goto P_0c054c4a;
case 0x0c054c4cu: goto P_0c054c4c;
case 0x0c054c4eu: goto P_0c054c4e;
case 0x0c054c50u: goto P_0c054c50;
case 0x0c054c52u: goto P_0c054c52;
case 0x0c054c54u: goto P_0c054c54;
case 0x0c054c56u: goto P_0c054c56;
case 0x0c054c58u: goto P_0c054c58;
case 0x0c054c5au: goto P_0c054c5a;
case 0x0c054c5cu: goto P_0c054c5c;
case 0x0c054c5eu: goto P_0c054c5e;
case 0x0c054c60u: goto P_0c054c60;
case 0x0c054c62u: goto P_0c054c62;
case 0x0c054c64u: goto P_0c054c64;
case 0x0c054c66u: goto P_0c054c66;
case 0x0c054c68u: goto P_0c054c68;
case 0x0c054c6au: goto P_0c054c6a;
case 0x0c054c6cu: goto P_0c054c6c;
case 0x0c054c6eu: goto P_0c054c6e;
case 0x0c054c70u: goto P_0c054c70;
case 0x0c054c72u: goto P_0c054c72;
case 0x0c054c74u: goto P_0c054c74;
case 0x0c054c76u: goto P_0c054c76;
case 0x0c054c78u: goto P_0c054c78;
case 0x0c054c7au: goto P_0c054c7a;
case 0x0c054c7cu: goto P_0c054c7c;
case 0x0c054c7eu: goto P_0c054c7e;
case 0x0c054c80u: goto P_0c054c80;
case 0x0c054c82u: goto P_0c054c82;
case 0x0c054c84u: goto P_0c054c84;
case 0x0c054c86u: goto P_0c054c86;
case 0x0c054c88u: goto P_0c054c88;
case 0x0c054c8au: goto P_0c054c8a;
case 0x0c054c8cu: goto P_0c054c8c;
case 0x0c054c8eu: goto P_0c054c8e;
case 0x0c054c90u: goto P_0c054c90;
case 0x0c054c92u: goto P_0c054c92;
case 0x0c054c94u: goto P_0c054c94;
case 0x0c054c96u: goto P_0c054c96;
case 0x0c054c98u: goto P_0c054c98;
case 0x0c054c9au: goto P_0c054c9a;
case 0x0c054c9cu: goto P_0c054c9c;
case 0x0c054c9eu: goto P_0c054c9e;
case 0x0c054ca0u: goto P_0c054ca0;
case 0x0c054ca2u: goto P_0c054ca2;
case 0x0c054ca4u: goto P_0c054ca4;
case 0x0c054ca6u: goto P_0c054ca6;
case 0x0c054ca8u: goto P_0c054ca8;
case 0x0c054caau: goto P_0c054caa;
case 0x0c054cacu: goto P_0c054cac;
case 0x0c054caeu: goto P_0c054cae;
case 0x0c054cb0u: goto P_0c054cb0;
case 0x0c054cb2u: goto P_0c054cb2;
case 0x0c054cb4u: goto P_0c054cb4;
case 0x0c054cb6u: goto P_0c054cb6;
case 0x0c054cb8u: goto P_0c054cb8;
case 0x0c054cbau: goto P_0c054cba;
case 0x0c054cbcu: goto P_0c054cbc;
case 0x0c054cbeu: goto P_0c054cbe;
case 0x0c054cc0u: goto P_0c054cc0;
case 0x0c054cc2u: goto P_0c054cc2;
case 0x0c054cc4u: goto P_0c054cc4;
case 0x0c054cc6u: goto P_0c054cc6;
case 0x0c054cc8u: goto P_0c054cc8;
case 0x0c054ce6u: goto P_0c054ce6;
case 0x0c054ce8u: goto P_0c054ce8;
case 0x0c054ceau: goto P_0c054cea;
case 0x0c054cecu: goto P_0c054cec;
case 0x0c054ceeu: goto P_0c054cee;
case 0x0c054cf0u: goto P_0c054cf0;
case 0x0c054cf2u: goto P_0c054cf2;
case 0x0c054cf4u: goto P_0c054cf4;
case 0x0c054cf6u: goto P_0c054cf6;
case 0x0c054cf8u: goto P_0c054cf8;
case 0x0c054cfau: goto P_0c054cfa;
case 0x0c054cfcu: goto P_0c054cfc;
case 0x0c054cfeu: goto P_0c054cfe;
case 0x0c054d00u: goto P_0c054d00;
case 0x0c054d02u: goto P_0c054d02;
case 0x0c054d04u: goto P_0c054d04;
case 0x0c054d06u: goto P_0c054d06;
case 0x0c054d08u: goto P_0c054d08;
case 0x0c054d0au: goto P_0c054d0a;
case 0x0c054d0cu: goto P_0c054d0c;
case 0x0c054d0eu: goto P_0c054d0e;
case 0x0c054d10u: goto P_0c054d10;
case 0x0c054d12u: goto P_0c054d12;
case 0x0c054d14u: goto P_0c054d14;
case 0x0c054d16u: goto P_0c054d16;
case 0x0c054d18u: goto P_0c054d18;
case 0x0c054d1au: goto P_0c054d1a;
case 0x0c054d1cu: goto P_0c054d1c;
case 0x0c054d1eu: goto P_0c054d1e;
case 0x0c054d20u: goto P_0c054d20;
case 0x0c054d22u: goto P_0c054d22;
case 0x0c054d24u: goto P_0c054d24;
case 0x0c054d26u: goto P_0c054d26;
case 0x0c054d28u: goto P_0c054d28;
case 0x0c054d2au: goto P_0c054d2a;
case 0x0c054d2cu: goto P_0c054d2c;
case 0x0c054d2eu: goto P_0c054d2e;
case 0x0c054d30u: goto P_0c054d30;
case 0x0c054d32u: goto P_0c054d32;
case 0x0c054d34u: goto P_0c054d34;
case 0x0c054d36u: goto P_0c054d36;
case 0x0c054d38u: goto P_0c054d38;
case 0x0c054d3au: goto P_0c054d3a;
case 0x0c054d3cu: goto P_0c054d3c;
case 0x0c054d3eu: goto P_0c054d3e;
case 0x0c054d40u: goto P_0c054d40;
case 0x0c054d42u: goto P_0c054d42;
case 0x0c054d44u: goto P_0c054d44;
case 0x0c054d46u: goto P_0c054d46;
case 0x0c054d48u: goto P_0c054d48;
case 0x0c054d4au: goto P_0c054d4a;
case 0x0c054d4cu: goto P_0c054d4c;
case 0x0c054d4eu: goto P_0c054d4e;
case 0x0c054d50u: goto P_0c054d50;
case 0x0c054d52u: goto P_0c054d52;
case 0x0c054d54u: goto P_0c054d54;
case 0x0c054d56u: goto P_0c054d56;
case 0x0c054d58u: goto P_0c054d58;
case 0x0c054d5au: goto P_0c054d5a;
case 0x0c054d5cu: goto P_0c054d5c;
case 0x0c054d5eu: goto P_0c054d5e;
case 0x0c054d60u: goto P_0c054d60;
case 0x0c054d62u: goto P_0c054d62;
case 0x0c054d64u: goto P_0c054d64;
case 0x0c054d66u: goto P_0c054d66;
case 0x0c054d68u: goto P_0c054d68;
case 0x0c054d6au: goto P_0c054d6a;
case 0x0c054d6cu: goto P_0c054d6c;
case 0x0c054d6eu: goto P_0c054d6e;
case 0x0c054d70u: goto P_0c054d70;
case 0x0c054d72u: goto P_0c054d72;
case 0x0c054d74u: goto P_0c054d74;
case 0x0c054d76u: goto P_0c054d76;
case 0x0c054d78u: goto P_0c054d78;
case 0x0c054d7au: goto P_0c054d7a;
case 0x0c054d7cu: goto P_0c054d7c;
case 0x0c054d7eu: goto P_0c054d7e;
case 0x0c054d80u: goto P_0c054d80;
case 0x0c054d82u: goto P_0c054d82;
case 0x0c054d84u: goto P_0c054d84;
case 0x0c054d86u: goto P_0c054d86;
case 0x0c054d88u: goto P_0c054d88;
case 0x0c054d8au: goto P_0c054d8a;
case 0x0c054d8cu: goto P_0c054d8c;
case 0x0c054d8eu: goto P_0c054d8e;
case 0x0c054d90u: goto P_0c054d90;
case 0x0c054d92u: goto P_0c054d92;
case 0x0c054d94u: goto P_0c054d94;
case 0x0c054d96u: goto P_0c054d96;
case 0x0c054d98u: goto P_0c054d98;
case 0x0c054d9au: goto P_0c054d9a;
case 0x0c054d9cu: goto P_0c054d9c;
case 0x0c054d9eu: goto P_0c054d9e;
case 0x0c054da0u: goto P_0c054da0;
case 0x0c054da2u: goto P_0c054da2;
case 0x0c054da4u: goto P_0c054da4;
case 0x0c054da6u: goto P_0c054da6;
case 0x0c054da8u: goto P_0c054da8;
case 0x0c054daau: goto P_0c054daa;
case 0x0c054dacu: goto P_0c054dac;
case 0x0c054daeu: goto P_0c054dae;
case 0x0c054db0u: goto P_0c054db0;
case 0x0c054db2u: goto P_0c054db2;
case 0x0c054db4u: goto P_0c054db4;
case 0x0c054db6u: goto P_0c054db6;
case 0x0c054db8u: goto P_0c054db8;
case 0x0c054dbau: goto P_0c054dba;
case 0x0c054dbcu: goto P_0c054dbc;
case 0x0c054dbeu: goto P_0c054dbe;
case 0x0c054dc0u: goto P_0c054dc0;
case 0x0c054dc2u: goto P_0c054dc2;
case 0x0c054dc4u: goto P_0c054dc4;
case 0x0c054dc6u: goto P_0c054dc6;
case 0x0c054dc8u: goto P_0c054dc8;
case 0x0c054dcau: goto P_0c054dca;
case 0x0c054dccu: goto P_0c054dcc;
case 0x0c054dceu: goto P_0c054dce;
case 0x0c054dd0u: goto P_0c054dd0;
case 0x0c054dd2u: goto P_0c054dd2;
case 0x0c054dd4u: goto P_0c054dd4;
case 0x0c054dd6u: goto P_0c054dd6;
case 0x0c054dd8u: goto P_0c054dd8;
case 0x0c054ddau: goto P_0c054dda;
case 0x0c054ddcu: goto P_0c054ddc;
case 0x0c054ddeu: goto P_0c054dde;
case 0x0c054de0u: goto P_0c054de0;
case 0x0c054de2u: goto P_0c054de2;
case 0x0c054de4u: goto P_0c054de4;
case 0x0c054de6u: goto P_0c054de6;
case 0x0c054de8u: goto P_0c054de8;
case 0x0c054deau: goto P_0c054dea;
case 0x0c054decu: goto P_0c054dec;
case 0x0c054deeu: goto P_0c054dee;
case 0x0c054df0u: goto P_0c054df0;
case 0x0c054df2u: goto P_0c054df2;
case 0x0c054df4u: goto P_0c054df4;
case 0x0c054df6u: goto P_0c054df6;
case 0x0c054df8u: goto P_0c054df8;
case 0x0c054dfau: goto P_0c054dfa;
case 0x0c054dfcu: goto P_0c054dfc;
case 0x0c054dfeu: goto P_0c054dfe;
case 0x0c054e00u: goto P_0c054e00;
case 0x0c054e02u: goto P_0c054e02;
case 0x0c054e04u: goto P_0c054e04;
case 0x0c054e06u: goto P_0c054e06;
case 0x0c054e08u: goto P_0c054e08;
case 0x0c054e0au: goto P_0c054e0a;
case 0x0c054e0cu: goto P_0c054e0c;
case 0x0c054e0eu: goto P_0c054e0e;
case 0x0c054e10u: goto P_0c054e10;
case 0x0c054e12u: goto P_0c054e12;
case 0x0c054e14u: goto P_0c054e14;
case 0x0c054e16u: goto P_0c054e16;
case 0x0c054e18u: goto P_0c054e18;
case 0x0c054e1au: goto P_0c054e1a;
case 0x0c054e1cu: goto P_0c054e1c;
case 0x0c054e1eu: goto P_0c054e1e;
case 0x0c054e20u: goto P_0c054e20;
case 0x0c054e22u: goto P_0c054e22;
case 0x0c054e24u: goto P_0c054e24;
case 0x0c054e26u: goto P_0c054e26;
case 0x0c054e28u: goto P_0c054e28;
case 0x0c054e2au: goto P_0c054e2a;
case 0x0c054e2cu: goto P_0c054e2c;
case 0x0c054e2eu: goto P_0c054e2e;
case 0x0c054e30u: goto P_0c054e30;
case 0x0c054e32u: goto P_0c054e32;
case 0x0c054e34u: goto P_0c054e34;
case 0x0c054e36u: goto P_0c054e36;
case 0x0c054e38u: goto P_0c054e38;
case 0x0c054e3au: goto P_0c054e3a;
case 0x0c054e3cu: goto P_0c054e3c;
case 0x0c054e3eu: goto P_0c054e3e;
case 0x0c054e40u: goto P_0c054e40;
case 0x0c054e42u: goto P_0c054e42;
case 0x0c054e44u: goto P_0c054e44;
case 0x0c054e46u: goto P_0c054e46;
case 0x0c054e48u: goto P_0c054e48;
case 0x0c054e4au: goto P_0c054e4a;
case 0x0c054e4cu: goto P_0c054e4c;
case 0x0c054e4eu: goto P_0c054e4e;
case 0x0c054e50u: goto P_0c054e50;
case 0x0c054e52u: goto P_0c054e52;
case 0x0c054e54u: goto P_0c054e54;
case 0x0c054e56u: goto P_0c054e56;
case 0x0c054e58u: goto P_0c054e58;
case 0x0c054e5au: goto P_0c054e5a;
case 0x0c054e5cu: goto P_0c054e5c;
case 0x0c054e5eu: goto P_0c054e5e;
case 0x0c054e60u: goto P_0c054e60;
case 0x0c054e62u: goto P_0c054e62;
case 0x0c054e64u: goto P_0c054e64;
case 0x0c054e66u: goto P_0c054e66;
case 0x0c054e68u: goto P_0c054e68;
case 0x0c054e6au: goto P_0c054e6a;
case 0x0c054e6cu: goto P_0c054e6c;
case 0x0c054e6eu: goto P_0c054e6e;
case 0x0c054e70u: goto P_0c054e70;
case 0x0c054e72u: goto P_0c054e72;
case 0x0c054e74u: goto P_0c054e74;
case 0x0c054e76u: goto P_0c054e76;
case 0x0c054e78u: goto P_0c054e78;
case 0x0c054e7au: goto P_0c054e7a;
case 0x0c054e7cu: goto P_0c054e7c;
case 0x0c054e7eu: goto P_0c054e7e;
case 0x0c054e80u: goto P_0c054e80;
case 0x0c054e82u: goto P_0c054e82;
case 0x0c054e84u: goto P_0c054e84;
case 0x0c054e86u: goto P_0c054e86;
case 0x0c054e88u: goto P_0c054e88;
case 0x0c054e8au: goto P_0c054e8a;
case 0x0c054e8cu: goto P_0c054e8c;
case 0x0c054e8eu: goto P_0c054e8e;
case 0x0c054e90u: goto P_0c054e90;
case 0x0c054e92u: goto P_0c054e92;
case 0x0c054e94u: goto P_0c054e94;
case 0x0c054e96u: goto P_0c054e96;
case 0x0c054e98u: goto P_0c054e98;
case 0x0c054e9au: goto P_0c054e9a;
case 0x0c054e9cu: goto P_0c054e9c;
case 0x0c054e9eu: goto P_0c054e9e;
case 0x0c054ea0u: goto P_0c054ea0;
case 0x0c054ea2u: goto P_0c054ea2;
case 0x0c054ea4u: goto P_0c054ea4;
case 0x0c054ea6u: goto P_0c054ea6;
case 0x0c054ea8u: goto P_0c054ea8;
case 0x0c054eaau: goto P_0c054eaa;
case 0x0c054eacu: goto P_0c054eac;
case 0x0c054eaeu: goto P_0c054eae;
case 0x0c054eb0u: goto P_0c054eb0;
case 0x0c054eb2u: goto P_0c054eb2;
case 0x0c054eb4u: goto P_0c054eb4;
case 0x0c054eb6u: goto P_0c054eb6;
case 0x0c054eb8u: goto P_0c054eb8;
case 0x0c054ebau: goto P_0c054eba;
case 0x0c054ebcu: goto P_0c054ebc;
case 0x0c054ebeu: goto P_0c054ebe;
case 0x0c054ec0u: goto P_0c054ec0;
case 0x0c054ec2u: goto P_0c054ec2;
case 0x0c054ec4u: goto P_0c054ec4;
case 0x0c054ec6u: goto P_0c054ec6;
case 0x0c054ec8u: goto P_0c054ec8;
case 0x0c054ecau: goto P_0c054eca;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04625c: /* original be8f, guest PC 0x0c04625c */
if(!s->budget--) { s->failed_pc=0x0c04625cu; return 0; }
target=0x0c045f7eu; r[16]=0x0c046260u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046260u) { target=s->pc; goto dispatch; }
goto P_0c046260;
P_0c04625e: /* original 64f1, guest PC 0x0c04625e */
if(!s->budget--) { s->failed_pc=0x0c04625eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c046260;
P_0c046260: /* original 6e03, guest PC 0x0c046260 */
if(!s->budget--) { s->failed_pc=0x0c046260u; return 0; }
r[14]=r[0];
goto P_0c046262;
P_0c046262: /* original 2ee8, guest PC 0x0c046262 */
if(!s->budget--) { s->failed_pc=0x0c046262u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c046264;
P_0c046264: /* original 8b00, guest PC 0x0c046264 */
if(!s->budget--) { s->failed_pc=0x0c046264u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c046268; }
goto P_0c046266;
P_0c046266: /* original c332, guest PC 0x0c046266 */
if(!s->budget--) { s->failed_pc=0x0c046266u; return 0; }
s->failed_pc=0x0c046266u; return 0;
goto P_0c046268;
P_0c046268: /* original 54e1, guest PC 0x0c046268 */
if(!s->budget--) { s->failed_pc=0x0c046268u; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c04626a;
P_0c04626a: /* original 84e2, guest PC 0x0c04626a */
if(!s->budget--) { s->failed_pc=0x0c04626au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c04626c;
P_0c04626c: /* original 2448, guest PC 0x0c04626c */
if(!s->budget--) { s->failed_pc=0x0c04626cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c04626e;
P_0c04626e: /* original 8d04, guest PC 0x0c04626e */
if(!s->budget--) { s->failed_pc=0x0c04626eu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[0],4);
if(cond) { goto P_0c04627a; }
goto P_0c046272;
P_0c046270: /* original 2f02, guest PC 0x0c046270 */
if(!s->budget--) { s->failed_pc=0x0c046270u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c046272;
P_0c046272: /* original d30e, guest PC 0x0c046272 */
if(!s->budget--) { s->failed_pc=0x0c046272u; return 0; }
r[3]=read(ram,0x0c0462acu,4);
goto P_0c046274;
P_0c046274: /* original 6232, guest PC 0x0c046274 */
if(!s->budget--) { s->failed_pc=0x0c046274u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c046276;
P_0c046276: /* original 224b, guest PC 0x0c046276 */
if(!s->budget--) { s->failed_pc=0x0c046276u; return 0; }
r[2]|=r[4];
goto P_0c046278;
P_0c046278: /* original 2322, guest PC 0x0c046278 */
if(!s->budget--) { s->failed_pc=0x0c046278u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c04627a;
P_0c04627a: /* original 55f1, guest PC 0x0c04627a */
if(!s->budget--) { s->failed_pc=0x0c04627au; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c04627c;
P_0c04627c: /* original 56f3, guest PC 0x0c04627c */
if(!s->budget--) { s->failed_pc=0x0c04627cu; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c04627e;
P_0c04627e: /* original 57f2, guest PC 0x0c04627e */
if(!s->budget--) { s->failed_pc=0x0c04627eu; return 0; }
r[7]=read(ram,r[15]+8,4);
goto P_0c046280;
P_0c046280: /* original be8d, guest PC 0x0c046280 */
if(!s->budget--) { s->failed_pc=0x0c046280u; return 0; }
target=0x0c045f9eu; r[16]=0x0c046284u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046284u) { target=s->pc; goto dispatch; }
goto P_0c046284;
P_0c046282: /* original 64f2, guest PC 0x0c046282 */
if(!s->budget--) { s->failed_pc=0x0c046282u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c046284;
P_0c046284: /* original 6403, guest PC 0x0c046284 */
if(!s->budget--) { s->failed_pc=0x0c046284u; return 0; }
r[4]=r[0];
goto P_0c046286;
P_0c046286: /* original 50f4, guest PC 0x0c046286 */
if(!s->budget--) { s->failed_pc=0x0c046286u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c046288;
P_0c046288: /* original 0202, guest PC 0x0c046288 */
if(!s->budget--) { s->failed_pc=0x0c046288u; return 0; }
r[2]=r[17];
goto P_0c04628a;
P_0c04628a: /* original 930c, guest PC 0x0c04628a */
if(!s->budget--) { s->failed_pc=0x0c04628au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0462a6u,2);
goto P_0c04628c;
P_0c04628c: /* original c90f, guest PC 0x0c04628c */
if(!s->budget--) { s->failed_pc=0x0c04628cu; return 0; }
r[0]&=15u;
goto P_0c04628e;
P_0c04628e: /* original 4008, guest PC 0x0c04628e */
if(!s->budget--) { s->failed_pc=0x0c04628eu; return 0; }
r[0]<<=2;
goto P_0c046290;
P_0c046290: /* original 2239, guest PC 0x0c046290 */
if(!s->budget--) { s->failed_pc=0x0c046290u; return 0; }
r[2]&=r[3];
goto P_0c046292;
P_0c046292: /* original 4008, guest PC 0x0c046292 */
if(!s->budget--) { s->failed_pc=0x0c046292u; return 0; }
r[0]<<=2;
goto P_0c046294;
P_0c046294: /* original 202b, guest PC 0x0c046294 */
if(!s->budget--) { s->failed_pc=0x0c046294u; return 0; }
r[0]|=r[2];
goto P_0c046296;
P_0c046296: /* original 400e, guest PC 0x0c046296 */
if(!s->budget--) { s->failed_pc=0x0c046296u; return 0; }
r[17]=r[0];
goto P_0c046298;
P_0c046298: /* original 6043, guest PC 0x0c046298 */
if(!s->budget--) { s->failed_pc=0x0c046298u; return 0; }
r[0]=r[4];
goto P_0c04629a;
P_0c04629a: /* original 7f14, guest PC 0x0c04629a */
if(!s->budget--) { s->failed_pc=0x0c04629au; return 0; }
r[15]+=0x00000014u;
goto P_0c04629c;
P_0c04629c: /* original 4f26, guest PC 0x0c04629c */
if(!s->budget--) { s->failed_pc=0x0c04629cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04629e;
P_0c04629e: /* original 000b, guest PC 0x0c04629e */
if(!s->budget--) { s->failed_pc=0x0c04629eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0462a0: /* original 6ef6, guest PC 0x0c0462a0 */
if(!s->budget--) { s->failed_pc=0x0c0462a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0462a2u,s,ram);
P_0c047230: /* original 4f22, guest PC 0x0c047230 */
if(!s->budget--) { s->failed_pc=0x0c047230u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c047232;
P_0c047232: /* original 7ff0, guest PC 0x0c047232 */
if(!s->budget--) { s->failed_pc=0x0c047232u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c047234;
P_0c047234: /* original 1f43, guest PC 0x0c047234 */
if(!s->budget--) { s->failed_pc=0x0c047234u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c047236;
P_0c047236: /* original 54f3, guest PC 0x0c047236 */
if(!s->budget--) { s->failed_pc=0x0c047236u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c047238;
P_0c047238: /* original d317, guest PC 0x0c047238 */
if(!s->budget--) { s->failed_pc=0x0c047238u; return 0; }
r[3]=read(ram,0x0c047298u,4);
goto P_0c04723a;
P_0c04723a: /* original 430b, guest PC 0x0c04723a */
if(!s->budget--) { s->failed_pc=0x0c04723au; return 0; }
target=r[3];
r[16]=0x0c04723eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04723eu) { target=s->pc; goto dispatch; }
goto P_0c04723e;
P_0c04723c: /* original 0009, guest PC 0x0c04723c */
if(!s->budget--) { s->failed_pc=0x0c04723cu; return 0; }
goto P_0c04723e;
P_0c04723e: /* original 1f02, guest PC 0x0c04723e */
if(!s->budget--) { s->failed_pc=0x0c04723eu; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c047240;
P_0c047240: /* original e602, guest PC 0x0c047240 */
if(!s->budget--) { s->failed_pc=0x0c047240u; return 0; }
r[6]=0x00000002u;
goto P_0c047242;
P_0c047242: /* original 65f3, guest PC 0x0c047242 */
if(!s->budget--) { s->failed_pc=0x0c047242u; return 0; }
r[5]=r[15];
goto P_0c047244;
P_0c047244: /* original 7504, guest PC 0x0c047244 */
if(!s->budget--) { s->failed_pc=0x0c047244u; return 0; }
r[5]+=0x00000004u;
goto P_0c047246;
P_0c047246: /* original d415, guest PC 0x0c047246 */
if(!s->budget--) { s->failed_pc=0x0c047246u; return 0; }
r[4]=read(ram,0x0c04729cu,4);
goto P_0c047248;
P_0c047248: /* original d315, guest PC 0x0c047248 */
if(!s->budget--) { s->failed_pc=0x0c047248u; return 0; }
r[3]=read(ram,0x0c0472a0u,4);
goto P_0c04724a;
P_0c04724a: /* original 430b, guest PC 0x0c04724a */
if(!s->budget--) { s->failed_pc=0x0c04724au; return 0; }
target=r[3];
r[16]=0x0c04724eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04724eu) { target=s->pc; goto dispatch; }
goto P_0c04724e;
P_0c04724c: /* original 0009, guest PC 0x0c04724c */
if(!s->budget--) { s->failed_pc=0x0c04724cu; return 0; }
goto P_0c04724e;
P_0c04724e: /* original 2008, guest PC 0x0c04724e */
if(!s->budget--) { s->failed_pc=0x0c04724eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c047250;
P_0c047250: /* original 8b18, guest PC 0x0c047250 */
if(!s->budget--) { s->failed_pc=0x0c047250u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c047284; }
goto P_0c047252;
P_0c047252: /* original 84f4, guest PC 0x0c047252 */
if(!s->budget--) { s->failed_pc=0x0c047252u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c047254;
P_0c047254: /* original 600c, guest PC 0x0c047254 */
if(!s->budget--) { s->failed_pc=0x0c047254u; return 0; }
r[0]=r[0]&255u;
goto P_0c047256;
P_0c047256: /* original 931e, guest PC 0x0c047256 */
if(!s->budget--) { s->failed_pc=0x0c047256u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c047296u,2);
goto P_0c047258;
P_0c047258: /* original 3030, guest PC 0x0c047258 */
if(!s->budget--) { s->failed_pc=0x0c047258u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c04725a;
P_0c04725a: /* original 8b03, guest PC 0x0c04725a */
if(!s->budget--) { s->failed_pc=0x0c04725au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c047264; }
goto P_0c04725c;
P_0c04725c: /* original 84f5, guest PC 0x0c04725c */
if(!s->budget--) { s->failed_pc=0x0c04725cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+5,1);
goto P_0c04725e;
P_0c04725e: /* original 600c, guest PC 0x0c04725e */
if(!s->budget--) { s->failed_pc=0x0c04725eu; return 0; }
r[0]=r[0]&255u;
goto P_0c047260;
P_0c047260: /* original 3030, guest PC 0x0c047260 */
if(!s->budget--) { s->failed_pc=0x0c047260u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c047262;
P_0c047262: /* original 890f, guest PC 0x0c047262 */
if(!s->budget--) { s->failed_pc=0x0c047262u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c047284; }
goto P_0c047264;
P_0c047264: /* original d30f, guest PC 0x0c047264 */
if(!s->budget--) { s->failed_pc=0x0c047264u; return 0; }
r[3]=read(ram,0x0c0472a4u,4);
goto P_0c047266;
P_0c047266: /* original 2f32, guest PC 0x0c047266 */
if(!s->budget--) { s->failed_pc=0x0c047266u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c047268;
P_0c047268: /* original 62f2, guest PC 0x0c047268 */
if(!s->budget--) { s->failed_pc=0x0c047268u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04726a;
P_0c04726a: /* original 7201, guest PC 0x0c04726a */
if(!s->budget--) { s->failed_pc=0x0c04726au; return 0; }
r[2]+=0x00000001u;
goto P_0c04726c;
P_0c04726c: /* original 2f22, guest PC 0x0c04726c */
if(!s->budget--) { s->failed_pc=0x0c04726cu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c04726e;
P_0c04726e: /* original 72ff, guest PC 0x0c04726e */
if(!s->budget--) { s->failed_pc=0x0c04726eu; return 0; }
r[2]+=0xffffffffu;
goto P_0c047270;
P_0c047270: /* original 84f4, guest PC 0x0c047270 */
if(!s->budget--) { s->failed_pc=0x0c047270u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c047272;
P_0c047272: /* original 2200, guest PC 0x0c047272 */
if(!s->budget--) { s->failed_pc=0x0c047272u; return 0; }
write(ram,r[2],r[0],1);
goto P_0c047274;
P_0c047274: /* original 63f2, guest PC 0x0c047274 */
if(!s->budget--) { s->failed_pc=0x0c047274u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c047276;
P_0c047276: /* original 84f5, guest PC 0x0c047276 */
if(!s->budget--) { s->failed_pc=0x0c047276u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+5,1);
goto P_0c047278;
P_0c047278: /* original 2300, guest PC 0x0c047278 */
if(!s->budget--) { s->failed_pc=0x0c047278u; return 0; }
write(ram,r[3],r[0],1);
goto P_0c04727a;
P_0c04727a: /* original e502, guest PC 0x0c04727a */
if(!s->budget--) { s->failed_pc=0x0c04727au; return 0; }
r[5]=0x00000002u;
goto P_0c04727c;
P_0c04727c: /* original d409, guest PC 0x0c04727c */
if(!s->budget--) { s->failed_pc=0x0c04727cu; return 0; }
r[4]=read(ram,0x0c0472a4u,4);
goto P_0c04727e;
P_0c04727e: /* original d30a, guest PC 0x0c04727e */
if(!s->budget--) { s->failed_pc=0x0c04727eu; return 0; }
r[3]=read(ram,0x0c0472a8u,4);
goto P_0c047280;
P_0c047280: /* original 430b, guest PC 0x0c047280 */
if(!s->budget--) { s->failed_pc=0x0c047280u; return 0; }
target=r[3];
r[16]=0x0c047284u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c047284u) { target=s->pc; goto dispatch; }
goto P_0c047284;
P_0c047282: /* original 0009, guest PC 0x0c047282 */
if(!s->budget--) { s->failed_pc=0x0c047282u; return 0; }
goto P_0c047284;
P_0c047284: /* original 50f2, guest PC 0x0c047284 */
if(!s->budget--) { s->failed_pc=0x0c047284u; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c047286;
P_0c047286: /* original 7f10, guest PC 0x0c047286 */
if(!s->budget--) { s->failed_pc=0x0c047286u; return 0; }
r[15]+=0x00000010u;
goto P_0c047288;
P_0c047288: /* original 4f26, guest PC 0x0c047288 */
if(!s->budget--) { s->failed_pc=0x0c047288u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04728a;
P_0c04728a: /* original 000b, guest PC 0x0c04728a */
if(!s->budget--) { s->failed_pc=0x0c04728au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c04728c: /* original 0009, guest PC 0x0c04728c */
if(!s->budget--) { s->failed_pc=0x0c04728cu; return 0; }
return vf3_matrix_family(0x0c04728eu,s,ram);
P_0c04fab4: /* original 4f22, guest PC 0x0c04fab4 */
if(!s->budget--) { s->failed_pc=0x0c04fab4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04fab6;
P_0c04fab6: /* original 4f12, guest PC 0x0c04fab6 */
if(!s->budget--) { s->failed_pc=0x0c04fab6u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fab8;
P_0c04fab8: /* original 7ffc, guest PC 0x0c04fab8 */
if(!s->budget--) { s->failed_pc=0x0c04fab8u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04faba;
P_0c04faba: /* original 2f42, guest PC 0x0c04faba */
if(!s->budget--) { s->failed_pc=0x0c04fabau; return 0; }
write(ram,r[15],r[4],4);
goto P_0c04fabc;
P_0c04fabc: /* original 9312, guest PC 0x0c04fabc */
if(!s->budget--) { s->failed_pc=0x0c04fabcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fae4u,2);
goto P_0c04fabe;
P_0c04fabe: /* original d20c, guest PC 0x0c04fabe */
if(!s->budget--) { s->failed_pc=0x0c04fabeu; return 0; }
r[2]=read(ram,0x0c04faf0u,4);
goto P_0c04fac0;
P_0c04fac0: /* original 2e3f, guest PC 0x0c04fac0 */
if(!s->budget--) { s->failed_pc=0x0c04fac0u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c04fac2;
P_0c04fac2: /* original d309, guest PC 0x0c04fac2 */
if(!s->budget--) { s->failed_pc=0x0c04fac2u; return 0; }
r[3]=read(ram,0x0c04fae8u,4);
goto P_0c04fac4;
P_0c04fac4: /* original d10b, guest PC 0x0c04fac4 */
if(!s->budget--) { s->failed_pc=0x0c04fac4u; return 0; }
r[1]=read(ram,0x0c04faf4u,4);
goto P_0c04fac6;
P_0c04fac6: /* original 0e1a, guest PC 0x0c04fac6 */
if(!s->budget--) { s->failed_pc=0x0c04fac6u; return 0; }
r[14]=r[19];
goto P_0c04fac8;
P_0c04fac8: /* original 6eef, guest PC 0x0c04fac8 */
if(!s->budget--) { s->failed_pc=0x0c04fac8u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04faca;
P_0c04faca: /* original 3e2c, guest PC 0x0c04faca */
if(!s->budget--) { s->failed_pc=0x0c04facau; return 0; }
r[14]+=r[2];
goto P_0c04facc;
P_0c04facc: /* original 430b, guest PC 0x0c04facc */
if(!s->budget--) { s->failed_pc=0x0c04faccu; return 0; }
target=r[3];
r[16]=0x0c04fad0u;
r[15]-=4; write(ram,r[15],r[1],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04fad0u) { target=s->pc; goto dispatch; }
goto P_0c04fad0;
P_0c04face: /* original 2f16, guest PC 0x0c04face */
if(!s->budget--) { s->failed_pc=0x0c04faceu; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c04fad0;
P_0c04fad0: /* original 54f1, guest PC 0x0c04fad0 */
if(!s->budget--) { s->failed_pc=0x0c04fad0u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c04fad2;
P_0c04fad2: /* original 7f08, guest PC 0x0c04fad2 */
if(!s->budget--) { s->failed_pc=0x0c04fad2u; return 0; }
r[15]+=0x00000008u;
goto P_0c04fad4;
P_0c04fad4: /* original 4f16, guest PC 0x0c04fad4 */
if(!s->budget--) { s->failed_pc=0x0c04fad4u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fad6;
P_0c04fad6: /* original 55e7, guest PC 0x0c04fad6 */
if(!s->budget--) { s->failed_pc=0x0c04fad6u; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c04fad8;
P_0c04fad8: /* original d307, guest PC 0x0c04fad8 */
if(!s->budget--) { s->failed_pc=0x0c04fad8u; return 0; }
r[3]=read(ram,0x0c04faf8u,4);
goto P_0c04fada;
P_0c04fada: /* original 4f26, guest PC 0x0c04fada */
if(!s->budget--) { s->failed_pc=0x0c04fadau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fadc;
P_0c04fadc: /* original 56e8, guest PC 0x0c04fadc */
if(!s->budget--) { s->failed_pc=0x0c04fadcu; return 0; }
r[6]=read(ram,r[14]+32,4);
goto P_0c04fade;
P_0c04fade: /* original 5552, guest PC 0x0c04fade */
if(!s->budget--) { s->failed_pc=0x0c04fadeu; return 0; }
r[5]=read(ram,r[5]+8,4);
goto P_0c04fae0;
P_0c04fae0: /* original 432b, guest PC 0x0c04fae0 */
if(!s->budget--) { s->failed_pc=0x0c04fae0u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c04fae2: /* original 6ef6, guest PC 0x0c04fae2 */
if(!s->budget--) { s->failed_pc=0x0c04fae2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04fae4u,s,ram);
P_0c050128: /* original 4f22, guest PC 0x0c050128 */
if(!s->budget--) { s->failed_pc=0x0c050128u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05012a;
P_0c05012a: /* original d34c, guest PC 0x0c05012a */
if(!s->budget--) { s->failed_pc=0x0c05012au; return 0; }
r[3]=read(ram,0x0c05025cu,4);
goto P_0c05012c;
P_0c05012c: /* original 6143, guest PC 0x0c05012c */
if(!s->budget--) { s->failed_pc=0x0c05012cu; return 0; }
r[1]=r[4];
goto P_0c05012e;
P_0c05012e: /* original e60a, guest PC 0x0c05012e */
if(!s->budget--) { s->failed_pc=0x0c05012eu; return 0; }
r[6]=0x0000000au;
goto P_0c050130;
P_0c050130: /* original 430b, guest PC 0x0c050130 */
if(!s->budget--) { s->failed_pc=0x0c050130u; return 0; }
target=r[3];
r[16]=0x0c050134u;
r[0]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050134u) { target=s->pc; goto dispatch; }
goto P_0c050134;
P_0c050132: /* original 6063, guest PC 0x0c050132 */
if(!s->budget--) { s->failed_pc=0x0c050132u; return 0; }
r[0]=r[6];
goto P_0c050134;
P_0c050134: /* original d24a, guest PC 0x0c050134 */
if(!s->budget--) { s->failed_pc=0x0c050134u; return 0; }
r[2]=read(ram,0x0c050260u,4);
goto P_0c050136;
P_0c050136: /* original 6143, guest PC 0x0c050136 */
if(!s->budget--) { s->failed_pc=0x0c050136u; return 0; }
r[1]=r[4];
goto P_0c050138;
P_0c050138: /* original 6503, guest PC 0x0c050138 */
if(!s->budget--) { s->failed_pc=0x0c050138u; return 0; }
r[5]=r[0];
goto P_0c05013a;
P_0c05013a: /* original 420b, guest PC 0x0c05013a */
if(!s->budget--) { s->failed_pc=0x0c05013au; return 0; }
target=r[2];
r[16]=0x0c05013eu;
r[0]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05013eu) { target=s->pc; goto dispatch; }
goto P_0c05013e;
P_0c05013c: /* original 6063, guest PC 0x0c05013c */
if(!s->budget--) { s->failed_pc=0x0c05013cu; return 0; }
r[0]=r[6];
goto P_0c05013e;
P_0c05013e: /* original 6403, guest PC 0x0c05013e */
if(!s->budget--) { s->failed_pc=0x0c05013eu; return 0; }
r[4]=r[0];
goto P_0c050140;
P_0c050140: /* original 6053, guest PC 0x0c050140 */
if(!s->budget--) { s->failed_pc=0x0c050140u; return 0; }
r[0]=r[5];
goto P_0c050142;
P_0c050142: /* original 4f26, guest PC 0x0c050142 */
if(!s->budget--) { s->failed_pc=0x0c050142u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c050144;
P_0c050144: /* original 4008, guest PC 0x0c050144 */
if(!s->budget--) { s->failed_pc=0x0c050144u; return 0; }
r[0]<<=2;
goto P_0c050146;
P_0c050146: /* original 4008, guest PC 0x0c050146 */
if(!s->budget--) { s->failed_pc=0x0c050146u; return 0; }
r[0]<<=2;
goto P_0c050148;
P_0c050148: /* original 000b, guest PC 0x0c050148 */
if(!s->budget--) { s->failed_pc=0x0c050148u; return 0; }
target=r[16];
r[0]+=r[4];
s->pc=target; return ram->oob==0;
P_0c05014a: /* original 304c, guest PC 0x0c05014a */
if(!s->budget--) { s->failed_pc=0x0c05014au; return 0; }
r[0]+=r[4];
goto P_0c05014c;
P_0c05014c: /* original 6543, guest PC 0x0c05014c */
if(!s->budget--) { s->failed_pc=0x0c05014cu; return 0; }
r[5]=r[4];
goto P_0c05014e;
P_0c05014e: /* original 4509, guest PC 0x0c05014e */
if(!s->budget--) { s->failed_pc=0x0c05014eu; return 0; }
r[5]>>=2;
goto P_0c050150;
P_0c050150: /* original 4509, guest PC 0x0c050150 */
if(!s->budget--) { s->failed_pc=0x0c050150u; return 0; }
r[5]>>=2;
goto P_0c050152;
P_0c050152: /* original 6053, guest PC 0x0c050152 */
if(!s->budget--) { s->failed_pc=0x0c050152u; return 0; }
r[0]=r[5];
goto P_0c050154;
P_0c050154: /* original 6253, guest PC 0x0c050154 */
if(!s->budget--) { s->failed_pc=0x0c050154u; return 0; }
r[2]=r[5];
goto P_0c050156;
P_0c050156: /* original 4008, guest PC 0x0c050156 */
if(!s->budget--) { s->failed_pc=0x0c050156u; return 0; }
r[0]<<=2;
goto P_0c050158;
P_0c050158: /* original e30f, guest PC 0x0c050158 */
if(!s->budget--) { s->failed_pc=0x0c050158u; return 0; }
r[3]=0x0000000fu;
goto P_0c05015a;
P_0c05015a: /* original 302c, guest PC 0x0c05015a */
if(!s->budget--) { s->failed_pc=0x0c05015au; return 0; }
r[0]+=r[2];
goto P_0c05015c;
P_0c05015c: /* original 4000, guest PC 0x0c05015c */
if(!s->budget--) { s->failed_pc=0x0c05015cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c05015e;
P_0c05015e: /* original 2439, guest PC 0x0c05015e */
if(!s->budget--) { s->failed_pc=0x0c05015eu; return 0; }
r[4]&=r[3];
goto P_0c050160;
P_0c050160: /* original 000b, guest PC 0x0c050160 */
if(!s->budget--) { s->failed_pc=0x0c050160u; return 0; }
target=r[16];
r[0]+=r[4];
s->pc=target; return ram->oob==0;
P_0c050162: /* original 304c, guest PC 0x0c050162 */
if(!s->budget--) { s->failed_pc=0x0c050162u; return 0; }
r[0]+=r[4];
return vf3_matrix_family(0x0c050164u,s,ram);
P_0c050174: /* original 4f22, guest PC 0x0c050174 */
if(!s->budget--) { s->failed_pc=0x0c050174u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c050176;
P_0c050176: /* original d33b, guest PC 0x0c050176 */
if(!s->budget--) { s->failed_pc=0x0c050176u; return 0; }
r[3]=read(ram,0x0c050264u,4);
goto P_0c050178;
P_0c050178: /* original 611d, guest PC 0x0c050178 */
if(!s->budget--) { s->failed_pc=0x0c050178u; return 0; }
r[1]=r[1]&65535u;
goto P_0c05017a;
P_0c05017a: /* original 430b, guest PC 0x0c05017a */
if(!s->budget--) { s->failed_pc=0x0c05017au; return 0; }
target=r[3];
r[16]=0x0c05017eu;
r[14]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05017eu) { target=s->pc; goto dispatch; }
goto P_0c05017e;
P_0c05017c: /* original 7e01, guest PC 0x0c05017c */
if(!s->budget--) { s->failed_pc=0x0c05017cu; return 0; }
r[14]+=0x00000001u;
goto P_0c05017e;
P_0c05017e: /* original bfd3, guest PC 0x0c05017e */
if(!s->budget--) { s->failed_pc=0x0c05017eu; return 0; }
target=0x0c050128u; r[16]=0x0c050182u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050182u) { target=s->pc; goto dispatch; }
goto P_0c050182;
P_0c050180: /* original 6403, guest PC 0x0c050180 */
if(!s->budget--) { s->failed_pc=0x0c050180u; return 0; }
r[4]=r[0];
goto P_0c050182;
P_0c050182: /* original 2800, guest PC 0x0c050182 */
if(!s->budget--) { s->failed_pc=0x0c050182u; return 0; }
write(ram,r[8],r[0],1);
goto P_0c050184;
P_0c050184: /* original e064, guest PC 0x0c050184 */
if(!s->budget--) { s->failed_pc=0x0c050184u; return 0; }
r[0]=0x00000064u;
goto P_0c050186;
P_0c050186: /* original 61d1, guest PC 0x0c050186 */
if(!s->budget--) { s->failed_pc=0x0c050186u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[1]=tmp;
goto P_0c050188;
P_0c050188: /* original 68e3, guest PC 0x0c050188 */
if(!s->budget--) { s->failed_pc=0x0c050188u; return 0; }
r[8]=r[14];
goto P_0c05018a;
P_0c05018a: /* original d337, guest PC 0x0c05018a */
if(!s->budget--) { s->failed_pc=0x0c05018au; return 0; }
r[3]=read(ram,0x0c050268u,4);
goto P_0c05018c;
P_0c05018c: /* original 611d, guest PC 0x0c05018c */
if(!s->budget--) { s->failed_pc=0x0c05018cu; return 0; }
r[1]=r[1]&65535u;
goto P_0c05018e;
P_0c05018e: /* original 430b, guest PC 0x0c05018e */
if(!s->budget--) { s->failed_pc=0x0c05018eu; return 0; }
target=r[3];
r[16]=0x0c050192u;
r[14]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050192u) { target=s->pc; goto dispatch; }
goto P_0c050192;
P_0c050190: /* original 7e01, guest PC 0x0c050190 */
if(!s->budget--) { s->failed_pc=0x0c050190u; return 0; }
r[14]+=0x00000001u;
goto P_0c050192;
P_0c050192: /* original bfc9, guest PC 0x0c050192 */
if(!s->budget--) { s->failed_pc=0x0c050192u; return 0; }
target=0x0c050128u; r[16]=0x0c050196u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050196u) { target=s->pc; goto dispatch; }
goto P_0c050196;
P_0c050194: /* original 6403, guest PC 0x0c050194 */
if(!s->budget--) { s->failed_pc=0x0c050194u; return 0; }
r[4]=r[0];
goto P_0c050196;
P_0c050196: /* original 2800, guest PC 0x0c050196 */
if(!s->budget--) { s->failed_pc=0x0c050196u; return 0; }
write(ram,r[8],r[0],1);
goto P_0c050198;
P_0c050198: /* original 68e3, guest PC 0x0c050198 */
if(!s->budget--) { s->failed_pc=0x0c050198u; return 0; }
r[8]=r[14];
goto P_0c05019a;
P_0c05019a: /* original 84d2, guest PC 0x0c05019a */
if(!s->budget--) { s->failed_pc=0x0c05019au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+2,1);
goto P_0c05019c;
P_0c05019c: /* original 640c, guest PC 0x0c05019c */
if(!s->budget--) { s->failed_pc=0x0c05019cu; return 0; }
r[4]=r[0]&255u;
goto P_0c05019e;
P_0c05019e: /* original bfc3, guest PC 0x0c05019e */
if(!s->budget--) { s->failed_pc=0x0c05019eu; return 0; }
target=0x0c050128u; r[16]=0x0c0501a2u;
r[14]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0501a2u) { target=s->pc; goto dispatch; }
goto P_0c0501a2;
P_0c0501a0: /* original 7e01, guest PC 0x0c0501a0 */
if(!s->budget--) { s->failed_pc=0x0c0501a0u; return 0; }
r[14]+=0x00000001u;
goto P_0c0501a2;
P_0c0501a2: /* original 2800, guest PC 0x0c0501a2 */
if(!s->budget--) { s->failed_pc=0x0c0501a2u; return 0; }
write(ram,r[8],r[0],1);
goto P_0c0501a4;
P_0c0501a4: /* original 68e3, guest PC 0x0c0501a4 */
if(!s->budget--) { s->failed_pc=0x0c0501a4u; return 0; }
r[8]=r[14];
goto P_0c0501a6;
P_0c0501a6: /* original 84d3, guest PC 0x0c0501a6 */
if(!s->budget--) { s->failed_pc=0x0c0501a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+3,1);
goto P_0c0501a8;
P_0c0501a8: /* original 640c, guest PC 0x0c0501a8 */
if(!s->budget--) { s->failed_pc=0x0c0501a8u; return 0; }
r[4]=r[0]&255u;
goto P_0c0501aa;
P_0c0501aa: /* original bfbd, guest PC 0x0c0501aa */
if(!s->budget--) { s->failed_pc=0x0c0501aau; return 0; }
target=0x0c050128u; r[16]=0x0c0501aeu;
r[14]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0501aeu) { target=s->pc; goto dispatch; }
goto P_0c0501ae;
P_0c0501ac: /* original 7e01, guest PC 0x0c0501ac */
if(!s->budget--) { s->failed_pc=0x0c0501acu; return 0; }
r[14]+=0x00000001u;
goto P_0c0501ae;
P_0c0501ae: /* original 2800, guest PC 0x0c0501ae */
if(!s->budget--) { s->failed_pc=0x0c0501aeu; return 0; }
write(ram,r[8],r[0],1);
goto P_0c0501b0;
P_0c0501b0: /* original 68e3, guest PC 0x0c0501b0 */
if(!s->budget--) { s->failed_pc=0x0c0501b0u; return 0; }
r[8]=r[14];
goto P_0c0501b2;
P_0c0501b2: /* original 84d4, guest PC 0x0c0501b2 */
if(!s->budget--) { s->failed_pc=0x0c0501b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+4,1);
goto P_0c0501b4;
P_0c0501b4: /* original 640c, guest PC 0x0c0501b4 */
if(!s->budget--) { s->failed_pc=0x0c0501b4u; return 0; }
r[4]=r[0]&255u;
goto P_0c0501b6;
P_0c0501b6: /* original bfb7, guest PC 0x0c0501b6 */
if(!s->budget--) { s->failed_pc=0x0c0501b6u; return 0; }
target=0x0c050128u; r[16]=0x0c0501bau;
r[14]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0501bau) { target=s->pc; goto dispatch; }
goto P_0c0501ba;
P_0c0501b8: /* original 7e01, guest PC 0x0c0501b8 */
if(!s->budget--) { s->failed_pc=0x0c0501b8u; return 0; }
r[14]+=0x00000001u;
goto P_0c0501ba;
P_0c0501ba: /* original 2800, guest PC 0x0c0501ba */
if(!s->budget--) { s->failed_pc=0x0c0501bau; return 0; }
write(ram,r[8],r[0],1);
goto P_0c0501bc;
P_0c0501bc: /* original 68e3, guest PC 0x0c0501bc */
if(!s->budget--) { s->failed_pc=0x0c0501bcu; return 0; }
r[8]=r[14];
goto P_0c0501be;
P_0c0501be: /* original 84d5, guest PC 0x0c0501be */
if(!s->budget--) { s->failed_pc=0x0c0501beu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+5,1);
goto P_0c0501c0;
P_0c0501c0: /* original 640c, guest PC 0x0c0501c0 */
if(!s->budget--) { s->failed_pc=0x0c0501c0u; return 0; }
r[4]=r[0]&255u;
goto P_0c0501c2;
P_0c0501c2: /* original bfb1, guest PC 0x0c0501c2 */
if(!s->budget--) { s->failed_pc=0x0c0501c2u; return 0; }
target=0x0c050128u; r[16]=0x0c0501c6u;
r[14]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0501c6u) { target=s->pc; goto dispatch; }
goto P_0c0501c6;
P_0c0501c4: /* original 7e01, guest PC 0x0c0501c4 */
if(!s->budget--) { s->failed_pc=0x0c0501c4u; return 0; }
r[14]+=0x00000001u;
goto P_0c0501c6;
P_0c0501c6: /* original 2800, guest PC 0x0c0501c6 */
if(!s->budget--) { s->failed_pc=0x0c0501c6u; return 0; }
write(ram,r[8],r[0],1);
goto P_0c0501c8;
P_0c0501c8: /* original 68e3, guest PC 0x0c0501c8 */
if(!s->budget--) { s->failed_pc=0x0c0501c8u; return 0; }
r[8]=r[14];
goto P_0c0501ca;
P_0c0501ca: /* original 84d6, guest PC 0x0c0501ca */
if(!s->budget--) { s->failed_pc=0x0c0501cau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+6,1);
goto P_0c0501cc;
P_0c0501cc: /* original 640c, guest PC 0x0c0501cc */
if(!s->budget--) { s->failed_pc=0x0c0501ccu; return 0; }
r[4]=r[0]&255u;
goto P_0c0501ce;
P_0c0501ce: /* original bfab, guest PC 0x0c0501ce */
if(!s->budget--) { s->failed_pc=0x0c0501ceu; return 0; }
target=0x0c050128u; r[16]=0x0c0501d2u;
r[14]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0501d2u) { target=s->pc; goto dispatch; }
goto P_0c0501d2;
P_0c0501d0: /* original 7e01, guest PC 0x0c0501d0 */
if(!s->budget--) { s->failed_pc=0x0c0501d0u; return 0; }
r[14]+=0x00000001u;
goto P_0c0501d2;
P_0c0501d2: /* original 2800, guest PC 0x0c0501d2 */
if(!s->budget--) { s->failed_pc=0x0c0501d2u; return 0; }
write(ram,r[8],r[0],1);
goto P_0c0501d4;
P_0c0501d4: /* original 4f26, guest PC 0x0c0501d4 */
if(!s->budget--) { s->failed_pc=0x0c0501d4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0501d6;
P_0c0501d6: /* original 84d7, guest PC 0x0c0501d6 */
if(!s->budget--) { s->failed_pc=0x0c0501d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+7,1);
goto P_0c0501d8;
P_0c0501d8: /* original d124, guest PC 0x0c0501d8 */
if(!s->budget--) { s->failed_pc=0x0c0501d8u; return 0; }
r[1]=read(ram,0x0c05026cu,4);
goto P_0c0501da;
P_0c0501da: /* original 600c, guest PC 0x0c0501da */
if(!s->budget--) { s->failed_pc=0x0c0501dau; return 0; }
r[0]=r[0]&255u;
goto P_0c0501dc;
P_0c0501dc: /* original c907, guest PC 0x0c0501dc */
if(!s->budget--) { s->failed_pc=0x0c0501dcu; return 0; }
r[0]&=7u;
goto P_0c0501de;
P_0c0501de: /* original 031c, guest PC 0x0c0501de */
if(!s->budget--) { s->failed_pc=0x0c0501deu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0501e0;
P_0c0501e0: /* original 2e30, guest PC 0x0c0501e0 */
if(!s->budget--) { s->failed_pc=0x0c0501e0u; return 0; }
write(ram,r[14],r[3],1);
goto P_0c0501e2;
P_0c0501e2: /* original 68f6, guest PC 0x0c0501e2 */
if(!s->budget--) { s->failed_pc=0x0c0501e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0501e4;
P_0c0501e4: /* original 6df6, guest PC 0x0c0501e4 */
if(!s->budget--) { s->failed_pc=0x0c0501e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0501e6;
P_0c0501e6: /* original 000b, guest PC 0x0c0501e6 */
if(!s->budget--) { s->failed_pc=0x0c0501e6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0501e8: /* original 6ef6, guest PC 0x0c0501e8 */
if(!s->budget--) { s->failed_pc=0x0c0501e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0501eau,s,ram);
P_0c0501f4: /* original 4f22, guest PC 0x0c0501f4 */
if(!s->budget--) { s->failed_pc=0x0c0501f4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0501f6;
P_0c0501f6: /* original 64e0, guest PC 0x0c0501f6 */
if(!s->budget--) { s->failed_pc=0x0c0501f6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[4]=tmp;
goto P_0c0501f8;
P_0c0501f8: /* original 4f12, guest PC 0x0c0501f8 */
if(!s->budget--) { s->failed_pc=0x0c0501f8u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0501fa;
P_0c0501fa: /* original bfa7, guest PC 0x0c0501fa */
if(!s->budget--) { s->failed_pc=0x0c0501fau; return 0; }
target=0x0c05014cu; r[16]=0x0c0501feu;
r[4]=r[4]&255u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0501feu) { target=s->pc; goto dispatch; }
goto P_0c0501fe;
P_0c0501fc: /* original 644c, guest PC 0x0c0501fc */
if(!s->budget--) { s->failed_pc=0x0c0501fcu; return 0; }
r[4]=r[4]&255u;
goto P_0c0501fe;
P_0c0501fe: /* original e264, guest PC 0x0c0501fe */
if(!s->budget--) { s->failed_pc=0x0c0501feu; return 0; }
r[2]=0x00000064u;
goto P_0c050200;
P_0c050200: /* original 202e, guest PC 0x0c050200 */
if(!s->budget--) { s->failed_pc=0x0c050200u; return 0; }
r[19]=(r[0]&65535u)*(r[2]&65535u);
goto P_0c050202;
P_0c050202: /* original 001a, guest PC 0x0c050202 */
if(!s->budget--) { s->failed_pc=0x0c050202u; return 0; }
r[0]=r[19];
goto P_0c050204;
P_0c050204: /* original 6803, guest PC 0x0c050204 */
if(!s->budget--) { s->failed_pc=0x0c050204u; return 0; }
r[8]=r[0];
goto P_0c050206;
P_0c050206: /* original 84e1, guest PC 0x0c050206 */
if(!s->budget--) { s->failed_pc=0x0c050206u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+1,1);
goto P_0c050208;
P_0c050208: /* original bfa0, guest PC 0x0c050208 */
if(!s->budget--) { s->failed_pc=0x0c050208u; return 0; }
target=0x0c05014cu; r[16]=0x0c05020cu;
r[4]=r[0]&255u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05020cu) { target=s->pc; goto dispatch; }
goto P_0c05020c;
P_0c05020a: /* original 640c, guest PC 0x0c05020a */
if(!s->budget--) { s->failed_pc=0x0c05020au; return 0; }
r[4]=r[0]&255u;
goto P_0c05020c;
P_0c05020c: /* original 380c, guest PC 0x0c05020c */
if(!s->budget--) { s->failed_pc=0x0c05020cu; return 0; }
r[8]+=r[0];
goto P_0c05020e;
P_0c05020e: /* original 2d81, guest PC 0x0c05020e */
if(!s->budget--) { s->failed_pc=0x0c05020eu; return 0; }
write(ram,r[13],r[8],2);
goto P_0c050210;
P_0c050210: /* original 84e2, guest PC 0x0c050210 */
if(!s->budget--) { s->failed_pc=0x0c050210u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c050212;
P_0c050212: /* original bf9b, guest PC 0x0c050212 */
if(!s->budget--) { s->failed_pc=0x0c050212u; return 0; }
target=0x0c05014cu; r[16]=0x0c050216u;
r[4]=r[0]&255u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050216u) { target=s->pc; goto dispatch; }
goto P_0c050216;
P_0c050214: /* original 640c, guest PC 0x0c050214 */
if(!s->budget--) { s->failed_pc=0x0c050214u; return 0; }
r[4]=r[0]&255u;
goto P_0c050216;
P_0c050216: /* original 80d2, guest PC 0x0c050216 */
if(!s->budget--) { s->failed_pc=0x0c050216u; return 0; }
write(ram,r[13]+2,r[0],1);
goto P_0c050218;
P_0c050218: /* original 84e3, guest PC 0x0c050218 */
if(!s->budget--) { s->failed_pc=0x0c050218u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+3,1);
goto P_0c05021a;
P_0c05021a: /* original bf97, guest PC 0x0c05021a */
if(!s->budget--) { s->failed_pc=0x0c05021au; return 0; }
target=0x0c05014cu; r[16]=0x0c05021eu;
r[4]=r[0]&255u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05021eu) { target=s->pc; goto dispatch; }
goto P_0c05021e;
P_0c05021c: /* original 640c, guest PC 0x0c05021c */
if(!s->budget--) { s->failed_pc=0x0c05021cu; return 0; }
r[4]=r[0]&255u;
goto P_0c05021e;
P_0c05021e: /* original 80d3, guest PC 0x0c05021e */
if(!s->budget--) { s->failed_pc=0x0c05021eu; return 0; }
write(ram,r[13]+3,r[0],1);
goto P_0c050220;
P_0c050220: /* original 84e4, guest PC 0x0c050220 */
if(!s->budget--) { s->failed_pc=0x0c050220u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c050222;
P_0c050222: /* original bf93, guest PC 0x0c050222 */
if(!s->budget--) { s->failed_pc=0x0c050222u; return 0; }
target=0x0c05014cu; r[16]=0x0c050226u;
r[4]=r[0]&255u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050226u) { target=s->pc; goto dispatch; }
goto P_0c050226;
P_0c050224: /* original 640c, guest PC 0x0c050224 */
if(!s->budget--) { s->failed_pc=0x0c050224u; return 0; }
r[4]=r[0]&255u;
goto P_0c050226;
P_0c050226: /* original 80d4, guest PC 0x0c050226 */
if(!s->budget--) { s->failed_pc=0x0c050226u; return 0; }
write(ram,r[13]+4,r[0],1);
goto P_0c050228;
P_0c050228: /* original 84e5, guest PC 0x0c050228 */
if(!s->budget--) { s->failed_pc=0x0c050228u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+5,1);
goto P_0c05022a;
P_0c05022a: /* original bf8f, guest PC 0x0c05022a */
if(!s->budget--) { s->failed_pc=0x0c05022au; return 0; }
target=0x0c05014cu; r[16]=0x0c05022eu;
r[4]=r[0]&255u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05022eu) { target=s->pc; goto dispatch; }
goto P_0c05022e;
P_0c05022c: /* original 640c, guest PC 0x0c05022c */
if(!s->budget--) { s->failed_pc=0x0c05022cu; return 0; }
r[4]=r[0]&255u;
goto P_0c05022e;
P_0c05022e: /* original 80d5, guest PC 0x0c05022e */
if(!s->budget--) { s->failed_pc=0x0c05022eu; return 0; }
write(ram,r[13]+5,r[0],1);
goto P_0c050230;
P_0c050230: /* original 84e6, guest PC 0x0c050230 */
if(!s->budget--) { s->failed_pc=0x0c050230u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+6,1);
goto P_0c050232;
P_0c050232: /* original bf8b, guest PC 0x0c050232 */
if(!s->budget--) { s->failed_pc=0x0c050232u; return 0; }
target=0x0c05014cu; r[16]=0x0c050236u;
r[4]=r[0]&255u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050236u) { target=s->pc; goto dispatch; }
goto P_0c050236;
P_0c050234: /* original 640c, guest PC 0x0c050234 */
if(!s->budget--) { s->failed_pc=0x0c050234u; return 0; }
r[4]=r[0]&255u;
goto P_0c050236;
P_0c050236: /* original 4f16, guest PC 0x0c050236 */
if(!s->budget--) { s->failed_pc=0x0c050236u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c050238;
P_0c050238: /* original 80d6, guest PC 0x0c050238 */
if(!s->budget--) { s->failed_pc=0x0c050238u; return 0; }
write(ram,r[13]+6,r[0],1);
goto P_0c05023a;
P_0c05023a: /* original 84e7, guest PC 0x0c05023a */
if(!s->budget--) { s->failed_pc=0x0c05023au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+7,1);
goto P_0c05023c;
P_0c05023c: /* original 4f26, guest PC 0x0c05023c */
if(!s->budget--) { s->failed_pc=0x0c05023cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05023e;
P_0c05023e: /* original d10c, guest PC 0x0c05023e */
if(!s->budget--) { s->failed_pc=0x0c05023eu; return 0; }
r[1]=read(ram,0x0c050270u,4);
goto P_0c050240;
P_0c050240: /* original 600c, guest PC 0x0c050240 */
if(!s->budget--) { s->failed_pc=0x0c050240u; return 0; }
r[0]=r[0]&255u;
goto P_0c050242;
P_0c050242: /* original c907, guest PC 0x0c050242 */
if(!s->budget--) { s->failed_pc=0x0c050242u; return 0; }
r[0]&=7u;
goto P_0c050244;
P_0c050244: /* original 001c, guest PC 0x0c050244 */
if(!s->budget--) { s->failed_pc=0x0c050244u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c050246;
P_0c050246: /* original 80d7, guest PC 0x0c050246 */
if(!s->budget--) { s->failed_pc=0x0c050246u; return 0; }
write(ram,r[13]+7,r[0],1);
goto P_0c050248;
P_0c050248: /* original 68f6, guest PC 0x0c050248 */
if(!s->budget--) { s->failed_pc=0x0c050248u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c05024a;
P_0c05024a: /* original 6df6, guest PC 0x0c05024a */
if(!s->budget--) { s->failed_pc=0x0c05024au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05024c;
P_0c05024c: /* original 000b, guest PC 0x0c05024c */
if(!s->budget--) { s->failed_pc=0x0c05024cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05024e: /* original 6ef6, guest PC 0x0c05024e */
if(!s->budget--) { s->failed_pc=0x0c05024eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c050250u,s,ram);
P_0c0512dc: /* original 7f24, guest PC 0x0c0512dc */
if(!s->budget--) { s->failed_pc=0x0c0512dcu; return 0; }
r[15]+=0x00000024u;
goto P_0c0512de;
P_0c0512de: /* original 000b, guest PC 0x0c0512de */
if(!s->budget--) { s->failed_pc=0x0c0512deu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0512e0: /* original 0009, guest PC 0x0c0512e0 */
if(!s->budget--) { s->failed_pc=0x0c0512e0u; return 0; }
return vf3_matrix_family(0x0c0512e2u,s,ram);
P_0c0514f0: /* original d702, guest PC 0x0c0514f0 */
if(!s->budget--) { s->failed_pc=0x0c0514f0u; return 0; }
r[7]=read(ram,0x0c0514fcu,4);
goto P_0c0514f2;
P_0c0514f2: /* original d003, guest PC 0x0c0514f2 */
if(!s->budget--) { s->failed_pc=0x0c0514f2u; return 0; }
r[0]=read(ram,0x0c051500u,4);
goto P_0c0514f4;
P_0c0514f4: /* original 6002, guest PC 0x0c0514f4 */
if(!s->budget--) { s->failed_pc=0x0c0514f4u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c0514f6;
P_0c0514f6: /* original 402b, guest PC 0x0c0514f6 */
if(!s->budget--) { s->failed_pc=0x0c0514f6u; return 0; }
target=r[0];
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
P_0c0514f8: /* original 0009, guest PC 0x0c0514f8 */
if(!s->budget--) { s->failed_pc=0x0c0514f8u; return 0; }
return vf3_matrix_family(0x0c0514fau,s,ram);
P_0c05174c: /* original d007, guest PC 0x0c05174c */
if(!s->budget--) { s->failed_pc=0x0c05174cu; return 0; }
r[0]=read(ram,0x0c05176cu,4);
goto P_0c05174e;
P_0c05174e: /* original 6002, guest PC 0x0c05174e */
if(!s->budget--) { s->failed_pc=0x0c05174eu; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c051750;
P_0c051750: /* original 2008, guest PC 0x0c051750 */
if(!s->budget--) { s->failed_pc=0x0c051750u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c051752;
P_0c051752: /* original 8b0d, guest PC 0x0c051752 */
if(!s->budget--) { s->failed_pc=0x0c051752u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c051770; }
goto P_0c051754;
P_0c051754: /* original 7c1c, guest PC 0x0c051754 */
if(!s->budget--) { s->failed_pc=0x0c051754u; return 0; }
r[12]+=0x0000001cu;
goto P_0c051756;
P_0c051756: /* original 2c56, guest PC 0x0c051756 */
if(!s->budget--) { s->failed_pc=0x0c051756u; return 0; }
r[12]-=4; write(ram,r[12],r[5],4);
goto P_0c051758;
P_0c051758: /* original 7cfc, guest PC 0x0c051758 */
if(!s->budget--) { s->failed_pc=0x0c051758u; return 0; }
r[12]+=0xfffffffcu;
goto P_0c05175a;
P_0c05175a: /* original e000, guest PC 0x0c05175a */
if(!s->budget--) { s->failed_pc=0x0c05175au; return 0; }
r[0]=0x00000000u;
goto P_0c05175c;
P_0c05175c: /* original 2c06, guest PC 0x0c05175c */
if(!s->budget--) { s->failed_pc=0x0c05175cu; return 0; }
r[12]-=4; write(ram,r[12],r[0],4);
goto P_0c05175e;
P_0c05175e: /* original fc6b, guest PC 0x0c05175e */
if(!s->budget--) { s->failed_pc=0x0c05175eu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c051760;
P_0c051760: /* original fc5b, guest PC 0x0c051760 */
if(!s->budget--) { s->failed_pc=0x0c051760u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c051762;
P_0c051762: /* original fc4b, guest PC 0x0c051762 */
if(!s->budget--) { s->failed_pc=0x0c051762u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c051764;
P_0c051764: /* original 2c46, guest PC 0x0c051764 */
if(!s->budget--) { s->failed_pc=0x0c051764u; return 0; }
r[12]-=4; write(ram,r[12],r[4],4);
goto P_0c051766;
P_0c051766: /* original 0c83, guest PC 0x0c051766 */
if(!s->budget--) { s->failed_pc=0x0c051766u; return 0; }
goto P_0c051768;
P_0c051768: /* original 000b, guest PC 0x0c051768 */
if(!s->budget--) { s->failed_pc=0x0c051768u; return 0; }
target=r[16];
r[12]+=0x00000020u;
s->pc=target; return ram->oob==0;
P_0c05176a: /* original 7c20, guest PC 0x0c05176a */
if(!s->budget--) { s->failed_pc=0x0c05176au; return 0; }
r[12]+=0x00000020u;
return vf3_matrix_family(0x0c05176cu,s,ram);
P_0c051770: /* original d168, guest PC 0x0c051770 */
if(!s->budget--) { s->failed_pc=0x0c051770u; return 0; }
r[1]=read(ram,0x0c051914u,4);
goto P_0c051772;
P_0c051772: /* original f018, guest PC 0x0c051772 */
if(!s->budget--) { s->failed_pc=0x0c051772u; return 0; }
vf3_matrix_load(s,ram,0,r[1]);
goto P_0c051774;
P_0c051774: /* original d109, guest PC 0x0c051774 */
if(!s->budget--) { s->failed_pc=0x0c051774u; return 0; }
r[1]=read(ram,0x0c05179cu,4);
goto P_0c051776;
P_0c051776: /* original f218, guest PC 0x0c051776 */
if(!s->budget--) { s->failed_pc=0x0c051776u; return 0; }
vf3_matrix_load(s,ram,2,r[1]);
goto P_0c051778;
P_0c051778: /* original f022, guest PC 0x0c051778 */
if(!s->budget--) { s->failed_pc=0x0c051778u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'*');
goto P_0c05177a;
P_0c05177a: /* original f03d, guest PC 0x0c05177a */
if(!s->budget--) { s->failed_pc=0x0c05177au; return 0; }
r[53]=truncate_float(fr[0]);
goto P_0c05177c;
P_0c05177c: /* original 015a, guest PC 0x0c05177c */
if(!s->budget--) { s->failed_pc=0x0c05177cu; return 0; }
r[1]=r[53];
goto P_0c05177e;
P_0c05177e: /* original 4128, guest PC 0x0c05177e */
if(!s->budget--) { s->failed_pc=0x0c05177eu; return 0; }
r[1]<<=16;
goto P_0c051780;
P_0c051780: /* original 4118, guest PC 0x0c051780 */
if(!s->budget--) { s->failed_pc=0x0c051780u; return 0; }
r[1]<<=8;
goto P_0c051782;
P_0c051782: /* original 251b, guest PC 0x0c051782 */
if(!s->budget--) { s->failed_pc=0x0c051782u; return 0; }
r[5]|=r[1];
goto P_0c051784;
P_0c051784: /* original 7c1c, guest PC 0x0c051784 */
if(!s->budget--) { s->failed_pc=0x0c051784u; return 0; }
r[12]+=0x0000001cu;
goto P_0c051786;
P_0c051786: /* original 2c56, guest PC 0x0c051786 */
if(!s->budget--) { s->failed_pc=0x0c051786u; return 0; }
r[12]-=4; write(ram,r[12],r[5],4);
goto P_0c051788;
P_0c051788: /* original 7cfc, guest PC 0x0c051788 */
if(!s->budget--) { s->failed_pc=0x0c051788u; return 0; }
r[12]+=0xfffffffcu;
goto P_0c05178a;
P_0c05178a: /* original e000, guest PC 0x0c05178a */
if(!s->budget--) { s->failed_pc=0x0c05178au; return 0; }
r[0]=0x00000000u;
goto P_0c05178c;
P_0c05178c: /* original 2c06, guest PC 0x0c05178c */
if(!s->budget--) { s->failed_pc=0x0c05178cu; return 0; }
r[12]-=4; write(ram,r[12],r[0],4);
goto P_0c05178e;
P_0c05178e: /* original fc6b, guest PC 0x0c05178e */
if(!s->budget--) { s->failed_pc=0x0c05178eu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c051790;
P_0c051790: /* original fc5b, guest PC 0x0c051790 */
if(!s->budget--) { s->failed_pc=0x0c051790u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c051792;
P_0c051792: /* original fc4b, guest PC 0x0c051792 */
if(!s->budget--) { s->failed_pc=0x0c051792u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c051794;
P_0c051794: /* original 2c46, guest PC 0x0c051794 */
if(!s->budget--) { s->failed_pc=0x0c051794u; return 0; }
r[12]-=4; write(ram,r[12],r[4],4);
goto P_0c051796;
P_0c051796: /* original 0c83, guest PC 0x0c051796 */
if(!s->budget--) { s->failed_pc=0x0c051796u; return 0; }
goto P_0c051798;
P_0c051798: /* original 000b, guest PC 0x0c051798 */
if(!s->budget--) { s->failed_pc=0x0c051798u; return 0; }
target=r[16];
r[12]+=0x00000020u;
s->pc=target; return ram->oob==0;
P_0c05179a: /* original 7c20, guest PC 0x0c05179a */
if(!s->budget--) { s->failed_pc=0x0c05179au; return 0; }
r[12]+=0x00000020u;
return vf3_matrix_family(0x0c05179cu,s,ram);
P_0c0517b8: /* original 4f22, guest PC 0x0c0517b8 */
if(!s->budget--) { s->failed_pc=0x0c0517b8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0517ba;
P_0c0517ba: /* original d510, guest PC 0x0c0517ba */
if(!s->budget--) { s->failed_pc=0x0c0517bau; return 0; }
r[5]=read(ram,0x0c0517fcu,4);
goto P_0c0517bc;
P_0c0517bc: /* original 08ee, guest PC 0x0c0517bc */
if(!s->budget--) { s->failed_pc=0x0c0517bcu; return 0; }
r[8]=read(ram,r[14]+r[0],4);
goto P_0c0517be;
P_0c0517be: /* original 6081, guest PC 0x0c0517be */
if(!s->budget--) { s->failed_pc=0x0c0517beu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[0]=tmp;
goto P_0c0517c0;
P_0c0517c0: /* original 4008, guest PC 0x0c0517c0 */
if(!s->budget--) { s->failed_pc=0x0c0517c0u; return 0; }
r[0]<<=2;
goto P_0c0517c2;
P_0c0517c2: /* original 6552, guest PC 0x0c0517c2 */
if(!s->budget--) { s->failed_pc=0x0c0517c2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0517c4;
P_0c0517c4: /* original 4000, guest PC 0x0c0517c4 */
if(!s->budget--) { s->failed_pc=0x0c0517c4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0517c6;
P_0c0517c6: /* original 065e, guest PC 0x0c0517c6 */
if(!s->budget--) { s->failed_pc=0x0c0517c6u; return 0; }
r[6]=read(ram,r[5]+r[0],4);
goto P_0c0517c8;
P_0c0517c8: /* original 6023, guest PC 0x0c0517c8 */
if(!s->budget--) { s->failed_pc=0x0c0517c8u; return 0; }
r[0]=r[2];
goto P_0c0517ca;
P_0c0517ca: /* original 08ee, guest PC 0x0c0517ca */
if(!s->budget--) { s->failed_pc=0x0c0517cau; return 0; }
r[8]=read(ram,r[14]+r[0],4);
goto P_0c0517cc;
P_0c0517cc: /* original 6081, guest PC 0x0c0517cc */
if(!s->budget--) { s->failed_pc=0x0c0517ccu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[0]=tmp;
goto P_0c0517ce;
P_0c0517ce: /* original 4008, guest PC 0x0c0517ce */
if(!s->budget--) { s->failed_pc=0x0c0517ceu; return 0; }
r[0]<<=2;
goto P_0c0517d0;
P_0c0517d0: /* original 4000, guest PC 0x0c0517d0 */
if(!s->budget--) { s->failed_pc=0x0c0517d0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0517d2;
P_0c0517d2: /* original 075e, guest PC 0x0c0517d2 */
if(!s->budget--) { s->failed_pc=0x0c0517d2u; return 0; }
r[7]=read(ram,r[5]+r[0],4);
goto P_0c0517d4;
P_0c0517d4: /* original 31ec, guest PC 0x0c0517d4 */
if(!s->budget--) { s->failed_pc=0x0c0517d4u; return 0; }
r[1]+=r[14];
goto P_0c0517d6;
P_0c0517d6: /* original f419, guest PC 0x0c0517d6 */
if(!s->budget--) { s->failed_pc=0x0c0517d6u; return 0; }
vf3_matrix_load(s,ram,4,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c0517d8;
P_0c0517d8: /* original f519, guest PC 0x0c0517d8 */
if(!s->budget--) { s->failed_pc=0x0c0517d8u; return 0; }
vf3_matrix_load(s,ram,5,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c0517da;
P_0c0517da: /* original f619, guest PC 0x0c0517da */
if(!s->budget--) { s->failed_pc=0x0c0517dau; return 0; }
vf3_matrix_load(s,ram,6,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c0517dc;
P_0c0517dc: /* original 33ec, guest PC 0x0c0517dc */
if(!s->budget--) { s->failed_pc=0x0c0517dcu; return 0; }
r[3]+=r[14];
goto P_0c0517de;
P_0c0517de: /* original f839, guest PC 0x0c0517de */
if(!s->budget--) { s->failed_pc=0x0c0517deu; return 0; }
vf3_matrix_load(s,ram,8,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c0517e0;
P_0c0517e0: /* original f939, guest PC 0x0c0517e0 */
if(!s->budget--) { s->failed_pc=0x0c0517e0u; return 0; }
vf3_matrix_load(s,ram,9,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c0517e2;
P_0c0517e2: /* original fa39, guest PC 0x0c0517e2 */
if(!s->budget--) { s->failed_pc=0x0c0517e2u; return 0; }
vf3_matrix_load(s,ram,10,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c0517e4;
P_0c0517e4: /* original c748, guest PC 0x0c0517e4 */
if(!s->budget--) { s->failed_pc=0x0c0517e4u; return 0; }
r[0]=0x0c051908u;
goto P_0c0517e6;
P_0c0517e6: /* original 6002, guest PC 0x0c0517e6 */
if(!s->budget--) { s->failed_pc=0x0c0517e6u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c0517e8;
P_0c0517e8: /* original b00a, guest PC 0x0c0517e8 */
if(!s->budget--) { s->failed_pc=0x0c0517e8u; return 0; }
target=0x0c051800u; r[16]=0x0c0517ecu;
vf3_matrix_load(s,ram,3,r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0517ecu) { target=s->pc; goto dispatch; }
goto P_0c0517ec;
P_0c0517ea: /* original f308, guest PC 0x0c0517ea */
if(!s->budget--) { s->failed_pc=0x0c0517eau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0517ec;
P_0c0517ec: /* original b02e, guest PC 0x0c0517ec */
if(!s->budget--) { s->failed_pc=0x0c0517ecu; return 0; }
target=0x0c05184cu; r[16]=0x0c0517f0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0517f0u) { target=s->pc; goto dispatch; }
goto P_0c0517f0;
P_0c0517ee: /* original 0009, guest PC 0x0c0517ee */
if(!s->budget--) { s->failed_pc=0x0c0517eeu; return 0; }
goto P_0c0517f0;
P_0c0517f0: /* original bfac, guest PC 0x0c0517f0 */
if(!s->budget--) { s->failed_pc=0x0c0517f0u; return 0; }
target=0x0c05174cu; r[16]=0x0c0517f4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0517f4u) { target=s->pc; goto dispatch; }
goto P_0c0517f4;
P_0c0517f2: /* original 0009, guest PC 0x0c0517f2 */
if(!s->budget--) { s->failed_pc=0x0c0517f2u; return 0; }
goto P_0c0517f4;
P_0c0517f4: /* original 4f26, guest PC 0x0c0517f4 */
if(!s->budget--) { s->failed_pc=0x0c0517f4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0517f6;
P_0c0517f6: /* original 000b, guest PC 0x0c0517f6 */
if(!s->budget--) { s->failed_pc=0x0c0517f6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0517f8: /* original 0009, guest PC 0x0c0517f8 */
if(!s->budget--) { s->failed_pc=0x0c0517f8u; return 0; }
return vf3_matrix_family(0x0c0517fau,s,ram);
P_0c05184c: /* original c72c, guest PC 0x0c05184c */
if(!s->budget--) { s->failed_pc=0x0c05184cu; return 0; }
r[0]=0x0c051900u;
goto P_0c05184e;
P_0c05184e: /* original fe09, guest PC 0x0c05184e */
if(!s->budget--) { s->failed_pc=0x0c05184eu; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c051850;
P_0c051850: /* original e101, guest PC 0x0c051850 */
if(!s->budget--) { s->failed_pc=0x0c051850u; return 0; }
r[1]=0x00000001u;
goto P_0c051852;
P_0c051852: /* original 4118, guest PC 0x0c051852 */
if(!s->budget--) { s->failed_pc=0x0c051852u; return 0; }
r[1]<<=8;
goto P_0c051854;
P_0c051854: /* original 71ff, guest PC 0x0c051854 */
if(!s->budget--) { s->failed_pc=0x0c051854u; return 0; }
r[1]+=0xffffffffu;
goto P_0c051856;
P_0c051856: /* original 6363, guest PC 0x0c051856 */
if(!s->budget--) { s->failed_pc=0x0c051856u; return 0; }
r[3]=r[6];
goto P_0c051858;
P_0c051858: /* original 2319, guest PC 0x0c051858 */
if(!s->budget--) { s->failed_pc=0x0c051858u; return 0; }
r[3]&=r[1];
goto P_0c05185a;
P_0c05185a: /* original 435a, guest PC 0x0c05185a */
if(!s->budget--) { s->failed_pc=0x0c05185au; return 0; }
r[53]=r[3];
goto P_0c05185c;
P_0c05185c: /* original f02d, guest PC 0x0c05185c */
if(!s->budget--) { s->failed_pc=0x0c05185cu; return 0; }
fr[0]=vf3_fpu_float(r[53],r[18]);
goto P_0c05185e;
P_0c05185e: /* original f0e2, guest PC 0x0c05185e */
if(!s->budget--) { s->failed_pc=0x0c05185eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[14],r[18],'*');
goto P_0c051860;
P_0c051860: /* original 6363, guest PC 0x0c051860 */
if(!s->budget--) { s->failed_pc=0x0c051860u; return 0; }
r[3]=r[6];
goto P_0c051862;
P_0c051862: /* original 4319, guest PC 0x0c051862 */
if(!s->budget--) { s->failed_pc=0x0c051862u; return 0; }
r[3]>>=8;
goto P_0c051864;
P_0c051864: /* original 2319, guest PC 0x0c051864 */
if(!s->budget--) { s->failed_pc=0x0c051864u; return 0; }
r[3]&=r[1];
goto P_0c051866;
P_0c051866: /* original 435a, guest PC 0x0c051866 */
if(!s->budget--) { s->failed_pc=0x0c051866u; return 0; }
r[53]=r[3];
goto P_0c051868;
P_0c051868: /* original f12d, guest PC 0x0c051868 */
if(!s->budget--) { s->failed_pc=0x0c051868u; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c05186a;
P_0c05186a: /* original f1e2, guest PC 0x0c05186a */
if(!s->budget--) { s->failed_pc=0x0c05186au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[14],r[18],'*');
goto P_0c05186c;
P_0c05186c: /* original 6363, guest PC 0x0c05186c */
if(!s->budget--) { s->failed_pc=0x0c05186cu; return 0; }
r[3]=r[6];
goto P_0c05186e;
P_0c05186e: /* original 4329, guest PC 0x0c05186e */
if(!s->budget--) { s->failed_pc=0x0c05186eu; return 0; }
r[3]>>=16;
goto P_0c051870;
P_0c051870: /* original 2319, guest PC 0x0c051870 */
if(!s->budget--) { s->failed_pc=0x0c051870u; return 0; }
r[3]&=r[1];
goto P_0c051872;
P_0c051872: /* original 435a, guest PC 0x0c051872 */
if(!s->budget--) { s->failed_pc=0x0c051872u; return 0; }
r[53]=r[3];
goto P_0c051874;
P_0c051874: /* original f22d, guest PC 0x0c051874 */
if(!s->budget--) { s->failed_pc=0x0c051874u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c051876;
P_0c051876: /* original f2e2, guest PC 0x0c051876 */
if(!s->budget--) { s->failed_pc=0x0c051876u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[14],r[18],'*');
goto P_0c051878;
P_0c051878: /* original 4629, guest PC 0x0c051878 */
if(!s->budget--) { s->failed_pc=0x0c051878u; return 0; }
r[6]>>=16;
goto P_0c05187a;
P_0c05187a: /* original 4619, guest PC 0x0c05187a */
if(!s->budget--) { s->failed_pc=0x0c05187au; return 0; }
r[6]>>=8;
goto P_0c05187c;
P_0c05187c: /* original 2619, guest PC 0x0c05187c */
if(!s->budget--) { s->failed_pc=0x0c05187cu; return 0; }
r[6]&=r[1];
goto P_0c05187e;
P_0c05187e: /* original 465a, guest PC 0x0c05187e */
if(!s->budget--) { s->failed_pc=0x0c05187eu; return 0; }
r[53]=r[6];
goto P_0c051880;
P_0c051880: /* original f32d, guest PC 0x0c051880 */
if(!s->budget--) { s->failed_pc=0x0c051880u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c051882;
P_0c051882: /* original f3e2, guest PC 0x0c051882 */
if(!s->budget--) { s->failed_pc=0x0c051882u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'*');
goto P_0c051884;
P_0c051884: /* original 6373, guest PC 0x0c051884 */
if(!s->budget--) { s->failed_pc=0x0c051884u; return 0; }
r[3]=r[7];
goto P_0c051886;
P_0c051886: /* original 2319, guest PC 0x0c051886 */
if(!s->budget--) { s->failed_pc=0x0c051886u; return 0; }
r[3]&=r[1];
goto P_0c051888;
P_0c051888: /* original 435a, guest PC 0x0c051888 */
if(!s->budget--) { s->failed_pc=0x0c051888u; return 0; }
r[53]=r[3];
goto P_0c05188a;
P_0c05188a: /* original fa2d, guest PC 0x0c05188a */
if(!s->budget--) { s->failed_pc=0x0c05188au; return 0; }
fr[10]=vf3_fpu_float(r[53],r[18]);
goto P_0c05188c;
P_0c05188c: /* original fae2, guest PC 0x0c05188c */
if(!s->budget--) { s->failed_pc=0x0c05188cu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[14],r[18],'*');
goto P_0c05188e;
P_0c05188e: /* original 6373, guest PC 0x0c05188e */
if(!s->budget--) { s->failed_pc=0x0c05188eu; return 0; }
r[3]=r[7];
goto P_0c051890;
P_0c051890: /* original 4319, guest PC 0x0c051890 */
if(!s->budget--) { s->failed_pc=0x0c051890u; return 0; }
r[3]>>=8;
goto P_0c051892;
P_0c051892: /* original 2319, guest PC 0x0c051892 */
if(!s->budget--) { s->failed_pc=0x0c051892u; return 0; }
r[3]&=r[1];
goto P_0c051894;
P_0c051894: /* original 435a, guest PC 0x0c051894 */
if(!s->budget--) { s->failed_pc=0x0c051894u; return 0; }
r[53]=r[3];
goto P_0c051896;
P_0c051896: /* original fb2d, guest PC 0x0c051896 */
if(!s->budget--) { s->failed_pc=0x0c051896u; return 0; }
fr[11]=vf3_fpu_float(r[53],r[18]);
goto P_0c051898;
P_0c051898: /* original fbe2, guest PC 0x0c051898 */
if(!s->budget--) { s->failed_pc=0x0c051898u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[14],r[18],'*');
goto P_0c05189a;
P_0c05189a: /* original 6373, guest PC 0x0c05189a */
if(!s->budget--) { s->failed_pc=0x0c05189au; return 0; }
r[3]=r[7];
goto P_0c05189c;
P_0c05189c: /* original 4329, guest PC 0x0c05189c */
if(!s->budget--) { s->failed_pc=0x0c05189cu; return 0; }
r[3]>>=16;
goto P_0c05189e;
P_0c05189e: /* original 2319, guest PC 0x0c05189e */
if(!s->budget--) { s->failed_pc=0x0c05189eu; return 0; }
r[3]&=r[1];
goto P_0c0518a0;
P_0c0518a0: /* original 435a, guest PC 0x0c0518a0 */
if(!s->budget--) { s->failed_pc=0x0c0518a0u; return 0; }
r[53]=r[3];
goto P_0c0518a2;
P_0c0518a2: /* original fc2d, guest PC 0x0c0518a2 */
if(!s->budget--) { s->failed_pc=0x0c0518a2u; return 0; }
fr[12]=vf3_fpu_float(r[53],r[18]);
goto P_0c0518a4;
P_0c0518a4: /* original fce2, guest PC 0x0c0518a4 */
if(!s->budget--) { s->failed_pc=0x0c0518a4u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[14],r[18],'*');
goto P_0c0518a6;
P_0c0518a6: /* original f0d2, guest PC 0x0c0518a6 */
if(!s->budget--) { s->failed_pc=0x0c0518a6u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[13],r[18],'*');
goto P_0c0518a8;
P_0c0518a8: /* original f1d2, guest PC 0x0c0518a8 */
if(!s->budget--) { s->failed_pc=0x0c0518a8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[13],r[18],'*');
goto P_0c0518aa;
P_0c0518aa: /* original f2d2, guest PC 0x0c0518aa */
if(!s->budget--) { s->failed_pc=0x0c0518aau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[13],r[18],'*');
goto P_0c0518ac;
P_0c0518ac: /* original f3d2, guest PC 0x0c0518ac */
if(!s->budget--) { s->failed_pc=0x0c0518acu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[13],r[18],'*');
goto P_0c0518ae;
P_0c0518ae: /* original 4729, guest PC 0x0c0518ae */
if(!s->budget--) { s->failed_pc=0x0c0518aeu; return 0; }
r[7]>>=16;
goto P_0c0518b0;
P_0c0518b0: /* original 4719, guest PC 0x0c0518b0 */
if(!s->budget--) { s->failed_pc=0x0c0518b0u; return 0; }
r[7]>>=8;
goto P_0c0518b2;
P_0c0518b2: /* original 2719, guest PC 0x0c0518b2 */
if(!s->budget--) { s->failed_pc=0x0c0518b2u; return 0; }
r[7]&=r[1];
goto P_0c0518b4;
P_0c0518b4: /* original 475a, guest PC 0x0c0518b4 */
if(!s->budget--) { s->failed_pc=0x0c0518b4u; return 0; }
r[53]=r[7];
goto P_0c0518b6;
P_0c0518b6: /* original fd2d, guest PC 0x0c0518b6 */
if(!s->budget--) { s->failed_pc=0x0c0518b6u; return 0; }
fr[13]=vf3_fpu_float(r[53],r[18]);
goto P_0c0518b8;
P_0c0518b8: /* original fed2, guest PC 0x0c0518b8 */
if(!s->budget--) { s->failed_pc=0x0c0518b8u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[13],r[18],'*');
goto P_0c0518ba;
P_0c0518ba: /* original fa72, guest PC 0x0c0518ba */
if(!s->budget--) { s->failed_pc=0x0c0518bau; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[7],r[18],'*');
goto P_0c0518bc;
P_0c0518bc: /* original fb72, guest PC 0x0c0518bc */
if(!s->budget--) { s->failed_pc=0x0c0518bcu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[7],r[18],'*');
goto P_0c0518be;
P_0c0518be: /* original fc72, guest PC 0x0c0518be */
if(!s->budget--) { s->failed_pc=0x0c0518beu; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[7],r[18],'*');
goto P_0c0518c0;
P_0c0518c0: /* original fe72, guest PC 0x0c0518c0 */
if(!s->budget--) { s->failed_pc=0x0c0518c0u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[7],r[18],'*');
goto P_0c0518c2;
P_0c0518c2: /* original f0a0, guest PC 0x0c0518c2 */
if(!s->budget--) { s->failed_pc=0x0c0518c2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[10],r[18],'+');
goto P_0c0518c4;
P_0c0518c4: /* original f1b0, guest PC 0x0c0518c4 */
if(!s->budget--) { s->failed_pc=0x0c0518c4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[11],r[18],'+');
goto P_0c0518c6;
P_0c0518c6: /* original f2c0, guest PC 0x0c0518c6 */
if(!s->budget--) { s->failed_pc=0x0c0518c6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[12],r[18],'+');
goto P_0c0518c8;
P_0c0518c8: /* original f3e0, guest PC 0x0c0518c8 */
if(!s->budget--) { s->failed_pc=0x0c0518c8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'+');
goto P_0c0518ca;
P_0c0518ca: /* original fa09, guest PC 0x0c0518ca */
if(!s->budget--) { s->failed_pc=0x0c0518cau; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c0518cc;
P_0c0518cc: /* original f0a2, guest PC 0x0c0518cc */
if(!s->budget--) { s->failed_pc=0x0c0518ccu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[10],r[18],'*');
goto P_0c0518ce;
P_0c0518ce: /* original f03d, guest PC 0x0c0518ce */
if(!s->budget--) { s->failed_pc=0x0c0518ceu; return 0; }
r[53]=truncate_float(fr[0]);
goto P_0c0518d0;
P_0c0518d0: /* original 035a, guest PC 0x0c0518d0 */
if(!s->budget--) { s->failed_pc=0x0c0518d0u; return 0; }
r[3]=r[53];
goto P_0c0518d2;
P_0c0518d2: /* original f1a2, guest PC 0x0c0518d2 */
if(!s->budget--) { s->failed_pc=0x0c0518d2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[10],r[18],'*');
goto P_0c0518d4;
P_0c0518d4: /* original 2319, guest PC 0x0c0518d4 */
if(!s->budget--) { s->failed_pc=0x0c0518d4u; return 0; }
r[3]&=r[1];
goto P_0c0518d6;
P_0c0518d6: /* original f13d, guest PC 0x0c0518d6 */
if(!s->budget--) { s->failed_pc=0x0c0518d6u; return 0; }
r[53]=truncate_float(fr[1]);
goto P_0c0518d8;
P_0c0518d8: /* original 055a, guest PC 0x0c0518d8 */
if(!s->budget--) { s->failed_pc=0x0c0518d8u; return 0; }
r[5]=r[53];
goto P_0c0518da;
P_0c0518da: /* original f2a2, guest PC 0x0c0518da */
if(!s->budget--) { s->failed_pc=0x0c0518dau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c0518dc;
P_0c0518dc: /* original 2519, guest PC 0x0c0518dc */
if(!s->budget--) { s->failed_pc=0x0c0518dcu; return 0; }
r[5]&=r[1];
goto P_0c0518de;
P_0c0518de: /* original f23d, guest PC 0x0c0518de */
if(!s->budget--) { s->failed_pc=0x0c0518deu; return 0; }
r[53]=truncate_float(fr[2]);
goto P_0c0518e0;
P_0c0518e0: /* original 065a, guest PC 0x0c0518e0 */
if(!s->budget--) { s->failed_pc=0x0c0518e0u; return 0; }
r[6]=r[53];
goto P_0c0518e2;
P_0c0518e2: /* original f3a2, guest PC 0x0c0518e2 */
if(!s->budget--) { s->failed_pc=0x0c0518e2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[10],r[18],'*');
goto P_0c0518e4;
P_0c0518e4: /* original 2619, guest PC 0x0c0518e4 */
if(!s->budget--) { s->failed_pc=0x0c0518e4u; return 0; }
r[6]&=r[1];
goto P_0c0518e6;
P_0c0518e6: /* original f33d, guest PC 0x0c0518e6 */
if(!s->budget--) { s->failed_pc=0x0c0518e6u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0518e8;
P_0c0518e8: /* original 075a, guest PC 0x0c0518e8 */
if(!s->budget--) { s->failed_pc=0x0c0518e8u; return 0; }
r[7]=r[53];
goto P_0c0518ea;
P_0c0518ea: /* original 2719, guest PC 0x0c0518ea */
if(!s->budget--) { s->failed_pc=0x0c0518eau; return 0; }
r[7]&=r[1];
goto P_0c0518ec;
P_0c0518ec: /* original 4728, guest PC 0x0c0518ec */
if(!s->budget--) { s->failed_pc=0x0c0518ecu; return 0; }
r[7]<<=16;
goto P_0c0518ee;
P_0c0518ee: /* original 4718, guest PC 0x0c0518ee */
if(!s->budget--) { s->failed_pc=0x0c0518eeu; return 0; }
r[7]<<=8;
goto P_0c0518f0;
P_0c0518f0: /* original 4628, guest PC 0x0c0518f0 */
if(!s->budget--) { s->failed_pc=0x0c0518f0u; return 0; }
r[6]<<=16;
goto P_0c0518f2;
P_0c0518f2: /* original 4518, guest PC 0x0c0518f2 */
if(!s->budget--) { s->failed_pc=0x0c0518f2u; return 0; }
r[5]<<=8;
goto P_0c0518f4;
P_0c0518f4: /* original 257b, guest PC 0x0c0518f4 */
if(!s->budget--) { s->failed_pc=0x0c0518f4u; return 0; }
r[5]|=r[7];
goto P_0c0518f6;
P_0c0518f6: /* original 256b, guest PC 0x0c0518f6 */
if(!s->budget--) { s->failed_pc=0x0c0518f6u; return 0; }
r[5]|=r[6];
goto P_0c0518f8;
P_0c0518f8: /* original 253b, guest PC 0x0c0518f8 */
if(!s->budget--) { s->failed_pc=0x0c0518f8u; return 0; }
r[5]|=r[3];
goto P_0c0518fa;
P_0c0518fa: /* original 000b, guest PC 0x0c0518fa */
if(!s->budget--) { s->failed_pc=0x0c0518fau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0518fc: /* original 0009, guest PC 0x0c0518fc */
if(!s->budget--) { s->failed_pc=0x0c0518fcu; return 0; }
return vf3_matrix_family(0x0c0518feu,s,ram);
P_0c051e4c: /* original d007, guest PC 0x0c051e4c */
if(!s->budget--) { s->failed_pc=0x0c051e4cu; return 0; }
r[0]=read(ram,0x0c051e6cu,4);
goto P_0c051e4e;
P_0c051e4e: /* original 6002, guest PC 0x0c051e4e */
if(!s->budget--) { s->failed_pc=0x0c051e4eu; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c051e50;
P_0c051e50: /* original 2008, guest PC 0x0c051e50 */
if(!s->budget--) { s->failed_pc=0x0c051e50u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c051e52;
P_0c051e52: /* original 8b0d, guest PC 0x0c051e52 */
if(!s->budget--) { s->failed_pc=0x0c051e52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c051e70; }
goto P_0c051e54;
P_0c051e54: /* original 7c1c, guest PC 0x0c051e54 */
if(!s->budget--) { s->failed_pc=0x0c051e54u; return 0; }
r[12]+=0x0000001cu;
goto P_0c051e56;
P_0c051e56: /* original 2c56, guest PC 0x0c051e56 */
if(!s->budget--) { s->failed_pc=0x0c051e56u; return 0; }
r[12]-=4; write(ram,r[12],r[5],4);
goto P_0c051e58;
P_0c051e58: /* original fc9b, guest PC 0x0c051e58 */
if(!s->budget--) { s->failed_pc=0x0c051e58u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c051e5a;
P_0c051e5a: /* original fc8b, guest PC 0x0c051e5a */
if(!s->budget--) { s->failed_pc=0x0c051e5au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c051e5c;
P_0c051e5c: /* original fc6b, guest PC 0x0c051e5c */
if(!s->budget--) { s->failed_pc=0x0c051e5cu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c051e5e;
P_0c051e5e: /* original fc5b, guest PC 0x0c051e5e */
if(!s->budget--) { s->failed_pc=0x0c051e5eu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c051e60;
P_0c051e60: /* original fc4b, guest PC 0x0c051e60 */
if(!s->budget--) { s->failed_pc=0x0c051e60u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c051e62;
P_0c051e62: /* original 2c46, guest PC 0x0c051e62 */
if(!s->budget--) { s->failed_pc=0x0c051e62u; return 0; }
r[12]-=4; write(ram,r[12],r[4],4);
goto P_0c051e64;
P_0c051e64: /* original 0c83, guest PC 0x0c051e64 */
if(!s->budget--) { s->failed_pc=0x0c051e64u; return 0; }
goto P_0c051e66;
P_0c051e66: /* original 000b, guest PC 0x0c051e66 */
if(!s->budget--) { s->failed_pc=0x0c051e66u; return 0; }
target=r[16];
r[12]+=0x00000020u;
s->pc=target; return ram->oob==0;
P_0c051e68: /* original 7c20, guest PC 0x0c051e68 */
if(!s->budget--) { s->failed_pc=0x0c051e68u; return 0; }
r[12]+=0x00000020u;
return vf3_matrix_family(0x0c051e6au,s,ram);
P_0c051e70: /* original d136, guest PC 0x0c051e70 */
if(!s->budget--) { s->failed_pc=0x0c051e70u; return 0; }
r[1]=read(ram,0x0c051f4cu,4);
goto P_0c051e72;
P_0c051e72: /* original f018, guest PC 0x0c051e72 */
if(!s->budget--) { s->failed_pc=0x0c051e72u; return 0; }
vf3_matrix_load(s,ram,0,r[1]);
goto P_0c051e74;
P_0c051e74: /* original d109, guest PC 0x0c051e74 */
if(!s->budget--) { s->failed_pc=0x0c051e74u; return 0; }
r[1]=read(ram,0x0c051e9cu,4);
goto P_0c051e76;
P_0c051e76: /* original f218, guest PC 0x0c051e76 */
if(!s->budget--) { s->failed_pc=0x0c051e76u; return 0; }
vf3_matrix_load(s,ram,2,r[1]);
goto P_0c051e78;
P_0c051e78: /* original f022, guest PC 0x0c051e78 */
if(!s->budget--) { s->failed_pc=0x0c051e78u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'*');
goto P_0c051e7a;
P_0c051e7a: /* original f03d, guest PC 0x0c051e7a */
if(!s->budget--) { s->failed_pc=0x0c051e7au; return 0; }
r[53]=truncate_float(fr[0]);
goto P_0c051e7c;
P_0c051e7c: /* original 015a, guest PC 0x0c051e7c */
if(!s->budget--) { s->failed_pc=0x0c051e7cu; return 0; }
r[1]=r[53];
goto P_0c051e7e;
P_0c051e7e: /* original 4128, guest PC 0x0c051e7e */
if(!s->budget--) { s->failed_pc=0x0c051e7eu; return 0; }
r[1]<<=16;
goto P_0c051e80;
P_0c051e80: /* original 4118, guest PC 0x0c051e80 */
if(!s->budget--) { s->failed_pc=0x0c051e80u; return 0; }
r[1]<<=8;
goto P_0c051e82;
P_0c051e82: /* original 251b, guest PC 0x0c051e82 */
if(!s->budget--) { s->failed_pc=0x0c051e82u; return 0; }
r[5]|=r[1];
goto P_0c051e84;
P_0c051e84: /* original 7c1c, guest PC 0x0c051e84 */
if(!s->budget--) { s->failed_pc=0x0c051e84u; return 0; }
r[12]+=0x0000001cu;
goto P_0c051e86;
P_0c051e86: /* original 2c56, guest PC 0x0c051e86 */
if(!s->budget--) { s->failed_pc=0x0c051e86u; return 0; }
r[12]-=4; write(ram,r[12],r[5],4);
goto P_0c051e88;
P_0c051e88: /* original fc9b, guest PC 0x0c051e88 */
if(!s->budget--) { s->failed_pc=0x0c051e88u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c051e8a;
P_0c051e8a: /* original fc8b, guest PC 0x0c051e8a */
if(!s->budget--) { s->failed_pc=0x0c051e8au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c051e8c;
P_0c051e8c: /* original fc6b, guest PC 0x0c051e8c */
if(!s->budget--) { s->failed_pc=0x0c051e8cu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c051e8e;
P_0c051e8e: /* original fc5b, guest PC 0x0c051e8e */
if(!s->budget--) { s->failed_pc=0x0c051e8eu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c051e90;
P_0c051e90: /* original fc4b, guest PC 0x0c051e90 */
if(!s->budget--) { s->failed_pc=0x0c051e90u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c051e92;
P_0c051e92: /* original 2c46, guest PC 0x0c051e92 */
if(!s->budget--) { s->failed_pc=0x0c051e92u; return 0; }
r[12]-=4; write(ram,r[12],r[4],4);
goto P_0c051e94;
P_0c051e94: /* original 0c83, guest PC 0x0c051e94 */
if(!s->budget--) { s->failed_pc=0x0c051e94u; return 0; }
goto P_0c051e96;
P_0c051e96: /* original 000b, guest PC 0x0c051e96 */
if(!s->budget--) { s->failed_pc=0x0c051e96u; return 0; }
target=r[16];
r[12]+=0x00000020u;
s->pc=target; return ram->oob==0;
P_0c051e98: /* original 7c20, guest PC 0x0c051e98 */
if(!s->budget--) { s->failed_pc=0x0c051e98u; return 0; }
r[12]+=0x00000020u;
return vf3_matrix_family(0x0c051e9au,s,ram);
P_0c051eca: /* original 4f22, guest PC 0x0c051eca */
if(!s->budget--) { s->failed_pc=0x0c051ecau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c051ecc;
P_0c051ecc: /* original 08ee, guest PC 0x0c051ecc */
if(!s->budget--) { s->failed_pc=0x0c051eccu; return 0; }
r[8]=read(ram,r[14]+r[0],4);
goto P_0c051ece;
P_0c051ece: /* original 6681, guest PC 0x0c051ece */
if(!s->budget--) { s->failed_pc=0x0c051eceu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[6]=tmp;
goto P_0c051ed0;
P_0c051ed0: /* original d01a, guest PC 0x0c051ed0 */
if(!s->budget--) { s->failed_pc=0x0c051ed0u; return 0; }
r[0]=read(ram,0x0c051f3cu,4);
goto P_0c051ed2;
P_0c051ed2: /* original 4608, guest PC 0x0c051ed2 */
if(!s->budget--) { s->failed_pc=0x0c051ed2u; return 0; }
r[6]<<=2;
goto P_0c051ed4;
P_0c051ed4: /* original 6002, guest PC 0x0c051ed4 */
if(!s->budget--) { s->failed_pc=0x0c051ed4u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c051ed6;
P_0c051ed6: /* original 4600, guest PC 0x0c051ed6 */
if(!s->budget--) { s->failed_pc=0x0c051ed6u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c051ed8;
P_0c051ed8: /* original 066e, guest PC 0x0c051ed8 */
if(!s->budget--) { s->failed_pc=0x0c051ed8u; return 0; }
r[6]=read(ram,r[6]+r[0],4);
goto P_0c051eda;
P_0c051eda: /* original 8581, guest PC 0x0c051eda */
if(!s->budget--) { s->failed_pc=0x0c051edau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+2,2);
goto P_0c051edc;
P_0c051edc: /* original 405a, guest PC 0x0c051edc */
if(!s->budget--) { s->failed_pc=0x0c051edcu; return 0; }
r[53]=r[0];
goto P_0c051ede;
P_0c051ede: /* original f02d, guest PC 0x0c051ede */
if(!s->budget--) { s->failed_pc=0x0c051edeu; return 0; }
fr[0]=vf3_fpu_float(r[53],r[18]);
goto P_0c051ee0;
P_0c051ee0: /* original f0f2, guest PC 0x0c051ee0 */
if(!s->budget--) { s->failed_pc=0x0c051ee0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c051ee2;
P_0c051ee2: /* original 8582, guest PC 0x0c051ee2 */
if(!s->budget--) { s->failed_pc=0x0c051ee2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+4,2);
goto P_0c051ee4;
P_0c051ee4: /* original 405a, guest PC 0x0c051ee4 */
if(!s->budget--) { s->failed_pc=0x0c051ee4u; return 0; }
r[53]=r[0];
goto P_0c051ee6;
P_0c051ee6: /* original f12d, guest PC 0x0c051ee6 */
if(!s->budget--) { s->failed_pc=0x0c051ee6u; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c051ee8;
P_0c051ee8: /* original f1f2, guest PC 0x0c051ee8 */
if(!s->budget--) { s->failed_pc=0x0c051ee8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[15],r[18],'*');
goto P_0c051eea;
P_0c051eea: /* original 31ec, guest PC 0x0c051eea */
if(!s->budget--) { s->failed_pc=0x0c051eeau; return 0; }
r[1]+=r[14];
goto P_0c051eec;
P_0c051eec: /* original f419, guest PC 0x0c051eec */
if(!s->budget--) { s->failed_pc=0x0c051eecu; return 0; }
vf3_matrix_load(s,ram,4,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c051eee;
P_0c051eee: /* original f519, guest PC 0x0c051eee */
if(!s->budget--) { s->failed_pc=0x0c051eeeu; return 0; }
vf3_matrix_load(s,ram,5,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c051ef0;
P_0c051ef0: /* original f619, guest PC 0x0c051ef0 */
if(!s->budget--) { s->failed_pc=0x0c051ef0u; return 0; }
vf3_matrix_load(s,ram,6,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c051ef2;
P_0c051ef2: /* original 6023, guest PC 0x0c051ef2 */
if(!s->budget--) { s->failed_pc=0x0c051ef2u; return 0; }
r[0]=r[2];
goto P_0c051ef4;
P_0c051ef4: /* original 08ee, guest PC 0x0c051ef4 */
if(!s->budget--) { s->failed_pc=0x0c051ef4u; return 0; }
r[8]=read(ram,r[14]+r[0],4);
goto P_0c051ef6;
P_0c051ef6: /* original 6781, guest PC 0x0c051ef6 */
if(!s->budget--) { s->failed_pc=0x0c051ef6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[7]=tmp;
goto P_0c051ef8;
P_0c051ef8: /* original d010, guest PC 0x0c051ef8 */
if(!s->budget--) { s->failed_pc=0x0c051ef8u; return 0; }
r[0]=read(ram,0x0c051f3cu,4);
goto P_0c051efa;
P_0c051efa: /* original 4708, guest PC 0x0c051efa */
if(!s->budget--) { s->failed_pc=0x0c051efau; return 0; }
r[7]<<=2;
goto P_0c051efc;
P_0c051efc: /* original 6002, guest PC 0x0c051efc */
if(!s->budget--) { s->failed_pc=0x0c051efcu; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c051efe;
P_0c051efe: /* original 4700, guest PC 0x0c051efe */
if(!s->budget--) { s->failed_pc=0x0c051efeu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c051f00;
P_0c051f00: /* original 077e, guest PC 0x0c051f00 */
if(!s->budget--) { s->failed_pc=0x0c051f00u; return 0; }
r[7]=read(ram,r[7]+r[0],4);
goto P_0c051f02;
P_0c051f02: /* original 8581, guest PC 0x0c051f02 */
if(!s->budget--) { s->failed_pc=0x0c051f02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+2,2);
goto P_0c051f04;
P_0c051f04: /* original 405a, guest PC 0x0c051f04 */
if(!s->budget--) { s->failed_pc=0x0c051f04u; return 0; }
r[53]=r[0];
goto P_0c051f06;
P_0c051f06: /* original fb2d, guest PC 0x0c051f06 */
if(!s->budget--) { s->failed_pc=0x0c051f06u; return 0; }
fr[11]=vf3_fpu_float(r[53],r[18]);
goto P_0c051f08;
P_0c051f08: /* original fbf2, guest PC 0x0c051f08 */
if(!s->budget--) { s->failed_pc=0x0c051f08u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[15],r[18],'*');
goto P_0c051f0a;
P_0c051f0a: /* original 8582, guest PC 0x0c051f0a */
if(!s->budget--) { s->failed_pc=0x0c051f0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+4,2);
goto P_0c051f0c;
P_0c051f0c: /* original 405a, guest PC 0x0c051f0c */
if(!s->budget--) { s->failed_pc=0x0c051f0cu; return 0; }
r[53]=r[0];
goto P_0c051f0e;
P_0c051f0e: /* original fc2d, guest PC 0x0c051f0e */
if(!s->budget--) { s->failed_pc=0x0c051f0eu; return 0; }
fr[12]=vf3_fpu_float(r[53],r[18]);
goto P_0c051f10;
P_0c051f10: /* original fcf2, guest PC 0x0c051f10 */
if(!s->budget--) { s->failed_pc=0x0c051f10u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[15],r[18],'*');
goto P_0c051f12;
P_0c051f12: /* original 33ec, guest PC 0x0c051f12 */
if(!s->budget--) { s->failed_pc=0x0c051f12u; return 0; }
r[3]+=r[14];
goto P_0c051f14;
P_0c051f14: /* original f839, guest PC 0x0c051f14 */
if(!s->budget--) { s->failed_pc=0x0c051f14u; return 0; }
vf3_matrix_load(s,ram,8,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c051f16;
P_0c051f16: /* original f939, guest PC 0x0c051f16 */
if(!s->budget--) { s->failed_pc=0x0c051f16u; return 0; }
vf3_matrix_load(s,ram,9,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c051f18;
P_0c051f18: /* original fa39, guest PC 0x0c051f18 */
if(!s->budget--) { s->failed_pc=0x0c051f18u; return 0; }
vf3_matrix_load(s,ram,10,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c051f1a;
P_0c051f1a: /* original c709, guest PC 0x0c051f1a */
if(!s->budget--) { s->failed_pc=0x0c051f1au; return 0; }
r[0]=0x0c051f40u;
goto P_0c051f1c;
P_0c051f1c: /* original 6002, guest PC 0x0c051f1c */
if(!s->budget--) { s->failed_pc=0x0c051f1cu; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c051f1e;
P_0c051f1e: /* original d105, guest PC 0x0c051f1e */
if(!s->budget--) { s->failed_pc=0x0c051f1eu; return 0; }
r[1]=read(ram,0x0c051f34u,4);
goto P_0c051f20;
P_0c051f20: /* original 410b, guest PC 0x0c051f20 */
if(!s->budget--) { s->failed_pc=0x0c051f20u; return 0; }
target=r[1];
r[16]=0x0c051f24u;
vf3_matrix_load(s,ram,3,r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c051f24u) { target=s->pc; goto dispatch; }
goto P_0c051f24;
P_0c051f22: /* original f308, guest PC 0x0c051f22 */
if(!s->budget--) { s->failed_pc=0x0c051f22u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c051f24;
P_0c051f24: /* original d004, guest PC 0x0c051f24 */
if(!s->budget--) { s->failed_pc=0x0c051f24u; return 0; }
r[0]=read(ram,0x0c051f38u,4);
goto P_0c051f26;
P_0c051f26: /* original 400b, guest PC 0x0c051f26 */
if(!s->budget--) { s->failed_pc=0x0c051f26u; return 0; }
target=r[0];
r[16]=0x0c051f2au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c051f2au) { target=s->pc; goto dispatch; }
goto P_0c051f2a;
P_0c051f28: /* original 0009, guest PC 0x0c051f28 */
if(!s->budget--) { s->failed_pc=0x0c051f28u; return 0; }
goto P_0c051f2a;
P_0c051f2a: /* original bf8f, guest PC 0x0c051f2a */
if(!s->budget--) { s->failed_pc=0x0c051f2au; return 0; }
target=0x0c051e4cu; r[16]=0x0c051f2eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c051f2eu) { target=s->pc; goto dispatch; }
goto P_0c051f2e;
P_0c051f2c: /* original 0009, guest PC 0x0c051f2c */
if(!s->budget--) { s->failed_pc=0x0c051f2cu; return 0; }
goto P_0c051f2e;
P_0c051f2e: /* original 4f26, guest PC 0x0c051f2e */
if(!s->budget--) { s->failed_pc=0x0c051f2eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c051f30;
P_0c051f30: /* original 000b, guest PC 0x0c051f30 */
if(!s->budget--) { s->failed_pc=0x0c051f30u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c051f32: /* original 0009, guest PC 0x0c051f32 */
if(!s->budget--) { s->failed_pc=0x0c051f32u; return 0; }
return vf3_matrix_family(0x0c051f34u,s,ram);
P_0c0524ac: /* original d00a, guest PC 0x0c0524ac */
if(!s->budget--) { s->failed_pc=0x0c0524acu; return 0; }
r[0]=read(ram,0x0c0524d8u,4);
goto P_0c0524ae;
P_0c0524ae: /* original 6002, guest PC 0x0c0524ae */
if(!s->budget--) { s->failed_pc=0x0c0524aeu; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c0524b0;
P_0c0524b0: /* original 2008, guest PC 0x0c0524b0 */
if(!s->budget--) { s->failed_pc=0x0c0524b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0524b2;
P_0c0524b2: /* original 8b13, guest PC 0x0c0524b2 */
if(!s->budget--) { s->failed_pc=0x0c0524b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0524dc; }
goto P_0c0524b4;
P_0c0524b4: /* original 7c1c, guest PC 0x0c0524b4 */
if(!s->budget--) { s->failed_pc=0x0c0524b4u; return 0; }
r[12]+=0x0000001cu;
goto P_0c0524b6;
P_0c0524b6: /* original f81d, guest PC 0x0c0524b6 */
if(!s->budget--) { s->failed_pc=0x0c0524b6u; return 0; }
r[53]=fr[8];
goto P_0c0524b8;
P_0c0524b8: /* original 005a, guest PC 0x0c0524b8 */
if(!s->budget--) { s->failed_pc=0x0c0524b8u; return 0; }
r[0]=r[53];
goto P_0c0524ba;
P_0c0524ba: /* original f91d, guest PC 0x0c0524ba */
if(!s->budget--) { s->failed_pc=0x0c0524bau; return 0; }
r[53]=fr[9];
goto P_0c0524bc;
P_0c0524bc: /* original 015a, guest PC 0x0c0524bc */
if(!s->budget--) { s->failed_pc=0x0c0524bcu; return 0; }
r[1]=r[53];
goto P_0c0524be;
P_0c0524be: /* original 4029, guest PC 0x0c0524be */
if(!s->budget--) { s->failed_pc=0x0c0524beu; return 0; }
r[0]>>=16;
goto P_0c0524c0;
P_0c0524c0: /* original 210d, guest PC 0x0c0524c0 */
if(!s->budget--) { s->failed_pc=0x0c0524c0u; return 0; }
r[1]=(r[1]>>16)|(r[0]<<16);
goto P_0c0524c2;
P_0c0524c2: /* original 2c56, guest PC 0x0c0524c2 */
if(!s->budget--) { s->failed_pc=0x0c0524c2u; return 0; }
r[12]-=4; write(ram,r[12],r[5],4);
goto P_0c0524c4;
P_0c0524c4: /* original 7cfc, guest PC 0x0c0524c4 */
if(!s->budget--) { s->failed_pc=0x0c0524c4u; return 0; }
r[12]+=0xfffffffcu;
goto P_0c0524c6;
P_0c0524c6: /* original 2c16, guest PC 0x0c0524c6 */
if(!s->budget--) { s->failed_pc=0x0c0524c6u; return 0; }
r[12]-=4; write(ram,r[12],r[1],4);
goto P_0c0524c8;
P_0c0524c8: /* original fc6b, guest PC 0x0c0524c8 */
if(!s->budget--) { s->failed_pc=0x0c0524c8u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c0524ca;
P_0c0524ca: /* original fc5b, guest PC 0x0c0524ca */
if(!s->budget--) { s->failed_pc=0x0c0524cau; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c0524cc;
P_0c0524cc: /* original fc4b, guest PC 0x0c0524cc */
if(!s->budget--) { s->failed_pc=0x0c0524ccu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c0524ce;
P_0c0524ce: /* original 2c46, guest PC 0x0c0524ce */
if(!s->budget--) { s->failed_pc=0x0c0524ceu; return 0; }
r[12]-=4; write(ram,r[12],r[4],4);
goto P_0c0524d0;
P_0c0524d0: /* original 0c83, guest PC 0x0c0524d0 */
if(!s->budget--) { s->failed_pc=0x0c0524d0u; return 0; }
goto P_0c0524d2;
P_0c0524d2: /* original 000b, guest PC 0x0c0524d2 */
if(!s->budget--) { s->failed_pc=0x0c0524d2u; return 0; }
target=r[16];
r[12]+=0x00000020u;
s->pc=target; return ram->oob==0;
P_0c0524d4: /* original 7c20, guest PC 0x0c0524d4 */
if(!s->budget--) { s->failed_pc=0x0c0524d4u; return 0; }
r[12]+=0x00000020u;
return vf3_matrix_family(0x0c0524d6u,s,ram);
P_0c0524dc: /* original d137, guest PC 0x0c0524dc */
if(!s->budget--) { s->failed_pc=0x0c0524dcu; return 0; }
r[1]=read(ram,0x0c0525bcu,4);
goto P_0c0524de;
P_0c0524de: /* original f018, guest PC 0x0c0524de */
if(!s->budget--) { s->failed_pc=0x0c0524deu; return 0; }
vf3_matrix_load(s,ram,0,r[1]);
goto P_0c0524e0;
P_0c0524e0: /* original d10c, guest PC 0x0c0524e0 */
if(!s->budget--) { s->failed_pc=0x0c0524e0u; return 0; }
r[1]=read(ram,0x0c052514u,4);
goto P_0c0524e2;
P_0c0524e2: /* original f218, guest PC 0x0c0524e2 */
if(!s->budget--) { s->failed_pc=0x0c0524e2u; return 0; }
vf3_matrix_load(s,ram,2,r[1]);
goto P_0c0524e4;
P_0c0524e4: /* original f022, guest PC 0x0c0524e4 */
if(!s->budget--) { s->failed_pc=0x0c0524e4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'*');
goto P_0c0524e6;
P_0c0524e6: /* original f03d, guest PC 0x0c0524e6 */
if(!s->budget--) { s->failed_pc=0x0c0524e6u; return 0; }
r[53]=truncate_float(fr[0]);
goto P_0c0524e8;
P_0c0524e8: /* original 015a, guest PC 0x0c0524e8 */
if(!s->budget--) { s->failed_pc=0x0c0524e8u; return 0; }
r[1]=r[53];
goto P_0c0524ea;
P_0c0524ea: /* original 4128, guest PC 0x0c0524ea */
if(!s->budget--) { s->failed_pc=0x0c0524eau; return 0; }
r[1]<<=16;
goto P_0c0524ec;
P_0c0524ec: /* original 4118, guest PC 0x0c0524ec */
if(!s->budget--) { s->failed_pc=0x0c0524ecu; return 0; }
r[1]<<=8;
goto P_0c0524ee;
P_0c0524ee: /* original 251b, guest PC 0x0c0524ee */
if(!s->budget--) { s->failed_pc=0x0c0524eeu; return 0; }
r[5]|=r[1];
goto P_0c0524f0;
P_0c0524f0: /* original 7c1c, guest PC 0x0c0524f0 */
if(!s->budget--) { s->failed_pc=0x0c0524f0u; return 0; }
r[12]+=0x0000001cu;
goto P_0c0524f2;
P_0c0524f2: /* original f81d, guest PC 0x0c0524f2 */
if(!s->budget--) { s->failed_pc=0x0c0524f2u; return 0; }
r[53]=fr[8];
goto P_0c0524f4;
P_0c0524f4: /* original 005a, guest PC 0x0c0524f4 */
if(!s->budget--) { s->failed_pc=0x0c0524f4u; return 0; }
r[0]=r[53];
goto P_0c0524f6;
P_0c0524f6: /* original f91d, guest PC 0x0c0524f6 */
if(!s->budget--) { s->failed_pc=0x0c0524f6u; return 0; }
r[53]=fr[9];
goto P_0c0524f8;
P_0c0524f8: /* original 015a, guest PC 0x0c0524f8 */
if(!s->budget--) { s->failed_pc=0x0c0524f8u; return 0; }
r[1]=r[53];
goto P_0c0524fa;
P_0c0524fa: /* original 4029, guest PC 0x0c0524fa */
if(!s->budget--) { s->failed_pc=0x0c0524fau; return 0; }
r[0]>>=16;
goto P_0c0524fc;
P_0c0524fc: /* original 210d, guest PC 0x0c0524fc */
if(!s->budget--) { s->failed_pc=0x0c0524fcu; return 0; }
r[1]=(r[1]>>16)|(r[0]<<16);
goto P_0c0524fe;
P_0c0524fe: /* original 2c56, guest PC 0x0c0524fe */
if(!s->budget--) { s->failed_pc=0x0c0524feu; return 0; }
r[12]-=4; write(ram,r[12],r[5],4);
goto P_0c052500;
P_0c052500: /* original 7cfc, guest PC 0x0c052500 */
if(!s->budget--) { s->failed_pc=0x0c052500u; return 0; }
r[12]+=0xfffffffcu;
goto P_0c052502;
P_0c052502: /* original 2c16, guest PC 0x0c052502 */
if(!s->budget--) { s->failed_pc=0x0c052502u; return 0; }
r[12]-=4; write(ram,r[12],r[1],4);
goto P_0c052504;
P_0c052504: /* original fc6b, guest PC 0x0c052504 */
if(!s->budget--) { s->failed_pc=0x0c052504u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c052506;
P_0c052506: /* original fc5b, guest PC 0x0c052506 */
if(!s->budget--) { s->failed_pc=0x0c052506u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c052508;
P_0c052508: /* original fc4b, guest PC 0x0c052508 */
if(!s->budget--) { s->failed_pc=0x0c052508u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c05250a;
P_0c05250a: /* original 2c46, guest PC 0x0c05250a */
if(!s->budget--) { s->failed_pc=0x0c05250au; return 0; }
r[12]-=4; write(ram,r[12],r[4],4);
goto P_0c05250c;
P_0c05250c: /* original 0c83, guest PC 0x0c05250c */
if(!s->budget--) { s->failed_pc=0x0c05250cu; return 0; }
goto P_0c05250e;
P_0c05250e: /* original 000b, guest PC 0x0c05250e */
if(!s->budget--) { s->failed_pc=0x0c05250eu; return 0; }
target=r[16];
r[12]+=0x00000020u;
s->pc=target; return ram->oob==0;
P_0c052510: /* original 7c20, guest PC 0x0c052510 */
if(!s->budget--) { s->failed_pc=0x0c052510u; return 0; }
r[12]+=0x00000020u;
return vf3_matrix_family(0x0c052512u,s,ram);
P_0c052540: /* original 4f22, guest PC 0x0c052540 */
if(!s->budget--) { s->failed_pc=0x0c052540u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c052542;
P_0c052542: /* original d51a, guest PC 0x0c052542 */
if(!s->budget--) { s->failed_pc=0x0c052542u; return 0; }
r[5]=read(ram,0x0c0525acu,4);
goto P_0c052544;
P_0c052544: /* original 08ee, guest PC 0x0c052544 */
if(!s->budget--) { s->failed_pc=0x0c052544u; return 0; }
r[8]=read(ram,r[14]+r[0],4);
goto P_0c052546;
P_0c052546: /* original 6081, guest PC 0x0c052546 */
if(!s->budget--) { s->failed_pc=0x0c052546u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[0]=tmp;
goto P_0c052548;
P_0c052548: /* original 4008, guest PC 0x0c052548 */
if(!s->budget--) { s->failed_pc=0x0c052548u; return 0; }
r[0]<<=2;
goto P_0c05254a;
P_0c05254a: /* original 6552, guest PC 0x0c05254a */
if(!s->budget--) { s->failed_pc=0x0c05254au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c05254c;
P_0c05254c: /* original 4000, guest PC 0x0c05254c */
if(!s->budget--) { s->failed_pc=0x0c05254cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c05254e;
P_0c05254e: /* original 065e, guest PC 0x0c05254e */
if(!s->budget--) { s->failed_pc=0x0c05254eu; return 0; }
r[6]=read(ram,r[5]+r[0],4);
goto P_0c052550;
P_0c052550: /* original 6023, guest PC 0x0c052550 */
if(!s->budget--) { s->failed_pc=0x0c052550u; return 0; }
r[0]=r[2];
goto P_0c052552;
P_0c052552: /* original 08ee, guest PC 0x0c052552 */
if(!s->budget--) { s->failed_pc=0x0c052552u; return 0; }
r[8]=read(ram,r[14]+r[0],4);
goto P_0c052554;
P_0c052554: /* original 6081, guest PC 0x0c052554 */
if(!s->budget--) { s->failed_pc=0x0c052554u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[0]=tmp;
goto P_0c052556;
P_0c052556: /* original 4008, guest PC 0x0c052556 */
if(!s->budget--) { s->failed_pc=0x0c052556u; return 0; }
r[0]<<=2;
goto P_0c052558;
P_0c052558: /* original 4000, guest PC 0x0c052558 */
if(!s->budget--) { s->failed_pc=0x0c052558u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c05255a;
P_0c05255a: /* original 075e, guest PC 0x0c05255a */
if(!s->budget--) { s->failed_pc=0x0c05255au; return 0; }
r[7]=read(ram,r[5]+r[0],4);
goto P_0c05255c;
P_0c05255c: /* original 31ec, guest PC 0x0c05255c */
if(!s->budget--) { s->failed_pc=0x0c05255cu; return 0; }
r[1]+=r[14];
goto P_0c05255e;
P_0c05255e: /* original f419, guest PC 0x0c05255e */
if(!s->budget--) { s->failed_pc=0x0c05255eu; return 0; }
vf3_matrix_load(s,ram,4,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c052560;
P_0c052560: /* original f519, guest PC 0x0c052560 */
if(!s->budget--) { s->failed_pc=0x0c052560u; return 0; }
vf3_matrix_load(s,ram,5,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c052562;
P_0c052562: /* original f619, guest PC 0x0c052562 */
if(!s->budget--) { s->failed_pc=0x0c052562u; return 0; }
vf3_matrix_load(s,ram,6,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c052564;
P_0c052564: /* original 6016, guest PC 0x0c052564 */
if(!s->budget--) { s->failed_pc=0x0c052564u; return 0; }
tmp=read(ram,r[1],4);
r[1]+=4;
r[0]=tmp;
goto P_0c052566;
P_0c052566: /* original 6103, guest PC 0x0c052566 */
if(!s->budget--) { s->failed_pc=0x0c052566u; return 0; }
r[1]=r[0];
goto P_0c052568;
P_0c052568: /* original 4128, guest PC 0x0c052568 */
if(!s->budget--) { s->failed_pc=0x0c052568u; return 0; }
r[1]<<=16;
goto P_0c05256a;
P_0c05256a: /* original 405a, guest PC 0x0c05256a */
if(!s->budget--) { s->failed_pc=0x0c05256au; return 0; }
r[53]=r[0];
goto P_0c05256c;
P_0c05256c: /* original f00d, guest PC 0x0c05256c */
if(!s->budget--) { s->failed_pc=0x0c05256cu; return 0; }
fr[0]=r[53];
goto P_0c05256e;
P_0c05256e: /* original 415a, guest PC 0x0c05256e */
if(!s->budget--) { s->failed_pc=0x0c05256eu; return 0; }
r[53]=r[1];
goto P_0c052570;
P_0c052570: /* original f10d, guest PC 0x0c052570 */
if(!s->budget--) { s->failed_pc=0x0c052570u; return 0; }
fr[1]=r[53];
goto P_0c052572;
P_0c052572: /* original 33ec, guest PC 0x0c052572 */
if(!s->budget--) { s->failed_pc=0x0c052572u; return 0; }
r[3]+=r[14];
goto P_0c052574;
P_0c052574: /* original f839, guest PC 0x0c052574 */
if(!s->budget--) { s->failed_pc=0x0c052574u; return 0; }
vf3_matrix_load(s,ram,8,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c052576;
P_0c052576: /* original f939, guest PC 0x0c052576 */
if(!s->budget--) { s->failed_pc=0x0c052576u; return 0; }
vf3_matrix_load(s,ram,9,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c052578;
P_0c052578: /* original fa39, guest PC 0x0c052578 */
if(!s->budget--) { s->failed_pc=0x0c052578u; return 0; }
vf3_matrix_load(s,ram,10,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c05257a;
P_0c05257a: /* original 6036, guest PC 0x0c05257a */
if(!s->budget--) { s->failed_pc=0x0c05257au; return 0; }
tmp=read(ram,r[3],4);
r[3]+=4;
r[0]=tmp;
goto P_0c05257c;
P_0c05257c: /* original 6103, guest PC 0x0c05257c */
if(!s->budget--) { s->failed_pc=0x0c05257cu; return 0; }
r[1]=r[0];
goto P_0c05257e;
P_0c05257e: /* original 4128, guest PC 0x0c05257e */
if(!s->budget--) { s->failed_pc=0x0c05257eu; return 0; }
r[1]<<=16;
goto P_0c052580;
P_0c052580: /* original 405a, guest PC 0x0c052580 */
if(!s->budget--) { s->failed_pc=0x0c052580u; return 0; }
r[53]=r[0];
goto P_0c052582;
P_0c052582: /* original fb0d, guest PC 0x0c052582 */
if(!s->budget--) { s->failed_pc=0x0c052582u; return 0; }
fr[11]=r[53];
goto P_0c052584;
P_0c052584: /* original 415a, guest PC 0x0c052584 */
if(!s->budget--) { s->failed_pc=0x0c052584u; return 0; }
r[53]=r[1];
goto P_0c052586;
P_0c052586: /* original fc0d, guest PC 0x0c052586 */
if(!s->budget--) { s->failed_pc=0x0c052586u; return 0; }
fr[12]=r[53];
goto P_0c052588;
P_0c052588: /* original c709, guest PC 0x0c052588 */
if(!s->budget--) { s->failed_pc=0x0c052588u; return 0; }
r[0]=0x0c0525b0u;
goto P_0c05258a;
P_0c05258a: /* original 6002, guest PC 0x0c05258a */
if(!s->budget--) { s->failed_pc=0x0c05258au; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c05258c;
P_0c05258c: /* original d105, guest PC 0x0c05258c */
if(!s->budget--) { s->failed_pc=0x0c05258cu; return 0; }
r[1]=read(ram,0x0c0525a4u,4);
goto P_0c05258e;
P_0c05258e: /* original 410b, guest PC 0x0c05258e */
if(!s->budget--) { s->failed_pc=0x0c05258eu; return 0; }
target=r[1];
r[16]=0x0c052592u;
vf3_matrix_load(s,ram,3,r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052592u) { target=s->pc; goto dispatch; }
goto P_0c052592;
P_0c052590: /* original f308, guest PC 0x0c052590 */
if(!s->budget--) { s->failed_pc=0x0c052590u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c052592;
P_0c052592: /* original d005, guest PC 0x0c052592 */
if(!s->budget--) { s->failed_pc=0x0c052592u; return 0; }
r[0]=read(ram,0x0c0525a8u,4);
goto P_0c052594;
P_0c052594: /* original 400b, guest PC 0x0c052594 */
if(!s->budget--) { s->failed_pc=0x0c052594u; return 0; }
target=r[0];
r[16]=0x0c052598u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052598u) { target=s->pc; goto dispatch; }
goto P_0c052598;
P_0c052596: /* original 0009, guest PC 0x0c052596 */
if(!s->budget--) { s->failed_pc=0x0c052596u; return 0; }
goto P_0c052598;
P_0c052598: /* original bf88, guest PC 0x0c052598 */
if(!s->budget--) { s->failed_pc=0x0c052598u; return 0; }
target=0x0c0524acu; r[16]=0x0c05259cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05259cu) { target=s->pc; goto dispatch; }
goto P_0c05259c;
P_0c05259a: /* original 0009, guest PC 0x0c05259a */
if(!s->budget--) { s->failed_pc=0x0c05259au; return 0; }
goto P_0c05259c;
P_0c05259c: /* original 4f26, guest PC 0x0c05259c */
if(!s->budget--) { s->failed_pc=0x0c05259cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05259e;
P_0c05259e: /* original 000b, guest PC 0x0c05259e */
if(!s->budget--) { s->failed_pc=0x0c05259eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0525a0: /* original 0009, guest PC 0x0c0525a0 */
if(!s->budget--) { s->failed_pc=0x0c0525a0u; return 0; }
return vf3_matrix_family(0x0c0525a2u,s,ram);
P_0c052b3c: /* original d007, guest PC 0x0c052b3c */
if(!s->budget--) { s->failed_pc=0x0c052b3cu; return 0; }
r[0]=read(ram,0x0c052b5cu,4);
goto P_0c052b3e;
P_0c052b3e: /* original 6002, guest PC 0x0c052b3e */
if(!s->budget--) { s->failed_pc=0x0c052b3eu; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c052b40;
P_0c052b40: /* original 2008, guest PC 0x0c052b40 */
if(!s->budget--) { s->failed_pc=0x0c052b40u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c052b42;
P_0c052b42: /* original 8b0d, guest PC 0x0c052b42 */
if(!s->budget--) { s->failed_pc=0x0c052b42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c052b60; }
goto P_0c052b44;
P_0c052b44: /* original 7c1c, guest PC 0x0c052b44 */
if(!s->budget--) { s->failed_pc=0x0c052b44u; return 0; }
r[12]+=0x0000001cu;
goto P_0c052b46;
P_0c052b46: /* original 2c56, guest PC 0x0c052b46 */
if(!s->budget--) { s->failed_pc=0x0c052b46u; return 0; }
r[12]-=4; write(ram,r[12],r[5],4);
goto P_0c052b48;
P_0c052b48: /* original fc9b, guest PC 0x0c052b48 */
if(!s->budget--) { s->failed_pc=0x0c052b48u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c052b4a;
P_0c052b4a: /* original fc8b, guest PC 0x0c052b4a */
if(!s->budget--) { s->failed_pc=0x0c052b4au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c052b4c;
P_0c052b4c: /* original fc6b, guest PC 0x0c052b4c */
if(!s->budget--) { s->failed_pc=0x0c052b4cu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c052b4e;
P_0c052b4e: /* original fc5b, guest PC 0x0c052b4e */
if(!s->budget--) { s->failed_pc=0x0c052b4eu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c052b50;
P_0c052b50: /* original fc4b, guest PC 0x0c052b50 */
if(!s->budget--) { s->failed_pc=0x0c052b50u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c052b52;
P_0c052b52: /* original 2c46, guest PC 0x0c052b52 */
if(!s->budget--) { s->failed_pc=0x0c052b52u; return 0; }
r[12]-=4; write(ram,r[12],r[4],4);
goto P_0c052b54;
P_0c052b54: /* original 0c83, guest PC 0x0c052b54 */
if(!s->budget--) { s->failed_pc=0x0c052b54u; return 0; }
goto P_0c052b56;
P_0c052b56: /* original 000b, guest PC 0x0c052b56 */
if(!s->budget--) { s->failed_pc=0x0c052b56u; return 0; }
target=r[16];
r[12]+=0x00000020u;
s->pc=target; return ram->oob==0;
P_0c052b58: /* original 7c20, guest PC 0x0c052b58 */
if(!s->budget--) { s->failed_pc=0x0c052b58u; return 0; }
r[12]+=0x00000020u;
return vf3_matrix_family(0x0c052b5au,s,ram);
P_0c052b60: /* original d10b, guest PC 0x0c052b60 */
if(!s->budget--) { s->failed_pc=0x0c052b60u; return 0; }
r[1]=read(ram,0x0c052b90u,4);
goto P_0c052b62;
P_0c052b62: /* original 6112, guest PC 0x0c052b62 */
if(!s->budget--) { s->failed_pc=0x0c052b62u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c052b64;
P_0c052b64: /* original 6253, guest PC 0x0c052b64 */
if(!s->budget--) { s->failed_pc=0x0c052b64u; return 0; }
r[2]=r[5];
goto P_0c052b66;
P_0c052b66: /* original 4229, guest PC 0x0c052b66 */
if(!s->budget--) { s->failed_pc=0x0c052b66u; return 0; }
r[2]>>=16;
goto P_0c052b68;
P_0c052b68: /* original 4219, guest PC 0x0c052b68 */
if(!s->budget--) { s->failed_pc=0x0c052b68u; return 0; }
r[2]>>=8;
goto P_0c052b6a;
P_0c052b6a: /* original 221e, guest PC 0x0c052b6a */
if(!s->budget--) { s->failed_pc=0x0c052b6au; return 0; }
r[19]=(r[2]&65535u)*(r[1]&65535u);
goto P_0c052b6c;
P_0c052b6c: /* original 021a, guest PC 0x0c052b6c */
if(!s->budget--) { s->failed_pc=0x0c052b6cu; return 0; }
r[2]=r[19];
goto P_0c052b6e;
P_0c052b6e: /* original 4219, guest PC 0x0c052b6e */
if(!s->budget--) { s->failed_pc=0x0c052b6eu; return 0; }
r[2]>>=8;
goto P_0c052b70;
P_0c052b70: /* original 4218, guest PC 0x0c052b70 */
if(!s->budget--) { s->failed_pc=0x0c052b70u; return 0; }
r[2]<<=8;
goto P_0c052b72;
P_0c052b72: /* original 4228, guest PC 0x0c052b72 */
if(!s->budget--) { s->failed_pc=0x0c052b72u; return 0; }
r[2]<<=16;
goto P_0c052b74;
P_0c052b74: /* original 4518, guest PC 0x0c052b74 */
if(!s->budget--) { s->failed_pc=0x0c052b74u; return 0; }
r[5]<<=8;
goto P_0c052b76;
P_0c052b76: /* original 4519, guest PC 0x0c052b76 */
if(!s->budget--) { s->failed_pc=0x0c052b76u; return 0; }
r[5]>>=8;
goto P_0c052b78;
P_0c052b78: /* original 252b, guest PC 0x0c052b78 */
if(!s->budget--) { s->failed_pc=0x0c052b78u; return 0; }
r[5]|=r[2];
goto P_0c052b7a;
P_0c052b7a: /* original 7c1c, guest PC 0x0c052b7a */
if(!s->budget--) { s->failed_pc=0x0c052b7au; return 0; }
r[12]+=0x0000001cu;
goto P_0c052b7c;
P_0c052b7c: /* original 2c56, guest PC 0x0c052b7c */
if(!s->budget--) { s->failed_pc=0x0c052b7cu; return 0; }
r[12]-=4; write(ram,r[12],r[5],4);
goto P_0c052b7e;
P_0c052b7e: /* original fc9b, guest PC 0x0c052b7e */
if(!s->budget--) { s->failed_pc=0x0c052b7eu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c052b80;
P_0c052b80: /* original fc8b, guest PC 0x0c052b80 */
if(!s->budget--) { s->failed_pc=0x0c052b80u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c052b82;
P_0c052b82: /* original fc6b, guest PC 0x0c052b82 */
if(!s->budget--) { s->failed_pc=0x0c052b82u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c052b84;
P_0c052b84: /* original fc5b, guest PC 0x0c052b84 */
if(!s->budget--) { s->failed_pc=0x0c052b84u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c052b86;
P_0c052b86: /* original fc4b, guest PC 0x0c052b86 */
if(!s->budget--) { s->failed_pc=0x0c052b86u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c052b88;
P_0c052b88: /* original 2c46, guest PC 0x0c052b88 */
if(!s->budget--) { s->failed_pc=0x0c052b88u; return 0; }
r[12]-=4; write(ram,r[12],r[4],4);
goto P_0c052b8a;
P_0c052b8a: /* original 0c83, guest PC 0x0c052b8a */
if(!s->budget--) { s->failed_pc=0x0c052b8au; return 0; }
goto P_0c052b8c;
P_0c052b8c: /* original 000b, guest PC 0x0c052b8c */
if(!s->budget--) { s->failed_pc=0x0c052b8cu; return 0; }
target=r[16];
r[12]+=0x00000020u;
s->pc=target; return ram->oob==0;
P_0c052b8e: /* original 7c20, guest PC 0x0c052b8e */
if(!s->budget--) { s->failed_pc=0x0c052b8eu; return 0; }
r[12]+=0x00000020u;
return vf3_matrix_family(0x0c052b90u,s,ram);
P_0c052bba: /* original 4f22, guest PC 0x0c052bba */
if(!s->budget--) { s->failed_pc=0x0c052bbau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c052bbc;
P_0c052bbc: /* original 08ee, guest PC 0x0c052bbc */
if(!s->budget--) { s->failed_pc=0x0c052bbcu; return 0; }
r[8]=read(ram,r[14]+r[0],4);
goto P_0c052bbe;
P_0c052bbe: /* original 8581, guest PC 0x0c052bbe */
if(!s->budget--) { s->failed_pc=0x0c052bbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+2,2);
goto P_0c052bc0;
P_0c052bc0: /* original 405a, guest PC 0x0c052bc0 */
if(!s->budget--) { s->failed_pc=0x0c052bc0u; return 0; }
r[53]=r[0];
goto P_0c052bc2;
P_0c052bc2: /* original f02d, guest PC 0x0c052bc2 */
if(!s->budget--) { s->failed_pc=0x0c052bc2u; return 0; }
fr[0]=vf3_fpu_float(r[53],r[18]);
goto P_0c052bc4;
P_0c052bc4: /* original f0f2, guest PC 0x0c052bc4 */
if(!s->budget--) { s->failed_pc=0x0c052bc4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c052bc6;
P_0c052bc6: /* original 8582, guest PC 0x0c052bc6 */
if(!s->budget--) { s->failed_pc=0x0c052bc6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+4,2);
goto P_0c052bc8;
P_0c052bc8: /* original 405a, guest PC 0x0c052bc8 */
if(!s->budget--) { s->failed_pc=0x0c052bc8u; return 0; }
r[53]=r[0];
goto P_0c052bca;
P_0c052bca: /* original f12d, guest PC 0x0c052bca */
if(!s->budget--) { s->failed_pc=0x0c052bcau; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c052bcc;
P_0c052bcc: /* original f1f2, guest PC 0x0c052bcc */
if(!s->budget--) { s->failed_pc=0x0c052bccu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[15],r[18],'*');
goto P_0c052bce;
P_0c052bce: /* original 8583, guest PC 0x0c052bce */
if(!s->budget--) { s->failed_pc=0x0c052bceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+6,2);
goto P_0c052bd0;
P_0c052bd0: /* original 6609, guest PC 0x0c052bd0 */
if(!s->budget--) { s->failed_pc=0x0c052bd0u; return 0; }
r[6]=(r[0]<<16)|(r[0]>>16);
goto P_0c052bd2;
P_0c052bd2: /* original 8584, guest PC 0x0c052bd2 */
if(!s->budget--) { s->failed_pc=0x0c052bd2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+8,2);
goto P_0c052bd4;
P_0c052bd4: /* original 260d, guest PC 0x0c052bd4 */
if(!s->budget--) { s->failed_pc=0x0c052bd4u; return 0; }
r[6]=(r[6]>>16)|(r[0]<<16);
goto P_0c052bd6;
P_0c052bd6: /* original 31ec, guest PC 0x0c052bd6 */
if(!s->budget--) { s->failed_pc=0x0c052bd6u; return 0; }
r[1]+=r[14];
goto P_0c052bd8;
P_0c052bd8: /* original f419, guest PC 0x0c052bd8 */
if(!s->budget--) { s->failed_pc=0x0c052bd8u; return 0; }
vf3_matrix_load(s,ram,4,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c052bda;
P_0c052bda: /* original f519, guest PC 0x0c052bda */
if(!s->budget--) { s->failed_pc=0x0c052bdau; return 0; }
vf3_matrix_load(s,ram,5,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c052bdc;
P_0c052bdc: /* original f619, guest PC 0x0c052bdc */
if(!s->budget--) { s->failed_pc=0x0c052bdcu; return 0; }
vf3_matrix_load(s,ram,6,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c052bde;
P_0c052bde: /* original 6023, guest PC 0x0c052bde */
if(!s->budget--) { s->failed_pc=0x0c052bdeu; return 0; }
r[0]=r[2];
goto P_0c052be0;
P_0c052be0: /* original 08ee, guest PC 0x0c052be0 */
if(!s->budget--) { s->failed_pc=0x0c052be0u; return 0; }
r[8]=read(ram,r[14]+r[0],4);
goto P_0c052be2;
P_0c052be2: /* original 8581, guest PC 0x0c052be2 */
if(!s->budget--) { s->failed_pc=0x0c052be2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+2,2);
goto P_0c052be4;
P_0c052be4: /* original 405a, guest PC 0x0c052be4 */
if(!s->budget--) { s->failed_pc=0x0c052be4u; return 0; }
r[53]=r[0];
goto P_0c052be6;
P_0c052be6: /* original fb2d, guest PC 0x0c052be6 */
if(!s->budget--) { s->failed_pc=0x0c052be6u; return 0; }
fr[11]=vf3_fpu_float(r[53],r[18]);
goto P_0c052be8;
P_0c052be8: /* original fbf2, guest PC 0x0c052be8 */
if(!s->budget--) { s->failed_pc=0x0c052be8u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[15],r[18],'*');
goto P_0c052bea;
P_0c052bea: /* original 8582, guest PC 0x0c052bea */
if(!s->budget--) { s->failed_pc=0x0c052beau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+4,2);
goto P_0c052bec;
P_0c052bec: /* original 405a, guest PC 0x0c052bec */
if(!s->budget--) { s->failed_pc=0x0c052becu; return 0; }
r[53]=r[0];
goto P_0c052bee;
P_0c052bee: /* original fc2d, guest PC 0x0c052bee */
if(!s->budget--) { s->failed_pc=0x0c052beeu; return 0; }
fr[12]=vf3_fpu_float(r[53],r[18]);
goto P_0c052bf0;
P_0c052bf0: /* original fcf2, guest PC 0x0c052bf0 */
if(!s->budget--) { s->failed_pc=0x0c052bf0u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[15],r[18],'*');
goto P_0c052bf2;
P_0c052bf2: /* original 8583, guest PC 0x0c052bf2 */
if(!s->budget--) { s->failed_pc=0x0c052bf2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+6,2);
goto P_0c052bf4;
P_0c052bf4: /* original 6709, guest PC 0x0c052bf4 */
if(!s->budget--) { s->failed_pc=0x0c052bf4u; return 0; }
r[7]=(r[0]<<16)|(r[0]>>16);
goto P_0c052bf6;
P_0c052bf6: /* original 8584, guest PC 0x0c052bf6 */
if(!s->budget--) { s->failed_pc=0x0c052bf6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+8,2);
goto P_0c052bf8;
P_0c052bf8: /* original 270d, guest PC 0x0c052bf8 */
if(!s->budget--) { s->failed_pc=0x0c052bf8u; return 0; }
r[7]=(r[7]>>16)|(r[0]<<16);
goto P_0c052bfa;
P_0c052bfa: /* original 33ec, guest PC 0x0c052bfa */
if(!s->budget--) { s->failed_pc=0x0c052bfau; return 0; }
r[3]+=r[14];
goto P_0c052bfc;
P_0c052bfc: /* original f839, guest PC 0x0c052bfc */
if(!s->budget--) { s->failed_pc=0x0c052bfcu; return 0; }
vf3_matrix_load(s,ram,8,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c052bfe;
P_0c052bfe: /* original f939, guest PC 0x0c052bfe */
if(!s->budget--) { s->failed_pc=0x0c052bfeu; return 0; }
vf3_matrix_load(s,ram,9,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c052c00;
P_0c052c00: /* original fa39, guest PC 0x0c052c00 */
if(!s->budget--) { s->failed_pc=0x0c052c00u; return 0; }
vf3_matrix_load(s,ram,10,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c052c02;
P_0c052c02: /* original c709, guest PC 0x0c052c02 */
if(!s->budget--) { s->failed_pc=0x0c052c02u; return 0; }
r[0]=0x0c052c28u;
goto P_0c052c04;
P_0c052c04: /* original 6002, guest PC 0x0c052c04 */
if(!s->budget--) { s->failed_pc=0x0c052c04u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c052c06;
P_0c052c06: /* original d105, guest PC 0x0c052c06 */
if(!s->budget--) { s->failed_pc=0x0c052c06u; return 0; }
r[1]=read(ram,0x0c052c1cu,4);
goto P_0c052c08;
P_0c052c08: /* original 410b, guest PC 0x0c052c08 */
if(!s->budget--) { s->failed_pc=0x0c052c08u; return 0; }
target=r[1];
r[16]=0x0c052c0cu;
vf3_matrix_load(s,ram,3,r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052c0cu) { target=s->pc; goto dispatch; }
goto P_0c052c0c;
P_0c052c0a: /* original f308, guest PC 0x0c052c0a */
if(!s->budget--) { s->failed_pc=0x0c052c0au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c052c0c;
P_0c052c0c: /* original d004, guest PC 0x0c052c0c */
if(!s->budget--) { s->failed_pc=0x0c052c0cu; return 0; }
r[0]=read(ram,0x0c052c20u,4);
goto P_0c052c0e;
P_0c052c0e: /* original 400b, guest PC 0x0c052c0e */
if(!s->budget--) { s->failed_pc=0x0c052c0eu; return 0; }
target=r[0];
r[16]=0x0c052c12u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052c12u) { target=s->pc; goto dispatch; }
goto P_0c052c12;
P_0c052c10: /* original 0009, guest PC 0x0c052c10 */
if(!s->budget--) { s->failed_pc=0x0c052c10u; return 0; }
goto P_0c052c12;
P_0c052c12: /* original bf93, guest PC 0x0c052c12 */
if(!s->budget--) { s->failed_pc=0x0c052c12u; return 0; }
target=0x0c052b3cu; r[16]=0x0c052c16u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052c16u) { target=s->pc; goto dispatch; }
goto P_0c052c16;
P_0c052c14: /* original 0009, guest PC 0x0c052c14 */
if(!s->budget--) { s->failed_pc=0x0c052c14u; return 0; }
goto P_0c052c16;
P_0c052c16: /* original 4f26, guest PC 0x0c052c16 */
if(!s->budget--) { s->failed_pc=0x0c052c16u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c052c18;
P_0c052c18: /* original 000b, guest PC 0x0c052c18 */
if(!s->budget--) { s->failed_pc=0x0c052c18u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c052c1a: /* original 0009, guest PC 0x0c052c1a */
if(!s->budget--) { s->failed_pc=0x0c052c1au; return 0; }
return vf3_matrix_family(0x0c052c1cu,s,ram);
P_0c052e54: /* original d008, guest PC 0x0c052e54 */
if(!s->budget--) { s->failed_pc=0x0c052e54u; return 0; }
r[0]=read(ram,0x0c052e78u,4);
goto P_0c052e56;
P_0c052e56: /* original 6002, guest PC 0x0c052e56 */
if(!s->budget--) { s->failed_pc=0x0c052e56u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c052e58;
P_0c052e58: /* original 2008, guest PC 0x0c052e58 */
if(!s->budget--) { s->failed_pc=0x0c052e58u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c052e5a;
P_0c052e5a: /* original 8f0f, guest PC 0x0c052e5a */
if(!s->budget--) { s->failed_pc=0x0c052e5au; return 0; }
cond=r[17]&1u;
r[0]=0x00000000u;
if(!cond) { goto P_0c052e7c; }
goto P_0c052e5e;
P_0c052e5c: /* original e000, guest PC 0x0c052e5c */
if(!s->budget--) { s->failed_pc=0x0c052e5cu; return 0; }
r[0]=0x00000000u;
goto P_0c052e5e;
P_0c052e5e: /* original 7c1c, guest PC 0x0c052e5e */
if(!s->budget--) { s->failed_pc=0x0c052e5eu; return 0; }
r[12]+=0x0000001cu;
goto P_0c052e60;
P_0c052e60: /* original 2c02, guest PC 0x0c052e60 */
if(!s->budget--) { s->failed_pc=0x0c052e60u; return 0; }
write(ram,r[12],r[0],4);
goto P_0c052e62;
P_0c052e62: /* original 2c56, guest PC 0x0c052e62 */
if(!s->budget--) { s->failed_pc=0x0c052e62u; return 0; }
r[12]-=4; write(ram,r[12],r[5],4);
goto P_0c052e64;
P_0c052e64: /* original 7cfc, guest PC 0x0c052e64 */
if(!s->budget--) { s->failed_pc=0x0c052e64u; return 0; }
r[12]+=0xfffffffcu;
goto P_0c052e66;
P_0c052e66: /* original 2c06, guest PC 0x0c052e66 */
if(!s->budget--) { s->failed_pc=0x0c052e66u; return 0; }
r[12]-=4; write(ram,r[12],r[0],4);
goto P_0c052e68;
P_0c052e68: /* original fc6b, guest PC 0x0c052e68 */
if(!s->budget--) { s->failed_pc=0x0c052e68u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c052e6a;
P_0c052e6a: /* original fc5b, guest PC 0x0c052e6a */
if(!s->budget--) { s->failed_pc=0x0c052e6au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c052e6c;
P_0c052e6c: /* original fc4b, guest PC 0x0c052e6c */
if(!s->budget--) { s->failed_pc=0x0c052e6cu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c052e6e;
P_0c052e6e: /* original 2c46, guest PC 0x0c052e6e */
if(!s->budget--) { s->failed_pc=0x0c052e6eu; return 0; }
r[12]-=4; write(ram,r[12],r[4],4);
goto P_0c052e70;
P_0c052e70: /* original 0c83, guest PC 0x0c052e70 */
if(!s->budget--) { s->failed_pc=0x0c052e70u; return 0; }
goto P_0c052e72;
P_0c052e72: /* original 000b, guest PC 0x0c052e72 */
if(!s->budget--) { s->failed_pc=0x0c052e72u; return 0; }
target=r[16];
r[12]+=0x00000020u;
s->pc=target; return ram->oob==0;
P_0c052e74: /* original 7c20, guest PC 0x0c052e74 */
if(!s->budget--) { s->failed_pc=0x0c052e74u; return 0; }
r[12]+=0x00000020u;
return vf3_matrix_family(0x0c052e76u,s,ram);
P_0c052e7c: /* original d10c, guest PC 0x0c052e7c */
if(!s->budget--) { s->failed_pc=0x0c052e7cu; return 0; }
r[1]=read(ram,0x0c052eb0u,4);
goto P_0c052e7e;
P_0c052e7e: /* original 6112, guest PC 0x0c052e7e */
if(!s->budget--) { s->failed_pc=0x0c052e7eu; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c052e80;
P_0c052e80: /* original 6253, guest PC 0x0c052e80 */
if(!s->budget--) { s->failed_pc=0x0c052e80u; return 0; }
r[2]=r[5];
goto P_0c052e82;
P_0c052e82: /* original 4229, guest PC 0x0c052e82 */
if(!s->budget--) { s->failed_pc=0x0c052e82u; return 0; }
r[2]>>=16;
goto P_0c052e84;
P_0c052e84: /* original 4219, guest PC 0x0c052e84 */
if(!s->budget--) { s->failed_pc=0x0c052e84u; return 0; }
r[2]>>=8;
goto P_0c052e86;
P_0c052e86: /* original 221e, guest PC 0x0c052e86 */
if(!s->budget--) { s->failed_pc=0x0c052e86u; return 0; }
r[19]=(r[2]&65535u)*(r[1]&65535u);
goto P_0c052e88;
P_0c052e88: /* original 021a, guest PC 0x0c052e88 */
if(!s->budget--) { s->failed_pc=0x0c052e88u; return 0; }
r[2]=r[19];
goto P_0c052e8a;
P_0c052e8a: /* original 4219, guest PC 0x0c052e8a */
if(!s->budget--) { s->failed_pc=0x0c052e8au; return 0; }
r[2]>>=8;
goto P_0c052e8c;
P_0c052e8c: /* original 4218, guest PC 0x0c052e8c */
if(!s->budget--) { s->failed_pc=0x0c052e8cu; return 0; }
r[2]<<=8;
goto P_0c052e8e;
P_0c052e8e: /* original 4228, guest PC 0x0c052e8e */
if(!s->budget--) { s->failed_pc=0x0c052e8eu; return 0; }
r[2]<<=16;
goto P_0c052e90;
P_0c052e90: /* original 4518, guest PC 0x0c052e90 */
if(!s->budget--) { s->failed_pc=0x0c052e90u; return 0; }
r[5]<<=8;
goto P_0c052e92;
P_0c052e92: /* original 4519, guest PC 0x0c052e92 */
if(!s->budget--) { s->failed_pc=0x0c052e92u; return 0; }
r[5]>>=8;
goto P_0c052e94;
P_0c052e94: /* original 252b, guest PC 0x0c052e94 */
if(!s->budget--) { s->failed_pc=0x0c052e94u; return 0; }
r[5]|=r[2];
goto P_0c052e96;
P_0c052e96: /* original 7c1c, guest PC 0x0c052e96 */
if(!s->budget--) { s->failed_pc=0x0c052e96u; return 0; }
r[12]+=0x0000001cu;
goto P_0c052e98;
P_0c052e98: /* original 2c02, guest PC 0x0c052e98 */
if(!s->budget--) { s->failed_pc=0x0c052e98u; return 0; }
write(ram,r[12],r[0],4);
goto P_0c052e9a;
P_0c052e9a: /* original 2c56, guest PC 0x0c052e9a */
if(!s->budget--) { s->failed_pc=0x0c052e9au; return 0; }
r[12]-=4; write(ram,r[12],r[5],4);
goto P_0c052e9c;
P_0c052e9c: /* original 7cfc, guest PC 0x0c052e9c */
if(!s->budget--) { s->failed_pc=0x0c052e9cu; return 0; }
r[12]+=0xfffffffcu;
goto P_0c052e9e;
P_0c052e9e: /* original 2c06, guest PC 0x0c052e9e */
if(!s->budget--) { s->failed_pc=0x0c052e9eu; return 0; }
r[12]-=4; write(ram,r[12],r[0],4);
goto P_0c052ea0;
P_0c052ea0: /* original fc6b, guest PC 0x0c052ea0 */
if(!s->budget--) { s->failed_pc=0x0c052ea0u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c052ea2;
P_0c052ea2: /* original fc5b, guest PC 0x0c052ea2 */
if(!s->budget--) { s->failed_pc=0x0c052ea2u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c052ea4;
P_0c052ea4: /* original fc4b, guest PC 0x0c052ea4 */
if(!s->budget--) { s->failed_pc=0x0c052ea4u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c052ea6;
P_0c052ea6: /* original 2c46, guest PC 0x0c052ea6 */
if(!s->budget--) { s->failed_pc=0x0c052ea6u; return 0; }
r[12]-=4; write(ram,r[12],r[4],4);
goto P_0c052ea8;
P_0c052ea8: /* original 0c83, guest PC 0x0c052ea8 */
if(!s->budget--) { s->failed_pc=0x0c052ea8u; return 0; }
goto P_0c052eaa;
P_0c052eaa: /* original 000b, guest PC 0x0c052eaa */
if(!s->budget--) { s->failed_pc=0x0c052eaau; return 0; }
target=r[16];
r[12]+=0x00000020u;
s->pc=target; return ram->oob==0;
P_0c052eac: /* original 7c20, guest PC 0x0c052eac */
if(!s->budget--) { s->failed_pc=0x0c052eacu; return 0; }
r[12]+=0x00000020u;
return vf3_matrix_family(0x0c052eaeu,s,ram);
P_0c052eca: /* original 4f22, guest PC 0x0c052eca */
if(!s->budget--) { s->failed_pc=0x0c052ecau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c052ecc;
P_0c052ecc: /* original 08ee, guest PC 0x0c052ecc */
if(!s->budget--) { s->failed_pc=0x0c052eccu; return 0; }
r[8]=read(ram,r[14]+r[0],4);
goto P_0c052ece;
P_0c052ece: /* original 8581, guest PC 0x0c052ece */
if(!s->budget--) { s->failed_pc=0x0c052eceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+2,2);
goto P_0c052ed0;
P_0c052ed0: /* original 6609, guest PC 0x0c052ed0 */
if(!s->budget--) { s->failed_pc=0x0c052ed0u; return 0; }
r[6]=(r[0]<<16)|(r[0]>>16);
goto P_0c052ed2;
P_0c052ed2: /* original 8582, guest PC 0x0c052ed2 */
if(!s->budget--) { s->failed_pc=0x0c052ed2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+4,2);
goto P_0c052ed4;
P_0c052ed4: /* original 260d, guest PC 0x0c052ed4 */
if(!s->budget--) { s->failed_pc=0x0c052ed4u; return 0; }
r[6]=(r[6]>>16)|(r[0]<<16);
goto P_0c052ed6;
P_0c052ed6: /* original 31ec, guest PC 0x0c052ed6 */
if(!s->budget--) { s->failed_pc=0x0c052ed6u; return 0; }
r[1]+=r[14];
goto P_0c052ed8;
P_0c052ed8: /* original f419, guest PC 0x0c052ed8 */
if(!s->budget--) { s->failed_pc=0x0c052ed8u; return 0; }
vf3_matrix_load(s,ram,4,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c052eda;
P_0c052eda: /* original f519, guest PC 0x0c052eda */
if(!s->budget--) { s->failed_pc=0x0c052edau; return 0; }
vf3_matrix_load(s,ram,5,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c052edc;
P_0c052edc: /* original f619, guest PC 0x0c052edc */
if(!s->budget--) { s->failed_pc=0x0c052edcu; return 0; }
vf3_matrix_load(s,ram,6,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c052ede;
P_0c052ede: /* original 6023, guest PC 0x0c052ede */
if(!s->budget--) { s->failed_pc=0x0c052edeu; return 0; }
r[0]=r[2];
goto P_0c052ee0;
P_0c052ee0: /* original 08ee, guest PC 0x0c052ee0 */
if(!s->budget--) { s->failed_pc=0x0c052ee0u; return 0; }
r[8]=read(ram,r[14]+r[0],4);
goto P_0c052ee2;
P_0c052ee2: /* original 8581, guest PC 0x0c052ee2 */
if(!s->budget--) { s->failed_pc=0x0c052ee2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+2,2);
goto P_0c052ee4;
P_0c052ee4: /* original 6709, guest PC 0x0c052ee4 */
if(!s->budget--) { s->failed_pc=0x0c052ee4u; return 0; }
r[7]=(r[0]<<16)|(r[0]>>16);
goto P_0c052ee6;
P_0c052ee6: /* original 8582, guest PC 0x0c052ee6 */
if(!s->budget--) { s->failed_pc=0x0c052ee6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+4,2);
goto P_0c052ee8;
P_0c052ee8: /* original 270d, guest PC 0x0c052ee8 */
if(!s->budget--) { s->failed_pc=0x0c052ee8u; return 0; }
r[7]=(r[7]>>16)|(r[0]<<16);
goto P_0c052eea;
P_0c052eea: /* original 33ec, guest PC 0x0c052eea */
if(!s->budget--) { s->failed_pc=0x0c052eeau; return 0; }
r[3]+=r[14];
goto P_0c052eec;
P_0c052eec: /* original f839, guest PC 0x0c052eec */
if(!s->budget--) { s->failed_pc=0x0c052eecu; return 0; }
vf3_matrix_load(s,ram,8,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c052eee;
P_0c052eee: /* original f939, guest PC 0x0c052eee */
if(!s->budget--) { s->failed_pc=0x0c052eeeu; return 0; }
vf3_matrix_load(s,ram,9,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c052ef0;
P_0c052ef0: /* original fa39, guest PC 0x0c052ef0 */
if(!s->budget--) { s->failed_pc=0x0c052ef0u; return 0; }
vf3_matrix_load(s,ram,10,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c052ef2;
P_0c052ef2: /* original c709, guest PC 0x0c052ef2 */
if(!s->budget--) { s->failed_pc=0x0c052ef2u; return 0; }
r[0]=0x0c052f18u;
goto P_0c052ef4;
P_0c052ef4: /* original 6002, guest PC 0x0c052ef4 */
if(!s->budget--) { s->failed_pc=0x0c052ef4u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c052ef6;
P_0c052ef6: /* original d105, guest PC 0x0c052ef6 */
if(!s->budget--) { s->failed_pc=0x0c052ef6u; return 0; }
r[1]=read(ram,0x0c052f0cu,4);
goto P_0c052ef8;
P_0c052ef8: /* original 410b, guest PC 0x0c052ef8 */
if(!s->budget--) { s->failed_pc=0x0c052ef8u; return 0; }
target=r[1];
r[16]=0x0c052efcu;
vf3_matrix_load(s,ram,3,r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052efcu) { target=s->pc; goto dispatch; }
goto P_0c052efc;
P_0c052efa: /* original f308, guest PC 0x0c052efa */
if(!s->budget--) { s->failed_pc=0x0c052efau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c052efc;
P_0c052efc: /* original d004, guest PC 0x0c052efc */
if(!s->budget--) { s->failed_pc=0x0c052efcu; return 0; }
r[0]=read(ram,0x0c052f10u,4);
goto P_0c052efe;
P_0c052efe: /* original 400b, guest PC 0x0c052efe */
if(!s->budget--) { s->failed_pc=0x0c052efeu; return 0; }
target=r[0];
r[16]=0x0c052f02u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052f02u) { target=s->pc; goto dispatch; }
goto P_0c052f02;
P_0c052f00: /* original 0009, guest PC 0x0c052f00 */
if(!s->budget--) { s->failed_pc=0x0c052f00u; return 0; }
goto P_0c052f02;
P_0c052f02: /* original bfa7, guest PC 0x0c052f02 */
if(!s->budget--) { s->failed_pc=0x0c052f02u; return 0; }
target=0x0c052e54u; r[16]=0x0c052f06u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052f06u) { target=s->pc; goto dispatch; }
goto P_0c052f06;
P_0c052f04: /* original 0009, guest PC 0x0c052f04 */
if(!s->budget--) { s->failed_pc=0x0c052f04u; return 0; }
goto P_0c052f06;
P_0c052f06: /* original 4f26, guest PC 0x0c052f06 */
if(!s->budget--) { s->failed_pc=0x0c052f06u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c052f08;
P_0c052f08: /* original 000b, guest PC 0x0c052f08 */
if(!s->budget--) { s->failed_pc=0x0c052f08u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c052f0a: /* original 0009, guest PC 0x0c052f0a */
if(!s->budget--) { s->failed_pc=0x0c052f0au; return 0; }
return vf3_matrix_family(0x0c052f0cu,s,ram);
P_0c053ed4: /* original 4f22, guest PC 0x0c053ed4 */
if(!s->budget--) { s->failed_pc=0x0c053ed4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c053ed6;
P_0c053ed6: /* original 7fec, guest PC 0x0c053ed6 */
if(!s->budget--) { s->failed_pc=0x0c053ed6u; return 0; }
r[15]+=0xffffffecu;
goto P_0c053ed8;
P_0c053ed8: /* original 7ff8, guest PC 0x0c053ed8 */
if(!s->budget--) { s->failed_pc=0x0c053ed8u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c053eda;
P_0c053eda: /* original 53f9, guest PC 0x0c053eda */
if(!s->budget--) { s->failed_pc=0x0c053edau; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c053edc;
P_0c053edc: /* original 2f36, guest PC 0x0c053edc */
if(!s->budget--) { s->failed_pc=0x0c053edcu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c053ede;
P_0c053ede: /* original 53f9, guest PC 0x0c053ede */
if(!s->budget--) { s->failed_pc=0x0c053edeu; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c053ee0;
P_0c053ee0: /* original 2f36, guest PC 0x0c053ee0 */
if(!s->budget--) { s->failed_pc=0x0c053ee0u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c053ee2;
P_0c053ee2: /* original 64f3, guest PC 0x0c053ee2 */
if(!s->budget--) { s->failed_pc=0x0c053ee2u; return 0; }
r[4]=r[15];
goto P_0c053ee4;
P_0c053ee4: /* original 7410, guest PC 0x0c053ee4 */
if(!s->budget--) { s->failed_pc=0x0c053ee4u; return 0; }
r[4]+=0x00000010u;
goto P_0c053ee6;
P_0c053ee6: /* original e308, guest PC 0x0c053ee6 */
if(!s->budget--) { s->failed_pc=0x0c053ee6u; return 0; }
r[3]=0x00000008u;
goto P_0c053ee8;
P_0c053ee8: /* original 33fc, guest PC 0x0c053ee8 */
if(!s->budget--) { s->failed_pc=0x0c053ee8u; return 0; }
r[3]+=r[15];
goto P_0c053eea;
P_0c053eea: /* original b024, guest PC 0x0c053eea */
if(!s->budget--) { s->failed_pc=0x0c053eeau; return 0; }
target=0x0c053f36u; r[16]=0x0c053eeeu;
r[15]-=4; write(ram,r[15],r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053eeeu) { target=s->pc; goto dispatch; }
goto P_0c053eee;
P_0c053eec: /* original 2f36, guest PC 0x0c053eec */
if(!s->budget--) { s->failed_pc=0x0c053eecu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c053eee;
P_0c053eee: /* original 7f14, guest PC 0x0c053eee */
if(!s->budget--) { s->failed_pc=0x0c053eeeu; return 0; }
r[15]+=0x00000014u;
goto P_0c053ef0;
P_0c053ef0: /* original d34c, guest PC 0x0c053ef0 */
if(!s->budget--) { s->failed_pc=0x0c053ef0u; return 0; }
r[3]=read(ram,0x0c054024u,4);
goto P_0c053ef2;
P_0c053ef2: /* original 60f2, guest PC 0x0c053ef2 */
if(!s->budget--) { s->failed_pc=0x0c053ef2u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c053ef4;
P_0c053ef4: /* original 7ff8, guest PC 0x0c053ef4 */
if(!s->budget--) { s->failed_pc=0x0c053ef4u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c053ef6;
P_0c053ef6: /* original 430b, guest PC 0x0c053ef6 */
if(!s->budget--) { s->failed_pc=0x0c053ef6u; return 0; }
target=r[3];
r[16]=0x0c053efau;
tmp=r[15]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053efau) { target=s->pc; goto dispatch; }
goto P_0c053efa;
P_0c053ef8: /* original 2ff6, guest PC 0x0c053ef8 */
if(!s->budget--) { s->failed_pc=0x0c053ef8u; return 0; }
tmp=r[15]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053efa;
P_0c053efa: /* original d24b, guest PC 0x0c053efa */
if(!s->budget--) { s->failed_pc=0x0c053efau; return 0; }
r[2]=read(ram,0x0c054028u,4);
goto P_0c053efc;
P_0c053efc: /* original d34c, guest PC 0x0c053efc */
if(!s->budget--) { s->failed_pc=0x0c053efcu; return 0; }
r[3]=read(ram,0x0c054030u,4);
goto P_0c053efe;
P_0c053efe: /* original 2f26, guest PC 0x0c053efe */
if(!s->budget--) { s->failed_pc=0x0c053efeu; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c053f00;
P_0c053f00: /* original d24a, guest PC 0x0c053f00 */
if(!s->budget--) { s->failed_pc=0x0c053f00u; return 0; }
r[2]=read(ram,0x0c05402cu,4);
goto P_0c053f02;
P_0c053f02: /* original 2f26, guest PC 0x0c053f02 */
if(!s->budget--) { s->failed_pc=0x0c053f02u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c053f04;
P_0c053f04: /* original 61f3, guest PC 0x0c053f04 */
if(!s->budget--) { s->failed_pc=0x0c053f04u; return 0; }
r[1]=r[15];
goto P_0c053f06;
P_0c053f06: /* original 7114, guest PC 0x0c053f06 */
if(!s->budget--) { s->failed_pc=0x0c053f06u; return 0; }
r[1]+=0x00000014u;
goto P_0c053f08;
P_0c053f08: /* original 430b, guest PC 0x0c053f08 */
if(!s->budget--) { s->failed_pc=0x0c053f08u; return 0; }
target=r[3];
r[16]=0x0c053f0cu;
r[15]-=4; write(ram,r[15],r[1],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053f0cu) { target=s->pc; goto dispatch; }
goto P_0c053f0c;
P_0c053f0a: /* original 2f16, guest PC 0x0c053f0a */
if(!s->budget--) { s->failed_pc=0x0c053f0au; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c053f0c;
P_0c053f0c: /* original 7ff8, guest PC 0x0c053f0c */
if(!s->budget--) { s->failed_pc=0x0c053f0cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c053f0e;
P_0c053f0e: /* original e308, guest PC 0x0c053f0e */
if(!s->budget--) { s->failed_pc=0x0c053f0eu; return 0; }
r[3]=0x00000008u;
goto P_0c053f10;
P_0c053f10: /* original 52f4, guest PC 0x0c053f10 */
if(!s->budget--) { s->failed_pc=0x0c053f10u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c053f12;
P_0c053f12: /* original 2f26, guest PC 0x0c053f12 */
if(!s->budget--) { s->failed_pc=0x0c053f12u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c053f14;
P_0c053f14: /* original 52f4, guest PC 0x0c053f14 */
if(!s->budget--) { s->failed_pc=0x0c053f14u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c053f16;
P_0c053f16: /* original 2f26, guest PC 0x0c053f16 */
if(!s->budget--) { s->failed_pc=0x0c053f16u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c053f18;
P_0c053f18: /* original 64f3, guest PC 0x0c053f18 */
if(!s->budget--) { s->failed_pc=0x0c053f18u; return 0; }
r[4]=r[15];
goto P_0c053f1a;
P_0c053f1a: /* original 741c, guest PC 0x0c053f1a */
if(!s->budget--) { s->failed_pc=0x0c053f1au; return 0; }
r[4]+=0x0000001cu;
goto P_0c053f1c;
P_0c053f1c: /* original 33fc, guest PC 0x0c053f1c */
if(!s->budget--) { s->failed_pc=0x0c053f1cu; return 0; }
r[3]+=r[15];
goto P_0c053f1e;
P_0c053f1e: /* original b0c3, guest PC 0x0c053f1e */
if(!s->budget--) { s->failed_pc=0x0c053f1eu; return 0; }
target=0x0c0540a8u; r[16]=0x0c053f22u;
r[15]-=4; write(ram,r[15],r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053f22u) { target=s->pc; goto dispatch; }
goto P_0c053f22;
P_0c053f20: /* original 2f36, guest PC 0x0c053f20 */
if(!s->budget--) { s->failed_pc=0x0c053f20u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c053f22;
P_0c053f22: /* original 53f9, guest PC 0x0c053f22 */
if(!s->budget--) { s->failed_pc=0x0c053f22u; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c053f24;
P_0c053f24: /* original d243, guest PC 0x0c053f24 */
if(!s->budget--) { s->failed_pc=0x0c053f24u; return 0; }
r[2]=read(ram,0x0c054034u,4);
goto P_0c053f26;
P_0c053f26: /* original 2f36, guest PC 0x0c053f26 */
if(!s->budget--) { s->failed_pc=0x0c053f26u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c053f28;
P_0c053f28: /* original 53f9, guest PC 0x0c053f28 */
if(!s->budget--) { s->failed_pc=0x0c053f28u; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c053f2a;
P_0c053f2a: /* original 420b, guest PC 0x0c053f2a */
if(!s->budget--) { s->failed_pc=0x0c053f2au; return 0; }
target=r[2];
r[16]=0x0c053f2eu;
r[15]-=4; write(ram,r[15],r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053f2eu) { target=s->pc; goto dispatch; }
goto P_0c053f2e;
P_0c053f2c: /* original 2f36, guest PC 0x0c053f2c */
if(!s->budget--) { s->failed_pc=0x0c053f2cu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c053f2e;
P_0c053f2e: /* original 7f28, guest PC 0x0c053f2e */
if(!s->budget--) { s->failed_pc=0x0c053f2eu; return 0; }
r[15]+=0x00000028u;
goto P_0c053f30;
P_0c053f30: /* original 4f26, guest PC 0x0c053f30 */
if(!s->budget--) { s->failed_pc=0x0c053f30u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053f32;
P_0c053f32: /* original 000b, guest PC 0x0c053f32 */
if(!s->budget--) { s->failed_pc=0x0c053f32u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c053f34: /* original 0009, guest PC 0x0c053f34 */
if(!s->budget--) { s->failed_pc=0x0c053f34u; return 0; }
return vf3_matrix_family(0x0c053f36u,s,ram);
P_0c05480c: /* original d50c, guest PC 0x0c05480c */
if(!s->budget--) { s->failed_pc=0x0c05480cu; return 0; }
r[5]=read(ram,0x0c054840u,4);
goto P_0c05480e;
P_0c05480e: /* original 64f3, guest PC 0x0c05480e */
if(!s->budget--) { s->failed_pc=0x0c05480eu; return 0; }
r[4]=r[15];
goto P_0c054810;
P_0c054810: /* original 7404, guest PC 0x0c054810 */
if(!s->budget--) { s->failed_pc=0x0c054810u; return 0; }
r[4]+=0x00000004u;
goto P_0c054812;
P_0c054812: /* original 6342, guest PC 0x0c054812 */
if(!s->budget--) { s->failed_pc=0x0c054812u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c054814;
P_0c054814: /* original 2359, guest PC 0x0c054814 */
if(!s->budget--) { s->failed_pc=0x0c054814u; return 0; }
r[3]&=r[5];
goto P_0c054816;
P_0c054816: /* original 3350, guest PC 0x0c054816 */
if(!s->budget--) { s->failed_pc=0x0c054816u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[5])!=0);
goto P_0c054818;
P_0c054818: /* original 8d02, guest PC 0x0c054818 */
if(!s->budget--) { s->failed_pc=0x0c054818u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054820; }
goto P_0c05481c;
P_0c05481a: /* original 0009, guest PC 0x0c05481a */
if(!s->budget--) { s->failed_pc=0x0c05481au; return 0; }
goto P_0c05481c;
P_0c05481c: /* original 000b, guest PC 0x0c05481c */
if(!s->budget--) { s->failed_pc=0x0c05481cu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c05481e: /* original e000, guest PC 0x0c05481e */
if(!s->budget--) { s->failed_pc=0x0c05481eu; return 0; }
r[0]=0x00000000u;
goto P_0c054820;
P_0c054820: /* original d308, guest PC 0x0c054820 */
if(!s->budget--) { s->failed_pc=0x0c054820u; return 0; }
r[3]=read(ram,0x0c054844u,4);
goto P_0c054822;
P_0c054822: /* original 6242, guest PC 0x0c054822 */
if(!s->budget--) { s->failed_pc=0x0c054822u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c054824;
P_0c054824: /* original 2238, guest PC 0x0c054824 */
if(!s->budget--) { s->failed_pc=0x0c054824u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c054826;
P_0c054826: /* original 8f05, guest PC 0x0c054826 */
if(!s->budget--) { s->failed_pc=0x0c054826u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054834; }
goto P_0c05482a;
P_0c054828: /* original 0009, guest PC 0x0c054828 */
if(!s->budget--) { s->failed_pc=0x0c054828u; return 0; }
goto P_0c05482a;
P_0c05482a: /* original 74fc, guest PC 0x0c05482a */
if(!s->budget--) { s->failed_pc=0x0c05482au; return 0; }
r[4]+=0xfffffffcu;
goto P_0c05482c;
P_0c05482c: /* original 6342, guest PC 0x0c05482c */
if(!s->budget--) { s->failed_pc=0x0c05482cu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c05482e;
P_0c05482e: /* original 2338, guest PC 0x0c05482e */
if(!s->budget--) { s->failed_pc=0x0c05482eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c054830;
P_0c054830: /* original 8d02, guest PC 0x0c054830 */
if(!s->budget--) { s->failed_pc=0x0c054830u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054838; }
goto P_0c054834;
P_0c054832: /* original 0009, guest PC 0x0c054832 */
if(!s->budget--) { s->failed_pc=0x0c054832u; return 0; }
goto P_0c054834;
P_0c054834: /* original 000b, guest PC 0x0c054834 */
if(!s->budget--) { s->failed_pc=0x0c054834u; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c054836: /* original e001, guest PC 0x0c054836 */
if(!s->budget--) { s->failed_pc=0x0c054836u; return 0; }
r[0]=0x00000001u;
goto P_0c054838;
P_0c054838: /* original e002, guest PC 0x0c054838 */
if(!s->budget--) { s->failed_pc=0x0c054838u; return 0; }
r[0]=0x00000002u;
goto P_0c05483a;
P_0c05483a: /* original 000b, guest PC 0x0c05483a */
if(!s->budget--) { s->failed_pc=0x0c05483au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c05483c: /* original 0009, guest PC 0x0c05483c */
if(!s->budget--) { s->failed_pc=0x0c05483cu; return 0; }
return vf3_matrix_family(0x0c05483eu,s,ram);
P_0c054848: /* original 2fd6, guest PC 0x0c054848 */
if(!s->budget--) { s->failed_pc=0x0c054848u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c05484a;
P_0c05484a: /* original e700, guest PC 0x0c05484a */
if(!s->budget--) { s->failed_pc=0x0c05484au; return 0; }
r[7]=0x00000000u;
goto P_0c05484c;
P_0c05484c: /* original 9d23, guest PC 0x0c05484c */
if(!s->budget--) { s->failed_pc=0x0c05484cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c054896u,2);
goto P_0c05484e;
P_0c05484e: /* original 7ffc, guest PC 0x0c05484e */
if(!s->budget--) { s->failed_pc=0x0c05484eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c054850;
P_0c054850: /* original 75ff, guest PC 0x0c054850 */
if(!s->budget--) { s->failed_pc=0x0c054850u; return 0; }
r[5]+=0xffffffffu;
goto P_0c054852;
P_0c054852: /* original 6653, guest PC 0x0c054852 */
if(!s->budget--) { s->failed_pc=0x0c054852u; return 0; }
r[6]=r[5];
goto P_0c054854;
P_0c054854: /* original 364c, guest PC 0x0c054854 */
if(!s->budget--) { s->failed_pc=0x0c054854u; return 0; }
r[6]+=r[4];
goto P_0c054856;
P_0c054856: /* original 4511, guest PC 0x0c054856 */
if(!s->budget--) { s->failed_pc=0x0c054856u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c054858;
P_0c054858: /* original 2f62, guest PC 0x0c054858 */
if(!s->budget--) { s->failed_pc=0x0c054858u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c05485a;
P_0c05485a: /* original 8f11, guest PC 0x0c05485a */
if(!s->budget--) { s->failed_pc=0x0c05485au; return 0; }
cond=r[17]&1u;
r[4]=r[6];
if(!cond) { goto P_0c054880; }
goto P_0c05485e;
P_0c05485c: /* original 6463, guest PC 0x0c05485c */
if(!s->budget--) { s->failed_pc=0x0c05485cu; return 0; }
r[4]=r[6];
goto P_0c05485e;
P_0c05485e: /* original 6140, guest PC 0x0c05485e */
if(!s->budget--) { s->failed_pc=0x0c05485eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[1]=tmp;
goto P_0c054860;
P_0c054860: /* original 6340, guest PC 0x0c054860 */
if(!s->budget--) { s->failed_pc=0x0c054860u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c054862;
P_0c054862: /* original 611c, guest PC 0x0c054862 */
if(!s->budget--) { s->failed_pc=0x0c054862u; return 0; }
r[1]=r[1]&255u;
goto P_0c054864;
P_0c054864: /* original 21d9, guest PC 0x0c054864 */
if(!s->budget--) { s->failed_pc=0x0c054864u; return 0; }
r[1]&=r[13];
goto P_0c054866;
P_0c054866: /* original 4300, guest PC 0x0c054866 */
if(!s->budget--) { s->failed_pc=0x0c054866u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c054868;
P_0c054868: /* original 2778, guest PC 0x0c054868 */
if(!s->budget--) { s->failed_pc=0x0c054868u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c05486a;
P_0c05486a: /* original 8d03, guest PC 0x0c05486a */
if(!s->budget--) { s->failed_pc=0x0c05486au; return 0; }
cond=r[17]&1u;
write(ram,r[4],r[3],1);
if(cond) { goto P_0c054874; }
goto P_0c05486e;
P_0c05486c: /* original 2430, guest PC 0x0c05486c */
if(!s->budget--) { s->failed_pc=0x0c05486cu; return 0; }
write(ram,r[4],r[3],1);
goto P_0c05486e;
P_0c05486e: /* original 6060, guest PC 0x0c05486e */
if(!s->budget--) { s->failed_pc=0x0c05486eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[0]=tmp;
goto P_0c054870;
P_0c054870: /* original cb01, guest PC 0x0c054870 */
if(!s->budget--) { s->failed_pc=0x0c054870u; return 0; }
r[0]|=1u;
goto P_0c054872;
P_0c054872: /* original 2600, guest PC 0x0c054872 */
if(!s->budget--) { s->failed_pc=0x0c054872u; return 0; }
write(ram,r[6],r[0],1);
goto P_0c054874;
P_0c054874: /* original 6713, guest PC 0x0c054874 */
if(!s->budget--) { s->failed_pc=0x0c054874u; return 0; }
r[7]=r[1];
goto P_0c054876;
P_0c054876: /* original 75ff, guest PC 0x0c054876 */
if(!s->budget--) { s->failed_pc=0x0c054876u; return 0; }
r[5]+=0xffffffffu;
goto P_0c054878;
P_0c054878: /* original 76ff, guest PC 0x0c054878 */
if(!s->budget--) { s->failed_pc=0x0c054878u; return 0; }
r[6]+=0xffffffffu;
goto P_0c05487a;
P_0c05487a: /* original 4511, guest PC 0x0c05487a */
if(!s->budget--) { s->failed_pc=0x0c05487au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c05487c;
P_0c05487c: /* original 8def, guest PC 0x0c05487c */
if(!s->budget--) { s->failed_pc=0x0c05487cu; return 0; }
cond=r[17]&1u;
r[4]+=0xffffffffu;
if(cond) { goto P_0c05485e; }
goto P_0c054880;
P_0c05487e: /* original 74ff, guest PC 0x0c05487e */
if(!s->budget--) { s->failed_pc=0x0c05487eu; return 0; }
r[4]+=0xffffffffu;
goto P_0c054880;
P_0c054880: /* original 2778, guest PC 0x0c054880 */
if(!s->budget--) { s->failed_pc=0x0c054880u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c054882;
P_0c054882: /* original 8d04, guest PC 0x0c054882 */
if(!s->budget--) { s->failed_pc=0x0c054882u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05488e; }
goto P_0c054886;
P_0c054884: /* original 0009, guest PC 0x0c054884 */
if(!s->budget--) { s->failed_pc=0x0c054884u; return 0; }
goto P_0c054886;
P_0c054886: /* original e001, guest PC 0x0c054886 */
if(!s->budget--) { s->failed_pc=0x0c054886u; return 0; }
r[0]=0x00000001u;
goto P_0c054888;
P_0c054888: /* original 7f04, guest PC 0x0c054888 */
if(!s->budget--) { s->failed_pc=0x0c054888u; return 0; }
r[15]+=0x00000004u;
goto P_0c05488a;
P_0c05488a: /* original 000b, guest PC 0x0c05488a */
if(!s->budget--) { s->failed_pc=0x0c05488au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c05488c: /* original 6df6, guest PC 0x0c05488c */
if(!s->budget--) { s->failed_pc=0x0c05488cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05488e;
P_0c05488e: /* original e000, guest PC 0x0c05488e */
if(!s->budget--) { s->failed_pc=0x0c05488eu; return 0; }
r[0]=0x00000000u;
goto P_0c054890;
P_0c054890: /* original 7f04, guest PC 0x0c054890 */
if(!s->budget--) { s->failed_pc=0x0c054890u; return 0; }
r[15]+=0x00000004u;
goto P_0c054892;
P_0c054892: /* original 000b, guest PC 0x0c054892 */
if(!s->budget--) { s->failed_pc=0x0c054892u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c054894: /* original 6df6, guest PC 0x0c054894 */
if(!s->budget--) { s->failed_pc=0x0c054894u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
return vf3_matrix_family(0x0c054896u,s,ram);
P_0c054c1c: /* original 2f06, guest PC 0x0c054c1c */
if(!s->budget--) { s->failed_pc=0x0c054c1cu; return 0; }
r[15]-=4; write(ram,r[15],r[0],4);
goto P_0c054c1e;
P_0c054c1e: /* original 2f46, guest PC 0x0c054c1e */
if(!s->budget--) { s->failed_pc=0x0c054c1eu; return 0; }
r[15]-=4; write(ram,r[15],r[4],4);
goto P_0c054c20;
P_0c054c20: /* original 2f56, guest PC 0x0c054c20 */
if(!s->budget--) { s->failed_pc=0x0c054c20u; return 0; }
r[15]-=4; write(ram,r[15],r[5],4);
goto P_0c054c22;
P_0c054c22: /* original 2f66, guest PC 0x0c054c22 */
if(!s->budget--) { s->failed_pc=0x0c054c22u; return 0; }
r[15]-=4; write(ram,r[15],r[6],4);
goto P_0c054c24;
P_0c054c24: /* original 2f76, guest PC 0x0c054c24 */
if(!s->budget--) { s->failed_pc=0x0c054c24u; return 0; }
r[15]-=4; write(ram,r[15],r[7],4);
goto P_0c054c26;
P_0c054c26: /* original 57f6, guest PC 0x0c054c26 */
if(!s->budget--) { s->failed_pc=0x0c054c26u; return 0; }
r[7]=read(ram,r[15]+24,4);
goto P_0c054c28;
P_0c054c28: /* original 56f7, guest PC 0x0c054c28 */
if(!s->budget--) { s->failed_pc=0x0c054c28u; return 0; }
r[6]=read(ram,r[15]+28,4);
goto P_0c054c2a;
P_0c054c2a: /* original 55f8, guest PC 0x0c054c2a */
if(!s->budget--) { s->failed_pc=0x0c054c2au; return 0; }
r[5]=read(ram,r[15]+32,4);
goto P_0c054c2c;
P_0c054c2c: /* original 54f9, guest PC 0x0c054c2c */
if(!s->budget--) { s->failed_pc=0x0c054c2cu; return 0; }
r[4]=read(ram,r[15]+36,4);
goto P_0c054c2e;
P_0c054c2e: /* original d0b6, guest PC 0x0c054c2e */
if(!s->budget--) { s->failed_pc=0x0c054c2eu; return 0; }
r[0]=read(ram,0x0c054f08u,4);
goto P_0c054c30;
P_0c054c30: /* original a059, guest PC 0x0c054c30 */
if(!s->budget--) { s->failed_pc=0x0c054c30u; return 0; }
r[6]^=r[0];
goto P_0c054ce6;
P_0c054c32: /* original 260a, guest PC 0x0c054c32 */
if(!s->budget--) { s->failed_pc=0x0c054c32u; return 0; }
r[6]^=r[0];
goto P_0c054c34;
P_0c054c34: /* original 2448, guest PC 0x0c054c34 */
if(!s->budget--) { s->failed_pc=0x0c054c34u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c054c36;
P_0c054c36: /* original 8b07, guest PC 0x0c054c36 */
if(!s->budget--) { s->failed_pc=0x0c054c36u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054c48; }
goto P_0c054c38;
P_0c054c38: /* original 2558, guest PC 0x0c054c38 */
if(!s->budget--) { s->failed_pc=0x0c054c38u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c054c3a;
P_0c054c3a: /* original 8b05, guest PC 0x0c054c3a */
if(!s->budget--) { s->failed_pc=0x0c054c3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054c48; }
goto P_0c054c3c;
P_0c054c3c: /* original 3930, guest PC 0x0c054c3c */
if(!s->budget--) { s->failed_pc=0x0c054c3cu; return 0; }
r[17]=(r[17]&~1u)|((r[9]==r[3])!=0);
goto P_0c054c3e;
P_0c054c3e: /* original 8b07, guest PC 0x0c054c3e */
if(!s->budget--) { s->failed_pc=0x0c054c3eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054c50; }
goto P_0c054c40;
P_0c054c40: /* original 2778, guest PC 0x0c054c40 */
if(!s->budget--) { s->failed_pc=0x0c054c40u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c054c42;
P_0c054c42: /* original 8b01, guest PC 0x0c054c42 */
if(!s->budget--) { s->failed_pc=0x0c054c42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054c48; }
goto P_0c054c44;
P_0c054c44: /* original 2ba7, guest PC 0x0c054c44 */
if(!s->budget--) { s->failed_pc=0x0c054c44u; return 0; }
r[17]=(r[17]&~0x301u)|((r[11]>>31)<<8)|((r[10]>>31)<<9)|(((r[11]^r[10])>>31)&1u);
goto P_0c054c46;
P_0c054c46: /* original 8b03, guest PC 0x0c054c46 */
if(!s->budget--) { s->failed_pc=0x0c054c46u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054c50; }
goto P_0c054c48;
P_0c054c48: /* original ea00, guest PC 0x0c054c48 */
if(!s->budget--) { s->failed_pc=0x0c054c48u; return 0; }
r[10]=0x00000000u;
goto P_0c054c4a;
P_0c054c4a: /* original e400, guest PC 0x0c054c4a */
if(!s->budget--) { s->failed_pc=0x0c054c4au; return 0; }
r[4]=0x00000000u;
goto P_0c054c4c;
P_0c054c4c: /* original a11f, guest PC 0x0c054c4c */
if(!s->budget--) { s->failed_pc=0x0c054c4cu; return 0; }
r[5]=0x00000008u;
goto P_0c054e8e;
P_0c054c4e: /* original e508, guest PC 0x0c054c4e */
if(!s->budget--) { s->failed_pc=0x0c054c4eu; return 0; }
r[5]=0x00000008u;
goto P_0c054c50;
P_0c054c50: /* original a11d, guest PC 0x0c054c50 */
if(!s->budget--) { s->failed_pc=0x0c054c50u; return 0; }
goto P_0c054e8e;
P_0c054c52: /* original 0009, guest PC 0x0c054c52 */
if(!s->budget--) { s->failed_pc=0x0c054c52u; return 0; }
goto P_0c054c54;
P_0c054c54: /* original 2888, guest PC 0x0c054c54 */
if(!s->budget--) { s->failed_pc=0x0c054c54u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c054c56;
P_0c054c56: /* original 8b07, guest PC 0x0c054c56 */
if(!s->budget--) { s->failed_pc=0x0c054c56u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054c68; }
goto P_0c054c58;
P_0c054c58: /* original 2448, guest PC 0x0c054c58 */
if(!s->budget--) { s->failed_pc=0x0c054c58u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c054c5a;
P_0c054c5a: /* original 8b0b, guest PC 0x0c054c5a */
if(!s->budget--) { s->failed_pc=0x0c054c5au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054c74; }
goto P_0c054c5c;
P_0c054c5c: /* original 2558, guest PC 0x0c054c5c */
if(!s->budget--) { s->failed_pc=0x0c054c5cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c054c5e;
P_0c054c5e: /* original 8b09, guest PC 0x0c054c5e */
if(!s->budget--) { s->failed_pc=0x0c054c5eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054c74; }
goto P_0c054c60;
P_0c054c60: /* original 2778, guest PC 0x0c054c60 */
if(!s->budget--) { s->failed_pc=0x0c054c60u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c054c62;
P_0c054c62: /* original 8b0d, guest PC 0x0c054c62 */
if(!s->budget--) { s->failed_pc=0x0c054c62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054c80; }
goto P_0c054c64;
P_0c054c64: /* original a113, guest PC 0x0c054c64 */
if(!s->budget--) { s->failed_pc=0x0c054c64u; return 0; }
r[10]&=r[11];
goto P_0c054e8e;
P_0c054c66: /* original 2ab9, guest PC 0x0c054c66 */
if(!s->budget--) { s->failed_pc=0x0c054c66u; return 0; }
r[10]&=r[11];
goto P_0c054c68;
P_0c054c68: /* original 2668, guest PC 0x0c054c68 */
if(!s->budget--) { s->failed_pc=0x0c054c68u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c054c6a;
P_0c054c6a: /* original 8b1e, guest PC 0x0c054c6a */
if(!s->budget--) { s->failed_pc=0x0c054c6au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054caa; }
goto P_0c054c6c;
P_0c054c6c: /* original 2778, guest PC 0x0c054c6c */
if(!s->budget--) { s->failed_pc=0x0c054c6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c054c6e;
P_0c054c6e: /* original 8b1c, guest PC 0x0c054c6e */
if(!s->budget--) { s->failed_pc=0x0c054c6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054caa; }
goto P_0c054c70;
P_0c054c70: /* original a00a, guest PC 0x0c054c70 */
if(!s->budget--) { s->failed_pc=0x0c054c70u; return 0; }
goto P_0c054c88;
P_0c054c72: /* original 0009, guest PC 0x0c054c72 */
if(!s->budget--) { s->failed_pc=0x0c054c72u; return 0; }
goto P_0c054c74;
P_0c054c74: /* original 2668, guest PC 0x0c054c74 */
if(!s->budget--) { s->failed_pc=0x0c054c74u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c054c76;
P_0c054c76: /* original 8b0e, guest PC 0x0c054c76 */
if(!s->budget--) { s->failed_pc=0x0c054c76u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054c96; }
goto P_0c054c78;
P_0c054c78: /* original 2778, guest PC 0x0c054c78 */
if(!s->budget--) { s->failed_pc=0x0c054c78u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c054c7a;
P_0c054c7a: /* original 8b0c, guest PC 0x0c054c7a */
if(!s->budget--) { s->failed_pc=0x0c054c7au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054c96; }
goto P_0c054c7c;
P_0c054c7c: /* original a004, guest PC 0x0c054c7c */
if(!s->budget--) { s->failed_pc=0x0c054c7cu; return 0; }
goto P_0c054c88;
P_0c054c7e: /* original 0009, guest PC 0x0c054c7e */
if(!s->budget--) { s->failed_pc=0x0c054c7eu; return 0; }
goto P_0c054c80;
P_0c054c80: /* original 6463, guest PC 0x0c054c80 */
if(!s->budget--) { s->failed_pc=0x0c054c80u; return 0; }
r[4]=r[6];
goto P_0c054c82;
P_0c054c82: /* original 6573, guest PC 0x0c054c82 */
if(!s->budget--) { s->failed_pc=0x0c054c82u; return 0; }
r[5]=r[7];
goto P_0c054c84;
P_0c054c84: /* original 6893, guest PC 0x0c054c84 */
if(!s->budget--) { s->failed_pc=0x0c054c84u; return 0; }
r[8]=r[9];
goto P_0c054c86;
P_0c054c86: /* original 6ab3, guest PC 0x0c054c86 */
if(!s->budget--) { s->failed_pc=0x0c054c86u; return 0; }
r[10]=r[11];
goto P_0c054c88;
P_0c054c88: /* original 4500, guest PC 0x0c054c88 */
if(!s->budget--) { s->failed_pc=0x0c054c88u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054c8a;
P_0c054c8a: /* original 4424, guest PC 0x0c054c8a */
if(!s->budget--) { s->failed_pc=0x0c054c8au; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054c8c;
P_0c054c8c: /* original 4500, guest PC 0x0c054c8c */
if(!s->budget--) { s->failed_pc=0x0c054c8cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054c8e;
P_0c054c8e: /* original 4424, guest PC 0x0c054c8e */
if(!s->budget--) { s->failed_pc=0x0c054c8eu; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054c90;
P_0c054c90: /* original 4500, guest PC 0x0c054c90 */
if(!s->budget--) { s->failed_pc=0x0c054c90u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054c92;
P_0c054c92: /* original a0fc, guest PC 0x0c054c92 */
if(!s->budget--) { s->failed_pc=0x0c054c92u; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e8e;
P_0c054c94: /* original 4424, guest PC 0x0c054c94 */
if(!s->budget--) { s->failed_pc=0x0c054c94u; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054c96;
P_0c054c96: /* original d39b, guest PC 0x0c054c96 */
if(!s->budget--) { s->failed_pc=0x0c054c96u; return 0; }
r[3]=read(ram,0x0c054f04u,4);
goto P_0c054c98;
P_0c054c98: /* original 4500, guest PC 0x0c054c98 */
if(!s->budget--) { s->failed_pc=0x0c054c98u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054c9a;
P_0c054c9a: /* original 4424, guest PC 0x0c054c9a */
if(!s->budget--) { s->failed_pc=0x0c054c9au; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054c9c;
P_0c054c9c: /* original 3433, guest PC 0x0c054c9c */
if(!s->budget--) { s->failed_pc=0x0c054c9cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c054c9e;
P_0c054c9e: /* original 8904, guest PC 0x0c054c9e */
if(!s->budget--) { s->failed_pc=0x0c054c9eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054caa; }
goto P_0c054ca0;
P_0c054ca0: /* original 4500, guest PC 0x0c054ca0 */
if(!s->budget--) { s->failed_pc=0x0c054ca0u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054ca2;
P_0c054ca2: /* original 4424, guest PC 0x0c054ca2 */
if(!s->budget--) { s->failed_pc=0x0c054ca2u; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054ca4;
P_0c054ca4: /* original 3433, guest PC 0x0c054ca4 */
if(!s->budget--) { s->failed_pc=0x0c054ca4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c054ca6;
P_0c054ca6: /* original 8ffb, guest PC 0x0c054ca6 */
if(!s->budget--) { s->failed_pc=0x0c054ca6u; return 0; }
cond=r[17]&1u;
r[8]+=0xffffffffu;
if(!cond) { goto P_0c054ca0; }
goto P_0c054caa;
P_0c054ca8: /* original 78ff, guest PC 0x0c054ca8 */
if(!s->budget--) { s->failed_pc=0x0c054ca8u; return 0; }
r[8]+=0xffffffffu;
goto P_0c054caa;
P_0c054caa: /* original d396, guest PC 0x0c054caa */
if(!s->budget--) { s->failed_pc=0x0c054caau; return 0; }
r[3]=read(ram,0x0c054f04u,4);
goto P_0c054cac;
P_0c054cac: /* original 4700, guest PC 0x0c054cac */
if(!s->budget--) { s->failed_pc=0x0c054cacu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c054cae;
P_0c054cae: /* original 4624, guest PC 0x0c054cae */
if(!s->budget--) { s->failed_pc=0x0c054caeu; return 0; }
tmp=r[6]>>31; r[6]=(r[6]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054cb0;
P_0c054cb0: /* original 3633, guest PC 0x0c054cb0 */
if(!s->budget--) { s->failed_pc=0x0c054cb0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[3])!=0);
goto P_0c054cb2;
P_0c054cb2: /* original 8904, guest PC 0x0c054cb2 */
if(!s->budget--) { s->failed_pc=0x0c054cb2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054cbe; }
goto P_0c054cb4;
P_0c054cb4: /* original 4700, guest PC 0x0c054cb4 */
if(!s->budget--) { s->failed_pc=0x0c054cb4u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c054cb6;
P_0c054cb6: /* original 4624, guest PC 0x0c054cb6 */
if(!s->budget--) { s->failed_pc=0x0c054cb6u; return 0; }
tmp=r[6]>>31; r[6]=(r[6]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054cb8;
P_0c054cb8: /* original 3633, guest PC 0x0c054cb8 */
if(!s->budget--) { s->failed_pc=0x0c054cb8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[3])!=0);
goto P_0c054cba;
P_0c054cba: /* original 8ffb, guest PC 0x0c054cba */
if(!s->budget--) { s->failed_pc=0x0c054cbau; return 0; }
cond=r[17]&1u;
r[9]+=0xffffffffu;
if(!cond) { goto P_0c054cb4; }
goto P_0c054cbe;
P_0c054cbc: /* original 79ff, guest PC 0x0c054cbc */
if(!s->budget--) { s->failed_pc=0x0c054cbcu; return 0; }
r[9]+=0xffffffffu;
goto P_0c054cbe;
P_0c054cbe: /* original 3987, guest PC 0x0c054cbe */
if(!s->budget--) { s->failed_pc=0x0c054cbeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>(int32_t)r[8])!=0);
goto P_0c054cc0;
P_0c054cc0: /* original 8b01, guest PC 0x0c054cc0 */
if(!s->budget--) { s->failed_pc=0x0c054cc0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054cc6; }
goto P_0c054cc2;
P_0c054cc2: /* original a108, guest PC 0x0c054cc2 */
if(!s->budget--) { s->failed_pc=0x0c054cc2u; return 0; }
return vf3_matrix_family(0x0c054ed6u,s,ram);
P_0c054cc4: /* original 0009, guest PC 0x0c054cc4 */
if(!s->budget--) { s->failed_pc=0x0c054cc4u; return 0; }
goto P_0c054cc6;
P_0c054cc6: /* original a034, guest PC 0x0c054cc6 */
if(!s->budget--) { s->failed_pc=0x0c054cc6u; return 0; }
goto P_0c054d32;
P_0c054cc8: /* original 0009, guest PC 0x0c054cc8 */
if(!s->budget--) { s->failed_pc=0x0c054cc8u; return 0; }
return vf3_matrix_family(0x0c054ccau,s,ram);
P_0c054ce6: /* original 2f26, guest PC 0x0c054ce6 */
if(!s->budget--) { s->failed_pc=0x0c054ce6u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c054ce8;
P_0c054ce8: /* original 2f36, guest PC 0x0c054ce8 */
if(!s->budget--) { s->failed_pc=0x0c054ce8u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c054cea;
P_0c054cea: /* original 2f86, guest PC 0x0c054cea */
if(!s->budget--) { s->failed_pc=0x0c054ceau; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c054cec;
P_0c054cec: /* original 2f96, guest PC 0x0c054cec */
if(!s->budget--) { s->failed_pc=0x0c054cecu; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c054cee;
P_0c054cee: /* original 2fa6, guest PC 0x0c054cee */
if(!s->budget--) { s->failed_pc=0x0c054ceeu; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c054cf0;
P_0c054cf0: /* original 2fb6, guest PC 0x0c054cf0 */
if(!s->budget--) { s->failed_pc=0x0c054cf0u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c054cf2;
P_0c054cf2: /* original 4404, guest PC 0x0c054cf2 */
if(!s->budget--) { s->failed_pc=0x0c054cf2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]=(r[4]<<1)|(r[4]>>31);
goto P_0c054cf4;
P_0c054cf4: /* original 4604, guest PC 0x0c054cf4 */
if(!s->budget--) { s->failed_pc=0x0c054cf4u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]=(r[6]<<1)|(r[6]>>31);
goto P_0c054cf6;
P_0c054cf6: /* original 3462, guest PC 0x0c054cf6 */
if(!s->budget--) { s->failed_pc=0x0c054cf6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[6])!=0);
goto P_0c054cf8;
P_0c054cf8: /* original 8905, guest PC 0x0c054cf8 */
if(!s->budget--) { s->failed_pc=0x0c054cf8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054d06; }
goto P_0c054cfa;
P_0c054cfa: /* original 6243, guest PC 0x0c054cfa */
if(!s->budget--) { s->failed_pc=0x0c054cfau; return 0; }
r[2]=r[4];
goto P_0c054cfc;
P_0c054cfc: /* original 6463, guest PC 0x0c054cfc */
if(!s->budget--) { s->failed_pc=0x0c054cfcu; return 0; }
r[4]=r[6];
goto P_0c054cfe;
P_0c054cfe: /* original 6623, guest PC 0x0c054cfe */
if(!s->budget--) { s->failed_pc=0x0c054cfeu; return 0; }
r[6]=r[2];
goto P_0c054d00;
P_0c054d00: /* original 6253, guest PC 0x0c054d00 */
if(!s->budget--) { s->failed_pc=0x0c054d00u; return 0; }
r[2]=r[5];
goto P_0c054d02;
P_0c054d02: /* original 6573, guest PC 0x0c054d02 */
if(!s->budget--) { s->failed_pc=0x0c054d02u; return 0; }
r[5]=r[7];
goto P_0c054d04;
P_0c054d04: /* original 6723, guest PC 0x0c054d04 */
if(!s->budget--) { s->failed_pc=0x0c054d04u; return 0; }
r[7]=r[2];
goto P_0c054d06;
P_0c054d06: /* original 4405, guest PC 0x0c054d06 */
if(!s->budget--) { s->failed_pc=0x0c054d06u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1u)!=0);
r[4]=(r[4]>>1)|(r[4]<<31);
goto P_0c054d08;
P_0c054d08: /* original 4605, guest PC 0x0c054d08 */
if(!s->budget--) { s->failed_pc=0x0c054d08u; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1u)!=0);
r[6]=(r[6]>>1)|(r[6]<<31);
goto P_0c054d0a;
P_0c054d0a: /* original d379, guest PC 0x0c054d0a */
if(!s->budget--) { s->failed_pc=0x0c054d0au; return 0; }
r[3]=read(ram,0x0c054ef0u,4);
goto P_0c054d0c;
P_0c054d0c: /* original d079, guest PC 0x0c054d0c */
if(!s->budget--) { s->failed_pc=0x0c054d0cu; return 0; }
r[0]=read(ram,0x0c054ef4u,4);
goto P_0c054d0e;
P_0c054d0e: /* original 6a43, guest PC 0x0c054d0e */
if(!s->budget--) { s->failed_pc=0x0c054d0eu; return 0; }
r[10]=r[4];
goto P_0c054d10;
P_0c054d10: /* original 6b63, guest PC 0x0c054d10 */
if(!s->budget--) { s->failed_pc=0x0c054d10u; return 0; }
r[11]=r[6];
goto P_0c054d12;
P_0c054d12: /* original 6843, guest PC 0x0c054d12 */
if(!s->budget--) { s->failed_pc=0x0c054d12u; return 0; }
r[8]=r[4];
goto P_0c054d14;
P_0c054d14: /* original 4829, guest PC 0x0c054d14 */
if(!s->budget--) { s->failed_pc=0x0c054d14u; return 0; }
r[8]>>=16;
goto P_0c054d16;
P_0c054d16: /* original 4809, guest PC 0x0c054d16 */
if(!s->budget--) { s->failed_pc=0x0c054d16u; return 0; }
r[8]>>=2;
goto P_0c054d18;
P_0c054d18: /* original 4809, guest PC 0x0c054d18 */
if(!s->budget--) { s->failed_pc=0x0c054d18u; return 0; }
r[8]>>=2;
goto P_0c054d1a;
P_0c054d1a: /* original 2839, guest PC 0x0c054d1a */
if(!s->budget--) { s->failed_pc=0x0c054d1au; return 0; }
r[8]&=r[3];
goto P_0c054d1c;
P_0c054d1c: /* original 6963, guest PC 0x0c054d1c */
if(!s->budget--) { s->failed_pc=0x0c054d1cu; return 0; }
r[9]=r[6];
goto P_0c054d1e;
P_0c054d1e: /* original 4929, guest PC 0x0c054d1e */
if(!s->budget--) { s->failed_pc=0x0c054d1eu; return 0; }
r[9]>>=16;
goto P_0c054d20;
P_0c054d20: /* original 4909, guest PC 0x0c054d20 */
if(!s->budget--) { s->failed_pc=0x0c054d20u; return 0; }
r[9]>>=2;
goto P_0c054d22;
P_0c054d22: /* original 4909, guest PC 0x0c054d22 */
if(!s->budget--) { s->failed_pc=0x0c054d22u; return 0; }
r[9]>>=2;
goto P_0c054d24;
P_0c054d24: /* original 2939, guest PC 0x0c054d24 */
if(!s->budget--) { s->failed_pc=0x0c054d24u; return 0; }
r[9]&=r[3];
goto P_0c054d26;
P_0c054d26: /* original 2409, guest PC 0x0c054d26 */
if(!s->budget--) { s->failed_pc=0x0c054d26u; return 0; }
r[4]&=r[0];
goto P_0c054d28;
P_0c054d28: /* original 2609, guest PC 0x0c054d28 */
if(!s->budget--) { s->failed_pc=0x0c054d28u; return 0; }
r[6]&=r[0];
goto P_0c054d2a;
P_0c054d2a: /* original 3830, guest PC 0x0c054d2a */
if(!s->budget--) { s->failed_pc=0x0c054d2au; return 0; }
r[17]=(r[17]&~1u)|((r[8]==r[3])!=0);
goto P_0c054d2c;
P_0c054d2c: /* original 8982, guest PC 0x0c054d2c */
if(!s->budget--) { s->failed_pc=0x0c054d2cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054c34; }
goto P_0c054d2e;
P_0c054d2e: /* original 2998, guest PC 0x0c054d2e */
if(!s->budget--) { s->failed_pc=0x0c054d2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c054d30;
P_0c054d30: /* original 8990, guest PC 0x0c054d30 */
if(!s->budget--) { s->failed_pc=0x0c054d30u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054c54; }
goto P_0c054d32;
P_0c054d32: /* original 4500, guest PC 0x0c054d32 */
if(!s->budget--) { s->failed_pc=0x0c054d32u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054d34;
P_0c054d34: /* original 4424, guest PC 0x0c054d34 */
if(!s->budget--) { s->failed_pc=0x0c054d34u; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054d36;
P_0c054d36: /* original 4500, guest PC 0x0c054d36 */
if(!s->budget--) { s->failed_pc=0x0c054d36u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054d38;
P_0c054d38: /* original 4424, guest PC 0x0c054d38 */
if(!s->budget--) { s->failed_pc=0x0c054d38u; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054d3a;
P_0c054d3a: /* original 4500, guest PC 0x0c054d3a */
if(!s->budget--) { s->failed_pc=0x0c054d3au; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054d3c;
P_0c054d3c: /* original 4424, guest PC 0x0c054d3c */
if(!s->budget--) { s->failed_pc=0x0c054d3cu; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054d3e;
P_0c054d3e: /* original 4700, guest PC 0x0c054d3e */
if(!s->budget--) { s->failed_pc=0x0c054d3eu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c054d40;
P_0c054d40: /* original 4624, guest PC 0x0c054d40 */
if(!s->budget--) { s->failed_pc=0x0c054d40u; return 0; }
tmp=r[6]>>31; r[6]=(r[6]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054d42;
P_0c054d42: /* original 4700, guest PC 0x0c054d42 */
if(!s->budget--) { s->failed_pc=0x0c054d42u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c054d44;
P_0c054d44: /* original 4624, guest PC 0x0c054d44 */
if(!s->budget--) { s->failed_pc=0x0c054d44u; return 0; }
tmp=r[6]>>31; r[6]=(r[6]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054d46;
P_0c054d46: /* original 4700, guest PC 0x0c054d46 */
if(!s->budget--) { s->failed_pc=0x0c054d46u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c054d48;
P_0c054d48: /* original 4624, guest PC 0x0c054d48 */
if(!s->budget--) { s->failed_pc=0x0c054d48u; return 0; }
tmp=r[6]>>31; r[6]=(r[6]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054d4a;
P_0c054d4a: /* original d06b, guest PC 0x0c054d4a */
if(!s->budget--) { s->failed_pc=0x0c054d4au; return 0; }
r[0]=read(ram,0x0c054ef8u,4);
goto P_0c054d4c;
P_0c054d4c: /* original 240b, guest PC 0x0c054d4c */
if(!s->budget--) { s->failed_pc=0x0c054d4cu; return 0; }
r[4]|=r[0];
goto P_0c054d4e;
P_0c054d4e: /* original 260b, guest PC 0x0c054d4e */
if(!s->budget--) { s->failed_pc=0x0c054d4eu; return 0; }
r[6]|=r[0];
goto P_0c054d50;
P_0c054d50: /* original 6283, guest PC 0x0c054d50 */
if(!s->budget--) { s->failed_pc=0x0c054d50u; return 0; }
r[2]=r[8];
goto P_0c054d52;
P_0c054d52: /* original 3298, guest PC 0x0c054d52 */
if(!s->budget--) { s->failed_pc=0x0c054d52u; return 0; }
r[2]-=r[9];
goto P_0c054d54;
P_0c054d54: /* original 2228, guest PC 0x0c054d54 */
if(!s->budget--) { s->failed_pc=0x0c054d54u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c054d56;
P_0c054d56: /* original 8929, guest PC 0x0c054d56 */
if(!s->budget--) { s->failed_pc=0x0c054d56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054dac; }
goto P_0c054d58;
P_0c054d58: /* original e303, guest PC 0x0c054d58 */
if(!s->budget--) { s->failed_pc=0x0c054d58u; return 0; }
r[3]=0x00000003u;
goto P_0c054d5a;
P_0c054d5a: /* original 3323, guest PC 0x0c054d5a */
if(!s->budget--) { s->failed_pc=0x0c054d5au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c054d5c;
P_0c054d5c: /* original 8922, guest PC 0x0c054d5c */
if(!s->budget--) { s->failed_pc=0x0c054d5cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054da4; }
goto P_0c054d5e;
P_0c054d5e: /* original e336, guest PC 0x0c054d5e */
if(!s->budget--) { s->failed_pc=0x0c054d5eu; return 0; }
r[3]=0x00000036u;
goto P_0c054d60;
P_0c054d60: /* original 3237, guest PC 0x0c054d60 */
if(!s->budget--) { s->failed_pc=0x0c054d60u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[3])!=0);
goto P_0c054d62;
P_0c054d62: /* original 891c, guest PC 0x0c054d62 */
if(!s->budget--) { s->failed_pc=0x0c054d62u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054d9e; }
goto P_0c054d64;
P_0c054d64: /* original e320, guest PC 0x0c054d64 */
if(!s->budget--) { s->failed_pc=0x0c054d64u; return 0; }
r[3]=0x00000020u;
goto P_0c054d66;
P_0c054d66: /* original 3237, guest PC 0x0c054d66 */
if(!s->budget--) { s->failed_pc=0x0c054d66u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[3])!=0);
goto P_0c054d68;
P_0c054d68: /* original 8f06, guest PC 0x0c054d68 */
if(!s->budget--) { s->failed_pc=0x0c054d68u; return 0; }
cond=r[17]&1u;
r[9]=0x00000001u;
if(!cond) { goto P_0c054d78; }
goto P_0c054d6c;
P_0c054d6a: /* original e901, guest PC 0x0c054d6a */
if(!s->budget--) { s->failed_pc=0x0c054d6au; return 0; }
r[9]=0x00000001u;
goto P_0c054d6c;
P_0c054d6c: /* original 3238, guest PC 0x0c054d6c */
if(!s->budget--) { s->failed_pc=0x0c054d6cu; return 0; }
r[2]-=r[3];
goto P_0c054d6e;
P_0c054d6e: /* original 2778, guest PC 0x0c054d6e */
if(!s->budget--) { s->failed_pc=0x0c054d6eu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c054d70;
P_0c054d70: /* original 8900, guest PC 0x0c054d70 */
if(!s->budget--) { s->failed_pc=0x0c054d70u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054d74; }
goto P_0c054d72;
P_0c054d72: /* original 269b, guest PC 0x0c054d72 */
if(!s->budget--) { s->failed_pc=0x0c054d72u; return 0; }
r[6]|=r[9];
goto P_0c054d74;
P_0c054d74: /* original 6763, guest PC 0x0c054d74 */
if(!s->budget--) { s->failed_pc=0x0c054d74u; return 0; }
r[7]=r[6];
goto P_0c054d76;
P_0c054d76: /* original e600, guest PC 0x0c054d76 */
if(!s->budget--) { s->failed_pc=0x0c054d76u; return 0; }
r[6]=0x00000000u;
goto P_0c054d78;
P_0c054d78: /* original 4f02, guest PC 0x0c054d78 */
if(!s->budget--) { s->failed_pc=0x0c054d78u; return 0; }
r[15]-=4; write(ram,r[15],r[20],4);
goto P_0c054d7a;
P_0c054d7a: /* original c765, guest PC 0x0c054d7a */
if(!s->budget--) { s->failed_pc=0x0c054d7au; return 0; }
r[0]=0x0c054f10u;
goto P_0c054d7c;
P_0c054d7c: /* original 4f12, guest PC 0x0c054d7c */
if(!s->budget--) { s->failed_pc=0x0c054d7cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c054d7e;
P_0c054d7e: /* original 4208, guest PC 0x0c054d7e */
if(!s->budget--) { s->failed_pc=0x0c054d7eu; return 0; }
r[2]<<=2;
goto P_0c054d80;
P_0c054d80: /* original 302c, guest PC 0x0c054d80 */
if(!s->budget--) { s->failed_pc=0x0c054d80u; return 0; }
r[0]+=r[2];
goto P_0c054d82;
P_0c054d82: /* original 6002, guest PC 0x0c054d82 */
if(!s->budget--) { s->failed_pc=0x0c054d82u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c054d84;
P_0c054d84: /* original 3705, guest PC 0x0c054d84 */
if(!s->budget--) { s->failed_pc=0x0c054d84u; return 0; }
wide=(uint64_t)r[7]*r[0]; r[19]=(uint32_t)wide; r[20]=(uint32_t)(wide>>32);
goto P_0c054d86;
P_0c054d86: /* original 070a, guest PC 0x0c054d86 */
if(!s->budget--) { s->failed_pc=0x0c054d86u; return 0; }
r[7]=r[20];
goto P_0c054d88;
P_0c054d88: /* original 021a, guest PC 0x0c054d88 */
if(!s->budget--) { s->failed_pc=0x0c054d88u; return 0; }
r[2]=r[19];
goto P_0c054d8a;
P_0c054d8a: /* original 3605, guest PC 0x0c054d8a */
if(!s->budget--) { s->failed_pc=0x0c054d8au; return 0; }
wide=(uint64_t)r[6]*r[0]; r[19]=(uint32_t)wide; r[20]=(uint32_t)(wide>>32);
goto P_0c054d8c;
P_0c054d8c: /* original 060a, guest PC 0x0c054d8c */
if(!s->budget--) { s->failed_pc=0x0c054d8cu; return 0; }
r[6]=r[20];
goto P_0c054d8e;
P_0c054d8e: /* original 031a, guest PC 0x0c054d8e */
if(!s->budget--) { s->failed_pc=0x0c054d8eu; return 0; }
r[3]=r[19];
goto P_0c054d90;
P_0c054d90: /* original 4f16, guest PC 0x0c054d90 */
if(!s->budget--) { s->failed_pc=0x0c054d90u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c054d92;
P_0c054d92: /* original 2228, guest PC 0x0c054d92 */
if(!s->budget--) { s->failed_pc=0x0c054d92u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c054d94;
P_0c054d94: /* original 4f06, guest PC 0x0c054d94 */
if(!s->budget--) { s->failed_pc=0x0c054d94u; return 0; }
r[20]=read(ram,r[15],4); r[15]+=4;
goto P_0c054d96;
P_0c054d96: /* original 8d09, guest PC 0x0c054d96 */
if(!s->budget--) { s->failed_pc=0x0c054d96u; return 0; }
cond=r[17]&1u;
r[7]|=r[3];
if(cond) { goto P_0c054dac; }
goto P_0c054d9a;
P_0c054d98: /* original 273b, guest PC 0x0c054d98 */
if(!s->budget--) { s->failed_pc=0x0c054d98u; return 0; }
r[7]|=r[3];
goto P_0c054d9a;
P_0c054d9a: /* original a007, guest PC 0x0c054d9a */
if(!s->budget--) { s->failed_pc=0x0c054d9au; return 0; }
r[7]|=r[9];
goto P_0c054dac;
P_0c054d9c: /* original 279b, guest PC 0x0c054d9c */
if(!s->budget--) { s->failed_pc=0x0c054d9cu; return 0; }
r[7]|=r[9];
goto P_0c054d9e;
P_0c054d9e: /* original e600, guest PC 0x0c054d9e */
if(!s->budget--) { s->failed_pc=0x0c054d9eu; return 0; }
r[6]=0x00000000u;
goto P_0c054da0;
P_0c054da0: /* original a004, guest PC 0x0c054da0 */
if(!s->budget--) { s->failed_pc=0x0c054da0u; return 0; }
r[7]=0x00000001u;
goto P_0c054dac;
P_0c054da2: /* original e701, guest PC 0x0c054da2 */
if(!s->budget--) { s->failed_pc=0x0c054da2u; return 0; }
r[7]=0x00000001u;
goto P_0c054da4;
P_0c054da4: /* original 4601, guest PC 0x0c054da4 */
if(!s->budget--) { s->failed_pc=0x0c054da4u; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]>>=1;
goto P_0c054da6;
P_0c054da6: /* original 4725, guest PC 0x0c054da6 */
if(!s->budget--) { s->failed_pc=0x0c054da6u; return 0; }
tmp=r[7]&1u; r[7]=(r[7]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054da8;
P_0c054da8: /* original 4210, guest PC 0x0c054da8 */
if(!s->budget--) { s->failed_pc=0x0c054da8u; return 0; }
--r[2];
r[17]=(r[17]&~1u)|((r[2]==0)!=0);
goto P_0c054daa;
P_0c054daa: /* original 8bfb, guest PC 0x0c054daa */
if(!s->budget--) { s->failed_pc=0x0c054daau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054da4; }
goto P_0c054dac;
P_0c054dac: /* original 2ba7, guest PC 0x0c054dac */
if(!s->budget--) { s->failed_pc=0x0c054dacu; return 0; }
r[17]=(r[17]&~0x301u)|((r[11]>>31)<<8)|((r[10]>>31)<<9)|(((r[11]^r[10])>>31)&1u);
goto P_0c054dae;
P_0c054dae: /* original 890f, guest PC 0x0c054dae */
if(!s->budget--) { s->failed_pc=0x0c054daeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054dd0; }
goto P_0c054db0;
P_0c054db0: /* original 357e, guest PC 0x0c054db0 */
if(!s->budget--) { s->failed_pc=0x0c054db0u; return 0; }
wide=(uint64_t)r[5]+r[7]+(r[17]&1u); r[5]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c054db2;
P_0c054db2: /* original 346e, guest PC 0x0c054db2 */
if(!s->budget--) { s->failed_pc=0x0c054db2u; return 0; }
wide=(uint64_t)r[4]+r[6]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c054db4;
P_0c054db4: /* original d352, guest PC 0x0c054db4 */
if(!s->budget--) { s->failed_pc=0x0c054db4u; return 0; }
r[3]=read(ram,0x0c054f00u,4);
goto P_0c054db6;
P_0c054db6: /* original 3347, guest PC 0x0c054db6 */
if(!s->budget--) { s->failed_pc=0x0c054db6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[4])!=0);
goto P_0c054db8;
P_0c054db8: /* original 8952, guest PC 0x0c054db8 */
if(!s->budget--) { s->failed_pc=0x0c054db8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054e60; }
goto P_0c054dba;
P_0c054dba: /* original 4401, guest PC 0x0c054dba */
if(!s->budget--) { s->failed_pc=0x0c054dbau; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c054dbc;
P_0c054dbc: /* original 4525, guest PC 0x0c054dbc */
if(!s->budget--) { s->failed_pc=0x0c054dbcu; return 0; }
tmp=r[5]&1u; r[5]=(r[5]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054dbe;
P_0c054dbe: /* original 0229, guest PC 0x0c054dbe */
if(!s->budget--) { s->failed_pc=0x0c054dbeu; return 0; }
r[2]=r[17]&1u;
goto P_0c054dc0;
P_0c054dc0: /* original 252b, guest PC 0x0c054dc0 */
if(!s->budget--) { s->failed_pc=0x0c054dc0u; return 0; }
r[5]|=r[2];
goto P_0c054dc2;
P_0c054dc2: /* original 7801, guest PC 0x0c054dc2 */
if(!s->budget--) { s->failed_pc=0x0c054dc2u; return 0; }
r[8]+=0x00000001u;
goto P_0c054dc4;
P_0c054dc4: /* original d34a, guest PC 0x0c054dc4 */
if(!s->budget--) { s->failed_pc=0x0c054dc4u; return 0; }
r[3]=read(ram,0x0c054ef0u,4);
goto P_0c054dc6;
P_0c054dc6: /* original 3830, guest PC 0x0c054dc6 */
if(!s->budget--) { s->failed_pc=0x0c054dc6u; return 0; }
r[17]=(r[17]&~1u)|((r[8]==r[3])!=0);
goto P_0c054dc8;
P_0c054dc8: /* original 8b4a, guest PC 0x0c054dc8 */
if(!s->budget--) { s->failed_pc=0x0c054dc8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054e60; }
goto P_0c054dca;
P_0c054dca: /* original e500, guest PC 0x0c054dca */
if(!s->budget--) { s->failed_pc=0x0c054dcau; return 0; }
r[5]=0x00000000u;
goto P_0c054dcc;
P_0c054dcc: /* original a05f, guest PC 0x0c054dcc */
if(!s->budget--) { s->failed_pc=0x0c054dccu; return 0; }
r[4]=0x00000000u;
goto P_0c054e8e;
P_0c054dce: /* original e400, guest PC 0x0c054dce */
if(!s->budget--) { s->failed_pc=0x0c054dceu; return 0; }
r[4]=0x00000000u;
goto P_0c054dd0;
P_0c054dd0: /* original 3640, guest PC 0x0c054dd0 */
if(!s->budget--) { s->failed_pc=0x0c054dd0u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[4])!=0);
goto P_0c054dd2;
P_0c054dd2: /* original 8b01, guest PC 0x0c054dd2 */
if(!s->budget--) { s->failed_pc=0x0c054dd2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054dd8; }
goto P_0c054dd4;
P_0c054dd4: /* original 3750, guest PC 0x0c054dd4 */
if(!s->budget--) { s->failed_pc=0x0c054dd4u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[5])!=0);
goto P_0c054dd6;
P_0c054dd6: /* original 8979, guest PC 0x0c054dd6 */
if(!s->budget--) { s->failed_pc=0x0c054dd6u; return 0; }
cond=r[17]&1u;
if(cond) { return vf3_matrix_family(0x0c054eccu,s,ram); }
goto P_0c054dd8;
P_0c054dd8: /* original 357a, guest PC 0x0c054dd8 */
if(!s->budget--) { s->failed_pc=0x0c054dd8u; return 0; }
wide=(uint64_t)r[5]-r[7]-(r[17]&1u); r[5]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c054dda;
P_0c054dda: /* original 346a, guest PC 0x0c054dda */
if(!s->budget--) { s->failed_pc=0x0c054ddau; return 0; }
wide=(uint64_t)r[4]-r[6]-(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c054ddc;
P_0c054ddc: /* original 8b03, guest PC 0x0c054ddc */
if(!s->budget--) { s->failed_pc=0x0c054ddcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054de6; }
goto P_0c054dde;
P_0c054dde: /* original 0008, guest PC 0x0c054dde */
if(!s->budget--) { s->failed_pc=0x0c054ddeu; return 0; }
r[17]=(r[17]&~1u)|((0)!=0);
goto P_0c054de0;
P_0c054de0: /* original 655a, guest PC 0x0c054de0 */
if(!s->budget--) { s->failed_pc=0x0c054de0u; return 0; }
s->failed_pc=0x0c054de0u; return 0;
goto P_0c054de2;
P_0c054de2: /* original 644a, guest PC 0x0c054de2 */
if(!s->budget--) { s->failed_pc=0x0c054de2u; return 0; }
s->failed_pc=0x0c054de2u; return 0;
goto P_0c054de4;
P_0c054de4: /* original 6ab3, guest PC 0x0c054de4 */
if(!s->budget--) { s->failed_pc=0x0c054de4u; return 0; }
r[10]=r[11];
goto P_0c054de6;
P_0c054de6: /* original 2448, guest PC 0x0c054de6 */
if(!s->budget--) { s->failed_pc=0x0c054de6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c054de8;
P_0c054de8: /* original 8b02, guest PC 0x0c054de8 */
if(!s->budget--) { s->failed_pc=0x0c054de8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054df0; }
goto P_0c054dea;
P_0c054dea: /* original 6453, guest PC 0x0c054dea */
if(!s->budget--) { s->failed_pc=0x0c054deau; return 0; }
r[4]=r[5];
goto P_0c054dec;
P_0c054dec: /* original e500, guest PC 0x0c054dec */
if(!s->budget--) { s->failed_pc=0x0c054decu; return 0; }
r[5]=0x00000000u;
goto P_0c054dee;
P_0c054dee: /* original 78e0, guest PC 0x0c054dee */
if(!s->budget--) { s->failed_pc=0x0c054deeu; return 0; }
r[8]+=0xffffffe0u;
goto P_0c054df0;
P_0c054df0: /* original d346, guest PC 0x0c054df0 */
if(!s->budget--) { s->failed_pc=0x0c054df0u; return 0; }
r[3]=read(ram,0x0c054f0cu,4);
goto P_0c054df2;
P_0c054df2: /* original 2348, guest PC 0x0c054df2 */
if(!s->budget--) { s->failed_pc=0x0c054df2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c054df4;
P_0c054df4: /* original 8b04, guest PC 0x0c054df4 */
if(!s->budget--) { s->failed_pc=0x0c054df4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054e00; }
goto P_0c054df6;
P_0c054df6: /* original 6353, guest PC 0x0c054df6 */
if(!s->budget--) { s->failed_pc=0x0c054df6u; return 0; }
r[3]=r[5];
goto P_0c054df8;
P_0c054df8: /* original 234d, guest PC 0x0c054df8 */
if(!s->budget--) { s->failed_pc=0x0c054df8u; return 0; }
r[3]=(r[3]>>16)|(r[4]<<16);
goto P_0c054dfa;
P_0c054dfa: /* original 6433, guest PC 0x0c054dfa */
if(!s->budget--) { s->failed_pc=0x0c054dfau; return 0; }
r[4]=r[3];
goto P_0c054dfc;
P_0c054dfc: /* original 4528, guest PC 0x0c054dfc */
if(!s->budget--) { s->failed_pc=0x0c054dfcu; return 0; }
r[5]<<=16;
goto P_0c054dfe;
P_0c054dfe: /* original 78f0, guest PC 0x0c054dfe */
if(!s->budget--) { s->failed_pc=0x0c054dfeu; return 0; }
r[8]+=0xfffffff0u;
goto P_0c054e00;
P_0c054e00: /* original d33f, guest PC 0x0c054e00 */
if(!s->budget--) { s->failed_pc=0x0c054e00u; return 0; }
r[3]=read(ram,0x0c054f00u,4);
goto P_0c054e02;
P_0c054e02: /* original 3346, guest PC 0x0c054e02 */
if(!s->budget--) { s->failed_pc=0x0c054e02u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[4])!=0);
goto P_0c054e04;
P_0c054e04: /* original 8915, guest PC 0x0c054e04 */
if(!s->budget--) { s->failed_pc=0x0c054e04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054e32; }
goto P_0c054e06;
P_0c054e06: /* original 4401, guest PC 0x0c054e06 */
if(!s->budget--) { s->failed_pc=0x0c054e06u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c054e08;
P_0c054e08: /* original 4525, guest PC 0x0c054e08 */
if(!s->budget--) { s->failed_pc=0x0c054e08u; return 0; }
tmp=r[5]&1u; r[5]=(r[5]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e0a;
P_0c054e0a: /* original 3346, guest PC 0x0c054e0a */
if(!s->budget--) { s->failed_pc=0x0c054e0au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[4])!=0);
goto P_0c054e0c;
P_0c054e0c: /* original 8d28, guest PC 0x0c054e0c */
if(!s->budget--) { s->failed_pc=0x0c054e0cu; return 0; }
cond=r[17]&1u;
r[8]+=0x00000001u;
if(cond) { goto P_0c054e60; }
goto P_0c054e10;
P_0c054e0e: /* original 7801, guest PC 0x0c054e0e */
if(!s->budget--) { s->failed_pc=0x0c054e0eu; return 0; }
r[8]+=0x00000001u;
goto P_0c054e10;
P_0c054e10: /* original 4401, guest PC 0x0c054e10 */
if(!s->budget--) { s->failed_pc=0x0c054e10u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c054e12;
P_0c054e12: /* original 4525, guest PC 0x0c054e12 */
if(!s->budget--) { s->failed_pc=0x0c054e12u; return 0; }
tmp=r[5]&1u; r[5]=(r[5]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e14;
P_0c054e14: /* original 3346, guest PC 0x0c054e14 */
if(!s->budget--) { s->failed_pc=0x0c054e14u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[4])!=0);
goto P_0c054e16;
P_0c054e16: /* original 8d23, guest PC 0x0c054e16 */
if(!s->budget--) { s->failed_pc=0x0c054e16u; return 0; }
cond=r[17]&1u;
r[8]+=0x00000001u;
if(cond) { goto P_0c054e60; }
goto P_0c054e1a;
P_0c054e18: /* original 7801, guest PC 0x0c054e18 */
if(!s->budget--) { s->failed_pc=0x0c054e18u; return 0; }
r[8]+=0x00000001u;
goto P_0c054e1a;
P_0c054e1a: /* original 4401, guest PC 0x0c054e1a */
if(!s->budget--) { s->failed_pc=0x0c054e1au; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c054e1c;
P_0c054e1c: /* original 4525, guest PC 0x0c054e1c */
if(!s->budget--) { s->failed_pc=0x0c054e1cu; return 0; }
tmp=r[5]&1u; r[5]=(r[5]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e1e;
P_0c054e1e: /* original 3346, guest PC 0x0c054e1e */
if(!s->budget--) { s->failed_pc=0x0c054e1eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[4])!=0);
goto P_0c054e20;
P_0c054e20: /* original 8d1e, guest PC 0x0c054e20 */
if(!s->budget--) { s->failed_pc=0x0c054e20u; return 0; }
cond=r[17]&1u;
r[8]+=0x00000001u;
if(cond) { goto P_0c054e60; }
goto P_0c054e24;
P_0c054e22: /* original 7801, guest PC 0x0c054e22 */
if(!s->budget--) { s->failed_pc=0x0c054e22u; return 0; }
r[8]+=0x00000001u;
goto P_0c054e24;
P_0c054e24: /* original 4401, guest PC 0x0c054e24 */
if(!s->budget--) { s->failed_pc=0x0c054e24u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c054e26;
P_0c054e26: /* original 4525, guest PC 0x0c054e26 */
if(!s->budget--) { s->failed_pc=0x0c054e26u; return 0; }
tmp=r[5]&1u; r[5]=(r[5]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e28;
P_0c054e28: /* original 3346, guest PC 0x0c054e28 */
if(!s->budget--) { s->failed_pc=0x0c054e28u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[4])!=0);
goto P_0c054e2a;
P_0c054e2a: /* original 8d19, guest PC 0x0c054e2a */
if(!s->budget--) { s->failed_pc=0x0c054e2au; return 0; }
cond=r[17]&1u;
r[8]+=0x00000001u;
if(cond) { goto P_0c054e60; }
goto P_0c054e2e;
P_0c054e2c: /* original 7801, guest PC 0x0c054e2c */
if(!s->budget--) { s->failed_pc=0x0c054e2cu; return 0; }
r[8]+=0x00000001u;
goto P_0c054e2e;
P_0c054e2e: /* original afea, guest PC 0x0c054e2e */
if(!s->budget--) { s->failed_pc=0x0c054e2eu; return 0; }
goto P_0c054e06;
P_0c054e30: /* original 0009, guest PC 0x0c054e30 */
if(!s->budget--) { s->failed_pc=0x0c054e30u; return 0; }
goto P_0c054e32;
P_0c054e32: /* original d331, guest PC 0x0c054e32 */
if(!s->budget--) { s->failed_pc=0x0c054e32u; return 0; }
r[3]=read(ram,0x0c054ef8u,4);
goto P_0c054e34;
P_0c054e34: /* original 3433, guest PC 0x0c054e34 */
if(!s->budget--) { s->failed_pc=0x0c054e34u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c054e36;
P_0c054e36: /* original 8913, guest PC 0x0c054e36 */
if(!s->budget--) { s->failed_pc=0x0c054e36u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054e60; }
goto P_0c054e38;
P_0c054e38: /* original 4500, guest PC 0x0c054e38 */
if(!s->budget--) { s->failed_pc=0x0c054e38u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054e3a;
P_0c054e3a: /* original 4424, guest PC 0x0c054e3a */
if(!s->budget--) { s->failed_pc=0x0c054e3au; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e3c;
P_0c054e3c: /* original 3433, guest PC 0x0c054e3c */
if(!s->budget--) { s->failed_pc=0x0c054e3cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c054e3e;
P_0c054e3e: /* original 8d0f, guest PC 0x0c054e3e */
if(!s->budget--) { s->failed_pc=0x0c054e3eu; return 0; }
cond=r[17]&1u;
r[8]+=0xffffffffu;
if(cond) { goto P_0c054e60; }
goto P_0c054e42;
P_0c054e40: /* original 78ff, guest PC 0x0c054e40 */
if(!s->budget--) { s->failed_pc=0x0c054e40u; return 0; }
r[8]+=0xffffffffu;
goto P_0c054e42;
P_0c054e42: /* original 4500, guest PC 0x0c054e42 */
if(!s->budget--) { s->failed_pc=0x0c054e42u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054e44;
P_0c054e44: /* original 4424, guest PC 0x0c054e44 */
if(!s->budget--) { s->failed_pc=0x0c054e44u; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e46;
P_0c054e46: /* original 3433, guest PC 0x0c054e46 */
if(!s->budget--) { s->failed_pc=0x0c054e46u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c054e48;
P_0c054e48: /* original 8d0a, guest PC 0x0c054e48 */
if(!s->budget--) { s->failed_pc=0x0c054e48u; return 0; }
cond=r[17]&1u;
r[8]+=0xffffffffu;
if(cond) { goto P_0c054e60; }
goto P_0c054e4c;
P_0c054e4a: /* original 78ff, guest PC 0x0c054e4a */
if(!s->budget--) { s->failed_pc=0x0c054e4au; return 0; }
r[8]+=0xffffffffu;
goto P_0c054e4c;
P_0c054e4c: /* original 4500, guest PC 0x0c054e4c */
if(!s->budget--) { s->failed_pc=0x0c054e4cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054e4e;
P_0c054e4e: /* original 4424, guest PC 0x0c054e4e */
if(!s->budget--) { s->failed_pc=0x0c054e4eu; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e50;
P_0c054e50: /* original 3433, guest PC 0x0c054e50 */
if(!s->budget--) { s->failed_pc=0x0c054e50u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c054e52;
P_0c054e52: /* original 8d05, guest PC 0x0c054e52 */
if(!s->budget--) { s->failed_pc=0x0c054e52u; return 0; }
cond=r[17]&1u;
r[8]+=0xffffffffu;
if(cond) { goto P_0c054e60; }
goto P_0c054e56;
P_0c054e54: /* original 78ff, guest PC 0x0c054e54 */
if(!s->budget--) { s->failed_pc=0x0c054e54u; return 0; }
r[8]+=0xffffffffu;
goto P_0c054e56;
P_0c054e56: /* original 4500, guest PC 0x0c054e56 */
if(!s->budget--) { s->failed_pc=0x0c054e56u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054e58;
P_0c054e58: /* original 4424, guest PC 0x0c054e58 */
if(!s->budget--) { s->failed_pc=0x0c054e58u; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e5a;
P_0c054e5a: /* original 3433, guest PC 0x0c054e5a */
if(!s->budget--) { s->failed_pc=0x0c054e5au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c054e5c;
P_0c054e5c: /* original 8fec, guest PC 0x0c054e5c */
if(!s->budget--) { s->failed_pc=0x0c054e5cu; return 0; }
cond=r[17]&1u;
r[8]+=0xffffffffu;
if(!cond) { goto P_0c054e38; }
goto P_0c054e60;
P_0c054e5e: /* original 78ff, guest PC 0x0c054e5e */
if(!s->budget--) { s->failed_pc=0x0c054e5eu; return 0; }
r[8]+=0xffffffffu;
goto P_0c054e60;
P_0c054e60: /* original 4815, guest PC 0x0c054e60 */
if(!s->budget--) { s->failed_pc=0x0c054e60u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>0)!=0);
goto P_0c054e62;
P_0c054e62: /* original 8905, guest PC 0x0c054e62 */
if(!s->budget--) { s->failed_pc=0x0c054e62u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054e70; }
goto P_0c054e64;
P_0c054e64: /* original 688b, guest PC 0x0c054e64 */
if(!s->budget--) { s->failed_pc=0x0c054e64u; return 0; }
r[8]=0u-r[8];
goto P_0c054e66;
P_0c054e66: /* original 7801, guest PC 0x0c054e66 */
if(!s->budget--) { s->failed_pc=0x0c054e66u; return 0; }
r[8]+=0x00000001u;
goto P_0c054e68;
P_0c054e68: /* original 4401, guest PC 0x0c054e68 */
if(!s->budget--) { s->failed_pc=0x0c054e68u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c054e6a;
P_0c054e6a: /* original 4525, guest PC 0x0c054e6a */
if(!s->budget--) { s->failed_pc=0x0c054e6au; return 0; }
tmp=r[5]&1u; r[5]=(r[5]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e6c;
P_0c054e6c: /* original 4810, guest PC 0x0c054e6c */
if(!s->budget--) { s->failed_pc=0x0c054e6cu; return 0; }
--r[8];
r[17]=(r[17]&~1u)|((r[8]==0)!=0);
goto P_0c054e6e;
P_0c054e6e: /* original 8bfb, guest PC 0x0c054e6e */
if(!s->budget--) { s->failed_pc=0x0c054e6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054e68; }
goto P_0c054e70;
P_0c054e70: /* original 6053, guest PC 0x0c054e70 */
if(!s->budget--) { s->failed_pc=0x0c054e70u; return 0; }
r[0]=r[5];
goto P_0c054e72;
P_0c054e72: /* original c804, guest PC 0x0c054e72 */
if(!s->budget--) { s->failed_pc=0x0c054e72u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c054e74;
P_0c054e74: /* original 890b, guest PC 0x0c054e74 */
if(!s->budget--) { s->failed_pc=0x0c054e74u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054e8e; }
goto P_0c054e76;
P_0c054e76: /* original c80b, guest PC 0x0c054e76 */
if(!s->budget--) { s->failed_pc=0x0c054e76u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&11u)==0)!=0);
goto P_0c054e78;
P_0c054e78: /* original 8909, guest PC 0x0c054e78 */
if(!s->budget--) { s->failed_pc=0x0c054e78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054e8e; }
goto P_0c054e7a;
P_0c054e7a: /* original e008, guest PC 0x0c054e7a */
if(!s->budget--) { s->failed_pc=0x0c054e7au; return 0; }
r[0]=0x00000008u;
goto P_0c054e7c;
P_0c054e7c: /* original 350e, guest PC 0x0c054e7c */
if(!s->budget--) { s->failed_pc=0x0c054e7cu; return 0; }
wide=(uint64_t)r[5]+r[0]+(r[17]&1u); r[5]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c054e7e;
P_0c054e7e: /* original e000, guest PC 0x0c054e7e */
if(!s->budget--) { s->failed_pc=0x0c054e7eu; return 0; }
r[0]=0x00000000u;
goto P_0c054e80;
P_0c054e80: /* original 340e, guest PC 0x0c054e80 */
if(!s->budget--) { s->failed_pc=0x0c054e80u; return 0; }
wide=(uint64_t)r[4]+r[0]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c054e82;
P_0c054e82: /* original d01f, guest PC 0x0c054e82 */
if(!s->budget--) { s->failed_pc=0x0c054e82u; return 0; }
r[0]=read(ram,0x0c054f00u,4);
goto P_0c054e84;
P_0c054e84: /* original 3047, guest PC 0x0c054e84 */
if(!s->budget--) { s->failed_pc=0x0c054e84u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>(int32_t)r[4])!=0);
goto P_0c054e86;
P_0c054e86: /* original 8902, guest PC 0x0c054e86 */
if(!s->budget--) { s->failed_pc=0x0c054e86u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054e8e; }
goto P_0c054e88;
P_0c054e88: /* original 4401, guest PC 0x0c054e88 */
if(!s->budget--) { s->failed_pc=0x0c054e88u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c054e8a;
P_0c054e8a: /* original 4525, guest PC 0x0c054e8a */
if(!s->budget--) { s->failed_pc=0x0c054e8au; return 0; }
tmp=r[5]&1u; r[5]=(r[5]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e8c;
P_0c054e8c: /* original 7801, guest PC 0x0c054e8c */
if(!s->budget--) { s->failed_pc=0x0c054e8cu; return 0; }
r[8]+=0x00000001u;
goto P_0c054e8e;
P_0c054e8e: /* original 4401, guest PC 0x0c054e8e */
if(!s->budget--) { s->failed_pc=0x0c054e8eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c054e90;
P_0c054e90: /* original 4525, guest PC 0x0c054e90 */
if(!s->budget--) { s->failed_pc=0x0c054e90u; return 0; }
tmp=r[5]&1u; r[5]=(r[5]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e92;
P_0c054e92: /* original 4401, guest PC 0x0c054e92 */
if(!s->budget--) { s->failed_pc=0x0c054e92u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c054e94;
P_0c054e94: /* original 4525, guest PC 0x0c054e94 */
if(!s->budget--) { s->failed_pc=0x0c054e94u; return 0; }
tmp=r[5]&1u; r[5]=(r[5]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e96;
P_0c054e96: /* original 4401, guest PC 0x0c054e96 */
if(!s->budget--) { s->failed_pc=0x0c054e96u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c054e98;
P_0c054e98: /* original 4525, guest PC 0x0c054e98 */
if(!s->budget--) { s->failed_pc=0x0c054e98u; return 0; }
tmp=r[5]&1u; r[5]=(r[5]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054e9a;
P_0c054e9a: /* original d016, guest PC 0x0c054e9a */
if(!s->budget--) { s->failed_pc=0x0c054e9au; return 0; }
r[0]=read(ram,0x0c054ef4u,4);
goto P_0c054e9c;
P_0c054e9c: /* original 2409, guest PC 0x0c054e9c */
if(!s->budget--) { s->failed_pc=0x0c054e9cu; return 0; }
r[4]&=r[0];
goto P_0c054e9e;
P_0c054e9e: /* original 4828, guest PC 0x0c054e9e */
if(!s->budget--) { s->failed_pc=0x0c054e9eu; return 0; }
r[8]<<=16;
goto P_0c054ea0;
P_0c054ea0: /* original 4808, guest PC 0x0c054ea0 */
if(!s->budget--) { s->failed_pc=0x0c054ea0u; return 0; }
r[8]<<=2;
goto P_0c054ea2;
P_0c054ea2: /* original 4808, guest PC 0x0c054ea2 */
if(!s->budget--) { s->failed_pc=0x0c054ea2u; return 0; }
r[8]<<=2;
goto P_0c054ea4;
P_0c054ea4: /* original 248b, guest PC 0x0c054ea4 */
if(!s->budget--) { s->failed_pc=0x0c054ea4u; return 0; }
r[4]|=r[8];
goto P_0c054ea6;
P_0c054ea6: /* original 4400, guest PC 0x0c054ea6 */
if(!s->budget--) { s->failed_pc=0x0c054ea6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c054ea8;
P_0c054ea8: /* original 4a00, guest PC 0x0c054ea8 */
if(!s->budget--) { s->failed_pc=0x0c054ea8u; return 0; }
r[17]=(r[17]&~1u)|((r[10]>>31)!=0);
r[10]<<=1;
goto P_0c054eaa;
P_0c054eaa: /* original 4425, guest PC 0x0c054eaa */
if(!s->budget--) { s->failed_pc=0x0c054eaau; return 0; }
tmp=r[4]&1u; r[4]=(r[4]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054eac;
P_0c054eac: /* original 6bf6, guest PC 0x0c054eac */
if(!s->budget--) { s->failed_pc=0x0c054eacu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c054eae;
P_0c054eae: /* original 6af6, guest PC 0x0c054eae */
if(!s->budget--) { s->failed_pc=0x0c054eaeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c054eb0;
P_0c054eb0: /* original 69f6, guest PC 0x0c054eb0 */
if(!s->budget--) { s->failed_pc=0x0c054eb0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c054eb2;
P_0c054eb2: /* original 68f6, guest PC 0x0c054eb2 */
if(!s->budget--) { s->failed_pc=0x0c054eb2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c054eb4;
P_0c054eb4: /* original 63f6, guest PC 0x0c054eb4 */
if(!s->budget--) { s->failed_pc=0x0c054eb4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c054eb6;
P_0c054eb6: /* original 62f6, guest PC 0x0c054eb6 */
if(!s->budget--) { s->failed_pc=0x0c054eb6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c054eb8;
P_0c054eb8: /* original 56f5, guest PC 0x0c054eb8 */
if(!s->budget--) { s->failed_pc=0x0c054eb8u; return 0; }
r[6]=read(ram,r[15]+20,4);
goto P_0c054eba;
P_0c054eba: /* original 2652, guest PC 0x0c054eba */
if(!s->budget--) { s->failed_pc=0x0c054ebau; return 0; }
write(ram,r[6],r[5],4);
goto P_0c054ebc;
P_0c054ebc: /* original 1641, guest PC 0x0c054ebc */
if(!s->budget--) { s->failed_pc=0x0c054ebcu; return 0; }
write(ram,r[6]+4,r[4],4);
goto P_0c054ebe;
P_0c054ebe: /* original 67f6, guest PC 0x0c054ebe */
if(!s->budget--) { s->failed_pc=0x0c054ebeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[7]=tmp;
goto P_0c054ec0;
P_0c054ec0: /* original 66f6, guest PC 0x0c054ec0 */
if(!s->budget--) { s->failed_pc=0x0c054ec0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[6]=tmp;
goto P_0c054ec2;
P_0c054ec2: /* original 65f6, guest PC 0x0c054ec2 */
if(!s->budget--) { s->failed_pc=0x0c054ec2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[5]=tmp;
goto P_0c054ec4;
P_0c054ec4: /* original 64f6, guest PC 0x0c054ec4 */
if(!s->budget--) { s->failed_pc=0x0c054ec4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c054ec6;
P_0c054ec6: /* original 60f6, guest PC 0x0c054ec6 */
if(!s->budget--) { s->failed_pc=0x0c054ec6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[0]=tmp;
goto P_0c054ec8;
P_0c054ec8: /* original 000b, guest PC 0x0c054ec8 */
if(!s->budget--) { s->failed_pc=0x0c054ec8u; return 0; }
target=r[16];
r[15]+=0x00000014u;
s->pc=target; return ram->oob==0;
P_0c054eca: /* original 7f14, guest PC 0x0c054eca */
if(!s->budget--) { s->failed_pc=0x0c054ecau; return 0; }
r[15]+=0x00000014u;
return vf3_matrix_family(0x0c054eccu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
