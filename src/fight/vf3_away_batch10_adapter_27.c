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
int vf3_away_batch10_adapter_27(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c070008u: goto P_0c070008;
case 0x0c07000au: goto P_0c07000a;
case 0x0c07000cu: goto P_0c07000c;
case 0x0c07000eu: goto P_0c07000e;
case 0x0c070010u: goto P_0c070010;
case 0x0c070012u: goto P_0c070012;
case 0x0c070014u: goto P_0c070014;
case 0x0c070016u: goto P_0c070016;
case 0x0c070018u: goto P_0c070018;
case 0x0c07001au: goto P_0c07001a;
case 0x0c07001cu: goto P_0c07001c;
case 0x0c07001eu: goto P_0c07001e;
case 0x0c070020u: goto P_0c070020;
case 0x0c070022u: goto P_0c070022;
case 0x0c070024u: goto P_0c070024;
case 0x0c070026u: goto P_0c070026;
case 0x0c070028u: goto P_0c070028;
case 0x0c07002au: goto P_0c07002a;
case 0x0c07002cu: goto P_0c07002c;
case 0x0c07002eu: goto P_0c07002e;
case 0x0c070030u: goto P_0c070030;
case 0x0c070032u: goto P_0c070032;
case 0x0c070034u: goto P_0c070034;
case 0x0c070036u: goto P_0c070036;
case 0x0c070038u: goto P_0c070038;
case 0x0c07003au: goto P_0c07003a;
case 0x0c07003cu: goto P_0c07003c;
case 0x0c07003eu: goto P_0c07003e;
case 0x0c070040u: goto P_0c070040;
case 0x0c070042u: goto P_0c070042;
case 0x0c070044u: goto P_0c070044;
case 0x0c070046u: goto P_0c070046;
case 0x0c070048u: goto P_0c070048;
case 0x0c07004au: goto P_0c07004a;
case 0x0c07004cu: goto P_0c07004c;
case 0x0c07004eu: goto P_0c07004e;
case 0x0c070050u: goto P_0c070050;
case 0x0c070052u: goto P_0c070052;
case 0x0c070054u: goto P_0c070054;
case 0x0c070056u: goto P_0c070056;
case 0x0c070058u: goto P_0c070058;
case 0x0c07005au: goto P_0c07005a;
case 0x0c07005cu: goto P_0c07005c;
case 0x0c07005eu: goto P_0c07005e;
case 0x0c070060u: goto P_0c070060;
case 0x0c070088u: goto P_0c070088;
case 0x0c07008au: goto P_0c07008a;
case 0x0c07008cu: goto P_0c07008c;
case 0x0c07008eu: goto P_0c07008e;
case 0x0c070090u: goto P_0c070090;
case 0x0c070092u: goto P_0c070092;
case 0x0c070094u: goto P_0c070094;
case 0x0c070096u: goto P_0c070096;
case 0x0c070098u: goto P_0c070098;
case 0x0c07009au: goto P_0c07009a;
case 0x0c07009cu: goto P_0c07009c;
case 0x0c07009eu: goto P_0c07009e;
case 0x0c0700a0u: goto P_0c0700a0;
case 0x0c0700a2u: goto P_0c0700a2;
case 0x0c0700a4u: goto P_0c0700a4;
case 0x0c0700a6u: goto P_0c0700a6;
case 0x0c0700a8u: goto P_0c0700a8;
case 0x0c0700aau: goto P_0c0700aa;
case 0x0c0700acu: goto P_0c0700ac;
case 0x0c0700aeu: goto P_0c0700ae;
case 0x0c0700b0u: goto P_0c0700b0;
case 0x0c0700b2u: goto P_0c0700b2;
case 0x0c0700b4u: goto P_0c0700b4;
case 0x0c0700b6u: goto P_0c0700b6;
case 0x0c0700b8u: goto P_0c0700b8;
case 0x0c0700bau: goto P_0c0700ba;
case 0x0c0700bcu: goto P_0c0700bc;
case 0x0c0700beu: goto P_0c0700be;
case 0x0c0700c0u: goto P_0c0700c0;
case 0x0c0700c2u: goto P_0c0700c2;
case 0x0c0700c4u: goto P_0c0700c4;
case 0x0c0700c6u: goto P_0c0700c6;
case 0x0c0700c8u: goto P_0c0700c8;
case 0x0c0700cau: goto P_0c0700ca;
case 0x0c0700ccu: goto P_0c0700cc;
case 0x0c0700ceu: goto P_0c0700ce;
case 0x0c0700d0u: goto P_0c0700d0;
case 0x0c0700d2u: goto P_0c0700d2;
case 0x0c0700d4u: goto P_0c0700d4;
case 0x0c0700d6u: goto P_0c0700d6;
case 0x0c0700d8u: goto P_0c0700d8;
case 0x0c0700dau: goto P_0c0700da;
case 0x0c0700dcu: goto P_0c0700dc;
case 0x0c0700deu: goto P_0c0700de;
case 0x0c0700e0u: goto P_0c0700e0;
case 0x0c0700e2u: goto P_0c0700e2;
case 0x0c0700e4u: goto P_0c0700e4;
case 0x0c0700e6u: goto P_0c0700e6;
case 0x0c0700e8u: goto P_0c0700e8;
case 0x0c0700eau: goto P_0c0700ea;
case 0x0c0700ecu: goto P_0c0700ec;
case 0x0c0700eeu: goto P_0c0700ee;
case 0x0c0700f0u: goto P_0c0700f0;
case 0x0c0700f2u: goto P_0c0700f2;
case 0x0c0700f4u: goto P_0c0700f4;
case 0x0c0700f6u: goto P_0c0700f6;
case 0x0c0700f8u: goto P_0c0700f8;
case 0x0c0700fau: goto P_0c0700fa;
case 0x0c070108u: goto P_0c070108;
case 0x0c07010au: goto P_0c07010a;
case 0x0c07010cu: goto P_0c07010c;
case 0x0c07010eu: goto P_0c07010e;
case 0x0c070110u: goto P_0c070110;
case 0x0c070112u: goto P_0c070112;
case 0x0c070114u: goto P_0c070114;
case 0x0c070116u: goto P_0c070116;
case 0x0c070118u: goto P_0c070118;
case 0x0c07011au: goto P_0c07011a;
case 0x0c07011cu: goto P_0c07011c;
case 0x0c07011eu: goto P_0c07011e;
case 0x0c070120u: goto P_0c070120;
case 0x0c070122u: goto P_0c070122;
case 0x0c070124u: goto P_0c070124;
case 0x0c070126u: goto P_0c070126;
case 0x0c070128u: goto P_0c070128;
case 0x0c07012au: goto P_0c07012a;
case 0x0c07012cu: goto P_0c07012c;
case 0x0c07012eu: goto P_0c07012e;
case 0x0c070130u: goto P_0c070130;
case 0x0c070132u: goto P_0c070132;
case 0x0c070134u: goto P_0c070134;
case 0x0c070136u: goto P_0c070136;
case 0x0c070138u: goto P_0c070138;
case 0x0c07013au: goto P_0c07013a;
case 0x0c07013cu: goto P_0c07013c;
case 0x0c07013eu: goto P_0c07013e;
case 0x0c070140u: goto P_0c070140;
case 0x0c070142u: goto P_0c070142;
case 0x0c070144u: goto P_0c070144;
case 0x0c070146u: goto P_0c070146;
case 0x0c070148u: goto P_0c070148;
case 0x0c07014au: goto P_0c07014a;
case 0x0c07014cu: goto P_0c07014c;
case 0x0c07014eu: goto P_0c07014e;
case 0x0c070154u: goto P_0c070154;
case 0x0c070156u: goto P_0c070156;
case 0x0c070158u: goto P_0c070158;
case 0x0c07015au: goto P_0c07015a;
case 0x0c07015cu: goto P_0c07015c;
case 0x0c07015eu: goto P_0c07015e;
case 0x0c070160u: goto P_0c070160;
case 0x0c070162u: goto P_0c070162;
case 0x0c070164u: goto P_0c070164;
case 0x0c070166u: goto P_0c070166;
case 0x0c070168u: goto P_0c070168;
case 0x0c07016au: goto P_0c07016a;
case 0x0c07016cu: goto P_0c07016c;
case 0x0c07016eu: goto P_0c07016e;
case 0x0c070170u: goto P_0c070170;
case 0x0c070172u: goto P_0c070172;
case 0x0c070174u: goto P_0c070174;
case 0x0c070176u: goto P_0c070176;
case 0x0c070178u: goto P_0c070178;
case 0x0c07017au: goto P_0c07017a;
case 0x0c07017cu: goto P_0c07017c;
case 0x0c07017eu: goto P_0c07017e;
case 0x0c070180u: goto P_0c070180;
case 0x0c070182u: goto P_0c070182;
case 0x0c070184u: goto P_0c070184;
case 0x0c070186u: goto P_0c070186;
case 0x0c070188u: goto P_0c070188;
case 0x0c07018au: goto P_0c07018a;
case 0x0c07018cu: goto P_0c07018c;
case 0x0c07018eu: goto P_0c07018e;
case 0x0c070190u: goto P_0c070190;
case 0x0c070192u: goto P_0c070192;
case 0x0c070194u: goto P_0c070194;
case 0x0c070196u: goto P_0c070196;
case 0x0c070198u: goto P_0c070198;
case 0x0c07019au: goto P_0c07019a;
case 0x0c0701a0u: goto P_0c0701a0;
case 0x0c0701a2u: goto P_0c0701a2;
case 0x0c0701a4u: goto P_0c0701a4;
case 0x0c0701a6u: goto P_0c0701a6;
case 0x0c0701a8u: goto P_0c0701a8;
case 0x0c0701aau: goto P_0c0701aa;
case 0x0c0701acu: goto P_0c0701ac;
case 0x0c0701aeu: goto P_0c0701ae;
case 0x0c0701b0u: goto P_0c0701b0;
case 0x0c0701b2u: goto P_0c0701b2;
case 0x0c0701b4u: goto P_0c0701b4;
case 0x0c0701b6u: goto P_0c0701b6;
case 0x0c0701b8u: goto P_0c0701b8;
case 0x0c0701bau: goto P_0c0701ba;
case 0x0c0701bcu: goto P_0c0701bc;
case 0x0c0701beu: goto P_0c0701be;
case 0x0c0701c0u: goto P_0c0701c0;
case 0x0c0701c2u: goto P_0c0701c2;
case 0x0c0701c4u: goto P_0c0701c4;
case 0x0c0701c6u: goto P_0c0701c6;
case 0x0c0701c8u: goto P_0c0701c8;
case 0x0c0701cau: goto P_0c0701ca;
case 0x0c0701ccu: goto P_0c0701cc;
case 0x0c0701ceu: goto P_0c0701ce;
case 0x0c0701d0u: goto P_0c0701d0;
case 0x0c0701d2u: goto P_0c0701d2;
case 0x0c0701d4u: goto P_0c0701d4;
case 0x0c0701d6u: goto P_0c0701d6;
case 0x0c0701d8u: goto P_0c0701d8;
case 0x0c0701dau: goto P_0c0701da;
case 0x0c0701e4u: goto P_0c0701e4;
case 0x0c0701e6u: goto P_0c0701e6;
case 0x0c0701e8u: goto P_0c0701e8;
case 0x0c0701eau: goto P_0c0701ea;
case 0x0c0701ecu: goto P_0c0701ec;
case 0x0c0701eeu: goto P_0c0701ee;
case 0x0c0701f0u: goto P_0c0701f0;
case 0x0c0701f2u: goto P_0c0701f2;
case 0x0c0701f4u: goto P_0c0701f4;
case 0x0c0701f6u: goto P_0c0701f6;
case 0x0c0701f8u: goto P_0c0701f8;
case 0x0c0701fau: goto P_0c0701fa;
case 0x0c0701fcu: goto P_0c0701fc;
case 0x0c0701feu: goto P_0c0701fe;
case 0x0c070200u: goto P_0c070200;
case 0x0c070202u: goto P_0c070202;
case 0x0c070204u: goto P_0c070204;
case 0x0c070206u: goto P_0c070206;
case 0x0c070208u: goto P_0c070208;
case 0x0c07020au: goto P_0c07020a;
case 0x0c07020cu: goto P_0c07020c;
case 0x0c07020eu: goto P_0c07020e;
case 0x0c070210u: goto P_0c070210;
case 0x0c070212u: goto P_0c070212;
case 0x0c070214u: goto P_0c070214;
case 0x0c070216u: goto P_0c070216;
case 0x0c070218u: goto P_0c070218;
case 0x0c07021au: goto P_0c07021a;
case 0x0c07021cu: goto P_0c07021c;
case 0x0c07021eu: goto P_0c07021e;
case 0x0c070220u: goto P_0c070220;
case 0x0c070222u: goto P_0c070222;
case 0x0c070224u: goto P_0c070224;
case 0x0c070226u: goto P_0c070226;
case 0x0c070228u: goto P_0c070228;
case 0x0c07022au: goto P_0c07022a;
case 0x0c07022cu: goto P_0c07022c;
case 0x0c07022eu: goto P_0c07022e;
case 0x0c070230u: goto P_0c070230;
case 0x0c070232u: goto P_0c070232;
case 0x0c070234u: goto P_0c070234;
case 0x0c070236u: goto P_0c070236;
case 0x0c070238u: goto P_0c070238;
case 0x0c070240u: goto P_0c070240;
case 0x0c070242u: goto P_0c070242;
case 0x0c070244u: goto P_0c070244;
case 0x0c070246u: goto P_0c070246;
case 0x0c070248u: goto P_0c070248;
case 0x0c07024au: goto P_0c07024a;
case 0x0c07024cu: goto P_0c07024c;
case 0x0c07024eu: goto P_0c07024e;
case 0x0c070250u: goto P_0c070250;
case 0x0c070252u: goto P_0c070252;
case 0x0c070254u: goto P_0c070254;
case 0x0c070256u: goto P_0c070256;
case 0x0c070258u: goto P_0c070258;
case 0x0c07025au: goto P_0c07025a;
case 0x0c07025cu: goto P_0c07025c;
case 0x0c07025eu: goto P_0c07025e;
case 0x0c070260u: goto P_0c070260;
case 0x0c070262u: goto P_0c070262;
case 0x0c070264u: goto P_0c070264;
case 0x0c070266u: goto P_0c070266;
case 0x0c070268u: goto P_0c070268;
case 0x0c07026au: goto P_0c07026a;
case 0x0c07026cu: goto P_0c07026c;
case 0x0c07026eu: goto P_0c07026e;
case 0x0c070270u: goto P_0c070270;
case 0x0c070272u: goto P_0c070272;
case 0x0c070274u: goto P_0c070274;
case 0x0c070276u: goto P_0c070276;
case 0x0c070278u: goto P_0c070278;
case 0x0c07027au: goto P_0c07027a;
case 0x0c07027cu: goto P_0c07027c;
case 0x0c07027eu: goto P_0c07027e;
case 0x0c070280u: goto P_0c070280;
case 0x0c070282u: goto P_0c070282;
case 0x0c070284u: goto P_0c070284;
case 0x0c070286u: goto P_0c070286;
case 0x0c070288u: goto P_0c070288;
case 0x0c07028au: goto P_0c07028a;
case 0x0c07028cu: goto P_0c07028c;
case 0x0c07028eu: goto P_0c07028e;
case 0x0c070290u: goto P_0c070290;
case 0x0c070292u: goto P_0c070292;
case 0x0c070294u: goto P_0c070294;
case 0x0c070296u: goto P_0c070296;
case 0x0c070298u: goto P_0c070298;
case 0x0c07029au: goto P_0c07029a;
case 0x0c07029cu: goto P_0c07029c;
case 0x0c07029eu: goto P_0c07029e;
case 0x0c0702a0u: goto P_0c0702a0;
case 0x0c0702a2u: goto P_0c0702a2;
case 0x0c0702a4u: goto P_0c0702a4;
case 0x0c0702a6u: goto P_0c0702a6;
case 0x0c0702a8u: goto P_0c0702a8;
case 0x0c0702aau: goto P_0c0702aa;
case 0x0c0702acu: goto P_0c0702ac;
case 0x0c0702aeu: goto P_0c0702ae;
case 0x0c0702b0u: goto P_0c0702b0;
case 0x0c0702b2u: goto P_0c0702b2;
case 0x0c0702b4u: goto P_0c0702b4;
case 0x0c0702b6u: goto P_0c0702b6;
case 0x0c0702b8u: goto P_0c0702b8;
case 0x0c0702bau: goto P_0c0702ba;
case 0x0c0702bcu: goto P_0c0702bc;
case 0x0c0702beu: goto P_0c0702be;
case 0x0c0702c0u: goto P_0c0702c0;
case 0x0c0702c2u: goto P_0c0702c2;
case 0x0c0702c4u: goto P_0c0702c4;
case 0x0c0702c6u: goto P_0c0702c6;
case 0x0c0702c8u: goto P_0c0702c8;
case 0x0c0702cau: goto P_0c0702ca;
case 0x0c0702ccu: goto P_0c0702cc;
case 0x0c0702ceu: goto P_0c0702ce;
case 0x0c0702d0u: goto P_0c0702d0;
case 0x0c0702d2u: goto P_0c0702d2;
case 0x0c0702d4u: goto P_0c0702d4;
case 0x0c0702d6u: goto P_0c0702d6;
case 0x0c0702d8u: goto P_0c0702d8;
case 0x0c0702dau: goto P_0c0702da;
case 0x0c0702dcu: goto P_0c0702dc;
case 0x0c0702deu: goto P_0c0702de;
case 0x0c0702e0u: goto P_0c0702e0;
case 0x0c0702e2u: goto P_0c0702e2;
case 0x0c0702e4u: goto P_0c0702e4;
case 0x0c0702e6u: goto P_0c0702e6;
case 0x0c0702e8u: goto P_0c0702e8;
case 0x0c0702eau: goto P_0c0702ea;
case 0x0c0702ecu: goto P_0c0702ec;
case 0x0c0702eeu: goto P_0c0702ee;
case 0x0c0702f0u: goto P_0c0702f0;
case 0x0c0702f2u: goto P_0c0702f2;
case 0x0c0702f4u: goto P_0c0702f4;
case 0x0c0702f6u: goto P_0c0702f6;
case 0x0c0702f8u: goto P_0c0702f8;
case 0x0c0702fau: goto P_0c0702fa;
case 0x0c0702fcu: goto P_0c0702fc;
case 0x0c0702feu: goto P_0c0702fe;
case 0x0c070300u: goto P_0c070300;
case 0x0c070302u: goto P_0c070302;
case 0x0c070304u: goto P_0c070304;
case 0x0c070306u: goto P_0c070306;
case 0x0c070308u: goto P_0c070308;
case 0x0c07030au: goto P_0c07030a;
case 0x0c07030cu: goto P_0c07030c;
case 0x0c07030eu: goto P_0c07030e;
case 0x0c070310u: goto P_0c070310;
case 0x0c070312u: goto P_0c070312;
case 0x0c070314u: goto P_0c070314;
case 0x0c070316u: goto P_0c070316;
case 0x0c070318u: goto P_0c070318;
case 0x0c07031au: goto P_0c07031a;
case 0x0c07031cu: goto P_0c07031c;
case 0x0c07031eu: goto P_0c07031e;
case 0x0c070320u: goto P_0c070320;
case 0x0c070322u: goto P_0c070322;
case 0x0c070324u: goto P_0c070324;
case 0x0c070326u: goto P_0c070326;
case 0x0c070328u: goto P_0c070328;
case 0x0c07032au: goto P_0c07032a;
case 0x0c07032cu: goto P_0c07032c;
case 0x0c07032eu: goto P_0c07032e;
case 0x0c070330u: goto P_0c070330;
case 0x0c070332u: goto P_0c070332;
case 0x0c070334u: goto P_0c070334;
case 0x0c070336u: goto P_0c070336;
case 0x0c070338u: goto P_0c070338;
case 0x0c07033au: goto P_0c07033a;
case 0x0c07033cu: goto P_0c07033c;
case 0x0c070344u: goto P_0c070344;
case 0x0c070346u: goto P_0c070346;
case 0x0c070348u: goto P_0c070348;
case 0x0c07034au: goto P_0c07034a;
case 0x0c07034cu: goto P_0c07034c;
case 0x0c07034eu: goto P_0c07034e;
case 0x0c070350u: goto P_0c070350;
case 0x0c070352u: goto P_0c070352;
case 0x0c070354u: goto P_0c070354;
case 0x0c070356u: goto P_0c070356;
case 0x0c070358u: goto P_0c070358;
case 0x0c07035au: goto P_0c07035a;
case 0x0c07035cu: goto P_0c07035c;
case 0x0c07035eu: goto P_0c07035e;
case 0x0c070360u: goto P_0c070360;
case 0x0c070362u: goto P_0c070362;
case 0x0c070364u: goto P_0c070364;
case 0x0c070366u: goto P_0c070366;
case 0x0c070368u: goto P_0c070368;
case 0x0c07036au: goto P_0c07036a;
case 0x0c07036cu: goto P_0c07036c;
case 0x0c07036eu: goto P_0c07036e;
case 0x0c070370u: goto P_0c070370;
case 0x0c070372u: goto P_0c070372;
case 0x0c070374u: goto P_0c070374;
case 0x0c070376u: goto P_0c070376;
case 0x0c070378u: goto P_0c070378;
case 0x0c07037au: goto P_0c07037a;
case 0x0c07037cu: goto P_0c07037c;
case 0x0c07037eu: goto P_0c07037e;
case 0x0c070380u: goto P_0c070380;
case 0x0c070382u: goto P_0c070382;
case 0x0c070384u: goto P_0c070384;
case 0x0c070386u: goto P_0c070386;
case 0x0c070388u: goto P_0c070388;
case 0x0c070390u: goto P_0c070390;
case 0x0c070392u: goto P_0c070392;
case 0x0c070394u: goto P_0c070394;
case 0x0c070396u: goto P_0c070396;
case 0x0c070398u: goto P_0c070398;
case 0x0c07039au: goto P_0c07039a;
case 0x0c07039cu: goto P_0c07039c;
case 0x0c07039eu: goto P_0c07039e;
case 0x0c0703a0u: goto P_0c0703a0;
case 0x0c0703a2u: goto P_0c0703a2;
case 0x0c0703a4u: goto P_0c0703a4;
case 0x0c0703a6u: goto P_0c0703a6;
case 0x0c0703a8u: goto P_0c0703a8;
case 0x0c0703aau: goto P_0c0703aa;
case 0x0c0703acu: goto P_0c0703ac;
case 0x0c0703aeu: goto P_0c0703ae;
case 0x0c0703b0u: goto P_0c0703b0;
case 0x0c0703b2u: goto P_0c0703b2;
case 0x0c0703b4u: goto P_0c0703b4;
case 0x0c0703b6u: goto P_0c0703b6;
case 0x0c0703b8u: goto P_0c0703b8;
case 0x0c0703bau: goto P_0c0703ba;
case 0x0c0703bcu: goto P_0c0703bc;
case 0x0c0703beu: goto P_0c0703be;
case 0x0c0703c0u: goto P_0c0703c0;
case 0x0c0703c2u: goto P_0c0703c2;
case 0x0c0703c4u: goto P_0c0703c4;
case 0x0c0703c6u: goto P_0c0703c6;
case 0x0c0703c8u: goto P_0c0703c8;
case 0x0c0703cau: goto P_0c0703ca;
case 0x0c0703ccu: goto P_0c0703cc;
case 0x0c0703d8u: goto P_0c0703d8;
case 0x0c0703dau: goto P_0c0703da;
case 0x0c0703dcu: goto P_0c0703dc;
case 0x0c0703deu: goto P_0c0703de;
case 0x0c0703e0u: goto P_0c0703e0;
case 0x0c0703e2u: goto P_0c0703e2;
case 0x0c0703e4u: goto P_0c0703e4;
case 0x0c0703e6u: goto P_0c0703e6;
case 0x0c0703e8u: goto P_0c0703e8;
case 0x0c0703eau: goto P_0c0703ea;
case 0x0c0703ecu: goto P_0c0703ec;
case 0x0c0703eeu: goto P_0c0703ee;
case 0x0c0703f0u: goto P_0c0703f0;
case 0x0c0703f2u: goto P_0c0703f2;
case 0x0c0703f4u: goto P_0c0703f4;
case 0x0c0703f6u: goto P_0c0703f6;
case 0x0c0703f8u: goto P_0c0703f8;
case 0x0c0703fau: goto P_0c0703fa;
case 0x0c0703fcu: goto P_0c0703fc;
case 0x0c0703feu: goto P_0c0703fe;
case 0x0c070400u: goto P_0c070400;
case 0x0c070402u: goto P_0c070402;
case 0x0c070404u: goto P_0c070404;
case 0x0c070406u: goto P_0c070406;
case 0x0c070408u: goto P_0c070408;
case 0x0c07040au: goto P_0c07040a;
case 0x0c07040cu: goto P_0c07040c;
case 0x0c070418u: goto P_0c070418;
case 0x0c07041au: goto P_0c07041a;
case 0x0c07041cu: goto P_0c07041c;
case 0x0c07041eu: goto P_0c07041e;
case 0x0c070420u: goto P_0c070420;
case 0x0c070422u: goto P_0c070422;
case 0x0c070424u: goto P_0c070424;
case 0x0c070426u: goto P_0c070426;
case 0x0c070428u: goto P_0c070428;
case 0x0c07042au: goto P_0c07042a;
case 0x0c07042cu: goto P_0c07042c;
case 0x0c07042eu: goto P_0c07042e;
case 0x0c070430u: goto P_0c070430;
case 0x0c070432u: goto P_0c070432;
case 0x0c070434u: goto P_0c070434;
case 0x0c070436u: goto P_0c070436;
case 0x0c070438u: goto P_0c070438;
case 0x0c07043au: goto P_0c07043a;
case 0x0c07043cu: goto P_0c07043c;
case 0x0c07043eu: goto P_0c07043e;
case 0x0c070440u: goto P_0c070440;
case 0x0c070442u: goto P_0c070442;
case 0x0c070444u: goto P_0c070444;
case 0x0c070446u: goto P_0c070446;
case 0x0c070448u: goto P_0c070448;
case 0x0c07044au: goto P_0c07044a;
case 0x0c07044cu: goto P_0c07044c;
case 0x0c07044eu: goto P_0c07044e;
case 0x0c070450u: goto P_0c070450;
case 0x0c070452u: goto P_0c070452;
case 0x0c070454u: goto P_0c070454;
case 0x0c070456u: goto P_0c070456;
case 0x0c070458u: goto P_0c070458;
case 0x0c07045au: goto P_0c07045a;
case 0x0c07045cu: goto P_0c07045c;
case 0x0c07045eu: goto P_0c07045e;
case 0x0c070460u: goto P_0c070460;
case 0x0c070462u: goto P_0c070462;
case 0x0c070464u: goto P_0c070464;
case 0x0c070466u: goto P_0c070466;
case 0x0c070468u: goto P_0c070468;
case 0x0c07046au: goto P_0c07046a;
case 0x0c07046cu: goto P_0c07046c;
case 0x0c07046eu: goto P_0c07046e;
case 0x0c070470u: goto P_0c070470;
case 0x0c070472u: goto P_0c070472;
case 0x0c070474u: goto P_0c070474;
case 0x0c070476u: goto P_0c070476;
case 0x0c070478u: goto P_0c070478;
case 0x0c07047au: goto P_0c07047a;
case 0x0c07047cu: goto P_0c07047c;
case 0x0c07047eu: goto P_0c07047e;
case 0x0c070480u: goto P_0c070480;
case 0x0c070482u: goto P_0c070482;
case 0x0c070484u: goto P_0c070484;
case 0x0c070486u: goto P_0c070486;
case 0x0c070488u: goto P_0c070488;
case 0x0c07048au: goto P_0c07048a;
case 0x0c07048cu: goto P_0c07048c;
case 0x0c07048eu: goto P_0c07048e;
case 0x0c070490u: goto P_0c070490;
case 0x0c070492u: goto P_0c070492;
case 0x0c070494u: goto P_0c070494;
case 0x0c070496u: goto P_0c070496;
case 0x0c070498u: goto P_0c070498;
case 0x0c07049au: goto P_0c07049a;
case 0x0c07049cu: goto P_0c07049c;
case 0x0c07049eu: goto P_0c07049e;
case 0x0c0704a0u: goto P_0c0704a0;
case 0x0c0704a2u: goto P_0c0704a2;
case 0x0c0704a4u: goto P_0c0704a4;
case 0x0c0704a6u: goto P_0c0704a6;
case 0x0c0704a8u: goto P_0c0704a8;
case 0x0c0704aau: goto P_0c0704aa;
case 0x0c0704acu: goto P_0c0704ac;
case 0x0c0704aeu: goto P_0c0704ae;
case 0x0c0704b0u: goto P_0c0704b0;
case 0x0c0704b2u: goto P_0c0704b2;
case 0x0c0704b4u: goto P_0c0704b4;
case 0x0c0704b6u: goto P_0c0704b6;
case 0x0c0704b8u: goto P_0c0704b8;
case 0x0c0704bau: goto P_0c0704ba;
case 0x0c0704bcu: goto P_0c0704bc;
case 0x0c0704beu: goto P_0c0704be;
case 0x0c0704c0u: goto P_0c0704c0;
case 0x0c0704c2u: goto P_0c0704c2;
case 0x0c0704c4u: goto P_0c0704c4;
case 0x0c0704c6u: goto P_0c0704c6;
case 0x0c0704c8u: goto P_0c0704c8;
case 0x0c0704cau: goto P_0c0704ca;
case 0x0c0704ccu: goto P_0c0704cc;
case 0x0c0704ceu: goto P_0c0704ce;
case 0x0c0704d0u: goto P_0c0704d0;
case 0x0c0704d2u: goto P_0c0704d2;
case 0x0c0704d4u: goto P_0c0704d4;
case 0x0c0704d6u: goto P_0c0704d6;
case 0x0c0704dcu: goto P_0c0704dc;
case 0x0c0704deu: goto P_0c0704de;
case 0x0c0704e0u: goto P_0c0704e0;
case 0x0c0704e2u: goto P_0c0704e2;
case 0x0c0704e4u: goto P_0c0704e4;
case 0x0c0704e6u: goto P_0c0704e6;
case 0x0c0704e8u: goto P_0c0704e8;
case 0x0c0704eau: goto P_0c0704ea;
case 0x0c0704ecu: goto P_0c0704ec;
case 0x0c0704eeu: goto P_0c0704ee;
case 0x0c0704f0u: goto P_0c0704f0;
case 0x0c0704f2u: goto P_0c0704f2;
case 0x0c0704f4u: goto P_0c0704f4;
case 0x0c0704f6u: goto P_0c0704f6;
case 0x0c0704f8u: goto P_0c0704f8;
case 0x0c0704fau: goto P_0c0704fa;
case 0x0c0704fcu: goto P_0c0704fc;
case 0x0c0704feu: goto P_0c0704fe;
case 0x0c070500u: goto P_0c070500;
case 0x0c070502u: goto P_0c070502;
case 0x0c070504u: goto P_0c070504;
case 0x0c070506u: goto P_0c070506;
case 0x0c070508u: goto P_0c070508;
case 0x0c07050au: goto P_0c07050a;
case 0x0c07050cu: goto P_0c07050c;
case 0x0c07050eu: goto P_0c07050e;
case 0x0c070510u: goto P_0c070510;
case 0x0c070512u: goto P_0c070512;
case 0x0c070514u: goto P_0c070514;
case 0x0c070516u: goto P_0c070516;
case 0x0c070518u: goto P_0c070518;
case 0x0c07051au: goto P_0c07051a;
case 0x0c07051cu: goto P_0c07051c;
case 0x0c07051eu: goto P_0c07051e;
case 0x0c070520u: goto P_0c070520;
case 0x0c070522u: goto P_0c070522;
case 0x0c070528u: goto P_0c070528;
case 0x0c07052au: goto P_0c07052a;
case 0x0c07052cu: goto P_0c07052c;
case 0x0c07052eu: goto P_0c07052e;
case 0x0c070530u: goto P_0c070530;
case 0x0c070532u: goto P_0c070532;
case 0x0c070534u: goto P_0c070534;
case 0x0c070536u: goto P_0c070536;
case 0x0c070538u: goto P_0c070538;
case 0x0c07053au: goto P_0c07053a;
case 0x0c07053cu: goto P_0c07053c;
case 0x0c07053eu: goto P_0c07053e;
case 0x0c070540u: goto P_0c070540;
case 0x0c070542u: goto P_0c070542;
case 0x0c070544u: goto P_0c070544;
case 0x0c070546u: goto P_0c070546;
case 0x0c070548u: goto P_0c070548;
case 0x0c07054au: goto P_0c07054a;
case 0x0c07054cu: goto P_0c07054c;
case 0x0c07054eu: goto P_0c07054e;
case 0x0c070550u: goto P_0c070550;
case 0x0c070552u: goto P_0c070552;
case 0x0c070554u: goto P_0c070554;
case 0x0c070556u: goto P_0c070556;
case 0x0c070558u: goto P_0c070558;
case 0x0c07055au: goto P_0c07055a;
case 0x0c07055cu: goto P_0c07055c;
case 0x0c07055eu: goto P_0c07055e;
case 0x0c070560u: goto P_0c070560;
case 0x0c070562u: goto P_0c070562;
case 0x0c070564u: goto P_0c070564;
case 0x0c070566u: goto P_0c070566;
case 0x0c070568u: goto P_0c070568;
case 0x0c07056au: goto P_0c07056a;
case 0x0c07056cu: goto P_0c07056c;
case 0x0c07056eu: goto P_0c07056e;
case 0x0c070574u: goto P_0c070574;
case 0x0c070576u: goto P_0c070576;
case 0x0c070578u: goto P_0c070578;
case 0x0c07057au: goto P_0c07057a;
case 0x0c07057cu: goto P_0c07057c;
case 0x0c07057eu: goto P_0c07057e;
case 0x0c070580u: goto P_0c070580;
case 0x0c070582u: goto P_0c070582;
case 0x0c070584u: goto P_0c070584;
case 0x0c070586u: goto P_0c070586;
case 0x0c070588u: goto P_0c070588;
case 0x0c07058au: goto P_0c07058a;
case 0x0c07058cu: goto P_0c07058c;
case 0x0c07058eu: goto P_0c07058e;
case 0x0c070590u: goto P_0c070590;
case 0x0c070592u: goto P_0c070592;
case 0x0c070594u: goto P_0c070594;
case 0x0c070596u: goto P_0c070596;
case 0x0c070598u: goto P_0c070598;
case 0x0c07059au: goto P_0c07059a;
case 0x0c07059cu: goto P_0c07059c;
case 0x0c07059eu: goto P_0c07059e;
case 0x0c0705a0u: goto P_0c0705a0;
case 0x0c0705a2u: goto P_0c0705a2;
case 0x0c0705a4u: goto P_0c0705a4;
case 0x0c0705a6u: goto P_0c0705a6;
case 0x0c0705a8u: goto P_0c0705a8;
case 0x0c0705aau: goto P_0c0705aa;
case 0x0c0705acu: goto P_0c0705ac;
case 0x0c0705b8u: goto P_0c0705b8;
case 0x0c0705bau: goto P_0c0705ba;
case 0x0c0705bcu: goto P_0c0705bc;
case 0x0c0705beu: goto P_0c0705be;
case 0x0c0705c0u: goto P_0c0705c0;
case 0x0c0705c2u: goto P_0c0705c2;
case 0x0c0705c4u: goto P_0c0705c4;
case 0x0c0705c6u: goto P_0c0705c6;
case 0x0c0705c8u: goto P_0c0705c8;
case 0x0c0705cau: goto P_0c0705ca;
case 0x0c0705ccu: goto P_0c0705cc;
case 0x0c0705ceu: goto P_0c0705ce;
case 0x0c0705d0u: goto P_0c0705d0;
case 0x0c0705d2u: goto P_0c0705d2;
case 0x0c0705d4u: goto P_0c0705d4;
case 0x0c0705d6u: goto P_0c0705d6;
case 0x0c0705d8u: goto P_0c0705d8;
case 0x0c0705dau: goto P_0c0705da;
case 0x0c0705dcu: goto P_0c0705dc;
case 0x0c0705deu: goto P_0c0705de;
case 0x0c0705e0u: goto P_0c0705e0;
case 0x0c0705e2u: goto P_0c0705e2;
case 0x0c0705e4u: goto P_0c0705e4;
case 0x0c0705e6u: goto P_0c0705e6;
case 0x0c0705e8u: goto P_0c0705e8;
case 0x0c0705eau: goto P_0c0705ea;
case 0x0c0705ecu: goto P_0c0705ec;
case 0x0c0705f8u: goto P_0c0705f8;
case 0x0c0705fau: goto P_0c0705fa;
case 0x0c0705fcu: goto P_0c0705fc;
case 0x0c0705feu: goto P_0c0705fe;
case 0x0c070600u: goto P_0c070600;
case 0x0c070602u: goto P_0c070602;
case 0x0c070604u: goto P_0c070604;
case 0x0c070606u: goto P_0c070606;
case 0x0c070608u: goto P_0c070608;
case 0x0c07060au: goto P_0c07060a;
case 0x0c07060cu: goto P_0c07060c;
case 0x0c07060eu: goto P_0c07060e;
case 0x0c070610u: goto P_0c070610;
case 0x0c070612u: goto P_0c070612;
case 0x0c070614u: goto P_0c070614;
case 0x0c070616u: goto P_0c070616;
case 0x0c070618u: goto P_0c070618;
case 0x0c07061au: goto P_0c07061a;
case 0x0c07061cu: goto P_0c07061c;
case 0x0c07061eu: goto P_0c07061e;
case 0x0c070620u: goto P_0c070620;
case 0x0c070622u: goto P_0c070622;
case 0x0c070624u: goto P_0c070624;
case 0x0c070626u: goto P_0c070626;
case 0x0c070628u: goto P_0c070628;
case 0x0c07062au: goto P_0c07062a;
case 0x0c07062cu: goto P_0c07062c;
case 0x0c07062eu: goto P_0c07062e;
case 0x0c070630u: goto P_0c070630;
case 0x0c070632u: goto P_0c070632;
case 0x0c070634u: goto P_0c070634;
case 0x0c070636u: goto P_0c070636;
case 0x0c070638u: goto P_0c070638;
case 0x0c07063au: goto P_0c07063a;
case 0x0c07063cu: goto P_0c07063c;
case 0x0c07063eu: goto P_0c07063e;
case 0x0c070640u: goto P_0c070640;
case 0x0c070642u: goto P_0c070642;
case 0x0c070644u: goto P_0c070644;
case 0x0c070646u: goto P_0c070646;
case 0x0c070648u: goto P_0c070648;
case 0x0c07064au: goto P_0c07064a;
case 0x0c07064cu: goto P_0c07064c;
case 0x0c07064eu: goto P_0c07064e;
case 0x0c070650u: goto P_0c070650;
case 0x0c070652u: goto P_0c070652;
case 0x0c070654u: goto P_0c070654;
case 0x0c070656u: goto P_0c070656;
case 0x0c070658u: goto P_0c070658;
case 0x0c07065au: goto P_0c07065a;
case 0x0c07065cu: goto P_0c07065c;
case 0x0c07065eu: goto P_0c07065e;
case 0x0c070660u: goto P_0c070660;
case 0x0c070662u: goto P_0c070662;
case 0x0c070664u: goto P_0c070664;
case 0x0c070666u: goto P_0c070666;
case 0x0c070668u: goto P_0c070668;
case 0x0c07066au: goto P_0c07066a;
case 0x0c07066cu: goto P_0c07066c;
case 0x0c07066eu: goto P_0c07066e;
case 0x0c070670u: goto P_0c070670;
case 0x0c070672u: goto P_0c070672;
case 0x0c070674u: goto P_0c070674;
case 0x0c070676u: goto P_0c070676;
case 0x0c070678u: goto P_0c070678;
case 0x0c07067au: goto P_0c07067a;
case 0x0c07067cu: goto P_0c07067c;
case 0x0c07067eu: goto P_0c07067e;
case 0x0c070680u: goto P_0c070680;
case 0x0c070682u: goto P_0c070682;
case 0x0c070684u: goto P_0c070684;
case 0x0c070686u: goto P_0c070686;
case 0x0c070688u: goto P_0c070688;
case 0x0c07068au: goto P_0c07068a;
case 0x0c07068cu: goto P_0c07068c;
case 0x0c07068eu: goto P_0c07068e;
case 0x0c070690u: goto P_0c070690;
case 0x0c070692u: goto P_0c070692;
case 0x0c070694u: goto P_0c070694;
case 0x0c070696u: goto P_0c070696;
case 0x0c070698u: goto P_0c070698;
case 0x0c07069au: goto P_0c07069a;
case 0x0c07069cu: goto P_0c07069c;
case 0x0c07069eu: goto P_0c07069e;
case 0x0c0706a0u: goto P_0c0706a0;
case 0x0c0706a2u: goto P_0c0706a2;
case 0x0c0706a4u: goto P_0c0706a4;
case 0x0c0706a6u: goto P_0c0706a6;
case 0x0c0706a8u: goto P_0c0706a8;
case 0x0c0706aau: goto P_0c0706aa;
case 0x0c0706acu: goto P_0c0706ac;
case 0x0c0706aeu: goto P_0c0706ae;
case 0x0c0706b0u: goto P_0c0706b0;
case 0x0c0706b2u: goto P_0c0706b2;
case 0x0c0706b4u: goto P_0c0706b4;
case 0x0c0706b6u: goto P_0c0706b6;
case 0x0c0706b8u: goto P_0c0706b8;
case 0x0c0706bau: goto P_0c0706ba;
case 0x0c0706bcu: goto P_0c0706bc;
case 0x0c0706beu: goto P_0c0706be;
case 0x0c0706c0u: goto P_0c0706c0;
case 0x0c0706c2u: goto P_0c0706c2;
case 0x0c0706c4u: goto P_0c0706c4;
case 0x0c0706c6u: goto P_0c0706c6;
case 0x0c0706c8u: goto P_0c0706c8;
case 0x0c0706cau: goto P_0c0706ca;
case 0x0c0706ccu: goto P_0c0706cc;
case 0x0c0706ceu: goto P_0c0706ce;
case 0x0c0706d0u: goto P_0c0706d0;
case 0x0c0706d2u: goto P_0c0706d2;
case 0x0c0706d4u: goto P_0c0706d4;
case 0x0c0706d6u: goto P_0c0706d6;
case 0x0c0706d8u: goto P_0c0706d8;
case 0x0c0706dau: goto P_0c0706da;
case 0x0c0706dcu: goto P_0c0706dc;
case 0x0c0706deu: goto P_0c0706de;
case 0x0c0706e0u: goto P_0c0706e0;
case 0x0c0706e2u: goto P_0c0706e2;
case 0x0c0706e4u: goto P_0c0706e4;
case 0x0c0706e6u: goto P_0c0706e6;
case 0x0c0706e8u: goto P_0c0706e8;
case 0x0c0706eau: goto P_0c0706ea;
case 0x0c0706ecu: goto P_0c0706ec;
case 0x0c0706eeu: goto P_0c0706ee;
case 0x0c0706f0u: goto P_0c0706f0;
case 0x0c0706f2u: goto P_0c0706f2;
case 0x0c0706f4u: goto P_0c0706f4;
case 0x0c0706fcu: goto P_0c0706fc;
case 0x0c0706feu: goto P_0c0706fe;
case 0x0c070700u: goto P_0c070700;
case 0x0c070702u: goto P_0c070702;
case 0x0c070704u: goto P_0c070704;
case 0x0c070706u: goto P_0c070706;
case 0x0c070708u: goto P_0c070708;
case 0x0c07070au: goto P_0c07070a;
case 0x0c07070cu: goto P_0c07070c;
case 0x0c07070eu: goto P_0c07070e;
case 0x0c070710u: goto P_0c070710;
case 0x0c070712u: goto P_0c070712;
case 0x0c070714u: goto P_0c070714;
case 0x0c070716u: goto P_0c070716;
case 0x0c070718u: goto P_0c070718;
case 0x0c07071au: goto P_0c07071a;
case 0x0c07071cu: goto P_0c07071c;
case 0x0c07071eu: goto P_0c07071e;
case 0x0c070720u: goto P_0c070720;
case 0x0c070722u: goto P_0c070722;
case 0x0c070724u: goto P_0c070724;
case 0x0c070726u: goto P_0c070726;
case 0x0c070728u: goto P_0c070728;
case 0x0c07072au: goto P_0c07072a;
case 0x0c07072cu: goto P_0c07072c;
case 0x0c07072eu: goto P_0c07072e;
case 0x0c070730u: goto P_0c070730;
case 0x0c070732u: goto P_0c070732;
case 0x0c070734u: goto P_0c070734;
case 0x0c070736u: goto P_0c070736;
case 0x0c070738u: goto P_0c070738;
case 0x0c07073au: goto P_0c07073a;
case 0x0c07073cu: goto P_0c07073c;
case 0x0c07073eu: goto P_0c07073e;
case 0x0c070740u: goto P_0c070740;
case 0x0c070748u: goto P_0c070748;
case 0x0c07074au: goto P_0c07074a;
case 0x0c07074cu: goto P_0c07074c;
case 0x0c07074eu: goto P_0c07074e;
case 0x0c070750u: goto P_0c070750;
case 0x0c070752u: goto P_0c070752;
case 0x0c070754u: goto P_0c070754;
case 0x0c070756u: goto P_0c070756;
case 0x0c070758u: goto P_0c070758;
case 0x0c07075au: goto P_0c07075a;
case 0x0c07075cu: goto P_0c07075c;
case 0x0c07075eu: goto P_0c07075e;
case 0x0c070760u: goto P_0c070760;
case 0x0c070762u: goto P_0c070762;
case 0x0c070764u: goto P_0c070764;
case 0x0c070766u: goto P_0c070766;
case 0x0c070768u: goto P_0c070768;
case 0x0c07076au: goto P_0c07076a;
case 0x0c07076cu: goto P_0c07076c;
case 0x0c07076eu: goto P_0c07076e;
case 0x0c070770u: goto P_0c070770;
case 0x0c070772u: goto P_0c070772;
case 0x0c070774u: goto P_0c070774;
case 0x0c070776u: goto P_0c070776;
case 0x0c070778u: goto P_0c070778;
case 0x0c07077au: goto P_0c07077a;
case 0x0c07077cu: goto P_0c07077c;
case 0x0c07077eu: goto P_0c07077e;
case 0x0c070780u: goto P_0c070780;
case 0x0c070782u: goto P_0c070782;
case 0x0c070784u: goto P_0c070784;
case 0x0c070790u: goto P_0c070790;
case 0x0c070792u: goto P_0c070792;
case 0x0c070794u: goto P_0c070794;
case 0x0c070796u: goto P_0c070796;
case 0x0c070798u: goto P_0c070798;
case 0x0c07079au: goto P_0c07079a;
case 0x0c07079cu: goto P_0c07079c;
case 0x0c07079eu: goto P_0c07079e;
case 0x0c0707a0u: goto P_0c0707a0;
case 0x0c0707a2u: goto P_0c0707a2;
case 0x0c0707a4u: goto P_0c0707a4;
case 0x0c0707a6u: goto P_0c0707a6;
case 0x0c0707a8u: goto P_0c0707a8;
case 0x0c0707aau: goto P_0c0707aa;
case 0x0c0707acu: goto P_0c0707ac;
case 0x0c0707aeu: goto P_0c0707ae;
case 0x0c0707b0u: goto P_0c0707b0;
case 0x0c0707b2u: goto P_0c0707b2;
case 0x0c0707b4u: goto P_0c0707b4;
case 0x0c0707b6u: goto P_0c0707b6;
case 0x0c0707b8u: goto P_0c0707b8;
case 0x0c0707bau: goto P_0c0707ba;
case 0x0c0707bcu: goto P_0c0707bc;
case 0x0c0707beu: goto P_0c0707be;
case 0x0c0707c0u: goto P_0c0707c0;
case 0x0c0707c2u: goto P_0c0707c2;
case 0x0c0707c4u: goto P_0c0707c4;
case 0x0c0707d0u: goto P_0c0707d0;
case 0x0c0707d2u: goto P_0c0707d2;
case 0x0c0707d4u: goto P_0c0707d4;
case 0x0c0707d6u: goto P_0c0707d6;
case 0x0c0707d8u: goto P_0c0707d8;
case 0x0c0707dau: goto P_0c0707da;
case 0x0c0707dcu: goto P_0c0707dc;
case 0x0c0707deu: goto P_0c0707de;
case 0x0c0707e0u: goto P_0c0707e0;
case 0x0c0707e2u: goto P_0c0707e2;
case 0x0c0707e4u: goto P_0c0707e4;
case 0x0c0707e6u: goto P_0c0707e6;
case 0x0c0707e8u: goto P_0c0707e8;
case 0x0c0707eau: goto P_0c0707ea;
case 0x0c0707ecu: goto P_0c0707ec;
case 0x0c0707eeu: goto P_0c0707ee;
case 0x0c0707f0u: goto P_0c0707f0;
case 0x0c0707f2u: goto P_0c0707f2;
case 0x0c0707f4u: goto P_0c0707f4;
case 0x0c0707f6u: goto P_0c0707f6;
case 0x0c0707f8u: goto P_0c0707f8;
case 0x0c0707fau: goto P_0c0707fa;
case 0x0c0707fcu: goto P_0c0707fc;
case 0x0c0707feu: goto P_0c0707fe;
case 0x0c070800u: goto P_0c070800;
case 0x0c070802u: goto P_0c070802;
case 0x0c070804u: goto P_0c070804;
case 0x0c070806u: goto P_0c070806;
case 0x0c070808u: goto P_0c070808;
case 0x0c07080au: goto P_0c07080a;
case 0x0c07080cu: goto P_0c07080c;
case 0x0c07080eu: goto P_0c07080e;
case 0x0c070810u: goto P_0c070810;
case 0x0c070812u: goto P_0c070812;
case 0x0c070814u: goto P_0c070814;
case 0x0c070816u: goto P_0c070816;
case 0x0c070818u: goto P_0c070818;
case 0x0c07081au: goto P_0c07081a;
case 0x0c07081cu: goto P_0c07081c;
case 0x0c07081eu: goto P_0c07081e;
case 0x0c070820u: goto P_0c070820;
case 0x0c070822u: goto P_0c070822;
case 0x0c070824u: goto P_0c070824;
case 0x0c070826u: goto P_0c070826;
case 0x0c070828u: goto P_0c070828;
case 0x0c07082au: goto P_0c07082a;
case 0x0c07082cu: goto P_0c07082c;
case 0x0c07082eu: goto P_0c07082e;
case 0x0c070830u: goto P_0c070830;
case 0x0c070832u: goto P_0c070832;
case 0x0c070834u: goto P_0c070834;
case 0x0c070836u: goto P_0c070836;
case 0x0c070838u: goto P_0c070838;
case 0x0c07083au: goto P_0c07083a;
case 0x0c07083cu: goto P_0c07083c;
case 0x0c07083eu: goto P_0c07083e;
case 0x0c070840u: goto P_0c070840;
case 0x0c070842u: goto P_0c070842;
case 0x0c070844u: goto P_0c070844;
case 0x0c070846u: goto P_0c070846;
case 0x0c070848u: goto P_0c070848;
case 0x0c07084au: goto P_0c07084a;
case 0x0c07084cu: goto P_0c07084c;
case 0x0c07084eu: goto P_0c07084e;
case 0x0c070850u: goto P_0c070850;
case 0x0c070852u: goto P_0c070852;
case 0x0c070854u: goto P_0c070854;
case 0x0c070856u: goto P_0c070856;
case 0x0c070858u: goto P_0c070858;
case 0x0c07085au: goto P_0c07085a;
case 0x0c07085cu: goto P_0c07085c;
case 0x0c07085eu: goto P_0c07085e;
case 0x0c070860u: goto P_0c070860;
case 0x0c070862u: goto P_0c070862;
case 0x0c070864u: goto P_0c070864;
case 0x0c070866u: goto P_0c070866;
case 0x0c070868u: goto P_0c070868;
case 0x0c07086au: goto P_0c07086a;
case 0x0c07086cu: goto P_0c07086c;
case 0x0c07086eu: goto P_0c07086e;
case 0x0c070870u: goto P_0c070870;
case 0x0c070872u: goto P_0c070872;
case 0x0c070874u: goto P_0c070874;
case 0x0c070876u: goto P_0c070876;
case 0x0c070878u: goto P_0c070878;
case 0x0c07087au: goto P_0c07087a;
case 0x0c07087cu: goto P_0c07087c;
case 0x0c07087eu: goto P_0c07087e;
case 0x0c070880u: goto P_0c070880;
case 0x0c070882u: goto P_0c070882;
case 0x0c070884u: goto P_0c070884;
case 0x0c070886u: goto P_0c070886;
case 0x0c070888u: goto P_0c070888;
case 0x0c07088au: goto P_0c07088a;
case 0x0c07088cu: goto P_0c07088c;
case 0x0c07088eu: goto P_0c07088e;
case 0x0c070890u: goto P_0c070890;
case 0x0c070892u: goto P_0c070892;
case 0x0c070898u: goto P_0c070898;
case 0x0c07089au: goto P_0c07089a;
case 0x0c07089cu: goto P_0c07089c;
case 0x0c07089eu: goto P_0c07089e;
case 0x0c0708a0u: goto P_0c0708a0;
case 0x0c0708a2u: goto P_0c0708a2;
case 0x0c0708a4u: goto P_0c0708a4;
case 0x0c0708a6u: goto P_0c0708a6;
case 0x0c0708a8u: goto P_0c0708a8;
case 0x0c0708aau: goto P_0c0708aa;
case 0x0c0708acu: goto P_0c0708ac;
case 0x0c0708aeu: goto P_0c0708ae;
case 0x0c0708b0u: goto P_0c0708b0;
case 0x0c0708b2u: goto P_0c0708b2;
case 0x0c0708b4u: goto P_0c0708b4;
case 0x0c0708b6u: goto P_0c0708b6;
case 0x0c0708b8u: goto P_0c0708b8;
case 0x0c0708bau: goto P_0c0708ba;
case 0x0c0708bcu: goto P_0c0708bc;
case 0x0c0708beu: goto P_0c0708be;
case 0x0c0708c0u: goto P_0c0708c0;
case 0x0c0708c2u: goto P_0c0708c2;
case 0x0c0708c4u: goto P_0c0708c4;
case 0x0c0708c6u: goto P_0c0708c6;
case 0x0c0708c8u: goto P_0c0708c8;
case 0x0c0708cau: goto P_0c0708ca;
case 0x0c0708ccu: goto P_0c0708cc;
case 0x0c0708ceu: goto P_0c0708ce;
case 0x0c0708d0u: goto P_0c0708d0;
case 0x0c0708d2u: goto P_0c0708d2;
case 0x0c0708d4u: goto P_0c0708d4;
case 0x0c0708d6u: goto P_0c0708d6;
case 0x0c0708d8u: goto P_0c0708d8;
case 0x0c0708dau: goto P_0c0708da;
case 0x0c0708dcu: goto P_0c0708dc;
case 0x0c0708deu: goto P_0c0708de;
case 0x0c0708e0u: goto P_0c0708e0;
case 0x0c0708e8u: goto P_0c0708e8;
case 0x0c0708eau: goto P_0c0708ea;
case 0x0c0708ecu: goto P_0c0708ec;
case 0x0c0708eeu: goto P_0c0708ee;
case 0x0c0708f0u: goto P_0c0708f0;
case 0x0c0708f2u: goto P_0c0708f2;
case 0x0c0708f4u: goto P_0c0708f4;
case 0x0c0708f6u: goto P_0c0708f6;
case 0x0c0708f8u: goto P_0c0708f8;
case 0x0c0708fau: goto P_0c0708fa;
case 0x0c0708fcu: goto P_0c0708fc;
case 0x0c0708feu: goto P_0c0708fe;
case 0x0c070900u: goto P_0c070900;
case 0x0c070902u: goto P_0c070902;
case 0x0c070904u: goto P_0c070904;
case 0x0c070906u: goto P_0c070906;
case 0x0c070908u: goto P_0c070908;
case 0x0c07090au: goto P_0c07090a;
case 0x0c07090cu: goto P_0c07090c;
case 0x0c07090eu: goto P_0c07090e;
case 0x0c070910u: goto P_0c070910;
case 0x0c070912u: goto P_0c070912;
case 0x0c070914u: goto P_0c070914;
case 0x0c070916u: goto P_0c070916;
case 0x0c070918u: goto P_0c070918;
case 0x0c07091au: goto P_0c07091a;
case 0x0c07091cu: goto P_0c07091c;
case 0x0c07091eu: goto P_0c07091e;
case 0x0c070920u: goto P_0c070920;
case 0x0c070922u: goto P_0c070922;
case 0x0c070924u: goto P_0c070924;
case 0x0c070926u: goto P_0c070926;
case 0x0c070928u: goto P_0c070928;
case 0x0c07092au: goto P_0c07092a;
case 0x0c07092cu: goto P_0c07092c;
case 0x0c070934u: goto P_0c070934;
case 0x0c070936u: goto P_0c070936;
case 0x0c070938u: goto P_0c070938;
case 0x0c07093au: goto P_0c07093a;
case 0x0c07093cu: goto P_0c07093c;
case 0x0c07093eu: goto P_0c07093e;
case 0x0c070940u: goto P_0c070940;
case 0x0c070942u: goto P_0c070942;
case 0x0c070944u: goto P_0c070944;
case 0x0c070946u: goto P_0c070946;
case 0x0c070948u: goto P_0c070948;
case 0x0c07094au: goto P_0c07094a;
case 0x0c07094cu: goto P_0c07094c;
case 0x0c07094eu: goto P_0c07094e;
case 0x0c070950u: goto P_0c070950;
case 0x0c070952u: goto P_0c070952;
case 0x0c070954u: goto P_0c070954;
case 0x0c070956u: goto P_0c070956;
case 0x0c070958u: goto P_0c070958;
case 0x0c07095au: goto P_0c07095a;
case 0x0c07095cu: goto P_0c07095c;
case 0x0c07095eu: goto P_0c07095e;
case 0x0c070960u: goto P_0c070960;
case 0x0c070962u: goto P_0c070962;
case 0x0c070964u: goto P_0c070964;
case 0x0c070966u: goto P_0c070966;
case 0x0c070968u: goto P_0c070968;
case 0x0c07096au: goto P_0c07096a;
case 0x0c07096cu: goto P_0c07096c;
case 0x0c07096eu: goto P_0c07096e;
case 0x0c070970u: goto P_0c070970;
case 0x0c07097cu: goto P_0c07097c;
case 0x0c07097eu: goto P_0c07097e;
case 0x0c070980u: goto P_0c070980;
case 0x0c070982u: goto P_0c070982;
case 0x0c070984u: goto P_0c070984;
case 0x0c070986u: goto P_0c070986;
case 0x0c070988u: goto P_0c070988;
case 0x0c07098au: goto P_0c07098a;
case 0x0c07098cu: goto P_0c07098c;
case 0x0c07098eu: goto P_0c07098e;
case 0x0c070990u: goto P_0c070990;
case 0x0c070992u: goto P_0c070992;
case 0x0c070994u: goto P_0c070994;
case 0x0c070996u: goto P_0c070996;
case 0x0c070998u: goto P_0c070998;
case 0x0c07099au: goto P_0c07099a;
case 0x0c07099cu: goto P_0c07099c;
case 0x0c07099eu: goto P_0c07099e;
case 0x0c0709a0u: goto P_0c0709a0;
case 0x0c0709a2u: goto P_0c0709a2;
case 0x0c0709a4u: goto P_0c0709a4;
case 0x0c0709a6u: goto P_0c0709a6;
case 0x0c0709a8u: goto P_0c0709a8;
case 0x0c0709aau: goto P_0c0709aa;
case 0x0c0709acu: goto P_0c0709ac;
case 0x0c0709aeu: goto P_0c0709ae;
case 0x0c0709b0u: goto P_0c0709b0;
case 0x0c0709bcu: goto P_0c0709bc;
case 0x0c0709beu: goto P_0c0709be;
case 0x0c0709c0u: goto P_0c0709c0;
case 0x0c0709c2u: goto P_0c0709c2;
case 0x0c0709c4u: goto P_0c0709c4;
case 0x0c0709c6u: goto P_0c0709c6;
case 0x0c0709c8u: goto P_0c0709c8;
case 0x0c0709cau: goto P_0c0709ca;
case 0x0c0709ccu: goto P_0c0709cc;
case 0x0c0709ceu: goto P_0c0709ce;
case 0x0c0709d0u: goto P_0c0709d0;
case 0x0c0709d2u: goto P_0c0709d2;
case 0x0c0709d4u: goto P_0c0709d4;
case 0x0c0709d6u: goto P_0c0709d6;
case 0x0c0709d8u: goto P_0c0709d8;
case 0x0c0709dau: goto P_0c0709da;
case 0x0c0709dcu: goto P_0c0709dc;
case 0x0c0709deu: goto P_0c0709de;
case 0x0c0709e0u: goto P_0c0709e0;
case 0x0c0709e2u: goto P_0c0709e2;
case 0x0c0709e4u: goto P_0c0709e4;
case 0x0c0709e6u: goto P_0c0709e6;
case 0x0c0709e8u: goto P_0c0709e8;
case 0x0c0709eau: goto P_0c0709ea;
case 0x0c0709ecu: goto P_0c0709ec;
case 0x0c0709eeu: goto P_0c0709ee;
case 0x0c0709f0u: goto P_0c0709f0;
case 0x0c0709f2u: goto P_0c0709f2;
case 0x0c0709f4u: goto P_0c0709f4;
case 0x0c0709f6u: goto P_0c0709f6;
case 0x0c0709f8u: goto P_0c0709f8;
case 0x0c0709fau: goto P_0c0709fa;
case 0x0c0709fcu: goto P_0c0709fc;
case 0x0c0709feu: goto P_0c0709fe;
case 0x0c070a00u: goto P_0c070a00;
case 0x0c070a02u: goto P_0c070a02;
case 0x0c070a04u: goto P_0c070a04;
case 0x0c070a06u: goto P_0c070a06;
case 0x0c070a08u: goto P_0c070a08;
case 0x0c070a0au: goto P_0c070a0a;
case 0x0c070a0cu: goto P_0c070a0c;
case 0x0c070a0eu: goto P_0c070a0e;
case 0x0c070a10u: goto P_0c070a10;
case 0x0c070a12u: goto P_0c070a12;
case 0x0c070a14u: goto P_0c070a14;
case 0x0c070a16u: goto P_0c070a16;
case 0x0c070a18u: goto P_0c070a18;
case 0x0c070a1au: goto P_0c070a1a;
case 0x0c070a1cu: goto P_0c070a1c;
case 0x0c070a1eu: goto P_0c070a1e;
case 0x0c070a20u: goto P_0c070a20;
case 0x0c070a22u: goto P_0c070a22;
case 0x0c070a24u: goto P_0c070a24;
case 0x0c070a26u: goto P_0c070a26;
case 0x0c070a28u: goto P_0c070a28;
case 0x0c070a2au: goto P_0c070a2a;
case 0x0c070a2cu: goto P_0c070a2c;
case 0x0c070a2eu: goto P_0c070a2e;
case 0x0c070a30u: goto P_0c070a30;
case 0x0c070a32u: goto P_0c070a32;
case 0x0c070a34u: goto P_0c070a34;
case 0x0c070a36u: goto P_0c070a36;
case 0x0c070a38u: goto P_0c070a38;
case 0x0c070a3au: goto P_0c070a3a;
case 0x0c070a3cu: goto P_0c070a3c;
case 0x0c070a3eu: goto P_0c070a3e;
case 0x0c070a40u: goto P_0c070a40;
case 0x0c070a42u: goto P_0c070a42;
case 0x0c070a44u: goto P_0c070a44;
case 0x0c070a46u: goto P_0c070a46;
case 0x0c070a48u: goto P_0c070a48;
case 0x0c070a4au: goto P_0c070a4a;
case 0x0c070a4cu: goto P_0c070a4c;
case 0x0c070a4eu: goto P_0c070a4e;
case 0x0c070a50u: goto P_0c070a50;
case 0x0c070a52u: goto P_0c070a52;
case 0x0c070a54u: goto P_0c070a54;
case 0x0c070a56u: goto P_0c070a56;
case 0x0c070a58u: goto P_0c070a58;
case 0x0c070a5au: goto P_0c070a5a;
case 0x0c070a5cu: goto P_0c070a5c;
case 0x0c070a5eu: goto P_0c070a5e;
case 0x0c070a60u: goto P_0c070a60;
case 0x0c070a62u: goto P_0c070a62;
case 0x0c070a64u: goto P_0c070a64;
case 0x0c070a66u: goto P_0c070a66;
case 0x0c070a68u: goto P_0c070a68;
case 0x0c070a6au: goto P_0c070a6a;
case 0x0c070a6cu: goto P_0c070a6c;
case 0x0c070a6eu: goto P_0c070a6e;
case 0x0c070a70u: goto P_0c070a70;
case 0x0c070a72u: goto P_0c070a72;
case 0x0c070a74u: goto P_0c070a74;
case 0x0c070a76u: goto P_0c070a76;
case 0x0c070a78u: goto P_0c070a78;
case 0x0c070a7au: goto P_0c070a7a;
case 0x0c070a7cu: goto P_0c070a7c;
case 0x0c070a7eu: goto P_0c070a7e;
case 0x0c070a80u: goto P_0c070a80;
case 0x0c070a82u: goto P_0c070a82;
case 0x0c070a84u: goto P_0c070a84;
case 0x0c070a86u: goto P_0c070a86;
case 0x0c070a88u: goto P_0c070a88;
case 0x0c070a8au: goto P_0c070a8a;
case 0x0c070a8cu: goto P_0c070a8c;
case 0x0c070a8eu: goto P_0c070a8e;
case 0x0c070a90u: goto P_0c070a90;
case 0x0c070a92u: goto P_0c070a92;
case 0x0c070a94u: goto P_0c070a94;
case 0x0c070a96u: goto P_0c070a96;
case 0x0c070a98u: goto P_0c070a98;
case 0x0c070a9au: goto P_0c070a9a;
case 0x0c070a9cu: goto P_0c070a9c;
case 0x0c070a9eu: goto P_0c070a9e;
case 0x0c070aa0u: goto P_0c070aa0;
case 0x0c070aa2u: goto P_0c070aa2;
case 0x0c070aa4u: goto P_0c070aa4;
case 0x0c070aa6u: goto P_0c070aa6;
case 0x0c070aa8u: goto P_0c070aa8;
case 0x0c070aaau: goto P_0c070aaa;
case 0x0c070aacu: goto P_0c070aac;
case 0x0c070aaeu: goto P_0c070aae;
case 0x0c070ab0u: goto P_0c070ab0;
case 0x0c070ab2u: goto P_0c070ab2;
case 0x0c070ab4u: goto P_0c070ab4;
case 0x0c070abcu: goto P_0c070abc;
case 0x0c070abeu: goto P_0c070abe;
case 0x0c070ac0u: goto P_0c070ac0;
case 0x0c070ac2u: goto P_0c070ac2;
case 0x0c070ac4u: goto P_0c070ac4;
case 0x0c070ac6u: goto P_0c070ac6;
case 0x0c070ac8u: goto P_0c070ac8;
case 0x0c070acau: goto P_0c070aca;
case 0x0c070accu: goto P_0c070acc;
case 0x0c070aceu: goto P_0c070ace;
case 0x0c070ad0u: goto P_0c070ad0;
case 0x0c070ad2u: goto P_0c070ad2;
case 0x0c070ad4u: goto P_0c070ad4;
case 0x0c070ad6u: goto P_0c070ad6;
case 0x0c070ad8u: goto P_0c070ad8;
case 0x0c070adau: goto P_0c070ada;
case 0x0c070adcu: goto P_0c070adc;
case 0x0c070adeu: goto P_0c070ade;
case 0x0c070ae0u: goto P_0c070ae0;
case 0x0c070ae2u: goto P_0c070ae2;
case 0x0c070ae4u: goto P_0c070ae4;
case 0x0c070ae6u: goto P_0c070ae6;
case 0x0c070ae8u: goto P_0c070ae8;
case 0x0c070aeau: goto P_0c070aea;
case 0x0c070aecu: goto P_0c070aec;
case 0x0c070aeeu: goto P_0c070aee;
case 0x0c070af0u: goto P_0c070af0;
case 0x0c070af2u: goto P_0c070af2;
case 0x0c070af4u: goto P_0c070af4;
case 0x0c070af6u: goto P_0c070af6;
case 0x0c070af8u: goto P_0c070af8;
case 0x0c070afau: goto P_0c070afa;
case 0x0c070afcu: goto P_0c070afc;
case 0x0c070afeu: goto P_0c070afe;
case 0x0c070b00u: goto P_0c070b00;
case 0x0c070b08u: goto P_0c070b08;
case 0x0c070b0au: goto P_0c070b0a;
case 0x0c070b0cu: goto P_0c070b0c;
case 0x0c070b0eu: goto P_0c070b0e;
case 0x0c070b10u: goto P_0c070b10;
case 0x0c070b12u: goto P_0c070b12;
case 0x0c070b14u: goto P_0c070b14;
case 0x0c070b16u: goto P_0c070b16;
case 0x0c070b18u: goto P_0c070b18;
case 0x0c070b1au: goto P_0c070b1a;
case 0x0c070b1cu: goto P_0c070b1c;
case 0x0c070b1eu: goto P_0c070b1e;
case 0x0c070b20u: goto P_0c070b20;
case 0x0c070b22u: goto P_0c070b22;
case 0x0c070b24u: goto P_0c070b24;
case 0x0c070b26u: goto P_0c070b26;
case 0x0c070b28u: goto P_0c070b28;
case 0x0c070b2au: goto P_0c070b2a;
case 0x0c070b2cu: goto P_0c070b2c;
case 0x0c070b2eu: goto P_0c070b2e;
case 0x0c070b30u: goto P_0c070b30;
case 0x0c070b32u: goto P_0c070b32;
case 0x0c070b34u: goto P_0c070b34;
case 0x0c070b36u: goto P_0c070b36;
case 0x0c070b38u: goto P_0c070b38;
case 0x0c070b3au: goto P_0c070b3a;
case 0x0c070b3cu: goto P_0c070b3c;
case 0x0c070b3eu: goto P_0c070b3e;
case 0x0c070b40u: goto P_0c070b40;
case 0x0c070b42u: goto P_0c070b42;
case 0x0c070b44u: goto P_0c070b44;
case 0x0c070b50u: goto P_0c070b50;
case 0x0c070b52u: goto P_0c070b52;
case 0x0c070b54u: goto P_0c070b54;
case 0x0c070b56u: goto P_0c070b56;
case 0x0c070b58u: goto P_0c070b58;
case 0x0c070b5au: goto P_0c070b5a;
case 0x0c070b5cu: goto P_0c070b5c;
case 0x0c070b5eu: goto P_0c070b5e;
case 0x0c070b60u: goto P_0c070b60;
case 0x0c070b62u: goto P_0c070b62;
case 0x0c070b64u: goto P_0c070b64;
case 0x0c070b66u: goto P_0c070b66;
case 0x0c070b68u: goto P_0c070b68;
case 0x0c070b6au: goto P_0c070b6a;
case 0x0c070b6cu: goto P_0c070b6c;
case 0x0c070b6eu: goto P_0c070b6e;
case 0x0c070b70u: goto P_0c070b70;
case 0x0c070b72u: goto P_0c070b72;
case 0x0c070b74u: goto P_0c070b74;
case 0x0c070b76u: goto P_0c070b76;
case 0x0c070b78u: goto P_0c070b78;
case 0x0c070b7au: goto P_0c070b7a;
case 0x0c070b7cu: goto P_0c070b7c;
case 0x0c070b7eu: goto P_0c070b7e;
case 0x0c070b80u: goto P_0c070b80;
case 0x0c070b82u: goto P_0c070b82;
case 0x0c070b84u: goto P_0c070b84;
case 0x0c070b90u: goto P_0c070b90;
case 0x0c070b92u: goto P_0c070b92;
case 0x0c070b94u: goto P_0c070b94;
case 0x0c070b96u: goto P_0c070b96;
case 0x0c070b98u: goto P_0c070b98;
case 0x0c070b9au: goto P_0c070b9a;
case 0x0c070b9cu: goto P_0c070b9c;
case 0x0c070b9eu: goto P_0c070b9e;
case 0x0c070ba0u: goto P_0c070ba0;
case 0x0c070ba2u: goto P_0c070ba2;
case 0x0c070ba4u: goto P_0c070ba4;
case 0x0c070ba6u: goto P_0c070ba6;
case 0x0c070ba8u: goto P_0c070ba8;
case 0x0c070baau: goto P_0c070baa;
case 0x0c070bacu: goto P_0c070bac;
case 0x0c070baeu: goto P_0c070bae;
case 0x0c070bb0u: goto P_0c070bb0;
case 0x0c070bb2u: goto P_0c070bb2;
case 0x0c070bb4u: goto P_0c070bb4;
case 0x0c070bb6u: goto P_0c070bb6;
case 0x0c070bb8u: goto P_0c070bb8;
case 0x0c070bbau: goto P_0c070bba;
case 0x0c070bbcu: goto P_0c070bbc;
case 0x0c070bbeu: goto P_0c070bbe;
case 0x0c070bc0u: goto P_0c070bc0;
case 0x0c070bc2u: goto P_0c070bc2;
case 0x0c070bc4u: goto P_0c070bc4;
case 0x0c070bc6u: goto P_0c070bc6;
case 0x0c070bc8u: goto P_0c070bc8;
case 0x0c070bcau: goto P_0c070bca;
case 0x0c070bccu: goto P_0c070bcc;
case 0x0c070bceu: goto P_0c070bce;
case 0x0c070bd0u: goto P_0c070bd0;
case 0x0c070bd2u: goto P_0c070bd2;
case 0x0c070bd4u: goto P_0c070bd4;
case 0x0c070bd6u: goto P_0c070bd6;
case 0x0c070bd8u: goto P_0c070bd8;
case 0x0c070bdau: goto P_0c070bda;
case 0x0c070bdcu: goto P_0c070bdc;
case 0x0c070bdeu: goto P_0c070bde;
case 0x0c070be0u: goto P_0c070be0;
case 0x0c070be2u: goto P_0c070be2;
case 0x0c070be4u: goto P_0c070be4;
case 0x0c070be6u: goto P_0c070be6;
case 0x0c070be8u: goto P_0c070be8;
case 0x0c070beau: goto P_0c070bea;
case 0x0c070becu: goto P_0c070bec;
case 0x0c070beeu: goto P_0c070bee;
case 0x0c070bf0u: goto P_0c070bf0;
case 0x0c070bf2u: goto P_0c070bf2;
case 0x0c070bf4u: goto P_0c070bf4;
case 0x0c070bf6u: goto P_0c070bf6;
case 0x0c070bf8u: goto P_0c070bf8;
case 0x0c070bfau: goto P_0c070bfa;
case 0x0c070bfcu: goto P_0c070bfc;
case 0x0c070bfeu: goto P_0c070bfe;
case 0x0c070c00u: goto P_0c070c00;
case 0x0c070c02u: goto P_0c070c02;
case 0x0c070c04u: goto P_0c070c04;
case 0x0c070c06u: goto P_0c070c06;
case 0x0c070c08u: goto P_0c070c08;
case 0x0c070c0au: goto P_0c070c0a;
case 0x0c070c0cu: goto P_0c070c0c;
case 0x0c070c0eu: goto P_0c070c0e;
case 0x0c070c10u: goto P_0c070c10;
case 0x0c070c12u: goto P_0c070c12;
case 0x0c070c14u: goto P_0c070c14;
case 0x0c070c16u: goto P_0c070c16;
case 0x0c070c18u: goto P_0c070c18;
case 0x0c070c1au: goto P_0c070c1a;
case 0x0c070c1cu: goto P_0c070c1c;
case 0x0c070c1eu: goto P_0c070c1e;
case 0x0c070c20u: goto P_0c070c20;
case 0x0c070c22u: goto P_0c070c22;
case 0x0c070c24u: goto P_0c070c24;
case 0x0c070c26u: goto P_0c070c26;
case 0x0c070c28u: goto P_0c070c28;
case 0x0c070c2au: goto P_0c070c2a;
case 0x0c070c2cu: goto P_0c070c2c;
case 0x0c070c2eu: goto P_0c070c2e;
case 0x0c070c30u: goto P_0c070c30;
case 0x0c070c32u: goto P_0c070c32;
case 0x0c070c34u: goto P_0c070c34;
case 0x0c070c36u: goto P_0c070c36;
case 0x0c070c38u: goto P_0c070c38;
case 0x0c070c3au: goto P_0c070c3a;
case 0x0c070c3cu: goto P_0c070c3c;
case 0x0c070c3eu: goto P_0c070c3e;
case 0x0c070c40u: goto P_0c070c40;
case 0x0c070c42u: goto P_0c070c42;
case 0x0c070c44u: goto P_0c070c44;
case 0x0c070c46u: goto P_0c070c46;
case 0x0c070c48u: goto P_0c070c48;
case 0x0c070c4au: goto P_0c070c4a;
case 0x0c070c4cu: goto P_0c070c4c;
case 0x0c070c4eu: goto P_0c070c4e;
case 0x0c070c50u: goto P_0c070c50;
case 0x0c070c52u: goto P_0c070c52;
case 0x0c070c54u: goto P_0c070c54;
case 0x0c070c56u: goto P_0c070c56;
case 0x0c070c58u: goto P_0c070c58;
case 0x0c070c5au: goto P_0c070c5a;
case 0x0c070c5cu: goto P_0c070c5c;
case 0x0c070c5eu: goto P_0c070c5e;
case 0x0c070c60u: goto P_0c070c60;
case 0x0c070c62u: goto P_0c070c62;
case 0x0c070c64u: goto P_0c070c64;
case 0x0c070c66u: goto P_0c070c66;
case 0x0c070c68u: goto P_0c070c68;
case 0x0c070c6au: goto P_0c070c6a;
case 0x0c070c6cu: goto P_0c070c6c;
case 0x0c070c6eu: goto P_0c070c6e;
case 0x0c070c70u: goto P_0c070c70;
case 0x0c070c72u: goto P_0c070c72;
case 0x0c070c74u: goto P_0c070c74;
case 0x0c070c76u: goto P_0c070c76;
case 0x0c070c78u: goto P_0c070c78;
case 0x0c070c7au: goto P_0c070c7a;
case 0x0c070c7cu: goto P_0c070c7c;
case 0x0c070c7eu: goto P_0c070c7e;
case 0x0c070c80u: goto P_0c070c80;
case 0x0c070c82u: goto P_0c070c82;
case 0x0c070c84u: goto P_0c070c84;
case 0x0c070c86u: goto P_0c070c86;
case 0x0c070c88u: goto P_0c070c88;
case 0x0c070c90u: goto P_0c070c90;
case 0x0c070c92u: goto P_0c070c92;
case 0x0c070c94u: goto P_0c070c94;
case 0x0c070c96u: goto P_0c070c96;
case 0x0c070c98u: goto P_0c070c98;
case 0x0c070c9au: goto P_0c070c9a;
case 0x0c070c9cu: goto P_0c070c9c;
case 0x0c070c9eu: goto P_0c070c9e;
case 0x0c070ca0u: goto P_0c070ca0;
case 0x0c070ca2u: goto P_0c070ca2;
case 0x0c070ca4u: goto P_0c070ca4;
case 0x0c070ca6u: goto P_0c070ca6;
case 0x0c070ca8u: goto P_0c070ca8;
case 0x0c070caau: goto P_0c070caa;
case 0x0c070cacu: goto P_0c070cac;
case 0x0c070caeu: goto P_0c070cae;
case 0x0c070cb0u: goto P_0c070cb0;
case 0x0c070cb2u: goto P_0c070cb2;
case 0x0c070cb4u: goto P_0c070cb4;
case 0x0c070cb6u: goto P_0c070cb6;
case 0x0c070cb8u: goto P_0c070cb8;
case 0x0c070cbau: goto P_0c070cba;
case 0x0c070cbcu: goto P_0c070cbc;
case 0x0c070cbeu: goto P_0c070cbe;
case 0x0c070cc0u: goto P_0c070cc0;
case 0x0c070cc2u: goto P_0c070cc2;
case 0x0c070cc4u: goto P_0c070cc4;
case 0x0c070cc6u: goto P_0c070cc6;
case 0x0c070cc8u: goto P_0c070cc8;
case 0x0c070ccau: goto P_0c070cca;
case 0x0c070cccu: goto P_0c070ccc;
case 0x0c070cceu: goto P_0c070cce;
case 0x0c070cd0u: goto P_0c070cd0;
case 0x0c070cd2u: goto P_0c070cd2;
case 0x0c070cd4u: goto P_0c070cd4;
case 0x0c070cd6u: goto P_0c070cd6;
case 0x0c070cd8u: goto P_0c070cd8;
case 0x0c070cdau: goto P_0c070cda;
case 0x0c070cdcu: goto P_0c070cdc;
case 0x0c070cdeu: goto P_0c070cde;
case 0x0c070ce0u: goto P_0c070ce0;
case 0x0c070ce2u: goto P_0c070ce2;
case 0x0c070ce4u: goto P_0c070ce4;
case 0x0c070ce6u: goto P_0c070ce6;
case 0x0c070ce8u: goto P_0c070ce8;
case 0x0c070ceau: goto P_0c070cea;
case 0x0c070cecu: goto P_0c070cec;
case 0x0c070ceeu: goto P_0c070cee;
case 0x0c070cf0u: goto P_0c070cf0;
case 0x0c070cf2u: goto P_0c070cf2;
case 0x0c070cf4u: goto P_0c070cf4;
case 0x0c070cf6u: goto P_0c070cf6;
case 0x0c070cf8u: goto P_0c070cf8;
case 0x0c070cfau: goto P_0c070cfa;
case 0x0c070cfcu: goto P_0c070cfc;
case 0x0c070cfeu: goto P_0c070cfe;
case 0x0c070d00u: goto P_0c070d00;
case 0x0c070d02u: goto P_0c070d02;
case 0x0c070d04u: goto P_0c070d04;
case 0x0c070d06u: goto P_0c070d06;
case 0x0c070d08u: goto P_0c070d08;
case 0x0c070d0au: goto P_0c070d0a;
case 0x0c070d0cu: goto P_0c070d0c;
case 0x0c070d0eu: goto P_0c070d0e;
case 0x0c070d10u: goto P_0c070d10;
case 0x0c070d12u: goto P_0c070d12;
case 0x0c070d14u: goto P_0c070d14;
case 0x0c070d16u: goto P_0c070d16;
case 0x0c070d18u: goto P_0c070d18;
case 0x0c070d1au: goto P_0c070d1a;
case 0x0c070d1cu: goto P_0c070d1c;
case 0x0c070d1eu: goto P_0c070d1e;
case 0x0c070d24u: goto P_0c070d24;
case 0x0c070d26u: goto P_0c070d26;
case 0x0c070d28u: goto P_0c070d28;
case 0x0c070d2au: goto P_0c070d2a;
case 0x0c070d2cu: goto P_0c070d2c;
case 0x0c070d2eu: goto P_0c070d2e;
case 0x0c070d30u: goto P_0c070d30;
case 0x0c070d32u: goto P_0c070d32;
case 0x0c070d34u: goto P_0c070d34;
case 0x0c070d36u: goto P_0c070d36;
case 0x0c070d38u: goto P_0c070d38;
case 0x0c070d3au: goto P_0c070d3a;
case 0x0c070d3cu: goto P_0c070d3c;
case 0x0c070d3eu: goto P_0c070d3e;
case 0x0c070d40u: goto P_0c070d40;
case 0x0c070d42u: goto P_0c070d42;
case 0x0c070d44u: goto P_0c070d44;
case 0x0c070d46u: goto P_0c070d46;
case 0x0c070d48u: goto P_0c070d48;
case 0x0c070d4au: goto P_0c070d4a;
case 0x0c070d4cu: goto P_0c070d4c;
case 0x0c070d4eu: goto P_0c070d4e;
case 0x0c070d50u: goto P_0c070d50;
case 0x0c070d52u: goto P_0c070d52;
case 0x0c070d54u: goto P_0c070d54;
case 0x0c070d56u: goto P_0c070d56;
case 0x0c070d58u: goto P_0c070d58;
case 0x0c070d5au: goto P_0c070d5a;
case 0x0c070d5cu: goto P_0c070d5c;
case 0x0c070d5eu: goto P_0c070d5e;
case 0x0c070d60u: goto P_0c070d60;
case 0x0c070d62u: goto P_0c070d62;
case 0x0c070d64u: goto P_0c070d64;
case 0x0c070d66u: goto P_0c070d66;
case 0x0c070d68u: goto P_0c070d68;
case 0x0c070d6au: goto P_0c070d6a;
case 0x0c070d70u: goto P_0c070d70;
case 0x0c070d72u: goto P_0c070d72;
case 0x0c070d74u: goto P_0c070d74;
case 0x0c070d76u: goto P_0c070d76;
case 0x0c070d78u: goto P_0c070d78;
case 0x0c070d7au: goto P_0c070d7a;
case 0x0c070d7cu: goto P_0c070d7c;
case 0x0c070d7eu: goto P_0c070d7e;
case 0x0c070d80u: goto P_0c070d80;
case 0x0c070d82u: goto P_0c070d82;
case 0x0c070d84u: goto P_0c070d84;
case 0x0c070d86u: goto P_0c070d86;
case 0x0c070d88u: goto P_0c070d88;
case 0x0c070d8au: goto P_0c070d8a;
case 0x0c070d8cu: goto P_0c070d8c;
case 0x0c070d8eu: goto P_0c070d8e;
case 0x0c070d90u: goto P_0c070d90;
case 0x0c070d92u: goto P_0c070d92;
case 0x0c070d94u: goto P_0c070d94;
case 0x0c070d96u: goto P_0c070d96;
case 0x0c070d98u: goto P_0c070d98;
case 0x0c070d9au: goto P_0c070d9a;
case 0x0c070d9cu: goto P_0c070d9c;
case 0x0c070d9eu: goto P_0c070d9e;
case 0x0c070da0u: goto P_0c070da0;
case 0x0c070da2u: goto P_0c070da2;
case 0x0c070da4u: goto P_0c070da4;
case 0x0c070da6u: goto P_0c070da6;
case 0x0c070da8u: goto P_0c070da8;
case 0x0c070db4u: goto P_0c070db4;
case 0x0c070db6u: goto P_0c070db6;
case 0x0c070db8u: goto P_0c070db8;
case 0x0c070dbau: goto P_0c070dba;
case 0x0c070dbcu: goto P_0c070dbc;
case 0x0c070dbeu: goto P_0c070dbe;
case 0x0c070dc0u: goto P_0c070dc0;
case 0x0c070dc2u: goto P_0c070dc2;
case 0x0c070dc4u: goto P_0c070dc4;
case 0x0c070dc6u: goto P_0c070dc6;
case 0x0c070dc8u: goto P_0c070dc8;
case 0x0c070dcau: goto P_0c070dca;
case 0x0c070dccu: goto P_0c070dcc;
case 0x0c070dceu: goto P_0c070dce;
case 0x0c070dd0u: goto P_0c070dd0;
case 0x0c070dd2u: goto P_0c070dd2;
case 0x0c070dd4u: goto P_0c070dd4;
case 0x0c070dd6u: goto P_0c070dd6;
case 0x0c070dd8u: goto P_0c070dd8;
case 0x0c070ddau: goto P_0c070dda;
case 0x0c070ddcu: goto P_0c070ddc;
case 0x0c070ddeu: goto P_0c070dde;
case 0x0c070de0u: goto P_0c070de0;
case 0x0c070de2u: goto P_0c070de2;
case 0x0c070de4u: goto P_0c070de4;
case 0x0c070de6u: goto P_0c070de6;
case 0x0c070de8u: goto P_0c070de8;
case 0x0c070df4u: goto P_0c070df4;
case 0x0c070df6u: goto P_0c070df6;
case 0x0c070df8u: goto P_0c070df8;
case 0x0c070dfau: goto P_0c070dfa;
case 0x0c070dfcu: goto P_0c070dfc;
case 0x0c070dfeu: goto P_0c070dfe;
case 0x0c070e00u: goto P_0c070e00;
case 0x0c070e02u: goto P_0c070e02;
case 0x0c070e04u: goto P_0c070e04;
case 0x0c070e06u: goto P_0c070e06;
case 0x0c070e08u: goto P_0c070e08;
case 0x0c070e0au: goto P_0c070e0a;
case 0x0c070e0cu: goto P_0c070e0c;
case 0x0c070e0eu: goto P_0c070e0e;
case 0x0c070e10u: goto P_0c070e10;
case 0x0c070e12u: goto P_0c070e12;
case 0x0c070e14u: goto P_0c070e14;
case 0x0c070e16u: goto P_0c070e16;
case 0x0c070e18u: goto P_0c070e18;
case 0x0c070e1au: goto P_0c070e1a;
case 0x0c070e1cu: goto P_0c070e1c;
case 0x0c070e1eu: goto P_0c070e1e;
case 0x0c070e20u: goto P_0c070e20;
case 0x0c070e22u: goto P_0c070e22;
case 0x0c070e24u: goto P_0c070e24;
case 0x0c070e26u: goto P_0c070e26;
case 0x0c070e28u: goto P_0c070e28;
case 0x0c070e2au: goto P_0c070e2a;
case 0x0c070e2cu: goto P_0c070e2c;
case 0x0c070e2eu: goto P_0c070e2e;
case 0x0c070e30u: goto P_0c070e30;
case 0x0c070e32u: goto P_0c070e32;
case 0x0c070e34u: goto P_0c070e34;
case 0x0c070e36u: goto P_0c070e36;
case 0x0c070e38u: goto P_0c070e38;
case 0x0c070e3au: goto P_0c070e3a;
case 0x0c070e3cu: goto P_0c070e3c;
case 0x0c070e3eu: goto P_0c070e3e;
case 0x0c070e40u: goto P_0c070e40;
case 0x0c070e42u: goto P_0c070e42;
case 0x0c070e44u: goto P_0c070e44;
case 0x0c070e46u: goto P_0c070e46;
case 0x0c070e48u: goto P_0c070e48;
case 0x0c070e4au: goto P_0c070e4a;
case 0x0c070e4cu: goto P_0c070e4c;
case 0x0c070e4eu: goto P_0c070e4e;
case 0x0c070e50u: goto P_0c070e50;
case 0x0c070e52u: goto P_0c070e52;
case 0x0c070e54u: goto P_0c070e54;
case 0x0c070e56u: goto P_0c070e56;
case 0x0c070e58u: goto P_0c070e58;
case 0x0c070e5au: goto P_0c070e5a;
case 0x0c070e5cu: goto P_0c070e5c;
case 0x0c070e5eu: goto P_0c070e5e;
case 0x0c070e60u: goto P_0c070e60;
case 0x0c070e62u: goto P_0c070e62;
case 0x0c070e64u: goto P_0c070e64;
case 0x0c070e66u: goto P_0c070e66;
case 0x0c070e68u: goto P_0c070e68;
case 0x0c070e6au: goto P_0c070e6a;
case 0x0c070e6cu: goto P_0c070e6c;
case 0x0c070e6eu: goto P_0c070e6e;
case 0x0c070e70u: goto P_0c070e70;
case 0x0c070e72u: goto P_0c070e72;
case 0x0c070e74u: goto P_0c070e74;
case 0x0c070e76u: goto P_0c070e76;
case 0x0c070e78u: goto P_0c070e78;
case 0x0c070e7au: goto P_0c070e7a;
case 0x0c070e7cu: goto P_0c070e7c;
case 0x0c070e7eu: goto P_0c070e7e;
case 0x0c070e80u: goto P_0c070e80;
case 0x0c070e82u: goto P_0c070e82;
case 0x0c070e84u: goto P_0c070e84;
case 0x0c070e86u: goto P_0c070e86;
case 0x0c070e88u: goto P_0c070e88;
case 0x0c070e8au: goto P_0c070e8a;
case 0x0c070e8cu: goto P_0c070e8c;
case 0x0c070e8eu: goto P_0c070e8e;
case 0x0c070e90u: goto P_0c070e90;
case 0x0c070e92u: goto P_0c070e92;
case 0x0c070e94u: goto P_0c070e94;
case 0x0c070e96u: goto P_0c070e96;
case 0x0c070e98u: goto P_0c070e98;
case 0x0c070e9au: goto P_0c070e9a;
case 0x0c070e9cu: goto P_0c070e9c;
case 0x0c070e9eu: goto P_0c070e9e;
case 0x0c070ea0u: goto P_0c070ea0;
case 0x0c070ea2u: goto P_0c070ea2;
case 0x0c070ea4u: goto P_0c070ea4;
case 0x0c070ea6u: goto P_0c070ea6;
case 0x0c070ea8u: goto P_0c070ea8;
case 0x0c070eaau: goto P_0c070eaa;
case 0x0c070eacu: goto P_0c070eac;
case 0x0c070eaeu: goto P_0c070eae;
case 0x0c070eb0u: goto P_0c070eb0;
case 0x0c070eb2u: goto P_0c070eb2;
case 0x0c070eb4u: goto P_0c070eb4;
case 0x0c070eb6u: goto P_0c070eb6;
case 0x0c070eb8u: goto P_0c070eb8;
case 0x0c070ebau: goto P_0c070eba;
case 0x0c070ebcu: goto P_0c070ebc;
case 0x0c070ebeu: goto P_0c070ebe;
case 0x0c070ec0u: goto P_0c070ec0;
case 0x0c070ec2u: goto P_0c070ec2;
case 0x0c070ec4u: goto P_0c070ec4;
case 0x0c070ec6u: goto P_0c070ec6;
case 0x0c070ec8u: goto P_0c070ec8;
case 0x0c070ecau: goto P_0c070eca;
case 0x0c070eccu: goto P_0c070ecc;
case 0x0c070eceu: goto P_0c070ece;
case 0x0c070ed0u: goto P_0c070ed0;
case 0x0c070ed2u: goto P_0c070ed2;
case 0x0c070ed4u: goto P_0c070ed4;
case 0x0c070ed6u: goto P_0c070ed6;
case 0x0c070ed8u: goto P_0c070ed8;
case 0x0c070edau: goto P_0c070eda;
case 0x0c070edcu: goto P_0c070edc;
case 0x0c070edeu: goto P_0c070ede;
case 0x0c070ee0u: goto P_0c070ee0;
case 0x0c070ee2u: goto P_0c070ee2;
case 0x0c070ee4u: goto P_0c070ee4;
case 0x0c070ee6u: goto P_0c070ee6;
case 0x0c070ee8u: goto P_0c070ee8;
case 0x0c070eeau: goto P_0c070eea;
case 0x0c070eecu: goto P_0c070eec;
case 0x0c070eeeu: goto P_0c070eee;
case 0x0c070ef4u: goto P_0c070ef4;
case 0x0c070ef6u: goto P_0c070ef6;
case 0x0c070ef8u: goto P_0c070ef8;
case 0x0c070efau: goto P_0c070efa;
case 0x0c070efcu: goto P_0c070efc;
case 0x0c070efeu: goto P_0c070efe;
case 0x0c070f00u: goto P_0c070f00;
case 0x0c070f02u: goto P_0c070f02;
case 0x0c070f04u: goto P_0c070f04;
case 0x0c070f06u: goto P_0c070f06;
case 0x0c070f08u: goto P_0c070f08;
case 0x0c070f0au: goto P_0c070f0a;
case 0x0c070f0cu: goto P_0c070f0c;
case 0x0c070f0eu: goto P_0c070f0e;
case 0x0c070f10u: goto P_0c070f10;
case 0x0c070f12u: goto P_0c070f12;
case 0x0c070f14u: goto P_0c070f14;
case 0x0c070f16u: goto P_0c070f16;
case 0x0c070f18u: goto P_0c070f18;
case 0x0c070f1au: goto P_0c070f1a;
case 0x0c070f1cu: goto P_0c070f1c;
case 0x0c070f1eu: goto P_0c070f1e;
case 0x0c070f20u: goto P_0c070f20;
case 0x0c070f22u: goto P_0c070f22;
case 0x0c070f24u: goto P_0c070f24;
case 0x0c070f26u: goto P_0c070f26;
case 0x0c070f28u: goto P_0c070f28;
case 0x0c070f2au: goto P_0c070f2a;
case 0x0c070f2cu: goto P_0c070f2c;
case 0x0c070f2eu: goto P_0c070f2e;
case 0x0c070f30u: goto P_0c070f30;
case 0x0c070f32u: goto P_0c070f32;
case 0x0c070f34u: goto P_0c070f34;
case 0x0c070f36u: goto P_0c070f36;
case 0x0c070f38u: goto P_0c070f38;
case 0x0c070f3au: goto P_0c070f3a;
case 0x0c070f40u: goto P_0c070f40;
case 0x0c070f42u: goto P_0c070f42;
case 0x0c070f44u: goto P_0c070f44;
case 0x0c070f46u: goto P_0c070f46;
case 0x0c070f48u: goto P_0c070f48;
case 0x0c070f4au: goto P_0c070f4a;
case 0x0c070f4cu: goto P_0c070f4c;
case 0x0c070f4eu: goto P_0c070f4e;
case 0x0c070f50u: goto P_0c070f50;
case 0x0c070f52u: goto P_0c070f52;
case 0x0c070f54u: goto P_0c070f54;
case 0x0c070f56u: goto P_0c070f56;
case 0x0c070f58u: goto P_0c070f58;
case 0x0c070f5au: goto P_0c070f5a;
case 0x0c070f5cu: goto P_0c070f5c;
case 0x0c070f5eu: goto P_0c070f5e;
case 0x0c070f60u: goto P_0c070f60;
case 0x0c070f62u: goto P_0c070f62;
case 0x0c070f64u: goto P_0c070f64;
case 0x0c070f66u: goto P_0c070f66;
case 0x0c070f68u: goto P_0c070f68;
case 0x0c070f6au: goto P_0c070f6a;
case 0x0c070f6cu: goto P_0c070f6c;
case 0x0c070f6eu: goto P_0c070f6e;
case 0x0c070f70u: goto P_0c070f70;
case 0x0c070f72u: goto P_0c070f72;
case 0x0c070f74u: goto P_0c070f74;
case 0x0c070f76u: goto P_0c070f76;
case 0x0c070f78u: goto P_0c070f78;
case 0x0c070f84u: goto P_0c070f84;
case 0x0c070f86u: goto P_0c070f86;
case 0x0c070f88u: goto P_0c070f88;
case 0x0c070f8au: goto P_0c070f8a;
case 0x0c070f8cu: goto P_0c070f8c;
case 0x0c070f8eu: goto P_0c070f8e;
case 0x0c070f90u: goto P_0c070f90;
case 0x0c070f92u: goto P_0c070f92;
case 0x0c070f94u: goto P_0c070f94;
case 0x0c070f96u: goto P_0c070f96;
case 0x0c070f98u: goto P_0c070f98;
case 0x0c070f9au: goto P_0c070f9a;
case 0x0c070f9cu: goto P_0c070f9c;
case 0x0c070f9eu: goto P_0c070f9e;
case 0x0c070fa0u: goto P_0c070fa0;
case 0x0c070fa2u: goto P_0c070fa2;
case 0x0c070fa4u: goto P_0c070fa4;
case 0x0c070fa6u: goto P_0c070fa6;
case 0x0c070fa8u: goto P_0c070fa8;
case 0x0c070faau: goto P_0c070faa;
case 0x0c070facu: goto P_0c070fac;
case 0x0c070faeu: goto P_0c070fae;
case 0x0c070fb0u: goto P_0c070fb0;
case 0x0c070fb2u: goto P_0c070fb2;
case 0x0c070fb4u: goto P_0c070fb4;
case 0x0c070fb6u: goto P_0c070fb6;
case 0x0c070fb8u: goto P_0c070fb8;
case 0x0c070fc4u: goto P_0c070fc4;
case 0x0c070fc6u: goto P_0c070fc6;
case 0x0c070fc8u: goto P_0c070fc8;
case 0x0c070fcau: goto P_0c070fca;
case 0x0c070fccu: goto P_0c070fcc;
case 0x0c070fceu: goto P_0c070fce;
case 0x0c070fd0u: goto P_0c070fd0;
case 0x0c070fd2u: goto P_0c070fd2;
case 0x0c070fd4u: goto P_0c070fd4;
case 0x0c070fd6u: goto P_0c070fd6;
case 0x0c070fd8u: goto P_0c070fd8;
case 0x0c070fdau: goto P_0c070fda;
case 0x0c070fdcu: goto P_0c070fdc;
case 0x0c070fdeu: goto P_0c070fde;
case 0x0c070fe0u: goto P_0c070fe0;
case 0x0c070fe2u: goto P_0c070fe2;
case 0x0c070fe4u: goto P_0c070fe4;
case 0x0c070fe6u: goto P_0c070fe6;
case 0x0c070fe8u: goto P_0c070fe8;
case 0x0c070feau: goto P_0c070fea;
case 0x0c070fecu: goto P_0c070fec;
case 0x0c070feeu: goto P_0c070fee;
case 0x0c070ff0u: goto P_0c070ff0;
case 0x0c070ff2u: goto P_0c070ff2;
case 0x0c070ff4u: goto P_0c070ff4;
case 0x0c070ff6u: goto P_0c070ff6;
case 0x0c070ff8u: goto P_0c070ff8;
case 0x0c070ffau: goto P_0c070ffa;
case 0x0c070ffcu: goto P_0c070ffc;
case 0x0c070ffeu: goto P_0c070ffe;
case 0x0c071000u: goto P_0c071000;
case 0x0c071002u: goto P_0c071002;
case 0x0c071004u: goto P_0c071004;
case 0x0c071006u: goto P_0c071006;
case 0x0c071008u: goto P_0c071008;
case 0x0c07100au: goto P_0c07100a;
case 0x0c07100cu: goto P_0c07100c;
case 0x0c07100eu: goto P_0c07100e;
case 0x0c071010u: goto P_0c071010;
case 0x0c071012u: goto P_0c071012;
case 0x0c071014u: goto P_0c071014;
case 0x0c071016u: goto P_0c071016;
case 0x0c071018u: goto P_0c071018;
case 0x0c07101au: goto P_0c07101a;
case 0x0c07101cu: goto P_0c07101c;
case 0x0c07101eu: goto P_0c07101e;
case 0x0c071020u: goto P_0c071020;
case 0x0c071022u: goto P_0c071022;
case 0x0c071024u: goto P_0c071024;
case 0x0c071026u: goto P_0c071026;
case 0x0c071028u: goto P_0c071028;
case 0x0c07102au: goto P_0c07102a;
case 0x0c07102cu: goto P_0c07102c;
case 0x0c07102eu: goto P_0c07102e;
case 0x0c071030u: goto P_0c071030;
case 0x0c071032u: goto P_0c071032;
case 0x0c071034u: goto P_0c071034;
case 0x0c071036u: goto P_0c071036;
case 0x0c071038u: goto P_0c071038;
case 0x0c07103au: goto P_0c07103a;
case 0x0c07103cu: goto P_0c07103c;
case 0x0c07103eu: goto P_0c07103e;
case 0x0c071040u: goto P_0c071040;
case 0x0c071042u: goto P_0c071042;
case 0x0c071044u: goto P_0c071044;
case 0x0c071046u: goto P_0c071046;
case 0x0c071048u: goto P_0c071048;
case 0x0c07104au: goto P_0c07104a;
case 0x0c07104cu: goto P_0c07104c;
case 0x0c07104eu: goto P_0c07104e;
case 0x0c071050u: goto P_0c071050;
case 0x0c071052u: goto P_0c071052;
case 0x0c071054u: goto P_0c071054;
case 0x0c071056u: goto P_0c071056;
case 0x0c071058u: goto P_0c071058;
case 0x0c07105au: goto P_0c07105a;
case 0x0c07105cu: goto P_0c07105c;
case 0x0c07105eu: goto P_0c07105e;
case 0x0c071060u: goto P_0c071060;
case 0x0c071062u: goto P_0c071062;
case 0x0c071064u: goto P_0c071064;
case 0x0c071066u: goto P_0c071066;
case 0x0c071068u: goto P_0c071068;
case 0x0c07106au: goto P_0c07106a;
case 0x0c07106cu: goto P_0c07106c;
case 0x0c07106eu: goto P_0c07106e;
case 0x0c071070u: goto P_0c071070;
case 0x0c071072u: goto P_0c071072;
case 0x0c071074u: goto P_0c071074;
case 0x0c071076u: goto P_0c071076;
case 0x0c071078u: goto P_0c071078;
case 0x0c07107au: goto P_0c07107a;
case 0x0c07107cu: goto P_0c07107c;
case 0x0c07107eu: goto P_0c07107e;
case 0x0c071080u: goto P_0c071080;
case 0x0c071082u: goto P_0c071082;
case 0x0c071084u: goto P_0c071084;
case 0x0c071086u: goto P_0c071086;
case 0x0c071088u: goto P_0c071088;
case 0x0c07108au: goto P_0c07108a;
case 0x0c07108cu: goto P_0c07108c;
case 0x0c07108eu: goto P_0c07108e;
case 0x0c071090u: goto P_0c071090;
case 0x0c071092u: goto P_0c071092;
case 0x0c071094u: goto P_0c071094;
case 0x0c071096u: goto P_0c071096;
case 0x0c071098u: goto P_0c071098;
case 0x0c07109au: goto P_0c07109a;
case 0x0c07109cu: goto P_0c07109c;
case 0x0c07109eu: goto P_0c07109e;
case 0x0c0710a0u: goto P_0c0710a0;
case 0x0c0710a2u: goto P_0c0710a2;
case 0x0c0710a4u: goto P_0c0710a4;
case 0x0c0710a6u: goto P_0c0710a6;
case 0x0c0710a8u: goto P_0c0710a8;
case 0x0c0710aau: goto P_0c0710aa;
case 0x0c0710acu: goto P_0c0710ac;
case 0x0c0710aeu: goto P_0c0710ae;
case 0x0c0710b0u: goto P_0c0710b0;
case 0x0c0710b2u: goto P_0c0710b2;
case 0x0c0710b4u: goto P_0c0710b4;
case 0x0c0710b6u: goto P_0c0710b6;
case 0x0c0710b8u: goto P_0c0710b8;
case 0x0c0710bau: goto P_0c0710ba;
case 0x0c0710bcu: goto P_0c0710bc;
case 0x0c0710beu: goto P_0c0710be;
case 0x0c0710c0u: goto P_0c0710c0;
case 0x0c0710c8u: goto P_0c0710c8;
case 0x0c0710cau: goto P_0c0710ca;
case 0x0c0710ccu: goto P_0c0710cc;
case 0x0c0710ceu: goto P_0c0710ce;
case 0x0c0710d0u: goto P_0c0710d0;
case 0x0c0710d2u: goto P_0c0710d2;
case 0x0c0710d4u: goto P_0c0710d4;
case 0x0c0710d6u: goto P_0c0710d6;
case 0x0c0710d8u: goto P_0c0710d8;
case 0x0c0710dau: goto P_0c0710da;
case 0x0c0710dcu: goto P_0c0710dc;
case 0x0c0710deu: goto P_0c0710de;
case 0x0c0710e0u: goto P_0c0710e0;
case 0x0c0710e2u: goto P_0c0710e2;
case 0x0c0710e4u: goto P_0c0710e4;
case 0x0c0710e6u: goto P_0c0710e6;
case 0x0c0710e8u: goto P_0c0710e8;
case 0x0c0710eau: goto P_0c0710ea;
case 0x0c0710ecu: goto P_0c0710ec;
case 0x0c0710eeu: goto P_0c0710ee;
case 0x0c0710f0u: goto P_0c0710f0;
case 0x0c0710f2u: goto P_0c0710f2;
case 0x0c0710f4u: goto P_0c0710f4;
case 0x0c0710f6u: goto P_0c0710f6;
case 0x0c0710f8u: goto P_0c0710f8;
case 0x0c0710fau: goto P_0c0710fa;
case 0x0c0710fcu: goto P_0c0710fc;
case 0x0c0710feu: goto P_0c0710fe;
case 0x0c071100u: goto P_0c071100;
case 0x0c071102u: goto P_0c071102;
case 0x0c071104u: goto P_0c071104;
case 0x0c071106u: goto P_0c071106;
case 0x0c071108u: goto P_0c071108;
case 0x0c07110au: goto P_0c07110a;
case 0x0c07110cu: goto P_0c07110c;
case 0x0c07110eu: goto P_0c07110e;
case 0x0c071110u: goto P_0c071110;
case 0x0c071112u: goto P_0c071112;
case 0x0c071114u: goto P_0c071114;
case 0x0c071116u: goto P_0c071116;
case 0x0c071118u: goto P_0c071118;
case 0x0c07111au: goto P_0c07111a;
case 0x0c07111cu: goto P_0c07111c;
case 0x0c07111eu: goto P_0c07111e;
case 0x0c071120u: goto P_0c071120;
case 0x0c071122u: goto P_0c071122;
case 0x0c071124u: goto P_0c071124;
case 0x0c071126u: goto P_0c071126;
case 0x0c071128u: goto P_0c071128;
case 0x0c07112au: goto P_0c07112a;
case 0x0c07112cu: goto P_0c07112c;
case 0x0c07112eu: goto P_0c07112e;
case 0x0c071130u: goto P_0c071130;
case 0x0c071132u: goto P_0c071132;
case 0x0c071134u: goto P_0c071134;
case 0x0c071136u: goto P_0c071136;
case 0x0c071138u: goto P_0c071138;
case 0x0c07113au: goto P_0c07113a;
case 0x0c07113cu: goto P_0c07113c;
case 0x0c07113eu: goto P_0c07113e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c070008: /* original 2fe6, guest PC 0x0c070008 */
if(!s->budget--) { s->failed_pc=0x0c070008u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07000a;
P_0c07000a: /* original e058, guest PC 0x0c07000a */
if(!s->budget--) { s->failed_pc=0x0c07000au; return 0; }
r[0]=0x00000058u;
goto P_0c07000c;
P_0c07000c: /* original 2fd6, guest PC 0x0c07000c */
if(!s->budget--) { s->failed_pc=0x0c07000cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07000e;
P_0c07000e: /* original e300, guest PC 0x0c07000e */
if(!s->budget--) { s->failed_pc=0x0c07000eu; return 0; }
r[3]=0x00000000u;
goto P_0c070010;
P_0c070010: /* original 2fc6, guest PC 0x0c070010 */
if(!s->budget--) { s->failed_pc=0x0c070010u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c070012;
P_0c070012: /* original 2fb6, guest PC 0x0c070012 */
if(!s->budget--) { s->failed_pc=0x0c070012u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c070014;
P_0c070014: /* original 2fa6, guest PC 0x0c070014 */
if(!s->budget--) { s->failed_pc=0x0c070014u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c070016;
P_0c070016: /* original 2f96, guest PC 0x0c070016 */
if(!s->budget--) { s->failed_pc=0x0c070016u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c070018;
P_0c070018: /* original 2f86, guest PC 0x0c070018 */
if(!s->budget--) { s->failed_pc=0x0c070018u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07001a;
P_0c07001a: /* original fffb, guest PC 0x0c07001a */
if(!s->budget--) { s->failed_pc=0x0c07001au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c07001c;
P_0c07001c: /* original ffeb, guest PC 0x0c07001c */
if(!s->budget--) { s->failed_pc=0x0c07001cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c07001e;
P_0c07001e: /* original ffdb, guest PC 0x0c07001e */
if(!s->budget--) { s->failed_pc=0x0c07001eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c070020;
P_0c070020: /* original ffcb, guest PC 0x0c070020 */
if(!s->budget--) { s->failed_pc=0x0c070020u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c070022;
P_0c070022: /* original 4f22, guest PC 0x0c070022 */
if(!s->budget--) { s->failed_pc=0x0c070022u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c070024;
P_0c070024: /* original 7fa4, guest PC 0x0c070024 */
if(!s->budget--) { s->failed_pc=0x0c070024u; return 0; }
r[15]+=0xffffffa4u;
goto P_0c070026;
P_0c070026: /* original 1f3a, guest PC 0x0c070026 */
if(!s->budget--) { s->failed_pc=0x0c070026u; return 0; }
write(ram,r[15]+40,r[3],4);
goto P_0c070028;
P_0c070028: /* original 0e5e, guest PC 0x0c070028 */
if(!s->budget--) { s->failed_pc=0x0c070028u; return 0; }
r[14]=read(ram,r[5]+r[0],4);
goto P_0c07002a;
P_0c07002a: /* original e060, guest PC 0x0c07002a */
if(!s->budget--) { s->failed_pc=0x0c07002au; return 0; }
r[0]=0x00000060u;
goto P_0c07002c;
P_0c07002c: /* original 63e3, guest PC 0x0c07002c */
if(!s->budget--) { s->failed_pc=0x0c07002cu; return 0; }
r[3]=r[14];
goto P_0c07002e;
P_0c07002e: /* original 4321, guest PC 0x0c07002e */
if(!s->budget--) { s->failed_pc=0x0c07002eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c070030;
P_0c070030: /* original 2f32, guest PC 0x0c070030 */
if(!s->budget--) { s->failed_pc=0x0c070030u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c070032;
P_0c070032: /* original 61e3, guest PC 0x0c070032 */
if(!s->budget--) { s->failed_pc=0x0c070032u; return 0; }
r[1]=r[14];
goto P_0c070034;
P_0c070034: /* original fd56, guest PC 0x0c070034 */
if(!s->budget--) { s->failed_pc=0x0c070034u; return 0; }
vf3_matrix_load(s,ram,13,r[5]+r[0]);
goto P_0c070036;
P_0c070036: /* original 7048, guest PC 0x0c070036 */
if(!s->budget--) { s->failed_pc=0x0c070036u; return 0; }
r[0]+=0x00000048u;
goto P_0c070038;
P_0c070038: /* original fe56, guest PC 0x0c070038 */
if(!s->budget--) { s->failed_pc=0x0c070038u; return 0; }
vf3_matrix_load(s,ram,14,r[5]+r[0]);
goto P_0c07003a;
P_0c07003a: /* original 7004, guest PC 0x0c07003a */
if(!s->budget--) { s->failed_pc=0x0c07003au; return 0; }
r[0]+=0x00000004u;
goto P_0c07003c;
P_0c07003c: /* original d311, guest PC 0x0c07003c */
if(!s->budget--) { s->failed_pc=0x0c07003cu; return 0; }
r[3]=read(ram,0x0c070084u,4);
goto P_0c07003e;
P_0c07003e: /* original ff56, guest PC 0x0c07003e */
if(!s->budget--) { s->failed_pc=0x0c07003eu; return 0; }
vf3_matrix_load(s,ram,15,r[5]+r[0]);
goto P_0c070040;
P_0c070040: /* original 430b, guest PC 0x0c070040 */
if(!s->budget--) { s->failed_pc=0x0c070040u; return 0; }
target=r[3];
r[16]=code_base|0x0c070044u;
r[0]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c070044u) { target=s->pc; goto dispatch; }
goto P_0c070044;
P_0c070042: /* original e002, guest PC 0x0c070042 */
if(!s->budget--) { s->failed_pc=0x0c070042u; return 0; }
r[0]=0x00000002u;
goto P_0c070044;
P_0c070044: /* original 2008, guest PC 0x0c070044 */
if(!s->budget--) { s->failed_pc=0x0c070044u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c070046;
P_0c070046: /* original 891f, guest PC 0x0c070046 */
if(!s->budget--) { s->failed_pc=0x0c070046u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070088; }
goto P_0c070048;
P_0c070048: /* original 61f2, guest PC 0x0c070048 */
if(!s->budget--) { s->failed_pc=0x0c070048u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c07004a;
P_0c07004a: /* original 6863, guest PC 0x0c07004a */
if(!s->budget--) { s->failed_pc=0x0c07004au; return 0; }
r[8]=r[6];
goto P_0c07004c;
P_0c07004c: /* original 7101, guest PC 0x0c07004c */
if(!s->budget--) { s->failed_pc=0x0c07004cu; return 0; }
r[1]+=0x00000001u;
goto P_0c07004e;
P_0c07004e: /* original 6313, guest PC 0x0c07004e */
if(!s->budget--) { s->failed_pc=0x0c07004eu; return 0; }
r[3]=r[1];
goto P_0c070050;
P_0c070050: /* original 4100, guest PC 0x0c070050 */
if(!s->budget--) { s->failed_pc=0x0c070050u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c070052;
P_0c070052: /* original 313c, guest PC 0x0c070052 */
if(!s->budget--) { s->failed_pc=0x0c070052u; return 0; }
r[1]+=r[3];
goto P_0c070054;
P_0c070054: /* original 4108, guest PC 0x0c070054 */
if(!s->budget--) { s->failed_pc=0x0c070054u; return 0; }
r[1]<<=2;
goto P_0c070056;
P_0c070056: /* original 4100, guest PC 0x0c070056 */
if(!s->budget--) { s->failed_pc=0x0c070056u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c070058;
P_0c070058: /* original 3818, guest PC 0x0c070058 */
if(!s->budget--) { s->failed_pc=0x0c070058u; return 0; }
r[8]-=r[1];
goto P_0c07005a;
P_0c07005a: /* original 6e83, guest PC 0x0c07005a */
if(!s->budget--) { s->failed_pc=0x0c07005au; return 0; }
r[14]=r[8];
goto P_0c07005c;
P_0c07005c: /* original 1f81, guest PC 0x0c07005c */
if(!s->budget--) { s->failed_pc=0x0c07005cu; return 0; }
write(ram,r[15]+4,r[8],4);
goto P_0c07005e;
P_0c07005e: /* original a028, guest PC 0x0c07005e */
if(!s->budget--) { s->failed_pc=0x0c07005eu; return 0; }
r[13]=r[8];
goto P_0c0700b2;
P_0c070060: /* original 6d83, guest PC 0x0c070060 */
if(!s->budget--) { s->failed_pc=0x0c070060u; return 0; }
r[13]=r[8];
if(!vf3_matrix_family(0x0c070062u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c070062u; return 0; } return 1;
P_0c070088: /* original 62f2, guest PC 0x0c070088 */
if(!s->budget--) { s->failed_pc=0x0c070088u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07008a;
P_0c07008a: /* original 6863, guest PC 0x0c07008a */
if(!s->budget--) { s->failed_pc=0x0c07008au; return 0; }
r[8]=r[6];
goto P_0c07008c;
P_0c07008c: /* original 6323, guest PC 0x0c07008c */
if(!s->budget--) { s->failed_pc=0x0c07008cu; return 0; }
r[3]=r[2];
goto P_0c07008e;
P_0c07008e: /* original 4200, guest PC 0x0c07008e */
if(!s->budget--) { s->failed_pc=0x0c07008eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c070090;
P_0c070090: /* original 323c, guest PC 0x0c070090 */
if(!s->budget--) { s->failed_pc=0x0c070090u; return 0; }
r[2]+=r[3];
goto P_0c070092;
P_0c070092: /* original 63f2, guest PC 0x0c070092 */
if(!s->budget--) { s->failed_pc=0x0c070092u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c070094;
P_0c070094: /* original 4208, guest PC 0x0c070094 */
if(!s->budget--) { s->failed_pc=0x0c070094u; return 0; }
r[2]<<=2;
goto P_0c070096;
P_0c070096: /* original 4200, guest PC 0x0c070096 */
if(!s->budget--) { s->failed_pc=0x0c070096u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c070098;
P_0c070098: /* original 7301, guest PC 0x0c070098 */
if(!s->budget--) { s->failed_pc=0x0c070098u; return 0; }
r[3]+=0x00000001u;
goto P_0c07009a;
P_0c07009a: /* original 3828, guest PC 0x0c07009a */
if(!s->budget--) { s->failed_pc=0x0c07009au; return 0; }
r[8]-=r[2];
goto P_0c07009c;
P_0c07009c: /* original 6233, guest PC 0x0c07009c */
if(!s->budget--) { s->failed_pc=0x0c07009cu; return 0; }
r[2]=r[3];
goto P_0c07009e;
P_0c07009e: /* original 4300, guest PC 0x0c07009e */
if(!s->budget--) { s->failed_pc=0x0c07009eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0700a0;
P_0c0700a0: /* original 6e83, guest PC 0x0c0700a0 */
if(!s->budget--) { s->failed_pc=0x0c0700a0u; return 0; }
r[14]=r[8];
goto P_0c0700a2;
P_0c0700a2: /* original 332c, guest PC 0x0c0700a2 */
if(!s->budget--) { s->failed_pc=0x0c0700a2u; return 0; }
r[3]+=r[2];
goto P_0c0700a4;
P_0c0700a4: /* original 4308, guest PC 0x0c0700a4 */
if(!s->budget--) { s->failed_pc=0x0c0700a4u; return 0; }
r[3]<<=2;
goto P_0c0700a6;
P_0c0700a6: /* original 4300, guest PC 0x0c0700a6 */
if(!s->budget--) { s->failed_pc=0x0c0700a6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0700a8;
P_0c0700a8: /* original 3638, guest PC 0x0c0700a8 */
if(!s->budget--) { s->failed_pc=0x0c0700a8u; return 0; }
r[6]-=r[3];
goto P_0c0700aa;
P_0c0700aa: /* original e301, guest PC 0x0c0700aa */
if(!s->budget--) { s->failed_pc=0x0c0700aau; return 0; }
r[3]=0x00000001u;
goto P_0c0700ac;
P_0c0700ac: /* original 6d63, guest PC 0x0c0700ac */
if(!s->budget--) { s->failed_pc=0x0c0700acu; return 0; }
r[13]=r[6];
goto P_0c0700ae;
P_0c0700ae: /* original 1f61, guest PC 0x0c0700ae */
if(!s->budget--) { s->failed_pc=0x0c0700aeu; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0700b0;
P_0c0700b0: /* original 1f3a, guest PC 0x0c0700b0 */
if(!s->budget--) { s->failed_pc=0x0c0700b0u; return 0; }
write(ram,r[15]+40,r[3],4);
goto P_0c0700b2;
P_0c0700b2: /* original 9924, guest PC 0x0c0700b2 */
if(!s->budget--) { s->failed_pc=0x0c0700b2u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0700feu,2);
goto P_0c0700b4;
P_0c0700b4: /* original 6b53, guest PC 0x0c0700b4 */
if(!s->budget--) { s->failed_pc=0x0c0700b4u; return 0; }
r[11]=r[5];
goto P_0c0700b6;
P_0c0700b6: /* original 9c23, guest PC 0x0c0700b6 */
if(!s->budget--) { s->failed_pc=0x0c0700b6u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c070100u,2);
goto P_0c0700b8;
P_0c0700b8: /* original e304, guest PC 0x0c0700b8 */
if(!s->budget--) { s->failed_pc=0x0c0700b8u; return 0; }
r[3]=0x00000004u;
goto P_0c0700ba;
P_0c0700ba: /* original 9a1f, guest PC 0x0c0700ba */
if(!s->budget--) { s->failed_pc=0x0c0700bau; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0700fcu,2);
goto P_0c0700bc;
P_0c0700bc: /* original 395c, guest PC 0x0c0700bc */
if(!s->budget--) { s->failed_pc=0x0c0700bcu; return 0; }
r[9]+=r[5];
goto P_0c0700be;
P_0c0700be: /* original 3c5c, guest PC 0x0c0700be */
if(!s->budget--) { s->failed_pc=0x0c0700beu; return 0; }
r[12]+=r[5];
goto P_0c0700c0;
P_0c0700c0: /* original 3a5c, guest PC 0x0c0700c0 */
if(!s->budget--) { s->failed_pc=0x0c0700c0u; return 0; }
r[10]+=r[5];
goto P_0c0700c2;
P_0c0700c2: /* original 657f, guest PC 0x0c0700c2 */
if(!s->budget--) { s->failed_pc=0x0c0700c2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[7];
goto P_0c0700c4;
P_0c0700c4: /* original 3537, guest PC 0x0c0700c4 */
if(!s->budget--) { s->failed_pc=0x0c0700c4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[3])!=0);
goto P_0c0700c6;
P_0c0700c6: /* original 8d08, guest PC 0x0c0700c6 */
if(!s->budget--) { s->failed_pc=0x0c0700c6u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000074u;
if(cond) { goto P_0c0700da; }
goto P_0c0700ca;
P_0c0700c8: /* original 7b74, guest PC 0x0c0700c8 */
if(!s->budget--) { s->failed_pc=0x0c0700c8u; return 0; }
r[11]+=0x00000074u;
goto P_0c0700ca;
P_0c0700ca: /* original e061, guest PC 0x0c0700ca */
if(!s->budget--) { s->failed_pc=0x0c0700cau; return 0; }
r[0]=0x00000061u;
goto P_0c0700cc;
P_0c0700cc: /* original 004c, guest PC 0x0c0700cc */
if(!s->budget--) { s->failed_pc=0x0c0700ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0700ce;
P_0c0700ce: /* original 600c, guest PC 0x0c0700ce */
if(!s->budget--) { s->failed_pc=0x0c0700ceu; return 0; }
r[0]=r[0]&255u;
goto P_0c0700d0;
P_0c0700d0: /* original 8804, guest PC 0x0c0700d0 */
if(!s->budget--) { s->failed_pc=0x0c0700d0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0700d2;
P_0c0700d2: /* original 8b02, guest PC 0x0c0700d2 */
if(!s->budget--) { s->failed_pc=0x0c0700d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0700da; }
goto P_0c0700d4;
P_0c0700d4: /* original d20b, guest PC 0x0c0700d4 */
if(!s->budget--) { s->failed_pc=0x0c0700d4u; return 0; }
r[2]=read(ram,0x0c070104u,4);
goto P_0c0700d6;
P_0c0700d6: /* original 422b, guest PC 0x0c0700d6 */
if(!s->budget--) { s->failed_pc=0x0c0700d6u; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0704c0u: goto P_0c0704c0;
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
P_0c0700d8: /* original 0009, guest PC 0x0c0700d8 */
if(!s->budget--) { s->failed_pc=0x0c0700d8u; return 0; }
goto P_0c0700da;
P_0c0700da: /* original e303, guest PC 0x0c0700da */
if(!s->budget--) { s->failed_pc=0x0c0700dau; return 0; }
r[3]=0x00000003u;
goto P_0c0700dc;
P_0c0700dc: /* original 3537, guest PC 0x0c0700dc */
if(!s->budget--) { s->failed_pc=0x0c0700dcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[3])!=0);
goto P_0c0700de;
P_0c0700de: /* original 8907, guest PC 0x0c0700de */
if(!s->budget--) { s->failed_pc=0x0c0700deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0700f0; }
goto P_0c0700e0;
P_0c0700e0: /* original e060, guest PC 0x0c0700e0 */
if(!s->budget--) { s->failed_pc=0x0c0700e0u; return 0; }
r[0]=0x00000060u;
goto P_0c0700e2;
P_0c0700e2: /* original 004c, guest PC 0x0c0700e2 */
if(!s->budget--) { s->failed_pc=0x0c0700e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0700e4;
P_0c0700e4: /* original 600c, guest PC 0x0c0700e4 */
if(!s->budget--) { s->failed_pc=0x0c0700e4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0700e6;
P_0c0700e6: /* original 8808, guest PC 0x0c0700e6 */
if(!s->budget--) { s->failed_pc=0x0c0700e6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0700e8;
P_0c0700e8: /* original 8b02, guest PC 0x0c0700e8 */
if(!s->budget--) { s->failed_pc=0x0c0700e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0700f0; }
goto P_0c0700ea;
P_0c0700ea: /* original d206, guest PC 0x0c0700ea */
if(!s->budget--) { s->failed_pc=0x0c0700eau; return 0; }
r[2]=read(ram,0x0c070104u,4);
goto P_0c0700ec;
P_0c0700ec: /* original 422b, guest PC 0x0c0700ec */
if(!s->budget--) { s->failed_pc=0x0c0700ecu; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0704c0u: goto P_0c0704c0;
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
P_0c0700ee: /* original 0009, guest PC 0x0c0700ee */
if(!s->budget--) { s->failed_pc=0x0c0700eeu; return 0; }
goto P_0c0700f0;
P_0c0700f0: /* original 64f3, guest PC 0x0c0700f0 */
if(!s->budget--) { s->failed_pc=0x0c0700f0u; return 0; }
r[4]=r[15];
goto P_0c0700f2;
P_0c0700f2: /* original 7444, guest PC 0x0c0700f2 */
if(!s->budget--) { s->failed_pc=0x0c0700f2u; return 0; }
r[4]+=0x00000044u;
goto P_0c0700f4;
P_0c0700f4: /* original 66a3, guest PC 0x0c0700f4 */
if(!s->budget--) { s->failed_pc=0x0c0700f4u; return 0; }
r[6]=r[10];
goto P_0c0700f6;
P_0c0700f6: /* original 65e3, guest PC 0x0c0700f6 */
if(!s->budget--) { s->failed_pc=0x0c0700f6u; return 0; }
r[5]=r[14];
goto P_0c0700f8;
P_0c0700f8: /* original a006, guest PC 0x0c0700f8 */
if(!s->budget--) { s->failed_pc=0x0c0700f8u; return 0; }
goto P_0c070108;
P_0c0700fa: /* original 0009, guest PC 0x0c0700fa */
if(!s->budget--) { s->failed_pc=0x0c0700fau; return 0; }
if(!vf3_matrix_family(0x0c0700fcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0700fcu; return 0; } return 1;
P_0c070108: /* original f059, guest PC 0x0c070108 */
if(!s->budget--) { s->failed_pc=0x0c070108u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07010a;
P_0c07010a: /* original f369, guest PC 0x0c07010a */
if(!s->budget--) { s->failed_pc=0x0c07010au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07010c;
P_0c07010c: /* original f159, guest PC 0x0c07010c */
if(!s->budget--) { s->failed_pc=0x0c07010cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07010e;
P_0c07010e: /* original f469, guest PC 0x0c07010e */
if(!s->budget--) { s->failed_pc=0x0c07010eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070110;
P_0c070110: /* original f031, guest PC 0x0c070110 */
if(!s->budget--) { s->failed_pc=0x0c070110u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070112;
P_0c070112: /* original f258, guest PC 0x0c070112 */
if(!s->budget--) { s->failed_pc=0x0c070112u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070114;
P_0c070114: /* original f568, guest PC 0x0c070114 */
if(!s->budget--) { s->failed_pc=0x0c070114u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070116;
P_0c070116: /* original f141, guest PC 0x0c070116 */
if(!s->budget--) { s->failed_pc=0x0c070116u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070118;
P_0c070118: /* original f251, guest PC 0x0c070118 */
if(!s->budget--) { s->failed_pc=0x0c070118u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c07011a;
P_0c07011a: /* original 7408, guest PC 0x0c07011a */
if(!s->budget--) { s->failed_pc=0x0c07011au; return 0; }
r[4]+=0x00000008u;
goto P_0c07011c;
P_0c07011c: /* original f42a, guest PC 0x0c07011c */
if(!s->budget--) { s->failed_pc=0x0c07011cu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07011e;
P_0c07011e: /* original f41b, guest PC 0x0c07011e */
if(!s->budget--) { s->failed_pc=0x0c07011eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070120;
P_0c070120: /* original f40b, guest PC 0x0c070120 */
if(!s->budget--) { s->failed_pc=0x0c070120u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070122;
P_0c070122: /* original 0009, guest PC 0x0c070122 */
if(!s->budget--) { s->failed_pc=0x0c070122u; return 0; }
goto P_0c070124;
P_0c070124: /* original 64f3, guest PC 0x0c070124 */
if(!s->budget--) { s->failed_pc=0x0c070124u; return 0; }
r[4]=r[15];
goto P_0c070126;
P_0c070126: /* original 7444, guest PC 0x0c070126 */
if(!s->budget--) { s->failed_pc=0x0c070126u; return 0; }
r[4]+=0x00000044u;
goto P_0c070128;
P_0c070128: /* original f049, guest PC 0x0c070128 */
if(!s->budget--) { s->failed_pc=0x0c070128u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07012a;
P_0c07012a: /* original f149, guest PC 0x0c07012a */
if(!s->budget--) { s->failed_pc=0x0c07012au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07012c;
P_0c07012c: /* original f249, guest PC 0x0c07012c */
if(!s->budget--) { s->failed_pc=0x0c07012cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07012e;
P_0c07012e: /* original f38d, guest PC 0x0c07012e */
if(!s->budget--) { s->failed_pc=0x0c07012eu; return 0; }
fr[3]=0;
goto P_0c070130;
P_0c070130: /* original f0ed, guest PC 0x0c070130 */
if(!s->budget--) { s->failed_pc=0x0c070130u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070132;
P_0c070132: /* original f03c, guest PC 0x0c070132 */
if(!s->budget--) { s->failed_pc=0x0c070132u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070134;
P_0c070134: /* original f06d, guest PC 0x0c070134 */
if(!s->budget--) { s->failed_pc=0x0c070134u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070136;
P_0c070136: /* original 0009, guest PC 0x0c070136 */
if(!s->budget--) { s->failed_pc=0x0c070136u; return 0; }
goto P_0c070138;
P_0c070138: /* original f38d, guest PC 0x0c070138 */
if(!s->budget--) { s->failed_pc=0x0c070138u; return 0; }
fr[3]=0;
goto P_0c07013a;
P_0c07013a: /* original fc0c, guest PC 0x0c07013a */
if(!s->budget--) { s->failed_pc=0x0c07013au; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c07013c;
P_0c07013c: /* original fc35, guest PC 0x0c07013c */
if(!s->budget--) { s->failed_pc=0x0c07013cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[12])>as_float(fr[3]))!=0);
goto P_0c07013e;
P_0c07013e: /* original 8902, guest PC 0x0c07013e */
if(!s->budget--) { s->failed_pc=0x0c07013eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070146; }
goto P_0c070140;
P_0c070140: /* original d303, guest PC 0x0c070140 */
if(!s->budget--) { s->failed_pc=0x0c070140u; return 0; }
r[3]=read(ram,0x0c070150u,4);
goto P_0c070142;
P_0c070142: /* original 432b, guest PC 0x0c070142 */
if(!s->budget--) { s->failed_pc=0x0c070142u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0702ecu: goto P_0c0702ec;
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
P_0c070144: /* original 0009, guest PC 0x0c070144 */
if(!s->budget--) { s->failed_pc=0x0c070144u; return 0; }
goto P_0c070146;
P_0c070146: /* original 64f3, guest PC 0x0c070146 */
if(!s->budget--) { s->failed_pc=0x0c070146u; return 0; }
r[4]=r[15];
goto P_0c070148;
P_0c070148: /* original 7444, guest PC 0x0c070148 */
if(!s->budget--) { s->failed_pc=0x0c070148u; return 0; }
r[4]+=0x00000044u;
goto P_0c07014a;
P_0c07014a: /* original 65b3, guest PC 0x0c07014a */
if(!s->budget--) { s->failed_pc=0x0c07014au; return 0; }
r[5]=r[11];
goto P_0c07014c;
P_0c07014c: /* original a002, guest PC 0x0c07014c */
if(!s->budget--) { s->failed_pc=0x0c07014cu; return 0; }
goto P_0c070154;
P_0c07014e: /* original 0009, guest PC 0x0c07014e */
if(!s->budget--) { s->failed_pc=0x0c07014eu; return 0; }
if(!vf3_matrix_family(0x0c070150u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c070150u; return 0; } return 1;
P_0c070154: /* original f049, guest PC 0x0c070154 */
if(!s->budget--) { s->failed_pc=0x0c070154u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070156;
P_0c070156: /* original f549, guest PC 0x0c070156 */
if(!s->budget--) { s->failed_pc=0x0c070156u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070158;
P_0c070158: /* original f648, guest PC 0x0c070158 */
if(!s->budget--) { s->failed_pc=0x0c070158u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c07015a;
P_0c07015a: /* original f859, guest PC 0x0c07015a */
if(!s->budget--) { s->failed_pc=0x0c07015au; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07015c;
P_0c07015c: /* original f959, guest PC 0x0c07015c */
if(!s->budget--) { s->failed_pc=0x0c07015cu; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07015e;
P_0c07015e: /* original fa58, guest PC 0x0c07015e */
if(!s->budget--) { s->failed_pc=0x0c07015eu; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c070160;
P_0c070160: /* original f35c, guest PC 0x0c070160 */
if(!s->budget--) { s->failed_pc=0x0c070160u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c070162;
P_0c070162: /* original f382, guest PC 0x0c070162 */
if(!s->budget--) { s->failed_pc=0x0c070162u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c070164;
P_0c070164: /* original f20c, guest PC 0x0c070164 */
if(!s->budget--) { s->failed_pc=0x0c070164u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c070166;
P_0c070166: /* original f2a2, guest PC 0x0c070166 */
if(!s->budget--) { s->failed_pc=0x0c070166u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c070168;
P_0c070168: /* original f16c, guest PC 0x0c070168 */
if(!s->budget--) { s->failed_pc=0x0c070168u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c07016a;
P_0c07016a: /* original f192, guest PC 0x0c07016a */
if(!s->budget--) { s->failed_pc=0x0c07016au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c07016c;
P_0c07016c: /* original f34d, guest PC 0x0c07016c */
if(!s->budget--) { s->failed_pc=0x0c07016cu; return 0; }
fr[3]^=0x80000000u;
goto P_0c07016e;
P_0c07016e: /* original f39e, guest PC 0x0c07016e */
if(!s->budget--) { s->failed_pc=0x0c07016eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c070170;
P_0c070170: /* original f24d, guest PC 0x0c070170 */
if(!s->budget--) { s->failed_pc=0x0c070170u; return 0; }
fr[2]^=0x80000000u;
goto P_0c070172;
P_0c070172: /* original f06c, guest PC 0x0c070172 */
if(!s->budget--) { s->failed_pc=0x0c070172u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c070174;
P_0c070174: /* original f28e, guest PC 0x0c070174 */
if(!s->budget--) { s->failed_pc=0x0c070174u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c070176;
P_0c070176: /* original f14d, guest PC 0x0c070176 */
if(!s->budget--) { s->failed_pc=0x0c070176u; return 0; }
fr[1]^=0x80000000u;
goto P_0c070178;
P_0c070178: /* original f05c, guest PC 0x0c070178 */
if(!s->budget--) { s->failed_pc=0x0c070178u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c07017a;
P_0c07017a: /* original f1ae, guest PC 0x0c07017a */
if(!s->budget--) { s->failed_pc=0x0c07017au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c07017c;
P_0c07017c: /* original f08d, guest PC 0x0c07017c */
if(!s->budget--) { s->failed_pc=0x0c07017cu; return 0; }
fr[0]=0;
goto P_0c07017e;
P_0c07017e: /* original f0ed, guest PC 0x0c07017e */
if(!s->budget--) { s->failed_pc=0x0c07017eu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070180;
P_0c070180: /* original f03c, guest PC 0x0c070180 */
if(!s->budget--) { s->failed_pc=0x0c070180u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070182;
P_0c070182: /* original f06d, guest PC 0x0c070182 */
if(!s->budget--) { s->failed_pc=0x0c070182u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070184;
P_0c070184: /* original ff05, guest PC 0x0c070184 */
if(!s->budget--) { s->failed_pc=0x0c070184u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[0]))!=0);
goto P_0c070186;
P_0c070186: /* original e00c, guest PC 0x0c070186 */
if(!s->budget--) { s->failed_pc=0x0c070186u; return 0; }
r[0]=0x0000000cu;
goto P_0c070188;
P_0c070188: /* original 8d03, guest PC 0x0c070188 */
if(!s->budget--) { s->failed_pc=0x0c070188u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(cond) { goto P_0c070192; }
goto P_0c07018c;
P_0c07018a: /* original ff07, guest PC 0x0c07018a */
if(!s->budget--) { s->failed_pc=0x0c07018au; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c07018c;
P_0c07018c: /* original d303, guest PC 0x0c07018c */
if(!s->budget--) { s->failed_pc=0x0c07018cu; return 0; }
r[3]=read(ram,0x0c07019cu,4);
goto P_0c07018e;
P_0c07018e: /* original 432b, guest PC 0x0c07018e */
if(!s->budget--) { s->failed_pc=0x0c07018eu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0702ecu: goto P_0c0702ec;
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
P_0c070190: /* original 0009, guest PC 0x0c070190 */
if(!s->budget--) { s->failed_pc=0x0c070190u; return 0; }
goto P_0c070192;
P_0c070192: /* original 64f3, guest PC 0x0c070192 */
if(!s->budget--) { s->failed_pc=0x0c070192u; return 0; }
r[4]=r[15];
goto P_0c070194;
P_0c070194: /* original 7444, guest PC 0x0c070194 */
if(!s->budget--) { s->failed_pc=0x0c070194u; return 0; }
r[4]+=0x00000044u;
goto P_0c070196;
P_0c070196: /* original 65b3, guest PC 0x0c070196 */
if(!s->budget--) { s->failed_pc=0x0c070196u; return 0; }
r[5]=r[11];
goto P_0c070198;
P_0c070198: /* original a002, guest PC 0x0c070198 */
if(!s->budget--) { s->failed_pc=0x0c070198u; return 0; }
goto P_0c0701a0;
P_0c07019a: /* original 0009, guest PC 0x0c07019a */
if(!s->budget--) { s->failed_pc=0x0c07019au; return 0; }
if(!vf3_matrix_family(0x0c07019cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07019cu; return 0; } return 1;
P_0c0701a0: /* original f049, guest PC 0x0c0701a0 */
if(!s->budget--) { s->failed_pc=0x0c0701a0u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0701a2;
P_0c0701a2: /* original f149, guest PC 0x0c0701a2 */
if(!s->budget--) { s->failed_pc=0x0c0701a2u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0701a4;
P_0c0701a4: /* original f249, guest PC 0x0c0701a4 */
if(!s->budget--) { s->failed_pc=0x0c0701a4u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0701a6;
P_0c0701a6: /* original f38d, guest PC 0x0c0701a6 */
if(!s->budget--) { s->failed_pc=0x0c0701a6u; return 0; }
fr[3]=0;
goto P_0c0701a8;
P_0c0701a8: /* original f459, guest PC 0x0c0701a8 */
if(!s->budget--) { s->failed_pc=0x0c0701a8u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0701aa;
P_0c0701aa: /* original f559, guest PC 0x0c0701aa */
if(!s->budget--) { s->failed_pc=0x0c0701aau; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0701ac;
P_0c0701ac: /* original f659, guest PC 0x0c0701ac */
if(!s->budget--) { s->failed_pc=0x0c0701acu; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0701ae;
P_0c0701ae: /* original f78d, guest PC 0x0c0701ae */
if(!s->budget--) { s->failed_pc=0x0c0701aeu; return 0; }
fr[7]=0;
goto P_0c0701b0;
P_0c0701b0: /* original f4ed, guest PC 0x0c0701b0 */
if(!s->budget--) { s->failed_pc=0x0c0701b0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c0701b2;
P_0c0701b2: /* original f07c, guest PC 0x0c0701b2 */
if(!s->budget--) { s->failed_pc=0x0c0701b2u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c0701b4;
P_0c0701b4: /* original f38d, guest PC 0x0c0701b4 */
if(!s->budget--) { s->failed_pc=0x0c0701b4u; return 0; }
fr[3]=0;
goto P_0c0701b6;
P_0c0701b6: /* original f40c, guest PC 0x0c0701b6 */
if(!s->budget--) { s->failed_pc=0x0c0701b6u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0701b8;
P_0c0701b8: /* original f345, guest PC 0x0c0701b8 */
if(!s->budget--) { s->failed_pc=0x0c0701b8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0701ba;
P_0c0701ba: /* original 8902, guest PC 0x0c0701ba */
if(!s->budget--) { s->failed_pc=0x0c0701bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0701c2; }
goto P_0c0701bc;
P_0c0701bc: /* original d307, guest PC 0x0c0701bc */
if(!s->budget--) { s->failed_pc=0x0c0701bcu; return 0; }
r[3]=read(ram,0x0c0701dcu,4);
goto P_0c0701be;
P_0c0701be: /* original 432b, guest PC 0x0c0701be */
if(!s->budget--) { s->failed_pc=0x0c0701beu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070226u: goto P_0c070226;
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
P_0c0701c0: /* original 0009, guest PC 0x0c0701c0 */
if(!s->budget--) { s->failed_pc=0x0c0701c0u; return 0; }
goto P_0c0701c2;
P_0c0701c2: /* original ffc5, guest PC 0x0c0701c2 */
if(!s->budget--) { s->failed_pc=0x0c0701c2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[12]))!=0);
goto P_0c0701c4;
P_0c0701c4: /* original 8902, guest PC 0x0c0701c4 */
if(!s->budget--) { s->failed_pc=0x0c0701c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0701cc; }
goto P_0c0701c6;
P_0c0701c6: /* original d206, guest PC 0x0c0701c6 */
if(!s->budget--) { s->failed_pc=0x0c0701c6u; return 0; }
r[2]=read(ram,0x0c0701e0u,4);
goto P_0c0701c8;
P_0c0701c8: /* original 422b, guest PC 0x0c0701c8 */
if(!s->budget--) { s->failed_pc=0x0c0701c8u; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0702ecu: goto P_0c0702ec;
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
P_0c0701ca: /* original 0009, guest PC 0x0c0701ca */
if(!s->budget--) { s->failed_pc=0x0c0701cau; return 0; }
goto P_0c0701cc;
P_0c0701cc: /* original f4cc, guest PC 0x0c0701cc */
if(!s->budget--) { s->failed_pc=0x0c0701ccu; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c0701ce;
P_0c0701ce: /* original f4f1, guest PC 0x0c0701ce */
if(!s->budget--) { s->failed_pc=0x0c0701ceu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
goto P_0c0701d0;
P_0c0701d0: /* original 64f3, guest PC 0x0c0701d0 */
if(!s->budget--) { s->failed_pc=0x0c0701d0u; return 0; }
r[4]=r[15];
goto P_0c0701d2;
P_0c0701d2: /* original 65f3, guest PC 0x0c0701d2 */
if(!s->budget--) { s->failed_pc=0x0c0701d2u; return 0; }
r[5]=r[15];
goto P_0c0701d4;
P_0c0701d4: /* original 7444, guest PC 0x0c0701d4 */
if(!s->budget--) { s->failed_pc=0x0c0701d4u; return 0; }
r[4]+=0x00000044u;
goto P_0c0701d6;
P_0c0701d6: /* original 7544, guest PC 0x0c0701d6 */
if(!s->budget--) { s->failed_pc=0x0c0701d6u; return 0; }
r[5]+=0x00000044u;
goto P_0c0701d8;
P_0c0701d8: /* original a004, guest PC 0x0c0701d8 */
if(!s->budget--) { s->failed_pc=0x0c0701d8u; return 0; }
goto P_0c0701e4;
P_0c0701da: /* original 0009, guest PC 0x0c0701da */
if(!s->budget--) { s->failed_pc=0x0c0701dau; return 0; }
if(!vf3_matrix_family(0x0c0701dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0701dcu; return 0; } return 1;
P_0c0701e4: /* original f059, guest PC 0x0c0701e4 */
if(!s->budget--) { s->failed_pc=0x0c0701e4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0701e6;
P_0c0701e6: /* original f159, guest PC 0x0c0701e6 */
if(!s->budget--) { s->failed_pc=0x0c0701e6u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0701e8;
P_0c0701e8: /* original f259, guest PC 0x0c0701e8 */
if(!s->budget--) { s->failed_pc=0x0c0701e8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0701ea;
P_0c0701ea: /* original f38d, guest PC 0x0c0701ea */
if(!s->budget--) { s->failed_pc=0x0c0701eau; return 0; }
fr[3]=0;
goto P_0c0701ec;
P_0c0701ec: /* original f0ed, guest PC 0x0c0701ec */
if(!s->budget--) { s->failed_pc=0x0c0701ecu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0701ee;
P_0c0701ee: /* original f37d, guest PC 0x0c0701ee */
if(!s->budget--) { s->failed_pc=0x0c0701eeu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0701f0;
P_0c0701f0: /* original f342, guest PC 0x0c0701f0 */
if(!s->budget--) { s->failed_pc=0x0c0701f0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0701f2;
P_0c0701f2: /* original 740c, guest PC 0x0c0701f2 */
if(!s->budget--) { s->failed_pc=0x0c0701f2u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0701f4;
P_0c0701f4: /* original f232, guest PC 0x0c0701f4 */
if(!s->budget--) { s->failed_pc=0x0c0701f4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0701f6;
P_0c0701f6: /* original f132, guest PC 0x0c0701f6 */
if(!s->budget--) { s->failed_pc=0x0c0701f6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0701f8;
P_0c0701f8: /* original f032, guest PC 0x0c0701f8 */
if(!s->budget--) { s->failed_pc=0x0c0701f8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0701fa;
P_0c0701fa: /* original f42b, guest PC 0x0c0701fa */
if(!s->budget--) { s->failed_pc=0x0c0701fau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0701fc;
P_0c0701fc: /* original f41b, guest PC 0x0c0701fc */
if(!s->budget--) { s->failed_pc=0x0c0701fcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0701fe;
P_0c0701fe: /* original f40b, guest PC 0x0c0701fe */
if(!s->budget--) { s->failed_pc=0x0c0701feu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070200;
P_0c070200: /* original 65f3, guest PC 0x0c070200 */
if(!s->budget--) { s->failed_pc=0x0c070200u; return 0; }
r[5]=r[15];
goto P_0c070202;
P_0c070202: /* original 64e3, guest PC 0x0c070202 */
if(!s->budget--) { s->failed_pc=0x0c070202u; return 0; }
r[4]=r[14];
goto P_0c070204;
P_0c070204: /* original 7544, guest PC 0x0c070204 */
if(!s->budget--) { s->failed_pc=0x0c070204u; return 0; }
r[5]+=0x00000044u;
goto P_0c070206;
P_0c070206: /* original f049, guest PC 0x0c070206 */
if(!s->budget--) { s->failed_pc=0x0c070206u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070208;
P_0c070208: /* original f359, guest PC 0x0c070208 */
if(!s->budget--) { s->failed_pc=0x0c070208u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07020a;
P_0c07020a: /* original f149, guest PC 0x0c07020a */
if(!s->budget--) { s->failed_pc=0x0c07020au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07020c;
P_0c07020c: /* original f459, guest PC 0x0c07020c */
if(!s->budget--) { s->failed_pc=0x0c07020cu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07020e;
P_0c07020e: /* original f249, guest PC 0x0c07020e */
if(!s->budget--) { s->failed_pc=0x0c07020eu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070210;
P_0c070210: /* original f559, guest PC 0x0c070210 */
if(!s->budget--) { s->failed_pc=0x0c070210u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070212;
P_0c070212: /* original f030, guest PC 0x0c070212 */
if(!s->budget--) { s->failed_pc=0x0c070212u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070214;
P_0c070214: /* original f250, guest PC 0x0c070214 */
if(!s->budget--) { s->failed_pc=0x0c070214u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070216;
P_0c070216: /* original f140, guest PC 0x0c070216 */
if(!s->budget--) { s->failed_pc=0x0c070216u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070218;
P_0c070218: /* original f42b, guest PC 0x0c070218 */
if(!s->budget--) { s->failed_pc=0x0c070218u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07021a;
P_0c07021a: /* original f41b, guest PC 0x0c07021a */
if(!s->budget--) { s->failed_pc=0x0c07021au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07021c;
P_0c07021c: /* original f40b, guest PC 0x0c07021c */
if(!s->budget--) { s->failed_pc=0x0c07021cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07021e;
P_0c07021e: /* original 0009, guest PC 0x0c07021e */
if(!s->budget--) { s->failed_pc=0x0c07021eu; return 0; }
goto P_0c070220;
P_0c070220: /* original d306, guest PC 0x0c070220 */
if(!s->budget--) { s->failed_pc=0x0c070220u; return 0; }
r[3]=read(ram,0x0c07023cu,4);
goto P_0c070222;
P_0c070222: /* original 432b, guest PC 0x0c070222 */
if(!s->budget--) { s->failed_pc=0x0c070222u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0702ecu: goto P_0c0702ec;
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
P_0c070224: /* original 0009, guest PC 0x0c070224 */
if(!s->budget--) { s->failed_pc=0x0c070224u; return 0; }
goto P_0c070226;
P_0c070226: /* original fe45, guest PC 0x0c070226 */
if(!s->budget--) { s->failed_pc=0x0c070226u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[4]))!=0);
goto P_0c070228;
P_0c070228: /* original 8902, guest PC 0x0c070228 */
if(!s->budget--) { s->failed_pc=0x0c070228u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070230; }
goto P_0c07022a;
P_0c07022a: /* original d204, guest PC 0x0c07022a */
if(!s->budget--) { s->failed_pc=0x0c07022au; return 0; }
r[2]=read(ram,0x0c07023cu,4);
goto P_0c07022c;
P_0c07022c: /* original 422b, guest PC 0x0c07022c */
if(!s->budget--) { s->failed_pc=0x0c07022cu; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0702ecu: goto P_0c0702ec;
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
P_0c07022e: /* original 0009, guest PC 0x0c07022e */
if(!s->budget--) { s->failed_pc=0x0c07022eu; return 0; }
goto P_0c070230;
P_0c070230: /* original 64f3, guest PC 0x0c070230 */
if(!s->budget--) { s->failed_pc=0x0c070230u; return 0; }
r[4]=r[15];
goto P_0c070232;
P_0c070232: /* original 7438, guest PC 0x0c070232 */
if(!s->budget--) { s->failed_pc=0x0c070232u; return 0; }
r[4]+=0x00000038u;
goto P_0c070234;
P_0c070234: /* original 65b3, guest PC 0x0c070234 */
if(!s->budget--) { s->failed_pc=0x0c070234u; return 0; }
r[5]=r[11];
goto P_0c070236;
P_0c070236: /* original a003, guest PC 0x0c070236 */
if(!s->budget--) { s->failed_pc=0x0c070236u; return 0; }
goto P_0c070240;
P_0c070238: /* original 0009, guest PC 0x0c070238 */
if(!s->budget--) { s->failed_pc=0x0c070238u; return 0; }
if(!vf3_matrix_family(0x0c07023au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07023au; return 0; } return 1;
P_0c070240: /* original f059, guest PC 0x0c070240 */
if(!s->budget--) { s->failed_pc=0x0c070240u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070242;
P_0c070242: /* original f159, guest PC 0x0c070242 */
if(!s->budget--) { s->failed_pc=0x0c070242u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070244;
P_0c070244: /* original f259, guest PC 0x0c070244 */
if(!s->budget--) { s->failed_pc=0x0c070244u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070246;
P_0c070246: /* original 740c, guest PC 0x0c070246 */
if(!s->budget--) { s->failed_pc=0x0c070246u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070248;
P_0c070248: /* original f242, guest PC 0x0c070248 */
if(!s->budget--) { s->failed_pc=0x0c070248u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c07024a;
P_0c07024a: /* original f142, guest PC 0x0c07024a */
if(!s->budget--) { s->failed_pc=0x0c07024au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c07024c;
P_0c07024c: /* original f042, guest PC 0x0c07024c */
if(!s->budget--) { s->failed_pc=0x0c07024cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c07024e;
P_0c07024e: /* original f42b, guest PC 0x0c07024e */
if(!s->budget--) { s->failed_pc=0x0c07024eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070250;
P_0c070250: /* original f41b, guest PC 0x0c070250 */
if(!s->budget--) { s->failed_pc=0x0c070250u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070252;
P_0c070252: /* original f40b, guest PC 0x0c070252 */
if(!s->budget--) { s->failed_pc=0x0c070252u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070254;
P_0c070254: /* original 65f3, guest PC 0x0c070254 */
if(!s->budget--) { s->failed_pc=0x0c070254u; return 0; }
r[5]=r[15];
goto P_0c070256;
P_0c070256: /* original 64f3, guest PC 0x0c070256 */
if(!s->budget--) { s->failed_pc=0x0c070256u; return 0; }
r[4]=r[15];
goto P_0c070258;
P_0c070258: /* original 66f3, guest PC 0x0c070258 */
if(!s->budget--) { s->failed_pc=0x0c070258u; return 0; }
r[6]=r[15];
goto P_0c07025a;
P_0c07025a: /* original 7438, guest PC 0x0c07025a */
if(!s->budget--) { s->failed_pc=0x0c07025au; return 0; }
r[4]+=0x00000038u;
goto P_0c07025c;
P_0c07025c: /* original 7638, guest PC 0x0c07025c */
if(!s->budget--) { s->failed_pc=0x0c07025cu; return 0; }
r[6]+=0x00000038u;
goto P_0c07025e;
P_0c07025e: /* original 7544, guest PC 0x0c07025e */
if(!s->budget--) { s->failed_pc=0x0c07025eu; return 0; }
r[5]+=0x00000044u;
goto P_0c070260;
P_0c070260: /* original f059, guest PC 0x0c070260 */
if(!s->budget--) { s->failed_pc=0x0c070260u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070262;
P_0c070262: /* original f369, guest PC 0x0c070262 */
if(!s->budget--) { s->failed_pc=0x0c070262u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070264;
P_0c070264: /* original f159, guest PC 0x0c070264 */
if(!s->budget--) { s->failed_pc=0x0c070264u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070266;
P_0c070266: /* original f469, guest PC 0x0c070266 */
if(!s->budget--) { s->failed_pc=0x0c070266u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070268;
P_0c070268: /* original f031, guest PC 0x0c070268 */
if(!s->budget--) { s->failed_pc=0x0c070268u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c07026a;
P_0c07026a: /* original f258, guest PC 0x0c07026a */
if(!s->budget--) { s->failed_pc=0x0c07026au; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c07026c;
P_0c07026c: /* original f568, guest PC 0x0c07026c */
if(!s->budget--) { s->failed_pc=0x0c07026cu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c07026e;
P_0c07026e: /* original f141, guest PC 0x0c07026e */
if(!s->budget--) { s->failed_pc=0x0c07026eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070270;
P_0c070270: /* original f251, guest PC 0x0c070270 */
if(!s->budget--) { s->failed_pc=0x0c070270u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070272;
P_0c070272: /* original 7408, guest PC 0x0c070272 */
if(!s->budget--) { s->failed_pc=0x0c070272u; return 0; }
r[4]+=0x00000008u;
goto P_0c070274;
P_0c070274: /* original f42a, guest PC 0x0c070274 */
if(!s->budget--) { s->failed_pc=0x0c070274u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070276;
P_0c070276: /* original f41b, guest PC 0x0c070276 */
if(!s->budget--) { s->failed_pc=0x0c070276u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070278;
P_0c070278: /* original f40b, guest PC 0x0c070278 */
if(!s->budget--) { s->failed_pc=0x0c070278u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07027a;
P_0c07027a: /* original 0009, guest PC 0x0c07027a */
if(!s->budget--) { s->failed_pc=0x0c07027au; return 0; }
goto P_0c07027c;
P_0c07027c: /* original e00c, guest PC 0x0c07027c */
if(!s->budget--) { s->failed_pc=0x0c07027cu; return 0; }
r[0]=0x0000000cu;
goto P_0c07027e;
P_0c07027e: /* original f4fc, guest PC 0x0c07027e */
if(!s->budget--) { s->failed_pc=0x0c07027eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070280;
P_0c070280: /* original f3f6, guest PC 0x0c070280 */
if(!s->budget--) { s->failed_pc=0x0c070280u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c070282;
P_0c070282: /* original 64f3, guest PC 0x0c070282 */
if(!s->budget--) { s->failed_pc=0x0c070282u; return 0; }
r[4]=r[15];
goto P_0c070284;
P_0c070284: /* original 65f3, guest PC 0x0c070284 */
if(!s->budget--) { s->failed_pc=0x0c070284u; return 0; }
r[5]=r[15];
goto P_0c070286;
P_0c070286: /* original 7438, guest PC 0x0c070286 */
if(!s->budget--) { s->failed_pc=0x0c070286u; return 0; }
r[4]+=0x00000038u;
goto P_0c070288;
P_0c070288: /* original f431, guest PC 0x0c070288 */
if(!s->budget--) { s->failed_pc=0x0c070288u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c07028a;
P_0c07028a: /* original 7538, guest PC 0x0c07028a */
if(!s->budget--) { s->failed_pc=0x0c07028au; return 0; }
r[5]+=0x00000038u;
goto P_0c07028c;
P_0c07028c: /* original f059, guest PC 0x0c07028c */
if(!s->budget--) { s->failed_pc=0x0c07028cu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07028e;
P_0c07028e: /* original f159, guest PC 0x0c07028e */
if(!s->budget--) { s->failed_pc=0x0c07028eu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070290;
P_0c070290: /* original f259, guest PC 0x0c070290 */
if(!s->budget--) { s->failed_pc=0x0c070290u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070292;
P_0c070292: /* original f38d, guest PC 0x0c070292 */
if(!s->budget--) { s->failed_pc=0x0c070292u; return 0; }
fr[3]=0;
goto P_0c070294;
P_0c070294: /* original f0ed, guest PC 0x0c070294 */
if(!s->budget--) { s->failed_pc=0x0c070294u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070296;
P_0c070296: /* original f37d, guest PC 0x0c070296 */
if(!s->budget--) { s->failed_pc=0x0c070296u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070298;
P_0c070298: /* original f342, guest PC 0x0c070298 */
if(!s->budget--) { s->failed_pc=0x0c070298u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c07029a;
P_0c07029a: /* original 740c, guest PC 0x0c07029a */
if(!s->budget--) { s->failed_pc=0x0c07029au; return 0; }
r[4]+=0x0000000cu;
goto P_0c07029c;
P_0c07029c: /* original f232, guest PC 0x0c07029c */
if(!s->budget--) { s->failed_pc=0x0c07029cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07029e;
P_0c07029e: /* original f132, guest PC 0x0c07029e */
if(!s->budget--) { s->failed_pc=0x0c07029eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0702a0;
P_0c0702a0: /* original f032, guest PC 0x0c0702a0 */
if(!s->budget--) { s->failed_pc=0x0c0702a0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0702a2;
P_0c0702a2: /* original f42b, guest PC 0x0c0702a2 */
if(!s->budget--) { s->failed_pc=0x0c0702a2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0702a4;
P_0c0702a4: /* original f41b, guest PC 0x0c0702a4 */
if(!s->budget--) { s->failed_pc=0x0c0702a4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0702a6;
P_0c0702a6: /* original f40b, guest PC 0x0c0702a6 */
if(!s->budget--) { s->failed_pc=0x0c0702a6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0702a8;
P_0c0702a8: /* original 64f3, guest PC 0x0c0702a8 */
if(!s->budget--) { s->failed_pc=0x0c0702a8u; return 0; }
r[4]=r[15];
goto P_0c0702aa;
P_0c0702aa: /* original 65f3, guest PC 0x0c0702aa */
if(!s->budget--) { s->failed_pc=0x0c0702aau; return 0; }
r[5]=r[15];
goto P_0c0702ac;
P_0c0702ac: /* original 7444, guest PC 0x0c0702ac */
if(!s->budget--) { s->failed_pc=0x0c0702acu; return 0; }
r[4]+=0x00000044u;
goto P_0c0702ae;
P_0c0702ae: /* original 7538, guest PC 0x0c0702ae */
if(!s->budget--) { s->failed_pc=0x0c0702aeu; return 0; }
r[5]+=0x00000038u;
goto P_0c0702b0;
P_0c0702b0: /* original f049, guest PC 0x0c0702b0 */
if(!s->budget--) { s->failed_pc=0x0c0702b0u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0702b2;
P_0c0702b2: /* original f359, guest PC 0x0c0702b2 */
if(!s->budget--) { s->failed_pc=0x0c0702b2u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702b4;
P_0c0702b4: /* original f149, guest PC 0x0c0702b4 */
if(!s->budget--) { s->failed_pc=0x0c0702b4u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0702b6;
P_0c0702b6: /* original f459, guest PC 0x0c0702b6 */
if(!s->budget--) { s->failed_pc=0x0c0702b6u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702b8;
P_0c0702b8: /* original f249, guest PC 0x0c0702b8 */
if(!s->budget--) { s->failed_pc=0x0c0702b8u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0702ba;
P_0c0702ba: /* original f559, guest PC 0x0c0702ba */
if(!s->budget--) { s->failed_pc=0x0c0702bau; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702bc;
P_0c0702bc: /* original f030, guest PC 0x0c0702bc */
if(!s->budget--) { s->failed_pc=0x0c0702bcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c0702be;
P_0c0702be: /* original f250, guest PC 0x0c0702be */
if(!s->budget--) { s->failed_pc=0x0c0702beu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c0702c0;
P_0c0702c0: /* original f140, guest PC 0x0c0702c0 */
if(!s->budget--) { s->failed_pc=0x0c0702c0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c0702c2;
P_0c0702c2: /* original f42b, guest PC 0x0c0702c2 */
if(!s->budget--) { s->failed_pc=0x0c0702c2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0702c4;
P_0c0702c4: /* original f41b, guest PC 0x0c0702c4 */
if(!s->budget--) { s->failed_pc=0x0c0702c4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0702c6;
P_0c0702c6: /* original f40b, guest PC 0x0c0702c6 */
if(!s->budget--) { s->failed_pc=0x0c0702c6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0702c8;
P_0c0702c8: /* original 65f3, guest PC 0x0c0702c8 */
if(!s->budget--) { s->failed_pc=0x0c0702c8u; return 0; }
r[5]=r[15];
goto P_0c0702ca;
P_0c0702ca: /* original 64e3, guest PC 0x0c0702ca */
if(!s->budget--) { s->failed_pc=0x0c0702cau; return 0; }
r[4]=r[14];
goto P_0c0702cc;
P_0c0702cc: /* original 7544, guest PC 0x0c0702cc */
if(!s->budget--) { s->failed_pc=0x0c0702ccu; return 0; }
r[5]+=0x00000044u;
goto P_0c0702ce;
P_0c0702ce: /* original 66a3, guest PC 0x0c0702ce */
if(!s->budget--) { s->failed_pc=0x0c0702ceu; return 0; }
r[6]=r[10];
goto P_0c0702d0;
P_0c0702d0: /* original f059, guest PC 0x0c0702d0 */
if(!s->budget--) { s->failed_pc=0x0c0702d0u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702d2;
P_0c0702d2: /* original f369, guest PC 0x0c0702d2 */
if(!s->budget--) { s->failed_pc=0x0c0702d2u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0702d4;
P_0c0702d4: /* original f159, guest PC 0x0c0702d4 */
if(!s->budget--) { s->failed_pc=0x0c0702d4u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702d6;
P_0c0702d6: /* original f469, guest PC 0x0c0702d6 */
if(!s->budget--) { s->failed_pc=0x0c0702d6u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0702d8;
P_0c0702d8: /* original f259, guest PC 0x0c0702d8 */
if(!s->budget--) { s->failed_pc=0x0c0702d8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702da;
P_0c0702da: /* original f569, guest PC 0x0c0702da */
if(!s->budget--) { s->failed_pc=0x0c0702dau; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0702dc;
P_0c0702dc: /* original 740c, guest PC 0x0c0702dc */
if(!s->budget--) { s->failed_pc=0x0c0702dcu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0702de;
P_0c0702de: /* original f030, guest PC 0x0c0702de */
if(!s->budget--) { s->failed_pc=0x0c0702deu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c0702e0;
P_0c0702e0: /* original f250, guest PC 0x0c0702e0 */
if(!s->budget--) { s->failed_pc=0x0c0702e0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c0702e2;
P_0c0702e2: /* original f140, guest PC 0x0c0702e2 */
if(!s->budget--) { s->failed_pc=0x0c0702e2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c0702e4;
P_0c0702e4: /* original f42b, guest PC 0x0c0702e4 */
if(!s->budget--) { s->failed_pc=0x0c0702e4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0702e6;
P_0c0702e6: /* original f41b, guest PC 0x0c0702e6 */
if(!s->budget--) { s->failed_pc=0x0c0702e6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0702e8;
P_0c0702e8: /* original f40b, guest PC 0x0c0702e8 */
if(!s->budget--) { s->failed_pc=0x0c0702e8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0702ea;
P_0c0702ea: /* original 0009, guest PC 0x0c0702ea */
if(!s->budget--) { s->failed_pc=0x0c0702eau; return 0; }
goto P_0c0702ec;
P_0c0702ec: /* original 64f3, guest PC 0x0c0702ec */
if(!s->budget--) { s->failed_pc=0x0c0702ecu; return 0; }
r[4]=r[15];
goto P_0c0702ee;
P_0c0702ee: /* original 7444, guest PC 0x0c0702ee */
if(!s->budget--) { s->failed_pc=0x0c0702eeu; return 0; }
r[4]+=0x00000044u;
goto P_0c0702f0;
P_0c0702f0: /* original 6693, guest PC 0x0c0702f0 */
if(!s->budget--) { s->failed_pc=0x0c0702f0u; return 0; }
r[6]=r[9];
goto P_0c0702f2;
P_0c0702f2: /* original 65e3, guest PC 0x0c0702f2 */
if(!s->budget--) { s->failed_pc=0x0c0702f2u; return 0; }
r[5]=r[14];
goto P_0c0702f4;
P_0c0702f4: /* original f059, guest PC 0x0c0702f4 */
if(!s->budget--) { s->failed_pc=0x0c0702f4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702f6;
P_0c0702f6: /* original f369, guest PC 0x0c0702f6 */
if(!s->budget--) { s->failed_pc=0x0c0702f6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0702f8;
P_0c0702f8: /* original f159, guest PC 0x0c0702f8 */
if(!s->budget--) { s->failed_pc=0x0c0702f8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702fa;
P_0c0702fa: /* original f469, guest PC 0x0c0702fa */
if(!s->budget--) { s->failed_pc=0x0c0702fau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0702fc;
P_0c0702fc: /* original f031, guest PC 0x0c0702fc */
if(!s->budget--) { s->failed_pc=0x0c0702fcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0702fe;
P_0c0702fe: /* original f258, guest PC 0x0c0702fe */
if(!s->budget--) { s->failed_pc=0x0c0702feu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070300;
P_0c070300: /* original f568, guest PC 0x0c070300 */
if(!s->budget--) { s->failed_pc=0x0c070300u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070302;
P_0c070302: /* original f141, guest PC 0x0c070302 */
if(!s->budget--) { s->failed_pc=0x0c070302u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070304;
P_0c070304: /* original f251, guest PC 0x0c070304 */
if(!s->budget--) { s->failed_pc=0x0c070304u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070306;
P_0c070306: /* original 7408, guest PC 0x0c070306 */
if(!s->budget--) { s->failed_pc=0x0c070306u; return 0; }
r[4]+=0x00000008u;
goto P_0c070308;
P_0c070308: /* original f42a, guest PC 0x0c070308 */
if(!s->budget--) { s->failed_pc=0x0c070308u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07030a;
P_0c07030a: /* original f41b, guest PC 0x0c07030a */
if(!s->budget--) { s->failed_pc=0x0c07030au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07030c;
P_0c07030c: /* original f40b, guest PC 0x0c07030c */
if(!s->budget--) { s->failed_pc=0x0c07030cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07030e;
P_0c07030e: /* original 0009, guest PC 0x0c07030e */
if(!s->budget--) { s->failed_pc=0x0c07030eu; return 0; }
goto P_0c070310;
P_0c070310: /* original 64f3, guest PC 0x0c070310 */
if(!s->budget--) { s->failed_pc=0x0c070310u; return 0; }
r[4]=r[15];
goto P_0c070312;
P_0c070312: /* original 7444, guest PC 0x0c070312 */
if(!s->budget--) { s->failed_pc=0x0c070312u; return 0; }
r[4]+=0x00000044u;
goto P_0c070314;
P_0c070314: /* original f049, guest PC 0x0c070314 */
if(!s->budget--) { s->failed_pc=0x0c070314u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070316;
P_0c070316: /* original f149, guest PC 0x0c070316 */
if(!s->budget--) { s->failed_pc=0x0c070316u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070318;
P_0c070318: /* original f249, guest PC 0x0c070318 */
if(!s->budget--) { s->failed_pc=0x0c070318u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07031a;
P_0c07031a: /* original f38d, guest PC 0x0c07031a */
if(!s->budget--) { s->failed_pc=0x0c07031au; return 0; }
fr[3]=0;
goto P_0c07031c;
P_0c07031c: /* original f0ed, guest PC 0x0c07031c */
if(!s->budget--) { s->failed_pc=0x0c07031cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07031e;
P_0c07031e: /* original f03c, guest PC 0x0c07031e */
if(!s->budget--) { s->failed_pc=0x0c07031eu; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070320;
P_0c070320: /* original f06d, guest PC 0x0c070320 */
if(!s->budget--) { s->failed_pc=0x0c070320u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070322;
P_0c070322: /* original 0009, guest PC 0x0c070322 */
if(!s->budget--) { s->failed_pc=0x0c070322u; return 0; }
goto P_0c070324;
P_0c070324: /* original f38d, guest PC 0x0c070324 */
if(!s->budget--) { s->failed_pc=0x0c070324u; return 0; }
fr[3]=0;
goto P_0c070326;
P_0c070326: /* original f035, guest PC 0x0c070326 */
if(!s->budget--) { s->failed_pc=0x0c070326u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c070328;
P_0c070328: /* original e014, guest PC 0x0c070328 */
if(!s->budget--) { s->failed_pc=0x0c070328u; return 0; }
r[0]=0x00000014u;
goto P_0c07032a;
P_0c07032a: /* original 8d03, guest PC 0x0c07032a */
if(!s->budget--) { s->failed_pc=0x0c07032au; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(cond) { goto P_0c070334; }
goto P_0c07032e;
P_0c07032c: /* original ff07, guest PC 0x0c07032c */
if(!s->budget--) { s->failed_pc=0x0c07032cu; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c07032e;
P_0c07032e: /* original d304, guest PC 0x0c07032e */
if(!s->budget--) { s->failed_pc=0x0c07032eu; return 0; }
r[3]=read(ram,0x0c070340u,4);
goto P_0c070330;
P_0c070330: /* original 432b, guest PC 0x0c070330 */
if(!s->budget--) { s->failed_pc=0x0c070330u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0704c0u: goto P_0c0704c0;
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
P_0c070332: /* original 0009, guest PC 0x0c070332 */
if(!s->budget--) { s->failed_pc=0x0c070332u; return 0; }
goto P_0c070334;
P_0c070334: /* original 64f3, guest PC 0x0c070334 */
if(!s->budget--) { s->failed_pc=0x0c070334u; return 0; }
r[4]=r[15];
goto P_0c070336;
P_0c070336: /* original 7444, guest PC 0x0c070336 */
if(!s->budget--) { s->failed_pc=0x0c070336u; return 0; }
r[4]+=0x00000044u;
goto P_0c070338;
P_0c070338: /* original 65c3, guest PC 0x0c070338 */
if(!s->budget--) { s->failed_pc=0x0c070338u; return 0; }
r[5]=r[12];
goto P_0c07033a;
P_0c07033a: /* original a003, guest PC 0x0c07033a */
if(!s->budget--) { s->failed_pc=0x0c07033au; return 0; }
goto P_0c070344;
P_0c07033c: /* original 0009, guest PC 0x0c07033c */
if(!s->budget--) { s->failed_pc=0x0c07033cu; return 0; }
if(!vf3_matrix_family(0x0c07033eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07033eu; return 0; } return 1;
P_0c070344: /* original f049, guest PC 0x0c070344 */
if(!s->budget--) { s->failed_pc=0x0c070344u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070346;
P_0c070346: /* original f549, guest PC 0x0c070346 */
if(!s->budget--) { s->failed_pc=0x0c070346u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070348;
P_0c070348: /* original f648, guest PC 0x0c070348 */
if(!s->budget--) { s->failed_pc=0x0c070348u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c07034a;
P_0c07034a: /* original f859, guest PC 0x0c07034a */
if(!s->budget--) { s->failed_pc=0x0c07034au; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07034c;
P_0c07034c: /* original f959, guest PC 0x0c07034c */
if(!s->budget--) { s->failed_pc=0x0c07034cu; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07034e;
P_0c07034e: /* original fa58, guest PC 0x0c07034e */
if(!s->budget--) { s->failed_pc=0x0c07034eu; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c070350;
P_0c070350: /* original f35c, guest PC 0x0c070350 */
if(!s->budget--) { s->failed_pc=0x0c070350u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c070352;
P_0c070352: /* original f382, guest PC 0x0c070352 */
if(!s->budget--) { s->failed_pc=0x0c070352u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c070354;
P_0c070354: /* original f20c, guest PC 0x0c070354 */
if(!s->budget--) { s->failed_pc=0x0c070354u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c070356;
P_0c070356: /* original f2a2, guest PC 0x0c070356 */
if(!s->budget--) { s->failed_pc=0x0c070356u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c070358;
P_0c070358: /* original f16c, guest PC 0x0c070358 */
if(!s->budget--) { s->failed_pc=0x0c070358u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c07035a;
P_0c07035a: /* original f192, guest PC 0x0c07035a */
if(!s->budget--) { s->failed_pc=0x0c07035au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c07035c;
P_0c07035c: /* original f34d, guest PC 0x0c07035c */
if(!s->budget--) { s->failed_pc=0x0c07035cu; return 0; }
fr[3]^=0x80000000u;
goto P_0c07035e;
P_0c07035e: /* original f39e, guest PC 0x0c07035e */
if(!s->budget--) { s->failed_pc=0x0c07035eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c070360;
P_0c070360: /* original f24d, guest PC 0x0c070360 */
if(!s->budget--) { s->failed_pc=0x0c070360u; return 0; }
fr[2]^=0x80000000u;
goto P_0c070362;
P_0c070362: /* original f06c, guest PC 0x0c070362 */
if(!s->budget--) { s->failed_pc=0x0c070362u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c070364;
P_0c070364: /* original f28e, guest PC 0x0c070364 */
if(!s->budget--) { s->failed_pc=0x0c070364u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c070366;
P_0c070366: /* original f14d, guest PC 0x0c070366 */
if(!s->budget--) { s->failed_pc=0x0c070366u; return 0; }
fr[1]^=0x80000000u;
goto P_0c070368;
P_0c070368: /* original f05c, guest PC 0x0c070368 */
if(!s->budget--) { s->failed_pc=0x0c070368u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c07036a;
P_0c07036a: /* original f1ae, guest PC 0x0c07036a */
if(!s->budget--) { s->failed_pc=0x0c07036au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c07036c;
P_0c07036c: /* original f08d, guest PC 0x0c07036c */
if(!s->budget--) { s->failed_pc=0x0c07036cu; return 0; }
fr[0]=0;
goto P_0c07036e;
P_0c07036e: /* original f0ed, guest PC 0x0c07036e */
if(!s->budget--) { s->failed_pc=0x0c07036eu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070370;
P_0c070370: /* original f03c, guest PC 0x0c070370 */
if(!s->budget--) { s->failed_pc=0x0c070370u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070372;
P_0c070372: /* original f06d, guest PC 0x0c070372 */
if(!s->budget--) { s->failed_pc=0x0c070372u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070374;
P_0c070374: /* original fc0c, guest PC 0x0c070374 */
if(!s->budget--) { s->failed_pc=0x0c070374u; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c070376;
P_0c070376: /* original ffc5, guest PC 0x0c070376 */
if(!s->budget--) { s->failed_pc=0x0c070376u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[12]))!=0);
goto P_0c070378;
P_0c070378: /* original 8902, guest PC 0x0c070378 */
if(!s->budget--) { s->failed_pc=0x0c070378u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070380; }
goto P_0c07037a;
P_0c07037a: /* original d304, guest PC 0x0c07037a */
if(!s->budget--) { s->failed_pc=0x0c07037au; return 0; }
r[3]=read(ram,0x0c07038cu,4);
goto P_0c07037c;
P_0c07037c: /* original 432b, guest PC 0x0c07037c */
if(!s->budget--) { s->failed_pc=0x0c07037cu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0704c0u: goto P_0c0704c0;
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
P_0c07037e: /* original 0009, guest PC 0x0c07037e */
if(!s->budget--) { s->failed_pc=0x0c07037eu; return 0; }
goto P_0c070380;
P_0c070380: /* original 64f3, guest PC 0x0c070380 */
if(!s->budget--) { s->failed_pc=0x0c070380u; return 0; }
r[4]=r[15];
goto P_0c070382;
P_0c070382: /* original 7444, guest PC 0x0c070382 */
if(!s->budget--) { s->failed_pc=0x0c070382u; return 0; }
r[4]+=0x00000044u;
goto P_0c070384;
P_0c070384: /* original 65c3, guest PC 0x0c070384 */
if(!s->budget--) { s->failed_pc=0x0c070384u; return 0; }
r[5]=r[12];
goto P_0c070386;
P_0c070386: /* original a003, guest PC 0x0c070386 */
if(!s->budget--) { s->failed_pc=0x0c070386u; return 0; }
goto P_0c070390;
P_0c070388: /* original 0009, guest PC 0x0c070388 */
if(!s->budget--) { s->failed_pc=0x0c070388u; return 0; }
if(!vf3_matrix_family(0x0c07038au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07038au; return 0; } return 1;
P_0c070390: /* original f049, guest PC 0x0c070390 */
if(!s->budget--) { s->failed_pc=0x0c070390u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070392;
P_0c070392: /* original f149, guest PC 0x0c070392 */
if(!s->budget--) { s->failed_pc=0x0c070392u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070394;
P_0c070394: /* original f249, guest PC 0x0c070394 */
if(!s->budget--) { s->failed_pc=0x0c070394u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070396;
P_0c070396: /* original f38d, guest PC 0x0c070396 */
if(!s->budget--) { s->failed_pc=0x0c070396u; return 0; }
fr[3]=0;
goto P_0c070398;
P_0c070398: /* original f459, guest PC 0x0c070398 */
if(!s->budget--) { s->failed_pc=0x0c070398u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07039a;
P_0c07039a: /* original f559, guest PC 0x0c07039a */
if(!s->budget--) { s->failed_pc=0x0c07039au; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07039c;
P_0c07039c: /* original f659, guest PC 0x0c07039c */
if(!s->budget--) { s->failed_pc=0x0c07039cu; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07039e;
P_0c07039e: /* original f78d, guest PC 0x0c07039e */
if(!s->budget--) { s->failed_pc=0x0c07039eu; return 0; }
fr[7]=0;
goto P_0c0703a0;
P_0c0703a0: /* original f4ed, guest PC 0x0c0703a0 */
if(!s->budget--) { s->failed_pc=0x0c0703a0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c0703a2;
P_0c0703a2: /* original f07c, guest PC 0x0c0703a2 */
if(!s->budget--) { s->failed_pc=0x0c0703a2u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c0703a4;
P_0c0703a4: /* original f38d, guest PC 0x0c0703a4 */
if(!s->budget--) { s->failed_pc=0x0c0703a4u; return 0; }
fr[3]=0;
goto P_0c0703a6;
P_0c0703a6: /* original f40c, guest PC 0x0c0703a6 */
if(!s->budget--) { s->failed_pc=0x0c0703a6u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0703a8;
P_0c0703a8: /* original f345, guest PC 0x0c0703a8 */
if(!s->budget--) { s->failed_pc=0x0c0703a8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0703aa;
P_0c0703aa: /* original 8902, guest PC 0x0c0703aa */
if(!s->budget--) { s->failed_pc=0x0c0703aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0703b2; }
goto P_0c0703ac;
P_0c0703ac: /* original d308, guest PC 0x0c0703ac */
if(!s->budget--) { s->failed_pc=0x0c0703acu; return 0; }
r[3]=read(ram,0x0c0703d0u,4);
goto P_0c0703ae;
P_0c0703ae: /* original 432b, guest PC 0x0c0703ae */
if(!s->budget--) { s->failed_pc=0x0c0703aeu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0703fau: goto P_0c0703fa;
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
P_0c0703b0: /* original 0009, guest PC 0x0c0703b0 */
if(!s->budget--) { s->failed_pc=0x0c0703b0u; return 0; }
goto P_0c0703b2;
P_0c0703b2: /* original e014, guest PC 0x0c0703b2 */
if(!s->budget--) { s->failed_pc=0x0c0703b2u; return 0; }
r[0]=0x00000014u;
goto P_0c0703b4;
P_0c0703b4: /* original f3f6, guest PC 0x0c0703b4 */
if(!s->budget--) { s->failed_pc=0x0c0703b4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0703b6;
P_0c0703b6: /* original ff35, guest PC 0x0c0703b6 */
if(!s->budget--) { s->failed_pc=0x0c0703b6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c0703b8;
P_0c0703b8: /* original 8902, guest PC 0x0c0703b8 */
if(!s->budget--) { s->failed_pc=0x0c0703b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0703c0; }
goto P_0c0703ba;
P_0c0703ba: /* original d306, guest PC 0x0c0703ba */
if(!s->budget--) { s->failed_pc=0x0c0703bau; return 0; }
r[3]=read(ram,0x0c0703d4u,4);
goto P_0c0703bc;
P_0c0703bc: /* original 432b, guest PC 0x0c0703bc */
if(!s->budget--) { s->failed_pc=0x0c0703bcu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0704c0u: goto P_0c0704c0;
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
P_0c0703be: /* original 0009, guest PC 0x0c0703be */
if(!s->budget--) { s->failed_pc=0x0c0703beu; return 0; }
goto P_0c0703c0;
P_0c0703c0: /* original 64f3, guest PC 0x0c0703c0 */
if(!s->budget--) { s->failed_pc=0x0c0703c0u; return 0; }
r[4]=r[15];
goto P_0c0703c2;
P_0c0703c2: /* original 65f3, guest PC 0x0c0703c2 */
if(!s->budget--) { s->failed_pc=0x0c0703c2u; return 0; }
r[5]=r[15];
goto P_0c0703c4;
P_0c0703c4: /* original 7444, guest PC 0x0c0703c4 */
if(!s->budget--) { s->failed_pc=0x0c0703c4u; return 0; }
r[4]+=0x00000044u;
goto P_0c0703c6;
P_0c0703c6: /* original f4fc, guest PC 0x0c0703c6 */
if(!s->budget--) { s->failed_pc=0x0c0703c6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0703c8;
P_0c0703c8: /* original 7544, guest PC 0x0c0703c8 */
if(!s->budget--) { s->failed_pc=0x0c0703c8u; return 0; }
r[5]+=0x00000044u;
goto P_0c0703ca;
P_0c0703ca: /* original a005, guest PC 0x0c0703ca */
if(!s->budget--) { s->failed_pc=0x0c0703cau; return 0; }
goto P_0c0703d8;
P_0c0703cc: /* original 0009, guest PC 0x0c0703cc */
if(!s->budget--) { s->failed_pc=0x0c0703ccu; return 0; }
if(!vf3_matrix_family(0x0c0703ceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0703ceu; return 0; } return 1;
P_0c0703d8: /* original f059, guest PC 0x0c0703d8 */
if(!s->budget--) { s->failed_pc=0x0c0703d8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0703da;
P_0c0703da: /* original f159, guest PC 0x0c0703da */
if(!s->budget--) { s->failed_pc=0x0c0703dau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0703dc;
P_0c0703dc: /* original f259, guest PC 0x0c0703dc */
if(!s->budget--) { s->failed_pc=0x0c0703dcu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0703de;
P_0c0703de: /* original f38d, guest PC 0x0c0703de */
if(!s->budget--) { s->failed_pc=0x0c0703deu; return 0; }
fr[3]=0;
goto P_0c0703e0;
P_0c0703e0: /* original f0ed, guest PC 0x0c0703e0 */
if(!s->budget--) { s->failed_pc=0x0c0703e0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0703e2;
P_0c0703e2: /* original f37d, guest PC 0x0c0703e2 */
if(!s->budget--) { s->failed_pc=0x0c0703e2u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0703e4;
P_0c0703e4: /* original f342, guest PC 0x0c0703e4 */
if(!s->budget--) { s->failed_pc=0x0c0703e4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0703e6;
P_0c0703e6: /* original 740c, guest PC 0x0c0703e6 */
if(!s->budget--) { s->failed_pc=0x0c0703e6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0703e8;
P_0c0703e8: /* original f232, guest PC 0x0c0703e8 */
if(!s->budget--) { s->failed_pc=0x0c0703e8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0703ea;
P_0c0703ea: /* original f132, guest PC 0x0c0703ea */
if(!s->budget--) { s->failed_pc=0x0c0703eau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0703ec;
P_0c0703ec: /* original f032, guest PC 0x0c0703ec */
if(!s->budget--) { s->failed_pc=0x0c0703ecu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0703ee;
P_0c0703ee: /* original f42b, guest PC 0x0c0703ee */
if(!s->budget--) { s->failed_pc=0x0c0703eeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0703f0;
P_0c0703f0: /* original f41b, guest PC 0x0c0703f0 */
if(!s->budget--) { s->failed_pc=0x0c0703f0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0703f2;
P_0c0703f2: /* original f40b, guest PC 0x0c0703f2 */
if(!s->budget--) { s->failed_pc=0x0c0703f2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0703f4;
P_0c0703f4: /* original d306, guest PC 0x0c0703f4 */
if(!s->budget--) { s->failed_pc=0x0c0703f4u; return 0; }
r[3]=read(ram,0x0c070410u,4);
goto P_0c0703f6;
P_0c0703f6: /* original 432b, guest PC 0x0c0703f6 */
if(!s->budget--) { s->failed_pc=0x0c0703f6u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c07049cu: goto P_0c07049c;
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
P_0c0703f8: /* original 0009, guest PC 0x0c0703f8 */
if(!s->budget--) { s->failed_pc=0x0c0703f8u; return 0; }
goto P_0c0703fa;
P_0c0703fa: /* original fe45, guest PC 0x0c0703fa */
if(!s->budget--) { s->failed_pc=0x0c0703fau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[4]))!=0);
goto P_0c0703fc;
P_0c0703fc: /* original 8902, guest PC 0x0c0703fc */
if(!s->budget--) { s->failed_pc=0x0c0703fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070404; }
goto P_0c0703fe;
P_0c0703fe: /* original d305, guest PC 0x0c0703fe */
if(!s->budget--) { s->failed_pc=0x0c0703feu; return 0; }
r[3]=read(ram,0x0c070414u,4);
goto P_0c070400;
P_0c070400: /* original 432b, guest PC 0x0c070400 */
if(!s->budget--) { s->failed_pc=0x0c070400u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0704c0u: goto P_0c0704c0;
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
P_0c070402: /* original 0009, guest PC 0x0c070402 */
if(!s->budget--) { s->failed_pc=0x0c070402u; return 0; }
goto P_0c070404;
P_0c070404: /* original 64f3, guest PC 0x0c070404 */
if(!s->budget--) { s->failed_pc=0x0c070404u; return 0; }
r[4]=r[15];
goto P_0c070406;
P_0c070406: /* original 7438, guest PC 0x0c070406 */
if(!s->budget--) { s->failed_pc=0x0c070406u; return 0; }
r[4]+=0x00000038u;
goto P_0c070408;
P_0c070408: /* original 65c3, guest PC 0x0c070408 */
if(!s->budget--) { s->failed_pc=0x0c070408u; return 0; }
r[5]=r[12];
goto P_0c07040a;
P_0c07040a: /* original a005, guest PC 0x0c07040a */
if(!s->budget--) { s->failed_pc=0x0c07040au; return 0; }
goto P_0c070418;
P_0c07040c: /* original 0009, guest PC 0x0c07040c */
if(!s->budget--) { s->failed_pc=0x0c07040cu; return 0; }
if(!vf3_matrix_family(0x0c07040eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07040eu; return 0; } return 1;
P_0c070418: /* original f059, guest PC 0x0c070418 */
if(!s->budget--) { s->failed_pc=0x0c070418u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07041a;
P_0c07041a: /* original f159, guest PC 0x0c07041a */
if(!s->budget--) { s->failed_pc=0x0c07041au; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07041c;
P_0c07041c: /* original f259, guest PC 0x0c07041c */
if(!s->budget--) { s->failed_pc=0x0c07041cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07041e;
P_0c07041e: /* original 740c, guest PC 0x0c07041e */
if(!s->budget--) { s->failed_pc=0x0c07041eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c070420;
P_0c070420: /* original f242, guest PC 0x0c070420 */
if(!s->budget--) { s->failed_pc=0x0c070420u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c070422;
P_0c070422: /* original f142, guest PC 0x0c070422 */
if(!s->budget--) { s->failed_pc=0x0c070422u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c070424;
P_0c070424: /* original f042, guest PC 0x0c070424 */
if(!s->budget--) { s->failed_pc=0x0c070424u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c070426;
P_0c070426: /* original f42b, guest PC 0x0c070426 */
if(!s->budget--) { s->failed_pc=0x0c070426u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070428;
P_0c070428: /* original f41b, guest PC 0x0c070428 */
if(!s->budget--) { s->failed_pc=0x0c070428u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07042a;
P_0c07042a: /* original f40b, guest PC 0x0c07042a */
if(!s->budget--) { s->failed_pc=0x0c07042au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07042c;
P_0c07042c: /* original 65f3, guest PC 0x0c07042c */
if(!s->budget--) { s->failed_pc=0x0c07042cu; return 0; }
r[5]=r[15];
goto P_0c07042e;
P_0c07042e: /* original 64f3, guest PC 0x0c07042e */
if(!s->budget--) { s->failed_pc=0x0c07042eu; return 0; }
r[4]=r[15];
goto P_0c070430;
P_0c070430: /* original 66f3, guest PC 0x0c070430 */
if(!s->budget--) { s->failed_pc=0x0c070430u; return 0; }
r[6]=r[15];
goto P_0c070432;
P_0c070432: /* original 7438, guest PC 0x0c070432 */
if(!s->budget--) { s->failed_pc=0x0c070432u; return 0; }
r[4]+=0x00000038u;
goto P_0c070434;
P_0c070434: /* original 7638, guest PC 0x0c070434 */
if(!s->budget--) { s->failed_pc=0x0c070434u; return 0; }
r[6]+=0x00000038u;
goto P_0c070436;
P_0c070436: /* original 7544, guest PC 0x0c070436 */
if(!s->budget--) { s->failed_pc=0x0c070436u; return 0; }
r[5]+=0x00000044u;
goto P_0c070438;
P_0c070438: /* original f059, guest PC 0x0c070438 */
if(!s->budget--) { s->failed_pc=0x0c070438u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07043a;
P_0c07043a: /* original f369, guest PC 0x0c07043a */
if(!s->budget--) { s->failed_pc=0x0c07043au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07043c;
P_0c07043c: /* original f159, guest PC 0x0c07043c */
if(!s->budget--) { s->failed_pc=0x0c07043cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07043e;
P_0c07043e: /* original f469, guest PC 0x0c07043e */
if(!s->budget--) { s->failed_pc=0x0c07043eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070440;
P_0c070440: /* original f031, guest PC 0x0c070440 */
if(!s->budget--) { s->failed_pc=0x0c070440u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070442;
P_0c070442: /* original f258, guest PC 0x0c070442 */
if(!s->budget--) { s->failed_pc=0x0c070442u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070444;
P_0c070444: /* original f568, guest PC 0x0c070444 */
if(!s->budget--) { s->failed_pc=0x0c070444u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070446;
P_0c070446: /* original f141, guest PC 0x0c070446 */
if(!s->budget--) { s->failed_pc=0x0c070446u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070448;
P_0c070448: /* original f251, guest PC 0x0c070448 */
if(!s->budget--) { s->failed_pc=0x0c070448u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c07044a;
P_0c07044a: /* original 7408, guest PC 0x0c07044a */
if(!s->budget--) { s->failed_pc=0x0c07044au; return 0; }
r[4]+=0x00000008u;
goto P_0c07044c;
P_0c07044c: /* original f42a, guest PC 0x0c07044c */
if(!s->budget--) { s->failed_pc=0x0c07044cu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07044e;
P_0c07044e: /* original f41b, guest PC 0x0c07044e */
if(!s->budget--) { s->failed_pc=0x0c07044eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070450;
P_0c070450: /* original f40b, guest PC 0x0c070450 */
if(!s->budget--) { s->failed_pc=0x0c070450u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070452;
P_0c070452: /* original 0009, guest PC 0x0c070452 */
if(!s->budget--) { s->failed_pc=0x0c070452u; return 0; }
goto P_0c070454;
P_0c070454: /* original f4fc, guest PC 0x0c070454 */
if(!s->budget--) { s->failed_pc=0x0c070454u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070456;
P_0c070456: /* original f4c1, guest PC 0x0c070456 */
if(!s->budget--) { s->failed_pc=0x0c070456u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[12],r[18],'-');
goto P_0c070458;
P_0c070458: /* original 64f3, guest PC 0x0c070458 */
if(!s->budget--) { s->failed_pc=0x0c070458u; return 0; }
r[4]=r[15];
goto P_0c07045a;
P_0c07045a: /* original 65f3, guest PC 0x0c07045a */
if(!s->budget--) { s->failed_pc=0x0c07045au; return 0; }
r[5]=r[15];
goto P_0c07045c;
P_0c07045c: /* original 7438, guest PC 0x0c07045c */
if(!s->budget--) { s->failed_pc=0x0c07045cu; return 0; }
r[4]+=0x00000038u;
goto P_0c07045e;
P_0c07045e: /* original 7538, guest PC 0x0c07045e */
if(!s->budget--) { s->failed_pc=0x0c07045eu; return 0; }
r[5]+=0x00000038u;
goto P_0c070460;
P_0c070460: /* original f059, guest PC 0x0c070460 */
if(!s->budget--) { s->failed_pc=0x0c070460u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070462;
P_0c070462: /* original f159, guest PC 0x0c070462 */
if(!s->budget--) { s->failed_pc=0x0c070462u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070464;
P_0c070464: /* original f259, guest PC 0x0c070464 */
if(!s->budget--) { s->failed_pc=0x0c070464u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070466;
P_0c070466: /* original f38d, guest PC 0x0c070466 */
if(!s->budget--) { s->failed_pc=0x0c070466u; return 0; }
fr[3]=0;
goto P_0c070468;
P_0c070468: /* original f0ed, guest PC 0x0c070468 */
if(!s->budget--) { s->failed_pc=0x0c070468u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07046a;
P_0c07046a: /* original f37d, guest PC 0x0c07046a */
if(!s->budget--) { s->failed_pc=0x0c07046au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c07046c;
P_0c07046c: /* original f342, guest PC 0x0c07046c */
if(!s->budget--) { s->failed_pc=0x0c07046cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c07046e;
P_0c07046e: /* original 740c, guest PC 0x0c07046e */
if(!s->budget--) { s->failed_pc=0x0c07046eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c070470;
P_0c070470: /* original f232, guest PC 0x0c070470 */
if(!s->budget--) { s->failed_pc=0x0c070470u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070472;
P_0c070472: /* original f132, guest PC 0x0c070472 */
if(!s->budget--) { s->failed_pc=0x0c070472u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070474;
P_0c070474: /* original f032, guest PC 0x0c070474 */
if(!s->budget--) { s->failed_pc=0x0c070474u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070476;
P_0c070476: /* original f42b, guest PC 0x0c070476 */
if(!s->budget--) { s->failed_pc=0x0c070476u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070478;
P_0c070478: /* original f41b, guest PC 0x0c070478 */
if(!s->budget--) { s->failed_pc=0x0c070478u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07047a;
P_0c07047a: /* original f40b, guest PC 0x0c07047a */
if(!s->budget--) { s->failed_pc=0x0c07047au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07047c;
P_0c07047c: /* original 64f3, guest PC 0x0c07047c */
if(!s->budget--) { s->failed_pc=0x0c07047cu; return 0; }
r[4]=r[15];
goto P_0c07047e;
P_0c07047e: /* original 65f3, guest PC 0x0c07047e */
if(!s->budget--) { s->failed_pc=0x0c07047eu; return 0; }
r[5]=r[15];
goto P_0c070480;
P_0c070480: /* original 7444, guest PC 0x0c070480 */
if(!s->budget--) { s->failed_pc=0x0c070480u; return 0; }
r[4]+=0x00000044u;
goto P_0c070482;
P_0c070482: /* original 7538, guest PC 0x0c070482 */
if(!s->budget--) { s->failed_pc=0x0c070482u; return 0; }
r[5]+=0x00000038u;
goto P_0c070484;
P_0c070484: /* original f049, guest PC 0x0c070484 */
if(!s->budget--) { s->failed_pc=0x0c070484u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070486;
P_0c070486: /* original f359, guest PC 0x0c070486 */
if(!s->budget--) { s->failed_pc=0x0c070486u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070488;
P_0c070488: /* original f149, guest PC 0x0c070488 */
if(!s->budget--) { s->failed_pc=0x0c070488u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07048a;
P_0c07048a: /* original f459, guest PC 0x0c07048a */
if(!s->budget--) { s->failed_pc=0x0c07048au; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07048c;
P_0c07048c: /* original f249, guest PC 0x0c07048c */
if(!s->budget--) { s->failed_pc=0x0c07048cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07048e;
P_0c07048e: /* original f559, guest PC 0x0c07048e */
if(!s->budget--) { s->failed_pc=0x0c07048eu; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070490;
P_0c070490: /* original f030, guest PC 0x0c070490 */
if(!s->budget--) { s->failed_pc=0x0c070490u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070492;
P_0c070492: /* original f250, guest PC 0x0c070492 */
if(!s->budget--) { s->failed_pc=0x0c070492u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070494;
P_0c070494: /* original f140, guest PC 0x0c070494 */
if(!s->budget--) { s->failed_pc=0x0c070494u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070496;
P_0c070496: /* original f42b, guest PC 0x0c070496 */
if(!s->budget--) { s->failed_pc=0x0c070496u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070498;
P_0c070498: /* original f41b, guest PC 0x0c070498 */
if(!s->budget--) { s->failed_pc=0x0c070498u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07049a;
P_0c07049a: /* original f40b, guest PC 0x0c07049a */
if(!s->budget--) { s->failed_pc=0x0c07049au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07049c;
P_0c07049c: /* original 65f3, guest PC 0x0c07049c */
if(!s->budget--) { s->failed_pc=0x0c07049cu; return 0; }
r[5]=r[15];
goto P_0c07049e;
P_0c07049e: /* original 64e3, guest PC 0x0c07049e */
if(!s->budget--) { s->failed_pc=0x0c07049eu; return 0; }
r[4]=r[14];
goto P_0c0704a0;
P_0c0704a0: /* original 7544, guest PC 0x0c0704a0 */
if(!s->budget--) { s->failed_pc=0x0c0704a0u; return 0; }
r[5]+=0x00000044u;
goto P_0c0704a2;
P_0c0704a2: /* original 6693, guest PC 0x0c0704a2 */
if(!s->budget--) { s->failed_pc=0x0c0704a2u; return 0; }
r[6]=r[9];
goto P_0c0704a4;
P_0c0704a4: /* original f059, guest PC 0x0c0704a4 */
if(!s->budget--) { s->failed_pc=0x0c0704a4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0704a6;
P_0c0704a6: /* original f369, guest PC 0x0c0704a6 */
if(!s->budget--) { s->failed_pc=0x0c0704a6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0704a8;
P_0c0704a8: /* original f159, guest PC 0x0c0704a8 */
if(!s->budget--) { s->failed_pc=0x0c0704a8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0704aa;
P_0c0704aa: /* original f469, guest PC 0x0c0704aa */
if(!s->budget--) { s->failed_pc=0x0c0704aau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0704ac;
P_0c0704ac: /* original f259, guest PC 0x0c0704ac */
if(!s->budget--) { s->failed_pc=0x0c0704acu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0704ae;
P_0c0704ae: /* original f569, guest PC 0x0c0704ae */
if(!s->budget--) { s->failed_pc=0x0c0704aeu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0704b0;
P_0c0704b0: /* original 740c, guest PC 0x0c0704b0 */
if(!s->budget--) { s->failed_pc=0x0c0704b0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0704b2;
P_0c0704b2: /* original f030, guest PC 0x0c0704b2 */
if(!s->budget--) { s->failed_pc=0x0c0704b2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c0704b4;
P_0c0704b4: /* original f250, guest PC 0x0c0704b4 */
if(!s->budget--) { s->failed_pc=0x0c0704b4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c0704b6;
P_0c0704b6: /* original f140, guest PC 0x0c0704b6 */
if(!s->budget--) { s->failed_pc=0x0c0704b6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c0704b8;
P_0c0704b8: /* original f42b, guest PC 0x0c0704b8 */
if(!s->budget--) { s->failed_pc=0x0c0704b8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0704ba;
P_0c0704ba: /* original f41b, guest PC 0x0c0704ba */
if(!s->budget--) { s->failed_pc=0x0c0704bau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0704bc;
P_0c0704bc: /* original f40b, guest PC 0x0c0704bc */
if(!s->budget--) { s->failed_pc=0x0c0704bcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0704be;
P_0c0704be: /* original 0009, guest PC 0x0c0704be */
if(!s->budget--) { s->failed_pc=0x0c0704beu; return 0; }
goto P_0c0704c0;
P_0c0704c0: /* original 50fa, guest PC 0x0c0704c0 */
if(!s->budget--) { s->failed_pc=0x0c0704c0u; return 0; }
r[0]=read(ram,r[15]+40,4);
goto P_0c0704c2;
P_0c0704c2: /* original 8801, guest PC 0x0c0704c2 */
if(!s->budget--) { s->failed_pc=0x0c0704c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0704c4;
P_0c0704c4: /* original 8902, guest PC 0x0c0704c4 */
if(!s->budget--) { s->failed_pc=0x0c0704c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0704cc; }
goto P_0c0704c6;
P_0c0704c6: /* original d304, guest PC 0x0c0704c6 */
if(!s->budget--) { s->failed_pc=0x0c0704c6u; return 0; }
r[3]=read(ram,0x0c0704d8u,4);
goto P_0c0704c8;
P_0c0704c8: /* original 432b, guest PC 0x0c0704c8 */
if(!s->budget--) { s->failed_pc=0x0c0704c8u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070878u: goto P_0c070878;
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
P_0c0704ca: /* original 0009, guest PC 0x0c0704ca */
if(!s->budget--) { s->failed_pc=0x0c0704cau; return 0; }
goto P_0c0704cc;
P_0c0704cc: /* original 64f3, guest PC 0x0c0704cc */
if(!s->budget--) { s->failed_pc=0x0c0704ccu; return 0; }
r[4]=r[15];
goto P_0c0704ce;
P_0c0704ce: /* original 7444, guest PC 0x0c0704ce */
if(!s->budget--) { s->failed_pc=0x0c0704ceu; return 0; }
r[4]+=0x00000044u;
goto P_0c0704d0;
P_0c0704d0: /* original 66a3, guest PC 0x0c0704d0 */
if(!s->budget--) { s->failed_pc=0x0c0704d0u; return 0; }
r[6]=r[10];
goto P_0c0704d2;
P_0c0704d2: /* original 65d3, guest PC 0x0c0704d2 */
if(!s->budget--) { s->failed_pc=0x0c0704d2u; return 0; }
r[5]=r[13];
goto P_0c0704d4;
P_0c0704d4: /* original a002, guest PC 0x0c0704d4 */
if(!s->budget--) { s->failed_pc=0x0c0704d4u; return 0; }
goto P_0c0704dc;
P_0c0704d6: /* original 0009, guest PC 0x0c0704d6 */
if(!s->budget--) { s->failed_pc=0x0c0704d6u; return 0; }
if(!vf3_matrix_family(0x0c0704d8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0704d8u; return 0; } return 1;
P_0c0704dc: /* original f059, guest PC 0x0c0704dc */
if(!s->budget--) { s->failed_pc=0x0c0704dcu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0704de;
P_0c0704de: /* original f369, guest PC 0x0c0704de */
if(!s->budget--) { s->failed_pc=0x0c0704deu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0704e0;
P_0c0704e0: /* original f159, guest PC 0x0c0704e0 */
if(!s->budget--) { s->failed_pc=0x0c0704e0u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0704e2;
P_0c0704e2: /* original f469, guest PC 0x0c0704e2 */
if(!s->budget--) { s->failed_pc=0x0c0704e2u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0704e4;
P_0c0704e4: /* original f031, guest PC 0x0c0704e4 */
if(!s->budget--) { s->failed_pc=0x0c0704e4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0704e6;
P_0c0704e6: /* original f258, guest PC 0x0c0704e6 */
if(!s->budget--) { s->failed_pc=0x0c0704e6u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0704e8;
P_0c0704e8: /* original f568, guest PC 0x0c0704e8 */
if(!s->budget--) { s->failed_pc=0x0c0704e8u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0704ea;
P_0c0704ea: /* original f141, guest PC 0x0c0704ea */
if(!s->budget--) { s->failed_pc=0x0c0704eau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0704ec;
P_0c0704ec: /* original f251, guest PC 0x0c0704ec */
if(!s->budget--) { s->failed_pc=0x0c0704ecu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0704ee;
P_0c0704ee: /* original 7408, guest PC 0x0c0704ee */
if(!s->budget--) { s->failed_pc=0x0c0704eeu; return 0; }
r[4]+=0x00000008u;
goto P_0c0704f0;
P_0c0704f0: /* original f42a, guest PC 0x0c0704f0 */
if(!s->budget--) { s->failed_pc=0x0c0704f0u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0704f2;
P_0c0704f2: /* original f41b, guest PC 0x0c0704f2 */
if(!s->budget--) { s->failed_pc=0x0c0704f2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0704f4;
P_0c0704f4: /* original f40b, guest PC 0x0c0704f4 */
if(!s->budget--) { s->failed_pc=0x0c0704f4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0704f6;
P_0c0704f6: /* original 0009, guest PC 0x0c0704f6 */
if(!s->budget--) { s->failed_pc=0x0c0704f6u; return 0; }
goto P_0c0704f8;
P_0c0704f8: /* original 64f3, guest PC 0x0c0704f8 */
if(!s->budget--) { s->failed_pc=0x0c0704f8u; return 0; }
r[4]=r[15];
goto P_0c0704fa;
P_0c0704fa: /* original 7444, guest PC 0x0c0704fa */
if(!s->budget--) { s->failed_pc=0x0c0704fau; return 0; }
r[4]+=0x00000044u;
goto P_0c0704fc;
P_0c0704fc: /* original f049, guest PC 0x0c0704fc */
if(!s->budget--) { s->failed_pc=0x0c0704fcu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0704fe;
P_0c0704fe: /* original f149, guest PC 0x0c0704fe */
if(!s->budget--) { s->failed_pc=0x0c0704feu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070500;
P_0c070500: /* original f249, guest PC 0x0c070500 */
if(!s->budget--) { s->failed_pc=0x0c070500u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070502;
P_0c070502: /* original f38d, guest PC 0x0c070502 */
if(!s->budget--) { s->failed_pc=0x0c070502u; return 0; }
fr[3]=0;
goto P_0c070504;
P_0c070504: /* original f0ed, guest PC 0x0c070504 */
if(!s->budget--) { s->failed_pc=0x0c070504u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070506;
P_0c070506: /* original f03c, guest PC 0x0c070506 */
if(!s->budget--) { s->failed_pc=0x0c070506u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070508;
P_0c070508: /* original f06d, guest PC 0x0c070508 */
if(!s->budget--) { s->failed_pc=0x0c070508u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c07050a;
P_0c07050a: /* original 0009, guest PC 0x0c07050a */
if(!s->budget--) { s->failed_pc=0x0c07050au; return 0; }
goto P_0c07050c;
P_0c07050c: /* original f38d, guest PC 0x0c07050c */
if(!s->budget--) { s->failed_pc=0x0c07050cu; return 0; }
fr[3]=0;
goto P_0c07050e;
P_0c07050e: /* original fc0c, guest PC 0x0c07050e */
if(!s->budget--) { s->failed_pc=0x0c07050eu; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c070510;
P_0c070510: /* original fc35, guest PC 0x0c070510 */
if(!s->budget--) { s->failed_pc=0x0c070510u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[12])>as_float(fr[3]))!=0);
goto P_0c070512;
P_0c070512: /* original 8902, guest PC 0x0c070512 */
if(!s->budget--) { s->failed_pc=0x0c070512u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07051a; }
goto P_0c070514;
P_0c070514: /* original d303, guest PC 0x0c070514 */
if(!s->budget--) { s->failed_pc=0x0c070514u; return 0; }
r[3]=read(ram,0x0c070524u,4);
goto P_0c070516;
P_0c070516: /* original 432b, guest PC 0x0c070516 */
if(!s->budget--) { s->failed_pc=0x0c070516u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0706a4u: goto P_0c0706a4;
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
P_0c070518: /* original 0009, guest PC 0x0c070518 */
if(!s->budget--) { s->failed_pc=0x0c070518u; return 0; }
goto P_0c07051a;
P_0c07051a: /* original 64f3, guest PC 0x0c07051a */
if(!s->budget--) { s->failed_pc=0x0c07051au; return 0; }
r[4]=r[15];
goto P_0c07051c;
P_0c07051c: /* original 7444, guest PC 0x0c07051c */
if(!s->budget--) { s->failed_pc=0x0c07051cu; return 0; }
r[4]+=0x00000044u;
goto P_0c07051e;
P_0c07051e: /* original 65b3, guest PC 0x0c07051e */
if(!s->budget--) { s->failed_pc=0x0c07051eu; return 0; }
r[5]=r[11];
goto P_0c070520;
P_0c070520: /* original a002, guest PC 0x0c070520 */
if(!s->budget--) { s->failed_pc=0x0c070520u; return 0; }
goto P_0c070528;
P_0c070522: /* original 0009, guest PC 0x0c070522 */
if(!s->budget--) { s->failed_pc=0x0c070522u; return 0; }
if(!vf3_matrix_family(0x0c070524u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c070524u; return 0; } return 1;
P_0c070528: /* original f049, guest PC 0x0c070528 */
if(!s->budget--) { s->failed_pc=0x0c070528u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07052a;
P_0c07052a: /* original f549, guest PC 0x0c07052a */
if(!s->budget--) { s->failed_pc=0x0c07052au; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07052c;
P_0c07052c: /* original f648, guest PC 0x0c07052c */
if(!s->budget--) { s->failed_pc=0x0c07052cu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c07052e;
P_0c07052e: /* original f859, guest PC 0x0c07052e */
if(!s->budget--) { s->failed_pc=0x0c07052eu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070530;
P_0c070530: /* original f959, guest PC 0x0c070530 */
if(!s->budget--) { s->failed_pc=0x0c070530u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070532;
P_0c070532: /* original fa58, guest PC 0x0c070532 */
if(!s->budget--) { s->failed_pc=0x0c070532u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c070534;
P_0c070534: /* original f35c, guest PC 0x0c070534 */
if(!s->budget--) { s->failed_pc=0x0c070534u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c070536;
P_0c070536: /* original f382, guest PC 0x0c070536 */
if(!s->budget--) { s->failed_pc=0x0c070536u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c070538;
P_0c070538: /* original f20c, guest PC 0x0c070538 */
if(!s->budget--) { s->failed_pc=0x0c070538u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c07053a;
P_0c07053a: /* original f2a2, guest PC 0x0c07053a */
if(!s->budget--) { s->failed_pc=0x0c07053au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c07053c;
P_0c07053c: /* original f16c, guest PC 0x0c07053c */
if(!s->budget--) { s->failed_pc=0x0c07053cu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c07053e;
P_0c07053e: /* original f192, guest PC 0x0c07053e */
if(!s->budget--) { s->failed_pc=0x0c07053eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c070540;
P_0c070540: /* original f34d, guest PC 0x0c070540 */
if(!s->budget--) { s->failed_pc=0x0c070540u; return 0; }
fr[3]^=0x80000000u;
goto P_0c070542;
P_0c070542: /* original f39e, guest PC 0x0c070542 */
if(!s->budget--) { s->failed_pc=0x0c070542u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c070544;
P_0c070544: /* original f24d, guest PC 0x0c070544 */
if(!s->budget--) { s->failed_pc=0x0c070544u; return 0; }
fr[2]^=0x80000000u;
goto P_0c070546;
P_0c070546: /* original f06c, guest PC 0x0c070546 */
if(!s->budget--) { s->failed_pc=0x0c070546u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c070548;
P_0c070548: /* original f28e, guest PC 0x0c070548 */
if(!s->budget--) { s->failed_pc=0x0c070548u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c07054a;
P_0c07054a: /* original f14d, guest PC 0x0c07054a */
if(!s->budget--) { s->failed_pc=0x0c07054au; return 0; }
fr[1]^=0x80000000u;
goto P_0c07054c;
P_0c07054c: /* original f05c, guest PC 0x0c07054c */
if(!s->budget--) { s->failed_pc=0x0c07054cu; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c07054e;
P_0c07054e: /* original f1ae, guest PC 0x0c07054e */
if(!s->budget--) { s->failed_pc=0x0c07054eu; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c070550;
P_0c070550: /* original f08d, guest PC 0x0c070550 */
if(!s->budget--) { s->failed_pc=0x0c070550u; return 0; }
fr[0]=0;
goto P_0c070552;
P_0c070552: /* original f0ed, guest PC 0x0c070552 */
if(!s->budget--) { s->failed_pc=0x0c070552u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070554;
P_0c070554: /* original f03c, guest PC 0x0c070554 */
if(!s->budget--) { s->failed_pc=0x0c070554u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070556;
P_0c070556: /* original f06d, guest PC 0x0c070556 */
if(!s->budget--) { s->failed_pc=0x0c070556u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070558;
P_0c070558: /* original ff05, guest PC 0x0c070558 */
if(!s->budget--) { s->failed_pc=0x0c070558u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[0]))!=0);
goto P_0c07055a;
P_0c07055a: /* original e010, guest PC 0x0c07055a */
if(!s->budget--) { s->failed_pc=0x0c07055au; return 0; }
r[0]=0x00000010u;
goto P_0c07055c;
P_0c07055c: /* original 8d03, guest PC 0x0c07055c */
if(!s->budget--) { s->failed_pc=0x0c07055cu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(cond) { goto P_0c070566; }
goto P_0c070560;
P_0c07055e: /* original ff07, guest PC 0x0c07055e */
if(!s->budget--) { s->failed_pc=0x0c07055eu; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c070560;
P_0c070560: /* original d303, guest PC 0x0c070560 */
if(!s->budget--) { s->failed_pc=0x0c070560u; return 0; }
r[3]=read(ram,0x0c070570u,4);
goto P_0c070562;
P_0c070562: /* original 432b, guest PC 0x0c070562 */
if(!s->budget--) { s->failed_pc=0x0c070562u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0706a4u: goto P_0c0706a4;
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
P_0c070564: /* original 0009, guest PC 0x0c070564 */
if(!s->budget--) { s->failed_pc=0x0c070564u; return 0; }
goto P_0c070566;
P_0c070566: /* original 64f3, guest PC 0x0c070566 */
if(!s->budget--) { s->failed_pc=0x0c070566u; return 0; }
r[4]=r[15];
goto P_0c070568;
P_0c070568: /* original 7444, guest PC 0x0c070568 */
if(!s->budget--) { s->failed_pc=0x0c070568u; return 0; }
r[4]+=0x00000044u;
goto P_0c07056a;
P_0c07056a: /* original 65b3, guest PC 0x0c07056a */
if(!s->budget--) { s->failed_pc=0x0c07056au; return 0; }
r[5]=r[11];
goto P_0c07056c;
P_0c07056c: /* original a002, guest PC 0x0c07056c */
if(!s->budget--) { s->failed_pc=0x0c07056cu; return 0; }
goto P_0c070574;
P_0c07056e: /* original 0009, guest PC 0x0c07056e */
if(!s->budget--) { s->failed_pc=0x0c07056eu; return 0; }
if(!vf3_matrix_family(0x0c070570u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c070570u; return 0; } return 1;
P_0c070574: /* original f049, guest PC 0x0c070574 */
if(!s->budget--) { s->failed_pc=0x0c070574u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070576;
P_0c070576: /* original f149, guest PC 0x0c070576 */
if(!s->budget--) { s->failed_pc=0x0c070576u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070578;
P_0c070578: /* original f249, guest PC 0x0c070578 */
if(!s->budget--) { s->failed_pc=0x0c070578u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07057a;
P_0c07057a: /* original f38d, guest PC 0x0c07057a */
if(!s->budget--) { s->failed_pc=0x0c07057au; return 0; }
fr[3]=0;
goto P_0c07057c;
P_0c07057c: /* original f459, guest PC 0x0c07057c */
if(!s->budget--) { s->failed_pc=0x0c07057cu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07057e;
P_0c07057e: /* original f559, guest PC 0x0c07057e */
if(!s->budget--) { s->failed_pc=0x0c07057eu; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070580;
P_0c070580: /* original f659, guest PC 0x0c070580 */
if(!s->budget--) { s->failed_pc=0x0c070580u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070582;
P_0c070582: /* original f78d, guest PC 0x0c070582 */
if(!s->budget--) { s->failed_pc=0x0c070582u; return 0; }
fr[7]=0;
goto P_0c070584;
P_0c070584: /* original f4ed, guest PC 0x0c070584 */
if(!s->budget--) { s->failed_pc=0x0c070584u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c070586;
P_0c070586: /* original f07c, guest PC 0x0c070586 */
if(!s->budget--) { s->failed_pc=0x0c070586u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c070588;
P_0c070588: /* original f38d, guest PC 0x0c070588 */
if(!s->budget--) { s->failed_pc=0x0c070588u; return 0; }
fr[3]=0;
goto P_0c07058a;
P_0c07058a: /* original f40c, guest PC 0x0c07058a */
if(!s->budget--) { s->failed_pc=0x0c07058au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c07058c;
P_0c07058c: /* original f345, guest PC 0x0c07058c */
if(!s->budget--) { s->failed_pc=0x0c07058cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c07058e;
P_0c07058e: /* original 8902, guest PC 0x0c07058e */
if(!s->budget--) { s->failed_pc=0x0c07058eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070596; }
goto P_0c070590;
P_0c070590: /* original d307, guest PC 0x0c070590 */
if(!s->budget--) { s->failed_pc=0x0c070590u; return 0; }
r[3]=read(ram,0x0c0705b0u,4);
goto P_0c070592;
P_0c070592: /* original 432b, guest PC 0x0c070592 */
if(!s->budget--) { s->failed_pc=0x0c070592u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0705dau: goto P_0c0705da;
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
P_0c070594: /* original 0009, guest PC 0x0c070594 */
if(!s->budget--) { s->failed_pc=0x0c070594u; return 0; }
goto P_0c070596;
P_0c070596: /* original ffc5, guest PC 0x0c070596 */
if(!s->budget--) { s->failed_pc=0x0c070596u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[12]))!=0);
goto P_0c070598;
P_0c070598: /* original 8902, guest PC 0x0c070598 */
if(!s->budget--) { s->failed_pc=0x0c070598u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0705a0; }
goto P_0c07059a;
P_0c07059a: /* original d206, guest PC 0x0c07059a */
if(!s->budget--) { s->failed_pc=0x0c07059au; return 0; }
r[2]=read(ram,0x0c0705b4u,4);
goto P_0c07059c;
P_0c07059c: /* original 422b, guest PC 0x0c07059c */
if(!s->budget--) { s->failed_pc=0x0c07059cu; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0706a4u: goto P_0c0706a4;
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
P_0c07059e: /* original 0009, guest PC 0x0c07059e */
if(!s->budget--) { s->failed_pc=0x0c07059eu; return 0; }
goto P_0c0705a0;
P_0c0705a0: /* original 64f3, guest PC 0x0c0705a0 */
if(!s->budget--) { s->failed_pc=0x0c0705a0u; return 0; }
r[4]=r[15];
goto P_0c0705a2;
P_0c0705a2: /* original 65f3, guest PC 0x0c0705a2 */
if(!s->budget--) { s->failed_pc=0x0c0705a2u; return 0; }
r[5]=r[15];
goto P_0c0705a4;
P_0c0705a4: /* original 7444, guest PC 0x0c0705a4 */
if(!s->budget--) { s->failed_pc=0x0c0705a4u; return 0; }
r[4]+=0x00000044u;
goto P_0c0705a6;
P_0c0705a6: /* original f4fc, guest PC 0x0c0705a6 */
if(!s->budget--) { s->failed_pc=0x0c0705a6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0705a8;
P_0c0705a8: /* original 7544, guest PC 0x0c0705a8 */
if(!s->budget--) { s->failed_pc=0x0c0705a8u; return 0; }
r[5]+=0x00000044u;
goto P_0c0705aa;
P_0c0705aa: /* original a005, guest PC 0x0c0705aa */
if(!s->budget--) { s->failed_pc=0x0c0705aau; return 0; }
goto P_0c0705b8;
P_0c0705ac: /* original 0009, guest PC 0x0c0705ac */
if(!s->budget--) { s->failed_pc=0x0c0705acu; return 0; }
if(!vf3_matrix_family(0x0c0705aeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0705aeu; return 0; } return 1;
P_0c0705b8: /* original f059, guest PC 0x0c0705b8 */
if(!s->budget--) { s->failed_pc=0x0c0705b8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0705ba;
P_0c0705ba: /* original f159, guest PC 0x0c0705ba */
if(!s->budget--) { s->failed_pc=0x0c0705bau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0705bc;
P_0c0705bc: /* original f259, guest PC 0x0c0705bc */
if(!s->budget--) { s->failed_pc=0x0c0705bcu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0705be;
P_0c0705be: /* original f38d, guest PC 0x0c0705be */
if(!s->budget--) { s->failed_pc=0x0c0705beu; return 0; }
fr[3]=0;
goto P_0c0705c0;
P_0c0705c0: /* original f0ed, guest PC 0x0c0705c0 */
if(!s->budget--) { s->failed_pc=0x0c0705c0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0705c2;
P_0c0705c2: /* original f37d, guest PC 0x0c0705c2 */
if(!s->budget--) { s->failed_pc=0x0c0705c2u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0705c4;
P_0c0705c4: /* original f342, guest PC 0x0c0705c4 */
if(!s->budget--) { s->failed_pc=0x0c0705c4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0705c6;
P_0c0705c6: /* original 740c, guest PC 0x0c0705c6 */
if(!s->budget--) { s->failed_pc=0x0c0705c6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0705c8;
P_0c0705c8: /* original f232, guest PC 0x0c0705c8 */
if(!s->budget--) { s->failed_pc=0x0c0705c8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0705ca;
P_0c0705ca: /* original f132, guest PC 0x0c0705ca */
if(!s->budget--) { s->failed_pc=0x0c0705cau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0705cc;
P_0c0705cc: /* original f032, guest PC 0x0c0705cc */
if(!s->budget--) { s->failed_pc=0x0c0705ccu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0705ce;
P_0c0705ce: /* original f42b, guest PC 0x0c0705ce */
if(!s->budget--) { s->failed_pc=0x0c0705ceu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0705d0;
P_0c0705d0: /* original f41b, guest PC 0x0c0705d0 */
if(!s->budget--) { s->failed_pc=0x0c0705d0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0705d2;
P_0c0705d2: /* original f40b, guest PC 0x0c0705d2 */
if(!s->budget--) { s->failed_pc=0x0c0705d2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0705d4;
P_0c0705d4: /* original d206, guest PC 0x0c0705d4 */
if(!s->budget--) { s->failed_pc=0x0c0705d4u; return 0; }
r[2]=read(ram,0x0c0705f0u,4);
goto P_0c0705d6;
P_0c0705d6: /* original 422b, guest PC 0x0c0705d6 */
if(!s->budget--) { s->failed_pc=0x0c0705d6u; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070680u: goto P_0c070680;
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
P_0c0705d8: /* original 0009, guest PC 0x0c0705d8 */
if(!s->budget--) { s->failed_pc=0x0c0705d8u; return 0; }
goto P_0c0705da;
P_0c0705da: /* original fe45, guest PC 0x0c0705da */
if(!s->budget--) { s->failed_pc=0x0c0705dau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[4]))!=0);
goto P_0c0705dc;
P_0c0705dc: /* original 8902, guest PC 0x0c0705dc */
if(!s->budget--) { s->failed_pc=0x0c0705dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0705e4; }
goto P_0c0705de;
P_0c0705de: /* original d205, guest PC 0x0c0705de */
if(!s->budget--) { s->failed_pc=0x0c0705deu; return 0; }
r[2]=read(ram,0x0c0705f4u,4);
goto P_0c0705e0;
P_0c0705e0: /* original 422b, guest PC 0x0c0705e0 */
if(!s->budget--) { s->failed_pc=0x0c0705e0u; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0706a4u: goto P_0c0706a4;
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
P_0c0705e2: /* original 0009, guest PC 0x0c0705e2 */
if(!s->budget--) { s->failed_pc=0x0c0705e2u; return 0; }
goto P_0c0705e4;
P_0c0705e4: /* original 64f3, guest PC 0x0c0705e4 */
if(!s->budget--) { s->failed_pc=0x0c0705e4u; return 0; }
r[4]=r[15];
goto P_0c0705e6;
P_0c0705e6: /* original 7438, guest PC 0x0c0705e6 */
if(!s->budget--) { s->failed_pc=0x0c0705e6u; return 0; }
r[4]+=0x00000038u;
goto P_0c0705e8;
P_0c0705e8: /* original 65b3, guest PC 0x0c0705e8 */
if(!s->budget--) { s->failed_pc=0x0c0705e8u; return 0; }
r[5]=r[11];
goto P_0c0705ea;
P_0c0705ea: /* original a005, guest PC 0x0c0705ea */
if(!s->budget--) { s->failed_pc=0x0c0705eau; return 0; }
goto P_0c0705f8;
P_0c0705ec: /* original 0009, guest PC 0x0c0705ec */
if(!s->budget--) { s->failed_pc=0x0c0705ecu; return 0; }
if(!vf3_matrix_family(0x0c0705eeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0705eeu; return 0; } return 1;
P_0c0705f8: /* original f059, guest PC 0x0c0705f8 */
if(!s->budget--) { s->failed_pc=0x0c0705f8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0705fa;
P_0c0705fa: /* original f159, guest PC 0x0c0705fa */
if(!s->budget--) { s->failed_pc=0x0c0705fau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0705fc;
P_0c0705fc: /* original f259, guest PC 0x0c0705fc */
if(!s->budget--) { s->failed_pc=0x0c0705fcu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0705fe;
P_0c0705fe: /* original 740c, guest PC 0x0c0705fe */
if(!s->budget--) { s->failed_pc=0x0c0705feu; return 0; }
r[4]+=0x0000000cu;
goto P_0c070600;
P_0c070600: /* original f242, guest PC 0x0c070600 */
if(!s->budget--) { s->failed_pc=0x0c070600u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c070602;
P_0c070602: /* original f142, guest PC 0x0c070602 */
if(!s->budget--) { s->failed_pc=0x0c070602u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c070604;
P_0c070604: /* original f042, guest PC 0x0c070604 */
if(!s->budget--) { s->failed_pc=0x0c070604u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c070606;
P_0c070606: /* original f42b, guest PC 0x0c070606 */
if(!s->budget--) { s->failed_pc=0x0c070606u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070608;
P_0c070608: /* original f41b, guest PC 0x0c070608 */
if(!s->budget--) { s->failed_pc=0x0c070608u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07060a;
P_0c07060a: /* original f40b, guest PC 0x0c07060a */
if(!s->budget--) { s->failed_pc=0x0c07060au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07060c;
P_0c07060c: /* original 65f3, guest PC 0x0c07060c */
if(!s->budget--) { s->failed_pc=0x0c07060cu; return 0; }
r[5]=r[15];
goto P_0c07060e;
P_0c07060e: /* original 64f3, guest PC 0x0c07060e */
if(!s->budget--) { s->failed_pc=0x0c07060eu; return 0; }
r[4]=r[15];
goto P_0c070610;
P_0c070610: /* original 66f3, guest PC 0x0c070610 */
if(!s->budget--) { s->failed_pc=0x0c070610u; return 0; }
r[6]=r[15];
goto P_0c070612;
P_0c070612: /* original 7438, guest PC 0x0c070612 */
if(!s->budget--) { s->failed_pc=0x0c070612u; return 0; }
r[4]+=0x00000038u;
goto P_0c070614;
P_0c070614: /* original 7638, guest PC 0x0c070614 */
if(!s->budget--) { s->failed_pc=0x0c070614u; return 0; }
r[6]+=0x00000038u;
goto P_0c070616;
P_0c070616: /* original 7544, guest PC 0x0c070616 */
if(!s->budget--) { s->failed_pc=0x0c070616u; return 0; }
r[5]+=0x00000044u;
goto P_0c070618;
P_0c070618: /* original f059, guest PC 0x0c070618 */
if(!s->budget--) { s->failed_pc=0x0c070618u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07061a;
P_0c07061a: /* original f369, guest PC 0x0c07061a */
if(!s->budget--) { s->failed_pc=0x0c07061au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07061c;
P_0c07061c: /* original f159, guest PC 0x0c07061c */
if(!s->budget--) { s->failed_pc=0x0c07061cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07061e;
P_0c07061e: /* original f469, guest PC 0x0c07061e */
if(!s->budget--) { s->failed_pc=0x0c07061eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070620;
P_0c070620: /* original f031, guest PC 0x0c070620 */
if(!s->budget--) { s->failed_pc=0x0c070620u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070622;
P_0c070622: /* original f258, guest PC 0x0c070622 */
if(!s->budget--) { s->failed_pc=0x0c070622u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070624;
P_0c070624: /* original f568, guest PC 0x0c070624 */
if(!s->budget--) { s->failed_pc=0x0c070624u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070626;
P_0c070626: /* original f141, guest PC 0x0c070626 */
if(!s->budget--) { s->failed_pc=0x0c070626u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070628;
P_0c070628: /* original f251, guest PC 0x0c070628 */
if(!s->budget--) { s->failed_pc=0x0c070628u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c07062a;
P_0c07062a: /* original 7408, guest PC 0x0c07062a */
if(!s->budget--) { s->failed_pc=0x0c07062au; return 0; }
r[4]+=0x00000008u;
goto P_0c07062c;
P_0c07062c: /* original f42a, guest PC 0x0c07062c */
if(!s->budget--) { s->failed_pc=0x0c07062cu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07062e;
P_0c07062e: /* original f41b, guest PC 0x0c07062e */
if(!s->budget--) { s->failed_pc=0x0c07062eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070630;
P_0c070630: /* original f40b, guest PC 0x0c070630 */
if(!s->budget--) { s->failed_pc=0x0c070630u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070632;
P_0c070632: /* original 0009, guest PC 0x0c070632 */
if(!s->budget--) { s->failed_pc=0x0c070632u; return 0; }
goto P_0c070634;
P_0c070634: /* original e010, guest PC 0x0c070634 */
if(!s->budget--) { s->failed_pc=0x0c070634u; return 0; }
r[0]=0x00000010u;
goto P_0c070636;
P_0c070636: /* original f4fc, guest PC 0x0c070636 */
if(!s->budget--) { s->failed_pc=0x0c070636u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070638;
P_0c070638: /* original f3f6, guest PC 0x0c070638 */
if(!s->budget--) { s->failed_pc=0x0c070638u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c07063a;
P_0c07063a: /* original 64f3, guest PC 0x0c07063a */
if(!s->budget--) { s->failed_pc=0x0c07063au; return 0; }
r[4]=r[15];
goto P_0c07063c;
P_0c07063c: /* original 65f3, guest PC 0x0c07063c */
if(!s->budget--) { s->failed_pc=0x0c07063cu; return 0; }
r[5]=r[15];
goto P_0c07063e;
P_0c07063e: /* original 7438, guest PC 0x0c07063e */
if(!s->budget--) { s->failed_pc=0x0c07063eu; return 0; }
r[4]+=0x00000038u;
goto P_0c070640;
P_0c070640: /* original f431, guest PC 0x0c070640 */
if(!s->budget--) { s->failed_pc=0x0c070640u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c070642;
P_0c070642: /* original 7538, guest PC 0x0c070642 */
if(!s->budget--) { s->failed_pc=0x0c070642u; return 0; }
r[5]+=0x00000038u;
goto P_0c070644;
P_0c070644: /* original f059, guest PC 0x0c070644 */
if(!s->budget--) { s->failed_pc=0x0c070644u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070646;
P_0c070646: /* original f159, guest PC 0x0c070646 */
if(!s->budget--) { s->failed_pc=0x0c070646u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070648;
P_0c070648: /* original f259, guest PC 0x0c070648 */
if(!s->budget--) { s->failed_pc=0x0c070648u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07064a;
P_0c07064a: /* original f38d, guest PC 0x0c07064a */
if(!s->budget--) { s->failed_pc=0x0c07064au; return 0; }
fr[3]=0;
goto P_0c07064c;
P_0c07064c: /* original f0ed, guest PC 0x0c07064c */
if(!s->budget--) { s->failed_pc=0x0c07064cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07064e;
P_0c07064e: /* original f37d, guest PC 0x0c07064e */
if(!s->budget--) { s->failed_pc=0x0c07064eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070650;
P_0c070650: /* original f342, guest PC 0x0c070650 */
if(!s->budget--) { s->failed_pc=0x0c070650u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070652;
P_0c070652: /* original 740c, guest PC 0x0c070652 */
if(!s->budget--) { s->failed_pc=0x0c070652u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070654;
P_0c070654: /* original f232, guest PC 0x0c070654 */
if(!s->budget--) { s->failed_pc=0x0c070654u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070656;
P_0c070656: /* original f132, guest PC 0x0c070656 */
if(!s->budget--) { s->failed_pc=0x0c070656u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070658;
P_0c070658: /* original f032, guest PC 0x0c070658 */
if(!s->budget--) { s->failed_pc=0x0c070658u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c07065a;
P_0c07065a: /* original f42b, guest PC 0x0c07065a */
if(!s->budget--) { s->failed_pc=0x0c07065au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07065c;
P_0c07065c: /* original f41b, guest PC 0x0c07065c */
if(!s->budget--) { s->failed_pc=0x0c07065cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07065e;
P_0c07065e: /* original f40b, guest PC 0x0c07065e */
if(!s->budget--) { s->failed_pc=0x0c07065eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070660;
P_0c070660: /* original 64f3, guest PC 0x0c070660 */
if(!s->budget--) { s->failed_pc=0x0c070660u; return 0; }
r[4]=r[15];
goto P_0c070662;
P_0c070662: /* original 65f3, guest PC 0x0c070662 */
if(!s->budget--) { s->failed_pc=0x0c070662u; return 0; }
r[5]=r[15];
goto P_0c070664;
P_0c070664: /* original 7444, guest PC 0x0c070664 */
if(!s->budget--) { s->failed_pc=0x0c070664u; return 0; }
r[4]+=0x00000044u;
goto P_0c070666;
P_0c070666: /* original 7538, guest PC 0x0c070666 */
if(!s->budget--) { s->failed_pc=0x0c070666u; return 0; }
r[5]+=0x00000038u;
goto P_0c070668;
P_0c070668: /* original f049, guest PC 0x0c070668 */
if(!s->budget--) { s->failed_pc=0x0c070668u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07066a;
P_0c07066a: /* original f359, guest PC 0x0c07066a */
if(!s->budget--) { s->failed_pc=0x0c07066au; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07066c;
P_0c07066c: /* original f149, guest PC 0x0c07066c */
if(!s->budget--) { s->failed_pc=0x0c07066cu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07066e;
P_0c07066e: /* original f459, guest PC 0x0c07066e */
if(!s->budget--) { s->failed_pc=0x0c07066eu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070670;
P_0c070670: /* original f249, guest PC 0x0c070670 */
if(!s->budget--) { s->failed_pc=0x0c070670u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070672;
P_0c070672: /* original f559, guest PC 0x0c070672 */
if(!s->budget--) { s->failed_pc=0x0c070672u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070674;
P_0c070674: /* original f030, guest PC 0x0c070674 */
if(!s->budget--) { s->failed_pc=0x0c070674u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070676;
P_0c070676: /* original f250, guest PC 0x0c070676 */
if(!s->budget--) { s->failed_pc=0x0c070676u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070678;
P_0c070678: /* original f140, guest PC 0x0c070678 */
if(!s->budget--) { s->failed_pc=0x0c070678u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c07067a;
P_0c07067a: /* original f42b, guest PC 0x0c07067a */
if(!s->budget--) { s->failed_pc=0x0c07067au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07067c;
P_0c07067c: /* original f41b, guest PC 0x0c07067c */
if(!s->budget--) { s->failed_pc=0x0c07067cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07067e;
P_0c07067e: /* original f40b, guest PC 0x0c07067e */
if(!s->budget--) { s->failed_pc=0x0c07067eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070680;
P_0c070680: /* original 65f3, guest PC 0x0c070680 */
if(!s->budget--) { s->failed_pc=0x0c070680u; return 0; }
r[5]=r[15];
goto P_0c070682;
P_0c070682: /* original 64d3, guest PC 0x0c070682 */
if(!s->budget--) { s->failed_pc=0x0c070682u; return 0; }
r[4]=r[13];
goto P_0c070684;
P_0c070684: /* original 7544, guest PC 0x0c070684 */
if(!s->budget--) { s->failed_pc=0x0c070684u; return 0; }
r[5]+=0x00000044u;
goto P_0c070686;
P_0c070686: /* original 66a3, guest PC 0x0c070686 */
if(!s->budget--) { s->failed_pc=0x0c070686u; return 0; }
r[6]=r[10];
goto P_0c070688;
P_0c070688: /* original f059, guest PC 0x0c070688 */
if(!s->budget--) { s->failed_pc=0x0c070688u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07068a;
P_0c07068a: /* original f369, guest PC 0x0c07068a */
if(!s->budget--) { s->failed_pc=0x0c07068au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07068c;
P_0c07068c: /* original f159, guest PC 0x0c07068c */
if(!s->budget--) { s->failed_pc=0x0c07068cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07068e;
P_0c07068e: /* original f469, guest PC 0x0c07068e */
if(!s->budget--) { s->failed_pc=0x0c07068eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070690;
P_0c070690: /* original f259, guest PC 0x0c070690 */
if(!s->budget--) { s->failed_pc=0x0c070690u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070692;
P_0c070692: /* original f569, guest PC 0x0c070692 */
if(!s->budget--) { s->failed_pc=0x0c070692u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070694;
P_0c070694: /* original 740c, guest PC 0x0c070694 */
if(!s->budget--) { s->failed_pc=0x0c070694u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070696;
P_0c070696: /* original f030, guest PC 0x0c070696 */
if(!s->budget--) { s->failed_pc=0x0c070696u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070698;
P_0c070698: /* original f250, guest PC 0x0c070698 */
if(!s->budget--) { s->failed_pc=0x0c070698u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c07069a;
P_0c07069a: /* original f140, guest PC 0x0c07069a */
if(!s->budget--) { s->failed_pc=0x0c07069au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c07069c;
P_0c07069c: /* original f42b, guest PC 0x0c07069c */
if(!s->budget--) { s->failed_pc=0x0c07069cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07069e;
P_0c07069e: /* original f41b, guest PC 0x0c07069e */
if(!s->budget--) { s->failed_pc=0x0c07069eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0706a0;
P_0c0706a0: /* original f40b, guest PC 0x0c0706a0 */
if(!s->budget--) { s->failed_pc=0x0c0706a0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0706a2;
P_0c0706a2: /* original 0009, guest PC 0x0c0706a2 */
if(!s->budget--) { s->failed_pc=0x0c0706a2u; return 0; }
goto P_0c0706a4;
P_0c0706a4: /* original 64f3, guest PC 0x0c0706a4 */
if(!s->budget--) { s->failed_pc=0x0c0706a4u; return 0; }
r[4]=r[15];
goto P_0c0706a6;
P_0c0706a6: /* original 7444, guest PC 0x0c0706a6 */
if(!s->budget--) { s->failed_pc=0x0c0706a6u; return 0; }
r[4]+=0x00000044u;
goto P_0c0706a8;
P_0c0706a8: /* original 6693, guest PC 0x0c0706a8 */
if(!s->budget--) { s->failed_pc=0x0c0706a8u; return 0; }
r[6]=r[9];
goto P_0c0706aa;
P_0c0706aa: /* original 65d3, guest PC 0x0c0706aa */
if(!s->budget--) { s->failed_pc=0x0c0706aau; return 0; }
r[5]=r[13];
goto P_0c0706ac;
P_0c0706ac: /* original f059, guest PC 0x0c0706ac */
if(!s->budget--) { s->failed_pc=0x0c0706acu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0706ae;
P_0c0706ae: /* original f369, guest PC 0x0c0706ae */
if(!s->budget--) { s->failed_pc=0x0c0706aeu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0706b0;
P_0c0706b0: /* original f159, guest PC 0x0c0706b0 */
if(!s->budget--) { s->failed_pc=0x0c0706b0u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0706b2;
P_0c0706b2: /* original f469, guest PC 0x0c0706b2 */
if(!s->budget--) { s->failed_pc=0x0c0706b2u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0706b4;
P_0c0706b4: /* original f031, guest PC 0x0c0706b4 */
if(!s->budget--) { s->failed_pc=0x0c0706b4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0706b6;
P_0c0706b6: /* original f258, guest PC 0x0c0706b6 */
if(!s->budget--) { s->failed_pc=0x0c0706b6u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0706b8;
P_0c0706b8: /* original f568, guest PC 0x0c0706b8 */
if(!s->budget--) { s->failed_pc=0x0c0706b8u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0706ba;
P_0c0706ba: /* original f141, guest PC 0x0c0706ba */
if(!s->budget--) { s->failed_pc=0x0c0706bau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0706bc;
P_0c0706bc: /* original f251, guest PC 0x0c0706bc */
if(!s->budget--) { s->failed_pc=0x0c0706bcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0706be;
P_0c0706be: /* original 7408, guest PC 0x0c0706be */
if(!s->budget--) { s->failed_pc=0x0c0706beu; return 0; }
r[4]+=0x00000008u;
goto P_0c0706c0;
P_0c0706c0: /* original f42a, guest PC 0x0c0706c0 */
if(!s->budget--) { s->failed_pc=0x0c0706c0u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0706c2;
P_0c0706c2: /* original f41b, guest PC 0x0c0706c2 */
if(!s->budget--) { s->failed_pc=0x0c0706c2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0706c4;
P_0c0706c4: /* original f40b, guest PC 0x0c0706c4 */
if(!s->budget--) { s->failed_pc=0x0c0706c4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0706c6;
P_0c0706c6: /* original 0009, guest PC 0x0c0706c6 */
if(!s->budget--) { s->failed_pc=0x0c0706c6u; return 0; }
goto P_0c0706c8;
P_0c0706c8: /* original 64f3, guest PC 0x0c0706c8 */
if(!s->budget--) { s->failed_pc=0x0c0706c8u; return 0; }
r[4]=r[15];
goto P_0c0706ca;
P_0c0706ca: /* original 7444, guest PC 0x0c0706ca */
if(!s->budget--) { s->failed_pc=0x0c0706cau; return 0; }
r[4]+=0x00000044u;
goto P_0c0706cc;
P_0c0706cc: /* original f049, guest PC 0x0c0706cc */
if(!s->budget--) { s->failed_pc=0x0c0706ccu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0706ce;
P_0c0706ce: /* original f149, guest PC 0x0c0706ce */
if(!s->budget--) { s->failed_pc=0x0c0706ceu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0706d0;
P_0c0706d0: /* original f249, guest PC 0x0c0706d0 */
if(!s->budget--) { s->failed_pc=0x0c0706d0u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0706d2;
P_0c0706d2: /* original f38d, guest PC 0x0c0706d2 */
if(!s->budget--) { s->failed_pc=0x0c0706d2u; return 0; }
fr[3]=0;
goto P_0c0706d4;
P_0c0706d4: /* original f0ed, guest PC 0x0c0706d4 */
if(!s->budget--) { s->failed_pc=0x0c0706d4u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0706d6;
P_0c0706d6: /* original f03c, guest PC 0x0c0706d6 */
if(!s->budget--) { s->failed_pc=0x0c0706d6u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c0706d8;
P_0c0706d8: /* original f06d, guest PC 0x0c0706d8 */
if(!s->budget--) { s->failed_pc=0x0c0706d8u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c0706da;
P_0c0706da: /* original 0009, guest PC 0x0c0706da */
if(!s->budget--) { s->failed_pc=0x0c0706dau; return 0; }
goto P_0c0706dc;
P_0c0706dc: /* original f38d, guest PC 0x0c0706dc */
if(!s->budget--) { s->failed_pc=0x0c0706dcu; return 0; }
fr[3]=0;
goto P_0c0706de;
P_0c0706de: /* original f035, guest PC 0x0c0706de */
if(!s->budget--) { s->failed_pc=0x0c0706deu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c0706e0;
P_0c0706e0: /* original e008, guest PC 0x0c0706e0 */
if(!s->budget--) { s->failed_pc=0x0c0706e0u; return 0; }
r[0]=0x00000008u;
goto P_0c0706e2;
P_0c0706e2: /* original 8d03, guest PC 0x0c0706e2 */
if(!s->budget--) { s->failed_pc=0x0c0706e2u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(cond) { goto P_0c0706ec; }
goto P_0c0706e6;
P_0c0706e4: /* original ff07, guest PC 0x0c0706e4 */
if(!s->budget--) { s->failed_pc=0x0c0706e4u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0706e6;
P_0c0706e6: /* original d304, guest PC 0x0c0706e6 */
if(!s->budget--) { s->failed_pc=0x0c0706e6u; return 0; }
r[3]=read(ram,0x0c0706f8u,4);
goto P_0c0706e8;
P_0c0706e8: /* original 432b, guest PC 0x0c0706e8 */
if(!s->budget--) { s->failed_pc=0x0c0706e8u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070878u: goto P_0c070878;
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
P_0c0706ea: /* original 0009, guest PC 0x0c0706ea */
if(!s->budget--) { s->failed_pc=0x0c0706eau; return 0; }
goto P_0c0706ec;
P_0c0706ec: /* original 64f3, guest PC 0x0c0706ec */
if(!s->budget--) { s->failed_pc=0x0c0706ecu; return 0; }
r[4]=r[15];
goto P_0c0706ee;
P_0c0706ee: /* original 7444, guest PC 0x0c0706ee */
if(!s->budget--) { s->failed_pc=0x0c0706eeu; return 0; }
r[4]+=0x00000044u;
goto P_0c0706f0;
P_0c0706f0: /* original 65c3, guest PC 0x0c0706f0 */
if(!s->budget--) { s->failed_pc=0x0c0706f0u; return 0; }
r[5]=r[12];
goto P_0c0706f2;
P_0c0706f2: /* original a003, guest PC 0x0c0706f2 */
if(!s->budget--) { s->failed_pc=0x0c0706f2u; return 0; }
goto P_0c0706fc;
P_0c0706f4: /* original 0009, guest PC 0x0c0706f4 */
if(!s->budget--) { s->failed_pc=0x0c0706f4u; return 0; }
if(!vf3_matrix_family(0x0c0706f6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0706f6u; return 0; } return 1;
P_0c0706fc: /* original f049, guest PC 0x0c0706fc */
if(!s->budget--) { s->failed_pc=0x0c0706fcu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0706fe;
P_0c0706fe: /* original f549, guest PC 0x0c0706fe */
if(!s->budget--) { s->failed_pc=0x0c0706feu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070700;
P_0c070700: /* original f648, guest PC 0x0c070700 */
if(!s->budget--) { s->failed_pc=0x0c070700u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c070702;
P_0c070702: /* original f859, guest PC 0x0c070702 */
if(!s->budget--) { s->failed_pc=0x0c070702u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070704;
P_0c070704: /* original f959, guest PC 0x0c070704 */
if(!s->budget--) { s->failed_pc=0x0c070704u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070706;
P_0c070706: /* original fa58, guest PC 0x0c070706 */
if(!s->budget--) { s->failed_pc=0x0c070706u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c070708;
P_0c070708: /* original f35c, guest PC 0x0c070708 */
if(!s->budget--) { s->failed_pc=0x0c070708u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c07070a;
P_0c07070a: /* original f382, guest PC 0x0c07070a */
if(!s->budget--) { s->failed_pc=0x0c07070au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c07070c;
P_0c07070c: /* original f20c, guest PC 0x0c07070c */
if(!s->budget--) { s->failed_pc=0x0c07070cu; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c07070e;
P_0c07070e: /* original f2a2, guest PC 0x0c07070e */
if(!s->budget--) { s->failed_pc=0x0c07070eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c070710;
P_0c070710: /* original f16c, guest PC 0x0c070710 */
if(!s->budget--) { s->failed_pc=0x0c070710u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c070712;
P_0c070712: /* original f192, guest PC 0x0c070712 */
if(!s->budget--) { s->failed_pc=0x0c070712u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c070714;
P_0c070714: /* original f34d, guest PC 0x0c070714 */
if(!s->budget--) { s->failed_pc=0x0c070714u; return 0; }
fr[3]^=0x80000000u;
goto P_0c070716;
P_0c070716: /* original f39e, guest PC 0x0c070716 */
if(!s->budget--) { s->failed_pc=0x0c070716u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c070718;
P_0c070718: /* original f24d, guest PC 0x0c070718 */
if(!s->budget--) { s->failed_pc=0x0c070718u; return 0; }
fr[2]^=0x80000000u;
goto P_0c07071a;
P_0c07071a: /* original f06c, guest PC 0x0c07071a */
if(!s->budget--) { s->failed_pc=0x0c07071au; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c07071c;
P_0c07071c: /* original f28e, guest PC 0x0c07071c */
if(!s->budget--) { s->failed_pc=0x0c07071cu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c07071e;
P_0c07071e: /* original f14d, guest PC 0x0c07071e */
if(!s->budget--) { s->failed_pc=0x0c07071eu; return 0; }
fr[1]^=0x80000000u;
goto P_0c070720;
P_0c070720: /* original f05c, guest PC 0x0c070720 */
if(!s->budget--) { s->failed_pc=0x0c070720u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c070722;
P_0c070722: /* original f1ae, guest PC 0x0c070722 */
if(!s->budget--) { s->failed_pc=0x0c070722u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c070724;
P_0c070724: /* original f08d, guest PC 0x0c070724 */
if(!s->budget--) { s->failed_pc=0x0c070724u; return 0; }
fr[0]=0;
goto P_0c070726;
P_0c070726: /* original f0ed, guest PC 0x0c070726 */
if(!s->budget--) { s->failed_pc=0x0c070726u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070728;
P_0c070728: /* original f03c, guest PC 0x0c070728 */
if(!s->budget--) { s->failed_pc=0x0c070728u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c07072a;
P_0c07072a: /* original f06d, guest PC 0x0c07072a */
if(!s->budget--) { s->failed_pc=0x0c07072au; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c07072c;
P_0c07072c: /* original fc0c, guest PC 0x0c07072c */
if(!s->budget--) { s->failed_pc=0x0c07072cu; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c07072e;
P_0c07072e: /* original ffc5, guest PC 0x0c07072e */
if(!s->budget--) { s->failed_pc=0x0c07072eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[12]))!=0);
goto P_0c070730;
P_0c070730: /* original 8902, guest PC 0x0c070730 */
if(!s->budget--) { s->failed_pc=0x0c070730u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070738; }
goto P_0c070732;
P_0c070732: /* original d304, guest PC 0x0c070732 */
if(!s->budget--) { s->failed_pc=0x0c070732u; return 0; }
r[3]=read(ram,0x0c070744u,4);
goto P_0c070734;
P_0c070734: /* original 432b, guest PC 0x0c070734 */
if(!s->budget--) { s->failed_pc=0x0c070734u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070878u: goto P_0c070878;
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
P_0c070736: /* original 0009, guest PC 0x0c070736 */
if(!s->budget--) { s->failed_pc=0x0c070736u; return 0; }
goto P_0c070738;
P_0c070738: /* original 64f3, guest PC 0x0c070738 */
if(!s->budget--) { s->failed_pc=0x0c070738u; return 0; }
r[4]=r[15];
goto P_0c07073a;
P_0c07073a: /* original 7444, guest PC 0x0c07073a */
if(!s->budget--) { s->failed_pc=0x0c07073au; return 0; }
r[4]+=0x00000044u;
goto P_0c07073c;
P_0c07073c: /* original 65c3, guest PC 0x0c07073c */
if(!s->budget--) { s->failed_pc=0x0c07073cu; return 0; }
r[5]=r[12];
goto P_0c07073e;
P_0c07073e: /* original a003, guest PC 0x0c07073e */
if(!s->budget--) { s->failed_pc=0x0c07073eu; return 0; }
goto P_0c070748;
P_0c070740: /* original 0009, guest PC 0x0c070740 */
if(!s->budget--) { s->failed_pc=0x0c070740u; return 0; }
if(!vf3_matrix_family(0x0c070742u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c070742u; return 0; } return 1;
P_0c070748: /* original f049, guest PC 0x0c070748 */
if(!s->budget--) { s->failed_pc=0x0c070748u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07074a;
P_0c07074a: /* original f149, guest PC 0x0c07074a */
if(!s->budget--) { s->failed_pc=0x0c07074au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07074c;
P_0c07074c: /* original f249, guest PC 0x0c07074c */
if(!s->budget--) { s->failed_pc=0x0c07074cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07074e;
P_0c07074e: /* original f38d, guest PC 0x0c07074e */
if(!s->budget--) { s->failed_pc=0x0c07074eu; return 0; }
fr[3]=0;
goto P_0c070750;
P_0c070750: /* original f459, guest PC 0x0c070750 */
if(!s->budget--) { s->failed_pc=0x0c070750u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070752;
P_0c070752: /* original f559, guest PC 0x0c070752 */
if(!s->budget--) { s->failed_pc=0x0c070752u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070754;
P_0c070754: /* original f659, guest PC 0x0c070754 */
if(!s->budget--) { s->failed_pc=0x0c070754u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070756;
P_0c070756: /* original f78d, guest PC 0x0c070756 */
if(!s->budget--) { s->failed_pc=0x0c070756u; return 0; }
fr[7]=0;
goto P_0c070758;
P_0c070758: /* original f4ed, guest PC 0x0c070758 */
if(!s->budget--) { s->failed_pc=0x0c070758u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c07075a;
P_0c07075a: /* original f07c, guest PC 0x0c07075a */
if(!s->budget--) { s->failed_pc=0x0c07075au; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c07075c;
P_0c07075c: /* original f38d, guest PC 0x0c07075c */
if(!s->budget--) { s->failed_pc=0x0c07075cu; return 0; }
fr[3]=0;
goto P_0c07075e;
P_0c07075e: /* original f40c, guest PC 0x0c07075e */
if(!s->budget--) { s->failed_pc=0x0c07075eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c070760;
P_0c070760: /* original f345, guest PC 0x0c070760 */
if(!s->budget--) { s->failed_pc=0x0c070760u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c070762;
P_0c070762: /* original 8902, guest PC 0x0c070762 */
if(!s->budget--) { s->failed_pc=0x0c070762u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07076a; }
goto P_0c070764;
P_0c070764: /* original d308, guest PC 0x0c070764 */
if(!s->budget--) { s->failed_pc=0x0c070764u; return 0; }
r[3]=read(ram,0x0c070788u,4);
goto P_0c070766;
P_0c070766: /* original 432b, guest PC 0x0c070766 */
if(!s->budget--) { s->failed_pc=0x0c070766u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0707b2u: goto P_0c0707b2;
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
P_0c070768: /* original 0009, guest PC 0x0c070768 */
if(!s->budget--) { s->failed_pc=0x0c070768u; return 0; }
goto P_0c07076a;
P_0c07076a: /* original e008, guest PC 0x0c07076a */
if(!s->budget--) { s->failed_pc=0x0c07076au; return 0; }
r[0]=0x00000008u;
goto P_0c07076c;
P_0c07076c: /* original f3f6, guest PC 0x0c07076c */
if(!s->budget--) { s->failed_pc=0x0c07076cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c07076e;
P_0c07076e: /* original ff35, guest PC 0x0c07076e */
if(!s->budget--) { s->failed_pc=0x0c07076eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c070770;
P_0c070770: /* original 8902, guest PC 0x0c070770 */
if(!s->budget--) { s->failed_pc=0x0c070770u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070778; }
goto P_0c070772;
P_0c070772: /* original d306, guest PC 0x0c070772 */
if(!s->budget--) { s->failed_pc=0x0c070772u; return 0; }
r[3]=read(ram,0x0c07078cu,4);
goto P_0c070774;
P_0c070774: /* original 432b, guest PC 0x0c070774 */
if(!s->budget--) { s->failed_pc=0x0c070774u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070878u: goto P_0c070878;
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
P_0c070776: /* original 0009, guest PC 0x0c070776 */
if(!s->budget--) { s->failed_pc=0x0c070776u; return 0; }
goto P_0c070778;
P_0c070778: /* original 64f3, guest PC 0x0c070778 */
if(!s->budget--) { s->failed_pc=0x0c070778u; return 0; }
r[4]=r[15];
goto P_0c07077a;
P_0c07077a: /* original 65f3, guest PC 0x0c07077a */
if(!s->budget--) { s->failed_pc=0x0c07077au; return 0; }
r[5]=r[15];
goto P_0c07077c;
P_0c07077c: /* original 7444, guest PC 0x0c07077c */
if(!s->budget--) { s->failed_pc=0x0c07077cu; return 0; }
r[4]+=0x00000044u;
goto P_0c07077e;
P_0c07077e: /* original f4fc, guest PC 0x0c07077e */
if(!s->budget--) { s->failed_pc=0x0c07077eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070780;
P_0c070780: /* original 7544, guest PC 0x0c070780 */
if(!s->budget--) { s->failed_pc=0x0c070780u; return 0; }
r[5]+=0x00000044u;
goto P_0c070782;
P_0c070782: /* original a005, guest PC 0x0c070782 */
if(!s->budget--) { s->failed_pc=0x0c070782u; return 0; }
goto P_0c070790;
P_0c070784: /* original 0009, guest PC 0x0c070784 */
if(!s->budget--) { s->failed_pc=0x0c070784u; return 0; }
if(!vf3_matrix_family(0x0c070786u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c070786u; return 0; } return 1;
P_0c070790: /* original f059, guest PC 0x0c070790 */
if(!s->budget--) { s->failed_pc=0x0c070790u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070792;
P_0c070792: /* original f159, guest PC 0x0c070792 */
if(!s->budget--) { s->failed_pc=0x0c070792u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070794;
P_0c070794: /* original f259, guest PC 0x0c070794 */
if(!s->budget--) { s->failed_pc=0x0c070794u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070796;
P_0c070796: /* original f38d, guest PC 0x0c070796 */
if(!s->budget--) { s->failed_pc=0x0c070796u; return 0; }
fr[3]=0;
goto P_0c070798;
P_0c070798: /* original f0ed, guest PC 0x0c070798 */
if(!s->budget--) { s->failed_pc=0x0c070798u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07079a;
P_0c07079a: /* original f37d, guest PC 0x0c07079a */
if(!s->budget--) { s->failed_pc=0x0c07079au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c07079c;
P_0c07079c: /* original f342, guest PC 0x0c07079c */
if(!s->budget--) { s->failed_pc=0x0c07079cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c07079e;
P_0c07079e: /* original 740c, guest PC 0x0c07079e */
if(!s->budget--) { s->failed_pc=0x0c07079eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0707a0;
P_0c0707a0: /* original f232, guest PC 0x0c0707a0 */
if(!s->budget--) { s->failed_pc=0x0c0707a0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0707a2;
P_0c0707a2: /* original f132, guest PC 0x0c0707a2 */
if(!s->budget--) { s->failed_pc=0x0c0707a2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0707a4;
P_0c0707a4: /* original f032, guest PC 0x0c0707a4 */
if(!s->budget--) { s->failed_pc=0x0c0707a4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0707a6;
P_0c0707a6: /* original f42b, guest PC 0x0c0707a6 */
if(!s->budget--) { s->failed_pc=0x0c0707a6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0707a8;
P_0c0707a8: /* original f41b, guest PC 0x0c0707a8 */
if(!s->budget--) { s->failed_pc=0x0c0707a8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0707aa;
P_0c0707aa: /* original f40b, guest PC 0x0c0707aa */
if(!s->budget--) { s->failed_pc=0x0c0707aau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0707ac;
P_0c0707ac: /* original d306, guest PC 0x0c0707ac */
if(!s->budget--) { s->failed_pc=0x0c0707acu; return 0; }
r[3]=read(ram,0x0c0707c8u,4);
goto P_0c0707ae;
P_0c0707ae: /* original 432b, guest PC 0x0c0707ae */
if(!s->budget--) { s->failed_pc=0x0c0707aeu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070854u: goto P_0c070854;
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
P_0c0707b0: /* original 0009, guest PC 0x0c0707b0 */
if(!s->budget--) { s->failed_pc=0x0c0707b0u; return 0; }
goto P_0c0707b2;
P_0c0707b2: /* original fe45, guest PC 0x0c0707b2 */
if(!s->budget--) { s->failed_pc=0x0c0707b2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[4]))!=0);
goto P_0c0707b4;
P_0c0707b4: /* original 8902, guest PC 0x0c0707b4 */
if(!s->budget--) { s->failed_pc=0x0c0707b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0707bc; }
goto P_0c0707b6;
P_0c0707b6: /* original d305, guest PC 0x0c0707b6 */
if(!s->budget--) { s->failed_pc=0x0c0707b6u; return 0; }
r[3]=read(ram,0x0c0707ccu,4);
goto P_0c0707b8;
P_0c0707b8: /* original 432b, guest PC 0x0c0707b8 */
if(!s->budget--) { s->failed_pc=0x0c0707b8u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070878u: goto P_0c070878;
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
P_0c0707ba: /* original 0009, guest PC 0x0c0707ba */
if(!s->budget--) { s->failed_pc=0x0c0707bau; return 0; }
goto P_0c0707bc;
P_0c0707bc: /* original 64f3, guest PC 0x0c0707bc */
if(!s->budget--) { s->failed_pc=0x0c0707bcu; return 0; }
r[4]=r[15];
goto P_0c0707be;
P_0c0707be: /* original 7438, guest PC 0x0c0707be */
if(!s->budget--) { s->failed_pc=0x0c0707beu; return 0; }
r[4]+=0x00000038u;
goto P_0c0707c0;
P_0c0707c0: /* original 65c3, guest PC 0x0c0707c0 */
if(!s->budget--) { s->failed_pc=0x0c0707c0u; return 0; }
r[5]=r[12];
goto P_0c0707c2;
P_0c0707c2: /* original a005, guest PC 0x0c0707c2 */
if(!s->budget--) { s->failed_pc=0x0c0707c2u; return 0; }
goto P_0c0707d0;
P_0c0707c4: /* original 0009, guest PC 0x0c0707c4 */
if(!s->budget--) { s->failed_pc=0x0c0707c4u; return 0; }
if(!vf3_matrix_family(0x0c0707c6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0707c6u; return 0; } return 1;
P_0c0707d0: /* original f059, guest PC 0x0c0707d0 */
if(!s->budget--) { s->failed_pc=0x0c0707d0u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0707d2;
P_0c0707d2: /* original f159, guest PC 0x0c0707d2 */
if(!s->budget--) { s->failed_pc=0x0c0707d2u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0707d4;
P_0c0707d4: /* original f259, guest PC 0x0c0707d4 */
if(!s->budget--) { s->failed_pc=0x0c0707d4u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0707d6;
P_0c0707d6: /* original 740c, guest PC 0x0c0707d6 */
if(!s->budget--) { s->failed_pc=0x0c0707d6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0707d8;
P_0c0707d8: /* original f242, guest PC 0x0c0707d8 */
if(!s->budget--) { s->failed_pc=0x0c0707d8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c0707da;
P_0c0707da: /* original f142, guest PC 0x0c0707da */
if(!s->budget--) { s->failed_pc=0x0c0707dau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c0707dc;
P_0c0707dc: /* original f042, guest PC 0x0c0707dc */
if(!s->budget--) { s->failed_pc=0x0c0707dcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c0707de;
P_0c0707de: /* original f42b, guest PC 0x0c0707de */
if(!s->budget--) { s->failed_pc=0x0c0707deu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0707e0;
P_0c0707e0: /* original f41b, guest PC 0x0c0707e0 */
if(!s->budget--) { s->failed_pc=0x0c0707e0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0707e2;
P_0c0707e2: /* original f40b, guest PC 0x0c0707e2 */
if(!s->budget--) { s->failed_pc=0x0c0707e2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0707e4;
P_0c0707e4: /* original 65f3, guest PC 0x0c0707e4 */
if(!s->budget--) { s->failed_pc=0x0c0707e4u; return 0; }
r[5]=r[15];
goto P_0c0707e6;
P_0c0707e6: /* original 64f3, guest PC 0x0c0707e6 */
if(!s->budget--) { s->failed_pc=0x0c0707e6u; return 0; }
r[4]=r[15];
goto P_0c0707e8;
P_0c0707e8: /* original 66f3, guest PC 0x0c0707e8 */
if(!s->budget--) { s->failed_pc=0x0c0707e8u; return 0; }
r[6]=r[15];
goto P_0c0707ea;
P_0c0707ea: /* original 7438, guest PC 0x0c0707ea */
if(!s->budget--) { s->failed_pc=0x0c0707eau; return 0; }
r[4]+=0x00000038u;
goto P_0c0707ec;
P_0c0707ec: /* original 7638, guest PC 0x0c0707ec */
if(!s->budget--) { s->failed_pc=0x0c0707ecu; return 0; }
r[6]+=0x00000038u;
goto P_0c0707ee;
P_0c0707ee: /* original 7544, guest PC 0x0c0707ee */
if(!s->budget--) { s->failed_pc=0x0c0707eeu; return 0; }
r[5]+=0x00000044u;
goto P_0c0707f0;
P_0c0707f0: /* original f059, guest PC 0x0c0707f0 */
if(!s->budget--) { s->failed_pc=0x0c0707f0u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0707f2;
P_0c0707f2: /* original f369, guest PC 0x0c0707f2 */
if(!s->budget--) { s->failed_pc=0x0c0707f2u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0707f4;
P_0c0707f4: /* original f159, guest PC 0x0c0707f4 */
if(!s->budget--) { s->failed_pc=0x0c0707f4u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0707f6;
P_0c0707f6: /* original f469, guest PC 0x0c0707f6 */
if(!s->budget--) { s->failed_pc=0x0c0707f6u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0707f8;
P_0c0707f8: /* original f031, guest PC 0x0c0707f8 */
if(!s->budget--) { s->failed_pc=0x0c0707f8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0707fa;
P_0c0707fa: /* original f258, guest PC 0x0c0707fa */
if(!s->budget--) { s->failed_pc=0x0c0707fau; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0707fc;
P_0c0707fc: /* original f568, guest PC 0x0c0707fc */
if(!s->budget--) { s->failed_pc=0x0c0707fcu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0707fe;
P_0c0707fe: /* original f141, guest PC 0x0c0707fe */
if(!s->budget--) { s->failed_pc=0x0c0707feu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070800;
P_0c070800: /* original f251, guest PC 0x0c070800 */
if(!s->budget--) { s->failed_pc=0x0c070800u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070802;
P_0c070802: /* original 7408, guest PC 0x0c070802 */
if(!s->budget--) { s->failed_pc=0x0c070802u; return 0; }
r[4]+=0x00000008u;
goto P_0c070804;
P_0c070804: /* original f42a, guest PC 0x0c070804 */
if(!s->budget--) { s->failed_pc=0x0c070804u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070806;
P_0c070806: /* original f41b, guest PC 0x0c070806 */
if(!s->budget--) { s->failed_pc=0x0c070806u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070808;
P_0c070808: /* original f40b, guest PC 0x0c070808 */
if(!s->budget--) { s->failed_pc=0x0c070808u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07080a;
P_0c07080a: /* original 0009, guest PC 0x0c07080a */
if(!s->budget--) { s->failed_pc=0x0c07080au; return 0; }
goto P_0c07080c;
P_0c07080c: /* original f4fc, guest PC 0x0c07080c */
if(!s->budget--) { s->failed_pc=0x0c07080cu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c07080e;
P_0c07080e: /* original f4c1, guest PC 0x0c07080e */
if(!s->budget--) { s->failed_pc=0x0c07080eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[12],r[18],'-');
goto P_0c070810;
P_0c070810: /* original 64f3, guest PC 0x0c070810 */
if(!s->budget--) { s->failed_pc=0x0c070810u; return 0; }
r[4]=r[15];
goto P_0c070812;
P_0c070812: /* original 65f3, guest PC 0x0c070812 */
if(!s->budget--) { s->failed_pc=0x0c070812u; return 0; }
r[5]=r[15];
goto P_0c070814;
P_0c070814: /* original 7438, guest PC 0x0c070814 */
if(!s->budget--) { s->failed_pc=0x0c070814u; return 0; }
r[4]+=0x00000038u;
goto P_0c070816;
P_0c070816: /* original 7538, guest PC 0x0c070816 */
if(!s->budget--) { s->failed_pc=0x0c070816u; return 0; }
r[5]+=0x00000038u;
goto P_0c070818;
P_0c070818: /* original f059, guest PC 0x0c070818 */
if(!s->budget--) { s->failed_pc=0x0c070818u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07081a;
P_0c07081a: /* original f159, guest PC 0x0c07081a */
if(!s->budget--) { s->failed_pc=0x0c07081au; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07081c;
P_0c07081c: /* original f259, guest PC 0x0c07081c */
if(!s->budget--) { s->failed_pc=0x0c07081cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07081e;
P_0c07081e: /* original f38d, guest PC 0x0c07081e */
if(!s->budget--) { s->failed_pc=0x0c07081eu; return 0; }
fr[3]=0;
goto P_0c070820;
P_0c070820: /* original f0ed, guest PC 0x0c070820 */
if(!s->budget--) { s->failed_pc=0x0c070820u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070822;
P_0c070822: /* original f37d, guest PC 0x0c070822 */
if(!s->budget--) { s->failed_pc=0x0c070822u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070824;
P_0c070824: /* original f342, guest PC 0x0c070824 */
if(!s->budget--) { s->failed_pc=0x0c070824u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070826;
P_0c070826: /* original 740c, guest PC 0x0c070826 */
if(!s->budget--) { s->failed_pc=0x0c070826u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070828;
P_0c070828: /* original f232, guest PC 0x0c070828 */
if(!s->budget--) { s->failed_pc=0x0c070828u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07082a;
P_0c07082a: /* original f132, guest PC 0x0c07082a */
if(!s->budget--) { s->failed_pc=0x0c07082au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c07082c;
P_0c07082c: /* original f032, guest PC 0x0c07082c */
if(!s->budget--) { s->failed_pc=0x0c07082cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c07082e;
P_0c07082e: /* original f42b, guest PC 0x0c07082e */
if(!s->budget--) { s->failed_pc=0x0c07082eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070830;
P_0c070830: /* original f41b, guest PC 0x0c070830 */
if(!s->budget--) { s->failed_pc=0x0c070830u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070832;
P_0c070832: /* original f40b, guest PC 0x0c070832 */
if(!s->budget--) { s->failed_pc=0x0c070832u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070834;
P_0c070834: /* original 64f3, guest PC 0x0c070834 */
if(!s->budget--) { s->failed_pc=0x0c070834u; return 0; }
r[4]=r[15];
goto P_0c070836;
P_0c070836: /* original 65f3, guest PC 0x0c070836 */
if(!s->budget--) { s->failed_pc=0x0c070836u; return 0; }
r[5]=r[15];
goto P_0c070838;
P_0c070838: /* original 7444, guest PC 0x0c070838 */
if(!s->budget--) { s->failed_pc=0x0c070838u; return 0; }
r[4]+=0x00000044u;
goto P_0c07083a;
P_0c07083a: /* original 7538, guest PC 0x0c07083a */
if(!s->budget--) { s->failed_pc=0x0c07083au; return 0; }
r[5]+=0x00000038u;
goto P_0c07083c;
P_0c07083c: /* original f049, guest PC 0x0c07083c */
if(!s->budget--) { s->failed_pc=0x0c07083cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07083e;
P_0c07083e: /* original f359, guest PC 0x0c07083e */
if(!s->budget--) { s->failed_pc=0x0c07083eu; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070840;
P_0c070840: /* original f149, guest PC 0x0c070840 */
if(!s->budget--) { s->failed_pc=0x0c070840u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070842;
P_0c070842: /* original f459, guest PC 0x0c070842 */
if(!s->budget--) { s->failed_pc=0x0c070842u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070844;
P_0c070844: /* original f249, guest PC 0x0c070844 */
if(!s->budget--) { s->failed_pc=0x0c070844u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070846;
P_0c070846: /* original f559, guest PC 0x0c070846 */
if(!s->budget--) { s->failed_pc=0x0c070846u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070848;
P_0c070848: /* original f030, guest PC 0x0c070848 */
if(!s->budget--) { s->failed_pc=0x0c070848u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c07084a;
P_0c07084a: /* original f250, guest PC 0x0c07084a */
if(!s->budget--) { s->failed_pc=0x0c07084au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c07084c;
P_0c07084c: /* original f140, guest PC 0x0c07084c */
if(!s->budget--) { s->failed_pc=0x0c07084cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c07084e;
P_0c07084e: /* original f42b, guest PC 0x0c07084e */
if(!s->budget--) { s->failed_pc=0x0c07084eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070850;
P_0c070850: /* original f41b, guest PC 0x0c070850 */
if(!s->budget--) { s->failed_pc=0x0c070850u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070852;
P_0c070852: /* original f40b, guest PC 0x0c070852 */
if(!s->budget--) { s->failed_pc=0x0c070852u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070854;
P_0c070854: /* original 65f3, guest PC 0x0c070854 */
if(!s->budget--) { s->failed_pc=0x0c070854u; return 0; }
r[5]=r[15];
goto P_0c070856;
P_0c070856: /* original 64d3, guest PC 0x0c070856 */
if(!s->budget--) { s->failed_pc=0x0c070856u; return 0; }
r[4]=r[13];
goto P_0c070858;
P_0c070858: /* original 7544, guest PC 0x0c070858 */
if(!s->budget--) { s->failed_pc=0x0c070858u; return 0; }
r[5]+=0x00000044u;
goto P_0c07085a;
P_0c07085a: /* original 6693, guest PC 0x0c07085a */
if(!s->budget--) { s->failed_pc=0x0c07085au; return 0; }
r[6]=r[9];
goto P_0c07085c;
P_0c07085c: /* original f059, guest PC 0x0c07085c */
if(!s->budget--) { s->failed_pc=0x0c07085cu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07085e;
P_0c07085e: /* original f369, guest PC 0x0c07085e */
if(!s->budget--) { s->failed_pc=0x0c07085eu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070860;
P_0c070860: /* original f159, guest PC 0x0c070860 */
if(!s->budget--) { s->failed_pc=0x0c070860u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070862;
P_0c070862: /* original f469, guest PC 0x0c070862 */
if(!s->budget--) { s->failed_pc=0x0c070862u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070864;
P_0c070864: /* original f259, guest PC 0x0c070864 */
if(!s->budget--) { s->failed_pc=0x0c070864u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070866;
P_0c070866: /* original f569, guest PC 0x0c070866 */
if(!s->budget--) { s->failed_pc=0x0c070866u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070868;
P_0c070868: /* original 740c, guest PC 0x0c070868 */
if(!s->budget--) { s->failed_pc=0x0c070868u; return 0; }
r[4]+=0x0000000cu;
goto P_0c07086a;
P_0c07086a: /* original f030, guest PC 0x0c07086a */
if(!s->budget--) { s->failed_pc=0x0c07086au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c07086c;
P_0c07086c: /* original f250, guest PC 0x0c07086c */
if(!s->budget--) { s->failed_pc=0x0c07086cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c07086e;
P_0c07086e: /* original f140, guest PC 0x0c07086e */
if(!s->budget--) { s->failed_pc=0x0c07086eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070870;
P_0c070870: /* original f42b, guest PC 0x0c070870 */
if(!s->budget--) { s->failed_pc=0x0c070870u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070872;
P_0c070872: /* original f41b, guest PC 0x0c070872 */
if(!s->budget--) { s->failed_pc=0x0c070872u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070874;
P_0c070874: /* original f40b, guest PC 0x0c070874 */
if(!s->budget--) { s->failed_pc=0x0c070874u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070876;
P_0c070876: /* original 0009, guest PC 0x0c070876 */
if(!s->budget--) { s->failed_pc=0x0c070876u; return 0; }
goto P_0c070878;
P_0c070878: /* original 63f2, guest PC 0x0c070878 */
if(!s->budget--) { s->failed_pc=0x0c070878u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07087a;
P_0c07087a: /* original 7ee8, guest PC 0x0c07087a */
if(!s->budget--) { s->failed_pc=0x0c07087au; return 0; }
r[14]+=0xffffffe8u;
goto P_0c07087c;
P_0c07087c: /* original 4315, guest PC 0x0c07087c */
if(!s->budget--) { s->failed_pc=0x0c07087cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c07087e;
P_0c07087e: /* original 8d03, guest PC 0x0c07087e */
if(!s->budget--) { s->failed_pc=0x0c07087eu; return 0; }
cond=r[17]&1u;
r[13]+=0x00000018u;
if(cond) { goto P_0c070888; }
goto P_0c070882;
P_0c070880: /* original 7d18, guest PC 0x0c070880 */
if(!s->budget--) { s->failed_pc=0x0c070880u; return 0; }
r[13]+=0x00000018u;
goto P_0c070882;
P_0c070882: /* original d204, guest PC 0x0c070882 */
if(!s->budget--) { s->failed_pc=0x0c070882u; return 0; }
r[2]=read(ram,0x0c070894u,4);
goto P_0c070884;
P_0c070884: /* original 422b, guest PC 0x0c070884 */
if(!s->budget--) { s->failed_pc=0x0c070884u; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c071124u: goto P_0c071124;
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
P_0c070886: /* original 0009, guest PC 0x0c070886 */
if(!s->budget--) { s->failed_pc=0x0c070886u; return 0; }
goto P_0c070888;
P_0c070888: /* original 64f3, guest PC 0x0c070888 */
if(!s->budget--) { s->failed_pc=0x0c070888u; return 0; }
r[4]=r[15];
goto P_0c07088a;
P_0c07088a: /* original 7444, guest PC 0x0c07088a */
if(!s->budget--) { s->failed_pc=0x0c07088au; return 0; }
r[4]+=0x00000044u;
goto P_0c07088c;
P_0c07088c: /* original 66a3, guest PC 0x0c07088c */
if(!s->budget--) { s->failed_pc=0x0c07088cu; return 0; }
r[6]=r[10];
goto P_0c07088e;
P_0c07088e: /* original 65e3, guest PC 0x0c07088e */
if(!s->budget--) { s->failed_pc=0x0c07088eu; return 0; }
r[5]=r[14];
goto P_0c070890;
P_0c070890: /* original a002, guest PC 0x0c070890 */
if(!s->budget--) { s->failed_pc=0x0c070890u; return 0; }
goto P_0c070898;
P_0c070892: /* original 0009, guest PC 0x0c070892 */
if(!s->budget--) { s->failed_pc=0x0c070892u; return 0; }
if(!vf3_matrix_family(0x0c070894u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c070894u; return 0; } return 1;
P_0c070898: /* original f059, guest PC 0x0c070898 */
if(!s->budget--) { s->failed_pc=0x0c070898u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07089a;
P_0c07089a: /* original f369, guest PC 0x0c07089a */
if(!s->budget--) { s->failed_pc=0x0c07089au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07089c;
P_0c07089c: /* original f159, guest PC 0x0c07089c */
if(!s->budget--) { s->failed_pc=0x0c07089cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07089e;
P_0c07089e: /* original f469, guest PC 0x0c07089e */
if(!s->budget--) { s->failed_pc=0x0c07089eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0708a0;
P_0c0708a0: /* original f031, guest PC 0x0c0708a0 */
if(!s->budget--) { s->failed_pc=0x0c0708a0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0708a2;
P_0c0708a2: /* original f258, guest PC 0x0c0708a2 */
if(!s->budget--) { s->failed_pc=0x0c0708a2u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0708a4;
P_0c0708a4: /* original f568, guest PC 0x0c0708a4 */
if(!s->budget--) { s->failed_pc=0x0c0708a4u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0708a6;
P_0c0708a6: /* original f141, guest PC 0x0c0708a6 */
if(!s->budget--) { s->failed_pc=0x0c0708a6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0708a8;
P_0c0708a8: /* original f251, guest PC 0x0c0708a8 */
if(!s->budget--) { s->failed_pc=0x0c0708a8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0708aa;
P_0c0708aa: /* original 7408, guest PC 0x0c0708aa */
if(!s->budget--) { s->failed_pc=0x0c0708aau; return 0; }
r[4]+=0x00000008u;
goto P_0c0708ac;
P_0c0708ac: /* original f42a, guest PC 0x0c0708ac */
if(!s->budget--) { s->failed_pc=0x0c0708acu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0708ae;
P_0c0708ae: /* original f41b, guest PC 0x0c0708ae */
if(!s->budget--) { s->failed_pc=0x0c0708aeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0708b0;
P_0c0708b0: /* original f40b, guest PC 0x0c0708b0 */
if(!s->budget--) { s->failed_pc=0x0c0708b0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0708b2;
P_0c0708b2: /* original 0009, guest PC 0x0c0708b2 */
if(!s->budget--) { s->failed_pc=0x0c0708b2u; return 0; }
goto P_0c0708b4;
P_0c0708b4: /* original 64f3, guest PC 0x0c0708b4 */
if(!s->budget--) { s->failed_pc=0x0c0708b4u; return 0; }
r[4]=r[15];
goto P_0c0708b6;
P_0c0708b6: /* original 7444, guest PC 0x0c0708b6 */
if(!s->budget--) { s->failed_pc=0x0c0708b6u; return 0; }
r[4]+=0x00000044u;
goto P_0c0708b8;
P_0c0708b8: /* original f049, guest PC 0x0c0708b8 */
if(!s->budget--) { s->failed_pc=0x0c0708b8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0708ba;
P_0c0708ba: /* original f149, guest PC 0x0c0708ba */
if(!s->budget--) { s->failed_pc=0x0c0708bau; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0708bc;
P_0c0708bc: /* original f249, guest PC 0x0c0708bc */
if(!s->budget--) { s->failed_pc=0x0c0708bcu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0708be;
P_0c0708be: /* original f38d, guest PC 0x0c0708be */
if(!s->budget--) { s->failed_pc=0x0c0708beu; return 0; }
fr[3]=0;
goto P_0c0708c0;
P_0c0708c0: /* original f0ed, guest PC 0x0c0708c0 */
if(!s->budget--) { s->failed_pc=0x0c0708c0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0708c2;
P_0c0708c2: /* original f03c, guest PC 0x0c0708c2 */
if(!s->budget--) { s->failed_pc=0x0c0708c2u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c0708c4;
P_0c0708c4: /* original f06d, guest PC 0x0c0708c4 */
if(!s->budget--) { s->failed_pc=0x0c0708c4u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c0708c6;
P_0c0708c6: /* original 0009, guest PC 0x0c0708c6 */
if(!s->budget--) { s->failed_pc=0x0c0708c6u; return 0; }
goto P_0c0708c8;
P_0c0708c8: /* original f38d, guest PC 0x0c0708c8 */
if(!s->budget--) { s->failed_pc=0x0c0708c8u; return 0; }
fr[3]=0;
goto P_0c0708ca;
P_0c0708ca: /* original f035, guest PC 0x0c0708ca */
if(!s->budget--) { s->failed_pc=0x0c0708cau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c0708cc;
P_0c0708cc: /* original e018, guest PC 0x0c0708cc */
if(!s->budget--) { s->failed_pc=0x0c0708ccu; return 0; }
r[0]=0x00000018u;
goto P_0c0708ce;
P_0c0708ce: /* original 8d03, guest PC 0x0c0708ce */
if(!s->budget--) { s->failed_pc=0x0c0708ceu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(cond) { goto P_0c0708d8; }
goto P_0c0708d2;
P_0c0708d0: /* original ff07, guest PC 0x0c0708d0 */
if(!s->budget--) { s->failed_pc=0x0c0708d0u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0708d2;
P_0c0708d2: /* original d304, guest PC 0x0c0708d2 */
if(!s->budget--) { s->failed_pc=0x0c0708d2u; return 0; }
r[3]=read(ram,0x0c0708e4u,4);
goto P_0c0708d4;
P_0c0708d4: /* original 432b, guest PC 0x0c0708d4 */
if(!s->budget--) { s->failed_pc=0x0c0708d4u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070a64u: goto P_0c070a64;
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
P_0c0708d6: /* original 0009, guest PC 0x0c0708d6 */
if(!s->budget--) { s->failed_pc=0x0c0708d6u; return 0; }
goto P_0c0708d8;
P_0c0708d8: /* original 64f3, guest PC 0x0c0708d8 */
if(!s->budget--) { s->failed_pc=0x0c0708d8u; return 0; }
r[4]=r[15];
goto P_0c0708da;
P_0c0708da: /* original 7444, guest PC 0x0c0708da */
if(!s->budget--) { s->failed_pc=0x0c0708dau; return 0; }
r[4]+=0x00000044u;
goto P_0c0708dc;
P_0c0708dc: /* original 65b3, guest PC 0x0c0708dc */
if(!s->budget--) { s->failed_pc=0x0c0708dcu; return 0; }
r[5]=r[11];
goto P_0c0708de;
P_0c0708de: /* original a003, guest PC 0x0c0708de */
if(!s->budget--) { s->failed_pc=0x0c0708deu; return 0; }
goto P_0c0708e8;
P_0c0708e0: /* original 0009, guest PC 0x0c0708e0 */
if(!s->budget--) { s->failed_pc=0x0c0708e0u; return 0; }
if(!vf3_matrix_family(0x0c0708e2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0708e2u; return 0; } return 1;
P_0c0708e8: /* original f049, guest PC 0x0c0708e8 */
if(!s->budget--) { s->failed_pc=0x0c0708e8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0708ea;
P_0c0708ea: /* original f549, guest PC 0x0c0708ea */
if(!s->budget--) { s->failed_pc=0x0c0708eau; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0708ec;
P_0c0708ec: /* original f648, guest PC 0x0c0708ec */
if(!s->budget--) { s->failed_pc=0x0c0708ecu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0708ee;
P_0c0708ee: /* original f859, guest PC 0x0c0708ee */
if(!s->budget--) { s->failed_pc=0x0c0708eeu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0708f0;
P_0c0708f0: /* original f959, guest PC 0x0c0708f0 */
if(!s->budget--) { s->failed_pc=0x0c0708f0u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0708f2;
P_0c0708f2: /* original fa58, guest PC 0x0c0708f2 */
if(!s->budget--) { s->failed_pc=0x0c0708f2u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c0708f4;
P_0c0708f4: /* original f35c, guest PC 0x0c0708f4 */
if(!s->budget--) { s->failed_pc=0x0c0708f4u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0708f6;
P_0c0708f6: /* original f382, guest PC 0x0c0708f6 */
if(!s->budget--) { s->failed_pc=0x0c0708f6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c0708f8;
P_0c0708f8: /* original f20c, guest PC 0x0c0708f8 */
if(!s->budget--) { s->failed_pc=0x0c0708f8u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c0708fa;
P_0c0708fa: /* original f2a2, guest PC 0x0c0708fa */
if(!s->budget--) { s->failed_pc=0x0c0708fau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c0708fc;
P_0c0708fc: /* original f16c, guest PC 0x0c0708fc */
if(!s->budget--) { s->failed_pc=0x0c0708fcu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c0708fe;
P_0c0708fe: /* original f192, guest PC 0x0c0708fe */
if(!s->budget--) { s->failed_pc=0x0c0708feu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c070900;
P_0c070900: /* original f34d, guest PC 0x0c070900 */
if(!s->budget--) { s->failed_pc=0x0c070900u; return 0; }
fr[3]^=0x80000000u;
goto P_0c070902;
P_0c070902: /* original f39e, guest PC 0x0c070902 */
if(!s->budget--) { s->failed_pc=0x0c070902u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c070904;
P_0c070904: /* original f24d, guest PC 0x0c070904 */
if(!s->budget--) { s->failed_pc=0x0c070904u; return 0; }
fr[2]^=0x80000000u;
goto P_0c070906;
P_0c070906: /* original f06c, guest PC 0x0c070906 */
if(!s->budget--) { s->failed_pc=0x0c070906u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c070908;
P_0c070908: /* original f28e, guest PC 0x0c070908 */
if(!s->budget--) { s->failed_pc=0x0c070908u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c07090a;
P_0c07090a: /* original f14d, guest PC 0x0c07090a */
if(!s->budget--) { s->failed_pc=0x0c07090au; return 0; }
fr[1]^=0x80000000u;
goto P_0c07090c;
P_0c07090c: /* original f05c, guest PC 0x0c07090c */
if(!s->budget--) { s->failed_pc=0x0c07090cu; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c07090e;
P_0c07090e: /* original f1ae, guest PC 0x0c07090e */
if(!s->budget--) { s->failed_pc=0x0c07090eu; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c070910;
P_0c070910: /* original f08d, guest PC 0x0c070910 */
if(!s->budget--) { s->failed_pc=0x0c070910u; return 0; }
fr[0]=0;
goto P_0c070912;
P_0c070912: /* original f0ed, guest PC 0x0c070912 */
if(!s->budget--) { s->failed_pc=0x0c070912u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070914;
P_0c070914: /* original f03c, guest PC 0x0c070914 */
if(!s->budget--) { s->failed_pc=0x0c070914u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070916;
P_0c070916: /* original f06d, guest PC 0x0c070916 */
if(!s->budget--) { s->failed_pc=0x0c070916u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070918;
P_0c070918: /* original fc0c, guest PC 0x0c070918 */
if(!s->budget--) { s->failed_pc=0x0c070918u; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c07091a;
P_0c07091a: /* original ffc5, guest PC 0x0c07091a */
if(!s->budget--) { s->failed_pc=0x0c07091au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[12]))!=0);
goto P_0c07091c;
P_0c07091c: /* original 8902, guest PC 0x0c07091c */
if(!s->budget--) { s->failed_pc=0x0c07091cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070924; }
goto P_0c07091e;
P_0c07091e: /* original d304, guest PC 0x0c07091e */
if(!s->budget--) { s->failed_pc=0x0c07091eu; return 0; }
r[3]=read(ram,0x0c070930u,4);
goto P_0c070920;
P_0c070920: /* original 432b, guest PC 0x0c070920 */
if(!s->budget--) { s->failed_pc=0x0c070920u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070a64u: goto P_0c070a64;
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
P_0c070922: /* original 0009, guest PC 0x0c070922 */
if(!s->budget--) { s->failed_pc=0x0c070922u; return 0; }
goto P_0c070924;
P_0c070924: /* original 64f3, guest PC 0x0c070924 */
if(!s->budget--) { s->failed_pc=0x0c070924u; return 0; }
r[4]=r[15];
goto P_0c070926;
P_0c070926: /* original 7444, guest PC 0x0c070926 */
if(!s->budget--) { s->failed_pc=0x0c070926u; return 0; }
r[4]+=0x00000044u;
goto P_0c070928;
P_0c070928: /* original 65b3, guest PC 0x0c070928 */
if(!s->budget--) { s->failed_pc=0x0c070928u; return 0; }
r[5]=r[11];
goto P_0c07092a;
P_0c07092a: /* original a003, guest PC 0x0c07092a */
if(!s->budget--) { s->failed_pc=0x0c07092au; return 0; }
goto P_0c070934;
P_0c07092c: /* original 0009, guest PC 0x0c07092c */
if(!s->budget--) { s->failed_pc=0x0c07092cu; return 0; }
if(!vf3_matrix_family(0x0c07092eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07092eu; return 0; } return 1;
P_0c070934: /* original f049, guest PC 0x0c070934 */
if(!s->budget--) { s->failed_pc=0x0c070934u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070936;
P_0c070936: /* original f149, guest PC 0x0c070936 */
if(!s->budget--) { s->failed_pc=0x0c070936u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070938;
P_0c070938: /* original f249, guest PC 0x0c070938 */
if(!s->budget--) { s->failed_pc=0x0c070938u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07093a;
P_0c07093a: /* original f38d, guest PC 0x0c07093a */
if(!s->budget--) { s->failed_pc=0x0c07093au; return 0; }
fr[3]=0;
goto P_0c07093c;
P_0c07093c: /* original f459, guest PC 0x0c07093c */
if(!s->budget--) { s->failed_pc=0x0c07093cu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07093e;
P_0c07093e: /* original f559, guest PC 0x0c07093e */
if(!s->budget--) { s->failed_pc=0x0c07093eu; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070940;
P_0c070940: /* original f659, guest PC 0x0c070940 */
if(!s->budget--) { s->failed_pc=0x0c070940u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070942;
P_0c070942: /* original f78d, guest PC 0x0c070942 */
if(!s->budget--) { s->failed_pc=0x0c070942u; return 0; }
fr[7]=0;
goto P_0c070944;
P_0c070944: /* original f4ed, guest PC 0x0c070944 */
if(!s->budget--) { s->failed_pc=0x0c070944u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c070946;
P_0c070946: /* original f07c, guest PC 0x0c070946 */
if(!s->budget--) { s->failed_pc=0x0c070946u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c070948;
P_0c070948: /* original f38d, guest PC 0x0c070948 */
if(!s->budget--) { s->failed_pc=0x0c070948u; return 0; }
fr[3]=0;
goto P_0c07094a;
P_0c07094a: /* original f40c, guest PC 0x0c07094a */
if(!s->budget--) { s->failed_pc=0x0c07094au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c07094c;
P_0c07094c: /* original f345, guest PC 0x0c07094c */
if(!s->budget--) { s->failed_pc=0x0c07094cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c07094e;
P_0c07094e: /* original 8902, guest PC 0x0c07094e */
if(!s->budget--) { s->failed_pc=0x0c07094eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070956; }
goto P_0c070950;
P_0c070950: /* original d308, guest PC 0x0c070950 */
if(!s->budget--) { s->failed_pc=0x0c070950u; return 0; }
r[3]=read(ram,0x0c070974u,4);
goto P_0c070952;
P_0c070952: /* original 432b, guest PC 0x0c070952 */
if(!s->budget--) { s->failed_pc=0x0c070952u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c07099eu: goto P_0c07099e;
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
P_0c070954: /* original 0009, guest PC 0x0c070954 */
if(!s->budget--) { s->failed_pc=0x0c070954u; return 0; }
goto P_0c070956;
P_0c070956: /* original e018, guest PC 0x0c070956 */
if(!s->budget--) { s->failed_pc=0x0c070956u; return 0; }
r[0]=0x00000018u;
goto P_0c070958;
P_0c070958: /* original f3f6, guest PC 0x0c070958 */
if(!s->budget--) { s->failed_pc=0x0c070958u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c07095a;
P_0c07095a: /* original ff35, guest PC 0x0c07095a */
if(!s->budget--) { s->failed_pc=0x0c07095au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c07095c;
P_0c07095c: /* original 8902, guest PC 0x0c07095c */
if(!s->budget--) { s->failed_pc=0x0c07095cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070964; }
goto P_0c07095e;
P_0c07095e: /* original d306, guest PC 0x0c07095e */
if(!s->budget--) { s->failed_pc=0x0c07095eu; return 0; }
r[3]=read(ram,0x0c070978u,4);
goto P_0c070960;
P_0c070960: /* original 432b, guest PC 0x0c070960 */
if(!s->budget--) { s->failed_pc=0x0c070960u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070a64u: goto P_0c070a64;
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
P_0c070962: /* original 0009, guest PC 0x0c070962 */
if(!s->budget--) { s->failed_pc=0x0c070962u; return 0; }
goto P_0c070964;
P_0c070964: /* original 64f3, guest PC 0x0c070964 */
if(!s->budget--) { s->failed_pc=0x0c070964u; return 0; }
r[4]=r[15];
goto P_0c070966;
P_0c070966: /* original 65f3, guest PC 0x0c070966 */
if(!s->budget--) { s->failed_pc=0x0c070966u; return 0; }
r[5]=r[15];
goto P_0c070968;
P_0c070968: /* original 7444, guest PC 0x0c070968 */
if(!s->budget--) { s->failed_pc=0x0c070968u; return 0; }
r[4]+=0x00000044u;
goto P_0c07096a;
P_0c07096a: /* original f4fc, guest PC 0x0c07096a */
if(!s->budget--) { s->failed_pc=0x0c07096au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c07096c;
P_0c07096c: /* original 7544, guest PC 0x0c07096c */
if(!s->budget--) { s->failed_pc=0x0c07096cu; return 0; }
r[5]+=0x00000044u;
goto P_0c07096e;
P_0c07096e: /* original a005, guest PC 0x0c07096e */
if(!s->budget--) { s->failed_pc=0x0c07096eu; return 0; }
goto P_0c07097c;
P_0c070970: /* original 0009, guest PC 0x0c070970 */
if(!s->budget--) { s->failed_pc=0x0c070970u; return 0; }
if(!vf3_matrix_family(0x0c070972u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c070972u; return 0; } return 1;
P_0c07097c: /* original f059, guest PC 0x0c07097c */
if(!s->budget--) { s->failed_pc=0x0c07097cu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07097e;
P_0c07097e: /* original f159, guest PC 0x0c07097e */
if(!s->budget--) { s->failed_pc=0x0c07097eu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070980;
P_0c070980: /* original f259, guest PC 0x0c070980 */
if(!s->budget--) { s->failed_pc=0x0c070980u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070982;
P_0c070982: /* original f38d, guest PC 0x0c070982 */
if(!s->budget--) { s->failed_pc=0x0c070982u; return 0; }
fr[3]=0;
goto P_0c070984;
P_0c070984: /* original f0ed, guest PC 0x0c070984 */
if(!s->budget--) { s->failed_pc=0x0c070984u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070986;
P_0c070986: /* original f37d, guest PC 0x0c070986 */
if(!s->budget--) { s->failed_pc=0x0c070986u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070988;
P_0c070988: /* original f342, guest PC 0x0c070988 */
if(!s->budget--) { s->failed_pc=0x0c070988u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c07098a;
P_0c07098a: /* original 740c, guest PC 0x0c07098a */
if(!s->budget--) { s->failed_pc=0x0c07098au; return 0; }
r[4]+=0x0000000cu;
goto P_0c07098c;
P_0c07098c: /* original f232, guest PC 0x0c07098c */
if(!s->budget--) { s->failed_pc=0x0c07098cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07098e;
P_0c07098e: /* original f132, guest PC 0x0c07098e */
if(!s->budget--) { s->failed_pc=0x0c07098eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070990;
P_0c070990: /* original f032, guest PC 0x0c070990 */
if(!s->budget--) { s->failed_pc=0x0c070990u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070992;
P_0c070992: /* original f42b, guest PC 0x0c070992 */
if(!s->budget--) { s->failed_pc=0x0c070992u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070994;
P_0c070994: /* original f41b, guest PC 0x0c070994 */
if(!s->budget--) { s->failed_pc=0x0c070994u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070996;
P_0c070996: /* original f40b, guest PC 0x0c070996 */
if(!s->budget--) { s->failed_pc=0x0c070996u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070998;
P_0c070998: /* original d306, guest PC 0x0c070998 */
if(!s->budget--) { s->failed_pc=0x0c070998u; return 0; }
r[3]=read(ram,0x0c0709b4u,4);
goto P_0c07099a;
P_0c07099a: /* original 432b, guest PC 0x0c07099a */
if(!s->budget--) { s->failed_pc=0x0c07099au; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070a40u: goto P_0c070a40;
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
P_0c07099c: /* original 0009, guest PC 0x0c07099c */
if(!s->budget--) { s->failed_pc=0x0c07099cu; return 0; }
goto P_0c07099e;
P_0c07099e: /* original fe45, guest PC 0x0c07099e */
if(!s->budget--) { s->failed_pc=0x0c07099eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[4]))!=0);
goto P_0c0709a0;
P_0c0709a0: /* original 8902, guest PC 0x0c0709a0 */
if(!s->budget--) { s->failed_pc=0x0c0709a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0709a8; }
goto P_0c0709a2;
P_0c0709a2: /* original d305, guest PC 0x0c0709a2 */
if(!s->budget--) { s->failed_pc=0x0c0709a2u; return 0; }
r[3]=read(ram,0x0c0709b8u,4);
goto P_0c0709a4;
P_0c0709a4: /* original 432b, guest PC 0x0c0709a4 */
if(!s->budget--) { s->failed_pc=0x0c0709a4u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070a64u: goto P_0c070a64;
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
P_0c0709a6: /* original 0009, guest PC 0x0c0709a6 */
if(!s->budget--) { s->failed_pc=0x0c0709a6u; return 0; }
goto P_0c0709a8;
P_0c0709a8: /* original 64f3, guest PC 0x0c0709a8 */
if(!s->budget--) { s->failed_pc=0x0c0709a8u; return 0; }
r[4]=r[15];
goto P_0c0709aa;
P_0c0709aa: /* original 7438, guest PC 0x0c0709aa */
if(!s->budget--) { s->failed_pc=0x0c0709aau; return 0; }
r[4]+=0x00000038u;
goto P_0c0709ac;
P_0c0709ac: /* original 65b3, guest PC 0x0c0709ac */
if(!s->budget--) { s->failed_pc=0x0c0709acu; return 0; }
r[5]=r[11];
goto P_0c0709ae;
P_0c0709ae: /* original a005, guest PC 0x0c0709ae */
if(!s->budget--) { s->failed_pc=0x0c0709aeu; return 0; }
goto P_0c0709bc;
P_0c0709b0: /* original 0009, guest PC 0x0c0709b0 */
if(!s->budget--) { s->failed_pc=0x0c0709b0u; return 0; }
if(!vf3_matrix_family(0x0c0709b2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0709b2u; return 0; } return 1;
P_0c0709bc: /* original f059, guest PC 0x0c0709bc */
if(!s->budget--) { s->failed_pc=0x0c0709bcu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0709be;
P_0c0709be: /* original f159, guest PC 0x0c0709be */
if(!s->budget--) { s->failed_pc=0x0c0709beu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0709c0;
P_0c0709c0: /* original f259, guest PC 0x0c0709c0 */
if(!s->budget--) { s->failed_pc=0x0c0709c0u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0709c2;
P_0c0709c2: /* original 740c, guest PC 0x0c0709c2 */
if(!s->budget--) { s->failed_pc=0x0c0709c2u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0709c4;
P_0c0709c4: /* original f242, guest PC 0x0c0709c4 */
if(!s->budget--) { s->failed_pc=0x0c0709c4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c0709c6;
P_0c0709c6: /* original f142, guest PC 0x0c0709c6 */
if(!s->budget--) { s->failed_pc=0x0c0709c6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c0709c8;
P_0c0709c8: /* original f042, guest PC 0x0c0709c8 */
if(!s->budget--) { s->failed_pc=0x0c0709c8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c0709ca;
P_0c0709ca: /* original f42b, guest PC 0x0c0709ca */
if(!s->budget--) { s->failed_pc=0x0c0709cau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0709cc;
P_0c0709cc: /* original f41b, guest PC 0x0c0709cc */
if(!s->budget--) { s->failed_pc=0x0c0709ccu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0709ce;
P_0c0709ce: /* original f40b, guest PC 0x0c0709ce */
if(!s->budget--) { s->failed_pc=0x0c0709ceu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0709d0;
P_0c0709d0: /* original 65f3, guest PC 0x0c0709d0 */
if(!s->budget--) { s->failed_pc=0x0c0709d0u; return 0; }
r[5]=r[15];
goto P_0c0709d2;
P_0c0709d2: /* original 64f3, guest PC 0x0c0709d2 */
if(!s->budget--) { s->failed_pc=0x0c0709d2u; return 0; }
r[4]=r[15];
goto P_0c0709d4;
P_0c0709d4: /* original 66f3, guest PC 0x0c0709d4 */
if(!s->budget--) { s->failed_pc=0x0c0709d4u; return 0; }
r[6]=r[15];
goto P_0c0709d6;
P_0c0709d6: /* original 7438, guest PC 0x0c0709d6 */
if(!s->budget--) { s->failed_pc=0x0c0709d6u; return 0; }
r[4]+=0x00000038u;
goto P_0c0709d8;
P_0c0709d8: /* original 7638, guest PC 0x0c0709d8 */
if(!s->budget--) { s->failed_pc=0x0c0709d8u; return 0; }
r[6]+=0x00000038u;
goto P_0c0709da;
P_0c0709da: /* original 7544, guest PC 0x0c0709da */
if(!s->budget--) { s->failed_pc=0x0c0709dau; return 0; }
r[5]+=0x00000044u;
goto P_0c0709dc;
P_0c0709dc: /* original f059, guest PC 0x0c0709dc */
if(!s->budget--) { s->failed_pc=0x0c0709dcu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0709de;
P_0c0709de: /* original f369, guest PC 0x0c0709de */
if(!s->budget--) { s->failed_pc=0x0c0709deu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0709e0;
P_0c0709e0: /* original f159, guest PC 0x0c0709e0 */
if(!s->budget--) { s->failed_pc=0x0c0709e0u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0709e2;
P_0c0709e2: /* original f469, guest PC 0x0c0709e2 */
if(!s->budget--) { s->failed_pc=0x0c0709e2u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0709e4;
P_0c0709e4: /* original f031, guest PC 0x0c0709e4 */
if(!s->budget--) { s->failed_pc=0x0c0709e4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0709e6;
P_0c0709e6: /* original f258, guest PC 0x0c0709e6 */
if(!s->budget--) { s->failed_pc=0x0c0709e6u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0709e8;
P_0c0709e8: /* original f568, guest PC 0x0c0709e8 */
if(!s->budget--) { s->failed_pc=0x0c0709e8u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0709ea;
P_0c0709ea: /* original f141, guest PC 0x0c0709ea */
if(!s->budget--) { s->failed_pc=0x0c0709eau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0709ec;
P_0c0709ec: /* original f251, guest PC 0x0c0709ec */
if(!s->budget--) { s->failed_pc=0x0c0709ecu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0709ee;
P_0c0709ee: /* original 7408, guest PC 0x0c0709ee */
if(!s->budget--) { s->failed_pc=0x0c0709eeu; return 0; }
r[4]+=0x00000008u;
goto P_0c0709f0;
P_0c0709f0: /* original f42a, guest PC 0x0c0709f0 */
if(!s->budget--) { s->failed_pc=0x0c0709f0u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0709f2;
P_0c0709f2: /* original f41b, guest PC 0x0c0709f2 */
if(!s->budget--) { s->failed_pc=0x0c0709f2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0709f4;
P_0c0709f4: /* original f40b, guest PC 0x0c0709f4 */
if(!s->budget--) { s->failed_pc=0x0c0709f4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0709f6;
P_0c0709f6: /* original 0009, guest PC 0x0c0709f6 */
if(!s->budget--) { s->failed_pc=0x0c0709f6u; return 0; }
goto P_0c0709f8;
P_0c0709f8: /* original f4fc, guest PC 0x0c0709f8 */
if(!s->budget--) { s->failed_pc=0x0c0709f8u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0709fa;
P_0c0709fa: /* original f4c1, guest PC 0x0c0709fa */
if(!s->budget--) { s->failed_pc=0x0c0709fau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[12],r[18],'-');
goto P_0c0709fc;
P_0c0709fc: /* original 64f3, guest PC 0x0c0709fc */
if(!s->budget--) { s->failed_pc=0x0c0709fcu; return 0; }
r[4]=r[15];
goto P_0c0709fe;
P_0c0709fe: /* original 65f3, guest PC 0x0c0709fe */
if(!s->budget--) { s->failed_pc=0x0c0709feu; return 0; }
r[5]=r[15];
goto P_0c070a00;
P_0c070a00: /* original 7438, guest PC 0x0c070a00 */
if(!s->budget--) { s->failed_pc=0x0c070a00u; return 0; }
r[4]+=0x00000038u;
goto P_0c070a02;
P_0c070a02: /* original 7538, guest PC 0x0c070a02 */
if(!s->budget--) { s->failed_pc=0x0c070a02u; return 0; }
r[5]+=0x00000038u;
goto P_0c070a04;
P_0c070a04: /* original f059, guest PC 0x0c070a04 */
if(!s->budget--) { s->failed_pc=0x0c070a04u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a06;
P_0c070a06: /* original f159, guest PC 0x0c070a06 */
if(!s->budget--) { s->failed_pc=0x0c070a06u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a08;
P_0c070a08: /* original f259, guest PC 0x0c070a08 */
if(!s->budget--) { s->failed_pc=0x0c070a08u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a0a;
P_0c070a0a: /* original f38d, guest PC 0x0c070a0a */
if(!s->budget--) { s->failed_pc=0x0c070a0au; return 0; }
fr[3]=0;
goto P_0c070a0c;
P_0c070a0c: /* original f0ed, guest PC 0x0c070a0c */
if(!s->budget--) { s->failed_pc=0x0c070a0cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070a0e;
P_0c070a0e: /* original f37d, guest PC 0x0c070a0e */
if(!s->budget--) { s->failed_pc=0x0c070a0eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070a10;
P_0c070a10: /* original f342, guest PC 0x0c070a10 */
if(!s->budget--) { s->failed_pc=0x0c070a10u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070a12;
P_0c070a12: /* original 740c, guest PC 0x0c070a12 */
if(!s->budget--) { s->failed_pc=0x0c070a12u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070a14;
P_0c070a14: /* original f232, guest PC 0x0c070a14 */
if(!s->budget--) { s->failed_pc=0x0c070a14u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070a16;
P_0c070a16: /* original f132, guest PC 0x0c070a16 */
if(!s->budget--) { s->failed_pc=0x0c070a16u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070a18;
P_0c070a18: /* original f032, guest PC 0x0c070a18 */
if(!s->budget--) { s->failed_pc=0x0c070a18u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070a1a;
P_0c070a1a: /* original f42b, guest PC 0x0c070a1a */
if(!s->budget--) { s->failed_pc=0x0c070a1au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070a1c;
P_0c070a1c: /* original f41b, guest PC 0x0c070a1c */
if(!s->budget--) { s->failed_pc=0x0c070a1cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070a1e;
P_0c070a1e: /* original f40b, guest PC 0x0c070a1e */
if(!s->budget--) { s->failed_pc=0x0c070a1eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070a20;
P_0c070a20: /* original 64f3, guest PC 0x0c070a20 */
if(!s->budget--) { s->failed_pc=0x0c070a20u; return 0; }
r[4]=r[15];
goto P_0c070a22;
P_0c070a22: /* original 65f3, guest PC 0x0c070a22 */
if(!s->budget--) { s->failed_pc=0x0c070a22u; return 0; }
r[5]=r[15];
goto P_0c070a24;
P_0c070a24: /* original 7444, guest PC 0x0c070a24 */
if(!s->budget--) { s->failed_pc=0x0c070a24u; return 0; }
r[4]+=0x00000044u;
goto P_0c070a26;
P_0c070a26: /* original 7538, guest PC 0x0c070a26 */
if(!s->budget--) { s->failed_pc=0x0c070a26u; return 0; }
r[5]+=0x00000038u;
goto P_0c070a28;
P_0c070a28: /* original f049, guest PC 0x0c070a28 */
if(!s->budget--) { s->failed_pc=0x0c070a28u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070a2a;
P_0c070a2a: /* original f359, guest PC 0x0c070a2a */
if(!s->budget--) { s->failed_pc=0x0c070a2au; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a2c;
P_0c070a2c: /* original f149, guest PC 0x0c070a2c */
if(!s->budget--) { s->failed_pc=0x0c070a2cu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070a2e;
P_0c070a2e: /* original f459, guest PC 0x0c070a2e */
if(!s->budget--) { s->failed_pc=0x0c070a2eu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a30;
P_0c070a30: /* original f249, guest PC 0x0c070a30 */
if(!s->budget--) { s->failed_pc=0x0c070a30u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070a32;
P_0c070a32: /* original f559, guest PC 0x0c070a32 */
if(!s->budget--) { s->failed_pc=0x0c070a32u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a34;
P_0c070a34: /* original f030, guest PC 0x0c070a34 */
if(!s->budget--) { s->failed_pc=0x0c070a34u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070a36;
P_0c070a36: /* original f250, guest PC 0x0c070a36 */
if(!s->budget--) { s->failed_pc=0x0c070a36u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070a38;
P_0c070a38: /* original f140, guest PC 0x0c070a38 */
if(!s->budget--) { s->failed_pc=0x0c070a38u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070a3a;
P_0c070a3a: /* original f42b, guest PC 0x0c070a3a */
if(!s->budget--) { s->failed_pc=0x0c070a3au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070a3c;
P_0c070a3c: /* original f41b, guest PC 0x0c070a3c */
if(!s->budget--) { s->failed_pc=0x0c070a3cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070a3e;
P_0c070a3e: /* original f40b, guest PC 0x0c070a3e */
if(!s->budget--) { s->failed_pc=0x0c070a3eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070a40;
P_0c070a40: /* original 65f3, guest PC 0x0c070a40 */
if(!s->budget--) { s->failed_pc=0x0c070a40u; return 0; }
r[5]=r[15];
goto P_0c070a42;
P_0c070a42: /* original 64e3, guest PC 0x0c070a42 */
if(!s->budget--) { s->failed_pc=0x0c070a42u; return 0; }
r[4]=r[14];
goto P_0c070a44;
P_0c070a44: /* original 7544, guest PC 0x0c070a44 */
if(!s->budget--) { s->failed_pc=0x0c070a44u; return 0; }
r[5]+=0x00000044u;
goto P_0c070a46;
P_0c070a46: /* original 66a3, guest PC 0x0c070a46 */
if(!s->budget--) { s->failed_pc=0x0c070a46u; return 0; }
r[6]=r[10];
goto P_0c070a48;
P_0c070a48: /* original f059, guest PC 0x0c070a48 */
if(!s->budget--) { s->failed_pc=0x0c070a48u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a4a;
P_0c070a4a: /* original f369, guest PC 0x0c070a4a */
if(!s->budget--) { s->failed_pc=0x0c070a4au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070a4c;
P_0c070a4c: /* original f159, guest PC 0x0c070a4c */
if(!s->budget--) { s->failed_pc=0x0c070a4cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a4e;
P_0c070a4e: /* original f469, guest PC 0x0c070a4e */
if(!s->budget--) { s->failed_pc=0x0c070a4eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070a50;
P_0c070a50: /* original f259, guest PC 0x0c070a50 */
if(!s->budget--) { s->failed_pc=0x0c070a50u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a52;
P_0c070a52: /* original f569, guest PC 0x0c070a52 */
if(!s->budget--) { s->failed_pc=0x0c070a52u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070a54;
P_0c070a54: /* original 740c, guest PC 0x0c070a54 */
if(!s->budget--) { s->failed_pc=0x0c070a54u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070a56;
P_0c070a56: /* original f030, guest PC 0x0c070a56 */
if(!s->budget--) { s->failed_pc=0x0c070a56u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070a58;
P_0c070a58: /* original f250, guest PC 0x0c070a58 */
if(!s->budget--) { s->failed_pc=0x0c070a58u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070a5a;
P_0c070a5a: /* original f140, guest PC 0x0c070a5a */
if(!s->budget--) { s->failed_pc=0x0c070a5au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070a5c;
P_0c070a5c: /* original f42b, guest PC 0x0c070a5c */
if(!s->budget--) { s->failed_pc=0x0c070a5cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070a5e;
P_0c070a5e: /* original f41b, guest PC 0x0c070a5e */
if(!s->budget--) { s->failed_pc=0x0c070a5eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070a60;
P_0c070a60: /* original f40b, guest PC 0x0c070a60 */
if(!s->budget--) { s->failed_pc=0x0c070a60u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070a62;
P_0c070a62: /* original 0009, guest PC 0x0c070a62 */
if(!s->budget--) { s->failed_pc=0x0c070a62u; return 0; }
goto P_0c070a64;
P_0c070a64: /* original 64f3, guest PC 0x0c070a64 */
if(!s->budget--) { s->failed_pc=0x0c070a64u; return 0; }
r[4]=r[15];
goto P_0c070a66;
P_0c070a66: /* original 7444, guest PC 0x0c070a66 */
if(!s->budget--) { s->failed_pc=0x0c070a66u; return 0; }
r[4]+=0x00000044u;
goto P_0c070a68;
P_0c070a68: /* original 6693, guest PC 0x0c070a68 */
if(!s->budget--) { s->failed_pc=0x0c070a68u; return 0; }
r[6]=r[9];
goto P_0c070a6a;
P_0c070a6a: /* original 65e3, guest PC 0x0c070a6a */
if(!s->budget--) { s->failed_pc=0x0c070a6au; return 0; }
r[5]=r[14];
goto P_0c070a6c;
P_0c070a6c: /* original f059, guest PC 0x0c070a6c */
if(!s->budget--) { s->failed_pc=0x0c070a6cu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a6e;
P_0c070a6e: /* original f369, guest PC 0x0c070a6e */
if(!s->budget--) { s->failed_pc=0x0c070a6eu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070a70;
P_0c070a70: /* original f159, guest PC 0x0c070a70 */
if(!s->budget--) { s->failed_pc=0x0c070a70u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a72;
P_0c070a72: /* original f469, guest PC 0x0c070a72 */
if(!s->budget--) { s->failed_pc=0x0c070a72u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070a74;
P_0c070a74: /* original f031, guest PC 0x0c070a74 */
if(!s->budget--) { s->failed_pc=0x0c070a74u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070a76;
P_0c070a76: /* original f258, guest PC 0x0c070a76 */
if(!s->budget--) { s->failed_pc=0x0c070a76u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070a78;
P_0c070a78: /* original f568, guest PC 0x0c070a78 */
if(!s->budget--) { s->failed_pc=0x0c070a78u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070a7a;
P_0c070a7a: /* original f141, guest PC 0x0c070a7a */
if(!s->budget--) { s->failed_pc=0x0c070a7au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070a7c;
P_0c070a7c: /* original f251, guest PC 0x0c070a7c */
if(!s->budget--) { s->failed_pc=0x0c070a7cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070a7e;
P_0c070a7e: /* original 7408, guest PC 0x0c070a7e */
if(!s->budget--) { s->failed_pc=0x0c070a7eu; return 0; }
r[4]+=0x00000008u;
goto P_0c070a80;
P_0c070a80: /* original f42a, guest PC 0x0c070a80 */
if(!s->budget--) { s->failed_pc=0x0c070a80u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070a82;
P_0c070a82: /* original f41b, guest PC 0x0c070a82 */
if(!s->budget--) { s->failed_pc=0x0c070a82u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070a84;
P_0c070a84: /* original f40b, guest PC 0x0c070a84 */
if(!s->budget--) { s->failed_pc=0x0c070a84u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070a86;
P_0c070a86: /* original 0009, guest PC 0x0c070a86 */
if(!s->budget--) { s->failed_pc=0x0c070a86u; return 0; }
goto P_0c070a88;
P_0c070a88: /* original 64f3, guest PC 0x0c070a88 */
if(!s->budget--) { s->failed_pc=0x0c070a88u; return 0; }
r[4]=r[15];
goto P_0c070a8a;
P_0c070a8a: /* original 7444, guest PC 0x0c070a8a */
if(!s->budget--) { s->failed_pc=0x0c070a8au; return 0; }
r[4]+=0x00000044u;
goto P_0c070a8c;
P_0c070a8c: /* original f049, guest PC 0x0c070a8c */
if(!s->budget--) { s->failed_pc=0x0c070a8cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070a8e;
P_0c070a8e: /* original f149, guest PC 0x0c070a8e */
if(!s->budget--) { s->failed_pc=0x0c070a8eu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070a90;
P_0c070a90: /* original f249, guest PC 0x0c070a90 */
if(!s->budget--) { s->failed_pc=0x0c070a90u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070a92;
P_0c070a92: /* original f38d, guest PC 0x0c070a92 */
if(!s->budget--) { s->failed_pc=0x0c070a92u; return 0; }
fr[3]=0;
goto P_0c070a94;
P_0c070a94: /* original f0ed, guest PC 0x0c070a94 */
if(!s->budget--) { s->failed_pc=0x0c070a94u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070a96;
P_0c070a96: /* original f03c, guest PC 0x0c070a96 */
if(!s->budget--) { s->failed_pc=0x0c070a96u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070a98;
P_0c070a98: /* original f06d, guest PC 0x0c070a98 */
if(!s->budget--) { s->failed_pc=0x0c070a98u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070a9a;
P_0c070a9a: /* original 0009, guest PC 0x0c070a9a */
if(!s->budget--) { s->failed_pc=0x0c070a9au; return 0; }
goto P_0c070a9c;
P_0c070a9c: /* original f38d, guest PC 0x0c070a9c */
if(!s->budget--) { s->failed_pc=0x0c070a9cu; return 0; }
fr[3]=0;
goto P_0c070a9e;
P_0c070a9e: /* original f035, guest PC 0x0c070a9e */
if(!s->budget--) { s->failed_pc=0x0c070a9eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c070aa0;
P_0c070aa0: /* original e020, guest PC 0x0c070aa0 */
if(!s->budget--) { s->failed_pc=0x0c070aa0u; return 0; }
r[0]=0x00000020u;
goto P_0c070aa2;
P_0c070aa2: /* original 8d03, guest PC 0x0c070aa2 */
if(!s->budget--) { s->failed_pc=0x0c070aa2u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(cond) { goto P_0c070aac; }
goto P_0c070aa6;
P_0c070aa4: /* original ff07, guest PC 0x0c070aa4 */
if(!s->budget--) { s->failed_pc=0x0c070aa4u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c070aa6;
P_0c070aa6: /* original d304, guest PC 0x0c070aa6 */
if(!s->budget--) { s->failed_pc=0x0c070aa6u; return 0; }
r[3]=read(ram,0x0c070ab8u,4);
goto P_0c070aa8;
P_0c070aa8: /* original 432b, guest PC 0x0c070aa8 */
if(!s->budget--) { s->failed_pc=0x0c070aa8u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070c38u: goto P_0c070c38;
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
P_0c070aaa: /* original 0009, guest PC 0x0c070aaa */
if(!s->budget--) { s->failed_pc=0x0c070aaau; return 0; }
goto P_0c070aac;
P_0c070aac: /* original 64f3, guest PC 0x0c070aac */
if(!s->budget--) { s->failed_pc=0x0c070aacu; return 0; }
r[4]=r[15];
goto P_0c070aae;
P_0c070aae: /* original 7444, guest PC 0x0c070aae */
if(!s->budget--) { s->failed_pc=0x0c070aaeu; return 0; }
r[4]+=0x00000044u;
goto P_0c070ab0;
P_0c070ab0: /* original 65c3, guest PC 0x0c070ab0 */
if(!s->budget--) { s->failed_pc=0x0c070ab0u; return 0; }
r[5]=r[12];
goto P_0c070ab2;
P_0c070ab2: /* original a003, guest PC 0x0c070ab2 */
if(!s->budget--) { s->failed_pc=0x0c070ab2u; return 0; }
goto P_0c070abc;
P_0c070ab4: /* original 0009, guest PC 0x0c070ab4 */
if(!s->budget--) { s->failed_pc=0x0c070ab4u; return 0; }
if(!vf3_matrix_family(0x0c070ab6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c070ab6u; return 0; } return 1;
P_0c070abc: /* original f049, guest PC 0x0c070abc */
if(!s->budget--) { s->failed_pc=0x0c070abcu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070abe;
P_0c070abe: /* original f549, guest PC 0x0c070abe */
if(!s->budget--) { s->failed_pc=0x0c070abeu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070ac0;
P_0c070ac0: /* original f648, guest PC 0x0c070ac0 */
if(!s->budget--) { s->failed_pc=0x0c070ac0u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c070ac2;
P_0c070ac2: /* original f859, guest PC 0x0c070ac2 */
if(!s->budget--) { s->failed_pc=0x0c070ac2u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070ac4;
P_0c070ac4: /* original f959, guest PC 0x0c070ac4 */
if(!s->budget--) { s->failed_pc=0x0c070ac4u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070ac6;
P_0c070ac6: /* original fa58, guest PC 0x0c070ac6 */
if(!s->budget--) { s->failed_pc=0x0c070ac6u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c070ac8;
P_0c070ac8: /* original f35c, guest PC 0x0c070ac8 */
if(!s->budget--) { s->failed_pc=0x0c070ac8u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c070aca;
P_0c070aca: /* original f382, guest PC 0x0c070aca */
if(!s->budget--) { s->failed_pc=0x0c070acau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c070acc;
P_0c070acc: /* original f20c, guest PC 0x0c070acc */
if(!s->budget--) { s->failed_pc=0x0c070accu; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c070ace;
P_0c070ace: /* original f2a2, guest PC 0x0c070ace */
if(!s->budget--) { s->failed_pc=0x0c070aceu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c070ad0;
P_0c070ad0: /* original f16c, guest PC 0x0c070ad0 */
if(!s->budget--) { s->failed_pc=0x0c070ad0u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c070ad2;
P_0c070ad2: /* original f192, guest PC 0x0c070ad2 */
if(!s->budget--) { s->failed_pc=0x0c070ad2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c070ad4;
P_0c070ad4: /* original f34d, guest PC 0x0c070ad4 */
if(!s->budget--) { s->failed_pc=0x0c070ad4u; return 0; }
fr[3]^=0x80000000u;
goto P_0c070ad6;
P_0c070ad6: /* original f39e, guest PC 0x0c070ad6 */
if(!s->budget--) { s->failed_pc=0x0c070ad6u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c070ad8;
P_0c070ad8: /* original f24d, guest PC 0x0c070ad8 */
if(!s->budget--) { s->failed_pc=0x0c070ad8u; return 0; }
fr[2]^=0x80000000u;
goto P_0c070ada;
P_0c070ada: /* original f06c, guest PC 0x0c070ada */
if(!s->budget--) { s->failed_pc=0x0c070adau; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c070adc;
P_0c070adc: /* original f28e, guest PC 0x0c070adc */
if(!s->budget--) { s->failed_pc=0x0c070adcu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c070ade;
P_0c070ade: /* original f14d, guest PC 0x0c070ade */
if(!s->budget--) { s->failed_pc=0x0c070adeu; return 0; }
fr[1]^=0x80000000u;
goto P_0c070ae0;
P_0c070ae0: /* original f05c, guest PC 0x0c070ae0 */
if(!s->budget--) { s->failed_pc=0x0c070ae0u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c070ae2;
P_0c070ae2: /* original f1ae, guest PC 0x0c070ae2 */
if(!s->budget--) { s->failed_pc=0x0c070ae2u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c070ae4;
P_0c070ae4: /* original f08d, guest PC 0x0c070ae4 */
if(!s->budget--) { s->failed_pc=0x0c070ae4u; return 0; }
fr[0]=0;
goto P_0c070ae6;
P_0c070ae6: /* original f0ed, guest PC 0x0c070ae6 */
if(!s->budget--) { s->failed_pc=0x0c070ae6u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070ae8;
P_0c070ae8: /* original f03c, guest PC 0x0c070ae8 */
if(!s->budget--) { s->failed_pc=0x0c070ae8u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070aea;
P_0c070aea: /* original f06d, guest PC 0x0c070aea */
if(!s->budget--) { s->failed_pc=0x0c070aeau; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070aec;
P_0c070aec: /* original fc0c, guest PC 0x0c070aec */
if(!s->budget--) { s->failed_pc=0x0c070aecu; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c070aee;
P_0c070aee: /* original ffc5, guest PC 0x0c070aee */
if(!s->budget--) { s->failed_pc=0x0c070aeeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[12]))!=0);
goto P_0c070af0;
P_0c070af0: /* original 8902, guest PC 0x0c070af0 */
if(!s->budget--) { s->failed_pc=0x0c070af0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070af8; }
goto P_0c070af2;
P_0c070af2: /* original d304, guest PC 0x0c070af2 */
if(!s->budget--) { s->failed_pc=0x0c070af2u; return 0; }
r[3]=read(ram,0x0c070b04u,4);
goto P_0c070af4;
P_0c070af4: /* original 432b, guest PC 0x0c070af4 */
if(!s->budget--) { s->failed_pc=0x0c070af4u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070c38u: goto P_0c070c38;
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
P_0c070af6: /* original 0009, guest PC 0x0c070af6 */
if(!s->budget--) { s->failed_pc=0x0c070af6u; return 0; }
goto P_0c070af8;
P_0c070af8: /* original 64f3, guest PC 0x0c070af8 */
if(!s->budget--) { s->failed_pc=0x0c070af8u; return 0; }
r[4]=r[15];
goto P_0c070afa;
P_0c070afa: /* original 7444, guest PC 0x0c070afa */
if(!s->budget--) { s->failed_pc=0x0c070afau; return 0; }
r[4]+=0x00000044u;
goto P_0c070afc;
P_0c070afc: /* original 65c3, guest PC 0x0c070afc */
if(!s->budget--) { s->failed_pc=0x0c070afcu; return 0; }
r[5]=r[12];
goto P_0c070afe;
P_0c070afe: /* original a003, guest PC 0x0c070afe */
if(!s->budget--) { s->failed_pc=0x0c070afeu; return 0; }
goto P_0c070b08;
P_0c070b00: /* original 0009, guest PC 0x0c070b00 */
if(!s->budget--) { s->failed_pc=0x0c070b00u; return 0; }
if(!vf3_matrix_family(0x0c070b02u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c070b02u; return 0; } return 1;
P_0c070b08: /* original f049, guest PC 0x0c070b08 */
if(!s->budget--) { s->failed_pc=0x0c070b08u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070b0a;
P_0c070b0a: /* original f149, guest PC 0x0c070b0a */
if(!s->budget--) { s->failed_pc=0x0c070b0au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070b0c;
P_0c070b0c: /* original f249, guest PC 0x0c070b0c */
if(!s->budget--) { s->failed_pc=0x0c070b0cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070b0e;
P_0c070b0e: /* original f38d, guest PC 0x0c070b0e */
if(!s->budget--) { s->failed_pc=0x0c070b0eu; return 0; }
fr[3]=0;
goto P_0c070b10;
P_0c070b10: /* original f459, guest PC 0x0c070b10 */
if(!s->budget--) { s->failed_pc=0x0c070b10u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b12;
P_0c070b12: /* original f559, guest PC 0x0c070b12 */
if(!s->budget--) { s->failed_pc=0x0c070b12u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b14;
P_0c070b14: /* original f659, guest PC 0x0c070b14 */
if(!s->budget--) { s->failed_pc=0x0c070b14u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b16;
P_0c070b16: /* original f78d, guest PC 0x0c070b16 */
if(!s->budget--) { s->failed_pc=0x0c070b16u; return 0; }
fr[7]=0;
goto P_0c070b18;
P_0c070b18: /* original f4ed, guest PC 0x0c070b18 */
if(!s->budget--) { s->failed_pc=0x0c070b18u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c070b1a;
P_0c070b1a: /* original f07c, guest PC 0x0c070b1a */
if(!s->budget--) { s->failed_pc=0x0c070b1au; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c070b1c;
P_0c070b1c: /* original f38d, guest PC 0x0c070b1c */
if(!s->budget--) { s->failed_pc=0x0c070b1cu; return 0; }
fr[3]=0;
goto P_0c070b1e;
P_0c070b1e: /* original f40c, guest PC 0x0c070b1e */
if(!s->budget--) { s->failed_pc=0x0c070b1eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c070b20;
P_0c070b20: /* original f345, guest PC 0x0c070b20 */
if(!s->budget--) { s->failed_pc=0x0c070b20u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c070b22;
P_0c070b22: /* original 8902, guest PC 0x0c070b22 */
if(!s->budget--) { s->failed_pc=0x0c070b22u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070b2a; }
goto P_0c070b24;
P_0c070b24: /* original d308, guest PC 0x0c070b24 */
if(!s->budget--) { s->failed_pc=0x0c070b24u; return 0; }
r[3]=read(ram,0x0c070b48u,4);
goto P_0c070b26;
P_0c070b26: /* original 432b, guest PC 0x0c070b26 */
if(!s->budget--) { s->failed_pc=0x0c070b26u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070b72u: goto P_0c070b72;
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
P_0c070b28: /* original 0009, guest PC 0x0c070b28 */
if(!s->budget--) { s->failed_pc=0x0c070b28u; return 0; }
goto P_0c070b2a;
P_0c070b2a: /* original e020, guest PC 0x0c070b2a */
if(!s->budget--) { s->failed_pc=0x0c070b2au; return 0; }
r[0]=0x00000020u;
goto P_0c070b2c;
P_0c070b2c: /* original f3f6, guest PC 0x0c070b2c */
if(!s->budget--) { s->failed_pc=0x0c070b2cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c070b2e;
P_0c070b2e: /* original ff35, guest PC 0x0c070b2e */
if(!s->budget--) { s->failed_pc=0x0c070b2eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c070b30;
P_0c070b30: /* original 8902, guest PC 0x0c070b30 */
if(!s->budget--) { s->failed_pc=0x0c070b30u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070b38; }
goto P_0c070b32;
P_0c070b32: /* original d306, guest PC 0x0c070b32 */
if(!s->budget--) { s->failed_pc=0x0c070b32u; return 0; }
r[3]=read(ram,0x0c070b4cu,4);
goto P_0c070b34;
P_0c070b34: /* original 432b, guest PC 0x0c070b34 */
if(!s->budget--) { s->failed_pc=0x0c070b34u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070c38u: goto P_0c070c38;
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
P_0c070b36: /* original 0009, guest PC 0x0c070b36 */
if(!s->budget--) { s->failed_pc=0x0c070b36u; return 0; }
goto P_0c070b38;
P_0c070b38: /* original 64f3, guest PC 0x0c070b38 */
if(!s->budget--) { s->failed_pc=0x0c070b38u; return 0; }
r[4]=r[15];
goto P_0c070b3a;
P_0c070b3a: /* original 65f3, guest PC 0x0c070b3a */
if(!s->budget--) { s->failed_pc=0x0c070b3au; return 0; }
r[5]=r[15];
goto P_0c070b3c;
P_0c070b3c: /* original 7444, guest PC 0x0c070b3c */
if(!s->budget--) { s->failed_pc=0x0c070b3cu; return 0; }
r[4]+=0x00000044u;
goto P_0c070b3e;
P_0c070b3e: /* original f4fc, guest PC 0x0c070b3e */
if(!s->budget--) { s->failed_pc=0x0c070b3eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070b40;
P_0c070b40: /* original 7544, guest PC 0x0c070b40 */
if(!s->budget--) { s->failed_pc=0x0c070b40u; return 0; }
r[5]+=0x00000044u;
goto P_0c070b42;
P_0c070b42: /* original a005, guest PC 0x0c070b42 */
if(!s->budget--) { s->failed_pc=0x0c070b42u; return 0; }
goto P_0c070b50;
P_0c070b44: /* original 0009, guest PC 0x0c070b44 */
if(!s->budget--) { s->failed_pc=0x0c070b44u; return 0; }
if(!vf3_matrix_family(0x0c070b46u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c070b46u; return 0; } return 1;
P_0c070b50: /* original f059, guest PC 0x0c070b50 */
if(!s->budget--) { s->failed_pc=0x0c070b50u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b52;
P_0c070b52: /* original f159, guest PC 0x0c070b52 */
if(!s->budget--) { s->failed_pc=0x0c070b52u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b54;
P_0c070b54: /* original f259, guest PC 0x0c070b54 */
if(!s->budget--) { s->failed_pc=0x0c070b54u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b56;
P_0c070b56: /* original f38d, guest PC 0x0c070b56 */
if(!s->budget--) { s->failed_pc=0x0c070b56u; return 0; }
fr[3]=0;
goto P_0c070b58;
P_0c070b58: /* original f0ed, guest PC 0x0c070b58 */
if(!s->budget--) { s->failed_pc=0x0c070b58u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070b5a;
P_0c070b5a: /* original f37d, guest PC 0x0c070b5a */
if(!s->budget--) { s->failed_pc=0x0c070b5au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070b5c;
P_0c070b5c: /* original f342, guest PC 0x0c070b5c */
if(!s->budget--) { s->failed_pc=0x0c070b5cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070b5e;
P_0c070b5e: /* original 740c, guest PC 0x0c070b5e */
if(!s->budget--) { s->failed_pc=0x0c070b5eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c070b60;
P_0c070b60: /* original f232, guest PC 0x0c070b60 */
if(!s->budget--) { s->failed_pc=0x0c070b60u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070b62;
P_0c070b62: /* original f132, guest PC 0x0c070b62 */
if(!s->budget--) { s->failed_pc=0x0c070b62u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070b64;
P_0c070b64: /* original f032, guest PC 0x0c070b64 */
if(!s->budget--) { s->failed_pc=0x0c070b64u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070b66;
P_0c070b66: /* original f42b, guest PC 0x0c070b66 */
if(!s->budget--) { s->failed_pc=0x0c070b66u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070b68;
P_0c070b68: /* original f41b, guest PC 0x0c070b68 */
if(!s->budget--) { s->failed_pc=0x0c070b68u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070b6a;
P_0c070b6a: /* original f40b, guest PC 0x0c070b6a */
if(!s->budget--) { s->failed_pc=0x0c070b6au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070b6c;
P_0c070b6c: /* original d306, guest PC 0x0c070b6c */
if(!s->budget--) { s->failed_pc=0x0c070b6cu; return 0; }
r[3]=read(ram,0x0c070b88u,4);
goto P_0c070b6e;
P_0c070b6e: /* original 432b, guest PC 0x0c070b6e */
if(!s->budget--) { s->failed_pc=0x0c070b6eu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070c14u: goto P_0c070c14;
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
P_0c070b70: /* original 0009, guest PC 0x0c070b70 */
if(!s->budget--) { s->failed_pc=0x0c070b70u; return 0; }
goto P_0c070b72;
P_0c070b72: /* original fe45, guest PC 0x0c070b72 */
if(!s->budget--) { s->failed_pc=0x0c070b72u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[4]))!=0);
goto P_0c070b74;
P_0c070b74: /* original 8902, guest PC 0x0c070b74 */
if(!s->budget--) { s->failed_pc=0x0c070b74u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070b7c; }
goto P_0c070b76;
P_0c070b76: /* original d305, guest PC 0x0c070b76 */
if(!s->budget--) { s->failed_pc=0x0c070b76u; return 0; }
r[3]=read(ram,0x0c070b8cu,4);
goto P_0c070b78;
P_0c070b78: /* original 432b, guest PC 0x0c070b78 */
if(!s->budget--) { s->failed_pc=0x0c070b78u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070c38u: goto P_0c070c38;
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
P_0c070b7a: /* original 0009, guest PC 0x0c070b7a */
if(!s->budget--) { s->failed_pc=0x0c070b7au; return 0; }
goto P_0c070b7c;
P_0c070b7c: /* original 64f3, guest PC 0x0c070b7c */
if(!s->budget--) { s->failed_pc=0x0c070b7cu; return 0; }
r[4]=r[15];
goto P_0c070b7e;
P_0c070b7e: /* original 7438, guest PC 0x0c070b7e */
if(!s->budget--) { s->failed_pc=0x0c070b7eu; return 0; }
r[4]+=0x00000038u;
goto P_0c070b80;
P_0c070b80: /* original 65c3, guest PC 0x0c070b80 */
if(!s->budget--) { s->failed_pc=0x0c070b80u; return 0; }
r[5]=r[12];
goto P_0c070b82;
P_0c070b82: /* original a005, guest PC 0x0c070b82 */
if(!s->budget--) { s->failed_pc=0x0c070b82u; return 0; }
goto P_0c070b90;
P_0c070b84: /* original 0009, guest PC 0x0c070b84 */
if(!s->budget--) { s->failed_pc=0x0c070b84u; return 0; }
if(!vf3_matrix_family(0x0c070b86u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c070b86u; return 0; } return 1;
P_0c070b90: /* original f059, guest PC 0x0c070b90 */
if(!s->budget--) { s->failed_pc=0x0c070b90u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b92;
P_0c070b92: /* original f159, guest PC 0x0c070b92 */
if(!s->budget--) { s->failed_pc=0x0c070b92u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b94;
P_0c070b94: /* original f259, guest PC 0x0c070b94 */
if(!s->budget--) { s->failed_pc=0x0c070b94u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b96;
P_0c070b96: /* original 740c, guest PC 0x0c070b96 */
if(!s->budget--) { s->failed_pc=0x0c070b96u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070b98;
P_0c070b98: /* original f242, guest PC 0x0c070b98 */
if(!s->budget--) { s->failed_pc=0x0c070b98u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c070b9a;
P_0c070b9a: /* original f142, guest PC 0x0c070b9a */
if(!s->budget--) { s->failed_pc=0x0c070b9au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c070b9c;
P_0c070b9c: /* original f042, guest PC 0x0c070b9c */
if(!s->budget--) { s->failed_pc=0x0c070b9cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c070b9e;
P_0c070b9e: /* original f42b, guest PC 0x0c070b9e */
if(!s->budget--) { s->failed_pc=0x0c070b9eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070ba0;
P_0c070ba0: /* original f41b, guest PC 0x0c070ba0 */
if(!s->budget--) { s->failed_pc=0x0c070ba0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070ba2;
P_0c070ba2: /* original f40b, guest PC 0x0c070ba2 */
if(!s->budget--) { s->failed_pc=0x0c070ba2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070ba4;
P_0c070ba4: /* original 65f3, guest PC 0x0c070ba4 */
if(!s->budget--) { s->failed_pc=0x0c070ba4u; return 0; }
r[5]=r[15];
goto P_0c070ba6;
P_0c070ba6: /* original 64f3, guest PC 0x0c070ba6 */
if(!s->budget--) { s->failed_pc=0x0c070ba6u; return 0; }
r[4]=r[15];
goto P_0c070ba8;
P_0c070ba8: /* original 66f3, guest PC 0x0c070ba8 */
if(!s->budget--) { s->failed_pc=0x0c070ba8u; return 0; }
r[6]=r[15];
goto P_0c070baa;
P_0c070baa: /* original 7438, guest PC 0x0c070baa */
if(!s->budget--) { s->failed_pc=0x0c070baau; return 0; }
r[4]+=0x00000038u;
goto P_0c070bac;
P_0c070bac: /* original 7638, guest PC 0x0c070bac */
if(!s->budget--) { s->failed_pc=0x0c070bacu; return 0; }
r[6]+=0x00000038u;
goto P_0c070bae;
P_0c070bae: /* original 7544, guest PC 0x0c070bae */
if(!s->budget--) { s->failed_pc=0x0c070baeu; return 0; }
r[5]+=0x00000044u;
goto P_0c070bb0;
P_0c070bb0: /* original f059, guest PC 0x0c070bb0 */
if(!s->budget--) { s->failed_pc=0x0c070bb0u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070bb2;
P_0c070bb2: /* original f369, guest PC 0x0c070bb2 */
if(!s->budget--) { s->failed_pc=0x0c070bb2u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070bb4;
P_0c070bb4: /* original f159, guest PC 0x0c070bb4 */
if(!s->budget--) { s->failed_pc=0x0c070bb4u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070bb6;
P_0c070bb6: /* original f469, guest PC 0x0c070bb6 */
if(!s->budget--) { s->failed_pc=0x0c070bb6u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070bb8;
P_0c070bb8: /* original f031, guest PC 0x0c070bb8 */
if(!s->budget--) { s->failed_pc=0x0c070bb8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070bba;
P_0c070bba: /* original f258, guest PC 0x0c070bba */
if(!s->budget--) { s->failed_pc=0x0c070bbau; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070bbc;
P_0c070bbc: /* original f568, guest PC 0x0c070bbc */
if(!s->budget--) { s->failed_pc=0x0c070bbcu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070bbe;
P_0c070bbe: /* original f141, guest PC 0x0c070bbe */
if(!s->budget--) { s->failed_pc=0x0c070bbeu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070bc0;
P_0c070bc0: /* original f251, guest PC 0x0c070bc0 */
if(!s->budget--) { s->failed_pc=0x0c070bc0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070bc2;
P_0c070bc2: /* original 7408, guest PC 0x0c070bc2 */
if(!s->budget--) { s->failed_pc=0x0c070bc2u; return 0; }
r[4]+=0x00000008u;
goto P_0c070bc4;
P_0c070bc4: /* original f42a, guest PC 0x0c070bc4 */
if(!s->budget--) { s->failed_pc=0x0c070bc4u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070bc6;
P_0c070bc6: /* original f41b, guest PC 0x0c070bc6 */
if(!s->budget--) { s->failed_pc=0x0c070bc6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070bc8;
P_0c070bc8: /* original f40b, guest PC 0x0c070bc8 */
if(!s->budget--) { s->failed_pc=0x0c070bc8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070bca;
P_0c070bca: /* original 0009, guest PC 0x0c070bca */
if(!s->budget--) { s->failed_pc=0x0c070bcau; return 0; }
goto P_0c070bcc;
P_0c070bcc: /* original f4fc, guest PC 0x0c070bcc */
if(!s->budget--) { s->failed_pc=0x0c070bccu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070bce;
P_0c070bce: /* original f4c1, guest PC 0x0c070bce */
if(!s->budget--) { s->failed_pc=0x0c070bceu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[12],r[18],'-');
goto P_0c070bd0;
P_0c070bd0: /* original 64f3, guest PC 0x0c070bd0 */
if(!s->budget--) { s->failed_pc=0x0c070bd0u; return 0; }
r[4]=r[15];
goto P_0c070bd2;
P_0c070bd2: /* original 65f3, guest PC 0x0c070bd2 */
if(!s->budget--) { s->failed_pc=0x0c070bd2u; return 0; }
r[5]=r[15];
goto P_0c070bd4;
P_0c070bd4: /* original 7438, guest PC 0x0c070bd4 */
if(!s->budget--) { s->failed_pc=0x0c070bd4u; return 0; }
r[4]+=0x00000038u;
goto P_0c070bd6;
P_0c070bd6: /* original 7538, guest PC 0x0c070bd6 */
if(!s->budget--) { s->failed_pc=0x0c070bd6u; return 0; }
r[5]+=0x00000038u;
goto P_0c070bd8;
P_0c070bd8: /* original f059, guest PC 0x0c070bd8 */
if(!s->budget--) { s->failed_pc=0x0c070bd8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070bda;
P_0c070bda: /* original f159, guest PC 0x0c070bda */
if(!s->budget--) { s->failed_pc=0x0c070bdau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070bdc;
P_0c070bdc: /* original f259, guest PC 0x0c070bdc */
if(!s->budget--) { s->failed_pc=0x0c070bdcu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070bde;
P_0c070bde: /* original f38d, guest PC 0x0c070bde */
if(!s->budget--) { s->failed_pc=0x0c070bdeu; return 0; }
fr[3]=0;
goto P_0c070be0;
P_0c070be0: /* original f0ed, guest PC 0x0c070be0 */
if(!s->budget--) { s->failed_pc=0x0c070be0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070be2;
P_0c070be2: /* original f37d, guest PC 0x0c070be2 */
if(!s->budget--) { s->failed_pc=0x0c070be2u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070be4;
P_0c070be4: /* original f342, guest PC 0x0c070be4 */
if(!s->budget--) { s->failed_pc=0x0c070be4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070be6;
P_0c070be6: /* original 740c, guest PC 0x0c070be6 */
if(!s->budget--) { s->failed_pc=0x0c070be6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070be8;
P_0c070be8: /* original f232, guest PC 0x0c070be8 */
if(!s->budget--) { s->failed_pc=0x0c070be8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070bea;
P_0c070bea: /* original f132, guest PC 0x0c070bea */
if(!s->budget--) { s->failed_pc=0x0c070beau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070bec;
P_0c070bec: /* original f032, guest PC 0x0c070bec */
if(!s->budget--) { s->failed_pc=0x0c070becu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070bee;
P_0c070bee: /* original f42b, guest PC 0x0c070bee */
if(!s->budget--) { s->failed_pc=0x0c070beeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070bf0;
P_0c070bf0: /* original f41b, guest PC 0x0c070bf0 */
if(!s->budget--) { s->failed_pc=0x0c070bf0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070bf2;
P_0c070bf2: /* original f40b, guest PC 0x0c070bf2 */
if(!s->budget--) { s->failed_pc=0x0c070bf2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070bf4;
P_0c070bf4: /* original 64f3, guest PC 0x0c070bf4 */
if(!s->budget--) { s->failed_pc=0x0c070bf4u; return 0; }
r[4]=r[15];
goto P_0c070bf6;
P_0c070bf6: /* original 65f3, guest PC 0x0c070bf6 */
if(!s->budget--) { s->failed_pc=0x0c070bf6u; return 0; }
r[5]=r[15];
goto P_0c070bf8;
P_0c070bf8: /* original 7444, guest PC 0x0c070bf8 */
if(!s->budget--) { s->failed_pc=0x0c070bf8u; return 0; }
r[4]+=0x00000044u;
goto P_0c070bfa;
P_0c070bfa: /* original 7538, guest PC 0x0c070bfa */
if(!s->budget--) { s->failed_pc=0x0c070bfau; return 0; }
r[5]+=0x00000038u;
goto P_0c070bfc;
P_0c070bfc: /* original f049, guest PC 0x0c070bfc */
if(!s->budget--) { s->failed_pc=0x0c070bfcu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070bfe;
P_0c070bfe: /* original f359, guest PC 0x0c070bfe */
if(!s->budget--) { s->failed_pc=0x0c070bfeu; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c00;
P_0c070c00: /* original f149, guest PC 0x0c070c00 */
if(!s->budget--) { s->failed_pc=0x0c070c00u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070c02;
P_0c070c02: /* original f459, guest PC 0x0c070c02 */
if(!s->budget--) { s->failed_pc=0x0c070c02u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c04;
P_0c070c04: /* original f249, guest PC 0x0c070c04 */
if(!s->budget--) { s->failed_pc=0x0c070c04u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070c06;
P_0c070c06: /* original f559, guest PC 0x0c070c06 */
if(!s->budget--) { s->failed_pc=0x0c070c06u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c08;
P_0c070c08: /* original f030, guest PC 0x0c070c08 */
if(!s->budget--) { s->failed_pc=0x0c070c08u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070c0a;
P_0c070c0a: /* original f250, guest PC 0x0c070c0a */
if(!s->budget--) { s->failed_pc=0x0c070c0au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070c0c;
P_0c070c0c: /* original f140, guest PC 0x0c070c0c */
if(!s->budget--) { s->failed_pc=0x0c070c0cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070c0e;
P_0c070c0e: /* original f42b, guest PC 0x0c070c0e */
if(!s->budget--) { s->failed_pc=0x0c070c0eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070c10;
P_0c070c10: /* original f41b, guest PC 0x0c070c10 */
if(!s->budget--) { s->failed_pc=0x0c070c10u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070c12;
P_0c070c12: /* original f40b, guest PC 0x0c070c12 */
if(!s->budget--) { s->failed_pc=0x0c070c12u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070c14;
P_0c070c14: /* original 65f3, guest PC 0x0c070c14 */
if(!s->budget--) { s->failed_pc=0x0c070c14u; return 0; }
r[5]=r[15];
goto P_0c070c16;
P_0c070c16: /* original 64e3, guest PC 0x0c070c16 */
if(!s->budget--) { s->failed_pc=0x0c070c16u; return 0; }
r[4]=r[14];
goto P_0c070c18;
P_0c070c18: /* original 7544, guest PC 0x0c070c18 */
if(!s->budget--) { s->failed_pc=0x0c070c18u; return 0; }
r[5]+=0x00000044u;
goto P_0c070c1a;
P_0c070c1a: /* original 6693, guest PC 0x0c070c1a */
if(!s->budget--) { s->failed_pc=0x0c070c1au; return 0; }
r[6]=r[9];
goto P_0c070c1c;
P_0c070c1c: /* original f059, guest PC 0x0c070c1c */
if(!s->budget--) { s->failed_pc=0x0c070c1cu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c1e;
P_0c070c1e: /* original f369, guest PC 0x0c070c1e */
if(!s->budget--) { s->failed_pc=0x0c070c1eu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070c20;
P_0c070c20: /* original f159, guest PC 0x0c070c20 */
if(!s->budget--) { s->failed_pc=0x0c070c20u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c22;
P_0c070c22: /* original f469, guest PC 0x0c070c22 */
if(!s->budget--) { s->failed_pc=0x0c070c22u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070c24;
P_0c070c24: /* original f259, guest PC 0x0c070c24 */
if(!s->budget--) { s->failed_pc=0x0c070c24u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c26;
P_0c070c26: /* original f569, guest PC 0x0c070c26 */
if(!s->budget--) { s->failed_pc=0x0c070c26u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070c28;
P_0c070c28: /* original 740c, guest PC 0x0c070c28 */
if(!s->budget--) { s->failed_pc=0x0c070c28u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070c2a;
P_0c070c2a: /* original f030, guest PC 0x0c070c2a */
if(!s->budget--) { s->failed_pc=0x0c070c2au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070c2c;
P_0c070c2c: /* original f250, guest PC 0x0c070c2c */
if(!s->budget--) { s->failed_pc=0x0c070c2cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070c2e;
P_0c070c2e: /* original f140, guest PC 0x0c070c2e */
if(!s->budget--) { s->failed_pc=0x0c070c2eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070c30;
P_0c070c30: /* original f42b, guest PC 0x0c070c30 */
if(!s->budget--) { s->failed_pc=0x0c070c30u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070c32;
P_0c070c32: /* original f41b, guest PC 0x0c070c32 */
if(!s->budget--) { s->failed_pc=0x0c070c32u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070c34;
P_0c070c34: /* original f40b, guest PC 0x0c070c34 */
if(!s->budget--) { s->failed_pc=0x0c070c34u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070c36;
P_0c070c36: /* original 0009, guest PC 0x0c070c36 */
if(!s->budget--) { s->failed_pc=0x0c070c36u; return 0; }
goto P_0c070c38;
P_0c070c38: /* original 64f3, guest PC 0x0c070c38 */
if(!s->budget--) { s->failed_pc=0x0c070c38u; return 0; }
r[4]=r[15];
goto P_0c070c3a;
P_0c070c3a: /* original 742c, guest PC 0x0c070c3a */
if(!s->budget--) { s->failed_pc=0x0c070c3au; return 0; }
r[4]+=0x0000002cu;
goto P_0c070c3c;
P_0c070c3c: /* original 6683, guest PC 0x0c070c3c */
if(!s->budget--) { s->failed_pc=0x0c070c3cu; return 0; }
r[6]=r[8];
goto P_0c070c3e;
P_0c070c3e: /* original 65e3, guest PC 0x0c070c3e */
if(!s->budget--) { s->failed_pc=0x0c070c3eu; return 0; }
r[5]=r[14];
goto P_0c070c40;
P_0c070c40: /* original f059, guest PC 0x0c070c40 */
if(!s->budget--) { s->failed_pc=0x0c070c40u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c42;
P_0c070c42: /* original f369, guest PC 0x0c070c42 */
if(!s->budget--) { s->failed_pc=0x0c070c42u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070c44;
P_0c070c44: /* original f159, guest PC 0x0c070c44 */
if(!s->budget--) { s->failed_pc=0x0c070c44u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c46;
P_0c070c46: /* original f469, guest PC 0x0c070c46 */
if(!s->budget--) { s->failed_pc=0x0c070c46u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070c48;
P_0c070c48: /* original f031, guest PC 0x0c070c48 */
if(!s->budget--) { s->failed_pc=0x0c070c48u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070c4a;
P_0c070c4a: /* original f258, guest PC 0x0c070c4a */
if(!s->budget--) { s->failed_pc=0x0c070c4au; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070c4c;
P_0c070c4c: /* original f568, guest PC 0x0c070c4c */
if(!s->budget--) { s->failed_pc=0x0c070c4cu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070c4e;
P_0c070c4e: /* original f141, guest PC 0x0c070c4e */
if(!s->budget--) { s->failed_pc=0x0c070c4eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070c50;
P_0c070c50: /* original f251, guest PC 0x0c070c50 */
if(!s->budget--) { s->failed_pc=0x0c070c50u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070c52;
P_0c070c52: /* original 7408, guest PC 0x0c070c52 */
if(!s->budget--) { s->failed_pc=0x0c070c52u; return 0; }
r[4]+=0x00000008u;
goto P_0c070c54;
P_0c070c54: /* original f42a, guest PC 0x0c070c54 */
if(!s->budget--) { s->failed_pc=0x0c070c54u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070c56;
P_0c070c56: /* original f41b, guest PC 0x0c070c56 */
if(!s->budget--) { s->failed_pc=0x0c070c56u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070c58;
P_0c070c58: /* original f40b, guest PC 0x0c070c58 */
if(!s->budget--) { s->failed_pc=0x0c070c58u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070c5a;
P_0c070c5a: /* original 0009, guest PC 0x0c070c5a */
if(!s->budget--) { s->failed_pc=0x0c070c5au; return 0; }
goto P_0c070c5c;
P_0c070c5c: /* original 64f3, guest PC 0x0c070c5c */
if(!s->budget--) { s->failed_pc=0x0c070c5cu; return 0; }
r[4]=r[15];
goto P_0c070c5e;
P_0c070c5e: /* original 742c, guest PC 0x0c070c5e */
if(!s->budget--) { s->failed_pc=0x0c070c5eu; return 0; }
r[4]+=0x0000002cu;
goto P_0c070c60;
P_0c070c60: /* original f049, guest PC 0x0c070c60 */
if(!s->budget--) { s->failed_pc=0x0c070c60u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070c62;
P_0c070c62: /* original f149, guest PC 0x0c070c62 */
if(!s->budget--) { s->failed_pc=0x0c070c62u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070c64;
P_0c070c64: /* original f249, guest PC 0x0c070c64 */
if(!s->budget--) { s->failed_pc=0x0c070c64u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070c66;
P_0c070c66: /* original f38d, guest PC 0x0c070c66 */
if(!s->budget--) { s->failed_pc=0x0c070c66u; return 0; }
fr[3]=0;
goto P_0c070c68;
P_0c070c68: /* original f0ed, guest PC 0x0c070c68 */
if(!s->budget--) { s->failed_pc=0x0c070c68u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070c6a;
P_0c070c6a: /* original f03c, guest PC 0x0c070c6a */
if(!s->budget--) { s->failed_pc=0x0c070c6au; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070c6c;
P_0c070c6c: /* original f06d, guest PC 0x0c070c6c */
if(!s->budget--) { s->failed_pc=0x0c070c6cu; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070c6e;
P_0c070c6e: /* original 0009, guest PC 0x0c070c6e */
if(!s->budget--) { s->failed_pc=0x0c070c6eu; return 0; }
goto P_0c070c70;
P_0c070c70: /* original f38d, guest PC 0x0c070c70 */
if(!s->budget--) { s->failed_pc=0x0c070c70u; return 0; }
fr[3]=0;
goto P_0c070c72;
P_0c070c72: /* original f035, guest PC 0x0c070c72 */
if(!s->budget--) { s->failed_pc=0x0c070c72u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c070c74;
P_0c070c74: /* original 8902, guest PC 0x0c070c74 */
if(!s->budget--) { s->failed_pc=0x0c070c74u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070c7c; }
goto P_0c070c76;
P_0c070c76: /* original d305, guest PC 0x0c070c76 */
if(!s->budget--) { s->failed_pc=0x0c070c76u; return 0; }
r[3]=read(ram,0x0c070c8cu,4);
goto P_0c070c78;
P_0c070c78: /* original 432b, guest PC 0x0c070c78 */
if(!s->budget--) { s->failed_pc=0x0c070c78u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070cd0u: goto P_0c070cd0;
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
P_0c070c7a: /* original 0009, guest PC 0x0c070c7a */
if(!s->budget--) { s->failed_pc=0x0c070c7au; return 0; }
goto P_0c070c7c;
P_0c070c7c: /* original 64f3, guest PC 0x0c070c7c */
if(!s->budget--) { s->failed_pc=0x0c070c7cu; return 0; }
r[4]=r[15];
goto P_0c070c7e;
P_0c070c7e: /* original 65f3, guest PC 0x0c070c7e */
if(!s->budget--) { s->failed_pc=0x0c070c7eu; return 0; }
r[5]=r[15];
goto P_0c070c80;
P_0c070c80: /* original 742c, guest PC 0x0c070c80 */
if(!s->budget--) { s->failed_pc=0x0c070c80u; return 0; }
r[4]+=0x0000002cu;
goto P_0c070c82;
P_0c070c82: /* original f4dc, guest PC 0x0c070c82 */
if(!s->budget--) { s->failed_pc=0x0c070c82u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c070c84;
P_0c070c84: /* original 752c, guest PC 0x0c070c84 */
if(!s->budget--) { s->failed_pc=0x0c070c84u; return 0; }
r[5]+=0x0000002cu;
goto P_0c070c86;
P_0c070c86: /* original a003, guest PC 0x0c070c86 */
if(!s->budget--) { s->failed_pc=0x0c070c86u; return 0; }
goto P_0c070c90;
P_0c070c88: /* original 0009, guest PC 0x0c070c88 */
if(!s->budget--) { s->failed_pc=0x0c070c88u; return 0; }
if(!vf3_matrix_family(0x0c070c8au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c070c8au; return 0; } return 1;
P_0c070c90: /* original f059, guest PC 0x0c070c90 */
if(!s->budget--) { s->failed_pc=0x0c070c90u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c92;
P_0c070c92: /* original f159, guest PC 0x0c070c92 */
if(!s->budget--) { s->failed_pc=0x0c070c92u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c94;
P_0c070c94: /* original f259, guest PC 0x0c070c94 */
if(!s->budget--) { s->failed_pc=0x0c070c94u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c96;
P_0c070c96: /* original f38d, guest PC 0x0c070c96 */
if(!s->budget--) { s->failed_pc=0x0c070c96u; return 0; }
fr[3]=0;
goto P_0c070c98;
P_0c070c98: /* original f0ed, guest PC 0x0c070c98 */
if(!s->budget--) { s->failed_pc=0x0c070c98u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070c9a;
P_0c070c9a: /* original f37d, guest PC 0x0c070c9a */
if(!s->budget--) { s->failed_pc=0x0c070c9au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070c9c;
P_0c070c9c: /* original f342, guest PC 0x0c070c9c */
if(!s->budget--) { s->failed_pc=0x0c070c9cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070c9e;
P_0c070c9e: /* original 740c, guest PC 0x0c070c9e */
if(!s->budget--) { s->failed_pc=0x0c070c9eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c070ca0;
P_0c070ca0: /* original f232, guest PC 0x0c070ca0 */
if(!s->budget--) { s->failed_pc=0x0c070ca0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070ca2;
P_0c070ca2: /* original f132, guest PC 0x0c070ca2 */
if(!s->budget--) { s->failed_pc=0x0c070ca2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070ca4;
P_0c070ca4: /* original f032, guest PC 0x0c070ca4 */
if(!s->budget--) { s->failed_pc=0x0c070ca4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070ca6;
P_0c070ca6: /* original f42b, guest PC 0x0c070ca6 */
if(!s->budget--) { s->failed_pc=0x0c070ca6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070ca8;
P_0c070ca8: /* original f41b, guest PC 0x0c070ca8 */
if(!s->budget--) { s->failed_pc=0x0c070ca8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070caa;
P_0c070caa: /* original f40b, guest PC 0x0c070caa */
if(!s->budget--) { s->failed_pc=0x0c070caau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070cac;
P_0c070cac: /* original 66f3, guest PC 0x0c070cac */
if(!s->budget--) { s->failed_pc=0x0c070cacu; return 0; }
r[6]=r[15];
goto P_0c070cae;
P_0c070cae: /* original 64e3, guest PC 0x0c070cae */
if(!s->budget--) { s->failed_pc=0x0c070caeu; return 0; }
r[4]=r[14];
goto P_0c070cb0;
P_0c070cb0: /* original 6583, guest PC 0x0c070cb0 */
if(!s->budget--) { s->failed_pc=0x0c070cb0u; return 0; }
r[5]=r[8];
goto P_0c070cb2;
P_0c070cb2: /* original 762c, guest PC 0x0c070cb2 */
if(!s->budget--) { s->failed_pc=0x0c070cb2u; return 0; }
r[6]+=0x0000002cu;
goto P_0c070cb4;
P_0c070cb4: /* original f059, guest PC 0x0c070cb4 */
if(!s->budget--) { s->failed_pc=0x0c070cb4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070cb6;
P_0c070cb6: /* original f369, guest PC 0x0c070cb6 */
if(!s->budget--) { s->failed_pc=0x0c070cb6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070cb8;
P_0c070cb8: /* original f159, guest PC 0x0c070cb8 */
if(!s->budget--) { s->failed_pc=0x0c070cb8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070cba;
P_0c070cba: /* original f469, guest PC 0x0c070cba */
if(!s->budget--) { s->failed_pc=0x0c070cbau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070cbc;
P_0c070cbc: /* original f259, guest PC 0x0c070cbc */
if(!s->budget--) { s->failed_pc=0x0c070cbcu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070cbe;
P_0c070cbe: /* original f569, guest PC 0x0c070cbe */
if(!s->budget--) { s->failed_pc=0x0c070cbeu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070cc0;
P_0c070cc0: /* original 740c, guest PC 0x0c070cc0 */
if(!s->budget--) { s->failed_pc=0x0c070cc0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070cc2;
P_0c070cc2: /* original f030, guest PC 0x0c070cc2 */
if(!s->budget--) { s->failed_pc=0x0c070cc2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070cc4;
P_0c070cc4: /* original f250, guest PC 0x0c070cc4 */
if(!s->budget--) { s->failed_pc=0x0c070cc4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070cc6;
P_0c070cc6: /* original f140, guest PC 0x0c070cc6 */
if(!s->budget--) { s->failed_pc=0x0c070cc6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070cc8;
P_0c070cc8: /* original f42b, guest PC 0x0c070cc8 */
if(!s->budget--) { s->failed_pc=0x0c070cc8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070cca;
P_0c070cca: /* original f41b, guest PC 0x0c070cca */
if(!s->budget--) { s->failed_pc=0x0c070ccau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070ccc;
P_0c070ccc: /* original f40b, guest PC 0x0c070ccc */
if(!s->budget--) { s->failed_pc=0x0c070cccu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070cce;
P_0c070cce: /* original 0009, guest PC 0x0c070cce */
if(!s->budget--) { s->failed_pc=0x0c070cceu; return 0; }
goto P_0c070cd0;
P_0c070cd0: /* original 64f3, guest PC 0x0c070cd0 */
if(!s->budget--) { s->failed_pc=0x0c070cd0u; return 0; }
r[4]=r[15];
goto P_0c070cd2;
P_0c070cd2: /* original 7444, guest PC 0x0c070cd2 */
if(!s->budget--) { s->failed_pc=0x0c070cd2u; return 0; }
r[4]+=0x00000044u;
goto P_0c070cd4;
P_0c070cd4: /* original 66a3, guest PC 0x0c070cd4 */
if(!s->budget--) { s->failed_pc=0x0c070cd4u; return 0; }
r[6]=r[10];
goto P_0c070cd6;
P_0c070cd6: /* original 65d3, guest PC 0x0c070cd6 */
if(!s->budget--) { s->failed_pc=0x0c070cd6u; return 0; }
r[5]=r[13];
goto P_0c070cd8;
P_0c070cd8: /* original f059, guest PC 0x0c070cd8 */
if(!s->budget--) { s->failed_pc=0x0c070cd8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070cda;
P_0c070cda: /* original f369, guest PC 0x0c070cda */
if(!s->budget--) { s->failed_pc=0x0c070cdau; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070cdc;
P_0c070cdc: /* original f159, guest PC 0x0c070cdc */
if(!s->budget--) { s->failed_pc=0x0c070cdcu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070cde;
P_0c070cde: /* original f469, guest PC 0x0c070cde */
if(!s->budget--) { s->failed_pc=0x0c070cdeu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070ce0;
P_0c070ce0: /* original f031, guest PC 0x0c070ce0 */
if(!s->budget--) { s->failed_pc=0x0c070ce0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070ce2;
P_0c070ce2: /* original f258, guest PC 0x0c070ce2 */
if(!s->budget--) { s->failed_pc=0x0c070ce2u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070ce4;
P_0c070ce4: /* original f568, guest PC 0x0c070ce4 */
if(!s->budget--) { s->failed_pc=0x0c070ce4u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070ce6;
P_0c070ce6: /* original f141, guest PC 0x0c070ce6 */
if(!s->budget--) { s->failed_pc=0x0c070ce6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070ce8;
P_0c070ce8: /* original f251, guest PC 0x0c070ce8 */
if(!s->budget--) { s->failed_pc=0x0c070ce8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070cea;
P_0c070cea: /* original 7408, guest PC 0x0c070cea */
if(!s->budget--) { s->failed_pc=0x0c070ceau; return 0; }
r[4]+=0x00000008u;
goto P_0c070cec;
P_0c070cec: /* original f42a, guest PC 0x0c070cec */
if(!s->budget--) { s->failed_pc=0x0c070cecu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070cee;
P_0c070cee: /* original f41b, guest PC 0x0c070cee */
if(!s->budget--) { s->failed_pc=0x0c070ceeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070cf0;
P_0c070cf0: /* original f40b, guest PC 0x0c070cf0 */
if(!s->budget--) { s->failed_pc=0x0c070cf0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070cf2;
P_0c070cf2: /* original 0009, guest PC 0x0c070cf2 */
if(!s->budget--) { s->failed_pc=0x0c070cf2u; return 0; }
goto P_0c070cf4;
P_0c070cf4: /* original 64f3, guest PC 0x0c070cf4 */
if(!s->budget--) { s->failed_pc=0x0c070cf4u; return 0; }
r[4]=r[15];
goto P_0c070cf6;
P_0c070cf6: /* original 7444, guest PC 0x0c070cf6 */
if(!s->budget--) { s->failed_pc=0x0c070cf6u; return 0; }
r[4]+=0x00000044u;
goto P_0c070cf8;
P_0c070cf8: /* original f049, guest PC 0x0c070cf8 */
if(!s->budget--) { s->failed_pc=0x0c070cf8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070cfa;
P_0c070cfa: /* original f149, guest PC 0x0c070cfa */
if(!s->budget--) { s->failed_pc=0x0c070cfau; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070cfc;
P_0c070cfc: /* original f249, guest PC 0x0c070cfc */
if(!s->budget--) { s->failed_pc=0x0c070cfcu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070cfe;
P_0c070cfe: /* original f38d, guest PC 0x0c070cfe */
if(!s->budget--) { s->failed_pc=0x0c070cfeu; return 0; }
fr[3]=0;
goto P_0c070d00;
P_0c070d00: /* original f0ed, guest PC 0x0c070d00 */
if(!s->budget--) { s->failed_pc=0x0c070d00u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070d02;
P_0c070d02: /* original f03c, guest PC 0x0c070d02 */
if(!s->budget--) { s->failed_pc=0x0c070d02u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070d04;
P_0c070d04: /* original f06d, guest PC 0x0c070d04 */
if(!s->budget--) { s->failed_pc=0x0c070d04u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070d06;
P_0c070d06: /* original 0009, guest PC 0x0c070d06 */
if(!s->budget--) { s->failed_pc=0x0c070d06u; return 0; }
goto P_0c070d08;
P_0c070d08: /* original f38d, guest PC 0x0c070d08 */
if(!s->budget--) { s->failed_pc=0x0c070d08u; return 0; }
fr[3]=0;
goto P_0c070d0a;
P_0c070d0a: /* original fc0c, guest PC 0x0c070d0a */
if(!s->budget--) { s->failed_pc=0x0c070d0au; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c070d0c;
P_0c070d0c: /* original fc35, guest PC 0x0c070d0c */
if(!s->budget--) { s->failed_pc=0x0c070d0cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[12])>as_float(fr[3]))!=0);
goto P_0c070d0e;
P_0c070d0e: /* original 8902, guest PC 0x0c070d0e */
if(!s->budget--) { s->failed_pc=0x0c070d0eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070d16; }
goto P_0c070d10;
P_0c070d10: /* original d303, guest PC 0x0c070d10 */
if(!s->budget--) { s->failed_pc=0x0c070d10u; return 0; }
r[3]=read(ram,0x0c070d20u,4);
goto P_0c070d12;
P_0c070d12: /* original 432b, guest PC 0x0c070d12 */
if(!s->budget--) { s->failed_pc=0x0c070d12u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070ea0u: goto P_0c070ea0;
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
P_0c070d14: /* original 0009, guest PC 0x0c070d14 */
if(!s->budget--) { s->failed_pc=0x0c070d14u; return 0; }
goto P_0c070d16;
P_0c070d16: /* original 64f3, guest PC 0x0c070d16 */
if(!s->budget--) { s->failed_pc=0x0c070d16u; return 0; }
r[4]=r[15];
goto P_0c070d18;
P_0c070d18: /* original 7444, guest PC 0x0c070d18 */
if(!s->budget--) { s->failed_pc=0x0c070d18u; return 0; }
r[4]+=0x00000044u;
goto P_0c070d1a;
P_0c070d1a: /* original 65b3, guest PC 0x0c070d1a */
if(!s->budget--) { s->failed_pc=0x0c070d1au; return 0; }
r[5]=r[11];
goto P_0c070d1c;
P_0c070d1c: /* original a002, guest PC 0x0c070d1c */
if(!s->budget--) { s->failed_pc=0x0c070d1cu; return 0; }
goto P_0c070d24;
P_0c070d1e: /* original 0009, guest PC 0x0c070d1e */
if(!s->budget--) { s->failed_pc=0x0c070d1eu; return 0; }
if(!vf3_matrix_family(0x0c070d20u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c070d20u; return 0; } return 1;
P_0c070d24: /* original f049, guest PC 0x0c070d24 */
if(!s->budget--) { s->failed_pc=0x0c070d24u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070d26;
P_0c070d26: /* original f549, guest PC 0x0c070d26 */
if(!s->budget--) { s->failed_pc=0x0c070d26u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070d28;
P_0c070d28: /* original f648, guest PC 0x0c070d28 */
if(!s->budget--) { s->failed_pc=0x0c070d28u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c070d2a;
P_0c070d2a: /* original f859, guest PC 0x0c070d2a */
if(!s->budget--) { s->failed_pc=0x0c070d2au; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070d2c;
P_0c070d2c: /* original f959, guest PC 0x0c070d2c */
if(!s->budget--) { s->failed_pc=0x0c070d2cu; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070d2e;
P_0c070d2e: /* original fa58, guest PC 0x0c070d2e */
if(!s->budget--) { s->failed_pc=0x0c070d2eu; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c070d30;
P_0c070d30: /* original f35c, guest PC 0x0c070d30 */
if(!s->budget--) { s->failed_pc=0x0c070d30u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c070d32;
P_0c070d32: /* original f382, guest PC 0x0c070d32 */
if(!s->budget--) { s->failed_pc=0x0c070d32u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c070d34;
P_0c070d34: /* original f20c, guest PC 0x0c070d34 */
if(!s->budget--) { s->failed_pc=0x0c070d34u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c070d36;
P_0c070d36: /* original f2a2, guest PC 0x0c070d36 */
if(!s->budget--) { s->failed_pc=0x0c070d36u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c070d38;
P_0c070d38: /* original f16c, guest PC 0x0c070d38 */
if(!s->budget--) { s->failed_pc=0x0c070d38u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c070d3a;
P_0c070d3a: /* original f192, guest PC 0x0c070d3a */
if(!s->budget--) { s->failed_pc=0x0c070d3au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c070d3c;
P_0c070d3c: /* original f34d, guest PC 0x0c070d3c */
if(!s->budget--) { s->failed_pc=0x0c070d3cu; return 0; }
fr[3]^=0x80000000u;
goto P_0c070d3e;
P_0c070d3e: /* original f39e, guest PC 0x0c070d3e */
if(!s->budget--) { s->failed_pc=0x0c070d3eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c070d40;
P_0c070d40: /* original f24d, guest PC 0x0c070d40 */
if(!s->budget--) { s->failed_pc=0x0c070d40u; return 0; }
fr[2]^=0x80000000u;
goto P_0c070d42;
P_0c070d42: /* original f06c, guest PC 0x0c070d42 */
if(!s->budget--) { s->failed_pc=0x0c070d42u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c070d44;
P_0c070d44: /* original f28e, guest PC 0x0c070d44 */
if(!s->budget--) { s->failed_pc=0x0c070d44u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c070d46;
P_0c070d46: /* original f14d, guest PC 0x0c070d46 */
if(!s->budget--) { s->failed_pc=0x0c070d46u; return 0; }
fr[1]^=0x80000000u;
goto P_0c070d48;
P_0c070d48: /* original f05c, guest PC 0x0c070d48 */
if(!s->budget--) { s->failed_pc=0x0c070d48u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c070d4a;
P_0c070d4a: /* original f1ae, guest PC 0x0c070d4a */
if(!s->budget--) { s->failed_pc=0x0c070d4au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c070d4c;
P_0c070d4c: /* original f08d, guest PC 0x0c070d4c */
if(!s->budget--) { s->failed_pc=0x0c070d4cu; return 0; }
fr[0]=0;
goto P_0c070d4e;
P_0c070d4e: /* original f0ed, guest PC 0x0c070d4e */
if(!s->budget--) { s->failed_pc=0x0c070d4eu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070d50;
P_0c070d50: /* original f03c, guest PC 0x0c070d50 */
if(!s->budget--) { s->failed_pc=0x0c070d50u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070d52;
P_0c070d52: /* original f06d, guest PC 0x0c070d52 */
if(!s->budget--) { s->failed_pc=0x0c070d52u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070d54;
P_0c070d54: /* original ff05, guest PC 0x0c070d54 */
if(!s->budget--) { s->failed_pc=0x0c070d54u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[0]))!=0);
goto P_0c070d56;
P_0c070d56: /* original e01c, guest PC 0x0c070d56 */
if(!s->budget--) { s->failed_pc=0x0c070d56u; return 0; }
r[0]=0x0000001cu;
goto P_0c070d58;
P_0c070d58: /* original 8d03, guest PC 0x0c070d58 */
if(!s->budget--) { s->failed_pc=0x0c070d58u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(cond) { goto P_0c070d62; }
goto P_0c070d5c;
P_0c070d5a: /* original ff07, guest PC 0x0c070d5a */
if(!s->budget--) { s->failed_pc=0x0c070d5au; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c070d5c;
P_0c070d5c: /* original d303, guest PC 0x0c070d5c */
if(!s->budget--) { s->failed_pc=0x0c070d5cu; return 0; }
r[3]=read(ram,0x0c070d6cu,4);
goto P_0c070d5e;
P_0c070d5e: /* original 432b, guest PC 0x0c070d5e */
if(!s->budget--) { s->failed_pc=0x0c070d5eu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070ea0u: goto P_0c070ea0;
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
P_0c070d60: /* original 0009, guest PC 0x0c070d60 */
if(!s->budget--) { s->failed_pc=0x0c070d60u; return 0; }
goto P_0c070d62;
P_0c070d62: /* original 64f3, guest PC 0x0c070d62 */
if(!s->budget--) { s->failed_pc=0x0c070d62u; return 0; }
r[4]=r[15];
goto P_0c070d64;
P_0c070d64: /* original 7444, guest PC 0x0c070d64 */
if(!s->budget--) { s->failed_pc=0x0c070d64u; return 0; }
r[4]+=0x00000044u;
goto P_0c070d66;
P_0c070d66: /* original 65b3, guest PC 0x0c070d66 */
if(!s->budget--) { s->failed_pc=0x0c070d66u; return 0; }
r[5]=r[11];
goto P_0c070d68;
P_0c070d68: /* original a002, guest PC 0x0c070d68 */
if(!s->budget--) { s->failed_pc=0x0c070d68u; return 0; }
goto P_0c070d70;
P_0c070d6a: /* original 0009, guest PC 0x0c070d6a */
if(!s->budget--) { s->failed_pc=0x0c070d6au; return 0; }
if(!vf3_matrix_family(0x0c070d6cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c070d6cu; return 0; } return 1;
P_0c070d70: /* original f049, guest PC 0x0c070d70 */
if(!s->budget--) { s->failed_pc=0x0c070d70u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070d72;
P_0c070d72: /* original f149, guest PC 0x0c070d72 */
if(!s->budget--) { s->failed_pc=0x0c070d72u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070d74;
P_0c070d74: /* original f249, guest PC 0x0c070d74 */
if(!s->budget--) { s->failed_pc=0x0c070d74u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070d76;
P_0c070d76: /* original f38d, guest PC 0x0c070d76 */
if(!s->budget--) { s->failed_pc=0x0c070d76u; return 0; }
fr[3]=0;
goto P_0c070d78;
P_0c070d78: /* original f459, guest PC 0x0c070d78 */
if(!s->budget--) { s->failed_pc=0x0c070d78u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070d7a;
P_0c070d7a: /* original f559, guest PC 0x0c070d7a */
if(!s->budget--) { s->failed_pc=0x0c070d7au; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070d7c;
P_0c070d7c: /* original f659, guest PC 0x0c070d7c */
if(!s->budget--) { s->failed_pc=0x0c070d7cu; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070d7e;
P_0c070d7e: /* original f78d, guest PC 0x0c070d7e */
if(!s->budget--) { s->failed_pc=0x0c070d7eu; return 0; }
fr[7]=0;
goto P_0c070d80;
P_0c070d80: /* original f4ed, guest PC 0x0c070d80 */
if(!s->budget--) { s->failed_pc=0x0c070d80u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c070d82;
P_0c070d82: /* original f07c, guest PC 0x0c070d82 */
if(!s->budget--) { s->failed_pc=0x0c070d82u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c070d84;
P_0c070d84: /* original f38d, guest PC 0x0c070d84 */
if(!s->budget--) { s->failed_pc=0x0c070d84u; return 0; }
fr[3]=0;
goto P_0c070d86;
P_0c070d86: /* original f40c, guest PC 0x0c070d86 */
if(!s->budget--) { s->failed_pc=0x0c070d86u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c070d88;
P_0c070d88: /* original f345, guest PC 0x0c070d88 */
if(!s->budget--) { s->failed_pc=0x0c070d88u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c070d8a;
P_0c070d8a: /* original 8902, guest PC 0x0c070d8a */
if(!s->budget--) { s->failed_pc=0x0c070d8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070d92; }
goto P_0c070d8c;
P_0c070d8c: /* original d307, guest PC 0x0c070d8c */
if(!s->budget--) { s->failed_pc=0x0c070d8cu; return 0; }
r[3]=read(ram,0x0c070dacu,4);
goto P_0c070d8e;
P_0c070d8e: /* original 432b, guest PC 0x0c070d8e */
if(!s->budget--) { s->failed_pc=0x0c070d8eu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070dd6u: goto P_0c070dd6;
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
P_0c070d90: /* original 0009, guest PC 0x0c070d90 */
if(!s->budget--) { s->failed_pc=0x0c070d90u; return 0; }
goto P_0c070d92;
P_0c070d92: /* original ffc5, guest PC 0x0c070d92 */
if(!s->budget--) { s->failed_pc=0x0c070d92u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[12]))!=0);
goto P_0c070d94;
P_0c070d94: /* original 8902, guest PC 0x0c070d94 */
if(!s->budget--) { s->failed_pc=0x0c070d94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070d9c; }
goto P_0c070d96;
P_0c070d96: /* original d206, guest PC 0x0c070d96 */
if(!s->budget--) { s->failed_pc=0x0c070d96u; return 0; }
r[2]=read(ram,0x0c070db0u,4);
goto P_0c070d98;
P_0c070d98: /* original 422b, guest PC 0x0c070d98 */
if(!s->budget--) { s->failed_pc=0x0c070d98u; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070ea0u: goto P_0c070ea0;
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
P_0c070d9a: /* original 0009, guest PC 0x0c070d9a */
if(!s->budget--) { s->failed_pc=0x0c070d9au; return 0; }
goto P_0c070d9c;
P_0c070d9c: /* original 64f3, guest PC 0x0c070d9c */
if(!s->budget--) { s->failed_pc=0x0c070d9cu; return 0; }
r[4]=r[15];
goto P_0c070d9e;
P_0c070d9e: /* original 65f3, guest PC 0x0c070d9e */
if(!s->budget--) { s->failed_pc=0x0c070d9eu; return 0; }
r[5]=r[15];
goto P_0c070da0;
P_0c070da0: /* original 7444, guest PC 0x0c070da0 */
if(!s->budget--) { s->failed_pc=0x0c070da0u; return 0; }
r[4]+=0x00000044u;
goto P_0c070da2;
P_0c070da2: /* original f4fc, guest PC 0x0c070da2 */
if(!s->budget--) { s->failed_pc=0x0c070da2u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070da4;
P_0c070da4: /* original 7544, guest PC 0x0c070da4 */
if(!s->budget--) { s->failed_pc=0x0c070da4u; return 0; }
r[5]+=0x00000044u;
goto P_0c070da6;
P_0c070da6: /* original a005, guest PC 0x0c070da6 */
if(!s->budget--) { s->failed_pc=0x0c070da6u; return 0; }
goto P_0c070db4;
P_0c070da8: /* original 0009, guest PC 0x0c070da8 */
if(!s->budget--) { s->failed_pc=0x0c070da8u; return 0; }
if(!vf3_matrix_family(0x0c070daau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c070daau; return 0; } return 1;
P_0c070db4: /* original f059, guest PC 0x0c070db4 */
if(!s->budget--) { s->failed_pc=0x0c070db4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070db6;
P_0c070db6: /* original f159, guest PC 0x0c070db6 */
if(!s->budget--) { s->failed_pc=0x0c070db6u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070db8;
P_0c070db8: /* original f259, guest PC 0x0c070db8 */
if(!s->budget--) { s->failed_pc=0x0c070db8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070dba;
P_0c070dba: /* original f38d, guest PC 0x0c070dba */
if(!s->budget--) { s->failed_pc=0x0c070dbau; return 0; }
fr[3]=0;
goto P_0c070dbc;
P_0c070dbc: /* original f0ed, guest PC 0x0c070dbc */
if(!s->budget--) { s->failed_pc=0x0c070dbcu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070dbe;
P_0c070dbe: /* original f37d, guest PC 0x0c070dbe */
if(!s->budget--) { s->failed_pc=0x0c070dbeu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070dc0;
P_0c070dc0: /* original f342, guest PC 0x0c070dc0 */
if(!s->budget--) { s->failed_pc=0x0c070dc0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070dc2;
P_0c070dc2: /* original 740c, guest PC 0x0c070dc2 */
if(!s->budget--) { s->failed_pc=0x0c070dc2u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070dc4;
P_0c070dc4: /* original f232, guest PC 0x0c070dc4 */
if(!s->budget--) { s->failed_pc=0x0c070dc4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070dc6;
P_0c070dc6: /* original f132, guest PC 0x0c070dc6 */
if(!s->budget--) { s->failed_pc=0x0c070dc6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070dc8;
P_0c070dc8: /* original f032, guest PC 0x0c070dc8 */
if(!s->budget--) { s->failed_pc=0x0c070dc8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070dca;
P_0c070dca: /* original f42b, guest PC 0x0c070dca */
if(!s->budget--) { s->failed_pc=0x0c070dcau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070dcc;
P_0c070dcc: /* original f41b, guest PC 0x0c070dcc */
if(!s->budget--) { s->failed_pc=0x0c070dccu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070dce;
P_0c070dce: /* original f40b, guest PC 0x0c070dce */
if(!s->budget--) { s->failed_pc=0x0c070dceu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070dd0;
P_0c070dd0: /* original d206, guest PC 0x0c070dd0 */
if(!s->budget--) { s->failed_pc=0x0c070dd0u; return 0; }
r[2]=read(ram,0x0c070decu,4);
goto P_0c070dd2;
P_0c070dd2: /* original 422b, guest PC 0x0c070dd2 */
if(!s->budget--) { s->failed_pc=0x0c070dd2u; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070e7cu: goto P_0c070e7c;
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
P_0c070dd4: /* original 0009, guest PC 0x0c070dd4 */
if(!s->budget--) { s->failed_pc=0x0c070dd4u; return 0; }
goto P_0c070dd6;
P_0c070dd6: /* original fe45, guest PC 0x0c070dd6 */
if(!s->budget--) { s->failed_pc=0x0c070dd6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[4]))!=0);
goto P_0c070dd8;
P_0c070dd8: /* original 8902, guest PC 0x0c070dd8 */
if(!s->budget--) { s->failed_pc=0x0c070dd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070de0; }
goto P_0c070dda;
P_0c070dda: /* original d205, guest PC 0x0c070dda */
if(!s->budget--) { s->failed_pc=0x0c070ddau; return 0; }
r[2]=read(ram,0x0c070df0u,4);
goto P_0c070ddc;
P_0c070ddc: /* original 422b, guest PC 0x0c070ddc */
if(!s->budget--) { s->failed_pc=0x0c070ddcu; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070ea0u: goto P_0c070ea0;
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
P_0c070dde: /* original 0009, guest PC 0x0c070dde */
if(!s->budget--) { s->failed_pc=0x0c070ddeu; return 0; }
goto P_0c070de0;
P_0c070de0: /* original 64f3, guest PC 0x0c070de0 */
if(!s->budget--) { s->failed_pc=0x0c070de0u; return 0; }
r[4]=r[15];
goto P_0c070de2;
P_0c070de2: /* original 7438, guest PC 0x0c070de2 */
if(!s->budget--) { s->failed_pc=0x0c070de2u; return 0; }
r[4]+=0x00000038u;
goto P_0c070de4;
P_0c070de4: /* original 65b3, guest PC 0x0c070de4 */
if(!s->budget--) { s->failed_pc=0x0c070de4u; return 0; }
r[5]=r[11];
goto P_0c070de6;
P_0c070de6: /* original a005, guest PC 0x0c070de6 */
if(!s->budget--) { s->failed_pc=0x0c070de6u; return 0; }
goto P_0c070df4;
P_0c070de8: /* original 0009, guest PC 0x0c070de8 */
if(!s->budget--) { s->failed_pc=0x0c070de8u; return 0; }
if(!vf3_matrix_family(0x0c070deau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c070deau; return 0; } return 1;
P_0c070df4: /* original f059, guest PC 0x0c070df4 */
if(!s->budget--) { s->failed_pc=0x0c070df4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070df6;
P_0c070df6: /* original f159, guest PC 0x0c070df6 */
if(!s->budget--) { s->failed_pc=0x0c070df6u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070df8;
P_0c070df8: /* original f259, guest PC 0x0c070df8 */
if(!s->budget--) { s->failed_pc=0x0c070df8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070dfa;
P_0c070dfa: /* original 740c, guest PC 0x0c070dfa */
if(!s->budget--) { s->failed_pc=0x0c070dfau; return 0; }
r[4]+=0x0000000cu;
goto P_0c070dfc;
P_0c070dfc: /* original f242, guest PC 0x0c070dfc */
if(!s->budget--) { s->failed_pc=0x0c070dfcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c070dfe;
P_0c070dfe: /* original f142, guest PC 0x0c070dfe */
if(!s->budget--) { s->failed_pc=0x0c070dfeu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c070e00;
P_0c070e00: /* original f042, guest PC 0x0c070e00 */
if(!s->budget--) { s->failed_pc=0x0c070e00u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c070e02;
P_0c070e02: /* original f42b, guest PC 0x0c070e02 */
if(!s->budget--) { s->failed_pc=0x0c070e02u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070e04;
P_0c070e04: /* original f41b, guest PC 0x0c070e04 */
if(!s->budget--) { s->failed_pc=0x0c070e04u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070e06;
P_0c070e06: /* original f40b, guest PC 0x0c070e06 */
if(!s->budget--) { s->failed_pc=0x0c070e06u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070e08;
P_0c070e08: /* original 65f3, guest PC 0x0c070e08 */
if(!s->budget--) { s->failed_pc=0x0c070e08u; return 0; }
r[5]=r[15];
goto P_0c070e0a;
P_0c070e0a: /* original 64f3, guest PC 0x0c070e0a */
if(!s->budget--) { s->failed_pc=0x0c070e0au; return 0; }
r[4]=r[15];
goto P_0c070e0c;
P_0c070e0c: /* original 66f3, guest PC 0x0c070e0c */
if(!s->budget--) { s->failed_pc=0x0c070e0cu; return 0; }
r[6]=r[15];
goto P_0c070e0e;
P_0c070e0e: /* original 7438, guest PC 0x0c070e0e */
if(!s->budget--) { s->failed_pc=0x0c070e0eu; return 0; }
r[4]+=0x00000038u;
goto P_0c070e10;
P_0c070e10: /* original 7638, guest PC 0x0c070e10 */
if(!s->budget--) { s->failed_pc=0x0c070e10u; return 0; }
r[6]+=0x00000038u;
goto P_0c070e12;
P_0c070e12: /* original 7544, guest PC 0x0c070e12 */
if(!s->budget--) { s->failed_pc=0x0c070e12u; return 0; }
r[5]+=0x00000044u;
goto P_0c070e14;
P_0c070e14: /* original f059, guest PC 0x0c070e14 */
if(!s->budget--) { s->failed_pc=0x0c070e14u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e16;
P_0c070e16: /* original f369, guest PC 0x0c070e16 */
if(!s->budget--) { s->failed_pc=0x0c070e16u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070e18;
P_0c070e18: /* original f159, guest PC 0x0c070e18 */
if(!s->budget--) { s->failed_pc=0x0c070e18u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e1a;
P_0c070e1a: /* original f469, guest PC 0x0c070e1a */
if(!s->budget--) { s->failed_pc=0x0c070e1au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070e1c;
P_0c070e1c: /* original f031, guest PC 0x0c070e1c */
if(!s->budget--) { s->failed_pc=0x0c070e1cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070e1e;
P_0c070e1e: /* original f258, guest PC 0x0c070e1e */
if(!s->budget--) { s->failed_pc=0x0c070e1eu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070e20;
P_0c070e20: /* original f568, guest PC 0x0c070e20 */
if(!s->budget--) { s->failed_pc=0x0c070e20u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070e22;
P_0c070e22: /* original f141, guest PC 0x0c070e22 */
if(!s->budget--) { s->failed_pc=0x0c070e22u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070e24;
P_0c070e24: /* original f251, guest PC 0x0c070e24 */
if(!s->budget--) { s->failed_pc=0x0c070e24u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070e26;
P_0c070e26: /* original 7408, guest PC 0x0c070e26 */
if(!s->budget--) { s->failed_pc=0x0c070e26u; return 0; }
r[4]+=0x00000008u;
goto P_0c070e28;
P_0c070e28: /* original f42a, guest PC 0x0c070e28 */
if(!s->budget--) { s->failed_pc=0x0c070e28u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070e2a;
P_0c070e2a: /* original f41b, guest PC 0x0c070e2a */
if(!s->budget--) { s->failed_pc=0x0c070e2au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070e2c;
P_0c070e2c: /* original f40b, guest PC 0x0c070e2c */
if(!s->budget--) { s->failed_pc=0x0c070e2cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070e2e;
P_0c070e2e: /* original 0009, guest PC 0x0c070e2e */
if(!s->budget--) { s->failed_pc=0x0c070e2eu; return 0; }
goto P_0c070e30;
P_0c070e30: /* original e01c, guest PC 0x0c070e30 */
if(!s->budget--) { s->failed_pc=0x0c070e30u; return 0; }
r[0]=0x0000001cu;
goto P_0c070e32;
P_0c070e32: /* original f4fc, guest PC 0x0c070e32 */
if(!s->budget--) { s->failed_pc=0x0c070e32u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070e34;
P_0c070e34: /* original f3f6, guest PC 0x0c070e34 */
if(!s->budget--) { s->failed_pc=0x0c070e34u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c070e36;
P_0c070e36: /* original 64f3, guest PC 0x0c070e36 */
if(!s->budget--) { s->failed_pc=0x0c070e36u; return 0; }
r[4]=r[15];
goto P_0c070e38;
P_0c070e38: /* original 65f3, guest PC 0x0c070e38 */
if(!s->budget--) { s->failed_pc=0x0c070e38u; return 0; }
r[5]=r[15];
goto P_0c070e3a;
P_0c070e3a: /* original 7438, guest PC 0x0c070e3a */
if(!s->budget--) { s->failed_pc=0x0c070e3au; return 0; }
r[4]+=0x00000038u;
goto P_0c070e3c;
P_0c070e3c: /* original f431, guest PC 0x0c070e3c */
if(!s->budget--) { s->failed_pc=0x0c070e3cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c070e3e;
P_0c070e3e: /* original 7538, guest PC 0x0c070e3e */
if(!s->budget--) { s->failed_pc=0x0c070e3eu; return 0; }
r[5]+=0x00000038u;
goto P_0c070e40;
P_0c070e40: /* original f059, guest PC 0x0c070e40 */
if(!s->budget--) { s->failed_pc=0x0c070e40u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e42;
P_0c070e42: /* original f159, guest PC 0x0c070e42 */
if(!s->budget--) { s->failed_pc=0x0c070e42u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e44;
P_0c070e44: /* original f259, guest PC 0x0c070e44 */
if(!s->budget--) { s->failed_pc=0x0c070e44u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e46;
P_0c070e46: /* original f38d, guest PC 0x0c070e46 */
if(!s->budget--) { s->failed_pc=0x0c070e46u; return 0; }
fr[3]=0;
goto P_0c070e48;
P_0c070e48: /* original f0ed, guest PC 0x0c070e48 */
if(!s->budget--) { s->failed_pc=0x0c070e48u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070e4a;
P_0c070e4a: /* original f37d, guest PC 0x0c070e4a */
if(!s->budget--) { s->failed_pc=0x0c070e4au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070e4c;
P_0c070e4c: /* original f342, guest PC 0x0c070e4c */
if(!s->budget--) { s->failed_pc=0x0c070e4cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070e4e;
P_0c070e4e: /* original 740c, guest PC 0x0c070e4e */
if(!s->budget--) { s->failed_pc=0x0c070e4eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c070e50;
P_0c070e50: /* original f232, guest PC 0x0c070e50 */
if(!s->budget--) { s->failed_pc=0x0c070e50u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070e52;
P_0c070e52: /* original f132, guest PC 0x0c070e52 */
if(!s->budget--) { s->failed_pc=0x0c070e52u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070e54;
P_0c070e54: /* original f032, guest PC 0x0c070e54 */
if(!s->budget--) { s->failed_pc=0x0c070e54u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070e56;
P_0c070e56: /* original f42b, guest PC 0x0c070e56 */
if(!s->budget--) { s->failed_pc=0x0c070e56u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070e58;
P_0c070e58: /* original f41b, guest PC 0x0c070e58 */
if(!s->budget--) { s->failed_pc=0x0c070e58u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070e5a;
P_0c070e5a: /* original f40b, guest PC 0x0c070e5a */
if(!s->budget--) { s->failed_pc=0x0c070e5au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070e5c;
P_0c070e5c: /* original 64f3, guest PC 0x0c070e5c */
if(!s->budget--) { s->failed_pc=0x0c070e5cu; return 0; }
r[4]=r[15];
goto P_0c070e5e;
P_0c070e5e: /* original 65f3, guest PC 0x0c070e5e */
if(!s->budget--) { s->failed_pc=0x0c070e5eu; return 0; }
r[5]=r[15];
goto P_0c070e60;
P_0c070e60: /* original 7444, guest PC 0x0c070e60 */
if(!s->budget--) { s->failed_pc=0x0c070e60u; return 0; }
r[4]+=0x00000044u;
goto P_0c070e62;
P_0c070e62: /* original 7538, guest PC 0x0c070e62 */
if(!s->budget--) { s->failed_pc=0x0c070e62u; return 0; }
r[5]+=0x00000038u;
goto P_0c070e64;
P_0c070e64: /* original f049, guest PC 0x0c070e64 */
if(!s->budget--) { s->failed_pc=0x0c070e64u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070e66;
P_0c070e66: /* original f359, guest PC 0x0c070e66 */
if(!s->budget--) { s->failed_pc=0x0c070e66u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e68;
P_0c070e68: /* original f149, guest PC 0x0c070e68 */
if(!s->budget--) { s->failed_pc=0x0c070e68u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070e6a;
P_0c070e6a: /* original f459, guest PC 0x0c070e6a */
if(!s->budget--) { s->failed_pc=0x0c070e6au; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e6c;
P_0c070e6c: /* original f249, guest PC 0x0c070e6c */
if(!s->budget--) { s->failed_pc=0x0c070e6cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070e6e;
P_0c070e6e: /* original f559, guest PC 0x0c070e6e */
if(!s->budget--) { s->failed_pc=0x0c070e6eu; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e70;
P_0c070e70: /* original f030, guest PC 0x0c070e70 */
if(!s->budget--) { s->failed_pc=0x0c070e70u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070e72;
P_0c070e72: /* original f250, guest PC 0x0c070e72 */
if(!s->budget--) { s->failed_pc=0x0c070e72u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070e74;
P_0c070e74: /* original f140, guest PC 0x0c070e74 */
if(!s->budget--) { s->failed_pc=0x0c070e74u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070e76;
P_0c070e76: /* original f42b, guest PC 0x0c070e76 */
if(!s->budget--) { s->failed_pc=0x0c070e76u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070e78;
P_0c070e78: /* original f41b, guest PC 0x0c070e78 */
if(!s->budget--) { s->failed_pc=0x0c070e78u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070e7a;
P_0c070e7a: /* original f40b, guest PC 0x0c070e7a */
if(!s->budget--) { s->failed_pc=0x0c070e7au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070e7c;
P_0c070e7c: /* original 65f3, guest PC 0x0c070e7c */
if(!s->budget--) { s->failed_pc=0x0c070e7cu; return 0; }
r[5]=r[15];
goto P_0c070e7e;
P_0c070e7e: /* original 64d3, guest PC 0x0c070e7e */
if(!s->budget--) { s->failed_pc=0x0c070e7eu; return 0; }
r[4]=r[13];
goto P_0c070e80;
P_0c070e80: /* original 7544, guest PC 0x0c070e80 */
if(!s->budget--) { s->failed_pc=0x0c070e80u; return 0; }
r[5]+=0x00000044u;
goto P_0c070e82;
P_0c070e82: /* original 66a3, guest PC 0x0c070e82 */
if(!s->budget--) { s->failed_pc=0x0c070e82u; return 0; }
r[6]=r[10];
goto P_0c070e84;
P_0c070e84: /* original f059, guest PC 0x0c070e84 */
if(!s->budget--) { s->failed_pc=0x0c070e84u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e86;
P_0c070e86: /* original f369, guest PC 0x0c070e86 */
if(!s->budget--) { s->failed_pc=0x0c070e86u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070e88;
P_0c070e88: /* original f159, guest PC 0x0c070e88 */
if(!s->budget--) { s->failed_pc=0x0c070e88u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e8a;
P_0c070e8a: /* original f469, guest PC 0x0c070e8a */
if(!s->budget--) { s->failed_pc=0x0c070e8au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070e8c;
P_0c070e8c: /* original f259, guest PC 0x0c070e8c */
if(!s->budget--) { s->failed_pc=0x0c070e8cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e8e;
P_0c070e8e: /* original f569, guest PC 0x0c070e8e */
if(!s->budget--) { s->failed_pc=0x0c070e8eu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070e90;
P_0c070e90: /* original 740c, guest PC 0x0c070e90 */
if(!s->budget--) { s->failed_pc=0x0c070e90u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070e92;
P_0c070e92: /* original f030, guest PC 0x0c070e92 */
if(!s->budget--) { s->failed_pc=0x0c070e92u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070e94;
P_0c070e94: /* original f250, guest PC 0x0c070e94 */
if(!s->budget--) { s->failed_pc=0x0c070e94u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070e96;
P_0c070e96: /* original f140, guest PC 0x0c070e96 */
if(!s->budget--) { s->failed_pc=0x0c070e96u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070e98;
P_0c070e98: /* original f42b, guest PC 0x0c070e98 */
if(!s->budget--) { s->failed_pc=0x0c070e98u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070e9a;
P_0c070e9a: /* original f41b, guest PC 0x0c070e9a */
if(!s->budget--) { s->failed_pc=0x0c070e9au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070e9c;
P_0c070e9c: /* original f40b, guest PC 0x0c070e9c */
if(!s->budget--) { s->failed_pc=0x0c070e9cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070e9e;
P_0c070e9e: /* original 0009, guest PC 0x0c070e9e */
if(!s->budget--) { s->failed_pc=0x0c070e9eu; return 0; }
goto P_0c070ea0;
P_0c070ea0: /* original 64f3, guest PC 0x0c070ea0 */
if(!s->budget--) { s->failed_pc=0x0c070ea0u; return 0; }
r[4]=r[15];
goto P_0c070ea2;
P_0c070ea2: /* original 7444, guest PC 0x0c070ea2 */
if(!s->budget--) { s->failed_pc=0x0c070ea2u; return 0; }
r[4]+=0x00000044u;
goto P_0c070ea4;
P_0c070ea4: /* original 6693, guest PC 0x0c070ea4 */
if(!s->budget--) { s->failed_pc=0x0c070ea4u; return 0; }
r[6]=r[9];
goto P_0c070ea6;
P_0c070ea6: /* original 65d3, guest PC 0x0c070ea6 */
if(!s->budget--) { s->failed_pc=0x0c070ea6u; return 0; }
r[5]=r[13];
goto P_0c070ea8;
P_0c070ea8: /* original f059, guest PC 0x0c070ea8 */
if(!s->budget--) { s->failed_pc=0x0c070ea8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070eaa;
P_0c070eaa: /* original f369, guest PC 0x0c070eaa */
if(!s->budget--) { s->failed_pc=0x0c070eaau; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070eac;
P_0c070eac: /* original f159, guest PC 0x0c070eac */
if(!s->budget--) { s->failed_pc=0x0c070eacu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070eae;
P_0c070eae: /* original f469, guest PC 0x0c070eae */
if(!s->budget--) { s->failed_pc=0x0c070eaeu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070eb0;
P_0c070eb0: /* original f031, guest PC 0x0c070eb0 */
if(!s->budget--) { s->failed_pc=0x0c070eb0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070eb2;
P_0c070eb2: /* original f258, guest PC 0x0c070eb2 */
if(!s->budget--) { s->failed_pc=0x0c070eb2u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070eb4;
P_0c070eb4: /* original f568, guest PC 0x0c070eb4 */
if(!s->budget--) { s->failed_pc=0x0c070eb4u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070eb6;
P_0c070eb6: /* original f141, guest PC 0x0c070eb6 */
if(!s->budget--) { s->failed_pc=0x0c070eb6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070eb8;
P_0c070eb8: /* original f251, guest PC 0x0c070eb8 */
if(!s->budget--) { s->failed_pc=0x0c070eb8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070eba;
P_0c070eba: /* original 7408, guest PC 0x0c070eba */
if(!s->budget--) { s->failed_pc=0x0c070ebau; return 0; }
r[4]+=0x00000008u;
goto P_0c070ebc;
P_0c070ebc: /* original f42a, guest PC 0x0c070ebc */
if(!s->budget--) { s->failed_pc=0x0c070ebcu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070ebe;
P_0c070ebe: /* original f41b, guest PC 0x0c070ebe */
if(!s->budget--) { s->failed_pc=0x0c070ebeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070ec0;
P_0c070ec0: /* original f40b, guest PC 0x0c070ec0 */
if(!s->budget--) { s->failed_pc=0x0c070ec0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070ec2;
P_0c070ec2: /* original 0009, guest PC 0x0c070ec2 */
if(!s->budget--) { s->failed_pc=0x0c070ec2u; return 0; }
goto P_0c070ec4;
P_0c070ec4: /* original 64f3, guest PC 0x0c070ec4 */
if(!s->budget--) { s->failed_pc=0x0c070ec4u; return 0; }
r[4]=r[15];
goto P_0c070ec6;
P_0c070ec6: /* original 7444, guest PC 0x0c070ec6 */
if(!s->budget--) { s->failed_pc=0x0c070ec6u; return 0; }
r[4]+=0x00000044u;
goto P_0c070ec8;
P_0c070ec8: /* original f049, guest PC 0x0c070ec8 */
if(!s->budget--) { s->failed_pc=0x0c070ec8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070eca;
P_0c070eca: /* original f149, guest PC 0x0c070eca */
if(!s->budget--) { s->failed_pc=0x0c070ecau; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070ecc;
P_0c070ecc: /* original f249, guest PC 0x0c070ecc */
if(!s->budget--) { s->failed_pc=0x0c070eccu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070ece;
P_0c070ece: /* original f38d, guest PC 0x0c070ece */
if(!s->budget--) { s->failed_pc=0x0c070eceu; return 0; }
fr[3]=0;
goto P_0c070ed0;
P_0c070ed0: /* original f0ed, guest PC 0x0c070ed0 */
if(!s->budget--) { s->failed_pc=0x0c070ed0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070ed2;
P_0c070ed2: /* original f03c, guest PC 0x0c070ed2 */
if(!s->budget--) { s->failed_pc=0x0c070ed2u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070ed4;
P_0c070ed4: /* original f06d, guest PC 0x0c070ed4 */
if(!s->budget--) { s->failed_pc=0x0c070ed4u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070ed6;
P_0c070ed6: /* original 0009, guest PC 0x0c070ed6 */
if(!s->budget--) { s->failed_pc=0x0c070ed6u; return 0; }
goto P_0c070ed8;
P_0c070ed8: /* original f38d, guest PC 0x0c070ed8 */
if(!s->budget--) { s->failed_pc=0x0c070ed8u; return 0; }
fr[3]=0;
goto P_0c070eda;
P_0c070eda: /* original fc0c, guest PC 0x0c070eda */
if(!s->budget--) { s->failed_pc=0x0c070edau; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c070edc;
P_0c070edc: /* original fc35, guest PC 0x0c070edc */
if(!s->budget--) { s->failed_pc=0x0c070edcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[12])>as_float(fr[3]))!=0);
goto P_0c070ede;
P_0c070ede: /* original 8902, guest PC 0x0c070ede */
if(!s->budget--) { s->failed_pc=0x0c070edeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070ee6; }
goto P_0c070ee0;
P_0c070ee0: /* original d303, guest PC 0x0c070ee0 */
if(!s->budget--) { s->failed_pc=0x0c070ee0u; return 0; }
r[3]=read(ram,0x0c070ef0u,4);
goto P_0c070ee2;
P_0c070ee2: /* original 432b, guest PC 0x0c070ee2 */
if(!s->budget--) { s->failed_pc=0x0c070ee2u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c071070u: goto P_0c071070;
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
P_0c070ee4: /* original 0009, guest PC 0x0c070ee4 */
if(!s->budget--) { s->failed_pc=0x0c070ee4u; return 0; }
goto P_0c070ee6;
P_0c070ee6: /* original 64f3, guest PC 0x0c070ee6 */
if(!s->budget--) { s->failed_pc=0x0c070ee6u; return 0; }
r[4]=r[15];
goto P_0c070ee8;
P_0c070ee8: /* original 7444, guest PC 0x0c070ee8 */
if(!s->budget--) { s->failed_pc=0x0c070ee8u; return 0; }
r[4]+=0x00000044u;
goto P_0c070eea;
P_0c070eea: /* original 65c3, guest PC 0x0c070eea */
if(!s->budget--) { s->failed_pc=0x0c070eeau; return 0; }
r[5]=r[12];
goto P_0c070eec;
P_0c070eec: /* original a002, guest PC 0x0c070eec */
if(!s->budget--) { s->failed_pc=0x0c070eecu; return 0; }
goto P_0c070ef4;
P_0c070eee: /* original 0009, guest PC 0x0c070eee */
if(!s->budget--) { s->failed_pc=0x0c070eeeu; return 0; }
if(!vf3_matrix_family(0x0c070ef0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c070ef0u; return 0; } return 1;
P_0c070ef4: /* original f049, guest PC 0x0c070ef4 */
if(!s->budget--) { s->failed_pc=0x0c070ef4u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070ef6;
P_0c070ef6: /* original f549, guest PC 0x0c070ef6 */
if(!s->budget--) { s->failed_pc=0x0c070ef6u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070ef8;
P_0c070ef8: /* original f648, guest PC 0x0c070ef8 */
if(!s->budget--) { s->failed_pc=0x0c070ef8u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c070efa;
P_0c070efa: /* original f859, guest PC 0x0c070efa */
if(!s->budget--) { s->failed_pc=0x0c070efau; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070efc;
P_0c070efc: /* original f959, guest PC 0x0c070efc */
if(!s->budget--) { s->failed_pc=0x0c070efcu; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070efe;
P_0c070efe: /* original fa58, guest PC 0x0c070efe */
if(!s->budget--) { s->failed_pc=0x0c070efeu; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c070f00;
P_0c070f00: /* original f35c, guest PC 0x0c070f00 */
if(!s->budget--) { s->failed_pc=0x0c070f00u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c070f02;
P_0c070f02: /* original f382, guest PC 0x0c070f02 */
if(!s->budget--) { s->failed_pc=0x0c070f02u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c070f04;
P_0c070f04: /* original f20c, guest PC 0x0c070f04 */
if(!s->budget--) { s->failed_pc=0x0c070f04u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c070f06;
P_0c070f06: /* original f2a2, guest PC 0x0c070f06 */
if(!s->budget--) { s->failed_pc=0x0c070f06u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c070f08;
P_0c070f08: /* original f16c, guest PC 0x0c070f08 */
if(!s->budget--) { s->failed_pc=0x0c070f08u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c070f0a;
P_0c070f0a: /* original f192, guest PC 0x0c070f0a */
if(!s->budget--) { s->failed_pc=0x0c070f0au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c070f0c;
P_0c070f0c: /* original f34d, guest PC 0x0c070f0c */
if(!s->budget--) { s->failed_pc=0x0c070f0cu; return 0; }
fr[3]^=0x80000000u;
goto P_0c070f0e;
P_0c070f0e: /* original f39e, guest PC 0x0c070f0e */
if(!s->budget--) { s->failed_pc=0x0c070f0eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c070f10;
P_0c070f10: /* original f24d, guest PC 0x0c070f10 */
if(!s->budget--) { s->failed_pc=0x0c070f10u; return 0; }
fr[2]^=0x80000000u;
goto P_0c070f12;
P_0c070f12: /* original f06c, guest PC 0x0c070f12 */
if(!s->budget--) { s->failed_pc=0x0c070f12u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c070f14;
P_0c070f14: /* original f28e, guest PC 0x0c070f14 */
if(!s->budget--) { s->failed_pc=0x0c070f14u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c070f16;
P_0c070f16: /* original f14d, guest PC 0x0c070f16 */
if(!s->budget--) { s->failed_pc=0x0c070f16u; return 0; }
fr[1]^=0x80000000u;
goto P_0c070f18;
P_0c070f18: /* original f05c, guest PC 0x0c070f18 */
if(!s->budget--) { s->failed_pc=0x0c070f18u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c070f1a;
P_0c070f1a: /* original f1ae, guest PC 0x0c070f1a */
if(!s->budget--) { s->failed_pc=0x0c070f1au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c070f1c;
P_0c070f1c: /* original f08d, guest PC 0x0c070f1c */
if(!s->budget--) { s->failed_pc=0x0c070f1cu; return 0; }
fr[0]=0;
goto P_0c070f1e;
P_0c070f1e: /* original f0ed, guest PC 0x0c070f1e */
if(!s->budget--) { s->failed_pc=0x0c070f1eu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070f20;
P_0c070f20: /* original f03c, guest PC 0x0c070f20 */
if(!s->budget--) { s->failed_pc=0x0c070f20u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070f22;
P_0c070f22: /* original f06d, guest PC 0x0c070f22 */
if(!s->budget--) { s->failed_pc=0x0c070f22u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070f24;
P_0c070f24: /* original ff05, guest PC 0x0c070f24 */
if(!s->budget--) { s->failed_pc=0x0c070f24u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[0]))!=0);
goto P_0c070f26;
P_0c070f26: /* original e024, guest PC 0x0c070f26 */
if(!s->budget--) { s->failed_pc=0x0c070f26u; return 0; }
r[0]=0x00000024u;
goto P_0c070f28;
P_0c070f28: /* original 8d03, guest PC 0x0c070f28 */
if(!s->budget--) { s->failed_pc=0x0c070f28u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(cond) { goto P_0c070f32; }
goto P_0c070f2c;
P_0c070f2a: /* original ff07, guest PC 0x0c070f2a */
if(!s->budget--) { s->failed_pc=0x0c070f2au; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c070f2c;
P_0c070f2c: /* original d303, guest PC 0x0c070f2c */
if(!s->budget--) { s->failed_pc=0x0c070f2cu; return 0; }
r[3]=read(ram,0x0c070f3cu,4);
goto P_0c070f2e;
P_0c070f2e: /* original 432b, guest PC 0x0c070f2e */
if(!s->budget--) { s->failed_pc=0x0c070f2eu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c071070u: goto P_0c071070;
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
P_0c070f30: /* original 0009, guest PC 0x0c070f30 */
if(!s->budget--) { s->failed_pc=0x0c070f30u; return 0; }
goto P_0c070f32;
P_0c070f32: /* original 64f3, guest PC 0x0c070f32 */
if(!s->budget--) { s->failed_pc=0x0c070f32u; return 0; }
r[4]=r[15];
goto P_0c070f34;
P_0c070f34: /* original 7444, guest PC 0x0c070f34 */
if(!s->budget--) { s->failed_pc=0x0c070f34u; return 0; }
r[4]+=0x00000044u;
goto P_0c070f36;
P_0c070f36: /* original 65c3, guest PC 0x0c070f36 */
if(!s->budget--) { s->failed_pc=0x0c070f36u; return 0; }
r[5]=r[12];
goto P_0c070f38;
P_0c070f38: /* original a002, guest PC 0x0c070f38 */
if(!s->budget--) { s->failed_pc=0x0c070f38u; return 0; }
goto P_0c070f40;
P_0c070f3a: /* original 0009, guest PC 0x0c070f3a */
if(!s->budget--) { s->failed_pc=0x0c070f3au; return 0; }
if(!vf3_matrix_family(0x0c070f3cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c070f3cu; return 0; } return 1;
P_0c070f40: /* original f049, guest PC 0x0c070f40 */
if(!s->budget--) { s->failed_pc=0x0c070f40u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070f42;
P_0c070f42: /* original f149, guest PC 0x0c070f42 */
if(!s->budget--) { s->failed_pc=0x0c070f42u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070f44;
P_0c070f44: /* original f249, guest PC 0x0c070f44 */
if(!s->budget--) { s->failed_pc=0x0c070f44u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070f46;
P_0c070f46: /* original f38d, guest PC 0x0c070f46 */
if(!s->budget--) { s->failed_pc=0x0c070f46u; return 0; }
fr[3]=0;
goto P_0c070f48;
P_0c070f48: /* original f459, guest PC 0x0c070f48 */
if(!s->budget--) { s->failed_pc=0x0c070f48u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070f4a;
P_0c070f4a: /* original f559, guest PC 0x0c070f4a */
if(!s->budget--) { s->failed_pc=0x0c070f4au; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070f4c;
P_0c070f4c: /* original f659, guest PC 0x0c070f4c */
if(!s->budget--) { s->failed_pc=0x0c070f4cu; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070f4e;
P_0c070f4e: /* original f78d, guest PC 0x0c070f4e */
if(!s->budget--) { s->failed_pc=0x0c070f4eu; return 0; }
fr[7]=0;
goto P_0c070f50;
P_0c070f50: /* original f4ed, guest PC 0x0c070f50 */
if(!s->budget--) { s->failed_pc=0x0c070f50u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c070f52;
P_0c070f52: /* original f07c, guest PC 0x0c070f52 */
if(!s->budget--) { s->failed_pc=0x0c070f52u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c070f54;
P_0c070f54: /* original f38d, guest PC 0x0c070f54 */
if(!s->budget--) { s->failed_pc=0x0c070f54u; return 0; }
fr[3]=0;
goto P_0c070f56;
P_0c070f56: /* original f40c, guest PC 0x0c070f56 */
if(!s->budget--) { s->failed_pc=0x0c070f56u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c070f58;
P_0c070f58: /* original f345, guest PC 0x0c070f58 */
if(!s->budget--) { s->failed_pc=0x0c070f58u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c070f5a;
P_0c070f5a: /* original 8902, guest PC 0x0c070f5a */
if(!s->budget--) { s->failed_pc=0x0c070f5au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070f62; }
goto P_0c070f5c;
P_0c070f5c: /* original d307, guest PC 0x0c070f5c */
if(!s->budget--) { s->failed_pc=0x0c070f5cu; return 0; }
r[3]=read(ram,0x0c070f7cu,4);
goto P_0c070f5e;
P_0c070f5e: /* original 432b, guest PC 0x0c070f5e */
if(!s->budget--) { s->failed_pc=0x0c070f5eu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070fa6u: goto P_0c070fa6;
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
P_0c070f60: /* original 0009, guest PC 0x0c070f60 */
if(!s->budget--) { s->failed_pc=0x0c070f60u; return 0; }
goto P_0c070f62;
P_0c070f62: /* original ffc5, guest PC 0x0c070f62 */
if(!s->budget--) { s->failed_pc=0x0c070f62u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[12]))!=0);
goto P_0c070f64;
P_0c070f64: /* original 8902, guest PC 0x0c070f64 */
if(!s->budget--) { s->failed_pc=0x0c070f64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070f6c; }
goto P_0c070f66;
P_0c070f66: /* original d206, guest PC 0x0c070f66 */
if(!s->budget--) { s->failed_pc=0x0c070f66u; return 0; }
r[2]=read(ram,0x0c070f80u,4);
goto P_0c070f68;
P_0c070f68: /* original 422b, guest PC 0x0c070f68 */
if(!s->budget--) { s->failed_pc=0x0c070f68u; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c071070u: goto P_0c071070;
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
P_0c070f6a: /* original 0009, guest PC 0x0c070f6a */
if(!s->budget--) { s->failed_pc=0x0c070f6au; return 0; }
goto P_0c070f6c;
P_0c070f6c: /* original 64f3, guest PC 0x0c070f6c */
if(!s->budget--) { s->failed_pc=0x0c070f6cu; return 0; }
r[4]=r[15];
goto P_0c070f6e;
P_0c070f6e: /* original 65f3, guest PC 0x0c070f6e */
if(!s->budget--) { s->failed_pc=0x0c070f6eu; return 0; }
r[5]=r[15];
goto P_0c070f70;
P_0c070f70: /* original 7444, guest PC 0x0c070f70 */
if(!s->budget--) { s->failed_pc=0x0c070f70u; return 0; }
r[4]+=0x00000044u;
goto P_0c070f72;
P_0c070f72: /* original f4fc, guest PC 0x0c070f72 */
if(!s->budget--) { s->failed_pc=0x0c070f72u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070f74;
P_0c070f74: /* original 7544, guest PC 0x0c070f74 */
if(!s->budget--) { s->failed_pc=0x0c070f74u; return 0; }
r[5]+=0x00000044u;
goto P_0c070f76;
P_0c070f76: /* original a005, guest PC 0x0c070f76 */
if(!s->budget--) { s->failed_pc=0x0c070f76u; return 0; }
goto P_0c070f84;
P_0c070f78: /* original 0009, guest PC 0x0c070f78 */
if(!s->budget--) { s->failed_pc=0x0c070f78u; return 0; }
if(!vf3_matrix_family(0x0c070f7au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c070f7au; return 0; } return 1;
P_0c070f84: /* original f059, guest PC 0x0c070f84 */
if(!s->budget--) { s->failed_pc=0x0c070f84u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070f86;
P_0c070f86: /* original f159, guest PC 0x0c070f86 */
if(!s->budget--) { s->failed_pc=0x0c070f86u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070f88;
P_0c070f88: /* original f259, guest PC 0x0c070f88 */
if(!s->budget--) { s->failed_pc=0x0c070f88u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070f8a;
P_0c070f8a: /* original f38d, guest PC 0x0c070f8a */
if(!s->budget--) { s->failed_pc=0x0c070f8au; return 0; }
fr[3]=0;
goto P_0c070f8c;
P_0c070f8c: /* original f0ed, guest PC 0x0c070f8c */
if(!s->budget--) { s->failed_pc=0x0c070f8cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070f8e;
P_0c070f8e: /* original f37d, guest PC 0x0c070f8e */
if(!s->budget--) { s->failed_pc=0x0c070f8eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070f90;
P_0c070f90: /* original f342, guest PC 0x0c070f90 */
if(!s->budget--) { s->failed_pc=0x0c070f90u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070f92;
P_0c070f92: /* original 740c, guest PC 0x0c070f92 */
if(!s->budget--) { s->failed_pc=0x0c070f92u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070f94;
P_0c070f94: /* original f232, guest PC 0x0c070f94 */
if(!s->budget--) { s->failed_pc=0x0c070f94u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070f96;
P_0c070f96: /* original f132, guest PC 0x0c070f96 */
if(!s->budget--) { s->failed_pc=0x0c070f96u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070f98;
P_0c070f98: /* original f032, guest PC 0x0c070f98 */
if(!s->budget--) { s->failed_pc=0x0c070f98u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070f9a;
P_0c070f9a: /* original f42b, guest PC 0x0c070f9a */
if(!s->budget--) { s->failed_pc=0x0c070f9au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070f9c;
P_0c070f9c: /* original f41b, guest PC 0x0c070f9c */
if(!s->budget--) { s->failed_pc=0x0c070f9cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070f9e;
P_0c070f9e: /* original f40b, guest PC 0x0c070f9e */
if(!s->budget--) { s->failed_pc=0x0c070f9eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070fa0;
P_0c070fa0: /* original d206, guest PC 0x0c070fa0 */
if(!s->budget--) { s->failed_pc=0x0c070fa0u; return 0; }
r[2]=read(ram,0x0c070fbcu,4);
goto P_0c070fa2;
P_0c070fa2: /* original 422b, guest PC 0x0c070fa2 */
if(!s->budget--) { s->failed_pc=0x0c070fa2u; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c07104cu: goto P_0c07104c;
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
P_0c070fa4: /* original 0009, guest PC 0x0c070fa4 */
if(!s->budget--) { s->failed_pc=0x0c070fa4u; return 0; }
goto P_0c070fa6;
P_0c070fa6: /* original fe45, guest PC 0x0c070fa6 */
if(!s->budget--) { s->failed_pc=0x0c070fa6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[4]))!=0);
goto P_0c070fa8;
P_0c070fa8: /* original 8902, guest PC 0x0c070fa8 */
if(!s->budget--) { s->failed_pc=0x0c070fa8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070fb0; }
goto P_0c070faa;
P_0c070faa: /* original d205, guest PC 0x0c070faa */
if(!s->budget--) { s->failed_pc=0x0c070faau; return 0; }
r[2]=read(ram,0x0c070fc0u,4);
goto P_0c070fac;
P_0c070fac: /* original 422b, guest PC 0x0c070fac */
if(!s->budget--) { s->failed_pc=0x0c070facu; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c071070u: goto P_0c071070;
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
P_0c070fae: /* original 0009, guest PC 0x0c070fae */
if(!s->budget--) { s->failed_pc=0x0c070faeu; return 0; }
goto P_0c070fb0;
P_0c070fb0: /* original 64f3, guest PC 0x0c070fb0 */
if(!s->budget--) { s->failed_pc=0x0c070fb0u; return 0; }
r[4]=r[15];
goto P_0c070fb2;
P_0c070fb2: /* original 7438, guest PC 0x0c070fb2 */
if(!s->budget--) { s->failed_pc=0x0c070fb2u; return 0; }
r[4]+=0x00000038u;
goto P_0c070fb4;
P_0c070fb4: /* original 65c3, guest PC 0x0c070fb4 */
if(!s->budget--) { s->failed_pc=0x0c070fb4u; return 0; }
r[5]=r[12];
goto P_0c070fb6;
P_0c070fb6: /* original a005, guest PC 0x0c070fb6 */
if(!s->budget--) { s->failed_pc=0x0c070fb6u; return 0; }
goto P_0c070fc4;
P_0c070fb8: /* original 0009, guest PC 0x0c070fb8 */
if(!s->budget--) { s->failed_pc=0x0c070fb8u; return 0; }
if(!vf3_matrix_family(0x0c070fbau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c070fbau; return 0; } return 1;
P_0c070fc4: /* original f059, guest PC 0x0c070fc4 */
if(!s->budget--) { s->failed_pc=0x0c070fc4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070fc6;
P_0c070fc6: /* original f159, guest PC 0x0c070fc6 */
if(!s->budget--) { s->failed_pc=0x0c070fc6u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070fc8;
P_0c070fc8: /* original f259, guest PC 0x0c070fc8 */
if(!s->budget--) { s->failed_pc=0x0c070fc8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070fca;
P_0c070fca: /* original 740c, guest PC 0x0c070fca */
if(!s->budget--) { s->failed_pc=0x0c070fcau; return 0; }
r[4]+=0x0000000cu;
goto P_0c070fcc;
P_0c070fcc: /* original f242, guest PC 0x0c070fcc */
if(!s->budget--) { s->failed_pc=0x0c070fccu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c070fce;
P_0c070fce: /* original f142, guest PC 0x0c070fce */
if(!s->budget--) { s->failed_pc=0x0c070fceu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c070fd0;
P_0c070fd0: /* original f042, guest PC 0x0c070fd0 */
if(!s->budget--) { s->failed_pc=0x0c070fd0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c070fd2;
P_0c070fd2: /* original f42b, guest PC 0x0c070fd2 */
if(!s->budget--) { s->failed_pc=0x0c070fd2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070fd4;
P_0c070fd4: /* original f41b, guest PC 0x0c070fd4 */
if(!s->budget--) { s->failed_pc=0x0c070fd4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070fd6;
P_0c070fd6: /* original f40b, guest PC 0x0c070fd6 */
if(!s->budget--) { s->failed_pc=0x0c070fd6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070fd8;
P_0c070fd8: /* original 65f3, guest PC 0x0c070fd8 */
if(!s->budget--) { s->failed_pc=0x0c070fd8u; return 0; }
r[5]=r[15];
goto P_0c070fda;
P_0c070fda: /* original 64f3, guest PC 0x0c070fda */
if(!s->budget--) { s->failed_pc=0x0c070fdau; return 0; }
r[4]=r[15];
goto P_0c070fdc;
P_0c070fdc: /* original 66f3, guest PC 0x0c070fdc */
if(!s->budget--) { s->failed_pc=0x0c070fdcu; return 0; }
r[6]=r[15];
goto P_0c070fde;
P_0c070fde: /* original 7438, guest PC 0x0c070fde */
if(!s->budget--) { s->failed_pc=0x0c070fdeu; return 0; }
r[4]+=0x00000038u;
goto P_0c070fe0;
P_0c070fe0: /* original 7638, guest PC 0x0c070fe0 */
if(!s->budget--) { s->failed_pc=0x0c070fe0u; return 0; }
r[6]+=0x00000038u;
goto P_0c070fe2;
P_0c070fe2: /* original 7544, guest PC 0x0c070fe2 */
if(!s->budget--) { s->failed_pc=0x0c070fe2u; return 0; }
r[5]+=0x00000044u;
goto P_0c070fe4;
P_0c070fe4: /* original f059, guest PC 0x0c070fe4 */
if(!s->budget--) { s->failed_pc=0x0c070fe4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070fe6;
P_0c070fe6: /* original f369, guest PC 0x0c070fe6 */
if(!s->budget--) { s->failed_pc=0x0c070fe6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070fe8;
P_0c070fe8: /* original f159, guest PC 0x0c070fe8 */
if(!s->budget--) { s->failed_pc=0x0c070fe8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070fea;
P_0c070fea: /* original f469, guest PC 0x0c070fea */
if(!s->budget--) { s->failed_pc=0x0c070feau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070fec;
P_0c070fec: /* original f031, guest PC 0x0c070fec */
if(!s->budget--) { s->failed_pc=0x0c070fecu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070fee;
P_0c070fee: /* original f258, guest PC 0x0c070fee */
if(!s->budget--) { s->failed_pc=0x0c070feeu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070ff0;
P_0c070ff0: /* original f568, guest PC 0x0c070ff0 */
if(!s->budget--) { s->failed_pc=0x0c070ff0u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070ff2;
P_0c070ff2: /* original f141, guest PC 0x0c070ff2 */
if(!s->budget--) { s->failed_pc=0x0c070ff2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070ff4;
P_0c070ff4: /* original f251, guest PC 0x0c070ff4 */
if(!s->budget--) { s->failed_pc=0x0c070ff4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070ff6;
P_0c070ff6: /* original 7408, guest PC 0x0c070ff6 */
if(!s->budget--) { s->failed_pc=0x0c070ff6u; return 0; }
r[4]+=0x00000008u;
goto P_0c070ff8;
P_0c070ff8: /* original f42a, guest PC 0x0c070ff8 */
if(!s->budget--) { s->failed_pc=0x0c070ff8u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070ffa;
P_0c070ffa: /* original f41b, guest PC 0x0c070ffa */
if(!s->budget--) { s->failed_pc=0x0c070ffau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070ffc;
P_0c070ffc: /* original f40b, guest PC 0x0c070ffc */
if(!s->budget--) { s->failed_pc=0x0c070ffcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070ffe;
P_0c070ffe: /* original 0009, guest PC 0x0c070ffe */
if(!s->budget--) { s->failed_pc=0x0c070ffeu; return 0; }
goto P_0c071000;
P_0c071000: /* original e024, guest PC 0x0c071000 */
if(!s->budget--) { s->failed_pc=0x0c071000u; return 0; }
r[0]=0x00000024u;
goto P_0c071002;
P_0c071002: /* original f4fc, guest PC 0x0c071002 */
if(!s->budget--) { s->failed_pc=0x0c071002u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c071004;
P_0c071004: /* original f3f6, guest PC 0x0c071004 */
if(!s->budget--) { s->failed_pc=0x0c071004u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c071006;
P_0c071006: /* original 64f3, guest PC 0x0c071006 */
if(!s->budget--) { s->failed_pc=0x0c071006u; return 0; }
r[4]=r[15];
goto P_0c071008;
P_0c071008: /* original 65f3, guest PC 0x0c071008 */
if(!s->budget--) { s->failed_pc=0x0c071008u; return 0; }
r[5]=r[15];
goto P_0c07100a;
P_0c07100a: /* original 7438, guest PC 0x0c07100a */
if(!s->budget--) { s->failed_pc=0x0c07100au; return 0; }
r[4]+=0x00000038u;
goto P_0c07100c;
P_0c07100c: /* original f431, guest PC 0x0c07100c */
if(!s->budget--) { s->failed_pc=0x0c07100cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c07100e;
P_0c07100e: /* original 7538, guest PC 0x0c07100e */
if(!s->budget--) { s->failed_pc=0x0c07100eu; return 0; }
r[5]+=0x00000038u;
goto P_0c071010;
P_0c071010: /* original f059, guest PC 0x0c071010 */
if(!s->budget--) { s->failed_pc=0x0c071010u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071012;
P_0c071012: /* original f159, guest PC 0x0c071012 */
if(!s->budget--) { s->failed_pc=0x0c071012u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071014;
P_0c071014: /* original f259, guest PC 0x0c071014 */
if(!s->budget--) { s->failed_pc=0x0c071014u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071016;
P_0c071016: /* original f38d, guest PC 0x0c071016 */
if(!s->budget--) { s->failed_pc=0x0c071016u; return 0; }
fr[3]=0;
goto P_0c071018;
P_0c071018: /* original f0ed, guest PC 0x0c071018 */
if(!s->budget--) { s->failed_pc=0x0c071018u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07101a;
P_0c07101a: /* original f37d, guest PC 0x0c07101a */
if(!s->budget--) { s->failed_pc=0x0c07101au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c07101c;
P_0c07101c: /* original f342, guest PC 0x0c07101c */
if(!s->budget--) { s->failed_pc=0x0c07101cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c07101e;
P_0c07101e: /* original 740c, guest PC 0x0c07101e */
if(!s->budget--) { s->failed_pc=0x0c07101eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c071020;
P_0c071020: /* original f232, guest PC 0x0c071020 */
if(!s->budget--) { s->failed_pc=0x0c071020u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071022;
P_0c071022: /* original f132, guest PC 0x0c071022 */
if(!s->budget--) { s->failed_pc=0x0c071022u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071024;
P_0c071024: /* original f032, guest PC 0x0c071024 */
if(!s->budget--) { s->failed_pc=0x0c071024u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071026;
P_0c071026: /* original f42b, guest PC 0x0c071026 */
if(!s->budget--) { s->failed_pc=0x0c071026u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071028;
P_0c071028: /* original f41b, guest PC 0x0c071028 */
if(!s->budget--) { s->failed_pc=0x0c071028u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07102a;
P_0c07102a: /* original f40b, guest PC 0x0c07102a */
if(!s->budget--) { s->failed_pc=0x0c07102au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07102c;
P_0c07102c: /* original 64f3, guest PC 0x0c07102c */
if(!s->budget--) { s->failed_pc=0x0c07102cu; return 0; }
r[4]=r[15];
goto P_0c07102e;
P_0c07102e: /* original 65f3, guest PC 0x0c07102e */
if(!s->budget--) { s->failed_pc=0x0c07102eu; return 0; }
r[5]=r[15];
goto P_0c071030;
P_0c071030: /* original 7444, guest PC 0x0c071030 */
if(!s->budget--) { s->failed_pc=0x0c071030u; return 0; }
r[4]+=0x00000044u;
goto P_0c071032;
P_0c071032: /* original 7538, guest PC 0x0c071032 */
if(!s->budget--) { s->failed_pc=0x0c071032u; return 0; }
r[5]+=0x00000038u;
goto P_0c071034;
P_0c071034: /* original f049, guest PC 0x0c071034 */
if(!s->budget--) { s->failed_pc=0x0c071034u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071036;
P_0c071036: /* original f359, guest PC 0x0c071036 */
if(!s->budget--) { s->failed_pc=0x0c071036u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071038;
P_0c071038: /* original f149, guest PC 0x0c071038 */
if(!s->budget--) { s->failed_pc=0x0c071038u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07103a;
P_0c07103a: /* original f459, guest PC 0x0c07103a */
if(!s->budget--) { s->failed_pc=0x0c07103au; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07103c;
P_0c07103c: /* original f249, guest PC 0x0c07103c */
if(!s->budget--) { s->failed_pc=0x0c07103cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07103e;
P_0c07103e: /* original f559, guest PC 0x0c07103e */
if(!s->budget--) { s->failed_pc=0x0c07103eu; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071040;
P_0c071040: /* original f030, guest PC 0x0c071040 */
if(!s->budget--) { s->failed_pc=0x0c071040u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c071042;
P_0c071042: /* original f250, guest PC 0x0c071042 */
if(!s->budget--) { s->failed_pc=0x0c071042u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c071044;
P_0c071044: /* original f140, guest PC 0x0c071044 */
if(!s->budget--) { s->failed_pc=0x0c071044u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071046;
P_0c071046: /* original f42b, guest PC 0x0c071046 */
if(!s->budget--) { s->failed_pc=0x0c071046u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071048;
P_0c071048: /* original f41b, guest PC 0x0c071048 */
if(!s->budget--) { s->failed_pc=0x0c071048u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07104a;
P_0c07104a: /* original f40b, guest PC 0x0c07104a */
if(!s->budget--) { s->failed_pc=0x0c07104au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07104c;
P_0c07104c: /* original 65f3, guest PC 0x0c07104c */
if(!s->budget--) { s->failed_pc=0x0c07104cu; return 0; }
r[5]=r[15];
goto P_0c07104e;
P_0c07104e: /* original 64d3, guest PC 0x0c07104e */
if(!s->budget--) { s->failed_pc=0x0c07104eu; return 0; }
r[4]=r[13];
goto P_0c071050;
P_0c071050: /* original 7544, guest PC 0x0c071050 */
if(!s->budget--) { s->failed_pc=0x0c071050u; return 0; }
r[5]+=0x00000044u;
goto P_0c071052;
P_0c071052: /* original 6693, guest PC 0x0c071052 */
if(!s->budget--) { s->failed_pc=0x0c071052u; return 0; }
r[6]=r[9];
goto P_0c071054;
P_0c071054: /* original f059, guest PC 0x0c071054 */
if(!s->budget--) { s->failed_pc=0x0c071054u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071056;
P_0c071056: /* original f369, guest PC 0x0c071056 */
if(!s->budget--) { s->failed_pc=0x0c071056u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071058;
P_0c071058: /* original f159, guest PC 0x0c071058 */
if(!s->budget--) { s->failed_pc=0x0c071058u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07105a;
P_0c07105a: /* original f469, guest PC 0x0c07105a */
if(!s->budget--) { s->failed_pc=0x0c07105au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07105c;
P_0c07105c: /* original f259, guest PC 0x0c07105c */
if(!s->budget--) { s->failed_pc=0x0c07105cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07105e;
P_0c07105e: /* original f569, guest PC 0x0c07105e */
if(!s->budget--) { s->failed_pc=0x0c07105eu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071060;
P_0c071060: /* original 740c, guest PC 0x0c071060 */
if(!s->budget--) { s->failed_pc=0x0c071060u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071062;
P_0c071062: /* original f030, guest PC 0x0c071062 */
if(!s->budget--) { s->failed_pc=0x0c071062u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c071064;
P_0c071064: /* original f250, guest PC 0x0c071064 */
if(!s->budget--) { s->failed_pc=0x0c071064u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c071066;
P_0c071066: /* original f140, guest PC 0x0c071066 */
if(!s->budget--) { s->failed_pc=0x0c071066u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071068;
P_0c071068: /* original f42b, guest PC 0x0c071068 */
if(!s->budget--) { s->failed_pc=0x0c071068u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07106a;
P_0c07106a: /* original f41b, guest PC 0x0c07106a */
if(!s->budget--) { s->failed_pc=0x0c07106au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07106c;
P_0c07106c: /* original f40b, guest PC 0x0c07106c */
if(!s->budget--) { s->failed_pc=0x0c07106cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07106e;
P_0c07106e: /* original 0009, guest PC 0x0c07106e */
if(!s->budget--) { s->failed_pc=0x0c07106eu; return 0; }
goto P_0c071070;
P_0c071070: /* original 64f3, guest PC 0x0c071070 */
if(!s->budget--) { s->failed_pc=0x0c071070u; return 0; }
r[4]=r[15];
goto P_0c071072;
P_0c071072: /* original 56f1, guest PC 0x0c071072 */
if(!s->budget--) { s->failed_pc=0x0c071072u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c071074;
P_0c071074: /* original 742c, guest PC 0x0c071074 */
if(!s->budget--) { s->failed_pc=0x0c071074u; return 0; }
r[4]+=0x0000002cu;
goto P_0c071076;
P_0c071076: /* original 65d3, guest PC 0x0c071076 */
if(!s->budget--) { s->failed_pc=0x0c071076u; return 0; }
r[5]=r[13];
goto P_0c071078;
P_0c071078: /* original f059, guest PC 0x0c071078 */
if(!s->budget--) { s->failed_pc=0x0c071078u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07107a;
P_0c07107a: /* original f369, guest PC 0x0c07107a */
if(!s->budget--) { s->failed_pc=0x0c07107au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07107c;
P_0c07107c: /* original f159, guest PC 0x0c07107c */
if(!s->budget--) { s->failed_pc=0x0c07107cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07107e;
P_0c07107e: /* original f469, guest PC 0x0c07107e */
if(!s->budget--) { s->failed_pc=0x0c07107eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071080;
P_0c071080: /* original f031, guest PC 0x0c071080 */
if(!s->budget--) { s->failed_pc=0x0c071080u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071082;
P_0c071082: /* original f258, guest PC 0x0c071082 */
if(!s->budget--) { s->failed_pc=0x0c071082u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071084;
P_0c071084: /* original f568, guest PC 0x0c071084 */
if(!s->budget--) { s->failed_pc=0x0c071084u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071086;
P_0c071086: /* original f141, guest PC 0x0c071086 */
if(!s->budget--) { s->failed_pc=0x0c071086u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071088;
P_0c071088: /* original f251, guest PC 0x0c071088 */
if(!s->budget--) { s->failed_pc=0x0c071088u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c07108a;
P_0c07108a: /* original 7408, guest PC 0x0c07108a */
if(!s->budget--) { s->failed_pc=0x0c07108au; return 0; }
r[4]+=0x00000008u;
goto P_0c07108c;
P_0c07108c: /* original f42a, guest PC 0x0c07108c */
if(!s->budget--) { s->failed_pc=0x0c07108cu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07108e;
P_0c07108e: /* original f41b, guest PC 0x0c07108e */
if(!s->budget--) { s->failed_pc=0x0c07108eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071090;
P_0c071090: /* original f40b, guest PC 0x0c071090 */
if(!s->budget--) { s->failed_pc=0x0c071090u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071092;
P_0c071092: /* original 0009, guest PC 0x0c071092 */
if(!s->budget--) { s->failed_pc=0x0c071092u; return 0; }
goto P_0c071094;
P_0c071094: /* original 64f3, guest PC 0x0c071094 */
if(!s->budget--) { s->failed_pc=0x0c071094u; return 0; }
r[4]=r[15];
goto P_0c071096;
P_0c071096: /* original 742c, guest PC 0x0c071096 */
if(!s->budget--) { s->failed_pc=0x0c071096u; return 0; }
r[4]+=0x0000002cu;
goto P_0c071098;
P_0c071098: /* original f049, guest PC 0x0c071098 */
if(!s->budget--) { s->failed_pc=0x0c071098u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07109a;
P_0c07109a: /* original f149, guest PC 0x0c07109a */
if(!s->budget--) { s->failed_pc=0x0c07109au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07109c;
P_0c07109c: /* original f249, guest PC 0x0c07109c */
if(!s->budget--) { s->failed_pc=0x0c07109cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07109e;
P_0c07109e: /* original f38d, guest PC 0x0c07109e */
if(!s->budget--) { s->failed_pc=0x0c07109eu; return 0; }
fr[3]=0;
goto P_0c0710a0;
P_0c0710a0: /* original f0ed, guest PC 0x0c0710a0 */
if(!s->budget--) { s->failed_pc=0x0c0710a0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0710a2;
P_0c0710a2: /* original f03c, guest PC 0x0c0710a2 */
if(!s->budget--) { s->failed_pc=0x0c0710a2u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c0710a4;
P_0c0710a4: /* original f06d, guest PC 0x0c0710a4 */
if(!s->budget--) { s->failed_pc=0x0c0710a4u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c0710a6;
P_0c0710a6: /* original 0009, guest PC 0x0c0710a6 */
if(!s->budget--) { s->failed_pc=0x0c0710a6u; return 0; }
goto P_0c0710a8;
P_0c0710a8: /* original f38d, guest PC 0x0c0710a8 */
if(!s->budget--) { s->failed_pc=0x0c0710a8u; return 0; }
fr[3]=0;
goto P_0c0710aa;
P_0c0710aa: /* original f035, guest PC 0x0c0710aa */
if(!s->budget--) { s->failed_pc=0x0c0710aau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c0710ac;
P_0c0710ac: /* original 8902, guest PC 0x0c0710ac */
if(!s->budget--) { s->failed_pc=0x0c0710acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0710b4; }
goto P_0c0710ae;
P_0c0710ae: /* original d305, guest PC 0x0c0710ae */
if(!s->budget--) { s->failed_pc=0x0c0710aeu; return 0; }
r[3]=read(ram,0x0c0710c4u,4);
goto P_0c0710b0;
P_0c0710b0: /* original 432b, guest PC 0x0c0710b0 */
if(!s->budget--) { s->failed_pc=0x0c0710b0u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c071108u: goto P_0c071108;
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
P_0c0710b2: /* original 0009, guest PC 0x0c0710b2 */
if(!s->budget--) { s->failed_pc=0x0c0710b2u; return 0; }
goto P_0c0710b4;
P_0c0710b4: /* original 64f3, guest PC 0x0c0710b4 */
if(!s->budget--) { s->failed_pc=0x0c0710b4u; return 0; }
r[4]=r[15];
goto P_0c0710b6;
P_0c0710b6: /* original 65f3, guest PC 0x0c0710b6 */
if(!s->budget--) { s->failed_pc=0x0c0710b6u; return 0; }
r[5]=r[15];
goto P_0c0710b8;
P_0c0710b8: /* original 742c, guest PC 0x0c0710b8 */
if(!s->budget--) { s->failed_pc=0x0c0710b8u; return 0; }
r[4]+=0x0000002cu;
goto P_0c0710ba;
P_0c0710ba: /* original f4dc, guest PC 0x0c0710ba */
if(!s->budget--) { s->failed_pc=0x0c0710bau; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0710bc;
P_0c0710bc: /* original 752c, guest PC 0x0c0710bc */
if(!s->budget--) { s->failed_pc=0x0c0710bcu; return 0; }
r[5]+=0x0000002cu;
goto P_0c0710be;
P_0c0710be: /* original a003, guest PC 0x0c0710be */
if(!s->budget--) { s->failed_pc=0x0c0710beu; return 0; }
goto P_0c0710c8;
P_0c0710c0: /* original 0009, guest PC 0x0c0710c0 */
if(!s->budget--) { s->failed_pc=0x0c0710c0u; return 0; }
if(!vf3_matrix_family(0x0c0710c2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0710c2u; return 0; } return 1;
P_0c0710c8: /* original f059, guest PC 0x0c0710c8 */
if(!s->budget--) { s->failed_pc=0x0c0710c8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0710ca;
P_0c0710ca: /* original f159, guest PC 0x0c0710ca */
if(!s->budget--) { s->failed_pc=0x0c0710cau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0710cc;
P_0c0710cc: /* original f259, guest PC 0x0c0710cc */
if(!s->budget--) { s->failed_pc=0x0c0710ccu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0710ce;
P_0c0710ce: /* original f38d, guest PC 0x0c0710ce */
if(!s->budget--) { s->failed_pc=0x0c0710ceu; return 0; }
fr[3]=0;
goto P_0c0710d0;
P_0c0710d0: /* original f0ed, guest PC 0x0c0710d0 */
if(!s->budget--) { s->failed_pc=0x0c0710d0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0710d2;
P_0c0710d2: /* original f37d, guest PC 0x0c0710d2 */
if(!s->budget--) { s->failed_pc=0x0c0710d2u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0710d4;
P_0c0710d4: /* original f342, guest PC 0x0c0710d4 */
if(!s->budget--) { s->failed_pc=0x0c0710d4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0710d6;
P_0c0710d6: /* original 740c, guest PC 0x0c0710d6 */
if(!s->budget--) { s->failed_pc=0x0c0710d6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0710d8;
P_0c0710d8: /* original f232, guest PC 0x0c0710d8 */
if(!s->budget--) { s->failed_pc=0x0c0710d8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0710da;
P_0c0710da: /* original f132, guest PC 0x0c0710da */
if(!s->budget--) { s->failed_pc=0x0c0710dau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0710dc;
P_0c0710dc: /* original f032, guest PC 0x0c0710dc */
if(!s->budget--) { s->failed_pc=0x0c0710dcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0710de;
P_0c0710de: /* original f42b, guest PC 0x0c0710de */
if(!s->budget--) { s->failed_pc=0x0c0710deu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0710e0;
P_0c0710e0: /* original f41b, guest PC 0x0c0710e0 */
if(!s->budget--) { s->failed_pc=0x0c0710e0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0710e2;
P_0c0710e2: /* original f40b, guest PC 0x0c0710e2 */
if(!s->budget--) { s->failed_pc=0x0c0710e2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0710e4;
P_0c0710e4: /* original 55f1, guest PC 0x0c0710e4 */
if(!s->budget--) { s->failed_pc=0x0c0710e4u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0710e6;
P_0c0710e6: /* original 66f3, guest PC 0x0c0710e6 */
if(!s->budget--) { s->failed_pc=0x0c0710e6u; return 0; }
r[6]=r[15];
goto P_0c0710e8;
P_0c0710e8: /* original 64d3, guest PC 0x0c0710e8 */
if(!s->budget--) { s->failed_pc=0x0c0710e8u; return 0; }
r[4]=r[13];
goto P_0c0710ea;
P_0c0710ea: /* original 762c, guest PC 0x0c0710ea */
if(!s->budget--) { s->failed_pc=0x0c0710eau; return 0; }
r[6]+=0x0000002cu;
goto P_0c0710ec;
P_0c0710ec: /* original f059, guest PC 0x0c0710ec */
if(!s->budget--) { s->failed_pc=0x0c0710ecu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0710ee;
P_0c0710ee: /* original f369, guest PC 0x0c0710ee */
if(!s->budget--) { s->failed_pc=0x0c0710eeu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0710f0;
P_0c0710f0: /* original f159, guest PC 0x0c0710f0 */
if(!s->budget--) { s->failed_pc=0x0c0710f0u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0710f2;
P_0c0710f2: /* original f469, guest PC 0x0c0710f2 */
if(!s->budget--) { s->failed_pc=0x0c0710f2u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0710f4;
P_0c0710f4: /* original f259, guest PC 0x0c0710f4 */
if(!s->budget--) { s->failed_pc=0x0c0710f4u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0710f6;
P_0c0710f6: /* original f569, guest PC 0x0c0710f6 */
if(!s->budget--) { s->failed_pc=0x0c0710f6u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0710f8;
P_0c0710f8: /* original 740c, guest PC 0x0c0710f8 */
if(!s->budget--) { s->failed_pc=0x0c0710f8u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0710fa;
P_0c0710fa: /* original f030, guest PC 0x0c0710fa */
if(!s->budget--) { s->failed_pc=0x0c0710fau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c0710fc;
P_0c0710fc: /* original f250, guest PC 0x0c0710fc */
if(!s->budget--) { s->failed_pc=0x0c0710fcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c0710fe;
P_0c0710fe: /* original f140, guest PC 0x0c0710fe */
if(!s->budget--) { s->failed_pc=0x0c0710feu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071100;
P_0c071100: /* original f42b, guest PC 0x0c071100 */
if(!s->budget--) { s->failed_pc=0x0c071100u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071102;
P_0c071102: /* original f41b, guest PC 0x0c071102 */
if(!s->budget--) { s->failed_pc=0x0c071102u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071104;
P_0c071104: /* original f40b, guest PC 0x0c071104 */
if(!s->budget--) { s->failed_pc=0x0c071104u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071106;
P_0c071106: /* original 0009, guest PC 0x0c071106 */
if(!s->budget--) { s->failed_pc=0x0c071106u; return 0; }
goto P_0c071108;
P_0c071108: /* original 52f1, guest PC 0x0c071108 */
if(!s->budget--) { s->failed_pc=0x0c071108u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07110a;
P_0c07110a: /* original 7d18, guest PC 0x0c07110a */
if(!s->budget--) { s->failed_pc=0x0c07110au; return 0; }
r[13]+=0x00000018u;
goto P_0c07110c;
P_0c07110c: /* original 78e8, guest PC 0x0c07110c */
if(!s->budget--) { s->failed_pc=0x0c07110cu; return 0; }
r[8]+=0xffffffe8u;
goto P_0c07110e;
P_0c07110e: /* original 7218, guest PC 0x0c07110e */
if(!s->budget--) { s->failed_pc=0x0c07110eu; return 0; }
r[2]+=0x00000018u;
goto P_0c071110;
P_0c071110: /* original 1f21, guest PC 0x0c071110 */
if(!s->budget--) { s->failed_pc=0x0c071110u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c071112;
P_0c071112: /* original 7ee8, guest PC 0x0c071112 */
if(!s->budget--) { s->failed_pc=0x0c071112u; return 0; }
r[14]+=0xffffffe8u;
goto P_0c071114;
P_0c071114: /* original 63f2, guest PC 0x0c071114 */
if(!s->budget--) { s->failed_pc=0x0c071114u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c071116;
P_0c071116: /* original 73ff, guest PC 0x0c071116 */
if(!s->budget--) { s->failed_pc=0x0c071116u; return 0; }
r[3]+=0xffffffffu;
goto P_0c071118;
P_0c071118: /* original 4315, guest PC 0x0c071118 */
if(!s->budget--) { s->failed_pc=0x0c071118u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c07111a;
P_0c07111a: /* original 8f03, guest PC 0x0c07111a */
if(!s->budget--) { s->failed_pc=0x0c07111au; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c071124; }
goto P_0c07111e;
P_0c07111c: /* original 2f32, guest PC 0x0c07111c */
if(!s->budget--) { s->failed_pc=0x0c07111cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07111e;
P_0c07111e: /* original d11d, guest PC 0x0c07111e */
if(!s->budget--) { s->failed_pc=0x0c07111eu; return 0; }
r[1]=read(ram,0x0c071194u,4);
goto P_0c071120;
P_0c071120: /* original 412b, guest PC 0x0c071120 */
if(!s->budget--) { s->failed_pc=0x0c071120u; return 0; }
target=r[1];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c070888u: goto P_0c070888;
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
P_0c071122: /* original 0009, guest PC 0x0c071122 */
if(!s->budget--) { s->failed_pc=0x0c071122u; return 0; }
goto P_0c071124;
P_0c071124: /* original 7f5c, guest PC 0x0c071124 */
if(!s->budget--) { s->failed_pc=0x0c071124u; return 0; }
r[15]+=0x0000005cu;
goto P_0c071126;
P_0c071126: /* original 4f26, guest PC 0x0c071126 */
if(!s->budget--) { s->failed_pc=0x0c071126u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c071128;
P_0c071128: /* original fcf9, guest PC 0x0c071128 */
if(!s->budget--) { s->failed_pc=0x0c071128u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07112a;
P_0c07112a: /* original fdf9, guest PC 0x0c07112a */
if(!s->budget--) { s->failed_pc=0x0c07112au; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07112c;
P_0c07112c: /* original fef9, guest PC 0x0c07112c */
if(!s->budget--) { s->failed_pc=0x0c07112cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07112e;
P_0c07112e: /* original fff9, guest PC 0x0c07112e */
if(!s->budget--) { s->failed_pc=0x0c07112eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c071130;
P_0c071130: /* original 68f6, guest PC 0x0c071130 */
if(!s->budget--) { s->failed_pc=0x0c071130u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c071132;
P_0c071132: /* original 69f6, guest PC 0x0c071132 */
if(!s->budget--) { s->failed_pc=0x0c071132u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c071134;
P_0c071134: /* original 6af6, guest PC 0x0c071134 */
if(!s->budget--) { s->failed_pc=0x0c071134u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c071136;
P_0c071136: /* original 6bf6, guest PC 0x0c071136 */
if(!s->budget--) { s->failed_pc=0x0c071136u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c071138;
P_0c071138: /* original 6cf6, guest PC 0x0c071138 */
if(!s->budget--) { s->failed_pc=0x0c071138u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07113a;
P_0c07113a: /* original 6df6, guest PC 0x0c07113a */
if(!s->budget--) { s->failed_pc=0x0c07113au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07113c;
P_0c07113c: /* original 000b, guest PC 0x0c07113c */
if(!s->budget--) { s->failed_pc=0x0c07113cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07113e: /* original 6ef6, guest PC 0x0c07113e */
if(!s->budget--) { s->failed_pc=0x0c07113eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c071140u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
