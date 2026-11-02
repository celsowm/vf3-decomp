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
int vf3_away_batch24_adapter_13(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0bd4beu: goto P_0c0bd4be;
case 0x0c0bd4c0u: goto P_0c0bd4c0;
case 0x0c0bd4c2u: goto P_0c0bd4c2;
case 0x0c0bd4c4u: goto P_0c0bd4c4;
case 0x0c0bd4c6u: goto P_0c0bd4c6;
case 0x0c0bd4c8u: goto P_0c0bd4c8;
case 0x0c0bd4cau: goto P_0c0bd4ca;
case 0x0c0bd4ccu: goto P_0c0bd4cc;
case 0x0c0bd4ceu: goto P_0c0bd4ce;
case 0x0c0bd4d0u: goto P_0c0bd4d0;
case 0x0c0bd4d2u: goto P_0c0bd4d2;
case 0x0c0bd4d4u: goto P_0c0bd4d4;
case 0x0c0bd4d6u: goto P_0c0bd4d6;
case 0x0c0bd4d8u: goto P_0c0bd4d8;
case 0x0c0bd4dau: goto P_0c0bd4da;
case 0x0c0bd4dcu: goto P_0c0bd4dc;
case 0x0c0bd4deu: goto P_0c0bd4de;
case 0x0c0bd4e0u: goto P_0c0bd4e0;
case 0x0c0bd4e2u: goto P_0c0bd4e2;
case 0x0c0bd4e4u: goto P_0c0bd4e4;
case 0x0c0bd4e6u: goto P_0c0bd4e6;
case 0x0c0bd4e8u: goto P_0c0bd4e8;
case 0x0c0bd4eau: goto P_0c0bd4ea;
case 0x0c0bd4ecu: goto P_0c0bd4ec;
case 0x0c0bd4eeu: goto P_0c0bd4ee;
case 0x0c0bd4f0u: goto P_0c0bd4f0;
case 0x0c0bd4f2u: goto P_0c0bd4f2;
case 0x0c0bd4f4u: goto P_0c0bd4f4;
case 0x0c0bd4f6u: goto P_0c0bd4f6;
case 0x0c0bd4f8u: goto P_0c0bd4f8;
case 0x0c0bd4fau: goto P_0c0bd4fa;
case 0x0c0bd4fcu: goto P_0c0bd4fc;
case 0x0c0bd4feu: goto P_0c0bd4fe;
case 0x0c0bd500u: goto P_0c0bd500;
case 0x0c0bd502u: goto P_0c0bd502;
case 0x0c0bd504u: goto P_0c0bd504;
case 0x0c0bd506u: goto P_0c0bd506;
case 0x0c0bd508u: goto P_0c0bd508;
case 0x0c0bd50au: goto P_0c0bd50a;
case 0x0c0bd50cu: goto P_0c0bd50c;
case 0x0c0bd50eu: goto P_0c0bd50e;
case 0x0c0bd510u: goto P_0c0bd510;
case 0x0c0bd512u: goto P_0c0bd512;
case 0x0c0bd514u: goto P_0c0bd514;
case 0x0c0bd516u: goto P_0c0bd516;
case 0x0c0bd518u: goto P_0c0bd518;
case 0x0c0bd51au: goto P_0c0bd51a;
case 0x0c0bd51cu: goto P_0c0bd51c;
case 0x0c0bd51eu: goto P_0c0bd51e;
case 0x0c0bd520u: goto P_0c0bd520;
case 0x0c0bd522u: goto P_0c0bd522;
case 0x0c0bd524u: goto P_0c0bd524;
case 0x0c0bd526u: goto P_0c0bd526;
case 0x0c0bd528u: goto P_0c0bd528;
case 0x0c0bd52au: goto P_0c0bd52a;
case 0x0c0bd52cu: goto P_0c0bd52c;
case 0x0c0bd52eu: goto P_0c0bd52e;
case 0x0c0bd530u: goto P_0c0bd530;
case 0x0c0bd532u: goto P_0c0bd532;
case 0x0c0bd534u: goto P_0c0bd534;
case 0x0c0bd536u: goto P_0c0bd536;
case 0x0c0bd538u: goto P_0c0bd538;
case 0x0c0bd53au: goto P_0c0bd53a;
case 0x0c0bd53cu: goto P_0c0bd53c;
case 0x0c0bd53eu: goto P_0c0bd53e;
case 0x0c0bd540u: goto P_0c0bd540;
case 0x0c0bd542u: goto P_0c0bd542;
case 0x0c0bd544u: goto P_0c0bd544;
case 0x0c0bd546u: goto P_0c0bd546;
case 0x0c0bd548u: goto P_0c0bd548;
case 0x0c0bd54au: goto P_0c0bd54a;
case 0x0c0bd54cu: goto P_0c0bd54c;
case 0x0c0bd54eu: goto P_0c0bd54e;
case 0x0c0bd550u: goto P_0c0bd550;
case 0x0c0bd552u: goto P_0c0bd552;
case 0x0c0bd554u: goto P_0c0bd554;
case 0x0c0bd556u: goto P_0c0bd556;
case 0x0c0bd558u: goto P_0c0bd558;
case 0x0c0bd55au: goto P_0c0bd55a;
case 0x0c0bd55cu: goto P_0c0bd55c;
case 0x0c0bd55eu: goto P_0c0bd55e;
case 0x0c0bd560u: goto P_0c0bd560;
case 0x0c0bd562u: goto P_0c0bd562;
case 0x0c0bd564u: goto P_0c0bd564;
case 0x0c0bd566u: goto P_0c0bd566;
case 0x0c0bd568u: goto P_0c0bd568;
case 0x0c0bd56au: goto P_0c0bd56a;
case 0x0c0bd56cu: goto P_0c0bd56c;
case 0x0c0bd56eu: goto P_0c0bd56e;
case 0x0c0bd570u: goto P_0c0bd570;
case 0x0c0bd572u: goto P_0c0bd572;
case 0x0c0bd574u: goto P_0c0bd574;
case 0x0c0bd576u: goto P_0c0bd576;
case 0x0c0bd578u: goto P_0c0bd578;
case 0x0c0bd57au: goto P_0c0bd57a;
case 0x0c0bd57cu: goto P_0c0bd57c;
case 0x0c0bd57eu: goto P_0c0bd57e;
case 0x0c0bd580u: goto P_0c0bd580;
case 0x0c0bd582u: goto P_0c0bd582;
case 0x0c0bd584u: goto P_0c0bd584;
case 0x0c0bd586u: goto P_0c0bd586;
case 0x0c0bd588u: goto P_0c0bd588;
case 0x0c0bd58au: goto P_0c0bd58a;
case 0x0c0bd58cu: goto P_0c0bd58c;
case 0x0c0bd58eu: goto P_0c0bd58e;
case 0x0c0bd590u: goto P_0c0bd590;
case 0x0c0bd592u: goto P_0c0bd592;
case 0x0c0bd594u: goto P_0c0bd594;
case 0x0c0bd596u: goto P_0c0bd596;
case 0x0c0bd598u: goto P_0c0bd598;
case 0x0c0bd59au: goto P_0c0bd59a;
case 0x0c0bd59cu: goto P_0c0bd59c;
case 0x0c0bd59eu: goto P_0c0bd59e;
case 0x0c0bd5a0u: goto P_0c0bd5a0;
case 0x0c0bd5a2u: goto P_0c0bd5a2;
case 0x0c0bd5a4u: goto P_0c0bd5a4;
case 0x0c0bd5a6u: goto P_0c0bd5a6;
case 0x0c0bd5a8u: goto P_0c0bd5a8;
case 0x0c0bd5aau: goto P_0c0bd5aa;
case 0x0c0bd5acu: goto P_0c0bd5ac;
case 0x0c0bd5aeu: goto P_0c0bd5ae;
case 0x0c0bd5b0u: goto P_0c0bd5b0;
case 0x0c0bd5b2u: goto P_0c0bd5b2;
case 0x0c0bd5b4u: goto P_0c0bd5b4;
case 0x0c0bd5b6u: goto P_0c0bd5b6;
case 0x0c0bd5b8u: goto P_0c0bd5b8;
case 0x0c0bd5bau: goto P_0c0bd5ba;
case 0x0c0bd5bcu: goto P_0c0bd5bc;
case 0x0c0bd5beu: goto P_0c0bd5be;
case 0x0c0bd5c0u: goto P_0c0bd5c0;
case 0x0c0bd5c2u: goto P_0c0bd5c2;
case 0x0c0bd5c4u: goto P_0c0bd5c4;
case 0x0c0bd5c6u: goto P_0c0bd5c6;
case 0x0c0bd5c8u: goto P_0c0bd5c8;
case 0x0c0bd5cau: goto P_0c0bd5ca;
case 0x0c0bd5ccu: goto P_0c0bd5cc;
case 0x0c0bd5ceu: goto P_0c0bd5ce;
case 0x0c0bd5d0u: goto P_0c0bd5d0;
case 0x0c0bd5d2u: goto P_0c0bd5d2;
case 0x0c0bd5d4u: goto P_0c0bd5d4;
case 0x0c0bd5d6u: goto P_0c0bd5d6;
case 0x0c0bd5d8u: goto P_0c0bd5d8;
case 0x0c0bd5dau: goto P_0c0bd5da;
case 0x0c0bd5dcu: goto P_0c0bd5dc;
case 0x0c0bd5deu: goto P_0c0bd5de;
case 0x0c0bd5e0u: goto P_0c0bd5e0;
case 0x0c0bd5e2u: goto P_0c0bd5e2;
case 0x0c0bd5e4u: goto P_0c0bd5e4;
case 0x0c0bd5e6u: goto P_0c0bd5e6;
case 0x0c0bd5e8u: goto P_0c0bd5e8;
case 0x0c0bd5eau: goto P_0c0bd5ea;
case 0x0c0bd5ecu: goto P_0c0bd5ec;
case 0x0c0bd5eeu: goto P_0c0bd5ee;
case 0x0c0bd5f0u: goto P_0c0bd5f0;
case 0x0c0bd5f2u: goto P_0c0bd5f2;
case 0x0c0bd5f4u: goto P_0c0bd5f4;
case 0x0c0bd5f6u: goto P_0c0bd5f6;
case 0x0c0bd5f8u: goto P_0c0bd5f8;
case 0x0c0bd5fau: goto P_0c0bd5fa;
case 0x0c0bd5fcu: goto P_0c0bd5fc;
case 0x0c0bd5feu: goto P_0c0bd5fe;
case 0x0c0bd600u: goto P_0c0bd600;
case 0x0c0bd602u: goto P_0c0bd602;
case 0x0c0bd604u: goto P_0c0bd604;
case 0x0c0bd606u: goto P_0c0bd606;
case 0x0c0bd608u: goto P_0c0bd608;
case 0x0c0bd60au: goto P_0c0bd60a;
case 0x0c0bd60cu: goto P_0c0bd60c;
case 0x0c0bd60eu: goto P_0c0bd60e;
case 0x0c0bd610u: goto P_0c0bd610;
case 0x0c0bd612u: goto P_0c0bd612;
case 0x0c0bd614u: goto P_0c0bd614;
case 0x0c0bd616u: goto P_0c0bd616;
case 0x0c0bd618u: goto P_0c0bd618;
case 0x0c0bd61au: goto P_0c0bd61a;
case 0x0c0bd61cu: goto P_0c0bd61c;
case 0x0c0bd61eu: goto P_0c0bd61e;
case 0x0c0bd620u: goto P_0c0bd620;
case 0x0c0bd690u: goto P_0c0bd690;
case 0x0c0bd692u: goto P_0c0bd692;
case 0x0c0bd694u: goto P_0c0bd694;
case 0x0c0bd696u: goto P_0c0bd696;
case 0x0c0bd698u: goto P_0c0bd698;
case 0x0c0bd69au: goto P_0c0bd69a;
case 0x0c0bd69cu: goto P_0c0bd69c;
case 0x0c0bd69eu: goto P_0c0bd69e;
case 0x0c0bd6a0u: goto P_0c0bd6a0;
case 0x0c0bd6a2u: goto P_0c0bd6a2;
case 0x0c0bd6a4u: goto P_0c0bd6a4;
case 0x0c0bd6a6u: goto P_0c0bd6a6;
case 0x0c0bd6a8u: goto P_0c0bd6a8;
case 0x0c0bd6aau: goto P_0c0bd6aa;
case 0x0c0bd6acu: goto P_0c0bd6ac;
case 0x0c0bd6aeu: goto P_0c0bd6ae;
case 0x0c0bd6b0u: goto P_0c0bd6b0;
case 0x0c0bd6b2u: goto P_0c0bd6b2;
case 0x0c0bd6b4u: goto P_0c0bd6b4;
case 0x0c0bd6b6u: goto P_0c0bd6b6;
case 0x0c0bd6b8u: goto P_0c0bd6b8;
case 0x0c0bd6bau: goto P_0c0bd6ba;
case 0x0c0bd6bcu: goto P_0c0bd6bc;
case 0x0c0bd6beu: goto P_0c0bd6be;
case 0x0c0bd6c0u: goto P_0c0bd6c0;
case 0x0c0bd6c2u: goto P_0c0bd6c2;
case 0x0c0bd6c4u: goto P_0c0bd6c4;
case 0x0c0bd6c6u: goto P_0c0bd6c6;
case 0x0c0bd6c8u: goto P_0c0bd6c8;
case 0x0c0bd6cau: goto P_0c0bd6ca;
case 0x0c0bd6ccu: goto P_0c0bd6cc;
case 0x0c0bd6ceu: goto P_0c0bd6ce;
case 0x0c0bd6d0u: goto P_0c0bd6d0;
case 0x0c0bd6d2u: goto P_0c0bd6d2;
case 0x0c0bd6d4u: goto P_0c0bd6d4;
case 0x0c0bd6d6u: goto P_0c0bd6d6;
case 0x0c0bd6d8u: goto P_0c0bd6d8;
case 0x0c0bd6dau: goto P_0c0bd6da;
case 0x0c0bd6dcu: goto P_0c0bd6dc;
case 0x0c0bd6deu: goto P_0c0bd6de;
case 0x0c0bd6e0u: goto P_0c0bd6e0;
case 0x0c0bd6e2u: goto P_0c0bd6e2;
case 0x0c0bd6e4u: goto P_0c0bd6e4;
case 0x0c0bd6e6u: goto P_0c0bd6e6;
case 0x0c0bd6e8u: goto P_0c0bd6e8;
case 0x0c0bd6eau: goto P_0c0bd6ea;
case 0x0c0bd6ecu: goto P_0c0bd6ec;
case 0x0c0bd6eeu: goto P_0c0bd6ee;
case 0x0c0bd6f0u: goto P_0c0bd6f0;
case 0x0c0bd6f2u: goto P_0c0bd6f2;
case 0x0c0bd6f4u: goto P_0c0bd6f4;
case 0x0c0bd6f6u: goto P_0c0bd6f6;
case 0x0c0bd6f8u: goto P_0c0bd6f8;
case 0x0c0bd6fau: goto P_0c0bd6fa;
case 0x0c0bd6fcu: goto P_0c0bd6fc;
case 0x0c0bd6feu: goto P_0c0bd6fe;
case 0x0c0bd700u: goto P_0c0bd700;
case 0x0c0bd702u: goto P_0c0bd702;
case 0x0c0bd704u: goto P_0c0bd704;
case 0x0c0bd706u: goto P_0c0bd706;
case 0x0c0bd708u: goto P_0c0bd708;
case 0x0c0bd70au: goto P_0c0bd70a;
case 0x0c0bd70cu: goto P_0c0bd70c;
case 0x0c0bd70eu: goto P_0c0bd70e;
case 0x0c0bd710u: goto P_0c0bd710;
case 0x0c0bd712u: goto P_0c0bd712;
case 0x0c0bd714u: goto P_0c0bd714;
case 0x0c0bd716u: goto P_0c0bd716;
case 0x0c0bd718u: goto P_0c0bd718;
case 0x0c0bd71au: goto P_0c0bd71a;
case 0x0c0bd71cu: goto P_0c0bd71c;
case 0x0c0bd71eu: goto P_0c0bd71e;
case 0x0c0bd720u: goto P_0c0bd720;
case 0x0c0bd722u: goto P_0c0bd722;
case 0x0c0bd724u: goto P_0c0bd724;
case 0x0c0bd726u: goto P_0c0bd726;
case 0x0c0bd728u: goto P_0c0bd728;
case 0x0c0bd72au: goto P_0c0bd72a;
case 0x0c0bd72cu: goto P_0c0bd72c;
case 0x0c0bd72eu: goto P_0c0bd72e;
case 0x0c0bd730u: goto P_0c0bd730;
case 0x0c0bd732u: goto P_0c0bd732;
case 0x0c0bd734u: goto P_0c0bd734;
case 0x0c0bd736u: goto P_0c0bd736;
case 0x0c0bd738u: goto P_0c0bd738;
case 0x0c0bd73au: goto P_0c0bd73a;
case 0x0c0bd73cu: goto P_0c0bd73c;
case 0x0c0bd73eu: goto P_0c0bd73e;
case 0x0c0bd740u: goto P_0c0bd740;
case 0x0c0bd742u: goto P_0c0bd742;
case 0x0c0bd744u: goto P_0c0bd744;
case 0x0c0bd746u: goto P_0c0bd746;
case 0x0c0bd748u: goto P_0c0bd748;
case 0x0c0bd74au: goto P_0c0bd74a;
case 0x0c0bd74cu: goto P_0c0bd74c;
case 0x0c0bd74eu: goto P_0c0bd74e;
case 0x0c0bd750u: goto P_0c0bd750;
case 0x0c0bd752u: goto P_0c0bd752;
case 0x0c0bd754u: goto P_0c0bd754;
case 0x0c0bd756u: goto P_0c0bd756;
case 0x0c0bd758u: goto P_0c0bd758;
case 0x0c0bd75au: goto P_0c0bd75a;
case 0x0c0bd75cu: goto P_0c0bd75c;
case 0x0c0bd75eu: goto P_0c0bd75e;
case 0x0c0bd760u: goto P_0c0bd760;
case 0x0c0bd762u: goto P_0c0bd762;
case 0x0c0bd764u: goto P_0c0bd764;
case 0x0c0bd766u: goto P_0c0bd766;
case 0x0c0bd768u: goto P_0c0bd768;
case 0x0c0bd76au: goto P_0c0bd76a;
case 0x0c0bd76cu: goto P_0c0bd76c;
case 0x0c0bd76eu: goto P_0c0bd76e;
case 0x0c0bd770u: goto P_0c0bd770;
case 0x0c0bd772u: goto P_0c0bd772;
case 0x0c0bd774u: goto P_0c0bd774;
case 0x0c0bd776u: goto P_0c0bd776;
case 0x0c0bd778u: goto P_0c0bd778;
case 0x0c0bd77au: goto P_0c0bd77a;
case 0x0c0bd77cu: goto P_0c0bd77c;
case 0x0c0bd77eu: goto P_0c0bd77e;
case 0x0c0bd780u: goto P_0c0bd780;
case 0x0c0bd782u: goto P_0c0bd782;
case 0x0c0bd784u: goto P_0c0bd784;
case 0x0c0bd786u: goto P_0c0bd786;
case 0x0c0bd788u: goto P_0c0bd788;
case 0x0c0bd78au: goto P_0c0bd78a;
case 0x0c0bd78cu: goto P_0c0bd78c;
case 0x0c0bd78eu: goto P_0c0bd78e;
case 0x0c0bd790u: goto P_0c0bd790;
case 0x0c0bd792u: goto P_0c0bd792;
case 0x0c0bd794u: goto P_0c0bd794;
case 0x0c0bd796u: goto P_0c0bd796;
case 0x0c0bd798u: goto P_0c0bd798;
case 0x0c0bd79au: goto P_0c0bd79a;
case 0x0c0bd79cu: goto P_0c0bd79c;
case 0x0c0bd79eu: goto P_0c0bd79e;
case 0x0c0bd7a0u: goto P_0c0bd7a0;
case 0x0c0bd7a2u: goto P_0c0bd7a2;
case 0x0c0bd7a4u: goto P_0c0bd7a4;
case 0x0c0bd7a6u: goto P_0c0bd7a6;
case 0x0c0bd7a8u: goto P_0c0bd7a8;
case 0x0c0bd7aau: goto P_0c0bd7aa;
case 0x0c0bd7acu: goto P_0c0bd7ac;
case 0x0c0bd7aeu: goto P_0c0bd7ae;
case 0x0c0bd7b0u: goto P_0c0bd7b0;
case 0x0c0bd7b2u: goto P_0c0bd7b2;
case 0x0c0bd7b4u: goto P_0c0bd7b4;
case 0x0c0bd7b6u: goto P_0c0bd7b6;
case 0x0c0bd7b8u: goto P_0c0bd7b8;
case 0x0c0bd7bau: goto P_0c0bd7ba;
case 0x0c0bd7bcu: goto P_0c0bd7bc;
case 0x0c0bd7beu: goto P_0c0bd7be;
case 0x0c0bd7c0u: goto P_0c0bd7c0;
case 0x0c0bd7c2u: goto P_0c0bd7c2;
case 0x0c0bd7c4u: goto P_0c0bd7c4;
case 0x0c0bd7c6u: goto P_0c0bd7c6;
case 0x0c0bd7c8u: goto P_0c0bd7c8;
case 0x0c0bd7cau: goto P_0c0bd7ca;
case 0x0c0bd7ccu: goto P_0c0bd7cc;
case 0x0c0bd7ceu: goto P_0c0bd7ce;
case 0x0c0bd7d0u: goto P_0c0bd7d0;
case 0x0c0bd7d2u: goto P_0c0bd7d2;
case 0x0c0bd7d4u: goto P_0c0bd7d4;
case 0x0c0bd7d6u: goto P_0c0bd7d6;
case 0x0c0bd7d8u: goto P_0c0bd7d8;
case 0x0c0bd7dau: goto P_0c0bd7da;
case 0x0c0bd7dcu: goto P_0c0bd7dc;
case 0x0c0bd7deu: goto P_0c0bd7de;
case 0x0c0bd7e0u: goto P_0c0bd7e0;
case 0x0c0bd7e2u: goto P_0c0bd7e2;
case 0x0c0bd7e4u: goto P_0c0bd7e4;
case 0x0c0bd7e6u: goto P_0c0bd7e6;
case 0x0c0bd7e8u: goto P_0c0bd7e8;
case 0x0c0bd862u: goto P_0c0bd862;
case 0x0c0bd864u: goto P_0c0bd864;
case 0x0c0bd866u: goto P_0c0bd866;
case 0x0c0bd868u: goto P_0c0bd868;
case 0x0c0bd86au: goto P_0c0bd86a;
case 0x0c0bd86cu: goto P_0c0bd86c;
case 0x0c0bd86eu: goto P_0c0bd86e;
case 0x0c0bd870u: goto P_0c0bd870;
case 0x0c0bd872u: goto P_0c0bd872;
case 0x0c0bd874u: goto P_0c0bd874;
case 0x0c0bd876u: goto P_0c0bd876;
case 0x0c0bd878u: goto P_0c0bd878;
case 0x0c0bd87au: goto P_0c0bd87a;
case 0x0c0bd87cu: goto P_0c0bd87c;
case 0x0c0bd87eu: goto P_0c0bd87e;
case 0x0c0bd880u: goto P_0c0bd880;
case 0x0c0bd882u: goto P_0c0bd882;
case 0x0c0bd884u: goto P_0c0bd884;
case 0x0c0bd886u: goto P_0c0bd886;
case 0x0c0bd888u: goto P_0c0bd888;
case 0x0c0bd88au: goto P_0c0bd88a;
case 0x0c0bd88cu: goto P_0c0bd88c;
case 0x0c0bd88eu: goto P_0c0bd88e;
case 0x0c0bd890u: goto P_0c0bd890;
case 0x0c0bd892u: goto P_0c0bd892;
case 0x0c0bd894u: goto P_0c0bd894;
case 0x0c0bd896u: goto P_0c0bd896;
case 0x0c0bd898u: goto P_0c0bd898;
case 0x0c0bd89au: goto P_0c0bd89a;
case 0x0c0bd89cu: goto P_0c0bd89c;
case 0x0c0bd89eu: goto P_0c0bd89e;
case 0x0c0bd8a0u: goto P_0c0bd8a0;
case 0x0c0bd8a2u: goto P_0c0bd8a2;
case 0x0c0bd8a4u: goto P_0c0bd8a4;
case 0x0c0bd8a6u: goto P_0c0bd8a6;
case 0x0c0bd8a8u: goto P_0c0bd8a8;
case 0x0c0bd8aau: goto P_0c0bd8aa;
case 0x0c0bd8acu: goto P_0c0bd8ac;
case 0x0c0bd8aeu: goto P_0c0bd8ae;
case 0x0c0bd8b0u: goto P_0c0bd8b0;
case 0x0c0bd8b2u: goto P_0c0bd8b2;
case 0x0c0bd8b4u: goto P_0c0bd8b4;
case 0x0c0bd8b6u: goto P_0c0bd8b6;
case 0x0c0bd8b8u: goto P_0c0bd8b8;
case 0x0c0bd8bau: goto P_0c0bd8ba;
case 0x0c0bd8bcu: goto P_0c0bd8bc;
case 0x0c0bd8beu: goto P_0c0bd8be;
case 0x0c0bd8c0u: goto P_0c0bd8c0;
case 0x0c0bd8c2u: goto P_0c0bd8c2;
case 0x0c0bd8c4u: goto P_0c0bd8c4;
case 0x0c0bd8c6u: goto P_0c0bd8c6;
case 0x0c0bd8c8u: goto P_0c0bd8c8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0bd4be: /* original 2fe6, guest PC 0x0c0bd4be */
if(!s->budget--) { s->failed_pc=0x0c0bd4beu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bd4c0;
P_0c0bd4c0: /* original 2fd6, guest PC 0x0c0bd4c0 */
if(!s->budget--) { s->failed_pc=0x0c0bd4c0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bd4c2;
P_0c0bd4c2: /* original 2fc6, guest PC 0x0c0bd4c2 */
if(!s->budget--) { s->failed_pc=0x0c0bd4c2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bd4c4;
P_0c0bd4c4: /* original 2fb6, guest PC 0x0c0bd4c4 */
if(!s->budget--) { s->failed_pc=0x0c0bd4c4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bd4c6;
P_0c0bd4c6: /* original 2fa6, guest PC 0x0c0bd4c6 */
if(!s->budget--) { s->failed_pc=0x0c0bd4c6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bd4c8;
P_0c0bd4c8: /* original 2f96, guest PC 0x0c0bd4c8 */
if(!s->budget--) { s->failed_pc=0x0c0bd4c8u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bd4ca;
P_0c0bd4ca: /* original 4f22, guest PC 0x0c0bd4ca */
if(!s->budget--) { s->failed_pc=0x0c0bd4cau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0bd4cc;
P_0c0bd4cc: /* original 5d44, guest PC 0x0c0bd4cc */
if(!s->budget--) { s->failed_pc=0x0c0bd4ccu; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0bd4ce;
P_0c0bd4ce: /* original 94a8, guest PC 0x0c0bd4ce */
if(!s->budget--) { s->failed_pc=0x0c0bd4ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd622u,2);
goto P_0c0bd4d0;
P_0c0bd4d0: /* original de6e, guest PC 0x0c0bd4d0 */
if(!s->budget--) { s->failed_pc=0x0c0bd4d0u; return 0; }
r[14]=read(ram,0x0c0bd68cu,4);
goto P_0c0bd4d2;
P_0c0bd4d2: /* original 7ff8, guest PC 0x0c0bd4d2 */
if(!s->budget--) { s->failed_pc=0x0c0bd4d2u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0bd4d4;
P_0c0bd4d4: /* original 4e0b, guest PC 0x0c0bd4d4 */
if(!s->budget--) { s->failed_pc=0x0c0bd4d4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd4d8u;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd4d8u) { target=s->pc; goto dispatch; }
goto P_0c0bd4d8;
P_0c0bd4d6: /* original 65d2, guest PC 0x0c0bd4d6 */
if(!s->budget--) { s->failed_pc=0x0c0bd4d6u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0bd4d8;
P_0c0bd4d8: /* original 94a4, guest PC 0x0c0bd4d8 */
if(!s->budget--) { s->failed_pc=0x0c0bd4d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd624u,2);
goto P_0c0bd4da;
P_0c0bd4da: /* original 4e0b, guest PC 0x0c0bd4da */
if(!s->budget--) { s->failed_pc=0x0c0bd4dau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd4deu;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd4deu) { target=s->pc; goto dispatch; }
goto P_0c0bd4de;
P_0c0bd4dc: /* original 55d1, guest PC 0x0c0bd4dc */
if(!s->budget--) { s->failed_pc=0x0c0bd4dcu; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0bd4de;
P_0c0bd4de: /* original 94a2, guest PC 0x0c0bd4de */
if(!s->budget--) { s->failed_pc=0x0c0bd4deu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd626u,2);
goto P_0c0bd4e0;
P_0c0bd4e0: /* original 4e0b, guest PC 0x0c0bd4e0 */
if(!s->budget--) { s->failed_pc=0x0c0bd4e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd4e4u;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd4e4u) { target=s->pc; goto dispatch; }
goto P_0c0bd4e4;
P_0c0bd4e2: /* original 55d2, guest PC 0x0c0bd4e2 */
if(!s->budget--) { s->failed_pc=0x0c0bd4e2u; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0bd4e4;
P_0c0bd4e4: /* original 94a0, guest PC 0x0c0bd4e4 */
if(!s->budget--) { s->failed_pc=0x0c0bd4e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd628u,2);
goto P_0c0bd4e6;
P_0c0bd4e6: /* original 4e0b, guest PC 0x0c0bd4e6 */
if(!s->budget--) { s->failed_pc=0x0c0bd4e6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd4eau;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd4eau) { target=s->pc; goto dispatch; }
goto P_0c0bd4ea;
P_0c0bd4e8: /* original 55d3, guest PC 0x0c0bd4e8 */
if(!s->budget--) { s->failed_pc=0x0c0bd4e8u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0bd4ea;
P_0c0bd4ea: /* original 949e, guest PC 0x0c0bd4ea */
if(!s->budget--) { s->failed_pc=0x0c0bd4eau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd62au,2);
goto P_0c0bd4ec;
P_0c0bd4ec: /* original 4e0b, guest PC 0x0c0bd4ec */
if(!s->budget--) { s->failed_pc=0x0c0bd4ecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd4f0u;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd4f0u) { target=s->pc; goto dispatch; }
goto P_0c0bd4f0;
P_0c0bd4ee: /* original 55d4, guest PC 0x0c0bd4ee */
if(!s->budget--) { s->failed_pc=0x0c0bd4eeu; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0bd4f0;
P_0c0bd4f0: /* original 949c, guest PC 0x0c0bd4f0 */
if(!s->budget--) { s->failed_pc=0x0c0bd4f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd62cu,2);
goto P_0c0bd4f2;
P_0c0bd4f2: /* original 4e0b, guest PC 0x0c0bd4f2 */
if(!s->budget--) { s->failed_pc=0x0c0bd4f2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd4f6u;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd4f6u) { target=s->pc; goto dispatch; }
goto P_0c0bd4f6;
P_0c0bd4f4: /* original 55d5, guest PC 0x0c0bd4f4 */
if(!s->budget--) { s->failed_pc=0x0c0bd4f4u; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0bd4f6;
P_0c0bd4f6: /* original 949a, guest PC 0x0c0bd4f6 */
if(!s->budget--) { s->failed_pc=0x0c0bd4f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd62eu,2);
goto P_0c0bd4f8;
P_0c0bd4f8: /* original 4e0b, guest PC 0x0c0bd4f8 */
if(!s->budget--) { s->failed_pc=0x0c0bd4f8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd4fcu;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd4fcu) { target=s->pc; goto dispatch; }
goto P_0c0bd4fc;
P_0c0bd4fa: /* original 55d6, guest PC 0x0c0bd4fa */
if(!s->budget--) { s->failed_pc=0x0c0bd4fau; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0bd4fc;
P_0c0bd4fc: /* original 9498, guest PC 0x0c0bd4fc */
if(!s->budget--) { s->failed_pc=0x0c0bd4fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd630u,2);
goto P_0c0bd4fe;
P_0c0bd4fe: /* original 4e0b, guest PC 0x0c0bd4fe */
if(!s->budget--) { s->failed_pc=0x0c0bd4feu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd502u;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd502u) { target=s->pc; goto dispatch; }
goto P_0c0bd502;
P_0c0bd500: /* original 55d7, guest PC 0x0c0bd500 */
if(!s->budget--) { s->failed_pc=0x0c0bd500u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0bd502;
P_0c0bd502: /* original 9496, guest PC 0x0c0bd502 */
if(!s->budget--) { s->failed_pc=0x0c0bd502u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd632u,2);
goto P_0c0bd504;
P_0c0bd504: /* original 4e0b, guest PC 0x0c0bd504 */
if(!s->budget--) { s->failed_pc=0x0c0bd504u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd508u;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd508u) { target=s->pc; goto dispatch; }
goto P_0c0bd508;
P_0c0bd506: /* original 55d8, guest PC 0x0c0bd506 */
if(!s->budget--) { s->failed_pc=0x0c0bd506u; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0bd508;
P_0c0bd508: /* original 9494, guest PC 0x0c0bd508 */
if(!s->budget--) { s->failed_pc=0x0c0bd508u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd634u,2);
goto P_0c0bd50a;
P_0c0bd50a: /* original 4e0b, guest PC 0x0c0bd50a */
if(!s->budget--) { s->failed_pc=0x0c0bd50au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd50eu;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd50eu) { target=s->pc; goto dispatch; }
goto P_0c0bd50e;
P_0c0bd50c: /* original 55d9, guest PC 0x0c0bd50c */
if(!s->budget--) { s->failed_pc=0x0c0bd50cu; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0bd50e;
P_0c0bd50e: /* original 9492, guest PC 0x0c0bd50e */
if(!s->budget--) { s->failed_pc=0x0c0bd50eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd636u,2);
goto P_0c0bd510;
P_0c0bd510: /* original 4e0b, guest PC 0x0c0bd510 */
if(!s->budget--) { s->failed_pc=0x0c0bd510u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd514u;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd514u) { target=s->pc; goto dispatch; }
goto P_0c0bd514;
P_0c0bd512: /* original 55da, guest PC 0x0c0bd512 */
if(!s->budget--) { s->failed_pc=0x0c0bd512u; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0bd514;
P_0c0bd514: /* original 9490, guest PC 0x0c0bd514 */
if(!s->budget--) { s->failed_pc=0x0c0bd514u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd638u,2);
goto P_0c0bd516;
P_0c0bd516: /* original 4e0b, guest PC 0x0c0bd516 */
if(!s->budget--) { s->failed_pc=0x0c0bd516u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd51au;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd51au) { target=s->pc; goto dispatch; }
goto P_0c0bd51a;
P_0c0bd518: /* original 55db, guest PC 0x0c0bd518 */
if(!s->budget--) { s->failed_pc=0x0c0bd518u; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0bd51a;
P_0c0bd51a: /* original 948e, guest PC 0x0c0bd51a */
if(!s->budget--) { s->failed_pc=0x0c0bd51au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd63au,2);
goto P_0c0bd51c;
P_0c0bd51c: /* original 4e0b, guest PC 0x0c0bd51c */
if(!s->budget--) { s->failed_pc=0x0c0bd51cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd520u;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd520u) { target=s->pc; goto dispatch; }
goto P_0c0bd520;
P_0c0bd51e: /* original 55dc, guest PC 0x0c0bd51e */
if(!s->budget--) { s->failed_pc=0x0c0bd51eu; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0bd520;
P_0c0bd520: /* original 948c, guest PC 0x0c0bd520 */
if(!s->budget--) { s->failed_pc=0x0c0bd520u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd63cu,2);
goto P_0c0bd522;
P_0c0bd522: /* original 4e0b, guest PC 0x0c0bd522 */
if(!s->budget--) { s->failed_pc=0x0c0bd522u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd526u;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd526u) { target=s->pc; goto dispatch; }
goto P_0c0bd526;
P_0c0bd524: /* original 55dd, guest PC 0x0c0bd524 */
if(!s->budget--) { s->failed_pc=0x0c0bd524u; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0bd526;
P_0c0bd526: /* original 948a, guest PC 0x0c0bd526 */
if(!s->budget--) { s->failed_pc=0x0c0bd526u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd63eu,2);
goto P_0c0bd528;
P_0c0bd528: /* original 4e0b, guest PC 0x0c0bd528 */
if(!s->budget--) { s->failed_pc=0x0c0bd528u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd52cu;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd52cu) { target=s->pc; goto dispatch; }
goto P_0c0bd52c;
P_0c0bd52a: /* original 55de, guest PC 0x0c0bd52a */
if(!s->budget--) { s->failed_pc=0x0c0bd52au; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0bd52c;
P_0c0bd52c: /* original 9488, guest PC 0x0c0bd52c */
if(!s->budget--) { s->failed_pc=0x0c0bd52cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd640u,2);
goto P_0c0bd52e;
P_0c0bd52e: /* original 4e0b, guest PC 0x0c0bd52e */
if(!s->budget--) { s->failed_pc=0x0c0bd52eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd532u;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd532u) { target=s->pc; goto dispatch; }
goto P_0c0bd532;
P_0c0bd530: /* original 55df, guest PC 0x0c0bd530 */
if(!s->budget--) { s->failed_pc=0x0c0bd530u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0bd532;
P_0c0bd532: /* original 9486, guest PC 0x0c0bd532 */
if(!s->budget--) { s->failed_pc=0x0c0bd532u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd642u,2);
goto P_0c0bd534;
P_0c0bd534: /* original e040, guest PC 0x0c0bd534 */
if(!s->budget--) { s->failed_pc=0x0c0bd534u; return 0; }
r[0]=0x00000040u;
goto P_0c0bd536;
P_0c0bd536: /* original 4e0b, guest PC 0x0c0bd536 */
if(!s->budget--) { s->failed_pc=0x0c0bd536u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd53au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd53au) { target=s->pc; goto dispatch; }
goto P_0c0bd53a;
P_0c0bd538: /* original 05de, guest PC 0x0c0bd538 */
if(!s->budget--) { s->failed_pc=0x0c0bd538u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd53a;
P_0c0bd53a: /* original 9483, guest PC 0x0c0bd53a */
if(!s->budget--) { s->failed_pc=0x0c0bd53au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd644u,2);
goto P_0c0bd53c;
P_0c0bd53c: /* original e044, guest PC 0x0c0bd53c */
if(!s->budget--) { s->failed_pc=0x0c0bd53cu; return 0; }
r[0]=0x00000044u;
goto P_0c0bd53e;
P_0c0bd53e: /* original 4e0b, guest PC 0x0c0bd53e */
if(!s->budget--) { s->failed_pc=0x0c0bd53eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd542u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd542u) { target=s->pc; goto dispatch; }
goto P_0c0bd542;
P_0c0bd540: /* original 05de, guest PC 0x0c0bd540 */
if(!s->budget--) { s->failed_pc=0x0c0bd540u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd542;
P_0c0bd542: /* original 9480, guest PC 0x0c0bd542 */
if(!s->budget--) { s->failed_pc=0x0c0bd542u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd646u,2);
goto P_0c0bd544;
P_0c0bd544: /* original e048, guest PC 0x0c0bd544 */
if(!s->budget--) { s->failed_pc=0x0c0bd544u; return 0; }
r[0]=0x00000048u;
goto P_0c0bd546;
P_0c0bd546: /* original 4e0b, guest PC 0x0c0bd546 */
if(!s->budget--) { s->failed_pc=0x0c0bd546u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd54au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd54au) { target=s->pc; goto dispatch; }
goto P_0c0bd54a;
P_0c0bd548: /* original 05de, guest PC 0x0c0bd548 */
if(!s->budget--) { s->failed_pc=0x0c0bd548u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd54a;
P_0c0bd54a: /* original 947d, guest PC 0x0c0bd54a */
if(!s->budget--) { s->failed_pc=0x0c0bd54au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd648u,2);
goto P_0c0bd54c;
P_0c0bd54c: /* original e04c, guest PC 0x0c0bd54c */
if(!s->budget--) { s->failed_pc=0x0c0bd54cu; return 0; }
r[0]=0x0000004cu;
goto P_0c0bd54e;
P_0c0bd54e: /* original 4e0b, guest PC 0x0c0bd54e */
if(!s->budget--) { s->failed_pc=0x0c0bd54eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd552u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd552u) { target=s->pc; goto dispatch; }
goto P_0c0bd552;
P_0c0bd550: /* original 05de, guest PC 0x0c0bd550 */
if(!s->budget--) { s->failed_pc=0x0c0bd550u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd552;
P_0c0bd552: /* original 947a, guest PC 0x0c0bd552 */
if(!s->budget--) { s->failed_pc=0x0c0bd552u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd64au,2);
goto P_0c0bd554;
P_0c0bd554: /* original e050, guest PC 0x0c0bd554 */
if(!s->budget--) { s->failed_pc=0x0c0bd554u; return 0; }
r[0]=0x00000050u;
goto P_0c0bd556;
P_0c0bd556: /* original 4e0b, guest PC 0x0c0bd556 */
if(!s->budget--) { s->failed_pc=0x0c0bd556u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd55au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd55au) { target=s->pc; goto dispatch; }
goto P_0c0bd55a;
P_0c0bd558: /* original 05de, guest PC 0x0c0bd558 */
if(!s->budget--) { s->failed_pc=0x0c0bd558u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd55a;
P_0c0bd55a: /* original 9477, guest PC 0x0c0bd55a */
if(!s->budget--) { s->failed_pc=0x0c0bd55au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd64cu,2);
goto P_0c0bd55c;
P_0c0bd55c: /* original e054, guest PC 0x0c0bd55c */
if(!s->budget--) { s->failed_pc=0x0c0bd55cu; return 0; }
r[0]=0x00000054u;
goto P_0c0bd55e;
P_0c0bd55e: /* original 4e0b, guest PC 0x0c0bd55e */
if(!s->budget--) { s->failed_pc=0x0c0bd55eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd562u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd562u) { target=s->pc; goto dispatch; }
goto P_0c0bd562;
P_0c0bd560: /* original 05de, guest PC 0x0c0bd560 */
if(!s->budget--) { s->failed_pc=0x0c0bd560u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd562;
P_0c0bd562: /* original 9474, guest PC 0x0c0bd562 */
if(!s->budget--) { s->failed_pc=0x0c0bd562u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd64eu,2);
goto P_0c0bd564;
P_0c0bd564: /* original e058, guest PC 0x0c0bd564 */
if(!s->budget--) { s->failed_pc=0x0c0bd564u; return 0; }
r[0]=0x00000058u;
goto P_0c0bd566;
P_0c0bd566: /* original 4e0b, guest PC 0x0c0bd566 */
if(!s->budget--) { s->failed_pc=0x0c0bd566u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd56au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd56au) { target=s->pc; goto dispatch; }
goto P_0c0bd56a;
P_0c0bd568: /* original 05de, guest PC 0x0c0bd568 */
if(!s->budget--) { s->failed_pc=0x0c0bd568u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd56a;
P_0c0bd56a: /* original 9471, guest PC 0x0c0bd56a */
if(!s->budget--) { s->failed_pc=0x0c0bd56au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd650u,2);
goto P_0c0bd56c;
P_0c0bd56c: /* original e05c, guest PC 0x0c0bd56c */
if(!s->budget--) { s->failed_pc=0x0c0bd56cu; return 0; }
r[0]=0x0000005cu;
goto P_0c0bd56e;
P_0c0bd56e: /* original 4e0b, guest PC 0x0c0bd56e */
if(!s->budget--) { s->failed_pc=0x0c0bd56eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd572u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd572u) { target=s->pc; goto dispatch; }
goto P_0c0bd572;
P_0c0bd570: /* original 05de, guest PC 0x0c0bd570 */
if(!s->budget--) { s->failed_pc=0x0c0bd570u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd572;
P_0c0bd572: /* original 946e, guest PC 0x0c0bd572 */
if(!s->budget--) { s->failed_pc=0x0c0bd572u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd652u,2);
goto P_0c0bd574;
P_0c0bd574: /* original e060, guest PC 0x0c0bd574 */
if(!s->budget--) { s->failed_pc=0x0c0bd574u; return 0; }
r[0]=0x00000060u;
goto P_0c0bd576;
P_0c0bd576: /* original 4e0b, guest PC 0x0c0bd576 */
if(!s->budget--) { s->failed_pc=0x0c0bd576u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd57au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd57au) { target=s->pc; goto dispatch; }
goto P_0c0bd57a;
P_0c0bd578: /* original 05de, guest PC 0x0c0bd578 */
if(!s->budget--) { s->failed_pc=0x0c0bd578u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd57a;
P_0c0bd57a: /* original 946b, guest PC 0x0c0bd57a */
if(!s->budget--) { s->failed_pc=0x0c0bd57au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd654u,2);
goto P_0c0bd57c;
P_0c0bd57c: /* original e064, guest PC 0x0c0bd57c */
if(!s->budget--) { s->failed_pc=0x0c0bd57cu; return 0; }
r[0]=0x00000064u;
goto P_0c0bd57e;
P_0c0bd57e: /* original 4e0b, guest PC 0x0c0bd57e */
if(!s->budget--) { s->failed_pc=0x0c0bd57eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd582u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd582u) { target=s->pc; goto dispatch; }
goto P_0c0bd582;
P_0c0bd580: /* original 05de, guest PC 0x0c0bd580 */
if(!s->budget--) { s->failed_pc=0x0c0bd580u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd582;
P_0c0bd582: /* original 9468, guest PC 0x0c0bd582 */
if(!s->budget--) { s->failed_pc=0x0c0bd582u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd656u,2);
goto P_0c0bd584;
P_0c0bd584: /* original e068, guest PC 0x0c0bd584 */
if(!s->budget--) { s->failed_pc=0x0c0bd584u; return 0; }
r[0]=0x00000068u;
goto P_0c0bd586;
P_0c0bd586: /* original 4e0b, guest PC 0x0c0bd586 */
if(!s->budget--) { s->failed_pc=0x0c0bd586u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd58au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd58au) { target=s->pc; goto dispatch; }
goto P_0c0bd58a;
P_0c0bd588: /* original 05de, guest PC 0x0c0bd588 */
if(!s->budget--) { s->failed_pc=0x0c0bd588u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd58a;
P_0c0bd58a: /* original 9465, guest PC 0x0c0bd58a */
if(!s->budget--) { s->failed_pc=0x0c0bd58au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd658u,2);
goto P_0c0bd58c;
P_0c0bd58c: /* original e06c, guest PC 0x0c0bd58c */
if(!s->budget--) { s->failed_pc=0x0c0bd58cu; return 0; }
r[0]=0x0000006cu;
goto P_0c0bd58e;
P_0c0bd58e: /* original 4e0b, guest PC 0x0c0bd58e */
if(!s->budget--) { s->failed_pc=0x0c0bd58eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd592u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd592u) { target=s->pc; goto dispatch; }
goto P_0c0bd592;
P_0c0bd590: /* original 05de, guest PC 0x0c0bd590 */
if(!s->budget--) { s->failed_pc=0x0c0bd590u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd592;
P_0c0bd592: /* original 9462, guest PC 0x0c0bd592 */
if(!s->budget--) { s->failed_pc=0x0c0bd592u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd65au,2);
goto P_0c0bd594;
P_0c0bd594: /* original e070, guest PC 0x0c0bd594 */
if(!s->budget--) { s->failed_pc=0x0c0bd594u; return 0; }
r[0]=0x00000070u;
goto P_0c0bd596;
P_0c0bd596: /* original 4e0b, guest PC 0x0c0bd596 */
if(!s->budget--) { s->failed_pc=0x0c0bd596u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd59au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd59au) { target=s->pc; goto dispatch; }
goto P_0c0bd59a;
P_0c0bd598: /* original 05de, guest PC 0x0c0bd598 */
if(!s->budget--) { s->failed_pc=0x0c0bd598u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd59a;
P_0c0bd59a: /* original 945f, guest PC 0x0c0bd59a */
if(!s->budget--) { s->failed_pc=0x0c0bd59au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd65cu,2);
goto P_0c0bd59c;
P_0c0bd59c: /* original e074, guest PC 0x0c0bd59c */
if(!s->budget--) { s->failed_pc=0x0c0bd59cu; return 0; }
r[0]=0x00000074u;
goto P_0c0bd59e;
P_0c0bd59e: /* original 4e0b, guest PC 0x0c0bd59e */
if(!s->budget--) { s->failed_pc=0x0c0bd59eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd5a2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd5a2u) { target=s->pc; goto dispatch; }
goto P_0c0bd5a2;
P_0c0bd5a0: /* original 05de, guest PC 0x0c0bd5a0 */
if(!s->budget--) { s->failed_pc=0x0c0bd5a0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd5a2;
P_0c0bd5a2: /* original 945c, guest PC 0x0c0bd5a2 */
if(!s->budget--) { s->failed_pc=0x0c0bd5a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd65eu,2);
goto P_0c0bd5a4;
P_0c0bd5a4: /* original e078, guest PC 0x0c0bd5a4 */
if(!s->budget--) { s->failed_pc=0x0c0bd5a4u; return 0; }
r[0]=0x00000078u;
goto P_0c0bd5a6;
P_0c0bd5a6: /* original 4e0b, guest PC 0x0c0bd5a6 */
if(!s->budget--) { s->failed_pc=0x0c0bd5a6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd5aau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd5aau) { target=s->pc; goto dispatch; }
goto P_0c0bd5aa;
P_0c0bd5a8: /* original 05de, guest PC 0x0c0bd5a8 */
if(!s->budget--) { s->failed_pc=0x0c0bd5a8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd5aa;
P_0c0bd5aa: /* original 9459, guest PC 0x0c0bd5aa */
if(!s->budget--) { s->failed_pc=0x0c0bd5aau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd660u,2);
goto P_0c0bd5ac;
P_0c0bd5ac: /* original e07c, guest PC 0x0c0bd5ac */
if(!s->budget--) { s->failed_pc=0x0c0bd5acu; return 0; }
r[0]=0x0000007cu;
goto P_0c0bd5ae;
P_0c0bd5ae: /* original 4e0b, guest PC 0x0c0bd5ae */
if(!s->budget--) { s->failed_pc=0x0c0bd5aeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd5b2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd5b2u) { target=s->pc; goto dispatch; }
goto P_0c0bd5b2;
P_0c0bd5b0: /* original 05de, guest PC 0x0c0bd5b0 */
if(!s->budget--) { s->failed_pc=0x0c0bd5b0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd5b2;
P_0c0bd5b2: /* original 9457, guest PC 0x0c0bd5b2 */
if(!s->budget--) { s->failed_pc=0x0c0bd5b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd664u,2);
goto P_0c0bd5b4;
P_0c0bd5b4: /* original 9055, guest PC 0x0c0bd5b4 */
if(!s->budget--) { s->failed_pc=0x0c0bd5b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd662u,2);
goto P_0c0bd5b6;
P_0c0bd5b6: /* original 4e0b, guest PC 0x0c0bd5b6 */
if(!s->budget--) { s->failed_pc=0x0c0bd5b6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd5bau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd5bau) { target=s->pc; goto dispatch; }
goto P_0c0bd5ba;
P_0c0bd5b8: /* original 05de, guest PC 0x0c0bd5b8 */
if(!s->budget--) { s->failed_pc=0x0c0bd5b8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd5ba;
P_0c0bd5ba: /* original 9554, guest PC 0x0c0bd5ba */
if(!s->budget--) { s->failed_pc=0x0c0bd5bau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd666u,2);
goto P_0c0bd5bc;
P_0c0bd5bc: /* original 35dc, guest PC 0x0c0bd5bc */
if(!s->budget--) { s->failed_pc=0x0c0bd5bcu; return 0; }
r[5]+=r[13];
goto P_0c0bd5be;
P_0c0bd5be: /* original 2f52, guest PC 0x0c0bd5be */
if(!s->budget--) { s->failed_pc=0x0c0bd5beu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bd5c0;
P_0c0bd5c0: /* original 9452, guest PC 0x0c0bd5c0 */
if(!s->budget--) { s->failed_pc=0x0c0bd5c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd668u,2);
goto P_0c0bd5c2;
P_0c0bd5c2: /* original 4e0b, guest PC 0x0c0bd5c2 */
if(!s->budget--) { s->failed_pc=0x0c0bd5c2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd5c6u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd5c6u) { target=s->pc; goto dispatch; }
goto P_0c0bd5c6;
P_0c0bd5c4: /* original 6552, guest PC 0x0c0bd5c4 */
if(!s->budget--) { s->failed_pc=0x0c0bd5c4u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd5c6;
P_0c0bd5c6: /* original 9550, guest PC 0x0c0bd5c6 */
if(!s->budget--) { s->failed_pc=0x0c0bd5c6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd66au,2);
goto P_0c0bd5c8;
P_0c0bd5c8: /* original 35dc, guest PC 0x0c0bd5c8 */
if(!s->budget--) { s->failed_pc=0x0c0bd5c8u; return 0; }
r[5]+=r[13];
goto P_0c0bd5ca;
P_0c0bd5ca: /* original 1f51, guest PC 0x0c0bd5ca */
if(!s->budget--) { s->failed_pc=0x0c0bd5cau; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0bd5cc;
P_0c0bd5cc: /* original 944e, guest PC 0x0c0bd5cc */
if(!s->budget--) { s->failed_pc=0x0c0bd5ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd66cu,2);
goto P_0c0bd5ce;
P_0c0bd5ce: /* original 4e0b, guest PC 0x0c0bd5ce */
if(!s->budget--) { s->failed_pc=0x0c0bd5ceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd5d2u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd5d2u) { target=s->pc; goto dispatch; }
goto P_0c0bd5d2;
P_0c0bd5d0: /* original 6552, guest PC 0x0c0bd5d0 */
if(!s->budget--) { s->failed_pc=0x0c0bd5d0u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd5d2;
P_0c0bd5d2: /* original 944d, guest PC 0x0c0bd5d2 */
if(!s->budget--) { s->failed_pc=0x0c0bd5d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd670u,2);
goto P_0c0bd5d4;
P_0c0bd5d4: /* original 904b, guest PC 0x0c0bd5d4 */
if(!s->budget--) { s->failed_pc=0x0c0bd5d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd66eu,2);
goto P_0c0bd5d6;
P_0c0bd5d6: /* original 4e0b, guest PC 0x0c0bd5d6 */
if(!s->budget--) { s->failed_pc=0x0c0bd5d6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd5dau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd5dau) { target=s->pc; goto dispatch; }
goto P_0c0bd5da;
P_0c0bd5d8: /* original 05de, guest PC 0x0c0bd5d8 */
if(!s->budget--) { s->failed_pc=0x0c0bd5d8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd5da;
P_0c0bd5da: /* original 944b, guest PC 0x0c0bd5da */
if(!s->budget--) { s->failed_pc=0x0c0bd5dau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd674u,2);
goto P_0c0bd5dc;
P_0c0bd5dc: /* original 9049, guest PC 0x0c0bd5dc */
if(!s->budget--) { s->failed_pc=0x0c0bd5dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd672u,2);
goto P_0c0bd5de;
P_0c0bd5de: /* original 4e0b, guest PC 0x0c0bd5de */
if(!s->budget--) { s->failed_pc=0x0c0bd5deu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd5e2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd5e2u) { target=s->pc; goto dispatch; }
goto P_0c0bd5e2;
P_0c0bd5e0: /* original 05de, guest PC 0x0c0bd5e0 */
if(!s->budget--) { s->failed_pc=0x0c0bd5e0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd5e2;
P_0c0bd5e2: /* original 9948, guest PC 0x0c0bd5e2 */
if(!s->budget--) { s->failed_pc=0x0c0bd5e2u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd676u,2);
goto P_0c0bd5e4;
P_0c0bd5e4: /* original 9448, guest PC 0x0c0bd5e4 */
if(!s->budget--) { s->failed_pc=0x0c0bd5e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd678u,2);
goto P_0c0bd5e6;
P_0c0bd5e6: /* original 39dc, guest PC 0x0c0bd5e6 */
if(!s->budget--) { s->failed_pc=0x0c0bd5e6u; return 0; }
r[9]+=r[13];
goto P_0c0bd5e8;
P_0c0bd5e8: /* original 4e0b, guest PC 0x0c0bd5e8 */
if(!s->budget--) { s->failed_pc=0x0c0bd5e8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd5ecu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd5ecu) { target=s->pc; goto dispatch; }
goto P_0c0bd5ec;
P_0c0bd5ea: /* original 6592, guest PC 0x0c0bd5ea */
if(!s->budget--) { s->failed_pc=0x0c0bd5eau; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bd5ec;
P_0c0bd5ec: /* original 9445, guest PC 0x0c0bd5ec */
if(!s->budget--) { s->failed_pc=0x0c0bd5ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd67au,2);
goto P_0c0bd5ee;
P_0c0bd5ee: /* original 4e0b, guest PC 0x0c0bd5ee */
if(!s->budget--) { s->failed_pc=0x0c0bd5eeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd5f2u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd5f2u) { target=s->pc; goto dispatch; }
goto P_0c0bd5f2;
P_0c0bd5f0: /* original 6592, guest PC 0x0c0bd5f0 */
if(!s->budget--) { s->failed_pc=0x0c0bd5f0u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bd5f2;
P_0c0bd5f2: /* original 9443, guest PC 0x0c0bd5f2 */
if(!s->budget--) { s->failed_pc=0x0c0bd5f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd67cu,2);
goto P_0c0bd5f4;
P_0c0bd5f4: /* original 4e0b, guest PC 0x0c0bd5f4 */
if(!s->budget--) { s->failed_pc=0x0c0bd5f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd5f8u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd5f8u) { target=s->pc; goto dispatch; }
goto P_0c0bd5f8;
P_0c0bd5f6: /* original 6592, guest PC 0x0c0bd5f6 */
if(!s->budget--) { s->failed_pc=0x0c0bd5f6u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bd5f8;
P_0c0bd5f8: /* original 9441, guest PC 0x0c0bd5f8 */
if(!s->budget--) { s->failed_pc=0x0c0bd5f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd67eu,2);
goto P_0c0bd5fa;
P_0c0bd5fa: /* original 4e0b, guest PC 0x0c0bd5fa */
if(!s->budget--) { s->failed_pc=0x0c0bd5fau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd5feu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd5feu) { target=s->pc; goto dispatch; }
goto P_0c0bd5fe;
P_0c0bd5fc: /* original 6592, guest PC 0x0c0bd5fc */
if(!s->budget--) { s->failed_pc=0x0c0bd5fcu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bd5fe;
P_0c0bd5fe: /* original 9c3f, guest PC 0x0c0bd5fe */
if(!s->budget--) { s->failed_pc=0x0c0bd5feu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd680u,2);
goto P_0c0bd600;
P_0c0bd600: /* original 943f, guest PC 0x0c0bd600 */
if(!s->budget--) { s->failed_pc=0x0c0bd600u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd682u,2);
goto P_0c0bd602;
P_0c0bd602: /* original 3cdc, guest PC 0x0c0bd602 */
if(!s->budget--) { s->failed_pc=0x0c0bd602u; return 0; }
r[12]+=r[13];
goto P_0c0bd604;
P_0c0bd604: /* original 4e0b, guest PC 0x0c0bd604 */
if(!s->budget--) { s->failed_pc=0x0c0bd604u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd608u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd608u) { target=s->pc; goto dispatch; }
goto P_0c0bd608;
P_0c0bd606: /* original 65c2, guest PC 0x0c0bd606 */
if(!s->budget--) { s->failed_pc=0x0c0bd606u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bd608;
P_0c0bd608: /* original 943c, guest PC 0x0c0bd608 */
if(!s->budget--) { s->failed_pc=0x0c0bd608u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd684u,2);
goto P_0c0bd60a;
P_0c0bd60a: /* original 4e0b, guest PC 0x0c0bd60a */
if(!s->budget--) { s->failed_pc=0x0c0bd60au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd60eu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd60eu) { target=s->pc; goto dispatch; }
goto P_0c0bd60e;
P_0c0bd60c: /* original 65c2, guest PC 0x0c0bd60c */
if(!s->budget--) { s->failed_pc=0x0c0bd60cu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bd60e;
P_0c0bd60e: /* original 943a, guest PC 0x0c0bd60e */
if(!s->budget--) { s->failed_pc=0x0c0bd60eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd686u,2);
goto P_0c0bd610;
P_0c0bd610: /* original 4e0b, guest PC 0x0c0bd610 */
if(!s->budget--) { s->failed_pc=0x0c0bd610u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd614u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd614u) { target=s->pc; goto dispatch; }
goto P_0c0bd614;
P_0c0bd612: /* original 65c2, guest PC 0x0c0bd612 */
if(!s->budget--) { s->failed_pc=0x0c0bd612u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bd614;
P_0c0bd614: /* original 9438, guest PC 0x0c0bd614 */
if(!s->budget--) { s->failed_pc=0x0c0bd614u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd688u,2);
goto P_0c0bd616;
P_0c0bd616: /* original 4e0b, guest PC 0x0c0bd616 */
if(!s->budget--) { s->failed_pc=0x0c0bd616u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd61au;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd61au) { target=s->pc; goto dispatch; }
goto P_0c0bd61a;
P_0c0bd618: /* original 65c2, guest PC 0x0c0bd618 */
if(!s->budget--) { s->failed_pc=0x0c0bd618u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bd61a;
P_0c0bd61a: /* original 9b36, guest PC 0x0c0bd61a */
if(!s->budget--) { s->failed_pc=0x0c0bd61au; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd68au,2);
goto P_0c0bd61c;
P_0c0bd61c: /* original 3bdc, guest PC 0x0c0bd61c */
if(!s->budget--) { s->failed_pc=0x0c0bd61cu; return 0; }
r[11]+=r[13];
goto P_0c0bd61e;
P_0c0bd61e: /* original a037, guest PC 0x0c0bd61e */
if(!s->budget--) { s->failed_pc=0x0c0bd61eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bd690;
P_0c0bd620: /* original 65b2, guest PC 0x0c0bd620 */
if(!s->budget--) { s->failed_pc=0x0c0bd620u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0bd622u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bd622u; return 0; } return 1;
P_0c0bd690: /* original 94ab, guest PC 0x0c0bd690 */
if(!s->budget--) { s->failed_pc=0x0c0bd690u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd7eau,2);
goto P_0c0bd692;
P_0c0bd692: /* original 4e0b, guest PC 0x0c0bd692 */
if(!s->budget--) { s->failed_pc=0x0c0bd692u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd696u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd696u) { target=s->pc; goto dispatch; }
goto P_0c0bd696;
P_0c0bd694: /* original 0009, guest PC 0x0c0bd694 */
if(!s->budget--) { s->failed_pc=0x0c0bd694u; return 0; }
goto P_0c0bd696;
P_0c0bd696: /* original 94a9, guest PC 0x0c0bd696 */
if(!s->budget--) { s->failed_pc=0x0c0bd696u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd7ecu,2);
goto P_0c0bd698;
P_0c0bd698: /* original 4e0b, guest PC 0x0c0bd698 */
if(!s->budget--) { s->failed_pc=0x0c0bd698u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd69cu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd69cu) { target=s->pc; goto dispatch; }
goto P_0c0bd69c;
P_0c0bd69a: /* original 65b2, guest PC 0x0c0bd69a */
if(!s->budget--) { s->failed_pc=0x0c0bd69au; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bd69c;
P_0c0bd69c: /* original 94a7, guest PC 0x0c0bd69c */
if(!s->budget--) { s->failed_pc=0x0c0bd69cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd7eeu,2);
goto P_0c0bd69e;
P_0c0bd69e: /* original 4e0b, guest PC 0x0c0bd69e */
if(!s->budget--) { s->failed_pc=0x0c0bd69eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd6a2u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd6a2u) { target=s->pc; goto dispatch; }
goto P_0c0bd6a2;
P_0c0bd6a0: /* original 65b2, guest PC 0x0c0bd6a0 */
if(!s->budget--) { s->failed_pc=0x0c0bd6a0u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bd6a2;
P_0c0bd6a2: /* original 94a5, guest PC 0x0c0bd6a2 */
if(!s->budget--) { s->failed_pc=0x0c0bd6a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd7f0u,2);
goto P_0c0bd6a4;
P_0c0bd6a4: /* original 4e0b, guest PC 0x0c0bd6a4 */
if(!s->budget--) { s->failed_pc=0x0c0bd6a4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd6a8u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd6a8u) { target=s->pc; goto dispatch; }
goto P_0c0bd6a8;
P_0c0bd6a6: /* original 65b2, guest PC 0x0c0bd6a6 */
if(!s->budget--) { s->failed_pc=0x0c0bd6a6u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bd6a8;
P_0c0bd6a8: /* original 9aa3, guest PC 0x0c0bd6a8 */
if(!s->budget--) { s->failed_pc=0x0c0bd6a8u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd7f2u,2);
goto P_0c0bd6aa;
P_0c0bd6aa: /* original 94a3, guest PC 0x0c0bd6aa */
if(!s->budget--) { s->failed_pc=0x0c0bd6aau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd7f4u,2);
goto P_0c0bd6ac;
P_0c0bd6ac: /* original 3adc, guest PC 0x0c0bd6ac */
if(!s->budget--) { s->failed_pc=0x0c0bd6acu; return 0; }
r[10]+=r[13];
goto P_0c0bd6ae;
P_0c0bd6ae: /* original 4e0b, guest PC 0x0c0bd6ae */
if(!s->budget--) { s->failed_pc=0x0c0bd6aeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd6b2u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd6b2u) { target=s->pc; goto dispatch; }
goto P_0c0bd6b2;
P_0c0bd6b0: /* original 65a2, guest PC 0x0c0bd6b0 */
if(!s->budget--) { s->failed_pc=0x0c0bd6b0u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bd6b2;
P_0c0bd6b2: /* original 94a0, guest PC 0x0c0bd6b2 */
if(!s->budget--) { s->failed_pc=0x0c0bd6b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd7f6u,2);
goto P_0c0bd6b4;
P_0c0bd6b4: /* original 4e0b, guest PC 0x0c0bd6b4 */
if(!s->budget--) { s->failed_pc=0x0c0bd6b4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd6b8u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd6b8u) { target=s->pc; goto dispatch; }
goto P_0c0bd6b8;
P_0c0bd6b6: /* original 65a2, guest PC 0x0c0bd6b6 */
if(!s->budget--) { s->failed_pc=0x0c0bd6b6u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bd6b8;
P_0c0bd6b8: /* original 949e, guest PC 0x0c0bd6b8 */
if(!s->budget--) { s->failed_pc=0x0c0bd6b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd7f8u,2);
goto P_0c0bd6ba;
P_0c0bd6ba: /* original 4e0b, guest PC 0x0c0bd6ba */
if(!s->budget--) { s->failed_pc=0x0c0bd6bau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd6beu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd6beu) { target=s->pc; goto dispatch; }
goto P_0c0bd6be;
P_0c0bd6bc: /* original 65a2, guest PC 0x0c0bd6bc */
if(!s->budget--) { s->failed_pc=0x0c0bd6bcu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bd6be;
P_0c0bd6be: /* original 949c, guest PC 0x0c0bd6be */
if(!s->budget--) { s->failed_pc=0x0c0bd6beu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd7fau,2);
goto P_0c0bd6c0;
P_0c0bd6c0: /* original 4e0b, guest PC 0x0c0bd6c0 */
if(!s->budget--) { s->failed_pc=0x0c0bd6c0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd6c4u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd6c4u) { target=s->pc; goto dispatch; }
goto P_0c0bd6c4;
P_0c0bd6c2: /* original 65a2, guest PC 0x0c0bd6c2 */
if(!s->budget--) { s->failed_pc=0x0c0bd6c2u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bd6c4;
P_0c0bd6c4: /* original 949a, guest PC 0x0c0bd6c4 */
if(!s->budget--) { s->failed_pc=0x0c0bd6c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd7fcu,2);
goto P_0c0bd6c6;
P_0c0bd6c6: /* original 65f2, guest PC 0x0c0bd6c6 */
if(!s->budget--) { s->failed_pc=0x0c0bd6c6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bd6c8;
P_0c0bd6c8: /* original 4e0b, guest PC 0x0c0bd6c8 */
if(!s->budget--) { s->failed_pc=0x0c0bd6c8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd6ccu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd6ccu) { target=s->pc; goto dispatch; }
goto P_0c0bd6cc;
P_0c0bd6ca: /* original 6552, guest PC 0x0c0bd6ca */
if(!s->budget--) { s->failed_pc=0x0c0bd6cau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd6cc;
P_0c0bd6cc: /* original 9497, guest PC 0x0c0bd6cc */
if(!s->budget--) { s->failed_pc=0x0c0bd6ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd7feu,2);
goto P_0c0bd6ce;
P_0c0bd6ce: /* original 55f1, guest PC 0x0c0bd6ce */
if(!s->budget--) { s->failed_pc=0x0c0bd6ceu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0bd6d0;
P_0c0bd6d0: /* original 4e0b, guest PC 0x0c0bd6d0 */
if(!s->budget--) { s->failed_pc=0x0c0bd6d0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd6d4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd6d4u) { target=s->pc; goto dispatch; }
goto P_0c0bd6d4;
P_0c0bd6d2: /* original 6552, guest PC 0x0c0bd6d2 */
if(!s->budget--) { s->failed_pc=0x0c0bd6d2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd6d4;
P_0c0bd6d4: /* original 9494, guest PC 0x0c0bd6d4 */
if(!s->budget--) { s->failed_pc=0x0c0bd6d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd800u,2);
goto P_0c0bd6d6;
P_0c0bd6d6: /* original 4e0b, guest PC 0x0c0bd6d6 */
if(!s->budget--) { s->failed_pc=0x0c0bd6d6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd6dau;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd6dau) { target=s->pc; goto dispatch; }
goto P_0c0bd6da;
P_0c0bd6d8: /* original 6592, guest PC 0x0c0bd6d8 */
if(!s->budget--) { s->failed_pc=0x0c0bd6d8u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bd6da;
P_0c0bd6da: /* original 9492, guest PC 0x0c0bd6da */
if(!s->budget--) { s->failed_pc=0x0c0bd6dau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd802u,2);
goto P_0c0bd6dc;
P_0c0bd6dc: /* original 4e0b, guest PC 0x0c0bd6dc */
if(!s->budget--) { s->failed_pc=0x0c0bd6dcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd6e0u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd6e0u) { target=s->pc; goto dispatch; }
goto P_0c0bd6e0;
P_0c0bd6de: /* original 6592, guest PC 0x0c0bd6de */
if(!s->budget--) { s->failed_pc=0x0c0bd6deu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bd6e0;
P_0c0bd6e0: /* original 9490, guest PC 0x0c0bd6e0 */
if(!s->budget--) { s->failed_pc=0x0c0bd6e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd804u,2);
goto P_0c0bd6e2;
P_0c0bd6e2: /* original 4e0b, guest PC 0x0c0bd6e2 */
if(!s->budget--) { s->failed_pc=0x0c0bd6e2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd6e6u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd6e6u) { target=s->pc; goto dispatch; }
goto P_0c0bd6e6;
P_0c0bd6e4: /* original 6592, guest PC 0x0c0bd6e4 */
if(!s->budget--) { s->failed_pc=0x0c0bd6e4u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bd6e6;
P_0c0bd6e6: /* original 948e, guest PC 0x0c0bd6e6 */
if(!s->budget--) { s->failed_pc=0x0c0bd6e6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd806u,2);
goto P_0c0bd6e8;
P_0c0bd6e8: /* original 4e0b, guest PC 0x0c0bd6e8 */
if(!s->budget--) { s->failed_pc=0x0c0bd6e8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd6ecu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd6ecu) { target=s->pc; goto dispatch; }
goto P_0c0bd6ec;
P_0c0bd6ea: /* original 6592, guest PC 0x0c0bd6ea */
if(!s->budget--) { s->failed_pc=0x0c0bd6eau; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bd6ec;
P_0c0bd6ec: /* original 948c, guest PC 0x0c0bd6ec */
if(!s->budget--) { s->failed_pc=0x0c0bd6ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd808u,2);
goto P_0c0bd6ee;
P_0c0bd6ee: /* original 4e0b, guest PC 0x0c0bd6ee */
if(!s->budget--) { s->failed_pc=0x0c0bd6eeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd6f2u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd6f2u) { target=s->pc; goto dispatch; }
goto P_0c0bd6f2;
P_0c0bd6f0: /* original 65c2, guest PC 0x0c0bd6f0 */
if(!s->budget--) { s->failed_pc=0x0c0bd6f0u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bd6f2;
P_0c0bd6f2: /* original 948a, guest PC 0x0c0bd6f2 */
if(!s->budget--) { s->failed_pc=0x0c0bd6f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd80au,2);
goto P_0c0bd6f4;
P_0c0bd6f4: /* original 4e0b, guest PC 0x0c0bd6f4 */
if(!s->budget--) { s->failed_pc=0x0c0bd6f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd6f8u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd6f8u) { target=s->pc; goto dispatch; }
goto P_0c0bd6f8;
P_0c0bd6f6: /* original 65c2, guest PC 0x0c0bd6f6 */
if(!s->budget--) { s->failed_pc=0x0c0bd6f6u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bd6f8;
P_0c0bd6f8: /* original 9488, guest PC 0x0c0bd6f8 */
if(!s->budget--) { s->failed_pc=0x0c0bd6f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd80cu,2);
goto P_0c0bd6fa;
P_0c0bd6fa: /* original 4e0b, guest PC 0x0c0bd6fa */
if(!s->budget--) { s->failed_pc=0x0c0bd6fau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd6feu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd6feu) { target=s->pc; goto dispatch; }
goto P_0c0bd6fe;
P_0c0bd6fc: /* original 65c2, guest PC 0x0c0bd6fc */
if(!s->budget--) { s->failed_pc=0x0c0bd6fcu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bd6fe;
P_0c0bd6fe: /* original 9486, guest PC 0x0c0bd6fe */
if(!s->budget--) { s->failed_pc=0x0c0bd6feu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd80eu,2);
goto P_0c0bd700;
P_0c0bd700: /* original 4e0b, guest PC 0x0c0bd700 */
if(!s->budget--) { s->failed_pc=0x0c0bd700u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd704u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd704u) { target=s->pc; goto dispatch; }
goto P_0c0bd704;
P_0c0bd702: /* original 65c2, guest PC 0x0c0bd702 */
if(!s->budget--) { s->failed_pc=0x0c0bd702u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bd704;
P_0c0bd704: /* original 9484, guest PC 0x0c0bd704 */
if(!s->budget--) { s->failed_pc=0x0c0bd704u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd810u,2);
goto P_0c0bd706;
P_0c0bd706: /* original 4e0b, guest PC 0x0c0bd706 */
if(!s->budget--) { s->failed_pc=0x0c0bd706u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd70au;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd70au) { target=s->pc; goto dispatch; }
goto P_0c0bd70a;
P_0c0bd708: /* original 65b2, guest PC 0x0c0bd708 */
if(!s->budget--) { s->failed_pc=0x0c0bd708u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bd70a;
P_0c0bd70a: /* original 9482, guest PC 0x0c0bd70a */
if(!s->budget--) { s->failed_pc=0x0c0bd70au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd812u,2);
goto P_0c0bd70c;
P_0c0bd70c: /* original 4e0b, guest PC 0x0c0bd70c */
if(!s->budget--) { s->failed_pc=0x0c0bd70cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd710u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd710u) { target=s->pc; goto dispatch; }
goto P_0c0bd710;
P_0c0bd70e: /* original 65b2, guest PC 0x0c0bd70e */
if(!s->budget--) { s->failed_pc=0x0c0bd70eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bd710;
P_0c0bd710: /* original 9480, guest PC 0x0c0bd710 */
if(!s->budget--) { s->failed_pc=0x0c0bd710u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd814u,2);
goto P_0c0bd712;
P_0c0bd712: /* original 4e0b, guest PC 0x0c0bd712 */
if(!s->budget--) { s->failed_pc=0x0c0bd712u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd716u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd716u) { target=s->pc; goto dispatch; }
goto P_0c0bd716;
P_0c0bd714: /* original 65b2, guest PC 0x0c0bd714 */
if(!s->budget--) { s->failed_pc=0x0c0bd714u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bd716;
P_0c0bd716: /* original 947e, guest PC 0x0c0bd716 */
if(!s->budget--) { s->failed_pc=0x0c0bd716u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd816u,2);
goto P_0c0bd718;
P_0c0bd718: /* original 4e0b, guest PC 0x0c0bd718 */
if(!s->budget--) { s->failed_pc=0x0c0bd718u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd71cu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd71cu) { target=s->pc; goto dispatch; }
goto P_0c0bd71c;
P_0c0bd71a: /* original 65b2, guest PC 0x0c0bd71a */
if(!s->budget--) { s->failed_pc=0x0c0bd71au; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bd71c;
P_0c0bd71c: /* original 947c, guest PC 0x0c0bd71c */
if(!s->budget--) { s->failed_pc=0x0c0bd71cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd818u,2);
goto P_0c0bd71e;
P_0c0bd71e: /* original 4e0b, guest PC 0x0c0bd71e */
if(!s->budget--) { s->failed_pc=0x0c0bd71eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd722u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd722u) { target=s->pc; goto dispatch; }
goto P_0c0bd722;
P_0c0bd720: /* original 65a2, guest PC 0x0c0bd720 */
if(!s->budget--) { s->failed_pc=0x0c0bd720u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bd722;
P_0c0bd722: /* original 947a, guest PC 0x0c0bd722 */
if(!s->budget--) { s->failed_pc=0x0c0bd722u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd81au,2);
goto P_0c0bd724;
P_0c0bd724: /* original 4e0b, guest PC 0x0c0bd724 */
if(!s->budget--) { s->failed_pc=0x0c0bd724u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd728u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd728u) { target=s->pc; goto dispatch; }
goto P_0c0bd728;
P_0c0bd726: /* original 65a2, guest PC 0x0c0bd726 */
if(!s->budget--) { s->failed_pc=0x0c0bd726u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bd728;
P_0c0bd728: /* original 9478, guest PC 0x0c0bd728 */
if(!s->budget--) { s->failed_pc=0x0c0bd728u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd81cu,2);
goto P_0c0bd72a;
P_0c0bd72a: /* original 4e0b, guest PC 0x0c0bd72a */
if(!s->budget--) { s->failed_pc=0x0c0bd72au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd72eu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd72eu) { target=s->pc; goto dispatch; }
goto P_0c0bd72e;
P_0c0bd72c: /* original 65a2, guest PC 0x0c0bd72c */
if(!s->budget--) { s->failed_pc=0x0c0bd72cu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bd72e;
P_0c0bd72e: /* original 9476, guest PC 0x0c0bd72e */
if(!s->budget--) { s->failed_pc=0x0c0bd72eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd81eu,2);
goto P_0c0bd730;
P_0c0bd730: /* original 4e0b, guest PC 0x0c0bd730 */
if(!s->budget--) { s->failed_pc=0x0c0bd730u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd734u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd734u) { target=s->pc; goto dispatch; }
goto P_0c0bd734;
P_0c0bd732: /* original 65a2, guest PC 0x0c0bd732 */
if(!s->budget--) { s->failed_pc=0x0c0bd732u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bd734;
P_0c0bd734: /* original 9574, guest PC 0x0c0bd734 */
if(!s->budget--) { s->failed_pc=0x0c0bd734u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd820u,2);
goto P_0c0bd736;
P_0c0bd736: /* original 35dc, guest PC 0x0c0bd736 */
if(!s->budget--) { s->failed_pc=0x0c0bd736u; return 0; }
r[5]+=r[13];
goto P_0c0bd738;
P_0c0bd738: /* original 2f52, guest PC 0x0c0bd738 */
if(!s->budget--) { s->failed_pc=0x0c0bd738u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bd73a;
P_0c0bd73a: /* original 9472, guest PC 0x0c0bd73a */
if(!s->budget--) { s->failed_pc=0x0c0bd73au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd822u,2);
goto P_0c0bd73c;
P_0c0bd73c: /* original 4e0b, guest PC 0x0c0bd73c */
if(!s->budget--) { s->failed_pc=0x0c0bd73cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd740u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd740u) { target=s->pc; goto dispatch; }
goto P_0c0bd740;
P_0c0bd73e: /* original 6552, guest PC 0x0c0bd73e */
if(!s->budget--) { s->failed_pc=0x0c0bd73eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd740;
P_0c0bd740: /* original 9470, guest PC 0x0c0bd740 */
if(!s->budget--) { s->failed_pc=0x0c0bd740u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd824u,2);
goto P_0c0bd742;
P_0c0bd742: /* original 65f2, guest PC 0x0c0bd742 */
if(!s->budget--) { s->failed_pc=0x0c0bd742u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bd744;
P_0c0bd744: /* original 4e0b, guest PC 0x0c0bd744 */
if(!s->budget--) { s->failed_pc=0x0c0bd744u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd748u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd748u) { target=s->pc; goto dispatch; }
goto P_0c0bd748;
P_0c0bd746: /* original 6552, guest PC 0x0c0bd746 */
if(!s->budget--) { s->failed_pc=0x0c0bd746u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd748;
P_0c0bd748: /* original 956d, guest PC 0x0c0bd748 */
if(!s->budget--) { s->failed_pc=0x0c0bd748u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd826u,2);
goto P_0c0bd74a;
P_0c0bd74a: /* original 35dc, guest PC 0x0c0bd74a */
if(!s->budget--) { s->failed_pc=0x0c0bd74au; return 0; }
r[5]+=r[13];
goto P_0c0bd74c;
P_0c0bd74c: /* original 2f52, guest PC 0x0c0bd74c */
if(!s->budget--) { s->failed_pc=0x0c0bd74cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bd74e;
P_0c0bd74e: /* original 946b, guest PC 0x0c0bd74e */
if(!s->budget--) { s->failed_pc=0x0c0bd74eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd828u,2);
goto P_0c0bd750;
P_0c0bd750: /* original 4e0b, guest PC 0x0c0bd750 */
if(!s->budget--) { s->failed_pc=0x0c0bd750u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd754u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd754u) { target=s->pc; goto dispatch; }
goto P_0c0bd754;
P_0c0bd752: /* original 6552, guest PC 0x0c0bd752 */
if(!s->budget--) { s->failed_pc=0x0c0bd752u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd754;
P_0c0bd754: /* original 9469, guest PC 0x0c0bd754 */
if(!s->budget--) { s->failed_pc=0x0c0bd754u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd82au,2);
goto P_0c0bd756;
P_0c0bd756: /* original 65f2, guest PC 0x0c0bd756 */
if(!s->budget--) { s->failed_pc=0x0c0bd756u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bd758;
P_0c0bd758: /* original 4e0b, guest PC 0x0c0bd758 */
if(!s->budget--) { s->failed_pc=0x0c0bd758u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd75cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd75cu) { target=s->pc; goto dispatch; }
goto P_0c0bd75c;
P_0c0bd75a: /* original 6552, guest PC 0x0c0bd75a */
if(!s->budget--) { s->failed_pc=0x0c0bd75au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd75c;
P_0c0bd75c: /* original 9467, guest PC 0x0c0bd75c */
if(!s->budget--) { s->failed_pc=0x0c0bd75cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd82eu,2);
goto P_0c0bd75e;
P_0c0bd75e: /* original 9065, guest PC 0x0c0bd75e */
if(!s->budget--) { s->failed_pc=0x0c0bd75eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd82cu,2);
goto P_0c0bd760;
P_0c0bd760: /* original 4e0b, guest PC 0x0c0bd760 */
if(!s->budget--) { s->failed_pc=0x0c0bd760u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd764u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd764u) { target=s->pc; goto dispatch; }
goto P_0c0bd764;
P_0c0bd762: /* original 05de, guest PC 0x0c0bd762 */
if(!s->budget--) { s->failed_pc=0x0c0bd762u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd764;
P_0c0bd764: /* original 9564, guest PC 0x0c0bd764 */
if(!s->budget--) { s->failed_pc=0x0c0bd764u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd830u,2);
goto P_0c0bd766;
P_0c0bd766: /* original 35dc, guest PC 0x0c0bd766 */
if(!s->budget--) { s->failed_pc=0x0c0bd766u; return 0; }
r[5]+=r[13];
goto P_0c0bd768;
P_0c0bd768: /* original 2f52, guest PC 0x0c0bd768 */
if(!s->budget--) { s->failed_pc=0x0c0bd768u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bd76a;
P_0c0bd76a: /* original 9462, guest PC 0x0c0bd76a */
if(!s->budget--) { s->failed_pc=0x0c0bd76au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd832u,2);
goto P_0c0bd76c;
P_0c0bd76c: /* original 4e0b, guest PC 0x0c0bd76c */
if(!s->budget--) { s->failed_pc=0x0c0bd76cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd770u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd770u) { target=s->pc; goto dispatch; }
goto P_0c0bd770;
P_0c0bd76e: /* original 6552, guest PC 0x0c0bd76e */
if(!s->budget--) { s->failed_pc=0x0c0bd76eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd770;
P_0c0bd770: /* original 9460, guest PC 0x0c0bd770 */
if(!s->budget--) { s->failed_pc=0x0c0bd770u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd834u,2);
goto P_0c0bd772;
P_0c0bd772: /* original 65f2, guest PC 0x0c0bd772 */
if(!s->budget--) { s->failed_pc=0x0c0bd772u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bd774;
P_0c0bd774: /* original 4e0b, guest PC 0x0c0bd774 */
if(!s->budget--) { s->failed_pc=0x0c0bd774u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd778u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd778u) { target=s->pc; goto dispatch; }
goto P_0c0bd778;
P_0c0bd776: /* original 6552, guest PC 0x0c0bd776 */
if(!s->budget--) { s->failed_pc=0x0c0bd776u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd778;
P_0c0bd778: /* original 945e, guest PC 0x0c0bd778 */
if(!s->budget--) { s->failed_pc=0x0c0bd778u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd838u,2);
goto P_0c0bd77a;
P_0c0bd77a: /* original 905c, guest PC 0x0c0bd77a */
if(!s->budget--) { s->failed_pc=0x0c0bd77au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd836u,2);
goto P_0c0bd77c;
P_0c0bd77c: /* original 4e0b, guest PC 0x0c0bd77c */
if(!s->budget--) { s->failed_pc=0x0c0bd77cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd780u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd780u) { target=s->pc; goto dispatch; }
goto P_0c0bd780;
P_0c0bd77e: /* original 05de, guest PC 0x0c0bd77e */
if(!s->budget--) { s->failed_pc=0x0c0bd77eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd780;
P_0c0bd780: /* original 955b, guest PC 0x0c0bd780 */
if(!s->budget--) { s->failed_pc=0x0c0bd780u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd83au,2);
goto P_0c0bd782;
P_0c0bd782: /* original 35dc, guest PC 0x0c0bd782 */
if(!s->budget--) { s->failed_pc=0x0c0bd782u; return 0; }
r[5]+=r[13];
goto P_0c0bd784;
P_0c0bd784: /* original 2f52, guest PC 0x0c0bd784 */
if(!s->budget--) { s->failed_pc=0x0c0bd784u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bd786;
P_0c0bd786: /* original 9459, guest PC 0x0c0bd786 */
if(!s->budget--) { s->failed_pc=0x0c0bd786u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd83cu,2);
goto P_0c0bd788;
P_0c0bd788: /* original 4e0b, guest PC 0x0c0bd788 */
if(!s->budget--) { s->failed_pc=0x0c0bd788u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd78cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd78cu) { target=s->pc; goto dispatch; }
goto P_0c0bd78c;
P_0c0bd78a: /* original 6552, guest PC 0x0c0bd78a */
if(!s->budget--) { s->failed_pc=0x0c0bd78au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd78c;
P_0c0bd78c: /* original 9457, guest PC 0x0c0bd78c */
if(!s->budget--) { s->failed_pc=0x0c0bd78cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd83eu,2);
goto P_0c0bd78e;
P_0c0bd78e: /* original 65f2, guest PC 0x0c0bd78e */
if(!s->budget--) { s->failed_pc=0x0c0bd78eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bd790;
P_0c0bd790: /* original 4e0b, guest PC 0x0c0bd790 */
if(!s->budget--) { s->failed_pc=0x0c0bd790u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd794u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd794u) { target=s->pc; goto dispatch; }
goto P_0c0bd794;
P_0c0bd792: /* original 6552, guest PC 0x0c0bd792 */
if(!s->budget--) { s->failed_pc=0x0c0bd792u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd794;
P_0c0bd794: /* original 9455, guest PC 0x0c0bd794 */
if(!s->budget--) { s->failed_pc=0x0c0bd794u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd842u,2);
goto P_0c0bd796;
P_0c0bd796: /* original 9053, guest PC 0x0c0bd796 */
if(!s->budget--) { s->failed_pc=0x0c0bd796u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd840u,2);
goto P_0c0bd798;
P_0c0bd798: /* original 4e0b, guest PC 0x0c0bd798 */
if(!s->budget--) { s->failed_pc=0x0c0bd798u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd79cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd79cu) { target=s->pc; goto dispatch; }
goto P_0c0bd79c;
P_0c0bd79a: /* original 05de, guest PC 0x0c0bd79a */
if(!s->budget--) { s->failed_pc=0x0c0bd79au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd79c;
P_0c0bd79c: /* original 9552, guest PC 0x0c0bd79c */
if(!s->budget--) { s->failed_pc=0x0c0bd79cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd844u,2);
goto P_0c0bd79e;
P_0c0bd79e: /* original 35dc, guest PC 0x0c0bd79e */
if(!s->budget--) { s->failed_pc=0x0c0bd79eu; return 0; }
r[5]+=r[13];
goto P_0c0bd7a0;
P_0c0bd7a0: /* original 2f52, guest PC 0x0c0bd7a0 */
if(!s->budget--) { s->failed_pc=0x0c0bd7a0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bd7a2;
P_0c0bd7a2: /* original 9450, guest PC 0x0c0bd7a2 */
if(!s->budget--) { s->failed_pc=0x0c0bd7a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd846u,2);
goto P_0c0bd7a4;
P_0c0bd7a4: /* original 4e0b, guest PC 0x0c0bd7a4 */
if(!s->budget--) { s->failed_pc=0x0c0bd7a4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd7a8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd7a8u) { target=s->pc; goto dispatch; }
goto P_0c0bd7a8;
P_0c0bd7a6: /* original 6552, guest PC 0x0c0bd7a6 */
if(!s->budget--) { s->failed_pc=0x0c0bd7a6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd7a8;
P_0c0bd7a8: /* original 944e, guest PC 0x0c0bd7a8 */
if(!s->budget--) { s->failed_pc=0x0c0bd7a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd848u,2);
goto P_0c0bd7aa;
P_0c0bd7aa: /* original 65f2, guest PC 0x0c0bd7aa */
if(!s->budget--) { s->failed_pc=0x0c0bd7aau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bd7ac;
P_0c0bd7ac: /* original 4e0b, guest PC 0x0c0bd7ac */
if(!s->budget--) { s->failed_pc=0x0c0bd7acu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd7b0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd7b0u) { target=s->pc; goto dispatch; }
goto P_0c0bd7b0;
P_0c0bd7ae: /* original 6552, guest PC 0x0c0bd7ae */
if(!s->budget--) { s->failed_pc=0x0c0bd7aeu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd7b0;
P_0c0bd7b0: /* original 954b, guest PC 0x0c0bd7b0 */
if(!s->budget--) { s->failed_pc=0x0c0bd7b0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd84au,2);
goto P_0c0bd7b2;
P_0c0bd7b2: /* original 35dc, guest PC 0x0c0bd7b2 */
if(!s->budget--) { s->failed_pc=0x0c0bd7b2u; return 0; }
r[5]+=r[13];
goto P_0c0bd7b4;
P_0c0bd7b4: /* original 2f52, guest PC 0x0c0bd7b4 */
if(!s->budget--) { s->failed_pc=0x0c0bd7b4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bd7b6;
P_0c0bd7b6: /* original 9449, guest PC 0x0c0bd7b6 */
if(!s->budget--) { s->failed_pc=0x0c0bd7b6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd84cu,2);
goto P_0c0bd7b8;
P_0c0bd7b8: /* original 4e0b, guest PC 0x0c0bd7b8 */
if(!s->budget--) { s->failed_pc=0x0c0bd7b8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd7bcu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd7bcu) { target=s->pc; goto dispatch; }
goto P_0c0bd7bc;
P_0c0bd7ba: /* original 6552, guest PC 0x0c0bd7ba */
if(!s->budget--) { s->failed_pc=0x0c0bd7bau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd7bc;
P_0c0bd7bc: /* original 9447, guest PC 0x0c0bd7bc */
if(!s->budget--) { s->failed_pc=0x0c0bd7bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd84eu,2);
goto P_0c0bd7be;
P_0c0bd7be: /* original 65f2, guest PC 0x0c0bd7be */
if(!s->budget--) { s->failed_pc=0x0c0bd7beu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bd7c0;
P_0c0bd7c0: /* original 4e0b, guest PC 0x0c0bd7c0 */
if(!s->budget--) { s->failed_pc=0x0c0bd7c0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd7c4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd7c4u) { target=s->pc; goto dispatch; }
goto P_0c0bd7c4;
P_0c0bd7c2: /* original 6552, guest PC 0x0c0bd7c2 */
if(!s->budget--) { s->failed_pc=0x0c0bd7c2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd7c4;
P_0c0bd7c4: /* original 9445, guest PC 0x0c0bd7c4 */
if(!s->budget--) { s->failed_pc=0x0c0bd7c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd852u,2);
goto P_0c0bd7c6;
P_0c0bd7c6: /* original 9043, guest PC 0x0c0bd7c6 */
if(!s->budget--) { s->failed_pc=0x0c0bd7c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd850u,2);
goto P_0c0bd7c8;
P_0c0bd7c8: /* original 4e0b, guest PC 0x0c0bd7c8 */
if(!s->budget--) { s->failed_pc=0x0c0bd7c8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd7ccu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd7ccu) { target=s->pc; goto dispatch; }
goto P_0c0bd7cc;
P_0c0bd7ca: /* original 05de, guest PC 0x0c0bd7ca */
if(!s->budget--) { s->failed_pc=0x0c0bd7cau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd7cc;
P_0c0bd7cc: /* original 9443, guest PC 0x0c0bd7cc */
if(!s->budget--) { s->failed_pc=0x0c0bd7ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd856u,2);
goto P_0c0bd7ce;
P_0c0bd7ce: /* original 9041, guest PC 0x0c0bd7ce */
if(!s->budget--) { s->failed_pc=0x0c0bd7ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd854u,2);
goto P_0c0bd7d0;
P_0c0bd7d0: /* original 4e0b, guest PC 0x0c0bd7d0 */
if(!s->budget--) { s->failed_pc=0x0c0bd7d0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd7d4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd7d4u) { target=s->pc; goto dispatch; }
goto P_0c0bd7d4;
P_0c0bd7d2: /* original 05de, guest PC 0x0c0bd7d2 */
if(!s->budget--) { s->failed_pc=0x0c0bd7d2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd7d4;
P_0c0bd7d4: /* original 9441, guest PC 0x0c0bd7d4 */
if(!s->budget--) { s->failed_pc=0x0c0bd7d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd85au,2);
goto P_0c0bd7d6;
P_0c0bd7d6: /* original 903f, guest PC 0x0c0bd7d6 */
if(!s->budget--) { s->failed_pc=0x0c0bd7d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd858u,2);
goto P_0c0bd7d8;
P_0c0bd7d8: /* original 4e0b, guest PC 0x0c0bd7d8 */
if(!s->budget--) { s->failed_pc=0x0c0bd7d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd7dcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd7dcu) { target=s->pc; goto dispatch; }
goto P_0c0bd7dc;
P_0c0bd7da: /* original 05de, guest PC 0x0c0bd7da */
if(!s->budget--) { s->failed_pc=0x0c0bd7dau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd7dc;
P_0c0bd7dc: /* original 943f, guest PC 0x0c0bd7dc */
if(!s->budget--) { s->failed_pc=0x0c0bd7dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd85eu,2);
goto P_0c0bd7de;
P_0c0bd7de: /* original 903d, guest PC 0x0c0bd7de */
if(!s->budget--) { s->failed_pc=0x0c0bd7deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd85cu,2);
goto P_0c0bd7e0;
P_0c0bd7e0: /* original 4e0b, guest PC 0x0c0bd7e0 */
if(!s->budget--) { s->failed_pc=0x0c0bd7e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd7e4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd7e4u) { target=s->pc; goto dispatch; }
goto P_0c0bd7e4;
P_0c0bd7e2: /* original 05de, guest PC 0x0c0bd7e2 */
if(!s->budget--) { s->failed_pc=0x0c0bd7e2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd7e4;
P_0c0bd7e4: /* original 903c, guest PC 0x0c0bd7e4 */
if(!s->budget--) { s->failed_pc=0x0c0bd7e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd860u,2);
goto P_0c0bd7e6;
P_0c0bd7e6: /* original a03c, guest PC 0x0c0bd7e6 */
if(!s->budget--) { s->failed_pc=0x0c0bd7e6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd862;
P_0c0bd7e8: /* original 05de, guest PC 0x0c0bd7e8 */
if(!s->budget--) { s->failed_pc=0x0c0bd7e8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0bd7eau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bd7eau; return 0; } return 1;
P_0c0bd862: /* original 9432, guest PC 0x0c0bd862 */
if(!s->budget--) { s->failed_pc=0x0c0bd862u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd8cau,2);
goto P_0c0bd864;
P_0c0bd864: /* original 4e0b, guest PC 0x0c0bd864 */
if(!s->budget--) { s->failed_pc=0x0c0bd864u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd868u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd868u) { target=s->pc; goto dispatch; }
goto P_0c0bd868;
P_0c0bd866: /* original 0009, guest PC 0x0c0bd866 */
if(!s->budget--) { s->failed_pc=0x0c0bd866u; return 0; }
goto P_0c0bd868;
P_0c0bd868: /* original 9431, guest PC 0x0c0bd868 */
if(!s->budget--) { s->failed_pc=0x0c0bd868u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd8ceu,2);
goto P_0c0bd86a;
P_0c0bd86a: /* original 902f, guest PC 0x0c0bd86a */
if(!s->budget--) { s->failed_pc=0x0c0bd86au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd8ccu,2);
goto P_0c0bd86c;
P_0c0bd86c: /* original 4e0b, guest PC 0x0c0bd86c */
if(!s->budget--) { s->failed_pc=0x0c0bd86cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd870u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd870u) { target=s->pc; goto dispatch; }
goto P_0c0bd870;
P_0c0bd86e: /* original 05de, guest PC 0x0c0bd86e */
if(!s->budget--) { s->failed_pc=0x0c0bd86eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd870;
P_0c0bd870: /* original 942f, guest PC 0x0c0bd870 */
if(!s->budget--) { s->failed_pc=0x0c0bd870u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd8d2u,2);
goto P_0c0bd872;
P_0c0bd872: /* original 902d, guest PC 0x0c0bd872 */
if(!s->budget--) { s->failed_pc=0x0c0bd872u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd8d0u,2);
goto P_0c0bd874;
P_0c0bd874: /* original 4e0b, guest PC 0x0c0bd874 */
if(!s->budget--) { s->failed_pc=0x0c0bd874u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd878u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd878u) { target=s->pc; goto dispatch; }
goto P_0c0bd878;
P_0c0bd876: /* original 05de, guest PC 0x0c0bd876 */
if(!s->budget--) { s->failed_pc=0x0c0bd876u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd878;
P_0c0bd878: /* original 942d, guest PC 0x0c0bd878 */
if(!s->budget--) { s->failed_pc=0x0c0bd878u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd8d6u,2);
goto P_0c0bd87a;
P_0c0bd87a: /* original 902b, guest PC 0x0c0bd87a */
if(!s->budget--) { s->failed_pc=0x0c0bd87au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd8d4u,2);
goto P_0c0bd87c;
P_0c0bd87c: /* original 4e0b, guest PC 0x0c0bd87c */
if(!s->budget--) { s->failed_pc=0x0c0bd87cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd880u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd880u) { target=s->pc; goto dispatch; }
goto P_0c0bd880;
P_0c0bd87e: /* original 05de, guest PC 0x0c0bd87e */
if(!s->budget--) { s->failed_pc=0x0c0bd87eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd880;
P_0c0bd880: /* original 942b, guest PC 0x0c0bd880 */
if(!s->budget--) { s->failed_pc=0x0c0bd880u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd8dau,2);
goto P_0c0bd882;
P_0c0bd882: /* original 9029, guest PC 0x0c0bd882 */
if(!s->budget--) { s->failed_pc=0x0c0bd882u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd8d8u,2);
goto P_0c0bd884;
P_0c0bd884: /* original 4e0b, guest PC 0x0c0bd884 */
if(!s->budget--) { s->failed_pc=0x0c0bd884u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd888u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd888u) { target=s->pc; goto dispatch; }
goto P_0c0bd888;
P_0c0bd886: /* original 05de, guest PC 0x0c0bd886 */
if(!s->budget--) { s->failed_pc=0x0c0bd886u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd888;
P_0c0bd888: /* original 9429, guest PC 0x0c0bd888 */
if(!s->budget--) { s->failed_pc=0x0c0bd888u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd8deu,2);
goto P_0c0bd88a;
P_0c0bd88a: /* original 9027, guest PC 0x0c0bd88a */
if(!s->budget--) { s->failed_pc=0x0c0bd88au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd8dcu,2);
goto P_0c0bd88c;
P_0c0bd88c: /* original 4e0b, guest PC 0x0c0bd88c */
if(!s->budget--) { s->failed_pc=0x0c0bd88cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd890u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd890u) { target=s->pc; goto dispatch; }
goto P_0c0bd890;
P_0c0bd88e: /* original 05de, guest PC 0x0c0bd88e */
if(!s->budget--) { s->failed_pc=0x0c0bd88eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd890;
P_0c0bd890: /* original 9427, guest PC 0x0c0bd890 */
if(!s->budget--) { s->failed_pc=0x0c0bd890u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd8e2u,2);
goto P_0c0bd892;
P_0c0bd892: /* original 9025, guest PC 0x0c0bd892 */
if(!s->budget--) { s->failed_pc=0x0c0bd892u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd8e0u,2);
goto P_0c0bd894;
P_0c0bd894: /* original 4e0b, guest PC 0x0c0bd894 */
if(!s->budget--) { s->failed_pc=0x0c0bd894u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd898u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd898u) { target=s->pc; goto dispatch; }
goto P_0c0bd898;
P_0c0bd896: /* original 05de, guest PC 0x0c0bd896 */
if(!s->budget--) { s->failed_pc=0x0c0bd896u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd898;
P_0c0bd898: /* original 9425, guest PC 0x0c0bd898 */
if(!s->budget--) { s->failed_pc=0x0c0bd898u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd8e6u,2);
goto P_0c0bd89a;
P_0c0bd89a: /* original 9023, guest PC 0x0c0bd89a */
if(!s->budget--) { s->failed_pc=0x0c0bd89au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd8e4u,2);
goto P_0c0bd89c;
P_0c0bd89c: /* original 4e0b, guest PC 0x0c0bd89c */
if(!s->budget--) { s->failed_pc=0x0c0bd89cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd8a0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd8a0u) { target=s->pc; goto dispatch; }
goto P_0c0bd8a0;
P_0c0bd89e: /* original 05de, guest PC 0x0c0bd89e */
if(!s->budget--) { s->failed_pc=0x0c0bd89eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd8a0;
P_0c0bd8a0: /* original 9423, guest PC 0x0c0bd8a0 */
if(!s->budget--) { s->failed_pc=0x0c0bd8a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd8eau,2);
goto P_0c0bd8a2;
P_0c0bd8a2: /* original 9021, guest PC 0x0c0bd8a2 */
if(!s->budget--) { s->failed_pc=0x0c0bd8a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd8e8u,2);
goto P_0c0bd8a4;
P_0c0bd8a4: /* original 4e0b, guest PC 0x0c0bd8a4 */
if(!s->budget--) { s->failed_pc=0x0c0bd8a4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd8a8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd8a8u) { target=s->pc; goto dispatch; }
goto P_0c0bd8a8;
P_0c0bd8a6: /* original 05de, guest PC 0x0c0bd8a6 */
if(!s->budget--) { s->failed_pc=0x0c0bd8a6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd8a8;
P_0c0bd8a8: /* original 9421, guest PC 0x0c0bd8a8 */
if(!s->budget--) { s->failed_pc=0x0c0bd8a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd8eeu,2);
goto P_0c0bd8aa;
P_0c0bd8aa: /* original 901f, guest PC 0x0c0bd8aa */
if(!s->budget--) { s->failed_pc=0x0c0bd8aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd8ecu,2);
goto P_0c0bd8ac;
P_0c0bd8ac: /* original 4e0b, guest PC 0x0c0bd8ac */
if(!s->budget--) { s->failed_pc=0x0c0bd8acu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd8b0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd8b0u) { target=s->pc; goto dispatch; }
goto P_0c0bd8b0;
P_0c0bd8ae: /* original 05de, guest PC 0x0c0bd8ae */
if(!s->budget--) { s->failed_pc=0x0c0bd8aeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd8b0;
P_0c0bd8b0: /* original 941f, guest PC 0x0c0bd8b0 */
if(!s->budget--) { s->failed_pc=0x0c0bd8b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd8f2u,2);
goto P_0c0bd8b2;
P_0c0bd8b2: /* original 901d, guest PC 0x0c0bd8b2 */
if(!s->budget--) { s->failed_pc=0x0c0bd8b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd8f0u,2);
goto P_0c0bd8b4;
P_0c0bd8b4: /* original 4e0b, guest PC 0x0c0bd8b4 */
if(!s->budget--) { s->failed_pc=0x0c0bd8b4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd8b8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd8b8u) { target=s->pc; goto dispatch; }
goto P_0c0bd8b8;
P_0c0bd8b6: /* original 05de, guest PC 0x0c0bd8b6 */
if(!s->budget--) { s->failed_pc=0x0c0bd8b6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd8b8;
P_0c0bd8b8: /* original 7f08, guest PC 0x0c0bd8b8 */
if(!s->budget--) { s->failed_pc=0x0c0bd8b8u; return 0; }
r[15]+=0x00000008u;
goto P_0c0bd8ba;
P_0c0bd8ba: /* original 4f26, guest PC 0x0c0bd8ba */
if(!s->budget--) { s->failed_pc=0x0c0bd8bau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0bd8bc;
P_0c0bd8bc: /* original 69f6, guest PC 0x0c0bd8bc */
if(!s->budget--) { s->failed_pc=0x0c0bd8bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0bd8be;
P_0c0bd8be: /* original 6af6, guest PC 0x0c0bd8be */
if(!s->budget--) { s->failed_pc=0x0c0bd8beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0bd8c0;
P_0c0bd8c0: /* original 6bf6, guest PC 0x0c0bd8c0 */
if(!s->budget--) { s->failed_pc=0x0c0bd8c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0bd8c2;
P_0c0bd8c2: /* original 6cf6, guest PC 0x0c0bd8c2 */
if(!s->budget--) { s->failed_pc=0x0c0bd8c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0bd8c4;
P_0c0bd8c4: /* original 6df6, guest PC 0x0c0bd8c4 */
if(!s->budget--) { s->failed_pc=0x0c0bd8c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0bd8c6;
P_0c0bd8c6: /* original 000b, guest PC 0x0c0bd8c6 */
if(!s->budget--) { s->failed_pc=0x0c0bd8c6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0bd8c8: /* original 6ef6, guest PC 0x0c0bd8c8 */
if(!s->budget--) { s->failed_pc=0x0c0bd8c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0bd8cau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bd8cau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
