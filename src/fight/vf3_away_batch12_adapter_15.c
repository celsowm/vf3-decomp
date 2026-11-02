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
int vf3_away_batch12_adapter_15(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c082110u: goto P_0c082110;
case 0x0c082112u: goto P_0c082112;
case 0x0c082114u: goto P_0c082114;
case 0x0c082116u: goto P_0c082116;
case 0x0c082118u: goto P_0c082118;
case 0x0c08211au: goto P_0c08211a;
case 0x0c08211cu: goto P_0c08211c;
case 0x0c08211eu: goto P_0c08211e;
case 0x0c082120u: goto P_0c082120;
case 0x0c082122u: goto P_0c082122;
case 0x0c082124u: goto P_0c082124;
case 0x0c082126u: goto P_0c082126;
case 0x0c082128u: goto P_0c082128;
case 0x0c08212au: goto P_0c08212a;
case 0x0c08212cu: goto P_0c08212c;
case 0x0c08212eu: goto P_0c08212e;
case 0x0c082130u: goto P_0c082130;
case 0x0c082132u: goto P_0c082132;
case 0x0c082134u: goto P_0c082134;
case 0x0c082136u: goto P_0c082136;
case 0x0c082138u: goto P_0c082138;
case 0x0c08213au: goto P_0c08213a;
case 0x0c08213cu: goto P_0c08213c;
case 0x0c08213eu: goto P_0c08213e;
case 0x0c082140u: goto P_0c082140;
case 0x0c082142u: goto P_0c082142;
case 0x0c082144u: goto P_0c082144;
case 0x0c082146u: goto P_0c082146;
case 0x0c082148u: goto P_0c082148;
case 0x0c08214au: goto P_0c08214a;
case 0x0c08214cu: goto P_0c08214c;
case 0x0c08214eu: goto P_0c08214e;
case 0x0c082150u: goto P_0c082150;
case 0x0c082152u: goto P_0c082152;
case 0x0c082154u: goto P_0c082154;
case 0x0c082156u: goto P_0c082156;
case 0x0c082158u: goto P_0c082158;
case 0x0c08215au: goto P_0c08215a;
case 0x0c08215cu: goto P_0c08215c;
case 0x0c08215eu: goto P_0c08215e;
case 0x0c082160u: goto P_0c082160;
case 0x0c082162u: goto P_0c082162;
case 0x0c082164u: goto P_0c082164;
case 0x0c082166u: goto P_0c082166;
case 0x0c082168u: goto P_0c082168;
case 0x0c08216au: goto P_0c08216a;
case 0x0c08216cu: goto P_0c08216c;
case 0x0c08216eu: goto P_0c08216e;
case 0x0c082170u: goto P_0c082170;
case 0x0c082172u: goto P_0c082172;
case 0x0c082174u: goto P_0c082174;
case 0x0c082176u: goto P_0c082176;
case 0x0c082178u: goto P_0c082178;
case 0x0c08217au: goto P_0c08217a;
case 0x0c08217cu: goto P_0c08217c;
case 0x0c08217eu: goto P_0c08217e;
case 0x0c082180u: goto P_0c082180;
case 0x0c082182u: goto P_0c082182;
case 0x0c082184u: goto P_0c082184;
case 0x0c082186u: goto P_0c082186;
case 0x0c082188u: goto P_0c082188;
case 0x0c08218au: goto P_0c08218a;
case 0x0c08218cu: goto P_0c08218c;
case 0x0c08218eu: goto P_0c08218e;
case 0x0c082190u: goto P_0c082190;
case 0x0c082192u: goto P_0c082192;
case 0x0c082194u: goto P_0c082194;
case 0x0c082196u: goto P_0c082196;
case 0x0c082198u: goto P_0c082198;
case 0x0c08219au: goto P_0c08219a;
case 0x0c08219cu: goto P_0c08219c;
case 0x0c08219eu: goto P_0c08219e;
case 0x0c0821a0u: goto P_0c0821a0;
case 0x0c0821a2u: goto P_0c0821a2;
case 0x0c0821a4u: goto P_0c0821a4;
case 0x0c0821a6u: goto P_0c0821a6;
case 0x0c0821a8u: goto P_0c0821a8;
case 0x0c0821aau: goto P_0c0821aa;
case 0x0c0821acu: goto P_0c0821ac;
case 0x0c0821aeu: goto P_0c0821ae;
case 0x0c0821b0u: goto P_0c0821b0;
case 0x0c0821b2u: goto P_0c0821b2;
case 0x0c0821b4u: goto P_0c0821b4;
case 0x0c0821b6u: goto P_0c0821b6;
case 0x0c0821b8u: goto P_0c0821b8;
case 0x0c0821bau: goto P_0c0821ba;
case 0x0c0821bcu: goto P_0c0821bc;
case 0x0c0821beu: goto P_0c0821be;
case 0x0c0821c0u: goto P_0c0821c0;
case 0x0c0821c2u: goto P_0c0821c2;
case 0x0c0821c4u: goto P_0c0821c4;
case 0x0c0821c6u: goto P_0c0821c6;
case 0x0c0821c8u: goto P_0c0821c8;
case 0x0c0821cau: goto P_0c0821ca;
case 0x0c0821ccu: goto P_0c0821cc;
case 0x0c0821ceu: goto P_0c0821ce;
case 0x0c0821d0u: goto P_0c0821d0;
case 0x0c0821d2u: goto P_0c0821d2;
case 0x0c0821d4u: goto P_0c0821d4;
case 0x0c0821d6u: goto P_0c0821d6;
case 0x0c0821d8u: goto P_0c0821d8;
case 0x0c0821dau: goto P_0c0821da;
case 0x0c0821dcu: goto P_0c0821dc;
case 0x0c0821deu: goto P_0c0821de;
case 0x0c0821e0u: goto P_0c0821e0;
case 0x0c0821e2u: goto P_0c0821e2;
case 0x0c0821e4u: goto P_0c0821e4;
case 0x0c0821e6u: goto P_0c0821e6;
case 0x0c0821e8u: goto P_0c0821e8;
case 0x0c0821eau: goto P_0c0821ea;
case 0x0c0821ecu: goto P_0c0821ec;
case 0x0c0821eeu: goto P_0c0821ee;
case 0x0c0821f0u: goto P_0c0821f0;
case 0x0c0821f2u: goto P_0c0821f2;
case 0x0c0821f4u: goto P_0c0821f4;
case 0x0c0821f6u: goto P_0c0821f6;
case 0x0c0821f8u: goto P_0c0821f8;
case 0x0c0821fau: goto P_0c0821fa;
case 0x0c0821fcu: goto P_0c0821fc;
case 0x0c0821feu: goto P_0c0821fe;
case 0x0c082200u: goto P_0c082200;
case 0x0c082202u: goto P_0c082202;
case 0x0c082204u: goto P_0c082204;
case 0x0c082206u: goto P_0c082206;
case 0x0c082208u: goto P_0c082208;
case 0x0c08220au: goto P_0c08220a;
case 0x0c08220cu: goto P_0c08220c;
case 0x0c08220eu: goto P_0c08220e;
case 0x0c082210u: goto P_0c082210;
case 0x0c082212u: goto P_0c082212;
case 0x0c082214u: goto P_0c082214;
case 0x0c082216u: goto P_0c082216;
case 0x0c082218u: goto P_0c082218;
case 0x0c082258u: goto P_0c082258;
case 0x0c08225au: goto P_0c08225a;
case 0x0c08225cu: goto P_0c08225c;
case 0x0c08225eu: goto P_0c08225e;
case 0x0c082260u: goto P_0c082260;
case 0x0c082262u: goto P_0c082262;
case 0x0c082264u: goto P_0c082264;
case 0x0c082266u: goto P_0c082266;
case 0x0c082268u: goto P_0c082268;
case 0x0c08226au: goto P_0c08226a;
case 0x0c08226cu: goto P_0c08226c;
case 0x0c08226eu: goto P_0c08226e;
case 0x0c082270u: goto P_0c082270;
case 0x0c082272u: goto P_0c082272;
case 0x0c082274u: goto P_0c082274;
case 0x0c082276u: goto P_0c082276;
case 0x0c082278u: goto P_0c082278;
case 0x0c08227au: goto P_0c08227a;
case 0x0c08227cu: goto P_0c08227c;
case 0x0c08227eu: goto P_0c08227e;
case 0x0c082280u: goto P_0c082280;
case 0x0c082282u: goto P_0c082282;
case 0x0c082284u: goto P_0c082284;
case 0x0c082286u: goto P_0c082286;
case 0x0c082288u: goto P_0c082288;
case 0x0c08228au: goto P_0c08228a;
case 0x0c08228cu: goto P_0c08228c;
case 0x0c08228eu: goto P_0c08228e;
case 0x0c082290u: goto P_0c082290;
case 0x0c082292u: goto P_0c082292;
case 0x0c082294u: goto P_0c082294;
case 0x0c082296u: goto P_0c082296;
case 0x0c082298u: goto P_0c082298;
case 0x0c08229au: goto P_0c08229a;
case 0x0c08229cu: goto P_0c08229c;
case 0x0c08229eu: goto P_0c08229e;
case 0x0c0822a0u: goto P_0c0822a0;
case 0x0c0822a2u: goto P_0c0822a2;
case 0x0c0822a4u: goto P_0c0822a4;
case 0x0c0822a6u: goto P_0c0822a6;
case 0x0c0822a8u: goto P_0c0822a8;
case 0x0c0822aau: goto P_0c0822aa;
case 0x0c0822acu: goto P_0c0822ac;
case 0x0c0822aeu: goto P_0c0822ae;
case 0x0c0822b0u: goto P_0c0822b0;
case 0x0c0822b2u: goto P_0c0822b2;
case 0x0c0822b4u: goto P_0c0822b4;
case 0x0c0822b6u: goto P_0c0822b6;
case 0x0c0822b8u: goto P_0c0822b8;
case 0x0c0822bau: goto P_0c0822ba;
case 0x0c0822bcu: goto P_0c0822bc;
case 0x0c0822beu: goto P_0c0822be;
case 0x0c0822c0u: goto P_0c0822c0;
case 0x0c0822c2u: goto P_0c0822c2;
case 0x0c0822c4u: goto P_0c0822c4;
case 0x0c0822c6u: goto P_0c0822c6;
case 0x0c0822c8u: goto P_0c0822c8;
case 0x0c0822cau: goto P_0c0822ca;
case 0x0c0822ccu: goto P_0c0822cc;
case 0x0c0822ceu: goto P_0c0822ce;
case 0x0c0822d0u: goto P_0c0822d0;
case 0x0c0822d2u: goto P_0c0822d2;
case 0x0c0822d4u: goto P_0c0822d4;
case 0x0c0822d6u: goto P_0c0822d6;
case 0x0c0822d8u: goto P_0c0822d8;
case 0x0c0822dau: goto P_0c0822da;
case 0x0c0822dcu: goto P_0c0822dc;
case 0x0c0822deu: goto P_0c0822de;
case 0x0c0822e0u: goto P_0c0822e0;
case 0x0c0822e2u: goto P_0c0822e2;
case 0x0c0822e4u: goto P_0c0822e4;
case 0x0c0822e6u: goto P_0c0822e6;
case 0x0c0822e8u: goto P_0c0822e8;
case 0x0c0822eau: goto P_0c0822ea;
case 0x0c0822ecu: goto P_0c0822ec;
case 0x0c08230cu: goto P_0c08230c;
case 0x0c08230eu: goto P_0c08230e;
case 0x0c082310u: goto P_0c082310;
case 0x0c082312u: goto P_0c082312;
case 0x0c082314u: goto P_0c082314;
case 0x0c082316u: goto P_0c082316;
case 0x0c082318u: goto P_0c082318;
case 0x0c08231au: goto P_0c08231a;
case 0x0c08231cu: goto P_0c08231c;
case 0x0c08231eu: goto P_0c08231e;
case 0x0c082320u: goto P_0c082320;
case 0x0c082322u: goto P_0c082322;
case 0x0c082324u: goto P_0c082324;
case 0x0c082326u: goto P_0c082326;
case 0x0c082328u: goto P_0c082328;
case 0x0c08232au: goto P_0c08232a;
case 0x0c08232cu: goto P_0c08232c;
case 0x0c08232eu: goto P_0c08232e;
case 0x0c082330u: goto P_0c082330;
case 0x0c082332u: goto P_0c082332;
case 0x0c082334u: goto P_0c082334;
case 0x0c082336u: goto P_0c082336;
case 0x0c082338u: goto P_0c082338;
case 0x0c08233au: goto P_0c08233a;
case 0x0c08233cu: goto P_0c08233c;
case 0x0c08233eu: goto P_0c08233e;
case 0x0c082340u: goto P_0c082340;
case 0x0c082342u: goto P_0c082342;
case 0x0c082344u: goto P_0c082344;
case 0x0c082346u: goto P_0c082346;
case 0x0c082348u: goto P_0c082348;
case 0x0c08234au: goto P_0c08234a;
case 0x0c08234cu: goto P_0c08234c;
case 0x0c08234eu: goto P_0c08234e;
case 0x0c082350u: goto P_0c082350;
case 0x0c082352u: goto P_0c082352;
case 0x0c082354u: goto P_0c082354;
case 0x0c082356u: goto P_0c082356;
case 0x0c082358u: goto P_0c082358;
case 0x0c08235au: goto P_0c08235a;
case 0x0c08235cu: goto P_0c08235c;
case 0x0c08235eu: goto P_0c08235e;
case 0x0c082360u: goto P_0c082360;
case 0x0c082362u: goto P_0c082362;
case 0x0c082364u: goto P_0c082364;
case 0x0c082366u: goto P_0c082366;
case 0x0c082368u: goto P_0c082368;
case 0x0c08236au: goto P_0c08236a;
case 0x0c08236cu: goto P_0c08236c;
case 0x0c08236eu: goto P_0c08236e;
case 0x0c082370u: goto P_0c082370;
case 0x0c082372u: goto P_0c082372;
case 0x0c082374u: goto P_0c082374;
case 0x0c082376u: goto P_0c082376;
case 0x0c082378u: goto P_0c082378;
case 0x0c08237au: goto P_0c08237a;
case 0x0c08237cu: goto P_0c08237c;
case 0x0c08237eu: goto P_0c08237e;
case 0x0c082380u: goto P_0c082380;
case 0x0c082382u: goto P_0c082382;
case 0x0c082384u: goto P_0c082384;
case 0x0c082386u: goto P_0c082386;
case 0x0c082388u: goto P_0c082388;
case 0x0c08238au: goto P_0c08238a;
case 0x0c08238cu: goto P_0c08238c;
case 0x0c08238eu: goto P_0c08238e;
case 0x0c082390u: goto P_0c082390;
case 0x0c082392u: goto P_0c082392;
case 0x0c082394u: goto P_0c082394;
case 0x0c082396u: goto P_0c082396;
case 0x0c082398u: goto P_0c082398;
case 0x0c08239au: goto P_0c08239a;
case 0x0c08239cu: goto P_0c08239c;
case 0x0c08239eu: goto P_0c08239e;
case 0x0c0823a0u: goto P_0c0823a0;
case 0x0c0823a2u: goto P_0c0823a2;
case 0x0c0823a4u: goto P_0c0823a4;
case 0x0c0823a6u: goto P_0c0823a6;
case 0x0c0823a8u: goto P_0c0823a8;
case 0x0c0823aau: goto P_0c0823aa;
case 0x0c0823acu: goto P_0c0823ac;
case 0x0c0823aeu: goto P_0c0823ae;
case 0x0c0823b0u: goto P_0c0823b0;
case 0x0c0823b2u: goto P_0c0823b2;
case 0x0c0823b4u: goto P_0c0823b4;
case 0x0c0823b6u: goto P_0c0823b6;
case 0x0c0823b8u: goto P_0c0823b8;
case 0x0c0823bau: goto P_0c0823ba;
case 0x0c0823bcu: goto P_0c0823bc;
case 0x0c0823beu: goto P_0c0823be;
case 0x0c0823c0u: goto P_0c0823c0;
case 0x0c0823c2u: goto P_0c0823c2;
case 0x0c0823c4u: goto P_0c0823c4;
case 0x0c0823c6u: goto P_0c0823c6;
case 0x0c0823c8u: goto P_0c0823c8;
case 0x0c0823cau: goto P_0c0823ca;
case 0x0c0823ccu: goto P_0c0823cc;
case 0x0c0823ceu: goto P_0c0823ce;
case 0x0c0823d0u: goto P_0c0823d0;
case 0x0c0823d2u: goto P_0c0823d2;
case 0x0c0823d4u: goto P_0c0823d4;
case 0x0c0823d6u: goto P_0c0823d6;
case 0x0c0823d8u: goto P_0c0823d8;
case 0x0c0823dau: goto P_0c0823da;
case 0x0c0823dcu: goto P_0c0823dc;
case 0x0c0823deu: goto P_0c0823de;
case 0x0c0823e0u: goto P_0c0823e0;
case 0x0c0823e2u: goto P_0c0823e2;
case 0x0c0823e4u: goto P_0c0823e4;
case 0x0c0823e6u: goto P_0c0823e6;
case 0x0c0823e8u: goto P_0c0823e8;
case 0x0c0823eau: goto P_0c0823ea;
case 0x0c0823ecu: goto P_0c0823ec;
case 0x0c0823eeu: goto P_0c0823ee;
case 0x0c0823f0u: goto P_0c0823f0;
case 0x0c0823f2u: goto P_0c0823f2;
case 0x0c0823f4u: goto P_0c0823f4;
case 0x0c0823f6u: goto P_0c0823f6;
case 0x0c0823f8u: goto P_0c0823f8;
case 0x0c0823fau: goto P_0c0823fa;
case 0x0c0823fcu: goto P_0c0823fc;
case 0x0c0823feu: goto P_0c0823fe;
case 0x0c082400u: goto P_0c082400;
case 0x0c082402u: goto P_0c082402;
case 0x0c082404u: goto P_0c082404;
case 0x0c082406u: goto P_0c082406;
case 0x0c082408u: goto P_0c082408;
case 0x0c08240au: goto P_0c08240a;
case 0x0c08240cu: goto P_0c08240c;
case 0x0c08240eu: goto P_0c08240e;
case 0x0c082410u: goto P_0c082410;
case 0x0c082412u: goto P_0c082412;
case 0x0c082414u: goto P_0c082414;
case 0x0c082416u: goto P_0c082416;
case 0x0c082418u: goto P_0c082418;
case 0x0c08241au: goto P_0c08241a;
case 0x0c08241cu: goto P_0c08241c;
case 0x0c08241eu: goto P_0c08241e;
case 0x0c082420u: goto P_0c082420;
case 0x0c082422u: goto P_0c082422;
case 0x0c082424u: goto P_0c082424;
case 0x0c082426u: goto P_0c082426;
case 0x0c082428u: goto P_0c082428;
case 0x0c08242au: goto P_0c08242a;
case 0x0c08242cu: goto P_0c08242c;
case 0x0c08242eu: goto P_0c08242e;
case 0x0c082430u: goto P_0c082430;
case 0x0c082432u: goto P_0c082432;
case 0x0c082434u: goto P_0c082434;
case 0x0c082436u: goto P_0c082436;
case 0x0c082438u: goto P_0c082438;
case 0x0c08243au: goto P_0c08243a;
case 0x0c08243cu: goto P_0c08243c;
case 0x0c08243eu: goto P_0c08243e;
case 0x0c082440u: goto P_0c082440;
case 0x0c082442u: goto P_0c082442;
case 0x0c082444u: goto P_0c082444;
case 0x0c082446u: goto P_0c082446;
case 0x0c082448u: goto P_0c082448;
case 0x0c08244au: goto P_0c08244a;
case 0x0c08244cu: goto P_0c08244c;
case 0x0c08244eu: goto P_0c08244e;
case 0x0c082450u: goto P_0c082450;
case 0x0c082452u: goto P_0c082452;
case 0x0c082454u: goto P_0c082454;
case 0x0c082456u: goto P_0c082456;
case 0x0c082458u: goto P_0c082458;
case 0x0c08245au: goto P_0c08245a;
case 0x0c08245cu: goto P_0c08245c;
case 0x0c08245eu: goto P_0c08245e;
case 0x0c082460u: goto P_0c082460;
case 0x0c082462u: goto P_0c082462;
case 0x0c082464u: goto P_0c082464;
case 0x0c082466u: goto P_0c082466;
case 0x0c082468u: goto P_0c082468;
case 0x0c0824d4u: goto P_0c0824d4;
case 0x0c0824d6u: goto P_0c0824d6;
case 0x0c0824d8u: goto P_0c0824d8;
case 0x0c0824dau: goto P_0c0824da;
case 0x0c0824dcu: goto P_0c0824dc;
case 0x0c0824deu: goto P_0c0824de;
case 0x0c0824e0u: goto P_0c0824e0;
case 0x0c0824e2u: goto P_0c0824e2;
case 0x0c0824e4u: goto P_0c0824e4;
case 0x0c0824e6u: goto P_0c0824e6;
case 0x0c0824e8u: goto P_0c0824e8;
case 0x0c0824eau: goto P_0c0824ea;
case 0x0c0824ecu: goto P_0c0824ec;
case 0x0c0824eeu: goto P_0c0824ee;
case 0x0c0824f0u: goto P_0c0824f0;
case 0x0c0824f2u: goto P_0c0824f2;
case 0x0c0824f4u: goto P_0c0824f4;
case 0x0c0824f6u: goto P_0c0824f6;
case 0x0c0824f8u: goto P_0c0824f8;
case 0x0c0824fau: goto P_0c0824fa;
case 0x0c0824fcu: goto P_0c0824fc;
case 0x0c0824feu: goto P_0c0824fe;
case 0x0c082500u: goto P_0c082500;
case 0x0c082502u: goto P_0c082502;
case 0x0c082504u: goto P_0c082504;
case 0x0c082506u: goto P_0c082506;
case 0x0c082508u: goto P_0c082508;
case 0x0c08250au: goto P_0c08250a;
case 0x0c08250cu: goto P_0c08250c;
case 0x0c08250eu: goto P_0c08250e;
case 0x0c082510u: goto P_0c082510;
case 0x0c082512u: goto P_0c082512;
case 0x0c082514u: goto P_0c082514;
case 0x0c082516u: goto P_0c082516;
case 0x0c082518u: goto P_0c082518;
case 0x0c08251au: goto P_0c08251a;
case 0x0c08251cu: goto P_0c08251c;
case 0x0c08251eu: goto P_0c08251e;
case 0x0c082520u: goto P_0c082520;
case 0x0c082522u: goto P_0c082522;
case 0x0c082524u: goto P_0c082524;
case 0x0c082526u: goto P_0c082526;
case 0x0c082528u: goto P_0c082528;
case 0x0c08252au: goto P_0c08252a;
case 0x0c08252cu: goto P_0c08252c;
case 0x0c08252eu: goto P_0c08252e;
case 0x0c082530u: goto P_0c082530;
case 0x0c082544u: goto P_0c082544;
case 0x0c082546u: goto P_0c082546;
case 0x0c082548u: goto P_0c082548;
case 0x0c08254au: goto P_0c08254a;
case 0x0c08254cu: goto P_0c08254c;
case 0x0c08254eu: goto P_0c08254e;
case 0x0c082550u: goto P_0c082550;
case 0x0c082552u: goto P_0c082552;
case 0x0c082554u: goto P_0c082554;
case 0x0c082556u: goto P_0c082556;
case 0x0c082558u: goto P_0c082558;
case 0x0c08255au: goto P_0c08255a;
case 0x0c08255cu: goto P_0c08255c;
case 0x0c08255eu: goto P_0c08255e;
case 0x0c082560u: goto P_0c082560;
case 0x0c082562u: goto P_0c082562;
case 0x0c082564u: goto P_0c082564;
case 0x0c082566u: goto P_0c082566;
case 0x0c082568u: goto P_0c082568;
case 0x0c08256au: goto P_0c08256a;
case 0x0c08256cu: goto P_0c08256c;
case 0x0c08256eu: goto P_0c08256e;
case 0x0c082570u: goto P_0c082570;
case 0x0c082572u: goto P_0c082572;
case 0x0c082574u: goto P_0c082574;
case 0x0c082576u: goto P_0c082576;
case 0x0c082578u: goto P_0c082578;
case 0x0c08257au: goto P_0c08257a;
case 0x0c08257cu: goto P_0c08257c;
case 0x0c08257eu: goto P_0c08257e;
case 0x0c082580u: goto P_0c082580;
case 0x0c082582u: goto P_0c082582;
case 0x0c082584u: goto P_0c082584;
case 0x0c082586u: goto P_0c082586;
case 0x0c082588u: goto P_0c082588;
case 0x0c08258au: goto P_0c08258a;
case 0x0c08258cu: goto P_0c08258c;
case 0x0c08258eu: goto P_0c08258e;
case 0x0c082590u: goto P_0c082590;
case 0x0c082592u: goto P_0c082592;
case 0x0c082594u: goto P_0c082594;
case 0x0c082596u: goto P_0c082596;
case 0x0c082598u: goto P_0c082598;
case 0x0c08259au: goto P_0c08259a;
case 0x0c08259cu: goto P_0c08259c;
case 0x0c08259eu: goto P_0c08259e;
case 0x0c0825a0u: goto P_0c0825a0;
case 0x0c0825a2u: goto P_0c0825a2;
case 0x0c0825a4u: goto P_0c0825a4;
case 0x0c0825a6u: goto P_0c0825a6;
case 0x0c0825a8u: goto P_0c0825a8;
case 0x0c0825aau: goto P_0c0825aa;
case 0x0c0825acu: goto P_0c0825ac;
case 0x0c0825aeu: goto P_0c0825ae;
case 0x0c0825b0u: goto P_0c0825b0;
case 0x0c0825b2u: goto P_0c0825b2;
case 0x0c0825b4u: goto P_0c0825b4;
case 0x0c0825b6u: goto P_0c0825b6;
case 0x0c0825b8u: goto P_0c0825b8;
case 0x0c0825bau: goto P_0c0825ba;
case 0x0c0825bcu: goto P_0c0825bc;
case 0x0c0825beu: goto P_0c0825be;
case 0x0c0825c0u: goto P_0c0825c0;
case 0x0c0825c2u: goto P_0c0825c2;
case 0x0c0825c4u: goto P_0c0825c4;
case 0x0c0825c6u: goto P_0c0825c6;
case 0x0c0825c8u: goto P_0c0825c8;
case 0x0c0825cau: goto P_0c0825ca;
case 0x0c0825ccu: goto P_0c0825cc;
case 0x0c0825ceu: goto P_0c0825ce;
case 0x0c0825d0u: goto P_0c0825d0;
case 0x0c0825d2u: goto P_0c0825d2;
case 0x0c0825d4u: goto P_0c0825d4;
case 0x0c0825d6u: goto P_0c0825d6;
case 0x0c0825d8u: goto P_0c0825d8;
case 0x0c0825dau: goto P_0c0825da;
case 0x0c0825dcu: goto P_0c0825dc;
case 0x0c0825deu: goto P_0c0825de;
case 0x0c0825e0u: goto P_0c0825e0;
case 0x0c0825e2u: goto P_0c0825e2;
case 0x0c0825e4u: goto P_0c0825e4;
case 0x0c0825e6u: goto P_0c0825e6;
case 0x0c0825e8u: goto P_0c0825e8;
case 0x0c0825eau: goto P_0c0825ea;
case 0x0c0825ecu: goto P_0c0825ec;
case 0x0c0825eeu: goto P_0c0825ee;
case 0x0c0825f0u: goto P_0c0825f0;
case 0x0c0825f2u: goto P_0c0825f2;
case 0x0c0825f4u: goto P_0c0825f4;
case 0x0c0825f6u: goto P_0c0825f6;
case 0x0c0825f8u: goto P_0c0825f8;
case 0x0c0825fau: goto P_0c0825fa;
case 0x0c0825fcu: goto P_0c0825fc;
case 0x0c0825feu: goto P_0c0825fe;
case 0x0c082600u: goto P_0c082600;
case 0x0c082602u: goto P_0c082602;
case 0x0c082604u: goto P_0c082604;
case 0x0c082606u: goto P_0c082606;
case 0x0c082608u: goto P_0c082608;
case 0x0c08260au: goto P_0c08260a;
case 0x0c08260cu: goto P_0c08260c;
case 0x0c08260eu: goto P_0c08260e;
case 0x0c082610u: goto P_0c082610;
case 0x0c082612u: goto P_0c082612;
case 0x0c082614u: goto P_0c082614;
case 0x0c082616u: goto P_0c082616;
case 0x0c082618u: goto P_0c082618;
case 0x0c08261au: goto P_0c08261a;
case 0x0c08261cu: goto P_0c08261c;
case 0x0c08261eu: goto P_0c08261e;
case 0x0c082620u: goto P_0c082620;
case 0x0c082622u: goto P_0c082622;
case 0x0c082624u: goto P_0c082624;
case 0x0c082626u: goto P_0c082626;
case 0x0c082628u: goto P_0c082628;
case 0x0c08262au: goto P_0c08262a;
case 0x0c08262cu: goto P_0c08262c;
case 0x0c08262eu: goto P_0c08262e;
case 0x0c082630u: goto P_0c082630;
case 0x0c082632u: goto P_0c082632;
case 0x0c082634u: goto P_0c082634;
case 0x0c082636u: goto P_0c082636;
case 0x0c082638u: goto P_0c082638;
case 0x0c08263au: goto P_0c08263a;
case 0x0c08263cu: goto P_0c08263c;
case 0x0c08263eu: goto P_0c08263e;
case 0x0c082640u: goto P_0c082640;
case 0x0c082642u: goto P_0c082642;
case 0x0c082644u: goto P_0c082644;
case 0x0c082646u: goto P_0c082646;
case 0x0c082648u: goto P_0c082648;
case 0x0c08264au: goto P_0c08264a;
case 0x0c08264cu: goto P_0c08264c;
case 0x0c08264eu: goto P_0c08264e;
case 0x0c082650u: goto P_0c082650;
case 0x0c082652u: goto P_0c082652;
case 0x0c082654u: goto P_0c082654;
case 0x0c082656u: goto P_0c082656;
case 0x0c082658u: goto P_0c082658;
case 0x0c08265au: goto P_0c08265a;
case 0x0c08265cu: goto P_0c08265c;
case 0x0c08265eu: goto P_0c08265e;
case 0x0c082660u: goto P_0c082660;
case 0x0c082662u: goto P_0c082662;
case 0x0c082664u: goto P_0c082664;
case 0x0c082666u: goto P_0c082666;
case 0x0c082668u: goto P_0c082668;
case 0x0c08266au: goto P_0c08266a;
case 0x0c08266cu: goto P_0c08266c;
case 0x0c08266eu: goto P_0c08266e;
case 0x0c082670u: goto P_0c082670;
case 0x0c082672u: goto P_0c082672;
case 0x0c082674u: goto P_0c082674;
case 0x0c082676u: goto P_0c082676;
case 0x0c082678u: goto P_0c082678;
case 0x0c08267au: goto P_0c08267a;
case 0x0c08267cu: goto P_0c08267c;
case 0x0c08267eu: goto P_0c08267e;
case 0x0c082680u: goto P_0c082680;
case 0x0c0826a4u: goto P_0c0826a4;
case 0x0c0826a6u: goto P_0c0826a6;
case 0x0c0826a8u: goto P_0c0826a8;
case 0x0c0826aau: goto P_0c0826aa;
case 0x0c0826acu: goto P_0c0826ac;
case 0x0c0826aeu: goto P_0c0826ae;
case 0x0c0826b4u: goto P_0c0826b4;
case 0x0c0826b6u: goto P_0c0826b6;
case 0x0c0826b8u: goto P_0c0826b8;
case 0x0c0826bau: goto P_0c0826ba;
case 0x0c0826bcu: goto P_0c0826bc;
case 0x0c0826beu: goto P_0c0826be;
case 0x0c0826c0u: goto P_0c0826c0;
case 0x0c0826c2u: goto P_0c0826c2;
case 0x0c0826c4u: goto P_0c0826c4;
case 0x0c0826c6u: goto P_0c0826c6;
case 0x0c0826c8u: goto P_0c0826c8;
case 0x0c0826cau: goto P_0c0826ca;
case 0x0c0826ccu: goto P_0c0826cc;
case 0x0c0826ceu: goto P_0c0826ce;
case 0x0c0826d0u: goto P_0c0826d0;
case 0x0c0826d2u: goto P_0c0826d2;
case 0x0c0826d4u: goto P_0c0826d4;
case 0x0c0826d6u: goto P_0c0826d6;
case 0x0c0826d8u: goto P_0c0826d8;
case 0x0c0826dau: goto P_0c0826da;
case 0x0c0826dcu: goto P_0c0826dc;
case 0x0c0826deu: goto P_0c0826de;
case 0x0c0826e0u: goto P_0c0826e0;
case 0x0c0826e2u: goto P_0c0826e2;
case 0x0c0826e4u: goto P_0c0826e4;
case 0x0c0826e6u: goto P_0c0826e6;
case 0x0c0826e8u: goto P_0c0826e8;
case 0x0c0826eau: goto P_0c0826ea;
case 0x0c0826ecu: goto P_0c0826ec;
case 0x0c0826eeu: goto P_0c0826ee;
case 0x0c0826f0u: goto P_0c0826f0;
case 0x0c0826f2u: goto P_0c0826f2;
case 0x0c0826f4u: goto P_0c0826f4;
case 0x0c0826f6u: goto P_0c0826f6;
case 0x0c0826f8u: goto P_0c0826f8;
case 0x0c0826fau: goto P_0c0826fa;
case 0x0c0826fcu: goto P_0c0826fc;
case 0x0c0826feu: goto P_0c0826fe;
case 0x0c082700u: goto P_0c082700;
case 0x0c082702u: goto P_0c082702;
case 0x0c082704u: goto P_0c082704;
case 0x0c082706u: goto P_0c082706;
case 0x0c082708u: goto P_0c082708;
case 0x0c08270au: goto P_0c08270a;
case 0x0c08270cu: goto P_0c08270c;
case 0x0c08270eu: goto P_0c08270e;
case 0x0c082710u: goto P_0c082710;
case 0x0c082712u: goto P_0c082712;
case 0x0c082714u: goto P_0c082714;
case 0x0c082716u: goto P_0c082716;
case 0x0c082718u: goto P_0c082718;
case 0x0c08271au: goto P_0c08271a;
case 0x0c08271cu: goto P_0c08271c;
case 0x0c08271eu: goto P_0c08271e;
case 0x0c082720u: goto P_0c082720;
case 0x0c082722u: goto P_0c082722;
case 0x0c082724u: goto P_0c082724;
case 0x0c082726u: goto P_0c082726;
case 0x0c082728u: goto P_0c082728;
case 0x0c08272au: goto P_0c08272a;
case 0x0c08272cu: goto P_0c08272c;
case 0x0c08272eu: goto P_0c08272e;
case 0x0c082730u: goto P_0c082730;
case 0x0c082732u: goto P_0c082732;
case 0x0c082734u: goto P_0c082734;
case 0x0c082736u: goto P_0c082736;
case 0x0c082738u: goto P_0c082738;
case 0x0c08273au: goto P_0c08273a;
case 0x0c08273cu: goto P_0c08273c;
case 0x0c08273eu: goto P_0c08273e;
case 0x0c082740u: goto P_0c082740;
case 0x0c082742u: goto P_0c082742;
case 0x0c082744u: goto P_0c082744;
case 0x0c082746u: goto P_0c082746;
case 0x0c082748u: goto P_0c082748;
case 0x0c08274au: goto P_0c08274a;
case 0x0c08274cu: goto P_0c08274c;
case 0x0c08274eu: goto P_0c08274e;
case 0x0c082750u: goto P_0c082750;
case 0x0c082752u: goto P_0c082752;
case 0x0c082754u: goto P_0c082754;
case 0x0c082756u: goto P_0c082756;
case 0x0c082758u: goto P_0c082758;
case 0x0c08275au: goto P_0c08275a;
case 0x0c08275cu: goto P_0c08275c;
case 0x0c08275eu: goto P_0c08275e;
case 0x0c082760u: goto P_0c082760;
case 0x0c082762u: goto P_0c082762;
case 0x0c082764u: goto P_0c082764;
case 0x0c082766u: goto P_0c082766;
case 0x0c082768u: goto P_0c082768;
case 0x0c08276au: goto P_0c08276a;
case 0x0c08276cu: goto P_0c08276c;
case 0x0c08276eu: goto P_0c08276e;
case 0x0c082770u: goto P_0c082770;
case 0x0c082772u: goto P_0c082772;
case 0x0c082774u: goto P_0c082774;
case 0x0c082776u: goto P_0c082776;
case 0x0c082778u: goto P_0c082778;
case 0x0c08277au: goto P_0c08277a;
case 0x0c08277cu: goto P_0c08277c;
case 0x0c08277eu: goto P_0c08277e;
case 0x0c082780u: goto P_0c082780;
case 0x0c082782u: goto P_0c082782;
case 0x0c082784u: goto P_0c082784;
case 0x0c082786u: goto P_0c082786;
case 0x0c082788u: goto P_0c082788;
case 0x0c08278au: goto P_0c08278a;
case 0x0c08278cu: goto P_0c08278c;
case 0x0c08278eu: goto P_0c08278e;
case 0x0c082790u: goto P_0c082790;
case 0x0c082792u: goto P_0c082792;
case 0x0c082794u: goto P_0c082794;
case 0x0c082796u: goto P_0c082796;
case 0x0c082798u: goto P_0c082798;
case 0x0c08279au: goto P_0c08279a;
case 0x0c08279cu: goto P_0c08279c;
case 0x0c08279eu: goto P_0c08279e;
case 0x0c0827a0u: goto P_0c0827a0;
case 0x0c0827a2u: goto P_0c0827a2;
case 0x0c0827a4u: goto P_0c0827a4;
case 0x0c0827a6u: goto P_0c0827a6;
case 0x0c0827a8u: goto P_0c0827a8;
case 0x0c0827aau: goto P_0c0827aa;
case 0x0c0827acu: goto P_0c0827ac;
case 0x0c0827aeu: goto P_0c0827ae;
case 0x0c0827b0u: goto P_0c0827b0;
case 0x0c0827b2u: goto P_0c0827b2;
case 0x0c0827b4u: goto P_0c0827b4;
case 0x0c0827b6u: goto P_0c0827b6;
case 0x0c0827b8u: goto P_0c0827b8;
case 0x0c0827bau: goto P_0c0827ba;
case 0x0c0827bcu: goto P_0c0827bc;
case 0x0c0827beu: goto P_0c0827be;
case 0x0c0827c0u: goto P_0c0827c0;
case 0x0c0827c2u: goto P_0c0827c2;
case 0x0c0827c4u: goto P_0c0827c4;
case 0x0c0827c6u: goto P_0c0827c6;
case 0x0c0827c8u: goto P_0c0827c8;
case 0x0c0827cau: goto P_0c0827ca;
case 0x0c0827ccu: goto P_0c0827cc;
case 0x0c0827ceu: goto P_0c0827ce;
case 0x0c0827d0u: goto P_0c0827d0;
case 0x0c0827d2u: goto P_0c0827d2;
case 0x0c0827d4u: goto P_0c0827d4;
case 0x0c0827d6u: goto P_0c0827d6;
case 0x0c0827d8u: goto P_0c0827d8;
case 0x0c0827dau: goto P_0c0827da;
case 0x0c0827dcu: goto P_0c0827dc;
case 0x0c0827deu: goto P_0c0827de;
case 0x0c0827e0u: goto P_0c0827e0;
case 0x0c0827e2u: goto P_0c0827e2;
case 0x0c0827e4u: goto P_0c0827e4;
case 0x0c0827e6u: goto P_0c0827e6;
case 0x0c0827e8u: goto P_0c0827e8;
case 0x0c0827eau: goto P_0c0827ea;
case 0x0c0827ecu: goto P_0c0827ec;
case 0x0c0827eeu: goto P_0c0827ee;
case 0x0c0827f0u: goto P_0c0827f0;
case 0x0c0827f2u: goto P_0c0827f2;
case 0x0c0827f4u: goto P_0c0827f4;
case 0x0c0827f6u: goto P_0c0827f6;
case 0x0c0827f8u: goto P_0c0827f8;
case 0x0c0827fau: goto P_0c0827fa;
case 0x0c0827fcu: goto P_0c0827fc;
case 0x0c0827feu: goto P_0c0827fe;
case 0x0c082800u: goto P_0c082800;
case 0x0c082802u: goto P_0c082802;
case 0x0c082824u: goto P_0c082824;
case 0x0c082826u: goto P_0c082826;
case 0x0c082828u: goto P_0c082828;
case 0x0c08282au: goto P_0c08282a;
case 0x0c08282cu: goto P_0c08282c;
case 0x0c08282eu: goto P_0c08282e;
case 0x0c082830u: goto P_0c082830;
case 0x0c082832u: goto P_0c082832;
case 0x0c082834u: goto P_0c082834;
case 0x0c082836u: goto P_0c082836;
case 0x0c082838u: goto P_0c082838;
case 0x0c08283au: goto P_0c08283a;
case 0x0c08283cu: goto P_0c08283c;
case 0x0c08283eu: goto P_0c08283e;
case 0x0c082840u: goto P_0c082840;
case 0x0c082842u: goto P_0c082842;
case 0x0c082844u: goto P_0c082844;
case 0x0c082846u: goto P_0c082846;
case 0x0c082848u: goto P_0c082848;
case 0x0c08284au: goto P_0c08284a;
case 0x0c08284cu: goto P_0c08284c;
case 0x0c08284eu: goto P_0c08284e;
case 0x0c082850u: goto P_0c082850;
case 0x0c082852u: goto P_0c082852;
case 0x0c082854u: goto P_0c082854;
case 0x0c082856u: goto P_0c082856;
case 0x0c082858u: goto P_0c082858;
case 0x0c08285au: goto P_0c08285a;
case 0x0c082868u: goto P_0c082868;
case 0x0c08286au: goto P_0c08286a;
case 0x0c08286cu: goto P_0c08286c;
case 0x0c08286eu: goto P_0c08286e;
case 0x0c082870u: goto P_0c082870;
case 0x0c082872u: goto P_0c082872;
case 0x0c082874u: goto P_0c082874;
case 0x0c082876u: goto P_0c082876;
case 0x0c082878u: goto P_0c082878;
case 0x0c08287au: goto P_0c08287a;
case 0x0c08287cu: goto P_0c08287c;
case 0x0c08287eu: goto P_0c08287e;
case 0x0c082880u: goto P_0c082880;
case 0x0c082882u: goto P_0c082882;
case 0x0c082884u: goto P_0c082884;
case 0x0c082886u: goto P_0c082886;
case 0x0c082888u: goto P_0c082888;
case 0x0c08288au: goto P_0c08288a;
case 0x0c08288cu: goto P_0c08288c;
case 0x0c08288eu: goto P_0c08288e;
case 0x0c082890u: goto P_0c082890;
case 0x0c082892u: goto P_0c082892;
case 0x0c082894u: goto P_0c082894;
case 0x0c082896u: goto P_0c082896;
case 0x0c082898u: goto P_0c082898;
case 0x0c08289au: goto P_0c08289a;
case 0x0c08289cu: goto P_0c08289c;
case 0x0c08289eu: goto P_0c08289e;
case 0x0c0828a0u: goto P_0c0828a0;
case 0x0c0828a2u: goto P_0c0828a2;
case 0x0c0828a4u: goto P_0c0828a4;
case 0x0c0828a6u: goto P_0c0828a6;
case 0x0c0828a8u: goto P_0c0828a8;
case 0x0c0828aau: goto P_0c0828aa;
case 0x0c0828acu: goto P_0c0828ac;
case 0x0c0828aeu: goto P_0c0828ae;
case 0x0c0828b0u: goto P_0c0828b0;
case 0x0c0828b2u: goto P_0c0828b2;
case 0x0c0828b4u: goto P_0c0828b4;
case 0x0c0828b6u: goto P_0c0828b6;
case 0x0c0828b8u: goto P_0c0828b8;
case 0x0c0828bau: goto P_0c0828ba;
case 0x0c0828bcu: goto P_0c0828bc;
case 0x0c0828beu: goto P_0c0828be;
case 0x0c0828c0u: goto P_0c0828c0;
case 0x0c0828c2u: goto P_0c0828c2;
case 0x0c0828c4u: goto P_0c0828c4;
case 0x0c0828c6u: goto P_0c0828c6;
case 0x0c0828c8u: goto P_0c0828c8;
case 0x0c0828cau: goto P_0c0828ca;
case 0x0c0828ccu: goto P_0c0828cc;
case 0x0c0828ceu: goto P_0c0828ce;
case 0x0c0828d0u: goto P_0c0828d0;
case 0x0c0828d2u: goto P_0c0828d2;
case 0x0c0828d4u: goto P_0c0828d4;
case 0x0c0828d6u: goto P_0c0828d6;
case 0x0c0828d8u: goto P_0c0828d8;
case 0x0c0828dau: goto P_0c0828da;
case 0x0c0828dcu: goto P_0c0828dc;
case 0x0c0828deu: goto P_0c0828de;
case 0x0c0828e0u: goto P_0c0828e0;
case 0x0c0828e2u: goto P_0c0828e2;
case 0x0c0828e4u: goto P_0c0828e4;
case 0x0c0828e6u: goto P_0c0828e6;
case 0x0c0828e8u: goto P_0c0828e8;
case 0x0c0828eau: goto P_0c0828ea;
case 0x0c0828ecu: goto P_0c0828ec;
case 0x0c0828eeu: goto P_0c0828ee;
case 0x0c0828f0u: goto P_0c0828f0;
case 0x0c0828f2u: goto P_0c0828f2;
case 0x0c0828f4u: goto P_0c0828f4;
case 0x0c0828f6u: goto P_0c0828f6;
case 0x0c0828f8u: goto P_0c0828f8;
case 0x0c0828fau: goto P_0c0828fa;
case 0x0c0828fcu: goto P_0c0828fc;
case 0x0c0828feu: goto P_0c0828fe;
case 0x0c082900u: goto P_0c082900;
case 0x0c082902u: goto P_0c082902;
case 0x0c082904u: goto P_0c082904;
case 0x0c082906u: goto P_0c082906;
case 0x0c082908u: goto P_0c082908;
case 0x0c08290au: goto P_0c08290a;
case 0x0c08290cu: goto P_0c08290c;
case 0x0c08290eu: goto P_0c08290e;
case 0x0c082910u: goto P_0c082910;
case 0x0c082912u: goto P_0c082912;
case 0x0c082914u: goto P_0c082914;
case 0x0c082916u: goto P_0c082916;
case 0x0c082918u: goto P_0c082918;
case 0x0c08291au: goto P_0c08291a;
case 0x0c08291cu: goto P_0c08291c;
case 0x0c08291eu: goto P_0c08291e;
case 0x0c082920u: goto P_0c082920;
case 0x0c082922u: goto P_0c082922;
case 0x0c082924u: goto P_0c082924;
case 0x0c082926u: goto P_0c082926;
case 0x0c082928u: goto P_0c082928;
case 0x0c08292au: goto P_0c08292a;
case 0x0c08292cu: goto P_0c08292c;
case 0x0c08292eu: goto P_0c08292e;
case 0x0c082930u: goto P_0c082930;
case 0x0c082932u: goto P_0c082932;
case 0x0c082934u: goto P_0c082934;
case 0x0c082936u: goto P_0c082936;
case 0x0c082938u: goto P_0c082938;
case 0x0c08293au: goto P_0c08293a;
case 0x0c08293cu: goto P_0c08293c;
case 0x0c08293eu: goto P_0c08293e;
case 0x0c082940u: goto P_0c082940;
case 0x0c082942u: goto P_0c082942;
case 0x0c082944u: goto P_0c082944;
case 0x0c082946u: goto P_0c082946;
case 0x0c082948u: goto P_0c082948;
case 0x0c08294au: goto P_0c08294a;
case 0x0c08294cu: goto P_0c08294c;
case 0x0c08294eu: goto P_0c08294e;
case 0x0c082950u: goto P_0c082950;
case 0x0c082952u: goto P_0c082952;
case 0x0c082954u: goto P_0c082954;
case 0x0c082956u: goto P_0c082956;
case 0x0c082958u: goto P_0c082958;
case 0x0c08295au: goto P_0c08295a;
case 0x0c08295cu: goto P_0c08295c;
case 0x0c08295eu: goto P_0c08295e;
case 0x0c082960u: goto P_0c082960;
case 0x0c082962u: goto P_0c082962;
case 0x0c082964u: goto P_0c082964;
case 0x0c082966u: goto P_0c082966;
case 0x0c082968u: goto P_0c082968;
case 0x0c08296au: goto P_0c08296a;
case 0x0c08296cu: goto P_0c08296c;
case 0x0c08296eu: goto P_0c08296e;
case 0x0c082970u: goto P_0c082970;
case 0x0c082972u: goto P_0c082972;
case 0x0c082974u: goto P_0c082974;
case 0x0c082976u: goto P_0c082976;
case 0x0c082978u: goto P_0c082978;
case 0x0c08297au: goto P_0c08297a;
case 0x0c08297cu: goto P_0c08297c;
case 0x0c08297eu: goto P_0c08297e;
case 0x0c082980u: goto P_0c082980;
case 0x0c082982u: goto P_0c082982;
case 0x0c082984u: goto P_0c082984;
case 0x0c082986u: goto P_0c082986;
case 0x0c082988u: goto P_0c082988;
case 0x0c08298au: goto P_0c08298a;
case 0x0c08298cu: goto P_0c08298c;
case 0x0c08298eu: goto P_0c08298e;
case 0x0c082990u: goto P_0c082990;
case 0x0c082992u: goto P_0c082992;
case 0x0c0829c0u: goto P_0c0829c0;
case 0x0c0829c2u: goto P_0c0829c2;
case 0x0c0829c4u: goto P_0c0829c4;
case 0x0c0829c6u: goto P_0c0829c6;
case 0x0c0829c8u: goto P_0c0829c8;
case 0x0c0829cau: goto P_0c0829ca;
case 0x0c0829ccu: goto P_0c0829cc;
case 0x0c0829ceu: goto P_0c0829ce;
case 0x0c0829d0u: goto P_0c0829d0;
case 0x0c0829d2u: goto P_0c0829d2;
case 0x0c0829d4u: goto P_0c0829d4;
case 0x0c0829d6u: goto P_0c0829d6;
case 0x0c0829d8u: goto P_0c0829d8;
case 0x0c0829dau: goto P_0c0829da;
case 0x0c0829dcu: goto P_0c0829dc;
case 0x0c0829deu: goto P_0c0829de;
case 0x0c0829e0u: goto P_0c0829e0;
case 0x0c0829e2u: goto P_0c0829e2;
case 0x0c0829e4u: goto P_0c0829e4;
case 0x0c0829e6u: goto P_0c0829e6;
case 0x0c0829e8u: goto P_0c0829e8;
case 0x0c0829eau: goto P_0c0829ea;
case 0x0c0829ecu: goto P_0c0829ec;
case 0x0c0829eeu: goto P_0c0829ee;
case 0x0c0829f0u: goto P_0c0829f0;
case 0x0c0829f2u: goto P_0c0829f2;
case 0x0c0829f4u: goto P_0c0829f4;
case 0x0c0829f6u: goto P_0c0829f6;
case 0x0c0829f8u: goto P_0c0829f8;
case 0x0c0829fau: goto P_0c0829fa;
case 0x0c0829fcu: goto P_0c0829fc;
case 0x0c0829feu: goto P_0c0829fe;
case 0x0c082a00u: goto P_0c082a00;
case 0x0c082a02u: goto P_0c082a02;
case 0x0c082a04u: goto P_0c082a04;
case 0x0c082a06u: goto P_0c082a06;
case 0x0c082a08u: goto P_0c082a08;
case 0x0c082a0au: goto P_0c082a0a;
case 0x0c082a0cu: goto P_0c082a0c;
case 0x0c082a0eu: goto P_0c082a0e;
case 0x0c082a10u: goto P_0c082a10;
case 0x0c082a12u: goto P_0c082a12;
case 0x0c082a14u: goto P_0c082a14;
case 0x0c082a16u: goto P_0c082a16;
case 0x0c082a18u: goto P_0c082a18;
case 0x0c082a1au: goto P_0c082a1a;
case 0x0c082a1cu: goto P_0c082a1c;
case 0x0c082a1eu: goto P_0c082a1e;
case 0x0c082a20u: goto P_0c082a20;
case 0x0c082a22u: goto P_0c082a22;
case 0x0c082a24u: goto P_0c082a24;
case 0x0c082a26u: goto P_0c082a26;
case 0x0c082a28u: goto P_0c082a28;
case 0x0c082a2au: goto P_0c082a2a;
case 0x0c082a2cu: goto P_0c082a2c;
case 0x0c082a2eu: goto P_0c082a2e;
case 0x0c082a30u: goto P_0c082a30;
case 0x0c082a32u: goto P_0c082a32;
case 0x0c082a34u: goto P_0c082a34;
case 0x0c082a36u: goto P_0c082a36;
case 0x0c082a38u: goto P_0c082a38;
case 0x0c082a3au: goto P_0c082a3a;
case 0x0c082a3cu: goto P_0c082a3c;
case 0x0c082a3eu: goto P_0c082a3e;
case 0x0c082a40u: goto P_0c082a40;
case 0x0c082a42u: goto P_0c082a42;
case 0x0c082a44u: goto P_0c082a44;
case 0x0c082a46u: goto P_0c082a46;
case 0x0c082a48u: goto P_0c082a48;
case 0x0c082a4au: goto P_0c082a4a;
case 0x0c082a4cu: goto P_0c082a4c;
case 0x0c082a4eu: goto P_0c082a4e;
case 0x0c082a50u: goto P_0c082a50;
case 0x0c082a52u: goto P_0c082a52;
case 0x0c082a54u: goto P_0c082a54;
case 0x0c082a56u: goto P_0c082a56;
case 0x0c082a58u: goto P_0c082a58;
case 0x0c082a5au: goto P_0c082a5a;
case 0x0c082a5cu: goto P_0c082a5c;
case 0x0c082a5eu: goto P_0c082a5e;
case 0x0c082a60u: goto P_0c082a60;
case 0x0c082a62u: goto P_0c082a62;
case 0x0c082a64u: goto P_0c082a64;
case 0x0c082a66u: goto P_0c082a66;
case 0x0c082a68u: goto P_0c082a68;
case 0x0c082a6au: goto P_0c082a6a;
case 0x0c082a6cu: goto P_0c082a6c;
case 0x0c082a6eu: goto P_0c082a6e;
case 0x0c082a70u: goto P_0c082a70;
case 0x0c082a72u: goto P_0c082a72;
case 0x0c082a74u: goto P_0c082a74;
case 0x0c082a76u: goto P_0c082a76;
case 0x0c082a78u: goto P_0c082a78;
case 0x0c082a7au: goto P_0c082a7a;
case 0x0c082a7cu: goto P_0c082a7c;
case 0x0c082a7eu: goto P_0c082a7e;
case 0x0c082a80u: goto P_0c082a80;
case 0x0c082a82u: goto P_0c082a82;
case 0x0c082a84u: goto P_0c082a84;
case 0x0c082a86u: goto P_0c082a86;
case 0x0c082a88u: goto P_0c082a88;
case 0x0c082a8au: goto P_0c082a8a;
case 0x0c082a8cu: goto P_0c082a8c;
case 0x0c082a8eu: goto P_0c082a8e;
case 0x0c082a90u: goto P_0c082a90;
case 0x0c082a92u: goto P_0c082a92;
case 0x0c082a94u: goto P_0c082a94;
case 0x0c082a96u: goto P_0c082a96;
case 0x0c082a98u: goto P_0c082a98;
case 0x0c082a9au: goto P_0c082a9a;
case 0x0c082a9cu: goto P_0c082a9c;
case 0x0c082a9eu: goto P_0c082a9e;
case 0x0c082aa0u: goto P_0c082aa0;
case 0x0c082aa2u: goto P_0c082aa2;
case 0x0c082aa4u: goto P_0c082aa4;
case 0x0c082aa6u: goto P_0c082aa6;
case 0x0c082aa8u: goto P_0c082aa8;
case 0x0c082aaau: goto P_0c082aaa;
case 0x0c082aacu: goto P_0c082aac;
case 0x0c082aaeu: goto P_0c082aae;
case 0x0c082ab0u: goto P_0c082ab0;
case 0x0c082ab2u: goto P_0c082ab2;
case 0x0c082ab4u: goto P_0c082ab4;
case 0x0c082ab6u: goto P_0c082ab6;
case 0x0c082ab8u: goto P_0c082ab8;
case 0x0c082abau: goto P_0c082aba;
case 0x0c082abcu: goto P_0c082abc;
case 0x0c082abeu: goto P_0c082abe;
case 0x0c082ac0u: goto P_0c082ac0;
case 0x0c082ac2u: goto P_0c082ac2;
case 0x0c082ac4u: goto P_0c082ac4;
case 0x0c082ac6u: goto P_0c082ac6;
case 0x0c082ac8u: goto P_0c082ac8;
case 0x0c082acau: goto P_0c082aca;
case 0x0c082accu: goto P_0c082acc;
case 0x0c082aceu: goto P_0c082ace;
case 0x0c082ad0u: goto P_0c082ad0;
case 0x0c082ad2u: goto P_0c082ad2;
case 0x0c082ad4u: goto P_0c082ad4;
case 0x0c082ad6u: goto P_0c082ad6;
case 0x0c082ad8u: goto P_0c082ad8;
case 0x0c082adau: goto P_0c082ada;
case 0x0c082adcu: goto P_0c082adc;
case 0x0c082adeu: goto P_0c082ade;
case 0x0c082ae0u: goto P_0c082ae0;
case 0x0c082ae2u: goto P_0c082ae2;
case 0x0c082ae4u: goto P_0c082ae4;
case 0x0c082ae6u: goto P_0c082ae6;
case 0x0c082ae8u: goto P_0c082ae8;
case 0x0c082aeau: goto P_0c082aea;
case 0x0c082b14u: goto P_0c082b14;
case 0x0c082b16u: goto P_0c082b16;
case 0x0c082b18u: goto P_0c082b18;
case 0x0c082b1au: goto P_0c082b1a;
case 0x0c082b1cu: goto P_0c082b1c;
case 0x0c082b1eu: goto P_0c082b1e;
case 0x0c082b20u: goto P_0c082b20;
case 0x0c082b22u: goto P_0c082b22;
case 0x0c082b24u: goto P_0c082b24;
case 0x0c082b26u: goto P_0c082b26;
case 0x0c082b28u: goto P_0c082b28;
case 0x0c082b2au: goto P_0c082b2a;
case 0x0c082b2cu: goto P_0c082b2c;
case 0x0c082b2eu: goto P_0c082b2e;
case 0x0c082b30u: goto P_0c082b30;
case 0x0c082b32u: goto P_0c082b32;
case 0x0c082b34u: goto P_0c082b34;
case 0x0c082b36u: goto P_0c082b36;
case 0x0c082b38u: goto P_0c082b38;
case 0x0c082b3au: goto P_0c082b3a;
case 0x0c082b3cu: goto P_0c082b3c;
case 0x0c082b3eu: goto P_0c082b3e;
case 0x0c082b40u: goto P_0c082b40;
case 0x0c082b42u: goto P_0c082b42;
case 0x0c082b44u: goto P_0c082b44;
case 0x0c082b46u: goto P_0c082b46;
case 0x0c082b48u: goto P_0c082b48;
case 0x0c082b4au: goto P_0c082b4a;
case 0x0c082b4cu: goto P_0c082b4c;
case 0x0c082b4eu: goto P_0c082b4e;
case 0x0c082b50u: goto P_0c082b50;
case 0x0c082b52u: goto P_0c082b52;
case 0x0c082b54u: goto P_0c082b54;
case 0x0c082b56u: goto P_0c082b56;
case 0x0c082b58u: goto P_0c082b58;
case 0x0c082b5au: goto P_0c082b5a;
case 0x0c082b5cu: goto P_0c082b5c;
case 0x0c082b5eu: goto P_0c082b5e;
case 0x0c082b60u: goto P_0c082b60;
case 0x0c082b62u: goto P_0c082b62;
case 0x0c082b64u: goto P_0c082b64;
case 0x0c082b66u: goto P_0c082b66;
case 0x0c082b68u: goto P_0c082b68;
case 0x0c082b6au: goto P_0c082b6a;
case 0x0c082b6cu: goto P_0c082b6c;
case 0x0c082b6eu: goto P_0c082b6e;
case 0x0c082b70u: goto P_0c082b70;
case 0x0c082b72u: goto P_0c082b72;
case 0x0c082b74u: goto P_0c082b74;
case 0x0c082b76u: goto P_0c082b76;
case 0x0c082b78u: goto P_0c082b78;
case 0x0c082b7au: goto P_0c082b7a;
case 0x0c082b7cu: goto P_0c082b7c;
case 0x0c082b7eu: goto P_0c082b7e;
case 0x0c082b80u: goto P_0c082b80;
case 0x0c082b82u: goto P_0c082b82;
case 0x0c082b84u: goto P_0c082b84;
case 0x0c082b86u: goto P_0c082b86;
case 0x0c082b88u: goto P_0c082b88;
case 0x0c082b8au: goto P_0c082b8a;
case 0x0c082b8cu: goto P_0c082b8c;
case 0x0c082b8eu: goto P_0c082b8e;
case 0x0c082b90u: goto P_0c082b90;
case 0x0c082b92u: goto P_0c082b92;
case 0x0c082b94u: goto P_0c082b94;
case 0x0c082b96u: goto P_0c082b96;
case 0x0c082b98u: goto P_0c082b98;
case 0x0c082b9au: goto P_0c082b9a;
case 0x0c082b9cu: goto P_0c082b9c;
case 0x0c082b9eu: goto P_0c082b9e;
case 0x0c082ba0u: goto P_0c082ba0;
case 0x0c082c94u: goto P_0c082c94;
case 0x0c082c96u: goto P_0c082c96;
case 0x0c082c98u: goto P_0c082c98;
case 0x0c082c9au: goto P_0c082c9a;
case 0x0c082c9cu: goto P_0c082c9c;
case 0x0c082c9eu: goto P_0c082c9e;
case 0x0c082ca0u: goto P_0c082ca0;
case 0x0c082ca2u: goto P_0c082ca2;
case 0x0c082ca4u: goto P_0c082ca4;
case 0x0c082ca6u: goto P_0c082ca6;
case 0x0c082ca8u: goto P_0c082ca8;
case 0x0c082caau: goto P_0c082caa;
case 0x0c082cacu: goto P_0c082cac;
case 0x0c082caeu: goto P_0c082cae;
case 0x0c082cb0u: goto P_0c082cb0;
case 0x0c082cb2u: goto P_0c082cb2;
case 0x0c082cb4u: goto P_0c082cb4;
case 0x0c082cb6u: goto P_0c082cb6;
case 0x0c082cb8u: goto P_0c082cb8;
case 0x0c082cbau: goto P_0c082cba;
case 0x0c082cbcu: goto P_0c082cbc;
case 0x0c082cbeu: goto P_0c082cbe;
case 0x0c082cc0u: goto P_0c082cc0;
case 0x0c082cc2u: goto P_0c082cc2;
case 0x0c082cc4u: goto P_0c082cc4;
case 0x0c082cc6u: goto P_0c082cc6;
case 0x0c082cc8u: goto P_0c082cc8;
case 0x0c082ccau: goto P_0c082cca;
case 0x0c082cccu: goto P_0c082ccc;
case 0x0c082cceu: goto P_0c082cce;
case 0x0c082cd0u: goto P_0c082cd0;
case 0x0c082cd2u: goto P_0c082cd2;
case 0x0c082cd4u: goto P_0c082cd4;
case 0x0c082cd6u: goto P_0c082cd6;
case 0x0c082cd8u: goto P_0c082cd8;
case 0x0c082cdau: goto P_0c082cda;
case 0x0c082cdcu: goto P_0c082cdc;
case 0x0c082cdeu: goto P_0c082cde;
case 0x0c082ce0u: goto P_0c082ce0;
case 0x0c082ce2u: goto P_0c082ce2;
case 0x0c082ce4u: goto P_0c082ce4;
case 0x0c082ce6u: goto P_0c082ce6;
case 0x0c082ce8u: goto P_0c082ce8;
case 0x0c082ceau: goto P_0c082cea;
case 0x0c082cecu: goto P_0c082cec;
case 0x0c082ceeu: goto P_0c082cee;
case 0x0c082cf0u: goto P_0c082cf0;
case 0x0c082cf2u: goto P_0c082cf2;
case 0x0c082cf4u: goto P_0c082cf4;
case 0x0c082cf6u: goto P_0c082cf6;
case 0x0c082cf8u: goto P_0c082cf8;
case 0x0c082cfau: goto P_0c082cfa;
case 0x0c082cfcu: goto P_0c082cfc;
case 0x0c082cfeu: goto P_0c082cfe;
case 0x0c082d00u: goto P_0c082d00;
case 0x0c082d02u: goto P_0c082d02;
case 0x0c082d04u: goto P_0c082d04;
case 0x0c082d06u: goto P_0c082d06;
case 0x0c082d08u: goto P_0c082d08;
case 0x0c082d0au: goto P_0c082d0a;
case 0x0c082d0cu: goto P_0c082d0c;
case 0x0c082d0eu: goto P_0c082d0e;
case 0x0c082d10u: goto P_0c082d10;
case 0x0c082d12u: goto P_0c082d12;
case 0x0c082d14u: goto P_0c082d14;
case 0x0c082d54u: goto P_0c082d54;
case 0x0c082d56u: goto P_0c082d56;
case 0x0c082d58u: goto P_0c082d58;
case 0x0c082d5au: goto P_0c082d5a;
case 0x0c082d5cu: goto P_0c082d5c;
case 0x0c082d5eu: goto P_0c082d5e;
case 0x0c082d60u: goto P_0c082d60;
case 0x0c082d62u: goto P_0c082d62;
case 0x0c082d64u: goto P_0c082d64;
case 0x0c082d66u: goto P_0c082d66;
case 0x0c082d68u: goto P_0c082d68;
case 0x0c082d6au: goto P_0c082d6a;
case 0x0c082d6cu: goto P_0c082d6c;
case 0x0c082d6eu: goto P_0c082d6e;
case 0x0c082d70u: goto P_0c082d70;
case 0x0c082d72u: goto P_0c082d72;
case 0x0c082d74u: goto P_0c082d74;
case 0x0c082d76u: goto P_0c082d76;
case 0x0c082d78u: goto P_0c082d78;
case 0x0c082d7au: goto P_0c082d7a;
case 0x0c082d7cu: goto P_0c082d7c;
case 0x0c082d7eu: goto P_0c082d7e;
case 0x0c082d80u: goto P_0c082d80;
case 0x0c082d82u: goto P_0c082d82;
case 0x0c082d84u: goto P_0c082d84;
case 0x0c082d86u: goto P_0c082d86;
case 0x0c082d88u: goto P_0c082d88;
case 0x0c082d8au: goto P_0c082d8a;
case 0x0c082d8cu: goto P_0c082d8c;
case 0x0c082d8eu: goto P_0c082d8e;
case 0x0c082d90u: goto P_0c082d90;
case 0x0c082d92u: goto P_0c082d92;
case 0x0c082d94u: goto P_0c082d94;
case 0x0c082d96u: goto P_0c082d96;
case 0x0c082d98u: goto P_0c082d98;
case 0x0c082d9au: goto P_0c082d9a;
case 0x0c082d9cu: goto P_0c082d9c;
case 0x0c082d9eu: goto P_0c082d9e;
case 0x0c082da0u: goto P_0c082da0;
case 0x0c082da2u: goto P_0c082da2;
case 0x0c082da4u: goto P_0c082da4;
case 0x0c082da6u: goto P_0c082da6;
case 0x0c082da8u: goto P_0c082da8;
case 0x0c082daau: goto P_0c082daa;
case 0x0c082dacu: goto P_0c082dac;
case 0x0c082daeu: goto P_0c082dae;
case 0x0c082db0u: goto P_0c082db0;
case 0x0c082db2u: goto P_0c082db2;
case 0x0c082db4u: goto P_0c082db4;
case 0x0c082db6u: goto P_0c082db6;
case 0x0c082db8u: goto P_0c082db8;
case 0x0c082dbau: goto P_0c082dba;
case 0x0c082dbcu: goto P_0c082dbc;
case 0x0c082dbeu: goto P_0c082dbe;
case 0x0c082dc0u: goto P_0c082dc0;
case 0x0c082dc2u: goto P_0c082dc2;
case 0x0c082dc4u: goto P_0c082dc4;
case 0x0c082dc6u: goto P_0c082dc6;
case 0x0c082dc8u: goto P_0c082dc8;
case 0x0c082dcau: goto P_0c082dca;
case 0x0c082dccu: goto P_0c082dcc;
case 0x0c082dceu: goto P_0c082dce;
case 0x0c082dd0u: goto P_0c082dd0;
case 0x0c082dd2u: goto P_0c082dd2;
case 0x0c082dd4u: goto P_0c082dd4;
case 0x0c082dd6u: goto P_0c082dd6;
case 0x0c082dd8u: goto P_0c082dd8;
case 0x0c082ddau: goto P_0c082dda;
case 0x0c082ddcu: goto P_0c082ddc;
case 0x0c082ddeu: goto P_0c082dde;
case 0x0c082de0u: goto P_0c082de0;
case 0x0c082de2u: goto P_0c082de2;
case 0x0c082de4u: goto P_0c082de4;
case 0x0c082de6u: goto P_0c082de6;
case 0x0c082de8u: goto P_0c082de8;
case 0x0c082deau: goto P_0c082dea;
case 0x0c082decu: goto P_0c082dec;
case 0x0c082deeu: goto P_0c082dee;
case 0x0c082df0u: goto P_0c082df0;
case 0x0c082df2u: goto P_0c082df2;
case 0x0c082df4u: goto P_0c082df4;
case 0x0c082df6u: goto P_0c082df6;
case 0x0c082df8u: goto P_0c082df8;
case 0x0c082dfau: goto P_0c082dfa;
case 0x0c082dfcu: goto P_0c082dfc;
case 0x0c082dfeu: goto P_0c082dfe;
case 0x0c083d18u: goto P_0c083d18;
case 0x0c083d1au: goto P_0c083d1a;
case 0x0c083d1cu: goto P_0c083d1c;
case 0x0c083d1eu: goto P_0c083d1e;
case 0x0c083d20u: goto P_0c083d20;
case 0x0c083d22u: goto P_0c083d22;
case 0x0c083d24u: goto P_0c083d24;
case 0x0c083d26u: goto P_0c083d26;
case 0x0c083d28u: goto P_0c083d28;
case 0x0c083d2au: goto P_0c083d2a;
case 0x0c083d2cu: goto P_0c083d2c;
case 0x0c083d2eu: goto P_0c083d2e;
case 0x0c083d30u: goto P_0c083d30;
case 0x0c083d32u: goto P_0c083d32;
case 0x0c083d34u: goto P_0c083d34;
case 0x0c083d36u: goto P_0c083d36;
case 0x0c083d38u: goto P_0c083d38;
case 0x0c083d3au: goto P_0c083d3a;
case 0x0c083d3cu: goto P_0c083d3c;
case 0x0c083d3eu: goto P_0c083d3e;
case 0x0c083d40u: goto P_0c083d40;
case 0x0c083d42u: goto P_0c083d42;
case 0x0c083d44u: goto P_0c083d44;
case 0x0c083d46u: goto P_0c083d46;
case 0x0c083d48u: goto P_0c083d48;
case 0x0c083d4au: goto P_0c083d4a;
case 0x0c083d4cu: goto P_0c083d4c;
case 0x0c083d4eu: goto P_0c083d4e;
case 0x0c083d50u: goto P_0c083d50;
case 0x0c083d52u: goto P_0c083d52;
case 0x0c083d54u: goto P_0c083d54;
case 0x0c083d56u: goto P_0c083d56;
case 0x0c083d58u: goto P_0c083d58;
case 0x0c083d5au: goto P_0c083d5a;
case 0x0c083d5cu: goto P_0c083d5c;
case 0x0c083d5eu: goto P_0c083d5e;
case 0x0c083d60u: goto P_0c083d60;
case 0x0c083d62u: goto P_0c083d62;
case 0x0c083d64u: goto P_0c083d64;
case 0x0c0a0280u: goto P_0c0a0280;
case 0x0c0a0282u: goto P_0c0a0282;
case 0x0c0a0284u: goto P_0c0a0284;
case 0x0c0a0286u: goto P_0c0a0286;
case 0x0c0a0288u: goto P_0c0a0288;
case 0x0c0a028au: goto P_0c0a028a;
case 0x0c0a028cu: goto P_0c0a028c;
case 0x0c0a028eu: goto P_0c0a028e;
case 0x0c0a0290u: goto P_0c0a0290;
case 0x0c0a0292u: goto P_0c0a0292;
case 0x0c0a0294u: goto P_0c0a0294;
case 0x0c0a0296u: goto P_0c0a0296;
case 0x0c0a0298u: goto P_0c0a0298;
case 0x0c0a029au: goto P_0c0a029a;
case 0x0c0a029cu: goto P_0c0a029c;
case 0x0c0a029eu: goto P_0c0a029e;
case 0x0c0a02a0u: goto P_0c0a02a0;
case 0x0c0a02a2u: goto P_0c0a02a2;
case 0x0c0a02a4u: goto P_0c0a02a4;
case 0x0c0a02a6u: goto P_0c0a02a6;
case 0x0c0a02a8u: goto P_0c0a02a8;
case 0x0c0a02aau: goto P_0c0a02aa;
case 0x0c0a02acu: goto P_0c0a02ac;
case 0x0c0a02aeu: goto P_0c0a02ae;
case 0x0c0a02b0u: goto P_0c0a02b0;
case 0x0c0a02b2u: goto P_0c0a02b2;
case 0x0c0a02b4u: goto P_0c0a02b4;
case 0x0c0a02b6u: goto P_0c0a02b6;
case 0x0c0a02b8u: goto P_0c0a02b8;
case 0x0c0a02bau: goto P_0c0a02ba;
case 0x0c0a02bcu: goto P_0c0a02bc;
case 0x0c0a02beu: goto P_0c0a02be;
case 0x0c0a02c0u: goto P_0c0a02c0;
case 0x0c0a02c2u: goto P_0c0a02c2;
case 0x0c0a02c4u: goto P_0c0a02c4;
case 0x0c0a02c6u: goto P_0c0a02c6;
case 0x0c0a02c8u: goto P_0c0a02c8;
case 0x0c0a02cau: goto P_0c0a02ca;
case 0x0c0a02ccu: goto P_0c0a02cc;
case 0x0c0a02ceu: goto P_0c0a02ce;
case 0x0c0a02d0u: goto P_0c0a02d0;
case 0x0c0a02d2u: goto P_0c0a02d2;
case 0x0c0a02d4u: goto P_0c0a02d4;
case 0x0c0a02d6u: goto P_0c0a02d6;
case 0x0c0a02d8u: goto P_0c0a02d8;
case 0x0c0a02dau: goto P_0c0a02da;
case 0x0c0a02dcu: goto P_0c0a02dc;
case 0x0c0a02deu: goto P_0c0a02de;
case 0x0c0a02e0u: goto P_0c0a02e0;
case 0x0c0a02e2u: goto P_0c0a02e2;
case 0x0c0a02e4u: goto P_0c0a02e4;
case 0x0c0a02e6u: goto P_0c0a02e6;
case 0x0c0a02e8u: goto P_0c0a02e8;
case 0x0c0a02eau: goto P_0c0a02ea;
case 0x0c0a02ecu: goto P_0c0a02ec;
case 0x0c0a02eeu: goto P_0c0a02ee;
case 0x0c0a02f0u: goto P_0c0a02f0;
case 0x0c0a02f2u: goto P_0c0a02f2;
case 0x0c0a02f4u: goto P_0c0a02f4;
case 0x0c0a02f6u: goto P_0c0a02f6;
case 0x0c0a02f8u: goto P_0c0a02f8;
case 0x0c0a02fau: goto P_0c0a02fa;
case 0x0c0a02fcu: goto P_0c0a02fc;
case 0x0c0a02feu: goto P_0c0a02fe;
case 0x0c0a0300u: goto P_0c0a0300;
case 0x0c0a0302u: goto P_0c0a0302;
case 0x0c0a0304u: goto P_0c0a0304;
case 0x0c0a0306u: goto P_0c0a0306;
case 0x0c0a0308u: goto P_0c0a0308;
case 0x0c0a030au: goto P_0c0a030a;
case 0x0c0a030cu: goto P_0c0a030c;
case 0x0c0a030eu: goto P_0c0a030e;
case 0x0c0a0310u: goto P_0c0a0310;
case 0x0c0a0312u: goto P_0c0a0312;
case 0x0c0a0314u: goto P_0c0a0314;
case 0x0c0a0316u: goto P_0c0a0316;
case 0x0c0a0318u: goto P_0c0a0318;
case 0x0c0a031au: goto P_0c0a031a;
case 0x0c0a031cu: goto P_0c0a031c;
case 0x0c0a031eu: goto P_0c0a031e;
case 0x0c0a0320u: goto P_0c0a0320;
case 0x0c0a0322u: goto P_0c0a0322;
case 0x0c0a0324u: goto P_0c0a0324;
case 0x0c0a0326u: goto P_0c0a0326;
case 0x0c0a0328u: goto P_0c0a0328;
case 0x0c0a032au: goto P_0c0a032a;
case 0x0c0a032cu: goto P_0c0a032c;
case 0x0c0a032eu: goto P_0c0a032e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c082110: /* original 2fe6, guest PC 0x0c082110 */
if(!s->budget--) { s->failed_pc=0x0c082110u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082112;
P_0c082112: /* original 2fd6, guest PC 0x0c082112 */
if(!s->budget--) { s->failed_pc=0x0c082112u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082114;
P_0c082114: /* original 2fc6, guest PC 0x0c082114 */
if(!s->budget--) { s->failed_pc=0x0c082114u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082116;
P_0c082116: /* original 2fb6, guest PC 0x0c082116 */
if(!s->budget--) { s->failed_pc=0x0c082116u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082118;
P_0c082118: /* original 2fa6, guest PC 0x0c082118 */
if(!s->budget--) { s->failed_pc=0x0c082118u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08211a;
P_0c08211a: /* original 2f96, guest PC 0x0c08211a */
if(!s->budget--) { s->failed_pc=0x0c08211au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08211c;
P_0c08211c: /* original 4f22, guest PC 0x0c08211c */
if(!s->budget--) { s->failed_pc=0x0c08211cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08211e;
P_0c08211e: /* original 7ff4, guest PC 0x0c08211e */
if(!s->budget--) { s->failed_pc=0x0c08211eu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c082120;
P_0c082120: /* original 1f41, guest PC 0x0c082120 */
if(!s->budget--) { s->failed_pc=0x0c082120u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c082122;
P_0c082122: /* original d347, guest PC 0x0c082122 */
if(!s->budget--) { s->failed_pc=0x0c082122u; return 0; }
r[3]=read(ram,0x0c082240u,4);
goto P_0c082124;
P_0c082124: /* original 2f32, guest PC 0x0c082124 */
if(!s->budget--) { s->failed_pc=0x0c082124u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c082126;
P_0c082126: /* original d348, guest PC 0x0c082126 */
if(!s->budget--) { s->failed_pc=0x0c082126u; return 0; }
r[3]=read(ram,0x0c082248u,4);
goto P_0c082128;
P_0c082128: /* original de46, guest PC 0x0c082128 */
if(!s->budget--) { s->failed_pc=0x0c082128u; return 0; }
r[14]=read(ram,0x0c082244u,4);
goto P_0c08212a;
P_0c08212a: /* original 430b, guest PC 0x0c08212a */
if(!s->budget--) { s->failed_pc=0x0c08212au; return 0; }
target=r[3];
r[16]=code_base|0x0c08212eu;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08212eu) { target=s->pc; goto dispatch; }
goto P_0c08212e;
P_0c08212c: /* original 54f1, guest PC 0x0c08212c */
if(!s->budget--) { s->failed_pc=0x0c08212cu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c08212e;
P_0c08212e: /* original d247, guest PC 0x0c08212e */
if(!s->budget--) { s->failed_pc=0x0c08212eu; return 0; }
r[2]=read(ram,0x0c08224cu,4);
goto P_0c082130;
P_0c082130: /* original 420b, guest PC 0x0c082130 */
if(!s->budget--) { s->failed_pc=0x0c082130u; return 0; }
target=r[2];
r[16]=code_base|0x0c082134u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082134u) { target=s->pc; goto dispatch; }
goto P_0c082134;
P_0c082132: /* original 64e3, guest PC 0x0c082132 */
if(!s->budget--) { s->failed_pc=0x0c082132u; return 0; }
r[4]=r[14];
goto P_0c082134;
P_0c082134: /* original d345, guest PC 0x0c082134 */
if(!s->budget--) { s->failed_pc=0x0c082134u; return 0; }
r[3]=read(ram,0x0c08224cu,4);
goto P_0c082136;
P_0c082136: /* original 64e3, guest PC 0x0c082136 */
if(!s->budget--) { s->failed_pc=0x0c082136u; return 0; }
r[4]=r[14];
goto P_0c082138;
P_0c082138: /* original 430b, guest PC 0x0c082138 */
if(!s->budget--) { s->failed_pc=0x0c082138u; return 0; }
target=r[3];
r[16]=code_base|0x0c08213cu;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08213cu) { target=s->pc; goto dispatch; }
goto P_0c08213c;
P_0c08213a: /* original 7458, guest PC 0x0c08213a */
if(!s->budget--) { s->failed_pc=0x0c08213au; return 0; }
r[4]+=0x00000058u;
goto P_0c08213c;
P_0c08213c: /* original e220, guest PC 0x0c08213c */
if(!s->budget--) { s->failed_pc=0x0c08213cu; return 0; }
r[2]=0x00000020u;
goto P_0c08213e;
P_0c08213e: /* original 956c, guest PC 0x0c08213e */
if(!s->budget--) { s->failed_pc=0x0c08213eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08221au,2);
goto P_0c082140;
P_0c082140: /* original e640, guest PC 0x0c082140 */
if(!s->budget--) { s->failed_pc=0x0c082140u; return 0; }
r[6]=0x00000040u;
goto P_0c082142;
P_0c082142: /* original 2f26, guest PC 0x0c082142 */
if(!s->budget--) { s->failed_pc=0x0c082142u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082144;
P_0c082144: /* original d342, guest PC 0x0c082144 */
if(!s->budget--) { s->failed_pc=0x0c082144u; return 0; }
r[3]=read(ram,0x0c082250u,4);
goto P_0c082146;
P_0c082146: /* original e709, guest PC 0x0c082146 */
if(!s->budget--) { s->failed_pc=0x0c082146u; return 0; }
r[7]=0x00000009u;
goto P_0c082148;
P_0c082148: /* original 430b, guest PC 0x0c082148 */
if(!s->budget--) { s->failed_pc=0x0c082148u; return 0; }
target=r[3];
r[16]=code_base|0x0c08214cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08214cu) { target=s->pc; goto dispatch; }
goto P_0c08214c;
P_0c08214a: /* original 64e3, guest PC 0x0c08214a */
if(!s->budget--) { s->failed_pc=0x0c08214au; return 0; }
r[4]=r[14];
goto P_0c08214c;
P_0c08214c: /* original 9266, guest PC 0x0c08214c */
if(!s->budget--) { s->failed_pc=0x0c08214cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08221cu,2);
goto P_0c08214e;
P_0c08214e: /* original ec00, guest PC 0x0c08214e */
if(!s->budget--) { s->failed_pc=0x0c08214eu; return 0; }
r[12]=0x00000000u;
goto P_0c082150;
P_0c082150: /* original 66e3, guest PC 0x0c082150 */
if(!s->budget--) { s->failed_pc=0x0c082150u; return 0; }
r[6]=r[14];
goto P_0c082152;
P_0c082152: /* original 67c3, guest PC 0x0c082152 */
if(!s->budget--) { s->failed_pc=0x0c082152u; return 0; }
r[7]=r[12];
goto P_0c082154;
P_0c082154: /* original 1f23, guest PC 0x0c082154 */
if(!s->budget--) { s->failed_pc=0x0c082154u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c082156;
P_0c082156: /* original dd3f, guest PC 0x0c082156 */
if(!s->budget--) { s->failed_pc=0x0c082156u; return 0; }
r[13]=read(ram,0x0c082254u,4);
goto P_0c082158;
P_0c082158: /* original 2fc6, guest PC 0x0c082158 */
if(!s->budget--) { s->failed_pc=0x0c082158u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08215a;
P_0c08215a: /* original 9560, guest PC 0x0c08215a */
if(!s->budget--) { s->failed_pc=0x0c08215au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08221eu,2);
goto P_0c08215c;
P_0c08215c: /* original 4d0b, guest PC 0x0c08215c */
if(!s->budget--) { s->failed_pc=0x0c08215cu; return 0; }
target=r[13];
r[16]=code_base|0x0c082160u;
r[4]=read(ram,r[15]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082160u) { target=s->pc; goto dispatch; }
goto P_0c082160;
P_0c08215e: /* original 54f4, guest PC 0x0c08215e */
if(!s->budget--) { s->failed_pc=0x0c08215eu; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c082160;
P_0c082160: /* original 9b5e, guest PC 0x0c082160 */
if(!s->budget--) { s->failed_pc=0x0c082160u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082220u,2);
goto P_0c082162;
P_0c082162: /* original 66e3, guest PC 0x0c082162 */
if(!s->budget--) { s->failed_pc=0x0c082162u; return 0; }
r[6]=r[14];
goto P_0c082164;
P_0c082164: /* original 2fc6, guest PC 0x0c082164 */
if(!s->budget--) { s->failed_pc=0x0c082164u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082166;
P_0c082166: /* original 67c3, guest PC 0x0c082166 */
if(!s->budget--) { s->failed_pc=0x0c082166u; return 0; }
r[7]=r[12];
goto P_0c082168;
P_0c082168: /* original 955b, guest PC 0x0c082168 */
if(!s->budget--) { s->failed_pc=0x0c082168u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082222u,2);
goto P_0c08216a;
P_0c08216a: /* original 4d0b, guest PC 0x0c08216a */
if(!s->budget--) { s->failed_pc=0x0c08216au; return 0; }
target=r[13];
r[16]=code_base|0x0c08216eu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08216eu) { target=s->pc; goto dispatch; }
goto P_0c08216e;
P_0c08216c: /* original 64b3, guest PC 0x0c08216c */
if(!s->budget--) { s->failed_pc=0x0c08216cu; return 0; }
r[4]=r[11];
goto P_0c08216e;
P_0c08216e: /* original 7f0c, guest PC 0x0c08216e */
if(!s->budget--) { s->failed_pc=0x0c08216eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c082170;
P_0c082170: /* original 915a, guest PC 0x0c082170 */
if(!s->budget--) { s->failed_pc=0x0c082170u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082228u,2);
goto P_0c082172;
P_0c082172: /* original 60f2, guest PC 0x0c082172 */
if(!s->budget--) { s->failed_pc=0x0c082172u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c082174;
P_0c082174: /* original 9956, guest PC 0x0c082174 */
if(!s->budget--) { s->failed_pc=0x0c082174u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082224u,2);
goto P_0c082176;
P_0c082176: /* original 001e, guest PC 0x0c082176 */
if(!s->budget--) { s->failed_pc=0x0c082176u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c082178;
P_0c082178: /* original 9a55, guest PC 0x0c082178 */
if(!s->budget--) { s->failed_pc=0x0c082178u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082226u,2);
goto P_0c08217a;
P_0c08217a: /* original 8800, guest PC 0x0c08217a */
if(!s->budget--) { s->failed_pc=0x0c08217au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c08217c;
P_0c08217c: /* original 8915, guest PC 0x0c08217c */
if(!s->budget--) { s->failed_pc=0x0c08217cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0821aa; }
goto P_0c08217e;
P_0c08217e: /* original 8801, guest PC 0x0c08217e */
if(!s->budget--) { s->failed_pc=0x0c08217eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c082180;
P_0c082180: /* original 8925, guest PC 0x0c082180 */
if(!s->budget--) { s->failed_pc=0x0c082180u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0821ce; }
goto P_0c082182;
P_0c082182: /* original 8802, guest PC 0x0c082182 */
if(!s->budget--) { s->failed_pc=0x0c082182u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c082184;
P_0c082184: /* original 892e, guest PC 0x0c082184 */
if(!s->budget--) { s->failed_pc=0x0c082184u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0821e4; }
goto P_0c082186;
P_0c082186: /* original 8803, guest PC 0x0c082186 */
if(!s->budget--) { s->failed_pc=0x0c082186u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c082188;
P_0c082188: /* original 8966, guest PC 0x0c082188 */
if(!s->budget--) { s->failed_pc=0x0c082188u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c082258; }
goto P_0c08218a;
P_0c08218a: /* original 8804, guest PC 0x0c08218a */
if(!s->budget--) { s->failed_pc=0x0c08218au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c08218c;
P_0c08218c: /* original 8977, guest PC 0x0c08218c */
if(!s->budget--) { s->failed_pc=0x0c08218cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08227e; }
goto P_0c08218e;
P_0c08218e: /* original 8805, guest PC 0x0c08218e */
if(!s->budget--) { s->failed_pc=0x0c08218eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c082190;
P_0c082190: /* original 8b01, guest PC 0x0c082190 */
if(!s->budget--) { s->failed_pc=0x0c082190u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c082196; }
goto P_0c082192;
P_0c082192: /* original a083, guest PC 0x0c082192 */
if(!s->budget--) { s->failed_pc=0x0c082192u; return 0; }
goto P_0c08229c;
P_0c082194: /* original 0009, guest PC 0x0c082194 */
if(!s->budget--) { s->failed_pc=0x0c082194u; return 0; }
goto P_0c082196;
P_0c082196: /* original 8806, guest PC 0x0c082196 */
if(!s->budget--) { s->failed_pc=0x0c082196u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c082198;
P_0c082198: /* original 8b01, guest PC 0x0c082198 */
if(!s->budget--) { s->failed_pc=0x0c082198u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08219e; }
goto P_0c08219a;
P_0c08219a: /* original a08e, guest PC 0x0c08219a */
if(!s->budget--) { s->failed_pc=0x0c08219au; return 0; }
goto P_0c0822ba;
P_0c08219c: /* original 0009, guest PC 0x0c08219c */
if(!s->budget--) { s->failed_pc=0x0c08219cu; return 0; }
goto P_0c08219e;
P_0c08219e: /* original 8807, guest PC 0x0c08219e */
if(!s->budget--) { s->failed_pc=0x0c08219eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0821a0;
P_0c0821a0: /* original 8b01, guest PC 0x0c0821a0 */
if(!s->budget--) { s->failed_pc=0x0c0821a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0821a6; }
goto P_0c0821a2;
P_0c0821a2: /* original a090, guest PC 0x0c0821a2 */
if(!s->budget--) { s->failed_pc=0x0c0821a2u; return 0; }
goto P_0c0822c6;
P_0c0821a4: /* original 0009, guest PC 0x0c0821a4 */
if(!s->budget--) { s->failed_pc=0x0c0821a4u; return 0; }
goto P_0c0821a6;
P_0c0821a6: /* original a096, guest PC 0x0c0821a6 */
if(!s->budget--) { s->failed_pc=0x0c0821a6u; return 0; }
goto P_0c0822d6;
P_0c0821a8: /* original 0009, guest PC 0x0c0821a8 */
if(!s->budget--) { s->failed_pc=0x0c0821a8u; return 0; }
goto P_0c0821aa;
P_0c0821aa: /* original 933e, guest PC 0x0c0821aa */
if(!s->budget--) { s->failed_pc=0x0c0821aau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08222au,2);
goto P_0c0821ac;
P_0c0821ac: /* original 66e3, guest PC 0x0c0821ac */
if(!s->budget--) { s->failed_pc=0x0c0821acu; return 0; }
r[6]=r[14];
goto P_0c0821ae;
P_0c0821ae: /* original e700, guest PC 0x0c0821ae */
if(!s->budget--) { s->failed_pc=0x0c0821aeu; return 0; }
r[7]=0x00000000u;
goto P_0c0821b0;
P_0c0821b0: /* original 2f32, guest PC 0x0c0821b0 */
if(!s->budget--) { s->failed_pc=0x0c0821b0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0821b2;
P_0c0821b2: /* original 2fc6, guest PC 0x0c0821b2 */
if(!s->budget--) { s->failed_pc=0x0c0821b2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0821b4;
P_0c0821b4: /* original 953a, guest PC 0x0c0821b4 */
if(!s->budget--) { s->failed_pc=0x0c0821b4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08222cu,2);
goto P_0c0821b6;
P_0c0821b6: /* original 4d0b, guest PC 0x0c0821b6 */
if(!s->budget--) { s->failed_pc=0x0c0821b6u; return 0; }
target=r[13];
r[16]=code_base|0x0c0821bau;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0821bau) { target=s->pc; goto dispatch; }
goto P_0c0821ba;
P_0c0821b8: /* original 54f1, guest PC 0x0c0821b8 */
if(!s->budget--) { s->failed_pc=0x0c0821b8u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0821ba;
P_0c0821ba: /* original 1f91, guest PC 0x0c0821ba */
if(!s->budget--) { s->failed_pc=0x0c0821bau; return 0; }
write(ram,r[15]+4,r[9],4);
goto P_0c0821bc;
P_0c0821bc: /* original 66e3, guest PC 0x0c0821bc */
if(!s->budget--) { s->failed_pc=0x0c0821bcu; return 0; }
r[6]=r[14];
goto P_0c0821be;
P_0c0821be: /* original 2fc6, guest PC 0x0c0821be */
if(!s->budget--) { s->failed_pc=0x0c0821beu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0821c0;
P_0c0821c0: /* original e700, guest PC 0x0c0821c0 */
if(!s->budget--) { s->failed_pc=0x0c0821c0u; return 0; }
r[7]=0x00000000u;
goto P_0c0821c2;
P_0c0821c2: /* original 9534, guest PC 0x0c0821c2 */
if(!s->budget--) { s->failed_pc=0x0c0821c2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08222eu,2);
goto P_0c0821c4;
P_0c0821c4: /* original 4d0b, guest PC 0x0c0821c4 */
if(!s->budget--) { s->failed_pc=0x0c0821c4u; return 0; }
target=r[13];
r[16]=code_base|0x0c0821c8u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0821c8u) { target=s->pc; goto dispatch; }
goto P_0c0821c8;
P_0c0821c6: /* original 54f2, guest PC 0x0c0821c6 */
if(!s->budget--) { s->failed_pc=0x0c0821c6u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0821c8;
P_0c0821c8: /* original 9b32, guest PC 0x0c0821c8 */
if(!s->budget--) { s->failed_pc=0x0c0821c8u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082230u,2);
goto P_0c0821ca;
P_0c0821ca: /* original a062, guest PC 0x0c0821ca */
if(!s->budget--) { s->failed_pc=0x0c0821cau; return 0; }
r[15]+=0x00000008u;
goto P_0c082292;
P_0c0821cc: /* original 7f08, guest PC 0x0c0821cc */
if(!s->budget--) { s->failed_pc=0x0c0821ccu; return 0; }
r[15]+=0x00000008u;
goto P_0c0821ce;
P_0c0821ce: /* original 9230, guest PC 0x0c0821ce */
if(!s->budget--) { s->failed_pc=0x0c0821ceu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082232u,2);
goto P_0c0821d0;
P_0c0821d0: /* original 66e3, guest PC 0x0c0821d0 */
if(!s->budget--) { s->failed_pc=0x0c0821d0u; return 0; }
r[6]=r[14];
goto P_0c0821d2;
P_0c0821d2: /* original e700, guest PC 0x0c0821d2 */
if(!s->budget--) { s->failed_pc=0x0c0821d2u; return 0; }
r[7]=0x00000000u;
goto P_0c0821d4;
P_0c0821d4: /* original 2f22, guest PC 0x0c0821d4 */
if(!s->budget--) { s->failed_pc=0x0c0821d4u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0821d6;
P_0c0821d6: /* original 2fc6, guest PC 0x0c0821d6 */
if(!s->budget--) { s->failed_pc=0x0c0821d6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0821d8;
P_0c0821d8: /* original 952c, guest PC 0x0c0821d8 */
if(!s->budget--) { s->failed_pc=0x0c0821d8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082234u,2);
goto P_0c0821da;
P_0c0821da: /* original 4d0b, guest PC 0x0c0821da */
if(!s->budget--) { s->failed_pc=0x0c0821dau; return 0; }
target=r[13];
r[16]=code_base|0x0c0821deu;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0821deu) { target=s->pc; goto dispatch; }
goto P_0c0821de;
P_0c0821dc: /* original 54f1, guest PC 0x0c0821dc */
if(!s->budget--) { s->failed_pc=0x0c0821dcu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0821de;
P_0c0821de: /* original 9b2a, guest PC 0x0c0821de */
if(!s->budget--) { s->failed_pc=0x0c0821deu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082236u,2);
goto P_0c0821e0;
P_0c0821e0: /* original a057, guest PC 0x0c0821e0 */
if(!s->budget--) { s->failed_pc=0x0c0821e0u; return 0; }
r[15]+=0x00000004u;
goto P_0c082292;
P_0c0821e2: /* original 7f04, guest PC 0x0c0821e2 */
if(!s->budget--) { s->failed_pc=0x0c0821e2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0821e4;
P_0c0821e4: /* original 9328, guest PC 0x0c0821e4 */
if(!s->budget--) { s->failed_pc=0x0c0821e4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082238u,2);
goto P_0c0821e6;
P_0c0821e6: /* original 66e3, guest PC 0x0c0821e6 */
if(!s->budget--) { s->failed_pc=0x0c0821e6u; return 0; }
r[6]=r[14];
goto P_0c0821e8;
P_0c0821e8: /* original 65a3, guest PC 0x0c0821e8 */
if(!s->budget--) { s->failed_pc=0x0c0821e8u; return 0; }
r[5]=r[10];
goto P_0c0821ea;
P_0c0821ea: /* original e700, guest PC 0x0c0821ea */
if(!s->budget--) { s->failed_pc=0x0c0821eau; return 0; }
r[7]=0x00000000u;
goto P_0c0821ec;
P_0c0821ec: /* original 2f32, guest PC 0x0c0821ec */
if(!s->budget--) { s->failed_pc=0x0c0821ecu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0821ee;
P_0c0821ee: /* original 2fc6, guest PC 0x0c0821ee */
if(!s->budget--) { s->failed_pc=0x0c0821eeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0821f0;
P_0c0821f0: /* original 4d0b, guest PC 0x0c0821f0 */
if(!s->budget--) { s->failed_pc=0x0c0821f0u; return 0; }
target=r[13];
r[16]=code_base|0x0c0821f4u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0821f4u) { target=s->pc; goto dispatch; }
goto P_0c0821f4;
P_0c0821f2: /* original 54f1, guest PC 0x0c0821f2 */
if(!s->budget--) { s->failed_pc=0x0c0821f2u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0821f4;
P_0c0821f4: /* original 931d, guest PC 0x0c0821f4 */
if(!s->budget--) { s->failed_pc=0x0c0821f4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082232u,2);
goto P_0c0821f6;
P_0c0821f6: /* original 66e3, guest PC 0x0c0821f6 */
if(!s->budget--) { s->failed_pc=0x0c0821f6u; return 0; }
r[6]=r[14];
goto P_0c0821f8;
P_0c0821f8: /* original e700, guest PC 0x0c0821f8 */
if(!s->budget--) { s->failed_pc=0x0c0821f8u; return 0; }
r[7]=0x00000000u;
goto P_0c0821fa;
P_0c0821fa: /* original 1f31, guest PC 0x0c0821fa */
if(!s->budget--) { s->failed_pc=0x0c0821fau; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0821fc;
P_0c0821fc: /* original 2fc6, guest PC 0x0c0821fc */
if(!s->budget--) { s->failed_pc=0x0c0821fcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0821fe;
P_0c0821fe: /* original 9515, guest PC 0x0c0821fe */
if(!s->budget--) { s->failed_pc=0x0c0821feu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08222cu,2);
goto P_0c082200;
P_0c082200: /* original 4d0b, guest PC 0x0c082200 */
if(!s->budget--) { s->failed_pc=0x0c082200u; return 0; }
target=r[13];
r[16]=code_base|0x0c082204u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082204u) { target=s->pc; goto dispatch; }
goto P_0c082204;
P_0c082202: /* original 54f2, guest PC 0x0c082202 */
if(!s->budget--) { s->failed_pc=0x0c082202u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c082204;
P_0c082204: /* original 9319, guest PC 0x0c082204 */
if(!s->budget--) { s->failed_pc=0x0c082204u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08223au,2);
goto P_0c082206;
P_0c082206: /* original 66e3, guest PC 0x0c082206 */
if(!s->budget--) { s->failed_pc=0x0c082206u; return 0; }
r[6]=r[14];
goto P_0c082208;
P_0c082208: /* original e700, guest PC 0x0c082208 */
if(!s->budget--) { s->failed_pc=0x0c082208u; return 0; }
r[7]=0x00000000u;
goto P_0c08220a;
P_0c08220a: /* original 1f32, guest PC 0x0c08220a */
if(!s->budget--) { s->failed_pc=0x0c08220au; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c08220c;
P_0c08220c: /* original 2fc6, guest PC 0x0c08220c */
if(!s->budget--) { s->failed_pc=0x0c08220cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08220e;
P_0c08220e: /* original 950e, guest PC 0x0c08220e */
if(!s->budget--) { s->failed_pc=0x0c08220eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08222eu,2);
goto P_0c082210;
P_0c082210: /* original 4d0b, guest PC 0x0c082210 */
if(!s->budget--) { s->failed_pc=0x0c082210u; return 0; }
target=r[13];
r[16]=code_base|0x0c082214u;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082214u) { target=s->pc; goto dispatch; }
goto P_0c082214;
P_0c082212: /* original 54f3, guest PC 0x0c082212 */
if(!s->budget--) { s->failed_pc=0x0c082212u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c082214;
P_0c082214: /* original 9b12, guest PC 0x0c082214 */
if(!s->budget--) { s->failed_pc=0x0c082214u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08223cu,2);
goto P_0c082216;
P_0c082216: /* original a03c, guest PC 0x0c082216 */
if(!s->budget--) { s->failed_pc=0x0c082216u; return 0; }
r[15]+=0x0000000cu;
goto P_0c082292;
P_0c082218: /* original 7f0c, guest PC 0x0c082218 */
if(!s->budget--) { s->failed_pc=0x0c082218u; return 0; }
r[15]+=0x0000000cu;
if(!vf3_matrix_family(0x0c08221au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08221au; return 0; } return 1;
P_0c082258: /* original 9249, guest PC 0x0c082258 */
if(!s->budget--) { s->failed_pc=0x0c082258u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0822eeu,2);
goto P_0c08225a;
P_0c08225a: /* original 66e3, guest PC 0x0c08225a */
if(!s->budget--) { s->failed_pc=0x0c08225au; return 0; }
r[6]=r[14];
goto P_0c08225c;
P_0c08225c: /* original 65a3, guest PC 0x0c08225c */
if(!s->budget--) { s->failed_pc=0x0c08225cu; return 0; }
r[5]=r[10];
goto P_0c08225e;
P_0c08225e: /* original e700, guest PC 0x0c08225e */
if(!s->budget--) { s->failed_pc=0x0c08225eu; return 0; }
r[7]=0x00000000u;
goto P_0c082260;
P_0c082260: /* original 2f22, guest PC 0x0c082260 */
if(!s->budget--) { s->failed_pc=0x0c082260u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c082262;
P_0c082262: /* original 2fc6, guest PC 0x0c082262 */
if(!s->budget--) { s->failed_pc=0x0c082262u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082264;
P_0c082264: /* original 4d0b, guest PC 0x0c082264 */
if(!s->budget--) { s->failed_pc=0x0c082264u; return 0; }
target=r[13];
r[16]=code_base|0x0c082268u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082268u) { target=s->pc; goto dispatch; }
goto P_0c082268;
P_0c082266: /* original 54f1, guest PC 0x0c082266 */
if(!s->budget--) { s->failed_pc=0x0c082266u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c082268;
P_0c082268: /* original 9342, guest PC 0x0c082268 */
if(!s->budget--) { s->failed_pc=0x0c082268u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0822f0u,2);
goto P_0c08226a;
P_0c08226a: /* original 66e3, guest PC 0x0c08226a */
if(!s->budget--) { s->failed_pc=0x0c08226au; return 0; }
r[6]=r[14];
goto P_0c08226c;
P_0c08226c: /* original e700, guest PC 0x0c08226c */
if(!s->budget--) { s->failed_pc=0x0c08226cu; return 0; }
r[7]=0x00000000u;
goto P_0c08226e;
P_0c08226e: /* original 1f31, guest PC 0x0c08226e */
if(!s->budget--) { s->failed_pc=0x0c08226eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c082270;
P_0c082270: /* original 2fc6, guest PC 0x0c082270 */
if(!s->budget--) { s->failed_pc=0x0c082270u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082272;
P_0c082272: /* original 953e, guest PC 0x0c082272 */
if(!s->budget--) { s->failed_pc=0x0c082272u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0822f2u,2);
goto P_0c082274;
P_0c082274: /* original 4d0b, guest PC 0x0c082274 */
if(!s->budget--) { s->failed_pc=0x0c082274u; return 0; }
target=r[13];
r[16]=code_base|0x0c082278u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082278u) { target=s->pc; goto dispatch; }
goto P_0c082278;
P_0c082276: /* original 54f2, guest PC 0x0c082276 */
if(!s->budget--) { s->failed_pc=0x0c082276u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c082278;
P_0c082278: /* original 9b3c, guest PC 0x0c082278 */
if(!s->budget--) { s->failed_pc=0x0c082278u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0822f4u,2);
goto P_0c08227a;
P_0c08227a: /* original a00a, guest PC 0x0c08227a */
if(!s->budget--) { s->failed_pc=0x0c08227au; return 0; }
r[15]+=0x00000008u;
goto P_0c082292;
P_0c08227c: /* original 7f08, guest PC 0x0c08227c */
if(!s->budget--) { s->failed_pc=0x0c08227cu; return 0; }
r[15]+=0x00000008u;
goto P_0c08227e;
P_0c08227e: /* original 933a, guest PC 0x0c08227e */
if(!s->budget--) { s->failed_pc=0x0c08227eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0822f6u,2);
goto P_0c082280;
P_0c082280: /* original 66e3, guest PC 0x0c082280 */
if(!s->budget--) { s->failed_pc=0x0c082280u; return 0; }
r[6]=r[14];
goto P_0c082282;
P_0c082282: /* original e700, guest PC 0x0c082282 */
if(!s->budget--) { s->failed_pc=0x0c082282u; return 0; }
r[7]=0x00000000u;
goto P_0c082284;
P_0c082284: /* original 2f32, guest PC 0x0c082284 */
if(!s->budget--) { s->failed_pc=0x0c082284u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c082286;
P_0c082286: /* original 2fc6, guest PC 0x0c082286 */
if(!s->budget--) { s->failed_pc=0x0c082286u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082288;
P_0c082288: /* original 9536, guest PC 0x0c082288 */
if(!s->budget--) { s->failed_pc=0x0c082288u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0822f8u,2);
goto P_0c08228a;
P_0c08228a: /* original 4d0b, guest PC 0x0c08228a */
if(!s->budget--) { s->failed_pc=0x0c08228au; return 0; }
target=r[13];
r[16]=code_base|0x0c08228eu;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08228eu) { target=s->pc; goto dispatch; }
goto P_0c08228e;
P_0c08228c: /* original 54f1, guest PC 0x0c08228c */
if(!s->budget--) { s->failed_pc=0x0c08228cu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c08228e;
P_0c08228e: /* original 9b34, guest PC 0x0c08228e */
if(!s->budget--) { s->failed_pc=0x0c08228eu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0822fau,2);
goto P_0c082290;
P_0c082290: /* original 7f04, guest PC 0x0c082290 */
if(!s->budget--) { s->failed_pc=0x0c082290u; return 0; }
r[15]+=0x00000004u;
goto P_0c082292;
P_0c082292: /* original e700, guest PC 0x0c082292 */
if(!s->budget--) { s->failed_pc=0x0c082292u; return 0; }
r[7]=0x00000000u;
goto P_0c082294;
P_0c082294: /* original 2fc6, guest PC 0x0c082294 */
if(!s->budget--) { s->failed_pc=0x0c082294u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082296;
P_0c082296: /* original 9531, guest PC 0x0c082296 */
if(!s->budget--) { s->failed_pc=0x0c082296u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0822fcu,2);
goto P_0c082298;
P_0c082298: /* original a01a, guest PC 0x0c082298 */
if(!s->budget--) { s->failed_pc=0x0c082298u; return 0; }
r[6]=r[14];
goto P_0c0822d0;
P_0c08229a: /* original 66e3, guest PC 0x0c08229a */
if(!s->budget--) { s->failed_pc=0x0c08229au; return 0; }
r[6]=r[14];
goto P_0c08229c;
P_0c08229c: /* original 9228, guest PC 0x0c08229c */
if(!s->budget--) { s->failed_pc=0x0c08229cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0822f0u,2);
goto P_0c08229e;
P_0c08229e: /* original 66e3, guest PC 0x0c08229e */
if(!s->budget--) { s->failed_pc=0x0c08229eu; return 0; }
r[6]=r[14];
goto P_0c0822a0;
P_0c0822a0: /* original 65a3, guest PC 0x0c0822a0 */
if(!s->budget--) { s->failed_pc=0x0c0822a0u; return 0; }
r[5]=r[10];
goto P_0c0822a2;
P_0c0822a2: /* original e700, guest PC 0x0c0822a2 */
if(!s->budget--) { s->failed_pc=0x0c0822a2u; return 0; }
r[7]=0x00000000u;
goto P_0c0822a4;
P_0c0822a4: /* original 2f22, guest PC 0x0c0822a4 */
if(!s->budget--) { s->failed_pc=0x0c0822a4u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0822a6;
P_0c0822a6: /* original 2fc6, guest PC 0x0c0822a6 */
if(!s->budget--) { s->failed_pc=0x0c0822a6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0822a8;
P_0c0822a8: /* original 4d0b, guest PC 0x0c0822a8 */
if(!s->budget--) { s->failed_pc=0x0c0822a8u; return 0; }
target=r[13];
r[16]=code_base|0x0c0822acu;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0822acu) { target=s->pc; goto dispatch; }
goto P_0c0822ac;
P_0c0822aa: /* original 54f1, guest PC 0x0c0822aa */
if(!s->budget--) { s->failed_pc=0x0c0822aau; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0822ac;
P_0c0822ac: /* original 9b27, guest PC 0x0c0822ac */
if(!s->budget--) { s->failed_pc=0x0c0822acu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0822feu,2);
goto P_0c0822ae;
P_0c0822ae: /* original 7f04, guest PC 0x0c0822ae */
if(!s->budget--) { s->failed_pc=0x0c0822aeu; return 0; }
r[15]+=0x00000004u;
goto P_0c0822b0;
P_0c0822b0: /* original e700, guest PC 0x0c0822b0 */
if(!s->budget--) { s->failed_pc=0x0c0822b0u; return 0; }
r[7]=0x00000000u;
goto P_0c0822b2;
P_0c0822b2: /* original 2fc6, guest PC 0x0c0822b2 */
if(!s->budget--) { s->failed_pc=0x0c0822b2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0822b4;
P_0c0822b4: /* original 9524, guest PC 0x0c0822b4 */
if(!s->budget--) { s->failed_pc=0x0c0822b4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082300u,2);
goto P_0c0822b6;
P_0c0822b6: /* original a00b, guest PC 0x0c0822b6 */
if(!s->budget--) { s->failed_pc=0x0c0822b6u; return 0; }
r[6]=r[14];
goto P_0c0822d0;
P_0c0822b8: /* original 66e3, guest PC 0x0c0822b8 */
if(!s->budget--) { s->failed_pc=0x0c0822b8u; return 0; }
r[6]=r[14];
goto P_0c0822ba;
P_0c0822ba: /* original e700, guest PC 0x0c0822ba */
if(!s->budget--) { s->failed_pc=0x0c0822bau; return 0; }
r[7]=0x00000000u;
goto P_0c0822bc;
P_0c0822bc: /* original 6b93, guest PC 0x0c0822bc */
if(!s->budget--) { s->failed_pc=0x0c0822bcu; return 0; }
r[11]=r[9];
goto P_0c0822be;
P_0c0822be: /* original 2fc6, guest PC 0x0c0822be */
if(!s->budget--) { s->failed_pc=0x0c0822beu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0822c0;
P_0c0822c0: /* original 951f, guest PC 0x0c0822c0 */
if(!s->budget--) { s->failed_pc=0x0c0822c0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082302u,2);
goto P_0c0822c2;
P_0c0822c2: /* original a005, guest PC 0x0c0822c2 */
if(!s->budget--) { s->failed_pc=0x0c0822c2u; return 0; }
r[6]=r[14];
goto P_0c0822d0;
P_0c0822c4: /* original 66e3, guest PC 0x0c0822c4 */
if(!s->budget--) { s->failed_pc=0x0c0822c4u; return 0; }
r[6]=r[14];
goto P_0c0822c6;
P_0c0822c6: /* original 66e3, guest PC 0x0c0822c6 */
if(!s->budget--) { s->failed_pc=0x0c0822c6u; return 0; }
r[6]=r[14];
goto P_0c0822c8;
P_0c0822c8: /* original e700, guest PC 0x0c0822c8 */
if(!s->budget--) { s->failed_pc=0x0c0822c8u; return 0; }
r[7]=0x00000000u;
goto P_0c0822ca;
P_0c0822ca: /* original 6b93, guest PC 0x0c0822ca */
if(!s->budget--) { s->failed_pc=0x0c0822cau; return 0; }
r[11]=r[9];
goto P_0c0822cc;
P_0c0822cc: /* original 2fc6, guest PC 0x0c0822cc */
if(!s->budget--) { s->failed_pc=0x0c0822ccu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0822ce;
P_0c0822ce: /* original 9519, guest PC 0x0c0822ce */
if(!s->budget--) { s->failed_pc=0x0c0822ceu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082304u,2);
goto P_0c0822d0;
P_0c0822d0: /* original 4d0b, guest PC 0x0c0822d0 */
if(!s->budget--) { s->failed_pc=0x0c0822d0u; return 0; }
target=r[13];
r[16]=code_base|0x0c0822d4u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0822d4u) { target=s->pc; goto dispatch; }
goto P_0c0822d4;
P_0c0822d2: /* original 64b3, guest PC 0x0c0822d2 */
if(!s->budget--) { s->failed_pc=0x0c0822d2u; return 0; }
r[4]=r[11];
goto P_0c0822d4;
P_0c0822d4: /* original 7f04, guest PC 0x0c0822d4 */
if(!s->budget--) { s->failed_pc=0x0c0822d4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0822d6;
P_0c0822d6: /* original 54f1, guest PC 0x0c0822d6 */
if(!s->budget--) { s->failed_pc=0x0c0822d6u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0822d8;
P_0c0822d8: /* original 7f0c, guest PC 0x0c0822d8 */
if(!s->budget--) { s->failed_pc=0x0c0822d8u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0822da;
P_0c0822da: /* original 4f26, guest PC 0x0c0822da */
if(!s->budget--) { s->failed_pc=0x0c0822dau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0822dc;
P_0c0822dc: /* original 65b3, guest PC 0x0c0822dc */
if(!s->budget--) { s->failed_pc=0x0c0822dcu; return 0; }
r[5]=r[11];
goto P_0c0822de;
P_0c0822de: /* original d30a, guest PC 0x0c0822de */
if(!s->budget--) { s->failed_pc=0x0c0822deu; return 0; }
r[3]=read(ram,0x0c082308u,4);
goto P_0c0822e0;
P_0c0822e0: /* original 69f6, guest PC 0x0c0822e0 */
if(!s->budget--) { s->failed_pc=0x0c0822e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0822e2;
P_0c0822e2: /* original 6af6, guest PC 0x0c0822e2 */
if(!s->budget--) { s->failed_pc=0x0c0822e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0822e4;
P_0c0822e4: /* original 6bf6, guest PC 0x0c0822e4 */
if(!s->budget--) { s->failed_pc=0x0c0822e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0822e6;
P_0c0822e6: /* original 6cf6, guest PC 0x0c0822e6 */
if(!s->budget--) { s->failed_pc=0x0c0822e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0822e8;
P_0c0822e8: /* original 6df6, guest PC 0x0c0822e8 */
if(!s->budget--) { s->failed_pc=0x0c0822e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0822ea;
P_0c0822ea: /* original 432b, guest PC 0x0c0822ea */
if(!s->budget--) { s->failed_pc=0x0c0822eau; return 0; }
target=r[3];
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
P_0c0822ec: /* original 6ef6, guest PC 0x0c0822ec */
if(!s->budget--) { s->failed_pc=0x0c0822ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0822eeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0822eeu; return 0; } return 1;
P_0c08230c: /* original 2fe6, guest PC 0x0c08230c */
if(!s->budget--) { s->failed_pc=0x0c08230cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08230e;
P_0c08230e: /* original ee00, guest PC 0x0c08230e */
if(!s->budget--) { s->failed_pc=0x0c08230eu; return 0; }
r[14]=0x00000000u;
goto P_0c082310;
P_0c082310: /* original 2fd6, guest PC 0x0c082310 */
if(!s->budget--) { s->failed_pc=0x0c082310u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082312;
P_0c082312: /* original 2fc6, guest PC 0x0c082312 */
if(!s->budget--) { s->failed_pc=0x0c082312u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082314;
P_0c082314: /* original 2fb6, guest PC 0x0c082314 */
if(!s->budget--) { s->failed_pc=0x0c082314u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082316;
P_0c082316: /* original 2fa6, guest PC 0x0c082316 */
if(!s->budget--) { s->failed_pc=0x0c082316u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082318;
P_0c082318: /* original 2f96, guest PC 0x0c082318 */
if(!s->budget--) { s->failed_pc=0x0c082318u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08231a;
P_0c08231a: /* original 2f86, guest PC 0x0c08231a */
if(!s->budget--) { s->failed_pc=0x0c08231au; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08231c;
P_0c08231c: /* original 4f22, guest PC 0x0c08231c */
if(!s->budget--) { s->failed_pc=0x0c08231cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08231e;
P_0c08231e: /* original dc66, guest PC 0x0c08231e */
if(!s->budget--) { s->failed_pc=0x0c08231eu; return 0; }
r[12]=read(ram,0x0c0824b8u,4);
goto P_0c082320;
P_0c082320: /* original 4f12, guest PC 0x0c082320 */
if(!s->budget--) { s->failed_pc=0x0c082320u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c082322;
P_0c082322: /* original 7fdc, guest PC 0x0c082322 */
if(!s->budget--) { s->failed_pc=0x0c082322u; return 0; }
r[15]+=0xffffffdcu;
goto P_0c082324;
P_0c082324: /* original 1f48, guest PC 0x0c082324 */
if(!s->budget--) { s->failed_pc=0x0c082324u; return 0; }
write(ram,r[15]+32,r[4],4);
goto P_0c082326;
P_0c082326: /* original d865, guest PC 0x0c082326 */
if(!s->budget--) { s->failed_pc=0x0c082326u; return 0; }
r[8]=read(ram,0x0c0824bcu,4);
goto P_0c082328;
P_0c082328: /* original 909f, guest PC 0x0c082328 */
if(!s->budget--) { s->failed_pc=0x0c082328u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08246au,2);
goto P_0c08232a;
P_0c08232a: /* original d365, guest PC 0x0c08232a */
if(!s->budget--) { s->failed_pc=0x0c08232au; return 0; }
r[3]=read(ram,0x0c0824c0u,4);
goto P_0c08232c;
P_0c08232c: /* original 018e, guest PC 0x0c08232c */
if(!s->budget--) { s->failed_pc=0x0c08232cu; return 0; }
r[1]=read(ram,r[8]+r[0],4);
goto P_0c08232e;
P_0c08232e: /* original 430b, guest PC 0x0c08232e */
if(!s->budget--) { s->failed_pc=0x0c08232eu; return 0; }
target=r[3];
r[16]=code_base|0x0c082332u;
r[0]=0x0000000du;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082332u) { target=s->pc; goto dispatch; }
goto P_0c082332;
P_0c082330: /* original e00d, guest PC 0x0c082330 */
if(!s->budget--) { s->failed_pc=0x0c082330u; return 0; }
r[0]=0x0000000du;
goto P_0c082332;
P_0c082332: /* original 2f02, guest PC 0x0c082332 */
if(!s->budget--) { s->failed_pc=0x0c082332u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c082334;
P_0c082334: /* original 909a, guest PC 0x0c082334 */
if(!s->budget--) { s->failed_pc=0x0c082334u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08246cu,2);
goto P_0c082336;
P_0c082336: /* original d362, guest PC 0x0c082336 */
if(!s->budget--) { s->failed_pc=0x0c082336u; return 0; }
r[3]=read(ram,0x0c0824c0u,4);
goto P_0c082338;
P_0c082338: /* original 018e, guest PC 0x0c082338 */
if(!s->budget--) { s->failed_pc=0x0c082338u; return 0; }
r[1]=read(ram,r[8]+r[0],4);
goto P_0c08233a;
P_0c08233a: /* original 430b, guest PC 0x0c08233a */
if(!s->budget--) { s->failed_pc=0x0c08233au; return 0; }
target=r[3];
r[16]=code_base|0x0c08233eu;
r[0]=0x0000000du;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08233eu) { target=s->pc; goto dispatch; }
goto P_0c08233e;
P_0c08233c: /* original e00d, guest PC 0x0c08233c */
if(!s->budget--) { s->failed_pc=0x0c08233cu; return 0; }
r[0]=0x0000000du;
goto P_0c08233e;
P_0c08233e: /* original 1f04, guest PC 0x0c08233e */
if(!s->budget--) { s->failed_pc=0x0c08233eu; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c082340;
P_0c082340: /* original d460, guest PC 0x0c082340 */
if(!s->budget--) { s->failed_pc=0x0c082340u; return 0; }
r[4]=read(ram,0x0c0824c4u,4);
goto P_0c082342;
P_0c082342: /* original 6343, guest PC 0x0c082342 */
if(!s->budget--) { s->failed_pc=0x0c082342u; return 0; }
r[3]=r[4];
goto P_0c082344;
P_0c082344: /* original 732c, guest PC 0x0c082344 */
if(!s->budget--) { s->failed_pc=0x0c082344u; return 0; }
r[3]+=0x0000002cu;
goto P_0c082346;
P_0c082346: /* original 6b43, guest PC 0x0c082346 */
if(!s->budget--) { s->failed_pc=0x0c082346u; return 0; }
r[11]=r[4];
goto P_0c082348;
P_0c082348: /* original 1f32, guest PC 0x0c082348 */
if(!s->budget--) { s->failed_pc=0x0c082348u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c08234a;
P_0c08234a: /* original d25f, guest PC 0x0c08234a */
if(!s->budget--) { s->failed_pc=0x0c08234au; return 0; }
r[2]=read(ram,0x0c0824c8u,4);
goto P_0c08234c;
P_0c08234c: /* original 6d43, guest PC 0x0c08234c */
if(!s->budget--) { s->failed_pc=0x0c08234cu; return 0; }
r[13]=r[4];
goto P_0c08234e;
P_0c08234e: /* original 7b58, guest PC 0x0c08234e */
if(!s->budget--) { s->failed_pc=0x0c08234eu; return 0; }
r[11]+=0x00000058u;
goto P_0c082350;
P_0c082350: /* original 420b, guest PC 0x0c082350 */
if(!s->budget--) { s->failed_pc=0x0c082350u; return 0; }
target=r[2];
r[16]=code_base|0x0c082354u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082354u) { target=s->pc; goto dispatch; }
goto P_0c082354;
P_0c082352: /* original 64b3, guest PC 0x0c082352 */
if(!s->budget--) { s->failed_pc=0x0c082352u; return 0; }
r[4]=r[11];
goto P_0c082354;
P_0c082354: /* original 53f2, guest PC 0x0c082354 */
if(!s->budget--) { s->failed_pc=0x0c082354u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c082356;
P_0c082356: /* original e026, guest PC 0x0c082356 */
if(!s->budget--) { s->failed_pc=0x0c082356u; return 0; }
r[0]=0x00000026u;
goto P_0c082358;
P_0c082358: /* original e202, guest PC 0x0c082358 */
if(!s->budget--) { s->failed_pc=0x0c082358u; return 0; }
r[2]=0x00000002u;
goto P_0c08235a;
P_0c08235a: /* original 0325, guest PC 0x0c08235a */
if(!s->budget--) { s->failed_pc=0x0c08235au; return 0; }
write(ram,r[3]+r[0],r[2],2);
goto P_0c08235c;
P_0c08235c: /* original e301, guest PC 0x0c08235c */
if(!s->budget--) { s->failed_pc=0x0c08235cu; return 0; }
r[3]=0x00000001u;
goto P_0c08235e;
P_0c08235e: /* original 0b35, guest PC 0x0c08235e */
if(!s->budget--) { s->failed_pc=0x0c08235eu; return 0; }
write(ram,r[11]+r[0],r[3],2);
goto P_0c082360;
P_0c082360: /* original 6323, guest PC 0x0c082360 */
if(!s->budget--) { s->failed_pc=0x0c082360u; return 0; }
r[3]=r[2];
goto P_0c082362;
P_0c082362: /* original 0de5, guest PC 0x0c082362 */
if(!s->budget--) { s->failed_pc=0x0c082362u; return 0; }
write(ram,r[13]+r[0],r[14],2);
goto P_0c082364;
P_0c082364: /* original e022, guest PC 0x0c082364 */
if(!s->budget--) { s->failed_pc=0x0c082364u; return 0; }
r[0]=0x00000022u;
goto P_0c082366;
P_0c082366: /* original 02dd, guest PC 0x0c082366 */
if(!s->budget--) { s->failed_pc=0x0c082366u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c082368;
P_0c082368: /* original e640, guest PC 0x0c082368 */
if(!s->budget--) { s->failed_pc=0x0c082368u; return 0; }
r[6]=0x00000040u;
goto P_0c08236a;
P_0c08236a: /* original e709, guest PC 0x0c08236a */
if(!s->budget--) { s->failed_pc=0x0c08236au; return 0; }
r[7]=0x00000009u;
goto P_0c08236c;
P_0c08236c: /* original 223b, guest PC 0x0c08236c */
if(!s->budget--) { s->failed_pc=0x0c08236cu; return 0; }
r[2]|=r[3];
goto P_0c08236e;
P_0c08236e: /* original 0d25, guest PC 0x0c08236e */
if(!s->budget--) { s->failed_pc=0x0c08236eu; return 0; }
write(ram,r[13]+r[0],r[2],2);
goto P_0c082370;
P_0c082370: /* original 01bd, guest PC 0x0c082370 */
if(!s->budget--) { s->failed_pc=0x0c082370u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c082372;
P_0c082372: /* original 213b, guest PC 0x0c082372 */
if(!s->budget--) { s->failed_pc=0x0c082372u; return 0; }
r[1]|=r[3];
goto P_0c082374;
P_0c082374: /* original 0b15, guest PC 0x0c082374 */
if(!s->budget--) { s->failed_pc=0x0c082374u; return 0; }
write(ram,r[11]+r[0],r[1],2);
goto P_0c082376;
P_0c082376: /* original e022, guest PC 0x0c082376 */
if(!s->budget--) { s->failed_pc=0x0c082376u; return 0; }
r[0]=0x00000022u;
goto P_0c082378;
P_0c082378: /* original 52f2, guest PC 0x0c082378 */
if(!s->budget--) { s->failed_pc=0x0c082378u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c08237a;
P_0c08237a: /* original 012d, guest PC 0x0c08237a */
if(!s->budget--) { s->failed_pc=0x0c08237au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c08237c;
P_0c08237c: /* original 213b, guest PC 0x0c08237c */
if(!s->budget--) { s->failed_pc=0x0c08237cu; return 0; }
r[1]|=r[3];
goto P_0c08237e;
P_0c08237e: /* original 0215, guest PC 0x0c08237e */
if(!s->budget--) { s->failed_pc=0x0c08237eu; return 0; }
write(ram,r[2]+r[0],r[1],2);
goto P_0c082380;
P_0c082380: /* original e220, guest PC 0x0c082380 */
if(!s->budget--) { s->failed_pc=0x0c082380u; return 0; }
r[2]=0x00000020u;
goto P_0c082382;
P_0c082382: /* original 9a74, guest PC 0x0c082382 */
if(!s->budget--) { s->failed_pc=0x0c082382u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08246eu,2);
goto P_0c082384;
P_0c082384: /* original 2f26, guest PC 0x0c082384 */
if(!s->budget--) { s->failed_pc=0x0c082384u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082386;
P_0c082386: /* original d151, guest PC 0x0c082386 */
if(!s->budget--) { s->failed_pc=0x0c082386u; return 0; }
r[1]=read(ram,0x0c0824ccu,4);
goto P_0c082388;
P_0c082388: /* original 65a3, guest PC 0x0c082388 */
if(!s->budget--) { s->failed_pc=0x0c082388u; return 0; }
r[5]=r[10];
goto P_0c08238a;
P_0c08238a: /* original 410b, guest PC 0x0c08238a */
if(!s->budget--) { s->failed_pc=0x0c08238au; return 0; }
target=r[1];
r[16]=code_base|0x0c08238eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08238eu) { target=s->pc; goto dispatch; }
goto P_0c08238e;
P_0c08238c: /* original 64d3, guest PC 0x0c08238c */
if(!s->budget--) { s->failed_pc=0x0c08238cu; return 0; }
r[4]=r[13];
goto P_0c08238e;
P_0c08238e: /* original 946f, guest PC 0x0c08238e */
if(!s->budget--) { s->failed_pc=0x0c08238eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082470u,2);
goto P_0c082390;
P_0c082390: /* original 7f04, guest PC 0x0c082390 */
if(!s->budget--) { s->failed_pc=0x0c082390u; return 0; }
r[15]+=0x00000004u;
goto P_0c082392;
P_0c082392: /* original d94f, guest PC 0x0c082392 */
if(!s->budget--) { s->failed_pc=0x0c082392u; return 0; }
r[9]=read(ram,0x0c0824d0u,4);
goto P_0c082394;
P_0c082394: /* original 490b, guest PC 0x0c082394 */
if(!s->budget--) { s->failed_pc=0x0c082394u; return 0; }
target=r[9];
r[16]=code_base|0x0c082398u;
r[5]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082398u) { target=s->pc; goto dispatch; }
goto P_0c082398;
P_0c082396: /* original 65b3, guest PC 0x0c082396 */
if(!s->budget--) { s->failed_pc=0x0c082396u; return 0; }
r[5]=r[11];
goto P_0c082398;
P_0c082398: /* original 946b, guest PC 0x0c082398 */
if(!s->budget--) { s->failed_pc=0x0c082398u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082472u,2);
goto P_0c08239a;
P_0c08239a: /* original 490b, guest PC 0x0c08239a */
if(!s->budget--) { s->failed_pc=0x0c08239au; return 0; }
target=r[9];
r[16]=code_base|0x0c08239eu;
r[5]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08239eu) { target=s->pc; goto dispatch; }
goto P_0c08239e;
P_0c08239c: /* original 65b3, guest PC 0x0c08239c */
if(!s->budget--) { s->failed_pc=0x0c08239cu; return 0; }
r[5]=r[11];
goto P_0c08239e;
P_0c08239e: /* original 9469, guest PC 0x0c08239e */
if(!s->budget--) { s->failed_pc=0x0c08239eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082474u,2);
goto P_0c0823a0;
P_0c0823a0: /* original 490b, guest PC 0x0c0823a0 */
if(!s->budget--) { s->failed_pc=0x0c0823a0u; return 0; }
target=r[9];
r[16]=code_base|0x0c0823a4u;
r[5]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823a4u) { target=s->pc; goto dispatch; }
goto P_0c0823a4;
P_0c0823a2: /* original 65b3, guest PC 0x0c0823a2 */
if(!s->budget--) { s->failed_pc=0x0c0823a2u; return 0; }
r[5]=r[11];
goto P_0c0823a4;
P_0c0823a4: /* original 9467, guest PC 0x0c0823a4 */
if(!s->budget--) { s->failed_pc=0x0c0823a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082476u,2);
goto P_0c0823a6;
P_0c0823a6: /* original 490b, guest PC 0x0c0823a6 */
if(!s->budget--) { s->failed_pc=0x0c0823a6u; return 0; }
target=r[9];
r[16]=code_base|0x0c0823aau;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823aau) { target=s->pc; goto dispatch; }
goto P_0c0823aa;
P_0c0823a8: /* original 65d3, guest PC 0x0c0823a8 */
if(!s->budget--) { s->failed_pc=0x0c0823a8u; return 0; }
r[5]=r[13];
goto P_0c0823aa;
P_0c0823aa: /* original 9465, guest PC 0x0c0823aa */
if(!s->budget--) { s->failed_pc=0x0c0823aau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082478u,2);
goto P_0c0823ac;
P_0c0823ac: /* original 490b, guest PC 0x0c0823ac */
if(!s->budget--) { s->failed_pc=0x0c0823acu; return 0; }
target=r[9];
r[16]=code_base|0x0c0823b0u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823b0u) { target=s->pc; goto dispatch; }
goto P_0c0823b0;
P_0c0823ae: /* original 65d3, guest PC 0x0c0823ae */
if(!s->budget--) { s->failed_pc=0x0c0823aeu; return 0; }
r[5]=r[13];
goto P_0c0823b0;
P_0c0823b0: /* original 9463, guest PC 0x0c0823b0 */
if(!s->budget--) { s->failed_pc=0x0c0823b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08247au,2);
goto P_0c0823b2;
P_0c0823b2: /* original 490b, guest PC 0x0c0823b2 */
if(!s->budget--) { s->failed_pc=0x0c0823b2u; return 0; }
target=r[9];
r[16]=code_base|0x0c0823b6u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823b6u) { target=s->pc; goto dispatch; }
goto P_0c0823b6;
P_0c0823b4: /* original 65d3, guest PC 0x0c0823b4 */
if(!s->budget--) { s->failed_pc=0x0c0823b4u; return 0; }
r[5]=r[13];
goto P_0c0823b6;
P_0c0823b6: /* original 9461, guest PC 0x0c0823b6 */
if(!s->budget--) { s->failed_pc=0x0c0823b6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08247cu,2);
goto P_0c0823b8;
P_0c0823b8: /* original 490b, guest PC 0x0c0823b8 */
if(!s->budget--) { s->failed_pc=0x0c0823b8u; return 0; }
target=r[9];
r[16]=code_base|0x0c0823bcu;
r[5]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823bcu) { target=s->pc; goto dispatch; }
goto P_0c0823bc;
P_0c0823ba: /* original 65b3, guest PC 0x0c0823ba */
if(!s->budget--) { s->failed_pc=0x0c0823bau; return 0; }
r[5]=r[11];
goto P_0c0823bc;
P_0c0823bc: /* original 945f, guest PC 0x0c0823bc */
if(!s->budget--) { s->failed_pc=0x0c0823bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08247eu,2);
goto P_0c0823be;
P_0c0823be: /* original 490b, guest PC 0x0c0823be */
if(!s->budget--) { s->failed_pc=0x0c0823beu; return 0; }
target=r[9];
r[16]=code_base|0x0c0823c2u;
r[5]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823c2u) { target=s->pc; goto dispatch; }
goto P_0c0823c2;
P_0c0823c0: /* original 65b3, guest PC 0x0c0823c0 */
if(!s->budget--) { s->failed_pc=0x0c0823c0u; return 0; }
r[5]=r[11];
goto P_0c0823c2;
P_0c0823c2: /* original 945d, guest PC 0x0c0823c2 */
if(!s->budget--) { s->failed_pc=0x0c0823c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082480u,2);
goto P_0c0823c4;
P_0c0823c4: /* original 490b, guest PC 0x0c0823c4 */
if(!s->budget--) { s->failed_pc=0x0c0823c4u; return 0; }
target=r[9];
r[16]=code_base|0x0c0823c8u;
r[5]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823c8u) { target=s->pc; goto dispatch; }
goto P_0c0823c8;
P_0c0823c6: /* original 65b3, guest PC 0x0c0823c6 */
if(!s->budget--) { s->failed_pc=0x0c0823c6u; return 0; }
r[5]=r[11];
goto P_0c0823c8;
P_0c0823c8: /* original 945b, guest PC 0x0c0823c8 */
if(!s->budget--) { s->failed_pc=0x0c0823c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082482u,2);
goto P_0c0823ca;
P_0c0823ca: /* original 490b, guest PC 0x0c0823ca */
if(!s->budget--) { s->failed_pc=0x0c0823cau; return 0; }
target=r[9];
r[16]=code_base|0x0c0823ceu;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823ceu) { target=s->pc; goto dispatch; }
goto P_0c0823ce;
P_0c0823cc: /* original 65d3, guest PC 0x0c0823cc */
if(!s->budget--) { s->failed_pc=0x0c0823ccu; return 0; }
r[5]=r[13];
goto P_0c0823ce;
P_0c0823ce: /* original 9459, guest PC 0x0c0823ce */
if(!s->budget--) { s->failed_pc=0x0c0823ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082484u,2);
goto P_0c0823d0;
P_0c0823d0: /* original 490b, guest PC 0x0c0823d0 */
if(!s->budget--) { s->failed_pc=0x0c0823d0u; return 0; }
target=r[9];
r[16]=code_base|0x0c0823d4u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823d4u) { target=s->pc; goto dispatch; }
goto P_0c0823d4;
P_0c0823d2: /* original 65d3, guest PC 0x0c0823d2 */
if(!s->budget--) { s->failed_pc=0x0c0823d2u; return 0; }
r[5]=r[13];
goto P_0c0823d4;
P_0c0823d4: /* original 9457, guest PC 0x0c0823d4 */
if(!s->budget--) { s->failed_pc=0x0c0823d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082486u,2);
goto P_0c0823d6;
P_0c0823d6: /* original 490b, guest PC 0x0c0823d6 */
if(!s->budget--) { s->failed_pc=0x0c0823d6u; return 0; }
target=r[9];
r[16]=code_base|0x0c0823dau;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823dau) { target=s->pc; goto dispatch; }
goto P_0c0823da;
P_0c0823d8: /* original 65d3, guest PC 0x0c0823d8 */
if(!s->budget--) { s->failed_pc=0x0c0823d8u; return 0; }
r[5]=r[13];
goto P_0c0823da;
P_0c0823da: /* original 9455, guest PC 0x0c0823da */
if(!s->budget--) { s->failed_pc=0x0c0823dau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082488u,2);
goto P_0c0823dc;
P_0c0823dc: /* original 490b, guest PC 0x0c0823dc */
if(!s->budget--) { s->failed_pc=0x0c0823dcu; return 0; }
target=r[9];
r[16]=code_base|0x0c0823e0u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823e0u) { target=s->pc; goto dispatch; }
goto P_0c0823e0;
P_0c0823de: /* original 65d3, guest PC 0x0c0823de */
if(!s->budget--) { s->failed_pc=0x0c0823deu; return 0; }
r[5]=r[13];
goto P_0c0823e0;
P_0c0823e0: /* original 9453, guest PC 0x0c0823e0 */
if(!s->budget--) { s->failed_pc=0x0c0823e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08248au,2);
goto P_0c0823e2;
P_0c0823e2: /* original 490b, guest PC 0x0c0823e2 */
if(!s->budget--) { s->failed_pc=0x0c0823e2u; return 0; }
target=r[9];
r[16]=code_base|0x0c0823e6u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823e6u) { target=s->pc; goto dispatch; }
goto P_0c0823e6;
P_0c0823e4: /* original 65d3, guest PC 0x0c0823e4 */
if(!s->budget--) { s->failed_pc=0x0c0823e4u; return 0; }
r[5]=r[13];
goto P_0c0823e6;
P_0c0823e6: /* original 9451, guest PC 0x0c0823e6 */
if(!s->budget--) { s->failed_pc=0x0c0823e6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08248cu,2);
goto P_0c0823e8;
P_0c0823e8: /* original 490b, guest PC 0x0c0823e8 */
if(!s->budget--) { s->failed_pc=0x0c0823e8u; return 0; }
target=r[9];
r[16]=code_base|0x0c0823ecu;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823ecu) { target=s->pc; goto dispatch; }
goto P_0c0823ec;
P_0c0823ea: /* original 65d3, guest PC 0x0c0823ea */
if(!s->budget--) { s->failed_pc=0x0c0823eau; return 0; }
r[5]=r[13];
goto P_0c0823ec;
P_0c0823ec: /* original 944f, guest PC 0x0c0823ec */
if(!s->budget--) { s->failed_pc=0x0c0823ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08248eu,2);
goto P_0c0823ee;
P_0c0823ee: /* original 490b, guest PC 0x0c0823ee */
if(!s->budget--) { s->failed_pc=0x0c0823eeu; return 0; }
target=r[9];
r[16]=code_base|0x0c0823f2u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823f2u) { target=s->pc; goto dispatch; }
goto P_0c0823f2;
P_0c0823f0: /* original 65d3, guest PC 0x0c0823f0 */
if(!s->budget--) { s->failed_pc=0x0c0823f0u; return 0; }
r[5]=r[13];
goto P_0c0823f2;
P_0c0823f2: /* original 944d, guest PC 0x0c0823f2 */
if(!s->budget--) { s->failed_pc=0x0c0823f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082490u,2);
goto P_0c0823f4;
P_0c0823f4: /* original 490b, guest PC 0x0c0823f4 */
if(!s->budget--) { s->failed_pc=0x0c0823f4u; return 0; }
target=r[9];
r[16]=code_base|0x0c0823f8u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823f8u) { target=s->pc; goto dispatch; }
goto P_0c0823f8;
P_0c0823f6: /* original 65d3, guest PC 0x0c0823f6 */
if(!s->budget--) { s->failed_pc=0x0c0823f6u; return 0; }
r[5]=r[13];
goto P_0c0823f8;
P_0c0823f8: /* original 944b, guest PC 0x0c0823f8 */
if(!s->budget--) { s->failed_pc=0x0c0823f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082492u,2);
goto P_0c0823fa;
P_0c0823fa: /* original 490b, guest PC 0x0c0823fa */
if(!s->budget--) { s->failed_pc=0x0c0823fau; return 0; }
target=r[9];
r[16]=code_base|0x0c0823feu;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823feu) { target=s->pc; goto dispatch; }
goto P_0c0823fe;
P_0c0823fc: /* original 65d3, guest PC 0x0c0823fc */
if(!s->budget--) { s->failed_pc=0x0c0823fcu; return 0; }
r[5]=r[13];
goto P_0c0823fe;
P_0c0823fe: /* original 9449, guest PC 0x0c0823fe */
if(!s->budget--) { s->failed_pc=0x0c0823feu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082494u,2);
goto P_0c082400;
P_0c082400: /* original 490b, guest PC 0x0c082400 */
if(!s->budget--) { s->failed_pc=0x0c082400u; return 0; }
target=r[9];
r[16]=code_base|0x0c082404u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082404u) { target=s->pc; goto dispatch; }
goto P_0c082404;
P_0c082402: /* original 65d3, guest PC 0x0c082402 */
if(!s->budget--) { s->failed_pc=0x0c082402u; return 0; }
r[5]=r[13];
goto P_0c082404;
P_0c082404: /* original 9447, guest PC 0x0c082404 */
if(!s->budget--) { s->failed_pc=0x0c082404u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082496u,2);
goto P_0c082406;
P_0c082406: /* original 490b, guest PC 0x0c082406 */
if(!s->budget--) { s->failed_pc=0x0c082406u; return 0; }
target=r[9];
r[16]=code_base|0x0c08240au;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08240au) { target=s->pc; goto dispatch; }
goto P_0c08240a;
P_0c082408: /* original 65d3, guest PC 0x0c082408 */
if(!s->budget--) { s->failed_pc=0x0c082408u; return 0; }
r[5]=r[13];
goto P_0c08240a;
P_0c08240a: /* original 9445, guest PC 0x0c08240a */
if(!s->budget--) { s->failed_pc=0x0c08240au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082498u,2);
goto P_0c08240c;
P_0c08240c: /* original 490b, guest PC 0x0c08240c */
if(!s->budget--) { s->failed_pc=0x0c08240cu; return 0; }
target=r[9];
r[16]=code_base|0x0c082410u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082410u) { target=s->pc; goto dispatch; }
goto P_0c082410;
P_0c08240e: /* original 65d3, guest PC 0x0c08240e */
if(!s->budget--) { s->failed_pc=0x0c08240eu; return 0; }
r[5]=r[13];
goto P_0c082410;
P_0c082410: /* original 9443, guest PC 0x0c082410 */
if(!s->budget--) { s->failed_pc=0x0c082410u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08249au,2);
goto P_0c082412;
P_0c082412: /* original 490b, guest PC 0x0c082412 */
if(!s->budget--) { s->failed_pc=0x0c082412u; return 0; }
target=r[9];
r[16]=code_base|0x0c082416u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082416u) { target=s->pc; goto dispatch; }
goto P_0c082416;
P_0c082414: /* original 65d3, guest PC 0x0c082414 */
if(!s->budget--) { s->failed_pc=0x0c082414u; return 0; }
r[5]=r[13];
goto P_0c082416;
P_0c082416: /* original 9441, guest PC 0x0c082416 */
if(!s->budget--) { s->failed_pc=0x0c082416u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08249cu,2);
goto P_0c082418;
P_0c082418: /* original 490b, guest PC 0x0c082418 */
if(!s->budget--) { s->failed_pc=0x0c082418u; return 0; }
target=r[9];
r[16]=code_base|0x0c08241cu;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08241cu) { target=s->pc; goto dispatch; }
goto P_0c08241c;
P_0c08241a: /* original 65d3, guest PC 0x0c08241a */
if(!s->budget--) { s->failed_pc=0x0c08241au; return 0; }
r[5]=r[13];
goto P_0c08241c;
P_0c08241c: /* original 943f, guest PC 0x0c08241c */
if(!s->budget--) { s->failed_pc=0x0c08241cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08249eu,2);
goto P_0c08241e;
P_0c08241e: /* original 490b, guest PC 0x0c08241e */
if(!s->budget--) { s->failed_pc=0x0c08241eu; return 0; }
target=r[9];
r[16]=code_base|0x0c082422u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082422u) { target=s->pc; goto dispatch; }
goto P_0c082422;
P_0c082420: /* original 65d3, guest PC 0x0c082420 */
if(!s->budget--) { s->failed_pc=0x0c082420u; return 0; }
r[5]=r[13];
goto P_0c082422;
P_0c082422: /* original 943d, guest PC 0x0c082422 */
if(!s->budget--) { s->failed_pc=0x0c082422u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0824a0u,2);
goto P_0c082424;
P_0c082424: /* original 490b, guest PC 0x0c082424 */
if(!s->budget--) { s->failed_pc=0x0c082424u; return 0; }
target=r[9];
r[16]=code_base|0x0c082428u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082428u) { target=s->pc; goto dispatch; }
goto P_0c082428;
P_0c082426: /* original 65d3, guest PC 0x0c082426 */
if(!s->budget--) { s->failed_pc=0x0c082426u; return 0; }
r[5]=r[13];
goto P_0c082428;
P_0c082428: /* original 943b, guest PC 0x0c082428 */
if(!s->budget--) { s->failed_pc=0x0c082428u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0824a2u,2);
goto P_0c08242a;
P_0c08242a: /* original 490b, guest PC 0x0c08242a */
if(!s->budget--) { s->failed_pc=0x0c08242au; return 0; }
target=r[9];
r[16]=code_base|0x0c08242eu;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08242eu) { target=s->pc; goto dispatch; }
goto P_0c08242e;
P_0c08242c: /* original 65d3, guest PC 0x0c08242c */
if(!s->budget--) { s->failed_pc=0x0c08242cu; return 0; }
r[5]=r[13];
goto P_0c08242e;
P_0c08242e: /* original 9439, guest PC 0x0c08242e */
if(!s->budget--) { s->failed_pc=0x0c08242eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0824a4u,2);
goto P_0c082430;
P_0c082430: /* original 490b, guest PC 0x0c082430 */
if(!s->budget--) { s->failed_pc=0x0c082430u; return 0; }
target=r[9];
r[16]=code_base|0x0c082434u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082434u) { target=s->pc; goto dispatch; }
goto P_0c082434;
P_0c082432: /* original 65d3, guest PC 0x0c082432 */
if(!s->budget--) { s->failed_pc=0x0c082432u; return 0; }
r[5]=r[13];
goto P_0c082434;
P_0c082434: /* original 9437, guest PC 0x0c082434 */
if(!s->budget--) { s->failed_pc=0x0c082434u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0824a6u,2);
goto P_0c082436;
P_0c082436: /* original 490b, guest PC 0x0c082436 */
if(!s->budget--) { s->failed_pc=0x0c082436u; return 0; }
target=r[9];
r[16]=code_base|0x0c08243au;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08243au) { target=s->pc; goto dispatch; }
goto P_0c08243a;
P_0c082438: /* original 65d3, guest PC 0x0c082438 */
if(!s->budget--) { s->failed_pc=0x0c082438u; return 0; }
r[5]=r[13];
goto P_0c08243a;
P_0c08243a: /* original 9435, guest PC 0x0c08243a */
if(!s->budget--) { s->failed_pc=0x0c08243au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0824a8u,2);
goto P_0c08243c;
P_0c08243c: /* original 490b, guest PC 0x0c08243c */
if(!s->budget--) { s->failed_pc=0x0c08243cu; return 0; }
target=r[9];
r[16]=code_base|0x0c082440u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082440u) { target=s->pc; goto dispatch; }
goto P_0c082440;
P_0c08243e: /* original 65d3, guest PC 0x0c08243e */
if(!s->budget--) { s->failed_pc=0x0c08243eu; return 0; }
r[5]=r[13];
goto P_0c082440;
P_0c082440: /* original 9433, guest PC 0x0c082440 */
if(!s->budget--) { s->failed_pc=0x0c082440u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0824aau,2);
goto P_0c082442;
P_0c082442: /* original 490b, guest PC 0x0c082442 */
if(!s->budget--) { s->failed_pc=0x0c082442u; return 0; }
target=r[9];
r[16]=code_base|0x0c082446u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082446u) { target=s->pc; goto dispatch; }
goto P_0c082446;
P_0c082444: /* original 65d3, guest PC 0x0c082444 */
if(!s->budget--) { s->failed_pc=0x0c082444u; return 0; }
r[5]=r[13];
goto P_0c082446;
P_0c082446: /* original 9431, guest PC 0x0c082446 */
if(!s->budget--) { s->failed_pc=0x0c082446u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0824acu,2);
goto P_0c082448;
P_0c082448: /* original 490b, guest PC 0x0c082448 */
if(!s->budget--) { s->failed_pc=0x0c082448u; return 0; }
target=r[9];
r[16]=code_base|0x0c08244cu;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08244cu) { target=s->pc; goto dispatch; }
goto P_0c08244c;
P_0c08244a: /* original 65d3, guest PC 0x0c08244a */
if(!s->budget--) { s->failed_pc=0x0c08244au; return 0; }
r[5]=r[13];
goto P_0c08244c;
P_0c08244c: /* original 942f, guest PC 0x0c08244c */
if(!s->budget--) { s->failed_pc=0x0c08244cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0824aeu,2);
goto P_0c08244e;
P_0c08244e: /* original 490b, guest PC 0x0c08244e */
if(!s->budget--) { s->failed_pc=0x0c08244eu; return 0; }
target=r[9];
r[16]=code_base|0x0c082452u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082452u) { target=s->pc; goto dispatch; }
goto P_0c082452;
P_0c082450: /* original 65d3, guest PC 0x0c082450 */
if(!s->budget--) { s->failed_pc=0x0c082450u; return 0; }
r[5]=r[13];
goto P_0c082452;
P_0c082452: /* original 942d, guest PC 0x0c082452 */
if(!s->budget--) { s->failed_pc=0x0c082452u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0824b0u,2);
goto P_0c082454;
P_0c082454: /* original 490b, guest PC 0x0c082454 */
if(!s->budget--) { s->failed_pc=0x0c082454u; return 0; }
target=r[9];
r[16]=code_base|0x0c082458u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082458u) { target=s->pc; goto dispatch; }
goto P_0c082458;
P_0c082456: /* original 65d3, guest PC 0x0c082456 */
if(!s->budget--) { s->failed_pc=0x0c082456u; return 0; }
r[5]=r[13];
goto P_0c082458;
P_0c082458: /* original 942b, guest PC 0x0c082458 */
if(!s->budget--) { s->failed_pc=0x0c082458u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0824b2u,2);
goto P_0c08245a;
P_0c08245a: /* original 490b, guest PC 0x0c08245a */
if(!s->budget--) { s->failed_pc=0x0c08245au; return 0; }
target=r[9];
r[16]=code_base|0x0c08245eu;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08245eu) { target=s->pc; goto dispatch; }
goto P_0c08245e;
P_0c08245c: /* original 65d3, guest PC 0x0c08245c */
if(!s->budget--) { s->failed_pc=0x0c08245cu; return 0; }
r[5]=r[13];
goto P_0c08245e;
P_0c08245e: /* original 9429, guest PC 0x0c08245e */
if(!s->budget--) { s->failed_pc=0x0c08245eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0824b4u,2);
goto P_0c082460;
P_0c082460: /* original 490b, guest PC 0x0c082460 */
if(!s->budget--) { s->failed_pc=0x0c082460u; return 0; }
target=r[9];
r[16]=code_base|0x0c082464u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082464u) { target=s->pc; goto dispatch; }
goto P_0c082464;
P_0c082462: /* original 65d3, guest PC 0x0c082462 */
if(!s->budget--) { s->failed_pc=0x0c082462u; return 0; }
r[5]=r[13];
goto P_0c082464;
P_0c082464: /* original 1fe3, guest PC 0x0c082464 */
if(!s->budget--) { s->failed_pc=0x0c082464u; return 0; }
write(ram,r[15]+12,r[14],4);
goto P_0c082466;
P_0c082466: /* original a041, guest PC 0x0c082466 */
if(!s->budget--) { s->failed_pc=0x0c082466u; return 0; }
r[9]=r[14];
goto P_0c0824ec;
P_0c082468: /* original 69e3, guest PC 0x0c082468 */
if(!s->budget--) { s->failed_pc=0x0c082468u; return 0; }
r[9]=r[14];
if(!vf3_matrix_family(0x0c08246au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08246au; return 0; } return 1;
P_0c0824d4: /* original 2fe6, guest PC 0x0c0824d4 */
if(!s->budget--) { s->failed_pc=0x0c0824d4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0824d6;
P_0c0824d6: /* original 6a93, guest PC 0x0c0824d6 */
if(!s->budget--) { s->failed_pc=0x0c0824d6u; return 0; }
r[10]=r[9];
goto P_0c0824d8;
P_0c0824d8: /* original 56f3, guest PC 0x0c0824d8 */
if(!s->budget--) { s->failed_pc=0x0c0824d8u; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c0824da;
P_0c0824da: /* original e700, guest PC 0x0c0824da */
if(!s->budget--) { s->failed_pc=0x0c0824dau; return 0; }
r[7]=0x00000000u;
goto P_0c0824dc;
P_0c0824dc: /* original 9529, guest PC 0x0c0824dc */
if(!s->budget--) { s->failed_pc=0x0c0824dcu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082532u,2);
goto P_0c0824de;
P_0c0824de: /* original 4c0b, guest PC 0x0c0824de */
if(!s->budget--) { s->failed_pc=0x0c0824deu; return 0; }
target=r[12];
r[16]=code_base|0x0c0824e2u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0824e2u) { target=s->pc; goto dispatch; }
goto P_0c0824e2;
P_0c0824e0: /* original 64a3, guest PC 0x0c0824e0 */
if(!s->budget--) { s->failed_pc=0x0c0824e0u; return 0; }
r[4]=r[10];
goto P_0c0824e2;
P_0c0824e2: /* original 7f04, guest PC 0x0c0824e2 */
if(!s->budget--) { s->failed_pc=0x0c0824e2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0824e4;
P_0c0824e4: /* original 53f3, guest PC 0x0c0824e4 */
if(!s->budget--) { s->failed_pc=0x0c0824e4u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0824e6;
P_0c0824e6: /* original 7910, guest PC 0x0c0824e6 */
if(!s->budget--) { s->failed_pc=0x0c0824e6u; return 0; }
r[9]+=0x00000010u;
goto P_0c0824e8;
P_0c0824e8: /* original 7301, guest PC 0x0c0824e8 */
if(!s->budget--) { s->failed_pc=0x0c0824e8u; return 0; }
r[3]+=0x00000001u;
goto P_0c0824ea;
P_0c0824ea: /* original 1f33, guest PC 0x0c0824ea */
if(!s->budget--) { s->failed_pc=0x0c0824eau; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0824ec;
P_0c0824ec: /* original 52f3, guest PC 0x0c0824ec */
if(!s->budget--) { s->failed_pc=0x0c0824ecu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0824ee;
P_0c0824ee: /* original e308, guest PC 0x0c0824ee */
if(!s->budget--) { s->failed_pc=0x0c0824eeu; return 0; }
r[3]=0x00000008u;
goto P_0c0824f0;
P_0c0824f0: /* original 3233, guest PC 0x0c0824f0 */
if(!s->budget--) { s->failed_pc=0x0c0824f0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c0824f2;
P_0c0824f2: /* original 8bef, guest PC 0x0c0824f2 */
if(!s->budget--) { s->failed_pc=0x0c0824f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0824d4; }
goto P_0c0824f4;
P_0c0824f4: /* original 60f2, guest PC 0x0c0824f4 */
if(!s->budget--) { s->failed_pc=0x0c0824f4u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0824f6;
P_0c0824f6: /* original d910, guest PC 0x0c0824f6 */
if(!s->budget--) { s->failed_pc=0x0c0824f6u; return 0; }
r[9]=read(ram,0x0c082538u,4);
goto P_0c0824f8;
P_0c0824f8: /* original 4008, guest PC 0x0c0824f8 */
if(!s->budget--) { s->failed_pc=0x0c0824f8u; return 0; }
r[0]<<=2;
goto P_0c0824fa;
P_0c0824fa: /* original d510, guest PC 0x0c0824fa */
if(!s->budget--) { s->failed_pc=0x0c0824fau; return 0; }
r[5]=read(ram,0x0c08253cu,4);
goto P_0c0824fc;
P_0c0824fc: /* original d410, guest PC 0x0c0824fc */
if(!s->budget--) { s->failed_pc=0x0c0824fcu; return 0; }
r[4]=read(ram,0x0c082540u,4);
goto P_0c0824fe;
P_0c0824fe: /* original 1f03, guest PC 0x0c0824fe */
if(!s->budget--) { s->failed_pc=0x0c0824feu; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c082500;
P_0c082500: /* original 50f4, guest PC 0x0c082500 */
if(!s->budget--) { s->failed_pc=0x0c082500u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c082502;
P_0c082502: /* original 4008, guest PC 0x0c082502 */
if(!s->budget--) { s->failed_pc=0x0c082502u; return 0; }
r[0]<<=2;
goto P_0c082504;
P_0c082504: /* original 1f02, guest PC 0x0c082504 */
if(!s->budget--) { s->failed_pc=0x0c082504u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c082506;
P_0c082506: /* original 9015, guest PC 0x0c082506 */
if(!s->budget--) { s->failed_pc=0x0c082506u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082534u,2);
goto P_0c082508;
P_0c082508: /* original 008e, guest PC 0x0c082508 */
if(!s->budget--) { s->failed_pc=0x0c082508u; return 0; }
r[0]=read(ram,r[8]+r[0],4);
goto P_0c08250a;
P_0c08250a: /* original 8800, guest PC 0x0c08250a */
if(!s->budget--) { s->failed_pc=0x0c08250au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c08250c;
P_0c08250c: /* original 890d, guest PC 0x0c08250c */
if(!s->budget--) { s->failed_pc=0x0c08250cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08252a; }
goto P_0c08250e;
P_0c08250e: /* original 8801, guest PC 0x0c08250e */
if(!s->budget--) { s->failed_pc=0x0c08250eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c082510;
P_0c082510: /* original 8b01, guest PC 0x0c082510 */
if(!s->budget--) { s->failed_pc=0x0c082510u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c082516; }
goto P_0c082512;
P_0c082512: /* original a0c7, guest PC 0x0c082512 */
if(!s->budget--) { s->failed_pc=0x0c082512u; return 0; }
goto P_0c0826a4;
P_0c082514: /* original 0009, guest PC 0x0c082514 */
if(!s->budget--) { s->failed_pc=0x0c082514u; return 0; }
goto P_0c082516;
P_0c082516: /* original 8802, guest PC 0x0c082516 */
if(!s->budget--) { s->failed_pc=0x0c082516u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c082518;
P_0c082518: /* original 8b01, guest PC 0x0c082518 */
if(!s->budget--) { s->failed_pc=0x0c082518u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08251e; }
goto P_0c08251a;
P_0c08251a: /* original a183, guest PC 0x0c08251a */
if(!s->budget--) { s->failed_pc=0x0c08251au; return 0; }
goto P_0c082824;
P_0c08251c: /* original 0009, guest PC 0x0c08251c */
if(!s->budget--) { s->failed_pc=0x0c08251cu; return 0; }
goto P_0c08251e;
P_0c08251e: /* original 8803, guest PC 0x0c08251e */
if(!s->budget--) { s->failed_pc=0x0c08251eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c082520;
P_0c082520: /* original 8b01, guest PC 0x0c082520 */
if(!s->budget--) { s->failed_pc=0x0c082520u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c082526; }
goto P_0c082522;
P_0c082522: /* original a268, guest PC 0x0c082522 */
if(!s->budget--) { s->failed_pc=0x0c082522u; return 0; }
goto P_0c0829f6;
P_0c082524: /* original 0009, guest PC 0x0c082524 */
if(!s->budget--) { s->failed_pc=0x0c082524u; return 0; }
goto P_0c082526;
P_0c082526: /* original a32c, guest PC 0x0c082526 */
if(!s->budget--) { s->failed_pc=0x0c082526u; return 0; }
goto P_0c082b82;
P_0c082528: /* original 0009, guest PC 0x0c082528 */
if(!s->budget--) { s->failed_pc=0x0c082528u; return 0; }
goto P_0c08252a;
P_0c08252a: /* original 1fe2, guest PC 0x0c08252a */
if(!s->budget--) { s->failed_pc=0x0c08252au; return 0; }
write(ram,r[15]+8,r[14],4);
goto P_0c08252c;
P_0c08252c: /* original 1f55, guest PC 0x0c08252c */
if(!s->budget--) { s->failed_pc=0x0c08252cu; return 0; }
write(ram,r[15]+20,r[5],4);
goto P_0c08252e;
P_0c08252e: /* original a04a, guest PC 0x0c08252e */
if(!s->budget--) { s->failed_pc=0x0c08252eu; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c0825c6;
P_0c082530: /* original 1f44, guest PC 0x0c082530 */
if(!s->budget--) { s->failed_pc=0x0c082530u; return 0; }
write(ram,r[15]+16,r[4],4);
if(!vf3_matrix_family(0x0c082532u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c082532u; return 0; } return 1;
P_0c082544: /* original 5af4, guest PC 0x0c082544 */
if(!s->budget--) { s->failed_pc=0x0c082544u; return 0; }
r[10]=read(ram,r[15]+16,4);
goto P_0c082546;
P_0c082546: /* original 7a04, guest PC 0x0c082546 */
if(!s->budget--) { s->failed_pc=0x0c082546u; return 0; }
r[10]+=0x00000004u;
goto P_0c082548;
P_0c082548: /* original 1fa4, guest PC 0x0c082548 */
if(!s->budget--) { s->failed_pc=0x0c082548u; return 0; }
write(ram,r[15]+16,r[10],4);
goto P_0c08254a;
P_0c08254a: /* original 7afc, guest PC 0x0c08254a */
if(!s->budget--) { s->failed_pc=0x0c08254au; return 0; }
r[10]+=0xfffffffcu;
goto P_0c08254c;
P_0c08254c: /* original 55f5, guest PC 0x0c08254c */
if(!s->budget--) { s->failed_pc=0x0c08254cu; return 0; }
r[5]=read(ram,r[15]+20,4);
goto P_0c08254e;
P_0c08254e: /* original 5483, guest PC 0x0c08254e */
if(!s->budget--) { s->failed_pc=0x0c08254eu; return 0; }
r[4]=read(ram,r[8]+12,4);
goto P_0c082550;
P_0c082550: /* original 7508, guest PC 0x0c082550 */
if(!s->budget--) { s->failed_pc=0x0c082550u; return 0; }
r[5]+=0x00000008u;
goto P_0c082552;
P_0c082552: /* original 6aa2, guest PC 0x0c082552 */
if(!s->budget--) { s->failed_pc=0x0c082552u; return 0; }
tmp=read(ram,r[10],4);
r[10]=tmp;
goto P_0c082554;
P_0c082554: /* original 1f55, guest PC 0x0c082554 */
if(!s->budget--) { s->failed_pc=0x0c082554u; return 0; }
write(ram,r[15]+20,r[5],4);
goto P_0c082556;
P_0c082556: /* original 75f8, guest PC 0x0c082556 */
if(!s->budget--) { s->failed_pc=0x0c082556u; return 0; }
r[5]+=0xfffffff8u;
goto P_0c082558;
P_0c082558: /* original 644b, guest PC 0x0c082558 */
if(!s->budget--) { s->failed_pc=0x0c082558u; return 0; }
r[4]=0u-r[4];
goto P_0c08255a;
P_0c08255a: /* original 5351, guest PC 0x0c08255a */
if(!s->budget--) { s->failed_pc=0x0c08255au; return 0; }
r[3]=read(ram,r[5]+4,4);
goto P_0c08255c;
P_0c08255c: /* original 7420, guest PC 0x0c08255c */
if(!s->budget--) { s->failed_pc=0x0c08255cu; return 0; }
r[4]+=0x00000020u;
goto P_0c08255e;
P_0c08255e: /* original 3438, guest PC 0x0c08255e */
if(!s->budget--) { s->failed_pc=0x0c08255eu; return 0; }
r[4]-=r[3];
goto P_0c082560;
P_0c082560: /* original 4411, guest PC 0x0c082560 */
if(!s->budget--) { s->failed_pc=0x0c082560u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c082562;
P_0c082562: /* original 8f2d, guest PC 0x0c082562 */
if(!s->budget--) { s->failed_pc=0x0c082562u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[5],4);
r[6]=tmp;
if(!cond) { goto P_0c0825c0; }
goto P_0c082566;
P_0c082564: /* original 6652, guest PC 0x0c082564 */
if(!s->budget--) { s->failed_pc=0x0c082564u; return 0; }
tmp=read(ram,r[5],4);
r[6]=tmp;
goto P_0c082566;
P_0c082566: /* original d04c, guest PC 0x0c082566 */
if(!s->budget--) { s->failed_pc=0x0c082566u; return 0; }
r[0]=read(ram,0x0c082698u,4);
goto P_0c082568;
P_0c082568: /* original 65a3, guest PC 0x0c082568 */
if(!s->budget--) { s->failed_pc=0x0c082568u; return 0; }
r[5]=r[10];
goto P_0c08256a;
P_0c08256a: /* original 0647, guest PC 0x0c08256a */
if(!s->budget--) { s->failed_pc=0x0c08256au; return 0; }
r[19]=r[6]*r[4];
goto P_0c08256c;
P_0c08256c: /* original 4500, guest PC 0x0c08256c */
if(!s->budget--) { s->failed_pc=0x0c08256cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c08256e;
P_0c08256e: /* original 055c, guest PC 0x0c08256e */
if(!s->budget--) { s->failed_pc=0x0c08256eu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c082570;
P_0c082570: /* original 061a, guest PC 0x0c082570 */
if(!s->budget--) { s->failed_pc=0x0c082570u; return 0; }
r[6]=r[19];
goto P_0c082572;
P_0c082572: /* original 6353, guest PC 0x0c082572 */
if(!s->budget--) { s->failed_pc=0x0c082572u; return 0; }
r[3]=r[5];
goto P_0c082574;
P_0c082574: /* original 4508, guest PC 0x0c082574 */
if(!s->budget--) { s->failed_pc=0x0c082574u; return 0; }
r[5]<<=2;
goto P_0c082576;
P_0c082576: /* original 4500, guest PC 0x0c082576 */
if(!s->budget--) { s->failed_pc=0x0c082576u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c082578;
P_0c082578: /* original 6463, guest PC 0x0c082578 */
if(!s->budget--) { s->failed_pc=0x0c082578u; return 0; }
r[4]=r[6];
goto P_0c08257a;
P_0c08257a: /* original 353c, guest PC 0x0c08257a */
if(!s->budget--) { s->failed_pc=0x0c08257au; return 0; }
r[5]+=r[3];
goto P_0c08257c;
P_0c08257c: /* original 74f7, guest PC 0x0c08257c */
if(!s->budget--) { s->failed_pc=0x0c08257cu; return 0; }
r[4]+=0xfffffff7u;
goto P_0c08257e;
P_0c08257e: /* original 7504, guest PC 0x0c08257e */
if(!s->budget--) { s->failed_pc=0x0c08257eu; return 0; }
r[5]+=0x00000004u;
goto P_0c082580;
P_0c082580: /* original 3457, guest PC 0x0c082580 */
if(!s->budget--) { s->failed_pc=0x0c082580u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[5])!=0);
goto P_0c082582;
P_0c082582: /* original 8f01, guest PC 0x0c082582 */
if(!s->budget--) { s->failed_pc=0x0c082582u; return 0; }
cond=r[17]&1u;
r[0]=r[10];
if(!cond) { goto P_0c082588; }
goto P_0c082586;
P_0c082584: /* original 60a3, guest PC 0x0c082584 */
if(!s->budget--) { s->failed_pc=0x0c082584u; return 0; }
r[0]=r[10];
goto P_0c082586;
P_0c082586: /* original 6453, guest PC 0x0c082586 */
if(!s->budget--) { s->failed_pc=0x0c082586u; return 0; }
r[4]=r[5];
goto P_0c082588;
P_0c082588: /* original 8809, guest PC 0x0c082588 */
if(!s->budget--) { s->failed_pc=0x0c082588u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c08258a;
P_0c08258a: /* original 8919, guest PC 0x0c08258a */
if(!s->budget--) { s->failed_pc=0x0c08258au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0825c0; }
goto P_0c08258c;
P_0c08258c: /* original e2f8, guest PC 0x0c08258c */
if(!s->budget--) { s->failed_pc=0x0c08258cu; return 0; }
r[2]=0xfffffff8u;
goto P_0c08258e;
P_0c08258e: /* original 3423, guest PC 0x0c08258e */
if(!s->budget--) { s->failed_pc=0x0c08258eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c082590;
P_0c082590: /* original 8b16, guest PC 0x0c082590 */
if(!s->budget--) { s->failed_pc=0x0c082590u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0825c0; }
goto P_0c082592;
P_0c082592: /* original d042, guest PC 0x0c082592 */
if(!s->budget--) { s->failed_pc=0x0c082592u; return 0; }
r[0]=read(ram,0x0c08269cu,4);
goto P_0c082594;
P_0c082594: /* original 61a3, guest PC 0x0c082594 */
if(!s->budget--) { s->failed_pc=0x0c082594u; return 0; }
r[1]=r[10];
goto P_0c082596;
P_0c082596: /* original 4100, guest PC 0x0c082596 */
if(!s->budget--) { s->failed_pc=0x0c082596u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c082598;
P_0c082598: /* original 66b3, guest PC 0x0c082598 */
if(!s->budget--) { s->failed_pc=0x0c082598u; return 0; }
r[6]=r[11];
goto P_0c08259a;
P_0c08259a: /* original 031c, guest PC 0x0c08259a */
if(!s->budget--) { s->failed_pc=0x0c08259au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c08259c;
P_0c08259c: /* original 60a3, guest PC 0x0c08259c */
if(!s->budget--) { s->failed_pc=0x0c08259cu; return 0; }
r[0]=r[10];
goto P_0c08259e;
P_0c08259e: /* original 4008, guest PC 0x0c08259e */
if(!s->budget--) { s->failed_pc=0x0c08259eu; return 0; }
r[0]<<=2;
goto P_0c0825a0;
P_0c0825a0: /* original 6233, guest PC 0x0c0825a0 */
if(!s->budget--) { s->failed_pc=0x0c0825a0u; return 0; }
r[2]=r[3];
goto P_0c0825a2;
P_0c0825a2: /* original 4208, guest PC 0x0c0825a2 */
if(!s->budget--) { s->failed_pc=0x0c0825a2u; return 0; }
r[2]<<=2;
goto P_0c0825a4;
P_0c0825a4: /* original 4300, guest PC 0x0c0825a4 */
if(!s->budget--) { s->failed_pc=0x0c0825a4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0825a6;
P_0c0825a6: /* original 332c, guest PC 0x0c0825a6 */
if(!s->budget--) { s->failed_pc=0x0c0825a6u; return 0; }
r[3]+=r[2];
goto P_0c0825a8;
P_0c0825a8: /* original e207, guest PC 0x0c0825a8 */
if(!s->budget--) { s->failed_pc=0x0c0825a8u; return 0; }
r[2]=0x00000007u;
goto P_0c0825aa;
P_0c0825aa: /* original 730e, guest PC 0x0c0825aa */
if(!s->budget--) { s->failed_pc=0x0c0825aau; return 0; }
r[3]+=0x0000000eu;
goto P_0c0825ac;
P_0c0825ac: /* original 4400, guest PC 0x0c0825ac */
if(!s->budget--) { s->failed_pc=0x0c0825acu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0825ae;
P_0c0825ae: /* original 432c, guest PC 0x0c0825ae */
if(!s->budget--) { s->failed_pc=0x0c0825aeu; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c0825b0;
P_0c0825b0: /* original 234b, guest PC 0x0c0825b0 */
if(!s->budget--) { s->failed_pc=0x0c0825b0u; return 0; }
r[3]|=r[4];
goto P_0c0825b2;
P_0c0825b2: /* original 1f31, guest PC 0x0c0825b2 */
if(!s->budget--) { s->failed_pc=0x0c0825b2u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0825b4;
P_0c0825b4: /* original e700, guest PC 0x0c0825b4 */
if(!s->budget--) { s->failed_pc=0x0c0825b4u; return 0; }
r[7]=0x00000000u;
goto P_0c0825b6;
P_0c0825b6: /* original 2fe6, guest PC 0x0c0825b6 */
if(!s->budget--) { s->failed_pc=0x0c0825b6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0825b8;
P_0c0825b8: /* original 059e, guest PC 0x0c0825b8 */
if(!s->budget--) { s->failed_pc=0x0c0825b8u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c0825ba;
P_0c0825ba: /* original 4c0b, guest PC 0x0c0825ba */
if(!s->budget--) { s->failed_pc=0x0c0825bau; return 0; }
target=r[12];
r[16]=code_base|0x0c0825beu;
r[4]=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0825beu) { target=s->pc; goto dispatch; }
goto P_0c0825be;
P_0c0825bc: /* original 6433, guest PC 0x0c0825bc */
if(!s->budget--) { s->failed_pc=0x0c0825bcu; return 0; }
r[4]=r[3];
goto P_0c0825be;
P_0c0825be: /* original 7f04, guest PC 0x0c0825be */
if(!s->budget--) { s->failed_pc=0x0c0825beu; return 0; }
r[15]+=0x00000004u;
goto P_0c0825c0;
P_0c0825c0: /* original 52f2, guest PC 0x0c0825c0 */
if(!s->budget--) { s->failed_pc=0x0c0825c0u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0825c2;
P_0c0825c2: /* original 7201, guest PC 0x0c0825c2 */
if(!s->budget--) { s->failed_pc=0x0c0825c2u; return 0; }
r[2]+=0x00000001u;
goto P_0c0825c4;
P_0c0825c4: /* original 1f22, guest PC 0x0c0825c4 */
if(!s->budget--) { s->failed_pc=0x0c0825c4u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0825c6;
P_0c0825c6: /* original 51f2, guest PC 0x0c0825c6 */
if(!s->budget--) { s->failed_pc=0x0c0825c6u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c0825c8;
P_0c0825c8: /* original e30c, guest PC 0x0c0825c8 */
if(!s->budget--) { s->failed_pc=0x0c0825c8u; return 0; }
r[3]=0x0000000cu;
goto P_0c0825ca;
P_0c0825ca: /* original 3133, guest PC 0x0c0825ca */
if(!s->budget--) { s->failed_pc=0x0c0825cau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c0825cc;
P_0c0825cc: /* original 8bba, guest PC 0x0c0825cc */
if(!s->budget--) { s->failed_pc=0x0c0825ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c082544; }
goto P_0c0825ce;
P_0c0825ce: /* original 9358, guest PC 0x0c0825ce */
if(!s->budget--) { s->failed_pc=0x0c0825ceu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082682u,2);
goto P_0c0825d0;
P_0c0825d0: /* original 66b3, guest PC 0x0c0825d0 */
if(!s->budget--) { s->failed_pc=0x0c0825d0u; return 0; }
r[6]=r[11];
goto P_0c0825d2;
P_0c0825d2: /* original e700, guest PC 0x0c0825d2 */
if(!s->budget--) { s->failed_pc=0x0c0825d2u; return 0; }
r[7]=0x00000000u;
goto P_0c0825d4;
P_0c0825d4: /* original 1f32, guest PC 0x0c0825d4 */
if(!s->budget--) { s->failed_pc=0x0c0825d4u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0825d6;
P_0c0825d6: /* original 2fe6, guest PC 0x0c0825d6 */
if(!s->budget--) { s->failed_pc=0x0c0825d6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0825d8;
P_0c0825d8: /* original 9554, guest PC 0x0c0825d8 */
if(!s->budget--) { s->failed_pc=0x0c0825d8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082684u,2);
goto P_0c0825da;
P_0c0825da: /* original 4c0b, guest PC 0x0c0825da */
if(!s->budget--) { s->failed_pc=0x0c0825dau; return 0; }
target=r[12];
r[16]=code_base|0x0c0825deu;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0825deu) { target=s->pc; goto dispatch; }
goto P_0c0825de;
P_0c0825dc: /* original 54f3, guest PC 0x0c0825dc */
if(!s->budget--) { s->failed_pc=0x0c0825dcu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c0825de;
P_0c0825de: /* original 9a52, guest PC 0x0c0825de */
if(!s->budget--) { s->failed_pc=0x0c0825deu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082686u,2);
goto P_0c0825e0;
P_0c0825e0: /* original 66b3, guest PC 0x0c0825e0 */
if(!s->budget--) { s->failed_pc=0x0c0825e0u; return 0; }
r[6]=r[11];
goto P_0c0825e2;
P_0c0825e2: /* original 2fe6, guest PC 0x0c0825e2 */
if(!s->budget--) { s->failed_pc=0x0c0825e2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0825e4;
P_0c0825e4: /* original e700, guest PC 0x0c0825e4 */
if(!s->budget--) { s->failed_pc=0x0c0825e4u; return 0; }
r[7]=0x00000000u;
goto P_0c0825e6;
P_0c0825e6: /* original 954f, guest PC 0x0c0825e6 */
if(!s->budget--) { s->failed_pc=0x0c0825e6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082688u,2);
goto P_0c0825e8;
P_0c0825e8: /* original 4c0b, guest PC 0x0c0825e8 */
if(!s->budget--) { s->failed_pc=0x0c0825e8u; return 0; }
target=r[12];
r[16]=code_base|0x0c0825ecu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0825ecu) { target=s->pc; goto dispatch; }
goto P_0c0825ec;
P_0c0825ea: /* original 64a3, guest PC 0x0c0825ea */
if(!s->budget--) { s->failed_pc=0x0c0825eau; return 0; }
r[4]=r[10];
goto P_0c0825ec;
P_0c0825ec: /* original 5383, guest PC 0x0c0825ec */
if(!s->budget--) { s->failed_pc=0x0c0825ecu; return 0; }
r[3]=read(ram,r[8]+12,4);
goto P_0c0825ee;
P_0c0825ee: /* original 4315, guest PC 0x0c0825ee */
if(!s->budget--) { s->failed_pc=0x0c0825eeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c0825f0;
P_0c0825f0: /* original 8d09, guest PC 0x0c0825f0 */
if(!s->budget--) { s->failed_pc=0x0c0825f0u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000008u;
if(cond) { goto P_0c082606; }
goto P_0c0825f4;
P_0c0825f2: /* original 7f08, guest PC 0x0c0825f2 */
if(!s->budget--) { s->failed_pc=0x0c0825f2u; return 0; }
r[15]+=0x00000008u;
goto P_0c0825f4;
P_0c0825f4: /* original 9a49, guest PC 0x0c0825f4 */
if(!s->budget--) { s->failed_pc=0x0c0825f4u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08268au,2);
goto P_0c0825f6;
P_0c0825f6: /* original e700, guest PC 0x0c0825f6 */
if(!s->budget--) { s->failed_pc=0x0c0825f6u; return 0; }
r[7]=0x00000000u;
goto P_0c0825f8;
P_0c0825f8: /* original 2fe6, guest PC 0x0c0825f8 */
if(!s->budget--) { s->failed_pc=0x0c0825f8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0825fa;
P_0c0825fa: /* original 66d3, guest PC 0x0c0825fa */
if(!s->budget--) { s->failed_pc=0x0c0825fau; return 0; }
r[6]=r[13];
goto P_0c0825fc;
P_0c0825fc: /* original 50f4, guest PC 0x0c0825fc */
if(!s->budget--) { s->failed_pc=0x0c0825fcu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c0825fe;
P_0c0825fe: /* original 059e, guest PC 0x0c0825fe */
if(!s->budget--) { s->failed_pc=0x0c0825feu; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c082600;
P_0c082600: /* original 4c0b, guest PC 0x0c082600 */
if(!s->budget--) { s->failed_pc=0x0c082600u; return 0; }
target=r[12];
r[16]=code_base|0x0c082604u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082604u) { target=s->pc; goto dispatch; }
goto P_0c082604;
P_0c082602: /* original 64a3, guest PC 0x0c082602 */
if(!s->budget--) { s->failed_pc=0x0c082602u; return 0; }
r[4]=r[10];
goto P_0c082604;
P_0c082604: /* original 7f04, guest PC 0x0c082604 */
if(!s->budget--) { s->failed_pc=0x0c082604u; return 0; }
r[15]+=0x00000004u;
goto P_0c082606;
P_0c082606: /* original d326, guest PC 0x0c082606 */
if(!s->budget--) { s->failed_pc=0x0c082606u; return 0; }
r[3]=read(ram,0x0c0826a0u,4);
goto P_0c082608;
P_0c082608: /* original 6032, guest PC 0x0c082608 */
if(!s->budget--) { s->failed_pc=0x0c082608u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c08260a;
P_0c08260a: /* original c810, guest PC 0x0c08260a */
if(!s->budget--) { s->failed_pc=0x0c08260au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c08260c;
P_0c08260c: /* original 8904, guest PC 0x0c08260c */
if(!s->budget--) { s->failed_pc=0x0c08260cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c082618; }
goto P_0c08260e;
P_0c08260e: /* original 5183, guest PC 0x0c08260e */
if(!s->budget--) { s->failed_pc=0x0c08260eu; return 0; }
r[1]=read(ram,r[8]+12,4);
goto P_0c082610;
P_0c082610: /* original 4115, guest PC 0x0c082610 */
if(!s->budget--) { s->failed_pc=0x0c082610u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c082612;
P_0c082612: /* original 8901, guest PC 0x0c082612 */
if(!s->budget--) { s->failed_pc=0x0c082612u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c082618; }
goto P_0c082614;
P_0c082614: /* original a2b5, guest PC 0x0c082614 */
if(!s->budget--) { s->failed_pc=0x0c082614u; return 0; }
goto P_0c082b82;
P_0c082616: /* original 0009, guest PC 0x0c082616 */
if(!s->budget--) { s->failed_pc=0x0c082616u; return 0; }
goto P_0c082618;
P_0c082618: /* original 9338, guest PC 0x0c082618 */
if(!s->budget--) { s->failed_pc=0x0c082618u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08268cu,2);
goto P_0c08261a;
P_0c08261a: /* original 66b3, guest PC 0x0c08261a */
if(!s->budget--) { s->failed_pc=0x0c08261au; return 0; }
r[6]=r[11];
goto P_0c08261c;
P_0c08261c: /* original e700, guest PC 0x0c08261c */
if(!s->budget--) { s->failed_pc=0x0c08261cu; return 0; }
r[7]=0x00000000u;
goto P_0c08261e;
P_0c08261e: /* original 1f33, guest PC 0x0c08261e */
if(!s->budget--) { s->failed_pc=0x0c08261eu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c082620;
P_0c082620: /* original 2fe6, guest PC 0x0c082620 */
if(!s->budget--) { s->failed_pc=0x0c082620u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082622;
P_0c082622: /* original 9534, guest PC 0x0c082622 */
if(!s->budget--) { s->failed_pc=0x0c082622u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08268eu,2);
goto P_0c082624;
P_0c082624: /* original 4c0b, guest PC 0x0c082624 */
if(!s->budget--) { s->failed_pc=0x0c082624u; return 0; }
target=r[12];
r[16]=code_base|0x0c082628u;
r[4]=read(ram,r[15]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082628u) { target=s->pc; goto dispatch; }
goto P_0c082628;
P_0c082626: /* original 54f4, guest PC 0x0c082626 */
if(!s->budget--) { s->failed_pc=0x0c082626u; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c082628;
P_0c082628: /* original 5383, guest PC 0x0c082628 */
if(!s->budget--) { s->failed_pc=0x0c082628u; return 0; }
r[3]=read(ram,r[8]+12,4);
goto P_0c08262a;
P_0c08262a: /* original 4315, guest PC 0x0c08262a */
if(!s->budget--) { s->failed_pc=0x0c08262au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c08262c;
P_0c08262c: /* original 8d1f, guest PC 0x0c08262c */
if(!s->budget--) { s->failed_pc=0x0c08262cu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c08266e; }
goto P_0c082630;
P_0c08262e: /* original 7f04, guest PC 0x0c08262e */
if(!s->budget--) { s->failed_pc=0x0c08262eu; return 0; }
r[15]+=0x00000004u;
goto P_0c082630;
P_0c082630: /* original 60f2, guest PC 0x0c082630 */
if(!s->budget--) { s->failed_pc=0x0c082630u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c082632;
P_0c082632: /* original 8809, guest PC 0x0c082632 */
if(!s->budget--) { s->failed_pc=0x0c082632u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c082634;
P_0c082634: /* original 891b, guest PC 0x0c082634 */
if(!s->budget--) { s->failed_pc=0x0c082634u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08266e; }
goto P_0c082636;
P_0c082636: /* original 64f2, guest PC 0x0c082636 */
if(!s->budget--) { s->failed_pc=0x0c082636u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c082638;
P_0c082638: /* original 66d3, guest PC 0x0c082638 */
if(!s->budget--) { s->failed_pc=0x0c082638u; return 0; }
r[6]=r[13];
goto P_0c08263a;
P_0c08263a: /* original d317, guest PC 0x0c08263a */
if(!s->budget--) { s->failed_pc=0x0c08263au; return 0; }
r[3]=read(ram,0x0c082698u,4);
goto P_0c08263c;
P_0c08263c: /* original e700, guest PC 0x0c08263c */
if(!s->budget--) { s->failed_pc=0x0c08263cu; return 0; }
r[7]=0x00000000u;
goto P_0c08263e;
P_0c08263e: /* original 4400, guest PC 0x0c08263e */
if(!s->budget--) { s->failed_pc=0x0c08263eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c082640;
P_0c082640: /* original 343c, guest PC 0x0c082640 */
if(!s->budget--) { s->failed_pc=0x0c082640u; return 0; }
r[4]+=r[3];
goto P_0c082642;
P_0c082642: /* original 6240, guest PC 0x0c082642 */
if(!s->budget--) { s->failed_pc=0x0c082642u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c082644;
P_0c082644: /* original 8441, guest PC 0x0c082644 */
if(!s->budget--) { s->failed_pc=0x0c082644u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c082646;
P_0c082646: /* original 6123, guest PC 0x0c082646 */
if(!s->budget--) { s->failed_pc=0x0c082646u; return 0; }
r[1]=r[2];
goto P_0c082648;
P_0c082648: /* original 4208, guest PC 0x0c082648 */
if(!s->budget--) { s->failed_pc=0x0c082648u; return 0; }
r[2]<<=2;
goto P_0c08264a;
P_0c08264a: /* original 4200, guest PC 0x0c08264a */
if(!s->budget--) { s->failed_pc=0x0c08264au; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c08264c;
P_0c08264c: /* original 321c, guest PC 0x0c08264c */
if(!s->budget--) { s->failed_pc=0x0c08264cu; return 0; }
r[2]+=r[1];
goto P_0c08264e;
P_0c08264e: /* original 6103, guest PC 0x0c08264e */
if(!s->budget--) { s->failed_pc=0x0c08264eu; return 0; }
r[1]=r[0];
goto P_0c082650;
P_0c082650: /* original 4108, guest PC 0x0c082650 */
if(!s->budget--) { s->failed_pc=0x0c082650u; return 0; }
r[1]<<=2;
goto P_0c082652;
P_0c082652: /* original 7204, guest PC 0x0c082652 */
if(!s->budget--) { s->failed_pc=0x0c082652u; return 0; }
r[2]+=0x00000004u;
goto P_0c082654;
P_0c082654: /* original 4200, guest PC 0x0c082654 */
if(!s->budget--) { s->failed_pc=0x0c082654u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c082656;
P_0c082656: /* original 4000, guest PC 0x0c082656 */
if(!s->budget--) { s->failed_pc=0x0c082656u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c082658;
P_0c082658: /* original 301c, guest PC 0x0c082658 */
if(!s->budget--) { s->failed_pc=0x0c082658u; return 0; }
r[0]+=r[1];
goto P_0c08265a;
P_0c08265a: /* original e107, guest PC 0x0c08265a */
if(!s->budget--) { s->failed_pc=0x0c08265au; return 0; }
r[1]=0x00000007u;
goto P_0c08265c;
P_0c08265c: /* original 700e, guest PC 0x0c08265c */
if(!s->budget--) { s->failed_pc=0x0c08265cu; return 0; }
r[0]+=0x0000000eu;
goto P_0c08265e;
P_0c08265e: /* original 401c, guest PC 0x0c08265e */
if(!s->budget--) { s->failed_pc=0x0c08265eu; return 0; }
r[0]=(r[1]&0x80000000u)?((r[1]&31u)?(uint32_t)((int32_t)r[0]>>((-r[1])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[1]&31u);
goto P_0c082660;
P_0c082660: /* original 220b, guest PC 0x0c082660 */
if(!s->budget--) { s->failed_pc=0x0c082660u; return 0; }
r[2]|=r[0];
goto P_0c082662;
P_0c082662: /* original 2f22, guest PC 0x0c082662 */
if(!s->budget--) { s->failed_pc=0x0c082662u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c082664;
P_0c082664: /* original 2fe6, guest PC 0x0c082664 */
if(!s->budget--) { s->failed_pc=0x0c082664u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082666;
P_0c082666: /* original 9513, guest PC 0x0c082666 */
if(!s->budget--) { s->failed_pc=0x0c082666u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082690u,2);
goto P_0c082668;
P_0c082668: /* original 4c0b, guest PC 0x0c082668 */
if(!s->budget--) { s->failed_pc=0x0c082668u; return 0; }
target=r[12];
r[16]=code_base|0x0c08266cu;
r[4]=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08266cu) { target=s->pc; goto dispatch; }
goto P_0c08266c;
P_0c08266a: /* original 6423, guest PC 0x0c08266a */
if(!s->budget--) { s->failed_pc=0x0c08266au; return 0; }
r[4]=r[2];
goto P_0c08266c;
P_0c08266c: /* original 7f04, guest PC 0x0c08266c */
if(!s->budget--) { s->failed_pc=0x0c08266cu; return 0; }
r[15]+=0x00000004u;
goto P_0c08266e;
P_0c08266e: /* original e301, guest PC 0x0c08266e */
if(!s->budget--) { s->failed_pc=0x0c08266eu; return 0; }
r[3]=0x00000001u;
goto P_0c082670;
P_0c082670: /* original 9a0f, guest PC 0x0c082670 */
if(!s->budget--) { s->failed_pc=0x0c082670u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082692u,2);
goto P_0c082672;
P_0c082672: /* original 66b3, guest PC 0x0c082672 */
if(!s->budget--) { s->failed_pc=0x0c082672u; return 0; }
r[6]=r[11];
goto P_0c082674;
P_0c082674: /* original 2f36, guest PC 0x0c082674 */
if(!s->budget--) { s->failed_pc=0x0c082674u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082676;
P_0c082676: /* original 950d, guest PC 0x0c082676 */
if(!s->budget--) { s->failed_pc=0x0c082676u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082694u,2);
goto P_0c082678;
P_0c082678: /* original e700, guest PC 0x0c082678 */
if(!s->budget--) { s->failed_pc=0x0c082678u; return 0; }
r[7]=0x00000000u;
goto P_0c08267a;
P_0c08267a: /* original 4c0b, guest PC 0x0c08267a */
if(!s->budget--) { s->failed_pc=0x0c08267au; return 0; }
target=r[12];
r[16]=code_base|0x0c08267eu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08267eu) { target=s->pc; goto dispatch; }
goto P_0c08267e;
P_0c08267c: /* original 64a3, guest PC 0x0c08267c */
if(!s->budget--) { s->failed_pc=0x0c08267cu; return 0; }
r[4]=r[10];
goto P_0c08267e;
P_0c08267e: /* original a280, guest PC 0x0c08267e */
if(!s->budget--) { s->failed_pc=0x0c08267eu; return 0; }
r[15]+=0x00000004u;
goto P_0c082b82;
P_0c082680: /* original 7f04, guest PC 0x0c082680 */
if(!s->budget--) { s->failed_pc=0x0c082680u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c082682u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c082682u; return 0; } return 1;
P_0c0826a4: /* original 1fe5, guest PC 0x0c0826a4 */
if(!s->budget--) { s->failed_pc=0x0c0826a4u; return 0; }
write(ram,r[15]+20,r[14],4);
goto P_0c0826a6;
P_0c0826a6: /* original 1f51, guest PC 0x0c0826a6 */
if(!s->budget--) { s->failed_pc=0x0c0826a6u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0826a8;
P_0c0826a8: /* original d301, guest PC 0x0c0826a8 */
if(!s->budget--) { s->failed_pc=0x0c0826a8u; return 0; }
r[3]=read(ram,0x0c0826b0u,4);
goto P_0c0826aa;
P_0c0826aa: /* original 2f32, guest PC 0x0c0826aa */
if(!s->budget--) { s->failed_pc=0x0c0826aau; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0826ac;
P_0c0826ac: /* original a043, guest PC 0x0c0826ac */
if(!s->budget--) { s->failed_pc=0x0c0826acu; return 0; }
write(ram,r[15]+24,r[4],4);
goto P_0c082736;
P_0c0826ae: /* original 1f46, guest PC 0x0c0826ae */
if(!s->budget--) { s->failed_pc=0x0c0826aeu; return 0; }
write(ram,r[15]+24,r[4],4);
if(!vf3_matrix_family(0x0c0826b0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0826b0u; return 0; } return 1;
P_0c0826b4: /* original 5af6, guest PC 0x0c0826b4 */
if(!s->budget--) { s->failed_pc=0x0c0826b4u; return 0; }
r[10]=read(ram,r[15]+24,4);
goto P_0c0826b6;
P_0c0826b6: /* original 7a04, guest PC 0x0c0826b6 */
if(!s->budget--) { s->failed_pc=0x0c0826b6u; return 0; }
r[10]+=0x00000004u;
goto P_0c0826b8;
P_0c0826b8: /* original 1fa6, guest PC 0x0c0826b8 */
if(!s->budget--) { s->failed_pc=0x0c0826b8u; return 0; }
write(ram,r[15]+24,r[10],4);
goto P_0c0826ba;
P_0c0826ba: /* original 7afc, guest PC 0x0c0826ba */
if(!s->budget--) { s->failed_pc=0x0c0826bau; return 0; }
r[10]+=0xfffffffcu;
goto P_0c0826bc;
P_0c0826bc: /* original 63f2, guest PC 0x0c0826bc */
if(!s->budget--) { s->failed_pc=0x0c0826bcu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0826be;
P_0c0826be: /* original 5483, guest PC 0x0c0826be */
if(!s->budget--) { s->failed_pc=0x0c0826beu; return 0; }
r[4]=read(ram,r[8]+12,4);
goto P_0c0826c0;
P_0c0826c0: /* original 5231, guest PC 0x0c0826c0 */
if(!s->budget--) { s->failed_pc=0x0c0826c0u; return 0; }
r[2]=read(ram,r[3]+4,4);
goto P_0c0826c2;
P_0c0826c2: /* original 53f1, guest PC 0x0c0826c2 */
if(!s->budget--) { s->failed_pc=0x0c0826c2u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0826c4;
P_0c0826c4: /* original 644b, guest PC 0x0c0826c4 */
if(!s->budget--) { s->failed_pc=0x0c0826c4u; return 0; }
r[4]=0u-r[4];
goto P_0c0826c6;
P_0c0826c6: /* original 7420, guest PC 0x0c0826c6 */
if(!s->budget--) { s->failed_pc=0x0c0826c6u; return 0; }
r[4]+=0x00000020u;
goto P_0c0826c8;
P_0c0826c8: /* original 6aa2, guest PC 0x0c0826c8 */
if(!s->budget--) { s->failed_pc=0x0c0826c8u; return 0; }
tmp=read(ram,r[10],4);
r[10]=tmp;
goto P_0c0826ca;
P_0c0826ca: /* original 6632, guest PC 0x0c0826ca */
if(!s->budget--) { s->failed_pc=0x0c0826cau; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c0826cc;
P_0c0826cc: /* original 3428, guest PC 0x0c0826cc */
if(!s->budget--) { s->failed_pc=0x0c0826ccu; return 0; }
r[4]-=r[2];
goto P_0c0826ce;
P_0c0826ce: /* original 4411, guest PC 0x0c0826ce */
if(!s->budget--) { s->failed_pc=0x0c0826ceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0826d0;
P_0c0826d0: /* original 8f28, guest PC 0x0c0826d0 */
if(!s->budget--) { s->failed_pc=0x0c0826d0u; return 0; }
cond=r[17]&1u;
r[6]+=0xfffffff6u;
if(!cond) { goto P_0c082724; }
goto P_0c0826d4;
P_0c0826d2: /* original 76f6, guest PC 0x0c0826d2 */
if(!s->budget--) { s->failed_pc=0x0c0826d2u; return 0; }
r[6]+=0xfffffff6u;
goto P_0c0826d4;
P_0c0826d4: /* original d351, guest PC 0x0c0826d4 */
if(!s->budget--) { s->failed_pc=0x0c0826d4u; return 0; }
r[3]=read(ram,0x0c08281cu,4);
goto P_0c0826d6;
P_0c0826d6: /* original 67a3, guest PC 0x0c0826d6 */
if(!s->budget--) { s->failed_pc=0x0c0826d6u; return 0; }
r[7]=r[10];
goto P_0c0826d8;
P_0c0826d8: /* original 0647, guest PC 0x0c0826d8 */
if(!s->budget--) { s->failed_pc=0x0c0826d8u; return 0; }
r[19]=r[6]*r[4];
goto P_0c0826da;
P_0c0826da: /* original 4700, guest PC 0x0c0826da */
if(!s->budget--) { s->failed_pc=0x0c0826dau; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c0826dc;
P_0c0826dc: /* original 373c, guest PC 0x0c0826dc */
if(!s->budget--) { s->failed_pc=0x0c0826dcu; return 0; }
r[7]+=r[3];
goto P_0c0826de;
P_0c0826de: /* original 6570, guest PC 0x0c0826de */
if(!s->budget--) { s->failed_pc=0x0c0826deu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[5]=tmp;
goto P_0c0826e0;
P_0c0826e0: /* original 061a, guest PC 0x0c0826e0 */
if(!s->budget--) { s->failed_pc=0x0c0826e0u; return 0; }
r[6]=r[19];
goto P_0c0826e2;
P_0c0826e2: /* original 6253, guest PC 0x0c0826e2 */
if(!s->budget--) { s->failed_pc=0x0c0826e2u; return 0; }
r[2]=r[5];
goto P_0c0826e4;
P_0c0826e4: /* original 4508, guest PC 0x0c0826e4 */
if(!s->budget--) { s->failed_pc=0x0c0826e4u; return 0; }
r[5]<<=2;
goto P_0c0826e6;
P_0c0826e6: /* original 4500, guest PC 0x0c0826e6 */
if(!s->budget--) { s->failed_pc=0x0c0826e6u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0826e8;
P_0c0826e8: /* original 6463, guest PC 0x0c0826e8 */
if(!s->budget--) { s->failed_pc=0x0c0826e8u; return 0; }
r[4]=r[6];
goto P_0c0826ea;
P_0c0826ea: /* original 352c, guest PC 0x0c0826ea */
if(!s->budget--) { s->failed_pc=0x0c0826eau; return 0; }
r[5]+=r[2];
goto P_0c0826ec;
P_0c0826ec: /* original 7438, guest PC 0x0c0826ec */
if(!s->budget--) { s->failed_pc=0x0c0826ecu; return 0; }
r[4]+=0x00000038u;
goto P_0c0826ee;
P_0c0826ee: /* original 7504, guest PC 0x0c0826ee */
if(!s->budget--) { s->failed_pc=0x0c0826eeu; return 0; }
r[5]+=0x00000004u;
goto P_0c0826f0;
P_0c0826f0: /* original 3453, guest PC 0x0c0826f0 */
if(!s->budget--) { s->failed_pc=0x0c0826f0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c0826f2;
P_0c0826f2: /* original 8d01, guest PC 0x0c0826f2 */
if(!s->budget--) { s->failed_pc=0x0c0826f2u; return 0; }
cond=r[17]&1u;
r[0]=r[10];
if(cond) { goto P_0c0826f8; }
goto P_0c0826f6;
P_0c0826f4: /* original 60a3, guest PC 0x0c0826f4 */
if(!s->budget--) { s->failed_pc=0x0c0826f4u; return 0; }
r[0]=r[10];
goto P_0c0826f6;
P_0c0826f6: /* original 6453, guest PC 0x0c0826f6 */
if(!s->budget--) { s->failed_pc=0x0c0826f6u; return 0; }
r[4]=r[5];
goto P_0c0826f8;
P_0c0826f8: /* original 8809, guest PC 0x0c0826f8 */
if(!s->budget--) { s->failed_pc=0x0c0826f8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0826fa;
P_0c0826fa: /* original 8913, guest PC 0x0c0826fa */
if(!s->budget--) { s->failed_pc=0x0c0826fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c082724; }
goto P_0c0826fc;
P_0c0826fc: /* original 8471, guest PC 0x0c0826fc */
if(!s->budget--) { s->failed_pc=0x0c0826fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+1,1);
goto P_0c0826fe;
P_0c0826fe: /* original e700, guest PC 0x0c0826fe */
if(!s->budget--) { s->failed_pc=0x0c0826feu; return 0; }
r[7]=0x00000000u;
goto P_0c082700;
P_0c082700: /* original 66b3, guest PC 0x0c082700 */
if(!s->budget--) { s->failed_pc=0x0c082700u; return 0; }
r[6]=r[11];
goto P_0c082702;
P_0c082702: /* original 6303, guest PC 0x0c082702 */
if(!s->budget--) { s->failed_pc=0x0c082702u; return 0; }
r[3]=r[0];
goto P_0c082704;
P_0c082704: /* original 4308, guest PC 0x0c082704 */
if(!s->budget--) { s->failed_pc=0x0c082704u; return 0; }
r[3]<<=2;
goto P_0c082706;
P_0c082706: /* original 4000, guest PC 0x0c082706 */
if(!s->budget--) { s->failed_pc=0x0c082706u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c082708;
P_0c082708: /* original 303c, guest PC 0x0c082708 */
if(!s->budget--) { s->failed_pc=0x0c082708u; return 0; }
r[0]+=r[3];
goto P_0c08270a;
P_0c08270a: /* original e307, guest PC 0x0c08270a */
if(!s->budget--) { s->failed_pc=0x0c08270au; return 0; }
r[3]=0x00000007u;
goto P_0c08270c;
P_0c08270c: /* original 700e, guest PC 0x0c08270c */
if(!s->budget--) { s->failed_pc=0x0c08270cu; return 0; }
r[0]+=0x0000000eu;
goto P_0c08270e;
P_0c08270e: /* original 4400, guest PC 0x0c08270e */
if(!s->budget--) { s->failed_pc=0x0c08270eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c082710;
P_0c082710: /* original 403c, guest PC 0x0c082710 */
if(!s->budget--) { s->failed_pc=0x0c082710u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c082712;
P_0c082712: /* original 204b, guest PC 0x0c082712 */
if(!s->budget--) { s->failed_pc=0x0c082712u; return 0; }
r[0]|=r[4];
goto P_0c082714;
P_0c082714: /* original 1f07, guest PC 0x0c082714 */
if(!s->budget--) { s->failed_pc=0x0c082714u; return 0; }
write(ram,r[15]+28,r[0],4);
goto P_0c082716;
P_0c082716: /* original 60a3, guest PC 0x0c082716 */
if(!s->budget--) { s->failed_pc=0x0c082716u; return 0; }
r[0]=r[10];
goto P_0c082718;
P_0c082718: /* original 4008, guest PC 0x0c082718 */
if(!s->budget--) { s->failed_pc=0x0c082718u; return 0; }
r[0]<<=2;
goto P_0c08271a;
P_0c08271a: /* original 2fe6, guest PC 0x0c08271a */
if(!s->budget--) { s->failed_pc=0x0c08271au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08271c;
P_0c08271c: /* original 059e, guest PC 0x0c08271c */
if(!s->budget--) { s->failed_pc=0x0c08271cu; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c08271e;
P_0c08271e: /* original 4c0b, guest PC 0x0c08271e */
if(!s->budget--) { s->failed_pc=0x0c08271eu; return 0; }
target=r[12];
r[16]=code_base|0x0c082722u;
r[4]=read(ram,r[15]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082722u) { target=s->pc; goto dispatch; }
goto P_0c082722;
P_0c082720: /* original 54f8, guest PC 0x0c082720 */
if(!s->budget--) { s->failed_pc=0x0c082720u; return 0; }
r[4]=read(ram,r[15]+32,4);
goto P_0c082722;
P_0c082722: /* original 7f04, guest PC 0x0c082722 */
if(!s->budget--) { s->failed_pc=0x0c082722u; return 0; }
r[15]+=0x00000004u;
goto P_0c082724;
P_0c082724: /* original 53f5, guest PC 0x0c082724 */
if(!s->budget--) { s->failed_pc=0x0c082724u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c082726;
P_0c082726: /* original 7301, guest PC 0x0c082726 */
if(!s->budget--) { s->failed_pc=0x0c082726u; return 0; }
r[3]+=0x00000001u;
goto P_0c082728;
P_0c082728: /* original 1f35, guest PC 0x0c082728 */
if(!s->budget--) { s->failed_pc=0x0c082728u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c08272a;
P_0c08272a: /* original 52f1, guest PC 0x0c08272a */
if(!s->budget--) { s->failed_pc=0x0c08272au; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c08272c;
P_0c08272c: /* original 7208, guest PC 0x0c08272c */
if(!s->budget--) { s->failed_pc=0x0c08272cu; return 0; }
r[2]+=0x00000008u;
goto P_0c08272e;
P_0c08272e: /* original 1f21, guest PC 0x0c08272e */
if(!s->budget--) { s->failed_pc=0x0c08272eu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c082730;
P_0c082730: /* original 61f2, guest PC 0x0c082730 */
if(!s->budget--) { s->failed_pc=0x0c082730u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c082732;
P_0c082732: /* original 71f8, guest PC 0x0c082732 */
if(!s->budget--) { s->failed_pc=0x0c082732u; return 0; }
r[1]+=0xfffffff8u;
goto P_0c082734;
P_0c082734: /* original 2f12, guest PC 0x0c082734 */
if(!s->budget--) { s->failed_pc=0x0c082734u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c082736;
P_0c082736: /* original 52f5, guest PC 0x0c082736 */
if(!s->budget--) { s->failed_pc=0x0c082736u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c082738;
P_0c082738: /* original e30c, guest PC 0x0c082738 */
if(!s->budget--) { s->failed_pc=0x0c082738u; return 0; }
r[3]=0x0000000cu;
goto P_0c08273a;
P_0c08273a: /* original 3233, guest PC 0x0c08273a */
if(!s->budget--) { s->failed_pc=0x0c08273au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c08273c;
P_0c08273c: /* original 8bba, guest PC 0x0c08273c */
if(!s->budget--) { s->failed_pc=0x0c08273cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0826b4; }
goto P_0c08273e;
P_0c08273e: /* original 9361, guest PC 0x0c08273e */
if(!s->budget--) { s->failed_pc=0x0c08273eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082804u,2);
goto P_0c082740;
P_0c082740: /* original 66b3, guest PC 0x0c082740 */
if(!s->budget--) { s->failed_pc=0x0c082740u; return 0; }
r[6]=r[11];
goto P_0c082742;
P_0c082742: /* original e700, guest PC 0x0c082742 */
if(!s->budget--) { s->failed_pc=0x0c082742u; return 0; }
r[7]=0x00000000u;
goto P_0c082744;
P_0c082744: /* original 2f32, guest PC 0x0c082744 */
if(!s->budget--) { s->failed_pc=0x0c082744u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c082746;
P_0c082746: /* original 2fe6, guest PC 0x0c082746 */
if(!s->budget--) { s->failed_pc=0x0c082746u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082748;
P_0c082748: /* original 955d, guest PC 0x0c082748 */
if(!s->budget--) { s->failed_pc=0x0c082748u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082806u,2);
goto P_0c08274a;
P_0c08274a: /* original 4c0b, guest PC 0x0c08274a */
if(!s->budget--) { s->failed_pc=0x0c08274au; return 0; }
target=r[12];
r[16]=code_base|0x0c08274eu;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08274eu) { target=s->pc; goto dispatch; }
goto P_0c08274e;
P_0c08274c: /* original 54f1, guest PC 0x0c08274c */
if(!s->budget--) { s->failed_pc=0x0c08274cu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c08274e;
P_0c08274e: /* original 935b, guest PC 0x0c08274e */
if(!s->budget--) { s->failed_pc=0x0c08274eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082808u,2);
goto P_0c082750;
P_0c082750: /* original 66b3, guest PC 0x0c082750 */
if(!s->budget--) { s->failed_pc=0x0c082750u; return 0; }
r[6]=r[11];
goto P_0c082752;
P_0c082752: /* original e700, guest PC 0x0c082752 */
if(!s->budget--) { s->failed_pc=0x0c082752u; return 0; }
r[7]=0x00000000u;
goto P_0c082754;
P_0c082754: /* original 1f31, guest PC 0x0c082754 */
if(!s->budget--) { s->failed_pc=0x0c082754u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c082756;
P_0c082756: /* original 2fe6, guest PC 0x0c082756 */
if(!s->budget--) { s->failed_pc=0x0c082756u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082758;
P_0c082758: /* original 9557, guest PC 0x0c082758 */
if(!s->budget--) { s->failed_pc=0x0c082758u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08280au,2);
goto P_0c08275a;
P_0c08275a: /* original 4c0b, guest PC 0x0c08275a */
if(!s->budget--) { s->failed_pc=0x0c08275au; return 0; }
target=r[12];
r[16]=code_base|0x0c08275eu;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08275eu) { target=s->pc; goto dispatch; }
goto P_0c08275e;
P_0c08275c: /* original 54f2, guest PC 0x0c08275c */
if(!s->budget--) { s->failed_pc=0x0c08275cu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c08275e;
P_0c08275e: /* original 9a55, guest PC 0x0c08275e */
if(!s->budget--) { s->failed_pc=0x0c08275eu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08280cu,2);
goto P_0c082760;
P_0c082760: /* original e700, guest PC 0x0c082760 */
if(!s->budget--) { s->failed_pc=0x0c082760u; return 0; }
r[7]=0x00000000u;
goto P_0c082762;
P_0c082762: /* original 2fe6, guest PC 0x0c082762 */
if(!s->budget--) { s->failed_pc=0x0c082762u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082764;
P_0c082764: /* original 66d3, guest PC 0x0c082764 */
if(!s->budget--) { s->failed_pc=0x0c082764u; return 0; }
r[6]=r[13];
goto P_0c082766;
P_0c082766: /* original 50f6, guest PC 0x0c082766 */
if(!s->budget--) { s->failed_pc=0x0c082766u; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c082768;
P_0c082768: /* original 059e, guest PC 0x0c082768 */
if(!s->budget--) { s->failed_pc=0x0c082768u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c08276a;
P_0c08276a: /* original 4c0b, guest PC 0x0c08276a */
if(!s->budget--) { s->failed_pc=0x0c08276au; return 0; }
target=r[12];
r[16]=code_base|0x0c08276eu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08276eu) { target=s->pc; goto dispatch; }
goto P_0c08276e;
P_0c08276c: /* original 64a3, guest PC 0x0c08276c */
if(!s->budget--) { s->failed_pc=0x0c08276cu; return 0; }
r[4]=r[10];
goto P_0c08276e;
P_0c08276e: /* original 5383, guest PC 0x0c08276e */
if(!s->budget--) { s->failed_pc=0x0c08276eu; return 0; }
r[3]=read(ram,r[8]+12,4);
goto P_0c082770;
P_0c082770: /* original 2338, guest PC 0x0c082770 */
if(!s->budget--) { s->failed_pc=0x0c082770u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c082772;
P_0c082772: /* original 8f09, guest PC 0x0c082772 */
if(!s->budget--) { s->failed_pc=0x0c082772u; return 0; }
cond=r[17]&1u;
r[15]+=0x0000000cu;
if(!cond) { goto P_0c082788; }
goto P_0c082776;
P_0c082774: /* original 7f0c, guest PC 0x0c082774 */
if(!s->budget--) { s->failed_pc=0x0c082774u; return 0; }
r[15]+=0x0000000cu;
goto P_0c082776;
P_0c082776: /* original 9a4a, guest PC 0x0c082776 */
if(!s->budget--) { s->failed_pc=0x0c082776u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08280eu,2);
goto P_0c082778;
P_0c082778: /* original e700, guest PC 0x0c082778 */
if(!s->budget--) { s->failed_pc=0x0c082778u; return 0; }
r[7]=0x00000000u;
goto P_0c08277a;
P_0c08277a: /* original 2fe6, guest PC 0x0c08277a */
if(!s->budget--) { s->failed_pc=0x0c08277au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08277c;
P_0c08277c: /* original 66d3, guest PC 0x0c08277c */
if(!s->budget--) { s->failed_pc=0x0c08277cu; return 0; }
r[6]=r[13];
goto P_0c08277e;
P_0c08277e: /* original 50f3, guest PC 0x0c08277e */
if(!s->budget--) { s->failed_pc=0x0c08277eu; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c082780;
P_0c082780: /* original 059e, guest PC 0x0c082780 */
if(!s->budget--) { s->failed_pc=0x0c082780u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c082782;
P_0c082782: /* original 4c0b, guest PC 0x0c082782 */
if(!s->budget--) { s->failed_pc=0x0c082782u; return 0; }
target=r[12];
r[16]=code_base|0x0c082786u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082786u) { target=s->pc; goto dispatch; }
goto P_0c082786;
P_0c082784: /* original 64a3, guest PC 0x0c082784 */
if(!s->budget--) { s->failed_pc=0x0c082784u; return 0; }
r[4]=r[10];
goto P_0c082786;
P_0c082786: /* original 7f04, guest PC 0x0c082786 */
if(!s->budget--) { s->failed_pc=0x0c082786u; return 0; }
r[15]+=0x00000004u;
goto P_0c082788;
P_0c082788: /* original d325, guest PC 0x0c082788 */
if(!s->budget--) { s->failed_pc=0x0c082788u; return 0; }
r[3]=read(ram,0x0c082820u,4);
goto P_0c08278a;
P_0c08278a: /* original 6032, guest PC 0x0c08278a */
if(!s->budget--) { s->failed_pc=0x0c08278au; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c08278c;
P_0c08278c: /* original c810, guest PC 0x0c08278c */
if(!s->budget--) { s->failed_pc=0x0c08278cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c08278e;
P_0c08278e: /* original 8904, guest PC 0x0c08278e */
if(!s->budget--) { s->failed_pc=0x0c08278eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08279a; }
goto P_0c082790;
P_0c082790: /* original 5183, guest PC 0x0c082790 */
if(!s->budget--) { s->failed_pc=0x0c082790u; return 0; }
r[1]=read(ram,r[8]+12,4);
goto P_0c082792;
P_0c082792: /* original 4115, guest PC 0x0c082792 */
if(!s->budget--) { s->failed_pc=0x0c082792u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c082794;
P_0c082794: /* original 8901, guest PC 0x0c082794 */
if(!s->budget--) { s->failed_pc=0x0c082794u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08279a; }
goto P_0c082796;
P_0c082796: /* original a1f4, guest PC 0x0c082796 */
if(!s->budget--) { s->failed_pc=0x0c082796u; return 0; }
goto P_0c082b82;
P_0c082798: /* original 0009, guest PC 0x0c082798 */
if(!s->budget--) { s->failed_pc=0x0c082798u; return 0; }
goto P_0c08279a;
P_0c08279a: /* original 9339, guest PC 0x0c08279a */
if(!s->budget--) { s->failed_pc=0x0c08279au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082810u,2);
goto P_0c08279c;
P_0c08279c: /* original 66b3, guest PC 0x0c08279c */
if(!s->budget--) { s->failed_pc=0x0c08279cu; return 0; }
r[6]=r[11];
goto P_0c08279e;
P_0c08279e: /* original e700, guest PC 0x0c08279e */
if(!s->budget--) { s->failed_pc=0x0c08279eu; return 0; }
r[7]=0x00000000u;
goto P_0c0827a0;
P_0c0827a0: /* original 2f32, guest PC 0x0c0827a0 */
if(!s->budget--) { s->failed_pc=0x0c0827a0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0827a2;
P_0c0827a2: /* original 2fe6, guest PC 0x0c0827a2 */
if(!s->budget--) { s->failed_pc=0x0c0827a2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0827a4;
P_0c0827a4: /* original 9535, guest PC 0x0c0827a4 */
if(!s->budget--) { s->failed_pc=0x0c0827a4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082812u,2);
goto P_0c0827a6;
P_0c0827a6: /* original 4c0b, guest PC 0x0c0827a6 */
if(!s->budget--) { s->failed_pc=0x0c0827a6u; return 0; }
target=r[12];
r[16]=code_base|0x0c0827aau;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0827aau) { target=s->pc; goto dispatch; }
goto P_0c0827aa;
P_0c0827a8: /* original 54f1, guest PC 0x0c0827a8 */
if(!s->budget--) { s->failed_pc=0x0c0827a8u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0827aa;
P_0c0827aa: /* original 5383, guest PC 0x0c0827aa */
if(!s->budget--) { s->failed_pc=0x0c0827aau; return 0; }
r[3]=read(ram,r[8]+12,4);
goto P_0c0827ac;
P_0c0827ac: /* original 4315, guest PC 0x0c0827ac */
if(!s->budget--) { s->failed_pc=0x0c0827acu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c0827ae;
P_0c0827ae: /* original 8d1f, guest PC 0x0c0827ae */
if(!s->budget--) { s->failed_pc=0x0c0827aeu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c0827f0; }
goto P_0c0827b2;
P_0c0827b0: /* original 7f04, guest PC 0x0c0827b0 */
if(!s->budget--) { s->failed_pc=0x0c0827b0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0827b2;
P_0c0827b2: /* original 50f4, guest PC 0x0c0827b2 */
if(!s->budget--) { s->failed_pc=0x0c0827b2u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c0827b4;
P_0c0827b4: /* original 8809, guest PC 0x0c0827b4 */
if(!s->budget--) { s->failed_pc=0x0c0827b4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0827b6;
P_0c0827b6: /* original 891b, guest PC 0x0c0827b6 */
if(!s->budget--) { s->failed_pc=0x0c0827b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0827f0; }
goto P_0c0827b8;
P_0c0827b8: /* original 54f4, guest PC 0x0c0827b8 */
if(!s->budget--) { s->failed_pc=0x0c0827b8u; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c0827ba;
P_0c0827ba: /* original 66d3, guest PC 0x0c0827ba */
if(!s->budget--) { s->failed_pc=0x0c0827bau; return 0; }
r[6]=r[13];
goto P_0c0827bc;
P_0c0827bc: /* original d317, guest PC 0x0c0827bc */
if(!s->budget--) { s->failed_pc=0x0c0827bcu; return 0; }
r[3]=read(ram,0x0c08281cu,4);
goto P_0c0827be;
P_0c0827be: /* original e700, guest PC 0x0c0827be */
if(!s->budget--) { s->failed_pc=0x0c0827beu; return 0; }
r[7]=0x00000000u;
goto P_0c0827c0;
P_0c0827c0: /* original 4400, guest PC 0x0c0827c0 */
if(!s->budget--) { s->failed_pc=0x0c0827c0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0827c2;
P_0c0827c2: /* original 343c, guest PC 0x0c0827c2 */
if(!s->budget--) { s->failed_pc=0x0c0827c2u; return 0; }
r[4]+=r[3];
goto P_0c0827c4;
P_0c0827c4: /* original 6240, guest PC 0x0c0827c4 */
if(!s->budget--) { s->failed_pc=0x0c0827c4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c0827c6;
P_0c0827c6: /* original 8441, guest PC 0x0c0827c6 */
if(!s->budget--) { s->failed_pc=0x0c0827c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c0827c8;
P_0c0827c8: /* original 6123, guest PC 0x0c0827c8 */
if(!s->budget--) { s->failed_pc=0x0c0827c8u; return 0; }
r[1]=r[2];
goto P_0c0827ca;
P_0c0827ca: /* original 4208, guest PC 0x0c0827ca */
if(!s->budget--) { s->failed_pc=0x0c0827cau; return 0; }
r[2]<<=2;
goto P_0c0827cc;
P_0c0827cc: /* original 4200, guest PC 0x0c0827cc */
if(!s->budget--) { s->failed_pc=0x0c0827ccu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0827ce;
P_0c0827ce: /* original 321c, guest PC 0x0c0827ce */
if(!s->budget--) { s->failed_pc=0x0c0827ceu; return 0; }
r[2]+=r[1];
goto P_0c0827d0;
P_0c0827d0: /* original 6103, guest PC 0x0c0827d0 */
if(!s->budget--) { s->failed_pc=0x0c0827d0u; return 0; }
r[1]=r[0];
goto P_0c0827d2;
P_0c0827d2: /* original 4108, guest PC 0x0c0827d2 */
if(!s->budget--) { s->failed_pc=0x0c0827d2u; return 0; }
r[1]<<=2;
goto P_0c0827d4;
P_0c0827d4: /* original 7204, guest PC 0x0c0827d4 */
if(!s->budget--) { s->failed_pc=0x0c0827d4u; return 0; }
r[2]+=0x00000004u;
goto P_0c0827d6;
P_0c0827d6: /* original 4200, guest PC 0x0c0827d6 */
if(!s->budget--) { s->failed_pc=0x0c0827d6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0827d8;
P_0c0827d8: /* original 4000, guest PC 0x0c0827d8 */
if(!s->budget--) { s->failed_pc=0x0c0827d8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0827da;
P_0c0827da: /* original 301c, guest PC 0x0c0827da */
if(!s->budget--) { s->failed_pc=0x0c0827dau; return 0; }
r[0]+=r[1];
goto P_0c0827dc;
P_0c0827dc: /* original e107, guest PC 0x0c0827dc */
if(!s->budget--) { s->failed_pc=0x0c0827dcu; return 0; }
r[1]=0x00000007u;
goto P_0c0827de;
P_0c0827de: /* original 700e, guest PC 0x0c0827de */
if(!s->budget--) { s->failed_pc=0x0c0827deu; return 0; }
r[0]+=0x0000000eu;
goto P_0c0827e0;
P_0c0827e0: /* original 401c, guest PC 0x0c0827e0 */
if(!s->budget--) { s->failed_pc=0x0c0827e0u; return 0; }
r[0]=(r[1]&0x80000000u)?((r[1]&31u)?(uint32_t)((int32_t)r[0]>>((-r[1])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[1]&31u);
goto P_0c0827e2;
P_0c0827e2: /* original 220b, guest PC 0x0c0827e2 */
if(!s->budget--) { s->failed_pc=0x0c0827e2u; return 0; }
r[2]|=r[0];
goto P_0c0827e4;
P_0c0827e4: /* original 2f22, guest PC 0x0c0827e4 */
if(!s->budget--) { s->failed_pc=0x0c0827e4u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0827e6;
P_0c0827e6: /* original 2fe6, guest PC 0x0c0827e6 */
if(!s->budget--) { s->failed_pc=0x0c0827e6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0827e8;
P_0c0827e8: /* original 9514, guest PC 0x0c0827e8 */
if(!s->budget--) { s->failed_pc=0x0c0827e8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082814u,2);
goto P_0c0827ea;
P_0c0827ea: /* original 4c0b, guest PC 0x0c0827ea */
if(!s->budget--) { s->failed_pc=0x0c0827eau; return 0; }
target=r[12];
r[16]=code_base|0x0c0827eeu;
r[4]=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0827eeu) { target=s->pc; goto dispatch; }
goto P_0c0827ee;
P_0c0827ec: /* original 6423, guest PC 0x0c0827ec */
if(!s->budget--) { s->failed_pc=0x0c0827ecu; return 0; }
r[4]=r[2];
goto P_0c0827ee;
P_0c0827ee: /* original 7f04, guest PC 0x0c0827ee */
if(!s->budget--) { s->failed_pc=0x0c0827eeu; return 0; }
r[15]+=0x00000004u;
goto P_0c0827f0;
P_0c0827f0: /* original e301, guest PC 0x0c0827f0 */
if(!s->budget--) { s->failed_pc=0x0c0827f0u; return 0; }
r[3]=0x00000001u;
goto P_0c0827f2;
P_0c0827f2: /* original 9a10, guest PC 0x0c0827f2 */
if(!s->budget--) { s->failed_pc=0x0c0827f2u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082816u,2);
goto P_0c0827f4;
P_0c0827f4: /* original 66b3, guest PC 0x0c0827f4 */
if(!s->budget--) { s->failed_pc=0x0c0827f4u; return 0; }
r[6]=r[11];
goto P_0c0827f6;
P_0c0827f6: /* original 2f36, guest PC 0x0c0827f6 */
if(!s->budget--) { s->failed_pc=0x0c0827f6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0827f8;
P_0c0827f8: /* original 950e, guest PC 0x0c0827f8 */
if(!s->budget--) { s->failed_pc=0x0c0827f8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082818u,2);
goto P_0c0827fa;
P_0c0827fa: /* original e700, guest PC 0x0c0827fa */
if(!s->budget--) { s->failed_pc=0x0c0827fau; return 0; }
r[7]=0x00000000u;
goto P_0c0827fc;
P_0c0827fc: /* original 4c0b, guest PC 0x0c0827fc */
if(!s->budget--) { s->failed_pc=0x0c0827fcu; return 0; }
target=r[12];
r[16]=code_base|0x0c082800u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082800u) { target=s->pc; goto dispatch; }
goto P_0c082800;
P_0c0827fe: /* original 64a3, guest PC 0x0c0827fe */
if(!s->budget--) { s->failed_pc=0x0c0827feu; return 0; }
r[4]=r[10];
goto P_0c082800;
P_0c082800: /* original a1bf, guest PC 0x0c082800 */
if(!s->budget--) { s->failed_pc=0x0c082800u; return 0; }
r[15]+=0x00000004u;
goto P_0c082b82;
P_0c082802: /* original 7f04, guest PC 0x0c082802 */
if(!s->budget--) { s->failed_pc=0x0c082802u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c082804u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c082804u; return 0; } return 1;
P_0c082824: /* original a05e, guest PC 0x0c082824 */
if(!s->budget--) { s->failed_pc=0x0c082824u; return 0; }
r[10]=r[14];
goto P_0c0828e4;
P_0c082826: /* original 6ae3, guest PC 0x0c082826 */
if(!s->budget--) { s->failed_pc=0x0c082826u; return 0; }
r[10]=r[14];
goto P_0c082828;
P_0c082828: /* original d00c, guest PC 0x0c082828 */
if(!s->budget--) { s->failed_pc=0x0c082828u; return 0; }
r[0]=read(ram,0x0c08285cu,4);
goto P_0c08282a;
P_0c08282a: /* original 62a3, guest PC 0x0c08282a */
if(!s->budget--) { s->failed_pc=0x0c08282au; return 0; }
r[2]=r[10];
goto P_0c08282c;
P_0c08282c: /* original 4208, guest PC 0x0c08282c */
if(!s->budget--) { s->failed_pc=0x0c08282cu; return 0; }
r[2]<<=2;
goto P_0c08282e;
P_0c08282e: /* original 61a3, guest PC 0x0c08282e */
if(!s->budget--) { s->failed_pc=0x0c08282eu; return 0; }
r[1]=r[10];
goto P_0c082830;
P_0c082830: /* original 032e, guest PC 0x0c082830 */
if(!s->budget--) { s->failed_pc=0x0c082830u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c082832;
P_0c082832: /* original 2f32, guest PC 0x0c082832 */
if(!s->budget--) { s->failed_pc=0x0c082832u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c082834;
P_0c082834: /* original 5483, guest PC 0x0c082834 */
if(!s->budget--) { s->failed_pc=0x0c082834u; return 0; }
r[4]=read(ram,r[8]+12,4);
goto P_0c082836;
P_0c082836: /* original d30a, guest PC 0x0c082836 */
if(!s->budget--) { s->failed_pc=0x0c082836u; return 0; }
r[3]=read(ram,0x0c082860u,4);
goto P_0c082838;
P_0c082838: /* original 644b, guest PC 0x0c082838 */
if(!s->budget--) { s->failed_pc=0x0c082838u; return 0; }
r[4]=0u-r[4];
goto P_0c08283a;
P_0c08283a: /* original 7420, guest PC 0x0c08283a */
if(!s->budget--) { s->failed_pc=0x0c08283au; return 0; }
r[4]+=0x00000020u;
goto P_0c08283c;
P_0c08283c: /* original 430b, guest PC 0x0c08283c */
if(!s->budget--) { s->failed_pc=0x0c08283cu; return 0; }
target=r[3];
r[16]=code_base|0x0c082840u;
r[0]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082840u) { target=s->pc; goto dispatch; }
goto P_0c082840;
P_0c08283e: /* original e002, guest PC 0x0c08283e */
if(!s->budget--) { s->failed_pc=0x0c08283eu; return 0; }
r[0]=0x00000002u;
goto P_0c082840;
P_0c082840: /* original 2008, guest PC 0x0c082840 */
if(!s->budget--) { s->failed_pc=0x0c082840u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c082842;
P_0c082842: /* original 8911, guest PC 0x0c082842 */
if(!s->budget--) { s->failed_pc=0x0c082842u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c082868; }
goto P_0c082844;
P_0c082844: /* original 66a3, guest PC 0x0c082844 */
if(!s->budget--) { s->failed_pc=0x0c082844u; return 0; }
r[6]=r[10];
goto P_0c082846;
P_0c082846: /* original d307, guest PC 0x0c082846 */
if(!s->budget--) { s->failed_pc=0x0c082846u; return 0; }
r[3]=read(ram,0x0c082864u,4);
goto P_0c082848;
P_0c082848: /* original 4608, guest PC 0x0c082848 */
if(!s->budget--) { s->failed_pc=0x0c082848u; return 0; }
r[6]<<=2;
goto P_0c08284a;
P_0c08284a: /* original 4600, guest PC 0x0c08284a */
if(!s->budget--) { s->failed_pc=0x0c08284au; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c08284c;
P_0c08284c: /* original 363c, guest PC 0x0c08284c */
if(!s->budget--) { s->failed_pc=0x0c08284cu; return 0; }
r[6]+=r[3];
goto P_0c08284e;
P_0c08284e: /* original 5261, guest PC 0x0c08284e */
if(!s->budget--) { s->failed_pc=0x0c08284eu; return 0; }
r[2]=read(ram,r[6]+4,4);
goto P_0c082850;
P_0c082850: /* original 6662, guest PC 0x0c082850 */
if(!s->budget--) { s->failed_pc=0x0c082850u; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c082852;
P_0c082852: /* original 3428, guest PC 0x0c082852 */
if(!s->budget--) { s->failed_pc=0x0c082852u; return 0; }
r[4]-=r[2];
goto P_0c082854;
P_0c082854: /* original 0647, guest PC 0x0c082854 */
if(!s->budget--) { s->failed_pc=0x0c082854u; return 0; }
r[19]=r[6]*r[4];
goto P_0c082856;
P_0c082856: /* original 051a, guest PC 0x0c082856 */
if(!s->budget--) { s->failed_pc=0x0c082856u; return 0; }
r[5]=r[19];
goto P_0c082858;
P_0c082858: /* original a014, guest PC 0x0c082858 */
if(!s->budget--) { s->failed_pc=0x0c082858u; return 0; }
r[5]+=0xfffffff8u;
goto P_0c082884;
P_0c08285a: /* original 75f8, guest PC 0x0c08285a */
if(!s->budget--) { s->failed_pc=0x0c08285au; return 0; }
r[5]+=0xfffffff8u;
if(!vf3_matrix_family(0x0c08285cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08285cu; return 0; } return 1;
P_0c082868: /* original e60c, guest PC 0x0c082868 */
if(!s->budget--) { s->failed_pc=0x0c082868u; return 0; }
r[6]=0x0000000cu;
goto P_0c08286a;
P_0c08286a: /* original d34f, guest PC 0x0c08286a */
if(!s->budget--) { s->failed_pc=0x0c08286au; return 0; }
r[3]=read(ram,0x0c0829a8u,4);
goto P_0c08286c;
P_0c08286c: /* original 36a8, guest PC 0x0c08286c */
if(!s->budget--) { s->failed_pc=0x0c08286cu; return 0; }
r[6]-=r[10];
goto P_0c08286e;
P_0c08286e: /* original 6563, guest PC 0x0c08286e */
if(!s->budget--) { s->failed_pc=0x0c08286eu; return 0; }
r[5]=r[6];
goto P_0c082870;
P_0c082870: /* original 4508, guest PC 0x0c082870 */
if(!s->budget--) { s->failed_pc=0x0c082870u; return 0; }
r[5]<<=2;
goto P_0c082872;
P_0c082872: /* original 4500, guest PC 0x0c082872 */
if(!s->budget--) { s->failed_pc=0x0c082872u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c082874;
P_0c082874: /* original 353c, guest PC 0x0c082874 */
if(!s->budget--) { s->failed_pc=0x0c082874u; return 0; }
r[5]+=r[3];
goto P_0c082876;
P_0c082876: /* original 6652, guest PC 0x0c082876 */
if(!s->budget--) { s->failed_pc=0x0c082876u; return 0; }
tmp=read(ram,r[5],4);
r[6]=tmp;
goto P_0c082878;
P_0c082878: /* original 5251, guest PC 0x0c082878 */
if(!s->budget--) { s->failed_pc=0x0c082878u; return 0; }
r[2]=read(ram,r[5]+4,4);
goto P_0c08287a;
P_0c08287a: /* original 76f6, guest PC 0x0c08287a */
if(!s->budget--) { s->failed_pc=0x0c08287au; return 0; }
r[6]+=0xfffffff6u;
goto P_0c08287c;
P_0c08287c: /* original 3428, guest PC 0x0c08287c */
if(!s->budget--) { s->failed_pc=0x0c08287cu; return 0; }
r[4]-=r[2];
goto P_0c08287e;
P_0c08287e: /* original 0647, guest PC 0x0c08287e */
if(!s->budget--) { s->failed_pc=0x0c08287eu; return 0; }
r[19]=r[6]*r[4];
goto P_0c082880;
P_0c082880: /* original 051a, guest PC 0x0c082880 */
if(!s->budget--) { s->failed_pc=0x0c082880u; return 0; }
r[5]=r[19];
goto P_0c082882;
P_0c082882: /* original 7538, guest PC 0x0c082882 */
if(!s->budget--) { s->failed_pc=0x0c082882u; return 0; }
r[5]+=0x00000038u;
goto P_0c082884;
P_0c082884: /* original 4411, guest PC 0x0c082884 */
if(!s->budget--) { s->failed_pc=0x0c082884u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c082886;
P_0c082886: /* original 8b2c, guest PC 0x0c082886 */
if(!s->budget--) { s->failed_pc=0x0c082886u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0828e2; }
goto P_0c082888;
P_0c082888: /* original 64f2, guest PC 0x0c082888 */
if(!s->budget--) { s->failed_pc=0x0c082888u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c08288a;
P_0c08288a: /* original 61a3, guest PC 0x0c08288a */
if(!s->budget--) { s->failed_pc=0x0c08288au; return 0; }
r[1]=r[10];
goto P_0c08288c;
P_0c08288c: /* original d047, guest PC 0x0c08288c */
if(!s->budget--) { s->failed_pc=0x0c08288cu; return 0; }
r[0]=read(ram,0x0c0829acu,4);
goto P_0c08288e;
P_0c08288e: /* original 4400, guest PC 0x0c08288e */
if(!s->budget--) { s->failed_pc=0x0c08288eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c082890;
P_0c082890: /* original d347, guest PC 0x0c082890 */
if(!s->budget--) { s->failed_pc=0x0c082890u; return 0; }
r[3]=read(ram,0x0c0829b0u,4);
goto P_0c082892;
P_0c082892: /* original 044c, guest PC 0x0c082892 */
if(!s->budget--) { s->failed_pc=0x0c082892u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c082894;
P_0c082894: /* original 7404, guest PC 0x0c082894 */
if(!s->budget--) { s->failed_pc=0x0c082894u; return 0; }
r[4]+=0x00000004u;
goto P_0c082896;
P_0c082896: /* original 430b, guest PC 0x0c082896 */
if(!s->budget--) { s->failed_pc=0x0c082896u; return 0; }
target=r[3];
r[16]=code_base|0x0c08289au;
r[0]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08289au) { target=s->pc; goto dispatch; }
goto P_0c08289a;
P_0c082898: /* original e002, guest PC 0x0c082898 */
if(!s->budget--) { s->failed_pc=0x0c082898u; return 0; }
r[0]=0x00000002u;
goto P_0c08289a;
P_0c08289a: /* original 2008, guest PC 0x0c08289a */
if(!s->budget--) { s->failed_pc=0x0c08289au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c08289c;
P_0c08289c: /* original 8f02, guest PC 0x0c08289c */
if(!s->budget--) { s->failed_pc=0x0c08289cu; return 0; }
cond=r[17]&1u;
r[6]=r[0];
if(!cond) { goto P_0c0828a4; }
goto P_0c0828a0;
P_0c08289e: /* original 6603, guest PC 0x0c08289e */
if(!s->budget--) { s->failed_pc=0x0c08289eu; return 0; }
r[6]=r[0];
goto P_0c0828a0;
P_0c0828a0: /* original 3543, guest PC 0x0c0828a0 */
if(!s->budget--) { s->failed_pc=0x0c0828a0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[4])!=0);
goto P_0c0828a2;
P_0c0828a2: /* original 8b03, guest PC 0x0c0828a2 */
if(!s->budget--) { s->failed_pc=0x0c0828a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0828ac; }
goto P_0c0828a4;
P_0c0828a4: /* original 2668, guest PC 0x0c0828a4 */
if(!s->budget--) { s->failed_pc=0x0c0828a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0828a6;
P_0c0828a6: /* original 8902, guest PC 0x0c0828a6 */
if(!s->budget--) { s->failed_pc=0x0c0828a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0828ae; }
goto P_0c0828a8;
P_0c0828a8: /* original 3547, guest PC 0x0c0828a8 */
if(!s->budget--) { s->failed_pc=0x0c0828a8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[4])!=0);
goto P_0c0828aa;
P_0c0828aa: /* original 8b00, guest PC 0x0c0828aa */
if(!s->budget--) { s->failed_pc=0x0c0828aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0828ae; }
goto P_0c0828ac;
P_0c0828ac: /* original 6543, guest PC 0x0c0828ac */
if(!s->budget--) { s->failed_pc=0x0c0828acu; return 0; }
r[5]=r[4];
goto P_0c0828ae;
P_0c0828ae: /* original 60f2, guest PC 0x0c0828ae */
if(!s->budget--) { s->failed_pc=0x0c0828aeu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0828b0;
P_0c0828b0: /* original d140, guest PC 0x0c0828b0 */
if(!s->budget--) { s->failed_pc=0x0c0828b0u; return 0; }
r[1]=read(ram,0x0c0829b4u,4);
goto P_0c0828b2;
P_0c0828b2: /* original 4008, guest PC 0x0c0828b2 */
if(!s->budget--) { s->failed_pc=0x0c0828b2u; return 0; }
r[0]<<=2;
goto P_0c0828b4;
P_0c0828b4: /* original 001e, guest PC 0x0c0828b4 */
if(!s->budget--) { s->failed_pc=0x0c0828b4u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c0828b6;
P_0c0828b6: /* original 88ff, guest PC 0x0c0828b6 */
if(!s->budget--) { s->failed_pc=0x0c0828b6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0828b8;
P_0c0828b8: /* original 8913, guest PC 0x0c0828b8 */
if(!s->budget--) { s->failed_pc=0x0c0828b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0828e2; }
goto P_0c0828ba;
P_0c0828ba: /* original 62f2, guest PC 0x0c0828ba */
if(!s->budget--) { s->failed_pc=0x0c0828bau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0828bc;
P_0c0828bc: /* original e700, guest PC 0x0c0828bc */
if(!s->budget--) { s->failed_pc=0x0c0828bcu; return 0; }
r[7]=0x00000000u;
goto P_0c0828be;
P_0c0828be: /* original d03e, guest PC 0x0c0828be */
if(!s->budget--) { s->failed_pc=0x0c0828beu; return 0; }
r[0]=read(ram,0x0c0829b8u,4);
goto P_0c0828c0;
P_0c0828c0: /* original 66b3, guest PC 0x0c0828c0 */
if(!s->budget--) { s->failed_pc=0x0c0828c0u; return 0; }
r[6]=r[11];
goto P_0c0828c2;
P_0c0828c2: /* original 4200, guest PC 0x0c0828c2 */
if(!s->budget--) { s->failed_pc=0x0c0828c2u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0828c4;
P_0c0828c4: /* original 032c, guest PC 0x0c0828c4 */
if(!s->budget--) { s->failed_pc=0x0c0828c4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c0828c6;
P_0c0828c6: /* original e207, guest PC 0x0c0828c6 */
if(!s->budget--) { s->failed_pc=0x0c0828c6u; return 0; }
r[2]=0x00000007u;
goto P_0c0828c8;
P_0c0828c8: /* original 4500, guest PC 0x0c0828c8 */
if(!s->budget--) { s->failed_pc=0x0c0828c8u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0828ca;
P_0c0828ca: /* original 730e, guest PC 0x0c0828ca */
if(!s->budget--) { s->failed_pc=0x0c0828cau; return 0; }
r[3]+=0x0000000eu;
goto P_0c0828cc;
P_0c0828cc: /* original 432c, guest PC 0x0c0828cc */
if(!s->budget--) { s->failed_pc=0x0c0828ccu; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c0828ce;
P_0c0828ce: /* original 235b, guest PC 0x0c0828ce */
if(!s->budget--) { s->failed_pc=0x0c0828ceu; return 0; }
r[3]|=r[5];
goto P_0c0828d0;
P_0c0828d0: /* original 1f31, guest PC 0x0c0828d0 */
if(!s->budget--) { s->failed_pc=0x0c0828d0u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0828d2;
P_0c0828d2: /* original 2fe6, guest PC 0x0c0828d2 */
if(!s->budget--) { s->failed_pc=0x0c0828d2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0828d4;
P_0c0828d4: /* original 55f1, guest PC 0x0c0828d4 */
if(!s->budget--) { s->failed_pc=0x0c0828d4u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0828d6;
P_0c0828d6: /* original d037, guest PC 0x0c0828d6 */
if(!s->budget--) { s->failed_pc=0x0c0828d6u; return 0; }
r[0]=read(ram,0x0c0829b4u,4);
goto P_0c0828d8;
P_0c0828d8: /* original 4508, guest PC 0x0c0828d8 */
if(!s->budget--) { s->failed_pc=0x0c0828d8u; return 0; }
r[5]<<=2;
goto P_0c0828da;
P_0c0828da: /* original 055e, guest PC 0x0c0828da */
if(!s->budget--) { s->failed_pc=0x0c0828dau; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c0828dc;
P_0c0828dc: /* original 4c0b, guest PC 0x0c0828dc */
if(!s->budget--) { s->failed_pc=0x0c0828dcu; return 0; }
target=r[12];
r[16]=code_base|0x0c0828e0u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0828e0u) { target=s->pc; goto dispatch; }
goto P_0c0828e0;
P_0c0828de: /* original 54f2, guest PC 0x0c0828de */
if(!s->budget--) { s->failed_pc=0x0c0828deu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0828e0;
P_0c0828e0: /* original 7f04, guest PC 0x0c0828e0 */
if(!s->budget--) { s->failed_pc=0x0c0828e0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0828e2;
P_0c0828e2: /* original 7a01, guest PC 0x0c0828e2 */
if(!s->budget--) { s->failed_pc=0x0c0828e2u; return 0; }
r[10]+=0x00000001u;
goto P_0c0828e4;
P_0c0828e4: /* original e30d, guest PC 0x0c0828e4 */
if(!s->budget--) { s->failed_pc=0x0c0828e4u; return 0; }
r[3]=0x0000000du;
goto P_0c0828e6;
P_0c0828e6: /* original 3a33, guest PC 0x0c0828e6 */
if(!s->budget--) { s->failed_pc=0x0c0828e6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[3])!=0);
goto P_0c0828e8;
P_0c0828e8: /* original 8b9e, guest PC 0x0c0828e8 */
if(!s->budget--) { s->failed_pc=0x0c0828e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c082828; }
goto P_0c0828ea;
P_0c0828ea: /* original 9153, guest PC 0x0c0828ea */
if(!s->budget--) { s->failed_pc=0x0c0828eau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082994u,2);
goto P_0c0828ec;
P_0c0828ec: /* original 66b3, guest PC 0x0c0828ec */
if(!s->budget--) { s->failed_pc=0x0c0828ecu; return 0; }
r[6]=r[11];
goto P_0c0828ee;
P_0c0828ee: /* original e700, guest PC 0x0c0828ee */
if(!s->budget--) { s->failed_pc=0x0c0828eeu; return 0; }
r[7]=0x00000000u;
goto P_0c0828f0;
P_0c0828f0: /* original 2f12, guest PC 0x0c0828f0 */
if(!s->budget--) { s->failed_pc=0x0c0828f0u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0828f2;
P_0c0828f2: /* original 2fe6, guest PC 0x0c0828f2 */
if(!s->budget--) { s->failed_pc=0x0c0828f2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0828f4;
P_0c0828f4: /* original 954f, guest PC 0x0c0828f4 */
if(!s->budget--) { s->failed_pc=0x0c0828f4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082996u,2);
goto P_0c0828f6;
P_0c0828f6: /* original 4c0b, guest PC 0x0c0828f6 */
if(!s->budget--) { s->failed_pc=0x0c0828f6u; return 0; }
target=r[12];
r[16]=code_base|0x0c0828fau;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0828fau) { target=s->pc; goto dispatch; }
goto P_0c0828fa;
P_0c0828f8: /* original 54f1, guest PC 0x0c0828f8 */
if(!s->budget--) { s->failed_pc=0x0c0828f8u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0828fa;
P_0c0828fa: /* original 934d, guest PC 0x0c0828fa */
if(!s->budget--) { s->failed_pc=0x0c0828fau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082998u,2);
goto P_0c0828fc;
P_0c0828fc: /* original 66b3, guest PC 0x0c0828fc */
if(!s->budget--) { s->failed_pc=0x0c0828fcu; return 0; }
r[6]=r[11];
goto P_0c0828fe;
P_0c0828fe: /* original e700, guest PC 0x0c0828fe */
if(!s->budget--) { s->failed_pc=0x0c0828feu; return 0; }
r[7]=0x00000000u;
goto P_0c082900;
P_0c082900: /* original 1f31, guest PC 0x0c082900 */
if(!s->budget--) { s->failed_pc=0x0c082900u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c082902;
P_0c082902: /* original 2fe6, guest PC 0x0c082902 */
if(!s->budget--) { s->failed_pc=0x0c082902u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082904;
P_0c082904: /* original 9549, guest PC 0x0c082904 */
if(!s->budget--) { s->failed_pc=0x0c082904u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08299au,2);
goto P_0c082906;
P_0c082906: /* original 4c0b, guest PC 0x0c082906 */
if(!s->budget--) { s->failed_pc=0x0c082906u; return 0; }
target=r[12];
r[16]=code_base|0x0c08290au;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08290au) { target=s->pc; goto dispatch; }
goto P_0c08290a;
P_0c082908: /* original 54f2, guest PC 0x0c082908 */
if(!s->budget--) { s->failed_pc=0x0c082908u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c08290a;
P_0c08290a: /* original 9347, guest PC 0x0c08290a */
if(!s->budget--) { s->failed_pc=0x0c08290au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08299cu,2);
goto P_0c08290c;
P_0c08290c: /* original e700, guest PC 0x0c08290c */
if(!s->budget--) { s->failed_pc=0x0c08290cu; return 0; }
r[7]=0x00000000u;
goto P_0c08290e;
P_0c08290e: /* original 66d3, guest PC 0x0c08290e */
if(!s->budget--) { s->failed_pc=0x0c08290eu; return 0; }
r[6]=r[13];
goto P_0c082910;
P_0c082910: /* original 1f32, guest PC 0x0c082910 */
if(!s->budget--) { s->failed_pc=0x0c082910u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c082912;
P_0c082912: /* original 2fe6, guest PC 0x0c082912 */
if(!s->budget--) { s->failed_pc=0x0c082912u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082914;
P_0c082914: /* original 50f6, guest PC 0x0c082914 */
if(!s->budget--) { s->failed_pc=0x0c082914u; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c082916;
P_0c082916: /* original 059e, guest PC 0x0c082916 */
if(!s->budget--) { s->failed_pc=0x0c082916u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c082918;
P_0c082918: /* original 4c0b, guest PC 0x0c082918 */
if(!s->budget--) { s->failed_pc=0x0c082918u; return 0; }
target=r[12];
r[16]=code_base|0x0c08291cu;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08291cu) { target=s->pc; goto dispatch; }
goto P_0c08291c;
P_0c08291a: /* original 54f3, guest PC 0x0c08291a */
if(!s->budget--) { s->failed_pc=0x0c08291au; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c08291c;
P_0c08291c: /* original 9a3f, guest PC 0x0c08291c */
if(!s->budget--) { s->failed_pc=0x0c08291cu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08299eu,2);
goto P_0c08291e;
P_0c08291e: /* original e700, guest PC 0x0c08291e */
if(!s->budget--) { s->failed_pc=0x0c08291eu; return 0; }
r[7]=0x00000000u;
goto P_0c082920;
P_0c082920: /* original 2fe6, guest PC 0x0c082920 */
if(!s->budget--) { s->failed_pc=0x0c082920u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082922;
P_0c082922: /* original 66d3, guest PC 0x0c082922 */
if(!s->budget--) { s->failed_pc=0x0c082922u; return 0; }
r[6]=r[13];
goto P_0c082924;
P_0c082924: /* original 50f6, guest PC 0x0c082924 */
if(!s->budget--) { s->failed_pc=0x0c082924u; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c082926;
P_0c082926: /* original 059e, guest PC 0x0c082926 */
if(!s->budget--) { s->failed_pc=0x0c082926u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c082928;
P_0c082928: /* original 4c0b, guest PC 0x0c082928 */
if(!s->budget--) { s->failed_pc=0x0c082928u; return 0; }
target=r[12];
r[16]=code_base|0x0c08292cu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08292cu) { target=s->pc; goto dispatch; }
goto P_0c08292c;
P_0c08292a: /* original 64a3, guest PC 0x0c08292a */
if(!s->budget--) { s->failed_pc=0x0c08292au; return 0; }
r[4]=r[10];
goto P_0c08292c;
P_0c08292c: /* original 9038, guest PC 0x0c08292c */
if(!s->budget--) { s->failed_pc=0x0c08292cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0829a0u,2);
goto P_0c08292e;
P_0c08292e: /* original 7f10, guest PC 0x0c08292e */
if(!s->budget--) { s->failed_pc=0x0c08292eu; return 0; }
r[15]+=0x00000010u;
goto P_0c082930;
P_0c082930: /* original d31f, guest PC 0x0c082930 */
if(!s->budget--) { s->failed_pc=0x0c082930u; return 0; }
r[3]=read(ram,0x0c0829b0u,4);
goto P_0c082932;
P_0c082932: /* original 018e, guest PC 0x0c082932 */
if(!s->budget--) { s->failed_pc=0x0c082932u; return 0; }
r[1]=read(ram,r[8]+r[0],4);
goto P_0c082934;
P_0c082934: /* original 430b, guest PC 0x0c082934 */
if(!s->budget--) { s->failed_pc=0x0c082934u; return 0; }
target=r[3];
r[16]=code_base|0x0c082938u;
r[0]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082938u) { target=s->pc; goto dispatch; }
goto P_0c082938;
P_0c082936: /* original e010, guest PC 0x0c082936 */
if(!s->budget--) { s->failed_pc=0x0c082936u; return 0; }
r[0]=0x00000010u;
goto P_0c082938;
P_0c082938: /* original 5383, guest PC 0x0c082938 */
if(!s->budget--) { s->failed_pc=0x0c082938u; return 0; }
r[3]=read(ram,r[8]+12,4);
goto P_0c08293a;
P_0c08293a: /* original 4315, guest PC 0x0c08293a */
if(!s->budget--) { s->failed_pc=0x0c08293au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c08293c;
P_0c08293c: /* original 8d11, guest PC 0x0c08293c */
if(!s->budget--) { s->failed_pc=0x0c08293cu; return 0; }
cond=r[17]&1u;
r[9]=r[0];
if(cond) { goto P_0c082962; }
goto P_0c082940;
P_0c08293e: /* original 6903, guest PC 0x0c08293e */
if(!s->budget--) { s->failed_pc=0x0c08293eu; return 0; }
r[9]=r[0];
goto P_0c082940;
P_0c082940: /* original 6093, guest PC 0x0c082940 */
if(!s->budget--) { s->failed_pc=0x0c082940u; return 0; }
r[0]=r[9];
goto P_0c082942;
P_0c082942: /* original d11c, guest PC 0x0c082942 */
if(!s->budget--) { s->failed_pc=0x0c082942u; return 0; }
r[1]=read(ram,0x0c0829b4u,4);
goto P_0c082944;
P_0c082944: /* original 4008, guest PC 0x0c082944 */
if(!s->budget--) { s->failed_pc=0x0c082944u; return 0; }
r[0]<<=2;
goto P_0c082946;
P_0c082946: /* original 9a2c, guest PC 0x0c082946 */
if(!s->budget--) { s->failed_pc=0x0c082946u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0829a2u,2);
goto P_0c082948;
P_0c082948: /* original 001e, guest PC 0x0c082948 */
if(!s->budget--) { s->failed_pc=0x0c082948u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c08294a;
P_0c08294a: /* original 88ff, guest PC 0x0c08294a */
if(!s->budget--) { s->failed_pc=0x0c08294au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c08294c;
P_0c08294c: /* original 8909, guest PC 0x0c08294c */
if(!s->budget--) { s->failed_pc=0x0c08294cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c082962; }
goto P_0c08294e;
P_0c08294e: /* original 6593, guest PC 0x0c08294e */
if(!s->budget--) { s->failed_pc=0x0c08294eu; return 0; }
r[5]=r[9];
goto P_0c082950;
P_0c082950: /* original 4508, guest PC 0x0c082950 */
if(!s->budget--) { s->failed_pc=0x0c082950u; return 0; }
r[5]<<=2;
goto P_0c082952;
P_0c082952: /* original 2fe6, guest PC 0x0c082952 */
if(!s->budget--) { s->failed_pc=0x0c082952u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082954;
P_0c082954: /* original e700, guest PC 0x0c082954 */
if(!s->budget--) { s->failed_pc=0x0c082954u; return 0; }
r[7]=0x00000000u;
goto P_0c082956;
P_0c082956: /* original d017, guest PC 0x0c082956 */
if(!s->budget--) { s->failed_pc=0x0c082956u; return 0; }
r[0]=read(ram,0x0c0829b4u,4);
goto P_0c082958;
P_0c082958: /* original 66d3, guest PC 0x0c082958 */
if(!s->budget--) { s->failed_pc=0x0c082958u; return 0; }
r[6]=r[13];
goto P_0c08295a;
P_0c08295a: /* original 055e, guest PC 0x0c08295a */
if(!s->budget--) { s->failed_pc=0x0c08295au; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c08295c;
P_0c08295c: /* original 4c0b, guest PC 0x0c08295c */
if(!s->budget--) { s->failed_pc=0x0c08295cu; return 0; }
target=r[12];
r[16]=code_base|0x0c082960u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082960u) { target=s->pc; goto dispatch; }
goto P_0c082960;
P_0c08295e: /* original 64a3, guest PC 0x0c08295e */
if(!s->budget--) { s->failed_pc=0x0c08295eu; return 0; }
r[4]=r[10];
goto P_0c082960;
P_0c082960: /* original 7f04, guest PC 0x0c082960 */
if(!s->budget--) { s->failed_pc=0x0c082960u; return 0; }
r[15]+=0x00000004u;
goto P_0c082962;
P_0c082962: /* original d316, guest PC 0x0c082962 */
if(!s->budget--) { s->failed_pc=0x0c082962u; return 0; }
r[3]=read(ram,0x0c0829bcu,4);
goto P_0c082964;
P_0c082964: /* original 6032, guest PC 0x0c082964 */
if(!s->budget--) { s->failed_pc=0x0c082964u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c082966;
P_0c082966: /* original c810, guest PC 0x0c082966 */
if(!s->budget--) { s->failed_pc=0x0c082966u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c082968;
P_0c082968: /* original 8904, guest PC 0x0c082968 */
if(!s->budget--) { s->failed_pc=0x0c082968u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c082974; }
goto P_0c08296a;
P_0c08296a: /* original 5183, guest PC 0x0c08296a */
if(!s->budget--) { s->failed_pc=0x0c08296au; return 0; }
r[1]=read(ram,r[8]+12,4);
goto P_0c08296c;
P_0c08296c: /* original 4115, guest PC 0x0c08296c */
if(!s->budget--) { s->failed_pc=0x0c08296cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c08296e;
P_0c08296e: /* original 8901, guest PC 0x0c08296e */
if(!s->budget--) { s->failed_pc=0x0c08296eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c082974; }
goto P_0c082970;
P_0c082970: /* original a107, guest PC 0x0c082970 */
if(!s->budget--) { s->failed_pc=0x0c082970u; return 0; }
goto P_0c082b82;
P_0c082972: /* original 0009, guest PC 0x0c082972 */
if(!s->budget--) { s->failed_pc=0x0c082972u; return 0; }
goto P_0c082974;
P_0c082974: /* original 9316, guest PC 0x0c082974 */
if(!s->budget--) { s->failed_pc=0x0c082974u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0829a4u,2);
goto P_0c082976;
P_0c082976: /* original 66b3, guest PC 0x0c082976 */
if(!s->budget--) { s->failed_pc=0x0c082976u; return 0; }
r[6]=r[11];
goto P_0c082978;
P_0c082978: /* original e700, guest PC 0x0c082978 */
if(!s->budget--) { s->failed_pc=0x0c082978u; return 0; }
r[7]=0x00000000u;
goto P_0c08297a;
P_0c08297a: /* original 2f32, guest PC 0x0c08297a */
if(!s->budget--) { s->failed_pc=0x0c08297au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08297c;
P_0c08297c: /* original 2fe6, guest PC 0x0c08297c */
if(!s->budget--) { s->failed_pc=0x0c08297cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08297e;
P_0c08297e: /* original 9512, guest PC 0x0c08297e */
if(!s->budget--) { s->failed_pc=0x0c08297eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0829a6u,2);
goto P_0c082980;
P_0c082980: /* original 4c0b, guest PC 0x0c082980 */
if(!s->budget--) { s->failed_pc=0x0c082980u; return 0; }
target=r[12];
r[16]=code_base|0x0c082984u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082984u) { target=s->pc; goto dispatch; }
goto P_0c082984;
P_0c082982: /* original 54f1, guest PC 0x0c082982 */
if(!s->budget--) { s->failed_pc=0x0c082982u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c082984;
P_0c082984: /* original 5383, guest PC 0x0c082984 */
if(!s->budget--) { s->failed_pc=0x0c082984u; return 0; }
r[3]=read(ram,r[8]+12,4);
goto P_0c082986;
P_0c082986: /* original 4315, guest PC 0x0c082986 */
if(!s->budget--) { s->failed_pc=0x0c082986u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c082988;
P_0c082988: /* original 8d2c, guest PC 0x0c082988 */
if(!s->budget--) { s->failed_pc=0x0c082988u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c0829e4; }
goto P_0c08298c;
P_0c08298a: /* original 7f04, guest PC 0x0c08298a */
if(!s->budget--) { s->failed_pc=0x0c08298au; return 0; }
r[15]+=0x00000004u;
goto P_0c08298c;
P_0c08298c: /* original 6493, guest PC 0x0c08298c */
if(!s->budget--) { s->failed_pc=0x0c08298cu; return 0; }
r[4]=r[9];
goto P_0c08298e;
P_0c08298e: /* original 4400, guest PC 0x0c08298e */
if(!s->budget--) { s->failed_pc=0x0c08298eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c082990;
P_0c082990: /* original a016, guest PC 0x0c082990 */
if(!s->budget--) { s->failed_pc=0x0c082990u; return 0; }
goto P_0c0829c0;
P_0c082992: /* original 0009, guest PC 0x0c082992 */
if(!s->budget--) { s->failed_pc=0x0c082992u; return 0; }
if(!vf3_matrix_family(0x0c082994u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c082994u; return 0; } return 1;
P_0c0829c0: /* original d34e, guest PC 0x0c0829c0 */
if(!s->budget--) { s->failed_pc=0x0c0829c0u; return 0; }
r[3]=read(ram,0x0c082afcu,4);
goto P_0c0829c2;
P_0c0829c2: /* original e107, guest PC 0x0c0829c2 */
if(!s->budget--) { s->failed_pc=0x0c0829c2u; return 0; }
r[1]=0x00000007u;
goto P_0c0829c4;
P_0c0829c4: /* original 66d3, guest PC 0x0c0829c4 */
if(!s->budget--) { s->failed_pc=0x0c0829c4u; return 0; }
r[6]=r[13];
goto P_0c0829c6;
P_0c0829c6: /* original e700, guest PC 0x0c0829c6 */
if(!s->budget--) { s->failed_pc=0x0c0829c6u; return 0; }
r[7]=0x00000000u;
goto P_0c0829c8;
P_0c0829c8: /* original 343c, guest PC 0x0c0829c8 */
if(!s->budget--) { s->failed_pc=0x0c0829c8u; return 0; }
r[4]+=r[3];
goto P_0c0829ca;
P_0c0829ca: /* original 8441, guest PC 0x0c0829ca */
if(!s->budget--) { s->failed_pc=0x0c0829cau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c0829cc;
P_0c0829cc: /* original 6240, guest PC 0x0c0829cc */
if(!s->budget--) { s->failed_pc=0x0c0829ccu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c0829ce;
P_0c0829ce: /* original 700e, guest PC 0x0c0829ce */
if(!s->budget--) { s->failed_pc=0x0c0829ceu; return 0; }
r[0]+=0x0000000eu;
goto P_0c0829d0;
P_0c0829d0: /* original 7204, guest PC 0x0c0829d0 */
if(!s->budget--) { s->failed_pc=0x0c0829d0u; return 0; }
r[2]+=0x00000004u;
goto P_0c0829d2;
P_0c0829d2: /* original 401c, guest PC 0x0c0829d2 */
if(!s->budget--) { s->failed_pc=0x0c0829d2u; return 0; }
r[0]=(r[1]&0x80000000u)?((r[1]&31u)?(uint32_t)((int32_t)r[0]>>((-r[1])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[1]&31u);
goto P_0c0829d4;
P_0c0829d4: /* original 4200, guest PC 0x0c0829d4 */
if(!s->budget--) { s->failed_pc=0x0c0829d4u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0829d6;
P_0c0829d6: /* original 220b, guest PC 0x0c0829d6 */
if(!s->budget--) { s->failed_pc=0x0c0829d6u; return 0; }
r[2]|=r[0];
goto P_0c0829d8;
P_0c0829d8: /* original 2f22, guest PC 0x0c0829d8 */
if(!s->budget--) { s->failed_pc=0x0c0829d8u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0829da;
P_0c0829da: /* original 2fe6, guest PC 0x0c0829da */
if(!s->budget--) { s->failed_pc=0x0c0829dau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0829dc;
P_0c0829dc: /* original 9586, guest PC 0x0c0829dc */
if(!s->budget--) { s->failed_pc=0x0c0829dcu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082aecu,2);
goto P_0c0829de;
P_0c0829de: /* original 4c0b, guest PC 0x0c0829de */
if(!s->budget--) { s->failed_pc=0x0c0829deu; return 0; }
target=r[12];
r[16]=code_base|0x0c0829e2u;
r[4]=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0829e2u) { target=s->pc; goto dispatch; }
goto P_0c0829e2;
P_0c0829e0: /* original 6423, guest PC 0x0c0829e0 */
if(!s->budget--) { s->failed_pc=0x0c0829e0u; return 0; }
r[4]=r[2];
goto P_0c0829e2;
P_0c0829e2: /* original 7f04, guest PC 0x0c0829e2 */
if(!s->budget--) { s->failed_pc=0x0c0829e2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0829e4;
P_0c0829e4: /* original 9a83, guest PC 0x0c0829e4 */
if(!s->budget--) { s->failed_pc=0x0c0829e4u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082aeeu,2);
goto P_0c0829e6;
P_0c0829e6: /* original 66b3, guest PC 0x0c0829e6 */
if(!s->budget--) { s->failed_pc=0x0c0829e6u; return 0; }
r[6]=r[11];
goto P_0c0829e8;
P_0c0829e8: /* original 2fe6, guest PC 0x0c0829e8 */
if(!s->budget--) { s->failed_pc=0x0c0829e8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0829ea;
P_0c0829ea: /* original e700, guest PC 0x0c0829ea */
if(!s->budget--) { s->failed_pc=0x0c0829eau; return 0; }
r[7]=0x00000000u;
goto P_0c0829ec;
P_0c0829ec: /* original 9580, guest PC 0x0c0829ec */
if(!s->budget--) { s->failed_pc=0x0c0829ecu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082af0u,2);
goto P_0c0829ee;
P_0c0829ee: /* original 4c0b, guest PC 0x0c0829ee */
if(!s->budget--) { s->failed_pc=0x0c0829eeu; return 0; }
target=r[12];
r[16]=code_base|0x0c0829f2u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0829f2u) { target=s->pc; goto dispatch; }
goto P_0c0829f2;
P_0c0829f0: /* original 64a3, guest PC 0x0c0829f0 */
if(!s->budget--) { s->failed_pc=0x0c0829f0u; return 0; }
r[4]=r[10];
goto P_0c0829f2;
P_0c0829f2: /* original a0c6, guest PC 0x0c0829f2 */
if(!s->budget--) { s->failed_pc=0x0c0829f2u; return 0; }
r[15]+=0x00000004u;
goto P_0c082b82;
P_0c0829f4: /* original 7f04, guest PC 0x0c0829f4 */
if(!s->budget--) { s->failed_pc=0x0c0829f4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0829f6;
P_0c0829f6: /* original 5a83, guest PC 0x0c0829f6 */
if(!s->budget--) { s->failed_pc=0x0c0829f6u; return 0; }
r[10]=read(ram,r[8]+12,4);
goto P_0c0829f8;
P_0c0829f8: /* original e300, guest PC 0x0c0829f8 */
if(!s->budget--) { s->failed_pc=0x0c0829f8u; return 0; }
r[3]=0x00000000u;
goto P_0c0829fa;
P_0c0829fa: /* original 907a, guest PC 0x0c0829fa */
if(!s->budget--) { s->failed_pc=0x0c0829fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082af2u,2);
goto P_0c0829fc;
P_0c0829fc: /* original 7ae0, guest PC 0x0c0829fc */
if(!s->budget--) { s->failed_pc=0x0c0829fcu; return 0; }
r[10]+=0xffffffe0u;
goto P_0c0829fe;
P_0c0829fe: /* original d240, guest PC 0x0c0829fe */
if(!s->budget--) { s->failed_pc=0x0c0829feu; return 0; }
r[2]=read(ram,0x0c082b00u,4);
goto P_0c082a00;
P_0c082a00: /* original 33a7, guest PC 0x0c082a00 */
if(!s->budget--) { s->failed_pc=0x0c082a00u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[10])!=0);
goto P_0c082a02;
P_0c082a02: /* original 018e, guest PC 0x0c082a02 */
if(!s->budget--) { s->failed_pc=0x0c082a02u; return 0; }
r[1]=read(ram,r[8]+r[0],4);
goto P_0c082a04;
P_0c082a04: /* original 3a3e, guest PC 0x0c082a04 */
if(!s->budget--) { s->failed_pc=0x0c082a04u; return 0; }
wide=(uint64_t)r[10]+r[3]+(r[17]&1u); r[10]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c082a06;
P_0c082a06: /* original 4a21, guest PC 0x0c082a06 */
if(!s->budget--) { s->failed_pc=0x0c082a06u; return 0; }
r[17]=(r[17]&~1u)|((r[10]&1)!=0);
r[10]=(uint32_t)((int32_t)r[10]>>1);
goto P_0c082a08;
P_0c082a08: /* original 420b, guest PC 0x0c082a08 */
if(!s->budget--) { s->failed_pc=0x0c082a08u; return 0; }
target=r[2];
r[16]=code_base|0x0c082a0cu;
r[0]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082a0cu) { target=s->pc; goto dispatch; }
goto P_0c082a0c;
P_0c082a0a: /* original e010, guest PC 0x0c082a0a */
if(!s->budget--) { s->failed_pc=0x0c082a0au; return 0; }
r[0]=0x00000010u;
goto P_0c082a0c;
P_0c082a0c: /* original 2f02, guest PC 0x0c082a0c */
if(!s->budget--) { s->failed_pc=0x0c082a0cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c082a0e;
P_0c082a0e: /* original 60a3, guest PC 0x0c082a0e */
if(!s->budget--) { s->failed_pc=0x0c082a0eu; return 0; }
r[0]=r[10];
goto P_0c082a10;
P_0c082a10: /* original e307, guest PC 0x0c082a10 */
if(!s->budget--) { s->failed_pc=0x0c082a10u; return 0; }
r[3]=0x00000007u;
goto P_0c082a12;
P_0c082a12: /* original 66b3, guest PC 0x0c082a12 */
if(!s->budget--) { s->failed_pc=0x0c082a12u; return 0; }
r[6]=r[11];
goto P_0c082a14;
P_0c082a14: /* original 701d, guest PC 0x0c082a14 */
if(!s->budget--) { s->failed_pc=0x0c082a14u; return 0; }
r[0]+=0x0000001du;
goto P_0c082a16;
P_0c082a16: /* original 403c, guest PC 0x0c082a16 */
if(!s->budget--) { s->failed_pc=0x0c082a16u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c082a18;
P_0c082a18: /* original 1f01, guest PC 0x0c082a18 */
if(!s->budget--) { s->failed_pc=0x0c082a18u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c082a1a;
P_0c082a1a: /* original cb18, guest PC 0x0c082a1a */
if(!s->budget--) { s->failed_pc=0x0c082a1au; return 0; }
r[0]|=24u;
goto P_0c082a1c;
P_0c082a1c: /* original 1f04, guest PC 0x0c082a1c */
if(!s->budget--) { s->failed_pc=0x0c082a1cu; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c082a1e;
P_0c082a1e: /* original e700, guest PC 0x0c082a1e */
if(!s->budget--) { s->failed_pc=0x0c082a1eu; return 0; }
r[7]=0x00000000u;
goto P_0c082a20;
P_0c082a20: /* original 2fe6, guest PC 0x0c082a20 */
if(!s->budget--) { s->failed_pc=0x0c082a20u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082a22;
P_0c082a22: /* original 9567, guest PC 0x0c082a22 */
if(!s->budget--) { s->failed_pc=0x0c082a22u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082af4u,2);
goto P_0c082a24;
P_0c082a24: /* original 4c0b, guest PC 0x0c082a24 */
if(!s->budget--) { s->failed_pc=0x0c082a24u; return 0; }
target=r[12];
r[16]=code_base|0x0c082a28u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082a28u) { target=s->pc; goto dispatch; }
goto P_0c082a28;
P_0c082a26: /* original 6403, guest PC 0x0c082a26 */
if(!s->budget--) { s->failed_pc=0x0c082a26u; return 0; }
r[4]=r[0];
goto P_0c082a28;
P_0c082a28: /* original 50f2, guest PC 0x0c082a28 */
if(!s->budget--) { s->failed_pc=0x0c082a28u; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c082a2a;
P_0c082a2a: /* original 66b3, guest PC 0x0c082a2a */
if(!s->budget--) { s->failed_pc=0x0c082a2au; return 0; }
r[6]=r[11];
goto P_0c082a2c;
P_0c082a2c: /* original e700, guest PC 0x0c082a2c */
if(!s->budget--) { s->failed_pc=0x0c082a2cu; return 0; }
r[7]=0x00000000u;
goto P_0c082a2e;
P_0c082a2e: /* original cb4e, guest PC 0x0c082a2e */
if(!s->budget--) { s->failed_pc=0x0c082a2eu; return 0; }
r[0]|=78u;
goto P_0c082a30;
P_0c082a30: /* original 1f05, guest PC 0x0c082a30 */
if(!s->budget--) { s->failed_pc=0x0c082a30u; return 0; }
write(ram,r[15]+20,r[0],4);
goto P_0c082a32;
P_0c082a32: /* original 2fe6, guest PC 0x0c082a32 */
if(!s->budget--) { s->failed_pc=0x0c082a32u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082a34;
P_0c082a34: /* original 955f, guest PC 0x0c082a34 */
if(!s->budget--) { s->failed_pc=0x0c082a34u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082af6u,2);
goto P_0c082a36;
P_0c082a36: /* original 4c0b, guest PC 0x0c082a36 */
if(!s->budget--) { s->failed_pc=0x0c082a36u; return 0; }
target=r[12];
r[16]=code_base|0x0c082a3au;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082a3au) { target=s->pc; goto dispatch; }
goto P_0c082a3a;
P_0c082a38: /* original 6403, guest PC 0x0c082a38 */
if(!s->budget--) { s->failed_pc=0x0c082a38u; return 0; }
r[4]=r[0];
goto P_0c082a3a;
P_0c082a3a: /* original 50f3, guest PC 0x0c082a3a */
if(!s->budget--) { s->failed_pc=0x0c082a3au; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c082a3c;
P_0c082a3c: /* original 66b3, guest PC 0x0c082a3c */
if(!s->budget--) { s->failed_pc=0x0c082a3cu; return 0; }
r[6]=r[11];
goto P_0c082a3e;
P_0c082a3e: /* original e700, guest PC 0x0c082a3e */
if(!s->budget--) { s->failed_pc=0x0c082a3eu; return 0; }
r[7]=0x00000000u;
goto P_0c082a40;
P_0c082a40: /* original cb34, guest PC 0x0c082a40 */
if(!s->budget--) { s->failed_pc=0x0c082a40u; return 0; }
r[0]|=52u;
goto P_0c082a42;
P_0c082a42: /* original 1f03, guest PC 0x0c082a42 */
if(!s->budget--) { s->failed_pc=0x0c082a42u; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c082a44;
P_0c082a44: /* original 2fe6, guest PC 0x0c082a44 */
if(!s->budget--) { s->failed_pc=0x0c082a44u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082a46;
P_0c082a46: /* original 9557, guest PC 0x0c082a46 */
if(!s->budget--) { s->failed_pc=0x0c082a46u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082af8u,2);
goto P_0c082a48;
P_0c082a48: /* original 4c0b, guest PC 0x0c082a48 */
if(!s->budget--) { s->failed_pc=0x0c082a48u; return 0; }
target=r[12];
r[16]=code_base|0x0c082a4cu;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082a4cu) { target=s->pc; goto dispatch; }
goto P_0c082a4c;
P_0c082a4a: /* original 6403, guest PC 0x0c082a4a */
if(!s->budget--) { s->failed_pc=0x0c082a4au; return 0; }
r[4]=r[0];
goto P_0c082a4c;
P_0c082a4c: /* original 60a3, guest PC 0x0c082a4c */
if(!s->budget--) { s->failed_pc=0x0c082a4cu; return 0; }
r[0]=r[10];
goto P_0c082a4e;
P_0c082a4e: /* original e307, guest PC 0x0c082a4e */
if(!s->budget--) { s->failed_pc=0x0c082a4eu; return 0; }
r[3]=0x00000007u;
goto P_0c082a50;
P_0c082a50: /* original 701e, guest PC 0x0c082a50 */
if(!s->budget--) { s->failed_pc=0x0c082a50u; return 0; }
r[0]+=0x0000001eu;
goto P_0c082a52;
P_0c082a52: /* original 66d3, guest PC 0x0c082a52 */
if(!s->budget--) { s->failed_pc=0x0c082a52u; return 0; }
r[6]=r[13];
goto P_0c082a54;
P_0c082a54: /* original 403c, guest PC 0x0c082a54 */
if(!s->budget--) { s->failed_pc=0x0c082a54u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c082a56;
P_0c082a56: /* original 1f04, guest PC 0x0c082a56 */
if(!s->budget--) { s->failed_pc=0x0c082a56u; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c082a58;
P_0c082a58: /* original cb1a, guest PC 0x0c082a58 */
if(!s->budget--) { s->failed_pc=0x0c082a58u; return 0; }
r[0]|=26u;
goto P_0c082a5a;
P_0c082a5a: /* original 1f07, guest PC 0x0c082a5a */
if(!s->budget--) { s->failed_pc=0x0c082a5au; return 0; }
write(ram,r[15]+28,r[0],4);
goto P_0c082a5c;
P_0c082a5c: /* original e700, guest PC 0x0c082a5c */
if(!s->budget--) { s->failed_pc=0x0c082a5cu; return 0; }
r[7]=0x00000000u;
goto P_0c082a5e;
P_0c082a5e: /* original 2fe6, guest PC 0x0c082a5e */
if(!s->budget--) { s->failed_pc=0x0c082a5eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082a60;
P_0c082a60: /* original 50f7, guest PC 0x0c082a60 */
if(!s->budget--) { s->failed_pc=0x0c082a60u; return 0; }
r[0]=read(ram,r[15]+28,4);
goto P_0c082a62;
P_0c082a62: /* original 059e, guest PC 0x0c082a62 */
if(!s->budget--) { s->failed_pc=0x0c082a62u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c082a64;
P_0c082a64: /* original 4c0b, guest PC 0x0c082a64 */
if(!s->budget--) { s->failed_pc=0x0c082a64u; return 0; }
target=r[12];
r[16]=code_base|0x0c082a68u;
r[4]=read(ram,r[15]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082a68u) { target=s->pc; goto dispatch; }
goto P_0c082a68;
P_0c082a66: /* original 54f8, guest PC 0x0c082a66 */
if(!s->budget--) { s->failed_pc=0x0c082a66u; return 0; }
r[4]=read(ram,r[15]+32,4);
goto P_0c082a68;
P_0c082a68: /* original 50f5, guest PC 0x0c082a68 */
if(!s->budget--) { s->failed_pc=0x0c082a68u; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c082a6a;
P_0c082a6a: /* original e700, guest PC 0x0c082a6a */
if(!s->budget--) { s->failed_pc=0x0c082a6au; return 0; }
r[7]=0x00000000u;
goto P_0c082a6c;
P_0c082a6c: /* original 66d3, guest PC 0x0c082a6c */
if(!s->budget--) { s->failed_pc=0x0c082a6cu; return 0; }
r[6]=r[13];
goto P_0c082a6e;
P_0c082a6e: /* original cb50, guest PC 0x0c082a6e */
if(!s->budget--) { s->failed_pc=0x0c082a6eu; return 0; }
r[0]|=80u;
goto P_0c082a70;
P_0c082a70: /* original 1f07, guest PC 0x0c082a70 */
if(!s->budget--) { s->failed_pc=0x0c082a70u; return 0; }
write(ram,r[15]+28,r[0],4);
goto P_0c082a72;
P_0c082a72: /* original 2fe6, guest PC 0x0c082a72 */
if(!s->budget--) { s->failed_pc=0x0c082a72u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082a74;
P_0c082a74: /* original 50f7, guest PC 0x0c082a74 */
if(!s->budget--) { s->failed_pc=0x0c082a74u; return 0; }
r[0]=read(ram,r[15]+28,4);
goto P_0c082a76;
P_0c082a76: /* original 059e, guest PC 0x0c082a76 */
if(!s->budget--) { s->failed_pc=0x0c082a76u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c082a78;
P_0c082a78: /* original 4c0b, guest PC 0x0c082a78 */
if(!s->budget--) { s->failed_pc=0x0c082a78u; return 0; }
target=r[12];
r[16]=code_base|0x0c082a7cu;
r[4]=read(ram,r[15]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082a7cu) { target=s->pc; goto dispatch; }
goto P_0c082a7c;
P_0c082a7a: /* original 54f8, guest PC 0x0c082a7a */
if(!s->budget--) { s->failed_pc=0x0c082a7au; return 0; }
r[4]=read(ram,r[15]+32,4);
goto P_0c082a7c;
P_0c082a7c: /* original 7f14, guest PC 0x0c082a7c */
if(!s->budget--) { s->failed_pc=0x0c082a7cu; return 0; }
r[15]+=0x00000014u;
goto P_0c082a7e;
P_0c082a7e: /* original d121, guest PC 0x0c082a7e */
if(!s->budget--) { s->failed_pc=0x0c082a7eu; return 0; }
r[1]=read(ram,0x0c082b04u,4);
goto P_0c082a80;
P_0c082a80: /* original 50f1, guest PC 0x0c082a80 */
if(!s->budget--) { s->failed_pc=0x0c082a80u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c082a82;
P_0c082a82: /* original cb36, guest PC 0x0c082a82 */
if(!s->budget--) { s->failed_pc=0x0c082a82u; return 0; }
r[0]|=54u;
goto P_0c082a84;
P_0c082a84: /* original 6a03, guest PC 0x0c082a84 */
if(!s->budget--) { s->failed_pc=0x0c082a84u; return 0; }
r[10]=r[0];
goto P_0c082a86;
P_0c082a86: /* original 60f2, guest PC 0x0c082a86 */
if(!s->budget--) { s->failed_pc=0x0c082a86u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c082a88;
P_0c082a88: /* original 4008, guest PC 0x0c082a88 */
if(!s->budget--) { s->failed_pc=0x0c082a88u; return 0; }
r[0]<<=2;
goto P_0c082a8a;
P_0c082a8a: /* original 001e, guest PC 0x0c082a8a */
if(!s->budget--) { s->failed_pc=0x0c082a8au; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c082a8c;
P_0c082a8c: /* original 88ff, guest PC 0x0c082a8c */
if(!s->budget--) { s->failed_pc=0x0c082a8cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c082a8e;
P_0c082a8e: /* original 8909, guest PC 0x0c082a8e */
if(!s->budget--) { s->failed_pc=0x0c082a8eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c082aa4; }
goto P_0c082a90;
P_0c082a90: /* original 2fe6, guest PC 0x0c082a90 */
if(!s->budget--) { s->failed_pc=0x0c082a90u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082a92;
P_0c082a92: /* original 66d3, guest PC 0x0c082a92 */
if(!s->budget--) { s->failed_pc=0x0c082a92u; return 0; }
r[6]=r[13];
goto P_0c082a94;
P_0c082a94: /* original 55f1, guest PC 0x0c082a94 */
if(!s->budget--) { s->failed_pc=0x0c082a94u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c082a96;
P_0c082a96: /* original e700, guest PC 0x0c082a96 */
if(!s->budget--) { s->failed_pc=0x0c082a96u; return 0; }
r[7]=0x00000000u;
goto P_0c082a98;
P_0c082a98: /* original d01a, guest PC 0x0c082a98 */
if(!s->budget--) { s->failed_pc=0x0c082a98u; return 0; }
r[0]=read(ram,0x0c082b04u,4);
goto P_0c082a9a;
P_0c082a9a: /* original 4508, guest PC 0x0c082a9a */
if(!s->budget--) { s->failed_pc=0x0c082a9au; return 0; }
r[5]<<=2;
goto P_0c082a9c;
P_0c082a9c: /* original 055e, guest PC 0x0c082a9c */
if(!s->budget--) { s->failed_pc=0x0c082a9cu; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c082a9e;
P_0c082a9e: /* original 4c0b, guest PC 0x0c082a9e */
if(!s->budget--) { s->failed_pc=0x0c082a9eu; return 0; }
target=r[12];
r[16]=code_base|0x0c082aa2u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082aa2u) { target=s->pc; goto dispatch; }
goto P_0c082aa2;
P_0c082aa0: /* original 64a3, guest PC 0x0c082aa0 */
if(!s->budget--) { s->failed_pc=0x0c082aa0u; return 0; }
r[4]=r[10];
goto P_0c082aa2;
P_0c082aa2: /* original 7f04, guest PC 0x0c082aa2 */
if(!s->budget--) { s->failed_pc=0x0c082aa2u; return 0; }
r[15]+=0x00000004u;
goto P_0c082aa4;
P_0c082aa4: /* original a06a, guest PC 0x0c082aa4 */
if(!s->budget--) { s->failed_pc=0x0c082aa4u; return 0; }
r[13]=r[14];
goto P_0c082b7c;
P_0c082aa6: /* original 6de3, guest PC 0x0c082aa6 */
if(!s->budget--) { s->failed_pc=0x0c082aa6u; return 0; }
r[13]=r[14];
goto P_0c082aa8;
P_0c082aa8: /* original d017, guest PC 0x0c082aa8 */
if(!s->budget--) { s->failed_pc=0x0c082aa8u; return 0; }
r[0]=read(ram,0x0c082b08u,4);
goto P_0c082aaa;
P_0c082aaa: /* original 69d3, guest PC 0x0c082aaa */
if(!s->budget--) { s->failed_pc=0x0c082aaau; return 0; }
r[9]=r[13];
goto P_0c082aac;
P_0c082aac: /* original 4908, guest PC 0x0c082aac */
if(!s->budget--) { s->failed_pc=0x0c082aacu; return 0; }
r[9]<<=2;
goto P_0c082aae;
P_0c082aae: /* original 5483, guest PC 0x0c082aae */
if(!s->budget--) { s->failed_pc=0x0c082aaeu; return 0; }
r[4]=read(ram,r[8]+12,4);
goto P_0c082ab0;
P_0c082ab0: /* original 099e, guest PC 0x0c082ab0 */
if(!s->budget--) { s->failed_pc=0x0c082ab0u; return 0; }
r[9]=read(ram,r[9]+r[0],4);
goto P_0c082ab2;
P_0c082ab2: /* original 61d3, guest PC 0x0c082ab2 */
if(!s->budget--) { s->failed_pc=0x0c082ab2u; return 0; }
r[1]=r[13];
goto P_0c082ab4;
P_0c082ab4: /* original d011, guest PC 0x0c082ab4 */
if(!s->budget--) { s->failed_pc=0x0c082ab4u; return 0; }
r[0]=read(ram,0x0c082afcu,4);
goto P_0c082ab6;
P_0c082ab6: /* original 644b, guest PC 0x0c082ab6 */
if(!s->budget--) { s->failed_pc=0x0c082ab6u; return 0; }
r[4]=0u-r[4];
goto P_0c082ab8;
P_0c082ab8: /* original 6793, guest PC 0x0c082ab8 */
if(!s->budget--) { s->failed_pc=0x0c082ab8u; return 0; }
r[7]=r[9];
goto P_0c082aba;
P_0c082aba: /* original 4700, guest PC 0x0c082aba */
if(!s->budget--) { s->failed_pc=0x0c082abau; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c082abc;
P_0c082abc: /* original 077c, guest PC 0x0c082abc */
if(!s->budget--) { s->failed_pc=0x0c082abcu; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c082abe;
P_0c082abe: /* original 7420, guest PC 0x0c082abe */
if(!s->budget--) { s->failed_pc=0x0c082abeu; return 0; }
r[4]+=0x00000020u;
goto P_0c082ac0;
P_0c082ac0: /* original d30f, guest PC 0x0c082ac0 */
if(!s->budget--) { s->failed_pc=0x0c082ac0u; return 0; }
r[3]=read(ram,0x0c082b00u,4);
goto P_0c082ac2;
P_0c082ac2: /* original 7704, guest PC 0x0c082ac2 */
if(!s->budget--) { s->failed_pc=0x0c082ac2u; return 0; }
r[7]+=0x00000004u;
goto P_0c082ac4;
P_0c082ac4: /* original 430b, guest PC 0x0c082ac4 */
if(!s->budget--) { s->failed_pc=0x0c082ac4u; return 0; }
target=r[3];
r[16]=code_base|0x0c082ac8u;
r[0]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082ac8u) { target=s->pc; goto dispatch; }
goto P_0c082ac8;
P_0c082ac6: /* original e002, guest PC 0x0c082ac6 */
if(!s->budget--) { s->failed_pc=0x0c082ac6u; return 0; }
r[0]=0x00000002u;
goto P_0c082ac8;
P_0c082ac8: /* original 2008, guest PC 0x0c082ac8 */
if(!s->budget--) { s->failed_pc=0x0c082ac8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c082aca;
P_0c082aca: /* original 8b23, guest PC 0x0c082aca */
if(!s->budget--) { s->failed_pc=0x0c082acau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c082b14; }
goto P_0c082acc;
P_0c082acc: /* original e30c, guest PC 0x0c082acc */
if(!s->budget--) { s->failed_pc=0x0c082accu; return 0; }
r[3]=0x0000000cu;
goto P_0c082ace;
P_0c082ace: /* original 65d3, guest PC 0x0c082ace */
if(!s->budget--) { s->failed_pc=0x0c082aceu; return 0; }
r[5]=r[13];
goto P_0c082ad0;
P_0c082ad0: /* original 3358, guest PC 0x0c082ad0 */
if(!s->budget--) { s->failed_pc=0x0c082ad0u; return 0; }
r[3]-=r[5];
goto P_0c082ad2;
P_0c082ad2: /* original d00e, guest PC 0x0c082ad2 */
if(!s->budget--) { s->failed_pc=0x0c082ad2u; return 0; }
r[0]=read(ram,0x0c082b0cu,4);
goto P_0c082ad4;
P_0c082ad4: /* original 4308, guest PC 0x0c082ad4 */
if(!s->budget--) { s->failed_pc=0x0c082ad4u; return 0; }
r[3]<<=2;
goto P_0c082ad6;
P_0c082ad6: /* original 4300, guest PC 0x0c082ad6 */
if(!s->budget--) { s->failed_pc=0x0c082ad6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c082ad8;
P_0c082ad8: /* original 023e, guest PC 0x0c082ad8 */
if(!s->budget--) { s->failed_pc=0x0c082ad8u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c082ada;
P_0c082ada: /* original 3428, guest PC 0x0c082ada */
if(!s->budget--) { s->failed_pc=0x0c082adau; return 0; }
r[4]-=r[2];
goto P_0c082adc;
P_0c082adc: /* original 4411, guest PC 0x0c082adc */
if(!s->budget--) { s->failed_pc=0x0c082adcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c082ade;
P_0c082ade: /* original 8b4c, guest PC 0x0c082ade */
if(!s->budget--) { s->failed_pc=0x0c082adeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c082b7a; }
goto P_0c082ae0;
P_0c082ae0: /* original 6653, guest PC 0x0c082ae0 */
if(!s->budget--) { s->failed_pc=0x0c082ae0u; return 0; }
r[6]=r[5];
goto P_0c082ae2;
P_0c082ae2: /* original d00b, guest PC 0x0c082ae2 */
if(!s->budget--) { s->failed_pc=0x0c082ae2u; return 0; }
r[0]=read(ram,0x0c082b10u,4);
goto P_0c082ae4;
P_0c082ae4: /* original 4608, guest PC 0x0c082ae4 */
if(!s->budget--) { s->failed_pc=0x0c082ae4u; return 0; }
r[6]<<=2;
goto P_0c082ae6;
P_0c082ae6: /* original 4600, guest PC 0x0c082ae6 */
if(!s->budget--) { s->failed_pc=0x0c082ae6u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c082ae8;
P_0c082ae8: /* original a025, guest PC 0x0c082ae8 */
if(!s->budget--) { s->failed_pc=0x0c082ae8u; return 0; }
r[6]=read(ram,r[6]+r[0],4);
goto P_0c082b36;
P_0c082aea: /* original 066e, guest PC 0x0c082aea */
if(!s->budget--) { s->failed_pc=0x0c082aeau; return 0; }
r[6]=read(ram,r[6]+r[0],4);
if(!vf3_matrix_family(0x0c082aecu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c082aecu; return 0; } return 1;
P_0c082b14: /* original e50c, guest PC 0x0c082b14 */
if(!s->budget--) { s->failed_pc=0x0c082b14u; return 0; }
r[5]=0x0000000cu;
goto P_0c082b16;
P_0c082b16: /* original d040, guest PC 0x0c082b16 */
if(!s->budget--) { s->failed_pc=0x0c082b16u; return 0; }
r[0]=read(ram,0x0c082c18u,4);
goto P_0c082b18;
P_0c082b18: /* original e30c, guest PC 0x0c082b18 */
if(!s->budget--) { s->failed_pc=0x0c082b18u; return 0; }
r[3]=0x0000000cu;
goto P_0c082b1a;
P_0c082b1a: /* original 35d8, guest PC 0x0c082b1a */
if(!s->budget--) { s->failed_pc=0x0c082b1au; return 0; }
r[5]-=r[13];
goto P_0c082b1c;
P_0c082b1c: /* original 3358, guest PC 0x0c082b1c */
if(!s->budget--) { s->failed_pc=0x0c082b1cu; return 0; }
r[3]-=r[5];
goto P_0c082b1e;
P_0c082b1e: /* original 4308, guest PC 0x0c082b1e */
if(!s->budget--) { s->failed_pc=0x0c082b1eu; return 0; }
r[3]<<=2;
goto P_0c082b20;
P_0c082b20: /* original 4300, guest PC 0x0c082b20 */
if(!s->budget--) { s->failed_pc=0x0c082b20u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c082b22;
P_0c082b22: /* original 023e, guest PC 0x0c082b22 */
if(!s->budget--) { s->failed_pc=0x0c082b22u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c082b24;
P_0c082b24: /* original 3428, guest PC 0x0c082b24 */
if(!s->budget--) { s->failed_pc=0x0c082b24u; return 0; }
r[4]-=r[2];
goto P_0c082b26;
P_0c082b26: /* original 4411, guest PC 0x0c082b26 */
if(!s->budget--) { s->failed_pc=0x0c082b26u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c082b28;
P_0c082b28: /* original 8b27, guest PC 0x0c082b28 */
if(!s->budget--) { s->failed_pc=0x0c082b28u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c082b7a; }
goto P_0c082b2a;
P_0c082b2a: /* original 6653, guest PC 0x0c082b2a */
if(!s->budget--) { s->failed_pc=0x0c082b2au; return 0; }
r[6]=r[5];
goto P_0c082b2c;
P_0c082b2c: /* original d03b, guest PC 0x0c082b2c */
if(!s->budget--) { s->failed_pc=0x0c082b2cu; return 0; }
r[0]=read(ram,0x0c082c1cu,4);
goto P_0c082b2e;
P_0c082b2e: /* original 4608, guest PC 0x0c082b2e */
if(!s->budget--) { s->failed_pc=0x0c082b2eu; return 0; }
r[6]<<=2;
goto P_0c082b30;
P_0c082b30: /* original 4600, guest PC 0x0c082b30 */
if(!s->budget--) { s->failed_pc=0x0c082b30u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c082b32;
P_0c082b32: /* original 066e, guest PC 0x0c082b32 */
if(!s->budget--) { s->failed_pc=0x0c082b32u; return 0; }
r[6]=read(ram,r[6]+r[0],4);
goto P_0c082b34;
P_0c082b34: /* original 76f6, guest PC 0x0c082b34 */
if(!s->budget--) { s->failed_pc=0x0c082b34u; return 0; }
r[6]+=0xfffffff6u;
goto P_0c082b36;
P_0c082b36: /* original 0647, guest PC 0x0c082b36 */
if(!s->budget--) { s->failed_pc=0x0c082b36u; return 0; }
r[19]=r[6]*r[4];
goto P_0c082b38;
P_0c082b38: /* original e438, guest PC 0x0c082b38 */
if(!s->budget--) { s->failed_pc=0x0c082b38u; return 0; }
r[4]=0x00000038u;
goto P_0c082b3a;
P_0c082b3a: /* original 051a, guest PC 0x0c082b3a */
if(!s->budget--) { s->failed_pc=0x0c082b3au; return 0; }
r[5]=r[19];
goto P_0c082b3c;
P_0c082b3c: /* original 357c, guest PC 0x0c082b3c */
if(!s->budget--) { s->failed_pc=0x0c082b3cu; return 0; }
r[5]+=r[7];
goto P_0c082b3e;
P_0c082b3e: /* original 3547, guest PC 0x0c082b3e */
if(!s->budget--) { s->failed_pc=0x0c082b3eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[4])!=0);
goto P_0c082b40;
P_0c082b40: /* original 891b, guest PC 0x0c082b40 */
if(!s->budget--) { s->failed_pc=0x0c082b40u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c082b7a; }
goto P_0c082b42;
P_0c082b42: /* original e2f7, guest PC 0x0c082b42 */
if(!s->budget--) { s->failed_pc=0x0c082b42u; return 0; }
r[2]=0xfffffff7u;
goto P_0c082b44;
P_0c082b44: /* original 3523, guest PC 0x0c082b44 */
if(!s->budget--) { s->failed_pc=0x0c082b44u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[2])!=0);
goto P_0c082b46;
P_0c082b46: /* original 8b18, guest PC 0x0c082b46 */
if(!s->budget--) { s->failed_pc=0x0c082b46u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c082b7a; }
goto P_0c082b48;
P_0c082b48: /* original d135, guest PC 0x0c082b48 */
if(!s->budget--) { s->failed_pc=0x0c082b48u; return 0; }
r[1]=read(ram,0x0c082c20u,4);
goto P_0c082b4a;
P_0c082b4a: /* original 6093, guest PC 0x0c082b4a */
if(!s->budget--) { s->failed_pc=0x0c082b4au; return 0; }
r[0]=r[9];
goto P_0c082b4c;
P_0c082b4c: /* original 4008, guest PC 0x0c082b4c */
if(!s->budget--) { s->failed_pc=0x0c082b4cu; return 0; }
r[0]<<=2;
goto P_0c082b4e;
P_0c082b4e: /* original 001e, guest PC 0x0c082b4e */
if(!s->budget--) { s->failed_pc=0x0c082b4eu; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c082b50;
P_0c082b50: /* original 88ff, guest PC 0x0c082b50 */
if(!s->budget--) { s->failed_pc=0x0c082b50u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c082b52;
P_0c082b52: /* original 8912, guest PC 0x0c082b52 */
if(!s->budget--) { s->failed_pc=0x0c082b52u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c082b7a; }
goto P_0c082b54;
P_0c082b54: /* original d033, guest PC 0x0c082b54 */
if(!s->budget--) { s->failed_pc=0x0c082b54u; return 0; }
r[0]=read(ram,0x0c082c24u,4);
goto P_0c082b56;
P_0c082b56: /* original 6a93, guest PC 0x0c082b56 */
if(!s->budget--) { s->failed_pc=0x0c082b56u; return 0; }
r[10]=r[9];
goto P_0c082b58;
P_0c082b58: /* original 4a00, guest PC 0x0c082b58 */
if(!s->budget--) { s->failed_pc=0x0c082b58u; return 0; }
r[17]=(r[17]&~1u)|((r[10]>>31)!=0);
r[10]<<=1;
goto P_0c082b5a;
P_0c082b5a: /* original 66b3, guest PC 0x0c082b5a */
if(!s->budget--) { s->failed_pc=0x0c082b5au; return 0; }
r[6]=r[11];
goto P_0c082b5c;
P_0c082b5c: /* original 0aac, guest PC 0x0c082b5c */
if(!s->budget--) { s->failed_pc=0x0c082b5cu; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c082b5e;
P_0c082b5e: /* original e307, guest PC 0x0c082b5e */
if(!s->budget--) { s->failed_pc=0x0c082b5eu; return 0; }
r[3]=0x00000007u;
goto P_0c082b60;
P_0c082b60: /* original 4500, guest PC 0x0c082b60 */
if(!s->budget--) { s->failed_pc=0x0c082b60u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c082b62;
P_0c082b62: /* original 2fe6, guest PC 0x0c082b62 */
if(!s->budget--) { s->failed_pc=0x0c082b62u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082b64;
P_0c082b64: /* original 7a0e, guest PC 0x0c082b64 */
if(!s->budget--) { s->failed_pc=0x0c082b64u; return 0; }
r[10]+=0x0000000eu;
goto P_0c082b66;
P_0c082b66: /* original d02e, guest PC 0x0c082b66 */
if(!s->budget--) { s->failed_pc=0x0c082b66u; return 0; }
r[0]=read(ram,0x0c082c20u,4);
goto P_0c082b68;
P_0c082b68: /* original 4a3c, guest PC 0x0c082b68 */
if(!s->budget--) { s->failed_pc=0x0c082b68u; return 0; }
r[10]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[10]>>((-r[3])&31u)):((int32_t)r[10]<0?0xffffffffu:0)):r[10]<<(r[3]&31u);
goto P_0c082b6a;
P_0c082b6a: /* original 2a5b, guest PC 0x0c082b6a */
if(!s->budget--) { s->failed_pc=0x0c082b6au; return 0; }
r[10]|=r[5];
goto P_0c082b6c;
P_0c082b6c: /* original 6593, guest PC 0x0c082b6c */
if(!s->budget--) { s->failed_pc=0x0c082b6cu; return 0; }
r[5]=r[9];
goto P_0c082b6e;
P_0c082b6e: /* original 4508, guest PC 0x0c082b6e */
if(!s->budget--) { s->failed_pc=0x0c082b6eu; return 0; }
r[5]<<=2;
goto P_0c082b70;
P_0c082b70: /* original 055e, guest PC 0x0c082b70 */
if(!s->budget--) { s->failed_pc=0x0c082b70u; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c082b72;
P_0c082b72: /* original e700, guest PC 0x0c082b72 */
if(!s->budget--) { s->failed_pc=0x0c082b72u; return 0; }
r[7]=0x00000000u;
goto P_0c082b74;
P_0c082b74: /* original 4c0b, guest PC 0x0c082b74 */
if(!s->budget--) { s->failed_pc=0x0c082b74u; return 0; }
target=r[12];
r[16]=code_base|0x0c082b78u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082b78u) { target=s->pc; goto dispatch; }
goto P_0c082b78;
P_0c082b76: /* original 64a3, guest PC 0x0c082b76 */
if(!s->budget--) { s->failed_pc=0x0c082b76u; return 0; }
r[4]=r[10];
goto P_0c082b78;
P_0c082b78: /* original 7f04, guest PC 0x0c082b78 */
if(!s->budget--) { s->failed_pc=0x0c082b78u; return 0; }
r[15]+=0x00000004u;
goto P_0c082b7a;
P_0c082b7a: /* original 7d01, guest PC 0x0c082b7a */
if(!s->budget--) { s->failed_pc=0x0c082b7au; return 0; }
r[13]+=0x00000001u;
goto P_0c082b7c;
P_0c082b7c: /* original e30d, guest PC 0x0c082b7c */
if(!s->budget--) { s->failed_pc=0x0c082b7cu; return 0; }
r[3]=0x0000000du;
goto P_0c082b7e;
P_0c082b7e: /* original 3d33, guest PC 0x0c082b7e */
if(!s->budget--) { s->failed_pc=0x0c082b7eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[3])!=0);
goto P_0c082b80;
P_0c082b80: /* original 8b92, guest PC 0x0c082b80 */
if(!s->budget--) { s->failed_pc=0x0c082b80u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c082aa8; }
goto P_0c082b82;
P_0c082b82: /* original 65a3, guest PC 0x0c082b82 */
if(!s->budget--) { s->failed_pc=0x0c082b82u; return 0; }
r[5]=r[10];
goto P_0c082b84;
P_0c082b84: /* original d128, guest PC 0x0c082b84 */
if(!s->budget--) { s->failed_pc=0x0c082b84u; return 0; }
r[1]=read(ram,0x0c082c28u,4);
goto P_0c082b86;
P_0c082b86: /* original 21e2, guest PC 0x0c082b86 */
if(!s->budget--) { s->failed_pc=0x0c082b86u; return 0; }
write(ram,r[1],r[14],4);
goto P_0c082b88;
P_0c082b88: /* original 54f8, guest PC 0x0c082b88 */
if(!s->budget--) { s->failed_pc=0x0c082b88u; return 0; }
r[4]=read(ram,r[15]+32,4);
goto P_0c082b8a;
P_0c082b8a: /* original 7f24, guest PC 0x0c082b8a */
if(!s->budget--) { s->failed_pc=0x0c082b8au; return 0; }
r[15]+=0x00000024u;
goto P_0c082b8c;
P_0c082b8c: /* original 4f16, guest PC 0x0c082b8c */
if(!s->budget--) { s->failed_pc=0x0c082b8cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c082b8e;
P_0c082b8e: /* original d327, guest PC 0x0c082b8e */
if(!s->budget--) { s->failed_pc=0x0c082b8eu; return 0; }
r[3]=read(ram,0x0c082c2cu,4);
goto P_0c082b90;
P_0c082b90: /* original 4f26, guest PC 0x0c082b90 */
if(!s->budget--) { s->failed_pc=0x0c082b90u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c082b92;
P_0c082b92: /* original 68f6, guest PC 0x0c082b92 */
if(!s->budget--) { s->failed_pc=0x0c082b92u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c082b94;
P_0c082b94: /* original 69f6, guest PC 0x0c082b94 */
if(!s->budget--) { s->failed_pc=0x0c082b94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c082b96;
P_0c082b96: /* original 6af6, guest PC 0x0c082b96 */
if(!s->budget--) { s->failed_pc=0x0c082b96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c082b98;
P_0c082b98: /* original 6bf6, guest PC 0x0c082b98 */
if(!s->budget--) { s->failed_pc=0x0c082b98u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c082b9a;
P_0c082b9a: /* original 6cf6, guest PC 0x0c082b9a */
if(!s->budget--) { s->failed_pc=0x0c082b9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c082b9c;
P_0c082b9c: /* original 6df6, guest PC 0x0c082b9c */
if(!s->budget--) { s->failed_pc=0x0c082b9cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c082b9e;
P_0c082b9e: /* original 432b, guest PC 0x0c082b9e */
if(!s->budget--) { s->failed_pc=0x0c082b9eu; return 0; }
target=r[3];
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
P_0c082ba0: /* original 6ef6, guest PC 0x0c082ba0 */
if(!s->budget--) { s->failed_pc=0x0c082ba0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c082ba2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c082ba2u; return 0; } return 1;
P_0c082c94: /* original 2fe6, guest PC 0x0c082c94 */
if(!s->budget--) { s->failed_pc=0x0c082c94u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082c96;
P_0c082c96: /* original 2fd6, guest PC 0x0c082c96 */
if(!s->budget--) { s->failed_pc=0x0c082c96u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082c98;
P_0c082c98: /* original 2fc6, guest PC 0x0c082c98 */
if(!s->budget--) { s->failed_pc=0x0c082c98u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082c9a;
P_0c082c9a: /* original 2fb6, guest PC 0x0c082c9a */
if(!s->budget--) { s->failed_pc=0x0c082c9au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082c9c;
P_0c082c9c: /* original 2fa6, guest PC 0x0c082c9c */
if(!s->budget--) { s->failed_pc=0x0c082c9cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082c9e;
P_0c082c9e: /* original 2f96, guest PC 0x0c082c9e */
if(!s->budget--) { s->failed_pc=0x0c082c9eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082ca0;
P_0c082ca0: /* original 2f86, guest PC 0x0c082ca0 */
if(!s->budget--) { s->failed_pc=0x0c082ca0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082ca2;
P_0c082ca2: /* original 4f22, guest PC 0x0c082ca2 */
if(!s->budget--) { s->failed_pc=0x0c082ca2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c082ca4;
P_0c082ca4: /* original 7ff8, guest PC 0x0c082ca4 */
if(!s->budget--) { s->failed_pc=0x0c082ca4u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c082ca6;
P_0c082ca6: /* original 2f42, guest PC 0x0c082ca6 */
if(!s->budget--) { s->failed_pc=0x0c082ca6u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c082ca8;
P_0c082ca8: /* original 1f51, guest PC 0x0c082ca8 */
if(!s->budget--) { s->failed_pc=0x0c082ca8u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c082caa;
P_0c082caa: /* original de25, guest PC 0x0c082caa */
if(!s->budget--) { s->failed_pc=0x0c082caau; return 0; }
r[14]=read(ram,0x0c082d40u,4);
goto P_0c082cac;
P_0c082cac: /* original dd23, guest PC 0x0c082cac */
if(!s->budget--) { s->failed_pc=0x0c082cacu; return 0; }
r[13]=read(ram,0x0c082d3cu,4);
goto P_0c082cae;
P_0c082cae: /* original d325, guest PC 0x0c082cae */
if(!s->budget--) { s->failed_pc=0x0c082caeu; return 0; }
r[3]=read(ram,0x0c082d44u,4);
goto P_0c082cb0;
P_0c082cb0: /* original 430b, guest PC 0x0c082cb0 */
if(!s->budget--) { s->failed_pc=0x0c082cb0u; return 0; }
target=r[3];
r[16]=code_base|0x0c082cb4u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082cb4u) { target=s->pc; goto dispatch; }
goto P_0c082cb4;
P_0c082cb2: /* original 64f2, guest PC 0x0c082cb2 */
if(!s->budget--) { s->failed_pc=0x0c082cb2u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c082cb4;
P_0c082cb4: /* original d224, guest PC 0x0c082cb4 */
if(!s->budget--) { s->failed_pc=0x0c082cb4u; return 0; }
r[2]=read(ram,0x0c082d48u,4);
goto P_0c082cb6;
P_0c082cb6: /* original 420b, guest PC 0x0c082cb6 */
if(!s->budget--) { s->failed_pc=0x0c082cb6u; return 0; }
target=r[2];
r[16]=code_base|0x0c082cbau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082cbau) { target=s->pc; goto dispatch; }
goto P_0c082cba;
P_0c082cb8: /* original 64e3, guest PC 0x0c082cb8 */
if(!s->budget--) { s->failed_pc=0x0c082cb8u; return 0; }
r[4]=r[14];
goto P_0c082cba;
P_0c082cba: /* original 982f, guest PC 0x0c082cba */
if(!s->budget--) { s->failed_pc=0x0c082cbau; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082d1cu,2);
goto P_0c082cbc;
P_0c082cbc: /* original eb03, guest PC 0x0c082cbc */
if(!s->budget--) { s->failed_pc=0x0c082cbcu; return 0; }
r[11]=0x00000003u;
goto P_0c082cbe;
P_0c082cbe: /* original 9a2e, guest PC 0x0c082cbe */
if(!s->budget--) { s->failed_pc=0x0c082cbeu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082d1eu,2);
goto P_0c082cc0;
P_0c082cc0: /* original ee00, guest PC 0x0c082cc0 */
if(!s->budget--) { s->failed_pc=0x0c082cc0u; return 0; }
r[14]=0x00000000u;
goto P_0c082cc2;
P_0c082cc2: /* original 6983, guest PC 0x0c082cc2 */
if(!s->budget--) { s->failed_pc=0x0c082cc2u; return 0; }
r[9]=r[8];
goto P_0c082cc4;
P_0c082cc4: /* original 9c2c, guest PC 0x0c082cc4 */
if(!s->budget--) { s->failed_pc=0x0c082cc4u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082d20u,2);
goto P_0c082cc6;
P_0c082cc6: /* original 79ff, guest PC 0x0c082cc6 */
if(!s->budget--) { s->failed_pc=0x0c082cc6u; return 0; }
r[9]+=0xffffffffu;
goto P_0c082cc8;
P_0c082cc8: /* original 60e3, guest PC 0x0c082cc8 */
if(!s->budget--) { s->failed_pc=0x0c082cc8u; return 0; }
r[0]=r[14];
goto P_0c082cca;
P_0c082cca: /* original 8800, guest PC 0x0c082cca */
if(!s->budget--) { s->failed_pc=0x0c082ccau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c082ccc;
P_0c082ccc: /* original 8905, guest PC 0x0c082ccc */
if(!s->budget--) { s->failed_pc=0x0c082cccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c082cda; }
goto P_0c082cce;
P_0c082cce: /* original 8801, guest PC 0x0c082cce */
if(!s->budget--) { s->failed_pc=0x0c082cceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c082cd0;
P_0c082cd0: /* original 8910, guest PC 0x0c082cd0 */
if(!s->budget--) { s->failed_pc=0x0c082cd0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c082cf4; }
goto P_0c082cd2;
P_0c082cd2: /* original 8802, guest PC 0x0c082cd2 */
if(!s->budget--) { s->failed_pc=0x0c082cd2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c082cd4;
P_0c082cd4: /* original 893e, guest PC 0x0c082cd4 */
if(!s->budget--) { s->failed_pc=0x0c082cd4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c082d54; }
goto P_0c082cd6;
P_0c082cd6: /* original a048, guest PC 0x0c082cd6 */
if(!s->budget--) { s->failed_pc=0x0c082cd6u; return 0; }
goto P_0c082d6a;
P_0c082cd8: /* original 0009, guest PC 0x0c082cd8 */
if(!s->budget--) { s->failed_pc=0x0c082cd8u; return 0; }
goto P_0c082cda;
P_0c082cda: /* original 9022, guest PC 0x0c082cda */
if(!s->budget--) { s->failed_pc=0x0c082cdau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082d22u,2);
goto P_0c082cdc;
P_0c082cdc: /* original 03de, guest PC 0x0c082cdc */
if(!s->budget--) { s->failed_pc=0x0c082cdcu; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c082cde;
P_0c082cde: /* original 3e30, guest PC 0x0c082cde */
if(!s->budget--) { s->failed_pc=0x0c082cdeu; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[3])!=0);
goto P_0c082ce0;
P_0c082ce0: /* original 8f02, guest PC 0x0c082ce0 */
if(!s->budget--) { s->failed_pc=0x0c082ce0u; return 0; }
cond=r[17]&1u;
r[5]=0x0000000au;
if(!cond) { goto P_0c082ce8; }
goto P_0c082ce4;
P_0c082ce2: /* original e50a, guest PC 0x0c082ce2 */
if(!s->budget--) { s->failed_pc=0x0c082ce2u; return 0; }
r[5]=0x0000000au;
goto P_0c082ce4;
P_0c082ce4: /* original a001, guest PC 0x0c082ce4 */
if(!s->budget--) { s->failed_pc=0x0c082ce4u; return 0; }
r[6]=r[10];
goto P_0c082cea;
P_0c082ce6: /* original 66a3, guest PC 0x0c082ce6 */
if(!s->budget--) { s->failed_pc=0x0c082ce6u; return 0; }
r[6]=r[10];
goto P_0c082ce8;
P_0c082ce8: /* original 961c, guest PC 0x0c082ce8 */
if(!s->budget--) { s->failed_pc=0x0c082ce8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082d24u,2);
goto P_0c082cea;
P_0c082cea: /* original d318, guest PC 0x0c082cea */
if(!s->budget--) { s->failed_pc=0x0c082ceau; return 0; }
r[3]=read(ram,0x0c082d4cu,4);
goto P_0c082cec;
P_0c082cec: /* original 430b, guest PC 0x0c082cec */
if(!s->budget--) { s->failed_pc=0x0c082cecu; return 0; }
target=r[3];
r[16]=code_base|0x0c082cf0u;
r[4]=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082cf0u) { target=s->pc; goto dispatch; }
goto P_0c082cf0;
P_0c082cee: /* original e418, guest PC 0x0c082cee */
if(!s->budget--) { s->failed_pc=0x0c082ceeu; return 0; }
r[4]=0x00000018u;
goto P_0c082cf0;
P_0c082cf0: /* original a03b, guest PC 0x0c082cf0 */
if(!s->budget--) { s->failed_pc=0x0c082cf0u; return 0; }
goto P_0c082d6a;
P_0c082cf2: /* original 0009, guest PC 0x0c082cf2 */
if(!s->budget--) { s->failed_pc=0x0c082cf2u; return 0; }
goto P_0c082cf4;
P_0c082cf4: /* original d216, guest PC 0x0c082cf4 */
if(!s->budget--) { s->failed_pc=0x0c082cf4u; return 0; }
r[2]=read(ram,0x0c082d50u,4);
goto P_0c082cf6;
P_0c082cf6: /* original 6322, guest PC 0x0c082cf6 */
if(!s->budget--) { s->failed_pc=0x0c082cf6u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c082cf8;
P_0c082cf8: /* original 2338, guest PC 0x0c082cf8 */
if(!s->budget--) { s->failed_pc=0x0c082cf8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c082cfa;
P_0c082cfa: /* original 8936, guest PC 0x0c082cfa */
if(!s->budget--) { s->failed_pc=0x0c082cfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c082d6a; }
goto P_0c082cfc;
P_0c082cfc: /* original 9011, guest PC 0x0c082cfc */
if(!s->budget--) { s->failed_pc=0x0c082cfcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082d22u,2);
goto P_0c082cfe;
P_0c082cfe: /* original 03de, guest PC 0x0c082cfe */
if(!s->budget--) { s->failed_pc=0x0c082cfeu; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c082d00;
P_0c082d00: /* original 3e30, guest PC 0x0c082d00 */
if(!s->budget--) { s->failed_pc=0x0c082d00u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[3])!=0);
goto P_0c082d02;
P_0c082d02: /* original 8f02, guest PC 0x0c082d02 */
if(!s->budget--) { s->failed_pc=0x0c082d02u; return 0; }
cond=r[17]&1u;
r[5]=0x0000000eu;
if(!cond) { goto P_0c082d0a; }
goto P_0c082d06;
P_0c082d04: /* original e50e, guest PC 0x0c082d04 */
if(!s->budget--) { s->failed_pc=0x0c082d04u; return 0; }
r[5]=0x0000000eu;
goto P_0c082d06;
P_0c082d06: /* original a001, guest PC 0x0c082d06 */
if(!s->budget--) { s->failed_pc=0x0c082d06u; return 0; }
r[6]=r[12];
goto P_0c082d0c;
P_0c082d08: /* original 66c3, guest PC 0x0c082d08 */
if(!s->budget--) { s->failed_pc=0x0c082d08u; return 0; }
r[6]=r[12];
goto P_0c082d0a;
P_0c082d0a: /* original 960c, guest PC 0x0c082d0a */
if(!s->budget--) { s->failed_pc=0x0c082d0au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082d26u,2);
goto P_0c082d0c;
P_0c082d0c: /* original d30f, guest PC 0x0c082d0c */
if(!s->budget--) { s->failed_pc=0x0c082d0cu; return 0; }
r[3]=read(ram,0x0c082d4cu,4);
goto P_0c082d0e;
P_0c082d0e: /* original 430b, guest PC 0x0c082d0e */
if(!s->budget--) { s->failed_pc=0x0c082d0eu; return 0; }
target=r[3];
r[16]=code_base|0x0c082d12u;
r[4]=0x00000019u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082d12u) { target=s->pc; goto dispatch; }
goto P_0c082d12;
P_0c082d10: /* original e419, guest PC 0x0c082d10 */
if(!s->budget--) { s->failed_pc=0x0c082d10u; return 0; }
r[4]=0x00000019u;
goto P_0c082d12;
P_0c082d12: /* original a02a, guest PC 0x0c082d12 */
if(!s->budget--) { s->failed_pc=0x0c082d12u; return 0; }
goto P_0c082d6a;
P_0c082d14: /* original 0009, guest PC 0x0c082d14 */
if(!s->budget--) { s->failed_pc=0x0c082d14u; return 0; }
if(!vf3_matrix_family(0x0c082d16u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c082d16u; return 0; } return 1;
P_0c082d54: /* original 9088, guest PC 0x0c082d54 */
if(!s->budget--) { s->failed_pc=0x0c082d54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082e68u,2);
goto P_0c082d56;
P_0c082d56: /* original 03de, guest PC 0x0c082d56 */
if(!s->budget--) { s->failed_pc=0x0c082d56u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c082d58;
P_0c082d58: /* original 3e30, guest PC 0x0c082d58 */
if(!s->budget--) { s->failed_pc=0x0c082d58u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[3])!=0);
goto P_0c082d5a;
P_0c082d5a: /* original 8f02, guest PC 0x0c082d5a */
if(!s->budget--) { s->failed_pc=0x0c082d5au; return 0; }
cond=r[17]&1u;
r[5]=0x00000012u;
if(!cond) { goto P_0c082d62; }
goto P_0c082d5e;
P_0c082d5c: /* original e512, guest PC 0x0c082d5c */
if(!s->budget--) { s->failed_pc=0x0c082d5cu; return 0; }
r[5]=0x00000012u;
goto P_0c082d5e;
P_0c082d5e: /* original a001, guest PC 0x0c082d5e */
if(!s->budget--) { s->failed_pc=0x0c082d5eu; return 0; }
r[6]=r[9];
goto P_0c082d64;
P_0c082d60: /* original 6693, guest PC 0x0c082d60 */
if(!s->budget--) { s->failed_pc=0x0c082d60u; return 0; }
r[6]=r[9];
goto P_0c082d62;
P_0c082d62: /* original 6683, guest PC 0x0c082d62 */
if(!s->budget--) { s->failed_pc=0x0c082d62u; return 0; }
r[6]=r[8];
goto P_0c082d64;
P_0c082d64: /* original d346, guest PC 0x0c082d64 */
if(!s->budget--) { s->failed_pc=0x0c082d64u; return 0; }
r[3]=read(ram,0x0c082e80u,4);
goto P_0c082d66;
P_0c082d66: /* original 430b, guest PC 0x0c082d66 */
if(!s->budget--) { s->failed_pc=0x0c082d66u; return 0; }
target=r[3];
r[16]=code_base|0x0c082d6au;
r[4]=0x0000001bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082d6au) { target=s->pc; goto dispatch; }
goto P_0c082d6a;
P_0c082d68: /* original e41b, guest PC 0x0c082d68 */
if(!s->budget--) { s->failed_pc=0x0c082d68u; return 0; }
r[4]=0x0000001bu;
goto P_0c082d6a;
P_0c082d6a: /* original 7e01, guest PC 0x0c082d6a */
if(!s->budget--) { s->failed_pc=0x0c082d6au; return 0; }
r[14]+=0x00000001u;
goto P_0c082d6c;
P_0c082d6c: /* original 3eb3, guest PC 0x0c082d6c */
if(!s->budget--) { s->failed_pc=0x0c082d6cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[11])!=0);
goto P_0c082d6e;
P_0c082d6e: /* original 8bab, guest PC 0x0c082d6e */
if(!s->budget--) { s->failed_pc=0x0c082d6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c082cc8; }
goto P_0c082d70;
P_0c082d70: /* original d243, guest PC 0x0c082d70 */
if(!s->budget--) { s->failed_pc=0x0c082d70u; return 0; }
r[2]=read(ram,0x0c082e80u,4);
goto P_0c082d72;
P_0c082d72: /* original e51f, guest PC 0x0c082d72 */
if(!s->budget--) { s->failed_pc=0x0c082d72u; return 0; }
r[5]=0x0000001fu;
goto P_0c082d74;
P_0c082d74: /* original 9679, guest PC 0x0c082d74 */
if(!s->budget--) { s->failed_pc=0x0c082d74u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082e6au,2);
goto P_0c082d76;
P_0c082d76: /* original 420b, guest PC 0x0c082d76 */
if(!s->budget--) { s->failed_pc=0x0c082d76u; return 0; }
target=r[2];
r[16]=code_base|0x0c082d7au;
r[4]=0x00000028u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082d7au) { target=s->pc; goto dispatch; }
goto P_0c082d7a;
P_0c082d78: /* original e428, guest PC 0x0c082d78 */
if(!s->budget--) { s->failed_pc=0x0c082d78u; return 0; }
r[4]=0x00000028u;
goto P_0c082d7a;
P_0c082d7a: /* original d342, guest PC 0x0c082d7a */
if(!s->budget--) { s->failed_pc=0x0c082d7au; return 0; }
r[3]=read(ram,0x0c082e84u,4);
goto P_0c082d7c;
P_0c082d7c: /* original 430b, guest PC 0x0c082d7c */
if(!s->budget--) { s->failed_pc=0x0c082d7cu; return 0; }
target=r[3];
r[16]=code_base|0x0c082d80u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082d80u) { target=s->pc; goto dispatch; }
goto P_0c082d80;
P_0c082d7e: /* original 0009, guest PC 0x0c082d7e */
if(!s->budget--) { s->failed_pc=0x0c082d7eu; return 0; }
goto P_0c082d80;
P_0c082d80: /* original d241, guest PC 0x0c082d80 */
if(!s->budget--) { s->failed_pc=0x0c082d80u; return 0; }
r[2]=read(ram,0x0c082e88u,4);
goto P_0c082d82;
P_0c082d82: /* original 420b, guest PC 0x0c082d82 */
if(!s->budget--) { s->failed_pc=0x0c082d82u; return 0; }
target=r[2];
r[16]=code_base|0x0c082d86u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082d86u) { target=s->pc; goto dispatch; }
goto P_0c082d86;
P_0c082d84: /* original e400, guest PC 0x0c082d84 */
if(!s->budget--) { s->failed_pc=0x0c082d84u; return 0; }
r[4]=0x00000000u;
goto P_0c082d86;
P_0c082d86: /* original d341, guest PC 0x0c082d86 */
if(!s->budget--) { s->failed_pc=0x0c082d86u; return 0; }
r[3]=read(ram,0x0c082e8cu,4);
goto P_0c082d88;
P_0c082d88: /* original 430b, guest PC 0x0c082d88 */
if(!s->budget--) { s->failed_pc=0x0c082d88u; return 0; }
target=r[3];
r[16]=code_base|0x0c082d8cu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082d8cu) { target=s->pc; goto dispatch; }
goto P_0c082d8c;
P_0c082d8a: /* original e401, guest PC 0x0c082d8a */
if(!s->budget--) { s->failed_pc=0x0c082d8au; return 0; }
r[4]=0x00000001u;
goto P_0c082d8c;
P_0c082d8c: /* original d240, guest PC 0x0c082d8c */
if(!s->budget--) { s->failed_pc=0x0c082d8cu; return 0; }
r[2]=read(ram,0x0c082e90u,4);
goto P_0c082d8e;
P_0c082d8e: /* original 420b, guest PC 0x0c082d8e */
if(!s->budget--) { s->failed_pc=0x0c082d8eu; return 0; }
target=r[2];
r[16]=code_base|0x0c082d92u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082d92u) { target=s->pc; goto dispatch; }
goto P_0c082d92;
P_0c082d90: /* original e400, guest PC 0x0c082d90 */
if(!s->budget--) { s->failed_pc=0x0c082d90u; return 0; }
r[4]=0x00000000u;
goto P_0c082d92;
P_0c082d92: /* original d340, guest PC 0x0c082d92 */
if(!s->budget--) { s->failed_pc=0x0c082d92u; return 0; }
r[3]=read(ram,0x0c082e94u,4);
goto P_0c082d94;
P_0c082d94: /* original e502, guest PC 0x0c082d94 */
if(!s->budget--) { s->failed_pc=0x0c082d94u; return 0; }
r[5]=0x00000002u;
goto P_0c082d96;
P_0c082d96: /* original 430b, guest PC 0x0c082d96 */
if(!s->budget--) { s->failed_pc=0x0c082d96u; return 0; }
target=r[3];
r[16]=code_base|0x0c082d9au;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082d9au) { target=s->pc; goto dispatch; }
goto P_0c082d9a;
P_0c082d98: /* original e403, guest PC 0x0c082d98 */
if(!s->budget--) { s->failed_pc=0x0c082d98u; return 0; }
r[4]=0x00000003u;
goto P_0c082d9a;
P_0c082d9a: /* original d240, guest PC 0x0c082d9a */
if(!s->budget--) { s->failed_pc=0x0c082d9au; return 0; }
r[2]=read(ram,0x0c082e9cu,4);
goto P_0c082d9c;
P_0c082d9c: /* original e600, guest PC 0x0c082d9c */
if(!s->budget--) { s->failed_pc=0x0c082d9cu; return 0; }
r[6]=0x00000000u;
goto P_0c082d9e;
P_0c082d9e: /* original d73e, guest PC 0x0c082d9e */
if(!s->budget--) { s->failed_pc=0x0c082d9eu; return 0; }
r[7]=read(ram,0x0c082e98u,4);
goto P_0c082da0;
P_0c082da0: /* original 6563, guest PC 0x0c082da0 */
if(!s->budget--) { s->failed_pc=0x0c082da0u; return 0; }
r[5]=r[6];
goto P_0c082da2;
P_0c082da2: /* original 420b, guest PC 0x0c082da2 */
if(!s->budget--) { s->failed_pc=0x0c082da2u; return 0; }
target=r[2];
r[16]=code_base|0x0c082da6u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082da6u) { target=s->pc; goto dispatch; }
goto P_0c082da6;
P_0c082da4: /* original 6463, guest PC 0x0c082da4 */
if(!s->budget--) { s->failed_pc=0x0c082da4u; return 0; }
r[4]=r[6];
goto P_0c082da6;
P_0c082da6: /* original 9561, guest PC 0x0c082da6 */
if(!s->budget--) { s->failed_pc=0x0c082da6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082e6cu,2);
goto P_0c082da8;
P_0c082da8: /* original dd3d, guest PC 0x0c082da8 */
if(!s->budget--) { s->failed_pc=0x0c082da8u; return 0; }
r[13]=read(ram,0x0c082ea0u,4);
goto P_0c082daa;
P_0c082daa: /* original 4d0b, guest PC 0x0c082daa */
if(!s->budget--) { s->failed_pc=0x0c082daau; return 0; }
target=r[13];
r[16]=code_base|0x0c082daeu;
r[4]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082daeu) { target=s->pc; goto dispatch; }
goto P_0c082dae;
P_0c082dac: /* original e410, guest PC 0x0c082dac */
if(!s->budget--) { s->failed_pc=0x0c082dacu; return 0; }
r[4]=0x00000010u;
goto P_0c082dae;
P_0c082dae: /* original d33e, guest PC 0x0c082dae */
if(!s->budget--) { s->failed_pc=0x0c082daeu; return 0; }
r[3]=read(ram,0x0c082ea8u,4);
goto P_0c082db0;
P_0c082db0: /* original de3c, guest PC 0x0c082db0 */
if(!s->budget--) { s->failed_pc=0x0c082db0u; return 0; }
r[14]=read(ram,0x0c082ea4u,4);
goto P_0c082db2;
P_0c082db2: /* original 4e0b, guest PC 0x0c082db2 */
if(!s->budget--) { s->failed_pc=0x0c082db2u; return 0; }
target=r[14];
r[16]=code_base|0x0c082db6u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082db6u) { target=s->pc; goto dispatch; }
goto P_0c082db6;
P_0c082db4: /* original 2f36, guest PC 0x0c082db4 */
if(!s->budget--) { s->failed_pc=0x0c082db4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082db6;
P_0c082db6: /* original 955a, guest PC 0x0c082db6 */
if(!s->budget--) { s->failed_pc=0x0c082db6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082e6eu,2);
goto P_0c082db8;
P_0c082db8: /* original 4d0b, guest PC 0x0c082db8 */
if(!s->budget--) { s->failed_pc=0x0c082db8u; return 0; }
target=r[13];
r[16]=code_base|0x0c082dbcu;
r[4]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082dbcu) { target=s->pc; goto dispatch; }
goto P_0c082dbc;
P_0c082dba: /* original e410, guest PC 0x0c082dba */
if(!s->budget--) { s->failed_pc=0x0c082dbau; return 0; }
r[4]=0x00000010u;
goto P_0c082dbc;
P_0c082dbc: /* original d23b, guest PC 0x0c082dbc */
if(!s->budget--) { s->failed_pc=0x0c082dbcu; return 0; }
r[2]=read(ram,0x0c082eacu,4);
goto P_0c082dbe;
P_0c082dbe: /* original 4e0b, guest PC 0x0c082dbe */
if(!s->budget--) { s->failed_pc=0x0c082dbeu; return 0; }
target=r[14];
r[16]=code_base|0x0c082dc2u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082dc2u) { target=s->pc; goto dispatch; }
goto P_0c082dc2;
P_0c082dc0: /* original 2f26, guest PC 0x0c082dc0 */
if(!s->budget--) { s->failed_pc=0x0c082dc0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082dc2;
P_0c082dc2: /* original 9555, guest PC 0x0c082dc2 */
if(!s->budget--) { s->failed_pc=0x0c082dc2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082e70u,2);
goto P_0c082dc4;
P_0c082dc4: /* original 4d0b, guest PC 0x0c082dc4 */
if(!s->budget--) { s->failed_pc=0x0c082dc4u; return 0; }
target=r[13];
r[16]=code_base|0x0c082dc8u;
r[4]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082dc8u) { target=s->pc; goto dispatch; }
goto P_0c082dc8;
P_0c082dc6: /* original e410, guest PC 0x0c082dc6 */
if(!s->budget--) { s->failed_pc=0x0c082dc6u; return 0; }
r[4]=0x00000010u;
goto P_0c082dc8;
P_0c082dc8: /* original d339, guest PC 0x0c082dc8 */
if(!s->budget--) { s->failed_pc=0x0c082dc8u; return 0; }
r[3]=read(ram,0x0c082eb0u,4);
goto P_0c082dca;
P_0c082dca: /* original 4e0b, guest PC 0x0c082dca */
if(!s->budget--) { s->failed_pc=0x0c082dcau; return 0; }
target=r[14];
r[16]=code_base|0x0c082dceu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082dceu) { target=s->pc; goto dispatch; }
goto P_0c082dce;
P_0c082dcc: /* original 2f36, guest PC 0x0c082dcc */
if(!s->budget--) { s->failed_pc=0x0c082dccu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082dce;
P_0c082dce: /* original 9550, guest PC 0x0c082dce */
if(!s->budget--) { s->failed_pc=0x0c082dceu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c082e72u,2);
goto P_0c082dd0;
P_0c082dd0: /* original 4d0b, guest PC 0x0c082dd0 */
if(!s->budget--) { s->failed_pc=0x0c082dd0u; return 0; }
target=r[13];
r[16]=code_base|0x0c082dd4u;
r[4]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082dd4u) { target=s->pc; goto dispatch; }
goto P_0c082dd4;
P_0c082dd2: /* original e410, guest PC 0x0c082dd2 */
if(!s->budget--) { s->failed_pc=0x0c082dd2u; return 0; }
r[4]=0x00000010u;
goto P_0c082dd4;
P_0c082dd4: /* original d237, guest PC 0x0c082dd4 */
if(!s->budget--) { s->failed_pc=0x0c082dd4u; return 0; }
r[2]=read(ram,0x0c082eb4u,4);
goto P_0c082dd6;
P_0c082dd6: /* original 4e0b, guest PC 0x0c082dd6 */
if(!s->budget--) { s->failed_pc=0x0c082dd6u; return 0; }
target=r[14];
r[16]=code_base|0x0c082ddau;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082ddau) { target=s->pc; goto dispatch; }
goto P_0c082dda;
P_0c082dd8: /* original 2f26, guest PC 0x0c082dd8 */
if(!s->budget--) { s->failed_pc=0x0c082dd8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c082dda;
P_0c082dda: /* original d337, guest PC 0x0c082dda */
if(!s->budget--) { s->failed_pc=0x0c082ddau; return 0; }
r[3]=read(ram,0x0c082eb8u,4);
goto P_0c082ddc;
P_0c082ddc: /* original 430b, guest PC 0x0c082ddc */
if(!s->budget--) { s->failed_pc=0x0c082ddcu; return 0; }
target=r[3];
r[16]=code_base|0x0c082de0u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082de0u) { target=s->pc; goto dispatch; }
goto P_0c082de0;
P_0c082dde: /* original e403, guest PC 0x0c082dde */
if(!s->budget--) { s->failed_pc=0x0c082ddeu; return 0; }
r[4]=0x00000003u;
goto P_0c082de0;
P_0c082de0: /* original d236, guest PC 0x0c082de0 */
if(!s->budget--) { s->failed_pc=0x0c082de0u; return 0; }
r[2]=read(ram,0x0c082ebcu,4);
goto P_0c082de2;
P_0c082de2: /* original 420b, guest PC 0x0c082de2 */
if(!s->budget--) { s->failed_pc=0x0c082de2u; return 0; }
target=r[2];
r[16]=code_base|0x0c082de6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082de6u) { target=s->pc; goto dispatch; }
goto P_0c082de6;
P_0c082de4: /* original 0009, guest PC 0x0c082de4 */
if(!s->budget--) { s->failed_pc=0x0c082de4u; return 0; }
goto P_0c082de6;
P_0c082de6: /* original 54f4, guest PC 0x0c082de6 */
if(!s->budget--) { s->failed_pc=0x0c082de6u; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c082de8;
P_0c082de8: /* original 55f5, guest PC 0x0c082de8 */
if(!s->budget--) { s->failed_pc=0x0c082de8u; return 0; }
r[5]=read(ram,r[15]+20,4);
goto P_0c082dea;
P_0c082dea: /* original 7f18, guest PC 0x0c082dea */
if(!s->budget--) { s->failed_pc=0x0c082deau; return 0; }
r[15]+=0x00000018u;
goto P_0c082dec;
P_0c082dec: /* original 4f26, guest PC 0x0c082dec */
if(!s->budget--) { s->failed_pc=0x0c082decu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c082dee;
P_0c082dee: /* original d334, guest PC 0x0c082dee */
if(!s->budget--) { s->failed_pc=0x0c082deeu; return 0; }
r[3]=read(ram,0x0c082ec0u,4);
goto P_0c082df0;
P_0c082df0: /* original 68f6, guest PC 0x0c082df0 */
if(!s->budget--) { s->failed_pc=0x0c082df0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c082df2;
P_0c082df2: /* original 69f6, guest PC 0x0c082df2 */
if(!s->budget--) { s->failed_pc=0x0c082df2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c082df4;
P_0c082df4: /* original 6af6, guest PC 0x0c082df4 */
if(!s->budget--) { s->failed_pc=0x0c082df4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c082df6;
P_0c082df6: /* original 6bf6, guest PC 0x0c082df6 */
if(!s->budget--) { s->failed_pc=0x0c082df6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c082df8;
P_0c082df8: /* original 6cf6, guest PC 0x0c082df8 */
if(!s->budget--) { s->failed_pc=0x0c082df8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c082dfa;
P_0c082dfa: /* original 6df6, guest PC 0x0c082dfa */
if(!s->budget--) { s->failed_pc=0x0c082dfau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c082dfc;
P_0c082dfc: /* original 432b, guest PC 0x0c082dfc */
if(!s->budget--) { s->failed_pc=0x0c082dfcu; return 0; }
target=r[3];
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
P_0c082dfe: /* original 6ef6, guest PC 0x0c082dfe */
if(!s->budget--) { s->failed_pc=0x0c082dfeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c082e00u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c082e00u; return 0; } return 1;
P_0c083d18: /* original 2fe6, guest PC 0x0c083d18 */
if(!s->budget--) { s->failed_pc=0x0c083d18u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083d1a;
P_0c083d1a: /* original d426, guest PC 0x0c083d1a */
if(!s->budget--) { s->failed_pc=0x0c083d1au; return 0; }
r[4]=read(ram,0x0c083db4u,4);
goto P_0c083d1c;
P_0c083d1c: /* original 4f22, guest PC 0x0c083d1c */
if(!s->budget--) { s->failed_pc=0x0c083d1cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c083d1e;
P_0c083d1e: /* original 6343, guest PC 0x0c083d1e */
if(!s->budget--) { s->failed_pc=0x0c083d1eu; return 0; }
r[3]=r[4];
goto P_0c083d20;
P_0c083d20: /* original 7358, guest PC 0x0c083d20 */
if(!s->budget--) { s->failed_pc=0x0c083d20u; return 0; }
r[3]+=0x00000058u;
goto P_0c083d22;
P_0c083d22: /* original 6543, guest PC 0x0c083d22 */
if(!s->budget--) { s->failed_pc=0x0c083d22u; return 0; }
r[5]=r[4];
goto P_0c083d24;
P_0c083d24: /* original 6e53, guest PC 0x0c083d24 */
if(!s->budget--) { s->failed_pc=0x0c083d24u; return 0; }
r[14]=r[5];
goto P_0c083d26;
P_0c083d26: /* original 7ffc, guest PC 0x0c083d26 */
if(!s->budget--) { s->failed_pc=0x0c083d26u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c083d28;
P_0c083d28: /* original 2f32, guest PC 0x0c083d28 */
if(!s->budget--) { s->failed_pc=0x0c083d28u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c083d2a;
P_0c083d2a: /* original 7e2c, guest PC 0x0c083d2a */
if(!s->budget--) { s->failed_pc=0x0c083d2au; return 0; }
r[14]+=0x0000002cu;
goto P_0c083d2c;
P_0c083d2c: /* original 943e, guest PC 0x0c083d2c */
if(!s->budget--) { s->failed_pc=0x0c083d2cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083dacu,2);
goto P_0c083d2e;
P_0c083d2e: /* original d328, guest PC 0x0c083d2e */
if(!s->budget--) { s->failed_pc=0x0c083d2eu; return 0; }
r[3]=read(ram,0x0c083dd0u,4);
goto P_0c083d30;
P_0c083d30: /* original 430b, guest PC 0x0c083d30 */
if(!s->budget--) { s->failed_pc=0x0c083d30u; return 0; }
target=r[3];
r[16]=code_base|0x0c083d34u;
r[6]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083d34u) { target=s->pc; goto dispatch; }
goto P_0c083d34;
P_0c083d32: /* original 66e3, guest PC 0x0c083d32 */
if(!s->budget--) { s->failed_pc=0x0c083d32u; return 0; }
r[6]=r[14];
goto P_0c083d34;
P_0c083d34: /* original 63f2, guest PC 0x0c083d34 */
if(!s->budget--) { s->failed_pc=0x0c083d34u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c083d36;
P_0c083d36: /* original e022, guest PC 0x0c083d36 */
if(!s->budget--) { s->failed_pc=0x0c083d36u; return 0; }
r[0]=0x00000022u;
goto P_0c083d38;
P_0c083d38: /* original e202, guest PC 0x0c083d38 */
if(!s->budget--) { s->failed_pc=0x0c083d38u; return 0; }
r[2]=0x00000002u;
goto P_0c083d3a;
P_0c083d3a: /* original 66e3, guest PC 0x0c083d3a */
if(!s->budget--) { s->failed_pc=0x0c083d3au; return 0; }
r[6]=r[14];
goto P_0c083d3c;
P_0c083d3c: /* original 013d, guest PC 0x0c083d3c */
if(!s->budget--) { s->failed_pc=0x0c083d3cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c083d3e;
P_0c083d3e: /* original e700, guest PC 0x0c083d3e */
if(!s->budget--) { s->failed_pc=0x0c083d3eu; return 0; }
r[7]=0x00000000u;
goto P_0c083d40;
P_0c083d40: /* original 212b, guest PC 0x0c083d40 */
if(!s->budget--) { s->failed_pc=0x0c083d40u; return 0; }
r[1]|=r[2];
goto P_0c083d42;
P_0c083d42: /* original 0315, guest PC 0x0c083d42 */
if(!s->budget--) { s->failed_pc=0x0c083d42u; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c083d44;
P_0c083d44: /* original e309, guest PC 0x0c083d44 */
if(!s->budget--) { s->failed_pc=0x0c083d44u; return 0; }
r[3]=0x00000009u;
goto P_0c083d46;
P_0c083d46: /* original 2f36, guest PC 0x0c083d46 */
if(!s->budget--) { s->failed_pc=0x0c083d46u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083d48;
P_0c083d48: /* original 9531, guest PC 0x0c083d48 */
if(!s->budget--) { s->failed_pc=0x0c083d48u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083daeu,2);
goto P_0c083d4a;
P_0c083d4a: /* original d122, guest PC 0x0c083d4a */
if(!s->budget--) { s->failed_pc=0x0c083d4au; return 0; }
r[1]=read(ram,0x0c083dd4u,4);
goto P_0c083d4c;
P_0c083d4c: /* original 410b, guest PC 0x0c083d4c */
if(!s->budget--) { s->failed_pc=0x0c083d4cu; return 0; }
target=r[1];
r[16]=code_base|0x0c083d50u;
r[4]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083d50u) { target=s->pc; goto dispatch; }
goto P_0c083d50;
P_0c083d4e: /* original 6473, guest PC 0x0c083d4e */
if(!s->budget--) { s->failed_pc=0x0c083d4eu; return 0; }
r[4]=r[7];
goto P_0c083d50;
P_0c083d50: /* original 7f08, guest PC 0x0c083d50 */
if(!s->budget--) { s->failed_pc=0x0c083d50u; return 0; }
r[15]+=0x00000008u;
goto P_0c083d52;
P_0c083d52: /* original d322, guest PC 0x0c083d52 */
if(!s->budget--) { s->failed_pc=0x0c083d52u; return 0; }
r[3]=read(ram,0x0c083ddcu,4);
goto P_0c083d54;
P_0c083d54: /* original 4f26, guest PC 0x0c083d54 */
if(!s->budget--) { s->failed_pc=0x0c083d54u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c083d56;
P_0c083d56: /* original c720, guest PC 0x0c083d56 */
if(!s->budget--) { s->failed_pc=0x0c083d56u; return 0; }
r[0]=code_base|0x00083dd8u;
goto P_0c083d58;
P_0c083d58: /* original f58d, guest PC 0x0c083d58 */
if(!s->budget--) { s->failed_pc=0x0c083d58u; return 0; }
fr[5]=0;
goto P_0c083d5a;
P_0c083d5a: /* original e600, guest PC 0x0c083d5a */
if(!s->budget--) { s->failed_pc=0x0c083d5au; return 0; }
r[6]=0x00000000u;
goto P_0c083d5c;
P_0c083d5c: /* original f408, guest PC 0x0c083d5c */
if(!s->budget--) { s->failed_pc=0x0c083d5cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c083d5e;
P_0c083d5e: /* original 6563, guest PC 0x0c083d5e */
if(!s->budget--) { s->failed_pc=0x0c083d5eu; return 0; }
r[5]=r[6];
goto P_0c083d60;
P_0c083d60: /* original 6463, guest PC 0x0c083d60 */
if(!s->budget--) { s->failed_pc=0x0c083d60u; return 0; }
r[4]=r[6];
goto P_0c083d62;
P_0c083d62: /* original 432b, guest PC 0x0c083d62 */
if(!s->budget--) { s->failed_pc=0x0c083d62u; return 0; }
target=r[3];
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
P_0c083d64: /* original 6ef6, guest PC 0x0c083d64 */
if(!s->budget--) { s->failed_pc=0x0c083d64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c083d66u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c083d66u; return 0; } return 1;
P_0c0a0280: /* original 2fe6, guest PC 0x0c0a0280 */
if(!s->budget--) { s->failed_pc=0x0c0a0280u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0282;
P_0c0a0282: /* original 2fd6, guest PC 0x0c0a0282 */
if(!s->budget--) { s->failed_pc=0x0c0a0282u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0284;
P_0c0a0284: /* original 2fc6, guest PC 0x0c0a0284 */
if(!s->budget--) { s->failed_pc=0x0c0a0284u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0286;
P_0c0a0286: /* original ec2b, guest PC 0x0c0a0286 */
if(!s->budget--) { s->failed_pc=0x0c0a0286u; return 0; }
r[12]=0x0000002bu;
goto P_0c0a0288;
P_0c0a0288: /* original 2fb6, guest PC 0x0c0a0288 */
if(!s->budget--) { s->failed_pc=0x0c0a0288u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a028a;
P_0c0a028a: /* original 4f22, guest PC 0x0c0a028a */
if(!s->budget--) { s->failed_pc=0x0c0a028au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a028c;
P_0c0a028c: /* original d32f, guest PC 0x0c0a028c */
if(!s->budget--) { s->failed_pc=0x0c0a028cu; return 0; }
r[3]=read(ram,0x0c0a034cu,4);
goto P_0c0a028e;
P_0c0a028e: /* original de2e, guest PC 0x0c0a028e */
if(!s->budget--) { s->failed_pc=0x0c0a028eu; return 0; }
r[14]=read(ram,0x0c0a0348u,4);
goto P_0c0a0290;
P_0c0a0290: /* original 7ff8, guest PC 0x0c0a0290 */
if(!s->budget--) { s->failed_pc=0x0c0a0290u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a0292;
P_0c0a0292: /* original 1f31, guest PC 0x0c0a0292 */
if(!s->budget--) { s->failed_pc=0x0c0a0292u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0a0294;
P_0c0a0294: /* original e307, guest PC 0x0c0a0294 */
if(!s->budget--) { s->failed_pc=0x0c0a0294u; return 0; }
r[3]=0x00000007u;
goto P_0c0a0296;
P_0c0a0296: /* original d22e, guest PC 0x0c0a0296 */
if(!s->budget--) { s->failed_pc=0x0c0a0296u; return 0; }
r[2]=read(ram,0x0c0a0350u,4);
goto P_0c0a0298;
P_0c0a0298: /* original 6422, guest PC 0x0c0a0298 */
if(!s->budget--) { s->failed_pc=0x0c0a0298u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0a029a;
P_0c0a029a: /* original 3c48, guest PC 0x0c0a029a */
if(!s->budget--) { s->failed_pc=0x0c0a029au; return 0; }
r[12]-=r[4];
goto P_0c0a029c;
P_0c0a029c: /* original 2fc2, guest PC 0x0c0a029c */
if(!s->budget--) { s->failed_pc=0x0c0a029cu; return 0; }
write(ram,r[15],r[12],4);
goto P_0c0a029e;
P_0c0a029e: /* original e428, guest PC 0x0c0a029e */
if(!s->budget--) { s->failed_pc=0x0c0a029eu; return 0; }
r[4]=0x00000028u;
goto P_0c0a02a0;
P_0c0a02a0: /* original d52c, guest PC 0x0c0a02a0 */
if(!s->budget--) { s->failed_pc=0x0c0a02a0u; return 0; }
r[5]=read(ram,0x0c0a0354u,4);
goto P_0c0a02a2;
P_0c0a02a2: /* original 4c3c, guest PC 0x0c0a02a2 */
if(!s->budget--) { s->failed_pc=0x0c0a02a2u; return 0; }
r[12]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[12]>>((-r[3])&31u)):((int32_t)r[12]<0?0xffffffffu:0)):r[12]<<(r[3]&31u);
goto P_0c0a02a4;
P_0c0a02a4: /* original d12c, guest PC 0x0c0a02a4 */
if(!s->budget--) { s->failed_pc=0x0c0a02a4u; return 0; }
r[1]=read(ram,0x0c0a0358u,4);
goto P_0c0a02a6;
P_0c0a02a6: /* original 24cb, guest PC 0x0c0a02a6 */
if(!s->budget--) { s->failed_pc=0x0c0a02a6u; return 0; }
r[4]|=r[12];
goto P_0c0a02a8;
P_0c0a02a8: /* original 410b, guest PC 0x0c0a02a8 */
if(!s->budget--) { s->failed_pc=0x0c0a02a8u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a02acu;
r[6]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a02acu) { target=s->pc; goto dispatch; }
goto P_0c0a02ac;
P_0c0a02aa: /* original e601, guest PC 0x0c0a02aa */
if(!s->budget--) { s->failed_pc=0x0c0a02aau; return 0; }
r[6]=0x00000001u;
goto P_0c0a02ac;
P_0c0a02ac: /* original 9041, guest PC 0x0c0a02ac */
if(!s->budget--) { s->failed_pc=0x0c0a02acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0332u,2);
goto P_0c0a02ae;
P_0c0a02ae: /* original e41c, guest PC 0x0c0a02ae */
if(!s->budget--) { s->failed_pc=0x0c0a02aeu; return 0; }
r[4]=0x0000001cu;
goto P_0c0a02b0;
P_0c0a02b0: /* original dd2b, guest PC 0x0c0a02b0 */
if(!s->budget--) { s->failed_pc=0x0c0a02b0u; return 0; }
r[13]=read(ram,0x0c0a0360u,4);
goto P_0c0a02b2;
P_0c0a02b2: /* original 24cb, guest PC 0x0c0a02b2 */
if(!s->budget--) { s->failed_pc=0x0c0a02b2u; return 0; }
r[4]|=r[12];
goto P_0c0a02b4;
P_0c0a02b4: /* original 03ec, guest PC 0x0c0a02b4 */
if(!s->budget--) { s->failed_pc=0x0c0a02b4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02b6;
P_0c0a02b6: /* original db29, guest PC 0x0c0a02b6 */
if(!s->budget--) { s->failed_pc=0x0c0a02b6u; return 0; }
r[11]=read(ram,0x0c0a035cu,4);
goto P_0c0a02b8;
P_0c0a02b8: /* original 2f36, guest PC 0x0c0a02b8 */
if(!s->budget--) { s->failed_pc=0x0c0a02b8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02ba;
P_0c0a02ba: /* original 4d0b, guest PC 0x0c0a02ba */
if(!s->budget--) { s->failed_pc=0x0c0a02bau; return 0; }
target=r[13];
r[16]=code_base|0x0c0a02beu;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a02beu) { target=s->pc; goto dispatch; }
goto P_0c0a02be;
P_0c0a02bc: /* original 2fb6, guest PC 0x0c0a02bc */
if(!s->budget--) { s->failed_pc=0x0c0a02bcu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02be;
P_0c0a02be: /* original 903b, guest PC 0x0c0a02be */
if(!s->budget--) { s->failed_pc=0x0c0a02beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0338u,2);
goto P_0c0a02c0;
P_0c0a02c0: /* original e420, guest PC 0x0c0a02c0 */
if(!s->budget--) { s->failed_pc=0x0c0a02c0u; return 0; }
r[4]=0x00000020u;
goto P_0c0a02c2;
P_0c0a02c2: /* original 24cb, guest PC 0x0c0a02c2 */
if(!s->budget--) { s->failed_pc=0x0c0a02c2u; return 0; }
r[4]|=r[12];
goto P_0c0a02c4;
P_0c0a02c4: /* original 03ec, guest PC 0x0c0a02c4 */
if(!s->budget--) { s->failed_pc=0x0c0a02c4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02c6;
P_0c0a02c6: /* original 2f36, guest PC 0x0c0a02c6 */
if(!s->budget--) { s->failed_pc=0x0c0a02c6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02c8;
P_0c0a02c8: /* original 4d0b, guest PC 0x0c0a02c8 */
if(!s->budget--) { s->failed_pc=0x0c0a02c8u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a02ccu;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a02ccu) { target=s->pc; goto dispatch; }
goto P_0c0a02cc;
P_0c0a02ca: /* original 2fb6, guest PC 0x0c0a02ca */
if(!s->budget--) { s->failed_pc=0x0c0a02cau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02cc;
P_0c0a02cc: /* original 9035, guest PC 0x0c0a02cc */
if(!s->budget--) { s->failed_pc=0x0c0a02ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a033au,2);
goto P_0c0a02ce;
P_0c0a02ce: /* original e424, guest PC 0x0c0a02ce */
if(!s->budget--) { s->failed_pc=0x0c0a02ceu; return 0; }
r[4]=0x00000024u;
goto P_0c0a02d0;
P_0c0a02d0: /* original 24cb, guest PC 0x0c0a02d0 */
if(!s->budget--) { s->failed_pc=0x0c0a02d0u; return 0; }
r[4]|=r[12];
goto P_0c0a02d2;
P_0c0a02d2: /* original 03ec, guest PC 0x0c0a02d2 */
if(!s->budget--) { s->failed_pc=0x0c0a02d2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02d4;
P_0c0a02d4: /* original 2f36, guest PC 0x0c0a02d4 */
if(!s->budget--) { s->failed_pc=0x0c0a02d4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02d6;
P_0c0a02d6: /* original 4d0b, guest PC 0x0c0a02d6 */
if(!s->budget--) { s->failed_pc=0x0c0a02d6u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a02dau;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a02dau) { target=s->pc; goto dispatch; }
goto P_0c0a02da;
P_0c0a02d8: /* original 2fb6, guest PC 0x0c0a02d8 */
if(!s->budget--) { s->failed_pc=0x0c0a02d8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02da;
P_0c0a02da: /* original 902f, guest PC 0x0c0a02da */
if(!s->budget--) { s->failed_pc=0x0c0a02dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a033cu,2);
goto P_0c0a02dc;
P_0c0a02dc: /* original e428, guest PC 0x0c0a02dc */
if(!s->budget--) { s->failed_pc=0x0c0a02dcu; return 0; }
r[4]=0x00000028u;
goto P_0c0a02de;
P_0c0a02de: /* original 24cb, guest PC 0x0c0a02de */
if(!s->budget--) { s->failed_pc=0x0c0a02deu; return 0; }
r[4]|=r[12];
goto P_0c0a02e0;
P_0c0a02e0: /* original 03ec, guest PC 0x0c0a02e0 */
if(!s->budget--) { s->failed_pc=0x0c0a02e0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02e2;
P_0c0a02e2: /* original 2f36, guest PC 0x0c0a02e2 */
if(!s->budget--) { s->failed_pc=0x0c0a02e2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02e4;
P_0c0a02e4: /* original 4d0b, guest PC 0x0c0a02e4 */
if(!s->budget--) { s->failed_pc=0x0c0a02e4u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a02e8u;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a02e8u) { target=s->pc; goto dispatch; }
goto P_0c0a02e8;
P_0c0a02e6: /* original 2fb6, guest PC 0x0c0a02e6 */
if(!s->budget--) { s->failed_pc=0x0c0a02e6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02e8;
P_0c0a02e8: /* original 9029, guest PC 0x0c0a02e8 */
if(!s->budget--) { s->failed_pc=0x0c0a02e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a033eu,2);
goto P_0c0a02ea;
P_0c0a02ea: /* original e307, guest PC 0x0c0a02ea */
if(!s->budget--) { s->failed_pc=0x0c0a02eau; return 0; }
r[3]=0x00000007u;
goto P_0c0a02ec;
P_0c0a02ec: /* original e601, guest PC 0x0c0a02ec */
if(!s->budget--) { s->failed_pc=0x0c0a02ecu; return 0; }
r[6]=0x00000001u;
goto P_0c0a02ee;
P_0c0a02ee: /* original 04ec, guest PC 0x0c0a02ee */
if(!s->budget--) { s->failed_pc=0x0c0a02eeu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02f0;
P_0c0a02f0: /* original d01c, guest PC 0x0c0a02f0 */
if(!s->budget--) { s->failed_pc=0x0c0a02f0u; return 0; }
r[0]=read(ram,0x0c0a0364u,4);
goto P_0c0a02f2;
P_0c0a02f2: /* original 044c, guest PC 0x0c0a02f2 */
if(!s->budget--) { s->failed_pc=0x0c0a02f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a02f4;
P_0c0a02f4: /* original 9024, guest PC 0x0c0a02f4 */
if(!s->budget--) { s->failed_pc=0x0c0a02f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0340u,2);
goto P_0c0a02f6;
P_0c0a02f6: /* original 0e44, guest PC 0x0c0a02f6 */
if(!s->budget--) { s->failed_pc=0x0c0a02f6u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a02f8;
P_0c0a02f8: /* original 70f9, guest PC 0x0c0a02f8 */
if(!s->budget--) { s->failed_pc=0x0c0a02f8u; return 0; }
r[0]+=0xfffffff9u;
goto P_0c0a02fa;
P_0c0a02fa: /* original 04ec, guest PC 0x0c0a02fa */
if(!s->budget--) { s->failed_pc=0x0c0a02fau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02fc;
P_0c0a02fc: /* original 52f8, guest PC 0x0c0a02fc */
if(!s->budget--) { s->failed_pc=0x0c0a02fcu; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c0a02fe;
P_0c0a02fe: /* original 4400, guest PC 0x0c0a02fe */
if(!s->budget--) { s->failed_pc=0x0c0a02feu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a0300;
P_0c0a0300: /* original 951e, guest PC 0x0c0a0300 */
if(!s->budget--) { s->failed_pc=0x0c0a0300u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0340u,2);
goto P_0c0a0302;
P_0c0a0302: /* original 740e, guest PC 0x0c0a0302 */
if(!s->budget--) { s->failed_pc=0x0c0a0302u; return 0; }
r[4]+=0x0000000eu;
goto P_0c0a0304;
P_0c0a0304: /* original 423c, guest PC 0x0c0a0304 */
if(!s->budget--) { s->failed_pc=0x0c0a0304u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[2]>>((-r[3])&31u)):((int32_t)r[2]<0?0xffffffffu:0)):r[2]<<(r[3]&31u);
goto P_0c0a0306;
P_0c0a0306: /* original 4400, guest PC 0x0c0a0306 */
if(!s->budget--) { s->failed_pc=0x0c0a0306u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a0308;
P_0c0a0308: /* original 242b, guest PC 0x0c0a0308 */
if(!s->budget--) { s->failed_pc=0x0c0a0308u; return 0; }
r[4]|=r[2];
goto P_0c0a030a;
P_0c0a030a: /* original d213, guest PC 0x0c0a030a */
if(!s->budget--) { s->failed_pc=0x0c0a030au; return 0; }
r[2]=read(ram,0x0c0a0358u,4);
goto P_0c0a030c;
P_0c0a030c: /* original 420b, guest PC 0x0c0a030c */
if(!s->budget--) { s->failed_pc=0x0c0a030cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a0310u;
r[5]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0310u) { target=s->pc; goto dispatch; }
goto P_0c0a0310;
P_0c0a030e: /* original 35ec, guest PC 0x0c0a030e */
if(!s->budget--) { s->failed_pc=0x0c0a030eu; return 0; }
r[5]+=r[14];
goto P_0c0a0310;
P_0c0a0310: /* original 55f9, guest PC 0x0c0a0310 */
if(!s->budget--) { s->failed_pc=0x0c0a0310u; return 0; }
r[5]=read(ram,r[15]+36,4);
goto P_0c0a0312;
P_0c0a0312: /* original e3fa, guest PC 0x0c0a0312 */
if(!s->budget--) { s->failed_pc=0x0c0a0312u; return 0; }
r[3]=0xfffffffau;
goto P_0c0a0314;
P_0c0a0314: /* original 9415, guest PC 0x0c0a0314 */
if(!s->budget--) { s->failed_pc=0x0c0a0314u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0342u,2);
goto P_0c0a0316;
P_0c0a0316: /* original 5553, guest PC 0x0c0a0316 */
if(!s->budget--) { s->failed_pc=0x0c0a0316u; return 0; }
r[5]=read(ram,r[5]+12,4);
goto P_0c0a0318;
P_0c0a0318: /* original 453c, guest PC 0x0c0a0318 */
if(!s->budget--) { s->failed_pc=0x0c0a0318u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c0a031a;
P_0c0a031a: /* original 2f56, guest PC 0x0c0a031a */
if(!s->budget--) { s->failed_pc=0x0c0a031au; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a031c;
P_0c0a031c: /* original d212, guest PC 0x0c0a031c */
if(!s->budget--) { s->failed_pc=0x0c0a031cu; return 0; }
r[2]=read(ram,0x0c0a0368u,4);
goto P_0c0a031e;
P_0c0a031e: /* original 4d0b, guest PC 0x0c0a031e */
if(!s->budget--) { s->failed_pc=0x0c0a031eu; return 0; }
target=r[13];
r[16]=code_base|0x0c0a0322u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0322u) { target=s->pc; goto dispatch; }
goto P_0c0a0322;
P_0c0a0320: /* original 2f26, guest PC 0x0c0a0320 */
if(!s->budget--) { s->failed_pc=0x0c0a0320u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0322;
P_0c0a0322: /* original 7f30, guest PC 0x0c0a0322 */
if(!s->budget--) { s->failed_pc=0x0c0a0322u; return 0; }
r[15]+=0x00000030u;
goto P_0c0a0324;
P_0c0a0324: /* original 4f26, guest PC 0x0c0a0324 */
if(!s->budget--) { s->failed_pc=0x0c0a0324u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a0326;
P_0c0a0326: /* original 6bf6, guest PC 0x0c0a0326 */
if(!s->budget--) { s->failed_pc=0x0c0a0326u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a0328;
P_0c0a0328: /* original 6cf6, guest PC 0x0c0a0328 */
if(!s->budget--) { s->failed_pc=0x0c0a0328u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a032a;
P_0c0a032a: /* original 6df6, guest PC 0x0c0a032a */
if(!s->budget--) { s->failed_pc=0x0c0a032au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a032c;
P_0c0a032c: /* original 000b, guest PC 0x0c0a032c */
if(!s->budget--) { s->failed_pc=0x0c0a032cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a032e: /* original 6ef6, guest PC 0x0c0a032e */
if(!s->budget--) { s->failed_pc=0x0c0a032eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a0330u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a0330u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
