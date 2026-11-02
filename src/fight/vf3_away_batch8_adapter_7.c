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
int vf3_away_batch8_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05fc9au: goto P_0c05fc9a;
case 0x0c05fc9cu: goto P_0c05fc9c;
case 0x0c05fc9eu: goto P_0c05fc9e;
case 0x0c05fcc4u: goto P_0c05fcc4;
case 0x0c05fcc6u: goto P_0c05fcc6;
case 0x0c05fcc8u: goto P_0c05fcc8;
case 0x0c05fccau: goto P_0c05fcca;
case 0x0c05fcccu: goto P_0c05fccc;
case 0x0c05fcceu: goto P_0c05fcce;
case 0x0c060030u: goto P_0c060030;
case 0x0c060032u: goto P_0c060032;
case 0x0c060034u: goto P_0c060034;
case 0x0c060036u: goto P_0c060036;
case 0x0c060038u: goto P_0c060038;
case 0x0c06003au: goto P_0c06003a;
case 0x0c06003cu: goto P_0c06003c;
case 0x0c06003eu: goto P_0c06003e;
case 0x0c060040u: goto P_0c060040;
case 0x0c060042u: goto P_0c060042;
case 0x0c060044u: goto P_0c060044;
case 0x0c060046u: goto P_0c060046;
case 0x0c060048u: goto P_0c060048;
case 0x0c06004au: goto P_0c06004a;
case 0x0c06004cu: goto P_0c06004c;
case 0x0c06004eu: goto P_0c06004e;
case 0x0c060050u: goto P_0c060050;
case 0x0c060052u: goto P_0c060052;
case 0x0c060054u: goto P_0c060054;
case 0x0c060056u: goto P_0c060056;
case 0x0c060058u: goto P_0c060058;
case 0x0c06005au: goto P_0c06005a;
case 0x0c06005cu: goto P_0c06005c;
case 0x0c06005eu: goto P_0c06005e;
case 0x0c060060u: goto P_0c060060;
case 0x0c060062u: goto P_0c060062;
case 0x0c060064u: goto P_0c060064;
case 0x0c060066u: goto P_0c060066;
case 0x0c060068u: goto P_0c060068;
case 0x0c06006au: goto P_0c06006a;
case 0x0c06006cu: goto P_0c06006c;
case 0x0c06006eu: goto P_0c06006e;
case 0x0c060070u: goto P_0c060070;
case 0x0c060072u: goto P_0c060072;
case 0x0c060074u: goto P_0c060074;
case 0x0c060076u: goto P_0c060076;
case 0x0c060078u: goto P_0c060078;
case 0x0c06007au: goto P_0c06007a;
case 0x0c06007cu: goto P_0c06007c;
case 0x0c06007eu: goto P_0c06007e;
case 0x0c060080u: goto P_0c060080;
case 0x0c060082u: goto P_0c060082;
case 0x0c060084u: goto P_0c060084;
case 0x0c060086u: goto P_0c060086;
case 0x0c060088u: goto P_0c060088;
case 0x0c06008au: goto P_0c06008a;
case 0x0c06008cu: goto P_0c06008c;
case 0x0c06008eu: goto P_0c06008e;
case 0x0c060090u: goto P_0c060090;
case 0x0c060092u: goto P_0c060092;
case 0x0c060094u: goto P_0c060094;
case 0x0c060096u: goto P_0c060096;
case 0x0c060098u: goto P_0c060098;
case 0x0c06009au: goto P_0c06009a;
case 0x0c06009cu: goto P_0c06009c;
case 0x0c06009eu: goto P_0c06009e;
case 0x0c0600a0u: goto P_0c0600a0;
case 0x0c0600a2u: goto P_0c0600a2;
case 0x0c0600a4u: goto P_0c0600a4;
case 0x0c0600a6u: goto P_0c0600a6;
case 0x0c0600a8u: goto P_0c0600a8;
case 0x0c0600aau: goto P_0c0600aa;
case 0x0c0600acu: goto P_0c0600ac;
case 0x0c0600aeu: goto P_0c0600ae;
case 0x0c0600b0u: goto P_0c0600b0;
case 0x0c0600b2u: goto P_0c0600b2;
case 0x0c0600b4u: goto P_0c0600b4;
case 0x0c0600b6u: goto P_0c0600b6;
case 0x0c0600b8u: goto P_0c0600b8;
case 0x0c0600bau: goto P_0c0600ba;
case 0x0c0600bcu: goto P_0c0600bc;
case 0x0c0600beu: goto P_0c0600be;
case 0x0c0600c0u: goto P_0c0600c0;
case 0x0c0600c2u: goto P_0c0600c2;
case 0x0c0600c4u: goto P_0c0600c4;
case 0x0c0600c6u: goto P_0c0600c6;
case 0x0c0600c8u: goto P_0c0600c8;
case 0x0c0600cau: goto P_0c0600ca;
case 0x0c0600ccu: goto P_0c0600cc;
case 0x0c0600ceu: goto P_0c0600ce;
case 0x0c0600d0u: goto P_0c0600d0;
case 0x0c0600d2u: goto P_0c0600d2;
case 0x0c0600d4u: goto P_0c0600d4;
case 0x0c0600d6u: goto P_0c0600d6;
case 0x0c0600d8u: goto P_0c0600d8;
case 0x0c0600dau: goto P_0c0600da;
case 0x0c0600dcu: goto P_0c0600dc;
case 0x0c0600deu: goto P_0c0600de;
case 0x0c0600e0u: goto P_0c0600e0;
case 0x0c0600e2u: goto P_0c0600e2;
case 0x0c0600e4u: goto P_0c0600e4;
case 0x0c0600e6u: goto P_0c0600e6;
case 0x0c0600e8u: goto P_0c0600e8;
case 0x0c0600eau: goto P_0c0600ea;
case 0x0c0600ecu: goto P_0c0600ec;
case 0x0c0600eeu: goto P_0c0600ee;
case 0x0c0600f0u: goto P_0c0600f0;
case 0x0c0600f2u: goto P_0c0600f2;
case 0x0c0600f4u: goto P_0c0600f4;
case 0x0c0600f6u: goto P_0c0600f6;
case 0x0c0600f8u: goto P_0c0600f8;
case 0x0c0600fau: goto P_0c0600fa;
case 0x0c0600fcu: goto P_0c0600fc;
case 0x0c0600feu: goto P_0c0600fe;
case 0x0c060100u: goto P_0c060100;
case 0x0c060102u: goto P_0c060102;
case 0x0c060104u: goto P_0c060104;
case 0x0c060106u: goto P_0c060106;
case 0x0c060108u: goto P_0c060108;
case 0x0c06010au: goto P_0c06010a;
case 0x0c06010cu: goto P_0c06010c;
case 0x0c06010eu: goto P_0c06010e;
case 0x0c060110u: goto P_0c060110;
case 0x0c060112u: goto P_0c060112;
case 0x0c060114u: goto P_0c060114;
case 0x0c060116u: goto P_0c060116;
case 0x0c060118u: goto P_0c060118;
case 0x0c06011au: goto P_0c06011a;
case 0x0c06011cu: goto P_0c06011c;
case 0x0c06011eu: goto P_0c06011e;
case 0x0c060120u: goto P_0c060120;
case 0x0c060122u: goto P_0c060122;
case 0x0c060124u: goto P_0c060124;
case 0x0c060126u: goto P_0c060126;
case 0x0c060128u: goto P_0c060128;
case 0x0c06012au: goto P_0c06012a;
case 0x0c06012cu: goto P_0c06012c;
case 0x0c06012eu: goto P_0c06012e;
case 0x0c060130u: goto P_0c060130;
case 0x0c060132u: goto P_0c060132;
case 0x0c060134u: goto P_0c060134;
case 0x0c060136u: goto P_0c060136;
case 0x0c060138u: goto P_0c060138;
case 0x0c06013au: goto P_0c06013a;
case 0x0c06013cu: goto P_0c06013c;
case 0x0c06013eu: goto P_0c06013e;
case 0x0c060140u: goto P_0c060140;
case 0x0c060142u: goto P_0c060142;
case 0x0c060144u: goto P_0c060144;
case 0x0c060146u: goto P_0c060146;
case 0x0c060148u: goto P_0c060148;
case 0x0c06014au: goto P_0c06014a;
case 0x0c06014cu: goto P_0c06014c;
case 0x0c06014eu: goto P_0c06014e;
case 0x0c060150u: goto P_0c060150;
case 0x0c060152u: goto P_0c060152;
case 0x0c060154u: goto P_0c060154;
case 0x0c060156u: goto P_0c060156;
case 0x0c060158u: goto P_0c060158;
case 0x0c06015au: goto P_0c06015a;
case 0x0c06015cu: goto P_0c06015c;
case 0x0c06015eu: goto P_0c06015e;
case 0x0c060160u: goto P_0c060160;
case 0x0c060162u: goto P_0c060162;
case 0x0c060164u: goto P_0c060164;
case 0x0c060166u: goto P_0c060166;
case 0x0c060168u: goto P_0c060168;
case 0x0c06016au: goto P_0c06016a;
case 0x0c06016cu: goto P_0c06016c;
case 0x0c06016eu: goto P_0c06016e;
case 0x0c060170u: goto P_0c060170;
case 0x0c060172u: goto P_0c060172;
case 0x0c060174u: goto P_0c060174;
case 0x0c060176u: goto P_0c060176;
case 0x0c060178u: goto P_0c060178;
case 0x0c06017au: goto P_0c06017a;
case 0x0c06017cu: goto P_0c06017c;
case 0x0c06017eu: goto P_0c06017e;
case 0x0c060180u: goto P_0c060180;
case 0x0c060182u: goto P_0c060182;
case 0x0c0601b8u: goto P_0c0601b8;
case 0x0c0601bau: goto P_0c0601ba;
case 0x0c0601bcu: goto P_0c0601bc;
case 0x0c0601beu: goto P_0c0601be;
case 0x0c0601c0u: goto P_0c0601c0;
case 0x0c0601c2u: goto P_0c0601c2;
case 0x0c0601c4u: goto P_0c0601c4;
case 0x0c0601c6u: goto P_0c0601c6;
case 0x0c0601c8u: goto P_0c0601c8;
case 0x0c0601cau: goto P_0c0601ca;
case 0x0c0601ccu: goto P_0c0601cc;
case 0x0c0601ceu: goto P_0c0601ce;
case 0x0c0601d0u: goto P_0c0601d0;
case 0x0c0601d2u: goto P_0c0601d2;
case 0x0c0601d4u: goto P_0c0601d4;
case 0x0c0601d6u: goto P_0c0601d6;
case 0x0c0601d8u: goto P_0c0601d8;
case 0x0c0601dau: goto P_0c0601da;
case 0x0c0601dcu: goto P_0c0601dc;
case 0x0c0601deu: goto P_0c0601de;
case 0x0c0601e0u: goto P_0c0601e0;
case 0x0c0601e2u: goto P_0c0601e2;
case 0x0c0601e4u: goto P_0c0601e4;
case 0x0c0601e6u: goto P_0c0601e6;
case 0x0c0601e8u: goto P_0c0601e8;
case 0x0c0601eau: goto P_0c0601ea;
case 0x0c0601ecu: goto P_0c0601ec;
case 0x0c0601eeu: goto P_0c0601ee;
case 0x0c0601f0u: goto P_0c0601f0;
case 0x0c0601f2u: goto P_0c0601f2;
case 0x0c0601f4u: goto P_0c0601f4;
case 0x0c0601f6u: goto P_0c0601f6;
case 0x0c0601f8u: goto P_0c0601f8;
case 0x0c0601fau: goto P_0c0601fa;
case 0x0c0601fcu: goto P_0c0601fc;
case 0x0c0601feu: goto P_0c0601fe;
case 0x0c060200u: goto P_0c060200;
case 0x0c060202u: goto P_0c060202;
case 0x0c060204u: goto P_0c060204;
case 0x0c060206u: goto P_0c060206;
case 0x0c060208u: goto P_0c060208;
case 0x0c06020au: goto P_0c06020a;
case 0x0c06020cu: goto P_0c06020c;
case 0x0c06020eu: goto P_0c06020e;
case 0x0c060210u: goto P_0c060210;
case 0x0c060212u: goto P_0c060212;
case 0x0c060214u: goto P_0c060214;
case 0x0c060216u: goto P_0c060216;
case 0x0c060218u: goto P_0c060218;
case 0x0c06021au: goto P_0c06021a;
case 0x0c06021cu: goto P_0c06021c;
case 0x0c06021eu: goto P_0c06021e;
case 0x0c060220u: goto P_0c060220;
case 0x0c060222u: goto P_0c060222;
case 0x0c060224u: goto P_0c060224;
case 0x0c060226u: goto P_0c060226;
case 0x0c060228u: goto P_0c060228;
case 0x0c06022au: goto P_0c06022a;
case 0x0c06022cu: goto P_0c06022c;
case 0x0c06022eu: goto P_0c06022e;
case 0x0c060230u: goto P_0c060230;
case 0x0c060232u: goto P_0c060232;
case 0x0c060234u: goto P_0c060234;
case 0x0c060236u: goto P_0c060236;
case 0x0c060238u: goto P_0c060238;
case 0x0c06023au: goto P_0c06023a;
case 0x0c06023cu: goto P_0c06023c;
case 0x0c06023eu: goto P_0c06023e;
case 0x0c060240u: goto P_0c060240;
case 0x0c060242u: goto P_0c060242;
case 0x0c060244u: goto P_0c060244;
case 0x0c060246u: goto P_0c060246;
case 0x0c060248u: goto P_0c060248;
case 0x0c06024au: goto P_0c06024a;
case 0x0c06024cu: goto P_0c06024c;
case 0x0c06024eu: goto P_0c06024e;
case 0x0c060250u: goto P_0c060250;
case 0x0c060252u: goto P_0c060252;
case 0x0c060254u: goto P_0c060254;
case 0x0c060256u: goto P_0c060256;
case 0x0c060258u: goto P_0c060258;
case 0x0c06025au: goto P_0c06025a;
case 0x0c06025cu: goto P_0c06025c;
case 0x0c06025eu: goto P_0c06025e;
case 0x0c060260u: goto P_0c060260;
case 0x0c060262u: goto P_0c060262;
case 0x0c060264u: goto P_0c060264;
case 0x0c060266u: goto P_0c060266;
case 0x0c060268u: goto P_0c060268;
case 0x0c06026au: goto P_0c06026a;
case 0x0c06026cu: goto P_0c06026c;
case 0x0c06026eu: goto P_0c06026e;
case 0x0c060270u: goto P_0c060270;
case 0x0c060272u: goto P_0c060272;
case 0x0c060274u: goto P_0c060274;
case 0x0c060276u: goto P_0c060276;
case 0x0c060278u: goto P_0c060278;
case 0x0c06027au: goto P_0c06027a;
case 0x0c06027cu: goto P_0c06027c;
case 0x0c06027eu: goto P_0c06027e;
case 0x0c060280u: goto P_0c060280;
case 0x0c060282u: goto P_0c060282;
case 0x0c060284u: goto P_0c060284;
case 0x0c0602a4u: goto P_0c0602a4;
case 0x0c0602a6u: goto P_0c0602a6;
case 0x0c0602a8u: goto P_0c0602a8;
case 0x0c0602aau: goto P_0c0602aa;
case 0x0c0602acu: goto P_0c0602ac;
case 0x0c0602aeu: goto P_0c0602ae;
case 0x0c0602b0u: goto P_0c0602b0;
case 0x0c0602b2u: goto P_0c0602b2;
case 0x0c0602b4u: goto P_0c0602b4;
case 0x0c0602b6u: goto P_0c0602b6;
case 0x0c0602b8u: goto P_0c0602b8;
case 0x0c0602bau: goto P_0c0602ba;
case 0x0c0602bcu: goto P_0c0602bc;
case 0x0c0602beu: goto P_0c0602be;
case 0x0c0602c0u: goto P_0c0602c0;
case 0x0c0602c2u: goto P_0c0602c2;
case 0x0c0602c4u: goto P_0c0602c4;
case 0x0c0602c6u: goto P_0c0602c6;
case 0x0c0602c8u: goto P_0c0602c8;
case 0x0c0602cau: goto P_0c0602ca;
case 0x0c0602ccu: goto P_0c0602cc;
case 0x0c0602ceu: goto P_0c0602ce;
case 0x0c0602d0u: goto P_0c0602d0;
case 0x0c0602d2u: goto P_0c0602d2;
case 0x0c0602d4u: goto P_0c0602d4;
case 0x0c0602d6u: goto P_0c0602d6;
case 0x0c0602d8u: goto P_0c0602d8;
case 0x0c0602dau: goto P_0c0602da;
case 0x0c0602dcu: goto P_0c0602dc;
case 0x0c0602deu: goto P_0c0602de;
case 0x0c0602e0u: goto P_0c0602e0;
case 0x0c0602e2u: goto P_0c0602e2;
case 0x0c0602e4u: goto P_0c0602e4;
case 0x0c0602e6u: goto P_0c0602e6;
case 0x0c0602e8u: goto P_0c0602e8;
case 0x0c0602eau: goto P_0c0602ea;
case 0x0c0602ecu: goto P_0c0602ec;
case 0x0c0602eeu: goto P_0c0602ee;
case 0x0c0602f0u: goto P_0c0602f0;
case 0x0c0602f2u: goto P_0c0602f2;
case 0x0c0602f4u: goto P_0c0602f4;
case 0x0c0602f6u: goto P_0c0602f6;
case 0x0c0602f8u: goto P_0c0602f8;
case 0x0c0602fau: goto P_0c0602fa;
case 0x0c0602fcu: goto P_0c0602fc;
case 0x0c0602feu: goto P_0c0602fe;
case 0x0c060300u: goto P_0c060300;
case 0x0c060302u: goto P_0c060302;
case 0x0c060304u: goto P_0c060304;
case 0x0c060306u: goto P_0c060306;
case 0x0c060308u: goto P_0c060308;
case 0x0c06030au: goto P_0c06030a;
case 0x0c06030cu: goto P_0c06030c;
case 0x0c06030eu: goto P_0c06030e;
case 0x0c060310u: goto P_0c060310;
case 0x0c060312u: goto P_0c060312;
case 0x0c060314u: goto P_0c060314;
case 0x0c060316u: goto P_0c060316;
case 0x0c060318u: goto P_0c060318;
case 0x0c06031au: goto P_0c06031a;
case 0x0c06031cu: goto P_0c06031c;
case 0x0c06031eu: goto P_0c06031e;
case 0x0c060320u: goto P_0c060320;
case 0x0c060322u: goto P_0c060322;
case 0x0c060324u: goto P_0c060324;
case 0x0c060326u: goto P_0c060326;
case 0x0c060328u: goto P_0c060328;
case 0x0c06032au: goto P_0c06032a;
case 0x0c06032cu: goto P_0c06032c;
case 0x0c06032eu: goto P_0c06032e;
case 0x0c060330u: goto P_0c060330;
case 0x0c060332u: goto P_0c060332;
case 0x0c060334u: goto P_0c060334;
case 0x0c060336u: goto P_0c060336;
case 0x0c060338u: goto P_0c060338;
case 0x0c06033au: goto P_0c06033a;
case 0x0c06033cu: goto P_0c06033c;
case 0x0c06033eu: goto P_0c06033e;
case 0x0c060340u: goto P_0c060340;
case 0x0c060342u: goto P_0c060342;
case 0x0c060344u: goto P_0c060344;
case 0x0c060346u: goto P_0c060346;
case 0x0c060348u: goto P_0c060348;
case 0x0c06034au: goto P_0c06034a;
case 0x0c06034cu: goto P_0c06034c;
case 0x0c06034eu: goto P_0c06034e;
case 0x0c060350u: goto P_0c060350;
case 0x0c060352u: goto P_0c060352;
case 0x0c060354u: goto P_0c060354;
case 0x0c060356u: goto P_0c060356;
case 0x0c060358u: goto P_0c060358;
case 0x0c06035au: goto P_0c06035a;
case 0x0c06035cu: goto P_0c06035c;
case 0x0c06035eu: goto P_0c06035e;
case 0x0c060360u: goto P_0c060360;
case 0x0c060362u: goto P_0c060362;
case 0x0c060364u: goto P_0c060364;
case 0x0c060366u: goto P_0c060366;
case 0x0c060368u: goto P_0c060368;
case 0x0c06036au: goto P_0c06036a;
case 0x0c06036cu: goto P_0c06036c;
case 0x0c06036eu: goto P_0c06036e;
case 0x0c060370u: goto P_0c060370;
case 0x0c060372u: goto P_0c060372;
case 0x0c060374u: goto P_0c060374;
case 0x0c060376u: goto P_0c060376;
case 0x0c060378u: goto P_0c060378;
case 0x0c06037au: goto P_0c06037a;
case 0x0c06037cu: goto P_0c06037c;
case 0x0c06037eu: goto P_0c06037e;
case 0x0c060380u: goto P_0c060380;
case 0x0c060382u: goto P_0c060382;
case 0x0c060384u: goto P_0c060384;
case 0x0c060386u: goto P_0c060386;
case 0x0c060388u: goto P_0c060388;
case 0x0c06038au: goto P_0c06038a;
case 0x0c06038cu: goto P_0c06038c;
case 0x0c0603acu: goto P_0c0603ac;
case 0x0c0603aeu: goto P_0c0603ae;
case 0x0c0603b0u: goto P_0c0603b0;
case 0x0c0603b2u: goto P_0c0603b2;
case 0x0c0603b4u: goto P_0c0603b4;
case 0x0c0603b6u: goto P_0c0603b6;
case 0x0c0603b8u: goto P_0c0603b8;
case 0x0c0603bau: goto P_0c0603ba;
case 0x0c0603bcu: goto P_0c0603bc;
case 0x0c0603beu: goto P_0c0603be;
case 0x0c0603c0u: goto P_0c0603c0;
case 0x0c0603c2u: goto P_0c0603c2;
case 0x0c0603c4u: goto P_0c0603c4;
case 0x0c0603c6u: goto P_0c0603c6;
case 0x0c0603c8u: goto P_0c0603c8;
case 0x0c0603cau: goto P_0c0603ca;
case 0x0c0603ccu: goto P_0c0603cc;
case 0x0c0603ceu: goto P_0c0603ce;
case 0x0c0603d0u: goto P_0c0603d0;
case 0x0c0603d2u: goto P_0c0603d2;
case 0x0c0603d4u: goto P_0c0603d4;
case 0x0c0603d6u: goto P_0c0603d6;
case 0x0c0603d8u: goto P_0c0603d8;
case 0x0c0603dau: goto P_0c0603da;
case 0x0c0603dcu: goto P_0c0603dc;
case 0x0c0603deu: goto P_0c0603de;
case 0x0c0603e0u: goto P_0c0603e0;
case 0x0c0603e2u: goto P_0c0603e2;
case 0x0c0603e4u: goto P_0c0603e4;
case 0x0c0603e6u: goto P_0c0603e6;
case 0x0c0603e8u: goto P_0c0603e8;
case 0x0c0603eau: goto P_0c0603ea;
case 0x0c0603ecu: goto P_0c0603ec;
case 0x0c0603eeu: goto P_0c0603ee;
case 0x0c0603f0u: goto P_0c0603f0;
case 0x0c0603f2u: goto P_0c0603f2;
case 0x0c0603f4u: goto P_0c0603f4;
case 0x0c0603f6u: goto P_0c0603f6;
case 0x0c0603f8u: goto P_0c0603f8;
case 0x0c0603fau: goto P_0c0603fa;
case 0x0c0603fcu: goto P_0c0603fc;
case 0x0c0603feu: goto P_0c0603fe;
case 0x0c060400u: goto P_0c060400;
case 0x0c060402u: goto P_0c060402;
case 0x0c060404u: goto P_0c060404;
case 0x0c060406u: goto P_0c060406;
case 0x0c060408u: goto P_0c060408;
case 0x0c06040au: goto P_0c06040a;
case 0x0c06040cu: goto P_0c06040c;
case 0x0c06040eu: goto P_0c06040e;
case 0x0c060410u: goto P_0c060410;
case 0x0c060412u: goto P_0c060412;
case 0x0c060414u: goto P_0c060414;
case 0x0c060416u: goto P_0c060416;
case 0x0c060418u: goto P_0c060418;
case 0x0c06041au: goto P_0c06041a;
case 0x0c06041cu: goto P_0c06041c;
case 0x0c06041eu: goto P_0c06041e;
case 0x0c060420u: goto P_0c060420;
case 0x0c060422u: goto P_0c060422;
case 0x0c060424u: goto P_0c060424;
case 0x0c060426u: goto P_0c060426;
case 0x0c060428u: goto P_0c060428;
case 0x0c06042au: goto P_0c06042a;
case 0x0c06042cu: goto P_0c06042c;
case 0x0c06042eu: goto P_0c06042e;
case 0x0c060430u: goto P_0c060430;
case 0x0c060432u: goto P_0c060432;
case 0x0c060434u: goto P_0c060434;
case 0x0c060436u: goto P_0c060436;
case 0x0c060438u: goto P_0c060438;
case 0x0c06043au: goto P_0c06043a;
case 0x0c06043cu: goto P_0c06043c;
case 0x0c06043eu: goto P_0c06043e;
case 0x0c060440u: goto P_0c060440;
case 0x0c060442u: goto P_0c060442;
case 0x0c060444u: goto P_0c060444;
case 0x0c060446u: goto P_0c060446;
case 0x0c060448u: goto P_0c060448;
case 0x0c06044au: goto P_0c06044a;
case 0x0c06044cu: goto P_0c06044c;
case 0x0c06044eu: goto P_0c06044e;
case 0x0c060450u: goto P_0c060450;
case 0x0c060452u: goto P_0c060452;
case 0x0c060454u: goto P_0c060454;
case 0x0c060456u: goto P_0c060456;
case 0x0c060458u: goto P_0c060458;
case 0x0c06045au: goto P_0c06045a;
case 0x0c06045cu: goto P_0c06045c;
case 0x0c06045eu: goto P_0c06045e;
case 0x0c060460u: goto P_0c060460;
case 0x0c060462u: goto P_0c060462;
case 0x0c060464u: goto P_0c060464;
case 0x0c060466u: goto P_0c060466;
case 0x0c060468u: goto P_0c060468;
case 0x0c06046au: goto P_0c06046a;
case 0x0c06046cu: goto P_0c06046c;
case 0x0c06046eu: goto P_0c06046e;
case 0x0c060470u: goto P_0c060470;
case 0x0c060472u: goto P_0c060472;
case 0x0c060474u: goto P_0c060474;
case 0x0c060476u: goto P_0c060476;
case 0x0c060478u: goto P_0c060478;
case 0x0c06047au: goto P_0c06047a;
case 0x0c06047cu: goto P_0c06047c;
case 0x0c06047eu: goto P_0c06047e;
case 0x0c060480u: goto P_0c060480;
case 0x0c060482u: goto P_0c060482;
case 0x0c060484u: goto P_0c060484;
case 0x0c060486u: goto P_0c060486;
case 0x0c060488u: goto P_0c060488;
case 0x0c06048au: goto P_0c06048a;
case 0x0c06048cu: goto P_0c06048c;
case 0x0c06048eu: goto P_0c06048e;
case 0x0c060490u: goto P_0c060490;
case 0x0c060492u: goto P_0c060492;
case 0x0c060494u: goto P_0c060494;
case 0x0c0604b8u: goto P_0c0604b8;
case 0x0c0604bau: goto P_0c0604ba;
case 0x0c0604bcu: goto P_0c0604bc;
case 0x0c0604beu: goto P_0c0604be;
case 0x0c0604c0u: goto P_0c0604c0;
case 0x0c0604c2u: goto P_0c0604c2;
case 0x0c0604c4u: goto P_0c0604c4;
case 0x0c0604c6u: goto P_0c0604c6;
case 0x0c0604c8u: goto P_0c0604c8;
case 0x0c0604cau: goto P_0c0604ca;
case 0x0c0604ccu: goto P_0c0604cc;
case 0x0c0604ceu: goto P_0c0604ce;
case 0x0c0604d0u: goto P_0c0604d0;
case 0x0c0604d2u: goto P_0c0604d2;
case 0x0c0604d4u: goto P_0c0604d4;
case 0x0c0604d6u: goto P_0c0604d6;
case 0x0c0604d8u: goto P_0c0604d8;
case 0x0c0604dau: goto P_0c0604da;
case 0x0c0604dcu: goto P_0c0604dc;
case 0x0c0604deu: goto P_0c0604de;
case 0x0c0604e0u: goto P_0c0604e0;
case 0x0c0604e2u: goto P_0c0604e2;
case 0x0c0604e4u: goto P_0c0604e4;
case 0x0c0604e6u: goto P_0c0604e6;
case 0x0c0604e8u: goto P_0c0604e8;
case 0x0c0604eau: goto P_0c0604ea;
case 0x0c0604ecu: goto P_0c0604ec;
case 0x0c0604eeu: goto P_0c0604ee;
case 0x0c0604f0u: goto P_0c0604f0;
case 0x0c0604f2u: goto P_0c0604f2;
case 0x0c0604f4u: goto P_0c0604f4;
case 0x0c0604f6u: goto P_0c0604f6;
case 0x0c0604f8u: goto P_0c0604f8;
case 0x0c0604fau: goto P_0c0604fa;
case 0x0c0604fcu: goto P_0c0604fc;
case 0x0c0604feu: goto P_0c0604fe;
case 0x0c060500u: goto P_0c060500;
case 0x0c060502u: goto P_0c060502;
case 0x0c060504u: goto P_0c060504;
case 0x0c060506u: goto P_0c060506;
case 0x0c060508u: goto P_0c060508;
case 0x0c06050au: goto P_0c06050a;
case 0x0c06050cu: goto P_0c06050c;
case 0x0c06050eu: goto P_0c06050e;
case 0x0c060510u: goto P_0c060510;
case 0x0c060512u: goto P_0c060512;
case 0x0c060514u: goto P_0c060514;
case 0x0c060516u: goto P_0c060516;
case 0x0c060518u: goto P_0c060518;
case 0x0c06051au: goto P_0c06051a;
case 0x0c06051cu: goto P_0c06051c;
case 0x0c06051eu: goto P_0c06051e;
case 0x0c060520u: goto P_0c060520;
case 0x0c060522u: goto P_0c060522;
case 0x0c060524u: goto P_0c060524;
case 0x0c060526u: goto P_0c060526;
case 0x0c060528u: goto P_0c060528;
case 0x0c06052au: goto P_0c06052a;
case 0x0c06052cu: goto P_0c06052c;
case 0x0c06052eu: goto P_0c06052e;
case 0x0c060530u: goto P_0c060530;
case 0x0c060532u: goto P_0c060532;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05fc9a: /* original d339, guest PC 0x0c05fc9a */
if(!s->budget--) { s->failed_pc=0x0c05fc9au; return 0; }
r[3]=read(ram,0x0c05fd80u,4);
goto P_0c05fc9c;
P_0c05fc9c: /* original 432b, guest PC 0x0c05fc9c */
if(!s->budget--) { s->failed_pc=0x0c05fc9cu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c060d14u: return vf3_matrix_family(0x0c060d14u,s,ram);
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
P_0c05fc9e: /* original 0009, guest PC 0x0c05fc9e */
if(!s->budget--) { s->failed_pc=0x0c05fc9eu; return 0; }
if(!vf3_matrix_family(0x0c05fca0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05fca0u; return 0; } return 1;
P_0c05fcc4: /* original d330, guest PC 0x0c05fcc4 */
if(!s->budget--) { s->failed_pc=0x0c05fcc4u; return 0; }
r[3]=read(ram,0x0c05fd88u,4);
goto P_0c05fcc6;
P_0c05fcc6: /* original 7ffc, guest PC 0x0c05fcc6 */
if(!s->budget--) { s->failed_pc=0x0c05fcc6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05fcc8;
P_0c05fcc8: /* original 2f42, guest PC 0x0c05fcc8 */
if(!s->budget--) { s->failed_pc=0x0c05fcc8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c05fcca;
P_0c05fcca: /* original 6232, guest PC 0x0c05fcca */
if(!s->budget--) { s->failed_pc=0x0c05fccau; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c05fccc;
P_0c05fccc: /* original 422b, guest PC 0x0c05fccc */
if(!s->budget--) { s->failed_pc=0x0c05fcccu; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c05fcce: /* original 7f04, guest PC 0x0c05fcce */
if(!s->budget--) { s->failed_pc=0x0c05fcceu; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c05fcd0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05fcd0u; return 0; } return 1;
P_0c060030: /* original 2fe6, guest PC 0x0c060030 */
if(!s->budget--) { s->failed_pc=0x0c060030u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060032;
P_0c060032: /* original e058, guest PC 0x0c060032 */
if(!s->budget--) { s->failed_pc=0x0c060032u; return 0; }
r[0]=0x00000058u;
goto P_0c060034;
P_0c060034: /* original 95a6, guest PC 0x0c060034 */
if(!s->budget--) { s->failed_pc=0x0c060034u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060184u,2);
goto P_0c060036;
P_0c060036: /* original 2fd6, guest PC 0x0c060036 */
if(!s->budget--) { s->failed_pc=0x0c060036u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060038;
P_0c060038: /* original 64f3, guest PC 0x0c060038 */
if(!s->budget--) { s->failed_pc=0x0c060038u; return 0; }
r[4]=r[15];
goto P_0c06003a;
P_0c06003a: /* original 7408, guest PC 0x0c06003a */
if(!s->budget--) { s->failed_pc=0x0c06003au; return 0; }
r[4]+=0x00000008u;
goto P_0c06003c;
P_0c06003c: /* original 034e, guest PC 0x0c06003c */
if(!s->budget--) { s->failed_pc=0x0c06003cu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c06003e;
P_0c06003e: /* original e054, guest PC 0x0c06003e */
if(!s->budget--) { s->failed_pc=0x0c06003eu; return 0; }
r[0]=0x00000054u;
goto P_0c060040;
P_0c060040: /* original 024e, guest PC 0x0c060040 */
if(!s->budget--) { s->failed_pc=0x0c060040u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c060042;
P_0c060042: /* original 2359, guest PC 0x0c060042 */
if(!s->budget--) { s->failed_pc=0x0c060042u; return 0; }
r[3]&=r[5];
goto P_0c060044;
P_0c060044: /* original 2259, guest PC 0x0c060044 */
if(!s->budget--) { s->failed_pc=0x0c060044u; return 0; }
r[2]&=r[5];
goto P_0c060046;
P_0c060046: /* original 4228, guest PC 0x0c060046 */
if(!s->budget--) { s->failed_pc=0x0c060046u; return 0; }
r[2]<<=16;
goto P_0c060048;
P_0c060048: /* original 232b, guest PC 0x0c060048 */
if(!s->budget--) { s->failed_pc=0x0c060048u; return 0; }
r[3]|=r[2];
goto P_0c06004a;
P_0c06004a: /* original d250, guest PC 0x0c06004a */
if(!s->budget--) { s->failed_pc=0x0c06004au; return 0; }
r[2]=read(ram,0x0c06018cu,4);
goto P_0c06004c;
P_0c06004c: /* original 2232, guest PC 0x0c06004c */
if(!s->budget--) { s->failed_pc=0x0c06004cu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c06004e;
P_0c06004e: /* original e060, guest PC 0x0c06004e */
if(!s->budget--) { s->failed_pc=0x0c06004eu; return 0; }
r[0]=0x00000060u;
goto P_0c060050;
P_0c060050: /* original 014e, guest PC 0x0c060050 */
if(!s->budget--) { s->failed_pc=0x0c060050u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c060052;
P_0c060052: /* original e05c, guest PC 0x0c060052 */
if(!s->budget--) { s->failed_pc=0x0c060052u; return 0; }
r[0]=0x0000005cu;
goto P_0c060054;
P_0c060054: /* original 034e, guest PC 0x0c060054 */
if(!s->budget--) { s->failed_pc=0x0c060054u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c060056;
P_0c060056: /* original 2159, guest PC 0x0c060056 */
if(!s->budget--) { s->failed_pc=0x0c060056u; return 0; }
r[1]&=r[5];
goto P_0c060058;
P_0c060058: /* original 2359, guest PC 0x0c060058 */
if(!s->budget--) { s->failed_pc=0x0c060058u; return 0; }
r[3]&=r[5];
goto P_0c06005a;
P_0c06005a: /* original 4328, guest PC 0x0c06005a */
if(!s->budget--) { s->failed_pc=0x0c06005au; return 0; }
r[3]<<=16;
goto P_0c06005c;
P_0c06005c: /* original 213b, guest PC 0x0c06005c */
if(!s->budget--) { s->failed_pc=0x0c06005cu; return 0; }
r[1]|=r[3];
goto P_0c06005e;
P_0c06005e: /* original d34c, guest PC 0x0c06005e */
if(!s->budget--) { s->failed_pc=0x0c06005eu; return 0; }
r[3]=read(ram,0x0c060190u,4);
goto P_0c060060;
P_0c060060: /* original 2312, guest PC 0x0c060060 */
if(!s->budget--) { s->failed_pc=0x0c060060u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c060062;
P_0c060062: /* original e50f, guest PC 0x0c060062 */
if(!s->budget--) { s->failed_pc=0x0c060062u; return 0; }
r[5]=0x0000000fu;
goto P_0c060064;
P_0c060064: /* original e61f, guest PC 0x0c060064 */
if(!s->budget--) { s->failed_pc=0x0c060064u; return 0; }
r[6]=0x0000001fu;
goto P_0c060066;
P_0c060066: /* original e048, guest PC 0x0c060066 */
if(!s->budget--) { s->failed_pc=0x0c060066u; return 0; }
r[0]=0x00000048u;
goto P_0c060068;
P_0c060068: /* original 024e, guest PC 0x0c060068 */
if(!s->budget--) { s->failed_pc=0x0c060068u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c06006a;
P_0c06006a: /* original e04c, guest PC 0x0c06006a */
if(!s->budget--) { s->failed_pc=0x0c06006au; return 0; }
r[0]=0x0000004cu;
goto P_0c06006c;
P_0c06006c: /* original 2259, guest PC 0x0c06006c */
if(!s->budget--) { s->failed_pc=0x0c06006cu; return 0; }
r[2]&=r[5];
goto P_0c06006e;
P_0c06006e: /* original 014e, guest PC 0x0c06006e */
if(!s->budget--) { s->failed_pc=0x0c06006eu; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c060070;
P_0c060070: /* original 2169, guest PC 0x0c060070 */
if(!s->budget--) { s->failed_pc=0x0c060070u; return 0; }
r[1]&=r[6];
goto P_0c060072;
P_0c060072: /* original 4108, guest PC 0x0c060072 */
if(!s->budget--) { s->failed_pc=0x0c060072u; return 0; }
r[1]<<=2;
goto P_0c060074;
P_0c060074: /* original 4108, guest PC 0x0c060074 */
if(!s->budget--) { s->failed_pc=0x0c060074u; return 0; }
r[1]<<=2;
goto P_0c060076;
P_0c060076: /* original 221b, guest PC 0x0c060076 */
if(!s->budget--) { s->failed_pc=0x0c060076u; return 0; }
r[2]|=r[1];
goto P_0c060078;
P_0c060078: /* original e050, guest PC 0x0c060078 */
if(!s->budget--) { s->failed_pc=0x0c060078u; return 0; }
r[0]=0x00000050u;
goto P_0c06007a;
P_0c06007a: /* original 014e, guest PC 0x0c06007a */
if(!s->budget--) { s->failed_pc=0x0c06007au; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c06007c;
P_0c06007c: /* original 2159, guest PC 0x0c06007c */
if(!s->budget--) { s->failed_pc=0x0c06007cu; return 0; }
r[1]&=r[5];
goto P_0c06007e;
P_0c06007e: /* original 4118, guest PC 0x0c06007e */
if(!s->budget--) { s->failed_pc=0x0c06007eu; return 0; }
r[1]<<=8;
goto P_0c060080;
P_0c060080: /* original 4100, guest PC 0x0c060080 */
if(!s->budget--) { s->failed_pc=0x0c060080u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c060082;
P_0c060082: /* original 221b, guest PC 0x0c060082 */
if(!s->budget--) { s->failed_pc=0x0c060082u; return 0; }
r[2]|=r[1];
goto P_0c060084;
P_0c060084: /* original d143, guest PC 0x0c060084 */
if(!s->budget--) { s->failed_pc=0x0c060084u; return 0; }
r[1]=read(ram,0x0c060194u,4);
goto P_0c060086;
P_0c060086: /* original 2122, guest PC 0x0c060086 */
if(!s->budget--) { s->failed_pc=0x0c060086u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c060088;
P_0c060088: /* original 6342, guest PC 0x0c060088 */
if(!s->budget--) { s->failed_pc=0x0c060088u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c06008a;
P_0c06008a: /* original d243, guest PC 0x0c06008a */
if(!s->budget--) { s->failed_pc=0x0c06008au; return 0; }
r[2]=read(ram,0x0c060198u,4);
goto P_0c06008c;
P_0c06008c: /* original 2232, guest PC 0x0c06008c */
if(!s->budget--) { s->failed_pc=0x0c06008cu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c06008e;
P_0c06008e: /* original 5141, guest PC 0x0c06008e */
if(!s->budget--) { s->failed_pc=0x0c06008eu; return 0; }
r[1]=read(ram,r[4]+4,4);
goto P_0c060090;
P_0c060090: /* original d342, guest PC 0x0c060090 */
if(!s->budget--) { s->failed_pc=0x0c060090u; return 0; }
r[3]=read(ram,0x0c06019cu,4);
goto P_0c060092;
P_0c060092: /* original 2312, guest PC 0x0c060092 */
if(!s->budget--) { s->failed_pc=0x0c060092u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c060094;
P_0c060094: /* original 9577, guest PC 0x0c060094 */
if(!s->budget--) { s->failed_pc=0x0c060094u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060186u,2);
goto P_0c060096;
P_0c060096: /* original 6742, guest PC 0x0c060096 */
if(!s->budget--) { s->failed_pc=0x0c060096u; return 0; }
tmp=read(ram,r[4],4);
r[7]=tmp;
goto P_0c060098;
P_0c060098: /* original 5d41, guest PC 0x0c060098 */
if(!s->budget--) { s->failed_pc=0x0c060098u; return 0; }
r[13]=read(ram,r[4]+4,4);
goto P_0c06009a;
P_0c06009a: /* original 2759, guest PC 0x0c06009a */
if(!s->budget--) { s->failed_pc=0x0c06009au; return 0; }
r[7]&=r[5];
goto P_0c06009c;
P_0c06009c: /* original 5e42, guest PC 0x0c06009c */
if(!s->budget--) { s->failed_pc=0x0c06009cu; return 0; }
r[14]=read(ram,r[4]+8,4);
goto P_0c06009e;
P_0c06009e: /* original 2e59, guest PC 0x0c06009e */
if(!s->budget--) { s->failed_pc=0x0c06009eu; return 0; }
r[14]&=r[5];
goto P_0c0600a0;
P_0c0600a0: /* original d03f, guest PC 0x0c0600a0 */
if(!s->budget--) { s->failed_pc=0x0c0600a0u; return 0; }
r[0]=read(ram,0x0c0601a0u,4);
goto P_0c0600a2;
P_0c0600a2: /* original 4e28, guest PC 0x0c0600a2 */
if(!s->budget--) { s->failed_pc=0x0c0600a2u; return 0; }
r[14]<<=16;
goto P_0c0600a4;
P_0c0600a4: /* original 4e08, guest PC 0x0c0600a4 */
if(!s->budget--) { s->failed_pc=0x0c0600a4u; return 0; }
r[14]<<=2;
goto P_0c0600a6;
P_0c0600a6: /* original 6102, guest PC 0x0c0600a6 */
if(!s->budget--) { s->failed_pc=0x0c0600a6u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c0600a8;
P_0c0600a8: /* original 4115, guest PC 0x0c0600a8 */
if(!s->budget--) { s->failed_pc=0x0c0600a8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c0600aa;
P_0c0600aa: /* original 8f0b, guest PC 0x0c0600aa */
if(!s->budget--) { s->failed_pc=0x0c0600aau; return 0; }
cond=r[17]&1u;
r[14]<<=2;
if(!cond) { goto P_0c0600c4; }
goto P_0c0600ae;
P_0c0600ac: /* original 4e08, guest PC 0x0c0600ac */
if(!s->budget--) { s->failed_pc=0x0c0600acu; return 0; }
r[14]<<=2;
goto P_0c0600ae;
P_0c0600ae: /* original d13c, guest PC 0x0c0600ae */
if(!s->budget--) { s->failed_pc=0x0c0600aeu; return 0; }
r[1]=read(ram,0x0c0601a0u,4);
goto P_0c0600b0;
P_0c0600b0: /* original 6212, guest PC 0x0c0600b0 */
if(!s->budget--) { s->failed_pc=0x0c0600b0u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0600b2;
P_0c0600b2: /* original 3d28, guest PC 0x0c0600b2 */
if(!s->budget--) { s->failed_pc=0x0c0600b2u; return 0; }
r[13]-=r[2];
goto P_0c0600b4;
P_0c0600b4: /* original d33b, guest PC 0x0c0600b4 */
if(!s->budget--) { s->failed_pc=0x0c0600b4u; return 0; }
r[3]=read(ram,0x0c0601a4u,4);
goto P_0c0600b6;
P_0c0600b6: /* original 2d59, guest PC 0x0c0600b6 */
if(!s->budget--) { s->failed_pc=0x0c0600b6u; return 0; }
r[13]&=r[5];
goto P_0c0600b8;
P_0c0600b8: /* original 4d18, guest PC 0x0c0600b8 */
if(!s->budget--) { s->failed_pc=0x0c0600b8u; return 0; }
r[13]<<=8;
goto P_0c0600ba;
P_0c0600ba: /* original 4d08, guest PC 0x0c0600ba */
if(!s->budget--) { s->failed_pc=0x0c0600bau; return 0; }
r[13]<<=2;
goto P_0c0600bc;
P_0c0600bc: /* original 27db, guest PC 0x0c0600bc */
if(!s->budget--) { s->failed_pc=0x0c0600bcu; return 0; }
r[7]|=r[13];
goto P_0c0600be;
P_0c0600be: /* original 27eb, guest PC 0x0c0600be */
if(!s->budget--) { s->failed_pc=0x0c0600beu; return 0; }
r[7]|=r[14];
goto P_0c0600c0;
P_0c0600c0: /* original a007, guest PC 0x0c0600c0 */
if(!s->budget--) { s->failed_pc=0x0c0600c0u; return 0; }
write(ram,r[3],r[7],4);
goto P_0c0600d2;
P_0c0600c2: /* original 2372, guest PC 0x0c0600c2 */
if(!s->budget--) { s->failed_pc=0x0c0600c2u; return 0; }
write(ram,r[3],r[7],4);
goto P_0c0600c4;
P_0c0600c4: /* original d137, guest PC 0x0c0600c4 */
if(!s->budget--) { s->failed_pc=0x0c0600c4u; return 0; }
r[1]=read(ram,0x0c0601a4u,4);
goto P_0c0600c6;
P_0c0600c6: /* original 2d59, guest PC 0x0c0600c6 */
if(!s->budget--) { s->failed_pc=0x0c0600c6u; return 0; }
r[13]&=r[5];
goto P_0c0600c8;
P_0c0600c8: /* original 4d18, guest PC 0x0c0600c8 */
if(!s->budget--) { s->failed_pc=0x0c0600c8u; return 0; }
r[13]<<=8;
goto P_0c0600ca;
P_0c0600ca: /* original 4d08, guest PC 0x0c0600ca */
if(!s->budget--) { s->failed_pc=0x0c0600cau; return 0; }
r[13]<<=2;
goto P_0c0600cc;
P_0c0600cc: /* original 27db, guest PC 0x0c0600cc */
if(!s->budget--) { s->failed_pc=0x0c0600ccu; return 0; }
r[7]|=r[13];
goto P_0c0600ce;
P_0c0600ce: /* original 27eb, guest PC 0x0c0600ce */
if(!s->budget--) { s->failed_pc=0x0c0600ceu; return 0; }
r[7]|=r[14];
goto P_0c0600d0;
P_0c0600d0: /* original 2172, guest PC 0x0c0600d0 */
if(!s->budget--) { s->failed_pc=0x0c0600d0u; return 0; }
write(ram,r[1],r[7],4);
goto P_0c0600d2;
P_0c0600d2: /* original 5345, guest PC 0x0c0600d2 */
if(!s->budget--) { s->failed_pc=0x0c0600d2u; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c0600d4;
P_0c0600d4: /* original 5246, guest PC 0x0c0600d4 */
if(!s->budget--) { s->failed_pc=0x0c0600d4u; return 0; }
r[2]=read(ram,r[4]+24,4);
goto P_0c0600d6;
P_0c0600d6: /* original 633c, guest PC 0x0c0600d6 */
if(!s->budget--) { s->failed_pc=0x0c0600d6u; return 0; }
r[3]=r[3]&255u;
goto P_0c0600d8;
P_0c0600d8: /* original d133, guest PC 0x0c0600d8 */
if(!s->budget--) { s->failed_pc=0x0c0600d8u; return 0; }
r[1]=read(ram,0x0c0601a8u,4);
goto P_0c0600da;
P_0c0600da: /* original 622c, guest PC 0x0c0600da */
if(!s->budget--) { s->failed_pc=0x0c0600dau; return 0; }
r[2]=r[2]&255u;
goto P_0c0600dc;
P_0c0600dc: /* original 4218, guest PC 0x0c0600dc */
if(!s->budget--) { s->failed_pc=0x0c0600dcu; return 0; }
r[2]<<=8;
goto P_0c0600de;
P_0c0600de: /* original 232b, guest PC 0x0c0600de */
if(!s->budget--) { s->failed_pc=0x0c0600deu; return 0; }
r[3]|=r[2];
goto P_0c0600e0;
P_0c0600e0: /* original 2132, guest PC 0x0c0600e0 */
if(!s->budget--) { s->failed_pc=0x0c0600e0u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c0600e2;
P_0c0600e2: /* original e501, guest PC 0x0c0600e2 */
if(!s->budget--) { s->failed_pc=0x0c0600e2u; return 0; }
r[5]=0x00000001u;
goto P_0c0600e4;
P_0c0600e4: /* original 5344, guest PC 0x0c0600e4 */
if(!s->budget--) { s->failed_pc=0x0c0600e4u; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c0600e6;
P_0c0600e6: /* original 633d, guest PC 0x0c0600e6 */
if(!s->budget--) { s->failed_pc=0x0c0600e6u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0600e8;
P_0c0600e8: /* original 5243, guest PC 0x0c0600e8 */
if(!s->budget--) { s->failed_pc=0x0c0600e8u; return 0; }
r[2]=read(ram,r[4]+12,4);
goto P_0c0600ea;
P_0c0600ea: /* original 2259, guest PC 0x0c0600ea */
if(!s->budget--) { s->failed_pc=0x0c0600eau; return 0; }
r[2]&=r[5];
goto P_0c0600ec;
P_0c0600ec: /* original 5047, guest PC 0x0c0600ec */
if(!s->budget--) { s->failed_pc=0x0c0600ecu; return 0; }
r[0]=read(ram,r[4]+28,4);
goto P_0c0600ee;
P_0c0600ee: /* original 4228, guest PC 0x0c0600ee */
if(!s->budget--) { s->failed_pc=0x0c0600eeu; return 0; }
r[2]<<=16;
goto P_0c0600f0;
P_0c0600f0: /* original 232b, guest PC 0x0c0600f0 */
if(!s->budget--) { s->failed_pc=0x0c0600f0u; return 0; }
r[3]|=r[2];
goto P_0c0600f2;
P_0c0600f2: /* original 2059, guest PC 0x0c0600f2 */
if(!s->budget--) { s->failed_pc=0x0c0600f2u; return 0; }
r[0]&=r[5];
goto P_0c0600f4;
P_0c0600f4: /* original d22d, guest PC 0x0c0600f4 */
if(!s->budget--) { s->failed_pc=0x0c0600f4u; return 0; }
r[2]=read(ram,0x0c0601acu,4);
goto P_0c0600f6;
P_0c0600f6: /* original 4028, guest PC 0x0c0600f6 */
if(!s->budget--) { s->failed_pc=0x0c0600f6u; return 0; }
r[0]<<=16;
goto P_0c0600f8;
P_0c0600f8: /* original 4008, guest PC 0x0c0600f8 */
if(!s->budget--) { s->failed_pc=0x0c0600f8u; return 0; }
r[0]<<=2;
goto P_0c0600fa;
P_0c0600fa: /* original 230b, guest PC 0x0c0600fa */
if(!s->budget--) { s->failed_pc=0x0c0600fau; return 0; }
r[3]|=r[0];
goto P_0c0600fc;
P_0c0600fc: /* original 2232, guest PC 0x0c0600fc */
if(!s->budget--) { s->failed_pc=0x0c0600fcu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0600fe;
P_0c0600fe: /* original e044, guest PC 0x0c0600fe */
if(!s->budget--) { s->failed_pc=0x0c0600feu; return 0; }
r[0]=0x00000044u;
goto P_0c060100;
P_0c060100: /* original 9342, guest PC 0x0c060100 */
if(!s->budget--) { s->failed_pc=0x0c060100u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060188u,2);
goto P_0c060102;
P_0c060102: /* original 72c4, guest PC 0x0c060102 */
if(!s->budget--) { s->failed_pc=0x0c060102u; return 0; }
r[2]+=0xffffffc4u;
goto P_0c060104;
P_0c060104: /* original 004e, guest PC 0x0c060104 */
if(!s->budget--) { s->failed_pc=0x0c060104u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c060106;
P_0c060106: /* original 2039, guest PC 0x0c060106 */
if(!s->budget--) { s->failed_pc=0x0c060106u; return 0; }
r[0]&=r[3];
goto P_0c060108;
P_0c060108: /* original 2202, guest PC 0x0c060108 */
if(!s->budget--) { s->failed_pc=0x0c060108u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c06010a;
P_0c06010a: /* original e707, guest PC 0x0c06010a */
if(!s->budget--) { s->failed_pc=0x0c06010au; return 0; }
r[7]=0x00000007u;
goto P_0c06010c;
P_0c06010c: /* original 514c, guest PC 0x0c06010c */
if(!s->budget--) { s->failed_pc=0x0c06010cu; return 0; }
r[1]=read(ram,r[4]+48,4);
goto P_0c06010e;
P_0c06010e: /* original 2179, guest PC 0x0c06010e */
if(!s->budget--) { s->failed_pc=0x0c06010eu; return 0; }
r[1]&=r[7];
goto P_0c060110;
P_0c060110: /* original 504b, guest PC 0x0c060110 */
if(!s->budget--) { s->failed_pc=0x0c060110u; return 0; }
r[0]=read(ram,r[4]+44,4);
goto P_0c060112;
P_0c060112: /* original 2059, guest PC 0x0c060112 */
if(!s->budget--) { s->failed_pc=0x0c060112u; return 0; }
r[0]&=r[5];
goto P_0c060114;
P_0c060114: /* original 4008, guest PC 0x0c060114 */
if(!s->budget--) { s->failed_pc=0x0c060114u; return 0; }
r[0]<<=2;
goto P_0c060116;
P_0c060116: /* original 4000, guest PC 0x0c060116 */
if(!s->budget--) { s->failed_pc=0x0c060116u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c060118;
P_0c060118: /* original 210b, guest PC 0x0c060118 */
if(!s->budget--) { s->failed_pc=0x0c060118u; return 0; }
r[1]|=r[0];
goto P_0c06011a;
P_0c06011a: /* original 504d, guest PC 0x0c06011a */
if(!s->budget--) { s->failed_pc=0x0c06011au; return 0; }
r[0]=read(ram,r[4]+52,4);
goto P_0c06011c;
P_0c06011c: /* original 600c, guest PC 0x0c06011c */
if(!s->budget--) { s->failed_pc=0x0c06011cu; return 0; }
r[0]=r[0]&255u;
goto P_0c06011e;
P_0c06011e: /* original 4018, guest PC 0x0c06011e */
if(!s->budget--) { s->failed_pc=0x0c06011eu; return 0; }
r[0]<<=8;
goto P_0c060120;
P_0c060120: /* original 210b, guest PC 0x0c060120 */
if(!s->budget--) { s->failed_pc=0x0c060120u; return 0; }
r[1]|=r[0];
goto P_0c060122;
P_0c060122: /* original 504e, guest PC 0x0c060122 */
if(!s->budget--) { s->failed_pc=0x0c060122u; return 0; }
r[0]=read(ram,r[4]+56,4);
goto P_0c060124;
P_0c060124: /* original 600c, guest PC 0x0c060124 */
if(!s->budget--) { s->failed_pc=0x0c060124u; return 0; }
r[0]=r[0]&255u;
goto P_0c060126;
P_0c060126: /* original 4028, guest PC 0x0c060126 */
if(!s->budget--) { s->failed_pc=0x0c060126u; return 0; }
r[0]<<=16;
goto P_0c060128;
P_0c060128: /* original 210b, guest PC 0x0c060128 */
if(!s->budget--) { s->failed_pc=0x0c060128u; return 0; }
r[1]|=r[0];
goto P_0c06012a;
P_0c06012a: /* original d021, guest PC 0x0c06012a */
if(!s->budget--) { s->failed_pc=0x0c06012au; return 0; }
r[0]=read(ram,0x0c0601b0u,4);
goto P_0c06012c;
P_0c06012c: /* original 2012, guest PC 0x0c06012c */
if(!s->budget--) { s->failed_pc=0x0c06012cu; return 0; }
write(ram,r[0],r[1],4);
goto P_0c06012e;
P_0c06012e: /* original 5348, guest PC 0x0c06012e */
if(!s->budget--) { s->failed_pc=0x0c06012eu; return 0; }
r[3]=read(ram,r[4]+32,4);
goto P_0c060130;
P_0c060130: /* original 514a, guest PC 0x0c060130 */
if(!s->budget--) { s->failed_pc=0x0c060130u; return 0; }
r[1]=read(ram,r[4]+40,4);
goto P_0c060132;
P_0c060132: /* original 2359, guest PC 0x0c060132 */
if(!s->budget--) { s->failed_pc=0x0c060132u; return 0; }
r[3]&=r[5];
goto P_0c060134;
P_0c060134: /* original 504f, guest PC 0x0c060134 */
if(!s->budget--) { s->failed_pc=0x0c060134u; return 0; }
r[0]=read(ram,r[4]+60,4);
goto P_0c060136;
P_0c060136: /* original 2159, guest PC 0x0c060136 */
if(!s->budget--) { s->failed_pc=0x0c060136u; return 0; }
r[1]&=r[5];
goto P_0c060138;
P_0c060138: /* original 4100, guest PC 0x0c060138 */
if(!s->budget--) { s->failed_pc=0x0c060138u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c06013a;
P_0c06013a: /* original 231b, guest PC 0x0c06013a */
if(!s->budget--) { s->failed_pc=0x0c06013au; return 0; }
r[3]|=r[1];
goto P_0c06013c;
P_0c06013c: /* original c903, guest PC 0x0c06013c */
if(!s->budget--) { s->failed_pc=0x0c06013cu; return 0; }
r[0]&=3u;
goto P_0c06013e;
P_0c06013e: /* original 4008, guest PC 0x0c06013e */
if(!s->budget--) { s->failed_pc=0x0c06013eu; return 0; }
r[0]<<=2;
goto P_0c060140;
P_0c060140: /* original 230b, guest PC 0x0c060140 */
if(!s->budget--) { s->failed_pc=0x0c060140u; return 0; }
r[3]|=r[0];
goto P_0c060142;
P_0c060142: /* original e040, guest PC 0x0c060142 */
if(!s->budget--) { s->failed_pc=0x0c060142u; return 0; }
r[0]=0x00000040u;
goto P_0c060144;
P_0c060144: /* original 004e, guest PC 0x0c060144 */
if(!s->budget--) { s->failed_pc=0x0c060144u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c060146;
P_0c060146: /* original 2709, guest PC 0x0c060146 */
if(!s->budget--) { s->failed_pc=0x0c060146u; return 0; }
r[7]&=r[0];
goto P_0c060148;
P_0c060148: /* original 4708, guest PC 0x0c060148 */
if(!s->budget--) { s->failed_pc=0x0c060148u; return 0; }
r[7]<<=2;
goto P_0c06014a;
P_0c06014a: /* original 4708, guest PC 0x0c06014a */
if(!s->budget--) { s->failed_pc=0x0c06014au; return 0; }
r[7]<<=2;
goto P_0c06014c;
P_0c06014c: /* original 237b, guest PC 0x0c06014c */
if(!s->budget--) { s->failed_pc=0x0c06014cu; return 0; }
r[3]|=r[7];
goto P_0c06014e;
P_0c06014e: /* original e070, guest PC 0x0c06014e */
if(!s->budget--) { s->failed_pc=0x0c06014eu; return 0; }
r[0]=0x00000070u;
goto P_0c060150;
P_0c060150: /* original 014c, guest PC 0x0c060150 */
if(!s->budget--) { s->failed_pc=0x0c060150u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c060152;
P_0c060152: /* original e216, guest PC 0x0c060152 */
if(!s->budget--) { s->failed_pc=0x0c060152u; return 0; }
r[2]=0x00000016u;
goto P_0c060154;
P_0c060154: /* original 611c, guest PC 0x0c060154 */
if(!s->budget--) { s->failed_pc=0x0c060154u; return 0; }
r[1]=r[1]&255u;
goto P_0c060156;
P_0c060156: /* original 4118, guest PC 0x0c060156 */
if(!s->budget--) { s->failed_pc=0x0c060156u; return 0; }
r[1]<<=8;
goto P_0c060158;
P_0c060158: /* original 231b, guest PC 0x0c060158 */
if(!s->budget--) { s->failed_pc=0x0c060158u; return 0; }
r[3]|=r[1];
goto P_0c06015a;
P_0c06015a: /* original e068, guest PC 0x0c06015a */
if(!s->budget--) { s->failed_pc=0x0c06015au; return 0; }
r[0]=0x00000068u;
goto P_0c06015c;
P_0c06015c: /* original 014e, guest PC 0x0c06015c */
if(!s->budget--) { s->failed_pc=0x0c06015cu; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c06015e;
P_0c06015e: /* original e064, guest PC 0x0c06015e */
if(!s->budget--) { s->failed_pc=0x0c06015eu; return 0; }
r[0]=0x00000064u;
goto P_0c060160;
P_0c060160: /* original 2619, guest PC 0x0c060160 */
if(!s->budget--) { s->failed_pc=0x0c060160u; return 0; }
r[6]&=r[1];
goto P_0c060162;
P_0c060162: /* original 4628, guest PC 0x0c060162 */
if(!s->budget--) { s->failed_pc=0x0c060162u; return 0; }
r[6]<<=16;
goto P_0c060164;
P_0c060164: /* original 014e, guest PC 0x0c060164 */
if(!s->budget--) { s->failed_pc=0x0c060164u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c060166;
P_0c060166: /* original 236b, guest PC 0x0c060166 */
if(!s->budget--) { s->failed_pc=0x0c060166u; return 0; }
r[3]|=r[6];
goto P_0c060168;
P_0c060168: /* original 2159, guest PC 0x0c060168 */
if(!s->budget--) { s->failed_pc=0x0c060168u; return 0; }
r[1]&=r[5];
goto P_0c06016a;
P_0c06016a: /* original 412c, guest PC 0x0c06016a */
if(!s->budget--) { s->failed_pc=0x0c06016au; return 0; }
r[1]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[1]>>((-r[2])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[2]&31u);
goto P_0c06016c;
P_0c06016c: /* original 231b, guest PC 0x0c06016c */
if(!s->budget--) { s->failed_pc=0x0c06016cu; return 0; }
r[3]|=r[1];
goto P_0c06016e;
P_0c06016e: /* original e06c, guest PC 0x0c06016e */
if(!s->budget--) { s->failed_pc=0x0c06016eu; return 0; }
r[0]=0x0000006cu;
goto P_0c060170;
P_0c060170: /* original 014e, guest PC 0x0c060170 */
if(!s->budget--) { s->failed_pc=0x0c060170u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c060172;
P_0c060172: /* original e217, guest PC 0x0c060172 */
if(!s->budget--) { s->failed_pc=0x0c060172u; return 0; }
r[2]=0x00000017u;
goto P_0c060174;
P_0c060174: /* original 2159, guest PC 0x0c060174 */
if(!s->budget--) { s->failed_pc=0x0c060174u; return 0; }
r[1]&=r[5];
goto P_0c060176;
P_0c060176: /* original 412c, guest PC 0x0c060176 */
if(!s->budget--) { s->failed_pc=0x0c060176u; return 0; }
r[1]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[1]>>((-r[2])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[2]&31u);
goto P_0c060178;
P_0c060178: /* original 231b, guest PC 0x0c060178 */
if(!s->budget--) { s->failed_pc=0x0c060178u; return 0; }
r[3]|=r[1];
goto P_0c06017a;
P_0c06017a: /* original d10e, guest PC 0x0c06017a */
if(!s->budget--) { s->failed_pc=0x0c06017au; return 0; }
r[1]=read(ram,0x0c0601b4u,4);
goto P_0c06017c;
P_0c06017c: /* original 2132, guest PC 0x0c06017c */
if(!s->budget--) { s->failed_pc=0x0c06017cu; return 0; }
write(ram,r[1],r[3],4);
goto P_0c06017e;
P_0c06017e: /* original 6df6, guest PC 0x0c06017e */
if(!s->budget--) { s->failed_pc=0x0c06017eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c060180;
P_0c060180: /* original 000b, guest PC 0x0c060180 */
if(!s->budget--) { s->failed_pc=0x0c060180u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c060182: /* original 6ef6, guest PC 0x0c060182 */
if(!s->budget--) { s->failed_pc=0x0c060182u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c060184u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c060184u; return 0; } return 1;
P_0c0601b8: /* original 2fe6, guest PC 0x0c0601b8 */
if(!s->budget--) { s->failed_pc=0x0c0601b8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0601ba;
P_0c0601ba: /* original 2fd6, guest PC 0x0c0601ba */
if(!s->budget--) { s->failed_pc=0x0c0601bau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0601bc;
P_0c0601bc: /* original 2fc6, guest PC 0x0c0601bc */
if(!s->budget--) { s->failed_pc=0x0c0601bcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0601be;
P_0c0601be: /* original ed00, guest PC 0x0c0601be */
if(!s->budget--) { s->failed_pc=0x0c0601beu; return 0; }
r[13]=0x00000000u;
goto P_0c0601c0;
P_0c0601c0: /* original d233, guest PC 0x0c0601c0 */
if(!s->budget--) { s->failed_pc=0x0c0601c0u; return 0; }
r[2]=read(ram,0x0c060290u,4);
goto P_0c0601c2;
P_0c0601c2: /* original ec01, guest PC 0x0c0601c2 */
if(!s->budget--) { s->failed_pc=0x0c0601c2u; return 0; }
r[12]=0x00000001u;
goto P_0c0601c4;
P_0c0601c4: /* original d333, guest PC 0x0c0601c4 */
if(!s->budget--) { s->failed_pc=0x0c0601c4u; return 0; }
r[3]=read(ram,0x0c060294u,4);
goto P_0c0601c6;
P_0c0601c6: /* original 2fb6, guest PC 0x0c0601c6 */
if(!s->budget--) { s->failed_pc=0x0c0601c6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0601c8;
P_0c0601c8: /* original 2fa6, guest PC 0x0c0601c8 */
if(!s->budget--) { s->failed_pc=0x0c0601c8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0601ca;
P_0c0601ca: /* original ea20, guest PC 0x0c0601ca */
if(!s->budget--) { s->failed_pc=0x0c0601cau; return 0; }
r[10]=0x00000020u;
goto P_0c0601cc;
P_0c0601cc: /* original 2f96, guest PC 0x0c0601cc */
if(!s->budget--) { s->failed_pc=0x0c0601ccu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0601ce;
P_0c0601ce: /* original 2f86, guest PC 0x0c0601ce */
if(!s->budget--) { s->failed_pc=0x0c0601ceu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0601d0;
P_0c0601d0: /* original 4f22, guest PC 0x0c0601d0 */
if(!s->budget--) { s->failed_pc=0x0c0601d0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0601d2;
P_0c0601d2: /* original 9058, guest PC 0x0c0601d2 */
if(!s->budget--) { s->failed_pc=0x0c0601d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060286u,2);
goto P_0c0601d4;
P_0c0601d4: /* original 3f0c, guest PC 0x0c0601d4 */
if(!s->budget--) { s->failed_pc=0x0c0601d4u; return 0; }
r[15]+=r[0];
goto P_0c0601d6;
P_0c0601d6: /* original 6ef3, guest PC 0x0c0601d6 */
if(!s->budget--) { s->failed_pc=0x0c0601d6u; return 0; }
r[14]=r[15];
goto P_0c0601d8;
P_0c0601d8: /* original 7e18, guest PC 0x0c0601d8 */
if(!s->budget--) { s->failed_pc=0x0c0601d8u; return 0; }
r[14]+=0x00000018u;
goto P_0c0601da;
P_0c0601da: /* original 61f3, guest PC 0x0c0601da */
if(!s->budget--) { s->failed_pc=0x0c0601dau; return 0; }
r[1]=r[15];
goto P_0c0601dc;
P_0c0601dc: /* original 430b, guest PC 0x0c0601dc */
if(!s->budget--) { s->failed_pc=0x0c0601dcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0601e0u;
r[0]=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0601e0u) { target=s->pc; goto dispatch; }
goto P_0c0601e0;
P_0c0601de: /* original e018, guest PC 0x0c0601de */
if(!s->budget--) { s->failed_pc=0x0c0601deu; return 0; }
r[0]=0x00000018u;
goto P_0c0601e0;
P_0c0601e0: /* original 9052, guest PC 0x0c0601e0 */
if(!s->budget--) { s->failed_pc=0x0c0601e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060288u,2);
goto P_0c0601e2;
P_0c0601e2: /* original 6b63, guest PC 0x0c0601e2 */
if(!s->budget--) { s->failed_pc=0x0c0601e2u; return 0; }
r[11]=r[6];
goto P_0c0601e4;
P_0c0601e4: /* original 01fe, guest PC 0x0c0601e4 */
if(!s->budget--) { s->failed_pc=0x0c0601e4u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0601e6;
P_0c0601e6: /* original 63f3, guest PC 0x0c0601e6 */
if(!s->budget--) { s->failed_pc=0x0c0601e6u; return 0; }
r[3]=r[15];
goto P_0c0601e8;
P_0c0601e8: /* original 4b08, guest PC 0x0c0601e8 */
if(!s->budget--) { s->failed_pc=0x0c0601e8u; return 0; }
r[11]<<=2;
goto P_0c0601ea;
P_0c0601ea: /* original 3b3c, guest PC 0x0c0601ea */
if(!s->budget--) { s->failed_pc=0x0c0601eau; return 0; }
r[11]+=r[3];
goto P_0c0601ec;
P_0c0601ec: /* original 2118, guest PC 0x0c0601ec */
if(!s->budget--) { s->failed_pc=0x0c0601ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0601ee;
P_0c0601ee: /* original 8d04, guest PC 0x0c0601ee */
if(!s->budget--) { s->failed_pc=0x0c0601eeu; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[11],4);
r[11]=tmp;
if(cond) { goto P_0c0601fa; }
goto P_0c0601f2;
P_0c0601f0: /* original 6bb2, guest PC 0x0c0601f0 */
if(!s->budget--) { s->failed_pc=0x0c0601f0u; return 0; }
tmp=read(ram,r[11],4);
r[11]=tmp;
goto P_0c0601f2;
P_0c0601f2: /* original 914a, guest PC 0x0c0601f2 */
if(!s->budget--) { s->failed_pc=0x0c0601f2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06028au,2);
goto P_0c0601f4;
P_0c0601f4: /* original 3510, guest PC 0x0c0601f4 */
if(!s->budget--) { s->failed_pc=0x0c0601f4u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[1])!=0);
goto P_0c0601f6;
P_0c0601f6: /* original 8b00, guest PC 0x0c0601f6 */
if(!s->budget--) { s->failed_pc=0x0c0601f6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0601fa; }
goto P_0c0601f8;
P_0c0601f8: /* original 4500, guest PC 0x0c0601f8 */
if(!s->budget--) { s->failed_pc=0x0c0601f8u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0601fa;
P_0c0601fa: /* original d327, guest PC 0x0c0601fa */
if(!s->budget--) { s->failed_pc=0x0c0601fau; return 0; }
r[3]=read(ram,0x0c060298u,4);
goto P_0c0601fc;
P_0c0601fc: /* original 2342, guest PC 0x0c0601fc */
if(!s->budget--) { s->failed_pc=0x0c0601fcu; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0601fe;
P_0c0601fe: /* original d227, guest PC 0x0c0601fe */
if(!s->budget--) { s->failed_pc=0x0c0601feu; return 0; }
r[2]=read(ram,0x0c06029cu,4);
goto P_0c060200;
P_0c060200: /* original 2252, guest PC 0x0c060200 */
if(!s->budget--) { s->failed_pc=0x0c060200u; return 0; }
write(ram,r[2],r[5],4);
goto P_0c060202;
P_0c060202: /* original e040, guest PC 0x0c060202 */
if(!s->budget--) { s->failed_pc=0x0c060202u; return 0; }
r[0]=0x00000040u;
goto P_0c060204;
P_0c060204: /* original d126, guest PC 0x0c060204 */
if(!s->budget--) { s->failed_pc=0x0c060204u; return 0; }
r[1]=read(ram,0x0c0602a0u,4);
goto P_0c060206;
P_0c060206: /* original 1ec8, guest PC 0x0c060206 */
if(!s->budget--) { s->failed_pc=0x0c060206u; return 0; }
write(ram,r[14]+32,r[12],4);
goto P_0c060208;
P_0c060208: /* original 1ede, guest PC 0x0c060208 */
if(!s->budget--) { s->failed_pc=0x0c060208u; return 0; }
write(ram,r[14]+56,r[13],4);
goto P_0c06020a;
P_0c06020a: /* original 1edd, guest PC 0x0c06020a */
if(!s->budget--) { s->failed_pc=0x0c06020au; return 0; }
write(ram,r[14]+52,r[13],4);
goto P_0c06020c;
P_0c06020c: /* original 0ed6, guest PC 0x0c06020c */
if(!s->budget--) { s->failed_pc=0x0c06020cu; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c06020e;
P_0c06020e: /* original e070, guest PC 0x0c06020e */
if(!s->budget--) { s->failed_pc=0x0c06020eu; return 0; }
r[0]=0x00000070u;
goto P_0c060210;
P_0c060210: /* original 0ed6, guest PC 0x0c060210 */
if(!s->budget--) { s->failed_pc=0x0c060210u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c060212;
P_0c060212: /* original e068, guest PC 0x0c060212 */
if(!s->budget--) { s->failed_pc=0x0c060212u; return 0; }
r[0]=0x00000068u;
goto P_0c060214;
P_0c060214: /* original 0ed6, guest PC 0x0c060214 */
if(!s->budget--) { s->failed_pc=0x0c060214u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c060216;
P_0c060216: /* original e064, guest PC 0x0c060216 */
if(!s->budget--) { s->failed_pc=0x0c060216u; return 0; }
r[0]=0x00000064u;
goto P_0c060218;
P_0c060218: /* original 0ed6, guest PC 0x0c060218 */
if(!s->budget--) { s->failed_pc=0x0c060218u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c06021a;
P_0c06021a: /* original 6312, guest PC 0x0c06021a */
if(!s->budget--) { s->failed_pc=0x0c06021au; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c06021c;
P_0c06021c: /* original 23c8, guest PC 0x0c06021c */
if(!s->budget--) { s->failed_pc=0x0c06021cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c06021e;
P_0c06021e: /* original 8903, guest PC 0x0c06021e */
if(!s->budget--) { s->failed_pc=0x0c06021eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060228; }
goto P_0c060220;
P_0c060220: /* original e06c, guest PC 0x0c060220 */
if(!s->budget--) { s->failed_pc=0x0c060220u; return 0; }
r[0]=0x0000006cu;
goto P_0c060222;
P_0c060222: /* original 0ec6, guest PC 0x0c060222 */
if(!s->budget--) { s->failed_pc=0x0c060222u; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c060224;
P_0c060224: /* original a007, guest PC 0x0c060224 */
if(!s->budget--) { s->failed_pc=0x0c060224u; return 0; }
r[9]=0x00000001u;
goto P_0c060236;
P_0c060226: /* original e901, guest PC 0x0c060226 */
if(!s->budget--) { s->failed_pc=0x0c060226u; return 0; }
r[9]=0x00000001u;
goto P_0c060228;
P_0c060228: /* original e06c, guest PC 0x0c060228 */
if(!s->budget--) { s->failed_pc=0x0c060228u; return 0; }
r[0]=0x0000006cu;
goto P_0c06022a;
P_0c06022a: /* original 0ed6, guest PC 0x0c06022a */
if(!s->budget--) { s->failed_pc=0x0c06022au; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c06022c;
P_0c06022c: /* original 6073, guest PC 0x0c06022c */
if(!s->budget--) { s->failed_pc=0x0c06022cu; return 0; }
r[0]=r[7];
goto P_0c06022e;
P_0c06022e: /* original 0009, guest PC 0x0c06022e */
if(!s->budget--) { s->failed_pc=0x0c06022eu; return 0; }
goto P_0c060230;
P_0c060230: /* original 8801, guest PC 0x0c060230 */
if(!s->budget--) { s->failed_pc=0x0c060230u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c060232;
P_0c060232: /* original 8b02, guest PC 0x0c060232 */
if(!s->budget--) { s->failed_pc=0x0c060232u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06023a; }
goto P_0c060234;
P_0c060234: /* original e902, guest PC 0x0c060234 */
if(!s->budget--) { s->failed_pc=0x0c060234u; return 0; }
r[9]=0x00000002u;
goto P_0c060236;
P_0c060236: /* original a002, guest PC 0x0c060236 */
if(!s->budget--) { s->failed_pc=0x0c060236u; return 0; }
r[8]=0x00000000u;
goto P_0c06023e;
P_0c060238: /* original e800, guest PC 0x0c060238 */
if(!s->budget--) { s->failed_pc=0x0c060238u; return 0; }
r[8]=0x00000000u;
goto P_0c06023a;
P_0c06023a: /* original e901, guest PC 0x0c06023a */
if(!s->budget--) { s->failed_pc=0x0c06023au; return 0; }
r[9]=0x00000001u;
goto P_0c06023c;
P_0c06023c: /* original e801, guest PC 0x0c06023c */
if(!s->budget--) { s->failed_pc=0x0c06023cu; return 0; }
r[8]=0x00000001u;
goto P_0c06023e;
P_0c06023e: /* original 60b3, guest PC 0x0c06023e */
if(!s->budget--) { s->failed_pc=0x0c06023eu; return 0; }
r[0]=r[11];
goto P_0c060240;
P_0c060240: /* original 0009, guest PC 0x0c060240 */
if(!s->budget--) { s->failed_pc=0x0c060240u; return 0; }
goto P_0c060242;
P_0c060242: /* original 8810, guest PC 0x0c060242 */
if(!s->budget--) { s->failed_pc=0x0c060242u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c060244;
P_0c060244: /* original 8905, guest PC 0x0c060244 */
if(!s->budget--) { s->failed_pc=0x0c060244u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060252; }
goto P_0c060246;
P_0c060246: /* original 8818, guest PC 0x0c060246 */
if(!s->budget--) { s->failed_pc=0x0c060246u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000018u)!=0);
goto P_0c060248;
P_0c060248: /* original 8919, guest PC 0x0c060248 */
if(!s->budget--) { s->failed_pc=0x0c060248u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06027e; }
goto P_0c06024a;
P_0c06024a: /* original 8820, guest PC 0x0c06024a */
if(!s->budget--) { s->failed_pc=0x0c06024au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c06024c;
P_0c06024c: /* original 892a, guest PC 0x0c06024c */
if(!s->budget--) { s->failed_pc=0x0c06024cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0602a4; }
goto P_0c06024e;
P_0c06024e: /* original a02e, guest PC 0x0c06024e */
if(!s->budget--) { s->failed_pc=0x0c06024eu; return 0; }
goto P_0c0602ae;
P_0c060250: /* original 0009, guest PC 0x0c060250 */
if(!s->budget--) { s->failed_pc=0x0c060250u; return 0; }
goto P_0c060252;
P_0c060252: /* original 6063, guest PC 0x0c060252 */
if(!s->budget--) { s->failed_pc=0x0c060252u; return 0; }
r[0]=r[6];
goto P_0c060254;
P_0c060254: /* original 0009, guest PC 0x0c060254 */
if(!s->budget--) { s->failed_pc=0x0c060254u; return 0; }
goto P_0c060256;
P_0c060256: /* original 8803, guest PC 0x0c060256 */
if(!s->budget--) { s->failed_pc=0x0c060256u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c060258;
P_0c060258: /* original 8b02, guest PC 0x0c060258 */
if(!s->budget--) { s->failed_pc=0x0c060258u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060260; }
goto P_0c06025a;
P_0c06025a: /* original e203, guest PC 0x0c06025a */
if(!s->budget--) { s->failed_pc=0x0c06025au; return 0; }
r[2]=0x00000003u;
goto P_0c06025c;
P_0c06025c: /* original a007, guest PC 0x0c06025c */
if(!s->budget--) { s->failed_pc=0x0c06025cu; return 0; }
write(ram,r[14]+48,r[2],4);
goto P_0c06026e;
P_0c06025e: /* original 1e2c, guest PC 0x0c06025e */
if(!s->budget--) { s->failed_pc=0x0c06025eu; return 0; }
write(ram,r[14]+48,r[2],4);
goto P_0c060260;
P_0c060260: /* original 2668, guest PC 0x0c060260 */
if(!s->budget--) { s->failed_pc=0x0c060260u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c060262;
P_0c060262: /* original 8906, guest PC 0x0c060262 */
if(!s->budget--) { s->failed_pc=0x0c060262u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060272; }
goto P_0c060264;
P_0c060264: /* original 6063, guest PC 0x0c060264 */
if(!s->budget--) { s->failed_pc=0x0c060264u; return 0; }
r[0]=r[6];
goto P_0c060266;
P_0c060266: /* original 0009, guest PC 0x0c060266 */
if(!s->budget--) { s->failed_pc=0x0c060266u; return 0; }
goto P_0c060268;
P_0c060268: /* original 8801, guest PC 0x0c060268 */
if(!s->budget--) { s->failed_pc=0x0c060268u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06026a;
P_0c06026a: /* original 8b02, guest PC 0x0c06026a */
if(!s->budget--) { s->failed_pc=0x0c06026au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060272; }
goto P_0c06026c;
P_0c06026c: /* original 1edc, guest PC 0x0c06026c */
if(!s->budget--) { s->failed_pc=0x0c06026cu; return 0; }
write(ram,r[14]+48,r[13],4);
goto P_0c06026e;
P_0c06026e: /* original a002, guest PC 0x0c06026e */
if(!s->budget--) { s->failed_pc=0x0c06026eu; return 0; }
write(ram,r[14]+60,r[13],4);
goto P_0c060276;
P_0c060270: /* original 1edf, guest PC 0x0c060270 */
if(!s->budget--) { s->failed_pc=0x0c060270u; return 0; }
write(ram,r[14]+60,r[13],4);
goto P_0c060272;
P_0c060272: /* original 1ecc, guest PC 0x0c060272 */
if(!s->budget--) { s->failed_pc=0x0c060272u; return 0; }
write(ram,r[14]+48,r[12],4);
goto P_0c060274;
P_0c060274: /* original 1ecf, guest PC 0x0c060274 */
if(!s->budget--) { s->failed_pc=0x0c060274u; return 0; }
write(ram,r[14]+60,r[12],4);
goto P_0c060276;
P_0c060276: /* original 9009, guest PC 0x0c060276 */
if(!s->budget--) { s->failed_pc=0x0c060276u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06028cu,2);
goto P_0c060278;
P_0c060278: /* original 02fe, guest PC 0x0c060278 */
if(!s->budget--) { s->failed_pc=0x0c060278u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c06027a;
P_0c06027a: /* original a018, guest PC 0x0c06027a */
if(!s->budget--) { s->failed_pc=0x0c06027au; return 0; }
write(ram,r[14]+44,r[2],4);
goto P_0c0602ae;
P_0c06027c: /* original 1e2b, guest PC 0x0c06027c */
if(!s->budget--) { s->failed_pc=0x0c06027cu; return 0; }
write(ram,r[14]+44,r[2],4);
goto P_0c06027e;
P_0c06027e: /* original e104, guest PC 0x0c06027e */
if(!s->budget--) { s->failed_pc=0x0c06027eu; return 0; }
r[1]=0x00000004u;
goto P_0c060280;
P_0c060280: /* original 1e1c, guest PC 0x0c060280 */
if(!s->budget--) { s->failed_pc=0x0c060280u; return 0; }
write(ram,r[14]+48,r[1],4);
goto P_0c060282;
P_0c060282: /* original a012, guest PC 0x0c060282 */
if(!s->budget--) { s->failed_pc=0x0c060282u; return 0; }
r[3]=0x00000002u;
goto P_0c0602aa;
P_0c060284: /* original e302, guest PC 0x0c060284 */
if(!s->budget--) { s->failed_pc=0x0c060284u; return 0; }
r[3]=0x00000002u;
if(!vf3_matrix_family(0x0c060286u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c060286u; return 0; } return 1;
P_0c0602a4: /* original e206, guest PC 0x0c0602a4 */
if(!s->budget--) { s->failed_pc=0x0c0602a4u; return 0; }
r[2]=0x00000006u;
goto P_0c0602a6;
P_0c0602a6: /* original e303, guest PC 0x0c0602a6 */
if(!s->budget--) { s->failed_pc=0x0c0602a6u; return 0; }
r[3]=0x00000003u;
goto P_0c0602a8;
P_0c0602a8: /* original 1e2c, guest PC 0x0c0602a8 */
if(!s->budget--) { s->failed_pc=0x0c0602a8u; return 0; }
write(ram,r[14]+48,r[2],4);
goto P_0c0602aa;
P_0c0602aa: /* original 1e3f, guest PC 0x0c0602aa */
if(!s->budget--) { s->failed_pc=0x0c0602aau; return 0; }
write(ram,r[14]+60,r[3],4);
goto P_0c0602ac;
P_0c0602ac: /* original 1edb, guest PC 0x0c0602ac */
if(!s->budget--) { s->failed_pc=0x0c0602acu; return 0; }
write(ram,r[14]+44,r[13],4);
goto P_0c0602ae;
P_0c0602ae: /* original 1eda, guest PC 0x0c0602ae */
if(!s->budget--) { s->failed_pc=0x0c0602aeu; return 0; }
write(ram,r[14]+40,r[13],4);
goto P_0c0602b0;
P_0c0602b0: /* original 1e79, guest PC 0x0c0602b0 */
if(!s->budget--) { s->failed_pc=0x0c0602b0u; return 0; }
write(ram,r[14]+36,r[7],4);
goto P_0c0602b2;
P_0c0602b2: /* original 1ed7, guest PC 0x0c0602b2 */
if(!s->budget--) { s->failed_pc=0x0c0602b2u; return 0; }
write(ram,r[14]+28,r[13],4);
goto P_0c0602b4;
P_0c0602b4: /* original 04b7, guest PC 0x0c0602b4 */
if(!s->budget--) { s->failed_pc=0x0c0602b4u; return 0; }
r[19]=r[4]*r[11];
goto P_0c0602b6;
P_0c0602b6: /* original 061a, guest PC 0x0c0602b6 */
if(!s->budget--) { s->failed_pc=0x0c0602b6u; return 0; }
r[6]=r[19];
goto P_0c0602b8;
P_0c0602b8: /* original d337, guest PC 0x0c0602b8 */
if(!s->budget--) { s->failed_pc=0x0c0602b8u; return 0; }
r[3]=read(ram,0x0c060398u,4);
goto P_0c0602ba;
P_0c0602ba: /* original 6163, guest PC 0x0c0602ba */
if(!s->budget--) { s->failed_pc=0x0c0602bau; return 0; }
r[1]=r[6];
goto P_0c0602bc;
P_0c0602bc: /* original 430b, guest PC 0x0c0602bc */
if(!s->budget--) { s->failed_pc=0x0c0602bcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0602c0u;
r[0]=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0602c0u) { target=s->pc; goto dispatch; }
goto P_0c0602c0;
P_0c0602be: /* original e040, guest PC 0x0c0602be */
if(!s->budget--) { s->failed_pc=0x0c0602beu; return 0; }
r[0]=0x00000040u;
goto P_0c0602c0;
P_0c0602c0: /* original e144, guest PC 0x0c0602c0 */
if(!s->budget--) { s->failed_pc=0x0c0602c0u; return 0; }
r[1]=0x00000044u;
goto P_0c0602c2;
P_0c0602c2: /* original 31ec, guest PC 0x0c0602c2 */
if(!s->budget--) { s->failed_pc=0x0c0602c2u; return 0; }
r[1]+=r[14];
goto P_0c0602c4;
P_0c0602c4: /* original 2102, guest PC 0x0c0602c4 */
if(!s->budget--) { s->failed_pc=0x0c0602c4u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0602c6;
P_0c0602c6: /* original 6163, guest PC 0x0c0602c6 */
if(!s->budget--) { s->failed_pc=0x0c0602c6u; return 0; }
r[1]=r[6];
goto P_0c0602c8;
P_0c0602c8: /* original 60a3, guest PC 0x0c0602c8 */
if(!s->budget--) { s->failed_pc=0x0c0602c8u; return 0; }
r[0]=r[10];
goto P_0c0602ca;
P_0c0602ca: /* original 0009, guest PC 0x0c0602ca */
if(!s->budget--) { s->failed_pc=0x0c0602cau; return 0; }
goto P_0c0602cc;
P_0c0602cc: /* original d332, guest PC 0x0c0602cc */
if(!s->budget--) { s->failed_pc=0x0c0602ccu; return 0; }
r[3]=read(ram,0x0c060398u,4);
goto P_0c0602ce;
P_0c0602ce: /* original 430b, guest PC 0x0c0602ce */
if(!s->budget--) { s->failed_pc=0x0c0602ceu; return 0; }
target=r[3];
r[16]=code_base|0x0c0602d2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0602d2u) { target=s->pc; goto dispatch; }
goto P_0c0602d2;
P_0c0602d0: /* original 0009, guest PC 0x0c0602d0 */
if(!s->budget--) { s->failed_pc=0x0c0602d0u; return 0; }
goto P_0c0602d2;
P_0c0602d2: /* original 70ff, guest PC 0x0c0602d2 */
if(!s->budget--) { s->failed_pc=0x0c0602d2u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0602d4;
P_0c0602d4: /* original d230, guest PC 0x0c0602d4 */
if(!s->budget--) { s->failed_pc=0x0c0602d4u; return 0; }
r[2]=read(ram,0x0c060398u,4);
goto P_0c0602d6;
P_0c0602d6: /* original 61b3, guest PC 0x0c0602d6 */
if(!s->budget--) { s->failed_pc=0x0c0602d6u; return 0; }
r[1]=r[11];
goto P_0c0602d8;
P_0c0602d8: /* original 2e02, guest PC 0x0c0602d8 */
if(!s->budget--) { s->failed_pc=0x0c0602d8u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c0602da;
P_0c0602da: /* original 420b, guest PC 0x0c0602da */
if(!s->budget--) { s->failed_pc=0x0c0602dau; return 0; }
target=r[2];
r[16]=code_base|0x0c0602deu;
r[0]=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0602deu) { target=s->pc; goto dispatch; }
goto P_0c0602de;
P_0c0602dc: /* original e008, guest PC 0x0c0602dc */
if(!s->budget--) { s->failed_pc=0x0c0602dcu; return 0; }
r[0]=0x00000008u;
goto P_0c0602de;
P_0c0602de: /* original 0047, guest PC 0x0c0602de */
if(!s->budget--) { s->failed_pc=0x0c0602deu; return 0; }
r[19]=r[0]*r[4];
goto P_0c0602e0;
P_0c0602e0: /* original 6073, guest PC 0x0c0602e0 */
if(!s->budget--) { s->failed_pc=0x0c0602e0u; return 0; }
r[0]=r[7];
goto P_0c0602e2;
P_0c0602e2: /* original 0009, guest PC 0x0c0602e2 */
if(!s->budget--) { s->failed_pc=0x0c0602e2u; return 0; }
goto P_0c0602e4;
P_0c0602e4: /* original 8801, guest PC 0x0c0602e4 */
if(!s->budget--) { s->failed_pc=0x0c0602e4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0602e6;
P_0c0602e6: /* original 8f14, guest PC 0x0c0602e6 */
if(!s->budget--) { s->failed_pc=0x0c0602e6u; return 0; }
cond=r[17]&1u;
r[6]=r[19];
if(!cond) { goto P_0c060312; }
goto P_0c0602ea;
P_0c0602e8: /* original 061a, guest PC 0x0c0602e8 */
if(!s->budget--) { s->failed_pc=0x0c0602e8u; return 0; }
r[6]=r[19];
goto P_0c0602ea;
P_0c0602ea: /* original 9250, guest PC 0x0c0602ea */
if(!s->budget--) { s->failed_pc=0x0c0602eau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06038eu,2);
goto P_0c0602ec;
P_0c0602ec: /* original 3520, guest PC 0x0c0602ec */
if(!s->budget--) { s->failed_pc=0x0c0602ecu; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[2])!=0);
goto P_0c0602ee;
P_0c0602ee: /* original 8b25, guest PC 0x0c0602ee */
if(!s->budget--) { s->failed_pc=0x0c0602eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06033c; }
goto P_0c0602f0;
P_0c0602f0: /* original 914e, guest PC 0x0c0602f0 */
if(!s->budget--) { s->failed_pc=0x0c0602f0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060390u,2);
goto P_0c0602f2;
P_0c0602f2: /* original 1e11, guest PC 0x0c0602f2 */
if(!s->budget--) { s->failed_pc=0x0c0602f2u; return 0; }
write(ram,r[14]+4,r[1],4);
goto P_0c0602f4;
P_0c0602f4: /* original 04b7, guest PC 0x0c0602f4 */
if(!s->budget--) { s->failed_pc=0x0c0602f4u; return 0; }
r[19]=r[4]*r[11];
goto P_0c0602f6;
P_0c0602f6: /* original 011a, guest PC 0x0c0602f6 */
if(!s->budget--) { s->failed_pc=0x0c0602f6u; return 0; }
r[1]=r[19];
goto P_0c0602f8;
P_0c0602f8: /* original d327, guest PC 0x0c0602f8 */
if(!s->budget--) { s->failed_pc=0x0c0602f8u; return 0; }
r[3]=read(ram,0x0c060398u,4);
goto P_0c0602fa;
P_0c0602fa: /* original 430b, guest PC 0x0c0602fa */
if(!s->budget--) { s->failed_pc=0x0c0602fau; return 0; }
target=r[3];
r[16]=code_base|0x0c0602feu;
r[0]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0602feu) { target=s->pc; goto dispatch; }
goto P_0c0602fe;
P_0c0602fc: /* original 60a3, guest PC 0x0c0602fc */
if(!s->budget--) { s->failed_pc=0x0c0602fcu; return 0; }
r[0]=r[10];
goto P_0c0602fe;
P_0c0602fe: /* original 7001, guest PC 0x0c0602fe */
if(!s->budget--) { s->failed_pc=0x0c0602feu; return 0; }
r[0]+=0x00000001u;
goto P_0c060300;
P_0c060300: /* original d126, guest PC 0x0c060300 */
if(!s->budget--) { s->failed_pc=0x0c060300u; return 0; }
r[1]=read(ram,0x0c06039cu,4);
goto P_0c060302;
P_0c060302: /* original 1e02, guest PC 0x0c060302 */
if(!s->budget--) { s->failed_pc=0x0c060302u; return 0; }
write(ram,r[14]+8,r[0],4);
goto P_0c060304;
P_0c060304: /* original 6012, guest PC 0x0c060304 */
if(!s->budget--) { s->failed_pc=0x0c060304u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c060306;
P_0c060306: /* original c802, guest PC 0x0c060306 */
if(!s->budget--) { s->failed_pc=0x0c060306u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c060308;
P_0c060308: /* original d325, guest PC 0x0c060308 */
if(!s->budget--) { s->failed_pc=0x0c060308u; return 0; }
r[3]=read(ram,0x0c0603a0u,4);
goto P_0c06030a;
P_0c06030a: /* original 23d2, guest PC 0x0c06030a */
if(!s->budget--) { s->failed_pc=0x0c06030au; return 0; }
write(ram,r[3],r[13],4);
goto P_0c06030c;
P_0c06030c: /* original d225, guest PC 0x0c06030c */
if(!s->budget--) { s->failed_pc=0x0c06030cu; return 0; }
r[2]=read(ram,0x0c0603a4u,4);
goto P_0c06030e;
P_0c06030e: /* original a01d, guest PC 0x0c06030e */
if(!s->budget--) { s->failed_pc=0x0c06030eu; return 0; }
write(ram,r[2],r[6],4);
goto P_0c06034c;
P_0c060310: /* original 2262, guest PC 0x0c060310 */
if(!s->budget--) { s->failed_pc=0x0c060310u; return 0; }
write(ram,r[2],r[6],4);
goto P_0c060312;
P_0c060312: /* original d222, guest PC 0x0c060312 */
if(!s->budget--) { s->failed_pc=0x0c060312u; return 0; }
r[2]=read(ram,0x0c06039cu,4);
goto P_0c060314;
P_0c060314: /* original 6322, guest PC 0x0c060314 */
if(!s->budget--) { s->failed_pc=0x0c060314u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c060316;
P_0c060316: /* original 23c8, guest PC 0x0c060316 */
if(!s->budget--) { s->failed_pc=0x0c060316u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c060318;
P_0c060318: /* original 8b10, guest PC 0x0c060318 */
if(!s->budget--) { s->failed_pc=0x0c060318u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06033c; }
goto P_0c06031a;
P_0c06031a: /* original 9038, guest PC 0x0c06031a */
if(!s->budget--) { s->failed_pc=0x0c06031au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06038eu,2);
goto P_0c06031c;
P_0c06031c: /* original 3500, guest PC 0x0c06031c */
if(!s->budget--) { s->failed_pc=0x0c06031cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[0])!=0);
goto P_0c06031e;
P_0c06031e: /* original 8b0d, guest PC 0x0c06031e */
if(!s->budget--) { s->failed_pc=0x0c06031eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06033c; }
goto P_0c060320;
P_0c060320: /* original 9136, guest PC 0x0c060320 */
if(!s->budget--) { s->failed_pc=0x0c060320u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060390u,2);
goto P_0c060322;
P_0c060322: /* original 1e11, guest PC 0x0c060322 */
if(!s->budget--) { s->failed_pc=0x0c060322u; return 0; }
write(ram,r[14]+4,r[1],4);
goto P_0c060324;
P_0c060324: /* original d31e, guest PC 0x0c060324 */
if(!s->budget--) { s->failed_pc=0x0c060324u; return 0; }
r[3]=read(ram,0x0c0603a0u,4);
goto P_0c060326;
P_0c060326: /* original 23d2, guest PC 0x0c060326 */
if(!s->budget--) { s->failed_pc=0x0c060326u; return 0; }
write(ram,r[3],r[13],4);
goto P_0c060328;
P_0c060328: /* original d21e, guest PC 0x0c060328 */
if(!s->budget--) { s->failed_pc=0x0c060328u; return 0; }
r[2]=read(ram,0x0c0603a4u,4);
goto P_0c06032a;
P_0c06032a: /* original 2262, guest PC 0x0c06032a */
if(!s->budget--) { s->failed_pc=0x0c06032au; return 0; }
write(ram,r[2],r[6],4);
goto P_0c06032c;
P_0c06032c: /* original 04b7, guest PC 0x0c06032c */
if(!s->budget--) { s->failed_pc=0x0c06032cu; return 0; }
r[19]=r[4]*r[11];
goto P_0c06032e;
P_0c06032e: /* original 011a, guest PC 0x0c06032e */
if(!s->budget--) { s->failed_pc=0x0c06032eu; return 0; }
r[1]=r[19];
goto P_0c060330;
P_0c060330: /* original d319, guest PC 0x0c060330 */
if(!s->budget--) { s->failed_pc=0x0c060330u; return 0; }
r[3]=read(ram,0x0c060398u,4);
goto P_0c060332;
P_0c060332: /* original 430b, guest PC 0x0c060332 */
if(!s->budget--) { s->failed_pc=0x0c060332u; return 0; }
target=r[3];
r[16]=code_base|0x0c060336u;
r[0]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060336u) { target=s->pc; goto dispatch; }
goto P_0c060336;
P_0c060334: /* original 60a3, guest PC 0x0c060334 */
if(!s->budget--) { s->failed_pc=0x0c060334u; return 0; }
r[0]=r[10];
goto P_0c060336;
P_0c060336: /* original 7001, guest PC 0x0c060336 */
if(!s->budget--) { s->failed_pc=0x0c060336u; return 0; }
r[0]+=0x00000001u;
goto P_0c060338;
P_0c060338: /* original a008, guest PC 0x0c060338 */
if(!s->budget--) { s->failed_pc=0x0c060338u; return 0; }
write(ram,r[14]+8,r[0],4);
goto P_0c06034c;
P_0c06033a: /* original 1e02, guest PC 0x0c06033a */
if(!s->budget--) { s->failed_pc=0x0c06033au; return 0; }
write(ram,r[14]+8,r[0],4);
goto P_0c06033c;
P_0c06033c: /* original d218, guest PC 0x0c06033c */
if(!s->budget--) { s->failed_pc=0x0c06033cu; return 0; }
r[2]=read(ram,0x0c0603a0u,4);
goto P_0c06033e;
P_0c06033e: /* original 6353, guest PC 0x0c06033e */
if(!s->budget--) { s->failed_pc=0x0c06033eu; return 0; }
r[3]=r[5];
goto P_0c060340;
P_0c060340: /* original 73ff, guest PC 0x0c060340 */
if(!s->budget--) { s->failed_pc=0x0c060340u; return 0; }
r[3]+=0xffffffffu;
goto P_0c060342;
P_0c060342: /* original 1e31, guest PC 0x0c060342 */
if(!s->budget--) { s->failed_pc=0x0c060342u; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c060344;
P_0c060344: /* original 22d2, guest PC 0x0c060344 */
if(!s->budget--) { s->failed_pc=0x0c060344u; return 0; }
write(ram,r[2],r[13],4);
goto P_0c060346;
P_0c060346: /* original d317, guest PC 0x0c060346 */
if(!s->budget--) { s->failed_pc=0x0c060346u; return 0; }
r[3]=read(ram,0x0c0603a4u,4);
goto P_0c060348;
P_0c060348: /* original 2362, guest PC 0x0c060348 */
if(!s->budget--) { s->failed_pc=0x0c060348u; return 0; }
write(ram,r[3],r[6],4);
goto P_0c06034a;
P_0c06034a: /* original 1ec2, guest PC 0x0c06034a */
if(!s->budget--) { s->failed_pc=0x0c06034au; return 0; }
write(ram,r[14]+8,r[12],4);
goto P_0c06034c;
P_0c06034c: /* original 9621, guest PC 0x0c06034c */
if(!s->budget--) { s->failed_pc=0x0c06034cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060392u,2);
goto P_0c06034e;
P_0c06034e: /* original 9021, guest PC 0x0c06034e */
if(!s->budget--) { s->failed_pc=0x0c06034eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060394u,2);
goto P_0c060350;
P_0c060350: /* original 02fe, guest PC 0x0c060350 */
if(!s->budget--) { s->failed_pc=0x0c060350u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c060352;
P_0c060352: /* original 2228, guest PC 0x0c060352 */
if(!s->budget--) { s->failed_pc=0x0c060352u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c060354;
P_0c060354: /* original 893e, guest PC 0x0c060354 */
if(!s->budget--) { s->failed_pc=0x0c060354u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0603d4; }
goto P_0c060356;
P_0c060356: /* original d314, guest PC 0x0c060356 */
if(!s->budget--) { s->failed_pc=0x0c060356u; return 0; }
r[3]=read(ram,0x0c0603a8u,4);
goto P_0c060358;
P_0c060358: /* original 6232, guest PC 0x0c060358 */
if(!s->budget--) { s->failed_pc=0x0c060358u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c06035a;
P_0c06035a: /* original 22cb, guest PC 0x0c06035a */
if(!s->budget--) { s->failed_pc=0x0c06035au; return 0; }
r[2]|=r[12];
goto P_0c06035c;
P_0c06035c: /* original 2322, guest PC 0x0c06035c */
if(!s->budget--) { s->failed_pc=0x0c06035cu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c06035e;
P_0c06035e: /* original 1ec3, guest PC 0x0c06035e */
if(!s->budget--) { s->failed_pc=0x0c06035eu; return 0; }
write(ram,r[14]+12,r[12],4);
goto P_0c060360;
P_0c060360: /* original d20e, guest PC 0x0c060360 */
if(!s->budget--) { s->failed_pc=0x0c060360u; return 0; }
r[2]=read(ram,0x0c06039cu,4);
goto P_0c060362;
P_0c060362: /* original 6322, guest PC 0x0c060362 */
if(!s->budget--) { s->failed_pc=0x0c060362u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c060364;
P_0c060364: /* original 23c8, guest PC 0x0c060364 */
if(!s->budget--) { s->failed_pc=0x0c060364u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c060366;
P_0c060366: /* original 8d02, guest PC 0x0c060366 */
if(!s->budget--) { s->failed_pc=0x0c060366u; return 0; }
cond=r[17]&1u;
r[7]=0x00000002u;
if(cond) { goto P_0c06036e; }
goto P_0c06036a;
P_0c060368: /* original e702, guest PC 0x0c060368 */
if(!s->budget--) { s->failed_pc=0x0c060368u; return 0; }
r[7]=0x00000002u;
goto P_0c06036a;
P_0c06036a: /* original a02f, guest PC 0x0c06036a */
if(!s->budget--) { s->failed_pc=0x0c06036au; return 0; }
write(ram,r[14]+16,r[6],4);
goto P_0c0603cc;
P_0c06036c: /* original 1e64, guest PC 0x0c06036c */
if(!s->budget--) { s->failed_pc=0x0c06036cu; return 0; }
write(ram,r[14]+16,r[6],4);
goto P_0c06036e;
P_0c06036e: /* original e3ec, guest PC 0x0c06036e */
if(!s->budget--) { s->failed_pc=0x0c06036eu; return 0; }
r[3]=0xffffffecu;
goto P_0c060370;
P_0c060370: /* original d10a, guest PC 0x0c060370 */
if(!s->budget--) { s->failed_pc=0x0c060370u; return 0; }
r[1]=read(ram,0x0c06039cu,4);
goto P_0c060372;
P_0c060372: /* original 6012, guest PC 0x0c060372 */
if(!s->budget--) { s->failed_pc=0x0c060372u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c060374;
P_0c060374: /* original 2039, guest PC 0x0c060374 */
if(!s->budget--) { s->failed_pc=0x0c060374u; return 0; }
r[0]&=r[3];
goto P_0c060376;
P_0c060376: /* original 8800, guest PC 0x0c060376 */
if(!s->budget--) { s->failed_pc=0x0c060376u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c060378;
P_0c060378: /* original 8921, guest PC 0x0c060378 */
if(!s->budget--) { s->failed_pc=0x0c060378u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0603be; }
goto P_0c06037a;
P_0c06037a: /* original 8804, guest PC 0x0c06037a */
if(!s->budget--) { s->failed_pc=0x0c06037au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c06037c;
P_0c06037c: /* original 891f, guest PC 0x0c06037c */
if(!s->budget--) { s->failed_pc=0x0c06037cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0603be; }
goto P_0c06037e;
P_0c06037e: /* original 8820, guest PC 0x0c06037e */
if(!s->budget--) { s->failed_pc=0x0c06037eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c060380;
P_0c060380: /* original 891d, guest PC 0x0c060380 */
if(!s->budget--) { s->failed_pc=0x0c060380u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0603be; }
goto P_0c060382;
P_0c060382: /* original 8824, guest PC 0x0c060382 */
if(!s->budget--) { s->failed_pc=0x0c060382u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000024u)!=0);
goto P_0c060384;
P_0c060384: /* original 8912, guest PC 0x0c060384 */
if(!s->budget--) { s->failed_pc=0x0c060384u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0603ac; }
goto P_0c060386;
P_0c060386: /* original 8828, guest PC 0x0c060386 */
if(!s->budget--) { s->failed_pc=0x0c060386u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000028u)!=0);
goto P_0c060388;
P_0c060388: /* original 8910, guest PC 0x0c060388 */
if(!s->budget--) { s->failed_pc=0x0c060388u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0603ac; }
goto P_0c06038a;
P_0c06038a: /* original a056, guest PC 0x0c06038a */
if(!s->budget--) { s->failed_pc=0x0c06038au; return 0; }
goto P_0c06043a;
P_0c06038c: /* original 0009, guest PC 0x0c06038c */
if(!s->budget--) { s->failed_pc=0x0c06038cu; return 0; }
if(!vf3_matrix_family(0x0c06038eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06038eu; return 0; } return 1;
P_0c0603ac: /* original 1e64, guest PC 0x0c0603ac */
if(!s->budget--) { s->failed_pc=0x0c0603acu; return 0; }
write(ram,r[14]+16,r[6],4);
goto P_0c0603ae;
P_0c0603ae: /* original 04b7, guest PC 0x0c0603ae */
if(!s->budget--) { s->failed_pc=0x0c0603aeu; return 0; }
r[19]=r[4]*r[11];
goto P_0c0603b0;
P_0c0603b0: /* original d23b, guest PC 0x0c0603b0 */
if(!s->budget--) { s->failed_pc=0x0c0603b0u; return 0; }
r[2]=read(ram,0x0c0604a0u,4);
goto P_0c0603b2;
P_0c0603b2: /* original 011a, guest PC 0x0c0603b2 */
if(!s->budget--) { s->failed_pc=0x0c0603b2u; return 0; }
r[1]=r[19];
goto P_0c0603b4;
P_0c0603b4: /* original 420b, guest PC 0x0c0603b4 */
if(!s->budget--) { s->failed_pc=0x0c0603b4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0603b8u;
r[0]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0603b8u) { target=s->pc; goto dispatch; }
goto P_0c0603b8;
P_0c0603b6: /* original 60a3, guest PC 0x0c0603b6 */
if(!s->budget--) { s->failed_pc=0x0c0603b6u; return 0; }
r[0]=r[10];
goto P_0c0603b8;
P_0c0603b8: /* original 7001, guest PC 0x0c0603b8 */
if(!s->budget--) { s->failed_pc=0x0c0603b8u; return 0; }
r[0]+=0x00000001u;
goto P_0c0603ba;
P_0c0603ba: /* original a007, guest PC 0x0c0603ba */
if(!s->budget--) { s->failed_pc=0x0c0603bau; return 0; }
write(ram,r[14]+8,r[0],4);
goto P_0c0603cc;
P_0c0603bc: /* original 1e02, guest PC 0x0c0603bc */
if(!s->budget--) { s->failed_pc=0x0c0603bcu; return 0; }
write(ram,r[14]+8,r[0],4);
goto P_0c0603be;
P_0c0603be: /* original d139, guest PC 0x0c0603be */
if(!s->budget--) { s->failed_pc=0x0c0603beu; return 0; }
r[1]=read(ram,0x0c0604a4u,4);
goto P_0c0603c0;
P_0c0603c0: /* original 21d2, guest PC 0x0c0603c0 */
if(!s->budget--) { s->failed_pc=0x0c0603c0u; return 0; }
write(ram,r[1],r[13],4);
goto P_0c0603c2;
P_0c0603c2: /* original d239, guest PC 0x0c0603c2 */
if(!s->budget--) { s->failed_pc=0x0c0603c2u; return 0; }
r[2]=read(ram,0x0c0604a8u,4);
goto P_0c0603c4;
P_0c0603c4: /* original 22d2, guest PC 0x0c0603c4 */
if(!s->budget--) { s->failed_pc=0x0c0603c4u; return 0; }
write(ram,r[2],r[13],4);
goto P_0c0603c6;
P_0c0603c6: /* original 9366, guest PC 0x0c0603c6 */
if(!s->budget--) { s->failed_pc=0x0c0603c6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060496u,2);
goto P_0c0603c8;
P_0c0603c8: /* original 1e34, guest PC 0x0c0603c8 */
if(!s->budget--) { s->failed_pc=0x0c0603c8u; return 0; }
write(ram,r[14]+16,r[3],4);
goto P_0c0603ca;
P_0c0603ca: /* original 1ec2, guest PC 0x0c0603ca */
if(!s->budget--) { s->failed_pc=0x0c0603cau; return 0; }
write(ram,r[14]+8,r[12],4);
goto P_0c0603cc;
P_0c0603cc: /* original 52e1, guest PC 0x0c0603cc */
if(!s->budget--) { s->failed_pc=0x0c0603ccu; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0603ce;
P_0c0603ce: /* original 72fe, guest PC 0x0c0603ce */
if(!s->budget--) { s->failed_pc=0x0c0603ceu; return 0; }
r[2]+=0xfffffffeu;
goto P_0c0603d0;
P_0c0603d0: /* original a033, guest PC 0x0c0603d0 */
if(!s->budget--) { s->failed_pc=0x0c0603d0u; return 0; }
write(ram,r[14]+4,r[2],4);
goto P_0c06043a;
P_0c0603d2: /* original 1e21, guest PC 0x0c0603d2 */
if(!s->budget--) { s->failed_pc=0x0c0603d2u; return 0; }
write(ram,r[14]+4,r[2],4);
goto P_0c0603d4;
P_0c0603d4: /* original 1ed3, guest PC 0x0c0603d4 */
if(!s->budget--) { s->failed_pc=0x0c0603d4u; return 0; }
write(ram,r[14]+12,r[13],4);
goto P_0c0603d6;
P_0c0603d6: /* original d335, guest PC 0x0c0603d6 */
if(!s->budget--) { s->failed_pc=0x0c0603d6u; return 0; }
r[3]=read(ram,0x0c0604acu,4);
goto P_0c0603d8;
P_0c0603d8: /* original 6032, guest PC 0x0c0603d8 */
if(!s->budget--) { s->failed_pc=0x0c0603d8u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0603da;
P_0c0603da: /* original 20c9, guest PC 0x0c0603da */
if(!s->budget--) { s->failed_pc=0x0c0603dau; return 0; }
r[0]&=r[12];
goto P_0c0603dc;
P_0c0603dc: /* original 8801, guest PC 0x0c0603dc */
if(!s->budget--) { s->failed_pc=0x0c0603dcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0603de;
P_0c0603de: /* original 8b03, guest PC 0x0c0603de */
if(!s->budget--) { s->failed_pc=0x0c0603deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0603e8; }
goto P_0c0603e0;
P_0c0603e0: /* original 2dd8, guest PC 0x0c0603e0 */
if(!s->budget--) { s->failed_pc=0x0c0603e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0603e2;
P_0c0603e2: /* original 8916, guest PC 0x0c0603e2 */
if(!s->budget--) { s->failed_pc=0x0c0603e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060412; }
goto P_0c0603e4;
P_0c0603e4: /* original a00b, guest PC 0x0c0603e4 */
if(!s->budget--) { s->failed_pc=0x0c0603e4u; return 0; }
goto P_0c0603fe;
P_0c0603e6: /* original 0009, guest PC 0x0c0603e6 */
if(!s->budget--) { s->failed_pc=0x0c0603e6u; return 0; }
goto P_0c0603e8;
P_0c0603e8: /* original d230, guest PC 0x0c0603e8 */
if(!s->budget--) { s->failed_pc=0x0c0603e8u; return 0; }
r[2]=read(ram,0x0c0604acu,4);
goto P_0c0603ea;
P_0c0603ea: /* original 6022, guest PC 0x0c0603ea */
if(!s->budget--) { s->failed_pc=0x0c0603eau; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0603ec;
P_0c0603ec: /* original c92c, guest PC 0x0c0603ec */
if(!s->budget--) { s->failed_pc=0x0c0603ecu; return 0; }
r[0]&=44u;
goto P_0c0603ee;
P_0c0603ee: /* original 8820, guest PC 0x0c0603ee */
if(!s->budget--) { s->failed_pc=0x0c0603eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c0603f0;
P_0c0603f0: /* original 8b03, guest PC 0x0c0603f0 */
if(!s->budget--) { s->failed_pc=0x0c0603f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0603fa; }
goto P_0c0603f2;
P_0c0603f2: /* original 2cc8, guest PC 0x0c0603f2 */
if(!s->budget--) { s->failed_pc=0x0c0603f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0603f4;
P_0c0603f4: /* original 890d, guest PC 0x0c0603f4 */
if(!s->budget--) { s->failed_pc=0x0c0603f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060412; }
goto P_0c0603f6;
P_0c0603f6: /* original a002, guest PC 0x0c0603f6 */
if(!s->budget--) { s->failed_pc=0x0c0603f6u; return 0; }
goto P_0c0603fe;
P_0c0603f8: /* original 0009, guest PC 0x0c0603f8 */
if(!s->budget--) { s->failed_pc=0x0c0603f8u; return 0; }
goto P_0c0603fa;
P_0c0603fa: /* original 2dd8, guest PC 0x0c0603fa */
if(!s->budget--) { s->failed_pc=0x0c0603fau; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0603fc;
P_0c0603fc: /* original 8909, guest PC 0x0c0603fc */
if(!s->budget--) { s->failed_pc=0x0c0603fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060412; }
goto P_0c0603fe;
P_0c0603fe: /* original 934a, guest PC 0x0c0603fe */
if(!s->budget--) { s->failed_pc=0x0c0603feu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060496u,2);
goto P_0c060400;
P_0c060400: /* original 924a, guest PC 0x0c060400 */
if(!s->budget--) { s->failed_pc=0x0c060400u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060498u,2);
goto P_0c060402;
P_0c060402: /* original 1e34, guest PC 0x0c060402 */
if(!s->budget--) { s->failed_pc=0x0c060402u; return 0; }
write(ram,r[14]+16,r[3],4);
goto P_0c060404;
P_0c060404: /* original 1e21, guest PC 0x0c060404 */
if(!s->budget--) { s->failed_pc=0x0c060404u; return 0; }
write(ram,r[14]+4,r[2],4);
goto P_0c060406;
P_0c060406: /* original d327, guest PC 0x0c060406 */
if(!s->budget--) { s->failed_pc=0x0c060406u; return 0; }
r[3]=read(ram,0x0c0604a4u,4);
goto P_0c060408;
P_0c060408: /* original 23d2, guest PC 0x0c060408 */
if(!s->budget--) { s->failed_pc=0x0c060408u; return 0; }
write(ram,r[3],r[13],4);
goto P_0c06040a;
P_0c06040a: /* original d227, guest PC 0x0c06040a */
if(!s->budget--) { s->failed_pc=0x0c06040au; return 0; }
r[2]=read(ram,0x0c0604a8u,4);
goto P_0c06040c;
P_0c06040c: /* original 22d2, guest PC 0x0c06040c */
if(!s->budget--) { s->failed_pc=0x0c06040cu; return 0; }
write(ram,r[2],r[13],4);
goto P_0c06040e;
P_0c06040e: /* original a013, guest PC 0x0c06040e */
if(!s->budget--) { s->failed_pc=0x0c06040eu; return 0; }
write(ram,r[14]+8,r[12],4);
goto P_0c060438;
P_0c060410: /* original 1ec2, guest PC 0x0c060410 */
if(!s->budget--) { s->failed_pc=0x0c060410u; return 0; }
write(ram,r[14]+8,r[12],4);
goto P_0c060412;
P_0c060412: /* original 9742, guest PC 0x0c060412 */
if(!s->budget--) { s->failed_pc=0x0c060412u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06049au,2);
goto P_0c060414;
P_0c060414: /* original d225, guest PC 0x0c060414 */
if(!s->budget--) { s->failed_pc=0x0c060414u; return 0; }
r[2]=read(ram,0x0c0604acu,4);
goto P_0c060416;
P_0c060416: /* original 6322, guest PC 0x0c060416 */
if(!s->budget--) { s->failed_pc=0x0c060416u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c060418;
P_0c060418: /* original 23c8, guest PC 0x0c060418 */
if(!s->budget--) { s->failed_pc=0x0c060418u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c06041a;
P_0c06041a: /* original 8901, guest PC 0x0c06041a */
if(!s->budget--) { s->failed_pc=0x0c06041au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060420; }
goto P_0c06041c;
P_0c06041c: /* original a00c, guest PC 0x0c06041c */
if(!s->budget--) { s->failed_pc=0x0c06041cu; return 0; }
write(ram,r[14]+16,r[7],4);
goto P_0c060438;
P_0c06041e: /* original 1e74, guest PC 0x0c06041e */
if(!s->budget--) { s->failed_pc=0x0c06041eu; return 0; }
write(ram,r[14]+16,r[7],4);
goto P_0c060420;
P_0c060420: /* original d322, guest PC 0x0c060420 */
if(!s->budget--) { s->failed_pc=0x0c060420u; return 0; }
r[3]=read(ram,0x0c0604acu,4);
goto P_0c060422;
P_0c060422: /* original 6132, guest PC 0x0c060422 */
if(!s->budget--) { s->failed_pc=0x0c060422u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c060424;
P_0c060424: /* original 21a8, guest PC 0x0c060424 */
if(!s->budget--) { s->failed_pc=0x0c060424u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[10])==0)!=0);
goto P_0c060426;
P_0c060426: /* original 8903, guest PC 0x0c060426 */
if(!s->budget--) { s->failed_pc=0x0c060426u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060430; }
goto P_0c060428;
P_0c060428: /* original 1e64, guest PC 0x0c060428 */
if(!s->budget--) { s->failed_pc=0x0c060428u; return 0; }
write(ram,r[14]+16,r[6],4);
goto P_0c06042a;
P_0c06042a: /* original 51e1, guest PC 0x0c06042a */
if(!s->budget--) { s->failed_pc=0x0c06042au; return 0; }
r[1]=read(ram,r[14]+4,4);
goto P_0c06042c;
P_0c06042c: /* original a003, guest PC 0x0c06042c */
if(!s->budget--) { s->failed_pc=0x0c06042cu; return 0; }
r[1]+=0xfffffffeu;
goto P_0c060436;
P_0c06042e: /* original 71fe, guest PC 0x0c06042e */
if(!s->budget--) { s->failed_pc=0x0c06042eu; return 0; }
r[1]+=0xfffffffeu;
goto P_0c060430;
P_0c060430: /* original 1e74, guest PC 0x0c060430 */
if(!s->budget--) { s->failed_pc=0x0c060430u; return 0; }
write(ram,r[14]+16,r[7],4);
goto P_0c060432;
P_0c060432: /* original 51e1, guest PC 0x0c060432 */
if(!s->budget--) { s->failed_pc=0x0c060432u; return 0; }
r[1]=read(ram,r[14]+4,4);
goto P_0c060434;
P_0c060434: /* original 71ff, guest PC 0x0c060434 */
if(!s->budget--) { s->failed_pc=0x0c060434u; return 0; }
r[1]+=0xffffffffu;
goto P_0c060436;
P_0c060436: /* original 1e11, guest PC 0x0c060436 */
if(!s->budget--) { s->failed_pc=0x0c060436u; return 0; }
write(ram,r[14]+4,r[1],4);
goto P_0c060438;
P_0c060438: /* original e701, guest PC 0x0c060438 */
if(!s->budget--) { s->failed_pc=0x0c060438u; return 0; }
r[7]=0x00000001u;
goto P_0c06043a;
P_0c06043a: /* original e340, guest PC 0x0c06043a */
if(!s->budget--) { s->failed_pc=0x0c06043au; return 0; }
r[3]=0x00000040u;
goto P_0c06043c;
P_0c06043c: /* original 922e, guest PC 0x0c06043c */
if(!s->budget--) { s->failed_pc=0x0c06043cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06049cu,2);
goto P_0c06043e;
P_0c06043e: /* original 6143, guest PC 0x0c06043e */
if(!s->budget--) { s->failed_pc=0x0c06043eu; return 0; }
r[1]=r[4];
goto P_0c060440;
P_0c060440: /* original 1e35, guest PC 0x0c060440 */
if(!s->budget--) { s->failed_pc=0x0c060440u; return 0; }
write(ram,r[14]+20,r[3],4);
goto P_0c060442;
P_0c060442: /* original 1e26, guest PC 0x0c060442 */
if(!s->budget--) { s->failed_pc=0x0c060442u; return 0; }
write(ram,r[14]+24,r[2],4);
goto P_0c060444;
P_0c060444: /* original 60a3, guest PC 0x0c060444 */
if(!s->budget--) { s->failed_pc=0x0c060444u; return 0; }
r[0]=r[10];
goto P_0c060446;
P_0c060446: /* original 0009, guest PC 0x0c060446 */
if(!s->budget--) { s->failed_pc=0x0c060446u; return 0; }
goto P_0c060448;
P_0c060448: /* original d315, guest PC 0x0c060448 */
if(!s->budget--) { s->failed_pc=0x0c060448u; return 0; }
r[3]=read(ram,0x0c0604a0u,4);
goto P_0c06044a;
P_0c06044a: /* original 430b, guest PC 0x0c06044a */
if(!s->budget--) { s->failed_pc=0x0c06044au; return 0; }
target=r[3];
r[16]=code_base|0x0c06044eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06044eu) { target=s->pc; goto dispatch; }
goto P_0c06044e;
P_0c06044c: /* original 0009, guest PC 0x0c06044c */
if(!s->budget--) { s->failed_pc=0x0c06044cu; return 0; }
goto P_0c06044e;
P_0c06044e: /* original 0077, guest PC 0x0c06044e */
if(!s->budget--) { s->failed_pc=0x0c06044eu; return 0; }
r[19]=r[0]*r[7];
goto P_0c060450;
P_0c060450: /* original d217, guest PC 0x0c060450 */
if(!s->budget--) { s->failed_pc=0x0c060450u; return 0; }
r[2]=read(ram,0x0c0604b0u,4);
goto P_0c060452;
P_0c060452: /* original 001a, guest PC 0x0c060452 */
if(!s->budget--) { s->failed_pc=0x0c060452u; return 0; }
r[0]=r[19];
goto P_0c060454;
P_0c060454: /* original 2202, guest PC 0x0c060454 */
if(!s->budget--) { s->failed_pc=0x0c060454u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c060456;
P_0c060456: /* original 0597, guest PC 0x0c060456 */
if(!s->budget--) { s->failed_pc=0x0c060456u; return 0; }
r[19]=r[5]*r[9];
goto P_0c060458;
P_0c060458: /* original 011a, guest PC 0x0c060458 */
if(!s->budget--) { s->failed_pc=0x0c060458u; return 0; }
r[1]=r[19];
goto P_0c06045a;
P_0c06045a: /* original 60a3, guest PC 0x0c06045a */
if(!s->budget--) { s->failed_pc=0x0c06045au; return 0; }
r[0]=r[10];
goto P_0c06045c;
P_0c06045c: /* original 0009, guest PC 0x0c06045c */
if(!s->budget--) { s->failed_pc=0x0c06045cu; return 0; }
goto P_0c06045e;
P_0c06045e: /* original d310, guest PC 0x0c06045e */
if(!s->budget--) { s->failed_pc=0x0c06045eu; return 0; }
r[3]=read(ram,0x0c0604a0u,4);
goto P_0c060460;
P_0c060460: /* original 430b, guest PC 0x0c060460 */
if(!s->budget--) { s->failed_pc=0x0c060460u; return 0; }
target=r[3];
r[16]=code_base|0x0c060464u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060464u) { target=s->pc; goto dispatch; }
goto P_0c060464;
P_0c060462: /* original 0009, guest PC 0x0c060462 */
if(!s->budget--) { s->failed_pc=0x0c060462u; return 0; }
goto P_0c060464;
P_0c060464: /* original d113, guest PC 0x0c060464 */
if(!s->budget--) { s->failed_pc=0x0c060464u; return 0; }
r[1]=read(ram,0x0c0604b4u,4);
goto P_0c060466;
P_0c060466: /* original 308c, guest PC 0x0c060466 */
if(!s->budget--) { s->failed_pc=0x0c060466u; return 0; }
r[0]+=r[8];
goto P_0c060468;
P_0c060468: /* original 2102, guest PC 0x0c060468 */
if(!s->budget--) { s->failed_pc=0x0c060468u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c06046a;
P_0c06046a: /* original e60f, guest PC 0x0c06046a */
if(!s->budget--) { s->failed_pc=0x0c06046au; return 0; }
r[6]=0x0000000fu;
goto P_0c06046c;
P_0c06046c: /* original 6013, guest PC 0x0c06046c */
if(!s->budget--) { s->failed_pc=0x0c06046cu; return 0; }
r[0]=r[1];
goto P_0c06046e;
P_0c06046e: /* original 0009, guest PC 0x0c06046e */
if(!s->budget--) { s->failed_pc=0x0c06046eu; return 0; }
goto P_0c060470;
P_0c060470: /* original 6302, guest PC 0x0c060470 */
if(!s->budget--) { s->failed_pc=0x0c060470u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c060472;
P_0c060472: /* original 3366, guest PC 0x0c060472 */
if(!s->budget--) { s->failed_pc=0x0c060472u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[6])!=0);
goto P_0c060474;
P_0c060474: /* original 8b01, guest PC 0x0c060474 */
if(!s->budget--) { s->failed_pc=0x0c060474u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06047a; }
goto P_0c060476;
P_0c060476: /* original d30f, guest PC 0x0c060476 */
if(!s->budget--) { s->failed_pc=0x0c060476u; return 0; }
r[3]=read(ram,0x0c0604b4u,4);
goto P_0c060478;
P_0c060478: /* original 2362, guest PC 0x0c060478 */
if(!s->budget--) { s->failed_pc=0x0c060478u; return 0; }
write(ram,r[3],r[6],4);
goto P_0c06047a;
P_0c06047a: /* original e209, guest PC 0x0c06047a */
if(!s->budget--) { s->failed_pc=0x0c06047au; return 0; }
r[2]=0x00000009u;
goto P_0c06047c;
P_0c06047c: /* original e04c, guest PC 0x0c06047c */
if(!s->budget--) { s->failed_pc=0x0c06047cu; return 0; }
r[0]=0x0000004cu;
goto P_0c06047e;
P_0c06047e: /* original e306, guest PC 0x0c06047e */
if(!s->budget--) { s->failed_pc=0x0c06047eu; return 0; }
r[3]=0x00000006u;
goto P_0c060480;
P_0c060480: /* original 0e26, guest PC 0x0c060480 */
if(!s->budget--) { s->failed_pc=0x0c060480u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c060482;
P_0c060482: /* original e048, guest PC 0x0c060482 */
if(!s->budget--) { s->failed_pc=0x0c060482u; return 0; }
r[0]=0x00000048u;
goto P_0c060484;
P_0c060484: /* original 0e36, guest PC 0x0c060484 */
if(!s->budget--) { s->failed_pc=0x0c060484u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c060486;
P_0c060486: /* original 60b3, guest PC 0x0c060486 */
if(!s->budget--) { s->failed_pc=0x0c060486u; return 0; }
r[0]=r[11];
goto P_0c060488;
P_0c060488: /* original 0009, guest PC 0x0c060488 */
if(!s->budget--) { s->failed_pc=0x0c060488u; return 0; }
goto P_0c06048a;
P_0c06048a: /* original 8810, guest PC 0x0c06048a */
if(!s->budget--) { s->failed_pc=0x0c06048au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c06048c;
P_0c06048c: /* original 8b14, guest PC 0x0c06048c */
if(!s->budget--) { s->failed_pc=0x0c06048cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0604b8; }
goto P_0c06048e;
P_0c06048e: /* original e208, guest PC 0x0c06048e */
if(!s->budget--) { s->failed_pc=0x0c06048eu; return 0; }
r[2]=0x00000008u;
goto P_0c060490;
P_0c060490: /* original e050, guest PC 0x0c060490 */
if(!s->budget--) { s->failed_pc=0x0c060490u; return 0; }
r[0]=0x00000050u;
goto P_0c060492;
P_0c060492: /* original a014, guest PC 0x0c060492 */
if(!s->budget--) { s->failed_pc=0x0c060492u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0604be;
P_0c060494: /* original 0e26, guest PC 0x0c060494 */
if(!s->budget--) { s->failed_pc=0x0c060494u; return 0; }
write(ram,r[14]+r[0],r[2],4);
if(!vf3_matrix_family(0x0c060496u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c060496u; return 0; } return 1;
P_0c0604b8: /* original e10b, guest PC 0x0c0604b8 */
if(!s->budget--) { s->failed_pc=0x0c0604b8u; return 0; }
r[1]=0x0000000bu;
goto P_0c0604ba;
P_0c0604ba: /* original e050, guest PC 0x0c0604ba */
if(!s->budget--) { s->failed_pc=0x0c0604bau; return 0; }
r[0]=0x00000050u;
goto P_0c0604bc;
P_0c0604bc: /* original 0e16, guest PC 0x0c0604bc */
if(!s->budget--) { s->failed_pc=0x0c0604bcu; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c0604be;
P_0c0604be: /* original e058, guest PC 0x0c0604be */
if(!s->budget--) { s->failed_pc=0x0c0604beu; return 0; }
r[0]=0x00000058u;
goto P_0c0604c0;
P_0c0604c0: /* original d31e, guest PC 0x0c0604c0 */
if(!s->budget--) { s->failed_pc=0x0c0604c0u; return 0; }
r[3]=read(ram,0x0c06053cu,4);
goto P_0c0604c2;
P_0c0604c2: /* original 74ff, guest PC 0x0c0604c2 */
if(!s->budget--) { s->failed_pc=0x0c0604c2u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0604c4;
P_0c0604c4: /* original 0ed6, guest PC 0x0c0604c4 */
if(!s->budget--) { s->failed_pc=0x0c0604c4u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0604c6;
P_0c0604c6: /* original e054, guest PC 0x0c0604c6 */
if(!s->budget--) { s->failed_pc=0x0c0604c6u; return 0; }
r[0]=0x00000054u;
goto P_0c0604c8;
P_0c0604c8: /* original 0e46, guest PC 0x0c0604c8 */
if(!s->budget--) { s->failed_pc=0x0c0604c8u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0604ca;
P_0c0604ca: /* original e060, guest PC 0x0c0604ca */
if(!s->budget--) { s->failed_pc=0x0c0604cau; return 0; }
r[0]=0x00000060u;
goto P_0c0604cc;
P_0c0604cc: /* original 0ed6, guest PC 0x0c0604cc */
if(!s->budget--) { s->failed_pc=0x0c0604ccu; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0604ce;
P_0c0604ce: /* original 6032, guest PC 0x0c0604ce */
if(!s->budget--) { s->failed_pc=0x0c0604ceu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0604d0;
P_0c0604d0: /* original 20c9, guest PC 0x0c0604d0 */
if(!s->budget--) { s->failed_pc=0x0c0604d0u; return 0; }
r[0]&=r[12];
goto P_0c0604d2;
P_0c0604d2: /* original 8801, guest PC 0x0c0604d2 */
if(!s->budget--) { s->failed_pc=0x0c0604d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0604d4;
P_0c0604d4: /* original 8b03, guest PC 0x0c0604d4 */
if(!s->budget--) { s->failed_pc=0x0c0604d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0604de; }
goto P_0c0604d6;
P_0c0604d6: /* original 2dd8, guest PC 0x0c0604d6 */
if(!s->budget--) { s->failed_pc=0x0c0604d6u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0604d8;
P_0c0604d8: /* original 8910, guest PC 0x0c0604d8 */
if(!s->budget--) { s->failed_pc=0x0c0604d8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0604fc; }
goto P_0c0604da;
P_0c0604da: /* original a00b, guest PC 0x0c0604da */
if(!s->budget--) { s->failed_pc=0x0c0604dau; return 0; }
goto P_0c0604f4;
P_0c0604dc: /* original 0009, guest PC 0x0c0604dc */
if(!s->budget--) { s->failed_pc=0x0c0604dcu; return 0; }
goto P_0c0604de;
P_0c0604de: /* original d217, guest PC 0x0c0604de */
if(!s->budget--) { s->failed_pc=0x0c0604deu; return 0; }
r[2]=read(ram,0x0c06053cu,4);
goto P_0c0604e0;
P_0c0604e0: /* original 6022, guest PC 0x0c0604e0 */
if(!s->budget--) { s->failed_pc=0x0c0604e0u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0604e2;
P_0c0604e2: /* original c92c, guest PC 0x0c0604e2 */
if(!s->budget--) { s->failed_pc=0x0c0604e2u; return 0; }
r[0]&=44u;
goto P_0c0604e4;
P_0c0604e4: /* original 8820, guest PC 0x0c0604e4 */
if(!s->budget--) { s->failed_pc=0x0c0604e4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c0604e6;
P_0c0604e6: /* original 8b03, guest PC 0x0c0604e6 */
if(!s->budget--) { s->failed_pc=0x0c0604e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0604f0; }
goto P_0c0604e8;
P_0c0604e8: /* original 2cc8, guest PC 0x0c0604e8 */
if(!s->budget--) { s->failed_pc=0x0c0604e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0604ea;
P_0c0604ea: /* original 8907, guest PC 0x0c0604ea */
if(!s->budget--) { s->failed_pc=0x0c0604eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0604fc; }
goto P_0c0604ec;
P_0c0604ec: /* original a002, guest PC 0x0c0604ec */
if(!s->budget--) { s->failed_pc=0x0c0604ecu; return 0; }
goto P_0c0604f4;
P_0c0604ee: /* original 0009, guest PC 0x0c0604ee */
if(!s->budget--) { s->failed_pc=0x0c0604eeu; return 0; }
goto P_0c0604f0;
P_0c0604f0: /* original 2dd8, guest PC 0x0c0604f0 */
if(!s->budget--) { s->failed_pc=0x0c0604f0u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0604f2;
P_0c0604f2: /* original 8903, guest PC 0x0c0604f2 */
if(!s->budget--) { s->failed_pc=0x0c0604f2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0604fc; }
goto P_0c0604f4;
P_0c0604f4: /* original e300, guest PC 0x0c0604f4 */
if(!s->budget--) { s->failed_pc=0x0c0604f4u; return 0; }
r[3]=0x00000000u;
goto P_0c0604f6;
P_0c0604f6: /* original 3357, guest PC 0x0c0604f6 */
if(!s->budget--) { s->failed_pc=0x0c0604f6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[5])!=0);
goto P_0c0604f8;
P_0c0604f8: /* original 353e, guest PC 0x0c0604f8 */
if(!s->budget--) { s->failed_pc=0x0c0604f8u; return 0; }
wide=(uint64_t)r[5]+r[3]+(r[17]&1u); r[5]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0604fa;
P_0c0604fa: /* original 4521, guest PC 0x0c0604fa */
if(!s->budget--) { s->failed_pc=0x0c0604fau; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]=(uint32_t)((int32_t)r[5]>>1);
goto P_0c0604fc;
P_0c0604fc: /* original d310, guest PC 0x0c0604fc */
if(!s->budget--) { s->failed_pc=0x0c0604fcu; return 0; }
r[3]=read(ram,0x0c060540u,4);
goto P_0c0604fe;
P_0c0604fe: /* original 75ff, guest PC 0x0c0604fe */
if(!s->budget--) { s->failed_pc=0x0c0604feu; return 0; }
r[5]+=0xffffffffu;
goto P_0c060500;
P_0c060500: /* original e05c, guest PC 0x0c060500 */
if(!s->budget--) { s->failed_pc=0x0c060500u; return 0; }
r[0]=0x0000005cu;
goto P_0c060502;
P_0c060502: /* original 62e3, guest PC 0x0c060502 */
if(!s->budget--) { s->failed_pc=0x0c060502u; return 0; }
r[2]=r[14];
goto P_0c060504;
P_0c060504: /* original 0e56, guest PC 0x0c060504 */
if(!s->budget--) { s->failed_pc=0x0c060504u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c060506;
P_0c060506: /* original e074, guest PC 0x0c060506 */
if(!s->budget--) { s->failed_pc=0x0c060506u; return 0; }
r[0]=0x00000074u;
goto P_0c060508;
P_0c060508: /* original 3f08, guest PC 0x0c060508 */
if(!s->budget--) { s->failed_pc=0x0c060508u; return 0; }
r[15]-=r[0];
goto P_0c06050a;
P_0c06050a: /* original 430b, guest PC 0x0c06050a */
if(!s->budget--) { s->failed_pc=0x0c06050au; return 0; }
target=r[3];
r[16]=code_base|0x0c06050eu;
r[1]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06050eu) { target=s->pc; goto dispatch; }
goto P_0c06050e;
P_0c06050c: /* original 61f3, guest PC 0x0c06050c */
if(!s->budget--) { s->failed_pc=0x0c06050cu; return 0; }
r[1]=r[15];
goto P_0c06050e;
P_0c06050e: /* original bd8f, guest PC 0x0c06050e */
if(!s->budget--) { s->failed_pc=0x0c06050eu; return 0; }
target=code_base|0x0c060030u; r[16]=code_base|0x0c060512u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060512u) { target=s->pc; goto dispatch; }
goto P_0c060512;
P_0c060510: /* original 0009, guest PC 0x0c060510 */
if(!s->budget--) { s->failed_pc=0x0c060510u; return 0; }
goto P_0c060512;
P_0c060512: /* original d10c, guest PC 0x0c060512 */
if(!s->budget--) { s->failed_pc=0x0c060512u; return 0; }
r[1]=read(ram,0x0c060544u,4);
goto P_0c060514;
P_0c060514: /* original 21d2, guest PC 0x0c060514 */
if(!s->budget--) { s->failed_pc=0x0c060514u; return 0; }
write(ram,r[1],r[13],4);
goto P_0c060516;
P_0c060516: /* original d30c, guest PC 0x0c060516 */
if(!s->budget--) { s->failed_pc=0x0c060516u; return 0; }
r[3]=read(ram,0x0c060548u,4);
goto P_0c060518;
P_0c060518: /* original 23d2, guest PC 0x0c060518 */
if(!s->budget--) { s->failed_pc=0x0c060518u; return 0; }
write(ram,r[3],r[13],4);
goto P_0c06051a;
P_0c06051a: /* original 60d3, guest PC 0x0c06051a */
if(!s->budget--) { s->failed_pc=0x0c06051au; return 0; }
r[0]=r[13];
goto P_0c06051c;
P_0c06051c: /* original 0009, guest PC 0x0c06051c */
if(!s->budget--) { s->failed_pc=0x0c06051cu; return 0; }
goto P_0c06051e;
P_0c06051e: /* original 910b, guest PC 0x0c06051e */
if(!s->budget--) { s->failed_pc=0x0c06051eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060538u,2);
goto P_0c060520;
P_0c060520: /* original 3f1c, guest PC 0x0c060520 */
if(!s->budget--) { s->failed_pc=0x0c060520u; return 0; }
r[15]+=r[1];
goto P_0c060522;
P_0c060522: /* original 4f26, guest PC 0x0c060522 */
if(!s->budget--) { s->failed_pc=0x0c060522u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c060524;
P_0c060524: /* original 68f6, guest PC 0x0c060524 */
if(!s->budget--) { s->failed_pc=0x0c060524u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c060526;
P_0c060526: /* original 69f6, guest PC 0x0c060526 */
if(!s->budget--) { s->failed_pc=0x0c060526u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c060528;
P_0c060528: /* original 6af6, guest PC 0x0c060528 */
if(!s->budget--) { s->failed_pc=0x0c060528u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06052a;
P_0c06052a: /* original 6bf6, guest PC 0x0c06052a */
if(!s->budget--) { s->failed_pc=0x0c06052au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06052c;
P_0c06052c: /* original 6cf6, guest PC 0x0c06052c */
if(!s->budget--) { s->failed_pc=0x0c06052cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06052e;
P_0c06052e: /* original 6df6, guest PC 0x0c06052e */
if(!s->budget--) { s->failed_pc=0x0c06052eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c060530;
P_0c060530: /* original 000b, guest PC 0x0c060530 */
if(!s->budget--) { s->failed_pc=0x0c060530u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c060532: /* original 6ef6, guest PC 0x0c060532 */
if(!s->budget--) { s->failed_pc=0x0c060532u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c060534u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c060534u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
