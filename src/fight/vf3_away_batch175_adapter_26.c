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
int vf3_away_batch175_adapter_26(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c098040u: goto P_0c098040;
case 0x0c098042u: goto P_0c098042;
case 0x0c098044u: goto P_0c098044;
case 0x0c098046u: goto P_0c098046;
case 0x0c098048u: goto P_0c098048;
case 0x0c09804au: goto P_0c09804a;
case 0x0c09804cu: goto P_0c09804c;
case 0x0c09804eu: goto P_0c09804e;
case 0x0c098050u: goto P_0c098050;
case 0x0c098052u: goto P_0c098052;
case 0x0c098054u: goto P_0c098054;
case 0x0c098056u: goto P_0c098056;
case 0x0c098058u: goto P_0c098058;
case 0x0c09805au: goto P_0c09805a;
case 0x0c09805cu: goto P_0c09805c;
case 0x0c09805eu: goto P_0c09805e;
case 0x0c098060u: goto P_0c098060;
case 0x0c098062u: goto P_0c098062;
case 0x0c098064u: goto P_0c098064;
case 0x0c098066u: goto P_0c098066;
case 0x0c098068u: goto P_0c098068;
case 0x0c09806au: goto P_0c09806a;
case 0x0c09806cu: goto P_0c09806c;
case 0x0c09806eu: goto P_0c09806e;
case 0x0c098070u: goto P_0c098070;
case 0x0c098072u: goto P_0c098072;
case 0x0c098074u: goto P_0c098074;
case 0x0c098076u: goto P_0c098076;
case 0x0c098078u: goto P_0c098078;
case 0x0c09807au: goto P_0c09807a;
case 0x0c09807cu: goto P_0c09807c;
case 0x0c09807eu: goto P_0c09807e;
case 0x0c098080u: goto P_0c098080;
case 0x0c098082u: goto P_0c098082;
case 0x0c098084u: goto P_0c098084;
case 0x0c098086u: goto P_0c098086;
case 0x0c098088u: goto P_0c098088;
case 0x0c0980c0u: goto P_0c0980c0;
case 0x0c0980c2u: goto P_0c0980c2;
case 0x0c0980c4u: goto P_0c0980c4;
case 0x0c0980c6u: goto P_0c0980c6;
case 0x0c0980c8u: goto P_0c0980c8;
case 0x0c0980cau: goto P_0c0980ca;
case 0x0c0980ccu: goto P_0c0980cc;
case 0x0c0980ceu: goto P_0c0980ce;
case 0x0c0980d0u: goto P_0c0980d0;
case 0x0c0980d2u: goto P_0c0980d2;
case 0x0c0980d4u: goto P_0c0980d4;
case 0x0c0980d6u: goto P_0c0980d6;
case 0x0c0980d8u: goto P_0c0980d8;
case 0x0c0980dau: goto P_0c0980da;
case 0x0c0980dcu: goto P_0c0980dc;
case 0x0c0980deu: goto P_0c0980de;
case 0x0c0980e0u: goto P_0c0980e0;
case 0x0c0980e2u: goto P_0c0980e2;
case 0x0c0980e4u: goto P_0c0980e4;
case 0x0c0980e6u: goto P_0c0980e6;
case 0x0c0980e8u: goto P_0c0980e8;
case 0x0c0980eau: goto P_0c0980ea;
case 0x0c0980ecu: goto P_0c0980ec;
case 0x0c0980eeu: goto P_0c0980ee;
case 0x0c0980f0u: goto P_0c0980f0;
case 0x0c0980f2u: goto P_0c0980f2;
case 0x0c0980f4u: goto P_0c0980f4;
case 0x0c0980f6u: goto P_0c0980f6;
case 0x0c0980f8u: goto P_0c0980f8;
case 0x0c0980fau: goto P_0c0980fa;
case 0x0c0980fcu: goto P_0c0980fc;
case 0x0c0980feu: goto P_0c0980fe;
case 0x0c098100u: goto P_0c098100;
case 0x0c098102u: goto P_0c098102;
case 0x0c098104u: goto P_0c098104;
case 0x0c098106u: goto P_0c098106;
case 0x0c098108u: goto P_0c098108;
case 0x0c09810au: goto P_0c09810a;
case 0x0c09810cu: goto P_0c09810c;
case 0x0c09810eu: goto P_0c09810e;
case 0x0c098110u: goto P_0c098110;
case 0x0c098112u: goto P_0c098112;
case 0x0c098114u: goto P_0c098114;
case 0x0c098116u: goto P_0c098116;
case 0x0c098118u: goto P_0c098118;
case 0x0c09811au: goto P_0c09811a;
case 0x0c09811cu: goto P_0c09811c;
case 0x0c09811eu: goto P_0c09811e;
case 0x0c098120u: goto P_0c098120;
case 0x0c098122u: goto P_0c098122;
case 0x0c098124u: goto P_0c098124;
case 0x0c098126u: goto P_0c098126;
case 0x0c098128u: goto P_0c098128;
case 0x0c09812au: goto P_0c09812a;
case 0x0c09812cu: goto P_0c09812c;
case 0x0c09812eu: goto P_0c09812e;
case 0x0c098130u: goto P_0c098130;
case 0x0c098132u: goto P_0c098132;
case 0x0c098134u: goto P_0c098134;
case 0x0c098136u: goto P_0c098136;
case 0x0c098138u: goto P_0c098138;
case 0x0c09813au: goto P_0c09813a;
case 0x0c09813cu: goto P_0c09813c;
case 0x0c09813eu: goto P_0c09813e;
case 0x0c098140u: goto P_0c098140;
case 0x0c098142u: goto P_0c098142;
case 0x0c098144u: goto P_0c098144;
case 0x0c098146u: goto P_0c098146;
case 0x0c098148u: goto P_0c098148;
case 0x0c09814au: goto P_0c09814a;
case 0x0c09814cu: goto P_0c09814c;
case 0x0c09814eu: goto P_0c09814e;
case 0x0c098150u: goto P_0c098150;
case 0x0c098152u: goto P_0c098152;
case 0x0c098154u: goto P_0c098154;
case 0x0c098156u: goto P_0c098156;
case 0x0c098158u: goto P_0c098158;
case 0x0c09815au: goto P_0c09815a;
case 0x0c09815cu: goto P_0c09815c;
case 0x0c09815eu: goto P_0c09815e;
case 0x0c098160u: goto P_0c098160;
case 0x0c098162u: goto P_0c098162;
case 0x0c098164u: goto P_0c098164;
case 0x0c098166u: goto P_0c098166;
case 0x0c098168u: goto P_0c098168;
case 0x0c09816au: goto P_0c09816a;
case 0x0c09816cu: goto P_0c09816c;
case 0x0c09816eu: goto P_0c09816e;
case 0x0c098170u: goto P_0c098170;
case 0x0c098172u: goto P_0c098172;
case 0x0c098174u: goto P_0c098174;
case 0x0c098176u: goto P_0c098176;
case 0x0c098178u: goto P_0c098178;
case 0x0c09817au: goto P_0c09817a;
case 0x0c09817cu: goto P_0c09817c;
case 0x0c09817eu: goto P_0c09817e;
case 0x0c098180u: goto P_0c098180;
case 0x0c098182u: goto P_0c098182;
case 0x0c098184u: goto P_0c098184;
case 0x0c098186u: goto P_0c098186;
case 0x0c098188u: goto P_0c098188;
case 0x0c09818au: goto P_0c09818a;
case 0x0c09818cu: goto P_0c09818c;
case 0x0c09818eu: goto P_0c09818e;
case 0x0c098190u: goto P_0c098190;
case 0x0c098192u: goto P_0c098192;
case 0x0c098194u: goto P_0c098194;
case 0x0c098196u: goto P_0c098196;
case 0x0c098198u: goto P_0c098198;
case 0x0c09819au: goto P_0c09819a;
case 0x0c09819cu: goto P_0c09819c;
case 0x0c09819eu: goto P_0c09819e;
case 0x0c0981a0u: goto P_0c0981a0;
case 0x0c0981a2u: goto P_0c0981a2;
case 0x0c0981a4u: goto P_0c0981a4;
case 0x0c0981a6u: goto P_0c0981a6;
case 0x0c0981a8u: goto P_0c0981a8;
case 0x0c0981aau: goto P_0c0981aa;
case 0x0c0981acu: goto P_0c0981ac;
case 0x0c0981aeu: goto P_0c0981ae;
case 0x0c0981b0u: goto P_0c0981b0;
case 0x0c0981b2u: goto P_0c0981b2;
case 0x0c0981b4u: goto P_0c0981b4;
case 0x0c0981b6u: goto P_0c0981b6;
case 0x0c0981b8u: goto P_0c0981b8;
case 0x0c0981bau: goto P_0c0981ba;
case 0x0c0981bcu: goto P_0c0981bc;
case 0x0c0981beu: goto P_0c0981be;
case 0x0c0981c0u: goto P_0c0981c0;
case 0x0c0981c2u: goto P_0c0981c2;
case 0x0c0981c4u: goto P_0c0981c4;
case 0x0c0981c6u: goto P_0c0981c6;
case 0x0c0981c8u: goto P_0c0981c8;
case 0x0c0981cau: goto P_0c0981ca;
case 0x0c0981ccu: goto P_0c0981cc;
case 0x0c0981ceu: goto P_0c0981ce;
case 0x0c0981d0u: goto P_0c0981d0;
case 0x0c0981d2u: goto P_0c0981d2;
case 0x0c0981d4u: goto P_0c0981d4;
case 0x0c0981d6u: goto P_0c0981d6;
case 0x0c09822cu: goto P_0c09822c;
case 0x0c09822eu: goto P_0c09822e;
case 0x0c098230u: goto P_0c098230;
case 0x0c098232u: goto P_0c098232;
case 0x0c098234u: goto P_0c098234;
case 0x0c098236u: goto P_0c098236;
case 0x0c098238u: goto P_0c098238;
case 0x0c09823au: goto P_0c09823a;
case 0x0c09823cu: goto P_0c09823c;
case 0x0c09823eu: goto P_0c09823e;
case 0x0c098240u: goto P_0c098240;
case 0x0c098242u: goto P_0c098242;
case 0x0c098244u: goto P_0c098244;
case 0x0c098246u: goto P_0c098246;
case 0x0c098248u: goto P_0c098248;
case 0x0c09824au: goto P_0c09824a;
case 0x0c09824cu: goto P_0c09824c;
case 0x0c09824eu: goto P_0c09824e;
case 0x0c098250u: goto P_0c098250;
case 0x0c098252u: goto P_0c098252;
case 0x0c098254u: goto P_0c098254;
case 0x0c098256u: goto P_0c098256;
case 0x0c098258u: goto P_0c098258;
case 0x0c09825au: goto P_0c09825a;
case 0x0c09825cu: goto P_0c09825c;
case 0x0c09825eu: goto P_0c09825e;
case 0x0c098260u: goto P_0c098260;
case 0x0c098262u: goto P_0c098262;
case 0x0c098264u: goto P_0c098264;
case 0x0c098266u: goto P_0c098266;
case 0x0c098268u: goto P_0c098268;
case 0x0c09826au: goto P_0c09826a;
case 0x0c09826cu: goto P_0c09826c;
case 0x0c09826eu: goto P_0c09826e;
case 0x0c098270u: goto P_0c098270;
case 0x0c098272u: goto P_0c098272;
case 0x0c098274u: goto P_0c098274;
case 0x0c098276u: goto P_0c098276;
case 0x0c098278u: goto P_0c098278;
case 0x0c09827au: goto P_0c09827a;
case 0x0c09827cu: goto P_0c09827c;
case 0x0c09827eu: goto P_0c09827e;
case 0x0c098280u: goto P_0c098280;
case 0x0c098282u: goto P_0c098282;
case 0x0c098284u: goto P_0c098284;
case 0x0c098286u: goto P_0c098286;
case 0x0c098288u: goto P_0c098288;
case 0x0c09828au: goto P_0c09828a;
case 0x0c09828cu: goto P_0c09828c;
case 0x0c09828eu: goto P_0c09828e;
case 0x0c098290u: goto P_0c098290;
case 0x0c098292u: goto P_0c098292;
case 0x0c098294u: goto P_0c098294;
case 0x0c098296u: goto P_0c098296;
case 0x0c098298u: goto P_0c098298;
case 0x0c09829au: goto P_0c09829a;
case 0x0c09829cu: goto P_0c09829c;
case 0x0c09829eu: goto P_0c09829e;
case 0x0c0982a0u: goto P_0c0982a0;
case 0x0c0982a2u: goto P_0c0982a2;
case 0x0c0982a4u: goto P_0c0982a4;
case 0x0c0982a6u: goto P_0c0982a6;
case 0x0c0982a8u: goto P_0c0982a8;
case 0x0c0982aau: goto P_0c0982aa;
case 0x0c0982acu: goto P_0c0982ac;
case 0x0c0982aeu: goto P_0c0982ae;
case 0x0c0982b0u: goto P_0c0982b0;
case 0x0c0982b2u: goto P_0c0982b2;
case 0x0c0982b4u: goto P_0c0982b4;
case 0x0c0982b6u: goto P_0c0982b6;
case 0x0c0982b8u: goto P_0c0982b8;
case 0x0c0982bau: goto P_0c0982ba;
case 0x0c0982bcu: goto P_0c0982bc;
case 0x0c0982beu: goto P_0c0982be;
case 0x0c0982c0u: goto P_0c0982c0;
case 0x0c0982c2u: goto P_0c0982c2;
case 0x0c0982c4u: goto P_0c0982c4;
case 0x0c0982c6u: goto P_0c0982c6;
case 0x0c0982c8u: goto P_0c0982c8;
case 0x0c0982cau: goto P_0c0982ca;
case 0x0c0982ccu: goto P_0c0982cc;
case 0x0c0982ceu: goto P_0c0982ce;
case 0x0c0982d0u: goto P_0c0982d0;
case 0x0c0982d2u: goto P_0c0982d2;
case 0x0c0982d4u: goto P_0c0982d4;
case 0x0c0982d6u: goto P_0c0982d6;
case 0x0c0982d8u: goto P_0c0982d8;
case 0x0c0982dau: goto P_0c0982da;
case 0x0c0982dcu: goto P_0c0982dc;
case 0x0c0982deu: goto P_0c0982de;
case 0x0c0982e0u: goto P_0c0982e0;
case 0x0c0982e2u: goto P_0c0982e2;
case 0x0c0982e4u: goto P_0c0982e4;
case 0x0c0982e6u: goto P_0c0982e6;
case 0x0c0982e8u: goto P_0c0982e8;
case 0x0c0982eau: goto P_0c0982ea;
case 0x0c0982ecu: goto P_0c0982ec;
case 0x0c0982eeu: goto P_0c0982ee;
case 0x0c0982f0u: goto P_0c0982f0;
case 0x0c0982f2u: goto P_0c0982f2;
case 0x0c0982f4u: goto P_0c0982f4;
case 0x0c0982f6u: goto P_0c0982f6;
case 0x0c0982f8u: goto P_0c0982f8;
case 0x0c0982fau: goto P_0c0982fa;
case 0x0c0982fcu: goto P_0c0982fc;
case 0x0c0982feu: goto P_0c0982fe;
case 0x0c098300u: goto P_0c098300;
case 0x0c098302u: goto P_0c098302;
case 0x0c098304u: goto P_0c098304;
case 0x0c098306u: goto P_0c098306;
case 0x0c098308u: goto P_0c098308;
case 0x0c09830au: goto P_0c09830a;
case 0x0c09830cu: goto P_0c09830c;
case 0x0c09830eu: goto P_0c09830e;
case 0x0c098310u: goto P_0c098310;
case 0x0c098312u: goto P_0c098312;
case 0x0c098314u: goto P_0c098314;
case 0x0c098316u: goto P_0c098316;
case 0x0c098318u: goto P_0c098318;
case 0x0c09831au: goto P_0c09831a;
case 0x0c09831cu: goto P_0c09831c;
case 0x0c09831eu: goto P_0c09831e;
case 0x0c098320u: goto P_0c098320;
case 0x0c098322u: goto P_0c098322;
case 0x0c098324u: goto P_0c098324;
case 0x0c098326u: goto P_0c098326;
case 0x0c098328u: goto P_0c098328;
case 0x0c09832au: goto P_0c09832a;
case 0x0c09832cu: goto P_0c09832c;
case 0x0c09832eu: goto P_0c09832e;
case 0x0c098330u: goto P_0c098330;
case 0x0c098332u: goto P_0c098332;
case 0x0c098334u: goto P_0c098334;
case 0x0c098336u: goto P_0c098336;
case 0x0c098338u: goto P_0c098338;
case 0x0c09833au: goto P_0c09833a;
case 0x0c09833cu: goto P_0c09833c;
case 0x0c09833eu: goto P_0c09833e;
case 0x0c098340u: goto P_0c098340;
case 0x0c098342u: goto P_0c098342;
case 0x0c098344u: goto P_0c098344;
case 0x0c098346u: goto P_0c098346;
case 0x0c098348u: goto P_0c098348;
case 0x0c09834au: goto P_0c09834a;
case 0x0c09834cu: goto P_0c09834c;
case 0x0c09834eu: goto P_0c09834e;
case 0x0c098350u: goto P_0c098350;
case 0x0c098352u: goto P_0c098352;
case 0x0c098354u: goto P_0c098354;
case 0x0c098356u: goto P_0c098356;
case 0x0c098358u: goto P_0c098358;
case 0x0c09835au: goto P_0c09835a;
case 0x0c098370u: goto P_0c098370;
case 0x0c098372u: goto P_0c098372;
case 0x0c098374u: goto P_0c098374;
case 0x0c098376u: goto P_0c098376;
case 0x0c098378u: goto P_0c098378;
case 0x0c09837au: goto P_0c09837a;
case 0x0c09837cu: goto P_0c09837c;
case 0x0c09837eu: goto P_0c09837e;
case 0x0c098380u: goto P_0c098380;
case 0x0c098382u: goto P_0c098382;
case 0x0c098384u: goto P_0c098384;
case 0x0c098386u: goto P_0c098386;
case 0x0c098388u: goto P_0c098388;
case 0x0c09838au: goto P_0c09838a;
case 0x0c09838cu: goto P_0c09838c;
case 0x0c09838eu: goto P_0c09838e;
case 0x0c098390u: goto P_0c098390;
case 0x0c098392u: goto P_0c098392;
case 0x0c098394u: goto P_0c098394;
case 0x0c098396u: goto P_0c098396;
case 0x0c098398u: goto P_0c098398;
case 0x0c09839au: goto P_0c09839a;
case 0x0c09839cu: goto P_0c09839c;
case 0x0c09839eu: goto P_0c09839e;
case 0x0c0983a0u: goto P_0c0983a0;
case 0x0c0983a2u: goto P_0c0983a2;
case 0x0c0983a4u: goto P_0c0983a4;
case 0x0c0983a6u: goto P_0c0983a6;
case 0x0c0983a8u: goto P_0c0983a8;
case 0x0c0983aau: goto P_0c0983aa;
case 0x0c0983acu: goto P_0c0983ac;
case 0x0c0983aeu: goto P_0c0983ae;
case 0x0c0983b0u: goto P_0c0983b0;
case 0x0c0983b2u: goto P_0c0983b2;
case 0x0c0983b4u: goto P_0c0983b4;
case 0x0c0983b6u: goto P_0c0983b6;
case 0x0c0983b8u: goto P_0c0983b8;
case 0x0c0983bau: goto P_0c0983ba;
case 0x0c0983bcu: goto P_0c0983bc;
case 0x0c0983beu: goto P_0c0983be;
case 0x0c0983c0u: goto P_0c0983c0;
case 0x0c0983c2u: goto P_0c0983c2;
case 0x0c0983c4u: goto P_0c0983c4;
case 0x0c0983c6u: goto P_0c0983c6;
case 0x0c0983c8u: goto P_0c0983c8;
case 0x0c0983cau: goto P_0c0983ca;
case 0x0c0983ccu: goto P_0c0983cc;
case 0x0c0983ceu: goto P_0c0983ce;
case 0x0c0983d0u: goto P_0c0983d0;
case 0x0c0983d2u: goto P_0c0983d2;
case 0x0c0983d4u: goto P_0c0983d4;
case 0x0c0983d6u: goto P_0c0983d6;
case 0x0c0983d8u: goto P_0c0983d8;
case 0x0c0983dau: goto P_0c0983da;
case 0x0c0983dcu: goto P_0c0983dc;
case 0x0c0983deu: goto P_0c0983de;
case 0x0c0983e0u: goto P_0c0983e0;
case 0x0c0983e2u: goto P_0c0983e2;
case 0x0c0983e4u: goto P_0c0983e4;
case 0x0c0983e6u: goto P_0c0983e6;
case 0x0c0983e8u: goto P_0c0983e8;
case 0x0c0983eau: goto P_0c0983ea;
case 0x0c0983ecu: goto P_0c0983ec;
case 0x0c0983eeu: goto P_0c0983ee;
case 0x0c0983f0u: goto P_0c0983f0;
case 0x0c0983f2u: goto P_0c0983f2;
case 0x0c0983f4u: goto P_0c0983f4;
case 0x0c0983f6u: goto P_0c0983f6;
case 0x0c0983f8u: goto P_0c0983f8;
case 0x0c0983fau: goto P_0c0983fa;
case 0x0c0983fcu: goto P_0c0983fc;
case 0x0c0983feu: goto P_0c0983fe;
case 0x0c098400u: goto P_0c098400;
case 0x0c098402u: goto P_0c098402;
case 0x0c098404u: goto P_0c098404;
case 0x0c098406u: goto P_0c098406;
case 0x0c098408u: goto P_0c098408;
case 0x0c09840au: goto P_0c09840a;
case 0x0c09840cu: goto P_0c09840c;
case 0x0c09840eu: goto P_0c09840e;
case 0x0c098410u: goto P_0c098410;
case 0x0c098412u: goto P_0c098412;
case 0x0c098414u: goto P_0c098414;
case 0x0c098416u: goto P_0c098416;
case 0x0c098418u: goto P_0c098418;
case 0x0c09841au: goto P_0c09841a;
case 0x0c09841cu: goto P_0c09841c;
case 0x0c09841eu: goto P_0c09841e;
case 0x0c098420u: goto P_0c098420;
case 0x0c098422u: goto P_0c098422;
case 0x0c098424u: goto P_0c098424;
case 0x0c098426u: goto P_0c098426;
case 0x0c098428u: goto P_0c098428;
case 0x0c09842au: goto P_0c09842a;
case 0x0c09842cu: goto P_0c09842c;
case 0x0c09842eu: goto P_0c09842e;
case 0x0c098430u: goto P_0c098430;
case 0x0c098432u: goto P_0c098432;
case 0x0c0a13a4u: goto P_0c0a13a4;
case 0x0c0a13a6u: goto P_0c0a13a6;
case 0x0c0a13a8u: goto P_0c0a13a8;
case 0x0c0a13aau: goto P_0c0a13aa;
case 0x0c0a13acu: goto P_0c0a13ac;
case 0x0c0a13aeu: goto P_0c0a13ae;
case 0x0c0a13b0u: goto P_0c0a13b0;
case 0x0c0a13b2u: goto P_0c0a13b2;
case 0x0c0a13b4u: goto P_0c0a13b4;
case 0x0c0a13b6u: goto P_0c0a13b6;
case 0x0c0a13b8u: goto P_0c0a13b8;
case 0x0c0a13bau: goto P_0c0a13ba;
case 0x0c0a13bcu: goto P_0c0a13bc;
case 0x0c0a13beu: goto P_0c0a13be;
case 0x0c0a13c0u: goto P_0c0a13c0;
default: return vf3_matrix_family(target,s,ram);
}
P_0c098040: /* original 2fe6, guest PC 0x0c098040 */
if(!s->budget--) { s->failed_pc=0x0c098040u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098042;
P_0c098042: /* original 4f22, guest PC 0x0c098042 */
if(!s->budget--) { s->failed_pc=0x0c098042u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c098044;
P_0c098044: /* original d31a, guest PC 0x0c098044 */
if(!s->budget--) { s->failed_pc=0x0c098044u; return 0; }
r[3]=read(ram,0x0c0980b0u,4);
goto P_0c098046;
P_0c098046: /* original d419, guest PC 0x0c098046 */
if(!s->budget--) { s->failed_pc=0x0c098046u; return 0; }
r[4]=read(ram,0x0c0980acu,4);
goto P_0c098048;
P_0c098048: /* original 430b, guest PC 0x0c098048 */
if(!s->budget--) { s->failed_pc=0x0c098048u; return 0; }
target=r[3];
r[16]=code_base|0x0c09804cu;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09804cu) { target=s->pc; goto dispatch; }
goto P_0c09804c;
P_0c09804a: /* original e500, guest PC 0x0c09804a */
if(!s->budget--) { s->failed_pc=0x0c09804au; return 0; }
r[5]=0x00000000u;
goto P_0c09804c;
P_0c09804c: /* original d21a, guest PC 0x0c09804c */
if(!s->budget--) { s->failed_pc=0x0c09804cu; return 0; }
r[2]=read(ram,0x0c0980b8u,4);
goto P_0c09804e;
P_0c09804e: /* original de19, guest PC 0x0c09804e */
if(!s->budget--) { s->failed_pc=0x0c09804eu; return 0; }
r[14]=read(ram,0x0c0980b4u,4);
goto P_0c098050;
P_0c098050: /* original 420b, guest PC 0x0c098050 */
if(!s->budget--) { s->failed_pc=0x0c098050u; return 0; }
target=r[2];
r[16]=code_base|0x0c098054u;
r[4]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098054u) { target=s->pc; goto dispatch; }
goto P_0c098054;
P_0c098052: /* original 54e4, guest PC 0x0c098052 */
if(!s->budget--) { s->failed_pc=0x0c098052u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c098054;
P_0c098054: /* original d318, guest PC 0x0c098054 */
if(!s->budget--) { s->failed_pc=0x0c098054u; return 0; }
r[3]=read(ram,0x0c0980b8u,4);
goto P_0c098056;
P_0c098056: /* original 430b, guest PC 0x0c098056 */
if(!s->budget--) { s->failed_pc=0x0c098056u; return 0; }
target=r[3];
r[16]=code_base|0x0c09805au;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09805au) { target=s->pc; goto dispatch; }
goto P_0c09805a;
P_0c098058: /* original 54e5, guest PC 0x0c098058 */
if(!s->budget--) { s->failed_pc=0x0c098058u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c09805a;
P_0c09805a: /* original d218, guest PC 0x0c09805a */
if(!s->budget--) { s->failed_pc=0x0c09805au; return 0; }
r[2]=read(ram,0x0c0980bcu,4);
goto P_0c09805c;
P_0c09805c: /* original 420b, guest PC 0x0c09805c */
if(!s->budget--) { s->failed_pc=0x0c09805cu; return 0; }
target=r[2];
r[16]=code_base|0x0c098060u;
r[4]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098060u) { target=s->pc; goto dispatch; }
goto P_0c098060;
P_0c09805e: /* original 54e4, guest PC 0x0c09805e */
if(!s->budget--) { s->failed_pc=0x0c09805eu; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c098060;
P_0c098060: /* original d316, guest PC 0x0c098060 */
if(!s->budget--) { s->failed_pc=0x0c098060u; return 0; }
r[3]=read(ram,0x0c0980bcu,4);
goto P_0c098062;
P_0c098062: /* original 430b, guest PC 0x0c098062 */
if(!s->budget--) { s->failed_pc=0x0c098062u; return 0; }
target=r[3];
r[16]=code_base|0x0c098066u;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098066u) { target=s->pc; goto dispatch; }
goto P_0c098066;
P_0c098064: /* original 54e5, guest PC 0x0c098064 */
if(!s->budget--) { s->failed_pc=0x0c098064u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c098066;
P_0c098066: /* original d315, guest PC 0x0c098066 */
if(!s->budget--) { s->failed_pc=0x0c098066u; return 0; }
r[3]=read(ram,0x0c0980bcu,4);
goto P_0c098068;
P_0c098068: /* original e048, guest PC 0x0c098068 */
if(!s->budget--) { s->failed_pc=0x0c098068u; return 0; }
r[0]=0x00000048u;
goto P_0c09806a;
P_0c09806a: /* original 430b, guest PC 0x0c09806a */
if(!s->budget--) { s->failed_pc=0x0c09806au; return 0; }
target=r[3];
r[16]=code_base|0x0c09806eu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09806eu) { target=s->pc; goto dispatch; }
goto P_0c09806e;
P_0c09806c: /* original 04ee, guest PC 0x0c09806c */
if(!s->budget--) { s->failed_pc=0x0c09806cu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09806e;
P_0c09806e: /* original d313, guest PC 0x0c09806e */
if(!s->budget--) { s->failed_pc=0x0c09806eu; return 0; }
r[3]=read(ram,0x0c0980bcu,4);
goto P_0c098070;
P_0c098070: /* original e05c, guest PC 0x0c098070 */
if(!s->budget--) { s->failed_pc=0x0c098070u; return 0; }
r[0]=0x0000005cu;
goto P_0c098072;
P_0c098072: /* original 430b, guest PC 0x0c098072 */
if(!s->budget--) { s->failed_pc=0x0c098072u; return 0; }
target=r[3];
r[16]=code_base|0x0c098076u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098076u) { target=s->pc; goto dispatch; }
goto P_0c098076;
P_0c098074: /* original 04ee, guest PC 0x0c098074 */
if(!s->budget--) { s->failed_pc=0x0c098074u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c098076;
P_0c098076: /* original d311, guest PC 0x0c098076 */
if(!s->budget--) { s->failed_pc=0x0c098076u; return 0; }
r[3]=read(ram,0x0c0980bcu,4);
goto P_0c098078;
P_0c098078: /* original e060, guest PC 0x0c098078 */
if(!s->budget--) { s->failed_pc=0x0c098078u; return 0; }
r[0]=0x00000060u;
goto P_0c09807a;
P_0c09807a: /* original 430b, guest PC 0x0c09807a */
if(!s->budget--) { s->failed_pc=0x0c09807au; return 0; }
target=r[3];
r[16]=code_base|0x0c09807eu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09807eu) { target=s->pc; goto dispatch; }
goto P_0c09807e;
P_0c09807c: /* original 04ee, guest PC 0x0c09807c */
if(!s->budget--) { s->failed_pc=0x0c09807cu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09807e;
P_0c09807e: /* original 4f26, guest PC 0x0c09807e */
if(!s->budget--) { s->failed_pc=0x0c09807eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c098080;
P_0c098080: /* original e064, guest PC 0x0c098080 */
if(!s->budget--) { s->failed_pc=0x0c098080u; return 0; }
r[0]=0x00000064u;
goto P_0c098082;
P_0c098082: /* original d30e, guest PC 0x0c098082 */
if(!s->budget--) { s->failed_pc=0x0c098082u; return 0; }
r[3]=read(ram,0x0c0980bcu,4);
goto P_0c098084;
P_0c098084: /* original 04ee, guest PC 0x0c098084 */
if(!s->budget--) { s->failed_pc=0x0c098084u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c098086;
P_0c098086: /* original 432b, guest PC 0x0c098086 */
if(!s->budget--) { s->failed_pc=0x0c098086u; return 0; }
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
P_0c098088: /* original 6ef6, guest PC 0x0c098088 */
if(!s->budget--) { s->failed_pc=0x0c098088u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09808au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09808au; return 0; } return 1;
P_0c0980c0: /* original 2fe6, guest PC 0x0c0980c0 */
if(!s->budget--) { s->failed_pc=0x0c0980c0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0980c2;
P_0c0980c2: /* original e600, guest PC 0x0c0980c2 */
if(!s->budget--) { s->failed_pc=0x0c0980c2u; return 0; }
r[6]=0x00000000u;
goto P_0c0980c4;
P_0c0980c4: /* original 2fd6, guest PC 0x0c0980c4 */
if(!s->budget--) { s->failed_pc=0x0c0980c4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0980c6;
P_0c0980c6: /* original 6563, guest PC 0x0c0980c6 */
if(!s->budget--) { s->failed_pc=0x0c0980c6u; return 0; }
r[5]=r[6];
goto P_0c0980c8;
P_0c0980c8: /* original 2fc6, guest PC 0x0c0980c8 */
if(!s->budget--) { s->failed_pc=0x0c0980c8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0980ca;
P_0c0980ca: /* original 2fb6, guest PC 0x0c0980ca */
if(!s->budget--) { s->failed_pc=0x0c0980cau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0980cc;
P_0c0980cc: /* original 2fa6, guest PC 0x0c0980cc */
if(!s->budget--) { s->failed_pc=0x0c0980ccu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0980ce;
P_0c0980ce: /* original 2f96, guest PC 0x0c0980ce */
if(!s->budget--) { s->failed_pc=0x0c0980ceu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0980d0;
P_0c0980d0: /* original 2f86, guest PC 0x0c0980d0 */
if(!s->budget--) { s->failed_pc=0x0c0980d0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0980d2;
P_0c0980d2: /* original 4f22, guest PC 0x0c0980d2 */
if(!s->budget--) { s->failed_pc=0x0c0980d2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0980d4;
P_0c0980d4: /* original d945, guest PC 0x0c0980d4 */
if(!s->budget--) { s->failed_pc=0x0c0980d4u; return 0; }
r[9]=read(ram,0x0c0981ecu,4);
goto P_0c0980d6;
P_0c0980d6: /* original d346, guest PC 0x0c0980d6 */
if(!s->budget--) { s->failed_pc=0x0c0980d6u; return 0; }
r[3]=read(ram,0x0c0981f0u,4);
goto P_0c0980d8;
P_0c0980d8: /* original 4f12, guest PC 0x0c0980d8 */
if(!s->budget--) { s->failed_pc=0x0c0980d8u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0980da;
P_0c0980da: /* original de42, guest PC 0x0c0980da */
if(!s->budget--) { s->failed_pc=0x0c0980dau; return 0; }
r[14]=read(ram,0x0c0981e4u,4);
goto P_0c0980dc;
P_0c0980dc: /* original dd42, guest PC 0x0c0980dc */
if(!s->budget--) { s->failed_pc=0x0c0980dcu; return 0; }
r[13]=read(ram,0x0c0981e8u,4);
goto P_0c0980de;
P_0c0980de: /* original 7ff4, guest PC 0x0c0980de */
if(!s->budget--) { s->failed_pc=0x0c0980deu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0980e0;
P_0c0980e0: /* original 430b, guest PC 0x0c0980e0 */
if(!s->budget--) { s->failed_pc=0x0c0980e0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0980e4u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0980e4u) { target=s->pc; goto dispatch; }
goto P_0c0980e4;
P_0c0980e2: /* original 6463, guest PC 0x0c0980e2 */
if(!s->budget--) { s->failed_pc=0x0c0980e2u; return 0; }
r[4]=r[6];
goto P_0c0980e4;
P_0c0980e4: /* original e600, guest PC 0x0c0980e4 */
if(!s->budget--) { s->failed_pc=0x0c0980e4u; return 0; }
r[6]=0x00000000u;
goto P_0c0980e6;
P_0c0980e6: /* original d243, guest PC 0x0c0980e6 */
if(!s->budget--) { s->failed_pc=0x0c0980e6u; return 0; }
r[2]=read(ram,0x0c0981f4u,4);
goto P_0c0980e8;
P_0c0980e8: /* original f58d, guest PC 0x0c0980e8 */
if(!s->budget--) { s->failed_pc=0x0c0980e8u; return 0; }
fr[5]=0;
goto P_0c0980ea;
P_0c0980ea: /* original 6563, guest PC 0x0c0980ea */
if(!s->budget--) { s->failed_pc=0x0c0980eau; return 0; }
r[5]=r[6];
goto P_0c0980ec;
P_0c0980ec: /* original f48d, guest PC 0x0c0980ec */
if(!s->budget--) { s->failed_pc=0x0c0980ecu; return 0; }
fr[4]=0;
goto P_0c0980ee;
P_0c0980ee: /* original 420b, guest PC 0x0c0980ee */
if(!s->budget--) { s->failed_pc=0x0c0980eeu; return 0; }
target=r[2];
r[16]=code_base|0x0c0980f2u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0980f2u) { target=s->pc; goto dispatch; }
goto P_0c0980f2;
P_0c0980f0: /* original 6463, guest PC 0x0c0980f0 */
if(!s->budget--) { s->failed_pc=0x0c0980f0u; return 0; }
r[4]=r[6];
goto P_0c0980f2;
P_0c0980f2: /* original d341, guest PC 0x0c0980f2 */
if(!s->budget--) { s->failed_pc=0x0c0980f2u; return 0; }
r[3]=read(ram,0x0c0981f8u,4);
goto P_0c0980f4;
P_0c0980f4: /* original 430b, guest PC 0x0c0980f4 */
if(!s->budget--) { s->failed_pc=0x0c0980f4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0980f8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0980f8u) { target=s->pc; goto dispatch; }
goto P_0c0980f8;
P_0c0980f6: /* original 0009, guest PC 0x0c0980f6 */
if(!s->budget--) { s->failed_pc=0x0c0980f6u; return 0; }
goto P_0c0980f8;
P_0c0980f8: /* original 946e, guest PC 0x0c0980f8 */
if(!s->budget--) { s->failed_pc=0x0c0980f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0981d8u,2);
goto P_0c0980fa;
P_0c0980fa: /* original dc40, guest PC 0x0c0980fa */
if(!s->budget--) { s->failed_pc=0x0c0980fau; return 0; }
r[12]=read(ram,0x0c0981fcu,4);
goto P_0c0980fc;
P_0c0980fc: /* original 4c0b, guest PC 0x0c0980fc */
if(!s->budget--) { s->failed_pc=0x0c0980fcu; return 0; }
target=r[12];
r[16]=code_base|0x0c098100u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098100u) { target=s->pc; goto dispatch; }
goto P_0c098100;
P_0c0980fe: /* original 0009, guest PC 0x0c0980fe */
if(!s->budget--) { s->failed_pc=0x0c0980feu; return 0; }
goto P_0c098100;
P_0c098100: /* original 4c0b, guest PC 0x0c098100 */
if(!s->budget--) { s->failed_pc=0x0c098100u; return 0; }
target=r[12];
r[16]=code_base|0x0c098104u;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098104u) { target=s->pc; goto dispatch; }
goto P_0c098104;
P_0c098102: /* original e414, guest PC 0x0c098102 */
if(!s->budget--) { s->failed_pc=0x0c098102u; return 0; }
r[4]=0x00000014u;
goto P_0c098104;
P_0c098104: /* original 4c0b, guest PC 0x0c098104 */
if(!s->budget--) { s->failed_pc=0x0c098104u; return 0; }
target=r[12];
r[16]=code_base|0x0c098108u;
r[4]=0x00000016u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098108u) { target=s->pc; goto dispatch; }
goto P_0c098108;
P_0c098106: /* original e416, guest PC 0x0c098106 */
if(!s->budget--) { s->failed_pc=0x0c098106u; return 0; }
r[4]=0x00000016u;
goto P_0c098108;
P_0c098108: /* original 4c0b, guest PC 0x0c098108 */
if(!s->budget--) { s->failed_pc=0x0c098108u; return 0; }
target=r[12];
r[16]=code_base|0x0c09810cu;
r[4]=0x0000000fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09810cu) { target=s->pc; goto dispatch; }
goto P_0c09810c;
P_0c09810a: /* original e40f, guest PC 0x0c09810a */
if(!s->budget--) { s->failed_pc=0x0c09810au; return 0; }
r[4]=0x0000000fu;
goto P_0c09810c;
P_0c09810c: /* original d23c, guest PC 0x0c09810c */
if(!s->budget--) { s->failed_pc=0x0c09810cu; return 0; }
r[2]=read(ram,0x0c098200u,4);
goto P_0c09810e;
P_0c09810e: /* original 420b, guest PC 0x0c09810e */
if(!s->budget--) { s->failed_pc=0x0c09810eu; return 0; }
target=r[2];
r[16]=code_base|0x0c098112u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098112u) { target=s->pc; goto dispatch; }
goto P_0c098112;
P_0c098110: /* original 0009, guest PC 0x0c098110 */
if(!s->budget--) { s->failed_pc=0x0c098110u; return 0; }
goto P_0c098112;
P_0c098112: /* original d33c, guest PC 0x0c098112 */
if(!s->budget--) { s->failed_pc=0x0c098112u; return 0; }
r[3]=read(ram,0x0c098204u,4);
goto P_0c098114;
P_0c098114: /* original 430b, guest PC 0x0c098114 */
if(!s->budget--) { s->failed_pc=0x0c098114u; return 0; }
target=r[3];
r[16]=code_base|0x0c098118u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098118u) { target=s->pc; goto dispatch; }
goto P_0c098118;
P_0c098116: /* original 0009, guest PC 0x0c098116 */
if(!s->budget--) { s->failed_pc=0x0c098116u; return 0; }
goto P_0c098118;
P_0c098118: /* original bf92, guest PC 0x0c098118 */
if(!s->budget--) { s->failed_pc=0x0c098118u; return 0; }
target=code_base|0x0c098040u; r[16]=code_base|0x0c09811cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09811cu) { target=s->pc; goto dispatch; }
goto P_0c09811c;
P_0c09811a: /* original 0009, guest PC 0x0c09811a */
if(!s->budget--) { s->failed_pc=0x0c09811au; return 0; }
goto P_0c09811c;
P_0c09811c: /* original da3a, guest PC 0x0c09811c */
if(!s->budget--) { s->failed_pc=0x0c09811cu; return 0; }
r[10]=read(ram,0x0c098208u,4);
goto P_0c09811e;
P_0c09811e: /* original e046, guest PC 0x0c09811e */
if(!s->budget--) { s->failed_pc=0x0c09811eu; return 0; }
r[0]=0x00000046u;
goto P_0c098120;
P_0c098120: /* original e800, guest PC 0x0c098120 */
if(!s->budget--) { s->failed_pc=0x0c098120u; return 0; }
r[8]=0x00000000u;
goto P_0c098122;
P_0c098122: /* original 5ba4, guest PC 0x0c098122 */
if(!s->budget--) { s->failed_pc=0x0c098122u; return 0; }
r[11]=read(ram,r[10]+16,4);
goto P_0c098124;
P_0c098124: /* original 5ca5, guest PC 0x0c098124 */
if(!s->budget--) { s->failed_pc=0x0c098124u; return 0; }
r[12]=read(ram,r[10]+20,4);
goto P_0c098126;
P_0c098126: /* original 0b85, guest PC 0x0c098126 */
if(!s->budget--) { s->failed_pc=0x0c098126u; return 0; }
write(ram,r[11]+r[0],r[8],2);
goto P_0c098128;
P_0c098128: /* original d338, guest PC 0x0c098128 */
if(!s->budget--) { s->failed_pc=0x0c098128u; return 0; }
r[3]=read(ram,0x0c09820cu,4);
goto P_0c09812a;
P_0c09812a: /* original 430b, guest PC 0x0c09812a */
if(!s->budget--) { s->failed_pc=0x0c09812au; return 0; }
target=r[3];
r[16]=code_base|0x0c09812eu;
write(ram,r[12]+r[0],r[8],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09812eu) { target=s->pc; goto dispatch; }
goto P_0c09812e;
P_0c09812c: /* original 0c85, guest PC 0x0c09812c */
if(!s->budget--) { s->failed_pc=0x0c09812cu; return 0; }
write(ram,r[12]+r[0],r[8],2);
goto P_0c09812e;
P_0c09812e: /* original 65b2, guest PC 0x0c09812e */
if(!s->budget--) { s->failed_pc=0x0c09812eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c098130;
P_0c098130: /* original e029, guest PC 0x0c098130 */
if(!s->budget--) { s->failed_pc=0x0c098130u; return 0; }
r[0]=0x00000029u;
goto P_0c098132;
P_0c098132: /* original 64c2, guest PC 0x0c098132 */
if(!s->budget--) { s->failed_pc=0x0c098132u; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c098134;
P_0c098134: /* original e301, guest PC 0x0c098134 */
if(!s->budget--) { s->failed_pc=0x0c098134u; return 0; }
r[3]=0x00000001u;
goto P_0c098136;
P_0c098136: /* original d736, guest PC 0x0c098136 */
if(!s->budget--) { s->failed_pc=0x0c098136u; return 0; }
r[7]=read(ram,0x0c098210u,4);
goto P_0c098138;
P_0c098138: /* original 06ec, guest PC 0x0c098138 */
if(!s->budget--) { s->failed_pc=0x0c098138u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09813a;
P_0c09813a: /* original 2479, guest PC 0x0c09813a */
if(!s->budget--) { s->failed_pc=0x0c09813au; return 0; }
r[4]&=r[7];
goto P_0c09813c;
P_0c09813c: /* original 2579, guest PC 0x0c09813c */
if(!s->budget--) { s->failed_pc=0x0c09813cu; return 0; }
r[5]&=r[7];
goto P_0c09813e;
P_0c09813e: /* original d735, guest PC 0x0c09813e */
if(!s->budget--) { s->failed_pc=0x0c09813eu; return 0; }
r[7]=read(ram,0x0c098214u,4);
goto P_0c098140;
P_0c098140: /* original 666c, guest PC 0x0c098140 */
if(!s->budget--) { s->failed_pc=0x0c098140u; return 0; }
r[6]=r[6]&255u;
goto P_0c098142;
P_0c098142: /* original 2368, guest PC 0x0c098142 */
if(!s->budget--) { s->failed_pc=0x0c098142u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c098144;
P_0c098144: /* original 8d01, guest PC 0x0c098144 */
if(!s->budget--) { s->failed_pc=0x0c098144u; return 0; }
cond=r[17]&1u;
r[3]=0x00000002u;
if(cond) { goto P_0c09814a; }
goto P_0c098148;
P_0c098146: /* original e302, guest PC 0x0c098146 */
if(!s->budget--) { s->failed_pc=0x0c098146u; return 0; }
r[3]=0x00000002u;
goto P_0c098148;
P_0c098148: /* original 257b, guest PC 0x0c098148 */
if(!s->budget--) { s->failed_pc=0x0c098148u; return 0; }
r[5]|=r[7];
goto P_0c09814a;
P_0c09814a: /* original 2638, guest PC 0x0c09814a */
if(!s->budget--) { s->failed_pc=0x0c09814au; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c09814c;
P_0c09814c: /* original 8d01, guest PC 0x0c09814c */
if(!s->budget--) { s->failed_pc=0x0c09814cu; return 0; }
cond=r[17]&1u;
write(ram,r[11],r[5],4);
if(cond) { goto P_0c098152; }
goto P_0c098150;
P_0c09814e: /* original 2b52, guest PC 0x0c09814e */
if(!s->budget--) { s->failed_pc=0x0c09814eu; return 0; }
write(ram,r[11],r[5],4);
goto P_0c098150;
P_0c098150: /* original 247b, guest PC 0x0c098150 */
if(!s->budget--) { s->failed_pc=0x0c098150u; return 0; }
r[4]|=r[7];
goto P_0c098152;
P_0c098152: /* original 2c42, guest PC 0x0c098152 */
if(!s->budget--) { s->failed_pc=0x0c098152u; return 0; }
write(ram,r[12],r[4],4);
goto P_0c098154;
P_0c098154: /* original 6493, guest PC 0x0c098154 */
if(!s->budget--) { s->failed_pc=0x0c098154u; return 0; }
r[4]=r[9];
goto P_0c098156;
P_0c098156: /* original 52e2, guest PC 0x0c098156 */
if(!s->budget--) { s->failed_pc=0x0c098156u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c098158;
P_0c098158: /* original d32f, guest PC 0x0c098158 */
if(!s->budget--) { s->failed_pc=0x0c098158u; return 0; }
r[3]=read(ram,0x0c098218u,4);
goto P_0c09815a;
P_0c09815a: /* original 2239, guest PC 0x0c09815a */
if(!s->budget--) { s->failed_pc=0x0c09815au; return 0; }
r[2]&=r[3];
goto P_0c09815c;
P_0c09815c: /* original 1e22, guest PC 0x0c09815c */
if(!s->budget--) { s->failed_pc=0x0c09815cu; return 0; }
write(ram,r[14]+8,r[2],4);
goto P_0c09815e;
P_0c09815e: /* original d12f, guest PC 0x0c09815e */
if(!s->budget--) { s->failed_pc=0x0c09815eu; return 0; }
r[1]=read(ram,0x0c09821cu,4);
goto P_0c098160;
P_0c098160: /* original 410b, guest PC 0x0c098160 */
if(!s->budget--) { s->failed_pc=0x0c098160u; return 0; }
target=r[1];
r[16]=code_base|0x0c098164u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098164u) { target=s->pc; goto dispatch; }
goto P_0c098164;
P_0c098162: /* original 7404, guest PC 0x0c098162 */
if(!s->budget--) { s->failed_pc=0x0c098162u; return 0; }
r[4]+=0x00000004u;
goto P_0c098164;
P_0c098164: /* original 9139, guest PC 0x0c098164 */
if(!s->budget--) { s->failed_pc=0x0c098164u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0981dau,2);
goto P_0c098166;
P_0c098166: /* original 7001, guest PC 0x0c098166 */
if(!s->budget--) { s->failed_pc=0x0c098166u; return 0; }
r[0]+=0x00000001u;
goto P_0c098168;
P_0c098168: /* original 6493, guest PC 0x0c098168 */
if(!s->budget--) { s->failed_pc=0x0c098168u; return 0; }
r[4]=r[9];
goto P_0c09816a;
P_0c09816a: /* original 31bc, guest PC 0x0c09816a */
if(!s->budget--) { s->failed_pc=0x0c09816au; return 0; }
r[1]+=r[11];
goto P_0c09816c;
P_0c09816c: /* original 2101, guest PC 0x0c09816c */
if(!s->budget--) { s->failed_pc=0x0c09816cu; return 0; }
write(ram,r[1],r[0],2);
goto P_0c09816e;
P_0c09816e: /* original d32b, guest PC 0x0c09816e */
if(!s->budget--) { s->failed_pc=0x0c09816eu; return 0; }
r[3]=read(ram,0x0c09821cu,4);
goto P_0c098170;
P_0c098170: /* original 430b, guest PC 0x0c098170 */
if(!s->budget--) { s->failed_pc=0x0c098170u; return 0; }
target=r[3];
r[16]=code_base|0x0c098174u;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098174u) { target=s->pc; goto dispatch; }
goto P_0c098174;
P_0c098172: /* original 7408, guest PC 0x0c098172 */
if(!s->budget--) { s->failed_pc=0x0c098172u; return 0; }
r[4]+=0x00000008u;
goto P_0c098174;
P_0c098174: /* original 9131, guest PC 0x0c098174 */
if(!s->budget--) { s->failed_pc=0x0c098174u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0981dau,2);
goto P_0c098176;
P_0c098176: /* original 7001, guest PC 0x0c098176 */
if(!s->budget--) { s->failed_pc=0x0c098176u; return 0; }
r[0]+=0x00000001u;
goto P_0c098178;
P_0c098178: /* original 31cc, guest PC 0x0c098178 */
if(!s->budget--) { s->failed_pc=0x0c098178u; return 0; }
r[1]+=r[12];
goto P_0c09817a;
P_0c09817a: /* original 2101, guest PC 0x0c09817a */
if(!s->budget--) { s->failed_pc=0x0c09817au; return 0; }
write(ram,r[1],r[0],2);
goto P_0c09817c;
P_0c09817c: /* original d428, guest PC 0x0c09817c */
if(!s->budget--) { s->failed_pc=0x0c09817cu; return 0; }
r[4]=read(ram,0x0c098220u,4);
goto P_0c09817e;
P_0c09817e: /* original d329, guest PC 0x0c09817e */
if(!s->budget--) { s->failed_pc=0x0c09817eu; return 0; }
r[3]=read(ram,0x0c098224u,4);
goto P_0c098180;
P_0c098180: /* original 430b, guest PC 0x0c098180 */
if(!s->budget--) { s->failed_pc=0x0c098180u; return 0; }
target=r[3];
r[16]=code_base|0x0c098184u;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098184u) { target=s->pc; goto dispatch; }
goto P_0c098184;
P_0c098182: /* original e500, guest PC 0x0c098182 */
if(!s->budget--) { s->failed_pc=0x0c098182u; return 0; }
r[5]=0x00000000u;
goto P_0c098184;
P_0c098184: /* original 52e2, guest PC 0x0c098184 */
if(!s->budget--) { s->failed_pc=0x0c098184u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c098186;
P_0c098186: /* original d328, guest PC 0x0c098186 */
if(!s->budget--) { s->failed_pc=0x0c098186u; return 0; }
r[3]=read(ram,0x0c098228u,4);
goto P_0c098188;
P_0c098188: /* original 2238, guest PC 0x0c098188 */
if(!s->budget--) { s->failed_pc=0x0c098188u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09818a;
P_0c09818a: /* original 8d4f, guest PC 0x0c09818a */
if(!s->budget--) { s->failed_pc=0x0c09818au; return 0; }
cond=r[17]&1u;
r[9]=0x0000000du;
if(cond) { goto P_0c09822c; }
goto P_0c09818e;
P_0c09818c: /* original e90d, guest PC 0x0c09818c */
if(!s->budget--) { s->failed_pc=0x0c09818cu; return 0; }
r[9]=0x0000000du;
goto P_0c09818e;
P_0c09818e: /* original 9025, guest PC 0x0c09818e */
if(!s->budget--) { s->failed_pc=0x0c09818eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0981dcu,2);
goto P_0c098190;
P_0c098190: /* original e160, guest PC 0x0c098190 */
if(!s->budget--) { s->failed_pc=0x0c098190u; return 0; }
r[1]=0x00000060u;
goto P_0c098192;
P_0c098192: /* original 31bc, guest PC 0x0c098192 */
if(!s->budget--) { s->failed_pc=0x0c098192u; return 0; }
r[1]+=r[11];
goto P_0c098194;
P_0c098194: /* original 00dc, guest PC 0x0c098194 */
if(!s->budget--) { s->failed_pc=0x0c098194u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c098196;
P_0c098196: /* original 2100, guest PC 0x0c098196 */
if(!s->budget--) { s->failed_pc=0x0c098196u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c098198;
P_0c098198: /* original 9021, guest PC 0x0c098198 */
if(!s->budget--) { s->failed_pc=0x0c098198u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0981deu,2);
goto P_0c09819a;
P_0c09819a: /* original 02dc, guest PC 0x0c09819a */
if(!s->budget--) { s->failed_pc=0x0c09819au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c09819c;
P_0c09819c: /* original e060, guest PC 0x0c09819c */
if(!s->budget--) { s->failed_pc=0x0c09819cu; return 0; }
r[0]=0x00000060u;
goto P_0c09819e;
P_0c09819e: /* original 0c24, guest PC 0x0c09819e */
if(!s->budget--) { s->failed_pc=0x0c09819eu; return 0; }
write(ram,r[12]+r[0],r[2],1);
goto P_0c0981a0;
P_0c0981a0: /* original 04bc, guest PC 0x0c0981a0 */
if(!s->budget--) { s->failed_pc=0x0c0981a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0981a2;
P_0c0981a2: /* original 644c, guest PC 0x0c0981a2 */
if(!s->budget--) { s->failed_pc=0x0c0981a2u; return 0; }
r[4]=r[4]&255u;
goto P_0c0981a4;
P_0c0981a4: /* original 3493, guest PC 0x0c0981a4 */
if(!s->budget--) { s->failed_pc=0x0c0981a4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[9])!=0);
goto P_0c0981a6;
P_0c0981a6: /* original 8f03, guest PC 0x0c0981a6 */
if(!s->budget--) { s->failed_pc=0x0c0981a6u; return 0; }
cond=r[17]&1u;
r[0]=0x00000061u;
if(!cond) { goto P_0c0981b0; }
goto P_0c0981aa;
P_0c0981a8: /* original e061, guest PC 0x0c0981a8 */
if(!s->budget--) { s->failed_pc=0x0c0981a8u; return 0; }
r[0]=0x00000061u;
goto P_0c0981aa;
P_0c0981aa: /* original 6143, guest PC 0x0c0981aa */
if(!s->budget--) { s->failed_pc=0x0c0981aau; return 0; }
r[1]=r[4];
goto P_0c0981ac;
P_0c0981ac: /* original a001, guest PC 0x0c0981ac */
if(!s->budget--) { s->failed_pc=0x0c0981acu; return 0; }
r[1]+=0xfffffff3u;
goto P_0c0981b2;
P_0c0981ae: /* original 71f3, guest PC 0x0c0981ae */
if(!s->budget--) { s->failed_pc=0x0c0981aeu; return 0; }
r[1]+=0xfffffff3u;
goto P_0c0981b0;
P_0c0981b0: /* original 6143, guest PC 0x0c0981b0 */
if(!s->budget--) { s->failed_pc=0x0c0981b0u; return 0; }
r[1]=r[4];
goto P_0c0981b2;
P_0c0981b2: /* original 0b14, guest PC 0x0c0981b2 */
if(!s->budget--) { s->failed_pc=0x0c0981b2u; return 0; }
write(ram,r[11]+r[0],r[1],1);
goto P_0c0981b4;
P_0c0981b4: /* original e060, guest PC 0x0c0981b4 */
if(!s->budget--) { s->failed_pc=0x0c0981b4u; return 0; }
r[0]=0x00000060u;
goto P_0c0981b6;
P_0c0981b6: /* original 04cc, guest PC 0x0c0981b6 */
if(!s->budget--) { s->failed_pc=0x0c0981b6u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0981b8;
P_0c0981b8: /* original 644c, guest PC 0x0c0981b8 */
if(!s->budget--) { s->failed_pc=0x0c0981b8u; return 0; }
r[4]=r[4]&255u;
goto P_0c0981ba;
P_0c0981ba: /* original 3493, guest PC 0x0c0981ba */
if(!s->budget--) { s->failed_pc=0x0c0981bau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[9])!=0);
goto P_0c0981bc;
P_0c0981bc: /* original 8f03, guest PC 0x0c0981bc */
if(!s->budget--) { s->failed_pc=0x0c0981bcu; return 0; }
cond=r[17]&1u;
r[0]=0x00000061u;
if(!cond) { goto P_0c0981c6; }
goto P_0c0981c0;
P_0c0981be: /* original e061, guest PC 0x0c0981be */
if(!s->budget--) { s->failed_pc=0x0c0981beu; return 0; }
r[0]=0x00000061u;
goto P_0c0981c0;
P_0c0981c0: /* original 6343, guest PC 0x0c0981c0 */
if(!s->budget--) { s->failed_pc=0x0c0981c0u; return 0; }
r[3]=r[4];
goto P_0c0981c2;
P_0c0981c2: /* original a001, guest PC 0x0c0981c2 */
if(!s->budget--) { s->failed_pc=0x0c0981c2u; return 0; }
r[3]+=0xfffffff3u;
goto P_0c0981c8;
P_0c0981c4: /* original 73f3, guest PC 0x0c0981c4 */
if(!s->budget--) { s->failed_pc=0x0c0981c4u; return 0; }
r[3]+=0xfffffff3u;
goto P_0c0981c6;
P_0c0981c6: /* original 6343, guest PC 0x0c0981c6 */
if(!s->budget--) { s->failed_pc=0x0c0981c6u; return 0; }
r[3]=r[4];
goto P_0c0981c8;
P_0c0981c8: /* original 0c34, guest PC 0x0c0981c8 */
if(!s->budget--) { s->failed_pc=0x0c0981c8u; return 0; }
write(ram,r[12]+r[0],r[3],1);
goto P_0c0981ca;
P_0c0981ca: /* original 9009, guest PC 0x0c0981ca */
if(!s->budget--) { s->failed_pc=0x0c0981cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0981e0u,2);
goto P_0c0981cc;
P_0c0981cc: /* original 02dc, guest PC 0x0c0981cc */
if(!s->budget--) { s->failed_pc=0x0c0981ccu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0981ce;
P_0c0981ce: /* original e01c, guest PC 0x0c0981ce */
if(!s->budget--) { s->failed_pc=0x0c0981ceu; return 0; }
r[0]=0x0000001cu;
goto P_0c0981d0;
P_0c0981d0: /* original 0d24, guest PC 0x0c0981d0 */
if(!s->budget--) { s->failed_pc=0x0c0981d0u; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c0981d2;
P_0c0981d2: /* original e07c, guest PC 0x0c0981d2 */
if(!s->budget--) { s->failed_pc=0x0c0981d2u; return 0; }
r[0]=0x0000007cu;
goto P_0c0981d4;
P_0c0981d4: /* original a09a, guest PC 0x0c0981d4 */
if(!s->budget--) { s->failed_pc=0x0c0981d4u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c09830c;
P_0c0981d6: /* original 0e24, guest PC 0x0c0981d6 */
if(!s->budget--) { s->failed_pc=0x0c0981d6u; return 0; }
write(ram,r[14]+r[0],r[2],1);
if(!vf3_matrix_family(0x0c0981d8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0981d8u; return 0; } return 1;
P_0c09822c: /* original d14e, guest PC 0x0c09822c */
if(!s->budget--) { s->failed_pc=0x0c09822cu; return 0; }
r[1]=read(ram,0x0c098368u,4);
goto P_0c09822e;
P_0c09822e: /* original 410b, guest PC 0x0c09822e */
if(!s->budget--) { s->failed_pc=0x0c09822eu; return 0; }
target=r[1];
r[16]=code_base|0x0c098232u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098232u) { target=s->pc; goto dispatch; }
goto P_0c098232;
P_0c098230: /* original 0009, guest PC 0x0c098230 */
if(!s->budget--) { s->failed_pc=0x0c098230u; return 0; }
goto P_0c098232;
P_0c098232: /* original 6403, guest PC 0x0c098232 */
if(!s->budget--) { s->failed_pc=0x0c098232u; return 0; }
r[4]=r[0];
goto P_0c098234;
P_0c098234: /* original e07c, guest PC 0x0c098234 */
if(!s->budget--) { s->failed_pc=0x0c098234u; return 0; }
r[0]=0x0000007cu;
goto P_0c098236;
P_0c098236: /* original 0e44, guest PC 0x0c098236 */
if(!s->budget--) { s->failed_pc=0x0c098236u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c098238;
P_0c098238: /* original 50e2, guest PC 0x0c098238 */
if(!s->budget--) { s->failed_pc=0x0c098238u; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c09823a;
P_0c09823a: /* original c804, guest PC 0x0c09823a */
if(!s->budget--) { s->failed_pc=0x0c09823au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c09823c;
P_0c09823c: /* original 8966, guest PC 0x0c09823c */
if(!s->budget--) { s->failed_pc=0x0c09823cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09830c; }
goto P_0c09823e;
P_0c09823e: /* original e01c, guest PC 0x0c09823e */
if(!s->budget--) { s->failed_pc=0x0c09823eu; return 0; }
r[0]=0x0000001cu;
goto P_0c098240;
P_0c098240: /* original e301, guest PC 0x0c098240 */
if(!s->budget--) { s->failed_pc=0x0c098240u; return 0; }
r[3]=0x00000001u;
goto P_0c098242;
P_0c098242: /* original 0e34, guest PC 0x0c098242 */
if(!s->budget--) { s->failed_pc=0x0c098242u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c098244;
P_0c098244: /* original e029, guest PC 0x0c098244 */
if(!s->budget--) { s->failed_pc=0x0c098244u; return 0; }
r[0]=0x00000029u;
goto P_0c098246;
P_0c098246: /* original 00ec, guest PC 0x0c098246 */
if(!s->budget--) { s->failed_pc=0x0c098246u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098248;
P_0c098248: /* original 600c, guest PC 0x0c098248 */
if(!s->budget--) { s->failed_pc=0x0c098248u; return 0; }
r[0]=r[0]&255u;
goto P_0c09824a;
P_0c09824a: /* original 8803, guest PC 0x0c09824a */
if(!s->budget--) { s->failed_pc=0x0c09824au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09824c;
P_0c09824c: /* original 8945, guest PC 0x0c09824c */
if(!s->budget--) { s->failed_pc=0x0c09824cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0982da; }
goto P_0c09824e;
P_0c09824e: /* original 6083, guest PC 0x0c09824e */
if(!s->budget--) { s->failed_pc=0x0c09824eu; return 0; }
r[0]=r[8];
goto P_0c098250;
P_0c098250: /* original 9584, guest PC 0x0c098250 */
if(!s->budget--) { s->failed_pc=0x0c098250u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09835cu,2);
goto P_0c098252;
P_0c098252: /* original 9684, guest PC 0x0c098252 */
if(!s->budget--) { s->failed_pc=0x0c098252u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09835eu,2);
goto P_0c098254;
P_0c098254: /* original 80c4, guest PC 0x0c098254 */
if(!s->budget--) { s->failed_pc=0x0c098254u; return 0; }
write(ram,r[12]+4,r[0],1);
goto P_0c098256;
P_0c098256: /* original e029, guest PC 0x0c098256 */
if(!s->budget--) { s->failed_pc=0x0c098256u; return 0; }
r[0]=0x00000029u;
goto P_0c098258;
P_0c098258: /* original 00ec, guest PC 0x0c098258 */
if(!s->budget--) { s->failed_pc=0x0c098258u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09825a;
P_0c09825a: /* original 35ec, guest PC 0x0c09825a */
if(!s->budget--) { s->failed_pc=0x0c09825au; return 0; }
r[5]+=r[14];
goto P_0c09825c;
P_0c09825c: /* original 600c, guest PC 0x0c09825c */
if(!s->budget--) { s->failed_pc=0x0c09825cu; return 0; }
r[0]=r[0]&255u;
goto P_0c09825e;
P_0c09825e: /* original 8802, guest PC 0x0c09825e */
if(!s->budget--) { s->failed_pc=0x0c09825eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c098260;
P_0c098260: /* original 8d06, guest PC 0x0c098260 */
if(!s->budget--) { s->failed_pc=0x0c098260u; return 0; }
cond=r[17]&1u;
r[6]+=r[14];
if(cond) { goto P_0c098270; }
goto P_0c098264;
P_0c098262: /* original 36ec, guest PC 0x0c098262 */
if(!s->budget--) { s->failed_pc=0x0c098262u; return 0; }
r[6]+=r[14];
goto P_0c098264;
P_0c098264: /* original e001, guest PC 0x0c098264 */
if(!s->budget--) { s->failed_pc=0x0c098264u; return 0; }
r[0]=0x00000001u;
goto P_0c098266;
P_0c098266: /* original 80c4, guest PC 0x0c098266 */
if(!s->budget--) { s->failed_pc=0x0c098266u; return 0; }
write(ram,r[12]+4,r[0],1);
goto P_0c098268;
P_0c098268: /* original 9579, guest PC 0x0c098268 */
if(!s->budget--) { s->failed_pc=0x0c098268u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09835eu,2);
goto P_0c09826a;
P_0c09826a: /* original 9677, guest PC 0x0c09826a */
if(!s->budget--) { s->failed_pc=0x0c09826au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09835cu,2);
goto P_0c09826c;
P_0c09826c: /* original 35ec, guest PC 0x0c09826c */
if(!s->budget--) { s->failed_pc=0x0c09826cu; return 0; }
r[5]+=r[14];
goto P_0c09826e;
P_0c09826e: /* original 36ec, guest PC 0x0c09826e */
if(!s->budget--) { s->failed_pc=0x0c09826eu; return 0; }
r[6]+=r[14];
goto P_0c098270;
P_0c098270: /* original e02b, guest PC 0x0c098270 */
if(!s->budget--) { s->failed_pc=0x0c098270u; return 0; }
r[0]=0x0000002bu;
goto P_0c098272;
P_0c098272: /* original 9475, guest PC 0x0c098272 */
if(!s->budget--) { s->failed_pc=0x0c098272u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098360u,2);
goto P_0c098274;
P_0c098274: /* original 0bec, guest PC 0x0c098274 */
if(!s->budget--) { s->failed_pc=0x0c098274u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098276;
P_0c098276: /* original 9074, guest PC 0x0c098276 */
if(!s->budget--) { s->failed_pc=0x0c098276u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098362u,2);
goto P_0c098278;
P_0c098278: /* original 34ec, guest PC 0x0c098278 */
if(!s->budget--) { s->failed_pc=0x0c098278u; return 0; }
r[4]+=r[14];
goto P_0c09827a;
P_0c09827a: /* original 3b4c, guest PC 0x0c09827a */
if(!s->budget--) { s->failed_pc=0x0c09827au; return 0; }
r[11]+=r[4];
goto P_0c09827c;
P_0c09827c: /* original 04ec, guest PC 0x0c09827c */
if(!s->budget--) { s->failed_pc=0x0c09827cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09827e;
P_0c09827e: /* original 7bf3, guest PC 0x0c09827e */
if(!s->budget--) { s->failed_pc=0x0c09827eu; return 0; }
r[11]+=0xfffffff3u;
goto P_0c098280;
P_0c098280: /* original 6843, guest PC 0x0c098280 */
if(!s->budget--) { s->failed_pc=0x0c098280u; return 0; }
r[8]=r[4];
goto P_0c098282;
P_0c098282: /* original e30d, guest PC 0x0c098282 */
if(!s->budget--) { s->failed_pc=0x0c098282u; return 0; }
r[3]=0x0000000du;
goto P_0c098284;
P_0c098284: /* original 7b0c, guest PC 0x0c098284 */
if(!s->budget--) { s->failed_pc=0x0c098284u; return 0; }
r[11]+=0x0000000cu;
goto P_0c098286;
P_0c098286: /* original 64b0, guest PC 0x0c098286 */
if(!s->budget--) { s->failed_pc=0x0c098286u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[11],1);
r[4]=tmp;
goto P_0c098288;
P_0c098288: /* original 644c, guest PC 0x0c098288 */
if(!s->budget--) { s->failed_pc=0x0c098288u; return 0; }
r[4]=r[4]&255u;
goto P_0c09828a;
P_0c09828a: /* original 1f42, guest PC 0x0c09828a */
if(!s->budget--) { s->failed_pc=0x0c09828au; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c09828c;
P_0c09828c: /* original 84c4, guest PC 0x0c09828c */
if(!s->budget--) { s->failed_pc=0x0c09828cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+4,1);
goto P_0c09828e;
P_0c09828e: /* original 600c, guest PC 0x0c09828e */
if(!s->budget--) { s->failed_pc=0x0c09828eu; return 0; }
r[0]=r[0]&255u;
goto P_0c098290;
P_0c098290: /* original 203e, guest PC 0x0c098290 */
if(!s->budget--) { s->failed_pc=0x0c098290u; return 0; }
r[19]=(r[0]&65535u)*(r[3]&65535u);
goto P_0c098292;
P_0c098292: /* original 001a, guest PC 0x0c098292 */
if(!s->budget--) { s->failed_pc=0x0c098292u; return 0; }
r[0]=r[19];
goto P_0c098294;
P_0c098294: /* original 2f02, guest PC 0x0c098294 */
if(!s->budget--) { s->failed_pc=0x0c098294u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c098296;
P_0c098296: /* original 9064, guest PC 0x0c098296 */
if(!s->budget--) { s->failed_pc=0x0c098296u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098362u,2);
goto P_0c098298;
P_0c098298: /* original 62f2, guest PC 0x0c098298 */
if(!s->budget--) { s->failed_pc=0x0c098298u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09829a;
P_0c09829a: /* original 07ec, guest PC 0x0c09829a */
if(!s->budget--) { s->failed_pc=0x0c09829au; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09829c;
P_0c09829c: /* original 342c, guest PC 0x0c09829c */
if(!s->budget--) { s->failed_pc=0x0c09829cu; return 0; }
r[4]+=r[2];
goto P_0c09829e;
P_0c09829e: /* original 77ff, guest PC 0x0c09829e */
if(!s->budget--) { s->failed_pc=0x0c09829eu; return 0; }
r[7]+=0xffffffffu;
goto P_0c0982a0;
P_0c0982a0: /* original 6073, guest PC 0x0c0982a0 */
if(!s->budget--) { s->failed_pc=0x0c0982a0u; return 0; }
r[0]=r[7];
goto P_0c0982a2;
P_0c0982a2: /* original 036c, guest PC 0x0c0982a2 */
if(!s->budget--) { s->failed_pc=0x0c0982a2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0982a4;
P_0c0982a4: /* original 633c, guest PC 0x0c0982a4 */
if(!s->budget--) { s->failed_pc=0x0c0982a4u; return 0; }
r[3]=r[3]&255u;
goto P_0c0982a6;
P_0c0982a6: /* original 3430, guest PC 0x0c0982a6 */
if(!s->budget--) { s->failed_pc=0x0c0982a6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c0982a8;
P_0c0982a8: /* original 8f08, guest PC 0x0c0982a8 */
if(!s->budget--) { s->failed_pc=0x0c0982a8u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c0982bc; }
goto P_0c0982ac;
P_0c0982aa: /* original 2f32, guest PC 0x0c0982aa */
if(!s->budget--) { s->failed_pc=0x0c0982aau; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0982ac;
P_0c0982ac: /* original e029, guest PC 0x0c0982ac */
if(!s->budget--) { s->failed_pc=0x0c0982acu; return 0; }
r[0]=0x00000029u;
goto P_0c0982ae;
P_0c0982ae: /* original 00ec, guest PC 0x0c0982ae */
if(!s->budget--) { s->failed_pc=0x0c0982aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0982b0;
P_0c0982b0: /* original 600c, guest PC 0x0c0982b0 */
if(!s->budget--) { s->failed_pc=0x0c0982b0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0982b2;
P_0c0982b2: /* original 8802, guest PC 0x0c0982b2 */
if(!s->budget--) { s->failed_pc=0x0c0982b2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0982b4;
P_0c0982b4: /* original 8901, guest PC 0x0c0982b4 */
if(!s->budget--) { s->failed_pc=0x0c0982b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0982ba; }
goto P_0c0982b6;
P_0c0982b6: /* original a001, guest PC 0x0c0982b6 */
if(!s->budget--) { s->failed_pc=0x0c0982b6u; return 0; }
r[4]+=0xfffffff3u;
goto P_0c0982bc;
P_0c0982b8: /* original 74f3, guest PC 0x0c0982b8 */
if(!s->budget--) { s->failed_pc=0x0c0982b8u; return 0; }
r[4]+=0xfffffff3u;
goto P_0c0982ba;
P_0c0982ba: /* original 740d, guest PC 0x0c0982ba */
if(!s->budget--) { s->failed_pc=0x0c0982bau; return 0; }
r[4]+=0x0000000du;
goto P_0c0982bc;
P_0c0982bc: /* original 77ff, guest PC 0x0c0982bc */
if(!s->budget--) { s->failed_pc=0x0c0982bcu; return 0; }
r[7]+=0xffffffffu;
goto P_0c0982be;
P_0c0982be: /* original 4711, guest PC 0x0c0982be */
if(!s->budget--) { s->failed_pc=0x0c0982beu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=0)!=0);
goto P_0c0982c0;
P_0c0982c0: /* original 89ee, guest PC 0x0c0982c0 */
if(!s->budget--) { s->failed_pc=0x0c0982c0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0982a0; }
goto P_0c0982c2;
P_0c0982c2: /* original 78ff, guest PC 0x0c0982c2 */
if(!s->budget--) { s->failed_pc=0x0c0982c2u; return 0; }
r[8]+=0xffffffffu;
goto P_0c0982c4;
P_0c0982c4: /* original 2540, guest PC 0x0c0982c4 */
if(!s->budget--) { s->failed_pc=0x0c0982c4u; return 0; }
write(ram,r[5],r[4],1);
goto P_0c0982c6;
P_0c0982c6: /* original 924d, guest PC 0x0c0982c6 */
if(!s->budget--) { s->failed_pc=0x0c0982c6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098364u,2);
goto P_0c0982c8;
P_0c0982c8: /* original 4815, guest PC 0x0c0982c8 */
if(!s->budget--) { s->failed_pc=0x0c0982c8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>0)!=0);
goto P_0c0982ca;
P_0c0982ca: /* original 53f2, guest PC 0x0c0982ca */
if(!s->budget--) { s->failed_pc=0x0c0982cau; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0982cc;
P_0c0982cc: /* original 7501, guest PC 0x0c0982cc */
if(!s->budget--) { s->failed_pc=0x0c0982ccu; return 0; }
r[5]+=0x00000001u;
goto P_0c0982ce;
P_0c0982ce: /* original 32ec, guest PC 0x0c0982ce */
if(!s->budget--) { s->failed_pc=0x0c0982ceu; return 0; }
r[2]+=r[14];
goto P_0c0982d0;
P_0c0982d0: /* original 323c, guest PC 0x0c0982d0 */
if(!s->budget--) { s->failed_pc=0x0c0982d0u; return 0; }
r[2]+=r[3];
goto P_0c0982d2;
P_0c0982d2: /* original 6120, guest PC 0x0c0982d2 */
if(!s->budget--) { s->failed_pc=0x0c0982d2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c0982d4;
P_0c0982d4: /* original 7101, guest PC 0x0c0982d4 */
if(!s->budget--) { s->failed_pc=0x0c0982d4u; return 0; }
r[1]+=0x00000001u;
goto P_0c0982d6;
P_0c0982d6: /* original 8dd4, guest PC 0x0c0982d6 */
if(!s->budget--) { s->failed_pc=0x0c0982d6u; return 0; }
cond=r[17]&1u;
write(ram,r[2],r[1],1);
if(cond) { goto P_0c098282; }
goto P_0c0982da;
P_0c0982d8: /* original 2210, guest PC 0x0c0982d8 */
if(!s->budget--) { s->failed_pc=0x0c0982d8u; return 0; }
write(ram,r[2],r[1],1);
goto P_0c0982da;
P_0c0982da: /* original 903f, guest PC 0x0c0982da */
if(!s->budget--) { s->failed_pc=0x0c0982dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09835cu,2);
goto P_0c0982dc;
P_0c0982dc: /* original 5ba4, guest PC 0x0c0982dc */
if(!s->budget--) { s->failed_pc=0x0c0982dcu; return 0; }
r[11]=read(ram,r[10]+16,4);
goto P_0c0982de;
P_0c0982de: /* original 05ec, guest PC 0x0c0982de */
if(!s->budget--) { s->failed_pc=0x0c0982deu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0982e0;
P_0c0982e0: /* original 7005, guest PC 0x0c0982e0 */
if(!s->budget--) { s->failed_pc=0x0c0982e0u; return 0; }
r[0]+=0x00000005u;
goto P_0c0982e2;
P_0c0982e2: /* original 04ec, guest PC 0x0c0982e2 */
if(!s->budget--) { s->failed_pc=0x0c0982e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0982e4;
P_0c0982e4: /* original 655c, guest PC 0x0c0982e4 */
if(!s->budget--) { s->failed_pc=0x0c0982e4u; return 0; }
r[5]=r[5]&255u;
goto P_0c0982e6;
P_0c0982e6: /* original 644c, guest PC 0x0c0982e6 */
if(!s->budget--) { s->failed_pc=0x0c0982e6u; return 0; }
r[4]=r[4]&255u;
goto P_0c0982e8;
P_0c0982e8: /* original 3592, guest PC 0x0c0982e8 */
if(!s->budget--) { s->failed_pc=0x0c0982e8u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[9])!=0);
goto P_0c0982ea;
P_0c0982ea: /* original 6653, guest PC 0x0c0982ea */
if(!s->budget--) { s->failed_pc=0x0c0982eau; return 0; }
r[6]=r[5];
goto P_0c0982ec;
P_0c0982ec: /* original 6c43, guest PC 0x0c0982ec */
if(!s->budget--) { s->failed_pc=0x0c0982ecu; return 0; }
r[12]=r[4];
goto P_0c0982ee;
P_0c0982ee: /* original 8f02, guest PC 0x0c0982ee */
if(!s->budget--) { s->failed_pc=0x0c0982eeu; return 0; }
cond=r[17]&1u;
r[7]=read(ram,r[10]+20,4);
if(!cond) { goto P_0c0982f6; }
goto P_0c0982f2;
P_0c0982f0: /* original 57a5, guest PC 0x0c0982f0 */
if(!s->budget--) { s->failed_pc=0x0c0982f0u; return 0; }
r[7]=read(ram,r[10]+20,4);
goto P_0c0982f2;
P_0c0982f2: /* original 6653, guest PC 0x0c0982f2 */
if(!s->budget--) { s->failed_pc=0x0c0982f2u; return 0; }
r[6]=r[5];
goto P_0c0982f4;
P_0c0982f4: /* original 76f3, guest PC 0x0c0982f4 */
if(!s->budget--) { s->failed_pc=0x0c0982f4u; return 0; }
r[6]+=0xfffffff3u;
goto P_0c0982f6;
P_0c0982f6: /* original 3492, guest PC 0x0c0982f6 */
if(!s->budget--) { s->failed_pc=0x0c0982f6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[9])!=0);
goto P_0c0982f8;
P_0c0982f8: /* original 8f02, guest PC 0x0c0982f8 */
if(!s->budget--) { s->failed_pc=0x0c0982f8u; return 0; }
cond=r[17]&1u;
r[0]=0x00000061u;
if(!cond) { goto P_0c098300; }
goto P_0c0982fc;
P_0c0982fa: /* original e061, guest PC 0x0c0982fa */
if(!s->budget--) { s->failed_pc=0x0c0982fau; return 0; }
r[0]=0x00000061u;
goto P_0c0982fc;
P_0c0982fc: /* original 6c43, guest PC 0x0c0982fc */
if(!s->budget--) { s->failed_pc=0x0c0982fcu; return 0; }
r[12]=r[4];
goto P_0c0982fe;
P_0c0982fe: /* original 7cf3, guest PC 0x0c0982fe */
if(!s->budget--) { s->failed_pc=0x0c0982feu; return 0; }
r[12]+=0xfffffff3u;
goto P_0c098300;
P_0c098300: /* original 0b64, guest PC 0x0c098300 */
if(!s->budget--) { s->failed_pc=0x0c098300u; return 0; }
write(ram,r[11]+r[0],r[6],1);
goto P_0c098302;
P_0c098302: /* original 07c4, guest PC 0x0c098302 */
if(!s->budget--) { s->failed_pc=0x0c098302u; return 0; }
write(ram,r[7]+r[0],r[12],1);
goto P_0c098304;
P_0c098304: /* original e060, guest PC 0x0c098304 */
if(!s->budget--) { s->failed_pc=0x0c098304u; return 0; }
r[0]=0x00000060u;
goto P_0c098306;
P_0c098306: /* original 0b54, guest PC 0x0c098306 */
if(!s->budget--) { s->failed_pc=0x0c098306u; return 0; }
write(ram,r[11]+r[0],r[5],1);
goto P_0c098308;
P_0c098308: /* original a03a, guest PC 0x0c098308 */
if(!s->budget--) { s->failed_pc=0x0c098308u; return 0; }
write(ram,r[7]+r[0],r[4],1);
goto P_0c098380;
P_0c09830a: /* original 0744, guest PC 0x0c09830a */
if(!s->budget--) { s->failed_pc=0x0c09830au; return 0; }
write(ram,r[7]+r[0],r[4],1);
goto P_0c09830c;
P_0c09830c: /* original e029, guest PC 0x0c09830c */
if(!s->budget--) { s->failed_pc=0x0c09830cu; return 0; }
r[0]=0x00000029u;
goto P_0c09830e;
P_0c09830e: /* original 05ec, guest PC 0x0c09830e */
if(!s->budget--) { s->failed_pc=0x0c09830eu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098310;
P_0c098310: /* original e060, guest PC 0x0c098310 */
if(!s->budget--) { s->failed_pc=0x0c098310u; return 0; }
r[0]=0x00000060u;
goto P_0c098312;
P_0c098312: /* original 03bc, guest PC 0x0c098312 */
if(!s->budget--) { s->failed_pc=0x0c098312u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c098314;
P_0c098314: /* original e060, guest PC 0x0c098314 */
if(!s->budget--) { s->failed_pc=0x0c098314u; return 0; }
r[0]=0x00000060u;
goto P_0c098316;
P_0c098316: /* original 655c, guest PC 0x0c098316 */
if(!s->budget--) { s->failed_pc=0x0c098316u; return 0; }
r[5]=r[5]&255u;
goto P_0c098318;
P_0c098318: /* original 633c, guest PC 0x0c098318 */
if(!s->budget--) { s->failed_pc=0x0c098318u; return 0; }
r[3]=r[3]&255u;
goto P_0c09831a;
P_0c09831a: /* original 6653, guest PC 0x0c09831a */
if(!s->budget--) { s->failed_pc=0x0c09831au; return 0; }
r[6]=r[5];
goto P_0c09831c;
P_0c09831c: /* original 1f31, guest PC 0x0c09831c */
if(!s->budget--) { s->failed_pc=0x0c09831cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09831e;
P_0c09831e: /* original 6753, guest PC 0x0c09831e */
if(!s->budget--) { s->failed_pc=0x0c09831eu; return 0; }
r[7]=r[5];
goto P_0c098320;
P_0c098320: /* original 02cc, guest PC 0x0c098320 */
if(!s->budget--) { s->failed_pc=0x0c098320u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c098322;
P_0c098322: /* original e061, guest PC 0x0c098322 */
if(!s->budget--) { s->failed_pc=0x0c098322u; return 0; }
r[0]=0x00000061u;
goto P_0c098324;
P_0c098324: /* original 77ff, guest PC 0x0c098324 */
if(!s->budget--) { s->failed_pc=0x0c098324u; return 0; }
r[7]+=0xffffffffu;
goto P_0c098326;
P_0c098326: /* original 622c, guest PC 0x0c098326 */
if(!s->budget--) { s->failed_pc=0x0c098326u; return 0; }
r[2]=r[2]&255u;
goto P_0c098328;
P_0c098328: /* original 2f22, guest PC 0x0c098328 */
if(!s->budget--) { s->failed_pc=0x0c098328u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c09832a;
P_0c09832a: /* original 2778, guest PC 0x0c09832a */
if(!s->budget--) { s->failed_pc=0x0c09832au; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c09832c;
P_0c09832c: /* original 03cc, guest PC 0x0c09832c */
if(!s->budget--) { s->failed_pc=0x0c09832cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c09832e;
P_0c09832e: /* original 633c, guest PC 0x0c09832e */
if(!s->budget--) { s->failed_pc=0x0c09832eu; return 0; }
r[3]=r[3]&255u;
goto P_0c098330;
P_0c098330: /* original 1f32, guest PC 0x0c098330 */
if(!s->budget--) { s->failed_pc=0x0c098330u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c098332;
P_0c098332: /* original 53f1, guest PC 0x0c098332 */
if(!s->budget--) { s->failed_pc=0x0c098332u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c098334;
P_0c098334: /* original 9017, guest PC 0x0c098334 */
if(!s->budget--) { s->failed_pc=0x0c098334u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098366u,2);
goto P_0c098336;
P_0c098336: /* original 73f3, guest PC 0x0c098336 */
if(!s->budget--) { s->failed_pc=0x0c098336u; return 0; }
r[3]+=0xfffffff3u;
goto P_0c098338;
P_0c098338: /* original 04de, guest PC 0x0c098338 */
if(!s->budget--) { s->failed_pc=0x0c098338u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c09833a;
P_0c09833a: /* original 1f31, guest PC 0x0c09833a */
if(!s->budget--) { s->failed_pc=0x0c09833au; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09833c;
P_0c09833c: /* original 62f2, guest PC 0x0c09833c */
if(!s->budget--) { s->failed_pc=0x0c09833cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09833e;
P_0c09833e: /* original 72f3, guest PC 0x0c09833e */
if(!s->budget--) { s->failed_pc=0x0c09833eu; return 0; }
r[2]+=0xfffffff3u;
goto P_0c098340;
P_0c098340: /* original 2f22, guest PC 0x0c098340 */
if(!s->budget--) { s->failed_pc=0x0c098340u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c098342;
P_0c098342: /* original 51f2, guest PC 0x0c098342 */
if(!s->budget--) { s->failed_pc=0x0c098342u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c098344;
P_0c098344: /* original d509, guest PC 0x0c098344 */
if(!s->budget--) { s->failed_pc=0x0c098344u; return 0; }
r[5]=read(ram,0x0c09836cu,4);
goto P_0c098346;
P_0c098346: /* original 611b, guest PC 0x0c098346 */
if(!s->budget--) { s->failed_pc=0x0c098346u; return 0; }
r[1]=0u-r[1];
goto P_0c098348;
P_0c098348: /* original 451d, guest PC 0x0c098348 */
if(!s->budget--) { s->failed_pc=0x0c098348u; return 0; }
r[5]=(r[1]&0x80000000u)?((r[1]&31u)?r[5]>>((-r[1])&31u):0):r[5]<<(r[1]&31u);
goto P_0c09834a;
P_0c09834a: /* original 8f11, guest PC 0x0c09834a */
if(!s->budget--) { s->failed_pc=0x0c09834au; return 0; }
cond=r[17]&1u;
r[6]+=0xfffffffeu;
if(!cond) { goto P_0c098370; }
goto P_0c09834e;
P_0c09834c: /* original 76fe, guest PC 0x0c09834c */
if(!s->budget--) { s->failed_pc=0x0c09834cu; return 0; }
r[6]+=0xfffffffeu;
goto P_0c09834e;
P_0c09834e: /* original 53f1, guest PC 0x0c09834e */
if(!s->budget--) { s->failed_pc=0x0c09834eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c098350;
P_0c098350: /* original 4311, guest PC 0x0c098350 */
if(!s->budget--) { s->failed_pc=0x0c098350u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c098352;
P_0c098352: /* original 8b15, guest PC 0x0c098352 */
if(!s->budget--) { s->failed_pc=0x0c098352u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098380; }
goto P_0c098354;
P_0c098354: /* original 9007, guest PC 0x0c098354 */
if(!s->budget--) { s->failed_pc=0x0c098354u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098366u,2);
goto P_0c098356;
P_0c098356: /* original 245b, guest PC 0x0c098356 */
if(!s->budget--) { s->failed_pc=0x0c098356u; return 0; }
r[4]|=r[5];
goto P_0c098358;
P_0c098358: /* original a012, guest PC 0x0c098358 */
if(!s->budget--) { s->failed_pc=0x0c098358u; return 0; }
write(ram,r[13]+r[0],r[4],4);
goto P_0c098380;
P_0c09835a: /* original 0d46, guest PC 0x0c09835a */
if(!s->budget--) { s->failed_pc=0x0c09835au; return 0; }
write(ram,r[13]+r[0],r[4],4);
if(!vf3_matrix_family(0x0c09835cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09835cu; return 0; } return 1;
P_0c098370: /* original 2668, guest PC 0x0c098370 */
if(!s->budget--) { s->failed_pc=0x0c098370u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c098372;
P_0c098372: /* original 8b05, guest PC 0x0c098372 */
if(!s->budget--) { s->failed_pc=0x0c098372u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098380; }
goto P_0c098374;
P_0c098374: /* original 62f2, guest PC 0x0c098374 */
if(!s->budget--) { s->failed_pc=0x0c098374u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c098376;
P_0c098376: /* original 4211, guest PC 0x0c098376 */
if(!s->budget--) { s->failed_pc=0x0c098376u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c098378;
P_0c098378: /* original 8b02, guest PC 0x0c098378 */
if(!s->budget--) { s->failed_pc=0x0c098378u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098380; }
goto P_0c09837a;
P_0c09837a: /* original 905b, guest PC 0x0c09837a */
if(!s->budget--) { s->failed_pc=0x0c09837au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098434u,2);
goto P_0c09837c;
P_0c09837c: /* original 245b, guest PC 0x0c09837c */
if(!s->budget--) { s->failed_pc=0x0c09837cu; return 0; }
r[4]|=r[5];
goto P_0c09837e;
P_0c09837e: /* original 0d46, guest PC 0x0c09837e */
if(!s->budget--) { s->failed_pc=0x0c09837eu; return 0; }
write(ram,r[13]+r[0],r[4],4);
goto P_0c098380;
P_0c098380: /* original e010, guest PC 0x0c098380 */
if(!s->budget--) { s->failed_pc=0x0c098380u; return 0; }
r[0]=0x00000010u;
goto P_0c098382;
P_0c098382: /* original e315, guest PC 0x0c098382 */
if(!s->budget--) { s->failed_pc=0x0c098382u; return 0; }
r[3]=0x00000015u;
goto P_0c098384;
P_0c098384: /* original 0d34, guest PC 0x0c098384 */
if(!s->budget--) { s->failed_pc=0x0c098384u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c098386;
P_0c098386: /* original 9256, guest PC 0x0c098386 */
if(!s->budget--) { s->failed_pc=0x0c098386u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098436u,2);
goto P_0c098388;
P_0c098388: /* original 1d23, guest PC 0x0c098388 */
if(!s->budget--) { s->failed_pc=0x0c098388u; return 0; }
write(ram,r[13]+12,r[2],4);
goto P_0c09838a;
P_0c09838a: /* original 84db, guest PC 0x0c09838a */
if(!s->budget--) { s->failed_pc=0x0c09838au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+11,1);
goto P_0c09838c;
P_0c09838c: /* original 7001, guest PC 0x0c09838c */
if(!s->budget--) { s->failed_pc=0x0c09838cu; return 0; }
r[0]+=0x00000001u;
goto P_0c09838e;
P_0c09838e: /* original 80db, guest PC 0x0c09838e */
if(!s->budget--) { s->failed_pc=0x0c09838eu; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c098390;
P_0c098390: /* original d32a, guest PC 0x0c098390 */
if(!s->budget--) { s->failed_pc=0x0c098390u; return 0; }
r[3]=read(ram,0x0c09843cu,4);
goto P_0c098392;
P_0c098392: /* original 430b, guest PC 0x0c098392 */
if(!s->budget--) { s->failed_pc=0x0c098392u; return 0; }
target=r[3];
r[16]=code_base|0x0c098396u;
r[4]=read(ram,r[10]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098396u) { target=s->pc; goto dispatch; }
goto P_0c098396;
P_0c098394: /* original 54a8, guest PC 0x0c098394 */
if(!s->budget--) { s->failed_pc=0x0c098394u; return 0; }
r[4]=read(ram,r[10]+32,4);
goto P_0c098396;
P_0c098396: /* original d329, guest PC 0x0c098396 */
if(!s->budget--) { s->failed_pc=0x0c098396u; return 0; }
r[3]=read(ram,0x0c09843cu,4);
goto P_0c098398;
P_0c098398: /* original e044, guest PC 0x0c098398 */
if(!s->budget--) { s->failed_pc=0x0c098398u; return 0; }
r[0]=0x00000044u;
goto P_0c09839a;
P_0c09839a: /* original 430b, guest PC 0x0c09839a */
if(!s->budget--) { s->failed_pc=0x0c09839au; return 0; }
target=r[3];
r[16]=code_base|0x0c09839eu;
r[4]=read(ram,r[10]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09839eu) { target=s->pc; goto dispatch; }
goto P_0c09839e;
P_0c09839c: /* original 04ae, guest PC 0x0c09839c */
if(!s->budget--) { s->failed_pc=0x0c09839cu; return 0; }
r[4]=read(ram,r[10]+r[0],4);
goto P_0c09839e;
P_0c09839e: /* original 7f0c, guest PC 0x0c09839e */
if(!s->budget--) { s->failed_pc=0x0c09839eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0983a0;
P_0c0983a0: /* original 4f16, guest PC 0x0c0983a0 */
if(!s->budget--) { s->failed_pc=0x0c0983a0u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0983a2;
P_0c0983a2: /* original e07c, guest PC 0x0c0983a2 */
if(!s->budget--) { s->failed_pc=0x0c0983a2u; return 0; }
r[0]=0x0000007cu;
goto P_0c0983a4;
P_0c0983a4: /* original 02ec, guest PC 0x0c0983a4 */
if(!s->budget--) { s->failed_pc=0x0c0983a4u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0983a6;
P_0c0983a6: /* original e01c, guest PC 0x0c0983a6 */
if(!s->budget--) { s->failed_pc=0x0c0983a6u; return 0; }
r[0]=0x0000001cu;
goto P_0c0983a8;
P_0c0983a8: /* original 4f26, guest PC 0x0c0983a8 */
if(!s->budget--) { s->failed_pc=0x0c0983a8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0983aa;
P_0c0983aa: /* original 0d24, guest PC 0x0c0983aa */
if(!s->budget--) { s->failed_pc=0x0c0983aau; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c0983ac;
P_0c0983ac: /* original 68f6, guest PC 0x0c0983ac */
if(!s->budget--) { s->failed_pc=0x0c0983acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0983ae;
P_0c0983ae: /* original 69f6, guest PC 0x0c0983ae */
if(!s->budget--) { s->failed_pc=0x0c0983aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0983b0;
P_0c0983b0: /* original 6af6, guest PC 0x0c0983b0 */
if(!s->budget--) { s->failed_pc=0x0c0983b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0983b2;
P_0c0983b2: /* original 6bf6, guest PC 0x0c0983b2 */
if(!s->budget--) { s->failed_pc=0x0c0983b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0983b4;
P_0c0983b4: /* original 6cf6, guest PC 0x0c0983b4 */
if(!s->budget--) { s->failed_pc=0x0c0983b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0983b6;
P_0c0983b6: /* original 6df6, guest PC 0x0c0983b6 */
if(!s->budget--) { s->failed_pc=0x0c0983b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0983b8;
P_0c0983b8: /* original ae1c, guest PC 0x0c0983b8 */
if(!s->budget--) { s->failed_pc=0x0c0983b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c097ff4u,s,ram);
P_0c0983ba: /* original 6ef6, guest PC 0x0c0983ba */
if(!s->budget--) { s->failed_pc=0x0c0983bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0983bc;
P_0c0983bc: /* original 2fe6, guest PC 0x0c0983bc */
if(!s->budget--) { s->failed_pc=0x0c0983bcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0983be;
P_0c0983be: /* original 2fd6, guest PC 0x0c0983be */
if(!s->budget--) { s->failed_pc=0x0c0983beu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0983c0;
P_0c0983c0: /* original 2fc6, guest PC 0x0c0983c0 */
if(!s->budget--) { s->failed_pc=0x0c0983c0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0983c2;
P_0c0983c2: /* original fffb, guest PC 0x0c0983c2 */
if(!s->budget--) { s->failed_pc=0x0c0983c2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0983c4;
P_0c0983c4: /* original de1f, guest PC 0x0c0983c4 */
if(!s->budget--) { s->failed_pc=0x0c0983c4u; return 0; }
r[14]=read(ram,0x0c098444u,4);
goto P_0c0983c6;
P_0c0983c6: /* original 4f22, guest PC 0x0c0983c6 */
if(!s->budget--) { s->failed_pc=0x0c0983c6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0983c8;
P_0c0983c8: /* original 53e3, guest PC 0x0c0983c8 */
if(!s->budget--) { s->failed_pc=0x0c0983c8u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c0983ca;
P_0c0983ca: /* original dc1d, guest PC 0x0c0983ca */
if(!s->budget--) { s->failed_pc=0x0c0983cau; return 0; }
r[12]=read(ram,0x0c098440u,4);
goto P_0c0983cc;
P_0c0983cc: /* original 4315, guest PC 0x0c0983cc */
if(!s->budget--) { s->failed_pc=0x0c0983ccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c0983ce;
P_0c0983ce: /* original 892b, guest PC 0x0c0983ce */
if(!s->budget--) { s->failed_pc=0x0c0983ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098428; }
goto P_0c0983d0;
P_0c0983d0: /* original d21d, guest PC 0x0c0983d0 */
if(!s->budget--) { s->failed_pc=0x0c0983d0u; return 0; }
r[2]=read(ram,0x0c098448u,4);
goto P_0c0983d2;
P_0c0983d2: /* original 420b, guest PC 0x0c0983d2 */
if(!s->budget--) { s->failed_pc=0x0c0983d2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0983d6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0983d6u) { target=s->pc; goto dispatch; }
goto P_0c0983d6;
P_0c0983d4: /* original 0009, guest PC 0x0c0983d4 */
if(!s->budget--) { s->failed_pc=0x0c0983d4u; return 0; }
goto P_0c0983d6;
P_0c0983d6: /* original d31d, guest PC 0x0c0983d6 */
if(!s->budget--) { s->failed_pc=0x0c0983d6u; return 0; }
r[3]=read(ram,0x0c09844cu,4);
goto P_0c0983d8;
P_0c0983d8: /* original e500, guest PC 0x0c0983d8 */
if(!s->budget--) { s->failed_pc=0x0c0983d8u; return 0; }
r[5]=0x00000000u;
goto P_0c0983da;
P_0c0983da: /* original ff8d, guest PC 0x0c0983da */
if(!s->budget--) { s->failed_pc=0x0c0983dau; return 0; }
fr[15]=0;
goto P_0c0983dc;
P_0c0983dc: /* original f4fc, guest PC 0x0c0983dc */
if(!s->budget--) { s->failed_pc=0x0c0983dcu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0983de;
P_0c0983de: /* original f5fc, guest PC 0x0c0983de */
if(!s->budget--) { s->failed_pc=0x0c0983deu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0983e0;
P_0c0983e0: /* original f6fc, guest PC 0x0c0983e0 */
if(!s->budget--) { s->failed_pc=0x0c0983e0u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0983e2;
P_0c0983e2: /* original 430b, guest PC 0x0c0983e2 */
if(!s->budget--) { s->failed_pc=0x0c0983e2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0983e6u;
r[4]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0983e6u) { target=s->pc; goto dispatch; }
goto P_0c0983e6;
P_0c0983e4: /* original 6453, guest PC 0x0c0983e4 */
if(!s->budget--) { s->failed_pc=0x0c0983e4u; return 0; }
r[4]=r[5];
goto P_0c0983e6;
P_0c0983e6: /* original d219, guest PC 0x0c0983e6 */
if(!s->budget--) { s->failed_pc=0x0c0983e6u; return 0; }
r[2]=read(ram,0x0c09844cu,4);
goto P_0c0983e8;
P_0c0983e8: /* original e500, guest PC 0x0c0983e8 */
if(!s->budget--) { s->failed_pc=0x0c0983e8u; return 0; }
r[5]=0x00000000u;
goto P_0c0983ea;
P_0c0983ea: /* original f4fc, guest PC 0x0c0983ea */
if(!s->budget--) { s->failed_pc=0x0c0983eau; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0983ec;
P_0c0983ec: /* original f5fc, guest PC 0x0c0983ec */
if(!s->budget--) { s->failed_pc=0x0c0983ecu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0983ee;
P_0c0983ee: /* original f6fc, guest PC 0x0c0983ee */
if(!s->budget--) { s->failed_pc=0x0c0983eeu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0983f0;
P_0c0983f0: /* original 420b, guest PC 0x0c0983f0 */
if(!s->budget--) { s->failed_pc=0x0c0983f0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0983f4u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0983f4u) { target=s->pc; goto dispatch; }
goto P_0c0983f4;
P_0c0983f2: /* original e401, guest PC 0x0c0983f2 */
if(!s->budget--) { s->failed_pc=0x0c0983f2u; return 0; }
r[4]=0x00000001u;
goto P_0c0983f4;
P_0c0983f4: /* original d316, guest PC 0x0c0983f4 */
if(!s->budget--) { s->failed_pc=0x0c0983f4u; return 0; }
r[3]=read(ram,0x0c098450u,4);
goto P_0c0983f6;
P_0c0983f6: /* original 430b, guest PC 0x0c0983f6 */
if(!s->budget--) { s->failed_pc=0x0c0983f6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0983fau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0983fau) { target=s->pc; goto dispatch; }
goto P_0c0983fa;
P_0c0983f8: /* original 0009, guest PC 0x0c0983f8 */
if(!s->budget--) { s->failed_pc=0x0c0983f8u; return 0; }
goto P_0c0983fa;
P_0c0983fa: /* original 2008, guest PC 0x0c0983fa */
if(!s->budget--) { s->failed_pc=0x0c0983fau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0983fc;
P_0c0983fc: /* original 8b02, guest PC 0x0c0983fc */
if(!s->budget--) { s->failed_pc=0x0c0983fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098404; }
goto P_0c0983fe;
P_0c0983fe: /* original e301, guest PC 0x0c0983fe */
if(!s->budget--) { s->failed_pc=0x0c0983feu; return 0; }
r[3]=0x00000001u;
goto P_0c098400;
P_0c098400: /* original a012, guest PC 0x0c098400 */
if(!s->budget--) { s->failed_pc=0x0c098400u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c098428;
P_0c098402: /* original 1e33, guest PC 0x0c098402 */
if(!s->budget--) { s->failed_pc=0x0c098402u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c098404;
P_0c098404: /* original d314, guest PC 0x0c098404 */
if(!s->budget--) { s->failed_pc=0x0c098404u; return 0; }
r[3]=read(ram,0x0c098458u,4);
goto P_0c098406;
P_0c098406: /* original dd13, guest PC 0x0c098406 */
if(!s->budget--) { s->failed_pc=0x0c098406u; return 0; }
r[13]=read(ram,0x0c098454u,4);
goto P_0c098408;
P_0c098408: /* original 430b, guest PC 0x0c098408 */
if(!s->budget--) { s->failed_pc=0x0c098408u; return 0; }
target=r[3];
r[16]=code_base|0x0c09840cu;
r[4]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09840cu) { target=s->pc; goto dispatch; }
goto P_0c09840c;
P_0c09840a: /* original 54d8, guest PC 0x0c09840a */
if(!s->budget--) { s->failed_pc=0x0c09840au; return 0; }
r[4]=read(ram,r[13]+32,4);
goto P_0c09840c;
P_0c09840c: /* original d312, guest PC 0x0c09840c */
if(!s->budget--) { s->failed_pc=0x0c09840cu; return 0; }
r[3]=read(ram,0x0c098458u,4);
goto P_0c09840e;
P_0c09840e: /* original e044, guest PC 0x0c09840e */
if(!s->budget--) { s->failed_pc=0x0c09840eu; return 0; }
r[0]=0x00000044u;
goto P_0c098410;
P_0c098410: /* original 430b, guest PC 0x0c098410 */
if(!s->budget--) { s->failed_pc=0x0c098410u; return 0; }
target=r[3];
r[16]=code_base|0x0c098414u;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098414u) { target=s->pc; goto dispatch; }
goto P_0c098414;
P_0c098412: /* original 04de, guest PC 0x0c098412 */
if(!s->budget--) { s->failed_pc=0x0c098412u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c098414;
P_0c098414: /* original e029, guest PC 0x0c098414 */
if(!s->budget--) { s->failed_pc=0x0c098414u; return 0; }
r[0]=0x00000029u;
goto P_0c098416;
P_0c098416: /* original 02cc, guest PC 0x0c098416 */
if(!s->budget--) { s->failed_pc=0x0c098416u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c098418;
P_0c098418: /* original e300, guest PC 0x0c098418 */
if(!s->budget--) { s->failed_pc=0x0c098418u; return 0; }
r[3]=0x00000000u;
goto P_0c09841a;
P_0c09841a: /* original 900d, guest PC 0x0c09841a */
if(!s->budget--) { s->failed_pc=0x0c09841au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098438u,2);
goto P_0c09841c;
P_0c09841c: /* original 0e24, guest PC 0x0c09841c */
if(!s->budget--) { s->failed_pc=0x0c09841cu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c09841e;
P_0c09841e: /* original 900c, guest PC 0x0c09841e */
if(!s->budget--) { s->failed_pc=0x0c09841eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09843au,2);
goto P_0c098420;
P_0c098420: /* original 0c34, guest PC 0x0c098420 */
if(!s->budget--) { s->failed_pc=0x0c098420u; return 0; }
write(ram,r[12]+r[0],r[3],1);
goto P_0c098422;
P_0c098422: /* original 84eb, guest PC 0x0c098422 */
if(!s->budget--) { s->failed_pc=0x0c098422u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c098424;
P_0c098424: /* original 7001, guest PC 0x0c098424 */
if(!s->budget--) { s->failed_pc=0x0c098424u; return 0; }
r[0]+=0x00000001u;
goto P_0c098426;
P_0c098426: /* original 80eb, guest PC 0x0c098426 */
if(!s->budget--) { s->failed_pc=0x0c098426u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c098428;
P_0c098428: /* original 4f26, guest PC 0x0c098428 */
if(!s->budget--) { s->failed_pc=0x0c098428u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09842a;
P_0c09842a: /* original fff9, guest PC 0x0c09842a */
if(!s->budget--) { s->failed_pc=0x0c09842au; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09842c;
P_0c09842c: /* original 6cf6, guest PC 0x0c09842c */
if(!s->budget--) { s->failed_pc=0x0c09842cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09842e;
P_0c09842e: /* original 6df6, guest PC 0x0c09842e */
if(!s->budget--) { s->failed_pc=0x0c09842eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c098430;
P_0c098430: /* original ade0, guest PC 0x0c098430 */
if(!s->budget--) { s->failed_pc=0x0c098430u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c097ff4u,s,ram);
P_0c098432: /* original 6ef6, guest PC 0x0c098432 */
if(!s->budget--) { s->failed_pc=0x0c098432u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c098434u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c098434u; return 0; } return 1;
P_0c0a13a4: /* original d224, guest PC 0x0c0a13a4 */
if(!s->budget--) { s->failed_pc=0x0c0a13a4u; return 0; }
r[2]=read(ram,0x0c0a1438u,4);
goto P_0c0a13a6;
P_0c0a13a6: /* original 6322, guest PC 0x0c0a13a6 */
if(!s->budget--) { s->failed_pc=0x0c0a13a6u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0a13a8;
P_0c0a13a8: /* original 435a, guest PC 0x0c0a13a8 */
if(!s->budget--) { s->failed_pc=0x0c0a13a8u; return 0; }
r[53]=r[3];
goto P_0c0a13aa;
P_0c0a13aa: /* original 4311, guest PC 0x0c0a13aa */
if(!s->budget--) { s->failed_pc=0x0c0a13aau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0a13ac;
P_0c0a13ac: /* original 8d04, guest PC 0x0c0a13ac */
if(!s->budget--) { s->failed_pc=0x0c0a13acu; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0a13b8; }
goto P_0c0a13b0;
P_0c0a13ae: /* original f32d, guest PC 0x0c0a13ae */
if(!s->budget--) { s->failed_pc=0x0c0a13aeu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0a13b0;
P_0c0a13b0: /* original d222, guest PC 0x0c0a13b0 */
if(!s->budget--) { s->failed_pc=0x0c0a13b0u; return 0; }
r[2]=read(ram,0x0c0a143cu,4);
goto P_0c0a13b2;
P_0c0a13b2: /* original 425a, guest PC 0x0c0a13b2 */
if(!s->budget--) { s->failed_pc=0x0c0a13b2u; return 0; }
r[53]=r[2];
goto P_0c0a13b4;
P_0c0a13b4: /* original f20d, guest PC 0x0c0a13b4 */
if(!s->budget--) { s->failed_pc=0x0c0a13b4u; return 0; }
fr[2]=r[53];
goto P_0c0a13b6;
P_0c0a13b6: /* original f320, guest PC 0x0c0a13b6 */
if(!s->budget--) { s->failed_pc=0x0c0a13b6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0a13b8;
P_0c0a13b8: /* original c721, guest PC 0x0c0a13b8 */
if(!s->budget--) { s->failed_pc=0x0c0a13b8u; return 0; }
r[0]=code_base|0x000a1440u;
goto P_0c0a13ba;
P_0c0a13ba: /* original f03c, guest PC 0x0c0a13ba */
if(!s->budget--) { s->failed_pc=0x0c0a13bau; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c0a13bc;
P_0c0a13bc: /* original f208, guest PC 0x0c0a13bc */
if(!s->budget--) { s->failed_pc=0x0c0a13bcu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0a13be;
P_0c0a13be: /* original 000b, guest PC 0x0c0a13be */
if(!s->budget--) { s->failed_pc=0x0c0a13beu; return 0; }
target=r[16];
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'/');
s->pc=target; return ram->oob==0;
P_0c0a13c0: /* original f023, guest PC 0x0c0a13c0 */
if(!s->budget--) { s->failed_pc=0x0c0a13c0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'/');
if(!vf3_matrix_family(0x0c0a13c2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a13c2u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
