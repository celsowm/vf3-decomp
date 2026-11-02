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
int vf3_away_batch70_adapter_27(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0971c8u: goto P_0c0971c8;
case 0x0c0971cau: goto P_0c0971ca;
case 0x0c0971ccu: goto P_0c0971cc;
case 0x0c0971ceu: goto P_0c0971ce;
case 0x0c0971d0u: goto P_0c0971d0;
case 0x0c0971d2u: goto P_0c0971d2;
case 0x0c0971d4u: goto P_0c0971d4;
case 0x0c0971d6u: goto P_0c0971d6;
case 0x0c0971d8u: goto P_0c0971d8;
case 0x0c0971dau: goto P_0c0971da;
case 0x0c0971dcu: goto P_0c0971dc;
case 0x0c0971deu: goto P_0c0971de;
case 0x0c0971e0u: goto P_0c0971e0;
case 0x0c0971e2u: goto P_0c0971e2;
case 0x0c0971e4u: goto P_0c0971e4;
case 0x0c0971e6u: goto P_0c0971e6;
case 0x0c0971e8u: goto P_0c0971e8;
case 0x0c0971eau: goto P_0c0971ea;
case 0x0c0971ecu: goto P_0c0971ec;
case 0x0c0971eeu: goto P_0c0971ee;
case 0x0c0971f0u: goto P_0c0971f0;
case 0x0c0971f2u: goto P_0c0971f2;
case 0x0c0971f4u: goto P_0c0971f4;
case 0x0c0971f6u: goto P_0c0971f6;
case 0x0c0971f8u: goto P_0c0971f8;
case 0x0c0971fau: goto P_0c0971fa;
case 0x0c09723cu: goto P_0c09723c;
case 0x0c09723eu: goto P_0c09723e;
case 0x0c097240u: goto P_0c097240;
case 0x0c097242u: goto P_0c097242;
case 0x0c097244u: goto P_0c097244;
case 0x0c097246u: goto P_0c097246;
case 0x0c097248u: goto P_0c097248;
case 0x0c09724au: goto P_0c09724a;
case 0x0c09724cu: goto P_0c09724c;
case 0x0c09724eu: goto P_0c09724e;
case 0x0c097250u: goto P_0c097250;
case 0x0c097252u: goto P_0c097252;
case 0x0c097254u: goto P_0c097254;
case 0x0c097256u: goto P_0c097256;
case 0x0c097258u: goto P_0c097258;
case 0x0c09725au: goto P_0c09725a;
case 0x0c09725cu: goto P_0c09725c;
case 0x0c09725eu: goto P_0c09725e;
case 0x0c097260u: goto P_0c097260;
case 0x0c097262u: goto P_0c097262;
case 0x0c097264u: goto P_0c097264;
case 0x0c097266u: goto P_0c097266;
case 0x0c097268u: goto P_0c097268;
case 0x0c09726au: goto P_0c09726a;
case 0x0c09726cu: goto P_0c09726c;
case 0x0c09726eu: goto P_0c09726e;
case 0x0c097270u: goto P_0c097270;
case 0x0c097272u: goto P_0c097272;
case 0x0c097274u: goto P_0c097274;
case 0x0c097276u: goto P_0c097276;
case 0x0c097278u: goto P_0c097278;
case 0x0c09727au: goto P_0c09727a;
case 0x0c09727cu: goto P_0c09727c;
case 0x0c09727eu: goto P_0c09727e;
case 0x0c097280u: goto P_0c097280;
case 0x0c097282u: goto P_0c097282;
case 0x0c097284u: goto P_0c097284;
case 0x0c097286u: goto P_0c097286;
case 0x0c0972c4u: goto P_0c0972c4;
case 0x0c0972c6u: goto P_0c0972c6;
case 0x0c0972c8u: goto P_0c0972c8;
case 0x0c0972cau: goto P_0c0972ca;
case 0x0c0972ccu: goto P_0c0972cc;
case 0x0c0972ceu: goto P_0c0972ce;
case 0x0c0972d0u: goto P_0c0972d0;
case 0x0c0972d2u: goto P_0c0972d2;
case 0x0c0972d4u: goto P_0c0972d4;
case 0x0c0972d6u: goto P_0c0972d6;
case 0x0c0972d8u: goto P_0c0972d8;
case 0x0c0972dau: goto P_0c0972da;
case 0x0c0972dcu: goto P_0c0972dc;
case 0x0c0972deu: goto P_0c0972de;
case 0x0c0972e0u: goto P_0c0972e0;
case 0x0c0972e2u: goto P_0c0972e2;
case 0x0c0972e4u: goto P_0c0972e4;
case 0x0c0972e6u: goto P_0c0972e6;
case 0x0c0972e8u: goto P_0c0972e8;
case 0x0c0972eau: goto P_0c0972ea;
case 0x0c0972ecu: goto P_0c0972ec;
case 0x0c0972eeu: goto P_0c0972ee;
case 0x0c0972f0u: goto P_0c0972f0;
case 0x0c0972f2u: goto P_0c0972f2;
case 0x0c0972f4u: goto P_0c0972f4;
case 0x0c0972f6u: goto P_0c0972f6;
case 0x0c0972f8u: goto P_0c0972f8;
case 0x0c0972fau: goto P_0c0972fa;
case 0x0c0972fcu: goto P_0c0972fc;
case 0x0c0972feu: goto P_0c0972fe;
case 0x0c097300u: goto P_0c097300;
case 0x0c097302u: goto P_0c097302;
case 0x0c097304u: goto P_0c097304;
case 0x0c097306u: goto P_0c097306;
case 0x0c097308u: goto P_0c097308;
case 0x0c09730au: goto P_0c09730a;
case 0x0c09730cu: goto P_0c09730c;
case 0x0c09730eu: goto P_0c09730e;
case 0x0c097310u: goto P_0c097310;
case 0x0c097312u: goto P_0c097312;
case 0x0c097314u: goto P_0c097314;
case 0x0c097316u: goto P_0c097316;
case 0x0c097318u: goto P_0c097318;
case 0x0c09731au: goto P_0c09731a;
case 0x0c09731cu: goto P_0c09731c;
case 0x0c09731eu: goto P_0c09731e;
case 0x0c097320u: goto P_0c097320;
case 0x0c097322u: goto P_0c097322;
case 0x0c097324u: goto P_0c097324;
case 0x0c097326u: goto P_0c097326;
case 0x0c097328u: goto P_0c097328;
case 0x0c09732au: goto P_0c09732a;
case 0x0c09732cu: goto P_0c09732c;
case 0x0c09732eu: goto P_0c09732e;
case 0x0c097330u: goto P_0c097330;
case 0x0c097332u: goto P_0c097332;
case 0x0c097334u: goto P_0c097334;
case 0x0c097336u: goto P_0c097336;
case 0x0c097338u: goto P_0c097338;
case 0x0c09733au: goto P_0c09733a;
case 0x0c09733cu: goto P_0c09733c;
case 0x0c09733eu: goto P_0c09733e;
case 0x0c097340u: goto P_0c097340;
case 0x0c097342u: goto P_0c097342;
case 0x0c097344u: goto P_0c097344;
case 0x0c097346u: goto P_0c097346;
case 0x0c097348u: goto P_0c097348;
case 0x0c09734au: goto P_0c09734a;
case 0x0c09734cu: goto P_0c09734c;
case 0x0c09734eu: goto P_0c09734e;
case 0x0c097350u: goto P_0c097350;
case 0x0c097352u: goto P_0c097352;
case 0x0c097354u: goto P_0c097354;
case 0x0c097356u: goto P_0c097356;
case 0x0c097358u: goto P_0c097358;
case 0x0c09735au: goto P_0c09735a;
case 0x0c09735cu: goto P_0c09735c;
case 0x0c09735eu: goto P_0c09735e;
case 0x0c097360u: goto P_0c097360;
case 0x0c097362u: goto P_0c097362;
case 0x0c097364u: goto P_0c097364;
case 0x0c097366u: goto P_0c097366;
case 0x0c097368u: goto P_0c097368;
case 0x0c09736au: goto P_0c09736a;
case 0x0c09736cu: goto P_0c09736c;
case 0x0c09736eu: goto P_0c09736e;
case 0x0c097370u: goto P_0c097370;
case 0x0c097372u: goto P_0c097372;
case 0x0c097374u: goto P_0c097374;
case 0x0c097376u: goto P_0c097376;
case 0x0c097378u: goto P_0c097378;
case 0x0c09737au: goto P_0c09737a;
case 0x0c09737cu: goto P_0c09737c;
case 0x0c09737eu: goto P_0c09737e;
case 0x0c097380u: goto P_0c097380;
case 0x0c097382u: goto P_0c097382;
case 0x0c097384u: goto P_0c097384;
case 0x0c097386u: goto P_0c097386;
case 0x0c097388u: goto P_0c097388;
case 0x0c09738au: goto P_0c09738a;
case 0x0c09738cu: goto P_0c09738c;
case 0x0c09738eu: goto P_0c09738e;
case 0x0c097390u: goto P_0c097390;
case 0x0c097392u: goto P_0c097392;
case 0x0c097394u: goto P_0c097394;
case 0x0c097396u: goto P_0c097396;
case 0x0c097398u: goto P_0c097398;
case 0x0c09739au: goto P_0c09739a;
case 0x0c09739cu: goto P_0c09739c;
case 0x0c09739eu: goto P_0c09739e;
case 0x0c0973a0u: goto P_0c0973a0;
case 0x0c0973a2u: goto P_0c0973a2;
case 0x0c0973a4u: goto P_0c0973a4;
case 0x0c0973a6u: goto P_0c0973a6;
case 0x0c0973a8u: goto P_0c0973a8;
case 0x0c0973aau: goto P_0c0973aa;
case 0x0c0973acu: goto P_0c0973ac;
case 0x0c0973aeu: goto P_0c0973ae;
case 0x0c0973b0u: goto P_0c0973b0;
case 0x0c0973b2u: goto P_0c0973b2;
case 0x0c0973b4u: goto P_0c0973b4;
case 0x0c0973b6u: goto P_0c0973b6;
case 0x0c0973b8u: goto P_0c0973b8;
case 0x0c0973bau: goto P_0c0973ba;
case 0x0c0973bcu: goto P_0c0973bc;
case 0x0c0973beu: goto P_0c0973be;
case 0x0c0973c0u: goto P_0c0973c0;
case 0x0c0973c2u: goto P_0c0973c2;
case 0x0c0973c4u: goto P_0c0973c4;
case 0x0c0973c6u: goto P_0c0973c6;
case 0x0c0973c8u: goto P_0c0973c8;
case 0x0c0973cau: goto P_0c0973ca;
case 0x0c0973ccu: goto P_0c0973cc;
case 0x0c0973ceu: goto P_0c0973ce;
case 0x0c0973d0u: goto P_0c0973d0;
case 0x0c0973d2u: goto P_0c0973d2;
case 0x0c0973d4u: goto P_0c0973d4;
case 0x0c0973d6u: goto P_0c0973d6;
case 0x0c0973d8u: goto P_0c0973d8;
case 0x0c0973dau: goto P_0c0973da;
case 0x0c0973dcu: goto P_0c0973dc;
case 0x0c0973deu: goto P_0c0973de;
case 0x0c0973e0u: goto P_0c0973e0;
case 0x0c0973e2u: goto P_0c0973e2;
case 0x0c0973e4u: goto P_0c0973e4;
case 0x0c0973e6u: goto P_0c0973e6;
case 0x0c0973e8u: goto P_0c0973e8;
case 0x0c0973eau: goto P_0c0973ea;
case 0x0c0973ecu: goto P_0c0973ec;
case 0x0c0973eeu: goto P_0c0973ee;
case 0x0c0973f0u: goto P_0c0973f0;
case 0x0c0973f2u: goto P_0c0973f2;
case 0x0c0973f4u: goto P_0c0973f4;
case 0x0c0973f6u: goto P_0c0973f6;
case 0x0c0973f8u: goto P_0c0973f8;
case 0x0c0973fau: goto P_0c0973fa;
case 0x0c0973fcu: goto P_0c0973fc;
case 0x0c0973feu: goto P_0c0973fe;
case 0x0c097400u: goto P_0c097400;
case 0x0c097402u: goto P_0c097402;
case 0x0c097404u: goto P_0c097404;
case 0x0c097406u: goto P_0c097406;
case 0x0c097408u: goto P_0c097408;
case 0x0c09740au: goto P_0c09740a;
case 0x0c09740cu: goto P_0c09740c;
case 0x0c09740eu: goto P_0c09740e;
case 0x0c097410u: goto P_0c097410;
case 0x0c097412u: goto P_0c097412;
case 0x0c097414u: goto P_0c097414;
case 0x0c097478u: goto P_0c097478;
case 0x0c09747au: goto P_0c09747a;
case 0x0c09747cu: goto P_0c09747c;
case 0x0c09747eu: goto P_0c09747e;
case 0x0c097480u: goto P_0c097480;
case 0x0c097482u: goto P_0c097482;
case 0x0c097484u: goto P_0c097484;
case 0x0c097486u: goto P_0c097486;
case 0x0c097488u: goto P_0c097488;
case 0x0c09748au: goto P_0c09748a;
case 0x0c09748cu: goto P_0c09748c;
case 0x0c09748eu: goto P_0c09748e;
case 0x0c097490u: goto P_0c097490;
case 0x0c097492u: goto P_0c097492;
case 0x0c097494u: goto P_0c097494;
case 0x0c097496u: goto P_0c097496;
case 0x0c097498u: goto P_0c097498;
case 0x0c09749au: goto P_0c09749a;
case 0x0c09749cu: goto P_0c09749c;
case 0x0c09749eu: goto P_0c09749e;
case 0x0c0974a0u: goto P_0c0974a0;
case 0x0c0974a2u: goto P_0c0974a2;
case 0x0c0974a4u: goto P_0c0974a4;
case 0x0c0974a6u: goto P_0c0974a6;
case 0x0c0974a8u: goto P_0c0974a8;
case 0x0c0974aau: goto P_0c0974aa;
case 0x0c0974acu: goto P_0c0974ac;
case 0x0c0974aeu: goto P_0c0974ae;
case 0x0c0974b0u: goto P_0c0974b0;
case 0x0c0974b2u: goto P_0c0974b2;
case 0x0c0974b4u: goto P_0c0974b4;
case 0x0c0974b6u: goto P_0c0974b6;
case 0x0c0974b8u: goto P_0c0974b8;
case 0x0c0974bau: goto P_0c0974ba;
case 0x0c0974bcu: goto P_0c0974bc;
case 0x0c0974beu: goto P_0c0974be;
case 0x0c0974c0u: goto P_0c0974c0;
case 0x0c0974c2u: goto P_0c0974c2;
case 0x0c0974c4u: goto P_0c0974c4;
case 0x0c0974c6u: goto P_0c0974c6;
case 0x0c0974c8u: goto P_0c0974c8;
case 0x0c0974cau: goto P_0c0974ca;
case 0x0c0974ccu: goto P_0c0974cc;
case 0x0c0974ceu: goto P_0c0974ce;
case 0x0c0974d0u: goto P_0c0974d0;
case 0x0c0974d2u: goto P_0c0974d2;
case 0x0c0974d4u: goto P_0c0974d4;
case 0x0c0974d6u: goto P_0c0974d6;
case 0x0c0974d8u: goto P_0c0974d8;
case 0x0c0974dau: goto P_0c0974da;
case 0x0c0974dcu: goto P_0c0974dc;
case 0x0c0974deu: goto P_0c0974de;
case 0x0c0974e0u: goto P_0c0974e0;
case 0x0c0974e2u: goto P_0c0974e2;
case 0x0c0974e4u: goto P_0c0974e4;
case 0x0c0974e6u: goto P_0c0974e6;
case 0x0c0974e8u: goto P_0c0974e8;
case 0x0c0974eau: goto P_0c0974ea;
case 0x0c0974ecu: goto P_0c0974ec;
case 0x0c0974eeu: goto P_0c0974ee;
case 0x0c0974f0u: goto P_0c0974f0;
case 0x0c0974f2u: goto P_0c0974f2;
case 0x0c0974f4u: goto P_0c0974f4;
case 0x0c0974f6u: goto P_0c0974f6;
case 0x0c0974f8u: goto P_0c0974f8;
case 0x0c0974fau: goto P_0c0974fa;
case 0x0c0974fcu: goto P_0c0974fc;
case 0x0c0974feu: goto P_0c0974fe;
case 0x0c097500u: goto P_0c097500;
case 0x0c097502u: goto P_0c097502;
case 0x0c097504u: goto P_0c097504;
case 0x0c097506u: goto P_0c097506;
case 0x0c097508u: goto P_0c097508;
case 0x0c09750au: goto P_0c09750a;
case 0x0c09750cu: goto P_0c09750c;
case 0x0c09750eu: goto P_0c09750e;
case 0x0c097510u: goto P_0c097510;
case 0x0c097512u: goto P_0c097512;
case 0x0c097514u: goto P_0c097514;
case 0x0c097516u: goto P_0c097516;
case 0x0c097518u: goto P_0c097518;
case 0x0c09751au: goto P_0c09751a;
case 0x0c09751cu: goto P_0c09751c;
case 0x0c09751eu: goto P_0c09751e;
case 0x0c097520u: goto P_0c097520;
case 0x0c097522u: goto P_0c097522;
case 0x0c097524u: goto P_0c097524;
case 0x0c097526u: goto P_0c097526;
case 0x0c097528u: goto P_0c097528;
case 0x0c09752au: goto P_0c09752a;
case 0x0c09752cu: goto P_0c09752c;
case 0x0c09752eu: goto P_0c09752e;
case 0x0c097530u: goto P_0c097530;
case 0x0c097532u: goto P_0c097532;
case 0x0c097534u: goto P_0c097534;
case 0x0c097536u: goto P_0c097536;
case 0x0c097538u: goto P_0c097538;
case 0x0c09753au: goto P_0c09753a;
case 0x0c09753cu: goto P_0c09753c;
case 0x0c09753eu: goto P_0c09753e;
case 0x0c097540u: goto P_0c097540;
case 0x0c097542u: goto P_0c097542;
case 0x0c097544u: goto P_0c097544;
case 0x0c097546u: goto P_0c097546;
case 0x0c097548u: goto P_0c097548;
case 0x0c09754au: goto P_0c09754a;
case 0x0c09754cu: goto P_0c09754c;
case 0x0c09754eu: goto P_0c09754e;
case 0x0c097550u: goto P_0c097550;
case 0x0c097552u: goto P_0c097552;
case 0x0c097554u: goto P_0c097554;
case 0x0c097556u: goto P_0c097556;
case 0x0c097558u: goto P_0c097558;
case 0x0c09755au: goto P_0c09755a;
case 0x0c09755cu: goto P_0c09755c;
case 0x0c09755eu: goto P_0c09755e;
case 0x0c097560u: goto P_0c097560;
case 0x0c097562u: goto P_0c097562;
case 0x0c097564u: goto P_0c097564;
case 0x0c097566u: goto P_0c097566;
case 0x0c097568u: goto P_0c097568;
case 0x0c09756au: goto P_0c09756a;
case 0x0c09756cu: goto P_0c09756c;
case 0x0c09756eu: goto P_0c09756e;
case 0x0c097570u: goto P_0c097570;
case 0x0c097572u: goto P_0c097572;
case 0x0c097574u: goto P_0c097574;
case 0x0c097576u: goto P_0c097576;
case 0x0c097578u: goto P_0c097578;
case 0x0c09757au: goto P_0c09757a;
case 0x0c09757cu: goto P_0c09757c;
case 0x0c09757eu: goto P_0c09757e;
case 0x0c097580u: goto P_0c097580;
case 0x0c097582u: goto P_0c097582;
case 0x0c097584u: goto P_0c097584;
case 0x0c097586u: goto P_0c097586;
case 0x0c097588u: goto P_0c097588;
case 0x0c09758au: goto P_0c09758a;
case 0x0c09758cu: goto P_0c09758c;
case 0x0c09758eu: goto P_0c09758e;
case 0x0c097590u: goto P_0c097590;
case 0x0c097592u: goto P_0c097592;
case 0x0c097594u: goto P_0c097594;
case 0x0c097596u: goto P_0c097596;
case 0x0c097598u: goto P_0c097598;
case 0x0c09759au: goto P_0c09759a;
case 0x0c0975d4u: goto P_0c0975d4;
case 0x0c0975d6u: goto P_0c0975d6;
case 0x0c0975d8u: goto P_0c0975d8;
case 0x0c0975dau: goto P_0c0975da;
case 0x0c0975dcu: goto P_0c0975dc;
case 0x0c0975deu: goto P_0c0975de;
case 0x0c0975e0u: goto P_0c0975e0;
case 0x0c0975e2u: goto P_0c0975e2;
case 0x0c0975e4u: goto P_0c0975e4;
case 0x0c0975e6u: goto P_0c0975e6;
case 0x0c0975e8u: goto P_0c0975e8;
case 0x0c0975eau: goto P_0c0975ea;
case 0x0c0975ecu: goto P_0c0975ec;
case 0x0c0975eeu: goto P_0c0975ee;
case 0x0c0975f0u: goto P_0c0975f0;
case 0x0c0975f2u: goto P_0c0975f2;
case 0x0c0975f4u: goto P_0c0975f4;
case 0x0c0975f6u: goto P_0c0975f6;
case 0x0c0975f8u: goto P_0c0975f8;
case 0x0c0975fau: goto P_0c0975fa;
case 0x0c0975fcu: goto P_0c0975fc;
case 0x0c0975feu: goto P_0c0975fe;
case 0x0c097600u: goto P_0c097600;
case 0x0c097602u: goto P_0c097602;
case 0x0c097604u: goto P_0c097604;
case 0x0c097606u: goto P_0c097606;
case 0x0c097608u: goto P_0c097608;
case 0x0c09760au: goto P_0c09760a;
case 0x0c09760cu: goto P_0c09760c;
case 0x0c09760eu: goto P_0c09760e;
case 0x0c097610u: goto P_0c097610;
case 0x0c097612u: goto P_0c097612;
case 0x0c097614u: goto P_0c097614;
case 0x0c097616u: goto P_0c097616;
case 0x0c097618u: goto P_0c097618;
case 0x0c09761au: goto P_0c09761a;
case 0x0c09761cu: goto P_0c09761c;
case 0x0c09761eu: goto P_0c09761e;
case 0x0c097620u: goto P_0c097620;
case 0x0c097622u: goto P_0c097622;
case 0x0c097624u: goto P_0c097624;
case 0x0c097626u: goto P_0c097626;
case 0x0c097628u: goto P_0c097628;
case 0x0c09762au: goto P_0c09762a;
case 0x0c097694u: goto P_0c097694;
case 0x0c097696u: goto P_0c097696;
case 0x0c097698u: goto P_0c097698;
case 0x0c09769au: goto P_0c09769a;
case 0x0c09769cu: goto P_0c09769c;
case 0x0c09769eu: goto P_0c09769e;
case 0x0c0976a0u: goto P_0c0976a0;
case 0x0c0976a2u: goto P_0c0976a2;
case 0x0c0976a4u: goto P_0c0976a4;
case 0x0c0976a6u: goto P_0c0976a6;
case 0x0c0976a8u: goto P_0c0976a8;
case 0x0c0976aau: goto P_0c0976aa;
case 0x0c0976acu: goto P_0c0976ac;
case 0x0c0976aeu: goto P_0c0976ae;
case 0x0c0976b0u: goto P_0c0976b0;
case 0x0c0976b2u: goto P_0c0976b2;
case 0x0c0976b4u: goto P_0c0976b4;
case 0x0c0976b6u: goto P_0c0976b6;
case 0x0c0976b8u: goto P_0c0976b8;
case 0x0c0976bau: goto P_0c0976ba;
case 0x0c0976bcu: goto P_0c0976bc;
case 0x0c0976beu: goto P_0c0976be;
case 0x0c0976c0u: goto P_0c0976c0;
case 0x0c0976c2u: goto P_0c0976c2;
case 0x0c0976c4u: goto P_0c0976c4;
case 0x0c0976c6u: goto P_0c0976c6;
case 0x0c0976c8u: goto P_0c0976c8;
case 0x0c0976cau: goto P_0c0976ca;
case 0x0c0976ccu: goto P_0c0976cc;
case 0x0c0976ceu: goto P_0c0976ce;
case 0x0c0976d0u: goto P_0c0976d0;
case 0x0c0976d2u: goto P_0c0976d2;
case 0x0c0976d4u: goto P_0c0976d4;
case 0x0c0976d6u: goto P_0c0976d6;
case 0x0c0976d8u: goto P_0c0976d8;
case 0x0c0976dau: goto P_0c0976da;
case 0x0c0976dcu: goto P_0c0976dc;
case 0x0c0976deu: goto P_0c0976de;
case 0x0c0976e0u: goto P_0c0976e0;
case 0x0c0976e2u: goto P_0c0976e2;
case 0x0c0976e4u: goto P_0c0976e4;
case 0x0c0976e6u: goto P_0c0976e6;
case 0x0c0976e8u: goto P_0c0976e8;
case 0x0c0976eau: goto P_0c0976ea;
case 0x0c0976ecu: goto P_0c0976ec;
case 0x0c0976eeu: goto P_0c0976ee;
case 0x0c0976f0u: goto P_0c0976f0;
case 0x0c0976f2u: goto P_0c0976f2;
case 0x0c0976f4u: goto P_0c0976f4;
case 0x0c0976f6u: goto P_0c0976f6;
case 0x0c0976f8u: goto P_0c0976f8;
case 0x0c0976fau: goto P_0c0976fa;
case 0x0c0976fcu: goto P_0c0976fc;
case 0x0c0976feu: goto P_0c0976fe;
case 0x0c097700u: goto P_0c097700;
case 0x0c097702u: goto P_0c097702;
case 0x0c097704u: goto P_0c097704;
case 0x0c097706u: goto P_0c097706;
case 0x0c097708u: goto P_0c097708;
case 0x0c09770au: goto P_0c09770a;
case 0x0c09770cu: goto P_0c09770c;
case 0x0c09770eu: goto P_0c09770e;
case 0x0c097710u: goto P_0c097710;
case 0x0c097712u: goto P_0c097712;
case 0x0c097714u: goto P_0c097714;
case 0x0c097716u: goto P_0c097716;
case 0x0c097718u: goto P_0c097718;
case 0x0c09771au: goto P_0c09771a;
case 0x0c09771cu: goto P_0c09771c;
case 0x0c09771eu: goto P_0c09771e;
case 0x0c097720u: goto P_0c097720;
case 0x0c097722u: goto P_0c097722;
case 0x0c097724u: goto P_0c097724;
case 0x0c097726u: goto P_0c097726;
case 0x0c097728u: goto P_0c097728;
case 0x0c09772au: goto P_0c09772a;
case 0x0c09772cu: goto P_0c09772c;
case 0x0c09772eu: goto P_0c09772e;
case 0x0c097730u: goto P_0c097730;
case 0x0c097732u: goto P_0c097732;
case 0x0c097734u: goto P_0c097734;
case 0x0c097736u: goto P_0c097736;
case 0x0c097738u: goto P_0c097738;
case 0x0c09773au: goto P_0c09773a;
case 0x0c097754u: goto P_0c097754;
case 0x0c097756u: goto P_0c097756;
case 0x0c097758u: goto P_0c097758;
case 0x0c09775au: goto P_0c09775a;
case 0x0c09775cu: goto P_0c09775c;
case 0x0c09775eu: goto P_0c09775e;
case 0x0c097760u: goto P_0c097760;
case 0x0c097762u: goto P_0c097762;
case 0x0c097764u: goto P_0c097764;
case 0x0c097766u: goto P_0c097766;
case 0x0c097768u: goto P_0c097768;
case 0x0c09776au: goto P_0c09776a;
case 0x0c09776cu: goto P_0c09776c;
case 0x0c09776eu: goto P_0c09776e;
case 0x0c097770u: goto P_0c097770;
case 0x0c097772u: goto P_0c097772;
case 0x0c097774u: goto P_0c097774;
case 0x0c097776u: goto P_0c097776;
case 0x0c097778u: goto P_0c097778;
case 0x0c09777au: goto P_0c09777a;
case 0x0c09777cu: goto P_0c09777c;
case 0x0c09777eu: goto P_0c09777e;
case 0x0c097780u: goto P_0c097780;
case 0x0c097782u: goto P_0c097782;
case 0x0c097784u: goto P_0c097784;
case 0x0c097786u: goto P_0c097786;
case 0x0c097788u: goto P_0c097788;
case 0x0c09778au: goto P_0c09778a;
case 0x0c09778cu: goto P_0c09778c;
case 0x0c09778eu: goto P_0c09778e;
case 0x0c097790u: goto P_0c097790;
case 0x0c097792u: goto P_0c097792;
case 0x0c097794u: goto P_0c097794;
case 0x0c097796u: goto P_0c097796;
case 0x0c097798u: goto P_0c097798;
case 0x0c09779au: goto P_0c09779a;
case 0x0c09779cu: goto P_0c09779c;
case 0x0c09779eu: goto P_0c09779e;
case 0x0c0977a0u: goto P_0c0977a0;
case 0x0c0977a2u: goto P_0c0977a2;
case 0x0c0977a4u: goto P_0c0977a4;
case 0x0c0977a6u: goto P_0c0977a6;
case 0x0c0977a8u: goto P_0c0977a8;
case 0x0c0977aau: goto P_0c0977aa;
case 0x0c0977acu: goto P_0c0977ac;
case 0x0c0977aeu: goto P_0c0977ae;
case 0x0c0977b0u: goto P_0c0977b0;
case 0x0c0977b2u: goto P_0c0977b2;
case 0x0c0977b4u: goto P_0c0977b4;
case 0x0c0977b6u: goto P_0c0977b6;
case 0x0c0977b8u: goto P_0c0977b8;
case 0x0c0977bau: goto P_0c0977ba;
case 0x0c0977bcu: goto P_0c0977bc;
case 0x0c0977beu: goto P_0c0977be;
case 0x0c0977c0u: goto P_0c0977c0;
case 0x0c0977c2u: goto P_0c0977c2;
case 0x0c0977c4u: goto P_0c0977c4;
case 0x0c0977c6u: goto P_0c0977c6;
case 0x0c0977c8u: goto P_0c0977c8;
case 0x0c0977cau: goto P_0c0977ca;
case 0x0c0977ccu: goto P_0c0977cc;
case 0x0c0977ceu: goto P_0c0977ce;
case 0x0c0977d0u: goto P_0c0977d0;
case 0x0c0977d2u: goto P_0c0977d2;
case 0x0c0977d4u: goto P_0c0977d4;
case 0x0c0977d6u: goto P_0c0977d6;
case 0x0c0977d8u: goto P_0c0977d8;
case 0x0c0977dau: goto P_0c0977da;
case 0x0c0977dcu: goto P_0c0977dc;
case 0x0c0977deu: goto P_0c0977de;
case 0x0c0977e0u: goto P_0c0977e0;
case 0x0c0977e2u: goto P_0c0977e2;
case 0x0c0977e4u: goto P_0c0977e4;
case 0x0c0977e6u: goto P_0c0977e6;
case 0x0c0977e8u: goto P_0c0977e8;
case 0x0c0977eau: goto P_0c0977ea;
case 0x0c0977ecu: goto P_0c0977ec;
case 0x0c0977eeu: goto P_0c0977ee;
case 0x0c0977f0u: goto P_0c0977f0;
case 0x0c0977f2u: goto P_0c0977f2;
case 0x0c0977f4u: goto P_0c0977f4;
case 0x0c0977f6u: goto P_0c0977f6;
case 0x0c0977f8u: goto P_0c0977f8;
case 0x0c0977fau: goto P_0c0977fa;
case 0x0c0977fcu: goto P_0c0977fc;
case 0x0c0977feu: goto P_0c0977fe;
case 0x0c097800u: goto P_0c097800;
case 0x0c097802u: goto P_0c097802;
case 0x0c097804u: goto P_0c097804;
case 0x0c097806u: goto P_0c097806;
case 0x0c097808u: goto P_0c097808;
case 0x0c09780au: goto P_0c09780a;
case 0x0c09780cu: goto P_0c09780c;
case 0x0c09780eu: goto P_0c09780e;
case 0x0c097810u: goto P_0c097810;
case 0x0c097812u: goto P_0c097812;
case 0x0c097814u: goto P_0c097814;
case 0x0c097816u: goto P_0c097816;
case 0x0c097818u: goto P_0c097818;
case 0x0c09781au: goto P_0c09781a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0971c8: /* original 2fe6, guest PC 0x0c0971c8 */
if(!s->budget--) { s->failed_pc=0x0c0971c8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0971ca;
P_0c0971ca: /* original 2fd6, guest PC 0x0c0971ca */
if(!s->budget--) { s->failed_pc=0x0c0971cau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0971cc;
P_0c0971cc: /* original fffb, guest PC 0x0c0971cc */
if(!s->budget--) { s->failed_pc=0x0c0971ccu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0971ce;
P_0c0971ce: /* original 9017, guest PC 0x0c0971ce */
if(!s->budget--) { s->failed_pc=0x0c0971ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097200u,2);
goto P_0c0971d0;
P_0c0971d0: /* original d40f, guest PC 0x0c0971d0 */
if(!s->budget--) { s->failed_pc=0x0c0971d0u; return 0; }
r[4]=read(ram,0x0c097210u,4);
goto P_0c0971d2;
P_0c0971d2: /* original 4f22, guest PC 0x0c0971d2 */
if(!s->budget--) { s->failed_pc=0x0c0971d2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0971d4;
P_0c0971d4: /* original 034d, guest PC 0x0c0971d4 */
if(!s->budget--) { s->failed_pc=0x0c0971d4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0971d6;
P_0c0971d6: /* original de0d, guest PC 0x0c0971d6 */
if(!s->budget--) { s->failed_pc=0x0c0971d6u; return 0; }
r[14]=read(ram,0x0c09720cu,4);
goto P_0c0971d8;
P_0c0971d8: /* original d512, guest PC 0x0c0971d8 */
if(!s->budget--) { s->failed_pc=0x0c0971d8u; return 0; }
r[5]=read(ram,0x0c097224u,4);
goto P_0c0971da;
P_0c0971da: /* original 2338, guest PC 0x0c0971da */
if(!s->budget--) { s->failed_pc=0x0c0971dau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0971dc;
P_0c0971dc: /* original 8f2e, guest PC 0x0c0971dc */
if(!s->budget--) { s->failed_pc=0x0c0971dcu; return 0; }
cond=r[17]&1u;
r[13]=read(ram,r[5]+32,4);
if(!cond) { goto P_0c09723c; }
goto P_0c0971e0;
P_0c0971de: /* original 5d58, guest PC 0x0c0971de */
if(!s->budget--) { s->failed_pc=0x0c0971deu; return 0; }
r[13]=read(ram,r[5]+32,4);
goto P_0c0971e0;
P_0c0971e0: /* original 5654, guest PC 0x0c0971e0 */
if(!s->budget--) { s->failed_pc=0x0c0971e0u; return 0; }
r[6]=read(ram,r[5]+16,4);
goto P_0c0971e2;
P_0c0971e2: /* original e048, guest PC 0x0c0971e2 */
if(!s->budget--) { s->failed_pc=0x0c0971e2u; return 0; }
r[0]=0x00000048u;
goto P_0c0971e4;
P_0c0971e4: /* original 5755, guest PC 0x0c0971e4 */
if(!s->budget--) { s->failed_pc=0x0c0971e4u; return 0; }
r[7]=read(ram,r[5]+20,4);
goto P_0c0971e6;
P_0c0971e6: /* original 056e, guest PC 0x0c0971e6 */
if(!s->budget--) { s->failed_pc=0x0c0971e6u; return 0; }
r[5]=read(ram,r[6]+r[0],4);
goto P_0c0971e8;
P_0c0971e8: /* original 960d, guest PC 0x0c0971e8 */
if(!s->budget--) { s->failed_pc=0x0c0971e8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097206u,2);
goto P_0c0971ea;
P_0c0971ea: /* original 2568, guest PC 0x0c0971ea */
if(!s->budget--) { s->failed_pc=0x0c0971eau; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[6])==0)!=0);
goto P_0c0971ec;
P_0c0971ec: /* original 8f02, guest PC 0x0c0971ec */
if(!s->budget--) { s->failed_pc=0x0c0971ecu; return 0; }
cond=r[17]&1u;
r[7]=read(ram,r[7]+r[0],4);
if(!cond) { goto P_0c0971f4; }
goto P_0c0971f0;
P_0c0971ee: /* original 077e, guest PC 0x0c0971ee */
if(!s->budget--) { s->failed_pc=0x0c0971eeu; return 0; }
r[7]=read(ram,r[7]+r[0],4);
goto P_0c0971f0;
P_0c0971f0: /* original 2768, guest PC 0x0c0971f0 */
if(!s->budget--) { s->failed_pc=0x0c0971f0u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[6])==0)!=0);
goto P_0c0971f2;
P_0c0971f2: /* original 893b, guest PC 0x0c0971f2 */
if(!s->budget--) { s->failed_pc=0x0c0971f2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09726c; }
goto P_0c0971f4;
P_0c0971f4: /* original 9004, guest PC 0x0c0971f4 */
if(!s->budget--) { s->failed_pc=0x0c0971f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097200u,2);
goto P_0c0971f6;
P_0c0971f6: /* original 9307, guest PC 0x0c0971f6 */
if(!s->budget--) { s->failed_pc=0x0c0971f6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097208u,2);
goto P_0c0971f8;
P_0c0971f8: /* original a041, guest PC 0x0c0971f8 */
if(!s->budget--) { s->failed_pc=0x0c0971f8u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c09727e;
P_0c0971fa: /* original 0435, guest PC 0x0c0971fa */
if(!s->budget--) { s->failed_pc=0x0c0971fau; return 0; }
write(ram,r[4]+r[0],r[3],2);
if(!vf3_matrix_family(0x0c0971fcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0971fcu; return 0; } return 1;
P_0c09723c: /* original 054d, guest PC 0x0c09723c */
if(!s->budget--) { s->failed_pc=0x0c09723cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09723e;
P_0c09723e: /* original 75ff, guest PC 0x0c09723e */
if(!s->budget--) { s->failed_pc=0x0c09723eu; return 0; }
r[5]+=0xffffffffu;
goto P_0c097240;
P_0c097240: /* original 2558, guest PC 0x0c097240 */
if(!s->budget--) { s->failed_pc=0x0c097240u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c097242;
P_0c097242: /* original 8f13, guest PC 0x0c097242 */
if(!s->budget--) { s->failed_pc=0x0c097242u; return 0; }
cond=r[17]&1u;
write(ram,r[4]+r[0],r[5],2);
if(!cond) { goto P_0c09726c; }
goto P_0c097246;
P_0c097244: /* original 0455, guest PC 0x0c097244 */
if(!s->budget--) { s->failed_pc=0x0c097244u; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c097246;
P_0c097246: /* original c71b, guest PC 0x0c097246 */
if(!s->budget--) { s->failed_pc=0x0c097246u; return 0; }
r[0]=code_base|0x000972b4u;
goto P_0c097248;
P_0c097248: /* original d31b, guest PC 0x0c097248 */
if(!s->budget--) { s->failed_pc=0x0c097248u; return 0; }
r[3]=read(ram,0x0c0972b8u,4);
goto P_0c09724a;
P_0c09724a: /* original f408, guest PC 0x0c09724a */
if(!s->budget--) { s->failed_pc=0x0c09724au; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c09724c;
P_0c09724c: /* original ff8d, guest PC 0x0c09724c */
if(!s->budget--) { s->failed_pc=0x0c09724cu; return 0; }
fr[15]=0;
goto P_0c09724e;
P_0c09724e: /* original d518, guest PC 0x0c09724e */
if(!s->budget--) { s->failed_pc=0x0c09724eu; return 0; }
r[5]=read(ram,0x0c0972b0u,4);
goto P_0c097250;
P_0c097250: /* original f6fc, guest PC 0x0c097250 */
if(!s->budget--) { s->failed_pc=0x0c097250u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c097252;
P_0c097252: /* original f5fc, guest PC 0x0c097252 */
if(!s->budget--) { s->failed_pc=0x0c097252u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c097254;
P_0c097254: /* original 430b, guest PC 0x0c097254 */
if(!s->budget--) { s->failed_pc=0x0c097254u; return 0; }
target=r[3];
r[16]=code_base|0x0c097258u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097258u) { target=s->pc; goto dispatch; }
goto P_0c097258;
P_0c097256: /* original e400, guest PC 0x0c097256 */
if(!s->budget--) { s->failed_pc=0x0c097256u; return 0; }
r[4]=0x00000000u;
goto P_0c097258;
P_0c097258: /* original d217, guest PC 0x0c097258 */
if(!s->budget--) { s->failed_pc=0x0c097258u; return 0; }
r[2]=read(ram,0x0c0972b8u,4);
goto P_0c09725a;
P_0c09725a: /* original 9527, guest PC 0x0c09725a */
if(!s->budget--) { s->failed_pc=0x0c09725au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0972acu,2);
goto P_0c09725c;
P_0c09725c: /* original f49d, guest PC 0x0c09725c */
if(!s->budget--) { s->failed_pc=0x0c09725cu; return 0; }
fr[4]=0x3f800000u;
goto P_0c09725e;
P_0c09725e: /* original f6fc, guest PC 0x0c09725e */
if(!s->budget--) { s->failed_pc=0x0c09725eu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c097260;
P_0c097260: /* original f5fc, guest PC 0x0c097260 */
if(!s->budget--) { s->failed_pc=0x0c097260u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c097262;
P_0c097262: /* original 420b, guest PC 0x0c097262 */
if(!s->budget--) { s->failed_pc=0x0c097262u; return 0; }
target=r[2];
r[16]=code_base|0x0c097266u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097266u) { target=s->pc; goto dispatch; }
goto P_0c097266;
P_0c097264: /* original e401, guest PC 0x0c097264 */
if(!s->budget--) { s->failed_pc=0x0c097264u; return 0; }
r[4]=0x00000001u;
goto P_0c097266;
P_0c097266: /* original 9022, guest PC 0x0c097266 */
if(!s->budget--) { s->failed_pc=0x0c097266u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0972aeu,2);
goto P_0c097268;
P_0c097268: /* original e306, guest PC 0x0c097268 */
if(!s->budget--) { s->failed_pc=0x0c097268u; return 0; }
r[3]=0x00000006u;
goto P_0c09726a;
P_0c09726a: /* original 0d34, guest PC 0x0c09726a */
if(!s->budget--) { s->failed_pc=0x0c09726au; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c09726c;
P_0c09726c: /* original 52e3, guest PC 0x0c09726c */
if(!s->budget--) { s->failed_pc=0x0c09726cu; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c09726e;
P_0c09726e: /* original 4215, guest PC 0x0c09726e */
if(!s->budget--) { s->failed_pc=0x0c09726eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c097270;
P_0c097270: /* original 8905, guest PC 0x0c097270 */
if(!s->budget--) { s->failed_pc=0x0c097270u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09727e; }
goto P_0c097272;
P_0c097272: /* original 61d2, guest PC 0x0c097272 */
if(!s->budget--) { s->failed_pc=0x0c097272u; return 0; }
tmp=read(ram,r[13],4);
r[1]=tmp;
goto P_0c097274;
P_0c097274: /* original e000, guest PC 0x0c097274 */
if(!s->budget--) { s->failed_pc=0x0c097274u; return 0; }
r[0]=0x00000000u;
goto P_0c097276;
P_0c097276: /* original d311, guest PC 0x0c097276 */
if(!s->budget--) { s->failed_pc=0x0c097276u; return 0; }
r[3]=read(ram,0x0c0972bcu,4);
goto P_0c097278;
P_0c097278: /* original 2139, guest PC 0x0c097278 */
if(!s->budget--) { s->failed_pc=0x0c097278u; return 0; }
r[1]&=r[3];
goto P_0c09727a;
P_0c09727a: /* original 2d12, guest PC 0x0c09727a */
if(!s->budget--) { s->failed_pc=0x0c09727au; return 0; }
write(ram,r[13],r[1],4);
goto P_0c09727c;
P_0c09727c: /* original 80eb, guest PC 0x0c09727c */
if(!s->budget--) { s->failed_pc=0x0c09727cu; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09727e;
P_0c09727e: /* original 4f26, guest PC 0x0c09727e */
if(!s->budget--) { s->failed_pc=0x0c09727eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c097280;
P_0c097280: /* original fff9, guest PC 0x0c097280 */
if(!s->budget--) { s->failed_pc=0x0c097280u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c097282;
P_0c097282: /* original 6df6, guest PC 0x0c097282 */
if(!s->budget--) { s->failed_pc=0x0c097282u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c097284;
P_0c097284: /* original ad6b, guest PC 0x0c097284 */
if(!s->budget--) { s->failed_pc=0x0c097284u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c096d5eu,s,ram);
P_0c097286: /* original 6ef6, guest PC 0x0c097286 */
if(!s->budget--) { s->failed_pc=0x0c097286u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c097288u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c097288u; return 0; } return 1;
P_0c0972c4: /* original 2fe6, guest PC 0x0c0972c4 */
if(!s->budget--) { s->failed_pc=0x0c0972c4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0972c6;
P_0c0972c6: /* original 2fd6, guest PC 0x0c0972c6 */
if(!s->budget--) { s->failed_pc=0x0c0972c6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0972c8;
P_0c0972c8: /* original 2fc6, guest PC 0x0c0972c8 */
if(!s->budget--) { s->failed_pc=0x0c0972c8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0972ca;
P_0c0972ca: /* original 2fb6, guest PC 0x0c0972ca */
if(!s->budget--) { s->failed_pc=0x0c0972cau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0972cc;
P_0c0972cc: /* original 2fa6, guest PC 0x0c0972cc */
if(!s->budget--) { s->failed_pc=0x0c0972ccu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0972ce;
P_0c0972ce: /* original 2f96, guest PC 0x0c0972ce */
if(!s->budget--) { s->failed_pc=0x0c0972ceu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0972d0;
P_0c0972d0: /* original fffb, guest PC 0x0c0972d0 */
if(!s->budget--) { s->failed_pc=0x0c0972d0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0972d2;
P_0c0972d2: /* original 4f22, guest PC 0x0c0972d2 */
if(!s->budget--) { s->failed_pc=0x0c0972d2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0972d4;
P_0c0972d4: /* original dc56, guest PC 0x0c0972d4 */
if(!s->budget--) { s->failed_pc=0x0c0972d4u; return 0; }
r[12]=read(ram,0x0c097430u,4);
goto P_0c0972d6;
P_0c0972d6: /* original d357, guest PC 0x0c0972d6 */
if(!s->budget--) { s->failed_pc=0x0c0972d6u; return 0; }
r[3]=read(ram,0x0c097434u,4);
goto P_0c0972d8;
P_0c0972d8: /* original da54, guest PC 0x0c0972d8 */
if(!s->budget--) { s->failed_pc=0x0c0972d8u; return 0; }
r[10]=read(ram,0x0c09742cu,4);
goto P_0c0972da;
P_0c0972da: /* original 7ff8, guest PC 0x0c0972da */
if(!s->budget--) { s->failed_pc=0x0c0972dau; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0972dc;
P_0c0972dc: /* original dd52, guest PC 0x0c0972dc */
if(!s->budget--) { s->failed_pc=0x0c0972dcu; return 0; }
r[13]=read(ram,0x0c097428u,4);
goto P_0c0972de;
P_0c0972de: /* original 430b, guest PC 0x0c0972de */
if(!s->budget--) { s->failed_pc=0x0c0972deu; return 0; }
target=r[3];
r[16]=code_base|0x0c0972e2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0972e2u) { target=s->pc; goto dispatch; }
goto P_0c0972e2;
P_0c0972e0: /* original 0009, guest PC 0x0c0972e0 */
if(!s->budget--) { s->failed_pc=0x0c0972e0u; return 0; }
goto P_0c0972e2;
P_0c0972e2: /* original d255, guest PC 0x0c0972e2 */
if(!s->budget--) { s->failed_pc=0x0c0972e2u; return 0; }
r[2]=read(ram,0x0c097438u,4);
goto P_0c0972e4;
P_0c0972e4: /* original e600, guest PC 0x0c0972e4 */
if(!s->budget--) { s->failed_pc=0x0c0972e4u; return 0; }
r[6]=0x00000000u;
goto P_0c0972e6;
P_0c0972e6: /* original 6563, guest PC 0x0c0972e6 */
if(!s->budget--) { s->failed_pc=0x0c0972e6u; return 0; }
r[5]=r[6];
goto P_0c0972e8;
P_0c0972e8: /* original 420b, guest PC 0x0c0972e8 */
if(!s->budget--) { s->failed_pc=0x0c0972e8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0972ecu;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0972ecu) { target=s->pc; goto dispatch; }
goto P_0c0972ec;
P_0c0972ea: /* original 6463, guest PC 0x0c0972ea */
if(!s->budget--) { s->failed_pc=0x0c0972eau; return 0; }
r[4]=r[6];
goto P_0c0972ec;
P_0c0972ec: /* original e600, guest PC 0x0c0972ec */
if(!s->budget--) { s->failed_pc=0x0c0972ecu; return 0; }
r[6]=0x00000000u;
goto P_0c0972ee;
P_0c0972ee: /* original d353, guest PC 0x0c0972ee */
if(!s->budget--) { s->failed_pc=0x0c0972eeu; return 0; }
r[3]=read(ram,0x0c09743cu,4);
goto P_0c0972f0;
P_0c0972f0: /* original ff8d, guest PC 0x0c0972f0 */
if(!s->budget--) { s->failed_pc=0x0c0972f0u; return 0; }
fr[15]=0;
goto P_0c0972f2;
P_0c0972f2: /* original 6563, guest PC 0x0c0972f2 */
if(!s->budget--) { s->failed_pc=0x0c0972f2u; return 0; }
r[5]=r[6];
goto P_0c0972f4;
P_0c0972f4: /* original f5fc, guest PC 0x0c0972f4 */
if(!s->budget--) { s->failed_pc=0x0c0972f4u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0972f6;
P_0c0972f6: /* original f4fc, guest PC 0x0c0972f6 */
if(!s->budget--) { s->failed_pc=0x0c0972f6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0972f8;
P_0c0972f8: /* original 430b, guest PC 0x0c0972f8 */
if(!s->budget--) { s->failed_pc=0x0c0972f8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0972fcu;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0972fcu) { target=s->pc; goto dispatch; }
goto P_0c0972fc;
P_0c0972fa: /* original 6463, guest PC 0x0c0972fa */
if(!s->budget--) { s->failed_pc=0x0c0972fau; return 0; }
r[4]=r[6];
goto P_0c0972fc;
P_0c0972fc: /* original d250, guest PC 0x0c0972fc */
if(!s->budget--) { s->failed_pc=0x0c0972fcu; return 0; }
r[2]=read(ram,0x0c097440u,4);
goto P_0c0972fe;
P_0c0972fe: /* original 420b, guest PC 0x0c0972fe */
if(!s->budget--) { s->failed_pc=0x0c0972feu; return 0; }
target=r[2];
r[16]=code_base|0x0c097302u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097302u) { target=s->pc; goto dispatch; }
goto P_0c097302;
P_0c097300: /* original 0009, guest PC 0x0c097300 */
if(!s->budget--) { s->failed_pc=0x0c097300u; return 0; }
goto P_0c097302;
P_0c097302: /* original 9488, guest PC 0x0c097302 */
if(!s->budget--) { s->failed_pc=0x0c097302u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097416u,2);
goto P_0c097304;
P_0c097304: /* original de4f, guest PC 0x0c097304 */
if(!s->budget--) { s->failed_pc=0x0c097304u; return 0; }
r[14]=read(ram,0x0c097444u,4);
goto P_0c097306;
P_0c097306: /* original 4e0b, guest PC 0x0c097306 */
if(!s->budget--) { s->failed_pc=0x0c097306u; return 0; }
target=r[14];
r[16]=code_base|0x0c09730au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09730au) { target=s->pc; goto dispatch; }
goto P_0c09730a;
P_0c097308: /* original 0009, guest PC 0x0c097308 */
if(!s->budget--) { s->failed_pc=0x0c097308u; return 0; }
goto P_0c09730a;
P_0c09730a: /* original 4e0b, guest PC 0x0c09730a */
if(!s->budget--) { s->failed_pc=0x0c09730au; return 0; }
target=r[14];
r[16]=code_base|0x0c09730eu;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09730eu) { target=s->pc; goto dispatch; }
goto P_0c09730e;
P_0c09730c: /* original e414, guest PC 0x0c09730c */
if(!s->budget--) { s->failed_pc=0x0c09730cu; return 0; }
r[4]=0x00000014u;
goto P_0c09730e;
P_0c09730e: /* original 4e0b, guest PC 0x0c09730e */
if(!s->budget--) { s->failed_pc=0x0c09730eu; return 0; }
target=r[14];
r[16]=code_base|0x0c097312u;
r[4]=0x00000016u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097312u) { target=s->pc; goto dispatch; }
goto P_0c097312;
P_0c097310: /* original e416, guest PC 0x0c097310 */
if(!s->budget--) { s->failed_pc=0x0c097310u; return 0; }
r[4]=0x00000016u;
goto P_0c097312;
P_0c097312: /* original 4e0b, guest PC 0x0c097312 */
if(!s->budget--) { s->failed_pc=0x0c097312u; return 0; }
target=r[14];
r[16]=code_base|0x0c097316u;
r[4]=0x00000017u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097316u) { target=s->pc; goto dispatch; }
goto P_0c097316;
P_0c097314: /* original e417, guest PC 0x0c097314 */
if(!s->budget--) { s->failed_pc=0x0c097314u; return 0; }
r[4]=0x00000017u;
goto P_0c097316;
P_0c097316: /* original 4e0b, guest PC 0x0c097316 */
if(!s->budget--) { s->failed_pc=0x0c097316u; return 0; }
target=r[14];
r[16]=code_base|0x0c09731au;
r[4]=0x0000000fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09731au) { target=s->pc; goto dispatch; }
goto P_0c09731a;
P_0c097318: /* original e40f, guest PC 0x0c097318 */
if(!s->budget--) { s->failed_pc=0x0c097318u; return 0; }
r[4]=0x0000000fu;
goto P_0c09731a;
P_0c09731a: /* original d34b, guest PC 0x0c09731a */
if(!s->budget--) { s->failed_pc=0x0c09731au; return 0; }
r[3]=read(ram,0x0c097448u,4);
goto P_0c09731c;
P_0c09731c: /* original 430b, guest PC 0x0c09731c */
if(!s->budget--) { s->failed_pc=0x0c09731cu; return 0; }
target=r[3];
r[16]=code_base|0x0c097320u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097320u) { target=s->pc; goto dispatch; }
goto P_0c097320;
P_0c09731e: /* original 0009, guest PC 0x0c09731e */
if(!s->budget--) { s->failed_pc=0x0c09731eu; return 0; }
goto P_0c097320;
P_0c097320: /* original d24a, guest PC 0x0c097320 */
if(!s->budget--) { s->failed_pc=0x0c097320u; return 0; }
r[2]=read(ram,0x0c09744cu,4);
goto P_0c097322;
P_0c097322: /* original 420b, guest PC 0x0c097322 */
if(!s->budget--) { s->failed_pc=0x0c097322u; return 0; }
target=r[2];
r[16]=code_base|0x0c097326u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097326u) { target=s->pc; goto dispatch; }
goto P_0c097326;
P_0c097324: /* original 0009, guest PC 0x0c097324 */
if(!s->budget--) { s->failed_pc=0x0c097324u; return 0; }
goto P_0c097326;
P_0c097326: /* original d34a, guest PC 0x0c097326 */
if(!s->budget--) { s->failed_pc=0x0c097326u; return 0; }
r[3]=read(ram,0x0c097450u,4);
goto P_0c097328;
P_0c097328: /* original 430b, guest PC 0x0c097328 */
if(!s->budget--) { s->failed_pc=0x0c097328u; return 0; }
target=r[3];
r[16]=code_base|0x0c09732cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09732cu) { target=s->pc; goto dispatch; }
goto P_0c09732c;
P_0c09732a: /* original 0009, guest PC 0x0c09732a */
if(!s->budget--) { s->failed_pc=0x0c09732au; return 0; }
goto P_0c09732c;
P_0c09732c: /* original bb0a, guest PC 0x0c09732c */
if(!s->budget--) { s->failed_pc=0x0c09732cu; return 0; }
target=code_base|0x0c096944u; r[16]=code_base|0x0c097330u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097330u) { target=s->pc; goto dispatch; }
goto P_0c097330;
P_0c09732e: /* original 0009, guest PC 0x0c09732e */
if(!s->budget--) { s->failed_pc=0x0c09732eu; return 0; }
goto P_0c097330;
P_0c097330: /* original d348, guest PC 0x0c097330 */
if(!s->budget--) { s->failed_pc=0x0c097330u; return 0; }
r[3]=read(ram,0x0c097454u,4);
goto P_0c097332;
P_0c097332: /* original 430b, guest PC 0x0c097332 */
if(!s->budget--) { s->failed_pc=0x0c097332u; return 0; }
target=r[3];
r[16]=code_base|0x0c097336u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097336u) { target=s->pc; goto dispatch; }
goto P_0c097336;
P_0c097334: /* original 0009, guest PC 0x0c097334 */
if(!s->budget--) { s->failed_pc=0x0c097334u; return 0; }
goto P_0c097336;
P_0c097336: /* original d248, guest PC 0x0c097336 */
if(!s->budget--) { s->failed_pc=0x0c097336u; return 0; }
r[2]=read(ram,0x0c097458u,4);
goto P_0c097338;
P_0c097338: /* original 420b, guest PC 0x0c097338 */
if(!s->budget--) { s->failed_pc=0x0c097338u; return 0; }
target=r[2];
r[16]=code_base|0x0c09733cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09733cu) { target=s->pc; goto dispatch; }
goto P_0c09733c;
P_0c09733a: /* original 0009, guest PC 0x0c09733a */
if(!s->budget--) { s->failed_pc=0x0c09733au; return 0; }
goto P_0c09733c;
P_0c09733c: /* original e4ff, guest PC 0x0c09733c */
if(!s->budget--) { s->failed_pc=0x0c09733cu; return 0; }
r[4]=0xffffffffu;
goto P_0c09733e;
P_0c09733e: /* original 1d48, guest PC 0x0c09733e */
if(!s->budget--) { s->failed_pc=0x0c09733eu; return 0; }
write(ram,r[13]+32,r[4],4);
goto P_0c097340;
P_0c097340: /* original 1d4a, guest PC 0x0c097340 */
if(!s->budget--) { s->failed_pc=0x0c097340u; return 0; }
write(ram,r[13]+40,r[4],4);
goto P_0c097342;
P_0c097342: /* original 1d49, guest PC 0x0c097342 */
if(!s->budget--) { s->failed_pc=0x0c097342u; return 0; }
write(ram,r[13]+36,r[4],4);
goto P_0c097344;
P_0c097344: /* original d345, guest PC 0x0c097344 */
if(!s->budget--) { s->failed_pc=0x0c097344u; return 0; }
r[3]=read(ram,0x0c09745cu,4);
goto P_0c097346;
P_0c097346: /* original 430b, guest PC 0x0c097346 */
if(!s->budget--) { s->failed_pc=0x0c097346u; return 0; }
target=r[3];
r[16]=code_base|0x0c09734au;
write(ram,r[13]+44,r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09734au) { target=s->pc; goto dispatch; }
goto P_0c09734a;
P_0c097348: /* original 1d4b, guest PC 0x0c097348 */
if(!s->budget--) { s->failed_pc=0x0c097348u; return 0; }
write(ram,r[13]+44,r[4],4);
goto P_0c09734a;
P_0c09734a: /* original c745, guest PC 0x0c09734a */
if(!s->budget--) { s->failed_pc=0x0c09734au; return 0; }
r[0]=code_base|0x00097460u;
goto P_0c09734c;
P_0c09734c: /* original 69c3, guest PC 0x0c09734c */
if(!s->budget--) { s->failed_pc=0x0c09734cu; return 0; }
r[9]=r[12];
goto P_0c09734e;
P_0c09734e: /* original f308, guest PC 0x0c09734e */
if(!s->budget--) { s->failed_pc=0x0c09734eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c097350;
P_0c097350: /* original e010, guest PC 0x0c097350 */
if(!s->budget--) { s->failed_pc=0x0c097350u; return 0; }
r[0]=0x00000010u;
goto P_0c097352;
P_0c097352: /* original fa3a, guest PC 0x0c097352 */
if(!s->budget--) { s->failed_pc=0x0c097352u; return 0; }
vf3_matrix_store(s,ram,3,r[10]);
goto P_0c097354;
P_0c097354: /* original 52a2, guest PC 0x0c097354 */
if(!s->budget--) { s->failed_pc=0x0c097354u; return 0; }
r[2]=read(ram,r[10]+8,4);
goto P_0c097356;
P_0c097356: /* original 935f, guest PC 0x0c097356 */
if(!s->budget--) { s->failed_pc=0x0c097356u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097418u,2);
goto P_0c097358;
P_0c097358: /* original 2239, guest PC 0x0c097358 */
if(!s->budget--) { s->failed_pc=0x0c097358u; return 0; }
r[2]&=r[3];
goto P_0c09735a;
P_0c09735a: /* original 1a22, guest PC 0x0c09735a */
if(!s->budget--) { s->failed_pc=0x0c09735au; return 0; }
write(ram,r[10]+8,r[2],4);
goto P_0c09735c;
P_0c09735c: /* original e2ff, guest PC 0x0c09735c */
if(!s->budget--) { s->failed_pc=0x0c09735cu; return 0; }
r[2]=0xffffffffu;
goto P_0c09735e;
P_0c09735e: /* original de41, guest PC 0x0c09735e */
if(!s->budget--) { s->failed_pc=0x0c09735eu; return 0; }
r[14]=read(ram,0x0c097464u,4);
goto P_0c097360;
P_0c097360: /* original 54e4, guest PC 0x0c097360 */
if(!s->budget--) { s->failed_pc=0x0c097360u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c097362;
P_0c097362: /* original f4f7, guest PC 0x0c097362 */
if(!s->budget--) { s->failed_pc=0x0c097362u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c097364;
P_0c097364: /* original e018, guest PC 0x0c097364 */
if(!s->budget--) { s->failed_pc=0x0c097364u; return 0; }
r[0]=0x00000018u;
goto P_0c097366;
P_0c097366: /* original f4f7, guest PC 0x0c097366 */
if(!s->budget--) { s->failed_pc=0x0c097366u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c097368;
P_0c097368: /* original 9057, guest PC 0x0c097368 */
if(!s->budget--) { s->failed_pc=0x0c097368u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09741au,2);
goto P_0c09736a;
P_0c09736a: /* original f4f7, guest PC 0x0c09736a */
if(!s->budget--) { s->failed_pc=0x0c09736au; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c09736c;
P_0c09736c: /* original 7008, guest PC 0x0c09736c */
if(!s->budget--) { s->failed_pc=0x0c09736cu; return 0; }
r[0]+=0x00000008u;
goto P_0c09736e;
P_0c09736e: /* original f4f7, guest PC 0x0c09736e */
if(!s->budget--) { s->failed_pc=0x0c09736eu; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c097370;
P_0c097370: /* original e010, guest PC 0x0c097370 */
if(!s->budget--) { s->failed_pc=0x0c097370u; return 0; }
r[0]=0x00000010u;
goto P_0c097372;
P_0c097372: /* original 5be5, guest PC 0x0c097372 */
if(!s->budget--) { s->failed_pc=0x0c097372u; return 0; }
r[11]=read(ram,r[14]+20,4);
goto P_0c097374;
P_0c097374: /* original fbf7, guest PC 0x0c097374 */
if(!s->budget--) { s->failed_pc=0x0c097374u; return 0; }
vf3_matrix_store(s,ram,15,r[11]+r[0]);
goto P_0c097376;
P_0c097376: /* original e018, guest PC 0x0c097376 */
if(!s->budget--) { s->failed_pc=0x0c097376u; return 0; }
r[0]=0x00000018u;
goto P_0c097378;
P_0c097378: /* original fbf7, guest PC 0x0c097378 */
if(!s->budget--) { s->failed_pc=0x0c097378u; return 0; }
vf3_matrix_store(s,ram,15,r[11]+r[0]);
goto P_0c09737a;
P_0c09737a: /* original 904e, guest PC 0x0c09737a */
if(!s->budget--) { s->failed_pc=0x0c09737au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09741au,2);
goto P_0c09737c;
P_0c09737c: /* original fbf7, guest PC 0x0c09737c */
if(!s->budget--) { s->failed_pc=0x0c09737cu; return 0; }
vf3_matrix_store(s,ram,15,r[11]+r[0]);
goto P_0c09737e;
P_0c09737e: /* original 7008, guest PC 0x0c09737e */
if(!s->budget--) { s->failed_pc=0x0c09737eu; return 0; }
r[0]+=0x00000008u;
goto P_0c097380;
P_0c097380: /* original fbf7, guest PC 0x0c097380 */
if(!s->budget--) { s->failed_pc=0x0c097380u; return 0; }
vf3_matrix_store(s,ram,15,r[11]+r[0]);
goto P_0c097382;
P_0c097382: /* original 904b, guest PC 0x0c097382 */
if(!s->budget--) { s->failed_pc=0x0c097382u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09741cu,2);
goto P_0c097384;
P_0c097384: /* original 0c26, guest PC 0x0c097384 */
if(!s->budget--) { s->failed_pc=0x0c097384u; return 0; }
write(ram,r[12]+r[0],r[2],4);
goto P_0c097386;
P_0c097386: /* original e200, guest PC 0x0c097386 */
if(!s->budget--) { s->failed_pc=0x0c097386u; return 0; }
r[2]=0x00000000u;
goto P_0c097388;
P_0c097388: /* original 7008, guest PC 0x0c097388 */
if(!s->budget--) { s->failed_pc=0x0c097388u; return 0; }
r[0]+=0x00000008u;
goto P_0c09738a;
P_0c09738a: /* original 0926, guest PC 0x0c09738a */
if(!s->budget--) { s->failed_pc=0x0c09738au; return 0; }
write(ram,r[9]+r[0],r[2],4);
goto P_0c09738c;
P_0c09738c: /* original 6693, guest PC 0x0c09738c */
if(!s->budget--) { s->failed_pc=0x0c09738cu; return 0; }
r[6]=r[9];
goto P_0c09738e;
P_0c09738e: /* original 9446, guest PC 0x0c09738e */
if(!s->budget--) { s->failed_pc=0x0c09738eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09741eu,2);
goto P_0c097390;
P_0c097390: /* original 7658, guest PC 0x0c097390 */
if(!s->budget--) { s->failed_pc=0x0c097390u; return 0; }
r[6]+=0x00000058u;
goto P_0c097392;
P_0c097392: /* original d235, guest PC 0x0c097392 */
if(!s->budget--) { s->failed_pc=0x0c097392u; return 0; }
r[2]=read(ram,0x0c097468u,4);
goto P_0c097394;
P_0c097394: /* original 6593, guest PC 0x0c097394 */
if(!s->budget--) { s->failed_pc=0x0c097394u; return 0; }
r[5]=r[9];
goto P_0c097396;
P_0c097396: /* original 420b, guest PC 0x0c097396 */
if(!s->budget--) { s->failed_pc=0x0c097396u; return 0; }
target=r[2];
r[16]=code_base|0x0c09739au;
r[5]+=0x0000002cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09739au) { target=s->pc; goto dispatch; }
goto P_0c09739a;
P_0c097398: /* original 752c, guest PC 0x0c097398 */
if(!s->budget--) { s->failed_pc=0x0c097398u; return 0; }
r[5]+=0x0000002cu;
goto P_0c09739a;
P_0c09739a: /* original e300, guest PC 0x0c09739a */
if(!s->budget--) { s->failed_pc=0x0c09739au; return 0; }
r[3]=0x00000000u;
goto P_0c09739c;
P_0c09739c: /* original 6493, guest PC 0x0c09739c */
if(!s->budget--) { s->failed_pc=0x0c09739cu; return 0; }
r[4]=r[9];
goto P_0c09739e;
P_0c09739e: /* original 6533, guest PC 0x0c09739e */
if(!s->budget--) { s->failed_pc=0x0c09739eu; return 0; }
r[5]=r[3];
goto P_0c0973a0;
P_0c0973a0: /* original 2f36, guest PC 0x0c0973a0 */
if(!s->budget--) { s->failed_pc=0x0c0973a0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0973a2;
P_0c0973a2: /* original d232, guest PC 0x0c0973a2 */
if(!s->budget--) { s->failed_pc=0x0c0973a2u; return 0; }
r[2]=read(ram,0x0c09746cu,4);
goto P_0c0973a4;
P_0c0973a4: /* original e730, guest PC 0x0c0973a4 */
if(!s->budget--) { s->failed_pc=0x0c0973a4u; return 0; }
r[7]=0x00000030u;
goto P_0c0973a6;
P_0c0973a6: /* original e63e, guest PC 0x0c0973a6 */
if(!s->budget--) { s->failed_pc=0x0c0973a6u; return 0; }
r[6]=0x0000003eu;
goto P_0c0973a8;
P_0c0973a8: /* original 420b, guest PC 0x0c0973a8 */
if(!s->budget--) { s->failed_pc=0x0c0973a8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0973acu;
r[4]+=0x0000002cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0973acu) { target=s->pc; goto dispatch; }
goto P_0c0973ac;
P_0c0973aa: /* original 742c, guest PC 0x0c0973aa */
if(!s->budget--) { s->failed_pc=0x0c0973aau; return 0; }
r[4]+=0x0000002cu;
goto P_0c0973ac;
P_0c0973ac: /* original 9438, guest PC 0x0c0973ac */
if(!s->budget--) { s->failed_pc=0x0c0973acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097420u,2);
goto P_0c0973ae;
P_0c0973ae: /* original dc30, guest PC 0x0c0973ae */
if(!s->budget--) { s->failed_pc=0x0c0973aeu; return 0; }
r[12]=read(ram,0x0c097470u,4);
goto P_0c0973b0;
P_0c0973b0: /* original 4c0b, guest PC 0x0c0973b0 */
if(!s->budget--) { s->failed_pc=0x0c0973b0u; return 0; }
target=r[12];
r[16]=code_base|0x0c0973b4u;
r[4]+=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0973b4u) { target=s->pc; goto dispatch; }
goto P_0c0973b4;
P_0c0973b2: /* original 349c, guest PC 0x0c0973b2 */
if(!s->budget--) { s->failed_pc=0x0c0973b2u; return 0; }
r[4]+=r[9];
goto P_0c0973b4;
P_0c0973b4: /* original 4c0b, guest PC 0x0c0973b4 */
if(!s->budget--) { s->failed_pc=0x0c0973b4u; return 0; }
target=r[12];
r[16]=code_base|0x0c0973b8u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0973b8u) { target=s->pc; goto dispatch; }
goto P_0c0973b8;
P_0c0973b6: /* original 6493, guest PC 0x0c0973b6 */
if(!s->budget--) { s->failed_pc=0x0c0973b6u; return 0; }
r[4]=r[9];
goto P_0c0973b8;
P_0c0973b8: /* original 6493, guest PC 0x0c0973b8 */
if(!s->budget--) { s->failed_pc=0x0c0973b8u; return 0; }
r[4]=r[9];
goto P_0c0973ba;
P_0c0973ba: /* original 4c0b, guest PC 0x0c0973ba */
if(!s->budget--) { s->failed_pc=0x0c0973bau; return 0; }
target=r[12];
r[16]=code_base|0x0c0973beu;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0973beu) { target=s->pc; goto dispatch; }
goto P_0c0973be;
P_0c0973bc: /* original 7458, guest PC 0x0c0973bc */
if(!s->budget--) { s->failed_pc=0x0c0973bcu; return 0; }
r[4]+=0x00000058u;
goto P_0c0973be;
P_0c0973be: /* original 9030, guest PC 0x0c0973be */
if(!s->budget--) { s->failed_pc=0x0c0973beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097422u,2);
goto P_0c0973c0;
P_0c0973c0: /* original ec00, guest PC 0x0c0973c0 */
if(!s->budget--) { s->failed_pc=0x0c0973c0u; return 0; }
r[12]=0x00000000u;
goto P_0c0973c2;
P_0c0973c2: /* original d32c, guest PC 0x0c0973c2 */
if(!s->budget--) { s->failed_pc=0x0c0973c2u; return 0; }
r[3]=read(ram,0x0c097474u,4);
goto P_0c0973c4;
P_0c0973c4: /* original 54ec, guest PC 0x0c0973c4 */
if(!s->budget--) { s->failed_pc=0x0c0973c4u; return 0; }
r[4]=read(ram,r[14]+48,4);
goto P_0c0973c6;
P_0c0973c6: /* original 0436, guest PC 0x0c0973c6 */
if(!s->budget--) { s->failed_pc=0x0c0973c6u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c0973c8;
P_0c0973c8: /* original 7098, guest PC 0x0c0973c8 */
if(!s->budget--) { s->failed_pc=0x0c0973c8u; return 0; }
r[0]+=0xffffff98u;
goto P_0c0973ca;
P_0c0973ca: /* original 0dc4, guest PC 0x0c0973ca */
if(!s->budget--) { s->failed_pc=0x0c0973cau; return 0; }
write(ram,r[13]+r[0],r[12],1);
goto P_0c0973cc;
P_0c0973cc: /* original ba94, guest PC 0x0c0973cc */
if(!s->budget--) { s->failed_pc=0x0c0973ccu; return 0; }
target=code_base|0x0c0968f8u; r[16]=code_base|0x0c0973d0u;
r[4]=read(ram,r[14]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0973d0u) { target=s->pc; goto dispatch; }
goto P_0c0973d0;
P_0c0973ce: /* original 54e6, guest PC 0x0c0973ce */
if(!s->budget--) { s->failed_pc=0x0c0973ceu; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c0973d0;
P_0c0973d0: /* original ba92, guest PC 0x0c0973d0 */
if(!s->budget--) { s->failed_pc=0x0c0973d0u; return 0; }
target=code_base|0x0c0968f8u; r[16]=code_base|0x0c0973d4u;
r[4]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0973d4u) { target=s->pc; goto dispatch; }
goto P_0c0973d4;
P_0c0973d2: /* original 54e7, guest PC 0x0c0973d2 */
if(!s->budget--) { s->failed_pc=0x0c0973d2u; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c0973d4;
P_0c0973d4: /* original ba90, guest PC 0x0c0973d4 */
if(!s->budget--) { s->failed_pc=0x0c0973d4u; return 0; }
target=code_base|0x0c0968f8u; r[16]=code_base|0x0c0973d8u;
r[4]=read(ram,r[14]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0973d8u) { target=s->pc; goto dispatch; }
goto P_0c0973d8;
P_0c0973d6: /* original 54ef, guest PC 0x0c0973d6 */
if(!s->budget--) { s->failed_pc=0x0c0973d6u; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c0973d8;
P_0c0973d8: /* original e040, guest PC 0x0c0973d8 */
if(!s->budget--) { s->failed_pc=0x0c0973d8u; return 0; }
r[0]=0x00000040u;
goto P_0c0973da;
P_0c0973da: /* original ba8d, guest PC 0x0c0973da */
if(!s->budget--) { s->failed_pc=0x0c0973dau; return 0; }
target=code_base|0x0c0968f8u; r[16]=code_base|0x0c0973deu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0973deu) { target=s->pc; goto dispatch; }
goto P_0c0973de;
P_0c0973dc: /* original 04ee, guest PC 0x0c0973dc */
if(!s->budget--) { s->failed_pc=0x0c0973dcu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0973de;
P_0c0973de: /* original ba8b, guest PC 0x0c0973de */
if(!s->budget--) { s->failed_pc=0x0c0973deu; return 0; }
target=code_base|0x0c0968f8u; r[16]=code_base|0x0c0973e2u;
r[4]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0973e2u) { target=s->pc; goto dispatch; }
goto P_0c0973e2;
P_0c0973e0: /* original 54e4, guest PC 0x0c0973e0 */
if(!s->budget--) { s->failed_pc=0x0c0973e0u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c0973e2;
P_0c0973e2: /* original ba89, guest PC 0x0c0973e2 */
if(!s->budget--) { s->failed_pc=0x0c0973e2u; return 0; }
target=code_base|0x0c0968f8u; r[16]=code_base|0x0c0973e6u;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0973e6u) { target=s->pc; goto dispatch; }
goto P_0c0973e6;
P_0c0973e4: /* original 54e5, guest PC 0x0c0973e4 */
if(!s->budget--) { s->failed_pc=0x0c0973e4u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c0973e6;
P_0c0973e6: /* original e048, guest PC 0x0c0973e6 */
if(!s->budget--) { s->failed_pc=0x0c0973e6u; return 0; }
r[0]=0x00000048u;
goto P_0c0973e8;
P_0c0973e8: /* original ba86, guest PC 0x0c0973e8 */
if(!s->budget--) { s->failed_pc=0x0c0973e8u; return 0; }
target=code_base|0x0c0968f8u; r[16]=code_base|0x0c0973ecu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0973ecu) { target=s->pc; goto dispatch; }
goto P_0c0973ec;
P_0c0973ea: /* original 04ee, guest PC 0x0c0973ea */
if(!s->budget--) { s->failed_pc=0x0c0973eau; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0973ec;
P_0c0973ec: /* original e05c, guest PC 0x0c0973ec */
if(!s->budget--) { s->failed_pc=0x0c0973ecu; return 0; }
r[0]=0x0000005cu;
goto P_0c0973ee;
P_0c0973ee: /* original ba83, guest PC 0x0c0973ee */
if(!s->budget--) { s->failed_pc=0x0c0973eeu; return 0; }
target=code_base|0x0c0968f8u; r[16]=code_base|0x0c0973f2u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0973f2u) { target=s->pc; goto dispatch; }
goto P_0c0973f2;
P_0c0973f0: /* original 04ee, guest PC 0x0c0973f0 */
if(!s->budget--) { s->failed_pc=0x0c0973f0u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0973f2;
P_0c0973f2: /* original e060, guest PC 0x0c0973f2 */
if(!s->budget--) { s->failed_pc=0x0c0973f2u; return 0; }
r[0]=0x00000060u;
goto P_0c0973f4;
P_0c0973f4: /* original ba80, guest PC 0x0c0973f4 */
if(!s->budget--) { s->failed_pc=0x0c0973f4u; return 0; }
target=code_base|0x0c0968f8u; r[16]=code_base|0x0c0973f8u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0973f8u) { target=s->pc; goto dispatch; }
goto P_0c0973f8;
P_0c0973f6: /* original 04ee, guest PC 0x0c0973f6 */
if(!s->budget--) { s->failed_pc=0x0c0973f6u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0973f8;
P_0c0973f8: /* original e064, guest PC 0x0c0973f8 */
if(!s->budget--) { s->failed_pc=0x0c0973f8u; return 0; }
r[0]=0x00000064u;
goto P_0c0973fa;
P_0c0973fa: /* original ba7d, guest PC 0x0c0973fa */
if(!s->budget--) { s->failed_pc=0x0c0973fau; return 0; }
target=code_base|0x0c0968f8u; r[16]=code_base|0x0c0973feu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0973feu) { target=s->pc; goto dispatch; }
goto P_0c0973fe;
P_0c0973fc: /* original 04ee, guest PC 0x0c0973fc */
if(!s->budget--) { s->failed_pc=0x0c0973fcu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0973fe;
P_0c0973fe: /* original e054, guest PC 0x0c0973fe */
if(!s->budget--) { s->failed_pc=0x0c0973feu; return 0; }
r[0]=0x00000054u;
goto P_0c097400;
P_0c097400: /* original ba7a, guest PC 0x0c097400 */
if(!s->budget--) { s->failed_pc=0x0c097400u; return 0; }
target=code_base|0x0c0968f8u; r[16]=code_base|0x0c097404u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097404u) { target=s->pc; goto dispatch; }
goto P_0c097404;
P_0c097402: /* original 04ee, guest PC 0x0c097402 */
if(!s->budget--) { s->failed_pc=0x0c097402u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c097404;
P_0c097404: /* original 900e, guest PC 0x0c097404 */
if(!s->budget--) { s->failed_pc=0x0c097404u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097424u,2);
goto P_0c097406;
P_0c097406: /* original 63c3, guest PC 0x0c097406 */
if(!s->budget--) { s->failed_pc=0x0c097406u; return 0; }
r[3]=r[12];
goto P_0c097408;
P_0c097408: /* original 0dc4, guest PC 0x0c097408 */
if(!s->budget--) { s->failed_pc=0x0c097408u; return 0; }
write(ram,r[13]+r[0],r[12],1);
goto P_0c09740a;
P_0c09740a: /* original 70d2, guest PC 0x0c09740a */
if(!s->budget--) { s->failed_pc=0x0c09740au; return 0; }
r[0]+=0xffffffd2u;
goto P_0c09740c;
P_0c09740c: /* original 0dc6, guest PC 0x0c09740c */
if(!s->budget--) { s->failed_pc=0x0c09740cu; return 0; }
write(ram,r[13]+r[0],r[12],4);
goto P_0c09740e;
P_0c09740e: /* original 7050, guest PC 0x0c09740e */
if(!s->budget--) { s->failed_pc=0x0c09740eu; return 0; }
r[0]+=0x00000050u;
goto P_0c097410;
P_0c097410: /* original 0d34, guest PC 0x0c097410 */
if(!s->budget--) { s->failed_pc=0x0c097410u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c097412;
P_0c097412: /* original a031, guest PC 0x0c097412 */
if(!s->budget--) { s->failed_pc=0x0c097412u; return 0; }
goto P_0c097478;
P_0c097414: /* original 0009, guest PC 0x0c097414 */
if(!s->budget--) { s->failed_pc=0x0c097414u; return 0; }
if(!vf3_matrix_family(0x0c097416u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c097416u; return 0; } return 1;
P_0c097478: /* original 54e4, guest PC 0x0c097478 */
if(!s->budget--) { s->failed_pc=0x0c097478u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c09747a;
P_0c09747a: /* original e3fd, guest PC 0x0c09747a */
if(!s->budget--) { s->failed_pc=0x0c09747au; return 0; }
r[3]=0xfffffffdu;
goto P_0c09747c;
P_0c09747c: /* original 6242, guest PC 0x0c09747c */
if(!s->budget--) { s->failed_pc=0x0c09747cu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09747e;
P_0c09747e: /* original 2239, guest PC 0x0c09747e */
if(!s->budget--) { s->failed_pc=0x0c09747eu; return 0; }
r[2]&=r[3];
goto P_0c097480;
P_0c097480: /* original 2422, guest PC 0x0c097480 */
if(!s->budget--) { s->failed_pc=0x0c097480u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c097482;
P_0c097482: /* original 908b, guest PC 0x0c097482 */
if(!s->budget--) { s->failed_pc=0x0c097482u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09759cu,2);
goto P_0c097484;
P_0c097484: /* original 04c4, guest PC 0x0c097484 */
if(!s->budget--) { s->failed_pc=0x0c097484u; return 0; }
write(ram,r[4]+r[0],r[12],1);
goto P_0c097486;
P_0c097486: /* original e060, guest PC 0x0c097486 */
if(!s->budget--) { s->failed_pc=0x0c097486u; return 0; }
r[0]=0x00000060u;
goto P_0c097488;
P_0c097488: /* original 024c, guest PC 0x0c097488 */
if(!s->budget--) { s->failed_pc=0x0c097488u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09748a;
P_0c09748a: /* original 622c, guest PC 0x0c09748a */
if(!s->budget--) { s->failed_pc=0x0c09748au; return 0; }
r[2]=r[2]&255u;
goto P_0c09748c;
P_0c09748c: /* original 1f21, guest PC 0x0c09748c */
if(!s->budget--) { s->failed_pc=0x0c09748cu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c09748e;
P_0c09748e: /* original 8444, guest PC 0x0c09748e */
if(!s->budget--) { s->failed_pc=0x0c09748eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+4,1);
goto P_0c097490;
P_0c097490: /* original 600c, guest PC 0x0c097490 */
if(!s->budget--) { s->failed_pc=0x0c097490u; return 0; }
r[0]=r[0]&255u;
goto P_0c097492;
P_0c097492: /* original 1f02, guest PC 0x0c097492 */
if(!s->budget--) { s->failed_pc=0x0c097492u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c097494;
P_0c097494: /* original 6603, guest PC 0x0c097494 */
if(!s->budget--) { s->failed_pc=0x0c097494u; return 0; }
r[6]=r[0];
goto P_0c097496;
P_0c097496: /* original 55f1, guest PC 0x0c097496 */
if(!s->budget--) { s->failed_pc=0x0c097496u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c097498;
P_0c097498: /* original d246, guest PC 0x0c097498 */
if(!s->budget--) { s->failed_pc=0x0c097498u; return 0; }
r[2]=read(ram,0x0c0975b4u,4);
goto P_0c09749a;
P_0c09749a: /* original 420b, guest PC 0x0c09749a */
if(!s->budget--) { s->failed_pc=0x0c09749au; return 0; }
target=r[2];
r[16]=code_base|0x0c09749eu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09749eu) { target=s->pc; goto dispatch; }
goto P_0c09749e;
P_0c09749c: /* original 64b3, guest PC 0x0c09749c */
if(!s->budget--) { s->failed_pc=0x0c09749cu; return 0; }
r[4]=r[11];
goto P_0c09749e;
P_0c09749e: /* original 54e5, guest PC 0x0c09749e */
if(!s->budget--) { s->failed_pc=0x0c09749eu; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c0974a0;
P_0c0974a0: /* original e3fd, guest PC 0x0c0974a0 */
if(!s->budget--) { s->failed_pc=0x0c0974a0u; return 0; }
r[3]=0xfffffffdu;
goto P_0c0974a2;
P_0c0974a2: /* original 6242, guest PC 0x0c0974a2 */
if(!s->budget--) { s->failed_pc=0x0c0974a2u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0974a4;
P_0c0974a4: /* original 2239, guest PC 0x0c0974a4 */
if(!s->budget--) { s->failed_pc=0x0c0974a4u; return 0; }
r[2]&=r[3];
goto P_0c0974a6;
P_0c0974a6: /* original 2422, guest PC 0x0c0974a6 */
if(!s->budget--) { s->failed_pc=0x0c0974a6u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c0974a8;
P_0c0974a8: /* original 9078, guest PC 0x0c0974a8 */
if(!s->budget--) { s->failed_pc=0x0c0974a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09759cu,2);
goto P_0c0974aa;
P_0c0974aa: /* original 04c4, guest PC 0x0c0974aa */
if(!s->budget--) { s->failed_pc=0x0c0974aau; return 0; }
write(ram,r[4]+r[0],r[12],1);
goto P_0c0974ac;
P_0c0974ac: /* original e060, guest PC 0x0c0974ac */
if(!s->budget--) { s->failed_pc=0x0c0974acu; return 0; }
r[0]=0x00000060u;
goto P_0c0974ae;
P_0c0974ae: /* original 024c, guest PC 0x0c0974ae */
if(!s->budget--) { s->failed_pc=0x0c0974aeu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0974b0;
P_0c0974b0: /* original 622c, guest PC 0x0c0974b0 */
if(!s->budget--) { s->failed_pc=0x0c0974b0u; return 0; }
r[2]=r[2]&255u;
goto P_0c0974b2;
P_0c0974b2: /* original 1f22, guest PC 0x0c0974b2 */
if(!s->budget--) { s->failed_pc=0x0c0974b2u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0974b4;
P_0c0974b4: /* original 8444, guest PC 0x0c0974b4 */
if(!s->budget--) { s->failed_pc=0x0c0974b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+4,1);
goto P_0c0974b6;
P_0c0974b6: /* original 600c, guest PC 0x0c0974b6 */
if(!s->budget--) { s->failed_pc=0x0c0974b6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0974b8;
P_0c0974b8: /* original 1f01, guest PC 0x0c0974b8 */
if(!s->budget--) { s->failed_pc=0x0c0974b8u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0974ba;
P_0c0974ba: /* original 6603, guest PC 0x0c0974ba */
if(!s->budget--) { s->failed_pc=0x0c0974bau; return 0; }
r[6]=r[0];
goto P_0c0974bc;
P_0c0974bc: /* original 55f2, guest PC 0x0c0974bc */
if(!s->budget--) { s->failed_pc=0x0c0974bcu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0974be;
P_0c0974be: /* original d23d, guest PC 0x0c0974be */
if(!s->budget--) { s->failed_pc=0x0c0974beu; return 0; }
r[2]=read(ram,0x0c0975b4u,4);
goto P_0c0974c0;
P_0c0974c0: /* original 420b, guest PC 0x0c0974c0 */
if(!s->budget--) { s->failed_pc=0x0c0974c0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0974c4u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0974c4u) { target=s->pc; goto dispatch; }
goto P_0c0974c4;
P_0c0974c2: /* original 64b3, guest PC 0x0c0974c2 */
if(!s->budget--) { s->failed_pc=0x0c0974c2u; return 0; }
r[4]=r[11];
goto P_0c0974c4;
P_0c0974c4: /* original e111, guest PC 0x0c0974c4 */
if(!s->budget--) { s->failed_pc=0x0c0974c4u; return 0; }
r[1]=0x00000011u;
goto P_0c0974c6;
P_0c0974c6: /* original d33c, guest PC 0x0c0974c6 */
if(!s->budget--) { s->failed_pc=0x0c0974c6u; return 0; }
r[3]=read(ram,0x0c0975b8u,4);
goto P_0c0974c8;
P_0c0974c8: /* original e010, guest PC 0x0c0974c8 */
if(!s->budget--) { s->failed_pc=0x0c0974c8u; return 0; }
r[0]=0x00000010u;
goto P_0c0974ca;
P_0c0974ca: /* original 52a2, guest PC 0x0c0974ca */
if(!s->budget--) { s->failed_pc=0x0c0974cau; return 0; }
r[2]=read(ram,r[10]+8,4);
goto P_0c0974cc;
P_0c0974cc: /* original e50f, guest PC 0x0c0974cc */
if(!s->budget--) { s->failed_pc=0x0c0974ccu; return 0; }
r[5]=0x0000000fu;
goto P_0c0974ce;
P_0c0974ce: /* original 2239, guest PC 0x0c0974ce */
if(!s->budget--) { s->failed_pc=0x0c0974ceu; return 0; }
r[2]&=r[3];
goto P_0c0974d0;
P_0c0974d0: /* original 1a22, guest PC 0x0c0974d0 */
if(!s->budget--) { s->failed_pc=0x0c0974d0u; return 0; }
write(ram,r[10]+8,r[2],4);
goto P_0c0974d2;
P_0c0974d2: /* original e201, guest PC 0x0c0974d2 */
if(!s->budget--) { s->failed_pc=0x0c0974d2u; return 0; }
r[2]=0x00000001u;
goto P_0c0974d4;
P_0c0974d4: /* original 0d14, guest PC 0x0c0974d4 */
if(!s->budget--) { s->failed_pc=0x0c0974d4u; return 0; }
write(ram,r[13]+r[0],r[1],1);
goto P_0c0974d6;
P_0c0974d6: /* original e114, guest PC 0x0c0974d6 */
if(!s->budget--) { s->failed_pc=0x0c0974d6u; return 0; }
r[1]=0x00000014u;
goto P_0c0974d8;
P_0c0974d8: /* original 9061, guest PC 0x0c0974d8 */
if(!s->budget--) { s->failed_pc=0x0c0974d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09759eu,2);
goto P_0c0974da;
P_0c0974da: /* original 54e8, guest PC 0x0c0974da */
if(!s->budget--) { s->failed_pc=0x0c0974dau; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c0974dc;
P_0c0974dc: /* original f4f7, guest PC 0x0c0974dc */
if(!s->budget--) { s->failed_pc=0x0c0974dcu; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c0974de;
P_0c0974de: /* original 709f, guest PC 0x0c0974de */
if(!s->budget--) { s->failed_pc=0x0c0974deu; return 0; }
r[0]+=0xffffff9fu;
goto P_0c0974e0;
P_0c0974e0: /* original 04c4, guest PC 0x0c0974e0 */
if(!s->budget--) { s->failed_pc=0x0c0974e0u; return 0; }
write(ram,r[4]+r[0],r[12],1);
goto P_0c0974e2;
P_0c0974e2: /* original 2422, guest PC 0x0c0974e2 */
if(!s->budget--) { s->failed_pc=0x0c0974e2u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c0974e4;
P_0c0974e4: /* original 905c, guest PC 0x0c0974e4 */
if(!s->budget--) { s->failed_pc=0x0c0974e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0975a0u,2);
goto P_0c0974e6;
P_0c0974e6: /* original 0414, guest PC 0x0c0974e6 */
if(!s->budget--) { s->failed_pc=0x0c0974e6u; return 0; }
write(ram,r[4]+r[0],r[1],1);
goto P_0c0974e8;
P_0c0974e8: /* original 905b, guest PC 0x0c0974e8 */
if(!s->budget--) { s->failed_pc=0x0c0974e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0975a2u,2);
goto P_0c0974ea;
P_0c0974ea: /* original 04c4, guest PC 0x0c0974ea */
if(!s->budget--) { s->failed_pc=0x0c0974eau; return 0; }
write(ram,r[4]+r[0],r[12],1);
goto P_0c0974ec;
P_0c0974ec: /* original e01c, guest PC 0x0c0974ec */
if(!s->budget--) { s->failed_pc=0x0c0974ecu; return 0; }
r[0]=0x0000001cu;
goto P_0c0974ee;
P_0c0974ee: /* original 00dc, guest PC 0x0c0974ee */
if(!s->budget--) { s->failed_pc=0x0c0974eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0974f0;
P_0c0974f0: /* original d232, guest PC 0x0c0974f0 */
if(!s->budget--) { s->failed_pc=0x0c0974f0u; return 0; }
r[2]=read(ram,0x0c0975bcu,4);
goto P_0c0974f2;
P_0c0974f2: /* original 600c, guest PC 0x0c0974f2 */
if(!s->budget--) { s->failed_pc=0x0c0974f2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0974f4;
P_0c0974f4: /* original 9156, guest PC 0x0c0974f4 */
if(!s->budget--) { s->failed_pc=0x0c0974f4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0975a4u,2);
goto P_0c0974f6;
P_0c0974f6: /* original 2509, guest PC 0x0c0974f6 */
if(!s->budget--) { s->failed_pc=0x0c0974f6u; return 0; }
r[5]&=r[0];
goto P_0c0974f8;
P_0c0974f8: /* original 4508, guest PC 0x0c0974f8 */
if(!s->budget--) { s->failed_pc=0x0c0974f8u; return 0; }
r[5]<<=2;
goto P_0c0974fa;
P_0c0974fa: /* original 4508, guest PC 0x0c0974fa */
if(!s->budget--) { s->failed_pc=0x0c0974fau; return 0; }
r[5]<<=2;
goto P_0c0974fc;
P_0c0974fc: /* original 4508, guest PC 0x0c0974fc */
if(!s->budget--) { s->failed_pc=0x0c0974fcu; return 0; }
r[5]<<=2;
goto P_0c0974fe;
P_0c0974fe: /* original 352c, guest PC 0x0c0974fe */
if(!s->budget--) { s->failed_pc=0x0c0974feu; return 0; }
r[5]+=r[2];
goto P_0c097500;
P_0c097500: /* original 8455, guest PC 0x0c097500 */
if(!s->budget--) { s->failed_pc=0x0c097500u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+5,1);
goto P_0c097502;
P_0c097502: /* original 314c, guest PC 0x0c097502 */
if(!s->budget--) { s->failed_pc=0x0c097502u; return 0; }
r[1]+=r[4];
goto P_0c097504;
P_0c097504: /* original 2100, guest PC 0x0c097504 */
if(!s->budget--) { s->failed_pc=0x0c097504u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c097506;
P_0c097506: /* original 914e, guest PC 0x0c097506 */
if(!s->budget--) { s->failed_pc=0x0c097506u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0975a6u,2);
goto P_0c097508;
P_0c097508: /* original 8456, guest PC 0x0c097508 */
if(!s->budget--) { s->failed_pc=0x0c097508u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+6,1);
goto P_0c09750a;
P_0c09750a: /* original 314c, guest PC 0x0c09750a */
if(!s->budget--) { s->failed_pc=0x0c09750au; return 0; }
r[1]+=r[4];
goto P_0c09750c;
P_0c09750c: /* original 2100, guest PC 0x0c09750c */
if(!s->budget--) { s->failed_pc=0x0c09750cu; return 0; }
write(ram,r[1],r[0],1);
goto P_0c09750e;
P_0c09750e: /* original 914b, guest PC 0x0c09750e */
if(!s->budget--) { s->failed_pc=0x0c09750eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0975a8u,2);
goto P_0c097510;
P_0c097510: /* original 8457, guest PC 0x0c097510 */
if(!s->budget--) { s->failed_pc=0x0c097510u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+7,1);
goto P_0c097512;
P_0c097512: /* original 314c, guest PC 0x0c097512 */
if(!s->budget--) { s->failed_pc=0x0c097512u; return 0; }
r[1]+=r[4];
goto P_0c097514;
P_0c097514: /* original 2100, guest PC 0x0c097514 */
if(!s->budget--) { s->failed_pc=0x0c097514u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c097516;
P_0c097516: /* original e01c, guest PC 0x0c097516 */
if(!s->budget--) { s->failed_pc=0x0c097516u; return 0; }
r[0]=0x0000001cu;
goto P_0c097518;
P_0c097518: /* original f356, guest PC 0x0c097518 */
if(!s->budget--) { s->failed_pc=0x0c097518u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c09751a;
P_0c09751a: /* original 9046, guest PC 0x0c09751a */
if(!s->budget--) { s->failed_pc=0x0c09751au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0975aau,2);
goto P_0c09751c;
P_0c09751c: /* original f437, guest PC 0x0c09751c */
if(!s->budget--) { s->failed_pc=0x0c09751cu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c09751e;
P_0c09751e: /* original e020, guest PC 0x0c09751e */
if(!s->budget--) { s->failed_pc=0x0c09751eu; return 0; }
r[0]=0x00000020u;
goto P_0c097520;
P_0c097520: /* original f356, guest PC 0x0c097520 */
if(!s->budget--) { s->failed_pc=0x0c097520u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c097522;
P_0c097522: /* original 9043, guest PC 0x0c097522 */
if(!s->budget--) { s->failed_pc=0x0c097522u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0975acu,2);
goto P_0c097524;
P_0c097524: /* original f437, guest PC 0x0c097524 */
if(!s->budget--) { s->failed_pc=0x0c097524u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c097526;
P_0c097526: /* original e024, guest PC 0x0c097526 */
if(!s->budget--) { s->failed_pc=0x0c097526u; return 0; }
r[0]=0x00000024u;
goto P_0c097528;
P_0c097528: /* original f356, guest PC 0x0c097528 */
if(!s->budget--) { s->failed_pc=0x0c097528u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c09752a;
P_0c09752a: /* original 9040, guest PC 0x0c09752a */
if(!s->budget--) { s->failed_pc=0x0c09752au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0975aeu,2);
goto P_0c09752c;
P_0c09752c: /* original f437, guest PC 0x0c09752c */
if(!s->budget--) { s->failed_pc=0x0c09752cu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c09752e;
P_0c09752e: /* original 5be4, guest PC 0x0c09752e */
if(!s->budget--) { s->failed_pc=0x0c09752eu; return 0; }
r[11]=read(ram,r[14]+16,4);
goto P_0c097530;
P_0c097530: /* original d123, guest PC 0x0c097530 */
if(!s->budget--) { s->failed_pc=0x0c097530u; return 0; }
r[1]=read(ram,0x0c0975c0u,4);
goto P_0c097532;
P_0c097532: /* original 410b, guest PC 0x0c097532 */
if(!s->budget--) { s->failed_pc=0x0c097532u; return 0; }
target=r[1];
r[16]=code_base|0x0c097536u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097536u) { target=s->pc; goto dispatch; }
goto P_0c097536;
P_0c097534: /* original 64b3, guest PC 0x0c097534 */
if(!s->budget--) { s->failed_pc=0x0c097534u; return 0; }
r[4]=r[11];
goto P_0c097536;
P_0c097536: /* original 903b, guest PC 0x0c097536 */
if(!s->budget--) { s->failed_pc=0x0c097536u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0975b0u,2);
goto P_0c097538;
P_0c097538: /* original 63c3, guest PC 0x0c097538 */
if(!s->budget--) { s->failed_pc=0x0c097538u; return 0; }
r[3]=r[12];
goto P_0c09753a;
P_0c09753a: /* original 0bc6, guest PC 0x0c09753a */
if(!s->budget--) { s->failed_pc=0x0c09753au; return 0; }
write(ram,r[11]+r[0],r[12],4);
goto P_0c09753c;
P_0c09753c: /* original d321, guest PC 0x0c09753c */
if(!s->budget--) { s->failed_pc=0x0c09753cu; return 0; }
r[3]=read(ram,0x0c0975c4u,4);
goto P_0c09753e;
P_0c09753e: /* original 62b2, guest PC 0x0c09753e */
if(!s->budget--) { s->failed_pc=0x0c09753eu; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c097540;
P_0c097540: /* original 2239, guest PC 0x0c097540 */
if(!s->budget--) { s->failed_pc=0x0c097540u; return 0; }
r[2]&=r[3];
goto P_0c097542;
P_0c097542: /* original 2b22, guest PC 0x0c097542 */
if(!s->budget--) { s->failed_pc=0x0c097542u; return 0; }
write(ram,r[11],r[2],4);
goto P_0c097544;
P_0c097544: /* original d11e, guest PC 0x0c097544 */
if(!s->budget--) { s->failed_pc=0x0c097544u; return 0; }
r[1]=read(ram,0x0c0975c0u,4);
goto P_0c097546;
P_0c097546: /* original 5be5, guest PC 0x0c097546 */
if(!s->budget--) { s->failed_pc=0x0c097546u; return 0; }
r[11]=read(ram,r[14]+20,4);
goto P_0c097548;
P_0c097548: /* original 410b, guest PC 0x0c097548 */
if(!s->budget--) { s->failed_pc=0x0c097548u; return 0; }
target=r[1];
r[16]=code_base|0x0c09754cu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09754cu) { target=s->pc; goto dispatch; }
goto P_0c09754c;
P_0c09754a: /* original 64b3, guest PC 0x0c09754a */
if(!s->budget--) { s->failed_pc=0x0c09754au; return 0; }
r[4]=r[11];
goto P_0c09754c;
P_0c09754c: /* original 9030, guest PC 0x0c09754c */
if(!s->budget--) { s->failed_pc=0x0c09754cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0975b0u,2);
goto P_0c09754e;
P_0c09754e: /* original e140, guest PC 0x0c09754e */
if(!s->budget--) { s->failed_pc=0x0c09754eu; return 0; }
r[1]=0x00000040u;
goto P_0c097550;
P_0c097550: /* original 66c3, guest PC 0x0c097550 */
if(!s->budget--) { s->failed_pc=0x0c097550u; return 0; }
r[6]=r[12];
goto P_0c097552;
P_0c097552: /* original 65c3, guest PC 0x0c097552 */
if(!s->budget--) { s->failed_pc=0x0c097552u; return 0; }
r[5]=r[12];
goto P_0c097554;
P_0c097554: /* original 0bc6, guest PC 0x0c097554 */
if(!s->budget--) { s->failed_pc=0x0c097554u; return 0; }
write(ram,r[11]+r[0],r[12],4);
goto P_0c097556;
P_0c097556: /* original 60c3, guest PC 0x0c097556 */
if(!s->budget--) { s->failed_pc=0x0c097556u; return 0; }
r[0]=r[12];
goto P_0c097558;
P_0c097558: /* original 62b2, guest PC 0x0c097558 */
if(!s->budget--) { s->failed_pc=0x0c097558u; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c09755a;
P_0c09755a: /* original 63c3, guest PC 0x0c09755a */
if(!s->budget--) { s->failed_pc=0x0c09755au; return 0; }
r[3]=r[12];
goto P_0c09755c;
P_0c09755c: /* original d319, guest PC 0x0c09755c */
if(!s->budget--) { s->failed_pc=0x0c09755cu; return 0; }
r[3]=read(ram,0x0c0975c4u,4);
goto P_0c09755e;
P_0c09755e: /* original 2239, guest PC 0x0c09755e */
if(!s->budget--) { s->failed_pc=0x0c09755eu; return 0; }
r[2]&=r[3];
goto P_0c097560;
P_0c097560: /* original 2b22, guest PC 0x0c097560 */
if(!s->budget--) { s->failed_pc=0x0c097560u; return 0; }
write(ram,r[11],r[2],4);
goto P_0c097562;
P_0c097562: /* original 1d13, guest PC 0x0c097562 */
if(!s->budget--) { s->failed_pc=0x0c097562u; return 0; }
write(ram,r[13]+12,r[1],4);
goto P_0c097564;
P_0c097564: /* original 80db, guest PC 0x0c097564 */
if(!s->budget--) { s->failed_pc=0x0c097564u; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c097566;
P_0c097566: /* original 84da, guest PC 0x0c097566 */
if(!s->budget--) { s->failed_pc=0x0c097566u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+10,1);
goto P_0c097568;
P_0c097568: /* original 7001, guest PC 0x0c097568 */
if(!s->budget--) { s->failed_pc=0x0c097568u; return 0; }
r[0]+=0x00000001u;
goto P_0c09756a;
P_0c09756a: /* original 80da, guest PC 0x0c09756a */
if(!s->budget--) { s->failed_pc=0x0c09756au; return 0; }
write(ram,r[13]+10,r[0],1);
goto P_0c09756c;
P_0c09756c: /* original d216, guest PC 0x0c09756c */
if(!s->budget--) { s->failed_pc=0x0c09756cu; return 0; }
r[2]=read(ram,0x0c0975c8u,4);
goto P_0c09756e;
P_0c09756e: /* original 420b, guest PC 0x0c09756e */
if(!s->budget--) { s->failed_pc=0x0c09756eu; return 0; }
target=r[2];
r[16]=code_base|0x0c097572u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097572u) { target=s->pc; goto dispatch; }
goto P_0c097572;
P_0c097570: /* original 64c3, guest PC 0x0c097570 */
if(!s->budget--) { s->failed_pc=0x0c097570u; return 0; }
r[4]=r[12];
goto P_0c097572;
P_0c097572: /* original d316, guest PC 0x0c097572 */
if(!s->budget--) { s->failed_pc=0x0c097572u; return 0; }
r[3]=read(ram,0x0c0975ccu,4);
goto P_0c097574;
P_0c097574: /* original 430b, guest PC 0x0c097574 */
if(!s->budget--) { s->failed_pc=0x0c097574u; return 0; }
target=r[3];
r[16]=code_base|0x0c097578u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097578u) { target=s->pc; goto dispatch; }
goto P_0c097578;
P_0c097576: /* original e401, guest PC 0x0c097576 */
if(!s->budget--) { s->failed_pc=0x0c097576u; return 0; }
r[4]=0x00000001u;
goto P_0c097578;
P_0c097578: /* original d515, guest PC 0x0c097578 */
if(!s->budget--) { s->failed_pc=0x0c097578u; return 0; }
r[5]=read(ram,0x0c0975d0u,4);
goto P_0c09757a;
P_0c09757a: /* original e060, guest PC 0x0c09757a */
if(!s->budget--) { s->failed_pc=0x0c09757au; return 0; }
r[0]=0x00000060u;
goto P_0c09757c;
P_0c09757c: /* original b9c5, guest PC 0x0c09757c */
if(!s->budget--) { s->failed_pc=0x0c09757cu; return 0; }
target=code_base|0x0c09690au; r[16]=code_base|0x0c097580u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097580u) { target=s->pc; goto dispatch; }
goto P_0c097580;
P_0c09757e: /* original 04ee, guest PC 0x0c09757e */
if(!s->budget--) { s->failed_pc=0x0c09757eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c097580;
P_0c097580: /* original d513, guest PC 0x0c097580 */
if(!s->budget--) { s->failed_pc=0x0c097580u; return 0; }
r[5]=read(ram,0x0c0975d0u,4);
goto P_0c097582;
P_0c097582: /* original e064, guest PC 0x0c097582 */
if(!s->budget--) { s->failed_pc=0x0c097582u; return 0; }
r[0]=0x00000064u;
goto P_0c097584;
P_0c097584: /* original b9c1, guest PC 0x0c097584 */
if(!s->budget--) { s->failed_pc=0x0c097584u; return 0; }
target=code_base|0x0c09690au; r[16]=code_base|0x0c097588u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097588u) { target=s->pc; goto dispatch; }
goto P_0c097588;
P_0c097586: /* original 04ee, guest PC 0x0c097586 */
if(!s->budget--) { s->failed_pc=0x0c097586u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c097588;
P_0c097588: /* original 7f0c, guest PC 0x0c097588 */
if(!s->budget--) { s->failed_pc=0x0c097588u; return 0; }
r[15]+=0x0000000cu;
goto P_0c09758a;
P_0c09758a: /* original 4f26, guest PC 0x0c09758a */
if(!s->budget--) { s->failed_pc=0x0c09758au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09758c;
P_0c09758c: /* original fff9, guest PC 0x0c09758c */
if(!s->budget--) { s->failed_pc=0x0c09758cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09758e;
P_0c09758e: /* original 69f6, guest PC 0x0c09758e */
if(!s->budget--) { s->failed_pc=0x0c09758eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c097590;
P_0c097590: /* original 6af6, guest PC 0x0c097590 */
if(!s->budget--) { s->failed_pc=0x0c097590u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c097592;
P_0c097592: /* original 6bf6, guest PC 0x0c097592 */
if(!s->budget--) { s->failed_pc=0x0c097592u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c097594;
P_0c097594: /* original 6cf6, guest PC 0x0c097594 */
if(!s->budget--) { s->failed_pc=0x0c097594u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c097596;
P_0c097596: /* original 6df6, guest PC 0x0c097596 */
if(!s->budget--) { s->failed_pc=0x0c097596u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c097598;
P_0c097598: /* original a01c, guest PC 0x0c097598 */
if(!s->budget--) { s->failed_pc=0x0c097598u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0975d4;
P_0c09759a: /* original 6ef6, guest PC 0x0c09759a */
if(!s->budget--) { s->failed_pc=0x0c09759au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09759cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09759cu; return 0; } return 1;
P_0c0975d4: /* original 2fe6, guest PC 0x0c0975d4 */
if(!s->budget--) { s->failed_pc=0x0c0975d4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0975d6;
P_0c0975d6: /* original e33e, guest PC 0x0c0975d6 */
if(!s->budget--) { s->failed_pc=0x0c0975d6u; return 0; }
r[3]=0x0000003eu;
goto P_0c0975d8;
P_0c0975d8: /* original 2fd6, guest PC 0x0c0975d8 */
if(!s->budget--) { s->failed_pc=0x0c0975d8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0975da;
P_0c0975da: /* original de22, guest PC 0x0c0975da */
if(!s->budget--) { s->failed_pc=0x0c0975dau; return 0; }
r[14]=read(ram,0x0c097664u,4);
goto P_0c0975dc;
P_0c0975dc: /* original 4f22, guest PC 0x0c0975dc */
if(!s->budget--) { s->failed_pc=0x0c0975dcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0975de;
P_0c0975de: /* original 54e3, guest PC 0x0c0975de */
if(!s->budget--) { s->failed_pc=0x0c0975deu; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c0975e0;
P_0c0975e0: /* original dd21, guest PC 0x0c0975e0 */
if(!s->budget--) { s->failed_pc=0x0c0975e0u; return 0; }
r[13]=read(ram,0x0c097668u,4);
goto P_0c0975e2;
P_0c0975e2: /* original 3437, guest PC 0x0c0975e2 */
if(!s->budget--) { s->failed_pc=0x0c0975e2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c0975e4;
P_0c0975e4: /* original 7ffc, guest PC 0x0c0975e4 */
if(!s->budget--) { s->failed_pc=0x0c0975e4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0975e6;
P_0c0975e6: /* original 890f, guest PC 0x0c0975e6 */
if(!s->budget--) { s->failed_pc=0x0c0975e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097608; }
goto P_0c0975e8;
P_0c0975e8: /* original d320, guest PC 0x0c0975e8 */
if(!s->budget--) { s->failed_pc=0x0c0975e8u; return 0; }
r[3]=read(ram,0x0c09766cu,4);
goto P_0c0975ea;
P_0c0975ea: /* original 6043, guest PC 0x0c0975ea */
if(!s->budget--) { s->failed_pc=0x0c0975eau; return 0; }
r[0]=r[4];
goto P_0c0975ec;
P_0c0975ec: /* original d620, guest PC 0x0c0975ec */
if(!s->budget--) { s->failed_pc=0x0c0975ecu; return 0; }
r[6]=read(ram,0x0c097670u,4);
goto P_0c0975ee;
P_0c0975ee: /* original 883e, guest PC 0x0c0975ee */
if(!s->budget--) { s->failed_pc=0x0c0975eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000003eu)!=0);
goto P_0c0975f0;
P_0c0975f0: /* original d220, guest PC 0x0c0975f0 */
if(!s->budget--) { s->failed_pc=0x0c0975f0u; return 0; }
r[2]=read(ram,0x0c097674u,4);
goto P_0c0975f2;
P_0c0975f2: /* original 55d2, guest PC 0x0c0975f2 */
if(!s->budget--) { s->failed_pc=0x0c0975f2u; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0975f4;
P_0c0975f4: /* original 420b, guest PC 0x0c0975f4 */
if(!s->budget--) { s->failed_pc=0x0c0975f4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0975f8u;
tmp=read(ram,r[3],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0975f8u) { target=s->pc; goto dispatch; }
goto P_0c0975f8;
P_0c0975f6: /* original 6432, guest PC 0x0c0975f6 */
if(!s->budget--) { s->failed_pc=0x0c0975f6u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0975f8;
P_0c0975f8: /* original d620, guest PC 0x0c0975f8 */
if(!s->budget--) { s->failed_pc=0x0c0975f8u; return 0; }
r[6]=read(ram,0x0c09767cu,4);
goto P_0c0975fa;
P_0c0975fa: /* original 6503, guest PC 0x0c0975fa */
if(!s->budget--) { s->failed_pc=0x0c0975fau; return 0; }
r[5]=r[0];
goto P_0c0975fc;
P_0c0975fc: /* original d21d, guest PC 0x0c0975fc */
if(!s->budget--) { s->failed_pc=0x0c0975fcu; return 0; }
r[2]=read(ram,0x0c097674u,4);
goto P_0c0975fe;
P_0c0975fe: /* original d31e, guest PC 0x0c0975fe */
if(!s->budget--) { s->failed_pc=0x0c0975feu; return 0; }
r[3]=read(ram,0x0c097678u,4);
goto P_0c097600;
P_0c097600: /* original 420b, guest PC 0x0c097600 */
if(!s->budget--) { s->failed_pc=0x0c097600u; return 0; }
target=r[2];
r[16]=code_base|0x0c097604u;
tmp=read(ram,r[3],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097604u) { target=s->pc; goto dispatch; }
goto P_0c097604;
P_0c097602: /* original 6432, guest PC 0x0c097602 */
if(!s->budget--) { s->failed_pc=0x0c097602u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c097604;
P_0c097604: /* original 1d02, guest PC 0x0c097604 */
if(!s->budget--) { s->failed_pc=0x0c097604u; return 0; }
write(ram,r[13]+8,r[0],4);
goto P_0c097606;
P_0c097606: /* original 6403, guest PC 0x0c097606 */
if(!s->budget--) { s->failed_pc=0x0c097606u; return 0; }
r[4]=r[0];
goto P_0c097608;
P_0c097608: /* original 84eb, guest PC 0x0c097608 */
if(!s->budget--) { s->failed_pc=0x0c097608u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c09760a;
P_0c09760a: /* original 640c, guest PC 0x0c09760a */
if(!s->budget--) { s->failed_pc=0x0c09760au; return 0; }
r[4]=r[0]&255u;
goto P_0c09760c;
P_0c09760c: /* original 6043, guest PC 0x0c09760c */
if(!s->budget--) { s->failed_pc=0x0c09760cu; return 0; }
r[0]=r[4];
goto P_0c09760e;
P_0c09760e: /* original 80e9, guest PC 0x0c09760e */
if(!s->budget--) { s->failed_pc=0x0c09760eu; return 0; }
write(ram,r[14]+9,r[0],1);
goto P_0c097610;
P_0c097610: /* original d21b, guest PC 0x0c097610 */
if(!s->budget--) { s->failed_pc=0x0c097610u; return 0; }
r[2]=read(ram,0x0c097680u,4);
goto P_0c097612;
P_0c097612: /* original 634b, guest PC 0x0c097612 */
if(!s->budget--) { s->failed_pc=0x0c097612u; return 0; }
r[3]=0u-r[4];
goto P_0c097614;
P_0c097614: /* original 4408, guest PC 0x0c097614 */
if(!s->budget--) { s->failed_pc=0x0c097614u; return 0; }
r[4]<<=2;
goto P_0c097616;
P_0c097616: /* original 423d, guest PC 0x0c097616 */
if(!s->budget--) { s->failed_pc=0x0c097616u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c097618;
P_0c097618: /* original 1e21, guest PC 0x0c097618 */
if(!s->budget--) { s->failed_pc=0x0c097618u; return 0; }
write(ram,r[14]+4,r[2],4);
goto P_0c09761a;
P_0c09761a: /* original d01a, guest PC 0x0c09761a */
if(!s->budget--) { s->failed_pc=0x0c09761au; return 0; }
r[0]=read(ram,0x0c097684u,4);
goto P_0c09761c;
P_0c09761c: /* original 034e, guest PC 0x0c09761c */
if(!s->budget--) { s->failed_pc=0x0c09761cu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c09761e;
P_0c09761e: /* original 2f32, guest PC 0x0c09761e */
if(!s->budget--) { s->failed_pc=0x0c09761eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c097620;
P_0c097620: /* original 7f04, guest PC 0x0c097620 */
if(!s->budget--) { s->failed_pc=0x0c097620u; return 0; }
r[15]+=0x00000004u;
goto P_0c097622;
P_0c097622: /* original 4f26, guest PC 0x0c097622 */
if(!s->budget--) { s->failed_pc=0x0c097622u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c097624;
P_0c097624: /* original 6233, guest PC 0x0c097624 */
if(!s->budget--) { s->failed_pc=0x0c097624u; return 0; }
r[2]=r[3];
goto P_0c097626;
P_0c097626: /* original 6df6, guest PC 0x0c097626 */
if(!s->budget--) { s->failed_pc=0x0c097626u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c097628;
P_0c097628: /* original 422b, guest PC 0x0c097628 */
if(!s->budget--) { s->failed_pc=0x0c097628u; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c09762a: /* original 6ef6, guest PC 0x0c09762a */
if(!s->budget--) { s->failed_pc=0x0c09762au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09762cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09762cu; return 0; } return 1;
P_0c097694: /* original 2fe6, guest PC 0x0c097694 */
if(!s->budget--) { s->failed_pc=0x0c097694u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c097696;
P_0c097696: /* original ee02, guest PC 0x0c097696 */
if(!s->budget--) { s->failed_pc=0x0c097696u; return 0; }
r[14]=0x00000002u;
goto P_0c097698;
P_0c097698: /* original 2fd6, guest PC 0x0c097698 */
if(!s->budget--) { s->failed_pc=0x0c097698u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09769a;
P_0c09769a: /* original 2fc6, guest PC 0x0c09769a */
if(!s->budget--) { s->failed_pc=0x0c09769au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09769c;
P_0c09769c: /* original 2fb6, guest PC 0x0c09769c */
if(!s->budget--) { s->failed_pc=0x0c09769cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09769e;
P_0c09769e: /* original 2fa6, guest PC 0x0c09769e */
if(!s->budget--) { s->failed_pc=0x0c09769eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0976a0;
P_0c0976a0: /* original 2f96, guest PC 0x0c0976a0 */
if(!s->budget--) { s->failed_pc=0x0c0976a0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0976a2;
P_0c0976a2: /* original 2f86, guest PC 0x0c0976a2 */
if(!s->budget--) { s->failed_pc=0x0c0976a2u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0976a4;
P_0c0976a4: /* original dd2a, guest PC 0x0c0976a4 */
if(!s->budget--) { s->failed_pc=0x0c0976a4u; return 0; }
r[13]=read(ram,0x0c097750u,4);
goto P_0c0976a6;
P_0c0976a6: /* original 4f22, guest PC 0x0c0976a6 */
if(!s->budget--) { s->failed_pc=0x0c0976a6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0976a8;
P_0c0976a8: /* original 57da, guest PC 0x0c0976a8 */
if(!s->budget--) { s->failed_pc=0x0c0976a8u; return 0; }
r[7]=read(ram,r[13]+40,4);
goto P_0c0976aa;
P_0c0976aa: /* original 5adb, guest PC 0x0c0976aa */
if(!s->budget--) { s->failed_pc=0x0c0976aau; return 0; }
r[10]=read(ram,r[13]+44,4);
goto P_0c0976ac;
P_0c0976ac: /* original 6672, guest PC 0x0c0976ac */
if(!s->budget--) { s->failed_pc=0x0c0976acu; return 0; }
tmp=read(ram,r[7],4);
r[6]=tmp;
goto P_0c0976ae;
P_0c0976ae: /* original 7ffc, guest PC 0x0c0976ae */
if(!s->budget--) { s->failed_pc=0x0c0976aeu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0976b0;
P_0c0976b0: /* original 65a2, guest PC 0x0c0976b0 */
if(!s->budget--) { s->failed_pc=0x0c0976b0u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0976b2;
P_0c0976b2: /* original 6363, guest PC 0x0c0976b2 */
if(!s->budget--) { s->failed_pc=0x0c0976b2u; return 0; }
r[3]=r[6];
goto P_0c0976b4;
P_0c0976b4: /* original db23, guest PC 0x0c0976b4 */
if(!s->budget--) { s->failed_pc=0x0c0976b4u; return 0; }
r[11]=read(ram,0x0c097744u,4);
goto P_0c0976b6;
P_0c0976b6: /* original d424, guest PC 0x0c0976b6 */
if(!s->budget--) { s->failed_pc=0x0c0976b6u; return 0; }
r[4]=read(ram,0x0c097748u,4);
goto P_0c0976b8;
P_0c0976b8: /* original 23e8, guest PC 0x0c0976b8 */
if(!s->budget--) { s->failed_pc=0x0c0976b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c0976ba;
P_0c0976ba: /* original d824, guest PC 0x0c0976ba */
if(!s->budget--) { s->failed_pc=0x0c0976bau; return 0; }
r[8]=read(ram,0x0c09774cu,4);
goto P_0c0976bc;
P_0c0976bc: /* original 8f0c, guest PC 0x0c0976bc */
if(!s->budget--) { s->failed_pc=0x0c0976bcu; return 0; }
cond=r[17]&1u;
r[12]=0x00000004u;
if(!cond) { goto P_0c0976d8; }
goto P_0c0976c0;
P_0c0976be: /* original ec04, guest PC 0x0c0976be */
if(!s->budget--) { s->failed_pc=0x0c0976beu; return 0; }
r[12]=0x00000004u;
goto P_0c0976c0;
P_0c0976c0: /* original e208, guest PC 0x0c0976c0 */
if(!s->budget--) { s->failed_pc=0x0c0976c0u; return 0; }
r[2]=0x00000008u;
goto P_0c0976c2;
P_0c0976c2: /* original 2268, guest PC 0x0c0976c2 */
if(!s->budget--) { s->failed_pc=0x0c0976c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c0976c4;
P_0c0976c4: /* original 8908, guest PC 0x0c0976c4 */
if(!s->budget--) { s->failed_pc=0x0c0976c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0976d8; }
goto P_0c0976c6;
P_0c0976c6: /* original 6253, guest PC 0x0c0976c6 */
if(!s->budget--) { s->failed_pc=0x0c0976c6u; return 0; }
r[2]=r[5];
goto P_0c0976c8;
P_0c0976c8: /* original e3fb, guest PC 0x0c0976c8 */
if(!s->budget--) { s->failed_pc=0x0c0976c8u; return 0; }
r[3]=0xfffffffbu;
goto P_0c0976ca;
P_0c0976ca: /* original 26eb, guest PC 0x0c0976ca */
if(!s->budget--) { s->failed_pc=0x0c0976cau; return 0; }
r[6]|=r[14];
goto P_0c0976cc;
P_0c0976cc: /* original 22c8, guest PC 0x0c0976cc */
if(!s->budget--) { s->failed_pc=0x0c0976ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c0976ce;
P_0c0976ce: /* original 2639, guest PC 0x0c0976ce */
if(!s->budget--) { s->failed_pc=0x0c0976ceu; return 0; }
r[6]&=r[3];
goto P_0c0976d0;
P_0c0976d0: /* original 8f02, guest PC 0x0c0976d0 */
if(!s->budget--) { s->failed_pc=0x0c0976d0u; return 0; }
cond=r[17]&1u;
write(ram,r[7],r[6],4);
if(!cond) { goto P_0c0976d8; }
goto P_0c0976d4;
P_0c0976d2: /* original 2762, guest PC 0x0c0976d2 */
if(!s->budget--) { s->failed_pc=0x0c0976d2u; return 0; }
write(ram,r[7],r[6],4);
goto P_0c0976d4;
P_0c0976d4: /* original e33f, guest PC 0x0c0976d4 */
if(!s->budget--) { s->failed_pc=0x0c0976d4u; return 0; }
r[3]=0x0000003fu;
goto P_0c0976d6;
P_0c0976d6: /* original 143b, guest PC 0x0c0976d6 */
if(!s->budget--) { s->failed_pc=0x0c0976d6u; return 0; }
write(ram,r[4]+44,r[3],4);
goto P_0c0976d8;
P_0c0976d8: /* original 6253, guest PC 0x0c0976d8 */
if(!s->budget--) { s->failed_pc=0x0c0976d8u; return 0; }
r[2]=r[5];
goto P_0c0976da;
P_0c0976da: /* original 22e8, guest PC 0x0c0976da */
if(!s->budget--) { s->failed_pc=0x0c0976dau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[14])==0)!=0);
goto P_0c0976dc;
P_0c0976dc: /* original 6763, guest PC 0x0c0976dc */
if(!s->budget--) { s->failed_pc=0x0c0976dcu; return 0; }
r[7]=r[6];
goto P_0c0976de;
P_0c0976de: /* original 8f0b, guest PC 0x0c0976de */
if(!s->budget--) { s->failed_pc=0x0c0976deu; return 0; }
cond=r[17]&1u;
r[7]&=r[12];
if(!cond) { goto P_0c0976f8; }
goto P_0c0976e2;
P_0c0976e0: /* original 27c9, guest PC 0x0c0976e0 */
if(!s->budget--) { s->failed_pc=0x0c0976e0u; return 0; }
r[7]&=r[12];
goto P_0c0976e2;
P_0c0976e2: /* original e308, guest PC 0x0c0976e2 */
if(!s->budget--) { s->failed_pc=0x0c0976e2u; return 0; }
r[3]=0x00000008u;
goto P_0c0976e4;
P_0c0976e4: /* original 2358, guest PC 0x0c0976e4 */
if(!s->budget--) { s->failed_pc=0x0c0976e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0976e6;
P_0c0976e6: /* original 8907, guest PC 0x0c0976e6 */
if(!s->budget--) { s->failed_pc=0x0c0976e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0976f8; }
goto P_0c0976e8;
P_0c0976e8: /* original e3fb, guest PC 0x0c0976e8 */
if(!s->budget--) { s->failed_pc=0x0c0976e8u; return 0; }
r[3]=0xfffffffbu;
goto P_0c0976ea;
P_0c0976ea: /* original 25eb, guest PC 0x0c0976ea */
if(!s->budget--) { s->failed_pc=0x0c0976eau; return 0; }
r[5]|=r[14];
goto P_0c0976ec;
P_0c0976ec: /* original 2778, guest PC 0x0c0976ec */
if(!s->budget--) { s->failed_pc=0x0c0976ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0976ee;
P_0c0976ee: /* original 2539, guest PC 0x0c0976ee */
if(!s->budget--) { s->failed_pc=0x0c0976eeu; return 0; }
r[5]&=r[3];
goto P_0c0976f0;
P_0c0976f0: /* original 8f02, guest PC 0x0c0976f0 */
if(!s->budget--) { s->failed_pc=0x0c0976f0u; return 0; }
cond=r[17]&1u;
write(ram,r[10],r[5],4);
if(!cond) { goto P_0c0976f8; }
goto P_0c0976f4;
P_0c0976f2: /* original 2a52, guest PC 0x0c0976f2 */
if(!s->budget--) { s->failed_pc=0x0c0976f2u; return 0; }
write(ram,r[10],r[5],4);
goto P_0c0976f4;
P_0c0976f4: /* original e33f, guest PC 0x0c0976f4 */
if(!s->budget--) { s->failed_pc=0x0c0976f4u; return 0; }
r[3]=0x0000003fu;
goto P_0c0976f6;
P_0c0976f6: /* original 143b, guest PC 0x0c0976f6 */
if(!s->budget--) { s->failed_pc=0x0c0976f6u; return 0; }
write(ram,r[4]+44,r[3],4);
goto P_0c0976f8;
P_0c0976f8: /* original 5242, guest PC 0x0c0976f8 */
if(!s->budget--) { s->failed_pc=0x0c0976f8u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c0976fa;
P_0c0976fa: /* original 22c8, guest PC 0x0c0976fa */
if(!s->budget--) { s->failed_pc=0x0c0976fau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c0976fc;
P_0c0976fc: /* original 8941, guest PC 0x0c0976fc */
if(!s->budget--) { s->failed_pc=0x0c0976fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097782; }
goto P_0c0976fe;
P_0c0976fe: /* original 901d, guest PC 0x0c0976fe */
if(!s->budget--) { s->failed_pc=0x0c0976feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09773cu,2);
goto P_0c097700;
P_0c097700: /* original 01bc, guest PC 0x0c097700 */
if(!s->budget--) { s->failed_pc=0x0c097700u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c097702;
P_0c097702: /* original 2118, guest PC 0x0c097702 */
if(!s->budget--) { s->failed_pc=0x0c097702u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c097704;
P_0c097704: /* original 8b3d, guest PC 0x0c097704 */
if(!s->budget--) { s->failed_pc=0x0c097704u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c097782; }
goto P_0c097706;
P_0c097706: /* original 26e8, guest PC 0x0c097706 */
if(!s->budget--) { s->failed_pc=0x0c097706u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[14])==0)!=0);
goto P_0c097708;
P_0c097708: /* original 8b01, guest PC 0x0c097708 */
if(!s->budget--) { s->failed_pc=0x0c097708u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09770e; }
goto P_0c09770a;
P_0c09770a: /* original 2778, guest PC 0x0c09770a */
if(!s->budget--) { s->failed_pc=0x0c09770au; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c09770c;
P_0c09770c: /* original 8939, guest PC 0x0c09770c */
if(!s->budget--) { s->failed_pc=0x0c09770cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097782; }
goto P_0c09770e;
P_0c09770e: /* original 6253, guest PC 0x0c09770e */
if(!s->budget--) { s->failed_pc=0x0c09770eu; return 0; }
r[2]=r[5];
goto P_0c097710;
P_0c097710: /* original 22e8, guest PC 0x0c097710 */
if(!s->budget--) { s->failed_pc=0x0c097710u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[14])==0)!=0);
goto P_0c097712;
P_0c097712: /* original 8b01, guest PC 0x0c097712 */
if(!s->budget--) { s->failed_pc=0x0c097712u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c097718; }
goto P_0c097714;
P_0c097714: /* original 25c8, guest PC 0x0c097714 */
if(!s->budget--) { s->failed_pc=0x0c097714u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[12])==0)!=0);
goto P_0c097716;
P_0c097716: /* original 8934, guest PC 0x0c097716 */
if(!s->budget--) { s->failed_pc=0x0c097716u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097782; }
goto P_0c097718;
P_0c097718: /* original e02a, guest PC 0x0c097718 */
if(!s->budget--) { s->failed_pc=0x0c097718u; return 0; }
r[0]=0x0000002au;
goto P_0c09771a;
P_0c09771a: /* original 054c, guest PC 0x0c09771a */
if(!s->budget--) { s->failed_pc=0x0c09771au; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09771c;
P_0c09771c: /* original 655c, guest PC 0x0c09771c */
if(!s->budget--) { s->failed_pc=0x0c09771cu; return 0; }
r[5]=r[5]&255u;
goto P_0c09771e;
P_0c09771e: /* original 2558, guest PC 0x0c09771e */
if(!s->budget--) { s->failed_pc=0x0c09771eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c097720;
P_0c097720: /* original 892f, guest PC 0x0c097720 */
if(!s->budget--) { s->failed_pc=0x0c097720u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097782; }
goto P_0c097722;
P_0c097722: /* original 900c, guest PC 0x0c097722 */
if(!s->budget--) { s->failed_pc=0x0c097722u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09773eu,2);
goto P_0c097724;
P_0c097724: /* original 75ff, guest PC 0x0c097724 */
if(!s->budget--) { s->failed_pc=0x0c097724u; return 0; }
r[5]+=0xffffffffu;
goto P_0c097726;
P_0c097726: /* original 635b, guest PC 0x0c097726 */
if(!s->budget--) { s->failed_pc=0x0c097726u; return 0; }
r[3]=0u-r[5];
goto P_0c097728;
P_0c097728: /* original 06be, guest PC 0x0c097728 */
if(!s->budget--) { s->failed_pc=0x0c097728u; return 0; }
r[6]=read(ram,r[11]+r[0],4);
goto P_0c09772a;
P_0c09772a: /* original e210, guest PC 0x0c09772a */
if(!s->budget--) { s->failed_pc=0x0c09772au; return 0; }
r[2]=0x00000010u;
goto P_0c09772c;
P_0c09772c: /* original 463d, guest PC 0x0c09772c */
if(!s->budget--) { s->failed_pc=0x0c09772cu; return 0; }
r[6]=(r[3]&0x80000000u)?((r[3]&31u)?r[6]>>((-r[3])&31u):0):r[6]<<(r[3]&31u);
goto P_0c09772e;
P_0c09772e: /* original 2628, guest PC 0x0c09772e */
if(!s->budget--) { s->failed_pc=0x0c09772eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c097730;
P_0c097730: /* original 8927, guest PC 0x0c097730 */
if(!s->budget--) { s->failed_pc=0x0c097730u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097782; }
goto P_0c097732;
P_0c097732: /* original 2558, guest PC 0x0c097732 */
if(!s->budget--) { s->failed_pc=0x0c097732u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c097734;
P_0c097734: /* original 890e, guest PC 0x0c097734 */
if(!s->budget--) { s->failed_pc=0x0c097734u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097754; }
goto P_0c097736;
P_0c097736: /* original 9603, guest PC 0x0c097736 */
if(!s->budget--) { s->failed_pc=0x0c097736u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097740u,2);
goto P_0c097738;
P_0c097738: /* original a00d, guest PC 0x0c097738 */
if(!s->budget--) { s->failed_pc=0x0c097738u; return 0; }
goto P_0c097756;
P_0c09773a: /* original 0009, guest PC 0x0c09773a */
if(!s->budget--) { s->failed_pc=0x0c09773au; return 0; }
if(!vf3_matrix_family(0x0c09773cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09773cu; return 0; } return 1;
P_0c097754: /* original 9662, guest PC 0x0c097754 */
if(!s->budget--) { s->failed_pc=0x0c097754u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09781cu,2);
goto P_0c097756;
P_0c097756: /* original 9062, guest PC 0x0c097756 */
if(!s->budget--) { s->failed_pc=0x0c097756u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09781eu,2);
goto P_0c097758;
P_0c097758: /* original 364c, guest PC 0x0c097758 */
if(!s->budget--) { s->failed_pc=0x0c097758u; return 0; }
r[6]+=r[4];
goto P_0c09775a;
P_0c09775a: /* original 6360, guest PC 0x0c09775a */
if(!s->budget--) { s->failed_pc=0x0c09775au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[3]=tmp;
goto P_0c09775c;
P_0c09775c: /* original 074c, guest PC 0x0c09775c */
if(!s->budget--) { s->failed_pc=0x0c09775cu; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09775e;
P_0c09775e: /* original 2f30, guest PC 0x0c09775e */
if(!s->budget--) { s->failed_pc=0x0c09775eu; return 0; }
write(ram,r[15],r[3],1);
goto P_0c097760;
P_0c097760: /* original 6a73, guest PC 0x0c097760 */
if(!s->budget--) { s->failed_pc=0x0c097760u; return 0; }
r[10]=r[7];
goto P_0c097762;
P_0c097762: /* original 7aff, guest PC 0x0c097762 */
if(!s->budget--) { s->failed_pc=0x0c097762u; return 0; }
r[10]+=0xffffffffu;
goto P_0c097764;
P_0c097764: /* original 4a15, guest PC 0x0c097764 */
if(!s->budget--) { s->failed_pc=0x0c097764u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>0)!=0);
goto P_0c097766;
P_0c097766: /* original 8f08, guest PC 0x0c097766 */
if(!s->budget--) { s->failed_pc=0x0c097766u; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(!cond) { goto P_0c09777a; }
goto P_0c09776a;
P_0c097768: /* original e500, guest PC 0x0c097768 */
if(!s->budget--) { s->failed_pc=0x0c097768u; return 0; }
r[5]=0x00000000u;
goto P_0c09776a;
P_0c09776a: /* original 675e, guest PC 0x0c09776a */
if(!s->budget--) { s->failed_pc=0x0c09776au; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c09776c;
P_0c09776c: /* original 7501, guest PC 0x0c09776c */
if(!s->budget--) { s->failed_pc=0x0c09776cu; return 0; }
r[5]+=0x00000001u;
goto P_0c09776e;
P_0c09776e: /* original 376c, guest PC 0x0c09776e */
if(!s->budget--) { s->failed_pc=0x0c09776eu; return 0; }
r[7]+=r[6];
goto P_0c097770;
P_0c097770: /* original 635e, guest PC 0x0c097770 */
if(!s->budget--) { s->failed_pc=0x0c097770u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c097772;
P_0c097772: /* original 8471, guest PC 0x0c097772 */
if(!s->budget--) { s->failed_pc=0x0c097772u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+1,1);
goto P_0c097774;
P_0c097774: /* original 33a3, guest PC 0x0c097774 */
if(!s->budget--) { s->failed_pc=0x0c097774u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[10])!=0);
goto P_0c097776;
P_0c097776: /* original 8ff8, guest PC 0x0c097776 */
if(!s->budget--) { s->failed_pc=0x0c097776u; return 0; }
cond=r[17]&1u;
write(ram,r[7],r[0],1);
if(!cond) { goto P_0c09776a; }
goto P_0c09777a;
P_0c097778: /* original 2700, guest PC 0x0c097778 */
if(!s->budget--) { s->failed_pc=0x0c097778u; return 0; }
write(ram,r[7],r[0],1);
goto P_0c09777a;
P_0c09777a: /* original 63f0, guest PC 0x0c09777a */
if(!s->budget--) { s->failed_pc=0x0c09777au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[3]=tmp;
goto P_0c09777c;
P_0c09777c: /* original 655e, guest PC 0x0c09777c */
if(!s->budget--) { s->failed_pc=0x0c09777cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c09777e;
P_0c09777e: /* original 6053, guest PC 0x0c09777e */
if(!s->budget--) { s->failed_pc=0x0c09777eu; return 0; }
r[0]=r[5];
goto P_0c097780;
P_0c097780: /* original 0634, guest PC 0x0c097780 */
if(!s->budget--) { s->failed_pc=0x0c097780u; return 0; }
write(ram,r[6]+r[0],r[3],1);
goto P_0c097782;
P_0c097782: /* original 524b, guest PC 0x0c097782 */
if(!s->budget--) { s->failed_pc=0x0c097782u; return 0; }
r[2]=read(ram,r[4]+44,4);
goto P_0c097784;
P_0c097784: /* original 4215, guest PC 0x0c097784 */
if(!s->budget--) { s->failed_pc=0x0c097784u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c097786;
P_0c097786: /* original 893f, guest PC 0x0c097786 */
if(!s->budget--) { s->failed_pc=0x0c097786u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097808; }
goto P_0c097788;
P_0c097788: /* original d326, guest PC 0x0c097788 */
if(!s->budget--) { s->failed_pc=0x0c097788u; return 0; }
r[3]=read(ram,0x0c097824u,4);
goto P_0c09778a;
P_0c09778a: /* original 430b, guest PC 0x0c09778a */
if(!s->budget--) { s->failed_pc=0x0c09778au; return 0; }
target=r[3];
r[16]=code_base|0x0c09778eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09778eu) { target=s->pc; goto dispatch; }
goto P_0c09778e;
P_0c09778c: /* original 0009, guest PC 0x0c09778c */
if(!s->budget--) { s->failed_pc=0x0c09778cu; return 0; }
goto P_0c09778e;
P_0c09778e: /* original e060, guest PC 0x0c09778e */
if(!s->budget--) { s->failed_pc=0x0c09778eu; return 0; }
r[0]=0x00000060u;
goto P_0c097790;
P_0c097790: /* original b8b2, guest PC 0x0c097790 */
if(!s->budget--) { s->failed_pc=0x0c097790u; return 0; }
target=code_base|0x0c0968f8u; r[16]=code_base|0x0c097794u;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097794u) { target=s->pc; goto dispatch; }
goto P_0c097794;
P_0c097792: /* original 04de, guest PC 0x0c097792 */
if(!s->budget--) { s->failed_pc=0x0c097792u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c097794;
P_0c097794: /* original e064, guest PC 0x0c097794 */
if(!s->budget--) { s->failed_pc=0x0c097794u; return 0; }
r[0]=0x00000064u;
goto P_0c097796;
P_0c097796: /* original b8af, guest PC 0x0c097796 */
if(!s->budget--) { s->failed_pc=0x0c097796u; return 0; }
target=code_base|0x0c0968f8u; r[16]=code_base|0x0c09779au;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09779au) { target=s->pc; goto dispatch; }
goto P_0c09779a;
P_0c097798: /* original 04de, guest PC 0x0c097798 */
if(!s->budget--) { s->failed_pc=0x0c097798u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c09779a;
P_0c09779a: /* original d223, guest PC 0x0c09779a */
if(!s->budget--) { s->failed_pc=0x0c09779au; return 0; }
r[2]=read(ram,0x0c097828u,4);
goto P_0c09779c;
P_0c09779c: /* original 420b, guest PC 0x0c09779c */
if(!s->budget--) { s->failed_pc=0x0c09779cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0977a0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0977a0u) { target=s->pc; goto dispatch; }
goto P_0c0977a0;
P_0c09779e: /* original 0009, guest PC 0x0c09779e */
if(!s->budget--) { s->failed_pc=0x0c09779eu; return 0; }
goto P_0c0977a0;
P_0c0977a0: /* original d322, guest PC 0x0c0977a0 */
if(!s->budget--) { s->failed_pc=0x0c0977a0u; return 0; }
r[3]=read(ram,0x0c09782cu,4);
goto P_0c0977a2;
P_0c0977a2: /* original 430b, guest PC 0x0c0977a2 */
if(!s->budget--) { s->failed_pc=0x0c0977a2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0977a6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0977a6u) { target=s->pc; goto dispatch; }
goto P_0c0977a6;
P_0c0977a4: /* original 0009, guest PC 0x0c0977a4 */
if(!s->budget--) { s->failed_pc=0x0c0977a4u; return 0; }
goto P_0c0977a6;
P_0c0977a6: /* original d222, guest PC 0x0c0977a6 */
if(!s->budget--) { s->failed_pc=0x0c0977a6u; return 0; }
r[2]=read(ram,0x0c097830u,4);
goto P_0c0977a8;
P_0c0977a8: /* original 6483, guest PC 0x0c0977a8 */
if(!s->budget--) { s->failed_pc=0x0c0977a8u; return 0; }
r[4]=r[8];
goto P_0c0977aa;
P_0c0977aa: /* original 420b, guest PC 0x0c0977aa */
if(!s->budget--) { s->failed_pc=0x0c0977aau; return 0; }
target=r[2];
r[16]=code_base|0x0c0977aeu;
r[4]+=0x0000000fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0977aeu) { target=s->pc; goto dispatch; }
goto P_0c0977ae;
P_0c0977ac: /* original 740f, guest PC 0x0c0977ac */
if(!s->budget--) { s->failed_pc=0x0c0977acu; return 0; }
r[4]+=0x0000000fu;
goto P_0c0977ae;
P_0c0977ae: /* original 640c, guest PC 0x0c0977ae */
if(!s->budget--) { s->failed_pc=0x0c0977aeu; return 0; }
r[4]=r[0]&255u;
goto P_0c0977b0;
P_0c0977b0: /* original 2448, guest PC 0x0c0977b0 */
if(!s->budget--) { s->failed_pc=0x0c0977b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0977b2;
P_0c0977b2: /* original 8913, guest PC 0x0c0977b2 */
if(!s->budget--) { s->failed_pc=0x0c0977b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0977dc; }
goto P_0c0977b4;
P_0c0977b4: /* original d220, guest PC 0x0c0977b4 */
if(!s->budget--) { s->failed_pc=0x0c0977b4u; return 0; }
r[2]=read(ram,0x0c097838u,4);
goto P_0c0977b6;
P_0c0977b6: /* original d41f, guest PC 0x0c0977b6 */
if(!s->budget--) { s->failed_pc=0x0c0977b6u; return 0; }
r[4]=read(ram,0x0c097834u,4);
goto P_0c0977b8;
P_0c0977b8: /* original 420b, guest PC 0x0c0977b8 */
if(!s->budget--) { s->failed_pc=0x0c0977b8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0977bcu;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0977bcu) { target=s->pc; goto dispatch; }
goto P_0c0977bc;
P_0c0977ba: /* original e500, guest PC 0x0c0977ba */
if(!s->budget--) { s->failed_pc=0x0c0977bau; return 0; }
r[5]=0x00000000u;
goto P_0c0977bc;
P_0c0977bc: /* original d31f, guest PC 0x0c0977bc */
if(!s->budget--) { s->failed_pc=0x0c0977bcu; return 0; }
r[3]=read(ram,0x0c09783cu,4);
goto P_0c0977be;
P_0c0977be: /* original 430b, guest PC 0x0c0977be */
if(!s->budget--) { s->failed_pc=0x0c0977beu; return 0; }
target=r[3];
r[16]=code_base|0x0c0977c2u;
r[4]=0x0000001bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0977c2u) { target=s->pc; goto dispatch; }
goto P_0c0977c2;
P_0c0977c0: /* original e41b, guest PC 0x0c0977c0 */
if(!s->budget--) { s->failed_pc=0x0c0977c0u; return 0; }
r[4]=0x0000001bu;
goto P_0c0977c2;
P_0c0977c2: /* original da20, guest PC 0x0c0977c2 */
if(!s->budget--) { s->failed_pc=0x0c0977c2u; return 0; }
r[10]=read(ram,0x0c097844u,4);
goto P_0c0977c4;
P_0c0977c4: /* original d91e, guest PC 0x0c0977c4 */
if(!s->budget--) { s->failed_pc=0x0c0977c4u; return 0; }
r[9]=read(ram,0x0c097840u,4);
goto P_0c0977c6;
P_0c0977c6: /* original 4a0b, guest PC 0x0c0977c6 */
if(!s->budget--) { s->failed_pc=0x0c0977c6u; return 0; }
target=r[10];
r[16]=code_base|0x0c0977cau;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0977cau) { target=s->pc; goto dispatch; }
goto P_0c0977ca;
P_0c0977c8: /* original 6493, guest PC 0x0c0977c8 */
if(!s->budget--) { s->failed_pc=0x0c0977c8u; return 0; }
r[4]=r[9];
goto P_0c0977ca;
P_0c0977ca: /* original 6493, guest PC 0x0c0977ca */
if(!s->budget--) { s->failed_pc=0x0c0977cau; return 0; }
r[4]=r[9];
goto P_0c0977cc;
P_0c0977cc: /* original 4a0b, guest PC 0x0c0977cc */
if(!s->budget--) { s->failed_pc=0x0c0977ccu; return 0; }
target=r[10];
r[16]=code_base|0x0c0977d0u;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0977d0u) { target=s->pc; goto dispatch; }
goto P_0c0977d0;
P_0c0977ce: /* original 7458, guest PC 0x0c0977ce */
if(!s->budget--) { s->failed_pc=0x0c0977ceu; return 0; }
r[4]+=0x00000058u;
goto P_0c0977d0;
P_0c0977d0: /* original 6493, guest PC 0x0c0977d0 */
if(!s->budget--) { s->failed_pc=0x0c0977d0u; return 0; }
r[4]=r[9];
goto P_0c0977d2;
P_0c0977d2: /* original 4a0b, guest PC 0x0c0977d2 */
if(!s->budget--) { s->failed_pc=0x0c0977d2u; return 0; }
target=r[10];
r[16]=code_base|0x0c0977d6u;
r[4]+=0x0000002cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0977d6u) { target=s->pc; goto dispatch; }
goto P_0c0977d6;
P_0c0977d4: /* original 742c, guest PC 0x0c0977d4 */
if(!s->budget--) { s->failed_pc=0x0c0977d4u; return 0; }
r[4]+=0x0000002cu;
goto P_0c0977d6;
P_0c0977d6: /* original 9423, guest PC 0x0c0977d6 */
if(!s->budget--) { s->failed_pc=0x0c0977d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097820u,2);
goto P_0c0977d8;
P_0c0977d8: /* original 4a0b, guest PC 0x0c0977d8 */
if(!s->budget--) { s->failed_pc=0x0c0977d8u; return 0; }
target=r[10];
r[16]=code_base|0x0c0977dcu;
r[4]+=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0977dcu) { target=s->pc; goto dispatch; }
goto P_0c0977dc;
P_0c0977da: /* original 349c, guest PC 0x0c0977da */
if(!s->budget--) { s->failed_pc=0x0c0977dau; return 0; }
r[4]+=r[9];
goto P_0c0977dc;
P_0c0977dc: /* original 60c3, guest PC 0x0c0977dc */
if(!s->budget--) { s->failed_pc=0x0c0977dcu; return 0; }
r[0]=r[12];
goto P_0c0977de;
P_0c0977de: /* original 80bb, guest PC 0x0c0977de */
if(!s->budget--) { s->failed_pc=0x0c0977deu; return 0; }
write(ram,r[11]+11,r[0],1);
goto P_0c0977e0;
P_0c0977e0: /* original d319, guest PC 0x0c0977e0 */
if(!s->budget--) { s->failed_pc=0x0c0977e0u; return 0; }
r[3]=read(ram,0x0c097848u,4);
goto P_0c0977e2;
P_0c0977e2: /* original 430b, guest PC 0x0c0977e2 */
if(!s->budget--) { s->failed_pc=0x0c0977e2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0977e6u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0977e6u) { target=s->pc; goto dispatch; }
goto P_0c0977e6;
P_0c0977e4: /* original e400, guest PC 0x0c0977e4 */
if(!s->budget--) { s->failed_pc=0x0c0977e4u; return 0; }
r[4]=0x00000000u;
goto P_0c0977e6;
P_0c0977e6: /* original 55da, guest PC 0x0c0977e6 */
if(!s->budget--) { s->failed_pc=0x0c0977e6u; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0977e8;
P_0c0977e8: /* original 54db, guest PC 0x0c0977e8 */
if(!s->budget--) { s->failed_pc=0x0c0977e8u; return 0; }
r[4]=read(ram,r[13]+44,4);
goto P_0c0977ea;
P_0c0977ea: /* original 6552, guest PC 0x0c0977ea */
if(!s->budget--) { s->failed_pc=0x0c0977eau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0977ec;
P_0c0977ec: /* original 25e8, guest PC 0x0c0977ec */
if(!s->budget--) { s->failed_pc=0x0c0977ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[14])==0)!=0);
goto P_0c0977ee;
P_0c0977ee: /* original 8d0b, guest PC 0x0c0977ee */
if(!s->budget--) { s->failed_pc=0x0c0977eeu; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[4],4);
r[4]=tmp;
if(cond) { goto P_0c097808; }
goto P_0c0977f2;
P_0c0977f0: /* original 6442, guest PC 0x0c0977f0 */
if(!s->budget--) { s->failed_pc=0x0c0977f0u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0977f2;
P_0c0977f2: /* original 24e8, guest PC 0x0c0977f2 */
if(!s->budget--) { s->failed_pc=0x0c0977f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[14])==0)!=0);
goto P_0c0977f4;
P_0c0977f4: /* original 8908, guest PC 0x0c0977f4 */
if(!s->budget--) { s->failed_pc=0x0c0977f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097808; }
goto P_0c0977f6;
P_0c0977f6: /* original d20e, guest PC 0x0c0977f6 */
if(!s->budget--) { s->failed_pc=0x0c0977f6u; return 0; }
r[2]=read(ram,0x0c097830u,4);
goto P_0c0977f8;
P_0c0977f8: /* original 6483, guest PC 0x0c0977f8 */
if(!s->budget--) { s->failed_pc=0x0c0977f8u; return 0; }
r[4]=r[8];
goto P_0c0977fa;
P_0c0977fa: /* original 420b, guest PC 0x0c0977fa */
if(!s->budget--) { s->failed_pc=0x0c0977fau; return 0; }
target=r[2];
r[16]=code_base|0x0c0977feu;
r[4]+=0x0000000fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0977feu) { target=s->pc; goto dispatch; }
goto P_0c0977fe;
P_0c0977fc: /* original 740f, guest PC 0x0c0977fc */
if(!s->budget--) { s->failed_pc=0x0c0977fcu; return 0; }
r[4]+=0x0000000fu;
goto P_0c0977fe;
P_0c0977fe: /* original 640c, guest PC 0x0c0977fe */
if(!s->budget--) { s->failed_pc=0x0c0977feu; return 0; }
r[4]=r[0]&255u;
goto P_0c097800;
P_0c097800: /* original 2448, guest PC 0x0c097800 */
if(!s->budget--) { s->failed_pc=0x0c097800u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c097802;
P_0c097802: /* original 8b01, guest PC 0x0c097802 */
if(!s->budget--) { s->failed_pc=0x0c097802u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c097808; }
goto P_0c097804;
P_0c097804: /* original 60e3, guest PC 0x0c097804 */
if(!s->budget--) { s->failed_pc=0x0c097804u; return 0; }
r[0]=r[14];
goto P_0c097806;
P_0c097806: /* original 80bb, guest PC 0x0c097806 */
if(!s->budget--) { s->failed_pc=0x0c097806u; return 0; }
write(ram,r[11]+11,r[0],1);
goto P_0c097808;
P_0c097808: /* original 7f04, guest PC 0x0c097808 */
if(!s->budget--) { s->failed_pc=0x0c097808u; return 0; }
r[15]+=0x00000004u;
goto P_0c09780a;
P_0c09780a: /* original 4f26, guest PC 0x0c09780a */
if(!s->budget--) { s->failed_pc=0x0c09780au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09780c;
P_0c09780c: /* original 68f6, guest PC 0x0c09780c */
if(!s->budget--) { s->failed_pc=0x0c09780cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09780e;
P_0c09780e: /* original 69f6, guest PC 0x0c09780e */
if(!s->budget--) { s->failed_pc=0x0c09780eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c097810;
P_0c097810: /* original 6af6, guest PC 0x0c097810 */
if(!s->budget--) { s->failed_pc=0x0c097810u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c097812;
P_0c097812: /* original 6bf6, guest PC 0x0c097812 */
if(!s->budget--) { s->failed_pc=0x0c097812u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c097814;
P_0c097814: /* original 6cf6, guest PC 0x0c097814 */
if(!s->budget--) { s->failed_pc=0x0c097814u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c097816;
P_0c097816: /* original 6df6, guest PC 0x0c097816 */
if(!s->budget--) { s->failed_pc=0x0c097816u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c097818;
P_0c097818: /* original 000b, guest PC 0x0c097818 */
if(!s->budget--) { s->failed_pc=0x0c097818u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09781a: /* original 6ef6, guest PC 0x0c09781a */
if(!s->budget--) { s->failed_pc=0x0c09781au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09781cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09781cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
