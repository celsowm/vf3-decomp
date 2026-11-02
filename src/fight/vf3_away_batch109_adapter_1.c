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
int vf3_away_batch109_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c093266u: goto P_0c093266;
case 0x0c093268u: goto P_0c093268;
case 0x0c09326au: goto P_0c09326a;
case 0x0c09326cu: goto P_0c09326c;
case 0x0c09326eu: goto P_0c09326e;
case 0x0c093270u: goto P_0c093270;
case 0x0c093272u: goto P_0c093272;
case 0x0c093274u: goto P_0c093274;
case 0x0c093276u: goto P_0c093276;
case 0x0c093278u: goto P_0c093278;
case 0x0c09327au: goto P_0c09327a;
case 0x0c09327cu: goto P_0c09327c;
case 0x0c09327eu: goto P_0c09327e;
case 0x0c093280u: goto P_0c093280;
case 0x0c093282u: goto P_0c093282;
case 0x0c093284u: goto P_0c093284;
case 0x0c093286u: goto P_0c093286;
case 0x0c093288u: goto P_0c093288;
case 0x0c09328au: goto P_0c09328a;
case 0x0c09328cu: goto P_0c09328c;
case 0x0c09328eu: goto P_0c09328e;
case 0x0c093290u: goto P_0c093290;
case 0x0c093292u: goto P_0c093292;
case 0x0c093294u: goto P_0c093294;
case 0x0c093296u: goto P_0c093296;
case 0x0c093298u: goto P_0c093298;
case 0x0c09329au: goto P_0c09329a;
case 0x0c09329cu: goto P_0c09329c;
case 0x0c09329eu: goto P_0c09329e;
case 0x0c0932a0u: goto P_0c0932a0;
case 0x0c0932a2u: goto P_0c0932a2;
case 0x0c0932a4u: goto P_0c0932a4;
case 0x0c0932a6u: goto P_0c0932a6;
case 0x0c0932a8u: goto P_0c0932a8;
case 0x0c0932c8u: goto P_0c0932c8;
case 0x0c0932cau: goto P_0c0932ca;
case 0x0c0932ccu: goto P_0c0932cc;
case 0x0c0932ceu: goto P_0c0932ce;
case 0x0c0932d0u: goto P_0c0932d0;
case 0x0c0932d2u: goto P_0c0932d2;
case 0x0c0932d4u: goto P_0c0932d4;
case 0x0c0932d6u: goto P_0c0932d6;
case 0x0c0932d8u: goto P_0c0932d8;
case 0x0c0932dau: goto P_0c0932da;
case 0x0c0932dcu: goto P_0c0932dc;
case 0x0c0932deu: goto P_0c0932de;
case 0x0c0932e0u: goto P_0c0932e0;
case 0x0c0932e2u: goto P_0c0932e2;
case 0x0c0932e4u: goto P_0c0932e4;
case 0x0c0932e6u: goto P_0c0932e6;
case 0x0c0932e8u: goto P_0c0932e8;
case 0x0c0932eau: goto P_0c0932ea;
case 0x0c0932ecu: goto P_0c0932ec;
case 0x0c0932eeu: goto P_0c0932ee;
case 0x0c0932f0u: goto P_0c0932f0;
case 0x0c0932f2u: goto P_0c0932f2;
case 0x0c0932f4u: goto P_0c0932f4;
case 0x0c0932f6u: goto P_0c0932f6;
case 0x0c0932f8u: goto P_0c0932f8;
case 0x0c0932fau: goto P_0c0932fa;
case 0x0c0932fcu: goto P_0c0932fc;
case 0x0c0932feu: goto P_0c0932fe;
case 0x0c093300u: goto P_0c093300;
case 0x0c093302u: goto P_0c093302;
case 0x0c093304u: goto P_0c093304;
case 0x0c093306u: goto P_0c093306;
case 0x0c093308u: goto P_0c093308;
case 0x0c09330au: goto P_0c09330a;
case 0x0c09330cu: goto P_0c09330c;
case 0x0c09330eu: goto P_0c09330e;
case 0x0c093310u: goto P_0c093310;
case 0x0c093312u: goto P_0c093312;
case 0x0c093314u: goto P_0c093314;
case 0x0c093316u: goto P_0c093316;
case 0x0c093318u: goto P_0c093318;
case 0x0c09331au: goto P_0c09331a;
case 0x0c09331cu: goto P_0c09331c;
case 0x0c09331eu: goto P_0c09331e;
case 0x0c093320u: goto P_0c093320;
case 0x0c093322u: goto P_0c093322;
case 0x0c093324u: goto P_0c093324;
case 0x0c093326u: goto P_0c093326;
case 0x0c093328u: goto P_0c093328;
case 0x0c09332au: goto P_0c09332a;
case 0x0c09332cu: goto P_0c09332c;
case 0x0c09332eu: goto P_0c09332e;
case 0x0c093330u: goto P_0c093330;
case 0x0c093332u: goto P_0c093332;
case 0x0c093334u: goto P_0c093334;
case 0x0c093336u: goto P_0c093336;
case 0x0c093338u: goto P_0c093338;
case 0x0c09333au: goto P_0c09333a;
case 0x0c09333cu: goto P_0c09333c;
case 0x0c09333eu: goto P_0c09333e;
case 0x0c093340u: goto P_0c093340;
case 0x0c093342u: goto P_0c093342;
case 0x0c093344u: goto P_0c093344;
case 0x0c093346u: goto P_0c093346;
case 0x0c093348u: goto P_0c093348;
case 0x0c09334au: goto P_0c09334a;
case 0x0c09334cu: goto P_0c09334c;
case 0x0c09334eu: goto P_0c09334e;
case 0x0c093350u: goto P_0c093350;
case 0x0c093352u: goto P_0c093352;
case 0x0c093354u: goto P_0c093354;
case 0x0c093356u: goto P_0c093356;
case 0x0c093358u: goto P_0c093358;
case 0x0c09335au: goto P_0c09335a;
case 0x0c09335cu: goto P_0c09335c;
case 0x0c09335eu: goto P_0c09335e;
case 0x0c093360u: goto P_0c093360;
case 0x0c093362u: goto P_0c093362;
case 0x0c093364u: goto P_0c093364;
case 0x0c093366u: goto P_0c093366;
case 0x0c093368u: goto P_0c093368;
case 0x0c093378u: goto P_0c093378;
case 0x0c09337au: goto P_0c09337a;
case 0x0c09337cu: goto P_0c09337c;
case 0x0c09337eu: goto P_0c09337e;
case 0x0c093380u: goto P_0c093380;
case 0x0c093382u: goto P_0c093382;
case 0x0c093384u: goto P_0c093384;
case 0x0c093386u: goto P_0c093386;
case 0x0c093388u: goto P_0c093388;
case 0x0c09338au: goto P_0c09338a;
case 0x0c09338cu: goto P_0c09338c;
case 0x0c09338eu: goto P_0c09338e;
case 0x0c093390u: goto P_0c093390;
case 0x0c093392u: goto P_0c093392;
case 0x0c093394u: goto P_0c093394;
case 0x0c093396u: goto P_0c093396;
case 0x0c093398u: goto P_0c093398;
case 0x0c09339au: goto P_0c09339a;
case 0x0c09339cu: goto P_0c09339c;
case 0x0c09339eu: goto P_0c09339e;
case 0x0c0933a0u: goto P_0c0933a0;
case 0x0c0933a2u: goto P_0c0933a2;
case 0x0c0933a4u: goto P_0c0933a4;
case 0x0c0933a6u: goto P_0c0933a6;
case 0x0c0933a8u: goto P_0c0933a8;
case 0x0c0933aau: goto P_0c0933aa;
case 0x0c0933acu: goto P_0c0933ac;
case 0x0c0933aeu: goto P_0c0933ae;
case 0x0c0933b0u: goto P_0c0933b0;
case 0x0c0933b2u: goto P_0c0933b2;
case 0x0c0933b4u: goto P_0c0933b4;
case 0x0c0933b6u: goto P_0c0933b6;
case 0x0c0933b8u: goto P_0c0933b8;
case 0x0c0933bau: goto P_0c0933ba;
case 0x0c0933bcu: goto P_0c0933bc;
case 0x0c0933beu: goto P_0c0933be;
case 0x0c0933c0u: goto P_0c0933c0;
case 0x0c0933c2u: goto P_0c0933c2;
case 0x0c0933c4u: goto P_0c0933c4;
case 0x0c0933c6u: goto P_0c0933c6;
case 0x0c0933c8u: goto P_0c0933c8;
case 0x0c0933cau: goto P_0c0933ca;
case 0x0c0933ccu: goto P_0c0933cc;
case 0x0c0933ceu: goto P_0c0933ce;
case 0x0c0933d0u: goto P_0c0933d0;
case 0x0c0933d2u: goto P_0c0933d2;
case 0x0c0933d4u: goto P_0c0933d4;
case 0x0c0933d6u: goto P_0c0933d6;
case 0x0c0933d8u: goto P_0c0933d8;
case 0x0c0933dau: goto P_0c0933da;
case 0x0c0933dcu: goto P_0c0933dc;
case 0x0c0933deu: goto P_0c0933de;
case 0x0c0933e0u: goto P_0c0933e0;
case 0x0c0933e2u: goto P_0c0933e2;
case 0x0c0933e4u: goto P_0c0933e4;
case 0x0c0933e6u: goto P_0c0933e6;
case 0x0c0933e8u: goto P_0c0933e8;
case 0x0c0933eau: goto P_0c0933ea;
case 0x0c0933ecu: goto P_0c0933ec;
case 0x0c0933eeu: goto P_0c0933ee;
case 0x0c0933f0u: goto P_0c0933f0;
case 0x0c0933f2u: goto P_0c0933f2;
case 0x0c0933f4u: goto P_0c0933f4;
case 0x0c0933f6u: goto P_0c0933f6;
case 0x0c0933f8u: goto P_0c0933f8;
case 0x0c0933fau: goto P_0c0933fa;
case 0x0c0933fcu: goto P_0c0933fc;
case 0x0c0933feu: goto P_0c0933fe;
case 0x0c093400u: goto P_0c093400;
case 0x0c093402u: goto P_0c093402;
case 0x0c093404u: goto P_0c093404;
case 0x0c093406u: goto P_0c093406;
case 0x0c093408u: goto P_0c093408;
case 0x0c09340au: goto P_0c09340a;
case 0x0c09340cu: goto P_0c09340c;
case 0x0c09340eu: goto P_0c09340e;
case 0x0c093410u: goto P_0c093410;
case 0x0c093412u: goto P_0c093412;
case 0x0c093414u: goto P_0c093414;
case 0x0c093416u: goto P_0c093416;
case 0x0c093418u: goto P_0c093418;
case 0x0c09341au: goto P_0c09341a;
case 0x0c09341cu: goto P_0c09341c;
case 0x0c09363au: goto P_0c09363a;
case 0x0c09363cu: goto P_0c09363c;
case 0x0c09363eu: goto P_0c09363e;
case 0x0c093640u: goto P_0c093640;
case 0x0c093642u: goto P_0c093642;
case 0x0c093644u: goto P_0c093644;
case 0x0c093646u: goto P_0c093646;
case 0x0c093648u: goto P_0c093648;
case 0x0c09364au: goto P_0c09364a;
case 0x0c09364cu: goto P_0c09364c;
case 0x0c09364eu: goto P_0c09364e;
case 0x0c093650u: goto P_0c093650;
case 0x0c093652u: goto P_0c093652;
case 0x0c093654u: goto P_0c093654;
case 0x0c093656u: goto P_0c093656;
case 0x0c093658u: goto P_0c093658;
case 0x0c09365au: goto P_0c09365a;
case 0x0c09365cu: goto P_0c09365c;
case 0x0c09365eu: goto P_0c09365e;
case 0x0c093660u: goto P_0c093660;
case 0x0c093662u: goto P_0c093662;
case 0x0c093664u: goto P_0c093664;
case 0x0c093666u: goto P_0c093666;
case 0x0c093668u: goto P_0c093668;
case 0x0c09366au: goto P_0c09366a;
case 0x0c09366cu: goto P_0c09366c;
case 0x0c09366eu: goto P_0c09366e;
case 0x0c093670u: goto P_0c093670;
case 0x0c093672u: goto P_0c093672;
case 0x0c093674u: goto P_0c093674;
case 0x0c093676u: goto P_0c093676;
case 0x0c093678u: goto P_0c093678;
case 0x0c09367au: goto P_0c09367a;
case 0x0c09367cu: goto P_0c09367c;
case 0x0c09367eu: goto P_0c09367e;
case 0x0c093680u: goto P_0c093680;
case 0x0c093682u: goto P_0c093682;
case 0x0c093684u: goto P_0c093684;
case 0x0c093686u: goto P_0c093686;
case 0x0c093688u: goto P_0c093688;
case 0x0c09368au: goto P_0c09368a;
case 0x0c09368cu: goto P_0c09368c;
case 0x0c09368eu: goto P_0c09368e;
case 0x0c093690u: goto P_0c093690;
case 0x0c093692u: goto P_0c093692;
case 0x0c093694u: goto P_0c093694;
case 0x0c093696u: goto P_0c093696;
case 0x0c093698u: goto P_0c093698;
case 0x0c09369au: goto P_0c09369a;
case 0x0c09369cu: goto P_0c09369c;
case 0x0c09369eu: goto P_0c09369e;
case 0x0c0936a0u: goto P_0c0936a0;
case 0x0c0936a2u: goto P_0c0936a2;
case 0x0c0936a4u: goto P_0c0936a4;
case 0x0c0936a6u: goto P_0c0936a6;
case 0x0c0936a8u: goto P_0c0936a8;
case 0x0c0936aau: goto P_0c0936aa;
case 0x0c0936acu: goto P_0c0936ac;
case 0x0c0936aeu: goto P_0c0936ae;
case 0x0c0936b0u: goto P_0c0936b0;
case 0x0c0936b2u: goto P_0c0936b2;
case 0x0c0936b4u: goto P_0c0936b4;
case 0x0c0936b6u: goto P_0c0936b6;
case 0x0c0936b8u: goto P_0c0936b8;
case 0x0c0936bau: goto P_0c0936ba;
case 0x0c0936bcu: goto P_0c0936bc;
case 0x0c0936beu: goto P_0c0936be;
case 0x0c0936c0u: goto P_0c0936c0;
case 0x0c0936c2u: goto P_0c0936c2;
case 0x0c0936c4u: goto P_0c0936c4;
case 0x0c0936c6u: goto P_0c0936c6;
case 0x0c0936c8u: goto P_0c0936c8;
case 0x0c0936cau: goto P_0c0936ca;
case 0x0c0936ccu: goto P_0c0936cc;
case 0x0c0936ceu: goto P_0c0936ce;
case 0x0c0936d0u: goto P_0c0936d0;
case 0x0c0936d2u: goto P_0c0936d2;
case 0x0c0936d4u: goto P_0c0936d4;
case 0x0c0936d6u: goto P_0c0936d6;
case 0x0c0936d8u: goto P_0c0936d8;
case 0x0c0936dau: goto P_0c0936da;
case 0x0c0936dcu: goto P_0c0936dc;
case 0x0c0936deu: goto P_0c0936de;
case 0x0c0936e0u: goto P_0c0936e0;
case 0x0c0936e2u: goto P_0c0936e2;
case 0x0c0936e4u: goto P_0c0936e4;
case 0x0c0936e6u: goto P_0c0936e6;
case 0x0c0936e8u: goto P_0c0936e8;
case 0x0c0936eau: goto P_0c0936ea;
case 0x0c0936ecu: goto P_0c0936ec;
case 0x0c0936eeu: goto P_0c0936ee;
case 0x0c0936f0u: goto P_0c0936f0;
case 0x0c0936f2u: goto P_0c0936f2;
case 0x0c0936f4u: goto P_0c0936f4;
case 0x0c0936f6u: goto P_0c0936f6;
case 0x0c0936f8u: goto P_0c0936f8;
case 0x0c0936fau: goto P_0c0936fa;
case 0x0c0936fcu: goto P_0c0936fc;
case 0x0c0936feu: goto P_0c0936fe;
case 0x0c093700u: goto P_0c093700;
case 0x0c093702u: goto P_0c093702;
case 0x0c093704u: goto P_0c093704;
case 0x0c093706u: goto P_0c093706;
case 0x0c093708u: goto P_0c093708;
case 0x0c09370au: goto P_0c09370a;
case 0x0c09370cu: goto P_0c09370c;
case 0x0c09370eu: goto P_0c09370e;
case 0x0c093710u: goto P_0c093710;
case 0x0c093712u: goto P_0c093712;
case 0x0c093714u: goto P_0c093714;
case 0x0c093716u: goto P_0c093716;
case 0x0c093718u: goto P_0c093718;
case 0x0c09371au: goto P_0c09371a;
case 0x0c09371cu: goto P_0c09371c;
case 0x0c09371eu: goto P_0c09371e;
case 0x0c093720u: goto P_0c093720;
case 0x0c093722u: goto P_0c093722;
case 0x0c093724u: goto P_0c093724;
case 0x0c093726u: goto P_0c093726;
case 0x0c093728u: goto P_0c093728;
case 0x0c09372au: goto P_0c09372a;
case 0x0c09372cu: goto P_0c09372c;
case 0x0c09372eu: goto P_0c09372e;
case 0x0c093730u: goto P_0c093730;
case 0x0c093732u: goto P_0c093732;
case 0x0c093734u: goto P_0c093734;
case 0x0c093736u: goto P_0c093736;
case 0x0c093738u: goto P_0c093738;
case 0x0c09373au: goto P_0c09373a;
case 0x0c09373cu: goto P_0c09373c;
case 0x0c09373eu: goto P_0c09373e;
case 0x0c093740u: goto P_0c093740;
case 0x0c093742u: goto P_0c093742;
case 0x0c093744u: goto P_0c093744;
case 0x0c093746u: goto P_0c093746;
case 0x0c093748u: goto P_0c093748;
case 0x0c09374au: goto P_0c09374a;
case 0x0c09374cu: goto P_0c09374c;
case 0x0c09374eu: goto P_0c09374e;
case 0x0c093750u: goto P_0c093750;
default: return vf3_matrix_family(target,s,ram);
}
P_0c093266: /* original 2fe6, guest PC 0x0c093266 */
if(!s->budget--) { s->failed_pc=0x0c093266u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093268;
P_0c093268: /* original 6e63, guest PC 0x0c093268 */
if(!s->budget--) { s->failed_pc=0x0c093268u; return 0; }
r[14]=r[6];
goto P_0c09326a;
P_0c09326a: /* original 2fd6, guest PC 0x0c09326a */
if(!s->budget--) { s->failed_pc=0x0c09326au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09326c;
P_0c09326c: /* original 6d43, guest PC 0x0c09326c */
if(!s->budget--) { s->failed_pc=0x0c09326cu; return 0; }
r[13]=r[4];
goto P_0c09326e;
P_0c09326e: /* original 2fc6, guest PC 0x0c09326e */
if(!s->budget--) { s->failed_pc=0x0c09326eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093270;
P_0c093270: /* original 4f22, guest PC 0x0c093270 */
if(!s->budget--) { s->failed_pc=0x0c093270u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c093272;
P_0c093272: /* original 7fd0, guest PC 0x0c093272 */
if(!s->budget--) { s->failed_pc=0x0c093272u; return 0; }
r[15]+=0xffffffd0u;
goto P_0c093274;
P_0c093274: /* original 1f51, guest PC 0x0c093274 */
if(!s->budget--) { s->failed_pc=0x0c093274u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c093276;
P_0c093276: /* original 1f72, guest PC 0x0c093276 */
if(!s->budget--) { s->failed_pc=0x0c093276u; return 0; }
write(ram,r[15]+8,r[7],4);
goto P_0c093278;
P_0c093278: /* original e034, guest PC 0x0c093278 */
if(!s->budget--) { s->failed_pc=0x0c093278u; return 0; }
r[0]=0x00000034u;
goto P_0c09327a;
P_0c09327a: /* original 03ed, guest PC 0x0c09327a */
if(!s->budget--) { s->failed_pc=0x0c09327au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09327c;
P_0c09327c: /* original e501, guest PC 0x0c09327c */
if(!s->budget--) { s->failed_pc=0x0c09327cu; return 0; }
r[5]=0x00000001u;
goto P_0c09327e;
P_0c09327e: /* original 633d, guest PC 0x0c09327e */
if(!s->budget--) { s->failed_pc=0x0c09327eu; return 0; }
r[3]=r[3]&65535u;
goto P_0c093280;
P_0c093280: /* original 2358, guest PC 0x0c093280 */
if(!s->budget--) { s->failed_pc=0x0c093280u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c093282;
P_0c093282: /* original 8f03, guest PC 0x0c093282 */
if(!s->budget--) { s->failed_pc=0x0c093282u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c09328c; }
goto P_0c093286;
P_0c093284: /* original 2f32, guest PC 0x0c093284 */
if(!s->budget--) { s->failed_pc=0x0c093284u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c093286;
P_0c093286: /* original d20e, guest PC 0x0c093286 */
if(!s->budget--) { s->failed_pc=0x0c093286u; return 0; }
r[2]=read(ram,0x0c0932c0u,4);
goto P_0c093288;
P_0c093288: /* original 422b, guest PC 0x0c093288 */
if(!s->budget--) { s->failed_pc=0x0c093288u; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c093412u: goto P_0c093412;
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
P_0c09328a: /* original 0009, guest PC 0x0c09328a */
if(!s->budget--) { s->failed_pc=0x0c09328au; return 0; }
goto P_0c09328c;
P_0c09328c: /* original 60f2, guest PC 0x0c09328c */
if(!s->budget--) { s->failed_pc=0x0c09328cu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c09328e;
P_0c09328e: /* original c802, guest PC 0x0c09328e */
if(!s->budget--) { s->failed_pc=0x0c09328eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c093290;
P_0c093290: /* original 8947, guest PC 0x0c093290 */
if(!s->budget--) { s->failed_pc=0x0c093290u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093322; }
goto P_0c093292;
P_0c093292: /* original 60f2, guest PC 0x0c093292 */
if(!s->budget--) { s->failed_pc=0x0c093292u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c093294;
P_0c093294: /* original c804, guest PC 0x0c093294 */
if(!s->budget--) { s->failed_pc=0x0c093294u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c093296;
P_0c093296: /* original 8d03, guest PC 0x0c093296 */
if(!s->budget--) { s->failed_pc=0x0c093296u; return 0; }
cond=r[17]&1u;
r[12]=0x00000058u;
if(cond) { goto P_0c0932a0; }
goto P_0c09329a;
P_0c093298: /* original ec58, guest PC 0x0c093298 */
if(!s->budget--) { s->failed_pc=0x0c093298u; return 0; }
r[12]=0x00000058u;
goto P_0c09329a;
P_0c09329a: /* original d30a, guest PC 0x0c09329a */
if(!s->budget--) { s->failed_pc=0x0c09329au; return 0; }
r[3]=read(ram,0x0c0932c4u,4);
goto P_0c09329c;
P_0c09329c: /* original 432b, guest PC 0x0c09329c */
if(!s->budget--) { s->failed_pc=0x0c09329cu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09340cu: goto P_0c09340c;
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
P_0c09329e: /* original 0009, guest PC 0x0c09329e */
if(!s->budget--) { s->failed_pc=0x0c09329eu; return 0; }
goto P_0c0932a0;
P_0c0932a0: /* original 60f2, guest PC 0x0c0932a0 */
if(!s->budget--) { s->failed_pc=0x0c0932a0u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0932a2;
P_0c0932a2: /* original c840, guest PC 0x0c0932a2 */
if(!s->budget--) { s->failed_pc=0x0c0932a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c0932a4;
P_0c0932a4: /* original 8910, guest PC 0x0c0932a4 */
if(!s->budget--) { s->failed_pc=0x0c0932a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0932c8; }
goto P_0c0932a6;
P_0c0932a6: /* original a010, guest PC 0x0c0932a6 */
if(!s->budget--) { s->failed_pc=0x0c0932a6u; return 0; }
r[4]=0x00000000u;
goto P_0c0932ca;
P_0c0932a8: /* original e400, guest PC 0x0c0932a8 */
if(!s->budget--) { s->failed_pc=0x0c0932a8u; return 0; }
r[4]=0x00000000u;
if(!vf3_matrix_family(0x0c0932aau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0932aau; return 0; } return 1;
P_0c0932c8: /* original 6453, guest PC 0x0c0932c8 */
if(!s->budget--) { s->failed_pc=0x0c0932c8u; return 0; }
r[4]=r[5];
goto P_0c0932ca;
P_0c0932ca: /* original 60f2, guest PC 0x0c0932ca */
if(!s->budget--) { s->failed_pc=0x0c0932cau; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0932cc;
P_0c0932cc: /* original c820, guest PC 0x0c0932cc */
if(!s->budget--) { s->failed_pc=0x0c0932ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0932ce;
P_0c0932ce: /* original 8919, guest PC 0x0c0932ce */
if(!s->budget--) { s->failed_pc=0x0c0932ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093304; }
goto P_0c0932d0;
P_0c0932d0: /* original e05c, guest PC 0x0c0932d0 */
if(!s->budget--) { s->failed_pc=0x0c0932d0u; return 0; }
r[0]=0x0000005cu;
goto P_0c0932d2;
P_0c0932d2: /* original f3d6, guest PC 0x0c0932d2 */
if(!s->budget--) { s->failed_pc=0x0c0932d2u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0932d4;
P_0c0932d4: /* original e074, guest PC 0x0c0932d4 */
if(!s->budget--) { s->failed_pc=0x0c0932d4u; return 0; }
r[0]=0x00000074u;
goto P_0c0932d6;
P_0c0932d6: /* original fd37, guest PC 0x0c0932d6 */
if(!s->budget--) { s->failed_pc=0x0c0932d6u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0932d8;
P_0c0932d8: /* original e060, guest PC 0x0c0932d8 */
if(!s->budget--) { s->failed_pc=0x0c0932d8u; return 0; }
r[0]=0x00000060u;
goto P_0c0932da;
P_0c0932da: /* original f3d6, guest PC 0x0c0932da */
if(!s->budget--) { s->failed_pc=0x0c0932dau; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0932dc;
P_0c0932dc: /* original e078, guest PC 0x0c0932dc */
if(!s->budget--) { s->failed_pc=0x0c0932dcu; return 0; }
r[0]=0x00000078u;
goto P_0c0932de;
P_0c0932de: /* original fd37, guest PC 0x0c0932de */
if(!s->budget--) { s->failed_pc=0x0c0932deu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0932e0;
P_0c0932e0: /* original e064, guest PC 0x0c0932e0 */
if(!s->budget--) { s->failed_pc=0x0c0932e0u; return 0; }
r[0]=0x00000064u;
goto P_0c0932e2;
P_0c0932e2: /* original f3d6, guest PC 0x0c0932e2 */
if(!s->budget--) { s->failed_pc=0x0c0932e2u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0932e4;
P_0c0932e4: /* original e07c, guest PC 0x0c0932e4 */
if(!s->budget--) { s->failed_pc=0x0c0932e4u; return 0; }
r[0]=0x0000007cu;
goto P_0c0932e6;
P_0c0932e6: /* original fd37, guest PC 0x0c0932e6 */
if(!s->budget--) { s->failed_pc=0x0c0932e6u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0932e8;
P_0c0932e8: /* original e024, guest PC 0x0c0932e8 */
if(!s->budget--) { s->failed_pc=0x0c0932e8u; return 0; }
r[0]=0x00000024u;
goto P_0c0932ea;
P_0c0932ea: /* original f3f6, guest PC 0x0c0932ea */
if(!s->budget--) { s->failed_pc=0x0c0932eau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0932ec;
P_0c0932ec: /* original e068, guest PC 0x0c0932ec */
if(!s->budget--) { s->failed_pc=0x0c0932ecu; return 0; }
r[0]=0x00000068u;
goto P_0c0932ee;
P_0c0932ee: /* original fd37, guest PC 0x0c0932ee */
if(!s->budget--) { s->failed_pc=0x0c0932eeu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0932f0;
P_0c0932f0: /* original e028, guest PC 0x0c0932f0 */
if(!s->budget--) { s->failed_pc=0x0c0932f0u; return 0; }
r[0]=0x00000028u;
goto P_0c0932f2;
P_0c0932f2: /* original f3f6, guest PC 0x0c0932f2 */
if(!s->budget--) { s->failed_pc=0x0c0932f2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0932f4;
P_0c0932f4: /* original e06c, guest PC 0x0c0932f4 */
if(!s->budget--) { s->failed_pc=0x0c0932f4u; return 0; }
r[0]=0x0000006cu;
goto P_0c0932f6;
P_0c0932f6: /* original fd37, guest PC 0x0c0932f6 */
if(!s->budget--) { s->failed_pc=0x0c0932f6u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0932f8;
P_0c0932f8: /* original e02c, guest PC 0x0c0932f8 */
if(!s->budget--) { s->failed_pc=0x0c0932f8u; return 0; }
r[0]=0x0000002cu;
goto P_0c0932fa;
P_0c0932fa: /* original d31c, guest PC 0x0c0932fa */
if(!s->budget--) { s->failed_pc=0x0c0932fau; return 0; }
r[3]=read(ram,0x0c09336cu,4);
goto P_0c0932fc;
P_0c0932fc: /* original f3f6, guest PC 0x0c0932fc */
if(!s->budget--) { s->failed_pc=0x0c0932fcu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0932fe;
P_0c0932fe: /* original e070, guest PC 0x0c0932fe */
if(!s->budget--) { s->failed_pc=0x0c0932feu; return 0; }
r[0]=0x00000070u;
goto P_0c093300;
P_0c093300: /* original 432b, guest PC 0x0c093300 */
if(!s->budget--) { s->failed_pc=0x0c093300u; return 0; }
target=r[3];
vf3_matrix_store(s,ram,3,r[13]+r[0]);
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
P_0c093302: /* original fd37, guest PC 0x0c093302 */
if(!s->budget--) { s->failed_pc=0x0c093302u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c093304;
P_0c093304: /* original 62f3, guest PC 0x0c093304 */
if(!s->budget--) { s->failed_pc=0x0c093304u; return 0; }
r[2]=r[15];
goto P_0c093306;
P_0c093306: /* original 2f26, guest PC 0x0c093306 */
if(!s->budget--) { s->failed_pc=0x0c093306u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093308;
P_0c093308: /* original 63f3, guest PC 0x0c093308 */
if(!s->budget--) { s->failed_pc=0x0c093308u; return 0; }
r[3]=r[15];
goto P_0c09330a;
P_0c09330a: /* original 7328, guest PC 0x0c09330a */
if(!s->budget--) { s->failed_pc=0x0c09330au; return 0; }
r[3]+=0x00000028u;
goto P_0c09330c;
P_0c09330c: /* original 2f36, guest PC 0x0c09330c */
if(!s->budget--) { s->failed_pc=0x0c09330cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09330e;
P_0c09330e: /* original e050, guest PC 0x0c09330e */
if(!s->budget--) { s->failed_pc=0x0c09330eu; return 0; }
r[0]=0x00000050u;
goto P_0c093310;
P_0c093310: /* original 2f46, guest PC 0x0c093310 */
if(!s->budget--) { s->failed_pc=0x0c093310u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093312;
P_0c093312: /* original 66e3, guest PC 0x0c093312 */
if(!s->budget--) { s->failed_pc=0x0c093312u; return 0; }
r[6]=r[14];
goto P_0c093314;
P_0c093314: /* original 55f4, guest PC 0x0c093314 */
if(!s->budget--) { s->failed_pc=0x0c093314u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c093316;
P_0c093316: /* original d316, guest PC 0x0c093316 */
if(!s->budget--) { s->failed_pc=0x0c093316u; return 0; }
r[3]=read(ram,0x0c093370u,4);
goto P_0c093318;
P_0c093318: /* original 07fe, guest PC 0x0c093318 */
if(!s->budget--) { s->failed_pc=0x0c093318u; return 0; }
r[7]=read(ram,r[15]+r[0],4);
goto P_0c09331a;
P_0c09331a: /* original 430b, guest PC 0x0c09331a */
if(!s->budget--) { s->failed_pc=0x0c09331au; return 0; }
target=r[3];
r[16]=code_base|0x0c09331eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09331eu) { target=s->pc; goto dispatch; }
goto P_0c09331e;
P_0c09331c: /* original 64d3, guest PC 0x0c09331c */
if(!s->budget--) { s->failed_pc=0x0c09331cu; return 0; }
r[4]=r[13];
goto P_0c09331e;
P_0c09331e: /* original a001, guest PC 0x0c09331e */
if(!s->budget--) { s->failed_pc=0x0c09331eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c093324;
P_0c093320: /* original 7f0c, guest PC 0x0c093320 */
if(!s->budget--) { s->failed_pc=0x0c093320u; return 0; }
r[15]+=0x0000000cu;
goto P_0c093322;
P_0c093322: /* original ec38, guest PC 0x0c093322 */
if(!s->budget--) { s->failed_pc=0x0c093322u; return 0; }
r[12]=0x00000038u;
goto P_0c093324;
P_0c093324: /* original 54f1, guest PC 0x0c093324 */
if(!s->budget--) { s->failed_pc=0x0c093324u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c093326;
P_0c093326: /* original e061, guest PC 0x0c093326 */
if(!s->budget--) { s->failed_pc=0x0c093326u; return 0; }
r[0]=0x00000061u;
goto P_0c093328;
P_0c093328: /* original 044c, guest PC 0x0c093328 */
if(!s->budget--) { s->failed_pc=0x0c093328u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09332a;
P_0c09332a: /* original 644c, guest PC 0x0c09332a */
if(!s->budget--) { s->failed_pc=0x0c09332au; return 0; }
r[4]=r[4]&255u;
goto P_0c09332c;
P_0c09332c: /* original 6043, guest PC 0x0c09332c */
if(!s->budget--) { s->failed_pc=0x0c09332cu; return 0; }
r[0]=r[4];
goto P_0c09332e;
P_0c09332e: /* original 8801, guest PC 0x0c09332e */
if(!s->budget--) { s->failed_pc=0x0c09332eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c093330;
P_0c093330: /* original 8913, guest PC 0x0c093330 */
if(!s->budget--) { s->failed_pc=0x0c093330u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09335a; }
goto P_0c093332;
P_0c093332: /* original 6043, guest PC 0x0c093332 */
if(!s->budget--) { s->failed_pc=0x0c093332u; return 0; }
r[0]=r[4];
goto P_0c093334;
P_0c093334: /* original 8805, guest PC 0x0c093334 */
if(!s->budget--) { s->failed_pc=0x0c093334u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c093336;
P_0c093336: /* original 8910, guest PC 0x0c093336 */
if(!s->budget--) { s->failed_pc=0x0c093336u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09335a; }
goto P_0c093338;
P_0c093338: /* original e024, guest PC 0x0c093338 */
if(!s->budget--) { s->failed_pc=0x0c093338u; return 0; }
r[0]=0x00000024u;
goto P_0c09333a;
P_0c09333a: /* original f3f6, guest PC 0x0c09333a */
if(!s->budget--) { s->failed_pc=0x0c09333au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09333c;
P_0c09333c: /* original e018, guest PC 0x0c09333c */
if(!s->budget--) { s->failed_pc=0x0c09333cu; return 0; }
r[0]=0x00000018u;
goto P_0c09333e;
P_0c09333e: /* original ff37, guest PC 0x0c09333e */
if(!s->budget--) { s->failed_pc=0x0c09333eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c093340;
P_0c093340: /* original e024, guest PC 0x0c093340 */
if(!s->budget--) { s->failed_pc=0x0c093340u; return 0; }
r[0]=0x00000024u;
goto P_0c093342;
P_0c093342: /* original f3e6, guest PC 0x0c093342 */
if(!s->budget--) { s->failed_pc=0x0c093342u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c093344;
P_0c093344: /* original e028, guest PC 0x0c093344 */
if(!s->budget--) { s->failed_pc=0x0c093344u; return 0; }
r[0]=0x00000028u;
goto P_0c093346;
P_0c093346: /* original f2f6, guest PC 0x0c093346 */
if(!s->budget--) { s->failed_pc=0x0c093346u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c093348;
P_0c093348: /* original e01c, guest PC 0x0c093348 */
if(!s->budget--) { s->failed_pc=0x0c093348u; return 0; }
r[0]=0x0000001cu;
goto P_0c09334a;
P_0c09334a: /* original f231, guest PC 0x0c09334a */
if(!s->budget--) { s->failed_pc=0x0c09334au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c09334c;
P_0c09334c: /* original ff27, guest PC 0x0c09334c */
if(!s->budget--) { s->failed_pc=0x0c09334cu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c09334e;
P_0c09334e: /* original e02c, guest PC 0x0c09334e */
if(!s->budget--) { s->failed_pc=0x0c09334eu; return 0; }
r[0]=0x0000002cu;
goto P_0c093350;
P_0c093350: /* original d308, guest PC 0x0c093350 */
if(!s->budget--) { s->failed_pc=0x0c093350u; return 0; }
r[3]=read(ram,0x0c093374u,4);
goto P_0c093352;
P_0c093352: /* original f3f6, guest PC 0x0c093352 */
if(!s->budget--) { s->failed_pc=0x0c093352u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c093354;
P_0c093354: /* original e020, guest PC 0x0c093354 */
if(!s->budget--) { s->failed_pc=0x0c093354u; return 0; }
r[0]=0x00000020u;
goto P_0c093356;
P_0c093356: /* original 432b, guest PC 0x0c093356 */
if(!s->budget--) { s->failed_pc=0x0c093356u; return 0; }
target=r[3];
vf3_matrix_store(s,ram,3,r[15]+r[0]);
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
P_0c093358: /* original ff37, guest PC 0x0c093358 */
if(!s->budget--) { s->failed_pc=0x0c093358u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09335a;
P_0c09335a: /* original 65f3, guest PC 0x0c09335a */
if(!s->budget--) { s->failed_pc=0x0c09335au; return 0; }
r[5]=r[15];
goto P_0c09335c;
P_0c09335c: /* original 64f3, guest PC 0x0c09335c */
if(!s->budget--) { s->failed_pc=0x0c09335cu; return 0; }
r[4]=r[15];
goto P_0c09335e;
P_0c09335e: /* original 66d3, guest PC 0x0c09335e */
if(!s->budget--) { s->failed_pc=0x0c09335eu; return 0; }
r[6]=r[13];
goto P_0c093360;
P_0c093360: /* original 7418, guest PC 0x0c093360 */
if(!s->budget--) { s->failed_pc=0x0c093360u; return 0; }
r[4]+=0x00000018u;
goto P_0c093362;
P_0c093362: /* original 765c, guest PC 0x0c093362 */
if(!s->budget--) { s->failed_pc=0x0c093362u; return 0; }
r[6]+=0x0000005cu;
goto P_0c093364;
P_0c093364: /* original 7524, guest PC 0x0c093364 */
if(!s->budget--) { s->failed_pc=0x0c093364u; return 0; }
r[5]+=0x00000024u;
goto P_0c093366;
P_0c093366: /* original a007, guest PC 0x0c093366 */
if(!s->budget--) { s->failed_pc=0x0c093366u; return 0; }
goto P_0c093378;
P_0c093368: /* original 0009, guest PC 0x0c093368 */
if(!s->budget--) { s->failed_pc=0x0c093368u; return 0; }
if(!vf3_matrix_family(0x0c09336au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09336au; return 0; } return 1;
P_0c093378: /* original f059, guest PC 0x0c093378 */
if(!s->budget--) { s->failed_pc=0x0c093378u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c09337a;
P_0c09337a: /* original f369, guest PC 0x0c09337a */
if(!s->budget--) { s->failed_pc=0x0c09337au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c09337c;
P_0c09337c: /* original f159, guest PC 0x0c09337c */
if(!s->budget--) { s->failed_pc=0x0c09337cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c09337e;
P_0c09337e: /* original f469, guest PC 0x0c09337e */
if(!s->budget--) { s->failed_pc=0x0c09337eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c093380;
P_0c093380: /* original f259, guest PC 0x0c093380 */
if(!s->budget--) { s->failed_pc=0x0c093380u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093382;
P_0c093382: /* original f569, guest PC 0x0c093382 */
if(!s->budget--) { s->failed_pc=0x0c093382u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c093384;
P_0c093384: /* original 740c, guest PC 0x0c093384 */
if(!s->budget--) { s->failed_pc=0x0c093384u; return 0; }
r[4]+=0x0000000cu;
goto P_0c093386;
P_0c093386: /* original f030, guest PC 0x0c093386 */
if(!s->budget--) { s->failed_pc=0x0c093386u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c093388;
P_0c093388: /* original f250, guest PC 0x0c093388 */
if(!s->budget--) { s->failed_pc=0x0c093388u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c09338a;
P_0c09338a: /* original f140, guest PC 0x0c09338a */
if(!s->budget--) { s->failed_pc=0x0c09338au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c09338c;
P_0c09338c: /* original f42b, guest PC 0x0c09338c */
if(!s->budget--) { s->failed_pc=0x0c09338cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c09338e;
P_0c09338e: /* original f41b, guest PC 0x0c09338e */
if(!s->budget--) { s->failed_pc=0x0c09338eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c093390;
P_0c093390: /* original f40b, guest PC 0x0c093390 */
if(!s->budget--) { s->failed_pc=0x0c093390u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093392;
P_0c093392: /* original 0009, guest PC 0x0c093392 */
if(!s->budget--) { s->failed_pc=0x0c093392u; return 0; }
goto P_0c093394;
P_0c093394: /* original 63f3, guest PC 0x0c093394 */
if(!s->budget--) { s->failed_pc=0x0c093394u; return 0; }
r[3]=r[15];
goto P_0c093396;
P_0c093396: /* original e044, guest PC 0x0c093396 */
if(!s->budget--) { s->failed_pc=0x0c093396u; return 0; }
r[0]=0x00000044u;
goto P_0c093398;
P_0c093398: /* original 2f36, guest PC 0x0c093398 */
if(!s->budget--) { s->failed_pc=0x0c093398u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09339a;
P_0c09339a: /* original 65e3, guest PC 0x0c09339a */
if(!s->budget--) { s->failed_pc=0x0c09339au; return 0; }
r[5]=r[14];
goto P_0c09339c;
P_0c09339c: /* original 02fe, guest PC 0x0c09339c */
if(!s->budget--) { s->failed_pc=0x0c09339cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c09339e;
P_0c09339e: /* original 2f26, guest PC 0x0c09339e */
if(!s->budget--) { s->failed_pc=0x0c09339eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0933a0;
P_0c0933a0: /* original 53f4, guest PC 0x0c0933a0 */
if(!s->budget--) { s->failed_pc=0x0c0933a0u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c0933a2;
P_0c0933a2: /* original 2f36, guest PC 0x0c0933a2 */
if(!s->budget--) { s->failed_pc=0x0c0933a2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0933a4;
P_0c0933a4: /* original 66f3, guest PC 0x0c0933a4 */
if(!s->budget--) { s->failed_pc=0x0c0933a4u; return 0; }
r[6]=r[15];
goto P_0c0933a6;
P_0c0933a6: /* original d352, guest PC 0x0c0933a6 */
if(!s->budget--) { s->failed_pc=0x0c0933a6u; return 0; }
r[3]=read(ram,0x0c0934f0u,4);
goto P_0c0933a8;
P_0c0933a8: /* original 67f3, guest PC 0x0c0933a8 */
if(!s->budget--) { s->failed_pc=0x0c0933a8u; return 0; }
r[7]=r[15];
goto P_0c0933aa;
P_0c0933aa: /* original 7730, guest PC 0x0c0933aa */
if(!s->budget--) { s->failed_pc=0x0c0933aau; return 0; }
r[7]+=0x00000030u;
goto P_0c0933ac;
P_0c0933ac: /* original 7624, guest PC 0x0c0933ac */
if(!s->budget--) { s->failed_pc=0x0c0933acu; return 0; }
r[6]+=0x00000024u;
goto P_0c0933ae;
P_0c0933ae: /* original 430b, guest PC 0x0c0933ae */
if(!s->budget--) { s->failed_pc=0x0c0933aeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0933b2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0933b2u) { target=s->pc; goto dispatch; }
goto P_0c0933b2;
P_0c0933b0: /* original 64d3, guest PC 0x0c0933b0 */
if(!s->budget--) { s->failed_pc=0x0c0933b0u; return 0; }
r[4]=r[13];
goto P_0c0933b2;
P_0c0933b2: /* original 7f0c, guest PC 0x0c0933b2 */
if(!s->budget--) { s->failed_pc=0x0c0933b2u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0933b4;
P_0c0933b4: /* original d24f, guest PC 0x0c0933b4 */
if(!s->budget--) { s->failed_pc=0x0c0933b4u; return 0; }
r[2]=read(ram,0x0c0934f4u,4);
goto P_0c0933b6;
P_0c0933b6: /* original 65f3, guest PC 0x0c0933b6 */
if(!s->budget--) { s->failed_pc=0x0c0933b6u; return 0; }
r[5]=r[15];
goto P_0c0933b8;
P_0c0933b8: /* original 66f3, guest PC 0x0c0933b8 */
if(!s->budget--) { s->failed_pc=0x0c0933b8u; return 0; }
r[6]=r[15];
goto P_0c0933ba;
P_0c0933ba: /* original 67f3, guest PC 0x0c0933ba */
if(!s->budget--) { s->failed_pc=0x0c0933bau; return 0; }
r[7]=r[15];
goto P_0c0933bc;
P_0c0933bc: /* original 7518, guest PC 0x0c0933bc */
if(!s->budget--) { s->failed_pc=0x0c0933bcu; return 0; }
r[5]+=0x00000018u;
goto P_0c0933be;
P_0c0933be: /* original 7624, guest PC 0x0c0933be */
if(!s->budget--) { s->failed_pc=0x0c0933beu; return 0; }
r[6]+=0x00000024u;
goto P_0c0933c0;
P_0c0933c0: /* original 770c, guest PC 0x0c0933c0 */
if(!s->budget--) { s->failed_pc=0x0c0933c0u; return 0; }
r[7]+=0x0000000cu;
goto P_0c0933c2;
P_0c0933c2: /* original 420b, guest PC 0x0c0933c2 */
if(!s->budget--) { s->failed_pc=0x0c0933c2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0933c6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0933c6u) { target=s->pc; goto dispatch; }
goto P_0c0933c6;
P_0c0933c4: /* original 64e3, guest PC 0x0c0933c4 */
if(!s->budget--) { s->failed_pc=0x0c0933c4u; return 0; }
r[4]=r[14];
goto P_0c0933c6;
P_0c0933c6: /* original e018, guest PC 0x0c0933c6 */
if(!s->budget--) { s->failed_pc=0x0c0933c6u; return 0; }
r[0]=0x00000018u;
goto P_0c0933c8;
P_0c0933c8: /* original f3f6, guest PC 0x0c0933c8 */
if(!s->budget--) { s->failed_pc=0x0c0933c8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0933ca;
P_0c0933ca: /* original e01c, guest PC 0x0c0933ca */
if(!s->budget--) { s->failed_pc=0x0c0933cau; return 0; }
r[0]=0x0000001cu;
goto P_0c0933cc;
P_0c0933cc: /* original fe3a, guest PC 0x0c0933cc */
if(!s->budget--) { s->failed_pc=0x0c0933ccu; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c0933ce;
P_0c0933ce: /* original f3f6, guest PC 0x0c0933ce */
if(!s->budget--) { s->failed_pc=0x0c0933ceu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0933d0;
P_0c0933d0: /* original e004, guest PC 0x0c0933d0 */
if(!s->budget--) { s->failed_pc=0x0c0933d0u; return 0; }
r[0]=0x00000004u;
goto P_0c0933d2;
P_0c0933d2: /* original fe37, guest PC 0x0c0933d2 */
if(!s->budget--) { s->failed_pc=0x0c0933d2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0933d4;
P_0c0933d4: /* original e020, guest PC 0x0c0933d4 */
if(!s->budget--) { s->failed_pc=0x0c0933d4u; return 0; }
r[0]=0x00000020u;
goto P_0c0933d6;
P_0c0933d6: /* original f3f6, guest PC 0x0c0933d6 */
if(!s->budget--) { s->failed_pc=0x0c0933d6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0933d8;
P_0c0933d8: /* original e008, guest PC 0x0c0933d8 */
if(!s->budget--) { s->failed_pc=0x0c0933d8u; return 0; }
r[0]=0x00000008u;
goto P_0c0933da;
P_0c0933da: /* original fe37, guest PC 0x0c0933da */
if(!s->budget--) { s->failed_pc=0x0c0933dau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0933dc;
P_0c0933dc: /* original e024, guest PC 0x0c0933dc */
if(!s->budget--) { s->failed_pc=0x0c0933dcu; return 0; }
r[0]=0x00000024u;
goto P_0c0933de;
P_0c0933de: /* original f3f6, guest PC 0x0c0933de */
if(!s->budget--) { s->failed_pc=0x0c0933deu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0933e0;
P_0c0933e0: /* original e00c, guest PC 0x0c0933e0 */
if(!s->budget--) { s->failed_pc=0x0c0933e0u; return 0; }
r[0]=0x0000000cu;
goto P_0c0933e2;
P_0c0933e2: /* original fe37, guest PC 0x0c0933e2 */
if(!s->budget--) { s->failed_pc=0x0c0933e2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0933e4;
P_0c0933e4: /* original e028, guest PC 0x0c0933e4 */
if(!s->budget--) { s->failed_pc=0x0c0933e4u; return 0; }
r[0]=0x00000028u;
goto P_0c0933e6;
P_0c0933e6: /* original f3f6, guest PC 0x0c0933e6 */
if(!s->budget--) { s->failed_pc=0x0c0933e6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0933e8;
P_0c0933e8: /* original e010, guest PC 0x0c0933e8 */
if(!s->budget--) { s->failed_pc=0x0c0933e8u; return 0; }
r[0]=0x00000010u;
goto P_0c0933ea;
P_0c0933ea: /* original fe37, guest PC 0x0c0933ea */
if(!s->budget--) { s->failed_pc=0x0c0933eau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0933ec;
P_0c0933ec: /* original e02c, guest PC 0x0c0933ec */
if(!s->budget--) { s->failed_pc=0x0c0933ecu; return 0; }
r[0]=0x0000002cu;
goto P_0c0933ee;
P_0c0933ee: /* original f3f6, guest PC 0x0c0933ee */
if(!s->budget--) { s->failed_pc=0x0c0933eeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0933f0;
P_0c0933f0: /* original e014, guest PC 0x0c0933f0 */
if(!s->budget--) { s->failed_pc=0x0c0933f0u; return 0; }
r[0]=0x00000014u;
goto P_0c0933f2;
P_0c0933f2: /* original fe37, guest PC 0x0c0933f2 */
if(!s->budget--) { s->failed_pc=0x0c0933f2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0933f4;
P_0c0933f4: /* original e018, guest PC 0x0c0933f4 */
if(!s->budget--) { s->failed_pc=0x0c0933f4u; return 0; }
r[0]=0x00000018u;
goto P_0c0933f6;
P_0c0933f6: /* original f3f6, guest PC 0x0c0933f6 */
if(!s->budget--) { s->failed_pc=0x0c0933f6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0933f8;
P_0c0933f8: /* original e024, guest PC 0x0c0933f8 */
if(!s->budget--) { s->failed_pc=0x0c0933f8u; return 0; }
r[0]=0x00000024u;
goto P_0c0933fa;
P_0c0933fa: /* original ff37, guest PC 0x0c0933fa */
if(!s->budget--) { s->failed_pc=0x0c0933fau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0933fc;
P_0c0933fc: /* original e01c, guest PC 0x0c0933fc */
if(!s->budget--) { s->failed_pc=0x0c0933fcu; return 0; }
r[0]=0x0000001cu;
goto P_0c0933fe;
P_0c0933fe: /* original f3f6, guest PC 0x0c0933fe */
if(!s->budget--) { s->failed_pc=0x0c0933feu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c093400;
P_0c093400: /* original e028, guest PC 0x0c093400 */
if(!s->budget--) { s->failed_pc=0x0c093400u; return 0; }
r[0]=0x00000028u;
goto P_0c093402;
P_0c093402: /* original ff37, guest PC 0x0c093402 */
if(!s->budget--) { s->failed_pc=0x0c093402u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c093404;
P_0c093404: /* original e020, guest PC 0x0c093404 */
if(!s->budget--) { s->failed_pc=0x0c093404u; return 0; }
r[0]=0x00000020u;
goto P_0c093406;
P_0c093406: /* original f3f6, guest PC 0x0c093406 */
if(!s->budget--) { s->failed_pc=0x0c093406u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c093408;
P_0c093408: /* original e02c, guest PC 0x0c093408 */
if(!s->budget--) { s->failed_pc=0x0c093408u; return 0; }
r[0]=0x0000002cu;
goto P_0c09340a;
P_0c09340a: /* original ff37, guest PC 0x0c09340a */
if(!s->budget--) { s->failed_pc=0x0c09340au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09340c;
P_0c09340c: /* original d33a, guest PC 0x0c09340c */
if(!s->budget--) { s->failed_pc=0x0c09340cu; return 0; }
r[3]=read(ram,0x0c0934f8u,4);
goto P_0c09340e;
P_0c09340e: /* original 432b, guest PC 0x0c09340e */
if(!s->budget--) { s->failed_pc=0x0c09340eu; return 0; }
target=r[3];
r[14]+=r[12];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c093278u: goto P_0c093278;
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
P_0c093410: /* original 3ecc, guest PC 0x0c093410 */
if(!s->budget--) { s->failed_pc=0x0c093410u; return 0; }
r[14]+=r[12];
goto P_0c093412;
P_0c093412: /* original 7f30, guest PC 0x0c093412 */
if(!s->budget--) { s->failed_pc=0x0c093412u; return 0; }
r[15]+=0x00000030u;
goto P_0c093414;
P_0c093414: /* original 4f26, guest PC 0x0c093414 */
if(!s->budget--) { s->failed_pc=0x0c093414u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c093416;
P_0c093416: /* original 6cf6, guest PC 0x0c093416 */
if(!s->budget--) { s->failed_pc=0x0c093416u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c093418;
P_0c093418: /* original 6df6, guest PC 0x0c093418 */
if(!s->budget--) { s->failed_pc=0x0c093418u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09341a;
P_0c09341a: /* original 000b, guest PC 0x0c09341a */
if(!s->budget--) { s->failed_pc=0x0c09341au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09341c: /* original 6ef6, guest PC 0x0c09341c */
if(!s->budget--) { s->failed_pc=0x0c09341cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09341eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09341eu; return 0; } return 1;
P_0c09363a: /* original 2fe6, guest PC 0x0c09363a */
if(!s->budget--) { s->failed_pc=0x0c09363au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09363c;
P_0c09363c: /* original 2fd6, guest PC 0x0c09363c */
if(!s->budget--) { s->failed_pc=0x0c09363cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09363e;
P_0c09363e: /* original 2fc6, guest PC 0x0c09363e */
if(!s->budget--) { s->failed_pc=0x0c09363eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093640;
P_0c093640: /* original 2fb6, guest PC 0x0c093640 */
if(!s->budget--) { s->failed_pc=0x0c093640u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093642;
P_0c093642: /* original 4f22, guest PC 0x0c093642 */
if(!s->budget--) { s->failed_pc=0x0c093642u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c093644;
P_0c093644: /* original 9385, guest PC 0x0c093644 */
if(!s->budget--) { s->failed_pc=0x0c093644u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093752u,2);
goto P_0c093646;
P_0c093646: /* original 7fec, guest PC 0x0c093646 */
if(!s->budget--) { s->failed_pc=0x0c093646u; return 0; }
r[15]+=0xffffffecu;
goto P_0c093648;
P_0c093648: /* original 5cfc, guest PC 0x0c093648 */
if(!s->budget--) { s->failed_pc=0x0c093648u; return 0; }
r[12]=read(ram,r[15]+48,4);
goto P_0c09364a;
P_0c09364a: /* original 62c2, guest PC 0x0c09364a */
if(!s->budget--) { s->failed_pc=0x0c09364au; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c09364c;
P_0c09364c: /* original 2239, guest PC 0x0c09364c */
if(!s->budget--) { s->failed_pc=0x0c09364cu; return 0; }
r[2]&=r[3];
goto P_0c09364e;
P_0c09364e: /* original 2c22, guest PC 0x0c09364e */
if(!s->budget--) { s->failed_pc=0x0c09364eu; return 0; }
write(ram,r[12],r[2],4);
goto P_0c093650;
P_0c093650: /* original 8548, guest PC 0x0c093650 */
if(!s->budget--) { s->failed_pc=0x0c093650u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+16,2);
goto P_0c093652;
P_0c093652: /* original 600d, guest PC 0x0c093652 */
if(!s->budget--) { s->failed_pc=0x0c093652u; return 0; }
r[0]=r[0]&65535u;
goto P_0c093654;
P_0c093654: /* original c801, guest PC 0x0c093654 */
if(!s->budget--) { s->failed_pc=0x0c093654u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c093656;
P_0c093656: /* original 8d0a, guest PC 0x0c093656 */
if(!s->budget--) { s->failed_pc=0x0c093656u; return 0; }
cond=r[17]&1u;
r[14]=r[6];
if(cond) { goto P_0c09366e; }
goto P_0c09365a;
P_0c093658: /* original 6e63, guest PC 0x0c093658 */
if(!s->budget--) { s->failed_pc=0x0c093658u; return 0; }
r[14]=r[6];
goto P_0c09365a;
P_0c09365a: /* original e036, guest PC 0x0c09365a */
if(!s->budget--) { s->failed_pc=0x0c09365au; return 0; }
r[0]=0x00000036u;
goto P_0c09365c;
P_0c09365c: /* original 045c, guest PC 0x0c09365c */
if(!s->budget--) { s->failed_pc=0x0c09365cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c09365e;
P_0c09365e: /* original 604c, guest PC 0x0c09365e */
if(!s->budget--) { s->failed_pc=0x0c09365eu; return 0; }
r[0]=r[4]&255u;
goto P_0c093660;
P_0c093660: /* original 8809, guest PC 0x0c093660 */
if(!s->budget--) { s->failed_pc=0x0c093660u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c093662;
P_0c093662: /* original 8d41, guest PC 0x0c093662 */
if(!s->budget--) { s->failed_pc=0x0c093662u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0936e8; }
goto P_0c093666;
P_0c093664: /* original 6403, guest PC 0x0c093664 */
if(!s->budget--) { s->failed_pc=0x0c093664u; return 0; }
r[4]=r[0];
goto P_0c093666;
P_0c093666: /* original 2448, guest PC 0x0c093666 */
if(!s->budget--) { s->failed_pc=0x0c093666u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c093668;
P_0c093668: /* original 893e, guest PC 0x0c093668 */
if(!s->budget--) { s->failed_pc=0x0c093668u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0936e8; }
goto P_0c09366a;
P_0c09366a: /* original a03d, guest PC 0x0c09366a */
if(!s->budget--) { s->failed_pc=0x0c09366au; return 0; }
r[4]=0x00000006u;
goto P_0c0936e8;
P_0c09366c: /* original e406, guest PC 0x0c09366c */
if(!s->budget--) { s->failed_pc=0x0c09366cu; return 0; }
r[4]=0x00000006u;
goto P_0c09366e;
P_0c09366e: /* original 9071, guest PC 0x0c09366e */
if(!s->budget--) { s->failed_pc=0x0c09366eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093754u,2);
goto P_0c093670;
P_0c093670: /* original f446, guest PC 0x0c093670 */
if(!s->budget--) { s->failed_pc=0x0c093670u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c093672;
P_0c093672: /* original e004, guest PC 0x0c093672 */
if(!s->budget--) { s->failed_pc=0x0c093672u; return 0; }
r[0]=0x00000004u;
goto P_0c093674;
P_0c093674: /* original f3e6, guest PC 0x0c093674 */
if(!s->budget--) { s->failed_pc=0x0c093674u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c093676;
P_0c093676: /* original f435, guest PC 0x0c093676 */
if(!s->budget--) { s->failed_pc=0x0c093676u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c093678;
P_0c093678: /* original 8b33, guest PC 0x0c093678 */
if(!s->budget--) { s->failed_pc=0x0c093678u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0936e2; }
goto P_0c09367a;
P_0c09367a: /* original f576, guest PC 0x0c09367a */
if(!s->budget--) { s->failed_pc=0x0c09367au; return 0; }
vf3_matrix_load(s,ram,5,r[7]+r[0]);
goto P_0c09367c;
P_0c09367c: /* original e024, guest PC 0x0c09367c */
if(!s->budget--) { s->failed_pc=0x0c09367cu; return 0; }
r[0]=0x00000024u;
goto P_0c09367e;
P_0c09367e: /* original f656, guest PC 0x0c09367e */
if(!s->budget--) { s->failed_pc=0x0c09367eu; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c093680;
P_0c093680: /* original c735, guest PC 0x0c093680 */
if(!s->budget--) { s->failed_pc=0x0c093680u; return 0; }
r[0]=code_base|0x00093758u;
goto P_0c093682;
P_0c093682: /* original f541, guest PC 0x0c093682 */
if(!s->budget--) { s->failed_pc=0x0c093682u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'-');
goto P_0c093684;
P_0c093684: /* original f908, guest PC 0x0c093684 */
if(!s->budget--) { s->failed_pc=0x0c093684u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c093686;
P_0c093686: /* original f36c, guest PC 0x0c093686 */
if(!s->budget--) { s->failed_pc=0x0c093686u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c093688;
P_0c093688: /* original f362, guest PC 0x0c093688 */
if(!s->budget--) { s->failed_pc=0x0c093688u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c09368a;
P_0c09368a: /* original f25c, guest PC 0x0c09368a */
if(!s->budget--) { s->failed_pc=0x0c09368au; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c09368c;
P_0c09368c: /* original f252, guest PC 0x0c09368c */
if(!s->budget--) { s->failed_pc=0x0c09368cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'*');
goto P_0c09368e;
P_0c09368e: /* original f53c, guest PC 0x0c09368e */
if(!s->budget--) { s->failed_pc=0x0c09368eu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c093690;
P_0c093690: /* original f521, guest PC 0x0c093690 */
if(!s->budget--) { s->failed_pc=0x0c093690u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'-');
goto P_0c093692;
P_0c093692: /* original f955, guest PC 0x0c093692 */
if(!s->budget--) { s->failed_pc=0x0c093692u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[5]))!=0);
goto P_0c093694;
P_0c093694: /* original 8f02, guest PC 0x0c093694 */
if(!s->budget--) { s->failed_pc=0x0c093694u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,3,r[7]);
if(!cond) { goto P_0c09369c; }
goto P_0c093698;
P_0c093696: /* original f378, guest PC 0x0c093696 */
if(!s->budget--) { s->failed_pc=0x0c093696u; return 0; }
vf3_matrix_load(s,ram,3,r[7]);
goto P_0c093698;
P_0c093698: /* original a002, guest PC 0x0c093698 */
if(!s->budget--) { s->failed_pc=0x0c093698u; return 0; }
fr[6]=0;
goto P_0c0936a0;
P_0c09369a: /* original f68d, guest PC 0x0c09369a */
if(!s->budget--) { s->failed_pc=0x0c09369au; return 0; }
fr[6]=0;
goto P_0c09369c;
P_0c09369c: /* original f65c, guest PC 0x0c09369c */
if(!s->budget--) { s->failed_pc=0x0c09369cu; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c09369e;
P_0c09369e: /* original f66d, guest PC 0x0c09369e */
if(!s->budget--) { s->failed_pc=0x0c09369eu; return 0; }
fr[6]=vf3_fpu_sqrt(fr[6],r[18]);
goto P_0c0936a0;
P_0c0936a0: /* original f5e8, guest PC 0x0c0936a0 */
if(!s->budget--) { s->failed_pc=0x0c0936a0u; return 0; }
vf3_matrix_load(s,ram,5,r[14]);
goto P_0c0936a2;
P_0c0936a2: /* original e008, guest PC 0x0c0936a2 */
if(!s->budget--) { s->failed_pc=0x0c0936a2u; return 0; }
r[0]=0x00000008u;
goto P_0c0936a4;
P_0c0936a4: /* original f7e6, guest PC 0x0c0936a4 */
if(!s->budget--) { s->failed_pc=0x0c0936a4u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0936a6;
P_0c0936a6: /* original f531, guest PC 0x0c0936a6 */
if(!s->budget--) { s->failed_pc=0x0c0936a6u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c0936a8;
P_0c0936a8: /* original f376, guest PC 0x0c0936a8 */
if(!s->budget--) { s->failed_pc=0x0c0936a8u; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c0936aa;
P_0c0936aa: /* original f731, guest PC 0x0c0936aa */
if(!s->budget--) { s->failed_pc=0x0c0936aau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c0936ac;
P_0c0936ac: /* original f35c, guest PC 0x0c0936ac */
if(!s->budget--) { s->failed_pc=0x0c0936acu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0936ae;
P_0c0936ae: /* original f352, guest PC 0x0c0936ae */
if(!s->budget--) { s->failed_pc=0x0c0936aeu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c0936b0;
P_0c0936b0: /* original f07c, guest PC 0x0c0936b0 */
if(!s->budget--) { s->failed_pc=0x0c0936b0u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c0936b2;
P_0c0936b2: /* original f37e, guest PC 0x0c0936b2 */
if(!s->budget--) { s->failed_pc=0x0c0936b2u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[7],fr[3],r[18]);
goto P_0c0936b4;
P_0c0936b4: /* original f935, guest PC 0x0c0936b4 */
if(!s->budget--) { s->failed_pc=0x0c0936b4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[3]))!=0);
goto P_0c0936b6;
P_0c0936b6: /* original 8f02, guest PC 0x0c0936b6 */
if(!s->budget--) { s->failed_pc=0x0c0936b6u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,8,3);
if(!cond) { goto P_0c0936be; }
goto P_0c0936ba;
P_0c0936b8: /* original f83c, guest PC 0x0c0936b8 */
if(!s->budget--) { s->failed_pc=0x0c0936b8u; return 0; }
vf3_matrix_move(s,8,3);
goto P_0c0936ba;
P_0c0936ba: /* original a002, guest PC 0x0c0936ba */
if(!s->budget--) { s->failed_pc=0x0c0936bau; return 0; }
fr[3]=0;
goto P_0c0936c2;
P_0c0936bc: /* original f38d, guest PC 0x0c0936bc */
if(!s->budget--) { s->failed_pc=0x0c0936bcu; return 0; }
fr[3]=0;
goto P_0c0936be;
P_0c0936be: /* original f38c, guest PC 0x0c0936be */
if(!s->budget--) { s->failed_pc=0x0c0936beu; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c0936c0;
P_0c0936c0: /* original f37d, guest PC 0x0c0936c0 */
if(!s->budget--) { s->failed_pc=0x0c0936c0u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0936c2;
P_0c0936c2: /* original f632, guest PC 0x0c0936c2 */
if(!s->budget--) { s->failed_pc=0x0c0936c2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c0936c4;
P_0c0936c4: /* original f378, guest PC 0x0c0936c4 */
if(!s->budget--) { s->failed_pc=0x0c0936c4u; return 0; }
vf3_matrix_load(s,ram,3,r[7]);
goto P_0c0936c6;
P_0c0936c6: /* original f05c, guest PC 0x0c0936c6 */
if(!s->budget--) { s->failed_pc=0x0c0936c6u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0936c8;
P_0c0936c8: /* original f36e, guest PC 0x0c0936c8 */
if(!s->budget--) { s->failed_pc=0x0c0936c8u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[6],fr[3],r[18]);
goto P_0c0936ca;
P_0c0936ca: /* original fe3a, guest PC 0x0c0936ca */
if(!s->budget--) { s->failed_pc=0x0c0936cau; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c0936cc;
P_0c0936cc: /* original f276, guest PC 0x0c0936cc */
if(!s->budget--) { s->failed_pc=0x0c0936ccu; return 0; }
vf3_matrix_load(s,ram,2,r[7]+r[0]);
goto P_0c0936ce;
P_0c0936ce: /* original f06c, guest PC 0x0c0936ce */
if(!s->budget--) { s->failed_pc=0x0c0936ceu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0936d0;
P_0c0936d0: /* original f27e, guest PC 0x0c0936d0 */
if(!s->budget--) { s->failed_pc=0x0c0936d0u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[7],fr[2],r[18]);
goto P_0c0936d2;
P_0c0936d2: /* original fe27, guest PC 0x0c0936d2 */
if(!s->budget--) { s->failed_pc=0x0c0936d2u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0936d4;
P_0c0936d4: /* original e004, guest PC 0x0c0936d4 */
if(!s->budget--) { s->failed_pc=0x0c0936d4u; return 0; }
r[0]=0x00000004u;
goto P_0c0936d6;
P_0c0936d6: /* original fe47, guest PC 0x0c0936d6 */
if(!s->budget--) { s->failed_pc=0x0c0936d6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0936d8;
P_0c0936d8: /* original 933d, guest PC 0x0c0936d8 */
if(!s->budget--) { s->failed_pc=0x0c0936d8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093756u,2);
goto P_0c0936da;
P_0c0936da: /* original 62c2, guest PC 0x0c0936da */
if(!s->budget--) { s->failed_pc=0x0c0936dau; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c0936dc;
P_0c0936dc: /* original 223b, guest PC 0x0c0936dc */
if(!s->budget--) { s->failed_pc=0x0c0936dcu; return 0; }
r[2]|=r[3];
goto P_0c0936de;
P_0c0936de: /* original a031, guest PC 0x0c0936de */
if(!s->budget--) { s->failed_pc=0x0c0936deu; return 0; }
write(ram,r[12],r[2],4);
goto P_0c093744;
P_0c0936e0: /* original 2c22, guest PC 0x0c0936e0 */
if(!s->budget--) { s->failed_pc=0x0c0936e0u; return 0; }
write(ram,r[12],r[2],4);
goto P_0c0936e2;
P_0c0936e2: /* original e036, guest PC 0x0c0936e2 */
if(!s->budget--) { s->failed_pc=0x0c0936e2u; return 0; }
r[0]=0x00000036u;
goto P_0c0936e4;
P_0c0936e4: /* original 045c, guest PC 0x0c0936e4 */
if(!s->budget--) { s->failed_pc=0x0c0936e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0936e6;
P_0c0936e6: /* original 644c, guest PC 0x0c0936e6 */
if(!s->budget--) { s->failed_pc=0x0c0936e6u; return 0; }
r[4]=r[4]&255u;
goto P_0c0936e8;
P_0c0936e8: /* original 4408, guest PC 0x0c0936e8 */
if(!s->budget--) { s->failed_pc=0x0c0936e8u; return 0; }
r[4]<<=2;
goto P_0c0936ea;
P_0c0936ea: /* original db1c, guest PC 0x0c0936ea */
if(!s->budget--) { s->failed_pc=0x0c0936eau; return 0; }
r[11]=read(ram,0x0c09375cu,4);
goto P_0c0936ec;
P_0c0936ec: /* original 4408, guest PC 0x0c0936ec */
if(!s->budget--) { s->failed_pc=0x0c0936ecu; return 0; }
r[4]<<=2;
goto P_0c0936ee;
P_0c0936ee: /* original 4400, guest PC 0x0c0936ee */
if(!s->budget--) { s->failed_pc=0x0c0936eeu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0936f0;
P_0c0936f0: /* original 3b4c, guest PC 0x0c0936f0 */
if(!s->budget--) { s->failed_pc=0x0c0936f0u; return 0; }
r[11]+=r[4];
goto P_0c0936f2;
P_0c0936f2: /* original 66b5, guest PC 0x0c0936f2 */
if(!s->budget--) { s->failed_pc=0x0c0936f2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[11],2);
r[11]+=2;
r[6]=tmp;
goto P_0c0936f4;
P_0c0936f4: /* original 656f, guest PC 0x0c0936f4 */
if(!s->budget--) { s->failed_pc=0x0c0936f4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c0936f6;
P_0c0936f6: /* original 64b5, guest PC 0x0c0936f6 */
if(!s->budget--) { s->failed_pc=0x0c0936f6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[11],2);
r[11]+=2;
r[4]=tmp;
goto P_0c0936f8;
P_0c0936f8: /* original 4511, guest PC 0x0c0936f8 */
if(!s->budget--) { s->failed_pc=0x0c0936f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c0936fa;
P_0c0936fa: /* original 8f23, guest PC 0x0c0936fa */
if(!s->budget--) { s->failed_pc=0x0c0936fau; return 0; }
cond=r[17]&1u;
r[4]=r[4]&65535u;
if(!cond) { goto P_0c093744; }
goto P_0c0936fe;
P_0c0936fc: /* original 644d, guest PC 0x0c0936fc */
if(!s->budget--) { s->failed_pc=0x0c0936fcu; return 0; }
r[4]=r[4]&65535u;
goto P_0c0936fe;
P_0c0936fe: /* original 2558, guest PC 0x0c0936fe */
if(!s->budget--) { s->failed_pc=0x0c0936feu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c093700;
P_0c093700: /* original 890e, guest PC 0x0c093700 */
if(!s->budget--) { s->failed_pc=0x0c093700u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093720; }
goto P_0c093702;
P_0c093702: /* original 2fc6, guest PC 0x0c093702 */
if(!s->budget--) { s->failed_pc=0x0c093702u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093704;
P_0c093704: /* original 2f46, guest PC 0x0c093704 */
if(!s->budget--) { s->failed_pc=0x0c093704u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093706;
P_0c093706: /* original 52fd, guest PC 0x0c093706 */
if(!s->budget--) { s->failed_pc=0x0c093706u; return 0; }
r[2]=read(ram,r[15]+52,4);
goto P_0c093708;
P_0c093708: /* original 2f26, guest PC 0x0c093708 */
if(!s->budget--) { s->failed_pc=0x0c093708u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09370a;
P_0c09370a: /* original 66f3, guest PC 0x0c09370a */
if(!s->budget--) { s->failed_pc=0x0c09370au; return 0; }
r[6]=r[15];
goto P_0c09370c;
P_0c09370c: /* original 65f3, guest PC 0x0c09370c */
if(!s->budget--) { s->failed_pc=0x0c09370cu; return 0; }
r[5]=r[15];
goto P_0c09370e;
P_0c09370e: /* original 67f3, guest PC 0x0c09370e */
if(!s->budget--) { s->failed_pc=0x0c09370eu; return 0; }
r[7]=r[15];
goto P_0c093710;
P_0c093710: /* original d313, guest PC 0x0c093710 */
if(!s->budget--) { s->failed_pc=0x0c093710u; return 0; }
r[3]=read(ram,0x0c093760u,4);
goto P_0c093712;
P_0c093712: /* original 7514, guest PC 0x0c093712 */
if(!s->budget--) { s->failed_pc=0x0c093712u; return 0; }
r[5]+=0x00000014u;
goto P_0c093714;
P_0c093714: /* original 7710, guest PC 0x0c093714 */
if(!s->budget--) { s->failed_pc=0x0c093714u; return 0; }
r[7]+=0x00000010u;
goto P_0c093716;
P_0c093716: /* original 760c, guest PC 0x0c093716 */
if(!s->budget--) { s->failed_pc=0x0c093716u; return 0; }
r[6]+=0x0000000cu;
goto P_0c093718;
P_0c093718: /* original 430b, guest PC 0x0c093718 */
if(!s->budget--) { s->failed_pc=0x0c093718u; return 0; }
target=r[3];
r[16]=code_base|0x0c09371cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09371cu) { target=s->pc; goto dispatch; }
goto P_0c09371c;
P_0c09371a: /* original 64e3, guest PC 0x0c09371a */
if(!s->budget--) { s->failed_pc=0x0c09371au; return 0; }
r[4]=r[14];
goto P_0c09371c;
P_0c09371c: /* original afe9, guest PC 0x0c09371c */
if(!s->budget--) { s->failed_pc=0x0c09371cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0936f2;
P_0c09371e: /* original 7f0c, guest PC 0x0c09371e */
if(!s->budget--) { s->failed_pc=0x0c09371eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c093720;
P_0c093720: /* original 5dfa, guest PC 0x0c093720 */
if(!s->budget--) { s->failed_pc=0x0c093720u; return 0; }
r[13]=read(ram,r[15]+40,4);
goto P_0c093722;
P_0c093722: /* original e00c, guest PC 0x0c093722 */
if(!s->budget--) { s->failed_pc=0x0c093722u; return 0; }
r[0]=0x0000000cu;
goto P_0c093724;
P_0c093724: /* original 66c3, guest PC 0x0c093724 */
if(!s->budget--) { s->failed_pc=0x0c093724u; return 0; }
r[6]=r[12];
goto P_0c093726;
P_0c093726: /* original 3d4c, guest PC 0x0c093726 */
if(!s->budget--) { s->failed_pc=0x0c093726u; return 0; }
r[13]+=r[4];
goto P_0c093728;
P_0c093728: /* original f3d6, guest PC 0x0c093728 */
if(!s->budget--) { s->failed_pc=0x0c093728u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c09372a;
P_0c09372a: /* original e010, guest PC 0x0c09372a */
if(!s->budget--) { s->failed_pc=0x0c09372au; return 0; }
r[0]=0x00000010u;
goto P_0c09372c;
P_0c09372c: /* original 65d3, guest PC 0x0c09372c */
if(!s->budget--) { s->failed_pc=0x0c09372cu; return 0; }
r[5]=r[13];
goto P_0c09372e;
P_0c09372e: /* original ff3a, guest PC 0x0c09372e */
if(!s->budget--) { s->failed_pc=0x0c09372eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c093730;
P_0c093730: /* original f3d6, guest PC 0x0c093730 */
if(!s->budget--) { s->failed_pc=0x0c093730u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c093732;
P_0c093732: /* original e004, guest PC 0x0c093732 */
if(!s->budget--) { s->failed_pc=0x0c093732u; return 0; }
r[0]=0x00000004u;
goto P_0c093734;
P_0c093734: /* original ff37, guest PC 0x0c093734 */
if(!s->budget--) { s->failed_pc=0x0c093734u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c093736;
P_0c093736: /* original f4f8, guest PC 0x0c093736 */
if(!s->budget--) { s->failed_pc=0x0c093736u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c093738;
P_0c093738: /* original d30a, guest PC 0x0c093738 */
if(!s->budget--) { s->failed_pc=0x0c093738u; return 0; }
r[3]=read(ram,0x0c093764u,4);
goto P_0c09373a;
P_0c09373a: /* original f53c, guest PC 0x0c09373a */
if(!s->budget--) { s->failed_pc=0x0c09373au; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c09373c;
P_0c09373c: /* original 430b, guest PC 0x0c09373c */
if(!s->budget--) { s->failed_pc=0x0c09373cu; return 0; }
target=r[3];
r[16]=code_base|0x0c093740u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c093740u) { target=s->pc; goto dispatch; }
goto P_0c093740;
P_0c09373e: /* original 64e3, guest PC 0x0c09373e */
if(!s->budget--) { s->failed_pc=0x0c09373eu; return 0; }
r[4]=r[14];
goto P_0c093740;
P_0c093740: /* original afd7, guest PC 0x0c093740 */
if(!s->budget--) { s->failed_pc=0x0c093740u; return 0; }
goto P_0c0936f2;
P_0c093742: /* original 0009, guest PC 0x0c093742 */
if(!s->budget--) { s->failed_pc=0x0c093742u; return 0; }
goto P_0c093744;
P_0c093744: /* original 7f14, guest PC 0x0c093744 */
if(!s->budget--) { s->failed_pc=0x0c093744u; return 0; }
r[15]+=0x00000014u;
goto P_0c093746;
P_0c093746: /* original 4f26, guest PC 0x0c093746 */
if(!s->budget--) { s->failed_pc=0x0c093746u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c093748;
P_0c093748: /* original 6bf6, guest PC 0x0c093748 */
if(!s->budget--) { s->failed_pc=0x0c093748u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09374a;
P_0c09374a: /* original 6cf6, guest PC 0x0c09374a */
if(!s->budget--) { s->failed_pc=0x0c09374au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09374c;
P_0c09374c: /* original 6df6, guest PC 0x0c09374c */
if(!s->budget--) { s->failed_pc=0x0c09374cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09374e;
P_0c09374e: /* original 000b, guest PC 0x0c09374e */
if(!s->budget--) { s->failed_pc=0x0c09374eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c093750: /* original 6ef6, guest PC 0x0c093750 */
if(!s->budget--) { s->failed_pc=0x0c093750u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c093752u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c093752u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
