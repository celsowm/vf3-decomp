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
int vf3_c101_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07d88au: goto P_0c07d88a;
case 0x0c07d88cu: goto P_0c07d88c;
case 0x0c07d88eu: goto P_0c07d88e;
case 0x0c07d890u: goto P_0c07d890;
case 0x0c07d892u: goto P_0c07d892;
case 0x0c07d894u: goto P_0c07d894;
case 0x0c07d896u: goto P_0c07d896;
case 0x0c07d898u: goto P_0c07d898;
case 0x0c07d89au: goto P_0c07d89a;
case 0x0c07d89cu: goto P_0c07d89c;
case 0x0c07d89eu: goto P_0c07d89e;
case 0x0c07d8a0u: goto P_0c07d8a0;
case 0x0c07d8a2u: goto P_0c07d8a2;
case 0x0c07d8a4u: goto P_0c07d8a4;
case 0x0c07d8a6u: goto P_0c07d8a6;
case 0x0c07d8a8u: goto P_0c07d8a8;
case 0x0c07d8aau: goto P_0c07d8aa;
case 0x0c07d8acu: goto P_0c07d8ac;
case 0x0c07d8aeu: goto P_0c07d8ae;
case 0x0c07d8b0u: goto P_0c07d8b0;
case 0x0c07d8b2u: goto P_0c07d8b2;
case 0x0c07d8b4u: goto P_0c07d8b4;
case 0x0c07d8b6u: goto P_0c07d8b6;
case 0x0c07d8b8u: goto P_0c07d8b8;
case 0x0c07d8bau: goto P_0c07d8ba;
case 0x0c07d8bcu: goto P_0c07d8bc;
case 0x0c07d8beu: goto P_0c07d8be;
case 0x0c07d8c0u: goto P_0c07d8c0;
case 0x0c07d8c2u: goto P_0c07d8c2;
case 0x0c07d8c4u: goto P_0c07d8c4;
case 0x0c07d8c6u: goto P_0c07d8c6;
case 0x0c07d8c8u: goto P_0c07d8c8;
case 0x0c07d8cau: goto P_0c07d8ca;
case 0x0c07d8ccu: goto P_0c07d8cc;
case 0x0c07d8ceu: goto P_0c07d8ce;
case 0x0c07d8d0u: goto P_0c07d8d0;
case 0x0c07d8d2u: goto P_0c07d8d2;
case 0x0c07d8d4u: goto P_0c07d8d4;
case 0x0c07d8d6u: goto P_0c07d8d6;
case 0x0c07d8d8u: goto P_0c07d8d8;
case 0x0c07d8dau: goto P_0c07d8da;
case 0x0c07d8dcu: goto P_0c07d8dc;
case 0x0c07d8deu: goto P_0c07d8de;
case 0x0c07d8e0u: goto P_0c07d8e0;
case 0x0c07d8e2u: goto P_0c07d8e2;
case 0x0c07d8e4u: goto P_0c07d8e4;
case 0x0c07d8e6u: goto P_0c07d8e6;
case 0x0c07d8e8u: goto P_0c07d8e8;
case 0x0c07d8eau: goto P_0c07d8ea;
case 0x0c07d8ecu: goto P_0c07d8ec;
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
case 0x0c0831eau: goto P_0c0831ea;
case 0x0c0831ecu: goto P_0c0831ec;
case 0x0c0831eeu: goto P_0c0831ee;
case 0x0c0831f0u: goto P_0c0831f0;
case 0x0c0831f2u: goto P_0c0831f2;
case 0x0c0831f4u: goto P_0c0831f4;
case 0x0c0831f6u: goto P_0c0831f6;
case 0x0c0831f8u: goto P_0c0831f8;
case 0x0c0831fau: goto P_0c0831fa;
case 0x0c0831fcu: goto P_0c0831fc;
case 0x0c0831feu: goto P_0c0831fe;
case 0x0c083200u: goto P_0c083200;
case 0x0c083202u: goto P_0c083202;
case 0x0c083204u: goto P_0c083204;
case 0x0c083206u: goto P_0c083206;
case 0x0c083208u: goto P_0c083208;
case 0x0c08320au: goto P_0c08320a;
case 0x0c08320cu: goto P_0c08320c;
case 0x0c08320eu: goto P_0c08320e;
case 0x0c083210u: goto P_0c083210;
case 0x0c083212u: goto P_0c083212;
case 0x0c083214u: goto P_0c083214;
case 0x0c083216u: goto P_0c083216;
case 0x0c083218u: goto P_0c083218;
case 0x0c08321au: goto P_0c08321a;
case 0x0c08321cu: goto P_0c08321c;
case 0x0c08321eu: goto P_0c08321e;
case 0x0c083220u: goto P_0c083220;
case 0x0c083222u: goto P_0c083222;
case 0x0c083224u: goto P_0c083224;
case 0x0c083226u: goto P_0c083226;
case 0x0c083228u: goto P_0c083228;
case 0x0c08322au: goto P_0c08322a;
case 0x0c08322cu: goto P_0c08322c;
case 0x0c08322eu: goto P_0c08322e;
case 0x0c083230u: goto P_0c083230;
case 0x0c083232u: goto P_0c083232;
case 0x0c083234u: goto P_0c083234;
case 0x0c083236u: goto P_0c083236;
case 0x0c083238u: goto P_0c083238;
case 0x0c08323au: goto P_0c08323a;
case 0x0c08323cu: goto P_0c08323c;
case 0x0c08323eu: goto P_0c08323e;
case 0x0c083240u: goto P_0c083240;
case 0x0c083242u: goto P_0c083242;
case 0x0c083244u: goto P_0c083244;
case 0x0c08327cu: goto P_0c08327c;
case 0x0c08327eu: goto P_0c08327e;
case 0x0c083280u: goto P_0c083280;
case 0x0c083282u: goto P_0c083282;
case 0x0c083284u: goto P_0c083284;
case 0x0c083286u: goto P_0c083286;
case 0x0c083288u: goto P_0c083288;
case 0x0c08328au: goto P_0c08328a;
case 0x0c08328cu: goto P_0c08328c;
case 0x0c08328eu: goto P_0c08328e;
case 0x0c083290u: goto P_0c083290;
case 0x0c083292u: goto P_0c083292;
case 0x0c083294u: goto P_0c083294;
case 0x0c083296u: goto P_0c083296;
case 0x0c083298u: goto P_0c083298;
case 0x0c08329au: goto P_0c08329a;
case 0x0c08329cu: goto P_0c08329c;
case 0x0c08329eu: goto P_0c08329e;
case 0x0c0832a0u: goto P_0c0832a0;
case 0x0c0832a2u: goto P_0c0832a2;
case 0x0c0832a4u: goto P_0c0832a4;
case 0x0c0832a6u: goto P_0c0832a6;
case 0x0c0832a8u: goto P_0c0832a8;
case 0x0c0832aau: goto P_0c0832aa;
case 0x0c0832acu: goto P_0c0832ac;
case 0x0c0832aeu: goto P_0c0832ae;
case 0x0c0832b0u: goto P_0c0832b0;
case 0x0c0832b2u: goto P_0c0832b2;
case 0x0c0832b4u: goto P_0c0832b4;
case 0x0c0832b6u: goto P_0c0832b6;
case 0x0c0832b8u: goto P_0c0832b8;
case 0x0c0832bau: goto P_0c0832ba;
case 0x0c0832bcu: goto P_0c0832bc;
case 0x0c0832beu: goto P_0c0832be;
case 0x0c0832c0u: goto P_0c0832c0;
case 0x0c0832c2u: goto P_0c0832c2;
case 0x0c0832c4u: goto P_0c0832c4;
case 0x0c0832c6u: goto P_0c0832c6;
case 0x0c0832c8u: goto P_0c0832c8;
case 0x0c0832cau: goto P_0c0832ca;
case 0x0c0832ccu: goto P_0c0832cc;
case 0x0c0832ceu: goto P_0c0832ce;
case 0x0c0832d0u: goto P_0c0832d0;
case 0x0c0832d2u: goto P_0c0832d2;
case 0x0c0832d4u: goto P_0c0832d4;
case 0x0c0832d6u: goto P_0c0832d6;
case 0x0c0832d8u: goto P_0c0832d8;
case 0x0c0832dau: goto P_0c0832da;
case 0x0c0832dcu: goto P_0c0832dc;
case 0x0c0832deu: goto P_0c0832de;
case 0x0c0832e0u: goto P_0c0832e0;
case 0x0c0832e2u: goto P_0c0832e2;
case 0x0c0832e4u: goto P_0c0832e4;
case 0x0c0832e6u: goto P_0c0832e6;
case 0x0c0832e8u: goto P_0c0832e8;
case 0x0c0832eau: goto P_0c0832ea;
case 0x0c0832ecu: goto P_0c0832ec;
case 0x0c0832eeu: goto P_0c0832ee;
case 0x0c0832f0u: goto P_0c0832f0;
case 0x0c0832f2u: goto P_0c0832f2;
case 0x0c0832f4u: goto P_0c0832f4;
case 0x0c0832f6u: goto P_0c0832f6;
case 0x0c0832f8u: goto P_0c0832f8;
case 0x0c0832fau: goto P_0c0832fa;
case 0x0c0832fcu: goto P_0c0832fc;
case 0x0c0832feu: goto P_0c0832fe;
case 0x0c083300u: goto P_0c083300;
case 0x0c083302u: goto P_0c083302;
case 0x0c083304u: goto P_0c083304;
case 0x0c083306u: goto P_0c083306;
case 0x0c083308u: goto P_0c083308;
case 0x0c08330au: goto P_0c08330a;
case 0x0c08330cu: goto P_0c08330c;
case 0x0c08330eu: goto P_0c08330e;
case 0x0c083310u: goto P_0c083310;
case 0x0c083312u: goto P_0c083312;
case 0x0c083314u: goto P_0c083314;
case 0x0c083316u: goto P_0c083316;
case 0x0c083318u: goto P_0c083318;
case 0x0c08331au: goto P_0c08331a;
case 0x0c08331cu: goto P_0c08331c;
case 0x0c08331eu: goto P_0c08331e;
case 0x0c083320u: goto P_0c083320;
case 0x0c083322u: goto P_0c083322;
case 0x0c083324u: goto P_0c083324;
case 0x0c083326u: goto P_0c083326;
case 0x0c083328u: goto P_0c083328;
case 0x0c08332au: goto P_0c08332a;
case 0x0c08332cu: goto P_0c08332c;
case 0x0c08332eu: goto P_0c08332e;
case 0x0c083330u: goto P_0c083330;
case 0x0c083332u: goto P_0c083332;
case 0x0c083334u: goto P_0c083334;
case 0x0c083336u: goto P_0c083336;
case 0x0c083338u: goto P_0c083338;
case 0x0c08333au: goto P_0c08333a;
case 0x0c08333cu: goto P_0c08333c;
case 0x0c08333eu: goto P_0c08333e;
case 0x0c083340u: goto P_0c083340;
case 0x0c083342u: goto P_0c083342;
case 0x0c083344u: goto P_0c083344;
case 0x0c083346u: goto P_0c083346;
case 0x0c083348u: goto P_0c083348;
case 0x0c08334au: goto P_0c08334a;
case 0x0c08334cu: goto P_0c08334c;
case 0x0c08334eu: goto P_0c08334e;
case 0x0c083350u: goto P_0c083350;
case 0x0c083352u: goto P_0c083352;
case 0x0c083354u: goto P_0c083354;
case 0x0c083356u: goto P_0c083356;
case 0x0c083358u: goto P_0c083358;
case 0x0c08335au: goto P_0c08335a;
case 0x0c08335cu: goto P_0c08335c;
case 0x0c08335eu: goto P_0c08335e;
case 0x0c083360u: goto P_0c083360;
case 0x0c083362u: goto P_0c083362;
case 0x0c083364u: goto P_0c083364;
case 0x0c083384u: goto P_0c083384;
case 0x0c083386u: goto P_0c083386;
case 0x0c083388u: goto P_0c083388;
case 0x0c08338au: goto P_0c08338a;
case 0x0c08338cu: goto P_0c08338c;
case 0x0c08338eu: goto P_0c08338e;
case 0x0c083390u: goto P_0c083390;
case 0x0c083392u: goto P_0c083392;
case 0x0c083394u: goto P_0c083394;
case 0x0c083396u: goto P_0c083396;
case 0x0c083398u: goto P_0c083398;
case 0x0c08339au: goto P_0c08339a;
case 0x0c08339cu: goto P_0c08339c;
case 0x0c08339eu: goto P_0c08339e;
case 0x0c0833a0u: goto P_0c0833a0;
case 0x0c0833a2u: goto P_0c0833a2;
case 0x0c0833a4u: goto P_0c0833a4;
case 0x0c0833a6u: goto P_0c0833a6;
case 0x0c0833a8u: goto P_0c0833a8;
case 0x0c0833aau: goto P_0c0833aa;
case 0x0c0833acu: goto P_0c0833ac;
case 0x0c0833aeu: goto P_0c0833ae;
case 0x0c0833b0u: goto P_0c0833b0;
case 0x0c0833b2u: goto P_0c0833b2;
case 0x0c0833b4u: goto P_0c0833b4;
case 0x0c0833b6u: goto P_0c0833b6;
case 0x0c0833b8u: goto P_0c0833b8;
case 0x0c0833bau: goto P_0c0833ba;
case 0x0c0833bcu: goto P_0c0833bc;
case 0x0c0833beu: goto P_0c0833be;
case 0x0c0833c0u: goto P_0c0833c0;
case 0x0c0833c2u: goto P_0c0833c2;
case 0x0c0833c4u: goto P_0c0833c4;
case 0x0c0833c6u: goto P_0c0833c6;
case 0x0c0833c8u: goto P_0c0833c8;
case 0x0c0833cau: goto P_0c0833ca;
case 0x0c0833ccu: goto P_0c0833cc;
case 0x0c0833ceu: goto P_0c0833ce;
case 0x0c0833d0u: goto P_0c0833d0;
case 0x0c0833d2u: goto P_0c0833d2;
case 0x0c0833d4u: goto P_0c0833d4;
case 0x0c0833d6u: goto P_0c0833d6;
case 0x0c0833d8u: goto P_0c0833d8;
case 0x0c0833dau: goto P_0c0833da;
case 0x0c0833dcu: goto P_0c0833dc;
case 0x0c0833deu: goto P_0c0833de;
case 0x0c0833e0u: goto P_0c0833e0;
case 0x0c0833e2u: goto P_0c0833e2;
case 0x0c0833e4u: goto P_0c0833e4;
case 0x0c0833e6u: goto P_0c0833e6;
case 0x0c0833e8u: goto P_0c0833e8;
case 0x0c0833eau: goto P_0c0833ea;
case 0x0c0833ecu: goto P_0c0833ec;
case 0x0c0833eeu: goto P_0c0833ee;
case 0x0c0833f0u: goto P_0c0833f0;
case 0x0c0833f2u: goto P_0c0833f2;
case 0x0c0833f4u: goto P_0c0833f4;
case 0x0c0833f6u: goto P_0c0833f6;
case 0x0c0833f8u: goto P_0c0833f8;
case 0x0c0833fau: goto P_0c0833fa;
case 0x0c0833fcu: goto P_0c0833fc;
case 0x0c0833feu: goto P_0c0833fe;
case 0x0c083400u: goto P_0c083400;
case 0x0c083402u: goto P_0c083402;
case 0x0c083404u: goto P_0c083404;
case 0x0c083406u: goto P_0c083406;
case 0x0c083408u: goto P_0c083408;
case 0x0c08340au: goto P_0c08340a;
case 0x0c08340cu: goto P_0c08340c;
case 0x0c08340eu: goto P_0c08340e;
case 0x0c083410u: goto P_0c083410;
case 0x0c083412u: goto P_0c083412;
case 0x0c083414u: goto P_0c083414;
case 0x0c083416u: goto P_0c083416;
case 0x0c083418u: goto P_0c083418;
case 0x0c08341au: goto P_0c08341a;
case 0x0c08341cu: goto P_0c08341c;
case 0x0c08341eu: goto P_0c08341e;
case 0x0c083420u: goto P_0c083420;
case 0x0c083422u: goto P_0c083422;
case 0x0c083424u: goto P_0c083424;
case 0x0c083426u: goto P_0c083426;
case 0x0c083428u: goto P_0c083428;
case 0x0c08342au: goto P_0c08342a;
case 0x0c08342cu: goto P_0c08342c;
case 0x0c08342eu: goto P_0c08342e;
case 0x0c083430u: goto P_0c083430;
case 0x0c083432u: goto P_0c083432;
case 0x0c083434u: goto P_0c083434;
case 0x0c083436u: goto P_0c083436;
case 0x0c083438u: goto P_0c083438;
case 0x0c08343au: goto P_0c08343a;
case 0x0c08343cu: goto P_0c08343c;
case 0x0c08343eu: goto P_0c08343e;
case 0x0c083440u: goto P_0c083440;
case 0x0c083442u: goto P_0c083442;
case 0x0c083444u: goto P_0c083444;
case 0x0c083446u: goto P_0c083446;
case 0x0c083448u: goto P_0c083448;
case 0x0c08344au: goto P_0c08344a;
case 0x0c08344cu: goto P_0c08344c;
case 0x0c08344eu: goto P_0c08344e;
case 0x0c083450u: goto P_0c083450;
case 0x0c083452u: goto P_0c083452;
case 0x0c083454u: goto P_0c083454;
case 0x0c083456u: goto P_0c083456;
case 0x0c083458u: goto P_0c083458;
case 0x0c08345au: goto P_0c08345a;
case 0x0c08345cu: goto P_0c08345c;
case 0x0c08345eu: goto P_0c08345e;
case 0x0c083460u: goto P_0c083460;
case 0x0c083462u: goto P_0c083462;
case 0x0c083464u: goto P_0c083464;
case 0x0c083466u: goto P_0c083466;
case 0x0c083468u: goto P_0c083468;
case 0x0c08346au: goto P_0c08346a;
case 0x0c08346cu: goto P_0c08346c;
case 0x0c08346eu: goto P_0c08346e;
case 0x0c083470u: goto P_0c083470;
case 0x0c083472u: goto P_0c083472;
case 0x0c083474u: goto P_0c083474;
case 0x0c083476u: goto P_0c083476;
case 0x0c083478u: goto P_0c083478;
case 0x0c08347au: goto P_0c08347a;
case 0x0c08347cu: goto P_0c08347c;
case 0x0c08347eu: goto P_0c08347e;
case 0x0c083480u: goto P_0c083480;
case 0x0c083482u: goto P_0c083482;
case 0x0c083484u: goto P_0c083484;
case 0x0c083486u: goto P_0c083486;
case 0x0c083488u: goto P_0c083488;
case 0x0c08348au: goto P_0c08348a;
case 0x0c08348cu: goto P_0c08348c;
case 0x0c08348eu: goto P_0c08348e;
case 0x0c083490u: goto P_0c083490;
case 0x0c083492u: goto P_0c083492;
case 0x0c0834b0u: goto P_0c0834b0;
case 0x0c0834b2u: goto P_0c0834b2;
case 0x0c0834b4u: goto P_0c0834b4;
case 0x0c0834b6u: goto P_0c0834b6;
case 0x0c0834b8u: goto P_0c0834b8;
case 0x0c0834bau: goto P_0c0834ba;
case 0x0c0834bcu: goto P_0c0834bc;
case 0x0c0834beu: goto P_0c0834be;
case 0x0c0834c0u: goto P_0c0834c0;
case 0x0c0834c2u: goto P_0c0834c2;
case 0x0c0834c4u: goto P_0c0834c4;
case 0x0c0834c6u: goto P_0c0834c6;
case 0x0c0834c8u: goto P_0c0834c8;
case 0x0c0834cau: goto P_0c0834ca;
case 0x0c0834ccu: goto P_0c0834cc;
case 0x0c0834ceu: goto P_0c0834ce;
case 0x0c0834d0u: goto P_0c0834d0;
case 0x0c0834d2u: goto P_0c0834d2;
case 0x0c0834d4u: goto P_0c0834d4;
case 0x0c0834d6u: goto P_0c0834d6;
case 0x0c0834d8u: goto P_0c0834d8;
case 0x0c0834dau: goto P_0c0834da;
case 0x0c0834dcu: goto P_0c0834dc;
case 0x0c0834deu: goto P_0c0834de;
case 0x0c0834e0u: goto P_0c0834e0;
case 0x0c0834e2u: goto P_0c0834e2;
case 0x0c0834e4u: goto P_0c0834e4;
case 0x0c0834e6u: goto P_0c0834e6;
case 0x0c0834e8u: goto P_0c0834e8;
case 0x0c0834eau: goto P_0c0834ea;
case 0x0c0834ecu: goto P_0c0834ec;
case 0x0c0834eeu: goto P_0c0834ee;
case 0x0c0834f0u: goto P_0c0834f0;
case 0x0c0834f2u: goto P_0c0834f2;
case 0x0c0834f4u: goto P_0c0834f4;
case 0x0c0834f6u: goto P_0c0834f6;
case 0x0c0834f8u: goto P_0c0834f8;
case 0x0c0834fau: goto P_0c0834fa;
case 0x0c0834fcu: goto P_0c0834fc;
case 0x0c0834feu: goto P_0c0834fe;
case 0x0c083500u: goto P_0c083500;
case 0x0c083502u: goto P_0c083502;
case 0x0c083504u: goto P_0c083504;
case 0x0c083506u: goto P_0c083506;
case 0x0c083508u: goto P_0c083508;
case 0x0c08350au: goto P_0c08350a;
case 0x0c08350cu: goto P_0c08350c;
case 0x0c08350eu: goto P_0c08350e;
case 0x0c083510u: goto P_0c083510;
case 0x0c083512u: goto P_0c083512;
case 0x0c083514u: goto P_0c083514;
case 0x0c083516u: goto P_0c083516;
case 0x0c083518u: goto P_0c083518;
case 0x0c08351au: goto P_0c08351a;
case 0x0c08351cu: goto P_0c08351c;
case 0x0c08351eu: goto P_0c08351e;
case 0x0c083520u: goto P_0c083520;
case 0x0c083522u: goto P_0c083522;
case 0x0c083524u: goto P_0c083524;
case 0x0c083526u: goto P_0c083526;
case 0x0c083528u: goto P_0c083528;
case 0x0c08352au: goto P_0c08352a;
case 0x0c08352cu: goto P_0c08352c;
case 0x0c08352eu: goto P_0c08352e;
case 0x0c083530u: goto P_0c083530;
case 0x0c083532u: goto P_0c083532;
case 0x0c083534u: goto P_0c083534;
case 0x0c083536u: goto P_0c083536;
case 0x0c083538u: goto P_0c083538;
case 0x0c08353au: goto P_0c08353a;
case 0x0c08353cu: goto P_0c08353c;
case 0x0c08353eu: goto P_0c08353e;
case 0x0c083540u: goto P_0c083540;
case 0x0c083542u: goto P_0c083542;
case 0x0c083544u: goto P_0c083544;
case 0x0c083546u: goto P_0c083546;
case 0x0c083548u: goto P_0c083548;
case 0x0c08354au: goto P_0c08354a;
case 0x0c08354cu: goto P_0c08354c;
case 0x0c08354eu: goto P_0c08354e;
case 0x0c083550u: goto P_0c083550;
case 0x0c083552u: goto P_0c083552;
case 0x0c083554u: goto P_0c083554;
case 0x0c083556u: goto P_0c083556;
case 0x0c083558u: goto P_0c083558;
case 0x0c08355au: goto P_0c08355a;
case 0x0c08355cu: goto P_0c08355c;
case 0x0c08355eu: goto P_0c08355e;
case 0x0c083560u: goto P_0c083560;
case 0x0c083562u: goto P_0c083562;
case 0x0c083564u: goto P_0c083564;
case 0x0c083566u: goto P_0c083566;
case 0x0c083568u: goto P_0c083568;
case 0x0c08356au: goto P_0c08356a;
case 0x0c08356cu: goto P_0c08356c;
case 0x0c08356eu: goto P_0c08356e;
case 0x0c083570u: goto P_0c083570;
case 0x0c083572u: goto P_0c083572;
case 0x0c083574u: goto P_0c083574;
case 0x0c083576u: goto P_0c083576;
case 0x0c083578u: goto P_0c083578;
case 0x0c08357au: goto P_0c08357a;
case 0x0c08357cu: goto P_0c08357c;
case 0x0c08357eu: goto P_0c08357e;
case 0x0c083580u: goto P_0c083580;
case 0x0c083582u: goto P_0c083582;
case 0x0c083584u: goto P_0c083584;
case 0x0c083586u: goto P_0c083586;
case 0x0c083588u: goto P_0c083588;
case 0x0c08358au: goto P_0c08358a;
case 0x0c08358cu: goto P_0c08358c;
case 0x0c08358eu: goto P_0c08358e;
case 0x0c083590u: goto P_0c083590;
case 0x0c083592u: goto P_0c083592;
case 0x0c083594u: goto P_0c083594;
case 0x0c083596u: goto P_0c083596;
case 0x0c083598u: goto P_0c083598;
case 0x0c08359au: goto P_0c08359a;
case 0x0c08359cu: goto P_0c08359c;
case 0x0c08359eu: goto P_0c08359e;
case 0x0c0835a0u: goto P_0c0835a0;
case 0x0c0835a2u: goto P_0c0835a2;
case 0x0c0835a4u: goto P_0c0835a4;
case 0x0c0835a6u: goto P_0c0835a6;
case 0x0c0835a8u: goto P_0c0835a8;
case 0x0c0835c4u: goto P_0c0835c4;
case 0x0c0835c6u: goto P_0c0835c6;
case 0x0c0835c8u: goto P_0c0835c8;
case 0x0c0835cau: goto P_0c0835ca;
case 0x0c0835ccu: goto P_0c0835cc;
case 0x0c0835ceu: goto P_0c0835ce;
case 0x0c0835d0u: goto P_0c0835d0;
case 0x0c0835d2u: goto P_0c0835d2;
case 0x0c0835d4u: goto P_0c0835d4;
case 0x0c0835d6u: goto P_0c0835d6;
case 0x0c0835d8u: goto P_0c0835d8;
case 0x0c0835dau: goto P_0c0835da;
case 0x0c0835dcu: goto P_0c0835dc;
case 0x0c0835deu: goto P_0c0835de;
case 0x0c0835e0u: goto P_0c0835e0;
case 0x0c0835e2u: goto P_0c0835e2;
case 0x0c0835e4u: goto P_0c0835e4;
case 0x0c0835e6u: goto P_0c0835e6;
case 0x0c0835e8u: goto P_0c0835e8;
case 0x0c0835eau: goto P_0c0835ea;
case 0x0c0835ecu: goto P_0c0835ec;
case 0x0c0835eeu: goto P_0c0835ee;
case 0x0c0835f0u: goto P_0c0835f0;
case 0x0c0835f2u: goto P_0c0835f2;
case 0x0c0835f4u: goto P_0c0835f4;
case 0x0c0835f6u: goto P_0c0835f6;
case 0x0c0835f8u: goto P_0c0835f8;
case 0x0c0835fau: goto P_0c0835fa;
case 0x0c0835fcu: goto P_0c0835fc;
case 0x0c0835feu: goto P_0c0835fe;
case 0x0c083600u: goto P_0c083600;
case 0x0c083602u: goto P_0c083602;
case 0x0c083604u: goto P_0c083604;
case 0x0c083606u: goto P_0c083606;
case 0x0c083608u: goto P_0c083608;
case 0x0c08360au: goto P_0c08360a;
case 0x0c08360cu: goto P_0c08360c;
case 0x0c08360eu: goto P_0c08360e;
case 0x0c083610u: goto P_0c083610;
case 0x0c083612u: goto P_0c083612;
case 0x0c083614u: goto P_0c083614;
case 0x0c083616u: goto P_0c083616;
case 0x0c083618u: goto P_0c083618;
case 0x0c08361au: goto P_0c08361a;
case 0x0c08361cu: goto P_0c08361c;
case 0x0c08361eu: goto P_0c08361e;
case 0x0c083620u: goto P_0c083620;
case 0x0c083622u: goto P_0c083622;
case 0x0c083624u: goto P_0c083624;
case 0x0c083626u: goto P_0c083626;
case 0x0c083628u: goto P_0c083628;
case 0x0c08362au: goto P_0c08362a;
case 0x0c08362cu: goto P_0c08362c;
case 0x0c08362eu: goto P_0c08362e;
case 0x0c083630u: goto P_0c083630;
case 0x0c083632u: goto P_0c083632;
case 0x0c083634u: goto P_0c083634;
case 0x0c083636u: goto P_0c083636;
case 0x0c083638u: goto P_0c083638;
case 0x0c08363au: goto P_0c08363a;
case 0x0c08363cu: goto P_0c08363c;
case 0x0c08363eu: goto P_0c08363e;
case 0x0c083640u: goto P_0c083640;
case 0x0c083642u: goto P_0c083642;
case 0x0c083644u: goto P_0c083644;
case 0x0c083646u: goto P_0c083646;
case 0x0c083648u: goto P_0c083648;
case 0x0c08364au: goto P_0c08364a;
case 0x0c08364cu: goto P_0c08364c;
case 0x0c08364eu: goto P_0c08364e;
case 0x0c083650u: goto P_0c083650;
case 0x0c083652u: goto P_0c083652;
case 0x0c083654u: goto P_0c083654;
case 0x0c083656u: goto P_0c083656;
case 0x0c083658u: goto P_0c083658;
case 0x0c08365au: goto P_0c08365a;
case 0x0c08365cu: goto P_0c08365c;
case 0x0c08365eu: goto P_0c08365e;
case 0x0c083660u: goto P_0c083660;
case 0x0c083662u: goto P_0c083662;
case 0x0c083664u: goto P_0c083664;
case 0x0c083666u: goto P_0c083666;
case 0x0c083668u: goto P_0c083668;
case 0x0c08366au: goto P_0c08366a;
case 0x0c08366cu: goto P_0c08366c;
case 0x0c08366eu: goto P_0c08366e;
case 0x0c083670u: goto P_0c083670;
case 0x0c083672u: goto P_0c083672;
case 0x0c083674u: goto P_0c083674;
case 0x0c083676u: goto P_0c083676;
case 0x0c083678u: goto P_0c083678;
case 0x0c08367au: goto P_0c08367a;
case 0x0c08367cu: goto P_0c08367c;
case 0x0c08367eu: goto P_0c08367e;
case 0x0c083680u: goto P_0c083680;
case 0x0c083682u: goto P_0c083682;
case 0x0c083684u: goto P_0c083684;
case 0x0c083686u: goto P_0c083686;
case 0x0c083688u: goto P_0c083688;
case 0x0c08368au: goto P_0c08368a;
case 0x0c08368cu: goto P_0c08368c;
case 0x0c08368eu: goto P_0c08368e;
case 0x0c083690u: goto P_0c083690;
case 0x0c083692u: goto P_0c083692;
case 0x0c083694u: goto P_0c083694;
case 0x0c083696u: goto P_0c083696;
case 0x0c083698u: goto P_0c083698;
case 0x0c08369au: goto P_0c08369a;
case 0x0c08369cu: goto P_0c08369c;
case 0x0c08369eu: goto P_0c08369e;
case 0x0c0836a0u: goto P_0c0836a0;
case 0x0c0836a2u: goto P_0c0836a2;
case 0x0c0836a4u: goto P_0c0836a4;
case 0x0c0836a6u: goto P_0c0836a6;
case 0x0c0836a8u: goto P_0c0836a8;
case 0x0c0836aau: goto P_0c0836aa;
case 0x0c0836acu: goto P_0c0836ac;
case 0x0c0836aeu: goto P_0c0836ae;
case 0x0c0836b0u: goto P_0c0836b0;
case 0x0c0836b2u: goto P_0c0836b2;
case 0x0c0836b4u: goto P_0c0836b4;
case 0x0c0836b6u: goto P_0c0836b6;
case 0x0c0836b8u: goto P_0c0836b8;
case 0x0c0836bau: goto P_0c0836ba;
case 0x0c0836bcu: goto P_0c0836bc;
case 0x0c0836beu: goto P_0c0836be;
case 0x0c0836c0u: goto P_0c0836c0;
case 0x0c0836c2u: goto P_0c0836c2;
case 0x0c0836c4u: goto P_0c0836c4;
case 0x0c0836c6u: goto P_0c0836c6;
case 0x0c0836c8u: goto P_0c0836c8;
case 0x0c0836cau: goto P_0c0836ca;
case 0x0c0836ccu: goto P_0c0836cc;
case 0x0c0836ceu: goto P_0c0836ce;
case 0x0c0836d0u: goto P_0c0836d0;
case 0x0c0836d2u: goto P_0c0836d2;
case 0x0c0836d4u: goto P_0c0836d4;
case 0x0c0836f0u: goto P_0c0836f0;
case 0x0c0836f2u: goto P_0c0836f2;
case 0x0c0836f4u: goto P_0c0836f4;
case 0x0c0836f6u: goto P_0c0836f6;
case 0x0c0836f8u: goto P_0c0836f8;
case 0x0c0836fau: goto P_0c0836fa;
case 0x0c0836fcu: goto P_0c0836fc;
case 0x0c0836feu: goto P_0c0836fe;
case 0x0c083700u: goto P_0c083700;
case 0x0c083702u: goto P_0c083702;
case 0x0c083704u: goto P_0c083704;
case 0x0c083706u: goto P_0c083706;
case 0x0c083708u: goto P_0c083708;
case 0x0c08370au: goto P_0c08370a;
case 0x0c08370cu: goto P_0c08370c;
case 0x0c08370eu: goto P_0c08370e;
case 0x0c083710u: goto P_0c083710;
case 0x0c083712u: goto P_0c083712;
case 0x0c083714u: goto P_0c083714;
case 0x0c083716u: goto P_0c083716;
case 0x0c083718u: goto P_0c083718;
case 0x0c08371au: goto P_0c08371a;
case 0x0c08371cu: goto P_0c08371c;
case 0x0c08371eu: goto P_0c08371e;
case 0x0c083720u: goto P_0c083720;
case 0x0c083722u: goto P_0c083722;
case 0x0c083724u: goto P_0c083724;
case 0x0c083726u: goto P_0c083726;
case 0x0c083728u: goto P_0c083728;
case 0x0c08372au: goto P_0c08372a;
case 0x0c08372cu: goto P_0c08372c;
case 0x0c08372eu: goto P_0c08372e;
case 0x0c083730u: goto P_0c083730;
case 0x0c083732u: goto P_0c083732;
case 0x0c083734u: goto P_0c083734;
case 0x0c083736u: goto P_0c083736;
case 0x0c083738u: goto P_0c083738;
case 0x0c08373au: goto P_0c08373a;
case 0x0c08373cu: goto P_0c08373c;
case 0x0c08373eu: goto P_0c08373e;
case 0x0c083740u: goto P_0c083740;
case 0x0c083742u: goto P_0c083742;
case 0x0c083744u: goto P_0c083744;
case 0x0c083746u: goto P_0c083746;
case 0x0c083748u: goto P_0c083748;
case 0x0c08374au: goto P_0c08374a;
case 0x0c08374cu: goto P_0c08374c;
case 0x0c08374eu: goto P_0c08374e;
case 0x0c083750u: goto P_0c083750;
case 0x0c083752u: goto P_0c083752;
case 0x0c083754u: goto P_0c083754;
case 0x0c083756u: goto P_0c083756;
case 0x0c083758u: goto P_0c083758;
case 0x0c08375au: goto P_0c08375a;
case 0x0c08375cu: goto P_0c08375c;
case 0x0c08375eu: goto P_0c08375e;
case 0x0c083760u: goto P_0c083760;
case 0x0c083762u: goto P_0c083762;
case 0x0c083764u: goto P_0c083764;
case 0x0c083766u: goto P_0c083766;
case 0x0c083768u: goto P_0c083768;
case 0x0c08376au: goto P_0c08376a;
case 0x0c08376cu: goto P_0c08376c;
case 0x0c08376eu: goto P_0c08376e;
case 0x0c083770u: goto P_0c083770;
case 0x0c083772u: goto P_0c083772;
case 0x0c083774u: goto P_0c083774;
case 0x0c083776u: goto P_0c083776;
case 0x0c083778u: goto P_0c083778;
case 0x0c08377au: goto P_0c08377a;
case 0x0c08377cu: goto P_0c08377c;
case 0x0c08377eu: goto P_0c08377e;
case 0x0c083780u: goto P_0c083780;
case 0x0c083782u: goto P_0c083782;
case 0x0c083784u: goto P_0c083784;
case 0x0c083786u: goto P_0c083786;
case 0x0c083788u: goto P_0c083788;
case 0x0c08378au: goto P_0c08378a;
case 0x0c08378cu: goto P_0c08378c;
case 0x0c08378eu: goto P_0c08378e;
case 0x0c083790u: goto P_0c083790;
case 0x0c083792u: goto P_0c083792;
case 0x0c083794u: goto P_0c083794;
case 0x0c083796u: goto P_0c083796;
case 0x0c083798u: goto P_0c083798;
case 0x0c08379au: goto P_0c08379a;
case 0x0c08379cu: goto P_0c08379c;
case 0x0c08379eu: goto P_0c08379e;
case 0x0c0837a0u: goto P_0c0837a0;
case 0x0c0837a2u: goto P_0c0837a2;
case 0x0c0837a4u: goto P_0c0837a4;
case 0x0c0837a6u: goto P_0c0837a6;
case 0x0c0837a8u: goto P_0c0837a8;
case 0x0c0837aau: goto P_0c0837aa;
case 0x0c0837acu: goto P_0c0837ac;
case 0x0c0837aeu: goto P_0c0837ae;
case 0x0c0837b0u: goto P_0c0837b0;
case 0x0c0837b2u: goto P_0c0837b2;
case 0x0c0837b4u: goto P_0c0837b4;
case 0x0c0837b6u: goto P_0c0837b6;
case 0x0c0837b8u: goto P_0c0837b8;
case 0x0c0837bau: goto P_0c0837ba;
case 0x0c0837bcu: goto P_0c0837bc;
case 0x0c0837beu: goto P_0c0837be;
case 0x0c0837c0u: goto P_0c0837c0;
case 0x0c0837c2u: goto P_0c0837c2;
case 0x0c0837c4u: goto P_0c0837c4;
case 0x0c0837c6u: goto P_0c0837c6;
case 0x0c0837c8u: goto P_0c0837c8;
case 0x0c0837cau: goto P_0c0837ca;
case 0x0c0837ccu: goto P_0c0837cc;
case 0x0c0837ceu: goto P_0c0837ce;
case 0x0c0837d0u: goto P_0c0837d0;
case 0x0c0837d2u: goto P_0c0837d2;
case 0x0c0837d4u: goto P_0c0837d4;
case 0x0c0837d6u: goto P_0c0837d6;
case 0x0c0837d8u: goto P_0c0837d8;
case 0x0c0837dau: goto P_0c0837da;
case 0x0c0837dcu: goto P_0c0837dc;
case 0x0c0837deu: goto P_0c0837de;
case 0x0c0837e0u: goto P_0c0837e0;
case 0x0c0837e2u: goto P_0c0837e2;
case 0x0c0837e4u: goto P_0c0837e4;
case 0x0c0837e6u: goto P_0c0837e6;
case 0x0c0837e8u: goto P_0c0837e8;
case 0x0c0837eau: goto P_0c0837ea;
case 0x0c0837ecu: goto P_0c0837ec;
case 0x0c0837eeu: goto P_0c0837ee;
case 0x0c0837f0u: goto P_0c0837f0;
case 0x0c08380cu: goto P_0c08380c;
case 0x0c08380eu: goto P_0c08380e;
case 0x0c083810u: goto P_0c083810;
case 0x0c083812u: goto P_0c083812;
case 0x0c083814u: goto P_0c083814;
case 0x0c083816u: goto P_0c083816;
case 0x0c083818u: goto P_0c083818;
case 0x0c08381au: goto P_0c08381a;
case 0x0c08381cu: goto P_0c08381c;
case 0x0c08381eu: goto P_0c08381e;
case 0x0c083820u: goto P_0c083820;
case 0x0c083822u: goto P_0c083822;
case 0x0c083824u: goto P_0c083824;
case 0x0c083826u: goto P_0c083826;
case 0x0c083828u: goto P_0c083828;
case 0x0c08382au: goto P_0c08382a;
case 0x0c08382cu: goto P_0c08382c;
case 0x0c08382eu: goto P_0c08382e;
case 0x0c083830u: goto P_0c083830;
case 0x0c083832u: goto P_0c083832;
case 0x0c083834u: goto P_0c083834;
case 0x0c083836u: goto P_0c083836;
case 0x0c083838u: goto P_0c083838;
case 0x0c08383au: goto P_0c08383a;
case 0x0c08383cu: goto P_0c08383c;
case 0x0c08383eu: goto P_0c08383e;
case 0x0c083840u: goto P_0c083840;
case 0x0c083842u: goto P_0c083842;
case 0x0c083844u: goto P_0c083844;
case 0x0c083846u: goto P_0c083846;
case 0x0c083848u: goto P_0c083848;
case 0x0c08384au: goto P_0c08384a;
case 0x0c08384cu: goto P_0c08384c;
case 0x0c08384eu: goto P_0c08384e;
case 0x0c083850u: goto P_0c083850;
case 0x0c083852u: goto P_0c083852;
case 0x0c083854u: goto P_0c083854;
case 0x0c083856u: goto P_0c083856;
case 0x0c083858u: goto P_0c083858;
case 0x0c08385au: goto P_0c08385a;
case 0x0c08385cu: goto P_0c08385c;
case 0x0c08385eu: goto P_0c08385e;
case 0x0c083860u: goto P_0c083860;
case 0x0c083862u: goto P_0c083862;
case 0x0c083864u: goto P_0c083864;
case 0x0c083866u: goto P_0c083866;
case 0x0c083868u: goto P_0c083868;
case 0x0c08386au: goto P_0c08386a;
case 0x0c08386cu: goto P_0c08386c;
case 0x0c08386eu: goto P_0c08386e;
case 0x0c083870u: goto P_0c083870;
case 0x0c083872u: goto P_0c083872;
case 0x0c083874u: goto P_0c083874;
case 0x0c083876u: goto P_0c083876;
case 0x0c083878u: goto P_0c083878;
case 0x0c08387au: goto P_0c08387a;
case 0x0c08387cu: goto P_0c08387c;
case 0x0c08387eu: goto P_0c08387e;
case 0x0c083880u: goto P_0c083880;
case 0x0c083882u: goto P_0c083882;
case 0x0c083884u: goto P_0c083884;
case 0x0c083886u: goto P_0c083886;
case 0x0c083888u: goto P_0c083888;
case 0x0c08388au: goto P_0c08388a;
case 0x0c08388cu: goto P_0c08388c;
case 0x0c08388eu: goto P_0c08388e;
case 0x0c083890u: goto P_0c083890;
case 0x0c083892u: goto P_0c083892;
case 0x0c083894u: goto P_0c083894;
case 0x0c083896u: goto P_0c083896;
case 0x0c083898u: goto P_0c083898;
case 0x0c08389au: goto P_0c08389a;
case 0x0c08389cu: goto P_0c08389c;
case 0x0c08389eu: goto P_0c08389e;
case 0x0c0838a0u: goto P_0c0838a0;
case 0x0c0838a2u: goto P_0c0838a2;
case 0x0c0838a4u: goto P_0c0838a4;
case 0x0c0838a6u: goto P_0c0838a6;
case 0x0c0838a8u: goto P_0c0838a8;
case 0x0c0838aau: goto P_0c0838aa;
case 0x0c0838acu: goto P_0c0838ac;
case 0x0c0838aeu: goto P_0c0838ae;
case 0x0c0838b0u: goto P_0c0838b0;
case 0x0c0838b2u: goto P_0c0838b2;
case 0x0c0838b4u: goto P_0c0838b4;
case 0x0c0838b6u: goto P_0c0838b6;
case 0x0c0838b8u: goto P_0c0838b8;
case 0x0c0838bau: goto P_0c0838ba;
case 0x0c0838bcu: goto P_0c0838bc;
case 0x0c0838beu: goto P_0c0838be;
case 0x0c0838c0u: goto P_0c0838c0;
case 0x0c0838c2u: goto P_0c0838c2;
case 0x0c0838c4u: goto P_0c0838c4;
case 0x0c0838c6u: goto P_0c0838c6;
case 0x0c0838c8u: goto P_0c0838c8;
case 0x0c0838cau: goto P_0c0838ca;
case 0x0c0838ccu: goto P_0c0838cc;
case 0x0c0838ceu: goto P_0c0838ce;
case 0x0c0838d0u: goto P_0c0838d0;
case 0x0c0838d2u: goto P_0c0838d2;
case 0x0c0838d4u: goto P_0c0838d4;
case 0x0c0838d6u: goto P_0c0838d6;
case 0x0c0838f0u: goto P_0c0838f0;
case 0x0c0838f2u: goto P_0c0838f2;
case 0x0c0838f4u: goto P_0c0838f4;
case 0x0c0838f6u: goto P_0c0838f6;
case 0x0c0838f8u: goto P_0c0838f8;
case 0x0c0838fau: goto P_0c0838fa;
case 0x0c0838fcu: goto P_0c0838fc;
case 0x0c0838feu: goto P_0c0838fe;
case 0x0c083900u: goto P_0c083900;
case 0x0c083902u: goto P_0c083902;
case 0x0c083904u: goto P_0c083904;
case 0x0c083906u: goto P_0c083906;
case 0x0c083908u: goto P_0c083908;
case 0x0c08390au: goto P_0c08390a;
case 0x0c08390cu: goto P_0c08390c;
case 0x0c08390eu: goto P_0c08390e;
case 0x0c083910u: goto P_0c083910;
case 0x0c083912u: goto P_0c083912;
case 0x0c083914u: goto P_0c083914;
case 0x0c083916u: goto P_0c083916;
case 0x0c083918u: goto P_0c083918;
case 0x0c08391au: goto P_0c08391a;
case 0x0c08391cu: goto P_0c08391c;
case 0x0c08391eu: goto P_0c08391e;
case 0x0c083920u: goto P_0c083920;
case 0x0c083922u: goto P_0c083922;
case 0x0c083924u: goto P_0c083924;
case 0x0c083926u: goto P_0c083926;
case 0x0c083928u: goto P_0c083928;
case 0x0c08392au: goto P_0c08392a;
case 0x0c08392cu: goto P_0c08392c;
case 0x0c08392eu: goto P_0c08392e;
case 0x0c083930u: goto P_0c083930;
case 0x0c083932u: goto P_0c083932;
case 0x0c083934u: goto P_0c083934;
case 0x0c083936u: goto P_0c083936;
case 0x0c083938u: goto P_0c083938;
case 0x0c08393au: goto P_0c08393a;
case 0x0c08393cu: goto P_0c08393c;
case 0x0c08393eu: goto P_0c08393e;
case 0x0c083940u: goto P_0c083940;
case 0x0c083942u: goto P_0c083942;
case 0x0c083944u: goto P_0c083944;
case 0x0c083946u: goto P_0c083946;
case 0x0c083948u: goto P_0c083948;
case 0x0c08394au: goto P_0c08394a;
case 0x0c08394cu: goto P_0c08394c;
case 0x0c08394eu: goto P_0c08394e;
case 0x0c083950u: goto P_0c083950;
case 0x0c083952u: goto P_0c083952;
case 0x0c083954u: goto P_0c083954;
case 0x0c083956u: goto P_0c083956;
case 0x0c083958u: goto P_0c083958;
case 0x0c08395au: goto P_0c08395a;
case 0x0c08395cu: goto P_0c08395c;
case 0x0c08395eu: goto P_0c08395e;
case 0x0c083960u: goto P_0c083960;
case 0x0c083962u: goto P_0c083962;
case 0x0c083964u: goto P_0c083964;
case 0x0c083966u: goto P_0c083966;
case 0x0c083968u: goto P_0c083968;
case 0x0c08396au: goto P_0c08396a;
case 0x0c08396cu: goto P_0c08396c;
case 0x0c08396eu: goto P_0c08396e;
case 0x0c083970u: goto P_0c083970;
case 0x0c083972u: goto P_0c083972;
case 0x0c083974u: goto P_0c083974;
case 0x0c083976u: goto P_0c083976;
case 0x0c083978u: goto P_0c083978;
case 0x0c08397au: goto P_0c08397a;
case 0x0c08397cu: goto P_0c08397c;
case 0x0c08397eu: goto P_0c08397e;
case 0x0c083980u: goto P_0c083980;
case 0x0c083982u: goto P_0c083982;
case 0x0c083984u: goto P_0c083984;
case 0x0c083986u: goto P_0c083986;
case 0x0c083988u: goto P_0c083988;
case 0x0c08398au: goto P_0c08398a;
case 0x0c08398cu: goto P_0c08398c;
case 0x0c08398eu: goto P_0c08398e;
case 0x0c083990u: goto P_0c083990;
case 0x0c083992u: goto P_0c083992;
case 0x0c083994u: goto P_0c083994;
case 0x0c083996u: goto P_0c083996;
case 0x0c083998u: goto P_0c083998;
case 0x0c08399au: goto P_0c08399a;
case 0x0c08399cu: goto P_0c08399c;
case 0x0c08399eu: goto P_0c08399e;
case 0x0c0839a0u: goto P_0c0839a0;
case 0x0c0839a2u: goto P_0c0839a2;
case 0x0c0839a4u: goto P_0c0839a4;
case 0x0c0839a6u: goto P_0c0839a6;
case 0x0c0839a8u: goto P_0c0839a8;
case 0x0c0839aau: goto P_0c0839aa;
case 0x0c0839acu: goto P_0c0839ac;
case 0x0c0839aeu: goto P_0c0839ae;
case 0x0c0839b0u: goto P_0c0839b0;
case 0x0c0839b2u: goto P_0c0839b2;
case 0x0c0839b4u: goto P_0c0839b4;
case 0x0c0839b6u: goto P_0c0839b6;
case 0x0c0839b8u: goto P_0c0839b8;
case 0x0c0839bau: goto P_0c0839ba;
case 0x0c0839bcu: goto P_0c0839bc;
case 0x0c0839beu: goto P_0c0839be;
case 0x0c0839c0u: goto P_0c0839c0;
case 0x0c0839c2u: goto P_0c0839c2;
case 0x0c0839c4u: goto P_0c0839c4;
case 0x0c0839c6u: goto P_0c0839c6;
case 0x0c0839c8u: goto P_0c0839c8;
case 0x0c0839cau: goto P_0c0839ca;
case 0x0c0839ccu: goto P_0c0839cc;
case 0x0c0839ceu: goto P_0c0839ce;
case 0x0c0839d0u: goto P_0c0839d0;
case 0x0c0839d2u: goto P_0c0839d2;
case 0x0c0839d4u: goto P_0c0839d4;
case 0x0c0839d6u: goto P_0c0839d6;
case 0x0c0839d8u: goto P_0c0839d8;
case 0x0c0839dau: goto P_0c0839da;
case 0x0c0839dcu: goto P_0c0839dc;
case 0x0c0839deu: goto P_0c0839de;
case 0x0c0839e0u: goto P_0c0839e0;
case 0x0c0839e2u: goto P_0c0839e2;
case 0x0c0839e4u: goto P_0c0839e4;
case 0x0c0839e6u: goto P_0c0839e6;
case 0x0c0839e8u: goto P_0c0839e8;
case 0x0c0839eau: goto P_0c0839ea;
case 0x0c0839ecu: goto P_0c0839ec;
case 0x0c0839eeu: goto P_0c0839ee;
case 0x0c0839f0u: goto P_0c0839f0;
case 0x0c0839f2u: goto P_0c0839f2;
case 0x0c0839f4u: goto P_0c0839f4;
case 0x0c0839f6u: goto P_0c0839f6;
case 0x0c0839f8u: goto P_0c0839f8;
case 0x0c0839fau: goto P_0c0839fa;
case 0x0c0839fcu: goto P_0c0839fc;
case 0x0c0839feu: goto P_0c0839fe;
case 0x0c083a00u: goto P_0c083a00;
case 0x0c083a02u: goto P_0c083a02;
case 0x0c083a04u: goto P_0c083a04;
case 0x0c083a24u: goto P_0c083a24;
case 0x0c083a26u: goto P_0c083a26;
case 0x0c083a28u: goto P_0c083a28;
case 0x0c083a2au: goto P_0c083a2a;
case 0x0c083a2cu: goto P_0c083a2c;
case 0x0c083a2eu: goto P_0c083a2e;
case 0x0c083a30u: goto P_0c083a30;
case 0x0c083a32u: goto P_0c083a32;
case 0x0c083a34u: goto P_0c083a34;
case 0x0c083a36u: goto P_0c083a36;
case 0x0c083a38u: goto P_0c083a38;
case 0x0c083a3au: goto P_0c083a3a;
case 0x0c083a3cu: goto P_0c083a3c;
case 0x0c083a3eu: goto P_0c083a3e;
case 0x0c083a40u: goto P_0c083a40;
case 0x0c083a42u: goto P_0c083a42;
case 0x0c083a44u: goto P_0c083a44;
case 0x0c083a46u: goto P_0c083a46;
case 0x0c083a48u: goto P_0c083a48;
case 0x0c083a4au: goto P_0c083a4a;
case 0x0c083a4cu: goto P_0c083a4c;
case 0x0c083a4eu: goto P_0c083a4e;
case 0x0c083a50u: goto P_0c083a50;
case 0x0c083a52u: goto P_0c083a52;
case 0x0c083a54u: goto P_0c083a54;
case 0x0c083a56u: goto P_0c083a56;
case 0x0c083a58u: goto P_0c083a58;
case 0x0c083a5au: goto P_0c083a5a;
case 0x0c083a5cu: goto P_0c083a5c;
case 0x0c083a5eu: goto P_0c083a5e;
case 0x0c083a60u: goto P_0c083a60;
case 0x0c083a62u: goto P_0c083a62;
case 0x0c083a64u: goto P_0c083a64;
case 0x0c083a66u: goto P_0c083a66;
case 0x0c083a68u: goto P_0c083a68;
case 0x0c083a6au: goto P_0c083a6a;
case 0x0c083a6cu: goto P_0c083a6c;
case 0x0c083a6eu: goto P_0c083a6e;
case 0x0c083a70u: goto P_0c083a70;
case 0x0c083a72u: goto P_0c083a72;
case 0x0c083a74u: goto P_0c083a74;
case 0x0c083a76u: goto P_0c083a76;
case 0x0c083a78u: goto P_0c083a78;
case 0x0c083a7au: goto P_0c083a7a;
case 0x0c083a7cu: goto P_0c083a7c;
case 0x0c083a7eu: goto P_0c083a7e;
case 0x0c083a80u: goto P_0c083a80;
case 0x0c083a82u: goto P_0c083a82;
case 0x0c083a84u: goto P_0c083a84;
case 0x0c083a86u: goto P_0c083a86;
case 0x0c083a88u: goto P_0c083a88;
case 0x0c083a8au: goto P_0c083a8a;
case 0x0c083a8cu: goto P_0c083a8c;
case 0x0c083a8eu: goto P_0c083a8e;
case 0x0c083a90u: goto P_0c083a90;
case 0x0c083a92u: goto P_0c083a92;
case 0x0c083a94u: goto P_0c083a94;
case 0x0c083a96u: goto P_0c083a96;
case 0x0c091028u: goto P_0c091028;
case 0x0c09102au: goto P_0c09102a;
case 0x0c09102cu: goto P_0c09102c;
case 0x0c09102eu: goto P_0c09102e;
case 0x0c091030u: goto P_0c091030;
case 0x0c091032u: goto P_0c091032;
case 0x0c091034u: goto P_0c091034;
case 0x0c091036u: goto P_0c091036;
case 0x0c091038u: goto P_0c091038;
case 0x0c09103au: goto P_0c09103a;
case 0x0c09103cu: goto P_0c09103c;
case 0x0c09103eu: goto P_0c09103e;
case 0x0c091040u: goto P_0c091040;
case 0x0c091042u: goto P_0c091042;
case 0x0c091044u: goto P_0c091044;
case 0x0c091046u: goto P_0c091046;
case 0x0c091048u: goto P_0c091048;
case 0x0c09104au: goto P_0c09104a;
case 0x0c09104cu: goto P_0c09104c;
case 0x0c09104eu: goto P_0c09104e;
case 0x0c091050u: goto P_0c091050;
case 0x0c091052u: goto P_0c091052;
case 0x0c091054u: goto P_0c091054;
case 0x0c091056u: goto P_0c091056;
case 0x0c091058u: goto P_0c091058;
case 0x0c09105au: goto P_0c09105a;
case 0x0c09105cu: goto P_0c09105c;
case 0x0c09105eu: goto P_0c09105e;
case 0x0c091060u: goto P_0c091060;
case 0x0c091062u: goto P_0c091062;
case 0x0c091064u: goto P_0c091064;
case 0x0c091066u: goto P_0c091066;
case 0x0c091068u: goto P_0c091068;
case 0x0c09106au: goto P_0c09106a;
case 0x0c09106cu: goto P_0c09106c;
case 0x0c09106eu: goto P_0c09106e;
case 0x0c091070u: goto P_0c091070;
case 0x0c091072u: goto P_0c091072;
case 0x0c091074u: goto P_0c091074;
case 0x0c091076u: goto P_0c091076;
case 0x0c091078u: goto P_0c091078;
case 0x0c09107au: goto P_0c09107a;
case 0x0c09107cu: goto P_0c09107c;
case 0x0c09107eu: goto P_0c09107e;
case 0x0c091080u: goto P_0c091080;
case 0x0c091108u: goto P_0c091108;
case 0x0c09110au: goto P_0c09110a;
case 0x0c09110cu: goto P_0c09110c;
case 0x0c09110eu: goto P_0c09110e;
case 0x0c091110u: goto P_0c091110;
case 0x0c091112u: goto P_0c091112;
case 0x0c091114u: goto P_0c091114;
case 0x0c091116u: goto P_0c091116;
case 0x0c091118u: goto P_0c091118;
case 0x0c09111au: goto P_0c09111a;
case 0x0c09111cu: goto P_0c09111c;
case 0x0c09111eu: goto P_0c09111e;
case 0x0c091120u: goto P_0c091120;
case 0x0c091122u: goto P_0c091122;
case 0x0c091124u: goto P_0c091124;
case 0x0c091126u: goto P_0c091126;
case 0x0c091128u: goto P_0c091128;
case 0x0c09112au: goto P_0c09112a;
case 0x0c09112cu: goto P_0c09112c;
case 0x0c09112eu: goto P_0c09112e;
case 0x0c091130u: goto P_0c091130;
case 0x0c091132u: goto P_0c091132;
case 0x0c091134u: goto P_0c091134;
case 0x0c091136u: goto P_0c091136;
case 0x0c091138u: goto P_0c091138;
case 0x0c09113au: goto P_0c09113a;
case 0x0c09113cu: goto P_0c09113c;
case 0x0c09113eu: goto P_0c09113e;
case 0x0c091180u: goto P_0c091180;
case 0x0c091182u: goto P_0c091182;
case 0x0c091184u: goto P_0c091184;
case 0x0c091186u: goto P_0c091186;
case 0x0c091188u: goto P_0c091188;
case 0x0c09118au: goto P_0c09118a;
case 0x0c09118cu: goto P_0c09118c;
case 0x0c09118eu: goto P_0c09118e;
case 0x0c091190u: goto P_0c091190;
case 0x0c091192u: goto P_0c091192;
case 0x0c091194u: goto P_0c091194;
case 0x0c091196u: goto P_0c091196;
case 0x0c091198u: goto P_0c091198;
case 0x0c09119au: goto P_0c09119a;
case 0x0c09119cu: goto P_0c09119c;
case 0x0c09119eu: goto P_0c09119e;
case 0x0c0911a0u: goto P_0c0911a0;
case 0x0c0911a2u: goto P_0c0911a2;
case 0x0c0911a4u: goto P_0c0911a4;
case 0x0c0911a6u: goto P_0c0911a6;
case 0x0c0911a8u: goto P_0c0911a8;
case 0x0c0911aau: goto P_0c0911aa;
case 0x0c0911acu: goto P_0c0911ac;
case 0x0c0911aeu: goto P_0c0911ae;
case 0x0c0911b0u: goto P_0c0911b0;
case 0x0c0911b2u: goto P_0c0911b2;
case 0x0c0911b4u: goto P_0c0911b4;
case 0x0c0911b6u: goto P_0c0911b6;
case 0x0c091242u: goto P_0c091242;
case 0x0c091244u: goto P_0c091244;
case 0x0c091246u: goto P_0c091246;
case 0x0c091248u: goto P_0c091248;
case 0x0c09124au: goto P_0c09124a;
case 0x0c09124cu: goto P_0c09124c;
case 0x0c09124eu: goto P_0c09124e;
case 0x0c091250u: goto P_0c091250;
case 0x0c091252u: goto P_0c091252;
case 0x0c091254u: goto P_0c091254;
case 0x0c091256u: goto P_0c091256;
case 0x0c091258u: goto P_0c091258;
case 0x0c09125au: goto P_0c09125a;
case 0x0c09125cu: goto P_0c09125c;
case 0x0c09125eu: goto P_0c09125e;
case 0x0c091260u: goto P_0c091260;
case 0x0c091262u: goto P_0c091262;
case 0x0c091264u: goto P_0c091264;
case 0x0c091266u: goto P_0c091266;
case 0x0c091268u: goto P_0c091268;
case 0x0c09126au: goto P_0c09126a;
case 0x0c09126cu: goto P_0c09126c;
case 0x0c09126eu: goto P_0c09126e;
case 0x0c091270u: goto P_0c091270;
case 0x0c091272u: goto P_0c091272;
case 0x0c091274u: goto P_0c091274;
case 0x0c091276u: goto P_0c091276;
case 0x0c091278u: goto P_0c091278;
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
case 0x0c097aa4u: goto P_0c097aa4;
case 0x0c097aa6u: goto P_0c097aa6;
case 0x0c097aa8u: goto P_0c097aa8;
case 0x0c097aaau: goto P_0c097aaa;
case 0x0c097aacu: goto P_0c097aac;
case 0x0c097aaeu: goto P_0c097aae;
case 0x0c097ab0u: goto P_0c097ab0;
case 0x0c097ab2u: goto P_0c097ab2;
case 0x0c097ab4u: goto P_0c097ab4;
case 0x0c097ab6u: goto P_0c097ab6;
case 0x0c097ab8u: goto P_0c097ab8;
case 0x0c097abau: goto P_0c097aba;
case 0x0c097abcu: goto P_0c097abc;
case 0x0c097abeu: goto P_0c097abe;
case 0x0c097ac0u: goto P_0c097ac0;
case 0x0c097ac2u: goto P_0c097ac2;
case 0x0c097ac4u: goto P_0c097ac4;
case 0x0c097ac6u: goto P_0c097ac6;
case 0x0c097ac8u: goto P_0c097ac8;
case 0x0c097acau: goto P_0c097aca;
case 0x0c097accu: goto P_0c097acc;
case 0x0c097aceu: goto P_0c097ace;
case 0x0c097ad0u: goto P_0c097ad0;
case 0x0c097ad2u: goto P_0c097ad2;
case 0x0c097ad4u: goto P_0c097ad4;
case 0x0c097ad6u: goto P_0c097ad6;
case 0x0c097ad8u: goto P_0c097ad8;
case 0x0c097adau: goto P_0c097ada;
case 0x0c097adcu: goto P_0c097adc;
case 0x0c097adeu: goto P_0c097ade;
case 0x0c097ae0u: goto P_0c097ae0;
case 0x0c097ae2u: goto P_0c097ae2;
case 0x0c097ae4u: goto P_0c097ae4;
case 0x0c097ae6u: goto P_0c097ae6;
case 0x0c097ae8u: goto P_0c097ae8;
case 0x0c097aeau: goto P_0c097aea;
case 0x0c097aecu: goto P_0c097aec;
case 0x0c097aeeu: goto P_0c097aee;
case 0x0c097af0u: goto P_0c097af0;
case 0x0c097af2u: goto P_0c097af2;
case 0x0c097af4u: goto P_0c097af4;
case 0x0c097af6u: goto P_0c097af6;
case 0x0c097af8u: goto P_0c097af8;
case 0x0c097afau: goto P_0c097afa;
case 0x0c097afcu: goto P_0c097afc;
case 0x0c097afeu: goto P_0c097afe;
case 0x0c097b00u: goto P_0c097b00;
case 0x0c097b02u: goto P_0c097b02;
case 0x0c097b04u: goto P_0c097b04;
case 0x0c097b06u: goto P_0c097b06;
case 0x0c097b08u: goto P_0c097b08;
case 0x0c097b0au: goto P_0c097b0a;
case 0x0c097b0cu: goto P_0c097b0c;
case 0x0c097b0eu: goto P_0c097b0e;
case 0x0c097b10u: goto P_0c097b10;
case 0x0c097b12u: goto P_0c097b12;
case 0x0c097b14u: goto P_0c097b14;
case 0x0c097b16u: goto P_0c097b16;
case 0x0c097b18u: goto P_0c097b18;
case 0x0c097b1au: goto P_0c097b1a;
case 0x0c097b1cu: goto P_0c097b1c;
case 0x0c097b1eu: goto P_0c097b1e;
case 0x0c097b20u: goto P_0c097b20;
case 0x0c097b22u: goto P_0c097b22;
case 0x0c097b24u: goto P_0c097b24;
case 0x0c097b26u: goto P_0c097b26;
case 0x0c097b28u: goto P_0c097b28;
case 0x0c097b2au: goto P_0c097b2a;
case 0x0c097b2cu: goto P_0c097b2c;
case 0x0c097b2eu: goto P_0c097b2e;
case 0x0c097b30u: goto P_0c097b30;
case 0x0c097b32u: goto P_0c097b32;
case 0x0c097b34u: goto P_0c097b34;
case 0x0c097b36u: goto P_0c097b36;
case 0x0c097b38u: goto P_0c097b38;
case 0x0c097b3au: goto P_0c097b3a;
case 0x0c097b3cu: goto P_0c097b3c;
case 0x0c097b3eu: goto P_0c097b3e;
case 0x0c097b40u: goto P_0c097b40;
case 0x0c097b42u: goto P_0c097b42;
case 0x0c097b44u: goto P_0c097b44;
case 0x0c097b46u: goto P_0c097b46;
case 0x0c097b48u: goto P_0c097b48;
case 0x0c097b4au: goto P_0c097b4a;
case 0x0c097b4cu: goto P_0c097b4c;
case 0x0c097b4eu: goto P_0c097b4e;
case 0x0c097b50u: goto P_0c097b50;
case 0x0c097b52u: goto P_0c097b52;
case 0x0c097b54u: goto P_0c097b54;
case 0x0c097b56u: goto P_0c097b56;
case 0x0c097b58u: goto P_0c097b58;
case 0x0c097b5au: goto P_0c097b5a;
case 0x0c097b5cu: goto P_0c097b5c;
case 0x0c097b5eu: goto P_0c097b5e;
case 0x0c097b60u: goto P_0c097b60;
case 0x0c097b62u: goto P_0c097b62;
case 0x0c097b64u: goto P_0c097b64;
case 0x0c097b66u: goto P_0c097b66;
case 0x0c097b68u: goto P_0c097b68;
case 0x0c097b6au: goto P_0c097b6a;
case 0x0c097b6cu: goto P_0c097b6c;
case 0x0c097b6eu: goto P_0c097b6e;
case 0x0c097b70u: goto P_0c097b70;
case 0x0c097b9cu: goto P_0c097b9c;
case 0x0c097b9eu: goto P_0c097b9e;
case 0x0c097ba0u: goto P_0c097ba0;
case 0x0c097ba2u: goto P_0c097ba2;
case 0x0c097ba4u: goto P_0c097ba4;
case 0x0c097ba6u: goto P_0c097ba6;
case 0x0c097ba8u: goto P_0c097ba8;
case 0x0c097baau: goto P_0c097baa;
case 0x0c097bacu: goto P_0c097bac;
case 0x0c097baeu: goto P_0c097bae;
case 0x0c097bb0u: goto P_0c097bb0;
case 0x0c097bb2u: goto P_0c097bb2;
case 0x0c097bb4u: goto P_0c097bb4;
case 0x0c097bb6u: goto P_0c097bb6;
case 0x0c097bb8u: goto P_0c097bb8;
case 0x0c097bbau: goto P_0c097bba;
case 0x0c097bbcu: goto P_0c097bbc;
case 0x0c097bbeu: goto P_0c097bbe;
case 0x0c097bc0u: goto P_0c097bc0;
case 0x0c097bc2u: goto P_0c097bc2;
case 0x0c097bc4u: goto P_0c097bc4;
case 0x0c097bc6u: goto P_0c097bc6;
case 0x0c097bc8u: goto P_0c097bc8;
case 0x0c097bcau: goto P_0c097bca;
case 0x0c097bccu: goto P_0c097bcc;
case 0x0c097bceu: goto P_0c097bce;
case 0x0c097bd0u: goto P_0c097bd0;
case 0x0c097bd2u: goto P_0c097bd2;
case 0x0c097bd4u: goto P_0c097bd4;
case 0x0c097bd6u: goto P_0c097bd6;
case 0x0c097bd8u: goto P_0c097bd8;
case 0x0c097bdau: goto P_0c097bda;
case 0x0c097bdcu: goto P_0c097bdc;
case 0x0c097bdeu: goto P_0c097bde;
case 0x0c097be0u: goto P_0c097be0;
case 0x0c097be2u: goto P_0c097be2;
case 0x0c097be4u: goto P_0c097be4;
case 0x0c097be6u: goto P_0c097be6;
case 0x0c097be8u: goto P_0c097be8;
case 0x0c097beau: goto P_0c097bea;
case 0x0c097becu: goto P_0c097bec;
case 0x0c097beeu: goto P_0c097bee;
case 0x0c097bf0u: goto P_0c097bf0;
case 0x0c097bf2u: goto P_0c097bf2;
case 0x0c097bf4u: goto P_0c097bf4;
case 0x0c097bf6u: goto P_0c097bf6;
case 0x0c097bf8u: goto P_0c097bf8;
case 0x0c097bfau: goto P_0c097bfa;
case 0x0c097bfcu: goto P_0c097bfc;
case 0x0c097bfeu: goto P_0c097bfe;
case 0x0c097c00u: goto P_0c097c00;
case 0x0c097c02u: goto P_0c097c02;
case 0x0c097c04u: goto P_0c097c04;
case 0x0c097c06u: goto P_0c097c06;
case 0x0c097c08u: goto P_0c097c08;
case 0x0c097c0au: goto P_0c097c0a;
case 0x0c097c0cu: goto P_0c097c0c;
case 0x0c097c0eu: goto P_0c097c0e;
case 0x0c097c10u: goto P_0c097c10;
case 0x0c097c12u: goto P_0c097c12;
case 0x0c097c14u: goto P_0c097c14;
case 0x0c097c16u: goto P_0c097c16;
case 0x0c097c18u: goto P_0c097c18;
case 0x0c097c1au: goto P_0c097c1a;
case 0x0c097c1cu: goto P_0c097c1c;
case 0x0c097c1eu: goto P_0c097c1e;
case 0x0c097c20u: goto P_0c097c20;
case 0x0c097c22u: goto P_0c097c22;
case 0x0c097c24u: goto P_0c097c24;
case 0x0c097c26u: goto P_0c097c26;
case 0x0c097c28u: goto P_0c097c28;
case 0x0c097c2au: goto P_0c097c2a;
case 0x0c097c2cu: goto P_0c097c2c;
case 0x0c097c2eu: goto P_0c097c2e;
case 0x0c097c30u: goto P_0c097c30;
case 0x0c097c32u: goto P_0c097c32;
case 0x0c097c34u: goto P_0c097c34;
case 0x0c097c36u: goto P_0c097c36;
case 0x0c097c38u: goto P_0c097c38;
case 0x0c097c3au: goto P_0c097c3a;
case 0x0c097c3cu: goto P_0c097c3c;
case 0x0c097c3eu: goto P_0c097c3e;
case 0x0c097c40u: goto P_0c097c40;
case 0x0c097c42u: goto P_0c097c42;
case 0x0c097c44u: goto P_0c097c44;
case 0x0c097c46u: goto P_0c097c46;
case 0x0c097c48u: goto P_0c097c48;
case 0x0c097c4au: goto P_0c097c4a;
case 0x0c097c4cu: goto P_0c097c4c;
case 0x0c097c4eu: goto P_0c097c4e;
case 0x0c097c50u: goto P_0c097c50;
case 0x0c097c52u: goto P_0c097c52;
case 0x0c097c54u: goto P_0c097c54;
case 0x0c097c56u: goto P_0c097c56;
case 0x0c097c58u: goto P_0c097c58;
case 0x0c097c5au: goto P_0c097c5a;
case 0x0c097c5cu: goto P_0c097c5c;
case 0x0c097c5eu: goto P_0c097c5e;
case 0x0c097c60u: goto P_0c097c60;
case 0x0c097c62u: goto P_0c097c62;
case 0x0c097c64u: goto P_0c097c64;
case 0x0c097c66u: goto P_0c097c66;
case 0x0c097c68u: goto P_0c097c68;
case 0x0c097c6au: goto P_0c097c6a;
case 0x0c097c6cu: goto P_0c097c6c;
case 0x0c097c6eu: goto P_0c097c6e;
case 0x0c097c70u: goto P_0c097c70;
case 0x0c097c72u: goto P_0c097c72;
case 0x0c097c74u: goto P_0c097c74;
case 0x0c097c76u: goto P_0c097c76;
case 0x0c097c78u: goto P_0c097c78;
case 0x0c097c7au: goto P_0c097c7a;
case 0x0c097c7cu: goto P_0c097c7c;
case 0x0c097c7eu: goto P_0c097c7e;
case 0x0c097c80u: goto P_0c097c80;
case 0x0c097c82u: goto P_0c097c82;
case 0x0c097c84u: goto P_0c097c84;
case 0x0c097c86u: goto P_0c097c86;
case 0x0c097c88u: goto P_0c097c88;
case 0x0c097c8au: goto P_0c097c8a;
case 0x0c097c8cu: goto P_0c097c8c;
case 0x0c097c8eu: goto P_0c097c8e;
case 0x0c097c90u: goto P_0c097c90;
case 0x0c097c92u: goto P_0c097c92;
case 0x0c097c94u: goto P_0c097c94;
case 0x0c097c96u: goto P_0c097c96;
case 0x0c097c98u: goto P_0c097c98;
case 0x0c097c9au: goto P_0c097c9a;
case 0x0c097c9cu: goto P_0c097c9c;
case 0x0c097c9eu: goto P_0c097c9e;
case 0x0c097ca0u: goto P_0c097ca0;
case 0x0c097ca2u: goto P_0c097ca2;
case 0x0c097ca4u: goto P_0c097ca4;
case 0x0c097ca6u: goto P_0c097ca6;
case 0x0c097ca8u: goto P_0c097ca8;
case 0x0c097caau: goto P_0c097caa;
case 0x0c097cacu: goto P_0c097cac;
case 0x0c097caeu: goto P_0c097cae;
case 0x0c097cb0u: goto P_0c097cb0;
case 0x0c097cb2u: goto P_0c097cb2;
case 0x0c097cb4u: goto P_0c097cb4;
case 0x0c097cb6u: goto P_0c097cb6;
case 0x0c097cb8u: goto P_0c097cb8;
case 0x0c097cbau: goto P_0c097cba;
case 0x0c097cbcu: goto P_0c097cbc;
case 0x0c097cbeu: goto P_0c097cbe;
case 0x0c097cc0u: goto P_0c097cc0;
case 0x0c097cc2u: goto P_0c097cc2;
case 0x0c097d18u: goto P_0c097d18;
case 0x0c097d1au: goto P_0c097d1a;
case 0x0c097d1cu: goto P_0c097d1c;
case 0x0c097d1eu: goto P_0c097d1e;
case 0x0c097d20u: goto P_0c097d20;
case 0x0c097d22u: goto P_0c097d22;
case 0x0c097d24u: goto P_0c097d24;
case 0x0c097d26u: goto P_0c097d26;
case 0x0c097d28u: goto P_0c097d28;
case 0x0c097d2au: goto P_0c097d2a;
case 0x0c097d2cu: goto P_0c097d2c;
case 0x0c097d2eu: goto P_0c097d2e;
case 0x0c097d30u: goto P_0c097d30;
case 0x0c097d32u: goto P_0c097d32;
case 0x0c097d34u: goto P_0c097d34;
case 0x0c097d36u: goto P_0c097d36;
case 0x0c097d38u: goto P_0c097d38;
case 0x0c097d3au: goto P_0c097d3a;
case 0x0c097d3cu: goto P_0c097d3c;
case 0x0c097d3eu: goto P_0c097d3e;
case 0x0c097d40u: goto P_0c097d40;
case 0x0c097d42u: goto P_0c097d42;
case 0x0c097d44u: goto P_0c097d44;
case 0x0c097d46u: goto P_0c097d46;
case 0x0c097d48u: goto P_0c097d48;
case 0x0c097d4au: goto P_0c097d4a;
case 0x0c097d4cu: goto P_0c097d4c;
case 0x0c097d4eu: goto P_0c097d4e;
case 0x0c097d50u: goto P_0c097d50;
case 0x0c097d52u: goto P_0c097d52;
case 0x0c097d54u: goto P_0c097d54;
case 0x0c097d56u: goto P_0c097d56;
case 0x0c097d58u: goto P_0c097d58;
case 0x0c097d5au: goto P_0c097d5a;
case 0x0c097d5cu: goto P_0c097d5c;
case 0x0c097d5eu: goto P_0c097d5e;
case 0x0c097d60u: goto P_0c097d60;
case 0x0c097d62u: goto P_0c097d62;
case 0x0c097d64u: goto P_0c097d64;
case 0x0c097d66u: goto P_0c097d66;
case 0x0c097d68u: goto P_0c097d68;
case 0x0c097d6au: goto P_0c097d6a;
case 0x0c097d6cu: goto P_0c097d6c;
case 0x0c097d6eu: goto P_0c097d6e;
case 0x0c097d70u: goto P_0c097d70;
case 0x0c097d72u: goto P_0c097d72;
case 0x0c097d74u: goto P_0c097d74;
case 0x0c097d76u: goto P_0c097d76;
case 0x0c097d78u: goto P_0c097d78;
case 0x0c097d7au: goto P_0c097d7a;
case 0x0c097d7cu: goto P_0c097d7c;
case 0x0c097d7eu: goto P_0c097d7e;
case 0x0c097d80u: goto P_0c097d80;
case 0x0c097d82u: goto P_0c097d82;
case 0x0c097d84u: goto P_0c097d84;
case 0x0c097d86u: goto P_0c097d86;
case 0x0c097d88u: goto P_0c097d88;
case 0x0c097d8au: goto P_0c097d8a;
case 0x0c097d8cu: goto P_0c097d8c;
case 0x0c097d8eu: goto P_0c097d8e;
case 0x0c097d90u: goto P_0c097d90;
case 0x0c097d92u: goto P_0c097d92;
case 0x0c097d94u: goto P_0c097d94;
case 0x0c097d96u: goto P_0c097d96;
case 0x0c097d98u: goto P_0c097d98;
case 0x0c097d9au: goto P_0c097d9a;
case 0x0c097d9cu: goto P_0c097d9c;
case 0x0c097d9eu: goto P_0c097d9e;
case 0x0c097da0u: goto P_0c097da0;
case 0x0c097da2u: goto P_0c097da2;
case 0x0c097da4u: goto P_0c097da4;
case 0x0c097da6u: goto P_0c097da6;
case 0x0c097da8u: goto P_0c097da8;
case 0x0c097daau: goto P_0c097daa;
case 0x0c097dacu: goto P_0c097dac;
case 0x0c097daeu: goto P_0c097dae;
case 0x0c097db0u: goto P_0c097db0;
case 0x0c097db2u: goto P_0c097db2;
case 0x0c097db4u: goto P_0c097db4;
case 0x0c097db6u: goto P_0c097db6;
case 0x0c097db8u: goto P_0c097db8;
case 0x0c097dbau: goto P_0c097dba;
case 0x0c097dbcu: goto P_0c097dbc;
case 0x0c097dbeu: goto P_0c097dbe;
case 0x0c097dc0u: goto P_0c097dc0;
case 0x0c097dc2u: goto P_0c097dc2;
case 0x0c097dc4u: goto P_0c097dc4;
case 0x0c097dc6u: goto P_0c097dc6;
case 0x0c097dc8u: goto P_0c097dc8;
case 0x0c097dcau: goto P_0c097dca;
case 0x0c097dccu: goto P_0c097dcc;
case 0x0c097dceu: goto P_0c097dce;
case 0x0c097dd0u: goto P_0c097dd0;
case 0x0c097dd2u: goto P_0c097dd2;
case 0x0c097dd4u: goto P_0c097dd4;
case 0x0c097dd6u: goto P_0c097dd6;
case 0x0c097dd8u: goto P_0c097dd8;
case 0x0c097ddau: goto P_0c097dda;
case 0x0c097ddcu: goto P_0c097ddc;
case 0x0c097ddeu: goto P_0c097dde;
case 0x0c097de0u: goto P_0c097de0;
case 0x0c097de2u: goto P_0c097de2;
case 0x0c097de4u: goto P_0c097de4;
case 0x0c097de6u: goto P_0c097de6;
case 0x0c097de8u: goto P_0c097de8;
case 0x0c097deau: goto P_0c097dea;
case 0x0c097decu: goto P_0c097dec;
case 0x0c097deeu: goto P_0c097dee;
case 0x0c097e0cu: goto P_0c097e0c;
case 0x0c097e0eu: goto P_0c097e0e;
case 0x0c097e10u: goto P_0c097e10;
case 0x0c097e12u: goto P_0c097e12;
case 0x0c097e14u: goto P_0c097e14;
case 0x0c097e16u: goto P_0c097e16;
case 0x0c097e18u: goto P_0c097e18;
case 0x0c097e1au: goto P_0c097e1a;
case 0x0c097e1cu: goto P_0c097e1c;
case 0x0c097e1eu: goto P_0c097e1e;
case 0x0c097e20u: goto P_0c097e20;
case 0x0c097e22u: goto P_0c097e22;
case 0x0c097e24u: goto P_0c097e24;
case 0x0c097e26u: goto P_0c097e26;
case 0x0c097e28u: goto P_0c097e28;
case 0x0c097e2au: goto P_0c097e2a;
case 0x0c097e2cu: goto P_0c097e2c;
case 0x0c097e2eu: goto P_0c097e2e;
case 0x0c097e30u: goto P_0c097e30;
case 0x0c097e32u: goto P_0c097e32;
case 0x0c097e34u: goto P_0c097e34;
case 0x0c097e36u: goto P_0c097e36;
case 0x0c097e38u: goto P_0c097e38;
case 0x0c097e3au: goto P_0c097e3a;
case 0x0c097e3cu: goto P_0c097e3c;
case 0x0c097e3eu: goto P_0c097e3e;
case 0x0c097e40u: goto P_0c097e40;
case 0x0c097e42u: goto P_0c097e42;
case 0x0c097e44u: goto P_0c097e44;
case 0x0c097e46u: goto P_0c097e46;
case 0x0c097e48u: goto P_0c097e48;
case 0x0c097e4au: goto P_0c097e4a;
case 0x0c097e4cu: goto P_0c097e4c;
case 0x0c097e4eu: goto P_0c097e4e;
case 0x0c097e50u: goto P_0c097e50;
case 0x0c097e52u: goto P_0c097e52;
case 0x0c097e54u: goto P_0c097e54;
case 0x0c097e56u: goto P_0c097e56;
case 0x0c097e58u: goto P_0c097e58;
case 0x0c097e5au: goto P_0c097e5a;
case 0x0c097e5cu: goto P_0c097e5c;
case 0x0c097e5eu: goto P_0c097e5e;
case 0x0c097e60u: goto P_0c097e60;
case 0x0c097e62u: goto P_0c097e62;
case 0x0c097e64u: goto P_0c097e64;
case 0x0c097e66u: goto P_0c097e66;
case 0x0c097e68u: goto P_0c097e68;
case 0x0c097e6au: goto P_0c097e6a;
case 0x0c097e6cu: goto P_0c097e6c;
case 0x0c097e6eu: goto P_0c097e6e;
case 0x0c097e70u: goto P_0c097e70;
case 0x0c097e72u: goto P_0c097e72;
case 0x0c097e74u: goto P_0c097e74;
case 0x0c097e76u: goto P_0c097e76;
case 0x0c097e78u: goto P_0c097e78;
case 0x0c097e7au: goto P_0c097e7a;
case 0x0c097e7cu: goto P_0c097e7c;
case 0x0c097e7eu: goto P_0c097e7e;
case 0x0c097e80u: goto P_0c097e80;
case 0x0c097e82u: goto P_0c097e82;
case 0x0c097e84u: goto P_0c097e84;
case 0x0c097e86u: goto P_0c097e86;
case 0x0c097e88u: goto P_0c097e88;
case 0x0c097e8au: goto P_0c097e8a;
case 0x0c097e8cu: goto P_0c097e8c;
case 0x0c097e8eu: goto P_0c097e8e;
case 0x0c097e90u: goto P_0c097e90;
case 0x0c097e92u: goto P_0c097e92;
case 0x0c097e94u: goto P_0c097e94;
case 0x0c097e96u: goto P_0c097e96;
case 0x0c097e98u: goto P_0c097e98;
case 0x0c097e9au: goto P_0c097e9a;
case 0x0c097e9cu: goto P_0c097e9c;
case 0x0c097e9eu: goto P_0c097e9e;
case 0x0c097ea0u: goto P_0c097ea0;
case 0x0c097ea2u: goto P_0c097ea2;
case 0x0c097ea4u: goto P_0c097ea4;
case 0x0c097eb6u: goto P_0c097eb6;
case 0x0c097eb8u: goto P_0c097eb8;
case 0x0c097ebau: goto P_0c097eba;
case 0x0c097ebcu: goto P_0c097ebc;
case 0x0c097ebeu: goto P_0c097ebe;
case 0x0c097ec0u: goto P_0c097ec0;
case 0x0c097ec2u: goto P_0c097ec2;
case 0x0c097ec4u: goto P_0c097ec4;
case 0x0c097ec6u: goto P_0c097ec6;
case 0x0c097ec8u: goto P_0c097ec8;
case 0x0c097ecau: goto P_0c097eca;
case 0x0c097eccu: goto P_0c097ecc;
case 0x0c097eceu: goto P_0c097ece;
case 0x0c097ed0u: goto P_0c097ed0;
case 0x0c097ed2u: goto P_0c097ed2;
case 0x0c097ed4u: goto P_0c097ed4;
case 0x0c097ed6u: goto P_0c097ed6;
case 0x0c097ed8u: goto P_0c097ed8;
case 0x0c097edau: goto P_0c097eda;
case 0x0c097edcu: goto P_0c097edc;
case 0x0c097edeu: goto P_0c097ede;
case 0x0c097ee0u: goto P_0c097ee0;
case 0x0c097ee2u: goto P_0c097ee2;
case 0x0c097ee4u: goto P_0c097ee4;
case 0x0c097ee6u: goto P_0c097ee6;
case 0x0c097ee8u: goto P_0c097ee8;
case 0x0c097eeau: goto P_0c097eea;
case 0x0c097eecu: goto P_0c097eec;
case 0x0c097eeeu: goto P_0c097eee;
case 0x0c097ef0u: goto P_0c097ef0;
case 0x0c097ef2u: goto P_0c097ef2;
case 0x0c097ef4u: goto P_0c097ef4;
case 0x0c097ef6u: goto P_0c097ef6;
case 0x0c097ef8u: goto P_0c097ef8;
case 0x0c097efau: goto P_0c097efa;
case 0x0c097efcu: goto P_0c097efc;
case 0x0c097efeu: goto P_0c097efe;
case 0x0c097f00u: goto P_0c097f00;
case 0x0c097f02u: goto P_0c097f02;
case 0x0c097f04u: goto P_0c097f04;
case 0x0c097f06u: goto P_0c097f06;
case 0x0c097f08u: goto P_0c097f08;
case 0x0c097f0au: goto P_0c097f0a;
case 0x0c097f0cu: goto P_0c097f0c;
case 0x0c097f0eu: goto P_0c097f0e;
case 0x0c097f10u: goto P_0c097f10;
case 0x0c097f12u: goto P_0c097f12;
case 0x0c097f14u: goto P_0c097f14;
case 0x0c097f16u: goto P_0c097f16;
case 0x0c097f18u: goto P_0c097f18;
case 0x0c097f1au: goto P_0c097f1a;
case 0x0c097f1cu: goto P_0c097f1c;
case 0x0c097f1eu: goto P_0c097f1e;
case 0x0c097f20u: goto P_0c097f20;
case 0x0c097f22u: goto P_0c097f22;
case 0x0c097f24u: goto P_0c097f24;
case 0x0c097f26u: goto P_0c097f26;
case 0x0c097f28u: goto P_0c097f28;
case 0x0c097f2au: goto P_0c097f2a;
case 0x0c097f2cu: goto P_0c097f2c;
case 0x0c097f2eu: goto P_0c097f2e;
case 0x0c097f30u: goto P_0c097f30;
case 0x0c097f32u: goto P_0c097f32;
case 0x0c097f34u: goto P_0c097f34;
case 0x0c097f36u: goto P_0c097f36;
case 0x0c097f38u: goto P_0c097f38;
case 0x0c097f3au: goto P_0c097f3a;
case 0x0c097f3cu: goto P_0c097f3c;
case 0x0c097f3eu: goto P_0c097f3e;
case 0x0c097f40u: goto P_0c097f40;
case 0x0c097f42u: goto P_0c097f42;
case 0x0c097f44u: goto P_0c097f44;
case 0x0c097f46u: goto P_0c097f46;
case 0x0c097f48u: goto P_0c097f48;
case 0x0c097f4au: goto P_0c097f4a;
case 0x0c097f4cu: goto P_0c097f4c;
case 0x0c097f4eu: goto P_0c097f4e;
case 0x0c097f50u: goto P_0c097f50;
case 0x0c097f52u: goto P_0c097f52;
case 0x0c097f54u: goto P_0c097f54;
case 0x0c097f56u: goto P_0c097f56;
case 0x0c097f58u: goto P_0c097f58;
case 0x0c097f5au: goto P_0c097f5a;
case 0x0c097f5cu: goto P_0c097f5c;
case 0x0c097f5eu: goto P_0c097f5e;
case 0x0c097f60u: goto P_0c097f60;
case 0x0c097f62u: goto P_0c097f62;
case 0x0c097f64u: goto P_0c097f64;
case 0x0c097f66u: goto P_0c097f66;
case 0x0c097f68u: goto P_0c097f68;
case 0x0c097f6au: goto P_0c097f6a;
case 0x0c097f6cu: goto P_0c097f6c;
case 0x0c097f6eu: goto P_0c097f6e;
case 0x0c097f70u: goto P_0c097f70;
case 0x0c097f72u: goto P_0c097f72;
case 0x0c097f74u: goto P_0c097f74;
case 0x0c097f76u: goto P_0c097f76;
case 0x0c097f78u: goto P_0c097f78;
case 0x0c097f9cu: goto P_0c097f9c;
case 0x0c097f9eu: goto P_0c097f9e;
case 0x0c097fa0u: goto P_0c097fa0;
case 0x0c097fa2u: goto P_0c097fa2;
case 0x0c097fa4u: goto P_0c097fa4;
case 0x0c097fa6u: goto P_0c097fa6;
case 0x0c097fa8u: goto P_0c097fa8;
case 0x0c097faau: goto P_0c097faa;
case 0x0c097facu: goto P_0c097fac;
case 0x0c097faeu: goto P_0c097fae;
case 0x0c097fb0u: goto P_0c097fb0;
case 0x0c097fb2u: goto P_0c097fb2;
case 0x0c097fb4u: goto P_0c097fb4;
case 0x0c097fb6u: goto P_0c097fb6;
case 0x0c097fb8u: goto P_0c097fb8;
case 0x0c097fbau: goto P_0c097fba;
case 0x0c097fbcu: goto P_0c097fbc;
case 0x0c097fbeu: goto P_0c097fbe;
case 0x0c097fc0u: goto P_0c097fc0;
case 0x0c097fc2u: goto P_0c097fc2;
case 0x0c097fc4u: goto P_0c097fc4;
case 0x0c097fc6u: goto P_0c097fc6;
case 0x0c097fc8u: goto P_0c097fc8;
case 0x0c097fcau: goto P_0c097fca;
case 0x0c097fccu: goto P_0c097fcc;
case 0x0c097fceu: goto P_0c097fce;
case 0x0c097fd0u: goto P_0c097fd0;
case 0x0c097fd2u: goto P_0c097fd2;
case 0x0c097fd4u: goto P_0c097fd4;
case 0x0c097fd6u: goto P_0c097fd6;
case 0x0c097fd8u: goto P_0c097fd8;
case 0x0c097fdau: goto P_0c097fda;
case 0x0c097fdcu: goto P_0c097fdc;
case 0x0c097fdeu: goto P_0c097fde;
case 0x0c097fe0u: goto P_0c097fe0;
case 0x0c097fe2u: goto P_0c097fe2;
case 0x0c097fe4u: goto P_0c097fe4;
case 0x0c097fe6u: goto P_0c097fe6;
case 0x0c097fe8u: goto P_0c097fe8;
case 0x0c097feau: goto P_0c097fea;
case 0x0c097fecu: goto P_0c097fec;
case 0x0c097feeu: goto P_0c097fee;
case 0x0c097ff0u: goto P_0c097ff0;
case 0x0c097ff2u: goto P_0c097ff2;
case 0x0c099d62u: goto P_0c099d62;
case 0x0c099d64u: goto P_0c099d64;
case 0x0c099d66u: goto P_0c099d66;
case 0x0c099d68u: goto P_0c099d68;
case 0x0c099d6au: goto P_0c099d6a;
case 0x0c099d6cu: goto P_0c099d6c;
case 0x0c099d6eu: goto P_0c099d6e;
case 0x0c099d70u: goto P_0c099d70;
case 0x0c099d72u: goto P_0c099d72;
case 0x0c099d74u: goto P_0c099d74;
case 0x0c099d76u: goto P_0c099d76;
case 0x0c099d78u: goto P_0c099d78;
case 0x0c099d7au: goto P_0c099d7a;
case 0x0c099d7cu: goto P_0c099d7c;
case 0x0c099d7eu: goto P_0c099d7e;
case 0x0c099d80u: goto P_0c099d80;
case 0x0c099d82u: goto P_0c099d82;
case 0x0c099d84u: goto P_0c099d84;
case 0x0c099d86u: goto P_0c099d86;
case 0x0c099d88u: goto P_0c099d88;
case 0x0c099d8au: goto P_0c099d8a;
case 0x0c099d8cu: goto P_0c099d8c;
case 0x0c099d8eu: goto P_0c099d8e;
case 0x0c099d90u: goto P_0c099d90;
case 0x0c099d92u: goto P_0c099d92;
case 0x0c099d94u: goto P_0c099d94;
case 0x0c099d96u: goto P_0c099d96;
case 0x0c099d98u: goto P_0c099d98;
case 0x0c099d9au: goto P_0c099d9a;
case 0x0c099d9cu: goto P_0c099d9c;
case 0x0c099d9eu: goto P_0c099d9e;
case 0x0c099de0u: goto P_0c099de0;
case 0x0c099de2u: goto P_0c099de2;
case 0x0c099de4u: goto P_0c099de4;
case 0x0c099de6u: goto P_0c099de6;
case 0x0c099de8u: goto P_0c099de8;
case 0x0c099deau: goto P_0c099dea;
case 0x0c099decu: goto P_0c099dec;
case 0x0c099deeu: goto P_0c099dee;
case 0x0c099df0u: goto P_0c099df0;
case 0x0c099df2u: goto P_0c099df2;
case 0x0c099df4u: goto P_0c099df4;
case 0x0c099df6u: goto P_0c099df6;
case 0x0c099df8u: goto P_0c099df8;
case 0x0c099dfau: goto P_0c099dfa;
case 0x0c099dfcu: goto P_0c099dfc;
case 0x0c099dfeu: goto P_0c099dfe;
case 0x0c099e00u: goto P_0c099e00;
case 0x0c099e02u: goto P_0c099e02;
case 0x0c099e04u: goto P_0c099e04;
case 0x0c099e06u: goto P_0c099e06;
case 0x0c099e08u: goto P_0c099e08;
case 0x0c099e0au: goto P_0c099e0a;
case 0x0c099e0cu: goto P_0c099e0c;
case 0x0c099e0eu: goto P_0c099e0e;
case 0x0c099e10u: goto P_0c099e10;
case 0x0c099e12u: goto P_0c099e12;
case 0x0c099e14u: goto P_0c099e14;
case 0x0c099e16u: goto P_0c099e16;
case 0x0c099e18u: goto P_0c099e18;
case 0x0c099e1au: goto P_0c099e1a;
case 0x0c099e1cu: goto P_0c099e1c;
case 0x0c099e1eu: goto P_0c099e1e;
case 0x0c099e20u: goto P_0c099e20;
case 0x0c099e22u: goto P_0c099e22;
case 0x0c099e24u: goto P_0c099e24;
case 0x0c099e26u: goto P_0c099e26;
case 0x0c099e28u: goto P_0c099e28;
case 0x0c099e2au: goto P_0c099e2a;
case 0x0c099e2cu: goto P_0c099e2c;
case 0x0c099e2eu: goto P_0c099e2e;
case 0x0c099e30u: goto P_0c099e30;
case 0x0c099e32u: goto P_0c099e32;
case 0x0c099e34u: goto P_0c099e34;
case 0x0c099e36u: goto P_0c099e36;
case 0x0c099e38u: goto P_0c099e38;
case 0x0c099e3au: goto P_0c099e3a;
case 0x0c099e3cu: goto P_0c099e3c;
case 0x0c099e3eu: goto P_0c099e3e;
case 0x0c099e40u: goto P_0c099e40;
case 0x0c099e42u: goto P_0c099e42;
case 0x0c099e44u: goto P_0c099e44;
case 0x0c099e46u: goto P_0c099e46;
case 0x0c099e48u: goto P_0c099e48;
case 0x0c099e4au: goto P_0c099e4a;
case 0x0c099e4cu: goto P_0c099e4c;
case 0x0c099e4eu: goto P_0c099e4e;
case 0x0c099e50u: goto P_0c099e50;
case 0x0c099e52u: goto P_0c099e52;
case 0x0c099e54u: goto P_0c099e54;
case 0x0c099e56u: goto P_0c099e56;
case 0x0c099e58u: goto P_0c099e58;
case 0x0c099e5au: goto P_0c099e5a;
case 0x0c099e5cu: goto P_0c099e5c;
case 0x0c099e5eu: goto P_0c099e5e;
case 0x0c099e60u: goto P_0c099e60;
case 0x0c099e62u: goto P_0c099e62;
case 0x0c099e64u: goto P_0c099e64;
case 0x0c099e66u: goto P_0c099e66;
case 0x0c099e68u: goto P_0c099e68;
case 0x0c099e6au: goto P_0c099e6a;
case 0x0c099e6cu: goto P_0c099e6c;
case 0x0c099e6eu: goto P_0c099e6e;
case 0x0c099e70u: goto P_0c099e70;
case 0x0c099e72u: goto P_0c099e72;
case 0x0c099e74u: goto P_0c099e74;
case 0x0c099e76u: goto P_0c099e76;
case 0x0c099e78u: goto P_0c099e78;
case 0x0c099e7au: goto P_0c099e7a;
case 0x0c099e7cu: goto P_0c099e7c;
case 0x0c099e7eu: goto P_0c099e7e;
case 0x0c099e80u: goto P_0c099e80;
case 0x0c099e82u: goto P_0c099e82;
case 0x0c099e84u: goto P_0c099e84;
case 0x0c099e86u: goto P_0c099e86;
case 0x0c099e88u: goto P_0c099e88;
case 0x0c099e8au: goto P_0c099e8a;
case 0x0c099e8cu: goto P_0c099e8c;
case 0x0c099e8eu: goto P_0c099e8e;
case 0x0c099e90u: goto P_0c099e90;
case 0x0c099e92u: goto P_0c099e92;
case 0x0c099e94u: goto P_0c099e94;
case 0x0c099e96u: goto P_0c099e96;
case 0x0c099e98u: goto P_0c099e98;
case 0x0c099e9au: goto P_0c099e9a;
case 0x0c099e9cu: goto P_0c099e9c;
case 0x0c099e9eu: goto P_0c099e9e;
case 0x0c099ea0u: goto P_0c099ea0;
case 0x0c099ea2u: goto P_0c099ea2;
case 0x0c099ea4u: goto P_0c099ea4;
case 0x0c099ea6u: goto P_0c099ea6;
case 0x0c099ea8u: goto P_0c099ea8;
case 0x0c099eaau: goto P_0c099eaa;
case 0x0c099eacu: goto P_0c099eac;
case 0x0c099eaeu: goto P_0c099eae;
case 0x0c099eb0u: goto P_0c099eb0;
case 0x0c099eb2u: goto P_0c099eb2;
case 0x0c099eb4u: goto P_0c099eb4;
case 0x0c099eb6u: goto P_0c099eb6;
case 0x0c099eb8u: goto P_0c099eb8;
case 0x0c099ebau: goto P_0c099eba;
case 0x0c099ebcu: goto P_0c099ebc;
case 0x0c099ebeu: goto P_0c099ebe;
case 0x0c099ec0u: goto P_0c099ec0;
case 0x0c099ec2u: goto P_0c099ec2;
case 0x0c099ec4u: goto P_0c099ec4;
case 0x0c099ec6u: goto P_0c099ec6;
case 0x0c099ec8u: goto P_0c099ec8;
case 0x0c099ecau: goto P_0c099eca;
case 0x0c099eccu: goto P_0c099ecc;
case 0x0c099eceu: goto P_0c099ece;
case 0x0c099ed0u: goto P_0c099ed0;
case 0x0c099ed2u: goto P_0c099ed2;
case 0x0c099ed4u: goto P_0c099ed4;
case 0x0c099ed6u: goto P_0c099ed6;
case 0x0c099f00u: goto P_0c099f00;
case 0x0c099f02u: goto P_0c099f02;
case 0x0c099f04u: goto P_0c099f04;
case 0x0c099f06u: goto P_0c099f06;
case 0x0c099f08u: goto P_0c099f08;
case 0x0c099f0au: goto P_0c099f0a;
case 0x0c099f0cu: goto P_0c099f0c;
case 0x0c099f0eu: goto P_0c099f0e;
case 0x0c099f10u: goto P_0c099f10;
case 0x0c099f12u: goto P_0c099f12;
case 0x0c099f14u: goto P_0c099f14;
case 0x0c099f16u: goto P_0c099f16;
case 0x0c099f18u: goto P_0c099f18;
case 0x0c099f1au: goto P_0c099f1a;
case 0x0c099f1cu: goto P_0c099f1c;
case 0x0c099f1eu: goto P_0c099f1e;
case 0x0c099f20u: goto P_0c099f20;
case 0x0c099f22u: goto P_0c099f22;
case 0x0c099f24u: goto P_0c099f24;
case 0x0c099f26u: goto P_0c099f26;
case 0x0c099f28u: goto P_0c099f28;
case 0x0c099f2au: goto P_0c099f2a;
case 0x0c099f2cu: goto P_0c099f2c;
case 0x0c099f2eu: goto P_0c099f2e;
case 0x0c099f30u: goto P_0c099f30;
case 0x0c099f32u: goto P_0c099f32;
case 0x0c099f34u: goto P_0c099f34;
case 0x0c099f36u: goto P_0c099f36;
case 0x0c099f38u: goto P_0c099f38;
case 0x0c099f3au: goto P_0c099f3a;
case 0x0c099f3cu: goto P_0c099f3c;
case 0x0c099f3eu: goto P_0c099f3e;
case 0x0c099f40u: goto P_0c099f40;
case 0x0c099f42u: goto P_0c099f42;
case 0x0c099f44u: goto P_0c099f44;
case 0x0c099f46u: goto P_0c099f46;
case 0x0c099f48u: goto P_0c099f48;
case 0x0c099f4au: goto P_0c099f4a;
case 0x0c099f4cu: goto P_0c099f4c;
case 0x0c099f4eu: goto P_0c099f4e;
case 0x0c099f50u: goto P_0c099f50;
case 0x0c099f52u: goto P_0c099f52;
case 0x0c099f54u: goto P_0c099f54;
case 0x0c099f56u: goto P_0c099f56;
case 0x0c099f58u: goto P_0c099f58;
case 0x0c099f5au: goto P_0c099f5a;
case 0x0c099f5cu: goto P_0c099f5c;
case 0x0c099f5eu: goto P_0c099f5e;
case 0x0c099f60u: goto P_0c099f60;
case 0x0c099f62u: goto P_0c099f62;
case 0x0c099f64u: goto P_0c099f64;
case 0x0c099f66u: goto P_0c099f66;
case 0x0c099f68u: goto P_0c099f68;
case 0x0c099f6au: goto P_0c099f6a;
case 0x0c099f6cu: goto P_0c099f6c;
case 0x0c099f6eu: goto P_0c099f6e;
case 0x0c099f70u: goto P_0c099f70;
case 0x0c099f72u: goto P_0c099f72;
case 0x0c099f74u: goto P_0c099f74;
case 0x0c099f76u: goto P_0c099f76;
case 0x0c099f78u: goto P_0c099f78;
case 0x0c099f7au: goto P_0c099f7a;
case 0x0c099f7cu: goto P_0c099f7c;
case 0x0c099f7eu: goto P_0c099f7e;
case 0x0c099f80u: goto P_0c099f80;
case 0x0c099f82u: goto P_0c099f82;
case 0x0c099f84u: goto P_0c099f84;
case 0x0c099f86u: goto P_0c099f86;
case 0x0c099f88u: goto P_0c099f88;
case 0x0c099f8au: goto P_0c099f8a;
case 0x0c099f8cu: goto P_0c099f8c;
case 0x0c099f8eu: goto P_0c099f8e;
case 0x0c099f90u: goto P_0c099f90;
case 0x0c099f92u: goto P_0c099f92;
case 0x0c099f94u: goto P_0c099f94;
case 0x0c099f96u: goto P_0c099f96;
case 0x0c099f98u: goto P_0c099f98;
case 0x0c099f9au: goto P_0c099f9a;
case 0x0c099f9cu: goto P_0c099f9c;
case 0x0c099f9eu: goto P_0c099f9e;
case 0x0c099fa0u: goto P_0c099fa0;
case 0x0c099fa2u: goto P_0c099fa2;
case 0x0c099fa4u: goto P_0c099fa4;
case 0x0c099fa6u: goto P_0c099fa6;
case 0x0c099fa8u: goto P_0c099fa8;
case 0x0c099faau: goto P_0c099faa;
case 0x0c099facu: goto P_0c099fac;
case 0x0c099faeu: goto P_0c099fae;
case 0x0c099fb0u: goto P_0c099fb0;
case 0x0c099fb2u: goto P_0c099fb2;
case 0x0c099fb4u: goto P_0c099fb4;
case 0x0c099fb6u: goto P_0c099fb6;
case 0x0c099fb8u: goto P_0c099fb8;
case 0x0c099fbau: goto P_0c099fba;
case 0x0c099fbcu: goto P_0c099fbc;
case 0x0c099fbeu: goto P_0c099fbe;
case 0x0c099fc0u: goto P_0c099fc0;
case 0x0c099fc2u: goto P_0c099fc2;
case 0x0c099fc4u: goto P_0c099fc4;
case 0x0c099fc6u: goto P_0c099fc6;
case 0x0c099fc8u: goto P_0c099fc8;
case 0x0c099fcau: goto P_0c099fca;
case 0x0c099fccu: goto P_0c099fcc;
case 0x0c099fceu: goto P_0c099fce;
case 0x0c099fd0u: goto P_0c099fd0;
case 0x0c099fd2u: goto P_0c099fd2;
case 0x0c099fd4u: goto P_0c099fd4;
case 0x0c099fd6u: goto P_0c099fd6;
case 0x0c099fd8u: goto P_0c099fd8;
case 0x0c099fdau: goto P_0c099fda;
case 0x0c099fdcu: goto P_0c099fdc;
case 0x0c099fdeu: goto P_0c099fde;
case 0x0c099fe0u: goto P_0c099fe0;
case 0x0c099fe2u: goto P_0c099fe2;
case 0x0c099fe4u: goto P_0c099fe4;
case 0x0c099fe6u: goto P_0c099fe6;
case 0x0c099fe8u: goto P_0c099fe8;
case 0x0c099feau: goto P_0c099fea;
case 0x0c099fecu: goto P_0c099fec;
case 0x0c099feeu: goto P_0c099fee;
case 0x0c099ff0u: goto P_0c099ff0;
case 0x0c099ff2u: goto P_0c099ff2;
case 0x0c099ff4u: goto P_0c099ff4;
case 0x0c099ff6u: goto P_0c099ff6;
case 0x0c099ff8u: goto P_0c099ff8;
case 0x0c09a01cu: goto P_0c09a01c;
case 0x0c09a01eu: goto P_0c09a01e;
case 0x0c09a020u: goto P_0c09a020;
case 0x0c09a022u: goto P_0c09a022;
case 0x0c09a024u: goto P_0c09a024;
case 0x0c09a026u: goto P_0c09a026;
case 0x0c09a028u: goto P_0c09a028;
case 0x0c09a02au: goto P_0c09a02a;
case 0x0c09a02cu: goto P_0c09a02c;
case 0x0c09a02eu: goto P_0c09a02e;
case 0x0c09a030u: goto P_0c09a030;
case 0x0c09a032u: goto P_0c09a032;
case 0x0c09a034u: goto P_0c09a034;
case 0x0c09a036u: goto P_0c09a036;
case 0x0c09a038u: goto P_0c09a038;
case 0x0c09a03au: goto P_0c09a03a;
case 0x0c09a03cu: goto P_0c09a03c;
case 0x0c09a03eu: goto P_0c09a03e;
case 0x0c09a040u: goto P_0c09a040;
case 0x0c09a042u: goto P_0c09a042;
case 0x0c09a044u: goto P_0c09a044;
case 0x0c09a046u: goto P_0c09a046;
case 0x0c09a048u: goto P_0c09a048;
case 0x0c09a04au: goto P_0c09a04a;
case 0x0c09a04cu: goto P_0c09a04c;
case 0x0c09a04eu: goto P_0c09a04e;
case 0x0c09a050u: goto P_0c09a050;
case 0x0c09a052u: goto P_0c09a052;
case 0x0c09a054u: goto P_0c09a054;
case 0x0c09a056u: goto P_0c09a056;
case 0x0c09a058u: goto P_0c09a058;
case 0x0c09a05au: goto P_0c09a05a;
case 0x0c09a05cu: goto P_0c09a05c;
case 0x0c09a05eu: goto P_0c09a05e;
case 0x0c09a060u: goto P_0c09a060;
case 0x0c09a062u: goto P_0c09a062;
case 0x0c09a064u: goto P_0c09a064;
case 0x0c09a066u: goto P_0c09a066;
case 0x0c09a068u: goto P_0c09a068;
case 0x0c09a06au: goto P_0c09a06a;
case 0x0c09a06cu: goto P_0c09a06c;
case 0x0c09a06eu: goto P_0c09a06e;
case 0x0c09a070u: goto P_0c09a070;
case 0x0c09a072u: goto P_0c09a072;
case 0x0c09a074u: goto P_0c09a074;
case 0x0c09a076u: goto P_0c09a076;
case 0x0c09a078u: goto P_0c09a078;
case 0x0c09a07au: goto P_0c09a07a;
case 0x0c09a07cu: goto P_0c09a07c;
case 0x0c09a07eu: goto P_0c09a07e;
case 0x0c09a080u: goto P_0c09a080;
case 0x0c09a082u: goto P_0c09a082;
case 0x0c09a084u: goto P_0c09a084;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07d88a: /* original 2fe6, guest PC 0x0c07d88a */
if(!s->budget--) { s->failed_pc=0x0c07d88au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07d88c;
P_0c07d88c: /* original 2fd6, guest PC 0x0c07d88c */
if(!s->budget--) { s->failed_pc=0x0c07d88cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07d88e;
P_0c07d88e: /* original 2fc6, guest PC 0x0c07d88e */
if(!s->budget--) { s->failed_pc=0x0c07d88eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07d890;
P_0c07d890: /* original 4f22, guest PC 0x0c07d890 */
if(!s->budget--) { s->failed_pc=0x0c07d890u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07d892;
P_0c07d892: /* original 7ff8, guest PC 0x0c07d892 */
if(!s->budget--) { s->failed_pc=0x0c07d892u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c07d894;
P_0c07d894: /* original 2f42, guest PC 0x0c07d894 */
if(!s->budget--) { s->failed_pc=0x0c07d894u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07d896;
P_0c07d896: /* original dd1d, guest PC 0x0c07d896 */
if(!s->budget--) { s->failed_pc=0x0c07d896u; return 0; }
r[13]=read(ram,0x0c07d90cu,4);
goto P_0c07d898;
P_0c07d898: /* original d326, guest PC 0x0c07d898 */
if(!s->budget--) { s->failed_pc=0x0c07d898u; return 0; }
r[3]=read(ram,0x0c07d934u,4);
goto P_0c07d89a;
P_0c07d89a: /* original 430b, guest PC 0x0c07d89a */
if(!s->budget--) { s->failed_pc=0x0c07d89au; return 0; }
target=r[3];
r[16]=code_base|0x0c07d89eu;
write(ram,r[15]+4,r[5],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07d89eu) { target=s->pc; goto dispatch; }
goto P_0c07d89e;
P_0c07d89c: /* original 1f51, guest PC 0x0c07d89c */
if(!s->budget--) { s->failed_pc=0x0c07d89cu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c07d89e;
P_0c07d89e: /* original d226, guest PC 0x0c07d89e */
if(!s->budget--) { s->failed_pc=0x0c07d89eu; return 0; }
r[2]=read(ram,0x0c07d938u,4);
goto P_0c07d8a0;
P_0c07d8a0: /* original 6422, guest PC 0x0c07d8a0 */
if(!s->budget--) { s->failed_pc=0x0c07d8a0u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c07d8a2;
P_0c07d8a2: /* original 4415, guest PC 0x0c07d8a2 */
if(!s->budget--) { s->failed_pc=0x0c07d8a2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c07d8a4;
P_0c07d8a4: /* original 8b1a, guest PC 0x0c07d8a4 */
if(!s->budget--) { s->failed_pc=0x0c07d8a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07d8dc; }
goto P_0c07d8a6;
P_0c07d8a6: /* original d225, guest PC 0x0c07d8a6 */
if(!s->budget--) { s->failed_pc=0x0c07d8a6u; return 0; }
r[2]=read(ram,0x0c07d93cu,4);
goto P_0c07d8a8;
P_0c07d8a8: /* original e3fa, guest PC 0x0c07d8a8 */
if(!s->budget--) { s->failed_pc=0x0c07d8a8u; return 0; }
r[3]=0xfffffffau;
goto P_0c07d8aa;
P_0c07d8aa: /* original 6e43, guest PC 0x0c07d8aa */
if(!s->budget--) { s->failed_pc=0x0c07d8aau; return 0; }
r[14]=r[4];
goto P_0c07d8ac;
P_0c07d8ac: /* original e00a, guest PC 0x0c07d8ac */
if(!s->budget--) { s->failed_pc=0x0c07d8acu; return 0; }
r[0]=0x0000000au;
goto P_0c07d8ae;
P_0c07d8ae: /* original 4e3c, guest PC 0x0c07d8ae */
if(!s->budget--) { s->failed_pc=0x0c07d8aeu; return 0; }
r[14]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[14]>>((-r[3])&31u)):((int32_t)r[14]<0?0xffffffffu:0)):r[14]<<(r[3]&31u);
goto P_0c07d8b0;
P_0c07d8b0: /* original 420b, guest PC 0x0c07d8b0 */
if(!s->budget--) { s->failed_pc=0x0c07d8b0u; return 0; }
target=r[2];
r[16]=code_base|0x0c07d8b4u;
r[1]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07d8b4u) { target=s->pc; goto dispatch; }
goto P_0c07d8b4;
P_0c07d8b2: /* original 61e3, guest PC 0x0c07d8b2 */
if(!s->budget--) { s->failed_pc=0x0c07d8b2u; return 0; }
r[1]=r[14];
goto P_0c07d8b4;
P_0c07d8b4: /* original 6403, guest PC 0x0c07d8b4 */
if(!s->budget--) { s->failed_pc=0x0c07d8b4u; return 0; }
r[4]=r[0];
goto P_0c07d8b6;
P_0c07d8b6: /* original 4408, guest PC 0x0c07d8b6 */
if(!s->budget--) { s->failed_pc=0x0c07d8b6u; return 0; }
r[4]<<=2;
goto P_0c07d8b8;
P_0c07d8b8: /* original 6303, guest PC 0x0c07d8b8 */
if(!s->budget--) { s->failed_pc=0x0c07d8b8u; return 0; }
r[3]=r[0];
goto P_0c07d8ba;
P_0c07d8ba: /* original 343c, guest PC 0x0c07d8ba */
if(!s->budget--) { s->failed_pc=0x0c07d8bau; return 0; }
r[4]+=r[3];
goto P_0c07d8bc;
P_0c07d8bc: /* original 951e, guest PC 0x0c07d8bc */
if(!s->budget--) { s->failed_pc=0x0c07d8bcu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07d8fcu,2);
goto P_0c07d8be;
P_0c07d8be: /* original 4400, guest PC 0x0c07d8be */
if(!s->budget--) { s->failed_pc=0x0c07d8beu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07d8c0;
P_0c07d8c0: /* original 971d, guest PC 0x0c07d8c0 */
if(!s->budget--) { s->failed_pc=0x0c07d8c0u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07d8feu,2);
goto P_0c07d8c2;
P_0c07d8c2: /* original 6c03, guest PC 0x0c07d8c2 */
if(!s->budget--) { s->failed_pc=0x0c07d8c2u; return 0; }
r[12]=r[0];
goto P_0c07d8c4;
P_0c07d8c4: /* original d21e, guest PC 0x0c07d8c4 */
if(!s->budget--) { s->failed_pc=0x0c07d8c4u; return 0; }
r[2]=read(ram,0x0c07d940u,4);
goto P_0c07d8c6;
P_0c07d8c6: /* original 6603, guest PC 0x0c07d8c6 */
if(!s->budget--) { s->failed_pc=0x0c07d8c6u; return 0; }
r[6]=r[0];
goto P_0c07d8c8;
P_0c07d8c8: /* original 3e48, guest PC 0x0c07d8c8 */
if(!s->budget--) { s->failed_pc=0x0c07d8c8u; return 0; }
r[14]-=r[4];
goto P_0c07d8ca;
P_0c07d8ca: /* original 420b, guest PC 0x0c07d8ca */
if(!s->budget--) { s->failed_pc=0x0c07d8cau; return 0; }
target=r[2];
r[16]=code_base|0x0c07d8ceu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07d8ceu) { target=s->pc; goto dispatch; }
goto P_0c07d8ce;
P_0c07d8cc: /* original 64d3, guest PC 0x0c07d8cc */
if(!s->budget--) { s->failed_pc=0x0c07d8ccu; return 0; }
r[4]=r[13];
goto P_0c07d8ce;
P_0c07d8ce: /* original d31c, guest PC 0x0c07d8ce */
if(!s->budget--) { s->failed_pc=0x0c07d8ceu; return 0; }
r[3]=read(ram,0x0c07d940u,4);
goto P_0c07d8d0;
P_0c07d8d0: /* original 66e3, guest PC 0x0c07d8d0 */
if(!s->budget--) { s->failed_pc=0x0c07d8d0u; return 0; }
r[6]=r[14];
goto P_0c07d8d2;
P_0c07d8d2: /* original 9714, guest PC 0x0c07d8d2 */
if(!s->budget--) { s->failed_pc=0x0c07d8d2u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07d8feu,2);
goto P_0c07d8d4;
P_0c07d8d4: /* original 9514, guest PC 0x0c07d8d4 */
if(!s->budget--) { s->failed_pc=0x0c07d8d4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07d900u,2);
goto P_0c07d8d6;
P_0c07d8d6: /* original 430b, guest PC 0x0c07d8d6 */
if(!s->budget--) { s->failed_pc=0x0c07d8d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c07d8dau;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07d8dau) { target=s->pc; goto dispatch; }
goto P_0c07d8da;
P_0c07d8d8: /* original 64d3, guest PC 0x0c07d8d8 */
if(!s->budget--) { s->failed_pc=0x0c07d8d8u; return 0; }
r[4]=r[13];
goto P_0c07d8da;
P_0c07d8da: /* original 1f01, guest PC 0x0c07d8da */
if(!s->budget--) { s->failed_pc=0x0c07d8dau; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c07d8dc;
P_0c07d8dc: /* original 64f2, guest PC 0x0c07d8dc */
if(!s->budget--) { s->failed_pc=0x0c07d8dcu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07d8de;
P_0c07d8de: /* original 55f1, guest PC 0x0c07d8de */
if(!s->budget--) { s->failed_pc=0x0c07d8deu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c07d8e0;
P_0c07d8e0: /* original 7f08, guest PC 0x0c07d8e0 */
if(!s->budget--) { s->failed_pc=0x0c07d8e0u; return 0; }
r[15]+=0x00000008u;
goto P_0c07d8e2;
P_0c07d8e2: /* original 4f26, guest PC 0x0c07d8e2 */
if(!s->budget--) { s->failed_pc=0x0c07d8e2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07d8e4;
P_0c07d8e4: /* original d317, guest PC 0x0c07d8e4 */
if(!s->budget--) { s->failed_pc=0x0c07d8e4u; return 0; }
r[3]=read(ram,0x0c07d944u,4);
goto P_0c07d8e6;
P_0c07d8e6: /* original 6cf6, guest PC 0x0c07d8e6 */
if(!s->budget--) { s->failed_pc=0x0c07d8e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07d8e8;
P_0c07d8e8: /* original 6df6, guest PC 0x0c07d8e8 */
if(!s->budget--) { s->failed_pc=0x0c07d8e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07d8ea;
P_0c07d8ea: /* original 432b, guest PC 0x0c07d8ea */
if(!s->budget--) { s->failed_pc=0x0c07d8eau; return 0; }
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
P_0c07d8ec: /* original 6ef6, guest PC 0x0c07d8ec */
if(!s->budget--) { s->failed_pc=0x0c07d8ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07d8eeu,s,ram);
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082332u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08233eu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082354u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08238eu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082398u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08239eu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823a4u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823aau) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823b0u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823b6u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823bcu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823c2u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823c8u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823ceu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823d4u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823dau) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823e0u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823e6u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823ecu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823f2u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823f8u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0823feu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082404u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08240au) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082410u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082416u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08241cu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082422u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082428u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08242eu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082434u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08243au) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082440u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082446u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08244cu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082452u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082458u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08245eu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082464u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c08246au,s,ram);
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0824e2u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c082532u,s,ram);
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0825beu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0825deu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0825ecu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082604u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082628u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08266cu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08267eu) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c082682u,s,ram);
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
return vf3_matrix_family(0x0c0826b0u,s,ram);
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082722u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08274eu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08275eu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08276eu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082786u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0827aau) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0827eeu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082800u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c082804u,s,ram);
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082840u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c08285cu,s,ram);
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08289au) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0828e0u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0828fau) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08290au) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08291cu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08292cu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082938u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082960u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082984u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c082994u,s,ram);
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0829e2u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0829f2u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082a0cu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082a28u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082a3au) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082a4cu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082a68u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082a7cu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082aa2u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082ac8u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c082aecu,s,ram);
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c082b78u) { target=s->pc; goto dispatch; }
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
P_0c082ba0: /* original 6ef6, guest PC 0x0c082ba0 */
if(!s->budget--) { s->failed_pc=0x0c082ba0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c082ba2u,s,ram);
P_0c0831ea: /* original 2fe6, guest PC 0x0c0831ea */
if(!s->budget--) { s->failed_pc=0x0c0831eau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0831ec;
P_0c0831ec: /* original 2fd6, guest PC 0x0c0831ec */
if(!s->budget--) { s->failed_pc=0x0c0831ecu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0831ee;
P_0c0831ee: /* original 2fc6, guest PC 0x0c0831ee */
if(!s->budget--) { s->failed_pc=0x0c0831eeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0831f0;
P_0c0831f0: /* original 2fb6, guest PC 0x0c0831f0 */
if(!s->budget--) { s->failed_pc=0x0c0831f0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0831f2;
P_0c0831f2: /* original 2fa6, guest PC 0x0c0831f2 */
if(!s->budget--) { s->failed_pc=0x0c0831f2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0831f4;
P_0c0831f4: /* original 2f96, guest PC 0x0c0831f4 */
if(!s->budget--) { s->failed_pc=0x0c0831f4u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0831f6;
P_0c0831f6: /* original 2f86, guest PC 0x0c0831f6 */
if(!s->budget--) { s->failed_pc=0x0c0831f6u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0831f8;
P_0c0831f8: /* original 4f22, guest PC 0x0c0831f8 */
if(!s->budget--) { s->failed_pc=0x0c0831f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0831fa;
P_0c0831fa: /* original 9b2b, guest PC 0x0c0831fa */
if(!s->budget--) { s->failed_pc=0x0c0831fau; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083254u,2);
goto P_0c0831fc;
P_0c0831fc: /* original 7fec, guest PC 0x0c0831fc */
if(!s->budget--) { s->failed_pc=0x0c0831fcu; return 0; }
r[15]+=0xffffffecu;
goto P_0c0831fe;
P_0c0831fe: /* original 1f43, guest PC 0x0c0831fe */
if(!s->budget--) { s->failed_pc=0x0c0831feu; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c083200;
P_0c083200: /* original 1f54, guest PC 0x0c083200 */
if(!s->budget--) { s->failed_pc=0x0c083200u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c083202;
P_0c083202: /* original dd1a, guest PC 0x0c083202 */
if(!s->budget--) { s->failed_pc=0x0c083202u; return 0; }
r[13]=read(ram,0x0c08326cu,4);
goto P_0c083204;
P_0c083204: /* original de18, guest PC 0x0c083204 */
if(!s->budget--) { s->failed_pc=0x0c083204u; return 0; }
r[14]=read(ram,0x0c083268u,4);
goto P_0c083206;
P_0c083206: /* original d31a, guest PC 0x0c083206 */
if(!s->budget--) { s->failed_pc=0x0c083206u; return 0; }
r[3]=read(ram,0x0c083270u,4);
goto P_0c083208;
P_0c083208: /* original 430b, guest PC 0x0c083208 */
if(!s->budget--) { s->failed_pc=0x0c083208u; return 0; }
target=r[3];
r[16]=code_base|0x0c08320cu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08320cu) { target=s->pc; goto dispatch; }
goto P_0c08320c;
P_0c08320a: /* original 64d3, guest PC 0x0c08320a */
if(!s->budget--) { s->failed_pc=0x0c08320au; return 0; }
r[4]=r[13];
goto P_0c08320c;
P_0c08320c: /* original d213, guest PC 0x0c08320c */
if(!s->budget--) { s->failed_pc=0x0c08320cu; return 0; }
r[2]=read(ram,0x0c08325cu,4);
goto P_0c08320e;
P_0c08320e: /* original e502, guest PC 0x0c08320e */
if(!s->budget--) { s->failed_pc=0x0c08320eu; return 0; }
r[5]=0x00000002u;
goto P_0c083210;
P_0c083210: /* original 9621, guest PC 0x0c083210 */
if(!s->budget--) { s->failed_pc=0x0c083210u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083256u,2);
goto P_0c083212;
P_0c083212: /* original 420b, guest PC 0x0c083212 */
if(!s->budget--) { s->failed_pc=0x0c083212u; return 0; }
target=r[2];
r[16]=code_base|0x0c083216u;
r[4]=0x00000016u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083216u) { target=s->pc; goto dispatch; }
goto P_0c083216;
P_0c083214: /* original e416, guest PC 0x0c083214 */
if(!s->budget--) { s->failed_pc=0x0c083214u; return 0; }
r[4]=0x00000016u;
goto P_0c083216;
P_0c083216: /* original a42d, guest PC 0x0c083216 */
if(!s->budget--) { s->failed_pc=0x0c083216u; return 0; }
r[10]=0x00000000u;
goto P_0c083a74;
P_0c083218: /* original ea00, guest PC 0x0c083218 */
if(!s->budget--) { s->failed_pc=0x0c083218u; return 0; }
r[10]=0x00000000u;
goto P_0c08321a;
P_0c08321a: /* original dc16, guest PC 0x0c08321a */
if(!s->budget--) { s->failed_pc=0x0c08321au; return 0; }
r[12]=read(ram,0x0c083274u,4);
goto P_0c08321c;
P_0c08321c: /* original 4c0b, guest PC 0x0c08321c */
if(!s->budget--) { s->failed_pc=0x0c08321cu; return 0; }
target=r[12];
r[16]=code_base|0x0c083220u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083220u) { target=s->pc; goto dispatch; }
goto P_0c083220;
P_0c08321e: /* original 64a3, guest PC 0x0c08321e */
if(!s->budget--) { s->failed_pc=0x0c08321eu; return 0; }
r[4]=r[10];
goto P_0c083220;
P_0c083220: /* original 68a3, guest PC 0x0c083220 */
if(!s->budget--) { s->failed_pc=0x0c083220u; return 0; }
r[8]=r[10];
goto P_0c083222;
P_0c083222: /* original 4808, guest PC 0x0c083222 */
if(!s->budget--) { s->failed_pc=0x0c083222u; return 0; }
r[8]<<=2;
goto P_0c083224;
P_0c083224: /* original 63a3, guest PC 0x0c083224 */
if(!s->budget--) { s->failed_pc=0x0c083224u; return 0; }
r[3]=r[10];
goto P_0c083226;
P_0c083226: /* original 383c, guest PC 0x0c083226 */
if(!s->budget--) { s->failed_pc=0x0c083226u; return 0; }
r[8]+=r[3];
goto P_0c083228;
P_0c083228: /* original 6903, guest PC 0x0c083228 */
if(!s->budget--) { s->failed_pc=0x0c083228u; return 0; }
r[9]=r[0];
goto P_0c08322a;
P_0c08322a: /* original 6392, guest PC 0x0c08322a */
if(!s->budget--) { s->failed_pc=0x0c08322au; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c08322c;
P_0c08322c: /* original d212, guest PC 0x0c08322c */
if(!s->budget--) { s->failed_pc=0x0c08322cu; return 0; }
r[2]=read(ram,0x0c083278u,4);
goto P_0c08322e;
P_0c08322e: /* original 4808, guest PC 0x0c08322e */
if(!s->budget--) { s->failed_pc=0x0c08322eu; return 0; }
r[8]<<=2;
goto P_0c083230;
P_0c083230: /* original 6c83, guest PC 0x0c083230 */
if(!s->budget--) { s->failed_pc=0x0c083230u; return 0; }
r[12]=r[8];
goto P_0c083232;
P_0c083232: /* original 3320, guest PC 0x0c083232 */
if(!s->budget--) { s->failed_pc=0x0c083232u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c083234;
P_0c083234: /* original 8f22, guest PC 0x0c083234 */
if(!s->budget--) { s->failed_pc=0x0c083234u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000007u;
if(!cond) { goto P_0c08327c; }
goto P_0c083238;
P_0c083236: /* original 7c07, guest PC 0x0c083236 */
if(!s->budget--) { s->failed_pc=0x0c083236u; return 0; }
r[12]+=0x00000007u;
goto P_0c083238;
P_0c083238: /* original d308, guest PC 0x0c083238 */
if(!s->budget--) { s->failed_pc=0x0c083238u; return 0; }
r[3]=read(ram,0x0c08325cu,4);
goto P_0c08323a;
P_0c08323a: /* original 65c3, guest PC 0x0c08323a */
if(!s->budget--) { s->failed_pc=0x0c08323au; return 0; }
r[5]=r[12];
goto P_0c08323c;
P_0c08323c: /* original 960c, guest PC 0x0c08323c */
if(!s->budget--) { s->failed_pc=0x0c08323cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083258u,2);
goto P_0c08323e;
P_0c08323e: /* original 430b, guest PC 0x0c08323e */
if(!s->budget--) { s->failed_pc=0x0c08323eu; return 0; }
target=r[3];
r[16]=code_base|0x0c083242u;
r[4]=0x0000001du;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083242u) { target=s->pc; goto dispatch; }
goto P_0c083242;
P_0c083240: /* original e41d, guest PC 0x0c083240 */
if(!s->budget--) { s->failed_pc=0x0c083240u; return 0; }
r[4]=0x0000001du;
goto P_0c083242;
P_0c083242: /* original a022, guest PC 0x0c083242 */
if(!s->budget--) { s->failed_pc=0x0c083242u; return 0; }
goto P_0c08328a;
P_0c083244: /* original 0009, guest PC 0x0c083244 */
if(!s->budget--) { s->failed_pc=0x0c083244u; return 0; }
return vf3_matrix_family(0x0c083246u,s,ram);
P_0c08327c: /* original 33b0, guest PC 0x0c08327c */
if(!s->budget--) { s->failed_pc=0x0c08327cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[11])!=0);
goto P_0c08327e;
P_0c08327e: /* original 8b04, guest PC 0x0c08327e */
if(!s->budget--) { s->failed_pc=0x0c08327eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08328a; }
goto P_0c083280;
P_0c083280: /* original d33e, guest PC 0x0c083280 */
if(!s->budget--) { s->failed_pc=0x0c083280u; return 0; }
r[3]=read(ram,0x0c08337cu,4);
goto P_0c083282;
P_0c083282: /* original 65c3, guest PC 0x0c083282 */
if(!s->budget--) { s->failed_pc=0x0c083282u; return 0; }
r[5]=r[12];
goto P_0c083284;
P_0c083284: /* original 966f, guest PC 0x0c083284 */
if(!s->budget--) { s->failed_pc=0x0c083284u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083366u,2);
goto P_0c083286;
P_0c083286: /* original 430b, guest PC 0x0c083286 */
if(!s->budget--) { s->failed_pc=0x0c083286u; return 0; }
target=r[3];
r[16]=code_base|0x0c08328au;
r[4]=0x00000021u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08328au) { target=s->pc; goto dispatch; }
goto P_0c08328a;
P_0c083288: /* original e421, guest PC 0x0c083288 */
if(!s->budget--) { s->failed_pc=0x0c083288u; return 0; }
r[4]=0x00000021u;
goto P_0c08328a;
P_0c08328a: /* original d53d, guest PC 0x0c08328a */
if(!s->budget--) { s->failed_pc=0x0c08328au; return 0; }
r[5]=read(ram,0x0c083380u,4);
goto P_0c08328c;
P_0c08328c: /* original e408, guest PC 0x0c08328c */
if(!s->budget--) { s->failed_pc=0x0c08328cu; return 0; }
r[4]=0x00000008u;
goto P_0c08328e;
P_0c08328e: /* original 63a3, guest PC 0x0c08328e */
if(!s->budget--) { s->failed_pc=0x0c08328eu; return 0; }
r[3]=r[10];
goto P_0c083290;
P_0c083290: /* original 4308, guest PC 0x0c083290 */
if(!s->budget--) { s->failed_pc=0x0c083290u; return 0; }
r[3]<<=2;
goto P_0c083292;
P_0c083292: /* original 6252, guest PC 0x0c083292 */
if(!s->budget--) { s->failed_pc=0x0c083292u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c083294;
P_0c083294: /* original e501, guest PC 0x0c083294 */
if(!s->budget--) { s->failed_pc=0x0c083294u; return 0; }
r[5]=0x00000001u;
goto P_0c083296;
P_0c083296: /* original 2249, guest PC 0x0c083296 */
if(!s->budget--) { s->failed_pc=0x0c083296u; return 0; }
r[2]&=r[4];
goto P_0c083298;
P_0c083298: /* original 1f22, guest PC 0x0c083298 */
if(!s->budget--) { s->failed_pc=0x0c083298u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c08329a;
P_0c08329a: /* original 2f32, guest PC 0x0c08329a */
if(!s->budget--) { s->failed_pc=0x0c08329au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08329c;
P_0c08329c: /* original 9264, guest PC 0x0c08329c */
if(!s->budget--) { s->failed_pc=0x0c08329cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083368u,2);
goto P_0c08329e;
P_0c08329e: /* original 32ec, guest PC 0x0c08329e */
if(!s->budget--) { s->failed_pc=0x0c08329eu; return 0; }
r[2]+=r[14];
goto P_0c0832a0;
P_0c0832a0: /* original 332c, guest PC 0x0c0832a0 */
if(!s->budget--) { s->failed_pc=0x0c0832a0u; return 0; }
r[3]+=r[2];
goto P_0c0832a2;
P_0c0832a2: /* original 62d3, guest PC 0x0c0832a2 */
if(!s->budget--) { s->failed_pc=0x0c0832a2u; return 0; }
r[2]=r[13];
goto P_0c0832a4;
P_0c0832a4: /* original 6132, guest PC 0x0c0832a4 */
if(!s->budget--) { s->failed_pc=0x0c0832a4u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0832a6;
P_0c0832a6: /* original e307, guest PC 0x0c0832a6 */
if(!s->budget--) { s->failed_pc=0x0c0832a6u; return 0; }
r[3]=0x00000007u;
goto P_0c0832a8;
P_0c0832a8: /* original 423c, guest PC 0x0c0832a8 */
if(!s->budget--) { s->failed_pc=0x0c0832a8u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[2]>>((-r[3])&31u)):((int32_t)r[2]<0?0xffffffffu:0)):r[2]<<(r[3]&31u);
goto P_0c0832aa;
P_0c0832aa: /* original 2159, guest PC 0x0c0832aa */
if(!s->budget--) { s->failed_pc=0x0c0832aau; return 0; }
r[1]&=r[5];
goto P_0c0832ac;
P_0c0832ac: /* original 65c3, guest PC 0x0c0832ac */
if(!s->budget--) { s->failed_pc=0x0c0832acu; return 0; }
r[5]=r[12];
goto P_0c0832ae;
P_0c0832ae: /* original 1f11, guest PC 0x0c0832ae */
if(!s->budget--) { s->failed_pc=0x0c0832aeu; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0832b0;
P_0c0832b0: /* original 224b, guest PC 0x0c0832b0 */
if(!s->budget--) { s->failed_pc=0x0c0832b0u; return 0; }
r[2]|=r[4];
goto P_0c0832b2;
P_0c0832b2: /* original 1f24, guest PC 0x0c0832b2 */
if(!s->budget--) { s->failed_pc=0x0c0832b2u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0832b4;
P_0c0832b4: /* original 9659, guest PC 0x0c0832b4 */
if(!s->budget--) { s->failed_pc=0x0c0832b4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08336au,2);
goto P_0c0832b6;
P_0c0832b6: /* original d131, guest PC 0x0c0832b6 */
if(!s->budget--) { s->failed_pc=0x0c0832b6u; return 0; }
r[1]=read(ram,0x0c08337cu,4);
goto P_0c0832b8;
P_0c0832b8: /* original 36ac, guest PC 0x0c0832b8 */
if(!s->budget--) { s->failed_pc=0x0c0832b8u; return 0; }
r[6]+=r[10];
goto P_0c0832ba;
P_0c0832ba: /* original 410b, guest PC 0x0c0832ba */
if(!s->budget--) { s->failed_pc=0x0c0832bau; return 0; }
target=r[1];
r[16]=code_base|0x0c0832beu;
r[4]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0832beu) { target=s->pc; goto dispatch; }
goto P_0c0832be;
P_0c0832bc: /* original e404, guest PC 0x0c0832bc */
if(!s->budget--) { s->failed_pc=0x0c0832bcu; return 0; }
r[4]=0x00000004u;
goto P_0c0832be;
P_0c0832be: /* original 9053, guest PC 0x0c0832be */
if(!s->budget--) { s->failed_pc=0x0c0832beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083368u,2);
goto P_0c0832c0;
P_0c0832c0: /* original 63f2, guest PC 0x0c0832c0 */
if(!s->budget--) { s->failed_pc=0x0c0832c0u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0832c2;
P_0c0832c2: /* original 30ec, guest PC 0x0c0832c2 */
if(!s->budget--) { s->failed_pc=0x0c0832c2u; return 0; }
r[0]+=r[14];
goto P_0c0832c4;
P_0c0832c4: /* original 003e, guest PC 0x0c0832c4 */
if(!s->budget--) { s->failed_pc=0x0c0832c4u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0832c6;
P_0c0832c6: /* original c804, guest PC 0x0c0832c6 */
if(!s->budget--) { s->failed_pc=0x0c0832c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0832c8;
P_0c0832c8: /* original 8907, guest PC 0x0c0832c8 */
if(!s->budget--) { s->failed_pc=0x0c0832c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0832da; }
goto P_0c0832ca;
P_0c0832ca: /* original 994f, guest PC 0x0c0832ca */
if(!s->budget--) { s->failed_pc=0x0c0832cau; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08336cu,2);
goto P_0c0832cc;
P_0c0832cc: /* original 65c3, guest PC 0x0c0832cc */
if(!s->budget--) { s->failed_pc=0x0c0832ccu; return 0; }
r[5]=r[12];
goto P_0c0832ce;
P_0c0832ce: /* original d12b, guest PC 0x0c0832ce */
if(!s->budget--) { s->failed_pc=0x0c0832ceu; return 0; }
r[1]=read(ram,0x0c08337cu,4);
goto P_0c0832d0;
P_0c0832d0: /* original 6693, guest PC 0x0c0832d0 */
if(!s->budget--) { s->failed_pc=0x0c0832d0u; return 0; }
r[6]=r[9];
goto P_0c0832d2;
P_0c0832d2: /* original 410b, guest PC 0x0c0832d2 */
if(!s->budget--) { s->failed_pc=0x0c0832d2u; return 0; }
target=r[1];
r[16]=code_base|0x0c0832d6u;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0832d6u) { target=s->pc; goto dispatch; }
goto P_0c0832d6;
P_0c0832d4: /* original e407, guest PC 0x0c0832d4 */
if(!s->budget--) { s->failed_pc=0x0c0832d4u; return 0; }
r[4]=0x00000007u;
goto P_0c0832d6;
P_0c0832d6: /* original a3cb, guest PC 0x0c0832d6 */
if(!s->budget--) { s->failed_pc=0x0c0832d6u; return 0; }
goto P_0c083a70;
P_0c0832d8: /* original 0009, guest PC 0x0c0832d8 */
if(!s->budget--) { s->failed_pc=0x0c0832d8u; return 0; }
goto P_0c0832da;
P_0c0832da: /* original 6283, guest PC 0x0c0832da */
if(!s->budget--) { s->failed_pc=0x0c0832dau; return 0; }
r[2]=r[8];
goto P_0c0832dc;
P_0c0832dc: /* original 7217, guest PC 0x0c0832dc */
if(!s->budget--) { s->failed_pc=0x0c0832dcu; return 0; }
r[2]+=0x00000017u;
goto P_0c0832de;
P_0c0832de: /* original 9d46, guest PC 0x0c0832de */
if(!s->budget--) { s->failed_pc=0x0c0832deu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08336eu,2);
goto P_0c0832e0;
P_0c0832e0: /* original 2f22, guest PC 0x0c0832e0 */
if(!s->budget--) { s->failed_pc=0x0c0832e0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0832e2;
P_0c0832e2: /* original 51f1, guest PC 0x0c0832e2 */
if(!s->budget--) { s->failed_pc=0x0c0832e2u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0832e4;
P_0c0832e4: /* original 2118, guest PC 0x0c0832e4 */
if(!s->budget--) { s->failed_pc=0x0c0832e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0832e6;
P_0c0832e6: /* original 8910, guest PC 0x0c0832e6 */
if(!s->budget--) { s->failed_pc=0x0c0832e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08330a; }
goto P_0c0832e8;
P_0c0832e8: /* original d124, guest PC 0x0c0832e8 */
if(!s->budget--) { s->failed_pc=0x0c0832e8u; return 0; }
r[1]=read(ram,0x0c08337cu,4);
goto P_0c0832ea;
P_0c0832ea: /* original 65c3, guest PC 0x0c0832ea */
if(!s->budget--) { s->failed_pc=0x0c0832eau; return 0; }
r[5]=r[12];
goto P_0c0832ec;
P_0c0832ec: /* original 9640, guest PC 0x0c0832ec */
if(!s->budget--) { s->failed_pc=0x0c0832ecu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083370u,2);
goto P_0c0832ee;
P_0c0832ee: /* original 410b, guest PC 0x0c0832ee */
if(!s->budget--) { s->failed_pc=0x0c0832eeu; return 0; }
target=r[1];
r[16]=code_base|0x0c0832f2u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0832f2u) { target=s->pc; goto dispatch; }
goto P_0c0832f2;
P_0c0832f0: /* original e414, guest PC 0x0c0832f0 */
if(!s->budget--) { s->failed_pc=0x0c0832f0u; return 0; }
r[4]=0x00000014u;
goto P_0c0832f2;
P_0c0832f2: /* original d322, guest PC 0x0c0832f2 */
if(!s->budget--) { s->failed_pc=0x0c0832f2u; return 0; }
r[3]=read(ram,0x0c08337cu,4);
goto P_0c0832f4;
P_0c0832f4: /* original 65c3, guest PC 0x0c0832f4 */
if(!s->budget--) { s->failed_pc=0x0c0832f4u; return 0; }
r[5]=r[12];
goto P_0c0832f6;
P_0c0832f6: /* original 963c, guest PC 0x0c0832f6 */
if(!s->budget--) { s->failed_pc=0x0c0832f6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083372u,2);
goto P_0c0832f8;
P_0c0832f8: /* original 430b, guest PC 0x0c0832f8 */
if(!s->budget--) { s->failed_pc=0x0c0832f8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0832fcu;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0832fcu) { target=s->pc; goto dispatch; }
goto P_0c0832fc;
P_0c0832fa: /* original e407, guest PC 0x0c0832fa */
if(!s->budget--) { s->failed_pc=0x0c0832fau; return 0; }
r[4]=0x00000007u;
goto P_0c0832fc;
P_0c0832fc: /* original d31f, guest PC 0x0c0832fc */
if(!s->budget--) { s->failed_pc=0x0c0832fcu; return 0; }
r[3]=read(ram,0x0c08337cu,4);
goto P_0c0832fe;
P_0c0832fe: /* original 66d3, guest PC 0x0c0832fe */
if(!s->budget--) { s->failed_pc=0x0c0832feu; return 0; }
r[6]=r[13];
goto P_0c083300;
P_0c083300: /* original 65f2, guest PC 0x0c083300 */
if(!s->budget--) { s->failed_pc=0x0c083300u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083302;
P_0c083302: /* original 430b, guest PC 0x0c083302 */
if(!s->budget--) { s->failed_pc=0x0c083302u; return 0; }
target=r[3];
r[16]=code_base|0x0c083306u;
r[4]=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083306u) { target=s->pc; goto dispatch; }
goto P_0c083306;
P_0c083304: /* original e410, guest PC 0x0c083304 */
if(!s->budget--) { s->failed_pc=0x0c083304u; return 0; }
r[4]=0x00000010u;
goto P_0c083306;
P_0c083306: /* original a068, guest PC 0x0c083306 */
if(!s->budget--) { s->failed_pc=0x0c083306u; return 0; }
goto P_0c0833da;
P_0c083308: /* original 0009, guest PC 0x0c083308 */
if(!s->budget--) { s->failed_pc=0x0c083308u; return 0; }
goto P_0c08330a;
P_0c08330a: /* original 9233, guest PC 0x0c08330a */
if(!s->budget--) { s->failed_pc=0x0c08330au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083374u,2);
goto P_0c08330c;
P_0c08330c: /* original 63a3, guest PC 0x0c08330c */
if(!s->budget--) { s->failed_pc=0x0c08330cu; return 0; }
r[3]=r[10];
goto P_0c08330e;
P_0c08330e: /* original 4308, guest PC 0x0c08330e */
if(!s->budget--) { s->failed_pc=0x0c08330eu; return 0; }
r[3]<<=2;
goto P_0c083310;
P_0c083310: /* original 32ec, guest PC 0x0c083310 */
if(!s->budget--) { s->failed_pc=0x0c083310u; return 0; }
r[2]+=r[14];
goto P_0c083312;
P_0c083312: /* original 332c, guest PC 0x0c083312 */
if(!s->budget--) { s->failed_pc=0x0c083312u; return 0; }
r[3]+=r[2];
goto P_0c083314;
P_0c083314: /* original 6132, guest PC 0x0c083314 */
if(!s->budget--) { s->failed_pc=0x0c083314u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c083316;
P_0c083316: /* original 2118, guest PC 0x0c083316 */
if(!s->budget--) { s->failed_pc=0x0c083316u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c083318;
P_0c083318: /* original 8b34, guest PC 0x0c083318 */
if(!s->budget--) { s->failed_pc=0x0c083318u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083384; }
goto P_0c08331a;
P_0c08331a: /* original d318, guest PC 0x0c08331a */
if(!s->budget--) { s->failed_pc=0x0c08331au; return 0; }
r[3]=read(ram,0x0c08337cu,4);
goto P_0c08331c;
P_0c08331c: /* original 65c3, guest PC 0x0c08331c */
if(!s->budget--) { s->failed_pc=0x0c08331cu; return 0; }
r[5]=r[12];
goto P_0c08331e;
P_0c08331e: /* original 9627, guest PC 0x0c08331e */
if(!s->budget--) { s->failed_pc=0x0c08331eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083370u,2);
goto P_0c083320;
P_0c083320: /* original 430b, guest PC 0x0c083320 */
if(!s->budget--) { s->failed_pc=0x0c083320u; return 0; }
target=r[3];
r[16]=code_base|0x0c083324u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083324u) { target=s->pc; goto dispatch; }
goto P_0c083324;
P_0c083322: /* original e414, guest PC 0x0c083322 */
if(!s->budget--) { s->failed_pc=0x0c083322u; return 0; }
r[4]=0x00000014u;
goto P_0c083324;
P_0c083324: /* original 9327, guest PC 0x0c083324 */
if(!s->budget--) { s->failed_pc=0x0c083324u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083376u,2);
goto P_0c083326;
P_0c083326: /* original 60a3, guest PC 0x0c083326 */
if(!s->budget--) { s->failed_pc=0x0c083326u; return 0; }
r[0]=r[10];
goto P_0c083328;
P_0c083328: /* original 4008, guest PC 0x0c083328 */
if(!s->budget--) { s->failed_pc=0x0c083328u; return 0; }
r[0]<<=2;
goto P_0c08332a;
P_0c08332a: /* original 33ec, guest PC 0x0c08332a */
if(!s->budget--) { s->failed_pc=0x0c08332au; return 0; }
r[3]+=r[14];
goto P_0c08332c;
P_0c08332c: /* original 003e, guest PC 0x0c08332c */
if(!s->budget--) { s->failed_pc=0x0c08332cu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c08332e;
P_0c08332e: /* original 8809, guest PC 0x0c08332e */
if(!s->budget--) { s->failed_pc=0x0c08332eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c083330;
P_0c083330: /* original 8b09, guest PC 0x0c083330 */
if(!s->budget--) { s->failed_pc=0x0c083330u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083346; }
goto P_0c083332;
P_0c083332: /* original 53f2, guest PC 0x0c083332 */
if(!s->budget--) { s->failed_pc=0x0c083332u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c083334;
P_0c083334: /* original 2338, guest PC 0x0c083334 */
if(!s->budget--) { s->failed_pc=0x0c083334u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c083336;
P_0c083336: /* original 890e, guest PC 0x0c083336 */
if(!s->budget--) { s->failed_pc=0x0c083336u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c083356; }
goto P_0c083338;
P_0c083338: /* original d310, guest PC 0x0c083338 */
if(!s->budget--) { s->failed_pc=0x0c083338u; return 0; }
r[3]=read(ram,0x0c08337cu,4);
goto P_0c08333a;
P_0c08333a: /* original 65f2, guest PC 0x0c08333a */
if(!s->budget--) { s->failed_pc=0x0c08333au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08333c;
P_0c08333c: /* original 961c, guest PC 0x0c08333c */
if(!s->budget--) { s->failed_pc=0x0c08333cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083378u,2);
goto P_0c08333e;
P_0c08333e: /* original 430b, guest PC 0x0c08333e */
if(!s->budget--) { s->failed_pc=0x0c08333eu; return 0; }
target=r[3];
r[16]=code_base|0x0c083342u;
r[4]=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083342u) { target=s->pc; goto dispatch; }
goto P_0c083342;
P_0c083340: /* original e410, guest PC 0x0c083340 */
if(!s->budget--) { s->failed_pc=0x0c083340u; return 0; }
r[4]=0x00000010u;
goto P_0c083342;
P_0c083342: /* original a008, guest PC 0x0c083342 */
if(!s->budget--) { s->failed_pc=0x0c083342u; return 0; }
goto P_0c083356;
P_0c083344: /* original 0009, guest PC 0x0c083344 */
if(!s->budget--) { s->failed_pc=0x0c083344u; return 0; }
goto P_0c083346;
P_0c083346: /* original d30d, guest PC 0x0c083346 */
if(!s->budget--) { s->failed_pc=0x0c083346u; return 0; }
r[3]=read(ram,0x0c08337cu,4);
goto P_0c083348;
P_0c083348: /* original 66d3, guest PC 0x0c083348 */
if(!s->budget--) { s->failed_pc=0x0c083348u; return 0; }
r[6]=r[13];
goto P_0c08334a;
P_0c08334a: /* original 65f2, guest PC 0x0c08334a */
if(!s->budget--) { s->failed_pc=0x0c08334au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08334c;
P_0c08334c: /* original 430b, guest PC 0x0c08334c */
if(!s->budget--) { s->failed_pc=0x0c08334cu; return 0; }
target=r[3];
r[16]=code_base|0x0c083350u;
r[4]=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083350u) { target=s->pc; goto dispatch; }
goto P_0c083350;
P_0c08334e: /* original e410, guest PC 0x0c08334e */
if(!s->budget--) { s->failed_pc=0x0c08334eu; return 0; }
r[4]=0x00000010u;
goto P_0c083350;
P_0c083350: /* original 52f2, guest PC 0x0c083350 */
if(!s->budget--) { s->failed_pc=0x0c083350u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c083352;
P_0c083352: /* original 2228, guest PC 0x0c083352 */
if(!s->budget--) { s->failed_pc=0x0c083352u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c083354;
P_0c083354: /* original 8941, guest PC 0x0c083354 */
if(!s->budget--) { s->failed_pc=0x0c083354u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0833da; }
goto P_0c083356;
P_0c083356: /* original 9d10, guest PC 0x0c083356 */
if(!s->budget--) { s->failed_pc=0x0c083356u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08337au,2);
goto P_0c083358;
P_0c083358: /* original 65c3, guest PC 0x0c083358 */
if(!s->budget--) { s->failed_pc=0x0c083358u; return 0; }
r[5]=r[12];
goto P_0c08335a;
P_0c08335a: /* original d308, guest PC 0x0c08335a */
if(!s->budget--) { s->failed_pc=0x0c08335au; return 0; }
r[3]=read(ram,0x0c08337cu,4);
goto P_0c08335c;
P_0c08335c: /* original 66d3, guest PC 0x0c08335c */
if(!s->budget--) { s->failed_pc=0x0c08335cu; return 0; }
r[6]=r[13];
goto P_0c08335e;
P_0c08335e: /* original 430b, guest PC 0x0c08335e */
if(!s->budget--) { s->failed_pc=0x0c08335eu; return 0; }
target=r[3];
r[16]=code_base|0x0c083362u;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083362u) { target=s->pc; goto dispatch; }
goto P_0c083362;
P_0c083360: /* original e407, guest PC 0x0c083360 */
if(!s->budget--) { s->failed_pc=0x0c083360u; return 0; }
r[4]=0x00000007u;
goto P_0c083362;
P_0c083362: /* original a03a, guest PC 0x0c083362 */
if(!s->budget--) { s->failed_pc=0x0c083362u; return 0; }
goto P_0c0833da;
P_0c083364: /* original 0009, guest PC 0x0c083364 */
if(!s->budget--) { s->failed_pc=0x0c083364u; return 0; }
return vf3_matrix_family(0x0c083366u,s,ram);
P_0c083384: /* original 9386, guest PC 0x0c083384 */
if(!s->budget--) { s->failed_pc=0x0c083384u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083494u,2);
goto P_0c083386;
P_0c083386: /* original 60a3, guest PC 0x0c083386 */
if(!s->budget--) { s->failed_pc=0x0c083386u; return 0; }
r[0]=r[10];
goto P_0c083388;
P_0c083388: /* original 4008, guest PC 0x0c083388 */
if(!s->budget--) { s->failed_pc=0x0c083388u; return 0; }
r[0]<<=2;
goto P_0c08338a;
P_0c08338a: /* original 33ec, guest PC 0x0c08338a */
if(!s->budget--) { s->failed_pc=0x0c08338au; return 0; }
r[3]+=r[14];
goto P_0c08338c;
P_0c08338c: /* original 003e, guest PC 0x0c08338c */
if(!s->budget--) { s->failed_pc=0x0c08338cu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c08338e;
P_0c08338e: /* original 8801, guest PC 0x0c08338e */
if(!s->budget--) { s->failed_pc=0x0c08338eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c083390;
P_0c083390: /* original 8b23, guest PC 0x0c083390 */
if(!s->budget--) { s->failed_pc=0x0c083390u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0833da; }
goto P_0c083392;
P_0c083392: /* original d344, guest PC 0x0c083392 */
if(!s->budget--) { s->failed_pc=0x0c083392u; return 0; }
r[3]=read(ram,0x0c0834a4u,4);
goto P_0c083394;
P_0c083394: /* original 65c3, guest PC 0x0c083394 */
if(!s->budget--) { s->failed_pc=0x0c083394u; return 0; }
r[5]=r[12];
goto P_0c083396;
P_0c083396: /* original 967e, guest PC 0x0c083396 */
if(!s->budget--) { s->failed_pc=0x0c083396u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083496u,2);
goto P_0c083398;
P_0c083398: /* original 430b, guest PC 0x0c083398 */
if(!s->budget--) { s->failed_pc=0x0c083398u; return 0; }
target=r[3];
r[16]=code_base|0x0c08339cu;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08339cu) { target=s->pc; goto dispatch; }
goto P_0c08339c;
P_0c08339a: /* original e407, guest PC 0x0c08339a */
if(!s->budget--) { s->failed_pc=0x0c08339au; return 0; }
r[4]=0x00000007u;
goto P_0c08339c;
P_0c08339c: /* original 937c, guest PC 0x0c08339c */
if(!s->budget--) { s->failed_pc=0x0c08339cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083498u,2);
goto P_0c08339e;
P_0c08339e: /* original 60a3, guest PC 0x0c08339e */
if(!s->budget--) { s->failed_pc=0x0c08339eu; return 0; }
r[0]=r[10];
goto P_0c0833a0;
P_0c0833a0: /* original 4008, guest PC 0x0c0833a0 */
if(!s->budget--) { s->failed_pc=0x0c0833a0u; return 0; }
r[0]<<=2;
goto P_0c0833a2;
P_0c0833a2: /* original 33ec, guest PC 0x0c0833a2 */
if(!s->budget--) { s->failed_pc=0x0c0833a2u; return 0; }
r[3]+=r[14];
goto P_0c0833a4;
P_0c0833a4: /* original 003e, guest PC 0x0c0833a4 */
if(!s->budget--) { s->failed_pc=0x0c0833a4u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0833a6;
P_0c0833a6: /* original 8809, guest PC 0x0c0833a6 */
if(!s->budget--) { s->failed_pc=0x0c0833a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0833a8;
P_0c0833a8: /* original 8b09, guest PC 0x0c0833a8 */
if(!s->budget--) { s->failed_pc=0x0c0833a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0833be; }
goto P_0c0833aa;
P_0c0833aa: /* original 53f2, guest PC 0x0c0833aa */
if(!s->budget--) { s->failed_pc=0x0c0833aau; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0833ac;
P_0c0833ac: /* original 2338, guest PC 0x0c0833ac */
if(!s->budget--) { s->failed_pc=0x0c0833acu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0833ae;
P_0c0833ae: /* original 890e, guest PC 0x0c0833ae */
if(!s->budget--) { s->failed_pc=0x0c0833aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0833ce; }
goto P_0c0833b0;
P_0c0833b0: /* original d33c, guest PC 0x0c0833b0 */
if(!s->budget--) { s->failed_pc=0x0c0833b0u; return 0; }
r[3]=read(ram,0x0c0834a4u,4);
goto P_0c0833b2;
P_0c0833b2: /* original 65f2, guest PC 0x0c0833b2 */
if(!s->budget--) { s->failed_pc=0x0c0833b2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0833b4;
P_0c0833b4: /* original 9671, guest PC 0x0c0833b4 */
if(!s->budget--) { s->failed_pc=0x0c0833b4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08349au,2);
goto P_0c0833b6;
P_0c0833b6: /* original 430b, guest PC 0x0c0833b6 */
if(!s->budget--) { s->failed_pc=0x0c0833b6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0833bau;
r[4]=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0833bau) { target=s->pc; goto dispatch; }
goto P_0c0833ba;
P_0c0833b8: /* original e410, guest PC 0x0c0833b8 */
if(!s->budget--) { s->failed_pc=0x0c0833b8u; return 0; }
r[4]=0x00000010u;
goto P_0c0833ba;
P_0c0833ba: /* original a008, guest PC 0x0c0833ba */
if(!s->budget--) { s->failed_pc=0x0c0833bau; return 0; }
goto P_0c0833ce;
P_0c0833bc: /* original 0009, guest PC 0x0c0833bc */
if(!s->budget--) { s->failed_pc=0x0c0833bcu; return 0; }
goto P_0c0833be;
P_0c0833be: /* original d339, guest PC 0x0c0833be */
if(!s->budget--) { s->failed_pc=0x0c0833beu; return 0; }
r[3]=read(ram,0x0c0834a4u,4);
goto P_0c0833c0;
P_0c0833c0: /* original 66d3, guest PC 0x0c0833c0 */
if(!s->budget--) { s->failed_pc=0x0c0833c0u; return 0; }
r[6]=r[13];
goto P_0c0833c2;
P_0c0833c2: /* original 65f2, guest PC 0x0c0833c2 */
if(!s->budget--) { s->failed_pc=0x0c0833c2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0833c4;
P_0c0833c4: /* original 430b, guest PC 0x0c0833c4 */
if(!s->budget--) { s->failed_pc=0x0c0833c4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0833c8u;
r[4]=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0833c8u) { target=s->pc; goto dispatch; }
goto P_0c0833c8;
P_0c0833c6: /* original e410, guest PC 0x0c0833c6 */
if(!s->budget--) { s->failed_pc=0x0c0833c6u; return 0; }
r[4]=0x00000010u;
goto P_0c0833c8;
P_0c0833c8: /* original 52f2, guest PC 0x0c0833c8 */
if(!s->budget--) { s->failed_pc=0x0c0833c8u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0833ca;
P_0c0833ca: /* original 2228, guest PC 0x0c0833ca */
if(!s->budget--) { s->failed_pc=0x0c0833cau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0833cc;
P_0c0833cc: /* original 8905, guest PC 0x0c0833cc */
if(!s->budget--) { s->failed_pc=0x0c0833ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0833da; }
goto P_0c0833ce;
P_0c0833ce: /* original 9d65, guest PC 0x0c0833ce */
if(!s->budget--) { s->failed_pc=0x0c0833ceu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08349cu,2);
goto P_0c0833d0;
P_0c0833d0: /* original 65c3, guest PC 0x0c0833d0 */
if(!s->budget--) { s->failed_pc=0x0c0833d0u; return 0; }
r[5]=r[12];
goto P_0c0833d2;
P_0c0833d2: /* original d334, guest PC 0x0c0833d2 */
if(!s->budget--) { s->failed_pc=0x0c0833d2u; return 0; }
r[3]=read(ram,0x0c0834a4u,4);
goto P_0c0833d4;
P_0c0833d4: /* original 66d3, guest PC 0x0c0833d4 */
if(!s->budget--) { s->failed_pc=0x0c0833d4u; return 0; }
r[6]=r[13];
goto P_0c0833d6;
P_0c0833d6: /* original 430b, guest PC 0x0c0833d6 */
if(!s->budget--) { s->failed_pc=0x0c0833d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0833dau;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0833dau) { target=s->pc; goto dispatch; }
goto P_0c0833da;
P_0c0833d8: /* original e414, guest PC 0x0c0833d8 */
if(!s->budget--) { s->failed_pc=0x0c0833d8u; return 0; }
r[4]=0x00000014u;
goto P_0c0833da;
P_0c0833da: /* original 6383, guest PC 0x0c0833da */
if(!s->budget--) { s->failed_pc=0x0c0833dau; return 0; }
r[3]=r[8];
goto P_0c0833dc;
P_0c0833dc: /* original 7311, guest PC 0x0c0833dc */
if(!s->budget--) { s->failed_pc=0x0c0833dcu; return 0; }
r[3]+=0x00000011u;
goto P_0c0833de;
P_0c0833de: /* original 60a3, guest PC 0x0c0833de */
if(!s->budget--) { s->failed_pc=0x0c0833deu; return 0; }
r[0]=r[10];
goto P_0c0833e0;
P_0c0833e0: /* original 4008, guest PC 0x0c0833e0 */
if(!s->budget--) { s->failed_pc=0x0c0833e0u; return 0; }
r[0]<<=2;
goto P_0c0833e2;
P_0c0833e2: /* original 6283, guest PC 0x0c0833e2 */
if(!s->budget--) { s->failed_pc=0x0c0833e2u; return 0; }
r[2]=r[8];
goto P_0c0833e4;
P_0c0833e4: /* original 6ca3, guest PC 0x0c0833e4 */
if(!s->budget--) { s->failed_pc=0x0c0833e4u; return 0; }
r[12]=r[10];
goto P_0c0833e6;
P_0c0833e6: /* original 6d83, guest PC 0x0c0833e6 */
if(!s->budget--) { s->failed_pc=0x0c0833e6u; return 0; }
r[13]=r[8];
goto P_0c0833e8;
P_0c0833e8: /* original 7d0a, guest PC 0x0c0833e8 */
if(!s->budget--) { s->failed_pc=0x0c0833e8u; return 0; }
r[13]+=0x0000000au;
goto P_0c0833ea;
P_0c0833ea: /* original 4c08, guest PC 0x0c0833ea */
if(!s->budget--) { s->failed_pc=0x0c0833eau; return 0; }
r[12]<<=2;
goto P_0c0833ec;
P_0c0833ec: /* original 1fd2, guest PC 0x0c0833ec */
if(!s->budget--) { s->failed_pc=0x0c0833ecu; return 0; }
write(ram,r[15]+8,r[13],4);
goto P_0c0833ee;
P_0c0833ee: /* original 2f32, guest PC 0x0c0833ee */
if(!s->budget--) { s->failed_pc=0x0c0833eeu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0833f0;
P_0c0833f0: /* original 720f, guest PC 0x0c0833f0 */
if(!s->budget--) { s->failed_pc=0x0c0833f0u; return 0; }
r[2]+=0x0000000fu;
goto P_0c0833f2;
P_0c0833f2: /* original 4c08, guest PC 0x0c0833f2 */
if(!s->budget--) { s->failed_pc=0x0c0833f2u; return 0; }
r[12]<<=2;
goto P_0c0833f4;
P_0c0833f4: /* original 1f21, guest PC 0x0c0833f4 */
if(!s->budget--) { s->failed_pc=0x0c0833f4u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0833f6;
P_0c0833f6: /* original 934d, guest PC 0x0c0833f6 */
if(!s->budget--) { s->failed_pc=0x0c0833f6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083494u,2);
goto P_0c0833f8;
P_0c0833f8: /* original 33ec, guest PC 0x0c0833f8 */
if(!s->budget--) { s->failed_pc=0x0c0833f8u; return 0; }
r[3]+=r[14];
goto P_0c0833fa;
P_0c0833fa: /* original 003e, guest PC 0x0c0833fa */
if(!s->budget--) { s->failed_pc=0x0c0833fau; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0833fc;
P_0c0833fc: /* original 8801, guest PC 0x0c0833fc */
if(!s->budget--) { s->failed_pc=0x0c0833fcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0833fe;
P_0c0833fe: /* original 8f57, guest PC 0x0c0833fe */
if(!s->budget--) { s->failed_pc=0x0c0833feu; return 0; }
cond=r[17]&1u;
r[12]<<=2;
if(!cond) { goto P_0c0834b0; }
goto P_0c083402;
P_0c083400: /* original 4c08, guest PC 0x0c083400 */
if(!s->budget--) { s->failed_pc=0x0c083400u; return 0; }
r[12]<<=2;
goto P_0c083402;
P_0c083402: /* original 9349, guest PC 0x0c083402 */
if(!s->budget--) { s->failed_pc=0x0c083402u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083498u,2);
goto P_0c083404;
P_0c083404: /* original 60a3, guest PC 0x0c083404 */
if(!s->budget--) { s->failed_pc=0x0c083404u; return 0; }
r[0]=r[10];
goto P_0c083406;
P_0c083406: /* original 4008, guest PC 0x0c083406 */
if(!s->budget--) { s->failed_pc=0x0c083406u; return 0; }
r[0]<<=2;
goto P_0c083408;
P_0c083408: /* original 33ec, guest PC 0x0c083408 */
if(!s->budget--) { s->failed_pc=0x0c083408u; return 0; }
r[3]+=r[14];
goto P_0c08340a;
P_0c08340a: /* original 003e, guest PC 0x0c08340a */
if(!s->budget--) { s->failed_pc=0x0c08340au; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c08340c;
P_0c08340c: /* original 8801, guest PC 0x0c08340c */
if(!s->budget--) { s->failed_pc=0x0c08340cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08340e;
P_0c08340e: /* original 8b20, guest PC 0x0c08340e */
if(!s->budget--) { s->failed_pc=0x0c08340eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083452; }
goto P_0c083410;
P_0c083410: /* original d324, guest PC 0x0c083410 */
if(!s->budget--) { s->failed_pc=0x0c083410u; return 0; }
r[3]=read(ram,0x0c0834a4u,4);
goto P_0c083412;
P_0c083412: /* original 65d3, guest PC 0x0c083412 */
if(!s->budget--) { s->failed_pc=0x0c083412u; return 0; }
r[5]=r[13];
goto P_0c083414;
P_0c083414: /* original 9643, guest PC 0x0c083414 */
if(!s->budget--) { s->failed_pc=0x0c083414u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08349eu,2);
goto P_0c083416;
P_0c083416: /* original 430b, guest PC 0x0c083416 */
if(!s->budget--) { s->failed_pc=0x0c083416u; return 0; }
target=r[3];
r[16]=code_base|0x0c08341au;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08341au) { target=s->pc; goto dispatch; }
goto P_0c08341a;
P_0c083418: /* original e412, guest PC 0x0c083418 */
if(!s->budget--) { s->failed_pc=0x0c083418u; return 0; }
r[4]=0x00000012u;
goto P_0c08341a;
P_0c08341a: /* original 9641, guest PC 0x0c08341a */
if(!s->budget--) { s->failed_pc=0x0c08341au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0834a0u,2);
goto P_0c08341c;
P_0c08341c: /* original 65d3, guest PC 0x0c08341c */
if(!s->budget--) { s->failed_pc=0x0c08341cu; return 0; }
r[5]=r[13];
goto P_0c08341e;
P_0c08341e: /* original d322, guest PC 0x0c08341e */
if(!s->budget--) { s->failed_pc=0x0c08341eu; return 0; }
r[3]=read(ram,0x0c0834a8u,4);
goto P_0c083420;
P_0c083420: /* original 36ec, guest PC 0x0c083420 */
if(!s->budget--) { s->failed_pc=0x0c083420u; return 0; }
r[6]+=r[14];
goto P_0c083422;
P_0c083422: /* original 36cc, guest PC 0x0c083422 */
if(!s->budget--) { s->failed_pc=0x0c083422u; return 0; }
r[6]+=r[12];
goto P_0c083424;
P_0c083424: /* original 5661, guest PC 0x0c083424 */
if(!s->budget--) { s->failed_pc=0x0c083424u; return 0; }
r[6]=read(ram,r[6]+4,4);
goto P_0c083426;
P_0c083426: /* original 430b, guest PC 0x0c083426 */
if(!s->budget--) { s->failed_pc=0x0c083426u; return 0; }
target=r[3];
r[16]=code_base|0x0c08342au;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08342au) { target=s->pc; goto dispatch; }
goto P_0c08342a;
P_0c083428: /* original e414, guest PC 0x0c083428 */
if(!s->budget--) { s->failed_pc=0x0c083428u; return 0; }
r[4]=0x00000014u;
goto P_0c08342a;
P_0c08342a: /* original 6292, guest PC 0x0c08342a */
if(!s->budget--) { s->failed_pc=0x0c08342au; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c08342c;
P_0c08342c: /* original 32b0, guest PC 0x0c08342c */
if(!s->budget--) { s->failed_pc=0x0c08342cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c08342e;
P_0c08342e: /* original 8f06, guest PC 0x0c08342e */
if(!s->budget--) { s->failed_pc=0x0c08342eu; return 0; }
cond=r[17]&1u;
r[4]=0x0000002du;
if(!cond) { goto P_0c08343e; }
goto P_0c083432;
P_0c083430: /* original e42d, guest PC 0x0c083430 */
if(!s->budget--) { s->failed_pc=0x0c083430u; return 0; }
r[4]=0x0000002du;
goto P_0c083432;
P_0c083432: /* original 9635, guest PC 0x0c083432 */
if(!s->budget--) { s->failed_pc=0x0c083432u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0834a0u,2);
goto P_0c083434;
P_0c083434: /* original 36ec, guest PC 0x0c083434 */
if(!s->budget--) { s->failed_pc=0x0c083434u; return 0; }
r[6]+=r[14];
goto P_0c083436;
P_0c083436: /* original 36cc, guest PC 0x0c083436 */
if(!s->budget--) { s->failed_pc=0x0c083436u; return 0; }
r[6]+=r[12];
goto P_0c083438;
P_0c083438: /* original 5661, guest PC 0x0c083438 */
if(!s->budget--) { s->failed_pc=0x0c083438u; return 0; }
r[6]=read(ram,r[6]+4,4);
goto P_0c08343a;
P_0c08343a: /* original a005, guest PC 0x0c08343a */
if(!s->budget--) { s->failed_pc=0x0c08343au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083448;
P_0c08343c: /* original 65f2, guest PC 0x0c08343c */
if(!s->budget--) { s->failed_pc=0x0c08343cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08343e;
P_0c08343e: /* original 962f, guest PC 0x0c08343e */
if(!s->budget--) { s->failed_pc=0x0c08343eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0834a0u,2);
goto P_0c083440;
P_0c083440: /* original 55f1, guest PC 0x0c083440 */
if(!s->budget--) { s->failed_pc=0x0c083440u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c083442;
P_0c083442: /* original 36ec, guest PC 0x0c083442 */
if(!s->budget--) { s->failed_pc=0x0c083442u; return 0; }
r[6]+=r[14];
goto P_0c083444;
P_0c083444: /* original 36cc, guest PC 0x0c083444 */
if(!s->budget--) { s->failed_pc=0x0c083444u; return 0; }
r[6]+=r[12];
goto P_0c083446;
P_0c083446: /* original 5661, guest PC 0x0c083446 */
if(!s->budget--) { s->failed_pc=0x0c083446u; return 0; }
r[6]=read(ram,r[6]+4,4);
goto P_0c083448;
P_0c083448: /* original d317, guest PC 0x0c083448 */
if(!s->budget--) { s->failed_pc=0x0c083448u; return 0; }
r[3]=read(ram,0x0c0834a8u,4);
goto P_0c08344a;
P_0c08344a: /* original 430b, guest PC 0x0c08344a */
if(!s->budget--) { s->failed_pc=0x0c08344au; return 0; }
target=r[3];
r[16]=code_base|0x0c08344eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08344eu) { target=s->pc; goto dispatch; }
goto P_0c08344e;
P_0c08344c: /* original 0009, guest PC 0x0c08344c */
if(!s->budget--) { s->failed_pc=0x0c08344cu; return 0; }
goto P_0c08344e;
P_0c08344e: /* original a045, guest PC 0x0c08344e */
if(!s->budget--) { s->failed_pc=0x0c08344eu; return 0; }
goto P_0c0834dc;
P_0c083450: /* original 0009, guest PC 0x0c083450 */
if(!s->budget--) { s->failed_pc=0x0c083450u; return 0; }
goto P_0c083452;
P_0c083452: /* original d314, guest PC 0x0c083452 */
if(!s->budget--) { s->failed_pc=0x0c083452u; return 0; }
r[3]=read(ram,0x0c0834a4u,4);
goto P_0c083454;
P_0c083454: /* original 65d3, guest PC 0x0c083454 */
if(!s->budget--) { s->failed_pc=0x0c083454u; return 0; }
r[5]=r[13];
goto P_0c083456;
P_0c083456: /* original 9624, guest PC 0x0c083456 */
if(!s->budget--) { s->failed_pc=0x0c083456u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0834a2u,2);
goto P_0c083458;
P_0c083458: /* original 430b, guest PC 0x0c083458 */
if(!s->budget--) { s->failed_pc=0x0c083458u; return 0; }
target=r[3];
r[16]=code_base|0x0c08345cu;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08345cu) { target=s->pc; goto dispatch; }
goto P_0c08345c;
P_0c08345a: /* original e412, guest PC 0x0c08345a */
if(!s->budget--) { s->failed_pc=0x0c08345au; return 0; }
r[4]=0x00000012u;
goto P_0c08345c;
P_0c08345c: /* original 9620, guest PC 0x0c08345c */
if(!s->budget--) { s->failed_pc=0x0c08345cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0834a0u,2);
goto P_0c08345e;
P_0c08345e: /* original 65d3, guest PC 0x0c08345e */
if(!s->budget--) { s->failed_pc=0x0c08345eu; return 0; }
r[5]=r[13];
goto P_0c083460;
P_0c083460: /* original d312, guest PC 0x0c083460 */
if(!s->budget--) { s->failed_pc=0x0c083460u; return 0; }
r[3]=read(ram,0x0c0834acu,4);
goto P_0c083462;
P_0c083462: /* original 36ec, guest PC 0x0c083462 */
if(!s->budget--) { s->failed_pc=0x0c083462u; return 0; }
r[6]+=r[14];
goto P_0c083464;
P_0c083464: /* original 36cc, guest PC 0x0c083464 */
if(!s->budget--) { s->failed_pc=0x0c083464u; return 0; }
r[6]+=r[12];
goto P_0c083466;
P_0c083466: /* original 5661, guest PC 0x0c083466 */
if(!s->budget--) { s->failed_pc=0x0c083466u; return 0; }
r[6]=read(ram,r[6]+4,4);
goto P_0c083468;
P_0c083468: /* original 430b, guest PC 0x0c083468 */
if(!s->budget--) { s->failed_pc=0x0c083468u; return 0; }
target=r[3];
r[16]=code_base|0x0c08346cu;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08346cu) { target=s->pc; goto dispatch; }
goto P_0c08346c;
P_0c08346a: /* original e414, guest PC 0x0c08346a */
if(!s->budget--) { s->failed_pc=0x0c08346au; return 0; }
r[4]=0x00000014u;
goto P_0c08346c;
P_0c08346c: /* original 6292, guest PC 0x0c08346c */
if(!s->budget--) { s->failed_pc=0x0c08346cu; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c08346e;
P_0c08346e: /* original 32b0, guest PC 0x0c08346e */
if(!s->budget--) { s->failed_pc=0x0c08346eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c083470;
P_0c083470: /* original 8f06, guest PC 0x0c083470 */
if(!s->budget--) { s->failed_pc=0x0c083470u; return 0; }
cond=r[17]&1u;
r[4]=0x0000002du;
if(!cond) { goto P_0c083480; }
goto P_0c083474;
P_0c083472: /* original e42d, guest PC 0x0c083472 */
if(!s->budget--) { s->failed_pc=0x0c083472u; return 0; }
r[4]=0x0000002du;
goto P_0c083474;
P_0c083474: /* original 9614, guest PC 0x0c083474 */
if(!s->budget--) { s->failed_pc=0x0c083474u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0834a0u,2);
goto P_0c083476;
P_0c083476: /* original 36ec, guest PC 0x0c083476 */
if(!s->budget--) { s->failed_pc=0x0c083476u; return 0; }
r[6]+=r[14];
goto P_0c083478;
P_0c083478: /* original 36cc, guest PC 0x0c083478 */
if(!s->budget--) { s->failed_pc=0x0c083478u; return 0; }
r[6]+=r[12];
goto P_0c08347a;
P_0c08347a: /* original 5661, guest PC 0x0c08347a */
if(!s->budget--) { s->failed_pc=0x0c08347au; return 0; }
r[6]=read(ram,r[6]+4,4);
goto P_0c08347c;
P_0c08347c: /* original a005, guest PC 0x0c08347c */
if(!s->budget--) { s->failed_pc=0x0c08347cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08348a;
P_0c08347e: /* original 65f2, guest PC 0x0c08347e */
if(!s->budget--) { s->failed_pc=0x0c08347eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083480;
P_0c083480: /* original 960e, guest PC 0x0c083480 */
if(!s->budget--) { s->failed_pc=0x0c083480u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0834a0u,2);
goto P_0c083482;
P_0c083482: /* original 55f1, guest PC 0x0c083482 */
if(!s->budget--) { s->failed_pc=0x0c083482u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c083484;
P_0c083484: /* original 36ec, guest PC 0x0c083484 */
if(!s->budget--) { s->failed_pc=0x0c083484u; return 0; }
r[6]+=r[14];
goto P_0c083486;
P_0c083486: /* original 36cc, guest PC 0x0c083486 */
if(!s->budget--) { s->failed_pc=0x0c083486u; return 0; }
r[6]+=r[12];
goto P_0c083488;
P_0c083488: /* original 5661, guest PC 0x0c083488 */
if(!s->budget--) { s->failed_pc=0x0c083488u; return 0; }
r[6]=read(ram,r[6]+4,4);
goto P_0c08348a;
P_0c08348a: /* original d308, guest PC 0x0c08348a */
if(!s->budget--) { s->failed_pc=0x0c08348au; return 0; }
r[3]=read(ram,0x0c0834acu,4);
goto P_0c08348c;
P_0c08348c: /* original 430b, guest PC 0x0c08348c */
if(!s->budget--) { s->failed_pc=0x0c08348cu; return 0; }
target=r[3];
r[16]=code_base|0x0c083490u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083490u) { target=s->pc; goto dispatch; }
goto P_0c083490;
P_0c08348e: /* original 0009, guest PC 0x0c08348e */
if(!s->budget--) { s->failed_pc=0x0c08348eu; return 0; }
goto P_0c083490;
P_0c083490: /* original a024, guest PC 0x0c083490 */
if(!s->budget--) { s->failed_pc=0x0c083490u; return 0; }
goto P_0c0834dc;
P_0c083492: /* original 0009, guest PC 0x0c083492 */
if(!s->budget--) { s->failed_pc=0x0c083492u; return 0; }
return vf3_matrix_family(0x0c083494u,s,ram);
P_0c0834b0: /* original d341, guest PC 0x0c0834b0 */
if(!s->budget--) { s->failed_pc=0x0c0834b0u; return 0; }
r[3]=read(ram,0x0c0835b8u,4);
goto P_0c0834b2;
P_0c0834b2: /* original 65d3, guest PC 0x0c0834b2 */
if(!s->budget--) { s->failed_pc=0x0c0834b2u; return 0; }
r[5]=r[13];
goto P_0c0834b4;
P_0c0834b4: /* original 9679, guest PC 0x0c0834b4 */
if(!s->budget--) { s->failed_pc=0x0c0834b4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835aau,2);
goto P_0c0834b6;
P_0c0834b6: /* original 430b, guest PC 0x0c0834b6 */
if(!s->budget--) { s->failed_pc=0x0c0834b6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0834bau;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0834bau) { target=s->pc; goto dispatch; }
goto P_0c0834ba;
P_0c0834b8: /* original e412, guest PC 0x0c0834b8 */
if(!s->budget--) { s->failed_pc=0x0c0834b8u; return 0; }
r[4]=0x00000012u;
goto P_0c0834ba;
P_0c0834ba: /* original d240, guest PC 0x0c0834ba */
if(!s->budget--) { s->failed_pc=0x0c0834bau; return 0; }
r[2]=read(ram,0x0c0835bcu,4);
goto P_0c0834bc;
P_0c0834bc: /* original 65d3, guest PC 0x0c0834bc */
if(!s->budget--) { s->failed_pc=0x0c0834bcu; return 0; }
r[5]=r[13];
goto P_0c0834be;
P_0c0834be: /* original e604, guest PC 0x0c0834be */
if(!s->budget--) { s->failed_pc=0x0c0834beu; return 0; }
r[6]=0x00000004u;
goto P_0c0834c0;
P_0c0834c0: /* original 420b, guest PC 0x0c0834c0 */
if(!s->budget--) { s->failed_pc=0x0c0834c0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0834c4u;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0834c4u) { target=s->pc; goto dispatch; }
goto P_0c0834c4;
P_0c0834c2: /* original e407, guest PC 0x0c0834c2 */
if(!s->budget--) { s->failed_pc=0x0c0834c2u; return 0; }
r[4]=0x00000007u;
goto P_0c0834c4;
P_0c0834c4: /* original 6392, guest PC 0x0c0834c4 */
if(!s->budget--) { s->failed_pc=0x0c0834c4u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c0834c6;
P_0c0834c6: /* original 33b0, guest PC 0x0c0834c6 */
if(!s->budget--) { s->failed_pc=0x0c0834c6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[11])!=0);
goto P_0c0834c8;
P_0c0834c8: /* original 8f03, guest PC 0x0c0834c8 */
if(!s->budget--) { s->failed_pc=0x0c0834c8u; return 0; }
cond=r[17]&1u;
r[4]=0x0000002du;
if(!cond) { goto P_0c0834d2; }
goto P_0c0834cc;
P_0c0834ca: /* original e42d, guest PC 0x0c0834ca */
if(!s->budget--) { s->failed_pc=0x0c0834cau; return 0; }
r[4]=0x0000002du;
goto P_0c0834cc;
P_0c0834cc: /* original e604, guest PC 0x0c0834cc */
if(!s->budget--) { s->failed_pc=0x0c0834ccu; return 0; }
r[6]=0x00000004u;
goto P_0c0834ce;
P_0c0834ce: /* original a002, guest PC 0x0c0834ce */
if(!s->budget--) { s->failed_pc=0x0c0834ceu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0834d6;
P_0c0834d0: /* original 65f2, guest PC 0x0c0834d0 */
if(!s->budget--) { s->failed_pc=0x0c0834d0u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0834d2;
P_0c0834d2: /* original 55f1, guest PC 0x0c0834d2 */
if(!s->budget--) { s->failed_pc=0x0c0834d2u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0834d4;
P_0c0834d4: /* original e604, guest PC 0x0c0834d4 */
if(!s->budget--) { s->failed_pc=0x0c0834d4u; return 0; }
r[6]=0x00000004u;
goto P_0c0834d6;
P_0c0834d6: /* original d339, guest PC 0x0c0834d6 */
if(!s->budget--) { s->failed_pc=0x0c0834d6u; return 0; }
r[3]=read(ram,0x0c0835bcu,4);
goto P_0c0834d8;
P_0c0834d8: /* original 430b, guest PC 0x0c0834d8 */
if(!s->budget--) { s->failed_pc=0x0c0834d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0834dcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0834dcu) { target=s->pc; goto dispatch; }
goto P_0c0834dc;
P_0c0834da: /* original 0009, guest PC 0x0c0834da */
if(!s->budget--) { s->failed_pc=0x0c0834dau; return 0; }
goto P_0c0834dc;
P_0c0834dc: /* original 60a3, guest PC 0x0c0834dc */
if(!s->budget--) { s->failed_pc=0x0c0834dcu; return 0; }
r[0]=r[10];
goto P_0c0834de;
P_0c0834de: /* original 4008, guest PC 0x0c0834de */
if(!s->budget--) { s->failed_pc=0x0c0834deu; return 0; }
r[0]<<=2;
goto P_0c0834e0;
P_0c0834e0: /* original 6283, guest PC 0x0c0834e0 */
if(!s->budget--) { s->failed_pc=0x0c0834e0u; return 0; }
r[2]=r[8];
goto P_0c0834e2;
P_0c0834e2: /* original 720d, guest PC 0x0c0834e2 */
if(!s->budget--) { s->failed_pc=0x0c0834e2u; return 0; }
r[2]+=0x0000000du;
goto P_0c0834e4;
P_0c0834e4: /* original 2f22, guest PC 0x0c0834e4 */
if(!s->budget--) { s->failed_pc=0x0c0834e4u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0834e6;
P_0c0834e6: /* original 9361, guest PC 0x0c0834e6 */
if(!s->budget--) { s->failed_pc=0x0c0834e6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835acu,2);
goto P_0c0834e8;
P_0c0834e8: /* original 33ec, guest PC 0x0c0834e8 */
if(!s->budget--) { s->failed_pc=0x0c0834e8u; return 0; }
r[3]+=r[14];
goto P_0c0834ea;
P_0c0834ea: /* original 003e, guest PC 0x0c0834ea */
if(!s->budget--) { s->failed_pc=0x0c0834eau; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0834ec;
P_0c0834ec: /* original 8801, guest PC 0x0c0834ec */
if(!s->budget--) { s->failed_pc=0x0c0834ecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0834ee;
P_0c0834ee: /* original 8f4b, guest PC 0x0c0834ee */
if(!s->budget--) { s->failed_pc=0x0c0834eeu; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c083588; }
goto P_0c0834f2;
P_0c0834f0: /* original 7d02, guest PC 0x0c0834f0 */
if(!s->budget--) { s->failed_pc=0x0c0834f0u; return 0; }
r[13]+=0x00000002u;
goto P_0c0834f2;
P_0c0834f2: /* original 935c, guest PC 0x0c0834f2 */
if(!s->budget--) { s->failed_pc=0x0c0834f2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835aeu,2);
goto P_0c0834f4;
P_0c0834f4: /* original 60a3, guest PC 0x0c0834f4 */
if(!s->budget--) { s->failed_pc=0x0c0834f4u; return 0; }
r[0]=r[10];
goto P_0c0834f6;
P_0c0834f6: /* original 4008, guest PC 0x0c0834f6 */
if(!s->budget--) { s->failed_pc=0x0c0834f6u; return 0; }
r[0]<<=2;
goto P_0c0834f8;
P_0c0834f8: /* original 33ec, guest PC 0x0c0834f8 */
if(!s->budget--) { s->failed_pc=0x0c0834f8u; return 0; }
r[3]+=r[14];
goto P_0c0834fa;
P_0c0834fa: /* original 003e, guest PC 0x0c0834fa */
if(!s->budget--) { s->failed_pc=0x0c0834fau; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0834fc;
P_0c0834fc: /* original 8802, guest PC 0x0c0834fc */
if(!s->budget--) { s->failed_pc=0x0c0834fcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0834fe;
P_0c0834fe: /* original 8b21, guest PC 0x0c0834fe */
if(!s->budget--) { s->failed_pc=0x0c0834feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083544; }
goto P_0c083500;
P_0c083500: /* original d32d, guest PC 0x0c083500 */
if(!s->budget--) { s->failed_pc=0x0c083500u; return 0; }
r[3]=read(ram,0x0c0835b8u,4);
goto P_0c083502;
P_0c083502: /* original 65d3, guest PC 0x0c083502 */
if(!s->budget--) { s->failed_pc=0x0c083502u; return 0; }
r[5]=r[13];
goto P_0c083504;
P_0c083504: /* original 9654, guest PC 0x0c083504 */
if(!s->budget--) { s->failed_pc=0x0c083504u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b0u,2);
goto P_0c083506;
P_0c083506: /* original 430b, guest PC 0x0c083506 */
if(!s->budget--) { s->failed_pc=0x0c083506u; return 0; }
target=r[3];
r[16]=code_base|0x0c08350au;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08350au) { target=s->pc; goto dispatch; }
goto P_0c08350a;
P_0c083508: /* original e412, guest PC 0x0c083508 */
if(!s->budget--) { s->failed_pc=0x0c083508u; return 0; }
r[4]=0x00000012u;
goto P_0c08350a;
P_0c08350a: /* original 9652, guest PC 0x0c08350a */
if(!s->budget--) { s->failed_pc=0x0c08350au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b2u,2);
goto P_0c08350c;
P_0c08350c: /* original 65d3, guest PC 0x0c08350c */
if(!s->budget--) { s->failed_pc=0x0c08350cu; return 0; }
r[5]=r[13];
goto P_0c08350e;
P_0c08350e: /* original d32c, guest PC 0x0c08350e */
if(!s->budget--) { s->failed_pc=0x0c08350eu; return 0; }
r[3]=read(ram,0x0c0835c0u,4);
goto P_0c083510;
P_0c083510: /* original 36ec, guest PC 0x0c083510 */
if(!s->budget--) { s->failed_pc=0x0c083510u; return 0; }
r[6]+=r[14];
goto P_0c083512;
P_0c083512: /* original 36cc, guest PC 0x0c083512 */
if(!s->budget--) { s->failed_pc=0x0c083512u; return 0; }
r[6]+=r[12];
goto P_0c083514;
P_0c083514: /* original 5662, guest PC 0x0c083514 */
if(!s->budget--) { s->failed_pc=0x0c083514u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c083516;
P_0c083516: /* original 430b, guest PC 0x0c083516 */
if(!s->budget--) { s->failed_pc=0x0c083516u; return 0; }
target=r[3];
r[16]=code_base|0x0c08351au;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08351au) { target=s->pc; goto dispatch; }
goto P_0c08351a;
P_0c083518: /* original e414, guest PC 0x0c083518 */
if(!s->budget--) { s->failed_pc=0x0c083518u; return 0; }
r[4]=0x00000014u;
goto P_0c08351a;
P_0c08351a: /* original 6292, guest PC 0x0c08351a */
if(!s->budget--) { s->failed_pc=0x0c08351au; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c08351c;
P_0c08351c: /* original 32b0, guest PC 0x0c08351c */
if(!s->budget--) { s->failed_pc=0x0c08351cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c08351e;
P_0c08351e: /* original 8b06, guest PC 0x0c08351e */
if(!s->budget--) { s->failed_pc=0x0c08351eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08352e; }
goto P_0c083520;
P_0c083520: /* original 9647, guest PC 0x0c083520 */
if(!s->budget--) { s->failed_pc=0x0c083520u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b2u,2);
goto P_0c083522;
P_0c083522: /* original 55f1, guest PC 0x0c083522 */
if(!s->budget--) { s->failed_pc=0x0c083522u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c083524;
P_0c083524: /* original 36ec, guest PC 0x0c083524 */
if(!s->budget--) { s->failed_pc=0x0c083524u; return 0; }
r[6]+=r[14];
goto P_0c083526;
P_0c083526: /* original 36cc, guest PC 0x0c083526 */
if(!s->budget--) { s->failed_pc=0x0c083526u; return 0; }
r[6]+=r[12];
goto P_0c083528;
P_0c083528: /* original 5662, guest PC 0x0c083528 */
if(!s->budget--) { s->failed_pc=0x0c083528u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c08352a;
P_0c08352a: /* original a006, guest PC 0x0c08352a */
if(!s->budget--) { s->failed_pc=0x0c08352au; return 0; }
r[4]=0x00000030u;
goto P_0c08353a;
P_0c08352c: /* original e430, guest PC 0x0c08352c */
if(!s->budget--) { s->failed_pc=0x0c08352cu; return 0; }
r[4]=0x00000030u;
goto P_0c08352e;
P_0c08352e: /* original 9640, guest PC 0x0c08352e */
if(!s->budget--) { s->failed_pc=0x0c08352eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b2u,2);
goto P_0c083530;
P_0c083530: /* original e433, guest PC 0x0c083530 */
if(!s->budget--) { s->failed_pc=0x0c083530u; return 0; }
r[4]=0x00000033u;
goto P_0c083532;
P_0c083532: /* original 65f2, guest PC 0x0c083532 */
if(!s->budget--) { s->failed_pc=0x0c083532u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083534;
P_0c083534: /* original 36ec, guest PC 0x0c083534 */
if(!s->budget--) { s->failed_pc=0x0c083534u; return 0; }
r[6]+=r[14];
goto P_0c083536;
P_0c083536: /* original 36cc, guest PC 0x0c083536 */
if(!s->budget--) { s->failed_pc=0x0c083536u; return 0; }
r[6]+=r[12];
goto P_0c083538;
P_0c083538: /* original 5662, guest PC 0x0c083538 */
if(!s->budget--) { s->failed_pc=0x0c083538u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c08353a;
P_0c08353a: /* original d321, guest PC 0x0c08353a */
if(!s->budget--) { s->failed_pc=0x0c08353au; return 0; }
r[3]=read(ram,0x0c0835c0u,4);
goto P_0c08353c;
P_0c08353c: /* original 430b, guest PC 0x0c08353c */
if(!s->budget--) { s->failed_pc=0x0c08353cu; return 0; }
target=r[3];
r[16]=code_base|0x0c083540u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083540u) { target=s->pc; goto dispatch; }
goto P_0c083540;
P_0c08353e: /* original 0009, guest PC 0x0c08353e */
if(!s->budget--) { s->failed_pc=0x0c08353eu; return 0; }
goto P_0c083540;
P_0c083540: /* original a046, guest PC 0x0c083540 */
if(!s->budget--) { s->failed_pc=0x0c083540u; return 0; }
goto P_0c0835d0;
P_0c083542: /* original 0009, guest PC 0x0c083542 */
if(!s->budget--) { s->failed_pc=0x0c083542u; return 0; }
goto P_0c083544;
P_0c083544: /* original d31c, guest PC 0x0c083544 */
if(!s->budget--) { s->failed_pc=0x0c083544u; return 0; }
r[3]=read(ram,0x0c0835b8u,4);
goto P_0c083546;
P_0c083546: /* original 65d3, guest PC 0x0c083546 */
if(!s->budget--) { s->failed_pc=0x0c083546u; return 0; }
r[5]=r[13];
goto P_0c083548;
P_0c083548: /* original 9634, guest PC 0x0c083548 */
if(!s->budget--) { s->failed_pc=0x0c083548u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b4u,2);
goto P_0c08354a;
P_0c08354a: /* original 430b, guest PC 0x0c08354a */
if(!s->budget--) { s->failed_pc=0x0c08354au; return 0; }
target=r[3];
r[16]=code_base|0x0c08354eu;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08354eu) { target=s->pc; goto dispatch; }
goto P_0c08354e;
P_0c08354c: /* original e412, guest PC 0x0c08354c */
if(!s->budget--) { s->failed_pc=0x0c08354cu; return 0; }
r[4]=0x00000012u;
goto P_0c08354e;
P_0c08354e: /* original 9630, guest PC 0x0c08354e */
if(!s->budget--) { s->failed_pc=0x0c08354eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b2u,2);
goto P_0c083550;
P_0c083550: /* original 65d3, guest PC 0x0c083550 */
if(!s->budget--) { s->failed_pc=0x0c083550u; return 0; }
r[5]=r[13];
goto P_0c083552;
P_0c083552: /* original d31a, guest PC 0x0c083552 */
if(!s->budget--) { s->failed_pc=0x0c083552u; return 0; }
r[3]=read(ram,0x0c0835bcu,4);
goto P_0c083554;
P_0c083554: /* original 36ec, guest PC 0x0c083554 */
if(!s->budget--) { s->failed_pc=0x0c083554u; return 0; }
r[6]+=r[14];
goto P_0c083556;
P_0c083556: /* original 36cc, guest PC 0x0c083556 */
if(!s->budget--) { s->failed_pc=0x0c083556u; return 0; }
r[6]+=r[12];
goto P_0c083558;
P_0c083558: /* original 5662, guest PC 0x0c083558 */
if(!s->budget--) { s->failed_pc=0x0c083558u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c08355a;
P_0c08355a: /* original 430b, guest PC 0x0c08355a */
if(!s->budget--) { s->failed_pc=0x0c08355au; return 0; }
target=r[3];
r[16]=code_base|0x0c08355eu;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08355eu) { target=s->pc; goto dispatch; }
goto P_0c08355e;
P_0c08355c: /* original e414, guest PC 0x0c08355c */
if(!s->budget--) { s->failed_pc=0x0c08355cu; return 0; }
r[4]=0x00000014u;
goto P_0c08355e;
P_0c08355e: /* original 6292, guest PC 0x0c08355e */
if(!s->budget--) { s->failed_pc=0x0c08355eu; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c083560;
P_0c083560: /* original 32b0, guest PC 0x0c083560 */
if(!s->budget--) { s->failed_pc=0x0c083560u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c083562;
P_0c083562: /* original 8b06, guest PC 0x0c083562 */
if(!s->budget--) { s->failed_pc=0x0c083562u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083572; }
goto P_0c083564;
P_0c083564: /* original 9625, guest PC 0x0c083564 */
if(!s->budget--) { s->failed_pc=0x0c083564u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b2u,2);
goto P_0c083566;
P_0c083566: /* original 55f1, guest PC 0x0c083566 */
if(!s->budget--) { s->failed_pc=0x0c083566u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c083568;
P_0c083568: /* original 36ec, guest PC 0x0c083568 */
if(!s->budget--) { s->failed_pc=0x0c083568u; return 0; }
r[6]+=r[14];
goto P_0c08356a;
P_0c08356a: /* original 36cc, guest PC 0x0c08356a */
if(!s->budget--) { s->failed_pc=0x0c08356au; return 0; }
r[6]+=r[12];
goto P_0c08356c;
P_0c08356c: /* original 5662, guest PC 0x0c08356c */
if(!s->budget--) { s->failed_pc=0x0c08356cu; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c08356e;
P_0c08356e: /* original a006, guest PC 0x0c08356e */
if(!s->budget--) { s->failed_pc=0x0c08356eu; return 0; }
r[4]=0x00000030u;
goto P_0c08357e;
P_0c083570: /* original e430, guest PC 0x0c083570 */
if(!s->budget--) { s->failed_pc=0x0c083570u; return 0; }
r[4]=0x00000030u;
goto P_0c083572;
P_0c083572: /* original 961e, guest PC 0x0c083572 */
if(!s->budget--) { s->failed_pc=0x0c083572u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b2u,2);
goto P_0c083574;
P_0c083574: /* original e433, guest PC 0x0c083574 */
if(!s->budget--) { s->failed_pc=0x0c083574u; return 0; }
r[4]=0x00000033u;
goto P_0c083576;
P_0c083576: /* original 65f2, guest PC 0x0c083576 */
if(!s->budget--) { s->failed_pc=0x0c083576u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083578;
P_0c083578: /* original 36ec, guest PC 0x0c083578 */
if(!s->budget--) { s->failed_pc=0x0c083578u; return 0; }
r[6]+=r[14];
goto P_0c08357a;
P_0c08357a: /* original 36cc, guest PC 0x0c08357a */
if(!s->budget--) { s->failed_pc=0x0c08357au; return 0; }
r[6]+=r[12];
goto P_0c08357c;
P_0c08357c: /* original 5662, guest PC 0x0c08357c */
if(!s->budget--) { s->failed_pc=0x0c08357cu; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c08357e;
P_0c08357e: /* original d30f, guest PC 0x0c08357e */
if(!s->budget--) { s->failed_pc=0x0c08357eu; return 0; }
r[3]=read(ram,0x0c0835bcu,4);
goto P_0c083580;
P_0c083580: /* original 430b, guest PC 0x0c083580 */
if(!s->budget--) { s->failed_pc=0x0c083580u; return 0; }
target=r[3];
r[16]=code_base|0x0c083584u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083584u) { target=s->pc; goto dispatch; }
goto P_0c083584;
P_0c083582: /* original 0009, guest PC 0x0c083582 */
if(!s->budget--) { s->failed_pc=0x0c083582u; return 0; }
goto P_0c083584;
P_0c083584: /* original a024, guest PC 0x0c083584 */
if(!s->budget--) { s->failed_pc=0x0c083584u; return 0; }
goto P_0c0835d0;
P_0c083586: /* original 0009, guest PC 0x0c083586 */
if(!s->budget--) { s->failed_pc=0x0c083586u; return 0; }
goto P_0c083588;
P_0c083588: /* original d30b, guest PC 0x0c083588 */
if(!s->budget--) { s->failed_pc=0x0c083588u; return 0; }
r[3]=read(ram,0x0c0835b8u,4);
goto P_0c08358a;
P_0c08358a: /* original 65d3, guest PC 0x0c08358a */
if(!s->budget--) { s->failed_pc=0x0c08358au; return 0; }
r[5]=r[13];
goto P_0c08358c;
P_0c08358c: /* original 9612, guest PC 0x0c08358c */
if(!s->budget--) { s->failed_pc=0x0c08358cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0835b4u,2);
goto P_0c08358e;
P_0c08358e: /* original 430b, guest PC 0x0c08358e */
if(!s->budget--) { s->failed_pc=0x0c08358eu; return 0; }
target=r[3];
r[16]=code_base|0x0c083592u;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083592u) { target=s->pc; goto dispatch; }
goto P_0c083592;
P_0c083590: /* original e412, guest PC 0x0c083590 */
if(!s->budget--) { s->failed_pc=0x0c083590u; return 0; }
r[4]=0x00000012u;
goto P_0c083592;
P_0c083592: /* original d20a, guest PC 0x0c083592 */
if(!s->budget--) { s->failed_pc=0x0c083592u; return 0; }
r[2]=read(ram,0x0c0835bcu,4);
goto P_0c083594;
P_0c083594: /* original 65d3, guest PC 0x0c083594 */
if(!s->budget--) { s->failed_pc=0x0c083594u; return 0; }
r[5]=r[13];
goto P_0c083596;
P_0c083596: /* original e608, guest PC 0x0c083596 */
if(!s->budget--) { s->failed_pc=0x0c083596u; return 0; }
r[6]=0x00000008u;
goto P_0c083598;
P_0c083598: /* original 420b, guest PC 0x0c083598 */
if(!s->budget--) { s->failed_pc=0x0c083598u; return 0; }
target=r[2];
r[16]=code_base|0x0c08359cu;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08359cu) { target=s->pc; goto dispatch; }
goto P_0c08359c;
P_0c08359a: /* original e407, guest PC 0x0c08359a */
if(!s->budget--) { s->failed_pc=0x0c08359au; return 0; }
r[4]=0x00000007u;
goto P_0c08359c;
P_0c08359c: /* original 6392, guest PC 0x0c08359c */
if(!s->budget--) { s->failed_pc=0x0c08359cu; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c08359e;
P_0c08359e: /* original 33b0, guest PC 0x0c08359e */
if(!s->budget--) { s->failed_pc=0x0c08359eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[11])!=0);
goto P_0c0835a0;
P_0c0835a0: /* original 8b10, guest PC 0x0c0835a0 */
if(!s->budget--) { s->failed_pc=0x0c0835a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0835c4; }
goto P_0c0835a2;
P_0c0835a2: /* original 55f1, guest PC 0x0c0835a2 */
if(!s->budget--) { s->failed_pc=0x0c0835a2u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0835a4;
P_0c0835a4: /* original e608, guest PC 0x0c0835a4 */
if(!s->budget--) { s->failed_pc=0x0c0835a4u; return 0; }
r[6]=0x00000008u;
goto P_0c0835a6;
P_0c0835a6: /* original a010, guest PC 0x0c0835a6 */
if(!s->budget--) { s->failed_pc=0x0c0835a6u; return 0; }
r[4]=0x00000030u;
goto P_0c0835ca;
P_0c0835a8: /* original e430, guest PC 0x0c0835a8 */
if(!s->budget--) { s->failed_pc=0x0c0835a8u; return 0; }
r[4]=0x00000030u;
return vf3_matrix_family(0x0c0835aau,s,ram);
P_0c0835c4: /* original 65f2, guest PC 0x0c0835c4 */
if(!s->budget--) { s->failed_pc=0x0c0835c4u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0835c6;
P_0c0835c6: /* original e433, guest PC 0x0c0835c6 */
if(!s->budget--) { s->failed_pc=0x0c0835c6u; return 0; }
r[4]=0x00000033u;
goto P_0c0835c8;
P_0c0835c8: /* original e608, guest PC 0x0c0835c8 */
if(!s->budget--) { s->failed_pc=0x0c0835c8u; return 0; }
r[6]=0x00000008u;
goto P_0c0835ca;
P_0c0835ca: /* original d346, guest PC 0x0c0835ca */
if(!s->budget--) { s->failed_pc=0x0c0835cau; return 0; }
r[3]=read(ram,0x0c0836e4u,4);
goto P_0c0835cc;
P_0c0835cc: /* original 430b, guest PC 0x0c0835cc */
if(!s->budget--) { s->failed_pc=0x0c0835ccu; return 0; }
target=r[3];
r[16]=code_base|0x0c0835d0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0835d0u) { target=s->pc; goto dispatch; }
goto P_0c0835d0;
P_0c0835ce: /* original 0009, guest PC 0x0c0835ce */
if(!s->budget--) { s->failed_pc=0x0c0835ceu; return 0; }
goto P_0c0835d0;
P_0c0835d0: /* original 6292, guest PC 0x0c0835d0 */
if(!s->budget--) { s->failed_pc=0x0c0835d0u; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c0835d2;
P_0c0835d2: /* original 32b0, guest PC 0x0c0835d2 */
if(!s->budget--) { s->failed_pc=0x0c0835d2u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c0835d4;
P_0c0835d4: /* original 8b4b, guest PC 0x0c0835d4 */
if(!s->budget--) { s->failed_pc=0x0c0835d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08366e; }
goto P_0c0835d6;
P_0c0835d6: /* original 937e, guest PC 0x0c0835d6 */
if(!s->budget--) { s->failed_pc=0x0c0835d6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836d6u,2);
goto P_0c0835d8;
P_0c0835d8: /* original 60a3, guest PC 0x0c0835d8 */
if(!s->budget--) { s->failed_pc=0x0c0835d8u; return 0; }
r[0]=r[10];
goto P_0c0835da;
P_0c0835da: /* original 4008, guest PC 0x0c0835da */
if(!s->budget--) { s->failed_pc=0x0c0835dau; return 0; }
r[0]<<=2;
goto P_0c0835dc;
P_0c0835dc: /* original 33ec, guest PC 0x0c0835dc */
if(!s->budget--) { s->failed_pc=0x0c0835dcu; return 0; }
r[3]+=r[14];
goto P_0c0835de;
P_0c0835de: /* original 003e, guest PC 0x0c0835de */
if(!s->budget--) { s->failed_pc=0x0c0835deu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0835e0;
P_0c0835e0: /* original 8801, guest PC 0x0c0835e0 */
if(!s->budget--) { s->failed_pc=0x0c0835e0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0835e2;
P_0c0835e2: /* original 8f35, guest PC 0x0c0835e2 */
if(!s->budget--) { s->failed_pc=0x0c0835e2u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c083650; }
goto P_0c0835e6;
P_0c0835e4: /* original 7d02, guest PC 0x0c0835e4 */
if(!s->budget--) { s->failed_pc=0x0c0835e4u; return 0; }
r[13]+=0x00000002u;
goto P_0c0835e6;
P_0c0835e6: /* original 9377, guest PC 0x0c0835e6 */
if(!s->budget--) { s->failed_pc=0x0c0835e6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836d8u,2);
goto P_0c0835e8;
P_0c0835e8: /* original 60a3, guest PC 0x0c0835e8 */
if(!s->budget--) { s->failed_pc=0x0c0835e8u; return 0; }
r[0]=r[10];
goto P_0c0835ea;
P_0c0835ea: /* original 4008, guest PC 0x0c0835ea */
if(!s->budget--) { s->failed_pc=0x0c0835eau; return 0; }
r[0]<<=2;
goto P_0c0835ec;
P_0c0835ec: /* original 33ec, guest PC 0x0c0835ec */
if(!s->budget--) { s->failed_pc=0x0c0835ecu; return 0; }
r[3]+=r[14];
goto P_0c0835ee;
P_0c0835ee: /* original 003e, guest PC 0x0c0835ee */
if(!s->budget--) { s->failed_pc=0x0c0835eeu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0835f0;
P_0c0835f0: /* original 8803, guest PC 0x0c0835f0 */
if(!s->budget--) { s->failed_pc=0x0c0835f0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0835f2;
P_0c0835f2: /* original 8b16, guest PC 0x0c0835f2 */
if(!s->budget--) { s->failed_pc=0x0c0835f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083622; }
goto P_0c0835f4;
P_0c0835f4: /* original d33c, guest PC 0x0c0835f4 */
if(!s->budget--) { s->failed_pc=0x0c0835f4u; return 0; }
r[3]=read(ram,0x0c0836e8u,4);
goto P_0c0835f6;
P_0c0835f6: /* original 65d3, guest PC 0x0c0835f6 */
if(!s->budget--) { s->failed_pc=0x0c0835f6u; return 0; }
r[5]=r[13];
goto P_0c0835f8;
P_0c0835f8: /* original 966f, guest PC 0x0c0835f8 */
if(!s->budget--) { s->failed_pc=0x0c0835f8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dau,2);
goto P_0c0835fa;
P_0c0835fa: /* original 430b, guest PC 0x0c0835fa */
if(!s->budget--) { s->failed_pc=0x0c0835fau; return 0; }
target=r[3];
r[16]=code_base|0x0c0835feu;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0835feu) { target=s->pc; goto dispatch; }
goto P_0c0835fe;
P_0c0835fc: /* original e412, guest PC 0x0c0835fc */
if(!s->budget--) { s->failed_pc=0x0c0835fcu; return 0; }
r[4]=0x00000012u;
goto P_0c0835fe;
P_0c0835fe: /* original 966d, guest PC 0x0c0835fe */
if(!s->budget--) { s->failed_pc=0x0c0835feu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dcu,2);
goto P_0c083600;
P_0c083600: /* original 65d3, guest PC 0x0c083600 */
if(!s->budget--) { s->failed_pc=0x0c083600u; return 0; }
r[5]=r[13];
goto P_0c083602;
P_0c083602: /* original d33a, guest PC 0x0c083602 */
if(!s->budget--) { s->failed_pc=0x0c083602u; return 0; }
r[3]=read(ram,0x0c0836ecu,4);
goto P_0c083604;
P_0c083604: /* original 36ec, guest PC 0x0c083604 */
if(!s->budget--) { s->failed_pc=0x0c083604u; return 0; }
r[6]+=r[14];
goto P_0c083606;
P_0c083606: /* original 36cc, guest PC 0x0c083606 */
if(!s->budget--) { s->failed_pc=0x0c083606u; return 0; }
r[6]+=r[12];
goto P_0c083608;
P_0c083608: /* original 5663, guest PC 0x0c083608 */
if(!s->budget--) { s->failed_pc=0x0c083608u; return 0; }
r[6]=read(ram,r[6]+12,4);
goto P_0c08360a;
P_0c08360a: /* original 430b, guest PC 0x0c08360a */
if(!s->budget--) { s->failed_pc=0x0c08360au; return 0; }
target=r[3];
r[16]=code_base|0x0c08360eu;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08360eu) { target=s->pc; goto dispatch; }
goto P_0c08360e;
P_0c08360c: /* original e414, guest PC 0x0c08360c */
if(!s->budget--) { s->failed_pc=0x0c08360cu; return 0; }
r[4]=0x00000014u;
goto P_0c08360e;
P_0c08360e: /* original 9665, guest PC 0x0c08360e */
if(!s->budget--) { s->failed_pc=0x0c08360eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dcu,2);
goto P_0c083610;
P_0c083610: /* original d336, guest PC 0x0c083610 */
if(!s->budget--) { s->failed_pc=0x0c083610u; return 0; }
r[3]=read(ram,0x0c0836ecu,4);
goto P_0c083612;
P_0c083612: /* original 36ec, guest PC 0x0c083612 */
if(!s->budget--) { s->failed_pc=0x0c083612u; return 0; }
r[6]+=r[14];
goto P_0c083614;
P_0c083614: /* original 65f2, guest PC 0x0c083614 */
if(!s->budget--) { s->failed_pc=0x0c083614u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083616;
P_0c083616: /* original 36cc, guest PC 0x0c083616 */
if(!s->budget--) { s->failed_pc=0x0c083616u; return 0; }
r[6]+=r[12];
goto P_0c083618;
P_0c083618: /* original 5663, guest PC 0x0c083618 */
if(!s->budget--) { s->failed_pc=0x0c083618u; return 0; }
r[6]=read(ram,r[6]+12,4);
goto P_0c08361a;
P_0c08361a: /* original 430b, guest PC 0x0c08361a */
if(!s->budget--) { s->failed_pc=0x0c08361au; return 0; }
target=r[3];
r[16]=code_base|0x0c08361eu;
r[4]=0x00000034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08361eu) { target=s->pc; goto dispatch; }
goto P_0c08361e;
P_0c08361c: /* original e434, guest PC 0x0c08361c */
if(!s->budget--) { s->failed_pc=0x0c08361cu; return 0; }
r[4]=0x00000034u;
goto P_0c08361e;
P_0c08361e: /* original a026, guest PC 0x0c08361e */
if(!s->budget--) { s->failed_pc=0x0c08361eu; return 0; }
goto P_0c08366e;
P_0c083620: /* original 0009, guest PC 0x0c083620 */
if(!s->budget--) { s->failed_pc=0x0c083620u; return 0; }
goto P_0c083622;
P_0c083622: /* original d331, guest PC 0x0c083622 */
if(!s->budget--) { s->failed_pc=0x0c083622u; return 0; }
r[3]=read(ram,0x0c0836e8u,4);
goto P_0c083624;
P_0c083624: /* original 65d3, guest PC 0x0c083624 */
if(!s->budget--) { s->failed_pc=0x0c083624u; return 0; }
r[5]=r[13];
goto P_0c083626;
P_0c083626: /* original 965a, guest PC 0x0c083626 */
if(!s->budget--) { s->failed_pc=0x0c083626u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836deu,2);
goto P_0c083628;
P_0c083628: /* original 430b, guest PC 0x0c083628 */
if(!s->budget--) { s->failed_pc=0x0c083628u; return 0; }
target=r[3];
r[16]=code_base|0x0c08362cu;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08362cu) { target=s->pc; goto dispatch; }
goto P_0c08362c;
P_0c08362a: /* original e412, guest PC 0x0c08362a */
if(!s->budget--) { s->failed_pc=0x0c08362au; return 0; }
r[4]=0x00000012u;
goto P_0c08362c;
P_0c08362c: /* original 9656, guest PC 0x0c08362c */
if(!s->budget--) { s->failed_pc=0x0c08362cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dcu,2);
goto P_0c08362e;
P_0c08362e: /* original 65d3, guest PC 0x0c08362e */
if(!s->budget--) { s->failed_pc=0x0c08362eu; return 0; }
r[5]=r[13];
goto P_0c083630;
P_0c083630: /* original d32c, guest PC 0x0c083630 */
if(!s->budget--) { s->failed_pc=0x0c083630u; return 0; }
r[3]=read(ram,0x0c0836e4u,4);
goto P_0c083632;
P_0c083632: /* original 36ec, guest PC 0x0c083632 */
if(!s->budget--) { s->failed_pc=0x0c083632u; return 0; }
r[6]+=r[14];
goto P_0c083634;
P_0c083634: /* original 36cc, guest PC 0x0c083634 */
if(!s->budget--) { s->failed_pc=0x0c083634u; return 0; }
r[6]+=r[12];
goto P_0c083636;
P_0c083636: /* original 5663, guest PC 0x0c083636 */
if(!s->budget--) { s->failed_pc=0x0c083636u; return 0; }
r[6]=read(ram,r[6]+12,4);
goto P_0c083638;
P_0c083638: /* original 430b, guest PC 0x0c083638 */
if(!s->budget--) { s->failed_pc=0x0c083638u; return 0; }
target=r[3];
r[16]=code_base|0x0c08363cu;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08363cu) { target=s->pc; goto dispatch; }
goto P_0c08363c;
P_0c08363a: /* original e414, guest PC 0x0c08363a */
if(!s->budget--) { s->failed_pc=0x0c08363au; return 0; }
r[4]=0x00000014u;
goto P_0c08363c;
P_0c08363c: /* original 964e, guest PC 0x0c08363c */
if(!s->budget--) { s->failed_pc=0x0c08363cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dcu,2);
goto P_0c08363e;
P_0c08363e: /* original d329, guest PC 0x0c08363e */
if(!s->budget--) { s->failed_pc=0x0c08363eu; return 0; }
r[3]=read(ram,0x0c0836e4u,4);
goto P_0c083640;
P_0c083640: /* original 36ec, guest PC 0x0c083640 */
if(!s->budget--) { s->failed_pc=0x0c083640u; return 0; }
r[6]+=r[14];
goto P_0c083642;
P_0c083642: /* original 65f2, guest PC 0x0c083642 */
if(!s->budget--) { s->failed_pc=0x0c083642u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083644;
P_0c083644: /* original 36cc, guest PC 0x0c083644 */
if(!s->budget--) { s->failed_pc=0x0c083644u; return 0; }
r[6]+=r[12];
goto P_0c083646;
P_0c083646: /* original 5663, guest PC 0x0c083646 */
if(!s->budget--) { s->failed_pc=0x0c083646u; return 0; }
r[6]=read(ram,r[6]+12,4);
goto P_0c083648;
P_0c083648: /* original 430b, guest PC 0x0c083648 */
if(!s->budget--) { s->failed_pc=0x0c083648u; return 0; }
target=r[3];
r[16]=code_base|0x0c08364cu;
r[4]=0x00000034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08364cu) { target=s->pc; goto dispatch; }
goto P_0c08364c;
P_0c08364a: /* original e434, guest PC 0x0c08364a */
if(!s->budget--) { s->failed_pc=0x0c08364au; return 0; }
r[4]=0x00000034u;
goto P_0c08364c;
P_0c08364c: /* original a00f, guest PC 0x0c08364c */
if(!s->budget--) { s->failed_pc=0x0c08364cu; return 0; }
goto P_0c08366e;
P_0c08364e: /* original 0009, guest PC 0x0c08364e */
if(!s->budget--) { s->failed_pc=0x0c08364eu; return 0; }
goto P_0c083650;
P_0c083650: /* original d325, guest PC 0x0c083650 */
if(!s->budget--) { s->failed_pc=0x0c083650u; return 0; }
r[3]=read(ram,0x0c0836e8u,4);
goto P_0c083652;
P_0c083652: /* original 65d3, guest PC 0x0c083652 */
if(!s->budget--) { s->failed_pc=0x0c083652u; return 0; }
r[5]=r[13];
goto P_0c083654;
P_0c083654: /* original 9643, guest PC 0x0c083654 */
if(!s->budget--) { s->failed_pc=0x0c083654u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836deu,2);
goto P_0c083656;
P_0c083656: /* original 430b, guest PC 0x0c083656 */
if(!s->budget--) { s->failed_pc=0x0c083656u; return 0; }
target=r[3];
r[16]=code_base|0x0c08365au;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08365au) { target=s->pc; goto dispatch; }
goto P_0c08365a;
P_0c083658: /* original e412, guest PC 0x0c083658 */
if(!s->budget--) { s->failed_pc=0x0c083658u; return 0; }
r[4]=0x00000012u;
goto P_0c08365a;
P_0c08365a: /* original d222, guest PC 0x0c08365a */
if(!s->budget--) { s->failed_pc=0x0c08365au; return 0; }
r[2]=read(ram,0x0c0836e4u,4);
goto P_0c08365c;
P_0c08365c: /* original 65d3, guest PC 0x0c08365c */
if(!s->budget--) { s->failed_pc=0x0c08365cu; return 0; }
r[5]=r[13];
goto P_0c08365e;
P_0c08365e: /* original e610, guest PC 0x0c08365e */
if(!s->budget--) { s->failed_pc=0x0c08365eu; return 0; }
r[6]=0x00000010u;
goto P_0c083660;
P_0c083660: /* original 420b, guest PC 0x0c083660 */
if(!s->budget--) { s->failed_pc=0x0c083660u; return 0; }
target=r[2];
r[16]=code_base|0x0c083664u;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083664u) { target=s->pc; goto dispatch; }
goto P_0c083664;
P_0c083662: /* original e407, guest PC 0x0c083662 */
if(!s->budget--) { s->failed_pc=0x0c083662u; return 0; }
r[4]=0x00000007u;
goto P_0c083664;
P_0c083664: /* original d31f, guest PC 0x0c083664 */
if(!s->budget--) { s->failed_pc=0x0c083664u; return 0; }
r[3]=read(ram,0x0c0836e4u,4);
goto P_0c083666;
P_0c083666: /* original e610, guest PC 0x0c083666 */
if(!s->budget--) { s->failed_pc=0x0c083666u; return 0; }
r[6]=0x00000010u;
goto P_0c083668;
P_0c083668: /* original 65f2, guest PC 0x0c083668 */
if(!s->budget--) { s->failed_pc=0x0c083668u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08366a;
P_0c08366a: /* original 430b, guest PC 0x0c08366a */
if(!s->budget--) { s->failed_pc=0x0c08366au; return 0; }
target=r[3];
r[16]=code_base|0x0c08366eu;
r[4]=0x00000034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08366eu) { target=s->pc; goto dispatch; }
goto P_0c08366e;
P_0c08366c: /* original e434, guest PC 0x0c08366c */
if(!s->budget--) { s->failed_pc=0x0c08366cu; return 0; }
r[4]=0x00000034u;
goto P_0c08366e;
P_0c08366e: /* original 60a3, guest PC 0x0c08366e */
if(!s->budget--) { s->failed_pc=0x0c08366eu; return 0; }
r[0]=r[10];
goto P_0c083670;
P_0c083670: /* original 4008, guest PC 0x0c083670 */
if(!s->budget--) { s->failed_pc=0x0c083670u; return 0; }
r[0]<<=2;
goto P_0c083672;
P_0c083672: /* original 6283, guest PC 0x0c083672 */
if(!s->budget--) { s->failed_pc=0x0c083672u; return 0; }
r[2]=r[8];
goto P_0c083674;
P_0c083674: /* original 720c, guest PC 0x0c083674 */
if(!s->budget--) { s->failed_pc=0x0c083674u; return 0; }
r[2]+=0x0000000cu;
goto P_0c083676;
P_0c083676: /* original 1f21, guest PC 0x0c083676 */
if(!s->budget--) { s->failed_pc=0x0c083676u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c083678;
P_0c083678: /* original 932d, guest PC 0x0c083678 */
if(!s->budget--) { s->failed_pc=0x0c083678u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836d6u,2);
goto P_0c08367a;
P_0c08367a: /* original 33ec, guest PC 0x0c08367a */
if(!s->budget--) { s->failed_pc=0x0c08367au; return 0; }
r[3]+=r[14];
goto P_0c08367c;
P_0c08367c: /* original 003e, guest PC 0x0c08367c */
if(!s->budget--) { s->failed_pc=0x0c08367cu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c08367e;
P_0c08367e: /* original 8801, guest PC 0x0c08367e */
if(!s->budget--) { s->failed_pc=0x0c08367eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c083680;
P_0c083680: /* original 8f58, guest PC 0x0c083680 */
if(!s->budget--) { s->failed_pc=0x0c083680u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c083734; }
goto P_0c083684;
P_0c083682: /* original 7d02, guest PC 0x0c083682 */
if(!s->budget--) { s->failed_pc=0x0c083682u; return 0; }
r[13]+=0x00000002u;
goto P_0c083684;
P_0c083684: /* original 9328, guest PC 0x0c083684 */
if(!s->budget--) { s->failed_pc=0x0c083684u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836d8u,2);
goto P_0c083686;
P_0c083686: /* original 60a3, guest PC 0x0c083686 */
if(!s->budget--) { s->failed_pc=0x0c083686u; return 0; }
r[0]=r[10];
goto P_0c083688;
P_0c083688: /* original 4008, guest PC 0x0c083688 */
if(!s->budget--) { s->failed_pc=0x0c083688u; return 0; }
r[0]<<=2;
goto P_0c08368a;
P_0c08368a: /* original 33ec, guest PC 0x0c08368a */
if(!s->budget--) { s->failed_pc=0x0c08368au; return 0; }
r[3]+=r[14];
goto P_0c08368c;
P_0c08368c: /* original 003e, guest PC 0x0c08368c */
if(!s->budget--) { s->failed_pc=0x0c08368cu; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c08368e;
P_0c08368e: /* original 8804, guest PC 0x0c08368e */
if(!s->budget--) { s->failed_pc=0x0c08368eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c083690;
P_0c083690: /* original 8b2e, guest PC 0x0c083690 */
if(!s->budget--) { s->failed_pc=0x0c083690u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0836f0; }
goto P_0c083692;
P_0c083692: /* original d315, guest PC 0x0c083692 */
if(!s->budget--) { s->failed_pc=0x0c083692u; return 0; }
r[3]=read(ram,0x0c0836e8u,4);
goto P_0c083694;
P_0c083694: /* original 65d3, guest PC 0x0c083694 */
if(!s->budget--) { s->failed_pc=0x0c083694u; return 0; }
r[5]=r[13];
goto P_0c083696;
P_0c083696: /* original 9623, guest PC 0x0c083696 */
if(!s->budget--) { s->failed_pc=0x0c083696u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836e0u,2);
goto P_0c083698;
P_0c083698: /* original 430b, guest PC 0x0c083698 */
if(!s->budget--) { s->failed_pc=0x0c083698u; return 0; }
target=r[3];
r[16]=code_base|0x0c08369cu;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08369cu) { target=s->pc; goto dispatch; }
goto P_0c08369c;
P_0c08369a: /* original e412, guest PC 0x0c08369a */
if(!s->budget--) { s->failed_pc=0x0c08369au; return 0; }
r[4]=0x00000012u;
goto P_0c08369c;
P_0c08369c: /* original 961e, guest PC 0x0c08369c */
if(!s->budget--) { s->failed_pc=0x0c08369cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dcu,2);
goto P_0c08369e;
P_0c08369e: /* original 65d3, guest PC 0x0c08369e */
if(!s->budget--) { s->failed_pc=0x0c08369eu; return 0; }
r[5]=r[13];
goto P_0c0836a0;
P_0c0836a0: /* original d312, guest PC 0x0c0836a0 */
if(!s->budget--) { s->failed_pc=0x0c0836a0u; return 0; }
r[3]=read(ram,0x0c0836ecu,4);
goto P_0c0836a2;
P_0c0836a2: /* original 36ec, guest PC 0x0c0836a2 */
if(!s->budget--) { s->failed_pc=0x0c0836a2u; return 0; }
r[6]+=r[14];
goto P_0c0836a4;
P_0c0836a4: /* original 36cc, guest PC 0x0c0836a4 */
if(!s->budget--) { s->failed_pc=0x0c0836a4u; return 0; }
r[6]+=r[12];
goto P_0c0836a6;
P_0c0836a6: /* original 5664, guest PC 0x0c0836a6 */
if(!s->budget--) { s->failed_pc=0x0c0836a6u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0836a8;
P_0c0836a8: /* original 430b, guest PC 0x0c0836a8 */
if(!s->budget--) { s->failed_pc=0x0c0836a8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0836acu;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0836acu) { target=s->pc; goto dispatch; }
goto P_0c0836ac;
P_0c0836aa: /* original e414, guest PC 0x0c0836aa */
if(!s->budget--) { s->failed_pc=0x0c0836aau; return 0; }
r[4]=0x00000014u;
goto P_0c0836ac;
P_0c0836ac: /* original 6292, guest PC 0x0c0836ac */
if(!s->budget--) { s->failed_pc=0x0c0836acu; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c0836ae;
P_0c0836ae: /* original 32b0, guest PC 0x0c0836ae */
if(!s->budget--) { s->failed_pc=0x0c0836aeu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c0836b0;
P_0c0836b0: /* original 8b06, guest PC 0x0c0836b0 */
if(!s->budget--) { s->failed_pc=0x0c0836b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0836c0; }
goto P_0c0836b2;
P_0c0836b2: /* original 9613, guest PC 0x0c0836b2 */
if(!s->budget--) { s->failed_pc=0x0c0836b2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dcu,2);
goto P_0c0836b4;
P_0c0836b4: /* original 55f1, guest PC 0x0c0836b4 */
if(!s->budget--) { s->failed_pc=0x0c0836b4u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0836b6;
P_0c0836b6: /* original 36ec, guest PC 0x0c0836b6 */
if(!s->budget--) { s->failed_pc=0x0c0836b6u; return 0; }
r[6]+=r[14];
goto P_0c0836b8;
P_0c0836b8: /* original 36cc, guest PC 0x0c0836b8 */
if(!s->budget--) { s->failed_pc=0x0c0836b8u; return 0; }
r[6]+=r[12];
goto P_0c0836ba;
P_0c0836ba: /* original 5664, guest PC 0x0c0836ba */
if(!s->budget--) { s->failed_pc=0x0c0836bau; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0836bc;
P_0c0836bc: /* original a006, guest PC 0x0c0836bc */
if(!s->budget--) { s->failed_pc=0x0c0836bcu; return 0; }
r[4]=0x00000027u;
goto P_0c0836cc;
P_0c0836be: /* original e427, guest PC 0x0c0836be */
if(!s->budget--) { s->failed_pc=0x0c0836beu; return 0; }
r[4]=0x00000027u;
goto P_0c0836c0;
P_0c0836c0: /* original 960c, guest PC 0x0c0836c0 */
if(!s->budget--) { s->failed_pc=0x0c0836c0u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0836dcu,2);
goto P_0c0836c2;
P_0c0836c2: /* original e428, guest PC 0x0c0836c2 */
if(!s->budget--) { s->failed_pc=0x0c0836c2u; return 0; }
r[4]=0x00000028u;
goto P_0c0836c4;
P_0c0836c4: /* original 65f2, guest PC 0x0c0836c4 */
if(!s->budget--) { s->failed_pc=0x0c0836c4u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0836c6;
P_0c0836c6: /* original 36ec, guest PC 0x0c0836c6 */
if(!s->budget--) { s->failed_pc=0x0c0836c6u; return 0; }
r[6]+=r[14];
goto P_0c0836c8;
P_0c0836c8: /* original 36cc, guest PC 0x0c0836c8 */
if(!s->budget--) { s->failed_pc=0x0c0836c8u; return 0; }
r[6]+=r[12];
goto P_0c0836ca;
P_0c0836ca: /* original 5664, guest PC 0x0c0836ca */
if(!s->budget--) { s->failed_pc=0x0c0836cau; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0836cc;
P_0c0836cc: /* original d307, guest PC 0x0c0836cc */
if(!s->budget--) { s->failed_pc=0x0c0836ccu; return 0; }
r[3]=read(ram,0x0c0836ecu,4);
goto P_0c0836ce;
P_0c0836ce: /* original 430b, guest PC 0x0c0836ce */
if(!s->budget--) { s->failed_pc=0x0c0836ceu; return 0; }
target=r[3];
r[16]=code_base|0x0c0836d2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0836d2u) { target=s->pc; goto dispatch; }
goto P_0c0836d2;
P_0c0836d0: /* original 0009, guest PC 0x0c0836d0 */
if(!s->budget--) { s->failed_pc=0x0c0836d0u; return 0; }
goto P_0c0836d2;
P_0c0836d2: /* original a046, guest PC 0x0c0836d2 */
if(!s->budget--) { s->failed_pc=0x0c0836d2u; return 0; }
goto P_0c083762;
P_0c0836d4: /* original 0009, guest PC 0x0c0836d4 */
if(!s->budget--) { s->failed_pc=0x0c0836d4u; return 0; }
return vf3_matrix_family(0x0c0836d6u,s,ram);
P_0c0836f0: /* original d343, guest PC 0x0c0836f0 */
if(!s->budget--) { s->failed_pc=0x0c0836f0u; return 0; }
r[3]=read(ram,0x0c083800u,4);
goto P_0c0836f2;
P_0c0836f2: /* original 65d3, guest PC 0x0c0836f2 */
if(!s->budget--) { s->failed_pc=0x0c0836f2u; return 0; }
r[5]=r[13];
goto P_0c0836f4;
P_0c0836f4: /* original 967d, guest PC 0x0c0836f4 */
if(!s->budget--) { s->failed_pc=0x0c0836f4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f2u,2);
goto P_0c0836f6;
P_0c0836f6: /* original 430b, guest PC 0x0c0836f6 */
if(!s->budget--) { s->failed_pc=0x0c0836f6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0836fau;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0836fau) { target=s->pc; goto dispatch; }
goto P_0c0836fa;
P_0c0836f8: /* original e412, guest PC 0x0c0836f8 */
if(!s->budget--) { s->failed_pc=0x0c0836f8u; return 0; }
r[4]=0x00000012u;
goto P_0c0836fa;
P_0c0836fa: /* original 967b, guest PC 0x0c0836fa */
if(!s->budget--) { s->failed_pc=0x0c0836fau; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c0836fc;
P_0c0836fc: /* original 65d3, guest PC 0x0c0836fc */
if(!s->budget--) { s->failed_pc=0x0c0836fcu; return 0; }
r[5]=r[13];
goto P_0c0836fe;
P_0c0836fe: /* original d341, guest PC 0x0c0836fe */
if(!s->budget--) { s->failed_pc=0x0c0836feu; return 0; }
r[3]=read(ram,0x0c083804u,4);
goto P_0c083700;
P_0c083700: /* original 36ec, guest PC 0x0c083700 */
if(!s->budget--) { s->failed_pc=0x0c083700u; return 0; }
r[6]+=r[14];
goto P_0c083702;
P_0c083702: /* original 36cc, guest PC 0x0c083702 */
if(!s->budget--) { s->failed_pc=0x0c083702u; return 0; }
r[6]+=r[12];
goto P_0c083704;
P_0c083704: /* original 5664, guest PC 0x0c083704 */
if(!s->budget--) { s->failed_pc=0x0c083704u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c083706;
P_0c083706: /* original 430b, guest PC 0x0c083706 */
if(!s->budget--) { s->failed_pc=0x0c083706u; return 0; }
target=r[3];
r[16]=code_base|0x0c08370au;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08370au) { target=s->pc; goto dispatch; }
goto P_0c08370a;
P_0c083708: /* original e414, guest PC 0x0c083708 */
if(!s->budget--) { s->failed_pc=0x0c083708u; return 0; }
r[4]=0x00000014u;
goto P_0c08370a;
P_0c08370a: /* original 6292, guest PC 0x0c08370a */
if(!s->budget--) { s->failed_pc=0x0c08370au; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c08370c;
P_0c08370c: /* original 32b0, guest PC 0x0c08370c */
if(!s->budget--) { s->failed_pc=0x0c08370cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c08370e;
P_0c08370e: /* original 8b06, guest PC 0x0c08370e */
if(!s->budget--) { s->failed_pc=0x0c08370eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08371e; }
goto P_0c083710;
P_0c083710: /* original 9670, guest PC 0x0c083710 */
if(!s->budget--) { s->failed_pc=0x0c083710u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c083712;
P_0c083712: /* original 55f1, guest PC 0x0c083712 */
if(!s->budget--) { s->failed_pc=0x0c083712u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c083714;
P_0c083714: /* original 36ec, guest PC 0x0c083714 */
if(!s->budget--) { s->failed_pc=0x0c083714u; return 0; }
r[6]+=r[14];
goto P_0c083716;
P_0c083716: /* original 36cc, guest PC 0x0c083716 */
if(!s->budget--) { s->failed_pc=0x0c083716u; return 0; }
r[6]+=r[12];
goto P_0c083718;
P_0c083718: /* original 5664, guest PC 0x0c083718 */
if(!s->budget--) { s->failed_pc=0x0c083718u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c08371a;
P_0c08371a: /* original a006, guest PC 0x0c08371a */
if(!s->budget--) { s->failed_pc=0x0c08371au; return 0; }
r[4]=0x00000027u;
goto P_0c08372a;
P_0c08371c: /* original e427, guest PC 0x0c08371c */
if(!s->budget--) { s->failed_pc=0x0c08371cu; return 0; }
r[4]=0x00000027u;
goto P_0c08371e;
P_0c08371e: /* original 9669, guest PC 0x0c08371e */
if(!s->budget--) { s->failed_pc=0x0c08371eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c083720;
P_0c083720: /* original e428, guest PC 0x0c083720 */
if(!s->budget--) { s->failed_pc=0x0c083720u; return 0; }
r[4]=0x00000028u;
goto P_0c083722;
P_0c083722: /* original 65f2, guest PC 0x0c083722 */
if(!s->budget--) { s->failed_pc=0x0c083722u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083724;
P_0c083724: /* original 36ec, guest PC 0x0c083724 */
if(!s->budget--) { s->failed_pc=0x0c083724u; return 0; }
r[6]+=r[14];
goto P_0c083726;
P_0c083726: /* original 36cc, guest PC 0x0c083726 */
if(!s->budget--) { s->failed_pc=0x0c083726u; return 0; }
r[6]+=r[12];
goto P_0c083728;
P_0c083728: /* original 5664, guest PC 0x0c083728 */
if(!s->budget--) { s->failed_pc=0x0c083728u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c08372a;
P_0c08372a: /* original d336, guest PC 0x0c08372a */
if(!s->budget--) { s->failed_pc=0x0c08372au; return 0; }
r[3]=read(ram,0x0c083804u,4);
goto P_0c08372c;
P_0c08372c: /* original 430b, guest PC 0x0c08372c */
if(!s->budget--) { s->failed_pc=0x0c08372cu; return 0; }
target=r[3];
r[16]=code_base|0x0c083730u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083730u) { target=s->pc; goto dispatch; }
goto P_0c083730;
P_0c08372e: /* original 0009, guest PC 0x0c08372e */
if(!s->budget--) { s->failed_pc=0x0c08372eu; return 0; }
goto P_0c083730;
P_0c083730: /* original a017, guest PC 0x0c083730 */
if(!s->budget--) { s->failed_pc=0x0c083730u; return 0; }
goto P_0c083762;
P_0c083732: /* original 0009, guest PC 0x0c083732 */
if(!s->budget--) { s->failed_pc=0x0c083732u; return 0; }
goto P_0c083734;
P_0c083734: /* original d332, guest PC 0x0c083734 */
if(!s->budget--) { s->failed_pc=0x0c083734u; return 0; }
r[3]=read(ram,0x0c083800u,4);
goto P_0c083736;
P_0c083736: /* original 65d3, guest PC 0x0c083736 */
if(!s->budget--) { s->failed_pc=0x0c083736u; return 0; }
r[5]=r[13];
goto P_0c083738;
P_0c083738: /* original 965b, guest PC 0x0c083738 */
if(!s->budget--) { s->failed_pc=0x0c083738u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f2u,2);
goto P_0c08373a;
P_0c08373a: /* original 430b, guest PC 0x0c08373a */
if(!s->budget--) { s->failed_pc=0x0c08373au; return 0; }
target=r[3];
r[16]=code_base|0x0c08373eu;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08373eu) { target=s->pc; goto dispatch; }
goto P_0c08373e;
P_0c08373c: /* original e412, guest PC 0x0c08373c */
if(!s->budget--) { s->failed_pc=0x0c08373cu; return 0; }
r[4]=0x00000012u;
goto P_0c08373e;
P_0c08373e: /* original d231, guest PC 0x0c08373e */
if(!s->budget--) { s->failed_pc=0x0c08373eu; return 0; }
r[2]=read(ram,0x0c083804u,4);
goto P_0c083740;
P_0c083740: /* original 65d3, guest PC 0x0c083740 */
if(!s->budget--) { s->failed_pc=0x0c083740u; return 0; }
r[5]=r[13];
goto P_0c083742;
P_0c083742: /* original e601, guest PC 0x0c083742 */
if(!s->budget--) { s->failed_pc=0x0c083742u; return 0; }
r[6]=0x00000001u;
goto P_0c083744;
P_0c083744: /* original 420b, guest PC 0x0c083744 */
if(!s->budget--) { s->failed_pc=0x0c083744u; return 0; }
target=r[2];
r[16]=code_base|0x0c083748u;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083748u) { target=s->pc; goto dispatch; }
goto P_0c083748;
P_0c083746: /* original e407, guest PC 0x0c083746 */
if(!s->budget--) { s->failed_pc=0x0c083746u; return 0; }
r[4]=0x00000007u;
goto P_0c083748;
P_0c083748: /* original 6392, guest PC 0x0c083748 */
if(!s->budget--) { s->failed_pc=0x0c083748u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c08374a;
P_0c08374a: /* original 33b0, guest PC 0x0c08374a */
if(!s->budget--) { s->failed_pc=0x0c08374au; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[11])!=0);
goto P_0c08374c;
P_0c08374c: /* original 8b03, guest PC 0x0c08374c */
if(!s->budget--) { s->failed_pc=0x0c08374cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083756; }
goto P_0c08374e;
P_0c08374e: /* original 55f1, guest PC 0x0c08374e */
if(!s->budget--) { s->failed_pc=0x0c08374eu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c083750;
P_0c083750: /* original e601, guest PC 0x0c083750 */
if(!s->budget--) { s->failed_pc=0x0c083750u; return 0; }
r[6]=0x00000001u;
goto P_0c083752;
P_0c083752: /* original a003, guest PC 0x0c083752 */
if(!s->budget--) { s->failed_pc=0x0c083752u; return 0; }
r[4]=0x00000027u;
goto P_0c08375c;
P_0c083754: /* original e427, guest PC 0x0c083754 */
if(!s->budget--) { s->failed_pc=0x0c083754u; return 0; }
r[4]=0x00000027u;
goto P_0c083756;
P_0c083756: /* original 65f2, guest PC 0x0c083756 */
if(!s->budget--) { s->failed_pc=0x0c083756u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083758;
P_0c083758: /* original e428, guest PC 0x0c083758 */
if(!s->budget--) { s->failed_pc=0x0c083758u; return 0; }
r[4]=0x00000028u;
goto P_0c08375a;
P_0c08375a: /* original e601, guest PC 0x0c08375a */
if(!s->budget--) { s->failed_pc=0x0c08375au; return 0; }
r[6]=0x00000001u;
goto P_0c08375c;
P_0c08375c: /* original d329, guest PC 0x0c08375c */
if(!s->budget--) { s->failed_pc=0x0c08375cu; return 0; }
r[3]=read(ram,0x0c083804u,4);
goto P_0c08375e;
P_0c08375e: /* original 430b, guest PC 0x0c08375e */
if(!s->budget--) { s->failed_pc=0x0c08375eu; return 0; }
target=r[3];
r[16]=code_base|0x0c083762u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083762u) { target=s->pc; goto dispatch; }
goto P_0c083762;
P_0c083760: /* original 0009, guest PC 0x0c083760 */
if(!s->budget--) { s->failed_pc=0x0c083760u; return 0; }
goto P_0c083762;
P_0c083762: /* original 9348, guest PC 0x0c083762 */
if(!s->budget--) { s->failed_pc=0x0c083762u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f6u,2);
goto P_0c083764;
P_0c083764: /* original 60a3, guest PC 0x0c083764 */
if(!s->budget--) { s->failed_pc=0x0c083764u; return 0; }
r[0]=r[10];
goto P_0c083766;
P_0c083766: /* original 4008, guest PC 0x0c083766 */
if(!s->budget--) { s->failed_pc=0x0c083766u; return 0; }
r[0]<<=2;
goto P_0c083768;
P_0c083768: /* original 33ec, guest PC 0x0c083768 */
if(!s->budget--) { s->failed_pc=0x0c083768u; return 0; }
r[3]+=r[14];
goto P_0c08376a;
P_0c08376a: /* original 003e, guest PC 0x0c08376a */
if(!s->budget--) { s->failed_pc=0x0c08376au; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c08376c;
P_0c08376c: /* original 8801, guest PC 0x0c08376c */
if(!s->budget--) { s->failed_pc=0x0c08376cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08376e;
P_0c08376e: /* original 8f58, guest PC 0x0c08376e */
if(!s->budget--) { s->failed_pc=0x0c08376eu; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c083822; }
goto P_0c083772;
P_0c083770: /* original 7d02, guest PC 0x0c083770 */
if(!s->budget--) { s->failed_pc=0x0c083770u; return 0; }
r[13]+=0x00000002u;
goto P_0c083772;
P_0c083772: /* original 9341, guest PC 0x0c083772 */
if(!s->budget--) { s->failed_pc=0x0c083772u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f8u,2);
goto P_0c083774;
P_0c083774: /* original 60a3, guest PC 0x0c083774 */
if(!s->budget--) { s->failed_pc=0x0c083774u; return 0; }
r[0]=r[10];
goto P_0c083776;
P_0c083776: /* original 4008, guest PC 0x0c083776 */
if(!s->budget--) { s->failed_pc=0x0c083776u; return 0; }
r[0]<<=2;
goto P_0c083778;
P_0c083778: /* original 33ec, guest PC 0x0c083778 */
if(!s->budget--) { s->failed_pc=0x0c083778u; return 0; }
r[3]+=r[14];
goto P_0c08377a;
P_0c08377a: /* original 003e, guest PC 0x0c08377a */
if(!s->budget--) { s->failed_pc=0x0c08377au; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c08377c;
P_0c08377c: /* original 8805, guest PC 0x0c08377c */
if(!s->budget--) { s->failed_pc=0x0c08377cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c08377e;
P_0c08377e: /* original 8b21, guest PC 0x0c08377e */
if(!s->budget--) { s->failed_pc=0x0c08377eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0837c4; }
goto P_0c083780;
P_0c083780: /* original d31f, guest PC 0x0c083780 */
if(!s->budget--) { s->failed_pc=0x0c083780u; return 0; }
r[3]=read(ram,0x0c083800u,4);
goto P_0c083782;
P_0c083782: /* original 65d3, guest PC 0x0c083782 */
if(!s->budget--) { s->failed_pc=0x0c083782u; return 0; }
r[5]=r[13];
goto P_0c083784;
P_0c083784: /* original 9639, guest PC 0x0c083784 */
if(!s->budget--) { s->failed_pc=0x0c083784u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837fau,2);
goto P_0c083786;
P_0c083786: /* original 430b, guest PC 0x0c083786 */
if(!s->budget--) { s->failed_pc=0x0c083786u; return 0; }
target=r[3];
r[16]=code_base|0x0c08378au;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08378au) { target=s->pc; goto dispatch; }
goto P_0c08378a;
P_0c083788: /* original e412, guest PC 0x0c083788 */
if(!s->budget--) { s->failed_pc=0x0c083788u; return 0; }
r[4]=0x00000012u;
goto P_0c08378a;
P_0c08378a: /* original 9633, guest PC 0x0c08378a */
if(!s->budget--) { s->failed_pc=0x0c08378au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c08378c;
P_0c08378c: /* original 65d3, guest PC 0x0c08378c */
if(!s->budget--) { s->failed_pc=0x0c08378cu; return 0; }
r[5]=r[13];
goto P_0c08378e;
P_0c08378e: /* original d31e, guest PC 0x0c08378e */
if(!s->budget--) { s->failed_pc=0x0c08378eu; return 0; }
r[3]=read(ram,0x0c083808u,4);
goto P_0c083790;
P_0c083790: /* original 36ec, guest PC 0x0c083790 */
if(!s->budget--) { s->failed_pc=0x0c083790u; return 0; }
r[6]+=r[14];
goto P_0c083792;
P_0c083792: /* original 36cc, guest PC 0x0c083792 */
if(!s->budget--) { s->failed_pc=0x0c083792u; return 0; }
r[6]+=r[12];
goto P_0c083794;
P_0c083794: /* original 5665, guest PC 0x0c083794 */
if(!s->budget--) { s->failed_pc=0x0c083794u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c083796;
P_0c083796: /* original 430b, guest PC 0x0c083796 */
if(!s->budget--) { s->failed_pc=0x0c083796u; return 0; }
target=r[3];
r[16]=code_base|0x0c08379au;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08379au) { target=s->pc; goto dispatch; }
goto P_0c08379a;
P_0c083798: /* original e414, guest PC 0x0c083798 */
if(!s->budget--) { s->failed_pc=0x0c083798u; return 0; }
r[4]=0x00000014u;
goto P_0c08379a;
P_0c08379a: /* original 6292, guest PC 0x0c08379a */
if(!s->budget--) { s->failed_pc=0x0c08379au; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c08379c;
P_0c08379c: /* original 32b0, guest PC 0x0c08379c */
if(!s->budget--) { s->failed_pc=0x0c08379cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c08379e;
P_0c08379e: /* original 8b06, guest PC 0x0c08379e */
if(!s->budget--) { s->failed_pc=0x0c08379eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0837ae; }
goto P_0c0837a0;
P_0c0837a0: /* original 9628, guest PC 0x0c0837a0 */
if(!s->budget--) { s->failed_pc=0x0c0837a0u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c0837a2;
P_0c0837a2: /* original 55f2, guest PC 0x0c0837a2 */
if(!s->budget--) { s->failed_pc=0x0c0837a2u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0837a4;
P_0c0837a4: /* original 36ec, guest PC 0x0c0837a4 */
if(!s->budget--) { s->failed_pc=0x0c0837a4u; return 0; }
r[6]+=r[14];
goto P_0c0837a6;
P_0c0837a6: /* original 36cc, guest PC 0x0c0837a6 */
if(!s->budget--) { s->failed_pc=0x0c0837a6u; return 0; }
r[6]+=r[12];
goto P_0c0837a8;
P_0c0837a8: /* original 5665, guest PC 0x0c0837a8 */
if(!s->budget--) { s->failed_pc=0x0c0837a8u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c0837aa;
P_0c0837aa: /* original a006, guest PC 0x0c0837aa */
if(!s->budget--) { s->failed_pc=0x0c0837aau; return 0; }
r[4]=0x0000002bu;
goto P_0c0837ba;
P_0c0837ac: /* original e42b, guest PC 0x0c0837ac */
if(!s->budget--) { s->failed_pc=0x0c0837acu; return 0; }
r[4]=0x0000002bu;
goto P_0c0837ae;
P_0c0837ae: /* original 9621, guest PC 0x0c0837ae */
if(!s->budget--) { s->failed_pc=0x0c0837aeu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c0837b0;
P_0c0837b0: /* original e42e, guest PC 0x0c0837b0 */
if(!s->budget--) { s->failed_pc=0x0c0837b0u; return 0; }
r[4]=0x0000002eu;
goto P_0c0837b2;
P_0c0837b2: /* original 55f2, guest PC 0x0c0837b2 */
if(!s->budget--) { s->failed_pc=0x0c0837b2u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0837b4;
P_0c0837b4: /* original 36ec, guest PC 0x0c0837b4 */
if(!s->budget--) { s->failed_pc=0x0c0837b4u; return 0; }
r[6]+=r[14];
goto P_0c0837b6;
P_0c0837b6: /* original 36cc, guest PC 0x0c0837b6 */
if(!s->budget--) { s->failed_pc=0x0c0837b6u; return 0; }
r[6]+=r[12];
goto P_0c0837b8;
P_0c0837b8: /* original 5665, guest PC 0x0c0837b8 */
if(!s->budget--) { s->failed_pc=0x0c0837b8u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c0837ba;
P_0c0837ba: /* original d313, guest PC 0x0c0837ba */
if(!s->budget--) { s->failed_pc=0x0c0837bau; return 0; }
r[3]=read(ram,0x0c083808u,4);
goto P_0c0837bc;
P_0c0837bc: /* original 430b, guest PC 0x0c0837bc */
if(!s->budget--) { s->failed_pc=0x0c0837bcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0837c0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0837c0u) { target=s->pc; goto dispatch; }
goto P_0c0837c0;
P_0c0837be: /* original 0009, guest PC 0x0c0837be */
if(!s->budget--) { s->failed_pc=0x0c0837beu; return 0; }
goto P_0c0837c0;
P_0c0837c0: /* original a046, guest PC 0x0c0837c0 */
if(!s->budget--) { s->failed_pc=0x0c0837c0u; return 0; }
goto P_0c083850;
P_0c0837c2: /* original 0009, guest PC 0x0c0837c2 */
if(!s->budget--) { s->failed_pc=0x0c0837c2u; return 0; }
goto P_0c0837c4;
P_0c0837c4: /* original d30e, guest PC 0x0c0837c4 */
if(!s->budget--) { s->failed_pc=0x0c0837c4u; return 0; }
r[3]=read(ram,0x0c083800u,4);
goto P_0c0837c6;
P_0c0837c6: /* original 65d3, guest PC 0x0c0837c6 */
if(!s->budget--) { s->failed_pc=0x0c0837c6u; return 0; }
r[5]=r[13];
goto P_0c0837c8;
P_0c0837c8: /* original 9618, guest PC 0x0c0837c8 */
if(!s->budget--) { s->failed_pc=0x0c0837c8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837fcu,2);
goto P_0c0837ca;
P_0c0837ca: /* original 430b, guest PC 0x0c0837ca */
if(!s->budget--) { s->failed_pc=0x0c0837cau; return 0; }
target=r[3];
r[16]=code_base|0x0c0837ceu;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0837ceu) { target=s->pc; goto dispatch; }
goto P_0c0837ce;
P_0c0837cc: /* original e412, guest PC 0x0c0837cc */
if(!s->budget--) { s->failed_pc=0x0c0837ccu; return 0; }
r[4]=0x00000012u;
goto P_0c0837ce;
P_0c0837ce: /* original 9611, guest PC 0x0c0837ce */
if(!s->budget--) { s->failed_pc=0x0c0837ceu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c0837d0;
P_0c0837d0: /* original 65d3, guest PC 0x0c0837d0 */
if(!s->budget--) { s->failed_pc=0x0c0837d0u; return 0; }
r[5]=r[13];
goto P_0c0837d2;
P_0c0837d2: /* original d30c, guest PC 0x0c0837d2 */
if(!s->budget--) { s->failed_pc=0x0c0837d2u; return 0; }
r[3]=read(ram,0x0c083804u,4);
goto P_0c0837d4;
P_0c0837d4: /* original 36ec, guest PC 0x0c0837d4 */
if(!s->budget--) { s->failed_pc=0x0c0837d4u; return 0; }
r[6]+=r[14];
goto P_0c0837d6;
P_0c0837d6: /* original 36cc, guest PC 0x0c0837d6 */
if(!s->budget--) { s->failed_pc=0x0c0837d6u; return 0; }
r[6]+=r[12];
goto P_0c0837d8;
P_0c0837d8: /* original 5665, guest PC 0x0c0837d8 */
if(!s->budget--) { s->failed_pc=0x0c0837d8u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c0837da;
P_0c0837da: /* original 430b, guest PC 0x0c0837da */
if(!s->budget--) { s->failed_pc=0x0c0837dau; return 0; }
target=r[3];
r[16]=code_base|0x0c0837deu;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0837deu) { target=s->pc; goto dispatch; }
goto P_0c0837de;
P_0c0837dc: /* original e414, guest PC 0x0c0837dc */
if(!s->budget--) { s->failed_pc=0x0c0837dcu; return 0; }
r[4]=0x00000014u;
goto P_0c0837de;
P_0c0837de: /* original 6292, guest PC 0x0c0837de */
if(!s->budget--) { s->failed_pc=0x0c0837deu; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c0837e0;
P_0c0837e0: /* original 32b0, guest PC 0x0c0837e0 */
if(!s->budget--) { s->failed_pc=0x0c0837e0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c0837e2;
P_0c0837e2: /* original 8b13, guest PC 0x0c0837e2 */
if(!s->budget--) { s->failed_pc=0x0c0837e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08380c; }
goto P_0c0837e4;
P_0c0837e4: /* original 9606, guest PC 0x0c0837e4 */
if(!s->budget--) { s->failed_pc=0x0c0837e4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0837f4u,2);
goto P_0c0837e6;
P_0c0837e6: /* original 55f2, guest PC 0x0c0837e6 */
if(!s->budget--) { s->failed_pc=0x0c0837e6u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0837e8;
P_0c0837e8: /* original 36ec, guest PC 0x0c0837e8 */
if(!s->budget--) { s->failed_pc=0x0c0837e8u; return 0; }
r[6]+=r[14];
goto P_0c0837ea;
P_0c0837ea: /* original 36cc, guest PC 0x0c0837ea */
if(!s->budget--) { s->failed_pc=0x0c0837eau; return 0; }
r[6]+=r[12];
goto P_0c0837ec;
P_0c0837ec: /* original 5665, guest PC 0x0c0837ec */
if(!s->budget--) { s->failed_pc=0x0c0837ecu; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c0837ee;
P_0c0837ee: /* original a013, guest PC 0x0c0837ee */
if(!s->budget--) { s->failed_pc=0x0c0837eeu; return 0; }
r[4]=0x0000002bu;
goto P_0c083818;
P_0c0837f0: /* original e42b, guest PC 0x0c0837f0 */
if(!s->budget--) { s->failed_pc=0x0c0837f0u; return 0; }
r[4]=0x0000002bu;
return vf3_matrix_family(0x0c0837f2u,s,ram);
P_0c08380c: /* original 9664, guest PC 0x0c08380c */
if(!s->budget--) { s->failed_pc=0x0c08380cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838d8u,2);
goto P_0c08380e;
P_0c08380e: /* original e42e, guest PC 0x0c08380e */
if(!s->budget--) { s->failed_pc=0x0c08380eu; return 0; }
r[4]=0x0000002eu;
goto P_0c083810;
P_0c083810: /* original 55f2, guest PC 0x0c083810 */
if(!s->budget--) { s->failed_pc=0x0c083810u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c083812;
P_0c083812: /* original 36ec, guest PC 0x0c083812 */
if(!s->budget--) { s->failed_pc=0x0c083812u; return 0; }
r[6]+=r[14];
goto P_0c083814;
P_0c083814: /* original 36cc, guest PC 0x0c083814 */
if(!s->budget--) { s->failed_pc=0x0c083814u; return 0; }
r[6]+=r[12];
goto P_0c083816;
P_0c083816: /* original 5665, guest PC 0x0c083816 */
if(!s->budget--) { s->failed_pc=0x0c083816u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c083818;
P_0c083818: /* original d332, guest PC 0x0c083818 */
if(!s->budget--) { s->failed_pc=0x0c083818u; return 0; }
r[3]=read(ram,0x0c0838e4u,4);
goto P_0c08381a;
P_0c08381a: /* original 430b, guest PC 0x0c08381a */
if(!s->budget--) { s->failed_pc=0x0c08381au; return 0; }
target=r[3];
r[16]=code_base|0x0c08381eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08381eu) { target=s->pc; goto dispatch; }
goto P_0c08381e;
P_0c08381c: /* original 0009, guest PC 0x0c08381c */
if(!s->budget--) { s->failed_pc=0x0c08381cu; return 0; }
goto P_0c08381e;
P_0c08381e: /* original a017, guest PC 0x0c08381e */
if(!s->budget--) { s->failed_pc=0x0c08381eu; return 0; }
goto P_0c083850;
P_0c083820: /* original 0009, guest PC 0x0c083820 */
if(!s->budget--) { s->failed_pc=0x0c083820u; return 0; }
goto P_0c083822;
P_0c083822: /* original d331, guest PC 0x0c083822 */
if(!s->budget--) { s->failed_pc=0x0c083822u; return 0; }
r[3]=read(ram,0x0c0838e8u,4);
goto P_0c083824;
P_0c083824: /* original 65d3, guest PC 0x0c083824 */
if(!s->budget--) { s->failed_pc=0x0c083824u; return 0; }
r[5]=r[13];
goto P_0c083826;
P_0c083826: /* original 9658, guest PC 0x0c083826 */
if(!s->budget--) { s->failed_pc=0x0c083826u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838dau,2);
goto P_0c083828;
P_0c083828: /* original 430b, guest PC 0x0c083828 */
if(!s->budget--) { s->failed_pc=0x0c083828u; return 0; }
target=r[3];
r[16]=code_base|0x0c08382cu;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08382cu) { target=s->pc; goto dispatch; }
goto P_0c08382c;
P_0c08382a: /* original e412, guest PC 0x0c08382a */
if(!s->budget--) { s->failed_pc=0x0c08382au; return 0; }
r[4]=0x00000012u;
goto P_0c08382c;
P_0c08382c: /* original d22d, guest PC 0x0c08382c */
if(!s->budget--) { s->failed_pc=0x0c08382cu; return 0; }
r[2]=read(ram,0x0c0838e4u,4);
goto P_0c08382e;
P_0c08382e: /* original 65d3, guest PC 0x0c08382e */
if(!s->budget--) { s->failed_pc=0x0c08382eu; return 0; }
r[5]=r[13];
goto P_0c083830;
P_0c083830: /* original e602, guest PC 0x0c083830 */
if(!s->budget--) { s->failed_pc=0x0c083830u; return 0; }
r[6]=0x00000002u;
goto P_0c083832;
P_0c083832: /* original 420b, guest PC 0x0c083832 */
if(!s->budget--) { s->failed_pc=0x0c083832u; return 0; }
target=r[2];
r[16]=code_base|0x0c083836u;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083836u) { target=s->pc; goto dispatch; }
goto P_0c083836;
P_0c083834: /* original e407, guest PC 0x0c083834 */
if(!s->budget--) { s->failed_pc=0x0c083834u; return 0; }
r[4]=0x00000007u;
goto P_0c083836;
P_0c083836: /* original 6392, guest PC 0x0c083836 */
if(!s->budget--) { s->failed_pc=0x0c083836u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c083838;
P_0c083838: /* original 33b0, guest PC 0x0c083838 */
if(!s->budget--) { s->failed_pc=0x0c083838u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[11])!=0);
goto P_0c08383a;
P_0c08383a: /* original 8b03, guest PC 0x0c08383a */
if(!s->budget--) { s->failed_pc=0x0c08383au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083844; }
goto P_0c08383c;
P_0c08383c: /* original 55f2, guest PC 0x0c08383c */
if(!s->budget--) { s->failed_pc=0x0c08383cu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c08383e;
P_0c08383e: /* original e602, guest PC 0x0c08383e */
if(!s->budget--) { s->failed_pc=0x0c08383eu; return 0; }
r[6]=0x00000002u;
goto P_0c083840;
P_0c083840: /* original a003, guest PC 0x0c083840 */
if(!s->budget--) { s->failed_pc=0x0c083840u; return 0; }
r[4]=0x0000002bu;
goto P_0c08384a;
P_0c083842: /* original e42b, guest PC 0x0c083842 */
if(!s->budget--) { s->failed_pc=0x0c083842u; return 0; }
r[4]=0x0000002bu;
goto P_0c083844;
P_0c083844: /* original 55f2, guest PC 0x0c083844 */
if(!s->budget--) { s->failed_pc=0x0c083844u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c083846;
P_0c083846: /* original e42e, guest PC 0x0c083846 */
if(!s->budget--) { s->failed_pc=0x0c083846u; return 0; }
r[4]=0x0000002eu;
goto P_0c083848;
P_0c083848: /* original e602, guest PC 0x0c083848 */
if(!s->budget--) { s->failed_pc=0x0c083848u; return 0; }
r[6]=0x00000002u;
goto P_0c08384a;
P_0c08384a: /* original d326, guest PC 0x0c08384a */
if(!s->budget--) { s->failed_pc=0x0c08384au; return 0; }
r[3]=read(ram,0x0c0838e4u,4);
goto P_0c08384c;
P_0c08384c: /* original 430b, guest PC 0x0c08384c */
if(!s->budget--) { s->failed_pc=0x0c08384cu; return 0; }
target=r[3];
r[16]=code_base|0x0c083850u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083850u) { target=s->pc; goto dispatch; }
goto P_0c083850;
P_0c08384e: /* original 0009, guest PC 0x0c08384e */
if(!s->budget--) { s->failed_pc=0x0c08384eu; return 0; }
goto P_0c083850;
P_0c083850: /* original 7808, guest PC 0x0c083850 */
if(!s->budget--) { s->failed_pc=0x0c083850u; return 0; }
r[8]+=0x00000008u;
goto P_0c083852;
P_0c083852: /* original 2f82, guest PC 0x0c083852 */
if(!s->budget--) { s->failed_pc=0x0c083852u; return 0; }
write(ram,r[15],r[8],4);
goto P_0c083854;
P_0c083854: /* original 6392, guest PC 0x0c083854 */
if(!s->budget--) { s->failed_pc=0x0c083854u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c083856;
P_0c083856: /* original 33b0, guest PC 0x0c083856 */
if(!s->budget--) { s->failed_pc=0x0c083856u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[11])!=0);
goto P_0c083858;
P_0c083858: /* original 8b59, guest PC 0x0c083858 */
if(!s->budget--) { s->failed_pc=0x0c083858u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08390e; }
goto P_0c08385a;
P_0c08385a: /* original 9340, guest PC 0x0c08385a */
if(!s->budget--) { s->failed_pc=0x0c08385au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838deu,2);
goto P_0c08385c;
P_0c08385c: /* original 60a3, guest PC 0x0c08385c */
if(!s->budget--) { s->failed_pc=0x0c08385cu; return 0; }
r[0]=r[10];
goto P_0c08385e;
P_0c08385e: /* original 4008, guest PC 0x0c08385e */
if(!s->budget--) { s->failed_pc=0x0c08385eu; return 0; }
r[0]<<=2;
goto P_0c083860;
P_0c083860: /* original 983c, guest PC 0x0c083860 */
if(!s->budget--) { s->failed_pc=0x0c083860u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838dcu,2);
goto P_0c083862;
P_0c083862: /* original 33ec, guest PC 0x0c083862 */
if(!s->budget--) { s->failed_pc=0x0c083862u; return 0; }
r[3]+=r[14];
goto P_0c083864;
P_0c083864: /* original 003e, guest PC 0x0c083864 */
if(!s->budget--) { s->failed_pc=0x0c083864u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c083866;
P_0c083866: /* original 8801, guest PC 0x0c083866 */
if(!s->budget--) { s->failed_pc=0x0c083866u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c083868;
P_0c083868: /* original 8f42, guest PC 0x0c083868 */
if(!s->budget--) { s->failed_pc=0x0c083868u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c0838f0; }
goto P_0c08386c;
P_0c08386a: /* original 7d02, guest PC 0x0c08386a */
if(!s->budget--) { s->failed_pc=0x0c08386au; return 0; }
r[13]+=0x00000002u;
goto P_0c08386c;
P_0c08386c: /* original 9338, guest PC 0x0c08386c */
if(!s->budget--) { s->failed_pc=0x0c08386cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838e0u,2);
goto P_0c08386e;
P_0c08386e: /* original 60a3, guest PC 0x0c08386e */
if(!s->budget--) { s->failed_pc=0x0c08386eu; return 0; }
r[0]=r[10];
goto P_0c083870;
P_0c083870: /* original 4008, guest PC 0x0c083870 */
if(!s->budget--) { s->failed_pc=0x0c083870u; return 0; }
r[0]<<=2;
goto P_0c083872;
P_0c083872: /* original 33ec, guest PC 0x0c083872 */
if(!s->budget--) { s->failed_pc=0x0c083872u; return 0; }
r[3]+=r[14];
goto P_0c083874;
P_0c083874: /* original 003e, guest PC 0x0c083874 */
if(!s->budget--) { s->failed_pc=0x0c083874u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c083876;
P_0c083876: /* original 8806, guest PC 0x0c083876 */
if(!s->budget--) { s->failed_pc=0x0c083876u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c083878;
P_0c083878: /* original 8b17, guest PC 0x0c083878 */
if(!s->budget--) { s->failed_pc=0x0c083878u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0838aa; }
goto P_0c08387a;
P_0c08387a: /* original 9832, guest PC 0x0c08387a */
if(!s->budget--) { s->failed_pc=0x0c08387au; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838e2u,2);
goto P_0c08387c;
P_0c08387c: /* original 65d3, guest PC 0x0c08387c */
if(!s->budget--) { s->failed_pc=0x0c08387cu; return 0; }
r[5]=r[13];
goto P_0c08387e;
P_0c08387e: /* original d31a, guest PC 0x0c08387e */
if(!s->budget--) { s->failed_pc=0x0c08387eu; return 0; }
r[3]=read(ram,0x0c0838e8u,4);
goto P_0c083880;
P_0c083880: /* original 6683, guest PC 0x0c083880 */
if(!s->budget--) { s->failed_pc=0x0c083880u; return 0; }
r[6]=r[8];
goto P_0c083882;
P_0c083882: /* original 430b, guest PC 0x0c083882 */
if(!s->budget--) { s->failed_pc=0x0c083882u; return 0; }
target=r[3];
r[16]=code_base|0x0c083886u;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083886u) { target=s->pc; goto dispatch; }
goto P_0c083886;
P_0c083884: /* original e412, guest PC 0x0c083884 */
if(!s->budget--) { s->failed_pc=0x0c083884u; return 0; }
r[4]=0x00000012u;
goto P_0c083886;
P_0c083886: /* original 9627, guest PC 0x0c083886 */
if(!s->budget--) { s->failed_pc=0x0c083886u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838d8u,2);
goto P_0c083888;
P_0c083888: /* original 65d3, guest PC 0x0c083888 */
if(!s->budget--) { s->failed_pc=0x0c083888u; return 0; }
r[5]=r[13];
goto P_0c08388a;
P_0c08388a: /* original d318, guest PC 0x0c08388a */
if(!s->budget--) { s->failed_pc=0x0c08388au; return 0; }
r[3]=read(ram,0x0c0838ecu,4);
goto P_0c08388c;
P_0c08388c: /* original 36ec, guest PC 0x0c08388c */
if(!s->budget--) { s->failed_pc=0x0c08388cu; return 0; }
r[6]+=r[14];
goto P_0c08388e;
P_0c08388e: /* original 36cc, guest PC 0x0c08388e */
if(!s->budget--) { s->failed_pc=0x0c08388eu; return 0; }
r[6]+=r[12];
goto P_0c083890;
P_0c083890: /* original 5666, guest PC 0x0c083890 */
if(!s->budget--) { s->failed_pc=0x0c083890u; return 0; }
r[6]=read(ram,r[6]+24,4);
goto P_0c083892;
P_0c083892: /* original 430b, guest PC 0x0c083892 */
if(!s->budget--) { s->failed_pc=0x0c083892u; return 0; }
target=r[3];
r[16]=code_base|0x0c083896u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083896u) { target=s->pc; goto dispatch; }
goto P_0c083896;
P_0c083894: /* original e414, guest PC 0x0c083894 */
if(!s->budget--) { s->failed_pc=0x0c083894u; return 0; }
r[4]=0x00000014u;
goto P_0c083896;
P_0c083896: /* original 961f, guest PC 0x0c083896 */
if(!s->budget--) { s->failed_pc=0x0c083896u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838d8u,2);
goto P_0c083898;
P_0c083898: /* original d314, guest PC 0x0c083898 */
if(!s->budget--) { s->failed_pc=0x0c083898u; return 0; }
r[3]=read(ram,0x0c0838ecu,4);
goto P_0c08389a;
P_0c08389a: /* original 36ec, guest PC 0x0c08389a */
if(!s->budget--) { s->failed_pc=0x0c08389au; return 0; }
r[6]+=r[14];
goto P_0c08389c;
P_0c08389c: /* original 65f2, guest PC 0x0c08389c */
if(!s->budget--) { s->failed_pc=0x0c08389cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08389e;
P_0c08389e: /* original 36cc, guest PC 0x0c08389e */
if(!s->budget--) { s->failed_pc=0x0c08389eu; return 0; }
r[6]+=r[12];
goto P_0c0838a0;
P_0c0838a0: /* original 5666, guest PC 0x0c0838a0 */
if(!s->budget--) { s->failed_pc=0x0c0838a0u; return 0; }
r[6]=read(ram,r[6]+24,4);
goto P_0c0838a2;
P_0c0838a2: /* original 430b, guest PC 0x0c0838a2 */
if(!s->budget--) { s->failed_pc=0x0c0838a2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0838a6u;
r[4]=0x00000033u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0838a6u) { target=s->pc; goto dispatch; }
goto P_0c0838a6;
P_0c0838a4: /* original e433, guest PC 0x0c0838a4 */
if(!s->budget--) { s->failed_pc=0x0c0838a4u; return 0; }
r[4]=0x00000033u;
goto P_0c0838a6;
P_0c0838a6: /* original a032, guest PC 0x0c0838a6 */
if(!s->budget--) { s->failed_pc=0x0c0838a6u; return 0; }
goto P_0c08390e;
P_0c0838a8: /* original 0009, guest PC 0x0c0838a8 */
if(!s->budget--) { s->failed_pc=0x0c0838a8u; return 0; }
goto P_0c0838aa;
P_0c0838aa: /* original d30f, guest PC 0x0c0838aa */
if(!s->budget--) { s->failed_pc=0x0c0838aau; return 0; }
r[3]=read(ram,0x0c0838e8u,4);
goto P_0c0838ac;
P_0c0838ac: /* original 65d3, guest PC 0x0c0838ac */
if(!s->budget--) { s->failed_pc=0x0c0838acu; return 0; }
r[5]=r[13];
goto P_0c0838ae;
P_0c0838ae: /* original 6683, guest PC 0x0c0838ae */
if(!s->budget--) { s->failed_pc=0x0c0838aeu; return 0; }
r[6]=r[8];
goto P_0c0838b0;
P_0c0838b0: /* original 430b, guest PC 0x0c0838b0 */
if(!s->budget--) { s->failed_pc=0x0c0838b0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0838b4u;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0838b4u) { target=s->pc; goto dispatch; }
goto P_0c0838b4;
P_0c0838b2: /* original e412, guest PC 0x0c0838b2 */
if(!s->budget--) { s->failed_pc=0x0c0838b2u; return 0; }
r[4]=0x00000012u;
goto P_0c0838b4;
P_0c0838b4: /* original 9610, guest PC 0x0c0838b4 */
if(!s->budget--) { s->failed_pc=0x0c0838b4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838d8u,2);
goto P_0c0838b6;
P_0c0838b6: /* original 65d3, guest PC 0x0c0838b6 */
if(!s->budget--) { s->failed_pc=0x0c0838b6u; return 0; }
r[5]=r[13];
goto P_0c0838b8;
P_0c0838b8: /* original d30a, guest PC 0x0c0838b8 */
if(!s->budget--) { s->failed_pc=0x0c0838b8u; return 0; }
r[3]=read(ram,0x0c0838e4u,4);
goto P_0c0838ba;
P_0c0838ba: /* original 36ec, guest PC 0x0c0838ba */
if(!s->budget--) { s->failed_pc=0x0c0838bau; return 0; }
r[6]+=r[14];
goto P_0c0838bc;
P_0c0838bc: /* original 36cc, guest PC 0x0c0838bc */
if(!s->budget--) { s->failed_pc=0x0c0838bcu; return 0; }
r[6]+=r[12];
goto P_0c0838be;
P_0c0838be: /* original 5666, guest PC 0x0c0838be */
if(!s->budget--) { s->failed_pc=0x0c0838beu; return 0; }
r[6]=read(ram,r[6]+24,4);
goto P_0c0838c0;
P_0c0838c0: /* original 430b, guest PC 0x0c0838c0 */
if(!s->budget--) { s->failed_pc=0x0c0838c0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0838c4u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0838c4u) { target=s->pc; goto dispatch; }
goto P_0c0838c4;
P_0c0838c2: /* original e414, guest PC 0x0c0838c2 */
if(!s->budget--) { s->failed_pc=0x0c0838c2u; return 0; }
r[4]=0x00000014u;
goto P_0c0838c4;
P_0c0838c4: /* original 9608, guest PC 0x0c0838c4 */
if(!s->budget--) { s->failed_pc=0x0c0838c4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0838d8u,2);
goto P_0c0838c6;
P_0c0838c6: /* original d307, guest PC 0x0c0838c6 */
if(!s->budget--) { s->failed_pc=0x0c0838c6u; return 0; }
r[3]=read(ram,0x0c0838e4u,4);
goto P_0c0838c8;
P_0c0838c8: /* original 36ec, guest PC 0x0c0838c8 */
if(!s->budget--) { s->failed_pc=0x0c0838c8u; return 0; }
r[6]+=r[14];
goto P_0c0838ca;
P_0c0838ca: /* original 65f2, guest PC 0x0c0838ca */
if(!s->budget--) { s->failed_pc=0x0c0838cau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0838cc;
P_0c0838cc: /* original 36cc, guest PC 0x0c0838cc */
if(!s->budget--) { s->failed_pc=0x0c0838ccu; return 0; }
r[6]+=r[12];
goto P_0c0838ce;
P_0c0838ce: /* original 5666, guest PC 0x0c0838ce */
if(!s->budget--) { s->failed_pc=0x0c0838ceu; return 0; }
r[6]=read(ram,r[6]+24,4);
goto P_0c0838d0;
P_0c0838d0: /* original 430b, guest PC 0x0c0838d0 */
if(!s->budget--) { s->failed_pc=0x0c0838d0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0838d4u;
r[4]=0x00000033u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0838d4u) { target=s->pc; goto dispatch; }
goto P_0c0838d4;
P_0c0838d2: /* original e433, guest PC 0x0c0838d2 */
if(!s->budget--) { s->failed_pc=0x0c0838d2u; return 0; }
r[4]=0x00000033u;
goto P_0c0838d4;
P_0c0838d4: /* original a01b, guest PC 0x0c0838d4 */
if(!s->budget--) { s->failed_pc=0x0c0838d4u; return 0; }
goto P_0c08390e;
P_0c0838d6: /* original 0009, guest PC 0x0c0838d6 */
if(!s->budget--) { s->failed_pc=0x0c0838d6u; return 0; }
return vf3_matrix_family(0x0c0838d8u,s,ram);
P_0c0838f0: /* original d348, guest PC 0x0c0838f0 */
if(!s->budget--) { s->failed_pc=0x0c0838f0u; return 0; }
r[3]=read(ram,0x0c083a14u,4);
goto P_0c0838f2;
P_0c0838f2: /* original 65d3, guest PC 0x0c0838f2 */
if(!s->budget--) { s->failed_pc=0x0c0838f2u; return 0; }
r[5]=r[13];
goto P_0c0838f4;
P_0c0838f4: /* original 6683, guest PC 0x0c0838f4 */
if(!s->budget--) { s->failed_pc=0x0c0838f4u; return 0; }
r[6]=r[8];
goto P_0c0838f6;
P_0c0838f6: /* original 430b, guest PC 0x0c0838f6 */
if(!s->budget--) { s->failed_pc=0x0c0838f6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0838fau;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0838fau) { target=s->pc; goto dispatch; }
goto P_0c0838fa;
P_0c0838f8: /* original e412, guest PC 0x0c0838f8 */
if(!s->budget--) { s->failed_pc=0x0c0838f8u; return 0; }
r[4]=0x00000012u;
goto P_0c0838fa;
P_0c0838fa: /* original d247, guest PC 0x0c0838fa */
if(!s->budget--) { s->failed_pc=0x0c0838fau; return 0; }
r[2]=read(ram,0x0c083a18u,4);
goto P_0c0838fc;
P_0c0838fc: /* original 65d3, guest PC 0x0c0838fc */
if(!s->budget--) { s->failed_pc=0x0c0838fcu; return 0; }
r[5]=r[13];
goto P_0c0838fe;
P_0c0838fe: /* original e608, guest PC 0x0c0838fe */
if(!s->budget--) { s->failed_pc=0x0c0838feu; return 0; }
r[6]=0x00000008u;
goto P_0c083900;
P_0c083900: /* original 420b, guest PC 0x0c083900 */
if(!s->budget--) { s->failed_pc=0x0c083900u; return 0; }
target=r[2];
r[16]=code_base|0x0c083904u;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083904u) { target=s->pc; goto dispatch; }
goto P_0c083904;
P_0c083902: /* original e407, guest PC 0x0c083902 */
if(!s->budget--) { s->failed_pc=0x0c083902u; return 0; }
r[4]=0x00000007u;
goto P_0c083904;
P_0c083904: /* original d344, guest PC 0x0c083904 */
if(!s->budget--) { s->failed_pc=0x0c083904u; return 0; }
r[3]=read(ram,0x0c083a18u,4);
goto P_0c083906;
P_0c083906: /* original e608, guest PC 0x0c083906 */
if(!s->budget--) { s->failed_pc=0x0c083906u; return 0; }
r[6]=0x00000008u;
goto P_0c083908;
P_0c083908: /* original 65f2, guest PC 0x0c083908 */
if(!s->budget--) { s->failed_pc=0x0c083908u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08390a;
P_0c08390a: /* original 430b, guest PC 0x0c08390a */
if(!s->budget--) { s->failed_pc=0x0c08390au; return 0; }
target=r[3];
r[16]=code_base|0x0c08390eu;
r[4]=0x00000033u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08390eu) { target=s->pc; goto dispatch; }
goto P_0c08390e;
P_0c08390c: /* original e433, guest PC 0x0c08390c */
if(!s->budget--) { s->failed_pc=0x0c08390cu; return 0; }
r[4]=0x00000033u;
goto P_0c08390e;
P_0c08390e: /* original 6392, guest PC 0x0c08390e */
if(!s->budget--) { s->failed_pc=0x0c08390eu; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c083910;
P_0c083910: /* original d242, guest PC 0x0c083910 */
if(!s->budget--) { s->failed_pc=0x0c083910u; return 0; }
r[2]=read(ram,0x0c083a1cu,4);
goto P_0c083912;
P_0c083912: /* original 3320, guest PC 0x0c083912 */
if(!s->budget--) { s->failed_pc=0x0c083912u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c083914;
P_0c083914: /* original 8901, guest PC 0x0c083914 */
if(!s->budget--) { s->failed_pc=0x0c083914u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08391a; }
goto P_0c083916;
P_0c083916: /* original a0ab, guest PC 0x0c083916 */
if(!s->budget--) { s->failed_pc=0x0c083916u; return 0; }
goto P_0c083a70;
P_0c083918: /* original 0009, guest PC 0x0c083918 */
if(!s->budget--) { s->failed_pc=0x0c083918u; return 0; }
goto P_0c08391a;
P_0c08391a: /* original 9375, guest PC 0x0c08391a */
if(!s->budget--) { s->failed_pc=0x0c08391au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a08u,2);
goto P_0c08391c;
P_0c08391c: /* original 60a3, guest PC 0x0c08391c */
if(!s->budget--) { s->failed_pc=0x0c08391cu; return 0; }
r[0]=r[10];
goto P_0c08391e;
P_0c08391e: /* original 4008, guest PC 0x0c08391e */
if(!s->budget--) { s->failed_pc=0x0c08391eu; return 0; }
r[0]<<=2;
goto P_0c083920;
P_0c083920: /* original 9971, guest PC 0x0c083920 */
if(!s->budget--) { s->failed_pc=0x0c083920u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a06u,2);
goto P_0c083922;
P_0c083922: /* original 33ec, guest PC 0x0c083922 */
if(!s->budget--) { s->failed_pc=0x0c083922u; return 0; }
r[3]+=r[14];
goto P_0c083924;
P_0c083924: /* original 003e, guest PC 0x0c083924 */
if(!s->budget--) { s->failed_pc=0x0c083924u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c083926;
P_0c083926: /* original 8801, guest PC 0x0c083926 */
if(!s->budget--) { s->failed_pc=0x0c083926u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c083928;
P_0c083928: /* original 8f36, guest PC 0x0c083928 */
if(!s->budget--) { s->failed_pc=0x0c083928u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c083998; }
goto P_0c08392c;
P_0c08392a: /* original 7d02, guest PC 0x0c08392a */
if(!s->budget--) { s->failed_pc=0x0c08392au; return 0; }
r[13]+=0x00000002u;
goto P_0c08392c;
P_0c08392c: /* original 936d, guest PC 0x0c08392c */
if(!s->budget--) { s->failed_pc=0x0c08392cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0au,2);
goto P_0c08392e;
P_0c08392e: /* original 60a3, guest PC 0x0c08392e */
if(!s->budget--) { s->failed_pc=0x0c08392eu; return 0; }
r[0]=r[10];
goto P_0c083930;
P_0c083930: /* original 4008, guest PC 0x0c083930 */
if(!s->budget--) { s->failed_pc=0x0c083930u; return 0; }
r[0]<<=2;
goto P_0c083932;
P_0c083932: /* original 33ec, guest PC 0x0c083932 */
if(!s->budget--) { s->failed_pc=0x0c083932u; return 0; }
r[3]+=r[14];
goto P_0c083934;
P_0c083934: /* original 003e, guest PC 0x0c083934 */
if(!s->budget--) { s->failed_pc=0x0c083934u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c083936;
P_0c083936: /* original 8807, guest PC 0x0c083936 */
if(!s->budget--) { s->failed_pc=0x0c083936u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c083938;
P_0c083938: /* original 8b17, guest PC 0x0c083938 */
if(!s->budget--) { s->failed_pc=0x0c083938u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08396a; }
goto P_0c08393a;
P_0c08393a: /* original 9967, guest PC 0x0c08393a */
if(!s->budget--) { s->failed_pc=0x0c08393au; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0cu,2);
goto P_0c08393c;
P_0c08393c: /* original 65d3, guest PC 0x0c08393c */
if(!s->budget--) { s->failed_pc=0x0c08393cu; return 0; }
r[5]=r[13];
goto P_0c08393e;
P_0c08393e: /* original d335, guest PC 0x0c08393e */
if(!s->budget--) { s->failed_pc=0x0c08393eu; return 0; }
r[3]=read(ram,0x0c083a14u,4);
goto P_0c083940;
P_0c083940: /* original 6693, guest PC 0x0c083940 */
if(!s->budget--) { s->failed_pc=0x0c083940u; return 0; }
r[6]=r[9];
goto P_0c083942;
P_0c083942: /* original 430b, guest PC 0x0c083942 */
if(!s->budget--) { s->failed_pc=0x0c083942u; return 0; }
target=r[3];
r[16]=code_base|0x0c083946u;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083946u) { target=s->pc; goto dispatch; }
goto P_0c083946;
P_0c083944: /* original e412, guest PC 0x0c083944 */
if(!s->budget--) { s->failed_pc=0x0c083944u; return 0; }
r[4]=0x00000012u;
goto P_0c083946;
P_0c083946: /* original 9662, guest PC 0x0c083946 */
if(!s->budget--) { s->failed_pc=0x0c083946u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0eu,2);
goto P_0c083948;
P_0c083948: /* original 65d3, guest PC 0x0c083948 */
if(!s->budget--) { s->failed_pc=0x0c083948u; return 0; }
r[5]=r[13];
goto P_0c08394a;
P_0c08394a: /* original d335, guest PC 0x0c08394a */
if(!s->budget--) { s->failed_pc=0x0c08394au; return 0; }
r[3]=read(ram,0x0c083a20u,4);
goto P_0c08394c;
P_0c08394c: /* original 36ec, guest PC 0x0c08394c */
if(!s->budget--) { s->failed_pc=0x0c08394cu; return 0; }
r[6]+=r[14];
goto P_0c08394e;
P_0c08394e: /* original 36cc, guest PC 0x0c08394e */
if(!s->budget--) { s->failed_pc=0x0c08394eu; return 0; }
r[6]+=r[12];
goto P_0c083950;
P_0c083950: /* original 5667, guest PC 0x0c083950 */
if(!s->budget--) { s->failed_pc=0x0c083950u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c083952;
P_0c083952: /* original 430b, guest PC 0x0c083952 */
if(!s->budget--) { s->failed_pc=0x0c083952u; return 0; }
target=r[3];
r[16]=code_base|0x0c083956u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083956u) { target=s->pc; goto dispatch; }
goto P_0c083956;
P_0c083954: /* original e414, guest PC 0x0c083954 */
if(!s->budget--) { s->failed_pc=0x0c083954u; return 0; }
r[4]=0x00000014u;
goto P_0c083956;
P_0c083956: /* original 965a, guest PC 0x0c083956 */
if(!s->budget--) { s->failed_pc=0x0c083956u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0eu,2);
goto P_0c083958;
P_0c083958: /* original d331, guest PC 0x0c083958 */
if(!s->budget--) { s->failed_pc=0x0c083958u; return 0; }
r[3]=read(ram,0x0c083a20u,4);
goto P_0c08395a;
P_0c08395a: /* original 36ec, guest PC 0x0c08395a */
if(!s->budget--) { s->failed_pc=0x0c08395au; return 0; }
r[6]+=r[14];
goto P_0c08395c;
P_0c08395c: /* original 65f2, guest PC 0x0c08395c */
if(!s->budget--) { s->failed_pc=0x0c08395cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08395e;
P_0c08395e: /* original 36cc, guest PC 0x0c08395e */
if(!s->budget--) { s->failed_pc=0x0c08395eu; return 0; }
r[6]+=r[12];
goto P_0c083960;
P_0c083960: /* original 5667, guest PC 0x0c083960 */
if(!s->budget--) { s->failed_pc=0x0c083960u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c083962;
P_0c083962: /* original 430b, guest PC 0x0c083962 */
if(!s->budget--) { s->failed_pc=0x0c083962u; return 0; }
target=r[3];
r[16]=code_base|0x0c083966u;
r[4]=0x00000021u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083966u) { target=s->pc; goto dispatch; }
goto P_0c083966;
P_0c083964: /* original e421, guest PC 0x0c083964 */
if(!s->budget--) { s->failed_pc=0x0c083964u; return 0; }
r[4]=0x00000021u;
goto P_0c083966;
P_0c083966: /* original a026, guest PC 0x0c083966 */
if(!s->budget--) { s->failed_pc=0x0c083966u; return 0; }
goto P_0c0839b6;
P_0c083968: /* original 0009, guest PC 0x0c083968 */
if(!s->budget--) { s->failed_pc=0x0c083968u; return 0; }
goto P_0c08396a;
P_0c08396a: /* original d32a, guest PC 0x0c08396a */
if(!s->budget--) { s->failed_pc=0x0c08396au; return 0; }
r[3]=read(ram,0x0c083a14u,4);
goto P_0c08396c;
P_0c08396c: /* original 65d3, guest PC 0x0c08396c */
if(!s->budget--) { s->failed_pc=0x0c08396cu; return 0; }
r[5]=r[13];
goto P_0c08396e;
P_0c08396e: /* original 6693, guest PC 0x0c08396e */
if(!s->budget--) { s->failed_pc=0x0c08396eu; return 0; }
r[6]=r[9];
goto P_0c083970;
P_0c083970: /* original 430b, guest PC 0x0c083970 */
if(!s->budget--) { s->failed_pc=0x0c083970u; return 0; }
target=r[3];
r[16]=code_base|0x0c083974u;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083974u) { target=s->pc; goto dispatch; }
goto P_0c083974;
P_0c083972: /* original e412, guest PC 0x0c083972 */
if(!s->budget--) { s->failed_pc=0x0c083972u; return 0; }
r[4]=0x00000012u;
goto P_0c083974;
P_0c083974: /* original 964b, guest PC 0x0c083974 */
if(!s->budget--) { s->failed_pc=0x0c083974u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0eu,2);
goto P_0c083976;
P_0c083976: /* original 65d3, guest PC 0x0c083976 */
if(!s->budget--) { s->failed_pc=0x0c083976u; return 0; }
r[5]=r[13];
goto P_0c083978;
P_0c083978: /* original d327, guest PC 0x0c083978 */
if(!s->budget--) { s->failed_pc=0x0c083978u; return 0; }
r[3]=read(ram,0x0c083a18u,4);
goto P_0c08397a;
P_0c08397a: /* original 36ec, guest PC 0x0c08397a */
if(!s->budget--) { s->failed_pc=0x0c08397au; return 0; }
r[6]+=r[14];
goto P_0c08397c;
P_0c08397c: /* original 36cc, guest PC 0x0c08397c */
if(!s->budget--) { s->failed_pc=0x0c08397cu; return 0; }
r[6]+=r[12];
goto P_0c08397e;
P_0c08397e: /* original 5667, guest PC 0x0c08397e */
if(!s->budget--) { s->failed_pc=0x0c08397eu; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c083980;
P_0c083980: /* original 430b, guest PC 0x0c083980 */
if(!s->budget--) { s->failed_pc=0x0c083980u; return 0; }
target=r[3];
r[16]=code_base|0x0c083984u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083984u) { target=s->pc; goto dispatch; }
goto P_0c083984;
P_0c083982: /* original e414, guest PC 0x0c083982 */
if(!s->budget--) { s->failed_pc=0x0c083982u; return 0; }
r[4]=0x00000014u;
goto P_0c083984;
P_0c083984: /* original 9643, guest PC 0x0c083984 */
if(!s->budget--) { s->failed_pc=0x0c083984u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0eu,2);
goto P_0c083986;
P_0c083986: /* original d324, guest PC 0x0c083986 */
if(!s->budget--) { s->failed_pc=0x0c083986u; return 0; }
r[3]=read(ram,0x0c083a18u,4);
goto P_0c083988;
P_0c083988: /* original 36ec, guest PC 0x0c083988 */
if(!s->budget--) { s->failed_pc=0x0c083988u; return 0; }
r[6]+=r[14];
goto P_0c08398a;
P_0c08398a: /* original 65f2, guest PC 0x0c08398a */
if(!s->budget--) { s->failed_pc=0x0c08398au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c08398c;
P_0c08398c: /* original 36cc, guest PC 0x0c08398c */
if(!s->budget--) { s->failed_pc=0x0c08398cu; return 0; }
r[6]+=r[12];
goto P_0c08398e;
P_0c08398e: /* original 5667, guest PC 0x0c08398e */
if(!s->budget--) { s->failed_pc=0x0c08398eu; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c083990;
P_0c083990: /* original 430b, guest PC 0x0c083990 */
if(!s->budget--) { s->failed_pc=0x0c083990u; return 0; }
target=r[3];
r[16]=code_base|0x0c083994u;
r[4]=0x00000021u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083994u) { target=s->pc; goto dispatch; }
goto P_0c083994;
P_0c083992: /* original e421, guest PC 0x0c083992 */
if(!s->budget--) { s->failed_pc=0x0c083992u; return 0; }
r[4]=0x00000021u;
goto P_0c083994;
P_0c083994: /* original a00f, guest PC 0x0c083994 */
if(!s->budget--) { s->failed_pc=0x0c083994u; return 0; }
goto P_0c0839b6;
P_0c083996: /* original 0009, guest PC 0x0c083996 */
if(!s->budget--) { s->failed_pc=0x0c083996u; return 0; }
goto P_0c083998;
P_0c083998: /* original d31e, guest PC 0x0c083998 */
if(!s->budget--) { s->failed_pc=0x0c083998u; return 0; }
r[3]=read(ram,0x0c083a14u,4);
goto P_0c08399a;
P_0c08399a: /* original 65d3, guest PC 0x0c08399a */
if(!s->budget--) { s->failed_pc=0x0c08399au; return 0; }
r[5]=r[13];
goto P_0c08399c;
P_0c08399c: /* original 6693, guest PC 0x0c08399c */
if(!s->budget--) { s->failed_pc=0x0c08399cu; return 0; }
r[6]=r[9];
goto P_0c08399e;
P_0c08399e: /* original 430b, guest PC 0x0c08399e */
if(!s->budget--) { s->failed_pc=0x0c08399eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0839a2u;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0839a2u) { target=s->pc; goto dispatch; }
goto P_0c0839a2;
P_0c0839a0: /* original e412, guest PC 0x0c0839a0 */
if(!s->budget--) { s->failed_pc=0x0c0839a0u; return 0; }
r[4]=0x00000012u;
goto P_0c0839a2;
P_0c0839a2: /* original d21d, guest PC 0x0c0839a2 */
if(!s->budget--) { s->failed_pc=0x0c0839a2u; return 0; }
r[2]=read(ram,0x0c083a18u,4);
goto P_0c0839a4;
P_0c0839a4: /* original 65d3, guest PC 0x0c0839a4 */
if(!s->budget--) { s->failed_pc=0x0c0839a4u; return 0; }
r[5]=r[13];
goto P_0c0839a6;
P_0c0839a6: /* original e610, guest PC 0x0c0839a6 */
if(!s->budget--) { s->failed_pc=0x0c0839a6u; return 0; }
r[6]=0x00000010u;
goto P_0c0839a8;
P_0c0839a8: /* original 420b, guest PC 0x0c0839a8 */
if(!s->budget--) { s->failed_pc=0x0c0839a8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0839acu;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0839acu) { target=s->pc; goto dispatch; }
goto P_0c0839ac;
P_0c0839aa: /* original e407, guest PC 0x0c0839aa */
if(!s->budget--) { s->failed_pc=0x0c0839aau; return 0; }
r[4]=0x00000007u;
goto P_0c0839ac;
P_0c0839ac: /* original d31a, guest PC 0x0c0839ac */
if(!s->budget--) { s->failed_pc=0x0c0839acu; return 0; }
r[3]=read(ram,0x0c083a18u,4);
goto P_0c0839ae;
P_0c0839ae: /* original e610, guest PC 0x0c0839ae */
if(!s->budget--) { s->failed_pc=0x0c0839aeu; return 0; }
r[6]=0x00000010u;
goto P_0c0839b0;
P_0c0839b0: /* original 65f2, guest PC 0x0c0839b0 */
if(!s->budget--) { s->failed_pc=0x0c0839b0u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0839b2;
P_0c0839b2: /* original 430b, guest PC 0x0c0839b2 */
if(!s->budget--) { s->failed_pc=0x0c0839b2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0839b6u;
r[4]=0x00000021u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0839b6u) { target=s->pc; goto dispatch; }
goto P_0c0839b6;
P_0c0839b4: /* original e421, guest PC 0x0c0839b4 */
if(!s->budget--) { s->failed_pc=0x0c0839b4u; return 0; }
r[4]=0x00000021u;
goto P_0c0839b6;
P_0c0839b6: /* original 9327, guest PC 0x0c0839b6 */
if(!s->budget--) { s->failed_pc=0x0c0839b6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a08u,2);
goto P_0c0839b8;
P_0c0839b8: /* original 60a3, guest PC 0x0c0839b8 */
if(!s->budget--) { s->failed_pc=0x0c0839b8u; return 0; }
r[0]=r[10];
goto P_0c0839ba;
P_0c0839ba: /* original 4008, guest PC 0x0c0839ba */
if(!s->budget--) { s->failed_pc=0x0c0839bau; return 0; }
r[0]<<=2;
goto P_0c0839bc;
P_0c0839bc: /* original 9928, guest PC 0x0c0839bc */
if(!s->budget--) { s->failed_pc=0x0c0839bcu; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a10u,2);
goto P_0c0839be;
P_0c0839be: /* original 33ec, guest PC 0x0c0839be */
if(!s->budget--) { s->failed_pc=0x0c0839beu; return 0; }
r[3]+=r[14];
goto P_0c0839c0;
P_0c0839c0: /* original 003e, guest PC 0x0c0839c0 */
if(!s->budget--) { s->failed_pc=0x0c0839c0u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0839c2;
P_0c0839c2: /* original 8801, guest PC 0x0c0839c2 */
if(!s->budget--) { s->failed_pc=0x0c0839c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0839c4;
P_0c0839c4: /* original 8f45, guest PC 0x0c0839c4 */
if(!s->budget--) { s->failed_pc=0x0c0839c4u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000002u;
if(!cond) { goto P_0c083a52; }
goto P_0c0839c8;
P_0c0839c6: /* original 7d02, guest PC 0x0c0839c6 */
if(!s->budget--) { s->failed_pc=0x0c0839c6u; return 0; }
r[13]+=0x00000002u;
goto P_0c0839c8;
P_0c0839c8: /* original 931f, guest PC 0x0c0839c8 */
if(!s->budget--) { s->failed_pc=0x0c0839c8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0au,2);
goto P_0c0839ca;
P_0c0839ca: /* original 60a3, guest PC 0x0c0839ca */
if(!s->budget--) { s->failed_pc=0x0c0839cau; return 0; }
r[0]=r[10];
goto P_0c0839cc;
P_0c0839cc: /* original 4008, guest PC 0x0c0839cc */
if(!s->budget--) { s->failed_pc=0x0c0839ccu; return 0; }
r[0]<<=2;
goto P_0c0839ce;
P_0c0839ce: /* original 33ec, guest PC 0x0c0839ce */
if(!s->budget--) { s->failed_pc=0x0c0839ceu; return 0; }
r[3]+=r[14];
goto P_0c0839d0;
P_0c0839d0: /* original 003e, guest PC 0x0c0839d0 */
if(!s->budget--) { s->failed_pc=0x0c0839d0u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c0839d2;
P_0c0839d2: /* original 8808, guest PC 0x0c0839d2 */
if(!s->budget--) { s->failed_pc=0x0c0839d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0839d4;
P_0c0839d4: /* original 8b26, guest PC 0x0c0839d4 */
if(!s->budget--) { s->failed_pc=0x0c0839d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083a24; }
goto P_0c0839d6;
P_0c0839d6: /* original 991c, guest PC 0x0c0839d6 */
if(!s->budget--) { s->failed_pc=0x0c0839d6u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a12u,2);
goto P_0c0839d8;
P_0c0839d8: /* original 65d3, guest PC 0x0c0839d8 */
if(!s->budget--) { s->failed_pc=0x0c0839d8u; return 0; }
r[5]=r[13];
goto P_0c0839da;
P_0c0839da: /* original d30e, guest PC 0x0c0839da */
if(!s->budget--) { s->failed_pc=0x0c0839dau; return 0; }
r[3]=read(ram,0x0c083a14u,4);
goto P_0c0839dc;
P_0c0839dc: /* original 6693, guest PC 0x0c0839dc */
if(!s->budget--) { s->failed_pc=0x0c0839dcu; return 0; }
r[6]=r[9];
goto P_0c0839de;
P_0c0839de: /* original 430b, guest PC 0x0c0839de */
if(!s->budget--) { s->failed_pc=0x0c0839deu; return 0; }
target=r[3];
r[16]=code_base|0x0c0839e2u;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0839e2u) { target=s->pc; goto dispatch; }
goto P_0c0839e2;
P_0c0839e0: /* original e412, guest PC 0x0c0839e0 */
if(!s->budget--) { s->failed_pc=0x0c0839e0u; return 0; }
r[4]=0x00000012u;
goto P_0c0839e2;
P_0c0839e2: /* original 9614, guest PC 0x0c0839e2 */
if(!s->budget--) { s->failed_pc=0x0c0839e2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0eu,2);
goto P_0c0839e4;
P_0c0839e4: /* original 65d3, guest PC 0x0c0839e4 */
if(!s->budget--) { s->failed_pc=0x0c0839e4u; return 0; }
r[5]=r[13];
goto P_0c0839e6;
P_0c0839e6: /* original d30e, guest PC 0x0c0839e6 */
if(!s->budget--) { s->failed_pc=0x0c0839e6u; return 0; }
r[3]=read(ram,0x0c083a20u,4);
goto P_0c0839e8;
P_0c0839e8: /* original 36ec, guest PC 0x0c0839e8 */
if(!s->budget--) { s->failed_pc=0x0c0839e8u; return 0; }
r[6]+=r[14];
goto P_0c0839ea;
P_0c0839ea: /* original 36cc, guest PC 0x0c0839ea */
if(!s->budget--) { s->failed_pc=0x0c0839eau; return 0; }
r[6]+=r[12];
goto P_0c0839ec;
P_0c0839ec: /* original 5668, guest PC 0x0c0839ec */
if(!s->budget--) { s->failed_pc=0x0c0839ecu; return 0; }
r[6]=read(ram,r[6]+32,4);
goto P_0c0839ee;
P_0c0839ee: /* original 430b, guest PC 0x0c0839ee */
if(!s->budget--) { s->failed_pc=0x0c0839eeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0839f2u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0839f2u) { target=s->pc; goto dispatch; }
goto P_0c0839f2;
P_0c0839f0: /* original e414, guest PC 0x0c0839f0 */
if(!s->budget--) { s->failed_pc=0x0c0839f0u; return 0; }
r[4]=0x00000014u;
goto P_0c0839f2;
P_0c0839f2: /* original 960c, guest PC 0x0c0839f2 */
if(!s->budget--) { s->failed_pc=0x0c0839f2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083a0eu,2);
goto P_0c0839f4;
P_0c0839f4: /* original d30a, guest PC 0x0c0839f4 */
if(!s->budget--) { s->failed_pc=0x0c0839f4u; return 0; }
r[3]=read(ram,0x0c083a20u,4);
goto P_0c0839f6;
P_0c0839f6: /* original 36ec, guest PC 0x0c0839f6 */
if(!s->budget--) { s->failed_pc=0x0c0839f6u; return 0; }
r[6]+=r[14];
goto P_0c0839f8;
P_0c0839f8: /* original 65f2, guest PC 0x0c0839f8 */
if(!s->budget--) { s->failed_pc=0x0c0839f8u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0839fa;
P_0c0839fa: /* original 36cc, guest PC 0x0c0839fa */
if(!s->budget--) { s->failed_pc=0x0c0839fau; return 0; }
r[6]+=r[12];
goto P_0c0839fc;
P_0c0839fc: /* original 5668, guest PC 0x0c0839fc */
if(!s->budget--) { s->failed_pc=0x0c0839fcu; return 0; }
r[6]=read(ram,r[6]+32,4);
goto P_0c0839fe;
P_0c0839fe: /* original 430b, guest PC 0x0c0839fe */
if(!s->budget--) { s->failed_pc=0x0c0839feu; return 0; }
target=r[3];
r[16]=code_base|0x0c083a02u;
r[4]=0x00000031u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083a02u) { target=s->pc; goto dispatch; }
goto P_0c083a02;
P_0c083a00: /* original e431, guest PC 0x0c083a00 */
if(!s->budget--) { s->failed_pc=0x0c083a00u; return 0; }
r[4]=0x00000031u;
goto P_0c083a02;
P_0c083a02: /* original a035, guest PC 0x0c083a02 */
if(!s->budget--) { s->failed_pc=0x0c083a02u; return 0; }
goto P_0c083a70;
P_0c083a04: /* original 0009, guest PC 0x0c083a04 */
if(!s->budget--) { s->failed_pc=0x0c083a04u; return 0; }
return vf3_matrix_family(0x0c083a06u,s,ram);
P_0c083a24: /* original d34a, guest PC 0x0c083a24 */
if(!s->budget--) { s->failed_pc=0x0c083a24u; return 0; }
r[3]=read(ram,0x0c083b50u,4);
goto P_0c083a26;
P_0c083a26: /* original 65d3, guest PC 0x0c083a26 */
if(!s->budget--) { s->failed_pc=0x0c083a26u; return 0; }
r[5]=r[13];
goto P_0c083a28;
P_0c083a28: /* original 6693, guest PC 0x0c083a28 */
if(!s->budget--) { s->failed_pc=0x0c083a28u; return 0; }
r[6]=r[9];
goto P_0c083a2a;
P_0c083a2a: /* original 430b, guest PC 0x0c083a2a */
if(!s->budget--) { s->failed_pc=0x0c083a2au; return 0; }
target=r[3];
r[16]=code_base|0x0c083a2eu;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083a2eu) { target=s->pc; goto dispatch; }
goto P_0c083a2e;
P_0c083a2c: /* original e412, guest PC 0x0c083a2c */
if(!s->budget--) { s->failed_pc=0x0c083a2cu; return 0; }
r[4]=0x00000012u;
goto P_0c083a2e;
P_0c083a2e: /* original 9685, guest PC 0x0c083a2e */
if(!s->budget--) { s->failed_pc=0x0c083a2eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083b3cu,2);
goto P_0c083a30;
P_0c083a30: /* original 65d3, guest PC 0x0c083a30 */
if(!s->budget--) { s->failed_pc=0x0c083a30u; return 0; }
r[5]=r[13];
goto P_0c083a32;
P_0c083a32: /* original d348, guest PC 0x0c083a32 */
if(!s->budget--) { s->failed_pc=0x0c083a32u; return 0; }
r[3]=read(ram,0x0c083b54u,4);
goto P_0c083a34;
P_0c083a34: /* original 36ec, guest PC 0x0c083a34 */
if(!s->budget--) { s->failed_pc=0x0c083a34u; return 0; }
r[6]+=r[14];
goto P_0c083a36;
P_0c083a36: /* original 36cc, guest PC 0x0c083a36 */
if(!s->budget--) { s->failed_pc=0x0c083a36u; return 0; }
r[6]+=r[12];
goto P_0c083a38;
P_0c083a38: /* original 5668, guest PC 0x0c083a38 */
if(!s->budget--) { s->failed_pc=0x0c083a38u; return 0; }
r[6]=read(ram,r[6]+32,4);
goto P_0c083a3a;
P_0c083a3a: /* original 430b, guest PC 0x0c083a3a */
if(!s->budget--) { s->failed_pc=0x0c083a3au; return 0; }
target=r[3];
r[16]=code_base|0x0c083a3eu;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083a3eu) { target=s->pc; goto dispatch; }
goto P_0c083a3e;
P_0c083a3c: /* original e414, guest PC 0x0c083a3c */
if(!s->budget--) { s->failed_pc=0x0c083a3cu; return 0; }
r[4]=0x00000014u;
goto P_0c083a3e;
P_0c083a3e: /* original 967d, guest PC 0x0c083a3e */
if(!s->budget--) { s->failed_pc=0x0c083a3eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083b3cu,2);
goto P_0c083a40;
P_0c083a40: /* original d344, guest PC 0x0c083a40 */
if(!s->budget--) { s->failed_pc=0x0c083a40u; return 0; }
r[3]=read(ram,0x0c083b54u,4);
goto P_0c083a42;
P_0c083a42: /* original 36ec, guest PC 0x0c083a42 */
if(!s->budget--) { s->failed_pc=0x0c083a42u; return 0; }
r[6]+=r[14];
goto P_0c083a44;
P_0c083a44: /* original 65f2, guest PC 0x0c083a44 */
if(!s->budget--) { s->failed_pc=0x0c083a44u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083a46;
P_0c083a46: /* original 36cc, guest PC 0x0c083a46 */
if(!s->budget--) { s->failed_pc=0x0c083a46u; return 0; }
r[6]+=r[12];
goto P_0c083a48;
P_0c083a48: /* original 5668, guest PC 0x0c083a48 */
if(!s->budget--) { s->failed_pc=0x0c083a48u; return 0; }
r[6]=read(ram,r[6]+32,4);
goto P_0c083a4a;
P_0c083a4a: /* original 430b, guest PC 0x0c083a4a */
if(!s->budget--) { s->failed_pc=0x0c083a4au; return 0; }
target=r[3];
r[16]=code_base|0x0c083a4eu;
r[4]=0x00000031u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083a4eu) { target=s->pc; goto dispatch; }
goto P_0c083a4e;
P_0c083a4c: /* original e431, guest PC 0x0c083a4c */
if(!s->budget--) { s->failed_pc=0x0c083a4cu; return 0; }
r[4]=0x00000031u;
goto P_0c083a4e;
P_0c083a4e: /* original a00f, guest PC 0x0c083a4e */
if(!s->budget--) { s->failed_pc=0x0c083a4eu; return 0; }
goto P_0c083a70;
P_0c083a50: /* original 0009, guest PC 0x0c083a50 */
if(!s->budget--) { s->failed_pc=0x0c083a50u; return 0; }
goto P_0c083a52;
P_0c083a52: /* original d33f, guest PC 0x0c083a52 */
if(!s->budget--) { s->failed_pc=0x0c083a52u; return 0; }
r[3]=read(ram,0x0c083b50u,4);
goto P_0c083a54;
P_0c083a54: /* original 65d3, guest PC 0x0c083a54 */
if(!s->budget--) { s->failed_pc=0x0c083a54u; return 0; }
r[5]=r[13];
goto P_0c083a56;
P_0c083a56: /* original 6693, guest PC 0x0c083a56 */
if(!s->budget--) { s->failed_pc=0x0c083a56u; return 0; }
r[6]=r[9];
goto P_0c083a58;
P_0c083a58: /* original 430b, guest PC 0x0c083a58 */
if(!s->budget--) { s->failed_pc=0x0c083a58u; return 0; }
target=r[3];
r[16]=code_base|0x0c083a5cu;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083a5cu) { target=s->pc; goto dispatch; }
goto P_0c083a5c;
P_0c083a5a: /* original e412, guest PC 0x0c083a5a */
if(!s->budget--) { s->failed_pc=0x0c083a5au; return 0; }
r[4]=0x00000012u;
goto P_0c083a5c;
P_0c083a5c: /* original d23d, guest PC 0x0c083a5c */
if(!s->budget--) { s->failed_pc=0x0c083a5cu; return 0; }
r[2]=read(ram,0x0c083b54u,4);
goto P_0c083a5e;
P_0c083a5e: /* original 65d3, guest PC 0x0c083a5e */
if(!s->budget--) { s->failed_pc=0x0c083a5eu; return 0; }
r[5]=r[13];
goto P_0c083a60;
P_0c083a60: /* original e610, guest PC 0x0c083a60 */
if(!s->budget--) { s->failed_pc=0x0c083a60u; return 0; }
r[6]=0x00000010u;
goto P_0c083a62;
P_0c083a62: /* original 420b, guest PC 0x0c083a62 */
if(!s->budget--) { s->failed_pc=0x0c083a62u; return 0; }
target=r[2];
r[16]=code_base|0x0c083a66u;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083a66u) { target=s->pc; goto dispatch; }
goto P_0c083a66;
P_0c083a64: /* original e407, guest PC 0x0c083a64 */
if(!s->budget--) { s->failed_pc=0x0c083a64u; return 0; }
r[4]=0x00000007u;
goto P_0c083a66;
P_0c083a66: /* original d33b, guest PC 0x0c083a66 */
if(!s->budget--) { s->failed_pc=0x0c083a66u; return 0; }
r[3]=read(ram,0x0c083b54u,4);
goto P_0c083a68;
P_0c083a68: /* original e610, guest PC 0x0c083a68 */
if(!s->budget--) { s->failed_pc=0x0c083a68u; return 0; }
r[6]=0x00000010u;
goto P_0c083a6a;
P_0c083a6a: /* original 65f2, guest PC 0x0c083a6a */
if(!s->budget--) { s->failed_pc=0x0c083a6au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c083a6c;
P_0c083a6c: /* original 430b, guest PC 0x0c083a6c */
if(!s->budget--) { s->failed_pc=0x0c083a6cu; return 0; }
target=r[3];
r[16]=code_base|0x0c083a70u;
r[4]=0x00000031u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083a70u) { target=s->pc; goto dispatch; }
goto P_0c083a70;
P_0c083a6e: /* original e431, guest PC 0x0c083a6e */
if(!s->budget--) { s->failed_pc=0x0c083a6eu; return 0; }
r[4]=0x00000031u;
goto P_0c083a70;
P_0c083a70: /* original 7a01, guest PC 0x0c083a70 */
if(!s->budget--) { s->failed_pc=0x0c083a70u; return 0; }
r[10]+=0x00000001u;
goto P_0c083a72;
P_0c083a72: /* original 7d0c, guest PC 0x0c083a72 */
if(!s->budget--) { s->failed_pc=0x0c083a72u; return 0; }
r[13]+=0x0000000cu;
goto P_0c083a74;
P_0c083a74: /* original e402, guest PC 0x0c083a74 */
if(!s->budget--) { s->failed_pc=0x0c083a74u; return 0; }
r[4]=0x00000002u;
goto P_0c083a76;
P_0c083a76: /* original 3a43, guest PC 0x0c083a76 */
if(!s->budget--) { s->failed_pc=0x0c083a76u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[4])!=0);
goto P_0c083a78;
P_0c083a78: /* original 8901, guest PC 0x0c083a78 */
if(!s->budget--) { s->failed_pc=0x0c083a78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c083a7e; }
goto P_0c083a7a;
P_0c083a7a: /* original abce, guest PC 0x0c083a7a */
if(!s->budget--) { s->failed_pc=0x0c083a7au; return 0; }
goto P_0c08321a;
P_0c083a7c: /* original 0009, guest PC 0x0c083a7c */
if(!s->budget--) { s->failed_pc=0x0c083a7cu; return 0; }
goto P_0c083a7e;
P_0c083a7e: /* original 54f3, guest PC 0x0c083a7e */
if(!s->budget--) { s->failed_pc=0x0c083a7eu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c083a80;
P_0c083a80: /* original 55f4, guest PC 0x0c083a80 */
if(!s->budget--) { s->failed_pc=0x0c083a80u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c083a82;
P_0c083a82: /* original 7f14, guest PC 0x0c083a82 */
if(!s->budget--) { s->failed_pc=0x0c083a82u; return 0; }
r[15]+=0x00000014u;
goto P_0c083a84;
P_0c083a84: /* original 4f26, guest PC 0x0c083a84 */
if(!s->budget--) { s->failed_pc=0x0c083a84u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c083a86;
P_0c083a86: /* original d334, guest PC 0x0c083a86 */
if(!s->budget--) { s->failed_pc=0x0c083a86u; return 0; }
r[3]=read(ram,0x0c083b58u,4);
goto P_0c083a88;
P_0c083a88: /* original 68f6, guest PC 0x0c083a88 */
if(!s->budget--) { s->failed_pc=0x0c083a88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c083a8a;
P_0c083a8a: /* original 69f6, guest PC 0x0c083a8a */
if(!s->budget--) { s->failed_pc=0x0c083a8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c083a8c;
P_0c083a8c: /* original 6af6, guest PC 0x0c083a8c */
if(!s->budget--) { s->failed_pc=0x0c083a8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c083a8e;
P_0c083a8e: /* original 6bf6, guest PC 0x0c083a8e */
if(!s->budget--) { s->failed_pc=0x0c083a8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c083a90;
P_0c083a90: /* original 6cf6, guest PC 0x0c083a90 */
if(!s->budget--) { s->failed_pc=0x0c083a90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c083a92;
P_0c083a92: /* original 6df6, guest PC 0x0c083a92 */
if(!s->budget--) { s->failed_pc=0x0c083a92u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c083a94;
P_0c083a94: /* original 432b, guest PC 0x0c083a94 */
if(!s->budget--) { s->failed_pc=0x0c083a94u; return 0; }
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
P_0c083a96: /* original 6ef6, guest PC 0x0c083a96 */
if(!s->budget--) { s->failed_pc=0x0c083a96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c083a98u,s,ram);
P_0c091028: /* original 2fe6, guest PC 0x0c091028 */
if(!s->budget--) { s->failed_pc=0x0c091028u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09102a;
P_0c09102a: /* original 4f22, guest PC 0x0c09102a */
if(!s->budget--) { s->failed_pc=0x0c09102au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09102c;
P_0c09102c: /* original d318, guest PC 0x0c09102c */
if(!s->budget--) { s->failed_pc=0x0c09102cu; return 0; }
r[3]=read(ram,0x0c091090u,4);
goto P_0c09102e;
P_0c09102e: /* original 430b, guest PC 0x0c09102e */
if(!s->budget--) { s->failed_pc=0x0c09102eu; return 0; }
target=r[3];
r[16]=code_base|0x0c091032u;
r[14]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091032u) { target=s->pc; goto dispatch; }
goto P_0c091032;
P_0c091030: /* original 6e43, guest PC 0x0c091030 */
if(!s->budget--) { s->failed_pc=0x0c091030u; return 0; }
r[14]=r[4];
goto P_0c091032;
P_0c091032: /* original be2b, guest PC 0x0c091032 */
if(!s->budget--) { s->failed_pc=0x0c091032u; return 0; }
target=0x0c090c8cu; r[16]=code_base|0x0c091036u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091036u) { target=s->pc; goto dispatch; }
goto P_0c091036;
P_0c091034: /* original 64e3, guest PC 0x0c091034 */
if(!s->budget--) { s->failed_pc=0x0c091034u; return 0; }
r[4]=r[14];
goto P_0c091036;
P_0c091036: /* original 4f26, guest PC 0x0c091036 */
if(!s->budget--) { s->failed_pc=0x0c091036u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c091038;
P_0c091038: /* original 9024, guest PC 0x0c091038 */
if(!s->budget--) { s->failed_pc=0x0c091038u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091084u,2);
goto P_0c09103a;
P_0c09103a: /* original e305, guest PC 0x0c09103a */
if(!s->budget--) { s->failed_pc=0x0c09103au; return 0; }
r[3]=0x00000005u;
goto P_0c09103c;
P_0c09103c: /* original 64e3, guest PC 0x0c09103c */
if(!s->budget--) { s->failed_pc=0x0c09103cu; return 0; }
r[4]=r[14];
goto P_0c09103e;
P_0c09103e: /* original 0e34, guest PC 0x0c09103e */
if(!s->budget--) { s->failed_pc=0x0c09103eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c091040;
P_0c091040: /* original a000, guest PC 0x0c091040 */
if(!s->budget--) { s->failed_pc=0x0c091040u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c091044;
P_0c091042: /* original 6ef6, guest PC 0x0c091042 */
if(!s->budget--) { s->failed_pc=0x0c091042u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c091044;
P_0c091044: /* original 2fe6, guest PC 0x0c091044 */
if(!s->budget--) { s->failed_pc=0x0c091044u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091046;
P_0c091046: /* original d115, guest PC 0x0c091046 */
if(!s->budget--) { s->failed_pc=0x0c091046u; return 0; }
r[1]=read(ram,0x0c09109cu,4);
goto P_0c091048;
P_0c091048: /* original 4f22, guest PC 0x0c091048 */
if(!s->budget--) { s->failed_pc=0x0c091048u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09104a;
P_0c09104a: /* original 6212, guest PC 0x0c09104a */
if(!s->budget--) { s->failed_pc=0x0c09104au; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c09104c;
P_0c09104c: /* original d312, guest PC 0x0c09104c */
if(!s->budget--) { s->failed_pc=0x0c09104cu; return 0; }
r[3]=read(ram,0x0c091098u,4);
goto P_0c09104e;
P_0c09104e: /* original 2238, guest PC 0x0c09104e */
if(!s->budget--) { s->failed_pc=0x0c09104eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c091050;
P_0c091050: /* original 8f14, guest PC 0x0c091050 */
if(!s->budget--) { s->failed_pc=0x0c091050u; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(!cond) { goto P_0c09107c; }
goto P_0c091054;
P_0c091052: /* original 6e43, guest PC 0x0c091052 */
if(!s->budget--) { s->failed_pc=0x0c091052u; return 0; }
r[14]=r[4];
goto P_0c091054;
P_0c091054: /* original d313, guest PC 0x0c091054 */
if(!s->budget--) { s->failed_pc=0x0c091054u; return 0; }
r[3]=read(ram,0x0c0910a4u,4);
goto P_0c091056;
P_0c091056: /* original 430b, guest PC 0x0c091056 */
if(!s->budget--) { s->failed_pc=0x0c091056u; return 0; }
target=r[3];
r[16]=code_base|0x0c09105au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09105au) { target=s->pc; goto dispatch; }
goto P_0c09105a;
P_0c091058: /* original 64e3, guest PC 0x0c091058 */
if(!s->budget--) { s->failed_pc=0x0c091058u; return 0; }
r[4]=r[14];
goto P_0c09105a;
P_0c09105a: /* original d213, guest PC 0x0c09105a */
if(!s->budget--) { s->failed_pc=0x0c09105au; return 0; }
r[2]=read(ram,0x0c0910a8u,4);
goto P_0c09105c;
P_0c09105c: /* original 420b, guest PC 0x0c09105c */
if(!s->budget--) { s->failed_pc=0x0c09105cu; return 0; }
target=r[2];
r[16]=code_base|0x0c091060u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091060u) { target=s->pc; goto dispatch; }
goto P_0c091060;
P_0c09105e: /* original 64e3, guest PC 0x0c09105e */
if(!s->budget--) { s->failed_pc=0x0c09105eu; return 0; }
r[4]=r[14];
goto P_0c091060;
P_0c091060: /* original d312, guest PC 0x0c091060 */
if(!s->budget--) { s->failed_pc=0x0c091060u; return 0; }
r[3]=read(ram,0x0c0910acu,4);
goto P_0c091062;
P_0c091062: /* original 430b, guest PC 0x0c091062 */
if(!s->budget--) { s->failed_pc=0x0c091062u; return 0; }
target=r[3];
r[16]=code_base|0x0c091066u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091066u) { target=s->pc; goto dispatch; }
goto P_0c091066;
P_0c091064: /* original 64e3, guest PC 0x0c091064 */
if(!s->budget--) { s->failed_pc=0x0c091064u; return 0; }
r[4]=r[14];
goto P_0c091066;
P_0c091066: /* original d212, guest PC 0x0c091066 */
if(!s->budget--) { s->failed_pc=0x0c091066u; return 0; }
r[2]=read(ram,0x0c0910b0u,4);
goto P_0c091068;
P_0c091068: /* original 420b, guest PC 0x0c091068 */
if(!s->budget--) { s->failed_pc=0x0c091068u; return 0; }
target=r[2];
r[16]=code_base|0x0c09106cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09106cu) { target=s->pc; goto dispatch; }
goto P_0c09106c;
P_0c09106a: /* original 64e3, guest PC 0x0c09106a */
if(!s->budget--) { s->failed_pc=0x0c09106au; return 0; }
r[4]=r[14];
goto P_0c09106c;
P_0c09106c: /* original bb23, guest PC 0x0c09106c */
if(!s->budget--) { s->failed_pc=0x0c09106cu; return 0; }
target=0x0c0906b6u; r[16]=code_base|0x0c091070u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091070u) { target=s->pc; goto dispatch; }
goto P_0c091070;
P_0c09106e: /* original 64e3, guest PC 0x0c09106e */
if(!s->budget--) { s->failed_pc=0x0c09106eu; return 0; }
r[4]=r[14];
goto P_0c091070;
P_0c091070: /* original d210, guest PC 0x0c091070 */
if(!s->budget--) { s->failed_pc=0x0c091070u; return 0; }
r[2]=read(ram,0x0c0910b4u,4);
goto P_0c091072;
P_0c091072: /* original 420b, guest PC 0x0c091072 */
if(!s->budget--) { s->failed_pc=0x0c091072u; return 0; }
target=r[2];
r[16]=code_base|0x0c091076u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091076u) { target=s->pc; goto dispatch; }
goto P_0c091076;
P_0c091074: /* original 64e3, guest PC 0x0c091074 */
if(!s->budget--) { s->failed_pc=0x0c091074u; return 0; }
r[4]=r[14];
goto P_0c091076;
P_0c091076: /* original d310, guest PC 0x0c091076 */
if(!s->budget--) { s->failed_pc=0x0c091076u; return 0; }
r[3]=read(ram,0x0c0910b8u,4);
goto P_0c091078;
P_0c091078: /* original 430b, guest PC 0x0c091078 */
if(!s->budget--) { s->failed_pc=0x0c091078u; return 0; }
target=r[3];
r[16]=code_base|0x0c09107cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09107cu) { target=s->pc; goto dispatch; }
goto P_0c09107c;
P_0c09107a: /* original 64e3, guest PC 0x0c09107a */
if(!s->budget--) { s->failed_pc=0x0c09107au; return 0; }
r[4]=r[14];
goto P_0c09107c;
P_0c09107c: /* original 4f26, guest PC 0x0c09107c */
if(!s->budget--) { s->failed_pc=0x0c09107cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09107e;
P_0c09107e: /* original 000b, guest PC 0x0c09107e */
if(!s->budget--) { s->failed_pc=0x0c09107eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c091080: /* original 6ef6, guest PC 0x0c091080 */
if(!s->budget--) { s->failed_pc=0x0c091080u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c091082u,s,ram);
P_0c091108: /* original 2fe6, guest PC 0x0c091108 */
if(!s->budget--) { s->failed_pc=0x0c091108u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09110a;
P_0c09110a: /* original d131, guest PC 0x0c09110a */
if(!s->budget--) { s->failed_pc=0x0c09110au; return 0; }
r[1]=read(ram,0x0c0911d0u,4);
goto P_0c09110c;
P_0c09110c: /* original 4f22, guest PC 0x0c09110c */
if(!s->budget--) { s->failed_pc=0x0c09110cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09110e;
P_0c09110e: /* original 6212, guest PC 0x0c09110e */
if(!s->budget--) { s->failed_pc=0x0c09110eu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c091110;
P_0c091110: /* original d32e, guest PC 0x0c091110 */
if(!s->budget--) { s->failed_pc=0x0c091110u; return 0; }
r[3]=read(ram,0x0c0911ccu,4);
goto P_0c091112;
P_0c091112: /* original 2238, guest PC 0x0c091112 */
if(!s->budget--) { s->failed_pc=0x0c091112u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c091114;
P_0c091114: /* original 8f11, guest PC 0x0c091114 */
if(!s->budget--) { s->failed_pc=0x0c091114u; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(!cond) { goto P_0c09113a; }
goto P_0c091118;
P_0c091116: /* original 6e43, guest PC 0x0c091116 */
if(!s->budget--) { s->failed_pc=0x0c091116u; return 0; }
r[14]=r[4];
goto P_0c091118;
P_0c091118: /* original d32e, guest PC 0x0c091118 */
if(!s->budget--) { s->failed_pc=0x0c091118u; return 0; }
r[3]=read(ram,0x0c0911d4u,4);
goto P_0c09111a;
P_0c09111a: /* original 430b, guest PC 0x0c09111a */
if(!s->budget--) { s->failed_pc=0x0c09111au; return 0; }
target=r[3];
r[16]=code_base|0x0c09111eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09111eu) { target=s->pc; goto dispatch; }
goto P_0c09111e;
P_0c09111c: /* original 64e3, guest PC 0x0c09111c */
if(!s->budget--) { s->failed_pc=0x0c09111cu; return 0; }
r[4]=r[14];
goto P_0c09111e;
P_0c09111e: /* original d22e, guest PC 0x0c09111e */
if(!s->budget--) { s->failed_pc=0x0c09111eu; return 0; }
r[2]=read(ram,0x0c0911d8u,4);
goto P_0c091120;
P_0c091120: /* original 420b, guest PC 0x0c091120 */
if(!s->budget--) { s->failed_pc=0x0c091120u; return 0; }
target=r[2];
r[16]=code_base|0x0c091124u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091124u) { target=s->pc; goto dispatch; }
goto P_0c091124;
P_0c091122: /* original 64e3, guest PC 0x0c091122 */
if(!s->budget--) { s->failed_pc=0x0c091122u; return 0; }
r[4]=r[14];
goto P_0c091124;
P_0c091124: /* original d32d, guest PC 0x0c091124 */
if(!s->budget--) { s->failed_pc=0x0c091124u; return 0; }
r[3]=read(ram,0x0c0911dcu,4);
goto P_0c091126;
P_0c091126: /* original 430b, guest PC 0x0c091126 */
if(!s->budget--) { s->failed_pc=0x0c091126u; return 0; }
target=r[3];
r[16]=code_base|0x0c09112au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09112au) { target=s->pc; goto dispatch; }
goto P_0c09112a;
P_0c091128: /* original 64e3, guest PC 0x0c091128 */
if(!s->budget--) { s->failed_pc=0x0c091128u; return 0; }
r[4]=r[14];
goto P_0c09112a;
P_0c09112a: /* original bb59, guest PC 0x0c09112a */
if(!s->budget--) { s->failed_pc=0x0c09112au; return 0; }
target=0x0c0907e0u; r[16]=code_base|0x0c09112eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09112eu) { target=s->pc; goto dispatch; }
goto P_0c09112e;
P_0c09112c: /* original 64e3, guest PC 0x0c09112c */
if(!s->budget--) { s->failed_pc=0x0c09112cu; return 0; }
r[4]=r[14];
goto P_0c09112e;
P_0c09112e: /* original d32c, guest PC 0x0c09112e */
if(!s->budget--) { s->failed_pc=0x0c09112eu; return 0; }
r[3]=read(ram,0x0c0911e0u,4);
goto P_0c091130;
P_0c091130: /* original 430b, guest PC 0x0c091130 */
if(!s->budget--) { s->failed_pc=0x0c091130u; return 0; }
target=r[3];
r[16]=code_base|0x0c091134u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091134u) { target=s->pc; goto dispatch; }
goto P_0c091134;
P_0c091132: /* original 64e3, guest PC 0x0c091132 */
if(!s->budget--) { s->failed_pc=0x0c091132u; return 0; }
r[4]=r[14];
goto P_0c091134;
P_0c091134: /* original d22b, guest PC 0x0c091134 */
if(!s->budget--) { s->failed_pc=0x0c091134u; return 0; }
r[2]=read(ram,0x0c0911e4u,4);
goto P_0c091136;
P_0c091136: /* original 420b, guest PC 0x0c091136 */
if(!s->budget--) { s->failed_pc=0x0c091136u; return 0; }
target=r[2];
r[16]=code_base|0x0c09113au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09113au) { target=s->pc; goto dispatch; }
goto P_0c09113a;
P_0c091138: /* original 64e3, guest PC 0x0c091138 */
if(!s->budget--) { s->failed_pc=0x0c091138u; return 0; }
r[4]=r[14];
goto P_0c09113a;
P_0c09113a: /* original 4f26, guest PC 0x0c09113a */
if(!s->budget--) { s->failed_pc=0x0c09113au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09113c;
P_0c09113c: /* original 000b, guest PC 0x0c09113c */
if(!s->budget--) { s->failed_pc=0x0c09113cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09113e: /* original 6ef6, guest PC 0x0c09113e */
if(!s->budget--) { s->failed_pc=0x0c09113eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c091140u,s,ram);
P_0c091180: /* original 2fe6, guest PC 0x0c091180 */
if(!s->budget--) { s->failed_pc=0x0c091180u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091182;
P_0c091182: /* original d113, guest PC 0x0c091182 */
if(!s->budget--) { s->failed_pc=0x0c091182u; return 0; }
r[1]=read(ram,0x0c0911d0u,4);
goto P_0c091184;
P_0c091184: /* original 4f22, guest PC 0x0c091184 */
if(!s->budget--) { s->failed_pc=0x0c091184u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c091186;
P_0c091186: /* original 6212, guest PC 0x0c091186 */
if(!s->budget--) { s->failed_pc=0x0c091186u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c091188;
P_0c091188: /* original d310, guest PC 0x0c091188 */
if(!s->budget--) { s->failed_pc=0x0c091188u; return 0; }
r[3]=read(ram,0x0c0911ccu,4);
goto P_0c09118a;
P_0c09118a: /* original 2238, guest PC 0x0c09118a */
if(!s->budget--) { s->failed_pc=0x0c09118au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09118c;
P_0c09118c: /* original 8f11, guest PC 0x0c09118c */
if(!s->budget--) { s->failed_pc=0x0c09118cu; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(!cond) { goto P_0c0911b2; }
goto P_0c091190;
P_0c09118e: /* original 6e43, guest PC 0x0c09118e */
if(!s->budget--) { s->failed_pc=0x0c09118eu; return 0; }
r[14]=r[4];
goto P_0c091190;
P_0c091190: /* original d310, guest PC 0x0c091190 */
if(!s->budget--) { s->failed_pc=0x0c091190u; return 0; }
r[3]=read(ram,0x0c0911d4u,4);
goto P_0c091192;
P_0c091192: /* original 430b, guest PC 0x0c091192 */
if(!s->budget--) { s->failed_pc=0x0c091192u; return 0; }
target=r[3];
r[16]=code_base|0x0c091196u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091196u) { target=s->pc; goto dispatch; }
goto P_0c091196;
P_0c091194: /* original 64e3, guest PC 0x0c091194 */
if(!s->budget--) { s->failed_pc=0x0c091194u; return 0; }
r[4]=r[14];
goto P_0c091196;
P_0c091196: /* original d210, guest PC 0x0c091196 */
if(!s->budget--) { s->failed_pc=0x0c091196u; return 0; }
r[2]=read(ram,0x0c0911d8u,4);
goto P_0c091198;
P_0c091198: /* original 420b, guest PC 0x0c091198 */
if(!s->budget--) { s->failed_pc=0x0c091198u; return 0; }
target=r[2];
r[16]=code_base|0x0c09119cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09119cu) { target=s->pc; goto dispatch; }
goto P_0c09119c;
P_0c09119a: /* original 64e3, guest PC 0x0c09119a */
if(!s->budget--) { s->failed_pc=0x0c09119au; return 0; }
r[4]=r[14];
goto P_0c09119c;
P_0c09119c: /* original d30f, guest PC 0x0c09119c */
if(!s->budget--) { s->failed_pc=0x0c09119cu; return 0; }
r[3]=read(ram,0x0c0911dcu,4);
goto P_0c09119e;
P_0c09119e: /* original 430b, guest PC 0x0c09119e */
if(!s->budget--) { s->failed_pc=0x0c09119eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0911a2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0911a2u) { target=s->pc; goto dispatch; }
goto P_0c0911a2;
P_0c0911a0: /* original 64e3, guest PC 0x0c0911a0 */
if(!s->budget--) { s->failed_pc=0x0c0911a0u; return 0; }
r[4]=r[14];
goto P_0c0911a2;
P_0c0911a2: /* original bb1d, guest PC 0x0c0911a2 */
if(!s->budget--) { s->failed_pc=0x0c0911a2u; return 0; }
target=0x0c0907e0u; r[16]=code_base|0x0c0911a6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0911a6u) { target=s->pc; goto dispatch; }
goto P_0c0911a6;
P_0c0911a4: /* original 64e3, guest PC 0x0c0911a4 */
if(!s->budget--) { s->failed_pc=0x0c0911a4u; return 0; }
r[4]=r[14];
goto P_0c0911a6;
P_0c0911a6: /* original d30e, guest PC 0x0c0911a6 */
if(!s->budget--) { s->failed_pc=0x0c0911a6u; return 0; }
r[3]=read(ram,0x0c0911e0u,4);
goto P_0c0911a8;
P_0c0911a8: /* original 430b, guest PC 0x0c0911a8 */
if(!s->budget--) { s->failed_pc=0x0c0911a8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0911acu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0911acu) { target=s->pc; goto dispatch; }
goto P_0c0911ac;
P_0c0911aa: /* original 64e3, guest PC 0x0c0911aa */
if(!s->budget--) { s->failed_pc=0x0c0911aau; return 0; }
r[4]=r[14];
goto P_0c0911ac;
P_0c0911ac: /* original d20d, guest PC 0x0c0911ac */
if(!s->budget--) { s->failed_pc=0x0c0911acu; return 0; }
r[2]=read(ram,0x0c0911e4u,4);
goto P_0c0911ae;
P_0c0911ae: /* original 420b, guest PC 0x0c0911ae */
if(!s->budget--) { s->failed_pc=0x0c0911aeu; return 0; }
target=r[2];
r[16]=code_base|0x0c0911b2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0911b2u) { target=s->pc; goto dispatch; }
goto P_0c0911b2;
P_0c0911b0: /* original 64e3, guest PC 0x0c0911b0 */
if(!s->budget--) { s->failed_pc=0x0c0911b0u; return 0; }
r[4]=r[14];
goto P_0c0911b2;
P_0c0911b2: /* original 4f26, guest PC 0x0c0911b2 */
if(!s->budget--) { s->failed_pc=0x0c0911b2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0911b4;
P_0c0911b4: /* original 000b, guest PC 0x0c0911b4 */
if(!s->budget--) { s->failed_pc=0x0c0911b4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0911b6: /* original 6ef6, guest PC 0x0c0911b6 */
if(!s->budget--) { s->failed_pc=0x0c0911b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0911b8u,s,ram);
P_0c091242: /* original 2fe6, guest PC 0x0c091242 */
if(!s->budget--) { s->failed_pc=0x0c091242u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091244;
P_0c091244: /* original d12e, guest PC 0x0c091244 */
if(!s->budget--) { s->failed_pc=0x0c091244u; return 0; }
r[1]=read(ram,0x0c091300u,4);
goto P_0c091246;
P_0c091246: /* original 4f22, guest PC 0x0c091246 */
if(!s->budget--) { s->failed_pc=0x0c091246u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c091248;
P_0c091248: /* original 6212, guest PC 0x0c091248 */
if(!s->budget--) { s->failed_pc=0x0c091248u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c09124a;
P_0c09124a: /* original d32c, guest PC 0x0c09124a */
if(!s->budget--) { s->failed_pc=0x0c09124au; return 0; }
r[3]=read(ram,0x0c0912fcu,4);
goto P_0c09124c;
P_0c09124c: /* original 2238, guest PC 0x0c09124c */
if(!s->budget--) { s->failed_pc=0x0c09124cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09124e;
P_0c09124e: /* original 8f11, guest PC 0x0c09124e */
if(!s->budget--) { s->failed_pc=0x0c09124eu; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(!cond) { goto P_0c091274; }
goto P_0c091252;
P_0c091250: /* original 6e43, guest PC 0x0c091250 */
if(!s->budget--) { s->failed_pc=0x0c091250u; return 0; }
r[14]=r[4];
goto P_0c091252;
P_0c091252: /* original d32c, guest PC 0x0c091252 */
if(!s->budget--) { s->failed_pc=0x0c091252u; return 0; }
r[3]=read(ram,0x0c091304u,4);
goto P_0c091254;
P_0c091254: /* original 430b, guest PC 0x0c091254 */
if(!s->budget--) { s->failed_pc=0x0c091254u; return 0; }
target=r[3];
r[16]=code_base|0x0c091258u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091258u) { target=s->pc; goto dispatch; }
goto P_0c091258;
P_0c091256: /* original 64e3, guest PC 0x0c091256 */
if(!s->budget--) { s->failed_pc=0x0c091256u; return 0; }
r[4]=r[14];
goto P_0c091258;
P_0c091258: /* original d22b, guest PC 0x0c091258 */
if(!s->budget--) { s->failed_pc=0x0c091258u; return 0; }
r[2]=read(ram,0x0c091308u,4);
goto P_0c09125a;
P_0c09125a: /* original 420b, guest PC 0x0c09125a */
if(!s->budget--) { s->failed_pc=0x0c09125au; return 0; }
target=r[2];
r[16]=code_base|0x0c09125eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09125eu) { target=s->pc; goto dispatch; }
goto P_0c09125e;
P_0c09125c: /* original 64e3, guest PC 0x0c09125c */
if(!s->budget--) { s->failed_pc=0x0c09125cu; return 0; }
r[4]=r[14];
goto P_0c09125e;
P_0c09125e: /* original d32b, guest PC 0x0c09125e */
if(!s->budget--) { s->failed_pc=0x0c09125eu; return 0; }
r[3]=read(ram,0x0c09130cu,4);
goto P_0c091260;
P_0c091260: /* original 430b, guest PC 0x0c091260 */
if(!s->budget--) { s->failed_pc=0x0c091260u; return 0; }
target=r[3];
r[16]=code_base|0x0c091264u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091264u) { target=s->pc; goto dispatch; }
goto P_0c091264;
P_0c091262: /* original 64e3, guest PC 0x0c091262 */
if(!s->budget--) { s->failed_pc=0x0c091262u; return 0; }
r[4]=r[14];
goto P_0c091264;
P_0c091264: /* original bb7c, guest PC 0x0c091264 */
if(!s->budget--) { s->failed_pc=0x0c091264u; return 0; }
target=0x0c090960u; r[16]=code_base|0x0c091268u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091268u) { target=s->pc; goto dispatch; }
goto P_0c091268;
P_0c091266: /* original 64e3, guest PC 0x0c091266 */
if(!s->budget--) { s->failed_pc=0x0c091266u; return 0; }
r[4]=r[14];
goto P_0c091268;
P_0c091268: /* original d329, guest PC 0x0c091268 */
if(!s->budget--) { s->failed_pc=0x0c091268u; return 0; }
r[3]=read(ram,0x0c091310u,4);
goto P_0c09126a;
P_0c09126a: /* original 430b, guest PC 0x0c09126a */
if(!s->budget--) { s->failed_pc=0x0c09126au; return 0; }
target=r[3];
r[16]=code_base|0x0c09126eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09126eu) { target=s->pc; goto dispatch; }
goto P_0c09126e;
P_0c09126c: /* original 64e3, guest PC 0x0c09126c */
if(!s->budget--) { s->failed_pc=0x0c09126cu; return 0; }
r[4]=r[14];
goto P_0c09126e;
P_0c09126e: /* original d229, guest PC 0x0c09126e */
if(!s->budget--) { s->failed_pc=0x0c09126eu; return 0; }
r[2]=read(ram,0x0c091314u,4);
goto P_0c091270;
P_0c091270: /* original 420b, guest PC 0x0c091270 */
if(!s->budget--) { s->failed_pc=0x0c091270u; return 0; }
target=r[2];
r[16]=code_base|0x0c091274u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091274u) { target=s->pc; goto dispatch; }
goto P_0c091274;
P_0c091272: /* original 64e3, guest PC 0x0c091272 */
if(!s->budget--) { s->failed_pc=0x0c091272u; return 0; }
r[4]=r[14];
goto P_0c091274;
P_0c091274: /* original 4f26, guest PC 0x0c091274 */
if(!s->budget--) { s->failed_pc=0x0c091274u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c091276;
P_0c091276: /* original 000b, guest PC 0x0c091276 */
if(!s->budget--) { s->failed_pc=0x0c091276u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c091278: /* original 6ef6, guest PC 0x0c091278 */
if(!s->budget--) { s->failed_pc=0x0c091278u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09127au,s,ram);
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0975f8u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097604u) { target=s->pc; goto dispatch; }
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
P_0c09762a: /* original 6ef6, guest PC 0x0c09762a */
if(!s->budget--) { s->failed_pc=0x0c09762au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09762cu,s,ram);
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
return vf3_matrix_family(0x0c0976a6u,s,ram);
P_0c097aa4: /* original 2fe6, guest PC 0x0c097aa4 */
if(!s->budget--) { s->failed_pc=0x0c097aa4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c097aa6;
P_0c097aa6: /* original 2fd6, guest PC 0x0c097aa6 */
if(!s->budget--) { s->failed_pc=0x0c097aa6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c097aa8;
P_0c097aa8: /* original 2fc6, guest PC 0x0c097aa8 */
if(!s->budget--) { s->failed_pc=0x0c097aa8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c097aaa;
P_0c097aaa: /* original 2fb6, guest PC 0x0c097aaa */
if(!s->budget--) { s->failed_pc=0x0c097aaau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c097aac;
P_0c097aac: /* original 2fa6, guest PC 0x0c097aac */
if(!s->budget--) { s->failed_pc=0x0c097aacu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c097aae;
P_0c097aae: /* original 2f96, guest PC 0x0c097aae */
if(!s->budget--) { s->failed_pc=0x0c097aaeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c097ab0;
P_0c097ab0: /* original 2f86, guest PC 0x0c097ab0 */
if(!s->budget--) { s->failed_pc=0x0c097ab0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c097ab2;
P_0c097ab2: /* original fffb, guest PC 0x0c097ab2 */
if(!s->budget--) { s->failed_pc=0x0c097ab2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c097ab4;
P_0c097ab4: /* original 905d, guest PC 0x0c097ab4 */
if(!s->budget--) { s->failed_pc=0x0c097ab4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097b72u,2);
goto P_0c097ab6;
P_0c097ab6: /* original dc31, guest PC 0x0c097ab6 */
if(!s->budget--) { s->failed_pc=0x0c097ab6u; return 0; }
r[12]=read(ram,0x0c097b7cu,4);
goto P_0c097ab8;
P_0c097ab8: /* original de31, guest PC 0x0c097ab8 */
if(!s->budget--) { s->failed_pc=0x0c097ab8u; return 0; }
r[14]=read(ram,0x0c097b80u,4);
goto P_0c097aba;
P_0c097aba: /* original 04cc, guest PC 0x0c097aba */
if(!s->budget--) { s->failed_pc=0x0c097abau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c097abc;
P_0c097abc: /* original 4f22, guest PC 0x0c097abc */
if(!s->budget--) { s->failed_pc=0x0c097abcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c097abe;
P_0c097abe: /* original 74ff, guest PC 0x0c097abe */
if(!s->budget--) { s->failed_pc=0x0c097abeu; return 0; }
r[4]+=0xffffffffu;
goto P_0c097ac0;
P_0c097ac0: /* original 0c44, guest PC 0x0c097ac0 */
if(!s->budget--) { s->failed_pc=0x0c097ac0u; return 0; }
write(ram,r[12]+r[0],r[4],1);
goto P_0c097ac2;
P_0c097ac2: /* original 52e1, guest PC 0x0c097ac2 */
if(!s->budget--) { s->failed_pc=0x0c097ac2u; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c097ac4;
P_0c097ac4: /* original 7ff4, guest PC 0x0c097ac4 */
if(!s->budget--) { s->failed_pc=0x0c097ac4u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c097ac6;
P_0c097ac6: /* original d330, guest PC 0x0c097ac6 */
if(!s->budget--) { s->failed_pc=0x0c097ac6u; return 0; }
r[3]=read(ram,0x0c097b88u,4);
goto P_0c097ac8;
P_0c097ac8: /* original dd2e, guest PC 0x0c097ac8 */
if(!s->budget--) { s->failed_pc=0x0c097ac8u; return 0; }
r[13]=read(ram,0x0c097b84u,4);
goto P_0c097aca;
P_0c097aca: /* original 2238, guest PC 0x0c097aca */
if(!s->budget--) { s->failed_pc=0x0c097acau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c097acc;
P_0c097acc: /* original 8917, guest PC 0x0c097acc */
if(!s->budget--) { s->failed_pc=0x0c097accu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097afe; }
goto P_0c097ace;
P_0c097ace: /* original 9051, guest PC 0x0c097ace */
if(!s->budget--) { s->failed_pc=0x0c097aceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097b74u,2);
goto P_0c097ad0;
P_0c097ad0: /* original e304, guest PC 0x0c097ad0 */
if(!s->budget--) { s->failed_pc=0x0c097ad0u; return 0; }
r[3]=0x00000004u;
goto P_0c097ad2;
P_0c097ad2: /* original 55d4, guest PC 0x0c097ad2 */
if(!s->budget--) { s->failed_pc=0x0c097ad2u; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c097ad4;
P_0c097ad4: /* original 055e, guest PC 0x0c097ad4 */
if(!s->budget--) { s->failed_pc=0x0c097ad4u; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c097ad6;
P_0c097ad6: /* original 2538, guest PC 0x0c097ad6 */
if(!s->budget--) { s->failed_pc=0x0c097ad6u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c097ad8;
P_0c097ad8: /* original 8f06, guest PC 0x0c097ad8 */
if(!s->budget--) { s->failed_pc=0x0c097ad8u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[13]+20,4);
if(!cond) { goto P_0c097ae8; }
goto P_0c097adc;
P_0c097ada: /* original 54d5, guest PC 0x0c097ada */
if(!s->budget--) { s->failed_pc=0x0c097adau; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c097adc;
P_0c097adc: /* original 904b, guest PC 0x0c097adc */
if(!s->budget--) { s->failed_pc=0x0c097adcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097b76u,2);
goto P_0c097ade;
P_0c097ade: /* original 914a, guest PC 0x0c097ade */
if(!s->budget--) { s->failed_pc=0x0c097adeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097b76u,2);
goto P_0c097ae0;
P_0c097ae0: /* original 00cc, guest PC 0x0c097ae0 */
if(!s->budget--) { s->failed_pc=0x0c097ae0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c097ae2;
P_0c097ae2: /* original 31cc, guest PC 0x0c097ae2 */
if(!s->budget--) { s->failed_pc=0x0c097ae2u; return 0; }
r[1]+=r[12];
goto P_0c097ae4;
P_0c097ae4: /* original cb01, guest PC 0x0c097ae4 */
if(!s->budget--) { s->failed_pc=0x0c097ae4u; return 0; }
r[0]|=1u;
goto P_0c097ae6;
P_0c097ae6: /* original 2100, guest PC 0x0c097ae6 */
if(!s->budget--) { s->failed_pc=0x0c097ae6u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c097ae8;
P_0c097ae8: /* original 9044, guest PC 0x0c097ae8 */
if(!s->budget--) { s->failed_pc=0x0c097ae8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097b74u,2);
goto P_0c097aea;
P_0c097aea: /* original e304, guest PC 0x0c097aea */
if(!s->budget--) { s->failed_pc=0x0c097aeau; return 0; }
r[3]=0x00000004u;
goto P_0c097aec;
P_0c097aec: /* original 044e, guest PC 0x0c097aec */
if(!s->budget--) { s->failed_pc=0x0c097aecu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c097aee;
P_0c097aee: /* original 2438, guest PC 0x0c097aee */
if(!s->budget--) { s->failed_pc=0x0c097aeeu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c097af0;
P_0c097af0: /* original 8b05, guest PC 0x0c097af0 */
if(!s->budget--) { s->failed_pc=0x0c097af0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c097afe; }
goto P_0c097af2;
P_0c097af2: /* original 9040, guest PC 0x0c097af2 */
if(!s->budget--) { s->failed_pc=0x0c097af2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097b76u,2);
goto P_0c097af4;
P_0c097af4: /* original 913f, guest PC 0x0c097af4 */
if(!s->budget--) { s->failed_pc=0x0c097af4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097b76u,2);
goto P_0c097af6;
P_0c097af6: /* original 00cc, guest PC 0x0c097af6 */
if(!s->budget--) { s->failed_pc=0x0c097af6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c097af8;
P_0c097af8: /* original 31cc, guest PC 0x0c097af8 */
if(!s->budget--) { s->failed_pc=0x0c097af8u; return 0; }
r[1]+=r[12];
goto P_0c097afa;
P_0c097afa: /* original cb02, guest PC 0x0c097afa */
if(!s->budget--) { s->failed_pc=0x0c097afau; return 0; }
r[0]|=2u;
goto P_0c097afc;
P_0c097afc: /* original 2100, guest PC 0x0c097afc */
if(!s->budget--) { s->failed_pc=0x0c097afcu; return 0; }
write(ram,r[1],r[0],1);
goto P_0c097afe;
P_0c097afe: /* original e301, guest PC 0x0c097afe */
if(!s->budget--) { s->failed_pc=0x0c097afeu; return 0; }
r[3]=0x00000001u;
goto P_0c097b00;
P_0c097b00: /* original eb00, guest PC 0x0c097b00 */
if(!s->budget--) { s->failed_pc=0x0c097b00u; return 0; }
r[11]=0x00000000u;
goto P_0c097b02;
P_0c097b02: /* original e01d, guest PC 0x0c097b02 */
if(!s->budget--) { s->failed_pc=0x0c097b02u; return 0; }
r[0]=0x0000001du;
goto P_0c097b04;
P_0c097b04: /* original 0eb4, guest PC 0x0c097b04 */
if(!s->budget--) { s->failed_pc=0x0c097b04u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c097b06;
P_0c097b06: /* original da21, guest PC 0x0c097b06 */
if(!s->budget--) { s->failed_pc=0x0c097b06u; return 0; }
r[10]=read(ram,0x0c097b8cu,4);
goto P_0c097b08;
P_0c097b08: /* original 64a2, guest PC 0x0c097b08 */
if(!s->budget--) { s->failed_pc=0x0c097b08u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c097b0a;
P_0c097b0a: /* original 2348, guest PC 0x0c097b0a */
if(!s->budget--) { s->failed_pc=0x0c097b0au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c097b0c;
P_0c097b0c: /* original 8b01, guest PC 0x0c097b0c */
if(!s->budget--) { s->failed_pc=0x0c097b0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c097b12; }
goto P_0c097b0e;
P_0c097b0e: /* original a245, guest PC 0x0c097b0e */
if(!s->budget--) { s->failed_pc=0x0c097b0eu; return 0; }
goto P_0c097f9c;
P_0c097b10: /* original 0009, guest PC 0x0c097b10 */
if(!s->budget--) { s->failed_pc=0x0c097b10u; return 0; }
goto P_0c097b12;
P_0c097b12: /* original 53c2, guest PC 0x0c097b12 */
if(!s->budget--) { s->failed_pc=0x0c097b12u; return 0; }
r[3]=read(ram,r[12]+8,4);
goto P_0c097b14;
P_0c097b14: /* original d81e, guest PC 0x0c097b14 */
if(!s->budget--) { s->failed_pc=0x0c097b14u; return 0; }
r[8]=read(ram,0x0c097b90u,4);
goto P_0c097b16;
P_0c097b16: /* original 2388, guest PC 0x0c097b16 */
if(!s->budget--) { s->failed_pc=0x0c097b16u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c097b18;
P_0c097b18: /* original 8b05, guest PC 0x0c097b18 */
if(!s->budget--) { s->failed_pc=0x0c097b18u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c097b26; }
goto P_0c097b1a;
P_0c097b1a: /* original 902d, guest PC 0x0c097b1a */
if(!s->budget--) { s->failed_pc=0x0c097b1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097b78u,2);
goto P_0c097b1c;
P_0c097b1c: /* original 01ec, guest PC 0x0c097b1c */
if(!s->budget--) { s->failed_pc=0x0c097b1cu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097b1e;
P_0c097b1e: /* original 2118, guest PC 0x0c097b1e */
if(!s->budget--) { s->failed_pc=0x0c097b1eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c097b20;
P_0c097b20: /* original 8b01, guest PC 0x0c097b20 */
if(!s->budget--) { s->failed_pc=0x0c097b20u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c097b26; }
goto P_0c097b22;
P_0c097b22: /* original a244, guest PC 0x0c097b22 */
if(!s->budget--) { s->failed_pc=0x0c097b22u; return 0; }
goto P_0c097fae;
P_0c097b24: /* original 0009, guest PC 0x0c097b24 */
if(!s->budget--) { s->failed_pc=0x0c097b24u; return 0; }
goto P_0c097b26;
P_0c097b26: /* original 52da, guest PC 0x0c097b26 */
if(!s->budget--) { s->failed_pc=0x0c097b26u; return 0; }
r[2]=read(ram,r[13]+40,4);
goto P_0c097b28;
P_0c097b28: /* original 2f22, guest PC 0x0c097b28 */
if(!s->budget--) { s->failed_pc=0x0c097b28u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c097b2a;
P_0c097b2a: /* original 53db, guest PC 0x0c097b2a */
if(!s->budget--) { s->failed_pc=0x0c097b2au; return 0; }
r[3]=read(ram,r[13]+44,4);
goto P_0c097b2c;
P_0c097b2c: /* original 1f32, guest PC 0x0c097b2c */
if(!s->budget--) { s->failed_pc=0x0c097b2cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c097b2e;
P_0c097b2e: /* original 9023, guest PC 0x0c097b2e */
if(!s->budget--) { s->failed_pc=0x0c097b2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097b78u,2);
goto P_0c097b30;
P_0c097b30: /* original 03ec, guest PC 0x0c097b30 */
if(!s->budget--) { s->failed_pc=0x0c097b30u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097b32;
P_0c097b32: /* original 2338, guest PC 0x0c097b32 */
if(!s->budget--) { s->failed_pc=0x0c097b32u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c097b34;
P_0c097b34: /* original 8d02, guest PC 0x0c097b34 */
if(!s->budget--) { s->failed_pc=0x0c097b34u; return 0; }
cond=r[17]&1u;
r[9]=0x00000002u;
if(cond) { goto P_0c097b3c; }
goto P_0c097b38;
P_0c097b36: /* original e902, guest PC 0x0c097b36 */
if(!s->budget--) { s->failed_pc=0x0c097b36u; return 0; }
r[9]=0x00000002u;
goto P_0c097b38;
P_0c097b38: /* original a0f1, guest PC 0x0c097b38 */
if(!s->budget--) { s->failed_pc=0x0c097b38u; return 0; }
goto P_0c097d1e;
P_0c097b3a: /* original 0009, guest PC 0x0c097b3a */
if(!s->budget--) { s->failed_pc=0x0c097b3au; return 0; }
goto P_0c097b3c;
P_0c097b3c: /* original 2488, guest PC 0x0c097b3c */
if(!s->budget--) { s->failed_pc=0x0c097b3cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[8])==0)!=0);
goto P_0c097b3e;
P_0c097b3e: /* original 8901, guest PC 0x0c097b3e */
if(!s->budget--) { s->failed_pc=0x0c097b3eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097b44; }
goto P_0c097b40;
P_0c097b40: /* original a001, guest PC 0x0c097b40 */
if(!s->budget--) { s->failed_pc=0x0c097b40u; return 0; }
r[4]=0x00000000u;
goto P_0c097b46;
P_0c097b42: /* original e400, guest PC 0x0c097b42 */
if(!s->budget--) { s->failed_pc=0x0c097b42u; return 0; }
r[4]=0x00000000u;
goto P_0c097b44;
P_0c097b44: /* original e401, guest PC 0x0c097b44 */
if(!s->budget--) { s->failed_pc=0x0c097b44u; return 0; }
r[4]=0x00000001u;
goto P_0c097b46;
P_0c097b46: /* original d213, guest PC 0x0c097b46 */
if(!s->budget--) { s->failed_pc=0x0c097b46u; return 0; }
r[2]=read(ram,0x0c097b94u,4);
goto P_0c097b48;
P_0c097b48: /* original 420b, guest PC 0x0c097b48 */
if(!s->budget--) { s->failed_pc=0x0c097b48u; return 0; }
target=r[2];
r[16]=code_base|0x0c097b4cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097b4cu) { target=s->pc; goto dispatch; }
goto P_0c097b4c;
P_0c097b4a: /* original 0009, guest PC 0x0c097b4a */
if(!s->budget--) { s->failed_pc=0x0c097b4au; return 0; }
goto P_0c097b4c;
P_0c097b4c: /* original 6403, guest PC 0x0c097b4c */
if(!s->budget--) { s->failed_pc=0x0c097b4cu; return 0; }
r[4]=r[0];
goto P_0c097b4e;
P_0c097b4e: /* original 5242, guest PC 0x0c097b4e */
if(!s->budget--) { s->failed_pc=0x0c097b4eu; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c097b50;
P_0c097b50: /* original 9313, guest PC 0x0c097b50 */
if(!s->budget--) { s->failed_pc=0x0c097b50u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097b7au,2);
goto P_0c097b52;
P_0c097b52: /* original 2238, guest PC 0x0c097b52 */
if(!s->budget--) { s->failed_pc=0x0c097b52u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c097b54;
P_0c097b54: /* original 8b01, guest PC 0x0c097b54 */
if(!s->budget--) { s->failed_pc=0x0c097b54u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c097b5a; }
goto P_0c097b56;
P_0c097b56: /* original a097, guest PC 0x0c097b56 */
if(!s->budget--) { s->failed_pc=0x0c097b56u; return 0; }
goto P_0c097c88;
P_0c097b58: /* original 0009, guest PC 0x0c097b58 */
if(!s->budget--) { s->failed_pc=0x0c097b58u; return 0; }
goto P_0c097b5a;
P_0c097b5a: /* original 51c2, guest PC 0x0c097b5a */
if(!s->budget--) { s->failed_pc=0x0c097b5au; return 0; }
r[1]=read(ram,r[12]+8,4);
goto P_0c097b5c;
P_0c097b5c: /* original e2fb, guest PC 0x0c097b5c */
if(!s->budget--) { s->failed_pc=0x0c097b5cu; return 0; }
r[2]=0xfffffffbu;
goto P_0c097b5e;
P_0c097b5e: /* original 2129, guest PC 0x0c097b5e */
if(!s->budget--) { s->failed_pc=0x0c097b5eu; return 0; }
r[1]&=r[2];
goto P_0c097b60;
P_0c097b60: /* original 6013, guest PC 0x0c097b60 */
if(!s->budget--) { s->failed_pc=0x0c097b60u; return 0; }
r[0]=r[1];
goto P_0c097b62;
P_0c097b62: /* original 208b, guest PC 0x0c097b62 */
if(!s->budget--) { s->failed_pc=0x0c097b62u; return 0; }
r[0]|=r[8];
goto P_0c097b64;
P_0c097b64: /* original 1c02, guest PC 0x0c097b64 */
if(!s->budget--) { s->failed_pc=0x0c097b64u; return 0; }
write(ram,r[12]+8,r[0],4);
goto P_0c097b66;
P_0c097b66: /* original 61a2, guest PC 0x0c097b66 */
if(!s->budget--) { s->failed_pc=0x0c097b66u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c097b68;
P_0c097b68: /* original 2818, guest PC 0x0c097b68 */
if(!s->budget--) { s->failed_pc=0x0c097b68u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[1])==0)!=0);
goto P_0c097b6a;
P_0c097b6a: /* original 8917, guest PC 0x0c097b6a */
if(!s->budget--) { s->failed_pc=0x0c097b6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097b9c; }
goto P_0c097b6c;
P_0c097b6c: /* original d10a, guest PC 0x0c097b6c */
if(!s->budget--) { s->failed_pc=0x0c097b6cu; return 0; }
r[1]=read(ram,0x0c097b98u,4);
goto P_0c097b6e;
P_0c097b6e: /* original a016, guest PC 0x0c097b6e */
if(!s->budget--) { s->failed_pc=0x0c097b6eu; return 0; }
goto P_0c097b9e;
P_0c097b70: /* original 0009, guest PC 0x0c097b70 */
if(!s->budget--) { s->failed_pc=0x0c097b70u; return 0; }
return vf3_matrix_family(0x0c097b72u,s,ram);
P_0c097b9c: /* original d14c, guest PC 0x0c097b9c */
if(!s->budget--) { s->failed_pc=0x0c097b9cu; return 0; }
r[1]=read(ram,0x0c097cd0u,4);
goto P_0c097b9e;
P_0c097b9e: /* original 50c2, guest PC 0x0c097b9e */
if(!s->budget--) { s->failed_pc=0x0c097b9eu; return 0; }
r[0]=read(ram,r[12]+8,4);
goto P_0c097ba0;
P_0c097ba0: /* original e600, guest PC 0x0c097ba0 */
if(!s->budget--) { s->failed_pc=0x0c097ba0u; return 0; }
r[6]=0x00000000u;
goto P_0c097ba2;
P_0c097ba2: /* original 6563, guest PC 0x0c097ba2 */
if(!s->budget--) { s->failed_pc=0x0c097ba2u; return 0; }
r[5]=r[6];
goto P_0c097ba4;
P_0c097ba4: /* original 201b, guest PC 0x0c097ba4 */
if(!s->budget--) { s->failed_pc=0x0c097ba4u; return 0; }
r[0]|=r[1];
goto P_0c097ba6;
P_0c097ba6: /* original 1c02, guest PC 0x0c097ba6 */
if(!s->budget--) { s->failed_pc=0x0c097ba6u; return 0; }
write(ram,r[12]+8,r[0],4);
goto P_0c097ba8;
P_0c097ba8: /* original d34a, guest PC 0x0c097ba8 */
if(!s->budget--) { s->failed_pc=0x0c097ba8u; return 0; }
r[3]=read(ram,0x0c097cd4u,4);
goto P_0c097baa;
P_0c097baa: /* original 430b, guest PC 0x0c097baa */
if(!s->budget--) { s->failed_pc=0x0c097baau; return 0; }
target=r[3];
r[16]=code_base|0x0c097baeu;
r[4]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097baeu) { target=s->pc; goto dispatch; }
goto P_0c097bae;
P_0c097bac: /* original 6463, guest PC 0x0c097bac */
if(!s->budget--) { s->failed_pc=0x0c097bacu; return 0; }
r[4]=r[6];
goto P_0c097bae;
P_0c097bae: /* original e600, guest PC 0x0c097bae */
if(!s->budget--) { s->failed_pc=0x0c097baeu; return 0; }
r[6]=0x00000000u;
goto P_0c097bb0;
P_0c097bb0: /* original ff8d, guest PC 0x0c097bb0 */
if(!s->budget--) { s->failed_pc=0x0c097bb0u; return 0; }
fr[15]=0;
goto P_0c097bb2;
P_0c097bb2: /* original dc49, guest PC 0x0c097bb2 */
if(!s->budget--) { s->failed_pc=0x0c097bb2u; return 0; }
r[12]=read(ram,0x0c097cd8u,4);
goto P_0c097bb4;
P_0c097bb4: /* original 6563, guest PC 0x0c097bb4 */
if(!s->budget--) { s->failed_pc=0x0c097bb4u; return 0; }
r[5]=r[6];
goto P_0c097bb6;
P_0c097bb6: /* original f5fc, guest PC 0x0c097bb6 */
if(!s->budget--) { s->failed_pc=0x0c097bb6u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c097bb8;
P_0c097bb8: /* original f4fc, guest PC 0x0c097bb8 */
if(!s->budget--) { s->failed_pc=0x0c097bb8u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c097bba;
P_0c097bba: /* original 4c0b, guest PC 0x0c097bba */
if(!s->budget--) { s->failed_pc=0x0c097bbau; return 0; }
target=r[12];
r[16]=code_base|0x0c097bbeu;
r[4]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097bbeu) { target=s->pc; goto dispatch; }
goto P_0c097bbe;
P_0c097bbc: /* original 6463, guest PC 0x0c097bbc */
if(!s->budget--) { s->failed_pc=0x0c097bbcu; return 0; }
r[4]=r[6];
goto P_0c097bbe;
P_0c097bbe: /* original d247, guest PC 0x0c097bbe */
if(!s->budget--) { s->failed_pc=0x0c097bbeu; return 0; }
r[2]=read(ram,0x0c097cdcu,4);
goto P_0c097bc0;
P_0c097bc0: /* original 420b, guest PC 0x0c097bc0 */
if(!s->budget--) { s->failed_pc=0x0c097bc0u; return 0; }
target=r[2];
r[16]=code_base|0x0c097bc4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097bc4u) { target=s->pc; goto dispatch; }
goto P_0c097bc4;
P_0c097bc2: /* original 0009, guest PC 0x0c097bc2 */
if(!s->budget--) { s->failed_pc=0x0c097bc2u; return 0; }
goto P_0c097bc4;
P_0c097bc4: /* original d346, guest PC 0x0c097bc4 */
if(!s->budget--) { s->failed_pc=0x0c097bc4u; return 0; }
r[3]=read(ram,0x0c097ce0u,4);
goto P_0c097bc6;
P_0c097bc6: /* original 430b, guest PC 0x0c097bc6 */
if(!s->budget--) { s->failed_pc=0x0c097bc6u; return 0; }
target=r[3];
r[16]=code_base|0x0c097bcau;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097bcau) { target=s->pc; goto dispatch; }
goto P_0c097bca;
P_0c097bc8: /* original 0009, guest PC 0x0c097bc8 */
if(!s->budget--) { s->failed_pc=0x0c097bc8u; return 0; }
goto P_0c097bca;
P_0c097bca: /* original d246, guest PC 0x0c097bca */
if(!s->budget--) { s->failed_pc=0x0c097bcau; return 0; }
r[2]=read(ram,0x0c097ce4u,4);
goto P_0c097bcc;
P_0c097bcc: /* original 420b, guest PC 0x0c097bcc */
if(!s->budget--) { s->failed_pc=0x0c097bccu; return 0; }
target=r[2];
r[16]=code_base|0x0c097bd0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097bd0u) { target=s->pc; goto dispatch; }
goto P_0c097bd0;
P_0c097bce: /* original 0009, guest PC 0x0c097bce */
if(!s->budget--) { s->failed_pc=0x0c097bceu; return 0; }
goto P_0c097bd0;
P_0c097bd0: /* original d346, guest PC 0x0c097bd0 */
if(!s->budget--) { s->failed_pc=0x0c097bd0u; return 0; }
r[3]=read(ram,0x0c097cecu,4);
goto P_0c097bd2;
P_0c097bd2: /* original d445, guest PC 0x0c097bd2 */
if(!s->budget--) { s->failed_pc=0x0c097bd2u; return 0; }
r[4]=read(ram,0x0c097ce8u,4);
goto P_0c097bd4;
P_0c097bd4: /* original 430b, guest PC 0x0c097bd4 */
if(!s->budget--) { s->failed_pc=0x0c097bd4u; return 0; }
target=r[3];
r[16]=code_base|0x0c097bd8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097bd8u) { target=s->pc; goto dispatch; }
goto P_0c097bd8;
P_0c097bd6: /* original 0009, guest PC 0x0c097bd6 */
if(!s->budget--) { s->failed_pc=0x0c097bd6u; return 0; }
goto P_0c097bd8;
P_0c097bd8: /* original d245, guest PC 0x0c097bd8 */
if(!s->budget--) { s->failed_pc=0x0c097bd8u; return 0; }
r[2]=read(ram,0x0c097cf0u,4);
goto P_0c097bda;
P_0c097bda: /* original 420b, guest PC 0x0c097bda */
if(!s->budget--) { s->failed_pc=0x0c097bdau; return 0; }
target=r[2];
r[16]=code_base|0x0c097bdeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097bdeu) { target=s->pc; goto dispatch; }
goto P_0c097bde;
P_0c097bdc: /* original 0009, guest PC 0x0c097bdc */
if(!s->budget--) { s->failed_pc=0x0c097bdcu; return 0; }
goto P_0c097bde;
P_0c097bde: /* original d345, guest PC 0x0c097bde */
if(!s->budget--) { s->failed_pc=0x0c097bdeu; return 0; }
r[3]=read(ram,0x0c097cf4u,4);
goto P_0c097be0;
P_0c097be0: /* original 430b, guest PC 0x0c097be0 */
if(!s->budget--) { s->failed_pc=0x0c097be0u; return 0; }
target=r[3];
r[16]=code_base|0x0c097be4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097be4u) { target=s->pc; goto dispatch; }
goto P_0c097be4;
P_0c097be2: /* original 0009, guest PC 0x0c097be2 */
if(!s->budget--) { s->failed_pc=0x0c097be2u; return 0; }
goto P_0c097be4;
P_0c097be4: /* original d244, guest PC 0x0c097be4 */
if(!s->budget--) { s->failed_pc=0x0c097be4u; return 0; }
r[2]=read(ram,0x0c097cf8u,4);
goto P_0c097be6;
P_0c097be6: /* original 420b, guest PC 0x0c097be6 */
if(!s->budget--) { s->failed_pc=0x0c097be6u; return 0; }
target=r[2];
r[16]=code_base|0x0c097beau;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097beau) { target=s->pc; goto dispatch; }
goto P_0c097bea;
P_0c097be8: /* original 0009, guest PC 0x0c097be8 */
if(!s->budget--) { s->failed_pc=0x0c097be8u; return 0; }
goto P_0c097bea;
P_0c097bea: /* original d844, guest PC 0x0c097bea */
if(!s->budget--) { s->failed_pc=0x0c097beau; return 0; }
r[8]=read(ram,0x0c097cfcu,4);
goto P_0c097bec;
P_0c097bec: /* original 480b, guest PC 0x0c097bec */
if(!s->budget--) { s->failed_pc=0x0c097becu; return 0; }
target=r[8];
r[16]=code_base|0x0c097bf0u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097bf0u) { target=s->pc; goto dispatch; }
goto P_0c097bf0;
P_0c097bee: /* original e414, guest PC 0x0c097bee */
if(!s->budget--) { s->failed_pc=0x0c097beeu; return 0; }
r[4]=0x00000014u;
goto P_0c097bf0;
P_0c097bf0: /* original 480b, guest PC 0x0c097bf0 */
if(!s->budget--) { s->failed_pc=0x0c097bf0u; return 0; }
target=r[8];
r[16]=code_base|0x0c097bf4u;
r[4]=0x00000016u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097bf4u) { target=s->pc; goto dispatch; }
goto P_0c097bf4;
P_0c097bf2: /* original e416, guest PC 0x0c097bf2 */
if(!s->budget--) { s->failed_pc=0x0c097bf2u; return 0; }
r[4]=0x00000016u;
goto P_0c097bf4;
P_0c097bf4: /* original 480b, guest PC 0x0c097bf4 */
if(!s->budget--) { s->failed_pc=0x0c097bf4u; return 0; }
target=r[8];
r[16]=code_base|0x0c097bf8u;
r[4]=0x0000000fu;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097bf8u) { target=s->pc; goto dispatch; }
goto P_0c097bf8;
P_0c097bf6: /* original e40f, guest PC 0x0c097bf6 */
if(!s->budget--) { s->failed_pc=0x0c097bf6u; return 0; }
r[4]=0x0000000fu;
goto P_0c097bf8;
P_0c097bf8: /* original c741, guest PC 0x0c097bf8 */
if(!s->budget--) { s->failed_pc=0x0c097bf8u; return 0; }
r[0]=0x0c097d00u;
goto P_0c097bfa;
P_0c097bfa: /* original f5fc, guest PC 0x0c097bfa */
if(!s->budget--) { s->failed_pc=0x0c097bfau; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c097bfc;
P_0c097bfc: /* original e600, guest PC 0x0c097bfc */
if(!s->budget--) { s->failed_pc=0x0c097bfcu; return 0; }
r[6]=0x00000000u;
goto P_0c097bfe;
P_0c097bfe: /* original f408, guest PC 0x0c097bfe */
if(!s->budget--) { s->failed_pc=0x0c097bfeu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c097c00;
P_0c097c00: /* original 6563, guest PC 0x0c097c00 */
if(!s->budget--) { s->failed_pc=0x0c097c00u; return 0; }
r[5]=r[6];
goto P_0c097c02;
P_0c097c02: /* original 4c0b, guest PC 0x0c097c02 */
if(!s->budget--) { s->failed_pc=0x0c097c02u; return 0; }
target=r[12];
r[16]=code_base|0x0c097c06u;
r[4]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097c06u) { target=s->pc; goto dispatch; }
goto P_0c097c06;
P_0c097c04: /* original 6463, guest PC 0x0c097c04 */
if(!s->budget--) { s->failed_pc=0x0c097c04u; return 0; }
r[4]=r[6];
goto P_0c097c06;
P_0c097c06: /* original c73f, guest PC 0x0c097c06 */
if(!s->budget--) { s->failed_pc=0x0c097c06u; return 0; }
r[0]=0x0c097d04u;
goto P_0c097c08;
P_0c097c08: /* original f5fc, guest PC 0x0c097c08 */
if(!s->budget--) { s->failed_pc=0x0c097c08u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c097c0a;
P_0c097c0a: /* original e600, guest PC 0x0c097c0a */
if(!s->budget--) { s->failed_pc=0x0c097c0au; return 0; }
r[6]=0x00000000u;
goto P_0c097c0c;
P_0c097c0c: /* original f408, guest PC 0x0c097c0c */
if(!s->budget--) { s->failed_pc=0x0c097c0cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c097c0e;
P_0c097c0e: /* original 6563, guest PC 0x0c097c0e */
if(!s->budget--) { s->failed_pc=0x0c097c0eu; return 0; }
r[5]=r[6];
goto P_0c097c10;
P_0c097c10: /* original 4c0b, guest PC 0x0c097c10 */
if(!s->budget--) { s->failed_pc=0x0c097c10u; return 0; }
target=r[12];
r[16]=code_base|0x0c097c14u;
r[4]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097c14u) { target=s->pc; goto dispatch; }
goto P_0c097c14;
P_0c097c12: /* original 6463, guest PC 0x0c097c12 */
if(!s->budget--) { s->failed_pc=0x0c097c12u; return 0; }
r[4]=r[6];
goto P_0c097c14;
P_0c097c14: /* original d33c, guest PC 0x0c097c14 */
if(!s->budget--) { s->failed_pc=0x0c097c14u; return 0; }
r[3]=read(ram,0x0c097d08u,4);
goto P_0c097c16;
P_0c097c16: /* original 430b, guest PC 0x0c097c16 */
if(!s->budget--) { s->failed_pc=0x0c097c16u; return 0; }
target=r[3];
r[16]=code_base|0x0c097c1au;
r[4]=read(ram,r[13]+24,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097c1au) { target=s->pc; goto dispatch; }
goto P_0c097c1a;
P_0c097c18: /* original 54d6, guest PC 0x0c097c18 */
if(!s->budget--) { s->failed_pc=0x0c097c18u; return 0; }
r[4]=read(ram,r[13]+24,4);
goto P_0c097c1a;
P_0c097c1a: /* original d23b, guest PC 0x0c097c1a */
if(!s->budget--) { s->failed_pc=0x0c097c1au; return 0; }
r[2]=read(ram,0x0c097d08u,4);
goto P_0c097c1c;
P_0c097c1c: /* original 420b, guest PC 0x0c097c1c */
if(!s->budget--) { s->failed_pc=0x0c097c1cu; return 0; }
target=r[2];
r[16]=code_base|0x0c097c20u;
r[4]=read(ram,r[13]+28,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097c20u) { target=s->pc; goto dispatch; }
goto P_0c097c20;
P_0c097c1e: /* original 54d7, guest PC 0x0c097c1e */
if(!s->budget--) { s->failed_pc=0x0c097c1eu; return 0; }
r[4]=read(ram,r[13]+28,4);
goto P_0c097c20;
P_0c097c20: /* original d339, guest PC 0x0c097c20 */
if(!s->budget--) { s->failed_pc=0x0c097c20u; return 0; }
r[3]=read(ram,0x0c097d08u,4);
goto P_0c097c22;
P_0c097c22: /* original 430b, guest PC 0x0c097c22 */
if(!s->budget--) { s->failed_pc=0x0c097c22u; return 0; }
target=r[3];
r[16]=code_base|0x0c097c26u;
r[4]=read(ram,r[13]+60,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097c26u) { target=s->pc; goto dispatch; }
goto P_0c097c26;
P_0c097c24: /* original 54df, guest PC 0x0c097c24 */
if(!s->budget--) { s->failed_pc=0x0c097c24u; return 0; }
r[4]=read(ram,r[13]+60,4);
goto P_0c097c26;
P_0c097c26: /* original d338, guest PC 0x0c097c26 */
if(!s->budget--) { s->failed_pc=0x0c097c26u; return 0; }
r[3]=read(ram,0x0c097d08u,4);
goto P_0c097c28;
P_0c097c28: /* original e040, guest PC 0x0c097c28 */
if(!s->budget--) { s->failed_pc=0x0c097c28u; return 0; }
r[0]=0x00000040u;
goto P_0c097c2a;
P_0c097c2a: /* original 430b, guest PC 0x0c097c2a */
if(!s->budget--) { s->failed_pc=0x0c097c2au; return 0; }
target=r[3];
r[16]=code_base|0x0c097c2eu;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097c2eu) { target=s->pc; goto dispatch; }
goto P_0c097c2e;
P_0c097c2c: /* original 04de, guest PC 0x0c097c2c */
if(!s->budget--) { s->failed_pc=0x0c097c2cu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c097c2e;
P_0c097c2e: /* original d236, guest PC 0x0c097c2e */
if(!s->budget--) { s->failed_pc=0x0c097c2eu; return 0; }
r[2]=read(ram,0x0c097d08u,4);
goto P_0c097c30;
P_0c097c30: /* original 420b, guest PC 0x0c097c30 */
if(!s->budget--) { s->failed_pc=0x0c097c30u; return 0; }
target=r[2];
r[16]=code_base|0x0c097c34u;
r[4]=read(ram,r[13]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097c34u) { target=s->pc; goto dispatch; }
goto P_0c097c34;
P_0c097c32: /* original 54d4, guest PC 0x0c097c32 */
if(!s->budget--) { s->failed_pc=0x0c097c32u; return 0; }
r[4]=read(ram,r[13]+16,4);
goto P_0c097c34;
P_0c097c34: /* original d334, guest PC 0x0c097c34 */
if(!s->budget--) { s->failed_pc=0x0c097c34u; return 0; }
r[3]=read(ram,0x0c097d08u,4);
goto P_0c097c36;
P_0c097c36: /* original 430b, guest PC 0x0c097c36 */
if(!s->budget--) { s->failed_pc=0x0c097c36u; return 0; }
target=r[3];
r[16]=code_base|0x0c097c3au;
r[4]=read(ram,r[13]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097c3au) { target=s->pc; goto dispatch; }
goto P_0c097c3a;
P_0c097c38: /* original 54d5, guest PC 0x0c097c38 */
if(!s->budget--) { s->failed_pc=0x0c097c38u; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c097c3a;
P_0c097c3a: /* original d333, guest PC 0x0c097c3a */
if(!s->budget--) { s->failed_pc=0x0c097c3au; return 0; }
r[3]=read(ram,0x0c097d08u,4);
goto P_0c097c3c;
P_0c097c3c: /* original e048, guest PC 0x0c097c3c */
if(!s->budget--) { s->failed_pc=0x0c097c3cu; return 0; }
r[0]=0x00000048u;
goto P_0c097c3e;
P_0c097c3e: /* original 430b, guest PC 0x0c097c3e */
if(!s->budget--) { s->failed_pc=0x0c097c3eu; return 0; }
target=r[3];
r[16]=code_base|0x0c097c42u;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097c42u) { target=s->pc; goto dispatch; }
goto P_0c097c42;
P_0c097c40: /* original 04de, guest PC 0x0c097c40 */
if(!s->budget--) { s->failed_pc=0x0c097c40u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c097c42;
P_0c097c42: /* original d331, guest PC 0x0c097c42 */
if(!s->budget--) { s->failed_pc=0x0c097c42u; return 0; }
r[3]=read(ram,0x0c097d08u,4);
goto P_0c097c44;
P_0c097c44: /* original e05c, guest PC 0x0c097c44 */
if(!s->budget--) { s->failed_pc=0x0c097c44u; return 0; }
r[0]=0x0000005cu;
goto P_0c097c46;
P_0c097c46: /* original 430b, guest PC 0x0c097c46 */
if(!s->budget--) { s->failed_pc=0x0c097c46u; return 0; }
target=r[3];
r[16]=code_base|0x0c097c4au;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097c4au) { target=s->pc; goto dispatch; }
goto P_0c097c4a;
P_0c097c48: /* original 04de, guest PC 0x0c097c48 */
if(!s->budget--) { s->failed_pc=0x0c097c48u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c097c4a;
P_0c097c4a: /* original d32f, guest PC 0x0c097c4a */
if(!s->budget--) { s->failed_pc=0x0c097c4au; return 0; }
r[3]=read(ram,0x0c097d08u,4);
goto P_0c097c4c;
P_0c097c4c: /* original e060, guest PC 0x0c097c4c */
if(!s->budget--) { s->failed_pc=0x0c097c4cu; return 0; }
r[0]=0x00000060u;
goto P_0c097c4e;
P_0c097c4e: /* original 430b, guest PC 0x0c097c4e */
if(!s->budget--) { s->failed_pc=0x0c097c4eu; return 0; }
target=r[3];
r[16]=code_base|0x0c097c52u;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097c52u) { target=s->pc; goto dispatch; }
goto P_0c097c52;
P_0c097c50: /* original 04de, guest PC 0x0c097c50 */
if(!s->budget--) { s->failed_pc=0x0c097c50u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c097c52;
P_0c097c52: /* original d32d, guest PC 0x0c097c52 */
if(!s->budget--) { s->failed_pc=0x0c097c52u; return 0; }
r[3]=read(ram,0x0c097d08u,4);
goto P_0c097c54;
P_0c097c54: /* original e064, guest PC 0x0c097c54 */
if(!s->budget--) { s->failed_pc=0x0c097c54u; return 0; }
r[0]=0x00000064u;
goto P_0c097c56;
P_0c097c56: /* original 430b, guest PC 0x0c097c56 */
if(!s->budget--) { s->failed_pc=0x0c097c56u; return 0; }
target=r[3];
r[16]=code_base|0x0c097c5au;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097c5au) { target=s->pc; goto dispatch; }
goto P_0c097c5a;
P_0c097c58: /* original 04de, guest PC 0x0c097c58 */
if(!s->budget--) { s->failed_pc=0x0c097c58u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c097c5a;
P_0c097c5a: /* original d32b, guest PC 0x0c097c5a */
if(!s->budget--) { s->failed_pc=0x0c097c5au; return 0; }
r[3]=read(ram,0x0c097d08u,4);
goto P_0c097c5c;
P_0c097c5c: /* original e060, guest PC 0x0c097c5c */
if(!s->budget--) { s->failed_pc=0x0c097c5cu; return 0; }
r[0]=0x00000060u;
goto P_0c097c5e;
P_0c097c5e: /* original 430b, guest PC 0x0c097c5e */
if(!s->budget--) { s->failed_pc=0x0c097c5eu; return 0; }
target=r[3];
r[16]=code_base|0x0c097c62u;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097c62u) { target=s->pc; goto dispatch; }
goto P_0c097c62;
P_0c097c60: /* original 04de, guest PC 0x0c097c60 */
if(!s->budget--) { s->failed_pc=0x0c097c60u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c097c62;
P_0c097c62: /* original d329, guest PC 0x0c097c62 */
if(!s->budget--) { s->failed_pc=0x0c097c62u; return 0; }
r[3]=read(ram,0x0c097d08u,4);
goto P_0c097c64;
P_0c097c64: /* original e064, guest PC 0x0c097c64 */
if(!s->budget--) { s->failed_pc=0x0c097c64u; return 0; }
r[0]=0x00000064u;
goto P_0c097c66;
P_0c097c66: /* original 430b, guest PC 0x0c097c66 */
if(!s->budget--) { s->failed_pc=0x0c097c66u; return 0; }
target=r[3];
r[16]=code_base|0x0c097c6au;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097c6au) { target=s->pc; goto dispatch; }
goto P_0c097c6a;
P_0c097c68: /* original 04de, guest PC 0x0c097c68 */
if(!s->budget--) { s->failed_pc=0x0c097c68u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c097c6a;
P_0c097c6a: /* original d327, guest PC 0x0c097c6a */
if(!s->budget--) { s->failed_pc=0x0c097c6au; return 0; }
r[3]=read(ram,0x0c097d08u,4);
goto P_0c097c6c;
P_0c097c6c: /* original e054, guest PC 0x0c097c6c */
if(!s->budget--) { s->failed_pc=0x0c097c6cu; return 0; }
r[0]=0x00000054u;
goto P_0c097c6e;
P_0c097c6e: /* original 430b, guest PC 0x0c097c6e */
if(!s->budget--) { s->failed_pc=0x0c097c6eu; return 0; }
target=r[3];
r[16]=code_base|0x0c097c72u;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097c72u) { target=s->pc; goto dispatch; }
goto P_0c097c72;
P_0c097c70: /* original 04de, guest PC 0x0c097c70 */
if(!s->budget--) { s->failed_pc=0x0c097c70u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c097c72;
P_0c097c72: /* original e017, guest PC 0x0c097c72 */
if(!s->budget--) { s->failed_pc=0x0c097c72u; return 0; }
r[0]=0x00000017u;
goto P_0c097c74;
P_0c097c74: /* original d325, guest PC 0x0c097c74 */
if(!s->budget--) { s->failed_pc=0x0c097c74u; return 0; }
r[3]=read(ram,0x0c097d0cu,4);
goto P_0c097c76;
P_0c097c76: /* original 62a2, guest PC 0x0c097c76 */
if(!s->budget--) { s->failed_pc=0x0c097c76u; return 0; }
tmp=read(ram,r[10],4);
r[2]=tmp;
goto P_0c097c78;
P_0c097c78: /* original 2239, guest PC 0x0c097c78 */
if(!s->budget--) { s->failed_pc=0x0c097c78u; return 0; }
r[2]&=r[3];
goto P_0c097c7a;
P_0c097c7a: /* original 2a22, guest PC 0x0c097c7a */
if(!s->budget--) { s->failed_pc=0x0c097c7au; return 0; }
write(ram,r[10],r[2],4);
goto P_0c097c7c;
P_0c097c7c: /* original 80ea, guest PC 0x0c097c7c */
if(!s->budget--) { s->failed_pc=0x0c097c7cu; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c097c7e;
P_0c097c7e: /* original 6093, guest PC 0x0c097c7e */
if(!s->budget--) { s->failed_pc=0x0c097c7eu; return 0; }
r[0]=r[9];
goto P_0c097c80;
P_0c097c80: /* original 80eb, guest PC 0x0c097c80 */
if(!s->budget--) { s->failed_pc=0x0c097c80u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c097c82;
P_0c097c82: /* original 901f, guest PC 0x0c097c82 */
if(!s->budget--) { s->failed_pc=0x0c097c82u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097cc4u,2);
goto P_0c097c84;
P_0c097c84: /* original a177, guest PC 0x0c097c84 */
if(!s->budget--) { s->failed_pc=0x0c097c84u; return 0; }
goto P_0c097f76;
P_0c097c86: /* original 0009, guest PC 0x0c097c86 */
if(!s->budget--) { s->failed_pc=0x0c097c86u; return 0; }
goto P_0c097c88;
P_0c097c88: /* original 63a2, guest PC 0x0c097c88 */
if(!s->budget--) { s->failed_pc=0x0c097c88u; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c097c8a;
P_0c097c8a: /* original 2388, guest PC 0x0c097c8a */
if(!s->budget--) { s->failed_pc=0x0c097c8au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c097c8c;
P_0c097c8c: /* original 8902, guest PC 0x0c097c8c */
if(!s->budget--) { s->failed_pc=0x0c097c8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097c94; }
goto P_0c097c8e;
P_0c097c8e: /* original 9d1a, guest PC 0x0c097c8e */
if(!s->budget--) { s->failed_pc=0x0c097c8eu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097cc6u,2);
goto P_0c097c90;
P_0c097c90: /* original a002, guest PC 0x0c097c90 */
if(!s->budget--) { s->failed_pc=0x0c097c90u; return 0; }
r[5]=r[9];
goto P_0c097c98;
P_0c097c92: /* original 6593, guest PC 0x0c097c92 */
if(!s->budget--) { s->failed_pc=0x0c097c92u; return 0; }
r[5]=r[9];
goto P_0c097c94;
P_0c097c94: /* original 9d18, guest PC 0x0c097c94 */
if(!s->budget--) { s->failed_pc=0x0c097c94u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097cc8u,2);
goto P_0c097c96;
P_0c097c96: /* original e52c, guest PC 0x0c097c96 */
if(!s->budget--) { s->failed_pc=0x0c097c96u; return 0; }
r[5]=0x0000002cu;
goto P_0c097c98;
P_0c097c98: /* original 9017, guest PC 0x0c097c98 */
if(!s->budget--) { s->failed_pc=0x0c097c98u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097ccau,2);
goto P_0c097c9a;
P_0c097c9a: /* original 02ec, guest PC 0x0c097c9a */
if(!s->budget--) { s->failed_pc=0x0c097c9au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097c9c;
P_0c097c9c: /* original 2228, guest PC 0x0c097c9c */
if(!s->budget--) { s->failed_pc=0x0c097c9cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c097c9e;
P_0c097c9e: /* original 893b, guest PC 0x0c097c9e */
if(!s->budget--) { s->failed_pc=0x0c097c9eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097d18; }
goto P_0c097ca0;
P_0c097ca0: /* original 9314, guest PC 0x0c097ca0 */
if(!s->budget--) { s->failed_pc=0x0c097ca0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097cccu,2);
goto P_0c097ca2;
P_0c097ca2: /* original 4500, guest PC 0x0c097ca2 */
if(!s->budget--) { s->failed_pc=0x0c097ca2u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c097ca4;
P_0c097ca4: /* original e220, guest PC 0x0c097ca4 */
if(!s->budget--) { s->failed_pc=0x0c097ca4u; return 0; }
r[2]=0x00000020u;
goto P_0c097ca6;
P_0c097ca6: /* original d41a, guest PC 0x0c097ca6 */
if(!s->budget--) { s->failed_pc=0x0c097ca6u; return 0; }
r[4]=read(ram,0x0c097d10u,4);
goto P_0c097ca8;
P_0c097ca8: /* original 253b, guest PC 0x0c097ca8 */
if(!s->budget--) { s->failed_pc=0x0c097ca8u; return 0; }
r[5]|=r[3];
goto P_0c097caa;
P_0c097caa: /* original 6723, guest PC 0x0c097caa */
if(!s->budget--) { s->failed_pc=0x0c097caau; return 0; }
r[7]=r[2];
goto P_0c097cac;
P_0c097cac: /* original 1f51, guest PC 0x0c097cac */
if(!s->budget--) { s->failed_pc=0x0c097cacu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c097cae;
P_0c097cae: /* original e610, guest PC 0x0c097cae */
if(!s->budget--) { s->failed_pc=0x0c097caeu; return 0; }
r[6]=0x00000010u;
goto P_0c097cb0;
P_0c097cb0: /* original 2f26, guest PC 0x0c097cb0 */
if(!s->budget--) { s->failed_pc=0x0c097cb0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c097cb2;
P_0c097cb2: /* original d118, guest PC 0x0c097cb2 */
if(!s->budget--) { s->failed_pc=0x0c097cb2u; return 0; }
r[1]=read(ram,0x0c097d14u,4);
goto P_0c097cb4;
P_0c097cb4: /* original 410b, guest PC 0x0c097cb4 */
if(!s->budget--) { s->failed_pc=0x0c097cb4u; return 0; }
target=r[1];
r[16]=code_base|0x0c097cb8u;
r[5]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097cb8u) { target=s->pc; goto dispatch; }
goto P_0c097cb8;
P_0c097cb6: /* original 55f2, guest PC 0x0c097cb6 */
if(!s->budget--) { s->failed_pc=0x0c097cb6u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c097cb8;
P_0c097cb8: /* original 53c2, guest PC 0x0c097cb8 */
if(!s->budget--) { s->failed_pc=0x0c097cb8u; return 0; }
r[3]=read(ram,r[12]+8,4);
goto P_0c097cba;
P_0c097cba: /* original 6dd7, guest PC 0x0c097cba */
if(!s->budget--) { s->failed_pc=0x0c097cbau; return 0; }
r[13]=~r[13];
goto P_0c097cbc;
P_0c097cbc: /* original 7f04, guest PC 0x0c097cbc */
if(!s->budget--) { s->failed_pc=0x0c097cbcu; return 0; }
r[15]+=0x00000004u;
goto P_0c097cbe;
P_0c097cbe: /* original 23d9, guest PC 0x0c097cbe */
if(!s->budget--) { s->failed_pc=0x0c097cbeu; return 0; }
r[3]&=r[13];
goto P_0c097cc0;
P_0c097cc0: /* original a02d, guest PC 0x0c097cc0 */
if(!s->budget--) { s->failed_pc=0x0c097cc0u; return 0; }
write(ram,r[12]+8,r[3],4);
goto P_0c097d1e;
P_0c097cc2: /* original 1c32, guest PC 0x0c097cc2 */
if(!s->budget--) { s->failed_pc=0x0c097cc2u; return 0; }
write(ram,r[12]+8,r[3],4);
return vf3_matrix_family(0x0c097cc4u,s,ram);
P_0c097d18: /* original 51c2, guest PC 0x0c097d18 */
if(!s->budget--) { s->failed_pc=0x0c097d18u; return 0; }
r[1]=read(ram,r[12]+8,4);
goto P_0c097d1a;
P_0c097d1a: /* original 21db, guest PC 0x0c097d1a */
if(!s->budget--) { s->failed_pc=0x0c097d1au; return 0; }
r[1]|=r[13];
goto P_0c097d1c;
P_0c097d1c: /* original 1c12, guest PC 0x0c097d1c */
if(!s->budget--) { s->failed_pc=0x0c097d1cu; return 0; }
write(ram,r[12]+8,r[1],4);
goto P_0c097d1e;
P_0c097d1e: /* original 9067, guest PC 0x0c097d1e */
if(!s->budget--) { s->failed_pc=0x0c097d1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df0u,2);
goto P_0c097d20;
P_0c097d20: /* original 03ec, guest PC 0x0c097d20 */
if(!s->budget--) { s->failed_pc=0x0c097d20u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097d22;
P_0c097d22: /* original 2338, guest PC 0x0c097d22 */
if(!s->budget--) { s->failed_pc=0x0c097d22u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c097d24;
P_0c097d24: /* original 8d14, guest PC 0x0c097d24 */
if(!s->budget--) { s->failed_pc=0x0c097d24u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[10],4);
r[4]=tmp;
if(cond) { goto P_0c097d50; }
goto P_0c097d28;
P_0c097d26: /* original 64a2, guest PC 0x0c097d26 */
if(!s->budget--) { s->failed_pc=0x0c097d26u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c097d28;
P_0c097d28: /* original 6343, guest PC 0x0c097d28 */
if(!s->budget--) { s->failed_pc=0x0c097d28u; return 0; }
r[3]=r[4];
goto P_0c097d2a;
P_0c097d2a: /* original 2388, guest PC 0x0c097d2a */
if(!s->budget--) { s->failed_pc=0x0c097d2au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c097d2c;
P_0c097d2c: /* original 8906, guest PC 0x0c097d2c */
if(!s->budget--) { s->failed_pc=0x0c097d2cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097d3c; }
goto P_0c097d2e;
P_0c097d2e: /* original 9060, guest PC 0x0c097d2e */
if(!s->budget--) { s->failed_pc=0x0c097d2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df2u,2);
goto P_0c097d30;
P_0c097d30: /* original d332, guest PC 0x0c097d30 */
if(!s->budget--) { s->failed_pc=0x0c097d30u; return 0; }
r[3]=read(ram,0x0c097dfcu,4);
goto P_0c097d32;
P_0c097d32: /* original 02ee, guest PC 0x0c097d32 */
if(!s->budget--) { s->failed_pc=0x0c097d32u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c097d34;
P_0c097d34: /* original 2238, guest PC 0x0c097d34 */
if(!s->budget--) { s->failed_pc=0x0c097d34u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c097d36;
P_0c097d36: /* original 8901, guest PC 0x0c097d36 */
if(!s->budget--) { s->failed_pc=0x0c097d36u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097d3c; }
goto P_0c097d38;
P_0c097d38: /* original a151, guest PC 0x0c097d38 */
if(!s->budget--) { s->failed_pc=0x0c097d38u; return 0; }
goto P_0c097fde;
P_0c097d3a: /* original 0009, guest PC 0x0c097d3a */
if(!s->budget--) { s->failed_pc=0x0c097d3au; return 0; }
goto P_0c097d3c;
P_0c097d3c: /* original d330, guest PC 0x0c097d3c */
if(!s->budget--) { s->failed_pc=0x0c097d3cu; return 0; }
r[3]=read(ram,0x0c097e00u,4);
goto P_0c097d3e;
P_0c097d3e: /* original 2348, guest PC 0x0c097d3e */
if(!s->budget--) { s->failed_pc=0x0c097d3eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c097d40;
P_0c097d40: /* original 891c, guest PC 0x0c097d40 */
if(!s->budget--) { s->failed_pc=0x0c097d40u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097d7c; }
goto P_0c097d42;
P_0c097d42: /* original 9056, guest PC 0x0c097d42 */
if(!s->budget--) { s->failed_pc=0x0c097d42u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df2u,2);
goto P_0c097d44;
P_0c097d44: /* original 9356, guest PC 0x0c097d44 */
if(!s->budget--) { s->failed_pc=0x0c097d44u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df4u,2);
goto P_0c097d46;
P_0c097d46: /* original 02ee, guest PC 0x0c097d46 */
if(!s->budget--) { s->failed_pc=0x0c097d46u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c097d48;
P_0c097d48: /* original 2238, guest PC 0x0c097d48 */
if(!s->budget--) { s->failed_pc=0x0c097d48u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c097d4a;
P_0c097d4a: /* original 8917, guest PC 0x0c097d4a */
if(!s->budget--) { s->failed_pc=0x0c097d4au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097d7c; }
goto P_0c097d4c;
P_0c097d4c: /* original a147, guest PC 0x0c097d4c */
if(!s->budget--) { s->failed_pc=0x0c097d4cu; return 0; }
goto P_0c097fde;
P_0c097d4e: /* original 0009, guest PC 0x0c097d4e */
if(!s->budget--) { s->failed_pc=0x0c097d4eu; return 0; }
goto P_0c097d50;
P_0c097d50: /* original 61f2, guest PC 0x0c097d50 */
if(!s->budget--) { s->failed_pc=0x0c097d50u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c097d52;
P_0c097d52: /* original 6312, guest PC 0x0c097d52 */
if(!s->budget--) { s->failed_pc=0x0c097d52u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c097d54;
P_0c097d54: /* original 2398, guest PC 0x0c097d54 */
if(!s->budget--) { s->failed_pc=0x0c097d54u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c097d56;
P_0c097d56: /* original 8906, guest PC 0x0c097d56 */
if(!s->budget--) { s->failed_pc=0x0c097d56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097d66; }
goto P_0c097d58;
P_0c097d58: /* original 904b, guest PC 0x0c097d58 */
if(!s->budget--) { s->failed_pc=0x0c097d58u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df2u,2);
goto P_0c097d5a;
P_0c097d5a: /* original d328, guest PC 0x0c097d5a */
if(!s->budget--) { s->failed_pc=0x0c097d5au; return 0; }
r[3]=read(ram,0x0c097dfcu,4);
goto P_0c097d5c;
P_0c097d5c: /* original 02ee, guest PC 0x0c097d5c */
if(!s->budget--) { s->failed_pc=0x0c097d5cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c097d5e;
P_0c097d5e: /* original 2238, guest PC 0x0c097d5e */
if(!s->budget--) { s->failed_pc=0x0c097d5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c097d60;
P_0c097d60: /* original 8901, guest PC 0x0c097d60 */
if(!s->budget--) { s->failed_pc=0x0c097d60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097d66; }
goto P_0c097d62;
P_0c097d62: /* original a13c, guest PC 0x0c097d62 */
if(!s->budget--) { s->failed_pc=0x0c097d62u; return 0; }
goto P_0c097fde;
P_0c097d64: /* original 0009, guest PC 0x0c097d64 */
if(!s->budget--) { s->failed_pc=0x0c097d64u; return 0; }
goto P_0c097d66;
P_0c097d66: /* original 53f2, guest PC 0x0c097d66 */
if(!s->budget--) { s->failed_pc=0x0c097d66u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c097d68;
P_0c097d68: /* original 6232, guest PC 0x0c097d68 */
if(!s->budget--) { s->failed_pc=0x0c097d68u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c097d6a;
P_0c097d6a: /* original 2298, guest PC 0x0c097d6a */
if(!s->budget--) { s->failed_pc=0x0c097d6au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[9])==0)!=0);
goto P_0c097d6c;
P_0c097d6c: /* original 8906, guest PC 0x0c097d6c */
if(!s->budget--) { s->failed_pc=0x0c097d6cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097d7c; }
goto P_0c097d6e;
P_0c097d6e: /* original 9040, guest PC 0x0c097d6e */
if(!s->budget--) { s->failed_pc=0x0c097d6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df2u,2);
goto P_0c097d70;
P_0c097d70: /* original 9340, guest PC 0x0c097d70 */
if(!s->budget--) { s->failed_pc=0x0c097d70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df4u,2);
goto P_0c097d72;
P_0c097d72: /* original 01ee, guest PC 0x0c097d72 */
if(!s->budget--) { s->failed_pc=0x0c097d72u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c097d74;
P_0c097d74: /* original 2138, guest PC 0x0c097d74 */
if(!s->budget--) { s->failed_pc=0x0c097d74u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c097d76;
P_0c097d76: /* original 8901, guest PC 0x0c097d76 */
if(!s->budget--) { s->failed_pc=0x0c097d76u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097d7c; }
goto P_0c097d78;
P_0c097d78: /* original a131, guest PC 0x0c097d78 */
if(!s->budget--) { s->failed_pc=0x0c097d78u; return 0; }
goto P_0c097fde;
P_0c097d7a: /* original 0009, guest PC 0x0c097d7a */
if(!s->budget--) { s->failed_pc=0x0c097d7au; return 0; }
goto P_0c097d7c;
P_0c097d7c: /* original 2488, guest PC 0x0c097d7c */
if(!s->budget--) { s->failed_pc=0x0c097d7cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[8])==0)!=0);
goto P_0c097d7e;
P_0c097d7e: /* original 8901, guest PC 0x0c097d7e */
if(!s->budget--) { s->failed_pc=0x0c097d7eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097d84; }
goto P_0c097d80;
P_0c097d80: /* original a001, guest PC 0x0c097d80 */
if(!s->budget--) { s->failed_pc=0x0c097d80u; return 0; }
r[4]=0x00000000u;
goto P_0c097d86;
P_0c097d82: /* original e400, guest PC 0x0c097d82 */
if(!s->budget--) { s->failed_pc=0x0c097d82u; return 0; }
r[4]=0x00000000u;
goto P_0c097d84;
P_0c097d84: /* original e401, guest PC 0x0c097d84 */
if(!s->budget--) { s->failed_pc=0x0c097d84u; return 0; }
r[4]=0x00000001u;
goto P_0c097d86;
P_0c097d86: /* original d21f, guest PC 0x0c097d86 */
if(!s->budget--) { s->failed_pc=0x0c097d86u; return 0; }
r[2]=read(ram,0x0c097e04u,4);
goto P_0c097d88;
P_0c097d88: /* original 420b, guest PC 0x0c097d88 */
if(!s->budget--) { s->failed_pc=0x0c097d88u; return 0; }
target=r[2];
r[16]=code_base|0x0c097d8cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097d8cu) { target=s->pc; goto dispatch; }
goto P_0c097d8c;
P_0c097d8a: /* original 0009, guest PC 0x0c097d8a */
if(!s->budget--) { s->failed_pc=0x0c097d8au; return 0; }
goto P_0c097d8c;
P_0c097d8c: /* original 6403, guest PC 0x0c097d8c */
if(!s->budget--) { s->failed_pc=0x0c097d8cu; return 0; }
r[4]=r[0];
goto P_0c097d8e;
P_0c097d8e: /* original 902f, guest PC 0x0c097d8e */
if(!s->budget--) { s->failed_pc=0x0c097d8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df0u,2);
goto P_0c097d90;
P_0c097d90: /* original 03ec, guest PC 0x0c097d90 */
if(!s->budget--) { s->failed_pc=0x0c097d90u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097d92;
P_0c097d92: /* original 2338, guest PC 0x0c097d92 */
if(!s->budget--) { s->failed_pc=0x0c097d92u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c097d94;
P_0c097d94: /* original 8d02, guest PC 0x0c097d94 */
if(!s->budget--) { s->failed_pc=0x0c097d94u; return 0; }
cond=r[17]&1u;
r[13]=read(ram,r[4]+8,4);
if(cond) { goto P_0c097d9c; }
goto P_0c097d98;
P_0c097d96: /* original 5d42, guest PC 0x0c097d96 */
if(!s->budget--) { s->failed_pc=0x0c097d96u; return 0; }
r[13]=read(ram,r[4]+8,4);
goto P_0c097d98;
P_0c097d98: /* original a0d7, guest PC 0x0c097d98 */
if(!s->budget--) { s->failed_pc=0x0c097d98u; return 0; }
goto P_0c097f4a;
P_0c097d9a: /* original 0009, guest PC 0x0c097d9a */
if(!s->budget--) { s->failed_pc=0x0c097d9au; return 0; }
goto P_0c097d9c;
P_0c097d9c: /* original e310, guest PC 0x0c097d9c */
if(!s->budget--) { s->failed_pc=0x0c097d9cu; return 0; }
r[3]=0x00000010u;
goto P_0c097d9e;
P_0c097d9e: /* original d81a, guest PC 0x0c097d9e */
if(!s->budget--) { s->failed_pc=0x0c097d9eu; return 0; }
r[8]=read(ram,0x0c097e08u,4);
goto P_0c097da0;
P_0c097da0: /* original 23d8, guest PC 0x0c097da0 */
if(!s->budget--) { s->failed_pc=0x0c097da0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c097da2;
P_0c097da2: /* original 8915, guest PC 0x0c097da2 */
if(!s->budget--) { s->failed_pc=0x0c097da2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097dd0; }
goto P_0c097da4;
P_0c097da4: /* original 9427, guest PC 0x0c097da4 */
if(!s->budget--) { s->failed_pc=0x0c097da4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df6u,2);
goto P_0c097da6;
P_0c097da6: /* original 480b, guest PC 0x0c097da6 */
if(!s->budget--) { s->failed_pc=0x0c097da6u; return 0; }
target=r[8];
r[16]=code_base|0x0c097daau;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097daau) { target=s->pc; goto dispatch; }
goto P_0c097daa;
P_0c097da8: /* original 0009, guest PC 0x0c097da8 */
if(!s->budget--) { s->failed_pc=0x0c097da8u; return 0; }
goto P_0c097daa;
P_0c097daa: /* original 9025, guest PC 0x0c097daa */
if(!s->budget--) { s->failed_pc=0x0c097daau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df8u,2);
goto P_0c097dac;
P_0c097dac: /* original 00ec, guest PC 0x0c097dac */
if(!s->budget--) { s->failed_pc=0x0c097dacu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097dae;
P_0c097dae: /* original 8801, guest PC 0x0c097dae */
if(!s->budget--) { s->failed_pc=0x0c097daeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c097db0;
P_0c097db0: /* original 8905, guest PC 0x0c097db0 */
if(!s->budget--) { s->failed_pc=0x0c097db0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097dbe; }
goto P_0c097db2;
P_0c097db2: /* original 9022, guest PC 0x0c097db2 */
if(!s->budget--) { s->failed_pc=0x0c097db2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097dfau,2);
goto P_0c097db4;
P_0c097db4: /* original 02ec, guest PC 0x0c097db4 */
if(!s->budget--) { s->failed_pc=0x0c097db4u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097db6;
P_0c097db6: /* original 622b, guest PC 0x0c097db6 */
if(!s->budget--) { s->failed_pc=0x0c097db6u; return 0; }
r[2]=0u-r[2];
goto P_0c097db8;
P_0c097db8: /* original 7201, guest PC 0x0c097db8 */
if(!s->budget--) { s->failed_pc=0x0c097db8u; return 0; }
r[2]+=0x00000001u;
goto P_0c097dba;
P_0c097dba: /* original a009, guest PC 0x0c097dba */
if(!s->budget--) { s->failed_pc=0x0c097dbau; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097dd0;
P_0c097dbc: /* original 0e24, guest PC 0x0c097dbc */
if(!s->budget--) { s->failed_pc=0x0c097dbcu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097dbe;
P_0c097dbe: /* original 901c, guest PC 0x0c097dbe */
if(!s->budget--) { s->failed_pc=0x0c097dbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097dfau,2);
goto P_0c097dc0;
P_0c097dc0: /* original 01ec, guest PC 0x0c097dc0 */
if(!s->budget--) { s->failed_pc=0x0c097dc0u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097dc2;
P_0c097dc2: /* original 2118, guest PC 0x0c097dc2 */
if(!s->budget--) { s->failed_pc=0x0c097dc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c097dc4;
P_0c097dc4: /* original 8b01, guest PC 0x0c097dc4 */
if(!s->budget--) { s->failed_pc=0x0c097dc4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c097dca; }
goto P_0c097dc6;
P_0c097dc6: /* original a002, guest PC 0x0c097dc6 */
if(!s->budget--) { s->failed_pc=0x0c097dc6u; return 0; }
r[2]=0x00000003u;
goto P_0c097dce;
P_0c097dc8: /* original e203, guest PC 0x0c097dc8 */
if(!s->budget--) { s->failed_pc=0x0c097dc8u; return 0; }
r[2]=0x00000003u;
goto P_0c097dca;
P_0c097dca: /* original 02ec, guest PC 0x0c097dca */
if(!s->budget--) { s->failed_pc=0x0c097dcau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097dcc;
P_0c097dcc: /* original 72ff, guest PC 0x0c097dcc */
if(!s->budget--) { s->failed_pc=0x0c097dccu; return 0; }
r[2]+=0xffffffffu;
goto P_0c097dce;
P_0c097dce: /* original 0e24, guest PC 0x0c097dce */
if(!s->budget--) { s->failed_pc=0x0c097dceu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097dd0;
P_0c097dd0: /* original e320, guest PC 0x0c097dd0 */
if(!s->budget--) { s->failed_pc=0x0c097dd0u; return 0; }
r[3]=0x00000020u;
goto P_0c097dd2;
P_0c097dd2: /* original 23d8, guest PC 0x0c097dd2 */
if(!s->budget--) { s->failed_pc=0x0c097dd2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c097dd4;
P_0c097dd4: /* original 8923, guest PC 0x0c097dd4 */
if(!s->budget--) { s->failed_pc=0x0c097dd4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097e1e; }
goto P_0c097dd6;
P_0c097dd6: /* original 940e, guest PC 0x0c097dd6 */
if(!s->budget--) { s->failed_pc=0x0c097dd6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df6u,2);
goto P_0c097dd8;
P_0c097dd8: /* original 480b, guest PC 0x0c097dd8 */
if(!s->budget--) { s->failed_pc=0x0c097dd8u; return 0; }
target=r[8];
r[16]=code_base|0x0c097ddcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097ddcu) { target=s->pc; goto dispatch; }
goto P_0c097ddc;
P_0c097dda: /* original 0009, guest PC 0x0c097dda */
if(!s->budget--) { s->failed_pc=0x0c097ddau; return 0; }
goto P_0c097ddc;
P_0c097ddc: /* original 900c, guest PC 0x0c097ddc */
if(!s->budget--) { s->failed_pc=0x0c097ddcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097df8u,2);
goto P_0c097dde;
P_0c097dde: /* original 00ec, guest PC 0x0c097dde */
if(!s->budget--) { s->failed_pc=0x0c097ddeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097de0;
P_0c097de0: /* original 8801, guest PC 0x0c097de0 */
if(!s->budget--) { s->failed_pc=0x0c097de0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c097de2;
P_0c097de2: /* original 8913, guest PC 0x0c097de2 */
if(!s->budget--) { s->failed_pc=0x0c097de2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097e0c; }
goto P_0c097de4;
P_0c097de4: /* original 9009, guest PC 0x0c097de4 */
if(!s->budget--) { s->failed_pc=0x0c097de4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097dfau,2);
goto P_0c097de6;
P_0c097de6: /* original 02ec, guest PC 0x0c097de6 */
if(!s->budget--) { s->failed_pc=0x0c097de6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097de8;
P_0c097de8: /* original 622b, guest PC 0x0c097de8 */
if(!s->budget--) { s->failed_pc=0x0c097de8u; return 0; }
r[2]=0u-r[2];
goto P_0c097dea;
P_0c097dea: /* original 7201, guest PC 0x0c097dea */
if(!s->budget--) { s->failed_pc=0x0c097deau; return 0; }
r[2]+=0x00000001u;
goto P_0c097dec;
P_0c097dec: /* original a017, guest PC 0x0c097dec */
if(!s->budget--) { s->failed_pc=0x0c097decu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097e1e;
P_0c097dee: /* original 0e24, guest PC 0x0c097dee */
if(!s->budget--) { s->failed_pc=0x0c097deeu; return 0; }
write(ram,r[14]+r[0],r[2],1);
return vf3_matrix_family(0x0c097df0u,s,ram);
P_0c097e0c: /* original 904b, guest PC 0x0c097e0c */
if(!s->budget--) { s->failed_pc=0x0c097e0cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097ea6u,2);
goto P_0c097e0e;
P_0c097e0e: /* original e303, guest PC 0x0c097e0e */
if(!s->budget--) { s->failed_pc=0x0c097e0eu; return 0; }
r[3]=0x00000003u;
goto P_0c097e10;
P_0c097e10: /* original 01ec, guest PC 0x0c097e10 */
if(!s->budget--) { s->failed_pc=0x0c097e10u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097e12;
P_0c097e12: /* original 3133, guest PC 0x0c097e12 */
if(!s->budget--) { s->failed_pc=0x0c097e12u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c097e14;
P_0c097e14: /* original 8b01, guest PC 0x0c097e14 */
if(!s->budget--) { s->failed_pc=0x0c097e14u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c097e1a; }
goto P_0c097e16;
P_0c097e16: /* original a002, guest PC 0x0c097e16 */
if(!s->budget--) { s->failed_pc=0x0c097e16u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c097e1e;
P_0c097e18: /* original 0eb4, guest PC 0x0c097e18 */
if(!s->budget--) { s->failed_pc=0x0c097e18u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c097e1a;
P_0c097e1a: /* original 7101, guest PC 0x0c097e1a */
if(!s->budget--) { s->failed_pc=0x0c097e1au; return 0; }
r[1]+=0x00000001u;
goto P_0c097e1c;
P_0c097e1c: /* original 0e14, guest PC 0x0c097e1c */
if(!s->budget--) { s->failed_pc=0x0c097e1cu; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c097e1e;
P_0c097e1e: /* original 9343, guest PC 0x0c097e1e */
if(!s->budget--) { s->failed_pc=0x0c097e1eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097ea8u,2);
goto P_0c097e20;
P_0c097e20: /* original 23d8, guest PC 0x0c097e20 */
if(!s->budget--) { s->failed_pc=0x0c097e20u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c097e22;
P_0c097e22: /* original 894b, guest PC 0x0c097e22 */
if(!s->budget--) { s->failed_pc=0x0c097e22u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097ebc; }
goto P_0c097e24;
P_0c097e24: /* original 480b, guest PC 0x0c097e24 */
if(!s->budget--) { s->failed_pc=0x0c097e24u; return 0; }
target=r[8];
r[16]=code_base|0x0c097e28u;
r[4]=0x0000007fu;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097e28u) { target=s->pc; goto dispatch; }
goto P_0c097e28;
P_0c097e26: /* original e47f, guest PC 0x0c097e26 */
if(!s->budget--) { s->failed_pc=0x0c097e26u; return 0; }
r[4]=0x0000007fu;
goto P_0c097e28;
P_0c097e28: /* original 903d, guest PC 0x0c097e28 */
if(!s->budget--) { s->failed_pc=0x0c097e28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097ea6u,2);
goto P_0c097e2a;
P_0c097e2a: /* original 00ec, guest PC 0x0c097e2a */
if(!s->budget--) { s->failed_pc=0x0c097e2au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097e2c;
P_0c097e2c: /* original 8800, guest PC 0x0c097e2c */
if(!s->budget--) { s->failed_pc=0x0c097e2cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c097e2e;
P_0c097e2e: /* original 8907, guest PC 0x0c097e2e */
if(!s->budget--) { s->failed_pc=0x0c097e2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097e40; }
goto P_0c097e30;
P_0c097e30: /* original 8801, guest PC 0x0c097e30 */
if(!s->budget--) { s->failed_pc=0x0c097e30u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c097e32;
P_0c097e32: /* original 890b, guest PC 0x0c097e32 */
if(!s->budget--) { s->failed_pc=0x0c097e32u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097e4c; }
goto P_0c097e34;
P_0c097e34: /* original 8802, guest PC 0x0c097e34 */
if(!s->budget--) { s->failed_pc=0x0c097e34u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c097e36;
P_0c097e36: /* original 8926, guest PC 0x0c097e36 */
if(!s->budget--) { s->failed_pc=0x0c097e36u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097e86; }
goto P_0c097e38;
P_0c097e38: /* original 8803, guest PC 0x0c097e38 */
if(!s->budget--) { s->failed_pc=0x0c097e38u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c097e3a;
P_0c097e3a: /* original 892c, guest PC 0x0c097e3a */
if(!s->budget--) { s->failed_pc=0x0c097e3au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097e96; }
goto P_0c097e3c;
P_0c097e3c: /* original a03e, guest PC 0x0c097e3c */
if(!s->budget--) { s->failed_pc=0x0c097e3cu; return 0; }
goto P_0c097ebc;
P_0c097e3e: /* original 0009, guest PC 0x0c097e3e */
if(!s->budget--) { s->failed_pc=0x0c097e3eu; return 0; }
goto P_0c097e40;
P_0c097e40: /* original 9033, guest PC 0x0c097e40 */
if(!s->budget--) { s->failed_pc=0x0c097e40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097eaau,2);
goto P_0c097e42;
P_0c097e42: /* original 03ec, guest PC 0x0c097e42 */
if(!s->budget--) { s->failed_pc=0x0c097e42u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097e44;
P_0c097e44: /* original 633b, guest PC 0x0c097e44 */
if(!s->budget--) { s->failed_pc=0x0c097e44u; return 0; }
r[3]=0u-r[3];
goto P_0c097e46;
P_0c097e46: /* original 7301, guest PC 0x0c097e46 */
if(!s->budget--) { s->failed_pc=0x0c097e46u; return 0; }
r[3]+=0x00000001u;
goto P_0c097e48;
P_0c097e48: /* original a038, guest PC 0x0c097e48 */
if(!s->budget--) { s->failed_pc=0x0c097e48u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c097ebc;
P_0c097e4a: /* original 0e34, guest PC 0x0c097e4a */
if(!s->budget--) { s->failed_pc=0x0c097e4au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c097e4c;
P_0c097e4c: /* original 902e, guest PC 0x0c097e4c */
if(!s->budget--) { s->failed_pc=0x0c097e4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097eacu,2);
goto P_0c097e4e;
P_0c097e4e: /* original e309, guest PC 0x0c097e4e */
if(!s->budget--) { s->failed_pc=0x0c097e4eu; return 0; }
r[3]=0x00000009u;
goto P_0c097e50;
P_0c097e50: /* original 01ec, guest PC 0x0c097e50 */
if(!s->budget--) { s->failed_pc=0x0c097e50u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097e52;
P_0c097e52: /* original 3137, guest PC 0x0c097e52 */
if(!s->budget--) { s->failed_pc=0x0c097e52u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[3])!=0);
goto P_0c097e54;
P_0c097e54: /* original 8b01, guest PC 0x0c097e54 */
if(!s->budget--) { s->failed_pc=0x0c097e54u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c097e5a; }
goto P_0c097e56;
P_0c097e56: /* original a002, guest PC 0x0c097e56 */
if(!s->budget--) { s->failed_pc=0x0c097e56u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c097e5e;
P_0c097e58: /* original 0eb4, guest PC 0x0c097e58 */
if(!s->budget--) { s->failed_pc=0x0c097e58u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c097e5a;
P_0c097e5a: /* original 7101, guest PC 0x0c097e5a */
if(!s->budget--) { s->failed_pc=0x0c097e5au; return 0; }
r[1]+=0x00000001u;
goto P_0c097e5c;
P_0c097e5c: /* original 0e14, guest PC 0x0c097e5c */
if(!s->budget--) { s->failed_pc=0x0c097e5cu; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c097e5e;
P_0c097e5e: /* original 00ec, guest PC 0x0c097e5e */
if(!s->budget--) { s->failed_pc=0x0c097e5eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097e60;
P_0c097e60: /* original 8800, guest PC 0x0c097e60 */
if(!s->budget--) { s->failed_pc=0x0c097e60u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c097e62;
P_0c097e62: /* original 8903, guest PC 0x0c097e62 */
if(!s->budget--) { s->failed_pc=0x0c097e62u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097e6c; }
goto P_0c097e64;
P_0c097e64: /* original 880a, guest PC 0x0c097e64 */
if(!s->budget--) { s->failed_pc=0x0c097e64u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c097e66;
P_0c097e66: /* original 8905, guest PC 0x0c097e66 */
if(!s->budget--) { s->failed_pc=0x0c097e66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097e74; }
goto P_0c097e68;
P_0c097e68: /* original a007, guest PC 0x0c097e68 */
if(!s->budget--) { s->failed_pc=0x0c097e68u; return 0; }
goto P_0c097e7a;
P_0c097e6a: /* original 0009, guest PC 0x0c097e6a */
if(!s->budget--) { s->failed_pc=0x0c097e6au; return 0; }
goto P_0c097e6c;
P_0c097e6c: /* original 901f, guest PC 0x0c097e6c */
if(!s->budget--) { s->failed_pc=0x0c097e6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097eaeu,2);
goto P_0c097e6e;
P_0c097e6e: /* original e301, guest PC 0x0c097e6e */
if(!s->budget--) { s->failed_pc=0x0c097e6eu; return 0; }
r[3]=0x00000001u;
goto P_0c097e70;
P_0c097e70: /* original a005, guest PC 0x0c097e70 */
if(!s->budget--) { s->failed_pc=0x0c097e70u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c097e7e;
P_0c097e72: /* original 0e34, guest PC 0x0c097e72 */
if(!s->budget--) { s->failed_pc=0x0c097e72u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c097e74;
P_0c097e74: /* original 901b, guest PC 0x0c097e74 */
if(!s->budget--) { s->failed_pc=0x0c097e74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097eaeu,2);
goto P_0c097e76;
P_0c097e76: /* original a002, guest PC 0x0c097e76 */
if(!s->budget--) { s->failed_pc=0x0c097e76u; return 0; }
write(ram,r[14]+r[0],r[9],1);
goto P_0c097e7e;
P_0c097e78: /* original 0e94, guest PC 0x0c097e78 */
if(!s->budget--) { s->failed_pc=0x0c097e78u; return 0; }
write(ram,r[14]+r[0],r[9],1);
goto P_0c097e7a;
P_0c097e7a: /* original 9018, guest PC 0x0c097e7a */
if(!s->budget--) { s->failed_pc=0x0c097e7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097eaeu,2);
goto P_0c097e7c;
P_0c097e7c: /* original 0eb4, guest PC 0x0c097e7c */
if(!s->budget--) { s->failed_pc=0x0c097e7cu; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c097e7e;
P_0c097e7e: /* original 9017, guest PC 0x0c097e7e */
if(!s->budget--) { s->failed_pc=0x0c097e7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097eb0u,2);
goto P_0c097e80;
P_0c097e80: /* original e201, guest PC 0x0c097e80 */
if(!s->budget--) { s->failed_pc=0x0c097e80u; return 0; }
r[2]=0x00000001u;
goto P_0c097e82;
P_0c097e82: /* original a01b, guest PC 0x0c097e82 */
if(!s->budget--) { s->failed_pc=0x0c097e82u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097ebc;
P_0c097e84: /* original 0e24, guest PC 0x0c097e84 */
if(!s->budget--) { s->failed_pc=0x0c097e84u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097e86;
P_0c097e86: /* original 9014, guest PC 0x0c097e86 */
if(!s->budget--) { s->failed_pc=0x0c097e86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097eb2u,2);
goto P_0c097e88;
P_0c097e88: /* original e30b, guest PC 0x0c097e88 */
if(!s->budget--) { s->failed_pc=0x0c097e88u; return 0; }
r[3]=0x0000000bu;
goto P_0c097e8a;
P_0c097e8a: /* original 01ec, guest PC 0x0c097e8a */
if(!s->budget--) { s->failed_pc=0x0c097e8au; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097e8c;
P_0c097e8c: /* original 3133, guest PC 0x0c097e8c */
if(!s->budget--) { s->failed_pc=0x0c097e8cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c097e8e;
P_0c097e8e: /* original 8908, guest PC 0x0c097e8e */
if(!s->budget--) { s->failed_pc=0x0c097e8eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097ea2; }
goto P_0c097e90;
P_0c097e90: /* original 7101, guest PC 0x0c097e90 */
if(!s->budget--) { s->failed_pc=0x0c097e90u; return 0; }
r[1]+=0x00000001u;
goto P_0c097e92;
P_0c097e92: /* original a013, guest PC 0x0c097e92 */
if(!s->budget--) { s->failed_pc=0x0c097e92u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c097ebc;
P_0c097e94: /* original 0e14, guest PC 0x0c097e94 */
if(!s->budget--) { s->failed_pc=0x0c097e94u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c097e96;
P_0c097e96: /* original 900d, guest PC 0x0c097e96 */
if(!s->budget--) { s->failed_pc=0x0c097e96u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097eb4u,2);
goto P_0c097e98;
P_0c097e98: /* original e304, guest PC 0x0c097e98 */
if(!s->budget--) { s->failed_pc=0x0c097e98u; return 0; }
r[3]=0x00000004u;
goto P_0c097e9a;
P_0c097e9a: /* original 02ec, guest PC 0x0c097e9a */
if(!s->budget--) { s->failed_pc=0x0c097e9au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097e9c;
P_0c097e9c: /* original 3233, guest PC 0x0c097e9c */
if(!s->budget--) { s->failed_pc=0x0c097e9cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c097e9e;
P_0c097e9e: /* original 8b0a, guest PC 0x0c097e9e */
if(!s->budget--) { s->failed_pc=0x0c097e9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c097eb6; }
goto P_0c097ea0;
P_0c097ea0: /* original 9008, guest PC 0x0c097ea0 */
if(!s->budget--) { s->failed_pc=0x0c097ea0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097eb4u,2);
goto P_0c097ea2;
P_0c097ea2: /* original a00b, guest PC 0x0c097ea2 */
if(!s->budget--) { s->failed_pc=0x0c097ea2u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c097ebc;
P_0c097ea4: /* original 0eb4, guest PC 0x0c097ea4 */
if(!s->budget--) { s->failed_pc=0x0c097ea4u; return 0; }
write(ram,r[14]+r[0],r[11],1);
return vf3_matrix_family(0x0c097ea6u,s,ram);
P_0c097eb6: /* original 01ec, guest PC 0x0c097eb6 */
if(!s->budget--) { s->failed_pc=0x0c097eb6u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097eb8;
P_0c097eb8: /* original 7101, guest PC 0x0c097eb8 */
if(!s->budget--) { s->failed_pc=0x0c097eb8u; return 0; }
r[1]+=0x00000001u;
goto P_0c097eba;
P_0c097eba: /* original 0e14, guest PC 0x0c097eba */
if(!s->budget--) { s->failed_pc=0x0c097ebau; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c097ebc;
P_0c097ebc: /* original e240, guest PC 0x0c097ebc */
if(!s->budget--) { s->failed_pc=0x0c097ebcu; return 0; }
r[2]=0x00000040u;
goto P_0c097ebe;
P_0c097ebe: /* original 22d8, guest PC 0x0c097ebe */
if(!s->budget--) { s->failed_pc=0x0c097ebeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c097ec0;
P_0c097ec0: /* original 8943, guest PC 0x0c097ec0 */
if(!s->budget--) { s->failed_pc=0x0c097ec0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097f4a; }
goto P_0c097ec2;
P_0c097ec2: /* original 480b, guest PC 0x0c097ec2 */
if(!s->budget--) { s->failed_pc=0x0c097ec2u; return 0; }
target=r[8];
r[16]=code_base|0x0c097ec6u;
r[4]=0x0000007fu;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097ec6u) { target=s->pc; goto dispatch; }
goto P_0c097ec6;
P_0c097ec4: /* original e47f, guest PC 0x0c097ec4 */
if(!s->budget--) { s->failed_pc=0x0c097ec4u; return 0; }
r[4]=0x0000007fu;
goto P_0c097ec6;
P_0c097ec6: /* original 9058, guest PC 0x0c097ec6 */
if(!s->budget--) { s->failed_pc=0x0c097ec6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097f7au,2);
goto P_0c097ec8;
P_0c097ec8: /* original 00ec, guest PC 0x0c097ec8 */
if(!s->budget--) { s->failed_pc=0x0c097ec8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097eca;
P_0c097eca: /* original 8800, guest PC 0x0c097eca */
if(!s->budget--) { s->failed_pc=0x0c097ecau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c097ecc;
P_0c097ecc: /* original 8907, guest PC 0x0c097ecc */
if(!s->budget--) { s->failed_pc=0x0c097eccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097ede; }
goto P_0c097ece;
P_0c097ece: /* original 8801, guest PC 0x0c097ece */
if(!s->budget--) { s->failed_pc=0x0c097eceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c097ed0;
P_0c097ed0: /* original 890b, guest PC 0x0c097ed0 */
if(!s->budget--) { s->failed_pc=0x0c097ed0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097eea; }
goto P_0c097ed2;
P_0c097ed2: /* original 8802, guest PC 0x0c097ed2 */
if(!s->budget--) { s->failed_pc=0x0c097ed2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c097ed4;
P_0c097ed4: /* original 8926, guest PC 0x0c097ed4 */
if(!s->budget--) { s->failed_pc=0x0c097ed4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097f24; }
goto P_0c097ed6;
P_0c097ed6: /* original 8803, guest PC 0x0c097ed6 */
if(!s->budget--) { s->failed_pc=0x0c097ed6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c097ed8;
P_0c097ed8: /* original 892e, guest PC 0x0c097ed8 */
if(!s->budget--) { s->failed_pc=0x0c097ed8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097f38; }
goto P_0c097eda;
P_0c097eda: /* original a036, guest PC 0x0c097eda */
if(!s->budget--) { s->failed_pc=0x0c097edau; return 0; }
goto P_0c097f4a;
P_0c097edc: /* original 0009, guest PC 0x0c097edc */
if(!s->budget--) { s->failed_pc=0x0c097edcu; return 0; }
goto P_0c097ede;
P_0c097ede: /* original 904d, guest PC 0x0c097ede */
if(!s->budget--) { s->failed_pc=0x0c097edeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097f7cu,2);
goto P_0c097ee0;
P_0c097ee0: /* original 03ec, guest PC 0x0c097ee0 */
if(!s->budget--) { s->failed_pc=0x0c097ee0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097ee2;
P_0c097ee2: /* original 633b, guest PC 0x0c097ee2 */
if(!s->budget--) { s->failed_pc=0x0c097ee2u; return 0; }
r[3]=0u-r[3];
goto P_0c097ee4;
P_0c097ee4: /* original 7301, guest PC 0x0c097ee4 */
if(!s->budget--) { s->failed_pc=0x0c097ee4u; return 0; }
r[3]+=0x00000001u;
goto P_0c097ee6;
P_0c097ee6: /* original a030, guest PC 0x0c097ee6 */
if(!s->budget--) { s->failed_pc=0x0c097ee6u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c097f4a;
P_0c097ee8: /* original 0e34, guest PC 0x0c097ee8 */
if(!s->budget--) { s->failed_pc=0x0c097ee8u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c097eea;
P_0c097eea: /* original 9048, guest PC 0x0c097eea */
if(!s->budget--) { s->failed_pc=0x0c097eeau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097f7eu,2);
goto P_0c097eec;
P_0c097eec: /* original 01ec, guest PC 0x0c097eec */
if(!s->budget--) { s->failed_pc=0x0c097eecu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097eee;
P_0c097eee: /* original 4115, guest PC 0x0c097eee */
if(!s->budget--) { s->failed_pc=0x0c097eeeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c097ef0;
P_0c097ef0: /* original 8901, guest PC 0x0c097ef0 */
if(!s->budget--) { s->failed_pc=0x0c097ef0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097ef6; }
goto P_0c097ef2;
P_0c097ef2: /* original a002, guest PC 0x0c097ef2 */
if(!s->budget--) { s->failed_pc=0x0c097ef2u; return 0; }
r[2]=0x0000000au;
goto P_0c097efa;
P_0c097ef4: /* original e20a, guest PC 0x0c097ef4 */
if(!s->budget--) { s->failed_pc=0x0c097ef4u; return 0; }
r[2]=0x0000000au;
goto P_0c097ef6;
P_0c097ef6: /* original 02ec, guest PC 0x0c097ef6 */
if(!s->budget--) { s->failed_pc=0x0c097ef6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097ef8;
P_0c097ef8: /* original 72ff, guest PC 0x0c097ef8 */
if(!s->budget--) { s->failed_pc=0x0c097ef8u; return 0; }
r[2]+=0xffffffffu;
goto P_0c097efa;
P_0c097efa: /* original 0e24, guest PC 0x0c097efa */
if(!s->budget--) { s->failed_pc=0x0c097efau; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097efc;
P_0c097efc: /* original 00ec, guest PC 0x0c097efc */
if(!s->budget--) { s->failed_pc=0x0c097efcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097efe;
P_0c097efe: /* original 8800, guest PC 0x0c097efe */
if(!s->budget--) { s->failed_pc=0x0c097efeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c097f00;
P_0c097f00: /* original 8903, guest PC 0x0c097f00 */
if(!s->budget--) { s->failed_pc=0x0c097f00u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097f0a; }
goto P_0c097f02;
P_0c097f02: /* original 880a, guest PC 0x0c097f02 */
if(!s->budget--) { s->failed_pc=0x0c097f02u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c097f04;
P_0c097f04: /* original 8905, guest PC 0x0c097f04 */
if(!s->budget--) { s->failed_pc=0x0c097f04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097f12; }
goto P_0c097f06;
P_0c097f06: /* original a007, guest PC 0x0c097f06 */
if(!s->budget--) { s->failed_pc=0x0c097f06u; return 0; }
goto P_0c097f18;
P_0c097f08: /* original 0009, guest PC 0x0c097f08 */
if(!s->budget--) { s->failed_pc=0x0c097f08u; return 0; }
goto P_0c097f0a;
P_0c097f0a: /* original 9039, guest PC 0x0c097f0a */
if(!s->budget--) { s->failed_pc=0x0c097f0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097f80u,2);
goto P_0c097f0c;
P_0c097f0c: /* original e301, guest PC 0x0c097f0c */
if(!s->budget--) { s->failed_pc=0x0c097f0cu; return 0; }
r[3]=0x00000001u;
goto P_0c097f0e;
P_0c097f0e: /* original a005, guest PC 0x0c097f0e */
if(!s->budget--) { s->failed_pc=0x0c097f0eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c097f1c;
P_0c097f10: /* original 0e34, guest PC 0x0c097f10 */
if(!s->budget--) { s->failed_pc=0x0c097f10u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c097f12;
P_0c097f12: /* original 9035, guest PC 0x0c097f12 */
if(!s->budget--) { s->failed_pc=0x0c097f12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097f80u,2);
goto P_0c097f14;
P_0c097f14: /* original a002, guest PC 0x0c097f14 */
if(!s->budget--) { s->failed_pc=0x0c097f14u; return 0; }
write(ram,r[14]+r[0],r[9],1);
goto P_0c097f1c;
P_0c097f16: /* original 0e94, guest PC 0x0c097f16 */
if(!s->budget--) { s->failed_pc=0x0c097f16u; return 0; }
write(ram,r[14]+r[0],r[9],1);
goto P_0c097f18;
P_0c097f18: /* original 9032, guest PC 0x0c097f18 */
if(!s->budget--) { s->failed_pc=0x0c097f18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097f80u,2);
goto P_0c097f1a;
P_0c097f1a: /* original 0eb4, guest PC 0x0c097f1a */
if(!s->budget--) { s->failed_pc=0x0c097f1au; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c097f1c;
P_0c097f1c: /* original 9031, guest PC 0x0c097f1c */
if(!s->budget--) { s->failed_pc=0x0c097f1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097f82u,2);
goto P_0c097f1e;
P_0c097f1e: /* original e201, guest PC 0x0c097f1e */
if(!s->budget--) { s->failed_pc=0x0c097f1eu; return 0; }
r[2]=0x00000001u;
goto P_0c097f20;
P_0c097f20: /* original a013, guest PC 0x0c097f20 */
if(!s->budget--) { s->failed_pc=0x0c097f20u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097f4a;
P_0c097f22: /* original 0e24, guest PC 0x0c097f22 */
if(!s->budget--) { s->failed_pc=0x0c097f22u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097f24;
P_0c097f24: /* original 902e, guest PC 0x0c097f24 */
if(!s->budget--) { s->failed_pc=0x0c097f24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097f84u,2);
goto P_0c097f26;
P_0c097f26: /* original 01ec, guest PC 0x0c097f26 */
if(!s->budget--) { s->failed_pc=0x0c097f26u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097f28;
P_0c097f28: /* original 4115, guest PC 0x0c097f28 */
if(!s->budget--) { s->failed_pc=0x0c097f28u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c097f2a;
P_0c097f2a: /* original 8901, guest PC 0x0c097f2a */
if(!s->budget--) { s->failed_pc=0x0c097f2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097f30; }
goto P_0c097f2c;
P_0c097f2c: /* original a002, guest PC 0x0c097f2c */
if(!s->budget--) { s->failed_pc=0x0c097f2cu; return 0; }
r[2]=0x0000000bu;
goto P_0c097f34;
P_0c097f2e: /* original e20b, guest PC 0x0c097f2e */
if(!s->budget--) { s->failed_pc=0x0c097f2eu; return 0; }
r[2]=0x0000000bu;
goto P_0c097f30;
P_0c097f30: /* original 02ec, guest PC 0x0c097f30 */
if(!s->budget--) { s->failed_pc=0x0c097f30u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097f32;
P_0c097f32: /* original 72ff, guest PC 0x0c097f32 */
if(!s->budget--) { s->failed_pc=0x0c097f32u; return 0; }
r[2]+=0xffffffffu;
goto P_0c097f34;
P_0c097f34: /* original a009, guest PC 0x0c097f34 */
if(!s->budget--) { s->failed_pc=0x0c097f34u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097f4a;
P_0c097f36: /* original 0e24, guest PC 0x0c097f36 */
if(!s->budget--) { s->failed_pc=0x0c097f36u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097f38;
P_0c097f38: /* original 9025, guest PC 0x0c097f38 */
if(!s->budget--) { s->failed_pc=0x0c097f38u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097f86u,2);
goto P_0c097f3a;
P_0c097f3a: /* original 01ec, guest PC 0x0c097f3a */
if(!s->budget--) { s->failed_pc=0x0c097f3au; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097f3c;
P_0c097f3c: /* original 4115, guest PC 0x0c097f3c */
if(!s->budget--) { s->failed_pc=0x0c097f3cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c097f3e;
P_0c097f3e: /* original 8901, guest PC 0x0c097f3e */
if(!s->budget--) { s->failed_pc=0x0c097f3eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097f44; }
goto P_0c097f40;
P_0c097f40: /* original a002, guest PC 0x0c097f40 */
if(!s->budget--) { s->failed_pc=0x0c097f40u; return 0; }
r[2]=0x00000004u;
goto P_0c097f48;
P_0c097f42: /* original e204, guest PC 0x0c097f42 */
if(!s->budget--) { s->failed_pc=0x0c097f42u; return 0; }
r[2]=0x00000004u;
goto P_0c097f44;
P_0c097f44: /* original 02ec, guest PC 0x0c097f44 */
if(!s->budget--) { s->failed_pc=0x0c097f44u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097f46;
P_0c097f46: /* original 72ff, guest PC 0x0c097f46 */
if(!s->budget--) { s->failed_pc=0x0c097f46u; return 0; }
r[2]+=0xffffffffu;
goto P_0c097f48;
P_0c097f48: /* original 0e24, guest PC 0x0c097f48 */
if(!s->budget--) { s->failed_pc=0x0c097f48u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c097f4a;
P_0c097f4a: /* original 2d98, guest PC 0x0c097f4a */
if(!s->budget--) { s->failed_pc=0x0c097f4au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[9])==0)!=0);
goto P_0c097f4c;
P_0c097f4c: /* original 892f, guest PC 0x0c097f4c */
if(!s->budget--) { s->failed_pc=0x0c097f4cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097fae; }
goto P_0c097f4e;
P_0c097f4e: /* original d30f, guest PC 0x0c097f4e */
if(!s->budget--) { s->failed_pc=0x0c097f4eu; return 0; }
r[3]=read(ram,0x0c097f8cu,4);
goto P_0c097f50;
P_0c097f50: /* original 430b, guest PC 0x0c097f50 */
if(!s->budget--) { s->failed_pc=0x0c097f50u; return 0; }
target=r[3];
r[16]=code_base|0x0c097f54u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097f54u) { target=s->pc; goto dispatch; }
goto P_0c097f54;
P_0c097f52: /* original 0009, guest PC 0x0c097f52 */
if(!s->budget--) { s->failed_pc=0x0c097f52u; return 0; }
goto P_0c097f54;
P_0c097f54: /* original e029, guest PC 0x0c097f54 */
if(!s->budget--) { s->failed_pc=0x0c097f54u; return 0; }
r[0]=0x00000029u;
goto P_0c097f56;
P_0c097f56: /* original 0cb4, guest PC 0x0c097f56 */
if(!s->budget--) { s->failed_pc=0x0c097f56u; return 0; }
write(ram,r[12]+r[0],r[11],1);
goto P_0c097f58;
P_0c097f58: /* original 6093, guest PC 0x0c097f58 */
if(!s->budget--) { s->failed_pc=0x0c097f58u; return 0; }
r[0]=r[9];
goto P_0c097f5a;
P_0c097f5a: /* original 54c2, guest PC 0x0c097f5a */
if(!s->budget--) { s->failed_pc=0x0c097f5au; return 0; }
r[4]=read(ram,r[12]+8,4);
goto P_0c097f5c;
P_0c097f5c: /* original d30c, guest PC 0x0c097f5c */
if(!s->budget--) { s->failed_pc=0x0c097f5cu; return 0; }
r[3]=read(ram,0x0c097f90u,4);
goto P_0c097f5e;
P_0c097f5e: /* original 2439, guest PC 0x0c097f5e */
if(!s->budget--) { s->failed_pc=0x0c097f5eu; return 0; }
r[4]&=r[3];
goto P_0c097f60;
P_0c097f60: /* original 1c42, guest PC 0x0c097f60 */
if(!s->budget--) { s->failed_pc=0x0c097f60u; return 0; }
write(ram,r[12]+8,r[4],4);
goto P_0c097f62;
P_0c097f62: /* original d20c, guest PC 0x0c097f62 */
if(!s->budget--) { s->failed_pc=0x0c097f62u; return 0; }
r[2]=read(ram,0x0c097f94u,4);
goto P_0c097f64;
P_0c097f64: /* original 420b, guest PC 0x0c097f64 */
if(!s->budget--) { s->failed_pc=0x0c097f64u; return 0; }
target=r[2];
r[16]=code_base|0x0c097f68u;
write(ram,r[14]+10,r[0],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097f68u) { target=s->pc; goto dispatch; }
goto P_0c097f68;
P_0c097f66: /* original 80ea, guest PC 0x0c097f66 */
if(!s->budget--) { s->failed_pc=0x0c097f66u; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c097f68;
P_0c097f68: /* original 62a2, guest PC 0x0c097f68 */
if(!s->budget--) { s->failed_pc=0x0c097f68u; return 0; }
tmp=read(ram,r[10],4);
r[2]=tmp;
goto P_0c097f6a;
P_0c097f6a: /* original d30b, guest PC 0x0c097f6a */
if(!s->budget--) { s->failed_pc=0x0c097f6au; return 0; }
r[3]=read(ram,0x0c097f98u,4);
goto P_0c097f6c;
P_0c097f6c: /* original 2239, guest PC 0x0c097f6c */
if(!s->budget--) { s->failed_pc=0x0c097f6cu; return 0; }
r[2]&=r[3];
goto P_0c097f6e;
P_0c097f6e: /* original 2a22, guest PC 0x0c097f6e */
if(!s->budget--) { s->failed_pc=0x0c097f6eu; return 0; }
write(ram,r[10],r[2],4);
goto P_0c097f70;
P_0c097f70: /* original 9006, guest PC 0x0c097f70 */
if(!s->budget--) { s->failed_pc=0x0c097f70u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097f80u,2);
goto P_0c097f72;
P_0c097f72: /* original 0eb4, guest PC 0x0c097f72 */
if(!s->budget--) { s->failed_pc=0x0c097f72u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c097f74;
P_0c097f74: /* original 9008, guest PC 0x0c097f74 */
if(!s->budget--) { s->failed_pc=0x0c097f74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097f88u,2);
goto P_0c097f76;
P_0c097f76: /* original a032, guest PC 0x0c097f76 */
if(!s->budget--) { s->failed_pc=0x0c097f76u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c097fde;
P_0c097f78: /* original 0eb4, guest PC 0x0c097f78 */
if(!s->budget--) { s->failed_pc=0x0c097f78u; return 0; }
write(ram,r[14]+r[0],r[11],1);
return vf3_matrix_family(0x0c097f7au,s,ram);
P_0c097f9c: /* original 9075, guest PC 0x0c097f9c */
if(!s->budget--) { s->failed_pc=0x0c097f9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09808au,2);
goto P_0c097f9e;
P_0c097f9e: /* original 02ec, guest PC 0x0c097f9e */
if(!s->budget--) { s->failed_pc=0x0c097f9eu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c097fa0;
P_0c097fa0: /* original 2228, guest PC 0x0c097fa0 */
if(!s->budget--) { s->failed_pc=0x0c097fa0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c097fa2;
P_0c097fa2: /* original 8904, guest PC 0x0c097fa2 */
if(!s->budget--) { s->failed_pc=0x0c097fa2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c097fae; }
goto P_0c097fa4;
P_0c097fa4: /* original e010, guest PC 0x0c097fa4 */
if(!s->budget--) { s->failed_pc=0x0c097fa4u; return 0; }
r[0]=0x00000010u;
goto P_0c097fa6;
P_0c097fa6: /* original b025, guest PC 0x0c097fa6 */
if(!s->budget--) { s->failed_pc=0x0c097fa6u; return 0; }
target=0x0c097ff4u; r[16]=code_base|0x0c097faau;
write(ram,r[14]+11,r[0],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097faau) { target=s->pc; goto dispatch; }
goto P_0c097faa;
P_0c097fa8: /* original 80eb, guest PC 0x0c097fa8 */
if(!s->budget--) { s->failed_pc=0x0c097fa8u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c097faa;
P_0c097faa: /* original 906e, guest PC 0x0c097faa */
if(!s->budget--) { s->failed_pc=0x0c097faau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09808au,2);
goto P_0c097fac;
P_0c097fac: /* original 0eb4, guest PC 0x0c097fac */
if(!s->budget--) { s->failed_pc=0x0c097facu; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c097fae;
P_0c097fae: /* original 84eb, guest PC 0x0c097fae */
if(!s->budget--) { s->failed_pc=0x0c097faeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c097fb0;
P_0c097fb0: /* original 640c, guest PC 0x0c097fb0 */
if(!s->budget--) { s->failed_pc=0x0c097fb0u; return 0; }
r[4]=r[0]&255u;
goto P_0c097fb2;
P_0c097fb2: /* original 6043, guest PC 0x0c097fb2 */
if(!s->budget--) { s->failed_pc=0x0c097fb2u; return 0; }
r[0]=r[4];
goto P_0c097fb4;
P_0c097fb4: /* original 80e9, guest PC 0x0c097fb4 */
if(!s->budget--) { s->failed_pc=0x0c097fb4u; return 0; }
write(ram,r[14]+9,r[0],1);
goto P_0c097fb6;
P_0c097fb6: /* original d235, guest PC 0x0c097fb6 */
if(!s->budget--) { s->failed_pc=0x0c097fb6u; return 0; }
r[2]=read(ram,0x0c09808cu,4);
goto P_0c097fb8;
P_0c097fb8: /* original 634b, guest PC 0x0c097fb8 */
if(!s->budget--) { s->failed_pc=0x0c097fb8u; return 0; }
r[3]=0u-r[4];
goto P_0c097fba;
P_0c097fba: /* original 4408, guest PC 0x0c097fba */
if(!s->budget--) { s->failed_pc=0x0c097fbau; return 0; }
r[4]<<=2;
goto P_0c097fbc;
P_0c097fbc: /* original 423d, guest PC 0x0c097fbc */
if(!s->budget--) { s->failed_pc=0x0c097fbcu; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c097fbe;
P_0c097fbe: /* original 1e21, guest PC 0x0c097fbe */
if(!s->budget--) { s->failed_pc=0x0c097fbeu; return 0; }
write(ram,r[14]+4,r[2],4);
goto P_0c097fc0;
P_0c097fc0: /* original d033, guest PC 0x0c097fc0 */
if(!s->budget--) { s->failed_pc=0x0c097fc0u; return 0; }
r[0]=read(ram,0x0c098090u,4);
goto P_0c097fc2;
P_0c097fc2: /* original 034e, guest PC 0x0c097fc2 */
if(!s->budget--) { s->failed_pc=0x0c097fc2u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c097fc4;
P_0c097fc4: /* original 2f32, guest PC 0x0c097fc4 */
if(!s->budget--) { s->failed_pc=0x0c097fc4u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c097fc6;
P_0c097fc6: /* original 7f0c, guest PC 0x0c097fc6 */
if(!s->budget--) { s->failed_pc=0x0c097fc6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c097fc8;
P_0c097fc8: /* original 4f26, guest PC 0x0c097fc8 */
if(!s->budget--) { s->failed_pc=0x0c097fc8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c097fca;
P_0c097fca: /* original 6233, guest PC 0x0c097fca */
if(!s->budget--) { s->failed_pc=0x0c097fcau; return 0; }
r[2]=r[3];
goto P_0c097fcc;
P_0c097fcc: /* original fff9, guest PC 0x0c097fcc */
if(!s->budget--) { s->failed_pc=0x0c097fccu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c097fce;
P_0c097fce: /* original 68f6, guest PC 0x0c097fce */
if(!s->budget--) { s->failed_pc=0x0c097fceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c097fd0;
P_0c097fd0: /* original 69f6, guest PC 0x0c097fd0 */
if(!s->budget--) { s->failed_pc=0x0c097fd0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c097fd2;
P_0c097fd2: /* original 6af6, guest PC 0x0c097fd2 */
if(!s->budget--) { s->failed_pc=0x0c097fd2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c097fd4;
P_0c097fd4: /* original 6bf6, guest PC 0x0c097fd4 */
if(!s->budget--) { s->failed_pc=0x0c097fd4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c097fd6;
P_0c097fd6: /* original 6cf6, guest PC 0x0c097fd6 */
if(!s->budget--) { s->failed_pc=0x0c097fd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c097fd8;
P_0c097fd8: /* original 6df6, guest PC 0x0c097fd8 */
if(!s->budget--) { s->failed_pc=0x0c097fd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c097fda;
P_0c097fda: /* original 422b, guest PC 0x0c097fda */
if(!s->budget--) { s->failed_pc=0x0c097fdau; return 0; }
target=r[2];
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
P_0c097fdc: /* original 6ef6, guest PC 0x0c097fdc */
if(!s->budget--) { s->failed_pc=0x0c097fdcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c097fde;
P_0c097fde: /* original 7f0c, guest PC 0x0c097fde */
if(!s->budget--) { s->failed_pc=0x0c097fdeu; return 0; }
r[15]+=0x0000000cu;
goto P_0c097fe0;
P_0c097fe0: /* original 4f26, guest PC 0x0c097fe0 */
if(!s->budget--) { s->failed_pc=0x0c097fe0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c097fe2;
P_0c097fe2: /* original fff9, guest PC 0x0c097fe2 */
if(!s->budget--) { s->failed_pc=0x0c097fe2u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c097fe4;
P_0c097fe4: /* original 68f6, guest PC 0x0c097fe4 */
if(!s->budget--) { s->failed_pc=0x0c097fe4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c097fe6;
P_0c097fe6: /* original 69f6, guest PC 0x0c097fe6 */
if(!s->budget--) { s->failed_pc=0x0c097fe6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c097fe8;
P_0c097fe8: /* original 6af6, guest PC 0x0c097fe8 */
if(!s->budget--) { s->failed_pc=0x0c097fe8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c097fea;
P_0c097fea: /* original 6bf6, guest PC 0x0c097fea */
if(!s->budget--) { s->failed_pc=0x0c097feau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c097fec;
P_0c097fec: /* original 6cf6, guest PC 0x0c097fec */
if(!s->budget--) { s->failed_pc=0x0c097fecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c097fee;
P_0c097fee: /* original 6df6, guest PC 0x0c097fee */
if(!s->budget--) { s->failed_pc=0x0c097feeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c097ff0;
P_0c097ff0: /* original 000b, guest PC 0x0c097ff0 */
if(!s->budget--) { s->failed_pc=0x0c097ff0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c097ff2: /* original 6ef6, guest PC 0x0c097ff2 */
if(!s->budget--) { s->failed_pc=0x0c097ff2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c097ff4u,s,ram);
P_0c099d62: /* original 2fe6, guest PC 0x0c099d62 */
if(!s->budget--) { s->failed_pc=0x0c099d62u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099d64;
P_0c099d64: /* original e060, guest PC 0x0c099d64 */
if(!s->budget--) { s->failed_pc=0x0c099d64u; return 0; }
r[0]=0x00000060u;
goto P_0c099d66;
P_0c099d66: /* original 2fd6, guest PC 0x0c099d66 */
if(!s->budget--) { s->failed_pc=0x0c099d66u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099d68;
P_0c099d68: /* original e601, guest PC 0x0c099d68 */
if(!s->budget--) { s->failed_pc=0x0c099d68u; return 0; }
r[6]=0x00000001u;
goto P_0c099d6a;
P_0c099d6a: /* original 2fc6, guest PC 0x0c099d6a */
if(!s->budget--) { s->failed_pc=0x0c099d6au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099d6c;
P_0c099d6c: /* original 2fb6, guest PC 0x0c099d6c */
if(!s->budget--) { s->failed_pc=0x0c099d6cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099d6e;
P_0c099d6e: /* original 2fa6, guest PC 0x0c099d6e */
if(!s->budget--) { s->failed_pc=0x0c099d6eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099d70;
P_0c099d70: /* original 2f96, guest PC 0x0c099d70 */
if(!s->budget--) { s->failed_pc=0x0c099d70u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099d72;
P_0c099d72: /* original 2f86, guest PC 0x0c099d72 */
if(!s->budget--) { s->failed_pc=0x0c099d72u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099d74;
P_0c099d74: /* original 4f22, guest PC 0x0c099d74 */
if(!s->budget--) { s->failed_pc=0x0c099d74u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c099d76;
P_0c099d76: /* original d318, guest PC 0x0c099d76 */
if(!s->budget--) { s->failed_pc=0x0c099d76u; return 0; }
r[3]=read(ram,0x0c099dd8u,4);
goto P_0c099d78;
P_0c099d78: /* original de10, guest PC 0x0c099d78 */
if(!s->budget--) { s->failed_pc=0x0c099d78u; return 0; }
r[14]=read(ram,0x0c099dbcu,4);
goto P_0c099d7a;
P_0c099d7a: /* original 7ff8, guest PC 0x0c099d7a */
if(!s->budget--) { s->failed_pc=0x0c099d7au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c099d7c;
P_0c099d7c: /* original dd10, guest PC 0x0c099d7c */
if(!s->budget--) { s->failed_pc=0x0c099d7cu; return 0; }
r[13]=read(ram,0x0c099dc0u,4);
goto P_0c099d7e;
P_0c099d7e: /* original 1f31, guest PC 0x0c099d7e */
if(!s->budget--) { s->failed_pc=0x0c099d7eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c099d80;
P_0c099d80: /* original d216, guest PC 0x0c099d80 */
if(!s->budget--) { s->failed_pc=0x0c099d80u; return 0; }
r[2]=read(ram,0x0c099ddcu,4);
goto P_0c099d82;
P_0c099d82: /* original 2f22, guest PC 0x0c099d82 */
if(!s->budget--) { s->failed_pc=0x0c099d82u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c099d84;
P_0c099d84: /* original db11, guest PC 0x0c099d84 */
if(!s->budget--) { s->failed_pc=0x0c099d84u; return 0; }
r[11]=read(ram,0x0c099dccu,4);
goto P_0c099d86;
P_0c099d86: /* original 03be, guest PC 0x0c099d86 */
if(!s->budget--) { s->failed_pc=0x0c099d86u; return 0; }
r[3]=read(ram,r[11]+r[0],4);
goto P_0c099d88;
P_0c099d88: /* original 54b4, guest PC 0x0c099d88 */
if(!s->budget--) { s->failed_pc=0x0c099d88u; return 0; }
r[4]=read(ram,r[11]+16,4);
goto P_0c099d8a;
P_0c099d8a: /* original 6232, guest PC 0x0c099d8a */
if(!s->budget--) { s->failed_pc=0x0c099d8au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c099d8c;
P_0c099d8c: /* original 2268, guest PC 0x0c099d8c */
if(!s->budget--) { s->failed_pc=0x0c099d8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c099d8e;
P_0c099d8e: /* original 8d27, guest PC 0x0c099d8e */
if(!s->budget--) { s->failed_pc=0x0c099d8eu; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[11]+20,4);
if(cond) { goto P_0c099de0; }
goto P_0c099d92;
P_0c099d90: /* original 55b5, guest PC 0x0c099d90 */
if(!s->budget--) { s->failed_pc=0x0c099d90u; return 0; }
r[5]=read(ram,r[11]+20,4);
goto P_0c099d92;
P_0c099d92: /* original e054, guest PC 0x0c099d92 */
if(!s->budget--) { s->failed_pc=0x0c099d92u; return 0; }
r[0]=0x00000054u;
goto P_0c099d94;
P_0c099d94: /* original 054e, guest PC 0x0c099d94 */
if(!s->budget--) { s->failed_pc=0x0c099d94u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c099d96;
P_0c099d96: /* original e022, guest PC 0x0c099d96 */
if(!s->budget--) { s->failed_pc=0x0c099d96u; return 0; }
r[0]=0x00000022u;
goto P_0c099d98;
P_0c099d98: /* original 035d, guest PC 0x0c099d98 */
if(!s->budget--) { s->failed_pc=0x0c099d98u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c099d9a;
P_0c099d9a: /* original 9004, guest PC 0x0c099d9a */
if(!s->budget--) { s->failed_pc=0x0c099d9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099da6u,2);
goto P_0c099d9c;
P_0c099d9c: /* original a02b, guest PC 0x0c099d9c */
if(!s->budget--) { s->failed_pc=0x0c099d9cu; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c099df6;
P_0c099d9e: /* original 0435, guest PC 0x0c099d9e */
if(!s->budget--) { s->failed_pc=0x0c099d9eu; return 0; }
write(ram,r[4]+r[0],r[3],2);
return vf3_matrix_family(0x0c099da0u,s,ram);
P_0c099de0: /* original e064, guest PC 0x0c099de0 */
if(!s->budget--) { s->failed_pc=0x0c099de0u; return 0; }
r[0]=0x00000064u;
goto P_0c099de2;
P_0c099de2: /* original 01be, guest PC 0x0c099de2 */
if(!s->budget--) { s->failed_pc=0x0c099de2u; return 0; }
r[1]=read(ram,r[11]+r[0],4);
goto P_0c099de4;
P_0c099de4: /* original 6312, guest PC 0x0c099de4 */
if(!s->budget--) { s->failed_pc=0x0c099de4u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c099de6;
P_0c099de6: /* original 2638, guest PC 0x0c099de6 */
if(!s->budget--) { s->failed_pc=0x0c099de6u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c099de8;
P_0c099de8: /* original 8905, guest PC 0x0c099de8 */
if(!s->budget--) { s->failed_pc=0x0c099de8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099df6; }
goto P_0c099dea;
P_0c099dea: /* original e054, guest PC 0x0c099dea */
if(!s->budget--) { s->failed_pc=0x0c099deau; return 0; }
r[0]=0x00000054u;
goto P_0c099dec;
P_0c099dec: /* original 045e, guest PC 0x0c099dec */
if(!s->budget--) { s->failed_pc=0x0c099decu; return 0; }
r[4]=read(ram,r[5]+r[0],4);
goto P_0c099dee;
P_0c099dee: /* original e022, guest PC 0x0c099dee */
if(!s->budget--) { s->failed_pc=0x0c099deeu; return 0; }
r[0]=0x00000022u;
goto P_0c099df0;
P_0c099df0: /* original 034d, guest PC 0x0c099df0 */
if(!s->budget--) { s->failed_pc=0x0c099df0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c099df2;
P_0c099df2: /* original 9071, guest PC 0x0c099df2 */
if(!s->budget--) { s->failed_pc=0x0c099df2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ed8u,2);
goto P_0c099df4;
P_0c099df4: /* original 0535, guest PC 0x0c099df4 */
if(!s->budget--) { s->failed_pc=0x0c099df4u; return 0; }
write(ram,r[5]+r[0],r[3],2);
goto P_0c099df6;
P_0c099df6: /* original d33c, guest PC 0x0c099df6 */
if(!s->budget--) { s->failed_pc=0x0c099df6u; return 0; }
r[3]=read(ram,0x0c099ee8u,4);
goto P_0c099df8;
P_0c099df8: /* original e060, guest PC 0x0c099df8 */
if(!s->budget--) { s->failed_pc=0x0c099df8u; return 0; }
r[0]=0x00000060u;
goto P_0c099dfa;
P_0c099dfa: /* original 430b, guest PC 0x0c099dfa */
if(!s->budget--) { s->failed_pc=0x0c099dfau; return 0; }
target=r[3];
r[16]=code_base|0x0c099dfeu;
r[4]=read(ram,r[11]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099dfeu) { target=s->pc; goto dispatch; }
goto P_0c099dfe;
P_0c099dfc: /* original 04be, guest PC 0x0c099dfc */
if(!s->budget--) { s->failed_pc=0x0c099dfcu; return 0; }
r[4]=read(ram,r[11]+r[0],4);
goto P_0c099dfe;
P_0c099dfe: /* original d33a, guest PC 0x0c099dfe */
if(!s->budget--) { s->failed_pc=0x0c099dfeu; return 0; }
r[3]=read(ram,0x0c099ee8u,4);
goto P_0c099e00;
P_0c099e00: /* original e064, guest PC 0x0c099e00 */
if(!s->budget--) { s->failed_pc=0x0c099e00u; return 0; }
r[0]=0x00000064u;
goto P_0c099e02;
P_0c099e02: /* original 430b, guest PC 0x0c099e02 */
if(!s->budget--) { s->failed_pc=0x0c099e02u; return 0; }
target=r[3];
r[16]=code_base|0x0c099e06u;
r[4]=read(ram,r[11]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099e06u) { target=s->pc; goto dispatch; }
goto P_0c099e06;
P_0c099e04: /* original 04be, guest PC 0x0c099e04 */
if(!s->budget--) { s->failed_pc=0x0c099e04u; return 0; }
r[4]=read(ram,r[11]+r[0],4);
goto P_0c099e06;
P_0c099e06: /* original d338, guest PC 0x0c099e06 */
if(!s->budget--) { s->failed_pc=0x0c099e06u; return 0; }
r[3]=read(ram,0x0c099ee8u,4);
goto P_0c099e08;
P_0c099e08: /* original e068, guest PC 0x0c099e08 */
if(!s->budget--) { s->failed_pc=0x0c099e08u; return 0; }
r[0]=0x00000068u;
goto P_0c099e0a;
P_0c099e0a: /* original 430b, guest PC 0x0c099e0a */
if(!s->budget--) { s->failed_pc=0x0c099e0au; return 0; }
target=r[3];
r[16]=code_base|0x0c099e0eu;
r[4]=read(ram,r[11]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099e0eu) { target=s->pc; goto dispatch; }
goto P_0c099e0e;
P_0c099e0c: /* original 04be, guest PC 0x0c099e0c */
if(!s->budget--) { s->failed_pc=0x0c099e0cu; return 0; }
r[4]=read(ram,r[11]+r[0],4);
goto P_0c099e0e;
P_0c099e0e: /* original d336, guest PC 0x0c099e0e */
if(!s->budget--) { s->failed_pc=0x0c099e0eu; return 0; }
r[3]=read(ram,0x0c099ee8u,4);
goto P_0c099e10;
P_0c099e10: /* original e06c, guest PC 0x0c099e10 */
if(!s->budget--) { s->failed_pc=0x0c099e10u; return 0; }
r[0]=0x0000006cu;
goto P_0c099e12;
P_0c099e12: /* original 430b, guest PC 0x0c099e12 */
if(!s->budget--) { s->failed_pc=0x0c099e12u; return 0; }
target=r[3];
r[16]=code_base|0x0c099e16u;
r[4]=read(ram,r[11]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099e16u) { target=s->pc; goto dispatch; }
goto P_0c099e16;
P_0c099e14: /* original 04be, guest PC 0x0c099e14 */
if(!s->budget--) { s->failed_pc=0x0c099e14u; return 0; }
r[4]=read(ram,r[11]+r[0],4);
goto P_0c099e16;
P_0c099e16: /* original 59e2, guest PC 0x0c099e16 */
if(!s->budget--) { s->failed_pc=0x0c099e16u; return 0; }
r[9]=read(ram,r[14]+8,4);
goto P_0c099e18;
P_0c099e18: /* original e210, guest PC 0x0c099e18 */
if(!s->budget--) { s->failed_pc=0x0c099e18u; return 0; }
r[2]=0x00000010u;
goto P_0c099e1a;
P_0c099e1a: /* original 2298, guest PC 0x0c099e1a */
if(!s->budget--) { s->failed_pc=0x0c099e1au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[9])==0)!=0);
goto P_0c099e1c;
P_0c099e1c: /* original 8d02, guest PC 0x0c099e1c */
if(!s->budget--) { s->failed_pc=0x0c099e1cu; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(cond) { goto P_0c099e24; }
goto P_0c099e20;
P_0c099e1e: /* original ec00, guest PC 0x0c099e1e */
if(!s->budget--) { s->failed_pc=0x0c099e1eu; return 0; }
r[12]=0x00000000u;
goto P_0c099e20;
P_0c099e20: /* original a102, guest PC 0x0c099e20 */
if(!s->budget--) { s->failed_pc=0x0c099e20u; return 0; }
goto P_0c09a028;
P_0c099e22: /* original 0009, guest PC 0x0c099e22 */
if(!s->budget--) { s->failed_pc=0x0c099e22u; return 0; }
goto P_0c099e24;
P_0c099e24: /* original d331, guest PC 0x0c099e24 */
if(!s->budget--) { s->failed_pc=0x0c099e24u; return 0; }
r[3]=read(ram,0x0c099eecu,4);
goto P_0c099e26;
P_0c099e26: /* original 2398, guest PC 0x0c099e26 */
if(!s->budget--) { s->failed_pc=0x0c099e26u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c099e28;
P_0c099e28: /* original 8f02, guest PC 0x0c099e28 */
if(!s->budget--) { s->failed_pc=0x0c099e28u; return 0; }
cond=r[17]&1u;
r[8]=0x00000004u;
if(!cond) { goto P_0c099e30; }
goto P_0c099e2c;
P_0c099e2a: /* original e804, guest PC 0x0c099e2a */
if(!s->budget--) { s->failed_pc=0x0c099e2au; return 0; }
r[8]=0x00000004u;
goto P_0c099e2c;
P_0c099e2c: /* original a0dc, guest PC 0x0c099e2c */
if(!s->budget--) { s->failed_pc=0x0c099e2cu; return 0; }
goto P_0c099fe8;
P_0c099e2e: /* original 0009, guest PC 0x0c099e2e */
if(!s->budget--) { s->failed_pc=0x0c099e2eu; return 0; }
goto P_0c099e30;
P_0c099e30: /* original e029, guest PC 0x0c099e30 */
if(!s->budget--) { s->failed_pc=0x0c099e30u; return 0; }
r[0]=0x00000029u;
goto P_0c099e32;
P_0c099e32: /* original 0aec, guest PC 0x0c099e32 */
if(!s->budget--) { s->failed_pc=0x0c099e32u; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099e34;
P_0c099e34: /* original 60ac, guest PC 0x0c099e34 */
if(!s->budget--) { s->failed_pc=0x0c099e34u; return 0; }
r[0]=r[10]&255u;
goto P_0c099e36;
P_0c099e36: /* original 8803, guest PC 0x0c099e36 */
if(!s->budget--) { s->failed_pc=0x0c099e36u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c099e38;
P_0c099e38: /* original 8d2c, guest PC 0x0c099e38 */
if(!s->budget--) { s->failed_pc=0x0c099e38u; return 0; }
cond=r[17]&1u;
r[10]=r[0];
if(cond) { goto P_0c099e94; }
goto P_0c099e3c;
P_0c099e3a: /* original 6a03, guest PC 0x0c099e3a */
if(!s->budget--) { s->failed_pc=0x0c099e3au; return 0; }
r[10]=r[0];
goto P_0c099e3c;
P_0c099e3c: /* original 2aa8, guest PC 0x0c099e3c */
if(!s->budget--) { s->failed_pc=0x0c099e3cu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c099e3e;
P_0c099e3e: /* original 8b01, guest PC 0x0c099e3e */
if(!s->budget--) { s->failed_pc=0x0c099e3eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099e44; }
goto P_0c099e40;
P_0c099e40: /* original a0c2, guest PC 0x0c099e40 */
if(!s->budget--) { s->failed_pc=0x0c099e40u; return 0; }
goto P_0c099fc8;
P_0c099e42: /* original 0009, guest PC 0x0c099e42 */
if(!s->budget--) { s->failed_pc=0x0c099e42u; return 0; }
goto P_0c099e44;
P_0c099e44: /* original e02b, guest PC 0x0c099e44 */
if(!s->budget--) { s->failed_pc=0x0c099e44u; return 0; }
r[0]=0x0000002bu;
goto P_0c099e46;
P_0c099e46: /* original 00ec, guest PC 0x0c099e46 */
if(!s->budget--) { s->failed_pc=0x0c099e46u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099e48;
P_0c099e48: /* original 8809, guest PC 0x0c099e48 */
if(!s->budget--) { s->failed_pc=0x0c099e48u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c099e4a;
P_0c099e4a: /* original 8b01, guest PC 0x0c099e4a */
if(!s->budget--) { s->failed_pc=0x0c099e4au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099e50; }
goto P_0c099e4c;
P_0c099e4c: /* original a0ec, guest PC 0x0c099e4c */
if(!s->budget--) { s->failed_pc=0x0c099e4cu; return 0; }
goto P_0c09a028;
P_0c099e4e: /* original 0009, guest PC 0x0c099e4e */
if(!s->budget--) { s->failed_pc=0x0c099e4eu; return 0; }
goto P_0c099e50;
P_0c099e50: /* original e01d, guest PC 0x0c099e50 */
if(!s->budget--) { s->failed_pc=0x0c099e50u; return 0; }
r[0]=0x0000001du;
goto P_0c099e52;
P_0c099e52: /* original 04ec, guest PC 0x0c099e52 */
if(!s->budget--) { s->failed_pc=0x0c099e52u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099e54;
P_0c099e54: /* original 644c, guest PC 0x0c099e54 */
if(!s->budget--) { s->failed_pc=0x0c099e54u; return 0; }
r[4]=r[4]&255u;
goto P_0c099e56;
P_0c099e56: /* original 7401, guest PC 0x0c099e56 */
if(!s->budget--) { s->failed_pc=0x0c099e56u; return 0; }
r[4]+=0x00000001u;
goto P_0c099e58;
P_0c099e58: /* original 3a40, guest PC 0x0c099e58 */
if(!s->budget--) { s->failed_pc=0x0c099e58u; return 0; }
r[17]=(r[17]&~1u)|((r[10]==r[4])!=0);
goto P_0c099e5a;
P_0c099e5a: /* original 8901, guest PC 0x0c099e5a */
if(!s->budget--) { s->failed_pc=0x0c099e5au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099e60; }
goto P_0c099e5c;
P_0c099e5c: /* original a0b4, guest PC 0x0c099e5c */
if(!s->budget--) { s->failed_pc=0x0c099e5cu; return 0; }
goto P_0c099fc8;
P_0c099e5e: /* original 0009, guest PC 0x0c099e5e */
if(!s->budget--) { s->failed_pc=0x0c099e5eu; return 0; }
goto P_0c099e60;
P_0c099e60: /* original e02b, guest PC 0x0c099e60 */
if(!s->budget--) { s->failed_pc=0x0c099e60u; return 0; }
r[0]=0x0000002bu;
goto P_0c099e62;
P_0c099e62: /* original 923a, guest PC 0x0c099e62 */
if(!s->budget--) { s->failed_pc=0x0c099e62u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099edau,2);
goto P_0c099e64;
P_0c099e64: /* original 03ec, guest PC 0x0c099e64 */
if(!s->budget--) { s->failed_pc=0x0c099e64u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099e66;
P_0c099e66: /* original 706d, guest PC 0x0c099e66 */
if(!s->budget--) { s->failed_pc=0x0c099e66u; return 0; }
r[0]+=0x0000006du;
goto P_0c099e68;
P_0c099e68: /* original 01de, guest PC 0x0c099e68 */
if(!s->budget--) { s->failed_pc=0x0c099e68u; return 0; }
r[1]=read(ram,r[13]+r[0],4);
goto P_0c099e6a;
P_0c099e6a: /* original 32ec, guest PC 0x0c099e6a */
if(!s->budget--) { s->failed_pc=0x0c099e6au; return 0; }
r[2]+=r[14];
goto P_0c099e6c;
P_0c099e6c: /* original 73ff, guest PC 0x0c099e6c */
if(!s->budget--) { s->failed_pc=0x0c099e6cu; return 0; }
r[3]+=0xffffffffu;
goto P_0c099e6e;
P_0c099e6e: /* original 4308, guest PC 0x0c099e6e */
if(!s->budget--) { s->failed_pc=0x0c099e6eu; return 0; }
r[3]<<=2;
goto P_0c099e70;
P_0c099e70: /* original 332c, guest PC 0x0c099e70 */
if(!s->budget--) { s->failed_pc=0x0c099e70u; return 0; }
r[3]+=r[2];
goto P_0c099e72;
P_0c099e72: /* original 2312, guest PC 0x0c099e72 */
if(!s->budget--) { s->failed_pc=0x0c099e72u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c099e74;
P_0c099e74: /* original d31e, guest PC 0x0c099e74 */
if(!s->budget--) { s->failed_pc=0x0c099e74u; return 0; }
r[3]=read(ram,0x0c099ef0u,4);
goto P_0c099e76;
P_0c099e76: /* original 430b, guest PC 0x0c099e76 */
if(!s->budget--) { s->failed_pc=0x0c099e76u; return 0; }
target=r[3];
r[16]=code_base|0x0c099e7au;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099e7au) { target=s->pc; goto dispatch; }
goto P_0c099e7a;
P_0c099e78: /* original 0009, guest PC 0x0c099e78 */
if(!s->budget--) { s->failed_pc=0x0c099e78u; return 0; }
goto P_0c099e7a;
P_0c099e7a: /* original e02b, guest PC 0x0c099e7a */
if(!s->budget--) { s->failed_pc=0x0c099e7au; return 0; }
r[0]=0x0000002bu;
goto P_0c099e7c;
P_0c099e7c: /* original 02ec, guest PC 0x0c099e7c */
if(!s->budget--) { s->failed_pc=0x0c099e7cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099e7e;
P_0c099e7e: /* original 7201, guest PC 0x0c099e7e */
if(!s->budget--) { s->failed_pc=0x0c099e7eu; return 0; }
r[2]+=0x00000001u;
goto P_0c099e80;
P_0c099e80: /* original 0e24, guest PC 0x0c099e80 */
if(!s->budget--) { s->failed_pc=0x0c099e80u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c099e82;
P_0c099e82: /* original 54ed, guest PC 0x0c099e82 */
if(!s->budget--) { s->failed_pc=0x0c099e82u; return 0; }
r[4]=read(ram,r[14]+52,4);
goto P_0c099e84;
P_0c099e84: /* original 53ee, guest PC 0x0c099e84 */
if(!s->budget--) { s->failed_pc=0x0c099e84u; return 0; }
r[3]=read(ram,r[14]+56,4);
goto P_0c099e86;
P_0c099e86: /* original 343c, guest PC 0x0c099e86 */
if(!s->budget--) { s->failed_pc=0x0c099e86u; return 0; }
r[4]+=r[3];
goto P_0c099e88;
P_0c099e88: /* original 1e4c, guest PC 0x0c099e88 */
if(!s->budget--) { s->failed_pc=0x0c099e88u; return 0; }
write(ram,r[14]+48,r[4],4);
goto P_0c099e8a;
P_0c099e8a: /* original 1e4d, guest PC 0x0c099e8a */
if(!s->budget--) { s->failed_pc=0x0c099e8au; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c099e8c;
P_0c099e8c: /* original 1ece, guest PC 0x0c099e8c */
if(!s->budget--) { s->failed_pc=0x0c099e8cu; return 0; }
write(ram,r[14]+56,r[12],4);
goto P_0c099e8e;
P_0c099e8e: /* original 60c3, guest PC 0x0c099e8e */
if(!s->budget--) { s->failed_pc=0x0c099e8eu; return 0; }
r[0]=r[12];
goto P_0c099e90;
P_0c099e90: /* original a0ef, guest PC 0x0c099e90 */
if(!s->budget--) { s->failed_pc=0x0c099e90u; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c09a072;
P_0c099e92: /* original 80db, guest PC 0x0c099e92 */
if(!s->budget--) { s->failed_pc=0x0c099e92u; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c099e94;
P_0c099e94: /* original 9022, guest PC 0x0c099e94 */
if(!s->budget--) { s->failed_pc=0x0c099e94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099edcu,2);
goto P_0c099e96;
P_0c099e96: /* original 02dc, guest PC 0x0c099e96 */
if(!s->budget--) { s->failed_pc=0x0c099e96u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c099e98;
P_0c099e98: /* original 2228, guest PC 0x0c099e98 */
if(!s->budget--) { s->failed_pc=0x0c099e98u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c099e9a;
P_0c099e9a: /* original 8901, guest PC 0x0c099e9a */
if(!s->budget--) { s->failed_pc=0x0c099e9au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099ea0; }
goto P_0c099e9c;
P_0c099e9c: /* original a0d3, guest PC 0x0c099e9c */
if(!s->budget--) { s->failed_pc=0x0c099e9cu; return 0; }
goto P_0c09a046;
P_0c099e9e: /* original 0009, guest PC 0x0c099e9e */
if(!s->budget--) { s->failed_pc=0x0c099e9eu; return 0; }
goto P_0c099ea0;
P_0c099ea0: /* original 901d, guest PC 0x0c099ea0 */
if(!s->budget--) { s->failed_pc=0x0c099ea0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099edeu,2);
goto P_0c099ea2;
P_0c099ea2: /* original 02ec, guest PC 0x0c099ea2 */
if(!s->budget--) { s->failed_pc=0x0c099ea2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099ea4;
P_0c099ea4: /* original 901c, guest PC 0x0c099ea4 */
if(!s->budget--) { s->failed_pc=0x0c099ea4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ee0u,2);
goto P_0c099ea6;
P_0c099ea6: /* original 0e24, guest PC 0x0c099ea6 */
if(!s->budget--) { s->failed_pc=0x0c099ea6u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c099ea8;
P_0c099ea8: /* original d312, guest PC 0x0c099ea8 */
if(!s->budget--) { s->failed_pc=0x0c099ea8u; return 0; }
r[3]=read(ram,0x0c099ef4u,4);
goto P_0c099eaa;
P_0c099eaa: /* original 64f2, guest PC 0x0c099eaa */
if(!s->budget--) { s->failed_pc=0x0c099eaau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c099eac;
P_0c099eac: /* original 430b, guest PC 0x0c099eac */
if(!s->budget--) { s->failed_pc=0x0c099eacu; return 0; }
target=r[3];
r[16]=code_base|0x0c099eb0u;
r[4]+=0x00000013u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099eb0u) { target=s->pc; goto dispatch; }
goto P_0c099eb0;
P_0c099eae: /* original 7413, guest PC 0x0c099eae */
if(!s->budget--) { s->failed_pc=0x0c099eaeu; return 0; }
r[4]+=0x00000013u;
goto P_0c099eb0;
P_0c099eb0: /* original 640c, guest PC 0x0c099eb0 */
if(!s->budget--) { s->failed_pc=0x0c099eb0u; return 0; }
r[4]=r[0]&255u;
goto P_0c099eb2;
P_0c099eb2: /* original 2448, guest PC 0x0c099eb2 */
if(!s->budget--) { s->failed_pc=0x0c099eb2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c099eb4;
P_0c099eb4: /* original 8905, guest PC 0x0c099eb4 */
if(!s->budget--) { s->failed_pc=0x0c099eb4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099ec2; }
goto P_0c099eb6;
P_0c099eb6: /* original 9014, guest PC 0x0c099eb6 */
if(!s->budget--) { s->failed_pc=0x0c099eb6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ee2u,2);
goto P_0c099eb8;
P_0c099eb8: /* original 0aee, guest PC 0x0c099eb8 */
if(!s->budget--) { s->failed_pc=0x0c099eb8u; return 0; }
r[10]=read(ram,r[14]+r[0],4);
goto P_0c099eba;
P_0c099eba: /* original 3a43, guest PC 0x0c099eba */
if(!s->budget--) { s->failed_pc=0x0c099ebau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[4])!=0);
goto P_0c099ebc;
P_0c099ebc: /* original 8b01, guest PC 0x0c099ebc */
if(!s->budget--) { s->failed_pc=0x0c099ebcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099ec2; }
goto P_0c099ebe;
P_0c099ebe: /* original a0c2, guest PC 0x0c099ebe */
if(!s->budget--) { s->failed_pc=0x0c099ebeu; return 0; }
goto P_0c09a046;
P_0c099ec0: /* original 0009, guest PC 0x0c099ec0 */
if(!s->budget--) { s->failed_pc=0x0c099ec0u; return 0; }
goto P_0c099ec2;
P_0c099ec2: /* original 900f, guest PC 0x0c099ec2 */
if(!s->budget--) { s->failed_pc=0x0c099ec2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ee4u,2);
goto P_0c099ec4;
P_0c099ec4: /* original 00ec, guest PC 0x0c099ec4 */
if(!s->budget--) { s->failed_pc=0x0c099ec4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099ec6;
P_0c099ec6: /* original 8801, guest PC 0x0c099ec6 */
if(!s->budget--) { s->failed_pc=0x0c099ec6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c099ec8;
P_0c099ec8: /* original 891a, guest PC 0x0c099ec8 */
if(!s->budget--) { s->failed_pc=0x0c099ec8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099f00; }
goto P_0c099eca;
P_0c099eca: /* original d30b, guest PC 0x0c099eca */
if(!s->budget--) { s->failed_pc=0x0c099ecau; return 0; }
r[3]=read(ram,0x0c099ef8u,4);
goto P_0c099ecc;
P_0c099ecc: /* original 2398, guest PC 0x0c099ecc */
if(!s->budget--) { s->failed_pc=0x0c099eccu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c099ece;
P_0c099ece: /* original 8920, guest PC 0x0c099ece */
if(!s->budget--) { s->failed_pc=0x0c099eceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099f12; }
goto P_0c099ed0;
P_0c099ed0: /* original d20a, guest PC 0x0c099ed0 */
if(!s->budget--) { s->failed_pc=0x0c099ed0u; return 0; }
r[2]=read(ram,0x0c099efcu,4);
goto P_0c099ed2;
P_0c099ed2: /* original 2929, guest PC 0x0c099ed2 */
if(!s->budget--) { s->failed_pc=0x0c099ed2u; return 0; }
r[9]&=r[2];
goto P_0c099ed4;
P_0c099ed4: /* original a01a, guest PC 0x0c099ed4 */
if(!s->budget--) { s->failed_pc=0x0c099ed4u; return 0; }
r[10]+=0xffffffffu;
goto P_0c099f0c;
P_0c099ed6: /* original 7aff, guest PC 0x0c099ed6 */
if(!s->budget--) { s->failed_pc=0x0c099ed6u; return 0; }
r[10]+=0xffffffffu;
return vf3_matrix_family(0x0c099ed8u,s,ram);
P_0c099f00: /* original d242, guest PC 0x0c099f00 */
if(!s->budget--) { s->failed_pc=0x0c099f00u; return 0; }
r[2]=read(ram,0x0c09a00cu,4);
goto P_0c099f02;
P_0c099f02: /* original 2298, guest PC 0x0c099f02 */
if(!s->budget--) { s->failed_pc=0x0c099f02u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[9])==0)!=0);
goto P_0c099f04;
P_0c099f04: /* original 8905, guest PC 0x0c099f04 */
if(!s->budget--) { s->failed_pc=0x0c099f04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099f12; }
goto P_0c099f06;
P_0c099f06: /* original d342, guest PC 0x0c099f06 */
if(!s->budget--) { s->failed_pc=0x0c099f06u; return 0; }
r[3]=read(ram,0x0c09a010u,4);
goto P_0c099f08;
P_0c099f08: /* original 7afe, guest PC 0x0c099f08 */
if(!s->budget--) { s->failed_pc=0x0c099f08u; return 0; }
r[10]+=0xfffffffeu;
goto P_0c099f0a;
P_0c099f0a: /* original 2939, guest PC 0x0c099f0a */
if(!s->budget--) { s->failed_pc=0x0c099f0au; return 0; }
r[9]&=r[3];
goto P_0c099f0c;
P_0c099f0c: /* original 9075, guest PC 0x0c099f0c */
if(!s->budget--) { s->failed_pc=0x0c099f0cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ffau,2);
goto P_0c099f0e;
P_0c099f0e: /* original 0ea4, guest PC 0x0c099f0e */
if(!s->budget--) { s->failed_pc=0x0c099f0eu; return 0; }
write(ram,r[14]+r[0],r[10],1);
goto P_0c099f10;
P_0c099f10: /* original 1e92, guest PC 0x0c099f10 */
if(!s->budget--) { s->failed_pc=0x0c099f10u; return 0; }
write(ram,r[14]+8,r[9],4);
goto P_0c099f12;
P_0c099f12: /* original 9073, guest PC 0x0c099f12 */
if(!s->budget--) { s->failed_pc=0x0c099f12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ffcu,2);
goto P_0c099f14;
P_0c099f14: /* original 00ec, guest PC 0x0c099f14 */
if(!s->budget--) { s->failed_pc=0x0c099f14u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099f16;
P_0c099f16: /* original 8801, guest PC 0x0c099f16 */
if(!s->budget--) { s->failed_pc=0x0c099f16u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c099f18;
P_0c099f18: /* original 8905, guest PC 0x0c099f18 */
if(!s->budget--) { s->failed_pc=0x0c099f18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099f26; }
goto P_0c099f1a;
P_0c099f1a: /* original 9070, guest PC 0x0c099f1a */
if(!s->budget--) { s->failed_pc=0x0c099f1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ffeu,2);
goto P_0c099f1c;
P_0c099f1c: /* original 05ec, guest PC 0x0c099f1c */
if(!s->budget--) { s->failed_pc=0x0c099f1cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099f1e;
P_0c099f1e: /* original 7002, guest PC 0x0c099f1e */
if(!s->budget--) { s->failed_pc=0x0c099f1eu; return 0; }
r[0]+=0x00000002u;
goto P_0c099f20;
P_0c099f20: /* original 04ec, guest PC 0x0c099f20 */
if(!s->budget--) { s->failed_pc=0x0c099f20u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099f22;
P_0c099f22: /* original 3540, guest PC 0x0c099f22 */
if(!s->budget--) { s->failed_pc=0x0c099f22u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[4])!=0);
goto P_0c099f24;
P_0c099f24: /* original 8b5a, guest PC 0x0c099f24 */
if(!s->budget--) { s->failed_pc=0x0c099f24u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099fdc; }
goto P_0c099f26;
P_0c099f26: /* original 53e2, guest PC 0x0c099f26 */
if(!s->budget--) { s->failed_pc=0x0c099f26u; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c099f28;
P_0c099f28: /* original d73a, guest PC 0x0c099f28 */
if(!s->budget--) { s->failed_pc=0x0c099f28u; return 0; }
r[7]=read(ram,0x0c09a014u,4);
goto P_0c099f2a;
P_0c099f2a: /* original 9069, guest PC 0x0c099f2a */
if(!s->budget--) { s->failed_pc=0x0c099f2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a000u,2);
goto P_0c099f2c;
P_0c099f2c: /* original 2838, guest PC 0x0c099f2c */
if(!s->budget--) { s->failed_pc=0x0c099f2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[3])==0)!=0);
goto P_0c099f2e;
P_0c099f2e: /* original 8d2b, guest PC 0x0c099f2e */
if(!s->budget--) { s->failed_pc=0x0c099f2eu; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[13]+r[0],4);
if(cond) { goto P_0c099f88; }
goto P_0c099f32;
P_0c099f30: /* original 04de, guest PC 0x0c099f30 */
if(!s->budget--) { s->failed_pc=0x0c099f30u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099f32;
P_0c099f32: /* original e02a, guest PC 0x0c099f32 */
if(!s->budget--) { s->failed_pc=0x0c099f32u; return 0; }
r[0]=0x0000002au;
goto P_0c099f34;
P_0c099f34: /* original 00ec, guest PC 0x0c099f34 */
if(!s->budget--) { s->failed_pc=0x0c099f34u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099f36;
P_0c099f36: /* original 600c, guest PC 0x0c099f36 */
if(!s->budget--) { s->failed_pc=0x0c099f36u; return 0; }
r[0]=r[0]&255u;
goto P_0c099f38;
P_0c099f38: /* original 8802, guest PC 0x0c099f38 */
if(!s->budget--) { s->failed_pc=0x0c099f38u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c099f3a;
P_0c099f3a: /* original 8b02, guest PC 0x0c099f3a */
if(!s->budget--) { s->failed_pc=0x0c099f3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099f42; }
goto P_0c099f3c;
P_0c099f3c: /* original 9b61, guest PC 0x0c099f3c */
if(!s->budget--) { s->failed_pc=0x0c099f3cu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a002u,2);
goto P_0c099f3e;
P_0c099f3e: /* original a001, guest PC 0x0c099f3e */
if(!s->budget--) { s->failed_pc=0x0c099f3eu; return 0; }
goto P_0c099f44;
P_0c099f40: /* original 0009, guest PC 0x0c099f40 */
if(!s->budget--) { s->failed_pc=0x0c099f40u; return 0; }
goto P_0c099f42;
P_0c099f42: /* original 9b5f, guest PC 0x0c099f42 */
if(!s->budget--) { s->failed_pc=0x0c099f42u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a004u,2);
goto P_0c099f44;
P_0c099f44: /* original 66c3, guest PC 0x0c099f44 */
if(!s->budget--) { s->failed_pc=0x0c099f44u; return 0; }
r[6]=r[12];
goto P_0c099f46;
P_0c099f46: /* original 3bec, guest PC 0x0c099f46 */
if(!s->budget--) { s->failed_pc=0x0c099f46u; return 0; }
r[11]+=r[14];
goto P_0c099f48;
P_0c099f48: /* original 6063, guest PC 0x0c099f48 */
if(!s->budget--) { s->failed_pc=0x0c099f48u; return 0; }
r[0]=r[6];
goto P_0c099f4a;
P_0c099f4a: /* original 05bc, guest PC 0x0c099f4a */
if(!s->budget--) { s->failed_pc=0x0c099f4au; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c099f4c;
P_0c099f4c: /* original e30d, guest PC 0x0c099f4c */
if(!s->budget--) { s->failed_pc=0x0c099f4cu; return 0; }
r[3]=0x0000000du;
goto P_0c099f4e;
P_0c099f4e: /* original 655c, guest PC 0x0c099f4e */
if(!s->budget--) { s->failed_pc=0x0c099f4eu; return 0; }
r[5]=r[5]&255u;
goto P_0c099f50;
P_0c099f50: /* original 3533, guest PC 0x0c099f50 */
if(!s->budget--) { s->failed_pc=0x0c099f50u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[3])!=0);
goto P_0c099f52;
P_0c099f52: /* original 8b00, guest PC 0x0c099f52 */
if(!s->budget--) { s->failed_pc=0x0c099f52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099f56; }
goto P_0c099f54;
P_0c099f54: /* original 75f3, guest PC 0x0c099f54 */
if(!s->budget--) { s->failed_pc=0x0c099f54u; return 0; }
r[5]+=0xfffffff3u;
goto P_0c099f56;
P_0c099f56: /* original 9a56, guest PC 0x0c099f56 */
if(!s->budget--) { s->failed_pc=0x0c099f56u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a006u,2);
goto P_0c099f58;
P_0c099f58: /* original 3aec, guest PC 0x0c099f58 */
if(!s->budget--) { s->failed_pc=0x0c099f58u; return 0; }
r[10]+=r[14];
goto P_0c099f5a;
P_0c099f5a: /* original 3a5c, guest PC 0x0c099f5a */
if(!s->budget--) { s->failed_pc=0x0c099f5au; return 0; }
r[10]+=r[5];
goto P_0c099f5c;
P_0c099f5c: /* original 2fa2, guest PC 0x0c099f5c */
if(!s->budget--) { s->failed_pc=0x0c099f5cu; return 0; }
write(ram,r[15],r[10],4);
goto P_0c099f5e;
P_0c099f5e: /* original 6aa0, guest PC 0x0c099f5e */
if(!s->budget--) { s->failed_pc=0x0c099f5eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[10],1);
r[10]=tmp;
goto P_0c099f60;
P_0c099f60: /* original 63f2, guest PC 0x0c099f60 */
if(!s->budget--) { s->failed_pc=0x0c099f60u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c099f62;
P_0c099f62: /* original 7aff, guest PC 0x0c099f62 */
if(!s->budget--) { s->failed_pc=0x0c099f62u; return 0; }
r[10]+=0xffffffffu;
goto P_0c099f64;
P_0c099f64: /* original 23a0, guest PC 0x0c099f64 */
if(!s->budget--) { s->failed_pc=0x0c099f64u; return 0; }
write(ram,r[3],r[10],1);
goto P_0c099f66;
P_0c099f66: /* original 6aae, guest PC 0x0c099f66 */
if(!s->budget--) { s->failed_pc=0x0c099f66u; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)r[10];
goto P_0c099f68;
P_0c099f68: /* original 4a15, guest PC 0x0c099f68 */
if(!s->budget--) { s->failed_pc=0x0c099f68u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>0)!=0);
goto P_0c099f6a;
P_0c099f6a: /* original 8d07, guest PC 0x0c099f6a */
if(!s->budget--) { s->failed_pc=0x0c099f6au; return 0; }
cond=r[17]&1u;
r[6]+=0x00000001u;
if(cond) { goto P_0c099f7c; }
goto P_0c099f6e;
P_0c099f6c: /* original 7601, guest PC 0x0c099f6c */
if(!s->budget--) { s->failed_pc=0x0c099f6cu; return 0; }
r[6]+=0x00000001u;
goto P_0c099f6e;
P_0c099f6e: /* original 655b, guest PC 0x0c099f6e */
if(!s->budget--) { s->failed_pc=0x0c099f6eu; return 0; }
r[5]=0u-r[5];
goto P_0c099f70;
P_0c099f70: /* original 6a73, guest PC 0x0c099f70 */
if(!s->budget--) { s->failed_pc=0x0c099f70u; return 0; }
r[10]=r[7];
goto P_0c099f72;
P_0c099f72: /* original 4a5d, guest PC 0x0c099f72 */
if(!s->budget--) { s->failed_pc=0x0c099f72u; return 0; }
r[10]=(r[5]&0x80000000u)?((r[5]&31u)?r[10]>>((-r[5])&31u):0):r[10]<<(r[5]&31u);
goto P_0c099f74;
P_0c099f74: /* original 9044, guest PC 0x0c099f74 */
if(!s->budget--) { s->failed_pc=0x0c099f74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a000u,2);
goto P_0c099f76;
P_0c099f76: /* original 6aa7, guest PC 0x0c099f76 */
if(!s->budget--) { s->failed_pc=0x0c099f76u; return 0; }
r[10]=~r[10];
goto P_0c099f78;
P_0c099f78: /* original 24a9, guest PC 0x0c099f78 */
if(!s->budget--) { s->failed_pc=0x0c099f78u; return 0; }
r[4]&=r[10];
goto P_0c099f7a;
P_0c099f7a: /* original 0d46, guest PC 0x0c099f7a */
if(!s->budget--) { s->failed_pc=0x0c099f7au; return 0; }
write(ram,r[13]+r[0],r[4],4);
goto P_0c099f7c;
P_0c099f7c: /* original 9044, guest PC 0x0c099f7c */
if(!s->budget--) { s->failed_pc=0x0c099f7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a008u,2);
goto P_0c099f7e;
P_0c099f7e: /* original 03ec, guest PC 0x0c099f7e */
if(!s->budget--) { s->failed_pc=0x0c099f7eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099f80;
P_0c099f80: /* original 3633, guest PC 0x0c099f80 */
if(!s->budget--) { s->failed_pc=0x0c099f80u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[3])!=0);
goto P_0c099f82;
P_0c099f82: /* original 8be1, guest PC 0x0c099f82 */
if(!s->budget--) { s->failed_pc=0x0c099f82u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099f48; }
goto P_0c099f84;
P_0c099f84: /* original af83, guest PC 0x0c099f84 */
if(!s->budget--) { s->failed_pc=0x0c099f84u; return 0; }
goto P_0c099e8e;
P_0c099f86: /* original 0009, guest PC 0x0c099f86 */
if(!s->budget--) { s->failed_pc=0x0c099f86u; return 0; }
goto P_0c099f88;
P_0c099f88: /* original e02a, guest PC 0x0c099f88 */
if(!s->budget--) { s->failed_pc=0x0c099f88u; return 0; }
r[0]=0x0000002au;
goto P_0c099f8a;
P_0c099f8a: /* original 00ec, guest PC 0x0c099f8a */
if(!s->budget--) { s->failed_pc=0x0c099f8au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099f8c;
P_0c099f8c: /* original 600c, guest PC 0x0c099f8c */
if(!s->budget--) { s->failed_pc=0x0c099f8cu; return 0; }
r[0]=r[0]&255u;
goto P_0c099f8e;
P_0c099f8e: /* original 8802, guest PC 0x0c099f8e */
if(!s->budget--) { s->failed_pc=0x0c099f8eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c099f90;
P_0c099f90: /* original 8f02, guest PC 0x0c099f90 */
if(!s->budget--) { s->failed_pc=0x0c099f90u; return 0; }
cond=r[17]&1u;
r[0]=0x00000061u;
if(!cond) { goto P_0c099f98; }
goto P_0c099f94;
P_0c099f92: /* original e061, guest PC 0x0c099f92 */
if(!s->budget--) { s->failed_pc=0x0c099f92u; return 0; }
r[0]=0x00000061u;
goto P_0c099f94;
P_0c099f94: /* original a001, guest PC 0x0c099f94 */
if(!s->budget--) { s->failed_pc=0x0c099f94u; return 0; }
r[5]=read(ram,r[11]+16,4);
goto P_0c099f9a;
P_0c099f96: /* original 55b4, guest PC 0x0c099f96 */
if(!s->budget--) { s->failed_pc=0x0c099f96u; return 0; }
r[5]=read(ram,r[11]+16,4);
goto P_0c099f98;
P_0c099f98: /* original 55b5, guest PC 0x0c099f98 */
if(!s->budget--) { s->failed_pc=0x0c099f98u; return 0; }
r[5]=read(ram,r[11]+20,4);
goto P_0c099f9a;
P_0c099f9a: /* original 065c, guest PC 0x0c099f9a */
if(!s->budget--) { s->failed_pc=0x0c099f9au; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c099f9c;
P_0c099f9c: /* original 9533, guest PC 0x0c099f9c */
if(!s->budget--) { s->failed_pc=0x0c099f9cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a006u,2);
goto P_0c099f9e;
P_0c099f9e: /* original 666c, guest PC 0x0c099f9e */
if(!s->budget--) { s->failed_pc=0x0c099f9eu; return 0; }
r[6]=r[6]&255u;
goto P_0c099fa0;
P_0c099fa0: /* original 35ec, guest PC 0x0c099fa0 */
if(!s->budget--) { s->failed_pc=0x0c099fa0u; return 0; }
r[5]+=r[14];
goto P_0c099fa2;
P_0c099fa2: /* original 356c, guest PC 0x0c099fa2 */
if(!s->budget--) { s->failed_pc=0x0c099fa2u; return 0; }
r[5]+=r[6];
goto P_0c099fa4;
P_0c099fa4: /* original 2f52, guest PC 0x0c099fa4 */
if(!s->budget--) { s->failed_pc=0x0c099fa4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c099fa6;
P_0c099fa6: /* original 6550, guest PC 0x0c099fa6 */
if(!s->budget--) { s->failed_pc=0x0c099fa6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c099fa8;
P_0c099fa8: /* original 63f2, guest PC 0x0c099fa8 */
if(!s->budget--) { s->failed_pc=0x0c099fa8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c099faa;
P_0c099faa: /* original 75ff, guest PC 0x0c099faa */
if(!s->budget--) { s->failed_pc=0x0c099faau; return 0; }
r[5]+=0xffffffffu;
goto P_0c099fac;
P_0c099fac: /* original 2350, guest PC 0x0c099fac */
if(!s->budget--) { s->failed_pc=0x0c099facu; return 0; }
write(ram,r[3],r[5],1);
goto P_0c099fae;
P_0c099fae: /* original 655e, guest PC 0x0c099fae */
if(!s->budget--) { s->failed_pc=0x0c099faeu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c099fb0;
P_0c099fb0: /* original 2558, guest PC 0x0c099fb0 */
if(!s->budget--) { s->failed_pc=0x0c099fb0u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c099fb2;
P_0c099fb2: /* original 8901, guest PC 0x0c099fb2 */
if(!s->budget--) { s->failed_pc=0x0c099fb2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099fb8; }
goto P_0c099fb4;
P_0c099fb4: /* original af6b, guest PC 0x0c099fb4 */
if(!s->budget--) { s->failed_pc=0x0c099fb4u; return 0; }
goto P_0c099e8e;
P_0c099fb6: /* original 0009, guest PC 0x0c099fb6 */
if(!s->budget--) { s->failed_pc=0x0c099fb6u; return 0; }
goto P_0c099fb8;
P_0c099fb8: /* original 666b, guest PC 0x0c099fb8 */
if(!s->budget--) { s->failed_pc=0x0c099fb8u; return 0; }
r[6]=0u-r[6];
goto P_0c099fba;
P_0c099fba: /* original 6573, guest PC 0x0c099fba */
if(!s->budget--) { s->failed_pc=0x0c099fbau; return 0; }
r[5]=r[7];
goto P_0c099fbc;
P_0c099fbc: /* original 456d, guest PC 0x0c099fbc */
if(!s->budget--) { s->failed_pc=0x0c099fbcu; return 0; }
r[5]=(r[6]&0x80000000u)?((r[6]&31u)?r[5]>>((-r[6])&31u):0):r[5]<<(r[6]&31u);
goto P_0c099fbe;
P_0c099fbe: /* original 901f, guest PC 0x0c099fbe */
if(!s->budget--) { s->failed_pc=0x0c099fbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a000u,2);
goto P_0c099fc0;
P_0c099fc0: /* original 6557, guest PC 0x0c099fc0 */
if(!s->budget--) { s->failed_pc=0x0c099fc0u; return 0; }
r[5]=~r[5];
goto P_0c099fc2;
P_0c099fc2: /* original 2459, guest PC 0x0c099fc2 */
if(!s->budget--) { s->failed_pc=0x0c099fc2u; return 0; }
r[4]&=r[5];
goto P_0c099fc4;
P_0c099fc4: /* original af63, guest PC 0x0c099fc4 */
if(!s->budget--) { s->failed_pc=0x0c099fc4u; return 0; }
write(ram,r[13]+r[0],r[4],4);
goto P_0c099e8e;
P_0c099fc6: /* original 0d46, guest PC 0x0c099fc6 */
if(!s->budget--) { s->failed_pc=0x0c099fc6u; return 0; }
write(ram,r[13]+r[0],r[4],4);
goto P_0c099fc8;
P_0c099fc8: /* original 54ed, guest PC 0x0c099fc8 */
if(!s->budget--) { s->failed_pc=0x0c099fc8u; return 0; }
r[4]=read(ram,r[14]+52,4);
goto P_0c099fca;
P_0c099fca: /* original 52ee, guest PC 0x0c099fca */
if(!s->budget--) { s->failed_pc=0x0c099fcau; return 0; }
r[2]=read(ram,r[14]+56,4);
goto P_0c099fcc;
P_0c099fcc: /* original 342c, guest PC 0x0c099fcc */
if(!s->budget--) { s->failed_pc=0x0c099fccu; return 0; }
r[4]+=r[2];
goto P_0c099fce;
P_0c099fce: /* original 1e4c, guest PC 0x0c099fce */
if(!s->budget--) { s->failed_pc=0x0c099fceu; return 0; }
write(ram,r[14]+48,r[4],4);
goto P_0c099fd0;
P_0c099fd0: /* original 1e4d, guest PC 0x0c099fd0 */
if(!s->budget--) { s->failed_pc=0x0c099fd0u; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c099fd2;
P_0c099fd2: /* original 1ece, guest PC 0x0c099fd2 */
if(!s->budget--) { s->failed_pc=0x0c099fd2u; return 0; }
write(ram,r[14]+56,r[12],4);
goto P_0c099fd4;
P_0c099fd4: /* original 9011, guest PC 0x0c099fd4 */
if(!s->budget--) { s->failed_pc=0x0c099fd4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099ffau,2);
goto P_0c099fd6;
P_0c099fd6: /* original 03ec, guest PC 0x0c099fd6 */
if(!s->budget--) { s->failed_pc=0x0c099fd6u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099fd8;
P_0c099fd8: /* original 9017, guest PC 0x0c099fd8 */
if(!s->budget--) { s->failed_pc=0x0c099fd8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a00au,2);
goto P_0c099fda;
P_0c099fda: /* original 0e34, guest PC 0x0c099fda */
if(!s->budget--) { s->failed_pc=0x0c099fdau; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c099fdc;
P_0c099fdc: /* original d20e, guest PC 0x0c099fdc */
if(!s->budget--) { s->failed_pc=0x0c099fdcu; return 0; }
r[2]=read(ram,0x0c09a018u,4);
goto P_0c099fde;
P_0c099fde: /* original 420b, guest PC 0x0c099fde */
if(!s->budget--) { s->failed_pc=0x0c099fdeu; return 0; }
target=r[2];
r[16]=code_base|0x0c099fe2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099fe2u) { target=s->pc; goto dispatch; }
goto P_0c099fe2;
P_0c099fe0: /* original 0009, guest PC 0x0c099fe0 */
if(!s->budget--) { s->failed_pc=0x0c099fe0u; return 0; }
goto P_0c099fe2;
P_0c099fe2: /* original e008, guest PC 0x0c099fe2 */
if(!s->budget--) { s->failed_pc=0x0c099fe2u; return 0; }
r[0]=0x00000008u;
goto P_0c099fe4;
P_0c099fe4: /* original a045, guest PC 0x0c099fe4 */
if(!s->budget--) { s->failed_pc=0x0c099fe4u; return 0; }
write(ram,r[13]+10,r[0],1);
goto P_0c09a072;
P_0c099fe6: /* original 80da, guest PC 0x0c099fe6 */
if(!s->budget--) { s->failed_pc=0x0c099fe6u; return 0; }
write(ram,r[13]+10,r[0],1);
goto P_0c099fe8;
P_0c099fe8: /* original e01c, guest PC 0x0c099fe8 */
if(!s->budget--) { s->failed_pc=0x0c099fe8u; return 0; }
r[0]=0x0000001cu;
goto P_0c099fea;
P_0c099fea: /* original 03ec, guest PC 0x0c099fea */
if(!s->budget--) { s->failed_pc=0x0c099feau; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099fec;
P_0c099fec: /* original 7301, guest PC 0x0c099fec */
if(!s->budget--) { s->failed_pc=0x0c099fecu; return 0; }
r[3]+=0x00000001u;
goto P_0c099fee;
P_0c099fee: /* original 0e34, guest PC 0x0c099fee */
if(!s->budget--) { s->failed_pc=0x0c099feeu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c099ff0;
P_0c099ff0: /* original 52e2, guest PC 0x0c099ff0 */
if(!s->budget--) { s->failed_pc=0x0c099ff0u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c099ff2;
P_0c099ff2: /* original 2288, guest PC 0x0c099ff2 */
if(!s->budget--) { s->failed_pc=0x0c099ff2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[8])==0)!=0);
goto P_0c099ff4;
P_0c099ff4: /* original 8912, guest PC 0x0c099ff4 */
if(!s->budget--) { s->failed_pc=0x0c099ff4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09a01c; }
goto P_0c099ff6;
P_0c099ff6: /* original a012, guest PC 0x0c099ff6 */
if(!s->budget--) { s->failed_pc=0x0c099ff6u; return 0; }
r[0]=0x00000011u;
goto P_0c09a01e;
P_0c099ff8: /* original e011, guest PC 0x0c099ff8 */
if(!s->budget--) { s->failed_pc=0x0c099ff8u; return 0; }
r[0]=0x00000011u;
return vf3_matrix_family(0x0c099ffau,s,ram);
P_0c09a01c: /* original 6083, guest PC 0x0c09a01c */
if(!s->budget--) { s->failed_pc=0x0c09a01cu; return 0; }
r[0]=r[8];
goto P_0c09a01e;
P_0c09a01e: /* original d345, guest PC 0x0c09a01e */
if(!s->budget--) { s->failed_pc=0x0c09a01eu; return 0; }
r[3]=read(ram,0x0c09a134u,4);
goto P_0c09a020;
P_0c09a020: /* original 430b, guest PC 0x0c09a020 */
if(!s->budget--) { s->failed_pc=0x0c09a020u; return 0; }
target=r[3];
r[16]=code_base|0x0c09a024u;
write(ram,r[13]+11,r[0],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a024u) { target=s->pc; goto dispatch; }
goto P_0c09a024;
P_0c09a022: /* original 80db, guest PC 0x0c09a022 */
if(!s->budget--) { s->failed_pc=0x0c09a022u; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c09a024;
P_0c09a024: /* original a025, guest PC 0x0c09a024 */
if(!s->budget--) { s->failed_pc=0x0c09a024u; return 0; }
goto P_0c09a072;
P_0c09a026: /* original 0009, guest PC 0x0c09a026 */
if(!s->budget--) { s->failed_pc=0x0c09a026u; return 0; }
goto P_0c09a028;
P_0c09a028: /* original e00c, guest PC 0x0c09a028 */
if(!s->budget--) { s->failed_pc=0x0c09a028u; return 0; }
r[0]=0x0000000cu;
goto P_0c09a02a;
P_0c09a02a: /* original e500, guest PC 0x0c09a02a */
if(!s->budget--) { s->failed_pc=0x0c09a02au; return 0; }
r[5]=0x00000000u;
goto P_0c09a02c;
P_0c09a02c: /* original 80da, guest PC 0x0c09a02c */
if(!s->budget--) { s->failed_pc=0x0c09a02cu; return 0; }
write(ram,r[13]+10,r[0],1);
goto P_0c09a02e;
P_0c09a02e: /* original 2fc6, guest PC 0x0c09a02e */
if(!s->budget--) { s->failed_pc=0x0c09a02eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09a030;
P_0c09a030: /* original e731, guest PC 0x0c09a030 */
if(!s->budget--) { s->failed_pc=0x0c09a030u; return 0; }
r[7]=0x00000031u;
goto P_0c09a032;
P_0c09a032: /* original 54f2, guest PC 0x0c09a032 */
if(!s->budget--) { s->failed_pc=0x0c09a032u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c09a034;
P_0c09a034: /* original e63f, guest PC 0x0c09a034 */
if(!s->budget--) { s->failed_pc=0x0c09a034u; return 0; }
r[6]=0x0000003fu;
goto P_0c09a036;
P_0c09a036: /* original d340, guest PC 0x0c09a036 */
if(!s->budget--) { s->failed_pc=0x0c09a036u; return 0; }
r[3]=read(ram,0x0c09a138u,4);
goto P_0c09a038;
P_0c09a038: /* original 430b, guest PC 0x0c09a038 */
if(!s->budget--) { s->failed_pc=0x0c09a038u; return 0; }
target=r[3];
r[16]=code_base|0x0c09a03cu;
r[4]+=0x0000002cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a03cu) { target=s->pc; goto dispatch; }
goto P_0c09a03c;
P_0c09a03a: /* original 742c, guest PC 0x0c09a03a */
if(!s->budget--) { s->failed_pc=0x0c09a03au; return 0; }
r[4]+=0x0000002cu;
goto P_0c09a03c;
P_0c09a03c: /* original d23f, guest PC 0x0c09a03c */
if(!s->budget--) { s->failed_pc=0x0c09a03cu; return 0; }
r[2]=read(ram,0x0c09a13cu,4);
goto P_0c09a03e;
P_0c09a03e: /* original 420b, guest PC 0x0c09a03e */
if(!s->budget--) { s->failed_pc=0x0c09a03eu; return 0; }
target=r[2];
r[16]=code_base|0x0c09a042u;
r[15]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a042u) { target=s->pc; goto dispatch; }
goto P_0c09a042;
P_0c09a040: /* original 7f04, guest PC 0x0c09a040 */
if(!s->budget--) { s->failed_pc=0x0c09a040u; return 0; }
r[15]+=0x00000004u;
goto P_0c09a042;
P_0c09a042: /* original a016, guest PC 0x0c09a042 */
if(!s->budget--) { s->failed_pc=0x0c09a042u; return 0; }
goto P_0c09a072;
P_0c09a044: /* original 0009, guest PC 0x0c09a044 */
if(!s->budget--) { s->failed_pc=0x0c09a044u; return 0; }
goto P_0c09a046;
P_0c09a046: /* original 9071, guest PC 0x0c09a046 */
if(!s->budget--) { s->failed_pc=0x0c09a046u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a12cu,2);
goto P_0c09a048;
P_0c09a048: /* original 03dc, guest PC 0x0c09a048 */
if(!s->budget--) { s->failed_pc=0x0c09a048u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c09a04a;
P_0c09a04a: /* original 2338, guest PC 0x0c09a04a */
if(!s->budget--) { s->failed_pc=0x0c09a04au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09a04c;
P_0c09a04c: /* original 890f, guest PC 0x0c09a04c */
if(!s->budget--) { s->failed_pc=0x0c09a04cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09a06e; }
goto P_0c09a04e;
P_0c09a04e: /* original 6083, guest PC 0x0c09a04e */
if(!s->budget--) { s->failed_pc=0x0c09a04eu; return 0; }
r[0]=r[8];
goto P_0c09a050;
P_0c09a050: /* original 80da, guest PC 0x0c09a050 */
if(!s->budget--) { s->failed_pc=0x0c09a050u; return 0; }
write(ram,r[13]+10,r[0],1);
goto P_0c09a052;
P_0c09a052: /* original 906c, guest PC 0x0c09a052 */
if(!s->budget--) { s->failed_pc=0x0c09a052u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a12eu,2);
goto P_0c09a054;
P_0c09a054: /* original 0dc6, guest PC 0x0c09a054 */
if(!s->budget--) { s->failed_pc=0x0c09a054u; return 0; }
write(ram,r[13]+r[0],r[12],4);
goto P_0c09a056;
P_0c09a056: /* original 60c3, guest PC 0x0c09a056 */
if(!s->budget--) { s->failed_pc=0x0c09a056u; return 0; }
r[0]=r[12];
goto P_0c09a058;
P_0c09a058: /* original d439, guest PC 0x0c09a058 */
if(!s->budget--) { s->failed_pc=0x0c09a058u; return 0; }
r[4]=read(ram,0x0c09a140u,4);
goto P_0c09a05a;
P_0c09a05a: /* original 24c0, guest PC 0x0c09a05a */
if(!s->budget--) { s->failed_pc=0x0c09a05au; return 0; }
write(ram,r[4],r[12],1);
goto P_0c09a05c;
P_0c09a05c: /* original 8041, guest PC 0x0c09a05c */
if(!s->budget--) { s->failed_pc=0x0c09a05cu; return 0; }
write(ram,r[4]+1,r[0],1);
goto P_0c09a05e;
P_0c09a05e: /* original 54bb, guest PC 0x0c09a05e */
if(!s->budget--) { s->failed_pc=0x0c09a05eu; return 0; }
r[4]=read(ram,r[11]+44,4);
goto P_0c09a060;
P_0c09a060: /* original 55ba, guest PC 0x0c09a060 */
if(!s->budget--) { s->failed_pc=0x0c09a060u; return 0; }
r[5]=read(ram,r[11]+40,4);
goto P_0c09a062;
P_0c09a062: /* original 2502, guest PC 0x0c09a062 */
if(!s->budget--) { s->failed_pc=0x0c09a062u; return 0; }
write(ram,r[5],r[0],4);
goto P_0c09a064;
P_0c09a064: /* original 2402, guest PC 0x0c09a064 */
if(!s->budget--) { s->failed_pc=0x0c09a064u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c09a066;
P_0c09a066: /* original e06c, guest PC 0x0c09a066 */
if(!s->budget--) { s->failed_pc=0x0c09a066u; return 0; }
r[0]=0x0000006cu;
goto P_0c09a068;
P_0c09a068: /* original 05c6, guest PC 0x0c09a068 */
if(!s->budget--) { s->failed_pc=0x0c09a068u; return 0; }
write(ram,r[5]+r[0],r[12],4);
goto P_0c09a06a;
P_0c09a06a: /* original a002, guest PC 0x0c09a06a */
if(!s->budget--) { s->failed_pc=0x0c09a06au; return 0; }
write(ram,r[4]+r[0],r[12],4);
goto P_0c09a072;
P_0c09a06c: /* original 04c6, guest PC 0x0c09a06c */
if(!s->budget--) { s->failed_pc=0x0c09a06cu; return 0; }
write(ram,r[4]+r[0],r[12],4);
goto P_0c09a06e;
P_0c09a06e: /* original e012, guest PC 0x0c09a06e */
if(!s->budget--) { s->failed_pc=0x0c09a06eu; return 0; }
r[0]=0x00000012u;
goto P_0c09a070;
P_0c09a070: /* original 80da, guest PC 0x0c09a070 */
if(!s->budget--) { s->failed_pc=0x0c09a070u; return 0; }
write(ram,r[13]+10,r[0],1);
goto P_0c09a072;
P_0c09a072: /* original 7f08, guest PC 0x0c09a072 */
if(!s->budget--) { s->failed_pc=0x0c09a072u; return 0; }
r[15]+=0x00000008u;
goto P_0c09a074;
P_0c09a074: /* original 4f26, guest PC 0x0c09a074 */
if(!s->budget--) { s->failed_pc=0x0c09a074u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09a076;
P_0c09a076: /* original 68f6, guest PC 0x0c09a076 */
if(!s->budget--) { s->failed_pc=0x0c09a076u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09a078;
P_0c09a078: /* original 69f6, guest PC 0x0c09a078 */
if(!s->budget--) { s->failed_pc=0x0c09a078u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09a07a;
P_0c09a07a: /* original 6af6, guest PC 0x0c09a07a */
if(!s->budget--) { s->failed_pc=0x0c09a07au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09a07c;
P_0c09a07c: /* original 6bf6, guest PC 0x0c09a07c */
if(!s->budget--) { s->failed_pc=0x0c09a07cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09a07e;
P_0c09a07e: /* original 6cf6, guest PC 0x0c09a07e */
if(!s->budget--) { s->failed_pc=0x0c09a07eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09a080;
P_0c09a080: /* original 6df6, guest PC 0x0c09a080 */
if(!s->budget--) { s->failed_pc=0x0c09a080u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09a082;
P_0c09a082: /* original 000b, guest PC 0x0c09a082 */
if(!s->budget--) { s->failed_pc=0x0c09a082u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09a084: /* original 6ef6, guest PC 0x0c09a084 */
if(!s->budget--) { s->failed_pc=0x0c09a084u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09a086u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c07d88au,0x0c07d88cu,0x0c07d88eu,0x0c07d890u,0x0c07d892u,0x0c07d894u,0x0c07d896u,0x0c07d898u,0x0c07d89au,0x0c07d89cu,0x0c07d89eu,0x0c07d8a0u,0x0c07d8a2u,0x0c07d8a4u,0x0c07d8a6u,0x0c07d8a8u,
0x0c07d8aau,0x0c07d8acu,0x0c07d8aeu,0x0c07d8b0u,0x0c07d8b2u,0x0c07d8b4u,0x0c07d8b6u,0x0c07d8b8u,0x0c07d8bau,0x0c07d8bcu,0x0c07d8beu,0x0c07d8c0u,0x0c07d8c2u,0x0c07d8c4u,0x0c07d8c6u,0x0c07d8c8u,
0x0c07d8cau,0x0c07d8ccu,0x0c07d8ceu,0x0c07d8d0u,0x0c07d8d2u,0x0c07d8d4u,0x0c07d8d6u,0x0c07d8d8u,0x0c07d8dau,0x0c07d8dcu,0x0c07d8deu,0x0c07d8e0u,0x0c07d8e2u,0x0c07d8e4u,0x0c07d8e6u,0x0c07d8e8u,
0x0c07d8eau,0x0c07d8ecu,0x0c08230cu,0x0c08230eu,0x0c082310u,0x0c082312u,0x0c082314u,0x0c082316u,0x0c082318u,0x0c08231au,0x0c08231cu,0x0c08231eu,0x0c082320u,0x0c082322u,0x0c082324u,0x0c082326u,
0x0c082328u,0x0c08232au,0x0c08232cu,0x0c08232eu,0x0c082330u,0x0c082332u,0x0c082334u,0x0c082336u,0x0c082338u,0x0c08233au,0x0c08233cu,0x0c08233eu,0x0c082340u,0x0c082342u,0x0c082344u,0x0c082346u,
0x0c082348u,0x0c08234au,0x0c08234cu,0x0c08234eu,0x0c082350u,0x0c082352u,0x0c082354u,0x0c082356u,0x0c082358u,0x0c08235au,0x0c08235cu,0x0c08235eu,0x0c082360u,0x0c082362u,0x0c082364u,0x0c082366u,
0x0c082368u,0x0c08236au,0x0c08236cu,0x0c08236eu,0x0c082370u,0x0c082372u,0x0c082374u,0x0c082376u,0x0c082378u,0x0c08237au,0x0c08237cu,0x0c08237eu,0x0c082380u,0x0c082382u,0x0c082384u,0x0c082386u,
0x0c082388u,0x0c08238au,0x0c08238cu,0x0c08238eu,0x0c082390u,0x0c082392u,0x0c082394u,0x0c082396u,0x0c082398u,0x0c08239au,0x0c08239cu,0x0c08239eu,0x0c0823a0u,0x0c0823a2u,0x0c0823a4u,0x0c0823a6u,
0x0c0823a8u,0x0c0823aau,0x0c0823acu,0x0c0823aeu,0x0c0823b0u,0x0c0823b2u,0x0c0823b4u,0x0c0823b6u,0x0c0823b8u,0x0c0823bau,0x0c0823bcu,0x0c0823beu,0x0c0823c0u,0x0c0823c2u,0x0c0823c4u,0x0c0823c6u,
0x0c0823c8u,0x0c0823cau,0x0c0823ccu,0x0c0823ceu,0x0c0823d0u,0x0c0823d2u,0x0c0823d4u,0x0c0823d6u,0x0c0823d8u,0x0c0823dau,0x0c0823dcu,0x0c0823deu,0x0c0823e0u,0x0c0823e2u,0x0c0823e4u,0x0c0823e6u,
0x0c0823e8u,0x0c0823eau,0x0c0823ecu,0x0c0823eeu,0x0c0823f0u,0x0c0823f2u,0x0c0823f4u,0x0c0823f6u,0x0c0823f8u,0x0c0823fau,0x0c0823fcu,0x0c0823feu,0x0c082400u,0x0c082402u,0x0c082404u,0x0c082406u,
0x0c082408u,0x0c08240au,0x0c08240cu,0x0c08240eu,0x0c082410u,0x0c082412u,0x0c082414u,0x0c082416u,0x0c082418u,0x0c08241au,0x0c08241cu,0x0c08241eu,0x0c082420u,0x0c082422u,0x0c082424u,0x0c082426u,
0x0c082428u,0x0c08242au,0x0c08242cu,0x0c08242eu,0x0c082430u,0x0c082432u,0x0c082434u,0x0c082436u,0x0c082438u,0x0c08243au,0x0c08243cu,0x0c08243eu,0x0c082440u,0x0c082442u,0x0c082444u,0x0c082446u,
0x0c082448u,0x0c08244au,0x0c08244cu,0x0c08244eu,0x0c082450u,0x0c082452u,0x0c082454u,0x0c082456u,0x0c082458u,0x0c08245au,0x0c08245cu,0x0c08245eu,0x0c082460u,0x0c082462u,0x0c082464u,0x0c082466u,
0x0c082468u,0x0c0824d4u,0x0c0824d6u,0x0c0824d8u,0x0c0824dau,0x0c0824dcu,0x0c0824deu,0x0c0824e0u,0x0c0824e2u,0x0c0824e4u,0x0c0824e6u,0x0c0824e8u,0x0c0824eau,0x0c0824ecu,0x0c0824eeu,0x0c0824f0u,
0x0c0824f2u,0x0c0824f4u,0x0c0824f6u,0x0c0824f8u,0x0c0824fau,0x0c0824fcu,0x0c0824feu,0x0c082500u,0x0c082502u,0x0c082504u,0x0c082506u,0x0c082508u,0x0c08250au,0x0c08250cu,0x0c08250eu,0x0c082510u,
0x0c082512u,0x0c082514u,0x0c082516u,0x0c082518u,0x0c08251au,0x0c08251cu,0x0c08251eu,0x0c082520u,0x0c082522u,0x0c082524u,0x0c082526u,0x0c082528u,0x0c08252au,0x0c08252cu,0x0c08252eu,0x0c082530u,
0x0c082544u,0x0c082546u,0x0c082548u,0x0c08254au,0x0c08254cu,0x0c08254eu,0x0c082550u,0x0c082552u,0x0c082554u,0x0c082556u,0x0c082558u,0x0c08255au,0x0c08255cu,0x0c08255eu,0x0c082560u,0x0c082562u,
0x0c082564u,0x0c082566u,0x0c082568u,0x0c08256au,0x0c08256cu,0x0c08256eu,0x0c082570u,0x0c082572u,0x0c082574u,0x0c082576u,0x0c082578u,0x0c08257au,0x0c08257cu,0x0c08257eu,0x0c082580u,0x0c082582u,
0x0c082584u,0x0c082586u,0x0c082588u,0x0c08258au,0x0c08258cu,0x0c08258eu,0x0c082590u,0x0c082592u,0x0c082594u,0x0c082596u,0x0c082598u,0x0c08259au,0x0c08259cu,0x0c08259eu,0x0c0825a0u,0x0c0825a2u,
0x0c0825a4u,0x0c0825a6u,0x0c0825a8u,0x0c0825aau,0x0c0825acu,0x0c0825aeu,0x0c0825b0u,0x0c0825b2u,0x0c0825b4u,0x0c0825b6u,0x0c0825b8u,0x0c0825bau,0x0c0825bcu,0x0c0825beu,0x0c0825c0u,0x0c0825c2u,
0x0c0825c4u,0x0c0825c6u,0x0c0825c8u,0x0c0825cau,0x0c0825ccu,0x0c0825ceu,0x0c0825d0u,0x0c0825d2u,0x0c0825d4u,0x0c0825d6u,0x0c0825d8u,0x0c0825dau,0x0c0825dcu,0x0c0825deu,0x0c0825e0u,0x0c0825e2u,
0x0c0825e4u,0x0c0825e6u,0x0c0825e8u,0x0c0825eau,0x0c0825ecu,0x0c0825eeu,0x0c0825f0u,0x0c0825f2u,0x0c0825f4u,0x0c0825f6u,0x0c0825f8u,0x0c0825fau,0x0c0825fcu,0x0c0825feu,0x0c082600u,0x0c082602u,
0x0c082604u,0x0c082606u,0x0c082608u,0x0c08260au,0x0c08260cu,0x0c08260eu,0x0c082610u,0x0c082612u,0x0c082614u,0x0c082616u,0x0c082618u,0x0c08261au,0x0c08261cu,0x0c08261eu,0x0c082620u,0x0c082622u,
0x0c082624u,0x0c082626u,0x0c082628u,0x0c08262au,0x0c08262cu,0x0c08262eu,0x0c082630u,0x0c082632u,0x0c082634u,0x0c082636u,0x0c082638u,0x0c08263au,0x0c08263cu,0x0c08263eu,0x0c082640u,0x0c082642u,
0x0c082644u,0x0c082646u,0x0c082648u,0x0c08264au,0x0c08264cu,0x0c08264eu,0x0c082650u,0x0c082652u,0x0c082654u,0x0c082656u,0x0c082658u,0x0c08265au,0x0c08265cu,0x0c08265eu,0x0c082660u,0x0c082662u,
0x0c082664u,0x0c082666u,0x0c082668u,0x0c08266au,0x0c08266cu,0x0c08266eu,0x0c082670u,0x0c082672u,0x0c082674u,0x0c082676u,0x0c082678u,0x0c08267au,0x0c08267cu,0x0c08267eu,0x0c082680u,0x0c0826a4u,
0x0c0826a6u,0x0c0826a8u,0x0c0826aau,0x0c0826acu,0x0c0826aeu,0x0c0826b4u,0x0c0826b6u,0x0c0826b8u,0x0c0826bau,0x0c0826bcu,0x0c0826beu,0x0c0826c0u,0x0c0826c2u,0x0c0826c4u,0x0c0826c6u,0x0c0826c8u,
0x0c0826cau,0x0c0826ccu,0x0c0826ceu,0x0c0826d0u,0x0c0826d2u,0x0c0826d4u,0x0c0826d6u,0x0c0826d8u,0x0c0826dau,0x0c0826dcu,0x0c0826deu,0x0c0826e0u,0x0c0826e2u,0x0c0826e4u,0x0c0826e6u,0x0c0826e8u,
0x0c0826eau,0x0c0826ecu,0x0c0826eeu,0x0c0826f0u,0x0c0826f2u,0x0c0826f4u,0x0c0826f6u,0x0c0826f8u,0x0c0826fau,0x0c0826fcu,0x0c0826feu,0x0c082700u,0x0c082702u,0x0c082704u,0x0c082706u,0x0c082708u,
0x0c08270au,0x0c08270cu,0x0c08270eu,0x0c082710u,0x0c082712u,0x0c082714u,0x0c082716u,0x0c082718u,0x0c08271au,0x0c08271cu,0x0c08271eu,0x0c082720u,0x0c082722u,0x0c082724u,0x0c082726u,0x0c082728u,
0x0c08272au,0x0c08272cu,0x0c08272eu,0x0c082730u,0x0c082732u,0x0c082734u,0x0c082736u,0x0c082738u,0x0c08273au,0x0c08273cu,0x0c08273eu,0x0c082740u,0x0c082742u,0x0c082744u,0x0c082746u,0x0c082748u,
0x0c08274au,0x0c08274cu,0x0c08274eu,0x0c082750u,0x0c082752u,0x0c082754u,0x0c082756u,0x0c082758u,0x0c08275au,0x0c08275cu,0x0c08275eu,0x0c082760u,0x0c082762u,0x0c082764u,0x0c082766u,0x0c082768u,
0x0c08276au,0x0c08276cu,0x0c08276eu,0x0c082770u,0x0c082772u,0x0c082774u,0x0c082776u,0x0c082778u,0x0c08277au,0x0c08277cu,0x0c08277eu,0x0c082780u,0x0c082782u,0x0c082784u,0x0c082786u,0x0c082788u,
0x0c08278au,0x0c08278cu,0x0c08278eu,0x0c082790u,0x0c082792u,0x0c082794u,0x0c082796u,0x0c082798u,0x0c08279au,0x0c08279cu,0x0c08279eu,0x0c0827a0u,0x0c0827a2u,0x0c0827a4u,0x0c0827a6u,0x0c0827a8u,
0x0c0827aau,0x0c0827acu,0x0c0827aeu,0x0c0827b0u,0x0c0827b2u,0x0c0827b4u,0x0c0827b6u,0x0c0827b8u,0x0c0827bau,0x0c0827bcu,0x0c0827beu,0x0c0827c0u,0x0c0827c2u,0x0c0827c4u,0x0c0827c6u,0x0c0827c8u,
0x0c0827cau,0x0c0827ccu,0x0c0827ceu,0x0c0827d0u,0x0c0827d2u,0x0c0827d4u,0x0c0827d6u,0x0c0827d8u,0x0c0827dau,0x0c0827dcu,0x0c0827deu,0x0c0827e0u,0x0c0827e2u,0x0c0827e4u,0x0c0827e6u,0x0c0827e8u,
0x0c0827eau,0x0c0827ecu,0x0c0827eeu,0x0c0827f0u,0x0c0827f2u,0x0c0827f4u,0x0c0827f6u,0x0c0827f8u,0x0c0827fau,0x0c0827fcu,0x0c0827feu,0x0c082800u,0x0c082802u,0x0c082824u,0x0c082826u,0x0c082828u,
0x0c08282au,0x0c08282cu,0x0c08282eu,0x0c082830u,0x0c082832u,0x0c082834u,0x0c082836u,0x0c082838u,0x0c08283au,0x0c08283cu,0x0c08283eu,0x0c082840u,0x0c082842u,0x0c082844u,0x0c082846u,0x0c082848u,
0x0c08284au,0x0c08284cu,0x0c08284eu,0x0c082850u,0x0c082852u,0x0c082854u,0x0c082856u,0x0c082858u,0x0c08285au,0x0c082868u,0x0c08286au,0x0c08286cu,0x0c08286eu,0x0c082870u,0x0c082872u,0x0c082874u,
0x0c082876u,0x0c082878u,0x0c08287au,0x0c08287cu,0x0c08287eu,0x0c082880u,0x0c082882u,0x0c082884u,0x0c082886u,0x0c082888u,0x0c08288au,0x0c08288cu,0x0c08288eu,0x0c082890u,0x0c082892u,0x0c082894u,
0x0c082896u,0x0c082898u,0x0c08289au,0x0c08289cu,0x0c08289eu,0x0c0828a0u,0x0c0828a2u,0x0c0828a4u,0x0c0828a6u,0x0c0828a8u,0x0c0828aau,0x0c0828acu,0x0c0828aeu,0x0c0828b0u,0x0c0828b2u,0x0c0828b4u,
0x0c0828b6u,0x0c0828b8u,0x0c0828bau,0x0c0828bcu,0x0c0828beu,0x0c0828c0u,0x0c0828c2u,0x0c0828c4u,0x0c0828c6u,0x0c0828c8u,0x0c0828cau,0x0c0828ccu,0x0c0828ceu,0x0c0828d0u,0x0c0828d2u,0x0c0828d4u,
0x0c0828d6u,0x0c0828d8u,0x0c0828dau,0x0c0828dcu,0x0c0828deu,0x0c0828e0u,0x0c0828e2u,0x0c0828e4u,0x0c0828e6u,0x0c0828e8u,0x0c0828eau,0x0c0828ecu,0x0c0828eeu,0x0c0828f0u,0x0c0828f2u,0x0c0828f4u,
0x0c0828f6u,0x0c0828f8u,0x0c0828fau,0x0c0828fcu,0x0c0828feu,0x0c082900u,0x0c082902u,0x0c082904u,0x0c082906u,0x0c082908u,0x0c08290au,0x0c08290cu,0x0c08290eu,0x0c082910u,0x0c082912u,0x0c082914u,
0x0c082916u,0x0c082918u,0x0c08291au,0x0c08291cu,0x0c08291eu,0x0c082920u,0x0c082922u,0x0c082924u,0x0c082926u,0x0c082928u,0x0c08292au,0x0c08292cu,0x0c08292eu,0x0c082930u,0x0c082932u,0x0c082934u,
0x0c082936u,0x0c082938u,0x0c08293au,0x0c08293cu,0x0c08293eu,0x0c082940u,0x0c082942u,0x0c082944u,0x0c082946u,0x0c082948u,0x0c08294au,0x0c08294cu,0x0c08294eu,0x0c082950u,0x0c082952u,0x0c082954u,
0x0c082956u,0x0c082958u,0x0c08295au,0x0c08295cu,0x0c08295eu,0x0c082960u,0x0c082962u,0x0c082964u,0x0c082966u,0x0c082968u,0x0c08296au,0x0c08296cu,0x0c08296eu,0x0c082970u,0x0c082972u,0x0c082974u,
0x0c082976u,0x0c082978u,0x0c08297au,0x0c08297cu,0x0c08297eu,0x0c082980u,0x0c082982u,0x0c082984u,0x0c082986u,0x0c082988u,0x0c08298au,0x0c08298cu,0x0c08298eu,0x0c082990u,0x0c082992u,0x0c0829c0u,
0x0c0829c2u,0x0c0829c4u,0x0c0829c6u,0x0c0829c8u,0x0c0829cau,0x0c0829ccu,0x0c0829ceu,0x0c0829d0u,0x0c0829d2u,0x0c0829d4u,0x0c0829d6u,0x0c0829d8u,0x0c0829dau,0x0c0829dcu,0x0c0829deu,0x0c0829e0u,
0x0c0829e2u,0x0c0829e4u,0x0c0829e6u,0x0c0829e8u,0x0c0829eau,0x0c0829ecu,0x0c0829eeu,0x0c0829f0u,0x0c0829f2u,0x0c0829f4u,0x0c0829f6u,0x0c0829f8u,0x0c0829fau,0x0c0829fcu,0x0c0829feu,0x0c082a00u,
0x0c082a02u,0x0c082a04u,0x0c082a06u,0x0c082a08u,0x0c082a0au,0x0c082a0cu,0x0c082a0eu,0x0c082a10u,0x0c082a12u,0x0c082a14u,0x0c082a16u,0x0c082a18u,0x0c082a1au,0x0c082a1cu,0x0c082a1eu,0x0c082a20u,
0x0c082a22u,0x0c082a24u,0x0c082a26u,0x0c082a28u,0x0c082a2au,0x0c082a2cu,0x0c082a2eu,0x0c082a30u,0x0c082a32u,0x0c082a34u,0x0c082a36u,0x0c082a38u,0x0c082a3au,0x0c082a3cu,0x0c082a3eu,0x0c082a40u,
0x0c082a42u,0x0c082a44u,0x0c082a46u,0x0c082a48u,0x0c082a4au,0x0c082a4cu,0x0c082a4eu,0x0c082a50u,0x0c082a52u,0x0c082a54u,0x0c082a56u,0x0c082a58u,0x0c082a5au,0x0c082a5cu,0x0c082a5eu,0x0c082a60u,
0x0c082a62u,0x0c082a64u,0x0c082a66u,0x0c082a68u,0x0c082a6au,0x0c082a6cu,0x0c082a6eu,0x0c082a70u,0x0c082a72u,0x0c082a74u,0x0c082a76u,0x0c082a78u,0x0c082a7au,0x0c082a7cu,0x0c082a7eu,0x0c082a80u,
0x0c082a82u,0x0c082a84u,0x0c082a86u,0x0c082a88u,0x0c082a8au,0x0c082a8cu,0x0c082a8eu,0x0c082a90u,0x0c082a92u,0x0c082a94u,0x0c082a96u,0x0c082a98u,0x0c082a9au,0x0c082a9cu,0x0c082a9eu,0x0c082aa0u,
0x0c082aa2u,0x0c082aa4u,0x0c082aa6u,0x0c082aa8u,0x0c082aaau,0x0c082aacu,0x0c082aaeu,0x0c082ab0u,0x0c082ab2u,0x0c082ab4u,0x0c082ab6u,0x0c082ab8u,0x0c082abau,0x0c082abcu,0x0c082abeu,0x0c082ac0u,
0x0c082ac2u,0x0c082ac4u,0x0c082ac6u,0x0c082ac8u,0x0c082acau,0x0c082accu,0x0c082aceu,0x0c082ad0u,0x0c082ad2u,0x0c082ad4u,0x0c082ad6u,0x0c082ad8u,0x0c082adau,0x0c082adcu,0x0c082adeu,0x0c082ae0u,
0x0c082ae2u,0x0c082ae4u,0x0c082ae6u,0x0c082ae8u,0x0c082aeau,0x0c082b14u,0x0c082b16u,0x0c082b18u,0x0c082b1au,0x0c082b1cu,0x0c082b1eu,0x0c082b20u,0x0c082b22u,0x0c082b24u,0x0c082b26u,0x0c082b28u,
0x0c082b2au,0x0c082b2cu,0x0c082b2eu,0x0c082b30u,0x0c082b32u,0x0c082b34u,0x0c082b36u,0x0c082b38u,0x0c082b3au,0x0c082b3cu,0x0c082b3eu,0x0c082b40u,0x0c082b42u,0x0c082b44u,0x0c082b46u,0x0c082b48u,
0x0c082b4au,0x0c082b4cu,0x0c082b4eu,0x0c082b50u,0x0c082b52u,0x0c082b54u,0x0c082b56u,0x0c082b58u,0x0c082b5au,0x0c082b5cu,0x0c082b5eu,0x0c082b60u,0x0c082b62u,0x0c082b64u,0x0c082b66u,0x0c082b68u,
0x0c082b6au,0x0c082b6cu,0x0c082b6eu,0x0c082b70u,0x0c082b72u,0x0c082b74u,0x0c082b76u,0x0c082b78u,0x0c082b7au,0x0c082b7cu,0x0c082b7eu,0x0c082b80u,0x0c082b82u,0x0c082b84u,0x0c082b86u,0x0c082b88u,
0x0c082b8au,0x0c082b8cu,0x0c082b8eu,0x0c082b90u,0x0c082b92u,0x0c082b94u,0x0c082b96u,0x0c082b98u,0x0c082b9au,0x0c082b9cu,0x0c082b9eu,0x0c082ba0u,0x0c0831eau,0x0c0831ecu,0x0c0831eeu,0x0c0831f0u,
0x0c0831f2u,0x0c0831f4u,0x0c0831f6u,0x0c0831f8u,0x0c0831fau,0x0c0831fcu,0x0c0831feu,0x0c083200u,0x0c083202u,0x0c083204u,0x0c083206u,0x0c083208u,0x0c08320au,0x0c08320cu,0x0c08320eu,0x0c083210u,
0x0c083212u,0x0c083214u,0x0c083216u,0x0c083218u,0x0c08321au,0x0c08321cu,0x0c08321eu,0x0c083220u,0x0c083222u,0x0c083224u,0x0c083226u,0x0c083228u,0x0c08322au,0x0c08322cu,0x0c08322eu,0x0c083230u,
0x0c083232u,0x0c083234u,0x0c083236u,0x0c083238u,0x0c08323au,0x0c08323cu,0x0c08323eu,0x0c083240u,0x0c083242u,0x0c083244u,0x0c08327cu,0x0c08327eu,0x0c083280u,0x0c083282u,0x0c083284u,0x0c083286u,
0x0c083288u,0x0c08328au,0x0c08328cu,0x0c08328eu,0x0c083290u,0x0c083292u,0x0c083294u,0x0c083296u,0x0c083298u,0x0c08329au,0x0c08329cu,0x0c08329eu,0x0c0832a0u,0x0c0832a2u,0x0c0832a4u,0x0c0832a6u,
0x0c0832a8u,0x0c0832aau,0x0c0832acu,0x0c0832aeu,0x0c0832b0u,0x0c0832b2u,0x0c0832b4u,0x0c0832b6u,0x0c0832b8u,0x0c0832bau,0x0c0832bcu,0x0c0832beu,0x0c0832c0u,0x0c0832c2u,0x0c0832c4u,0x0c0832c6u,
0x0c0832c8u,0x0c0832cau,0x0c0832ccu,0x0c0832ceu,0x0c0832d0u,0x0c0832d2u,0x0c0832d4u,0x0c0832d6u,0x0c0832d8u,0x0c0832dau,0x0c0832dcu,0x0c0832deu,0x0c0832e0u,0x0c0832e2u,0x0c0832e4u,0x0c0832e6u,
0x0c0832e8u,0x0c0832eau,0x0c0832ecu,0x0c0832eeu,0x0c0832f0u,0x0c0832f2u,0x0c0832f4u,0x0c0832f6u,0x0c0832f8u,0x0c0832fau,0x0c0832fcu,0x0c0832feu,0x0c083300u,0x0c083302u,0x0c083304u,0x0c083306u,
0x0c083308u,0x0c08330au,0x0c08330cu,0x0c08330eu,0x0c083310u,0x0c083312u,0x0c083314u,0x0c083316u,0x0c083318u,0x0c08331au,0x0c08331cu,0x0c08331eu,0x0c083320u,0x0c083322u,0x0c083324u,0x0c083326u,
0x0c083328u,0x0c08332au,0x0c08332cu,0x0c08332eu,0x0c083330u,0x0c083332u,0x0c083334u,0x0c083336u,0x0c083338u,0x0c08333au,0x0c08333cu,0x0c08333eu,0x0c083340u,0x0c083342u,0x0c083344u,0x0c083346u,
0x0c083348u,0x0c08334au,0x0c08334cu,0x0c08334eu,0x0c083350u,0x0c083352u,0x0c083354u,0x0c083356u,0x0c083358u,0x0c08335au,0x0c08335cu,0x0c08335eu,0x0c083360u,0x0c083362u,0x0c083364u,0x0c083384u,
0x0c083386u,0x0c083388u,0x0c08338au,0x0c08338cu,0x0c08338eu,0x0c083390u,0x0c083392u,0x0c083394u,0x0c083396u,0x0c083398u,0x0c08339au,0x0c08339cu,0x0c08339eu,0x0c0833a0u,0x0c0833a2u,0x0c0833a4u,
0x0c0833a6u,0x0c0833a8u,0x0c0833aau,0x0c0833acu,0x0c0833aeu,0x0c0833b0u,0x0c0833b2u,0x0c0833b4u,0x0c0833b6u,0x0c0833b8u,0x0c0833bau,0x0c0833bcu,0x0c0833beu,0x0c0833c0u,0x0c0833c2u,0x0c0833c4u,
0x0c0833c6u,0x0c0833c8u,0x0c0833cau,0x0c0833ccu,0x0c0833ceu,0x0c0833d0u,0x0c0833d2u,0x0c0833d4u,0x0c0833d6u,0x0c0833d8u,0x0c0833dau,0x0c0833dcu,0x0c0833deu,0x0c0833e0u,0x0c0833e2u,0x0c0833e4u,
0x0c0833e6u,0x0c0833e8u,0x0c0833eau,0x0c0833ecu,0x0c0833eeu,0x0c0833f0u,0x0c0833f2u,0x0c0833f4u,0x0c0833f6u,0x0c0833f8u,0x0c0833fau,0x0c0833fcu,0x0c0833feu,0x0c083400u,0x0c083402u,0x0c083404u,
0x0c083406u,0x0c083408u,0x0c08340au,0x0c08340cu,0x0c08340eu,0x0c083410u,0x0c083412u,0x0c083414u,0x0c083416u,0x0c083418u,0x0c08341au,0x0c08341cu,0x0c08341eu,0x0c083420u,0x0c083422u,0x0c083424u,
0x0c083426u,0x0c083428u,0x0c08342au,0x0c08342cu,0x0c08342eu,0x0c083430u,0x0c083432u,0x0c083434u,0x0c083436u,0x0c083438u,0x0c08343au,0x0c08343cu,0x0c08343eu,0x0c083440u,0x0c083442u,0x0c083444u,
0x0c083446u,0x0c083448u,0x0c08344au,0x0c08344cu,0x0c08344eu,0x0c083450u,0x0c083452u,0x0c083454u,0x0c083456u,0x0c083458u,0x0c08345au,0x0c08345cu,0x0c08345eu,0x0c083460u,0x0c083462u,0x0c083464u,
0x0c083466u,0x0c083468u,0x0c08346au,0x0c08346cu,0x0c08346eu,0x0c083470u,0x0c083472u,0x0c083474u,0x0c083476u,0x0c083478u,0x0c08347au,0x0c08347cu,0x0c08347eu,0x0c083480u,0x0c083482u,0x0c083484u,
0x0c083486u,0x0c083488u,0x0c08348au,0x0c08348cu,0x0c08348eu,0x0c083490u,0x0c083492u,0x0c0834b0u,0x0c0834b2u,0x0c0834b4u,0x0c0834b6u,0x0c0834b8u,0x0c0834bau,0x0c0834bcu,0x0c0834beu,0x0c0834c0u,
0x0c0834c2u,0x0c0834c4u,0x0c0834c6u,0x0c0834c8u,0x0c0834cau,0x0c0834ccu,0x0c0834ceu,0x0c0834d0u,0x0c0834d2u,0x0c0834d4u,0x0c0834d6u,0x0c0834d8u,0x0c0834dau,0x0c0834dcu,0x0c0834deu,0x0c0834e0u,
0x0c0834e2u,0x0c0834e4u,0x0c0834e6u,0x0c0834e8u,0x0c0834eau,0x0c0834ecu,0x0c0834eeu,0x0c0834f0u,0x0c0834f2u,0x0c0834f4u,0x0c0834f6u,0x0c0834f8u,0x0c0834fau,0x0c0834fcu,0x0c0834feu,0x0c083500u,
0x0c083502u,0x0c083504u,0x0c083506u,0x0c083508u,0x0c08350au,0x0c08350cu,0x0c08350eu,0x0c083510u,0x0c083512u,0x0c083514u,0x0c083516u,0x0c083518u,0x0c08351au,0x0c08351cu,0x0c08351eu,0x0c083520u,
0x0c083522u,0x0c083524u,0x0c083526u,0x0c083528u,0x0c08352au,0x0c08352cu,0x0c08352eu,0x0c083530u,0x0c083532u,0x0c083534u,0x0c083536u,0x0c083538u,0x0c08353au,0x0c08353cu,0x0c08353eu,0x0c083540u,
0x0c083542u,0x0c083544u,0x0c083546u,0x0c083548u,0x0c08354au,0x0c08354cu,0x0c08354eu,0x0c083550u,0x0c083552u,0x0c083554u,0x0c083556u,0x0c083558u,0x0c08355au,0x0c08355cu,0x0c08355eu,0x0c083560u,
0x0c083562u,0x0c083564u,0x0c083566u,0x0c083568u,0x0c08356au,0x0c08356cu,0x0c08356eu,0x0c083570u,0x0c083572u,0x0c083574u,0x0c083576u,0x0c083578u,0x0c08357au,0x0c08357cu,0x0c08357eu,0x0c083580u,
0x0c083582u,0x0c083584u,0x0c083586u,0x0c083588u,0x0c08358au,0x0c08358cu,0x0c08358eu,0x0c083590u,0x0c083592u,0x0c083594u,0x0c083596u,0x0c083598u,0x0c08359au,0x0c08359cu,0x0c08359eu,0x0c0835a0u,
0x0c0835a2u,0x0c0835a4u,0x0c0835a6u,0x0c0835a8u,0x0c0835c4u,0x0c0835c6u,0x0c0835c8u,0x0c0835cau,0x0c0835ccu,0x0c0835ceu,0x0c0835d0u,0x0c0835d2u,0x0c0835d4u,0x0c0835d6u,0x0c0835d8u,0x0c0835dau,
0x0c0835dcu,0x0c0835deu,0x0c0835e0u,0x0c0835e2u,0x0c0835e4u,0x0c0835e6u,0x0c0835e8u,0x0c0835eau,0x0c0835ecu,0x0c0835eeu,0x0c0835f0u,0x0c0835f2u,0x0c0835f4u,0x0c0835f6u,0x0c0835f8u,0x0c0835fau,
0x0c0835fcu,0x0c0835feu,0x0c083600u,0x0c083602u,0x0c083604u,0x0c083606u,0x0c083608u,0x0c08360au,0x0c08360cu,0x0c08360eu,0x0c083610u,0x0c083612u,0x0c083614u,0x0c083616u,0x0c083618u,0x0c08361au,
0x0c08361cu,0x0c08361eu,0x0c083620u,0x0c083622u,0x0c083624u,0x0c083626u,0x0c083628u,0x0c08362au,0x0c08362cu,0x0c08362eu,0x0c083630u,0x0c083632u,0x0c083634u,0x0c083636u,0x0c083638u,0x0c08363au,
0x0c08363cu,0x0c08363eu,0x0c083640u,0x0c083642u,0x0c083644u,0x0c083646u,0x0c083648u,0x0c08364au,0x0c08364cu,0x0c08364eu,0x0c083650u,0x0c083652u,0x0c083654u,0x0c083656u,0x0c083658u,0x0c08365au,
0x0c08365cu,0x0c08365eu,0x0c083660u,0x0c083662u,0x0c083664u,0x0c083666u,0x0c083668u,0x0c08366au,0x0c08366cu,0x0c08366eu,0x0c083670u,0x0c083672u,0x0c083674u,0x0c083676u,0x0c083678u,0x0c08367au,
0x0c08367cu,0x0c08367eu,0x0c083680u,0x0c083682u,0x0c083684u,0x0c083686u,0x0c083688u,0x0c08368au,0x0c08368cu,0x0c08368eu,0x0c083690u,0x0c083692u,0x0c083694u,0x0c083696u,0x0c083698u,0x0c08369au,
0x0c08369cu,0x0c08369eu,0x0c0836a0u,0x0c0836a2u,0x0c0836a4u,0x0c0836a6u,0x0c0836a8u,0x0c0836aau,0x0c0836acu,0x0c0836aeu,0x0c0836b0u,0x0c0836b2u,0x0c0836b4u,0x0c0836b6u,0x0c0836b8u,0x0c0836bau,
0x0c0836bcu,0x0c0836beu,0x0c0836c0u,0x0c0836c2u,0x0c0836c4u,0x0c0836c6u,0x0c0836c8u,0x0c0836cau,0x0c0836ccu,0x0c0836ceu,0x0c0836d0u,0x0c0836d2u,0x0c0836d4u,0x0c0836f0u,0x0c0836f2u,0x0c0836f4u,
0x0c0836f6u,0x0c0836f8u,0x0c0836fau,0x0c0836fcu,0x0c0836feu,0x0c083700u,0x0c083702u,0x0c083704u,0x0c083706u,0x0c083708u,0x0c08370au,0x0c08370cu,0x0c08370eu,0x0c083710u,0x0c083712u,0x0c083714u,
0x0c083716u,0x0c083718u,0x0c08371au,0x0c08371cu,0x0c08371eu,0x0c083720u,0x0c083722u,0x0c083724u,0x0c083726u,0x0c083728u,0x0c08372au,0x0c08372cu,0x0c08372eu,0x0c083730u,0x0c083732u,0x0c083734u,
0x0c083736u,0x0c083738u,0x0c08373au,0x0c08373cu,0x0c08373eu,0x0c083740u,0x0c083742u,0x0c083744u,0x0c083746u,0x0c083748u,0x0c08374au,0x0c08374cu,0x0c08374eu,0x0c083750u,0x0c083752u,0x0c083754u,
0x0c083756u,0x0c083758u,0x0c08375au,0x0c08375cu,0x0c08375eu,0x0c083760u,0x0c083762u,0x0c083764u,0x0c083766u,0x0c083768u,0x0c08376au,0x0c08376cu,0x0c08376eu,0x0c083770u,0x0c083772u,0x0c083774u,
0x0c083776u,0x0c083778u,0x0c08377au,0x0c08377cu,0x0c08377eu,0x0c083780u,0x0c083782u,0x0c083784u,0x0c083786u,0x0c083788u,0x0c08378au,0x0c08378cu,0x0c08378eu,0x0c083790u,0x0c083792u,0x0c083794u,
0x0c083796u,0x0c083798u,0x0c08379au,0x0c08379cu,0x0c08379eu,0x0c0837a0u,0x0c0837a2u,0x0c0837a4u,0x0c0837a6u,0x0c0837a8u,0x0c0837aau,0x0c0837acu,0x0c0837aeu,0x0c0837b0u,0x0c0837b2u,0x0c0837b4u,
0x0c0837b6u,0x0c0837b8u,0x0c0837bau,0x0c0837bcu,0x0c0837beu,0x0c0837c0u,0x0c0837c2u,0x0c0837c4u,0x0c0837c6u,0x0c0837c8u,0x0c0837cau,0x0c0837ccu,0x0c0837ceu,0x0c0837d0u,0x0c0837d2u,0x0c0837d4u,
0x0c0837d6u,0x0c0837d8u,0x0c0837dau,0x0c0837dcu,0x0c0837deu,0x0c0837e0u,0x0c0837e2u,0x0c0837e4u,0x0c0837e6u,0x0c0837e8u,0x0c0837eau,0x0c0837ecu,0x0c0837eeu,0x0c0837f0u,0x0c08380cu,0x0c08380eu,
0x0c083810u,0x0c083812u,0x0c083814u,0x0c083816u,0x0c083818u,0x0c08381au,0x0c08381cu,0x0c08381eu,0x0c083820u,0x0c083822u,0x0c083824u,0x0c083826u,0x0c083828u,0x0c08382au,0x0c08382cu,0x0c08382eu,
0x0c083830u,0x0c083832u,0x0c083834u,0x0c083836u,0x0c083838u,0x0c08383au,0x0c08383cu,0x0c08383eu,0x0c083840u,0x0c083842u,0x0c083844u,0x0c083846u,0x0c083848u,0x0c08384au,0x0c08384cu,0x0c08384eu,
0x0c083850u,0x0c083852u,0x0c083854u,0x0c083856u,0x0c083858u,0x0c08385au,0x0c08385cu,0x0c08385eu,0x0c083860u,0x0c083862u,0x0c083864u,0x0c083866u,0x0c083868u,0x0c08386au,0x0c08386cu,0x0c08386eu,
0x0c083870u,0x0c083872u,0x0c083874u,0x0c083876u,0x0c083878u,0x0c08387au,0x0c08387cu,0x0c08387eu,0x0c083880u,0x0c083882u,0x0c083884u,0x0c083886u,0x0c083888u,0x0c08388au,0x0c08388cu,0x0c08388eu,
0x0c083890u,0x0c083892u,0x0c083894u,0x0c083896u,0x0c083898u,0x0c08389au,0x0c08389cu,0x0c08389eu,0x0c0838a0u,0x0c0838a2u,0x0c0838a4u,0x0c0838a6u,0x0c0838a8u,0x0c0838aau,0x0c0838acu,0x0c0838aeu,
0x0c0838b0u,0x0c0838b2u,0x0c0838b4u,0x0c0838b6u,0x0c0838b8u,0x0c0838bau,0x0c0838bcu,0x0c0838beu,0x0c0838c0u,0x0c0838c2u,0x0c0838c4u,0x0c0838c6u,0x0c0838c8u,0x0c0838cau,0x0c0838ccu,0x0c0838ceu,
0x0c0838d0u,0x0c0838d2u,0x0c0838d4u,0x0c0838d6u,0x0c0838f0u,0x0c0838f2u,0x0c0838f4u,0x0c0838f6u,0x0c0838f8u,0x0c0838fau,0x0c0838fcu,0x0c0838feu,0x0c083900u,0x0c083902u,0x0c083904u,0x0c083906u,
0x0c083908u,0x0c08390au,0x0c08390cu,0x0c08390eu,0x0c083910u,0x0c083912u,0x0c083914u,0x0c083916u,0x0c083918u,0x0c08391au,0x0c08391cu,0x0c08391eu,0x0c083920u,0x0c083922u,0x0c083924u,0x0c083926u,
0x0c083928u,0x0c08392au,0x0c08392cu,0x0c08392eu,0x0c083930u,0x0c083932u,0x0c083934u,0x0c083936u,0x0c083938u,0x0c08393au,0x0c08393cu,0x0c08393eu,0x0c083940u,0x0c083942u,0x0c083944u,0x0c083946u,
0x0c083948u,0x0c08394au,0x0c08394cu,0x0c08394eu,0x0c083950u,0x0c083952u,0x0c083954u,0x0c083956u,0x0c083958u,0x0c08395au,0x0c08395cu,0x0c08395eu,0x0c083960u,0x0c083962u,0x0c083964u,0x0c083966u,
0x0c083968u,0x0c08396au,0x0c08396cu,0x0c08396eu,0x0c083970u,0x0c083972u,0x0c083974u,0x0c083976u,0x0c083978u,0x0c08397au,0x0c08397cu,0x0c08397eu,0x0c083980u,0x0c083982u,0x0c083984u,0x0c083986u,
0x0c083988u,0x0c08398au,0x0c08398cu,0x0c08398eu,0x0c083990u,0x0c083992u,0x0c083994u,0x0c083996u,0x0c083998u,0x0c08399au,0x0c08399cu,0x0c08399eu,0x0c0839a0u,0x0c0839a2u,0x0c0839a4u,0x0c0839a6u,
0x0c0839a8u,0x0c0839aau,0x0c0839acu,0x0c0839aeu,0x0c0839b0u,0x0c0839b2u,0x0c0839b4u,0x0c0839b6u,0x0c0839b8u,0x0c0839bau,0x0c0839bcu,0x0c0839beu,0x0c0839c0u,0x0c0839c2u,0x0c0839c4u,0x0c0839c6u,
0x0c0839c8u,0x0c0839cau,0x0c0839ccu,0x0c0839ceu,0x0c0839d0u,0x0c0839d2u,0x0c0839d4u,0x0c0839d6u,0x0c0839d8u,0x0c0839dau,0x0c0839dcu,0x0c0839deu,0x0c0839e0u,0x0c0839e2u,0x0c0839e4u,0x0c0839e6u,
0x0c0839e8u,0x0c0839eau,0x0c0839ecu,0x0c0839eeu,0x0c0839f0u,0x0c0839f2u,0x0c0839f4u,0x0c0839f6u,0x0c0839f8u,0x0c0839fau,0x0c0839fcu,0x0c0839feu,0x0c083a00u,0x0c083a02u,0x0c083a04u,0x0c083a24u,
0x0c083a26u,0x0c083a28u,0x0c083a2au,0x0c083a2cu,0x0c083a2eu,0x0c083a30u,0x0c083a32u,0x0c083a34u,0x0c083a36u,0x0c083a38u,0x0c083a3au,0x0c083a3cu,0x0c083a3eu,0x0c083a40u,0x0c083a42u,0x0c083a44u,
0x0c083a46u,0x0c083a48u,0x0c083a4au,0x0c083a4cu,0x0c083a4eu,0x0c083a50u,0x0c083a52u,0x0c083a54u,0x0c083a56u,0x0c083a58u,0x0c083a5au,0x0c083a5cu,0x0c083a5eu,0x0c083a60u,0x0c083a62u,0x0c083a64u,
0x0c083a66u,0x0c083a68u,0x0c083a6au,0x0c083a6cu,0x0c083a6eu,0x0c083a70u,0x0c083a72u,0x0c083a74u,0x0c083a76u,0x0c083a78u,0x0c083a7au,0x0c083a7cu,0x0c083a7eu,0x0c083a80u,0x0c083a82u,0x0c083a84u,
0x0c083a86u,0x0c083a88u,0x0c083a8au,0x0c083a8cu,0x0c083a8eu,0x0c083a90u,0x0c083a92u,0x0c083a94u,0x0c083a96u,0x0c091028u,0x0c09102au,0x0c09102cu,0x0c09102eu,0x0c091030u,0x0c091032u,0x0c091034u,
0x0c091036u,0x0c091038u,0x0c09103au,0x0c09103cu,0x0c09103eu,0x0c091040u,0x0c091042u,0x0c091044u,0x0c091046u,0x0c091048u,0x0c09104au,0x0c09104cu,0x0c09104eu,0x0c091050u,0x0c091052u,0x0c091054u,
0x0c091056u,0x0c091058u,0x0c09105au,0x0c09105cu,0x0c09105eu,0x0c091060u,0x0c091062u,0x0c091064u,0x0c091066u,0x0c091068u,0x0c09106au,0x0c09106cu,0x0c09106eu,0x0c091070u,0x0c091072u,0x0c091074u,
0x0c091076u,0x0c091078u,0x0c09107au,0x0c09107cu,0x0c09107eu,0x0c091080u,0x0c091108u,0x0c09110au,0x0c09110cu,0x0c09110eu,0x0c091110u,0x0c091112u,0x0c091114u,0x0c091116u,0x0c091118u,0x0c09111au,
0x0c09111cu,0x0c09111eu,0x0c091120u,0x0c091122u,0x0c091124u,0x0c091126u,0x0c091128u,0x0c09112au,0x0c09112cu,0x0c09112eu,0x0c091130u,0x0c091132u,0x0c091134u,0x0c091136u,0x0c091138u,0x0c09113au,
0x0c09113cu,0x0c09113eu,0x0c091180u,0x0c091182u,0x0c091184u,0x0c091186u,0x0c091188u,0x0c09118au,0x0c09118cu,0x0c09118eu,0x0c091190u,0x0c091192u,0x0c091194u,0x0c091196u,0x0c091198u,0x0c09119au,
0x0c09119cu,0x0c09119eu,0x0c0911a0u,0x0c0911a2u,0x0c0911a4u,0x0c0911a6u,0x0c0911a8u,0x0c0911aau,0x0c0911acu,0x0c0911aeu,0x0c0911b0u,0x0c0911b2u,0x0c0911b4u,0x0c0911b6u,0x0c091242u,0x0c091244u,
0x0c091246u,0x0c091248u,0x0c09124au,0x0c09124cu,0x0c09124eu,0x0c091250u,0x0c091252u,0x0c091254u,0x0c091256u,0x0c091258u,0x0c09125au,0x0c09125cu,0x0c09125eu,0x0c091260u,0x0c091262u,0x0c091264u,
0x0c091266u,0x0c091268u,0x0c09126au,0x0c09126cu,0x0c09126eu,0x0c091270u,0x0c091272u,0x0c091274u,0x0c091276u,0x0c091278u,0x0c0975d4u,0x0c0975d6u,0x0c0975d8u,0x0c0975dau,0x0c0975dcu,0x0c0975deu,
0x0c0975e0u,0x0c0975e2u,0x0c0975e4u,0x0c0975e6u,0x0c0975e8u,0x0c0975eau,0x0c0975ecu,0x0c0975eeu,0x0c0975f0u,0x0c0975f2u,0x0c0975f4u,0x0c0975f6u,0x0c0975f8u,0x0c0975fau,0x0c0975fcu,0x0c0975feu,
0x0c097600u,0x0c097602u,0x0c097604u,0x0c097606u,0x0c097608u,0x0c09760au,0x0c09760cu,0x0c09760eu,0x0c097610u,0x0c097612u,0x0c097614u,0x0c097616u,0x0c097618u,0x0c09761au,0x0c09761cu,0x0c09761eu,
0x0c097620u,0x0c097622u,0x0c097624u,0x0c097626u,0x0c097628u,0x0c09762au,0x0c097694u,0x0c097696u,0x0c097698u,0x0c09769au,0x0c09769cu,0x0c09769eu,0x0c0976a0u,0x0c0976a2u,0x0c0976a4u,0x0c097aa4u,
0x0c097aa6u,0x0c097aa8u,0x0c097aaau,0x0c097aacu,0x0c097aaeu,0x0c097ab0u,0x0c097ab2u,0x0c097ab4u,0x0c097ab6u,0x0c097ab8u,0x0c097abau,0x0c097abcu,0x0c097abeu,0x0c097ac0u,0x0c097ac2u,0x0c097ac4u,
0x0c097ac6u,0x0c097ac8u,0x0c097acau,0x0c097accu,0x0c097aceu,0x0c097ad0u,0x0c097ad2u,0x0c097ad4u,0x0c097ad6u,0x0c097ad8u,0x0c097adau,0x0c097adcu,0x0c097adeu,0x0c097ae0u,0x0c097ae2u,0x0c097ae4u,
0x0c097ae6u,0x0c097ae8u,0x0c097aeau,0x0c097aecu,0x0c097aeeu,0x0c097af0u,0x0c097af2u,0x0c097af4u,0x0c097af6u,0x0c097af8u,0x0c097afau,0x0c097afcu,0x0c097afeu,0x0c097b00u,0x0c097b02u,0x0c097b04u,
0x0c097b06u,0x0c097b08u,0x0c097b0au,0x0c097b0cu,0x0c097b0eu,0x0c097b10u,0x0c097b12u,0x0c097b14u,0x0c097b16u,0x0c097b18u,0x0c097b1au,0x0c097b1cu,0x0c097b1eu,0x0c097b20u,0x0c097b22u,0x0c097b24u,
0x0c097b26u,0x0c097b28u,0x0c097b2au,0x0c097b2cu,0x0c097b2eu,0x0c097b30u,0x0c097b32u,0x0c097b34u,0x0c097b36u,0x0c097b38u,0x0c097b3au,0x0c097b3cu,0x0c097b3eu,0x0c097b40u,0x0c097b42u,0x0c097b44u,
0x0c097b46u,0x0c097b48u,0x0c097b4au,0x0c097b4cu,0x0c097b4eu,0x0c097b50u,0x0c097b52u,0x0c097b54u,0x0c097b56u,0x0c097b58u,0x0c097b5au,0x0c097b5cu,0x0c097b5eu,0x0c097b60u,0x0c097b62u,0x0c097b64u,
0x0c097b66u,0x0c097b68u,0x0c097b6au,0x0c097b6cu,0x0c097b6eu,0x0c097b70u,0x0c097b9cu,0x0c097b9eu,0x0c097ba0u,0x0c097ba2u,0x0c097ba4u,0x0c097ba6u,0x0c097ba8u,0x0c097baau,0x0c097bacu,0x0c097baeu,
0x0c097bb0u,0x0c097bb2u,0x0c097bb4u,0x0c097bb6u,0x0c097bb8u,0x0c097bbau,0x0c097bbcu,0x0c097bbeu,0x0c097bc0u,0x0c097bc2u,0x0c097bc4u,0x0c097bc6u,0x0c097bc8u,0x0c097bcau,0x0c097bccu,0x0c097bceu,
0x0c097bd0u,0x0c097bd2u,0x0c097bd4u,0x0c097bd6u,0x0c097bd8u,0x0c097bdau,0x0c097bdcu,0x0c097bdeu,0x0c097be0u,0x0c097be2u,0x0c097be4u,0x0c097be6u,0x0c097be8u,0x0c097beau,0x0c097becu,0x0c097beeu,
0x0c097bf0u,0x0c097bf2u,0x0c097bf4u,0x0c097bf6u,0x0c097bf8u,0x0c097bfau,0x0c097bfcu,0x0c097bfeu,0x0c097c00u,0x0c097c02u,0x0c097c04u,0x0c097c06u,0x0c097c08u,0x0c097c0au,0x0c097c0cu,0x0c097c0eu,
0x0c097c10u,0x0c097c12u,0x0c097c14u,0x0c097c16u,0x0c097c18u,0x0c097c1au,0x0c097c1cu,0x0c097c1eu,0x0c097c20u,0x0c097c22u,0x0c097c24u,0x0c097c26u,0x0c097c28u,0x0c097c2au,0x0c097c2cu,0x0c097c2eu,
0x0c097c30u,0x0c097c32u,0x0c097c34u,0x0c097c36u,0x0c097c38u,0x0c097c3au,0x0c097c3cu,0x0c097c3eu,0x0c097c40u,0x0c097c42u,0x0c097c44u,0x0c097c46u,0x0c097c48u,0x0c097c4au,0x0c097c4cu,0x0c097c4eu,
0x0c097c50u,0x0c097c52u,0x0c097c54u,0x0c097c56u,0x0c097c58u,0x0c097c5au,0x0c097c5cu,0x0c097c5eu,0x0c097c60u,0x0c097c62u,0x0c097c64u,0x0c097c66u,0x0c097c68u,0x0c097c6au,0x0c097c6cu,0x0c097c6eu,
0x0c097c70u,0x0c097c72u,0x0c097c74u,0x0c097c76u,0x0c097c78u,0x0c097c7au,0x0c097c7cu,0x0c097c7eu,0x0c097c80u,0x0c097c82u,0x0c097c84u,0x0c097c86u,0x0c097c88u,0x0c097c8au,0x0c097c8cu,0x0c097c8eu,
0x0c097c90u,0x0c097c92u,0x0c097c94u,0x0c097c96u,0x0c097c98u,0x0c097c9au,0x0c097c9cu,0x0c097c9eu,0x0c097ca0u,0x0c097ca2u,0x0c097ca4u,0x0c097ca6u,0x0c097ca8u,0x0c097caau,0x0c097cacu,0x0c097caeu,
0x0c097cb0u,0x0c097cb2u,0x0c097cb4u,0x0c097cb6u,0x0c097cb8u,0x0c097cbau,0x0c097cbcu,0x0c097cbeu,0x0c097cc0u,0x0c097cc2u,0x0c097d18u,0x0c097d1au,0x0c097d1cu,0x0c097d1eu,0x0c097d20u,0x0c097d22u,
0x0c097d24u,0x0c097d26u,0x0c097d28u,0x0c097d2au,0x0c097d2cu,0x0c097d2eu,0x0c097d30u,0x0c097d32u,0x0c097d34u,0x0c097d36u,0x0c097d38u,0x0c097d3au,0x0c097d3cu,0x0c097d3eu,0x0c097d40u,0x0c097d42u,
0x0c097d44u,0x0c097d46u,0x0c097d48u,0x0c097d4au,0x0c097d4cu,0x0c097d4eu,0x0c097d50u,0x0c097d52u,0x0c097d54u,0x0c097d56u,0x0c097d58u,0x0c097d5au,0x0c097d5cu,0x0c097d5eu,0x0c097d60u,0x0c097d62u,
0x0c097d64u,0x0c097d66u,0x0c097d68u,0x0c097d6au,0x0c097d6cu,0x0c097d6eu,0x0c097d70u,0x0c097d72u,0x0c097d74u,0x0c097d76u,0x0c097d78u,0x0c097d7au,0x0c097d7cu,0x0c097d7eu,0x0c097d80u,0x0c097d82u,
0x0c097d84u,0x0c097d86u,0x0c097d88u,0x0c097d8au,0x0c097d8cu,0x0c097d8eu,0x0c097d90u,0x0c097d92u,0x0c097d94u,0x0c097d96u,0x0c097d98u,0x0c097d9au,0x0c097d9cu,0x0c097d9eu,0x0c097da0u,0x0c097da2u,
0x0c097da4u,0x0c097da6u,0x0c097da8u,0x0c097daau,0x0c097dacu,0x0c097daeu,0x0c097db0u,0x0c097db2u,0x0c097db4u,0x0c097db6u,0x0c097db8u,0x0c097dbau,0x0c097dbcu,0x0c097dbeu,0x0c097dc0u,0x0c097dc2u,
0x0c097dc4u,0x0c097dc6u,0x0c097dc8u,0x0c097dcau,0x0c097dccu,0x0c097dceu,0x0c097dd0u,0x0c097dd2u,0x0c097dd4u,0x0c097dd6u,0x0c097dd8u,0x0c097ddau,0x0c097ddcu,0x0c097ddeu,0x0c097de0u,0x0c097de2u,
0x0c097de4u,0x0c097de6u,0x0c097de8u,0x0c097deau,0x0c097decu,0x0c097deeu,0x0c097e0cu,0x0c097e0eu,0x0c097e10u,0x0c097e12u,0x0c097e14u,0x0c097e16u,0x0c097e18u,0x0c097e1au,0x0c097e1cu,0x0c097e1eu,
0x0c097e20u,0x0c097e22u,0x0c097e24u,0x0c097e26u,0x0c097e28u,0x0c097e2au,0x0c097e2cu,0x0c097e2eu,0x0c097e30u,0x0c097e32u,0x0c097e34u,0x0c097e36u,0x0c097e38u,0x0c097e3au,0x0c097e3cu,0x0c097e3eu,
0x0c097e40u,0x0c097e42u,0x0c097e44u,0x0c097e46u,0x0c097e48u,0x0c097e4au,0x0c097e4cu,0x0c097e4eu,0x0c097e50u,0x0c097e52u,0x0c097e54u,0x0c097e56u,0x0c097e58u,0x0c097e5au,0x0c097e5cu,0x0c097e5eu,
0x0c097e60u,0x0c097e62u,0x0c097e64u,0x0c097e66u,0x0c097e68u,0x0c097e6au,0x0c097e6cu,0x0c097e6eu,0x0c097e70u,0x0c097e72u,0x0c097e74u,0x0c097e76u,0x0c097e78u,0x0c097e7au,0x0c097e7cu,0x0c097e7eu,
0x0c097e80u,0x0c097e82u,0x0c097e84u,0x0c097e86u,0x0c097e88u,0x0c097e8au,0x0c097e8cu,0x0c097e8eu,0x0c097e90u,0x0c097e92u,0x0c097e94u,0x0c097e96u,0x0c097e98u,0x0c097e9au,0x0c097e9cu,0x0c097e9eu,
0x0c097ea0u,0x0c097ea2u,0x0c097ea4u,0x0c097eb6u,0x0c097eb8u,0x0c097ebau,0x0c097ebcu,0x0c097ebeu,0x0c097ec0u,0x0c097ec2u,0x0c097ec4u,0x0c097ec6u,0x0c097ec8u,0x0c097ecau,0x0c097eccu,0x0c097eceu,
0x0c097ed0u,0x0c097ed2u,0x0c097ed4u,0x0c097ed6u,0x0c097ed8u,0x0c097edau,0x0c097edcu,0x0c097edeu,0x0c097ee0u,0x0c097ee2u,0x0c097ee4u,0x0c097ee6u,0x0c097ee8u,0x0c097eeau,0x0c097eecu,0x0c097eeeu,
0x0c097ef0u,0x0c097ef2u,0x0c097ef4u,0x0c097ef6u,0x0c097ef8u,0x0c097efau,0x0c097efcu,0x0c097efeu,0x0c097f00u,0x0c097f02u,0x0c097f04u,0x0c097f06u,0x0c097f08u,0x0c097f0au,0x0c097f0cu,0x0c097f0eu,
0x0c097f10u,0x0c097f12u,0x0c097f14u,0x0c097f16u,0x0c097f18u,0x0c097f1au,0x0c097f1cu,0x0c097f1eu,0x0c097f20u,0x0c097f22u,0x0c097f24u,0x0c097f26u,0x0c097f28u,0x0c097f2au,0x0c097f2cu,0x0c097f2eu,
0x0c097f30u,0x0c097f32u,0x0c097f34u,0x0c097f36u,0x0c097f38u,0x0c097f3au,0x0c097f3cu,0x0c097f3eu,0x0c097f40u,0x0c097f42u,0x0c097f44u,0x0c097f46u,0x0c097f48u,0x0c097f4au,0x0c097f4cu,0x0c097f4eu,
0x0c097f50u,0x0c097f52u,0x0c097f54u,0x0c097f56u,0x0c097f58u,0x0c097f5au,0x0c097f5cu,0x0c097f5eu,0x0c097f60u,0x0c097f62u,0x0c097f64u,0x0c097f66u,0x0c097f68u,0x0c097f6au,0x0c097f6cu,0x0c097f6eu,
0x0c097f70u,0x0c097f72u,0x0c097f74u,0x0c097f76u,0x0c097f78u,0x0c097f9cu,0x0c097f9eu,0x0c097fa0u,0x0c097fa2u,0x0c097fa4u,0x0c097fa6u,0x0c097fa8u,0x0c097faau,0x0c097facu,0x0c097faeu,0x0c097fb0u,
0x0c097fb2u,0x0c097fb4u,0x0c097fb6u,0x0c097fb8u,0x0c097fbau,0x0c097fbcu,0x0c097fbeu,0x0c097fc0u,0x0c097fc2u,0x0c097fc4u,0x0c097fc6u,0x0c097fc8u,0x0c097fcau,0x0c097fccu,0x0c097fceu,0x0c097fd0u,
0x0c097fd2u,0x0c097fd4u,0x0c097fd6u,0x0c097fd8u,0x0c097fdau,0x0c097fdcu,0x0c097fdeu,0x0c097fe0u,0x0c097fe2u,0x0c097fe4u,0x0c097fe6u,0x0c097fe8u,0x0c097feau,0x0c097fecu,0x0c097feeu,0x0c097ff0u,
0x0c097ff2u,0x0c099d62u,0x0c099d64u,0x0c099d66u,0x0c099d68u,0x0c099d6au,0x0c099d6cu,0x0c099d6eu,0x0c099d70u,0x0c099d72u,0x0c099d74u,0x0c099d76u,0x0c099d78u,0x0c099d7au,0x0c099d7cu,0x0c099d7eu,
0x0c099d80u,0x0c099d82u,0x0c099d84u,0x0c099d86u,0x0c099d88u,0x0c099d8au,0x0c099d8cu,0x0c099d8eu,0x0c099d90u,0x0c099d92u,0x0c099d94u,0x0c099d96u,0x0c099d98u,0x0c099d9au,0x0c099d9cu,0x0c099d9eu,
0x0c099de0u,0x0c099de2u,0x0c099de4u,0x0c099de6u,0x0c099de8u,0x0c099deau,0x0c099decu,0x0c099deeu,0x0c099df0u,0x0c099df2u,0x0c099df4u,0x0c099df6u,0x0c099df8u,0x0c099dfau,0x0c099dfcu,0x0c099dfeu,
0x0c099e00u,0x0c099e02u,0x0c099e04u,0x0c099e06u,0x0c099e08u,0x0c099e0au,0x0c099e0cu,0x0c099e0eu,0x0c099e10u,0x0c099e12u,0x0c099e14u,0x0c099e16u,0x0c099e18u,0x0c099e1au,0x0c099e1cu,0x0c099e1eu,
0x0c099e20u,0x0c099e22u,0x0c099e24u,0x0c099e26u,0x0c099e28u,0x0c099e2au,0x0c099e2cu,0x0c099e2eu,0x0c099e30u,0x0c099e32u,0x0c099e34u,0x0c099e36u,0x0c099e38u,0x0c099e3au,0x0c099e3cu,0x0c099e3eu,
0x0c099e40u,0x0c099e42u,0x0c099e44u,0x0c099e46u,0x0c099e48u,0x0c099e4au,0x0c099e4cu,0x0c099e4eu,0x0c099e50u,0x0c099e52u,0x0c099e54u,0x0c099e56u,0x0c099e58u,0x0c099e5au,0x0c099e5cu,0x0c099e5eu,
0x0c099e60u,0x0c099e62u,0x0c099e64u,0x0c099e66u,0x0c099e68u,0x0c099e6au,0x0c099e6cu,0x0c099e6eu,0x0c099e70u,0x0c099e72u,0x0c099e74u,0x0c099e76u,0x0c099e78u,0x0c099e7au,0x0c099e7cu,0x0c099e7eu,
0x0c099e80u,0x0c099e82u,0x0c099e84u,0x0c099e86u,0x0c099e88u,0x0c099e8au,0x0c099e8cu,0x0c099e8eu,0x0c099e90u,0x0c099e92u,0x0c099e94u,0x0c099e96u,0x0c099e98u,0x0c099e9au,0x0c099e9cu,0x0c099e9eu,
0x0c099ea0u,0x0c099ea2u,0x0c099ea4u,0x0c099ea6u,0x0c099ea8u,0x0c099eaau,0x0c099eacu,0x0c099eaeu,0x0c099eb0u,0x0c099eb2u,0x0c099eb4u,0x0c099eb6u,0x0c099eb8u,0x0c099ebau,0x0c099ebcu,0x0c099ebeu,
0x0c099ec0u,0x0c099ec2u,0x0c099ec4u,0x0c099ec6u,0x0c099ec8u,0x0c099ecau,0x0c099eccu,0x0c099eceu,0x0c099ed0u,0x0c099ed2u,0x0c099ed4u,0x0c099ed6u,0x0c099f00u,0x0c099f02u,0x0c099f04u,0x0c099f06u,
0x0c099f08u,0x0c099f0au,0x0c099f0cu,0x0c099f0eu,0x0c099f10u,0x0c099f12u,0x0c099f14u,0x0c099f16u,0x0c099f18u,0x0c099f1au,0x0c099f1cu,0x0c099f1eu,0x0c099f20u,0x0c099f22u,0x0c099f24u,0x0c099f26u,
0x0c099f28u,0x0c099f2au,0x0c099f2cu,0x0c099f2eu,0x0c099f30u,0x0c099f32u,0x0c099f34u,0x0c099f36u,0x0c099f38u,0x0c099f3au,0x0c099f3cu,0x0c099f3eu,0x0c099f40u,0x0c099f42u,0x0c099f44u,0x0c099f46u,
0x0c099f48u,0x0c099f4au,0x0c099f4cu,0x0c099f4eu,0x0c099f50u,0x0c099f52u,0x0c099f54u,0x0c099f56u,0x0c099f58u,0x0c099f5au,0x0c099f5cu,0x0c099f5eu,0x0c099f60u,0x0c099f62u,0x0c099f64u,0x0c099f66u,
0x0c099f68u,0x0c099f6au,0x0c099f6cu,0x0c099f6eu,0x0c099f70u,0x0c099f72u,0x0c099f74u,0x0c099f76u,0x0c099f78u,0x0c099f7au,0x0c099f7cu,0x0c099f7eu,0x0c099f80u,0x0c099f82u,0x0c099f84u,0x0c099f86u,
0x0c099f88u,0x0c099f8au,0x0c099f8cu,0x0c099f8eu,0x0c099f90u,0x0c099f92u,0x0c099f94u,0x0c099f96u,0x0c099f98u,0x0c099f9au,0x0c099f9cu,0x0c099f9eu,0x0c099fa0u,0x0c099fa2u,0x0c099fa4u,0x0c099fa6u,
0x0c099fa8u,0x0c099faau,0x0c099facu,0x0c099faeu,0x0c099fb0u,0x0c099fb2u,0x0c099fb4u,0x0c099fb6u,0x0c099fb8u,0x0c099fbau,0x0c099fbcu,0x0c099fbeu,0x0c099fc0u,0x0c099fc2u,0x0c099fc4u,0x0c099fc6u,
0x0c099fc8u,0x0c099fcau,0x0c099fccu,0x0c099fceu,0x0c099fd0u,0x0c099fd2u,0x0c099fd4u,0x0c099fd6u,0x0c099fd8u,0x0c099fdau,0x0c099fdcu,0x0c099fdeu,0x0c099fe0u,0x0c099fe2u,0x0c099fe4u,0x0c099fe6u,
0x0c099fe8u,0x0c099feau,0x0c099fecu,0x0c099feeu,0x0c099ff0u,0x0c099ff2u,0x0c099ff4u,0x0c099ff6u,0x0c099ff8u,0x0c09a01cu,0x0c09a01eu,0x0c09a020u,0x0c09a022u,0x0c09a024u,0x0c09a026u,0x0c09a028u,
0x0c09a02au,0x0c09a02cu,0x0c09a02eu,0x0c09a030u,0x0c09a032u,0x0c09a034u,0x0c09a036u,0x0c09a038u,0x0c09a03au,0x0c09a03cu,0x0c09a03eu,0x0c09a040u,0x0c09a042u,0x0c09a044u,0x0c09a046u,0x0c09a048u,
0x0c09a04au,0x0c09a04cu,0x0c09a04eu,0x0c09a050u,0x0c09a052u,0x0c09a054u,0x0c09a056u,0x0c09a058u,0x0c09a05au,0x0c09a05cu,0x0c09a05eu,0x0c09a060u,0x0c09a062u,0x0c09a064u,0x0c09a066u,0x0c09a068u,
0x0c09a06au,0x0c09a06cu,0x0c09a06eu,0x0c09a070u,0x0c09a072u,0x0c09a074u,0x0c09a076u,0x0c09a078u,0x0c09a07au,0x0c09a07cu,0x0c09a07eu,0x0c09a080u,0x0c09a082u,0x0c09a084u,
};
static const uint32_t claim_pcs[]={
0x0c07d88au,0x0c08230cu,0x0c08230eu,0x0c082310u,0x0c082312u,0x0c082314u,0x0c082316u,0x0c082318u,0x0c08231au,0x0c0831eau,0x0c0831ecu,0x0c0831eeu,0x0c0831f0u,0x0c0831f2u,0x0c0831f4u,0x0c0831f6u,
0x0c091028u,0x0c091108u,0x0c091180u,0x0c091242u,0x0c0975d4u,0x0c0975d6u,0x0c0975d8u,0x0c0975dau,0x0c097694u,0x0c097696u,0x0c097698u,0x0c09769au,0x0c09769cu,0x0c09769eu,0x0c0976a0u,0x0c0976a2u,
0x0c0976a4u,0x0c097aa4u,0x0c097aa6u,0x0c097aa8u,0x0c097aaau,0x0c097aacu,0x0c097aaeu,0x0c097ab0u,0x0c097ab2u,0x0c097ab4u,0x0c097ab6u,0x0c097ab8u,0x0c097abau,0x0c099d62u,0x0c099d64u,0x0c099d66u,
0x0c099d68u,0x0c099d6au,0x0c099d6cu,0x0c099d6eu,0x0c099d70u,0x0c099d72u,
};
int vf3_c101_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(claim_pcs)/sizeof(claim_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(claim_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(claim_pcs)/sizeof(claim_pcs[0]) && claim_pcs[lo]==pc;
}
