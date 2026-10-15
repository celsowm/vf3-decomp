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
int vf3_clip_strip_writers_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0572e0u: goto P_0c0572e0;
case 0x0c0572e2u: goto P_0c0572e2;
case 0x0c0572e4u: goto P_0c0572e4;
case 0x0c0572e6u: goto P_0c0572e6;
case 0x0c0572e8u: goto P_0c0572e8;
case 0x0c0572eau: goto P_0c0572ea;
case 0x0c0572ecu: goto P_0c0572ec;
case 0x0c0572eeu: goto P_0c0572ee;
case 0x0c0572f0u: goto P_0c0572f0;
case 0x0c0572f2u: goto P_0c0572f2;
case 0x0c0572f4u: goto P_0c0572f4;
case 0x0c0572f6u: goto P_0c0572f6;
case 0x0c0572f8u: goto P_0c0572f8;
case 0x0c0572fau: goto P_0c0572fa;
case 0x0c0572fcu: goto P_0c0572fc;
case 0x0c0572feu: goto P_0c0572fe;
case 0x0c057300u: goto P_0c057300;
case 0x0c057302u: goto P_0c057302;
case 0x0c057320u: goto P_0c057320;
case 0x0c057322u: goto P_0c057322;
case 0x0c057324u: goto P_0c057324;
case 0x0c057326u: goto P_0c057326;
case 0x0c057328u: goto P_0c057328;
case 0x0c05732au: goto P_0c05732a;
case 0x0c05732cu: goto P_0c05732c;
case 0x0c05732eu: goto P_0c05732e;
case 0x0c057330u: goto P_0c057330;
case 0x0c057332u: goto P_0c057332;
case 0x0c057334u: goto P_0c057334;
case 0x0c057336u: goto P_0c057336;
case 0x0c057338u: goto P_0c057338;
case 0x0c05733au: goto P_0c05733a;
case 0x0c05733cu: goto P_0c05733c;
case 0x0c05733eu: goto P_0c05733e;
case 0x0c057340u: goto P_0c057340;
case 0x0c057342u: goto P_0c057342;
case 0x0c057344u: goto P_0c057344;
case 0x0c057346u: goto P_0c057346;
case 0x0c057360u: goto P_0c057360;
case 0x0c057362u: goto P_0c057362;
case 0x0c057364u: goto P_0c057364;
case 0x0c057366u: goto P_0c057366;
case 0x0c057368u: goto P_0c057368;
case 0x0c05736au: goto P_0c05736a;
case 0x0c05736cu: goto P_0c05736c;
case 0x0c05736eu: goto P_0c05736e;
case 0x0c057370u: goto P_0c057370;
case 0x0c057372u: goto P_0c057372;
case 0x0c057374u: goto P_0c057374;
case 0x0c057376u: goto P_0c057376;
case 0x0c057378u: goto P_0c057378;
case 0x0c05737au: goto P_0c05737a;
case 0x0c05737cu: goto P_0c05737c;
case 0x0c05737eu: goto P_0c05737e;
case 0x0c057380u: goto P_0c057380;
case 0x0c057382u: goto P_0c057382;
case 0x0c057384u: goto P_0c057384;
case 0x0c057386u: goto P_0c057386;
case 0x0c0573a0u: goto P_0c0573a0;
case 0x0c0573a2u: goto P_0c0573a2;
case 0x0c0573a4u: goto P_0c0573a4;
case 0x0c0573a6u: goto P_0c0573a6;
case 0x0c0573a8u: goto P_0c0573a8;
case 0x0c0573aau: goto P_0c0573aa;
case 0x0c0573acu: goto P_0c0573ac;
case 0x0c0573aeu: goto P_0c0573ae;
case 0x0c0573b0u: goto P_0c0573b0;
case 0x0c0573b2u: goto P_0c0573b2;
case 0x0c0573b4u: goto P_0c0573b4;
case 0x0c0573b6u: goto P_0c0573b6;
case 0x0c0573b8u: goto P_0c0573b8;
case 0x0c0573bau: goto P_0c0573ba;
case 0x0c0573bcu: goto P_0c0573bc;
case 0x0c0573beu: goto P_0c0573be;
case 0x0c0573c0u: goto P_0c0573c0;
case 0x0c0573c2u: goto P_0c0573c2;
case 0x0c0573c4u: goto P_0c0573c4;
case 0x0c0573c6u: goto P_0c0573c6;
case 0x0c0573c8u: goto P_0c0573c8;
case 0x0c0573cau: goto P_0c0573ca;
case 0x0c0573ccu: goto P_0c0573cc;
case 0x0c0573ceu: goto P_0c0573ce;
case 0x0c0573d0u: goto P_0c0573d0;
case 0x0c0573e0u: goto P_0c0573e0;
case 0x0c0573e2u: goto P_0c0573e2;
case 0x0c0573e4u: goto P_0c0573e4;
case 0x0c0573e6u: goto P_0c0573e6;
case 0x0c0573e8u: goto P_0c0573e8;
case 0x0c0573eau: goto P_0c0573ea;
case 0x0c0573ecu: goto P_0c0573ec;
case 0x0c0573eeu: goto P_0c0573ee;
case 0x0c0573f0u: goto P_0c0573f0;
case 0x0c0573f2u: goto P_0c0573f2;
case 0x0c0573f4u: goto P_0c0573f4;
case 0x0c0573f6u: goto P_0c0573f6;
case 0x0c0573f8u: goto P_0c0573f8;
case 0x0c0573fau: goto P_0c0573fa;
case 0x0c0573fcu: goto P_0c0573fc;
case 0x0c0573feu: goto P_0c0573fe;
case 0x0c057400u: goto P_0c057400;
case 0x0c057402u: goto P_0c057402;
case 0x0c057404u: goto P_0c057404;
case 0x0c057406u: goto P_0c057406;
case 0x0c057408u: goto P_0c057408;
case 0x0c05740au: goto P_0c05740a;
case 0x0c05740cu: goto P_0c05740c;
case 0x0c05740eu: goto P_0c05740e;
case 0x0c057410u: goto P_0c057410;
case 0x0c057412u: goto P_0c057412;
case 0x0c057414u: goto P_0c057414;
case 0x0c057420u: goto P_0c057420;
case 0x0c057422u: goto P_0c057422;
case 0x0c057424u: goto P_0c057424;
case 0x0c057426u: goto P_0c057426;
case 0x0c057428u: goto P_0c057428;
case 0x0c05742au: goto P_0c05742a;
case 0x0c05742cu: goto P_0c05742c;
case 0x0c05742eu: goto P_0c05742e;
case 0x0c057430u: goto P_0c057430;
case 0x0c057432u: goto P_0c057432;
case 0x0c057434u: goto P_0c057434;
case 0x0c057436u: goto P_0c057436;
case 0x0c057438u: goto P_0c057438;
case 0x0c05743au: goto P_0c05743a;
case 0x0c05743cu: goto P_0c05743c;
case 0x0c05743eu: goto P_0c05743e;
case 0x0c057440u: goto P_0c057440;
case 0x0c057442u: goto P_0c057442;
case 0x0c057444u: goto P_0c057444;
case 0x0c057446u: goto P_0c057446;
case 0x0c057448u: goto P_0c057448;
case 0x0c05744au: goto P_0c05744a;
case 0x0c05744cu: goto P_0c05744c;
case 0x0c05744eu: goto P_0c05744e;
case 0x0c057450u: goto P_0c057450;
case 0x0c057452u: goto P_0c057452;
case 0x0c057454u: goto P_0c057454;
case 0x0c057680u: goto P_0c057680;
case 0x0c057682u: goto P_0c057682;
case 0x0c057684u: goto P_0c057684;
case 0x0c057686u: goto P_0c057686;
case 0x0c057688u: goto P_0c057688;
case 0x0c05768au: goto P_0c05768a;
case 0x0c05768cu: goto P_0c05768c;
case 0x0c05768eu: goto P_0c05768e;
case 0x0c057690u: goto P_0c057690;
case 0x0c057692u: goto P_0c057692;
case 0x0c057694u: goto P_0c057694;
case 0x0c057696u: goto P_0c057696;
case 0x0c057698u: goto P_0c057698;
case 0x0c05769au: goto P_0c05769a;
case 0x0c05769cu: goto P_0c05769c;
case 0x0c05769eu: goto P_0c05769e;
case 0x0c0576a0u: goto P_0c0576a0;
case 0x0c0576a2u: goto P_0c0576a2;
case 0x0c0576a4u: goto P_0c0576a4;
case 0x0c0576a6u: goto P_0c0576a6;
case 0x0c0576a8u: goto P_0c0576a8;
case 0x0c0576aau: goto P_0c0576aa;
case 0x0c0576acu: goto P_0c0576ac;
case 0x0c0576aeu: goto P_0c0576ae;
case 0x0c0576b0u: goto P_0c0576b0;
case 0x0c0576b2u: goto P_0c0576b2;
case 0x0c0576b4u: goto P_0c0576b4;
case 0x0c0576b6u: goto P_0c0576b6;
case 0x0c0576c0u: goto P_0c0576c0;
case 0x0c0576c2u: goto P_0c0576c2;
case 0x0c0576c4u: goto P_0c0576c4;
case 0x0c0576c6u: goto P_0c0576c6;
case 0x0c0576c8u: goto P_0c0576c8;
case 0x0c0576cau: goto P_0c0576ca;
case 0x0c0576ccu: goto P_0c0576cc;
case 0x0c0576ceu: goto P_0c0576ce;
case 0x0c0576d0u: goto P_0c0576d0;
case 0x0c0576d2u: goto P_0c0576d2;
case 0x0c0576d4u: goto P_0c0576d4;
case 0x0c0576d6u: goto P_0c0576d6;
case 0x0c0576d8u: goto P_0c0576d8;
case 0x0c0576dau: goto P_0c0576da;
case 0x0c0576dcu: goto P_0c0576dc;
case 0x0c0576deu: goto P_0c0576de;
case 0x0c0576e0u: goto P_0c0576e0;
case 0x0c0576e2u: goto P_0c0576e2;
case 0x0c0576e4u: goto P_0c0576e4;
case 0x0c0576e6u: goto P_0c0576e6;
case 0x0c0576e8u: goto P_0c0576e8;
case 0x0c0576eau: goto P_0c0576ea;
case 0x0c0576ecu: goto P_0c0576ec;
case 0x0c0576eeu: goto P_0c0576ee;
case 0x0c0576f0u: goto P_0c0576f0;
case 0x0c0576f2u: goto P_0c0576f2;
case 0x0c0576f4u: goto P_0c0576f4;
case 0x0c0576f6u: goto P_0c0576f6;
case 0x0c0576f8u: goto P_0c0576f8;
case 0x0c0576fau: goto P_0c0576fa;
case 0x0c057700u: goto P_0c057700;
case 0x0c057702u: goto P_0c057702;
case 0x0c057704u: goto P_0c057704;
case 0x0c057706u: goto P_0c057706;
case 0x0c057708u: goto P_0c057708;
case 0x0c05770au: goto P_0c05770a;
case 0x0c05770cu: goto P_0c05770c;
case 0x0c05770eu: goto P_0c05770e;
case 0x0c057710u: goto P_0c057710;
case 0x0c057712u: goto P_0c057712;
case 0x0c057714u: goto P_0c057714;
case 0x0c057716u: goto P_0c057716;
case 0x0c057718u: goto P_0c057718;
case 0x0c05771au: goto P_0c05771a;
case 0x0c05771cu: goto P_0c05771c;
case 0x0c05771eu: goto P_0c05771e;
case 0x0c057720u: goto P_0c057720;
case 0x0c057722u: goto P_0c057722;
case 0x0c057724u: goto P_0c057724;
case 0x0c057726u: goto P_0c057726;
case 0x0c057728u: goto P_0c057728;
case 0x0c05772au: goto P_0c05772a;
case 0x0c05772cu: goto P_0c05772c;
case 0x0c05772eu: goto P_0c05772e;
case 0x0c057730u: goto P_0c057730;
case 0x0c057732u: goto P_0c057732;
case 0x0c057734u: goto P_0c057734;
case 0x0c057736u: goto P_0c057736;
case 0x0c057738u: goto P_0c057738;
case 0x0c05773au: goto P_0c05773a;
case 0x0c057740u: goto P_0c057740;
case 0x0c057742u: goto P_0c057742;
case 0x0c057744u: goto P_0c057744;
case 0x0c057746u: goto P_0c057746;
case 0x0c057748u: goto P_0c057748;
case 0x0c05774au: goto P_0c05774a;
case 0x0c05774cu: goto P_0c05774c;
case 0x0c05774eu: goto P_0c05774e;
case 0x0c057750u: goto P_0c057750;
case 0x0c057752u: goto P_0c057752;
case 0x0c057754u: goto P_0c057754;
case 0x0c057756u: goto P_0c057756;
case 0x0c057758u: goto P_0c057758;
case 0x0c05775au: goto P_0c05775a;
case 0x0c05775cu: goto P_0c05775c;
case 0x0c05775eu: goto P_0c05775e;
case 0x0c057760u: goto P_0c057760;
case 0x0c057762u: goto P_0c057762;
case 0x0c057764u: goto P_0c057764;
case 0x0c057766u: goto P_0c057766;
case 0x0c057768u: goto P_0c057768;
case 0x0c05776au: goto P_0c05776a;
case 0x0c05776cu: goto P_0c05776c;
case 0x0c05776eu: goto P_0c05776e;
case 0x0c057770u: goto P_0c057770;
case 0x0c057772u: goto P_0c057772;
case 0x0c057774u: goto P_0c057774;
case 0x0c057776u: goto P_0c057776;
case 0x0c057778u: goto P_0c057778;
case 0x0c05777au: goto P_0c05777a;
case 0x0c05777cu: goto P_0c05777c;
case 0x0c05777eu: goto P_0c05777e;
case 0x0c057780u: goto P_0c057780;
case 0x0c057782u: goto P_0c057782;
case 0x0c057784u: goto P_0c057784;
case 0x0c0577a0u: goto P_0c0577a0;
case 0x0c0577a2u: goto P_0c0577a2;
case 0x0c0577a4u: goto P_0c0577a4;
case 0x0c0577a6u: goto P_0c0577a6;
case 0x0c0577a8u: goto P_0c0577a8;
case 0x0c0577aau: goto P_0c0577aa;
case 0x0c0577acu: goto P_0c0577ac;
case 0x0c0577aeu: goto P_0c0577ae;
case 0x0c0577b0u: goto P_0c0577b0;
case 0x0c0577b2u: goto P_0c0577b2;
case 0x0c0577b4u: goto P_0c0577b4;
case 0x0c0577b6u: goto P_0c0577b6;
case 0x0c0577b8u: goto P_0c0577b8;
case 0x0c0577bau: goto P_0c0577ba;
case 0x0c0577bcu: goto P_0c0577bc;
case 0x0c0577beu: goto P_0c0577be;
case 0x0c0577c0u: goto P_0c0577c0;
case 0x0c0577c2u: goto P_0c0577c2;
case 0x0c0577c4u: goto P_0c0577c4;
case 0x0c0577c6u: goto P_0c0577c6;
case 0x0c0577c8u: goto P_0c0577c8;
case 0x0c0577cau: goto P_0c0577ca;
case 0x0c0577ccu: goto P_0c0577cc;
case 0x0c0577ceu: goto P_0c0577ce;
case 0x0c0577d0u: goto P_0c0577d0;
case 0x0c0577d2u: goto P_0c0577d2;
case 0x0c0577d4u: goto P_0c0577d4;
case 0x0c0577d6u: goto P_0c0577d6;
case 0x0c0577d8u: goto P_0c0577d8;
case 0x0c0577dau: goto P_0c0577da;
case 0x0c0577dcu: goto P_0c0577dc;
case 0x0c0577deu: goto P_0c0577de;
case 0x0c0577e0u: goto P_0c0577e0;
case 0x0c0577e2u: goto P_0c0577e2;
case 0x0c0577e4u: goto P_0c0577e4;
case 0x0c0577e6u: goto P_0c0577e6;
case 0x0c0577e8u: goto P_0c0577e8;
case 0x0c057800u: goto P_0c057800;
case 0x0c057802u: goto P_0c057802;
case 0x0c057804u: goto P_0c057804;
case 0x0c057806u: goto P_0c057806;
case 0x0c057808u: goto P_0c057808;
case 0x0c05780au: goto P_0c05780a;
case 0x0c05780cu: goto P_0c05780c;
case 0x0c05780eu: goto P_0c05780e;
case 0x0c057810u: goto P_0c057810;
case 0x0c057812u: goto P_0c057812;
case 0x0c057814u: goto P_0c057814;
case 0x0c057816u: goto P_0c057816;
case 0x0c057818u: goto P_0c057818;
case 0x0c05781au: goto P_0c05781a;
case 0x0c05781cu: goto P_0c05781c;
case 0x0c05781eu: goto P_0c05781e;
case 0x0c057820u: goto P_0c057820;
case 0x0c057822u: goto P_0c057822;
case 0x0c057824u: goto P_0c057824;
case 0x0c057826u: goto P_0c057826;
case 0x0c057828u: goto P_0c057828;
case 0x0c05782au: goto P_0c05782a;
case 0x0c05782cu: goto P_0c05782c;
case 0x0c05782eu: goto P_0c05782e;
case 0x0c057830u: goto P_0c057830;
case 0x0c057832u: goto P_0c057832;
case 0x0c057834u: goto P_0c057834;
case 0x0c057836u: goto P_0c057836;
case 0x0c057838u: goto P_0c057838;
case 0x0c05783au: goto P_0c05783a;
case 0x0c05783cu: goto P_0c05783c;
case 0x0c05783eu: goto P_0c05783e;
case 0x0c057840u: goto P_0c057840;
case 0x0c057842u: goto P_0c057842;
case 0x0c057844u: goto P_0c057844;
case 0x0c057846u: goto P_0c057846;
case 0x0c057848u: goto P_0c057848;
case 0x0c057a60u: goto P_0c057a60;
case 0x0c057a62u: goto P_0c057a62;
case 0x0c057a64u: goto P_0c057a64;
case 0x0c057a66u: goto P_0c057a66;
case 0x0c057a68u: goto P_0c057a68;
case 0x0c057a6au: goto P_0c057a6a;
case 0x0c057a6cu: goto P_0c057a6c;
case 0x0c057a6eu: goto P_0c057a6e;
case 0x0c057a70u: goto P_0c057a70;
case 0x0c057a72u: goto P_0c057a72;
case 0x0c057a74u: goto P_0c057a74;
case 0x0c057a76u: goto P_0c057a76;
case 0x0c057a78u: goto P_0c057a78;
case 0x0c057a7au: goto P_0c057a7a;
case 0x0c057a7cu: goto P_0c057a7c;
case 0x0c057a7eu: goto P_0c057a7e;
case 0x0c057a80u: goto P_0c057a80;
case 0x0c057aa0u: goto P_0c057aa0;
case 0x0c057aa2u: goto P_0c057aa2;
case 0x0c057aa4u: goto P_0c057aa4;
case 0x0c057aa6u: goto P_0c057aa6;
case 0x0c057aa8u: goto P_0c057aa8;
case 0x0c057aaau: goto P_0c057aaa;
case 0x0c057aacu: goto P_0c057aac;
case 0x0c057aaeu: goto P_0c057aae;
case 0x0c057ab0u: goto P_0c057ab0;
case 0x0c057ab2u: goto P_0c057ab2;
case 0x0c057ab4u: goto P_0c057ab4;
case 0x0c057ab6u: goto P_0c057ab6;
case 0x0c057ab8u: goto P_0c057ab8;
case 0x0c057abau: goto P_0c057aba;
case 0x0c057abcu: goto P_0c057abc;
case 0x0c057abeu: goto P_0c057abe;
case 0x0c057ac0u: goto P_0c057ac0;
case 0x0c057ac2u: goto P_0c057ac2;
case 0x0c057ac4u: goto P_0c057ac4;
case 0x0c057ae0u: goto P_0c057ae0;
case 0x0c057ae2u: goto P_0c057ae2;
case 0x0c057ae4u: goto P_0c057ae4;
case 0x0c057ae6u: goto P_0c057ae6;
case 0x0c057ae8u: goto P_0c057ae8;
case 0x0c057aeau: goto P_0c057aea;
case 0x0c057aecu: goto P_0c057aec;
case 0x0c057aeeu: goto P_0c057aee;
case 0x0c057af0u: goto P_0c057af0;
case 0x0c057af2u: goto P_0c057af2;
case 0x0c057af4u: goto P_0c057af4;
case 0x0c057af6u: goto P_0c057af6;
case 0x0c057af8u: goto P_0c057af8;
case 0x0c057afau: goto P_0c057afa;
case 0x0c057afcu: goto P_0c057afc;
case 0x0c057afeu: goto P_0c057afe;
case 0x0c057b00u: goto P_0c057b00;
case 0x0c057b02u: goto P_0c057b02;
case 0x0c057b04u: goto P_0c057b04;
case 0x0c057b20u: goto P_0c057b20;
case 0x0c057b22u: goto P_0c057b22;
case 0x0c057b24u: goto P_0c057b24;
case 0x0c057b26u: goto P_0c057b26;
case 0x0c057b28u: goto P_0c057b28;
case 0x0c057b2au: goto P_0c057b2a;
case 0x0c057b2cu: goto P_0c057b2c;
case 0x0c057b2eu: goto P_0c057b2e;
case 0x0c057b30u: goto P_0c057b30;
case 0x0c057b32u: goto P_0c057b32;
case 0x0c057b34u: goto P_0c057b34;
case 0x0c057b36u: goto P_0c057b36;
case 0x0c057b38u: goto P_0c057b38;
case 0x0c057b3au: goto P_0c057b3a;
case 0x0c057b3cu: goto P_0c057b3c;
case 0x0c057b3eu: goto P_0c057b3e;
case 0x0c057b40u: goto P_0c057b40;
case 0x0c057b42u: goto P_0c057b42;
case 0x0c057b44u: goto P_0c057b44;
case 0x0c057b46u: goto P_0c057b46;
case 0x0c057b48u: goto P_0c057b48;
case 0x0c057b4au: goto P_0c057b4a;
case 0x0c057b4cu: goto P_0c057b4c;
case 0x0c057b4eu: goto P_0c057b4e;
case 0x0c057b60u: goto P_0c057b60;
case 0x0c057b62u: goto P_0c057b62;
case 0x0c057b64u: goto P_0c057b64;
case 0x0c057b66u: goto P_0c057b66;
case 0x0c057b68u: goto P_0c057b68;
case 0x0c057b6au: goto P_0c057b6a;
case 0x0c057b6cu: goto P_0c057b6c;
case 0x0c057b6eu: goto P_0c057b6e;
case 0x0c057b70u: goto P_0c057b70;
case 0x0c057b72u: goto P_0c057b72;
case 0x0c057b74u: goto P_0c057b74;
case 0x0c057b76u: goto P_0c057b76;
case 0x0c057b78u: goto P_0c057b78;
case 0x0c057b7au: goto P_0c057b7a;
case 0x0c057b7cu: goto P_0c057b7c;
case 0x0c057b7eu: goto P_0c057b7e;
case 0x0c057b80u: goto P_0c057b80;
case 0x0c057b82u: goto P_0c057b82;
case 0x0c057b84u: goto P_0c057b84;
case 0x0c057b86u: goto P_0c057b86;
case 0x0c057b88u: goto P_0c057b88;
case 0x0c057b8au: goto P_0c057b8a;
case 0x0c057b8cu: goto P_0c057b8c;
case 0x0c057b8eu: goto P_0c057b8e;
case 0x0c057b90u: goto P_0c057b90;
case 0x0c057b92u: goto P_0c057b92;
case 0x0c057ba0u: goto P_0c057ba0;
case 0x0c057ba2u: goto P_0c057ba2;
case 0x0c057ba4u: goto P_0c057ba4;
case 0x0c057ba6u: goto P_0c057ba6;
case 0x0c057ba8u: goto P_0c057ba8;
case 0x0c057baau: goto P_0c057baa;
case 0x0c057bacu: goto P_0c057bac;
case 0x0c057baeu: goto P_0c057bae;
case 0x0c057bb0u: goto P_0c057bb0;
case 0x0c057bb2u: goto P_0c057bb2;
case 0x0c057bb4u: goto P_0c057bb4;
case 0x0c057bb6u: goto P_0c057bb6;
case 0x0c057bb8u: goto P_0c057bb8;
case 0x0c057bbau: goto P_0c057bba;
case 0x0c057bbcu: goto P_0c057bbc;
case 0x0c057bbeu: goto P_0c057bbe;
case 0x0c057bc0u: goto P_0c057bc0;
case 0x0c057bc2u: goto P_0c057bc2;
case 0x0c057bc4u: goto P_0c057bc4;
case 0x0c057bc6u: goto P_0c057bc6;
case 0x0c057bc8u: goto P_0c057bc8;
case 0x0c057bcau: goto P_0c057bca;
case 0x0c057bccu: goto P_0c057bcc;
case 0x0c057bceu: goto P_0c057bce;
case 0x0c057bd0u: goto P_0c057bd0;
case 0x0c057bd2u: goto P_0c057bd2;
case 0x0c057e60u: goto P_0c057e60;
case 0x0c057e62u: goto P_0c057e62;
case 0x0c057e64u: goto P_0c057e64;
case 0x0c057e66u: goto P_0c057e66;
case 0x0c057e68u: goto P_0c057e68;
case 0x0c057e6au: goto P_0c057e6a;
case 0x0c057e6cu: goto P_0c057e6c;
case 0x0c057e6eu: goto P_0c057e6e;
case 0x0c057e70u: goto P_0c057e70;
case 0x0c057e72u: goto P_0c057e72;
case 0x0c057e74u: goto P_0c057e74;
case 0x0c057e76u: goto P_0c057e76;
case 0x0c057e78u: goto P_0c057e78;
case 0x0c057e7au: goto P_0c057e7a;
case 0x0c057e7cu: goto P_0c057e7c;
case 0x0c057e7eu: goto P_0c057e7e;
case 0x0c057e80u: goto P_0c057e80;
case 0x0c057e82u: goto P_0c057e82;
case 0x0c057e84u: goto P_0c057e84;
case 0x0c057e86u: goto P_0c057e86;
case 0x0c057e88u: goto P_0c057e88;
case 0x0c057e8au: goto P_0c057e8a;
case 0x0c057e8cu: goto P_0c057e8c;
case 0x0c057e8eu: goto P_0c057e8e;
case 0x0c057e90u: goto P_0c057e90;
case 0x0c057e92u: goto P_0c057e92;
case 0x0c057e94u: goto P_0c057e94;
case 0x0c057e96u: goto P_0c057e96;
case 0x0c057e98u: goto P_0c057e98;
case 0x0c057e9au: goto P_0c057e9a;
case 0x0c057e9cu: goto P_0c057e9c;
case 0x0c057e9eu: goto P_0c057e9e;
case 0x0c057ea0u: goto P_0c057ea0;
case 0x0c057ea2u: goto P_0c057ea2;
case 0x0c057ea4u: goto P_0c057ea4;
case 0x0c057ea6u: goto P_0c057ea6;
case 0x0c057ea8u: goto P_0c057ea8;
case 0x0c057eaau: goto P_0c057eaa;
case 0x0c057eacu: goto P_0c057eac;
case 0x0c057eaeu: goto P_0c057eae;
case 0x0c057eb0u: goto P_0c057eb0;
case 0x0c057eb2u: goto P_0c057eb2;
case 0x0c057eb4u: goto P_0c057eb4;
case 0x0c057eb6u: goto P_0c057eb6;
case 0x0c057eb8u: goto P_0c057eb8;
case 0x0c057ebau: goto P_0c057eba;
case 0x0c057ebcu: goto P_0c057ebc;
case 0x0c057ebeu: goto P_0c057ebe;
case 0x0c057ec0u: goto P_0c057ec0;
case 0x0c057ec2u: goto P_0c057ec2;
case 0x0c057ec4u: goto P_0c057ec4;
case 0x0c057ec6u: goto P_0c057ec6;
case 0x0c057ee0u: goto P_0c057ee0;
case 0x0c057ee2u: goto P_0c057ee2;
case 0x0c057ee4u: goto P_0c057ee4;
case 0x0c057ee6u: goto P_0c057ee6;
case 0x0c057ee8u: goto P_0c057ee8;
case 0x0c057eeau: goto P_0c057eea;
case 0x0c057eecu: goto P_0c057eec;
case 0x0c057eeeu: goto P_0c057eee;
case 0x0c057ef0u: goto P_0c057ef0;
case 0x0c057ef2u: goto P_0c057ef2;
case 0x0c057ef4u: goto P_0c057ef4;
case 0x0c057ef6u: goto P_0c057ef6;
case 0x0c057ef8u: goto P_0c057ef8;
case 0x0c057efau: goto P_0c057efa;
case 0x0c057efcu: goto P_0c057efc;
case 0x0c057efeu: goto P_0c057efe;
case 0x0c057f00u: goto P_0c057f00;
case 0x0c057f02u: goto P_0c057f02;
case 0x0c057f04u: goto P_0c057f04;
case 0x0c057f06u: goto P_0c057f06;
case 0x0c057f08u: goto P_0c057f08;
case 0x0c057f0au: goto P_0c057f0a;
case 0x0c057f0cu: goto P_0c057f0c;
case 0x0c057f0eu: goto P_0c057f0e;
case 0x0c057f10u: goto P_0c057f10;
case 0x0c057f18u: goto P_0c057f18;
case 0x0c057f1au: goto P_0c057f1a;
case 0x0c057f1cu: goto P_0c057f1c;
case 0x0c057f1eu: goto P_0c057f1e;
case 0x0c057f20u: goto P_0c057f20;
case 0x0c057f22u: goto P_0c057f22;
case 0x0c057f24u: goto P_0c057f24;
case 0x0c057f26u: goto P_0c057f26;
case 0x0c057f28u: goto P_0c057f28;
case 0x0c057f2au: goto P_0c057f2a;
case 0x0c057f2cu: goto P_0c057f2c;
case 0x0c057f2eu: goto P_0c057f2e;
case 0x0c057f30u: goto P_0c057f30;
case 0x0c057f32u: goto P_0c057f32;
case 0x0c057f34u: goto P_0c057f34;
case 0x0c057f36u: goto P_0c057f36;
case 0x0c057f38u: goto P_0c057f38;
case 0x0c057f3au: goto P_0c057f3a;
case 0x0c057f3cu: goto P_0c057f3c;
case 0x0c057f3eu: goto P_0c057f3e;
case 0x0c057f40u: goto P_0c057f40;
case 0x0c057f42u: goto P_0c057f42;
case 0x0c057f44u: goto P_0c057f44;
case 0x0c057f46u: goto P_0c057f46;
case 0x0c057f48u: goto P_0c057f48;
case 0x0c057f4au: goto P_0c057f4a;
case 0x0c057f50u: goto P_0c057f50;
case 0x0c057f52u: goto P_0c057f52;
case 0x0c057f54u: goto P_0c057f54;
case 0x0c057f56u: goto P_0c057f56;
case 0x0c057f58u: goto P_0c057f58;
case 0x0c057f5au: goto P_0c057f5a;
case 0x0c057f5cu: goto P_0c057f5c;
case 0x0c057f5eu: goto P_0c057f5e;
case 0x0c057f60u: goto P_0c057f60;
case 0x0c057f62u: goto P_0c057f62;
case 0x0c057f64u: goto P_0c057f64;
case 0x0c057f66u: goto P_0c057f66;
case 0x0c057f68u: goto P_0c057f68;
case 0x0c057f6au: goto P_0c057f6a;
case 0x0c057f6cu: goto P_0c057f6c;
case 0x0c057f6eu: goto P_0c057f6e;
case 0x0c057f70u: goto P_0c057f70;
case 0x0c057f72u: goto P_0c057f72;
case 0x0c057f74u: goto P_0c057f74;
case 0x0c057f76u: goto P_0c057f76;
case 0x0c057f78u: goto P_0c057f78;
case 0x0c057f7au: goto P_0c057f7a;
case 0x0c057f7cu: goto P_0c057f7c;
case 0x0c057f7eu: goto P_0c057f7e;
case 0x0c057f80u: goto P_0c057f80;
case 0x0c057f82u: goto P_0c057f82;
case 0x0c0581a0u: goto P_0c0581a0;
case 0x0c0581a2u: goto P_0c0581a2;
case 0x0c0581a4u: goto P_0c0581a4;
case 0x0c0581a6u: goto P_0c0581a6;
case 0x0c0581a8u: goto P_0c0581a8;
case 0x0c0581aau: goto P_0c0581aa;
case 0x0c0581acu: goto P_0c0581ac;
case 0x0c0581aeu: goto P_0c0581ae;
case 0x0c0581b0u: goto P_0c0581b0;
case 0x0c0581b2u: goto P_0c0581b2;
case 0x0c0581b4u: goto P_0c0581b4;
case 0x0c0581b6u: goto P_0c0581b6;
case 0x0c0581b8u: goto P_0c0581b8;
case 0x0c0581bau: goto P_0c0581ba;
case 0x0c0581bcu: goto P_0c0581bc;
case 0x0c0581beu: goto P_0c0581be;
case 0x0c0581c0u: goto P_0c0581c0;
case 0x0c0581c2u: goto P_0c0581c2;
case 0x0c0581c4u: goto P_0c0581c4;
case 0x0c0581c6u: goto P_0c0581c6;
case 0x0c0581c8u: goto P_0c0581c8;
case 0x0c0581cau: goto P_0c0581ca;
case 0x0c0581ccu: goto P_0c0581cc;
case 0x0c0581ceu: goto P_0c0581ce;
case 0x0c0581d0u: goto P_0c0581d0;
case 0x0c0581d2u: goto P_0c0581d2;
case 0x0c0581d4u: goto P_0c0581d4;
case 0x0c0581d6u: goto P_0c0581d6;
case 0x0c0581d8u: goto P_0c0581d8;
case 0x0c0581dau: goto P_0c0581da;
case 0x0c0581dcu: goto P_0c0581dc;
case 0x0c0581deu: goto P_0c0581de;
case 0x0c0581e0u: goto P_0c0581e0;
case 0x0c0581e2u: goto P_0c0581e2;
case 0x0c0581e4u: goto P_0c0581e4;
case 0x0c0581e6u: goto P_0c0581e6;
case 0x0c0581e8u: goto P_0c0581e8;
case 0x0c0581eau: goto P_0c0581ea;
case 0x0c0581ecu: goto P_0c0581ec;
case 0x0c0581eeu: goto P_0c0581ee;
case 0x0c0581f0u: goto P_0c0581f0;
case 0x0c0581f2u: goto P_0c0581f2;
case 0x0c0581f4u: goto P_0c0581f4;
case 0x0c0581f6u: goto P_0c0581f6;
case 0x0c0581f8u: goto P_0c0581f8;
case 0x0c0581fau: goto P_0c0581fa;
case 0x0c0581fcu: goto P_0c0581fc;
case 0x0c0581feu: goto P_0c0581fe;
case 0x0c058200u: goto P_0c058200;
case 0x0c058202u: goto P_0c058202;
case 0x0c058204u: goto P_0c058204;
case 0x0c058206u: goto P_0c058206;
case 0x0c058208u: goto P_0c058208;
case 0x0c05820au: goto P_0c05820a;
case 0x0c05820cu: goto P_0c05820c;
case 0x0c05820eu: goto P_0c05820e;
case 0x0c058210u: goto P_0c058210;
case 0x0c058212u: goto P_0c058212;
case 0x0c058214u: goto P_0c058214;
case 0x0c058216u: goto P_0c058216;
case 0x0c058218u: goto P_0c058218;
case 0x0c05821au: goto P_0c05821a;
case 0x0c05821cu: goto P_0c05821c;
case 0x0c05821eu: goto P_0c05821e;
case 0x0c058220u: goto P_0c058220;
case 0x0c058222u: goto P_0c058222;
case 0x0c058224u: goto P_0c058224;
case 0x0c058226u: goto P_0c058226;
case 0x0c058228u: goto P_0c058228;
case 0x0c05822au: goto P_0c05822a;
case 0x0c05822cu: goto P_0c05822c;
case 0x0c05822eu: goto P_0c05822e;
case 0x0c058230u: goto P_0c058230;
case 0x0c058232u: goto P_0c058232;
case 0x0c058234u: goto P_0c058234;
case 0x0c058236u: goto P_0c058236;
case 0x0c058238u: goto P_0c058238;
case 0x0c058240u: goto P_0c058240;
case 0x0c058242u: goto P_0c058242;
case 0x0c058244u: goto P_0c058244;
case 0x0c058246u: goto P_0c058246;
case 0x0c058248u: goto P_0c058248;
case 0x0c05824au: goto P_0c05824a;
case 0x0c05824cu: goto P_0c05824c;
case 0x0c05824eu: goto P_0c05824e;
case 0x0c058250u: goto P_0c058250;
case 0x0c058252u: goto P_0c058252;
case 0x0c058254u: goto P_0c058254;
case 0x0c058256u: goto P_0c058256;
case 0x0c058258u: goto P_0c058258;
case 0x0c05825au: goto P_0c05825a;
case 0x0c05825cu: goto P_0c05825c;
case 0x0c05825eu: goto P_0c05825e;
case 0x0c058260u: goto P_0c058260;
case 0x0c058262u: goto P_0c058262;
case 0x0c058264u: goto P_0c058264;
case 0x0c058266u: goto P_0c058266;
case 0x0c058268u: goto P_0c058268;
case 0x0c05826au: goto P_0c05826a;
case 0x0c05826cu: goto P_0c05826c;
case 0x0c05826eu: goto P_0c05826e;
case 0x0c058270u: goto P_0c058270;
case 0x0c058272u: goto P_0c058272;
case 0x0c058274u: goto P_0c058274;
case 0x0c058276u: goto P_0c058276;
case 0x0c058278u: goto P_0c058278;
case 0x0c05827au: goto P_0c05827a;
case 0x0c05827cu: goto P_0c05827c;
case 0x0c05827eu: goto P_0c05827e;
case 0x0c058280u: goto P_0c058280;
case 0x0c058282u: goto P_0c058282;
case 0x0c058284u: goto P_0c058284;
case 0x0c05828cu: goto P_0c05828c;
case 0x0c05828eu: goto P_0c05828e;
case 0x0c058290u: goto P_0c058290;
case 0x0c058292u: goto P_0c058292;
case 0x0c058294u: goto P_0c058294;
case 0x0c058296u: goto P_0c058296;
case 0x0c058298u: goto P_0c058298;
case 0x0c05829au: goto P_0c05829a;
case 0x0c05829cu: goto P_0c05829c;
case 0x0c05829eu: goto P_0c05829e;
case 0x0c0582a0u: goto P_0c0582a0;
case 0x0c0582a2u: goto P_0c0582a2;
case 0x0c0582a4u: goto P_0c0582a4;
case 0x0c0582a6u: goto P_0c0582a6;
case 0x0c0582a8u: goto P_0c0582a8;
case 0x0c0582aau: goto P_0c0582aa;
case 0x0c0582acu: goto P_0c0582ac;
case 0x0c0582aeu: goto P_0c0582ae;
case 0x0c0582b0u: goto P_0c0582b0;
case 0x0c0582b2u: goto P_0c0582b2;
case 0x0c0582b4u: goto P_0c0582b4;
case 0x0c0582b6u: goto P_0c0582b6;
case 0x0c0582b8u: goto P_0c0582b8;
case 0x0c0582bau: goto P_0c0582ba;
case 0x0c0582bcu: goto P_0c0582bc;
case 0x0c0582beu: goto P_0c0582be;
case 0x0c0582c0u: goto P_0c0582c0;
case 0x0c0582c2u: goto P_0c0582c2;
case 0x0c0582c4u: goto P_0c0582c4;
case 0x0c0582c6u: goto P_0c0582c6;
case 0x0c0582c8u: goto P_0c0582c8;
case 0x0c0582cau: goto P_0c0582ca;
case 0x0c0582ccu: goto P_0c0582cc;
case 0x0c0582ceu: goto P_0c0582ce;
case 0x0c0582d0u: goto P_0c0582d0;
case 0x0c0582d2u: goto P_0c0582d2;
case 0x0c0582d8u: goto P_0c0582d8;
case 0x0c0582dau: goto P_0c0582da;
case 0x0c0582dcu: goto P_0c0582dc;
case 0x0c0582deu: goto P_0c0582de;
case 0x0c0582e0u: goto P_0c0582e0;
case 0x0c0582e2u: goto P_0c0582e2;
case 0x0c0582e4u: goto P_0c0582e4;
case 0x0c0582e6u: goto P_0c0582e6;
case 0x0c0582e8u: goto P_0c0582e8;
case 0x0c0582eau: goto P_0c0582ea;
case 0x0c0582ecu: goto P_0c0582ec;
case 0x0c0582eeu: goto P_0c0582ee;
case 0x0c0582f0u: goto P_0c0582f0;
case 0x0c0582f2u: goto P_0c0582f2;
case 0x0c0582f4u: goto P_0c0582f4;
case 0x0c0582f6u: goto P_0c0582f6;
case 0x0c0582f8u: goto P_0c0582f8;
case 0x0c0582fau: goto P_0c0582fa;
case 0x0c0582fcu: goto P_0c0582fc;
case 0x0c0582feu: goto P_0c0582fe;
case 0x0c058300u: goto P_0c058300;
case 0x0c058302u: goto P_0c058302;
case 0x0c058304u: goto P_0c058304;
case 0x0c058306u: goto P_0c058306;
case 0x0c058308u: goto P_0c058308;
case 0x0c05830au: goto P_0c05830a;
case 0x0c05830cu: goto P_0c05830c;
case 0x0c05830eu: goto P_0c05830e;
case 0x0c058310u: goto P_0c058310;
case 0x0c058312u: goto P_0c058312;
case 0x0c058314u: goto P_0c058314;
case 0x0c058316u: goto P_0c058316;
case 0x0c058318u: goto P_0c058318;
case 0x0c05831au: goto P_0c05831a;
case 0x0c05831cu: goto P_0c05831c;
case 0x0c05831eu: goto P_0c05831e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0572e0: /* original 6285, guest PC 0x0c0572e0 */
if(!s->budget--) { s->failed_pc=0x0c0572e0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c0572e2;
P_0c0572e2: /* original 001a, guest PC 0x0c0572e2 */
if(!s->budget--) { s->failed_pc=0x0c0572e2u; return 0; }
r[0]=r[19];
goto P_0c0572e4;
P_0c0572e4: /* original 4208, guest PC 0x0c0572e4 */
if(!s->budget--) { s->failed_pc=0x0c0572e4u; return 0; }
r[2]<<=2;
goto P_0c0572e6;
P_0c0572e6: /* original 7c0c, guest PC 0x0c0572e6 */
if(!s->budget--) { s->failed_pc=0x0c0572e6u; return 0; }
r[12]+=0x0000000cu;
goto P_0c0572e8;
P_0c0572e8: /* original 4200, guest PC 0x0c0572e8 */
if(!s->budget--) { s->failed_pc=0x0c0572e8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0572ea;
P_0c0572ea: /* original 78fe, guest PC 0x0c0572ea */
if(!s->budget--) { s->failed_pc=0x0c0572eau; return 0; }
r[8]+=0xfffffffeu;
goto P_0c0572ec;
P_0c0572ec: /* original 002e, guest PC 0x0c0572ec */
if(!s->budget--) { s->failed_pc=0x0c0572ecu; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c0572ee;
P_0c0572ee: /* original d15b, guest PC 0x0c0572ee */
if(!s->budget--) { s->failed_pc=0x0c0572eeu; return 0; }
r[1]=read(ram,0x0c05745cu,4);
goto P_0c0572f0;
P_0c0572f0: /* original 6112, guest PC 0x0c0572f0 */
if(!s->budget--) { s->failed_pc=0x0c0572f0u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c0572f2;
P_0c0572f2: /* original 201b, guest PC 0x0c0572f2 */
if(!s->budget--) { s->failed_pc=0x0c0572f2u; return 0; }
r[0]|=r[1];
goto P_0c0572f4;
P_0c0572f4: /* original fc6a, guest PC 0x0c0572f4 */
if(!s->budget--) { s->failed_pc=0x0c0572f4u; return 0; }
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c0572f6;
P_0c0572f6: /* original 1c03, guest PC 0x0c0572f6 */
if(!s->budget--) { s->failed_pc=0x0c0572f6u; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c0572f8;
P_0c0572f8: /* original fc5b, guest PC 0x0c0572f8 */
if(!s->budget--) { s->failed_pc=0x0c0572f8u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c0572fa;
P_0c0572fa: /* original fc4b, guest PC 0x0c0572fa */
if(!s->budget--) { s->failed_pc=0x0c0572fau; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c0572fc;
P_0c0572fc: /* original 2c66, guest PC 0x0c0572fc */
if(!s->budget--) { s->failed_pc=0x0c0572fcu; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c0572fe;
P_0c0572fe: /* original e000, guest PC 0x0c0572fe */
if(!s->budget--) { s->failed_pc=0x0c0572feu; return 0; }
r[0]=0x00000000u;
goto P_0c057300;
P_0c057300: /* original 000b, guest PC 0x0c057300 */
if(!s->budget--) { s->failed_pc=0x0c057300u; return 0; }
target=r[16];
write(ram,r[12]+16,r[0],4);
s->pc=target; return ram->oob==0;
P_0c057302: /* original 1c04, guest PC 0x0c057302 */
if(!s->budget--) { s->failed_pc=0x0c057302u; return 0; }
write(ram,r[12]+16,r[0],4);
return vf3_matrix_family(0x0c057304u,s,ram);
P_0c057320: /* original 0c83, guest PC 0x0c057320 */
if(!s->budget--) { s->failed_pc=0x0c057320u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c057322;
P_0c057322: /* original 7802, guest PC 0x0c057322 */
if(!s->budget--) { s->failed_pc=0x0c057322u; return 0; }
r[8]+=0x00000002u;
goto P_0c057324;
P_0c057324: /* original 6285, guest PC 0x0c057324 */
if(!s->budget--) { s->failed_pc=0x0c057324u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c057326;
P_0c057326: /* original 4208, guest PC 0x0c057326 */
if(!s->budget--) { s->failed_pc=0x0c057326u; return 0; }
r[2]<<=2;
goto P_0c057328;
P_0c057328: /* original 7c2c, guest PC 0x0c057328 */
if(!s->budget--) { s->failed_pc=0x0c057328u; return 0; }
r[12]+=0x0000002cu;
goto P_0c05732a;
P_0c05732a: /* original 001a, guest PC 0x0c05732a */
if(!s->budget--) { s->failed_pc=0x0c05732au; return 0; }
r[0]=r[19];
goto P_0c05732c;
P_0c05732c: /* original 4200, guest PC 0x0c05732c */
if(!s->budget--) { s->failed_pc=0x0c05732cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c05732e;
P_0c05732e: /* original 002e, guest PC 0x0c05732e */
if(!s->budget--) { s->failed_pc=0x0c05732eu; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c057330;
P_0c057330: /* original d14a, guest PC 0x0c057330 */
if(!s->budget--) { s->failed_pc=0x0c057330u; return 0; }
r[1]=read(ram,0x0c05745cu,4);
goto P_0c057332;
P_0c057332: /* original 6112, guest PC 0x0c057332 */
if(!s->budget--) { s->failed_pc=0x0c057332u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c057334;
P_0c057334: /* original 201b, guest PC 0x0c057334 */
if(!s->budget--) { s->failed_pc=0x0c057334u; return 0; }
r[0]|=r[1];
goto P_0c057336;
P_0c057336: /* original fcaa, guest PC 0x0c057336 */
if(!s->budget--) { s->failed_pc=0x0c057336u; return 0; }
vf3_matrix_store(s,ram,10,r[12]);
goto P_0c057338;
P_0c057338: /* original 1c03, guest PC 0x0c057338 */
if(!s->budget--) { s->failed_pc=0x0c057338u; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c05733a;
P_0c05733a: /* original fc9b, guest PC 0x0c05733a */
if(!s->budget--) { s->failed_pc=0x0c05733au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c05733c;
P_0c05733c: /* original fc8b, guest PC 0x0c05733c */
if(!s->budget--) { s->failed_pc=0x0c05733cu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c05733e;
P_0c05733e: /* original 78fc, guest PC 0x0c05733e */
if(!s->budget--) { s->failed_pc=0x0c05733eu; return 0; }
r[8]+=0xfffffffcu;
goto P_0c057340;
P_0c057340: /* original 2c66, guest PC 0x0c057340 */
if(!s->budget--) { s->failed_pc=0x0c057340u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c057342;
P_0c057342: /* original e000, guest PC 0x0c057342 */
if(!s->budget--) { s->failed_pc=0x0c057342u; return 0; }
r[0]=0x00000000u;
goto P_0c057344;
P_0c057344: /* original 000b, guest PC 0x0c057344 */
if(!s->budget--) { s->failed_pc=0x0c057344u; return 0; }
target=r[16];
write(ram,r[12]+16,r[0],4);
s->pc=target; return ram->oob==0;
P_0c057346: /* original 1c04, guest PC 0x0c057346 */
if(!s->budget--) { s->failed_pc=0x0c057346u; return 0; }
write(ram,r[12]+16,r[0],4);
return vf3_matrix_family(0x0c057348u,s,ram);
P_0c057360: /* original 0c83, guest PC 0x0c057360 */
if(!s->budget--) { s->failed_pc=0x0c057360u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c057362;
P_0c057362: /* original 7804, guest PC 0x0c057362 */
if(!s->budget--) { s->failed_pc=0x0c057362u; return 0; }
r[8]+=0x00000004u;
goto P_0c057364;
P_0c057364: /* original 6285, guest PC 0x0c057364 */
if(!s->budget--) { s->failed_pc=0x0c057364u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c057366;
P_0c057366: /* original 4208, guest PC 0x0c057366 */
if(!s->budget--) { s->failed_pc=0x0c057366u; return 0; }
r[2]<<=2;
goto P_0c057368;
P_0c057368: /* original 7c2c, guest PC 0x0c057368 */
if(!s->budget--) { s->failed_pc=0x0c057368u; return 0; }
r[12]+=0x0000002cu;
goto P_0c05736a;
P_0c05736a: /* original 001a, guest PC 0x0c05736a */
if(!s->budget--) { s->failed_pc=0x0c05736au; return 0; }
r[0]=r[19];
goto P_0c05736c;
P_0c05736c: /* original 4200, guest PC 0x0c05736c */
if(!s->budget--) { s->failed_pc=0x0c05736cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c05736e;
P_0c05736e: /* original 002e, guest PC 0x0c05736e */
if(!s->budget--) { s->failed_pc=0x0c05736eu; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c057370;
P_0c057370: /* original d13a, guest PC 0x0c057370 */
if(!s->budget--) { s->failed_pc=0x0c057370u; return 0; }
r[1]=read(ram,0x0c05745cu,4);
goto P_0c057372;
P_0c057372: /* original 6112, guest PC 0x0c057372 */
if(!s->budget--) { s->failed_pc=0x0c057372u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c057374;
P_0c057374: /* original 201b, guest PC 0x0c057374 */
if(!s->budget--) { s->failed_pc=0x0c057374u; return 0; }
r[0]|=r[1];
goto P_0c057376;
P_0c057376: /* original fcea, guest PC 0x0c057376 */
if(!s->budget--) { s->failed_pc=0x0c057376u; return 0; }
vf3_matrix_store(s,ram,14,r[12]);
goto P_0c057378;
P_0c057378: /* original 1c03, guest PC 0x0c057378 */
if(!s->budget--) { s->failed_pc=0x0c057378u; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c05737a;
P_0c05737a: /* original fcdb, guest PC 0x0c05737a */
if(!s->budget--) { s->failed_pc=0x0c05737au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[12]);
goto P_0c05737c;
P_0c05737c: /* original 78fa, guest PC 0x0c05737c */
if(!s->budget--) { s->failed_pc=0x0c05737cu; return 0; }
r[8]+=0xfffffffau;
goto P_0c05737e;
P_0c05737e: /* original fccb, guest PC 0x0c05737e */
if(!s->budget--) { s->failed_pc=0x0c05737eu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[12]);
goto P_0c057380;
P_0c057380: /* original 2c66, guest PC 0x0c057380 */
if(!s->budget--) { s->failed_pc=0x0c057380u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c057382;
P_0c057382: /* original e000, guest PC 0x0c057382 */
if(!s->budget--) { s->failed_pc=0x0c057382u; return 0; }
r[0]=0x00000000u;
goto P_0c057384;
P_0c057384: /* original 000b, guest PC 0x0c057384 */
if(!s->budget--) { s->failed_pc=0x0c057384u; return 0; }
target=r[16];
write(ram,r[12]+16,r[0],4);
s->pc=target; return ram->oob==0;
P_0c057386: /* original 1c04, guest PC 0x0c057386 */
if(!s->budget--) { s->failed_pc=0x0c057386u; return 0; }
write(ram,r[12]+16,r[0],4);
return vf3_matrix_family(0x0c057388u,s,ram);
P_0c0573a0: /* original 6285, guest PC 0x0c0573a0 */
if(!s->budget--) { s->failed_pc=0x0c0573a0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c0573a2;
P_0c0573a2: /* original 001a, guest PC 0x0c0573a2 */
if(!s->budget--) { s->failed_pc=0x0c0573a2u; return 0; }
r[0]=r[19];
goto P_0c0573a4;
P_0c0573a4: /* original 4208, guest PC 0x0c0573a4 */
if(!s->budget--) { s->failed_pc=0x0c0573a4u; return 0; }
r[2]<<=2;
goto P_0c0573a6;
P_0c0573a6: /* original 7c0c, guest PC 0x0c0573a6 */
if(!s->budget--) { s->failed_pc=0x0c0573a6u; return 0; }
r[12]+=0x0000000cu;
goto P_0c0573a8;
P_0c0573a8: /* original 4200, guest PC 0x0c0573a8 */
if(!s->budget--) { s->failed_pc=0x0c0573a8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0573aa;
P_0c0573aa: /* original 78fe, guest PC 0x0c0573aa */
if(!s->budget--) { s->failed_pc=0x0c0573aau; return 0; }
r[8]+=0xfffffffeu;
goto P_0c0573ac;
P_0c0573ac: /* original 002e, guest PC 0x0c0573ac */
if(!s->budget--) { s->failed_pc=0x0c0573acu; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c0573ae;
P_0c0573ae: /* original d12c, guest PC 0x0c0573ae */
if(!s->budget--) { s->failed_pc=0x0c0573aeu; return 0; }
r[1]=read(ram,0x0c057460u,4);
goto P_0c0573b0;
P_0c0573b0: /* original f018, guest PC 0x0c0573b0 */
if(!s->budget--) { s->failed_pc=0x0c0573b0u; return 0; }
vf3_matrix_load(s,ram,0,r[1]);
goto P_0c0573b2;
P_0c0573b2: /* original d108, guest PC 0x0c0573b2 */
if(!s->budget--) { s->failed_pc=0x0c0573b2u; return 0; }
r[1]=read(ram,0x0c0573d4u,4);
goto P_0c0573b4;
P_0c0573b4: /* original f218, guest PC 0x0c0573b4 */
if(!s->budget--) { s->failed_pc=0x0c0573b4u; return 0; }
vf3_matrix_load(s,ram,2,r[1]);
goto P_0c0573b6;
P_0c0573b6: /* original f022, guest PC 0x0c0573b6 */
if(!s->budget--) { s->failed_pc=0x0c0573b6u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'*');
goto P_0c0573b8;
P_0c0573b8: /* original f03d, guest PC 0x0c0573b8 */
if(!s->budget--) { s->failed_pc=0x0c0573b8u; return 0; }
r[53]=truncate_float(fr[0]);
goto P_0c0573ba;
P_0c0573ba: /* original 015a, guest PC 0x0c0573ba */
if(!s->budget--) { s->failed_pc=0x0c0573bau; return 0; }
r[1]=r[53];
goto P_0c0573bc;
P_0c0573bc: /* original 4128, guest PC 0x0c0573bc */
if(!s->budget--) { s->failed_pc=0x0c0573bcu; return 0; }
r[1]<<=16;
goto P_0c0573be;
P_0c0573be: /* original 4118, guest PC 0x0c0573be */
if(!s->budget--) { s->failed_pc=0x0c0573beu; return 0; }
r[1]<<=8;
goto P_0c0573c0;
P_0c0573c0: /* original 201b, guest PC 0x0c0573c0 */
if(!s->budget--) { s->failed_pc=0x0c0573c0u; return 0; }
r[0]|=r[1];
goto P_0c0573c2;
P_0c0573c2: /* original fc6a, guest PC 0x0c0573c2 */
if(!s->budget--) { s->failed_pc=0x0c0573c2u; return 0; }
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c0573c4;
P_0c0573c4: /* original 1c03, guest PC 0x0c0573c4 */
if(!s->budget--) { s->failed_pc=0x0c0573c4u; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c0573c6;
P_0c0573c6: /* original fc5b, guest PC 0x0c0573c6 */
if(!s->budget--) { s->failed_pc=0x0c0573c6u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c0573c8;
P_0c0573c8: /* original fc4b, guest PC 0x0c0573c8 */
if(!s->budget--) { s->failed_pc=0x0c0573c8u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c0573ca;
P_0c0573ca: /* original 2c66, guest PC 0x0c0573ca */
if(!s->budget--) { s->failed_pc=0x0c0573cau; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c0573cc;
P_0c0573cc: /* original e000, guest PC 0x0c0573cc */
if(!s->budget--) { s->failed_pc=0x0c0573ccu; return 0; }
r[0]=0x00000000u;
goto P_0c0573ce;
P_0c0573ce: /* original 000b, guest PC 0x0c0573ce */
if(!s->budget--) { s->failed_pc=0x0c0573ceu; return 0; }
target=r[16];
write(ram,r[12]+16,r[0],4);
s->pc=target; return ram->oob==0;
P_0c0573d0: /* original 1c04, guest PC 0x0c0573d0 */
if(!s->budget--) { s->failed_pc=0x0c0573d0u; return 0; }
write(ram,r[12]+16,r[0],4);
return vf3_matrix_family(0x0c0573d2u,s,ram);
P_0c0573e0: /* original 0c83, guest PC 0x0c0573e0 */
if(!s->budget--) { s->failed_pc=0x0c0573e0u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c0573e2;
P_0c0573e2: /* original 7802, guest PC 0x0c0573e2 */
if(!s->budget--) { s->failed_pc=0x0c0573e2u; return 0; }
r[8]+=0x00000002u;
goto P_0c0573e4;
P_0c0573e4: /* original 6285, guest PC 0x0c0573e4 */
if(!s->budget--) { s->failed_pc=0x0c0573e4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c0573e6;
P_0c0573e6: /* original 4208, guest PC 0x0c0573e6 */
if(!s->budget--) { s->failed_pc=0x0c0573e6u; return 0; }
r[2]<<=2;
goto P_0c0573e8;
P_0c0573e8: /* original 7c2c, guest PC 0x0c0573e8 */
if(!s->budget--) { s->failed_pc=0x0c0573e8u; return 0; }
r[12]+=0x0000002cu;
goto P_0c0573ea;
P_0c0573ea: /* original 001a, guest PC 0x0c0573ea */
if(!s->budget--) { s->failed_pc=0x0c0573eau; return 0; }
r[0]=r[19];
goto P_0c0573ec;
P_0c0573ec: /* original 4200, guest PC 0x0c0573ec */
if(!s->budget--) { s->failed_pc=0x0c0573ecu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0573ee;
P_0c0573ee: /* original 002e, guest PC 0x0c0573ee */
if(!s->budget--) { s->failed_pc=0x0c0573eeu; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c0573f0;
P_0c0573f0: /* original d11b, guest PC 0x0c0573f0 */
if(!s->budget--) { s->failed_pc=0x0c0573f0u; return 0; }
r[1]=read(ram,0x0c057460u,4);
goto P_0c0573f2;
P_0c0573f2: /* original f018, guest PC 0x0c0573f2 */
if(!s->budget--) { s->failed_pc=0x0c0573f2u; return 0; }
vf3_matrix_load(s,ram,0,r[1]);
goto P_0c0573f4;
P_0c0573f4: /* original d108, guest PC 0x0c0573f4 */
if(!s->budget--) { s->failed_pc=0x0c0573f4u; return 0; }
r[1]=read(ram,0x0c057418u,4);
goto P_0c0573f6;
P_0c0573f6: /* original f218, guest PC 0x0c0573f6 */
if(!s->budget--) { s->failed_pc=0x0c0573f6u; return 0; }
vf3_matrix_load(s,ram,2,r[1]);
goto P_0c0573f8;
P_0c0573f8: /* original f022, guest PC 0x0c0573f8 */
if(!s->budget--) { s->failed_pc=0x0c0573f8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'*');
goto P_0c0573fa;
P_0c0573fa: /* original f03d, guest PC 0x0c0573fa */
if(!s->budget--) { s->failed_pc=0x0c0573fau; return 0; }
r[53]=truncate_float(fr[0]);
goto P_0c0573fc;
P_0c0573fc: /* original 015a, guest PC 0x0c0573fc */
if(!s->budget--) { s->failed_pc=0x0c0573fcu; return 0; }
r[1]=r[53];
goto P_0c0573fe;
P_0c0573fe: /* original 4128, guest PC 0x0c0573fe */
if(!s->budget--) { s->failed_pc=0x0c0573feu; return 0; }
r[1]<<=16;
goto P_0c057400;
P_0c057400: /* original 4118, guest PC 0x0c057400 */
if(!s->budget--) { s->failed_pc=0x0c057400u; return 0; }
r[1]<<=8;
goto P_0c057402;
P_0c057402: /* original 201b, guest PC 0x0c057402 */
if(!s->budget--) { s->failed_pc=0x0c057402u; return 0; }
r[0]|=r[1];
goto P_0c057404;
P_0c057404: /* original fcaa, guest PC 0x0c057404 */
if(!s->budget--) { s->failed_pc=0x0c057404u; return 0; }
vf3_matrix_store(s,ram,10,r[12]);
goto P_0c057406;
P_0c057406: /* original 1c03, guest PC 0x0c057406 */
if(!s->budget--) { s->failed_pc=0x0c057406u; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c057408;
P_0c057408: /* original fc9b, guest PC 0x0c057408 */
if(!s->budget--) { s->failed_pc=0x0c057408u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c05740a;
P_0c05740a: /* original fc8b, guest PC 0x0c05740a */
if(!s->budget--) { s->failed_pc=0x0c05740au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c05740c;
P_0c05740c: /* original 78fc, guest PC 0x0c05740c */
if(!s->budget--) { s->failed_pc=0x0c05740cu; return 0; }
r[8]+=0xfffffffcu;
goto P_0c05740e;
P_0c05740e: /* original 2c66, guest PC 0x0c05740e */
if(!s->budget--) { s->failed_pc=0x0c05740eu; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c057410;
P_0c057410: /* original e000, guest PC 0x0c057410 */
if(!s->budget--) { s->failed_pc=0x0c057410u; return 0; }
r[0]=0x00000000u;
goto P_0c057412;
P_0c057412: /* original 000b, guest PC 0x0c057412 */
if(!s->budget--) { s->failed_pc=0x0c057412u; return 0; }
target=r[16];
write(ram,r[12]+16,r[0],4);
s->pc=target; return ram->oob==0;
P_0c057414: /* original 1c04, guest PC 0x0c057414 */
if(!s->budget--) { s->failed_pc=0x0c057414u; return 0; }
write(ram,r[12]+16,r[0],4);
return vf3_matrix_family(0x0c057416u,s,ram);
P_0c057420: /* original 0c83, guest PC 0x0c057420 */
if(!s->budget--) { s->failed_pc=0x0c057420u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c057422;
P_0c057422: /* original 7804, guest PC 0x0c057422 */
if(!s->budget--) { s->failed_pc=0x0c057422u; return 0; }
r[8]+=0x00000004u;
goto P_0c057424;
P_0c057424: /* original 6285, guest PC 0x0c057424 */
if(!s->budget--) { s->failed_pc=0x0c057424u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c057426;
P_0c057426: /* original 4208, guest PC 0x0c057426 */
if(!s->budget--) { s->failed_pc=0x0c057426u; return 0; }
r[2]<<=2;
goto P_0c057428;
P_0c057428: /* original 7c2c, guest PC 0x0c057428 */
if(!s->budget--) { s->failed_pc=0x0c057428u; return 0; }
r[12]+=0x0000002cu;
goto P_0c05742a;
P_0c05742a: /* original 001a, guest PC 0x0c05742a */
if(!s->budget--) { s->failed_pc=0x0c05742au; return 0; }
r[0]=r[19];
goto P_0c05742c;
P_0c05742c: /* original 4200, guest PC 0x0c05742c */
if(!s->budget--) { s->failed_pc=0x0c05742cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c05742e;
P_0c05742e: /* original 002e, guest PC 0x0c05742e */
if(!s->budget--) { s->failed_pc=0x0c05742eu; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c057430;
P_0c057430: /* original d10b, guest PC 0x0c057430 */
if(!s->budget--) { s->failed_pc=0x0c057430u; return 0; }
r[1]=read(ram,0x0c057460u,4);
goto P_0c057432;
P_0c057432: /* original f018, guest PC 0x0c057432 */
if(!s->budget--) { s->failed_pc=0x0c057432u; return 0; }
vf3_matrix_load(s,ram,0,r[1]);
goto P_0c057434;
P_0c057434: /* original d108, guest PC 0x0c057434 */
if(!s->budget--) { s->failed_pc=0x0c057434u; return 0; }
r[1]=read(ram,0x0c057458u,4);
goto P_0c057436;
P_0c057436: /* original f218, guest PC 0x0c057436 */
if(!s->budget--) { s->failed_pc=0x0c057436u; return 0; }
vf3_matrix_load(s,ram,2,r[1]);
goto P_0c057438;
P_0c057438: /* original f022, guest PC 0x0c057438 */
if(!s->budget--) { s->failed_pc=0x0c057438u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'*');
goto P_0c05743a;
P_0c05743a: /* original f03d, guest PC 0x0c05743a */
if(!s->budget--) { s->failed_pc=0x0c05743au; return 0; }
r[53]=truncate_float(fr[0]);
goto P_0c05743c;
P_0c05743c: /* original 015a, guest PC 0x0c05743c */
if(!s->budget--) { s->failed_pc=0x0c05743cu; return 0; }
r[1]=r[53];
goto P_0c05743e;
P_0c05743e: /* original 4128, guest PC 0x0c05743e */
if(!s->budget--) { s->failed_pc=0x0c05743eu; return 0; }
r[1]<<=16;
goto P_0c057440;
P_0c057440: /* original 4118, guest PC 0x0c057440 */
if(!s->budget--) { s->failed_pc=0x0c057440u; return 0; }
r[1]<<=8;
goto P_0c057442;
P_0c057442: /* original 201b, guest PC 0x0c057442 */
if(!s->budget--) { s->failed_pc=0x0c057442u; return 0; }
r[0]|=r[1];
goto P_0c057444;
P_0c057444: /* original fcea, guest PC 0x0c057444 */
if(!s->budget--) { s->failed_pc=0x0c057444u; return 0; }
vf3_matrix_store(s,ram,14,r[12]);
goto P_0c057446;
P_0c057446: /* original 1c03, guest PC 0x0c057446 */
if(!s->budget--) { s->failed_pc=0x0c057446u; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c057448;
P_0c057448: /* original fcdb, guest PC 0x0c057448 */
if(!s->budget--) { s->failed_pc=0x0c057448u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[12]);
goto P_0c05744a;
P_0c05744a: /* original 78fa, guest PC 0x0c05744a */
if(!s->budget--) { s->failed_pc=0x0c05744au; return 0; }
r[8]+=0xfffffffau;
goto P_0c05744c;
P_0c05744c: /* original fccb, guest PC 0x0c05744c */
if(!s->budget--) { s->failed_pc=0x0c05744cu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[12]);
goto P_0c05744e;
P_0c05744e: /* original 2c66, guest PC 0x0c05744e */
if(!s->budget--) { s->failed_pc=0x0c05744eu; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c057450;
P_0c057450: /* original e000, guest PC 0x0c057450 */
if(!s->budget--) { s->failed_pc=0x0c057450u; return 0; }
r[0]=0x00000000u;
goto P_0c057452;
P_0c057452: /* original 000b, guest PC 0x0c057452 */
if(!s->budget--) { s->failed_pc=0x0c057452u; return 0; }
target=r[16];
write(ram,r[12]+16,r[0],4);
s->pc=target; return ram->oob==0;
P_0c057454: /* original 1c04, guest PC 0x0c057454 */
if(!s->budget--) { s->failed_pc=0x0c057454u; return 0; }
write(ram,r[12]+16,r[0],4);
return vf3_matrix_family(0x0c057456u,s,ram);
P_0c057680: /* original 6285, guest PC 0x0c057680 */
if(!s->budget--) { s->failed_pc=0x0c057680u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c057682;
P_0c057682: /* original 001a, guest PC 0x0c057682 */
if(!s->budget--) { s->failed_pc=0x0c057682u; return 0; }
r[0]=r[19];
goto P_0c057684;
P_0c057684: /* original 6385, guest PC 0x0c057684 */
if(!s->budget--) { s->failed_pc=0x0c057684u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[3]=tmp;
goto P_0c057686;
P_0c057686: /* original 4208, guest PC 0x0c057686 */
if(!s->budget--) { s->failed_pc=0x0c057686u; return 0; }
r[2]<<=2;
goto P_0c057688;
P_0c057688: /* original 6185, guest PC 0x0c057688 */
if(!s->budget--) { s->failed_pc=0x0c057688u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[1]=tmp;
goto P_0c05768a;
P_0c05768a: /* original 7c0c, guest PC 0x0c05768a */
if(!s->budget--) { s->failed_pc=0x0c05768au; return 0; }
r[12]+=0x0000000cu;
goto P_0c05768c;
P_0c05768c: /* original 4200, guest PC 0x0c05768c */
if(!s->budget--) { s->failed_pc=0x0c05768cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c05768e;
P_0c05768e: /* original 78fa, guest PC 0x0c05768e */
if(!s->budget--) { s->failed_pc=0x0c05768eu; return 0; }
r[8]+=0xfffffffau;
goto P_0c057690;
P_0c057690: /* original 435a, guest PC 0x0c057690 */
if(!s->budget--) { s->failed_pc=0x0c057690u; return 0; }
r[53]=r[3];
goto P_0c057692;
P_0c057692: /* original f02d, guest PC 0x0c057692 */
if(!s->budget--) { s->failed_pc=0x0c057692u; return 0; }
fr[0]=vf3_fpu_float(r[53],r[18]);
goto P_0c057694;
P_0c057694: /* original 415a, guest PC 0x0c057694 */
if(!s->budget--) { s->failed_pc=0x0c057694u; return 0; }
r[53]=r[1];
goto P_0c057696;
P_0c057696: /* original 002e, guest PC 0x0c057696 */
if(!s->budget--) { s->failed_pc=0x0c057696u; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c057698;
P_0c057698: /* original d16d, guest PC 0x0c057698 */
if(!s->budget--) { s->failed_pc=0x0c057698u; return 0; }
r[1]=read(ram,0x0c057850u,4);
goto P_0c05769a;
P_0c05769a: /* original 6112, guest PC 0x0c05769a */
if(!s->budget--) { s->failed_pc=0x0c05769au; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c05769c;
P_0c05769c: /* original 201b, guest PC 0x0c05769c */
if(!s->budget--) { s->failed_pc=0x0c05769cu; return 0; }
r[0]|=r[1];
goto P_0c05769e;
P_0c05769e: /* original f12d, guest PC 0x0c05769e */
if(!s->budget--) { s->failed_pc=0x0c05769eu; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c0576a0;
P_0c0576a0: /* original fc6a, guest PC 0x0c0576a0 */
if(!s->budget--) { s->failed_pc=0x0c0576a0u; return 0; }
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c0576a2;
P_0c0576a2: /* original f032, guest PC 0x0c0576a2 */
if(!s->budget--) { s->failed_pc=0x0c0576a2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0576a4;
P_0c0576a4: /* original 1c03, guest PC 0x0c0576a4 */
if(!s->budget--) { s->failed_pc=0x0c0576a4u; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c0576a6;
P_0c0576a6: /* original f132, guest PC 0x0c0576a6 */
if(!s->budget--) { s->failed_pc=0x0c0576a6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0576a8;
P_0c0576a8: /* original fc5b, guest PC 0x0c0576a8 */
if(!s->budget--) { s->failed_pc=0x0c0576a8u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c0576aa;
P_0c0576aa: /* original e010, guest PC 0x0c0576aa */
if(!s->budget--) { s->failed_pc=0x0c0576aau; return 0; }
r[0]=0x00000010u;
goto P_0c0576ac;
P_0c0576ac: /* original fc4b, guest PC 0x0c0576ac */
if(!s->budget--) { s->failed_pc=0x0c0576acu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c0576ae;
P_0c0576ae: /* original 2c66, guest PC 0x0c0576ae */
if(!s->budget--) { s->failed_pc=0x0c0576aeu; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c0576b0;
P_0c0576b0: /* original fc07, guest PC 0x0c0576b0 */
if(!s->budget--) { s->failed_pc=0x0c0576b0u; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
goto P_0c0576b2;
P_0c0576b2: /* original e014, guest PC 0x0c0576b2 */
if(!s->budget--) { s->failed_pc=0x0c0576b2u; return 0; }
r[0]=0x00000014u;
goto P_0c0576b4;
P_0c0576b4: /* original 000b, guest PC 0x0c0576b4 */
if(!s->budget--) { s->failed_pc=0x0c0576b4u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,1,r[12]+r[0]);
s->pc=target; return ram->oob==0;
P_0c0576b6: /* original fc17, guest PC 0x0c0576b6 */
if(!s->budget--) { s->failed_pc=0x0c0576b6u; return 0; }
vf3_matrix_store(s,ram,1,r[12]+r[0]);
return vf3_matrix_family(0x0c0576b8u,s,ram);
P_0c0576c0: /* original 0c83, guest PC 0x0c0576c0 */
if(!s->budget--) { s->failed_pc=0x0c0576c0u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c0576c2;
P_0c0576c2: /* original 7806, guest PC 0x0c0576c2 */
if(!s->budget--) { s->failed_pc=0x0c0576c2u; return 0; }
r[8]+=0x00000006u;
goto P_0c0576c4;
P_0c0576c4: /* original 6285, guest PC 0x0c0576c4 */
if(!s->budget--) { s->failed_pc=0x0c0576c4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c0576c6;
P_0c0576c6: /* original 6385, guest PC 0x0c0576c6 */
if(!s->budget--) { s->failed_pc=0x0c0576c6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[3]=tmp;
goto P_0c0576c8;
P_0c0576c8: /* original 6185, guest PC 0x0c0576c8 */
if(!s->budget--) { s->failed_pc=0x0c0576c8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[1]=tmp;
goto P_0c0576ca;
P_0c0576ca: /* original 4208, guest PC 0x0c0576ca */
if(!s->budget--) { s->failed_pc=0x0c0576cau; return 0; }
r[2]<<=2;
goto P_0c0576cc;
P_0c0576cc: /* original 7c2c, guest PC 0x0c0576cc */
if(!s->budget--) { s->failed_pc=0x0c0576ccu; return 0; }
r[12]+=0x0000002cu;
goto P_0c0576ce;
P_0c0576ce: /* original 415a, guest PC 0x0c0576ce */
if(!s->budget--) { s->failed_pc=0x0c0576ceu; return 0; }
r[53]=r[1];
goto P_0c0576d0;
P_0c0576d0: /* original 001a, guest PC 0x0c0576d0 */
if(!s->budget--) { s->failed_pc=0x0c0576d0u; return 0; }
r[0]=r[19];
goto P_0c0576d2;
P_0c0576d2: /* original 4200, guest PC 0x0c0576d2 */
if(!s->budget--) { s->failed_pc=0x0c0576d2u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0576d4;
P_0c0576d4: /* original f12d, guest PC 0x0c0576d4 */
if(!s->budget--) { s->failed_pc=0x0c0576d4u; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c0576d6;
P_0c0576d6: /* original 435a, guest PC 0x0c0576d6 */
if(!s->budget--) { s->failed_pc=0x0c0576d6u; return 0; }
r[53]=r[3];
goto P_0c0576d8;
P_0c0576d8: /* original 002e, guest PC 0x0c0576d8 */
if(!s->budget--) { s->failed_pc=0x0c0576d8u; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c0576da;
P_0c0576da: /* original d15d, guest PC 0x0c0576da */
if(!s->budget--) { s->failed_pc=0x0c0576dau; return 0; }
r[1]=read(ram,0x0c057850u,4);
goto P_0c0576dc;
P_0c0576dc: /* original 6112, guest PC 0x0c0576dc */
if(!s->budget--) { s->failed_pc=0x0c0576dcu; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c0576de;
P_0c0576de: /* original 201b, guest PC 0x0c0576de */
if(!s->budget--) { s->failed_pc=0x0c0576deu; return 0; }
r[0]|=r[1];
goto P_0c0576e0;
P_0c0576e0: /* original f02d, guest PC 0x0c0576e0 */
if(!s->budget--) { s->failed_pc=0x0c0576e0u; return 0; }
fr[0]=vf3_fpu_float(r[53],r[18]);
goto P_0c0576e2;
P_0c0576e2: /* original fcaa, guest PC 0x0c0576e2 */
if(!s->budget--) { s->failed_pc=0x0c0576e2u; return 0; }
vf3_matrix_store(s,ram,10,r[12]);
goto P_0c0576e4;
P_0c0576e4: /* original f132, guest PC 0x0c0576e4 */
if(!s->budget--) { s->failed_pc=0x0c0576e4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0576e6;
P_0c0576e6: /* original 1c03, guest PC 0x0c0576e6 */
if(!s->budget--) { s->failed_pc=0x0c0576e6u; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c0576e8;
P_0c0576e8: /* original f032, guest PC 0x0c0576e8 */
if(!s->budget--) { s->failed_pc=0x0c0576e8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0576ea;
P_0c0576ea: /* original fc9b, guest PC 0x0c0576ea */
if(!s->budget--) { s->failed_pc=0x0c0576eau; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c0576ec;
P_0c0576ec: /* original e014, guest PC 0x0c0576ec */
if(!s->budget--) { s->failed_pc=0x0c0576ecu; return 0; }
r[0]=0x00000014u;
goto P_0c0576ee;
P_0c0576ee: /* original fc8b, guest PC 0x0c0576ee */
if(!s->budget--) { s->failed_pc=0x0c0576eeu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c0576f0;
P_0c0576f0: /* original 78f4, guest PC 0x0c0576f0 */
if(!s->budget--) { s->failed_pc=0x0c0576f0u; return 0; }
r[8]+=0xfffffff4u;
goto P_0c0576f2;
P_0c0576f2: /* original 2c66, guest PC 0x0c0576f2 */
if(!s->budget--) { s->failed_pc=0x0c0576f2u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c0576f4;
P_0c0576f4: /* original fc17, guest PC 0x0c0576f4 */
if(!s->budget--) { s->failed_pc=0x0c0576f4u; return 0; }
vf3_matrix_store(s,ram,1,r[12]+r[0]);
goto P_0c0576f6;
P_0c0576f6: /* original e010, guest PC 0x0c0576f6 */
if(!s->budget--) { s->failed_pc=0x0c0576f6u; return 0; }
r[0]=0x00000010u;
goto P_0c0576f8;
P_0c0576f8: /* original 000b, guest PC 0x0c0576f8 */
if(!s->budget--) { s->failed_pc=0x0c0576f8u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,0,r[12]+r[0]);
s->pc=target; return ram->oob==0;
P_0c0576fa: /* original fc07, guest PC 0x0c0576fa */
if(!s->budget--) { s->failed_pc=0x0c0576fau; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
return vf3_matrix_family(0x0c0576fcu,s,ram);
P_0c057700: /* original 0c83, guest PC 0x0c057700 */
if(!s->budget--) { s->failed_pc=0x0c057700u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c057702;
P_0c057702: /* original 780c, guest PC 0x0c057702 */
if(!s->budget--) { s->failed_pc=0x0c057702u; return 0; }
r[8]+=0x0000000cu;
goto P_0c057704;
P_0c057704: /* original 6285, guest PC 0x0c057704 */
if(!s->budget--) { s->failed_pc=0x0c057704u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c057706;
P_0c057706: /* original 6385, guest PC 0x0c057706 */
if(!s->budget--) { s->failed_pc=0x0c057706u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[3]=tmp;
goto P_0c057708;
P_0c057708: /* original 6185, guest PC 0x0c057708 */
if(!s->budget--) { s->failed_pc=0x0c057708u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[1]=tmp;
goto P_0c05770a;
P_0c05770a: /* original 4208, guest PC 0x0c05770a */
if(!s->budget--) { s->failed_pc=0x0c05770au; return 0; }
r[2]<<=2;
goto P_0c05770c;
P_0c05770c: /* original 7c2c, guest PC 0x0c05770c */
if(!s->budget--) { s->failed_pc=0x0c05770cu; return 0; }
r[12]+=0x0000002cu;
goto P_0c05770e;
P_0c05770e: /* original 415a, guest PC 0x0c05770e */
if(!s->budget--) { s->failed_pc=0x0c05770eu; return 0; }
r[53]=r[1];
goto P_0c057710;
P_0c057710: /* original 001a, guest PC 0x0c057710 */
if(!s->budget--) { s->failed_pc=0x0c057710u; return 0; }
r[0]=r[19];
goto P_0c057712;
P_0c057712: /* original 4200, guest PC 0x0c057712 */
if(!s->budget--) { s->failed_pc=0x0c057712u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c057714;
P_0c057714: /* original f12d, guest PC 0x0c057714 */
if(!s->budget--) { s->failed_pc=0x0c057714u; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c057716;
P_0c057716: /* original 435a, guest PC 0x0c057716 */
if(!s->budget--) { s->failed_pc=0x0c057716u; return 0; }
r[53]=r[3];
goto P_0c057718;
P_0c057718: /* original 002e, guest PC 0x0c057718 */
if(!s->budget--) { s->failed_pc=0x0c057718u; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c05771a;
P_0c05771a: /* original d14d, guest PC 0x0c05771a */
if(!s->budget--) { s->failed_pc=0x0c05771au; return 0; }
r[1]=read(ram,0x0c057850u,4);
goto P_0c05771c;
P_0c05771c: /* original 6112, guest PC 0x0c05771c */
if(!s->budget--) { s->failed_pc=0x0c05771cu; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c05771e;
P_0c05771e: /* original 201b, guest PC 0x0c05771e */
if(!s->budget--) { s->failed_pc=0x0c05771eu; return 0; }
r[0]|=r[1];
goto P_0c057720;
P_0c057720: /* original f02d, guest PC 0x0c057720 */
if(!s->budget--) { s->failed_pc=0x0c057720u; return 0; }
fr[0]=vf3_fpu_float(r[53],r[18]);
goto P_0c057722;
P_0c057722: /* original fcea, guest PC 0x0c057722 */
if(!s->budget--) { s->failed_pc=0x0c057722u; return 0; }
vf3_matrix_store(s,ram,14,r[12]);
goto P_0c057724;
P_0c057724: /* original f132, guest PC 0x0c057724 */
if(!s->budget--) { s->failed_pc=0x0c057724u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c057726;
P_0c057726: /* original 1c03, guest PC 0x0c057726 */
if(!s->budget--) { s->failed_pc=0x0c057726u; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c057728;
P_0c057728: /* original f032, guest PC 0x0c057728 */
if(!s->budget--) { s->failed_pc=0x0c057728u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c05772a;
P_0c05772a: /* original fcdb, guest PC 0x0c05772a */
if(!s->budget--) { s->failed_pc=0x0c05772au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[12]);
goto P_0c05772c;
P_0c05772c: /* original 78ee, guest PC 0x0c05772c */
if(!s->budget--) { s->failed_pc=0x0c05772cu; return 0; }
r[8]+=0xffffffeeu;
goto P_0c05772e;
P_0c05772e: /* original fccb, guest PC 0x0c05772e */
if(!s->budget--) { s->failed_pc=0x0c05772eu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[12]);
goto P_0c057730;
P_0c057730: /* original e014, guest PC 0x0c057730 */
if(!s->budget--) { s->failed_pc=0x0c057730u; return 0; }
r[0]=0x00000014u;
goto P_0c057732;
P_0c057732: /* original 2c66, guest PC 0x0c057732 */
if(!s->budget--) { s->failed_pc=0x0c057732u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c057734;
P_0c057734: /* original fc17, guest PC 0x0c057734 */
if(!s->budget--) { s->failed_pc=0x0c057734u; return 0; }
vf3_matrix_store(s,ram,1,r[12]+r[0]);
goto P_0c057736;
P_0c057736: /* original e010, guest PC 0x0c057736 */
if(!s->budget--) { s->failed_pc=0x0c057736u; return 0; }
r[0]=0x00000010u;
goto P_0c057738;
P_0c057738: /* original 000b, guest PC 0x0c057738 */
if(!s->budget--) { s->failed_pc=0x0c057738u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,0,r[12]+r[0]);
s->pc=target; return ram->oob==0;
P_0c05773a: /* original fc07, guest PC 0x0c05773a */
if(!s->budget--) { s->failed_pc=0x0c05773au; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
return vf3_matrix_family(0x0c05773cu,s,ram);
P_0c057740: /* original 6285, guest PC 0x0c057740 */
if(!s->budget--) { s->failed_pc=0x0c057740u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c057742;
P_0c057742: /* original 001a, guest PC 0x0c057742 */
if(!s->budget--) { s->failed_pc=0x0c057742u; return 0; }
r[0]=r[19];
goto P_0c057744;
P_0c057744: /* original 6385, guest PC 0x0c057744 */
if(!s->budget--) { s->failed_pc=0x0c057744u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[3]=tmp;
goto P_0c057746;
P_0c057746: /* original 4208, guest PC 0x0c057746 */
if(!s->budget--) { s->failed_pc=0x0c057746u; return 0; }
r[2]<<=2;
goto P_0c057748;
P_0c057748: /* original 6185, guest PC 0x0c057748 */
if(!s->budget--) { s->failed_pc=0x0c057748u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[1]=tmp;
goto P_0c05774a;
P_0c05774a: /* original 7c0c, guest PC 0x0c05774a */
if(!s->budget--) { s->failed_pc=0x0c05774au; return 0; }
r[12]+=0x0000000cu;
goto P_0c05774c;
P_0c05774c: /* original 4200, guest PC 0x0c05774c */
if(!s->budget--) { s->failed_pc=0x0c05774cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c05774e;
P_0c05774e: /* original 78fa, guest PC 0x0c05774e */
if(!s->budget--) { s->failed_pc=0x0c05774eu; return 0; }
r[8]+=0xfffffffau;
goto P_0c057750;
P_0c057750: /* original 415a, guest PC 0x0c057750 */
if(!s->budget--) { s->failed_pc=0x0c057750u; return 0; }
r[53]=r[1];
goto P_0c057752;
P_0c057752: /* original f12d, guest PC 0x0c057752 */
if(!s->budget--) { s->failed_pc=0x0c057752u; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c057754;
P_0c057754: /* original 002e, guest PC 0x0c057754 */
if(!s->budget--) { s->failed_pc=0x0c057754u; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c057756;
P_0c057756: /* original d13f, guest PC 0x0c057756 */
if(!s->budget--) { s->failed_pc=0x0c057756u; return 0; }
r[1]=read(ram,0x0c057854u,4);
goto P_0c057758;
P_0c057758: /* original f018, guest PC 0x0c057758 */
if(!s->budget--) { s->failed_pc=0x0c057758u; return 0; }
vf3_matrix_load(s,ram,0,r[1]);
goto P_0c05775a;
P_0c05775a: /* original d10b, guest PC 0x0c05775a */
if(!s->budget--) { s->failed_pc=0x0c05775au; return 0; }
r[1]=read(ram,0x0c057788u,4);
goto P_0c05775c;
P_0c05775c: /* original f218, guest PC 0x0c05775c */
if(!s->budget--) { s->failed_pc=0x0c05775cu; return 0; }
vf3_matrix_load(s,ram,2,r[1]);
goto P_0c05775e;
P_0c05775e: /* original f022, guest PC 0x0c05775e */
if(!s->budget--) { s->failed_pc=0x0c05775eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'*');
goto P_0c057760;
P_0c057760: /* original f03d, guest PC 0x0c057760 */
if(!s->budget--) { s->failed_pc=0x0c057760u; return 0; }
r[53]=truncate_float(fr[0]);
goto P_0c057762;
P_0c057762: /* original 015a, guest PC 0x0c057762 */
if(!s->budget--) { s->failed_pc=0x0c057762u; return 0; }
r[1]=r[53];
goto P_0c057764;
P_0c057764: /* original 4128, guest PC 0x0c057764 */
if(!s->budget--) { s->failed_pc=0x0c057764u; return 0; }
r[1]<<=16;
goto P_0c057766;
P_0c057766: /* original 4118, guest PC 0x0c057766 */
if(!s->budget--) { s->failed_pc=0x0c057766u; return 0; }
r[1]<<=8;
goto P_0c057768;
P_0c057768: /* original 201b, guest PC 0x0c057768 */
if(!s->budget--) { s->failed_pc=0x0c057768u; return 0; }
r[0]|=r[1];
goto P_0c05776a;
P_0c05776a: /* original 435a, guest PC 0x0c05776a */
if(!s->budget--) { s->failed_pc=0x0c05776au; return 0; }
r[53]=r[3];
goto P_0c05776c;
P_0c05776c: /* original f02d, guest PC 0x0c05776c */
if(!s->budget--) { s->failed_pc=0x0c05776cu; return 0; }
fr[0]=vf3_fpu_float(r[53],r[18]);
goto P_0c05776e;
P_0c05776e: /* original fc6a, guest PC 0x0c05776e */
if(!s->budget--) { s->failed_pc=0x0c05776eu; return 0; }
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c057770;
P_0c057770: /* original f032, guest PC 0x0c057770 */
if(!s->budget--) { s->failed_pc=0x0c057770u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c057772;
P_0c057772: /* original 1c03, guest PC 0x0c057772 */
if(!s->budget--) { s->failed_pc=0x0c057772u; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c057774;
P_0c057774: /* original f132, guest PC 0x0c057774 */
if(!s->budget--) { s->failed_pc=0x0c057774u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c057776;
P_0c057776: /* original fc5b, guest PC 0x0c057776 */
if(!s->budget--) { s->failed_pc=0x0c057776u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c057778;
P_0c057778: /* original e010, guest PC 0x0c057778 */
if(!s->budget--) { s->failed_pc=0x0c057778u; return 0; }
r[0]=0x00000010u;
goto P_0c05777a;
P_0c05777a: /* original fc4b, guest PC 0x0c05777a */
if(!s->budget--) { s->failed_pc=0x0c05777au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c05777c;
P_0c05777c: /* original 2c66, guest PC 0x0c05777c */
if(!s->budget--) { s->failed_pc=0x0c05777cu; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c05777e;
P_0c05777e: /* original fc07, guest PC 0x0c05777e */
if(!s->budget--) { s->failed_pc=0x0c05777eu; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
goto P_0c057780;
P_0c057780: /* original e014, guest PC 0x0c057780 */
if(!s->budget--) { s->failed_pc=0x0c057780u; return 0; }
r[0]=0x00000014u;
goto P_0c057782;
P_0c057782: /* original 000b, guest PC 0x0c057782 */
if(!s->budget--) { s->failed_pc=0x0c057782u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,1,r[12]+r[0]);
s->pc=target; return ram->oob==0;
P_0c057784: /* original fc17, guest PC 0x0c057784 */
if(!s->budget--) { s->failed_pc=0x0c057784u; return 0; }
vf3_matrix_store(s,ram,1,r[12]+r[0]);
return vf3_matrix_family(0x0c057786u,s,ram);
P_0c0577a0: /* original 0c83, guest PC 0x0c0577a0 */
if(!s->budget--) { s->failed_pc=0x0c0577a0u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c0577a2;
P_0c0577a2: /* original 7806, guest PC 0x0c0577a2 */
if(!s->budget--) { s->failed_pc=0x0c0577a2u; return 0; }
r[8]+=0x00000006u;
goto P_0c0577a4;
P_0c0577a4: /* original 6285, guest PC 0x0c0577a4 */
if(!s->budget--) { s->failed_pc=0x0c0577a4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c0577a6;
P_0c0577a6: /* original 6385, guest PC 0x0c0577a6 */
if(!s->budget--) { s->failed_pc=0x0c0577a6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[3]=tmp;
goto P_0c0577a8;
P_0c0577a8: /* original 6185, guest PC 0x0c0577a8 */
if(!s->budget--) { s->failed_pc=0x0c0577a8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[1]=tmp;
goto P_0c0577aa;
P_0c0577aa: /* original 4208, guest PC 0x0c0577aa */
if(!s->budget--) { s->failed_pc=0x0c0577aau; return 0; }
r[2]<<=2;
goto P_0c0577ac;
P_0c0577ac: /* original 7c2c, guest PC 0x0c0577ac */
if(!s->budget--) { s->failed_pc=0x0c0577acu; return 0; }
r[12]+=0x0000002cu;
goto P_0c0577ae;
P_0c0577ae: /* original 415a, guest PC 0x0c0577ae */
if(!s->budget--) { s->failed_pc=0x0c0577aeu; return 0; }
r[53]=r[1];
goto P_0c0577b0;
P_0c0577b0: /* original 001a, guest PC 0x0c0577b0 */
if(!s->budget--) { s->failed_pc=0x0c0577b0u; return 0; }
r[0]=r[19];
goto P_0c0577b2;
P_0c0577b2: /* original 4200, guest PC 0x0c0577b2 */
if(!s->budget--) { s->failed_pc=0x0c0577b2u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0577b4;
P_0c0577b4: /* original f12d, guest PC 0x0c0577b4 */
if(!s->budget--) { s->failed_pc=0x0c0577b4u; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c0577b6;
P_0c0577b6: /* original 002e, guest PC 0x0c0577b6 */
if(!s->budget--) { s->failed_pc=0x0c0577b6u; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c0577b8;
P_0c0577b8: /* original d126, guest PC 0x0c0577b8 */
if(!s->budget--) { s->failed_pc=0x0c0577b8u; return 0; }
r[1]=read(ram,0x0c057854u,4);
goto P_0c0577ba;
P_0c0577ba: /* original f018, guest PC 0x0c0577ba */
if(!s->budget--) { s->failed_pc=0x0c0577bau; return 0; }
vf3_matrix_load(s,ram,0,r[1]);
goto P_0c0577bc;
P_0c0577bc: /* original d10b, guest PC 0x0c0577bc */
if(!s->budget--) { s->failed_pc=0x0c0577bcu; return 0; }
r[1]=read(ram,0x0c0577ecu,4);
goto P_0c0577be;
P_0c0577be: /* original f218, guest PC 0x0c0577be */
if(!s->budget--) { s->failed_pc=0x0c0577beu; return 0; }
vf3_matrix_load(s,ram,2,r[1]);
goto P_0c0577c0;
P_0c0577c0: /* original f022, guest PC 0x0c0577c0 */
if(!s->budget--) { s->failed_pc=0x0c0577c0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'*');
goto P_0c0577c2;
P_0c0577c2: /* original f03d, guest PC 0x0c0577c2 */
if(!s->budget--) { s->failed_pc=0x0c0577c2u; return 0; }
r[53]=truncate_float(fr[0]);
goto P_0c0577c4;
P_0c0577c4: /* original 015a, guest PC 0x0c0577c4 */
if(!s->budget--) { s->failed_pc=0x0c0577c4u; return 0; }
r[1]=r[53];
goto P_0c0577c6;
P_0c0577c6: /* original 4128, guest PC 0x0c0577c6 */
if(!s->budget--) { s->failed_pc=0x0c0577c6u; return 0; }
r[1]<<=16;
goto P_0c0577c8;
P_0c0577c8: /* original 4118, guest PC 0x0c0577c8 */
if(!s->budget--) { s->failed_pc=0x0c0577c8u; return 0; }
r[1]<<=8;
goto P_0c0577ca;
P_0c0577ca: /* original 201b, guest PC 0x0c0577ca */
if(!s->budget--) { s->failed_pc=0x0c0577cau; return 0; }
r[0]|=r[1];
goto P_0c0577cc;
P_0c0577cc: /* original 435a, guest PC 0x0c0577cc */
if(!s->budget--) { s->failed_pc=0x0c0577ccu; return 0; }
r[53]=r[3];
goto P_0c0577ce;
P_0c0577ce: /* original f02d, guest PC 0x0c0577ce */
if(!s->budget--) { s->failed_pc=0x0c0577ceu; return 0; }
fr[0]=vf3_fpu_float(r[53],r[18]);
goto P_0c0577d0;
P_0c0577d0: /* original fcaa, guest PC 0x0c0577d0 */
if(!s->budget--) { s->failed_pc=0x0c0577d0u; return 0; }
vf3_matrix_store(s,ram,10,r[12]);
goto P_0c0577d2;
P_0c0577d2: /* original f132, guest PC 0x0c0577d2 */
if(!s->budget--) { s->failed_pc=0x0c0577d2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0577d4;
P_0c0577d4: /* original 1c03, guest PC 0x0c0577d4 */
if(!s->budget--) { s->failed_pc=0x0c0577d4u; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c0577d6;
P_0c0577d6: /* original f032, guest PC 0x0c0577d6 */
if(!s->budget--) { s->failed_pc=0x0c0577d6u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0577d8;
P_0c0577d8: /* original fc9b, guest PC 0x0c0577d8 */
if(!s->budget--) { s->failed_pc=0x0c0577d8u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c0577da;
P_0c0577da: /* original e014, guest PC 0x0c0577da */
if(!s->budget--) { s->failed_pc=0x0c0577dau; return 0; }
r[0]=0x00000014u;
goto P_0c0577dc;
P_0c0577dc: /* original fc8b, guest PC 0x0c0577dc */
if(!s->budget--) { s->failed_pc=0x0c0577dcu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c0577de;
P_0c0577de: /* original 78f4, guest PC 0x0c0577de */
if(!s->budget--) { s->failed_pc=0x0c0577deu; return 0; }
r[8]+=0xfffffff4u;
goto P_0c0577e0;
P_0c0577e0: /* original 2c66, guest PC 0x0c0577e0 */
if(!s->budget--) { s->failed_pc=0x0c0577e0u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c0577e2;
P_0c0577e2: /* original fc17, guest PC 0x0c0577e2 */
if(!s->budget--) { s->failed_pc=0x0c0577e2u; return 0; }
vf3_matrix_store(s,ram,1,r[12]+r[0]);
goto P_0c0577e4;
P_0c0577e4: /* original e010, guest PC 0x0c0577e4 */
if(!s->budget--) { s->failed_pc=0x0c0577e4u; return 0; }
r[0]=0x00000010u;
goto P_0c0577e6;
P_0c0577e6: /* original 000b, guest PC 0x0c0577e6 */
if(!s->budget--) { s->failed_pc=0x0c0577e6u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,0,r[12]+r[0]);
s->pc=target; return ram->oob==0;
P_0c0577e8: /* original fc07, guest PC 0x0c0577e8 */
if(!s->budget--) { s->failed_pc=0x0c0577e8u; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
return vf3_matrix_family(0x0c0577eau,s,ram);
P_0c057800: /* original 0c83, guest PC 0x0c057800 */
if(!s->budget--) { s->failed_pc=0x0c057800u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c057802;
P_0c057802: /* original 780c, guest PC 0x0c057802 */
if(!s->budget--) { s->failed_pc=0x0c057802u; return 0; }
r[8]+=0x0000000cu;
goto P_0c057804;
P_0c057804: /* original 6285, guest PC 0x0c057804 */
if(!s->budget--) { s->failed_pc=0x0c057804u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c057806;
P_0c057806: /* original 6385, guest PC 0x0c057806 */
if(!s->budget--) { s->failed_pc=0x0c057806u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[3]=tmp;
goto P_0c057808;
P_0c057808: /* original 6185, guest PC 0x0c057808 */
if(!s->budget--) { s->failed_pc=0x0c057808u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[1]=tmp;
goto P_0c05780a;
P_0c05780a: /* original 4208, guest PC 0x0c05780a */
if(!s->budget--) { s->failed_pc=0x0c05780au; return 0; }
r[2]<<=2;
goto P_0c05780c;
P_0c05780c: /* original 7c2c, guest PC 0x0c05780c */
if(!s->budget--) { s->failed_pc=0x0c05780cu; return 0; }
r[12]+=0x0000002cu;
goto P_0c05780e;
P_0c05780e: /* original 415a, guest PC 0x0c05780e */
if(!s->budget--) { s->failed_pc=0x0c05780eu; return 0; }
r[53]=r[1];
goto P_0c057810;
P_0c057810: /* original 001a, guest PC 0x0c057810 */
if(!s->budget--) { s->failed_pc=0x0c057810u; return 0; }
r[0]=r[19];
goto P_0c057812;
P_0c057812: /* original 4200, guest PC 0x0c057812 */
if(!s->budget--) { s->failed_pc=0x0c057812u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c057814;
P_0c057814: /* original f12d, guest PC 0x0c057814 */
if(!s->budget--) { s->failed_pc=0x0c057814u; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c057816;
P_0c057816: /* original 002e, guest PC 0x0c057816 */
if(!s->budget--) { s->failed_pc=0x0c057816u; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c057818;
P_0c057818: /* original d10e, guest PC 0x0c057818 */
if(!s->budget--) { s->failed_pc=0x0c057818u; return 0; }
r[1]=read(ram,0x0c057854u,4);
goto P_0c05781a;
P_0c05781a: /* original f018, guest PC 0x0c05781a */
if(!s->budget--) { s->failed_pc=0x0c05781au; return 0; }
vf3_matrix_load(s,ram,0,r[1]);
goto P_0c05781c;
P_0c05781c: /* original d10b, guest PC 0x0c05781c */
if(!s->budget--) { s->failed_pc=0x0c05781cu; return 0; }
r[1]=read(ram,0x0c05784cu,4);
goto P_0c05781e;
P_0c05781e: /* original f218, guest PC 0x0c05781e */
if(!s->budget--) { s->failed_pc=0x0c05781eu; return 0; }
vf3_matrix_load(s,ram,2,r[1]);
goto P_0c057820;
P_0c057820: /* original f022, guest PC 0x0c057820 */
if(!s->budget--) { s->failed_pc=0x0c057820u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'*');
goto P_0c057822;
P_0c057822: /* original f03d, guest PC 0x0c057822 */
if(!s->budget--) { s->failed_pc=0x0c057822u; return 0; }
r[53]=truncate_float(fr[0]);
goto P_0c057824;
P_0c057824: /* original 015a, guest PC 0x0c057824 */
if(!s->budget--) { s->failed_pc=0x0c057824u; return 0; }
r[1]=r[53];
goto P_0c057826;
P_0c057826: /* original 4128, guest PC 0x0c057826 */
if(!s->budget--) { s->failed_pc=0x0c057826u; return 0; }
r[1]<<=16;
goto P_0c057828;
P_0c057828: /* original 4118, guest PC 0x0c057828 */
if(!s->budget--) { s->failed_pc=0x0c057828u; return 0; }
r[1]<<=8;
goto P_0c05782a;
P_0c05782a: /* original 201b, guest PC 0x0c05782a */
if(!s->budget--) { s->failed_pc=0x0c05782au; return 0; }
r[0]|=r[1];
goto P_0c05782c;
P_0c05782c: /* original 435a, guest PC 0x0c05782c */
if(!s->budget--) { s->failed_pc=0x0c05782cu; return 0; }
r[53]=r[3];
goto P_0c05782e;
P_0c05782e: /* original f02d, guest PC 0x0c05782e */
if(!s->budget--) { s->failed_pc=0x0c05782eu; return 0; }
fr[0]=vf3_fpu_float(r[53],r[18]);
goto P_0c057830;
P_0c057830: /* original fcea, guest PC 0x0c057830 */
if(!s->budget--) { s->failed_pc=0x0c057830u; return 0; }
vf3_matrix_store(s,ram,14,r[12]);
goto P_0c057832;
P_0c057832: /* original f132, guest PC 0x0c057832 */
if(!s->budget--) { s->failed_pc=0x0c057832u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c057834;
P_0c057834: /* original 1c03, guest PC 0x0c057834 */
if(!s->budget--) { s->failed_pc=0x0c057834u; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c057836;
P_0c057836: /* original f032, guest PC 0x0c057836 */
if(!s->budget--) { s->failed_pc=0x0c057836u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c057838;
P_0c057838: /* original fcdb, guest PC 0x0c057838 */
if(!s->budget--) { s->failed_pc=0x0c057838u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[12]);
goto P_0c05783a;
P_0c05783a: /* original 78ee, guest PC 0x0c05783a */
if(!s->budget--) { s->failed_pc=0x0c05783au; return 0; }
r[8]+=0xffffffeeu;
goto P_0c05783c;
P_0c05783c: /* original fccb, guest PC 0x0c05783c */
if(!s->budget--) { s->failed_pc=0x0c05783cu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[12]);
goto P_0c05783e;
P_0c05783e: /* original e014, guest PC 0x0c05783e */
if(!s->budget--) { s->failed_pc=0x0c05783eu; return 0; }
r[0]=0x00000014u;
goto P_0c057840;
P_0c057840: /* original 2c66, guest PC 0x0c057840 */
if(!s->budget--) { s->failed_pc=0x0c057840u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c057842;
P_0c057842: /* original fc17, guest PC 0x0c057842 */
if(!s->budget--) { s->failed_pc=0x0c057842u; return 0; }
vf3_matrix_store(s,ram,1,r[12]+r[0]);
goto P_0c057844;
P_0c057844: /* original e010, guest PC 0x0c057844 */
if(!s->budget--) { s->failed_pc=0x0c057844u; return 0; }
r[0]=0x00000010u;
goto P_0c057846;
P_0c057846: /* original 000b, guest PC 0x0c057846 */
if(!s->budget--) { s->failed_pc=0x0c057846u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,0,r[12]+r[0]);
s->pc=target; return ram->oob==0;
P_0c057848: /* original fc07, guest PC 0x0c057848 */
if(!s->budget--) { s->failed_pc=0x0c057848u; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
return vf3_matrix_family(0x0c05784au,s,ram);
P_0c057a60: /* original 6285, guest PC 0x0c057a60 */
if(!s->budget--) { s->failed_pc=0x0c057a60u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c057a62;
P_0c057a62: /* original 001a, guest PC 0x0c057a62 */
if(!s->budget--) { s->failed_pc=0x0c057a62u; return 0; }
r[0]=r[19];
goto P_0c057a64;
P_0c057a64: /* original 4208, guest PC 0x0c057a64 */
if(!s->budget--) { s->failed_pc=0x0c057a64u; return 0; }
r[2]<<=2;
goto P_0c057a66;
P_0c057a66: /* original 7c14, guest PC 0x0c057a66 */
if(!s->budget--) { s->failed_pc=0x0c057a66u; return 0; }
r[12]+=0x00000014u;
goto P_0c057a68;
P_0c057a68: /* original 4200, guest PC 0x0c057a68 */
if(!s->budget--) { s->failed_pc=0x0c057a68u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c057a6a;
P_0c057a6a: /* original 78fe, guest PC 0x0c057a6a */
if(!s->budget--) { s->failed_pc=0x0c057a6au; return 0; }
r[8]+=0xfffffffeu;
goto P_0c057a6c;
P_0c057a6c: /* original 002e, guest PC 0x0c057a6c */
if(!s->budget--) { s->failed_pc=0x0c057a6cu; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c057a6e;
P_0c057a6e: /* original d178, guest PC 0x0c057a6e */
if(!s->budget--) { s->failed_pc=0x0c057a6eu; return 0; }
r[1]=read(ram,0x0c057c50u,4);
goto P_0c057a70;
P_0c057a70: /* original 6112, guest PC 0x0c057a70 */
if(!s->budget--) { s->failed_pc=0x0c057a70u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c057a72;
P_0c057a72: /* original 201b, guest PC 0x0c057a72 */
if(!s->budget--) { s->failed_pc=0x0c057a72u; return 0; }
r[0]|=r[1];
goto P_0c057a74;
P_0c057a74: /* original fc7b, guest PC 0x0c057a74 */
if(!s->budget--) { s->failed_pc=0x0c057a74u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,7,r[12]);
goto P_0c057a76;
P_0c057a76: /* original fc6b, guest PC 0x0c057a76 */
if(!s->budget--) { s->failed_pc=0x0c057a76u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c057a78;
P_0c057a78: /* original 1c03, guest PC 0x0c057a78 */
if(!s->budget--) { s->failed_pc=0x0c057a78u; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c057a7a;
P_0c057a7a: /* original fc5b, guest PC 0x0c057a7a */
if(!s->budget--) { s->failed_pc=0x0c057a7au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c057a7c;
P_0c057a7c: /* original fc4b, guest PC 0x0c057a7c */
if(!s->budget--) { s->failed_pc=0x0c057a7cu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c057a7e;
P_0c057a7e: /* original 000b, guest PC 0x0c057a7e */
if(!s->budget--) { s->failed_pc=0x0c057a7eu; return 0; }
target=r[16];
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
s->pc=target; return ram->oob==0;
P_0c057a80: /* original 2c66, guest PC 0x0c057a80 */
if(!s->budget--) { s->failed_pc=0x0c057a80u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
return vf3_matrix_family(0x0c057a82u,s,ram);
P_0c057aa0: /* original 0c83, guest PC 0x0c057aa0 */
if(!s->budget--) { s->failed_pc=0x0c057aa0u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c057aa2;
P_0c057aa2: /* original 7802, guest PC 0x0c057aa2 */
if(!s->budget--) { s->failed_pc=0x0c057aa2u; return 0; }
r[8]+=0x00000002u;
goto P_0c057aa4;
P_0c057aa4: /* original 6285, guest PC 0x0c057aa4 */
if(!s->budget--) { s->failed_pc=0x0c057aa4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c057aa6;
P_0c057aa6: /* original 4208, guest PC 0x0c057aa6 */
if(!s->budget--) { s->failed_pc=0x0c057aa6u; return 0; }
r[2]<<=2;
goto P_0c057aa8;
P_0c057aa8: /* original 7c34, guest PC 0x0c057aa8 */
if(!s->budget--) { s->failed_pc=0x0c057aa8u; return 0; }
r[12]+=0x00000034u;
goto P_0c057aaa;
P_0c057aaa: /* original 001a, guest PC 0x0c057aaa */
if(!s->budget--) { s->failed_pc=0x0c057aaau; return 0; }
r[0]=r[19];
goto P_0c057aac;
P_0c057aac: /* original 4200, guest PC 0x0c057aac */
if(!s->budget--) { s->failed_pc=0x0c057aacu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c057aae;
P_0c057aae: /* original 002e, guest PC 0x0c057aae */
if(!s->budget--) { s->failed_pc=0x0c057aaeu; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c057ab0;
P_0c057ab0: /* original d167, guest PC 0x0c057ab0 */
if(!s->budget--) { s->failed_pc=0x0c057ab0u; return 0; }
r[1]=read(ram,0x0c057c50u,4);
goto P_0c057ab2;
P_0c057ab2: /* original 6112, guest PC 0x0c057ab2 */
if(!s->budget--) { s->failed_pc=0x0c057ab2u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c057ab4;
P_0c057ab4: /* original 201b, guest PC 0x0c057ab4 */
if(!s->budget--) { s->failed_pc=0x0c057ab4u; return 0; }
r[0]|=r[1];
goto P_0c057ab6;
P_0c057ab6: /* original fcbb, guest PC 0x0c057ab6 */
if(!s->budget--) { s->failed_pc=0x0c057ab6u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,11,r[12]);
goto P_0c057ab8;
P_0c057ab8: /* original fcab, guest PC 0x0c057ab8 */
if(!s->budget--) { s->failed_pc=0x0c057ab8u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,10,r[12]);
goto P_0c057aba;
P_0c057aba: /* original 1c03, guest PC 0x0c057aba */
if(!s->budget--) { s->failed_pc=0x0c057abau; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c057abc;
P_0c057abc: /* original fc9b, guest PC 0x0c057abc */
if(!s->budget--) { s->failed_pc=0x0c057abcu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c057abe;
P_0c057abe: /* original fc8b, guest PC 0x0c057abe */
if(!s->budget--) { s->failed_pc=0x0c057abeu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c057ac0;
P_0c057ac0: /* original 78fc, guest PC 0x0c057ac0 */
if(!s->budget--) { s->failed_pc=0x0c057ac0u; return 0; }
r[8]+=0xfffffffcu;
goto P_0c057ac2;
P_0c057ac2: /* original 000b, guest PC 0x0c057ac2 */
if(!s->budget--) { s->failed_pc=0x0c057ac2u; return 0; }
target=r[16];
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
s->pc=target; return ram->oob==0;
P_0c057ac4: /* original 2c66, guest PC 0x0c057ac4 */
if(!s->budget--) { s->failed_pc=0x0c057ac4u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
return vf3_matrix_family(0x0c057ac6u,s,ram);
P_0c057ae0: /* original 0c83, guest PC 0x0c057ae0 */
if(!s->budget--) { s->failed_pc=0x0c057ae0u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c057ae2;
P_0c057ae2: /* original 7804, guest PC 0x0c057ae2 */
if(!s->budget--) { s->failed_pc=0x0c057ae2u; return 0; }
r[8]+=0x00000004u;
goto P_0c057ae4;
P_0c057ae4: /* original 6285, guest PC 0x0c057ae4 */
if(!s->budget--) { s->failed_pc=0x0c057ae4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c057ae6;
P_0c057ae6: /* original 4208, guest PC 0x0c057ae6 */
if(!s->budget--) { s->failed_pc=0x0c057ae6u; return 0; }
r[2]<<=2;
goto P_0c057ae8;
P_0c057ae8: /* original 7c34, guest PC 0x0c057ae8 */
if(!s->budget--) { s->failed_pc=0x0c057ae8u; return 0; }
r[12]+=0x00000034u;
goto P_0c057aea;
P_0c057aea: /* original 001a, guest PC 0x0c057aea */
if(!s->budget--) { s->failed_pc=0x0c057aeau; return 0; }
r[0]=r[19];
goto P_0c057aec;
P_0c057aec: /* original 4200, guest PC 0x0c057aec */
if(!s->budget--) { s->failed_pc=0x0c057aecu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c057aee;
P_0c057aee: /* original 002e, guest PC 0x0c057aee */
if(!s->budget--) { s->failed_pc=0x0c057aeeu; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c057af0;
P_0c057af0: /* original d157, guest PC 0x0c057af0 */
if(!s->budget--) { s->failed_pc=0x0c057af0u; return 0; }
r[1]=read(ram,0x0c057c50u,4);
goto P_0c057af2;
P_0c057af2: /* original 6112, guest PC 0x0c057af2 */
if(!s->budget--) { s->failed_pc=0x0c057af2u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c057af4;
P_0c057af4: /* original 201b, guest PC 0x0c057af4 */
if(!s->budget--) { s->failed_pc=0x0c057af4u; return 0; }
r[0]|=r[1];
goto P_0c057af6;
P_0c057af6: /* original fcfb, guest PC 0x0c057af6 */
if(!s->budget--) { s->failed_pc=0x0c057af6u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[12]);
goto P_0c057af8;
P_0c057af8: /* original fceb, guest PC 0x0c057af8 */
if(!s->budget--) { s->failed_pc=0x0c057af8u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[12]);
goto P_0c057afa;
P_0c057afa: /* original 1c03, guest PC 0x0c057afa */
if(!s->budget--) { s->failed_pc=0x0c057afau; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c057afc;
P_0c057afc: /* original fcdb, guest PC 0x0c057afc */
if(!s->budget--) { s->failed_pc=0x0c057afcu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[12]);
goto P_0c057afe;
P_0c057afe: /* original 78fa, guest PC 0x0c057afe */
if(!s->budget--) { s->failed_pc=0x0c057afeu; return 0; }
r[8]+=0xfffffffau;
goto P_0c057b00;
P_0c057b00: /* original fccb, guest PC 0x0c057b00 */
if(!s->budget--) { s->failed_pc=0x0c057b00u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[12]);
goto P_0c057b02;
P_0c057b02: /* original 000b, guest PC 0x0c057b02 */
if(!s->budget--) { s->failed_pc=0x0c057b02u; return 0; }
target=r[16];
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
s->pc=target; return ram->oob==0;
P_0c057b04: /* original 2c66, guest PC 0x0c057b04 */
if(!s->budget--) { s->failed_pc=0x0c057b04u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
return vf3_matrix_family(0x0c057b06u,s,ram);
P_0c057b20: /* original 6285, guest PC 0x0c057b20 */
if(!s->budget--) { s->failed_pc=0x0c057b20u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c057b22;
P_0c057b22: /* original 001a, guest PC 0x0c057b22 */
if(!s->budget--) { s->failed_pc=0x0c057b22u; return 0; }
r[0]=r[19];
goto P_0c057b24;
P_0c057b24: /* original 4208, guest PC 0x0c057b24 */
if(!s->budget--) { s->failed_pc=0x0c057b24u; return 0; }
r[2]<<=2;
goto P_0c057b26;
P_0c057b26: /* original 7c14, guest PC 0x0c057b26 */
if(!s->budget--) { s->failed_pc=0x0c057b26u; return 0; }
r[12]+=0x00000014u;
goto P_0c057b28;
P_0c057b28: /* original 4200, guest PC 0x0c057b28 */
if(!s->budget--) { s->failed_pc=0x0c057b28u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c057b2a;
P_0c057b2a: /* original 78fe, guest PC 0x0c057b2a */
if(!s->budget--) { s->failed_pc=0x0c057b2au; return 0; }
r[8]+=0xfffffffeu;
goto P_0c057b2c;
P_0c057b2c: /* original 002e, guest PC 0x0c057b2c */
if(!s->budget--) { s->failed_pc=0x0c057b2cu; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c057b2e;
P_0c057b2e: /* original d149, guest PC 0x0c057b2e */
if(!s->budget--) { s->failed_pc=0x0c057b2eu; return 0; }
r[1]=read(ram,0x0c057c54u,4);
goto P_0c057b30;
P_0c057b30: /* original f018, guest PC 0x0c057b30 */
if(!s->budget--) { s->failed_pc=0x0c057b30u; return 0; }
vf3_matrix_load(s,ram,0,r[1]);
goto P_0c057b32;
P_0c057b32: /* original d107, guest PC 0x0c057b32 */
if(!s->budget--) { s->failed_pc=0x0c057b32u; return 0; }
r[1]=read(ram,0x0c057b50u,4);
goto P_0c057b34;
P_0c057b34: /* original f218, guest PC 0x0c057b34 */
if(!s->budget--) { s->failed_pc=0x0c057b34u; return 0; }
vf3_matrix_load(s,ram,2,r[1]);
goto P_0c057b36;
P_0c057b36: /* original f022, guest PC 0x0c057b36 */
if(!s->budget--) { s->failed_pc=0x0c057b36u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'*');
goto P_0c057b38;
P_0c057b38: /* original f03d, guest PC 0x0c057b38 */
if(!s->budget--) { s->failed_pc=0x0c057b38u; return 0; }
r[53]=truncate_float(fr[0]);
goto P_0c057b3a;
P_0c057b3a: /* original 015a, guest PC 0x0c057b3a */
if(!s->budget--) { s->failed_pc=0x0c057b3au; return 0; }
r[1]=r[53];
goto P_0c057b3c;
P_0c057b3c: /* original 4128, guest PC 0x0c057b3c */
if(!s->budget--) { s->failed_pc=0x0c057b3cu; return 0; }
r[1]<<=16;
goto P_0c057b3e;
P_0c057b3e: /* original 4118, guest PC 0x0c057b3e */
if(!s->budget--) { s->failed_pc=0x0c057b3eu; return 0; }
r[1]<<=8;
goto P_0c057b40;
P_0c057b40: /* original 201b, guest PC 0x0c057b40 */
if(!s->budget--) { s->failed_pc=0x0c057b40u; return 0; }
r[0]|=r[1];
goto P_0c057b42;
P_0c057b42: /* original fc7b, guest PC 0x0c057b42 */
if(!s->budget--) { s->failed_pc=0x0c057b42u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,7,r[12]);
goto P_0c057b44;
P_0c057b44: /* original fc6b, guest PC 0x0c057b44 */
if(!s->budget--) { s->failed_pc=0x0c057b44u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c057b46;
P_0c057b46: /* original 1c03, guest PC 0x0c057b46 */
if(!s->budget--) { s->failed_pc=0x0c057b46u; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c057b48;
P_0c057b48: /* original fc5b, guest PC 0x0c057b48 */
if(!s->budget--) { s->failed_pc=0x0c057b48u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c057b4a;
P_0c057b4a: /* original fc4b, guest PC 0x0c057b4a */
if(!s->budget--) { s->failed_pc=0x0c057b4au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c057b4c;
P_0c057b4c: /* original 000b, guest PC 0x0c057b4c */
if(!s->budget--) { s->failed_pc=0x0c057b4cu; return 0; }
target=r[16];
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
s->pc=target; return ram->oob==0;
P_0c057b4e: /* original 2c66, guest PC 0x0c057b4e */
if(!s->budget--) { s->failed_pc=0x0c057b4eu; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
return vf3_matrix_family(0x0c057b50u,s,ram);
P_0c057b60: /* original 0c83, guest PC 0x0c057b60 */
if(!s->budget--) { s->failed_pc=0x0c057b60u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c057b62;
P_0c057b62: /* original 7802, guest PC 0x0c057b62 */
if(!s->budget--) { s->failed_pc=0x0c057b62u; return 0; }
r[8]+=0x00000002u;
goto P_0c057b64;
P_0c057b64: /* original 6285, guest PC 0x0c057b64 */
if(!s->budget--) { s->failed_pc=0x0c057b64u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c057b66;
P_0c057b66: /* original 4208, guest PC 0x0c057b66 */
if(!s->budget--) { s->failed_pc=0x0c057b66u; return 0; }
r[2]<<=2;
goto P_0c057b68;
P_0c057b68: /* original 7c34, guest PC 0x0c057b68 */
if(!s->budget--) { s->failed_pc=0x0c057b68u; return 0; }
r[12]+=0x00000034u;
goto P_0c057b6a;
P_0c057b6a: /* original 001a, guest PC 0x0c057b6a */
if(!s->budget--) { s->failed_pc=0x0c057b6au; return 0; }
r[0]=r[19];
goto P_0c057b6c;
P_0c057b6c: /* original 4200, guest PC 0x0c057b6c */
if(!s->budget--) { s->failed_pc=0x0c057b6cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c057b6e;
P_0c057b6e: /* original 002e, guest PC 0x0c057b6e */
if(!s->budget--) { s->failed_pc=0x0c057b6eu; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c057b70;
P_0c057b70: /* original d138, guest PC 0x0c057b70 */
if(!s->budget--) { s->failed_pc=0x0c057b70u; return 0; }
r[1]=read(ram,0x0c057c54u,4);
goto P_0c057b72;
P_0c057b72: /* original f018, guest PC 0x0c057b72 */
if(!s->budget--) { s->failed_pc=0x0c057b72u; return 0; }
vf3_matrix_load(s,ram,0,r[1]);
goto P_0c057b74;
P_0c057b74: /* original d107, guest PC 0x0c057b74 */
if(!s->budget--) { s->failed_pc=0x0c057b74u; return 0; }
r[1]=read(ram,0x0c057b94u,4);
goto P_0c057b76;
P_0c057b76: /* original f218, guest PC 0x0c057b76 */
if(!s->budget--) { s->failed_pc=0x0c057b76u; return 0; }
vf3_matrix_load(s,ram,2,r[1]);
goto P_0c057b78;
P_0c057b78: /* original f022, guest PC 0x0c057b78 */
if(!s->budget--) { s->failed_pc=0x0c057b78u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'*');
goto P_0c057b7a;
P_0c057b7a: /* original f03d, guest PC 0x0c057b7a */
if(!s->budget--) { s->failed_pc=0x0c057b7au; return 0; }
r[53]=truncate_float(fr[0]);
goto P_0c057b7c;
P_0c057b7c: /* original 015a, guest PC 0x0c057b7c */
if(!s->budget--) { s->failed_pc=0x0c057b7cu; return 0; }
r[1]=r[53];
goto P_0c057b7e;
P_0c057b7e: /* original 4128, guest PC 0x0c057b7e */
if(!s->budget--) { s->failed_pc=0x0c057b7eu; return 0; }
r[1]<<=16;
goto P_0c057b80;
P_0c057b80: /* original 4118, guest PC 0x0c057b80 */
if(!s->budget--) { s->failed_pc=0x0c057b80u; return 0; }
r[1]<<=8;
goto P_0c057b82;
P_0c057b82: /* original 201b, guest PC 0x0c057b82 */
if(!s->budget--) { s->failed_pc=0x0c057b82u; return 0; }
r[0]|=r[1];
goto P_0c057b84;
P_0c057b84: /* original fcbb, guest PC 0x0c057b84 */
if(!s->budget--) { s->failed_pc=0x0c057b84u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,11,r[12]);
goto P_0c057b86;
P_0c057b86: /* original fcab, guest PC 0x0c057b86 */
if(!s->budget--) { s->failed_pc=0x0c057b86u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,10,r[12]);
goto P_0c057b88;
P_0c057b88: /* original 1c03, guest PC 0x0c057b88 */
if(!s->budget--) { s->failed_pc=0x0c057b88u; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c057b8a;
P_0c057b8a: /* original fc9b, guest PC 0x0c057b8a */
if(!s->budget--) { s->failed_pc=0x0c057b8au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c057b8c;
P_0c057b8c: /* original fc8b, guest PC 0x0c057b8c */
if(!s->budget--) { s->failed_pc=0x0c057b8cu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c057b8e;
P_0c057b8e: /* original 78fc, guest PC 0x0c057b8e */
if(!s->budget--) { s->failed_pc=0x0c057b8eu; return 0; }
r[8]+=0xfffffffcu;
goto P_0c057b90;
P_0c057b90: /* original 000b, guest PC 0x0c057b90 */
if(!s->budget--) { s->failed_pc=0x0c057b90u; return 0; }
target=r[16];
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
s->pc=target; return ram->oob==0;
P_0c057b92: /* original 2c66, guest PC 0x0c057b92 */
if(!s->budget--) { s->failed_pc=0x0c057b92u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
return vf3_matrix_family(0x0c057b94u,s,ram);
P_0c057ba0: /* original 0c83, guest PC 0x0c057ba0 */
if(!s->budget--) { s->failed_pc=0x0c057ba0u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c057ba2;
P_0c057ba2: /* original 7804, guest PC 0x0c057ba2 */
if(!s->budget--) { s->failed_pc=0x0c057ba2u; return 0; }
r[8]+=0x00000004u;
goto P_0c057ba4;
P_0c057ba4: /* original 6285, guest PC 0x0c057ba4 */
if(!s->budget--) { s->failed_pc=0x0c057ba4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c057ba6;
P_0c057ba6: /* original 4208, guest PC 0x0c057ba6 */
if(!s->budget--) { s->failed_pc=0x0c057ba6u; return 0; }
r[2]<<=2;
goto P_0c057ba8;
P_0c057ba8: /* original 7c34, guest PC 0x0c057ba8 */
if(!s->budget--) { s->failed_pc=0x0c057ba8u; return 0; }
r[12]+=0x00000034u;
goto P_0c057baa;
P_0c057baa: /* original 001a, guest PC 0x0c057baa */
if(!s->budget--) { s->failed_pc=0x0c057baau; return 0; }
r[0]=r[19];
goto P_0c057bac;
P_0c057bac: /* original 4200, guest PC 0x0c057bac */
if(!s->budget--) { s->failed_pc=0x0c057bacu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c057bae;
P_0c057bae: /* original 002e, guest PC 0x0c057bae */
if(!s->budget--) { s->failed_pc=0x0c057baeu; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c057bb0;
P_0c057bb0: /* original d128, guest PC 0x0c057bb0 */
if(!s->budget--) { s->failed_pc=0x0c057bb0u; return 0; }
r[1]=read(ram,0x0c057c54u,4);
goto P_0c057bb2;
P_0c057bb2: /* original f018, guest PC 0x0c057bb2 */
if(!s->budget--) { s->failed_pc=0x0c057bb2u; return 0; }
vf3_matrix_load(s,ram,0,r[1]);
goto P_0c057bb4;
P_0c057bb4: /* original d107, guest PC 0x0c057bb4 */
if(!s->budget--) { s->failed_pc=0x0c057bb4u; return 0; }
r[1]=read(ram,0x0c057bd4u,4);
goto P_0c057bb6;
P_0c057bb6: /* original f218, guest PC 0x0c057bb6 */
if(!s->budget--) { s->failed_pc=0x0c057bb6u; return 0; }
vf3_matrix_load(s,ram,2,r[1]);
goto P_0c057bb8;
P_0c057bb8: /* original f022, guest PC 0x0c057bb8 */
if(!s->budget--) { s->failed_pc=0x0c057bb8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'*');
goto P_0c057bba;
P_0c057bba: /* original f03d, guest PC 0x0c057bba */
if(!s->budget--) { s->failed_pc=0x0c057bbau; return 0; }
r[53]=truncate_float(fr[0]);
goto P_0c057bbc;
P_0c057bbc: /* original 015a, guest PC 0x0c057bbc */
if(!s->budget--) { s->failed_pc=0x0c057bbcu; return 0; }
r[1]=r[53];
goto P_0c057bbe;
P_0c057bbe: /* original 4128, guest PC 0x0c057bbe */
if(!s->budget--) { s->failed_pc=0x0c057bbeu; return 0; }
r[1]<<=16;
goto P_0c057bc0;
P_0c057bc0: /* original 4118, guest PC 0x0c057bc0 */
if(!s->budget--) { s->failed_pc=0x0c057bc0u; return 0; }
r[1]<<=8;
goto P_0c057bc2;
P_0c057bc2: /* original 201b, guest PC 0x0c057bc2 */
if(!s->budget--) { s->failed_pc=0x0c057bc2u; return 0; }
r[0]|=r[1];
goto P_0c057bc4;
P_0c057bc4: /* original fcfb, guest PC 0x0c057bc4 */
if(!s->budget--) { s->failed_pc=0x0c057bc4u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[12]);
goto P_0c057bc6;
P_0c057bc6: /* original fceb, guest PC 0x0c057bc6 */
if(!s->budget--) { s->failed_pc=0x0c057bc6u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[12]);
goto P_0c057bc8;
P_0c057bc8: /* original 1c03, guest PC 0x0c057bc8 */
if(!s->budget--) { s->failed_pc=0x0c057bc8u; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c057bca;
P_0c057bca: /* original fcdb, guest PC 0x0c057bca */
if(!s->budget--) { s->failed_pc=0x0c057bcau; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[12]);
goto P_0c057bcc;
P_0c057bcc: /* original 78fa, guest PC 0x0c057bcc */
if(!s->budget--) { s->failed_pc=0x0c057bccu; return 0; }
r[8]+=0xfffffffau;
goto P_0c057bce;
P_0c057bce: /* original fccb, guest PC 0x0c057bce */
if(!s->budget--) { s->failed_pc=0x0c057bceu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[12]);
goto P_0c057bd0;
P_0c057bd0: /* original 000b, guest PC 0x0c057bd0 */
if(!s->budget--) { s->failed_pc=0x0c057bd0u; return 0; }
target=r[16];
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
s->pc=target; return ram->oob==0;
P_0c057bd2: /* original 2c66, guest PC 0x0c057bd2 */
if(!s->budget--) { s->failed_pc=0x0c057bd2u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
return vf3_matrix_family(0x0c057bd4u,s,ram);
P_0c057e60: /* original 8581, guest PC 0x0c057e60 */
if(!s->budget--) { s->failed_pc=0x0c057e60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+2,2);
goto P_0c057e62;
P_0c057e62: /* original 6209, guest PC 0x0c057e62 */
if(!s->budget--) { s->failed_pc=0x0c057e62u; return 0; }
r[2]=(r[0]<<16)|(r[0]>>16);
goto P_0c057e64;
P_0c057e64: /* original 7c0c, guest PC 0x0c057e64 */
if(!s->budget--) { s->failed_pc=0x0c057e64u; return 0; }
r[12]+=0x0000000cu;
goto P_0c057e66;
P_0c057e66: /* original 8582, guest PC 0x0c057e66 */
if(!s->budget--) { s->failed_pc=0x0c057e66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+4,2);
goto P_0c057e68;
P_0c057e68: /* original 220d, guest PC 0x0c057e68 */
if(!s->budget--) { s->failed_pc=0x0c057e68u; return 0; }
r[2]=(r[2]>>16)|(r[0]<<16);
goto P_0c057e6a;
P_0c057e6a: /* original fc6a, guest PC 0x0c057e6a */
if(!s->budget--) { s->failed_pc=0x0c057e6au; return 0; }
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c057e6c;
P_0c057e6c: /* original e000, guest PC 0x0c057e6c */
if(!s->budget--) { s->failed_pc=0x0c057e6cu; return 0; }
r[0]=0x00000000u;
goto P_0c057e6e;
P_0c057e6e: /* original 1c04, guest PC 0x0c057e6e */
if(!s->budget--) { s->failed_pc=0x0c057e6eu; return 0; }
write(ram,r[12]+16,r[0],4);
goto P_0c057e70;
P_0c057e70: /* original 1c23, guest PC 0x0c057e70 */
if(!s->budget--) { s->failed_pc=0x0c057e70u; return 0; }
write(ram,r[12]+12,r[2],4);
goto P_0c057e72;
P_0c057e72: /* original f132, guest PC 0x0c057e72 */
if(!s->budget--) { s->failed_pc=0x0c057e72u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c057e74;
P_0c057e74: /* original fc5b, guest PC 0x0c057e74 */
if(!s->budget--) { s->failed_pc=0x0c057e74u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c057e76;
P_0c057e76: /* original e000, guest PC 0x0c057e76 */
if(!s->budget--) { s->failed_pc=0x0c057e76u; return 0; }
r[0]=0x00000000u;
goto P_0c057e78;
P_0c057e78: /* original fc4b, guest PC 0x0c057e78 */
if(!s->budget--) { s->failed_pc=0x0c057e78u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c057e7a;
P_0c057e7a: /* original 2c66, guest PC 0x0c057e7a */
if(!s->budget--) { s->failed_pc=0x0c057e7au; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c057e7c;
P_0c057e7c: /* original 000b, guest PC 0x0c057e7c */
if(!s->budget--) { s->failed_pc=0x0c057e7cu; return 0; }
target=r[16];
write(ram,r[12]+16,r[0],4);
s->pc=target; return ram->oob==0;
P_0c057e7e: /* original 1c04, guest PC 0x0c057e7e */
if(!s->budget--) { s->failed_pc=0x0c057e7eu; return 0; }
write(ram,r[12]+16,r[0],4);
goto P_0c057e80;
P_0c057e80: /* original 0c83, guest PC 0x0c057e80 */
if(!s->budget--) { s->failed_pc=0x0c057e80u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c057e82;
P_0c057e82: /* original 7808, guest PC 0x0c057e82 */
if(!s->budget--) { s->failed_pc=0x0c057e82u; return 0; }
r[8]+=0x00000008u;
goto P_0c057e84;
P_0c057e84: /* original 6085, guest PC 0x0c057e84 */
if(!s->budget--) { s->failed_pc=0x0c057e84u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[0]=tmp;
goto P_0c057e86;
P_0c057e86: /* original 7c2c, guest PC 0x0c057e86 */
if(!s->budget--) { s->failed_pc=0x0c057e86u; return 0; }
r[12]+=0x0000002cu;
goto P_0c057e88;
P_0c057e88: /* original 4028, guest PC 0x0c057e88 */
if(!s->budget--) { s->failed_pc=0x0c057e88u; return 0; }
r[0]<<=16;
goto P_0c057e8a;
P_0c057e8a: /* original 6285, guest PC 0x0c057e8a */
if(!s->budget--) { s->failed_pc=0x0c057e8au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c057e8c;
P_0c057e8c: /* original 202d, guest PC 0x0c057e8c */
if(!s->budget--) { s->failed_pc=0x0c057e8cu; return 0; }
r[0]=(r[0]>>16)|(r[2]<<16);
goto P_0c057e8e;
P_0c057e8e: /* original fcaa, guest PC 0x0c057e8e */
if(!s->budget--) { s->failed_pc=0x0c057e8eu; return 0; }
vf3_matrix_store(s,ram,10,r[12]);
goto P_0c057e90;
P_0c057e90: /* original e101, guest PC 0x0c057e90 */
if(!s->budget--) { s->failed_pc=0x0c057e90u; return 0; }
r[1]=0x00000001u;
goto P_0c057e92;
P_0c057e92: /* original 1c14, guest PC 0x0c057e92 */
if(!s->budget--) { s->failed_pc=0x0c057e92u; return 0; }
write(ram,r[12]+16,r[1],4);
goto P_0c057e94;
P_0c057e94: /* original 1c03, guest PC 0x0c057e94 */
if(!s->budget--) { s->failed_pc=0x0c057e94u; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c057e96;
P_0c057e96: /* original fc9b, guest PC 0x0c057e96 */
if(!s->budget--) { s->failed_pc=0x0c057e96u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c057e98;
P_0c057e98: /* original e000, guest PC 0x0c057e98 */
if(!s->budget--) { s->failed_pc=0x0c057e98u; return 0; }
r[0]=0x00000000u;
goto P_0c057e9a;
P_0c057e9a: /* original fc8b, guest PC 0x0c057e9a */
if(!s->budget--) { s->failed_pc=0x0c057e9au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c057e9c;
P_0c057e9c: /* original 78f4, guest PC 0x0c057e9c */
if(!s->budget--) { s->failed_pc=0x0c057e9cu; return 0; }
r[8]+=0xfffffff4u;
goto P_0c057e9e;
P_0c057e9e: /* original 2c66, guest PC 0x0c057e9e */
if(!s->budget--) { s->failed_pc=0x0c057e9eu; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c057ea0;
P_0c057ea0: /* original 000b, guest PC 0x0c057ea0 */
if(!s->budget--) { s->failed_pc=0x0c057ea0u; return 0; }
target=r[16];
write(ram,r[12]+16,r[0],4);
s->pc=target; return ram->oob==0;
P_0c057ea2: /* original 1c04, guest PC 0x0c057ea2 */
if(!s->budget--) { s->failed_pc=0x0c057ea2u; return 0; }
write(ram,r[12]+16,r[0],4);
goto P_0c057ea4;
P_0c057ea4: /* original 0c83, guest PC 0x0c057ea4 */
if(!s->budget--) { s->failed_pc=0x0c057ea4u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c057ea6;
P_0c057ea6: /* original 780e, guest PC 0x0c057ea6 */
if(!s->budget--) { s->failed_pc=0x0c057ea6u; return 0; }
r[8]+=0x0000000eu;
goto P_0c057ea8;
P_0c057ea8: /* original 6085, guest PC 0x0c057ea8 */
if(!s->budget--) { s->failed_pc=0x0c057ea8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[0]=tmp;
goto P_0c057eaa;
P_0c057eaa: /* original 7c2c, guest PC 0x0c057eaa */
if(!s->budget--) { s->failed_pc=0x0c057eaau; return 0; }
r[12]+=0x0000002cu;
goto P_0c057eac;
P_0c057eac: /* original 4028, guest PC 0x0c057eac */
if(!s->budget--) { s->failed_pc=0x0c057eacu; return 0; }
r[0]<<=16;
goto P_0c057eae;
P_0c057eae: /* original 6285, guest PC 0x0c057eae */
if(!s->budget--) { s->failed_pc=0x0c057eaeu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c057eb0;
P_0c057eb0: /* original 202d, guest PC 0x0c057eb0 */
if(!s->budget--) { s->failed_pc=0x0c057eb0u; return 0; }
r[0]=(r[0]>>16)|(r[2]<<16);
goto P_0c057eb2;
P_0c057eb2: /* original fcea, guest PC 0x0c057eb2 */
if(!s->budget--) { s->failed_pc=0x0c057eb2u; return 0; }
vf3_matrix_store(s,ram,14,r[12]);
goto P_0c057eb4;
P_0c057eb4: /* original e100, guest PC 0x0c057eb4 */
if(!s->budget--) { s->failed_pc=0x0c057eb4u; return 0; }
r[1]=0x00000000u;
goto P_0c057eb6;
P_0c057eb6: /* original 1c14, guest PC 0x0c057eb6 */
if(!s->budget--) { s->failed_pc=0x0c057eb6u; return 0; }
write(ram,r[12]+16,r[1],4);
goto P_0c057eb8;
P_0c057eb8: /* original 1c03, guest PC 0x0c057eb8 */
if(!s->budget--) { s->failed_pc=0x0c057eb8u; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c057eba;
P_0c057eba: /* original fcdb, guest PC 0x0c057eba */
if(!s->budget--) { s->failed_pc=0x0c057ebau; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[12]);
goto P_0c057ebc;
P_0c057ebc: /* original 78ee, guest PC 0x0c057ebc */
if(!s->budget--) { s->failed_pc=0x0c057ebcu; return 0; }
r[8]+=0xffffffeeu;
goto P_0c057ebe;
P_0c057ebe: /* original fccb, guest PC 0x0c057ebe */
if(!s->budget--) { s->failed_pc=0x0c057ebeu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[12]);
goto P_0c057ec0;
P_0c057ec0: /* original e000, guest PC 0x0c057ec0 */
if(!s->budget--) { s->failed_pc=0x0c057ec0u; return 0; }
r[0]=0x00000000u;
goto P_0c057ec2;
P_0c057ec2: /* original 2c66, guest PC 0x0c057ec2 */
if(!s->budget--) { s->failed_pc=0x0c057ec2u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c057ec4;
P_0c057ec4: /* original 000b, guest PC 0x0c057ec4 */
if(!s->budget--) { s->failed_pc=0x0c057ec4u; return 0; }
target=r[16];
write(ram,r[12]+16,r[0],4);
s->pc=target; return ram->oob==0;
P_0c057ec6: /* original 1c04, guest PC 0x0c057ec6 */
if(!s->budget--) { s->failed_pc=0x0c057ec6u; return 0; }
write(ram,r[12]+16,r[0],4);
return vf3_matrix_family(0x0c057ec8u,s,ram);
P_0c057ee0: /* original 8581, guest PC 0x0c057ee0 */
if(!s->budget--) { s->failed_pc=0x0c057ee0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+2,2);
goto P_0c057ee2;
P_0c057ee2: /* original 6209, guest PC 0x0c057ee2 */
if(!s->budget--) { s->failed_pc=0x0c057ee2u; return 0; }
r[2]=(r[0]<<16)|(r[0]>>16);
goto P_0c057ee4;
P_0c057ee4: /* original 7c0c, guest PC 0x0c057ee4 */
if(!s->budget--) { s->failed_pc=0x0c057ee4u; return 0; }
r[12]+=0x0000000cu;
goto P_0c057ee6;
P_0c057ee6: /* original 8582, guest PC 0x0c057ee6 */
if(!s->budget--) { s->failed_pc=0x0c057ee6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+4,2);
goto P_0c057ee8;
P_0c057ee8: /* original d10a, guest PC 0x0c057ee8 */
if(!s->budget--) { s->failed_pc=0x0c057ee8u; return 0; }
r[1]=read(ram,0x0c057f14u,4);
goto P_0c057eea;
P_0c057eea: /* original 6112, guest PC 0x0c057eea */
if(!s->budget--) { s->failed_pc=0x0c057eeau; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c057eec;
P_0c057eec: /* original 630d, guest PC 0x0c057eec */
if(!s->budget--) { s->failed_pc=0x0c057eecu; return 0; }
r[3]=r[0]&65535u;
goto P_0c057eee;
P_0c057eee: /* original 4319, guest PC 0x0c057eee */
if(!s->budget--) { s->failed_pc=0x0c057eeeu; return 0; }
r[3]>>=8;
goto P_0c057ef0;
P_0c057ef0: /* original 231e, guest PC 0x0c057ef0 */
if(!s->budget--) { s->failed_pc=0x0c057ef0u; return 0; }
r[19]=(r[3]&65535u)*(r[1]&65535u);
goto P_0c057ef2;
P_0c057ef2: /* original 031a, guest PC 0x0c057ef2 */
if(!s->budget--) { s->failed_pc=0x0c057ef2u; return 0; }
r[3]=r[19];
goto P_0c057ef4;
P_0c057ef4: /* original 4319, guest PC 0x0c057ef4 */
if(!s->budget--) { s->failed_pc=0x0c057ef4u; return 0; }
r[3]>>=8;
goto P_0c057ef6;
P_0c057ef6: /* original 4318, guest PC 0x0c057ef6 */
if(!s->budget--) { s->failed_pc=0x0c057ef6u; return 0; }
r[3]<<=8;
goto P_0c057ef8;
P_0c057ef8: /* original c9ff, guest PC 0x0c057ef8 */
if(!s->budget--) { s->failed_pc=0x0c057ef8u; return 0; }
r[0]&=255u;
goto P_0c057efa;
P_0c057efa: /* original 203b, guest PC 0x0c057efa */
if(!s->budget--) { s->failed_pc=0x0c057efau; return 0; }
r[0]|=r[3];
goto P_0c057efc;
P_0c057efc: /* original 220d, guest PC 0x0c057efc */
if(!s->budget--) { s->failed_pc=0x0c057efcu; return 0; }
r[2]=(r[2]>>16)|(r[0]<<16);
goto P_0c057efe;
P_0c057efe: /* original fc6a, guest PC 0x0c057efe */
if(!s->budget--) { s->failed_pc=0x0c057efeu; return 0; }
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c057f00;
P_0c057f00: /* original 1c23, guest PC 0x0c057f00 */
if(!s->budget--) { s->failed_pc=0x0c057f00u; return 0; }
write(ram,r[12]+12,r[2],4);
goto P_0c057f02;
P_0c057f02: /* original e000, guest PC 0x0c057f02 */
if(!s->budget--) { s->failed_pc=0x0c057f02u; return 0; }
r[0]=0x00000000u;
goto P_0c057f04;
P_0c057f04: /* original 1c04, guest PC 0x0c057f04 */
if(!s->budget--) { s->failed_pc=0x0c057f04u; return 0; }
write(ram,r[12]+16,r[0],4);
goto P_0c057f06;
P_0c057f06: /* original fc5b, guest PC 0x0c057f06 */
if(!s->budget--) { s->failed_pc=0x0c057f06u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c057f08;
P_0c057f08: /* original e000, guest PC 0x0c057f08 */
if(!s->budget--) { s->failed_pc=0x0c057f08u; return 0; }
r[0]=0x00000000u;
goto P_0c057f0a;
P_0c057f0a: /* original fc4b, guest PC 0x0c057f0a */
if(!s->budget--) { s->failed_pc=0x0c057f0au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c057f0c;
P_0c057f0c: /* original 2c66, guest PC 0x0c057f0c */
if(!s->budget--) { s->failed_pc=0x0c057f0cu; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c057f0e;
P_0c057f0e: /* original 000b, guest PC 0x0c057f0e */
if(!s->budget--) { s->failed_pc=0x0c057f0eu; return 0; }
target=r[16];
write(ram,r[12]+16,r[0],4);
s->pc=target; return ram->oob==0;
P_0c057f10: /* original 1c04, guest PC 0x0c057f10 */
if(!s->budget--) { s->failed_pc=0x0c057f10u; return 0; }
write(ram,r[12]+16,r[0],4);
return vf3_matrix_family(0x0c057f12u,s,ram);
P_0c057f18: /* original 0c83, guest PC 0x0c057f18 */
if(!s->budget--) { s->failed_pc=0x0c057f18u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c057f1a;
P_0c057f1a: /* original 7808, guest PC 0x0c057f1a */
if(!s->budget--) { s->failed_pc=0x0c057f1au; return 0; }
r[8]+=0x00000008u;
goto P_0c057f1c;
P_0c057f1c: /* original 7c2c, guest PC 0x0c057f1c */
if(!s->budget--) { s->failed_pc=0x0c057f1cu; return 0; }
r[12]+=0x0000002cu;
goto P_0c057f1e;
P_0c057f1e: /* original 6285, guest PC 0x0c057f1e */
if(!s->budget--) { s->failed_pc=0x0c057f1eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c057f20;
P_0c057f20: /* original 6229, guest PC 0x0c057f20 */
if(!s->budget--) { s->failed_pc=0x0c057f20u; return 0; }
r[2]=(r[2]<<16)|(r[2]>>16);
goto P_0c057f22;
P_0c057f22: /* original 6085, guest PC 0x0c057f22 */
if(!s->budget--) { s->failed_pc=0x0c057f22u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[0]=tmp;
goto P_0c057f24;
P_0c057f24: /* original d109, guest PC 0x0c057f24 */
if(!s->budget--) { s->failed_pc=0x0c057f24u; return 0; }
r[1]=read(ram,0x0c057f4cu,4);
goto P_0c057f26;
P_0c057f26: /* original 6112, guest PC 0x0c057f26 */
if(!s->budget--) { s->failed_pc=0x0c057f26u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c057f28;
P_0c057f28: /* original 630d, guest PC 0x0c057f28 */
if(!s->budget--) { s->failed_pc=0x0c057f28u; return 0; }
r[3]=r[0]&65535u;
goto P_0c057f2a;
P_0c057f2a: /* original 4319, guest PC 0x0c057f2a */
if(!s->budget--) { s->failed_pc=0x0c057f2au; return 0; }
r[3]>>=8;
goto P_0c057f2c;
P_0c057f2c: /* original 231e, guest PC 0x0c057f2c */
if(!s->budget--) { s->failed_pc=0x0c057f2cu; return 0; }
r[19]=(r[3]&65535u)*(r[1]&65535u);
goto P_0c057f2e;
P_0c057f2e: /* original 031a, guest PC 0x0c057f2e */
if(!s->budget--) { s->failed_pc=0x0c057f2eu; return 0; }
r[3]=r[19];
goto P_0c057f30;
P_0c057f30: /* original 4319, guest PC 0x0c057f30 */
if(!s->budget--) { s->failed_pc=0x0c057f30u; return 0; }
r[3]>>=8;
goto P_0c057f32;
P_0c057f32: /* original 4318, guest PC 0x0c057f32 */
if(!s->budget--) { s->failed_pc=0x0c057f32u; return 0; }
r[3]<<=8;
goto P_0c057f34;
P_0c057f34: /* original c9ff, guest PC 0x0c057f34 */
if(!s->budget--) { s->failed_pc=0x0c057f34u; return 0; }
r[0]&=255u;
goto P_0c057f36;
P_0c057f36: /* original 203b, guest PC 0x0c057f36 */
if(!s->budget--) { s->failed_pc=0x0c057f36u; return 0; }
r[0]|=r[3];
goto P_0c057f38;
P_0c057f38: /* original 220d, guest PC 0x0c057f38 */
if(!s->budget--) { s->failed_pc=0x0c057f38u; return 0; }
r[2]=(r[2]>>16)|(r[0]<<16);
goto P_0c057f3a;
P_0c057f3a: /* original fcaa, guest PC 0x0c057f3a */
if(!s->budget--) { s->failed_pc=0x0c057f3au; return 0; }
vf3_matrix_store(s,ram,10,r[12]);
goto P_0c057f3c;
P_0c057f3c: /* original 1c23, guest PC 0x0c057f3c */
if(!s->budget--) { s->failed_pc=0x0c057f3cu; return 0; }
write(ram,r[12]+12,r[2],4);
goto P_0c057f3e;
P_0c057f3e: /* original fc9b, guest PC 0x0c057f3e */
if(!s->budget--) { s->failed_pc=0x0c057f3eu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c057f40;
P_0c057f40: /* original e000, guest PC 0x0c057f40 */
if(!s->budget--) { s->failed_pc=0x0c057f40u; return 0; }
r[0]=0x00000000u;
goto P_0c057f42;
P_0c057f42: /* original fc8b, guest PC 0x0c057f42 */
if(!s->budget--) { s->failed_pc=0x0c057f42u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c057f44;
P_0c057f44: /* original 78f4, guest PC 0x0c057f44 */
if(!s->budget--) { s->failed_pc=0x0c057f44u; return 0; }
r[8]+=0xfffffff4u;
goto P_0c057f46;
P_0c057f46: /* original 2c66, guest PC 0x0c057f46 */
if(!s->budget--) { s->failed_pc=0x0c057f46u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c057f48;
P_0c057f48: /* original 000b, guest PC 0x0c057f48 */
if(!s->budget--) { s->failed_pc=0x0c057f48u; return 0; }
target=r[16];
write(ram,r[12]+16,r[0],4);
s->pc=target; return ram->oob==0;
P_0c057f4a: /* original 1c04, guest PC 0x0c057f4a */
if(!s->budget--) { s->failed_pc=0x0c057f4au; return 0; }
write(ram,r[12]+16,r[0],4);
return vf3_matrix_family(0x0c057f4cu,s,ram);
P_0c057f50: /* original 0c83, guest PC 0x0c057f50 */
if(!s->budget--) { s->failed_pc=0x0c057f50u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c057f52;
P_0c057f52: /* original 780e, guest PC 0x0c057f52 */
if(!s->budget--) { s->failed_pc=0x0c057f52u; return 0; }
r[8]+=0x0000000eu;
goto P_0c057f54;
P_0c057f54: /* original 6285, guest PC 0x0c057f54 */
if(!s->budget--) { s->failed_pc=0x0c057f54u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c057f56;
P_0c057f56: /* original 6229, guest PC 0x0c057f56 */
if(!s->budget--) { s->failed_pc=0x0c057f56u; return 0; }
r[2]=(r[2]<<16)|(r[2]>>16);
goto P_0c057f58;
P_0c057f58: /* original 7c2c, guest PC 0x0c057f58 */
if(!s->budget--) { s->failed_pc=0x0c057f58u; return 0; }
r[12]+=0x0000002cu;
goto P_0c057f5a;
P_0c057f5a: /* original 6085, guest PC 0x0c057f5a */
if(!s->budget--) { s->failed_pc=0x0c057f5au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[0]=tmp;
goto P_0c057f5c;
P_0c057f5c: /* original d109, guest PC 0x0c057f5c */
if(!s->budget--) { s->failed_pc=0x0c057f5cu; return 0; }
r[1]=read(ram,0x0c057f84u,4);
goto P_0c057f5e;
P_0c057f5e: /* original 6112, guest PC 0x0c057f5e */
if(!s->budget--) { s->failed_pc=0x0c057f5eu; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c057f60;
P_0c057f60: /* original 630d, guest PC 0x0c057f60 */
if(!s->budget--) { s->failed_pc=0x0c057f60u; return 0; }
r[3]=r[0]&65535u;
goto P_0c057f62;
P_0c057f62: /* original 4319, guest PC 0x0c057f62 */
if(!s->budget--) { s->failed_pc=0x0c057f62u; return 0; }
r[3]>>=8;
goto P_0c057f64;
P_0c057f64: /* original 231e, guest PC 0x0c057f64 */
if(!s->budget--) { s->failed_pc=0x0c057f64u; return 0; }
r[19]=(r[3]&65535u)*(r[1]&65535u);
goto P_0c057f66;
P_0c057f66: /* original 031a, guest PC 0x0c057f66 */
if(!s->budget--) { s->failed_pc=0x0c057f66u; return 0; }
r[3]=r[19];
goto P_0c057f68;
P_0c057f68: /* original 4319, guest PC 0x0c057f68 */
if(!s->budget--) { s->failed_pc=0x0c057f68u; return 0; }
r[3]>>=8;
goto P_0c057f6a;
P_0c057f6a: /* original 4318, guest PC 0x0c057f6a */
if(!s->budget--) { s->failed_pc=0x0c057f6au; return 0; }
r[3]<<=8;
goto P_0c057f6c;
P_0c057f6c: /* original c9ff, guest PC 0x0c057f6c */
if(!s->budget--) { s->failed_pc=0x0c057f6cu; return 0; }
r[0]&=255u;
goto P_0c057f6e;
P_0c057f6e: /* original 203b, guest PC 0x0c057f6e */
if(!s->budget--) { s->failed_pc=0x0c057f6eu; return 0; }
r[0]|=r[3];
goto P_0c057f70;
P_0c057f70: /* original 220d, guest PC 0x0c057f70 */
if(!s->budget--) { s->failed_pc=0x0c057f70u; return 0; }
r[2]=(r[2]>>16)|(r[0]<<16);
goto P_0c057f72;
P_0c057f72: /* original fcea, guest PC 0x0c057f72 */
if(!s->budget--) { s->failed_pc=0x0c057f72u; return 0; }
vf3_matrix_store(s,ram,14,r[12]);
goto P_0c057f74;
P_0c057f74: /* original 1c23, guest PC 0x0c057f74 */
if(!s->budget--) { s->failed_pc=0x0c057f74u; return 0; }
write(ram,r[12]+12,r[2],4);
goto P_0c057f76;
P_0c057f76: /* original fcdb, guest PC 0x0c057f76 */
if(!s->budget--) { s->failed_pc=0x0c057f76u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[12]);
goto P_0c057f78;
P_0c057f78: /* original 78ee, guest PC 0x0c057f78 */
if(!s->budget--) { s->failed_pc=0x0c057f78u; return 0; }
r[8]+=0xffffffeeu;
goto P_0c057f7a;
P_0c057f7a: /* original fccb, guest PC 0x0c057f7a */
if(!s->budget--) { s->failed_pc=0x0c057f7au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[12]);
goto P_0c057f7c;
P_0c057f7c: /* original e000, guest PC 0x0c057f7c */
if(!s->budget--) { s->failed_pc=0x0c057f7cu; return 0; }
r[0]=0x00000000u;
goto P_0c057f7e;
P_0c057f7e: /* original 2c66, guest PC 0x0c057f7e */
if(!s->budget--) { s->failed_pc=0x0c057f7eu; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c057f80;
P_0c057f80: /* original 000b, guest PC 0x0c057f80 */
if(!s->budget--) { s->failed_pc=0x0c057f80u; return 0; }
target=r[16];
write(ram,r[12]+16,r[0],4);
s->pc=target; return ram->oob==0;
P_0c057f82: /* original 1c04, guest PC 0x0c057f82 */
if(!s->budget--) { s->failed_pc=0x0c057f82u; return 0; }
write(ram,r[12]+16,r[0],4);
return vf3_matrix_family(0x0c057f84u,s,ram);
P_0c0581a0: /* original 8583, guest PC 0x0c0581a0 */
if(!s->budget--) { s->failed_pc=0x0c0581a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+6,2);
goto P_0c0581a2;
P_0c0581a2: /* original 7802, guest PC 0x0c0581a2 */
if(!s->budget--) { s->failed_pc=0x0c0581a2u; return 0; }
r[8]+=0x00000002u;
goto P_0c0581a4;
P_0c0581a4: /* original 6385, guest PC 0x0c0581a4 */
if(!s->budget--) { s->failed_pc=0x0c0581a4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[3]=tmp;
goto P_0c0581a6;
P_0c0581a6: /* original 6209, guest PC 0x0c0581a6 */
if(!s->budget--) { s->failed_pc=0x0c0581a6u; return 0; }
r[2]=(r[0]<<16)|(r[0]>>16);
goto P_0c0581a8;
P_0c0581a8: /* original 6185, guest PC 0x0c0581a8 */
if(!s->budget--) { s->failed_pc=0x0c0581a8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[1]=tmp;
goto P_0c0581aa;
P_0c0581aa: /* original 7c0c, guest PC 0x0c0581aa */
if(!s->budget--) { s->failed_pc=0x0c0581aau; return 0; }
r[12]+=0x0000000cu;
goto P_0c0581ac;
P_0c0581ac: /* original 8581, guest PC 0x0c0581ac */
if(!s->budget--) { s->failed_pc=0x0c0581acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+2,2);
goto P_0c0581ae;
P_0c0581ae: /* original 78fa, guest PC 0x0c0581ae */
if(!s->budget--) { s->failed_pc=0x0c0581aeu; return 0; }
r[8]+=0xfffffffau;
goto P_0c0581b0;
P_0c0581b0: /* original 435a, guest PC 0x0c0581b0 */
if(!s->budget--) { s->failed_pc=0x0c0581b0u; return 0; }
r[53]=r[3];
goto P_0c0581b2;
P_0c0581b2: /* original f02d, guest PC 0x0c0581b2 */
if(!s->budget--) { s->failed_pc=0x0c0581b2u; return 0; }
fr[0]=vf3_fpu_float(r[53],r[18]);
goto P_0c0581b4;
P_0c0581b4: /* original 415a, guest PC 0x0c0581b4 */
if(!s->budget--) { s->failed_pc=0x0c0581b4u; return 0; }
r[53]=r[1];
goto P_0c0581b6;
P_0c0581b6: /* original 220d, guest PC 0x0c0581b6 */
if(!s->budget--) { s->failed_pc=0x0c0581b6u; return 0; }
r[2]=(r[2]>>16)|(r[0]<<16);
goto P_0c0581b8;
P_0c0581b8: /* original f12d, guest PC 0x0c0581b8 */
if(!s->budget--) { s->failed_pc=0x0c0581b8u; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c0581ba;
P_0c0581ba: /* original fc6a, guest PC 0x0c0581ba */
if(!s->budget--) { s->failed_pc=0x0c0581bau; return 0; }
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c0581bc;
P_0c0581bc: /* original f032, guest PC 0x0c0581bc */
if(!s->budget--) { s->failed_pc=0x0c0581bcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0581be;
P_0c0581be: /* original 1c23, guest PC 0x0c0581be */
if(!s->budget--) { s->failed_pc=0x0c0581beu; return 0; }
write(ram,r[12]+12,r[2],4);
goto P_0c0581c0;
P_0c0581c0: /* original f132, guest PC 0x0c0581c0 */
if(!s->budget--) { s->failed_pc=0x0c0581c0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0581c2;
P_0c0581c2: /* original fc5b, guest PC 0x0c0581c2 */
if(!s->budget--) { s->failed_pc=0x0c0581c2u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c0581c4;
P_0c0581c4: /* original e010, guest PC 0x0c0581c4 */
if(!s->budget--) { s->failed_pc=0x0c0581c4u; return 0; }
r[0]=0x00000010u;
goto P_0c0581c6;
P_0c0581c6: /* original fc4b, guest PC 0x0c0581c6 */
if(!s->budget--) { s->failed_pc=0x0c0581c6u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c0581c8;
P_0c0581c8: /* original 2c66, guest PC 0x0c0581c8 */
if(!s->budget--) { s->failed_pc=0x0c0581c8u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c0581ca;
P_0c0581ca: /* original fc07, guest PC 0x0c0581ca */
if(!s->budget--) { s->failed_pc=0x0c0581cau; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
goto P_0c0581cc;
P_0c0581cc: /* original e014, guest PC 0x0c0581cc */
if(!s->budget--) { s->failed_pc=0x0c0581ccu; return 0; }
r[0]=0x00000014u;
goto P_0c0581ce;
P_0c0581ce: /* original 000b, guest PC 0x0c0581ce */
if(!s->budget--) { s->failed_pc=0x0c0581ceu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,1,r[12]+r[0]);
s->pc=target; return ram->oob==0;
P_0c0581d0: /* original fc17, guest PC 0x0c0581d0 */
if(!s->budget--) { s->failed_pc=0x0c0581d0u; return 0; }
vf3_matrix_store(s,ram,1,r[12]+r[0]);
goto P_0c0581d2;
P_0c0581d2: /* original 0c83, guest PC 0x0c0581d2 */
if(!s->budget--) { s->failed_pc=0x0c0581d2u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c0581d4;
P_0c0581d4: /* original 780c, guest PC 0x0c0581d4 */
if(!s->budget--) { s->failed_pc=0x0c0581d4u; return 0; }
r[8]+=0x0000000cu;
goto P_0c0581d6;
P_0c0581d6: /* original 6385, guest PC 0x0c0581d6 */
if(!s->budget--) { s->failed_pc=0x0c0581d6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[3]=tmp;
goto P_0c0581d8;
P_0c0581d8: /* original 6185, guest PC 0x0c0581d8 */
if(!s->budget--) { s->failed_pc=0x0c0581d8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[1]=tmp;
goto P_0c0581da;
P_0c0581da: /* original 6085, guest PC 0x0c0581da */
if(!s->budget--) { s->failed_pc=0x0c0581dau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[0]=tmp;
goto P_0c0581dc;
P_0c0581dc: /* original 7c2c, guest PC 0x0c0581dc */
if(!s->budget--) { s->failed_pc=0x0c0581dcu; return 0; }
r[12]+=0x0000002cu;
goto P_0c0581de;
P_0c0581de: /* original 415a, guest PC 0x0c0581de */
if(!s->budget--) { s->failed_pc=0x0c0581deu; return 0; }
r[53]=r[1];
goto P_0c0581e0;
P_0c0581e0: /* original 4028, guest PC 0x0c0581e0 */
if(!s->budget--) { s->failed_pc=0x0c0581e0u; return 0; }
r[0]<<=16;
goto P_0c0581e2;
P_0c0581e2: /* original 6285, guest PC 0x0c0581e2 */
if(!s->budget--) { s->failed_pc=0x0c0581e2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c0581e4;
P_0c0581e4: /* original f12d, guest PC 0x0c0581e4 */
if(!s->budget--) { s->failed_pc=0x0c0581e4u; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c0581e6;
P_0c0581e6: /* original 435a, guest PC 0x0c0581e6 */
if(!s->budget--) { s->failed_pc=0x0c0581e6u; return 0; }
r[53]=r[3];
goto P_0c0581e8;
P_0c0581e8: /* original 202d, guest PC 0x0c0581e8 */
if(!s->budget--) { s->failed_pc=0x0c0581e8u; return 0; }
r[0]=(r[0]>>16)|(r[2]<<16);
goto P_0c0581ea;
P_0c0581ea: /* original f02d, guest PC 0x0c0581ea */
if(!s->budget--) { s->failed_pc=0x0c0581eau; return 0; }
fr[0]=vf3_fpu_float(r[53],r[18]);
goto P_0c0581ec;
P_0c0581ec: /* original fcaa, guest PC 0x0c0581ec */
if(!s->budget--) { s->failed_pc=0x0c0581ecu; return 0; }
vf3_matrix_store(s,ram,10,r[12]);
goto P_0c0581ee;
P_0c0581ee: /* original f132, guest PC 0x0c0581ee */
if(!s->budget--) { s->failed_pc=0x0c0581eeu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0581f0;
P_0c0581f0: /* original 1c03, guest PC 0x0c0581f0 */
if(!s->budget--) { s->failed_pc=0x0c0581f0u; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c0581f2;
P_0c0581f2: /* original f032, guest PC 0x0c0581f2 */
if(!s->budget--) { s->failed_pc=0x0c0581f2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0581f4;
P_0c0581f4: /* original fc9b, guest PC 0x0c0581f4 */
if(!s->budget--) { s->failed_pc=0x0c0581f4u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c0581f6;
P_0c0581f6: /* original e014, guest PC 0x0c0581f6 */
if(!s->budget--) { s->failed_pc=0x0c0581f6u; return 0; }
r[0]=0x00000014u;
goto P_0c0581f8;
P_0c0581f8: /* original fc8b, guest PC 0x0c0581f8 */
if(!s->budget--) { s->failed_pc=0x0c0581f8u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c0581fa;
P_0c0581fa: /* original 78ec, guest PC 0x0c0581fa */
if(!s->budget--) { s->failed_pc=0x0c0581fau; return 0; }
r[8]+=0xffffffecu;
goto P_0c0581fc;
P_0c0581fc: /* original 2c66, guest PC 0x0c0581fc */
if(!s->budget--) { s->failed_pc=0x0c0581fcu; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c0581fe;
P_0c0581fe: /* original fc17, guest PC 0x0c0581fe */
if(!s->budget--) { s->failed_pc=0x0c0581feu; return 0; }
vf3_matrix_store(s,ram,1,r[12]+r[0]);
goto P_0c058200;
P_0c058200: /* original e010, guest PC 0x0c058200 */
if(!s->budget--) { s->failed_pc=0x0c058200u; return 0; }
r[0]=0x00000010u;
goto P_0c058202;
P_0c058202: /* original 000b, guest PC 0x0c058202 */
if(!s->budget--) { s->failed_pc=0x0c058202u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,0,r[12]+r[0]);
s->pc=target; return ram->oob==0;
P_0c058204: /* original fc07, guest PC 0x0c058204 */
if(!s->budget--) { s->failed_pc=0x0c058204u; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
goto P_0c058206;
P_0c058206: /* original 0c83, guest PC 0x0c058206 */
if(!s->budget--) { s->failed_pc=0x0c058206u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c058208;
P_0c058208: /* original 7816, guest PC 0x0c058208 */
if(!s->budget--) { s->failed_pc=0x0c058208u; return 0; }
r[8]+=0x00000016u;
goto P_0c05820a;
P_0c05820a: /* original 6385, guest PC 0x0c05820a */
if(!s->budget--) { s->failed_pc=0x0c05820au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[3]=tmp;
goto P_0c05820c;
P_0c05820c: /* original 6185, guest PC 0x0c05820c */
if(!s->budget--) { s->failed_pc=0x0c05820cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[1]=tmp;
goto P_0c05820e;
P_0c05820e: /* original 6085, guest PC 0x0c05820e */
if(!s->budget--) { s->failed_pc=0x0c05820eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[0]=tmp;
goto P_0c058210;
P_0c058210: /* original 7c2c, guest PC 0x0c058210 */
if(!s->budget--) { s->failed_pc=0x0c058210u; return 0; }
r[12]+=0x0000002cu;
goto P_0c058212;
P_0c058212: /* original 415a, guest PC 0x0c058212 */
if(!s->budget--) { s->failed_pc=0x0c058212u; return 0; }
r[53]=r[1];
goto P_0c058214;
P_0c058214: /* original 4028, guest PC 0x0c058214 */
if(!s->budget--) { s->failed_pc=0x0c058214u; return 0; }
r[0]<<=16;
goto P_0c058216;
P_0c058216: /* original 6285, guest PC 0x0c058216 */
if(!s->budget--) { s->failed_pc=0x0c058216u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c058218;
P_0c058218: /* original f12d, guest PC 0x0c058218 */
if(!s->budget--) { s->failed_pc=0x0c058218u; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c05821a;
P_0c05821a: /* original 435a, guest PC 0x0c05821a */
if(!s->budget--) { s->failed_pc=0x0c05821au; return 0; }
r[53]=r[3];
goto P_0c05821c;
P_0c05821c: /* original 202d, guest PC 0x0c05821c */
if(!s->budget--) { s->failed_pc=0x0c05821cu; return 0; }
r[0]=(r[0]>>16)|(r[2]<<16);
goto P_0c05821e;
P_0c05821e: /* original f02d, guest PC 0x0c05821e */
if(!s->budget--) { s->failed_pc=0x0c05821eu; return 0; }
fr[0]=vf3_fpu_float(r[53],r[18]);
goto P_0c058220;
P_0c058220: /* original fcea, guest PC 0x0c058220 */
if(!s->budget--) { s->failed_pc=0x0c058220u; return 0; }
vf3_matrix_store(s,ram,14,r[12]);
goto P_0c058222;
P_0c058222: /* original f132, guest PC 0x0c058222 */
if(!s->budget--) { s->failed_pc=0x0c058222u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c058224;
P_0c058224: /* original 1c03, guest PC 0x0c058224 */
if(!s->budget--) { s->failed_pc=0x0c058224u; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c058226;
P_0c058226: /* original f032, guest PC 0x0c058226 */
if(!s->budget--) { s->failed_pc=0x0c058226u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c058228;
P_0c058228: /* original fcdb, guest PC 0x0c058228 */
if(!s->budget--) { s->failed_pc=0x0c058228u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[12]);
goto P_0c05822a;
P_0c05822a: /* original 78e2, guest PC 0x0c05822a */
if(!s->budget--) { s->failed_pc=0x0c05822au; return 0; }
r[8]+=0xffffffe2u;
goto P_0c05822c;
P_0c05822c: /* original fccb, guest PC 0x0c05822c */
if(!s->budget--) { s->failed_pc=0x0c05822cu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[12]);
goto P_0c05822e;
P_0c05822e: /* original e014, guest PC 0x0c05822e */
if(!s->budget--) { s->failed_pc=0x0c05822eu; return 0; }
r[0]=0x00000014u;
goto P_0c058230;
P_0c058230: /* original 2c66, guest PC 0x0c058230 */
if(!s->budget--) { s->failed_pc=0x0c058230u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c058232;
P_0c058232: /* original fc17, guest PC 0x0c058232 */
if(!s->budget--) { s->failed_pc=0x0c058232u; return 0; }
vf3_matrix_store(s,ram,1,r[12]+r[0]);
goto P_0c058234;
P_0c058234: /* original e010, guest PC 0x0c058234 */
if(!s->budget--) { s->failed_pc=0x0c058234u; return 0; }
r[0]=0x00000010u;
goto P_0c058236;
P_0c058236: /* original 000b, guest PC 0x0c058236 */
if(!s->budget--) { s->failed_pc=0x0c058236u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,0,r[12]+r[0]);
s->pc=target; return ram->oob==0;
P_0c058238: /* original fc07, guest PC 0x0c058238 */
if(!s->budget--) { s->failed_pc=0x0c058238u; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
return vf3_matrix_family(0x0c05823au,s,ram);
P_0c058240: /* original 8583, guest PC 0x0c058240 */
if(!s->budget--) { s->failed_pc=0x0c058240u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+6,2);
goto P_0c058242;
P_0c058242: /* original 7802, guest PC 0x0c058242 */
if(!s->budget--) { s->failed_pc=0x0c058242u; return 0; }
r[8]+=0x00000002u;
goto P_0c058244;
P_0c058244: /* original 6385, guest PC 0x0c058244 */
if(!s->budget--) { s->failed_pc=0x0c058244u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[3]=tmp;
goto P_0c058246;
P_0c058246: /* original 6209, guest PC 0x0c058246 */
if(!s->budget--) { s->failed_pc=0x0c058246u; return 0; }
r[2]=(r[0]<<16)|(r[0]>>16);
goto P_0c058248;
P_0c058248: /* original 6185, guest PC 0x0c058248 */
if(!s->budget--) { s->failed_pc=0x0c058248u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[1]=tmp;
goto P_0c05824a;
P_0c05824a: /* original 7c0c, guest PC 0x0c05824a */
if(!s->budget--) { s->failed_pc=0x0c05824au; return 0; }
r[12]+=0x0000000cu;
goto P_0c05824c;
P_0c05824c: /* original 8581, guest PC 0x0c05824c */
if(!s->budget--) { s->failed_pc=0x0c05824cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+2,2);
goto P_0c05824e;
P_0c05824e: /* original 78fa, guest PC 0x0c05824e */
if(!s->budget--) { s->failed_pc=0x0c05824eu; return 0; }
r[8]+=0xfffffffau;
goto P_0c058250;
P_0c058250: /* original 435a, guest PC 0x0c058250 */
if(!s->budget--) { s->failed_pc=0x0c058250u; return 0; }
r[53]=r[3];
goto P_0c058252;
P_0c058252: /* original f02d, guest PC 0x0c058252 */
if(!s->budget--) { s->failed_pc=0x0c058252u; return 0; }
fr[0]=vf3_fpu_float(r[53],r[18]);
goto P_0c058254;
P_0c058254: /* original 415a, guest PC 0x0c058254 */
if(!s->budget--) { s->failed_pc=0x0c058254u; return 0; }
r[53]=r[1];
goto P_0c058256;
P_0c058256: /* original d10c, guest PC 0x0c058256 */
if(!s->budget--) { s->failed_pc=0x0c058256u; return 0; }
r[1]=read(ram,0x0c058288u,4);
goto P_0c058258;
P_0c058258: /* original 6112, guest PC 0x0c058258 */
if(!s->budget--) { s->failed_pc=0x0c058258u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c05825a;
P_0c05825a: /* original 630d, guest PC 0x0c05825a */
if(!s->budget--) { s->failed_pc=0x0c05825au; return 0; }
r[3]=r[0]&65535u;
goto P_0c05825c;
P_0c05825c: /* original 4319, guest PC 0x0c05825c */
if(!s->budget--) { s->failed_pc=0x0c05825cu; return 0; }
r[3]>>=8;
goto P_0c05825e;
P_0c05825e: /* original 231e, guest PC 0x0c05825e */
if(!s->budget--) { s->failed_pc=0x0c05825eu; return 0; }
r[19]=(r[3]&65535u)*(r[1]&65535u);
goto P_0c058260;
P_0c058260: /* original 031a, guest PC 0x0c058260 */
if(!s->budget--) { s->failed_pc=0x0c058260u; return 0; }
r[3]=r[19];
goto P_0c058262;
P_0c058262: /* original 4319, guest PC 0x0c058262 */
if(!s->budget--) { s->failed_pc=0x0c058262u; return 0; }
r[3]>>=8;
goto P_0c058264;
P_0c058264: /* original 4318, guest PC 0x0c058264 */
if(!s->budget--) { s->failed_pc=0x0c058264u; return 0; }
r[3]<<=8;
goto P_0c058266;
P_0c058266: /* original c9ff, guest PC 0x0c058266 */
if(!s->budget--) { s->failed_pc=0x0c058266u; return 0; }
r[0]&=255u;
goto P_0c058268;
P_0c058268: /* original 203b, guest PC 0x0c058268 */
if(!s->budget--) { s->failed_pc=0x0c058268u; return 0; }
r[0]|=r[3];
goto P_0c05826a;
P_0c05826a: /* original 220d, guest PC 0x0c05826a */
if(!s->budget--) { s->failed_pc=0x0c05826au; return 0; }
r[2]=(r[2]>>16)|(r[0]<<16);
goto P_0c05826c;
P_0c05826c: /* original f12d, guest PC 0x0c05826c */
if(!s->budget--) { s->failed_pc=0x0c05826cu; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c05826e;
P_0c05826e: /* original fc6a, guest PC 0x0c05826e */
if(!s->budget--) { s->failed_pc=0x0c05826eu; return 0; }
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c058270;
P_0c058270: /* original f032, guest PC 0x0c058270 */
if(!s->budget--) { s->failed_pc=0x0c058270u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c058272;
P_0c058272: /* original 1c23, guest PC 0x0c058272 */
if(!s->budget--) { s->failed_pc=0x0c058272u; return 0; }
write(ram,r[12]+12,r[2],4);
goto P_0c058274;
P_0c058274: /* original f132, guest PC 0x0c058274 */
if(!s->budget--) { s->failed_pc=0x0c058274u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c058276;
P_0c058276: /* original fc5b, guest PC 0x0c058276 */
if(!s->budget--) { s->failed_pc=0x0c058276u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c058278;
P_0c058278: /* original e010, guest PC 0x0c058278 */
if(!s->budget--) { s->failed_pc=0x0c058278u; return 0; }
r[0]=0x00000010u;
goto P_0c05827a;
P_0c05827a: /* original fc4b, guest PC 0x0c05827a */
if(!s->budget--) { s->failed_pc=0x0c05827au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c05827c;
P_0c05827c: /* original 2c66, guest PC 0x0c05827c */
if(!s->budget--) { s->failed_pc=0x0c05827cu; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c05827e;
P_0c05827e: /* original fc07, guest PC 0x0c05827e */
if(!s->budget--) { s->failed_pc=0x0c05827eu; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
goto P_0c058280;
P_0c058280: /* original e014, guest PC 0x0c058280 */
if(!s->budget--) { s->failed_pc=0x0c058280u; return 0; }
r[0]=0x00000014u;
goto P_0c058282;
P_0c058282: /* original 000b, guest PC 0x0c058282 */
if(!s->budget--) { s->failed_pc=0x0c058282u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,1,r[12]+r[0]);
s->pc=target; return ram->oob==0;
P_0c058284: /* original fc17, guest PC 0x0c058284 */
if(!s->budget--) { s->failed_pc=0x0c058284u; return 0; }
vf3_matrix_store(s,ram,1,r[12]+r[0]);
return vf3_matrix_family(0x0c058286u,s,ram);
P_0c05828c: /* original 0c83, guest PC 0x0c05828c */
if(!s->budget--) { s->failed_pc=0x0c05828cu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c05828e;
P_0c05828e: /* original 780c, guest PC 0x0c05828e */
if(!s->budget--) { s->failed_pc=0x0c05828eu; return 0; }
r[8]+=0x0000000cu;
goto P_0c058290;
P_0c058290: /* original 6385, guest PC 0x0c058290 */
if(!s->budget--) { s->failed_pc=0x0c058290u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[3]=tmp;
goto P_0c058292;
P_0c058292: /* original 7c2c, guest PC 0x0c058292 */
if(!s->budget--) { s->failed_pc=0x0c058292u; return 0; }
r[12]+=0x0000002cu;
goto P_0c058294;
P_0c058294: /* original 6185, guest PC 0x0c058294 */
if(!s->budget--) { s->failed_pc=0x0c058294u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[1]=tmp;
goto P_0c058296;
P_0c058296: /* original 6285, guest PC 0x0c058296 */
if(!s->budget--) { s->failed_pc=0x0c058296u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c058298;
P_0c058298: /* original 415a, guest PC 0x0c058298 */
if(!s->budget--) { s->failed_pc=0x0c058298u; return 0; }
r[53]=r[1];
goto P_0c05829a;
P_0c05829a: /* original 6229, guest PC 0x0c05829a */
if(!s->budget--) { s->failed_pc=0x0c05829au; return 0; }
r[2]=(r[2]<<16)|(r[2]>>16);
goto P_0c05829c;
P_0c05829c: /* original 6085, guest PC 0x0c05829c */
if(!s->budget--) { s->failed_pc=0x0c05829cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[0]=tmp;
goto P_0c05829e;
P_0c05829e: /* original f12d, guest PC 0x0c05829e */
if(!s->budget--) { s->failed_pc=0x0c05829eu; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c0582a0;
P_0c0582a0: /* original 435a, guest PC 0x0c0582a0 */
if(!s->budget--) { s->failed_pc=0x0c0582a0u; return 0; }
r[53]=r[3];
goto P_0c0582a2;
P_0c0582a2: /* original d10c, guest PC 0x0c0582a2 */
if(!s->budget--) { s->failed_pc=0x0c0582a2u; return 0; }
r[1]=read(ram,0x0c0582d4u,4);
goto P_0c0582a4;
P_0c0582a4: /* original 6112, guest PC 0x0c0582a4 */
if(!s->budget--) { s->failed_pc=0x0c0582a4u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c0582a6;
P_0c0582a6: /* original 630d, guest PC 0x0c0582a6 */
if(!s->budget--) { s->failed_pc=0x0c0582a6u; return 0; }
r[3]=r[0]&65535u;
goto P_0c0582a8;
P_0c0582a8: /* original 4319, guest PC 0x0c0582a8 */
if(!s->budget--) { s->failed_pc=0x0c0582a8u; return 0; }
r[3]>>=8;
goto P_0c0582aa;
P_0c0582aa: /* original 231e, guest PC 0x0c0582aa */
if(!s->budget--) { s->failed_pc=0x0c0582aau; return 0; }
r[19]=(r[3]&65535u)*(r[1]&65535u);
goto P_0c0582ac;
P_0c0582ac: /* original 031a, guest PC 0x0c0582ac */
if(!s->budget--) { s->failed_pc=0x0c0582acu; return 0; }
r[3]=r[19];
goto P_0c0582ae;
P_0c0582ae: /* original 4319, guest PC 0x0c0582ae */
if(!s->budget--) { s->failed_pc=0x0c0582aeu; return 0; }
r[3]>>=8;
goto P_0c0582b0;
P_0c0582b0: /* original 4318, guest PC 0x0c0582b0 */
if(!s->budget--) { s->failed_pc=0x0c0582b0u; return 0; }
r[3]<<=8;
goto P_0c0582b2;
P_0c0582b2: /* original c9ff, guest PC 0x0c0582b2 */
if(!s->budget--) { s->failed_pc=0x0c0582b2u; return 0; }
r[0]&=255u;
goto P_0c0582b4;
P_0c0582b4: /* original 203b, guest PC 0x0c0582b4 */
if(!s->budget--) { s->failed_pc=0x0c0582b4u; return 0; }
r[0]|=r[3];
goto P_0c0582b6;
P_0c0582b6: /* original 220d, guest PC 0x0c0582b6 */
if(!s->budget--) { s->failed_pc=0x0c0582b6u; return 0; }
r[2]=(r[2]>>16)|(r[0]<<16);
goto P_0c0582b8;
P_0c0582b8: /* original f02d, guest PC 0x0c0582b8 */
if(!s->budget--) { s->failed_pc=0x0c0582b8u; return 0; }
fr[0]=vf3_fpu_float(r[53],r[18]);
goto P_0c0582ba;
P_0c0582ba: /* original fcaa, guest PC 0x0c0582ba */
if(!s->budget--) { s->failed_pc=0x0c0582bau; return 0; }
vf3_matrix_store(s,ram,10,r[12]);
goto P_0c0582bc;
P_0c0582bc: /* original f132, guest PC 0x0c0582bc */
if(!s->budget--) { s->failed_pc=0x0c0582bcu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0582be;
P_0c0582be: /* original 1c23, guest PC 0x0c0582be */
if(!s->budget--) { s->failed_pc=0x0c0582beu; return 0; }
write(ram,r[12]+12,r[2],4);
goto P_0c0582c0;
P_0c0582c0: /* original f032, guest PC 0x0c0582c0 */
if(!s->budget--) { s->failed_pc=0x0c0582c0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0582c2;
P_0c0582c2: /* original fc9b, guest PC 0x0c0582c2 */
if(!s->budget--) { s->failed_pc=0x0c0582c2u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c0582c4;
P_0c0582c4: /* original e014, guest PC 0x0c0582c4 */
if(!s->budget--) { s->failed_pc=0x0c0582c4u; return 0; }
r[0]=0x00000014u;
goto P_0c0582c6;
P_0c0582c6: /* original fc8b, guest PC 0x0c0582c6 */
if(!s->budget--) { s->failed_pc=0x0c0582c6u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c0582c8;
P_0c0582c8: /* original 78ec, guest PC 0x0c0582c8 */
if(!s->budget--) { s->failed_pc=0x0c0582c8u; return 0; }
r[8]+=0xffffffecu;
goto P_0c0582ca;
P_0c0582ca: /* original 2c66, guest PC 0x0c0582ca */
if(!s->budget--) { s->failed_pc=0x0c0582cau; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c0582cc;
P_0c0582cc: /* original fc17, guest PC 0x0c0582cc */
if(!s->budget--) { s->failed_pc=0x0c0582ccu; return 0; }
vf3_matrix_store(s,ram,1,r[12]+r[0]);
goto P_0c0582ce;
P_0c0582ce: /* original e010, guest PC 0x0c0582ce */
if(!s->budget--) { s->failed_pc=0x0c0582ceu; return 0; }
r[0]=0x00000010u;
goto P_0c0582d0;
P_0c0582d0: /* original 000b, guest PC 0x0c0582d0 */
if(!s->budget--) { s->failed_pc=0x0c0582d0u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,0,r[12]+r[0]);
s->pc=target; return ram->oob==0;
P_0c0582d2: /* original fc07, guest PC 0x0c0582d2 */
if(!s->budget--) { s->failed_pc=0x0c0582d2u; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
return vf3_matrix_family(0x0c0582d4u,s,ram);
P_0c0582d8: /* original 0c83, guest PC 0x0c0582d8 */
if(!s->budget--) { s->failed_pc=0x0c0582d8u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c0582da;
P_0c0582da: /* original 7816, guest PC 0x0c0582da */
if(!s->budget--) { s->failed_pc=0x0c0582dau; return 0; }
r[8]+=0x00000016u;
goto P_0c0582dc;
P_0c0582dc: /* original 6385, guest PC 0x0c0582dc */
if(!s->budget--) { s->failed_pc=0x0c0582dcu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[3]=tmp;
goto P_0c0582de;
P_0c0582de: /* original 6185, guest PC 0x0c0582de */
if(!s->budget--) { s->failed_pc=0x0c0582deu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[1]=tmp;
goto P_0c0582e0;
P_0c0582e0: /* original 6285, guest PC 0x0c0582e0 */
if(!s->budget--) { s->failed_pc=0x0c0582e0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[2]=tmp;
goto P_0c0582e2;
P_0c0582e2: /* original 6229, guest PC 0x0c0582e2 */
if(!s->budget--) { s->failed_pc=0x0c0582e2u; return 0; }
r[2]=(r[2]<<16)|(r[2]>>16);
goto P_0c0582e4;
P_0c0582e4: /* original 7c2c, guest PC 0x0c0582e4 */
if(!s->budget--) { s->failed_pc=0x0c0582e4u; return 0; }
r[12]+=0x0000002cu;
goto P_0c0582e6;
P_0c0582e6: /* original 415a, guest PC 0x0c0582e6 */
if(!s->budget--) { s->failed_pc=0x0c0582e6u; return 0; }
r[53]=r[1];
goto P_0c0582e8;
P_0c0582e8: /* original 6085, guest PC 0x0c0582e8 */
if(!s->budget--) { s->failed_pc=0x0c0582e8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[0]=tmp;
goto P_0c0582ea;
P_0c0582ea: /* original f12d, guest PC 0x0c0582ea */
if(!s->budget--) { s->failed_pc=0x0c0582eau; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c0582ec;
P_0c0582ec: /* original 435a, guest PC 0x0c0582ec */
if(!s->budget--) { s->failed_pc=0x0c0582ecu; return 0; }
r[53]=r[3];
goto P_0c0582ee;
P_0c0582ee: /* original d10c, guest PC 0x0c0582ee */
if(!s->budget--) { s->failed_pc=0x0c0582eeu; return 0; }
r[1]=read(ram,0x0c058320u,4);
goto P_0c0582f0;
P_0c0582f0: /* original 6112, guest PC 0x0c0582f0 */
if(!s->budget--) { s->failed_pc=0x0c0582f0u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c0582f2;
P_0c0582f2: /* original 630d, guest PC 0x0c0582f2 */
if(!s->budget--) { s->failed_pc=0x0c0582f2u; return 0; }
r[3]=r[0]&65535u;
goto P_0c0582f4;
P_0c0582f4: /* original 4319, guest PC 0x0c0582f4 */
if(!s->budget--) { s->failed_pc=0x0c0582f4u; return 0; }
r[3]>>=8;
goto P_0c0582f6;
P_0c0582f6: /* original 231e, guest PC 0x0c0582f6 */
if(!s->budget--) { s->failed_pc=0x0c0582f6u; return 0; }
r[19]=(r[3]&65535u)*(r[1]&65535u);
goto P_0c0582f8;
P_0c0582f8: /* original 031a, guest PC 0x0c0582f8 */
if(!s->budget--) { s->failed_pc=0x0c0582f8u; return 0; }
r[3]=r[19];
goto P_0c0582fa;
P_0c0582fa: /* original 4319, guest PC 0x0c0582fa */
if(!s->budget--) { s->failed_pc=0x0c0582fau; return 0; }
r[3]>>=8;
goto P_0c0582fc;
P_0c0582fc: /* original 4318, guest PC 0x0c0582fc */
if(!s->budget--) { s->failed_pc=0x0c0582fcu; return 0; }
r[3]<<=8;
goto P_0c0582fe;
P_0c0582fe: /* original c9ff, guest PC 0x0c0582fe */
if(!s->budget--) { s->failed_pc=0x0c0582feu; return 0; }
r[0]&=255u;
goto P_0c058300;
P_0c058300: /* original 203b, guest PC 0x0c058300 */
if(!s->budget--) { s->failed_pc=0x0c058300u; return 0; }
r[0]|=r[3];
goto P_0c058302;
P_0c058302: /* original 220d, guest PC 0x0c058302 */
if(!s->budget--) { s->failed_pc=0x0c058302u; return 0; }
r[2]=(r[2]>>16)|(r[0]<<16);
goto P_0c058304;
P_0c058304: /* original f02d, guest PC 0x0c058304 */
if(!s->budget--) { s->failed_pc=0x0c058304u; return 0; }
fr[0]=vf3_fpu_float(r[53],r[18]);
goto P_0c058306;
P_0c058306: /* original fcea, guest PC 0x0c058306 */
if(!s->budget--) { s->failed_pc=0x0c058306u; return 0; }
vf3_matrix_store(s,ram,14,r[12]);
goto P_0c058308;
P_0c058308: /* original f132, guest PC 0x0c058308 */
if(!s->budget--) { s->failed_pc=0x0c058308u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c05830a;
P_0c05830a: /* original 1c23, guest PC 0x0c05830a */
if(!s->budget--) { s->failed_pc=0x0c05830au; return 0; }
write(ram,r[12]+12,r[2],4);
goto P_0c05830c;
P_0c05830c: /* original f032, guest PC 0x0c05830c */
if(!s->budget--) { s->failed_pc=0x0c05830cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c05830e;
P_0c05830e: /* original fcdb, guest PC 0x0c05830e */
if(!s->budget--) { s->failed_pc=0x0c05830eu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[12]);
goto P_0c058310;
P_0c058310: /* original 78e2, guest PC 0x0c058310 */
if(!s->budget--) { s->failed_pc=0x0c058310u; return 0; }
r[8]+=0xffffffe2u;
goto P_0c058312;
P_0c058312: /* original fccb, guest PC 0x0c058312 */
if(!s->budget--) { s->failed_pc=0x0c058312u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[12]);
goto P_0c058314;
P_0c058314: /* original e014, guest PC 0x0c058314 */
if(!s->budget--) { s->failed_pc=0x0c058314u; return 0; }
r[0]=0x00000014u;
goto P_0c058316;
P_0c058316: /* original 2c66, guest PC 0x0c058316 */
if(!s->budget--) { s->failed_pc=0x0c058316u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c058318;
P_0c058318: /* original fc17, guest PC 0x0c058318 */
if(!s->budget--) { s->failed_pc=0x0c058318u; return 0; }
vf3_matrix_store(s,ram,1,r[12]+r[0]);
goto P_0c05831a;
P_0c05831a: /* original e010, guest PC 0x0c05831a */
if(!s->budget--) { s->failed_pc=0x0c05831au; return 0; }
r[0]=0x00000010u;
goto P_0c05831c;
P_0c05831c: /* original 000b, guest PC 0x0c05831c */
if(!s->budget--) { s->failed_pc=0x0c05831cu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,0,r[12]+r[0]);
s->pc=target; return ram->oob==0;
P_0c05831e: /* original fc07, guest PC 0x0c05831e */
if(!s->budget--) { s->failed_pc=0x0c05831eu; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
return vf3_matrix_family(0x0c058320u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c0572e0u,0x0c0572e2u,0x0c0572e4u,0x0c0572e6u,0x0c0572e8u,0x0c0572eau,0x0c0572ecu,0x0c0572eeu,0x0c0572f0u,0x0c0572f2u,0x0c0572f4u,0x0c0572f6u,0x0c0572f8u,0x0c0572fau,0x0c0572fcu,0x0c0572feu,
0x0c057300u,0x0c057302u,0x0c057320u,0x0c057322u,0x0c057324u,0x0c057326u,0x0c057328u,0x0c05732au,0x0c05732cu,0x0c05732eu,0x0c057330u,0x0c057332u,0x0c057334u,0x0c057336u,0x0c057338u,0x0c05733au,
0x0c05733cu,0x0c05733eu,0x0c057340u,0x0c057342u,0x0c057344u,0x0c057346u,0x0c057360u,0x0c057362u,0x0c057364u,0x0c057366u,0x0c057368u,0x0c05736au,0x0c05736cu,0x0c05736eu,0x0c057370u,0x0c057372u,
0x0c057374u,0x0c057376u,0x0c057378u,0x0c05737au,0x0c05737cu,0x0c05737eu,0x0c057380u,0x0c057382u,0x0c057384u,0x0c057386u,0x0c0573a0u,0x0c0573a2u,0x0c0573a4u,0x0c0573a6u,0x0c0573a8u,0x0c0573aau,
0x0c0573acu,0x0c0573aeu,0x0c0573b0u,0x0c0573b2u,0x0c0573b4u,0x0c0573b6u,0x0c0573b8u,0x0c0573bau,0x0c0573bcu,0x0c0573beu,0x0c0573c0u,0x0c0573c2u,0x0c0573c4u,0x0c0573c6u,0x0c0573c8u,0x0c0573cau,
0x0c0573ccu,0x0c0573ceu,0x0c0573d0u,0x0c0573e0u,0x0c0573e2u,0x0c0573e4u,0x0c0573e6u,0x0c0573e8u,0x0c0573eau,0x0c0573ecu,0x0c0573eeu,0x0c0573f0u,0x0c0573f2u,0x0c0573f4u,0x0c0573f6u,0x0c0573f8u,
0x0c0573fau,0x0c0573fcu,0x0c0573feu,0x0c057400u,0x0c057402u,0x0c057404u,0x0c057406u,0x0c057408u,0x0c05740au,0x0c05740cu,0x0c05740eu,0x0c057410u,0x0c057412u,0x0c057414u,0x0c057420u,0x0c057422u,
0x0c057424u,0x0c057426u,0x0c057428u,0x0c05742au,0x0c05742cu,0x0c05742eu,0x0c057430u,0x0c057432u,0x0c057434u,0x0c057436u,0x0c057438u,0x0c05743au,0x0c05743cu,0x0c05743eu,0x0c057440u,0x0c057442u,
0x0c057444u,0x0c057446u,0x0c057448u,0x0c05744au,0x0c05744cu,0x0c05744eu,0x0c057450u,0x0c057452u,0x0c057454u,0x0c057680u,0x0c057682u,0x0c057684u,0x0c057686u,0x0c057688u,0x0c05768au,0x0c05768cu,
0x0c05768eu,0x0c057690u,0x0c057692u,0x0c057694u,0x0c057696u,0x0c057698u,0x0c05769au,0x0c05769cu,0x0c05769eu,0x0c0576a0u,0x0c0576a2u,0x0c0576a4u,0x0c0576a6u,0x0c0576a8u,0x0c0576aau,0x0c0576acu,
0x0c0576aeu,0x0c0576b0u,0x0c0576b2u,0x0c0576b4u,0x0c0576b6u,0x0c0576c0u,0x0c0576c2u,0x0c0576c4u,0x0c0576c6u,0x0c0576c8u,0x0c0576cau,0x0c0576ccu,0x0c0576ceu,0x0c0576d0u,0x0c0576d2u,0x0c0576d4u,
0x0c0576d6u,0x0c0576d8u,0x0c0576dau,0x0c0576dcu,0x0c0576deu,0x0c0576e0u,0x0c0576e2u,0x0c0576e4u,0x0c0576e6u,0x0c0576e8u,0x0c0576eau,0x0c0576ecu,0x0c0576eeu,0x0c0576f0u,0x0c0576f2u,0x0c0576f4u,
0x0c0576f6u,0x0c0576f8u,0x0c0576fau,0x0c057700u,0x0c057702u,0x0c057704u,0x0c057706u,0x0c057708u,0x0c05770au,0x0c05770cu,0x0c05770eu,0x0c057710u,0x0c057712u,0x0c057714u,0x0c057716u,0x0c057718u,
0x0c05771au,0x0c05771cu,0x0c05771eu,0x0c057720u,0x0c057722u,0x0c057724u,0x0c057726u,0x0c057728u,0x0c05772au,0x0c05772cu,0x0c05772eu,0x0c057730u,0x0c057732u,0x0c057734u,0x0c057736u,0x0c057738u,
0x0c05773au,0x0c057740u,0x0c057742u,0x0c057744u,0x0c057746u,0x0c057748u,0x0c05774au,0x0c05774cu,0x0c05774eu,0x0c057750u,0x0c057752u,0x0c057754u,0x0c057756u,0x0c057758u,0x0c05775au,0x0c05775cu,
0x0c05775eu,0x0c057760u,0x0c057762u,0x0c057764u,0x0c057766u,0x0c057768u,0x0c05776au,0x0c05776cu,0x0c05776eu,0x0c057770u,0x0c057772u,0x0c057774u,0x0c057776u,0x0c057778u,0x0c05777au,0x0c05777cu,
0x0c05777eu,0x0c057780u,0x0c057782u,0x0c057784u,0x0c0577a0u,0x0c0577a2u,0x0c0577a4u,0x0c0577a6u,0x0c0577a8u,0x0c0577aau,0x0c0577acu,0x0c0577aeu,0x0c0577b0u,0x0c0577b2u,0x0c0577b4u,0x0c0577b6u,
0x0c0577b8u,0x0c0577bau,0x0c0577bcu,0x0c0577beu,0x0c0577c0u,0x0c0577c2u,0x0c0577c4u,0x0c0577c6u,0x0c0577c8u,0x0c0577cau,0x0c0577ccu,0x0c0577ceu,0x0c0577d0u,0x0c0577d2u,0x0c0577d4u,0x0c0577d6u,
0x0c0577d8u,0x0c0577dau,0x0c0577dcu,0x0c0577deu,0x0c0577e0u,0x0c0577e2u,0x0c0577e4u,0x0c0577e6u,0x0c0577e8u,0x0c057800u,0x0c057802u,0x0c057804u,0x0c057806u,0x0c057808u,0x0c05780au,0x0c05780cu,
0x0c05780eu,0x0c057810u,0x0c057812u,0x0c057814u,0x0c057816u,0x0c057818u,0x0c05781au,0x0c05781cu,0x0c05781eu,0x0c057820u,0x0c057822u,0x0c057824u,0x0c057826u,0x0c057828u,0x0c05782au,0x0c05782cu,
0x0c05782eu,0x0c057830u,0x0c057832u,0x0c057834u,0x0c057836u,0x0c057838u,0x0c05783au,0x0c05783cu,0x0c05783eu,0x0c057840u,0x0c057842u,0x0c057844u,0x0c057846u,0x0c057848u,0x0c057a60u,0x0c057a62u,
0x0c057a64u,0x0c057a66u,0x0c057a68u,0x0c057a6au,0x0c057a6cu,0x0c057a6eu,0x0c057a70u,0x0c057a72u,0x0c057a74u,0x0c057a76u,0x0c057a78u,0x0c057a7au,0x0c057a7cu,0x0c057a7eu,0x0c057a80u,0x0c057aa0u,
0x0c057aa2u,0x0c057aa4u,0x0c057aa6u,0x0c057aa8u,0x0c057aaau,0x0c057aacu,0x0c057aaeu,0x0c057ab0u,0x0c057ab2u,0x0c057ab4u,0x0c057ab6u,0x0c057ab8u,0x0c057abau,0x0c057abcu,0x0c057abeu,0x0c057ac0u,
0x0c057ac2u,0x0c057ac4u,0x0c057ae0u,0x0c057ae2u,0x0c057ae4u,0x0c057ae6u,0x0c057ae8u,0x0c057aeau,0x0c057aecu,0x0c057aeeu,0x0c057af0u,0x0c057af2u,0x0c057af4u,0x0c057af6u,0x0c057af8u,0x0c057afau,
0x0c057afcu,0x0c057afeu,0x0c057b00u,0x0c057b02u,0x0c057b04u,0x0c057b20u,0x0c057b22u,0x0c057b24u,0x0c057b26u,0x0c057b28u,0x0c057b2au,0x0c057b2cu,0x0c057b2eu,0x0c057b30u,0x0c057b32u,0x0c057b34u,
0x0c057b36u,0x0c057b38u,0x0c057b3au,0x0c057b3cu,0x0c057b3eu,0x0c057b40u,0x0c057b42u,0x0c057b44u,0x0c057b46u,0x0c057b48u,0x0c057b4au,0x0c057b4cu,0x0c057b4eu,0x0c057b60u,0x0c057b62u,0x0c057b64u,
0x0c057b66u,0x0c057b68u,0x0c057b6au,0x0c057b6cu,0x0c057b6eu,0x0c057b70u,0x0c057b72u,0x0c057b74u,0x0c057b76u,0x0c057b78u,0x0c057b7au,0x0c057b7cu,0x0c057b7eu,0x0c057b80u,0x0c057b82u,0x0c057b84u,
0x0c057b86u,0x0c057b88u,0x0c057b8au,0x0c057b8cu,0x0c057b8eu,0x0c057b90u,0x0c057b92u,0x0c057ba0u,0x0c057ba2u,0x0c057ba4u,0x0c057ba6u,0x0c057ba8u,0x0c057baau,0x0c057bacu,0x0c057baeu,0x0c057bb0u,
0x0c057bb2u,0x0c057bb4u,0x0c057bb6u,0x0c057bb8u,0x0c057bbau,0x0c057bbcu,0x0c057bbeu,0x0c057bc0u,0x0c057bc2u,0x0c057bc4u,0x0c057bc6u,0x0c057bc8u,0x0c057bcau,0x0c057bccu,0x0c057bceu,0x0c057bd0u,
0x0c057bd2u,0x0c057e60u,0x0c057e62u,0x0c057e64u,0x0c057e66u,0x0c057e68u,0x0c057e6au,0x0c057e6cu,0x0c057e6eu,0x0c057e70u,0x0c057e72u,0x0c057e74u,0x0c057e76u,0x0c057e78u,0x0c057e7au,0x0c057e7cu,
0x0c057e7eu,0x0c057e80u,0x0c057e82u,0x0c057e84u,0x0c057e86u,0x0c057e88u,0x0c057e8au,0x0c057e8cu,0x0c057e8eu,0x0c057e90u,0x0c057e92u,0x0c057e94u,0x0c057e96u,0x0c057e98u,0x0c057e9au,0x0c057e9cu,
0x0c057e9eu,0x0c057ea0u,0x0c057ea2u,0x0c057ea4u,0x0c057ea6u,0x0c057ea8u,0x0c057eaau,0x0c057eacu,0x0c057eaeu,0x0c057eb0u,0x0c057eb2u,0x0c057eb4u,0x0c057eb6u,0x0c057eb8u,0x0c057ebau,0x0c057ebcu,
0x0c057ebeu,0x0c057ec0u,0x0c057ec2u,0x0c057ec4u,0x0c057ec6u,0x0c057ee0u,0x0c057ee2u,0x0c057ee4u,0x0c057ee6u,0x0c057ee8u,0x0c057eeau,0x0c057eecu,0x0c057eeeu,0x0c057ef0u,0x0c057ef2u,0x0c057ef4u,
0x0c057ef6u,0x0c057ef8u,0x0c057efau,0x0c057efcu,0x0c057efeu,0x0c057f00u,0x0c057f02u,0x0c057f04u,0x0c057f06u,0x0c057f08u,0x0c057f0au,0x0c057f0cu,0x0c057f0eu,0x0c057f10u,0x0c057f18u,0x0c057f1au,
0x0c057f1cu,0x0c057f1eu,0x0c057f20u,0x0c057f22u,0x0c057f24u,0x0c057f26u,0x0c057f28u,0x0c057f2au,0x0c057f2cu,0x0c057f2eu,0x0c057f30u,0x0c057f32u,0x0c057f34u,0x0c057f36u,0x0c057f38u,0x0c057f3au,
0x0c057f3cu,0x0c057f3eu,0x0c057f40u,0x0c057f42u,0x0c057f44u,0x0c057f46u,0x0c057f48u,0x0c057f4au,0x0c057f50u,0x0c057f52u,0x0c057f54u,0x0c057f56u,0x0c057f58u,0x0c057f5au,0x0c057f5cu,0x0c057f5eu,
0x0c057f60u,0x0c057f62u,0x0c057f64u,0x0c057f66u,0x0c057f68u,0x0c057f6au,0x0c057f6cu,0x0c057f6eu,0x0c057f70u,0x0c057f72u,0x0c057f74u,0x0c057f76u,0x0c057f78u,0x0c057f7au,0x0c057f7cu,0x0c057f7eu,
0x0c057f80u,0x0c057f82u,0x0c0581a0u,0x0c0581a2u,0x0c0581a4u,0x0c0581a6u,0x0c0581a8u,0x0c0581aau,0x0c0581acu,0x0c0581aeu,0x0c0581b0u,0x0c0581b2u,0x0c0581b4u,0x0c0581b6u,0x0c0581b8u,0x0c0581bau,
0x0c0581bcu,0x0c0581beu,0x0c0581c0u,0x0c0581c2u,0x0c0581c4u,0x0c0581c6u,0x0c0581c8u,0x0c0581cau,0x0c0581ccu,0x0c0581ceu,0x0c0581d0u,0x0c0581d2u,0x0c0581d4u,0x0c0581d6u,0x0c0581d8u,0x0c0581dau,
0x0c0581dcu,0x0c0581deu,0x0c0581e0u,0x0c0581e2u,0x0c0581e4u,0x0c0581e6u,0x0c0581e8u,0x0c0581eau,0x0c0581ecu,0x0c0581eeu,0x0c0581f0u,0x0c0581f2u,0x0c0581f4u,0x0c0581f6u,0x0c0581f8u,0x0c0581fau,
0x0c0581fcu,0x0c0581feu,0x0c058200u,0x0c058202u,0x0c058204u,0x0c058206u,0x0c058208u,0x0c05820au,0x0c05820cu,0x0c05820eu,0x0c058210u,0x0c058212u,0x0c058214u,0x0c058216u,0x0c058218u,0x0c05821au,
0x0c05821cu,0x0c05821eu,0x0c058220u,0x0c058222u,0x0c058224u,0x0c058226u,0x0c058228u,0x0c05822au,0x0c05822cu,0x0c05822eu,0x0c058230u,0x0c058232u,0x0c058234u,0x0c058236u,0x0c058238u,0x0c058240u,
0x0c058242u,0x0c058244u,0x0c058246u,0x0c058248u,0x0c05824au,0x0c05824cu,0x0c05824eu,0x0c058250u,0x0c058252u,0x0c058254u,0x0c058256u,0x0c058258u,0x0c05825au,0x0c05825cu,0x0c05825eu,0x0c058260u,
0x0c058262u,0x0c058264u,0x0c058266u,0x0c058268u,0x0c05826au,0x0c05826cu,0x0c05826eu,0x0c058270u,0x0c058272u,0x0c058274u,0x0c058276u,0x0c058278u,0x0c05827au,0x0c05827cu,0x0c05827eu,0x0c058280u,
0x0c058282u,0x0c058284u,0x0c05828cu,0x0c05828eu,0x0c058290u,0x0c058292u,0x0c058294u,0x0c058296u,0x0c058298u,0x0c05829au,0x0c05829cu,0x0c05829eu,0x0c0582a0u,0x0c0582a2u,0x0c0582a4u,0x0c0582a6u,
0x0c0582a8u,0x0c0582aau,0x0c0582acu,0x0c0582aeu,0x0c0582b0u,0x0c0582b2u,0x0c0582b4u,0x0c0582b6u,0x0c0582b8u,0x0c0582bau,0x0c0582bcu,0x0c0582beu,0x0c0582c0u,0x0c0582c2u,0x0c0582c4u,0x0c0582c6u,
0x0c0582c8u,0x0c0582cau,0x0c0582ccu,0x0c0582ceu,0x0c0582d0u,0x0c0582d2u,0x0c0582d8u,0x0c0582dau,0x0c0582dcu,0x0c0582deu,0x0c0582e0u,0x0c0582e2u,0x0c0582e4u,0x0c0582e6u,0x0c0582e8u,0x0c0582eau,
0x0c0582ecu,0x0c0582eeu,0x0c0582f0u,0x0c0582f2u,0x0c0582f4u,0x0c0582f6u,0x0c0582f8u,0x0c0582fau,0x0c0582fcu,0x0c0582feu,0x0c058300u,0x0c058302u,0x0c058304u,0x0c058306u,0x0c058308u,0x0c05830au,
0x0c05830cu,0x0c05830eu,0x0c058310u,0x0c058312u,0x0c058314u,0x0c058316u,0x0c058318u,0x0c05831au,0x0c05831cu,0x0c05831eu,
};
int vf3_clip_strip_writers_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
