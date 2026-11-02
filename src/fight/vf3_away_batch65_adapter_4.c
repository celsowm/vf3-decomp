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
int vf3_away_batch65_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09302au: goto P_0c09302a;
case 0x0c09302cu: goto P_0c09302c;
case 0x0c09302eu: goto P_0c09302e;
case 0x0c093030u: goto P_0c093030;
case 0x0c093032u: goto P_0c093032;
case 0x0c093034u: goto P_0c093034;
case 0x0c093036u: goto P_0c093036;
case 0x0c093038u: goto P_0c093038;
case 0x0c09303au: goto P_0c09303a;
case 0x0c09303cu: goto P_0c09303c;
case 0x0c09303eu: goto P_0c09303e;
case 0x0c093040u: goto P_0c093040;
case 0x0c093042u: goto P_0c093042;
case 0x0c093044u: goto P_0c093044;
case 0x0c093046u: goto P_0c093046;
case 0x0c093048u: goto P_0c093048;
case 0x0c09304au: goto P_0c09304a;
case 0x0c09304cu: goto P_0c09304c;
case 0x0c09304eu: goto P_0c09304e;
case 0x0c093050u: goto P_0c093050;
case 0x0c093052u: goto P_0c093052;
case 0x0c093054u: goto P_0c093054;
case 0x0c093056u: goto P_0c093056;
case 0x0c093058u: goto P_0c093058;
case 0x0c09305au: goto P_0c09305a;
case 0x0c09305cu: goto P_0c09305c;
case 0x0c09305eu: goto P_0c09305e;
case 0x0c093060u: goto P_0c093060;
case 0x0c093062u: goto P_0c093062;
case 0x0c093064u: goto P_0c093064;
case 0x0c093066u: goto P_0c093066;
case 0x0c093068u: goto P_0c093068;
case 0x0c09306au: goto P_0c09306a;
case 0x0c09306cu: goto P_0c09306c;
case 0x0c09306eu: goto P_0c09306e;
case 0x0c093070u: goto P_0c093070;
case 0x0c093072u: goto P_0c093072;
case 0x0c093074u: goto P_0c093074;
case 0x0c093076u: goto P_0c093076;
case 0x0c093078u: goto P_0c093078;
case 0x0c09307au: goto P_0c09307a;
case 0x0c09307cu: goto P_0c09307c;
case 0x0c09307eu: goto P_0c09307e;
case 0x0c093080u: goto P_0c093080;
case 0x0c093082u: goto P_0c093082;
case 0x0c093084u: goto P_0c093084;
case 0x0c093086u: goto P_0c093086;
case 0x0c0930a4u: goto P_0c0930a4;
case 0x0c0930a6u: goto P_0c0930a6;
case 0x0c0930a8u: goto P_0c0930a8;
case 0x0c0930aau: goto P_0c0930aa;
case 0x0c0930acu: goto P_0c0930ac;
case 0x0c0930aeu: goto P_0c0930ae;
case 0x0c0930b0u: goto P_0c0930b0;
case 0x0c0930b2u: goto P_0c0930b2;
case 0x0c0930b4u: goto P_0c0930b4;
case 0x0c0930b6u: goto P_0c0930b6;
case 0x0c0930b8u: goto P_0c0930b8;
case 0x0c0930bau: goto P_0c0930ba;
case 0x0c0930bcu: goto P_0c0930bc;
case 0x0c0930beu: goto P_0c0930be;
case 0x0c0930c0u: goto P_0c0930c0;
case 0x0c0930c2u: goto P_0c0930c2;
case 0x0c0930c4u: goto P_0c0930c4;
case 0x0c0930c6u: goto P_0c0930c6;
case 0x0c0930c8u: goto P_0c0930c8;
case 0x0c0930cau: goto P_0c0930ca;
case 0x0c0930ccu: goto P_0c0930cc;
case 0x0c0930ceu: goto P_0c0930ce;
case 0x0c0930d0u: goto P_0c0930d0;
case 0x0c0930d2u: goto P_0c0930d2;
case 0x0c0930d4u: goto P_0c0930d4;
case 0x0c0930d6u: goto P_0c0930d6;
case 0x0c0930d8u: goto P_0c0930d8;
case 0x0c0930dau: goto P_0c0930da;
case 0x0c0930dcu: goto P_0c0930dc;
case 0x0c0931c8u: goto P_0c0931c8;
case 0x0c0931cau: goto P_0c0931ca;
case 0x0c0931ccu: goto P_0c0931cc;
case 0x0c0931ceu: goto P_0c0931ce;
case 0x0c0931d0u: goto P_0c0931d0;
case 0x0c0931d2u: goto P_0c0931d2;
case 0x0c0931d4u: goto P_0c0931d4;
case 0x0c0931d6u: goto P_0c0931d6;
case 0x0c0931d8u: goto P_0c0931d8;
case 0x0c0931dau: goto P_0c0931da;
case 0x0c0931dcu: goto P_0c0931dc;
case 0x0c0931deu: goto P_0c0931de;
case 0x0c0931e0u: goto P_0c0931e0;
case 0x0c0931e2u: goto P_0c0931e2;
case 0x0c0931e4u: goto P_0c0931e4;
case 0x0c0931e6u: goto P_0c0931e6;
case 0x0c0931e8u: goto P_0c0931e8;
case 0x0c0931eau: goto P_0c0931ea;
case 0x0c0931ecu: goto P_0c0931ec;
case 0x0c0931eeu: goto P_0c0931ee;
case 0x0c0931f0u: goto P_0c0931f0;
case 0x0c0931f2u: goto P_0c0931f2;
case 0x0c0931f4u: goto P_0c0931f4;
case 0x0c0931f6u: goto P_0c0931f6;
case 0x0c0931f8u: goto P_0c0931f8;
case 0x0c0931fau: goto P_0c0931fa;
case 0x0c0931fcu: goto P_0c0931fc;
case 0x0c0931feu: goto P_0c0931fe;
case 0x0c093200u: goto P_0c093200;
case 0x0c093202u: goto P_0c093202;
case 0x0c093204u: goto P_0c093204;
case 0x0c093206u: goto P_0c093206;
case 0x0c093208u: goto P_0c093208;
case 0x0c09320au: goto P_0c09320a;
case 0x0c09320cu: goto P_0c09320c;
case 0x0c09320eu: goto P_0c09320e;
case 0x0c093210u: goto P_0c093210;
case 0x0c093212u: goto P_0c093212;
case 0x0c093214u: goto P_0c093214;
case 0x0c093216u: goto P_0c093216;
case 0x0c093218u: goto P_0c093218;
case 0x0c09321au: goto P_0c09321a;
case 0x0c09321cu: goto P_0c09321c;
case 0x0c09321eu: goto P_0c09321e;
case 0x0c093220u: goto P_0c093220;
case 0x0c093222u: goto P_0c093222;
case 0x0c093224u: goto P_0c093224;
case 0x0c093226u: goto P_0c093226;
case 0x0c093228u: goto P_0c093228;
case 0x0c09322au: goto P_0c09322a;
case 0x0c09322cu: goto P_0c09322c;
case 0x0c09322eu: goto P_0c09322e;
case 0x0c093230u: goto P_0c093230;
case 0x0c093232u: goto P_0c093232;
case 0x0c093234u: goto P_0c093234;
case 0x0c093236u: goto P_0c093236;
case 0x0c093238u: goto P_0c093238;
case 0x0c09323au: goto P_0c09323a;
case 0x0c09323cu: goto P_0c09323c;
case 0x0c09323eu: goto P_0c09323e;
case 0x0c093240u: goto P_0c093240;
case 0x0c093242u: goto P_0c093242;
case 0x0c093244u: goto P_0c093244;
case 0x0c093246u: goto P_0c093246;
case 0x0c093248u: goto P_0c093248;
case 0x0c09324au: goto P_0c09324a;
case 0x0c09324cu: goto P_0c09324c;
case 0x0c09324eu: goto P_0c09324e;
case 0x0c093250u: goto P_0c093250;
case 0x0c093252u: goto P_0c093252;
case 0x0c093254u: goto P_0c093254;
case 0x0c093256u: goto P_0c093256;
case 0x0c093258u: goto P_0c093258;
case 0x0c09325au: goto P_0c09325a;
case 0x0c09325cu: goto P_0c09325c;
case 0x0c09325eu: goto P_0c09325e;
case 0x0c093260u: goto P_0c093260;
case 0x0c093262u: goto P_0c093262;
case 0x0c093264u: goto P_0c093264;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c09302a: /* original e010, guest PC 0x0c09302a */
if(!s->budget--) { s->failed_pc=0x0c09302au; return 0; }
r[0]=0x00000010u;
goto P_0c09302c;
P_0c09302c: /* original fffb, guest PC 0x0c09302c */
if(!s->budget--) { s->failed_pc=0x0c09302cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09302e;
P_0c09302e: /* original 7ff0, guest PC 0x0c09302e */
if(!s->budget--) { s->failed_pc=0x0c09302eu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c093030;
P_0c093030: /* original 2f42, guest PC 0x0c093030 */
if(!s->budget--) { s->failed_pc=0x0c093030u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c093032;
P_0c093032: /* original ff66, guest PC 0x0c093032 */
if(!s->budget--) { s->failed_pc=0x0c093032u; return 0; }
vf3_matrix_load(s,ram,15,r[6]+r[0]);
goto P_0c093034;
P_0c093034: /* original f38d, guest PC 0x0c093034 */
if(!s->budget--) { s->failed_pc=0x0c093034u; return 0; }
fr[3]=0;
goto P_0c093036;
P_0c093036: /* original ff34, guest PC 0x0c093036 */
if(!s->budget--) { s->failed_pc=0x0c093036u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])==as_float(fr[3]))!=0);
goto P_0c093038;
P_0c093038: /* original 8b02, guest PC 0x0c093038 */
if(!s->budget--) { s->failed_pc=0x0c093038u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c093040; }
goto P_0c09303a;
P_0c09303a: /* original d316, guest PC 0x0c09303a */
if(!s->budget--) { s->failed_pc=0x0c09303au; return 0; }
r[3]=read(ram,0x0c093094u,4);
goto P_0c09303c;
P_0c09303c: /* original 432b, guest PC 0x0c09303c */
if(!s->budget--) { s->failed_pc=0x0c09303cu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0930d8u: goto P_0c0930d8;
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
P_0c09303e: /* original 0009, guest PC 0x0c09303e */
if(!s->budget--) { s->failed_pc=0x0c09303eu; return 0; }
goto P_0c093040;
P_0c093040: /* original e048, guest PC 0x0c093040 */
if(!s->budget--) { s->failed_pc=0x0c093040u; return 0; }
r[0]=0x00000048u;
goto P_0c093042;
P_0c093042: /* original d313, guest PC 0x0c093042 */
if(!s->budget--) { s->failed_pc=0x0c093042u; return 0; }
r[3]=read(ram,0x0c093090u,4);
goto P_0c093044;
P_0c093044: /* original 025e, guest PC 0x0c093044 */
if(!s->budget--) { s->failed_pc=0x0c093044u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c093046;
P_0c093046: /* original 2238, guest PC 0x0c093046 */
if(!s->budget--) { s->failed_pc=0x0c093046u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c093048;
P_0c093048: /* original 8903, guest PC 0x0c093048 */
if(!s->budget--) { s->failed_pc=0x0c093048u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093052; }
goto P_0c09304a;
P_0c09304a: /* original c713, guest PC 0x0c09304a */
if(!s->budget--) { s->failed_pc=0x0c09304au; return 0; }
r[0]=code_base|0x00093098u;
goto P_0c09304c;
P_0c09304c: /* original f308, guest PC 0x0c09304c */
if(!s->budget--) { s->failed_pc=0x0c09304cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09304e;
P_0c09304e: /* original a014, guest PC 0x0c09304e */
if(!s->budget--) { s->failed_pc=0x0c09304eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c09307a;
P_0c093050: /* original ff32, guest PC 0x0c093050 */
if(!s->budget--) { s->failed_pc=0x0c093050u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c093052;
P_0c093052: /* original c712, guest PC 0x0c093052 */
if(!s->budget--) { s->failed_pc=0x0c093052u; return 0; }
r[0]=code_base|0x0009309cu;
goto P_0c093054;
P_0c093054: /* original f308, guest PC 0x0c093054 */
if(!s->budget--) { s->failed_pc=0x0c093054u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c093056;
P_0c093056: /* original 60f2, guest PC 0x0c093056 */
if(!s->budget--) { s->failed_pc=0x0c093056u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c093058;
P_0c093058: /* original 8508, guest PC 0x0c093058 */
if(!s->budget--) { s->failed_pc=0x0c093058u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[0]+16,2);
goto P_0c09305a;
P_0c09305a: /* original 600d, guest PC 0x0c09305a */
if(!s->budget--) { s->failed_pc=0x0c09305au; return 0; }
r[0]=r[0]&65535u;
goto P_0c09305c;
P_0c09305c: /* original c801, guest PC 0x0c09305c */
if(!s->budget--) { s->failed_pc=0x0c09305cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c09305e;
P_0c09305e: /* original 8f0c, guest PC 0x0c09305e */
if(!s->budget--) { s->failed_pc=0x0c09305eu; return 0; }
cond=r[17]&1u;
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
if(!cond) { goto P_0c09307a; }
goto P_0c093062;
P_0c093060: /* original ff32, guest PC 0x0c093060 */
if(!s->budget--) { s->failed_pc=0x0c093060u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c093062;
P_0c093062: /* original 9111, guest PC 0x0c093062 */
if(!s->budget--) { s->failed_pc=0x0c093062u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093088u,2);
goto P_0c093064;
P_0c093064: /* original 2178, guest PC 0x0c093064 */
if(!s->budget--) { s->failed_pc=0x0c093064u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[7])==0)!=0);
goto P_0c093066;
P_0c093066: /* original 8902, guest PC 0x0c093066 */
if(!s->budget--) { s->failed_pc=0x0c093066u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09306e; }
goto P_0c093068;
P_0c093068: /* original d20a, guest PC 0x0c093068 */
if(!s->budget--) { s->failed_pc=0x0c093068u; return 0; }
r[2]=read(ram,0x0c093094u,4);
goto P_0c09306a;
P_0c09306a: /* original 422b, guest PC 0x0c09306a */
if(!s->budget--) { s->failed_pc=0x0c09306au; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0930d8u: goto P_0c0930d8;
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
P_0c09306c: /* original 0009, guest PC 0x0c09306c */
if(!s->budget--) { s->failed_pc=0x0c09306cu; return 0; }
goto P_0c09306e;
P_0c09306e: /* original 930c, guest PC 0x0c09306e */
if(!s->budget--) { s->failed_pc=0x0c09306eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09308au,2);
goto P_0c093070;
P_0c093070: /* original 2738, guest PC 0x0c093070 */
if(!s->budget--) { s->failed_pc=0x0c093070u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[3])==0)!=0);
goto P_0c093072;
P_0c093072: /* original 8902, guest PC 0x0c093072 */
if(!s->budget--) { s->failed_pc=0x0c093072u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09307a; }
goto P_0c093074;
P_0c093074: /* original c70a, guest PC 0x0c093074 */
if(!s->budget--) { s->failed_pc=0x0c093074u; return 0; }
r[0]=code_base|0x000930a0u;
goto P_0c093076;
P_0c093076: /* original f308, guest PC 0x0c093076 */
if(!s->budget--) { s->failed_pc=0x0c093076u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c093078;
P_0c093078: /* original ff32, guest PC 0x0c093078 */
if(!s->budget--) { s->failed_pc=0x0c093078u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c09307a;
P_0c09307a: /* original 65f2, guest PC 0x0c09307a */
if(!s->budget--) { s->failed_pc=0x0c09307au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c09307c;
P_0c09307c: /* original 64f3, guest PC 0x0c09307c */
if(!s->budget--) { s->failed_pc=0x0c09307cu; return 0; }
r[4]=r[15];
goto P_0c09307e;
P_0c09307e: /* original 7404, guest PC 0x0c09307e */
if(!s->budget--) { s->failed_pc=0x0c09307eu; return 0; }
r[4]+=0x00000004u;
goto P_0c093080;
P_0c093080: /* original f4fc, guest PC 0x0c093080 */
if(!s->budget--) { s->failed_pc=0x0c093080u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c093082;
P_0c093082: /* original 755c, guest PC 0x0c093082 */
if(!s->budget--) { s->failed_pc=0x0c093082u; return 0; }
r[5]+=0x0000005cu;
goto P_0c093084;
P_0c093084: /* original a00e, guest PC 0x0c093084 */
if(!s->budget--) { s->failed_pc=0x0c093084u; return 0; }
goto P_0c0930a4;
P_0c093086: /* original 0009, guest PC 0x0c093086 */
if(!s->budget--) { s->failed_pc=0x0c093086u; return 0; }
if(!vf3_matrix_family(0x0c093088u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c093088u; return 0; } return 1;
P_0c0930a4: /* original f059, guest PC 0x0c0930a4 */
if(!s->budget--) { s->failed_pc=0x0c0930a4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0930a6;
P_0c0930a6: /* original f159, guest PC 0x0c0930a6 */
if(!s->budget--) { s->failed_pc=0x0c0930a6u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0930a8;
P_0c0930a8: /* original f259, guest PC 0x0c0930a8 */
if(!s->budget--) { s->failed_pc=0x0c0930a8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0930aa;
P_0c0930aa: /* original 740c, guest PC 0x0c0930aa */
if(!s->budget--) { s->failed_pc=0x0c0930aau; return 0; }
r[4]+=0x0000000cu;
goto P_0c0930ac;
P_0c0930ac: /* original f242, guest PC 0x0c0930ac */
if(!s->budget--) { s->failed_pc=0x0c0930acu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c0930ae;
P_0c0930ae: /* original f142, guest PC 0x0c0930ae */
if(!s->budget--) { s->failed_pc=0x0c0930aeu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c0930b0;
P_0c0930b0: /* original f042, guest PC 0x0c0930b0 */
if(!s->budget--) { s->failed_pc=0x0c0930b0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c0930b2;
P_0c0930b2: /* original f42b, guest PC 0x0c0930b2 */
if(!s->budget--) { s->failed_pc=0x0c0930b2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0930b4;
P_0c0930b4: /* original f41b, guest PC 0x0c0930b4 */
if(!s->budget--) { s->failed_pc=0x0c0930b4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0930b6;
P_0c0930b6: /* original f40b, guest PC 0x0c0930b6 */
if(!s->budget--) { s->failed_pc=0x0c0930b6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0930b8;
P_0c0930b8: /* original 54f5, guest PC 0x0c0930b8 */
if(!s->budget--) { s->failed_pc=0x0c0930b8u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c0930ba;
P_0c0930ba: /* original 65f3, guest PC 0x0c0930ba */
if(!s->budget--) { s->failed_pc=0x0c0930bau; return 0; }
r[5]=r[15];
goto P_0c0930bc;
P_0c0930bc: /* original 7504, guest PC 0x0c0930bc */
if(!s->budget--) { s->failed_pc=0x0c0930bcu; return 0; }
r[5]+=0x00000004u;
goto P_0c0930be;
P_0c0930be: /* original f049, guest PC 0x0c0930be */
if(!s->budget--) { s->failed_pc=0x0c0930beu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0930c0;
P_0c0930c0: /* original f359, guest PC 0x0c0930c0 */
if(!s->budget--) { s->failed_pc=0x0c0930c0u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0930c2;
P_0c0930c2: /* original f149, guest PC 0x0c0930c2 */
if(!s->budget--) { s->failed_pc=0x0c0930c2u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0930c4;
P_0c0930c4: /* original f459, guest PC 0x0c0930c4 */
if(!s->budget--) { s->failed_pc=0x0c0930c4u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0930c6;
P_0c0930c6: /* original f249, guest PC 0x0c0930c6 */
if(!s->budget--) { s->failed_pc=0x0c0930c6u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0930c8;
P_0c0930c8: /* original f559, guest PC 0x0c0930c8 */
if(!s->budget--) { s->failed_pc=0x0c0930c8u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0930ca;
P_0c0930ca: /* original f030, guest PC 0x0c0930ca */
if(!s->budget--) { s->failed_pc=0x0c0930cau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c0930cc;
P_0c0930cc: /* original f250, guest PC 0x0c0930cc */
if(!s->budget--) { s->failed_pc=0x0c0930ccu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c0930ce;
P_0c0930ce: /* original f140, guest PC 0x0c0930ce */
if(!s->budget--) { s->failed_pc=0x0c0930ceu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c0930d0;
P_0c0930d0: /* original f42b, guest PC 0x0c0930d0 */
if(!s->budget--) { s->failed_pc=0x0c0930d0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0930d2;
P_0c0930d2: /* original f41b, guest PC 0x0c0930d2 */
if(!s->budget--) { s->failed_pc=0x0c0930d2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0930d4;
P_0c0930d4: /* original f40b, guest PC 0x0c0930d4 */
if(!s->budget--) { s->failed_pc=0x0c0930d4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0930d6;
P_0c0930d6: /* original 0009, guest PC 0x0c0930d6 */
if(!s->budget--) { s->failed_pc=0x0c0930d6u; return 0; }
goto P_0c0930d8;
P_0c0930d8: /* original 7f10, guest PC 0x0c0930d8 */
if(!s->budget--) { s->failed_pc=0x0c0930d8u; return 0; }
r[15]+=0x00000010u;
goto P_0c0930da;
P_0c0930da: /* original 000b, guest PC 0x0c0930da */
if(!s->budget--) { s->failed_pc=0x0c0930dau; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c0930dc: /* original fff9, guest PC 0x0c0930dc */
if(!s->budget--) { s->failed_pc=0x0c0930dcu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c0930deu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0930deu; return 0; } return 1;
P_0c0931c8: /* original e040, guest PC 0x0c0931c8 */
if(!s->budget--) { s->failed_pc=0x0c0931c8u; return 0; }
r[0]=0x00000040u;
goto P_0c0931ca;
P_0c0931ca: /* original f38d, guest PC 0x0c0931ca */
if(!s->budget--) { s->failed_pc=0x0c0931cau; return 0; }
fr[3]=0;
goto P_0c0931cc;
P_0c0931cc: /* original f646, guest PC 0x0c0931cc */
if(!s->budget--) { s->failed_pc=0x0c0931ccu; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c0931ce;
P_0c0931ce: /* original f634, guest PC 0x0c0931ce */
if(!s->budget--) { s->failed_pc=0x0c0931ceu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])==as_float(fr[3]))!=0);
goto P_0c0931d0;
P_0c0931d0: /* original 8931, guest PC 0x0c0931d0 */
if(!s->budget--) { s->failed_pc=0x0c0931d0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093236; }
goto P_0c0931d2;
P_0c0931d2: /* original e034, guest PC 0x0c0931d2 */
if(!s->budget--) { s->failed_pc=0x0c0931d2u; return 0; }
r[0]=0x00000034u;
goto P_0c0931d4;
P_0c0931d4: /* original d638, guest PC 0x0c0931d4 */
if(!s->budget--) { s->failed_pc=0x0c0931d4u; return 0; }
r[6]=read(ram,0x0c0932b8u,4);
goto P_0c0931d6;
P_0c0931d6: /* original f446, guest PC 0x0c0931d6 */
if(!s->budget--) { s->failed_pc=0x0c0931d6u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0931d8;
P_0c0931d8: /* original e038, guest PC 0x0c0931d8 */
if(!s->budget--) { s->failed_pc=0x0c0931d8u; return 0; }
r[0]=0x00000038u;
goto P_0c0931da;
P_0c0931da: /* original f746, guest PC 0x0c0931da */
if(!s->budget--) { s->failed_pc=0x0c0931dau; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c0931dc;
P_0c0931dc: /* original e03c, guest PC 0x0c0931dc */
if(!s->budget--) { s->failed_pc=0x0c0931dcu; return 0; }
r[0]=0x0000003cu;
goto P_0c0931de;
P_0c0931de: /* original f546, guest PC 0x0c0931de */
if(!s->budget--) { s->failed_pc=0x0c0931deu; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0931e0;
P_0c0931e0: /* original 8548, guest PC 0x0c0931e0 */
if(!s->budget--) { s->failed_pc=0x0c0931e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+16,2);
goto P_0c0931e2;
P_0c0931e2: /* original 600d, guest PC 0x0c0931e2 */
if(!s->budget--) { s->failed_pc=0x0c0931e2u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0931e4;
P_0c0931e4: /* original c801, guest PC 0x0c0931e4 */
if(!s->budget--) { s->failed_pc=0x0c0931e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0931e6;
P_0c0931e6: /* original 8916, guest PC 0x0c0931e6 */
if(!s->budget--) { s->failed_pc=0x0c0931e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093216; }
goto P_0c0931e8;
P_0c0931e8: /* original 8454, guest PC 0x0c0931e8 */
if(!s->budget--) { s->failed_pc=0x0c0931e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+4,1);
goto P_0c0931ea;
P_0c0931ea: /* original 2008, guest PC 0x0c0931ea */
if(!s->budget--) { s->failed_pc=0x0c0931eau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0931ec;
P_0c0931ec: /* original 8d01, guest PC 0x0c0931ec */
if(!s->budget--) { s->failed_pc=0x0c0931ecu; return 0; }
cond=r[17]&1u;
r[0]=0x00000061u;
if(cond) { goto P_0c0931f2; }
goto P_0c0931f0;
P_0c0931ee: /* original e061, guest PC 0x0c0931ee */
if(!s->budget--) { s->failed_pc=0x0c0931eeu; return 0; }
r[0]=0x00000061u;
goto P_0c0931f0;
P_0c0931f0: /* original f44d, guest PC 0x0c0931f0 */
if(!s->budget--) { s->failed_pc=0x0c0931f0u; return 0; }
fr[4]^=0x80000000u;
goto P_0c0931f2;
P_0c0931f2: /* original 005c, guest PC 0x0c0931f2 */
if(!s->budget--) { s->failed_pc=0x0c0931f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0931f4;
P_0c0931f4: /* original 600c, guest PC 0x0c0931f4 */
if(!s->budget--) { s->failed_pc=0x0c0931f4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0931f6;
P_0c0931f6: /* original 880b, guest PC 0x0c0931f6 */
if(!s->budget--) { s->failed_pc=0x0c0931f6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0931f8;
P_0c0931f8: /* original 8f02, guest PC 0x0c0931f8 */
if(!s->budget--) { s->failed_pc=0x0c0931f8u; return 0; }
cond=r[17]&1u;
r[0]=0x00000060u;
if(!cond) { goto P_0c093200; }
goto P_0c0931fc;
P_0c0931fa: /* original e060, guest PC 0x0c0931fa */
if(!s->budget--) { s->failed_pc=0x0c0931fau; return 0; }
r[0]=0x00000060u;
goto P_0c0931fc;
P_0c0931fc: /* original f54d, guest PC 0x0c0931fc */
if(!s->budget--) { s->failed_pc=0x0c0931fcu; return 0; }
fr[5]^=0x80000000u;
goto P_0c0931fe;
P_0c0931fe: /* original f44d, guest PC 0x0c0931fe */
if(!s->budget--) { s->failed_pc=0x0c0931feu; return 0; }
fr[4]^=0x80000000u;
goto P_0c093200;
P_0c093200: /* original 025c, guest PC 0x0c093200 */
if(!s->budget--) { s->failed_pc=0x0c093200u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c093202;
P_0c093202: /* original 6563, guest PC 0x0c093202 */
if(!s->budget--) { s->failed_pc=0x0c093202u; return 0; }
r[5]=r[6];
goto P_0c093204;
P_0c093204: /* original 622c, guest PC 0x0c093204 */
if(!s->budget--) { s->failed_pc=0x0c093204u; return 0; }
r[2]=r[2]&255u;
goto P_0c093206;
P_0c093206: /* original 6323, guest PC 0x0c093206 */
if(!s->budget--) { s->failed_pc=0x0c093206u; return 0; }
r[3]=r[2];
goto P_0c093208;
P_0c093208: /* original 4200, guest PC 0x0c093208 */
if(!s->budget--) { s->failed_pc=0x0c093208u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c09320a;
P_0c09320a: /* original 323c, guest PC 0x0c09320a */
if(!s->budget--) { s->failed_pc=0x0c09320au; return 0; }
r[2]+=r[3];
goto P_0c09320c;
P_0c09320c: /* original 4208, guest PC 0x0c09320c */
if(!s->budget--) { s->failed_pc=0x0c09320cu; return 0; }
r[2]<<=2;
goto P_0c09320e;
P_0c09320e: /* original 622f, guest PC 0x0c09320e */
if(!s->budget--) { s->failed_pc=0x0c09320eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c093210;
P_0c093210: /* original 352c, guest PC 0x0c093210 */
if(!s->budget--) { s->failed_pc=0x0c093210u; return 0; }
r[5]+=r[2];
goto P_0c093212;
P_0c093212: /* original a00b, guest PC 0x0c093212 */
if(!s->budget--) { s->failed_pc=0x0c093212u; return 0; }
r[0]=0x00000004u;
goto P_0c09322c;
P_0c093214: /* original e004, guest PC 0x0c093214 */
if(!s->budget--) { s->failed_pc=0x0c093214u; return 0; }
r[0]=0x00000004u;
goto P_0c093216;
P_0c093216: /* original e060, guest PC 0x0c093216 */
if(!s->budget--) { s->failed_pc=0x0c093216u; return 0; }
r[0]=0x00000060u;
goto P_0c093218;
P_0c093218: /* original 025c, guest PC 0x0c093218 */
if(!s->budget--) { s->failed_pc=0x0c093218u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c09321a;
P_0c09321a: /* original 6563, guest PC 0x0c09321a */
if(!s->budget--) { s->failed_pc=0x0c09321au; return 0; }
r[5]=r[6];
goto P_0c09321c;
P_0c09321c: /* original e008, guest PC 0x0c09321c */
if(!s->budget--) { s->failed_pc=0x0c09321cu; return 0; }
r[0]=0x00000008u;
goto P_0c09321e;
P_0c09321e: /* original 622c, guest PC 0x0c09321e */
if(!s->budget--) { s->failed_pc=0x0c09321eu; return 0; }
r[2]=r[2]&255u;
goto P_0c093220;
P_0c093220: /* original 6323, guest PC 0x0c093220 */
if(!s->budget--) { s->failed_pc=0x0c093220u; return 0; }
r[3]=r[2];
goto P_0c093222;
P_0c093222: /* original 4200, guest PC 0x0c093222 */
if(!s->budget--) { s->failed_pc=0x0c093222u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c093224;
P_0c093224: /* original 323c, guest PC 0x0c093224 */
if(!s->budget--) { s->failed_pc=0x0c093224u; return 0; }
r[2]+=r[3];
goto P_0c093226;
P_0c093226: /* original 4208, guest PC 0x0c093226 */
if(!s->budget--) { s->failed_pc=0x0c093226u; return 0; }
r[2]<<=2;
goto P_0c093228;
P_0c093228: /* original 622f, guest PC 0x0c093228 */
if(!s->budget--) { s->failed_pc=0x0c093228u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c09322a;
P_0c09322a: /* original 352c, guest PC 0x0c09322a */
if(!s->budget--) { s->failed_pc=0x0c09322au; return 0; }
r[5]+=r[2];
goto P_0c09322c;
P_0c09322c: /* original f856, guest PC 0x0c09322c */
if(!s->budget--) { s->failed_pc=0x0c09322cu; return 0; }
vf3_matrix_load(s,ram,8,r[5]+r[0]);
goto P_0c09322e;
P_0c09322e: /* original f582, guest PC 0x0c09322e */
if(!s->budget--) { s->failed_pc=0x0c09322eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'*');
goto P_0c093230;
P_0c093230: /* original f682, guest PC 0x0c093230 */
if(!s->budget--) { s->failed_pc=0x0c093230u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[8],r[18],'*');
goto P_0c093232;
P_0c093232: /* original f482, guest PC 0x0c093232 */
if(!s->budget--) { s->failed_pc=0x0c093232u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'*');
goto P_0c093234;
P_0c093234: /* original f782, guest PC 0x0c093234 */
if(!s->budget--) { s->failed_pc=0x0c093234u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[8],r[18],'*');
goto P_0c093236;
P_0c093236: /* original e044, guest PC 0x0c093236 */
if(!s->budget--) { s->failed_pc=0x0c093236u; return 0; }
r[0]=0x00000044u;
goto P_0c093238;
P_0c093238: /* original f447, guest PC 0x0c093238 */
if(!s->budget--) { s->failed_pc=0x0c093238u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09323a;
P_0c09323a: /* original e048, guest PC 0x0c09323a */
if(!s->budget--) { s->failed_pc=0x0c09323au; return 0; }
r[0]=0x00000048u;
goto P_0c09323c;
P_0c09323c: /* original f477, guest PC 0x0c09323c */
if(!s->budget--) { s->failed_pc=0x0c09323cu; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c09323e;
P_0c09323e: /* original e04c, guest PC 0x0c09323e */
if(!s->budget--) { s->failed_pc=0x0c09323eu; return 0; }
r[0]=0x0000004cu;
goto P_0c093240;
P_0c093240: /* original f457, guest PC 0x0c093240 */
if(!s->budget--) { s->failed_pc=0x0c093240u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c093242;
P_0c093242: /* original e050, guest PC 0x0c093242 */
if(!s->budget--) { s->failed_pc=0x0c093242u; return 0; }
r[0]=0x00000050u;
goto P_0c093244;
P_0c093244: /* original f467, guest PC 0x0c093244 */
if(!s->budget--) { s->failed_pc=0x0c093244u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c093246;
P_0c093246: /* original c71d, guest PC 0x0c093246 */
if(!s->budget--) { s->failed_pc=0x0c093246u; return 0; }
r[0]=code_base|0x000932bcu;
goto P_0c093248;
P_0c093248: /* original f34c, guest PC 0x0c093248 */
if(!s->budget--) { s->failed_pc=0x0c093248u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c09324a;
P_0c09324a: /* original f342, guest PC 0x0c09324a */
if(!s->budget--) { s->failed_pc=0x0c09324au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c09324c;
P_0c09324c: /* original f05c, guest PC 0x0c09324c */
if(!s->budget--) { s->failed_pc=0x0c09324cu; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c09324e;
P_0c09324e: /* original f208, guest PC 0x0c09324e */
if(!s->budget--) { s->failed_pc=0x0c09324eu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c093250;
P_0c093250: /* original f35e, guest PC 0x0c093250 */
if(!s->budget--) { s->failed_pc=0x0c093250u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c093252;
P_0c093252: /* original f235, guest PC 0x0c093252 */
if(!s->budget--) { s->failed_pc=0x0c093252u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c093254;
P_0c093254: /* original 8f02, guest PC 0x0c093254 */
if(!s->budget--) { s->failed_pc=0x0c093254u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,6,3);
if(!cond) { goto P_0c09325c; }
goto P_0c093258;
P_0c093256: /* original f63c, guest PC 0x0c093256 */
if(!s->budget--) { s->failed_pc=0x0c093256u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c093258;
P_0c093258: /* original a002, guest PC 0x0c093258 */
if(!s->budget--) { s->failed_pc=0x0c093258u; return 0; }
fr[3]=0;
goto P_0c093260;
P_0c09325a: /* original f38d, guest PC 0x0c09325a */
if(!s->budget--) { s->failed_pc=0x0c09325au; return 0; }
fr[3]=0;
goto P_0c09325c;
P_0c09325c: /* original f36c, guest PC 0x0c09325c */
if(!s->budget--) { s->failed_pc=0x0c09325cu; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c09325e;
P_0c09325e: /* original f37d, guest PC 0x0c09325e */
if(!s->budget--) { s->failed_pc=0x0c09325eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c093260;
P_0c093260: /* original e054, guest PC 0x0c093260 */
if(!s->budget--) { s->failed_pc=0x0c093260u; return 0; }
r[0]=0x00000054u;
goto P_0c093262;
P_0c093262: /* original 000b, guest PC 0x0c093262 */
if(!s->budget--) { s->failed_pc=0x0c093262u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,3,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c093264: /* original f437, guest PC 0x0c093264 */
if(!s->budget--) { s->failed_pc=0x0c093264u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c093266;
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
unsupported: s->failed_pc=target; return 0;
}
