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
int vf3_away_batch10_adapter_28(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c071140u: goto P_0c071140;
case 0x0c071142u: goto P_0c071142;
case 0x0c071144u: goto P_0c071144;
case 0x0c071146u: goto P_0c071146;
case 0x0c071148u: goto P_0c071148;
case 0x0c07114au: goto P_0c07114a;
case 0x0c07114cu: goto P_0c07114c;
case 0x0c07114eu: goto P_0c07114e;
case 0x0c071150u: goto P_0c071150;
case 0x0c071152u: goto P_0c071152;
case 0x0c071154u: goto P_0c071154;
case 0x0c071156u: goto P_0c071156;
case 0x0c071158u: goto P_0c071158;
case 0x0c07115au: goto P_0c07115a;
case 0x0c07115cu: goto P_0c07115c;
case 0x0c07115eu: goto P_0c07115e;
case 0x0c071160u: goto P_0c071160;
case 0x0c071162u: goto P_0c071162;
case 0x0c071164u: goto P_0c071164;
case 0x0c071166u: goto P_0c071166;
case 0x0c071168u: goto P_0c071168;
case 0x0c07116au: goto P_0c07116a;
case 0x0c07116cu: goto P_0c07116c;
case 0x0c07116eu: goto P_0c07116e;
case 0x0c071170u: goto P_0c071170;
case 0x0c071172u: goto P_0c071172;
case 0x0c071174u: goto P_0c071174;
case 0x0c071176u: goto P_0c071176;
case 0x0c071178u: goto P_0c071178;
case 0x0c07117au: goto P_0c07117a;
case 0x0c07117cu: goto P_0c07117c;
case 0x0c07117eu: goto P_0c07117e;
case 0x0c071180u: goto P_0c071180;
case 0x0c071182u: goto P_0c071182;
case 0x0c071184u: goto P_0c071184;
case 0x0c071186u: goto P_0c071186;
case 0x0c071188u: goto P_0c071188;
case 0x0c07118au: goto P_0c07118a;
case 0x0c07118cu: goto P_0c07118c;
case 0x0c07118eu: goto P_0c07118e;
case 0x0c071198u: goto P_0c071198;
case 0x0c07119au: goto P_0c07119a;
case 0x0c07119cu: goto P_0c07119c;
case 0x0c07119eu: goto P_0c07119e;
case 0x0c0711a0u: goto P_0c0711a0;
case 0x0c0711a2u: goto P_0c0711a2;
case 0x0c0711a4u: goto P_0c0711a4;
case 0x0c0711a6u: goto P_0c0711a6;
case 0x0c0711a8u: goto P_0c0711a8;
case 0x0c0711aau: goto P_0c0711aa;
case 0x0c0711acu: goto P_0c0711ac;
case 0x0c0711aeu: goto P_0c0711ae;
case 0x0c0711b0u: goto P_0c0711b0;
case 0x0c0711b2u: goto P_0c0711b2;
case 0x0c0711b4u: goto P_0c0711b4;
case 0x0c0711b6u: goto P_0c0711b6;
case 0x0c0711b8u: goto P_0c0711b8;
case 0x0c0711bau: goto P_0c0711ba;
case 0x0c0711bcu: goto P_0c0711bc;
case 0x0c0711beu: goto P_0c0711be;
case 0x0c0711c0u: goto P_0c0711c0;
case 0x0c0711c2u: goto P_0c0711c2;
case 0x0c0711c4u: goto P_0c0711c4;
case 0x0c0711c6u: goto P_0c0711c6;
case 0x0c0711c8u: goto P_0c0711c8;
case 0x0c0711cau: goto P_0c0711ca;
case 0x0c0711ccu: goto P_0c0711cc;
case 0x0c0711ceu: goto P_0c0711ce;
case 0x0c0711d0u: goto P_0c0711d0;
case 0x0c0711d2u: goto P_0c0711d2;
case 0x0c0711d4u: goto P_0c0711d4;
case 0x0c0711d6u: goto P_0c0711d6;
case 0x0c0711d8u: goto P_0c0711d8;
case 0x0c0711dau: goto P_0c0711da;
case 0x0c0711dcu: goto P_0c0711dc;
case 0x0c0711deu: goto P_0c0711de;
case 0x0c0711e4u: goto P_0c0711e4;
case 0x0c0711e6u: goto P_0c0711e6;
case 0x0c0711e8u: goto P_0c0711e8;
case 0x0c0711eau: goto P_0c0711ea;
case 0x0c0711ecu: goto P_0c0711ec;
case 0x0c0711eeu: goto P_0c0711ee;
case 0x0c0711f0u: goto P_0c0711f0;
case 0x0c0711f2u: goto P_0c0711f2;
case 0x0c0711f4u: goto P_0c0711f4;
case 0x0c0711f6u: goto P_0c0711f6;
case 0x0c0711f8u: goto P_0c0711f8;
case 0x0c0711fau: goto P_0c0711fa;
case 0x0c0711fcu: goto P_0c0711fc;
case 0x0c0711feu: goto P_0c0711fe;
case 0x0c071200u: goto P_0c071200;
case 0x0c071202u: goto P_0c071202;
case 0x0c071204u: goto P_0c071204;
case 0x0c071206u: goto P_0c071206;
case 0x0c071208u: goto P_0c071208;
case 0x0c07120au: goto P_0c07120a;
case 0x0c07120cu: goto P_0c07120c;
case 0x0c07120eu: goto P_0c07120e;
case 0x0c071210u: goto P_0c071210;
case 0x0c071212u: goto P_0c071212;
case 0x0c071214u: goto P_0c071214;
case 0x0c071216u: goto P_0c071216;
case 0x0c071218u: goto P_0c071218;
case 0x0c07121au: goto P_0c07121a;
case 0x0c07121cu: goto P_0c07121c;
case 0x0c07121eu: goto P_0c07121e;
case 0x0c071220u: goto P_0c071220;
case 0x0c071222u: goto P_0c071222;
case 0x0c071224u: goto P_0c071224;
case 0x0c071226u: goto P_0c071226;
case 0x0c071228u: goto P_0c071228;
case 0x0c071230u: goto P_0c071230;
case 0x0c071232u: goto P_0c071232;
case 0x0c071234u: goto P_0c071234;
case 0x0c071236u: goto P_0c071236;
case 0x0c071238u: goto P_0c071238;
case 0x0c07123au: goto P_0c07123a;
case 0x0c07123cu: goto P_0c07123c;
case 0x0c07123eu: goto P_0c07123e;
case 0x0c071240u: goto P_0c071240;
case 0x0c071242u: goto P_0c071242;
case 0x0c071244u: goto P_0c071244;
case 0x0c071246u: goto P_0c071246;
case 0x0c071248u: goto P_0c071248;
case 0x0c07124au: goto P_0c07124a;
case 0x0c07124cu: goto P_0c07124c;
case 0x0c07124eu: goto P_0c07124e;
case 0x0c071250u: goto P_0c071250;
case 0x0c071252u: goto P_0c071252;
case 0x0c071254u: goto P_0c071254;
case 0x0c071256u: goto P_0c071256;
case 0x0c071258u: goto P_0c071258;
case 0x0c07125au: goto P_0c07125a;
case 0x0c07125cu: goto P_0c07125c;
case 0x0c07125eu: goto P_0c07125e;
case 0x0c071260u: goto P_0c071260;
case 0x0c071262u: goto P_0c071262;
case 0x0c071264u: goto P_0c071264;
case 0x0c071266u: goto P_0c071266;
case 0x0c071268u: goto P_0c071268;
case 0x0c071274u: goto P_0c071274;
case 0x0c071276u: goto P_0c071276;
case 0x0c071278u: goto P_0c071278;
case 0x0c07127au: goto P_0c07127a;
case 0x0c07127cu: goto P_0c07127c;
case 0x0c07127eu: goto P_0c07127e;
case 0x0c071280u: goto P_0c071280;
case 0x0c071282u: goto P_0c071282;
case 0x0c071284u: goto P_0c071284;
case 0x0c071286u: goto P_0c071286;
case 0x0c071288u: goto P_0c071288;
case 0x0c07128au: goto P_0c07128a;
case 0x0c07128cu: goto P_0c07128c;
case 0x0c07128eu: goto P_0c07128e;
case 0x0c071290u: goto P_0c071290;
case 0x0c071292u: goto P_0c071292;
case 0x0c071294u: goto P_0c071294;
case 0x0c071296u: goto P_0c071296;
case 0x0c071298u: goto P_0c071298;
case 0x0c07129au: goto P_0c07129a;
case 0x0c07129cu: goto P_0c07129c;
case 0x0c07129eu: goto P_0c07129e;
case 0x0c0712a0u: goto P_0c0712a0;
case 0x0c0712a2u: goto P_0c0712a2;
case 0x0c0712a4u: goto P_0c0712a4;
case 0x0c0712a6u: goto P_0c0712a6;
case 0x0c0712a8u: goto P_0c0712a8;
case 0x0c0712b4u: goto P_0c0712b4;
case 0x0c0712b6u: goto P_0c0712b6;
case 0x0c0712b8u: goto P_0c0712b8;
case 0x0c0712bau: goto P_0c0712ba;
case 0x0c0712bcu: goto P_0c0712bc;
case 0x0c0712beu: goto P_0c0712be;
case 0x0c0712c0u: goto P_0c0712c0;
case 0x0c0712c2u: goto P_0c0712c2;
case 0x0c0712c4u: goto P_0c0712c4;
case 0x0c0712c6u: goto P_0c0712c6;
case 0x0c0712c8u: goto P_0c0712c8;
case 0x0c0712cau: goto P_0c0712ca;
case 0x0c0712ccu: goto P_0c0712cc;
case 0x0c0712ceu: goto P_0c0712ce;
case 0x0c0712d0u: goto P_0c0712d0;
case 0x0c0712d2u: goto P_0c0712d2;
case 0x0c0712d4u: goto P_0c0712d4;
case 0x0c0712d6u: goto P_0c0712d6;
case 0x0c0712d8u: goto P_0c0712d8;
case 0x0c0712dau: goto P_0c0712da;
case 0x0c0712dcu: goto P_0c0712dc;
case 0x0c0712deu: goto P_0c0712de;
case 0x0c0712e0u: goto P_0c0712e0;
case 0x0c0712e2u: goto P_0c0712e2;
case 0x0c0712e4u: goto P_0c0712e4;
case 0x0c0712e6u: goto P_0c0712e6;
case 0x0c0712e8u: goto P_0c0712e8;
case 0x0c0712eau: goto P_0c0712ea;
case 0x0c0712ecu: goto P_0c0712ec;
case 0x0c0712eeu: goto P_0c0712ee;
case 0x0c0712f0u: goto P_0c0712f0;
case 0x0c0712f2u: goto P_0c0712f2;
case 0x0c0712f4u: goto P_0c0712f4;
case 0x0c0712f6u: goto P_0c0712f6;
case 0x0c0712f8u: goto P_0c0712f8;
case 0x0c0712fau: goto P_0c0712fa;
case 0x0c0712fcu: goto P_0c0712fc;
case 0x0c0712feu: goto P_0c0712fe;
case 0x0c071300u: goto P_0c071300;
case 0x0c071302u: goto P_0c071302;
case 0x0c071304u: goto P_0c071304;
case 0x0c071306u: goto P_0c071306;
case 0x0c071308u: goto P_0c071308;
case 0x0c07130au: goto P_0c07130a;
case 0x0c07130cu: goto P_0c07130c;
case 0x0c07130eu: goto P_0c07130e;
case 0x0c071310u: goto P_0c071310;
case 0x0c071312u: goto P_0c071312;
case 0x0c071314u: goto P_0c071314;
case 0x0c071316u: goto P_0c071316;
case 0x0c071318u: goto P_0c071318;
case 0x0c07131au: goto P_0c07131a;
case 0x0c07131cu: goto P_0c07131c;
case 0x0c07131eu: goto P_0c07131e;
case 0x0c071320u: goto P_0c071320;
case 0x0c071322u: goto P_0c071322;
case 0x0c071324u: goto P_0c071324;
case 0x0c071326u: goto P_0c071326;
case 0x0c071328u: goto P_0c071328;
case 0x0c07132au: goto P_0c07132a;
case 0x0c07132cu: goto P_0c07132c;
case 0x0c07132eu: goto P_0c07132e;
case 0x0c071330u: goto P_0c071330;
case 0x0c071332u: goto P_0c071332;
case 0x0c071334u: goto P_0c071334;
case 0x0c071336u: goto P_0c071336;
case 0x0c071338u: goto P_0c071338;
case 0x0c07133au: goto P_0c07133a;
case 0x0c07133cu: goto P_0c07133c;
case 0x0c07133eu: goto P_0c07133e;
case 0x0c071340u: goto P_0c071340;
case 0x0c071342u: goto P_0c071342;
case 0x0c071344u: goto P_0c071344;
case 0x0c071346u: goto P_0c071346;
case 0x0c071348u: goto P_0c071348;
case 0x0c07134au: goto P_0c07134a;
case 0x0c07134cu: goto P_0c07134c;
case 0x0c07134eu: goto P_0c07134e;
case 0x0c071350u: goto P_0c071350;
case 0x0c071352u: goto P_0c071352;
case 0x0c071354u: goto P_0c071354;
case 0x0c071356u: goto P_0c071356;
case 0x0c071358u: goto P_0c071358;
case 0x0c07135au: goto P_0c07135a;
case 0x0c07135cu: goto P_0c07135c;
case 0x0c07135eu: goto P_0c07135e;
case 0x0c071360u: goto P_0c071360;
case 0x0c071362u: goto P_0c071362;
case 0x0c071364u: goto P_0c071364;
case 0x0c071366u: goto P_0c071366;
case 0x0c071368u: goto P_0c071368;
case 0x0c07136au: goto P_0c07136a;
case 0x0c07136cu: goto P_0c07136c;
case 0x0c07136eu: goto P_0c07136e;
case 0x0c071370u: goto P_0c071370;
case 0x0c071372u: goto P_0c071372;
case 0x0c071374u: goto P_0c071374;
case 0x0c071376u: goto P_0c071376;
case 0x0c071378u: goto P_0c071378;
case 0x0c07137au: goto P_0c07137a;
case 0x0c07137cu: goto P_0c07137c;
case 0x0c07137eu: goto P_0c07137e;
case 0x0c071380u: goto P_0c071380;
case 0x0c071382u: goto P_0c071382;
case 0x0c071384u: goto P_0c071384;
case 0x0c071386u: goto P_0c071386;
case 0x0c071388u: goto P_0c071388;
case 0x0c07138au: goto P_0c07138a;
case 0x0c07138cu: goto P_0c07138c;
case 0x0c07138eu: goto P_0c07138e;
case 0x0c071390u: goto P_0c071390;
case 0x0c071392u: goto P_0c071392;
case 0x0c071394u: goto P_0c071394;
case 0x0c071396u: goto P_0c071396;
case 0x0c071398u: goto P_0c071398;
case 0x0c07139au: goto P_0c07139a;
case 0x0c07139cu: goto P_0c07139c;
case 0x0c07139eu: goto P_0c07139e;
case 0x0c0713a0u: goto P_0c0713a0;
case 0x0c0713a2u: goto P_0c0713a2;
case 0x0c0713a4u: goto P_0c0713a4;
case 0x0c0713a6u: goto P_0c0713a6;
case 0x0c0713a8u: goto P_0c0713a8;
case 0x0c0713aau: goto P_0c0713aa;
case 0x0c0713acu: goto P_0c0713ac;
case 0x0c0713b4u: goto P_0c0713b4;
case 0x0c0713b6u: goto P_0c0713b6;
case 0x0c0713b8u: goto P_0c0713b8;
case 0x0c0713bau: goto P_0c0713ba;
case 0x0c0713bcu: goto P_0c0713bc;
case 0x0c0713beu: goto P_0c0713be;
case 0x0c0713c0u: goto P_0c0713c0;
case 0x0c0713c2u: goto P_0c0713c2;
case 0x0c0713c4u: goto P_0c0713c4;
case 0x0c0713c6u: goto P_0c0713c6;
case 0x0c0713c8u: goto P_0c0713c8;
case 0x0c0713cau: goto P_0c0713ca;
case 0x0c0713ccu: goto P_0c0713cc;
case 0x0c0713ceu: goto P_0c0713ce;
case 0x0c0713d0u: goto P_0c0713d0;
case 0x0c0713d2u: goto P_0c0713d2;
case 0x0c0713d4u: goto P_0c0713d4;
case 0x0c0713d6u: goto P_0c0713d6;
case 0x0c0713d8u: goto P_0c0713d8;
case 0x0c0713dau: goto P_0c0713da;
case 0x0c0713dcu: goto P_0c0713dc;
case 0x0c0713deu: goto P_0c0713de;
case 0x0c0713e0u: goto P_0c0713e0;
case 0x0c0713e2u: goto P_0c0713e2;
case 0x0c0713e4u: goto P_0c0713e4;
case 0x0c0713e6u: goto P_0c0713e6;
case 0x0c0713e8u: goto P_0c0713e8;
case 0x0c0713eau: goto P_0c0713ea;
case 0x0c0713ecu: goto P_0c0713ec;
case 0x0c0713eeu: goto P_0c0713ee;
case 0x0c0713f0u: goto P_0c0713f0;
case 0x0c0713f2u: goto P_0c0713f2;
case 0x0c0713f4u: goto P_0c0713f4;
case 0x0c0713f6u: goto P_0c0713f6;
case 0x0c0713f8u: goto P_0c0713f8;
case 0x0c0713fau: goto P_0c0713fa;
case 0x0c0713fcu: goto P_0c0713fc;
case 0x0c0713feu: goto P_0c0713fe;
case 0x0c071400u: goto P_0c071400;
case 0x0c071402u: goto P_0c071402;
case 0x0c071404u: goto P_0c071404;
case 0x0c071406u: goto P_0c071406;
case 0x0c071408u: goto P_0c071408;
case 0x0c07140au: goto P_0c07140a;
case 0x0c071410u: goto P_0c071410;
case 0x0c071412u: goto P_0c071412;
case 0x0c071414u: goto P_0c071414;
case 0x0c071416u: goto P_0c071416;
case 0x0c071418u: goto P_0c071418;
case 0x0c07141au: goto P_0c07141a;
case 0x0c07141cu: goto P_0c07141c;
case 0x0c07141eu: goto P_0c07141e;
case 0x0c071420u: goto P_0c071420;
case 0x0c071422u: goto P_0c071422;
case 0x0c071424u: goto P_0c071424;
case 0x0c071426u: goto P_0c071426;
case 0x0c071428u: goto P_0c071428;
case 0x0c07142au: goto P_0c07142a;
case 0x0c07142cu: goto P_0c07142c;
case 0x0c07142eu: goto P_0c07142e;
case 0x0c071430u: goto P_0c071430;
case 0x0c071432u: goto P_0c071432;
case 0x0c071434u: goto P_0c071434;
case 0x0c071436u: goto P_0c071436;
case 0x0c071438u: goto P_0c071438;
case 0x0c07143au: goto P_0c07143a;
case 0x0c07143cu: goto P_0c07143c;
case 0x0c07143eu: goto P_0c07143e;
case 0x0c071440u: goto P_0c071440;
case 0x0c071442u: goto P_0c071442;
case 0x0c071444u: goto P_0c071444;
case 0x0c071446u: goto P_0c071446;
case 0x0c071448u: goto P_0c071448;
case 0x0c07144au: goto P_0c07144a;
case 0x0c07144cu: goto P_0c07144c;
case 0x0c07144eu: goto P_0c07144e;
case 0x0c071450u: goto P_0c071450;
case 0x0c071452u: goto P_0c071452;
case 0x0c071454u: goto P_0c071454;
case 0x0c071456u: goto P_0c071456;
case 0x0c07145cu: goto P_0c07145c;
case 0x0c07145eu: goto P_0c07145e;
case 0x0c071460u: goto P_0c071460;
case 0x0c071462u: goto P_0c071462;
case 0x0c071464u: goto P_0c071464;
case 0x0c071466u: goto P_0c071466;
case 0x0c071468u: goto P_0c071468;
case 0x0c07146au: goto P_0c07146a;
case 0x0c07146cu: goto P_0c07146c;
case 0x0c07146eu: goto P_0c07146e;
case 0x0c071470u: goto P_0c071470;
case 0x0c071472u: goto P_0c071472;
case 0x0c071474u: goto P_0c071474;
case 0x0c071476u: goto P_0c071476;
case 0x0c071478u: goto P_0c071478;
case 0x0c07147au: goto P_0c07147a;
case 0x0c07147cu: goto P_0c07147c;
case 0x0c07147eu: goto P_0c07147e;
case 0x0c071480u: goto P_0c071480;
case 0x0c071482u: goto P_0c071482;
case 0x0c071484u: goto P_0c071484;
case 0x0c071486u: goto P_0c071486;
case 0x0c071488u: goto P_0c071488;
case 0x0c07148au: goto P_0c07148a;
case 0x0c07148cu: goto P_0c07148c;
case 0x0c07148eu: goto P_0c07148e;
case 0x0c071490u: goto P_0c071490;
case 0x0c071492u: goto P_0c071492;
case 0x0c071494u: goto P_0c071494;
case 0x0c071496u: goto P_0c071496;
case 0x0c071498u: goto P_0c071498;
case 0x0c07149au: goto P_0c07149a;
case 0x0c07149cu: goto P_0c07149c;
case 0x0c07149eu: goto P_0c07149e;
case 0x0c0714a0u: goto P_0c0714a0;
case 0x0c0714a8u: goto P_0c0714a8;
case 0x0c0714aau: goto P_0c0714aa;
case 0x0c0714acu: goto P_0c0714ac;
case 0x0c0714aeu: goto P_0c0714ae;
case 0x0c0714b0u: goto P_0c0714b0;
case 0x0c0714b2u: goto P_0c0714b2;
case 0x0c0714b4u: goto P_0c0714b4;
case 0x0c0714b6u: goto P_0c0714b6;
case 0x0c0714b8u: goto P_0c0714b8;
case 0x0c0714bau: goto P_0c0714ba;
case 0x0c0714bcu: goto P_0c0714bc;
case 0x0c0714beu: goto P_0c0714be;
case 0x0c0714c0u: goto P_0c0714c0;
case 0x0c0714c2u: goto P_0c0714c2;
case 0x0c0714c4u: goto P_0c0714c4;
case 0x0c0714c6u: goto P_0c0714c6;
case 0x0c0714c8u: goto P_0c0714c8;
case 0x0c0714cau: goto P_0c0714ca;
case 0x0c0714ccu: goto P_0c0714cc;
case 0x0c0714ceu: goto P_0c0714ce;
case 0x0c0714d0u: goto P_0c0714d0;
case 0x0c0714d2u: goto P_0c0714d2;
case 0x0c0714d4u: goto P_0c0714d4;
case 0x0c0714d6u: goto P_0c0714d6;
case 0x0c0714d8u: goto P_0c0714d8;
case 0x0c0714dau: goto P_0c0714da;
case 0x0c0714dcu: goto P_0c0714dc;
case 0x0c0714deu: goto P_0c0714de;
case 0x0c0714e0u: goto P_0c0714e0;
case 0x0c0714ecu: goto P_0c0714ec;
case 0x0c0714eeu: goto P_0c0714ee;
case 0x0c0714f0u: goto P_0c0714f0;
case 0x0c0714f2u: goto P_0c0714f2;
case 0x0c0714f4u: goto P_0c0714f4;
case 0x0c0714f6u: goto P_0c0714f6;
case 0x0c0714f8u: goto P_0c0714f8;
case 0x0c0714fau: goto P_0c0714fa;
case 0x0c0714fcu: goto P_0c0714fc;
case 0x0c0714feu: goto P_0c0714fe;
case 0x0c071500u: goto P_0c071500;
case 0x0c071502u: goto P_0c071502;
case 0x0c071504u: goto P_0c071504;
case 0x0c071506u: goto P_0c071506;
case 0x0c071508u: goto P_0c071508;
case 0x0c07150au: goto P_0c07150a;
case 0x0c07150cu: goto P_0c07150c;
case 0x0c07150eu: goto P_0c07150e;
case 0x0c071510u: goto P_0c071510;
case 0x0c071512u: goto P_0c071512;
case 0x0c071514u: goto P_0c071514;
case 0x0c071516u: goto P_0c071516;
case 0x0c071518u: goto P_0c071518;
case 0x0c07151au: goto P_0c07151a;
case 0x0c07151cu: goto P_0c07151c;
case 0x0c07151eu: goto P_0c07151e;
case 0x0c071520u: goto P_0c071520;
case 0x0c07152cu: goto P_0c07152c;
case 0x0c07152eu: goto P_0c07152e;
case 0x0c071530u: goto P_0c071530;
case 0x0c071532u: goto P_0c071532;
case 0x0c071534u: goto P_0c071534;
case 0x0c071536u: goto P_0c071536;
case 0x0c071538u: goto P_0c071538;
case 0x0c07153au: goto P_0c07153a;
case 0x0c07153cu: goto P_0c07153c;
case 0x0c07153eu: goto P_0c07153e;
case 0x0c071540u: goto P_0c071540;
case 0x0c071542u: goto P_0c071542;
case 0x0c071544u: goto P_0c071544;
case 0x0c071546u: goto P_0c071546;
case 0x0c071548u: goto P_0c071548;
case 0x0c07154au: goto P_0c07154a;
case 0x0c07154cu: goto P_0c07154c;
case 0x0c07154eu: goto P_0c07154e;
case 0x0c071550u: goto P_0c071550;
case 0x0c071552u: goto P_0c071552;
case 0x0c071554u: goto P_0c071554;
case 0x0c071556u: goto P_0c071556;
case 0x0c071558u: goto P_0c071558;
case 0x0c07155au: goto P_0c07155a;
case 0x0c07155cu: goto P_0c07155c;
case 0x0c07155eu: goto P_0c07155e;
case 0x0c071560u: goto P_0c071560;
case 0x0c071562u: goto P_0c071562;
case 0x0c071564u: goto P_0c071564;
case 0x0c071566u: goto P_0c071566;
case 0x0c071568u: goto P_0c071568;
case 0x0c07156au: goto P_0c07156a;
case 0x0c07156cu: goto P_0c07156c;
case 0x0c07156eu: goto P_0c07156e;
case 0x0c071570u: goto P_0c071570;
case 0x0c071572u: goto P_0c071572;
case 0x0c071574u: goto P_0c071574;
case 0x0c071576u: goto P_0c071576;
case 0x0c071578u: goto P_0c071578;
case 0x0c07157au: goto P_0c07157a;
case 0x0c07157cu: goto P_0c07157c;
case 0x0c07157eu: goto P_0c07157e;
case 0x0c071580u: goto P_0c071580;
case 0x0c071582u: goto P_0c071582;
case 0x0c071584u: goto P_0c071584;
case 0x0c071586u: goto P_0c071586;
case 0x0c071588u: goto P_0c071588;
case 0x0c07158au: goto P_0c07158a;
case 0x0c07158cu: goto P_0c07158c;
case 0x0c07158eu: goto P_0c07158e;
case 0x0c071590u: goto P_0c071590;
case 0x0c071592u: goto P_0c071592;
case 0x0c071594u: goto P_0c071594;
case 0x0c071596u: goto P_0c071596;
case 0x0c071598u: goto P_0c071598;
case 0x0c07159au: goto P_0c07159a;
case 0x0c07159cu: goto P_0c07159c;
case 0x0c07159eu: goto P_0c07159e;
case 0x0c0715a0u: goto P_0c0715a0;
case 0x0c0715a2u: goto P_0c0715a2;
case 0x0c0715a4u: goto P_0c0715a4;
case 0x0c0715a6u: goto P_0c0715a6;
case 0x0c0715a8u: goto P_0c0715a8;
case 0x0c0715aau: goto P_0c0715aa;
case 0x0c0715acu: goto P_0c0715ac;
case 0x0c0715aeu: goto P_0c0715ae;
case 0x0c0715b0u: goto P_0c0715b0;
case 0x0c0715b2u: goto P_0c0715b2;
case 0x0c0715b4u: goto P_0c0715b4;
case 0x0c0715b6u: goto P_0c0715b6;
case 0x0c0715b8u: goto P_0c0715b8;
case 0x0c0715bau: goto P_0c0715ba;
case 0x0c0715bcu: goto P_0c0715bc;
case 0x0c0715beu: goto P_0c0715be;
case 0x0c0715c0u: goto P_0c0715c0;
case 0x0c0715c2u: goto P_0c0715c2;
case 0x0c0715c4u: goto P_0c0715c4;
case 0x0c0715c6u: goto P_0c0715c6;
case 0x0c0715c8u: goto P_0c0715c8;
case 0x0c0715cau: goto P_0c0715ca;
case 0x0c0715ccu: goto P_0c0715cc;
case 0x0c0715ceu: goto P_0c0715ce;
case 0x0c0715d0u: goto P_0c0715d0;
case 0x0c0715d2u: goto P_0c0715d2;
case 0x0c0715d4u: goto P_0c0715d4;
case 0x0c0715d6u: goto P_0c0715d6;
case 0x0c0715d8u: goto P_0c0715d8;
case 0x0c0715dau: goto P_0c0715da;
case 0x0c0715dcu: goto P_0c0715dc;
case 0x0c0715deu: goto P_0c0715de;
case 0x0c0715e0u: goto P_0c0715e0;
case 0x0c0715e2u: goto P_0c0715e2;
case 0x0c0715e4u: goto P_0c0715e4;
case 0x0c0715e6u: goto P_0c0715e6;
case 0x0c0715e8u: goto P_0c0715e8;
case 0x0c0715eau: goto P_0c0715ea;
case 0x0c0715ecu: goto P_0c0715ec;
case 0x0c0715eeu: goto P_0c0715ee;
case 0x0c0715f0u: goto P_0c0715f0;
case 0x0c0715f2u: goto P_0c0715f2;
case 0x0c0715f4u: goto P_0c0715f4;
case 0x0c0715f6u: goto P_0c0715f6;
case 0x0c0715f8u: goto P_0c0715f8;
case 0x0c0715fau: goto P_0c0715fa;
case 0x0c0715fcu: goto P_0c0715fc;
case 0x0c0715feu: goto P_0c0715fe;
case 0x0c071600u: goto P_0c071600;
case 0x0c071602u: goto P_0c071602;
case 0x0c071604u: goto P_0c071604;
case 0x0c071606u: goto P_0c071606;
case 0x0c071608u: goto P_0c071608;
case 0x0c07160au: goto P_0c07160a;
case 0x0c07160cu: goto P_0c07160c;
case 0x0c07160eu: goto P_0c07160e;
case 0x0c071610u: goto P_0c071610;
case 0x0c071612u: goto P_0c071612;
case 0x0c071614u: goto P_0c071614;
case 0x0c071616u: goto P_0c071616;
case 0x0c071618u: goto P_0c071618;
case 0x0c07161au: goto P_0c07161a;
case 0x0c07161cu: goto P_0c07161c;
case 0x0c07161eu: goto P_0c07161e;
case 0x0c071620u: goto P_0c071620;
case 0x0c071622u: goto P_0c071622;
case 0x0c071624u: goto P_0c071624;
case 0x0c07162cu: goto P_0c07162c;
case 0x0c07162eu: goto P_0c07162e;
case 0x0c071630u: goto P_0c071630;
case 0x0c071632u: goto P_0c071632;
case 0x0c071634u: goto P_0c071634;
case 0x0c071636u: goto P_0c071636;
case 0x0c071638u: goto P_0c071638;
case 0x0c07163au: goto P_0c07163a;
case 0x0c07163cu: goto P_0c07163c;
case 0x0c07163eu: goto P_0c07163e;
case 0x0c071640u: goto P_0c071640;
case 0x0c071642u: goto P_0c071642;
case 0x0c071644u: goto P_0c071644;
case 0x0c071646u: goto P_0c071646;
case 0x0c071648u: goto P_0c071648;
case 0x0c07164au: goto P_0c07164a;
case 0x0c07164cu: goto P_0c07164c;
case 0x0c07164eu: goto P_0c07164e;
case 0x0c071650u: goto P_0c071650;
case 0x0c071652u: goto P_0c071652;
case 0x0c071654u: goto P_0c071654;
case 0x0c071656u: goto P_0c071656;
case 0x0c071658u: goto P_0c071658;
case 0x0c07165au: goto P_0c07165a;
case 0x0c07165cu: goto P_0c07165c;
case 0x0c07165eu: goto P_0c07165e;
case 0x0c071660u: goto P_0c071660;
case 0x0c071662u: goto P_0c071662;
case 0x0c071664u: goto P_0c071664;
case 0x0c071666u: goto P_0c071666;
case 0x0c071668u: goto P_0c071668;
case 0x0c07166au: goto P_0c07166a;
case 0x0c07166cu: goto P_0c07166c;
case 0x0c07166eu: goto P_0c07166e;
case 0x0c071670u: goto P_0c071670;
case 0x0c071672u: goto P_0c071672;
case 0x0c071674u: goto P_0c071674;
case 0x0c071676u: goto P_0c071676;
case 0x0c071678u: goto P_0c071678;
case 0x0c07167au: goto P_0c07167a;
case 0x0c07167cu: goto P_0c07167c;
case 0x0c07167eu: goto P_0c07167e;
case 0x0c071680u: goto P_0c071680;
case 0x0c071682u: goto P_0c071682;
case 0x0c071684u: goto P_0c071684;
case 0x0c071686u: goto P_0c071686;
case 0x0c071688u: goto P_0c071688;
case 0x0c07168au: goto P_0c07168a;
case 0x0c07168cu: goto P_0c07168c;
case 0x0c07168eu: goto P_0c07168e;
case 0x0c071690u: goto P_0c071690;
case 0x0c071692u: goto P_0c071692;
default: return vf3_matrix_family(target,s,ram);
}
P_0c071140: /* original 2fe6, guest PC 0x0c071140 */
if(!s->budget--) { s->failed_pc=0x0c071140u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c071142;
P_0c071142: /* original e058, guest PC 0x0c071142 */
if(!s->budget--) { s->failed_pc=0x0c071142u; return 0; }
r[0]=0x00000058u;
goto P_0c071144;
P_0c071144: /* original 2fd6, guest PC 0x0c071144 */
if(!s->budget--) { s->failed_pc=0x0c071144u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c071146;
P_0c071146: /* original 2fc6, guest PC 0x0c071146 */
if(!s->budget--) { s->failed_pc=0x0c071146u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c071148;
P_0c071148: /* original 6c63, guest PC 0x0c071148 */
if(!s->budget--) { s->failed_pc=0x0c071148u; return 0; }
r[12]=r[6];
goto P_0c07114a;
P_0c07114a: /* original 2fb6, guest PC 0x0c07114a */
if(!s->budget--) { s->failed_pc=0x0c07114au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07114c;
P_0c07114c: /* original 2fa6, guest PC 0x0c07114c */
if(!s->budget--) { s->failed_pc=0x0c07114cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07114e;
P_0c07114e: /* original ea01, guest PC 0x0c07114e */
if(!s->budget--) { s->failed_pc=0x0c07114eu; return 0; }
r[10]=0x00000001u;
goto P_0c071150;
P_0c071150: /* original 2f96, guest PC 0x0c071150 */
if(!s->budget--) { s->failed_pc=0x0c071150u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c071152;
P_0c071152: /* original fffb, guest PC 0x0c071152 */
if(!s->budget--) { s->failed_pc=0x0c071152u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c071154;
P_0c071154: /* original ffeb, guest PC 0x0c071154 */
if(!s->budget--) { s->failed_pc=0x0c071154u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c071156;
P_0c071156: /* original ffdb, guest PC 0x0c071156 */
if(!s->budget--) { s->failed_pc=0x0c071156u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c071158;
P_0c071158: /* original ffcb, guest PC 0x0c071158 */
if(!s->budget--) { s->failed_pc=0x0c071158u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c07115a;
P_0c07115a: /* original 095e, guest PC 0x0c07115a */
if(!s->budget--) { s->failed_pc=0x0c07115au; return 0; }
r[9]=read(ram,r[5]+r[0],4);
goto P_0c07115c;
P_0c07115c: /* original e060, guest PC 0x0c07115c */
if(!s->budget--) { s->failed_pc=0x0c07115cu; return 0; }
r[0]=0x00000060u;
goto P_0c07115e;
P_0c07115e: /* original f356, guest PC 0x0c07115e */
if(!s->budget--) { s->failed_pc=0x0c07115eu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c071160;
P_0c071160: /* original 7fcc, guest PC 0x0c071160 */
if(!s->budget--) { s->failed_pc=0x0c071160u; return 0; }
r[15]+=0xffffffccu;
goto P_0c071162;
P_0c071162: /* original 6393, guest PC 0x0c071162 */
if(!s->budget--) { s->failed_pc=0x0c071162u; return 0; }
r[3]=r[9];
goto P_0c071164;
P_0c071164: /* original 6293, guest PC 0x0c071164 */
if(!s->budget--) { s->failed_pc=0x0c071164u; return 0; }
r[2]=r[9];
goto P_0c071166;
P_0c071166: /* original 4300, guest PC 0x0c071166 */
if(!s->budget--) { s->failed_pc=0x0c071166u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c071168;
P_0c071168: /* original ff3a, guest PC 0x0c071168 */
if(!s->budget--) { s->failed_pc=0x0c071168u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c07116a;
P_0c07116a: /* original 9011, guest PC 0x0c07116a */
if(!s->budget--) { s->failed_pc=0x0c07116au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c071190u,2);
goto P_0c07116c;
P_0c07116c: /* original 332c, guest PC 0x0c07116c */
if(!s->budget--) { s->failed_pc=0x0c07116cu; return 0; }
r[3]+=r[2];
goto P_0c07116e;
P_0c07116e: /* original 4308, guest PC 0x0c07116e */
if(!s->budget--) { s->failed_pc=0x0c07116eu; return 0; }
r[3]<<=2;
goto P_0c071170;
P_0c071170: /* original 9b0f, guest PC 0x0c071170 */
if(!s->budget--) { s->failed_pc=0x0c071170u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c071192u,2);
goto P_0c071172;
P_0c071172: /* original fc56, guest PC 0x0c071172 */
if(!s->budget--) { s->failed_pc=0x0c071172u; return 0; }
vf3_matrix_load(s,ram,12,r[5]+r[0]);
goto P_0c071174;
P_0c071174: /* original 4300, guest PC 0x0c071174 */
if(!s->budget--) { s->failed_pc=0x0c071174u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c071176;
P_0c071176: /* original 7004, guest PC 0x0c071176 */
if(!s->budget--) { s->failed_pc=0x0c071176u; return 0; }
r[0]+=0x00000004u;
goto P_0c071178;
P_0c071178: /* original 3c38, guest PC 0x0c071178 */
if(!s->budget--) { s->failed_pc=0x0c071178u; return 0; }
r[12]-=r[3];
goto P_0c07117a;
P_0c07117a: /* original ff56, guest PC 0x0c07117a */
if(!s->budget--) { s->failed_pc=0x0c07117au; return 0; }
vf3_matrix_load(s,ram,15,r[5]+r[0]);
goto P_0c07117c;
P_0c07117c: /* original 3b5c, guest PC 0x0c07117c */
if(!s->budget--) { s->failed_pc=0x0c07117cu; return 0; }
r[11]+=r[5];
goto P_0c07117e;
P_0c07117e: /* original 6ec3, guest PC 0x0c07117e */
if(!s->budget--) { s->failed_pc=0x0c07117eu; return 0; }
r[14]=r[12];
goto P_0c071180;
P_0c071180: /* original 64f3, guest PC 0x0c071180 */
if(!s->budget--) { s->failed_pc=0x0c071180u; return 0; }
r[4]=r[15];
goto P_0c071182;
P_0c071182: /* original 6d53, guest PC 0x0c071182 */
if(!s->budget--) { s->failed_pc=0x0c071182u; return 0; }
r[13]=r[5];
goto P_0c071184;
P_0c071184: /* original 741c, guest PC 0x0c071184 */
if(!s->budget--) { s->failed_pc=0x0c071184u; return 0; }
r[4]+=0x0000001cu;
goto P_0c071186;
P_0c071186: /* original 65c3, guest PC 0x0c071186 */
if(!s->budget--) { s->failed_pc=0x0c071186u; return 0; }
r[5]=r[12];
goto P_0c071188;
P_0c071188: /* original 7d74, guest PC 0x0c071188 */
if(!s->budget--) { s->failed_pc=0x0c071188u; return 0; }
r[13]+=0x00000074u;
goto P_0c07118a;
P_0c07118a: /* original 66b3, guest PC 0x0c07118a */
if(!s->budget--) { s->failed_pc=0x0c07118au; return 0; }
r[6]=r[11];
goto P_0c07118c;
P_0c07118c: /* original a004, guest PC 0x0c07118c */
if(!s->budget--) { s->failed_pc=0x0c07118cu; return 0; }
goto P_0c071198;
P_0c07118e: /* original 0009, guest PC 0x0c07118e */
if(!s->budget--) { s->failed_pc=0x0c07118eu; return 0; }
if(!vf3_matrix_family(0x0c071190u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c071190u; return 0; } return 1;
P_0c071198: /* original f059, guest PC 0x0c071198 */
if(!s->budget--) { s->failed_pc=0x0c071198u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07119a;
P_0c07119a: /* original f369, guest PC 0x0c07119a */
if(!s->budget--) { s->failed_pc=0x0c07119au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07119c;
P_0c07119c: /* original f159, guest PC 0x0c07119c */
if(!s->budget--) { s->failed_pc=0x0c07119cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07119e;
P_0c07119e: /* original f469, guest PC 0x0c07119e */
if(!s->budget--) { s->failed_pc=0x0c07119eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0711a0;
P_0c0711a0: /* original f031, guest PC 0x0c0711a0 */
if(!s->budget--) { s->failed_pc=0x0c0711a0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0711a2;
P_0c0711a2: /* original f258, guest PC 0x0c0711a2 */
if(!s->budget--) { s->failed_pc=0x0c0711a2u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0711a4;
P_0c0711a4: /* original f568, guest PC 0x0c0711a4 */
if(!s->budget--) { s->failed_pc=0x0c0711a4u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0711a6;
P_0c0711a6: /* original f141, guest PC 0x0c0711a6 */
if(!s->budget--) { s->failed_pc=0x0c0711a6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0711a8;
P_0c0711a8: /* original f251, guest PC 0x0c0711a8 */
if(!s->budget--) { s->failed_pc=0x0c0711a8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0711aa;
P_0c0711aa: /* original 7408, guest PC 0x0c0711aa */
if(!s->budget--) { s->failed_pc=0x0c0711aau; return 0; }
r[4]+=0x00000008u;
goto P_0c0711ac;
P_0c0711ac: /* original f42a, guest PC 0x0c0711ac */
if(!s->budget--) { s->failed_pc=0x0c0711acu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0711ae;
P_0c0711ae: /* original f41b, guest PC 0x0c0711ae */
if(!s->budget--) { s->failed_pc=0x0c0711aeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0711b0;
P_0c0711b0: /* original f40b, guest PC 0x0c0711b0 */
if(!s->budget--) { s->failed_pc=0x0c0711b0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0711b2;
P_0c0711b2: /* original 0009, guest PC 0x0c0711b2 */
if(!s->budget--) { s->failed_pc=0x0c0711b2u; return 0; }
goto P_0c0711b4;
P_0c0711b4: /* original 64f3, guest PC 0x0c0711b4 */
if(!s->budget--) { s->failed_pc=0x0c0711b4u; return 0; }
r[4]=r[15];
goto P_0c0711b6;
P_0c0711b6: /* original 741c, guest PC 0x0c0711b6 */
if(!s->budget--) { s->failed_pc=0x0c0711b6u; return 0; }
r[4]+=0x0000001cu;
goto P_0c0711b8;
P_0c0711b8: /* original f049, guest PC 0x0c0711b8 */
if(!s->budget--) { s->failed_pc=0x0c0711b8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0711ba;
P_0c0711ba: /* original f149, guest PC 0x0c0711ba */
if(!s->budget--) { s->failed_pc=0x0c0711bau; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0711bc;
P_0c0711bc: /* original f249, guest PC 0x0c0711bc */
if(!s->budget--) { s->failed_pc=0x0c0711bcu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0711be;
P_0c0711be: /* original f38d, guest PC 0x0c0711be */
if(!s->budget--) { s->failed_pc=0x0c0711beu; return 0; }
fr[3]=0;
goto P_0c0711c0;
P_0c0711c0: /* original f0ed, guest PC 0x0c0711c0 */
if(!s->budget--) { s->failed_pc=0x0c0711c0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0711c2;
P_0c0711c2: /* original f03c, guest PC 0x0c0711c2 */
if(!s->budget--) { s->failed_pc=0x0c0711c2u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c0711c4;
P_0c0711c4: /* original f06d, guest PC 0x0c0711c4 */
if(!s->budget--) { s->failed_pc=0x0c0711c4u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c0711c6;
P_0c0711c6: /* original 0009, guest PC 0x0c0711c6 */
if(!s->budget--) { s->failed_pc=0x0c0711c6u; return 0; }
goto P_0c0711c8;
P_0c0711c8: /* original f38d, guest PC 0x0c0711c8 */
if(!s->budget--) { s->failed_pc=0x0c0711c8u; return 0; }
fr[3]=0;
goto P_0c0711ca;
P_0c0711ca: /* original fe0c, guest PC 0x0c0711ca */
if(!s->budget--) { s->failed_pc=0x0c0711cau; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c0711cc;
P_0c0711cc: /* original fe35, guest PC 0x0c0711cc */
if(!s->budget--) { s->failed_pc=0x0c0711ccu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[3]))!=0);
goto P_0c0711ce;
P_0c0711ce: /* original 8902, guest PC 0x0c0711ce */
if(!s->budget--) { s->failed_pc=0x0c0711ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0711d6; }
goto P_0c0711d0;
P_0c0711d0: /* original d303, guest PC 0x0c0711d0 */
if(!s->budget--) { s->failed_pc=0x0c0711d0u; return 0; }
r[3]=read(ram,0x0c0711e0u,4);
goto P_0c0711d2;
P_0c0711d2: /* original 432b, guest PC 0x0c0711d2 */
if(!s->budget--) { s->failed_pc=0x0c0711d2u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c07135cu: goto P_0c07135c;
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
P_0c0711d4: /* original 0009, guest PC 0x0c0711d4 */
if(!s->budget--) { s->failed_pc=0x0c0711d4u; return 0; }
goto P_0c0711d6;
P_0c0711d6: /* original 64f3, guest PC 0x0c0711d6 */
if(!s->budget--) { s->failed_pc=0x0c0711d6u; return 0; }
r[4]=r[15];
goto P_0c0711d8;
P_0c0711d8: /* original 741c, guest PC 0x0c0711d8 */
if(!s->budget--) { s->failed_pc=0x0c0711d8u; return 0; }
r[4]+=0x0000001cu;
goto P_0c0711da;
P_0c0711da: /* original 65d3, guest PC 0x0c0711da */
if(!s->budget--) { s->failed_pc=0x0c0711dau; return 0; }
r[5]=r[13];
goto P_0c0711dc;
P_0c0711dc: /* original a002, guest PC 0x0c0711dc */
if(!s->budget--) { s->failed_pc=0x0c0711dcu; return 0; }
goto P_0c0711e4;
P_0c0711de: /* original 0009, guest PC 0x0c0711de */
if(!s->budget--) { s->failed_pc=0x0c0711deu; return 0; }
if(!vf3_matrix_family(0x0c0711e0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0711e0u; return 0; } return 1;
P_0c0711e4: /* original f049, guest PC 0x0c0711e4 */
if(!s->budget--) { s->failed_pc=0x0c0711e4u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0711e6;
P_0c0711e6: /* original f549, guest PC 0x0c0711e6 */
if(!s->budget--) { s->failed_pc=0x0c0711e6u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0711e8;
P_0c0711e8: /* original f648, guest PC 0x0c0711e8 */
if(!s->budget--) { s->failed_pc=0x0c0711e8u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0711ea;
P_0c0711ea: /* original f859, guest PC 0x0c0711ea */
if(!s->budget--) { s->failed_pc=0x0c0711eau; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0711ec;
P_0c0711ec: /* original f959, guest PC 0x0c0711ec */
if(!s->budget--) { s->failed_pc=0x0c0711ecu; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0711ee;
P_0c0711ee: /* original fa58, guest PC 0x0c0711ee */
if(!s->budget--) { s->failed_pc=0x0c0711eeu; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c0711f0;
P_0c0711f0: /* original f35c, guest PC 0x0c0711f0 */
if(!s->budget--) { s->failed_pc=0x0c0711f0u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0711f2;
P_0c0711f2: /* original f382, guest PC 0x0c0711f2 */
if(!s->budget--) { s->failed_pc=0x0c0711f2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c0711f4;
P_0c0711f4: /* original f20c, guest PC 0x0c0711f4 */
if(!s->budget--) { s->failed_pc=0x0c0711f4u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c0711f6;
P_0c0711f6: /* original f2a2, guest PC 0x0c0711f6 */
if(!s->budget--) { s->failed_pc=0x0c0711f6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c0711f8;
P_0c0711f8: /* original f16c, guest PC 0x0c0711f8 */
if(!s->budget--) { s->failed_pc=0x0c0711f8u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c0711fa;
P_0c0711fa: /* original f192, guest PC 0x0c0711fa */
if(!s->budget--) { s->failed_pc=0x0c0711fau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c0711fc;
P_0c0711fc: /* original f34d, guest PC 0x0c0711fc */
if(!s->budget--) { s->failed_pc=0x0c0711fcu; return 0; }
fr[3]^=0x80000000u;
goto P_0c0711fe;
P_0c0711fe: /* original f39e, guest PC 0x0c0711fe */
if(!s->budget--) { s->failed_pc=0x0c0711feu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071200;
P_0c071200: /* original f24d, guest PC 0x0c071200 */
if(!s->budget--) { s->failed_pc=0x0c071200u; return 0; }
fr[2]^=0x80000000u;
goto P_0c071202;
P_0c071202: /* original f06c, guest PC 0x0c071202 */
if(!s->budget--) { s->failed_pc=0x0c071202u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c071204;
P_0c071204: /* original f28e, guest PC 0x0c071204 */
if(!s->budget--) { s->failed_pc=0x0c071204u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c071206;
P_0c071206: /* original f14d, guest PC 0x0c071206 */
if(!s->budget--) { s->failed_pc=0x0c071206u; return 0; }
fr[1]^=0x80000000u;
goto P_0c071208;
P_0c071208: /* original f05c, guest PC 0x0c071208 */
if(!s->budget--) { s->failed_pc=0x0c071208u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c07120a;
P_0c07120a: /* original f1ae, guest PC 0x0c07120a */
if(!s->budget--) { s->failed_pc=0x0c07120au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c07120c;
P_0c07120c: /* original f08d, guest PC 0x0c07120c */
if(!s->budget--) { s->failed_pc=0x0c07120cu; return 0; }
fr[0]=0;
goto P_0c07120e;
P_0c07120e: /* original f0ed, guest PC 0x0c07120e */
if(!s->budget--) { s->failed_pc=0x0c07120eu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071210;
P_0c071210: /* original f03c, guest PC 0x0c071210 */
if(!s->budget--) { s->failed_pc=0x0c071210u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c071212;
P_0c071212: /* original f06d, guest PC 0x0c071212 */
if(!s->budget--) { s->failed_pc=0x0c071212u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c071214;
P_0c071214: /* original fd0c, guest PC 0x0c071214 */
if(!s->budget--) { s->failed_pc=0x0c071214u; return 0; }
vf3_matrix_move(s,13,0);
goto P_0c071216;
P_0c071216: /* original ffd5, guest PC 0x0c071216 */
if(!s->budget--) { s->failed_pc=0x0c071216u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[13]))!=0);
goto P_0c071218;
P_0c071218: /* original 8902, guest PC 0x0c071218 */
if(!s->budget--) { s->failed_pc=0x0c071218u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c071220; }
goto P_0c07121a;
P_0c07121a: /* original d304, guest PC 0x0c07121a */
if(!s->budget--) { s->failed_pc=0x0c07121au; return 0; }
r[3]=read(ram,0x0c07122cu,4);
goto P_0c07121c;
P_0c07121c: /* original 432b, guest PC 0x0c07121c */
if(!s->budget--) { s->failed_pc=0x0c07121cu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c07135cu: goto P_0c07135c;
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
P_0c07121e: /* original 0009, guest PC 0x0c07121e */
if(!s->budget--) { s->failed_pc=0x0c07121eu; return 0; }
goto P_0c071220;
P_0c071220: /* original 64f3, guest PC 0x0c071220 */
if(!s->budget--) { s->failed_pc=0x0c071220u; return 0; }
r[4]=r[15];
goto P_0c071222;
P_0c071222: /* original 741c, guest PC 0x0c071222 */
if(!s->budget--) { s->failed_pc=0x0c071222u; return 0; }
r[4]+=0x0000001cu;
goto P_0c071224;
P_0c071224: /* original 65d3, guest PC 0x0c071224 */
if(!s->budget--) { s->failed_pc=0x0c071224u; return 0; }
r[5]=r[13];
goto P_0c071226;
P_0c071226: /* original a003, guest PC 0x0c071226 */
if(!s->budget--) { s->failed_pc=0x0c071226u; return 0; }
goto P_0c071230;
P_0c071228: /* original 0009, guest PC 0x0c071228 */
if(!s->budget--) { s->failed_pc=0x0c071228u; return 0; }
if(!vf3_matrix_family(0x0c07122au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07122au; return 0; } return 1;
P_0c071230: /* original f049, guest PC 0x0c071230 */
if(!s->budget--) { s->failed_pc=0x0c071230u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071232;
P_0c071232: /* original f149, guest PC 0x0c071232 */
if(!s->budget--) { s->failed_pc=0x0c071232u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071234;
P_0c071234: /* original f249, guest PC 0x0c071234 */
if(!s->budget--) { s->failed_pc=0x0c071234u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071236;
P_0c071236: /* original f38d, guest PC 0x0c071236 */
if(!s->budget--) { s->failed_pc=0x0c071236u; return 0; }
fr[3]=0;
goto P_0c071238;
P_0c071238: /* original f459, guest PC 0x0c071238 */
if(!s->budget--) { s->failed_pc=0x0c071238u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07123a;
P_0c07123a: /* original f559, guest PC 0x0c07123a */
if(!s->budget--) { s->failed_pc=0x0c07123au; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07123c;
P_0c07123c: /* original f659, guest PC 0x0c07123c */
if(!s->budget--) { s->failed_pc=0x0c07123cu; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07123e;
P_0c07123e: /* original f78d, guest PC 0x0c07123e */
if(!s->budget--) { s->failed_pc=0x0c07123eu; return 0; }
fr[7]=0;
goto P_0c071240;
P_0c071240: /* original f4ed, guest PC 0x0c071240 */
if(!s->budget--) { s->failed_pc=0x0c071240u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c071242;
P_0c071242: /* original f07c, guest PC 0x0c071242 */
if(!s->budget--) { s->failed_pc=0x0c071242u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c071244;
P_0c071244: /* original f38d, guest PC 0x0c071244 */
if(!s->budget--) { s->failed_pc=0x0c071244u; return 0; }
fr[3]=0;
goto P_0c071246;
P_0c071246: /* original f40c, guest PC 0x0c071246 */
if(!s->budget--) { s->failed_pc=0x0c071246u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c071248;
P_0c071248: /* original f345, guest PC 0x0c071248 */
if(!s->budget--) { s->failed_pc=0x0c071248u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c07124a;
P_0c07124a: /* original 8902, guest PC 0x0c07124a */
if(!s->budget--) { s->failed_pc=0x0c07124au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c071252; }
goto P_0c07124c;
P_0c07124c: /* original d307, guest PC 0x0c07124c */
if(!s->budget--) { s->failed_pc=0x0c07124cu; return 0; }
r[3]=read(ram,0x0c07126cu,4);
goto P_0c07124e;
P_0c07124e: /* original 432b, guest PC 0x0c07124e */
if(!s->budget--) { s->failed_pc=0x0c07124eu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c071296u: goto P_0c071296;
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
P_0c071250: /* original 0009, guest PC 0x0c071250 */
if(!s->budget--) { s->failed_pc=0x0c071250u; return 0; }
goto P_0c071252;
P_0c071252: /* original ffe5, guest PC 0x0c071252 */
if(!s->budget--) { s->failed_pc=0x0c071252u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[14]))!=0);
goto P_0c071254;
P_0c071254: /* original 8902, guest PC 0x0c071254 */
if(!s->budget--) { s->failed_pc=0x0c071254u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07125c; }
goto P_0c071256;
P_0c071256: /* original d206, guest PC 0x0c071256 */
if(!s->budget--) { s->failed_pc=0x0c071256u; return 0; }
r[2]=read(ram,0x0c071270u,4);
goto P_0c071258;
P_0c071258: /* original 422b, guest PC 0x0c071258 */
if(!s->budget--) { s->failed_pc=0x0c071258u; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c07135cu: goto P_0c07135c;
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
P_0c07125a: /* original 0009, guest PC 0x0c07125a */
if(!s->budget--) { s->failed_pc=0x0c07125au; return 0; }
goto P_0c07125c;
P_0c07125c: /* original 64f3, guest PC 0x0c07125c */
if(!s->budget--) { s->failed_pc=0x0c07125cu; return 0; }
r[4]=r[15];
goto P_0c07125e;
P_0c07125e: /* original 65f3, guest PC 0x0c07125e */
if(!s->budget--) { s->failed_pc=0x0c07125eu; return 0; }
r[5]=r[15];
goto P_0c071260;
P_0c071260: /* original 741c, guest PC 0x0c071260 */
if(!s->budget--) { s->failed_pc=0x0c071260u; return 0; }
r[4]+=0x0000001cu;
goto P_0c071262;
P_0c071262: /* original f4fc, guest PC 0x0c071262 */
if(!s->budget--) { s->failed_pc=0x0c071262u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c071264;
P_0c071264: /* original 751c, guest PC 0x0c071264 */
if(!s->budget--) { s->failed_pc=0x0c071264u; return 0; }
r[5]+=0x0000001cu;
goto P_0c071266;
P_0c071266: /* original a005, guest PC 0x0c071266 */
if(!s->budget--) { s->failed_pc=0x0c071266u; return 0; }
goto P_0c071274;
P_0c071268: /* original 0009, guest PC 0x0c071268 */
if(!s->budget--) { s->failed_pc=0x0c071268u; return 0; }
if(!vf3_matrix_family(0x0c07126au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07126au; return 0; } return 1;
P_0c071274: /* original f059, guest PC 0x0c071274 */
if(!s->budget--) { s->failed_pc=0x0c071274u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071276;
P_0c071276: /* original f159, guest PC 0x0c071276 */
if(!s->budget--) { s->failed_pc=0x0c071276u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071278;
P_0c071278: /* original f259, guest PC 0x0c071278 */
if(!s->budget--) { s->failed_pc=0x0c071278u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07127a;
P_0c07127a: /* original f38d, guest PC 0x0c07127a */
if(!s->budget--) { s->failed_pc=0x0c07127au; return 0; }
fr[3]=0;
goto P_0c07127c;
P_0c07127c: /* original f0ed, guest PC 0x0c07127c */
if(!s->budget--) { s->failed_pc=0x0c07127cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07127e;
P_0c07127e: /* original f37d, guest PC 0x0c07127e */
if(!s->budget--) { s->failed_pc=0x0c07127eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071280;
P_0c071280: /* original f342, guest PC 0x0c071280 */
if(!s->budget--) { s->failed_pc=0x0c071280u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c071282;
P_0c071282: /* original 740c, guest PC 0x0c071282 */
if(!s->budget--) { s->failed_pc=0x0c071282u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071284;
P_0c071284: /* original f232, guest PC 0x0c071284 */
if(!s->budget--) { s->failed_pc=0x0c071284u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071286;
P_0c071286: /* original f132, guest PC 0x0c071286 */
if(!s->budget--) { s->failed_pc=0x0c071286u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071288;
P_0c071288: /* original f032, guest PC 0x0c071288 */
if(!s->budget--) { s->failed_pc=0x0c071288u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c07128a;
P_0c07128a: /* original f42b, guest PC 0x0c07128a */
if(!s->budget--) { s->failed_pc=0x0c07128au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07128c;
P_0c07128c: /* original f41b, guest PC 0x0c07128c */
if(!s->budget--) { s->failed_pc=0x0c07128cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07128e;
P_0c07128e: /* original f40b, guest PC 0x0c07128e */
if(!s->budget--) { s->failed_pc=0x0c07128eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071290;
P_0c071290: /* original d206, guest PC 0x0c071290 */
if(!s->budget--) { s->failed_pc=0x0c071290u; return 0; }
r[2]=read(ram,0x0c0712acu,4);
goto P_0c071292;
P_0c071292: /* original 422b, guest PC 0x0c071292 */
if(!s->budget--) { s->failed_pc=0x0c071292u; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c071338u: goto P_0c071338;
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
P_0c071294: /* original 0009, guest PC 0x0c071294 */
if(!s->budget--) { s->failed_pc=0x0c071294u; return 0; }
goto P_0c071296;
P_0c071296: /* original fc45, guest PC 0x0c071296 */
if(!s->budget--) { s->failed_pc=0x0c071296u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[12])>as_float(fr[4]))!=0);
goto P_0c071298;
P_0c071298: /* original 8902, guest PC 0x0c071298 */
if(!s->budget--) { s->failed_pc=0x0c071298u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0712a0; }
goto P_0c07129a;
P_0c07129a: /* original d205, guest PC 0x0c07129a */
if(!s->budget--) { s->failed_pc=0x0c07129au; return 0; }
r[2]=read(ram,0x0c0712b0u,4);
goto P_0c07129c;
P_0c07129c: /* original 422b, guest PC 0x0c07129c */
if(!s->budget--) { s->failed_pc=0x0c07129cu; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c07135cu: goto P_0c07135c;
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
P_0c07129e: /* original 0009, guest PC 0x0c07129e */
if(!s->budget--) { s->failed_pc=0x0c07129eu; return 0; }
goto P_0c0712a0;
P_0c0712a0: /* original 64f3, guest PC 0x0c0712a0 */
if(!s->budget--) { s->failed_pc=0x0c0712a0u; return 0; }
r[4]=r[15];
goto P_0c0712a2;
P_0c0712a2: /* original 7410, guest PC 0x0c0712a2 */
if(!s->budget--) { s->failed_pc=0x0c0712a2u; return 0; }
r[4]+=0x00000010u;
goto P_0c0712a4;
P_0c0712a4: /* original 65d3, guest PC 0x0c0712a4 */
if(!s->budget--) { s->failed_pc=0x0c0712a4u; return 0; }
r[5]=r[13];
goto P_0c0712a6;
P_0c0712a6: /* original a005, guest PC 0x0c0712a6 */
if(!s->budget--) { s->failed_pc=0x0c0712a6u; return 0; }
goto P_0c0712b4;
P_0c0712a8: /* original 0009, guest PC 0x0c0712a8 */
if(!s->budget--) { s->failed_pc=0x0c0712a8u; return 0; }
if(!vf3_matrix_family(0x0c0712aau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0712aau; return 0; } return 1;
P_0c0712b4: /* original f059, guest PC 0x0c0712b4 */
if(!s->budget--) { s->failed_pc=0x0c0712b4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0712b6;
P_0c0712b6: /* original f159, guest PC 0x0c0712b6 */
if(!s->budget--) { s->failed_pc=0x0c0712b6u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0712b8;
P_0c0712b8: /* original f259, guest PC 0x0c0712b8 */
if(!s->budget--) { s->failed_pc=0x0c0712b8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0712ba;
P_0c0712ba: /* original 740c, guest PC 0x0c0712ba */
if(!s->budget--) { s->failed_pc=0x0c0712bau; return 0; }
r[4]+=0x0000000cu;
goto P_0c0712bc;
P_0c0712bc: /* original f242, guest PC 0x0c0712bc */
if(!s->budget--) { s->failed_pc=0x0c0712bcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c0712be;
P_0c0712be: /* original f142, guest PC 0x0c0712be */
if(!s->budget--) { s->failed_pc=0x0c0712beu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c0712c0;
P_0c0712c0: /* original f042, guest PC 0x0c0712c0 */
if(!s->budget--) { s->failed_pc=0x0c0712c0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c0712c2;
P_0c0712c2: /* original f42b, guest PC 0x0c0712c2 */
if(!s->budget--) { s->failed_pc=0x0c0712c2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0712c4;
P_0c0712c4: /* original f41b, guest PC 0x0c0712c4 */
if(!s->budget--) { s->failed_pc=0x0c0712c4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0712c6;
P_0c0712c6: /* original f40b, guest PC 0x0c0712c6 */
if(!s->budget--) { s->failed_pc=0x0c0712c6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0712c8;
P_0c0712c8: /* original 65f3, guest PC 0x0c0712c8 */
if(!s->budget--) { s->failed_pc=0x0c0712c8u; return 0; }
r[5]=r[15];
goto P_0c0712ca;
P_0c0712ca: /* original 64f3, guest PC 0x0c0712ca */
if(!s->budget--) { s->failed_pc=0x0c0712cau; return 0; }
r[4]=r[15];
goto P_0c0712cc;
P_0c0712cc: /* original 66f3, guest PC 0x0c0712cc */
if(!s->budget--) { s->failed_pc=0x0c0712ccu; return 0; }
r[6]=r[15];
goto P_0c0712ce;
P_0c0712ce: /* original 7410, guest PC 0x0c0712ce */
if(!s->budget--) { s->failed_pc=0x0c0712ceu; return 0; }
r[4]+=0x00000010u;
goto P_0c0712d0;
P_0c0712d0: /* original 7610, guest PC 0x0c0712d0 */
if(!s->budget--) { s->failed_pc=0x0c0712d0u; return 0; }
r[6]+=0x00000010u;
goto P_0c0712d2;
P_0c0712d2: /* original 751c, guest PC 0x0c0712d2 */
if(!s->budget--) { s->failed_pc=0x0c0712d2u; return 0; }
r[5]+=0x0000001cu;
goto P_0c0712d4;
P_0c0712d4: /* original f059, guest PC 0x0c0712d4 */
if(!s->budget--) { s->failed_pc=0x0c0712d4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0712d6;
P_0c0712d6: /* original f369, guest PC 0x0c0712d6 */
if(!s->budget--) { s->failed_pc=0x0c0712d6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0712d8;
P_0c0712d8: /* original f159, guest PC 0x0c0712d8 */
if(!s->budget--) { s->failed_pc=0x0c0712d8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0712da;
P_0c0712da: /* original f469, guest PC 0x0c0712da */
if(!s->budget--) { s->failed_pc=0x0c0712dau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0712dc;
P_0c0712dc: /* original f031, guest PC 0x0c0712dc */
if(!s->budget--) { s->failed_pc=0x0c0712dcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0712de;
P_0c0712de: /* original f258, guest PC 0x0c0712de */
if(!s->budget--) { s->failed_pc=0x0c0712deu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0712e0;
P_0c0712e0: /* original f568, guest PC 0x0c0712e0 */
if(!s->budget--) { s->failed_pc=0x0c0712e0u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0712e2;
P_0c0712e2: /* original f141, guest PC 0x0c0712e2 */
if(!s->budget--) { s->failed_pc=0x0c0712e2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0712e4;
P_0c0712e4: /* original f251, guest PC 0x0c0712e4 */
if(!s->budget--) { s->failed_pc=0x0c0712e4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0712e6;
P_0c0712e6: /* original 7408, guest PC 0x0c0712e6 */
if(!s->budget--) { s->failed_pc=0x0c0712e6u; return 0; }
r[4]+=0x00000008u;
goto P_0c0712e8;
P_0c0712e8: /* original f42a, guest PC 0x0c0712e8 */
if(!s->budget--) { s->failed_pc=0x0c0712e8u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0712ea;
P_0c0712ea: /* original f41b, guest PC 0x0c0712ea */
if(!s->budget--) { s->failed_pc=0x0c0712eau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0712ec;
P_0c0712ec: /* original f40b, guest PC 0x0c0712ec */
if(!s->budget--) { s->failed_pc=0x0c0712ecu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0712ee;
P_0c0712ee: /* original 0009, guest PC 0x0c0712ee */
if(!s->budget--) { s->failed_pc=0x0c0712eeu; return 0; }
goto P_0c0712f0;
P_0c0712f0: /* original f4fc, guest PC 0x0c0712f0 */
if(!s->budget--) { s->failed_pc=0x0c0712f0u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0712f2;
P_0c0712f2: /* original f4d1, guest PC 0x0c0712f2 */
if(!s->budget--) { s->failed_pc=0x0c0712f2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[13],r[18],'-');
goto P_0c0712f4;
P_0c0712f4: /* original 64f3, guest PC 0x0c0712f4 */
if(!s->budget--) { s->failed_pc=0x0c0712f4u; return 0; }
r[4]=r[15];
goto P_0c0712f6;
P_0c0712f6: /* original 65f3, guest PC 0x0c0712f6 */
if(!s->budget--) { s->failed_pc=0x0c0712f6u; return 0; }
r[5]=r[15];
goto P_0c0712f8;
P_0c0712f8: /* original 7410, guest PC 0x0c0712f8 */
if(!s->budget--) { s->failed_pc=0x0c0712f8u; return 0; }
r[4]+=0x00000010u;
goto P_0c0712fa;
P_0c0712fa: /* original 7510, guest PC 0x0c0712fa */
if(!s->budget--) { s->failed_pc=0x0c0712fau; return 0; }
r[5]+=0x00000010u;
goto P_0c0712fc;
P_0c0712fc: /* original f059, guest PC 0x0c0712fc */
if(!s->budget--) { s->failed_pc=0x0c0712fcu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0712fe;
P_0c0712fe: /* original f159, guest PC 0x0c0712fe */
if(!s->budget--) { s->failed_pc=0x0c0712feu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071300;
P_0c071300: /* original f259, guest PC 0x0c071300 */
if(!s->budget--) { s->failed_pc=0x0c071300u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071302;
P_0c071302: /* original f38d, guest PC 0x0c071302 */
if(!s->budget--) { s->failed_pc=0x0c071302u; return 0; }
fr[3]=0;
goto P_0c071304;
P_0c071304: /* original f0ed, guest PC 0x0c071304 */
if(!s->budget--) { s->failed_pc=0x0c071304u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071306;
P_0c071306: /* original f37d, guest PC 0x0c071306 */
if(!s->budget--) { s->failed_pc=0x0c071306u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071308;
P_0c071308: /* original f342, guest PC 0x0c071308 */
if(!s->budget--) { s->failed_pc=0x0c071308u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c07130a;
P_0c07130a: /* original 740c, guest PC 0x0c07130a */
if(!s->budget--) { s->failed_pc=0x0c07130au; return 0; }
r[4]+=0x0000000cu;
goto P_0c07130c;
P_0c07130c: /* original f232, guest PC 0x0c07130c */
if(!s->budget--) { s->failed_pc=0x0c07130cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07130e;
P_0c07130e: /* original f132, guest PC 0x0c07130e */
if(!s->budget--) { s->failed_pc=0x0c07130eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071310;
P_0c071310: /* original f032, guest PC 0x0c071310 */
if(!s->budget--) { s->failed_pc=0x0c071310u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071312;
P_0c071312: /* original f42b, guest PC 0x0c071312 */
if(!s->budget--) { s->failed_pc=0x0c071312u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071314;
P_0c071314: /* original f41b, guest PC 0x0c071314 */
if(!s->budget--) { s->failed_pc=0x0c071314u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071316;
P_0c071316: /* original f40b, guest PC 0x0c071316 */
if(!s->budget--) { s->failed_pc=0x0c071316u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071318;
P_0c071318: /* original 64f3, guest PC 0x0c071318 */
if(!s->budget--) { s->failed_pc=0x0c071318u; return 0; }
r[4]=r[15];
goto P_0c07131a;
P_0c07131a: /* original 65f3, guest PC 0x0c07131a */
if(!s->budget--) { s->failed_pc=0x0c07131au; return 0; }
r[5]=r[15];
goto P_0c07131c;
P_0c07131c: /* original 741c, guest PC 0x0c07131c */
if(!s->budget--) { s->failed_pc=0x0c07131cu; return 0; }
r[4]+=0x0000001cu;
goto P_0c07131e;
P_0c07131e: /* original 7510, guest PC 0x0c07131e */
if(!s->budget--) { s->failed_pc=0x0c07131eu; return 0; }
r[5]+=0x00000010u;
goto P_0c071320;
P_0c071320: /* original f049, guest PC 0x0c071320 */
if(!s->budget--) { s->failed_pc=0x0c071320u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071322;
P_0c071322: /* original f359, guest PC 0x0c071322 */
if(!s->budget--) { s->failed_pc=0x0c071322u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071324;
P_0c071324: /* original f149, guest PC 0x0c071324 */
if(!s->budget--) { s->failed_pc=0x0c071324u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071326;
P_0c071326: /* original f459, guest PC 0x0c071326 */
if(!s->budget--) { s->failed_pc=0x0c071326u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071328;
P_0c071328: /* original f249, guest PC 0x0c071328 */
if(!s->budget--) { s->failed_pc=0x0c071328u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07132a;
P_0c07132a: /* original f559, guest PC 0x0c07132a */
if(!s->budget--) { s->failed_pc=0x0c07132au; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07132c;
P_0c07132c: /* original f030, guest PC 0x0c07132c */
if(!s->budget--) { s->failed_pc=0x0c07132cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c07132e;
P_0c07132e: /* original f250, guest PC 0x0c07132e */
if(!s->budget--) { s->failed_pc=0x0c07132eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c071330;
P_0c071330: /* original f140, guest PC 0x0c071330 */
if(!s->budget--) { s->failed_pc=0x0c071330u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071332;
P_0c071332: /* original f42b, guest PC 0x0c071332 */
if(!s->budget--) { s->failed_pc=0x0c071332u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071334;
P_0c071334: /* original f41b, guest PC 0x0c071334 */
if(!s->budget--) { s->failed_pc=0x0c071334u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071336;
P_0c071336: /* original f40b, guest PC 0x0c071336 */
if(!s->budget--) { s->failed_pc=0x0c071336u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071338;
P_0c071338: /* original 65f3, guest PC 0x0c071338 */
if(!s->budget--) { s->failed_pc=0x0c071338u; return 0; }
r[5]=r[15];
goto P_0c07133a;
P_0c07133a: /* original 64e3, guest PC 0x0c07133a */
if(!s->budget--) { s->failed_pc=0x0c07133au; return 0; }
r[4]=r[14];
goto P_0c07133c;
P_0c07133c: /* original 751c, guest PC 0x0c07133c */
if(!s->budget--) { s->failed_pc=0x0c07133cu; return 0; }
r[5]+=0x0000001cu;
goto P_0c07133e;
P_0c07133e: /* original 66b3, guest PC 0x0c07133e */
if(!s->budget--) { s->failed_pc=0x0c07133eu; return 0; }
r[6]=r[11];
goto P_0c071340;
P_0c071340: /* original f059, guest PC 0x0c071340 */
if(!s->budget--) { s->failed_pc=0x0c071340u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071342;
P_0c071342: /* original f369, guest PC 0x0c071342 */
if(!s->budget--) { s->failed_pc=0x0c071342u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071344;
P_0c071344: /* original f159, guest PC 0x0c071344 */
if(!s->budget--) { s->failed_pc=0x0c071344u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071346;
P_0c071346: /* original f469, guest PC 0x0c071346 */
if(!s->budget--) { s->failed_pc=0x0c071346u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071348;
P_0c071348: /* original f259, guest PC 0x0c071348 */
if(!s->budget--) { s->failed_pc=0x0c071348u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07134a;
P_0c07134a: /* original f569, guest PC 0x0c07134a */
if(!s->budget--) { s->failed_pc=0x0c07134au; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07134c;
P_0c07134c: /* original 740c, guest PC 0x0c07134c */
if(!s->budget--) { s->failed_pc=0x0c07134cu; return 0; }
r[4]+=0x0000000cu;
goto P_0c07134e;
P_0c07134e: /* original f030, guest PC 0x0c07134e */
if(!s->budget--) { s->failed_pc=0x0c07134eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c071350;
P_0c071350: /* original f250, guest PC 0x0c071350 */
if(!s->budget--) { s->failed_pc=0x0c071350u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c071352;
P_0c071352: /* original f140, guest PC 0x0c071352 */
if(!s->budget--) { s->failed_pc=0x0c071352u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071354;
P_0c071354: /* original f42b, guest PC 0x0c071354 */
if(!s->budget--) { s->failed_pc=0x0c071354u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071356;
P_0c071356: /* original f41b, guest PC 0x0c071356 */
if(!s->budget--) { s->failed_pc=0x0c071356u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071358;
P_0c071358: /* original f40b, guest PC 0x0c071358 */
if(!s->budget--) { s->failed_pc=0x0c071358u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07135a;
P_0c07135a: /* original 0009, guest PC 0x0c07135a */
if(!s->budget--) { s->failed_pc=0x0c07135au; return 0; }
goto P_0c07135c;
P_0c07135c: /* original 64f3, guest PC 0x0c07135c */
if(!s->budget--) { s->failed_pc=0x0c07135cu; return 0; }
r[4]=r[15];
goto P_0c07135e;
P_0c07135e: /* original 7404, guest PC 0x0c07135e */
if(!s->budget--) { s->failed_pc=0x0c07135eu; return 0; }
r[4]+=0x00000004u;
goto P_0c071360;
P_0c071360: /* original 66c3, guest PC 0x0c071360 */
if(!s->budget--) { s->failed_pc=0x0c071360u; return 0; }
r[6]=r[12];
goto P_0c071362;
P_0c071362: /* original 65e3, guest PC 0x0c071362 */
if(!s->budget--) { s->failed_pc=0x0c071362u; return 0; }
r[5]=r[14];
goto P_0c071364;
P_0c071364: /* original f059, guest PC 0x0c071364 */
if(!s->budget--) { s->failed_pc=0x0c071364u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071366;
P_0c071366: /* original f369, guest PC 0x0c071366 */
if(!s->budget--) { s->failed_pc=0x0c071366u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071368;
P_0c071368: /* original f159, guest PC 0x0c071368 */
if(!s->budget--) { s->failed_pc=0x0c071368u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07136a;
P_0c07136a: /* original f469, guest PC 0x0c07136a */
if(!s->budget--) { s->failed_pc=0x0c07136au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07136c;
P_0c07136c: /* original f031, guest PC 0x0c07136c */
if(!s->budget--) { s->failed_pc=0x0c07136cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c07136e;
P_0c07136e: /* original f258, guest PC 0x0c07136e */
if(!s->budget--) { s->failed_pc=0x0c07136eu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071370;
P_0c071370: /* original f568, guest PC 0x0c071370 */
if(!s->budget--) { s->failed_pc=0x0c071370u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071372;
P_0c071372: /* original f141, guest PC 0x0c071372 */
if(!s->budget--) { s->failed_pc=0x0c071372u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071374;
P_0c071374: /* original f251, guest PC 0x0c071374 */
if(!s->budget--) { s->failed_pc=0x0c071374u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071376;
P_0c071376: /* original 7408, guest PC 0x0c071376 */
if(!s->budget--) { s->failed_pc=0x0c071376u; return 0; }
r[4]+=0x00000008u;
goto P_0c071378;
P_0c071378: /* original f42a, guest PC 0x0c071378 */
if(!s->budget--) { s->failed_pc=0x0c071378u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07137a;
P_0c07137a: /* original f41b, guest PC 0x0c07137a */
if(!s->budget--) { s->failed_pc=0x0c07137au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07137c;
P_0c07137c: /* original f40b, guest PC 0x0c07137c */
if(!s->budget--) { s->failed_pc=0x0c07137cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07137e;
P_0c07137e: /* original 0009, guest PC 0x0c07137e */
if(!s->budget--) { s->failed_pc=0x0c07137eu; return 0; }
goto P_0c071380;
P_0c071380: /* original 64f3, guest PC 0x0c071380 */
if(!s->budget--) { s->failed_pc=0x0c071380u; return 0; }
r[4]=r[15];
goto P_0c071382;
P_0c071382: /* original 7404, guest PC 0x0c071382 */
if(!s->budget--) { s->failed_pc=0x0c071382u; return 0; }
r[4]+=0x00000004u;
goto P_0c071384;
P_0c071384: /* original f049, guest PC 0x0c071384 */
if(!s->budget--) { s->failed_pc=0x0c071384u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071386;
P_0c071386: /* original f149, guest PC 0x0c071386 */
if(!s->budget--) { s->failed_pc=0x0c071386u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071388;
P_0c071388: /* original f249, guest PC 0x0c071388 */
if(!s->budget--) { s->failed_pc=0x0c071388u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07138a;
P_0c07138a: /* original f38d, guest PC 0x0c07138a */
if(!s->budget--) { s->failed_pc=0x0c07138au; return 0; }
fr[3]=0;
goto P_0c07138c;
P_0c07138c: /* original f0ed, guest PC 0x0c07138c */
if(!s->budget--) { s->failed_pc=0x0c07138cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07138e;
P_0c07138e: /* original f03c, guest PC 0x0c07138e */
if(!s->budget--) { s->failed_pc=0x0c07138eu; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c071390;
P_0c071390: /* original f06d, guest PC 0x0c071390 */
if(!s->budget--) { s->failed_pc=0x0c071390u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c071392;
P_0c071392: /* original 0009, guest PC 0x0c071392 */
if(!s->budget--) { s->failed_pc=0x0c071392u; return 0; }
goto P_0c071394;
P_0c071394: /* original f38d, guest PC 0x0c071394 */
if(!s->budget--) { s->failed_pc=0x0c071394u; return 0; }
fr[3]=0;
goto P_0c071396;
P_0c071396: /* original f035, guest PC 0x0c071396 */
if(!s->budget--) { s->failed_pc=0x0c071396u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c071398;
P_0c071398: /* original 8902, guest PC 0x0c071398 */
if(!s->budget--) { s->failed_pc=0x0c071398u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0713a0; }
goto P_0c07139a;
P_0c07139a: /* original d305, guest PC 0x0c07139a */
if(!s->budget--) { s->failed_pc=0x0c07139au; return 0; }
r[3]=read(ram,0x0c0713b0u,4);
goto P_0c07139c;
P_0c07139c: /* original 432b, guest PC 0x0c07139c */
if(!s->budget--) { s->failed_pc=0x0c07139cu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0713f4u: goto P_0c0713f4;
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
P_0c07139e: /* original 0009, guest PC 0x0c07139e */
if(!s->budget--) { s->failed_pc=0x0c07139eu; return 0; }
goto P_0c0713a0;
P_0c0713a0: /* original 64f3, guest PC 0x0c0713a0 */
if(!s->budget--) { s->failed_pc=0x0c0713a0u; return 0; }
r[4]=r[15];
goto P_0c0713a2;
P_0c0713a2: /* original 65f3, guest PC 0x0c0713a2 */
if(!s->budget--) { s->failed_pc=0x0c0713a2u; return 0; }
r[5]=r[15];
goto P_0c0713a4;
P_0c0713a4: /* original f4f8, guest PC 0x0c0713a4 */
if(!s->budget--) { s->failed_pc=0x0c0713a4u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0713a6;
P_0c0713a6: /* original 7404, guest PC 0x0c0713a6 */
if(!s->budget--) { s->failed_pc=0x0c0713a6u; return 0; }
r[4]+=0x00000004u;
goto P_0c0713a8;
P_0c0713a8: /* original 7504, guest PC 0x0c0713a8 */
if(!s->budget--) { s->failed_pc=0x0c0713a8u; return 0; }
r[5]+=0x00000004u;
goto P_0c0713aa;
P_0c0713aa: /* original a003, guest PC 0x0c0713aa */
if(!s->budget--) { s->failed_pc=0x0c0713aau; return 0; }
goto P_0c0713b4;
P_0c0713ac: /* original 0009, guest PC 0x0c0713ac */
if(!s->budget--) { s->failed_pc=0x0c0713acu; return 0; }
if(!vf3_matrix_family(0x0c0713aeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0713aeu; return 0; } return 1;
P_0c0713b4: /* original f059, guest PC 0x0c0713b4 */
if(!s->budget--) { s->failed_pc=0x0c0713b4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0713b6;
P_0c0713b6: /* original f159, guest PC 0x0c0713b6 */
if(!s->budget--) { s->failed_pc=0x0c0713b6u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0713b8;
P_0c0713b8: /* original f259, guest PC 0x0c0713b8 */
if(!s->budget--) { s->failed_pc=0x0c0713b8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0713ba;
P_0c0713ba: /* original f38d, guest PC 0x0c0713ba */
if(!s->budget--) { s->failed_pc=0x0c0713bau; return 0; }
fr[3]=0;
goto P_0c0713bc;
P_0c0713bc: /* original f0ed, guest PC 0x0c0713bc */
if(!s->budget--) { s->failed_pc=0x0c0713bcu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0713be;
P_0c0713be: /* original f37d, guest PC 0x0c0713be */
if(!s->budget--) { s->failed_pc=0x0c0713beu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0713c0;
P_0c0713c0: /* original f342, guest PC 0x0c0713c0 */
if(!s->budget--) { s->failed_pc=0x0c0713c0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0713c2;
P_0c0713c2: /* original 740c, guest PC 0x0c0713c2 */
if(!s->budget--) { s->failed_pc=0x0c0713c2u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0713c4;
P_0c0713c4: /* original f232, guest PC 0x0c0713c4 */
if(!s->budget--) { s->failed_pc=0x0c0713c4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0713c6;
P_0c0713c6: /* original f132, guest PC 0x0c0713c6 */
if(!s->budget--) { s->failed_pc=0x0c0713c6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0713c8;
P_0c0713c8: /* original f032, guest PC 0x0c0713c8 */
if(!s->budget--) { s->failed_pc=0x0c0713c8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0713ca;
P_0c0713ca: /* original f42b, guest PC 0x0c0713ca */
if(!s->budget--) { s->failed_pc=0x0c0713cau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0713cc;
P_0c0713cc: /* original f41b, guest PC 0x0c0713cc */
if(!s->budget--) { s->failed_pc=0x0c0713ccu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0713ce;
P_0c0713ce: /* original f40b, guest PC 0x0c0713ce */
if(!s->budget--) { s->failed_pc=0x0c0713ceu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0713d0;
P_0c0713d0: /* original 66f3, guest PC 0x0c0713d0 */
if(!s->budget--) { s->failed_pc=0x0c0713d0u; return 0; }
r[6]=r[15];
goto P_0c0713d2;
P_0c0713d2: /* original 64e3, guest PC 0x0c0713d2 */
if(!s->budget--) { s->failed_pc=0x0c0713d2u; return 0; }
r[4]=r[14];
goto P_0c0713d4;
P_0c0713d4: /* original 65c3, guest PC 0x0c0713d4 */
if(!s->budget--) { s->failed_pc=0x0c0713d4u; return 0; }
r[5]=r[12];
goto P_0c0713d6;
P_0c0713d6: /* original 7604, guest PC 0x0c0713d6 */
if(!s->budget--) { s->failed_pc=0x0c0713d6u; return 0; }
r[6]+=0x00000004u;
goto P_0c0713d8;
P_0c0713d8: /* original f059, guest PC 0x0c0713d8 */
if(!s->budget--) { s->failed_pc=0x0c0713d8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0713da;
P_0c0713da: /* original f369, guest PC 0x0c0713da */
if(!s->budget--) { s->failed_pc=0x0c0713dau; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0713dc;
P_0c0713dc: /* original f159, guest PC 0x0c0713dc */
if(!s->budget--) { s->failed_pc=0x0c0713dcu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0713de;
P_0c0713de: /* original f469, guest PC 0x0c0713de */
if(!s->budget--) { s->failed_pc=0x0c0713deu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0713e0;
P_0c0713e0: /* original f259, guest PC 0x0c0713e0 */
if(!s->budget--) { s->failed_pc=0x0c0713e0u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0713e2;
P_0c0713e2: /* original f569, guest PC 0x0c0713e2 */
if(!s->budget--) { s->failed_pc=0x0c0713e2u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0713e4;
P_0c0713e4: /* original 740c, guest PC 0x0c0713e4 */
if(!s->budget--) { s->failed_pc=0x0c0713e4u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0713e6;
P_0c0713e6: /* original f030, guest PC 0x0c0713e6 */
if(!s->budget--) { s->failed_pc=0x0c0713e6u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c0713e8;
P_0c0713e8: /* original f250, guest PC 0x0c0713e8 */
if(!s->budget--) { s->failed_pc=0x0c0713e8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c0713ea;
P_0c0713ea: /* original f140, guest PC 0x0c0713ea */
if(!s->budget--) { s->failed_pc=0x0c0713eau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c0713ec;
P_0c0713ec: /* original f42b, guest PC 0x0c0713ec */
if(!s->budget--) { s->failed_pc=0x0c0713ecu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0713ee;
P_0c0713ee: /* original f41b, guest PC 0x0c0713ee */
if(!s->budget--) { s->failed_pc=0x0c0713eeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0713f0;
P_0c0713f0: /* original f40b, guest PC 0x0c0713f0 */
if(!s->budget--) { s->failed_pc=0x0c0713f0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0713f2;
P_0c0713f2: /* original 0009, guest PC 0x0c0713f2 */
if(!s->budget--) { s->failed_pc=0x0c0713f2u; return 0; }
goto P_0c0713f4;
P_0c0713f4: /* original 39a7, guest PC 0x0c0713f4 */
if(!s->budget--) { s->failed_pc=0x0c0713f4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>(int32_t)r[10])!=0);
goto P_0c0713f6;
P_0c0713f6: /* original 8d03, guest PC 0x0c0713f6 */
if(!s->budget--) { s->failed_pc=0x0c0713f6u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000018u;
if(cond) { goto P_0c071400; }
goto P_0c0713fa;
P_0c0713f8: /* original 7e18, guest PC 0x0c0713f8 */
if(!s->budget--) { s->failed_pc=0x0c0713f8u; return 0; }
r[14]+=0x00000018u;
goto P_0c0713fa;
P_0c0713fa: /* original d304, guest PC 0x0c0713fa */
if(!s->budget--) { s->failed_pc=0x0c0713fau; return 0; }
r[3]=read(ram,0x0c07140cu,4);
goto P_0c0713fc;
P_0c0713fc: /* original 432b, guest PC 0x0c0713fc */
if(!s->budget--) { s->failed_pc=0x0c0713fcu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c07167cu: goto P_0c07167c;
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
P_0c0713fe: /* original 0009, guest PC 0x0c0713fe */
if(!s->budget--) { s->failed_pc=0x0c0713feu; return 0; }
goto P_0c071400;
P_0c071400: /* original 64f3, guest PC 0x0c071400 */
if(!s->budget--) { s->failed_pc=0x0c071400u; return 0; }
r[4]=r[15];
goto P_0c071402;
P_0c071402: /* original 741c, guest PC 0x0c071402 */
if(!s->budget--) { s->failed_pc=0x0c071402u; return 0; }
r[4]+=0x0000001cu;
goto P_0c071404;
P_0c071404: /* original 66b3, guest PC 0x0c071404 */
if(!s->budget--) { s->failed_pc=0x0c071404u; return 0; }
r[6]=r[11];
goto P_0c071406;
P_0c071406: /* original 65e3, guest PC 0x0c071406 */
if(!s->budget--) { s->failed_pc=0x0c071406u; return 0; }
r[5]=r[14];
goto P_0c071408;
P_0c071408: /* original a002, guest PC 0x0c071408 */
if(!s->budget--) { s->failed_pc=0x0c071408u; return 0; }
goto P_0c071410;
P_0c07140a: /* original 0009, guest PC 0x0c07140a */
if(!s->budget--) { s->failed_pc=0x0c07140au; return 0; }
if(!vf3_matrix_family(0x0c07140cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07140cu; return 0; } return 1;
P_0c071410: /* original f059, guest PC 0x0c071410 */
if(!s->budget--) { s->failed_pc=0x0c071410u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071412;
P_0c071412: /* original f369, guest PC 0x0c071412 */
if(!s->budget--) { s->failed_pc=0x0c071412u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071414;
P_0c071414: /* original f159, guest PC 0x0c071414 */
if(!s->budget--) { s->failed_pc=0x0c071414u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071416;
P_0c071416: /* original f469, guest PC 0x0c071416 */
if(!s->budget--) { s->failed_pc=0x0c071416u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071418;
P_0c071418: /* original f031, guest PC 0x0c071418 */
if(!s->budget--) { s->failed_pc=0x0c071418u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c07141a;
P_0c07141a: /* original f258, guest PC 0x0c07141a */
if(!s->budget--) { s->failed_pc=0x0c07141au; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c07141c;
P_0c07141c: /* original f568, guest PC 0x0c07141c */
if(!s->budget--) { s->failed_pc=0x0c07141cu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c07141e;
P_0c07141e: /* original f141, guest PC 0x0c07141e */
if(!s->budget--) { s->failed_pc=0x0c07141eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071420;
P_0c071420: /* original f251, guest PC 0x0c071420 */
if(!s->budget--) { s->failed_pc=0x0c071420u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071422;
P_0c071422: /* original 7408, guest PC 0x0c071422 */
if(!s->budget--) { s->failed_pc=0x0c071422u; return 0; }
r[4]+=0x00000008u;
goto P_0c071424;
P_0c071424: /* original f42a, guest PC 0x0c071424 */
if(!s->budget--) { s->failed_pc=0x0c071424u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071426;
P_0c071426: /* original f41b, guest PC 0x0c071426 */
if(!s->budget--) { s->failed_pc=0x0c071426u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071428;
P_0c071428: /* original f40b, guest PC 0x0c071428 */
if(!s->budget--) { s->failed_pc=0x0c071428u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07142a;
P_0c07142a: /* original 0009, guest PC 0x0c07142a */
if(!s->budget--) { s->failed_pc=0x0c07142au; return 0; }
goto P_0c07142c;
P_0c07142c: /* original 64f3, guest PC 0x0c07142c */
if(!s->budget--) { s->failed_pc=0x0c07142cu; return 0; }
r[4]=r[15];
goto P_0c07142e;
P_0c07142e: /* original 741c, guest PC 0x0c07142e */
if(!s->budget--) { s->failed_pc=0x0c07142eu; return 0; }
r[4]+=0x0000001cu;
goto P_0c071430;
P_0c071430: /* original f049, guest PC 0x0c071430 */
if(!s->budget--) { s->failed_pc=0x0c071430u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071432;
P_0c071432: /* original f149, guest PC 0x0c071432 */
if(!s->budget--) { s->failed_pc=0x0c071432u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071434;
P_0c071434: /* original f249, guest PC 0x0c071434 */
if(!s->budget--) { s->failed_pc=0x0c071434u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071436;
P_0c071436: /* original f38d, guest PC 0x0c071436 */
if(!s->budget--) { s->failed_pc=0x0c071436u; return 0; }
fr[3]=0;
goto P_0c071438;
P_0c071438: /* original f0ed, guest PC 0x0c071438 */
if(!s->budget--) { s->failed_pc=0x0c071438u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07143a;
P_0c07143a: /* original f03c, guest PC 0x0c07143a */
if(!s->budget--) { s->failed_pc=0x0c07143au; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c07143c;
P_0c07143c: /* original f06d, guest PC 0x0c07143c */
if(!s->budget--) { s->failed_pc=0x0c07143cu; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c07143e;
P_0c07143e: /* original 0009, guest PC 0x0c07143e */
if(!s->budget--) { s->failed_pc=0x0c07143eu; return 0; }
goto P_0c071440;
P_0c071440: /* original f38d, guest PC 0x0c071440 */
if(!s->budget--) { s->failed_pc=0x0c071440u; return 0; }
fr[3]=0;
goto P_0c071442;
P_0c071442: /* original fd0c, guest PC 0x0c071442 */
if(!s->budget--) { s->failed_pc=0x0c071442u; return 0; }
vf3_matrix_move(s,13,0);
goto P_0c071444;
P_0c071444: /* original fd35, guest PC 0x0c071444 */
if(!s->budget--) { s->failed_pc=0x0c071444u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[13])>as_float(fr[3]))!=0);
goto P_0c071446;
P_0c071446: /* original 8902, guest PC 0x0c071446 */
if(!s->budget--) { s->failed_pc=0x0c071446u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07144e; }
goto P_0c071448;
P_0c071448: /* original d303, guest PC 0x0c071448 */
if(!s->budget--) { s->failed_pc=0x0c071448u; return 0; }
r[3]=read(ram,0x0c071458u,4);
goto P_0c07144a;
P_0c07144a: /* original 432b, guest PC 0x0c07144a */
if(!s->budget--) { s->failed_pc=0x0c07144au; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0715d4u: goto P_0c0715d4;
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
P_0c07144c: /* original 0009, guest PC 0x0c07144c */
if(!s->budget--) { s->failed_pc=0x0c07144cu; return 0; }
goto P_0c07144e;
P_0c07144e: /* original 64f3, guest PC 0x0c07144e */
if(!s->budget--) { s->failed_pc=0x0c07144eu; return 0; }
r[4]=r[15];
goto P_0c071450;
P_0c071450: /* original 741c, guest PC 0x0c071450 */
if(!s->budget--) { s->failed_pc=0x0c071450u; return 0; }
r[4]+=0x0000001cu;
goto P_0c071452;
P_0c071452: /* original 65d3, guest PC 0x0c071452 */
if(!s->budget--) { s->failed_pc=0x0c071452u; return 0; }
r[5]=r[13];
goto P_0c071454;
P_0c071454: /* original a002, guest PC 0x0c071454 */
if(!s->budget--) { s->failed_pc=0x0c071454u; return 0; }
goto P_0c07145c;
P_0c071456: /* original 0009, guest PC 0x0c071456 */
if(!s->budget--) { s->failed_pc=0x0c071456u; return 0; }
if(!vf3_matrix_family(0x0c071458u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c071458u; return 0; } return 1;
P_0c07145c: /* original f049, guest PC 0x0c07145c */
if(!s->budget--) { s->failed_pc=0x0c07145cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07145e;
P_0c07145e: /* original f549, guest PC 0x0c07145e */
if(!s->budget--) { s->failed_pc=0x0c07145eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071460;
P_0c071460: /* original f648, guest PC 0x0c071460 */
if(!s->budget--) { s->failed_pc=0x0c071460u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c071462;
P_0c071462: /* original f859, guest PC 0x0c071462 */
if(!s->budget--) { s->failed_pc=0x0c071462u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071464;
P_0c071464: /* original f959, guest PC 0x0c071464 */
if(!s->budget--) { s->failed_pc=0x0c071464u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071466;
P_0c071466: /* original fa58, guest PC 0x0c071466 */
if(!s->budget--) { s->failed_pc=0x0c071466u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c071468;
P_0c071468: /* original f35c, guest PC 0x0c071468 */
if(!s->budget--) { s->failed_pc=0x0c071468u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c07146a;
P_0c07146a: /* original f382, guest PC 0x0c07146a */
if(!s->budget--) { s->failed_pc=0x0c07146au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c07146c;
P_0c07146c: /* original f20c, guest PC 0x0c07146c */
if(!s->budget--) { s->failed_pc=0x0c07146cu; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c07146e;
P_0c07146e: /* original f2a2, guest PC 0x0c07146e */
if(!s->budget--) { s->failed_pc=0x0c07146eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c071470;
P_0c071470: /* original f16c, guest PC 0x0c071470 */
if(!s->budget--) { s->failed_pc=0x0c071470u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c071472;
P_0c071472: /* original f192, guest PC 0x0c071472 */
if(!s->budget--) { s->failed_pc=0x0c071472u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c071474;
P_0c071474: /* original f34d, guest PC 0x0c071474 */
if(!s->budget--) { s->failed_pc=0x0c071474u; return 0; }
fr[3]^=0x80000000u;
goto P_0c071476;
P_0c071476: /* original f39e, guest PC 0x0c071476 */
if(!s->budget--) { s->failed_pc=0x0c071476u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071478;
P_0c071478: /* original f24d, guest PC 0x0c071478 */
if(!s->budget--) { s->failed_pc=0x0c071478u; return 0; }
fr[2]^=0x80000000u;
goto P_0c07147a;
P_0c07147a: /* original f06c, guest PC 0x0c07147a */
if(!s->budget--) { s->failed_pc=0x0c07147au; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c07147c;
P_0c07147c: /* original f28e, guest PC 0x0c07147c */
if(!s->budget--) { s->failed_pc=0x0c07147cu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c07147e;
P_0c07147e: /* original f14d, guest PC 0x0c07147e */
if(!s->budget--) { s->failed_pc=0x0c07147eu; return 0; }
fr[1]^=0x80000000u;
goto P_0c071480;
P_0c071480: /* original f05c, guest PC 0x0c071480 */
if(!s->budget--) { s->failed_pc=0x0c071480u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c071482;
P_0c071482: /* original f1ae, guest PC 0x0c071482 */
if(!s->budget--) { s->failed_pc=0x0c071482u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c071484;
P_0c071484: /* original f08d, guest PC 0x0c071484 */
if(!s->budget--) { s->failed_pc=0x0c071484u; return 0; }
fr[0]=0;
goto P_0c071486;
P_0c071486: /* original f0ed, guest PC 0x0c071486 */
if(!s->budget--) { s->failed_pc=0x0c071486u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071488;
P_0c071488: /* original f03c, guest PC 0x0c071488 */
if(!s->budget--) { s->failed_pc=0x0c071488u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c07148a;
P_0c07148a: /* original f06d, guest PC 0x0c07148a */
if(!s->budget--) { s->failed_pc=0x0c07148au; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c07148c;
P_0c07148c: /* original fe0c, guest PC 0x0c07148c */
if(!s->budget--) { s->failed_pc=0x0c07148cu; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c07148e;
P_0c07148e: /* original ffe5, guest PC 0x0c07148e */
if(!s->budget--) { s->failed_pc=0x0c07148eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[14]))!=0);
goto P_0c071490;
P_0c071490: /* original 8902, guest PC 0x0c071490 */
if(!s->budget--) { s->failed_pc=0x0c071490u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c071498; }
goto P_0c071492;
P_0c071492: /* original d304, guest PC 0x0c071492 */
if(!s->budget--) { s->failed_pc=0x0c071492u; return 0; }
r[3]=read(ram,0x0c0714a4u,4);
goto P_0c071494;
P_0c071494: /* original 432b, guest PC 0x0c071494 */
if(!s->budget--) { s->failed_pc=0x0c071494u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0715d4u: goto P_0c0715d4;
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
P_0c071496: /* original 0009, guest PC 0x0c071496 */
if(!s->budget--) { s->failed_pc=0x0c071496u; return 0; }
goto P_0c071498;
P_0c071498: /* original 64f3, guest PC 0x0c071498 */
if(!s->budget--) { s->failed_pc=0x0c071498u; return 0; }
r[4]=r[15];
goto P_0c07149a;
P_0c07149a: /* original 741c, guest PC 0x0c07149a */
if(!s->budget--) { s->failed_pc=0x0c07149au; return 0; }
r[4]+=0x0000001cu;
goto P_0c07149c;
P_0c07149c: /* original 65d3, guest PC 0x0c07149c */
if(!s->budget--) { s->failed_pc=0x0c07149cu; return 0; }
r[5]=r[13];
goto P_0c07149e;
P_0c07149e: /* original a003, guest PC 0x0c07149e */
if(!s->budget--) { s->failed_pc=0x0c07149eu; return 0; }
goto P_0c0714a8;
P_0c0714a0: /* original 0009, guest PC 0x0c0714a0 */
if(!s->budget--) { s->failed_pc=0x0c0714a0u; return 0; }
if(!vf3_matrix_family(0x0c0714a2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0714a2u; return 0; } return 1;
P_0c0714a8: /* original f049, guest PC 0x0c0714a8 */
if(!s->budget--) { s->failed_pc=0x0c0714a8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0714aa;
P_0c0714aa: /* original f149, guest PC 0x0c0714aa */
if(!s->budget--) { s->failed_pc=0x0c0714aau; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0714ac;
P_0c0714ac: /* original f249, guest PC 0x0c0714ac */
if(!s->budget--) { s->failed_pc=0x0c0714acu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0714ae;
P_0c0714ae: /* original f38d, guest PC 0x0c0714ae */
if(!s->budget--) { s->failed_pc=0x0c0714aeu; return 0; }
fr[3]=0;
goto P_0c0714b0;
P_0c0714b0: /* original f459, guest PC 0x0c0714b0 */
if(!s->budget--) { s->failed_pc=0x0c0714b0u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0714b2;
P_0c0714b2: /* original f559, guest PC 0x0c0714b2 */
if(!s->budget--) { s->failed_pc=0x0c0714b2u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0714b4;
P_0c0714b4: /* original f659, guest PC 0x0c0714b4 */
if(!s->budget--) { s->failed_pc=0x0c0714b4u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0714b6;
P_0c0714b6: /* original f78d, guest PC 0x0c0714b6 */
if(!s->budget--) { s->failed_pc=0x0c0714b6u; return 0; }
fr[7]=0;
goto P_0c0714b8;
P_0c0714b8: /* original f4ed, guest PC 0x0c0714b8 */
if(!s->budget--) { s->failed_pc=0x0c0714b8u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c0714ba;
P_0c0714ba: /* original f07c, guest PC 0x0c0714ba */
if(!s->budget--) { s->failed_pc=0x0c0714bau; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c0714bc;
P_0c0714bc: /* original f38d, guest PC 0x0c0714bc */
if(!s->budget--) { s->failed_pc=0x0c0714bcu; return 0; }
fr[3]=0;
goto P_0c0714be;
P_0c0714be: /* original f40c, guest PC 0x0c0714be */
if(!s->budget--) { s->failed_pc=0x0c0714beu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0714c0;
P_0c0714c0: /* original f345, guest PC 0x0c0714c0 */
if(!s->budget--) { s->failed_pc=0x0c0714c0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0714c2;
P_0c0714c2: /* original 8902, guest PC 0x0c0714c2 */
if(!s->budget--) { s->failed_pc=0x0c0714c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0714ca; }
goto P_0c0714c4;
P_0c0714c4: /* original d307, guest PC 0x0c0714c4 */
if(!s->budget--) { s->failed_pc=0x0c0714c4u; return 0; }
r[3]=read(ram,0x0c0714e4u,4);
goto P_0c0714c6;
P_0c0714c6: /* original 432b, guest PC 0x0c0714c6 */
if(!s->budget--) { s->failed_pc=0x0c0714c6u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c07150eu: goto P_0c07150e;
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
P_0c0714c8: /* original 0009, guest PC 0x0c0714c8 */
if(!s->budget--) { s->failed_pc=0x0c0714c8u; return 0; }
goto P_0c0714ca;
P_0c0714ca: /* original ffd5, guest PC 0x0c0714ca */
if(!s->budget--) { s->failed_pc=0x0c0714cau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[13]))!=0);
goto P_0c0714cc;
P_0c0714cc: /* original 8902, guest PC 0x0c0714cc */
if(!s->budget--) { s->failed_pc=0x0c0714ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0714d4; }
goto P_0c0714ce;
P_0c0714ce: /* original d206, guest PC 0x0c0714ce */
if(!s->budget--) { s->failed_pc=0x0c0714ceu; return 0; }
r[2]=read(ram,0x0c0714e8u,4);
goto P_0c0714d0;
P_0c0714d0: /* original 422b, guest PC 0x0c0714d0 */
if(!s->budget--) { s->failed_pc=0x0c0714d0u; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0715d4u: goto P_0c0715d4;
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
P_0c0714d2: /* original 0009, guest PC 0x0c0714d2 */
if(!s->budget--) { s->failed_pc=0x0c0714d2u; return 0; }
goto P_0c0714d4;
P_0c0714d4: /* original 64f3, guest PC 0x0c0714d4 */
if(!s->budget--) { s->failed_pc=0x0c0714d4u; return 0; }
r[4]=r[15];
goto P_0c0714d6;
P_0c0714d6: /* original 65f3, guest PC 0x0c0714d6 */
if(!s->budget--) { s->failed_pc=0x0c0714d6u; return 0; }
r[5]=r[15];
goto P_0c0714d8;
P_0c0714d8: /* original 741c, guest PC 0x0c0714d8 */
if(!s->budget--) { s->failed_pc=0x0c0714d8u; return 0; }
r[4]+=0x0000001cu;
goto P_0c0714da;
P_0c0714da: /* original f4fc, guest PC 0x0c0714da */
if(!s->budget--) { s->failed_pc=0x0c0714dau; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0714dc;
P_0c0714dc: /* original 751c, guest PC 0x0c0714dc */
if(!s->budget--) { s->failed_pc=0x0c0714dcu; return 0; }
r[5]+=0x0000001cu;
goto P_0c0714de;
P_0c0714de: /* original a005, guest PC 0x0c0714de */
if(!s->budget--) { s->failed_pc=0x0c0714deu; return 0; }
goto P_0c0714ec;
P_0c0714e0: /* original 0009, guest PC 0x0c0714e0 */
if(!s->budget--) { s->failed_pc=0x0c0714e0u; return 0; }
if(!vf3_matrix_family(0x0c0714e2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0714e2u; return 0; } return 1;
P_0c0714ec: /* original f059, guest PC 0x0c0714ec */
if(!s->budget--) { s->failed_pc=0x0c0714ecu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0714ee;
P_0c0714ee: /* original f159, guest PC 0x0c0714ee */
if(!s->budget--) { s->failed_pc=0x0c0714eeu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0714f0;
P_0c0714f0: /* original f259, guest PC 0x0c0714f0 */
if(!s->budget--) { s->failed_pc=0x0c0714f0u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0714f2;
P_0c0714f2: /* original f38d, guest PC 0x0c0714f2 */
if(!s->budget--) { s->failed_pc=0x0c0714f2u; return 0; }
fr[3]=0;
goto P_0c0714f4;
P_0c0714f4: /* original f0ed, guest PC 0x0c0714f4 */
if(!s->budget--) { s->failed_pc=0x0c0714f4u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0714f6;
P_0c0714f6: /* original f37d, guest PC 0x0c0714f6 */
if(!s->budget--) { s->failed_pc=0x0c0714f6u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0714f8;
P_0c0714f8: /* original f342, guest PC 0x0c0714f8 */
if(!s->budget--) { s->failed_pc=0x0c0714f8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0714fa;
P_0c0714fa: /* original 740c, guest PC 0x0c0714fa */
if(!s->budget--) { s->failed_pc=0x0c0714fau; return 0; }
r[4]+=0x0000000cu;
goto P_0c0714fc;
P_0c0714fc: /* original f232, guest PC 0x0c0714fc */
if(!s->budget--) { s->failed_pc=0x0c0714fcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0714fe;
P_0c0714fe: /* original f132, guest PC 0x0c0714fe */
if(!s->budget--) { s->failed_pc=0x0c0714feu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071500;
P_0c071500: /* original f032, guest PC 0x0c071500 */
if(!s->budget--) { s->failed_pc=0x0c071500u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071502;
P_0c071502: /* original f42b, guest PC 0x0c071502 */
if(!s->budget--) { s->failed_pc=0x0c071502u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071504;
P_0c071504: /* original f41b, guest PC 0x0c071504 */
if(!s->budget--) { s->failed_pc=0x0c071504u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071506;
P_0c071506: /* original f40b, guest PC 0x0c071506 */
if(!s->budget--) { s->failed_pc=0x0c071506u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071508;
P_0c071508: /* original d206, guest PC 0x0c071508 */
if(!s->budget--) { s->failed_pc=0x0c071508u; return 0; }
r[2]=read(ram,0x0c071524u,4);
goto P_0c07150a;
P_0c07150a: /* original 422b, guest PC 0x0c07150a */
if(!s->budget--) { s->failed_pc=0x0c07150au; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0715b0u: goto P_0c0715b0;
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
P_0c07150c: /* original 0009, guest PC 0x0c07150c */
if(!s->budget--) { s->failed_pc=0x0c07150cu; return 0; }
goto P_0c07150e;
P_0c07150e: /* original fc45, guest PC 0x0c07150e */
if(!s->budget--) { s->failed_pc=0x0c07150eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[12])>as_float(fr[4]))!=0);
goto P_0c071510;
P_0c071510: /* original 8902, guest PC 0x0c071510 */
if(!s->budget--) { s->failed_pc=0x0c071510u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c071518; }
goto P_0c071512;
P_0c071512: /* original d205, guest PC 0x0c071512 */
if(!s->budget--) { s->failed_pc=0x0c071512u; return 0; }
r[2]=read(ram,0x0c071528u,4);
goto P_0c071514;
P_0c071514: /* original 422b, guest PC 0x0c071514 */
if(!s->budget--) { s->failed_pc=0x0c071514u; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0715d4u: goto P_0c0715d4;
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
P_0c071516: /* original 0009, guest PC 0x0c071516 */
if(!s->budget--) { s->failed_pc=0x0c071516u; return 0; }
goto P_0c071518;
P_0c071518: /* original 64f3, guest PC 0x0c071518 */
if(!s->budget--) { s->failed_pc=0x0c071518u; return 0; }
r[4]=r[15];
goto P_0c07151a;
P_0c07151a: /* original 7410, guest PC 0x0c07151a */
if(!s->budget--) { s->failed_pc=0x0c07151au; return 0; }
r[4]+=0x00000010u;
goto P_0c07151c;
P_0c07151c: /* original 65d3, guest PC 0x0c07151c */
if(!s->budget--) { s->failed_pc=0x0c07151cu; return 0; }
r[5]=r[13];
goto P_0c07151e;
P_0c07151e: /* original a005, guest PC 0x0c07151e */
if(!s->budget--) { s->failed_pc=0x0c07151eu; return 0; }
goto P_0c07152c;
P_0c071520: /* original 0009, guest PC 0x0c071520 */
if(!s->budget--) { s->failed_pc=0x0c071520u; return 0; }
if(!vf3_matrix_family(0x0c071522u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c071522u; return 0; } return 1;
P_0c07152c: /* original f059, guest PC 0x0c07152c */
if(!s->budget--) { s->failed_pc=0x0c07152cu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07152e;
P_0c07152e: /* original f159, guest PC 0x0c07152e */
if(!s->budget--) { s->failed_pc=0x0c07152eu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071530;
P_0c071530: /* original f259, guest PC 0x0c071530 */
if(!s->budget--) { s->failed_pc=0x0c071530u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071532;
P_0c071532: /* original 740c, guest PC 0x0c071532 */
if(!s->budget--) { s->failed_pc=0x0c071532u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071534;
P_0c071534: /* original f242, guest PC 0x0c071534 */
if(!s->budget--) { s->failed_pc=0x0c071534u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c071536;
P_0c071536: /* original f142, guest PC 0x0c071536 */
if(!s->budget--) { s->failed_pc=0x0c071536u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c071538;
P_0c071538: /* original f042, guest PC 0x0c071538 */
if(!s->budget--) { s->failed_pc=0x0c071538u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c07153a;
P_0c07153a: /* original f42b, guest PC 0x0c07153a */
if(!s->budget--) { s->failed_pc=0x0c07153au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07153c;
P_0c07153c: /* original f41b, guest PC 0x0c07153c */
if(!s->budget--) { s->failed_pc=0x0c07153cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07153e;
P_0c07153e: /* original f40b, guest PC 0x0c07153e */
if(!s->budget--) { s->failed_pc=0x0c07153eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071540;
P_0c071540: /* original 65f3, guest PC 0x0c071540 */
if(!s->budget--) { s->failed_pc=0x0c071540u; return 0; }
r[5]=r[15];
goto P_0c071542;
P_0c071542: /* original 64f3, guest PC 0x0c071542 */
if(!s->budget--) { s->failed_pc=0x0c071542u; return 0; }
r[4]=r[15];
goto P_0c071544;
P_0c071544: /* original 66f3, guest PC 0x0c071544 */
if(!s->budget--) { s->failed_pc=0x0c071544u; return 0; }
r[6]=r[15];
goto P_0c071546;
P_0c071546: /* original 7410, guest PC 0x0c071546 */
if(!s->budget--) { s->failed_pc=0x0c071546u; return 0; }
r[4]+=0x00000010u;
goto P_0c071548;
P_0c071548: /* original 7610, guest PC 0x0c071548 */
if(!s->budget--) { s->failed_pc=0x0c071548u; return 0; }
r[6]+=0x00000010u;
goto P_0c07154a;
P_0c07154a: /* original 751c, guest PC 0x0c07154a */
if(!s->budget--) { s->failed_pc=0x0c07154au; return 0; }
r[5]+=0x0000001cu;
goto P_0c07154c;
P_0c07154c: /* original f059, guest PC 0x0c07154c */
if(!s->budget--) { s->failed_pc=0x0c07154cu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07154e;
P_0c07154e: /* original f369, guest PC 0x0c07154e */
if(!s->budget--) { s->failed_pc=0x0c07154eu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071550;
P_0c071550: /* original f159, guest PC 0x0c071550 */
if(!s->budget--) { s->failed_pc=0x0c071550u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071552;
P_0c071552: /* original f469, guest PC 0x0c071552 */
if(!s->budget--) { s->failed_pc=0x0c071552u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071554;
P_0c071554: /* original f031, guest PC 0x0c071554 */
if(!s->budget--) { s->failed_pc=0x0c071554u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071556;
P_0c071556: /* original f258, guest PC 0x0c071556 */
if(!s->budget--) { s->failed_pc=0x0c071556u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071558;
P_0c071558: /* original f568, guest PC 0x0c071558 */
if(!s->budget--) { s->failed_pc=0x0c071558u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c07155a;
P_0c07155a: /* original f141, guest PC 0x0c07155a */
if(!s->budget--) { s->failed_pc=0x0c07155au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c07155c;
P_0c07155c: /* original f251, guest PC 0x0c07155c */
if(!s->budget--) { s->failed_pc=0x0c07155cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c07155e;
P_0c07155e: /* original 7408, guest PC 0x0c07155e */
if(!s->budget--) { s->failed_pc=0x0c07155eu; return 0; }
r[4]+=0x00000008u;
goto P_0c071560;
P_0c071560: /* original f42a, guest PC 0x0c071560 */
if(!s->budget--) { s->failed_pc=0x0c071560u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071562;
P_0c071562: /* original f41b, guest PC 0x0c071562 */
if(!s->budget--) { s->failed_pc=0x0c071562u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071564;
P_0c071564: /* original f40b, guest PC 0x0c071564 */
if(!s->budget--) { s->failed_pc=0x0c071564u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071566;
P_0c071566: /* original 0009, guest PC 0x0c071566 */
if(!s->budget--) { s->failed_pc=0x0c071566u; return 0; }
goto P_0c071568;
P_0c071568: /* original f4fc, guest PC 0x0c071568 */
if(!s->budget--) { s->failed_pc=0x0c071568u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c07156a;
P_0c07156a: /* original f4e1, guest PC 0x0c07156a */
if(!s->budget--) { s->failed_pc=0x0c07156au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'-');
goto P_0c07156c;
P_0c07156c: /* original 64f3, guest PC 0x0c07156c */
if(!s->budget--) { s->failed_pc=0x0c07156cu; return 0; }
r[4]=r[15];
goto P_0c07156e;
P_0c07156e: /* original 65f3, guest PC 0x0c07156e */
if(!s->budget--) { s->failed_pc=0x0c07156eu; return 0; }
r[5]=r[15];
goto P_0c071570;
P_0c071570: /* original 7410, guest PC 0x0c071570 */
if(!s->budget--) { s->failed_pc=0x0c071570u; return 0; }
r[4]+=0x00000010u;
goto P_0c071572;
P_0c071572: /* original 7510, guest PC 0x0c071572 */
if(!s->budget--) { s->failed_pc=0x0c071572u; return 0; }
r[5]+=0x00000010u;
goto P_0c071574;
P_0c071574: /* original f059, guest PC 0x0c071574 */
if(!s->budget--) { s->failed_pc=0x0c071574u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071576;
P_0c071576: /* original f159, guest PC 0x0c071576 */
if(!s->budget--) { s->failed_pc=0x0c071576u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071578;
P_0c071578: /* original f259, guest PC 0x0c071578 */
if(!s->budget--) { s->failed_pc=0x0c071578u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07157a;
P_0c07157a: /* original f38d, guest PC 0x0c07157a */
if(!s->budget--) { s->failed_pc=0x0c07157au; return 0; }
fr[3]=0;
goto P_0c07157c;
P_0c07157c: /* original f0ed, guest PC 0x0c07157c */
if(!s->budget--) { s->failed_pc=0x0c07157cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07157e;
P_0c07157e: /* original f37d, guest PC 0x0c07157e */
if(!s->budget--) { s->failed_pc=0x0c07157eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071580;
P_0c071580: /* original f342, guest PC 0x0c071580 */
if(!s->budget--) { s->failed_pc=0x0c071580u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c071582;
P_0c071582: /* original 740c, guest PC 0x0c071582 */
if(!s->budget--) { s->failed_pc=0x0c071582u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071584;
P_0c071584: /* original f232, guest PC 0x0c071584 */
if(!s->budget--) { s->failed_pc=0x0c071584u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071586;
P_0c071586: /* original f132, guest PC 0x0c071586 */
if(!s->budget--) { s->failed_pc=0x0c071586u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071588;
P_0c071588: /* original f032, guest PC 0x0c071588 */
if(!s->budget--) { s->failed_pc=0x0c071588u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c07158a;
P_0c07158a: /* original f42b, guest PC 0x0c07158a */
if(!s->budget--) { s->failed_pc=0x0c07158au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07158c;
P_0c07158c: /* original f41b, guest PC 0x0c07158c */
if(!s->budget--) { s->failed_pc=0x0c07158cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07158e;
P_0c07158e: /* original f40b, guest PC 0x0c07158e */
if(!s->budget--) { s->failed_pc=0x0c07158eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071590;
P_0c071590: /* original 64f3, guest PC 0x0c071590 */
if(!s->budget--) { s->failed_pc=0x0c071590u; return 0; }
r[4]=r[15];
goto P_0c071592;
P_0c071592: /* original 65f3, guest PC 0x0c071592 */
if(!s->budget--) { s->failed_pc=0x0c071592u; return 0; }
r[5]=r[15];
goto P_0c071594;
P_0c071594: /* original 741c, guest PC 0x0c071594 */
if(!s->budget--) { s->failed_pc=0x0c071594u; return 0; }
r[4]+=0x0000001cu;
goto P_0c071596;
P_0c071596: /* original 7510, guest PC 0x0c071596 */
if(!s->budget--) { s->failed_pc=0x0c071596u; return 0; }
r[5]+=0x00000010u;
goto P_0c071598;
P_0c071598: /* original f049, guest PC 0x0c071598 */
if(!s->budget--) { s->failed_pc=0x0c071598u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07159a;
P_0c07159a: /* original f359, guest PC 0x0c07159a */
if(!s->budget--) { s->failed_pc=0x0c07159au; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07159c;
P_0c07159c: /* original f149, guest PC 0x0c07159c */
if(!s->budget--) { s->failed_pc=0x0c07159cu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07159e;
P_0c07159e: /* original f459, guest PC 0x0c07159e */
if(!s->budget--) { s->failed_pc=0x0c07159eu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0715a0;
P_0c0715a0: /* original f249, guest PC 0x0c0715a0 */
if(!s->budget--) { s->failed_pc=0x0c0715a0u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0715a2;
P_0c0715a2: /* original f559, guest PC 0x0c0715a2 */
if(!s->budget--) { s->failed_pc=0x0c0715a2u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0715a4;
P_0c0715a4: /* original f030, guest PC 0x0c0715a4 */
if(!s->budget--) { s->failed_pc=0x0c0715a4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c0715a6;
P_0c0715a6: /* original f250, guest PC 0x0c0715a6 */
if(!s->budget--) { s->failed_pc=0x0c0715a6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c0715a8;
P_0c0715a8: /* original f140, guest PC 0x0c0715a8 */
if(!s->budget--) { s->failed_pc=0x0c0715a8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c0715aa;
P_0c0715aa: /* original f42b, guest PC 0x0c0715aa */
if(!s->budget--) { s->failed_pc=0x0c0715aau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0715ac;
P_0c0715ac: /* original f41b, guest PC 0x0c0715ac */
if(!s->budget--) { s->failed_pc=0x0c0715acu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0715ae;
P_0c0715ae: /* original f40b, guest PC 0x0c0715ae */
if(!s->budget--) { s->failed_pc=0x0c0715aeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0715b0;
P_0c0715b0: /* original 65f3, guest PC 0x0c0715b0 */
if(!s->budget--) { s->failed_pc=0x0c0715b0u; return 0; }
r[5]=r[15];
goto P_0c0715b2;
P_0c0715b2: /* original 64e3, guest PC 0x0c0715b2 */
if(!s->budget--) { s->failed_pc=0x0c0715b2u; return 0; }
r[4]=r[14];
goto P_0c0715b4;
P_0c0715b4: /* original 751c, guest PC 0x0c0715b4 */
if(!s->budget--) { s->failed_pc=0x0c0715b4u; return 0; }
r[5]+=0x0000001cu;
goto P_0c0715b6;
P_0c0715b6: /* original 66b3, guest PC 0x0c0715b6 */
if(!s->budget--) { s->failed_pc=0x0c0715b6u; return 0; }
r[6]=r[11];
goto P_0c0715b8;
P_0c0715b8: /* original f059, guest PC 0x0c0715b8 */
if(!s->budget--) { s->failed_pc=0x0c0715b8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0715ba;
P_0c0715ba: /* original f369, guest PC 0x0c0715ba */
if(!s->budget--) { s->failed_pc=0x0c0715bau; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0715bc;
P_0c0715bc: /* original f159, guest PC 0x0c0715bc */
if(!s->budget--) { s->failed_pc=0x0c0715bcu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0715be;
P_0c0715be: /* original f469, guest PC 0x0c0715be */
if(!s->budget--) { s->failed_pc=0x0c0715beu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0715c0;
P_0c0715c0: /* original f259, guest PC 0x0c0715c0 */
if(!s->budget--) { s->failed_pc=0x0c0715c0u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0715c2;
P_0c0715c2: /* original f569, guest PC 0x0c0715c2 */
if(!s->budget--) { s->failed_pc=0x0c0715c2u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0715c4;
P_0c0715c4: /* original 740c, guest PC 0x0c0715c4 */
if(!s->budget--) { s->failed_pc=0x0c0715c4u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0715c6;
P_0c0715c6: /* original f030, guest PC 0x0c0715c6 */
if(!s->budget--) { s->failed_pc=0x0c0715c6u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c0715c8;
P_0c0715c8: /* original f250, guest PC 0x0c0715c8 */
if(!s->budget--) { s->failed_pc=0x0c0715c8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c0715ca;
P_0c0715ca: /* original f140, guest PC 0x0c0715ca */
if(!s->budget--) { s->failed_pc=0x0c0715cau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c0715cc;
P_0c0715cc: /* original f42b, guest PC 0x0c0715cc */
if(!s->budget--) { s->failed_pc=0x0c0715ccu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0715ce;
P_0c0715ce: /* original f41b, guest PC 0x0c0715ce */
if(!s->budget--) { s->failed_pc=0x0c0715ceu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0715d0;
P_0c0715d0: /* original f40b, guest PC 0x0c0715d0 */
if(!s->budget--) { s->failed_pc=0x0c0715d0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0715d2;
P_0c0715d2: /* original 0009, guest PC 0x0c0715d2 */
if(!s->budget--) { s->failed_pc=0x0c0715d2u; return 0; }
goto P_0c0715d4;
P_0c0715d4: /* original 64f3, guest PC 0x0c0715d4 */
if(!s->budget--) { s->failed_pc=0x0c0715d4u; return 0; }
r[4]=r[15];
goto P_0c0715d6;
P_0c0715d6: /* original 7404, guest PC 0x0c0715d6 */
if(!s->budget--) { s->failed_pc=0x0c0715d6u; return 0; }
r[4]+=0x00000004u;
goto P_0c0715d8;
P_0c0715d8: /* original 66c3, guest PC 0x0c0715d8 */
if(!s->budget--) { s->failed_pc=0x0c0715d8u; return 0; }
r[6]=r[12];
goto P_0c0715da;
P_0c0715da: /* original 65e3, guest PC 0x0c0715da */
if(!s->budget--) { s->failed_pc=0x0c0715dau; return 0; }
r[5]=r[14];
goto P_0c0715dc;
P_0c0715dc: /* original f059, guest PC 0x0c0715dc */
if(!s->budget--) { s->failed_pc=0x0c0715dcu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0715de;
P_0c0715de: /* original f369, guest PC 0x0c0715de */
if(!s->budget--) { s->failed_pc=0x0c0715deu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0715e0;
P_0c0715e0: /* original f159, guest PC 0x0c0715e0 */
if(!s->budget--) { s->failed_pc=0x0c0715e0u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0715e2;
P_0c0715e2: /* original f469, guest PC 0x0c0715e2 */
if(!s->budget--) { s->failed_pc=0x0c0715e2u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0715e4;
P_0c0715e4: /* original f031, guest PC 0x0c0715e4 */
if(!s->budget--) { s->failed_pc=0x0c0715e4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0715e6;
P_0c0715e6: /* original f258, guest PC 0x0c0715e6 */
if(!s->budget--) { s->failed_pc=0x0c0715e6u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0715e8;
P_0c0715e8: /* original f568, guest PC 0x0c0715e8 */
if(!s->budget--) { s->failed_pc=0x0c0715e8u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0715ea;
P_0c0715ea: /* original f141, guest PC 0x0c0715ea */
if(!s->budget--) { s->failed_pc=0x0c0715eau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0715ec;
P_0c0715ec: /* original f251, guest PC 0x0c0715ec */
if(!s->budget--) { s->failed_pc=0x0c0715ecu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0715ee;
P_0c0715ee: /* original 7408, guest PC 0x0c0715ee */
if(!s->budget--) { s->failed_pc=0x0c0715eeu; return 0; }
r[4]+=0x00000008u;
goto P_0c0715f0;
P_0c0715f0: /* original f42a, guest PC 0x0c0715f0 */
if(!s->budget--) { s->failed_pc=0x0c0715f0u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0715f2;
P_0c0715f2: /* original f41b, guest PC 0x0c0715f2 */
if(!s->budget--) { s->failed_pc=0x0c0715f2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0715f4;
P_0c0715f4: /* original f40b, guest PC 0x0c0715f4 */
if(!s->budget--) { s->failed_pc=0x0c0715f4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0715f6;
P_0c0715f6: /* original 0009, guest PC 0x0c0715f6 */
if(!s->budget--) { s->failed_pc=0x0c0715f6u; return 0; }
goto P_0c0715f8;
P_0c0715f8: /* original 64f3, guest PC 0x0c0715f8 */
if(!s->budget--) { s->failed_pc=0x0c0715f8u; return 0; }
r[4]=r[15];
goto P_0c0715fa;
P_0c0715fa: /* original 7404, guest PC 0x0c0715fa */
if(!s->budget--) { s->failed_pc=0x0c0715fau; return 0; }
r[4]+=0x00000004u;
goto P_0c0715fc;
P_0c0715fc: /* original f049, guest PC 0x0c0715fc */
if(!s->budget--) { s->failed_pc=0x0c0715fcu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0715fe;
P_0c0715fe: /* original f149, guest PC 0x0c0715fe */
if(!s->budget--) { s->failed_pc=0x0c0715feu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071600;
P_0c071600: /* original f249, guest PC 0x0c071600 */
if(!s->budget--) { s->failed_pc=0x0c071600u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071602;
P_0c071602: /* original f38d, guest PC 0x0c071602 */
if(!s->budget--) { s->failed_pc=0x0c071602u; return 0; }
fr[3]=0;
goto P_0c071604;
P_0c071604: /* original f0ed, guest PC 0x0c071604 */
if(!s->budget--) { s->failed_pc=0x0c071604u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071606;
P_0c071606: /* original f03c, guest PC 0x0c071606 */
if(!s->budget--) { s->failed_pc=0x0c071606u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c071608;
P_0c071608: /* original f06d, guest PC 0x0c071608 */
if(!s->budget--) { s->failed_pc=0x0c071608u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c07160a;
P_0c07160a: /* original 0009, guest PC 0x0c07160a */
if(!s->budget--) { s->failed_pc=0x0c07160au; return 0; }
goto P_0c07160c;
P_0c07160c: /* original f38d, guest PC 0x0c07160c */
if(!s->budget--) { s->failed_pc=0x0c07160cu; return 0; }
fr[3]=0;
goto P_0c07160e;
P_0c07160e: /* original f035, guest PC 0x0c07160e */
if(!s->budget--) { s->failed_pc=0x0c07160eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c071610;
P_0c071610: /* original 8902, guest PC 0x0c071610 */
if(!s->budget--) { s->failed_pc=0x0c071610u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c071618; }
goto P_0c071612;
P_0c071612: /* original d305, guest PC 0x0c071612 */
if(!s->budget--) { s->failed_pc=0x0c071612u; return 0; }
r[3]=read(ram,0x0c071628u,4);
goto P_0c071614;
P_0c071614: /* original 432b, guest PC 0x0c071614 */
if(!s->budget--) { s->failed_pc=0x0c071614u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c07166cu: goto P_0c07166c;
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
P_0c071616: /* original 0009, guest PC 0x0c071616 */
if(!s->budget--) { s->failed_pc=0x0c071616u; return 0; }
goto P_0c071618;
P_0c071618: /* original 64f3, guest PC 0x0c071618 */
if(!s->budget--) { s->failed_pc=0x0c071618u; return 0; }
r[4]=r[15];
goto P_0c07161a;
P_0c07161a: /* original 65f3, guest PC 0x0c07161a */
if(!s->budget--) { s->failed_pc=0x0c07161au; return 0; }
r[5]=r[15];
goto P_0c07161c;
P_0c07161c: /* original f4f8, guest PC 0x0c07161c */
if(!s->budget--) { s->failed_pc=0x0c07161cu; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c07161e;
P_0c07161e: /* original 7404, guest PC 0x0c07161e */
if(!s->budget--) { s->failed_pc=0x0c07161eu; return 0; }
r[4]+=0x00000004u;
goto P_0c071620;
P_0c071620: /* original 7504, guest PC 0x0c071620 */
if(!s->budget--) { s->failed_pc=0x0c071620u; return 0; }
r[5]+=0x00000004u;
goto P_0c071622;
P_0c071622: /* original a003, guest PC 0x0c071622 */
if(!s->budget--) { s->failed_pc=0x0c071622u; return 0; }
goto P_0c07162c;
P_0c071624: /* original 0009, guest PC 0x0c071624 */
if(!s->budget--) { s->failed_pc=0x0c071624u; return 0; }
if(!vf3_matrix_family(0x0c071626u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c071626u; return 0; } return 1;
P_0c07162c: /* original f059, guest PC 0x0c07162c */
if(!s->budget--) { s->failed_pc=0x0c07162cu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07162e;
P_0c07162e: /* original f159, guest PC 0x0c07162e */
if(!s->budget--) { s->failed_pc=0x0c07162eu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071630;
P_0c071630: /* original f259, guest PC 0x0c071630 */
if(!s->budget--) { s->failed_pc=0x0c071630u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071632;
P_0c071632: /* original f38d, guest PC 0x0c071632 */
if(!s->budget--) { s->failed_pc=0x0c071632u; return 0; }
fr[3]=0;
goto P_0c071634;
P_0c071634: /* original f0ed, guest PC 0x0c071634 */
if(!s->budget--) { s->failed_pc=0x0c071634u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071636;
P_0c071636: /* original f37d, guest PC 0x0c071636 */
if(!s->budget--) { s->failed_pc=0x0c071636u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071638;
P_0c071638: /* original f342, guest PC 0x0c071638 */
if(!s->budget--) { s->failed_pc=0x0c071638u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c07163a;
P_0c07163a: /* original 740c, guest PC 0x0c07163a */
if(!s->budget--) { s->failed_pc=0x0c07163au; return 0; }
r[4]+=0x0000000cu;
goto P_0c07163c;
P_0c07163c: /* original f232, guest PC 0x0c07163c */
if(!s->budget--) { s->failed_pc=0x0c07163cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07163e;
P_0c07163e: /* original f132, guest PC 0x0c07163e */
if(!s->budget--) { s->failed_pc=0x0c07163eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071640;
P_0c071640: /* original f032, guest PC 0x0c071640 */
if(!s->budget--) { s->failed_pc=0x0c071640u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071642;
P_0c071642: /* original f42b, guest PC 0x0c071642 */
if(!s->budget--) { s->failed_pc=0x0c071642u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071644;
P_0c071644: /* original f41b, guest PC 0x0c071644 */
if(!s->budget--) { s->failed_pc=0x0c071644u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071646;
P_0c071646: /* original f40b, guest PC 0x0c071646 */
if(!s->budget--) { s->failed_pc=0x0c071646u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071648;
P_0c071648: /* original 66f3, guest PC 0x0c071648 */
if(!s->budget--) { s->failed_pc=0x0c071648u; return 0; }
r[6]=r[15];
goto P_0c07164a;
P_0c07164a: /* original 64e3, guest PC 0x0c07164a */
if(!s->budget--) { s->failed_pc=0x0c07164au; return 0; }
r[4]=r[14];
goto P_0c07164c;
P_0c07164c: /* original 65c3, guest PC 0x0c07164c */
if(!s->budget--) { s->failed_pc=0x0c07164cu; return 0; }
r[5]=r[12];
goto P_0c07164e;
P_0c07164e: /* original 7604, guest PC 0x0c07164e */
if(!s->budget--) { s->failed_pc=0x0c07164eu; return 0; }
r[6]+=0x00000004u;
goto P_0c071650;
P_0c071650: /* original f059, guest PC 0x0c071650 */
if(!s->budget--) { s->failed_pc=0x0c071650u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071652;
P_0c071652: /* original f369, guest PC 0x0c071652 */
if(!s->budget--) { s->failed_pc=0x0c071652u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071654;
P_0c071654: /* original f159, guest PC 0x0c071654 */
if(!s->budget--) { s->failed_pc=0x0c071654u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071656;
P_0c071656: /* original f469, guest PC 0x0c071656 */
if(!s->budget--) { s->failed_pc=0x0c071656u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071658;
P_0c071658: /* original f259, guest PC 0x0c071658 */
if(!s->budget--) { s->failed_pc=0x0c071658u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07165a;
P_0c07165a: /* original f569, guest PC 0x0c07165a */
if(!s->budget--) { s->failed_pc=0x0c07165au; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07165c;
P_0c07165c: /* original 740c, guest PC 0x0c07165c */
if(!s->budget--) { s->failed_pc=0x0c07165cu; return 0; }
r[4]+=0x0000000cu;
goto P_0c07165e;
P_0c07165e: /* original f030, guest PC 0x0c07165e */
if(!s->budget--) { s->failed_pc=0x0c07165eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c071660;
P_0c071660: /* original f250, guest PC 0x0c071660 */
if(!s->budget--) { s->failed_pc=0x0c071660u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c071662;
P_0c071662: /* original f140, guest PC 0x0c071662 */
if(!s->budget--) { s->failed_pc=0x0c071662u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071664;
P_0c071664: /* original f42b, guest PC 0x0c071664 */
if(!s->budget--) { s->failed_pc=0x0c071664u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071666;
P_0c071666: /* original f41b, guest PC 0x0c071666 */
if(!s->budget--) { s->failed_pc=0x0c071666u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071668;
P_0c071668: /* original f40b, guest PC 0x0c071668 */
if(!s->budget--) { s->failed_pc=0x0c071668u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07166a;
P_0c07166a: /* original 0009, guest PC 0x0c07166a */
if(!s->budget--) { s->failed_pc=0x0c07166au; return 0; }
goto P_0c07166c;
P_0c07166c: /* original 79ff, guest PC 0x0c07166c */
if(!s->budget--) { s->failed_pc=0x0c07166cu; return 0; }
r[9]+=0xffffffffu;
goto P_0c07166e;
P_0c07166e: /* original 39a7, guest PC 0x0c07166e */
if(!s->budget--) { s->failed_pc=0x0c07166eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>(int32_t)r[10])!=0);
goto P_0c071670;
P_0c071670: /* original 7c18, guest PC 0x0c071670 */
if(!s->budget--) { s->failed_pc=0x0c071670u; return 0; }
r[12]+=0x00000018u;
goto P_0c071672;
P_0c071672: /* original 8f03, guest PC 0x0c071672 */
if(!s->budget--) { s->failed_pc=0x0c071672u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000018u;
if(!cond) { goto P_0c07167c; }
goto P_0c071676;
P_0c071674: /* original 7e18, guest PC 0x0c071674 */
if(!s->budget--) { s->failed_pc=0x0c071674u; return 0; }
r[14]+=0x00000018u;
goto P_0c071676;
P_0c071676: /* original d321, guest PC 0x0c071676 */
if(!s->budget--) { s->failed_pc=0x0c071676u; return 0; }
r[3]=read(ram,0x0c0716fcu,4);
goto P_0c071678;
P_0c071678: /* original 432b, guest PC 0x0c071678 */
if(!s->budget--) { s->failed_pc=0x0c071678u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c071400u: goto P_0c071400;
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
P_0c07167a: /* original 0009, guest PC 0x0c07167a */
if(!s->budget--) { s->failed_pc=0x0c07167au; return 0; }
goto P_0c07167c;
P_0c07167c: /* original 7f34, guest PC 0x0c07167c */
if(!s->budget--) { s->failed_pc=0x0c07167cu; return 0; }
r[15]+=0x00000034u;
goto P_0c07167e;
P_0c07167e: /* original fcf9, guest PC 0x0c07167e */
if(!s->budget--) { s->failed_pc=0x0c07167eu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c071680;
P_0c071680: /* original fdf9, guest PC 0x0c071680 */
if(!s->budget--) { s->failed_pc=0x0c071680u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c071682;
P_0c071682: /* original fef9, guest PC 0x0c071682 */
if(!s->budget--) { s->failed_pc=0x0c071682u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c071684;
P_0c071684: /* original fff9, guest PC 0x0c071684 */
if(!s->budget--) { s->failed_pc=0x0c071684u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c071686;
P_0c071686: /* original 69f6, guest PC 0x0c071686 */
if(!s->budget--) { s->failed_pc=0x0c071686u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c071688;
P_0c071688: /* original 6af6, guest PC 0x0c071688 */
if(!s->budget--) { s->failed_pc=0x0c071688u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07168a;
P_0c07168a: /* original 6bf6, guest PC 0x0c07168a */
if(!s->budget--) { s->failed_pc=0x0c07168au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07168c;
P_0c07168c: /* original 6cf6, guest PC 0x0c07168c */
if(!s->budget--) { s->failed_pc=0x0c07168cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07168e;
P_0c07168e: /* original 6df6, guest PC 0x0c07168e */
if(!s->budget--) { s->failed_pc=0x0c07168eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c071690;
P_0c071690: /* original 000b, guest PC 0x0c071690 */
if(!s->budget--) { s->failed_pc=0x0c071690u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c071692: /* original 6ef6, guest PC 0x0c071692 */
if(!s->budget--) { s->failed_pc=0x0c071692u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c071694u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
