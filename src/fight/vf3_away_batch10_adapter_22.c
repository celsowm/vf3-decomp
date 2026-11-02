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
int vf3_away_batch10_adapter_22(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06e51au: goto P_0c06e51a;
case 0x0c06e51cu: goto P_0c06e51c;
case 0x0c06e51eu: goto P_0c06e51e;
case 0x0c06e520u: goto P_0c06e520;
case 0x0c06e522u: goto P_0c06e522;
case 0x0c06e524u: goto P_0c06e524;
case 0x0c06e526u: goto P_0c06e526;
case 0x0c06e528u: goto P_0c06e528;
case 0x0c06e52au: goto P_0c06e52a;
case 0x0c06e52cu: goto P_0c06e52c;
case 0x0c06e52eu: goto P_0c06e52e;
case 0x0c06e530u: goto P_0c06e530;
case 0x0c06e532u: goto P_0c06e532;
case 0x0c06e534u: goto P_0c06e534;
case 0x0c06e536u: goto P_0c06e536;
case 0x0c06e538u: goto P_0c06e538;
case 0x0c06e53au: goto P_0c06e53a;
case 0x0c06e53cu: goto P_0c06e53c;
case 0x0c06e53eu: goto P_0c06e53e;
case 0x0c06e540u: goto P_0c06e540;
case 0x0c06e542u: goto P_0c06e542;
case 0x0c06e544u: goto P_0c06e544;
case 0x0c06e546u: goto P_0c06e546;
case 0x0c06e548u: goto P_0c06e548;
case 0x0c06e54au: goto P_0c06e54a;
case 0x0c06e54cu: goto P_0c06e54c;
case 0x0c06e54eu: goto P_0c06e54e;
case 0x0c06e550u: goto P_0c06e550;
case 0x0c06e552u: goto P_0c06e552;
case 0x0c06e554u: goto P_0c06e554;
case 0x0c06e556u: goto P_0c06e556;
case 0x0c06e558u: goto P_0c06e558;
case 0x0c06e55au: goto P_0c06e55a;
case 0x0c06e55cu: goto P_0c06e55c;
case 0x0c06e55eu: goto P_0c06e55e;
case 0x0c06e560u: goto P_0c06e560;
case 0x0c06e562u: goto P_0c06e562;
case 0x0c06e564u: goto P_0c06e564;
case 0x0c06e566u: goto P_0c06e566;
case 0x0c06e568u: goto P_0c06e568;
case 0x0c06e56au: goto P_0c06e56a;
case 0x0c06e56cu: goto P_0c06e56c;
case 0x0c06e56eu: goto P_0c06e56e;
case 0x0c06e570u: goto P_0c06e570;
case 0x0c06e572u: goto P_0c06e572;
case 0x0c06e574u: goto P_0c06e574;
case 0x0c06e576u: goto P_0c06e576;
case 0x0c06e578u: goto P_0c06e578;
case 0x0c06e57au: goto P_0c06e57a;
case 0x0c06e57cu: goto P_0c06e57c;
case 0x0c06e57eu: goto P_0c06e57e;
case 0x0c06e580u: goto P_0c06e580;
case 0x0c06e582u: goto P_0c06e582;
case 0x0c06e584u: goto P_0c06e584;
case 0x0c06e586u: goto P_0c06e586;
case 0x0c06e588u: goto P_0c06e588;
case 0x0c06e58au: goto P_0c06e58a;
case 0x0c06e58cu: goto P_0c06e58c;
case 0x0c06e58eu: goto P_0c06e58e;
case 0x0c06e590u: goto P_0c06e590;
case 0x0c06e592u: goto P_0c06e592;
case 0x0c06e594u: goto P_0c06e594;
case 0x0c06e596u: goto P_0c06e596;
case 0x0c06e598u: goto P_0c06e598;
case 0x0c06e59au: goto P_0c06e59a;
case 0x0c06e59cu: goto P_0c06e59c;
case 0x0c06e59eu: goto P_0c06e59e;
case 0x0c06e5a0u: goto P_0c06e5a0;
case 0x0c06e5a2u: goto P_0c06e5a2;
case 0x0c06e5a4u: goto P_0c06e5a4;
case 0x0c06e5a6u: goto P_0c06e5a6;
case 0x0c06e5a8u: goto P_0c06e5a8;
case 0x0c06e5aau: goto P_0c06e5aa;
case 0x0c06e5acu: goto P_0c06e5ac;
case 0x0c06e5aeu: goto P_0c06e5ae;
case 0x0c06e5b0u: goto P_0c06e5b0;
case 0x0c06e5b2u: goto P_0c06e5b2;
case 0x0c06e5b4u: goto P_0c06e5b4;
case 0x0c06e5b6u: goto P_0c06e5b6;
case 0x0c06e5b8u: goto P_0c06e5b8;
case 0x0c06e5bau: goto P_0c06e5ba;
case 0x0c06e5bcu: goto P_0c06e5bc;
case 0x0c06e5beu: goto P_0c06e5be;
case 0x0c06e5c0u: goto P_0c06e5c0;
case 0x0c06e5c2u: goto P_0c06e5c2;
case 0x0c06e5c4u: goto P_0c06e5c4;
case 0x0c06e5c6u: goto P_0c06e5c6;
case 0x0c06e5c8u: goto P_0c06e5c8;
case 0x0c06e5cau: goto P_0c06e5ca;
case 0x0c06e5ccu: goto P_0c06e5cc;
case 0x0c06e5ceu: goto P_0c06e5ce;
case 0x0c06e5d0u: goto P_0c06e5d0;
case 0x0c06e5d2u: goto P_0c06e5d2;
case 0x0c06e5d4u: goto P_0c06e5d4;
case 0x0c06e5d6u: goto P_0c06e5d6;
case 0x0c06e5d8u: goto P_0c06e5d8;
case 0x0c06e5dau: goto P_0c06e5da;
case 0x0c06e5dcu: goto P_0c06e5dc;
case 0x0c06e5deu: goto P_0c06e5de;
case 0x0c06e5e0u: goto P_0c06e5e0;
case 0x0c06e5e2u: goto P_0c06e5e2;
case 0x0c06e5e4u: goto P_0c06e5e4;
case 0x0c06e5e6u: goto P_0c06e5e6;
case 0x0c06e5e8u: goto P_0c06e5e8;
case 0x0c06e5eau: goto P_0c06e5ea;
case 0x0c06e5ecu: goto P_0c06e5ec;
case 0x0c06e5eeu: goto P_0c06e5ee;
case 0x0c06e5f0u: goto P_0c06e5f0;
case 0x0c06e5f2u: goto P_0c06e5f2;
case 0x0c06e5f4u: goto P_0c06e5f4;
case 0x0c06e5f6u: goto P_0c06e5f6;
case 0x0c06e5f8u: goto P_0c06e5f8;
case 0x0c06e5fau: goto P_0c06e5fa;
case 0x0c06e5fcu: goto P_0c06e5fc;
case 0x0c06e5feu: goto P_0c06e5fe;
case 0x0c06e600u: goto P_0c06e600;
case 0x0c06e602u: goto P_0c06e602;
case 0x0c06e604u: goto P_0c06e604;
case 0x0c06e606u: goto P_0c06e606;
case 0x0c06e608u: goto P_0c06e608;
case 0x0c06e60au: goto P_0c06e60a;
case 0x0c06e620u: goto P_0c06e620;
case 0x0c06e622u: goto P_0c06e622;
case 0x0c06e624u: goto P_0c06e624;
case 0x0c06e626u: goto P_0c06e626;
case 0x0c06e628u: goto P_0c06e628;
case 0x0c06e62au: goto P_0c06e62a;
case 0x0c06e62cu: goto P_0c06e62c;
case 0x0c06e62eu: goto P_0c06e62e;
case 0x0c06e630u: goto P_0c06e630;
case 0x0c06e632u: goto P_0c06e632;
case 0x0c06e634u: goto P_0c06e634;
case 0x0c06e636u: goto P_0c06e636;
case 0x0c06e638u: goto P_0c06e638;
case 0x0c06e63au: goto P_0c06e63a;
case 0x0c06e63cu: goto P_0c06e63c;
case 0x0c06e63eu: goto P_0c06e63e;
case 0x0c06e640u: goto P_0c06e640;
case 0x0c06e642u: goto P_0c06e642;
case 0x0c06e644u: goto P_0c06e644;
case 0x0c06e646u: goto P_0c06e646;
case 0x0c06e648u: goto P_0c06e648;
case 0x0c06e64au: goto P_0c06e64a;
case 0x0c06e64cu: goto P_0c06e64c;
case 0x0c06e64eu: goto P_0c06e64e;
case 0x0c06e650u: goto P_0c06e650;
case 0x0c06e652u: goto P_0c06e652;
case 0x0c06e654u: goto P_0c06e654;
case 0x0c06e656u: goto P_0c06e656;
case 0x0c06e658u: goto P_0c06e658;
case 0x0c06e65au: goto P_0c06e65a;
case 0x0c06e65cu: goto P_0c06e65c;
case 0x0c06e65eu: goto P_0c06e65e;
case 0x0c06e660u: goto P_0c06e660;
case 0x0c06e662u: goto P_0c06e662;
case 0x0c06e664u: goto P_0c06e664;
case 0x0c06e666u: goto P_0c06e666;
case 0x0c06e668u: goto P_0c06e668;
case 0x0c06e66au: goto P_0c06e66a;
case 0x0c06e66cu: goto P_0c06e66c;
case 0x0c06e66eu: goto P_0c06e66e;
case 0x0c06e670u: goto P_0c06e670;
case 0x0c06e672u: goto P_0c06e672;
case 0x0c06e674u: goto P_0c06e674;
case 0x0c06e676u: goto P_0c06e676;
case 0x0c06e678u: goto P_0c06e678;
case 0x0c06e67au: goto P_0c06e67a;
case 0x0c06e67cu: goto P_0c06e67c;
case 0x0c06e67eu: goto P_0c06e67e;
case 0x0c06e680u: goto P_0c06e680;
case 0x0c06e682u: goto P_0c06e682;
case 0x0c06e684u: goto P_0c06e684;
case 0x0c06e686u: goto P_0c06e686;
case 0x0c06e688u: goto P_0c06e688;
case 0x0c06e68au: goto P_0c06e68a;
case 0x0c06e68cu: goto P_0c06e68c;
case 0x0c06e68eu: goto P_0c06e68e;
case 0x0c06e690u: goto P_0c06e690;
case 0x0c06e692u: goto P_0c06e692;
case 0x0c06e694u: goto P_0c06e694;
case 0x0c06e696u: goto P_0c06e696;
case 0x0c06e698u: goto P_0c06e698;
case 0x0c06e69au: goto P_0c06e69a;
case 0x0c06e69cu: goto P_0c06e69c;
case 0x0c06e69eu: goto P_0c06e69e;
case 0x0c06e6a0u: goto P_0c06e6a0;
case 0x0c06e6a2u: goto P_0c06e6a2;
case 0x0c06e6a4u: goto P_0c06e6a4;
case 0x0c06e6a6u: goto P_0c06e6a6;
case 0x0c06e6a8u: goto P_0c06e6a8;
case 0x0c06e6aau: goto P_0c06e6aa;
case 0x0c06e6acu: goto P_0c06e6ac;
case 0x0c06e6aeu: goto P_0c06e6ae;
case 0x0c06e6b0u: goto P_0c06e6b0;
case 0x0c06e6b2u: goto P_0c06e6b2;
case 0x0c06e6b4u: goto P_0c06e6b4;
case 0x0c06e6b6u: goto P_0c06e6b6;
case 0x0c06e6b8u: goto P_0c06e6b8;
case 0x0c06e6bau: goto P_0c06e6ba;
case 0x0c06e6bcu: goto P_0c06e6bc;
case 0x0c06e6beu: goto P_0c06e6be;
case 0x0c06e6c0u: goto P_0c06e6c0;
case 0x0c06e6c2u: goto P_0c06e6c2;
case 0x0c06e6c4u: goto P_0c06e6c4;
case 0x0c06e6c6u: goto P_0c06e6c6;
case 0x0c06e6c8u: goto P_0c06e6c8;
case 0x0c06e6cau: goto P_0c06e6ca;
case 0x0c06e6ccu: goto P_0c06e6cc;
case 0x0c06e6ceu: goto P_0c06e6ce;
case 0x0c06e6d0u: goto P_0c06e6d0;
case 0x0c06e6d2u: goto P_0c06e6d2;
case 0x0c06e6d4u: goto P_0c06e6d4;
case 0x0c06e6d6u: goto P_0c06e6d6;
case 0x0c06e6d8u: goto P_0c06e6d8;
case 0x0c06e6dau: goto P_0c06e6da;
case 0x0c06e6dcu: goto P_0c06e6dc;
case 0x0c06e6deu: goto P_0c06e6de;
case 0x0c06e6e0u: goto P_0c06e6e0;
case 0x0c06e6e2u: goto P_0c06e6e2;
case 0x0c06e6e4u: goto P_0c06e6e4;
case 0x0c06e6e6u: goto P_0c06e6e6;
case 0x0c06e6e8u: goto P_0c06e6e8;
case 0x0c06e6eau: goto P_0c06e6ea;
case 0x0c06e6ecu: goto P_0c06e6ec;
case 0x0c06e6eeu: goto P_0c06e6ee;
case 0x0c06e6f0u: goto P_0c06e6f0;
case 0x0c06e6f2u: goto P_0c06e6f2;
case 0x0c06e6f4u: goto P_0c06e6f4;
case 0x0c06e6f6u: goto P_0c06e6f6;
case 0x0c06e6f8u: goto P_0c06e6f8;
case 0x0c06e6fau: goto P_0c06e6fa;
case 0x0c06e6fcu: goto P_0c06e6fc;
case 0x0c06e6feu: goto P_0c06e6fe;
case 0x0c06e700u: goto P_0c06e700;
case 0x0c06e702u: goto P_0c06e702;
case 0x0c06e704u: goto P_0c06e704;
case 0x0c06e706u: goto P_0c06e706;
case 0x0c06e708u: goto P_0c06e708;
case 0x0c06e70au: goto P_0c06e70a;
case 0x0c06e70cu: goto P_0c06e70c;
case 0x0c06e70eu: goto P_0c06e70e;
case 0x0c06e710u: goto P_0c06e710;
case 0x0c06e712u: goto P_0c06e712;
case 0x0c06e714u: goto P_0c06e714;
case 0x0c06e716u: goto P_0c06e716;
case 0x0c06e718u: goto P_0c06e718;
case 0x0c06e71au: goto P_0c06e71a;
case 0x0c06e71cu: goto P_0c06e71c;
case 0x0c06e71eu: goto P_0c06e71e;
case 0x0c06e720u: goto P_0c06e720;
case 0x0c06e722u: goto P_0c06e722;
case 0x0c06e724u: goto P_0c06e724;
case 0x0c06e726u: goto P_0c06e726;
case 0x0c06e728u: goto P_0c06e728;
case 0x0c06e72au: goto P_0c06e72a;
case 0x0c06e72cu: goto P_0c06e72c;
case 0x0c06e72eu: goto P_0c06e72e;
case 0x0c06e730u: goto P_0c06e730;
case 0x0c06e732u: goto P_0c06e732;
case 0x0c06e734u: goto P_0c06e734;
case 0x0c06e736u: goto P_0c06e736;
case 0x0c06e738u: goto P_0c06e738;
case 0x0c06e73au: goto P_0c06e73a;
case 0x0c06e73cu: goto P_0c06e73c;
case 0x0c06e73eu: goto P_0c06e73e;
case 0x0c06e740u: goto P_0c06e740;
case 0x0c06e742u: goto P_0c06e742;
case 0x0c06e744u: goto P_0c06e744;
case 0x0c06e746u: goto P_0c06e746;
case 0x0c06e754u: goto P_0c06e754;
case 0x0c06e756u: goto P_0c06e756;
case 0x0c06e758u: goto P_0c06e758;
case 0x0c06e75au: goto P_0c06e75a;
case 0x0c06e75cu: goto P_0c06e75c;
case 0x0c06e75eu: goto P_0c06e75e;
case 0x0c06e760u: goto P_0c06e760;
case 0x0c06e762u: goto P_0c06e762;
case 0x0c06e764u: goto P_0c06e764;
case 0x0c06e766u: goto P_0c06e766;
case 0x0c06e768u: goto P_0c06e768;
case 0x0c06e76au: goto P_0c06e76a;
case 0x0c06e76cu: goto P_0c06e76c;
case 0x0c06e76eu: goto P_0c06e76e;
case 0x0c06e770u: goto P_0c06e770;
case 0x0c06e772u: goto P_0c06e772;
case 0x0c06e774u: goto P_0c06e774;
case 0x0c06e776u: goto P_0c06e776;
case 0x0c06e778u: goto P_0c06e778;
case 0x0c06e77au: goto P_0c06e77a;
case 0x0c06e77cu: goto P_0c06e77c;
case 0x0c06e77eu: goto P_0c06e77e;
case 0x0c06e780u: goto P_0c06e780;
case 0x0c06e782u: goto P_0c06e782;
case 0x0c06e784u: goto P_0c06e784;
case 0x0c06e786u: goto P_0c06e786;
case 0x0c06e788u: goto P_0c06e788;
case 0x0c06e78au: goto P_0c06e78a;
case 0x0c06e78cu: goto P_0c06e78c;
case 0x0c06e78eu: goto P_0c06e78e;
case 0x0c06e790u: goto P_0c06e790;
case 0x0c06e792u: goto P_0c06e792;
case 0x0c06e794u: goto P_0c06e794;
case 0x0c06e796u: goto P_0c06e796;
case 0x0c06e798u: goto P_0c06e798;
case 0x0c06e79au: goto P_0c06e79a;
case 0x0c06e79cu: goto P_0c06e79c;
case 0x0c06e79eu: goto P_0c06e79e;
case 0x0c06e7a0u: goto P_0c06e7a0;
case 0x0c06e7a2u: goto P_0c06e7a2;
case 0x0c06e7a4u: goto P_0c06e7a4;
case 0x0c06e7a6u: goto P_0c06e7a6;
case 0x0c06e7a8u: goto P_0c06e7a8;
case 0x0c06e7aau: goto P_0c06e7aa;
case 0x0c06e7acu: goto P_0c06e7ac;
case 0x0c06e7aeu: goto P_0c06e7ae;
case 0x0c06e7b0u: goto P_0c06e7b0;
case 0x0c06e7b2u: goto P_0c06e7b2;
case 0x0c06e7b4u: goto P_0c06e7b4;
case 0x0c06e7b6u: goto P_0c06e7b6;
case 0x0c06e7b8u: goto P_0c06e7b8;
case 0x0c06e7bau: goto P_0c06e7ba;
case 0x0c06e7bcu: goto P_0c06e7bc;
case 0x0c06e7beu: goto P_0c06e7be;
case 0x0c06e7c0u: goto P_0c06e7c0;
case 0x0c06e7c2u: goto P_0c06e7c2;
case 0x0c06e7c4u: goto P_0c06e7c4;
case 0x0c06e7c6u: goto P_0c06e7c6;
case 0x0c06e7c8u: goto P_0c06e7c8;
case 0x0c06e7cau: goto P_0c06e7ca;
case 0x0c06e7ccu: goto P_0c06e7cc;
case 0x0c06e7ceu: goto P_0c06e7ce;
case 0x0c06e7d0u: goto P_0c06e7d0;
case 0x0c06e7d2u: goto P_0c06e7d2;
case 0x0c06e7d4u: goto P_0c06e7d4;
case 0x0c06e7d6u: goto P_0c06e7d6;
case 0x0c06e7d8u: goto P_0c06e7d8;
case 0x0c06e7dau: goto P_0c06e7da;
case 0x0c06e7dcu: goto P_0c06e7dc;
case 0x0c06e7deu: goto P_0c06e7de;
case 0x0c06e7e0u: goto P_0c06e7e0;
case 0x0c06e7e2u: goto P_0c06e7e2;
case 0x0c06e7e4u: goto P_0c06e7e4;
case 0x0c06e7e6u: goto P_0c06e7e6;
case 0x0c06e7e8u: goto P_0c06e7e8;
case 0x0c06e7eau: goto P_0c06e7ea;
case 0x0c06e7ecu: goto P_0c06e7ec;
case 0x0c06e7eeu: goto P_0c06e7ee;
case 0x0c06e7f0u: goto P_0c06e7f0;
case 0x0c06e7f2u: goto P_0c06e7f2;
case 0x0c06e7f4u: goto P_0c06e7f4;
case 0x0c06e7f6u: goto P_0c06e7f6;
case 0x0c06e7f8u: goto P_0c06e7f8;
case 0x0c06e7fau: goto P_0c06e7fa;
case 0x0c06e7fcu: goto P_0c06e7fc;
case 0x0c06e7feu: goto P_0c06e7fe;
case 0x0c06e800u: goto P_0c06e800;
case 0x0c06e802u: goto P_0c06e802;
case 0x0c06e804u: goto P_0c06e804;
case 0x0c06e806u: goto P_0c06e806;
case 0x0c06e80cu: goto P_0c06e80c;
case 0x0c06e80eu: goto P_0c06e80e;
case 0x0c06e810u: goto P_0c06e810;
case 0x0c06e812u: goto P_0c06e812;
case 0x0c06e814u: goto P_0c06e814;
case 0x0c06e816u: goto P_0c06e816;
case 0x0c06e818u: goto P_0c06e818;
case 0x0c06e81au: goto P_0c06e81a;
case 0x0c06e81cu: goto P_0c06e81c;
case 0x0c06e81eu: goto P_0c06e81e;
case 0x0c06e820u: goto P_0c06e820;
case 0x0c06e822u: goto P_0c06e822;
case 0x0c06e824u: goto P_0c06e824;
case 0x0c06e826u: goto P_0c06e826;
case 0x0c06e828u: goto P_0c06e828;
case 0x0c06e82au: goto P_0c06e82a;
case 0x0c06e82cu: goto P_0c06e82c;
case 0x0c06e82eu: goto P_0c06e82e;
case 0x0c06e830u: goto P_0c06e830;
case 0x0c06e832u: goto P_0c06e832;
case 0x0c06e834u: goto P_0c06e834;
case 0x0c06e836u: goto P_0c06e836;
case 0x0c06e838u: goto P_0c06e838;
case 0x0c06e83au: goto P_0c06e83a;
case 0x0c06e83cu: goto P_0c06e83c;
case 0x0c06e83eu: goto P_0c06e83e;
case 0x0c06e840u: goto P_0c06e840;
case 0x0c06e842u: goto P_0c06e842;
case 0x0c06e844u: goto P_0c06e844;
case 0x0c06e846u: goto P_0c06e846;
case 0x0c06e848u: goto P_0c06e848;
case 0x0c06e84au: goto P_0c06e84a;
case 0x0c06e84cu: goto P_0c06e84c;
case 0x0c06e84eu: goto P_0c06e84e;
case 0x0c06e850u: goto P_0c06e850;
case 0x0c06e852u: goto P_0c06e852;
case 0x0c06e854u: goto P_0c06e854;
case 0x0c06e856u: goto P_0c06e856;
case 0x0c06e858u: goto P_0c06e858;
case 0x0c06e85au: goto P_0c06e85a;
case 0x0c06e85cu: goto P_0c06e85c;
case 0x0c06e85eu: goto P_0c06e85e;
case 0x0c06e860u: goto P_0c06e860;
case 0x0c06e862u: goto P_0c06e862;
case 0x0c06e864u: goto P_0c06e864;
case 0x0c06e866u: goto P_0c06e866;
case 0x0c06e868u: goto P_0c06e868;
case 0x0c06e86au: goto P_0c06e86a;
case 0x0c06e86cu: goto P_0c06e86c;
case 0x0c06e86eu: goto P_0c06e86e;
case 0x0c06e870u: goto P_0c06e870;
case 0x0c06e872u: goto P_0c06e872;
case 0x0c06e874u: goto P_0c06e874;
case 0x0c06e876u: goto P_0c06e876;
case 0x0c06e878u: goto P_0c06e878;
case 0x0c06e87au: goto P_0c06e87a;
case 0x0c06e87cu: goto P_0c06e87c;
case 0x0c06e87eu: goto P_0c06e87e;
case 0x0c06e880u: goto P_0c06e880;
case 0x0c06e882u: goto P_0c06e882;
case 0x0c06e884u: goto P_0c06e884;
case 0x0c06e886u: goto P_0c06e886;
case 0x0c06e888u: goto P_0c06e888;
case 0x0c06e88au: goto P_0c06e88a;
case 0x0c06e88cu: goto P_0c06e88c;
case 0x0c06e88eu: goto P_0c06e88e;
case 0x0c06e890u: goto P_0c06e890;
case 0x0c06e892u: goto P_0c06e892;
case 0x0c06e894u: goto P_0c06e894;
case 0x0c06e896u: goto P_0c06e896;
case 0x0c06e898u: goto P_0c06e898;
case 0x0c06e89au: goto P_0c06e89a;
case 0x0c06e89cu: goto P_0c06e89c;
case 0x0c06e89eu: goto P_0c06e89e;
case 0x0c06e8a0u: goto P_0c06e8a0;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06e51a: /* original 2fe6, guest PC 0x0c06e51a */
if(!s->budget--) { s->failed_pc=0x0c06e51au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06e51c;
P_0c06e51c: /* original c73f, guest PC 0x0c06e51c */
if(!s->budget--) { s->failed_pc=0x0c06e51cu; return 0; }
r[0]=code_base|0x0006e61cu;
goto P_0c06e51e;
P_0c06e51e: /* original 2fd6, guest PC 0x0c06e51e */
if(!s->budget--) { s->failed_pc=0x0c06e51eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06e520;
P_0c06e520: /* original ee04, guest PC 0x0c06e520 */
if(!s->budget--) { s->failed_pc=0x0c06e520u; return 0; }
r[14]=0x00000004u;
goto P_0c06e522;
P_0c06e522: /* original 2fc6, guest PC 0x0c06e522 */
if(!s->budget--) { s->failed_pc=0x0c06e522u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06e524;
P_0c06e524: /* original 2fb6, guest PC 0x0c06e524 */
if(!s->budget--) { s->failed_pc=0x0c06e524u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06e526;
P_0c06e526: /* original eb06, guest PC 0x0c06e526 */
if(!s->budget--) { s->failed_pc=0x0c06e526u; return 0; }
r[11]=0x00000006u;
goto P_0c06e528;
P_0c06e528: /* original 2fa6, guest PC 0x0c06e528 */
if(!s->budget--) { s->failed_pc=0x0c06e528u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06e52a;
P_0c06e52a: /* original 66b3, guest PC 0x0c06e52a */
if(!s->budget--) { s->failed_pc=0x0c06e52au; return 0; }
r[6]=r[11];
goto P_0c06e52c;
P_0c06e52c: /* original 2f96, guest PC 0x0c06e52c */
if(!s->budget--) { s->failed_pc=0x0c06e52cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06e52e;
P_0c06e52e: /* original 2f86, guest PC 0x0c06e52e */
if(!s->budget--) { s->failed_pc=0x0c06e52eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06e530;
P_0c06e530: /* original fffb, guest PC 0x0c06e530 */
if(!s->budget--) { s->failed_pc=0x0c06e530u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06e532;
P_0c06e532: /* original ffeb, guest PC 0x0c06e532 */
if(!s->budget--) { s->failed_pc=0x0c06e532u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06e534;
P_0c06e534: /* original ffdb, guest PC 0x0c06e534 */
if(!s->budget--) { s->failed_pc=0x0c06e534u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c06e536;
P_0c06e536: /* original 4f22, guest PC 0x0c06e536 */
if(!s->budget--) { s->failed_pc=0x0c06e536u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06e538;
P_0c06e538: /* original d237, guest PC 0x0c06e538 */
if(!s->budget--) { s->failed_pc=0x0c06e538u; return 0; }
r[2]=read(ram,0x0c06e618u,4);
goto P_0c06e53a;
P_0c06e53a: /* original 7fa8, guest PC 0x0c06e53a */
if(!s->budget--) { s->failed_pc=0x0c06e53au; return 0; }
r[15]+=0xffffffa8u;
goto P_0c06e53c;
P_0c06e53c: /* original 6322, guest PC 0x0c06e53c */
if(!s->budget--) { s->failed_pc=0x0c06e53cu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c06e53e;
P_0c06e53e: /* original 65f3, guest PC 0x0c06e53e */
if(!s->budget--) { s->failed_pc=0x0c06e53eu; return 0; }
r[5]=r[15];
goto P_0c06e540;
P_0c06e540: /* original 7538, guest PC 0x0c06e540 */
if(!s->budget--) { s->failed_pc=0x0c06e540u; return 0; }
r[5]+=0x00000038u;
goto P_0c06e542;
P_0c06e542: /* original 1f35, guest PC 0x0c06e542 */
if(!s->budget--) { s->failed_pc=0x0c06e542u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c06e544;
P_0c06e544: /* original f408, guest PC 0x0c06e544 */
if(!s->budget--) { s->failed_pc=0x0c06e544u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c06e546;
P_0c06e546: /* original a005, guest PC 0x0c06e546 */
if(!s->budget--) { s->failed_pc=0x0c06e546u; return 0; }
r[7]=0x00000000u;
goto P_0c06e554;
P_0c06e548: /* original e700, guest PC 0x0c06e548 */
if(!s->budget--) { s->failed_pc=0x0c06e548u; return 0; }
r[7]=0x00000000u;
goto P_0c06e54a;
P_0c06e54a: /* original 6073, guest PC 0x0c06e54a */
if(!s->budget--) { s->failed_pc=0x0c06e54au; return 0; }
r[0]=r[7];
goto P_0c06e54c;
P_0c06e54c: /* original 4008, guest PC 0x0c06e54c */
if(!s->budget--) { s->failed_pc=0x0c06e54cu; return 0; }
r[0]<<=2;
goto P_0c06e54e;
P_0c06e54e: /* original 76ff, guest PC 0x0c06e54e */
if(!s->budget--) { s->failed_pc=0x0c06e54eu; return 0; }
r[6]+=0xffffffffu;
goto P_0c06e550;
P_0c06e550: /* original f547, guest PC 0x0c06e550 */
if(!s->budget--) { s->failed_pc=0x0c06e550u; return 0; }
vf3_matrix_store(s,ram,4,r[5]+r[0]);
goto P_0c06e552;
P_0c06e552: /* original 7701, guest PC 0x0c06e552 */
if(!s->budget--) { s->failed_pc=0x0c06e552u; return 0; }
r[7]+=0x00000001u;
goto P_0c06e554;
P_0c06e554: /* original 2668, guest PC 0x0c06e554 */
if(!s->budget--) { s->failed_pc=0x0c06e554u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06e556;
P_0c06e556: /* original 8bf8, guest PC 0x0c06e556 */
if(!s->budget--) { s->failed_pc=0x0c06e556u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06e54a; }
goto P_0c06e558;
P_0c06e558: /* original 9059, guest PC 0x0c06e558 */
if(!s->budget--) { s->failed_pc=0x0c06e558u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06e60eu,2);
goto P_0c06e55a;
P_0c06e55a: /* original 56f5, guest PC 0x0c06e55a */
if(!s->budget--) { s->failed_pc=0x0c06e55au; return 0; }
r[6]=read(ram,r[15]+20,4);
goto P_0c06e55c;
P_0c06e55c: /* original f38d, guest PC 0x0c06e55c */
if(!s->budget--) { s->failed_pc=0x0c06e55cu; return 0; }
fr[3]=0;
goto P_0c06e55e;
P_0c06e55e: /* original 066e, guest PC 0x0c06e55e */
if(!s->budget--) { s->failed_pc=0x0c06e55eu; return 0; }
r[6]=read(ram,r[6]+r[0],4);
goto P_0c06e560;
P_0c06e560: /* original e004, guest PC 0x0c06e560 */
if(!s->budget--) { s->failed_pc=0x0c06e560u; return 0; }
r[0]=0x00000004u;
goto P_0c06e562;
P_0c06e562: /* original ff37, guest PC 0x0c06e562 */
if(!s->budget--) { s->failed_pc=0x0c06e562u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e564;
P_0c06e564: /* original e034, guest PC 0x0c06e564 */
if(!s->budget--) { s->failed_pc=0x0c06e564u; return 0; }
r[0]=0x00000034u;
goto P_0c06e566;
P_0c06e566: /* original 6d63, guest PC 0x0c06e566 */
if(!s->budget--) { s->failed_pc=0x0c06e566u; return 0; }
r[13]=r[6];
goto P_0c06e568;
P_0c06e568: /* original f39d, guest PC 0x0c06e568 */
if(!s->budget--) { s->failed_pc=0x0c06e568u; return 0; }
fr[3]=0x3f800000u;
goto P_0c06e56a;
P_0c06e56a: /* original 7d04, guest PC 0x0c06e56a */
if(!s->budget--) { s->failed_pc=0x0c06e56au; return 0; }
r[13]+=0x00000004u;
goto P_0c06e56c;
P_0c06e56c: /* original ff37, guest PC 0x0c06e56c */
if(!s->budget--) { s->failed_pc=0x0c06e56cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e56e;
P_0c06e56e: /* original f3d9, guest PC 0x0c06e56e */
if(!s->budget--) { s->failed_pc=0x0c06e56eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c06e570;
P_0c06e570: /* original e008, guest PC 0x0c06e570 */
if(!s->budget--) { s->failed_pc=0x0c06e570u; return 0; }
r[0]=0x00000008u;
goto P_0c06e572;
P_0c06e572: /* original 6862, guest PC 0x0c06e572 */
if(!s->budget--) { s->failed_pc=0x0c06e572u; return 0; }
tmp=read(ram,r[6],4);
r[8]=tmp;
goto P_0c06e574;
P_0c06e574: /* original ff37, guest PC 0x0c06e574 */
if(!s->budget--) { s->failed_pc=0x0c06e574u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e576;
P_0c06e576: /* original e00c, guest PC 0x0c06e576 */
if(!s->budget--) { s->failed_pc=0x0c06e576u; return 0; }
r[0]=0x0000000cu;
goto P_0c06e578;
P_0c06e578: /* original f3d9, guest PC 0x0c06e578 */
if(!s->budget--) { s->failed_pc=0x0c06e578u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c06e57a;
P_0c06e57a: /* original ff3a, guest PC 0x0c06e57a */
if(!s->budget--) { s->failed_pc=0x0c06e57au; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c06e57c;
P_0c06e57c: /* original f3d9, guest PC 0x0c06e57c */
if(!s->budget--) { s->failed_pc=0x0c06e57cu; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c06e57e;
P_0c06e57e: /* original ff37, guest PC 0x0c06e57e */
if(!s->budget--) { s->failed_pc=0x0c06e57eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e580;
P_0c06e580: /* original e010, guest PC 0x0c06e580 */
if(!s->budget--) { s->failed_pc=0x0c06e580u; return 0; }
r[0]=0x00000010u;
goto P_0c06e582;
P_0c06e582: /* original f3d9, guest PC 0x0c06e582 */
if(!s->budget--) { s->failed_pc=0x0c06e582u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c06e584;
P_0c06e584: /* original a135, guest PC 0x0c06e584 */
if(!s->budget--) { s->failed_pc=0x0c06e584u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e7f2;
P_0c06e586: /* original ff37, guest PC 0x0c06e586 */
if(!s->budget--) { s->failed_pc=0x0c06e586u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e588;
P_0c06e588: /* original e008, guest PC 0x0c06e588 */
if(!s->budget--) { s->failed_pc=0x0c06e588u; return 0; }
r[0]=0x00000008u;
goto P_0c06e58a;
P_0c06e58a: /* original f9f8, guest PC 0x0c06e58a */
if(!s->budget--) { s->failed_pc=0x0c06e58au; return 0; }
vf3_matrix_load(s,ram,9,r[15]);
goto P_0c06e58c;
P_0c06e58c: /* original fef6, guest PC 0x0c06e58c */
if(!s->budget--) { s->failed_pc=0x0c06e58cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]+r[0]);
goto P_0c06e58e;
P_0c06e58e: /* original e00c, guest PC 0x0c06e58e */
if(!s->budget--) { s->failed_pc=0x0c06e58eu; return 0; }
r[0]=0x0000000cu;
goto P_0c06e590;
P_0c06e590: /* original f3f6, guest PC 0x0c06e590 */
if(!s->budget--) { s->failed_pc=0x0c06e590u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06e592;
P_0c06e592: /* original e008, guest PC 0x0c06e592 */
if(!s->budget--) { s->failed_pc=0x0c06e592u; return 0; }
r[0]=0x00000008u;
goto P_0c06e594;
P_0c06e594: /* original ff37, guest PC 0x0c06e594 */
if(!s->budget--) { s->failed_pc=0x0c06e594u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e596;
P_0c06e596: /* original e010, guest PC 0x0c06e596 */
if(!s->budget--) { s->failed_pc=0x0c06e596u; return 0; }
r[0]=0x00000010u;
goto P_0c06e598;
P_0c06e598: /* original f3f6, guest PC 0x0c06e598 */
if(!s->budget--) { s->failed_pc=0x0c06e598u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06e59a;
P_0c06e59a: /* original e00c, guest PC 0x0c06e59a */
if(!s->budget--) { s->failed_pc=0x0c06e59au; return 0; }
r[0]=0x0000000cu;
goto P_0c06e59c;
P_0c06e59c: /* original ff3a, guest PC 0x0c06e59c */
if(!s->budget--) { s->failed_pc=0x0c06e59cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c06e59e;
P_0c06e59e: /* original f3d9, guest PC 0x0c06e59e */
if(!s->budget--) { s->failed_pc=0x0c06e59eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c06e5a0;
P_0c06e5a0: /* original ff37, guest PC 0x0c06e5a0 */
if(!s->budget--) { s->failed_pc=0x0c06e5a0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e5a2;
P_0c06e5a2: /* original e010, guest PC 0x0c06e5a2 */
if(!s->budget--) { s->failed_pc=0x0c06e5a2u; return 0; }
r[0]=0x00000010u;
goto P_0c06e5a4;
P_0c06e5a4: /* original f3d9, guest PC 0x0c06e5a4 */
if(!s->budget--) { s->failed_pc=0x0c06e5a4u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c06e5a6;
P_0c06e5a6: /* original ff37, guest PC 0x0c06e5a6 */
if(!s->budget--) { s->failed_pc=0x0c06e5a6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e5a8;
P_0c06e5a8: /* original e008, guest PC 0x0c06e5a8 */
if(!s->budget--) { s->failed_pc=0x0c06e5a8u; return 0; }
r[0]=0x00000008u;
goto P_0c06e5aa;
P_0c06e5aa: /* original f4f8, guest PC 0x0c06e5aa */
if(!s->budget--) { s->failed_pc=0x0c06e5aau; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c06e5ac;
P_0c06e5ac: /* original f39c, guest PC 0x0c06e5ac */
if(!s->budget--) { s->failed_pc=0x0c06e5acu; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c06e5ae;
P_0c06e5ae: /* original f341, guest PC 0x0c06e5ae */
if(!s->budget--) { s->failed_pc=0x0c06e5aeu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c06e5b0;
P_0c06e5b0: /* original fff6, guest PC 0x0c06e5b0 */
if(!s->budget--) { s->failed_pc=0x0c06e5b0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]+r[0]);
goto P_0c06e5b2;
P_0c06e5b2: /* original e028, guest PC 0x0c06e5b2 */
if(!s->budget--) { s->failed_pc=0x0c06e5b2u; return 0; }
r[0]=0x00000028u;
goto P_0c06e5b4;
P_0c06e5b4: /* original f64c, guest PC 0x0c06e5b4 */
if(!s->budget--) { s->failed_pc=0x0c06e5b4u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c06e5b6;
P_0c06e5b6: /* original ffe1, guest PC 0x0c06e5b6 */
if(!s->budget--) { s->failed_pc=0x0c06e5b6u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[14],r[18],'-');
goto P_0c06e5b8;
P_0c06e5b8: /* original f691, guest PC 0x0c06e5b8 */
if(!s->budget--) { s->failed_pc=0x0c06e5b8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[9],r[18],'-');
goto P_0c06e5ba;
P_0c06e5ba: /* original ff37, guest PC 0x0c06e5ba */
if(!s->budget--) { s->failed_pc=0x0c06e5bau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e5bc;
P_0c06e5bc: /* original e008, guest PC 0x0c06e5bc */
if(!s->budget--) { s->failed_pc=0x0c06e5bcu; return 0; }
r[0]=0x00000008u;
goto P_0c06e5be;
P_0c06e5be: /* original f2f6, guest PC 0x0c06e5be */
if(!s->budget--) { s->failed_pc=0x0c06e5beu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c06e5c0;
P_0c06e5c0: /* original f19c, guest PC 0x0c06e5c0 */
if(!s->budget--) { s->failed_pc=0x0c06e5c0u; return 0; }
vf3_matrix_move(s,1,9);
goto P_0c06e5c2;
P_0c06e5c2: /* original f3ec, guest PC 0x0c06e5c2 */
if(!s->budget--) { s->failed_pc=0x0c06e5c2u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c06e5c4;
P_0c06e5c4: /* original f342, guest PC 0x0c06e5c4 */
if(!s->budget--) { s->failed_pc=0x0c06e5c4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c06e5c6;
P_0c06e5c6: /* original f122, guest PC 0x0c06e5c6 */
if(!s->budget--) { s->failed_pc=0x0c06e5c6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c06e5c8;
P_0c06e5c8: /* original f311, guest PC 0x0c06e5c8 */
if(!s->budget--) { s->failed_pc=0x0c06e5c8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'-');
goto P_0c06e5ca;
P_0c06e5ca: /* original e01c, guest PC 0x0c06e5ca */
if(!s->budget--) { s->failed_pc=0x0c06e5cau; return 0; }
r[0]=0x0000001cu;
goto P_0c06e5cc;
P_0c06e5cc: /* original 6963, guest PC 0x0c06e5cc */
if(!s->budget--) { s->failed_pc=0x0c06e5ccu; return 0; }
r[9]=r[6];
goto P_0c06e5ce;
P_0c06e5ce: /* original 6ab3, guest PC 0x0c06e5ce */
if(!s->budget--) { s->failed_pc=0x0c06e5ceu; return 0; }
r[10]=r[11];
goto P_0c06e5d0;
P_0c06e5d0: /* original 79ff, guest PC 0x0c06e5d0 */
if(!s->budget--) { s->failed_pc=0x0c06e5d0u; return 0; }
r[9]+=0xffffffffu;
goto P_0c06e5d2;
P_0c06e5d2: /* original ff37, guest PC 0x0c06e5d2 */
if(!s->budget--) { s->failed_pc=0x0c06e5d2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e5d4;
P_0c06e5d4: /* original e010, guest PC 0x0c06e5d4 */
if(!s->budget--) { s->failed_pc=0x0c06e5d4u; return 0; }
r[0]=0x00000010u;
goto P_0c06e5d6;
P_0c06e5d6: /* original f3f6, guest PC 0x0c06e5d6 */
if(!s->budget--) { s->failed_pc=0x0c06e5d6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06e5d8;
P_0c06e5d8: /* original e030, guest PC 0x0c06e5d8 */
if(!s->budget--) { s->failed_pc=0x0c06e5d8u; return 0; }
r[0]=0x00000030u;
goto P_0c06e5da;
P_0c06e5da: /* original f19c, guest PC 0x0c06e5da */
if(!s->budget--) { s->failed_pc=0x0c06e5dau; return 0; }
vf3_matrix_move(s,1,9);
goto P_0c06e5dc;
P_0c06e5dc: /* original f131, guest PC 0x0c06e5dc */
if(!s->budget--) { s->failed_pc=0x0c06e5dcu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'-');
goto P_0c06e5de;
P_0c06e5de: /* original ff17, guest PC 0x0c06e5de */
if(!s->budget--) { s->failed_pc=0x0c06e5deu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c06e5e0;
P_0c06e5e0: /* original e00c, guest PC 0x0c06e5e0 */
if(!s->budget--) { s->failed_pc=0x0c06e5e0u; return 0; }
r[0]=0x0000000cu;
goto P_0c06e5e2;
P_0c06e5e2: /* original f2f6, guest PC 0x0c06e5e2 */
if(!s->budget--) { s->failed_pc=0x0c06e5e2u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c06e5e4;
P_0c06e5e4: /* original e02c, guest PC 0x0c06e5e4 */
if(!s->budget--) { s->failed_pc=0x0c06e5e4u; return 0; }
r[0]=0x0000002cu;
goto P_0c06e5e6;
P_0c06e5e6: /* original f2e1, guest PC 0x0c06e5e6 */
if(!s->budget--) { s->failed_pc=0x0c06e5e6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[14],r[18],'-');
goto P_0c06e5e8;
P_0c06e5e8: /* original ff27, guest PC 0x0c06e5e8 */
if(!s->budget--) { s->failed_pc=0x0c06e5e8u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c06e5ea;
P_0c06e5ea: /* original e00c, guest PC 0x0c06e5ea */
if(!s->budget--) { s->failed_pc=0x0c06e5eau; return 0; }
r[0]=0x0000000cu;
goto P_0c06e5ec;
P_0c06e5ec: /* original f3f6, guest PC 0x0c06e5ec */
if(!s->budget--) { s->failed_pc=0x0c06e5ecu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06e5ee;
P_0c06e5ee: /* original e018, guest PC 0x0c06e5ee */
if(!s->budget--) { s->failed_pc=0x0c06e5eeu; return 0; }
r[0]=0x00000018u;
goto P_0c06e5f0;
P_0c06e5f0: /* original f392, guest PC 0x0c06e5f0 */
if(!s->budget--) { s->failed_pc=0x0c06e5f0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[9],r[18],'*');
goto P_0c06e5f2;
P_0c06e5f2: /* original ff37, guest PC 0x0c06e5f2 */
if(!s->budget--) { s->failed_pc=0x0c06e5f2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e5f4;
P_0c06e5f4: /* original e010, guest PC 0x0c06e5f4 */
if(!s->budget--) { s->failed_pc=0x0c06e5f4u; return 0; }
r[0]=0x00000010u;
goto P_0c06e5f6;
P_0c06e5f6: /* original f1f6, guest PC 0x0c06e5f6 */
if(!s->budget--) { s->failed_pc=0x0c06e5f6u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c06e5f8;
P_0c06e5f8: /* original e018, guest PC 0x0c06e5f8 */
if(!s->budget--) { s->failed_pc=0x0c06e5f8u; return 0; }
r[0]=0x00000018u;
goto P_0c06e5fa;
P_0c06e5fa: /* original f0ec, guest PC 0x0c06e5fa */
if(!s->budget--) { s->failed_pc=0x0c06e5fau; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c06e5fc;
P_0c06e5fc: /* original f012, guest PC 0x0c06e5fc */
if(!s->budget--) { s->failed_pc=0x0c06e5fcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'*');
goto P_0c06e5fe;
P_0c06e5fe: /* original f031, guest PC 0x0c06e5fe */
if(!s->budget--) { s->failed_pc=0x0c06e5feu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c06e600;
P_0c06e600: /* original ff07, guest PC 0x0c06e600 */
if(!s->budget--) { s->failed_pc=0x0c06e600u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c06e602;
P_0c06e602: /* original 9005, guest PC 0x0c06e602 */
if(!s->budget--) { s->failed_pc=0x0c06e602u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06e610u,2);
goto P_0c06e604;
P_0c06e604: /* original 034e, guest PC 0x0c06e604 */
if(!s->budget--) { s->failed_pc=0x0c06e604u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c06e606;
P_0c06e606: /* original 1f35, guest PC 0x0c06e606 */
if(!s->budget--) { s->failed_pc=0x0c06e606u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c06e608;
P_0c06e608: /* original a0ee, guest PC 0x0c06e608 */
if(!s->budget--) { s->failed_pc=0x0c06e608u; return 0; }
r[6]=0x00000000u;
goto P_0c06e7e8;
P_0c06e60a: /* original e600, guest PC 0x0c06e60a */
if(!s->budget--) { s->failed_pc=0x0c06e60au; return 0; }
r[6]=0x00000000u;
if(!vf3_matrix_family(0x0c06e60cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06e60cu; return 0; } return 1;
P_0c06e620: /* original 7901, guest PC 0x0c06e620 */
if(!s->budget--) { s->failed_pc=0x0c06e620u; return 0; }
r[9]+=0x00000001u;
goto P_0c06e622;
P_0c06e622: /* original d24a, guest PC 0x0c06e622 */
if(!s->budget--) { s->failed_pc=0x0c06e622u; return 0; }
r[2]=read(ram,0x0c06e74cu,4);
goto P_0c06e624;
P_0c06e624: /* original 6790, guest PC 0x0c06e624 */
if(!s->budget--) { s->failed_pc=0x0c06e624u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[9],1);
r[7]=tmp;
goto P_0c06e626;
P_0c06e626: /* original 617c, guest PC 0x0c06e626 */
if(!s->budget--) { s->failed_pc=0x0c06e626u; return 0; }
r[1]=r[7]&255u;
goto P_0c06e628;
P_0c06e628: /* original 420b, guest PC 0x0c06e628 */
if(!s->budget--) { s->failed_pc=0x0c06e628u; return 0; }
target=r[2];
r[16]=code_base|0x0c06e62cu;
r[0]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06e62cu) { target=s->pc; goto dispatch; }
goto P_0c06e62c;
P_0c06e62a: /* original 60e3, guest PC 0x0c06e62a */
if(!s->budget--) { s->failed_pc=0x0c06e62au; return 0; }
r[0]=r[14];
goto P_0c06e62c;
P_0c06e62c: /* original 6703, guest PC 0x0c06e62c */
if(!s->budget--) { s->failed_pc=0x0c06e62cu; return 0; }
r[7]=r[0];
goto P_0c06e62e;
P_0c06e62e: /* original 6303, guest PC 0x0c06e62e */
if(!s->budget--) { s->failed_pc=0x0c06e62eu; return 0; }
r[3]=r[0];
goto P_0c06e630;
P_0c06e630: /* original 52f5, guest PC 0x0c06e630 */
if(!s->budget--) { s->failed_pc=0x0c06e630u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c06e632;
P_0c06e632: /* original 6c03, guest PC 0x0c06e632 */
if(!s->budget--) { s->failed_pc=0x0c06e632u; return 0; }
r[12]=r[0];
goto P_0c06e634;
P_0c06e634: /* original e008, guest PC 0x0c06e634 */
if(!s->budget--) { s->failed_pc=0x0c06e634u; return 0; }
r[0]=0x00000008u;
goto P_0c06e636;
P_0c06e636: /* original 4c00, guest PC 0x0c06e636 */
if(!s->budget--) { s->failed_pc=0x0c06e636u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c06e638;
P_0c06e638: /* original 4700, guest PC 0x0c06e638 */
if(!s->budget--) { s->failed_pc=0x0c06e638u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c06e63a;
P_0c06e63a: /* original 373c, guest PC 0x0c06e63a */
if(!s->budget--) { s->failed_pc=0x0c06e63au; return 0; }
r[7]+=r[3];
goto P_0c06e63c;
P_0c06e63c: /* original 9384, guest PC 0x0c06e63c */
if(!s->budget--) { s->failed_pc=0x0c06e63cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06e748u,2);
goto P_0c06e63e;
P_0c06e63e: /* original 4708, guest PC 0x0c06e63e */
if(!s->budget--) { s->failed_pc=0x0c06e63eu; return 0; }
r[7]<<=2;
goto P_0c06e640;
P_0c06e640: /* original 372c, guest PC 0x0c06e640 */
if(!s->budget--) { s->failed_pc=0x0c06e640u; return 0; }
r[7]+=r[2];
goto P_0c06e642;
P_0c06e642: /* original fa78, guest PC 0x0c06e642 */
if(!s->budget--) { s->failed_pc=0x0c06e642u; return 0; }
vf3_matrix_load(s,ram,10,r[7]);
goto P_0c06e644;
P_0c06e644: /* original 4c08, guest PC 0x0c06e644 */
if(!s->budget--) { s->failed_pc=0x0c06e644u; return 0; }
r[12]<<=2;
goto P_0c06e646;
P_0c06e646: /* original fb76, guest PC 0x0c06e646 */
if(!s->budget--) { s->failed_pc=0x0c06e646u; return 0; }
vf3_matrix_load(s,ram,11,r[7]+r[0]);
goto P_0c06e648;
P_0c06e648: /* original e024, guest PC 0x0c06e648 */
if(!s->budget--) { s->failed_pc=0x0c06e648u; return 0; }
r[0]=0x00000024u;
goto P_0c06e64a;
P_0c06e64a: /* original f4ac, guest PC 0x0c06e64a */
if(!s->budget--) { s->failed_pc=0x0c06e64au; return 0; }
vf3_matrix_move(s,4,10);
goto P_0c06e64c;
P_0c06e64c: /* original f4e1, guest PC 0x0c06e64c */
if(!s->budget--) { s->failed_pc=0x0c06e64cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'-');
goto P_0c06e64e;
P_0c06e64e: /* original fb4d, guest PC 0x0c06e64e */
if(!s->budget--) { s->failed_pc=0x0c06e64eu; return 0; }
fr[11]^=0x80000000u;
goto P_0c06e650;
P_0c06e650: /* original 334c, guest PC 0x0c06e650 */
if(!s->budget--) { s->failed_pc=0x0c06e650u; return 0; }
r[3]+=r[4];
goto P_0c06e652;
P_0c06e652: /* original f5bc, guest PC 0x0c06e652 */
if(!s->budget--) { s->failed_pc=0x0c06e652u; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c06e654;
P_0c06e654: /* original f591, guest PC 0x0c06e654 */
if(!s->budget--) { s->failed_pc=0x0c06e654u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[9],r[18],'-');
goto P_0c06e656;
P_0c06e656: /* original 3c3c, guest PC 0x0c06e656 */
if(!s->budget--) { s->failed_pc=0x0c06e656u; return 0; }
r[12]+=r[3];
goto P_0c06e658;
P_0c06e658: /* original f34c, guest PC 0x0c06e658 */
if(!s->budget--) { s->failed_pc=0x0c06e658u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c06e65a;
P_0c06e65a: /* original f4fc, guest PC 0x0c06e65a */
if(!s->budget--) { s->failed_pc=0x0c06e65au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c06e65c;
P_0c06e65c: /* original f432, guest PC 0x0c06e65c */
if(!s->budget--) { s->failed_pc=0x0c06e65cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c06e65e;
P_0c06e65e: /* original f3fc, guest PC 0x0c06e65e */
if(!s->budget--) { s->failed_pc=0x0c06e65eu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c06e660;
P_0c06e660: /* original f3f2, guest PC 0x0c06e660 */
if(!s->budget--) { s->failed_pc=0x0c06e660u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06e662;
P_0c06e662: /* original f05c, guest PC 0x0c06e662 */
if(!s->budget--) { s->failed_pc=0x0c06e662u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c06e664;
P_0c06e664: /* original f24c, guest PC 0x0c06e664 */
if(!s->budget--) { s->failed_pc=0x0c06e664u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c06e666;
P_0c06e666: /* original f26e, guest PC 0x0c06e666 */
if(!s->budget--) { s->failed_pc=0x0c06e666u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[6],fr[2],r[18]);
goto P_0c06e668;
P_0c06e668: /* original f42c, guest PC 0x0c06e668 */
if(!s->budget--) { s->failed_pc=0x0c06e668u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c06e66a;
P_0c06e66a: /* original ff37, guest PC 0x0c06e66a */
if(!s->budget--) { s->failed_pc=0x0c06e66au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e66c;
P_0c06e66c: /* original f26c, guest PC 0x0c06e66c */
if(!s->budget--) { s->failed_pc=0x0c06e66cu; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c06e66e;
P_0c06e66e: /* original f262, guest PC 0x0c06e66e */
if(!s->budget--) { s->failed_pc=0x0c06e66eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'*');
goto P_0c06e670;
P_0c06e670: /* original f13c, guest PC 0x0c06e670 */
if(!s->budget--) { s->failed_pc=0x0c06e670u; return 0; }
vf3_matrix_move(s,1,3);
goto P_0c06e672;
P_0c06e672: /* original e020, guest PC 0x0c06e672 */
if(!s->budget--) { s->failed_pc=0x0c06e672u; return 0; }
r[0]=0x00000020u;
goto P_0c06e674;
P_0c06e674: /* original ff27, guest PC 0x0c06e674 */
if(!s->budget--) { s->failed_pc=0x0c06e674u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c06e676;
P_0c06e676: /* original c736, guest PC 0x0c06e676 */
if(!s->budget--) { s->failed_pc=0x0c06e676u; return 0; }
r[0]=code_base|0x0006e750u;
goto P_0c06e678;
P_0c06e678: /* original f52c, guest PC 0x0c06e678 */
if(!s->budget--) { s->failed_pc=0x0c06e678u; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c06e67a;
P_0c06e67a: /* original f510, guest PC 0x0c06e67a */
if(!s->budget--) { s->failed_pc=0x0c06e67au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[1],r[18],'+');
goto P_0c06e67c;
P_0c06e67c: /* original f18d, guest PC 0x0c06e67c */
if(!s->budget--) { s->failed_pc=0x0c06e67cu; return 0; }
fr[1]=0;
goto P_0c06e67e;
P_0c06e67e: /* original f453, guest PC 0x0c06e67e */
if(!s->budget--) { s->failed_pc=0x0c06e67eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'/');
goto P_0c06e680;
P_0c06e680: /* original f145, guest PC 0x0c06e680 */
if(!s->budget--) { s->failed_pc=0x0c06e680u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[4]))!=0);
goto P_0c06e682;
P_0c06e682: /* original 8d53, guest PC 0x0c06e682 */
if(!s->budget--) { s->failed_pc=0x0c06e682u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,8,r[0]);
if(cond) { goto P_0c06e72c; }
goto P_0c06e686;
P_0c06e684: /* original f808, guest PC 0x0c06e684 */
if(!s->budget--) { s->failed_pc=0x0c06e684u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c06e686;
P_0c06e686: /* original e034, guest PC 0x0c06e686 */
if(!s->budget--) { s->failed_pc=0x0c06e686u; return 0; }
r[0]=0x00000034u;
goto P_0c06e688;
P_0c06e688: /* original f1f6, guest PC 0x0c06e688 */
if(!s->budget--) { s->failed_pc=0x0c06e688u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c06e68a;
P_0c06e68a: /* original f415, guest PC 0x0c06e68a */
if(!s->budget--) { s->failed_pc=0x0c06e68au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[1]))!=0);
goto P_0c06e68c;
P_0c06e68c: /* original 894e, guest PC 0x0c06e68c */
if(!s->budget--) { s->failed_pc=0x0c06e68cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06e72c; }
goto P_0c06e68e;
P_0c06e68e: /* original f5fc, guest PC 0x0c06e68e */
if(!s->budget--) { s->failed_pc=0x0c06e68eu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c06e690;
P_0c06e690: /* original f542, guest PC 0x0c06e690 */
if(!s->budget--) { s->failed_pc=0x0c06e690u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c06e692;
P_0c06e692: /* original f76c, guest PC 0x0c06e692 */
if(!s->budget--) { s->failed_pc=0x0c06e692u; return 0; }
vf3_matrix_move(s,7,6);
goto P_0c06e694;
P_0c06e694: /* original f742, guest PC 0x0c06e694 */
if(!s->budget--) { s->failed_pc=0x0c06e694u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c06e696;
P_0c06e696: /* original f5e0, guest PC 0x0c06e696 */
if(!s->budget--) { s->failed_pc=0x0c06e696u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'+');
goto P_0c06e698;
P_0c06e698: /* original f790, guest PC 0x0c06e698 */
if(!s->budget--) { s->failed_pc=0x0c06e698u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[9],r[18],'+');
goto P_0c06e69a;
P_0c06e69a: /* original f5a1, guest PC 0x0c06e69a */
if(!s->budget--) { s->failed_pc=0x0c06e69au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[10],r[18],'-');
goto P_0c06e69c;
P_0c06e69c: /* original f7b1, guest PC 0x0c06e69c */
if(!s->budget--) { s->failed_pc=0x0c06e69cu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[11],r[18],'-');
goto P_0c06e69e;
P_0c06e69e: /* original f35c, guest PC 0x0c06e69e */
if(!s->budget--) { s->failed_pc=0x0c06e69eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c06e6a0;
P_0c06e6a0: /* original f352, guest PC 0x0c06e6a0 */
if(!s->budget--) { s->failed_pc=0x0c06e6a0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c06e6a2;
P_0c06e6a2: /* original f07c, guest PC 0x0c06e6a2 */
if(!s->budget--) { s->failed_pc=0x0c06e6a2u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c06e6a4;
P_0c06e6a4: /* original f37e, guest PC 0x0c06e6a4 */
if(!s->budget--) { s->failed_pc=0x0c06e6a4u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[7],fr[3],r[18]);
goto P_0c06e6a6;
P_0c06e6a6: /* original f43c, guest PC 0x0c06e6a6 */
if(!s->budget--) { s->failed_pc=0x0c06e6a6u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c06e6a8;
P_0c06e6a8: /* original f845, guest PC 0x0c06e6a8 */
if(!s->budget--) { s->failed_pc=0x0c06e6a8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[4]))!=0);
goto P_0c06e6aa;
P_0c06e6aa: /* original 8b01, guest PC 0x0c06e6aa */
if(!s->budget--) { s->failed_pc=0x0c06e6aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06e6b0; }
goto P_0c06e6ac;
P_0c06e6ac: /* original a002, guest PC 0x0c06e6ac */
if(!s->budget--) { s->failed_pc=0x0c06e6acu; return 0; }
fr[13]=0;
goto P_0c06e6b4;
P_0c06e6ae: /* original fd8d, guest PC 0x0c06e6ae */
if(!s->budget--) { s->failed_pc=0x0c06e6aeu; return 0; }
fr[13]=0;
goto P_0c06e6b0;
P_0c06e6b0: /* original fd4c, guest PC 0x0c06e6b0 */
if(!s->budget--) { s->failed_pc=0x0c06e6b0u; return 0; }
vf3_matrix_move(s,13,4);
goto P_0c06e6b2;
P_0c06e6b2: /* original fd7d, guest PC 0x0c06e6b2 */
if(!s->budget--) { s->failed_pc=0x0c06e6b2u; return 0; }
if(!vf3_fpu_fsrra(fr[13],r[18],&fr[13])) goto unsupported;
goto P_0c06e6b4;
P_0c06e6b4: /* original 6063, guest PC 0x0c06e6b4 */
if(!s->budget--) { s->failed_pc=0x0c06e6b4u; return 0; }
r[0]=r[6];
goto P_0c06e6b6;
P_0c06e6b6: /* original 4008, guest PC 0x0c06e6b6 */
if(!s->budget--) { s->failed_pc=0x0c06e6b6u; return 0; }
r[0]<<=2;
goto P_0c06e6b8;
P_0c06e6b8: /* original f4d2, guest PC 0x0c06e6b8 */
if(!s->budget--) { s->failed_pc=0x0c06e6b8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[13],r[18],'*');
goto P_0c06e6ba;
P_0c06e6ba: /* original f156, guest PC 0x0c06e6ba */
if(!s->budget--) { s->failed_pc=0x0c06e6bau; return 0; }
vf3_matrix_load(s,ram,1,r[5]+r[0]);
goto P_0c06e6bc;
P_0c06e6bc: /* original f15d, guest PC 0x0c06e6bc */
if(!s->budget--) { s->failed_pc=0x0c06e6bcu; return 0; }
fr[1]&=0x7fffffffu;
goto P_0c06e6be;
P_0c06e6be: /* original f145, guest PC 0x0c06e6be */
if(!s->budget--) { s->failed_pc=0x0c06e6beu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[4]))!=0);
goto P_0c06e6c0;
P_0c06e6c0: /* original 8901, guest PC 0x0c06e6c0 */
if(!s->budget--) { s->failed_pc=0x0c06e6c0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06e6c6; }
goto P_0c06e6c2;
P_0c06e6c2: /* original a08f, guest PC 0x0c06e6c2 */
if(!s->budget--) { s->failed_pc=0x0c06e6c2u; return 0; }
goto P_0c06e7e4;
P_0c06e6c4: /* original 0009, guest PC 0x0c06e6c4 */
if(!s->budget--) { s->failed_pc=0x0c06e6c4u; return 0; }
goto P_0c06e6c6;
P_0c06e6c6: /* original e01c, guest PC 0x0c06e6c6 */
if(!s->budget--) { s->failed_pc=0x0c06e6c6u; return 0; }
r[0]=0x0000001cu;
goto P_0c06e6c8;
P_0c06e6c8: /* original f0ac, guest PC 0x0c06e6c8 */
if(!s->budget--) { s->failed_pc=0x0c06e6c8u; return 0; }
vf3_matrix_move(s,0,10);
goto P_0c06e6ca;
P_0c06e6ca: /* original f3f6, guest PC 0x0c06e6ca */
if(!s->budget--) { s->failed_pc=0x0c06e6cau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06e6cc;
P_0c06e6cc: /* original e028, guest PC 0x0c06e6cc */
if(!s->budget--) { s->failed_pc=0x0c06e6ccu; return 0; }
r[0]=0x00000028u;
goto P_0c06e6ce;
P_0c06e6ce: /* original f2f6, guest PC 0x0c06e6ce */
if(!s->budget--) { s->failed_pc=0x0c06e6ceu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c06e6d0;
P_0c06e6d0: /* original f32e, guest PC 0x0c06e6d0 */
if(!s->budget--) { s->failed_pc=0x0c06e6d0u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c06e6d2;
P_0c06e6d2: /* original f0bc, guest PC 0x0c06e6d2 */
if(!s->budget--) { s->failed_pc=0x0c06e6d2u; return 0; }
vf3_matrix_move(s,0,11);
goto P_0c06e6d4;
P_0c06e6d4: /* original f28d, guest PC 0x0c06e6d4 */
if(!s->budget--) { s->failed_pc=0x0c06e6d4u; return 0; }
fr[2]=0;
goto P_0c06e6d6;
P_0c06e6d6: /* original fb4c, guest PC 0x0c06e6d6 */
if(!s->budget--) { s->failed_pc=0x0c06e6d6u; return 0; }
vf3_matrix_move(s,11,4);
goto P_0c06e6d8;
P_0c06e6d8: /* original f3fe, guest PC 0x0c06e6d8 */
if(!s->budget--) { s->failed_pc=0x0c06e6d8u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[15],fr[3],r[18]);
goto P_0c06e6da;
P_0c06e6da: /* original fa3c, guest PC 0x0c06e6da */
if(!s->budget--) { s->failed_pc=0x0c06e6dau; return 0; }
vf3_matrix_move(s,10,3);
goto P_0c06e6dc;
P_0c06e6dc: /* original f2a5, guest PC 0x0c06e6dc */
if(!s->budget--) { s->failed_pc=0x0c06e6dcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[10]))!=0);
goto P_0c06e6de;
P_0c06e6de: /* original 8d01, guest PC 0x0c06e6de */
if(!s->budget--) { s->failed_pc=0x0c06e6deu; return 0; }
cond=r[17]&1u;
fr[11]^=0x80000000u;
if(cond) { goto P_0c06e6e4; }
goto P_0c06e6e2;
P_0c06e6e0: /* original fb4d, guest PC 0x0c06e6e0 */
if(!s->budget--) { s->failed_pc=0x0c06e6e0u; return 0; }
fr[11]^=0x80000000u;
goto P_0c06e6e2;
P_0c06e6e2: /* original fb4c, guest PC 0x0c06e6e2 */
if(!s->budget--) { s->failed_pc=0x0c06e6e2u; return 0; }
vf3_matrix_move(s,11,4);
goto P_0c06e6e4;
P_0c06e6e4: /* original f38d, guest PC 0x0c06e6e4 */
if(!s->budget--) { s->failed_pc=0x0c06e6e4u; return 0; }
fr[3]=0;
goto P_0c06e6e6;
P_0c06e6e6: /* original f3a5, guest PC 0x0c06e6e6 */
if(!s->budget--) { s->failed_pc=0x0c06e6e6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[10]))!=0);
goto P_0c06e6e8;
P_0c06e6e8: /* original f15c, guest PC 0x0c06e6e8 */
if(!s->budget--) { s->failed_pc=0x0c06e6e8u; return 0; }
vf3_matrix_move(s,1,5);
goto P_0c06e6ea;
P_0c06e6ea: /* original f14d, guest PC 0x0c06e6ea */
if(!s->budget--) { s->failed_pc=0x0c06e6eau; return 0; }
fr[1]^=0x80000000u;
goto P_0c06e6ec;
P_0c06e6ec: /* original f47c, guest PC 0x0c06e6ec */
if(!s->budget--) { s->failed_pc=0x0c06e6ecu; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c06e6ee;
P_0c06e6ee: /* original 8f01, guest PC 0x0c06e6ee */
if(!s->budget--) { s->failed_pc=0x0c06e6eeu; return 0; }
cond=r[17]&1u;
fr[4]^=0x80000000u;
if(!cond) { goto P_0c06e6f4; }
goto P_0c06e6f2;
P_0c06e6f0: /* original f44d, guest PC 0x0c06e6f0 */
if(!s->budget--) { s->failed_pc=0x0c06e6f0u; return 0; }
fr[4]^=0x80000000u;
goto P_0c06e6f2;
P_0c06e6f2: /* original f51c, guest PC 0x0c06e6f2 */
if(!s->budget--) { s->failed_pc=0x0c06e6f2u; return 0; }
vf3_matrix_move(s,5,1);
goto P_0c06e6f4;
P_0c06e6f4: /* original f38d, guest PC 0x0c06e6f4 */
if(!s->budget--) { s->failed_pc=0x0c06e6f4u; return 0; }
fr[3]=0;
goto P_0c06e6f6;
P_0c06e6f6: /* original f3a5, guest PC 0x0c06e6f6 */
if(!s->budget--) { s->failed_pc=0x0c06e6f6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[10]))!=0);
goto P_0c06e6f8;
P_0c06e6f8: /* original 8d01, guest PC 0x0c06e6f8 */
if(!s->budget--) { s->failed_pc=0x0c06e6f8u; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[13],r[18],'*');
if(cond) { goto P_0c06e6fe; }
goto P_0c06e6fc;
P_0c06e6fa: /* original f5d2, guest PC 0x0c06e6fa */
if(!s->budget--) { s->failed_pc=0x0c06e6fau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[13],r[18],'*');
goto P_0c06e6fc;
P_0c06e6fc: /* original f47c, guest PC 0x0c06e6fc */
if(!s->budget--) { s->failed_pc=0x0c06e6fcu; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c06e6fe;
P_0c06e6fe: /* original f38d, guest PC 0x0c06e6fe */
if(!s->budget--) { s->failed_pc=0x0c06e6feu; return 0; }
fr[3]=0;
goto P_0c06e700;
P_0c06e700: /* original fd34, guest PC 0x0c06e700 */
if(!s->budget--) { s->failed_pc=0x0c06e700u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[13])==as_float(fr[3]))!=0);
goto P_0c06e702;
P_0c06e702: /* original 8f69, guest PC 0x0c06e702 */
if(!s->budget--) { s->failed_pc=0x0c06e702u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[13],r[18],'*');
if(!cond) { goto P_0c06e7d8; }
goto P_0c06e706;
P_0c06e704: /* original f4d2, guest PC 0x0c06e704 */
if(!s->budget--) { s->failed_pc=0x0c06e704u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[13],r[18],'*');
goto P_0c06e706;
P_0c06e706: /* original e024, guest PC 0x0c06e706 */
if(!s->budget--) { s->failed_pc=0x0c06e706u; return 0; }
r[0]=0x00000024u;
goto P_0c06e708;
P_0c06e708: /* original f2f6, guest PC 0x0c06e708 */
if(!s->budget--) { s->failed_pc=0x0c06e708u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c06e70a;
P_0c06e70a: /* original e020, guest PC 0x0c06e70a */
if(!s->budget--) { s->failed_pc=0x0c06e70au; return 0; }
r[0]=0x00000020u;
goto P_0c06e70c;
P_0c06e70c: /* original f4f6, guest PC 0x0c06e70c */
if(!s->budget--) { s->failed_pc=0x0c06e70cu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c06e70e;
P_0c06e70e: /* original f420, guest PC 0x0c06e70e */
if(!s->budget--) { s->failed_pc=0x0c06e70eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'+');
goto P_0c06e710;
P_0c06e710: /* original f845, guest PC 0x0c06e710 */
if(!s->budget--) { s->failed_pc=0x0c06e710u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[4]))!=0);
goto P_0c06e712;
P_0c06e712: /* original 8f02, guest PC 0x0c06e712 */
if(!s->budget--) { s->failed_pc=0x0c06e712u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,13,15);
if(!cond) { goto P_0c06e71a; }
goto P_0c06e716;
P_0c06e714: /* original fdfc, guest PC 0x0c06e714 */
if(!s->budget--) { s->failed_pc=0x0c06e714u; return 0; }
vf3_matrix_move(s,13,15);
goto P_0c06e716;
P_0c06e716: /* original a001, guest PC 0x0c06e716 */
if(!s->budget--) { s->failed_pc=0x0c06e716u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c06e71c;
P_0c06e718: /* original f43c, guest PC 0x0c06e718 */
if(!s->budget--) { s->failed_pc=0x0c06e718u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c06e71a;
P_0c06e71a: /* original f47d, guest PC 0x0c06e71a */
if(!s->budget--) { s->failed_pc=0x0c06e71au; return 0; }
if(!vf3_fpu_fsrra(fr[4],r[18],&fr[4])) goto unsupported;
goto P_0c06e71c;
P_0c06e71c: /* original f34c, guest PC 0x0c06e71c */
if(!s->budget--) { s->failed_pc=0x0c06e71cu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c06e71e;
P_0c06e71e: /* original fd42, guest PC 0x0c06e71e */
if(!s->budget--) { s->failed_pc=0x0c06e71eu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'*');
goto P_0c06e720;
P_0c06e720: /* original f46c, guest PC 0x0c06e720 */
if(!s->budget--) { s->failed_pc=0x0c06e720u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c06e722;
P_0c06e722: /* original f432, guest PC 0x0c06e722 */
if(!s->budget--) { s->failed_pc=0x0c06e722u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c06e724;
P_0c06e724: /* original f54c, guest PC 0x0c06e724 */
if(!s->budget--) { s->failed_pc=0x0c06e724u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c06e726;
P_0c06e726: /* original f4dc, guest PC 0x0c06e726 */
if(!s->budget--) { s->failed_pc=0x0c06e726u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c06e728;
P_0c06e728: /* original a056, guest PC 0x0c06e728 */
if(!s->budget--) { s->failed_pc=0x0c06e728u; return 0; }
fr[4]^=0x80000000u;
goto P_0c06e7d8;
P_0c06e72a: /* original f44d, guest PC 0x0c06e72a */
if(!s->budget--) { s->failed_pc=0x0c06e72au; return 0; }
fr[4]^=0x80000000u;
goto P_0c06e72c;
P_0c06e72c: /* original e008, guest PC 0x0c06e72c */
if(!s->budget--) { s->failed_pc=0x0c06e72cu; return 0; }
r[0]=0x00000008u;
goto P_0c06e72e;
P_0c06e72e: /* original fdf8, guest PC 0x0c06e72e */
if(!s->budget--) { s->failed_pc=0x0c06e72eu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
goto P_0c06e730;
P_0c06e730: /* original f5f6, guest PC 0x0c06e730 */
if(!s->budget--) { s->failed_pc=0x0c06e730u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c06e732;
P_0c06e732: /* original fdb1, guest PC 0x0c06e732 */
if(!s->budget--) { s->failed_pc=0x0c06e732u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[11],r[18],'-');
goto P_0c06e734;
P_0c06e734: /* original f5a1, guest PC 0x0c06e734 */
if(!s->budget--) { s->failed_pc=0x0c06e734u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[10],r[18],'-');
goto P_0c06e736;
P_0c06e736: /* original f0dc, guest PC 0x0c06e736 */
if(!s->budget--) { s->failed_pc=0x0c06e736u; return 0; }
vf3_matrix_move(s,0,13);
goto P_0c06e738;
P_0c06e738: /* original f35c, guest PC 0x0c06e738 */
if(!s->budget--) { s->failed_pc=0x0c06e738u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c06e73a;
P_0c06e73a: /* original f352, guest PC 0x0c06e73a */
if(!s->budget--) { s->failed_pc=0x0c06e73au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c06e73c;
P_0c06e73c: /* original f3de, guest PC 0x0c06e73c */
if(!s->budget--) { s->failed_pc=0x0c06e73cu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[13],fr[3],r[18]);
goto P_0c06e73e;
P_0c06e73e: /* original f43c, guest PC 0x0c06e73e */
if(!s->budget--) { s->failed_pc=0x0c06e73eu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c06e740;
P_0c06e740: /* original f845, guest PC 0x0c06e740 */
if(!s->budget--) { s->failed_pc=0x0c06e740u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[4]))!=0);
goto P_0c06e742;
P_0c06e742: /* original 8b07, guest PC 0x0c06e742 */
if(!s->budget--) { s->failed_pc=0x0c06e742u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06e754; }
goto P_0c06e744;
P_0c06e744: /* original a008, guest PC 0x0c06e744 */
if(!s->budget--) { s->failed_pc=0x0c06e744u; return 0; }
fr[1]=0;
goto P_0c06e758;
P_0c06e746: /* original f18d, guest PC 0x0c06e746 */
if(!s->budget--) { s->failed_pc=0x0c06e746u; return 0; }
fr[1]=0;
if(!vf3_matrix_family(0x0c06e748u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06e748u; return 0; } return 1;
P_0c06e754: /* original f14c, guest PC 0x0c06e754 */
if(!s->budget--) { s->failed_pc=0x0c06e754u; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c06e756;
P_0c06e756: /* original f17d, guest PC 0x0c06e756 */
if(!s->budget--) { s->failed_pc=0x0c06e756u; return 0; }
if(!vf3_fpu_fsrra(fr[1],r[18],&fr[1])) goto unsupported;
goto P_0c06e758;
P_0c06e758: /* original 6063, guest PC 0x0c06e758 */
if(!s->budget--) { s->failed_pc=0x0c06e758u; return 0; }
r[0]=r[6];
goto P_0c06e75a;
P_0c06e75a: /* original 4008, guest PC 0x0c06e75a */
if(!s->budget--) { s->failed_pc=0x0c06e75au; return 0; }
r[0]<<=2;
goto P_0c06e75c;
P_0c06e75c: /* original f412, guest PC 0x0c06e75c */
if(!s->budget--) { s->failed_pc=0x0c06e75cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'*');
goto P_0c06e75e;
P_0c06e75e: /* original f756, guest PC 0x0c06e75e */
if(!s->budget--) { s->failed_pc=0x0c06e75eu; return 0; }
vf3_matrix_load(s,ram,7,r[5]+r[0]);
goto P_0c06e760;
P_0c06e760: /* original f75d, guest PC 0x0c06e760 */
if(!s->budget--) { s->failed_pc=0x0c06e760u; return 0; }
fr[7]&=0x7fffffffu;
goto P_0c06e762;
P_0c06e762: /* original f745, guest PC 0x0c06e762 */
if(!s->budget--) { s->failed_pc=0x0c06e762u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[4]))!=0);
goto P_0c06e764;
P_0c06e764: /* original 8b3e, guest PC 0x0c06e764 */
if(!s->budget--) { s->failed_pc=0x0c06e764u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06e7e4; }
goto P_0c06e766;
P_0c06e766: /* original e018, guest PC 0x0c06e766 */
if(!s->budget--) { s->failed_pc=0x0c06e766u; return 0; }
r[0]=0x00000018u;
goto P_0c06e768;
P_0c06e768: /* original f0ac, guest PC 0x0c06e768 */
if(!s->budget--) { s->failed_pc=0x0c06e768u; return 0; }
vf3_matrix_move(s,0,10);
goto P_0c06e76a;
P_0c06e76a: /* original f7f6, guest PC 0x0c06e76a */
if(!s->budget--) { s->failed_pc=0x0c06e76au; return 0; }
vf3_matrix_load(s,ram,7,r[15]+r[0]);
goto P_0c06e76c;
P_0c06e76c: /* original e030, guest PC 0x0c06e76c */
if(!s->budget--) { s->failed_pc=0x0c06e76cu; return 0; }
r[0]=0x00000030u;
goto P_0c06e76e;
P_0c06e76e: /* original f3f6, guest PC 0x0c06e76e */
if(!s->budget--) { s->failed_pc=0x0c06e76eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06e770;
P_0c06e770: /* original e02c, guest PC 0x0c06e770 */
if(!s->budget--) { s->failed_pc=0x0c06e770u; return 0; }
r[0]=0x0000002cu;
goto P_0c06e772;
P_0c06e772: /* original f2f6, guest PC 0x0c06e772 */
if(!s->budget--) { s->failed_pc=0x0c06e772u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c06e774;
P_0c06e774: /* original f73e, guest PC 0x0c06e774 */
if(!s->budget--) { s->failed_pc=0x0c06e774u; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[3],fr[7],r[18]);
goto P_0c06e776;
P_0c06e776: /* original f0bc, guest PC 0x0c06e776 */
if(!s->budget--) { s->failed_pc=0x0c06e776u; return 0; }
vf3_matrix_move(s,0,11);
goto P_0c06e778;
P_0c06e778: /* original fa4c, guest PC 0x0c06e778 */
if(!s->budget--) { s->failed_pc=0x0c06e778u; return 0; }
vf3_matrix_move(s,10,4);
goto P_0c06e77a;
P_0c06e77a: /* original f37c, guest PC 0x0c06e77a */
if(!s->budget--) { s->failed_pc=0x0c06e77au; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c06e77c;
P_0c06e77c: /* original f32e, guest PC 0x0c06e77c */
if(!s->budget--) { s->failed_pc=0x0c06e77cu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c06e77e;
P_0c06e77e: /* original f73c, guest PC 0x0c06e77e */
if(!s->budget--) { s->failed_pc=0x0c06e77eu; return 0; }
vf3_matrix_move(s,7,3);
goto P_0c06e780;
P_0c06e780: /* original f38d, guest PC 0x0c06e780 */
if(!s->budget--) { s->failed_pc=0x0c06e780u; return 0; }
fr[3]=0;
goto P_0c06e782;
P_0c06e782: /* original f375, guest PC 0x0c06e782 */
if(!s->budget--) { s->failed_pc=0x0c06e782u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[7]))!=0);
goto P_0c06e784;
P_0c06e784: /* original 8d02, guest PC 0x0c06e784 */
if(!s->budget--) { s->failed_pc=0x0c06e784u; return 0; }
cond=r[17]&1u;
fr[10]^=0x80000000u;
if(cond) { goto P_0c06e78c; }
goto P_0c06e788;
P_0c06e786: /* original fa4d, guest PC 0x0c06e786 */
if(!s->budget--) { s->failed_pc=0x0c06e786u; return 0; }
fr[10]^=0x80000000u;
goto P_0c06e788;
P_0c06e788: /* original a001, guest PC 0x0c06e788 */
if(!s->budget--) { s->failed_pc=0x0c06e788u; return 0; }
vf3_matrix_move(s,11,4);
goto P_0c06e78e;
P_0c06e78a: /* original fb4c, guest PC 0x0c06e78a */
if(!s->budget--) { s->failed_pc=0x0c06e78au; return 0; }
vf3_matrix_move(s,11,4);
goto P_0c06e78c;
P_0c06e78c: /* original fbac, guest PC 0x0c06e78c */
if(!s->budget--) { s->failed_pc=0x0c06e78cu; return 0; }
vf3_matrix_move(s,11,10);
goto P_0c06e78e;
P_0c06e78e: /* original f38d, guest PC 0x0c06e78e */
if(!s->budget--) { s->failed_pc=0x0c06e78eu; return 0; }
fr[3]=0;
goto P_0c06e790;
P_0c06e790: /* original f375, guest PC 0x0c06e790 */
if(!s->budget--) { s->failed_pc=0x0c06e790u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[7]))!=0);
goto P_0c06e792;
P_0c06e792: /* original f45c, guest PC 0x0c06e792 */
if(!s->budget--) { s->failed_pc=0x0c06e792u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c06e794;
P_0c06e794: /* original f44d, guest PC 0x0c06e794 */
if(!s->budget--) { s->failed_pc=0x0c06e794u; return 0; }
fr[4]^=0x80000000u;
goto P_0c06e796;
P_0c06e796: /* original fadc, guest PC 0x0c06e796 */
if(!s->budget--) { s->failed_pc=0x0c06e796u; return 0; }
vf3_matrix_move(s,10,13);
goto P_0c06e798;
P_0c06e798: /* original 8f01, guest PC 0x0c06e798 */
if(!s->budget--) { s->failed_pc=0x0c06e798u; return 0; }
cond=r[17]&1u;
fr[10]^=0x80000000u;
if(!cond) { goto P_0c06e79e; }
goto P_0c06e79c;
P_0c06e79a: /* original fa4d, guest PC 0x0c06e79a */
if(!s->budget--) { s->failed_pc=0x0c06e79au; return 0; }
fr[10]^=0x80000000u;
goto P_0c06e79c;
P_0c06e79c: /* original f54c, guest PC 0x0c06e79c */
if(!s->budget--) { s->failed_pc=0x0c06e79cu; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c06e79e;
P_0c06e79e: /* original f38d, guest PC 0x0c06e79e */
if(!s->budget--) { s->failed_pc=0x0c06e79eu; return 0; }
fr[3]=0;
goto P_0c06e7a0;
P_0c06e7a0: /* original f375, guest PC 0x0c06e7a0 */
if(!s->budget--) { s->failed_pc=0x0c06e7a0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[7]))!=0);
goto P_0c06e7a2;
P_0c06e7a2: /* original 8d02, guest PC 0x0c06e7a2 */
if(!s->budget--) { s->failed_pc=0x0c06e7a2u; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[1],r[18],'*');
if(cond) { goto P_0c06e7aa; }
goto P_0c06e7a6;
P_0c06e7a4: /* original f512, guest PC 0x0c06e7a4 */
if(!s->budget--) { s->failed_pc=0x0c06e7a4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[1],r[18],'*');
goto P_0c06e7a6;
P_0c06e7a6: /* original a001, guest PC 0x0c06e7a6 */
if(!s->budget--) { s->failed_pc=0x0c06e7a6u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c06e7ac;
P_0c06e7a8: /* original f4dc, guest PC 0x0c06e7a8 */
if(!s->budget--) { s->failed_pc=0x0c06e7a8u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c06e7aa;
P_0c06e7aa: /* original f4ac, guest PC 0x0c06e7aa */
if(!s->budget--) { s->failed_pc=0x0c06e7aau; return 0; }
vf3_matrix_move(s,4,10);
goto P_0c06e7ac;
P_0c06e7ac: /* original f38d, guest PC 0x0c06e7ac */
if(!s->budget--) { s->failed_pc=0x0c06e7acu; return 0; }
fr[3]=0;
goto P_0c06e7ae;
P_0c06e7ae: /* original f134, guest PC 0x0c06e7ae */
if(!s->budget--) { s->failed_pc=0x0c06e7aeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])==as_float(fr[3]))!=0);
goto P_0c06e7b0;
P_0c06e7b0: /* original 8f12, guest PC 0x0c06e7b0 */
if(!s->budget--) { s->failed_pc=0x0c06e7b0u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'*');
if(!cond) { goto P_0c06e7d8; }
goto P_0c06e7b4;
P_0c06e7b2: /* original f412, guest PC 0x0c06e7b2 */
if(!s->budget--) { s->failed_pc=0x0c06e7b2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'*');
goto P_0c06e7b4;
P_0c06e7b4: /* original e024, guest PC 0x0c06e7b4 */
if(!s->budget--) { s->failed_pc=0x0c06e7b4u; return 0; }
r[0]=0x00000024u;
goto P_0c06e7b6;
P_0c06e7b6: /* original f2f6, guest PC 0x0c06e7b6 */
if(!s->budget--) { s->failed_pc=0x0c06e7b6u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c06e7b8;
P_0c06e7b8: /* original e020, guest PC 0x0c06e7b8 */
if(!s->budget--) { s->failed_pc=0x0c06e7b8u; return 0; }
r[0]=0x00000020u;
goto P_0c06e7ba;
P_0c06e7ba: /* original f4f6, guest PC 0x0c06e7ba */
if(!s->budget--) { s->failed_pc=0x0c06e7bau; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c06e7bc;
P_0c06e7bc: /* original f420, guest PC 0x0c06e7bc */
if(!s->budget--) { s->failed_pc=0x0c06e7bcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'+');
goto P_0c06e7be;
P_0c06e7be: /* original f845, guest PC 0x0c06e7be */
if(!s->budget--) { s->failed_pc=0x0c06e7beu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[4]))!=0);
goto P_0c06e7c0;
P_0c06e7c0: /* original 8f02, guest PC 0x0c06e7c0 */
if(!s->budget--) { s->failed_pc=0x0c06e7c0u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,13,15);
if(!cond) { goto P_0c06e7c8; }
goto P_0c06e7c4;
P_0c06e7c2: /* original fdfc, guest PC 0x0c06e7c2 */
if(!s->budget--) { s->failed_pc=0x0c06e7c2u; return 0; }
vf3_matrix_move(s,13,15);
goto P_0c06e7c4;
P_0c06e7c4: /* original a001, guest PC 0x0c06e7c4 */
if(!s->budget--) { s->failed_pc=0x0c06e7c4u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c06e7ca;
P_0c06e7c6: /* original f43c, guest PC 0x0c06e7c6 */
if(!s->budget--) { s->failed_pc=0x0c06e7c6u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c06e7c8;
P_0c06e7c8: /* original f47d, guest PC 0x0c06e7c8 */
if(!s->budget--) { s->failed_pc=0x0c06e7c8u; return 0; }
if(!vf3_fpu_fsrra(fr[4],r[18],&fr[4])) goto unsupported;
goto P_0c06e7ca;
P_0c06e7ca: /* original f34c, guest PC 0x0c06e7ca */
if(!s->budget--) { s->failed_pc=0x0c06e7cau; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c06e7cc;
P_0c06e7cc: /* original fd42, guest PC 0x0c06e7cc */
if(!s->budget--) { s->failed_pc=0x0c06e7ccu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'*');
goto P_0c06e7ce;
P_0c06e7ce: /* original f46c, guest PC 0x0c06e7ce */
if(!s->budget--) { s->failed_pc=0x0c06e7ceu; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c06e7d0;
P_0c06e7d0: /* original f432, guest PC 0x0c06e7d0 */
if(!s->budget--) { s->failed_pc=0x0c06e7d0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c06e7d2;
P_0c06e7d2: /* original f54c, guest PC 0x0c06e7d2 */
if(!s->budget--) { s->failed_pc=0x0c06e7d2u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c06e7d4;
P_0c06e7d4: /* original f4dc, guest PC 0x0c06e7d4 */
if(!s->budget--) { s->failed_pc=0x0c06e7d4u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c06e7d6;
P_0c06e7d6: /* original f44d, guest PC 0x0c06e7d6 */
if(!s->budget--) { s->failed_pc=0x0c06e7d6u; return 0; }
fr[4]^=0x80000000u;
goto P_0c06e7d8;
P_0c06e7d8: /* original 6063, guest PC 0x0c06e7d8 */
if(!s->budget--) { s->failed_pc=0x0c06e7d8u; return 0; }
r[0]=r[6];
goto P_0c06e7da;
P_0c06e7da: /* original 4008, guest PC 0x0c06e7da */
if(!s->budget--) { s->failed_pc=0x0c06e7dau; return 0; }
r[0]<<=2;
goto P_0c06e7dc;
P_0c06e7dc: /* original f5b7, guest PC 0x0c06e7dc */
if(!s->budget--) { s->failed_pc=0x0c06e7dcu; return 0; }
vf3_matrix_store(s,ram,11,r[5]+r[0]);
goto P_0c06e7de;
P_0c06e7de: /* original e004, guest PC 0x0c06e7de */
if(!s->budget--) { s->failed_pc=0x0c06e7deu; return 0; }
r[0]=0x00000004u;
goto P_0c06e7e0;
P_0c06e7e0: /* original fc5a, guest PC 0x0c06e7e0 */
if(!s->budget--) { s->failed_pc=0x0c06e7e0u; return 0; }
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c06e7e2;
P_0c06e7e2: /* original fc47, guest PC 0x0c06e7e2 */
if(!s->budget--) { s->failed_pc=0x0c06e7e2u; return 0; }
vf3_matrix_store(s,ram,4,r[12]+r[0]);
goto P_0c06e7e4;
P_0c06e7e4: /* original 7aff, guest PC 0x0c06e7e4 */
if(!s->budget--) { s->failed_pc=0x0c06e7e4u; return 0; }
r[10]+=0xffffffffu;
goto P_0c06e7e6;
P_0c06e7e6: /* original 7601, guest PC 0x0c06e7e6 */
if(!s->budget--) { s->failed_pc=0x0c06e7e6u; return 0; }
r[6]+=0x00000001u;
goto P_0c06e7e8;
P_0c06e7e8: /* original 2aa8, guest PC 0x0c06e7e8 */
if(!s->budget--) { s->failed_pc=0x0c06e7e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c06e7ea;
P_0c06e7ea: /* original 8901, guest PC 0x0c06e7ea */
if(!s->budget--) { s->failed_pc=0x0c06e7eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06e7f0; }
goto P_0c06e7ec;
P_0c06e7ec: /* original af18, guest PC 0x0c06e7ec */
if(!s->budget--) { s->failed_pc=0x0c06e7ecu; return 0; }
goto P_0c06e620;
P_0c06e7ee: /* original 0009, guest PC 0x0c06e7ee */
if(!s->budget--) { s->failed_pc=0x0c06e7eeu; return 0; }
goto P_0c06e7f0;
P_0c06e7f0: /* original 78ff, guest PC 0x0c06e7f0 */
if(!s->budget--) { s->failed_pc=0x0c06e7f0u; return 0; }
r[8]+=0xffffffffu;
goto P_0c06e7f2;
P_0c06e7f2: /* original d705, guest PC 0x0c06e7f2 */
if(!s->budget--) { s->failed_pc=0x0c06e7f2u; return 0; }
r[7]=read(ram,0x0c06e808u,4);
goto P_0c06e7f4;
P_0c06e7f4: /* original 2888, guest PC 0x0c06e7f4 */
if(!s->budget--) { s->failed_pc=0x0c06e7f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c06e7f6;
P_0c06e7f6: /* original 8d02, guest PC 0x0c06e7f6 */
if(!s->budget--) { s->failed_pc=0x0c06e7f6u; return 0; }
cond=r[17]&1u;
r[6]=r[7];
if(cond) { goto P_0c06e7fe; }
goto P_0c06e7fa;
P_0c06e7f8: /* original 6673, guest PC 0x0c06e7f8 */
if(!s->budget--) { s->failed_pc=0x0c06e7f8u; return 0; }
r[6]=r[7];
goto P_0c06e7fa;
P_0c06e7fa: /* original aec5, guest PC 0x0c06e7fa */
if(!s->budget--) { s->failed_pc=0x0c06e7fau; return 0; }
goto P_0c06e588;
P_0c06e7fc: /* original 0009, guest PC 0x0c06e7fc */
if(!s->budget--) { s->failed_pc=0x0c06e7fcu; return 0; }
goto P_0c06e7fe;
P_0c06e7fe: /* original 6863, guest PC 0x0c06e7fe */
if(!s->budget--) { s->failed_pc=0x0c06e7feu; return 0; }
r[8]=r[6];
goto P_0c06e800;
P_0c06e800: /* original 78ff, guest PC 0x0c06e800 */
if(!s->budget--) { s->failed_pc=0x0c06e800u; return 0; }
r[8]+=0xffffffffu;
goto P_0c06e802;
P_0c06e802: /* original 6cb3, guest PC 0x0c06e802 */
if(!s->budget--) { s->failed_pc=0x0c06e802u; return 0; }
r[12]=r[11];
goto P_0c06e804;
P_0c06e804: /* original a03e, guest PC 0x0c06e804 */
if(!s->budget--) { s->failed_pc=0x0c06e804u; return 0; }
r[13]=0x00000000u;
goto P_0c06e884;
P_0c06e806: /* original ed00, guest PC 0x0c06e806 */
if(!s->budget--) { s->failed_pc=0x0c06e806u; return 0; }
r[13]=0x00000000u;
if(!vf3_matrix_family(0x0c06e808u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06e808u; return 0; } return 1;
P_0c06e80c: /* original 7801, guest PC 0x0c06e80c */
if(!s->budget--) { s->failed_pc=0x0c06e80cu; return 0; }
r[8]+=0x00000001u;
goto P_0c06e80e;
P_0c06e80e: /* original d24f, guest PC 0x0c06e80e */
if(!s->budget--) { s->failed_pc=0x0c06e80eu; return 0; }
r[2]=read(ram,0x0c06e94cu,4);
goto P_0c06e810;
P_0c06e810: /* original 6680, guest PC 0x0c06e810 */
if(!s->budget--) { s->failed_pc=0x0c06e810u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[8],1);
r[6]=tmp;
goto P_0c06e812;
P_0c06e812: /* original 616c, guest PC 0x0c06e812 */
if(!s->budget--) { s->failed_pc=0x0c06e812u; return 0; }
r[1]=r[6]&255u;
goto P_0c06e814;
P_0c06e814: /* original 420b, guest PC 0x0c06e814 */
if(!s->budget--) { s->failed_pc=0x0c06e814u; return 0; }
target=r[2];
r[16]=code_base|0x0c06e818u;
r[0]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06e818u) { target=s->pc; goto dispatch; }
goto P_0c06e818;
P_0c06e816: /* original 60e3, guest PC 0x0c06e816 */
if(!s->budget--) { s->failed_pc=0x0c06e816u; return 0; }
r[0]=r[14];
goto P_0c06e818;
P_0c06e818: /* original 9393, guest PC 0x0c06e818 */
if(!s->budget--) { s->failed_pc=0x0c06e818u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06e942u,2);
goto P_0c06e81a;
P_0c06e81a: /* original 6a03, guest PC 0x0c06e81a */
if(!s->budget--) { s->failed_pc=0x0c06e81au; return 0; }
r[10]=r[0];
goto P_0c06e81c;
P_0c06e81c: /* original 6603, guest PC 0x0c06e81c */
if(!s->budget--) { s->failed_pc=0x0c06e81cu; return 0; }
r[6]=r[0];
goto P_0c06e81e;
P_0c06e81e: /* original 6903, guest PC 0x0c06e81e */
if(!s->budget--) { s->failed_pc=0x0c06e81eu; return 0; }
r[9]=r[0];
goto P_0c06e820;
P_0c06e820: /* original 60d3, guest PC 0x0c06e820 */
if(!s->budget--) { s->failed_pc=0x0c06e820u; return 0; }
r[0]=r[13];
goto P_0c06e822;
P_0c06e822: /* original 4008, guest PC 0x0c06e822 */
if(!s->budget--) { s->failed_pc=0x0c06e822u; return 0; }
r[0]<<=2;
goto P_0c06e824;
P_0c06e824: /* original 334c, guest PC 0x0c06e824 */
if(!s->budget--) { s->failed_pc=0x0c06e824u; return 0; }
r[3]+=r[4];
goto P_0c06e826;
P_0c06e826: /* original fa56, guest PC 0x0c06e826 */
if(!s->budget--) { s->failed_pc=0x0c06e826u; return 0; }
vf3_matrix_load(s,ram,10,r[5]+r[0]);
goto P_0c06e828;
P_0c06e828: /* original 4a08, guest PC 0x0c06e828 */
if(!s->budget--) { s->failed_pc=0x0c06e828u; return 0; }
r[10]<<=2;
goto P_0c06e82a;
P_0c06e82a: /* original 968b, guest PC 0x0c06e82a */
if(!s->budget--) { s->failed_pc=0x0c06e82au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06e944u,2);
goto P_0c06e82c;
P_0c06e82c: /* original 3a3c, guest PC 0x0c06e82c */
if(!s->budget--) { s->failed_pc=0x0c06e82cu; return 0; }
r[10]+=r[3];
goto P_0c06e82e;
P_0c06e82e: /* original f4ac, guest PC 0x0c06e82e */
if(!s->budget--) { s->failed_pc=0x0c06e82eu; return 0; }
vf3_matrix_move(s,4,10);
goto P_0c06e830;
P_0c06e830: /* original f8a8, guest PC 0x0c06e830 */
if(!s->budget--) { s->failed_pc=0x0c06e830u; return 0; }
vf3_matrix_load(s,ram,8,r[10]);
goto P_0c06e832;
P_0c06e832: /* original 4900, guest PC 0x0c06e832 */
if(!s->budget--) { s->failed_pc=0x0c06e832u; return 0; }
r[17]=(r[17]&~1u)|((r[9]>>31)!=0);
r[9]<<=1;
goto P_0c06e834;
P_0c06e834: /* original 6793, guest PC 0x0c06e834 */
if(!s->budget--) { s->failed_pc=0x0c06e834u; return 0; }
r[7]=r[9];
goto P_0c06e836;
P_0c06e836: /* original 4708, guest PC 0x0c06e836 */
if(!s->budget--) { s->failed_pc=0x0c06e836u; return 0; }
r[7]<<=2;
goto P_0c06e838;
P_0c06e838: /* original f480, guest PC 0x0c06e838 */
if(!s->budget--) { s->failed_pc=0x0c06e838u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'+');
goto P_0c06e83a;
P_0c06e83a: /* original 364c, guest PC 0x0c06e83a */
if(!s->budget--) { s->failed_pc=0x0c06e83au; return 0; }
r[6]+=r[4];
goto P_0c06e83c;
P_0c06e83c: /* original 367c, guest PC 0x0c06e83c */
if(!s->budget--) { s->failed_pc=0x0c06e83cu; return 0; }
r[6]+=r[7];
goto P_0c06e83e;
P_0c06e83e: /* original f38d, guest PC 0x0c06e83e */
if(!s->budget--) { s->failed_pc=0x0c06e83eu; return 0; }
fr[3]=0;
goto P_0c06e840;
P_0c06e840: /* original 9381, guest PC 0x0c06e840 */
if(!s->budget--) { s->failed_pc=0x0c06e840u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06e946u,2);
goto P_0c06e842;
P_0c06e842: /* original e004, guest PC 0x0c06e842 */
if(!s->budget--) { s->failed_pc=0x0c06e842u; return 0; }
r[0]=0x00000004u;
goto P_0c06e844;
P_0c06e844: /* original f568, guest PC 0x0c06e844 */
if(!s->budget--) { s->failed_pc=0x0c06e844u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c06e846;
P_0c06e846: /* original f345, guest PC 0x0c06e846 */
if(!s->budget--) { s->failed_pc=0x0c06e846u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c06e848;
P_0c06e848: /* original f666, guest PC 0x0c06e848 */
if(!s->budget--) { s->failed_pc=0x0c06e848u; return 0; }
vf3_matrix_load(s,ram,6,r[6]+r[0]);
goto P_0c06e84a;
P_0c06e84a: /* original f95c, guest PC 0x0c06e84a */
if(!s->budget--) { s->failed_pc=0x0c06e84au; return 0; }
vf3_matrix_move(s,9,5);
goto P_0c06e84c;
P_0c06e84c: /* original 334c, guest PC 0x0c06e84c */
if(!s->budget--) { s->failed_pc=0x0c06e84cu; return 0; }
r[3]+=r[4];
goto P_0c06e84e;
P_0c06e84e: /* original f76c, guest PC 0x0c06e84e */
if(!s->budget--) { s->failed_pc=0x0c06e84eu; return 0; }
vf3_matrix_move(s,7,6);
goto P_0c06e850;
P_0c06e850: /* original 373c, guest PC 0x0c06e850 */
if(!s->budget--) { s->failed_pc=0x0c06e850u; return 0; }
r[7]+=r[3];
goto P_0c06e852;
P_0c06e852: /* original f94d, guest PC 0x0c06e852 */
if(!s->budget--) { s->failed_pc=0x0c06e852u; return 0; }
fr[9]^=0x80000000u;
goto P_0c06e854;
P_0c06e854: /* original 8f02, guest PC 0x0c06e854 */
if(!s->budget--) { s->failed_pc=0x0c06e854u; return 0; }
cond=r[17]&1u;
fr[7]^=0x80000000u;
if(!cond) { goto P_0c06e85c; }
goto P_0c06e858;
P_0c06e856: /* original f74d, guest PC 0x0c06e856 */
if(!s->budget--) { s->failed_pc=0x0c06e856u; return 0; }
fr[7]^=0x80000000u;
goto P_0c06e858;
P_0c06e858: /* original e004, guest PC 0x0c06e858 */
if(!s->budget--) { s->failed_pc=0x0c06e858u; return 0; }
r[0]=0x00000004u;
goto P_0c06e85a;
P_0c06e85a: /* original f4f6, guest PC 0x0c06e85a */
if(!s->budget--) { s->failed_pc=0x0c06e85au; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c06e85c;
P_0c06e85c: /* original f642, guest PC 0x0c06e85c */
if(!s->budget--) { s->failed_pc=0x0c06e85cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c06e85e;
P_0c06e85e: /* original e004, guest PC 0x0c06e85e */
if(!s->budget--) { s->failed_pc=0x0c06e85eu; return 0; }
r[0]=0x00000004u;
goto P_0c06e860;
P_0c06e860: /* original f542, guest PC 0x0c06e860 */
if(!s->budget--) { s->failed_pc=0x0c06e860u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c06e862;
P_0c06e862: /* original f65a, guest PC 0x0c06e862 */
if(!s->budget--) { s->failed_pc=0x0c06e862u; return 0; }
vf3_matrix_store(s,ram,5,r[6]);
goto P_0c06e864;
P_0c06e864: /* original f4ac, guest PC 0x0c06e864 */
if(!s->budget--) { s->failed_pc=0x0c06e864u; return 0; }
vf3_matrix_move(s,4,10);
goto P_0c06e866;
P_0c06e866: /* original f44d, guest PC 0x0c06e866 */
if(!s->budget--) { s->failed_pc=0x0c06e866u; return 0; }
fr[4]^=0x80000000u;
goto P_0c06e868;
P_0c06e868: /* original f480, guest PC 0x0c06e868 */
if(!s->budget--) { s->failed_pc=0x0c06e868u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'+');
goto P_0c06e86a;
P_0c06e86a: /* original f38d, guest PC 0x0c06e86a */
if(!s->budget--) { s->failed_pc=0x0c06e86au; return 0; }
fr[3]=0;
goto P_0c06e86c;
P_0c06e86c: /* original f345, guest PC 0x0c06e86c */
if(!s->budget--) { s->failed_pc=0x0c06e86cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c06e86e;
P_0c06e86e: /* original 8f02, guest PC 0x0c06e86e */
if(!s->budget--) { s->failed_pc=0x0c06e86eu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,6,r[6]+r[0]);
if(!cond) { goto P_0c06e876; }
goto P_0c06e872;
P_0c06e870: /* original f667, guest PC 0x0c06e870 */
if(!s->budget--) { s->failed_pc=0x0c06e870u; return 0; }
vf3_matrix_store(s,ram,6,r[6]+r[0]);
goto P_0c06e872;
P_0c06e872: /* original e004, guest PC 0x0c06e872 */
if(!s->budget--) { s->failed_pc=0x0c06e872u; return 0; }
r[0]=0x00000004u;
goto P_0c06e874;
P_0c06e874: /* original f4f6, guest PC 0x0c06e874 */
if(!s->budget--) { s->failed_pc=0x0c06e874u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c06e876;
P_0c06e876: /* original f742, guest PC 0x0c06e876 */
if(!s->budget--) { s->failed_pc=0x0c06e876u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c06e878;
P_0c06e878: /* original e004, guest PC 0x0c06e878 */
if(!s->budget--) { s->failed_pc=0x0c06e878u; return 0; }
r[0]=0x00000004u;
goto P_0c06e87a;
P_0c06e87a: /* original f942, guest PC 0x0c06e87a */
if(!s->budget--) { s->failed_pc=0x0c06e87au; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[4],r[18],'*');
goto P_0c06e87c;
P_0c06e87c: /* original 7d01, guest PC 0x0c06e87c */
if(!s->budget--) { s->failed_pc=0x0c06e87cu; return 0; }
r[13]+=0x00000001u;
goto P_0c06e87e;
P_0c06e87e: /* original 7cff, guest PC 0x0c06e87e */
if(!s->budget--) { s->failed_pc=0x0c06e87eu; return 0; }
r[12]+=0xffffffffu;
goto P_0c06e880;
P_0c06e880: /* original f79a, guest PC 0x0c06e880 */
if(!s->budget--) { s->failed_pc=0x0c06e880u; return 0; }
vf3_matrix_store(s,ram,9,r[7]);
goto P_0c06e882;
P_0c06e882: /* original f777, guest PC 0x0c06e882 */
if(!s->budget--) { s->failed_pc=0x0c06e882u; return 0; }
vf3_matrix_store(s,ram,7,r[7]+r[0]);
goto P_0c06e884;
P_0c06e884: /* original 2cc8, guest PC 0x0c06e884 */
if(!s->budget--) { s->failed_pc=0x0c06e884u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c06e886;
P_0c06e886: /* original 8bc1, guest PC 0x0c06e886 */
if(!s->budget--) { s->failed_pc=0x0c06e886u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06e80c; }
goto P_0c06e888;
P_0c06e888: /* original 7f58, guest PC 0x0c06e888 */
if(!s->budget--) { s->failed_pc=0x0c06e888u; return 0; }
r[15]+=0x00000058u;
goto P_0c06e88a;
P_0c06e88a: /* original 4f26, guest PC 0x0c06e88a */
if(!s->budget--) { s->failed_pc=0x0c06e88au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06e88c;
P_0c06e88c: /* original fdf9, guest PC 0x0c06e88c */
if(!s->budget--) { s->failed_pc=0x0c06e88cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06e88e;
P_0c06e88e: /* original fef9, guest PC 0x0c06e88e */
if(!s->budget--) { s->failed_pc=0x0c06e88eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06e890;
P_0c06e890: /* original fff9, guest PC 0x0c06e890 */
if(!s->budget--) { s->failed_pc=0x0c06e890u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06e892;
P_0c06e892: /* original 68f6, guest PC 0x0c06e892 */
if(!s->budget--) { s->failed_pc=0x0c06e892u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06e894;
P_0c06e894: /* original 69f6, guest PC 0x0c06e894 */
if(!s->budget--) { s->failed_pc=0x0c06e894u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06e896;
P_0c06e896: /* original 6af6, guest PC 0x0c06e896 */
if(!s->budget--) { s->failed_pc=0x0c06e896u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06e898;
P_0c06e898: /* original 6bf6, guest PC 0x0c06e898 */
if(!s->budget--) { s->failed_pc=0x0c06e898u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06e89a;
P_0c06e89a: /* original 6cf6, guest PC 0x0c06e89a */
if(!s->budget--) { s->failed_pc=0x0c06e89au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06e89c;
P_0c06e89c: /* original 6df6, guest PC 0x0c06e89c */
if(!s->budget--) { s->failed_pc=0x0c06e89cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06e89e;
P_0c06e89e: /* original 000b, guest PC 0x0c06e89e */
if(!s->budget--) { s->failed_pc=0x0c06e89eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06e8a0: /* original 6ef6, guest PC 0x0c06e8a0 */
if(!s->budget--) { s->failed_pc=0x0c06e8a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06e8a2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06e8a2u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
